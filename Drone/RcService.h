#ifndef CLASS_RC_SERVICE
#define CLASS_RC_SERVICE

#include "LevelService.h"

class RcService
{
private:
    LevelService *_levelService;

public:
    RcService(LevelService *levelService);
};

#endif