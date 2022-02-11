static unsigned int T_1 F_1 ( void )
{
const struct V_1 * V_2 ;
struct V_3 * V_4 , * V_5 ;
T_2 V_6 = 20000000 ;
int V_7 = 0 ;
V_4 = F_2 ( NULL , V_8 , & V_2 ) ;
if ( ! V_4 )
return V_6 ;
if ( V_2 -> V_9 )
V_7 = F_3 ( V_4 , L_1 , V_2 -> V_9 ) ;
V_5 = F_4 ( V_4 , L_2 , V_7 ) ;
F_5 ( V_4 ) ;
if ( ! V_5 )
return V_6 ;
F_6 ( V_5 , L_3 , & V_6 ) ;
F_5 ( V_5 ) ;
return V_6 ;
}
void T_1 F_7 ( void )
{
#ifdef F_8
void T_3 * V_10 ;
T_2 V_6 ;
if ( F_9 ( L_4 ) ||
F_9 ( L_5 ) ||
F_9 ( L_6 ) ) {
V_6 = 260000000 / 8 ;
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
V_6 = F_1 () / 2 ;
}
V_10 = F_10 ( 0xe6080000 , V_11 ) ;
if ( ( F_11 ( V_10 + V_12 ) & 1 ) == 0 ||
F_11 ( V_10 + V_13 ) != V_6 ) {
F_12 ( V_6 , V_10 + V_13 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_12 ( 1 , V_10 + V_12 ) ;
}
F_13 ( V_10 ) ;
#endif
F_14 ( NULL ) ;
F_15 () ;
}
static int T_1 F_16 ( unsigned long V_14 , const char * V_15 ,
int V_16 , void * V_9 )
{
const char * type = F_17 ( V_14 , L_7 , NULL ) ;
const T_4 * V_17 , * V_18 ;
int V_19 ;
struct V_20 * V_21 = V_9 ;
T_5 V_22 = 1ULL << 32 ;
if ( type == NULL || strcmp ( type , L_8 ) )
return 0 ;
V_17 = F_17 ( V_14 , L_9 , & V_19 ) ;
if ( V_17 == NULL )
V_17 = F_17 ( V_14 , L_10 , & V_19 ) ;
if ( V_17 == NULL )
return 0 ;
V_18 = V_17 + ( V_19 / sizeof( T_4 ) ) ;
while ( ( V_18 - V_17 ) >= ( V_23 + V_24 ) ) {
T_5 V_10 , V_25 ;
V_10 = F_18 ( V_23 , & V_17 ) ;
V_25 = F_18 ( V_24 , & V_17 ) ;
if ( V_10 >= V_22 )
continue;
if ( ( V_10 + V_25 ) >= V_22 )
V_25 = V_22 - V_10 ;
if ( V_25 < V_21 -> V_26 )
continue;
if ( V_10 < V_21 -> V_10 )
continue;
V_21 -> V_10 = V_10 + V_25 - V_21 -> V_26 ;
V_21 -> V_25 = V_21 -> V_26 ;
}
return 0 ;
}
void T_1 F_19 ( void )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_26 = V_27 ;
F_20 ( F_16 , & V_21 ) ;
#ifdef F_21
if ( V_21 . V_25 && F_22 ( V_21 . V_10 , V_21 . V_25 ) ) {
static struct V_28 * V_29 ;
F_23 ( V_21 . V_25 , V_21 . V_10 , 0 ,
& V_29 , true ) ;
}
#endif
}
