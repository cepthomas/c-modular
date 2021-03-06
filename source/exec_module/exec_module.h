

#ifndef EXEC_MODULE_H
#define EXEC_MODULE_H

#include "common_module.h"


/// @brief Interface to the exec module.


//---------------- Public API ----------------------//

/// Initialize the module.
/// @return Status.
status_t exec_init(void);

/// Enter the forever loop.
/// @return Status on exit.
status_t exec_run(void);

/// Stop and clean up module resources.
/// @return Status.
status_t exec_destroy(void);


#endif // EXEC_MODULE_H
