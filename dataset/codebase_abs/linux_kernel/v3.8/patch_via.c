static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return NULL ;
F_3 ( & V_4 -> V_6 , sizeof( struct V_7 ) , 32 ) ;
F_4 ( & V_4 -> V_8 ) ;
V_3 -> V_4 = V_4 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_9 = F_5 ( V_3 ) ;
if ( V_4 -> V_9 == V_10 )
V_4 -> V_9 = V_11 ;
F_6 ( & V_4 -> V_12 ) ;
return V_4 ;
}
static enum V_13 F_5 ( struct V_2 * V_3 )
{
T_1 V_14 = V_3 -> V_14 ;
T_2 V_15 = V_14 >> 16 ;
T_2 V_16 = V_14 & 0xffff ;
enum V_13 V_9 ;
if ( V_15 != 0x1106 )
V_9 = V_17 ;
else if ( V_16 >= 0x1708 && V_16 <= 0x170b )
V_9 = V_18 ;
else if ( V_16 >= 0xe710 && V_16 <= 0xe713 )
V_9 = V_19 ;
else if ( V_16 >= 0xe714 && V_16 <= 0xe717 )
V_9 = V_20 ;
else if ( V_16 >= 0xe720 && V_16 <= 0xe723 ) {
V_9 = V_21 ;
if ( F_7 ( V_3 , 0x16 , V_22 ) == 0x7 )
V_9 = V_10 ;
} else if ( V_16 >= 0xe724 && V_16 <= 0xe727 )
V_9 = V_23 ;
else if ( ( V_16 & 0xfff ) == 0x397
&& ( V_16 >> 12 ) < 8 )
V_9 = V_11 ;
else if ( ( V_16 & 0xfff ) == 0x398
&& ( V_16 >> 12 ) < 8 )
V_9 = V_24 ;
else if ( ( V_16 & 0xfff ) == 0x428
&& ( V_16 >> 12 ) < 8 )
V_9 = V_25 ;
else if ( V_16 == 0x0433 || V_16 == 0xa721 )
V_9 = V_26 ;
else if ( V_16 == 0x0441 || V_16 == 0x4441 )
V_9 = V_25 ;
else if ( V_16 == 0x0438 || V_16 == 0x4438 )
V_9 = V_27 ;
else if ( V_16 == 0x0448 )
V_9 = V_28 ;
else if ( V_16 == 0x0440 )
V_9 = V_11 ;
else if ( ( V_16 & 0xfff ) == 0x446 )
V_9 = V_29 ;
else if ( V_16 == 0x4760 )
V_9 = V_30 ;
else if ( V_16 == 0x4761 || V_16 == 0x4762 )
V_9 = V_31 ;
else
V_9 = V_17 ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_4 )
{
if ( V_4 -> V_9 != V_18 || V_4 -> V_32 . V_33 [ 0 ] == 0 )
return;
if ( V_4 -> V_34 ) {
F_9 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
F_10 ( & V_4 -> V_35 ) ;
V_4 -> V_34 = 0 ;
}
}
static void F_11 ( struct V_1 * V_4 )
{
if ( V_4 -> V_9 != V_18 || V_4 -> V_32 . V_33 [ 0 ] == 0 )
return;
if ( V_4 -> V_36 &&
( V_4 -> V_37 || F_12 ( V_4 -> V_3 ) ) ) {
if ( ! V_4 -> V_34 ) {
F_9 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_13 ( & V_4 -> V_35 ,
F_14 ( 100 ) ) ;
V_4 -> V_34 = 1 ;
}
} else if ( ! F_12 ( V_4 -> V_3 ) )
F_8 ( V_4 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> F_15 )
V_4 -> F_15 ( V_3 ) ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_42 = F_17 ( V_39 , V_41 ) ;
struct V_2 * V_3 = F_18 ( V_39 ) ;
F_15 ( V_3 ) ;
F_19 ( F_18 ( V_39 ) ) ;
F_11 ( V_3 -> V_4 ) ;
return V_42 ;
}
static struct V_7 * F_20 ( struct V_1 * V_4 ,
const struct V_7 * V_43 ,
const char * V_44 )
{
struct V_7 * V_45 ;
V_45 = F_21 ( & V_4 -> V_6 ) ;
if ( ! V_45 )
return NULL ;
* V_45 = * V_43 ;
if ( ! V_44 )
V_44 = V_43 -> V_44 ;
if ( V_44 ) {
V_45 -> V_44 = F_22 ( V_44 , V_5 ) ;
if ( ! V_45 -> V_44 )
return NULL ;
}
return V_45 ;
}
static int F_23 ( struct V_1 * V_4 , int type , const char * V_44 ,
int V_46 , unsigned long V_47 )
{
struct V_7 * V_45 ;
V_45 = F_20 ( V_4 , & V_48 [ type ] , V_44 ) ;
if ( ! V_45 )
return - V_49 ;
V_45 -> V_50 = V_46 ;
if ( F_24 ( V_47 ) )
V_45 -> V_51 = V_52 ;
V_45 -> V_53 = V_47 ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_6 . V_54 ) {
struct V_7 * V_55 = V_4 -> V_6 . V_54 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_6 . V_57 ; V_56 ++ )
F_26 ( V_55 [ V_56 ] . V_44 ) ;
}
F_27 ( & V_4 -> V_6 ) ;
}
static int F_28 ( struct V_1 * V_4 , const char * V_58 ,
int V_59 , int V_46 , int V_60 )
{
char V_44 [ 32 ] ;
int V_61 ;
sprintf ( V_44 , L_1 , V_58 ) ;
V_61 = F_23 ( V_4 , V_62 , V_44 , V_59 ,
F_29 ( V_60 , 3 , V_46 , V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
sprintf ( V_44 , L_2 , V_58 ) ;
V_61 = F_23 ( V_4 , V_64 , V_44 , V_59 ,
F_29 ( V_60 , 3 , V_46 , V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static bool F_30 ( struct V_2 * V_3 , T_3 V_65 , int V_66 ,
unsigned int V_67 )
{
unsigned int V_68 ;
if ( ! V_65 )
return false ;
V_68 = F_31 ( V_3 , V_65 ) ;
if ( V_66 == V_63 )
V_68 &= V_69 ;
else
V_68 &= V_70 ;
if ( ! V_68 )
return false ;
if ( F_32 ( V_3 , V_65 , V_66 ) & V_67 )
return true ;
return false ;
}
static void F_33 ( struct V_2 * V_3 , struct V_71 * V_72 ,
T_3 V_60 , int V_46 , bool V_73 )
{
int V_56 , V_74 , V_47 ;
if ( ! V_72 )
return;
V_74 = F_34 ( V_3 , V_60 ) ;
for ( V_56 = 0 ; V_56 < V_74 ; V_56 ++ ) {
if ( V_56 == V_46 )
V_47 = F_35 ( V_56 ) ;
else
V_47 = F_36 ( V_56 ) ;
F_9 ( V_3 , V_60 , 0 ,
V_75 , V_47 ) ;
}
}
static void F_37 ( struct V_2 * V_3 , struct V_71 * V_72 ,
bool V_73 , bool V_76 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_72 -> V_77 ; V_56 ++ ) {
T_3 V_78 , V_79 ;
int V_46 = V_72 -> V_46 [ V_56 ] ;
V_78 = V_72 -> V_72 [ V_56 ] ;
if ( V_56 < V_72 -> V_77 - 1 )
V_79 = V_72 -> V_72 [ V_56 + 1 ] ;
else
V_79 = 0 ;
if ( V_73 && V_72 -> V_80 [ V_56 ] )
F_9 ( V_3 , V_79 , 0 ,
V_81 , V_46 ) ;
if ( ! V_76 && ( V_79 == V_4 -> V_82 ) )
continue;
if ( F_38 ( V_3 , V_79 , V_63 ) )
F_33 ( V_3 , V_72 , V_79 , V_46 , V_73 ) ;
if ( ! V_76 && ( V_78 == V_72 -> V_83 || V_78 == V_72 -> V_84 ) )
continue;
if ( F_38 ( V_3 , V_78 , V_85 ) ) {
int V_47 = V_73 ? V_86 : V_87 ;
F_9 ( V_3 , V_78 , 0 ,
V_75 , V_47 ) ;
}
}
}
static void F_39 ( struct V_2 * V_3 , T_3 V_88 ,
int V_89 )
{
if ( ! V_88 )
return;
F_40 ( V_3 , V_88 , V_89 ) ;
if ( F_41 ( V_3 , V_88 ) & V_90 )
F_9 ( V_3 , V_88 , 0 ,
V_91 , 0x02 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_71 * V_72 , int V_89 )
{
unsigned int V_68 ;
T_3 V_88 ;
if ( ! V_72 -> V_77 )
return;
V_88 = V_72 -> V_72 [ V_72 -> V_77 - 1 ] ;
F_39 ( V_3 , V_88 , V_89 ) ;
if ( F_31 ( V_3 , V_88 ) & V_70 )
V_68 = F_32 ( V_3 , V_88 , V_85 ) ;
else
V_68 = 0 ;
if ( V_68 & V_92 ) {
unsigned int V_47 ;
V_47 = ( V_68 & V_93 ) >> V_94 ;
F_9 ( V_3 , V_88 , 0 , V_75 ,
V_87 | V_47 ) ;
}
F_37 ( V_3 , V_72 , true , true ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_71 * V_72 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_32 . V_95 + V_4 -> V_96 ; V_56 ++ ) {
V_72 = & V_4 -> V_97 [ V_56 ] ;
if ( ! V_56 && V_4 -> V_98 && V_4 -> V_99 . V_77 )
V_72 = & V_4 -> V_99 ;
F_42 ( V_3 , V_72 , V_100 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_101 = V_4 -> V_102 ;
if ( V_4 -> V_103 ) {
F_37 ( V_3 , & V_4 -> V_104 , false , false ) ;
F_37 ( V_3 , & V_4 -> V_105 , false , false ) ;
if ( V_101 )
F_37 ( V_3 , & V_4 -> V_97 [ V_101 ] ,
false , false ) ;
} else if ( V_4 -> V_98 || ! V_4 -> V_104 . V_77 ) {
F_37 ( V_3 , & V_4 -> V_106 , false , false ) ;
F_37 ( V_3 , & V_4 -> V_104 , false , false ) ;
} else {
F_37 ( V_3 , & V_4 -> V_106 , false , false ) ;
F_37 ( V_3 , & V_4 -> V_105 , false , false ) ;
}
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_104 . V_77 ) {
F_42 ( V_3 , & V_4 -> V_105 , V_107 ) ;
return;
}
F_44 ( V_3 ) ;
if ( V_4 -> V_103 )
F_42 ( V_3 , & V_4 -> V_106 , V_107 ) ;
else if ( V_4 -> V_98 )
F_42 ( V_3 , & V_4 -> V_105 , V_107 ) ;
else
F_42 ( V_3 , & V_4 -> V_104 , V_107 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_32 . V_108 )
return;
if ( ! V_4 -> V_109 . V_77 ) {
F_42 ( V_3 , & V_4 -> V_110 , V_100 ) ;
return;
}
if ( ! V_4 -> V_98 ) {
F_37 ( V_3 , & V_4 -> V_110 ,
false , false ) ;
F_42 ( V_3 , & V_4 -> V_109 , V_100 ) ;
} else {
F_37 ( V_3 , & V_4 -> V_109 , false , false ) ;
F_42 ( V_3 , & V_4 -> V_110 , V_100 ) ;
}
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_111 * V_112 = & V_4 -> V_32 ;
T_3 V_113 [ V_114 ] ;
unsigned int V_115 ;
int V_56 , V_116 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_117 ; V_56 ++ ) {
T_3 V_65 = V_4 -> V_118 [ V_56 ] ;
if ( ! ( F_31 ( V_3 , V_65 ) & V_69 ) ||
! ( F_32 ( V_3 , V_65 , V_63 ) & V_92 ) )
continue;
F_9 ( V_3 , V_4 -> V_118 [ V_56 ] , 0 ,
V_75 ,
F_35 ( 0 ) ) ;
}
for ( V_56 = 0 ; V_56 < V_112 -> V_119 ; V_56 ++ ) {
T_3 V_65 = V_112 -> V_120 [ V_56 ] . V_88 ;
if ( V_4 -> V_121 && F_48 ( V_3 , V_65 ) )
V_115 = V_100 ;
else {
V_115 = V_122 ;
if ( V_112 -> V_120 [ V_56 ] . type == V_123 )
V_115 |= F_49 ( V_3 , V_65 ) ;
}
F_40 ( V_3 , V_65 , V_115 ) ;
}
for ( V_56 = 0 ; V_56 < V_4 -> V_117 ; V_56 ++ ) {
int V_124 = V_4 -> V_120 [ V_4 -> V_125 [ V_56 ] ] . V_124 ;
if ( V_56 > 0 && ! V_4 -> V_126 [ V_56 ] )
break;
if ( V_4 -> V_126 [ V_124 ] ) {
int V_127 = V_4 -> V_120 [ V_4 -> V_125 [ V_56 ] ] . V_127 ;
F_9 ( V_3 , V_4 -> V_126 [ V_124 ] , 0 ,
V_81 ,
V_127 ) ;
}
if ( V_4 -> V_128 )
break;
}
if ( ! V_4 -> V_82 )
return;
V_116 = F_50 ( V_3 , V_4 -> V_82 , V_113 ,
F_51 ( V_113 ) ) ;
for ( V_56 = 0 ; V_56 < V_116 ; V_56 ++ ) {
unsigned int V_68 = F_31 ( V_3 , V_113 [ V_56 ] ) ;
if ( F_52 ( V_68 ) == V_129 )
F_9 ( V_3 , V_4 -> V_82 , 0 ,
V_75 ,
F_36 ( V_56 ) ) ;
}
}
static void F_53 ( struct V_2 * V_3 , T_3 V_65 ,
unsigned int V_130 )
{
if ( F_54 ( V_3 , V_65 , 0 ,
V_131 , 0 ) == V_130 )
return;
F_9 ( V_3 , V_65 , 0 , V_132 , V_130 ) ;
}
static void F_55 ( struct V_2 * V_3 , T_3 V_65 ,
unsigned int V_130 , unsigned int V_50 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_133 ;
if ( F_54 ( V_3 , V_65 , 0 ,
V_131 , 0 ) == V_130 )
return;
V_133 = F_54 ( V_3 , V_65 , 0 , V_134 , 0 ) ;
if ( V_133 && ( V_4 -> V_135 [ V_50 ] != V_133 ) )
V_4 -> V_135 [ V_50 ] = V_133 ;
F_9 ( V_3 , V_65 , 0 , V_132 , V_130 ) ;
if ( V_130 == V_136 ) {
V_133 = F_54 ( V_3 , V_65 , 0 , V_134 , 0 ) ;
if ( ! V_133 && ( V_4 -> V_135 [ V_50 ] != V_133 ) )
F_9 ( V_3 , V_65 , 0 ,
V_137 ,
V_4 -> V_135 [ V_50 ] ) ;
}
}
static void F_56 ( struct V_2 * V_3 , T_3 V_65 ,
unsigned int * V_138 )
{
unsigned V_130 ;
unsigned V_139 = F_57 ( V_3 , V_65 ) ;
unsigned V_140 = ( V_139 & V_141 )
>> V_142
& V_143 ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned V_144 = 0 ;
V_140 |= V_4 -> V_145 ;
if ( ! V_140 )
V_144 = F_58 ( V_3 , V_65 ) ;
if ( ( V_4 -> V_121 && F_48 ( V_3 , V_65 ) )
|| ( ( V_140 || V_144 )
&& F_59 ( V_139 ) != V_146 ) ) {
* V_138 = V_136 ;
V_130 = V_136 ;
} else
V_130 = V_147 ;
F_53 ( V_3 , V_65 , V_130 ) ;
}
static int F_60 ( struct V_38 * V_39 ,
struct V_148 * V_149 )
{
return F_61 ( V_39 , V_149 ) ;
}
static int F_62 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_41 -> V_150 . V_151 . V_152 [ 0 ] = ! V_4 -> V_145 ;
return 0 ;
}
static int F_63 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_47 = ! V_41 -> V_150 . V_151 . V_152 [ 0 ] ;
if ( V_47 == V_4 -> V_145 )
return 0 ;
V_4 -> V_145 = V_47 ;
F_15 ( V_3 ) ;
F_19 ( V_3 ) ;
return 1 ;
}
static int F_64 ( struct V_38 * V_39 ,
struct V_148 * V_149 )
{
static const char * const V_153 [] = { L_3 , L_4 } ;
V_149 -> type = V_154 ;
V_149 -> V_155 = 1 ;
V_149 -> V_150 . V_151 . V_156 = 2 ;
if ( V_149 -> V_150 . V_151 . V_152 >= 2 )
V_149 -> V_150 . V_151 . V_152 = 1 ;
strcpy ( V_149 -> V_150 . V_151 . V_44 ,
V_153 [ V_149 -> V_150 . V_151 . V_152 ] ) ;
return 0 ;
}
static int F_65 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_41 -> V_150 . V_151 . V_152 [ 0 ] = V_4 -> V_103 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_4 )
{
const struct V_111 * V_112 = & V_4 -> V_32 ;
V_4 -> V_157 . V_158 = V_112 -> V_95 + V_4 -> V_96 ;
V_4 -> V_157 . V_159 = 0 ;
if ( ! V_4 -> V_103 ) {
if ( ! V_4 -> V_102 )
V_4 -> V_157 . V_159 = V_4 -> V_160 ;
} else {
if ( V_4 -> V_102 )
V_4 -> V_157 . V_158 = V_112 -> V_95 - 1 ;
}
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_101 = V_4 -> V_102 ;
T_3 V_161 , V_162 ;
if ( ! V_4 -> V_163 )
return;
V_161 = V_101 ? V_4 -> V_157 . V_164 [ V_101 ] : 0 ;
V_162 = V_4 -> V_160 ;
if ( V_4 -> V_103 ) {
if ( V_4 -> V_37 & V_165 ) {
F_68 ( V_3 , V_162 , 1 ) ;
F_68 ( V_3 , V_161 , 1 ) ;
}
if ( V_4 -> V_37 & V_166 )
F_69 ( V_3 , V_162 ,
V_4 -> V_167 , 0 ,
V_4 -> V_168 ) ;
} else {
if ( V_4 -> V_37 & V_166 )
F_68 ( V_3 , V_162 , 1 ) ;
if ( V_4 -> V_37 & V_165 ) {
T_3 V_169 ;
int V_170 ;
if ( V_161 ) {
V_169 = V_161 ;
V_170 = V_101 * 2 ;
} else {
V_169 = V_162 ;
V_170 = 0 ;
}
F_69 ( V_3 , V_169 ,
V_4 -> V_171 , V_170 ,
V_4 -> V_172 ) ;
}
}
F_66 ( V_4 ) ;
}
static int F_70 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_173 , V_101 ;
F_71 ( & V_4 -> V_8 ) ;
V_173 = ! ! V_41 -> V_150 . V_151 . V_152 [ 0 ] ;
if ( V_4 -> V_103 == V_173 ) {
F_72 ( & V_4 -> V_8 ) ;
return 0 ;
}
V_4 -> V_103 = V_173 ;
V_101 = V_4 -> V_102 ;
F_44 ( V_3 ) ;
if ( V_173 )
F_37 ( V_3 , & V_4 -> V_106 , true , false ) ;
else {
if ( V_101 )
F_37 ( V_3 , & V_4 -> V_97 [ V_101 ] ,
true , false ) ;
if ( V_4 -> V_98 || ! V_4 -> V_104 . V_77 )
F_37 ( V_3 , & V_4 -> V_105 ,
true , false ) ;
else
F_37 ( V_3 , & V_4 -> V_104 ,
true , false ) ;
}
F_67 ( V_3 ) ;
F_72 ( & V_4 -> V_8 ) ;
F_15 ( V_3 ) ;
F_73 ( V_3 ) ;
return 1 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_7 * V_45 ;
T_3 V_65 ;
V_65 = V_4 -> V_32 . V_33 [ 0 ] ;
V_45 = F_75 ( V_4 , & V_174 ) ;
if ( V_45 == NULL )
return - V_49 ;
V_45 -> V_51 = V_175 | V_65 ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_96 ; V_56 ++ ) {
struct V_38 * V_115 ;
struct V_176 V_177 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_177 . V_178 = V_179 ;
sprintf ( V_177 . V_44 , L_1 , V_4 -> V_180 [ V_56 ] ) ;
V_115 = F_77 ( V_3 , V_177 . V_44 ) ;
if ( V_115 )
F_78 ( V_3 -> V_181 -> V_182 ,
V_183 ,
& V_115 -> V_177 ) ;
}
}
static void F_79 ( struct V_2 * V_3 , int V_184 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_47 = V_184 ? V_185 : V_186 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_96 ; V_56 ++ ) {
if ( V_4 -> V_187 [ V_56 ] < 0 )
continue;
F_80 ( V_3 , V_4 -> V_82 ,
V_63 , V_4 -> V_187 [ V_56 ] ,
V_185 , V_47 ) ;
}
}
static bool F_48 ( struct V_2 * V_3 , T_3 V_88 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_96 ; V_56 ++ )
if ( V_4 -> V_188 [ V_56 ] == V_88 )
return true ;
return false ;
}
static int F_81 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
* V_41 -> V_150 . integer . V_150 = V_4 -> V_121 ;
return 0 ;
}
static int F_82 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_189 = * V_41 -> V_150 . integer . V_150
? V_190 : V_191 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_96 ; V_56 ++ ) {
T_3 V_65 = V_4 -> V_188 [ V_56 ] ;
unsigned int V_130 ;
V_130 = F_54 ( V_3 , V_65 , 0 ,
V_192 , 0 ) ;
V_130 &= ~ ( V_191 | V_190 ) ;
V_130 |= V_189 ;
F_40 ( V_3 , V_65 , V_130 ) ;
if ( V_189 == V_190 ) {
F_79 ( V_3 , 1 ) ;
F_76 ( V_3 ) ;
}
}
V_4 -> V_121 = * V_41 -> V_150 . integer . V_150 ;
F_15 ( V_3 ) ;
return 1 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_96 )
return 0 ;
if ( ! F_75 ( V_4 , & V_193 ) )
return - V_49 ;
return 0 ;
}
static bool F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_194 * V_195 ;
int V_56 , V_170 , V_196 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_197 ; V_56 ++ ) {
V_195 = & V_4 -> V_198 [ V_56 ] ;
for ( V_170 = 0 ; V_170 < 2 ; V_170 ++ ) {
V_196 = F_85 ( V_3 , V_195 -> V_65 , V_170 , V_195 -> V_66 ,
V_195 -> V_46 ) ;
if ( ! ( V_196 & V_185 ) && V_196 > 0 )
return false ;
}
}
return true ;
}
static void F_86 ( struct V_2 * V_3 , bool V_76 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_73 ;
unsigned int V_199 , V_130 ;
if ( V_4 -> V_145 )
V_73 = false ;
else
V_73 = F_84 ( V_3 ) && ! V_4 -> V_163 ;
if ( V_73 == V_4 -> V_200 && ! V_76 )
return;
V_4 -> V_200 = V_73 ;
switch ( V_4 -> V_9 ) {
case V_21 :
case V_23 :
V_199 = 0xf70 ;
V_130 = V_73 ? 0x02 : 0x00 ;
break;
case V_11 :
case V_25 :
case V_26 :
V_199 = 0xf73 ;
V_130 = V_73 ? 0x51 : 0xe1 ;
break;
case V_24 :
V_199 = 0xf73 ;
V_130 = V_73 ? 0x01 : 0x1d ;
break;
case V_27 :
case V_28 :
case V_29 :
V_199 = 0xf93 ;
V_130 = V_73 ? 0x00 : 0xe0 ;
break;
case V_30 :
case V_31 :
V_199 = 0xf82 ;
V_130 = V_73 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_9 ( V_3 , V_3 -> V_201 , 0 , V_199 , V_130 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
return F_86 ( V_3 , false ) ;
}
static void F_87 ( struct V_2 * V_3 , int V_202 , bool V_203 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_203 )
V_4 -> V_163 |= V_202 ;
else
V_4 -> V_163 &= ~ V_202 ;
F_19 ( V_3 ) ;
}
static int F_88 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_111 * V_112 = & V_4 -> V_32 ;
int V_61 ;
V_4 -> V_157 . V_158 = V_112 -> V_95 + V_4 -> V_96 ;
V_4 -> V_157 . V_208 = V_4 -> V_157 . V_158 * 2 ;
F_87 ( V_3 , V_165 , true ) ;
V_61 = F_89 ( V_3 , & V_4 -> V_157 , V_207 ,
V_205 ) ;
if ( V_61 < 0 ) {
F_87 ( V_3 , V_165 , false ) ;
return V_61 ;
}
return 0 ;
}
static int F_90 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
F_87 ( V_3 , V_165 , false ) ;
return 0 ;
}
static int F_91 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_92 ( ! V_4 -> V_160 ) )
return - V_209 ;
F_87 ( V_3 , V_166 , true ) ;
return 0 ;
}
static int F_93 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
F_87 ( V_3 , V_166 , false ) ;
return 0 ;
}
static int F_94 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
unsigned int V_210 ,
unsigned int V_133 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_71 ( & V_4 -> V_8 ) ;
F_66 ( V_4 ) ;
F_95 ( V_3 , & V_4 -> V_157 , V_210 ,
V_133 , V_207 ) ;
V_4 -> V_37 |= V_165 ;
V_4 -> V_171 = V_210 ;
V_4 -> V_172 = V_133 ;
F_72 ( & V_4 -> V_8 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_96 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
unsigned int V_210 ,
unsigned int V_133 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_71 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_103 )
F_69 ( V_3 , V_4 -> V_160 ,
V_210 , 0 , V_133 ) ;
V_4 -> V_37 |= V_166 ;
V_4 -> V_167 = V_210 ;
V_4 -> V_168 = V_133 ;
F_72 ( & V_4 -> V_8 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_97 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_71 ( & V_4 -> V_8 ) ;
F_98 ( V_3 , & V_4 -> V_157 ) ;
V_4 -> V_37 &= ~ V_165 ;
F_72 ( & V_4 -> V_8 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_99 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_71 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_103 )
F_69 ( V_3 , V_4 -> V_160 , 0 , 0 , 0 ) ;
V_4 -> V_37 &= ~ V_166 ;
F_72 ( & V_4 -> V_8 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_100 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_101 ( V_3 , & V_4 -> V_157 ) ;
}
static int F_102 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_103 ( V_3 , & V_4 -> V_157 ) ;
}
static int F_104 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
unsigned int V_210 ,
unsigned int V_133 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_105 ( V_3 , & V_4 -> V_157 ,
V_210 , V_133 , V_207 ) ;
}
static int F_106 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_107 ( V_3 , & V_4 -> V_157 ) ;
return 0 ;
}
static int F_108 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
unsigned int V_210 ,
unsigned int V_133 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_69 ( V_3 , V_4 -> V_118 [ V_207 -> V_211 ] ,
V_210 , 0 , V_133 ) ;
return 0 ;
}
static int F_109 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_110 ( V_3 , V_4 -> V_118 [ V_207 -> V_211 ] ) ;
return 0 ;
}
static int F_111 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
unsigned int V_210 ,
unsigned int V_133 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_124 = V_4 -> V_120 [ V_4 -> V_125 [ 0 ] ] . V_124 ;
F_71 ( & V_4 -> V_8 ) ;
V_4 -> V_212 = V_4 -> V_118 [ V_124 ] ;
V_4 -> V_213 = V_210 ;
V_4 -> V_214 = V_133 ;
F_69 ( V_3 , V_4 -> V_212 , V_210 , 0 , V_133 ) ;
F_72 ( & V_4 -> V_8 ) ;
return 0 ;
}
static int F_112 ( struct V_204 * V_205 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_71 ( & V_4 -> V_8 ) ;
F_110 ( V_3 , V_4 -> V_212 ) ;
V_4 -> V_212 = 0 ;
F_72 ( & V_4 -> V_8 ) ;
return 0 ;
}
static bool F_113 ( struct V_2 * V_3 , int V_173 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_124 = V_4 -> V_120 [ V_173 ] . V_124 ;
T_3 V_215 = V_4 -> V_118 [ V_124 ] ;
bool V_216 = false ;
F_71 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_212 && V_4 -> V_212 != V_215 ) {
F_68 ( V_3 , V_4 -> V_212 , 1 ) ;
V_4 -> V_212 = V_215 ;
F_69 ( V_3 , V_215 ,
V_4 -> V_213 , 0 ,
V_4 -> V_214 ) ;
V_216 = true ;
}
F_72 ( & V_4 -> V_8 ) ;
return V_216 ;
}
static int F_114 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_38 * V_55 ;
int V_61 , V_56 ;
V_4 -> V_145 = 1 ;
if ( V_4 -> F_15 )
if ( ! F_75 ( V_4 , & V_217 ) )
return - V_49 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_218 ; V_56 ++ ) {
V_61 = F_115 ( V_3 , V_4 -> V_219 [ V_56 ] ) ;
if ( V_61 < 0 )
return V_61 ;
}
if ( V_4 -> V_157 . V_220 ) {
V_61 = F_116 ( V_3 ,
V_4 -> V_157 . V_220 ,
V_4 -> V_157 . V_220 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_117 ( V_3 ,
& V_4 -> V_157 ) ;
if ( V_61 < 0 )
return V_61 ;
V_4 -> V_157 . V_221 = 1 ;
}
if ( V_4 -> V_222 ) {
V_61 = F_118 ( V_3 , V_4 -> V_222 ) ;
if ( V_61 < 0 )
return V_61 ;
}
if ( ! F_77 ( V_3 , L_5 ) ) {
unsigned int V_223 [ 4 ] ;
F_119 ( V_3 , V_4 -> V_157 . V_164 [ 0 ] ,
V_85 , V_223 ) ;
V_61 = F_120 ( V_3 , L_5 ,
V_223 , V_224 ,
L_6 ) ;
if ( V_61 < 0 )
return V_61 ;
}
if ( ! F_77 ( V_3 , L_7 ) ) {
V_61 = F_120 ( V_3 , L_7 ,
NULL , V_224 ,
L_8 ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_55 = F_77 ( V_3 , L_9 ) ;
for ( V_56 = 0 ; V_55 && V_56 < V_55 -> V_155 ; V_56 ++ ) {
if ( ! V_4 -> V_126 [ V_56 ] )
continue;
V_61 = F_121 ( V_3 , V_55 , V_56 , V_4 -> V_126 [ V_56 ] ) ;
if ( V_61 < 0 )
return V_61 ;
}
F_25 ( V_3 ) ;
V_61 = F_122 ( V_3 , & V_4 -> V_32 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_225 * V_226 = V_4 -> V_227 ;
V_3 -> V_228 = 0 ;
V_3 -> V_229 = V_226 ;
if ( V_4 -> V_157 . V_158 || V_4 -> V_117 ) {
snprintf ( V_4 -> V_230 ,
sizeof( V_4 -> V_230 ) ,
L_10 , V_3 -> V_231 ) ;
V_226 -> V_44 = V_4 -> V_230 ;
if ( V_4 -> V_157 . V_158 ) {
if ( ! V_4 -> V_232 )
V_4 -> V_232 =
& V_233 ;
V_226 -> V_234 [ V_235 ] =
* V_4 -> V_232 ;
V_226 -> V_234 [ V_235 ] . V_65 =
V_4 -> V_157 . V_164 [ 0 ] ;
V_226 -> V_234 [ V_235 ] . V_236 =
V_4 -> V_157 . V_208 ;
if ( V_4 -> V_32 . V_237 == V_238
&& V_4 -> V_32 . V_95 == 2 )
V_226 -> V_234 [ V_235 ] . V_239 =
V_240 ;
}
if ( ! V_4 -> V_241 ) {
if ( V_4 -> V_128 )
V_4 -> V_241 =
& V_242 ;
else
V_4 -> V_241 =
& V_243 ;
}
if ( V_4 -> V_117 ) {
V_226 -> V_234 [ V_244 ] =
* V_4 -> V_241 ;
V_226 -> V_234 [ V_244 ] . V_65 =
V_4 -> V_118 [ 0 ] ;
if ( ! V_4 -> V_128 )
V_226 -> V_234 [ V_244 ] . V_245 =
V_4 -> V_117 ;
}
V_3 -> V_228 ++ ;
V_226 ++ ;
}
if ( V_4 -> V_157 . V_220 || V_4 -> V_222 ) {
snprintf ( V_4 -> V_246 ,
sizeof( V_4 -> V_246 ) ,
L_11 , V_3 -> V_231 ) ;
V_226 -> V_44 = V_4 -> V_246 ;
V_226 -> V_247 = V_248 ;
if ( V_4 -> V_157 . V_220 ) {
if ( ! V_4 -> V_249 )
V_4 -> V_249 =
& V_250 ;
V_226 -> V_234 [ V_235 ] =
* V_4 -> V_249 ;
V_226 -> V_234 [ V_235 ] . V_65 =
V_4 -> V_157 . V_220 ;
}
if ( V_4 -> V_222 ) {
if ( ! V_4 -> V_251 )
V_4 -> V_251 =
& V_252 ;
V_226 -> V_234 [ V_244 ] =
* V_4 -> V_251 ;
V_226 -> V_234 [ V_244 ] . V_65 =
V_4 -> V_222 ;
}
V_3 -> V_228 ++ ;
V_226 ++ ;
}
if ( V_4 -> V_160 ) {
snprintf ( V_4 -> V_253 , sizeof( V_4 -> V_253 ) ,
L_12 , V_3 -> V_231 ) ;
V_226 -> V_44 = V_4 -> V_253 ;
V_226 -> V_234 [ V_235 ] = V_254 ;
V_226 -> V_234 [ V_235 ] . V_65 =
V_4 -> V_160 ;
V_3 -> V_228 ++ ;
V_226 ++ ;
}
return 0 ;
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_25 ( V_3 ) ;
F_8 ( V_4 ) ;
F_26 ( V_4 -> V_255 ) ;
F_26 ( V_4 -> V_256 ) ;
F_125 ( & V_4 -> V_12 ) ;
F_26 ( V_4 ) ;
}
static void F_126 ( struct V_2 * V_3 , int V_257 ,
T_3 * V_258 , bool V_184 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_257 ; V_56 ++ ) {
unsigned int V_130 = F_54 ( V_3 , V_258 [ V_56 ] , 0 ,
V_192 , 0 ) ;
if ( V_130 & V_191 )
continue;
if ( V_184 )
V_130 &= ~ V_190 ;
else
V_130 |= V_190 ;
F_40 ( V_3 , V_258 [ V_56 ] , V_130 ) ;
}
}
static void F_127 ( struct V_2 * V_3 , int V_144 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_32 . V_108 )
return;
if ( ! V_144 )
V_144 = F_58 ( V_3 ,
V_4 -> V_32 . V_259 [ 0 ] ) ;
F_126 ( V_3 , V_4 -> V_32 . V_108 ,
V_4 -> V_32 . V_260 ,
V_144 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
int V_144 = 0 ;
int V_261 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_103 && V_4 -> V_32 . V_33 [ 0 ] &&
( V_4 -> V_9 != V_18 || V_4 -> V_36 ) &&
F_128 ( V_3 , V_4 -> V_32 . V_33 [ 0 ] ) )
V_144 = F_58 ( V_3 , V_4 -> V_32 . V_33 [ 0 ] ) ;
if ( V_4 -> V_121 )
V_261 = V_4 -> V_32 . V_95 + V_4 -> V_96 ;
else
V_261 = V_4 -> V_32 . V_95 ;
F_126 ( V_3 , V_261 , V_4 -> V_32 . V_259 , V_144 ) ;
F_127 ( V_3 , V_144 ) ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_8 ( V_4 ) ;
if ( V_4 -> V_9 == V_29 ) {
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_32 . V_262 ; V_56 ++ )
F_40 ( V_3 , V_4 -> V_32 . V_33 [ V_56 ] , 0 ) ;
}
return 0 ;
}
static int F_130 ( struct V_2 * V_3 , T_3 V_65 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_131 ( V_3 , & V_4 -> V_263 , V_65 ) ;
}
static bool F_132 ( struct V_2 * V_3 , T_3 V_169 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_157 . V_158 ; V_56 ++ ) {
if ( V_4 -> V_157 . V_164 [ V_56 ] == V_169 )
return false ;
}
if ( V_4 -> V_160 == V_169 )
return false ;
return true ;
}
static bool F_133 ( struct V_2 * V_3 , T_3 V_65 ,
T_3 V_264 , int V_265 ,
struct V_71 * V_72 , int V_77 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_113 [ 8 ] ;
int V_56 , V_261 ;
if ( V_65 == V_4 -> V_82 ) {
if ( ! V_265 )
return false ;
V_265 = 2 ;
}
V_261 = F_50 ( V_3 , V_65 , V_113 , F_51 ( V_113 ) ) ;
for ( V_56 = 0 ; V_56 < V_261 ; V_56 ++ ) {
if ( F_52 ( F_31 ( V_3 , V_113 [ V_56 ] ) ) != V_266 )
continue;
if ( V_113 [ V_56 ] == V_264 || F_132 ( V_3 , V_113 [ V_56 ] ) ) {
if ( ! ( V_4 -> V_82 && V_265 == 1 ) )
goto V_267;
}
}
if ( V_77 >= V_268 )
return false ;
for ( V_56 = 0 ; V_56 < V_261 ; V_56 ++ ) {
unsigned int type ;
type = F_52 ( F_31 ( V_3 , V_113 [ V_56 ] ) ) ;
if ( type == V_266 )
continue;
if ( F_133 ( V_3 , V_113 [ V_56 ] , V_264 ,
V_265 , V_72 , V_77 + 1 ) )
goto V_267;
}
return false ;
V_267:
V_72 -> V_72 [ V_72 -> V_77 ] = V_113 [ V_56 ] ;
V_72 -> V_46 [ V_72 -> V_77 ] = V_56 ;
if ( V_261 > 1 && F_52 ( F_31 ( V_3 , V_65 ) ) != V_269 )
V_72 -> V_80 [ V_72 -> V_77 ] = 1 ;
V_72 -> V_77 ++ ;
return true ;
}
static bool F_134 ( struct V_2 * V_3 , T_3 V_65 ,
T_3 V_264 , int V_265 ,
struct V_71 * V_72 )
{
if ( F_133 ( V_3 , V_65 , V_264 , V_265 , V_72 , 1 ) ) {
V_72 -> V_72 [ V_72 -> V_77 ] = V_65 ;
V_72 -> V_77 ++ ;
F_135 ( L_13 ,
V_72 -> V_77 , V_72 -> V_72 [ 0 ] , V_72 -> V_72 [ 1 ] ,
V_72 -> V_72 [ 2 ] , V_72 -> V_72 [ 3 ] , V_72 -> V_72 [ 4 ] ) ;
return true ;
}
return false ;
}
static int F_136 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_111 * V_112 = & V_4 -> V_32 ;
int V_56 ;
T_3 V_65 ;
V_4 -> V_157 . V_158 = 0 ;
V_4 -> V_157 . V_164 = V_4 -> V_270 ;
for ( V_56 = 0 ; V_56 < V_112 -> V_95 ; V_56 ++ ) {
T_3 V_169 = 0 ;
V_65 = V_112 -> V_259 [ V_56 ] ;
if ( ! V_65 )
continue;
if ( F_134 ( V_3 , V_65 , 0 , 0 , & V_4 -> V_97 [ V_56 ] ) )
V_169 = V_4 -> V_97 [ V_56 ] . V_72 [ 0 ] ;
if ( ! V_56 && F_134 ( V_3 , V_65 , V_169 , 1 ,
& V_4 -> V_99 ) )
V_169 = V_4 -> V_99 . V_72 [ 0 ] ;
if ( V_169 )
V_4 -> V_270 [ V_4 -> V_157 . V_158 ++ ] = V_169 ;
}
if ( ! V_4 -> V_97 [ 0 ] . V_77 && V_4 -> V_99 . V_77 ) {
V_4 -> V_97 [ 0 ] = V_4 -> V_99 ;
V_4 -> V_99 . V_77 = 0 ;
}
return 0 ;
}
static int F_137 ( struct V_2 * V_3 , const char * V_271 ,
int V_272 , bool V_273 , struct V_71 * V_72 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_44 [ 32 ] ;
T_3 V_169 , V_88 , V_274 , V_65 ;
int V_61 ;
V_169 = V_273 ? V_72 -> V_72 [ 0 ] : 0 ;
V_88 = V_72 -> V_72 [ V_72 -> V_77 - 1 ] ;
V_274 = V_72 -> V_77 > 1 ? V_72 -> V_72 [ 1 ] : 0 ;
if ( V_169 && F_30 ( V_3 , V_169 , V_85 , V_275 ) )
V_65 = V_169 ;
else if ( F_30 ( V_3 , V_88 , V_85 , V_275 ) )
V_65 = V_88 ;
else if ( F_30 ( V_3 , V_274 , V_85 , V_275 ) )
V_65 = V_274 ;
else
V_65 = 0 ;
if ( V_65 ) {
sprintf ( V_44 , L_1 , V_271 ) ;
V_61 = F_138 ( V_4 , V_62 , V_44 ,
F_29 ( V_65 , V_272 , 0 , V_85 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_72 -> V_83 = V_65 ;
}
if ( V_169 && F_30 ( V_3 , V_169 , V_85 , V_92 ) )
V_65 = V_169 ;
else if ( F_30 ( V_3 , V_88 , V_85 , V_92 ) )
V_65 = V_88 ;
else if ( F_30 ( V_3 , V_274 , V_85 , V_92 ) )
V_65 = V_274 ;
else
V_65 = 0 ;
if ( V_65 ) {
sprintf ( V_44 , L_2 , V_271 ) ;
V_61 = F_138 ( V_4 , V_276 , V_44 ,
F_29 ( V_65 , V_272 , 0 , V_85 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_72 -> V_84 = V_65 ;
}
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_111 * V_112 = & V_4 -> V_32 ;
struct V_277 * V_278 = V_112 -> V_120 ;
int V_56 , V_279 , V_261 , V_280 ;
int V_258 [ V_281 ] ;
for ( V_280 = V_282 ; V_280 >= V_283 ; V_280 -- ) {
V_261 = 0 ;
for ( V_56 = 0 ; V_56 < V_112 -> V_119 ; V_56 ++ ) {
unsigned int V_284 ;
if ( V_278 [ V_56 ] . type > V_285 )
continue;
V_284 = F_57 ( V_3 , V_278 [ V_56 ] . V_88 ) ;
if ( F_140 ( V_284 ) != V_280 )
continue;
for ( V_279 = 0 ; V_279 < V_261 ; V_279 ++ )
if ( V_278 [ V_258 [ V_279 ] ] . type < V_278 [ V_56 ] . type ) {
memmove ( V_258 + V_279 + 1 , V_258 + V_279 ,
( V_261 - V_279 ) * sizeof( int ) ) ;
break;
}
V_258 [ V_279 ] = V_56 ;
V_261 ++ ;
}
if ( V_112 -> V_95 + V_261 < 3 )
continue;
for ( V_56 = 0 ; V_56 < V_261 ; V_56 ++ ) {
T_3 V_88 = V_278 [ V_258 [ V_56 ] ] . V_88 ;
V_4 -> V_188 [ V_4 -> V_96 ++ ] = V_88 ;
V_112 -> V_259 [ V_112 -> V_95 ++ ] = V_88 ;
if ( V_112 -> V_95 == 3 )
break;
}
return;
}
}
static void F_141 ( struct V_71 * V_79 , struct V_71 * V_78 )
{
V_79 -> V_83 = V_78 -> V_83 ;
V_79 -> V_84 = V_78 -> V_84 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_111 * V_112 = & V_4 -> V_32 ;
struct V_71 * V_72 ;
static const char * const V_286 [ 4 ] = {
L_14 , L_15 , NULL , L_16
} ;
int V_56 , V_46 , V_61 ;
int V_287 ;
V_287 = V_112 -> V_95 ;
if ( V_112 -> V_95 == 1 )
F_139 ( V_3 ) ;
V_61 = F_136 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_4 -> V_157 . V_158 < 3 ) {
V_4 -> V_96 = 0 ;
V_112 -> V_95 = V_287 ;
}
for ( V_56 = 0 ; V_56 < V_112 -> V_95 ; V_56 ++ ) {
T_3 V_88 , V_169 ;
V_88 = V_112 -> V_259 [ V_56 ] ;
V_169 = V_4 -> V_157 . V_164 [ V_56 ] ;
if ( ! V_88 || ! V_169 )
continue;
V_72 = V_4 -> V_97 + V_56 ;
if ( V_56 == V_288 ) {
V_61 = F_137 ( V_3 , L_17 , 1 , true , V_72 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_137 ( V_3 , L_18 , 2 , true , V_72 ) ;
if ( V_61 < 0 )
return V_61 ;
} else {
const char * V_271 = V_286 [ V_56 ] ;
if ( V_112 -> V_237 == V_238 &&
V_112 -> V_95 <= 2 )
V_271 = V_56 ? L_19 : L_20 ;
V_61 = F_137 ( V_3 , V_271 , 3 , true , V_72 ) ;
if ( V_61 < 0 )
return V_61 ;
}
if ( V_72 != V_4 -> V_97 + V_56 )
F_141 ( & V_4 -> V_97 [ V_56 ] , V_72 ) ;
if ( V_72 == V_4 -> V_97 && V_4 -> V_99 . V_77 )
F_141 ( & V_4 -> V_99 , V_72 ) ;
}
V_46 = F_143 ( V_3 , V_4 -> V_82 ,
V_4 -> V_157 . V_164 [ 0 ] ) ;
if ( V_46 >= 0 ) {
const char * V_44 ;
V_44 = V_4 -> V_99 . V_77 ?
L_21 : L_22 ;
V_61 = F_138 ( V_4 , V_62 , V_44 ,
F_29 ( V_4 -> V_82 , 3 ,
V_46 , V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_44 = V_4 -> V_99 . V_77 ?
L_23 : L_24 ;
V_61 = F_138 ( V_4 , V_276 , V_44 ,
F_29 ( V_4 -> V_82 , 3 ,
V_46 , V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_112 -> V_95 = V_287 ;
return 0 ;
}
static int F_144 ( struct V_2 * V_3 , T_3 V_88 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_71 * V_72 ;
bool V_273 ;
int V_56 , V_61 ;
if ( ! V_88 )
return 0 ;
if ( ! F_134 ( V_3 , V_88 , 0 , 0 , & V_4 -> V_106 ) ) {
for ( V_56 = V_289 ; V_56 >= V_288 ; V_56 -- ) {
if ( V_56 < V_4 -> V_157 . V_158 &&
F_134 ( V_3 , V_88 ,
V_4 -> V_157 . V_164 [ V_56 ] , 0 ,
& V_4 -> V_106 ) ) {
V_4 -> V_102 = V_56 ;
break;
}
}
}
if ( V_4 -> V_106 . V_77 ) {
V_4 -> V_160 = V_4 -> V_106 . V_72 [ 0 ] ;
if ( ! V_4 -> V_102 )
V_4 -> V_104 = V_4 -> V_106 ;
}
if ( ! V_4 -> V_104 . V_77 )
F_134 ( V_3 , V_88 ,
V_4 -> V_157 . V_164 [ V_290 ] , 0 ,
& V_4 -> V_104 ) ;
if ( ! F_134 ( V_3 , V_88 , V_4 -> V_157 . V_164 [ V_290 ] ,
1 , & V_4 -> V_105 ) && ! V_4 -> V_104 . V_77 )
return 0 ;
if ( V_4 -> V_104 . V_77 ) {
V_72 = & V_4 -> V_104 ;
V_273 = true ;
} else {
V_72 = & V_4 -> V_105 ;
V_273 = false ;
}
V_61 = F_137 ( V_3 , L_25 , 3 , V_273 , V_72 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_273 )
F_141 ( & V_4 -> V_105 , V_72 ) ;
else
F_141 ( & V_4 -> V_104 , V_72 ) ;
if ( V_4 -> V_106 . V_77 )
F_141 ( & V_4 -> V_106 , V_72 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_71 * V_72 ;
bool V_273 ;
T_3 V_88 , V_169 = 0 ;
int V_61 ;
V_88 = V_4 -> V_32 . V_260 [ 0 ] ;
if ( ! V_4 -> V_32 . V_108 || ! V_88 )
return 0 ;
if ( F_134 ( V_3 , V_88 , 0 , 0 , & V_4 -> V_109 ) )
V_169 = V_4 -> V_109 . V_72 [ 0 ] ;
if ( ! V_169 )
F_134 ( V_3 , V_88 ,
V_4 -> V_157 . V_164 [ V_290 ] , 0 ,
& V_4 -> V_109 ) ;
if ( ! F_134 ( V_3 , V_88 , V_4 -> V_157 . V_164 [ V_290 ] ,
1 , & V_4 -> V_110 ) && ! V_169 )
return 0 ;
if ( ! V_4 -> V_99 . V_77 && V_4 -> V_110 . V_77 )
V_169 = 0 ;
V_4 -> V_291 = V_169 ;
V_4 -> V_157 . V_292 [ 0 ] = V_169 ;
if ( V_169 ) {
V_72 = & V_4 -> V_109 ;
V_273 = true ;
} else {
V_72 = & V_4 -> V_110 ;
V_273 = false ;
}
V_61 = F_137 ( V_3 , L_20 , 3 , V_273 , V_72 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_273 )
F_141 ( & V_4 -> V_110 , V_72 ) ;
else
F_141 ( & V_4 -> V_109 , V_72 ) ;
return 0 ;
}
static int F_146 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_41 -> V_150 . V_151 . V_152 [ 0 ] = V_4 -> V_98 ;
return 0 ;
}
static void F_147 ( struct V_2 * V_3 , int V_293 ,
struct V_71 * V_294 , struct V_71 * V_295 )
{
if ( V_293 ) {
F_37 ( V_3 , V_294 , false , false ) ;
F_37 ( V_3 , V_295 , true , false ) ;
} else {
F_37 ( V_3 , V_295 , false , false ) ;
F_37 ( V_3 , V_294 , true , false ) ;
}
}
static int F_148 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_47 = V_41 -> V_150 . V_151 . V_152 [ 0 ] ;
if ( V_47 == V_4 -> V_98 )
return 0 ;
V_4 -> V_98 = V_47 ;
F_147 ( V_3 , V_47 , & V_4 -> V_97 [ 0 ] , & V_4 -> V_99 ) ;
if ( ! V_4 -> V_103 ) {
F_147 ( V_3 , V_47 , & V_4 -> V_104 ,
& V_4 -> V_105 ) ;
}
F_147 ( V_3 , V_47 , & V_4 -> V_109 ,
& V_4 -> V_110 ) ;
return 1 ;
}
static int F_149 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_82 )
return 0 ;
if ( ! ( V_4 -> V_99 . V_77 || V_4 -> V_105 . V_77 ||
V_4 -> V_109 . V_77 ) )
return 0 ;
if ( ! F_75 ( V_4 , & V_296 ) )
return - V_49 ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_65 = V_3 -> V_297 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_3 -> V_298 ; V_56 ++ , V_65 ++ ) {
unsigned int V_299 = F_31 ( V_3 , V_65 ) ;
if ( F_52 ( V_299 ) != V_300 )
continue;
if ( V_299 & V_301 )
continue;
if ( ! ( V_299 & V_302 ) )
continue;
if ( V_4 -> V_117 >= F_51 ( V_4 -> V_118 ) )
return - V_49 ;
V_4 -> V_118 [ V_4 -> V_117 ++ ] = V_65 ;
}
return 0 ;
}
static int F_151 ( struct V_38 * V_39 ,
struct V_148 * V_149 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_149 -> type = V_154 ;
V_149 -> V_155 = 1 ;
V_149 -> V_150 . V_151 . V_156 = V_4 -> V_119 ;
if ( V_149 -> V_150 . V_151 . V_152 >= V_4 -> V_119 )
V_149 -> V_150 . V_151 . V_152 = V_4 -> V_119 - 1 ;
strcpy ( V_149 -> V_150 . V_151 . V_44 ,
V_4 -> V_120 [ V_149 -> V_150 . V_151 . V_152 ] . V_303 ) ;
return 0 ;
}
static int F_152 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_46 = F_153 ( V_39 , & V_41 -> V_177 ) ;
V_41 -> V_150 . V_151 . V_152 [ 0 ] = V_4 -> V_125 [ V_46 ] ;
return 0 ;
}
static int F_154 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_46 = F_153 ( V_39 , & V_41 -> V_177 ) ;
T_3 V_304 ;
int V_173 ;
V_173 = V_41 -> V_150 . V_151 . V_152 [ 0 ] ;
if ( V_173 < 0 || V_173 >= V_4 -> V_119 )
return - V_209 ;
if ( V_4 -> V_125 [ V_46 ] == V_173 )
return 0 ;
V_4 -> V_125 [ V_46 ] = V_173 ;
if ( V_4 -> V_128 ) {
int V_124 = V_4 -> V_120 [ V_173 ] . V_124 ;
V_304 = V_4 -> V_126 [ V_124 ] ;
F_113 ( V_3 , V_173 ) ;
} else {
V_304 = V_4 -> V_126 [ V_46 ] ;
if ( F_92 ( ! V_304 ) )
return - V_209 ;
}
if ( V_304 ) {
F_53 ( V_3 , V_304 , V_136 ) ;
F_9 ( V_3 , V_304 , 0 ,
V_81 ,
V_4 -> V_120 [ V_173 ] . V_127 ) ;
}
F_15 ( V_3 ) ;
return 0 ;
}
static int F_155 ( struct V_2 * V_3 , int V_155 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_7 * V_45 ;
if ( V_4 -> V_119 <= 1 || ! V_155 )
return 0 ;
V_45 = F_75 ( V_4 , & V_305 ) ;
if ( ! V_45 )
return - V_49 ;
V_45 -> V_155 = V_155 ;
return 0 ;
}
static void F_156 ( struct V_1 * V_4 , T_3 V_295 , int V_46 )
{
struct V_194 * V_54 ;
if ( V_4 -> V_197 >= F_51 ( V_4 -> V_198 ) - 1 )
return;
V_54 = V_4 -> V_198 + V_4 -> V_197 ;
V_54 -> V_65 = V_295 ;
V_54 -> V_66 = V_63 ;
V_54 -> V_46 = V_46 ;
V_4 -> V_197 ++ ;
V_4 -> V_263 . V_306 = V_4 -> V_198 ;
}
static bool F_157 ( struct V_2 * V_3 , T_3 V_78 ,
T_3 V_79 )
{
return F_158 ( V_3 , V_78 , V_79 , 1 ) >= 0 ;
}
static bool F_159 ( struct V_2 * V_3 , T_3 V_88 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_307 , V_46 ;
V_4 -> V_120 [ V_4 -> V_119 ] . V_124 = - 1 ;
V_4 -> V_120 [ V_4 -> V_119 ] . V_88 = V_88 ;
for ( V_307 = 0 ; V_307 < V_4 -> V_117 ; V_307 ++ ) {
if ( V_4 -> V_126 [ V_307 ] ) {
V_46 = F_143 ( V_3 , V_4 -> V_126 [ V_307 ] ,
V_88 ) ;
if ( V_46 < 0 )
continue;
V_4 -> V_120 [ V_4 -> V_119 ] . V_127 = V_46 ;
} else {
if ( ! F_157 ( V_3 , V_4 -> V_118 [ V_307 ] , V_88 ) )
continue;
}
V_4 -> V_120 [ V_4 -> V_119 ] . V_124 = V_307 ;
if ( ! V_4 -> V_128 &&
V_4 -> V_119 > 0 && V_4 -> V_120 [ 0 ] . V_124 != V_307 ) {
F_160 ( V_308
L_26 ) ;
V_4 -> V_128 = 1 ;
}
return true ;
}
return false ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_111 * V_112 = & V_4 -> V_32 ;
int V_56 , V_61 ;
V_61 = F_150 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_162 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
for ( V_56 = 0 ; V_56 < V_112 -> V_119 ; V_56 ++ ) {
if ( F_159 ( V_3 , V_112 -> V_120 [ V_56 ] . V_88 ) )
V_4 -> V_120 [ V_4 -> V_119 ++ ] . V_303 =
F_163 ( V_3 , V_112 , V_56 ) ;
}
if ( V_4 -> V_82 &&
F_159 ( V_3 , V_4 -> V_82 ) )
V_4 -> V_120 [ V_4 -> V_119 ++ ] . V_303 = L_27 ;
return 0 ;
}
static int F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_111 * V_112 = & V_4 -> V_32 ;
const char * V_309 = NULL ;
int V_59 = 0 ;
int V_56 , V_279 , V_61 , V_46 ;
if ( ! V_4 -> V_82 )
return 0 ;
for ( V_56 = 0 ; V_56 < V_112 -> V_119 ; V_56 ++ ) {
T_3 V_88 = V_112 -> V_120 [ V_56 ] . V_88 ;
const char * V_303 = F_163 ( V_3 , V_112 , V_56 ) ;
if ( V_309 && ! strcmp ( V_303 , V_309 ) )
V_59 ++ ;
else
V_59 = 0 ;
V_309 = V_303 ;
V_46 = F_143 ( V_3 , V_4 -> V_82 , V_88 ) ;
if ( V_46 >= 0 ) {
V_61 = F_28 ( V_4 , V_303 , V_59 ,
V_46 , V_4 -> V_82 ) ;
if ( V_61 < 0 )
return V_61 ;
F_156 ( V_4 , V_4 -> V_82 , V_46 ) ;
}
for ( V_279 = 0 ; V_279 < V_4 -> V_96 ; V_279 ++ ) {
if ( V_4 -> V_188 [ V_279 ] == V_88 ) {
V_4 -> V_187 [ V_279 ] = V_46 ;
V_4 -> V_180 [ V_279 ] = V_303 ;
break;
}
}
}
return 0 ;
}
static int F_165 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_111 * V_112 = & V_4 -> V_32 ;
const char * V_309 = NULL ;
int V_59 = 0 ;
int V_56 , V_61 ;
for ( V_56 = 0 ; V_56 < V_112 -> V_119 ; V_56 ++ ) {
T_3 V_88 = V_112 -> V_120 [ V_56 ] . V_88 ;
unsigned int V_68 ;
const char * V_303 ;
char V_44 [ 32 ] ;
if ( V_112 -> V_120 [ V_56 ] . type != V_123 )
continue;
V_68 = F_32 ( V_3 , V_88 , V_63 ) ;
if ( V_68 == - 1 || ! ( V_68 & V_275 ) )
continue;
V_303 = F_163 ( V_3 , V_112 , V_56 ) ;
if ( V_309 && ! strcmp ( V_303 , V_309 ) )
V_59 ++ ;
else
V_59 = 0 ;
V_309 = V_303 ;
snprintf ( V_44 , sizeof( V_44 ) , L_28 , V_303 ) ;
V_61 = F_23 ( V_4 , V_62 , V_44 , V_59 ,
F_29 ( V_88 , 3 , 0 , V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
}
return 0 ;
}
static int F_166 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 , V_61 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_117 ; V_56 ++ ) {
T_3 V_215 = V_4 -> V_118 [ V_56 ] ;
V_61 = F_23 ( V_4 , V_62 ,
L_29 , V_56 ,
F_29 ( V_215 , 3 , 0 ,
V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_23 ( V_4 , V_276 ,
L_30 , V_56 ,
F_29 ( V_215 , 3 , 0 ,
V_63 ) ) ;
if ( V_61 < 0 )
return V_61 ;
}
for ( V_56 = 0 ; V_56 < V_4 -> V_117 ; V_56 ++ )
if ( ! V_4 -> V_126 [ V_56 ] )
break;
V_61 = F_155 ( V_3 , V_56 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static int F_167 ( struct V_1 * V_4 , struct V_310 * * V_311 ,
struct V_312 * V_313 )
{
struct V_310 * V_115 ;
int V_56 ;
V_115 = F_2 ( sizeof( * V_115 ) + sizeof( long ) * 4 , V_5 ) ;
if ( ! V_115 )
return - V_49 ;
V_115 -> V_313 = V_313 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_117 ; V_56 ++ )
V_115 -> V_314 [ V_56 ] =
F_29 ( V_4 -> V_118 [ V_56 ] , 3 , 0 , V_63 ) ;
* V_311 = V_115 ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_7 * V_45 ;
int V_61 ;
V_61 = F_167 ( V_4 , & V_4 -> V_255 , & V_315 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_167 ( V_4 , & V_4 -> V_256 , & V_316 ) ;
if ( V_61 < 0 )
return V_61 ;
V_45 = F_75 ( V_4 , & V_317 ) ;
if ( ! V_45 )
return - V_49 ;
V_45 -> V_53 = ( long ) V_4 -> V_255 ;
V_45 = F_75 ( V_4 , & V_318 ) ;
if ( ! V_45 )
return - V_49 ;
V_45 -> V_53 = ( long ) V_4 -> V_256 ;
V_61 = F_155 ( V_3 , 1 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_61 ;
V_61 = F_161 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_4 -> V_128 )
V_61 = F_168 ( V_3 ) ;
else
V_61 = F_166 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_164 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_165 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static void F_170 ( struct V_2 * V_3 , T_3 V_65 )
{
unsigned int V_139 ;
unsigned char V_319 ;
V_139 = F_57 ( V_3 , V_65 ) ;
V_319 = ( unsigned char ) F_171 ( V_139 ) ;
V_319 = ( V_319 << 4 ) | F_172 ( V_139 ) ;
if ( F_59 ( V_139 ) == V_146
&& ( V_319 == 0xf0 || V_319 == 0xff ) ) {
V_139 = V_139 & ( ~ ( V_320 << 30 ) ) ;
F_173 ( V_3 , V_65 , V_139 ) ;
}
return;
}
static int F_174 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_9 != V_18 )
return 0 ;
V_41 -> V_150 . integer . V_150 [ 0 ] = V_4 -> V_36 ;
return 0 ;
}
static int F_175 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_47 ;
if ( V_4 -> V_9 != V_18 )
return 0 ;
V_47 = ! ! V_41 -> V_150 . integer . V_150 [ 0 ] ;
if ( V_4 -> V_36 == V_47 )
return 0 ;
V_4 -> V_36 = V_47 ;
if ( V_4 -> V_36 &&
F_176 ( V_3 , L_31 ) != 1 ) {
F_79 ( V_3 , 1 ) ;
F_76 ( V_3 ) ;
}
F_73 ( V_3 ) ;
F_11 ( V_4 ) ;
return 1 ;
}
static int F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_61 ;
V_61 = F_178 ( V_3 , & V_4 -> V_32 , NULL ) ;
if ( V_61 < 0 )
return V_61 ;
if ( ! V_4 -> V_32 . V_95 && ! V_4 -> V_32 . V_33 [ 0 ] )
return - V_209 ;
V_61 = F_142 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_144 ( V_3 , V_4 -> V_32 . V_33 [ 0 ] ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_145 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_149 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_169 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_4 -> V_157 . V_208 = V_4 -> V_157 . V_158 * 2 ;
F_179 ( V_3 ) ;
F_180 ( V_3 ) ;
if ( V_4 -> V_6 . V_54 )
V_4 -> V_219 [ V_4 -> V_218 ++ ] = V_4 -> V_6 . V_54 ;
if ( V_4 -> V_160 && V_4 -> V_105 . V_77 ) {
V_61 = F_74 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_61 = F_83 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_4 -> V_321 [ 0 ] )
V_3 -> V_321 = V_4 -> V_321 ;
return 1 ;
}
static void F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_157 . V_220 )
F_39 ( V_3 , V_4 -> V_32 . V_322 [ 0 ] , V_100 ) ;
if ( V_4 -> V_321 [ 0 ] )
F_39 ( V_3 , V_4 -> V_32 . V_322 [ 1 ] , V_100 ) ;
}
static void F_182 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 -> V_222 )
return;
F_40 ( V_3 , V_4 -> V_32 . V_323 , V_122 ) ;
}
static void F_183 ( struct V_2 * V_3 , struct V_324 * V_325 )
{
F_15 ( V_3 ) ;
F_73 ( V_3 ) ;
}
static void F_184 ( struct V_2 * V_3 , struct V_324 * V_325 )
{
F_15 ( V_3 ) ;
}
static void F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_111 * V_112 = & V_4 -> V_32 ;
unsigned int V_326 ;
int V_56 ;
T_4 V_327 ;
if ( V_112 -> V_33 [ 0 ] && F_128 ( V_3 , V_112 -> V_33 [ 0 ] ) )
F_186 ( V_3 , V_112 -> V_33 [ 0 ] ,
V_328 | V_329 ,
F_183 ) ;
if ( V_112 -> V_260 [ 0 ] )
V_326 = V_330 ;
else
V_326 = 0 ;
V_327 = V_326 ? F_183 : F_184 ;
for ( V_56 = 0 ; V_56 < V_112 -> V_95 ; V_56 ++ ) {
if ( V_112 -> V_259 [ V_56 ] &&
F_128 ( V_3 , V_112 -> V_259 [ V_56 ] ) )
F_186 ( V_3 , V_112 -> V_259 [ V_56 ] ,
V_326 | V_329 , V_327 ) ;
}
for ( V_56 = 0 ; V_56 < V_112 -> V_119 ; V_56 ++ ) {
if ( F_128 ( V_3 , V_112 -> V_120 [ V_56 ] . V_88 ) )
F_186 ( V_3 , V_112 -> V_120 [ V_56 ] . V_88 ,
V_329 ,
F_184 ) ;
}
}
static int F_187 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_331 ; V_56 ++ )
F_188 ( V_3 , V_4 -> V_332 [ V_56 ] ) ;
F_15 ( V_3 ) ;
F_86 ( V_3 , true ) ;
F_43 ( V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 ) ;
F_181 ( V_3 ) ;
F_182 ( V_3 ) ;
F_185 ( V_3 ) ;
F_73 ( V_3 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static void F_189 ( struct V_333 * V_334 )
{
struct V_1 * V_4 = F_190 ( V_334 , struct V_1 ,
V_35 . V_334 ) ;
if ( V_4 -> V_9 != V_18 )
return;
F_191 ( V_4 -> V_3 ) ;
if ( V_4 -> V_335
!= F_58 ( V_4 -> V_3 , V_4 -> V_32 . V_33 [ 0 ] ) ) {
V_4 -> V_335 ^= 1 ;
F_73 ( V_4 -> V_3 ) ;
}
if ( V_4 -> V_36 )
F_13 ( & V_4 -> V_35 ,
F_14 ( 100 ) ) ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_65 , V_113 [ 8 ] ;
unsigned int type ;
int V_56 , V_336 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_117 ; V_56 ++ ) {
V_65 = V_4 -> V_118 [ V_56 ] ;
while ( V_65 ) {
type = F_52 ( F_31 ( V_3 , V_65 ) ) ;
if ( type == V_129 )
break;
V_336 = F_50 ( V_3 , V_65 , V_113 ,
F_51 ( V_113 ) ) ;
if ( V_336 <= 0 )
break;
if ( V_336 > 1 ) {
V_4 -> V_126 [ V_56 ] = V_65 ;
break;
}
V_65 = V_113 [ 0 ] ;
}
}
return 0 ;
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x17 ;
F_170 ( V_3 , V_337 ) ;
F_170 ( V_3 , V_338 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
if ( ! F_75 ( V_4 , & V_339 ) )
return - V_49 ;
if ( V_3 -> V_14 == 0x11061708 )
V_4 -> V_232 = & V_340 ;
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_341 ;
V_3 -> V_342 = V_343 ;
F_193 ( & V_4 -> V_35 , F_189 ) ;
return 0 ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x18 ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_3 -> V_342 = V_343 ;
return 0 ;
}
static void F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_130 ;
int V_345 = 0 ;
if ( ( V_4 -> V_9 != V_23 ) &&
( V_3 -> V_14 != 0x11064397 ) )
V_345 = 1 ;
V_344 =
( F_54 ( V_3 , 0x17 , 0 , V_346 , 0x00 )
== ( ( V_4 -> V_9 == V_11 ) ? 5 : 0 ) ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x1a , & V_130 ) ;
F_56 ( V_3 , 0x1b , & V_130 ) ;
F_56 ( V_3 , 0x1e , & V_130 ) ;
if ( V_344 )
V_130 = V_136 ;
F_53 ( V_3 , 0x17 , V_130 ) ;
F_53 ( V_3 , 0x13 , V_130 ) ;
F_53 ( V_3 , 0x14 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x19 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x1b , & V_130 ) ;
F_53 ( V_3 , 0x18 , V_130 ) ;
F_53 ( V_3 , 0x11 , V_130 ) ;
if ( V_345 ) {
V_130 = V_147 ;
F_56 ( V_3 , 0x22 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x1a , & V_130 ) ;
F_53 ( V_3 , 0x26 , V_130 ) ;
F_53 ( V_3 , 0x24 , V_130 ) ;
} else if ( V_3 -> V_14 == 0x11064397 ) {
V_130 = V_147 ;
F_56 ( V_3 , 0x23 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x1a , & V_130 ) ;
F_53 ( V_3 , 0x27 , V_130 ) ;
F_53 ( V_3 , 0x25 , V_130 ) ;
}
V_130 = V_147 ;
F_56 ( V_3 , 0x1c , & V_130 ) ;
F_56 ( V_3 , 0x1d , & V_130 ) ;
if ( V_345 )
F_56 ( V_3 , 0x23 , & V_130 ) ;
F_53 ( V_3 , 0x16 , V_344 ? V_136 : V_130 ) ;
F_53 ( V_3 , 0x10 , V_130 ) ;
if ( V_345 ) {
F_53 ( V_3 , 0x25 , V_130 ) ;
F_53 ( V_3 , 0x27 , V_130 ) ;
} else if ( V_3 -> V_14 == 0x11064397 && V_4 -> V_103 )
F_53 ( V_3 , 0x25 , V_130 ) ;
}
static int F_196 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
if ( F_5 ( V_3 ) == V_10 )
return F_197 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x16 ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_195 ;
return 0 ;
}
static void F_179 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_32 . V_347 ; V_56 ++ ) {
T_3 V_65 ;
int V_113 ;
V_65 = V_4 -> V_32 . V_322 [ V_56 ] ;
if ( ! V_65 )
continue;
V_113 = F_50 ( V_3 , V_65 , & V_65 , 1 ) ;
if ( V_113 < 1 )
continue;
if ( ! V_4 -> V_157 . V_220 )
V_4 -> V_157 . V_220 = V_65 ;
else {
V_4 -> V_321 [ 0 ] = V_65 ;
break;
}
}
}
static void F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_348 ;
int V_56 , V_61 ;
if ( ! V_4 -> V_32 . V_323 )
return;
V_348 = V_3 -> V_297 ;
for ( V_56 = 0 ; V_56 < V_3 -> V_298 ; V_56 ++ , V_348 ++ ) {
unsigned int V_299 = F_31 ( V_3 , V_348 ) ;
if ( F_52 ( V_299 ) != V_300 )
continue;
if ( ! ( V_299 & V_301 ) )
continue;
if ( ! ( V_299 & V_302 ) )
continue;
V_61 = F_143 ( V_3 , V_348 ,
V_4 -> V_32 . V_323 ) ;
if ( V_61 >= 0 ) {
V_4 -> V_222 = V_348 ;
break;
}
}
}
static void F_198 ( struct V_2 * V_3 , T_3 V_88 ,
int V_349 , int V_350 , int V_351 )
{
F_199 ( V_3 , V_88 , V_63 ,
( V_349 << V_94 ) |
( V_350 << V_352 ) |
( V_351 << V_353 ) |
( 0 << V_354 ) ) ;
}
static int F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x16 ;
F_198 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_198 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_355 ;
V_3 -> V_342 = V_343 ;
if ( F_5 ( V_3 ) == V_10 ) {
F_26 ( V_3 -> V_231 ) ;
V_3 -> V_231 = F_22 ( L_32 , V_5 ) ;
snprintf ( V_3 -> V_181 -> V_182 -> V_356 ,
sizeof( V_3 -> V_181 -> V_182 -> V_356 ) ,
L_33 , V_3 -> V_357 , V_3 -> V_231 ) ;
}
if ( V_3 -> V_14 == 0x11064397 ) {
F_26 ( V_3 -> V_231 ) ;
V_3 -> V_231 = F_22 ( L_34 , V_5 ) ;
snprintf ( V_3 -> V_181 -> V_182 -> V_356 ,
sizeof( V_3 -> V_181 -> V_182 -> V_356 ) ,
L_33 , V_3 -> V_357 , V_3 -> V_231 ) ;
}
V_4 -> F_15 = F_195 ;
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
int V_344 =
F_54 ( V_3 , 0x13 , 0 , V_346 , 0x00 ) == 3 ;
unsigned int V_130 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x14 , & V_130 ) ;
F_56 ( V_3 , 0x15 , & V_130 ) ;
F_56 ( V_3 , 0x18 , & V_130 ) ;
if ( V_344 )
V_130 = V_136 ;
F_53 ( V_3 , 0x13 , V_130 ) ;
F_53 ( V_3 , 0x12 , V_130 ) ;
F_53 ( V_3 , 0x1f , V_130 ) ;
F_53 ( V_3 , 0x20 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x17 , & V_130 ) ;
F_56 ( V_3 , 0x16 , & V_130 ) ;
F_53 ( V_3 , 0x1a , V_344 ? V_136 : V_130 ) ;
F_53 ( V_3 , 0x10 , V_130 ) ;
F_53 ( V_3 , 0x1d , V_130 ) ;
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x1a ;
F_199 ( V_3 , 0x1A , V_63 ,
( 0x17 << V_94 ) |
( 0x17 << V_352 ) |
( 0x5 << V_353 ) |
( 1 << V_354 ) ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_358 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_200 ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_130 , V_359 ;
V_344 =
F_54 ( V_3 , 0x1e , 0 , V_346 , 0x00 ) == 5 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x29 , & V_130 ) ;
F_56 ( V_3 , 0x2a , & V_130 ) ;
F_56 ( V_3 , 0x2b , & V_130 ) ;
if ( V_344 )
V_130 = V_136 ;
F_53 ( V_3 , 0x1e , V_130 ) ;
F_53 ( V_3 , 0x1f , V_130 ) ;
F_53 ( V_3 , 0x10 , V_130 ) ;
F_53 ( V_3 , 0x11 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x27 , & V_130 ) ;
F_53 ( V_3 , 0x1a , V_130 ) ;
V_359 = V_130 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x26 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x2b , & V_130 ) ;
F_53 ( V_3 , 0xa , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x24 , & V_130 ) ;
if ( ! V_4 -> V_103 )
F_56 ( V_3 , 0x28 , & V_130 ) ;
F_53 ( V_3 , 0x8 , V_130 ) ;
if ( ! V_4 -> V_103 && V_359 != V_147 )
V_130 = V_359 ;
F_53 ( V_3 , 0xb , V_130 ) ;
F_53 ( V_3 , 0x21 , V_344 ? V_136 : V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x25 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x2a , & V_130 ) ;
F_53 ( V_3 , 0x9 , V_130 ) ;
if ( V_4 -> V_103 ) {
V_130 = V_147 ;
F_56 ( V_3 , 0x28 , & V_130 ) ;
F_53 ( V_3 , 0x1b , V_130 ) ;
F_53 ( V_3 , 0x34 , V_130 ) ;
F_53 ( V_3 , 0xc , V_130 ) ;
}
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_56 , V_261 ;
T_3 V_113 [ 8 ] ;
T_3 V_65 ;
if ( ! V_4 -> V_82 )
return 0 ;
V_261 = F_50 ( V_3 , V_4 -> V_82 , V_113 ,
F_51 ( V_113 ) - 1 ) ;
for ( V_56 = 0 ; V_56 < V_261 ; V_56 ++ ) {
if ( F_52 ( F_31 ( V_3 , V_113 [ V_56 ] ) ) == V_266 )
return 0 ;
}
V_65 = V_3 -> V_297 ;
for ( V_56 = 0 ; V_56 < V_3 -> V_298 ; V_56 ++ , V_65 ++ ) {
unsigned int V_68 = F_31 ( V_3 , V_65 ) ;
if ( F_52 ( V_68 ) == V_266 &&
! ( V_68 & V_301 ) ) {
V_113 [ V_261 ++ ] = V_65 ;
return F_204 ( V_3 ,
V_4 -> V_82 ,
V_261 , V_113 ) ;
}
}
return 0 ;
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x21 ;
F_198 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_198 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_203 ( V_3 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_360 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_202 ;
return 0 ;
}
static int F_206 ( struct V_38 * V_39 ,
struct V_148 * V_149 )
{
V_149 -> type = V_361 ;
V_149 -> V_155 = 1 ;
V_149 -> V_150 . integer . V_362 = 0 ;
V_149 -> V_150 . integer . V_363 = 1 ;
return 0 ;
}
static int F_207 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
int V_50 = 0 ;
V_50 = F_54 ( V_3 , 0x26 , 0 ,
V_346 , 0 ) ;
if ( V_50 != - 1 )
* V_41 -> V_150 . integer . V_150 = V_50 ;
return 0 ;
}
static int F_208 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_39 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_50 = * V_41 -> V_150 . integer . V_150 ;
F_9 ( V_3 , 0x26 , 0 ,
V_81 , V_50 ) ;
V_4 -> V_364 = V_50 ;
F_15 ( V_3 ) ;
return 1 ;
}
static void F_209 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_130 ;
unsigned int V_365 , V_144 ;
V_344 =
( F_54 ( V_3 , 0x17 , 0 ,
V_346 , 0x00 ) == 5 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x1a , & V_130 ) ;
F_56 ( V_3 , 0x1b , & V_130 ) ;
F_56 ( V_3 , 0x1e , & V_130 ) ;
if ( V_344 )
V_130 = V_136 ;
F_53 ( V_3 , 0x17 , V_130 ) ;
F_53 ( V_3 , 0x13 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x1e , & V_130 ) ;
if ( V_4 -> V_364 )
F_56 ( V_3 , 0x22 , & V_130 ) ;
else
F_53 ( V_3 , 0x22 , V_147 ) ;
F_53 ( V_3 , 0x26 , V_130 ) ;
F_53 ( V_3 , 0x14 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x19 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x1b , & V_130 ) ;
F_53 ( V_3 , 0x18 , V_130 ) ;
F_53 ( V_3 , 0x11 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x23 , & V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x1a , & V_130 ) ;
F_53 ( V_3 , 0x27 , V_130 ) ;
if ( V_4 -> V_121 )
F_56 ( V_3 , 0x1e , & V_130 ) ;
F_53 ( V_3 , 0x25 , V_130 ) ;
V_144 = F_58 ( V_3 , 0x1c ) ;
if ( V_144 )
V_365 = 0 ;
else {
V_144 = F_58 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_103 && V_144 )
V_365 = 0 ;
else
V_365 = 1 ;
}
V_130 = V_365 ? V_136 : V_147 ;
F_53 ( V_3 , 0x28 , V_130 ) ;
F_53 ( V_3 , 0x29 , V_130 ) ;
F_53 ( V_3 , 0x2a , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x1c , & V_130 ) ;
F_56 ( V_3 , 0x1d , & V_130 ) ;
if ( V_4 -> V_103 )
F_53 ( V_3 , 0x25 , V_130 ) ;
F_53 ( V_3 , 0x16 , V_344 ? V_136 : V_130 ) ;
F_53 ( V_3 , 0x10 , V_365 ? V_136 : V_130 ) ;
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x16 ;
F_198 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_198 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_366 ;
V_4 -> V_219 [ V_4 -> V_218 ] = V_367 ;
V_4 -> V_218 ++ ;
V_4 -> V_219 [ V_4 -> V_218 ++ ] = V_368 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_209 ;
return 0 ;
}
static void F_211 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_130 ;
unsigned int V_144 ;
V_344 =
F_54 ( V_3 , 0x1e , 0 , V_346 , 0x00 ) == 3 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x29 , & V_130 ) ;
F_56 ( V_3 , 0x2a , & V_130 ) ;
F_56 ( V_3 , 0x2b , & V_130 ) ;
V_130 = V_136 ;
F_53 ( V_3 , 0x1e , V_130 ) ;
F_53 ( V_3 , 0x1f , V_130 ) ;
F_53 ( V_3 , 0x10 , V_130 ) ;
F_53 ( V_3 , 0x11 , V_130 ) ;
F_53 ( V_3 , 0x8 , V_130 ) ;
if ( V_4 -> V_9 == V_29 ) {
V_130 = V_147 ;
F_56 ( V_3 , 0x28 , & V_130 ) ;
F_53 ( V_3 , 0x18 , V_130 ) ;
F_53 ( V_3 , 0x38 , V_130 ) ;
} else {
V_130 = V_147 ;
F_56 ( V_3 , 0x26 , & V_130 ) ;
F_53 ( V_3 , 0x1c , V_130 ) ;
F_53 ( V_3 , 0x37 , V_130 ) ;
}
if ( V_4 -> V_9 == V_29 ) {
V_130 = V_147 ;
F_56 ( V_3 , 0x25 , & V_130 ) ;
F_53 ( V_3 , 0x15 , V_130 ) ;
F_53 ( V_3 , 0x35 , V_130 ) ;
} else {
V_130 = V_147 ;
F_56 ( V_3 , 0x25 , & V_130 ) ;
F_53 ( V_3 , 0x19 , V_130 ) ;
F_53 ( V_3 , 0x35 , V_130 ) ;
}
if ( V_4 -> V_103 )
F_53 ( V_3 , 0x9 , V_136 ) ;
V_144 = F_58 ( V_3 , 0x25 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x24 , & V_130 ) ;
V_130 = V_144 ? V_147 : V_136 ;
if ( V_4 -> V_9 == V_29 )
F_53 ( V_3 , 0x14 , V_130 ) ;
else
F_53 ( V_3 , 0x18 , V_130 ) ;
F_53 ( V_3 , 0x34 , V_130 ) ;
V_144 = F_58 ( V_3 , 0x26 ) ;
V_130 = V_144 ? V_147 : V_136 ;
if ( V_4 -> V_9 == V_29 ) {
F_53 ( V_3 , 0x33 , V_130 ) ;
F_53 ( V_3 , 0x1c , V_130 ) ;
F_53 ( V_3 , 0x3c , V_130 ) ;
} else {
F_53 ( V_3 , 0x31 , V_130 ) ;
F_53 ( V_3 , 0x17 , V_130 ) ;
F_53 ( V_3 , 0x3b , V_130 ) ;
}
if ( V_344 || ! F_84 ( V_3 ) )
F_53 ( V_3 , 0x21 , V_136 ) ;
else
F_53 ( V_3 , 0x21 , V_147 ) ;
}
static void F_212 ( struct V_2 * V_3 ,
const struct V_369 * V_370 , int V_371 )
{
if ( V_371 == V_372 )
F_198 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_213 ( struct V_2 * V_3 )
{
static T_3 V_373 [] = { 0x14 , 0x1c } ;
static T_3 V_374 [] = { 0x1c } ;
F_204 ( V_3 , 0x24 , F_51 ( V_373 ) , V_373 ) ;
F_204 ( V_3 , 0x33 , F_51 ( V_374 ) , V_374 ) ;
}
static int F_214 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x21 ;
F_198 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_198 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_9 == V_29 )
F_213 ( V_3 ) ;
F_203 ( V_3 ) ;
F_215 ( V_3 , NULL , V_375 , V_376 ) ;
F_216 ( V_3 , V_372 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
if ( V_4 -> V_9 == V_29 )
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_377 ;
else
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_378 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_211 ;
return 0 ;
}
static void F_217 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_130 ;
unsigned int V_144 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x29 , & V_130 ) ;
F_56 ( V_3 , 0x2a , & V_130 ) ;
F_56 ( V_3 , 0x2b , & V_130 ) ;
V_130 = V_136 ;
F_53 ( V_3 , 0x1e , V_130 ) ;
F_53 ( V_3 , 0x1f , V_130 ) ;
F_53 ( V_3 , 0x10 , V_130 ) ;
F_53 ( V_3 , 0x11 , V_130 ) ;
F_53 ( V_3 , 0x8 , V_136 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x28 , & V_130 ) ;
F_53 ( V_3 , 0x18 , V_130 ) ;
F_53 ( V_3 , 0x38 , V_130 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x25 , & V_130 ) ;
F_53 ( V_3 , 0x15 , V_130 ) ;
F_53 ( V_3 , 0x35 , V_130 ) ;
if ( V_4 -> V_103 )
F_53 ( V_3 , 0x9 , V_136 ) ;
V_144 = F_58 ( V_3 , 0x25 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x24 , & V_130 ) ;
if ( V_144 ) {
F_53 ( V_3 , 0x14 , V_147 ) ;
F_53 ( V_3 , 0x34 , V_147 ) ;
} else {
F_53 ( V_3 , 0x14 , V_136 ) ;
F_53 ( V_3 , 0x34 , V_136 ) ;
}
V_144 = F_58 ( V_3 , 0x28 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x31 , & V_130 ) ;
if ( V_144 ) {
F_53 ( V_3 , 0x1c , V_147 ) ;
F_53 ( V_3 , 0x3c , V_147 ) ;
F_53 ( V_3 , 0x3e , V_147 ) ;
} else {
F_53 ( V_3 , 0x1c , V_136 ) ;
F_53 ( V_3 , 0x3c , V_136 ) ;
F_53 ( V_3 , 0x3e , V_136 ) ;
}
V_130 = V_147 ;
F_56 ( V_3 , 0x33 , & V_130 ) ;
F_53 ( V_3 , 0x1d , V_130 ) ;
F_53 ( V_3 , 0x3d , V_130 ) ;
}
static int F_218 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x21 ;
F_198 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_198 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_203 ( V_3 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_379 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_217 ;
return 0 ;
}
static void F_219 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_344 ;
unsigned int V_130 , V_359 ;
V_344 =
F_54 ( V_3 , 0x1e , 0 , V_346 , 0x00 ) == 4 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x29 , & V_130 ) ;
F_56 ( V_3 , 0x2a , & V_130 ) ;
F_56 ( V_3 , 0x2b , & V_130 ) ;
if ( V_344 )
V_130 = V_136 ;
F_53 ( V_3 , 0x1e , V_130 ) ;
F_53 ( V_3 , 0x1f , V_130 ) ;
F_53 ( V_3 , 0x10 , V_130 ) ;
F_53 ( V_3 , 0x11 , V_130 ) ;
if ( V_4 -> V_9 == V_30 ) {
V_130 = V_147 ;
F_53 ( V_3 , 0x27 , V_130 ) ;
F_53 ( V_3 , 0x37 , V_130 ) ;
} else {
V_130 = V_147 ;
F_56 ( V_3 , 0x27 , & V_130 ) ;
F_53 ( V_3 , 0x37 , V_130 ) ;
}
V_130 = V_147 ;
F_56 ( V_3 , 0x26 , & V_130 ) ;
F_53 ( V_3 , 0x36 , V_130 ) ;
if ( V_4 -> V_121 ) {
F_56 ( V_3 , 0x2b , & V_130 ) ;
F_53 ( V_3 , 0x3b , V_130 ) ;
F_53 ( V_3 , 0x1b , V_130 ) ;
}
F_55 ( V_3 , 0xa , V_130 , 2 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x25 , & V_130 ) ;
F_53 ( V_3 , 0x35 , V_130 ) ;
if ( V_4 -> V_121 ) {
F_56 ( V_3 , 0x2a , & V_130 ) ;
F_53 ( V_3 , 0x3a , V_130 ) ;
F_53 ( V_3 , 0x1a , V_130 ) ;
}
F_55 ( V_3 , 0x9 , V_130 , 1 ) ;
V_130 = V_147 ;
F_56 ( V_3 , 0x28 , & V_130 ) ;
F_53 ( V_3 , 0x38 , V_130 ) ;
F_53 ( V_3 , 0x18 , V_130 ) ;
if ( V_4 -> V_103 )
F_55 ( V_3 , 0xb , V_130 , 3 ) ;
V_359 = V_130 ;
V_130 = V_147 ;
F_56 ( V_3 , 0x24 , & V_130 ) ;
F_53 ( V_3 , 0x34 , V_130 ) ;
if ( ! V_4 -> V_103 && V_359 != V_147 )
V_130 = V_359 ;
F_55 ( V_3 , 0x8 , V_130 , 0 ) ;
F_53 ( V_3 , 0x3f , V_344 ? V_136 : V_130 ) ;
}
static int F_220 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_49 ;
V_4 -> V_82 = 0x3f ;
F_203 ( V_3 ) ;
V_61 = F_177 ( V_3 ) ;
if ( V_61 < 0 ) {
F_124 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_332 [ V_4 -> V_331 ++ ] = V_380 ;
V_3 -> V_342 = V_343 ;
V_4 -> F_15 = F_219 ;
return 0 ;
}
static int T_5 F_221 ( void )
{
return F_222 ( & V_381 ) ;
}
static void T_6 F_223 ( void )
{
F_224 ( & V_381 ) ;
}
