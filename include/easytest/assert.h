/**
 * @brief Checks if a given condition is true,
 * if it is true, does nothing, else it stores that the given test failed.
 *
 * @param condition The condition which has to be true.
 * @param fail_msg The message to print if the test has failed.
 * Defaults to "".
 */
void assert(int condition, char *fail_msg);
