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
static unsigned int T_3 F_6 ( void )
{
struct V_5 * V_6 , * V_7 ;
T_1 V_8 = 20000000 ;
V_6 = F_7 ( NULL , NULL ,
L_1 ) ;
if ( ! V_6 )
return V_8 ;
V_7 = F_8 ( V_6 , L_2 , 0 ) ;
F_9 ( V_6 ) ;
if ( ! V_7 )
return V_8 ;
F_10 ( V_7 , L_3 , & V_8 ) ;
F_9 ( V_7 ) ;
return V_8 ;
}
void T_3 F_11 ( void )
{
T_1 V_1 = F_1 () ;
#ifdef F_12
void T_2 * V_9 ;
T_1 V_8 ;
if ( F_13 ( L_4 ) ||
F_13 ( L_5 ) ) {
V_8 = 260000000 / 8 ;
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
V_8 = F_6 () / 2 ;
}
V_9 = F_14 ( 0xe6080000 , V_10 ) ;
if ( ( F_4 ( V_9 + V_11 ) & 1 ) == 0 ||
F_4 ( V_9 + V_12 ) != V_8 ) {
F_15 ( V_8 , V_9 + V_12 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_15 ( 1 , V_9 + V_11 ) ;
}
F_5 ( V_9 ) ;
#endif
F_16 ( V_1 ) ;
F_17 () ;
}
static int T_3 F_18 ( unsigned long V_13 , const char * V_14 ,
int V_15 , void * V_16 )
{
const char * type = F_19 ( V_13 , L_6 , NULL ) ;
const T_4 * V_17 , * V_18 ;
int V_19 ;
struct V_20 * V_21 = V_16 ;
T_5 V_22 = 1ULL << 32 ;
if ( type == NULL || strcmp ( type , L_7 ) )
return 0 ;
V_17 = F_19 ( V_13 , L_8 , & V_19 ) ;
if ( V_17 == NULL )
V_17 = F_19 ( V_13 , L_9 , & V_19 ) ;
if ( V_17 == NULL )
return 0 ;
V_18 = V_17 + ( V_19 / sizeof( T_4 ) ) ;
while ( ( V_18 - V_17 ) >= ( V_23 + V_24 ) ) {
T_5 V_9 , V_25 ;
V_9 = F_20 ( V_23 , & V_17 ) ;
V_25 = F_20 ( V_24 , & V_17 ) ;
if ( V_9 >= V_22 )
continue;
if ( ( V_9 + V_25 ) >= V_22 )
V_25 = V_22 - V_9 ;
if ( V_25 < V_21 -> V_26 )
continue;
if ( V_9 < V_21 -> V_9 )
continue;
V_21 -> V_9 = V_9 + V_25 - V_21 -> V_26 ;
V_21 -> V_25 = V_21 -> V_26 ;
}
return 0 ;
}
void T_3 F_21 ( void )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_26 = V_27 ;
F_22 ( F_18 , & V_21 ) ;
#ifdef F_23
if ( V_21 . V_25 && F_24 ( V_21 . V_9 , V_21 . V_25 ) ) {
static struct V_28 * V_29 ;
F_25 ( V_21 . V_25 , V_21 . V_9 , 0 ,
& V_29 , true ) ;
}
#endif
}
