static long F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 ;
int V_6 , V_7 ;
int V_8 = - V_9 ;
V_5 = ( unsigned long ) V_1 & ~ 3UL ;
V_6 = ( unsigned long ) V_1 & 3 ;
V_4 = F_2 (unsigned long, 4 - offset, size) ;
V_7 = ( 0xf << ( 4 - V_4 ) ) & 0xf ;
V_7 >>= V_6 ;
asm volatile(
" bras 1,0f\n"
" icm 0,0,0(%3)\n"
"0: l 0,0(%1)\n"
" lra %1,0(%1)\n"
"1: ex %2,0(1)\n"
"2: stura 0,%1\n"
" la %0,0\n"
"3:\n"
EX_TABLE(0b,3b) EX_TABLE(1b,3b) EX_TABLE(2b,3b)
: "+d" (rc), "+a" (aligned)
: "a" (mask), "a" (src) : "cc", "memory", "0", "1");
return V_8 ? V_8 : V_4 ;
}
long F_3 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
long V_10 = 0 ;
while ( V_3 ) {
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_10 < 0 )
break;
V_1 += V_10 ;
V_2 += V_10 ;
V_3 -= V_10 ;
}
return V_10 < 0 ? - V_9 : 0 ;
}
static int F_4 ( void * V_11 , void * V_2 , T_1 V_4 )
{
register unsigned long T_2 V_12 ( L_1 ) = ( unsigned long ) V_11 ;
register unsigned long T_3 V_12 ( L_2 ) = ( unsigned long ) V_4 ;
register unsigned long T_4 V_12 ( L_3 ) = ( unsigned long ) V_2 ;
register unsigned long T_5 V_12 ( L_4 ) = ( unsigned long ) V_4 ;
int V_8 = - V_9 ;
asm volatile (
"0: mvcle %1,%2,0x0\n"
"1: jo 0b\n"
" lhi %0,0x0\n"
"2:\n"
EX_TABLE(1b,2b)
: "+d" (rc), "+d" (_dest), "+d" (_src), "+d" (_len1),
"+d" (_len2), "=m" (*((long *) dest))
: "m" (*((long *) src))
: "cc", "memory");
return V_8 ;
}
int F_5 ( void * V_11 , void * V_2 , T_1 V_4 )
{
unsigned long V_13 ;
int V_8 ;
if ( ! V_4 )
return 0 ;
F_6 ( V_13 ) ;
F_7 ( 0xfbUL ) ;
V_8 = F_4 ( V_11 , V_2 , V_4 ) ;
F_8 ( V_13 ) ;
return V_8 ;
}
void F_9 ( void * V_11 , void * V_2 , T_1 V_4 )
{
unsigned long V_14 , V_13 , V_15 ;
V_13 = F_10 () ;
F_11 ( V_14 , 0 , 0 ) ;
F_12 ( 0 , 28 ) ;
V_15 = F_13 () ;
if ( V_15 ) {
F_14 () ;
F_15 ( 0 ) ;
memcpy ( V_11 , V_2 , V_4 ) ;
F_15 ( V_15 ) ;
F_16 () ;
} else {
memcpy ( V_11 , V_2 , V_4 ) ;
}
F_17 ( V_14 , 0 , 0 ) ;
F_18 ( V_13 ) ;
}
int F_19 ( void T_6 * V_11 , void * V_2 , T_1 V_4 )
{
int V_16 = 0 , V_3 , V_8 ;
char * V_17 ;
V_17 = ( char * ) F_20 ( V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_8 = - V_9 ;
while ( V_16 < V_4 ) {
V_3 = F_21 ( V_20 , V_4 - V_16 ) ;
if ( F_5 ( V_17 , V_2 + V_16 , V_3 ) )
goto V_21;
if ( F_22 ( V_11 + V_16 , V_17 , V_3 ) )
goto V_21;
V_16 += V_3 ;
}
V_8 = 0 ;
V_21:
F_23 ( ( unsigned long ) V_17 ) ;
return V_8 ;
}
int F_24 ( void * V_11 , void T_6 * V_2 , T_1 V_4 )
{
int V_16 = 0 , V_3 , V_8 ;
char * V_17 ;
V_17 = ( char * ) F_20 ( V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_8 = - V_9 ;
while ( V_16 < V_4 ) {
V_3 = F_21 ( V_20 , V_4 - V_16 ) ;
if ( F_25 ( V_17 , V_2 + V_16 , V_3 ) )
goto V_21;
if ( F_5 ( V_11 + V_16 , V_17 , V_3 ) )
goto V_21;
V_16 += V_3 ;
}
V_8 = 0 ;
V_21:
F_23 ( ( unsigned long ) V_17 ) ;
return V_8 ;
}
static int F_26 ( unsigned long V_22 )
{
unsigned long V_23 ;
int V_24 ;
if ( V_22 < sizeof( struct V_25 ) )
return 1 ;
F_27 (cpu) {
V_23 = ( unsigned long ) V_26 [ V_24 ] ;
if ( V_22 > V_23 + sizeof( struct V_25 ) - 1 || V_22 < V_23 )
continue;
return 1 ;
}
return 0 ;
}
void * F_28 ( unsigned long V_22 )
{
void * V_27 = ( void * ) V_22 ;
unsigned long V_3 ;
F_29 () ;
F_30 () ;
if ( F_26 ( V_22 ) ) {
V_3 = V_20 - ( V_22 & ~ V_28 ) ;
V_27 = ( void * ) F_20 ( V_29 ) ;
if ( V_27 )
F_9 ( V_27 , ( void * ) V_22 , V_3 ) ;
}
F_31 () ;
F_32 () ;
return V_27 ;
}
void F_33 ( unsigned long V_22 , void * V_17 )
{
if ( ( void * ) V_22 != V_17 )
F_23 ( ( unsigned long ) V_17 ) ;
}
