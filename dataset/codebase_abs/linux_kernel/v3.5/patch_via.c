static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return NULL ;
F_3 ( & V_4 -> V_6 ) ;
V_3 -> V_4 = V_4 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_7 = F_4 ( V_3 ) ;
if ( V_4 -> V_7 == V_8 )
V_4 -> V_7 = V_9 ;
return V_4 ;
}
static enum V_10 F_4 ( struct V_2 * V_3 )
{
T_1 V_11 = V_3 -> V_11 ;
T_2 V_12 = V_11 >> 16 ;
T_2 V_13 = V_11 & 0xffff ;
enum V_10 V_7 ;
if ( V_12 != 0x1106 )
V_7 = V_14 ;
else if ( V_13 >= 0x1708 && V_13 <= 0x170b )
V_7 = V_15 ;
else if ( V_13 >= 0xe710 && V_13 <= 0xe713 )
V_7 = V_16 ;
else if ( V_13 >= 0xe714 && V_13 <= 0xe717 )
V_7 = V_17 ;
else if ( V_13 >= 0xe720 && V_13 <= 0xe723 ) {
V_7 = V_18 ;
if ( F_5 ( V_3 , 0x16 , V_19 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_13 >= 0xe724 && V_13 <= 0xe727 )
V_7 = V_20 ;
else if ( ( V_13 & 0xfff ) == 0x397
&& ( V_13 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_13 & 0xfff ) == 0x398
&& ( V_13 >> 12 ) < 8 )
V_7 = V_21 ;
else if ( ( V_13 & 0xfff ) == 0x428
&& ( V_13 >> 12 ) < 8 )
V_7 = V_22 ;
else if ( V_13 == 0x0433 || V_13 == 0xa721 )
V_7 = V_23 ;
else if ( V_13 == 0x0441 || V_13 == 0x4441 )
V_7 = V_22 ;
else if ( V_13 == 0x0438 || V_13 == 0x4438 )
V_7 = V_24 ;
else if ( V_13 == 0x0448 )
V_7 = V_25 ;
else if ( V_13 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_13 & 0xfff ) == 0x446 )
V_7 = V_26 ;
else
V_7 = V_14 ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_4 )
{
if ( V_4 -> V_7 != V_15 || V_4 -> V_27 . V_28 [ 0 ] == 0 )
return;
if ( V_4 -> V_29 ) {
F_7 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
F_8 ( & V_4 -> V_30 ) ;
V_4 -> V_29 = 0 ;
}
}
static void F_9 ( struct V_1 * V_4 )
{
if ( V_4 -> V_7 != V_15 || V_4 -> V_27 . V_28 [ 0 ] == 0 )
return;
if ( V_4 -> V_31 &&
( V_4 -> V_32 || F_10 ( V_4 -> V_3 ) ) ) {
if ( ! V_4 -> V_29 ) {
F_7 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( & V_4 -> V_30 ,
F_12 ( 100 ) ) ;
V_4 -> V_29 = 1 ;
}
} else if ( ! F_10 ( V_4 -> V_3 ) )
F_6 ( V_4 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> F_13 )
V_4 -> F_13 ( V_3 ) ;
}
static int F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_37 = F_15 ( V_34 , V_36 ) ;
struct V_2 * V_3 = F_16 ( V_34 ) ;
F_13 ( V_3 ) ;
F_17 ( F_16 ( V_34 ) ) ;
F_9 ( V_3 -> V_4 ) ;
return V_37 ;
}
static struct V_38 * F_18 ( struct V_1 * V_4 ,
const struct V_38 * V_39 ,
const char * V_40 )
{
struct V_38 * V_41 ;
F_19 ( & V_4 -> V_42 , sizeof( * V_41 ) , 32 ) ;
V_41 = F_20 ( & V_4 -> V_42 ) ;
if ( ! V_41 )
return NULL ;
* V_41 = * V_39 ;
if ( ! V_40 )
V_40 = V_39 -> V_40 ;
if ( V_40 ) {
V_41 -> V_40 = F_21 ( V_40 , V_5 ) ;
if ( ! V_41 -> V_40 )
return NULL ;
}
return V_41 ;
}
static int F_22 ( struct V_1 * V_4 , int type , const char * V_40 ,
int V_43 , unsigned long V_44 )
{
struct V_38 * V_41 ;
V_41 = F_18 ( V_4 , & V_45 [ type ] , V_40 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_47 = V_43 ;
if ( F_23 ( V_44 ) )
V_41 -> V_48 = V_49 ;
V_41 -> V_50 = V_44 ;
return 0 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_42 . V_51 ) {
struct V_38 * V_52 = V_4 -> V_42 . V_51 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_42 . V_54 ; V_53 ++ )
F_25 ( V_52 [ V_53 ] . V_40 ) ;
}
F_26 ( & V_4 -> V_42 ) ;
}
static int F_27 ( struct V_1 * V_4 , const char * V_55 ,
int V_56 , int V_43 , int V_57 )
{
char V_40 [ 32 ] ;
int V_58 ;
sprintf ( V_40 , L_1 , V_55 ) ;
V_58 = F_22 ( V_4 , V_59 , V_40 , V_56 ,
F_28 ( V_57 , 3 , V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
sprintf ( V_40 , L_2 , V_55 ) ;
V_58 = F_22 ( V_4 , V_61 , V_40 , V_56 ,
F_28 ( V_57 , 3 , V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static bool F_29 ( struct V_2 * V_3 , T_3 V_62 , int V_63 ,
unsigned int V_64 )
{
unsigned int V_65 ;
if ( ! V_62 )
return false ;
V_65 = F_30 ( V_3 , V_62 ) ;
if ( V_63 == V_60 )
V_65 &= V_66 ;
else
V_65 &= V_67 ;
if ( ! V_65 )
return false ;
if ( F_31 ( V_3 , V_62 , V_63 ) & V_64 )
return true ;
return false ;
}
static void F_32 ( struct V_2 * V_3 , struct V_68 * V_69 ,
T_3 V_57 , int V_43 , bool V_70 )
{
int V_53 , V_71 , V_44 ;
if ( ! V_69 )
return;
V_71 = F_33 ( V_3 , V_57 ) ;
for ( V_53 = 0 ; V_53 < V_71 ; V_53 ++ ) {
if ( V_53 == V_43 )
V_44 = F_34 ( V_53 ) ;
else
V_44 = F_35 ( V_53 ) ;
F_7 ( V_3 , V_57 , 0 ,
V_72 , V_44 ) ;
}
}
static void F_36 ( struct V_2 * V_3 , struct V_68 * V_69 ,
bool V_70 , bool V_73 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_69 -> V_74 ; V_53 ++ ) {
T_3 V_75 , V_76 ;
int V_43 = V_69 -> V_43 [ V_53 ] ;
V_75 = V_69 -> V_69 [ V_53 ] ;
if ( V_53 < V_69 -> V_74 - 1 )
V_76 = V_69 -> V_69 [ V_53 + 1 ] ;
else
V_76 = 0 ;
if ( V_70 && V_69 -> V_77 [ V_53 ] )
F_7 ( V_3 , V_76 , 0 ,
V_78 , V_43 ) ;
if ( ! V_73 && ( V_76 == V_4 -> V_79 ) )
continue;
if ( F_37 ( V_3 , V_76 , V_60 ) )
F_32 ( V_3 , V_69 , V_76 , V_43 , V_70 ) ;
if ( ! V_73 && ( V_75 == V_69 -> V_80 || V_75 == V_69 -> V_81 ) )
continue;
if ( F_37 ( V_3 , V_75 , V_82 ) ) {
int V_44 = V_70 ? V_83 : V_84 ;
F_7 ( V_3 , V_75 , 0 ,
V_72 , V_44 ) ;
}
}
}
static void F_38 ( struct V_2 * V_3 , T_3 V_85 ,
int V_86 )
{
if ( ! V_85 )
return;
F_39 ( V_3 , V_85 , V_86 ) ;
if ( F_40 ( V_3 , V_85 ) & V_87 )
F_7 ( V_3 , V_85 , 0 ,
V_88 , 0x02 ) ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_68 * V_69 , int V_86 )
{
unsigned int V_65 ;
T_3 V_85 ;
if ( ! V_69 -> V_74 )
return;
V_85 = V_69 -> V_69 [ V_69 -> V_74 - 1 ] ;
F_38 ( V_3 , V_85 , V_86 ) ;
if ( F_30 ( V_3 , V_85 ) & V_67 )
V_65 = F_31 ( V_3 , V_85 , V_82 ) ;
else
V_65 = 0 ;
if ( V_65 & V_89 ) {
unsigned int V_44 ;
V_44 = ( V_65 & V_90 ) >> V_91 ;
F_7 ( V_3 , V_85 , 0 , V_72 ,
V_84 | V_44 ) ;
}
F_36 ( V_3 , V_69 , true , true ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_27 . V_92 + V_4 -> V_93 ; V_53 ++ ) {
V_69 = & V_4 -> V_94 [ V_53 ] ;
if ( ! V_53 && V_4 -> V_95 && V_4 -> V_96 . V_74 )
V_69 = & V_4 -> V_96 ;
F_41 ( V_3 , V_69 , V_97 ) ;
}
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_98 = V_4 -> V_99 ;
if ( V_4 -> V_100 ) {
F_36 ( V_3 , & V_4 -> V_101 , false , false ) ;
F_36 ( V_3 , & V_4 -> V_102 , false , false ) ;
if ( V_98 )
F_36 ( V_3 , & V_4 -> V_94 [ V_98 ] ,
false , false ) ;
} else if ( V_4 -> V_95 || ! V_4 -> V_101 . V_74 ) {
F_36 ( V_3 , & V_4 -> V_103 , false , false ) ;
F_36 ( V_3 , & V_4 -> V_101 , false , false ) ;
} else {
F_36 ( V_3 , & V_4 -> V_103 , false , false ) ;
F_36 ( V_3 , & V_4 -> V_102 , false , false ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_101 . V_74 ) {
F_41 ( V_3 , & V_4 -> V_102 , V_104 ) ;
return;
}
F_43 ( V_3 ) ;
if ( V_4 -> V_100 )
F_41 ( V_3 , & V_4 -> V_103 , V_104 ) ;
else if ( V_4 -> V_95 )
F_41 ( V_3 , & V_4 -> V_102 , V_104 ) ;
else
F_41 ( V_3 , & V_4 -> V_101 , V_104 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_105 )
return;
if ( ! V_4 -> V_106 . V_74 ) {
F_41 ( V_3 , & V_4 -> V_107 , V_97 ) ;
return;
}
if ( ! V_4 -> V_95 ) {
F_36 ( V_3 , & V_4 -> V_107 ,
false , false ) ;
F_41 ( V_3 , & V_4 -> V_106 , V_97 ) ;
} else {
F_36 ( V_3 , & V_4 -> V_106 , false , false ) ;
F_41 ( V_3 , & V_4 -> V_107 , V_97 ) ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_108 * V_109 = & V_4 -> V_27 ;
T_3 V_110 [ V_111 ] ;
unsigned int V_112 ;
int V_53 , V_113 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_114 ; V_53 ++ ) {
T_3 V_62 = V_4 -> V_115 [ V_53 ] ;
if ( ! ( F_30 ( V_3 , V_62 ) & V_66 ) ||
! ( F_31 ( V_3 , V_62 , V_60 ) & V_89 ) )
continue;
F_7 ( V_3 , V_4 -> V_115 [ V_53 ] , 0 ,
V_72 ,
F_34 ( 0 ) ) ;
}
for ( V_53 = 0 ; V_53 < V_109 -> V_116 ; V_53 ++ ) {
T_3 V_62 = V_109 -> V_117 [ V_53 ] . V_85 ;
if ( V_4 -> V_118 && F_47 ( V_3 , V_62 ) )
V_112 = V_97 ;
else {
V_112 = V_119 ;
if ( V_109 -> V_117 [ V_53 ] . type == V_120 )
V_112 |= F_48 ( V_3 , V_62 ) ;
}
F_39 ( V_3 , V_62 , V_112 ) ;
}
for ( V_53 = 0 ; V_53 < V_4 -> V_114 ; V_53 ++ ) {
int V_121 = V_4 -> V_117 [ V_4 -> V_122 [ V_53 ] ] . V_121 ;
if ( V_53 > 0 && ! V_4 -> V_123 [ V_53 ] )
break;
if ( V_4 -> V_123 [ V_121 ] ) {
int V_124 = V_4 -> V_117 [ V_4 -> V_122 [ V_53 ] ] . V_124 ;
F_7 ( V_3 , V_4 -> V_123 [ V_121 ] , 0 ,
V_78 ,
V_124 ) ;
}
if ( V_4 -> V_125 )
break;
}
if ( ! V_4 -> V_79 )
return;
V_113 = F_49 ( V_3 , V_4 -> V_79 , V_110 ,
F_50 ( V_110 ) ) ;
for ( V_53 = 0 ; V_53 < V_113 ; V_53 ++ ) {
unsigned int V_65 = F_30 ( V_3 , V_110 [ V_53 ] ) ;
if ( F_51 ( V_65 ) == V_126 )
F_7 ( V_3 , V_4 -> V_79 , 0 ,
V_72 ,
F_35 ( V_53 ) ) ;
}
}
static void F_52 ( struct V_2 * V_3 , T_3 V_62 ,
unsigned int V_127 )
{
if ( F_53 ( V_3 , V_62 , 0 ,
V_128 , 0 ) == V_127 )
return;
F_7 ( V_3 , V_62 , 0 , V_129 , V_127 ) ;
}
static void F_54 ( struct V_2 * V_3 , T_3 V_62 ,
unsigned int * V_130 )
{
unsigned V_127 ;
unsigned V_131 = F_55 ( V_3 , V_62 ) ;
unsigned V_132 = ( V_131 & V_133 )
>> V_134
& V_135 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_136 = 0 ;
V_132 |= V_4 -> V_137 ;
if ( ! V_132 )
V_136 = F_56 ( V_3 , V_62 ) ;
if ( ( V_4 -> V_118 && F_47 ( V_3 , V_62 ) )
|| ( ( V_132 || V_136 )
&& F_57 ( V_131 ) != V_138 ) ) {
* V_130 = V_139 ;
V_127 = V_139 ;
} else
V_127 = V_140 ;
F_52 ( V_3 , V_62 , V_127 ) ;
}
static int F_58 ( struct V_33 * V_34 ,
struct V_141 * V_142 )
{
static const char * const V_143 [] = {
L_3 , L_4
} ;
V_142 -> type = V_144 ;
V_142 -> V_145 = 1 ;
V_142 -> V_146 . V_147 . V_148 = 2 ;
if ( V_142 -> V_146 . V_147 . V_149 >= V_142 -> V_146 . V_147 . V_148 )
V_142 -> V_146 . V_147 . V_149 = V_142 -> V_146 . V_147 . V_148 - 1 ;
strcpy ( V_142 -> V_146 . V_147 . V_40 ,
V_143 [ V_142 -> V_146 . V_147 . V_149 ] ) ;
return 0 ;
}
static int F_59 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_146 . V_147 . V_149 [ 0 ] = ! V_4 -> V_137 ;
return 0 ;
}
static int F_60 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = ! V_36 -> V_146 . V_147 . V_149 [ 0 ] ;
if ( V_44 == V_4 -> V_137 )
return 0 ;
V_4 -> V_137 = V_44 ;
F_13 ( V_3 ) ;
F_17 ( V_3 ) ;
return 1 ;
}
static int F_61 ( struct V_33 * V_34 ,
struct V_141 * V_142 )
{
static const char * const V_143 [] = { L_5 , L_6 } ;
V_142 -> type = V_144 ;
V_142 -> V_145 = 1 ;
V_142 -> V_146 . V_147 . V_148 = 2 ;
if ( V_142 -> V_146 . V_147 . V_149 >= 2 )
V_142 -> V_146 . V_147 . V_149 = 1 ;
strcpy ( V_142 -> V_146 . V_147 . V_40 ,
V_143 [ V_142 -> V_146 . V_147 . V_149 ] ) ;
return 0 ;
}
static int F_62 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_146 . V_147 . V_149 [ 0 ] = V_4 -> V_100 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_4 )
{
const struct V_108 * V_109 = & V_4 -> V_27 ;
V_4 -> V_150 . V_151 = V_109 -> V_92 + V_4 -> V_93 ;
V_4 -> V_150 . V_152 = 0 ;
if ( ! V_4 -> V_100 ) {
if ( ! V_4 -> V_99 )
V_4 -> V_150 . V_152 = V_4 -> V_153 ;
} else {
if ( V_4 -> V_99 )
V_4 -> V_150 . V_151 = V_109 -> V_92 - 1 ;
}
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_98 = V_4 -> V_99 ;
T_3 V_154 , V_155 ;
if ( ! V_4 -> V_156 )
return;
V_154 = V_98 ? V_4 -> V_150 . V_157 [ V_98 ] : 0 ;
V_155 = V_4 -> V_153 ;
if ( V_4 -> V_100 ) {
if ( V_4 -> V_32 & V_158 ) {
F_65 ( V_3 , V_155 , 1 ) ;
F_65 ( V_3 , V_154 , 1 ) ;
}
if ( V_4 -> V_32 & V_159 )
F_66 ( V_3 , V_155 ,
V_4 -> V_160 , 0 ,
V_4 -> V_161 ) ;
} else {
if ( V_4 -> V_32 & V_159 )
F_65 ( V_3 , V_155 , 1 ) ;
if ( V_4 -> V_32 & V_158 ) {
T_3 V_162 ;
int V_163 ;
if ( V_154 ) {
V_162 = V_154 ;
V_163 = V_98 * 2 ;
} else {
V_162 = V_155 ;
V_163 = 0 ;
}
F_66 ( V_3 , V_162 ,
V_4 -> V_164 , V_163 ,
V_4 -> V_165 ) ;
}
}
F_63 ( V_4 ) ;
}
static int F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_166 , V_98 ;
F_68 ( & V_4 -> V_6 ) ;
V_166 = ! ! V_36 -> V_146 . V_147 . V_149 [ 0 ] ;
if ( V_4 -> V_100 == V_166 ) {
F_69 ( & V_4 -> V_6 ) ;
return 0 ;
}
V_4 -> V_100 = V_166 ;
V_98 = V_4 -> V_99 ;
F_43 ( V_3 ) ;
if ( V_166 )
F_36 ( V_3 , & V_4 -> V_103 , true , false ) ;
else {
if ( V_98 )
F_36 ( V_3 , & V_4 -> V_94 [ V_98 ] ,
true , false ) ;
if ( V_4 -> V_95 || ! V_4 -> V_101 . V_74 )
F_36 ( V_3 , & V_4 -> V_102 ,
true , false ) ;
else
F_36 ( V_3 , & V_4 -> V_101 ,
true , false ) ;
}
F_64 ( V_3 ) ;
F_69 ( & V_4 -> V_6 ) ;
F_13 ( V_3 ) ;
F_70 ( V_3 ) ;
return 1 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
T_3 V_62 ;
V_62 = V_4 -> V_27 . V_28 [ 0 ] ;
V_41 = F_72 ( V_4 , & V_167 ) ;
if ( V_41 == NULL )
return - V_46 ;
V_41 -> V_48 = V_168 | V_62 ;
return 0 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_93 ; V_53 ++ ) {
struct V_33 * V_112 ;
struct V_169 V_170 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_171 = V_172 ;
sprintf ( V_170 . V_40 , L_1 , V_4 -> V_173 [ V_53 ] ) ;
V_112 = F_74 ( V_3 , V_170 . V_40 ) ;
if ( V_112 )
F_75 ( V_3 -> V_174 -> V_175 ,
V_176 ,
& V_112 -> V_170 ) ;
}
}
static void F_76 ( struct V_2 * V_3 , int V_177 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 = V_177 ? V_178 : V_179 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_93 ; V_53 ++ ) {
if ( V_4 -> V_180 [ V_53 ] < 0 )
continue;
F_77 ( V_3 , V_4 -> V_79 ,
V_60 , V_4 -> V_180 [ V_53 ] ,
V_178 , V_44 ) ;
}
}
static bool F_47 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_93 ; V_53 ++ )
if ( V_4 -> V_181 [ V_53 ] == V_85 )
return true ;
return false ;
}
static int F_78 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
* V_36 -> V_146 . integer . V_146 = V_4 -> V_118 ;
return 0 ;
}
static int F_79 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_182 = * V_36 -> V_146 . integer . V_146
? V_183 : V_184 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_93 ; V_53 ++ ) {
T_3 V_62 = V_4 -> V_181 [ V_53 ] ;
unsigned int V_127 ;
V_127 = F_53 ( V_3 , V_62 , 0 ,
V_185 , 0 ) ;
V_127 &= ~ ( V_184 | V_183 ) ;
V_127 |= V_182 ;
F_39 ( V_3 , V_62 , V_127 ) ;
if ( V_182 == V_183 ) {
F_76 ( V_3 , 1 ) ;
F_73 ( V_3 ) ;
}
}
V_4 -> V_118 = * V_36 -> V_146 . integer . V_146 ;
F_13 ( V_3 ) ;
return 1 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_93 )
return 0 ;
if ( ! F_72 ( V_4 , & V_186 ) )
return - V_46 ;
return 0 ;
}
static bool F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_187 * V_188 ;
int V_53 , V_163 , V_189 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_190 ; V_53 ++ ) {
V_188 = & V_4 -> V_191 [ V_53 ] ;
for ( V_163 = 0 ; V_163 < 2 ; V_163 ++ ) {
V_189 = F_82 ( V_3 , V_188 -> V_62 , V_163 , V_188 -> V_63 ,
V_188 -> V_43 ) ;
if ( ! ( V_189 & V_178 ) && V_189 > 0 )
return false ;
}
}
return true ;
}
static void F_83 ( struct V_2 * V_3 , bool V_73 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_70 ;
unsigned int V_192 , V_127 ;
if ( V_4 -> V_137 )
V_70 = false ;
else
V_70 = F_81 ( V_3 ) && ! V_4 -> V_156 ;
if ( V_70 == V_4 -> V_193 && ! V_73 )
return;
V_4 -> V_193 = V_70 ;
switch ( V_4 -> V_7 ) {
case V_18 :
case V_20 :
V_192 = 0xf70 ;
V_127 = V_70 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_22 :
case V_23 :
V_192 = 0xf73 ;
V_127 = V_70 ? 0x51 : 0xe1 ;
break;
case V_21 :
V_192 = 0xf73 ;
V_127 = V_70 ? 0x01 : 0x1d ;
break;
case V_24 :
case V_25 :
case V_26 :
V_192 = 0xf93 ;
V_127 = V_70 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_194 , 0 , V_192 , V_127 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
return F_83 ( V_3 , false ) ;
}
static void F_84 ( struct V_2 * V_3 , int V_195 , bool V_196 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_196 )
V_4 -> V_156 |= V_195 ;
else
V_4 -> V_156 &= ~ V_195 ;
F_17 ( V_3 ) ;
}
static int F_85 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_108 * V_109 = & V_4 -> V_27 ;
int V_58 ;
V_4 -> V_150 . V_151 = V_109 -> V_92 + V_4 -> V_93 ;
V_4 -> V_150 . V_201 = V_4 -> V_150 . V_151 * 2 ;
F_84 ( V_3 , V_158 , true ) ;
V_58 = F_86 ( V_3 , & V_4 -> V_150 , V_200 ,
V_198 ) ;
if ( V_58 < 0 ) {
F_84 ( V_3 , V_158 , false ) ;
return V_58 ;
}
return 0 ;
}
static int F_87 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
F_84 ( V_3 , V_158 , false ) ;
return 0 ;
}
static int F_88 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_89 ( ! V_4 -> V_153 ) )
return - V_202 ;
F_84 ( V_3 , V_159 , true ) ;
return 0 ;
}
static int F_90 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
F_84 ( V_3 , V_159 , false ) ;
return 0 ;
}
static int F_91 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_68 ( & V_4 -> V_6 ) ;
F_63 ( V_4 ) ;
F_92 ( V_3 , & V_4 -> V_150 , V_203 ,
V_204 , V_200 ) ;
V_4 -> V_32 |= V_158 ;
V_4 -> V_164 = V_203 ;
V_4 -> V_165 = V_204 ;
F_69 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_93 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_68 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_100 )
F_66 ( V_3 , V_4 -> V_153 ,
V_203 , 0 , V_204 ) ;
V_4 -> V_32 |= V_159 ;
V_4 -> V_160 = V_203 ;
V_4 -> V_161 = V_204 ;
F_69 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_68 ( & V_4 -> V_6 ) ;
F_95 ( V_3 , & V_4 -> V_150 ) ;
V_4 -> V_32 &= ~ V_158 ;
F_69 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_96 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_68 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_100 )
F_66 ( V_3 , V_4 -> V_153 , 0 , 0 , 0 ) ;
V_4 -> V_32 &= ~ V_159 ;
F_69 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_97 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_98 ( V_3 , & V_4 -> V_150 ) ;
}
static int F_99 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_100 ( V_3 , & V_4 -> V_150 ) ;
}
static int F_101 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_102 ( V_3 , & V_4 -> V_150 ,
V_203 , V_204 , V_200 ) ;
}
static int F_103 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_104 ( V_3 , & V_4 -> V_150 ) ;
return 0 ;
}
static int F_105 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( V_3 , V_4 -> V_115 [ V_200 -> V_205 ] ,
V_203 , 0 , V_204 ) ;
return 0 ;
}
static int F_106 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_107 ( V_3 , V_4 -> V_115 [ V_200 -> V_205 ] ) ;
return 0 ;
}
static int F_108 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_121 = V_4 -> V_117 [ V_4 -> V_122 [ 0 ] ] . V_121 ;
F_68 ( & V_4 -> V_6 ) ;
V_4 -> V_206 = V_4 -> V_115 [ V_121 ] ;
V_4 -> V_207 = V_203 ;
V_4 -> V_208 = V_204 ;
F_66 ( V_3 , V_4 -> V_206 , V_203 , 0 , V_204 ) ;
F_69 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_109 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_68 ( & V_4 -> V_6 ) ;
F_107 ( V_3 , V_4 -> V_206 ) ;
V_4 -> V_206 = 0 ;
F_69 ( & V_4 -> V_6 ) ;
return 0 ;
}
static bool F_110 ( struct V_2 * V_3 , int V_166 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_121 = V_4 -> V_117 [ V_166 ] . V_121 ;
T_3 V_209 = V_4 -> V_115 [ V_121 ] ;
bool V_210 = false ;
F_68 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_206 && V_4 -> V_206 != V_209 ) {
F_65 ( V_3 , V_4 -> V_206 , 1 ) ;
V_4 -> V_206 = V_209 ;
F_66 ( V_3 , V_209 ,
V_4 -> V_207 , 0 ,
V_4 -> V_208 ) ;
V_210 = true ;
}
F_69 ( & V_4 -> V_6 ) ;
return V_210 ;
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_33 * V_52 ;
int V_58 , V_53 ;
V_4 -> V_137 = 1 ;
if ( V_4 -> F_13 )
if ( ! F_72 ( V_4 , & V_211 ) )
return - V_46 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_212 ; V_53 ++ ) {
V_58 = F_112 ( V_3 , V_4 -> V_213 [ V_53 ] ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( V_4 -> V_150 . V_214 ) {
V_58 = F_113 ( V_3 ,
V_4 -> V_150 . V_214 ,
V_4 -> V_150 . V_214 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_114 ( V_3 ,
& V_4 -> V_150 ) ;
if ( V_58 < 0 )
return V_58 ;
V_4 -> V_150 . V_215 = 1 ;
}
if ( V_4 -> V_216 ) {
V_58 = F_115 ( V_3 , V_4 -> V_216 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( ! F_74 ( V_3 , L_7 ) ) {
unsigned int V_217 [ 4 ] ;
F_116 ( V_3 , V_4 -> V_150 . V_157 [ 0 ] ,
V_82 , V_217 ) ;
V_58 = F_117 ( V_3 , L_7 ,
V_217 , V_218 ,
L_8 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( ! F_74 ( V_3 , L_9 ) ) {
V_58 = F_117 ( V_3 , L_9 ,
NULL , V_218 ,
L_10 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_52 = F_74 ( V_3 , L_11 ) ;
for ( V_53 = 0 ; V_52 && V_53 < V_52 -> V_145 ; V_53 ++ ) {
if ( ! V_4 -> V_123 [ V_53 ] )
continue;
V_58 = F_118 ( V_3 , V_52 , V_53 , V_4 -> V_123 [ V_53 ] ) ;
if ( V_58 < 0 )
return V_58 ;
}
F_24 ( V_3 ) ;
V_58 = F_119 ( V_3 , & V_4 -> V_27 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_219 * V_220 = V_4 -> V_221 ;
V_3 -> V_222 = 0 ;
V_3 -> V_223 = V_220 ;
if ( V_4 -> V_150 . V_151 || V_4 -> V_114 ) {
snprintf ( V_4 -> V_224 ,
sizeof( V_4 -> V_224 ) ,
L_12 , V_3 -> V_225 ) ;
V_220 -> V_40 = V_4 -> V_224 ;
if ( V_4 -> V_150 . V_151 ) {
if ( ! V_4 -> V_226 )
V_4 -> V_226 =
& V_227 ;
V_220 -> V_228 [ V_229 ] =
* V_4 -> V_226 ;
V_220 -> V_228 [ V_229 ] . V_62 =
V_4 -> V_150 . V_157 [ 0 ] ;
V_220 -> V_228 [ V_229 ] . V_230 =
V_4 -> V_150 . V_201 ;
}
if ( ! V_4 -> V_231 ) {
if ( V_4 -> V_125 )
V_4 -> V_231 =
& V_232 ;
else
V_4 -> V_231 =
& V_233 ;
}
if ( V_4 -> V_114 ) {
V_220 -> V_228 [ V_234 ] =
* V_4 -> V_231 ;
V_220 -> V_228 [ V_234 ] . V_62 =
V_4 -> V_115 [ 0 ] ;
if ( ! V_4 -> V_125 )
V_220 -> V_228 [ V_234 ] . V_235 =
V_4 -> V_114 ;
}
V_3 -> V_222 ++ ;
V_220 ++ ;
}
if ( V_4 -> V_150 . V_214 || V_4 -> V_216 ) {
snprintf ( V_4 -> V_236 ,
sizeof( V_4 -> V_236 ) ,
L_13 , V_3 -> V_225 ) ;
V_220 -> V_40 = V_4 -> V_236 ;
V_220 -> V_237 = V_238 ;
if ( V_4 -> V_150 . V_214 ) {
if ( ! V_4 -> V_239 )
V_4 -> V_239 =
& V_240 ;
V_220 -> V_228 [ V_229 ] =
* V_4 -> V_239 ;
V_220 -> V_228 [ V_229 ] . V_62 =
V_4 -> V_150 . V_214 ;
}
if ( V_4 -> V_216 ) {
if ( ! V_4 -> V_241 )
V_4 -> V_241 =
& V_242 ;
V_220 -> V_228 [ V_234 ] =
* V_4 -> V_241 ;
V_220 -> V_228 [ V_234 ] . V_62 =
V_4 -> V_216 ;
}
V_3 -> V_222 ++ ;
V_220 ++ ;
}
if ( V_4 -> V_153 ) {
snprintf ( V_4 -> V_243 , sizeof( V_4 -> V_243 ) ,
L_14 , V_3 -> V_225 ) ;
V_220 -> V_40 = V_4 -> V_243 ;
V_220 -> V_228 [ V_229 ] = V_244 ;
V_220 -> V_228 [ V_229 ] . V_62 =
V_4 -> V_153 ;
V_3 -> V_222 ++ ;
V_220 ++ ;
}
return 0 ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_24 ( V_3 ) ;
F_6 ( V_4 ) ;
F_25 ( V_4 -> V_245 ) ;
F_25 ( V_4 -> V_246 ) ;
F_25 ( V_4 ) ;
}
static void F_122 ( struct V_2 * V_3 , int V_247 ,
T_3 * V_248 , bool V_177 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_247 ; V_53 ++ ) {
unsigned int V_127 = F_53 ( V_3 , V_248 [ V_53 ] , 0 ,
V_185 , 0 ) ;
if ( V_127 & V_184 )
continue;
if ( V_177 )
V_127 &= ~ V_183 ;
else
V_127 |= V_183 ;
F_39 ( V_3 , V_248 [ V_53 ] , V_127 ) ;
}
}
static void F_123 ( struct V_2 * V_3 , int V_136 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_105 )
return;
if ( ! V_136 )
V_136 = F_56 ( V_3 ,
V_4 -> V_27 . V_249 [ 0 ] ) ;
F_122 ( V_3 , V_4 -> V_27 . V_105 ,
V_4 -> V_27 . V_250 ,
V_136 ) ;
}
static void F_70 ( struct V_2 * V_3 )
{
int V_136 = 0 ;
int V_251 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_100 && V_4 -> V_27 . V_28 [ 0 ] &&
( V_4 -> V_7 != V_15 || V_4 -> V_31 ) )
V_136 = F_56 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_4 -> V_118 )
V_251 = V_4 -> V_27 . V_92 + V_4 -> V_93 ;
else
V_251 = V_4 -> V_27 . V_92 ;
F_122 ( V_3 , V_251 , V_4 -> V_27 . V_249 , V_136 ) ;
F_123 ( V_3 , V_136 ) ;
}
static void F_124 ( struct V_2 * V_3 )
{
unsigned int V_252 ;
unsigned int V_253 ;
unsigned int V_254 ;
unsigned int V_255 ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_252 = F_53 ( V_3 , V_3 -> V_194 , 0 ,
V_256 , 0 ) & 0x03 ;
V_253 = ( F_53 ( V_3 , V_3 -> V_194 , 0 ,
0xF84 , 0 ) & 0x3F0000 ) >> 16 ;
V_254 = V_253 & 0x1F ;
V_255 = F_53 ( V_3 , 0x1A , 0 ,
V_257 ,
V_258 ) ;
if ( V_252 == 0x02 ) {
F_39 ( V_3 , V_4 -> V_27 . V_249 [ 0 ] ,
V_97 ) ;
if ( V_253 & 0x20 ) {
if ( V_254 > V_255 )
V_254 = V_255 ;
F_77 ( V_3 , 0x1A , V_60 ,
0 , V_259 ,
V_255 - V_254 ) ;
} else {
F_77 ( V_3 , 0x1A , V_60 , 0 ,
V_259 ,
( ( V_255 + V_254 ) > 0x2A ) ? 0x2A :
( V_255 + V_254 ) ) ;
}
} else if ( ! ( V_252 & 0x02 ) ) {
F_39 ( V_3 , V_4 -> V_27 . V_249 [ 0 ] , 0 ) ;
}
}
static void F_125 ( struct V_2 * V_3 ,
unsigned int V_260 )
{
V_260 >>= 26 ;
V_260 = F_126 ( V_3 , V_260 ) ;
if ( V_260 & V_261 )
F_13 ( V_3 ) ;
V_260 &= ~ V_261 ;
if ( V_260 == V_262 || V_260 == V_263 )
F_70 ( V_3 ) ;
else if ( V_260 == V_264 )
F_124 ( V_3 ) ;
F_127 ( V_3 ) ;
}
static int F_128 ( struct V_2 * V_3 , T_4 V_265 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 , T_3 V_62 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_130 ( V_3 , & V_4 -> V_266 , V_62 ) ;
}
static bool F_131 ( struct V_2 * V_3 , T_3 V_162 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_150 . V_151 ; V_53 ++ ) {
if ( V_4 -> V_150 . V_157 [ V_53 ] == V_162 )
return false ;
}
if ( V_4 -> V_153 == V_162 )
return false ;
return true ;
}
static bool F_132 ( struct V_2 * V_3 , T_3 V_62 ,
T_3 V_267 , int V_268 ,
struct V_68 * V_69 , int V_74 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_110 [ 8 ] ;
int V_53 , V_251 ;
if ( V_62 == V_4 -> V_79 ) {
if ( ! V_268 )
return false ;
V_268 = 2 ;
}
V_251 = F_49 ( V_3 , V_62 , V_110 , F_50 ( V_110 ) ) ;
for ( V_53 = 0 ; V_53 < V_251 ; V_53 ++ ) {
if ( F_51 ( F_30 ( V_3 , V_110 [ V_53 ] ) ) != V_269 )
continue;
if ( V_110 [ V_53 ] == V_267 || F_131 ( V_3 , V_110 [ V_53 ] ) ) {
if ( ! ( V_4 -> V_79 && V_268 == 1 ) )
goto V_270;
}
}
if ( V_74 >= V_271 )
return false ;
for ( V_53 = 0 ; V_53 < V_251 ; V_53 ++ ) {
unsigned int type ;
type = F_51 ( F_30 ( V_3 , V_110 [ V_53 ] ) ) ;
if ( type == V_269 )
continue;
if ( F_132 ( V_3 , V_110 [ V_53 ] , V_267 ,
V_268 , V_69 , V_74 + 1 ) )
goto V_270;
}
return false ;
V_270:
V_69 -> V_69 [ V_69 -> V_74 ] = V_110 [ V_53 ] ;
V_69 -> V_43 [ V_69 -> V_74 ] = V_53 ;
if ( V_251 > 1 && F_51 ( F_30 ( V_3 , V_62 ) ) != V_272 )
V_69 -> V_77 [ V_69 -> V_74 ] = 1 ;
V_69 -> V_74 ++ ;
return true ;
}
static bool F_133 ( struct V_2 * V_3 , T_3 V_62 ,
T_3 V_267 , int V_268 ,
struct V_68 * V_69 )
{
if ( F_132 ( V_3 , V_62 , V_267 , V_268 , V_69 , 1 ) ) {
V_69 -> V_69 [ V_69 -> V_74 ] = V_62 ;
V_69 -> V_74 ++ ;
F_134 ( L_15 ,
V_69 -> V_74 , V_69 -> V_69 [ 0 ] , V_69 -> V_69 [ 1 ] ,
V_69 -> V_69 [ 2 ] , V_69 -> V_69 [ 3 ] , V_69 -> V_69 [ 4 ] ) ;
return true ;
}
return false ;
}
static int F_135 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_108 * V_109 = & V_4 -> V_27 ;
int V_53 , V_273 ;
T_3 V_62 ;
V_4 -> V_150 . V_157 = V_4 -> V_274 ;
V_273 = 0 ;
for ( V_53 = 0 ; V_53 < V_109 -> V_92 ; V_53 ++ ) {
T_3 V_162 = 0 ;
V_62 = V_109 -> V_249 [ V_53 ] ;
if ( ! V_62 )
continue;
if ( F_133 ( V_3 , V_62 , 0 , 0 , & V_4 -> V_94 [ V_53 ] ) )
V_162 = V_4 -> V_94 [ V_53 ] . V_69 [ 0 ] ;
if ( ! V_53 && F_133 ( V_3 , V_62 , V_162 , 1 ,
& V_4 -> V_96 ) )
V_162 = V_4 -> V_96 . V_69 [ 0 ] ;
if ( V_162 ) {
V_4 -> V_274 [ V_53 ] = V_162 ;
V_273 ++ ;
}
}
if ( ! V_4 -> V_94 [ 0 ] . V_74 && V_4 -> V_96 . V_74 ) {
V_4 -> V_94 [ 0 ] = V_4 -> V_96 ;
V_4 -> V_96 . V_74 = 0 ;
}
V_4 -> V_150 . V_151 = V_273 ;
return 0 ;
}
static int F_136 ( struct V_2 * V_3 , const char * V_275 ,
int V_276 , bool V_277 , struct V_68 * V_69 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_40 [ 32 ] ;
T_3 V_162 , V_85 , V_278 , V_62 ;
int V_58 ;
V_162 = V_277 ? V_69 -> V_69 [ 0 ] : 0 ;
V_85 = V_69 -> V_69 [ V_69 -> V_74 - 1 ] ;
V_278 = V_69 -> V_74 > 1 ? V_69 -> V_69 [ 1 ] : 0 ;
if ( V_162 && F_29 ( V_3 , V_162 , V_82 , V_279 ) )
V_62 = V_162 ;
else if ( F_29 ( V_3 , V_85 , V_82 , V_279 ) )
V_62 = V_85 ;
else if ( F_29 ( V_3 , V_278 , V_82 , V_279 ) )
V_62 = V_278 ;
else
V_62 = 0 ;
if ( V_62 ) {
sprintf ( V_40 , L_1 , V_275 ) ;
V_58 = F_137 ( V_4 , V_59 , V_40 ,
F_28 ( V_62 , V_276 , 0 , V_82 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_69 -> V_80 = V_62 ;
}
if ( V_162 && F_29 ( V_3 , V_162 , V_82 , V_89 ) )
V_62 = V_162 ;
else if ( F_29 ( V_3 , V_85 , V_82 , V_89 ) )
V_62 = V_85 ;
else if ( F_29 ( V_3 , V_278 , V_82 , V_89 ) )
V_62 = V_278 ;
else
V_62 = 0 ;
if ( V_62 ) {
sprintf ( V_40 , L_2 , V_275 ) ;
V_58 = F_137 ( V_4 , V_280 , V_40 ,
F_28 ( V_62 , V_276 , 0 , V_82 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_69 -> V_81 = V_62 ;
}
return 0 ;
}
static void F_138 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_108 * V_109 = & V_4 -> V_27 ;
struct V_281 * V_282 = V_109 -> V_117 ;
int V_53 , V_283 , V_251 , V_284 ;
int V_248 [ V_285 ] ;
for ( V_284 = V_286 ; V_284 >= V_287 ; V_284 -- ) {
V_251 = 0 ;
for ( V_53 = 0 ; V_53 < V_109 -> V_116 ; V_53 ++ ) {
unsigned int V_288 ;
if ( V_282 [ V_53 ] . type > V_289 )
continue;
V_288 = F_55 ( V_3 , V_282 [ V_53 ] . V_85 ) ;
if ( F_139 ( V_288 ) != V_284 )
continue;
for ( V_283 = 0 ; V_283 < V_251 ; V_283 ++ )
if ( V_282 [ V_248 [ V_283 ] ] . type < V_282 [ V_53 ] . type ) {
memmove ( V_248 + V_283 + 1 , V_248 + V_283 ,
( V_251 - V_283 ) * sizeof( int ) ) ;
break;
}
V_248 [ V_283 ] = V_53 ;
V_251 ++ ;
}
if ( V_109 -> V_92 + V_251 < 3 )
continue;
for ( V_53 = 0 ; V_53 < V_251 ; V_53 ++ ) {
T_3 V_85 = V_282 [ V_248 [ V_53 ] ] . V_85 ;
V_4 -> V_181 [ V_4 -> V_93 ++ ] = V_85 ;
V_109 -> V_249 [ V_109 -> V_92 ++ ] = V_85 ;
if ( V_109 -> V_92 == 3 )
break;
}
return;
}
}
static void F_140 ( struct V_68 * V_76 , struct V_68 * V_75 )
{
V_76 -> V_80 = V_75 -> V_80 ;
V_76 -> V_81 = V_75 -> V_81 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_108 * V_109 = & V_4 -> V_27 ;
struct V_68 * V_69 ;
static const char * const V_290 [ 4 ] = {
L_16 , L_17 , L_18 , L_19
} ;
int V_53 , V_43 , V_58 ;
int V_291 ;
V_291 = V_109 -> V_92 ;
if ( V_109 -> V_92 == 1 )
F_138 ( V_3 ) ;
V_58 = F_135 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_150 . V_151 < 3 ) {
V_4 -> V_93 = 0 ;
V_109 -> V_92 = V_291 ;
}
for ( V_53 = 0 ; V_53 < V_109 -> V_92 ; V_53 ++ ) {
T_3 V_85 , V_162 ;
V_85 = V_109 -> V_249 [ V_53 ] ;
V_162 = V_4 -> V_150 . V_157 [ V_53 ] ;
if ( ! V_85 || ! V_162 )
continue;
V_69 = V_4 -> V_94 + V_53 ;
if ( V_53 == V_292 ) {
V_58 = F_136 ( V_3 , L_20 , 1 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_136 ( V_3 , L_21 , 2 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
} else {
const char * V_275 = V_290 [ V_53 ] ;
if ( V_109 -> V_293 == V_294 &&
V_109 -> V_92 == 1 )
V_275 = L_22 ;
V_58 = F_136 ( V_3 , V_275 , 3 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( V_69 != V_4 -> V_94 + V_53 )
F_140 ( & V_4 -> V_94 [ V_53 ] , V_69 ) ;
if ( V_69 == V_4 -> V_94 && V_4 -> V_96 . V_74 )
F_140 ( & V_4 -> V_96 , V_69 ) ;
}
V_43 = F_142 ( V_3 , V_4 -> V_79 ,
V_4 -> V_150 . V_157 [ 0 ] ) ;
if ( V_43 >= 0 ) {
const char * V_40 ;
V_40 = V_4 -> V_96 . V_74 ?
L_23 : L_24 ;
V_58 = F_137 ( V_4 , V_59 , V_40 ,
F_28 ( V_4 -> V_79 , 3 ,
V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_40 = V_4 -> V_96 . V_74 ?
L_25 : L_26 ;
V_58 = F_137 ( V_4 , V_280 , V_40 ,
F_28 ( V_4 -> V_79 , 3 ,
V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_109 -> V_92 = V_291 ;
return 0 ;
}
static int F_143 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
bool V_277 ;
int V_53 , V_58 ;
if ( ! V_85 )
return 0 ;
if ( ! F_133 ( V_3 , V_85 , 0 , 0 , & V_4 -> V_103 ) ) {
for ( V_53 = V_295 ; V_53 >= V_292 ; V_53 -- ) {
if ( V_53 < V_4 -> V_150 . V_151 &&
F_133 ( V_3 , V_85 ,
V_4 -> V_150 . V_157 [ V_53 ] , 0 ,
& V_4 -> V_103 ) ) {
V_4 -> V_99 = V_53 ;
break;
}
}
}
if ( V_4 -> V_103 . V_74 ) {
V_4 -> V_153 = V_4 -> V_103 . V_69 [ 0 ] ;
if ( ! V_4 -> V_99 )
V_4 -> V_101 = V_4 -> V_103 ;
}
if ( ! V_4 -> V_101 . V_74 )
F_133 ( V_3 , V_85 ,
V_4 -> V_150 . V_157 [ V_296 ] , 0 ,
& V_4 -> V_101 ) ;
if ( ! F_133 ( V_3 , V_85 , V_4 -> V_150 . V_157 [ V_296 ] ,
1 , & V_4 -> V_102 ) && ! V_4 -> V_101 . V_74 )
return 0 ;
if ( V_4 -> V_101 . V_74 ) {
V_69 = & V_4 -> V_101 ;
V_277 = true ;
} else {
V_69 = & V_4 -> V_102 ;
V_277 = false ;
}
V_58 = F_136 ( V_3 , L_27 , 3 , V_277 , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_277 )
F_140 ( & V_4 -> V_102 , V_69 ) ;
else
F_140 ( & V_4 -> V_101 , V_69 ) ;
if ( V_4 -> V_103 . V_74 )
F_140 ( & V_4 -> V_103 , V_69 ) ;
return 0 ;
}
static int F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
bool V_277 ;
T_3 V_85 , V_162 = 0 ;
int V_58 ;
V_85 = V_4 -> V_27 . V_250 [ 0 ] ;
if ( ! V_4 -> V_27 . V_105 || ! V_85 )
return 0 ;
if ( F_133 ( V_3 , V_85 , 0 , 0 , & V_4 -> V_106 ) )
V_162 = V_4 -> V_106 . V_69 [ 0 ] ;
if ( ! V_162 )
F_133 ( V_3 , V_85 ,
V_4 -> V_150 . V_157 [ V_296 ] , 0 ,
& V_4 -> V_106 ) ;
if ( ! F_133 ( V_3 , V_85 , V_4 -> V_150 . V_157 [ V_296 ] ,
1 , & V_4 -> V_107 ) && ! V_162 )
return 0 ;
if ( ! V_4 -> V_96 . V_74 && V_4 -> V_107 . V_74 )
V_162 = 0 ;
V_4 -> V_297 = V_162 ;
V_4 -> V_150 . V_298 [ 0 ] = V_162 ;
if ( V_162 ) {
V_69 = & V_4 -> V_106 ;
V_277 = true ;
} else {
V_69 = & V_4 -> V_107 ;
V_277 = false ;
}
V_58 = F_136 ( V_3 , L_22 , 3 , V_277 , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_277 )
F_140 ( & V_4 -> V_107 , V_69 ) ;
else
F_140 ( & V_4 -> V_106 , V_69 ) ;
return 0 ;
}
static int F_145 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_146 . V_147 . V_149 [ 0 ] = V_4 -> V_95 ;
return 0 ;
}
static void F_146 ( struct V_2 * V_3 , int V_299 ,
struct V_68 * V_300 , struct V_68 * V_301 )
{
if ( V_299 ) {
F_36 ( V_3 , V_300 , false , false ) ;
F_36 ( V_3 , V_301 , true , false ) ;
} else {
F_36 ( V_3 , V_301 , false , false ) ;
F_36 ( V_3 , V_300 , true , false ) ;
}
}
static int F_147 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = V_36 -> V_146 . V_147 . V_149 [ 0 ] ;
if ( V_44 == V_4 -> V_95 )
return 0 ;
V_4 -> V_95 = V_44 ;
F_146 ( V_3 , V_44 , & V_4 -> V_94 [ 0 ] , & V_4 -> V_96 ) ;
if ( ! V_4 -> V_100 ) {
F_146 ( V_3 , V_44 , & V_4 -> V_101 ,
& V_4 -> V_102 ) ;
}
F_146 ( V_3 , V_44 , & V_4 -> V_106 ,
& V_4 -> V_107 ) ;
return 1 ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_79 )
return 0 ;
if ( ! ( V_4 -> V_96 . V_74 || V_4 -> V_102 . V_74 ||
V_4 -> V_106 . V_74 ) )
return 0 ;
if ( ! F_72 ( V_4 , & V_302 ) )
return - V_46 ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_62 = V_3 -> V_303 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_304 ; V_53 ++ , V_62 ++ ) {
unsigned int V_305 = F_30 ( V_3 , V_62 ) ;
if ( F_51 ( V_305 ) != V_306 )
continue;
if ( V_305 & V_307 )
continue;
if ( ! ( V_305 & V_308 ) )
continue;
if ( V_4 -> V_114 >= F_50 ( V_4 -> V_115 ) )
return - V_46 ;
V_4 -> V_115 [ V_4 -> V_114 ++ ] = V_62 ;
}
return 0 ;
}
static int F_150 ( struct V_33 * V_34 ,
struct V_141 * V_142 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_142 -> type = V_144 ;
V_142 -> V_145 = 1 ;
V_142 -> V_146 . V_147 . V_148 = V_4 -> V_116 ;
if ( V_142 -> V_146 . V_147 . V_149 >= V_4 -> V_116 )
V_142 -> V_146 . V_147 . V_149 = V_4 -> V_116 - 1 ;
strcpy ( V_142 -> V_146 . V_147 . V_40 ,
V_4 -> V_117 [ V_142 -> V_146 . V_147 . V_149 ] . V_309 ) ;
return 0 ;
}
static int F_151 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 = F_152 ( V_34 , & V_36 -> V_170 ) ;
V_36 -> V_146 . V_147 . V_149 [ 0 ] = V_4 -> V_122 [ V_43 ] ;
return 0 ;
}
static int F_153 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 = F_152 ( V_34 , & V_36 -> V_170 ) ;
T_3 V_310 ;
int V_166 ;
V_166 = V_36 -> V_146 . V_147 . V_149 [ 0 ] ;
if ( V_166 < 0 || V_166 >= V_4 -> V_116 )
return - V_202 ;
if ( V_4 -> V_122 [ V_43 ] == V_166 )
return 0 ;
V_4 -> V_122 [ V_43 ] = V_166 ;
if ( V_4 -> V_125 ) {
int V_121 = V_4 -> V_117 [ V_166 ] . V_121 ;
V_310 = V_4 -> V_123 [ V_121 ] ;
F_110 ( V_3 , V_166 ) ;
} else {
V_310 = V_4 -> V_123 [ V_43 ] ;
if ( F_89 ( ! V_310 ) )
return - V_202 ;
}
if ( V_310 ) {
F_52 ( V_3 , V_310 , V_139 ) ;
F_7 ( V_3 , V_310 , 0 ,
V_78 ,
V_4 -> V_117 [ V_166 ] . V_124 ) ;
}
F_13 ( V_3 ) ;
return 0 ;
}
static int F_154 ( struct V_2 * V_3 , int V_145 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
if ( V_4 -> V_116 <= 1 || ! V_145 )
return 0 ;
V_41 = F_72 ( V_4 , & V_311 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_145 = V_145 ;
return 0 ;
}
static void F_155 ( struct V_1 * V_4 , T_3 V_301 , int V_43 )
{
struct V_187 * V_51 ;
if ( V_4 -> V_190 >= F_50 ( V_4 -> V_191 ) - 1 )
return;
V_51 = V_4 -> V_191 + V_4 -> V_190 ;
V_51 -> V_62 = V_301 ;
V_51 -> V_63 = V_60 ;
V_51 -> V_43 = V_43 ;
V_4 -> V_190 ++ ;
V_4 -> V_266 . V_312 = V_4 -> V_191 ;
}
static bool F_156 ( struct V_2 * V_3 , T_3 V_75 ,
T_3 V_76 )
{
return F_157 ( V_3 , V_75 , V_76 , 1 ) >= 0 ;
}
static bool F_158 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_313 , V_43 ;
V_4 -> V_117 [ V_4 -> V_116 ] . V_121 = - 1 ;
V_4 -> V_117 [ V_4 -> V_116 ] . V_85 = V_85 ;
for ( V_313 = 0 ; V_313 < V_4 -> V_114 ; V_313 ++ ) {
if ( V_4 -> V_123 [ V_313 ] ) {
V_43 = F_142 ( V_3 , V_4 -> V_123 [ V_313 ] ,
V_85 ) ;
if ( V_43 < 0 )
continue;
V_4 -> V_117 [ V_4 -> V_116 ] . V_124 = V_43 ;
} else {
if ( ! F_156 ( V_3 , V_4 -> V_115 [ V_313 ] , V_85 ) )
continue;
}
V_4 -> V_117 [ V_4 -> V_116 ] . V_121 = V_313 ;
if ( ! V_4 -> V_125 &&
V_4 -> V_116 > 0 && V_4 -> V_117 [ 0 ] . V_121 != V_313 ) {
F_159 ( V_314
L_28 ) ;
V_4 -> V_125 = 1 ;
}
return true ;
}
return false ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_108 * V_109 = & V_4 -> V_27 ;
int V_53 , V_58 ;
V_58 = F_149 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_161 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
for ( V_53 = 0 ; V_53 < V_109 -> V_116 ; V_53 ++ ) {
if ( F_158 ( V_3 , V_109 -> V_117 [ V_53 ] . V_85 ) )
V_4 -> V_117 [ V_4 -> V_116 ++ ] . V_309 =
F_162 ( V_3 , V_109 , V_53 ) ;
}
if ( V_4 -> V_79 &&
F_158 ( V_3 , V_4 -> V_79 ) )
V_4 -> V_117 [ V_4 -> V_116 ++ ] . V_309 = L_29 ;
return 0 ;
}
static int F_163 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_108 * V_109 = & V_4 -> V_27 ;
const char * V_315 = NULL ;
int V_56 = 0 ;
int V_53 , V_283 , V_58 , V_43 ;
if ( ! V_4 -> V_79 )
return 0 ;
for ( V_53 = 0 ; V_53 < V_109 -> V_116 ; V_53 ++ ) {
T_3 V_85 = V_109 -> V_117 [ V_53 ] . V_85 ;
const char * V_309 = F_162 ( V_3 , V_109 , V_53 ) ;
if ( V_315 && ! strcmp ( V_309 , V_315 ) )
V_56 ++ ;
else
V_56 = 0 ;
V_315 = V_309 ;
V_43 = F_142 ( V_3 , V_4 -> V_79 , V_85 ) ;
if ( V_43 >= 0 ) {
V_58 = F_27 ( V_4 , V_309 , V_56 ,
V_43 , V_4 -> V_79 ) ;
if ( V_58 < 0 )
return V_58 ;
F_155 ( V_4 , V_4 -> V_79 , V_43 ) ;
}
for ( V_283 = 0 ; V_283 < V_4 -> V_93 ; V_283 ++ ) {
if ( V_4 -> V_181 [ V_283 ] == V_85 ) {
V_4 -> V_180 [ V_283 ] = V_43 ;
V_4 -> V_173 [ V_283 ] = V_309 ;
break;
}
}
}
return 0 ;
}
static int F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_108 * V_109 = & V_4 -> V_27 ;
const char * V_315 = NULL ;
int V_56 = 0 ;
int V_53 , V_58 ;
for ( V_53 = 0 ; V_53 < V_109 -> V_116 ; V_53 ++ ) {
T_3 V_85 = V_109 -> V_117 [ V_53 ] . V_85 ;
unsigned int V_65 ;
const char * V_309 ;
char V_40 [ 32 ] ;
if ( V_109 -> V_117 [ V_53 ] . type != V_120 )
continue;
V_65 = F_31 ( V_3 , V_85 , V_60 ) ;
if ( V_65 == - 1 || ! ( V_65 & V_279 ) )
continue;
V_309 = F_162 ( V_3 , V_109 , V_53 ) ;
if ( V_315 && ! strcmp ( V_309 , V_315 ) )
V_56 ++ ;
else
V_56 = 0 ;
V_315 = V_309 ;
snprintf ( V_40 , sizeof( V_40 ) , L_30 , V_309 ) ;
V_58 = F_22 ( V_4 , V_59 , V_40 , V_56 ,
F_28 ( V_85 , 3 , 0 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
return 0 ;
}
static int F_165 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_58 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_114 ; V_53 ++ ) {
T_3 V_209 = V_4 -> V_115 [ V_53 ] ;
V_58 = F_22 ( V_4 , V_59 ,
L_31 , V_53 ,
F_28 ( V_209 , 3 , 0 ,
V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_22 ( V_4 , V_280 ,
L_32 , V_53 ,
F_28 ( V_209 , 3 , 0 ,
V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
for ( V_53 = 0 ; V_53 < V_4 -> V_114 ; V_53 ++ )
if ( ! V_4 -> V_123 [ V_53 ] )
break;
V_58 = F_154 ( V_3 , V_53 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_166 ( struct V_1 * V_4 , struct V_316 * * V_317 ,
struct V_318 * V_319 )
{
struct V_316 * V_112 ;
int V_53 ;
V_112 = F_2 ( sizeof( * V_112 ) + sizeof( long ) * 4 , V_5 ) ;
if ( ! V_112 )
return - V_46 ;
V_112 -> V_319 = V_319 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_114 ; V_53 ++ )
V_112 -> V_320 [ V_53 ] =
F_28 ( V_4 -> V_115 [ V_53 ] , 3 , 0 , V_60 ) ;
* V_317 = V_112 ;
return 0 ;
}
static int F_167 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
int V_58 ;
V_58 = F_166 ( V_4 , & V_4 -> V_245 , & V_321 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_166 ( V_4 , & V_4 -> V_246 , & V_322 ) ;
if ( V_58 < 0 )
return V_58 ;
V_41 = F_72 ( V_4 , & V_323 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_50 = ( long ) V_4 -> V_245 ;
V_41 = F_72 ( V_4 , & V_324 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_50 = ( long ) V_4 -> V_246 ;
V_58 = F_154 ( V_3 , 1 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_58 ;
V_58 = F_160 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_125 )
V_58 = F_167 ( V_3 ) ;
else
V_58 = F_165 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_163 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_164 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static void F_169 ( struct V_2 * V_3 , T_3 V_62 )
{
unsigned int V_131 ;
unsigned char V_325 ;
V_131 = F_55 ( V_3 , V_62 ) ;
V_325 = ( unsigned char ) F_170 ( V_131 ) ;
V_325 = ( V_325 << 4 ) | F_171 ( V_131 ) ;
if ( F_57 ( V_131 ) == V_138
&& ( V_325 == 0xf0 || V_325 == 0xff ) ) {
V_131 = V_131 & ( ~ ( V_326 << 30 ) ) ;
F_172 ( V_3 , V_62 , V_131 ) ;
}
return;
}
static int F_173 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_36 -> V_146 . integer . V_146 [ 0 ] = V_4 -> V_31 ;
return 0 ;
}
static int F_174 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_44 = ! ! V_36 -> V_146 . integer . V_146 [ 0 ] ;
if ( V_4 -> V_31 == V_44 )
return 0 ;
V_4 -> V_31 = V_44 ;
if ( V_4 -> V_31 &&
F_175 ( V_3 , L_33 ) != 1 ) {
F_76 ( V_3 , 1 ) ;
F_73 ( V_3 ) ;
}
F_70 ( V_3 ) ;
F_9 ( V_4 ) ;
return 1 ;
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_58 ;
V_58 = F_177 ( V_3 , & V_4 -> V_27 , NULL ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! V_4 -> V_27 . V_92 && ! V_4 -> V_27 . V_28 [ 0 ] )
return - V_202 ;
V_58 = F_141 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_143 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_144 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_148 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_168 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_4 -> V_150 . V_201 = V_4 -> V_150 . V_151 * 2 ;
F_178 ( V_3 ) ;
F_179 ( V_3 ) ;
if ( V_4 -> V_42 . V_51 )
V_4 -> V_213 [ V_4 -> V_212 ++ ] = V_4 -> V_42 . V_51 ;
if ( V_4 -> V_153 && V_4 -> V_102 . V_74 ) {
V_58 = F_71 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_58 = F_80 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_327 [ 0 ] )
V_3 -> V_327 = V_4 -> V_327 ;
return 1 ;
}
static void F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_150 . V_214 )
F_38 ( V_3 , V_4 -> V_27 . V_328 [ 0 ] , V_97 ) ;
if ( V_4 -> V_327 [ 0 ] )
F_38 ( V_3 , V_4 -> V_27 . V_328 [ 1 ] , V_97 ) ;
}
static void F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_216 )
return;
F_39 ( V_3 , V_4 -> V_27 . V_329 , V_119 ) ;
}
static void F_182 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_108 * V_109 = & V_4 -> V_27 ;
unsigned int V_330 ;
int V_53 ;
if ( V_109 -> V_28 [ 0 ] && F_183 ( V_3 , V_109 -> V_28 [ 0 ] ) )
F_184 ( V_3 , V_109 -> V_28 [ 0 ] ,
V_262 | V_261 ) ;
if ( V_109 -> V_250 [ 0 ] )
V_330 = V_263 ;
else
V_330 = 0 ;
for ( V_53 = 0 ; V_53 < V_109 -> V_92 ; V_53 ++ ) {
if ( V_109 -> V_249 [ V_53 ] &&
F_183 ( V_3 , V_109 -> V_249 [ V_53 ] ) )
F_184 ( V_3 , V_109 -> V_249 [ V_53 ] ,
V_330 | V_261 ) ;
}
for ( V_53 = 0 ; V_53 < V_109 -> V_116 ; V_53 ++ ) {
if ( F_183 ( V_3 , V_109 -> V_117 [ V_53 ] . V_85 ) )
F_184 ( V_3 , V_109 -> V_117 [ V_53 ] . V_85 ,
V_261 ) ;
}
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_331 ; V_53 ++ )
F_186 ( V_3 , V_4 -> V_332 [ V_53 ] ) ;
F_13 ( V_3 ) ;
F_83 ( V_3 , true ) ;
F_42 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
F_180 ( V_3 ) ;
F_181 ( V_3 ) ;
F_182 ( V_3 ) ;
F_70 ( V_3 ) ;
F_9 ( V_4 ) ;
F_127 ( V_3 ) ;
return 0 ;
}
static void F_187 ( struct V_333 * V_334 )
{
struct V_1 * V_4 = F_188 ( V_334 , struct V_1 ,
V_30 . V_334 ) ;
if ( V_4 -> V_7 != V_15 )
return;
F_189 ( V_4 -> V_3 ) ;
if ( V_4 -> V_335
!= F_56 ( V_4 -> V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ) {
V_4 -> V_335 ^= 1 ;
F_70 ( V_4 -> V_3 ) ;
}
if ( V_4 -> V_31 )
F_11 ( & V_4 -> V_30 ,
F_12 ( 100 ) ) ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_62 , V_110 [ 8 ] ;
unsigned int type ;
int V_53 , V_336 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_114 ; V_53 ++ ) {
V_62 = V_4 -> V_115 [ V_53 ] ;
while ( V_62 ) {
type = F_51 ( F_30 ( V_3 , V_62 ) ) ;
if ( type == V_126 )
break;
V_336 = F_49 ( V_3 , V_62 , V_110 ,
F_50 ( V_110 ) ) ;
if ( V_336 <= 0 )
break;
if ( V_336 > 1 ) {
V_4 -> V_123 [ V_53 ] = V_62 ;
break;
}
V_62 = V_110 [ 0 ] ;
}
}
return 0 ;
}
static int F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x17 ;
F_169 ( V_3 , V_337 ) ;
F_169 ( V_3 , V_338 ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
if ( ! F_72 ( V_4 , & V_339 ) )
return - V_46 ;
if ( V_3 -> V_11 == 0x11061708 )
V_4 -> V_226 = & V_340 ;
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_341 ;
V_3 -> V_342 = V_343 ;
F_191 ( & V_4 -> V_30 , F_187 ) ;
return 0 ;
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x18 ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_3 -> V_342 = V_343 ;
return 0 ;
}
static void F_193 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_127 ;
int V_345 = 0 ;
if ( ( V_4 -> V_7 != V_20 ) &&
( V_3 -> V_11 != 0x11064397 ) )
V_345 = 1 ;
V_344 =
( F_53 ( V_3 , 0x17 , 0 , V_346 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x1a , & V_127 ) ;
F_54 ( V_3 , 0x1b , & V_127 ) ;
F_54 ( V_3 , 0x1e , & V_127 ) ;
if ( V_344 )
V_127 = V_139 ;
F_52 ( V_3 , 0x17 , V_127 ) ;
F_52 ( V_3 , 0x13 , V_127 ) ;
F_52 ( V_3 , 0x14 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x19 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x1b , & V_127 ) ;
F_52 ( V_3 , 0x18 , V_127 ) ;
F_52 ( V_3 , 0x11 , V_127 ) ;
if ( V_345 ) {
V_127 = V_140 ;
F_54 ( V_3 , 0x22 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x1a , & V_127 ) ;
F_52 ( V_3 , 0x26 , V_127 ) ;
F_52 ( V_3 , 0x24 , V_127 ) ;
} else if ( V_3 -> V_11 == 0x11064397 ) {
V_127 = V_140 ;
F_54 ( V_3 , 0x23 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x1a , & V_127 ) ;
F_52 ( V_3 , 0x27 , V_127 ) ;
F_52 ( V_3 , 0x25 , V_127 ) ;
}
V_127 = V_140 ;
F_54 ( V_3 , 0x1c , & V_127 ) ;
F_54 ( V_3 , 0x1d , & V_127 ) ;
if ( V_345 )
F_54 ( V_3 , 0x23 , & V_127 ) ;
F_52 ( V_3 , 0x16 , V_344 ? V_139 : V_127 ) ;
F_52 ( V_3 , 0x10 , V_127 ) ;
if ( V_345 ) {
F_52 ( V_3 , 0x25 , V_127 ) ;
F_52 ( V_3 , 0x27 , V_127 ) ;
} else if ( V_3 -> V_11 == 0x11064397 && V_4 -> V_100 )
F_52 ( V_3 , 0x25 , V_127 ) ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
if ( F_4 ( V_3 ) == V_8 )
return F_195 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_3 -> V_342 = V_343 ;
V_4 -> F_13 = F_193 ;
return 0 ;
}
static void F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_27 . V_347 ; V_53 ++ ) {
T_3 V_62 ;
int V_110 ;
V_62 = V_4 -> V_27 . V_328 [ V_53 ] ;
if ( ! V_62 )
continue;
V_110 = F_49 ( V_3 , V_62 , & V_62 , 1 ) ;
if ( V_110 < 1 )
continue;
if ( ! V_4 -> V_150 . V_214 )
V_4 -> V_150 . V_214 = V_62 ;
else {
V_4 -> V_327 [ 0 ] = V_62 ;
break;
}
}
}
static void F_179 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_348 ;
int V_53 , V_58 ;
if ( ! V_4 -> V_27 . V_329 )
return;
V_348 = V_3 -> V_303 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_304 ; V_53 ++ , V_348 ++ ) {
unsigned int V_305 = F_30 ( V_3 , V_348 ) ;
if ( F_51 ( V_305 ) != V_306 )
continue;
if ( ! ( V_305 & V_307 ) )
continue;
if ( ! ( V_305 & V_308 ) )
continue;
V_58 = F_142 ( V_3 , V_348 ,
V_4 -> V_27 . V_329 ) ;
if ( V_58 >= 0 ) {
V_4 -> V_216 = V_348 ;
break;
}
}
}
static void F_196 ( struct V_2 * V_3 , T_3 V_85 ,
int V_349 , int V_350 , int V_351 )
{
F_197 ( V_3 , V_85 , V_60 ,
( V_349 << V_91 ) |
( V_350 << V_352 ) |
( V_351 << V_353 ) |
( 0 << V_354 ) ) ;
}
static int F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
F_196 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_355 ;
V_3 -> V_342 = V_343 ;
if ( F_4 ( V_3 ) == V_8 ) {
F_25 ( V_3 -> V_225 ) ;
V_3 -> V_225 = F_21 ( L_34 , V_5 ) ;
snprintf ( V_3 -> V_174 -> V_175 -> V_356 ,
sizeof( V_3 -> V_174 -> V_175 -> V_356 ) ,
L_35 , V_3 -> V_357 , V_3 -> V_225 ) ;
}
if ( V_3 -> V_11 == 0x11064397 ) {
F_25 ( V_3 -> V_225 ) ;
V_3 -> V_225 = F_21 ( L_36 , V_5 ) ;
snprintf ( V_3 -> V_174 -> V_175 -> V_356 ,
sizeof( V_3 -> V_174 -> V_175 -> V_356 ) ,
L_35 , V_3 -> V_357 , V_3 -> V_225 ) ;
}
V_4 -> F_13 = F_193 ;
return 0 ;
}
static void F_198 ( struct V_2 * V_3 )
{
int V_344 =
F_53 ( V_3 , 0x13 , 0 , V_346 , 0x00 ) == 3 ;
unsigned int V_127 ;
V_127 = V_140 ;
F_54 ( V_3 , 0x14 , & V_127 ) ;
F_54 ( V_3 , 0x15 , & V_127 ) ;
F_54 ( V_3 , 0x18 , & V_127 ) ;
if ( V_344 )
V_127 = V_139 ;
F_52 ( V_3 , 0x13 , V_127 ) ;
F_52 ( V_3 , 0x12 , V_127 ) ;
F_52 ( V_3 , 0x1f , V_127 ) ;
F_52 ( V_3 , 0x20 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x17 , & V_127 ) ;
F_54 ( V_3 , 0x16 , & V_127 ) ;
F_52 ( V_3 , 0x1a , V_344 ? V_139 : V_127 ) ;
F_52 ( V_3 , 0x10 , V_127 ) ;
F_52 ( V_3 , 0x1d , V_127 ) ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x1a ;
F_197 ( V_3 , 0x1A , V_60 ,
( 0x17 << V_91 ) |
( 0x17 << V_352 ) |
( 0x5 << V_353 ) |
( 1 << V_354 ) ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_358 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_13 = F_198 ;
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_127 ;
V_344 =
F_53 ( V_3 , 0x1e , 0 , V_346 , 0x00 ) == 5 ;
V_127 = V_140 ;
F_54 ( V_3 , 0x29 , & V_127 ) ;
F_54 ( V_3 , 0x2a , & V_127 ) ;
F_54 ( V_3 , 0x2b , & V_127 ) ;
if ( V_344 )
V_127 = V_139 ;
F_52 ( V_3 , 0x1e , V_127 ) ;
F_52 ( V_3 , 0x1f , V_127 ) ;
F_52 ( V_3 , 0x10 , V_127 ) ;
F_52 ( V_3 , 0x11 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x27 , & V_127 ) ;
F_52 ( V_3 , 0x1a , V_127 ) ;
F_52 ( V_3 , 0xb , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x26 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x2b , & V_127 ) ;
F_52 ( V_3 , 0xa , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x24 , & V_127 ) ;
if ( ! V_4 -> V_100 )
F_54 ( V_3 , 0x28 , & V_127 ) ;
F_52 ( V_3 , 0x8 , V_127 ) ;
F_52 ( V_3 , 0x21 , V_344 ? V_139 : V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x25 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x2a , & V_127 ) ;
F_52 ( V_3 , 0x9 , V_127 ) ;
if ( V_4 -> V_100 ) {
V_127 = V_140 ;
F_54 ( V_3 , 0x28 , & V_127 ) ;
F_52 ( V_3 , 0x1b , V_127 ) ;
F_52 ( V_3 , 0x34 , V_127 ) ;
F_52 ( V_3 , 0xc , V_127 ) ;
}
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_251 ;
T_3 V_110 [ 8 ] ;
T_3 V_62 ;
if ( ! V_4 -> V_79 )
return 0 ;
V_251 = F_49 ( V_3 , V_4 -> V_79 , V_110 ,
F_50 ( V_110 ) - 1 ) ;
for ( V_53 = 0 ; V_53 < V_251 ; V_53 ++ ) {
if ( F_51 ( F_30 ( V_3 , V_110 [ V_53 ] ) ) == V_269 )
return 0 ;
}
V_62 = V_3 -> V_303 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_304 ; V_53 ++ , V_62 ++ ) {
unsigned int V_65 = F_30 ( V_3 , V_62 ) ;
if ( F_51 ( V_65 ) == V_269 &&
! ( V_65 & V_307 ) ) {
V_110 [ V_251 ++ ] = V_62 ;
return F_202 ( V_3 ,
V_4 -> V_79 ,
V_251 , V_110 ) ;
}
}
return 0 ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_196 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_201 ( V_3 ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_359 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_13 = F_200 ;
return 0 ;
}
static int F_204 ( struct V_33 * V_34 ,
struct V_141 * V_142 )
{
V_142 -> type = V_360 ;
V_142 -> V_145 = 1 ;
V_142 -> V_146 . integer . V_361 = 0 ;
V_142 -> V_146 . integer . V_362 = 1 ;
return 0 ;
}
static int F_205 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
int V_47 = 0 ;
V_47 = F_53 ( V_3 , 0x26 , 0 ,
V_346 , 0 ) ;
if ( V_47 != - 1 )
* V_36 -> V_146 . integer . V_146 = V_47 ;
return 0 ;
}
static int F_206 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_47 = * V_36 -> V_146 . integer . V_146 ;
F_7 ( V_3 , 0x26 , 0 ,
V_78 , V_47 ) ;
V_4 -> V_363 = V_47 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_207 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_127 ;
unsigned int V_364 , V_136 ;
V_344 =
( F_53 ( V_3 , 0x17 , 0 ,
V_346 , 0x00 ) == 5 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x1a , & V_127 ) ;
F_54 ( V_3 , 0x1b , & V_127 ) ;
F_54 ( V_3 , 0x1e , & V_127 ) ;
if ( V_344 )
V_127 = V_139 ;
F_52 ( V_3 , 0x17 , V_127 ) ;
F_52 ( V_3 , 0x13 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x1e , & V_127 ) ;
if ( V_4 -> V_363 )
F_54 ( V_3 , 0x22 , & V_127 ) ;
else
F_52 ( V_3 , 0x22 , V_140 ) ;
F_52 ( V_3 , 0x26 , V_127 ) ;
F_52 ( V_3 , 0x14 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x19 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x1b , & V_127 ) ;
F_52 ( V_3 , 0x18 , V_127 ) ;
F_52 ( V_3 , 0x11 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x23 , & V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x1a , & V_127 ) ;
F_52 ( V_3 , 0x27 , V_127 ) ;
if ( V_4 -> V_118 )
F_54 ( V_3 , 0x1e , & V_127 ) ;
F_52 ( V_3 , 0x25 , V_127 ) ;
V_136 = F_56 ( V_3 , 0x1c ) ;
if ( V_136 )
V_364 = 0 ;
else {
V_136 = F_56 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_100 && V_136 )
V_364 = 0 ;
else
V_364 = 1 ;
}
V_127 = V_364 ? V_139 : V_140 ;
F_52 ( V_3 , 0x28 , V_127 ) ;
F_52 ( V_3 , 0x29 , V_127 ) ;
F_52 ( V_3 , 0x2a , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x1c , & V_127 ) ;
F_54 ( V_3 , 0x1d , & V_127 ) ;
if ( V_4 -> V_100 )
F_52 ( V_3 , 0x25 , V_127 ) ;
F_52 ( V_3 , 0x16 , V_344 ? V_139 : V_127 ) ;
F_52 ( V_3 , 0x10 , V_364 ? V_139 : V_127 ) ;
}
static int F_208 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
F_196 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_365 ;
V_4 -> V_213 [ V_4 -> V_212 ] = V_366 ;
V_4 -> V_212 ++ ;
V_4 -> V_213 [ V_4 -> V_212 ++ ] = V_367 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_13 = F_207 ;
return 0 ;
}
static void F_209 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_127 ;
unsigned int V_136 ;
V_344 =
F_53 ( V_3 , 0x1e , 0 , V_346 , 0x00 ) == 3 ;
V_127 = V_140 ;
F_54 ( V_3 , 0x29 , & V_127 ) ;
F_54 ( V_3 , 0x2a , & V_127 ) ;
F_54 ( V_3 , 0x2b , & V_127 ) ;
V_127 = V_139 ;
F_52 ( V_3 , 0x1e , V_127 ) ;
F_52 ( V_3 , 0x1f , V_127 ) ;
F_52 ( V_3 , 0x10 , V_127 ) ;
F_52 ( V_3 , 0x11 , V_127 ) ;
F_52 ( V_3 , 0x8 , V_127 ) ;
if ( V_4 -> V_7 == V_26 ) {
V_127 = V_140 ;
F_54 ( V_3 , 0x28 , & V_127 ) ;
F_52 ( V_3 , 0x18 , V_127 ) ;
F_52 ( V_3 , 0x38 , V_127 ) ;
} else {
V_127 = V_140 ;
F_54 ( V_3 , 0x26 , & V_127 ) ;
F_52 ( V_3 , 0x1c , V_127 ) ;
F_52 ( V_3 , 0x37 , V_127 ) ;
}
if ( V_4 -> V_7 == V_26 ) {
V_127 = V_140 ;
F_54 ( V_3 , 0x25 , & V_127 ) ;
F_52 ( V_3 , 0x15 , V_127 ) ;
F_52 ( V_3 , 0x35 , V_127 ) ;
} else {
V_127 = V_140 ;
F_54 ( V_3 , 0x25 , & V_127 ) ;
F_52 ( V_3 , 0x19 , V_127 ) ;
F_52 ( V_3 , 0x35 , V_127 ) ;
}
if ( V_4 -> V_100 )
F_52 ( V_3 , 0x9 , V_139 ) ;
V_136 = F_56 ( V_3 , 0x25 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x24 , & V_127 ) ;
V_127 = V_136 ? V_140 : V_139 ;
if ( V_4 -> V_7 == V_26 )
F_52 ( V_3 , 0x14 , V_127 ) ;
else
F_52 ( V_3 , 0x18 , V_127 ) ;
F_52 ( V_3 , 0x34 , V_127 ) ;
V_136 = F_56 ( V_3 , 0x26 ) ;
V_127 = V_136 ? V_140 : V_139 ;
if ( V_4 -> V_7 == V_26 ) {
F_52 ( V_3 , 0x33 , V_127 ) ;
F_52 ( V_3 , 0x1c , V_127 ) ;
F_52 ( V_3 , 0x3c , V_127 ) ;
} else {
F_52 ( V_3 , 0x31 , V_127 ) ;
F_52 ( V_3 , 0x17 , V_127 ) ;
F_52 ( V_3 , 0x3b , V_127 ) ;
}
if ( V_344 || ! F_81 ( V_3 ) )
F_52 ( V_3 , 0x21 , V_139 ) ;
else
F_52 ( V_3 , 0x21 , V_140 ) ;
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_196 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_201 ( V_3 ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
if ( V_4 -> V_7 == V_26 )
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_368 ;
else
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_369 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_13 = F_209 ;
return 0 ;
}
static void F_211 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_127 ;
unsigned int V_136 ;
V_127 = V_140 ;
F_54 ( V_3 , 0x29 , & V_127 ) ;
F_54 ( V_3 , 0x2a , & V_127 ) ;
F_54 ( V_3 , 0x2b , & V_127 ) ;
V_127 = V_139 ;
F_52 ( V_3 , 0x1e , V_127 ) ;
F_52 ( V_3 , 0x1f , V_127 ) ;
F_52 ( V_3 , 0x10 , V_127 ) ;
F_52 ( V_3 , 0x11 , V_127 ) ;
F_52 ( V_3 , 0x8 , V_139 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x28 , & V_127 ) ;
F_52 ( V_3 , 0x18 , V_127 ) ;
F_52 ( V_3 , 0x38 , V_127 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x25 , & V_127 ) ;
F_52 ( V_3 , 0x15 , V_127 ) ;
F_52 ( V_3 , 0x35 , V_127 ) ;
if ( V_4 -> V_100 )
F_52 ( V_3 , 0x9 , V_139 ) ;
V_136 = F_56 ( V_3 , 0x25 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x24 , & V_127 ) ;
if ( V_136 ) {
F_52 ( V_3 , 0x14 , V_140 ) ;
F_52 ( V_3 , 0x34 , V_140 ) ;
} else {
F_52 ( V_3 , 0x14 , V_139 ) ;
F_52 ( V_3 , 0x34 , V_139 ) ;
}
V_136 = F_56 ( V_3 , 0x28 ) ;
V_127 = V_140 ;
F_54 ( V_3 , 0x31 , & V_127 ) ;
if ( V_136 ) {
F_52 ( V_3 , 0x1c , V_140 ) ;
F_52 ( V_3 , 0x3c , V_140 ) ;
F_52 ( V_3 , 0x3e , V_140 ) ;
} else {
F_52 ( V_3 , 0x1c , V_139 ) ;
F_52 ( V_3 , 0x3c , V_139 ) ;
F_52 ( V_3 , 0x3e , V_139 ) ;
}
V_127 = V_140 ;
F_54 ( V_3 , 0x33 , & V_127 ) ;
F_52 ( V_3 , 0x1d , V_127 ) ;
F_52 ( V_3 , 0x3d , V_127 ) ;
}
static int F_212 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_196 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_201 ( V_3 ) ;
V_58 = F_176 ( V_3 ) ;
if ( V_58 < 0 ) {
F_121 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_370 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_13 = F_211 ;
return 0 ;
}
static int T_5 F_213 ( void )
{
return F_214 ( & V_371 ) ;
}
static void T_6 F_215 ( void )
{
F_216 ( & V_371 ) ;
}
