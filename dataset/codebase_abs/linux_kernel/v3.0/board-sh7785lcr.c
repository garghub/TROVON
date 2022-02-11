static int T_1 F_1 ( void )
{
F_2 ( 0 , V_1 ,
F_3 ( V_1 ) ) ;
if ( F_4 () ) {
V_2 . V_3 = V_4 ;
V_2 . V_5 = F_3 ( V_4 ) ;
}
return F_5 ( V_6 ,
F_3 ( V_6 ) ) ;
}
void T_1 F_6 ( void )
{
F_7 ( V_7 ) ;
F_7 ( V_8 ) ;
}
static int F_8 ( void )
{
struct V_9 * V_9 ;
int V_10 ;
V_9 = F_9 ( NULL , L_1 ) ;
if ( ! V_9 || F_10 ( V_9 ) )
return F_11 ( V_9 ) ;
V_10 = F_12 ( V_9 , 33333333 ) ;
F_13 ( V_9 ) ;
return V_10 ;
}
static void F_14 ( void )
{
unsigned char * V_11 ;
V_11 = F_15 ( V_12 , V_12 + 1 ) ;
if ( ! V_11 ) {
F_16 ( V_13 L_2 , V_14 ) ;
return;
}
* V_11 = 0x01 ;
F_17 ( V_11 ) ;
F_18 () ;
while ( 1 )
F_19 () ;
}
static void T_1 F_20 ( char * * V_15 )
{
void T_2 * V_16 ;
F_16 ( V_17 L_3 ) ;
V_18 = F_14 ;
V_16 = F_21 ( V_19 , V_20 ) ;
if ( ! V_16 ) {
F_16 ( V_13 L_2 , V_14 ) ;
return;
}
F_22 ( 0x000307c2 , V_16 + V_20 ) ;
F_17 ( V_16 ) ;
}
static int F_23 ( void )
{
int V_21 = 0 ;
V_21 |= V_22 ;
V_21 |= V_23 ;
V_21 |= V_24 ;
V_21 |= V_25 ;
V_21 |= V_26 ;
V_21 |= V_27 ;
V_21 |= V_28 ;
return V_21 ;
}
