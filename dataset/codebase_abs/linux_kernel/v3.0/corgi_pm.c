static void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) ) ;
}
static void F_4 ( int V_2 )
{
F_5 ( V_3 , V_2 ) ;
}
static void F_6 ( int V_2 )
{
if ( V_2 ) {
if ( F_7 () && ( V_4 . V_5 & V_6 ) ) {
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 1 ) ;
} else {
F_5 ( V_7 , 1 ) ;
F_5 ( V_8 , 0 ) ;
}
} else {
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 0 ) ;
}
}
static void F_8 ( int V_2 )
{
F_5 ( V_9 , V_2 ) ;
}
static void F_9 ( void )
{
}
static void F_10 ( void )
{
}
static int F_11 ( unsigned int V_10 )
{
int V_11 = 0 ;
F_12 ( V_4 . V_12 , L_1 , V_13 , V_14 ) ;
if ( ( V_14 & F_13 ( V_15 ) ) ) {
if ( V_4 . V_16 -> V_17 ( V_18 ) ) {
F_12 ( V_4 . V_12 , L_2 ) ;
V_4 . V_5 |= V_19 ;
} else {
F_12 ( V_4 . V_12 , L_3 ) ;
F_14 ( V_20 ) ;
V_4 . V_16 -> V_21 ( 0 ) ;
V_4 . V_22 = V_23 ;
}
}
if ( ( V_14 & F_13 ( V_24 ) ) )
F_12 ( V_4 . V_12 , L_4 ) ;
if ( V_14 & F_13 ( V_25 ) )
V_11 |= F_13 ( V_25 ) ;
if ( V_14 & F_13 ( V_26 ) )
V_11 |= F_13 ( V_26 ) ;
if ( V_10 && ( V_14 & V_27 ) )
V_11 |= V_27 ;
F_12 ( V_4 . V_12 , L_5 , V_11 ) ;
return V_11 ;
}
static unsigned long F_15 ( void )
{
return ~ V_13 & ( F_13 ( V_15 ) | F_13 ( V_25 ) | F_13 ( V_26 ) ) ;
}
unsigned long F_16 ( int type )
{
switch( type ) {
case V_18 :
return ( ( F_17 ( V_15 ) & F_13 ( V_15 ) ) != 0 ) ;
case V_28 :
return F_18 ( V_4 . V_16 -> V_29 ) ;
case V_30 :
return F_18 ( V_4 . V_16 -> V_31 ) ;
case V_32 :
return F_18 ( V_4 . V_16 -> V_33 ) ;
case V_34 :
return F_19 ( V_35 ) ;
case V_36 :
return F_19 ( V_37 ) ;
case V_38 :
default:
return F_19 ( V_39 ) ;
}
}
static int T_1 F_20 ( void )
{
int V_40 ;
if ( ! F_7 () && ! F_21 ()
&& ! F_22 () )
return - V_41 ;
V_42 = F_23 ( L_6 , - 1 ) ;
if ( ! V_42 )
return - V_43 ;
if ( ! F_7 () )
V_44 . V_45 = 1 ;
V_42 -> V_12 . V_46 = & V_44 ;
V_40 = F_24 ( V_42 ) ;
if ( V_40 )
F_25 ( V_42 ) ;
return V_40 ;
}
static void F_26 ( void )
{
F_27 ( V_42 ) ;
}
