static int F_1 ( int V_1 , int V_2 , int V_3 )
{
int V_4 ;
if ( V_1 == V_5 ) {
if ( V_2 == V_6 )
V_4 = V_7 ;
else
V_4 = V_8 ;
} else {
if ( V_2 == V_6 )
V_4 = V_9 ;
else
V_4 = V_10 ;
}
if ( V_3 == V_11 )
V_4 |= V_12 ;
return V_4 ;
}
static void F_2 ( struct V_13 * V_14 , int V_4 , int * V_1 ,
int * V_2 , int * V_3 )
{
switch ( V_4 & ( V_7 | V_8 |
V_9 | V_10 ) ) {
case V_7 :
* V_1 = V_5 ;
* V_2 = V_6 ;
break;
case V_8 :
* V_1 = V_5 ;
* V_2 = V_15 ;
break;
case V_9 :
* V_1 = V_16 ;
* V_2 = V_6 ;
break;
case V_10 :
* V_1 = V_16 ;
* V_2 = V_15 ;
break;
default:
F_3 ( & V_14 -> V_14 , L_1 ,
V_4 ) ;
* V_1 = V_16 ;
* V_2 = V_15 ;
break;
}
if ( V_4 & V_12 )
* V_3 = V_11 ;
else
* V_3 = V_17 ;
}
static void F_4 ( struct V_13 * V_14 ,
T_1 V_18 , int V_1 ,
int V_2 , int V_3 )
{
int V_19 , V_4 ;
int V_20 , V_21 ;
if ( ! F_5 ( V_18 ) ) {
F_6 ( V_14 , V_18 , V_22 ) ;
return;
}
if ( ! F_7 ( V_18 , & V_21 , & V_20 ) ) {
V_21 = V_21 ? V_5 : V_16 ;
V_20 = V_20 ? V_6 : V_15 ;
if ( V_1 != V_21 || V_2 != V_20 ) {
F_8 ( & V_14 -> V_14 , L_2 ,
V_18 , V_21 ? L_3 : L_4 , V_20 ? L_5 : L_6 ) ;
V_1 = V_21 ;
V_2 = V_20 ;
}
}
V_4 = F_1 ( V_1 , V_2 , V_3 ) ;
V_19 = F_9 ( & V_14 -> V_14 , V_18 , V_1 , V_2 ) ;
if ( V_19 >= 0 )
F_10 ( V_19 , 1 ) ;
else
V_4 |= V_22 ;
F_6 ( V_14 , V_19 , V_4 ) ;
}
static int F_11 ( struct V_13 * V_14 , int type , int V_23 ,
int V_24 )
{
int V_4 = 0 ;
if ( V_23 )
V_4 |= V_25 ;
switch ( type ) {
case V_26 :
V_4 |= V_27 ;
break;
case V_28 :
V_4 |= V_29 ;
break;
case V_30 :
V_4 |= V_31 ;
break;
case V_32 :
V_4 |= V_33 ;
break;
default:
V_4 |= V_27 ;
F_3 ( & V_14 -> V_14 , L_7 , type ) ;
}
switch ( V_24 ) {
case V_34 :
V_4 |= V_35 ;
break;
case V_36 :
V_4 |= V_37 ;
break;
case V_38 :
V_4 |= V_39 ;
break;
default:
V_4 |= V_37 ;
F_3 ( & V_14 -> V_14 , L_8 , V_24 ) ;
}
return V_4 ;
}
static void F_12 ( struct V_13 * V_14 , T_2 V_40 ,
T_2 V_41 , int V_42 ,
int V_43 )
{
int V_4 = 0 ;
T_2 V_44 = V_40 + V_41 - 1 ;
if ( V_42 == V_45 )
V_4 |= V_46 ;
if ( V_41 == 0 || V_44 >= 0x10003 )
V_4 |= V_22 ;
if ( V_43 )
V_4 |= V_47 ;
F_13 ( V_14 , V_40 , V_44 , V_4 ) ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
int V_52 )
{
int V_53 = sizeof( V_49 -> V_54 ) ;
T_3 V_55 = V_49 -> V_55 ;
T_3 * V_54 = V_49 -> V_54 ;
int V_56 ;
V_56 = V_49 -> V_57 - V_53 - 1 ;
if ( V_55 == V_51 -> V_58 &&
V_53 == sizeof( V_51 -> V_59 ) &&
memcmp ( V_54 , V_51 -> V_59 , V_53 ) == 0 ) {
if ( V_52 && V_52 != V_56 ) {
F_3 ( & V_14 -> V_14 , L_9
L_10 ,
V_52 , V_56 ) ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
static void F_15 ( struct V_13 * V_14 ,
struct V_48 * V_49 )
{
if ( F_14 ( V_14 , V_49 , & V_60 , 16 ) ) {
T_2 V_40 , V_61 ;
memcpy ( & V_40 , V_49 -> V_62 , sizeof( V_40 ) ) ;
memcpy ( & V_61 , V_49 -> V_62 + 8 , sizeof( V_61 ) ) ;
F_16 ( V_14 , V_40 , V_40 + V_61 - 1 , 0 ) ;
}
}
static void F_17 ( struct V_13 * V_14 ,
T_2 V_40 , T_2 V_41 ,
int V_63 , int V_43 )
{
int V_4 = 0 ;
T_2 V_44 = V_40 + V_41 - 1 ;
if ( V_41 == 0 )
V_4 |= V_22 ;
if ( V_63 == V_64 )
V_4 |= V_65 ;
if ( V_43 )
V_4 |= V_47 ;
F_16 ( V_14 , V_40 , V_44 , V_4 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
T_2 V_40 , T_2 V_41 )
{
T_2 V_44 = V_40 + V_41 - 1 ;
F_19 ( V_14 , V_40 , V_44 ) ;
}
static void F_20 ( struct V_13 * V_14 ,
struct V_66 * V_67 )
{
struct V_68 V_69 , * V_20 = & V_69 ;
T_4 V_70 ;
int V_43 ;
T_2 V_41 ;
V_70 = F_21 ( V_67 , V_20 ) ;
if ( ! F_22 ( V_70 ) ) {
F_8 ( & V_14 -> V_14 , L_11 ,
V_67 -> type ) ;
return;
}
V_41 = V_20 -> V_71 - V_20 -> V_72 + 1 ;
V_43 = ( V_20 -> V_73 == V_74 ) ? 1 : 0 ;
if ( V_20 -> V_75 == V_76 )
F_17 ( V_14 , V_20 -> V_72 , V_41 ,
V_20 -> V_77 . V_78 . V_63 , V_43 ) ;
else if ( V_20 -> V_75 == V_79 )
F_12 ( V_14 , V_20 -> V_72 , V_41 ,
V_20 -> V_80 == 0xfff ? V_81 :
V_45 , V_43 ) ;
else if ( V_20 -> V_75 == V_82 )
F_18 ( V_14 , V_20 -> V_72 , V_41 ) ;
}
static void F_23 ( struct V_13 * V_14 ,
struct V_66 * V_67 )
{
struct V_83 * V_20 = & V_67 -> V_59 . V_84 ;
int V_43 ;
T_2 V_41 ;
V_41 = V_20 -> V_71 - V_20 -> V_72 + 1 ;
V_43 = ( V_20 -> V_73 == V_74 ) ? 1 : 0 ;
if ( V_20 -> V_75 == V_76 )
F_17 ( V_14 , V_20 -> V_72 , V_41 ,
V_20 -> V_77 . V_78 . V_63 , V_43 ) ;
else if ( V_20 -> V_75 == V_79 )
F_12 ( V_14 , V_20 -> V_72 , V_41 ,
V_20 -> V_80 == 0xfff ? V_81 :
V_45 , V_43 ) ;
else if ( V_20 -> V_75 == V_82 )
F_18 ( V_14 , V_20 -> V_72 , V_41 ) ;
}
static T_4 F_24 ( struct V_66 * V_67 ,
void * V_59 )
{
struct V_13 * V_14 = V_59 ;
struct V_85 * V_19 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_48 * V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_101 , V_4 ;
switch ( V_67 -> type ) {
case V_102 :
V_19 = & V_67 -> V_59 . V_19 ;
if ( V_19 -> V_103 == 0 )
F_6 ( V_14 , 0 , V_22 ) ;
else {
for ( V_101 = 0 ; V_101 < V_19 -> V_103 ; V_101 ++ ) {
F_4 ( V_14 ,
V_19 -> V_104 [ V_101 ] ,
V_19 -> V_1 ,
V_19 -> V_2 ,
V_19 -> V_105 ) ;
}
if ( F_25 ( V_14 ) && V_19 -> V_103 > 1 ) {
F_8 ( & V_14 -> V_14 , L_12
L_13
L_14 ) ;
V_14 -> V_106 &= ~ V_107 ;
}
}
break;
case V_108 :
V_87 = & V_67 -> V_59 . V_87 ;
if ( V_87 -> V_109 > 0 && V_87 -> V_110 [ 0 ] != ( T_3 ) - 1 )
V_4 = F_11 ( V_14 , V_87 -> type , V_87 -> V_23 ,
V_87 -> V_24 ) ;
else
V_4 = V_22 ;
F_26 ( V_14 , V_87 -> V_110 [ 0 ] , V_4 ) ;
break;
case V_111 :
V_89 = & V_67 -> V_59 . V_89 ;
F_12 ( V_14 ,
V_89 -> V_72 ,
V_89 -> V_112 ,
V_89 -> V_42 , 0 ) ;
break;
case V_113 :
case V_114 :
break;
case V_115 :
V_91 = & V_67 -> V_59 . V_91 ;
F_12 ( V_14 ,
V_91 -> V_116 ,
V_91 -> V_112 ,
V_81 , 0 ) ;
break;
case V_117 :
V_92 = & V_67 -> V_59 . V_92 ;
F_15 ( V_14 , V_92 ) ;
break;
case V_118 :
break;
case V_119 :
V_94 = & V_67 -> V_59 . V_94 ;
F_17 ( V_14 ,
V_94 -> V_72 ,
V_94 -> V_112 ,
V_94 -> V_63 , 0 ) ;
break;
case V_120 :
V_96 = & V_67 -> V_59 . V_96 ;
F_17 ( V_14 ,
V_96 -> V_72 ,
V_96 -> V_112 ,
V_96 -> V_63 , 0 ) ;
break;
case V_121 :
V_98 = & V_67 -> V_59 . V_98 ;
F_17 ( V_14 ,
V_98 -> V_116 ,
V_98 -> V_112 ,
V_98 -> V_63 , 0 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
F_20 ( V_14 , V_67 ) ;
break;
case V_125 :
F_23 ( V_14 , V_67 ) ;
break;
case V_126 :
V_100 = & V_67 -> V_59 . V_100 ;
if ( V_100 -> V_103 == 0 )
F_6 ( V_14 , 0 , V_22 ) ;
else {
for ( V_101 = 0 ; V_101 < V_100 -> V_103 ; V_101 ++ ) {
F_4 ( V_14 ,
V_100 -> V_104 [ V_101 ] ,
V_100 -> V_1 ,
V_100 -> V_2 ,
V_100 -> V_105 ) ;
}
if ( F_25 ( V_14 ) &&
V_100 -> V_103 > 1 ) {
F_8 ( & V_14 -> V_14 , L_12
L_13
L_14 ) ;
V_14 -> V_106 &= ~ V_107 ;
}
}
break;
case V_127 :
break;
default:
F_8 ( & V_14 -> V_14 , L_15 ,
V_67 -> type ) ;
return V_128 ;
}
return V_129 ;
}
int F_27 ( struct V_13 * V_14 )
{
struct V_130 * V_131 = V_14 -> V_59 ;
T_5 V_132 = V_131 -> V_132 ;
T_4 V_70 ;
F_28 ( & V_14 -> V_14 , L_16 ) ;
F_29 ( V_14 ) ;
V_70 = F_30 ( V_132 , V_133 ,
F_24 , V_14 ) ;
if ( F_31 ( V_70 ) ) {
if ( V_70 != V_134 )
F_3 ( & V_14 -> V_14 , L_17 , V_70 ) ;
return - V_135 ;
}
return 0 ;
}
static T_6 void F_32 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_86 * V_20 )
{
int V_101 ;
unsigned char V_137 = 0 , V_4 ;
if ( V_20 -> V_109 == 0 )
return;
for ( V_101 = 0 ; V_101 < V_20 -> V_109 ; V_101 ++ )
V_137 |= 1 << V_20 -> V_110 [ V_101 ] ;
V_4 = F_11 ( V_14 , V_20 -> type , V_20 -> V_23 , V_20 -> V_24 ) ;
F_33 ( V_14 , V_136 , V_137 , V_4 ) ;
}
static T_6 void F_34 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_85 * V_20 )
{
int V_101 ;
T_7 V_137 ;
unsigned char V_4 ;
if ( V_20 -> V_103 == 0 )
return;
F_35 ( V_137 . V_138 , V_139 ) ;
for ( V_101 = 0 ; V_101 < V_20 -> V_103 ; V_101 ++ )
if ( V_20 -> V_104 [ V_101 ] )
F_36 ( V_20 -> V_104 [ V_101 ] , V_137 . V_138 ) ;
V_4 = F_1 ( V_20 -> V_1 , V_20 -> V_2 , V_20 -> V_105 ) ;
F_37 ( V_14 , V_136 , & V_137 , V_4 ) ;
}
static T_6 void F_38 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_99 * V_20 )
{
int V_101 ;
T_7 V_137 ;
unsigned char V_4 ;
if ( V_20 -> V_103 == 0 )
return;
F_35 ( V_137 . V_138 , V_139 ) ;
for ( V_101 = 0 ; V_101 < V_20 -> V_103 ; V_101 ++ ) {
if ( V_20 -> V_104 [ V_101 ] ) {
if ( V_20 -> V_104 [ V_101 ] < V_139 )
F_36 ( V_20 -> V_104 [ V_101 ] , V_137 . V_138 ) ;
else
F_3 ( & V_14 -> V_14 , L_18
L_19 ,
V_20 -> V_104 [ V_101 ] , V_139 ) ;
}
}
V_4 = F_1 ( V_20 -> V_1 , V_20 -> V_2 , V_20 -> V_105 ) ;
F_37 ( V_14 , V_136 , & V_137 , V_4 ) ;
}
static T_6 void F_39 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_88 * V_89 )
{
unsigned char V_4 = 0 ;
if ( V_89 -> V_112 == 0 )
return;
if ( V_89 -> V_42 == V_45 )
V_4 = V_46 ;
F_40 ( V_14 , V_136 , V_89 -> V_72 , V_89 -> V_71 ,
V_89 -> V_140 , V_89 -> V_112 , V_4 ) ;
}
static T_6 void F_41 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_90 * V_89 )
{
if ( V_89 -> V_112 == 0 )
return;
F_40 ( V_14 , V_136 , V_89 -> V_116 , V_89 -> V_116 ,
0 , V_89 -> V_112 , V_141 ) ;
}
static T_6 void F_42 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_93 * V_20 )
{
unsigned char V_4 = 0 ;
if ( V_20 -> V_112 == 0 )
return;
if ( V_20 -> V_63 == V_64 )
V_4 = V_65 ;
F_43 ( V_14 , V_136 , V_20 -> V_72 , V_20 -> V_71 ,
V_20 -> V_140 , V_20 -> V_112 , V_4 ) ;
}
static T_6 void F_44 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_95 * V_20 )
{
unsigned char V_4 = 0 ;
if ( V_20 -> V_112 == 0 )
return;
if ( V_20 -> V_63 == V_64 )
V_4 = V_65 ;
F_43 ( V_14 , V_136 , V_20 -> V_72 , V_20 -> V_71 ,
V_20 -> V_140 , V_20 -> V_112 , V_4 ) ;
}
static T_6 void F_45 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_97 * V_20 )
{
unsigned char V_4 = 0 ;
if ( V_20 -> V_112 == 0 )
return;
if ( V_20 -> V_63 == V_64 )
V_4 = V_65 ;
F_43 ( V_14 , V_136 , V_20 -> V_116 , V_20 -> V_116 ,
0 , V_20 -> V_112 , V_4 ) ;
}
static T_6 void F_46 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_66 * V_142 )
{
struct V_68 V_69 , * V_20 = & V_69 ;
T_4 V_70 ;
unsigned char V_4 = 0 ;
V_70 = F_21 ( V_142 , V_20 ) ;
if ( F_31 ( V_70 ) ) {
F_8 ( & V_14 -> V_14 , L_20 ,
V_142 -> type ) ;
return;
}
if ( V_20 -> V_112 == 0 )
return;
if ( V_20 -> V_75 == V_76 ) {
if ( V_20 -> V_77 . V_78 . V_63 == V_64 )
V_4 = V_65 ;
F_43 ( V_14 , V_136 , V_20 -> V_72 ,
V_20 -> V_72 , 0 , V_20 -> V_112 ,
V_4 ) ;
} else if ( V_20 -> V_75 == V_79 )
F_40 ( V_14 , V_136 , V_20 -> V_72 ,
V_20 -> V_72 , 0 , V_20 -> V_112 ,
V_141 ) ;
}
static T_6 void F_47 ( struct V_13 * V_14 ,
unsigned int V_136 ,
struct V_66 * V_142 )
{
struct V_83 * V_20 = & V_142 -> V_59 . V_84 ;
unsigned char V_4 = 0 ;
if ( V_20 -> V_112 == 0 )
return;
if ( V_20 -> V_75 == V_76 ) {
if ( V_20 -> V_77 . V_78 . V_63 == V_64 )
V_4 = V_65 ;
F_43 ( V_14 , V_136 , V_20 -> V_72 ,
V_20 -> V_72 , 0 , V_20 -> V_112 ,
V_4 ) ;
} else if ( V_20 -> V_75 == V_79 )
F_40 ( V_14 , V_136 , V_20 -> V_72 ,
V_20 -> V_72 , 0 , V_20 -> V_112 ,
V_141 ) ;
}
static T_6 T_4 F_48 ( struct V_66 * V_67 ,
void * V_59 )
{
int V_143 ;
struct V_144 * V_145 = V_59 ;
struct V_13 * V_14 = V_145 -> V_14 ;
unsigned int V_136 = V_145 -> V_136 ;
switch ( V_67 -> type ) {
case V_102 :
F_34 ( V_14 , V_136 , & V_67 -> V_59 . V_19 ) ;
break;
case V_108 :
F_32 ( V_14 , V_136 , & V_67 -> V_59 . V_87 ) ;
break;
case V_113 :
switch ( V_67 -> V_59 . V_146 . V_147 ) {
case V_148 :
V_143 = V_149 ;
break;
case V_150 :
V_143 = V_151 ;
break;
case V_152 :
V_143 = V_153 ;
break;
default:
V_143 = V_154 ;
break;
}
V_145 -> V_136 = F_49 ( V_14 , V_143 ) ;
break;
case V_114 :
V_145 -> V_136 = 0 ;
break;
case V_111 :
F_39 ( V_14 , V_136 , & V_67 -> V_59 . V_89 ) ;
break;
case V_115 :
F_41 ( V_14 , V_136 ,
& V_67 -> V_59 . V_91 ) ;
break;
case V_117 :
case V_118 :
break;
case V_119 :
F_42 ( V_14 , V_136 ,
& V_67 -> V_59 . V_94 ) ;
break;
case V_120 :
F_44 ( V_14 , V_136 ,
& V_67 -> V_59 . V_96 ) ;
break;
case V_121 :
F_45 ( V_14 , V_136 ,
& V_67 -> V_59 . V_98 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
F_46 ( V_14 , V_136 , V_67 ) ;
break;
case V_125 :
F_47 ( V_14 , V_136 , V_67 ) ;
break;
case V_126 :
F_38 ( V_14 , V_136 ,
& V_67 -> V_59 . V_100 ) ;
break;
case V_127 :
break;
default:
F_8 ( & V_14 -> V_14 , L_21 ,
V_67 -> type ) ;
return V_128 ;
}
return V_129 ;
}
int T_6 F_50 ( struct V_13 * V_14 )
{
struct V_130 * V_131 = V_14 -> V_59 ;
T_5 V_132 = V_131 -> V_132 ;
T_4 V_70 ;
struct V_144 V_145 ;
F_28 ( & V_14 -> V_14 , L_22 ) ;
V_145 . V_14 = V_14 ;
V_145 . V_136 = 0 ;
V_70 = F_30 ( V_132 , V_155 ,
F_48 , & V_145 ) ;
if ( F_31 ( V_70 ) ) {
if ( V_70 != V_134 )
F_3 ( & V_14 -> V_14 , L_23 , V_70 ) ;
return - V_135 ;
}
return 0 ;
}
static int F_51 ( struct V_66 * V_67 )
{
switch ( V_67 -> type ) {
case V_102 :
case V_108 :
case V_111 :
case V_115 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
return 1 ;
}
return 0 ;
}
static T_4 F_52 ( struct V_66 * V_67 ,
void * V_59 )
{
int * V_156 = V_59 ;
if ( F_51 ( V_67 ) )
( * V_156 ) ++ ;
return V_129 ;
}
static T_4 F_53 ( struct V_66 * V_67 , void * V_59 )
{
struct V_66 * * V_157 = V_59 ;
if ( F_51 ( V_67 ) ) {
( * V_157 ) -> type = V_67 -> type ;
( * V_157 ) -> V_61 = sizeof( struct V_66 ) ;
if ( V_67 -> type == V_102 )
( * V_157 ) -> V_59 . V_19 . V_158 =
V_67 -> V_59 . V_19 . V_158 ;
( * V_157 ) ++ ;
}
return V_129 ;
}
int F_54 ( struct V_13 * V_14 ,
struct V_159 * V_160 )
{
struct V_130 * V_131 = V_14 -> V_59 ;
T_5 V_132 = V_131 -> V_132 ;
struct V_66 * V_157 ;
int V_156 = 0 ;
T_4 V_70 ;
V_70 = F_30 ( V_132 , V_133 ,
F_52 , & V_156 ) ;
if ( F_31 ( V_70 ) ) {
F_3 ( & V_14 -> V_14 , L_24 , V_70 ) ;
return - V_161 ;
}
if ( ! V_156 )
return - V_161 ;
V_160 -> V_61 = sizeof( struct V_66 ) * ( V_156 + 1 ) + 1 ;
V_160 -> V_162 = F_55 ( V_160 -> V_61 - 1 , V_163 ) ;
if ( ! V_160 -> V_162 )
return - V_164 ;
V_157 = (struct V_66 * ) V_160 -> V_162 ;
V_70 = F_30 ( V_132 , V_133 ,
F_53 , & V_157 ) ;
if ( F_31 ( V_70 ) ) {
F_56 ( V_160 -> V_162 ) ;
F_3 ( & V_14 -> V_14 , L_24 , V_70 ) ;
return - V_161 ;
}
V_157 -> type = V_118 ;
return 0 ;
}
static void F_57 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_85 * V_19 = & V_157 -> V_59 . V_19 ;
int V_1 , V_2 , V_3 ;
if ( ! F_58 ( V_20 ) ) {
V_19 -> V_103 = 0 ;
F_28 ( & V_14 -> V_14 , L_25 ,
V_20 ? L_26 : L_27 ) ;
return;
}
F_2 ( V_14 , V_20 -> V_4 , & V_1 , & V_2 , & V_3 ) ;
V_19 -> V_1 = V_1 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_105 = V_3 ;
V_19 -> V_103 = 1 ;
V_19 -> V_104 [ 0 ] = V_20 -> V_40 ;
F_28 ( & V_14 -> V_14 , L_28 ,
( int ) V_20 -> V_40 ,
V_1 == V_5 ? L_4 : L_3 ,
V_2 == V_6 ? L_5 : L_6 ,
V_19 -> V_105 == V_11 ? L_29 : L_30 ,
V_19 -> V_158 ) ;
}
static void F_59 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_99 * V_100 = & V_157 -> V_59 . V_100 ;
int V_1 , V_2 , V_3 ;
if ( ! F_58 ( V_20 ) ) {
V_100 -> V_103 = 0 ;
F_28 ( & V_14 -> V_14 , L_31 ,
V_20 ? L_26 : L_27 ) ;
return;
}
F_2 ( V_14 , V_20 -> V_4 , & V_1 , & V_2 , & V_3 ) ;
V_100 -> V_73 = V_165 ;
V_100 -> V_1 = V_1 ;
V_100 -> V_2 = V_2 ;
V_100 -> V_105 = V_3 ;
V_100 -> V_103 = 1 ;
V_100 -> V_104 [ 0 ] = V_20 -> V_40 ;
F_28 ( & V_14 -> V_14 , L_32 , ( int ) V_20 -> V_40 ,
V_1 == V_5 ? L_4 : L_3 ,
V_2 == V_6 ? L_5 : L_6 ,
V_100 -> V_105 == V_11 ? L_29 : L_30 ) ;
}
static void F_60 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_86 * V_87 = & V_157 -> V_59 . V_87 ;
if ( ! F_58 ( V_20 ) ) {
V_87 -> V_109 = 0 ;
F_28 ( & V_14 -> V_14 , L_33 ,
V_20 ? L_26 : L_27 ) ;
return;
}
switch ( V_20 -> V_4 & V_166 ) {
case V_29 :
V_87 -> type = V_28 ;
break;
case V_31 :
V_87 -> type = V_30 ;
break;
case V_33 :
V_87 -> type = V_32 ;
break;
default:
V_87 -> type = V_26 ;
}
switch ( V_20 -> V_4 & V_167 ) {
case V_35 :
V_87 -> V_24 = V_34 ;
break;
case V_37 :
V_87 -> V_24 = V_36 ;
break;
default:
V_87 -> V_24 = V_38 ;
}
V_87 -> V_23 = ! ! ( V_20 -> V_4 & V_25 ) ;
V_87 -> V_109 = 1 ;
V_87 -> V_110 [ 0 ] = V_20 -> V_40 ;
F_28 ( & V_14 -> V_14 , L_34
L_35 ,
( int ) V_20 -> V_40 , V_87 -> type , V_87 -> V_24 , V_87 -> V_23 ) ;
}
static void F_61 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_88 * V_89 = & V_157 -> V_59 . V_89 ;
if ( F_58 ( V_20 ) ) {
V_89 -> V_42 = ( V_20 -> V_4 & V_46 ) ?
V_45 : V_81 ;
V_89 -> V_72 = V_20 -> V_40 ;
V_89 -> V_71 = V_20 -> V_44 ;
V_89 -> V_140 = 0 ;
V_89 -> V_112 = V_20 -> V_44 - V_20 -> V_40 + 1 ;
} else {
V_89 -> V_72 = 0 ;
V_89 -> V_112 = 0 ;
}
F_28 ( & V_14 -> V_14 , L_36 , V_89 -> V_72 ,
V_89 -> V_72 + V_89 -> V_112 - 1 , V_89 -> V_42 ) ;
}
static void F_62 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_90 * V_91 = & V_157 -> V_59 . V_91 ;
if ( F_58 ( V_20 ) ) {
V_91 -> V_116 = V_20 -> V_40 ;
V_91 -> V_112 = V_20 -> V_44 - V_20 -> V_40 + 1 ;
} else {
V_91 -> V_116 = 0 ;
V_91 -> V_112 = 0 ;
}
F_28 ( & V_14 -> V_14 , L_37 , V_91 -> V_116 ,
V_91 -> V_116 + V_91 -> V_112 - 1 ) ;
}
static void F_63 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_93 * V_94 = & V_157 -> V_59 . V_94 ;
if ( F_58 ( V_20 ) ) {
V_94 -> V_63 = V_20 -> V_4 & V_65 ?
V_64 : V_168 ;
V_94 -> V_72 = V_20 -> V_40 ;
V_94 -> V_71 = V_20 -> V_44 ;
V_94 -> V_140 = 0 ;
V_94 -> V_112 = V_20 -> V_44 - V_20 -> V_40 + 1 ;
} else {
V_94 -> V_72 = 0 ;
V_94 -> V_112 = 0 ;
}
F_28 ( & V_14 -> V_14 , L_38 ,
V_94 -> V_72 ,
V_94 -> V_72 + V_94 -> V_112 - 1 ,
V_94 -> V_63 ) ;
}
static void F_64 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_95 * V_96 = & V_157 -> V_59 . V_96 ;
if ( F_58 ( V_20 ) ) {
V_96 -> V_63 = V_20 -> V_4 & V_65 ?
V_64 : V_168 ;
V_96 -> V_72 = V_20 -> V_40 ;
V_96 -> V_71 = V_20 -> V_44 ;
V_96 -> V_140 = 0 ;
V_96 -> V_112 = V_20 -> V_44 - V_20 -> V_40 + 1 ;
} else {
V_96 -> V_72 = 0 ;
V_96 -> V_140 = 0 ;
}
F_28 ( & V_14 -> V_14 , L_39 ,
V_96 -> V_72 ,
V_96 -> V_72 + V_96 -> V_112 - 1 ,
V_96 -> V_63 ) ;
}
static void F_65 ( struct V_13 * V_14 ,
struct V_66 * V_157 ,
struct V_157 * V_20 )
{
struct V_97 * V_98 = & V_157 -> V_59 . V_98 ;
if ( F_58 ( V_20 ) ) {
V_98 -> V_63 =
V_20 -> V_4 & V_65 ?
V_64 : V_168 ;
V_98 -> V_116 = V_20 -> V_40 ;
V_98 -> V_112 = V_20 -> V_44 - V_20 -> V_40 + 1 ;
} else {
V_98 -> V_116 = 0 ;
V_98 -> V_112 = 0 ;
}
F_28 ( & V_14 -> V_14 , L_40 ,
V_98 -> V_116 ,
V_98 -> V_116 + V_98 -> V_112 - 1 ,
V_98 -> V_63 ) ;
}
int F_66 ( struct V_13 * V_14 , struct V_159 * V_160 )
{
int V_101 = 0 ;
int V_156 = ( V_160 -> V_61 - 1 ) / sizeof( struct V_66 ) - 1 ;
struct V_66 * V_157 = V_160 -> V_162 ;
int V_169 = 0 , V_19 = 0 , V_87 = 0 , V_78 = 0 ;
F_28 ( & V_14 -> V_14 , L_41 , V_156 ) ;
while ( V_101 < V_156 ) {
switch ( V_157 -> type ) {
case V_102 :
F_57 ( V_14 , V_157 ,
F_67 ( V_14 , V_170 , V_19 ) ) ;
V_19 ++ ;
break;
case V_108 :
F_60 ( V_14 , V_157 ,
F_67 ( V_14 , V_171 , V_87 ) ) ;
V_87 ++ ;
break;
case V_111 :
F_61 ( V_14 , V_157 ,
F_67 ( V_14 , V_172 , V_169 ) ) ;
V_169 ++ ;
break;
case V_115 :
F_62 ( V_14 , V_157 ,
F_67 ( V_14 , V_172 , V_169 ) ) ;
V_169 ++ ;
break;
case V_119 :
F_63 ( V_14 , V_157 ,
F_67 ( V_14 , V_173 , V_78 ) ) ;
V_78 ++ ;
break;
case V_120 :
F_64 ( V_14 , V_157 ,
F_67 ( V_14 , V_173 , V_78 ) ) ;
V_78 ++ ;
break;
case V_121 :
F_65 ( V_14 , V_157 ,
F_67 ( V_14 , V_173 , V_78 ) ) ;
V_78 ++ ;
break;
case V_126 :
F_59 ( V_14 , V_157 ,
F_67 ( V_14 , V_170 , V_19 ) ) ;
V_19 ++ ;
break;
case V_113 :
case V_114 :
case V_117 :
case V_118 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_127 :
default:
F_8 ( & V_14 -> V_14 , L_42
L_43 , V_157 -> type ) ;
return - V_161 ;
}
V_157 ++ ;
V_101 ++ ;
}
return 0 ;
}
