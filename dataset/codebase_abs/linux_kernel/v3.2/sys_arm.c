T_1 int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return F_3 ( V_3 , V_2 -> V_4 , V_2 , 0 , NULL , NULL ) ;
#else
return ( - V_5 ) ;
#endif
}
T_1 int F_4 ( unsigned long V_6 , unsigned long V_7 ,
int T_2 * V_8 , int V_9 ,
int T_2 * V_10 , struct V_1 * V_2 )
{
if ( ! V_7 )
V_7 = V_2 -> V_4 ;
return F_3 ( V_6 , V_7 , V_2 , 0 , V_8 , V_10 ) ;
}
T_1 int F_5 ( struct V_1 * V_2 )
{
return F_3 ( V_11 | V_12 | V_3 , V_2 -> V_4 , V_2 , 0 , NULL , NULL ) ;
}
T_1 int F_6 ( const char T_2 * V_13 ,
const char T_2 * const T_2 * V_14 ,
const char T_2 * const T_2 * V_15 , struct V_1 * V_2 )
{
int error ;
char * V_16 ;
V_16 = F_7 ( V_13 ) ;
error = F_8 ( V_16 ) ;
if ( F_9 ( V_16 ) )
goto V_17;
error = F_10 ( V_16 , V_14 , V_15 , V_2 ) ;
F_11 ( V_16 ) ;
V_17:
return error ;
}
int F_12 ( const char * V_16 ,
const char * const V_14 [] ,
const char * const V_15 [] )
{
struct V_1 V_2 ;
int V_18 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
V_18 = F_10 ( V_16 ,
( const char T_2 * const T_2 * ) V_14 ,
( const char T_2 * const T_2 * ) V_15 , & V_2 ) ;
if ( V_18 < 0 )
goto V_17;
V_2 . V_19 = V_18 ;
asm( "add r0, %0, %1\n\t"
"mov r1, %2\n\t"
"mov r2, %3\n\t"
"bl memmove\n\t"
"mov r8, #0\n\t"
"mov r9, %0\n\t"
"mov sp, r0\n\t"
"b ret_to_user"
:
: "r" (current_thread_info()),
"Ir" (THREAD_START_SP - sizeof(regs)),
"r" (&regs),
"Ir" (sizeof(regs))
: "r0", "r1", "r2", "r3", "ip", "lr", "memory");
V_17:
return V_18 ;
}
T_1 long F_13 ( int V_20 , int V_21 ,
T_3 V_22 , T_3 V_23 )
{
return F_14 ( V_20 , V_22 , V_23 , V_21 ) ;
}
