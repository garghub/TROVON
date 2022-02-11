static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_7 ;
int V_8 ;
if ( V_6 -> V_9 & V_10 )
return true ;
V_8 = F_5 ( V_4 , V_11 , V_6 -> V_12 -> V_13 ,
& V_7 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_3 -> V_14 , L_1 ,
V_6 -> V_12 -> V_13 , V_8 ) ;
return V_8 ;
}
return ( ( V_7 & V_15 ) == V_16 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( V_6 -> V_9 & V_10 )
return 0 ;
V_8 = F_8 ( V_4 , V_11 , V_6 -> V_12 -> V_13 ,
V_16 , V_15 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_3 -> V_14 , L_2 ,
V_6 -> V_12 -> V_13 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( V_6 -> V_9 & V_10 )
return 0 ;
V_8 = F_8 ( V_4 , V_11 , V_6 -> V_12 -> V_13 ,
V_17 , V_15 ) ;
if ( V_8 < 0 )
F_6 ( & V_3 -> V_14 , L_2 ,
V_6 -> V_12 -> V_13 , V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_18 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
int V_19 = V_6 -> V_20 & 0x3 ;
if ( V_18 == 0 )
return 0 ;
else if ( V_18 < 58 )
return F_11 ( V_3 , V_18 - 1 ) ;
else
return V_21 [ V_19 ] [ V_18 - 58 ] * 1000 ;
}
static int F_12 ( struct V_2 * V_3 ,
unsigned V_22 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
T_1 V_7 ;
if ( V_6 -> V_12 -> V_23 ) {
V_8 = F_5 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_23 , & V_7 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_6 -> V_12 -> V_23 , V_8 ) ;
return V_8 ;
}
if ( ! ( V_7 & V_25 ) ) {
V_8 = F_8 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_23 , V_22 , V_26 ) ;
if ( V_8 < 0 )
F_6 ( V_6 -> V_14 ,
L_4 ,
V_6 -> V_12 -> V_23 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_8 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_27 , V_22 , V_26 ) ;
if ( V_8 < 0 )
F_6 ( V_6 -> V_14 , L_4 ,
V_6 -> V_12 -> V_27 , V_8 ) ;
return V_8 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_22 = 0 ;
int V_8 ;
if ( V_6 -> V_12 -> V_23 ) {
V_8 = F_5 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_23 , & V_22 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_6 -> V_12 -> V_23 , V_8 ) ;
return V_8 ;
}
if ( ! ( V_22 & V_25 ) )
return V_22 & V_26 ;
}
V_8 = F_5 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_27 , & V_22 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_6 -> V_12 -> V_27 , V_8 ) ;
return V_8 ;
}
return V_22 & V_26 ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned V_18 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
if ( ( V_6 -> V_12 -> V_28 . V_29 == V_30 ) &&
( V_6 -> V_20 & V_31 ) ) {
unsigned V_32 = ( V_18 ) & 0x1F ;
if ( ( ( F_15 ( V_4 ) == V_33 ) ||
( ( F_15 ( V_4 ) == V_34 ) &&
( F_16 ( V_4 ) == 0x0 ) ) ) &&
( ( V_32 == 0x0 ) || ( V_32 >= 0x19 && V_32 <= 0x1F ) ) ) {
F_6 ( V_6 -> V_14 ,
L_5 ,
V_32 ) ;
return - V_35 ;
}
}
V_8 = F_17 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_27 , V_18 ) ;
if ( V_8 < 0 )
F_6 ( V_6 -> V_14 , L_6 ,
V_6 -> V_12 -> V_27 , V_8 ) ;
return V_8 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_22 ;
int V_8 ;
V_8 = F_5 ( V_4 , V_6 -> V_12 -> V_24 ,
V_6 -> V_12 -> V_27 , & V_22 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_7 ) ;
return V_8 ;
}
return V_22 & V_3 -> V_28 -> V_36 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = - V_37 ;
T_2 V_38 = 0 ;
T_2 V_39 = 0 ;
V_8 = F_5 ( V_4 , V_40 ,
V_41 , & V_38 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_41 , V_8 ) ;
return V_8 ;
}
V_8 = F_5 ( V_4 , V_40 ,
V_42 , & V_39 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_42 , V_8 ) ;
return V_8 ;
}
if ( ( V_38 & V_43 ) && ( V_39 & V_44 ) )
return 1 ;
return V_8 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_21 ( V_4 , V_40 ,
V_41 , V_43 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_41 , V_8 ) ;
return V_8 ;
}
V_8 = F_21 ( V_4 , V_40 ,
V_42 , V_44 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_42 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = 0 ;
if ( V_6 -> V_45 & V_46 ) {
V_8 = F_17 ( V_4 , V_40 ,
V_47 , V_48 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_8 ,
V_47 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_23 ( V_4 , V_40 ,
V_41 , V_43 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_9 ,
V_41 , V_8 ) ;
return V_8 ;
}
V_8 = F_23 ( V_4 , V_40 ,
V_42 , V_44 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_9 ,
V_42 , V_8 ) ;
return V_8 ;
}
F_24 ( F_25 ( V_6 -> V_12 -> V_28 . V_49 , 1000 ) ) ;
if ( V_6 -> V_45 & V_46 ) {
V_8 = F_17 ( V_4 , V_40 ,
V_50 , V_48 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_8 ,
V_50 , V_8 ) ;
return V_8 ;
}
}
return V_8 ;
}
static int F_26 ( struct V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_51 * V_52 )
{
int V_8 = 0 ;
if ( V_6 -> V_12 -> V_53 < 0 )
goto V_54;
V_8 = F_27 ( V_4 , V_6 -> V_9 ,
V_6 -> V_12 -> V_53 , V_6 -> V_12 -> V_13 ,
V_6 -> V_12 -> V_55 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_10 , V_8 ) ;
return V_8 ;
}
V_54:
if ( V_52 -> V_9 & V_56 ) {
V_8 = F_8 ( V_4 , V_11 ,
V_6 -> V_12 -> V_55 , V_57 ,
V_58 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_11 ,
V_6 -> V_12 -> V_55 , V_8 ) ;
return V_8 ;
}
}
return V_8 ;
}
static int F_28 ( struct V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_51 * V_52 )
{
int V_8 = 0 ;
switch ( V_6 -> V_12 -> V_28 . V_29 ) {
case V_59 :
if ( V_6 -> V_45 & ( V_60 |
V_61 ) ) {
unsigned V_62 = 0 ;
if ( V_6 -> V_45 & V_60 )
V_62 = V_63 ;
else
V_62 = V_64 ;
V_8 = F_8 ( V_4 , V_11 ,
V_65 , V_62 ,
V_66 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 ,
L_12 , V_8 ) ;
return V_8 ;
}
}
break;
case V_67 :
if ( V_6 -> V_45 & V_68 ) {
V_8 = F_8 ( V_4 , V_11 ,
V_65 , V_69 ,
V_70 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 ,
L_13 , V_8 ) ;
return V_8 ;
}
}
break;
case V_71 :
if ( ! ( V_6 -> V_45 & V_72 ) )
V_6 -> V_12 -> V_28 . V_73 = & V_74 ;
break;
default:
break;
}
V_8 = F_8 ( V_4 , V_11 , V_6 -> V_12 -> V_55 ,
V_75 | V_76 |
V_77 , V_78 |
V_58 | V_79 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_14 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_29 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
int V_80 ;
int V_8 ;
T_1 V_81 ;
T_1 V_82 ;
V_8 = F_5 ( V_4 , V_11 ,
V_83 , & V_81 ) ;
if ( V_8 < 0 ) {
F_6 ( V_4 , L_15 ) ;
return V_8 ;
}
V_8 = F_5 ( V_4 , V_11 ,
V_84 , & V_82 ) ;
if ( V_8 < 0 ) {
F_6 ( V_4 , L_16 ) ;
return V_8 ;
}
switch ( V_6 -> V_12 -> V_28 . V_29 ) {
case V_85 :
V_80 = V_86 ;
break;
case V_87 :
V_80 = V_88 ;
break;
case V_89 :
V_80 = V_90 ;
break;
case V_91 :
V_80 = V_92 ;
break;
case V_93 :
V_80 = V_94 ;
break;
case V_30 :
V_6 -> V_20 = V_82 & F_30 ( 5 ) ? V_31 : 0 ;
if ( V_6 -> V_20 & V_31 ) {
V_6 -> V_12 -> V_28 . V_95 = 600000 ;
V_6 -> V_12 -> V_28 . V_96 = 12500 ;
V_6 -> V_12 -> V_28 . V_97 = 57 ;
V_6 -> V_12 -> V_28 . V_36 = V_98 ;
}
return 0 ;
default:
return 0 ;
}
V_6 -> V_20 = ( V_81 & V_80 ) ? V_99 : 0 ;
V_6 -> V_20 |= ( V_82 & V_80 ) ? V_100 : 0 ;
switch ( V_6 -> V_20 ) {
case 0 :
V_6 -> V_12 -> V_28 . V_95 = 607700 ;
V_6 -> V_12 -> V_28 . V_96 = 12660 ;
break;
case V_99 :
V_6 -> V_12 -> V_28 . V_95 = 700000 ;
V_6 -> V_12 -> V_28 . V_96 = 12500 ;
break;
case V_100 :
V_6 -> V_12 -> V_28 . V_95 = 1852000 ;
V_6 -> V_12 -> V_28 . V_96 = 38600 ;
break;
case V_99 | V_100 :
V_6 -> V_12 -> V_28 . V_95 = 2161000 ;
V_6 -> V_12 -> V_28 . V_96 = 38600 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_101 * V_102 )
{
struct V_103 * V_104 ;
struct V_51 * V_105 ;
struct V_5 * V_6 ;
struct V_5 * V_106 ;
struct V_2 * V_3 ;
struct V_107 V_108 = { } ;
int V_8 ;
int V_109 ;
V_104 = F_32 ( V_102 -> V_14 . V_4 ) ;
if ( ! V_104 ) {
F_6 ( & V_102 -> V_14 , L_17 ) ;
return - V_35 ;
}
V_106 = F_33 ( & V_102 -> V_14 ,
V_110 * sizeof( * V_106 ) , V_111 ) ;
if ( ! V_106 ) {
F_6 ( & V_102 -> V_14 , L_18 ) ;
return - V_112 ;
}
for ( V_109 = 0 ; V_109 < V_110 ; ++ V_109 ) {
V_105 = V_104 -> V_113 [ V_109 ] ;
V_6 = & V_106 [ V_109 ] ;
V_6 -> V_12 = & V_114 [ V_109 ] ;
V_6 -> V_14 = & V_102 -> V_14 ;
F_29 ( V_102 -> V_14 . V_4 , V_6 ) ;
V_108 . V_14 = & V_102 -> V_14 ;
V_108 . V_115 = NULL ;
V_108 . V_116 = V_6 ;
if ( V_105 ) {
V_108 . V_115 = V_105 -> V_117 ;
V_6 -> V_45 = V_105 -> V_45 ;
V_6 -> V_9 = V_105 -> V_9 ;
V_8 = F_28 ( V_102 -> V_14 . V_4 ,
V_6 , V_105 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_102 -> V_14 ,
L_19 , V_8 ) ;
goto V_118;
}
V_8 = F_26 ( V_102 -> V_14 . V_4 ,
V_6 , V_105 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_102 -> V_14 ,
L_20 , V_8 ) ;
goto V_118;
}
}
V_3 = F_34 ( & V_6 -> V_12 -> V_28 , & V_108 ) ;
if ( F_35 ( V_3 ) ) {
F_6 ( & V_102 -> V_14 ,
L_21 ,
V_6 -> V_12 -> V_28 . V_119 ) ;
V_8 = F_36 ( V_3 ) ;
goto V_118;
}
V_6 -> V_3 = V_3 ;
}
F_37 ( V_102 , V_106 ) ;
return 0 ;
V_118:
while ( -- V_109 >= 0 ) {
V_6 = & V_106 [ V_109 ] ;
F_38 ( V_6 -> V_3 ) ;
}
return V_8 ;
}
static int F_39 ( struct V_101 * V_102 )
{
struct V_5 * V_106 = F_40 ( V_102 ) ;
struct V_5 * V_6 = NULL ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_110 ; ++ V_109 ) {
V_6 = & V_106 [ V_109 ] ;
F_38 ( V_6 -> V_3 ) ;
}
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_120 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_120 ) ;
}
