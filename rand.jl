@assert length(ARGS) == 1
using Random
using Distributions
using DelimitedFiles

function main(n::Int64)
	arr = rand(Uniform(0.01,1000.00),n)::Base.Array{Float64}
	res = map(x -> round(x,digits = 2),arr)
	writedlm("args.txt",res)
end

main(parse(Int64,ARGS[1]))