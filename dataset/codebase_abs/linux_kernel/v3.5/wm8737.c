static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_4 ( V_5 , V_6 ,
F_5 ( V_6 ) ) ;
F_6 ( V_5 , V_7 , F_5 ( V_7 ) ) ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_14 * V_15 = F_8 ( V_2 ) ;
int V_16 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
for ( V_16 = 0 ; V_16 < F_5 ( V_19 ) ; V_16 ++ ) {
if ( V_19 [ V_16 ] . V_20 != F_9 ( V_11 ) )
continue;
if ( V_19 [ V_16 ] . V_21 == V_15 -> V_21 )
break;
if ( V_19 [ V_16 ] . V_21 == V_15 -> V_21 * 2 ) {
V_17 |= V_22 ;
break;
}
}
if ( V_16 == F_5 ( V_19 ) ) {
F_10 ( V_2 -> V_23 , L_1 ,
V_15 -> V_21 , F_9 ( V_11 ) ) ;
return - V_24 ;
}
V_17 |= V_19 [ V_16 ] . V_25 | ( V_19 [ V_16 ] . V_26 << V_27 ) ;
switch ( F_11 ( V_11 ) ) {
case V_28 :
break;
case V_29 :
V_18 |= 0x8 ;
break;
case V_30 :
V_18 |= 0x10 ;
break;
case V_31 :
V_18 |= 0x18 ;
break;
default:
return - V_24 ;
}
F_12 ( V_2 , V_32 , V_33 , V_18 ) ;
F_12 ( V_2 , V_34 ,
V_35 | V_22 | V_36 ,
V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_37 ,
int V_38 , unsigned int V_39 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_14 * V_15 = F_8 ( V_2 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_5 ( V_19 ) ; V_16 ++ ) {
if ( V_39 == V_19 [ V_16 ] . V_21 ||
V_39 == V_19 [ V_16 ] . V_21 * 2 ) {
V_15 -> V_21 = V_39 ;
return 0 ;
}
}
F_10 ( V_2 -> V_23 , L_2 , V_39 ) ;
return - V_24 ;
}
static int F_14 ( struct V_12 * V_37 ,
unsigned int V_41 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_18 = 0 ;
switch ( V_41 & V_42 ) {
case V_43 :
V_18 |= V_44 ;
break;
case V_45 :
break;
default:
return - V_24 ;
}
switch ( V_41 & V_46 ) {
case V_47 :
V_18 |= 0x2 ;
break;
case V_48 :
break;
case V_49 :
V_18 |= 0x1 ;
break;
case V_50 :
V_18 |= 0x3 ;
break;
case V_51 :
V_18 |= 0x13 ;
break;
default:
return - V_24 ;
}
switch ( V_41 & V_52 ) {
case V_53 :
break;
case V_54 :
V_18 |= V_55 ;
break;
default:
return - V_24 ;
}
F_12 ( V_2 , V_32 ,
V_56 | V_55 | V_44 , V_18 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_57 V_58 )
{
struct V_14 * V_15 = F_8 ( V_2 ) ;
int V_59 ;
switch ( V_58 ) {
case V_60 :
break;
case V_61 :
F_12 ( V_2 , V_62 ,
V_63 , 0 ) ;
break;
case V_64 :
if ( V_2 -> V_5 . V_65 == V_66 ) {
V_59 = F_16 ( F_5 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
if ( V_59 != 0 ) {
F_10 ( V_2 -> V_23 ,
L_3 ,
V_59 ) ;
return V_59 ;
}
F_17 ( V_2 ) ;
F_12 ( V_2 , V_62 ,
V_63 , 0x4 ) ;
F_12 ( V_2 , V_68 ,
V_69 |
V_70 ,
V_69 |
V_70 ) ;
F_18 ( 500 ) ;
}
F_12 ( V_2 , V_62 ,
V_63 , 2 ) ;
break;
case V_66 :
F_12 ( V_2 , V_68 ,
V_69 | V_70 , 0 ) ;
F_19 ( F_5 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
break;
}
V_2 -> V_5 . V_65 = V_58 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_64 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_8 ( V_2 ) ;
int V_59 , V_16 ;
V_59 = F_23 ( V_2 , 7 , 9 , V_15 -> V_71 ) ;
if ( V_59 != 0 ) {
F_10 ( V_2 -> V_23 , L_4 , V_59 ) ;
return V_59 ;
}
for ( V_16 = 0 ; V_16 < F_5 ( V_15 -> V_67 ) ; V_16 ++ )
V_15 -> V_67 [ V_16 ] . V_72 = V_73 [ V_16 ] ;
V_59 = F_24 ( V_2 -> V_23 , F_5 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
if ( V_59 != 0 ) {
F_10 ( V_2 -> V_23 , L_5 , V_59 ) ;
return V_59 ;
}
V_59 = F_16 ( F_5 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
if ( V_59 != 0 ) {
F_10 ( V_2 -> V_23 , L_3 , V_59 ) ;
goto V_74;
}
V_59 = F_1 ( V_2 ) ;
if ( V_59 < 0 ) {
F_10 ( V_2 -> V_23 , L_6 ) ;
goto V_75;
}
F_12 ( V_2 , V_76 , V_77 ,
V_77 ) ;
F_12 ( V_2 , V_78 , V_79 ,
V_79 ) ;
F_15 ( V_2 , V_64 ) ;
F_19 ( F_5 ( V_15 -> V_67 ) , V_15 -> V_67 ) ;
F_25 ( V_2 , V_80 ,
F_5 ( V_80 ) ) ;
F_3 ( V_2 ) ;
return 0 ;
V_75:
F_19 ( F_5 ( V_15 -> V_67 ) , V_15 -> V_67 ) ;
V_74:
F_26 ( F_5 ( V_15 -> V_67 ) , V_15 -> V_67 ) ;
return V_59 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_8 ( V_2 ) ;
F_15 ( V_2 , V_66 ) ;
F_26 ( F_5 ( V_15 -> V_67 ) , V_15 -> V_67 ) ;
return 0 ;
}
static T_2 int F_28 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_14 * V_15 ;
int V_59 ;
V_15 = F_29 ( sizeof( struct V_14 ) , V_85 ) ;
if ( V_15 == NULL )
return - V_86 ;
F_30 ( V_82 , V_15 ) ;
V_15 -> V_71 = V_87 ;
V_59 = F_31 ( & V_82 -> V_23 ,
& V_88 , & V_89 , 1 ) ;
if ( V_59 < 0 )
F_32 ( V_15 ) ;
return V_59 ;
}
static T_3 int F_33 ( struct V_81 * V_90 )
{
F_34 ( & V_90 -> V_23 ) ;
F_32 ( F_35 ( V_90 ) ) ;
return 0 ;
}
static int T_2 F_36 ( struct V_91 * V_92 )
{
struct V_14 * V_15 ;
int V_59 ;
V_15 = F_29 ( sizeof( struct V_14 ) , V_85 ) ;
if ( V_15 == NULL )
return - V_86 ;
V_15 -> V_71 = V_93 ;
F_37 ( V_92 , V_15 ) ;
V_59 = F_31 ( & V_92 -> V_23 ,
& V_88 , & V_89 , 1 ) ;
if ( V_59 < 0 )
F_32 ( V_15 ) ;
return V_59 ;
}
static int T_3 F_38 ( struct V_91 * V_92 )
{
F_34 ( & V_92 -> V_23 ) ;
F_32 ( F_39 ( V_92 ) ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
int V_59 ;
#if F_41 ( V_94 ) || F_41 ( V_95 )
V_59 = F_42 ( & V_96 ) ;
if ( V_59 != 0 ) {
F_43 ( V_97 L_7 ,
V_59 ) ;
}
#endif
#if F_41 ( V_98 )
V_59 = F_44 ( & V_99 ) ;
if ( V_59 != 0 ) {
F_43 ( V_97 L_8 ,
V_59 ) ;
}
#endif
return 0 ;
}
static void T_5 F_45 ( void )
{
#if F_41 ( V_98 )
F_46 ( & V_99 ) ;
#endif
#if F_41 ( V_94 ) || F_41 ( V_95 )
F_47 ( & V_96 ) ;
#endif
}
