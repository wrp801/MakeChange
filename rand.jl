@assert length(ARGS) == 1
using Random
using Distributions
using DelimitedFiles

function main(n::Int64)
	# delete the file if it already exists
	if "args.txt" in readdir()
		rm("args.txt")
	end
	arr = rand(Uniform(0.01,1000.00),n)::Base.Array{Float64}
	res = map(x -> round(x,digits = 2),arr)
	writedlm("temp.txt",res)
	touch("args.txt")
	n_lines = countlines("temp.txt")
	output = open("args.txt","a")
	## the default of writelm will have a blank line as the last item, the code below will fix that
	open("temp.txt") do input
		i = 1
		for line in eachline(input)
			if line != "" 
				if i == n_lines
					write(output,line)
				else
					write(output,line)
					write(output,'\n')
					i+=1
				end
			end
		end
	end
	rm("temp.txt")
end

main(parse(Int64,ARGS[1]))