void
get_compiler_info(GString *str)
{
#if defined(__GNUC__) && defined(__VERSION__)
#if defined(__clang__)
g_string_append_printf(str, "\n\nBuilt using clang %s.\n", __VERSION__);
#elif defined(__llvm__)
g_string_append_printf(str, "\n\nBuilt using llvm-gcc %s.\n", __VERSION__);
#else
g_string_append_printf(str, "\n\nBuilt using gcc %s.\n", __VERSION__);
#endif
#elif defined(__HP_aCC)
g_string_append_printf(str, "\n\nBuilt using HP aCC %d.\n", __HP_aCC);
#elif defined(__xlC__)
g_string_append_printf(str, "\n\nBuilt using IBM XL C %d.%d\n",
(__xlC__ >> 8) & 0xFF, __xlC__ & 0xFF);
#ifdef __IBMC__
if ((__IBMC__ % 10) != 0)
g_string_append_printf(str, " patch %d", __IBMC__ % 10);
#endif
g_string_append_printf(str, "\n");
#elif defined(__INTEL_COMPILER)
g_string_append_printf(str, "\n\nBuilt using Intel C %d.%d",
__INTEL_COMPILER / 100, (__INTEL_COMPILER / 10) % 10);
if ((__INTEL_COMPILER % 10) != 0)
g_string_append_printf(str, " patch %d", __INTEL_COMPILER % 10);
#ifdef __INTEL_COMPILER_BUILD_DATE
g_string_sprinta(str, ", compiler built %04d-%02d-%02d",
__INTEL_COMPILER_BUILD_DATE / 10000,
(__INTEL_COMPILER_BUILD_DATE / 100) % 100,
__INTEL_COMPILER_BUILD_DATE % 100);
#endif
g_string_append_printf(str, "\n");
#elif defined(_MSC_FULL_VER)
# if _MSC_FULL_VER > 99999999
g_string_append_printf(str, "\n\nBuilt using Microsoft Visual C++ %d.%d",
(_MSC_FULL_VER / 10000000) - 6,
(_MSC_FULL_VER / 100000) % 100);
# if (_MSC_FULL_VER % 100000) != 0
g_string_append_printf(str, " build %d",
_MSC_FULL_VER % 100000);
# endif
# else
g_string_append_printf(str, "\n\nBuilt using Microsoft Visual C++ %d.%d",
(_MSC_FULL_VER / 1000000) - 6,
(_MSC_FULL_VER / 10000) % 100);
# if (_MSC_FULL_VER % 10000) != 0
g_string_append_printf(str, " build %d",
_MSC_FULL_VER % 10000);
# endif
# endif
g_string_append_printf(str, "\n");
#elif defined(_MSC_VER)
g_string_append_printf(str, "\n\nBuilt using Microsoft Visual C++ %d.%d\n",
(_MSC_VER / 100) - 6, _MSC_VER % 100);
#elif defined(__SUNPRO_C)
g_string_append_printf(str, "\n\nBuilt using Sun C %d.%d",
(__SUNPRO_C >> 8) & 0xF, (__SUNPRO_C >> 4) & 0xF);
if ((__SUNPRO_C & 0xF) != 0)
g_string_append_printf(str, " patch %d", __SUNPRO_C & 0xF);
g_string_append_printf(str, "\n");
#endif
}
