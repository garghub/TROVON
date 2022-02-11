static struct V_1 * F_1 (
struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
return F_2 ( V_5 -> V_7 , V_3 ) ;
}
static void F_3 ( void T_1 * V_8 ,
struct V_9 * V_10 ,
bool V_11 ,
T_2 V_12 ,
T_2 V_13 ,
T_2 V_14 )
{
T_2 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
T_2 V_18 ;
V_10 -> V_19 = V_13 ;
V_10 -> V_20 = V_14 ;
if ( V_11 ) {
V_15 = V_12 ;
V_16 = V_15 ^ F_4 ( 31 ) ;
} else {
V_16 = V_12 ;
V_15 = V_16 ;
}
V_17 = V_12 + V_14 - 1 ;
V_18 = V_13 - V_21 ;
F_5 ( V_12 , V_8 + V_10 -> V_22 ) ;
F_5 ( V_17 , V_8 + V_10 -> V_23 ) ;
F_5 ( V_18 , V_8 + V_10 -> V_24 ) ;
F_5 ( V_15 , V_8 + V_10 -> V_25 ) ;
F_5 ( V_16 , V_8 + V_10 -> V_26 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_27 ;
struct V_9 * V_10 ;
int V_28 = 0 ;
V_27 = F_1 ( V_3 ) ;
if ( V_3 -> V_29 == V_30 ) {
V_10 = & V_27 -> V_31 ;
switch ( V_27 -> V_32 ) {
case 0 :
* V_10 = F_7 ( 0 ) ;
break;
case 1 :
* V_10 = F_7 ( 2 ) ;
break;
case 2 :
* V_10 = F_7 ( 4 ) ;
break;
case 3 :
* V_10 = F_7 ( 6 ) ;
break;
default:
V_28 = - V_33 ;
}
} else {
V_10 = & V_27 -> V_34 ;
switch ( V_27 -> V_32 ) {
case 0 :
* V_10 = F_8 ( 0 ) ;
break;
case 1 :
* V_10 = F_8 ( 2 ) ;
break;
case 2 :
* V_10 = F_8 ( 4 ) ;
break;
default:
V_28 = - V_33 ;
}
}
return V_28 ;
}
static struct V_9 * F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_27 ;
struct V_9 * V_10 = NULL ;
V_27 = F_1 ( V_3 ) ;
if ( V_3 -> V_29 == V_30 )
V_10 = & V_27 -> V_31 ;
else
V_10 = & V_27 -> V_34 ;
return V_10 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_27 ;
T_2 V_35 ;
V_27 = F_1 ( V_3 ) ;
V_35 = F_4 ( V_27 -> V_32 ) ;
if ( V_3 -> V_29 == V_30 ) {
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_38 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_39 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_40 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_41 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_42 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_43 ) ;
F_5 ( V_44 ,
V_27 -> V_36 -> V_37 + V_45 ) ;
} else {
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_46 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_47 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_48 ) ;
F_5 ( V_35 , V_27 -> V_36 -> V_37 + V_49 ) ;
F_5 ( V_50 ,
V_27 -> V_36 -> V_37 + V_45 ) ;
}
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_1 * V_27 ;
T_2 V_52 ;
V_27 = F_1 ( V_3 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_1 , V_54 , V_27 -> V_32 ) ;
V_52 = F_4 ( V_27 -> V_32 ) ;
if ( V_3 -> V_29 == V_30 ) {
F_5 ( V_52 , V_27 -> V_36 -> V_37 + V_55 ) ;
F_5 ( V_52 , V_27 -> V_36 -> V_37 + V_56 ) ;
F_5 ( V_52 , V_27 -> V_36 -> V_37 + V_57 ) ;
} else {
F_5 ( V_52 , V_27 -> V_36 -> V_37 + V_58 ) ;
F_5 ( V_52 , V_27 -> V_36 -> V_37 + V_59 ) ;
}
}
static int F_13 ( struct V_2 * V_3 , int V_60 )
{
int V_61 = 0 ;
switch ( V_60 ) {
case V_62 :
case V_63 :
F_10 ( V_3 ) ;
break;
case V_64 :
case V_65 :
F_11 ( V_3 ) ;
break;
default:
V_61 = - V_33 ;
}
return V_61 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_27 ;
struct V_9 * V_10 = NULL ;
T_2 V_66 ;
V_27 = F_1 ( V_3 ) ;
V_10 = F_9 ( V_3 ) ;
F_15 ( V_3 ) ;
if ( V_3 -> V_29 == V_30 ) {
V_66 = F_16 ( V_27 -> V_36 -> V_37 + V_10 -> V_25 ) ;
V_66 = V_66 ^ F_4 ( 31 ) ;
F_5 ( V_66 , V_27 -> V_36 -> V_37 + V_10 -> V_26 ) ;
} else {
V_66 = F_16 ( V_27 -> V_36 -> V_37 + V_10 -> V_26 ) ;
F_5 ( V_66 , V_27 -> V_36 -> V_37 + V_10 -> V_25 ) ;
}
}
static void F_17 ( struct V_67 * V_36 )
{
void T_1 * V_8 ;
T_2 V_68 ;
T_2 V_69 , V_70 , V_71 ;
V_8 = V_36 -> V_37 ;
V_69 = F_16 ( V_8 + V_72 ) ;
V_69 &= ~ F_16 ( V_8 + V_73 ) ;
V_70 = F_16 ( V_8 + V_74 ) ;
V_70 &= ~ F_16 ( V_8 + V_75 ) ;
V_71 = F_16 ( V_8 + V_76 ) ;
V_71 &= ~ F_16 ( V_8 + V_77 ) ;
for ( V_68 = 0 ; V_68 < V_78 ; V_68 ++ ) {
T_2 V_79 = F_4 ( V_68 ) ;
if ( ( V_79 & V_70 ) || ( V_79 & V_69 ) ) {
F_12 ( V_36 -> V_53 ,
L_2 ,
V_69 , V_70 , V_71 ) ;
}
if ( V_79 & V_71 ) {
struct V_2 * V_80 ;
V_80 = V_36 -> V_81 [ V_68 ] . V_82 ;
F_14 ( V_80 ) ;
}
}
F_5 ( V_69 , V_8 + V_38 ) ;
F_5 ( V_70 , V_8 + V_39 ) ;
F_5 ( V_71 , V_8 + V_40 ) ;
F_5 ( V_71 , V_8 + V_83 ) ;
}
static void F_18 ( struct V_67 * V_36 )
{
void T_1 * V_8 ;
T_2 V_68 ;
T_2 V_84 , V_85 ;
V_8 = V_36 -> V_37 ;
V_84 = F_16 ( V_8 + V_86 ) ;
V_84 &= ~ F_16 ( V_8 + V_87 ) ;
V_85 = F_16 ( V_8 + V_88 ) ;
V_85 &= ~ F_16 ( V_8 + V_89 ) ;
for ( V_68 = 0 ; V_68 < V_90 ; V_68 ++ ) {
T_2 V_79 = F_4 ( V_68 ) ;
if ( V_79 & V_84 )
F_12 ( V_36 -> V_53 ,
L_3 , V_84 ) ;
if ( V_79 & V_85 ) {
struct V_2 * V_91 ;
V_91 = V_36 -> V_81 [ V_68 ] . V_92 ;
F_14 ( V_91 ) ;
}
}
F_5 ( V_84 , V_8 + V_46 ) ;
F_5 ( V_85 , V_8 + V_47 ) ;
F_5 ( V_85 , V_8 + V_93 ) ;
}
static T_3 F_19 ( int V_94 , void * V_95 )
{
T_2 V_96 ;
struct V_67 * V_36 = V_95 ;
V_96 = F_16 ( V_36 -> V_37 + V_97 ) ;
if ( ! ( V_96 & ( V_44 | V_50 ) ) )
return V_98 ;
if ( V_44 & V_96 ) {
F_17 ( V_36 ) ;
F_5 ( V_44 & V_96 ,
V_36 -> V_37 + V_99 ) ;
}
if ( V_50 & V_96 ) {
F_18 ( V_36 ) ;
F_5 ( V_50 & V_96 ,
V_36 -> V_37 + V_99 ) ;
}
return V_100 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_101 * V_102 = V_3 -> V_102 ;
struct V_1 * V_27 ;
int V_61 ;
V_27 = F_1 ( V_3 ) ;
if ( ! V_27 )
return - V_103 ;
F_12 ( V_51 -> V_7 -> V_53 , L_4 , V_54 , V_27 -> V_32 ) ;
F_21 ( V_3 , & V_104 ) ;
V_61 = F_22 ( V_102 , 0 ,
V_105 , V_21 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_22 ( V_102 , 0 ,
V_106 , V_21 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_3 -> V_29 == V_30 )
V_27 -> V_82 = V_3 ;
else
V_27 -> V_92 = V_3 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_1 * V_27 ;
V_27 = F_1 ( V_3 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_5 , V_54 , V_27 -> V_32 ) ;
if ( V_3 -> V_29 == V_30 )
V_27 -> V_82 = NULL ;
else
V_27 -> V_92 = NULL ;
if ( ! V_27 -> V_82 && ! V_27 -> V_92 )
F_12 ( V_51 -> V_7 -> V_53 , L_6 , V_27 -> V_32 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_107 * V_108 )
{
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_101 * V_102 = V_3 -> V_102 ;
struct V_1 * V_27 ;
int V_61 = 0 ;
V_27 = F_1 ( V_3 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_5 , V_54 , V_27 -> V_32 ) ;
F_25 ( V_3 , & V_3 -> V_109 ) ;
V_102 -> V_110 = F_26 ( V_108 ) ;
return V_61 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_1 * V_27 ;
V_27 = F_1 ( V_3 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_5 , V_54 , V_27 -> V_32 ) ;
F_25 ( V_3 , NULL ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_101 * V_102 = V_3 -> V_102 ;
struct V_1 * V_27 ;
unsigned long V_14 , V_13 ;
int V_61 = 0 ;
bool V_111 ;
T_2 V_12 ;
struct V_9 * V_10 = NULL ;
V_27 = F_1 ( V_3 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_4 , V_54 , V_27 -> V_32 ) ;
V_14 = F_29 ( V_3 ) ;
V_13 = F_30 ( V_3 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_7 ,
V_54 , V_14 , V_13 ) ;
F_6 ( V_3 ) ;
V_10 = F_9 ( V_3 ) ;
V_12 = V_102 -> V_112 ;
V_111 = ( V_3 -> V_29 == V_30 ) ? 1 : 0 ;
F_3 ( V_27 -> V_36 -> V_37 , V_10 , V_111 , V_12 ,
V_13 , V_14 ) ;
return V_61 ;
}
static T_4 F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_27 ;
unsigned int V_113 = 0 , V_114 = 0 , V_115 = 0 ;
struct V_9 * V_10 = NULL ;
V_27 = F_1 ( V_3 ) ;
V_10 = F_9 ( V_3 ) ;
if ( V_3 -> V_29 == V_30 )
V_114 = F_16 ( V_27 -> V_36 -> V_37 + V_10 -> V_25 ) ;
else
V_114 = F_16 ( V_27 -> V_36 -> V_37 + V_10 -> V_26 ) ;
V_115 = F_16 ( V_27 -> V_36 -> V_37 + V_10 -> V_22 ) ;
V_113 = ( V_114 & 0x7fffffff ) - ( V_115 & 0x7fffffff ) ;
return F_32 ( V_3 -> V_102 , V_113 ) ;
}
static int F_33 ( struct V_116 * V_117 , int V_29 )
{
struct V_2 * V_3 = V_117 -> V_118 [ V_29 ] . V_3 ;
struct V_4 * V_51 = V_3 -> V_6 ;
struct V_119 * V_120 = & V_3 -> V_109 ;
T_5 V_121 ;
V_121 = V_104 . V_122 ;
V_120 -> V_53 . type = V_123 ;
V_120 -> V_53 . V_53 = V_117 -> V_124 -> V_53 ;
V_120 -> V_6 = NULL ;
V_120 -> V_125 = F_34 ( V_117 -> V_124 -> V_53 , V_121 ,
& V_120 -> V_126 , V_127 ) ;
F_12 ( V_51 -> V_7 -> V_53 , L_8 ,
V_54 , V_121 , V_120 -> V_125 ) ;
if ( ! V_120 -> V_125 ) {
F_35 ( V_51 -> V_7 -> V_53 , L_9 , V_54 ) ;
return - V_128 ;
}
V_120 -> V_129 = V_121 ;
return 0 ;
}
static void F_36 ( struct V_116 * V_117 )
{
struct V_2 * V_3 ;
struct V_119 * V_120 ;
V_3 = V_117 -> V_118 [ V_30 ] . V_3 ;
if ( V_3 ) {
V_120 = & V_3 -> V_109 ;
if ( V_120 -> V_125 ) {
F_37 ( V_117 -> V_124 -> V_53 , V_120 -> V_129 ,
V_120 -> V_125 , V_120 -> V_126 ) ;
V_120 -> V_125 = NULL ;
}
}
V_3 = V_117 -> V_118 [ V_130 ] . V_3 ;
if ( V_3 ) {
V_120 = & V_3 -> V_109 ;
if ( V_120 -> V_125 ) {
F_37 ( V_117 -> V_124 -> V_53 , V_120 -> V_129 ,
V_120 -> V_125 , V_120 -> V_126 ) ;
V_120 -> V_125 = NULL ;
}
}
}
static int F_38 ( struct V_4 * V_51 )
{
struct V_131 * V_124 = V_51 -> V_124 -> V_131 ;
struct V_116 * V_117 = V_51 -> V_117 ;
int V_61 ;
if ( ! V_124 -> V_53 -> V_132 )
V_124 -> V_53 -> V_132 = & V_133 ;
if ( ! V_124 -> V_53 -> V_134 )
V_124 -> V_53 -> V_134 = F_39 ( 32 ) ;
if ( V_117 -> V_118 [ V_30 ] . V_3 ) {
V_61 = F_33 ( V_117 ,
V_30 ) ;
if ( V_61 )
return V_61 ;
}
if ( V_117 -> V_118 [ V_130 ] . V_3 ) {
V_61 = F_33 ( V_117 ,
V_130 ) ;
if ( V_61 ) {
F_36 ( V_117 ) ;
return V_61 ;
}
}
return 0 ;
}
int F_40 ( struct V_135 * V_53 ,
struct V_67 * V_36 )
{
int V_136 = 0 ;
F_12 ( V_53 , L_10 , V_54 ) ;
V_136 = F_41 ( V_53 , V_36 -> V_137 , F_19 ,
V_138 , L_11 , V_36 ) ;
if ( V_136 ) {
F_35 ( V_53 , L_12 , V_54 , V_136 ) ;
return V_136 ;
}
V_136 = F_42 ( V_53 , & V_139 ) ;
if ( V_136 ) {
F_35 ( V_53 , L_13 , V_54 ) ;
return V_136 ;
}
return 0 ;
}
int F_43 ( struct V_135 * V_53 )
{
F_44 ( V_53 ) ;
return 0 ;
}
