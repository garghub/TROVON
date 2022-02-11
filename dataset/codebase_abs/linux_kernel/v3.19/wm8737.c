static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_6 , V_4 , 0 ) ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_6 ;
struct V_13 * V_14 = F_5 ( V_6 ) ;
int V_15 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
for ( V_15 = 0 ; V_15 < F_6 ( V_18 ) ; V_15 ++ ) {
if ( V_18 [ V_15 ] . V_19 != F_7 ( V_10 ) )
continue;
if ( V_18 [ V_15 ] . V_20 == V_14 -> V_20 )
break;
if ( V_18 [ V_15 ] . V_20 == V_14 -> V_20 * 2 ) {
V_16 |= V_21 ;
break;
}
}
if ( V_15 == F_6 ( V_18 ) ) {
F_8 ( V_6 -> V_2 , L_1 ,
V_14 -> V_20 , F_7 ( V_10 ) ) ;
return - V_22 ;
}
V_16 |= V_18 [ V_15 ] . V_23 | ( V_18 [ V_15 ] . V_24 << V_25 ) ;
switch ( F_9 ( V_10 ) ) {
case 16 :
break;
case 20 :
V_17 |= 0x8 ;
break;
case 24 :
V_17 |= 0x10 ;
break;
case 32 :
V_17 |= 0x18 ;
break;
default:
return - V_22 ;
}
F_10 ( V_6 , V_26 , V_27 , V_17 ) ;
F_10 ( V_6 , V_28 ,
V_29 | V_21 | V_30 ,
V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_31 ,
int V_32 , unsigned int V_33 , int V_34 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
struct V_13 * V_14 = F_5 ( V_6 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_6 ( V_18 ) ; V_15 ++ ) {
if ( V_33 == V_18 [ V_15 ] . V_20 ||
V_33 == V_18 [ V_15 ] . V_20 * 2 ) {
V_14 -> V_20 = V_33 ;
return 0 ;
}
}
F_8 ( V_6 -> V_2 , L_2 , V_33 ) ;
return - V_22 ;
}
static int F_12 ( struct V_11 * V_31 ,
unsigned int V_35 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
T_1 V_17 = 0 ;
switch ( V_35 & V_36 ) {
case V_37 :
V_17 |= V_38 ;
break;
case V_39 :
break;
default:
return - V_22 ;
}
switch ( V_35 & V_40 ) {
case V_41 :
V_17 |= 0x2 ;
break;
case V_42 :
break;
case V_43 :
V_17 |= 0x1 ;
break;
case V_44 :
V_17 |= 0x3 ;
break;
case V_45 :
V_17 |= 0x13 ;
break;
default:
return - V_22 ;
}
switch ( V_35 & V_46 ) {
case V_47 :
break;
case V_48 :
V_17 |= V_49 ;
break;
default:
return - V_22 ;
}
F_10 ( V_6 , V_26 ,
V_50 | V_49 | V_38 , V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
enum V_51 V_52 )
{
struct V_13 * V_14 = F_5 ( V_6 ) ;
int V_53 ;
switch ( V_52 ) {
case V_54 :
break;
case V_55 :
F_10 ( V_6 , V_56 ,
V_57 , 0 ) ;
break;
case V_58 :
if ( V_6 -> V_59 . V_60 == V_61 ) {
V_53 = F_14 ( F_6 ( V_14 -> V_62 ) ,
V_14 -> V_62 ) ;
if ( V_53 != 0 ) {
F_8 ( V_6 -> V_2 ,
L_3 ,
V_53 ) ;
return V_53 ;
}
F_15 ( V_14 -> V_63 ) ;
F_10 ( V_6 , V_56 ,
V_57 , 0x4 ) ;
F_10 ( V_6 , V_64 ,
V_65 |
V_66 ,
V_65 |
V_66 ) ;
F_16 ( 500 ) ;
}
F_10 ( V_6 , V_56 ,
V_57 , 2 ) ;
break;
case V_61 :
F_10 ( V_6 , V_64 ,
V_65 | V_66 , 0 ) ;
F_17 ( F_6 ( V_14 -> V_62 ) ,
V_14 -> V_62 ) ;
break;
}
V_6 -> V_59 . V_60 = V_52 ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = F_5 ( V_6 ) ;
int V_53 ;
V_53 = F_14 ( F_6 ( V_14 -> V_62 ) ,
V_14 -> V_62 ) ;
if ( V_53 != 0 ) {
F_8 ( V_6 -> V_2 , L_3 , V_53 ) ;
goto V_67;
}
V_53 = F_2 ( V_6 ) ;
if ( V_53 < 0 ) {
F_8 ( V_6 -> V_2 , L_4 ) ;
goto V_68;
}
F_10 ( V_6 , V_69 , V_70 ,
V_70 ) ;
F_10 ( V_6 , V_71 , V_72 ,
V_72 ) ;
F_13 ( V_6 , V_58 ) ;
F_17 ( F_6 ( V_14 -> V_62 ) , V_14 -> V_62 ) ;
return 0 ;
V_68:
F_17 ( F_6 ( V_14 -> V_62 ) , V_14 -> V_62 ) ;
V_67:
return V_53 ;
}
static int F_19 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_13 * V_14 ;
int V_53 , V_15 ;
V_14 = F_20 ( & V_74 -> V_2 , sizeof( struct V_13 ) ,
V_77 ) ;
if ( V_14 == NULL )
return - V_78 ;
for ( V_15 = 0 ; V_15 < F_6 ( V_14 -> V_62 ) ; V_15 ++ )
V_14 -> V_62 [ V_15 ] . V_79 = V_80 [ V_15 ] ;
V_53 = F_21 ( & V_74 -> V_2 , F_6 ( V_14 -> V_62 ) ,
V_14 -> V_62 ) ;
if ( V_53 != 0 ) {
F_8 ( & V_74 -> V_2 , L_5 , V_53 ) ;
return V_53 ;
}
V_14 -> V_63 = F_22 ( V_74 , & V_81 ) ;
if ( F_23 ( V_14 -> V_63 ) )
return F_24 ( V_14 -> V_63 ) ;
F_25 ( V_74 , V_14 ) ;
V_53 = F_26 ( & V_74 -> V_2 ,
& V_82 , & V_83 , 1 ) ;
return V_53 ;
}
static int F_27 ( struct V_73 * V_84 )
{
F_28 ( & V_84 -> V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_85 * V_86 )
{
struct V_13 * V_14 ;
int V_53 , V_15 ;
V_14 = F_20 ( & V_86 -> V_2 , sizeof( struct V_13 ) ,
V_77 ) ;
if ( V_14 == NULL )
return - V_78 ;
for ( V_15 = 0 ; V_15 < F_6 ( V_14 -> V_62 ) ; V_15 ++ )
V_14 -> V_62 [ V_15 ] . V_79 = V_80 [ V_15 ] ;
V_53 = F_21 ( & V_86 -> V_2 , F_6 ( V_14 -> V_62 ) ,
V_14 -> V_62 ) ;
if ( V_53 != 0 ) {
F_8 ( & V_86 -> V_2 , L_5 , V_53 ) ;
return V_53 ;
}
V_14 -> V_63 = F_30 ( V_86 , & V_81 ) ;
if ( F_23 ( V_14 -> V_63 ) )
return F_24 ( V_14 -> V_63 ) ;
F_31 ( V_86 , V_14 ) ;
V_53 = F_26 ( & V_86 -> V_2 ,
& V_82 , & V_83 , 1 ) ;
return V_53 ;
}
static int F_32 ( struct V_85 * V_86 )
{
F_28 ( & V_86 -> V_2 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
int V_53 ;
#if F_34 ( V_87 )
V_53 = F_35 ( & V_88 ) ;
if ( V_53 != 0 ) {
F_36 ( V_89 L_6 ,
V_53 ) ;
}
#endif
#if F_37 ( V_90 )
V_53 = F_38 ( & V_91 ) ;
if ( V_53 != 0 ) {
F_36 ( V_89 L_7 ,
V_53 ) ;
}
#endif
return 0 ;
}
static void T_3 F_39 ( void )
{
#if F_37 ( V_90 )
F_40 ( & V_91 ) ;
#endif
#if F_34 ( V_87 )
F_41 ( & V_88 ) ;
#endif
}
