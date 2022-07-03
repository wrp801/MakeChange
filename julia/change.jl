using ArgParse
## Overload the Base max function to find the pair with the max value
function Base.max(d::Base.Dict{String,Int64})
	ret_val = 0 ## will be updated
	ret_key = nothing ## will be updated
	for (k,v) in d
		if v > ret_val
			ret_val = v
			ret_key = k
		end
	end
	return ret_key => ret_val
end

function filter_dict(d::Base.Dict{String,Int64},amt::Base.Number)
	temp = filter(x->x.second <= amt,d)
	return temp
end

function print_dict(coins::Base.Array{String,1},d::Base.Dict{String,Int64})
	for c in coins
		v = get(d,c,0) ## retrieve the value from the map
		if v != 0
			println("\t$c: $v")
		end
	end
end

function make_change(amt::Base.Integer)
	mapping = Dict(
		"Dollar100" => 10000,
		"Dollar50" => 5000,
		"Dollar20" => 2000,
		"Dollar10" => 1000,
		"Dollar5" => 500,
		"Dollar1" => 100,
		"Quarter" => 25,
		"Dime" => 10,
		"Nickel" => 5,
		"Penny" =>1
	)
	change_map = Dict(k => 0 for k in keys(mapping))
	change_amt = 0 
	while change_amt < amt
		delta = amt - change_amt
		temp_d = filter_dict(mapping,delta)
		ret_max = max(temp_d) ## use our customized max function
		max_k = ret_max.first ## the key
		max_v = ret_max.second ## the value
		change_amt += max_v ## update the total change
		delta += max_v ## update the difference between the tallied change and the requested amount
		change_map[max_k] += 1 ## increment the change map 
	end
	return filter(x->x.second > 0,change_map)

end

function parse_commandline()
	s = ArgParseSettings()

	@add_arg_table s begin 
		"-c"
			help = "Will read arguments from a file instead of the command line"
			action = :store_true
	end
	return parse_args(s)
end


function main(amt::String)
	coins = ["Penny","Nickel","Dime","Quarter","Dollar1","Dollar5","Dollar10","Dollar20","Dollar50","Dollar100"]
	amt_val = parse(Float32,amt)
	println("For \$$amt:")
	cent_amt = Integer(round(amt_val * 100,digits = 0))
	filtered_dict = make_change(cent_amt)
	coins_filt = filter(c -> c in keys(filtered_dict),coins)
	print_dict(coins_filt,filtered_dict)
	println("====================================")
end

## Add additional method to the main function
function main()
	coins = ["Penny","Nickel","Dime","Quarter","Dollar1","Dollar5","Dollar10","Dollar20","Dollar50","Dollar100"]
	file_data = ""
	file_data = read("args.txt",String)
	file_split = split(file_data,'\n')
	for args in file_split 
		if args == ""
			continue
		end
		amt_val = parse(Float32,args)
		cent_amt = Integer(round(amt_val * 100,digits = 0))
		filtered_dict = make_change(cent_amt)
		coins_filt = filter(c -> c in keys(filtered_dict),coins)
		# print_dict(coins_filt,filtered_dict)
		# println("====================================")
	end
end

## Run the script 
if length(parse_commandline()) > 0
	@time main()
else
	for a in ARGS 
		main(a)
	end
end
