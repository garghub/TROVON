T_1 long
F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 , unsigned long V_6 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
T_1 long
F_3 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 , T_2 V_7 )
{
if ( F_4 ( V_7 & ~ V_8 ) )
return - V_9 ;
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_7 >> V_10 ) ;
}
T_1 long
F_5 ( struct V_11 * V_12 )
{
return F_6 ( V_13 , V_12 -> V_12 [ 0 ] , V_12 , 0 , NULL , NULL ) ;
}
T_1 long
F_7 ( struct V_11 * V_12 )
{
unsigned long V_14 ;
unsigned long V_15 ;
int T_3 * V_16 , * V_17 ;
V_14 = V_12 -> V_12 [ 4 ] ;
V_15 = V_12 -> V_12 [ 5 ] ;
if ( ! V_15 )
V_15 = V_12 -> V_12 [ 0 ] ;
V_16 = ( int T_3 * ) V_12 -> V_12 [ 6 ] ;
V_17 = ( int T_3 * ) V_12 -> V_12 [ 8 ] ;
return F_6 ( V_14 , V_15 , V_12 , 0 ,
V_16 , V_17 ) ;
}
T_1 long
F_8 ( struct V_11 * V_12 )
{
return F_6 ( V_18 | V_19 | V_13 ,
V_12 -> V_12 [ 0 ] , V_12 , 0 , NULL , NULL ) ;
}
T_1 long
F_9 ( struct V_11 * V_12 )
{
int error ;
struct V_20 * V_20 ;
V_20 = F_10 ( ( char T_3 * ) V_12 -> V_12 [ 4 ] ) ;
error = F_11 ( V_20 ) ;
if ( F_12 ( V_20 ) )
return error ;
error = F_13 ( V_20 -> V_21 ,
( const char T_3 * const T_3 * ) V_12 -> V_12 [ 5 ] ,
( const char T_3 * const T_3 * ) V_12 -> V_12 [ 6 ] ,
V_12 ) ;
F_14 ( V_20 ) ;
return error ;
}
T_1
int F_15 ( const char * V_20 ,
const char * const V_22 [] ,
const char * const V_23 [] )
{
register unsigned long T_4 V_24 ( L_1 ) = ( unsigned long ) V_20 ;
register unsigned long T_5 V_24 ( L_2 ) = ( unsigned long ) V_22 ;
register unsigned long T_6 V_24 ( L_3 ) = ( unsigned long ) V_23 ;
register unsigned long T_7 V_24 ( L_4 ) ;
__asm__ __volatile__ (" \n"
"ldi r27, %5 \n"
"syscall \n"
"mv %0, r4 \n"
"mv %1, r7 \n"
: "=&r" (__r4), "=r" (__r7)
: "r" (__r4), "r" (__r5), "r" (__r6), "i" (__NR_execve)
: "r8", "r9", "r10", "r11", "r22", "r23", "r24", "r25",
"r26", "r27", "memory");
if ( T_7 == 0 )
return T_4 ;
return - T_4 ;
}
