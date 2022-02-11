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
F_5 ( & V_4 -> V_10 ) ;
return V_4 ;
}
static enum V_11 F_4 ( struct V_2 * V_3 )
{
T_1 V_12 = V_3 -> V_12 ;
T_2 V_13 = V_12 >> 16 ;
T_2 V_14 = V_12 & 0xffff ;
enum V_11 V_7 ;
if ( V_13 != 0x1106 )
V_7 = V_15 ;
else if ( V_14 >= 0x1708 && V_14 <= 0x170b )
V_7 = V_16 ;
else if ( V_14 >= 0xe710 && V_14 <= 0xe713 )
V_7 = V_17 ;
else if ( V_14 >= 0xe714 && V_14 <= 0xe717 )
V_7 = V_18 ;
else if ( V_14 >= 0xe720 && V_14 <= 0xe723 ) {
V_7 = V_19 ;
if ( F_6 ( V_3 , 0x16 , V_20 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_14 >= 0xe724 && V_14 <= 0xe727 )
V_7 = V_21 ;
else if ( ( V_14 & 0xfff ) == 0x397
&& ( V_14 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_14 & 0xfff ) == 0x398
&& ( V_14 >> 12 ) < 8 )
V_7 = V_22 ;
else if ( ( V_14 & 0xfff ) == 0x428
&& ( V_14 >> 12 ) < 8 )
V_7 = V_23 ;
else if ( V_14 == 0x0433 || V_14 == 0xa721 )
V_7 = V_24 ;
else if ( V_14 == 0x0441 || V_14 == 0x4441 )
V_7 = V_23 ;
else if ( V_14 == 0x0438 || V_14 == 0x4438 )
V_7 = V_25 ;
else if ( V_14 == 0x0448 )
V_7 = V_26 ;
else if ( V_14 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_14 & 0xfff ) == 0x446 )
V_7 = V_27 ;
else
V_7 = V_15 ;
return V_7 ;
}
static void F_7 ( struct V_1 * V_4 )
{
if ( V_4 -> V_7 != V_16 || V_4 -> V_28 . V_29 [ 0 ] == 0 )
return;
if ( V_4 -> V_30 ) {
F_8 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
F_9 ( & V_4 -> V_31 ) ;
V_4 -> V_30 = 0 ;
}
}
static void F_10 ( struct V_1 * V_4 )
{
if ( V_4 -> V_7 != V_16 || V_4 -> V_28 . V_29 [ 0 ] == 0 )
return;
if ( V_4 -> V_32 &&
( V_4 -> V_33 || F_11 ( V_4 -> V_3 ) ) ) {
if ( ! V_4 -> V_30 ) {
F_8 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_12 ( & V_4 -> V_31 ,
F_13 ( 100 ) ) ;
V_4 -> V_30 = 1 ;
}
} else if ( ! F_11 ( V_4 -> V_3 ) )
F_7 ( V_4 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> F_14 )
V_4 -> F_14 ( V_3 ) ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
int V_38 = F_16 ( V_35 , V_37 ) ;
struct V_2 * V_3 = F_17 ( V_35 ) ;
F_14 ( V_3 ) ;
F_18 ( F_17 ( V_35 ) ) ;
F_10 ( V_3 -> V_4 ) ;
return V_38 ;
}
static struct V_39 * F_19 ( struct V_1 * V_4 ,
const struct V_39 * V_40 ,
const char * V_41 )
{
struct V_39 * V_42 ;
F_20 ( & V_4 -> V_43 , sizeof( * V_42 ) , 32 ) ;
V_42 = F_21 ( & V_4 -> V_43 ) ;
if ( ! V_42 )
return NULL ;
* V_42 = * V_40 ;
if ( ! V_41 )
V_41 = V_40 -> V_41 ;
if ( V_41 ) {
V_42 -> V_41 = F_22 ( V_41 , V_5 ) ;
if ( ! V_42 -> V_41 )
return NULL ;
}
return V_42 ;
}
static int F_23 ( struct V_1 * V_4 , int type , const char * V_41 ,
int V_44 , unsigned long V_45 )
{
struct V_39 * V_42 ;
V_42 = F_19 ( V_4 , & V_46 [ type ] , V_41 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_48 = V_44 ;
if ( F_24 ( V_45 ) )
V_42 -> V_49 = V_50 ;
V_42 -> V_51 = V_45 ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_43 . V_52 ) {
struct V_39 * V_53 = V_4 -> V_43 . V_52 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_43 . V_55 ; V_54 ++ )
F_26 ( V_53 [ V_54 ] . V_41 ) ;
}
F_27 ( & V_4 -> V_43 ) ;
}
static int F_28 ( struct V_1 * V_4 , const char * V_56 ,
int V_57 , int V_44 , int V_58 )
{
char V_41 [ 32 ] ;
int V_59 ;
sprintf ( V_41 , L_1 , V_56 ) ;
V_59 = F_23 ( V_4 , V_60 , V_41 , V_57 ,
F_29 ( V_58 , 3 , V_44 , V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
sprintf ( V_41 , L_2 , V_56 ) ;
V_59 = F_23 ( V_4 , V_62 , V_41 , V_57 ,
F_29 ( V_58 , 3 , V_44 , V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static bool F_30 ( struct V_2 * V_3 , T_3 V_63 , int V_64 ,
unsigned int V_65 )
{
unsigned int V_66 ;
if ( ! V_63 )
return false ;
V_66 = F_31 ( V_3 , V_63 ) ;
if ( V_64 == V_61 )
V_66 &= V_67 ;
else
V_66 &= V_68 ;
if ( ! V_66 )
return false ;
if ( F_32 ( V_3 , V_63 , V_64 ) & V_65 )
return true ;
return false ;
}
static void F_33 ( struct V_2 * V_3 , struct V_69 * V_70 ,
T_3 V_58 , int V_44 , bool V_71 )
{
int V_54 , V_72 , V_45 ;
if ( ! V_70 )
return;
V_72 = F_34 ( V_3 , V_58 ) ;
for ( V_54 = 0 ; V_54 < V_72 ; V_54 ++ ) {
if ( V_54 == V_44 )
V_45 = F_35 ( V_54 ) ;
else
V_45 = F_36 ( V_54 ) ;
F_8 ( V_3 , V_58 , 0 ,
V_73 , V_45 ) ;
}
}
static void F_37 ( struct V_2 * V_3 , struct V_69 * V_70 ,
bool V_71 , bool V_74 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_70 -> V_75 ; V_54 ++ ) {
T_3 V_76 , V_77 ;
int V_44 = V_70 -> V_44 [ V_54 ] ;
V_76 = V_70 -> V_70 [ V_54 ] ;
if ( V_54 < V_70 -> V_75 - 1 )
V_77 = V_70 -> V_70 [ V_54 + 1 ] ;
else
V_77 = 0 ;
if ( V_71 && V_70 -> V_78 [ V_54 ] )
F_8 ( V_3 , V_77 , 0 ,
V_79 , V_44 ) ;
if ( ! V_74 && ( V_77 == V_4 -> V_80 ) )
continue;
if ( F_38 ( V_3 , V_77 , V_61 ) )
F_33 ( V_3 , V_70 , V_77 , V_44 , V_71 ) ;
if ( ! V_74 && ( V_76 == V_70 -> V_81 || V_76 == V_70 -> V_82 ) )
continue;
if ( F_38 ( V_3 , V_76 , V_83 ) ) {
int V_45 = V_71 ? V_84 : V_85 ;
F_8 ( V_3 , V_76 , 0 ,
V_73 , V_45 ) ;
}
}
}
static void F_39 ( struct V_2 * V_3 , T_3 V_86 ,
int V_87 )
{
if ( ! V_86 )
return;
F_40 ( V_3 , V_86 , V_87 ) ;
if ( F_41 ( V_3 , V_86 ) & V_88 )
F_8 ( V_3 , V_86 , 0 ,
V_89 , 0x02 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_69 * V_70 , int V_87 )
{
unsigned int V_66 ;
T_3 V_86 ;
if ( ! V_70 -> V_75 )
return;
V_86 = V_70 -> V_70 [ V_70 -> V_75 - 1 ] ;
F_39 ( V_3 , V_86 , V_87 ) ;
if ( F_31 ( V_3 , V_86 ) & V_68 )
V_66 = F_32 ( V_3 , V_86 , V_83 ) ;
else
V_66 = 0 ;
if ( V_66 & V_90 ) {
unsigned int V_45 ;
V_45 = ( V_66 & V_91 ) >> V_92 ;
F_8 ( V_3 , V_86 , 0 , V_73 ,
V_85 | V_45 ) ;
}
F_37 ( V_3 , V_70 , true , true ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_69 * V_70 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_28 . V_93 + V_4 -> V_94 ; V_54 ++ ) {
V_70 = & V_4 -> V_95 [ V_54 ] ;
if ( ! V_54 && V_4 -> V_96 && V_4 -> V_97 . V_75 )
V_70 = & V_4 -> V_97 ;
F_42 ( V_3 , V_70 , V_98 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_99 = V_4 -> V_100 ;
if ( V_4 -> V_101 ) {
F_37 ( V_3 , & V_4 -> V_102 , false , false ) ;
F_37 ( V_3 , & V_4 -> V_103 , false , false ) ;
if ( V_99 )
F_37 ( V_3 , & V_4 -> V_95 [ V_99 ] ,
false , false ) ;
} else if ( V_4 -> V_96 || ! V_4 -> V_102 . V_75 ) {
F_37 ( V_3 , & V_4 -> V_104 , false , false ) ;
F_37 ( V_3 , & V_4 -> V_102 , false , false ) ;
} else {
F_37 ( V_3 , & V_4 -> V_104 , false , false ) ;
F_37 ( V_3 , & V_4 -> V_103 , false , false ) ;
}
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_102 . V_75 ) {
F_42 ( V_3 , & V_4 -> V_103 , V_105 ) ;
return;
}
F_44 ( V_3 ) ;
if ( V_4 -> V_101 )
F_42 ( V_3 , & V_4 -> V_104 , V_105 ) ;
else if ( V_4 -> V_96 )
F_42 ( V_3 , & V_4 -> V_103 , V_105 ) ;
else
F_42 ( V_3 , & V_4 -> V_102 , V_105 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_28 . V_106 )
return;
if ( ! V_4 -> V_107 . V_75 ) {
F_42 ( V_3 , & V_4 -> V_108 , V_98 ) ;
return;
}
if ( ! V_4 -> V_96 ) {
F_37 ( V_3 , & V_4 -> V_108 ,
false , false ) ;
F_42 ( V_3 , & V_4 -> V_107 , V_98 ) ;
} else {
F_37 ( V_3 , & V_4 -> V_107 , false , false ) ;
F_42 ( V_3 , & V_4 -> V_108 , V_98 ) ;
}
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_28 ;
T_3 V_111 [ V_112 ] ;
unsigned int V_113 ;
int V_54 , V_114 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_115 ; V_54 ++ ) {
T_3 V_63 = V_4 -> V_116 [ V_54 ] ;
if ( ! ( F_31 ( V_3 , V_63 ) & V_67 ) ||
! ( F_32 ( V_3 , V_63 , V_61 ) & V_90 ) )
continue;
F_8 ( V_3 , V_4 -> V_116 [ V_54 ] , 0 ,
V_73 ,
F_35 ( 0 ) ) ;
}
for ( V_54 = 0 ; V_54 < V_110 -> V_117 ; V_54 ++ ) {
T_3 V_63 = V_110 -> V_118 [ V_54 ] . V_86 ;
if ( V_4 -> V_119 && F_48 ( V_3 , V_63 ) )
V_113 = V_98 ;
else {
V_113 = V_120 ;
if ( V_110 -> V_118 [ V_54 ] . type == V_121 )
V_113 |= F_49 ( V_3 , V_63 ) ;
}
F_40 ( V_3 , V_63 , V_113 ) ;
}
for ( V_54 = 0 ; V_54 < V_4 -> V_115 ; V_54 ++ ) {
int V_122 = V_4 -> V_118 [ V_4 -> V_123 [ V_54 ] ] . V_122 ;
if ( V_54 > 0 && ! V_4 -> V_124 [ V_54 ] )
break;
if ( V_4 -> V_124 [ V_122 ] ) {
int V_125 = V_4 -> V_118 [ V_4 -> V_123 [ V_54 ] ] . V_125 ;
F_8 ( V_3 , V_4 -> V_124 [ V_122 ] , 0 ,
V_79 ,
V_125 ) ;
}
if ( V_4 -> V_126 )
break;
}
if ( ! V_4 -> V_80 )
return;
V_114 = F_50 ( V_3 , V_4 -> V_80 , V_111 ,
F_51 ( V_111 ) ) ;
for ( V_54 = 0 ; V_54 < V_114 ; V_54 ++ ) {
unsigned int V_66 = F_31 ( V_3 , V_111 [ V_54 ] ) ;
if ( F_52 ( V_66 ) == V_127 )
F_8 ( V_3 , V_4 -> V_80 , 0 ,
V_73 ,
F_36 ( V_54 ) ) ;
}
}
static void F_53 ( struct V_2 * V_3 , T_3 V_63 ,
unsigned int V_128 )
{
if ( F_54 ( V_3 , V_63 , 0 ,
V_129 , 0 ) == V_128 )
return;
F_8 ( V_3 , V_63 , 0 , V_130 , V_128 ) ;
}
static void F_55 ( struct V_2 * V_3 , T_3 V_63 ,
unsigned int * V_131 )
{
unsigned V_128 ;
unsigned V_132 = F_56 ( V_3 , V_63 ) ;
unsigned V_133 = ( V_132 & V_134 )
>> V_135
& V_136 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_137 = 0 ;
V_133 |= V_4 -> V_138 ;
if ( ! V_133 )
V_137 = F_57 ( V_3 , V_63 ) ;
if ( ( V_4 -> V_119 && F_48 ( V_3 , V_63 ) )
|| ( ( V_133 || V_137 )
&& F_58 ( V_132 ) != V_139 ) ) {
* V_131 = V_140 ;
V_128 = V_140 ;
} else
V_128 = V_141 ;
F_53 ( V_3 , V_63 , V_128 ) ;
}
static int F_59 ( struct V_34 * V_35 ,
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
strcpy ( V_143 -> V_147 . V_148 . V_41 ,
V_144 [ V_143 -> V_147 . V_148 . V_150 ] ) ;
return 0 ;
}
static int F_60 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_37 -> V_147 . V_148 . V_150 [ 0 ] = ! V_4 -> V_138 ;
return 0 ;
}
static int F_61 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_45 = ! V_37 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_45 == V_4 -> V_138 )
return 0 ;
V_4 -> V_138 = V_45 ;
F_14 ( V_3 ) ;
F_18 ( V_3 ) ;
return 1 ;
}
static int F_62 ( struct V_34 * V_35 ,
struct V_142 * V_143 )
{
static const char * const V_144 [] = { L_5 , L_6 } ;
V_143 -> type = V_145 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . V_148 . V_149 = 2 ;
if ( V_143 -> V_147 . V_148 . V_150 >= 2 )
V_143 -> V_147 . V_148 . V_150 = 1 ;
strcpy ( V_143 -> V_147 . V_148 . V_41 ,
V_144 [ V_143 -> V_147 . V_148 . V_150 ] ) ;
return 0 ;
}
static int F_63 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_37 -> V_147 . V_148 . V_150 [ 0 ] = V_4 -> V_101 ;
return 0 ;
}
static void F_64 ( struct V_1 * V_4 )
{
const struct V_109 * V_110 = & V_4 -> V_28 ;
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
static void F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_99 = V_4 -> V_100 ;
T_3 V_155 , V_156 ;
if ( ! V_4 -> V_157 )
return;
V_155 = V_99 ? V_4 -> V_151 . V_158 [ V_99 ] : 0 ;
V_156 = V_4 -> V_154 ;
if ( V_4 -> V_101 ) {
if ( V_4 -> V_33 & V_159 ) {
F_66 ( V_3 , V_156 , 1 ) ;
F_66 ( V_3 , V_155 , 1 ) ;
}
if ( V_4 -> V_33 & V_160 )
F_67 ( V_3 , V_156 ,
V_4 -> V_161 , 0 ,
V_4 -> V_162 ) ;
} else {
if ( V_4 -> V_33 & V_160 )
F_66 ( V_3 , V_156 , 1 ) ;
if ( V_4 -> V_33 & V_159 ) {
T_3 V_163 ;
int V_164 ;
if ( V_155 ) {
V_163 = V_155 ;
V_164 = V_99 * 2 ;
} else {
V_163 = V_156 ;
V_164 = 0 ;
}
F_67 ( V_3 , V_163 ,
V_4 -> V_165 , V_164 ,
V_4 -> V_166 ) ;
}
}
F_64 ( V_4 ) ;
}
static int F_68 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_167 , V_99 ;
F_69 ( & V_4 -> V_6 ) ;
V_167 = ! ! V_37 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_4 -> V_101 == V_167 ) {
F_70 ( & V_4 -> V_6 ) ;
return 0 ;
}
V_4 -> V_101 = V_167 ;
V_99 = V_4 -> V_100 ;
F_44 ( V_3 ) ;
if ( V_167 )
F_37 ( V_3 , & V_4 -> V_104 , true , false ) ;
else {
if ( V_99 )
F_37 ( V_3 , & V_4 -> V_95 [ V_99 ] ,
true , false ) ;
if ( V_4 -> V_96 || ! V_4 -> V_102 . V_75 )
F_37 ( V_3 , & V_4 -> V_103 ,
true , false ) ;
else
F_37 ( V_3 , & V_4 -> V_102 ,
true , false ) ;
}
F_65 ( V_3 ) ;
F_70 ( & V_4 -> V_6 ) ;
F_14 ( V_3 ) ;
F_71 ( V_3 ) ;
return 1 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_39 * V_42 ;
T_3 V_63 ;
V_63 = V_4 -> V_28 . V_29 [ 0 ] ;
V_42 = F_73 ( V_4 , & V_168 ) ;
if ( V_42 == NULL )
return - V_47 ;
V_42 -> V_49 = V_169 | V_63 ;
return 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_94 ; V_54 ++ ) {
struct V_34 * V_113 ;
struct V_170 V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_172 = V_173 ;
sprintf ( V_171 . V_41 , L_1 , V_4 -> V_174 [ V_54 ] ) ;
V_113 = F_75 ( V_3 , V_171 . V_41 ) ;
if ( V_113 )
F_76 ( V_3 -> V_175 -> V_176 ,
V_177 ,
& V_113 -> V_171 ) ;
}
}
static void F_77 ( struct V_2 * V_3 , int V_178 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_45 = V_178 ? V_179 : V_180 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_94 ; V_54 ++ ) {
if ( V_4 -> V_181 [ V_54 ] < 0 )
continue;
F_78 ( V_3 , V_4 -> V_80 ,
V_61 , V_4 -> V_181 [ V_54 ] ,
V_179 , V_45 ) ;
}
}
static bool F_48 ( struct V_2 * V_3 , T_3 V_86 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_94 ; V_54 ++ )
if ( V_4 -> V_182 [ V_54 ] == V_86 )
return true ;
return false ;
}
static int F_79 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
* V_37 -> V_147 . integer . V_147 = V_4 -> V_119 ;
return 0 ;
}
static int F_80 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_183 = * V_37 -> V_147 . integer . V_147
? V_184 : V_185 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_94 ; V_54 ++ ) {
T_3 V_63 = V_4 -> V_182 [ V_54 ] ;
unsigned int V_128 ;
V_128 = F_54 ( V_3 , V_63 , 0 ,
V_186 , 0 ) ;
V_128 &= ~ ( V_185 | V_184 ) ;
V_128 |= V_183 ;
F_40 ( V_3 , V_63 , V_128 ) ;
if ( V_183 == V_184 ) {
F_77 ( V_3 , 1 ) ;
F_74 ( V_3 ) ;
}
}
V_4 -> V_119 = * V_37 -> V_147 . integer . V_147 ;
F_14 ( V_3 ) ;
return 1 ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_94 )
return 0 ;
if ( ! F_73 ( V_4 , & V_187 ) )
return - V_47 ;
return 0 ;
}
static bool F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_188 * V_189 ;
int V_54 , V_164 , V_190 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_191 ; V_54 ++ ) {
V_189 = & V_4 -> V_192 [ V_54 ] ;
for ( V_164 = 0 ; V_164 < 2 ; V_164 ++ ) {
V_190 = F_83 ( V_3 , V_189 -> V_63 , V_164 , V_189 -> V_64 ,
V_189 -> V_44 ) ;
if ( ! ( V_190 & V_179 ) && V_190 > 0 )
return false ;
}
}
return true ;
}
static void F_84 ( struct V_2 * V_3 , bool V_74 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_71 ;
unsigned int V_193 , V_128 ;
if ( V_4 -> V_138 )
V_71 = false ;
else
V_71 = F_82 ( V_3 ) && ! V_4 -> V_157 ;
if ( V_71 == V_4 -> V_194 && ! V_74 )
return;
V_4 -> V_194 = V_71 ;
switch ( V_4 -> V_7 ) {
case V_19 :
case V_21 :
V_193 = 0xf70 ;
V_128 = V_71 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_23 :
case V_24 :
V_193 = 0xf73 ;
V_128 = V_71 ? 0x51 : 0xe1 ;
break;
case V_22 :
V_193 = 0xf73 ;
V_128 = V_71 ? 0x01 : 0x1d ;
break;
case V_25 :
case V_26 :
case V_27 :
V_193 = 0xf93 ;
V_128 = V_71 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_8 ( V_3 , V_3 -> V_195 , 0 , V_193 , V_128 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
return F_84 ( V_3 , false ) ;
}
static void F_85 ( struct V_2 * V_3 , int V_196 , bool V_197 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_197 )
V_4 -> V_157 |= V_196 ;
else
V_4 -> V_157 &= ~ V_196 ;
F_18 ( V_3 ) ;
}
static int F_86 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_28 ;
int V_59 ;
V_4 -> V_151 . V_152 = V_110 -> V_93 + V_4 -> V_94 ;
V_4 -> V_151 . V_202 = V_4 -> V_151 . V_152 * 2 ;
F_85 ( V_3 , V_159 , true ) ;
V_59 = F_87 ( V_3 , & V_4 -> V_151 , V_201 ,
V_199 ) ;
if ( V_59 < 0 ) {
F_85 ( V_3 , V_159 , false ) ;
return V_59 ;
}
return 0 ;
}
static int F_88 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
F_85 ( V_3 , V_159 , false ) ;
return 0 ;
}
static int F_89 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_90 ( ! V_4 -> V_154 ) )
return - V_203 ;
F_85 ( V_3 , V_160 , true ) ;
return 0 ;
}
static int F_91 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
F_85 ( V_3 , V_160 , false ) ;
return 0 ;
}
static int F_92 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
unsigned int V_204 ,
unsigned int V_205 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_69 ( & V_4 -> V_6 ) ;
F_64 ( V_4 ) ;
F_93 ( V_3 , & V_4 -> V_151 , V_204 ,
V_205 , V_201 ) ;
V_4 -> V_33 |= V_159 ;
V_4 -> V_165 = V_204 ;
V_4 -> V_166 = V_205 ;
F_70 ( & V_4 -> V_6 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
unsigned int V_204 ,
unsigned int V_205 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_69 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_101 )
F_67 ( V_3 , V_4 -> V_154 ,
V_204 , 0 , V_205 ) ;
V_4 -> V_33 |= V_160 ;
V_4 -> V_161 = V_204 ;
V_4 -> V_162 = V_205 ;
F_70 ( & V_4 -> V_6 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_95 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_69 ( & V_4 -> V_6 ) ;
F_96 ( V_3 , & V_4 -> V_151 ) ;
V_4 -> V_33 &= ~ V_159 ;
F_70 ( & V_4 -> V_6 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_97 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_69 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_101 )
F_67 ( V_3 , V_4 -> V_154 , 0 , 0 , 0 ) ;
V_4 -> V_33 &= ~ V_160 ;
F_70 ( & V_4 -> V_6 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_98 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_99 ( V_3 , & V_4 -> V_151 ) ;
}
static int F_100 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_101 ( V_3 , & V_4 -> V_151 ) ;
}
static int F_102 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
unsigned int V_204 ,
unsigned int V_205 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_103 ( V_3 , & V_4 -> V_151 ,
V_204 , V_205 , V_201 ) ;
}
static int F_104 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_105 ( V_3 , & V_4 -> V_151 ) ;
return 0 ;
}
static int F_106 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
unsigned int V_204 ,
unsigned int V_205 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_67 ( V_3 , V_4 -> V_116 [ V_201 -> V_206 ] ,
V_204 , 0 , V_205 ) ;
return 0 ;
}
static int F_107 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_108 ( V_3 , V_4 -> V_116 [ V_201 -> V_206 ] ) ;
return 0 ;
}
static int F_109 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
unsigned int V_204 ,
unsigned int V_205 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_122 = V_4 -> V_118 [ V_4 -> V_123 [ 0 ] ] . V_122 ;
F_69 ( & V_4 -> V_6 ) ;
V_4 -> V_207 = V_4 -> V_116 [ V_122 ] ;
V_4 -> V_208 = V_204 ;
V_4 -> V_209 = V_205 ;
F_67 ( V_3 , V_4 -> V_207 , V_204 , 0 , V_205 ) ;
F_70 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_110 ( struct V_198 * V_199 ,
struct V_2 * V_3 ,
struct V_200 * V_201 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_69 ( & V_4 -> V_6 ) ;
F_108 ( V_3 , V_4 -> V_207 ) ;
V_4 -> V_207 = 0 ;
F_70 ( & V_4 -> V_6 ) ;
return 0 ;
}
static bool F_111 ( struct V_2 * V_3 , int V_167 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_122 = V_4 -> V_118 [ V_167 ] . V_122 ;
T_3 V_210 = V_4 -> V_116 [ V_122 ] ;
bool V_211 = false ;
F_69 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_207 && V_4 -> V_207 != V_210 ) {
F_66 ( V_3 , V_4 -> V_207 , 1 ) ;
V_4 -> V_207 = V_210 ;
F_67 ( V_3 , V_210 ,
V_4 -> V_208 , 0 ,
V_4 -> V_209 ) ;
V_211 = true ;
}
F_70 ( & V_4 -> V_6 ) ;
return V_211 ;
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_34 * V_53 ;
int V_59 , V_54 ;
V_4 -> V_138 = 1 ;
if ( V_4 -> F_14 )
if ( ! F_73 ( V_4 , & V_212 ) )
return - V_47 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_213 ; V_54 ++ ) {
V_59 = F_113 ( V_3 , V_4 -> V_214 [ V_54 ] ) ;
if ( V_59 < 0 )
return V_59 ;
}
if ( V_4 -> V_151 . V_215 ) {
V_59 = F_114 ( V_3 ,
V_4 -> V_151 . V_215 ,
V_4 -> V_151 . V_215 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_115 ( V_3 ,
& V_4 -> V_151 ) ;
if ( V_59 < 0 )
return V_59 ;
V_4 -> V_151 . V_216 = 1 ;
}
if ( V_4 -> V_217 ) {
V_59 = F_116 ( V_3 , V_4 -> V_217 ) ;
if ( V_59 < 0 )
return V_59 ;
}
if ( ! F_75 ( V_3 , L_7 ) ) {
unsigned int V_218 [ 4 ] ;
F_117 ( V_3 , V_4 -> V_151 . V_158 [ 0 ] ,
V_83 , V_218 ) ;
V_59 = F_118 ( V_3 , L_7 ,
V_218 , V_219 ,
L_8 ) ;
if ( V_59 < 0 )
return V_59 ;
}
if ( ! F_75 ( V_3 , L_9 ) ) {
V_59 = F_118 ( V_3 , L_9 ,
NULL , V_219 ,
L_10 ) ;
if ( V_59 < 0 )
return V_59 ;
}
V_53 = F_75 ( V_3 , L_11 ) ;
for ( V_54 = 0 ; V_53 && V_54 < V_53 -> V_146 ; V_54 ++ ) {
if ( ! V_4 -> V_124 [ V_54 ] )
continue;
V_59 = F_119 ( V_3 , V_53 , V_54 , V_4 -> V_124 [ V_54 ] ) ;
if ( V_59 < 0 )
return V_59 ;
}
F_25 ( V_3 ) ;
V_59 = F_120 ( V_3 , & V_4 -> V_28 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_220 * V_221 = V_4 -> V_222 ;
V_3 -> V_223 = 0 ;
V_3 -> V_224 = V_221 ;
if ( V_4 -> V_151 . V_152 || V_4 -> V_115 ) {
snprintf ( V_4 -> V_225 ,
sizeof( V_4 -> V_225 ) ,
L_12 , V_3 -> V_226 ) ;
V_221 -> V_41 = V_4 -> V_225 ;
if ( V_4 -> V_151 . V_152 ) {
if ( ! V_4 -> V_227 )
V_4 -> V_227 =
& V_228 ;
V_221 -> V_229 [ V_230 ] =
* V_4 -> V_227 ;
V_221 -> V_229 [ V_230 ] . V_63 =
V_4 -> V_151 . V_158 [ 0 ] ;
V_221 -> V_229 [ V_230 ] . V_231 =
V_4 -> V_151 . V_202 ;
}
if ( ! V_4 -> V_232 ) {
if ( V_4 -> V_126 )
V_4 -> V_232 =
& V_233 ;
else
V_4 -> V_232 =
& V_234 ;
}
if ( V_4 -> V_115 ) {
V_221 -> V_229 [ V_235 ] =
* V_4 -> V_232 ;
V_221 -> V_229 [ V_235 ] . V_63 =
V_4 -> V_116 [ 0 ] ;
if ( ! V_4 -> V_126 )
V_221 -> V_229 [ V_235 ] . V_236 =
V_4 -> V_115 ;
}
V_3 -> V_223 ++ ;
V_221 ++ ;
}
if ( V_4 -> V_151 . V_215 || V_4 -> V_217 ) {
snprintf ( V_4 -> V_237 ,
sizeof( V_4 -> V_237 ) ,
L_13 , V_3 -> V_226 ) ;
V_221 -> V_41 = V_4 -> V_237 ;
V_221 -> V_238 = V_239 ;
if ( V_4 -> V_151 . V_215 ) {
if ( ! V_4 -> V_240 )
V_4 -> V_240 =
& V_241 ;
V_221 -> V_229 [ V_230 ] =
* V_4 -> V_240 ;
V_221 -> V_229 [ V_230 ] . V_63 =
V_4 -> V_151 . V_215 ;
}
if ( V_4 -> V_217 ) {
if ( ! V_4 -> V_242 )
V_4 -> V_242 =
& V_243 ;
V_221 -> V_229 [ V_235 ] =
* V_4 -> V_242 ;
V_221 -> V_229 [ V_235 ] . V_63 =
V_4 -> V_217 ;
}
V_3 -> V_223 ++ ;
V_221 ++ ;
}
if ( V_4 -> V_154 ) {
snprintf ( V_4 -> V_244 , sizeof( V_4 -> V_244 ) ,
L_14 , V_3 -> V_226 ) ;
V_221 -> V_41 = V_4 -> V_244 ;
V_221 -> V_229 [ V_230 ] = V_245 ;
V_221 -> V_229 [ V_230 ] . V_63 =
V_4 -> V_154 ;
V_3 -> V_223 ++ ;
V_221 ++ ;
}
return 0 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_25 ( V_3 ) ;
F_7 ( V_4 ) ;
F_26 ( V_4 -> V_246 ) ;
F_26 ( V_4 -> V_247 ) ;
F_123 ( & V_4 -> V_10 ) ;
F_26 ( V_4 ) ;
}
static void F_124 ( struct V_2 * V_3 , int V_248 ,
T_3 * V_249 , bool V_178 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_248 ; V_54 ++ ) {
unsigned int V_128 = F_54 ( V_3 , V_249 [ V_54 ] , 0 ,
V_186 , 0 ) ;
if ( V_128 & V_185 )
continue;
if ( V_178 )
V_128 &= ~ V_184 ;
else
V_128 |= V_184 ;
F_40 ( V_3 , V_249 [ V_54 ] , V_128 ) ;
}
}
static void F_125 ( struct V_2 * V_3 , int V_137 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_28 . V_106 )
return;
if ( ! V_137 )
V_137 = F_57 ( V_3 ,
V_4 -> V_28 . V_250 [ 0 ] ) ;
F_124 ( V_3 , V_4 -> V_28 . V_106 ,
V_4 -> V_28 . V_251 ,
V_137 ) ;
}
static void F_71 ( struct V_2 * V_3 )
{
int V_137 = 0 ;
int V_252 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_101 && V_4 -> V_28 . V_29 [ 0 ] &&
( V_4 -> V_7 != V_16 || V_4 -> V_32 ) &&
F_126 ( V_3 , V_4 -> V_28 . V_29 [ 0 ] ) )
V_137 = F_57 ( V_3 , V_4 -> V_28 . V_29 [ 0 ] ) ;
if ( V_4 -> V_119 )
V_252 = V_4 -> V_28 . V_93 + V_4 -> V_94 ;
else
V_252 = V_4 -> V_28 . V_93 ;
F_124 ( V_3 , V_252 , V_4 -> V_28 . V_250 , V_137 ) ;
F_125 ( V_3 , V_137 ) ;
}
static int F_127 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_7 ( V_4 ) ;
if ( V_4 -> V_7 == V_27 ) {
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_28 . V_253 ; V_54 ++ )
F_40 ( V_3 , V_4 -> V_28 . V_29 [ V_54 ] , 0 ) ;
}
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , T_3 V_63 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_129 ( V_3 , & V_4 -> V_254 , V_63 ) ;
}
static bool F_130 ( struct V_2 * V_3 , T_3 V_163 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_151 . V_152 ; V_54 ++ ) {
if ( V_4 -> V_151 . V_158 [ V_54 ] == V_163 )
return false ;
}
if ( V_4 -> V_154 == V_163 )
return false ;
return true ;
}
static bool F_131 ( struct V_2 * V_3 , T_3 V_63 ,
T_3 V_255 , int V_256 ,
struct V_69 * V_70 , int V_75 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_111 [ 8 ] ;
int V_54 , V_252 ;
if ( V_63 == V_4 -> V_80 ) {
if ( ! V_256 )
return false ;
V_256 = 2 ;
}
V_252 = F_50 ( V_3 , V_63 , V_111 , F_51 ( V_111 ) ) ;
for ( V_54 = 0 ; V_54 < V_252 ; V_54 ++ ) {
if ( F_52 ( F_31 ( V_3 , V_111 [ V_54 ] ) ) != V_257 )
continue;
if ( V_111 [ V_54 ] == V_255 || F_130 ( V_3 , V_111 [ V_54 ] ) ) {
if ( ! ( V_4 -> V_80 && V_256 == 1 ) )
goto V_258;
}
}
if ( V_75 >= V_259 )
return false ;
for ( V_54 = 0 ; V_54 < V_252 ; V_54 ++ ) {
unsigned int type ;
type = F_52 ( F_31 ( V_3 , V_111 [ V_54 ] ) ) ;
if ( type == V_257 )
continue;
if ( F_131 ( V_3 , V_111 [ V_54 ] , V_255 ,
V_256 , V_70 , V_75 + 1 ) )
goto V_258;
}
return false ;
V_258:
V_70 -> V_70 [ V_70 -> V_75 ] = V_111 [ V_54 ] ;
V_70 -> V_44 [ V_70 -> V_75 ] = V_54 ;
if ( V_252 > 1 && F_52 ( F_31 ( V_3 , V_63 ) ) != V_260 )
V_70 -> V_78 [ V_70 -> V_75 ] = 1 ;
V_70 -> V_75 ++ ;
return true ;
}
static bool F_132 ( struct V_2 * V_3 , T_3 V_63 ,
T_3 V_255 , int V_256 ,
struct V_69 * V_70 )
{
if ( F_131 ( V_3 , V_63 , V_255 , V_256 , V_70 , 1 ) ) {
V_70 -> V_70 [ V_70 -> V_75 ] = V_63 ;
V_70 -> V_75 ++ ;
F_133 ( L_15 ,
V_70 -> V_75 , V_70 -> V_70 [ 0 ] , V_70 -> V_70 [ 1 ] ,
V_70 -> V_70 [ 2 ] , V_70 -> V_70 [ 3 ] , V_70 -> V_70 [ 4 ] ) ;
return true ;
}
return false ;
}
static int F_134 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_28 ;
int V_54 ;
T_3 V_63 ;
V_4 -> V_151 . V_152 = 0 ;
V_4 -> V_151 . V_158 = V_4 -> V_261 ;
for ( V_54 = 0 ; V_54 < V_110 -> V_93 ; V_54 ++ ) {
T_3 V_163 = 0 ;
V_63 = V_110 -> V_250 [ V_54 ] ;
if ( ! V_63 )
continue;
if ( F_132 ( V_3 , V_63 , 0 , 0 , & V_4 -> V_95 [ V_54 ] ) )
V_163 = V_4 -> V_95 [ V_54 ] . V_70 [ 0 ] ;
if ( ! V_54 && F_132 ( V_3 , V_63 , V_163 , 1 ,
& V_4 -> V_97 ) )
V_163 = V_4 -> V_97 . V_70 [ 0 ] ;
if ( V_163 )
V_4 -> V_261 [ V_4 -> V_151 . V_152 ++ ] = V_163 ;
}
if ( ! V_4 -> V_95 [ 0 ] . V_75 && V_4 -> V_97 . V_75 ) {
V_4 -> V_95 [ 0 ] = V_4 -> V_97 ;
V_4 -> V_97 . V_75 = 0 ;
}
return 0 ;
}
static int F_135 ( struct V_2 * V_3 , const char * V_262 ,
int V_263 , bool V_264 , struct V_69 * V_70 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_41 [ 32 ] ;
T_3 V_163 , V_86 , V_265 , V_63 ;
int V_59 ;
V_163 = V_264 ? V_70 -> V_70 [ 0 ] : 0 ;
V_86 = V_70 -> V_70 [ V_70 -> V_75 - 1 ] ;
V_265 = V_70 -> V_75 > 1 ? V_70 -> V_70 [ 1 ] : 0 ;
if ( V_163 && F_30 ( V_3 , V_163 , V_83 , V_266 ) )
V_63 = V_163 ;
else if ( F_30 ( V_3 , V_86 , V_83 , V_266 ) )
V_63 = V_86 ;
else if ( F_30 ( V_3 , V_265 , V_83 , V_266 ) )
V_63 = V_265 ;
else
V_63 = 0 ;
if ( V_63 ) {
sprintf ( V_41 , L_1 , V_262 ) ;
V_59 = F_136 ( V_4 , V_60 , V_41 ,
F_29 ( V_63 , V_263 , 0 , V_83 ) ) ;
if ( V_59 < 0 )
return V_59 ;
V_70 -> V_81 = V_63 ;
}
if ( V_163 && F_30 ( V_3 , V_163 , V_83 , V_90 ) )
V_63 = V_163 ;
else if ( F_30 ( V_3 , V_86 , V_83 , V_90 ) )
V_63 = V_86 ;
else if ( F_30 ( V_3 , V_265 , V_83 , V_90 ) )
V_63 = V_265 ;
else
V_63 = 0 ;
if ( V_63 ) {
sprintf ( V_41 , L_2 , V_262 ) ;
V_59 = F_136 ( V_4 , V_267 , V_41 ,
F_29 ( V_63 , V_263 , 0 , V_83 ) ) ;
if ( V_59 < 0 )
return V_59 ;
V_70 -> V_82 = V_63 ;
}
return 0 ;
}
static void F_137 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_28 ;
struct V_268 * V_269 = V_110 -> V_118 ;
int V_54 , V_270 , V_252 , V_271 ;
int V_249 [ V_272 ] ;
for ( V_271 = V_273 ; V_271 >= V_274 ; V_271 -- ) {
V_252 = 0 ;
for ( V_54 = 0 ; V_54 < V_110 -> V_117 ; V_54 ++ ) {
unsigned int V_275 ;
if ( V_269 [ V_54 ] . type > V_276 )
continue;
V_275 = F_56 ( V_3 , V_269 [ V_54 ] . V_86 ) ;
if ( F_138 ( V_275 ) != V_271 )
continue;
for ( V_270 = 0 ; V_270 < V_252 ; V_270 ++ )
if ( V_269 [ V_249 [ V_270 ] ] . type < V_269 [ V_54 ] . type ) {
memmove ( V_249 + V_270 + 1 , V_249 + V_270 ,
( V_252 - V_270 ) * sizeof( int ) ) ;
break;
}
V_249 [ V_270 ] = V_54 ;
V_252 ++ ;
}
if ( V_110 -> V_93 + V_252 < 3 )
continue;
for ( V_54 = 0 ; V_54 < V_252 ; V_54 ++ ) {
T_3 V_86 = V_269 [ V_249 [ V_54 ] ] . V_86 ;
V_4 -> V_182 [ V_4 -> V_94 ++ ] = V_86 ;
V_110 -> V_250 [ V_110 -> V_93 ++ ] = V_86 ;
if ( V_110 -> V_93 == 3 )
break;
}
return;
}
}
static void F_139 ( struct V_69 * V_77 , struct V_69 * V_76 )
{
V_77 -> V_81 = V_76 -> V_81 ;
V_77 -> V_82 = V_76 -> V_82 ;
}
static int F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_28 ;
struct V_69 * V_70 ;
static const char * const V_277 [ 4 ] = {
L_16 , L_17 , L_18 , L_19
} ;
int V_54 , V_44 , V_59 ;
int V_278 ;
V_278 = V_110 -> V_93 ;
if ( V_110 -> V_93 == 1 )
F_137 ( V_3 ) ;
V_59 = F_134 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_4 -> V_151 . V_152 < 3 ) {
V_4 -> V_94 = 0 ;
V_110 -> V_93 = V_278 ;
}
for ( V_54 = 0 ; V_54 < V_110 -> V_93 ; V_54 ++ ) {
T_3 V_86 , V_163 ;
V_86 = V_110 -> V_250 [ V_54 ] ;
V_163 = V_4 -> V_151 . V_158 [ V_54 ] ;
if ( ! V_86 || ! V_163 )
continue;
V_70 = V_4 -> V_95 + V_54 ;
if ( V_54 == V_279 ) {
V_59 = F_135 ( V_3 , L_20 , 1 , true , V_70 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_135 ( V_3 , L_21 , 2 , true , V_70 ) ;
if ( V_59 < 0 )
return V_59 ;
} else {
const char * V_262 = V_277 [ V_54 ] ;
if ( V_110 -> V_280 == V_281 &&
V_110 -> V_93 == 1 )
V_262 = L_22 ;
V_59 = F_135 ( V_3 , V_262 , 3 , true , V_70 ) ;
if ( V_59 < 0 )
return V_59 ;
}
if ( V_70 != V_4 -> V_95 + V_54 )
F_139 ( & V_4 -> V_95 [ V_54 ] , V_70 ) ;
if ( V_70 == V_4 -> V_95 && V_4 -> V_97 . V_75 )
F_139 ( & V_4 -> V_97 , V_70 ) ;
}
V_44 = F_141 ( V_3 , V_4 -> V_80 ,
V_4 -> V_151 . V_158 [ 0 ] ) ;
if ( V_44 >= 0 ) {
const char * V_41 ;
V_41 = V_4 -> V_97 . V_75 ?
L_23 : L_24 ;
V_59 = F_136 ( V_4 , V_60 , V_41 ,
F_29 ( V_4 -> V_80 , 3 ,
V_44 , V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
V_41 = V_4 -> V_97 . V_75 ?
L_25 : L_26 ;
V_59 = F_136 ( V_4 , V_267 , V_41 ,
F_29 ( V_4 -> V_80 , 3 ,
V_44 , V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
}
V_110 -> V_93 = V_278 ;
return 0 ;
}
static int F_142 ( struct V_2 * V_3 , T_3 V_86 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_69 * V_70 ;
bool V_264 ;
int V_54 , V_59 ;
if ( ! V_86 )
return 0 ;
if ( ! F_132 ( V_3 , V_86 , 0 , 0 , & V_4 -> V_104 ) ) {
for ( V_54 = V_282 ; V_54 >= V_279 ; V_54 -- ) {
if ( V_54 < V_4 -> V_151 . V_152 &&
F_132 ( V_3 , V_86 ,
V_4 -> V_151 . V_158 [ V_54 ] , 0 ,
& V_4 -> V_104 ) ) {
V_4 -> V_100 = V_54 ;
break;
}
}
}
if ( V_4 -> V_104 . V_75 ) {
V_4 -> V_154 = V_4 -> V_104 . V_70 [ 0 ] ;
if ( ! V_4 -> V_100 )
V_4 -> V_102 = V_4 -> V_104 ;
}
if ( ! V_4 -> V_102 . V_75 )
F_132 ( V_3 , V_86 ,
V_4 -> V_151 . V_158 [ V_283 ] , 0 ,
& V_4 -> V_102 ) ;
if ( ! F_132 ( V_3 , V_86 , V_4 -> V_151 . V_158 [ V_283 ] ,
1 , & V_4 -> V_103 ) && ! V_4 -> V_102 . V_75 )
return 0 ;
if ( V_4 -> V_102 . V_75 ) {
V_70 = & V_4 -> V_102 ;
V_264 = true ;
} else {
V_70 = & V_4 -> V_103 ;
V_264 = false ;
}
V_59 = F_135 ( V_3 , L_27 , 3 , V_264 , V_70 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_264 )
F_139 ( & V_4 -> V_103 , V_70 ) ;
else
F_139 ( & V_4 -> V_102 , V_70 ) ;
if ( V_4 -> V_104 . V_75 )
F_139 ( & V_4 -> V_104 , V_70 ) ;
return 0 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_69 * V_70 ;
bool V_264 ;
T_3 V_86 , V_163 = 0 ;
int V_59 ;
V_86 = V_4 -> V_28 . V_251 [ 0 ] ;
if ( ! V_4 -> V_28 . V_106 || ! V_86 )
return 0 ;
if ( F_132 ( V_3 , V_86 , 0 , 0 , & V_4 -> V_107 ) )
V_163 = V_4 -> V_107 . V_70 [ 0 ] ;
if ( ! V_163 )
F_132 ( V_3 , V_86 ,
V_4 -> V_151 . V_158 [ V_283 ] , 0 ,
& V_4 -> V_107 ) ;
if ( ! F_132 ( V_3 , V_86 , V_4 -> V_151 . V_158 [ V_283 ] ,
1 , & V_4 -> V_108 ) && ! V_163 )
return 0 ;
if ( ! V_4 -> V_97 . V_75 && V_4 -> V_108 . V_75 )
V_163 = 0 ;
V_4 -> V_284 = V_163 ;
V_4 -> V_151 . V_285 [ 0 ] = V_163 ;
if ( V_163 ) {
V_70 = & V_4 -> V_107 ;
V_264 = true ;
} else {
V_70 = & V_4 -> V_108 ;
V_264 = false ;
}
V_59 = F_135 ( V_3 , L_22 , 3 , V_264 , V_70 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_264 )
F_139 ( & V_4 -> V_108 , V_70 ) ;
else
F_139 ( & V_4 -> V_107 , V_70 ) ;
return 0 ;
}
static int F_144 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_37 -> V_147 . V_148 . V_150 [ 0 ] = V_4 -> V_96 ;
return 0 ;
}
static void F_145 ( struct V_2 * V_3 , int V_286 ,
struct V_69 * V_287 , struct V_69 * V_288 )
{
if ( V_286 ) {
F_37 ( V_3 , V_287 , false , false ) ;
F_37 ( V_3 , V_288 , true , false ) ;
} else {
F_37 ( V_3 , V_288 , false , false ) ;
F_37 ( V_3 , V_287 , true , false ) ;
}
}
static int F_146 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_45 = V_37 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_45 == V_4 -> V_96 )
return 0 ;
V_4 -> V_96 = V_45 ;
F_145 ( V_3 , V_45 , & V_4 -> V_95 [ 0 ] , & V_4 -> V_97 ) ;
if ( ! V_4 -> V_101 ) {
F_145 ( V_3 , V_45 , & V_4 -> V_102 ,
& V_4 -> V_103 ) ;
}
F_145 ( V_3 , V_45 , & V_4 -> V_107 ,
& V_4 -> V_108 ) ;
return 1 ;
}
static int F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_80 )
return 0 ;
if ( ! ( V_4 -> V_97 . V_75 || V_4 -> V_103 . V_75 ||
V_4 -> V_107 . V_75 ) )
return 0 ;
if ( ! F_73 ( V_4 , & V_289 ) )
return - V_47 ;
return 0 ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_63 = V_3 -> V_290 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_3 -> V_291 ; V_54 ++ , V_63 ++ ) {
unsigned int V_292 = F_31 ( V_3 , V_63 ) ;
if ( F_52 ( V_292 ) != V_293 )
continue;
if ( V_292 & V_294 )
continue;
if ( ! ( V_292 & V_295 ) )
continue;
if ( V_4 -> V_115 >= F_51 ( V_4 -> V_116 ) )
return - V_47 ;
V_4 -> V_116 [ V_4 -> V_115 ++ ] = V_63 ;
}
return 0 ;
}
static int F_149 ( struct V_34 * V_35 ,
struct V_142 * V_143 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_143 -> type = V_145 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . V_148 . V_149 = V_4 -> V_117 ;
if ( V_143 -> V_147 . V_148 . V_150 >= V_4 -> V_117 )
V_143 -> V_147 . V_148 . V_150 = V_4 -> V_117 - 1 ;
strcpy ( V_143 -> V_147 . V_148 . V_41 ,
V_4 -> V_118 [ V_143 -> V_147 . V_148 . V_150 ] . V_296 ) ;
return 0 ;
}
static int F_150 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = F_151 ( V_35 , & V_37 -> V_171 ) ;
V_37 -> V_147 . V_148 . V_150 [ 0 ] = V_4 -> V_123 [ V_44 ] ;
return 0 ;
}
static int F_152 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_44 = F_151 ( V_35 , & V_37 -> V_171 ) ;
T_3 V_297 ;
int V_167 ;
V_167 = V_37 -> V_147 . V_148 . V_150 [ 0 ] ;
if ( V_167 < 0 || V_167 >= V_4 -> V_117 )
return - V_203 ;
if ( V_4 -> V_123 [ V_44 ] == V_167 )
return 0 ;
V_4 -> V_123 [ V_44 ] = V_167 ;
if ( V_4 -> V_126 ) {
int V_122 = V_4 -> V_118 [ V_167 ] . V_122 ;
V_297 = V_4 -> V_124 [ V_122 ] ;
F_111 ( V_3 , V_167 ) ;
} else {
V_297 = V_4 -> V_124 [ V_44 ] ;
if ( F_90 ( ! V_297 ) )
return - V_203 ;
}
if ( V_297 ) {
F_53 ( V_3 , V_297 , V_140 ) ;
F_8 ( V_3 , V_297 , 0 ,
V_79 ,
V_4 -> V_118 [ V_167 ] . V_125 ) ;
}
F_14 ( V_3 ) ;
return 0 ;
}
static int F_153 ( struct V_2 * V_3 , int V_146 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_39 * V_42 ;
if ( V_4 -> V_117 <= 1 || ! V_146 )
return 0 ;
V_42 = F_73 ( V_4 , & V_298 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_146 = V_146 ;
return 0 ;
}
static void F_154 ( struct V_1 * V_4 , T_3 V_288 , int V_44 )
{
struct V_188 * V_52 ;
if ( V_4 -> V_191 >= F_51 ( V_4 -> V_192 ) - 1 )
return;
V_52 = V_4 -> V_192 + V_4 -> V_191 ;
V_52 -> V_63 = V_288 ;
V_52 -> V_64 = V_61 ;
V_52 -> V_44 = V_44 ;
V_4 -> V_191 ++ ;
V_4 -> V_254 . V_299 = V_4 -> V_192 ;
}
static bool F_155 ( struct V_2 * V_3 , T_3 V_76 ,
T_3 V_77 )
{
return F_156 ( V_3 , V_76 , V_77 , 1 ) >= 0 ;
}
static bool F_157 ( struct V_2 * V_3 , T_3 V_86 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_300 , V_44 ;
V_4 -> V_118 [ V_4 -> V_117 ] . V_122 = - 1 ;
V_4 -> V_118 [ V_4 -> V_117 ] . V_86 = V_86 ;
for ( V_300 = 0 ; V_300 < V_4 -> V_115 ; V_300 ++ ) {
if ( V_4 -> V_124 [ V_300 ] ) {
V_44 = F_141 ( V_3 , V_4 -> V_124 [ V_300 ] ,
V_86 ) ;
if ( V_44 < 0 )
continue;
V_4 -> V_118 [ V_4 -> V_117 ] . V_125 = V_44 ;
} else {
if ( ! F_155 ( V_3 , V_4 -> V_116 [ V_300 ] , V_86 ) )
continue;
}
V_4 -> V_118 [ V_4 -> V_117 ] . V_122 = V_300 ;
if ( ! V_4 -> V_126 &&
V_4 -> V_117 > 0 && V_4 -> V_118 [ 0 ] . V_122 != V_300 ) {
F_158 ( V_301
L_28 ) ;
V_4 -> V_126 = 1 ;
}
return true ;
}
return false ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_28 ;
int V_54 , V_59 ;
V_59 = F_148 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_160 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
for ( V_54 = 0 ; V_54 < V_110 -> V_117 ; V_54 ++ ) {
if ( F_157 ( V_3 , V_110 -> V_118 [ V_54 ] . V_86 ) )
V_4 -> V_118 [ V_4 -> V_117 ++ ] . V_296 =
F_161 ( V_3 , V_110 , V_54 ) ;
}
if ( V_4 -> V_80 &&
F_157 ( V_3 , V_4 -> V_80 ) )
V_4 -> V_118 [ V_4 -> V_117 ++ ] . V_296 = L_29 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_28 ;
const char * V_302 = NULL ;
int V_57 = 0 ;
int V_54 , V_270 , V_59 , V_44 ;
if ( ! V_4 -> V_80 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_110 -> V_117 ; V_54 ++ ) {
T_3 V_86 = V_110 -> V_118 [ V_54 ] . V_86 ;
const char * V_296 = F_161 ( V_3 , V_110 , V_54 ) ;
if ( V_302 && ! strcmp ( V_296 , V_302 ) )
V_57 ++ ;
else
V_57 = 0 ;
V_302 = V_296 ;
V_44 = F_141 ( V_3 , V_4 -> V_80 , V_86 ) ;
if ( V_44 >= 0 ) {
V_59 = F_28 ( V_4 , V_296 , V_57 ,
V_44 , V_4 -> V_80 ) ;
if ( V_59 < 0 )
return V_59 ;
F_154 ( V_4 , V_4 -> V_80 , V_44 ) ;
}
for ( V_270 = 0 ; V_270 < V_4 -> V_94 ; V_270 ++ ) {
if ( V_4 -> V_182 [ V_270 ] == V_86 ) {
V_4 -> V_181 [ V_270 ] = V_44 ;
V_4 -> V_174 [ V_270 ] = V_296 ;
break;
}
}
}
return 0 ;
}
static int F_163 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_109 * V_110 = & V_4 -> V_28 ;
const char * V_302 = NULL ;
int V_57 = 0 ;
int V_54 , V_59 ;
for ( V_54 = 0 ; V_54 < V_110 -> V_117 ; V_54 ++ ) {
T_3 V_86 = V_110 -> V_118 [ V_54 ] . V_86 ;
unsigned int V_66 ;
const char * V_296 ;
char V_41 [ 32 ] ;
if ( V_110 -> V_118 [ V_54 ] . type != V_121 )
continue;
V_66 = F_32 ( V_3 , V_86 , V_61 ) ;
if ( V_66 == - 1 || ! ( V_66 & V_266 ) )
continue;
V_296 = F_161 ( V_3 , V_110 , V_54 ) ;
if ( V_302 && ! strcmp ( V_296 , V_302 ) )
V_57 ++ ;
else
V_57 = 0 ;
V_302 = V_296 ;
snprintf ( V_41 , sizeof( V_41 ) , L_30 , V_296 ) ;
V_59 = F_23 ( V_4 , V_60 , V_41 , V_57 ,
F_29 ( V_86 , 3 , 0 , V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static int F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 , V_59 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_115 ; V_54 ++ ) {
T_3 V_210 = V_4 -> V_116 [ V_54 ] ;
V_59 = F_23 ( V_4 , V_60 ,
L_31 , V_54 ,
F_29 ( V_210 , 3 , 0 ,
V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_23 ( V_4 , V_267 ,
L_32 , V_54 ,
F_29 ( V_210 , 3 , 0 ,
V_61 ) ) ;
if ( V_59 < 0 )
return V_59 ;
}
for ( V_54 = 0 ; V_54 < V_4 -> V_115 ; V_54 ++ )
if ( ! V_4 -> V_124 [ V_54 ] )
break;
V_59 = F_153 ( V_3 , V_54 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static int F_165 ( struct V_1 * V_4 , struct V_303 * * V_304 ,
struct V_305 * V_306 )
{
struct V_303 * V_113 ;
int V_54 ;
V_113 = F_2 ( sizeof( * V_113 ) + sizeof( long ) * 4 , V_5 ) ;
if ( ! V_113 )
return - V_47 ;
V_113 -> V_306 = V_306 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_115 ; V_54 ++ )
V_113 -> V_307 [ V_54 ] =
F_29 ( V_4 -> V_116 [ V_54 ] , 3 , 0 , V_61 ) ;
* V_304 = V_113 ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_39 * V_42 ;
int V_59 ;
V_59 = F_165 ( V_4 , & V_4 -> V_246 , & V_308 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_165 ( V_4 , & V_4 -> V_247 , & V_309 ) ;
if ( V_59 < 0 )
return V_59 ;
V_42 = F_73 ( V_4 , & V_310 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_51 = ( long ) V_4 -> V_246 ;
V_42 = F_73 ( V_4 , & V_311 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_51 = ( long ) V_4 -> V_247 ;
V_59 = F_153 ( V_3 , 1 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static int F_167 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_59 ;
V_59 = F_159 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_4 -> V_126 )
V_59 = F_166 ( V_3 ) ;
else
V_59 = F_164 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_162 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_163 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static void F_168 ( struct V_2 * V_3 , T_3 V_63 )
{
unsigned int V_132 ;
unsigned char V_312 ;
V_132 = F_56 ( V_3 , V_63 ) ;
V_312 = ( unsigned char ) F_169 ( V_132 ) ;
V_312 = ( V_312 << 4 ) | F_170 ( V_132 ) ;
if ( F_58 ( V_132 ) == V_139
&& ( V_312 == 0xf0 || V_312 == 0xff ) ) {
V_132 = V_132 & ( ~ ( V_313 << 30 ) ) ;
F_171 ( V_3 , V_63 , V_132 ) ;
}
return;
}
static int F_172 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_16 )
return 0 ;
V_37 -> V_147 . integer . V_147 [ 0 ] = V_4 -> V_32 ;
return 0 ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_45 ;
if ( V_4 -> V_7 != V_16 )
return 0 ;
V_45 = ! ! V_37 -> V_147 . integer . V_147 [ 0 ] ;
if ( V_4 -> V_32 == V_45 )
return 0 ;
V_4 -> V_32 = V_45 ;
if ( V_4 -> V_32 &&
F_174 ( V_3 , L_33 ) != 1 ) {
F_77 ( V_3 , 1 ) ;
F_74 ( V_3 ) ;
}
F_71 ( V_3 ) ;
F_10 ( V_4 ) ;
return 1 ;
}
static int F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_59 ;
V_59 = F_176 ( V_3 , & V_4 -> V_28 , NULL ) ;
if ( V_59 < 0 )
return V_59 ;
if ( ! V_4 -> V_28 . V_93 && ! V_4 -> V_28 . V_29 [ 0 ] )
return - V_203 ;
V_59 = F_140 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_142 ( V_3 , V_4 -> V_28 . V_29 [ 0 ] ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_143 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_147 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_167 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_4 -> V_151 . V_202 = V_4 -> V_151 . V_152 * 2 ;
F_177 ( V_3 ) ;
F_178 ( V_3 ) ;
if ( V_4 -> V_43 . V_52 )
V_4 -> V_214 [ V_4 -> V_213 ++ ] = V_4 -> V_43 . V_52 ;
if ( V_4 -> V_154 && V_4 -> V_103 . V_75 ) {
V_59 = F_72 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
}
V_59 = F_81 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_4 -> V_314 [ 0 ] )
V_3 -> V_314 = V_4 -> V_314 ;
return 1 ;
}
static void F_179 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_151 . V_215 )
F_39 ( V_3 , V_4 -> V_28 . V_315 [ 0 ] , V_98 ) ;
if ( V_4 -> V_314 [ 0 ] )
F_39 ( V_3 , V_4 -> V_28 . V_315 [ 1 ] , V_98 ) ;
}
static void F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_217 )
return;
F_40 ( V_3 , V_4 -> V_28 . V_316 , V_120 ) ;
}
static void F_181 ( struct V_2 * V_3 , struct V_317 * V_318 )
{
F_14 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static void F_182 ( struct V_2 * V_3 , struct V_317 * V_318 )
{
F_14 ( V_3 ) ;
}
static void F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_28 ;
unsigned int V_319 ;
int V_54 ;
T_4 V_320 ;
if ( V_110 -> V_29 [ 0 ] && F_126 ( V_3 , V_110 -> V_29 [ 0 ] ) )
F_184 ( V_3 , V_110 -> V_29 [ 0 ] ,
V_321 | V_322 ,
F_181 ) ;
if ( V_110 -> V_251 [ 0 ] )
V_319 = V_323 ;
else
V_319 = 0 ;
V_320 = V_319 ? F_181 : F_182 ;
for ( V_54 = 0 ; V_54 < V_110 -> V_93 ; V_54 ++ ) {
if ( V_110 -> V_250 [ V_54 ] &&
F_126 ( V_3 , V_110 -> V_250 [ V_54 ] ) )
F_184 ( V_3 , V_110 -> V_250 [ V_54 ] ,
V_319 | V_322 , V_320 ) ;
}
for ( V_54 = 0 ; V_54 < V_110 -> V_117 ; V_54 ++ ) {
if ( F_126 ( V_3 , V_110 -> V_118 [ V_54 ] . V_86 ) )
F_184 ( V_3 , V_110 -> V_118 [ V_54 ] . V_86 ,
V_322 ,
F_182 ) ;
}
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_324 ; V_54 ++ )
F_186 ( V_3 , V_4 -> V_325 [ V_54 ] ) ;
F_14 ( V_3 ) ;
F_84 ( V_3 , true ) ;
F_43 ( V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 ) ;
F_179 ( V_3 ) ;
F_180 ( V_3 ) ;
F_183 ( V_3 ) ;
F_71 ( V_3 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static void F_187 ( struct V_326 * V_327 )
{
struct V_1 * V_4 = F_188 ( V_327 , struct V_1 ,
V_31 . V_327 ) ;
if ( V_4 -> V_7 != V_16 )
return;
F_189 ( V_4 -> V_3 ) ;
if ( V_4 -> V_328
!= F_57 ( V_4 -> V_3 , V_4 -> V_28 . V_29 [ 0 ] ) ) {
V_4 -> V_328 ^= 1 ;
F_71 ( V_4 -> V_3 ) ;
}
if ( V_4 -> V_32 )
F_12 ( & V_4 -> V_31 ,
F_13 ( 100 ) ) ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_63 , V_111 [ 8 ] ;
unsigned int type ;
int V_54 , V_329 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_115 ; V_54 ++ ) {
V_63 = V_4 -> V_116 [ V_54 ] ;
while ( V_63 ) {
type = F_52 ( F_31 ( V_3 , V_63 ) ) ;
if ( type == V_127 )
break;
V_329 = F_50 ( V_3 , V_63 , V_111 ,
F_51 ( V_111 ) ) ;
if ( V_329 <= 0 )
break;
if ( V_329 > 1 ) {
V_4 -> V_124 [ V_54 ] = V_63 ;
break;
}
V_63 = V_111 [ 0 ] ;
}
}
return 0 ;
}
static int F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x17 ;
F_168 ( V_3 , V_330 ) ;
F_168 ( V_3 , V_331 ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
if ( ! F_73 ( V_4 , & V_332 ) )
return - V_47 ;
if ( V_3 -> V_12 == 0x11061708 )
V_4 -> V_227 = & V_333 ;
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_334 ;
V_3 -> V_335 = V_336 ;
F_191 ( & V_4 -> V_31 , F_187 ) ;
return 0 ;
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x18 ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_3 -> V_335 = V_336 ;
return 0 ;
}
static void F_193 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_337 ;
unsigned int V_128 ;
int V_338 = 0 ;
if ( ( V_4 -> V_7 != V_21 ) &&
( V_3 -> V_12 != 0x11064397 ) )
V_338 = 1 ;
V_337 =
( F_54 ( V_3 , 0x17 , 0 , V_339 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x1a , & V_128 ) ;
F_55 ( V_3 , 0x1b , & V_128 ) ;
F_55 ( V_3 , 0x1e , & V_128 ) ;
if ( V_337 )
V_128 = V_140 ;
F_53 ( V_3 , 0x17 , V_128 ) ;
F_53 ( V_3 , 0x13 , V_128 ) ;
F_53 ( V_3 , 0x14 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x19 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x1b , & V_128 ) ;
F_53 ( V_3 , 0x18 , V_128 ) ;
F_53 ( V_3 , 0x11 , V_128 ) ;
if ( V_338 ) {
V_128 = V_141 ;
F_55 ( V_3 , 0x22 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x1a , & V_128 ) ;
F_53 ( V_3 , 0x26 , V_128 ) ;
F_53 ( V_3 , 0x24 , V_128 ) ;
} else if ( V_3 -> V_12 == 0x11064397 ) {
V_128 = V_141 ;
F_55 ( V_3 , 0x23 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x1a , & V_128 ) ;
F_53 ( V_3 , 0x27 , V_128 ) ;
F_53 ( V_3 , 0x25 , V_128 ) ;
}
V_128 = V_141 ;
F_55 ( V_3 , 0x1c , & V_128 ) ;
F_55 ( V_3 , 0x1d , & V_128 ) ;
if ( V_338 )
F_55 ( V_3 , 0x23 , & V_128 ) ;
F_53 ( V_3 , 0x16 , V_337 ? V_140 : V_128 ) ;
F_53 ( V_3 , 0x10 , V_128 ) ;
if ( V_338 ) {
F_53 ( V_3 , 0x25 , V_128 ) ;
F_53 ( V_3 , 0x27 , V_128 ) ;
} else if ( V_3 -> V_12 == 0x11064397 && V_4 -> V_101 )
F_53 ( V_3 , 0x25 , V_128 ) ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
if ( F_4 ( V_3 ) == V_8 )
return F_195 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x16 ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_3 -> V_335 = V_336 ;
V_4 -> F_14 = F_193 ;
return 0 ;
}
static void F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_28 . V_340 ; V_54 ++ ) {
T_3 V_63 ;
int V_111 ;
V_63 = V_4 -> V_28 . V_315 [ V_54 ] ;
if ( ! V_63 )
continue;
V_111 = F_50 ( V_3 , V_63 , & V_63 , 1 ) ;
if ( V_111 < 1 )
continue;
if ( ! V_4 -> V_151 . V_215 )
V_4 -> V_151 . V_215 = V_63 ;
else {
V_4 -> V_314 [ 0 ] = V_63 ;
break;
}
}
}
static void F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_341 ;
int V_54 , V_59 ;
if ( ! V_4 -> V_28 . V_316 )
return;
V_341 = V_3 -> V_290 ;
for ( V_54 = 0 ; V_54 < V_3 -> V_291 ; V_54 ++ , V_341 ++ ) {
unsigned int V_292 = F_31 ( V_3 , V_341 ) ;
if ( F_52 ( V_292 ) != V_293 )
continue;
if ( ! ( V_292 & V_294 ) )
continue;
if ( ! ( V_292 & V_295 ) )
continue;
V_59 = F_141 ( V_3 , V_341 ,
V_4 -> V_28 . V_316 ) ;
if ( V_59 >= 0 ) {
V_4 -> V_217 = V_341 ;
break;
}
}
}
static void F_196 ( struct V_2 * V_3 , T_3 V_86 ,
int V_342 , int V_343 , int V_344 )
{
F_197 ( V_3 , V_86 , V_61 ,
( V_342 << V_92 ) |
( V_343 << V_345 ) |
( V_344 << V_346 ) |
( 0 << V_347 ) ) ;
}
static int F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x16 ;
F_196 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_348 ;
V_3 -> V_335 = V_336 ;
if ( F_4 ( V_3 ) == V_8 ) {
F_26 ( V_3 -> V_226 ) ;
V_3 -> V_226 = F_22 ( L_34 , V_5 ) ;
snprintf ( V_3 -> V_175 -> V_176 -> V_349 ,
sizeof( V_3 -> V_175 -> V_176 -> V_349 ) ,
L_35 , V_3 -> V_350 , V_3 -> V_226 ) ;
}
if ( V_3 -> V_12 == 0x11064397 ) {
F_26 ( V_3 -> V_226 ) ;
V_3 -> V_226 = F_22 ( L_36 , V_5 ) ;
snprintf ( V_3 -> V_175 -> V_176 -> V_349 ,
sizeof( V_3 -> V_175 -> V_176 -> V_349 ) ,
L_35 , V_3 -> V_350 , V_3 -> V_226 ) ;
}
V_4 -> F_14 = F_193 ;
return 0 ;
}
static void F_198 ( struct V_2 * V_3 )
{
int V_337 =
F_54 ( V_3 , 0x13 , 0 , V_339 , 0x00 ) == 3 ;
unsigned int V_128 ;
V_128 = V_141 ;
F_55 ( V_3 , 0x14 , & V_128 ) ;
F_55 ( V_3 , 0x15 , & V_128 ) ;
F_55 ( V_3 , 0x18 , & V_128 ) ;
if ( V_337 )
V_128 = V_140 ;
F_53 ( V_3 , 0x13 , V_128 ) ;
F_53 ( V_3 , 0x12 , V_128 ) ;
F_53 ( V_3 , 0x1f , V_128 ) ;
F_53 ( V_3 , 0x20 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x17 , & V_128 ) ;
F_55 ( V_3 , 0x16 , & V_128 ) ;
F_53 ( V_3 , 0x1a , V_337 ? V_140 : V_128 ) ;
F_53 ( V_3 , 0x10 , V_128 ) ;
F_53 ( V_3 , 0x1d , V_128 ) ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x1a ;
F_197 ( V_3 , 0x1A , V_61 ,
( 0x17 << V_92 ) |
( 0x17 << V_345 ) |
( 0x5 << V_346 ) |
( 1 << V_347 ) ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_351 ;
V_3 -> V_335 = V_336 ;
V_4 -> F_14 = F_198 ;
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_337 ;
unsigned int V_128 , V_352 ;
V_337 =
F_54 ( V_3 , 0x1e , 0 , V_339 , 0x00 ) == 5 ;
V_128 = V_141 ;
F_55 ( V_3 , 0x29 , & V_128 ) ;
F_55 ( V_3 , 0x2a , & V_128 ) ;
F_55 ( V_3 , 0x2b , & V_128 ) ;
if ( V_337 )
V_128 = V_140 ;
F_53 ( V_3 , 0x1e , V_128 ) ;
F_53 ( V_3 , 0x1f , V_128 ) ;
F_53 ( V_3 , 0x10 , V_128 ) ;
F_53 ( V_3 , 0x11 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x27 , & V_128 ) ;
F_53 ( V_3 , 0x1a , V_128 ) ;
V_352 = V_128 ;
V_128 = V_141 ;
F_55 ( V_3 , 0x26 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x2b , & V_128 ) ;
F_53 ( V_3 , 0xa , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x24 , & V_128 ) ;
if ( ! V_4 -> V_101 )
F_55 ( V_3 , 0x28 , & V_128 ) ;
F_53 ( V_3 , 0x8 , V_128 ) ;
if ( ! V_4 -> V_101 && V_352 != V_141 )
V_128 = V_352 ;
F_53 ( V_3 , 0xb , V_128 ) ;
F_53 ( V_3 , 0x21 , V_337 ? V_140 : V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x25 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x2a , & V_128 ) ;
F_53 ( V_3 , 0x9 , V_128 ) ;
if ( V_4 -> V_101 ) {
V_128 = V_141 ;
F_55 ( V_3 , 0x28 , & V_128 ) ;
F_53 ( V_3 , 0x1b , V_128 ) ;
F_53 ( V_3 , 0x34 , V_128 ) ;
F_53 ( V_3 , 0xc , V_128 ) ;
}
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_54 , V_252 ;
T_3 V_111 [ 8 ] ;
T_3 V_63 ;
if ( ! V_4 -> V_80 )
return 0 ;
V_252 = F_50 ( V_3 , V_4 -> V_80 , V_111 ,
F_51 ( V_111 ) - 1 ) ;
for ( V_54 = 0 ; V_54 < V_252 ; V_54 ++ ) {
if ( F_52 ( F_31 ( V_3 , V_111 [ V_54 ] ) ) == V_257 )
return 0 ;
}
V_63 = V_3 -> V_290 ;
for ( V_54 = 0 ; V_54 < V_3 -> V_291 ; V_54 ++ , V_63 ++ ) {
unsigned int V_66 = F_31 ( V_3 , V_63 ) ;
if ( F_52 ( V_66 ) == V_257 &&
! ( V_66 & V_294 ) ) {
V_111 [ V_252 ++ ] = V_63 ;
return F_202 ( V_3 ,
V_4 -> V_80 ,
V_252 , V_111 ) ;
}
}
return 0 ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x21 ;
F_196 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_201 ( V_3 ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_353 ;
V_3 -> V_335 = V_336 ;
V_4 -> F_14 = F_200 ;
return 0 ;
}
static int F_204 ( struct V_34 * V_35 ,
struct V_142 * V_143 )
{
V_143 -> type = V_354 ;
V_143 -> V_146 = 1 ;
V_143 -> V_147 . integer . V_355 = 0 ;
V_143 -> V_147 . integer . V_356 = 1 ;
return 0 ;
}
static int F_205 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
int V_48 = 0 ;
V_48 = F_54 ( V_3 , 0x26 , 0 ,
V_339 , 0 ) ;
if ( V_48 != - 1 )
* V_37 -> V_147 . integer . V_147 = V_48 ;
return 0 ;
}
static int F_206 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = F_17 ( V_35 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_48 = * V_37 -> V_147 . integer . V_147 ;
F_8 ( V_3 , 0x26 , 0 ,
V_79 , V_48 ) ;
V_4 -> V_357 = V_48 ;
F_14 ( V_3 ) ;
return 1 ;
}
static void F_207 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_337 ;
unsigned int V_128 ;
unsigned int V_358 , V_137 ;
V_337 =
( F_54 ( V_3 , 0x17 , 0 ,
V_339 , 0x00 ) == 5 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x1a , & V_128 ) ;
F_55 ( V_3 , 0x1b , & V_128 ) ;
F_55 ( V_3 , 0x1e , & V_128 ) ;
if ( V_337 )
V_128 = V_140 ;
F_53 ( V_3 , 0x17 , V_128 ) ;
F_53 ( V_3 , 0x13 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x1e , & V_128 ) ;
if ( V_4 -> V_357 )
F_55 ( V_3 , 0x22 , & V_128 ) ;
else
F_53 ( V_3 , 0x22 , V_141 ) ;
F_53 ( V_3 , 0x26 , V_128 ) ;
F_53 ( V_3 , 0x14 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x19 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x1b , & V_128 ) ;
F_53 ( V_3 , 0x18 , V_128 ) ;
F_53 ( V_3 , 0x11 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x23 , & V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x1a , & V_128 ) ;
F_53 ( V_3 , 0x27 , V_128 ) ;
if ( V_4 -> V_119 )
F_55 ( V_3 , 0x1e , & V_128 ) ;
F_53 ( V_3 , 0x25 , V_128 ) ;
V_137 = F_57 ( V_3 , 0x1c ) ;
if ( V_137 )
V_358 = 0 ;
else {
V_137 = F_57 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_101 && V_137 )
V_358 = 0 ;
else
V_358 = 1 ;
}
V_128 = V_358 ? V_140 : V_141 ;
F_53 ( V_3 , 0x28 , V_128 ) ;
F_53 ( V_3 , 0x29 , V_128 ) ;
F_53 ( V_3 , 0x2a , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x1c , & V_128 ) ;
F_55 ( V_3 , 0x1d , & V_128 ) ;
if ( V_4 -> V_101 )
F_53 ( V_3 , 0x25 , V_128 ) ;
F_53 ( V_3 , 0x16 , V_337 ? V_140 : V_128 ) ;
F_53 ( V_3 , 0x10 , V_358 ? V_140 : V_128 ) ;
}
static int F_208 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x16 ;
F_196 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_359 ;
V_4 -> V_214 [ V_4 -> V_213 ] = V_360 ;
V_4 -> V_213 ++ ;
V_4 -> V_214 [ V_4 -> V_213 ++ ] = V_361 ;
V_3 -> V_335 = V_336 ;
V_4 -> F_14 = F_207 ;
return 0 ;
}
static void F_209 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_337 ;
unsigned int V_128 ;
unsigned int V_137 ;
V_337 =
F_54 ( V_3 , 0x1e , 0 , V_339 , 0x00 ) == 3 ;
V_128 = V_141 ;
F_55 ( V_3 , 0x29 , & V_128 ) ;
F_55 ( V_3 , 0x2a , & V_128 ) ;
F_55 ( V_3 , 0x2b , & V_128 ) ;
V_128 = V_140 ;
F_53 ( V_3 , 0x1e , V_128 ) ;
F_53 ( V_3 , 0x1f , V_128 ) ;
F_53 ( V_3 , 0x10 , V_128 ) ;
F_53 ( V_3 , 0x11 , V_128 ) ;
F_53 ( V_3 , 0x8 , V_128 ) ;
if ( V_4 -> V_7 == V_27 ) {
V_128 = V_141 ;
F_55 ( V_3 , 0x28 , & V_128 ) ;
F_53 ( V_3 , 0x18 , V_128 ) ;
F_53 ( V_3 , 0x38 , V_128 ) ;
} else {
V_128 = V_141 ;
F_55 ( V_3 , 0x26 , & V_128 ) ;
F_53 ( V_3 , 0x1c , V_128 ) ;
F_53 ( V_3 , 0x37 , V_128 ) ;
}
if ( V_4 -> V_7 == V_27 ) {
V_128 = V_141 ;
F_55 ( V_3 , 0x25 , & V_128 ) ;
F_53 ( V_3 , 0x15 , V_128 ) ;
F_53 ( V_3 , 0x35 , V_128 ) ;
} else {
V_128 = V_141 ;
F_55 ( V_3 , 0x25 , & V_128 ) ;
F_53 ( V_3 , 0x19 , V_128 ) ;
F_53 ( V_3 , 0x35 , V_128 ) ;
}
if ( V_4 -> V_101 )
F_53 ( V_3 , 0x9 , V_140 ) ;
V_137 = F_57 ( V_3 , 0x25 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x24 , & V_128 ) ;
V_128 = V_137 ? V_141 : V_140 ;
if ( V_4 -> V_7 == V_27 )
F_53 ( V_3 , 0x14 , V_128 ) ;
else
F_53 ( V_3 , 0x18 , V_128 ) ;
F_53 ( V_3 , 0x34 , V_128 ) ;
V_137 = F_57 ( V_3 , 0x26 ) ;
V_128 = V_137 ? V_141 : V_140 ;
if ( V_4 -> V_7 == V_27 ) {
F_53 ( V_3 , 0x33 , V_128 ) ;
F_53 ( V_3 , 0x1c , V_128 ) ;
F_53 ( V_3 , 0x3c , V_128 ) ;
} else {
F_53 ( V_3 , 0x31 , V_128 ) ;
F_53 ( V_3 , 0x17 , V_128 ) ;
F_53 ( V_3 , 0x3b , V_128 ) ;
}
if ( V_337 || ! F_82 ( V_3 ) )
F_53 ( V_3 , 0x21 , V_140 ) ;
else
F_53 ( V_3 , 0x21 , V_141 ) ;
}
static void F_210 ( struct V_2 * V_3 ,
const struct V_362 * V_363 , int V_364 )
{
if ( V_364 == V_365 )
F_196 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_211 ( struct V_2 * V_3 )
{
static T_3 V_366 [] = { 0x14 , 0x1c } ;
static T_3 V_367 [] = { 0x1c } ;
F_202 ( V_3 , 0x24 , F_51 ( V_366 ) , V_366 ) ;
F_202 ( V_3 , 0x33 , F_51 ( V_367 ) , V_367 ) ;
}
static int F_212 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x21 ;
F_196 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_27 )
F_211 ( V_3 ) ;
F_201 ( V_3 ) ;
F_213 ( V_3 , NULL , V_368 , V_369 ) ;
F_214 ( V_3 , V_365 ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
if ( V_4 -> V_7 == V_27 )
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_370 ;
else
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_371 ;
V_3 -> V_335 = V_336 ;
V_4 -> F_14 = F_209 ;
return 0 ;
}
static void F_215 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_128 ;
unsigned int V_137 ;
V_128 = V_141 ;
F_55 ( V_3 , 0x29 , & V_128 ) ;
F_55 ( V_3 , 0x2a , & V_128 ) ;
F_55 ( V_3 , 0x2b , & V_128 ) ;
V_128 = V_140 ;
F_53 ( V_3 , 0x1e , V_128 ) ;
F_53 ( V_3 , 0x1f , V_128 ) ;
F_53 ( V_3 , 0x10 , V_128 ) ;
F_53 ( V_3 , 0x11 , V_128 ) ;
F_53 ( V_3 , 0x8 , V_140 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x28 , & V_128 ) ;
F_53 ( V_3 , 0x18 , V_128 ) ;
F_53 ( V_3 , 0x38 , V_128 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x25 , & V_128 ) ;
F_53 ( V_3 , 0x15 , V_128 ) ;
F_53 ( V_3 , 0x35 , V_128 ) ;
if ( V_4 -> V_101 )
F_53 ( V_3 , 0x9 , V_140 ) ;
V_137 = F_57 ( V_3 , 0x25 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x24 , & V_128 ) ;
if ( V_137 ) {
F_53 ( V_3 , 0x14 , V_141 ) ;
F_53 ( V_3 , 0x34 , V_141 ) ;
} else {
F_53 ( V_3 , 0x14 , V_140 ) ;
F_53 ( V_3 , 0x34 , V_140 ) ;
}
V_137 = F_57 ( V_3 , 0x28 ) ;
V_128 = V_141 ;
F_55 ( V_3 , 0x31 , & V_128 ) ;
if ( V_137 ) {
F_53 ( V_3 , 0x1c , V_141 ) ;
F_53 ( V_3 , 0x3c , V_141 ) ;
F_53 ( V_3 , 0x3e , V_141 ) ;
} else {
F_53 ( V_3 , 0x1c , V_140 ) ;
F_53 ( V_3 , 0x3c , V_140 ) ;
F_53 ( V_3 , 0x3e , V_140 ) ;
}
V_128 = V_141 ;
F_55 ( V_3 , 0x33 , & V_128 ) ;
F_53 ( V_3 , 0x1d , V_128 ) ;
F_53 ( V_3 , 0x3d , V_128 ) ;
}
static int F_216 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_47 ;
V_4 -> V_80 = 0x21 ;
F_196 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_196 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_201 ( V_3 ) ;
V_59 = F_175 ( V_3 ) ;
if ( V_59 < 0 ) {
F_122 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_325 [ V_4 -> V_324 ++ ] = V_372 ;
V_3 -> V_335 = V_336 ;
V_4 -> F_14 = F_215 ;
return 0 ;
}
static int T_5 F_217 ( void )
{
return F_218 ( & V_373 ) ;
}
static void T_6 F_219 ( void )
{
F_220 ( & V_373 ) ;
}
