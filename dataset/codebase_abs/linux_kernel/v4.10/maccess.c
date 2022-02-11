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
int V_13 , V_11 ;
unsigned long V_14 ;
if ( ! V_6 )
return 0 ;
V_14 = F_6 ( 0xf8UL ) ;
V_13 = F_7 ( V_14 ) ;
if ( ! V_13 )
F_8 () ;
V_11 = F_4 ( V_9 , V_2 , V_6 ) ;
if ( ! V_13 )
F_9 () ;
F_10 ( V_14 ) ;
return V_11 ;
}
void F_11 ( void * V_9 , void * V_2 , T_2 V_6 )
{
unsigned long V_15 , V_14 , V_16 ;
V_14 = F_12 () ;
F_13 ( V_15 , 0 , 0 ) ;
F_14 ( 0 , 28 ) ;
V_16 = F_15 () ;
if ( V_16 ) {
F_16 () ;
F_17 ( 0 ) ;
memcpy ( V_9 , V_2 , V_6 ) ;
F_17 ( V_16 ) ;
F_18 () ;
} else {
memcpy ( V_9 , V_2 , V_6 ) ;
}
F_19 ( V_15 , 0 , 0 ) ;
F_20 ( V_14 ) ;
}
int F_21 ( void T_7 * V_9 , void * V_2 , unsigned long V_6 )
{
int V_17 = 0 , V_3 , V_11 ;
char * V_18 ;
V_18 = ( char * ) F_22 ( V_19 ) ;
if ( ! V_18 )
return - V_20 ;
V_11 = - V_12 ;
while ( V_17 < V_6 ) {
V_3 = F_2 ( V_21 , V_6 - V_17 ) ;
if ( F_5 ( V_18 , V_2 + V_17 , V_3 ) )
goto V_22;
if ( F_23 ( V_9 + V_17 , V_18 , V_3 ) )
goto V_22;
V_17 += V_3 ;
}
V_11 = 0 ;
V_22:
F_24 ( ( unsigned long ) V_18 ) ;
return V_11 ;
}
static int F_25 ( unsigned long V_23 )
{
unsigned long V_24 ;
int V_25 ;
if ( V_23 < sizeof( struct V_26 ) )
return 1 ;
F_26 (cpu) {
V_24 = ( unsigned long ) V_27 [ V_25 ] ;
if ( V_23 > V_24 + sizeof( struct V_26 ) - 1 || V_23 < V_24 )
continue;
return 1 ;
}
return 0 ;
}
void * F_27 ( T_8 V_23 )
{
void * V_28 = ( void * ) V_23 ;
unsigned long V_3 ;
F_28 () ;
F_29 () ;
if ( F_25 ( V_23 ) ) {
V_3 = V_21 - ( V_23 & ~ V_29 ) ;
V_28 = ( void * ) F_22 ( V_30 ) ;
if ( V_28 )
F_11 ( V_28 , ( void * ) V_23 , V_3 ) ;
}
F_30 () ;
F_31 () ;
return V_28 ;
}
void F_32 ( T_8 V_23 , void * V_18 )
{
if ( ( void * ) V_23 != V_18 )
F_24 ( ( unsigned long ) V_18 ) ;
}
