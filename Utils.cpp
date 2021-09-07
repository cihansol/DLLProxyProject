#include "Utils.h"

namespace Utils
{
    static UINT32 mempage_mask = (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);

    bool IsBadReadPtrEx(void* p)
    {
        MEMORY_BASIC_INFORMATION mbi = { 0 };
        if (::VirtualQuery(p, &mbi, sizeof(mbi)))
        {
            bool b = !(mbi.Protect & mempage_mask);
            // check the page is not a guard page
            if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) b = true;
            return b;
        }
        return true; //Unable to Query
    }

};