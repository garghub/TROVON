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
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
F_5 ( V_8 , V_9 ,
F_6 ( V_9 ) ) ;
F_7 ( V_8 , V_10 , F_6 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = V_16 -> V_6 ;
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_19 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_22 ) ; V_19 ++ ) {
if ( V_22 [ V_19 ] . V_23 != F_10 ( V_14 ) )
continue;
if ( V_22 [ V_19 ] . V_24 == V_18 -> V_24 )
break;
if ( V_22 [ V_19 ] . V_24 == V_18 -> V_24 * 2 ) {
V_20 |= V_25 ;
break;
}
}
if ( V_19 == F_6 ( V_22 ) ) {
F_11 ( V_6 -> V_2 , L_1 ,
V_18 -> V_24 , F_10 ( V_14 ) ) ;
return - V_26 ;
}
V_20 |= V_22 [ V_19 ] . V_27 | ( V_22 [ V_19 ] . V_28 << V_29 ) ;
switch ( F_12 ( V_14 ) ) {
case V_30 :
break;
case V_31 :
V_21 |= 0x8 ;
break;
case V_32 :
V_21 |= 0x10 ;
break;
case V_33 :
V_21 |= 0x18 ;
break;
default:
return - V_26 ;
}
F_13 ( V_6 , V_34 , V_35 , V_21 ) ;
F_13 ( V_6 , V_36 ,
V_37 | V_25 | V_38 ,
V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_39 ,
int V_40 , unsigned int V_41 , int V_42 )
{
struct V_5 * V_6 = V_39 -> V_6 ;
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_22 ) ; V_19 ++ ) {
if ( V_41 == V_22 [ V_19 ] . V_24 ||
V_41 == V_22 [ V_19 ] . V_24 * 2 ) {
V_18 -> V_24 = V_41 ;
return 0 ;
}
}
F_11 ( V_6 -> V_2 , L_2 , V_41 ) ;
return - V_26 ;
}
static int F_15 ( struct V_15 * V_39 ,
unsigned int V_43 )
{
struct V_5 * V_6 = V_39 -> V_6 ;
T_1 V_21 = 0 ;
switch ( V_43 & V_44 ) {
case V_45 :
V_21 |= V_46 ;
break;
case V_47 :
break;
default:
return - V_26 ;
}
switch ( V_43 & V_48 ) {
case V_49 :
V_21 |= 0x2 ;
break;
case V_50 :
break;
case V_51 :
V_21 |= 0x1 ;
break;
case V_52 :
V_21 |= 0x3 ;
break;
case V_53 :
V_21 |= 0x13 ;
break;
default:
return - V_26 ;
}
switch ( V_43 & V_54 ) {
case V_55 :
break;
case V_56 :
V_21 |= V_57 ;
break;
default:
return - V_26 ;
}
F_13 ( V_6 , V_34 ,
V_58 | V_57 | V_46 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
enum V_59 V_60 )
{
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_61 ;
switch ( V_60 ) {
case V_62 :
break;
case V_63 :
F_13 ( V_6 , V_64 ,
V_65 , 0 ) ;
break;
case V_66 :
if ( V_6 -> V_8 . V_67 == V_68 ) {
V_61 = F_17 ( F_6 ( V_18 -> V_69 ) ,
V_18 -> V_69 ) ;
if ( V_61 != 0 ) {
F_11 ( V_6 -> V_2 ,
L_3 ,
V_61 ) ;
return V_61 ;
}
F_18 ( V_18 -> V_70 ) ;
F_13 ( V_6 , V_64 ,
V_65 , 0x4 ) ;
F_13 ( V_6 , V_71 ,
V_72 |
V_73 ,
V_72 |
V_73 ) ;
F_19 ( 500 ) ;
}
F_13 ( V_6 , V_64 ,
V_65 , 2 ) ;
break;
case V_68 :
F_13 ( V_6 , V_71 ,
V_72 | V_73 , 0 ) ;
F_20 ( F_6 ( V_18 -> V_69 ) ,
V_18 -> V_69 ) ;
break;
}
V_6 -> V_8 . V_67 = V_60 ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_68 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_66 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_61 ;
V_61 = F_24 ( V_6 , 7 , 9 , V_74 ) ;
if ( V_61 != 0 ) {
F_11 ( V_6 -> V_2 , L_4 , V_61 ) ;
return V_61 ;
}
V_61 = F_17 ( F_6 ( V_18 -> V_69 ) ,
V_18 -> V_69 ) ;
if ( V_61 != 0 ) {
F_11 ( V_6 -> V_2 , L_3 , V_61 ) ;
goto V_75;
}
V_61 = F_2 ( V_6 ) ;
if ( V_61 < 0 ) {
F_11 ( V_6 -> V_2 , L_5 ) ;
goto V_76;
}
F_13 ( V_6 , V_77 , V_78 ,
V_78 ) ;
F_13 ( V_6 , V_79 , V_80 ,
V_80 ) ;
F_16 ( V_6 , V_66 ) ;
F_20 ( F_6 ( V_18 -> V_69 ) , V_18 -> V_69 ) ;
F_25 ( V_6 , V_81 ,
F_6 ( V_81 ) ) ;
F_4 ( V_6 ) ;
return 0 ;
V_76:
F_20 ( F_6 ( V_18 -> V_69 ) , V_18 -> V_69 ) ;
V_75:
return V_61 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_68 ) ;
return 0 ;
}
static int F_27 ( struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
struct V_17 * V_18 ;
int V_61 , V_19 ;
V_18 = F_28 ( & V_83 -> V_2 , sizeof( struct V_17 ) ,
V_86 ) ;
if ( V_18 == NULL )
return - V_87 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_18 -> V_69 ) ; V_19 ++ )
V_18 -> V_69 [ V_19 ] . V_88 = V_89 [ V_19 ] ;
V_61 = F_29 ( & V_83 -> V_2 , F_6 ( V_18 -> V_69 ) ,
V_18 -> V_69 ) ;
if ( V_61 != 0 ) {
F_11 ( & V_83 -> V_2 , L_6 , V_61 ) ;
return V_61 ;
}
V_18 -> V_70 = F_30 ( V_83 , & V_90 ) ;
if ( F_31 ( V_18 -> V_70 ) )
return F_32 ( V_18 -> V_70 ) ;
F_33 ( V_83 , V_18 ) ;
V_61 = F_34 ( & V_83 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_61 ;
}
static int F_35 ( struct V_82 * V_93 )
{
F_36 ( & V_93 -> V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_94 * V_95 )
{
struct V_17 * V_18 ;
int V_61 , V_19 ;
V_18 = F_28 ( & V_95 -> V_2 , sizeof( struct V_17 ) ,
V_86 ) ;
if ( V_18 == NULL )
return - V_87 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_18 -> V_69 ) ; V_19 ++ )
V_18 -> V_69 [ V_19 ] . V_88 = V_89 [ V_19 ] ;
V_61 = F_29 ( & V_95 -> V_2 , F_6 ( V_18 -> V_69 ) ,
V_18 -> V_69 ) ;
if ( V_61 != 0 ) {
F_11 ( & V_95 -> V_2 , L_6 , V_61 ) ;
return V_61 ;
}
V_18 -> V_70 = F_38 ( V_95 , & V_90 ) ;
if ( F_31 ( V_18 -> V_70 ) )
return F_32 ( V_18 -> V_70 ) ;
F_39 ( V_95 , V_18 ) ;
V_61 = F_34 ( & V_95 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_61 ;
}
static int F_40 ( struct V_94 * V_95 )
{
F_36 ( & V_95 -> V_2 ) ;
return 0 ;
}
static int T_2 F_41 ( void )
{
int V_61 ;
#if F_42 ( V_96 ) || F_42 ( V_97 )
V_61 = F_43 ( & V_98 ) ;
if ( V_61 != 0 ) {
F_44 ( V_99 L_7 ,
V_61 ) ;
}
#endif
#if F_42 ( V_100 )
V_61 = F_45 ( & V_101 ) ;
if ( V_61 != 0 ) {
F_44 ( V_99 L_8 ,
V_61 ) ;
}
#endif
return 0 ;
}
static void T_3 F_46 ( void )
{
#if F_42 ( V_100 )
F_47 ( & V_101 ) ;
#endif
#if F_42 ( V_96 ) || F_42 ( V_97 )
F_48 ( & V_98 ) ;
#endif
}
