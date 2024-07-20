def bounty(N):
    MOD = int(1e4 + 7)
    
    if N < 2:
        return 0
    
    total = (9 * pow(10, N-1, MOD)) % MOD
    no_zero = pow(9, N, MOD)
    one_zero = ((N-1) * pow(9, N-1, MOD)) % MOD
    
    valid_numbers = (total - no_zero - one_zero) % MOD
    return valid_numbers

# Test the function with an example
N = 4
print(bounty(N))  # Example output for N=3 check it
