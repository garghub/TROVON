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
F_7 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 ,
! V_4 -> V_29 ) ;
if ( ! F_8 ( & V_4 -> V_30 ) )
F_9 ( & V_4 -> V_30 ,
F_10 ( 100 ) ) ;
}
static void F_11 ( struct V_1 * V_4 )
{
if ( V_4 -> V_7 != V_15 || V_4 -> V_27 . V_28 [ 0 ] == 0 )
return;
if ( F_12 ( V_4 -> V_3 , L_1 ) == 1
&& ! F_13 ( V_4 -> V_3 ) )
return;
F_7 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 ,
! V_4 -> V_29 ) ;
F_14 ( & V_4 -> V_30 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> F_15 )
V_4 -> F_15 ( V_3 ) ;
}
static int F_16 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 = F_17 ( V_32 , V_34 ) ;
struct V_2 * V_3 = F_18 ( V_32 ) ;
F_15 ( V_3 ) ;
F_19 ( F_18 ( V_32 ) ) ;
if ( F_12 ( V_3 , L_1 ) == 1 ) {
if ( F_13 ( V_3 ) )
F_6 ( V_3 -> V_4 ) ;
else
F_11 ( V_3 -> V_4 ) ;
}
return V_35 ;
}
static struct V_36 * F_20 ( struct V_1 * V_4 ,
const struct V_36 * V_37 ,
const char * V_38 )
{
struct V_36 * V_39 ;
F_21 ( & V_4 -> V_40 , sizeof( * V_39 ) , 32 ) ;
V_39 = F_22 ( & V_4 -> V_40 ) ;
if ( ! V_39 )
return NULL ;
* V_39 = * V_37 ;
if ( ! V_38 )
V_38 = V_37 -> V_38 ;
if ( V_38 ) {
V_39 -> V_38 = F_23 ( V_38 , V_5 ) ;
if ( ! V_39 -> V_38 )
return NULL ;
}
return V_39 ;
}
static int F_24 ( struct V_1 * V_4 , int type , const char * V_38 ,
int V_41 , unsigned long V_42 )
{
struct V_36 * V_39 ;
V_39 = F_20 ( V_4 , & V_43 [ type ] , V_38 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_45 = V_41 ;
if ( F_25 ( V_42 ) )
V_39 -> V_46 = V_47 ;
V_39 -> V_48 = V_42 ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_40 . V_49 ) {
struct V_36 * V_50 = V_4 -> V_40 . V_49 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_40 . V_52 ; V_51 ++ )
F_27 ( V_50 [ V_51 ] . V_38 ) ;
}
F_28 ( & V_4 -> V_40 ) ;
}
static int F_29 ( struct V_1 * V_4 , const char * V_53 ,
int V_54 , int V_41 , int V_55 )
{
char V_38 [ 32 ] ;
int V_56 ;
sprintf ( V_38 , L_2 , V_53 ) ;
V_56 = F_24 ( V_4 , V_57 , V_38 , V_54 ,
F_30 ( V_55 , 3 , V_41 , V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
sprintf ( V_38 , L_3 , V_53 ) ;
V_56 = F_24 ( V_4 , V_59 , V_38 , V_54 ,
F_30 ( V_55 , 3 , V_41 , V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
static bool F_31 ( struct V_2 * V_3 , T_3 V_60 , int V_61 ,
unsigned int V_62 )
{
unsigned int V_63 ;
if ( ! V_60 )
return false ;
V_63 = F_32 ( V_3 , V_60 ) ;
if ( V_61 == V_58 )
V_63 &= V_64 ;
else
V_63 &= V_65 ;
if ( ! V_63 )
return false ;
if ( F_33 ( V_3 , V_60 , V_61 ) & V_62 )
return true ;
return false ;
}
static void F_34 ( struct V_2 * V_3 , struct V_66 * V_67 ,
T_3 V_55 , int V_41 , bool V_68 )
{
int V_51 , V_69 , V_42 ;
if ( ! V_67 )
return;
V_69 = F_35 ( V_3 , V_55 , NULL ) ;
for ( V_51 = 0 ; V_51 < V_69 ; V_51 ++ ) {
if ( V_51 == V_41 )
V_42 = F_36 ( V_51 ) ;
else
V_42 = F_37 ( V_51 ) ;
F_7 ( V_3 , V_55 , 0 ,
V_70 , V_42 ) ;
}
}
static void F_38 ( struct V_2 * V_3 , struct V_66 * V_67 ,
bool V_68 , bool V_71 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_67 -> V_72 ; V_51 ++ ) {
T_3 V_73 , V_74 ;
int V_41 = V_67 -> V_41 [ V_51 ] ;
V_73 = V_67 -> V_67 [ V_51 ] ;
if ( V_51 < V_67 -> V_72 - 1 )
V_74 = V_67 -> V_67 [ V_51 + 1 ] ;
else
V_74 = 0 ;
if ( V_68 && V_67 -> V_75 [ V_51 ] )
F_7 ( V_3 , V_74 , 0 ,
V_76 , V_41 ) ;
if ( ! V_71 && ( V_74 == V_4 -> V_77 ) )
continue;
if ( F_39 ( V_3 , V_74 , V_58 ) )
F_34 ( V_3 , V_67 , V_74 , V_41 , V_68 ) ;
if ( ! V_71 && ( V_73 == V_67 -> V_78 || V_73 == V_67 -> V_79 ) )
continue;
if ( F_39 ( V_3 , V_73 , V_80 ) ) {
int V_42 = V_68 ? V_81 : V_82 ;
F_7 ( V_3 , V_73 , 0 ,
V_70 , V_42 ) ;
}
}
}
static void F_40 ( struct V_2 * V_3 , T_3 V_83 ,
int V_84 )
{
if ( ! V_83 )
return;
F_7 ( V_3 , V_83 , 0 , V_85 ,
V_84 ) ;
if ( F_41 ( V_3 , V_83 ) & V_86 )
F_7 ( V_3 , V_83 , 0 ,
V_87 , 0x02 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_66 * V_67 , int V_84 )
{
unsigned int V_63 ;
T_3 V_83 ;
if ( ! V_67 -> V_72 )
return;
V_83 = V_67 -> V_67 [ V_67 -> V_72 - 1 ] ;
F_40 ( V_3 , V_83 , V_84 ) ;
V_63 = F_33 ( V_3 , V_83 , V_80 ) ;
if ( V_63 & V_88 ) {
unsigned int V_42 ;
V_42 = ( V_63 & V_89 ) >> V_90 ;
F_7 ( V_3 , V_83 , 0 , V_70 ,
V_82 | V_42 ) ;
}
F_38 ( V_3 , V_67 , true , true ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_66 * V_67 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_27 . V_91 + V_4 -> V_92 ; V_51 ++ ) {
V_67 = & V_4 -> V_93 [ V_51 ] ;
if ( ! V_51 && V_4 -> V_94 && V_4 -> V_95 . V_72 )
V_67 = & V_4 -> V_95 ;
F_42 ( V_3 , V_67 , V_96 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_97 = V_4 -> V_98 ;
if ( V_4 -> V_99 ) {
F_38 ( V_3 , & V_4 -> V_100 , false , false ) ;
F_38 ( V_3 , & V_4 -> V_101 , false , false ) ;
if ( V_97 )
F_38 ( V_3 , & V_4 -> V_93 [ V_97 ] ,
false , false ) ;
} else if ( V_4 -> V_94 || ! V_4 -> V_100 . V_72 ) {
F_38 ( V_3 , & V_4 -> V_102 , false , false ) ;
F_38 ( V_3 , & V_4 -> V_100 , false , false ) ;
} else {
F_38 ( V_3 , & V_4 -> V_102 , false , false ) ;
F_38 ( V_3 , & V_4 -> V_101 , false , false ) ;
}
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_100 . V_72 ) {
F_42 ( V_3 , & V_4 -> V_101 , V_103 ) ;
return;
}
F_44 ( V_3 ) ;
if ( V_4 -> V_99 )
F_42 ( V_3 , & V_4 -> V_102 , V_103 ) ;
else if ( V_4 -> V_94 )
F_42 ( V_3 , & V_4 -> V_101 , V_103 ) ;
else
F_42 ( V_3 , & V_4 -> V_100 , V_103 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_104 )
return;
if ( ! V_4 -> V_105 . V_72 ) {
F_42 ( V_3 , & V_4 -> V_106 , V_96 ) ;
return;
}
if ( ! V_4 -> V_94 ) {
F_38 ( V_3 , & V_4 -> V_106 ,
false , false ) ;
F_42 ( V_3 , & V_4 -> V_105 , V_96 ) ;
} else {
F_38 ( V_3 , & V_4 -> V_105 , false , false ) ;
F_42 ( V_3 , & V_4 -> V_106 , V_96 ) ;
}
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_107 * V_108 = & V_4 -> V_27 ;
T_3 V_109 [ V_110 ] ;
unsigned int V_111 ;
int V_51 , V_112 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_113 ; V_51 ++ ) {
F_7 ( V_3 , V_4 -> V_114 [ V_51 ] , 0 ,
V_70 ,
F_36 ( 0 ) ) ;
}
for ( V_51 = 0 ; V_51 < V_108 -> V_115 ; V_51 ++ ) {
T_3 V_60 = V_108 -> V_116 [ V_51 ] . V_83 ;
if ( V_4 -> V_117 && F_48 ( V_3 , V_60 ) )
V_111 = V_96 ;
else if ( V_108 -> V_116 [ V_51 ] . type == V_118 )
V_111 = V_119 ;
else
V_111 = V_120 ;
F_7 ( V_3 , V_60 , 0 ,
V_85 , V_111 ) ;
}
for ( V_51 = 0 ; V_51 < V_4 -> V_113 ; V_51 ++ ) {
int V_121 = V_4 -> V_116 [ V_4 -> V_122 [ V_51 ] ] . V_121 ;
if ( V_4 -> V_123 [ V_121 ] ) {
int V_124 = V_4 -> V_116 [ V_4 -> V_122 [ V_51 ] ] . V_124 ;
F_7 ( V_3 , V_4 -> V_123 [ V_121 ] , 0 ,
V_76 ,
V_124 ) ;
}
if ( V_4 -> V_125 )
break;
}
if ( ! V_4 -> V_77 )
return;
V_112 = F_49 ( V_3 , V_4 -> V_77 , V_109 ,
F_50 ( V_109 ) ) ;
for ( V_51 = 0 ; V_51 < V_112 ; V_51 ++ ) {
unsigned int V_63 = F_32 ( V_3 , V_109 [ V_51 ] ) ;
if ( F_51 ( V_63 ) == V_126 )
F_7 ( V_3 , V_4 -> V_77 , 0 ,
V_70 ,
F_37 ( V_51 ) ) ;
}
}
static void F_52 ( struct V_2 * V_3 , T_3 V_60 ,
unsigned int * V_127 )
{
unsigned V_128 ;
unsigned V_129 = F_53 ( V_3 , V_60 ) ;
unsigned V_130 = ( V_129 & V_131 )
>> V_132
& V_133 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_134 = 0 ;
V_130 |= V_4 -> V_135 ;
if ( ! V_130 )
V_134 = F_54 ( V_3 , V_60 ) ;
if ( ( V_4 -> V_117 && F_48 ( V_3 , V_60 ) )
|| ( ( V_130 || V_134 )
&& F_55 ( V_129 ) != V_136 ) ) {
* V_127 = V_137 ;
V_128 = V_137 ;
} else
V_128 = V_138 ;
F_7 ( V_3 , V_60 , 0 , V_139 , V_128 ) ;
}
static int F_56 ( struct V_31 * V_32 ,
struct V_140 * V_141 )
{
static const char * const V_142 [] = {
L_4 , L_5
} ;
V_141 -> type = V_143 ;
V_141 -> V_144 = 1 ;
V_141 -> V_145 . V_146 . V_147 = 2 ;
if ( V_141 -> V_145 . V_146 . V_148 >= V_141 -> V_145 . V_146 . V_147 )
V_141 -> V_145 . V_146 . V_148 = V_141 -> V_145 . V_146 . V_147 - 1 ;
strcpy ( V_141 -> V_145 . V_146 . V_38 ,
V_142 [ V_141 -> V_145 . V_146 . V_148 ] ) ;
return 0 ;
}
static int F_57 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_34 -> V_145 . V_146 . V_148 [ 0 ] = ! V_4 -> V_135 ;
return 0 ;
}
static int F_58 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_42 = ! V_34 -> V_145 . V_146 . V_148 [ 0 ] ;
if ( V_42 == V_4 -> V_135 )
return 0 ;
V_4 -> V_135 = V_42 ;
F_15 ( V_3 ) ;
return 1 ;
}
static int F_59 ( struct V_31 * V_32 ,
struct V_140 * V_141 )
{
static const char * const V_142 [] = { L_6 , L_7 } ;
V_141 -> type = V_143 ;
V_141 -> V_144 = 1 ;
V_141 -> V_145 . V_146 . V_147 = 2 ;
if ( V_141 -> V_145 . V_146 . V_148 >= 2 )
V_141 -> V_145 . V_146 . V_148 = 1 ;
strcpy ( V_141 -> V_145 . V_146 . V_38 ,
V_142 [ V_141 -> V_145 . V_146 . V_148 ] ) ;
return 0 ;
}
static int F_60 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_34 -> V_145 . V_146 . V_148 [ 0 ] = V_4 -> V_99 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_4 )
{
const struct V_107 * V_108 = & V_4 -> V_27 ;
V_4 -> V_149 . V_150 = V_108 -> V_91 + V_4 -> V_92 ;
V_4 -> V_149 . V_151 = 0 ;
if ( ! V_4 -> V_99 ) {
if ( ! V_4 -> V_98 )
V_4 -> V_149 . V_151 = V_4 -> V_152 ;
} else {
if ( V_4 -> V_98 )
V_4 -> V_149 . V_150 = V_108 -> V_91 - 1 ;
}
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_97 = V_4 -> V_98 ;
T_3 V_153 , V_154 ;
if ( ! V_4 -> V_155 )
return;
V_153 = V_97 ? V_4 -> V_149 . V_156 [ V_97 ] : 0 ;
V_154 = V_4 -> V_152 ;
if ( V_4 -> V_99 ) {
if ( V_4 -> V_157 & V_158 ) {
F_63 ( V_3 , V_154 , 1 ) ;
F_63 ( V_3 , V_153 , 1 ) ;
}
if ( V_4 -> V_157 & V_159 )
F_64 ( V_3 , V_154 ,
V_4 -> V_160 , 0 ,
V_4 -> V_161 ) ;
} else {
if ( V_4 -> V_157 & V_159 )
F_63 ( V_3 , V_154 , 1 ) ;
if ( V_4 -> V_157 & V_158 ) {
T_3 V_162 ;
int V_163 ;
if ( V_153 ) {
V_162 = V_153 ;
V_163 = V_97 * 2 ;
} else {
V_162 = V_154 ;
V_163 = 0 ;
}
F_64 ( V_3 , V_162 ,
V_4 -> V_164 , V_163 ,
V_4 -> V_165 ) ;
}
}
F_61 ( V_4 ) ;
}
static int F_65 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_166 , V_97 ;
F_66 ( & V_4 -> V_6 ) ;
V_166 = ! ! V_34 -> V_145 . V_146 . V_148 [ 0 ] ;
if ( V_4 -> V_99 == V_166 ) {
F_67 ( & V_4 -> V_6 ) ;
return 0 ;
}
V_4 -> V_99 = V_166 ;
V_97 = V_4 -> V_98 ;
F_44 ( V_3 ) ;
if ( V_166 )
F_38 ( V_3 , & V_4 -> V_102 , true , false ) ;
else {
if ( V_97 )
F_38 ( V_3 , & V_4 -> V_93 [ V_97 ] ,
true , false ) ;
if ( V_4 -> V_94 || ! V_4 -> V_100 . V_72 )
F_38 ( V_3 , & V_4 -> V_101 ,
true , false ) ;
else
F_38 ( V_3 , & V_4 -> V_100 ,
true , false ) ;
}
F_62 ( V_3 ) ;
F_67 ( & V_4 -> V_6 ) ;
F_15 ( V_3 ) ;
F_68 ( V_3 ) ;
return 1 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_36 * V_39 ;
T_3 V_60 ;
V_60 = V_4 -> V_27 . V_28 [ 0 ] ;
V_39 = F_70 ( V_4 , & V_167 ) ;
if ( V_39 == NULL )
return - V_44 ;
V_39 -> V_46 = V_168 | V_60 ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_92 ; V_51 ++ ) {
struct V_31 * V_111 ;
struct V_169 V_170 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_171 = V_172 ;
sprintf ( V_170 . V_38 , L_2 , V_4 -> V_173 [ V_51 ] ) ;
V_111 = F_72 ( V_3 , V_170 . V_38 ) ;
if ( V_111 )
F_73 ( V_3 -> V_174 -> V_175 ,
V_176 ,
& V_111 -> V_170 ) ;
}
}
static void F_74 ( struct V_2 * V_3 , int V_177 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_42 = V_177 ? V_178 : V_179 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_92 ; V_51 ++ ) {
if ( V_4 -> V_180 [ V_51 ] < 0 )
continue;
F_75 ( V_3 , V_4 -> V_77 ,
V_58 , V_4 -> V_180 [ V_51 ] ,
V_178 , V_42 ) ;
}
}
static bool F_48 ( struct V_2 * V_3 , T_3 V_83 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_92 ; V_51 ++ )
if ( V_4 -> V_181 [ V_51 ] == V_83 )
return true ;
return false ;
}
static int F_76 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
* V_34 -> V_145 . integer . V_145 = V_4 -> V_117 ;
return 0 ;
}
static int F_77 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_182 = * V_34 -> V_145 . integer . V_145
? V_183 : V_184 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_92 ; V_51 ++ ) {
T_3 V_60 = V_4 -> V_181 [ V_51 ] ;
unsigned int V_128 ;
V_128 = F_78 ( V_3 , V_60 , 0 ,
V_185 , 0 ) ;
V_128 &= ~ ( V_184 | V_183 ) ;
V_128 |= V_182 ;
F_7 ( V_3 , V_60 , 0 ,
V_85 ,
V_128 ) ;
if ( V_182 == V_183 ) {
F_74 ( V_3 , 1 ) ;
F_71 ( V_3 ) ;
}
}
V_4 -> V_117 = * V_34 -> V_145 . integer . V_145 ;
F_15 ( V_3 ) ;
return 1 ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_92 )
return 0 ;
if ( ! F_70 ( V_4 , & V_186 ) )
return - V_44 ;
return 0 ;
}
static bool F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_187 * V_188 ;
int V_51 , V_163 , V_189 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_190 ; V_51 ++ ) {
V_188 = & V_4 -> V_191 [ V_51 ] ;
for ( V_163 = 0 ; V_163 < 2 ; V_163 ++ ) {
V_189 = F_80 ( V_3 , V_188 -> V_60 , V_163 , V_188 -> V_61 ,
V_188 -> V_41 ) ;
if ( ! ( V_189 & V_178 ) && V_189 > 0 )
return false ;
}
}
return true ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_68 ;
unsigned int V_192 , V_128 ;
V_68 = F_13 ( V_3 ) && ( V_4 -> V_155 != 0 ) ;
switch ( V_4 -> V_7 ) {
case V_18 :
case V_20 :
V_192 = 0xf70 ;
V_128 = V_68 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_22 :
case V_23 :
V_192 = 0xf73 ;
V_128 = V_68 ? 0x51 : 0xe1 ;
break;
case V_21 :
V_192 = 0xf73 ;
V_128 = V_68 ? 0x01 : 0x1d ;
break;
case V_24 :
case V_25 :
case V_26 :
V_192 = 0xf93 ;
V_128 = V_68 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_193 , 0 , V_192 , V_128 ) ;
}
static void F_81 ( struct V_2 * V_3 , int V_194 , bool V_195 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_195 )
V_4 -> V_155 |= V_194 ;
else
V_4 -> V_155 &= ~ V_194 ;
F_19 ( V_3 ) ;
}
static int F_82 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_107 * V_108 = & V_4 -> V_27 ;
int V_56 ;
V_4 -> V_149 . V_150 = V_108 -> V_91 + V_4 -> V_92 ;
V_4 -> V_149 . V_200 = V_4 -> V_149 . V_150 * 2 ;
F_81 ( V_3 , V_158 , true ) ;
V_56 = F_83 ( V_3 , & V_4 -> V_149 , V_199 ,
V_197 ) ;
if ( V_56 < 0 ) {
F_81 ( V_3 , V_158 , false ) ;
return V_56 ;
}
return 0 ;
}
static int F_84 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
F_81 ( V_3 , V_158 , false ) ;
return 0 ;
}
static int F_85 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_86 ( ! V_4 -> V_152 ) )
return - V_201 ;
F_81 ( V_3 , V_159 , true ) ;
return 0 ;
}
static int F_87 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
F_81 ( V_3 , V_159 , false ) ;
return 0 ;
}
static int F_88 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
unsigned int V_202 ,
unsigned int V_203 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
F_61 ( V_4 ) ;
F_89 ( V_3 , & V_4 -> V_149 , V_202 ,
V_203 , V_199 ) ;
V_4 -> V_157 |= V_158 ;
V_4 -> V_164 = V_202 ;
V_4 -> V_165 = V_203 ;
F_67 ( & V_4 -> V_6 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_90 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
unsigned int V_202 ,
unsigned int V_203 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_99 )
F_64 ( V_3 , V_4 -> V_152 ,
V_202 , 0 , V_203 ) ;
V_4 -> V_157 |= V_159 ;
V_4 -> V_160 = V_202 ;
V_4 -> V_161 = V_203 ;
F_67 ( & V_4 -> V_6 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_91 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
F_92 ( V_3 , & V_4 -> V_149 ) ;
V_4 -> V_157 &= ~ V_158 ;
F_67 ( & V_4 -> V_6 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_93 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_99 )
F_64 ( V_3 , V_4 -> V_152 , 0 , 0 , 0 ) ;
V_4 -> V_157 &= ~ V_159 ;
F_67 ( & V_4 -> V_6 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_95 ( V_3 , & V_4 -> V_149 ) ;
}
static int F_96 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_97 ( V_3 , & V_4 -> V_149 ) ;
}
static int F_98 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
unsigned int V_202 ,
unsigned int V_203 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_99 ( V_3 , & V_4 -> V_149 ,
V_202 , V_203 , V_199 ) ;
}
static int F_100 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_101 ( V_3 , & V_4 -> V_149 ) ;
return 0 ;
}
static int F_102 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
unsigned int V_202 ,
unsigned int V_203 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_64 ( V_3 , V_4 -> V_114 [ V_199 -> V_204 ] ,
V_202 , 0 , V_203 ) ;
return 0 ;
}
static int F_103 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_104 ( V_3 , V_4 -> V_114 [ V_199 -> V_204 ] ) ;
return 0 ;
}
static int F_105 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
unsigned int V_202 ,
unsigned int V_203 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_121 = V_4 -> V_116 [ V_4 -> V_122 [ 0 ] ] . V_121 ;
F_66 ( & V_4 -> V_6 ) ;
V_4 -> V_205 = V_4 -> V_114 [ V_121 ] ;
V_4 -> V_206 = V_202 ;
V_4 -> V_207 = V_203 ;
F_64 ( V_3 , V_4 -> V_205 , V_202 , 0 , V_203 ) ;
F_67 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_106 ( struct V_196 * V_197 ,
struct V_2 * V_3 ,
struct V_198 * V_199 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_66 ( & V_4 -> V_6 ) ;
F_104 ( V_3 , V_4 -> V_205 ) ;
V_4 -> V_205 = 0 ;
F_67 ( & V_4 -> V_6 ) ;
return 0 ;
}
static bool F_107 ( struct V_2 * V_3 , int V_166 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_121 = V_4 -> V_116 [ V_166 ] . V_121 ;
T_3 V_208 = V_4 -> V_114 [ V_121 ] ;
bool V_209 = false ;
F_66 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_205 && V_4 -> V_205 != V_208 ) {
F_63 ( V_3 , V_4 -> V_205 , 1 ) ;
V_4 -> V_205 = V_208 ;
F_64 ( V_3 , V_208 ,
V_4 -> V_206 , 0 ,
V_4 -> V_207 ) ;
V_209 = true ;
}
F_67 ( & V_4 -> V_6 ) ;
return V_209 ;
}
static int F_108 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_31 * V_50 ;
int V_56 , V_51 ;
if ( V_4 -> F_15 )
if ( ! F_70 ( V_4 , & V_210 ) )
return - V_44 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_211 ; V_51 ++ ) {
V_56 = F_109 ( V_3 , V_4 -> V_212 [ V_51 ] ) ;
if ( V_56 < 0 )
return V_56 ;
}
if ( V_4 -> V_149 . V_213 ) {
V_56 = F_110 ( V_3 ,
V_4 -> V_149 . V_213 ,
V_4 -> V_149 . V_213 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_111 ( V_3 ,
& V_4 -> V_149 ) ;
if ( V_56 < 0 )
return V_56 ;
V_4 -> V_149 . V_214 = 1 ;
}
if ( V_4 -> V_215 ) {
V_56 = F_112 ( V_3 , V_4 -> V_215 ) ;
if ( V_56 < 0 )
return V_56 ;
}
if ( ! F_72 ( V_3 , L_8 ) ) {
unsigned int V_216 [ 4 ] ;
F_113 ( V_3 , V_4 -> V_149 . V_156 [ 0 ] ,
V_80 , V_216 ) ;
V_56 = F_114 ( V_3 , L_8 ,
V_216 , V_217 ) ;
if ( V_56 < 0 )
return V_56 ;
}
if ( ! F_72 ( V_3 , L_9 ) ) {
V_56 = F_114 ( V_3 , L_9 ,
NULL , V_218 ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_50 = F_72 ( V_3 , L_10 ) ;
for ( V_51 = 0 ; V_50 && V_51 < V_50 -> V_144 ; V_51 ++ ) {
V_56 = F_115 ( V_3 , V_50 , V_51 , V_4 -> V_123 [ V_51 ] ) ;
if ( V_56 < 0 )
return V_56 ;
}
F_15 ( V_3 ) ;
F_19 ( V_3 ) ;
F_26 ( V_3 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_219 * V_220 = V_4 -> V_221 ;
V_3 -> V_222 = 1 ;
V_3 -> V_223 = V_220 ;
snprintf ( V_4 -> V_224 , sizeof( V_4 -> V_224 ) ,
L_11 , V_3 -> V_225 ) ;
V_220 -> V_38 = V_4 -> V_224 ;
if ( ! V_4 -> V_226 )
V_4 -> V_226 = & V_227 ;
V_220 -> V_228 [ V_229 ] =
* V_4 -> V_226 ;
V_220 -> V_228 [ V_229 ] . V_60 =
V_4 -> V_149 . V_156 [ 0 ] ;
V_220 -> V_228 [ V_229 ] . V_230 =
V_4 -> V_149 . V_200 ;
if ( ! V_4 -> V_231 ) {
if ( V_4 -> V_125 )
V_4 -> V_231 =
& V_232 ;
else
V_4 -> V_231 = & V_233 ;
}
V_220 -> V_228 [ V_234 ] =
* V_4 -> V_231 ;
V_220 -> V_228 [ V_234 ] . V_60 = V_4 -> V_114 [ 0 ] ;
if ( ! V_4 -> V_125 )
V_220 -> V_228 [ V_234 ] . V_235 =
V_4 -> V_113 ;
if ( V_4 -> V_149 . V_213 || V_4 -> V_215 ) {
V_3 -> V_222 ++ ;
V_220 ++ ;
snprintf ( V_4 -> V_236 ,
sizeof( V_4 -> V_236 ) ,
L_12 , V_3 -> V_225 ) ;
V_220 -> V_38 = V_4 -> V_236 ;
V_220 -> V_237 = V_238 ;
if ( V_4 -> V_149 . V_213 ) {
if ( ! V_4 -> V_239 )
V_4 -> V_239 =
& V_240 ;
V_220 -> V_228 [ V_229 ] =
* V_4 -> V_239 ;
V_220 -> V_228 [ V_229 ] . V_60 =
V_4 -> V_149 . V_213 ;
}
if ( V_4 -> V_215 ) {
if ( ! V_4 -> V_241 )
V_4 -> V_241 =
& V_242 ;
V_220 -> V_228 [ V_234 ] =
* V_4 -> V_241 ;
V_220 -> V_228 [ V_234 ] . V_60 =
V_4 -> V_215 ;
}
}
if ( V_4 -> V_152 ) {
V_3 -> V_222 ++ ;
V_220 ++ ;
snprintf ( V_4 -> V_243 , sizeof( V_4 -> V_243 ) ,
L_13 , V_3 -> V_225 ) ;
V_220 -> V_38 = V_4 -> V_243 ;
V_220 -> V_228 [ V_229 ] = V_244 ;
V_220 -> V_228 [ V_229 ] . V_60 =
V_4 -> V_152 ;
}
return 0 ;
}
static void F_117 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_26 ( V_3 ) ;
F_11 ( V_4 ) ;
F_27 ( V_4 -> V_245 ) ;
F_27 ( V_4 -> V_246 ) ;
F_27 ( V_4 ) ;
}
static void F_118 ( struct V_2 * V_3 , int V_247 ,
T_3 * V_248 , bool V_177 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_247 ; V_51 ++ ) {
unsigned int V_128 = F_78 ( V_3 , V_248 [ V_51 ] , 0 ,
V_185 , 0 ) ;
if ( V_128 & V_184 )
continue;
if ( V_177 )
V_128 &= ~ V_183 ;
else
V_128 |= V_183 ;
F_7 ( V_3 , V_248 [ V_51 ] , 0 ,
V_85 , V_128 ) ;
}
}
static void F_119 ( struct V_2 * V_3 , int V_134 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_27 . V_104 )
return;
if ( ! V_134 )
V_134 = F_54 ( V_3 ,
V_4 -> V_27 . V_249 [ 0 ] ) ;
F_118 ( V_3 , V_4 -> V_27 . V_104 ,
V_4 -> V_27 . V_250 ,
V_134 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
int V_134 = 0 ;
int V_251 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_99 && V_4 -> V_27 . V_28 [ 0 ] )
V_134 = F_54 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_4 -> V_117 )
V_251 = V_4 -> V_27 . V_91 + V_4 -> V_92 ;
else
V_251 = V_4 -> V_27 . V_91 ;
F_118 ( V_3 , V_251 , V_4 -> V_27 . V_249 , V_134 ) ;
F_119 ( V_3 , V_134 ) ;
}
static void F_120 ( struct V_2 * V_3 )
{
unsigned int V_252 ;
unsigned int V_253 ;
unsigned int V_254 ;
unsigned int V_255 ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_252 = F_78 ( V_3 , V_3 -> V_193 , 0 ,
V_256 , 0 ) & 0x03 ;
V_253 = ( F_78 ( V_3 , V_3 -> V_193 , 0 ,
0xF84 , 0 ) & 0x3F0000 ) >> 16 ;
V_254 = V_253 & 0x1F ;
V_255 = F_78 ( V_3 , 0x1A , 0 ,
V_257 ,
V_258 ) ;
if ( V_252 == 0x02 ) {
F_7 ( V_3 , V_4 -> V_27 . V_249 [ 0 ] , 0 ,
V_85 ,
V_96 ) ;
if ( V_253 & 0x20 ) {
if ( V_254 > V_255 )
V_254 = V_255 ;
F_75 ( V_3 , 0x1A , V_58 ,
0 , V_259 ,
V_255 - V_254 ) ;
} else {
F_75 ( V_3 , 0x1A , V_58 , 0 ,
V_259 ,
( ( V_255 + V_254 ) > 0x2A ) ? 0x2A :
( V_255 + V_254 ) ) ;
}
} else if ( ! ( V_252 & 0x02 ) ) {
F_7 ( V_3 , V_4 -> V_27 . V_249 [ 0 ] , 0 ,
V_85 ,
0 ) ;
}
}
static void F_121 ( struct V_2 * V_3 ,
unsigned int V_260 )
{
V_260 >>= 26 ;
if ( V_260 & V_261 )
F_15 ( V_3 ) ;
V_260 &= ~ V_261 ;
if ( V_260 == V_262 || V_260 == V_263 )
F_68 ( V_3 ) ;
else if ( V_260 == V_264 )
F_120 ( V_3 ) ;
}
static int F_122 ( struct V_2 * V_3 , T_4 V_265 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 , T_3 V_60 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_124 ( V_3 , & V_4 -> V_266 , V_60 ) ;
}
static bool F_125 ( struct V_2 * V_3 , T_3 V_162 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_149 . V_150 ; V_51 ++ ) {
if ( V_4 -> V_149 . V_156 [ V_51 ] == V_162 )
return false ;
}
if ( V_4 -> V_152 == V_162 )
return false ;
return true ;
}
static bool F_126 ( struct V_2 * V_3 , T_3 V_60 ,
T_3 V_267 , int V_268 ,
struct V_66 * V_67 , int V_72 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_109 [ 8 ] ;
int V_51 , V_251 ;
if ( V_60 == V_4 -> V_77 ) {
if ( ! V_268 )
return false ;
V_268 = 2 ;
}
V_251 = F_49 ( V_3 , V_60 , V_109 , F_50 ( V_109 ) ) ;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ ) {
if ( F_51 ( F_32 ( V_3 , V_109 [ V_51 ] ) ) != V_269 )
continue;
if ( V_109 [ V_51 ] == V_267 || F_125 ( V_3 , V_109 [ V_51 ] ) ) {
if ( ! ( V_4 -> V_77 && V_268 == 1 ) )
goto V_270;
}
}
if ( V_72 >= V_271 )
return false ;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ ) {
unsigned int type ;
type = F_51 ( F_32 ( V_3 , V_109 [ V_51 ] ) ) ;
if ( type == V_269 )
continue;
if ( F_126 ( V_3 , V_109 [ V_51 ] , V_267 ,
V_268 , V_67 , V_72 + 1 ) )
goto V_270;
}
return false ;
V_270:
V_67 -> V_67 [ V_67 -> V_72 ] = V_109 [ V_51 ] ;
V_67 -> V_41 [ V_67 -> V_72 ] = V_51 ;
if ( V_251 > 1 && F_51 ( F_32 ( V_3 , V_60 ) ) != V_272 )
V_67 -> V_75 [ V_67 -> V_72 ] = 1 ;
V_67 -> V_72 ++ ;
return true ;
}
static bool F_127 ( struct V_2 * V_3 , T_3 V_60 ,
T_3 V_267 , int V_268 ,
struct V_66 * V_67 )
{
if ( F_126 ( V_3 , V_60 , V_267 , V_268 , V_67 , 1 ) ) {
V_67 -> V_67 [ V_67 -> V_72 ] = V_60 ;
V_67 -> V_72 ++ ;
F_128 ( L_14 ,
V_67 -> V_72 , V_67 -> V_67 [ 0 ] , V_67 -> V_67 [ 1 ] ,
V_67 -> V_67 [ 2 ] , V_67 -> V_67 [ 3 ] , V_67 -> V_67 [ 4 ] ) ;
return true ;
}
return false ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_107 * V_108 = & V_4 -> V_27 ;
int V_51 , V_273 ;
T_3 V_60 ;
V_4 -> V_149 . V_156 = V_4 -> V_274 ;
V_273 = 0 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_91 ; V_51 ++ ) {
T_3 V_162 = 0 ;
V_60 = V_108 -> V_249 [ V_51 ] ;
if ( ! V_60 )
continue;
if ( F_127 ( V_3 , V_60 , 0 , 0 , & V_4 -> V_93 [ V_51 ] ) )
V_162 = V_4 -> V_93 [ V_51 ] . V_67 [ 0 ] ;
if ( ! V_51 && F_127 ( V_3 , V_60 , V_162 , 1 ,
& V_4 -> V_95 ) )
V_162 = V_4 -> V_95 . V_67 [ 0 ] ;
if ( V_162 ) {
V_4 -> V_274 [ V_51 ] = V_162 ;
V_273 ++ ;
}
}
if ( ! V_4 -> V_93 [ 0 ] . V_72 && V_4 -> V_95 . V_72 ) {
V_4 -> V_93 [ 0 ] = V_4 -> V_95 ;
V_4 -> V_95 . V_72 = 0 ;
}
V_4 -> V_149 . V_150 = V_273 ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 , const char * V_275 ,
int V_276 , bool V_277 , struct V_66 * V_67 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_38 [ 32 ] ;
T_3 V_162 , V_83 , V_278 , V_60 ;
int V_56 ;
V_162 = V_277 ? V_67 -> V_67 [ 0 ] : 0 ;
V_83 = V_67 -> V_67 [ V_67 -> V_72 - 1 ] ;
V_278 = V_67 -> V_72 > 1 ? V_67 -> V_67 [ 1 ] : 0 ;
if ( V_162 && F_31 ( V_3 , V_162 , V_80 , V_279 ) )
V_60 = V_162 ;
else if ( F_31 ( V_3 , V_83 , V_80 , V_279 ) )
V_60 = V_83 ;
else if ( F_31 ( V_3 , V_278 , V_80 , V_279 ) )
V_60 = V_278 ;
else
V_60 = 0 ;
if ( V_60 ) {
sprintf ( V_38 , L_2 , V_275 ) ;
V_56 = F_131 ( V_4 , V_57 , V_38 ,
F_30 ( V_60 , V_276 , 0 , V_80 ) ) ;
if ( V_56 < 0 )
return V_56 ;
V_67 -> V_78 = V_60 ;
}
if ( V_162 && F_31 ( V_3 , V_162 , V_80 , V_88 ) )
V_60 = V_162 ;
else if ( F_31 ( V_3 , V_83 , V_80 , V_88 ) )
V_60 = V_83 ;
else if ( F_31 ( V_3 , V_278 , V_80 , V_88 ) )
V_60 = V_278 ;
else
V_60 = 0 ;
if ( V_60 ) {
sprintf ( V_38 , L_3 , V_275 ) ;
V_56 = F_131 ( V_4 , V_280 , V_38 ,
F_30 ( V_60 , V_276 , 0 , V_80 ) ) ;
if ( V_56 < 0 )
return V_56 ;
V_67 -> V_79 = V_60 ;
}
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_107 * V_108 = & V_4 -> V_27 ;
struct V_281 * V_282 = V_108 -> V_116 ;
int V_51 , V_283 , V_251 , V_284 ;
int V_248 [ V_285 ] ;
for ( V_284 = V_286 ; V_284 >= V_287 ; V_284 -- ) {
V_251 = 0 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_115 ; V_51 ++ ) {
unsigned int V_288 ;
if ( V_282 [ V_51 ] . type > V_289 )
continue;
V_288 = F_53 ( V_3 , V_282 [ V_51 ] . V_83 ) ;
if ( F_133 ( V_288 ) != V_284 )
continue;
for ( V_283 = 0 ; V_283 < V_251 ; V_283 ++ )
if ( V_282 [ V_248 [ V_283 ] ] . type < V_282 [ V_51 ] . type ) {
memmove ( V_248 + V_283 + 1 , V_248 + V_283 ,
( V_251 - V_283 ) * sizeof( int ) ) ;
break;
}
V_248 [ V_283 ] = V_51 ;
V_251 ++ ;
}
if ( V_108 -> V_91 + V_251 < 3 )
continue;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ ) {
T_3 V_83 = V_282 [ V_248 [ V_51 ] ] . V_83 ;
V_4 -> V_181 [ V_4 -> V_92 ++ ] = V_83 ;
V_108 -> V_249 [ V_108 -> V_91 ++ ] = V_83 ;
if ( V_108 -> V_91 == 3 )
break;
}
return;
}
}
static void F_134 ( struct V_66 * V_74 , struct V_66 * V_73 )
{
V_74 -> V_78 = V_73 -> V_78 ;
V_74 -> V_79 = V_73 -> V_79 ;
}
static int F_135 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_107 * V_108 = & V_4 -> V_27 ;
struct V_66 * V_67 ;
static const char * const V_290 [ 4 ] = {
L_15 , L_16 , L_17 , L_18
} ;
int V_51 , V_41 , V_56 ;
int V_291 ;
V_291 = V_108 -> V_91 ;
if ( V_108 -> V_91 == 1 )
F_132 ( V_3 ) ;
V_56 = F_129 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_4 -> V_149 . V_150 < 3 ) {
V_4 -> V_92 = 0 ;
V_108 -> V_91 = V_291 ;
}
for ( V_51 = 0 ; V_51 < V_108 -> V_91 ; V_51 ++ ) {
T_3 V_83 , V_162 ;
V_83 = V_108 -> V_249 [ V_51 ] ;
V_162 = V_4 -> V_149 . V_156 [ V_51 ] ;
if ( ! V_83 || ! V_162 )
continue;
V_67 = V_4 -> V_93 + V_51 ;
if ( V_51 == V_292 ) {
V_56 = F_130 ( V_3 , L_19 , 1 , true , V_67 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_130 ( V_3 , L_20 , 2 , true , V_67 ) ;
if ( V_56 < 0 )
return V_56 ;
} else {
const char * V_275 = V_290 [ V_51 ] ;
if ( V_108 -> V_293 == V_294 &&
V_108 -> V_91 == 1 )
V_275 = L_21 ;
V_56 = F_130 ( V_3 , V_275 , 3 , true , V_67 ) ;
if ( V_56 < 0 )
return V_56 ;
}
if ( V_67 != V_4 -> V_93 + V_51 )
F_134 ( & V_4 -> V_93 [ V_51 ] , V_67 ) ;
if ( V_67 == V_4 -> V_93 && V_4 -> V_95 . V_72 )
F_134 ( & V_4 -> V_95 , V_67 ) ;
}
V_41 = F_136 ( V_3 , V_4 -> V_77 ,
V_4 -> V_149 . V_156 [ 0 ] ) ;
if ( V_41 >= 0 ) {
const char * V_38 ;
V_38 = V_4 -> V_95 . V_72 ?
L_22 : L_23 ;
V_56 = F_131 ( V_4 , V_57 , V_38 ,
F_30 ( V_4 -> V_77 , 3 ,
V_41 , V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
V_38 = V_4 -> V_95 . V_72 ?
L_24 : L_25 ;
V_56 = F_131 ( V_4 , V_280 , V_38 ,
F_30 ( V_4 -> V_77 , 3 ,
V_41 , V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_108 -> V_91 = V_291 ;
return 0 ;
}
static int F_137 ( struct V_2 * V_3 , T_3 V_83 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_66 * V_67 ;
bool V_277 ;
int V_51 , V_56 ;
if ( ! V_83 )
return 0 ;
if ( ! F_127 ( V_3 , V_83 , 0 , 0 , & V_4 -> V_102 ) ) {
for ( V_51 = V_295 ; V_51 >= V_292 ; V_51 -- ) {
if ( V_51 < V_4 -> V_149 . V_150 &&
F_127 ( V_3 , V_83 ,
V_4 -> V_149 . V_156 [ V_51 ] , 0 ,
& V_4 -> V_102 ) ) {
V_4 -> V_98 = V_51 ;
break;
}
}
}
if ( V_4 -> V_102 . V_72 ) {
V_4 -> V_152 = V_4 -> V_102 . V_67 [ 0 ] ;
if ( ! V_4 -> V_98 )
V_4 -> V_100 = V_4 -> V_102 ;
}
if ( ! V_4 -> V_100 . V_72 )
F_127 ( V_3 , V_83 ,
V_4 -> V_149 . V_156 [ V_296 ] , 0 ,
& V_4 -> V_100 ) ;
if ( ! F_127 ( V_3 , V_83 , V_4 -> V_149 . V_156 [ V_296 ] ,
1 , & V_4 -> V_101 ) && ! V_4 -> V_100 . V_72 )
return 0 ;
if ( V_4 -> V_100 . V_72 ) {
V_67 = & V_4 -> V_100 ;
V_277 = true ;
} else {
V_67 = & V_4 -> V_101 ;
V_277 = false ;
}
V_56 = F_130 ( V_3 , L_26 , 3 , V_277 , V_67 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_277 )
F_134 ( & V_4 -> V_101 , V_67 ) ;
else
F_134 ( & V_4 -> V_100 , V_67 ) ;
if ( V_4 -> V_102 . V_72 )
F_134 ( & V_4 -> V_102 , V_67 ) ;
return 0 ;
}
static int F_138 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_66 * V_67 ;
bool V_277 ;
T_3 V_83 , V_162 = 0 ;
int V_56 ;
V_83 = V_4 -> V_27 . V_250 [ 0 ] ;
if ( ! V_4 -> V_27 . V_104 || ! V_83 )
return 0 ;
if ( F_127 ( V_3 , V_83 , 0 , 0 , & V_4 -> V_105 ) )
V_162 = V_4 -> V_105 . V_67 [ 0 ] ;
if ( ! V_162 )
F_127 ( V_3 , V_83 ,
V_4 -> V_149 . V_156 [ V_296 ] , 0 ,
& V_4 -> V_105 ) ;
if ( ! F_127 ( V_3 , V_83 , V_4 -> V_149 . V_156 [ V_296 ] ,
1 , & V_4 -> V_106 ) && ! V_162 )
return 0 ;
if ( ! V_4 -> V_95 . V_72 && V_4 -> V_106 . V_72 )
V_162 = 0 ;
V_4 -> V_297 = V_162 ;
V_4 -> V_149 . V_298 [ 0 ] = V_162 ;
if ( V_162 ) {
V_67 = & V_4 -> V_105 ;
V_277 = true ;
} else {
V_67 = & V_4 -> V_106 ;
V_277 = false ;
}
V_56 = F_130 ( V_3 , L_21 , 3 , V_277 , V_67 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_277 )
F_134 ( & V_4 -> V_106 , V_67 ) ;
else
F_134 ( & V_4 -> V_105 , V_67 ) ;
return 0 ;
}
static int F_139 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_34 -> V_145 . V_146 . V_148 [ 0 ] = V_4 -> V_94 ;
return 0 ;
}
static void F_140 ( struct V_2 * V_3 , int V_299 ,
struct V_66 * V_300 , struct V_66 * V_301 )
{
if ( V_299 ) {
F_38 ( V_3 , V_300 , false , false ) ;
F_38 ( V_3 , V_301 , true , false ) ;
} else {
F_38 ( V_3 , V_301 , false , false ) ;
F_38 ( V_3 , V_300 , true , false ) ;
}
}
static int F_141 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_42 = V_34 -> V_145 . V_146 . V_148 [ 0 ] ;
if ( V_42 == V_4 -> V_94 )
return 0 ;
V_4 -> V_94 = V_42 ;
F_140 ( V_3 , V_42 , & V_4 -> V_93 [ 0 ] , & V_4 -> V_95 ) ;
if ( ! V_4 -> V_99 ) {
F_140 ( V_3 , V_42 , & V_4 -> V_100 ,
& V_4 -> V_101 ) ;
}
F_140 ( V_3 , V_42 , & V_4 -> V_105 ,
& V_4 -> V_106 ) ;
return 1 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_77 || ! V_4 -> V_95 . V_72 )
return 0 ;
if ( ! F_70 ( V_4 , & V_302 ) )
return - V_44 ;
return 0 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_60 = V_3 -> V_303 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_3 -> V_304 ; V_51 ++ , V_60 ++ ) {
unsigned int V_305 = F_32 ( V_3 , V_60 ) ;
if ( F_51 ( V_305 ) != V_306 )
continue;
if ( V_305 & V_307 )
continue;
if ( ! ( V_305 & V_308 ) )
continue;
if ( V_4 -> V_113 >= F_50 ( V_4 -> V_114 ) )
return - V_44 ;
V_4 -> V_114 [ V_4 -> V_113 ++ ] = V_60 ;
}
return 0 ;
}
static int F_144 ( struct V_31 * V_32 ,
struct V_140 * V_141 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_141 -> type = V_143 ;
V_141 -> V_144 = 1 ;
V_141 -> V_145 . V_146 . V_147 = V_4 -> V_115 ;
if ( V_141 -> V_145 . V_146 . V_148 >= V_4 -> V_115 )
V_141 -> V_145 . V_146 . V_148 = V_4 -> V_115 - 1 ;
strcpy ( V_141 -> V_145 . V_146 . V_38 ,
V_4 -> V_116 [ V_141 -> V_145 . V_146 . V_148 ] . V_309 ) ;
return 0 ;
}
static int F_145 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_41 = F_146 ( V_32 , & V_34 -> V_170 ) ;
V_34 -> V_145 . V_146 . V_148 [ 0 ] = V_4 -> V_122 [ V_41 ] ;
return 0 ;
}
static int F_147 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_41 = F_146 ( V_32 , & V_34 -> V_170 ) ;
T_3 V_310 ;
int V_166 ;
V_166 = V_34 -> V_145 . V_146 . V_148 [ 0 ] ;
if ( V_166 < 0 || V_166 >= V_4 -> V_115 )
return - V_201 ;
if ( V_4 -> V_122 [ V_41 ] == V_166 )
return 0 ;
V_4 -> V_122 [ V_41 ] = V_166 ;
if ( V_4 -> V_125 ) {
int V_121 = V_4 -> V_116 [ V_166 ] . V_121 ;
V_310 = V_4 -> V_123 [ V_121 ] ;
F_107 ( V_3 , V_166 ) ;
} else {
V_310 = V_4 -> V_123 [ V_41 ] ;
if ( F_86 ( ! V_310 ) )
return - V_201 ;
}
if ( V_310 ) {
if ( F_78 ( V_3 , V_310 , 0 ,
V_311 , 0x00 ) != V_137 )
F_7 ( V_3 , V_310 , 0 ,
V_139 , V_137 ) ;
F_7 ( V_3 , V_310 , 0 ,
V_76 ,
V_4 -> V_116 [ V_166 ] . V_124 ) ;
}
F_15 ( V_3 ) ;
return 0 ;
}
static int F_148 ( struct V_2 * V_3 , int V_144 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_36 * V_39 ;
if ( V_4 -> V_115 <= 1 || ! V_144 )
return 0 ;
V_39 = F_70 ( V_4 , & V_312 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_144 = V_144 ;
return 0 ;
}
static void F_149 ( struct V_1 * V_4 , T_3 V_301 , int V_41 )
{
struct V_187 * V_49 ;
if ( V_4 -> V_190 >= F_50 ( V_4 -> V_191 ) - 1 )
return;
V_49 = V_4 -> V_191 + V_4 -> V_190 ;
V_49 -> V_60 = V_301 ;
V_49 -> V_61 = V_58 ;
V_49 -> V_41 = V_41 ;
V_4 -> V_190 ++ ;
V_4 -> V_266 . V_313 = V_4 -> V_191 ;
}
static bool F_150 ( struct V_2 * V_3 , T_3 V_73 ,
T_3 V_74 )
{
return F_151 ( V_3 , V_73 , V_74 , 1 ) >= 0 ;
}
static bool F_152 ( struct V_2 * V_3 , T_3 V_83 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_314 , V_41 ;
V_4 -> V_116 [ V_4 -> V_115 ] . V_121 = - 1 ;
V_4 -> V_116 [ V_4 -> V_115 ] . V_83 = V_83 ;
for ( V_314 = 0 ; V_314 < V_4 -> V_113 ; V_314 ++ ) {
if ( V_4 -> V_123 [ V_314 ] ) {
V_41 = F_136 ( V_3 , V_4 -> V_123 [ V_314 ] ,
V_83 ) ;
if ( V_41 < 0 )
continue;
V_4 -> V_116 [ V_4 -> V_115 ] . V_124 = V_41 ;
} else {
if ( ! F_150 ( V_3 , V_4 -> V_114 [ V_314 ] , V_83 ) )
continue;
}
V_4 -> V_116 [ V_4 -> V_115 ] . V_121 = V_314 ;
if ( ! V_4 -> V_125 &&
V_4 -> V_115 > 0 && V_4 -> V_116 [ 0 ] . V_121 != V_314 ) {
F_153 ( V_315
L_27 ) ;
V_4 -> V_125 = 1 ;
}
return true ;
}
return false ;
}
static int F_154 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_107 * V_108 = & V_4 -> V_27 ;
int V_51 , V_56 ;
V_56 = F_143 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_155 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_115 ; V_51 ++ ) {
if ( F_152 ( V_3 , V_108 -> V_116 [ V_51 ] . V_83 ) )
V_4 -> V_116 [ V_4 -> V_115 ++ ] . V_309 =
F_156 ( V_3 , V_108 , V_51 ) ;
}
if ( V_4 -> V_77 &&
F_152 ( V_3 , V_4 -> V_77 ) )
V_4 -> V_116 [ V_4 -> V_115 ++ ] . V_309 = L_28 ;
return 0 ;
}
static int F_157 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_107 * V_108 = & V_4 -> V_27 ;
const char * V_316 = NULL ;
int V_54 = 0 ;
int V_51 , V_283 , V_56 , V_41 ;
if ( ! V_4 -> V_77 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_115 ; V_51 ++ ) {
T_3 V_83 = V_108 -> V_116 [ V_51 ] . V_83 ;
const char * V_309 = F_156 ( V_3 , V_108 , V_51 ) ;
if ( V_316 && ! strcmp ( V_309 , V_316 ) )
V_54 ++ ;
else
V_54 = 0 ;
V_316 = V_309 ;
V_41 = F_136 ( V_3 , V_4 -> V_77 , V_83 ) ;
if ( V_41 >= 0 ) {
V_56 = F_29 ( V_4 , V_309 , V_54 ,
V_41 , V_4 -> V_77 ) ;
if ( V_56 < 0 )
return V_56 ;
F_149 ( V_4 , V_4 -> V_77 , V_41 ) ;
}
for ( V_283 = 0 ; V_283 < V_4 -> V_92 ; V_283 ++ ) {
if ( V_4 -> V_181 [ V_283 ] == V_83 ) {
V_4 -> V_180 [ V_283 ] = V_41 ;
V_4 -> V_173 [ V_283 ] = V_309 ;
break;
}
}
}
return 0 ;
}
static int F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_107 * V_108 = & V_4 -> V_27 ;
int V_51 , V_56 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_115 ; V_51 ++ ) {
T_3 V_83 = V_108 -> V_116 [ V_51 ] . V_83 ;
unsigned int V_63 ;
const char * V_309 ;
char V_38 [ 32 ] ;
if ( V_108 -> V_116 [ V_51 ] . type != V_118 )
continue;
V_63 = F_33 ( V_3 , V_83 , V_58 ) ;
if ( V_63 == - 1 || ! ( V_63 & V_279 ) )
continue;
V_309 = F_156 ( V_3 , V_108 , V_51 ) ;
snprintf ( V_38 , sizeof( V_38 ) , L_29 , V_309 ) ;
V_56 = F_131 ( V_4 , V_57 , V_38 ,
F_30 ( V_83 , 3 , 0 , V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 , V_56 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_113 ; V_51 ++ ) {
T_3 V_208 = V_4 -> V_114 [ V_51 ] ;
V_56 = F_24 ( V_4 , V_57 ,
L_30 , V_51 ,
F_30 ( V_208 , 3 , 0 ,
V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_24 ( V_4 , V_280 ,
L_31 , V_51 ,
F_30 ( V_208 , 3 , 0 ,
V_58 ) ) ;
if ( V_56 < 0 )
return V_56 ;
}
for ( V_51 = 0 ; V_51 < V_4 -> V_113 ; V_51 ++ )
if ( ! V_4 -> V_123 [ V_51 ] )
break;
V_56 = F_148 ( V_3 , V_51 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
static int F_160 ( struct V_1 * V_4 , struct V_317 * * V_318 ,
struct V_319 * V_320 )
{
struct V_317 * V_111 ;
int V_51 ;
V_111 = F_2 ( sizeof( * V_111 ) + sizeof( long ) * 4 , V_5 ) ;
if ( ! V_111 )
return - V_44 ;
V_111 -> V_320 = V_320 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_113 ; V_51 ++ )
V_111 -> V_321 [ V_51 ] =
F_30 ( V_4 -> V_114 [ V_51 ] , 3 , 0 , V_58 ) ;
* V_318 = V_111 ;
return 0 ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_36 * V_39 ;
int V_56 ;
V_56 = F_160 ( V_4 , & V_4 -> V_245 , & V_322 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_160 ( V_4 , & V_4 -> V_246 , & V_323 ) ;
if ( V_56 < 0 )
return V_56 ;
V_39 = F_70 ( V_4 , & V_324 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_48 = ( long ) V_4 -> V_245 ;
V_39 = F_70 ( V_4 , & V_325 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_48 = ( long ) V_4 -> V_246 ;
V_56 = F_148 ( V_3 , 1 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
V_56 = F_154 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_4 -> V_125 )
V_56 = F_161 ( V_3 ) ;
else
V_56 = F_159 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_157 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_158 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
static void F_163 ( struct V_2 * V_3 , T_3 V_60 )
{
unsigned int V_129 ;
unsigned char V_326 ;
V_129 = F_53 ( V_3 , V_60 ) ;
V_326 = ( unsigned char ) F_164 ( V_129 ) ;
V_326 = ( V_326 << 4 ) | F_165 ( V_129 ) ;
if ( F_55 ( V_129 ) == V_136
&& ( V_326 == 0xf0 || V_326 == 0xff ) ) {
V_129 = V_129 & ( ~ ( V_327 << 30 ) ) ;
F_166 ( V_3 , V_60 , V_129 ) ;
}
return;
}
static int F_167 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_4 -> V_29 =
! ( ( F_78 ( V_3 , 0x1 , 0 , 0xf84 , 0 ) >> 8 ) & 0x1 ) ;
V_34 -> V_145 . integer . V_145 [ 0 ] = V_4 -> V_29 ;
return 0 ;
}
static int F_168 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_35 ;
if ( V_4 -> V_7 != V_15 )
return 0 ;
V_4 -> V_29 = V_34 -> V_145 . integer . V_145 [ 0 ] ;
V_35 = ( 0x1 & ( F_78 ( V_3 , 0x1 , 0 , 0xf84 , 0 ) >> 8 ) )
== ! V_4 -> V_29 ;
if ( V_4 -> V_29 ) {
F_74 ( V_3 , 1 ) ;
F_71 ( V_3 ) ;
}
return V_35 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
V_56 = F_170 ( V_3 , & V_4 -> V_27 , NULL ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! V_4 -> V_27 . V_91 && ! V_4 -> V_27 . V_28 [ 0 ] )
return - V_201 ;
V_56 = F_135 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_137 ( V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_138 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_142 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_162 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
V_4 -> V_149 . V_200 = V_4 -> V_149 . V_150 * 2 ;
F_171 ( V_3 ) ;
F_172 ( V_3 ) ;
if ( V_4 -> V_40 . V_49 )
V_4 -> V_212 [ V_4 -> V_211 ++ ] = V_4 -> V_40 . V_49 ;
if ( V_4 -> V_152 && V_4 -> V_101 . V_72 ) {
V_56 = F_69 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_56 = F_79 ( V_3 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_4 -> V_328 [ 0 ] )
V_3 -> V_328 = V_4 -> V_328 ;
return 1 ;
}
static void F_173 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_149 . V_213 )
F_40 ( V_3 , V_4 -> V_27 . V_329 [ 0 ] , V_96 ) ;
if ( V_4 -> V_328 [ 0 ] )
F_40 ( V_3 , V_4 -> V_27 . V_329 [ 1 ] , V_96 ) ;
}
static void F_174 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_215 )
return;
F_7 ( V_3 , V_4 -> V_27 . V_330 , 0 ,
V_85 , V_120 ) ;
}
static void F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_107 * V_108 = & V_4 -> V_27 ;
unsigned int V_331 ;
int V_51 ;
if ( V_108 -> V_28 [ 0 ] && F_176 ( V_3 , V_108 -> V_28 [ 0 ] ) )
F_7 ( V_3 , V_108 -> V_28 [ 0 ] , 0 ,
V_332 ,
V_333 | V_262 | V_261 ) ;
if ( V_108 -> V_250 [ 0 ] )
V_331 = V_263 ;
else
V_331 = 0 ;
for ( V_51 = 0 ; V_51 < V_108 -> V_91 ; V_51 ++ ) {
if ( V_108 -> V_249 [ V_51 ] &&
F_176 ( V_3 , V_108 -> V_249 [ V_51 ] ) )
F_7 ( V_3 , V_108 -> V_249 [ V_51 ] , 0 ,
V_332 ,
V_333 | V_331 | V_261 ) ;
}
for ( V_51 = 0 ; V_51 < V_108 -> V_115 ; V_51 ++ ) {
if ( F_176 ( V_3 , V_108 -> V_116 [ V_51 ] . V_83 ) )
F_7 ( V_3 , V_108 -> V_116 [ V_51 ] . V_83 , 0 ,
V_332 ,
V_333 | V_261 ) ;
}
}
static int F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_334 ; V_51 ++ )
F_178 ( V_3 , V_4 -> V_335 [ V_51 ] ) ;
F_43 ( V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 ) ;
F_173 ( V_3 ) ;
F_174 ( V_3 ) ;
F_175 ( V_3 ) ;
F_68 ( V_3 ) ;
return 0 ;
}
static void F_179 ( struct V_336 * V_337 )
{
struct V_1 * V_4 = F_180 ( V_337 , struct V_1 ,
V_30 . V_337 ) ;
if ( V_4 -> V_7 != V_15 )
return;
if ( V_4 -> V_338
!= F_54 ( V_4 -> V_3 , V_4 -> V_27 . V_28 [ 0 ] ) ) {
V_4 -> V_338 ^= 1 ;
F_68 ( V_4 -> V_3 ) ;
}
F_6 ( V_4 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_60 , V_109 [ 8 ] ;
unsigned int type ;
int V_51 , V_339 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_113 ; V_51 ++ ) {
V_60 = V_4 -> V_114 [ V_51 ] ;
while ( V_60 ) {
type = F_51 ( F_32 ( V_3 , V_60 ) ) ;
if ( type == V_126 )
break;
V_339 = F_49 ( V_3 , V_60 , V_109 ,
F_50 ( V_109 ) ) ;
if ( V_339 <= 0 )
break;
if ( V_339 > 1 ) {
V_4 -> V_123 [ V_51 ] = V_60 ;
break;
}
V_60 = V_109 [ 0 ] ;
}
}
return 0 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x17 ;
F_163 ( V_3 , V_340 ) ;
F_163 ( V_3 , V_341 ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
if ( ! F_70 ( V_4 , & V_342 ) )
return - V_44 ;
if ( V_3 -> V_11 == 0x11061708 )
V_4 -> V_226 = & V_343 ;
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_344 ;
V_3 -> V_345 = V_346 ;
F_182 ( & V_4 -> V_30 , F_179 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x18 ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_3 -> V_345 = V_346 ;
return 0 ;
}
static void F_184 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_347 ;
unsigned int V_128 ;
int V_348 = 0 ;
if ( ( V_4 -> V_7 != V_20 ) &&
( V_3 -> V_11 != 0x11064397 ) )
V_348 = 1 ;
V_347 =
( F_78 ( V_3 , 0x17 , 0 , V_349 , 0x00 )
== ( ( V_4 -> V_7 == V_9 ) ? 5 : 0 ) ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x1a , & V_128 ) ;
F_52 ( V_3 , 0x1b , & V_128 ) ;
F_52 ( V_3 , 0x1e , & V_128 ) ;
if ( V_347 )
V_128 = V_137 ;
F_7 ( V_3 , 0x17 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x13 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x14 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x19 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x1b , & V_128 ) ;
F_7 ( V_3 , 0x18 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x11 , 0 , V_139 , V_128 ) ;
if ( V_348 ) {
V_128 = V_138 ;
F_52 ( V_3 , 0x22 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x1a , & V_128 ) ;
F_7 ( V_3 , 0x26 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x24 , 0 ,
V_139 , V_128 ) ;
} else if ( V_3 -> V_11 == 0x11064397 ) {
V_128 = V_138 ;
F_52 ( V_3 , 0x23 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x1a , & V_128 ) ;
F_7 ( V_3 , 0x27 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x25 , 0 ,
V_139 , V_128 ) ;
}
V_128 = V_138 ;
F_52 ( V_3 , 0x1c , & V_128 ) ;
F_52 ( V_3 , 0x1d , & V_128 ) ;
if ( V_348 )
F_52 ( V_3 , 0x23 , & V_128 ) ;
F_7 ( V_3 , 0x16 , 0 , V_139 ,
V_347 ? V_137 : V_128 ) ;
F_7 ( V_3 , 0x10 , 0 , V_139 , V_128 ) ;
if ( V_348 ) {
F_7 ( V_3 , 0x25 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x27 , 0 ,
V_139 , V_128 ) ;
} else if ( V_3 -> V_11 == 0x11064397 && V_4 -> V_99 )
F_7 ( V_3 , 0x25 , 0 ,
V_139 , V_128 ) ;
}
static int F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
if ( F_4 ( V_3 ) == V_8 )
return F_186 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x16 ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_3 -> V_345 = V_346 ;
V_4 -> F_15 = F_184 ;
return 0 ;
}
static void F_171 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_27 . V_350 ; V_51 ++ ) {
T_3 V_60 ;
int V_109 ;
V_60 = V_4 -> V_27 . V_329 [ V_51 ] ;
if ( ! V_60 )
continue;
V_109 = F_49 ( V_3 , V_60 , & V_60 , 1 ) ;
if ( V_109 < 1 )
continue;
if ( ! V_4 -> V_149 . V_213 )
V_4 -> V_149 . V_213 = V_60 ;
else {
V_4 -> V_328 [ 0 ] = V_60 ;
break;
}
}
}
static void F_172 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_351 ;
int V_51 , V_56 ;
if ( ! V_4 -> V_27 . V_330 )
return;
V_351 = V_3 -> V_303 ;
for ( V_51 = 0 ; V_51 < V_3 -> V_304 ; V_51 ++ , V_351 ++ ) {
unsigned int V_305 = F_32 ( V_3 , V_351 ) ;
if ( F_51 ( V_305 ) != V_306 )
continue;
if ( ! ( V_305 & V_307 ) )
continue;
if ( ! ( V_305 & V_308 ) )
continue;
V_56 = F_136 ( V_3 , V_351 ,
V_4 -> V_27 . V_330 ) ;
if ( V_56 >= 0 ) {
V_4 -> V_215 = V_351 ;
break;
}
}
}
static void F_187 ( struct V_2 * V_3 , T_3 V_83 ,
int V_352 , int V_353 , int V_354 )
{
F_188 ( V_3 , V_83 , V_58 ,
( V_352 << V_90 ) |
( V_353 << V_355 ) |
( V_354 << V_356 ) |
( 0 << V_357 ) ) ;
}
static int F_186 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x16 ;
F_187 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_358 ;
V_3 -> V_345 = V_346 ;
if ( F_4 ( V_3 ) == V_8 ) {
F_27 ( V_3 -> V_225 ) ;
V_3 -> V_225 = F_23 ( L_32 , V_5 ) ;
snprintf ( V_3 -> V_174 -> V_175 -> V_359 ,
sizeof( V_3 -> V_174 -> V_175 -> V_359 ) ,
L_33 , V_3 -> V_360 , V_3 -> V_225 ) ;
}
if ( V_3 -> V_11 == 0x11064397 ) {
F_27 ( V_3 -> V_225 ) ;
V_3 -> V_225 = F_23 ( L_34 , V_5 ) ;
snprintf ( V_3 -> V_174 -> V_175 -> V_359 ,
sizeof( V_3 -> V_174 -> V_175 -> V_359 ) ,
L_33 , V_3 -> V_360 , V_3 -> V_225 ) ;
}
V_4 -> F_15 = F_184 ;
return 0 ;
}
static void F_189 ( struct V_2 * V_3 )
{
int V_347 =
F_78 ( V_3 , 0x13 , 0 , V_349 , 0x00 ) == 3 ;
unsigned int V_128 ;
V_128 = V_138 ;
F_52 ( V_3 , 0x14 , & V_128 ) ;
F_52 ( V_3 , 0x15 , & V_128 ) ;
F_52 ( V_3 , 0x18 , & V_128 ) ;
if ( V_347 )
V_128 = V_137 ;
F_7 ( V_3 , 0x13 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x12 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x1f , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x20 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x17 , & V_128 ) ;
F_52 ( V_3 , 0x16 , & V_128 ) ;
F_7 ( V_3 , 0x1a , 0 , V_139 ,
V_347 ? V_137 : V_128 ) ;
F_7 ( V_3 , 0x10 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x1d , 0 , V_139 , V_128 ) ;
}
static int F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x1a ;
F_188 ( V_3 , 0x1A , V_58 ,
( 0x17 << V_90 ) |
( 0x17 << V_355 ) |
( 0x5 << V_356 ) |
( 1 << V_357 ) ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_361 ;
V_3 -> V_345 = V_346 ;
V_4 -> F_15 = F_189 ;
return 0 ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_347 ;
unsigned int V_128 ;
V_347 =
F_78 ( V_3 , 0x1e , 0 , V_349 , 0x00 ) == 5 ;
V_128 = V_138 ;
F_52 ( V_3 , 0x29 , & V_128 ) ;
F_52 ( V_3 , 0x2a , & V_128 ) ;
F_52 ( V_3 , 0x2b , & V_128 ) ;
if ( V_347 )
V_128 = V_137 ;
F_7 ( V_3 , 0x1e , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x1f , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x10 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x11 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x27 , & V_128 ) ;
F_7 ( V_3 , 0x1a , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0xb , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x26 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x2b , & V_128 ) ;
F_7 ( V_3 , 0xa , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x24 , & V_128 ) ;
if ( ! V_4 -> V_99 )
F_52 ( V_3 , 0x28 , & V_128 ) ;
F_7 ( V_3 , 0x8 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x21 , 0 , V_139 ,
V_347 ? V_137 : V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x25 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x2a , & V_128 ) ;
F_7 ( V_3 , 0x9 , 0 , V_139 , V_128 ) ;
if ( V_4 -> V_99 ) {
V_128 = V_138 ;
F_52 ( V_3 , 0x28 , & V_128 ) ;
F_7 ( V_3 , 0x1b , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x34 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0xc , 0 ,
V_139 , V_128 ) ;
}
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_51 , V_251 ;
T_3 V_109 [ 8 ] ;
T_3 V_60 ;
if ( ! V_4 -> V_77 )
return 0 ;
V_251 = F_49 ( V_3 , V_4 -> V_77 , V_109 ,
F_50 ( V_109 ) - 1 ) ;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ ) {
if ( F_51 ( F_32 ( V_3 , V_109 [ V_51 ] ) ) == V_269 )
return 0 ;
}
V_60 = V_3 -> V_303 ;
for ( V_51 = 0 ; V_51 < V_3 -> V_304 ; V_51 ++ , V_60 ++ ) {
unsigned int V_63 = F_32 ( V_3 , V_60 ) ;
if ( F_51 ( V_63 ) == V_269 &&
! ( V_63 & V_307 ) ) {
V_109 [ V_251 ++ ] = V_60 ;
return F_193 ( V_3 ,
V_4 -> V_77 ,
V_251 , V_109 ) ;
}
}
return 0 ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x21 ;
F_187 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_192 ( V_3 ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_362 ;
V_3 -> V_345 = V_346 ;
V_4 -> F_15 = F_191 ;
return 0 ;
}
static int F_195 ( struct V_31 * V_32 ,
struct V_140 * V_141 )
{
V_141 -> type = V_363 ;
V_141 -> V_144 = 1 ;
V_141 -> V_145 . integer . V_364 = 0 ;
V_141 -> V_145 . integer . V_365 = 1 ;
return 0 ;
}
static int F_196 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
int V_45 = 0 ;
V_45 = F_78 ( V_3 , 0x26 , 0 ,
V_349 , 0 ) ;
if ( V_45 != - 1 )
* V_34 -> V_145 . integer . V_145 = V_45 ;
return 0 ;
}
static int F_197 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_32 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_45 = * V_34 -> V_145 . integer . V_145 ;
F_7 ( V_3 , 0x26 , 0 ,
V_76 , V_45 ) ;
V_4 -> V_366 = V_45 ;
F_15 ( V_3 ) ;
return 1 ;
}
static void F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_347 ;
unsigned int V_128 ;
unsigned int V_367 , V_134 ;
V_347 =
( F_78 ( V_3 , 0x17 , 0 ,
V_349 , 0x00 ) == 5 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x1a , & V_128 ) ;
F_52 ( V_3 , 0x1b , & V_128 ) ;
F_52 ( V_3 , 0x1e , & V_128 ) ;
if ( V_347 )
V_128 = V_137 ;
F_7 ( V_3 , 0x17 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x13 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x1e , & V_128 ) ;
if ( V_4 -> V_366 )
F_52 ( V_3 , 0x22 , & V_128 ) ;
else
F_7 ( V_3 , 0x22 , 0 ,
V_139 , V_138 ) ;
F_7 ( V_3 , 0x26 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x14 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x19 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x1b , & V_128 ) ;
F_7 ( V_3 , 0x18 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x11 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x23 , & V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x1a , & V_128 ) ;
F_7 ( V_3 , 0x27 , 0 , V_139 , V_128 ) ;
if ( V_4 -> V_117 )
F_52 ( V_3 , 0x1e , & V_128 ) ;
F_7 ( V_3 , 0x25 , 0 , V_139 , V_128 ) ;
V_134 = F_54 ( V_3 , 0x1c ) ;
if ( V_134 )
V_367 = 0 ;
else {
V_134 = F_54 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_99 && V_134 )
V_367 = 0 ;
else
V_367 = 1 ;
}
V_128 = V_367 ? V_137 : V_138 ;
F_7 ( V_3 , 0x28 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x29 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x2a , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x1c , & V_128 ) ;
F_52 ( V_3 , 0x1d , & V_128 ) ;
if ( V_4 -> V_99 )
F_7 ( V_3 , 0x25 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x16 , 0 , V_139 ,
V_347 ? V_137 : V_128 ) ;
F_7 ( V_3 , 0x10 , 0 , V_139 ,
V_367 ? V_137 : V_128 ) ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x16 ;
F_187 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_368 ;
V_4 -> V_212 [ V_4 -> V_211 ] = V_369 ;
V_4 -> V_211 ++ ;
V_4 -> V_212 [ V_4 -> V_211 ++ ] = V_370 ;
V_3 -> V_345 = V_346 ;
V_4 -> F_15 = F_198 ;
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_347 ;
unsigned int V_128 ;
unsigned int V_134 ;
V_347 =
F_78 ( V_3 , 0x1e , 0 , V_349 , 0x00 ) == 3 ;
V_128 = V_138 ;
F_52 ( V_3 , 0x29 , & V_128 ) ;
F_52 ( V_3 , 0x2a , & V_128 ) ;
F_52 ( V_3 , 0x2b , & V_128 ) ;
V_128 = V_137 ;
F_7 ( V_3 , 0x1e , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x1f , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x10 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x11 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x8 , 0 , V_139 , V_128 ) ;
if ( V_4 -> V_7 == V_26 ) {
V_128 = V_138 ;
F_52 ( V_3 , 0x28 , & V_128 ) ;
F_7 ( V_3 , 0x18 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x38 , 0 ,
V_139 , V_128 ) ;
} else {
V_128 = V_138 ;
F_52 ( V_3 , 0x26 , & V_128 ) ;
F_7 ( V_3 , 0x1c , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x37 , 0 ,
V_139 , V_128 ) ;
}
if ( V_4 -> V_7 == V_26 ) {
V_128 = V_138 ;
F_52 ( V_3 , 0x25 , & V_128 ) ;
F_7 ( V_3 , 0x15 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x35 , 0 ,
V_139 , V_128 ) ;
} else {
V_128 = V_138 ;
F_52 ( V_3 , 0x25 , & V_128 ) ;
F_7 ( V_3 , 0x19 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x35 , 0 ,
V_139 , V_128 ) ;
}
if ( V_4 -> V_99 )
F_7 ( V_3 , 0x9 , 0 ,
V_139 , V_137 ) ;
V_134 = F_54 ( V_3 , 0x25 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x24 , & V_128 ) ;
V_128 = V_134 ? V_138 : V_137 ;
if ( V_4 -> V_7 == V_26 )
F_7 ( V_3 , 0x14 , 0 ,
V_139 , V_128 ) ;
else
F_7 ( V_3 , 0x18 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x34 , 0 , V_139 , V_128 ) ;
V_134 = F_54 ( V_3 , 0x26 ) ;
V_128 = V_134 ? V_138 : V_137 ;
if ( V_4 -> V_7 == V_26 ) {
F_7 ( V_3 , 0x33 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x1c , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x3c , 0 ,
V_139 , V_128 ) ;
} else {
F_7 ( V_3 , 0x31 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x17 , 0 ,
V_139 , V_128 ) ;
F_7 ( V_3 , 0x3b , 0 ,
V_139 , V_128 ) ;
}
if ( V_347 || ! F_13 ( V_3 ) )
F_7 ( V_3 , 0x21 , 0 ,
V_139 , V_137 ) ;
else
F_7 ( V_3 , 0x21 , 0 ,
V_139 , V_138 ) ;
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x21 ;
F_187 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_192 ( V_3 ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
if ( V_4 -> V_7 == V_26 )
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_371 ;
else
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_372 ;
V_3 -> V_345 = V_346 ;
V_4 -> F_15 = F_200 ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_347 =
F_78 ( V_3 , 0x13 , 0 , V_349 , 0x00 ) == 3 ;
unsigned int V_128 ;
unsigned int V_134 ;
V_347 =
F_78 ( V_3 , 0x1e , 0 , V_349 , 0x00 ) == 5 ;
V_128 = V_138 ;
F_52 ( V_3 , 0x29 , & V_128 ) ;
F_52 ( V_3 , 0x2a , & V_128 ) ;
F_52 ( V_3 , 0x2b , & V_128 ) ;
V_128 = V_137 ;
F_7 ( V_3 , 0x1e , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x1f , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x10 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x11 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x8 , 0 ,
V_139 , V_137 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x28 , & V_128 ) ;
F_7 ( V_3 , 0x18 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x38 , 0 , V_139 , V_128 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x25 , & V_128 ) ;
F_7 ( V_3 , 0x15 , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x35 , 0 , V_139 , V_128 ) ;
if ( V_4 -> V_99 )
F_7 ( V_3 , 0x9 , 0 ,
V_139 , V_137 ) ;
V_134 = F_54 ( V_3 , 0x25 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x24 , & V_128 ) ;
if ( V_134 ) {
F_7 ( V_3 , 0x14 , 0 ,
V_139 , V_138 ) ;
F_7 ( V_3 , 0x34 , 0 ,
V_139 , V_138 ) ;
} else {
F_7 ( V_3 , 0x14 , 0 ,
V_139 , V_137 ) ;
F_7 ( V_3 , 0x34 , 0 ,
V_139 , V_137 ) ;
}
V_134 = F_54 ( V_3 , 0x28 ) ;
V_128 = V_138 ;
F_52 ( V_3 , 0x31 , & V_128 ) ;
if ( V_134 ) {
F_7 ( V_3 , 0x1c , 0 ,
V_139 , V_138 ) ;
F_7 ( V_3 , 0x3c , 0 ,
V_139 , V_138 ) ;
F_7 ( V_3 , 0x3e , 0 ,
V_139 , V_138 ) ;
} else {
F_7 ( V_3 , 0x1c , 0 ,
V_139 , V_137 ) ;
F_7 ( V_3 , 0x3c , 0 ,
V_139 , V_137 ) ;
F_7 ( V_3 , 0x3e , 0 ,
V_139 , V_137 ) ;
}
V_128 = V_138 ;
F_52 ( V_3 , 0x33 , & V_128 ) ;
F_7 ( V_3 , 0x1d , 0 , V_139 , V_128 ) ;
F_7 ( V_3 , 0x3d , 0 , V_139 , V_128 ) ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_56 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
V_4 -> V_77 = 0x21 ;
F_187 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_187 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_192 ( V_3 ) ;
V_56 = F_169 ( V_3 ) ;
if ( V_56 < 0 ) {
F_117 ( V_3 ) ;
return V_56 ;
}
V_4 -> V_335 [ V_4 -> V_334 ++ ] = V_373 ;
V_3 -> V_345 = V_346 ;
V_4 -> F_15 = F_202 ;
return 0 ;
}
static int T_5 F_204 ( void )
{
return F_205 ( & V_374 ) ;
}
static void T_6 F_206 ( void )
{
F_207 ( & V_374 ) ;
}
