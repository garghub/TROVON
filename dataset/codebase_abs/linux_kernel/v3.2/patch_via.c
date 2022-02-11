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
V_71 = F_33 ( V_3 , V_57 , NULL ) ;
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
F_7 ( V_3 , V_85 , 0 , V_87 ,
V_86 ) ;
if ( F_39 ( V_3 , V_85 ) & V_88 )
F_7 ( V_3 , V_85 , 0 ,
V_89 , 0x02 ) ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_68 * V_69 , int V_86 )
{
unsigned int V_65 ;
T_3 V_85 ;
if ( ! V_69 -> V_74 )
return;
V_85 = V_69 -> V_69 [ V_69 -> V_74 - 1 ] ;
F_38 ( V_3 , V_85 , V_86 ) ;
V_65 = F_31 ( V_3 , V_85 , V_82 ) ;
if ( V_65 & V_90 ) {
unsigned int V_44 ;
V_44 = ( V_65 & V_91 ) >> V_92 ;
F_7 ( V_3 , V_85 , 0 , V_72 ,
V_84 | V_44 ) ;
}
F_36 ( V_3 , V_69 , true , true ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_27 . V_93 + V_4 -> V_94 ; V_53 ++ ) {
V_69 = & V_4 -> V_95 [ V_53 ] ;
if ( ! V_53 && V_4 -> V_96 && V_4 -> V_97 . V_74 )
V_69 = & V_4 -> V_97 ;
F_40 ( V_3 , V_69 , V_98 ) ;
}
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_99 = V_4 -> V_100 ;
if ( V_4 -> V_101 ) {
F_36 ( V_3 , & V_4 -> V_102 , false , false ) ;
F_36 ( V_3 , & V_4 -> V_103 , false , false ) ;
if ( V_99 )
F_36 ( V_3 , & V_4 -> V_95 [ V_99 ] ,
false , false ) ;
} else if ( V_4 -> V_96 || ! V_4 -> V_102 . V_74 ) {
F_36 ( V_3 , & V_4 -> V_104 , false , false ) ;
F_36 ( V_3 , & V_4 -> V_102 , false , false ) ;
} else {
F_36 ( V_3 , & V_4 -> V_104 , false , false ) ;
F_36 ( V_3 , & V_4 -> V_103 , false , false ) ;
}
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_102 . V_74 ) {
F_40 ( V_3 , & V_4 -> V_103 , V_105 ) ;
return;
}
F_42 ( V_3 ) ;
if ( V_4 -> V_101 )
F_40 ( V_3 , & V_4 -> V_104 , V_105 ) ;
else if ( V_4 -> V_96 )
F_40 ( V_3 , & V_4 -> V_103 , V_105 ) ;
else
F_40 ( V_3 , & V_4 -> V_102 , V_105 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_106 )
return;
if ( ! V_4 -> V_107 . V_74 ) {
F_40 ( V_3 , & V_4 -> V_108 , V_98 ) ;
return;
}
if ( ! V_4 -> V_96 ) {
F_36 ( V_3 , & V_4 -> V_108 ,
false , false ) ;
F_40 ( V_3 , & V_4 -> V_107 , V_98 ) ;
} else {
F_36 ( V_3 , & V_4 -> V_107 , false , false ) ;
F_40 ( V_3 , & V_4 -> V_108 , V_98 ) ;
}
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
T_3 V_111 [ V_112 ] ;
unsigned int V_113 ;
int V_53 , V_114 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ ) {
F_7 ( V_3 , V_4 -> V_116 [ V_53 ] , 0 ,
V_72 ,
F_34 ( 0 ) ) ;
}
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
T_3 V_62 = V_110 -> V_118 [ V_53 ] . V_85 ;
if ( V_4 -> V_119 && F_46 ( V_3 , V_62 ) )
V_113 = V_98 ;
else if ( V_110 -> V_118 [ V_53 ] . type == V_120 )
V_113 = V_121 ;
else
V_113 = V_122 ;
F_7 ( V_3 , V_62 , 0 ,
V_87 , V_113 ) ;
}
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ ) {
int V_123 = V_4 -> V_118 [ V_4 -> V_124 [ V_53 ] ] . V_123 ;
if ( V_4 -> V_125 [ V_123 ] ) {
int V_126 = V_4 -> V_118 [ V_4 -> V_124 [ V_53 ] ] . V_126 ;
F_7 ( V_3 , V_4 -> V_125 [ V_123 ] , 0 ,
V_78 ,
V_126 ) ;
}
if ( V_4 -> V_127 )
break;
}
if ( ! V_4 -> V_79 )
return;
V_114 = F_47 ( V_3 , V_4 -> V_79 , V_111 ,
F_48 ( V_111 ) ) ;
for ( V_53 = 0 ; V_53 < V_114 ; V_53 ++ ) {
unsigned int V_65 = F_30 ( V_3 , V_111 [ V_53 ] ) ;
if ( F_49 ( V_65 ) == V_128 )
F_7 ( V_3 , V_4 -> V_79 , 0 ,
V_72 ,
F_35 ( V_53 ) ) ;
}
}
static void F_50 ( struct V_2 * V_3 , T_3 V_62 ,
unsigned int * V_129 )
{
unsigned V_130 ;
unsigned V_131 = F_51 ( V_3 , V_62 ) ;
unsigned V_132 = ( V_131 & V_133 )
>> V_134
& V_135 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_136 = 0 ;
V_132 |= V_4 -> V_137 ;
if ( ! V_132 )
V_136 = F_52 ( V_3 , V_62 ) ;
if ( ( V_4 -> V_119 && F_46 ( V_3 , V_62 ) )
|| ( ( V_132 || V_136 )
&& F_53 ( V_131 ) != V_138 ) ) {
* V_129 = V_139 ;
V_130 = V_139 ;
} else
V_130 = V_140 ;
F_7 ( V_3 , V_62 , 0 , V_141 , V_130 ) ;
}
static int F_54 ( struct V_33 * V_34 ,
struct V_142 * V_143 )
{
static const char * const V_144 [] = {
L_3 , L_4
} ;
V_143 -> type = V_145 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . V_148 . V_149 = 2 ;
if ( V_143 -> V_147 . V_148 . V_150 >= V_143 -> V_147 . V_148 . V_149 )
V_143 -> V_147 . V_148 . V_150 = V_143 -> V_147 . V_148 . V_149 - 1 ;
strcpy ( V_143 -> V_147 . V_148 . V_40 ,
V_144 [ V_143 -> V_147 . V_148 . V_150 ] ) ;
return 0 ;
}
static int F_55 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_147 . V_148 . V_150 [ 0 ] = ! V_4 -> V_137 ;
return 0 ;
}
static int F_56 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = ! V_36 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_44 == V_4 -> V_137 )
return 0 ;
V_4 -> V_137 = V_44 ;
F_13 ( V_3 ) ;
return 1 ;
}
static int F_57 ( struct V_33 * V_34 ,
struct V_142 * V_143 )
{
static const char * const V_144 [] = { L_5 , L_6 } ;
V_143 -> type = V_145 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . V_148 . V_149 = 2 ;
if ( V_143 -> V_147 . V_148 . V_150 >= 2 )
V_143 -> V_147 . V_148 . V_150 = 1 ;
strcpy ( V_143 -> V_147 . V_148 . V_40 ,
V_144 [ V_143 -> V_147 . V_148 . V_150 ] ) ;
return 0 ;
}
static int F_58 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_147 . V_148 . V_150 [ 0 ] = V_4 -> V_101 ;
return 0 ;
}
static void F_59 ( struct V_1 * V_4 )
{
const struct V_109 * V_110 = & V_4 -> V_27 ;
V_4 -> V_151 . V_152 = V_110 -> V_93 + V_4 -> V_94 ;
V_4 -> V_151 . V_153 = 0 ;
if ( ! V_4 -> V_101 ) {
if ( ! V_4 -> V_100 )
V_4 -> V_151 . V_153 = V_4 -> V_154 ;
} else {
if ( V_4 -> V_100 )
V_4 -> V_151 . V_152 = V_110 -> V_93 - 1 ;
}
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_99 = V_4 -> V_100 ;
T_3 V_155 , V_156 ;
if ( ! V_4 -> V_157 )
return;
V_155 = V_99 ? V_4 -> V_151 . V_158 [ V_99 ] : 0 ;
V_156 = V_4 -> V_154 ;
if ( V_4 -> V_101 ) {
if ( V_4 -> V_32 & V_159 ) {
F_61 ( V_3 , V_156 , 1 ) ;
F_61 ( V_3 , V_155 , 1 ) ;
}
if ( V_4 -> V_32 & V_160 )
F_62 ( V_3 , V_156 ,
V_4 -> V_161 , 0 ,
V_4 -> V_162 ) ;
} else {
if ( V_4 -> V_32 & V_160 )
F_61 ( V_3 , V_156 , 1 ) ;
if ( V_4 -> V_32 & V_159 ) {
T_3 V_163 ;
int V_164 ;
if ( V_155 ) {
V_163 = V_155 ;
V_164 = V_99 * 2 ;
} else {
V_163 = V_156 ;
V_164 = 0 ;
}
F_62 ( V_3 , V_163 ,
V_4 -> V_165 , V_164 ,
V_4 -> V_166 ) ;
}
}
F_59 ( V_4 ) ;
}
static int F_63 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_167 , V_99 ;
F_64 ( & V_4 -> V_6 ) ;
V_167 = ! ! V_36 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_4 -> V_101 == V_167 ) {
F_65 ( & V_4 -> V_6 ) ;
return 0 ;
}
V_4 -> V_101 = V_167 ;
V_99 = V_4 -> V_100 ;
F_42 ( V_3 ) ;
if ( V_167 )
F_36 ( V_3 , & V_4 -> V_104 , true , false ) ;
else {
if ( V_99 )
F_36 ( V_3 , & V_4 -> V_95 [ V_99 ] ,
true , false ) ;
if ( V_4 -> V_96 || ! V_4 -> V_102 . V_74 )
F_36 ( V_3 , & V_4 -> V_103 ,
true , false ) ;
else
F_36 ( V_3 , & V_4 -> V_102 ,
true , false ) ;
}
F_60 ( V_3 ) ;
F_65 ( & V_4 -> V_6 ) ;
F_13 ( V_3 ) ;
F_66 ( V_3 ) ;
return 1 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
T_3 V_62 ;
V_62 = V_4 -> V_27 . V_28 [ 0 ] ;
V_41 = F_68 ( V_4 , & V_168 ) ;
if ( V_41 == NULL )
return - V_46 ;
V_41 -> V_48 = V_169 | V_62 ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ ) {
struct V_33 * V_113 ;
struct V_170 V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_172 = V_173 ;
sprintf ( V_171 . V_40 , L_1 , V_4 -> V_174 [ V_53 ] ) ;
V_113 = F_70 ( V_3 , V_171 . V_40 ) ;
if ( V_113 )
F_71 ( V_3 -> V_175 -> V_176 ,
V_177 ,
& V_113 -> V_171 ) ;
}
}
static void F_72 ( struct V_2 * V_3 , int V_178 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 = V_178 ? V_179 : V_180 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ ) {
if ( V_4 -> V_181 [ V_53 ] < 0 )
continue;
F_73 ( V_3 , V_4 -> V_79 ,
V_60 , V_4 -> V_181 [ V_53 ] ,
V_179 , V_44 ) ;
}
}
static bool F_46 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ )
if ( V_4 -> V_182 [ V_53 ] == V_85 )
return true ;
return false ;
}
static int F_74 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
* V_36 -> V_147 . integer . V_147 = V_4 -> V_119 ;
return 0 ;
}
static int F_75 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_183 = * V_36 -> V_147 . integer . V_147
? V_184 : V_185 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ ) {
T_3 V_62 = V_4 -> V_182 [ V_53 ] ;
unsigned int V_130 ;
V_130 = F_76 ( V_3 , V_62 , 0 ,
V_186 , 0 ) ;
V_130 &= ~ ( V_185 | V_184 ) ;
V_130 |= V_183 ;
F_7 ( V_3 , V_62 , 0 ,
V_87 ,
V_130 ) ;
if ( V_183 == V_184 ) {
F_72 ( V_3 , 1 ) ;
F_69 ( V_3 ) ;
}
}
V_4 -> V_119 = * V_36 -> V_147 . integer . V_147 ;
F_13 ( V_3 ) ;
return 1 ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_94 )
return 0 ;
if ( ! F_68 ( V_4 , & V_187 ) )
return - V_46 ;
return 0 ;
}
static bool F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_188 * V_189 ;
int V_53 , V_164 , V_190 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_191 ; V_53 ++ ) {
V_189 = & V_4 -> V_192 [ V_53 ] ;
for ( V_164 = 0 ; V_164 < 2 ; V_164 ++ ) {
V_190 = F_79 ( V_3 , V_189 -> V_62 , V_164 , V_189 -> V_63 ,
V_189 -> V_43 ) ;
if ( ! ( V_190 & V_179 ) && V_190 > 0 )
return false ;
}
}
return true ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_70 ;
unsigned int V_193 , V_130 ;
V_70 = F_78 ( V_3 ) && ( V_4 -> V_157 != 0 ) ;
switch ( V_4 -> V_7 ) {
case V_18 :
case V_20 :
V_193 = 0xf70 ;
V_130 = V_70 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_22 :
case V_23 :
V_193 = 0xf73 ;
V_130 = V_70 ? 0x51 : 0xe1 ;
break;
case V_21 :
V_193 = 0xf73 ;
V_130 = V_70 ? 0x01 : 0x1d ;
break;
case V_24 :
case V_25 :
case V_26 :
V_193 = 0xf93 ;
V_130 = V_70 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_194 , 0 , V_193 , V_130 ) ;
}
static void F_80 ( struct V_2 * V_3 , int V_195 , bool V_196 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_196 )
V_4 -> V_157 |= V_195 ;
else
V_4 -> V_157 &= ~ V_195 ;
F_17 ( V_3 ) ;
}
static int F_81 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_58 ;
V_4 -> V_151 . V_152 = V_110 -> V_93 + V_4 -> V_94 ;
V_4 -> V_151 . V_201 = V_4 -> V_151 . V_152 * 2 ;
F_80 ( V_3 , V_159 , true ) ;
V_58 = F_82 ( V_3 , & V_4 -> V_151 , V_200 ,
V_198 ) ;
if ( V_58 < 0 ) {
F_80 ( V_3 , V_159 , false ) ;
return V_58 ;
}
return 0 ;
}
static int F_83 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
F_80 ( V_3 , V_159 , false ) ;
return 0 ;
}
static int F_84 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_85 ( ! V_4 -> V_154 ) )
return - V_202 ;
F_80 ( V_3 , V_160 , true ) ;
return 0 ;
}
static int F_86 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
F_80 ( V_3 , V_160 , false ) ;
return 0 ;
}
static int F_87 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( & V_4 -> V_6 ) ;
F_59 ( V_4 ) ;
F_88 ( V_3 , & V_4 -> V_151 , V_203 ,
V_204 , V_200 ) ;
V_4 -> V_32 |= V_159 ;
V_4 -> V_165 = V_203 ;
V_4 -> V_166 = V_204 ;
F_65 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_89 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_101 )
F_62 ( V_3 , V_4 -> V_154 ,
V_203 , 0 , V_204 ) ;
V_4 -> V_32 |= V_160 ;
V_4 -> V_161 = V_203 ;
V_4 -> V_162 = V_204 ;
F_65 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_90 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( & V_4 -> V_6 ) ;
F_91 ( V_3 , & V_4 -> V_151 ) ;
V_4 -> V_32 &= ~ V_159 ;
F_65 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_92 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_101 )
F_62 ( V_3 , V_4 -> V_154 , 0 , 0 , 0 ) ;
V_4 -> V_32 &= ~ V_160 ;
F_65 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_93 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_94 ( V_3 , & V_4 -> V_151 ) ;
}
static int F_95 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_96 ( V_3 , & V_4 -> V_151 ) ;
}
static int F_97 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_98 ( V_3 , & V_4 -> V_151 ,
V_203 , V_204 , V_200 ) ;
}
static int F_99 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_100 ( V_3 , & V_4 -> V_151 ) ;
return 0 ;
}
static int F_101 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_62 ( V_3 , V_4 -> V_116 [ V_200 -> V_205 ] ,
V_203 , 0 , V_204 ) ;
return 0 ;
}
static int F_102 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_103 ( V_3 , V_4 -> V_116 [ V_200 -> V_205 ] ) ;
return 0 ;
}
static int F_104 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
unsigned int V_203 ,
unsigned int V_204 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_123 = V_4 -> V_118 [ V_4 -> V_124 [ 0 ] ] . V_123 ;
F_64 ( & V_4 -> V_6 ) ;
V_4 -> V_206 = V_4 -> V_116 [ V_123 ] ;
V_4 -> V_207 = V_203 ;
V_4 -> V_208 = V_204 ;
F_62 ( V_3 , V_4 -> V_206 , V_203 , 0 , V_204 ) ;
F_65 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_105 ( struct V_197 * V_198 ,
struct V_2 * V_3 ,
struct V_199 * V_200 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( & V_4 -> V_6 ) ;
F_103 ( V_3 , V_4 -> V_206 ) ;
V_4 -> V_206 = 0 ;
F_65 ( & V_4 -> V_6 ) ;
return 0 ;
}
static bool F_106 ( struct V_2 * V_3 , int V_167 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_123 = V_4 -> V_118 [ V_167 ] . V_123 ;
T_3 V_209 = V_4 -> V_116 [ V_123 ] ;
bool V_210 = false ;
F_64 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_206 && V_4 -> V_206 != V_209 ) {
F_61 ( V_3 , V_4 -> V_206 , 1 ) ;
V_4 -> V_206 = V_209 ;
F_62 ( V_3 , V_209 ,
V_4 -> V_207 , 0 ,
V_4 -> V_208 ) ;
V_210 = true ;
}
F_65 ( & V_4 -> V_6 ) ;
return V_210 ;
}
static int F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_33 * V_52 ;
int V_58 , V_53 ;
if ( V_4 -> F_13 )
if ( ! F_68 ( V_4 , & V_211 ) )
return - V_46 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_212 ; V_53 ++ ) {
V_58 = F_108 ( V_3 , V_4 -> V_213 [ V_53 ] ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( V_4 -> V_151 . V_214 ) {
V_58 = F_109 ( V_3 ,
V_4 -> V_151 . V_214 ,
V_4 -> V_151 . V_214 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_110 ( V_3 ,
& V_4 -> V_151 ) ;
if ( V_58 < 0 )
return V_58 ;
V_4 -> V_151 . V_215 = 1 ;
}
if ( V_4 -> V_216 ) {
V_58 = F_111 ( V_3 , V_4 -> V_216 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( ! F_70 ( V_3 , L_7 ) ) {
unsigned int V_217 [ 4 ] ;
F_112 ( V_3 , V_4 -> V_151 . V_158 [ 0 ] ,
V_82 , V_217 ) ;
V_58 = F_113 ( V_3 , L_7 ,
V_217 , V_218 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( ! F_70 ( V_3 , L_8 ) ) {
V_58 = F_113 ( V_3 , L_8 ,
NULL , V_219 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_52 = F_70 ( V_3 , L_9 ) ;
for ( V_53 = 0 ; V_52 && V_53 < V_52 -> V_146 ; V_53 ++ ) {
V_58 = F_114 ( V_3 , V_52 , V_53 , V_4 -> V_125 [ V_53 ] ) ;
if ( V_58 < 0 )
return V_58 ;
}
F_13 ( V_3 ) ;
F_17 ( V_3 ) ;
F_24 ( V_3 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_220 * V_221 = V_4 -> V_222 ;
V_3 -> V_223 = 0 ;
V_3 -> V_224 = V_221 ;
if ( V_4 -> V_151 . V_152 || V_4 -> V_115 ) {
snprintf ( V_4 -> V_225 ,
sizeof( V_4 -> V_225 ) ,
L_10 , V_3 -> V_226 ) ;
V_221 -> V_40 = V_4 -> V_225 ;
if ( V_4 -> V_151 . V_152 ) {
if ( ! V_4 -> V_227 )
V_4 -> V_227 =
& V_228 ;
V_221 -> V_229 [ V_230 ] =
* V_4 -> V_227 ;
V_221 -> V_229 [ V_230 ] . V_62 =
V_4 -> V_151 . V_158 [ 0 ] ;
V_221 -> V_229 [ V_230 ] . V_231 =
V_4 -> V_151 . V_201 ;
}
if ( ! V_4 -> V_232 ) {
if ( V_4 -> V_127 )
V_4 -> V_232 =
& V_233 ;
else
V_4 -> V_232 =
& V_234 ;
}
if ( V_4 -> V_115 ) {
V_221 -> V_229 [ V_235 ] =
* V_4 -> V_232 ;
V_221 -> V_229 [ V_235 ] . V_62 =
V_4 -> V_116 [ 0 ] ;
if ( ! V_4 -> V_127 )
V_221 -> V_229 [ V_235 ] . V_236 =
V_4 -> V_115 ;
}
V_3 -> V_223 ++ ;
V_221 ++ ;
}
if ( V_4 -> V_151 . V_214 || V_4 -> V_216 ) {
snprintf ( V_4 -> V_237 ,
sizeof( V_4 -> V_237 ) ,
L_11 , V_3 -> V_226 ) ;
V_221 -> V_40 = V_4 -> V_237 ;
V_221 -> V_238 = V_239 ;
if ( V_4 -> V_151 . V_214 ) {
if ( ! V_4 -> V_240 )
V_4 -> V_240 =
& V_241 ;
V_221 -> V_229 [ V_230 ] =
* V_4 -> V_240 ;
V_221 -> V_229 [ V_230 ] . V_62 =
V_4 -> V_151 . V_214 ;
}
if ( V_4 -> V_216 ) {
if ( ! V_4 -> V_242 )
V_4 -> V_242 =
& V_243 ;
V_221 -> V_229 [ V_235 ] =
* V_4 -> V_242 ;
V_221 -> V_229 [ V_235 ] . V_62 =
V_4 -> V_216 ;
}
V_3 -> V_223 ++ ;
V_221 ++ ;
}
if ( V_4 -> V_154 ) {
snprintf ( V_4 -> V_244 , sizeof( V_4 -> V_244 ) ,
L_12 , V_3 -> V_226 ) ;
V_221 -> V_40 = V_4 -> V_244 ;
V_221 -> V_229 [ V_230 ] = V_245 ;
V_221 -> V_229 [ V_230 ] . V_62 =
V_4 -> V_154 ;
V_3 -> V_223 ++ ;
V_221 ++ ;
}
return 0 ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_24 ( V_3 ) ;
F_6 ( V_4 ) ;
F_25 ( V_4 -> V_246 ) ;
F_25 ( V_4 -> V_247 ) ;
F_25 ( V_4 ) ;
}
static void F_117 ( struct V_2 * V_3 , int V_248 ,
T_3 * V_249 , bool V_178 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_248 ; V_53 ++ ) {
unsigned int V_130 = F_76 ( V_3 , V_249 [ V_53 ] , 0 ,
V_186 , 0 ) ;
if ( V_130 & V_185 )
continue;
if ( V_178 )
V_130 &= ~ V_184 ;
else
V_130 |= V_184 ;
F_7 ( V_3 , V_249 [ V_53 ] , 0 ,
V_87 , V_130 ) ;
}
}
static void F_118 ( struct V_2 * V_3 , int V_136 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_106 )
return;
if ( ! V_136 )
V_136 = F_52 ( V_3 ,
V_4 -> V_27 . V_250 [ 0 ] ) ;
F_117 ( V_3 , V_4 -> V_27 . V_106 ,
V_4 -> V_27 . V_251 ,
V_136 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
int V_136 = 0 ;
int V_252 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_101 && V_4 -> V_27 . V_28 [ 0 ] &&
( V_4 -> V_7 != V_15 || V_4 -> V_31 ) )
V_136 = F_52 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_4 -> V_119 )
V_252 = V_4 -> V_27 . V_93 + V_4 -> V_94 ;
else
V_252 = V_4 -> V_27 . V_93 ;
F_117 ( V_3 , V_252 , V_4 -> V_27 . V_250 , V_136 ) ;
F_118 ( V_3 , V_136 ) ;
}
static void F_119 ( struct V_2 * V_3 )
{
unsigned int V_253 ;
unsigned int V_254 ;
unsigned int V_255 ;
unsigned int V_256 ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_253 = F_76 ( V_3 , V_3 -> V_194 , 0 ,
V_257 , 0 ) & 0x03 ;
V_254 = ( F_76 ( V_3 , V_3 -> V_194 , 0 ,
0xF84 , 0 ) & 0x3F0000 ) >> 16 ;
V_255 = V_254 & 0x1F ;
V_256 = F_76 ( V_3 , 0x1A , 0 ,
V_258 ,
V_259 ) ;
if ( V_253 == 0x02 ) {
F_7 ( V_3 , V_4 -> V_27 . V_250 [ 0 ] , 0 ,
V_87 ,
V_98 ) ;
if ( V_254 & 0x20 ) {
if ( V_255 > V_256 )
V_255 = V_256 ;
F_73 ( V_3 , 0x1A , V_60 ,
0 , V_260 ,
V_256 - V_255 ) ;
} else {
F_73 ( V_3 , 0x1A , V_60 , 0 ,
V_260 ,
( ( V_256 + V_255 ) > 0x2A ) ? 0x2A :
( V_256 + V_255 ) ) ;
}
} else if ( ! ( V_253 & 0x02 ) ) {
F_7 ( V_3 , V_4 -> V_27 . V_250 [ 0 ] , 0 ,
V_87 ,
0 ) ;
}
}
static void F_120 ( struct V_2 * V_3 ,
unsigned int V_261 )
{
V_261 >>= 26 ;
if ( V_261 & V_262 )
F_13 ( V_3 ) ;
V_261 &= ~ V_262 ;
if ( V_261 == V_263 || V_261 == V_264 )
F_66 ( V_3 ) ;
else if ( V_261 == V_265 )
F_119 ( V_3 ) ;
}
static int F_121 ( struct V_2 * V_3 , T_4 V_266 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_122 ( struct V_2 * V_3 , T_3 V_62 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_123 ( V_3 , & V_4 -> V_267 , V_62 ) ;
}
static bool F_124 ( struct V_2 * V_3 , T_3 V_163 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_151 . V_152 ; V_53 ++ ) {
if ( V_4 -> V_151 . V_158 [ V_53 ] == V_163 )
return false ;
}
if ( V_4 -> V_154 == V_163 )
return false ;
return true ;
}
static bool F_125 ( struct V_2 * V_3 , T_3 V_62 ,
T_3 V_268 , int V_269 ,
struct V_68 * V_69 , int V_74 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_111 [ 8 ] ;
int V_53 , V_252 ;
if ( V_62 == V_4 -> V_79 ) {
if ( ! V_269 )
return false ;
V_269 = 2 ;
}
V_252 = F_47 ( V_3 , V_62 , V_111 , F_48 ( V_111 ) ) ;
for ( V_53 = 0 ; V_53 < V_252 ; V_53 ++ ) {
if ( F_49 ( F_30 ( V_3 , V_111 [ V_53 ] ) ) != V_270 )
continue;
if ( V_111 [ V_53 ] == V_268 || F_124 ( V_3 , V_111 [ V_53 ] ) ) {
if ( ! ( V_4 -> V_79 && V_269 == 1 ) )
goto V_271;
}
}
if ( V_74 >= V_272 )
return false ;
for ( V_53 = 0 ; V_53 < V_252 ; V_53 ++ ) {
unsigned int type ;
type = F_49 ( F_30 ( V_3 , V_111 [ V_53 ] ) ) ;
if ( type == V_270 )
continue;
if ( F_125 ( V_3 , V_111 [ V_53 ] , V_268 ,
V_269 , V_69 , V_74 + 1 ) )
goto V_271;
}
return false ;
V_271:
V_69 -> V_69 [ V_69 -> V_74 ] = V_111 [ V_53 ] ;
V_69 -> V_43 [ V_69 -> V_74 ] = V_53 ;
if ( V_252 > 1 && F_49 ( F_30 ( V_3 , V_62 ) ) != V_273 )
V_69 -> V_77 [ V_69 -> V_74 ] = 1 ;
V_69 -> V_74 ++ ;
return true ;
}
static bool F_126 ( struct V_2 * V_3 , T_3 V_62 ,
T_3 V_268 , int V_269 ,
struct V_68 * V_69 )
{
if ( F_125 ( V_3 , V_62 , V_268 , V_269 , V_69 , 1 ) ) {
V_69 -> V_69 [ V_69 -> V_74 ] = V_62 ;
V_69 -> V_74 ++ ;
F_127 ( L_13 ,
V_69 -> V_74 , V_69 -> V_69 [ 0 ] , V_69 -> V_69 [ 1 ] ,
V_69 -> V_69 [ 2 ] , V_69 -> V_69 [ 3 ] , V_69 -> V_69 [ 4 ] ) ;
return true ;
}
return false ;
}
static int F_128 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_53 , V_274 ;
T_3 V_62 ;
V_4 -> V_151 . V_158 = V_4 -> V_275 ;
V_274 = 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_93 ; V_53 ++ ) {
T_3 V_163 = 0 ;
V_62 = V_110 -> V_250 [ V_53 ] ;
if ( ! V_62 )
continue;
if ( F_126 ( V_3 , V_62 , 0 , 0 , & V_4 -> V_95 [ V_53 ] ) )
V_163 = V_4 -> V_95 [ V_53 ] . V_69 [ 0 ] ;
if ( ! V_53 && F_126 ( V_3 , V_62 , V_163 , 1 ,
& V_4 -> V_97 ) )
V_163 = V_4 -> V_97 . V_69 [ 0 ] ;
if ( V_163 ) {
V_4 -> V_275 [ V_53 ] = V_163 ;
V_274 ++ ;
}
}
if ( ! V_4 -> V_95 [ 0 ] . V_74 && V_4 -> V_97 . V_74 ) {
V_4 -> V_95 [ 0 ] = V_4 -> V_97 ;
V_4 -> V_97 . V_74 = 0 ;
}
V_4 -> V_151 . V_152 = V_274 ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 , const char * V_276 ,
int V_277 , bool V_278 , struct V_68 * V_69 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_40 [ 32 ] ;
T_3 V_163 , V_85 , V_279 , V_62 ;
int V_58 ;
V_163 = V_278 ? V_69 -> V_69 [ 0 ] : 0 ;
V_85 = V_69 -> V_69 [ V_69 -> V_74 - 1 ] ;
V_279 = V_69 -> V_74 > 1 ? V_69 -> V_69 [ 1 ] : 0 ;
if ( V_163 && F_29 ( V_3 , V_163 , V_82 , V_280 ) )
V_62 = V_163 ;
else if ( F_29 ( V_3 , V_85 , V_82 , V_280 ) )
V_62 = V_85 ;
else if ( F_29 ( V_3 , V_279 , V_82 , V_280 ) )
V_62 = V_279 ;
else
V_62 = 0 ;
if ( V_62 ) {
sprintf ( V_40 , L_1 , V_276 ) ;
V_58 = F_130 ( V_4 , V_59 , V_40 ,
F_28 ( V_62 , V_277 , 0 , V_82 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_69 -> V_80 = V_62 ;
}
if ( V_163 && F_29 ( V_3 , V_163 , V_82 , V_90 ) )
V_62 = V_163 ;
else if ( F_29 ( V_3 , V_85 , V_82 , V_90 ) )
V_62 = V_85 ;
else if ( F_29 ( V_3 , V_279 , V_82 , V_90 ) )
V_62 = V_279 ;
else
V_62 = 0 ;
if ( V_62 ) {
sprintf ( V_40 , L_2 , V_276 ) ;
V_58 = F_130 ( V_4 , V_281 , V_40 ,
F_28 ( V_62 , V_277 , 0 , V_82 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_69 -> V_81 = V_62 ;
}
return 0 ;
}
static void F_131 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_27 ;
struct V_282 * V_283 = V_110 -> V_118 ;
int V_53 , V_284 , V_252 , V_285 ;
int V_249 [ V_286 ] ;
for ( V_285 = V_287 ; V_285 >= V_288 ; V_285 -- ) {
V_252 = 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
unsigned int V_289 ;
if ( V_283 [ V_53 ] . type > V_290 )
continue;
V_289 = F_51 ( V_3 , V_283 [ V_53 ] . V_85 ) ;
if ( F_132 ( V_289 ) != V_285 )
continue;
for ( V_284 = 0 ; V_284 < V_252 ; V_284 ++ )
if ( V_283 [ V_249 [ V_284 ] ] . type < V_283 [ V_53 ] . type ) {
memmove ( V_249 + V_284 + 1 , V_249 + V_284 ,
( V_252 - V_284 ) * sizeof( int ) ) ;
break;
}
V_249 [ V_284 ] = V_53 ;
V_252 ++ ;
}
if ( V_110 -> V_93 + V_252 < 3 )
continue;
for ( V_53 = 0 ; V_53 < V_252 ; V_53 ++ ) {
T_3 V_85 = V_283 [ V_249 [ V_53 ] ] . V_85 ;
V_4 -> V_182 [ V_4 -> V_94 ++ ] = V_85 ;
V_110 -> V_250 [ V_110 -> V_93 ++ ] = V_85 ;
if ( V_110 -> V_93 == 3 )
break;
}
return;
}
}
static void F_133 ( struct V_68 * V_76 , struct V_68 * V_75 )
{
V_76 -> V_80 = V_75 -> V_80 ;
V_76 -> V_81 = V_75 -> V_81 ;
}
static int F_134 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_27 ;
struct V_68 * V_69 ;
static const char * const V_291 [ 4 ] = {
L_14 , L_15 , L_16 , L_17
} ;
int V_53 , V_43 , V_58 ;
int V_292 ;
V_292 = V_110 -> V_93 ;
if ( V_110 -> V_93 == 1 )
F_131 ( V_3 ) ;
V_58 = F_128 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_151 . V_152 < 3 ) {
V_4 -> V_94 = 0 ;
V_110 -> V_93 = V_292 ;
}
for ( V_53 = 0 ; V_53 < V_110 -> V_93 ; V_53 ++ ) {
T_3 V_85 , V_163 ;
V_85 = V_110 -> V_250 [ V_53 ] ;
V_163 = V_4 -> V_151 . V_158 [ V_53 ] ;
if ( ! V_85 || ! V_163 )
continue;
V_69 = V_4 -> V_95 + V_53 ;
if ( V_53 == V_293 ) {
V_58 = F_129 ( V_3 , L_18 , 1 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_129 ( V_3 , L_19 , 2 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
} else {
const char * V_276 = V_291 [ V_53 ] ;
if ( V_110 -> V_294 == V_295 &&
V_110 -> V_93 == 1 )
V_276 = L_20 ;
V_58 = F_129 ( V_3 , V_276 , 3 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( V_69 != V_4 -> V_95 + V_53 )
F_133 ( & V_4 -> V_95 [ V_53 ] , V_69 ) ;
if ( V_69 == V_4 -> V_95 && V_4 -> V_97 . V_74 )
F_133 ( & V_4 -> V_97 , V_69 ) ;
}
V_43 = F_135 ( V_3 , V_4 -> V_79 ,
V_4 -> V_151 . V_158 [ 0 ] ) ;
if ( V_43 >= 0 ) {
const char * V_40 ;
V_40 = V_4 -> V_97 . V_74 ?
L_21 : L_22 ;
V_58 = F_130 ( V_4 , V_59 , V_40 ,
F_28 ( V_4 -> V_79 , 3 ,
V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_40 = V_4 -> V_97 . V_74 ?
L_23 : L_24 ;
V_58 = F_130 ( V_4 , V_281 , V_40 ,
F_28 ( V_4 -> V_79 , 3 ,
V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_110 -> V_93 = V_292 ;
return 0 ;
}
static int F_136 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
bool V_278 ;
int V_53 , V_58 ;
if ( ! V_85 )
return 0 ;
if ( ! F_126 ( V_3 , V_85 , 0 , 0 , & V_4 -> V_104 ) ) {
for ( V_53 = V_296 ; V_53 >= V_293 ; V_53 -- ) {
if ( V_53 < V_4 -> V_151 . V_152 &&
F_126 ( V_3 , V_85 ,
V_4 -> V_151 . V_158 [ V_53 ] , 0 ,
& V_4 -> V_104 ) ) {
V_4 -> V_100 = V_53 ;
break;
}
}
}
if ( V_4 -> V_104 . V_74 ) {
V_4 -> V_154 = V_4 -> V_104 . V_69 [ 0 ] ;
if ( ! V_4 -> V_100 )
V_4 -> V_102 = V_4 -> V_104 ;
}
if ( ! V_4 -> V_102 . V_74 )
F_126 ( V_3 , V_85 ,
V_4 -> V_151 . V_158 [ V_297 ] , 0 ,
& V_4 -> V_102 ) ;
if ( ! F_126 ( V_3 , V_85 , V_4 -> V_151 . V_158 [ V_297 ] ,
1 , & V_4 -> V_103 ) && ! V_4 -> V_102 . V_74 )
return 0 ;
if ( V_4 -> V_102 . V_74 ) {
V_69 = & V_4 -> V_102 ;
V_278 = true ;
} else {
V_69 = & V_4 -> V_103 ;
V_278 = false ;
}
V_58 = F_129 ( V_3 , L_25 , 3 , V_278 , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_278 )
F_133 ( & V_4 -> V_103 , V_69 ) ;
else
F_133 ( & V_4 -> V_102 , V_69 ) ;
if ( V_4 -> V_104 . V_74 )
F_133 ( & V_4 -> V_104 , V_69 ) ;
return 0 ;
}
static int F_137 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
bool V_278 ;
T_3 V_85 , V_163 = 0 ;
int V_58 ;
V_85 = V_4 -> V_27 . V_251 [ 0 ] ;
if ( ! V_4 -> V_27 . V_106 || ! V_85 )
return 0 ;
if ( F_126 ( V_3 , V_85 , 0 , 0 , & V_4 -> V_107 ) )
V_163 = V_4 -> V_107 . V_69 [ 0 ] ;
if ( ! V_163 )
F_126 ( V_3 , V_85 ,
V_4 -> V_151 . V_158 [ V_297 ] , 0 ,
& V_4 -> V_107 ) ;
if ( ! F_126 ( V_3 , V_85 , V_4 -> V_151 . V_158 [ V_297 ] ,
1 , & V_4 -> V_108 ) && ! V_163 )
return 0 ;
if ( ! V_4 -> V_97 . V_74 && V_4 -> V_108 . V_74 )
V_163 = 0 ;
V_4 -> V_298 = V_163 ;
V_4 -> V_151 . V_299 [ 0 ] = V_163 ;
if ( V_163 ) {
V_69 = & V_4 -> V_107 ;
V_278 = true ;
} else {
V_69 = & V_4 -> V_108 ;
V_278 = false ;
}
V_58 = F_129 ( V_3 , L_20 , 3 , V_278 , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_278 )
F_133 ( & V_4 -> V_108 , V_69 ) ;
else
F_133 ( & V_4 -> V_107 , V_69 ) ;
return 0 ;
}
static int F_138 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_147 . V_148 . V_150 [ 0 ] = V_4 -> V_96 ;
return 0 ;
}
static void F_139 ( struct V_2 * V_3 , int V_300 ,
struct V_68 * V_301 , struct V_68 * V_302 )
{
if ( V_300 ) {
F_36 ( V_3 , V_301 , false , false ) ;
F_36 ( V_3 , V_302 , true , false ) ;
} else {
F_36 ( V_3 , V_302 , false , false ) ;
F_36 ( V_3 , V_301 , true , false ) ;
}
}
static int F_140 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = V_36 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_44 == V_4 -> V_96 )
return 0 ;
V_4 -> V_96 = V_44 ;
F_139 ( V_3 , V_44 , & V_4 -> V_95 [ 0 ] , & V_4 -> V_97 ) ;
if ( ! V_4 -> V_101 ) {
F_139 ( V_3 , V_44 , & V_4 -> V_102 ,
& V_4 -> V_103 ) ;
}
F_139 ( V_3 , V_44 , & V_4 -> V_107 ,
& V_4 -> V_108 ) ;
return 1 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_79 || ! V_4 -> V_97 . V_74 )
return 0 ;
if ( ! F_68 ( V_4 , & V_303 ) )
return - V_46 ;
return 0 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_62 = V_3 -> V_304 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_305 ; V_53 ++ , V_62 ++ ) {
unsigned int V_306 = F_30 ( V_3 , V_62 ) ;
if ( F_49 ( V_306 ) != V_307 )
continue;
if ( V_306 & V_308 )
continue;
if ( ! ( V_306 & V_309 ) )
continue;
if ( V_4 -> V_115 >= F_48 ( V_4 -> V_116 ) )
return - V_46 ;
V_4 -> V_116 [ V_4 -> V_115 ++ ] = V_62 ;
}
return 0 ;
}
static int F_143 ( struct V_33 * V_34 ,
struct V_142 * V_143 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_143 -> type = V_145 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . V_148 . V_149 = V_4 -> V_117 ;
if ( V_143 -> V_147 . V_148 . V_150 >= V_4 -> V_117 )
V_143 -> V_147 . V_148 . V_150 = V_4 -> V_117 - 1 ;
strcpy ( V_143 -> V_147 . V_148 . V_40 ,
V_4 -> V_118 [ V_143 -> V_147 . V_148 . V_150 ] . V_310 ) ;
return 0 ;
}
static int F_144 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 = F_145 ( V_34 , & V_36 -> V_171 ) ;
V_36 -> V_147 . V_148 . V_150 [ 0 ] = V_4 -> V_124 [ V_43 ] ;
return 0 ;
}
static int F_146 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 = F_145 ( V_34 , & V_36 -> V_171 ) ;
T_3 V_311 ;
int V_167 ;
V_167 = V_36 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_167 < 0 || V_167 >= V_4 -> V_117 )
return - V_202 ;
if ( V_4 -> V_124 [ V_43 ] == V_167 )
return 0 ;
V_4 -> V_124 [ V_43 ] = V_167 ;
if ( V_4 -> V_127 ) {
int V_123 = V_4 -> V_118 [ V_167 ] . V_123 ;
V_311 = V_4 -> V_125 [ V_123 ] ;
F_106 ( V_3 , V_167 ) ;
} else {
V_311 = V_4 -> V_125 [ V_43 ] ;
if ( F_85 ( ! V_311 ) )
return - V_202 ;
}
if ( V_311 ) {
if ( F_76 ( V_3 , V_311 , 0 ,
V_312 , 0x00 ) != V_139 )
F_7 ( V_3 , V_311 , 0 ,
V_141 , V_139 ) ;
F_7 ( V_3 , V_311 , 0 ,
V_78 ,
V_4 -> V_118 [ V_167 ] . V_126 ) ;
}
F_13 ( V_3 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 , int V_146 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
if ( V_4 -> V_117 <= 1 || ! V_146 )
return 0 ;
V_41 = F_68 ( V_4 , & V_313 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_146 = V_146 ;
return 0 ;
}
static void F_148 ( struct V_1 * V_4 , T_3 V_302 , int V_43 )
{
struct V_188 * V_51 ;
if ( V_4 -> V_191 >= F_48 ( V_4 -> V_192 ) - 1 )
return;
V_51 = V_4 -> V_192 + V_4 -> V_191 ;
V_51 -> V_62 = V_302 ;
V_51 -> V_63 = V_60 ;
V_51 -> V_43 = V_43 ;
V_4 -> V_191 ++ ;
V_4 -> V_267 . V_314 = V_4 -> V_192 ;
}
static bool F_149 ( struct V_2 * V_3 , T_3 V_75 ,
T_3 V_76 )
{
return F_150 ( V_3 , V_75 , V_76 , 1 ) >= 0 ;
}
static bool F_151 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_315 , V_43 ;
V_4 -> V_118 [ V_4 -> V_117 ] . V_123 = - 1 ;
V_4 -> V_118 [ V_4 -> V_117 ] . V_85 = V_85 ;
for ( V_315 = 0 ; V_315 < V_4 -> V_115 ; V_315 ++ ) {
if ( V_4 -> V_125 [ V_315 ] ) {
V_43 = F_135 ( V_3 , V_4 -> V_125 [ V_315 ] ,
V_85 ) ;
if ( V_43 < 0 )
continue;
V_4 -> V_118 [ V_4 -> V_117 ] . V_126 = V_43 ;
} else {
if ( ! F_149 ( V_3 , V_4 -> V_116 [ V_315 ] , V_85 ) )
continue;
}
V_4 -> V_118 [ V_4 -> V_117 ] . V_123 = V_315 ;
if ( ! V_4 -> V_127 &&
V_4 -> V_117 > 0 && V_4 -> V_118 [ 0 ] . V_123 != V_315 ) {
F_152 ( V_316
L_26 ) ;
V_4 -> V_127 = 1 ;
}
return true ;
}
return false ;
}
static int F_153 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_53 , V_58 ;
V_58 = F_142 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_154 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
if ( F_151 ( V_3 , V_110 -> V_118 [ V_53 ] . V_85 ) )
V_4 -> V_118 [ V_4 -> V_117 ++ ] . V_310 =
F_155 ( V_3 , V_110 , V_53 ) ;
}
if ( V_4 -> V_79 &&
F_151 ( V_3 , V_4 -> V_79 ) )
V_4 -> V_118 [ V_4 -> V_117 ++ ] . V_310 = L_27 ;
return 0 ;
}
static int F_156 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
const char * V_317 = NULL ;
int V_56 = 0 ;
int V_53 , V_284 , V_58 , V_43 ;
if ( ! V_4 -> V_79 )
return 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
T_3 V_85 = V_110 -> V_118 [ V_53 ] . V_85 ;
const char * V_310 = F_155 ( V_3 , V_110 , V_53 ) ;
if ( V_317 && ! strcmp ( V_310 , V_317 ) )
V_56 ++ ;
else
V_56 = 0 ;
V_317 = V_310 ;
V_43 = F_135 ( V_3 , V_4 -> V_79 , V_85 ) ;
if ( V_43 >= 0 ) {
V_58 = F_27 ( V_4 , V_310 , V_56 ,
V_43 , V_4 -> V_79 ) ;
if ( V_58 < 0 )
return V_58 ;
F_148 ( V_4 , V_4 -> V_79 , V_43 ) ;
}
for ( V_284 = 0 ; V_284 < V_4 -> V_94 ; V_284 ++ ) {
if ( V_4 -> V_182 [ V_284 ] == V_85 ) {
V_4 -> V_181 [ V_284 ] = V_43 ;
V_4 -> V_174 [ V_284 ] = V_310 ;
break;
}
}
}
return 0 ;
}
static int F_157 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_53 , V_58 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
T_3 V_85 = V_110 -> V_118 [ V_53 ] . V_85 ;
unsigned int V_65 ;
const char * V_310 ;
char V_40 [ 32 ] ;
if ( V_110 -> V_118 [ V_53 ] . type != V_120 )
continue;
V_65 = F_31 ( V_3 , V_85 , V_60 ) ;
if ( V_65 == - 1 || ! ( V_65 & V_280 ) )
continue;
V_310 = F_155 ( V_3 , V_110 , V_53 ) ;
snprintf ( V_40 , sizeof( V_40 ) , L_28 , V_310 ) ;
V_58 = F_130 ( V_4 , V_59 , V_40 ,
F_28 ( V_85 , 3 , 0 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
return 0 ;
}
static int F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_58 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ ) {
T_3 V_209 = V_4 -> V_116 [ V_53 ] ;
V_58 = F_22 ( V_4 , V_59 ,
L_29 , V_53 ,
F_28 ( V_209 , 3 , 0 ,
V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_22 ( V_4 , V_281 ,
L_30 , V_53 ,
F_28 ( V_209 , 3 , 0 ,
V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ )
if ( ! V_4 -> V_125 [ V_53 ] )
break;
V_58 = F_147 ( V_3 , V_53 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_159 ( struct V_1 * V_4 , struct V_318 * * V_319 ,
struct V_320 * V_321 )
{
struct V_318 * V_113 ;
int V_53 ;
V_113 = F_2 ( sizeof( * V_113 ) + sizeof( long ) * 4 , V_5 ) ;
if ( ! V_113 )
return - V_46 ;
V_113 -> V_321 = V_321 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ )
V_113 -> V_322 [ V_53 ] =
F_28 ( V_4 -> V_116 [ V_53 ] , 3 , 0 , V_60 ) ;
* V_319 = V_113 ;
return 0 ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
int V_58 ;
V_58 = F_159 ( V_4 , & V_4 -> V_246 , & V_323 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_159 ( V_4 , & V_4 -> V_247 , & V_324 ) ;
if ( V_58 < 0 )
return V_58 ;
V_41 = F_68 ( V_4 , & V_325 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_50 = ( long ) V_4 -> V_246 ;
V_41 = F_68 ( V_4 , & V_326 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_50 = ( long ) V_4 -> V_247 ;
V_58 = F_147 ( V_3 , 1 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_58 ;
V_58 = F_153 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_127 )
V_58 = F_160 ( V_3 ) ;
else
V_58 = F_158 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_156 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_157 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static void F_162 ( struct V_2 * V_3 , T_3 V_62 )
{
unsigned int V_131 ;
unsigned char V_327 ;
V_131 = F_51 ( V_3 , V_62 ) ;
V_327 = ( unsigned char ) F_163 ( V_131 ) ;
V_327 = ( V_327 << 4 ) | F_164 ( V_131 ) ;
if ( F_53 ( V_131 ) == V_138
&& ( V_327 == 0xf0 || V_327 == 0xff ) ) {
V_131 = V_131 & ( ~ ( V_328 << 30 ) ) ;
F_165 ( V_3 , V_62 , V_131 ) ;
}
return;
}
static int F_166 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_36 -> V_147 . integer . V_147 [ 0 ] = V_4 -> V_31 ;
return 0 ;
}
static int F_167 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_44 = ! ! V_36 -> V_147 . integer . V_147 [ 0 ] ;
if ( V_4 -> V_31 == V_44 )
return 0 ;
V_4 -> V_31 = V_44 ;
if ( V_4 -> V_31 &&
F_168 ( V_3 , L_31 ) != 1 ) {
F_72 ( V_3 , 1 ) ;
F_69 ( V_3 ) ;
}
F_66 ( V_3 ) ;
F_9 ( V_4 ) ;
return 1 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_58 ;
V_58 = F_170 ( V_3 , & V_4 -> V_27 , NULL ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! V_4 -> V_27 . V_93 && ! V_4 -> V_27 . V_28 [ 0 ] )
return - V_202 ;
V_58 = F_134 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_136 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_137 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_141 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_161 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_4 -> V_151 . V_201 = V_4 -> V_151 . V_152 * 2 ;
F_171 ( V_3 ) ;
F_172 ( V_3 ) ;
if ( V_4 -> V_42 . V_51 )
V_4 -> V_213 [ V_4 -> V_212 ++ ] = V_4 -> V_42 . V_51 ;
if ( V_4 -> V_154 && V_4 -> V_103 . V_74 ) {
V_58 = F_67 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_58 = F_77 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_329 [ 0 ] )
V_3 -> V_329 = V_4 -> V_329 ;
return 1 ;
}
static void F_173 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_151 . V_214 )
F_38 ( V_3 , V_4 -> V_27 . V_330 [ 0 ] , V_98 ) ;
if ( V_4 -> V_329 [ 0 ] )
F_38 ( V_3 , V_4 -> V_27 . V_330 [ 1 ] , V_98 ) ;
}
static void F_174 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_216 )
return;
F_7 ( V_3 , V_4 -> V_27 . V_331 , 0 ,
V_87 , V_122 ) ;
}
static void F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_27 ;
unsigned int V_332 ;
int V_53 ;
if ( V_110 -> V_28 [ 0 ] && F_176 ( V_3 , V_110 -> V_28 [ 0 ] ) )
F_7 ( V_3 , V_110 -> V_28 [ 0 ] , 0 ,
V_333 ,
V_334 | V_263 | V_262 ) ;
if ( V_110 -> V_251 [ 0 ] )
V_332 = V_264 ;
else
V_332 = 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_93 ; V_53 ++ ) {
if ( V_110 -> V_250 [ V_53 ] &&
F_176 ( V_3 , V_110 -> V_250 [ V_53 ] ) )
F_7 ( V_3 , V_110 -> V_250 [ V_53 ] , 0 ,
V_333 ,
V_334 | V_332 | V_262 ) ;
}
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
if ( F_176 ( V_3 , V_110 -> V_118 [ V_53 ] . V_85 ) )
F_7 ( V_3 , V_110 -> V_118 [ V_53 ] . V_85 , 0 ,
V_333 ,
V_334 | V_262 ) ;
}
}
static int F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_335 ; V_53 ++ )
F_178 ( V_3 , V_4 -> V_336 [ V_53 ] ) ;
F_41 ( V_3 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
F_173 ( V_3 ) ;
F_174 ( V_3 ) ;
F_175 ( V_3 ) ;
F_66 ( V_3 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static void F_179 ( struct V_337 * V_338 )
{
struct V_1 * V_4 = F_180 ( V_338 , struct V_1 ,
V_30 . V_338 ) ;
if ( V_4 -> V_7 != V_15 )
return;
if ( V_4 -> V_339
!= F_52 ( V_4 -> V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ) {
V_4 -> V_339 ^= 1 ;
F_66 ( V_4 -> V_3 ) ;
}
if ( V_4 -> V_31 )
F_11 ( & V_4 -> V_30 ,
F_12 ( 100 ) ) ;
}
static int F_154 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_62 , V_111 [ 8 ] ;
unsigned int type ;
int V_53 , V_340 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ ) {
V_62 = V_4 -> V_116 [ V_53 ] ;
while ( V_62 ) {
type = F_49 ( F_30 ( V_3 , V_62 ) ) ;
if ( type == V_128 )
break;
V_340 = F_47 ( V_3 , V_62 , V_111 ,
F_48 ( V_111 ) ) ;
if ( V_340 <= 0 )
break;
if ( V_340 > 1 ) {
V_4 -> V_125 [ V_53 ] = V_62 ;
break;
}
V_62 = V_111 [ 0 ] ;
}
}
return 0 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x17 ;
F_162 ( V_3 , V_341 ) ;
F_162 ( V_3 , V_342 ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
if ( ! F_68 ( V_4 , & V_343 ) )
return - V_46 ;
if ( V_3 -> V_11 == 0x11061708 )
V_4 -> V_227 = & V_344 ;
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_345 ;
V_3 -> V_346 = V_347 ;
F_182 ( & V_4 -> V_30 , F_179 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x18 ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_3 -> V_346 = V_347 ;
return 0 ;
}
static void F_184 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_348 ;
unsigned int V_130 ;
int V_349 = 0 ;
if ( ( V_4 -> V_7 != V_20 ) &&
( V_3 -> V_11 != 0x11064397 ) )
V_349 = 1 ;
V_348 =
( F_76 ( V_3 , 0x17 , 0 , V_350 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x1a , & V_130 ) ;
F_50 ( V_3 , 0x1b , & V_130 ) ;
F_50 ( V_3 , 0x1e , & V_130 ) ;
if ( V_348 )
V_130 = V_139 ;
F_7 ( V_3 , 0x17 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x13 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x14 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x19 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x1b , & V_130 ) ;
F_7 ( V_3 , 0x18 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x11 , 0 , V_141 , V_130 ) ;
if ( V_349 ) {
V_130 = V_140 ;
F_50 ( V_3 , 0x22 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x1a , & V_130 ) ;
F_7 ( V_3 , 0x26 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x24 , 0 ,
V_141 , V_130 ) ;
} else if ( V_3 -> V_11 == 0x11064397 ) {
V_130 = V_140 ;
F_50 ( V_3 , 0x23 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x1a , & V_130 ) ;
F_7 ( V_3 , 0x27 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x25 , 0 ,
V_141 , V_130 ) ;
}
V_130 = V_140 ;
F_50 ( V_3 , 0x1c , & V_130 ) ;
F_50 ( V_3 , 0x1d , & V_130 ) ;
if ( V_349 )
F_50 ( V_3 , 0x23 , & V_130 ) ;
F_7 ( V_3 , 0x16 , 0 , V_141 ,
V_348 ? V_139 : V_130 ) ;
F_7 ( V_3 , 0x10 , 0 , V_141 , V_130 ) ;
if ( V_349 ) {
F_7 ( V_3 , 0x25 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x27 , 0 ,
V_141 , V_130 ) ;
} else if ( V_3 -> V_11 == 0x11064397 && V_4 -> V_101 )
F_7 ( V_3 , 0x25 , 0 ,
V_141 , V_130 ) ;
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
if ( F_4 ( V_3 ) == V_8 )
return F_186 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_3 -> V_346 = V_347 ;
V_4 -> F_13 = F_184 ;
return 0 ;
}
static void F_171 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_27 . V_351 ; V_53 ++ ) {
T_3 V_62 ;
int V_111 ;
V_62 = V_4 -> V_27 . V_330 [ V_53 ] ;
if ( ! V_62 )
continue;
V_111 = F_47 ( V_3 , V_62 , & V_62 , 1 ) ;
if ( V_111 < 1 )
continue;
if ( ! V_4 -> V_151 . V_214 )
V_4 -> V_151 . V_214 = V_62 ;
else {
V_4 -> V_329 [ 0 ] = V_62 ;
break;
}
}
}
static void F_172 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_352 ;
int V_53 , V_58 ;
if ( ! V_4 -> V_27 . V_331 )
return;
V_352 = V_3 -> V_304 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_305 ; V_53 ++ , V_352 ++ ) {
unsigned int V_306 = F_30 ( V_3 , V_352 ) ;
if ( F_49 ( V_306 ) != V_307 )
continue;
if ( ! ( V_306 & V_308 ) )
continue;
if ( ! ( V_306 & V_309 ) )
continue;
V_58 = F_135 ( V_3 , V_352 ,
V_4 -> V_27 . V_331 ) ;
if ( V_58 >= 0 ) {
V_4 -> V_216 = V_352 ;
break;
}
}
}
static void F_187 ( struct V_2 * V_3 , T_3 V_85 ,
int V_353 , int V_354 , int V_355 )
{
F_188 ( V_3 , V_85 , V_60 ,
( V_353 << V_92 ) |
( V_354 << V_356 ) |
( V_355 << V_357 ) |
( 0 << V_358 ) ) ;
}
static int F_186 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
F_187 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_359 ;
V_3 -> V_346 = V_347 ;
if ( F_4 ( V_3 ) == V_8 ) {
F_25 ( V_3 -> V_226 ) ;
V_3 -> V_226 = F_21 ( L_32 , V_5 ) ;
snprintf ( V_3 -> V_175 -> V_176 -> V_360 ,
sizeof( V_3 -> V_175 -> V_176 -> V_360 ) ,
L_33 , V_3 -> V_361 , V_3 -> V_226 ) ;
}
if ( V_3 -> V_11 == 0x11064397 ) {
F_25 ( V_3 -> V_226 ) ;
V_3 -> V_226 = F_21 ( L_34 , V_5 ) ;
snprintf ( V_3 -> V_175 -> V_176 -> V_360 ,
sizeof( V_3 -> V_175 -> V_176 -> V_360 ) ,
L_33 , V_3 -> V_361 , V_3 -> V_226 ) ;
}
V_4 -> F_13 = F_184 ;
return 0 ;
}
static void F_189 ( struct V_2 * V_3 )
{
int V_348 =
F_76 ( V_3 , 0x13 , 0 , V_350 , 0x00 ) == 3 ;
unsigned int V_130 ;
V_130 = V_140 ;
F_50 ( V_3 , 0x14 , & V_130 ) ;
F_50 ( V_3 , 0x15 , & V_130 ) ;
F_50 ( V_3 , 0x18 , & V_130 ) ;
if ( V_348 )
V_130 = V_139 ;
F_7 ( V_3 , 0x13 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x12 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x1f , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x20 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x17 , & V_130 ) ;
F_50 ( V_3 , 0x16 , & V_130 ) ;
F_7 ( V_3 , 0x1a , 0 , V_141 ,
V_348 ? V_139 : V_130 ) ;
F_7 ( V_3 , 0x10 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x1d , 0 , V_141 , V_130 ) ;
}
static int F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x1a ;
F_188 ( V_3 , 0x1A , V_60 ,
( 0x17 << V_92 ) |
( 0x17 << V_356 ) |
( 0x5 << V_357 ) |
( 1 << V_358 ) ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_362 ;
V_3 -> V_346 = V_347 ;
V_4 -> F_13 = F_189 ;
return 0 ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_348 ;
unsigned int V_130 ;
V_348 =
F_76 ( V_3 , 0x1e , 0 , V_350 , 0x00 ) == 5 ;
V_130 = V_140 ;
F_50 ( V_3 , 0x29 , & V_130 ) ;
F_50 ( V_3 , 0x2a , & V_130 ) ;
F_50 ( V_3 , 0x2b , & V_130 ) ;
if ( V_348 )
V_130 = V_139 ;
F_7 ( V_3 , 0x1e , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x1f , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x10 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x11 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x27 , & V_130 ) ;
F_7 ( V_3 , 0x1a , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0xb , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x26 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x2b , & V_130 ) ;
F_7 ( V_3 , 0xa , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x24 , & V_130 ) ;
if ( ! V_4 -> V_101 )
F_50 ( V_3 , 0x28 , & V_130 ) ;
F_7 ( V_3 , 0x8 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x21 , 0 , V_141 ,
V_348 ? V_139 : V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x25 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x2a , & V_130 ) ;
F_7 ( V_3 , 0x9 , 0 , V_141 , V_130 ) ;
if ( V_4 -> V_101 ) {
V_130 = V_140 ;
F_50 ( V_3 , 0x28 , & V_130 ) ;
F_7 ( V_3 , 0x1b , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x34 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0xc , 0 ,
V_141 , V_130 ) ;
}
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_252 ;
T_3 V_111 [ 8 ] ;
T_3 V_62 ;
if ( ! V_4 -> V_79 )
return 0 ;
V_252 = F_47 ( V_3 , V_4 -> V_79 , V_111 ,
F_48 ( V_111 ) - 1 ) ;
for ( V_53 = 0 ; V_53 < V_252 ; V_53 ++ ) {
if ( F_49 ( F_30 ( V_3 , V_111 [ V_53 ] ) ) == V_270 )
return 0 ;
}
V_62 = V_3 -> V_304 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_305 ; V_53 ++ , V_62 ++ ) {
unsigned int V_65 = F_30 ( V_3 , V_62 ) ;
if ( F_49 ( V_65 ) == V_270 &&
! ( V_65 & V_308 ) ) {
V_111 [ V_252 ++ ] = V_62 ;
return F_193 ( V_3 ,
V_4 -> V_79 ,
V_252 , V_111 ) ;
}
}
return 0 ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_187 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_192 ( V_3 ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_363 ;
V_3 -> V_346 = V_347 ;
V_4 -> F_13 = F_191 ;
return 0 ;
}
static int F_195 ( struct V_33 * V_34 ,
struct V_142 * V_143 )
{
V_143 -> type = V_364 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . integer . V_365 = 0 ;
V_143 -> V_147 . integer . V_366 = 1 ;
return 0 ;
}
static int F_196 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
int V_47 = 0 ;
V_47 = F_76 ( V_3 , 0x26 , 0 ,
V_350 , 0 ) ;
if ( V_47 != - 1 )
* V_36 -> V_147 . integer . V_147 = V_47 ;
return 0 ;
}
static int F_197 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_47 = * V_36 -> V_147 . integer . V_147 ;
F_7 ( V_3 , 0x26 , 0 ,
V_78 , V_47 ) ;
V_4 -> V_367 = V_47 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_348 ;
unsigned int V_130 ;
unsigned int V_368 , V_136 ;
V_348 =
( F_76 ( V_3 , 0x17 , 0 ,
V_350 , 0x00 ) == 5 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x1a , & V_130 ) ;
F_50 ( V_3 , 0x1b , & V_130 ) ;
F_50 ( V_3 , 0x1e , & V_130 ) ;
if ( V_348 )
V_130 = V_139 ;
F_7 ( V_3 , 0x17 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x13 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x1e , & V_130 ) ;
if ( V_4 -> V_367 )
F_50 ( V_3 , 0x22 , & V_130 ) ;
else
F_7 ( V_3 , 0x22 , 0 ,
V_141 , V_140 ) ;
F_7 ( V_3 , 0x26 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x14 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x19 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x1b , & V_130 ) ;
F_7 ( V_3 , 0x18 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x11 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x23 , & V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x1a , & V_130 ) ;
F_7 ( V_3 , 0x27 , 0 , V_141 , V_130 ) ;
if ( V_4 -> V_119 )
F_50 ( V_3 , 0x1e , & V_130 ) ;
F_7 ( V_3 , 0x25 , 0 , V_141 , V_130 ) ;
V_136 = F_52 ( V_3 , 0x1c ) ;
if ( V_136 )
V_368 = 0 ;
else {
V_136 = F_52 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_101 && V_136 )
V_368 = 0 ;
else
V_368 = 1 ;
}
V_130 = V_368 ? V_139 : V_140 ;
F_7 ( V_3 , 0x28 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x29 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x2a , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x1c , & V_130 ) ;
F_50 ( V_3 , 0x1d , & V_130 ) ;
if ( V_4 -> V_101 )
F_7 ( V_3 , 0x25 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x16 , 0 , V_141 ,
V_348 ? V_139 : V_130 ) ;
F_7 ( V_3 , 0x10 , 0 , V_141 ,
V_368 ? V_139 : V_130 ) ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
F_187 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_369 ;
V_4 -> V_213 [ V_4 -> V_212 ] = V_370 ;
V_4 -> V_212 ++ ;
V_4 -> V_213 [ V_4 -> V_212 ++ ] = V_371 ;
V_3 -> V_346 = V_347 ;
V_4 -> F_13 = F_198 ;
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_348 ;
unsigned int V_130 ;
unsigned int V_136 ;
V_348 =
F_76 ( V_3 , 0x1e , 0 , V_350 , 0x00 ) == 3 ;
V_130 = V_140 ;
F_50 ( V_3 , 0x29 , & V_130 ) ;
F_50 ( V_3 , 0x2a , & V_130 ) ;
F_50 ( V_3 , 0x2b , & V_130 ) ;
V_130 = V_139 ;
F_7 ( V_3 , 0x1e , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x1f , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x10 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x11 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x8 , 0 , V_141 , V_130 ) ;
if ( V_4 -> V_7 == V_26 ) {
V_130 = V_140 ;
F_50 ( V_3 , 0x28 , & V_130 ) ;
F_7 ( V_3 , 0x18 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x38 , 0 ,
V_141 , V_130 ) ;
} else {
V_130 = V_140 ;
F_50 ( V_3 , 0x26 , & V_130 ) ;
F_7 ( V_3 , 0x1c , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x37 , 0 ,
V_141 , V_130 ) ;
}
if ( V_4 -> V_7 == V_26 ) {
V_130 = V_140 ;
F_50 ( V_3 , 0x25 , & V_130 ) ;
F_7 ( V_3 , 0x15 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x35 , 0 ,
V_141 , V_130 ) ;
} else {
V_130 = V_140 ;
F_50 ( V_3 , 0x25 , & V_130 ) ;
F_7 ( V_3 , 0x19 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x35 , 0 ,
V_141 , V_130 ) ;
}
if ( V_4 -> V_101 )
F_7 ( V_3 , 0x9 , 0 ,
V_141 , V_139 ) ;
V_136 = F_52 ( V_3 , 0x25 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x24 , & V_130 ) ;
V_130 = V_136 ? V_140 : V_139 ;
if ( V_4 -> V_7 == V_26 )
F_7 ( V_3 , 0x14 , 0 ,
V_141 , V_130 ) ;
else
F_7 ( V_3 , 0x18 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x34 , 0 , V_141 , V_130 ) ;
V_136 = F_52 ( V_3 , 0x26 ) ;
V_130 = V_136 ? V_140 : V_139 ;
if ( V_4 -> V_7 == V_26 ) {
F_7 ( V_3 , 0x33 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x1c , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x3c , 0 ,
V_141 , V_130 ) ;
} else {
F_7 ( V_3 , 0x31 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x17 , 0 ,
V_141 , V_130 ) ;
F_7 ( V_3 , 0x3b , 0 ,
V_141 , V_130 ) ;
}
if ( V_348 || ! F_78 ( V_3 ) )
F_7 ( V_3 , 0x21 , 0 ,
V_141 , V_139 ) ;
else
F_7 ( V_3 , 0x21 , 0 ,
V_141 , V_140 ) ;
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_187 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_192 ( V_3 ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
if ( V_4 -> V_7 == V_26 )
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_372 ;
else
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_373 ;
V_3 -> V_346 = V_347 ;
V_4 -> F_13 = F_200 ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_130 ;
unsigned int V_136 ;
V_130 = V_140 ;
F_50 ( V_3 , 0x29 , & V_130 ) ;
F_50 ( V_3 , 0x2a , & V_130 ) ;
F_50 ( V_3 , 0x2b , & V_130 ) ;
V_130 = V_139 ;
F_7 ( V_3 , 0x1e , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x1f , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x10 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x11 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x8 , 0 ,
V_141 , V_139 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x28 , & V_130 ) ;
F_7 ( V_3 , 0x18 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x38 , 0 , V_141 , V_130 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x25 , & V_130 ) ;
F_7 ( V_3 , 0x15 , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x35 , 0 , V_141 , V_130 ) ;
if ( V_4 -> V_101 )
F_7 ( V_3 , 0x9 , 0 ,
V_141 , V_139 ) ;
V_136 = F_52 ( V_3 , 0x25 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x24 , & V_130 ) ;
if ( V_136 ) {
F_7 ( V_3 , 0x14 , 0 ,
V_141 , V_140 ) ;
F_7 ( V_3 , 0x34 , 0 ,
V_141 , V_140 ) ;
} else {
F_7 ( V_3 , 0x14 , 0 ,
V_141 , V_139 ) ;
F_7 ( V_3 , 0x34 , 0 ,
V_141 , V_139 ) ;
}
V_136 = F_52 ( V_3 , 0x28 ) ;
V_130 = V_140 ;
F_50 ( V_3 , 0x31 , & V_130 ) ;
if ( V_136 ) {
F_7 ( V_3 , 0x1c , 0 ,
V_141 , V_140 ) ;
F_7 ( V_3 , 0x3c , 0 ,
V_141 , V_140 ) ;
F_7 ( V_3 , 0x3e , 0 ,
V_141 , V_140 ) ;
} else {
F_7 ( V_3 , 0x1c , 0 ,
V_141 , V_139 ) ;
F_7 ( V_3 , 0x3c , 0 ,
V_141 , V_139 ) ;
F_7 ( V_3 , 0x3e , 0 ,
V_141 , V_139 ) ;
}
V_130 = V_140 ;
F_50 ( V_3 , 0x33 , & V_130 ) ;
F_7 ( V_3 , 0x1d , 0 , V_141 , V_130 ) ;
F_7 ( V_3 , 0x3d , 0 , V_141 , V_130 ) ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_187 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_192 ( V_3 ) ;
V_58 = F_169 ( V_3 ) ;
if ( V_58 < 0 ) {
F_116 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_336 [ V_4 -> V_335 ++ ] = V_374 ;
V_3 -> V_346 = V_347 ;
V_4 -> F_13 = F_202 ;
return 0 ;
}
static int T_5 F_204 ( void )
{
return F_205 ( & V_375 ) ;
}
static void T_6 F_206 ( void )
{
F_207 ( & V_375 ) ;
}
