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
if ( V_1 == 0x3A )
return 1350000 ;
if ( V_5 & 0x8 )
return ( ( ( ( V_1 - 1 ) * 125 ) + 7000 ) ) * 100 ;
else
return ( ( ( ( V_1 - 1 ) * 125 ) + 6000 ) ) * 100 ;
}
static T_1 F_6 ( unsigned long V_2 )
{
if ( ! V_3 ) {
F_5 ( V_4 , & V_5 ,
V_6 ) ;
V_3 = true ;
}
if ( V_2 == 1350000 )
return 0x3A ;
if ( V_5 & 0x8 )
return F_3 ( V_2 - 700000 , 12500 ) + 1 ;
else
return F_3 ( V_2 - 600000 , 12500 ) + 1 ;
}
int T_2 F_7 ( void )
{
struct V_7 * V_8 ;
if ( ! F_8 () )
return - V_9 ;
V_8 = F_9 ( L_1 ) ;
F_10 ( V_8 , & V_10 ) ;
V_8 = F_9 ( L_2 ) ;
F_10 ( V_8 , & V_11 ) ;
V_8 = F_9 ( L_3 ) ;
F_10 ( V_8 , & V_12 ) ;
return 0 ;
}
int T_2 F_11 ( void )
{
struct V_7 * V_8 ;
if ( ! F_12 () )
return - V_9 ;
if ( F_13 () ) {
V_13 . V_14 = V_15 ;
V_13 . V_16 = V_17 ;
V_18 . V_14 = V_19 ;
V_18 . V_16 = V_20 ;
}
if ( ! V_21 )
F_14 ( true ) ;
V_8 = F_9 ( L_1 ) ;
F_10 ( V_8 , & V_13 ) ;
V_8 = F_9 ( L_3 ) ;
F_10 ( V_8 , & V_18 ) ;
return 0 ;
}
int T_2 F_14 ( bool V_22 )
{
T_1 V_23 ;
int V_24 ;
if ( V_21 )
F_15 ( L_4 , V_25 ) ;
V_24 = F_5 ( V_26 , & V_23 ,
V_27 ) ;
if ( V_24 )
goto V_28;
if ( V_22 )
V_23 |= V_29 ;
else
V_23 &= ~ V_29 ;
V_24 = F_16 ( V_26 , V_23 ,
V_27 ) ;
if ( ! V_24 ) {
V_21 = true ;
return 0 ;
}
V_28:
F_17 ( L_5 , V_25 , V_24 ) ;
return V_24 ;
}
