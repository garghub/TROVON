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
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
int V_19 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
for ( V_19 = 0 ; V_19 < F_5 ( V_22 ) ; V_19 ++ ) {
if ( V_22 [ V_19 ] . V_23 != F_9 ( V_11 ) )
continue;
if ( V_22 [ V_19 ] . V_24 == V_18 -> V_24 )
break;
if ( V_22 [ V_19 ] . V_24 == V_18 -> V_24 * 2 ) {
V_20 |= V_25 ;
break;
}
}
if ( V_19 == F_5 ( V_22 ) ) {
F_10 ( V_2 -> V_26 , L_1 ,
V_18 -> V_24 , F_9 ( V_11 ) ) ;
return - V_27 ;
}
V_20 |= V_22 [ V_19 ] . V_28 | ( V_22 [ V_19 ] . V_29 << V_30 ) ;
switch ( F_11 ( V_11 ) ) {
case V_31 :
break;
case V_32 :
V_21 |= 0x8 ;
break;
case V_33 :
V_21 |= 0x10 ;
break;
case V_34 :
V_21 |= 0x18 ;
break;
default:
return - V_27 ;
}
F_12 ( V_2 , V_35 , V_36 , V_21 ) ;
F_12 ( V_2 , V_37 ,
V_38 | V_25 | V_39 ,
V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_40 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_5 ( V_22 ) ; V_19 ++ ) {
if ( V_42 == V_22 [ V_19 ] . V_24 ||
V_42 == V_22 [ V_19 ] . V_24 * 2 ) {
V_18 -> V_24 = V_42 ;
return 0 ;
}
}
F_10 ( V_2 -> V_26 , L_2 , V_42 ) ;
return - V_27 ;
}
static int F_14 ( struct V_12 * V_40 ,
unsigned int V_44 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_21 = 0 ;
switch ( V_44 & V_45 ) {
case V_46 :
V_21 |= V_47 ;
break;
case V_48 :
break;
default:
return - V_27 ;
}
switch ( V_44 & V_49 ) {
case V_50 :
V_21 |= 0x2 ;
break;
case V_51 :
break;
case V_52 :
V_21 |= 0x1 ;
break;
case V_53 :
V_21 |= 0x3 ;
break;
case V_54 :
V_21 |= 0x13 ;
break;
default:
return - V_27 ;
}
switch ( V_44 & V_55 ) {
case V_56 :
break;
case V_57 :
V_21 |= V_58 ;
break;
default:
return - V_27 ;
}
F_12 ( V_2 , V_35 ,
V_59 | V_58 | V_47 , V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_60 V_61 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
int V_62 ;
switch ( V_61 ) {
case V_63 :
break;
case V_64 :
F_12 ( V_2 , V_65 ,
V_66 , 0 ) ;
break;
case V_67 :
if ( V_2 -> V_5 . V_68 == V_69 ) {
V_62 = F_16 ( F_5 ( V_18 -> V_70 ) ,
V_18 -> V_70 ) ;
if ( V_62 != 0 ) {
F_10 ( V_2 -> V_26 ,
L_3 ,
V_62 ) ;
return V_62 ;
}
F_17 ( V_2 ) ;
F_12 ( V_2 , V_65 ,
V_66 , 0x4 ) ;
F_12 ( V_2 , V_71 ,
V_72 |
V_73 ,
V_72 |
V_73 ) ;
F_18 ( 500 ) ;
}
F_12 ( V_2 , V_65 ,
V_66 , 2 ) ;
break;
case V_69 :
F_12 ( V_2 , V_71 ,
V_72 | V_73 , 0 ) ;
F_19 ( F_5 ( V_18 -> V_70 ) ,
V_18 -> V_70 ) ;
break;
}
V_2 -> V_5 . V_68 = V_61 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_74 )
{
F_15 ( V_2 , V_69 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_67 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
int V_62 , V_19 ;
V_62 = F_23 ( V_2 , 7 , 9 , V_18 -> V_75 ) ;
if ( V_62 != 0 ) {
F_10 ( V_2 -> V_26 , L_4 , V_62 ) ;
return V_62 ;
}
for ( V_19 = 0 ; V_19 < F_5 ( V_18 -> V_70 ) ; V_19 ++ )
V_18 -> V_70 [ V_19 ] . V_76 = V_77 [ V_19 ] ;
V_62 = F_24 ( V_2 -> V_26 , F_5 ( V_18 -> V_70 ) ,
V_18 -> V_70 ) ;
if ( V_62 != 0 ) {
F_10 ( V_2 -> V_26 , L_5 , V_62 ) ;
return V_62 ;
}
V_62 = F_16 ( F_5 ( V_18 -> V_70 ) ,
V_18 -> V_70 ) ;
if ( V_62 != 0 ) {
F_10 ( V_2 -> V_26 , L_3 , V_62 ) ;
goto V_78;
}
V_62 = F_1 ( V_2 ) ;
if ( V_62 < 0 ) {
F_10 ( V_2 -> V_26 , L_6 ) ;
goto V_79;
}
F_12 ( V_2 , V_80 , V_81 ,
V_81 ) ;
F_12 ( V_2 , V_82 , V_83 ,
V_83 ) ;
F_15 ( V_2 , V_67 ) ;
F_19 ( F_5 ( V_18 -> V_70 ) , V_18 -> V_70 ) ;
F_25 ( V_2 , V_84 ,
F_5 ( V_84 ) ) ;
F_3 ( V_2 ) ;
return 0 ;
V_79:
F_19 ( F_5 ( V_18 -> V_70 ) , V_18 -> V_70 ) ;
V_78:
F_26 ( F_5 ( V_18 -> V_70 ) , V_18 -> V_70 ) ;
return V_62 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
F_15 ( V_2 , V_69 ) ;
F_26 ( F_5 ( V_18 -> V_70 ) , V_18 -> V_70 ) ;
return 0 ;
}
static T_3 int F_28 ( struct V_85 * V_86 ,
const struct V_87 * V_88 )
{
struct V_17 * V_18 ;
int V_62 ;
V_18 = F_29 ( sizeof( struct V_17 ) , V_89 ) ;
if ( V_18 == NULL )
return - V_90 ;
F_30 ( V_86 , V_18 ) ;
V_18 -> V_75 = V_91 ;
V_62 = F_31 ( & V_86 -> V_26 ,
& V_92 , & V_93 , 1 ) ;
if ( V_62 < 0 )
F_32 ( V_18 ) ;
return V_62 ;
}
static T_4 int F_33 ( struct V_85 * V_94 )
{
F_34 ( & V_94 -> V_26 ) ;
F_32 ( F_35 ( V_94 ) ) ;
return 0 ;
}
static int T_3 F_36 ( struct V_95 * V_96 )
{
struct V_17 * V_18 ;
int V_62 ;
V_18 = F_29 ( sizeof( struct V_17 ) , V_89 ) ;
if ( V_18 == NULL )
return - V_90 ;
V_18 -> V_75 = V_97 ;
F_37 ( V_96 , V_18 ) ;
V_62 = F_31 ( & V_96 -> V_26 ,
& V_92 , & V_93 , 1 ) ;
if ( V_62 < 0 )
F_32 ( V_18 ) ;
return V_62 ;
}
static int T_4 F_38 ( struct V_95 * V_96 )
{
F_34 ( & V_96 -> V_26 ) ;
F_32 ( F_39 ( V_96 ) ) ;
return 0 ;
}
static int T_5 F_40 ( void )
{
int V_62 ;
#if F_41 ( V_98 ) || F_41 ( V_99 )
V_62 = F_42 ( & V_100 ) ;
if ( V_62 != 0 ) {
F_43 ( V_101 L_7 ,
V_62 ) ;
}
#endif
#if F_41 ( V_102 )
V_62 = F_44 ( & V_103 ) ;
if ( V_62 != 0 ) {
F_43 ( V_101 L_8 ,
V_62 ) ;
}
#endif
return 0 ;
}
static void T_6 F_45 ( void )
{
#if F_41 ( V_102 )
F_46 ( & V_103 ) ;
#endif
#if F_41 ( V_98 ) || F_41 ( V_99 )
F_47 ( & V_100 ) ;
#endif
}
