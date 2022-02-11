static T_1 long F_1 ( void * V_1 , const void * V_2 , T_2 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
char V_7 [ 8 ] ;
V_4 = ( unsigned long ) V_1 & ~ 7UL ;
V_5 = ( unsigned long ) V_1 & 7UL ;
V_3 = F_2 ( 8UL - V_5 , V_3 ) ;
V_6 = V_3 - 1 ;
asm volatile(
" bras 1,0f\n"
" mvc 0(1,%4),0(%5)\n"
"0: mvc 0(8,%3),0(%0)\n"
" ex %1,0(1)\n"
" lg %1,0(%3)\n"
" lra %0,0(%0)\n"
" sturg %1,%0\n"
: "+&a" (aligned), "+&a" (count), "=m" (tmp)
: "a" (&tmp), "a" (&tmp[offset]), "a" (src)
: "cc", "memory", "1");
return V_3 ;
}
void T_1 F_3 ( void * V_1 , const void * V_2 , T_2 V_3 )
{
long V_8 ;
while ( V_3 ) {
V_8 = F_1 ( V_1 , V_2 , V_3 ) ;
V_1 += V_8 ;
V_2 += V_8 ;
V_3 -= V_8 ;
}
}
static int F_4 ( void * V_9 , void * V_2 , T_2 V_6 )
{
register unsigned long T_3 V_10 ( L_1 ) = ( unsigned long ) V_9 ;
register unsigned long T_4 V_10 ( L_2 ) = ( unsigned long ) V_6 ;
register unsigned long T_5 V_10 ( L_3 ) = ( unsigned long ) V_2 ;
register unsigned long T_6 V_10 ( L_4 ) = ( unsigned long ) V_6 ;
int V_11 = - V_12 ;
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
return V_11 ;
}
int F_5 ( void * V_9 , void * V_2 , T_2 V_6 )
{
unsigned long V_13 ;
int V_11 ;
if ( ! V_6 )
return 0 ;
F_6 ( V_13 ) ;
F_7 ( 0xfbUL ) ;
V_11 = F_4 ( V_9 , V_2 , V_6 ) ;
F_8 ( V_13 ) ;
return V_11 ;
}
void F_9 ( void * V_9 , void * V_2 , T_2 V_6 )
{
unsigned long V_14 , V_13 , V_15 ;
V_13 = F_10 () ;
F_11 ( V_14 , 0 , 0 ) ;
F_12 ( 0 , 28 ) ;
V_15 = F_13 () ;
if ( V_15 ) {
F_14 () ;
F_15 ( 0 ) ;
memcpy ( V_9 , V_2 , V_6 ) ;
F_15 ( V_15 ) ;
F_16 () ;
} else {
memcpy ( V_9 , V_2 , V_6 ) ;
}
F_17 ( V_14 , 0 , 0 ) ;
F_18 ( V_13 ) ;
}
int F_19 ( void T_7 * V_9 , void * V_2 , unsigned long V_6 )
{
int V_16 = 0 , V_3 , V_11 ;
char * V_17 ;
V_17 = ( char * ) F_20 ( V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_11 = - V_12 ;
while ( V_16 < V_6 ) {
V_3 = F_2 ( V_20 , V_6 - V_16 ) ;
if ( F_5 ( V_17 , V_2 + V_16 , V_3 ) )
goto V_21;
if ( F_21 ( V_9 + V_16 , V_17 , V_3 ) )
goto V_21;
V_16 += V_3 ;
}
V_11 = 0 ;
V_21:
F_22 ( ( unsigned long ) V_17 ) ;
return V_11 ;
}
static int F_23 ( unsigned long V_22 )
{
unsigned long V_23 ;
int V_24 ;
if ( V_22 < sizeof( struct V_25 ) )
return 1 ;
F_24 (cpu) {
V_23 = ( unsigned long ) V_26 [ V_24 ] ;
if ( V_22 > V_23 + sizeof( struct V_25 ) - 1 || V_22 < V_23 )
continue;
return 1 ;
}
return 0 ;
}
void * F_25 ( T_8 V_22 )
{
void * V_27 = ( void * ) V_22 ;
unsigned long V_3 ;
F_26 () ;
F_27 () ;
if ( F_23 ( V_22 ) ) {
V_3 = V_20 - ( V_22 & ~ V_28 ) ;
V_27 = ( void * ) F_20 ( V_29 ) ;
if ( V_27 )
F_9 ( V_27 , ( void * ) V_22 , V_3 ) ;
}
F_28 () ;
F_29 () ;
return V_27 ;
}
void F_30 ( T_8 V_22 , void * V_17 )
{
if ( ( void * ) V_22 != V_17 )
F_22 ( ( unsigned long ) V_17 ) ;
}
