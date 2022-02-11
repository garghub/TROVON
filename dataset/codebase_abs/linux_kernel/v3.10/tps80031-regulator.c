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
unsigned int V_18 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
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
return F_11 ( V_3 , V_18 ) ;
}
static int F_17 ( struct V_2 * V_3 ,
int V_36 , int V_37 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ( V_6 -> V_12 -> V_28 . V_29 == V_30 ) &&
( V_6 -> V_20 & V_31 ) ) {
if ( ( ( F_15 ( V_4 ) == V_33 ) ||
( ( F_15 ( V_4 ) == V_34 ) &&
( F_16 ( V_4 ) == 0x0 ) ) ) ) {
return F_18 ( V_3 , V_36 ,
V_37 ) ;
}
}
return F_19 ( V_3 , V_36 , V_37 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = - V_38 ;
T_2 V_39 = 0 ;
T_2 V_40 = 0 ;
V_8 = F_5 ( V_4 , V_41 ,
V_42 , & V_39 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_42 , V_8 ) ;
return V_8 ;
}
V_8 = F_5 ( V_4 , V_41 ,
V_43 , & V_40 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_43 , V_8 ) ;
return V_8 ;
}
if ( ( V_39 & V_44 ) && ( V_40 & V_45 ) )
return 1 ;
return V_8 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_22 ( V_4 , V_41 ,
V_42 , V_44 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_42 , V_8 ) ;
return V_8 ;
}
V_8 = F_22 ( V_4 , V_41 ,
V_43 , V_45 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_3 ,
V_43 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 = 0 ;
if ( V_6 -> V_46 & V_47 ) {
V_8 = F_24 ( V_4 , V_41 ,
V_48 , V_49 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_6 ,
V_48 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_25 ( V_4 , V_41 ,
V_42 , V_44 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_7 ,
V_42 , V_8 ) ;
return V_8 ;
}
V_8 = F_25 ( V_4 , V_41 ,
V_43 , V_45 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_7 ,
V_43 , V_8 ) ;
return V_8 ;
}
F_26 ( F_27 ( V_6 -> V_12 -> V_28 . V_50 , 1000 ) ) ;
if ( V_6 -> V_46 & V_47 ) {
V_8 = F_24 ( V_4 , V_41 ,
V_51 , V_49 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_6 ,
V_51 , V_8 ) ;
return V_8 ;
}
}
return V_8 ;
}
static int F_28 ( struct V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_52 * V_53 )
{
int V_8 = 0 ;
if ( V_6 -> V_12 -> V_54 < 0 )
goto V_55;
V_8 = F_29 ( V_4 , V_6 -> V_9 ,
V_6 -> V_12 -> V_54 , V_6 -> V_12 -> V_13 ,
V_6 -> V_12 -> V_56 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_8 , V_8 ) ;
return V_8 ;
}
V_55:
if ( V_53 -> V_9 & V_57 ) {
V_8 = F_8 ( V_4 , V_11 ,
V_6 -> V_12 -> V_56 , V_58 ,
V_59 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_9 ,
V_6 -> V_12 -> V_56 , V_8 ) ;
return V_8 ;
}
}
return V_8 ;
}
static int F_30 ( struct V_1 * V_4 ,
struct V_5 * V_6 ,
struct V_52 * V_53 )
{
int V_8 = 0 ;
switch ( V_6 -> V_12 -> V_28 . V_29 ) {
case V_60 :
if ( V_6 -> V_46 & ( V_61 |
V_62 ) ) {
unsigned V_63 = 0 ;
if ( V_6 -> V_46 & V_61 )
V_63 = V_64 ;
else
V_63 = V_65 ;
V_8 = F_8 ( V_4 , V_11 ,
V_66 , V_63 ,
V_67 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 ,
L_10 , V_8 ) ;
return V_8 ;
}
}
break;
case V_68 :
if ( V_6 -> V_46 & V_69 ) {
V_8 = F_8 ( V_4 , V_11 ,
V_66 , V_70 ,
V_71 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 ,
L_11 , V_8 ) ;
return V_8 ;
}
}
break;
case V_72 :
if ( ! ( V_6 -> V_46 & V_73 ) )
V_6 -> V_12 -> V_28 . V_74 = & V_75 ;
break;
default:
break;
}
V_8 = F_8 ( V_4 , V_11 , V_6 -> V_12 -> V_56 ,
V_76 | V_77 |
V_78 , V_79 |
V_59 | V_80 ) ;
if ( V_8 < 0 ) {
F_6 ( V_6 -> V_14 , L_12 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_31 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
int V_81 ;
int V_8 ;
T_1 V_82 ;
T_1 V_83 ;
V_8 = F_5 ( V_4 , V_11 ,
V_84 , & V_82 ) ;
if ( V_8 < 0 ) {
F_6 ( V_4 , L_13 ) ;
return V_8 ;
}
V_8 = F_5 ( V_4 , V_11 ,
V_85 , & V_83 ) ;
if ( V_8 < 0 ) {
F_6 ( V_4 , L_14 ) ;
return V_8 ;
}
switch ( V_6 -> V_12 -> V_28 . V_29 ) {
case V_86 :
V_81 = V_87 ;
break;
case V_88 :
V_81 = V_89 ;
break;
case V_90 :
V_81 = V_91 ;
break;
case V_92 :
V_81 = V_93 ;
break;
case V_94 :
V_81 = V_95 ;
break;
case V_30 :
V_6 -> V_20 = V_83 & F_32 ( 5 ) ? V_31 : 0 ;
if ( V_6 -> V_20 & V_31 ) {
V_6 -> V_12 -> V_28 . V_36 = 600000 ;
V_6 -> V_12 -> V_28 . V_96 = 12500 ;
V_6 -> V_12 -> V_28 . V_97 = 57 ;
V_6 -> V_12 -> V_28 . V_98 = V_99 ;
}
return 0 ;
default:
return 0 ;
}
V_6 -> V_20 = ( V_82 & V_81 ) ? V_100 : 0 ;
V_6 -> V_20 |= ( V_83 & V_81 ) ? V_101 : 0 ;
switch ( V_6 -> V_20 ) {
case 0 :
V_6 -> V_12 -> V_28 . V_36 = 607700 ;
V_6 -> V_12 -> V_28 . V_96 = 12660 ;
break;
case V_100 :
V_6 -> V_12 -> V_28 . V_36 = 700000 ;
V_6 -> V_12 -> V_28 . V_96 = 12500 ;
break;
case V_101 :
V_6 -> V_12 -> V_28 . V_36 = 1852000 ;
V_6 -> V_12 -> V_28 . V_96 = 38600 ;
break;
case V_100 | V_101 :
V_6 -> V_12 -> V_28 . V_36 = 2161000 ;
V_6 -> V_12 -> V_28 . V_96 = 38600 ;
break;
}
return 0 ;
}
static int F_33 ( struct V_102 * V_103 )
{
struct V_104 * V_105 ;
struct V_52 * V_106 ;
struct V_5 * V_6 ;
struct V_5 * V_107 ;
struct V_2 * V_3 ;
struct V_108 V_109 = { } ;
struct V_110 * V_111 = F_34 ( V_103 -> V_14 . V_4 ) ;
int V_8 ;
int V_112 ;
V_105 = F_35 ( V_103 -> V_14 . V_4 ) ;
if ( ! V_105 ) {
F_6 ( & V_103 -> V_14 , L_15 ) ;
return - V_35 ;
}
V_107 = F_36 ( & V_103 -> V_14 ,
V_113 * sizeof( * V_107 ) , V_114 ) ;
if ( ! V_107 ) {
F_6 ( & V_103 -> V_14 , L_16 ) ;
return - V_115 ;
}
for ( V_112 = 0 ; V_112 < V_113 ; ++ V_112 ) {
V_106 = V_105 -> V_116 [ V_112 ] ;
V_6 = & V_107 [ V_112 ] ;
V_6 -> V_12 = & V_117 [ V_112 ] ;
V_6 -> V_14 = & V_103 -> V_14 ;
F_31 ( V_103 -> V_14 . V_4 , V_6 ) ;
V_109 . V_14 = & V_103 -> V_14 ;
V_109 . V_118 = NULL ;
V_109 . V_119 = V_6 ;
V_109 . V_120 = V_111 -> V_120 [ V_6 -> V_12 -> V_24 ] ;
if ( V_106 ) {
V_109 . V_118 = V_106 -> V_121 ;
V_6 -> V_46 = V_106 -> V_46 ;
V_6 -> V_9 = V_106 -> V_9 ;
V_8 = F_30 ( V_103 -> V_14 . V_4 ,
V_6 , V_106 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_103 -> V_14 ,
L_17 , V_8 ) ;
goto V_122;
}
V_8 = F_28 ( V_103 -> V_14 . V_4 ,
V_6 , V_106 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_103 -> V_14 ,
L_18 , V_8 ) ;
goto V_122;
}
}
V_3 = F_37 ( & V_6 -> V_12 -> V_28 , & V_109 ) ;
if ( F_38 ( V_3 ) ) {
F_6 ( & V_103 -> V_14 ,
L_19 ,
V_6 -> V_12 -> V_28 . V_123 ) ;
V_8 = F_39 ( V_3 ) ;
goto V_122;
}
V_6 -> V_3 = V_3 ;
}
F_40 ( V_103 , V_107 ) ;
return 0 ;
V_122:
while ( -- V_112 >= 0 ) {
V_6 = & V_107 [ V_112 ] ;
F_41 ( V_6 -> V_3 ) ;
}
return V_8 ;
}
static int F_42 ( struct V_102 * V_103 )
{
struct V_5 * V_107 = F_43 ( V_103 ) ;
struct V_5 * V_6 = NULL ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_113 ; ++ V_112 ) {
V_6 = & V_107 [ V_112 ] ;
F_41 ( V_6 -> V_3 ) ;
}
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_124 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_124 ) ;
}
