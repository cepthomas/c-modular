
#ifndef CLI_MODULE_H
#define CLI_MODULE_H

#include "common_module.h"

/// @brief Interface to the CLI module.


//---------------- Public API ----------------------//

#define CLI_BUFF_LEN 128

/// Initialize the module.
/// @return Status.
status_t cli_init(void);

/// Check for input and process to output.
/// @param cmd Command to process.
/// @param resp Result of the operation.
/// @return Status.
status_t cli_process(const char* cmd, char* resp);

/// Clean up module resources.
/// @return Status.
status_t cli_destroy(void);


#endif // CLI_MODULE_H
