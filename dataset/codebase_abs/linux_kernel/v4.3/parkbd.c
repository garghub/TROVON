static int F_1 ( void )
{
return ( F_2 ( V_1 -> V_2 ) >> 6 ) ^ 2 ;
}
static void F_3 ( int V_3 )
{
F_4 ( V_1 -> V_2 , ( ~ V_3 & 3 ) | 0x10 ) ;
}
static int F_5 ( struct V_4 * V_2 , unsigned char V_5 )
{
unsigned char V_6 ;
if ( ! V_7 ) return - 1 ;
V_6 = V_5 ^ ( V_5 >> 4 ) ;
V_6 = V_6 ^ ( V_6 >> 2 ) ;
V_6 = V_6 ^ ( V_6 >> 1 ) ;
V_8 = 0 ;
V_9 = 1 ;
V_10 = V_5 | ( ( ( int ) ( ~ V_6 & 1 ) ) << 8 ) | 0x600 ;
F_3 ( 2 ) ;
return 0 ;
}
static void F_6 ( void * V_11 )
{
if ( V_9 ) {
if ( V_8 && ( ( V_8 == 11 ) || F_7 ( V_12 , V_13 + V_14 / 100 ) ) ) {
V_8 = 0 ;
V_10 = 0 ;
V_9 = 0 ;
F_3 ( 3 ) ;
return;
}
F_3 ( ( ( V_10 >> V_8 ++ ) & 1 ) | 2 ) ;
if ( V_8 == 11 ) {
V_8 = 0 ;
V_10 = 0 ;
V_9 = 0 ;
F_3 ( 3 ) ;
}
} else {
if ( ( V_8 == V_7 + 10 ) || F_7 ( V_12 , V_13 + V_14 / 100 ) ) {
V_8 = 0 ;
V_10 = 0 ;
}
V_10 |= ( F_1 () >> 1 ) << V_8 ++ ;
if ( V_8 == V_7 + 10 )
F_8 ( V_15 , ( V_10 >> ( 2 - V_7 ) ) & 0xff , 0 ) ;
}
V_13 = V_12 ;
}
static int F_9 ( void )
{
struct V_16 * V_17 ;
V_17 = F_10 ( V_18 ) ;
if ( V_17 == NULL ) {
F_11 ( V_19 L_1 ) ;
return - V_20 ;
}
V_1 = F_12 ( V_17 , L_2 , NULL , NULL , F_6 , V_21 , NULL ) ;
F_13 ( V_17 ) ;
if ( ! V_1 )
return - V_20 ;
if ( F_14 ( V_1 ) ) {
F_15 ( V_1 ) ;
return - V_22 ;
}
V_23 = V_12 ;
return 0 ;
}
static struct V_4 * T_1 F_16 ( void )
{
struct V_4 * V_4 ;
V_4 = F_17 ( sizeof( struct V_4 ) , V_24 ) ;
if ( V_4 ) {
V_4 -> V_25 . type = V_7 ;
V_4 -> V_26 = F_5 ,
F_18 ( V_4 -> V_27 , L_3 , sizeof( V_4 -> V_27 ) ) ;
snprintf ( V_4 -> V_28 , sizeof( V_4 -> V_28 ) , L_4 , V_1 -> V_2 -> V_27 ) ;
}
return V_4 ;
}
static int T_1 F_19 ( void )
{
int V_29 ;
V_29 = F_9 () ;
if ( V_29 )
return V_29 ;
V_15 = F_16 () ;
if ( ! V_15 ) {
F_20 ( V_1 ) ;
F_15 ( V_1 ) ;
return - V_30 ;
}
F_3 ( 3 ) ;
F_21 ( V_15 ) ;
F_11 ( V_31 L_5 ,
V_7 ? L_6 : L_7 , V_1 -> V_2 -> V_27 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_20 ( V_1 ) ;
F_23 ( V_15 ) ;
F_15 ( V_1 ) ;
}
