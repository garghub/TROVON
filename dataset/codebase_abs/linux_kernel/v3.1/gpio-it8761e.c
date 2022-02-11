static T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_2 ) ;
return F_3 ( V_2 + 1 ) ;
}
static void F_4 ( T_1 V_3 , T_1 V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_3 , V_2 + 1 ) ;
}
static void F_5 ( T_1 V_2 )
{
F_2 ( 0x87 , V_2 ) ;
F_2 ( 0x61 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
F_2 ( ( V_2 == 0x2e ) ? 0x55 : 0xaa , V_2 ) ;
}
static void F_6 ( T_1 V_2 )
{
F_2 ( 0x2 , V_2 ) ;
F_2 ( 0x2 , V_2 + 1 ) ;
}
static void F_7 ( T_1 V_2 )
{
F_4 ( 0x2 , 0x7 , V_2 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned V_6 )
{
T_2 V_7 ;
T_1 V_8 ;
V_8 = V_6 % 8 ;
V_7 = ( V_6 >= 8 ) ? V_9 + 1 : V_9 ;
return ! ! ( F_3 ( V_7 ) & ( 1 << V_8 ) ) ;
}
static int F_9 ( struct V_4 * V_5 , unsigned V_6 )
{
T_1 V_10 ;
T_1 V_11 , V_8 ;
V_8 = V_6 % 8 ;
V_11 = ( V_6 >= 8 ) ? V_12 : V_13 ;
F_10 ( & V_14 ) ;
F_5 ( V_2 ) ;
F_7 ( V_2 ) ;
V_10 = F_1 ( V_11 , V_2 ) ;
if ( V_10 & ( 1 << V_8 ) )
F_4 ( V_10 & ~ ( 1 << V_8 ) , V_11 , V_2 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_14 ) ;
return 0 ;
}
static void F_12 ( struct V_4 * V_5 ,
unsigned V_6 , int V_15 )
{
T_1 V_16 , V_8 ;
T_2 V_7 ;
V_8 = V_6 % 8 ;
V_7 = ( V_6 >= 8 ) ? V_9 + 1 : V_9 ;
F_10 ( & V_14 ) ;
V_16 = F_3 ( V_7 ) ;
if ( V_15 )
F_2 ( V_16 | ( 1 << V_8 ) , V_7 ) ;
else
F_2 ( V_16 & ~ ( 1 << V_8 ) , V_7 ) ;
F_11 ( & V_14 ) ;
}
static int F_13 ( struct V_4 * V_5 ,
unsigned V_6 , int V_15 )
{
T_1 V_10 , V_11 , V_8 ;
V_8 = V_6 % 8 ;
V_11 = ( V_6 >= 8 ) ? V_12 : V_13 ;
F_12 ( V_5 , V_6 , V_15 ) ;
F_10 ( & V_14 ) ;
F_5 ( V_2 ) ;
F_7 ( V_2 ) ;
V_10 = F_1 ( V_11 , V_2 ) ;
if ( ! ( V_10 & ( 1 << V_8 ) ) )
F_4 ( V_10 | ( 1 << V_8 ) , V_11 , V_2 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_14 ) ;
return 0 ;
}
static int T_3 F_14 ( void )
{
int V_17 , V_18 , V_19 ;
for ( V_17 = 0 ; V_17 < F_15 ( V_20 ) ; V_17 ++ ) {
F_10 ( & V_14 ) ;
F_5 ( V_20 [ V_17 ] ) ;
V_18 = ( F_1 ( V_21 , V_20 [ V_17 ] ) << 8 ) +
F_1 ( V_22 , V_20 [ V_17 ] ) ;
F_6 ( V_20 [ V_17 ] ) ;
F_11 ( & V_14 ) ;
if ( V_18 == V_23 ) {
V_2 = V_20 [ V_17 ] ;
break;
}
}
if ( ! V_2 )
return - V_24 ;
F_5 ( V_2 ) ;
F_7 ( V_2 ) ;
V_9 = ( F_1 ( V_25 , V_2 ) << 8 ) +
F_1 ( V_26 , V_2 ) ;
F_6 ( V_2 ) ;
if ( ! F_16 ( V_9 , V_27 , V_28 ) )
return - V_29 ;
V_30 . V_31 = - 1 ;
V_30 . V_32 = 16 ;
V_19 = F_17 ( & V_30 ) ;
if ( V_19 < 0 )
goto V_33;
return 0 ;
V_33:
F_18 ( V_9 , V_27 ) ;
V_9 = 0 ;
return V_19 ;
}
static void T_4 F_19 ( void )
{
if ( V_9 ) {
int V_34 = F_20 ( & V_30 ) ;
F_21 ( V_34 , L_1 ,
V_35 , V_34 ) ;
F_18 ( V_9 , V_27 ) ;
V_9 = 0 ;
}
}
