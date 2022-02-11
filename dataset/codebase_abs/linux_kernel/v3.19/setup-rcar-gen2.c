T_1 F_1 ( void )
{
static T_1 V_1 ;
static bool V_2 ;
if ( ! V_2 ) {
void T_2 * V_3 = F_2 ( V_4 , 4 ) ;
F_3 ( ! V_3 ) ;
V_1 = F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
V_2 = true ;
}
return V_1 ;
}
void T_3 F_6 ( void )
{
#if F_7 ( V_5 ) || F_7 ( V_6 )
T_1 V_1 = F_1 () ;
bool V_7 = ( bool ) F_8 ( NULL , NULL ,
L_1 ) ;
#endif
#ifdef V_5
void T_2 * V_8 ;
int V_9 = 0 ;
T_1 V_10 ;
if ( V_7 ) {
V_10 = 260000000 / 8 ;
asm volatile(
" cps 0x16\n"
" mrc p15, 0, r1, c1, c1, 0\n"
" orr r0, r1, #1\n"
" mcr p15, 0, r0, c1, c1, 0\n"
" isb\n"
" mov r0, #0\n"
" mcrr p15, 4, r0, r0, c14\n"
" isb\n"
" mcr p15, 0, r1, c1, c1, 0\n"
" isb\n"
" cps 0x13\n"
: : : "r0", "r1");
} else {
switch ( V_1 & ( F_9 ( 14 ) | F_9 ( 13 ) ) ) {
case 0 :
V_9 = 15 ;
break;
case F_9 ( 13 ) :
V_9 = 20 ;
break;
case F_9 ( 14 ) :
V_9 = 26 ;
break;
case F_9 ( 13 ) | F_9 ( 14 ) :
V_9 = 30 ;
break;
}
V_10 = V_9 * ( 1000000 / 2 ) ;
}
V_8 = F_10 ( 0xe6080000 , V_11 ) ;
if ( ( F_4 ( V_8 + V_12 ) & 1 ) == 0 ||
F_4 ( V_8 + V_13 ) != V_10 ) {
F_11 ( V_10 , V_8 + V_13 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_11 ( 1 , V_8 + V_12 ) ;
}
F_5 ( V_8 ) ;
#endif
#ifdef V_6
F_12 ( V_1 ) ;
#endif
#ifdef F_13
F_14 () ;
#endif
}
static int T_3 F_15 ( unsigned long V_14 , const char * V_15 ,
int V_16 , void * V_17 )
{
const char * type = F_16 ( V_14 , L_2 , NULL ) ;
const T_4 * V_18 , * V_19 ;
int V_20 ;
struct V_21 * V_22 = V_17 ;
T_5 V_23 = 1ULL << 32 ;
if ( type == NULL || strcmp ( type , L_3 ) )
return 0 ;
V_18 = F_16 ( V_14 , L_4 , & V_20 ) ;
if ( V_18 == NULL )
V_18 = F_16 ( V_14 , L_5 , & V_20 ) ;
if ( V_18 == NULL )
return 0 ;
V_19 = V_18 + ( V_20 / sizeof( T_4 ) ) ;
while ( ( V_19 - V_18 ) >= ( V_24 + V_25 ) ) {
T_5 V_8 , V_26 ;
V_8 = F_17 ( V_24 , & V_18 ) ;
V_26 = F_17 ( V_25 , & V_18 ) ;
if ( V_8 >= V_23 )
continue;
if ( ( V_8 + V_26 ) >= V_23 )
V_26 = V_23 - V_8 ;
if ( V_26 < V_22 -> V_27 )
continue;
if ( V_8 < V_22 -> V_8 )
continue;
V_22 -> V_8 = V_8 + V_26 - V_22 -> V_27 ;
V_22 -> V_26 = V_22 -> V_27 ;
}
return 0 ;
}
void T_3 F_18 ( void )
{
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_27 = V_28 ;
F_19 ( F_15 , & V_22 ) ;
#ifdef F_20
if ( V_22 . V_26 )
F_21 ( V_22 . V_26 , V_22 . V_8 , 0 ,
& V_29 , true ) ;
#endif
}
