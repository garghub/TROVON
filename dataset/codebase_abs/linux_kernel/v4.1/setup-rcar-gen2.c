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
T_1 V_1 = F_1 () ;
#ifdef F_7
void T_2 * V_5 ;
int V_6 = 0 ;
T_1 V_7 ;
if ( F_8 ( L_1 ) ) {
V_7 = 260000000 / 8 ;
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
V_6 = 15 ;
break;
case F_9 ( 13 ) :
V_6 = 20 ;
break;
case F_9 ( 14 ) :
V_6 = 26 ;
break;
case F_9 ( 13 ) | F_9 ( 14 ) :
V_6 = 30 ;
break;
}
V_7 = V_6 * ( 1000000 / 2 ) ;
}
V_5 = F_10 ( 0xe6080000 , V_8 ) ;
if ( ( F_4 ( V_5 + V_9 ) & 1 ) == 0 ||
F_4 ( V_5 + V_10 ) != V_7 ) {
F_11 ( V_7 , V_5 + V_10 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_11 ( 1 , V_5 + V_9 ) ;
}
F_5 ( V_5 ) ;
#endif
F_12 ( V_1 ) ;
#ifdef F_13
F_14 () ;
#endif
}
static int T_3 F_15 ( unsigned long V_11 , const char * V_12 ,
int V_13 , void * V_14 )
{
const char * type = F_16 ( V_11 , L_2 , NULL ) ;
const T_4 * V_15 , * V_16 ;
int V_17 ;
struct V_18 * V_19 = V_14 ;
T_5 V_20 = 1ULL << 32 ;
if ( type == NULL || strcmp ( type , L_3 ) )
return 0 ;
V_15 = F_16 ( V_11 , L_4 , & V_17 ) ;
if ( V_15 == NULL )
V_15 = F_16 ( V_11 , L_5 , & V_17 ) ;
if ( V_15 == NULL )
return 0 ;
V_16 = V_15 + ( V_17 / sizeof( T_4 ) ) ;
while ( ( V_16 - V_15 ) >= ( V_21 + V_22 ) ) {
T_5 V_5 , V_23 ;
V_5 = F_17 ( V_21 , & V_15 ) ;
V_23 = F_17 ( V_22 , & V_15 ) ;
if ( V_5 >= V_20 )
continue;
if ( ( V_5 + V_23 ) >= V_20 )
V_23 = V_20 - V_5 ;
if ( V_23 < V_19 -> V_24 )
continue;
if ( V_5 < V_19 -> V_5 )
continue;
V_19 -> V_5 = V_5 + V_23 - V_19 -> V_24 ;
V_19 -> V_23 = V_19 -> V_24 ;
}
return 0 ;
}
void T_3 F_18 ( void )
{
struct V_18 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_24 = V_25 ;
F_19 ( F_15 , & V_19 ) ;
#ifdef F_20
if ( V_19 . V_23 && F_21 ( V_19 . V_5 , V_19 . V_23 ) )
F_22 ( V_19 . V_23 , V_19 . V_5 , 0 ,
& V_26 , true ) ;
#endif
}
