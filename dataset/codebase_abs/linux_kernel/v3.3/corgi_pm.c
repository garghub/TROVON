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
F_12 ( V_4 . V_12 , L_1
L_2 ,
V_13 , F_13 ( V_14 ) ,
F_13 ( V_15 ) ,
F_13 ( V_16 ) ,
F_13 ( V_17 ) ) ;
if ( ( V_13 & F_14 ( V_14 ) ) ) {
if ( V_4 . V_18 -> V_19 ( V_20 ) ) {
F_12 ( V_4 . V_12 , L_3 ) ;
V_4 . V_5 |= V_21 ;
} else {
F_12 ( V_4 . V_12 , L_4 ) ;
F_15 ( V_22 ) ;
V_4 . V_18 -> V_23 ( 0 ) ;
V_4 . V_24 = V_25 ;
}
}
if ( ( V_13 & F_14 ( V_15 ) ) )
F_12 ( V_4 . V_12 , L_5 ) ;
if ( V_13 & F_14 ( V_16 ) )
V_11 |= F_14 ( V_16 ) ;
if ( V_13 & F_14 ( V_17 ) )
V_11 |= F_14 ( V_17 ) ;
if ( V_10 && ( V_13 & V_26 ) )
V_11 |= V_26 ;
F_12 ( V_4 . V_12 , L_6 , V_11 ) ;
return V_11 ;
}
static unsigned long F_16 ( void )
{
unsigned long V_27 ;
V_27 = ( ! F_13 ( V_14 ) << F_14 ( V_14 ) )
| ( ! F_13 ( V_16 )
<< F_14 ( V_16 ) )
| ( ! F_13 ( V_17 )
<< F_14 ( V_17 ) ) ;
return V_27 ;
}
unsigned long F_17 ( int type )
{
switch( type ) {
case V_20 :
return ! F_13 ( V_14 ) ;
case V_28 :
return F_13 ( V_4 . V_18 -> V_29 ) ;
case V_30 :
return F_13 ( V_4 . V_18 -> V_31 ) ;
case V_32 :
return F_13 ( V_4 . V_18 -> V_33 ) ;
case V_34 :
return F_18 ( V_35 ) ;
case V_36 :
return F_18 ( V_37 ) ;
case V_38 :
default:
return F_18 ( V_39 ) ;
}
}
static int T_1 F_19 ( void )
{
int V_27 ;
if ( ! F_7 () && ! F_20 ()
&& ! F_21 () )
return - V_40 ;
V_41 = F_22 ( L_7 , - 1 ) ;
if ( ! V_41 )
return - V_42 ;
if ( ! F_7 () )
V_43 . V_44 = 1 ;
V_41 -> V_12 . V_45 = & V_43 ;
V_27 = F_23 ( V_41 ) ;
if ( V_27 )
F_24 ( V_41 ) ;
return V_27 ;
}
static void F_25 ( void )
{
F_26 ( V_41 ) ;
}
