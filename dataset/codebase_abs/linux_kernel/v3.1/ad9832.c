static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long long V_3 = ( V_4 ) V_2 *
( V_4 ) ( ( V_4 ) 1L << V_5 ) ;
F_2 ( V_3 , V_1 ) ;
return V_3 ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned V_8 , unsigned long V_2 )
{
unsigned long V_9 ;
if ( V_2 > ( V_7 -> V_1 / 2 ) )
return - V_10 ;
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
V_7 -> V_11 [ 0 ] = F_4 ( ( V_12 << V_13 ) |
( V_8 << V_14 ) |
( ( V_9 >> 24 ) & 0xFF ) ) ;
V_7 -> V_11 [ 1 ] = F_4 ( ( V_15 << V_13 ) |
( ( V_8 - 1 ) << V_14 ) |
( ( V_9 >> 16 ) & 0xFF ) ) ;
V_7 -> V_11 [ 2 ] = F_4 ( ( V_12 << V_13 ) |
( ( V_8 - 2 ) << V_14 ) |
( ( V_9 >> 8 ) & 0xFF ) ) ;
V_7 -> V_11 [ 3 ] = F_4 ( ( V_15 << V_13 ) |
( ( V_8 - 3 ) << V_14 ) |
( ( V_9 >> 0 ) & 0xFF ) ) ;
return F_5 ( V_7 -> V_16 , & V_7 -> V_17 ) ; ;
}
static int F_6 ( struct V_6 * V_7 ,
unsigned long V_8 , unsigned long V_18 )
{
if ( V_18 > ( 1 << V_19 ) )
return - V_10 ;
V_7 -> V_20 [ 0 ] = F_4 ( ( V_21 << V_13 ) |
( V_8 << V_14 ) |
( ( V_18 >> 8 ) & 0xFF ) ) ;
V_7 -> V_20 [ 1 ] = F_4 ( ( V_22 << V_13 ) |
( ( V_8 - 1 ) << V_14 ) |
( V_18 & 0xFF ) ) ;
return F_5 ( V_7 -> V_16 , & V_7 -> V_23 ) ;
}
static T_1 F_7 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 ,
T_2 V_29 )
{
struct V_30 * V_31 = F_8 ( V_25 ) ;
struct V_6 * V_7 = F_9 ( V_31 ) ;
struct V_32 * V_33 = F_10 ( V_27 ) ;
int V_34 ;
long V_35 ;
V_34 = F_11 ( V_28 , 10 , & V_35 ) ;
if ( V_34 )
goto V_36;
F_12 ( & V_31 -> V_37 ) ;
switch ( V_33 -> V_38 ) {
case V_39 :
case V_40 :
V_34 = F_3 ( V_7 , V_33 -> V_38 , V_35 ) ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_34 = F_6 ( V_7 , V_33 -> V_38 , V_35 ) ;
break;
case V_45 :
if ( V_35 )
V_7 -> V_46 &= ~ V_47 ;
else
V_7 -> V_46 |= V_47 ;
V_7 -> V_48 = F_4 ( ( V_49 << V_13 ) |
V_7 -> V_46 ) ;
V_34 = F_5 ( V_7 -> V_16 , & V_7 -> V_50 ) ;
break;
case V_51 :
if ( V_35 == 1 )
V_7 -> V_52 |= V_53 ;
else if ( V_35 == 0 )
V_7 -> V_52 &= ~ V_53 ;
else {
V_34 = - V_10 ;
break;
}
V_7 -> V_48 = F_4 ( ( V_54 << V_13 ) |
V_7 -> V_52 ) ;
V_34 = F_5 ( V_7 -> V_16 , & V_7 -> V_50 ) ;
break;
case V_55 :
if ( V_35 < 0 || V_35 > 3 ) {
V_34 = - V_10 ;
break;
}
V_7 -> V_52 &= ~ F_13 ( 3 ) ;
V_7 -> V_52 |= F_13 ( V_35 ) ;
V_7 -> V_48 = F_4 ( ( V_54 << V_13 ) |
V_7 -> V_52 ) ;
V_34 = F_5 ( V_7 -> V_16 , & V_7 -> V_50 ) ;
break;
case V_56 :
if ( V_35 )
V_7 -> V_57 &= ~ ( V_58 | V_59 |
V_60 ) ;
else
V_7 -> V_57 |= V_58 ;
V_7 -> V_48 = F_4 ( ( V_61 << V_13 ) |
V_7 -> V_57 ) ;
V_34 = F_5 ( V_7 -> V_16 , & V_7 -> V_50 ) ;
break;
default:
V_34 = - V_62 ;
}
F_14 ( & V_31 -> V_37 ) ;
V_36:
return V_34 ? V_34 : V_29 ;
}
static int T_3 F_15 ( struct V_63 * V_16 )
{
struct V_64 * V_65 = V_16 -> V_25 . V_66 ;
struct V_30 * V_67 ;
struct V_6 * V_7 ;
struct V_68 * V_69 ;
int V_34 ;
if ( ! V_65 ) {
F_16 ( & V_16 -> V_25 , L_1 ) ;
return - V_62 ;
}
V_69 = F_17 ( & V_16 -> V_25 , L_2 ) ;
if ( ! F_18 ( V_69 ) ) {
V_34 = F_19 ( V_69 ) ;
if ( V_34 )
goto V_70;
}
V_67 = F_20 ( sizeof( * V_7 ) ) ;
if ( V_67 == NULL ) {
V_34 = - V_71 ;
goto V_72;
}
F_21 ( V_16 , V_67 ) ;
V_7 = F_9 ( V_67 ) ;
V_7 -> V_69 = V_69 ;
V_7 -> V_1 = V_65 -> V_1 ;
V_7 -> V_16 = V_16 ;
V_67 -> V_25 . V_73 = & V_16 -> V_25 ;
V_67 -> V_74 = F_22 ( V_16 ) -> V_74 ;
V_67 -> V_75 = & V_76 ;
V_67 -> V_77 = V_78 ;
V_7 -> V_79 . V_80 = & V_7 -> V_48 ;
V_7 -> V_79 . V_29 = 2 ;
F_23 ( & V_7 -> V_50 ) ;
F_24 ( & V_7 -> V_79 , & V_7 -> V_50 ) ;
V_7 -> V_81 [ 0 ] . V_80 = & V_7 -> V_11 [ 0 ] ;
V_7 -> V_81 [ 0 ] . V_29 = 2 ;
V_7 -> V_81 [ 0 ] . V_82 = 1 ;
V_7 -> V_81 [ 1 ] . V_80 = & V_7 -> V_11 [ 1 ] ;
V_7 -> V_81 [ 1 ] . V_29 = 2 ;
V_7 -> V_81 [ 1 ] . V_82 = 1 ;
V_7 -> V_81 [ 2 ] . V_80 = & V_7 -> V_11 [ 2 ] ;
V_7 -> V_81 [ 2 ] . V_29 = 2 ;
V_7 -> V_81 [ 2 ] . V_82 = 1 ;
V_7 -> V_81 [ 3 ] . V_80 = & V_7 -> V_11 [ 3 ] ;
V_7 -> V_81 [ 3 ] . V_29 = 2 ;
F_23 ( & V_7 -> V_17 ) ;
F_24 ( & V_7 -> V_81 [ 0 ] , & V_7 -> V_17 ) ;
F_24 ( & V_7 -> V_81 [ 1 ] , & V_7 -> V_17 ) ;
F_24 ( & V_7 -> V_81 [ 2 ] , & V_7 -> V_17 ) ;
F_24 ( & V_7 -> V_81 [ 3 ] , & V_7 -> V_17 ) ;
V_7 -> V_83 [ 0 ] . V_80 = & V_7 -> V_20 [ 0 ] ;
V_7 -> V_83 [ 0 ] . V_29 = 2 ;
V_7 -> V_83 [ 0 ] . V_82 = 1 ;
V_7 -> V_83 [ 1 ] . V_80 = & V_7 -> V_20 [ 1 ] ;
V_7 -> V_83 [ 1 ] . V_29 = 2 ;
F_23 ( & V_7 -> V_23 ) ;
F_24 ( & V_7 -> V_83 [ 0 ] , & V_7 -> V_23 ) ;
F_24 ( & V_7 -> V_83 [ 1 ] , & V_7 -> V_23 ) ;
V_7 -> V_57 = V_59 | V_58 | V_60 ;
V_7 -> V_48 = F_4 ( ( V_61 << V_13 ) |
V_7 -> V_57 ) ;
V_34 = F_5 ( V_7 -> V_16 , & V_7 -> V_50 ) ;
if ( V_34 ) {
F_25 ( & V_16 -> V_25 , L_3 ) ;
goto V_84;
}
V_34 = F_3 ( V_7 , V_39 , V_65 -> V_85 ) ;
if ( V_34 )
goto V_84;
V_34 = F_3 ( V_7 , V_40 , V_65 -> V_86 ) ;
if ( V_34 )
goto V_84;
V_34 = F_6 ( V_7 , V_41 , V_65 -> V_87 ) ;
if ( V_34 )
goto V_84;
V_34 = F_6 ( V_7 , V_42 , V_65 -> V_88 ) ;
if ( V_34 )
goto V_84;
V_34 = F_6 ( V_7 , V_43 , V_65 -> V_89 ) ;
if ( V_34 )
goto V_84;
V_34 = F_6 ( V_7 , V_44 , V_65 -> V_90 ) ;
if ( V_34 )
goto V_84;
V_34 = F_26 ( V_67 ) ;
if ( V_34 )
goto V_84;
return 0 ;
V_84:
F_27 ( V_67 ) ;
V_72:
if ( ! F_18 ( V_69 ) )
F_28 ( V_69 ) ;
V_70:
if ( ! F_18 ( V_69 ) )
F_29 ( V_69 ) ;
return V_34 ;
}
static int T_4 F_30 ( struct V_63 * V_16 )
{
struct V_30 * V_67 = F_31 ( V_16 ) ;
struct V_6 * V_7 = F_9 ( V_67 ) ;
struct V_68 * V_69 = V_7 -> V_69 ;
F_32 ( V_67 ) ;
if ( ! F_18 ( V_69 ) ) {
F_28 ( V_69 ) ;
F_29 ( V_69 ) ;
}
return 0 ;
}
static int T_5 F_33 ( void )
{
return F_34 ( & V_91 ) ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_91 ) ;
}
