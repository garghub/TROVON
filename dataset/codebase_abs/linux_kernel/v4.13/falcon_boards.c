static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
while ( * V_3 ) {
T_1 V_4 = * V_3 ++ ;
T_1 V_5 = * V_3 ++ ;
int V_6 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static int F_3 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
const T_1 * V_3 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
struct V_1 * V_2 = F_4 ( & V_12 -> V_13 , V_10 ) ;
int V_6 ;
if ( ! V_2 )
return - V_14 ;
F_5 ( V_2 , V_15 ) ;
F_5 ( V_2 , V_16 ) ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 )
goto V_17;
V_6 = F_1 ( V_2 , V_18 ) ;
if ( V_6 )
goto V_17;
V_12 -> V_19 = V_2 ;
return 0 ;
V_17:
F_6 ( V_2 ) ;
return V_6 ;
}
static void F_7 ( struct V_7 * V_8 )
{
F_6 ( V_11 ( V_8 ) -> V_19 ) ;
}
static int F_8 ( struct V_7 * V_8 , unsigned V_20 )
{
struct V_1 * V_2 = V_11 ( V_8 ) -> V_19 ;
bool V_21 , V_22 , V_23 ;
T_2 V_24 ;
T_3 V_4 ;
if ( F_9 ( V_8 ) && V_8 -> V_25 . V_26 )
return 0 ;
V_4 = F_5 ( V_2 , V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
V_24 = V_4 ;
V_4 = F_5 ( V_2 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
V_24 |= V_4 << 8 ;
V_24 &= V_20 ;
V_21 = false ;
if ( V_24 & V_27 ) {
V_4 = F_5 ( V_2 , V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 > V_29 )
V_21 = true ;
}
if ( V_24 & V_30 ) {
V_4 = F_5 ( V_2 , V_31 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 > V_32 )
V_21 = true ;
}
V_22 = V_24 & ~ ( V_27 | V_30 ) ;
V_23 = V_21 || V_22 ;
if ( V_24 )
F_10 ( V_8 , V_33 , V_8 -> V_34 ,
L_1
L_2 ,
V_23 ? L_3 : L_4 ,
V_24 & 0xff , V_24 >> 8 ,
( V_24 & V_27 ) ?
L_5 : L_6 ,
( V_24 & V_30 ) ?
L_7 : L_6 ,
V_21 ? L_8 : L_6 ,
V_22 ? L_9 : L_6 ) ;
return V_23 ? - V_35 : 0 ;
}
static inline int
F_3 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
const T_1 * V_3 )
{
return 0 ;
}
static inline void F_7 ( struct V_7 * V_8 )
{
}
static inline int F_8 ( struct V_7 * V_8 , unsigned V_20 )
{
return 0 ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_36 = V_11 ( V_8 ) -> V_36 ;
struct V_1 * V_19 = V_11 ( V_8 ) -> V_19 ;
F_2 ( V_36 , V_37 , 0xff ) ;
F_2 ( V_36 , V_38 , 0xff ) ;
F_2 ( V_36 , V_39 , 0xff ) ;
F_5 ( V_19 , V_40 ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_36 = V_11 ( V_8 ) -> V_36 ;
struct V_1 * V_19 = V_11 ( V_8 ) -> V_19 ;
unsigned int V_41 , V_42 ;
int V_6 ;
T_1 V_43 ;
V_6 = F_5 ( V_19 , V_40 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_2 ( V_36 , V_39 , 0x00 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_36 , V_38 ,
0xff & ~ ( 1 << V_44 ) ) ;
if ( V_6 )
goto V_45;
V_6 = F_5 ( V_36 , V_37 ) ;
if ( V_6 < 0 )
goto V_45;
V_43 = 0xff & ~ ( ( 0 << V_46 ) | ( 0 << V_47 ) |
( 0 << V_48 ) | ( 0 << V_49 ) |
( 0 << V_50 ) ) ;
if ( V_6 != V_43 ) {
F_13 ( V_8 , V_33 , V_8 -> V_34 , L_10 ) ;
V_6 = F_2 ( V_36 , V_37 , V_43 ) ;
if ( V_6 )
goto V_45;
F_14 ( V_51 ) ;
}
for ( V_41 = 0 ; V_41 < 20 ; ++ V_41 ) {
V_43 = 0xff & ~ ( ( 1 << V_46 ) | ( 1 << V_47 ) |
( 1 << V_48 ) | ( 1 << V_49 ) |
( 1 << V_52 ) ) ;
if ( V_8 -> V_53 & V_54 )
V_43 |= 1 << V_48 ;
V_6 = F_2 ( V_36 , V_37 , V_43 ) ;
if ( V_6 )
goto V_45;
F_15 ( 10 ) ;
V_43 &= ~ ( 1 << V_50 ) ;
V_6 = F_2 ( V_36 , V_37 , V_43 ) ;
if ( V_6 )
goto V_45;
F_13 ( V_8 , V_33 , V_8 -> V_34 ,
L_11 , V_41 ) ;
if ( V_8 -> V_53 & V_54 ) {
F_14 ( V_51 ) ;
return 0 ;
}
for ( V_42 = 0 ; V_42 < 10 ; ++ V_42 ) {
F_15 ( 100 ) ;
V_6 = F_5 ( V_36 , V_55 ) ;
if ( V_6 < 0 )
goto V_45;
if ( V_6 & ( 1 << V_56 ) )
return 0 ;
}
}
F_13 ( V_8 , V_33 , V_8 -> V_34 , L_12 ) ;
V_6 = - V_57 ;
V_45:
F_11 ( V_8 ) ;
return V_6 ;
}
static T_4 F_16 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_7 * V_8 = F_17 ( F_18 ( V_59 ) ) ;
return sprintf ( V_62 , L_13 , ! ! ( V_8 -> V_53 & V_54 ) ) ;
}
static T_4 F_19 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_62 , T_5 V_63 )
{
struct V_7 * V_8 = F_17 ( F_18 ( V_59 ) ) ;
enum V_64 V_65 , V_66 ;
int V_17 ;
F_20 () ;
V_65 = V_8 -> V_53 ;
if ( V_63 == 0 || * V_62 == '0' )
V_66 = V_65 & ~ V_54 ;
else
V_66 = V_54 ;
if ( ! ( ( V_65 ^ V_66 ) & V_54 ) ) {
V_17 = 0 ;
} else if ( V_8 -> V_67 != V_68 || F_21 ( V_8 -> V_34 ) ) {
V_17 = - V_69 ;
} else {
V_8 -> V_53 = V_66 ;
if ( V_66 & V_54 )
F_22 ( V_8 ) ;
V_17 = F_12 ( V_8 ) ;
if ( ! V_17 )
V_17 = F_23 ( V_8 ) ;
if ( ! ( V_66 & V_54 ) )
F_24 ( V_8 ) ;
}
F_25 () ;
return V_17 ? V_17 : V_63 ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
F_13 ( V_8 , V_70 , V_8 -> V_34 , L_14 , V_71 ) ;
F_27 ( & V_8 -> V_72 -> V_59 , & V_73 ) ;
F_11 ( V_8 ) ;
F_6 ( V_12 -> V_36 ) ;
F_6 ( V_12 -> V_19 ) ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_74 * V_75 = V_8 -> V_75 ;
T_3 V_76 ;
if ( F_9 ( V_8 ) && ! V_75 -> V_77 )
return 0 ;
V_76 = F_5 ( V_11 ( V_8 ) -> V_36 , V_55 ) ;
if ( V_76 >= 0 &&
( V_76 & ( ( 1 << V_56 ) | ( 1 << V_78 ) ) ) != 0 )
return 0 ;
F_11 ( V_8 ) ;
V_8 -> V_53 = V_79 ;
return ( V_76 < 0 ) ? - V_14 : - V_35 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
int V_6 ;
#if F_30 ( V_80 )
V_12 -> V_19 =
F_4 ( & V_12 -> V_13 , & V_81 ) ;
#else
V_12 -> V_19 =
F_31 ( & V_12 -> V_13 , V_81 . V_82 ) ;
#endif
if ( ! V_12 -> V_19 )
return - V_14 ;
V_6 = F_2 ( V_12 -> V_19 ,
V_83 , 90 ) ;
if ( V_6 )
goto V_84;
V_12 -> V_36 = F_31 ( & V_12 -> V_13 , V_85 ) ;
if ( ! V_12 -> V_36 ) {
V_6 = - V_14 ;
goto V_84;
}
if ( V_8 -> V_53 & V_54 ) {
F_22 ( V_8 ) ;
}
V_6 = F_12 ( V_8 ) ;
if ( V_6 )
goto V_86;
V_6 = F_32 ( & V_8 -> V_72 -> V_59 , & V_73 ) ;
if ( V_6 )
goto V_45;
F_13 ( V_8 , V_33 , V_8 -> V_34 , L_15 ) ;
return 0 ;
V_45:
F_11 ( V_8 ) ;
V_86:
F_6 ( V_12 -> V_36 ) ;
V_84:
F_6 ( V_12 -> V_19 ) ;
return V_6 ;
}
static void F_33 ( struct V_7 * V_8 )
{
F_34 ( V_8 , V_87 ,
V_88 | V_89 ) ;
F_34 ( V_8 , V_90 ,
V_91 | V_89 ) ;
F_34 ( V_8 , V_92 , V_93 ) ;
}
static void F_35 ( struct V_7 * V_8 , enum V_94 V_95 )
{
F_34 (
V_8 , V_92 ,
( V_95 == V_96 ) ? V_97 : V_93 ) ;
}
static int F_36 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
unsigned V_98 =
( V_12 -> V_99 == 0 && V_12 -> V_100 == 0 ) ?
~ V_30 : ~ 0 ;
return F_8 ( V_8 , V_98 ) ;
}
static int F_37 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , & V_101 , V_102 ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
F_34 ( V_8 , V_103 ,
V_91 | V_104 ) ;
F_34 ( V_8 , V_105 ,
V_91 | V_106 ) ;
}
static void F_39 ( struct V_7 * V_8 , enum V_94 V_95 )
{
int V_4 ;
switch ( V_95 ) {
case V_107 :
V_4 = V_93 ;
break;
case V_96 :
V_4 = V_97 ;
break;
default:
V_4 = V_91 | V_106 ;
break;
}
F_34 ( V_8 , V_105 , V_4 ) ;
}
static int F_40 ( struct V_7 * V_8 )
{
return F_8 ( V_8 , ~ 0x48 ) ;
}
static int F_41 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , & V_108 , V_109 ) ;
}
static void F_42 ( struct V_7 * V_8 , enum V_94 V_95 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
if ( V_12 -> V_100 < 3 && V_12 -> V_99 == 0 )
return;
F_43 (
V_8 , V_110 ,
( V_95 == V_96 ) ? V_111 : V_112 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
if ( V_12 -> V_100 < 3 && V_12 -> V_99 == 0 )
return;
F_45 ( V_8 , V_110 , V_113 ) ;
F_43 ( V_8 , V_110 , V_112 ) ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
unsigned V_98 =
( V_12 -> V_99 == 0 && V_12 -> V_100 <= 2 ) ?
~ V_30 : ~ 0 ;
return F_8 ( V_8 , V_98 ) ;
}
static int F_47 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , & V_114 , V_115 ) ;
}
int F_48 ( struct V_7 * V_8 , T_2 V_116 )
{
struct V_11 * V_12 = V_11 ( V_8 ) ;
T_1 V_117 = F_49 ( V_116 ) ;
int V_41 ;
V_12 -> V_99 = F_50 ( V_116 ) ;
V_12 -> V_100 = F_51 ( V_116 ) ;
for ( V_41 = 0 ; V_41 < F_52 ( V_118 ) ; V_41 ++ )
if ( V_118 [ V_41 ] . V_119 == V_117 )
V_12 -> type = & V_118 [ V_41 ] ;
if ( V_12 -> type ) {
return 0 ;
} else {
F_10 ( V_8 , V_120 , V_8 -> V_34 , L_16 ,
V_117 ) ;
return - V_121 ;
}
}
