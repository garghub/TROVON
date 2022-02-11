static unsigned int T_1 F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
T_2 V_4 = 20000000 ;
V_2 = F_2 ( NULL , NULL ,
L_1 ) ;
if ( ! V_2 )
return V_4 ;
V_3 = F_3 ( V_2 , L_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_3 )
return V_4 ;
F_5 ( V_3 , L_3 , & V_4 ) ;
F_4 ( V_3 ) ;
return V_4 ;
}
void T_1 F_6 ( void )
{
#ifdef F_7
void T_3 * V_5 ;
T_2 V_4 ;
if ( F_8 ( L_4 ) ||
F_8 ( L_5 ) ) {
V_4 = 260000000 / 8 ;
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
V_4 = F_1 () / 2 ;
}
V_5 = F_9 ( 0xe6080000 , V_6 ) ;
if ( ( F_10 ( V_5 + V_7 ) & 1 ) == 0 ||
F_10 ( V_5 + V_8 ) != V_4 ) {
F_11 ( V_4 , V_5 + V_8 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_11 ( 1 , V_5 + V_7 ) ;
}
F_12 ( V_5 ) ;
#endif
F_13 ( NULL ) ;
F_14 () ;
}
static int T_1 F_15 ( unsigned long V_9 , const char * V_10 ,
int V_11 , void * V_12 )
{
const char * type = F_16 ( V_9 , L_6 , NULL ) ;
const T_4 * V_13 , * V_14 ;
int V_15 ;
struct V_16 * V_17 = V_12 ;
T_5 V_18 = 1ULL << 32 ;
if ( type == NULL || strcmp ( type , L_7 ) )
return 0 ;
V_13 = F_16 ( V_9 , L_8 , & V_15 ) ;
if ( V_13 == NULL )
V_13 = F_16 ( V_9 , L_9 , & V_15 ) ;
if ( V_13 == NULL )
return 0 ;
V_14 = V_13 + ( V_15 / sizeof( T_4 ) ) ;
while ( ( V_14 - V_13 ) >= ( V_19 + V_20 ) ) {
T_5 V_5 , V_21 ;
V_5 = F_17 ( V_19 , & V_13 ) ;
V_21 = F_17 ( V_20 , & V_13 ) ;
if ( V_5 >= V_18 )
continue;
if ( ( V_5 + V_21 ) >= V_18 )
V_21 = V_18 - V_5 ;
if ( V_21 < V_17 -> V_22 )
continue;
if ( V_5 < V_17 -> V_5 )
continue;
V_17 -> V_5 = V_5 + V_21 - V_17 -> V_22 ;
V_17 -> V_21 = V_17 -> V_22 ;
}
return 0 ;
}
void T_1 F_18 ( void )
{
struct V_16 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_22 = V_23 ;
F_19 ( F_15 , & V_17 ) ;
#ifdef F_20
if ( V_17 . V_21 && F_21 ( V_17 . V_5 , V_17 . V_21 ) ) {
static struct V_24 * V_25 ;
F_22 ( V_17 . V_21 , V_17 . V_5 , 0 ,
& V_25 , true ) ;
}
#endif
}
