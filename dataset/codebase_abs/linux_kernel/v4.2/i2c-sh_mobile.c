static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned char V_4 )
{
if ( V_3 == V_5 )
V_4 |= V_2 -> V_6 ;
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static unsigned char F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_7 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_8 , unsigned char V_9 )
{
F_1 ( V_2 , V_3 , ( F_3 ( V_2 , V_3 ) | V_8 ) & ~ V_9 ) ;
}
static T_1 F_6 ( unsigned long V_10 , T_1 V_11 , T_1 V_12 )
{
return ( ( ( V_10 * ( V_11 + V_12 ) ) + 5000 ) / 10000 ) ;
}
static T_1 F_7 ( unsigned long V_10 , T_1 V_13 , T_1 V_12 )
{
return ( ( ( V_10 * ( V_13 + V_12 ) ) + 5000 ) / 10000 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
T_1 V_13 , V_11 , V_12 ;
T_2 V_15 ;
F_9 ( V_2 -> V_16 ) ;
V_14 = F_10 ( V_2 -> V_16 ) / 1000 ;
F_11 ( V_2 -> V_16 ) ;
V_14 /= V_2 -> V_17 ;
if ( V_2 -> V_18 == V_19 ) {
V_11 = 47 ;
V_13 = 40 ;
V_12 = 3 ;
} else if ( V_2 -> V_18 == V_20 ) {
V_11 = 13 ;
V_13 = 6 ;
V_12 = 3 ;
} else {
F_12 ( V_2 -> V_21 , L_1 ,
V_2 -> V_18 ) ;
return - V_22 ;
}
V_2 -> V_23 = F_6 ( V_14 , V_11 , V_12 ) ;
V_2 -> V_24 = F_7 ( V_14 , V_13 , V_12 ) ;
V_15 = V_2 -> V_25 & V_26 ? 0x1ff : 0xff ;
if ( V_2 -> V_23 > V_15 || V_2 -> V_24 > V_15 ) {
F_12 ( V_2 -> V_21 , L_2 ,
V_2 -> V_23 , V_2 -> V_24 ) ;
return - V_22 ;
}
if ( V_2 -> V_23 & 0x100 )
V_2 -> V_6 |= V_27 ;
else
V_2 -> V_6 &= ~ V_27 ;
if ( V_2 -> V_24 & 0x100 )
V_2 -> V_6 |= V_28 ;
else
V_2 -> V_6 &= ~ V_28 ;
F_13 ( V_2 -> V_21 , L_3 , V_2 -> V_23 , V_2 -> V_24 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_21 ) ;
F_9 ( V_2 -> V_16 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_24 & 0xff ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_33 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_11 ( V_2 -> V_16 ) ;
F_17 ( V_2 -> V_21 ) ;
}
static unsigned char F_18 ( struct V_1 * V_2 ,
enum V_34 V_35 , unsigned char V_4 )
{
unsigned char V_36 = 0 ;
unsigned long V_25 ;
F_13 ( V_2 -> V_21 , L_4 , V_35 , V_4 ) ;
F_19 ( & V_2 -> V_37 , V_25 ) ;
switch ( V_35 ) {
case V_38 :
F_1 ( V_2 , V_29 , V_30 | V_39 | V_40 ) ;
break;
case V_41 :
F_1 ( V_2 , V_5 , V_42 | V_43 | V_44 ) ;
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_46 :
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_47 :
F_1 ( V_2 , V_45 , V_4 ) ;
case V_48 :
F_1 ( V_2 , V_29 , V_2 -> V_49 ? V_30 | V_39
: V_30 | V_39 | V_40 ) ;
break;
case V_50 :
F_1 ( V_2 , V_29 , V_30 | V_51 ) ;
break;
case V_52 :
V_36 = F_3 ( V_2 , V_45 ) ;
break;
case V_53 :
F_1 ( V_2 , V_5 ,
V_54 | V_42 | V_43 | V_44 ) ;
F_1 ( V_2 , V_29 , V_30 | V_55 ) ;
break;
case V_56 :
F_1 ( V_2 , V_5 ,
V_54 | V_42 | V_43 | V_44 ) ;
V_36 = F_3 ( V_2 , V_45 ) ;
F_1 ( V_2 , V_29 , V_30 | V_55 ) ;
break;
}
F_20 ( & V_2 -> V_37 , V_25 ) ;
F_13 ( V_2 -> V_21 , L_5 , V_35 , V_36 ) ;
return V_36 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
return V_2 -> V_57 == - 1 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_57 == V_2 -> V_58 -> V_59 - 1 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned char * V_60 )
{
switch ( V_2 -> V_57 ) {
case - 1 :
* V_60 = ( V_2 -> V_58 -> V_61 & 0x7f ) << 1 ;
* V_60 |= ( V_2 -> V_58 -> V_25 & V_62 ) ? 1 : 0 ;
break;
default:
* V_60 = V_2 -> V_58 -> V_60 [ V_2 -> V_57 ] ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( V_2 -> V_57 == V_2 -> V_58 -> V_59 ) {
if ( V_2 -> V_49 && V_2 -> V_63 )
F_18 ( V_2 , V_48 , 0 ) ;
return 1 ;
}
F_23 ( V_2 , & V_4 ) ;
if ( F_22 ( V_2 ) )
F_18 ( V_2 , V_47 , V_4 ) ;
else if ( F_21 ( V_2 ) )
F_18 ( V_2 , V_41 , V_4 ) ;
else
F_18 ( V_2 , V_46 , V_4 ) ;
V_2 -> V_57 ++ ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
int V_64 ;
do {
if ( V_2 -> V_57 <= - 1 ) {
F_23 ( V_2 , & V_4 ) ;
if ( F_21 ( V_2 ) )
F_18 ( V_2 , V_41 , V_4 ) ;
else
F_18 ( V_2 , V_46 , V_4 ) ;
break;
}
if ( V_2 -> V_57 == 0 ) {
F_18 ( V_2 , V_50 , 0 ) ;
break;
}
V_64 = V_2 -> V_57 - 2 ;
if ( V_2 -> V_57 == V_2 -> V_58 -> V_59 ) {
if ( V_2 -> V_63 ) {
F_18 ( V_2 , V_53 , 0 ) ;
V_2 -> V_57 ++ ;
break;
}
if ( V_64 < 0 ) {
F_18 ( V_2 , V_53 , 0 ) ;
break;
}
V_4 = F_18 ( V_2 , V_56 , 0 ) ;
} else
V_4 = F_18 ( V_2 , V_52 , 0 ) ;
if ( V_64 >= 0 )
V_2 -> V_58 -> V_60 [ V_64 ] = V_4 ;
} while ( 0 );
V_2 -> V_57 ++ ;
return V_2 -> V_57 == ( V_2 -> V_58 -> V_59 + 2 ) ;
}
static T_3 F_26 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned char V_67 ;
int V_68 = 0 ;
V_67 = F_3 ( V_2 , V_33 ) ;
V_2 -> V_67 |= V_67 ;
F_13 ( V_2 -> V_21 , L_6 , V_67 , V_2 -> V_67 ,
( V_2 -> V_58 -> V_25 & V_62 ) ? L_7 : L_8 ,
V_2 -> V_57 , V_2 -> V_58 -> V_59 ) ;
if ( V_2 -> V_69 == V_70 && V_2 -> V_57 == 0 )
F_5 ( V_2 , V_5 , V_71 , 0 ) ;
else if ( V_67 & ( V_72 | V_73 ) )
F_1 ( V_2 , V_33 , V_67 & ~ ( V_72 | V_73 ) ) ;
else if ( V_2 -> V_58 -> V_25 & V_62 )
V_68 = F_25 ( V_2 ) ;
else
V_68 = F_24 ( V_2 ) ;
if ( V_2 -> V_69 == V_74 && V_2 -> V_57 == 1 )
F_5 ( V_2 , V_5 , V_75 , 0 ) ;
if ( V_67 & V_76 )
F_1 ( V_2 , V_33 , V_67 & ~ V_76 ) ;
if ( V_68 ) {
V_2 -> V_67 |= V_77 ;
F_27 ( & V_2 -> V_78 ) ;
}
F_3 ( V_2 , V_33 ) ;
return V_79 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_69 == V_74
? V_2 -> V_82 : V_2 -> V_83 ;
F_29 ( V_81 -> V_84 -> V_21 , F_30 ( & V_2 -> V_85 ) ,
V_2 -> V_58 -> V_59 , V_2 -> V_69 ) ;
V_2 -> V_69 = V_86 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 == V_86 )
return;
else if ( V_2 -> V_69 == V_74 )
F_32 ( V_2 -> V_82 ) ;
else if ( V_2 -> V_69 == V_70 )
F_32 ( V_2 -> V_83 ) ;
F_28 ( V_2 ) ;
}
static void F_33 ( void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_28 ( V_2 ) ;
V_2 -> V_57 = V_2 -> V_58 -> V_59 ;
V_2 -> V_63 = true ;
F_5 ( V_2 , V_5 , 0 , V_71 | V_75 ) ;
}
static struct V_80 * F_34 ( struct V_84 * V_21 ,
enum V_87 V_88 , T_4 V_89 )
{
struct V_80 * V_81 ;
struct V_90 V_91 ;
char * V_92 = V_88 == V_93 ? L_9 : L_10 ;
int V_36 ;
V_81 = F_35 ( V_21 , V_92 ) ;
if ( F_36 ( V_81 ) ) {
V_36 = F_37 ( V_81 ) ;
F_13 ( V_21 , L_11 , V_92 , V_36 ) ;
return V_81 ;
}
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_94 = V_88 ;
if ( V_88 == V_93 ) {
V_91 . V_95 = V_89 ;
V_91 . V_96 = V_97 ;
} else {
V_91 . V_98 = V_89 ;
V_91 . V_99 = V_97 ;
}
V_36 = F_38 ( V_81 , & V_91 ) ;
if ( V_36 ) {
F_13 ( V_21 , L_12 , V_92 , V_36 ) ;
F_39 ( V_81 ) ;
return F_40 ( V_36 ) ;
}
F_13 ( V_21 , L_13 , V_92 ) ;
return V_81 ;
}
static void F_41 ( struct V_1 * V_2 )
{
bool V_100 = V_2 -> V_58 -> V_25 & V_62 ;
enum V_101 V_88 = V_100 ? V_74 : V_70 ;
struct V_80 * V_81 = V_100 ? V_2 -> V_82 : V_2 -> V_83 ;
struct V_102 * V_103 ;
T_4 V_104 ;
T_5 V_105 ;
if ( F_37 ( V_81 ) == - V_106 ) {
if ( V_100 )
V_81 = V_2 -> V_82 = F_34 ( V_2 -> V_21 , V_107 ,
V_2 -> V_108 -> V_109 + V_45 ) ;
else
V_81 = V_2 -> V_83 = F_34 ( V_2 -> V_21 , V_93 ,
V_2 -> V_108 -> V_109 + V_45 ) ;
}
if ( F_36 ( V_81 ) )
return;
V_104 = F_42 ( V_81 -> V_84 -> V_21 , V_2 -> V_58 -> V_60 , V_2 -> V_58 -> V_59 , V_88 ) ;
if ( F_43 ( V_2 -> V_21 , V_104 ) ) {
F_13 ( V_2 -> V_21 , L_14 ) ;
return;
}
F_44 ( & V_2 -> V_85 ) = V_2 -> V_58 -> V_59 ;
F_30 ( & V_2 -> V_85 ) = V_104 ;
V_2 -> V_69 = V_88 ;
V_103 = F_45 ( V_81 , & V_2 -> V_85 , 1 ,
V_100 ? V_107 : V_93 ,
V_110 | V_111 ) ;
if ( ! V_103 ) {
F_13 ( V_2 -> V_21 , L_15 ) ;
F_31 ( V_2 ) ;
return;
}
V_103 -> V_112 = F_33 ;
V_103 -> V_113 = V_2 ;
V_105 = F_46 ( V_103 ) ;
if ( F_47 ( V_105 ) ) {
F_13 ( V_2 -> V_21 , L_16 ) ;
F_31 ( V_2 ) ;
return;
}
F_48 ( V_81 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_114 * V_115 ,
bool V_116 )
{
if ( V_115 -> V_59 == 0 && ( V_115 -> V_25 & V_62 ) ) {
F_12 ( V_2 -> V_21 , L_17 ) ;
return - V_117 ;
}
if ( V_116 ) {
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_24 & 0xff ) ;
}
V_2 -> V_58 = V_115 ;
V_2 -> V_57 = - 1 ;
V_2 -> V_67 = 0 ;
if ( V_2 -> V_58 -> V_59 > 8 )
F_41 ( V_2 ) ;
F_1 ( V_2 , V_5 , V_54 | V_42 | V_43 | V_44 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_118 ;
for ( V_118 = 1000 ; V_118 ; V_118 -- ) {
T_6 V_119 = F_3 ( V_2 , V_33 ) ;
if ( V_119 & V_120 )
break;
if ( V_119 & V_73 )
return - V_121 ;
F_51 ( 10 ) ;
}
return V_118 ? 0 : - V_122 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_118 ;
for ( V_118 = 1000 ; V_118 ; V_118 -- ) {
T_6 V_119 = F_3 ( V_2 , V_33 ) ;
F_13 ( V_2 -> V_21 , L_18 , V_119 , V_2 -> V_67 ) ;
if ( ! ( V_119 & V_123 ) ) {
V_119 |= V_2 -> V_67 ;
if ( V_119 & V_73 )
return - V_121 ;
if ( V_119 & V_72 )
return - V_124 ;
break;
}
F_51 ( 10 ) ;
}
return V_118 ? 0 : - V_122 ;
}
static int F_53 ( struct V_125 * V_126 ,
struct V_114 * V_127 ,
int V_128 )
{
struct V_1 * V_2 = F_54 ( V_126 ) ;
struct V_114 * V_58 ;
int V_129 = 0 ;
int V_118 ;
long V_130 ;
F_14 ( V_2 ) ;
for ( V_118 = 0 ; V_118 < V_128 ; V_118 ++ ) {
bool V_131 = V_2 -> V_49 || ! V_118 ;
V_58 = & V_127 [ V_118 ] ;
V_2 -> V_49 = V_118 == V_128 - 1 || V_58 -> V_25 & V_132 ;
V_2 -> V_63 = false ;
V_129 = F_49 ( V_2 , V_58 , V_131 ) ;
if ( V_129 )
break;
if ( V_131 )
F_18 ( V_2 , V_38 , 0 ) ;
V_130 = F_55 ( V_2 -> V_78 ,
V_2 -> V_67 & ( V_73 | V_77 ) ,
V_126 -> V_130 ) ;
if ( ! V_130 ) {
F_12 ( V_2 -> V_21 , L_19 ) ;
if ( V_2 -> V_69 != V_86 )
F_31 ( V_2 ) ;
V_129 = - V_122 ;
break;
}
if ( V_2 -> V_49 )
V_129 = F_52 ( V_2 ) ;
else
V_129 = F_50 ( V_2 ) ;
if ( V_129 < 0 )
break;
}
F_16 ( V_2 ) ;
if ( ! V_129 )
V_129 = V_128 ;
return V_129 ;
}
static T_1 F_56 ( struct V_125 * V_126 )
{
return V_133 | V_134 | V_135 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_3 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_136 , V_137 , 0 ) ;
F_3 ( V_2 , V_136 ) ;
F_51 ( 10 ) ;
F_1 ( V_2 , V_29 , V_51 ) ;
F_1 ( V_2 , V_136 , 0 ) ;
F_51 ( 10 ) ;
F_1 ( V_2 , V_29 , V_39 ) ;
F_51 ( 10 ) ;
F_1 ( V_2 , V_29 , 0 ) ;
F_51 ( 10 ) ;
F_1 ( V_2 , V_29 , V_39 ) ;
F_51 ( 10 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! F_36 ( V_2 -> V_83 ) ) {
F_39 ( V_2 -> V_83 ) ;
V_2 -> V_83 = F_40 ( - V_106 ) ;
}
if ( ! F_36 ( V_2 -> V_82 ) ) {
F_39 ( V_2 -> V_82 ) ;
V_2 -> V_82 = F_40 ( - V_106 ) ;
}
}
static int F_59 ( struct V_138 * V_21 , struct V_1 * V_2 )
{
struct V_139 * V_108 ;
T_7 V_140 ;
int V_141 = 0 , V_36 ;
while ( ( V_108 = F_60 ( V_21 , V_142 , V_141 ) ) ) {
for ( V_140 = V_108 -> V_109 ; V_140 <= V_108 -> V_143 ; V_140 ++ ) {
V_36 = F_61 ( & V_21 -> V_21 , V_140 , F_26 ,
0 , F_62 ( & V_21 -> V_21 ) , V_2 ) ;
if ( V_36 ) {
F_12 ( & V_21 -> V_21 , L_20 , & V_140 ) ;
return V_36 ;
}
}
V_141 ++ ;
}
return V_141 > 0 ? 0 : - V_144 ;
}
static int F_63 ( struct V_138 * V_21 )
{
struct V_145 * V_146 = F_64 ( & V_21 -> V_21 ) ;
struct V_1 * V_2 ;
struct V_125 * V_147 ;
struct V_139 * V_108 ;
int V_36 ;
T_1 V_18 ;
V_2 = F_65 ( & V_21 -> V_21 , sizeof( struct V_1 ) , V_148 ) ;
if ( ! V_2 )
return - V_149 ;
V_2 -> V_16 = F_66 ( & V_21 -> V_21 , NULL ) ;
if ( F_36 ( V_2 -> V_16 ) ) {
F_12 ( & V_21 -> V_21 , L_21 ) ;
return F_37 ( V_2 -> V_16 ) ;
}
V_36 = F_59 ( V_21 , V_2 ) ;
if ( V_36 )
return V_36 ;
V_2 -> V_21 = & V_21 -> V_21 ;
F_67 ( V_21 , V_2 ) ;
V_108 = F_60 ( V_21 , V_150 , 0 ) ;
V_2 -> V_108 = V_108 ;
V_2 -> V_7 = F_68 ( & V_21 -> V_21 , V_108 ) ;
if ( F_36 ( V_2 -> V_7 ) )
return F_37 ( V_2 -> V_7 ) ;
V_36 = F_69 ( V_21 -> V_21 . V_151 , L_22 , & V_18 ) ;
V_2 -> V_18 = V_36 ? V_19 : V_18 ;
V_2 -> V_17 = 1 ;
if ( V_21 -> V_21 . V_151 ) {
const struct V_152 * V_153 ;
V_153 = F_70 ( V_154 , & V_21 -> V_21 ) ;
if ( V_153 ) {
const struct V_155 * V_156 ;
V_156 = V_153 -> V_4 ;
V_2 -> V_17 = V_156 -> V_17 ;
if ( V_156 -> V_157 )
V_156 -> V_157 ( V_2 ) ;
}
} else {
if ( V_146 && V_146 -> V_18 )
V_2 -> V_18 = V_146 -> V_18 ;
if ( V_146 && V_146 -> V_17 )
V_2 -> V_17 = V_146 -> V_17 ;
}
if ( F_71 ( V_108 ) > 0x17 )
V_2 -> V_25 |= V_26 ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_72 ( & V_2 -> V_85 , 1 ) ;
V_2 -> V_69 = V_86 ;
V_2 -> V_82 = V_2 -> V_83 = F_40 ( - V_106 ) ;
F_73 ( & V_21 -> V_21 , true ) ;
F_74 ( & V_21 -> V_21 ) ;
V_147 = & V_2 -> V_147 ;
F_75 ( V_147 , V_2 ) ;
V_147 -> V_158 = V_159 ;
V_147 -> V_160 = & V_161 ;
V_147 -> V_21 . V_162 = & V_21 -> V_21 ;
V_147 -> V_163 = 5 ;
V_147 -> V_164 = V_21 -> V_165 ;
V_147 -> V_21 . V_151 = V_21 -> V_21 . V_151 ;
F_76 ( V_147 -> V_166 , V_21 -> V_166 , sizeof( V_147 -> V_166 ) ) ;
F_77 ( & V_2 -> V_37 ) ;
F_78 ( & V_2 -> V_78 ) ;
V_36 = F_79 ( V_147 ) ;
if ( V_36 < 0 ) {
F_58 ( V_2 ) ;
F_12 ( & V_21 -> V_21 , L_23 ) ;
return V_36 ;
}
F_80 ( & V_21 -> V_21 , L_24 , V_147 -> V_164 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_81 ( struct V_138 * V_21 )
{
struct V_1 * V_2 = F_82 ( V_21 ) ;
F_83 ( & V_2 -> V_147 ) ;
F_58 ( V_2 ) ;
F_84 ( & V_21 -> V_21 ) ;
return 0 ;
}
static int F_85 ( struct V_84 * V_21 )
{
return 0 ;
}
static int T_8 F_86 ( void )
{
return F_87 ( & V_167 ) ;
}
static void T_9 F_88 ( void )
{
F_89 ( & V_167 ) ;
}
