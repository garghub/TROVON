T_1 int
F_1 ( unsigned long V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
return - V_5 ;
}
T_1 int F_2 ( void )
{
return V_6 ;
}
T_1 void F_3 ( void * V_7 , ... )
{
struct V_8 * V_9 = (struct V_8 * ) ( ( unsigned char * ) & V_7 - 4 ) ;
F_4 ( L_1 ,
( ( V_9 -> V_10 ) & 0xffffff ) - 2 , V_9 -> V_11 , V_9 -> V_12 , V_9 -> V_13 , V_9 -> V_14 , V_9 -> V_15 ) ;
}
int F_5 ( const char * V_16 ,
const char * const V_17 [] ,
const char * const V_18 [] )
{
register long T_2 V_19 ( L_2 ) ;
register const char * const * T_3 V_19 ( L_3 ) = V_18 ;
register const char * const * T_4 V_19 ( L_4 ) = V_17 ;
register const char * T_5 V_19 ( L_5 ) = V_16 ;
__asm__ __volatile__ ("mov.l %1,er0\n\t"
"trapa #0\n\t"
: "=r" (res)
: "g" (__NR_execve),
"g" (_a),
"g" (_b),
"g" (_c)
: "cc", "memory");
return T_2 ;
}
