/**
 * @brief Checks if a given condition is true,
 * if it is true, does nothing, else it stores that the given test failed.
 *
 * @param condition The condition which has to be true.
 */
void assert_true(int condition);

/**
 * @brief Checks if the given input matches the expected value within
 * a given tolerance.
 *
 * @param input The value to check.
 * @param expected The expected value.
 * @param tolerance The tolerance which can be off from the 
 * expected value
 *
 * @note If tolerance is 0.0 it will be assigned to 1e-4 (0.0001)
 */
void assert_close(
        double input,
        double expected,
        double tolerance,
        );
