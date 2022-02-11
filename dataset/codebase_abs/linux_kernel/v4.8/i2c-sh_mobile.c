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
* V_60 = F_24 ( V_2 -> V_58 ) ;
break;
default:
* V_60 = V_2 -> V_58 -> V_60 [ V_2 -> V_57 ] ;
}
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( V_2 -> V_57 == V_2 -> V_58 -> V_59 ) {
if ( V_2 -> V_49 && V_2 -> V_61 )
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
static int F_26 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
int V_62 ;
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
V_62 = V_2 -> V_57 - 2 ;
if ( V_2 -> V_57 == V_2 -> V_58 -> V_59 ) {
if ( V_2 -> V_61 ) {
F_18 ( V_2 , V_53 , 0 ) ;
V_2 -> V_57 ++ ;
break;
}
if ( V_62 < 0 ) {
F_18 ( V_2 , V_53 , 0 ) ;
break;
}
V_4 = F_18 ( V_2 , V_56 , 0 ) ;
} else
V_4 = F_18 ( V_2 , V_52 , 0 ) ;
if ( V_62 >= 0 )
V_2 -> V_58 -> V_60 [ V_62 ] = V_4 ;
} while ( 0 );
V_2 -> V_57 ++ ;
return V_2 -> V_57 == ( V_2 -> V_58 -> V_59 + 2 ) ;
}
static T_3 F_27 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
unsigned char V_65 ;
int V_66 = 0 ;
V_65 = F_3 ( V_2 , V_33 ) ;
V_2 -> V_65 |= V_65 ;
F_13 ( V_2 -> V_21 , L_6 , V_65 , V_2 -> V_65 ,
( V_2 -> V_58 -> V_25 & V_67 ) ? L_7 : L_8 ,
V_2 -> V_57 , V_2 -> V_58 -> V_59 ) ;
if ( V_2 -> V_68 == V_69 && V_2 -> V_57 == 0 )
F_5 ( V_2 , V_5 , V_70 , 0 ) ;
else if ( V_65 & ( V_71 | V_72 ) )
F_1 ( V_2 , V_33 , V_65 & ~ ( V_71 | V_72 ) ) ;
else if ( V_2 -> V_58 -> V_25 & V_67 )
V_66 = F_26 ( V_2 ) ;
else
V_66 = F_25 ( V_2 ) ;
if ( V_2 -> V_68 == V_73 && V_2 -> V_57 == 1 )
F_5 ( V_2 , V_5 , V_74 , 0 ) ;
if ( V_65 & V_75 )
F_1 ( V_2 , V_33 , V_65 & ~ V_75 ) ;
if ( V_66 ) {
V_2 -> V_65 |= V_76 ;
F_28 ( & V_2 -> V_77 ) ;
}
F_3 ( V_2 , V_33 ) ;
return V_78 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_68 == V_73
? V_2 -> V_81 : V_2 -> V_82 ;
F_30 ( V_80 -> V_83 -> V_21 , F_31 ( & V_2 -> V_84 ) ,
V_2 -> V_58 -> V_59 , V_2 -> V_68 ) ;
V_2 -> V_68 = V_85 ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 == V_85 )
return;
else if ( V_2 -> V_68 == V_73 )
F_33 ( V_2 -> V_81 ) ;
else if ( V_2 -> V_68 == V_69 )
F_33 ( V_2 -> V_82 ) ;
F_29 ( V_2 ) ;
}
static void F_34 ( void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_29 ( V_2 ) ;
V_2 -> V_57 = V_2 -> V_58 -> V_59 ;
V_2 -> V_61 = true ;
F_5 ( V_2 , V_5 , 0 , V_70 | V_74 ) ;
}
static struct V_79 * F_35 ( struct V_83 * V_21 ,
enum V_86 V_87 , T_4 V_88 )
{
struct V_79 * V_80 ;
struct V_89 V_90 ;
char * V_91 = V_87 == V_92 ? L_9 : L_10 ;
int V_36 ;
V_80 = F_36 ( V_21 , V_91 ) ;
if ( F_37 ( V_80 ) ) {
V_36 = F_38 ( V_80 ) ;
F_13 ( V_21 , L_11 , V_91 , V_36 ) ;
return V_80 ;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_93 = V_87 ;
if ( V_87 == V_92 ) {
V_90 . V_94 = V_88 ;
V_90 . V_95 = V_96 ;
} else {
V_90 . V_97 = V_88 ;
V_90 . V_98 = V_96 ;
}
V_36 = F_39 ( V_80 , & V_90 ) ;
if ( V_36 ) {
F_13 ( V_21 , L_12 , V_91 , V_36 ) ;
F_40 ( V_80 ) ;
return F_41 ( V_36 ) ;
}
F_13 ( V_21 , L_13 , V_91 ) ;
return V_80 ;
}
static void F_42 ( struct V_1 * V_2 )
{
bool V_99 = V_2 -> V_58 -> V_25 & V_67 ;
enum V_100 V_87 = V_99 ? V_73 : V_69 ;
struct V_79 * V_80 = V_99 ? V_2 -> V_81 : V_2 -> V_82 ;
struct V_101 * V_102 ;
T_4 V_103 ;
T_5 V_104 ;
if ( F_38 ( V_80 ) == - V_105 ) {
if ( V_99 )
V_80 = V_2 -> V_81 = F_35 ( V_2 -> V_21 , V_106 ,
V_2 -> V_107 -> V_108 + V_45 ) ;
else
V_80 = V_2 -> V_82 = F_35 ( V_2 -> V_21 , V_92 ,
V_2 -> V_107 -> V_108 + V_45 ) ;
}
if ( F_37 ( V_80 ) )
return;
V_103 = F_43 ( V_80 -> V_83 -> V_21 , V_2 -> V_58 -> V_60 , V_2 -> V_58 -> V_59 , V_87 ) ;
if ( F_44 ( V_80 -> V_83 -> V_21 , V_103 ) ) {
F_13 ( V_2 -> V_21 , L_14 ) ;
return;
}
F_45 ( & V_2 -> V_84 ) = V_2 -> V_58 -> V_59 ;
F_31 ( & V_2 -> V_84 ) = V_103 ;
V_2 -> V_68 = V_87 ;
V_102 = F_46 ( V_80 , & V_2 -> V_84 , 1 ,
V_99 ? V_106 : V_92 ,
V_109 | V_110 ) ;
if ( ! V_102 ) {
F_13 ( V_2 -> V_21 , L_15 ) ;
F_32 ( V_2 ) ;
return;
}
V_102 -> V_111 = F_34 ;
V_102 -> V_112 = V_2 ;
V_104 = F_47 ( V_102 ) ;
if ( F_48 ( V_104 ) ) {
F_13 ( V_2 -> V_21 , L_16 ) ;
F_32 ( V_2 ) ;
return;
}
F_49 ( V_80 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_113 * V_114 ,
bool V_115 )
{
if ( V_114 -> V_59 == 0 && ( V_114 -> V_25 & V_67 ) ) {
F_12 ( V_2 -> V_21 , L_17 ) ;
return - V_116 ;
}
if ( V_115 ) {
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_24 & 0xff ) ;
}
V_2 -> V_58 = V_114 ;
V_2 -> V_57 = - 1 ;
V_2 -> V_65 = 0 ;
if ( V_2 -> V_58 -> V_59 > 8 )
F_42 ( V_2 ) ;
F_1 ( V_2 , V_5 , V_54 | V_42 | V_43 | V_44 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_117 ;
for ( V_117 = 1000 ; V_117 ; V_117 -- ) {
T_6 V_118 = F_3 ( V_2 , V_33 ) ;
if ( V_118 & V_119 )
break;
if ( V_118 & V_72 )
return - V_120 ;
F_52 ( 10 ) ;
}
return V_117 ? 0 : - V_121 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_117 ;
for ( V_117 = 1000 ; V_117 ; V_117 -- ) {
T_6 V_118 = F_3 ( V_2 , V_33 ) ;
F_13 ( V_2 -> V_21 , L_18 , V_118 , V_2 -> V_65 ) ;
if ( ! ( V_118 & V_122 ) ) {
V_118 |= V_2 -> V_65 ;
if ( V_118 & V_72 )
return - V_120 ;
if ( V_118 & V_71 )
return - V_123 ;
break;
}
F_52 ( 10 ) ;
}
return V_117 ? 0 : - V_121 ;
}
static int F_54 ( struct V_124 * V_125 ,
struct V_113 * V_126 ,
int V_127 )
{
struct V_1 * V_2 = F_55 ( V_125 ) ;
struct V_113 * V_58 ;
int V_128 = 0 ;
int V_117 ;
long V_129 ;
F_14 ( V_2 ) ;
for ( V_117 = 0 ; V_117 < V_127 ; V_117 ++ ) {
bool V_130 = V_2 -> V_49 || ! V_117 ;
V_58 = & V_126 [ V_117 ] ;
V_2 -> V_49 = V_117 == V_127 - 1 || V_58 -> V_25 & V_131 ;
V_2 -> V_61 = false ;
V_128 = F_50 ( V_2 , V_58 , V_130 ) ;
if ( V_128 )
break;
if ( V_130 )
F_18 ( V_2 , V_38 , 0 ) ;
V_129 = F_56 ( V_2 -> V_77 ,
V_2 -> V_65 & ( V_72 | V_76 ) ,
V_125 -> V_129 ) ;
if ( ! V_129 ) {
F_12 ( V_2 -> V_21 , L_19 ) ;
if ( V_2 -> V_68 != V_85 )
F_32 ( V_2 ) ;
V_128 = - V_121 ;
break;
}
if ( V_2 -> V_49 )
V_128 = F_53 ( V_2 ) ;
else
V_128 = F_51 ( V_2 ) ;
if ( V_128 < 0 )
break;
}
F_16 ( V_2 ) ;
if ( ! V_128 )
V_128 = V_127 ;
return V_128 ;
}
static T_1 F_57 ( struct V_124 * V_125 )
{
return V_132 | V_133 | V_134 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_3 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_135 , V_136 , 0 ) ;
F_3 ( V_2 , V_135 ) ;
F_52 ( 10 ) ;
F_1 ( V_2 , V_29 , V_51 ) ;
F_1 ( V_2 , V_135 , 0 ) ;
F_52 ( 10 ) ;
F_1 ( V_2 , V_29 , V_39 ) ;
F_52 ( 10 ) ;
F_1 ( V_2 , V_29 , 0 ) ;
F_52 ( 10 ) ;
F_1 ( V_2 , V_29 , V_39 ) ;
F_52 ( 10 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! F_37 ( V_2 -> V_82 ) ) {
F_40 ( V_2 -> V_82 ) ;
V_2 -> V_82 = F_41 ( - V_105 ) ;
}
if ( ! F_37 ( V_2 -> V_81 ) ) {
F_40 ( V_2 -> V_81 ) ;
V_2 -> V_81 = F_41 ( - V_105 ) ;
}
}
static int F_60 ( struct V_137 * V_21 , struct V_1 * V_2 )
{
struct V_138 * V_107 ;
T_7 V_139 ;
int V_140 = 0 , V_36 ;
while ( ( V_107 = F_61 ( V_21 , V_141 , V_140 ) ) ) {
for ( V_139 = V_107 -> V_108 ; V_139 <= V_107 -> V_142 ; V_139 ++ ) {
V_36 = F_62 ( & V_21 -> V_21 , V_139 , F_27 ,
0 , F_63 ( & V_21 -> V_21 ) , V_2 ) ;
if ( V_36 ) {
F_12 ( & V_21 -> V_21 , L_20 , & V_139 ) ;
return V_36 ;
}
}
V_140 ++ ;
}
return V_140 > 0 ? 0 : - V_143 ;
}
static int F_64 ( struct V_137 * V_21 )
{
struct V_144 * V_145 = F_65 ( & V_21 -> V_21 ) ;
struct V_1 * V_2 ;
struct V_124 * V_146 ;
struct V_138 * V_107 ;
int V_36 ;
T_1 V_18 ;
V_2 = F_66 ( & V_21 -> V_21 , sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_2 )
return - V_148 ;
V_2 -> V_16 = F_67 ( & V_21 -> V_21 , NULL ) ;
if ( F_37 ( V_2 -> V_16 ) ) {
F_12 ( & V_21 -> V_21 , L_21 ) ;
return F_38 ( V_2 -> V_16 ) ;
}
V_36 = F_60 ( V_21 , V_2 ) ;
if ( V_36 )
return V_36 ;
V_2 -> V_21 = & V_21 -> V_21 ;
F_68 ( V_21 , V_2 ) ;
V_107 = F_61 ( V_21 , V_149 , 0 ) ;
V_2 -> V_107 = V_107 ;
V_2 -> V_7 = F_69 ( & V_21 -> V_21 , V_107 ) ;
if ( F_37 ( V_2 -> V_7 ) )
return F_38 ( V_2 -> V_7 ) ;
V_36 = F_70 ( V_21 -> V_21 . V_150 , L_22 , & V_18 ) ;
V_2 -> V_18 = V_36 ? V_19 : V_18 ;
V_2 -> V_17 = 1 ;
if ( V_21 -> V_21 . V_150 ) {
const struct V_151 * V_152 ;
V_152 = F_71 ( V_153 , & V_21 -> V_21 ) ;
if ( V_152 ) {
const struct V_154 * V_155 ;
V_155 = V_152 -> V_4 ;
V_2 -> V_17 = V_155 -> V_17 ;
if ( V_155 -> V_156 )
V_155 -> V_156 ( V_2 ) ;
}
} else {
if ( V_145 && V_145 -> V_18 )
V_2 -> V_18 = V_145 -> V_18 ;
if ( V_145 && V_145 -> V_17 )
V_2 -> V_17 = V_145 -> V_17 ;
}
if ( F_72 ( V_107 ) > 0x17 )
V_2 -> V_25 |= V_26 ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_73 ( & V_2 -> V_84 , 1 ) ;
V_2 -> V_68 = V_85 ;
V_2 -> V_81 = V_2 -> V_82 = F_41 ( - V_105 ) ;
F_74 ( & V_21 -> V_21 , true ) ;
F_75 ( & V_21 -> V_21 ) ;
V_146 = & V_2 -> V_146 ;
F_76 ( V_146 , V_2 ) ;
V_146 -> V_157 = V_158 ;
V_146 -> V_159 = & V_160 ;
V_146 -> V_21 . V_161 = & V_21 -> V_21 ;
V_146 -> V_162 = 5 ;
V_146 -> V_163 = V_21 -> V_164 ;
V_146 -> V_21 . V_150 = V_21 -> V_21 . V_150 ;
F_77 ( V_146 -> V_165 , V_21 -> V_165 , sizeof( V_146 -> V_165 ) ) ;
F_78 ( & V_2 -> V_37 ) ;
F_79 ( & V_2 -> V_77 ) ;
V_36 = F_80 ( V_146 ) ;
if ( V_36 < 0 ) {
F_59 ( V_2 ) ;
F_12 ( & V_21 -> V_21 , L_23 ) ;
return V_36 ;
}
F_81 ( & V_21 -> V_21 , L_24 , V_146 -> V_163 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_82 ( struct V_137 * V_21 )
{
struct V_1 * V_2 = F_83 ( V_21 ) ;
F_84 ( & V_2 -> V_146 ) ;
F_59 ( V_2 ) ;
F_85 ( & V_21 -> V_21 ) ;
return 0 ;
}
static int F_86 ( struct V_83 * V_21 )
{
return 0 ;
}
static int T_8 F_87 ( void )
{
return F_88 ( & V_166 ) ;
}
static void T_9 F_89 ( void )
{
F_90 ( & V_166 ) ;
}
