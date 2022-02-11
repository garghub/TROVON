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
if ( V_4 . V_5 & V_6 ) {
F_5 ( V_7 , 1 ) ;
F_5 ( V_8 , 0 ) ;
} else {
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 0 ) ;
}
} else {
F_5 ( V_7 , 0 ) ;
F_5 ( V_8 , 1 ) ;
}
}
static void F_7 ( int V_2 )
{
F_5 ( V_9 , V_2 ) ;
}
static void F_8 ( int V_2 )
{
F_5 ( V_10 , V_2 ) ;
}
static void F_9 ( void )
{
V_11 = V_4 . V_12 -> V_13 ( V_14 ) ;
V_15 = 0x00144018 ;
V_16 = 0x00EF0000 ;
if ( F_10 () ) {
V_17 = 0x2121C000 ;
V_18 = 0x00600400 ;
} else {
V_17 = 0x0121C000 ;
V_18 = 0x00600000 ;
}
V_15 &= ~ V_19 ;
V_16 &= ~ V_20 ;
V_17 &= ~ V_21 ;
V_18 &= ~ V_22 ;
V_17 |= F_11 ( V_23 ) ;
F_12 ( & V_24 , 1 ) ;
F_13 ( 18 , V_25 , L_1 ) ;
F_14 ( 18 ) ;
V_26 = F_11 ( V_27 ) ;
V_28 = F_11 ( V_27 ) | F_11 ( V_29 ) ;
V_30 = F_11 ( V_27 ) | F_11 ( V_29 ) | V_31 ;
V_32 = F_11 ( V_33 ) | F_11 ( V_27 ) | F_11 ( V_29 ) ;
V_34 = 0xffffffff ;
V_35 |= V_36 ;
V_37 = V_38 | V_39 ;
}
static void F_15 ( void )
{
}
static int F_16 ( unsigned int V_40 )
{
int V_41 = 0 ;
int V_42 = V_4 . V_12 -> V_13 ( V_14 ) ;
if ( V_11 != V_42 ) {
if ( V_42 ) {
V_4 . V_5 |= V_43 ;
F_17 ( V_4 . V_44 , L_2 ) ;
} else {
F_17 ( V_4 . V_44 , L_3 ) ;
F_18 ( V_45 ) ;
V_4 . V_12 -> V_46 ( 0 ) ;
V_4 . V_47 = V_48 ;
}
V_11 = V_42 ;
return 0 ;
}
if ( V_49 & F_11 ( V_27 ) )
V_41 |= F_11 ( V_27 ) ;
if ( V_34 & F_11 ( V_33 ) )
V_41 |= F_11 ( V_33 ) ;
if ( V_40 && ( V_49 & V_31 ) )
V_41 |= V_31 ;
F_17 ( V_4 . V_44 , L_4 , V_41 ) ;
return V_41 ;
}
static bool F_19 ( void )
{
return ! F_20 ( V_27 ) ||
F_20 ( V_33 ) ;
}
unsigned long F_21 ( int type )
{
switch ( type ) {
case V_14 :
return ! F_20 ( V_50 ) ;
case V_51 :
return F_20 ( V_4 . V_12 -> V_52 ) ;
case V_53 :
return F_20 ( V_4 . V_12 -> V_54 ) ;
case V_55 :
return F_20 ( V_4 . V_12 -> V_56 ) ;
case V_57 :
return F_22 ( V_58 ) ;
case V_59 :
return F_22 ( V_60 ) ;
case V_61 :
default:
return F_22 ( V_62 ) ;
}
}
static int F_23 ( void )
{
int V_63 ;
if ( ! F_24 () && ! F_10 ()
&& ! F_25 () )
return - V_64 ;
V_65 = F_26 ( L_5 , - 1 ) ;
if ( ! V_65 )
return - V_66 ;
V_65 -> V_44 . V_67 = & V_68 ;
V_63 = F_27 ( V_65 ) ;
if ( V_63 )
F_28 ( V_65 ) ;
return V_63 ;
}
static void F_29 ( void )
{
F_30 ( V_65 ) ;
}
