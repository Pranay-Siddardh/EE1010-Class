#Code by T.Pranay
#Date:- 5-10-26

import numpy as np


def verify_ranks(k):
    # kx + y = 1
    #  x + ky = -1
    A = np.array([[k, 1], [1, k]], dtype=float)
    b = np.array([[1], [-1]], dtype=float)

    # Build the augmented matrix [A|b]
    augmented = np.hstack((A, b))

    # Calculate ranks
    rank_A = np.linalg.matrix_rank(A)
    rank_augmented = np.linalg.matrix_rank(augmented)

    print(f"--- Testing k = {k} ---")
    print(f"Rank of A: {rank_A}")
    print(f"Rank of Augmented Matrix: {rank_augmented}")

    # Decision based strictly on ranks
    if rank_A != rank_augmented:
        print("Conclusion: No Solution")
    elif rank_A == 2:
        print("Conclusion: Unique Solution")
    else:
        print("Conclusion: Infinitely Many Solutions")
    print()


# Case 1: k = 2 (Unique solution condition)
verify_ranks(2.0)

# Case 2: k = 1 (No solution condition)
verify_ranks(1.0)

# Case 3: k = -1 (Infinite solutions condition)
verify_ranks(-1.0)

