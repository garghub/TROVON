static unsigned long F_1 ( const T_1 V_1 )
{
return ( ( ( V_1 * 125 ) + 6000 ) ) * 100 ;
}
static T_1 F_2 ( unsigned long V_2 )
{
return F_3 ( V_2 - 600000 , 12500 ) ;
}
static unsigned long F_4 ( const T_1 V_1 )
{
if ( ! V_3 ) {
F_5 ( V_4 , & V_5 ,
V_6 ) ;
V_3 = true ;
}
if ( ! V_1 )
return 0 ;
if ( V_1 == 0x3A )
return 1350000 ;
if ( V_5 & 0x8 )
return ( ( ( ( V_1 - 1 ) * 1266 ) + 70900 ) ) * 10 ;
else
return ( ( ( ( V_1 - 1 ) * 1266 ) + 60770 ) ) * 10 ;
}
static T_1 F_6 ( unsigned long V_2 )
{
if ( ! V_3 ) {
F_5 ( V_4 , & V_5 ,
V_6 ) ;
V_3 = true ;
}
if ( ! V_2 )
return 0x00 ;
if ( V_2 > F_4 ( 0x39 ) ) {
if ( V_2 == 1350000 )
return 0x3A ;
F_7 ( L_1 ,
V_7 , V_2 , F_4 ( 0x39 ) ) ;
return 0x3A ;
}
if ( V_5 & 0x8 )
return F_3 ( V_2 - 709000 , 12660 ) + 1 ;
else
return F_3 ( V_2 - 607700 , 12660 ) + 1 ;
}
int T_2 F_8 ( void )
{
struct V_8 * V_9 ;
if ( ! F_9 () )
return - V_10 ;
V_9 = F_10 ( L_2 ) ;
F_11 ( V_9 , & V_11 ) ;
V_9 = F_10 ( L_3 ) ;
F_11 ( V_9 , & V_12 ) ;
V_9 = F_10 ( L_4 ) ;
F_11 ( V_9 , & V_13 ) ;
return 0 ;
}
int T_2 F_12 ( void )
{
struct V_8 * V_9 ;
if ( ! F_13 () )
return - V_10 ;
if ( F_14 () ) {
V_14 . V_15 = V_16 ;
V_14 . V_17 = V_18 ;
V_19 . V_15 = V_20 ;
V_19 . V_17 = V_21 ;
}
if ( ! V_22 )
F_15 ( true ) ;
V_9 = F_10 ( L_5 ) ;
F_11 ( V_9 , & V_14 ) ;
V_9 = F_10 ( L_4 ) ;
F_11 ( V_9 , & V_19 ) ;
return 0 ;
}
int T_2 F_15 ( bool V_23 )
{
T_1 V_24 ;
int V_25 ;
if ( V_22 )
F_16 ( L_6 , V_7 ) ;
V_25 = F_5 ( V_26 , & V_24 ,
V_27 ) ;
if ( V_25 )
goto V_28;
if ( V_23 )
V_24 |= V_29 ;
else
V_24 &= ~ V_29 ;
V_25 = F_17 ( V_26 , V_24 ,
V_27 ) ;
if ( ! V_25 ) {
V_22 = true ;
return 0 ;
}
V_28:
F_7 ( L_7 , V_7 , V_25 ) ;
return V_25 ;
}
