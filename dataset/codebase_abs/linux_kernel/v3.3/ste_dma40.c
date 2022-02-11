static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 . V_5 -> V_1 ;
}
static bool F_2 ( struct V_2 * V_4 )
{
return V_4 -> V_6 == V_7 ;
}
static bool F_3 ( struct V_2 * V_4 )
{
return ! F_2 ( V_4 ) ;
}
static void T_1 * F_4 ( struct V_2 * V_4 )
{
return V_4 -> V_8 -> V_9 + V_10 +
V_4 -> V_11 -> V_12 * V_13 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_14 * V_15 ,
int V_16 )
{
bool V_17 = F_3 ( V_3 ) ;
T_2 V_18 ;
void * V_8 ;
if ( V_17 )
V_18 = sizeof( struct V_19 ) ;
else
V_18 = sizeof( struct V_20 ) ;
if ( V_16 == 1 ) {
V_8 = V_15 -> V_21 . V_22 ;
V_15 -> V_21 . V_23 = sizeof( V_15 -> V_21 . V_22 ) ;
V_15 -> V_21 . V_8 = NULL ;
} else {
V_15 -> V_21 . V_23 = V_16 * 2 * V_18 ;
V_8 = F_6 ( V_15 -> V_21 . V_23 + V_18 , V_24 ) ;
V_15 -> V_21 . V_8 = V_8 ;
if ( V_15 -> V_21 . V_8 == NULL )
return - V_25 ;
}
if ( V_17 ) {
V_15 -> V_26 . V_27 = F_7 ( V_8 , V_18 ) ;
V_15 -> V_26 . V_28 = V_15 -> V_26 . V_27 + V_16 ;
V_15 -> V_21 . V_29 = 0 ;
} else {
V_15 -> V_30 . V_27 = F_7 ( V_8 , V_18 ) ;
V_15 -> V_30 . V_28 = V_15 -> V_30 . V_27 + V_16 ;
V_15 -> V_21 . V_29 = F_8 ( V_3 -> V_8 -> V_5 ,
V_15 -> V_30 . V_27 ,
V_15 -> V_21 . V_23 ,
V_31 ) ;
if ( F_9 ( V_3 -> V_8 -> V_5 ,
V_15 -> V_21 . V_29 ) ) {
F_10 ( V_15 -> V_21 . V_8 ) ;
V_15 -> V_21 . V_8 = NULL ;
V_15 -> V_21 . V_29 = 0 ;
return - V_25 ;
}
}
return 0 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
if ( V_15 -> V_21 . V_29 )
F_12 ( V_3 -> V_8 -> V_5 , V_15 -> V_21 . V_29 ,
V_15 -> V_21 . V_23 , V_31 ) ;
F_10 ( V_15 -> V_21 . V_8 ) ;
V_15 -> V_21 . V_8 = NULL ;
V_15 -> V_21 . V_23 = 0 ;
V_15 -> V_26 . V_27 = NULL ;
V_15 -> V_26 . V_28 = NULL ;
V_15 -> V_30 . V_27 = NULL ;
V_15 -> V_30 . V_28 = NULL ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
unsigned long V_32 ;
int V_33 ;
int V_34 = - V_35 ;
int V_36 ;
F_14 ( & V_3 -> V_8 -> V_37 . V_38 , V_32 ) ;
V_36 = V_3 -> V_11 -> V_12 * V_39 ;
for ( V_33 = 1 ; V_33 < V_39 / 2 ; V_33 ++ ) {
if ( ! V_3 -> V_8 -> V_37 . V_40 [ V_36 + V_33 ] ) {
V_3 -> V_8 -> V_37 . V_40 [ V_36 + V_33 ] = V_15 ;
V_15 -> V_41 ++ ;
V_34 = V_33 ;
break;
}
}
F_15 ( & V_3 -> V_8 -> V_37 . V_38 , V_32 ) ;
return V_34 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
unsigned long V_32 ;
int V_33 ;
int V_34 = - V_35 ;
if ( F_2 ( V_3 ) )
return 0 ;
F_14 ( & V_3 -> V_8 -> V_37 . V_38 , V_32 ) ;
for ( V_33 = 1 ; V_33 < V_39 / 2 ; V_33 ++ ) {
if ( V_3 -> V_8 -> V_37 . V_40 [ V_3 -> V_11 -> V_12 *
V_39 + V_33 ] == V_15 ) {
V_3 -> V_8 -> V_37 . V_40 [ V_3 -> V_11 -> V_12 *
V_39 + V_33 ] = NULL ;
V_15 -> V_41 -- ;
if ( V_15 -> V_41 == 0 ) {
V_34 = 0 ;
break;
}
}
}
F_15 ( & V_3 -> V_8 -> V_37 . V_38 , V_32 ) ;
return V_34 ;
}
static void F_17 ( struct V_14 * V_15 )
{
F_18 ( & V_15 -> V_42 ) ;
}
static struct V_14 * F_19 ( struct V_2 * V_3 )
{
struct V_14 * V_43 = NULL ;
if ( ! F_20 ( & V_3 -> V_44 ) ) {
struct V_14 * V_45 ;
struct V_14 * V_46 ;
F_21 (d, _d, &d40c->client, node) {
if ( F_22 ( & V_45 -> V_47 ) ) {
F_17 ( V_45 ) ;
V_43 = V_45 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
break;
}
}
}
if ( ! V_43 )
V_43 = F_23 ( V_3 -> V_8 -> V_48 , V_24 ) ;
if ( V_43 )
F_24 ( & V_43 -> V_42 ) ;
return V_43 ;
}
static void F_25 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
F_11 ( V_3 , V_15 ) ;
F_16 ( V_3 , V_15 ) ;
F_26 ( V_3 -> V_8 -> V_48 , V_15 ) ;
}
static void F_27 ( struct V_2 * V_3 , struct V_14 * V_43 )
{
F_28 ( & V_43 -> V_42 , & V_3 -> V_49 ) ;
}
static void F_29 ( struct V_2 * V_4 , struct V_14 * V_43 )
{
struct V_20 * V_50 = V_43 -> V_30 . V_28 ;
struct V_20 * V_51 = V_43 -> V_30 . V_27 ;
void T_1 * V_8 = F_4 ( V_4 ) ;
F_30 ( V_51 -> V_52 , V_8 + V_53 ) ;
F_30 ( V_51 -> V_54 , V_8 + V_55 ) ;
F_30 ( V_51 -> V_56 , V_8 + V_57 ) ;
F_30 ( V_51 -> V_58 , V_8 + V_59 ) ;
F_30 ( V_50 -> V_52 , V_8 + V_60 ) ;
F_30 ( V_50 -> V_54 , V_8 + V_61 ) ;
F_30 ( V_50 -> V_56 , V_8 + V_62 ) ;
F_30 ( V_50 -> V_58 , V_8 + V_63 ) ;
}
static void F_31 ( struct V_2 * V_4 , struct V_14 * V_43 )
{
struct V_64 * V_65 = & V_4 -> V_8 -> V_37 ;
struct V_66 * V_67 = & V_43 -> V_26 ;
int V_68 = V_43 -> V_68 ;
int V_16 = V_43 -> V_16 ;
bool V_69 = V_43 -> V_69 ;
int V_70 = - V_35 ;
int V_71 = 0 ;
bool V_72 = V_4 -> V_8 -> V_73 -> V_72 ;
bool V_74 ;
V_74 = V_69 && V_68 == 0 ;
if ( V_74 || ( V_16 - V_68 > 1 ) ) {
V_70 = F_13 ( V_4 , V_43 ) ;
V_71 = V_70 ;
}
if ( ! V_74 || V_70 == - V_35 ) {
unsigned int V_32 = 0 ;
if ( V_70 == - V_35 )
V_32 |= V_75 ;
F_32 ( V_4 -> V_76 ,
& V_67 -> V_28 [ V_68 ] ,
& V_67 -> V_27 [ V_68 ] ,
V_70 ,
V_32 ) ;
V_68 ++ ;
}
if ( V_70 < 0 )
goto V_77;
for (; V_68 < V_16 ; V_68 ++ ) {
unsigned int V_78 = V_4 -> V_11 -> V_12 * 1024 +
8 * V_70 * 2 ;
struct V_19 * V_79 = V_65 -> V_8 + V_78 ;
unsigned int V_32 = 0 ;
int V_80 ;
if ( V_68 + 1 < V_16 )
V_80 = F_13 ( V_4 , V_43 ) ;
else
V_80 = V_74 ? V_71 : - V_35 ;
if ( V_69 || V_80 == - V_35 )
V_32 |= V_75 ;
if ( V_74 && V_70 == V_71 ) {
F_32 ( V_4 -> V_76 ,
& V_67 -> V_28 [ V_68 ] ,
& V_67 -> V_27 [ V_68 ] ,
V_80 , V_32 ) ;
}
F_33 ( V_79 ,
& V_67 -> V_28 [ V_68 ] ,
& V_67 -> V_27 [ V_68 ] ,
V_80 , V_32 ) ;
if ( ! V_72 ) {
F_34 ( V_4 -> V_8 -> V_5 ,
V_65 -> V_29 , V_78 ,
2 * sizeof( struct V_19 ) ,
V_31 ) ;
}
V_70 = V_80 ;
if ( V_70 == - V_35 || V_70 == V_71 ) {
V_68 ++ ;
break;
}
}
V_77:
V_43 -> V_68 = V_68 ;
}
static void F_35 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
if ( F_2 ( V_3 ) ) {
F_29 ( V_3 , V_15 ) ;
V_15 -> V_68 = V_15 -> V_16 ;
} else
F_31 ( V_3 , V_15 ) ;
}
static struct V_14 * F_36 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_49 ) )
return NULL ;
V_45 = F_37 ( & V_3 -> V_49 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static void F_38 ( struct V_2 * V_3 , struct V_14 * V_43 )
{
F_17 ( V_43 ) ;
V_43 -> V_81 = false ;
F_28 ( & V_43 -> V_42 , & V_3 -> V_82 ) ;
}
static struct V_14 * F_39 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_82 ) )
return NULL ;
V_45 = F_37 ( & V_3 -> V_82 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static struct V_14 * F_40 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_83 ) )
return NULL ;
V_45 = F_37 ( & V_3 -> V_83 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static int F_41 ( bool V_17 , int V_84 )
{
if ( V_17 ) {
if ( V_84 == V_85 )
return 1 ;
} else {
if ( V_84 == V_86 )
return 1 ;
}
return 2 << V_84 ;
}
static int F_42 ( int V_23 , T_2 V_87 , T_2 V_88 )
{
int V_89 ;
T_2 V_90 = F_43 ( V_87 , V_88 ) ;
T_2 V_91 = F_44 ( V_87 , V_88 ) ;
T_2 V_92 = F_45 ( V_93 << V_91 , 1 << V_90 ) ;
if ( V_92 > V_93 )
V_92 -= ( 1 << V_90 ) ;
if ( ! F_46 ( V_23 , 1 << V_90 ) )
return - V_35 ;
if ( V_23 <= V_92 )
V_89 = 1 ;
else {
V_89 = V_23 / V_92 ;
if ( V_89 * V_92 < V_23 )
V_89 ++ ;
}
return V_89 ;
}
static int F_47 ( struct V_94 * V_95 , int V_96 ,
T_2 V_87 , T_2 V_88 )
{
struct V_94 * V_97 ;
int V_33 ;
int V_98 = 0 ;
int V_34 ;
F_48 (sgl, sg, sg_len, i) {
V_34 = F_42 ( F_49 ( V_97 ) ,
V_87 , V_88 ) ;
if ( V_34 < 0 )
return V_34 ;
V_98 += V_34 ;
}
return V_98 ;
}
static void F_50 ( void T_1 * V_99 , T_2 * V_100 ,
T_2 * V_101 , int V_12 , bool V_102 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ ) {
void T_1 * V_103 = V_99 + V_101 [ V_33 ] ;
if ( V_102 )
V_100 [ V_33 ] = F_51 ( V_103 ) ;
else
F_52 ( V_100 [ V_33 ] , V_103 ) ;
}
}
static void F_53 ( struct V_104 * V_8 , bool V_102 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
void T_1 * V_103 ;
int V_106 ;
if ( V_8 -> V_107 [ V_33 ] . V_108 )
continue;
V_103 = V_8 -> V_9 + V_10 + V_33 * V_13 ;
V_106 = V_33 * F_54 ( V_109 ) ;
F_50 ( V_103 , & V_8 -> V_110 [ V_106 ] ,
V_109 ,
F_54 ( V_109 ) ,
V_102 ) ;
}
F_50 ( V_8 -> V_9 , V_8 -> V_111 ,
V_112 , F_54 ( V_112 ) ,
V_102 ) ;
if ( V_8 -> V_113 >= 3 )
F_50 ( V_8 -> V_9 , V_8 -> V_114 ,
V_115 ,
F_54 ( V_115 ) ,
V_102 ) ;
}
static void F_53 ( struct V_104 * V_8 , bool V_102 )
{
}
static int F_55 ( struct V_2 * V_3 ,
enum V_116 V_117 )
{
T_2 V_118 ;
int V_33 ;
void T_1 * V_119 ;
int V_34 = 0 ;
unsigned long V_32 ;
T_2 V_120 ;
F_14 ( & V_3 -> V_8 -> V_121 , V_32 ) ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_119 = V_3 -> V_8 -> V_9 + V_122 ;
else
V_119 = V_3 -> V_8 -> V_9 + V_123 ;
if ( V_117 == V_124 ) {
V_118 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
if ( V_118 == V_125 || V_118 == V_126 )
goto V_127;
}
V_120 = 0xffffffff & ~ ( F_57 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_120 | ( V_117 << F_58 ( V_3 -> V_11 -> V_12 ) ) ,
V_119 ) ;
if ( V_117 == V_124 ) {
for ( V_33 = 0 ; V_33 < V_128 ; V_33 ++ ) {
V_118 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
F_59 () ;
F_60 ( 3 ) ;
if ( V_118 == V_126 ||
V_118 == V_125 )
break;
}
if ( V_33 == V_128 ) {
F_61 ( V_3 ,
L_1 ,
V_3 -> V_11 -> V_12 , V_3 -> V_6 ,
V_118 ) ;
F_62 () ;
V_34 = - V_129 ;
}
}
V_127:
F_15 ( & V_3 -> V_8 -> V_121 , V_32 ) ;
return V_34 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
struct V_14 * V_46 ;
while ( ( V_15 = F_36 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
while ( ( V_15 = F_40 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
while ( ( V_15 = F_39 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
if ( ! F_20 ( & V_3 -> V_44 ) )
F_21 (d40d, _d, &d40c->client, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
if ( ! F_20 ( & V_3 -> V_130 ) )
F_21 (d40d, _d,
&d40c->prepare_queue, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
V_3 -> V_131 = 0 ;
V_3 -> V_132 = false ;
}
static void F_64 ( struct V_2 * V_3 , bool V_133 ,
T_2 V_134 , int V_135 )
{
void T_1 * V_103 = F_4 ( V_3 ) + V_135 ;
int V_136 ;
if ( ! V_133 ) {
F_30 ( ( V_137 << F_65 ( V_134 ) )
| ~ F_66 ( V_134 ) , V_103 ) ;
return;
}
V_136 = 100 ;
while ( -- V_136 ) {
F_30 ( ( V_138 << F_65 ( V_134 ) )
| ~ F_66 ( V_134 ) , V_103 ) ;
if ( F_56 ( V_103 ) & F_66 ( V_134 ) )
break;
}
if ( V_136 != 99 )
F_67 ( F_1 ( V_3 ) ,
L_2 ,
V_139 , V_135 == V_59 ? 'S' : 'D' ,
100 - V_136 ) ;
F_68 ( ! V_136 ) ;
}
static void F_69 ( struct V_2 * V_3 , bool V_140 )
{
unsigned long V_32 ;
F_14 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
if ( ( V_3 -> V_141 . V_142 == V_143 ) ||
( V_3 -> V_141 . V_142 == V_144 ) ) {
T_2 V_134 = F_70 ( V_3 -> V_141 . V_145 ) ;
F_64 ( V_3 , V_140 , V_134 ,
V_59 ) ;
}
if ( V_3 -> V_141 . V_142 != V_143 ) {
T_2 V_134 = F_70 ( V_3 -> V_141 . V_146 ) ;
F_64 ( V_3 , V_140 , V_134 ,
V_63 ) ;
}
F_15 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
}
static T_2 F_71 ( struct V_2 * V_3 )
{
void T_1 * V_147 = F_4 ( V_3 ) ;
T_2 V_148 ;
V_148 = F_56 ( V_147 + V_59 ) ;
V_148 |= F_56 ( V_147 + V_63 ) ;
return V_148 ;
}
static T_2 F_72 ( struct V_2 * V_3 )
{
static const unsigned int V_149 [] = {
[ V_150 ]
= V_151 ,
[ V_152 ]
= V_153 ,
[ V_154 ]
= V_155 ,
} ;
static const unsigned int V_156 [] = {
[ V_157 ]
= V_158 ,
[ V_159 ]
= V_160 ,
[ V_161 ]
= V_162 ,
} ;
if ( F_2 ( V_3 ) )
return V_149 [ V_3 -> V_141 . V_163 ] ;
else
return V_156 [ V_3 -> V_141 . V_163 ] ;
}
static void F_73 ( struct V_2 * V_3 )
{
T_2 V_164 ;
T_2 V_165 ;
V_164 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_165 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_58 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_165 , V_3 -> V_8 -> V_9 + V_166 + V_164 ) ;
V_165 = F_72 ( V_3 ) << F_58 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_165 , V_3 -> V_8 -> V_9 + V_167 + V_164 ) ;
if ( F_3 ( V_3 ) ) {
int V_168 = ( V_3 -> V_11 -> V_12 << V_169 )
& V_170 ;
void T_1 * V_147 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_171 , V_147 + V_53 ) ;
F_30 ( V_3 -> V_172 , V_147 + V_60 ) ;
F_30 ( V_168 , V_147 + V_55 ) ;
F_30 ( V_168 , V_147 + V_61 ) ;
F_30 ( 0 , V_147 + V_59 ) ;
F_30 ( 0 , V_147 + V_63 ) ;
}
}
static T_2 F_74 ( struct V_2 * V_3 )
{
T_2 V_173 ;
if ( F_3 ( V_3 ) )
V_173 = ( F_56 ( & V_3 -> V_76 -> V_174 ) & V_175 )
>> V_176 ;
else {
T_2 V_148 = F_56 ( F_4 ( V_3 ) + V_61 ) ;
V_173 = ( V_148 & V_177 )
>> V_178 ;
}
return V_173 * ( 1 << V_3 -> V_141 . V_179 . V_180 ) ;
}
static bool F_75 ( struct V_2 * V_3 )
{
bool V_181 ;
if ( F_3 ( V_3 ) )
V_181 = F_56 ( & V_3 -> V_76 -> V_182 ) & V_183 ;
else
V_181 = F_56 ( F_4 ( V_3 ) + V_63 )
& V_184 ;
return V_181 ;
}
static int F_76 ( struct V_2 * V_3 )
{
int V_185 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_132 )
return 0 ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_185 = F_55 ( V_3 , V_124 ) ;
if ( V_185 == 0 ) {
if ( F_3 ( V_3 ) ) {
F_69 ( V_3 , false ) ;
if ( F_71 ( V_3 ) )
V_185 = F_55 ( V_3 ,
V_186 ) ;
}
}
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_185 ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_185 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_132 )
return 0 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
if ( V_3 -> V_8 -> V_113 == 0 )
if ( F_3 ( V_3 ) ) {
V_185 = F_55 ( V_3 ,
V_124 ) ;
goto V_187;
}
if ( F_74 ( V_3 ) || F_75 ( V_3 ) ) {
if ( F_3 ( V_3 ) )
F_69 ( V_3 , true ) ;
V_185 = F_55 ( V_3 , V_186 ) ;
}
V_187:
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_185 ;
}
static int F_81 ( struct V_2 * V_4 )
{
unsigned long V_32 ;
int V_34 = 0 ;
V_34 = F_76 ( V_4 ) ;
if ( ! V_34 && F_2 ( V_4 ) )
V_34 = F_55 ( V_4 , V_126 ) ;
F_14 ( & V_4 -> V_38 , V_32 ) ;
F_63 ( V_4 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return V_34 ;
}
static T_3 F_82 ( struct V_188 * V_189 )
{
struct V_2 * V_3 = F_83 ( V_189 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_83 ( V_189 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_3 -> V_4 . V_190 ++ ;
if ( V_3 -> V_4 . V_190 < 0 )
V_3 -> V_4 . V_190 = 1 ;
V_15 -> V_47 . V_190 = V_3 -> V_4 . V_190 ;
F_38 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_189 -> V_190 ;
}
static int F_84 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_113 == 0 ) {
int V_191 ;
if ( F_3 ( V_3 ) ) {
V_191 = F_55 ( V_3 ,
V_124 ) ;
if ( V_191 )
return V_191 ;
}
}
if ( F_3 ( V_3 ) )
F_69 ( V_3 , true ) ;
return F_55 ( V_3 , V_186 ) ;
}
static struct V_14 * F_85 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_191 ;
V_15 = F_40 ( V_3 ) ;
if ( V_15 != NULL ) {
if ( ! V_3 -> V_132 )
V_3 -> V_132 = true ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
V_191 = F_84 ( V_3 ) ;
if ( V_191 )
return NULL ;
}
return V_15 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_69 ) {
if ( V_15 -> V_68 < V_15 -> V_16
&& ! F_75 ( V_3 )
&& ! F_74 ( V_3 ) ) {
F_16 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
( void ) F_84 ( V_3 ) ;
if ( V_15 -> V_68 == V_15 -> V_16 )
V_15 -> V_68 = 0 ;
}
} else {
F_16 ( V_3 , V_15 ) ;
if ( V_15 -> V_68 < V_15 -> V_16 ) {
F_35 ( V_3 , V_15 ) ;
( void ) F_84 ( V_3 ) ;
return;
}
if ( F_85 ( V_3 ) == NULL )
V_3 -> V_132 = false ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_131 ++ ;
F_87 ( & V_3 -> V_192 ) ;
}
static void F_88 ( unsigned long V_193 )
{
struct V_2 * V_3 = (struct V_2 * ) V_193 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
T_4 V_194 ;
void * V_195 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
goto V_191;
if ( ! V_15 -> V_69 )
V_3 -> V_196 = V_15 -> V_47 . V_190 ;
if ( V_3 -> V_131 == 0 ) {
F_15 ( & V_3 -> V_38 , V_32 ) ;
return;
}
V_194 = V_15 -> V_47 . V_194 ;
V_195 = V_15 -> V_47 . V_195 ;
if ( ! V_15 -> V_69 ) {
if ( F_22 ( & V_15 -> V_47 ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
} else {
if ( ! V_15 -> V_81 ) {
F_17 ( V_15 ) ;
F_16 ( V_3 , V_15 ) ;
F_28 ( & V_15 -> V_42 , & V_3 -> V_44 ) ;
V_15 -> V_81 = true ;
}
}
}
V_3 -> V_131 -- ;
if ( V_3 -> V_131 )
F_87 ( & V_3 -> V_192 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
if ( V_194 && ( V_15 -> V_47 . V_32 & V_197 ) )
V_194 ( V_195 ) ;
return;
V_191:
if ( V_3 -> V_131 > 0 )
V_3 -> V_131 -- ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static T_5 F_89 ( int V_198 , void * V_193 )
{
static const struct V_199 V_200 [] = {
{ V_201 , V_202 , false , 0 } ,
{ V_203 , V_204 , false , 32 } ,
{ V_205 , V_206 , false , 64 } ,
{ V_207 , V_208 , false , 96 } ,
{ V_209 , V_202 , true , 0 } ,
{ V_210 , V_204 , true , 32 } ,
{ V_211 , V_206 , true , 64 } ,
{ V_212 , V_208 , true , 96 } ,
{ V_213 , V_214 , false , V_7 } ,
{ V_215 , V_214 , true , V_7 } ,
} ;
int V_33 ;
T_2 V_216 [ F_54 ( V_200 ) ] ;
T_2 V_106 ;
T_2 V_217 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_104 * V_8 = V_193 ;
F_14 ( & V_8 -> V_218 , V_32 ) ;
for ( V_33 = 0 ; V_33 < F_54 ( V_200 ) ; V_33 ++ )
V_216 [ V_33 ] = F_56 ( V_8 -> V_9 + V_200 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_90 ( ( unsigned long * ) V_216 ,
V_219 * F_54 ( V_200 ) , V_4 + 1 ) ;
if ( V_4 == V_219 * F_54 ( V_200 ) )
break;
V_217 = V_4 / V_219 ;
V_106 = V_4 & ( V_219 - 1 ) ;
F_30 ( 1 << V_106 , V_8 -> V_9 + V_200 [ V_217 ] . V_220 ) ;
if ( V_200 [ V_217 ] . V_221 == V_7 )
V_3 = V_8 -> V_222 [ V_106 ] ;
else
V_3 = V_8 -> V_223 [ V_200 [ V_217 ] . V_221 + V_106 ] ;
F_91 ( & V_3 -> V_38 ) ;
if ( ! V_200 [ V_217 ] . V_224 )
F_86 ( V_3 ) ;
else
F_92 ( V_8 -> V_5 , L_3 ,
V_4 , V_200 [ V_217 ] . V_221 , V_106 ) ;
F_93 ( & V_3 -> V_38 ) ;
}
F_15 ( & V_8 -> V_218 , V_32 ) ;
return V_225 ;
}
static int F_94 ( struct V_2 * V_3 ,
struct V_226 * V_227 )
{
int V_185 = 0 ;
T_2 V_228 = F_95 ( V_227 -> V_146 ) ;
T_2 V_229 = F_95 ( V_227 -> V_145 ) ;
bool V_17 = V_227 -> V_230 == V_231 ;
if ( ! V_227 -> V_142 ) {
F_61 ( V_3 , L_4 ) ;
V_185 = - V_35 ;
}
if ( V_227 -> V_146 != V_232 &&
V_3 -> V_8 -> V_73 -> V_233 [ V_227 -> V_146 ] == 0 &&
V_3 -> V_234 == 0 ) {
F_61 ( V_3 , L_5 ,
V_227 -> V_146 ) ;
V_185 = - V_35 ;
}
if ( V_227 -> V_145 != V_235 &&
V_3 -> V_8 -> V_73 -> V_236 [ V_227 -> V_145 ] == 0 &&
V_3 -> V_234 == 0 ) {
F_61 ( V_3 , L_6 ,
V_227 -> V_145 ) ;
V_185 = - V_35 ;
}
if ( V_227 -> V_142 == V_237 &&
V_228 == V_232 ) {
F_61 ( V_3 , L_7 ) ;
V_185 = - V_35 ;
}
if ( V_227 -> V_142 == V_143 &&
V_229 == V_235 ) {
F_61 ( V_3 , L_8 ) ;
V_185 = - V_35 ;
}
if ( V_229 == V_235 &&
V_228 == V_232 && V_17 ) {
F_61 ( V_3 , L_9 ) ;
V_185 = - V_35 ;
}
if ( V_227 -> V_142 == V_144 &&
( V_229 != V_228 ) ) {
F_61 ( V_3 , L_10 ) ;
V_185 = - V_35 ;
}
if ( V_227 -> V_142 == V_144 ) {
F_61 ( V_3 , L_11 ) ;
V_185 = - V_35 ;
}
if ( F_41 ( V_17 , V_227 -> V_238 . V_84 ) *
( 1 << V_227 -> V_238 . V_180 ) !=
F_41 ( V_17 , V_227 -> V_179 . V_84 ) *
( 1 << V_227 -> V_179 . V_180 ) ) {
F_61 ( V_3 , L_12 ) ;
V_185 = - V_35 ;
}
return V_185 ;
}
static bool F_96 ( struct V_239 * V_240 ,
bool V_241 , int V_242 , bool V_17 ,
bool * V_243 )
{
unsigned long V_32 ;
F_14 ( & V_240 -> V_38 , V_32 ) ;
* V_243 = ( ( V_240 -> V_244 | V_240 -> V_245 )
== V_246 ) ;
if ( ! V_17 ) {
if ( V_240 -> V_244 == V_246 &&
V_240 -> V_245 == V_246 ) {
V_240 -> V_245 = V_247 ;
V_240 -> V_244 = V_247 ;
goto V_248;
} else
goto V_249;
}
if ( V_241 ) {
if ( V_240 -> V_244 == V_247 )
goto V_249;
if ( V_240 -> V_244 == V_246 )
V_240 -> V_244 = V_250 ;
if ( ! ( V_240 -> V_244 & ( 1 << V_242 ) ) ) {
V_240 -> V_244 |= 1 << V_242 ;
goto V_248;
} else
goto V_249;
} else {
if ( V_240 -> V_245 == V_247 )
goto V_249;
if ( V_240 -> V_245 == V_246 )
V_240 -> V_245 = V_250 ;
if ( ! ( V_240 -> V_245 & ( 1 << V_242 ) ) ) {
V_240 -> V_245 |= 1 << V_242 ;
goto V_248;
} else
goto V_249;
}
V_249:
F_15 ( & V_240 -> V_38 , V_32 ) ;
return false ;
V_248:
F_15 ( & V_240 -> V_38 , V_32 ) ;
return true ;
}
static bool F_97 ( struct V_239 * V_240 , bool V_241 ,
int V_242 )
{
unsigned long V_32 ;
bool V_251 = false ;
F_14 ( & V_240 -> V_38 , V_32 ) ;
if ( ! V_242 ) {
V_240 -> V_245 = V_246 ;
V_240 -> V_244 = V_246 ;
V_251 = true ;
goto V_77;
}
if ( V_241 ) {
V_240 -> V_244 &= ~ ( 1 << V_242 ) ;
if ( V_240 -> V_244 == V_250 )
V_240 -> V_244 = V_246 ;
} else {
V_240 -> V_245 &= ~ ( 1 << V_242 ) ;
if ( V_240 -> V_245 == V_250 )
V_240 -> V_245 = V_246 ;
}
V_251 = ( ( V_240 -> V_244 | V_240 -> V_245 ) ==
V_246 ) ;
V_77:
F_15 ( & V_240 -> V_38 , V_32 ) ;
return V_251 ;
}
static int F_98 ( struct V_2 * V_3 , bool * V_252 )
{
int V_253 ;
int V_254 ;
int V_255 ;
struct V_239 * V_256 ;
int V_33 ;
int V_257 ;
int V_6 ;
bool V_241 ;
bool V_17 = V_3 -> V_141 . V_230 == V_231 ;
V_256 = V_3 -> V_8 -> V_107 ;
if ( V_3 -> V_141 . V_142 == V_143 ) {
V_253 = V_3 -> V_141 . V_145 ;
V_6 = 2 * V_253 ;
V_241 = true ;
} else if ( V_3 -> V_141 . V_142 == V_237 ||
V_3 -> V_141 . V_142 == V_258 ) {
V_253 = V_3 -> V_141 . V_146 ;
V_6 = 2 * V_253 + 1 ;
V_241 = false ;
} else
return - V_35 ;
V_254 = F_95 ( V_253 ) ;
V_255 = F_70 ( V_253 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_141 . V_142 == V_258 ) {
for ( V_33 = 0 ; V_33 < V_3 -> V_8 -> V_105 ; V_33 ++ ) {
if ( F_96 ( & V_256 [ V_33 ] , V_241 ,
0 , V_17 ,
V_252 ) )
goto V_259;
}
} else
for ( V_257 = 0 ; V_257 < V_3 -> V_8 -> V_105 ; V_257 += 8 ) {
int V_260 = V_257 + V_254 * 2 ;
for ( V_33 = V_260 ; V_33 < V_260 + 2 ; V_33 ++ ) {
if ( F_96 ( & V_256 [ V_33 ] ,
V_241 ,
0 ,
V_17 ,
V_252 ) )
goto V_259;
}
}
return - V_35 ;
V_259:
V_3 -> V_11 = & V_256 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_77;
}
if ( V_253 == - 1 )
return - V_35 ;
for ( V_257 = 0 ; V_257 < V_3 -> V_8 -> V_105 ; V_257 += 8 ) {
int V_260 = V_257 + V_254 * 2 ;
if ( V_3 -> V_141 . V_261 ) {
V_33 = V_3 -> V_141 . V_262 ;
if ( ( V_33 != V_260 ) && ( V_33 != V_260 + 1 ) ) {
F_99 ( F_1 ( V_3 ) ,
L_13 , V_33 ) ;
return - V_35 ;
}
if ( F_96 ( & V_256 [ V_33 ] , V_241 , V_255 ,
V_17 , V_252 ) )
goto V_263;
F_99 ( F_1 ( V_3 ) ,
L_14 , V_33 ) ;
return - V_35 ;
}
if ( V_241 ) {
for ( V_33 = V_260 ; V_33 < V_260 + 2 ; V_33 ++ ) {
if ( F_96 ( & V_256 [ V_33 ] , V_241 ,
V_255 , V_17 ,
V_252 ) )
goto V_263;
}
} else {
for ( V_33 = V_260 + 1 ; V_33 >= V_260 ; V_33 -- ) {
if ( F_96 ( & V_256 [ V_33 ] , V_241 ,
V_255 , V_17 ,
V_252 ) )
goto V_263;
}
}
}
return - V_35 ;
V_263:
V_3 -> V_11 = & V_256 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_77:
if ( V_17 )
V_3 -> V_8 -> V_223 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_222 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 )
{
T_6 V_264 = V_3 -> V_4 . V_1 -> V_265 ;
if ( F_101 ( V_266 , V_264 ) && ! F_101 ( V_267 , V_264 ) ) {
V_3 -> V_141 = * V_3 -> V_8 -> V_73 -> V_268 ;
V_3 -> V_141 . V_145 = V_235 ;
V_3 -> V_141 . V_146 = V_3 -> V_8 -> V_73 ->
memcpy [ V_3 -> V_4 . V_269 ] ;
} else if ( F_101 ( V_266 , V_264 ) &&
F_101 ( V_267 , V_264 ) ) {
V_3 -> V_141 = * V_3 -> V_8 -> V_73 -> V_270 ;
} else {
F_61 ( V_3 , L_15 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_185 = 0 ;
T_2 V_134 ;
struct V_239 * V_240 = V_3 -> V_11 ;
bool V_241 ;
F_63 ( V_3 ) ;
if ( V_240 == NULL ) {
F_61 ( V_3 , L_16 ) ;
return - V_35 ;
}
if ( V_240 -> V_244 == V_246 &&
V_240 -> V_245 == V_246 ) {
F_61 ( V_3 , L_17 ) ;
return - V_35 ;
}
if ( V_3 -> V_141 . V_142 == V_237 ||
V_3 -> V_141 . V_142 == V_258 ) {
V_134 = F_70 ( V_3 -> V_141 . V_146 ) ;
V_241 = false ;
} else if ( V_3 -> V_141 . V_142 == V_143 ) {
V_134 = F_70 ( V_3 -> V_141 . V_145 ) ;
V_241 = true ;
} else {
F_61 ( V_3 , L_18 ) ;
return - V_35 ;
}
F_77 ( V_3 -> V_8 -> V_5 ) ;
V_185 = F_55 ( V_3 , V_124 ) ;
if ( V_185 ) {
F_61 ( V_3 , L_19 ) ;
goto V_77;
}
if ( F_3 ( V_3 ) ) {
F_69 ( V_3 , false ) ;
V_3 -> V_8 -> V_223 [ V_3 -> V_6 ] = NULL ;
if ( ! F_97 ( V_240 , V_241 , V_134 ) ) {
if ( F_71 ( V_3 ) ) {
V_185 = F_55 ( V_3 ,
V_186 ) ;
if ( V_185 )
F_61 ( V_3 ,
L_20 ) ;
}
goto V_77;
}
} else {
( void ) F_97 ( V_240 , V_241 , 0 ) ;
}
V_185 = F_55 ( V_3 , V_126 ) ;
if ( V_185 ) {
F_61 ( V_3 , L_21 ) ;
goto V_77;
}
if ( V_3 -> V_132 ) {
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_132 = false ;
V_3 -> V_11 = NULL ;
V_3 -> V_271 = false ;
V_3 -> V_8 -> V_222 [ V_240 -> V_12 ] = NULL ;
V_77:
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
return V_185 ;
}
static bool F_103 ( struct V_2 * V_3 )
{
void T_1 * V_147 = F_4 ( V_3 ) ;
bool V_272 = false ;
unsigned long V_32 ;
void T_1 * V_119 ;
T_2 V_118 ;
T_2 V_134 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( F_2 ( V_3 ) ) {
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_119 = V_3 -> V_8 -> V_9 + V_122 ;
else
V_119 = V_3 -> V_8 -> V_9 + V_123 ;
V_118 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
if ( V_118 == V_125 || V_118 == V_126 )
V_272 = true ;
goto V_273;
}
if ( V_3 -> V_141 . V_142 == V_237 ||
V_3 -> V_141 . V_142 == V_258 ) {
V_134 = F_70 ( V_3 -> V_141 . V_146 ) ;
V_118 = F_56 ( V_147 + V_63 ) ;
} else if ( V_3 -> V_141 . V_142 == V_143 ) {
V_134 = F_70 ( V_3 -> V_141 . V_145 ) ;
V_118 = F_56 ( V_147 + V_59 ) ;
} else {
F_61 ( V_3 , L_18 ) ;
goto V_273;
}
V_118 = ( V_118 & F_66 ( V_134 ) ) >>
F_65 ( V_134 ) ;
if ( V_118 != V_186 )
V_272 = true ;
V_273:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_272 ;
}
static T_2 F_104 ( struct V_274 * V_4 )
{
struct V_2 * V_3 =
F_83 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_275 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_275 = F_74 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_275 ;
}
static int
F_105 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_94 * V_276 , struct V_94 * V_277 ,
unsigned int V_96 , T_7 V_278 ,
T_7 V_279 )
{
struct V_226 * V_280 = & V_4 -> V_141 ;
struct V_281 * V_238 = & V_280 -> V_238 ;
struct V_281 * V_179 = & V_280 -> V_179 ;
int V_34 ;
V_34 = F_106 ( V_276 , V_96 ,
V_278 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_282 . V_283 ,
V_238 -> V_180 ,
V_179 -> V_180 ) ;
V_34 = F_106 ( V_277 , V_96 ,
V_279 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_282 . V_182 ,
V_179 -> V_180 ,
V_238 -> V_180 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_107 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_94 * V_276 , struct V_94 * V_277 ,
unsigned int V_96 , T_7 V_278 ,
T_7 V_279 )
{
struct V_226 * V_280 = & V_4 -> V_141 ;
struct V_281 * V_238 = & V_280 -> V_238 ;
struct V_281 * V_179 = & V_280 -> V_179 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_69 )
V_32 |= V_284 | V_75 ;
V_34 = F_108 ( V_276 , V_96 , V_278 ,
V_43 -> V_30 . V_27 ,
F_109 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_171 ,
V_238 , V_179 , V_32 ) ;
V_34 = F_108 ( V_277 , V_96 , V_279 ,
V_43 -> V_30 . V_28 ,
F_109 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_172 ,
V_179 , V_238 , V_32 ) ;
F_110 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_111 ( struct V_2 * V_4 , struct V_94 * V_97 ,
unsigned int V_96 , unsigned long V_285 )
{
struct V_226 * V_280 = & V_4 -> V_141 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_47 ( V_97 , V_96 , V_280 -> V_238 . V_180 ,
V_280 -> V_179 . V_180 ) ;
if ( V_43 -> V_16 < 0 ) {
F_61 ( V_4 , L_22 ) ;
goto V_191;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_61 ( V_4 , L_23 ) ;
goto V_191;
}
V_43 -> V_68 = 0 ;
V_43 -> V_47 . V_32 = V_285 ;
V_43 -> V_47 . V_286 = F_82 ;
F_112 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_191:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static T_7
F_113 ( struct V_2 * V_4 , enum V_287 V_288 )
{
struct V_289 * V_290 = V_4 -> V_8 -> V_73 ;
struct V_226 * V_280 = & V_4 -> V_141 ;
T_7 V_103 = 0 ;
if ( V_4 -> V_234 )
return V_4 -> V_234 ;
if ( V_288 == V_291 )
V_103 = V_290 -> V_236 [ V_280 -> V_145 ] ;
else if ( V_288 == V_292 )
V_103 = V_290 -> V_233 [ V_280 -> V_146 ] ;
return V_103 ;
}
static struct V_188 *
F_114 ( struct V_274 * V_293 , struct V_94 * V_276 ,
struct V_94 * V_277 , unsigned int V_96 ,
enum V_287 V_288 , unsigned long V_285 )
{
struct V_2 * V_4 = F_83 ( V_293 , struct V_2 , V_4 ) ;
T_7 V_278 = 0 ;
T_7 V_279 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_61 ( V_4 , L_24 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_38 , V_32 ) ;
V_43 = F_111 ( V_4 , V_276 , V_96 , V_285 ) ;
if ( V_43 == NULL )
goto V_191;
if ( F_115 ( & V_276 [ V_96 - 1 ] ) == V_276 )
V_43 -> V_69 = true ;
if ( V_288 != V_294 ) {
T_7 V_295 = F_113 ( V_4 , V_288 ) ;
if ( V_288 == V_291 )
V_278 = V_295 ;
else if ( V_288 == V_292 )
V_279 = V_295 ;
}
if ( F_3 ( V_4 ) )
V_34 = F_105 ( V_4 , V_43 , V_276 , V_277 ,
V_96 , V_278 , V_279 ) ;
else
V_34 = F_107 ( V_4 , V_43 , V_276 , V_277 ,
V_96 , V_278 , V_279 ) ;
if ( V_34 ) {
F_61 ( V_4 , L_25 ,
F_3 ( V_4 ) ? L_26 : L_27 , V_34 ) ;
goto V_191;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_130 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return & V_43 -> V_47 ;
V_191:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return NULL ;
}
bool F_116 ( struct V_274 * V_4 , void * V_193 )
{
struct V_226 * V_296 = V_193 ;
struct V_2 * V_3 =
F_83 ( V_4 , struct V_2 , V_4 ) ;
int V_191 ;
if ( V_193 ) {
V_191 = F_94 ( V_3 , V_296 ) ;
if ( ! V_191 )
V_3 -> V_141 = * V_296 ;
} else
V_191 = F_100 ( V_3 ) ;
if ( ! V_191 )
V_3 -> V_271 = true ;
return V_191 == 0 ;
}
static void F_117 ( struct V_2 * V_3 , int V_253 , bool V_27 )
{
bool V_297 = V_3 -> V_141 . V_297 ;
bool V_298 = V_3 -> V_141 . V_299 ;
T_2 V_300 = V_298 ? V_301 : V_302 ;
T_2 V_303 = V_297 ? V_304 : V_305 ;
T_2 V_134 = F_70 ( V_253 ) ;
T_2 V_306 = F_95 ( V_253 ) ;
T_2 V_307 = 1 << V_134 ;
if ( ! V_27 )
V_307 <<= 16 ;
F_30 ( V_307 , V_3 -> V_8 -> V_9 + V_300 + V_306 * 4 ) ;
F_30 ( V_307 , V_3 -> V_8 -> V_9 + V_303 + V_306 * 4 ) ;
}
static void F_118 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_113 < 3 )
return;
if ( ( V_3 -> V_141 . V_142 == V_143 ) ||
( V_3 -> V_141 . V_142 == V_144 ) )
F_117 ( V_3 , V_3 -> V_141 . V_145 , true ) ;
if ( ( V_3 -> V_141 . V_142 == V_237 ) ||
( V_3 -> V_141 . V_142 == V_144 ) )
F_117 ( V_3 , V_3 -> V_141 . V_146 , false ) ;
}
static int F_119 ( struct V_274 * V_4 )
{
int V_191 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_83 ( V_4 , struct V_2 , V_4 ) ;
bool V_308 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_3 -> V_196 = V_4 -> V_190 = 1 ;
if ( ! V_3 -> V_271 ) {
V_191 = F_100 ( V_3 ) ;
if ( V_191 ) {
F_61 ( V_3 , L_28 ) ;
goto V_309;
}
}
V_191 = F_98 ( V_3 , & V_308 ) ;
if ( V_191 ) {
F_61 ( V_3 , L_29 ) ;
V_3 -> V_271 = false ;
goto V_309;
}
F_77 ( V_3 -> V_8 -> V_5 ) ;
F_120 ( & V_3 -> V_141 , & V_3 -> V_171 ,
& V_3 -> V_172 , F_3 ( V_3 ) ) ;
F_118 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
F_121 ( & V_3 -> V_141 ,
& V_3 -> V_282 . V_283 , & V_3 -> V_282 . V_182 ) ;
if ( V_3 -> V_141 . V_142 == V_143 )
V_3 -> V_76 = V_3 -> V_8 -> V_310 +
V_3 -> V_141 . V_145 * V_311 ;
else
V_3 -> V_76 = V_3 -> V_8 -> V_310 +
V_3 -> V_141 . V_146 *
V_311 + V_312 ;
}
F_67 ( F_1 ( V_3 ) , L_30 ,
F_3 ( V_3 ) ? L_31 : L_32 ,
V_3 -> V_11 -> V_12 ,
V_3 -> V_141 . V_261 ? L_33 : L_34 ) ;
if ( V_308 )
F_73 ( V_3 ) ;
V_309:
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_191 ;
}
static void F_122 ( struct V_274 * V_4 )
{
struct V_2 * V_3 =
F_83 ( V_4 , struct V_2 , V_4 ) ;
int V_191 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_35 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_191 = F_102 ( V_3 ) ;
if ( V_191 )
F_61 ( V_3 , L_36 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static struct V_188 * F_123 ( struct V_274 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_285 )
{
struct V_94 V_313 ;
struct V_94 V_314 ;
F_124 ( & V_313 , 1 ) ;
F_124 ( & V_314 , 1 ) ;
F_125 ( & V_313 ) = V_28 ;
F_125 ( & V_314 ) = V_27 ;
F_49 ( & V_313 ) = V_23 ;
F_49 ( & V_314 ) = V_23 ;
return F_114 ( V_4 , & V_314 , & V_313 , 1 , V_294 , V_285 ) ;
}
static struct V_188 *
F_126 ( struct V_274 * V_4 ,
struct V_94 * V_313 , unsigned int V_315 ,
struct V_94 * V_314 , unsigned int V_316 ,
unsigned long V_285 )
{
if ( V_315 != V_316 )
return NULL ;
return F_114 ( V_4 , V_314 , V_313 , V_316 , V_294 , V_285 ) ;
}
static struct V_188 * F_127 ( struct V_274 * V_4 ,
struct V_94 * V_95 ,
unsigned int V_96 ,
enum V_287 V_288 ,
unsigned long V_285 )
{
if ( V_288 != V_291 && V_288 != V_292 )
return NULL ;
return F_114 ( V_4 , V_95 , V_95 , V_96 , V_288 , V_285 ) ;
}
static struct V_188 *
F_128 ( struct V_274 * V_4 , T_7 V_29 ,
T_8 V_317 , T_8 V_318 ,
enum V_287 V_288 )
{
unsigned int V_319 = V_317 / V_318 ;
struct V_188 * V_47 ;
struct V_94 * V_97 ;
int V_33 ;
V_97 = F_129 ( V_319 + 1 , sizeof( struct V_94 ) , V_24 ) ;
for ( V_33 = 0 ; V_33 < V_319 ; V_33 ++ ) {
F_125 ( & V_97 [ V_33 ] ) = V_29 ;
F_49 ( & V_97 [ V_33 ] ) = V_318 ;
V_29 += V_318 ;
}
V_97 [ V_319 ] . V_221 = 0 ;
V_97 [ V_319 ] . V_320 = 0 ;
V_97 [ V_319 ] . V_321 =
( ( unsigned long ) V_97 | 0x01 ) & ~ 0x02 ;
V_47 = F_114 ( V_4 , V_97 , V_97 , V_319 , V_288 ,
V_197 ) ;
F_10 ( V_97 ) ;
return V_47 ;
}
static enum V_322 F_130 ( struct V_274 * V_4 ,
T_3 V_190 ,
struct V_323 * V_324 )
{
struct V_2 * V_3 = F_83 ( V_4 , struct V_2 , V_4 ) ;
T_3 V_325 ;
T_3 V_326 ;
int V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_37 ) ;
return - V_35 ;
}
V_326 = V_3 -> V_196 ;
V_325 = V_4 -> V_190 ;
if ( F_103 ( V_3 ) )
V_34 = V_327 ;
else
V_34 = F_131 ( V_190 , V_326 , V_325 ) ;
F_132 ( V_324 , V_326 , V_325 ,
F_104 ( V_4 ) ) ;
return V_34 ;
}
static void F_133 ( struct V_274 * V_4 )
{
struct V_2 * V_3 = F_83 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_38 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_134 ( & V_3 -> V_82 , & V_3 -> V_83 ) ;
if ( ! V_3 -> V_132 )
( void ) F_85 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static int
F_135 ( struct V_2 * V_3 ,
struct V_281 * V_296 ,
enum V_328 V_329 ,
T_2 V_330 )
{
enum V_331 V_332 ;
int V_84 ;
switch ( V_329 ) {
case V_333 :
V_332 = V_334 ;
break;
case V_335 :
V_332 = V_336 ;
break;
case V_337 :
V_332 = V_338 ;
break;
case V_339 :
V_332 = V_340 ;
break;
default:
F_99 ( V_3 -> V_8 -> V_5 ,
L_39
L_40 ,
V_329 ) ;
return - V_35 ;
}
if ( F_3 ( V_3 ) ) {
if ( V_330 >= 16 )
V_84 = V_341 ;
else if ( V_330 >= 8 )
V_84 = V_342 ;
else if ( V_330 >= 4 )
V_84 = V_343 ;
else
V_84 = V_85 ;
} else {
if ( V_330 >= 16 )
V_84 = V_344 ;
else if ( V_330 >= 8 )
V_84 = V_345 ;
else if ( V_330 >= 4 )
V_84 = V_346 ;
else
V_84 = V_86 ;
}
V_296 -> V_180 = V_332 ;
V_296 -> V_84 = V_84 ;
V_296 -> V_347 = V_348 ;
return 0 ;
}
static int F_136 ( struct V_274 * V_4 ,
struct V_349 * V_350 )
{
struct V_2 * V_3 = F_83 ( V_4 , struct V_2 , V_4 ) ;
struct V_226 * V_280 = & V_3 -> V_141 ;
enum V_328 V_351 , V_352 ;
T_7 V_353 ;
T_2 V_354 , V_355 ;
int V_34 ;
V_351 = V_350 -> V_351 ;
V_354 = V_350 -> V_354 ;
V_352 = V_350 -> V_352 ;
V_355 = V_350 -> V_355 ;
if ( V_350 -> V_288 == V_291 ) {
T_7 V_356 =
V_3 -> V_8 -> V_73 -> V_236 [ V_280 -> V_145 ] ;
V_353 = V_350 -> V_357 ;
if ( V_356 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_41
L_42 ,
V_356 , V_353 ) ;
if ( V_280 -> V_142 != V_143 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_43
L_44 ,
V_280 -> V_142 ) ;
V_280 -> V_142 = V_143 ;
if ( V_352 == V_358 )
V_352 = V_351 ;
if ( V_355 == 0 )
V_355 = V_354 ;
} else if ( V_350 -> V_288 == V_292 ) {
T_7 V_359 =
V_3 -> V_8 -> V_73 -> V_233 [ V_280 -> V_146 ] ;
V_353 = V_350 -> V_360 ;
if ( V_359 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_45
L_42 ,
V_359 , V_353 ) ;
if ( V_280 -> V_142 != V_237 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_46
L_47 ,
V_280 -> V_142 ) ;
V_280 -> V_142 = V_237 ;
if ( V_351 == V_358 )
V_351 = V_352 ;
if ( V_354 == 0 )
V_354 = V_355 ;
} else {
F_99 ( V_3 -> V_8 -> V_5 ,
L_48 ,
V_350 -> V_288 ) ;
return - V_35 ;
}
if ( V_354 * V_351 != V_355 * V_352 ) {
F_99 ( V_3 -> V_8 -> V_5 ,
L_49 ,
V_354 ,
V_351 ,
V_355 ,
V_352 ) ;
return - V_35 ;
}
V_34 = F_135 ( V_3 , & V_280 -> V_238 ,
V_351 ,
V_354 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_135 ( V_3 , & V_280 -> V_179 ,
V_352 ,
V_355 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_121 ( V_280 , & V_3 -> V_282 . V_283 , & V_3 -> V_282 . V_182 ) ;
else
F_120 ( V_280 , & V_3 -> V_171 ,
& V_3 -> V_172 , false ) ;
V_3 -> V_234 = V_353 ;
V_3 -> V_361 = V_350 -> V_288 ;
F_67 ( V_3 -> V_8 -> V_5 ,
L_50
L_51 ,
F_137 ( V_4 ) ,
( V_350 -> V_288 == V_291 ) ? L_52 : L_53 ,
V_351 , V_352 ,
V_354 , V_355 ) ;
return 0 ;
}
static int F_138 ( struct V_274 * V_4 , enum V_362 V_363 ,
unsigned long V_364 )
{
struct V_2 * V_3 = F_83 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_38 ) ;
return - V_35 ;
}
switch ( V_363 ) {
case V_365 :
return F_81 ( V_3 ) ;
case V_366 :
return F_76 ( V_3 ) ;
case V_367 :
return F_80 ( V_3 ) ;
case V_368 :
return F_136 ( V_4 ,
(struct V_349 * ) V_364 ) ;
default:
break;
}
return - V_369 ;
}
static void T_9 F_139 ( struct V_104 * V_8 , struct V_370 * V_371 ,
struct V_2 * V_372 , int V_221 ,
int V_373 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_371 -> V_374 ) ;
for ( V_33 = V_221 ; V_33 < V_221 + V_373 ; V_33 ++ ) {
V_3 = & V_372 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_371 ;
F_140 ( & V_3 -> V_38 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_83 ) ;
F_24 ( & V_3 -> V_82 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_130 ) ;
F_141 ( & V_3 -> V_192 , F_88 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_375 ,
& V_371 -> V_374 ) ;
}
}
static void F_142 ( struct V_104 * V_8 , struct V_370 * V_5 )
{
if ( F_101 ( V_267 , V_5 -> V_265 ) )
V_5 -> V_376 = F_127 ;
if ( F_101 ( V_266 , V_5 -> V_265 ) ) {
V_5 -> V_377 = F_123 ;
V_5 -> V_378 = 2 ;
}
if ( F_101 ( V_379 , V_5 -> V_265 ) )
V_5 -> V_380 = F_126 ;
if ( F_101 ( V_381 , V_5 -> V_265 ) )
V_5 -> V_382 = F_128 ;
V_5 -> V_383 = F_119 ;
V_5 -> V_384 = F_122 ;
V_5 -> V_385 = F_133 ;
V_5 -> V_386 = F_130 ;
V_5 -> V_387 = F_138 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_143 ( struct V_104 * V_8 ,
int V_388 )
{
int V_191 ;
F_139 ( V_8 , & V_8 -> V_389 , V_8 -> V_390 ,
0 , V_8 -> V_391 ) ;
F_144 ( V_8 -> V_389 . V_265 ) ;
F_145 ( V_267 , V_8 -> V_389 . V_265 ) ;
F_145 ( V_381 , V_8 -> V_389 . V_265 ) ;
F_142 ( V_8 , & V_8 -> V_389 ) ;
V_191 = F_146 ( & V_8 -> V_389 ) ;
if ( V_191 ) {
F_92 ( V_8 -> V_5 , L_54 ) ;
goto V_392;
}
F_139 ( V_8 , & V_8 -> V_393 , V_8 -> V_390 ,
V_8 -> V_391 , V_8 -> V_73 -> V_394 ) ;
F_144 ( V_8 -> V_393 . V_265 ) ;
F_145 ( V_266 , V_8 -> V_393 . V_265 ) ;
F_145 ( V_379 , V_8 -> V_393 . V_265 ) ;
F_142 ( V_8 , & V_8 -> V_393 ) ;
V_191 = F_146 ( & V_8 -> V_393 ) ;
if ( V_191 ) {
F_92 ( V_8 -> V_5 ,
L_55 ) ;
goto V_395;
}
F_139 ( V_8 , & V_8 -> V_396 , V_8 -> V_397 ,
0 , V_388 ) ;
F_144 ( V_8 -> V_396 . V_265 ) ;
F_145 ( V_267 , V_8 -> V_396 . V_265 ) ;
F_145 ( V_266 , V_8 -> V_396 . V_265 ) ;
F_145 ( V_379 , V_8 -> V_396 . V_265 ) ;
F_145 ( V_381 , V_8 -> V_389 . V_265 ) ;
F_142 ( V_8 , & V_8 -> V_396 ) ;
V_191 = F_146 ( & V_8 -> V_396 ) ;
if ( V_191 ) {
F_92 ( V_8 -> V_5 ,
L_56 ) ;
goto V_398;
}
return 0 ;
V_398:
F_147 ( & V_8 -> V_393 ) ;
V_395:
F_147 ( & V_8 -> V_389 ) ;
V_392:
return V_191 ;
}
static int F_148 ( struct V_1 * V_5 )
{
struct V_399 * V_400 = F_149 ( V_5 ) ;
struct V_104 * V_8 = F_150 ( V_400 ) ;
int V_34 = 0 ;
if ( ! F_151 ( V_5 ) )
return - V_129 ;
if ( V_8 -> V_401 )
V_34 = F_152 ( V_8 -> V_401 ) ;
return V_34 ;
}
static int F_153 ( struct V_1 * V_5 )
{
struct V_399 * V_400 = F_149 ( V_5 ) ;
struct V_104 * V_8 = F_150 ( V_400 ) ;
F_53 ( V_8 , true ) ;
if ( V_8 -> V_113 != 1 )
F_52 ( V_8 -> V_402 ,
V_8 -> V_9 + V_403 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_5 )
{
struct V_399 * V_400 = F_149 ( V_5 ) ;
struct V_104 * V_8 = F_150 ( V_400 ) ;
if ( V_8 -> V_404 )
F_53 ( V_8 , false ) ;
F_52 ( V_405 ,
V_8 -> V_9 + V_403 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_5 )
{
struct V_399 * V_400 = F_149 ( V_5 ) ;
struct V_104 * V_8 = F_150 ( V_400 ) ;
int V_34 = 0 ;
if ( V_8 -> V_401 )
V_34 = F_156 ( V_8 -> V_401 ) ;
return V_34 ;
}
static int T_9 F_157 ( struct V_104 * V_8 )
{
int V_33 ;
int V_406 = 0 ;
T_2 V_148 [ 2 ] ;
int V_407 = - 2 ;
int V_408 = V_409 ;
V_148 [ 0 ] = F_56 ( V_8 -> V_9 + V_410 ) ;
V_148 [ 1 ] = F_56 ( V_8 -> V_9 + V_411 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
V_8 -> V_107 [ V_33 ] . V_12 = V_33 ;
V_407 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_148 [ V_33 % 2 ] >> V_407 ) & 3 ) == 1 ) {
V_8 -> V_107 [ V_33 ] . V_244 = V_247 ;
V_8 -> V_107 [ V_33 ] . V_245 = V_247 ;
V_8 -> V_107 [ V_33 ] . V_108 = true ;
V_408 |= F_158 ( F_159 ( V_33 ) ,
V_412 ) ;
V_408 |= F_158 ( F_159 ( V_33 ) ,
V_413 ) ;
} else {
V_8 -> V_107 [ V_33 ] . V_244 = V_246 ;
V_8 -> V_107 [ V_33 ] . V_245 = V_246 ;
V_8 -> V_107 [ V_33 ] . V_108 = false ;
V_406 ++ ;
}
F_140 ( & V_8 -> V_107 [ V_33 ] . V_38 ) ;
}
for ( V_33 = 0 ; V_8 -> V_73 -> V_414 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_73 -> V_414 [ V_33 ] ;
V_8 -> V_107 [ V_4 ] . V_244 = V_247 ;
V_8 -> V_107 [ V_4 ] . V_245 = V_247 ;
V_8 -> V_107 [ V_4 ] . V_108 = true ;
V_408 |= F_158 ( F_159 ( V_4 ) ,
V_412 ) ;
V_408 |= F_158 ( F_159 ( V_4 ) ,
V_413 ) ;
V_406 -- ;
}
F_160 ( V_8 -> V_5 , L_57 ,
V_406 , V_8 -> V_105 ) ;
V_148 [ 0 ] = F_56 ( V_8 -> V_9 + V_415 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
if ( V_8 -> V_107 [ V_33 ] . V_244 == V_246 &&
( V_148 [ 0 ] & 0x3 ) != 1 )
F_160 ( V_8 -> V_5 ,
L_58 ,
V_139 , V_33 , V_148 [ 0 ] & 0x3 ) ;
V_148 [ 0 ] = V_148 [ 0 ] >> 2 ;
}
F_30 ( V_405 , V_8 -> V_9 + V_403 ) ;
V_8 -> V_402 = V_408 ;
return V_406 ;
}
static struct V_104 * T_9 F_161 ( struct V_399 * V_400 )
{
struct V_289 * V_73 ;
struct V_416 * V_416 = NULL ;
void T_1 * V_9 = NULL ;
struct V_417 * V_185 = NULL ;
struct V_104 * V_8 = NULL ;
int V_391 = 0 ;
int V_105 ;
int V_33 ;
T_2 V_418 ;
T_2 V_419 ;
T_10 V_113 ;
V_416 = F_162 ( & V_400 -> V_5 , NULL ) ;
if ( F_163 ( V_416 ) ) {
F_92 ( & V_400 -> V_5 , L_59 ) ;
goto V_420;
}
F_164 ( V_416 ) ;
V_185 = F_165 ( V_400 , V_421 , L_60 ) ;
if ( ! V_185 )
goto V_420;
if ( F_166 ( V_185 -> V_422 , F_167 ( V_185 ) ,
V_423 L_61 ) == NULL )
goto V_420;
V_9 = F_168 ( V_185 -> V_422 , F_167 ( V_185 ) ) ;
if ( ! V_9 )
goto V_420;
for ( V_418 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_418 |= ( F_56 ( V_9 + F_167 ( V_185 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_419 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_419 |= ( F_56 ( V_9 + F_167 ( V_185 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_419 != V_424 ) {
F_92 ( & V_400 -> V_5 , L_62 ) ;
goto V_420;
}
if ( F_169 ( V_418 ) != V_425 ) {
F_92 ( & V_400 -> V_5 , L_63 ,
F_169 ( V_418 ) ,
V_425 ) ;
goto V_420;
}
V_113 = F_170 ( V_418 ) ;
V_105 = 4 * ( F_56 ( V_9 + V_426 ) & 0x7 ) + 4 ;
F_160 ( & V_400 -> V_5 , L_64 ,
V_113 , V_185 -> V_422 ) ;
V_73 = V_400 -> V_5 . V_427 ;
for ( V_33 = 0 ; V_33 < V_73 -> V_428 ; V_33 ++ )
if ( V_73 -> V_236 [ V_33 ] != 0 )
V_391 ++ ;
for ( V_33 = 0 ; V_33 < V_73 -> V_428 ; V_33 ++ )
if ( V_73 -> V_233 [ V_33 ] != 0 )
V_391 ++ ;
V_8 = F_171 ( F_45 ( sizeof( struct V_104 ) , 4 ) +
( V_105 + V_391 + V_73 -> V_394 ) *
sizeof( struct V_2 ) , V_429 ) ;
if ( V_8 == NULL ) {
F_92 ( & V_400 -> V_5 , L_65 ) ;
goto V_420;
}
V_8 -> V_113 = V_113 ;
V_8 -> V_416 = V_416 ;
V_8 -> V_105 = V_105 ;
V_8 -> V_391 = V_391 ;
V_8 -> V_430 = V_185 -> V_422 ;
V_8 -> V_431 = F_167 ( V_185 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_73 = V_73 ;
V_8 -> V_5 = & V_400 -> V_5 ;
V_8 -> V_397 = ( ( void * ) V_8 ) + F_45 ( sizeof( struct V_104 ) , 4 ) ;
V_8 -> V_390 = & V_8 -> V_397 [ V_105 ] ;
V_8 -> V_107 = F_171 ( V_105 * sizeof( struct V_239 ) ,
V_429 ) ;
if ( ! V_8 -> V_107 )
goto V_420;
V_8 -> V_222 = F_171 ( V_105 *
sizeof( struct V_2 * ) ,
V_429 ) ;
if ( ! V_8 -> V_222 )
goto V_420;
if ( V_391 + V_73 -> V_394 ) {
V_8 -> V_223 = F_171 ( V_73 -> V_428 * 2 *
sizeof( struct V_2 * ) ,
V_429 ) ;
if ( ! V_8 -> V_223 )
goto V_420;
}
V_8 -> V_110 = F_6 ( V_8 -> V_105 *
sizeof( V_109 ) ,
V_429 ) ;
if ( ! V_8 -> V_110 )
goto V_420;
V_8 -> V_37 . V_40 =
F_171 ( V_105 * sizeof( struct V_14 * )
* V_39 , V_429 ) ;
if ( ! V_8 -> V_37 . V_40 )
goto V_420;
V_8 -> V_48 = F_172 ( V_423 , sizeof( struct V_14 ) ,
0 , V_432 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_420;
return V_8 ;
V_420:
if ( ! F_163 ( V_416 ) ) {
F_173 ( V_416 ) ;
F_174 ( V_416 ) ;
}
if ( V_9 )
F_175 ( V_9 ) ;
if ( V_185 )
F_176 ( V_185 -> V_422 ,
F_167 ( V_185 ) ) ;
if ( V_9 )
F_175 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_223 ) ;
F_10 ( V_8 -> V_222 ) ;
F_10 ( V_8 -> V_107 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_177 ( struct V_104 * V_8 )
{
static struct V_433 V_434 [] = {
{ . V_135 = V_403 , . V_148 = V_405 } ,
{ . V_135 = V_435 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_436 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_437 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_438 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_202 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_204 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_206 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_208 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_201 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_203 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_205 , . V_148 = 0xFFFFFFFF } ,
{ . V_135 = V_207 , . V_148 = 0xFFFFFFFF }
} ;
int V_33 ;
T_2 V_439 [ 2 ] = { 0 , 0 } ;
T_2 V_440 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_441 = 0 ;
T_2 V_442 = 0 ;
for ( V_33 = 0 ; V_33 < F_54 ( V_434 ) ; V_33 ++ )
F_30 ( V_434 [ V_33 ] . V_148 ,
V_8 -> V_9 + V_434 [ V_33 ] . V_135 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
V_440 [ V_33 % 2 ] = V_440 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_107 [ V_8 -> V_105 - V_33 - 1 ] . V_244
== V_247 ) {
V_440 [ V_33 % 2 ] |= 3 ;
continue;
}
V_441 = ( V_441 << 1 ) | 1 ;
V_442 = ( V_442 << 1 ) | 1 ;
V_439 [ V_33 % 2 ] = V_439 [ V_33 % 2 ] << 2 ;
V_439 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_439 [ 1 ] , V_8 -> V_9 + V_166 ) ;
F_30 ( V_439 [ 0 ] , V_8 -> V_9 + V_443 ) ;
F_30 ( V_440 [ 1 ] , V_8 -> V_9 + V_122 ) ;
F_30 ( V_440 [ 0 ] , V_8 -> V_9 + V_123 ) ;
F_30 ( V_441 , V_8 -> V_9 + V_444 ) ;
F_30 ( V_442 , V_8 -> V_9 + V_214 ) ;
}
static int T_9 F_178 ( struct V_104 * V_8 )
{
struct V_64 * V_65 = & V_8 -> V_37 ;
unsigned long * V_445 ;
int V_33 , V_257 ;
int V_34 = 0 ;
V_445 = F_6 ( sizeof( unsigned long ) * V_446 ,
V_429 ) ;
if ( ! V_445 ) {
V_34 = - V_25 ;
goto V_420;
}
V_8 -> V_37 . V_447 = V_448 * V_8 -> V_105 / V_449 ;
for ( V_33 = 0 ; V_33 < V_446 ; V_33 ++ ) {
V_445 [ V_33 ] = F_179 ( V_429 ,
V_8 -> V_37 . V_447 ) ;
if ( ! V_445 [ V_33 ] ) {
F_92 ( V_8 -> V_5 , L_66 ,
V_8 -> V_37 . V_447 ) ;
for ( V_257 = 0 ; V_257 < V_33 ; V_257 ++ )
F_180 ( V_445 [ V_257 ] , V_8 -> V_37 . V_447 ) ;
goto V_420;
}
if ( ( F_109 ( ( void * ) V_445 [ V_33 ] ) &
( V_450 - 1 ) ) == 0 )
break;
}
for ( V_257 = 0 ; V_257 < V_33 ; V_257 ++ )
F_180 ( V_445 [ V_257 ] , V_8 -> V_37 . V_447 ) ;
if ( V_33 < V_446 ) {
V_8 -> V_37 . V_8 = ( void * ) V_445 [ V_33 ] ;
} else {
F_181 ( V_8 -> V_5 ,
L_67 ,
V_139 , V_8 -> V_37 . V_447 ) ;
V_8 -> V_37 . V_451 = F_6 ( V_448 *
V_8 -> V_105 +
V_450 ,
V_429 ) ;
if ( ! V_8 -> V_37 . V_451 ) {
V_34 = - V_25 ;
goto V_420;
}
V_8 -> V_37 . V_8 = F_7 ( V_8 -> V_37 . V_451 ,
V_450 ) ;
}
V_65 -> V_29 = F_8 ( V_8 -> V_5 , V_65 -> V_8 ,
V_448 * V_8 -> V_105 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_65 -> V_29 ) ) {
V_65 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_420;
}
F_30 ( F_109 ( V_8 -> V_37 . V_8 ) ,
V_8 -> V_9 + V_452 ) ;
V_420:
F_10 ( V_445 ) ;
return V_34 ;
}
static int T_9 F_182 ( struct V_399 * V_400 )
{
int V_191 ;
int V_34 = - V_453 ;
struct V_104 * V_8 ;
struct V_417 * V_185 = NULL ;
int V_388 ;
T_2 V_148 ;
V_8 = F_161 ( V_400 ) ;
if ( ! V_8 )
goto V_420;
V_388 = F_157 ( V_8 ) ;
F_183 ( V_400 , V_8 ) ;
F_140 ( & V_8 -> V_218 ) ;
F_140 ( & V_8 -> V_121 ) ;
V_185 = F_165 ( V_400 , V_421 , L_68 ) ;
if ( ! V_185 ) {
V_34 = - V_453 ;
F_92 ( & V_400 -> V_5 , L_69 ) ;
goto V_420;
}
V_8 -> V_454 = F_167 ( V_185 ) ;
V_8 -> V_455 = V_185 -> V_422 ;
if ( F_166 ( V_185 -> V_422 , F_167 ( V_185 ) ,
V_423 L_70 ) == NULL ) {
V_34 = - V_129 ;
F_92 ( & V_400 -> V_5 ,
L_71 ,
V_185 -> V_422 , V_185 -> V_456 ) ;
goto V_420;
}
V_148 = F_56 ( V_8 -> V_9 + V_457 ) ;
if ( V_185 -> V_422 != V_148 && V_148 != 0 ) {
F_181 ( & V_400 -> V_5 ,
L_72 ,
V_139 , V_148 , V_185 -> V_422 ) ;
} else
F_30 ( V_185 -> V_422 , V_8 -> V_9 + V_457 ) ;
V_8 -> V_310 = F_168 ( V_185 -> V_422 , F_167 ( V_185 ) ) ;
if ( ! V_8 -> V_310 ) {
V_34 = - V_25 ;
F_92 ( & V_400 -> V_5 , L_73 ) ;
goto V_420;
}
if ( V_8 -> V_73 -> V_72 ) {
V_185 = F_165 ( V_400 , V_421 ,
L_74 ) ;
if ( ! V_185 ) {
V_34 = - V_453 ;
F_92 ( & V_400 -> V_5 ,
L_75 ) ;
goto V_420;
}
V_8 -> V_37 . V_8 = F_168 ( V_185 -> V_422 ,
F_167 ( V_185 ) ) ;
if ( ! V_8 -> V_37 . V_8 ) {
V_34 = - V_25 ;
F_92 ( & V_400 -> V_5 , L_76 ) ;
goto V_420;
}
F_30 ( V_185 -> V_422 , V_8 -> V_9 + V_452 ) ;
} else {
V_34 = F_178 ( V_8 ) ;
if ( V_34 ) {
F_92 ( & V_400 -> V_5 , L_77 ) ;
goto V_420;
}
}
F_140 ( & V_8 -> V_37 . V_38 ) ;
V_8 -> V_198 = F_184 ( V_400 , 0 ) ;
V_34 = F_185 ( V_8 -> V_198 , F_89 , 0 , V_423 , V_8 ) ;
if ( V_34 ) {
F_92 ( & V_400 -> V_5 , L_78 ) ;
goto V_420;
}
F_186 ( V_8 -> V_5 ) ;
F_187 ( V_8 -> V_5 , V_458 ) ;
F_188 ( V_8 -> V_5 ) ;
F_189 ( V_8 -> V_5 ) ;
F_190 ( V_8 -> V_5 ) ;
if ( V_8 -> V_73 -> V_72 ) {
V_8 -> V_401 = F_191 ( V_8 -> V_5 , L_74 ) ;
if ( F_163 ( V_8 -> V_401 ) ) {
F_92 ( & V_400 -> V_5 , L_79 ) ;
V_8 -> V_401 = NULL ;
goto V_420;
}
V_34 = F_156 ( V_8 -> V_401 ) ;
if ( V_34 ) {
F_92 ( & V_400 -> V_5 ,
L_80 ) ;
F_192 ( V_8 -> V_401 ) ;
V_8 -> V_401 = NULL ;
goto V_420;
}
}
V_8 -> V_404 = true ;
V_191 = F_143 ( V_8 , V_388 ) ;
if ( V_191 )
goto V_420;
F_177 ( V_8 ) ;
F_160 ( V_8 -> V_5 , L_81 ) ;
return 0 ;
V_420:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_193 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_175 ( V_8 -> V_9 ) ;
if ( V_8 -> V_37 . V_8 && V_8 -> V_73 -> V_72 ) {
F_175 ( V_8 -> V_37 . V_8 ) ;
V_8 -> V_37 . V_8 = NULL ;
}
if ( V_8 -> V_37 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_37 . V_29 ,
V_448 * V_8 -> V_105 ,
V_31 ) ;
if ( ! V_8 -> V_37 . V_451 && V_8 -> V_37 . V_8 )
F_180 ( ( unsigned long ) V_8 -> V_37 . V_8 ,
V_8 -> V_37 . V_447 ) ;
F_10 ( V_8 -> V_37 . V_451 ) ;
if ( V_8 -> V_455 )
F_176 ( V_8 -> V_455 ,
V_8 -> V_454 ) ;
if ( V_8 -> V_430 )
F_176 ( V_8 -> V_430 ,
V_8 -> V_431 ) ;
if ( V_8 -> V_416 ) {
F_173 ( V_8 -> V_416 ) ;
F_174 ( V_8 -> V_416 ) ;
}
if ( V_8 -> V_401 ) {
F_152 ( V_8 -> V_401 ) ;
F_192 ( V_8 -> V_401 ) ;
}
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_223 ) ;
F_10 ( V_8 -> V_222 ) ;
F_10 ( V_8 -> V_107 ) ;
F_10 ( V_8 ) ;
}
F_92 ( & V_400 -> V_5 , L_82 ) ;
return V_34 ;
}
static int T_9 F_194 ( void )
{
return F_195 ( & V_459 , F_182 ) ;
}
