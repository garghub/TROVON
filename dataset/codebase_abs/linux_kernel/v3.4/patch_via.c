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
if ( F_30 ( V_3 , V_85 ) & V_67 )
V_65 = F_31 ( V_3 , V_85 , V_82 ) ;
else
V_65 = 0 ;
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
T_3 V_62 = V_4 -> V_116 [ V_53 ] ;
if ( ! ( F_30 ( V_3 , V_62 ) & V_66 ) ||
! ( F_31 ( V_3 , V_62 , V_60 ) & V_90 ) )
continue;
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
if ( V_53 > 0 && ! V_4 -> V_125 [ V_53 ] )
break;
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
unsigned int V_129 )
{
if ( F_51 ( V_3 , V_62 , 0 ,
V_130 , 0 ) == V_129 )
return;
F_7 ( V_3 , V_62 , 0 , V_131 , V_129 ) ;
}
static void F_52 ( struct V_2 * V_3 , T_3 V_62 ,
unsigned int * V_132 )
{
unsigned V_129 ;
unsigned V_133 = F_53 ( V_3 , V_62 ) ;
unsigned V_134 = ( V_133 & V_135 )
>> V_136
& V_137 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_138 = 0 ;
V_134 |= V_4 -> V_139 ;
if ( ! V_134 )
V_138 = F_54 ( V_3 , V_62 ) ;
if ( ( V_4 -> V_119 && F_46 ( V_3 , V_62 ) )
|| ( ( V_134 || V_138 )
&& F_55 ( V_133 ) != V_140 ) ) {
* V_132 = V_141 ;
V_129 = V_141 ;
} else
V_129 = V_142 ;
F_50 ( V_3 , V_62 , V_129 ) ;
}
static int F_56 ( struct V_33 * V_34 ,
struct V_143 * V_144 )
{
static const char * const V_145 [] = {
L_3 , L_4
} ;
V_144 -> type = V_146 ;
V_144 -> V_147 = 1 ;
V_144 -> V_148 . V_149 . V_150 = 2 ;
if ( V_144 -> V_148 . V_149 . V_151 >= V_144 -> V_148 . V_149 . V_150 )
V_144 -> V_148 . V_149 . V_151 = V_144 -> V_148 . V_149 . V_150 - 1 ;
strcpy ( V_144 -> V_148 . V_149 . V_40 ,
V_145 [ V_144 -> V_148 . V_149 . V_151 ] ) ;
return 0 ;
}
static int F_57 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_148 . V_149 . V_151 [ 0 ] = ! V_4 -> V_139 ;
return 0 ;
}
static int F_58 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = ! V_36 -> V_148 . V_149 . V_151 [ 0 ] ;
if ( V_44 == V_4 -> V_139 )
return 0 ;
V_4 -> V_139 = V_44 ;
F_13 ( V_3 ) ;
F_17 ( V_3 ) ;
return 1 ;
}
static int F_59 ( struct V_33 * V_34 ,
struct V_143 * V_144 )
{
static const char * const V_145 [] = { L_5 , L_6 } ;
V_144 -> type = V_146 ;
V_144 -> V_147 = 1 ;
V_144 -> V_148 . V_149 . V_150 = 2 ;
if ( V_144 -> V_148 . V_149 . V_151 >= 2 )
V_144 -> V_148 . V_149 . V_151 = 1 ;
strcpy ( V_144 -> V_148 . V_149 . V_40 ,
V_145 [ V_144 -> V_148 . V_149 . V_151 ] ) ;
return 0 ;
}
static int F_60 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_148 . V_149 . V_151 [ 0 ] = V_4 -> V_101 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_4 )
{
const struct V_109 * V_110 = & V_4 -> V_27 ;
V_4 -> V_152 . V_153 = V_110 -> V_93 + V_4 -> V_94 ;
V_4 -> V_152 . V_154 = 0 ;
if ( ! V_4 -> V_101 ) {
if ( ! V_4 -> V_100 )
V_4 -> V_152 . V_154 = V_4 -> V_155 ;
} else {
if ( V_4 -> V_100 )
V_4 -> V_152 . V_153 = V_110 -> V_93 - 1 ;
}
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_99 = V_4 -> V_100 ;
T_3 V_156 , V_157 ;
if ( ! V_4 -> V_158 )
return;
V_156 = V_99 ? V_4 -> V_152 . V_159 [ V_99 ] : 0 ;
V_157 = V_4 -> V_155 ;
if ( V_4 -> V_101 ) {
if ( V_4 -> V_32 & V_160 ) {
F_63 ( V_3 , V_157 , 1 ) ;
F_63 ( V_3 , V_156 , 1 ) ;
}
if ( V_4 -> V_32 & V_161 )
F_64 ( V_3 , V_157 ,
V_4 -> V_162 , 0 ,
V_4 -> V_163 ) ;
} else {
if ( V_4 -> V_32 & V_161 )
F_63 ( V_3 , V_157 , 1 ) ;
if ( V_4 -> V_32 & V_160 ) {
T_3 V_164 ;
int V_165 ;
if ( V_156 ) {
V_164 = V_156 ;
V_165 = V_99 * 2 ;
} else {
V_164 = V_157 ;
V_165 = 0 ;
}
F_64 ( V_3 , V_164 ,
V_4 -> V_166 , V_165 ,
V_4 -> V_167 ) ;
}
}
F_61 ( V_4 ) ;
}
static int F_65 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_168 , V_99 ;
F_66 ( & V_4 -> V_6 ) ;
V_168 = ! ! V_36 -> V_148 . V_149 . V_151 [ 0 ] ;
if ( V_4 -> V_101 == V_168 ) {
F_67 ( & V_4 -> V_6 ) ;
return 0 ;
}
V_4 -> V_101 = V_168 ;
V_99 = V_4 -> V_100 ;
F_42 ( V_3 ) ;
if ( V_168 )
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
F_62 ( V_3 ) ;
F_67 ( & V_4 -> V_6 ) ;
F_13 ( V_3 ) ;
F_68 ( V_3 ) ;
return 1 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
T_3 V_62 ;
V_62 = V_4 -> V_27 . V_28 [ 0 ] ;
V_41 = F_70 ( V_4 , & V_169 ) ;
if ( V_41 == NULL )
return - V_46 ;
V_41 -> V_48 = V_170 | V_62 ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ ) {
struct V_33 * V_113 ;
struct V_171 V_172 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 . V_173 = V_174 ;
sprintf ( V_172 . V_40 , L_1 , V_4 -> V_175 [ V_53 ] ) ;
V_113 = F_72 ( V_3 , V_172 . V_40 ) ;
if ( V_113 )
F_73 ( V_3 -> V_176 -> V_177 ,
V_178 ,
& V_113 -> V_172 ) ;
}
}
static void F_74 ( struct V_2 * V_3 , int V_179 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 = V_179 ? V_180 : V_181 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ ) {
if ( V_4 -> V_182 [ V_53 ] < 0 )
continue;
F_75 ( V_3 , V_4 -> V_79 ,
V_60 , V_4 -> V_182 [ V_53 ] ,
V_180 , V_44 ) ;
}
}
static bool F_46 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ )
if ( V_4 -> V_183 [ V_53 ] == V_85 )
return true ;
return false ;
}
static int F_76 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
* V_36 -> V_148 . integer . V_148 = V_4 -> V_119 ;
return 0 ;
}
static int F_77 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_184 = * V_36 -> V_148 . integer . V_148
? V_185 : V_186 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_94 ; V_53 ++ ) {
T_3 V_62 = V_4 -> V_183 [ V_53 ] ;
unsigned int V_129 ;
V_129 = F_51 ( V_3 , V_62 , 0 ,
V_187 , 0 ) ;
V_129 &= ~ ( V_186 | V_185 ) ;
V_129 |= V_184 ;
F_7 ( V_3 , V_62 , 0 ,
V_87 ,
V_129 ) ;
if ( V_184 == V_185 ) {
F_74 ( V_3 , 1 ) ;
F_71 ( V_3 ) ;
}
}
V_4 -> V_119 = * V_36 -> V_148 . integer . V_148 ;
F_13 ( V_3 ) ;
return 1 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_94 )
return 0 ;
if ( ! F_70 ( V_4 , & V_188 ) )
return - V_46 ;
return 0 ;
}
static bool F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_189 * V_190 ;
int V_53 , V_165 , V_191 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_192 ; V_53 ++ ) {
V_190 = & V_4 -> V_193 [ V_53 ] ;
for ( V_165 = 0 ; V_165 < 2 ; V_165 ++ ) {
V_191 = F_80 ( V_3 , V_190 -> V_62 , V_165 , V_190 -> V_63 ,
V_190 -> V_43 ) ;
if ( ! ( V_191 & V_180 ) && V_191 > 0 )
return false ;
}
}
return true ;
}
static void F_81 ( struct V_2 * V_3 , bool V_73 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_70 ;
unsigned int V_194 , V_129 ;
if ( V_4 -> V_139 )
V_70 = false ;
else
V_70 = F_79 ( V_3 ) && ! V_4 -> V_158 ;
if ( V_70 == V_4 -> V_195 && ! V_73 )
return;
V_4 -> V_195 = V_70 ;
switch ( V_4 -> V_7 ) {
case V_18 :
case V_20 :
V_194 = 0xf70 ;
V_129 = V_70 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_22 :
case V_23 :
V_194 = 0xf73 ;
V_129 = V_70 ? 0x51 : 0xe1 ;
break;
case V_21 :
V_194 = 0xf73 ;
V_129 = V_70 ? 0x01 : 0x1d ;
break;
case V_24 :
case V_25 :
case V_26 :
V_194 = 0xf93 ;
V_129 = V_70 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_196 , 0 , V_194 , V_129 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
return F_81 ( V_3 , false ) ;
}
static void F_82 ( struct V_2 * V_3 , int V_197 , bool V_198 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_198 )
V_4 -> V_158 |= V_197 ;
else
V_4 -> V_158 &= ~ V_197 ;
F_17 ( V_3 ) ;
}
static int F_83 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_58 ;
V_4 -> V_152 . V_153 = V_110 -> V_93 + V_4 -> V_94 ;
V_4 -> V_152 . V_203 = V_4 -> V_152 . V_153 * 2 ;
F_82 ( V_3 , V_160 , true ) ;
V_58 = F_84 ( V_3 , & V_4 -> V_152 , V_202 ,
V_200 ) ;
if ( V_58 < 0 ) {
F_82 ( V_3 , V_160 , false ) ;
return V_58 ;
}
return 0 ;
}
static int F_85 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
F_82 ( V_3 , V_160 , false ) ;
return 0 ;
}
static int F_86 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_87 ( ! V_4 -> V_155 ) )
return - V_204 ;
F_82 ( V_3 , V_161 , true ) ;
return 0 ;
}
static int F_88 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
F_82 ( V_3 , V_161 , false ) ;
return 0 ;
}
static int F_89 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
unsigned int V_205 ,
unsigned int V_206 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
F_61 ( V_4 ) ;
F_90 ( V_3 , & V_4 -> V_152 , V_205 ,
V_206 , V_202 ) ;
V_4 -> V_32 |= V_160 ;
V_4 -> V_166 = V_205 ;
V_4 -> V_167 = V_206 ;
F_67 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_91 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
unsigned int V_205 ,
unsigned int V_206 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_101 )
F_64 ( V_3 , V_4 -> V_155 ,
V_205 , 0 , V_206 ) ;
V_4 -> V_32 |= V_161 ;
V_4 -> V_162 = V_205 ;
V_4 -> V_163 = V_206 ;
F_67 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_92 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
F_93 ( V_3 , & V_4 -> V_152 ) ;
V_4 -> V_32 &= ~ V_160 ;
F_67 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_101 )
F_64 ( V_3 , V_4 -> V_155 , 0 , 0 , 0 ) ;
V_4 -> V_32 &= ~ V_161 ;
F_67 ( & V_4 -> V_6 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_95 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_96 ( V_3 , & V_4 -> V_152 ) ;
}
static int F_97 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_98 ( V_3 , & V_4 -> V_152 ) ;
}
static int F_99 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
unsigned int V_205 ,
unsigned int V_206 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_100 ( V_3 , & V_4 -> V_152 ,
V_205 , V_206 , V_202 ) ;
}
static int F_101 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_102 ( V_3 , & V_4 -> V_152 ) ;
return 0 ;
}
static int F_103 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
unsigned int V_205 ,
unsigned int V_206 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( V_3 , V_4 -> V_116 [ V_202 -> V_207 ] ,
V_205 , 0 , V_206 ) ;
return 0 ;
}
static int F_104 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_105 ( V_3 , V_4 -> V_116 [ V_202 -> V_207 ] ) ;
return 0 ;
}
static int F_106 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
unsigned int V_205 ,
unsigned int V_206 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_123 = V_4 -> V_118 [ V_4 -> V_124 [ 0 ] ] . V_123 ;
F_66 ( & V_4 -> V_6 ) ;
V_4 -> V_208 = V_4 -> V_116 [ V_123 ] ;
V_4 -> V_209 = V_205 ;
V_4 -> V_210 = V_206 ;
F_64 ( V_3 , V_4 -> V_208 , V_205 , 0 , V_206 ) ;
F_67 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_107 ( struct V_199 * V_200 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
F_105 ( V_3 , V_4 -> V_208 ) ;
V_4 -> V_208 = 0 ;
F_67 ( & V_4 -> V_6 ) ;
return 0 ;
}
static bool F_108 ( struct V_2 * V_3 , int V_168 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_123 = V_4 -> V_118 [ V_168 ] . V_123 ;
T_3 V_211 = V_4 -> V_116 [ V_123 ] ;
bool V_212 = false ;
F_66 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_208 && V_4 -> V_208 != V_211 ) {
F_63 ( V_3 , V_4 -> V_208 , 1 ) ;
V_4 -> V_208 = V_211 ;
F_64 ( V_3 , V_211 ,
V_4 -> V_209 , 0 ,
V_4 -> V_210 ) ;
V_212 = true ;
}
F_67 ( & V_4 -> V_6 ) ;
return V_212 ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_33 * V_52 ;
int V_58 , V_53 ;
V_4 -> V_139 = 1 ;
if ( V_4 -> F_13 )
if ( ! F_70 ( V_4 , & V_213 ) )
return - V_46 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_214 ; V_53 ++ ) {
V_58 = F_110 ( V_3 , V_4 -> V_215 [ V_53 ] ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( V_4 -> V_152 . V_216 ) {
V_58 = F_111 ( V_3 ,
V_4 -> V_152 . V_216 ,
V_4 -> V_152 . V_216 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_112 ( V_3 ,
& V_4 -> V_152 ) ;
if ( V_58 < 0 )
return V_58 ;
V_4 -> V_152 . V_217 = 1 ;
}
if ( V_4 -> V_218 ) {
V_58 = F_113 ( V_3 , V_4 -> V_218 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( ! F_72 ( V_3 , L_7 ) ) {
unsigned int V_219 [ 4 ] ;
F_114 ( V_3 , V_4 -> V_152 . V_159 [ 0 ] ,
V_82 , V_219 ) ;
V_58 = F_115 ( V_3 , L_7 ,
V_219 , V_220 ,
L_8 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( ! F_72 ( V_3 , L_9 ) ) {
V_58 = F_115 ( V_3 , L_9 ,
NULL , V_220 ,
L_10 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_52 = F_72 ( V_3 , L_11 ) ;
for ( V_53 = 0 ; V_52 && V_53 < V_52 -> V_147 ; V_53 ++ ) {
if ( ! V_4 -> V_125 [ V_53 ] )
continue;
V_58 = F_116 ( V_3 , V_52 , V_53 , V_4 -> V_125 [ V_53 ] ) ;
if ( V_58 < 0 )
return V_58 ;
}
F_24 ( V_3 ) ;
V_58 = F_117 ( V_3 , & V_4 -> V_27 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_221 * V_222 = V_4 -> V_223 ;
V_3 -> V_224 = 0 ;
V_3 -> V_225 = V_222 ;
if ( V_4 -> V_152 . V_153 || V_4 -> V_115 ) {
snprintf ( V_4 -> V_226 ,
sizeof( V_4 -> V_226 ) ,
L_12 , V_3 -> V_227 ) ;
V_222 -> V_40 = V_4 -> V_226 ;
if ( V_4 -> V_152 . V_153 ) {
if ( ! V_4 -> V_228 )
V_4 -> V_228 =
& V_229 ;
V_222 -> V_230 [ V_231 ] =
* V_4 -> V_228 ;
V_222 -> V_230 [ V_231 ] . V_62 =
V_4 -> V_152 . V_159 [ 0 ] ;
V_222 -> V_230 [ V_231 ] . V_232 =
V_4 -> V_152 . V_203 ;
}
if ( ! V_4 -> V_233 ) {
if ( V_4 -> V_127 )
V_4 -> V_233 =
& V_234 ;
else
V_4 -> V_233 =
& V_235 ;
}
if ( V_4 -> V_115 ) {
V_222 -> V_230 [ V_236 ] =
* V_4 -> V_233 ;
V_222 -> V_230 [ V_236 ] . V_62 =
V_4 -> V_116 [ 0 ] ;
if ( ! V_4 -> V_127 )
V_222 -> V_230 [ V_236 ] . V_237 =
V_4 -> V_115 ;
}
V_3 -> V_224 ++ ;
V_222 ++ ;
}
if ( V_4 -> V_152 . V_216 || V_4 -> V_218 ) {
snprintf ( V_4 -> V_238 ,
sizeof( V_4 -> V_238 ) ,
L_13 , V_3 -> V_227 ) ;
V_222 -> V_40 = V_4 -> V_238 ;
V_222 -> V_239 = V_240 ;
if ( V_4 -> V_152 . V_216 ) {
if ( ! V_4 -> V_241 )
V_4 -> V_241 =
& V_242 ;
V_222 -> V_230 [ V_231 ] =
* V_4 -> V_241 ;
V_222 -> V_230 [ V_231 ] . V_62 =
V_4 -> V_152 . V_216 ;
}
if ( V_4 -> V_218 ) {
if ( ! V_4 -> V_243 )
V_4 -> V_243 =
& V_244 ;
V_222 -> V_230 [ V_236 ] =
* V_4 -> V_243 ;
V_222 -> V_230 [ V_236 ] . V_62 =
V_4 -> V_218 ;
}
V_3 -> V_224 ++ ;
V_222 ++ ;
}
if ( V_4 -> V_155 ) {
snprintf ( V_4 -> V_245 , sizeof( V_4 -> V_245 ) ,
L_14 , V_3 -> V_227 ) ;
V_222 -> V_40 = V_4 -> V_245 ;
V_222 -> V_230 [ V_231 ] = V_246 ;
V_222 -> V_230 [ V_231 ] . V_62 =
V_4 -> V_155 ;
V_3 -> V_224 ++ ;
V_222 ++ ;
}
return 0 ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_24 ( V_3 ) ;
F_6 ( V_4 ) ;
F_25 ( V_4 -> V_247 ) ;
F_25 ( V_4 -> V_248 ) ;
F_25 ( V_4 ) ;
}
static void F_120 ( struct V_2 * V_3 , int V_249 ,
T_3 * V_250 , bool V_179 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_249 ; V_53 ++ ) {
unsigned int V_129 = F_51 ( V_3 , V_250 [ V_53 ] , 0 ,
V_187 , 0 ) ;
if ( V_129 & V_186 )
continue;
if ( V_179 )
V_129 &= ~ V_185 ;
else
V_129 |= V_185 ;
F_7 ( V_3 , V_250 [ V_53 ] , 0 ,
V_87 , V_129 ) ;
}
}
static void F_121 ( struct V_2 * V_3 , int V_138 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_106 )
return;
if ( ! V_138 )
V_138 = F_54 ( V_3 ,
V_4 -> V_27 . V_251 [ 0 ] ) ;
F_120 ( V_3 , V_4 -> V_27 . V_106 ,
V_4 -> V_27 . V_252 ,
V_138 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
int V_138 = 0 ;
int V_253 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_101 && V_4 -> V_27 . V_28 [ 0 ] &&
( V_4 -> V_7 != V_15 || V_4 -> V_31 ) )
V_138 = F_54 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_4 -> V_119 )
V_253 = V_4 -> V_27 . V_93 + V_4 -> V_94 ;
else
V_253 = V_4 -> V_27 . V_93 ;
F_120 ( V_3 , V_253 , V_4 -> V_27 . V_251 , V_138 ) ;
F_121 ( V_3 , V_138 ) ;
}
static void F_122 ( struct V_2 * V_3 )
{
unsigned int V_254 ;
unsigned int V_255 ;
unsigned int V_256 ;
unsigned int V_257 ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_254 = F_51 ( V_3 , V_3 -> V_196 , 0 ,
V_258 , 0 ) & 0x03 ;
V_255 = ( F_51 ( V_3 , V_3 -> V_196 , 0 ,
0xF84 , 0 ) & 0x3F0000 ) >> 16 ;
V_256 = V_255 & 0x1F ;
V_257 = F_51 ( V_3 , 0x1A , 0 ,
V_259 ,
V_260 ) ;
if ( V_254 == 0x02 ) {
F_7 ( V_3 , V_4 -> V_27 . V_251 [ 0 ] , 0 ,
V_87 ,
V_98 ) ;
if ( V_255 & 0x20 ) {
if ( V_256 > V_257 )
V_256 = V_257 ;
F_75 ( V_3 , 0x1A , V_60 ,
0 , V_261 ,
V_257 - V_256 ) ;
} else {
F_75 ( V_3 , 0x1A , V_60 , 0 ,
V_261 ,
( ( V_257 + V_256 ) > 0x2A ) ? 0x2A :
( V_257 + V_256 ) ) ;
}
} else if ( ! ( V_254 & 0x02 ) ) {
F_7 ( V_3 , V_4 -> V_27 . V_251 [ 0 ] , 0 ,
V_87 ,
0 ) ;
}
}
static void F_123 ( struct V_2 * V_3 ,
unsigned int V_262 )
{
V_262 >>= 26 ;
V_262 = F_124 ( V_3 , V_262 ) ;
if ( V_262 & V_263 )
F_13 ( V_3 ) ;
V_262 &= ~ V_263 ;
if ( V_262 == V_264 || V_262 == V_265 )
F_68 ( V_3 ) ;
else if ( V_262 == V_266 )
F_122 ( V_3 ) ;
F_125 ( V_3 ) ;
}
static int F_126 ( struct V_2 * V_3 , T_4 V_267 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , T_3 V_62 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_128 ( V_3 , & V_4 -> V_268 , V_62 ) ;
}
static bool F_129 ( struct V_2 * V_3 , T_3 V_164 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_152 . V_153 ; V_53 ++ ) {
if ( V_4 -> V_152 . V_159 [ V_53 ] == V_164 )
return false ;
}
if ( V_4 -> V_155 == V_164 )
return false ;
return true ;
}
static bool F_130 ( struct V_2 * V_3 , T_3 V_62 ,
T_3 V_269 , int V_270 ,
struct V_68 * V_69 , int V_74 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_111 [ 8 ] ;
int V_53 , V_253 ;
if ( V_62 == V_4 -> V_79 ) {
if ( ! V_270 )
return false ;
V_270 = 2 ;
}
V_253 = F_47 ( V_3 , V_62 , V_111 , F_48 ( V_111 ) ) ;
for ( V_53 = 0 ; V_53 < V_253 ; V_53 ++ ) {
if ( F_49 ( F_30 ( V_3 , V_111 [ V_53 ] ) ) != V_271 )
continue;
if ( V_111 [ V_53 ] == V_269 || F_129 ( V_3 , V_111 [ V_53 ] ) ) {
if ( ! ( V_4 -> V_79 && V_270 == 1 ) )
goto V_272;
}
}
if ( V_74 >= V_273 )
return false ;
for ( V_53 = 0 ; V_53 < V_253 ; V_53 ++ ) {
unsigned int type ;
type = F_49 ( F_30 ( V_3 , V_111 [ V_53 ] ) ) ;
if ( type == V_271 )
continue;
if ( F_130 ( V_3 , V_111 [ V_53 ] , V_269 ,
V_270 , V_69 , V_74 + 1 ) )
goto V_272;
}
return false ;
V_272:
V_69 -> V_69 [ V_69 -> V_74 ] = V_111 [ V_53 ] ;
V_69 -> V_43 [ V_69 -> V_74 ] = V_53 ;
if ( V_253 > 1 && F_49 ( F_30 ( V_3 , V_62 ) ) != V_274 )
V_69 -> V_77 [ V_69 -> V_74 ] = 1 ;
V_69 -> V_74 ++ ;
return true ;
}
static bool F_131 ( struct V_2 * V_3 , T_3 V_62 ,
T_3 V_269 , int V_270 ,
struct V_68 * V_69 )
{
if ( F_130 ( V_3 , V_62 , V_269 , V_270 , V_69 , 1 ) ) {
V_69 -> V_69 [ V_69 -> V_74 ] = V_62 ;
V_69 -> V_74 ++ ;
F_132 ( L_15 ,
V_69 -> V_74 , V_69 -> V_69 [ 0 ] , V_69 -> V_69 [ 1 ] ,
V_69 -> V_69 [ 2 ] , V_69 -> V_69 [ 3 ] , V_69 -> V_69 [ 4 ] ) ;
return true ;
}
return false ;
}
static int F_133 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_53 , V_275 ;
T_3 V_62 ;
V_4 -> V_152 . V_159 = V_4 -> V_276 ;
V_275 = 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_93 ; V_53 ++ ) {
T_3 V_164 = 0 ;
V_62 = V_110 -> V_251 [ V_53 ] ;
if ( ! V_62 )
continue;
if ( F_131 ( V_3 , V_62 , 0 , 0 , & V_4 -> V_95 [ V_53 ] ) )
V_164 = V_4 -> V_95 [ V_53 ] . V_69 [ 0 ] ;
if ( ! V_53 && F_131 ( V_3 , V_62 , V_164 , 1 ,
& V_4 -> V_97 ) )
V_164 = V_4 -> V_97 . V_69 [ 0 ] ;
if ( V_164 ) {
V_4 -> V_276 [ V_53 ] = V_164 ;
V_275 ++ ;
}
}
if ( ! V_4 -> V_95 [ 0 ] . V_74 && V_4 -> V_97 . V_74 ) {
V_4 -> V_95 [ 0 ] = V_4 -> V_97 ;
V_4 -> V_97 . V_74 = 0 ;
}
V_4 -> V_152 . V_153 = V_275 ;
return 0 ;
}
static int F_134 ( struct V_2 * V_3 , const char * V_277 ,
int V_278 , bool V_279 , struct V_68 * V_69 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_40 [ 32 ] ;
T_3 V_164 , V_85 , V_280 , V_62 ;
int V_58 ;
V_164 = V_279 ? V_69 -> V_69 [ 0 ] : 0 ;
V_85 = V_69 -> V_69 [ V_69 -> V_74 - 1 ] ;
V_280 = V_69 -> V_74 > 1 ? V_69 -> V_69 [ 1 ] : 0 ;
if ( V_164 && F_29 ( V_3 , V_164 , V_82 , V_281 ) )
V_62 = V_164 ;
else if ( F_29 ( V_3 , V_85 , V_82 , V_281 ) )
V_62 = V_85 ;
else if ( F_29 ( V_3 , V_280 , V_82 , V_281 ) )
V_62 = V_280 ;
else
V_62 = 0 ;
if ( V_62 ) {
sprintf ( V_40 , L_1 , V_277 ) ;
V_58 = F_135 ( V_4 , V_59 , V_40 ,
F_28 ( V_62 , V_278 , 0 , V_82 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_69 -> V_80 = V_62 ;
}
if ( V_164 && F_29 ( V_3 , V_164 , V_82 , V_90 ) )
V_62 = V_164 ;
else if ( F_29 ( V_3 , V_85 , V_82 , V_90 ) )
V_62 = V_85 ;
else if ( F_29 ( V_3 , V_280 , V_82 , V_90 ) )
V_62 = V_280 ;
else
V_62 = 0 ;
if ( V_62 ) {
sprintf ( V_40 , L_2 , V_277 ) ;
V_58 = F_135 ( V_4 , V_282 , V_40 ,
F_28 ( V_62 , V_278 , 0 , V_82 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_69 -> V_81 = V_62 ;
}
return 0 ;
}
static void F_136 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_27 ;
struct V_283 * V_284 = V_110 -> V_118 ;
int V_53 , V_285 , V_253 , V_286 ;
int V_250 [ V_287 ] ;
for ( V_286 = V_288 ; V_286 >= V_289 ; V_286 -- ) {
V_253 = 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
unsigned int V_290 ;
if ( V_284 [ V_53 ] . type > V_291 )
continue;
V_290 = F_53 ( V_3 , V_284 [ V_53 ] . V_85 ) ;
if ( F_137 ( V_290 ) != V_286 )
continue;
for ( V_285 = 0 ; V_285 < V_253 ; V_285 ++ )
if ( V_284 [ V_250 [ V_285 ] ] . type < V_284 [ V_53 ] . type ) {
memmove ( V_250 + V_285 + 1 , V_250 + V_285 ,
( V_253 - V_285 ) * sizeof( int ) ) ;
break;
}
V_250 [ V_285 ] = V_53 ;
V_253 ++ ;
}
if ( V_110 -> V_93 + V_253 < 3 )
continue;
for ( V_53 = 0 ; V_53 < V_253 ; V_53 ++ ) {
T_3 V_85 = V_284 [ V_250 [ V_53 ] ] . V_85 ;
V_4 -> V_183 [ V_4 -> V_94 ++ ] = V_85 ;
V_110 -> V_251 [ V_110 -> V_93 ++ ] = V_85 ;
if ( V_110 -> V_93 == 3 )
break;
}
return;
}
}
static void F_138 ( struct V_68 * V_76 , struct V_68 * V_75 )
{
V_76 -> V_80 = V_75 -> V_80 ;
V_76 -> V_81 = V_75 -> V_81 ;
}
static int F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_27 ;
struct V_68 * V_69 ;
static const char * const V_292 [ 4 ] = {
L_16 , L_17 , L_18 , L_19
} ;
int V_53 , V_43 , V_58 ;
int V_293 ;
V_293 = V_110 -> V_93 ;
if ( V_110 -> V_93 == 1 )
F_136 ( V_3 ) ;
V_58 = F_133 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_152 . V_153 < 3 ) {
V_4 -> V_94 = 0 ;
V_110 -> V_93 = V_293 ;
}
for ( V_53 = 0 ; V_53 < V_110 -> V_93 ; V_53 ++ ) {
T_3 V_85 , V_164 ;
V_85 = V_110 -> V_251 [ V_53 ] ;
V_164 = V_4 -> V_152 . V_159 [ V_53 ] ;
if ( ! V_85 || ! V_164 )
continue;
V_69 = V_4 -> V_95 + V_53 ;
if ( V_53 == V_294 ) {
V_58 = F_134 ( V_3 , L_20 , 1 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_134 ( V_3 , L_21 , 2 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
} else {
const char * V_277 = V_292 [ V_53 ] ;
if ( V_110 -> V_295 == V_296 &&
V_110 -> V_93 == 1 )
V_277 = L_22 ;
V_58 = F_134 ( V_3 , V_277 , 3 , true , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
}
if ( V_69 != V_4 -> V_95 + V_53 )
F_138 ( & V_4 -> V_95 [ V_53 ] , V_69 ) ;
if ( V_69 == V_4 -> V_95 && V_4 -> V_97 . V_74 )
F_138 ( & V_4 -> V_97 , V_69 ) ;
}
V_43 = F_140 ( V_3 , V_4 -> V_79 ,
V_4 -> V_152 . V_159 [ 0 ] ) ;
if ( V_43 >= 0 ) {
const char * V_40 ;
V_40 = V_4 -> V_97 . V_74 ?
L_23 : L_24 ;
V_58 = F_135 ( V_4 , V_59 , V_40 ,
F_28 ( V_4 -> V_79 , 3 ,
V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_40 = V_4 -> V_97 . V_74 ?
L_25 : L_26 ;
V_58 = F_135 ( V_4 , V_282 , V_40 ,
F_28 ( V_4 -> V_79 , 3 ,
V_43 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_110 -> V_93 = V_293 ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
bool V_279 ;
int V_53 , V_58 ;
if ( ! V_85 )
return 0 ;
if ( ! F_131 ( V_3 , V_85 , 0 , 0 , & V_4 -> V_104 ) ) {
for ( V_53 = V_297 ; V_53 >= V_294 ; V_53 -- ) {
if ( V_53 < V_4 -> V_152 . V_153 &&
F_131 ( V_3 , V_85 ,
V_4 -> V_152 . V_159 [ V_53 ] , 0 ,
& V_4 -> V_104 ) ) {
V_4 -> V_100 = V_53 ;
break;
}
}
}
if ( V_4 -> V_104 . V_74 ) {
V_4 -> V_155 = V_4 -> V_104 . V_69 [ 0 ] ;
if ( ! V_4 -> V_100 )
V_4 -> V_102 = V_4 -> V_104 ;
}
if ( ! V_4 -> V_102 . V_74 )
F_131 ( V_3 , V_85 ,
V_4 -> V_152 . V_159 [ V_298 ] , 0 ,
& V_4 -> V_102 ) ;
if ( ! F_131 ( V_3 , V_85 , V_4 -> V_152 . V_159 [ V_298 ] ,
1 , & V_4 -> V_103 ) && ! V_4 -> V_102 . V_74 )
return 0 ;
if ( V_4 -> V_102 . V_74 ) {
V_69 = & V_4 -> V_102 ;
V_279 = true ;
} else {
V_69 = & V_4 -> V_103 ;
V_279 = false ;
}
V_58 = F_134 ( V_3 , L_27 , 3 , V_279 , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_279 )
F_138 ( & V_4 -> V_103 , V_69 ) ;
else
F_138 ( & V_4 -> V_102 , V_69 ) ;
if ( V_4 -> V_104 . V_74 )
F_138 ( & V_4 -> V_104 , V_69 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_68 * V_69 ;
bool V_279 ;
T_3 V_85 , V_164 = 0 ;
int V_58 ;
V_85 = V_4 -> V_27 . V_252 [ 0 ] ;
if ( ! V_4 -> V_27 . V_106 || ! V_85 )
return 0 ;
if ( F_131 ( V_3 , V_85 , 0 , 0 , & V_4 -> V_107 ) )
V_164 = V_4 -> V_107 . V_69 [ 0 ] ;
if ( ! V_164 )
F_131 ( V_3 , V_85 ,
V_4 -> V_152 . V_159 [ V_298 ] , 0 ,
& V_4 -> V_107 ) ;
if ( ! F_131 ( V_3 , V_85 , V_4 -> V_152 . V_159 [ V_298 ] ,
1 , & V_4 -> V_108 ) && ! V_164 )
return 0 ;
if ( ! V_4 -> V_97 . V_74 && V_4 -> V_108 . V_74 )
V_164 = 0 ;
V_4 -> V_299 = V_164 ;
V_4 -> V_152 . V_300 [ 0 ] = V_164 ;
if ( V_164 ) {
V_69 = & V_4 -> V_107 ;
V_279 = true ;
} else {
V_69 = & V_4 -> V_108 ;
V_279 = false ;
}
V_58 = F_134 ( V_3 , L_22 , 3 , V_279 , V_69 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_279 )
F_138 ( & V_4 -> V_108 , V_69 ) ;
else
F_138 ( & V_4 -> V_107 , V_69 ) ;
return 0 ;
}
static int F_143 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_36 -> V_148 . V_149 . V_151 [ 0 ] = V_4 -> V_96 ;
return 0 ;
}
static void F_144 ( struct V_2 * V_3 , int V_301 ,
struct V_68 * V_302 , struct V_68 * V_303 )
{
if ( V_301 ) {
F_36 ( V_3 , V_302 , false , false ) ;
F_36 ( V_3 , V_303 , true , false ) ;
} else {
F_36 ( V_3 , V_303 , false , false ) ;
F_36 ( V_3 , V_302 , true , false ) ;
}
}
static int F_145 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = V_36 -> V_148 . V_149 . V_151 [ 0 ] ;
if ( V_44 == V_4 -> V_96 )
return 0 ;
V_4 -> V_96 = V_44 ;
F_144 ( V_3 , V_44 , & V_4 -> V_95 [ 0 ] , & V_4 -> V_97 ) ;
if ( ! V_4 -> V_101 ) {
F_144 ( V_3 , V_44 , & V_4 -> V_102 ,
& V_4 -> V_103 ) ;
}
F_144 ( V_3 , V_44 , & V_4 -> V_107 ,
& V_4 -> V_108 ) ;
return 1 ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_79 )
return 0 ;
if ( ! ( V_4 -> V_97 . V_74 || V_4 -> V_103 . V_74 ||
V_4 -> V_107 . V_74 ) )
return 0 ;
if ( ! F_70 ( V_4 , & V_304 ) )
return - V_46 ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_62 = V_3 -> V_305 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_306 ; V_53 ++ , V_62 ++ ) {
unsigned int V_307 = F_30 ( V_3 , V_62 ) ;
if ( F_49 ( V_307 ) != V_308 )
continue;
if ( V_307 & V_309 )
continue;
if ( ! ( V_307 & V_310 ) )
continue;
if ( V_4 -> V_115 >= F_48 ( V_4 -> V_116 ) )
return - V_46 ;
V_4 -> V_116 [ V_4 -> V_115 ++ ] = V_62 ;
}
return 0 ;
}
static int F_148 ( struct V_33 * V_34 ,
struct V_143 * V_144 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_144 -> type = V_146 ;
V_144 -> V_147 = 1 ;
V_144 -> V_148 . V_149 . V_150 = V_4 -> V_117 ;
if ( V_144 -> V_148 . V_149 . V_151 >= V_4 -> V_117 )
V_144 -> V_148 . V_149 . V_151 = V_4 -> V_117 - 1 ;
strcpy ( V_144 -> V_148 . V_149 . V_40 ,
V_4 -> V_118 [ V_144 -> V_148 . V_149 . V_151 ] . V_311 ) ;
return 0 ;
}
static int F_149 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 = F_150 ( V_34 , & V_36 -> V_172 ) ;
V_36 -> V_148 . V_149 . V_151 [ 0 ] = V_4 -> V_124 [ V_43 ] ;
return 0 ;
}
static int F_151 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_43 = F_150 ( V_34 , & V_36 -> V_172 ) ;
T_3 V_312 ;
int V_168 ;
V_168 = V_36 -> V_148 . V_149 . V_151 [ 0 ] ;
if ( V_168 < 0 || V_168 >= V_4 -> V_117 )
return - V_204 ;
if ( V_4 -> V_124 [ V_43 ] == V_168 )
return 0 ;
V_4 -> V_124 [ V_43 ] = V_168 ;
if ( V_4 -> V_127 ) {
int V_123 = V_4 -> V_118 [ V_168 ] . V_123 ;
V_312 = V_4 -> V_125 [ V_123 ] ;
F_108 ( V_3 , V_168 ) ;
} else {
V_312 = V_4 -> V_125 [ V_43 ] ;
if ( F_87 ( ! V_312 ) )
return - V_204 ;
}
if ( V_312 ) {
F_50 ( V_3 , V_312 , V_141 ) ;
F_7 ( V_3 , V_312 , 0 ,
V_78 ,
V_4 -> V_118 [ V_168 ] . V_126 ) ;
}
F_13 ( V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_2 * V_3 , int V_147 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
if ( V_4 -> V_117 <= 1 || ! V_147 )
return 0 ;
V_41 = F_70 ( V_4 , & V_313 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_147 = V_147 ;
return 0 ;
}
static void F_153 ( struct V_1 * V_4 , T_3 V_303 , int V_43 )
{
struct V_189 * V_51 ;
if ( V_4 -> V_192 >= F_48 ( V_4 -> V_193 ) - 1 )
return;
V_51 = V_4 -> V_193 + V_4 -> V_192 ;
V_51 -> V_62 = V_303 ;
V_51 -> V_63 = V_60 ;
V_51 -> V_43 = V_43 ;
V_4 -> V_192 ++ ;
V_4 -> V_268 . V_314 = V_4 -> V_193 ;
}
static bool F_154 ( struct V_2 * V_3 , T_3 V_75 ,
T_3 V_76 )
{
return F_155 ( V_3 , V_75 , V_76 , 1 ) >= 0 ;
}
static bool F_156 ( struct V_2 * V_3 , T_3 V_85 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_315 , V_43 ;
V_4 -> V_118 [ V_4 -> V_117 ] . V_123 = - 1 ;
V_4 -> V_118 [ V_4 -> V_117 ] . V_85 = V_85 ;
for ( V_315 = 0 ; V_315 < V_4 -> V_115 ; V_315 ++ ) {
if ( V_4 -> V_125 [ V_315 ] ) {
V_43 = F_140 ( V_3 , V_4 -> V_125 [ V_315 ] ,
V_85 ) ;
if ( V_43 < 0 )
continue;
V_4 -> V_118 [ V_4 -> V_117 ] . V_126 = V_43 ;
} else {
if ( ! F_154 ( V_3 , V_4 -> V_116 [ V_315 ] , V_85 ) )
continue;
}
V_4 -> V_118 [ V_4 -> V_117 ] . V_123 = V_315 ;
if ( ! V_4 -> V_127 &&
V_4 -> V_117 > 0 && V_4 -> V_118 [ 0 ] . V_123 != V_315 ) {
F_157 ( V_316
L_28 ) ;
V_4 -> V_127 = 1 ;
}
return true ;
}
return false ;
}
static int F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
int V_53 , V_58 ;
V_58 = F_147 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_159 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
if ( F_156 ( V_3 , V_110 -> V_118 [ V_53 ] . V_85 ) )
V_4 -> V_118 [ V_4 -> V_117 ++ ] . V_311 =
F_160 ( V_3 , V_110 , V_53 ) ;
}
if ( V_4 -> V_79 &&
F_156 ( V_3 , V_4 -> V_79 ) )
V_4 -> V_118 [ V_4 -> V_117 ++ ] . V_311 = L_29 ;
return 0 ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
const char * V_317 = NULL ;
int V_56 = 0 ;
int V_53 , V_285 , V_58 , V_43 ;
if ( ! V_4 -> V_79 )
return 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
T_3 V_85 = V_110 -> V_118 [ V_53 ] . V_85 ;
const char * V_311 = F_160 ( V_3 , V_110 , V_53 ) ;
if ( V_317 && ! strcmp ( V_311 , V_317 ) )
V_56 ++ ;
else
V_56 = 0 ;
V_317 = V_311 ;
V_43 = F_140 ( V_3 , V_4 -> V_79 , V_85 ) ;
if ( V_43 >= 0 ) {
V_58 = F_27 ( V_4 , V_311 , V_56 ,
V_43 , V_4 -> V_79 ) ;
if ( V_58 < 0 )
return V_58 ;
F_153 ( V_4 , V_4 -> V_79 , V_43 ) ;
}
for ( V_285 = 0 ; V_285 < V_4 -> V_94 ; V_285 ++ ) {
if ( V_4 -> V_183 [ V_285 ] == V_85 ) {
V_4 -> V_182 [ V_285 ] = V_43 ;
V_4 -> V_175 [ V_285 ] = V_311 ;
break;
}
}
}
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_27 ;
const char * V_317 = NULL ;
int V_56 = 0 ;
int V_53 , V_58 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
T_3 V_85 = V_110 -> V_118 [ V_53 ] . V_85 ;
unsigned int V_65 ;
const char * V_311 ;
char V_40 [ 32 ] ;
if ( V_110 -> V_118 [ V_53 ] . type != V_120 )
continue;
V_65 = F_31 ( V_3 , V_85 , V_60 ) ;
if ( V_65 == - 1 || ! ( V_65 & V_281 ) )
continue;
V_311 = F_160 ( V_3 , V_110 , V_53 ) ;
if ( V_317 && ! strcmp ( V_311 , V_317 ) )
V_56 ++ ;
else
V_56 = 0 ;
V_317 = V_311 ;
snprintf ( V_40 , sizeof( V_40 ) , L_30 , V_311 ) ;
V_58 = F_22 ( V_4 , V_59 , V_40 , V_56 ,
F_28 ( V_85 , 3 , 0 , V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
return 0 ;
}
static int F_163 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_58 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ ) {
T_3 V_211 = V_4 -> V_116 [ V_53 ] ;
V_58 = F_22 ( V_4 , V_59 ,
L_31 , V_53 ,
F_28 ( V_211 , 3 , 0 ,
V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_22 ( V_4 , V_282 ,
L_32 , V_53 ,
F_28 ( V_211 , 3 , 0 ,
V_60 ) ) ;
if ( V_58 < 0 )
return V_58 ;
}
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ )
if ( ! V_4 -> V_125 [ V_53 ] )
break;
V_58 = F_152 ( V_3 , V_53 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_4 , struct V_318 * * V_319 ,
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
static int F_165 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_41 ;
int V_58 ;
V_58 = F_164 ( V_4 , & V_4 -> V_247 , & V_323 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_164 ( V_4 , & V_4 -> V_248 , & V_324 ) ;
if ( V_58 < 0 )
return V_58 ;
V_41 = F_70 ( V_4 , & V_325 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_50 = ( long ) V_4 -> V_247 ;
V_41 = F_70 ( V_4 , & V_326 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_50 = ( long ) V_4 -> V_248 ;
V_58 = F_152 ( V_3 , 1 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_58 ;
V_58 = F_158 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_127 )
V_58 = F_165 ( V_3 ) ;
else
V_58 = F_163 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_161 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_162 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static void F_167 ( struct V_2 * V_3 , T_3 V_62 )
{
unsigned int V_133 ;
unsigned char V_327 ;
V_133 = F_53 ( V_3 , V_62 ) ;
V_327 = ( unsigned char ) F_168 ( V_133 ) ;
V_327 = ( V_327 << 4 ) | F_169 ( V_133 ) ;
if ( F_55 ( V_133 ) == V_140
&& ( V_327 == 0xf0 || V_327 == 0xff ) ) {
V_133 = V_133 & ( ~ ( V_328 << 30 ) ) ;
F_170 ( V_3 , V_62 , V_133 ) ;
}
return;
}
static int F_171 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_36 -> V_148 . integer . V_148 [ 0 ] = V_4 -> V_31 ;
return 0 ;
}
static int F_172 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_44 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_44 = ! ! V_36 -> V_148 . integer . V_148 [ 0 ] ;
if ( V_4 -> V_31 == V_44 )
return 0 ;
V_4 -> V_31 = V_44 ;
if ( V_4 -> V_31 &&
F_173 ( V_3 , L_33 ) != 1 ) {
F_74 ( V_3 , 1 ) ;
F_71 ( V_3 ) ;
}
F_68 ( V_3 ) ;
F_9 ( V_4 ) ;
return 1 ;
}
static int F_174 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_58 ;
V_58 = F_175 ( V_3 , & V_4 -> V_27 , NULL ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! V_4 -> V_27 . V_93 && ! V_4 -> V_27 . V_28 [ 0 ] )
return - V_204 ;
V_58 = F_139 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_141 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_142 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_146 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_166 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
V_4 -> V_152 . V_203 = V_4 -> V_152 . V_153 * 2 ;
F_176 ( V_3 ) ;
F_177 ( V_3 ) ;
if ( V_4 -> V_42 . V_51 )
V_4 -> V_215 [ V_4 -> V_214 ++ ] = V_4 -> V_42 . V_51 ;
if ( V_4 -> V_155 && V_4 -> V_103 . V_74 ) {
V_58 = F_69 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_58 = F_78 ( V_3 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_4 -> V_329 [ 0 ] )
V_3 -> V_329 = V_4 -> V_329 ;
return 1 ;
}
static void F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_152 . V_216 )
F_38 ( V_3 , V_4 -> V_27 . V_330 [ 0 ] , V_98 ) ;
if ( V_4 -> V_329 [ 0 ] )
F_38 ( V_3 , V_4 -> V_27 . V_330 [ 1 ] , V_98 ) ;
}
static void F_179 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_218 )
return;
F_7 ( V_3 , V_4 -> V_27 . V_331 , 0 ,
V_87 , V_122 ) ;
}
static void F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_27 ;
unsigned int V_332 ;
int V_53 ;
if ( V_110 -> V_28 [ 0 ] && F_181 ( V_3 , V_110 -> V_28 [ 0 ] ) )
F_182 ( V_3 , V_110 -> V_28 [ 0 ] ,
V_264 | V_263 ) ;
if ( V_110 -> V_252 [ 0 ] )
V_332 = V_265 ;
else
V_332 = 0 ;
for ( V_53 = 0 ; V_53 < V_110 -> V_93 ; V_53 ++ ) {
if ( V_110 -> V_251 [ V_53 ] &&
F_181 ( V_3 , V_110 -> V_251 [ V_53 ] ) )
F_182 ( V_3 , V_110 -> V_251 [ V_53 ] ,
V_332 | V_263 ) ;
}
for ( V_53 = 0 ; V_53 < V_110 -> V_117 ; V_53 ++ ) {
if ( F_181 ( V_3 , V_110 -> V_118 [ V_53 ] . V_85 ) )
F_182 ( V_3 , V_110 -> V_118 [ V_53 ] . V_85 ,
V_263 ) ;
}
}
static int F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_333 ; V_53 ++ )
F_184 ( V_3 , V_4 -> V_334 [ V_53 ] ) ;
F_13 ( V_3 ) ;
F_81 ( V_3 , true ) ;
F_41 ( V_3 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
F_178 ( V_3 ) ;
F_179 ( V_3 ) ;
F_180 ( V_3 ) ;
F_68 ( V_3 ) ;
F_9 ( V_4 ) ;
F_125 ( V_3 ) ;
return 0 ;
}
static void F_185 ( struct V_335 * V_336 )
{
struct V_1 * V_4 = F_186 ( V_336 , struct V_1 ,
V_30 . V_336 ) ;
if ( V_4 -> V_7 != V_15 )
return;
F_187 ( V_4 -> V_3 ) ;
if ( V_4 -> V_337
!= F_54 ( V_4 -> V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ) {
V_4 -> V_337 ^= 1 ;
F_68 ( V_4 -> V_3 ) ;
}
if ( V_4 -> V_31 )
F_11 ( & V_4 -> V_30 ,
F_12 ( 100 ) ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_62 , V_111 [ 8 ] ;
unsigned int type ;
int V_53 , V_338 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_115 ; V_53 ++ ) {
V_62 = V_4 -> V_116 [ V_53 ] ;
while ( V_62 ) {
type = F_49 ( F_30 ( V_3 , V_62 ) ) ;
if ( type == V_128 )
break;
V_338 = F_47 ( V_3 , V_62 , V_111 ,
F_48 ( V_111 ) ) ;
if ( V_338 <= 0 )
break;
if ( V_338 > 1 ) {
V_4 -> V_125 [ V_53 ] = V_62 ;
break;
}
V_62 = V_111 [ 0 ] ;
}
}
return 0 ;
}
static int F_188 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x17 ;
F_167 ( V_3 , V_339 ) ;
F_167 ( V_3 , V_340 ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
if ( ! F_70 ( V_4 , & V_341 ) )
return - V_46 ;
if ( V_3 -> V_11 == 0x11061708 )
V_4 -> V_228 = & V_342 ;
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_343 ;
V_3 -> V_344 = V_345 ;
F_189 ( & V_4 -> V_30 , F_185 ) ;
return 0 ;
}
static int F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x18 ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_3 -> V_344 = V_345 ;
return 0 ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_346 ;
unsigned int V_129 ;
int V_347 = 0 ;
if ( ( V_4 -> V_7 != V_20 ) &&
( V_3 -> V_11 != 0x11064397 ) )
V_347 = 1 ;
V_346 =
( F_51 ( V_3 , 0x17 , 0 , V_348 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x1a , & V_129 ) ;
F_52 ( V_3 , 0x1b , & V_129 ) ;
F_52 ( V_3 , 0x1e , & V_129 ) ;
if ( V_346 )
V_129 = V_141 ;
F_50 ( V_3 , 0x17 , V_129 ) ;
F_50 ( V_3 , 0x13 , V_129 ) ;
F_50 ( V_3 , 0x14 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x19 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x1b , & V_129 ) ;
F_50 ( V_3 , 0x18 , V_129 ) ;
F_50 ( V_3 , 0x11 , V_129 ) ;
if ( V_347 ) {
V_129 = V_142 ;
F_52 ( V_3 , 0x22 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x1a , & V_129 ) ;
F_50 ( V_3 , 0x26 , V_129 ) ;
F_50 ( V_3 , 0x24 , V_129 ) ;
} else if ( V_3 -> V_11 == 0x11064397 ) {
V_129 = V_142 ;
F_52 ( V_3 , 0x23 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x1a , & V_129 ) ;
F_50 ( V_3 , 0x27 , V_129 ) ;
F_50 ( V_3 , 0x25 , V_129 ) ;
}
V_129 = V_142 ;
F_52 ( V_3 , 0x1c , & V_129 ) ;
F_52 ( V_3 , 0x1d , & V_129 ) ;
if ( V_347 )
F_52 ( V_3 , 0x23 , & V_129 ) ;
F_50 ( V_3 , 0x16 , V_346 ? V_141 : V_129 ) ;
F_50 ( V_3 , 0x10 , V_129 ) ;
if ( V_347 ) {
F_50 ( V_3 , 0x25 , V_129 ) ;
F_50 ( V_3 , 0x27 , V_129 ) ;
} else if ( V_3 -> V_11 == 0x11064397 && V_4 -> V_101 )
F_50 ( V_3 , 0x25 , V_129 ) ;
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
if ( F_4 ( V_3 ) == V_8 )
return F_193 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_3 -> V_344 = V_345 ;
V_4 -> F_13 = F_191 ;
return 0 ;
}
static void F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_27 . V_349 ; V_53 ++ ) {
T_3 V_62 ;
int V_111 ;
V_62 = V_4 -> V_27 . V_330 [ V_53 ] ;
if ( ! V_62 )
continue;
V_111 = F_47 ( V_3 , V_62 , & V_62 , 1 ) ;
if ( V_111 < 1 )
continue;
if ( ! V_4 -> V_152 . V_216 )
V_4 -> V_152 . V_216 = V_62 ;
else {
V_4 -> V_329 [ 0 ] = V_62 ;
break;
}
}
}
static void F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_350 ;
int V_53 , V_58 ;
if ( ! V_4 -> V_27 . V_331 )
return;
V_350 = V_3 -> V_305 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_306 ; V_53 ++ , V_350 ++ ) {
unsigned int V_307 = F_30 ( V_3 , V_350 ) ;
if ( F_49 ( V_307 ) != V_308 )
continue;
if ( ! ( V_307 & V_309 ) )
continue;
if ( ! ( V_307 & V_310 ) )
continue;
V_58 = F_140 ( V_3 , V_350 ,
V_4 -> V_27 . V_331 ) ;
if ( V_58 >= 0 ) {
V_4 -> V_218 = V_350 ;
break;
}
}
}
static void F_194 ( struct V_2 * V_3 , T_3 V_85 ,
int V_351 , int V_352 , int V_353 )
{
F_195 ( V_3 , V_85 , V_60 ,
( V_351 << V_92 ) |
( V_352 << V_354 ) |
( V_353 << V_355 ) |
( 0 << V_356 ) ) ;
}
static int F_193 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
F_194 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_194 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_357 ;
V_3 -> V_344 = V_345 ;
if ( F_4 ( V_3 ) == V_8 ) {
F_25 ( V_3 -> V_227 ) ;
V_3 -> V_227 = F_21 ( L_34 , V_5 ) ;
snprintf ( V_3 -> V_176 -> V_177 -> V_358 ,
sizeof( V_3 -> V_176 -> V_177 -> V_358 ) ,
L_35 , V_3 -> V_359 , V_3 -> V_227 ) ;
}
if ( V_3 -> V_11 == 0x11064397 ) {
F_25 ( V_3 -> V_227 ) ;
V_3 -> V_227 = F_21 ( L_36 , V_5 ) ;
snprintf ( V_3 -> V_176 -> V_177 -> V_358 ,
sizeof( V_3 -> V_176 -> V_177 -> V_358 ) ,
L_35 , V_3 -> V_359 , V_3 -> V_227 ) ;
}
V_4 -> F_13 = F_191 ;
return 0 ;
}
static void F_196 ( struct V_2 * V_3 )
{
int V_346 =
F_51 ( V_3 , 0x13 , 0 , V_348 , 0x00 ) == 3 ;
unsigned int V_129 ;
V_129 = V_142 ;
F_52 ( V_3 , 0x14 , & V_129 ) ;
F_52 ( V_3 , 0x15 , & V_129 ) ;
F_52 ( V_3 , 0x18 , & V_129 ) ;
if ( V_346 )
V_129 = V_141 ;
F_50 ( V_3 , 0x13 , V_129 ) ;
F_50 ( V_3 , 0x12 , V_129 ) ;
F_50 ( V_3 , 0x1f , V_129 ) ;
F_50 ( V_3 , 0x20 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x17 , & V_129 ) ;
F_52 ( V_3 , 0x16 , & V_129 ) ;
F_50 ( V_3 , 0x1a , V_346 ? V_141 : V_129 ) ;
F_50 ( V_3 , 0x10 , V_129 ) ;
F_50 ( V_3 , 0x1d , V_129 ) ;
}
static int F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x1a ;
F_195 ( V_3 , 0x1A , V_60 ,
( 0x17 << V_92 ) |
( 0x17 << V_354 ) |
( 0x5 << V_355 ) |
( 1 << V_356 ) ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_360 ;
V_3 -> V_344 = V_345 ;
V_4 -> F_13 = F_196 ;
return 0 ;
}
static void F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_346 ;
unsigned int V_129 ;
V_346 =
F_51 ( V_3 , 0x1e , 0 , V_348 , 0x00 ) == 5 ;
V_129 = V_142 ;
F_52 ( V_3 , 0x29 , & V_129 ) ;
F_52 ( V_3 , 0x2a , & V_129 ) ;
F_52 ( V_3 , 0x2b , & V_129 ) ;
if ( V_346 )
V_129 = V_141 ;
F_50 ( V_3 , 0x1e , V_129 ) ;
F_50 ( V_3 , 0x1f , V_129 ) ;
F_50 ( V_3 , 0x10 , V_129 ) ;
F_50 ( V_3 , 0x11 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x27 , & V_129 ) ;
F_50 ( V_3 , 0x1a , V_129 ) ;
F_50 ( V_3 , 0xb , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x26 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x2b , & V_129 ) ;
F_50 ( V_3 , 0xa , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x24 , & V_129 ) ;
if ( ! V_4 -> V_101 )
F_52 ( V_3 , 0x28 , & V_129 ) ;
F_50 ( V_3 , 0x8 , V_129 ) ;
F_50 ( V_3 , 0x21 , V_346 ? V_141 : V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x25 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x2a , & V_129 ) ;
F_50 ( V_3 , 0x9 , V_129 ) ;
if ( V_4 -> V_101 ) {
V_129 = V_142 ;
F_52 ( V_3 , 0x28 , & V_129 ) ;
F_50 ( V_3 , 0x1b , V_129 ) ;
F_50 ( V_3 , 0x34 , V_129 ) ;
F_50 ( V_3 , 0xc , V_129 ) ;
}
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 , V_253 ;
T_3 V_111 [ 8 ] ;
T_3 V_62 ;
if ( ! V_4 -> V_79 )
return 0 ;
V_253 = F_47 ( V_3 , V_4 -> V_79 , V_111 ,
F_48 ( V_111 ) - 1 ) ;
for ( V_53 = 0 ; V_53 < V_253 ; V_53 ++ ) {
if ( F_49 ( F_30 ( V_3 , V_111 [ V_53 ] ) ) == V_271 )
return 0 ;
}
V_62 = V_3 -> V_305 ;
for ( V_53 = 0 ; V_53 < V_3 -> V_306 ; V_53 ++ , V_62 ++ ) {
unsigned int V_65 = F_30 ( V_3 , V_62 ) ;
if ( F_49 ( V_65 ) == V_271 &&
! ( V_65 & V_309 ) ) {
V_111 [ V_253 ++ ] = V_62 ;
return F_200 ( V_3 ,
V_4 -> V_79 ,
V_253 , V_111 ) ;
}
}
return 0 ;
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_194 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_194 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_199 ( V_3 ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_361 ;
V_3 -> V_344 = V_345 ;
V_4 -> F_13 = F_198 ;
return 0 ;
}
static int F_202 ( struct V_33 * V_34 ,
struct V_143 * V_144 )
{
V_144 -> type = V_362 ;
V_144 -> V_147 = 1 ;
V_144 -> V_148 . integer . V_363 = 0 ;
V_144 -> V_148 . integer . V_364 = 1 ;
return 0 ;
}
static int F_203 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
int V_47 = 0 ;
V_47 = F_51 ( V_3 , 0x26 , 0 ,
V_348 , 0 ) ;
if ( V_47 != - 1 )
* V_36 -> V_148 . integer . V_148 = V_47 ;
return 0 ;
}
static int F_204 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_16 ( V_34 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_47 = * V_36 -> V_148 . integer . V_148 ;
F_7 ( V_3 , 0x26 , 0 ,
V_78 , V_47 ) ;
V_4 -> V_365 = V_47 ;
F_13 ( V_3 ) ;
return 1 ;
}
static void F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_346 ;
unsigned int V_129 ;
unsigned int V_366 , V_138 ;
V_346 =
( F_51 ( V_3 , 0x17 , 0 ,
V_348 , 0x00 ) == 5 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x1a , & V_129 ) ;
F_52 ( V_3 , 0x1b , & V_129 ) ;
F_52 ( V_3 , 0x1e , & V_129 ) ;
if ( V_346 )
V_129 = V_141 ;
F_50 ( V_3 , 0x17 , V_129 ) ;
F_50 ( V_3 , 0x13 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x1e , & V_129 ) ;
if ( V_4 -> V_365 )
F_52 ( V_3 , 0x22 , & V_129 ) ;
else
F_50 ( V_3 , 0x22 , V_142 ) ;
F_50 ( V_3 , 0x26 , V_129 ) ;
F_50 ( V_3 , 0x14 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x19 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x1b , & V_129 ) ;
F_50 ( V_3 , 0x18 , V_129 ) ;
F_50 ( V_3 , 0x11 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x23 , & V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x1a , & V_129 ) ;
F_50 ( V_3 , 0x27 , V_129 ) ;
if ( V_4 -> V_119 )
F_52 ( V_3 , 0x1e , & V_129 ) ;
F_50 ( V_3 , 0x25 , V_129 ) ;
V_138 = F_54 ( V_3 , 0x1c ) ;
if ( V_138 )
V_366 = 0 ;
else {
V_138 = F_54 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_101 && V_138 )
V_366 = 0 ;
else
V_366 = 1 ;
}
V_129 = V_366 ? V_141 : V_142 ;
F_50 ( V_3 , 0x28 , V_129 ) ;
F_50 ( V_3 , 0x29 , V_129 ) ;
F_50 ( V_3 , 0x2a , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x1c , & V_129 ) ;
F_52 ( V_3 , 0x1d , & V_129 ) ;
if ( V_4 -> V_101 )
F_50 ( V_3 , 0x25 , V_129 ) ;
F_50 ( V_3 , 0x16 , V_346 ? V_141 : V_129 ) ;
F_50 ( V_3 , 0x10 , V_366 ? V_141 : V_129 ) ;
}
static int F_206 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x16 ;
F_194 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_194 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_367 ;
V_4 -> V_215 [ V_4 -> V_214 ] = V_368 ;
V_4 -> V_214 ++ ;
V_4 -> V_215 [ V_4 -> V_214 ++ ] = V_369 ;
V_3 -> V_344 = V_345 ;
V_4 -> F_13 = F_205 ;
return 0 ;
}
static void F_207 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_346 ;
unsigned int V_129 ;
unsigned int V_138 ;
V_346 =
F_51 ( V_3 , 0x1e , 0 , V_348 , 0x00 ) == 3 ;
V_129 = V_142 ;
F_52 ( V_3 , 0x29 , & V_129 ) ;
F_52 ( V_3 , 0x2a , & V_129 ) ;
F_52 ( V_3 , 0x2b , & V_129 ) ;
V_129 = V_141 ;
F_50 ( V_3 , 0x1e , V_129 ) ;
F_50 ( V_3 , 0x1f , V_129 ) ;
F_50 ( V_3 , 0x10 , V_129 ) ;
F_50 ( V_3 , 0x11 , V_129 ) ;
F_50 ( V_3 , 0x8 , V_129 ) ;
if ( V_4 -> V_7 == V_26 ) {
V_129 = V_142 ;
F_52 ( V_3 , 0x28 , & V_129 ) ;
F_50 ( V_3 , 0x18 , V_129 ) ;
F_50 ( V_3 , 0x38 , V_129 ) ;
} else {
V_129 = V_142 ;
F_52 ( V_3 , 0x26 , & V_129 ) ;
F_50 ( V_3 , 0x1c , V_129 ) ;
F_50 ( V_3 , 0x37 , V_129 ) ;
}
if ( V_4 -> V_7 == V_26 ) {
V_129 = V_142 ;
F_52 ( V_3 , 0x25 , & V_129 ) ;
F_50 ( V_3 , 0x15 , V_129 ) ;
F_50 ( V_3 , 0x35 , V_129 ) ;
} else {
V_129 = V_142 ;
F_52 ( V_3 , 0x25 , & V_129 ) ;
F_50 ( V_3 , 0x19 , V_129 ) ;
F_50 ( V_3 , 0x35 , V_129 ) ;
}
if ( V_4 -> V_101 )
F_50 ( V_3 , 0x9 , V_141 ) ;
V_138 = F_54 ( V_3 , 0x25 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x24 , & V_129 ) ;
V_129 = V_138 ? V_142 : V_141 ;
if ( V_4 -> V_7 == V_26 )
F_50 ( V_3 , 0x14 , V_129 ) ;
else
F_50 ( V_3 , 0x18 , V_129 ) ;
F_50 ( V_3 , 0x34 , V_129 ) ;
V_138 = F_54 ( V_3 , 0x26 ) ;
V_129 = V_138 ? V_142 : V_141 ;
if ( V_4 -> V_7 == V_26 ) {
F_50 ( V_3 , 0x33 , V_129 ) ;
F_50 ( V_3 , 0x1c , V_129 ) ;
F_50 ( V_3 , 0x3c , V_129 ) ;
} else {
F_50 ( V_3 , 0x31 , V_129 ) ;
F_50 ( V_3 , 0x17 , V_129 ) ;
F_50 ( V_3 , 0x3b , V_129 ) ;
}
if ( V_346 || ! F_79 ( V_3 ) )
F_50 ( V_3 , 0x21 , V_141 ) ;
else
F_50 ( V_3 , 0x21 , V_142 ) ;
}
static int F_208 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_194 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_194 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_199 ( V_3 ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
if ( V_4 -> V_7 == V_26 )
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_370 ;
else
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_371 ;
V_3 -> V_344 = V_345 ;
V_4 -> F_13 = F_207 ;
return 0 ;
}
static void F_209 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_129 ;
unsigned int V_138 ;
V_129 = V_142 ;
F_52 ( V_3 , 0x29 , & V_129 ) ;
F_52 ( V_3 , 0x2a , & V_129 ) ;
F_52 ( V_3 , 0x2b , & V_129 ) ;
V_129 = V_141 ;
F_50 ( V_3 , 0x1e , V_129 ) ;
F_50 ( V_3 , 0x1f , V_129 ) ;
F_50 ( V_3 , 0x10 , V_129 ) ;
F_50 ( V_3 , 0x11 , V_129 ) ;
F_50 ( V_3 , 0x8 , V_141 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x28 , & V_129 ) ;
F_50 ( V_3 , 0x18 , V_129 ) ;
F_50 ( V_3 , 0x38 , V_129 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x25 , & V_129 ) ;
F_50 ( V_3 , 0x15 , V_129 ) ;
F_50 ( V_3 , 0x35 , V_129 ) ;
if ( V_4 -> V_101 )
F_50 ( V_3 , 0x9 , V_141 ) ;
V_138 = F_54 ( V_3 , 0x25 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x24 , & V_129 ) ;
if ( V_138 ) {
F_50 ( V_3 , 0x14 , V_142 ) ;
F_50 ( V_3 , 0x34 , V_142 ) ;
} else {
F_50 ( V_3 , 0x14 , V_141 ) ;
F_50 ( V_3 , 0x34 , V_141 ) ;
}
V_138 = F_54 ( V_3 , 0x28 ) ;
V_129 = V_142 ;
F_52 ( V_3 , 0x31 , & V_129 ) ;
if ( V_138 ) {
F_50 ( V_3 , 0x1c , V_142 ) ;
F_50 ( V_3 , 0x3c , V_142 ) ;
F_50 ( V_3 , 0x3e , V_142 ) ;
} else {
F_50 ( V_3 , 0x1c , V_141 ) ;
F_50 ( V_3 , 0x3c , V_141 ) ;
F_50 ( V_3 , 0x3e , V_141 ) ;
}
V_129 = V_142 ;
F_52 ( V_3 , 0x33 , & V_129 ) ;
F_50 ( V_3 , 0x1d , V_129 ) ;
F_50 ( V_3 , 0x3d , V_129 ) ;
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_58 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_79 = 0x21 ;
F_194 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_194 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_199 ( V_3 ) ;
V_58 = F_174 ( V_3 ) ;
if ( V_58 < 0 ) {
F_119 ( V_3 ) ;
return V_58 ;
}
V_4 -> V_334 [ V_4 -> V_333 ++ ] = V_372 ;
V_3 -> V_344 = V_345 ;
V_4 -> F_13 = F_209 ;
return 0 ;
}
static int T_5 F_211 ( void )
{
return F_212 ( & V_373 ) ;
}
static void T_6 F_213 ( void )
{
F_214 ( & V_373 ) ;
}
