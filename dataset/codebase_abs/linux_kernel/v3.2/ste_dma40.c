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
F_21 (d, _d, &d40c->client, node)
if ( F_22 ( & V_45 -> V_47 ) ) {
F_17 ( V_45 ) ;
V_43 = V_45 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
break;
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
bool V_72 ;
V_72 = V_69 && V_68 == 0 ;
if ( V_72 || ( V_16 - V_68 > 1 ) ) {
V_70 = F_13 ( V_4 , V_43 ) ;
V_71 = V_70 ;
}
if ( ! V_72 || V_70 == - V_35 ) {
unsigned int V_32 = 0 ;
if ( V_70 == - V_35 )
V_32 |= V_73 ;
F_32 ( V_4 -> V_74 ,
& V_67 -> V_28 [ V_68 ] ,
& V_67 -> V_27 [ V_68 ] ,
V_70 ,
V_32 ) ;
V_68 ++ ;
}
if ( V_70 < 0 )
goto V_75;
for (; V_68 < V_16 ; V_68 ++ ) {
unsigned int V_76 = V_4 -> V_11 -> V_12 * 1024 +
8 * V_70 * 2 ;
struct V_19 * V_77 = V_65 -> V_8 + V_76 ;
unsigned int V_32 = 0 ;
int V_78 ;
if ( V_68 + 1 < V_16 )
V_78 = F_13 ( V_4 , V_43 ) ;
else
V_78 = V_72 ? V_71 : - V_35 ;
if ( V_69 || V_78 == - V_35 )
V_32 |= V_73 ;
if ( V_72 && V_70 == V_71 ) {
F_32 ( V_4 -> V_74 ,
& V_67 -> V_28 [ V_68 ] ,
& V_67 -> V_27 [ V_68 ] ,
V_78 , V_32 ) ;
}
F_33 ( V_77 ,
& V_67 -> V_28 [ V_68 ] ,
& V_67 -> V_27 [ V_68 ] ,
V_78 , V_32 ) ;
F_34 ( V_4 -> V_8 -> V_5 ,
V_65 -> V_29 , V_76 ,
2 * sizeof( struct V_19 ) ,
V_31 ) ;
V_70 = V_78 ;
if ( V_70 == - V_35 || V_70 == V_71 ) {
V_68 ++ ;
break;
}
}
V_75:
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
V_43 -> V_79 = false ;
F_28 ( & V_43 -> V_42 , & V_3 -> V_80 ) ;
}
static struct V_14 * F_39 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_80 ) )
return NULL ;
V_45 = F_37 ( & V_3 -> V_80 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static struct V_14 * F_40 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_81 ) )
return NULL ;
V_45 = F_37 ( & V_3 -> V_81 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static int F_41 ( bool V_17 , int V_82 )
{
if ( V_17 ) {
if ( V_82 == V_83 )
return 1 ;
} else {
if ( V_82 == V_84 )
return 1 ;
}
return 2 << V_82 ;
}
static int F_42 ( int V_23 , T_2 V_85 , T_2 V_86 )
{
int V_87 ;
T_2 V_88 = F_43 ( V_85 , V_86 ) ;
T_2 V_89 = F_44 ( V_85 , V_86 ) ;
T_2 V_90 = F_45 ( V_91 << V_89 , 1 << V_88 ) ;
if ( V_90 > V_91 )
V_90 -= ( 1 << V_88 ) ;
if ( ! F_46 ( V_23 , 1 << V_88 ) )
return - V_35 ;
if ( V_23 <= V_90 )
V_87 = 1 ;
else {
V_87 = V_23 / V_90 ;
if ( V_87 * V_90 < V_23 )
V_87 ++ ;
}
return V_87 ;
}
static int F_47 ( struct V_92 * V_93 , int V_94 ,
T_2 V_85 , T_2 V_86 )
{
struct V_92 * V_95 ;
int V_33 ;
int V_96 = 0 ;
int V_34 ;
F_48 (sgl, sg, sg_len, i) {
V_34 = F_42 ( F_49 ( V_95 ) ,
V_85 , V_86 ) ;
if ( V_34 < 0 )
return V_34 ;
V_96 += V_34 ;
}
return V_96 ;
}
static int F_50 ( struct V_2 * V_3 ,
enum V_97 V_98 )
{
T_2 V_99 ;
int V_33 ;
void T_1 * V_100 ;
int V_34 = 0 ;
unsigned long V_32 ;
T_2 V_101 ;
F_14 ( & V_3 -> V_8 -> V_102 , V_32 ) ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_100 = V_3 -> V_8 -> V_9 + V_103 ;
else
V_100 = V_3 -> V_8 -> V_9 + V_104 ;
if ( V_98 == V_105 ) {
V_99 = ( F_51 ( V_100 ) &
F_52 ( V_3 -> V_11 -> V_12 ) ) >>
F_53 ( V_3 -> V_11 -> V_12 ) ;
if ( V_99 == V_106 || V_99 == V_107 )
goto V_108;
}
V_101 = 0xffffffff & ~ ( F_52 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_101 | ( V_98 << F_53 ( V_3 -> V_11 -> V_12 ) ) ,
V_100 ) ;
if ( V_98 == V_105 ) {
for ( V_33 = 0 ; V_33 < V_109 ; V_33 ++ ) {
V_99 = ( F_51 ( V_100 ) &
F_52 ( V_3 -> V_11 -> V_12 ) ) >>
F_53 ( V_3 -> V_11 -> V_12 ) ;
F_54 () ;
F_55 ( 3 ) ;
if ( V_99 == V_107 ||
V_99 == V_106 )
break;
}
if ( V_33 == V_109 ) {
F_56 ( V_3 ,
L_1 ,
V_3 -> V_11 -> V_12 , V_3 -> V_6 ,
V_99 ) ;
F_57 () ;
V_34 = - V_110 ;
}
}
V_108:
F_15 ( & V_3 -> V_8 -> V_102 , V_32 ) ;
return V_34 ;
}
static void F_58 ( struct V_2 * V_3 )
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
if ( ! F_20 ( & V_3 -> V_111 ) )
F_21 (d40d, _d,
&d40c->prepare_queue, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
V_3 -> V_112 = 0 ;
V_3 -> V_113 = false ;
}
static void F_59 ( struct V_2 * V_3 , bool V_114 ,
T_2 V_115 , int V_116 )
{
void T_1 * V_117 = F_4 ( V_3 ) + V_116 ;
int V_118 ;
if ( ! V_114 ) {
F_30 ( ( V_119 << F_60 ( V_115 ) )
| ~ F_61 ( V_115 ) , V_117 ) ;
return;
}
V_118 = 100 ;
while ( -- V_118 ) {
F_30 ( ( V_120 << F_60 ( V_115 ) )
| ~ F_61 ( V_115 ) , V_117 ) ;
if ( F_51 ( V_117 ) & F_61 ( V_115 ) )
break;
}
if ( V_118 != 99 )
F_62 ( F_1 ( V_3 ) ,
L_2 ,
V_121 , V_116 == V_59 ? 'S' : 'D' ,
100 - V_118 ) ;
F_63 ( ! V_118 ) ;
}
static void F_64 ( struct V_2 * V_3 , bool V_122 )
{
unsigned long V_32 ;
F_14 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
if ( ( V_3 -> V_123 . V_124 == V_125 ) ||
( V_3 -> V_123 . V_124 == V_126 ) ) {
T_2 V_115 = F_65 ( V_3 -> V_123 . V_127 ) ;
F_59 ( V_3 , V_122 , V_115 ,
V_59 ) ;
}
if ( V_3 -> V_123 . V_124 != V_125 ) {
T_2 V_115 = F_65 ( V_3 -> V_123 . V_128 ) ;
F_59 ( V_3 , V_122 , V_115 ,
V_63 ) ;
}
F_15 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
}
static T_2 F_66 ( struct V_2 * V_3 )
{
void T_1 * V_129 = F_4 ( V_3 ) ;
T_2 V_130 ;
V_130 = F_51 ( V_129 + V_59 ) ;
V_130 |= F_51 ( V_129 + V_63 ) ;
return V_130 ;
}
static T_2 F_67 ( struct V_2 * V_3 )
{
static const unsigned int V_131 [] = {
[ V_132 ]
= V_133 ,
[ V_134 ]
= V_135 ,
[ V_136 ]
= V_137 ,
} ;
static const unsigned int V_138 [] = {
[ V_139 ]
= V_140 ,
[ V_141 ]
= V_142 ,
[ V_143 ]
= V_144 ,
} ;
if ( F_2 ( V_3 ) )
return V_131 [ V_3 -> V_123 . V_145 ] ;
else
return V_138 [ V_3 -> V_123 . V_145 ] ;
}
static void F_68 ( struct V_2 * V_3 )
{
T_2 V_146 ;
T_2 V_147 ;
V_146 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_147 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_53 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_147 , V_3 -> V_8 -> V_9 + V_148 + V_146 ) ;
V_147 = F_67 ( V_3 ) << F_53 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_147 , V_3 -> V_8 -> V_9 + V_149 + V_146 ) ;
if ( F_3 ( V_3 ) ) {
int V_150 = ( V_3 -> V_11 -> V_12 << V_151 )
& V_152 ;
void T_1 * V_129 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_153 , V_129 + V_53 ) ;
F_30 ( V_3 -> V_154 , V_129 + V_60 ) ;
F_30 ( V_150 , V_129 + V_55 ) ;
F_30 ( V_150 , V_129 + V_61 ) ;
}
}
static T_2 F_69 ( struct V_2 * V_3 )
{
T_2 V_155 ;
if ( F_3 ( V_3 ) )
V_155 = ( F_51 ( & V_3 -> V_74 -> V_156 ) & V_157 )
>> V_158 ;
else {
T_2 V_130 = F_51 ( F_4 ( V_3 ) + V_61 ) ;
V_155 = ( V_130 & V_159 )
>> V_160 ;
}
return V_155 * ( 1 << V_3 -> V_123 . V_161 . V_162 ) ;
}
static bool F_70 ( struct V_2 * V_3 )
{
bool V_163 ;
if ( F_3 ( V_3 ) )
V_163 = F_51 ( & V_3 -> V_74 -> V_164 ) & V_165 ;
else
V_163 = F_51 ( F_4 ( V_3 ) + V_63 )
& V_166 ;
return V_163 ;
}
static int F_71 ( struct V_2 * V_3 )
{
int V_167 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_113 )
return 0 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_167 = F_50 ( V_3 , V_105 ) ;
if ( V_167 == 0 ) {
if ( F_3 ( V_3 ) ) {
F_64 ( V_3 , false ) ;
if ( F_66 ( V_3 ) )
V_167 = F_50 ( V_3 ,
V_168 ) ;
}
}
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_167 ;
}
static int F_72 ( struct V_2 * V_3 )
{
int V_167 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_113 )
return 0 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( V_3 -> V_8 -> V_169 == 0 )
if ( F_3 ( V_3 ) ) {
V_167 = F_50 ( V_3 ,
V_105 ) ;
goto V_170;
}
if ( F_69 ( V_3 ) || F_70 ( V_3 ) ) {
if ( F_3 ( V_3 ) )
F_64 ( V_3 , true ) ;
V_167 = F_50 ( V_3 , V_168 ) ;
}
V_170:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_167 ;
}
static int F_73 ( struct V_2 * V_4 )
{
unsigned long V_32 ;
int V_34 = 0 ;
V_34 = F_71 ( V_4 ) ;
if ( ! V_34 && F_2 ( V_4 ) )
V_34 = F_50 ( V_4 , V_107 ) ;
F_14 ( & V_4 -> V_38 , V_32 ) ;
F_58 ( V_4 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return V_34 ;
}
static T_3 F_74 ( struct V_171 * V_172 )
{
struct V_2 * V_3 = F_75 ( V_172 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_75 ( V_172 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_3 -> V_4 . V_173 ++ ;
if ( V_3 -> V_4 . V_173 < 0 )
V_3 -> V_4 . V_173 = 1 ;
V_15 -> V_47 . V_173 = V_3 -> V_4 . V_173 ;
F_38 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_172 -> V_173 ;
}
static int F_76 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_169 == 0 ) {
int V_174 ;
if ( F_3 ( V_3 ) ) {
V_174 = F_50 ( V_3 ,
V_105 ) ;
if ( V_174 )
return V_174 ;
}
}
if ( F_3 ( V_3 ) )
F_64 ( V_3 , true ) ;
return F_50 ( V_3 , V_168 ) ;
}
static struct V_14 * F_77 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_174 ;
V_15 = F_40 ( V_3 ) ;
if ( V_15 != NULL ) {
V_3 -> V_113 = true ;
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
V_174 = F_76 ( V_3 ) ;
if ( V_174 )
return NULL ;
}
return V_15 ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_69 ) {
if ( V_15 -> V_68 < V_15 -> V_16
&& ! F_70 ( V_3 )
&& ! F_69 ( V_3 ) ) {
F_16 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
( void ) F_76 ( V_3 ) ;
if ( V_15 -> V_68 == V_15 -> V_16 )
V_15 -> V_68 = 0 ;
}
} else {
F_16 ( V_3 , V_15 ) ;
if ( V_15 -> V_68 < V_15 -> V_16 ) {
F_35 ( V_3 , V_15 ) ;
( void ) F_76 ( V_3 ) ;
return;
}
if ( F_77 ( V_3 ) == NULL )
V_3 -> V_113 = false ;
}
V_3 -> V_112 ++ ;
F_79 ( & V_3 -> V_175 ) ;
}
static void F_80 ( unsigned long V_176 )
{
struct V_2 * V_3 = (struct V_2 * ) V_176 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
T_4 V_177 ;
void * V_178 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
goto V_174;
if ( ! V_15 -> V_69 )
V_3 -> V_179 = V_15 -> V_47 . V_173 ;
if ( V_3 -> V_112 == 0 ) {
F_15 ( & V_3 -> V_38 , V_32 ) ;
return;
}
V_177 = V_15 -> V_47 . V_177 ;
V_178 = V_15 -> V_47 . V_178 ;
if ( ! V_15 -> V_69 ) {
if ( F_22 ( & V_15 -> V_47 ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
} else {
if ( ! V_15 -> V_79 ) {
F_17 ( V_15 ) ;
F_16 ( V_3 , V_15 ) ;
F_28 ( & V_15 -> V_42 , & V_3 -> V_44 ) ;
V_15 -> V_79 = true ;
}
}
}
V_3 -> V_112 -- ;
if ( V_3 -> V_112 )
F_79 ( & V_3 -> V_175 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
if ( V_177 && ( V_15 -> V_47 . V_32 & V_180 ) )
V_177 ( V_178 ) ;
return;
V_174:
if ( V_3 -> V_112 > 0 )
V_3 -> V_112 -- ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static T_5 F_81 ( int V_181 , void * V_176 )
{
static const struct V_182 V_183 [] = {
{ V_184 , V_185 , false , 0 } ,
{ V_186 , V_187 , false , 32 } ,
{ V_188 , V_189 , false , 64 } ,
{ V_190 , V_191 , false , 96 } ,
{ V_192 , V_185 , true , 0 } ,
{ V_193 , V_187 , true , 32 } ,
{ V_194 , V_189 , true , 64 } ,
{ V_195 , V_191 , true , 96 } ,
{ V_196 , V_197 , false , V_7 } ,
{ V_198 , V_197 , true , V_7 } ,
} ;
int V_33 ;
T_2 V_199 [ F_82 ( V_183 ) ] ;
T_2 V_200 ;
T_2 V_201 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_202 * V_8 = V_176 ;
F_14 ( & V_8 -> V_203 , V_32 ) ;
for ( V_33 = 0 ; V_33 < F_82 ( V_183 ) ; V_33 ++ )
V_199 [ V_33 ] = F_51 ( V_8 -> V_9 + V_183 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_83 ( ( unsigned long * ) V_199 ,
V_204 * F_82 ( V_183 ) , V_4 + 1 ) ;
if ( V_4 == V_204 * F_82 ( V_183 ) )
break;
V_201 = V_4 / V_204 ;
V_200 = V_4 & ( V_204 - 1 ) ;
F_30 ( 1 << V_200 , V_8 -> V_9 + V_183 [ V_201 ] . V_205 ) ;
if ( V_183 [ V_201 ] . V_206 == V_7 )
V_3 = V_8 -> V_207 [ V_200 ] ;
else
V_3 = V_8 -> V_208 [ V_183 [ V_201 ] . V_206 + V_200 ] ;
F_84 ( & V_3 -> V_38 ) ;
if ( ! V_183 [ V_201 ] . V_209 )
F_78 ( V_3 ) ;
else
F_85 ( V_8 -> V_5 , L_3 ,
V_4 , V_183 [ V_201 ] . V_206 , V_200 ) ;
F_86 ( & V_3 -> V_38 ) ;
}
F_15 ( & V_8 -> V_203 , V_32 ) ;
return V_210 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_211 * V_212 )
{
int V_167 = 0 ;
T_2 V_213 = F_88 ( V_212 -> V_128 ) ;
T_2 V_214 = F_88 ( V_212 -> V_127 ) ;
bool V_17 = V_212 -> V_215 == V_216 ;
if ( ! V_212 -> V_124 ) {
F_56 ( V_3 , L_4 ) ;
V_167 = - V_35 ;
}
if ( V_212 -> V_128 != V_217 &&
V_3 -> V_8 -> V_218 -> V_219 [ V_212 -> V_128 ] == 0 &&
V_3 -> V_220 == 0 ) {
F_56 ( V_3 , L_5 ,
V_212 -> V_128 ) ;
V_167 = - V_35 ;
}
if ( V_212 -> V_127 != V_221 &&
V_3 -> V_8 -> V_218 -> V_222 [ V_212 -> V_127 ] == 0 &&
V_3 -> V_220 == 0 ) {
F_56 ( V_3 , L_6 ,
V_212 -> V_127 ) ;
V_167 = - V_35 ;
}
if ( V_212 -> V_124 == V_223 &&
V_213 == V_217 ) {
F_56 ( V_3 , L_7 ) ;
V_167 = - V_35 ;
}
if ( V_212 -> V_124 == V_125 &&
V_214 == V_221 ) {
F_56 ( V_3 , L_8 ) ;
V_167 = - V_35 ;
}
if ( V_214 == V_221 &&
V_213 == V_217 && V_17 ) {
F_56 ( V_3 , L_9 ) ;
V_167 = - V_35 ;
}
if ( V_212 -> V_124 == V_126 &&
( V_214 != V_213 ) ) {
F_56 ( V_3 , L_10 ) ;
V_167 = - V_35 ;
}
if ( V_212 -> V_124 == V_126 ) {
F_56 ( V_3 , L_11 ) ;
V_167 = - V_35 ;
}
if ( F_41 ( V_17 , V_212 -> V_224 . V_82 ) *
( 1 << V_212 -> V_224 . V_162 ) !=
F_41 ( V_17 , V_212 -> V_161 . V_82 ) *
( 1 << V_212 -> V_161 . V_162 ) ) {
F_56 ( V_3 , L_12 ) ;
V_167 = - V_35 ;
}
return V_167 ;
}
static bool F_89 ( struct V_225 * V_226 , bool V_227 ,
int V_228 , bool V_17 )
{
unsigned long V_32 ;
F_14 ( & V_226 -> V_38 , V_32 ) ;
if ( ! V_17 ) {
if ( V_226 -> V_229 == V_230 &&
V_226 -> V_231 == V_230 ) {
V_226 -> V_231 = V_232 ;
V_226 -> V_229 = V_232 ;
goto V_233;
} else
goto V_234;
}
if ( V_227 ) {
if ( V_226 -> V_229 == V_232 )
goto V_234;
if ( V_226 -> V_229 == V_230 )
V_226 -> V_229 = V_235 ;
if ( ! ( V_226 -> V_229 & ( 1 << V_228 ) ) ) {
V_226 -> V_229 |= 1 << V_228 ;
goto V_233;
} else
goto V_234;
} else {
if ( V_226 -> V_231 == V_232 )
goto V_234;
if ( V_226 -> V_231 == V_230 )
V_226 -> V_231 = V_235 ;
if ( ! ( V_226 -> V_231 & ( 1 << V_228 ) ) ) {
V_226 -> V_231 |= 1 << V_228 ;
goto V_233;
} else
goto V_234;
}
V_234:
F_15 ( & V_226 -> V_38 , V_32 ) ;
return false ;
V_233:
F_15 ( & V_226 -> V_38 , V_32 ) ;
return true ;
}
static bool F_90 ( struct V_225 * V_226 , bool V_227 ,
int V_228 )
{
unsigned long V_32 ;
bool V_236 = false ;
F_14 ( & V_226 -> V_38 , V_32 ) ;
if ( ! V_228 ) {
V_226 -> V_231 = V_230 ;
V_226 -> V_229 = V_230 ;
V_236 = true ;
goto V_75;
}
if ( V_227 ) {
V_226 -> V_229 &= ~ ( 1 << V_228 ) ;
if ( V_226 -> V_229 == V_235 )
V_226 -> V_229 = V_230 ;
} else {
V_226 -> V_231 &= ~ ( 1 << V_228 ) ;
if ( V_226 -> V_231 == V_235 )
V_226 -> V_231 = V_230 ;
}
V_236 = ( ( V_226 -> V_229 | V_226 -> V_231 ) ==
V_230 ) ;
V_75:
F_15 ( & V_226 -> V_38 , V_32 ) ;
return V_236 ;
}
static int F_91 ( struct V_2 * V_3 )
{
int V_237 ;
int V_238 ;
int V_239 ;
struct V_225 * V_240 ;
int V_33 ;
int V_241 ;
int V_6 ;
bool V_227 ;
bool V_17 = V_3 -> V_123 . V_215 == V_216 ;
V_240 = V_3 -> V_8 -> V_242 ;
if ( V_3 -> V_123 . V_124 == V_125 ) {
V_237 = V_3 -> V_123 . V_127 ;
V_6 = 2 * V_237 ;
V_227 = true ;
} else if ( V_3 -> V_123 . V_124 == V_223 ||
V_3 -> V_123 . V_124 == V_243 ) {
V_237 = V_3 -> V_123 . V_128 ;
V_6 = 2 * V_237 + 1 ;
V_227 = false ;
} else
return - V_35 ;
V_238 = F_88 ( V_237 ) ;
V_239 = F_65 ( V_237 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_123 . V_124 == V_243 ) {
for ( V_33 = 0 ; V_33 < V_3 -> V_8 -> V_244 ; V_33 ++ ) {
if ( F_89 ( & V_240 [ V_33 ] , V_227 ,
0 , V_17 ) )
goto V_245;
}
} else
for ( V_241 = 0 ; V_241 < V_3 -> V_8 -> V_244 ; V_241 += 8 ) {
int V_246 = V_241 + V_238 * 2 ;
for ( V_33 = V_246 ; V_33 < V_246 + 2 ; V_33 ++ ) {
if ( F_89 ( & V_240 [ V_33 ] ,
V_227 ,
0 ,
V_17 ) )
goto V_245;
}
}
return - V_35 ;
V_245:
V_3 -> V_11 = & V_240 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_75;
}
if ( V_237 == - 1 )
return - V_35 ;
for ( V_241 = 0 ; V_241 < V_3 -> V_8 -> V_244 ; V_241 += 8 ) {
int V_246 = V_241 + V_238 * 2 ;
if ( V_227 ) {
for ( V_33 = V_246 ; V_33 < V_246 + 2 ; V_33 ++ ) {
if ( F_89 ( & V_240 [ V_33 ] , V_227 ,
V_239 , V_17 ) )
goto V_247;
}
} else {
for ( V_33 = V_246 + 1 ; V_33 >= V_246 ; V_33 -- ) {
if ( F_89 ( & V_240 [ V_33 ] , V_227 ,
V_239 , V_17 ) )
goto V_247;
}
}
}
return - V_35 ;
V_247:
V_3 -> V_11 = & V_240 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_75:
if ( V_17 )
V_3 -> V_8 -> V_208 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_207 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_92 ( struct V_2 * V_3 )
{
T_6 V_248 = V_3 -> V_4 . V_1 -> V_249 ;
if ( F_93 ( V_250 , V_248 ) && ! F_93 ( V_251 , V_248 ) ) {
V_3 -> V_123 = * V_3 -> V_8 -> V_218 -> V_252 ;
V_3 -> V_123 . V_127 = V_221 ;
V_3 -> V_123 . V_128 = V_3 -> V_8 -> V_218 ->
memcpy [ V_3 -> V_4 . V_253 ] ;
} else if ( F_93 ( V_250 , V_248 ) &&
F_93 ( V_251 , V_248 ) ) {
V_3 -> V_123 = * V_3 -> V_8 -> V_218 -> V_254 ;
} else {
F_56 ( V_3 , L_13 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 )
{
int V_167 = 0 ;
T_2 V_115 ;
struct V_225 * V_226 = V_3 -> V_11 ;
bool V_227 ;
F_58 ( V_3 ) ;
if ( V_226 == NULL ) {
F_56 ( V_3 , L_14 ) ;
return - V_35 ;
}
if ( V_226 -> V_229 == V_230 &&
V_226 -> V_231 == V_230 ) {
F_56 ( V_3 , L_15 ) ;
return - V_35 ;
}
if ( V_3 -> V_123 . V_124 == V_223 ||
V_3 -> V_123 . V_124 == V_243 ) {
V_115 = F_65 ( V_3 -> V_123 . V_128 ) ;
V_227 = false ;
} else if ( V_3 -> V_123 . V_124 == V_125 ) {
V_115 = F_65 ( V_3 -> V_123 . V_127 ) ;
V_227 = true ;
} else {
F_56 ( V_3 , L_16 ) ;
return - V_35 ;
}
V_167 = F_50 ( V_3 , V_105 ) ;
if ( V_167 ) {
F_56 ( V_3 , L_17 ) ;
return V_167 ;
}
if ( F_3 ( V_3 ) ) {
F_64 ( V_3 , false ) ;
V_3 -> V_8 -> V_208 [ V_3 -> V_6 ] = NULL ;
if ( ! F_90 ( V_226 , V_227 , V_115 ) ) {
if ( F_66 ( V_3 ) ) {
V_167 = F_50 ( V_3 ,
V_168 ) ;
if ( V_167 ) {
F_56 ( V_3 ,
L_18 ) ;
return V_167 ;
}
}
return 0 ;
}
} else {
( void ) F_90 ( V_226 , V_227 , 0 ) ;
}
V_167 = F_50 ( V_3 , V_107 ) ;
if ( V_167 ) {
F_56 ( V_3 , L_19 ) ;
return V_167 ;
}
V_3 -> V_11 = NULL ;
V_3 -> V_255 = false ;
V_3 -> V_8 -> V_207 [ V_226 -> V_12 ] = NULL ;
return 0 ;
}
static bool F_95 ( struct V_2 * V_3 )
{
void T_1 * V_129 = F_4 ( V_3 ) ;
bool V_256 = false ;
unsigned long V_32 ;
void T_1 * V_100 ;
T_2 V_99 ;
T_2 V_115 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( F_2 ( V_3 ) ) {
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_100 = V_3 -> V_8 -> V_9 + V_103 ;
else
V_100 = V_3 -> V_8 -> V_9 + V_104 ;
V_99 = ( F_51 ( V_100 ) &
F_52 ( V_3 -> V_11 -> V_12 ) ) >>
F_53 ( V_3 -> V_11 -> V_12 ) ;
if ( V_99 == V_106 || V_99 == V_107 )
V_256 = true ;
goto V_257;
}
if ( V_3 -> V_123 . V_124 == V_223 ||
V_3 -> V_123 . V_124 == V_243 ) {
V_115 = F_65 ( V_3 -> V_123 . V_128 ) ;
V_99 = F_51 ( V_129 + V_63 ) ;
} else if ( V_3 -> V_123 . V_124 == V_125 ) {
V_115 = F_65 ( V_3 -> V_123 . V_127 ) ;
V_99 = F_51 ( V_129 + V_59 ) ;
} else {
F_56 ( V_3 , L_16 ) ;
goto V_257;
}
V_99 = ( V_99 & F_61 ( V_115 ) ) >>
F_60 ( V_115 ) ;
if ( V_99 != V_168 )
V_256 = true ;
V_257:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_256 ;
}
static T_2 F_96 ( struct V_258 * V_4 )
{
struct V_2 * V_3 =
F_75 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_259 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_259 = F_69 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_259 ;
}
static int
F_97 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_92 * V_260 , struct V_92 * V_261 ,
unsigned int V_94 , T_7 V_262 ,
T_7 V_263 )
{
struct V_211 * V_264 = & V_4 -> V_123 ;
struct V_265 * V_224 = & V_264 -> V_224 ;
struct V_265 * V_161 = & V_264 -> V_161 ;
int V_34 ;
V_34 = F_98 ( V_260 , V_94 ,
V_262 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_266 . V_267 ,
V_224 -> V_162 ,
V_161 -> V_162 ) ;
V_34 = F_98 ( V_261 , V_94 ,
V_263 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_266 . V_164 ,
V_161 -> V_162 ,
V_224 -> V_162 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_99 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_92 * V_260 , struct V_92 * V_261 ,
unsigned int V_94 , T_7 V_262 ,
T_7 V_263 )
{
struct V_211 * V_264 = & V_4 -> V_123 ;
struct V_265 * V_224 = & V_264 -> V_224 ;
struct V_265 * V_161 = & V_264 -> V_161 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_69 )
V_32 |= V_268 | V_73 ;
V_34 = F_100 ( V_260 , V_94 , V_262 ,
V_43 -> V_30 . V_27 ,
F_101 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_153 ,
V_224 , V_161 , V_32 ) ;
V_34 = F_100 ( V_261 , V_94 , V_263 ,
V_43 -> V_30 . V_28 ,
F_101 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_154 ,
V_161 , V_224 , V_32 ) ;
F_102 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_103 ( struct V_2 * V_4 , struct V_92 * V_95 ,
unsigned int V_94 , unsigned long V_269 )
{
struct V_211 * V_264 = & V_4 -> V_123 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_47 ( V_95 , V_94 , V_264 -> V_224 . V_162 ,
V_264 -> V_161 . V_162 ) ;
if ( V_43 -> V_16 < 0 ) {
F_56 ( V_4 , L_20 ) ;
goto V_174;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_56 ( V_4 , L_21 ) ;
goto V_174;
}
V_43 -> V_68 = 0 ;
V_43 -> V_47 . V_32 = V_269 ;
V_43 -> V_47 . V_270 = F_74 ;
F_104 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_174:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static T_7
F_105 ( struct V_2 * V_4 , enum V_271 V_272 )
{
struct V_273 * V_274 = V_4 -> V_8 -> V_218 ;
struct V_211 * V_264 = & V_4 -> V_123 ;
T_7 V_117 = 0 ;
if ( V_4 -> V_220 )
return V_4 -> V_220 ;
if ( V_272 == V_275 )
V_117 = V_274 -> V_222 [ V_264 -> V_127 ] ;
else if ( V_272 == V_31 )
V_117 = V_274 -> V_219 [ V_264 -> V_128 ] ;
return V_117 ;
}
static struct V_171 *
F_106 ( struct V_258 * V_276 , struct V_92 * V_260 ,
struct V_92 * V_261 , unsigned int V_94 ,
enum V_271 V_272 , unsigned long V_269 )
{
struct V_2 * V_4 = F_75 ( V_276 , struct V_2 , V_4 ) ;
T_7 V_262 = 0 ;
T_7 V_263 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_56 ( V_4 , L_22 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_38 , V_32 ) ;
V_43 = F_103 ( V_4 , V_260 , V_94 , V_269 ) ;
if ( V_43 == NULL )
goto V_174;
if ( F_107 ( & V_260 [ V_94 - 1 ] ) == V_260 )
V_43 -> V_69 = true ;
if ( V_272 != V_277 ) {
T_7 V_278 = F_105 ( V_4 , V_272 ) ;
if ( V_272 == V_275 )
V_262 = V_278 ;
else if ( V_272 == V_31 )
V_263 = V_278 ;
}
if ( F_3 ( V_4 ) )
V_34 = F_97 ( V_4 , V_43 , V_260 , V_261 ,
V_94 , V_262 , V_263 ) ;
else
V_34 = F_99 ( V_4 , V_43 , V_260 , V_261 ,
V_94 , V_262 , V_263 ) ;
if ( V_34 ) {
F_56 ( V_4 , L_23 ,
F_3 ( V_4 ) ? L_24 : L_25 , V_34 ) ;
goto V_174;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_111 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return & V_43 -> V_47 ;
V_174:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return NULL ;
}
bool F_108 ( struct V_258 * V_4 , void * V_176 )
{
struct V_211 * V_279 = V_176 ;
struct V_2 * V_3 =
F_75 ( V_4 , struct V_2 , V_4 ) ;
int V_174 ;
if ( V_176 ) {
V_174 = F_87 ( V_3 , V_279 ) ;
if ( ! V_174 )
V_3 -> V_123 = * V_279 ;
} else
V_174 = F_92 ( V_3 ) ;
if ( ! V_174 )
V_3 -> V_255 = true ;
return V_174 == 0 ;
}
static void F_109 ( struct V_2 * V_3 , int V_237 , bool V_27 )
{
bool V_280 = V_3 -> V_123 . V_280 ;
bool V_281 = V_3 -> V_123 . V_282 ;
T_2 V_283 = V_281 ? V_284 : V_285 ;
T_2 V_286 = V_280 ? V_287 : V_288 ;
T_2 V_115 = F_65 ( V_237 ) ;
T_2 V_289 = F_88 ( V_237 ) ;
T_2 V_290 = 1 << V_115 ;
if ( ! V_27 )
V_290 <<= 16 ;
F_30 ( V_290 , V_3 -> V_8 -> V_9 + V_283 + V_289 * 4 ) ;
F_30 ( V_290 , V_3 -> V_8 -> V_9 + V_286 + V_289 * 4 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_169 < 3 )
return;
if ( ( V_3 -> V_123 . V_124 == V_125 ) ||
( V_3 -> V_123 . V_124 == V_126 ) )
F_109 ( V_3 , V_3 -> V_123 . V_127 , true ) ;
if ( ( V_3 -> V_123 . V_124 == V_223 ) ||
( V_3 -> V_123 . V_124 == V_126 ) )
F_109 ( V_3 , V_3 -> V_123 . V_128 , false ) ;
}
static int F_111 ( struct V_258 * V_4 )
{
int V_174 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_75 ( V_4 , struct V_2 , V_4 ) ;
bool V_291 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_3 -> V_179 = V_4 -> V_173 = 1 ;
if ( ! V_3 -> V_255 ) {
V_174 = F_92 ( V_3 ) ;
if ( V_174 ) {
F_56 ( V_3 , L_26 ) ;
goto V_292;
}
}
V_291 = ( V_3 -> V_11 == NULL ) ;
V_174 = F_91 ( V_3 ) ;
if ( V_174 ) {
F_56 ( V_3 , L_27 ) ;
goto V_292;
}
F_112 ( & V_3 -> V_123 , & V_3 -> V_153 ,
& V_3 -> V_154 , F_3 ( V_3 ) ) ;
F_110 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
F_113 ( & V_3 -> V_123 ,
& V_3 -> V_266 . V_267 , & V_3 -> V_266 . V_164 ) ;
if ( V_3 -> V_123 . V_124 == V_125 )
V_3 -> V_74 = V_3 -> V_8 -> V_293 +
V_3 -> V_123 . V_127 * V_294 ;
else
V_3 -> V_74 = V_3 -> V_8 -> V_293 +
V_3 -> V_123 . V_128 *
V_294 + V_295 ;
}
if ( V_291 )
F_68 ( V_3 ) ;
V_292:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_174 ;
}
static void F_114 ( struct V_258 * V_4 )
{
struct V_2 * V_3 =
F_75 ( V_4 , struct V_2 , V_4 ) ;
int V_174 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_56 ( V_3 , L_28 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_174 = F_94 ( V_3 ) ;
if ( V_174 )
F_56 ( V_3 , L_29 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static struct V_171 * F_115 ( struct V_258 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_269 )
{
struct V_92 V_296 ;
struct V_92 V_297 ;
F_116 ( & V_296 , 1 ) ;
F_116 ( & V_297 , 1 ) ;
F_117 ( & V_296 ) = V_28 ;
F_117 ( & V_297 ) = V_27 ;
F_49 ( & V_296 ) = V_23 ;
F_49 ( & V_297 ) = V_23 ;
return F_106 ( V_4 , & V_297 , & V_296 , 1 , V_277 , V_269 ) ;
}
static struct V_171 *
F_118 ( struct V_258 * V_4 ,
struct V_92 * V_296 , unsigned int V_298 ,
struct V_92 * V_297 , unsigned int V_299 ,
unsigned long V_269 )
{
if ( V_298 != V_299 )
return NULL ;
return F_106 ( V_4 , V_297 , V_296 , V_299 , V_277 , V_269 ) ;
}
static struct V_171 * F_119 ( struct V_258 * V_4 ,
struct V_92 * V_93 ,
unsigned int V_94 ,
enum V_271 V_272 ,
unsigned long V_269 )
{
if ( V_272 != V_275 && V_272 != V_31 )
return NULL ;
return F_106 ( V_4 , V_93 , V_93 , V_94 , V_272 , V_269 ) ;
}
static struct V_171 *
F_120 ( struct V_258 * V_4 , T_7 V_29 ,
T_8 V_300 , T_8 V_301 ,
enum V_271 V_272 )
{
unsigned int V_302 = V_300 / V_301 ;
struct V_171 * V_47 ;
struct V_92 * V_95 ;
int V_33 ;
V_95 = F_121 ( V_302 + 1 , sizeof( struct V_92 ) , V_24 ) ;
for ( V_33 = 0 ; V_33 < V_302 ; V_33 ++ ) {
F_117 ( & V_95 [ V_33 ] ) = V_29 ;
F_49 ( & V_95 [ V_33 ] ) = V_301 ;
V_29 += V_301 ;
}
V_95 [ V_302 ] . V_206 = 0 ;
V_95 [ V_302 ] . V_303 = 0 ;
V_95 [ V_302 ] . V_304 =
( ( unsigned long ) V_95 | 0x01 ) & ~ 0x02 ;
V_47 = F_106 ( V_4 , V_95 , V_95 , V_302 , V_272 ,
V_180 ) ;
F_10 ( V_95 ) ;
return V_47 ;
}
static enum V_305 F_122 ( struct V_258 * V_4 ,
T_3 V_173 ,
struct V_306 * V_307 )
{
struct V_2 * V_3 = F_75 ( V_4 , struct V_2 , V_4 ) ;
T_3 V_308 ;
T_3 V_309 ;
int V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_56 ( V_3 , L_30 ) ;
return - V_35 ;
}
V_309 = V_3 -> V_179 ;
V_308 = V_4 -> V_173 ;
if ( F_95 ( V_3 ) )
V_34 = V_310 ;
else
V_34 = F_123 ( V_173 , V_309 , V_308 ) ;
F_124 ( V_307 , V_309 , V_308 ,
F_96 ( V_4 ) ) ;
return V_34 ;
}
static void F_125 ( struct V_258 * V_4 )
{
struct V_2 * V_3 = F_75 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_56 ( V_3 , L_31 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_126 ( & V_3 -> V_80 , & V_3 -> V_81 ) ;
if ( ! V_3 -> V_113 )
( void ) F_77 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static int
F_127 ( struct V_2 * V_3 ,
struct V_265 * V_279 ,
enum V_311 V_312 ,
T_2 V_313 )
{
enum V_314 V_315 ;
int V_82 ;
switch ( V_312 ) {
case V_316 :
V_315 = V_317 ;
break;
case V_318 :
V_315 = V_319 ;
break;
case V_320 :
V_315 = V_321 ;
break;
case V_322 :
V_315 = V_323 ;
break;
default:
F_128 ( V_3 -> V_8 -> V_5 ,
L_32
L_33 ,
V_312 ) ;
return - V_35 ;
}
if ( F_3 ( V_3 ) ) {
if ( V_313 >= 16 )
V_82 = V_324 ;
else if ( V_313 >= 8 )
V_82 = V_325 ;
else if ( V_313 >= 4 )
V_82 = V_326 ;
else
V_82 = V_83 ;
} else {
if ( V_313 >= 16 )
V_82 = V_327 ;
else if ( V_313 >= 8 )
V_82 = V_328 ;
else if ( V_313 >= 4 )
V_82 = V_329 ;
else
V_82 = V_84 ;
}
V_279 -> V_162 = V_315 ;
V_279 -> V_82 = V_82 ;
V_279 -> V_330 = V_331 ;
return 0 ;
}
static int F_129 ( struct V_258 * V_4 ,
struct V_332 * V_333 )
{
struct V_2 * V_3 = F_75 ( V_4 , struct V_2 , V_4 ) ;
struct V_211 * V_264 = & V_3 -> V_123 ;
enum V_311 V_334 , V_335 ;
T_7 V_336 ;
T_2 V_337 , V_338 ;
int V_34 ;
V_334 = V_333 -> V_334 ;
V_337 = V_333 -> V_337 ;
V_335 = V_333 -> V_335 ;
V_338 = V_333 -> V_338 ;
if ( V_333 -> V_272 == V_275 ) {
T_7 V_339 =
V_3 -> V_8 -> V_218 -> V_222 [ V_264 -> V_127 ] ;
V_336 = V_333 -> V_340 ;
if ( V_339 )
F_62 ( V_3 -> V_8 -> V_5 ,
L_34
L_35 ,
V_339 , V_336 ) ;
if ( V_264 -> V_124 != V_125 )
F_62 ( V_3 -> V_8 -> V_5 ,
L_36
L_37 ,
V_264 -> V_124 ) ;
V_264 -> V_124 = V_125 ;
if ( V_335 == V_341 )
V_335 = V_334 ;
if ( V_338 == 0 )
V_338 = V_337 ;
} else if ( V_333 -> V_272 == V_31 ) {
T_7 V_342 =
V_3 -> V_8 -> V_218 -> V_219 [ V_264 -> V_128 ] ;
V_336 = V_333 -> V_343 ;
if ( V_342 )
F_62 ( V_3 -> V_8 -> V_5 ,
L_38
L_35 ,
V_342 , V_336 ) ;
if ( V_264 -> V_124 != V_223 )
F_62 ( V_3 -> V_8 -> V_5 ,
L_39
L_40 ,
V_264 -> V_124 ) ;
V_264 -> V_124 = V_223 ;
if ( V_334 == V_341 )
V_334 = V_335 ;
if ( V_337 == 0 )
V_337 = V_338 ;
} else {
F_128 ( V_3 -> V_8 -> V_5 ,
L_41 ,
V_333 -> V_272 ) ;
return - V_35 ;
}
if ( V_337 * V_334 != V_338 * V_335 ) {
F_128 ( V_3 -> V_8 -> V_5 ,
L_42 ,
V_337 ,
V_334 ,
V_338 ,
V_335 ) ;
return - V_35 ;
}
V_34 = F_127 ( V_3 , & V_264 -> V_224 ,
V_334 ,
V_337 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_127 ( V_3 , & V_264 -> V_161 ,
V_335 ,
V_338 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_113 ( V_264 , & V_3 -> V_266 . V_267 , & V_3 -> V_266 . V_164 ) ;
else
F_112 ( V_264 , & V_3 -> V_153 ,
& V_3 -> V_154 , false ) ;
V_3 -> V_220 = V_336 ;
V_3 -> V_344 = V_333 -> V_272 ;
F_62 ( V_3 -> V_8 -> V_5 ,
L_43
L_44 ,
F_130 ( V_4 ) ,
( V_333 -> V_272 == V_275 ) ? L_45 : L_46 ,
V_334 , V_335 ,
V_337 , V_338 ) ;
return 0 ;
}
static int F_131 ( struct V_258 * V_4 , enum V_345 V_346 ,
unsigned long V_347 )
{
struct V_2 * V_3 = F_75 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_56 ( V_3 , L_31 ) ;
return - V_35 ;
}
switch ( V_346 ) {
case V_348 :
return F_73 ( V_3 ) ;
case V_349 :
return F_71 ( V_3 ) ;
case V_350 :
return F_72 ( V_3 ) ;
case V_351 :
return F_129 ( V_4 ,
(struct V_332 * ) V_347 ) ;
default:
break;
}
return - V_352 ;
}
static void T_9 F_132 ( struct V_202 * V_8 , struct V_353 * V_354 ,
struct V_2 * V_355 , int V_206 ,
int V_356 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_354 -> V_357 ) ;
for ( V_33 = V_206 ; V_33 < V_206 + V_356 ; V_33 ++ ) {
V_3 = & V_355 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_354 ;
F_133 ( & V_3 -> V_38 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_81 ) ;
F_24 ( & V_3 -> V_80 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_111 ) ;
F_134 ( & V_3 -> V_175 , F_80 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_358 ,
& V_354 -> V_357 ) ;
}
}
static void F_135 ( struct V_202 * V_8 , struct V_353 * V_5 )
{
if ( F_93 ( V_251 , V_5 -> V_249 ) )
V_5 -> V_359 = F_119 ;
if ( F_93 ( V_250 , V_5 -> V_249 ) ) {
V_5 -> V_360 = F_115 ;
V_5 -> V_361 = 2 ;
}
if ( F_93 ( V_362 , V_5 -> V_249 ) )
V_5 -> V_363 = F_118 ;
if ( F_93 ( V_364 , V_5 -> V_249 ) )
V_5 -> V_365 = F_120 ;
V_5 -> V_366 = F_111 ;
V_5 -> V_367 = F_114 ;
V_5 -> V_368 = F_125 ;
V_5 -> V_369 = F_122 ;
V_5 -> V_370 = F_131 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_136 ( struct V_202 * V_8 ,
int V_371 )
{
int V_174 ;
F_132 ( V_8 , & V_8 -> V_372 , V_8 -> V_373 ,
0 , V_8 -> V_374 ) ;
F_137 ( V_8 -> V_372 . V_249 ) ;
F_138 ( V_251 , V_8 -> V_372 . V_249 ) ;
F_138 ( V_364 , V_8 -> V_372 . V_249 ) ;
F_135 ( V_8 , & V_8 -> V_372 ) ;
V_174 = F_139 ( & V_8 -> V_372 ) ;
if ( V_174 ) {
F_85 ( V_8 -> V_5 , L_47 ) ;
goto V_375;
}
F_132 ( V_8 , & V_8 -> V_376 , V_8 -> V_373 ,
V_8 -> V_374 , V_8 -> V_218 -> V_377 ) ;
F_137 ( V_8 -> V_376 . V_249 ) ;
F_138 ( V_250 , V_8 -> V_376 . V_249 ) ;
F_138 ( V_362 , V_8 -> V_376 . V_249 ) ;
F_135 ( V_8 , & V_8 -> V_376 ) ;
V_174 = F_139 ( & V_8 -> V_376 ) ;
if ( V_174 ) {
F_85 ( V_8 -> V_5 ,
L_48 ) ;
goto V_378;
}
F_132 ( V_8 , & V_8 -> V_379 , V_8 -> V_380 ,
0 , V_371 ) ;
F_137 ( V_8 -> V_379 . V_249 ) ;
F_138 ( V_251 , V_8 -> V_379 . V_249 ) ;
F_138 ( V_250 , V_8 -> V_379 . V_249 ) ;
F_138 ( V_362 , V_8 -> V_379 . V_249 ) ;
F_138 ( V_364 , V_8 -> V_372 . V_249 ) ;
F_135 ( V_8 , & V_8 -> V_379 ) ;
V_174 = F_139 ( & V_8 -> V_379 ) ;
if ( V_174 ) {
F_85 ( V_8 -> V_5 ,
L_49 ) ;
goto V_381;
}
return 0 ;
V_381:
F_140 ( & V_8 -> V_376 ) ;
V_378:
F_140 ( & V_8 -> V_372 ) ;
V_375:
return V_174 ;
}
static int T_9 F_141 ( struct V_202 * V_8 )
{
int V_33 ;
int V_382 = 0 ;
T_2 V_130 [ 2 ] ;
int V_383 = - 2 ;
V_130 [ 0 ] = F_51 ( V_8 -> V_9 + V_384 ) ;
V_130 [ 1 ] = F_51 ( V_8 -> V_9 + V_385 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_244 ; V_33 ++ ) {
V_8 -> V_242 [ V_33 ] . V_12 = V_33 ;
V_383 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_130 [ V_33 % 2 ] >> V_383 ) & 3 ) == 1 ) {
V_8 -> V_242 [ V_33 ] . V_229 = V_232 ;
V_8 -> V_242 [ V_33 ] . V_231 = V_232 ;
} else {
V_8 -> V_242 [ V_33 ] . V_229 = V_230 ;
V_8 -> V_242 [ V_33 ] . V_231 = V_230 ;
V_382 ++ ;
}
F_133 ( & V_8 -> V_242 [ V_33 ] . V_38 ) ;
}
for ( V_33 = 0 ; V_8 -> V_218 -> V_386 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_218 -> V_386 [ V_33 ] ;
V_8 -> V_242 [ V_4 ] . V_229 = V_232 ;
V_8 -> V_242 [ V_4 ] . V_231 = V_232 ;
V_382 -- ;
}
F_142 ( V_8 -> V_5 , L_50 ,
V_382 , V_8 -> V_244 ) ;
V_130 [ 0 ] = F_51 ( V_8 -> V_9 + V_387 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_244 ; V_33 ++ ) {
if ( V_8 -> V_242 [ V_33 ] . V_229 == V_230 &&
( V_130 [ 0 ] & 0x3 ) != 1 )
F_142 ( V_8 -> V_5 ,
L_51 ,
V_121 , V_33 , V_130 [ 0 ] & 0x3 ) ;
V_130 [ 0 ] = V_130 [ 0 ] >> 2 ;
}
return V_382 ;
}
static struct V_202 * T_9 F_143 ( struct V_388 * V_389 )
{
struct V_273 * V_218 ;
struct V_390 * V_390 = NULL ;
void T_1 * V_9 = NULL ;
struct V_391 * V_167 = NULL ;
struct V_202 * V_8 = NULL ;
int V_374 = 0 ;
int V_244 ;
int V_33 ;
T_2 V_392 ;
T_2 V_393 ;
T_10 V_169 ;
V_390 = F_144 ( & V_389 -> V_5 , NULL ) ;
if ( F_145 ( V_390 ) ) {
F_85 ( & V_389 -> V_5 , L_52 ) ;
goto V_394;
}
F_146 ( V_390 ) ;
V_167 = F_147 ( V_389 , V_395 , L_53 ) ;
if ( ! V_167 )
goto V_394;
if ( F_148 ( V_167 -> V_396 , F_149 ( V_167 ) ,
V_397 L_54 ) == NULL )
goto V_394;
V_9 = F_150 ( V_167 -> V_396 , F_149 ( V_167 ) ) ;
if ( ! V_9 )
goto V_394;
for ( V_392 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_392 |= ( F_51 ( V_9 + F_149 ( V_167 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_393 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_393 |= ( F_51 ( V_9 + F_149 ( V_167 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_393 != V_398 ) {
F_85 ( & V_389 -> V_5 , L_55 ) ;
goto V_394;
}
if ( F_151 ( V_392 ) != V_399 ) {
F_85 ( & V_389 -> V_5 , L_56 ,
F_151 ( V_392 ) ,
V_399 ) ;
goto V_394;
}
V_169 = F_152 ( V_392 ) ;
V_244 = 4 * ( F_51 ( V_9 + V_400 ) & 0x7 ) + 4 ;
F_142 ( & V_389 -> V_5 , L_57 ,
V_169 , V_167 -> V_396 ) ;
V_218 = V_389 -> V_5 . V_401 ;
for ( V_33 = 0 ; V_33 < V_218 -> V_402 ; V_33 ++ )
if ( V_218 -> V_222 [ V_33 ] != 0 )
V_374 ++ ;
for ( V_33 = 0 ; V_33 < V_218 -> V_402 ; V_33 ++ )
if ( V_218 -> V_219 [ V_33 ] != 0 )
V_374 ++ ;
V_8 = F_153 ( F_45 ( sizeof( struct V_202 ) , 4 ) +
( V_244 + V_374 + V_218 -> V_377 ) *
sizeof( struct V_2 ) , V_403 ) ;
if ( V_8 == NULL ) {
F_85 ( & V_389 -> V_5 , L_58 ) ;
goto V_394;
}
V_8 -> V_169 = V_169 ;
V_8 -> V_390 = V_390 ;
V_8 -> V_244 = V_244 ;
V_8 -> V_374 = V_374 ;
V_8 -> V_404 = V_167 -> V_396 ;
V_8 -> V_405 = F_149 ( V_167 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_218 = V_218 ;
V_8 -> V_5 = & V_389 -> V_5 ;
V_8 -> V_380 = ( ( void * ) V_8 ) + F_45 ( sizeof( struct V_202 ) , 4 ) ;
V_8 -> V_373 = & V_8 -> V_380 [ V_244 ] ;
V_8 -> V_242 = F_153 ( V_244 * sizeof( struct V_225 ) ,
V_403 ) ;
if ( ! V_8 -> V_242 )
goto V_394;
V_8 -> V_207 = F_153 ( V_244 *
sizeof( struct V_2 * ) ,
V_403 ) ;
if ( ! V_8 -> V_207 )
goto V_394;
if ( V_374 + V_218 -> V_377 ) {
V_8 -> V_208 = F_153 ( V_218 -> V_402 * 2 *
sizeof( struct V_2 * ) ,
V_403 ) ;
if ( ! V_8 -> V_208 )
goto V_394;
}
V_8 -> V_37 . V_40 = F_153 ( V_244 *
sizeof( struct V_14 * ) *
V_39 ,
V_403 ) ;
if ( ! V_8 -> V_37 . V_40 )
goto V_394;
V_8 -> V_48 = F_154 ( V_397 , sizeof( struct V_14 ) ,
0 , V_406 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_394;
return V_8 ;
V_394:
if ( ! F_145 ( V_390 ) ) {
F_155 ( V_390 ) ;
F_156 ( V_390 ) ;
}
if ( V_9 )
F_157 ( V_9 ) ;
if ( V_167 )
F_158 ( V_167 -> V_396 ,
F_149 ( V_167 ) ) ;
if ( V_9 )
F_157 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_208 ) ;
F_10 ( V_8 -> V_207 ) ;
F_10 ( V_8 -> V_242 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_159 ( struct V_202 * V_8 )
{
static const struct V_407 V_408 [] = {
{ . V_116 = V_409 , . V_130 = 0x0000ff01 } ,
{ . V_116 = V_410 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_411 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_412 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_413 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_185 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_187 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_189 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_191 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_184 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_186 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_188 , . V_130 = 0xFFFFFFFF } ,
{ . V_116 = V_190 , . V_130 = 0xFFFFFFFF }
} ;
int V_33 ;
T_2 V_414 [ 2 ] = { 0 , 0 } ;
T_2 V_415 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_416 = 0 ;
T_2 V_417 = 0 ;
for ( V_33 = 0 ; V_33 < F_82 ( V_408 ) ; V_33 ++ )
F_30 ( V_408 [ V_33 ] . V_130 ,
V_8 -> V_9 + V_408 [ V_33 ] . V_116 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_244 ; V_33 ++ ) {
V_415 [ V_33 % 2 ] = V_415 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_242 [ V_8 -> V_244 - V_33 - 1 ] . V_229
== V_232 ) {
V_415 [ V_33 % 2 ] |= 3 ;
continue;
}
V_416 = ( V_416 << 1 ) | 1 ;
V_417 = ( V_417 << 1 ) | 1 ;
V_414 [ V_33 % 2 ] = V_414 [ V_33 % 2 ] << 2 ;
V_414 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_414 [ 1 ] , V_8 -> V_9 + V_148 ) ;
F_30 ( V_414 [ 0 ] , V_8 -> V_9 + V_418 ) ;
F_30 ( V_415 [ 1 ] , V_8 -> V_9 + V_103 ) ;
F_30 ( V_415 [ 0 ] , V_8 -> V_9 + V_104 ) ;
F_30 ( V_416 , V_8 -> V_9 + V_419 ) ;
F_30 ( V_417 , V_8 -> V_9 + V_197 ) ;
}
static int T_9 F_160 ( struct V_202 * V_8 )
{
struct V_64 * V_65 = & V_8 -> V_37 ;
unsigned long * V_420 ;
int V_33 , V_241 ;
int V_34 = 0 ;
V_420 = F_6 ( sizeof( unsigned long ) * V_421 ,
V_403 ) ;
if ( ! V_420 ) {
V_34 = - V_25 ;
goto V_394;
}
V_8 -> V_37 . V_422 = V_423 * V_8 -> V_244 / V_424 ;
for ( V_33 = 0 ; V_33 < V_421 ; V_33 ++ ) {
V_420 [ V_33 ] = F_161 ( V_403 ,
V_8 -> V_37 . V_422 ) ;
if ( ! V_420 [ V_33 ] ) {
F_85 ( V_8 -> V_5 , L_59 ,
V_8 -> V_37 . V_422 ) ;
for ( V_241 = 0 ; V_241 < V_33 ; V_241 ++ )
F_162 ( V_420 [ V_241 ] , V_8 -> V_37 . V_422 ) ;
goto V_394;
}
if ( ( F_101 ( ( void * ) V_420 [ V_33 ] ) &
( V_425 - 1 ) ) == 0 )
break;
}
for ( V_241 = 0 ; V_241 < V_33 ; V_241 ++ )
F_162 ( V_420 [ V_241 ] , V_8 -> V_37 . V_422 ) ;
if ( V_33 < V_421 ) {
V_8 -> V_37 . V_8 = ( void * ) V_420 [ V_33 ] ;
} else {
F_163 ( V_8 -> V_5 ,
L_60 ,
V_121 , V_8 -> V_37 . V_422 ) ;
V_8 -> V_37 . V_426 = F_6 ( V_423 *
V_8 -> V_244 +
V_425 ,
V_403 ) ;
if ( ! V_8 -> V_37 . V_426 ) {
V_34 = - V_25 ;
goto V_394;
}
V_8 -> V_37 . V_8 = F_7 ( V_8 -> V_37 . V_426 ,
V_425 ) ;
}
V_65 -> V_29 = F_8 ( V_8 -> V_5 , V_65 -> V_8 ,
V_423 * V_8 -> V_244 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_65 -> V_29 ) ) {
V_65 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_394;
}
F_30 ( F_101 ( V_8 -> V_37 . V_8 ) ,
V_8 -> V_9 + V_427 ) ;
V_394:
F_10 ( V_420 ) ;
return V_34 ;
}
static int T_9 F_164 ( struct V_388 * V_389 )
{
int V_174 ;
int V_34 = - V_428 ;
struct V_202 * V_8 ;
struct V_391 * V_167 = NULL ;
int V_371 ;
T_2 V_130 ;
V_8 = F_143 ( V_389 ) ;
if ( ! V_8 )
goto V_394;
V_371 = F_141 ( V_8 ) ;
F_165 ( V_389 , V_8 ) ;
F_133 ( & V_8 -> V_203 ) ;
F_133 ( & V_8 -> V_102 ) ;
V_167 = F_147 ( V_389 , V_395 , L_61 ) ;
if ( ! V_167 ) {
V_34 = - V_428 ;
F_85 ( & V_389 -> V_5 , L_62 ) ;
goto V_394;
}
V_8 -> V_429 = F_149 ( V_167 ) ;
V_8 -> V_430 = V_167 -> V_396 ;
if ( F_148 ( V_167 -> V_396 , F_149 ( V_167 ) ,
V_397 L_63 ) == NULL ) {
V_34 = - V_110 ;
F_85 ( & V_389 -> V_5 ,
L_64 ,
V_167 -> V_396 , V_167 -> V_431 ) ;
goto V_394;
}
V_130 = F_51 ( V_8 -> V_9 + V_432 ) ;
if ( V_167 -> V_396 != V_130 && V_130 != 0 ) {
F_163 ( & V_389 -> V_5 ,
L_65 ,
V_121 , V_130 , V_167 -> V_396 ) ;
} else
F_30 ( V_167 -> V_396 , V_8 -> V_9 + V_432 ) ;
V_8 -> V_293 = F_150 ( V_167 -> V_396 , F_149 ( V_167 ) ) ;
if ( ! V_8 -> V_293 ) {
V_34 = - V_25 ;
F_85 ( & V_389 -> V_5 , L_66 ) ;
goto V_394;
}
V_34 = F_160 ( V_8 ) ;
if ( V_34 ) {
F_85 ( & V_389 -> V_5 , L_67 ) ;
goto V_394;
}
F_133 ( & V_8 -> V_37 . V_38 ) ;
V_8 -> V_181 = F_166 ( V_389 , 0 ) ;
V_34 = F_167 ( V_8 -> V_181 , F_81 , 0 , V_397 , V_8 ) ;
if ( V_34 ) {
F_85 ( & V_389 -> V_5 , L_68 ) ;
goto V_394;
}
V_174 = F_136 ( V_8 , V_371 ) ;
if ( V_174 )
goto V_394;
F_159 ( V_8 ) ;
F_142 ( V_8 -> V_5 , L_69 ) ;
return 0 ;
V_394:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_168 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_157 ( V_8 -> V_9 ) ;
if ( V_8 -> V_37 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_37 . V_29 ,
V_423 * V_8 -> V_244 ,
V_31 ) ;
if ( ! V_8 -> V_37 . V_426 && V_8 -> V_37 . V_8 )
F_162 ( ( unsigned long ) V_8 -> V_37 . V_8 ,
V_8 -> V_37 . V_422 ) ;
F_10 ( V_8 -> V_37 . V_426 ) ;
if ( V_8 -> V_430 )
F_158 ( V_8 -> V_430 ,
V_8 -> V_429 ) ;
if ( V_8 -> V_404 )
F_158 ( V_8 -> V_404 ,
V_8 -> V_405 ) ;
if ( V_8 -> V_390 ) {
F_155 ( V_8 -> V_390 ) ;
F_156 ( V_8 -> V_390 ) ;
}
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_208 ) ;
F_10 ( V_8 -> V_207 ) ;
F_10 ( V_8 -> V_242 ) ;
F_10 ( V_8 ) ;
}
F_85 ( & V_389 -> V_5 , L_70 ) ;
return V_34 ;
}
static int T_9 F_169 ( void )
{
return F_170 ( & V_433 , F_164 ) ;
}
