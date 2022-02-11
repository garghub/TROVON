T_1 long F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 | V_4 | V_5 , V_2 -> V_6 ,
V_2 , 0 , NULL , NULL ) ;
}
T_1 long F_3 ( int V_7 , unsigned long V_8 ,
struct V_1 * V_2 )
{
if ( ! V_8 )
V_8 = V_2 -> V_6 ;
return F_2 ( V_7 , V_8 , V_2 , 0 , NULL , NULL ) ;
}
T_1 long F_4 ( const char T_2 * V_9 ,
const char T_2 * const T_2 * V_10 ,
const char T_2 * const T_2 * V_11 ,
struct V_1 * V_2 )
{
int error ;
char * V_12 ;
V_12 = F_5 ( V_9 ) ;
error = F_6 ( V_12 ) ;
if ( F_7 ( V_12 ) )
goto V_13;
error = F_8 ( V_12 , V_10 , V_11 , V_2 ) ;
F_9 ( V_12 ) ;
V_13:
return error ;
}
T_1 long F_10 ( unsigned long V_14 , unsigned long V_15 ,
unsigned long V_16 , unsigned long V_7 ,
unsigned long V_17 , T_3 V_18 )
{
if ( V_18 & ~ V_19 )
return - V_20 ;
return F_11 ( V_14 , V_15 , V_16 , V_7 , V_17 , V_18 >> V_21 ) ;
}
int F_12 ( const char * V_12 ,
const char * const V_10 [] ,
const char * const V_11 [] )
{
register const char * T_4 V_22 ( L_1 ) = V_12 ;
register const void * T_5 V_22 ( L_2 ) = V_10 ;
register const void * T_6 V_22 ( L_3 ) = V_11 ;
register unsigned long T_7 V_22 ( L_4 ) = V_23 ;
register unsigned long T_8 V_22 ( L_5 ) ;
__asm__ __volatile__ ("brki r14, 0x8"
: "=r" (__ret), "=r" (__syscall)
: "1" (__syscall), "r" (__a), "r" (__b), "r" (__c)
: "r4", "r8", "r9",
"r10", "r11", "r14", "cc", "memory");
return T_8 ;
}
