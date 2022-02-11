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
F_11 ( V_3 , V_45 ) ;
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
F_28 ( & V_43 -> V_42 , & V_3 -> V_79 ) ;
}
static struct V_14 * F_39 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_79 ) )
return NULL ;
V_45 = F_37 ( & V_3 -> V_79 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static int F_40 ( bool V_17 , int V_80 )
{
if ( V_17 ) {
if ( V_80 == V_81 )
return 1 ;
} else {
if ( V_80 == V_82 )
return 1 ;
}
return 2 << V_80 ;
}
static int F_41 ( int V_23 , T_2 V_83 , T_2 V_84 )
{
int V_85 ;
T_2 V_86 = F_42 ( V_83 , V_84 ) ;
T_2 V_87 = F_43 ( V_83 , V_84 ) ;
T_2 V_88 = F_44 ( V_89 << V_87 , 1 << V_86 ) ;
if ( V_88 > V_89 )
V_88 -= ( 1 << V_86 ) ;
if ( ! F_45 ( V_23 , 1 << V_86 ) )
return - V_35 ;
if ( V_23 <= V_88 )
V_85 = 1 ;
else {
V_85 = V_23 / V_88 ;
if ( V_85 * V_88 < V_23 )
V_85 ++ ;
}
return V_85 ;
}
static int F_46 ( struct V_90 * V_91 , int V_92 ,
T_2 V_83 , T_2 V_84 )
{
struct V_90 * V_93 ;
int V_33 ;
int V_94 = 0 ;
int V_34 ;
F_47 (sgl, sg, sg_len, i) {
V_34 = F_41 ( F_48 ( V_93 ) ,
V_83 , V_84 ) ;
if ( V_34 < 0 )
return V_34 ;
V_94 += V_34 ;
}
return V_94 ;
}
static int F_49 ( struct V_2 * V_3 ,
enum V_95 V_96 )
{
T_2 V_97 ;
int V_33 ;
void T_1 * V_98 ;
int V_34 = 0 ;
unsigned long V_32 ;
T_2 V_99 ;
F_14 ( & V_3 -> V_8 -> V_100 , V_32 ) ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_98 = V_3 -> V_8 -> V_9 + V_101 ;
else
V_98 = V_3 -> V_8 -> V_9 + V_102 ;
if ( V_96 == V_103 ) {
V_97 = ( F_50 ( V_98 ) &
F_51 ( V_3 -> V_11 -> V_12 ) ) >>
F_52 ( V_3 -> V_11 -> V_12 ) ;
if ( V_97 == V_104 || V_97 == V_105 )
goto V_106;
}
V_99 = 0xffffffff & ~ ( F_51 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_99 | ( V_96 << F_52 ( V_3 -> V_11 -> V_12 ) ) ,
V_98 ) ;
if ( V_96 == V_103 ) {
for ( V_33 = 0 ; V_33 < V_107 ; V_33 ++ ) {
V_97 = ( F_50 ( V_98 ) &
F_51 ( V_3 -> V_11 -> V_12 ) ) >>
F_52 ( V_3 -> V_11 -> V_12 ) ;
F_53 () ;
F_54 ( 3 ) ;
if ( V_97 == V_105 ||
V_97 == V_104 )
break;
}
if ( V_33 == V_107 ) {
F_55 ( V_3 ,
L_1 ,
V_3 -> V_11 -> V_12 , V_3 -> V_6 ,
V_97 ) ;
F_56 () ;
V_34 = - V_108 ;
}
}
V_106:
F_15 ( & V_3 -> V_8 -> V_100 , V_32 ) ;
return V_34 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
while ( ( V_15 = F_36 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
while ( ( V_15 = F_39 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
V_3 -> V_109 = 0 ;
V_3 -> V_110 = false ;
}
static void F_58 ( struct V_2 * V_3 , bool V_111 ,
T_2 V_112 , int V_113 )
{
void T_1 * V_114 = F_4 ( V_3 ) + V_113 ;
int V_115 ;
if ( ! V_111 ) {
F_30 ( ( V_116 << F_59 ( V_112 ) )
| ~ F_60 ( V_112 ) , V_114 ) ;
return;
}
V_115 = 100 ;
while ( -- V_115 ) {
F_30 ( ( V_117 << F_59 ( V_112 ) )
| ~ F_60 ( V_112 ) , V_114 ) ;
if ( F_50 ( V_114 ) & F_60 ( V_112 ) )
break;
}
if ( V_115 != 99 )
F_61 ( F_1 ( V_3 ) ,
L_2 ,
V_118 , V_113 == V_59 ? 'S' : 'D' ,
100 - V_115 ) ;
F_62 ( ! V_115 ) ;
}
static void F_63 ( struct V_2 * V_3 , bool V_119 )
{
unsigned long V_32 ;
F_14 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
if ( ( V_3 -> V_120 . V_121 == V_122 ) ||
( V_3 -> V_120 . V_121 == V_123 ) ) {
T_2 V_112 = F_64 ( V_3 -> V_120 . V_124 ) ;
F_58 ( V_3 , V_119 , V_112 ,
V_59 ) ;
}
if ( V_3 -> V_120 . V_121 != V_122 ) {
T_2 V_112 = F_64 ( V_3 -> V_120 . V_125 ) ;
F_58 ( V_3 , V_119 , V_112 ,
V_63 ) ;
}
F_15 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
}
static T_2 F_65 ( struct V_2 * V_3 )
{
void T_1 * V_126 = F_4 ( V_3 ) ;
T_2 V_127 ;
V_127 = F_50 ( V_126 + V_59 ) ;
V_127 |= F_50 ( V_126 + V_63 ) ;
return V_127 ;
}
static T_2 F_66 ( struct V_2 * V_3 )
{
static const unsigned int V_128 [] = {
[ V_129 ]
= V_130 ,
[ V_131 ]
= V_132 ,
[ V_133 ]
= V_134 ,
} ;
static const unsigned int V_135 [] = {
[ V_136 ]
= V_137 ,
[ V_138 ]
= V_139 ,
[ V_140 ]
= V_141 ,
} ;
if ( F_2 ( V_3 ) )
return V_128 [ V_3 -> V_120 . V_142 ] ;
else
return V_135 [ V_3 -> V_120 . V_142 ] ;
}
static void F_67 ( struct V_2 * V_3 )
{
T_2 V_143 ;
T_2 V_144 ;
V_143 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_144 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_52 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_144 , V_3 -> V_8 -> V_9 + V_145 + V_143 ) ;
V_144 = F_66 ( V_3 ) << F_52 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_144 , V_3 -> V_8 -> V_9 + V_146 + V_143 ) ;
if ( F_3 ( V_3 ) ) {
int V_147 = ( V_3 -> V_11 -> V_12 << V_148 )
& V_149 ;
void T_1 * V_126 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_150 , V_126 + V_53 ) ;
F_30 ( V_3 -> V_151 , V_126 + V_60 ) ;
F_30 ( V_147 , V_126 + V_55 ) ;
F_30 ( V_147 , V_126 + V_61 ) ;
}
}
static T_2 F_68 ( struct V_2 * V_3 )
{
T_2 V_152 ;
if ( F_3 ( V_3 ) )
V_152 = ( F_50 ( & V_3 -> V_74 -> V_153 ) & V_154 )
>> V_155 ;
else {
T_2 V_127 = F_50 ( F_4 ( V_3 ) + V_61 ) ;
V_152 = ( V_127 & V_156 )
>> V_157 ;
}
return V_152 * ( 1 << V_3 -> V_120 . V_158 . V_159 ) ;
}
static bool F_69 ( struct V_2 * V_3 )
{
bool V_160 ;
if ( F_3 ( V_3 ) )
V_160 = F_50 ( & V_3 -> V_74 -> V_161 ) & V_162 ;
else
V_160 = F_50 ( F_4 ( V_3 ) + V_63 )
& V_163 ;
return V_160 ;
}
static int F_70 ( struct V_2 * V_3 )
{
int V_164 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_110 )
return 0 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_164 = F_49 ( V_3 , V_103 ) ;
if ( V_164 == 0 ) {
if ( F_3 ( V_3 ) ) {
F_63 ( V_3 , false ) ;
if ( F_65 ( V_3 ) )
V_164 = F_49 ( V_3 ,
V_165 ) ;
}
}
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_164 ;
}
static int F_71 ( struct V_2 * V_3 )
{
int V_164 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_110 )
return 0 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( V_3 -> V_8 -> V_166 == 0 )
if ( F_3 ( V_3 ) ) {
V_164 = F_49 ( V_3 ,
V_103 ) ;
goto V_167;
}
if ( F_68 ( V_3 ) || F_69 ( V_3 ) ) {
if ( F_3 ( V_3 ) )
F_63 ( V_3 , true ) ;
V_164 = F_49 ( V_3 , V_165 ) ;
}
V_167:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_164 ;
}
static int F_72 ( struct V_2 * V_4 )
{
unsigned long V_32 ;
int V_34 = 0 ;
V_34 = F_70 ( V_4 ) ;
if ( ! V_34 && F_2 ( V_4 ) )
V_34 = F_49 ( V_4 , V_105 ) ;
F_14 ( & V_4 -> V_38 , V_32 ) ;
F_57 ( V_4 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return V_34 ;
}
static T_3 F_73 ( struct V_168 * V_169 )
{
struct V_2 * V_3 = F_74 ( V_169 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_74 ( V_169 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_3 -> V_4 . V_170 ++ ;
if ( V_3 -> V_4 . V_170 < 0 )
V_3 -> V_4 . V_170 = 1 ;
V_15 -> V_47 . V_170 = V_3 -> V_4 . V_170 ;
F_38 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_169 -> V_170 ;
}
static int F_75 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_166 == 0 ) {
int V_171 ;
if ( F_3 ( V_3 ) ) {
V_171 = F_49 ( V_3 ,
V_103 ) ;
if ( V_171 )
return V_171 ;
}
}
if ( F_3 ( V_3 ) )
F_63 ( V_3 , true ) ;
return F_49 ( V_3 , V_165 ) ;
}
static struct V_14 * F_76 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_171 ;
V_15 = F_39 ( V_3 ) ;
if ( V_15 != NULL ) {
V_3 -> V_110 = true ;
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
V_171 = F_75 ( V_3 ) ;
if ( V_171 )
return NULL ;
}
return V_15 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_69 ) {
if ( V_15 -> V_68 < V_15 -> V_16
&& ! F_69 ( V_3 )
&& ! F_68 ( V_3 ) ) {
F_16 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
( void ) F_75 ( V_3 ) ;
if ( V_15 -> V_68 == V_15 -> V_16 )
V_15 -> V_68 = 0 ;
}
} else {
F_16 ( V_3 , V_15 ) ;
if ( V_15 -> V_68 < V_15 -> V_16 ) {
F_35 ( V_3 , V_15 ) ;
( void ) F_75 ( V_3 ) ;
return;
}
if ( F_76 ( V_3 ) == NULL )
V_3 -> V_110 = false ;
}
V_3 -> V_109 ++ ;
F_78 ( & V_3 -> V_172 ) ;
}
static void F_79 ( unsigned long V_173 )
{
struct V_2 * V_3 = (struct V_2 * ) V_173 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
T_4 V_174 ;
void * V_175 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
goto V_171;
if ( ! V_15 -> V_69 )
V_3 -> V_176 = V_15 -> V_47 . V_170 ;
if ( V_3 -> V_109 == 0 ) {
F_15 ( & V_3 -> V_38 , V_32 ) ;
return;
}
V_174 = V_15 -> V_47 . V_174 ;
V_175 = V_15 -> V_47 . V_175 ;
if ( ! V_15 -> V_69 ) {
if ( F_22 ( & V_15 -> V_47 ) ) {
F_11 ( V_3 , V_15 ) ;
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
} else {
if ( ! V_15 -> V_177 ) {
F_17 ( V_15 ) ;
F_16 ( V_3 , V_15 ) ;
F_28 ( & V_15 -> V_42 , & V_3 -> V_44 ) ;
V_15 -> V_177 = true ;
}
}
}
V_3 -> V_109 -- ;
if ( V_3 -> V_109 )
F_78 ( & V_3 -> V_172 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
if ( V_174 && ( V_15 -> V_47 . V_32 & V_178 ) )
V_174 ( V_175 ) ;
return;
V_171:
if ( V_3 -> V_109 > 0 )
V_3 -> V_109 -- ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static T_5 F_80 ( int V_179 , void * V_173 )
{
static const struct V_180 V_181 [] = {
{ V_182 , V_183 , false , 0 } ,
{ V_184 , V_185 , false , 32 } ,
{ V_186 , V_187 , false , 64 } ,
{ V_188 , V_189 , false , 96 } ,
{ V_190 , V_183 , true , 0 } ,
{ V_191 , V_185 , true , 32 } ,
{ V_192 , V_187 , true , 64 } ,
{ V_193 , V_189 , true , 96 } ,
{ V_194 , V_195 , false , V_7 } ,
{ V_196 , V_195 , true , V_7 } ,
} ;
int V_33 ;
T_2 V_197 [ F_81 ( V_181 ) ] ;
T_2 V_198 ;
T_2 V_199 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_200 * V_8 = V_173 ;
F_14 ( & V_8 -> V_201 , V_32 ) ;
for ( V_33 = 0 ; V_33 < F_81 ( V_181 ) ; V_33 ++ )
V_197 [ V_33 ] = F_50 ( V_8 -> V_9 + V_181 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_82 ( ( unsigned long * ) V_197 ,
V_202 * F_81 ( V_181 ) , V_4 + 1 ) ;
if ( V_4 == V_202 * F_81 ( V_181 ) )
break;
V_199 = V_4 / V_202 ;
V_198 = V_4 & ( V_202 - 1 ) ;
F_30 ( 1 << V_198 , V_8 -> V_9 + V_181 [ V_199 ] . V_203 ) ;
if ( V_181 [ V_199 ] . V_204 == V_7 )
V_3 = V_8 -> V_205 [ V_198 ] ;
else
V_3 = V_8 -> V_206 [ V_181 [ V_199 ] . V_204 + V_198 ] ;
F_83 ( & V_3 -> V_38 ) ;
if ( ! V_181 [ V_199 ] . V_207 )
F_77 ( V_3 ) ;
else
F_84 ( V_8 -> V_5 , L_3 ,
V_4 , V_181 [ V_199 ] . V_204 , V_198 ) ;
F_85 ( & V_3 -> V_38 ) ;
}
F_15 ( & V_8 -> V_201 , V_32 ) ;
return V_208 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_209 * V_210 )
{
int V_164 = 0 ;
T_2 V_211 = F_87 ( V_210 -> V_125 ) ;
T_2 V_212 = F_87 ( V_210 -> V_124 ) ;
bool V_17 = V_210 -> V_213 == V_214 ;
if ( ! V_210 -> V_121 ) {
F_55 ( V_3 , L_4 ) ;
V_164 = - V_35 ;
}
if ( V_210 -> V_125 != V_215 &&
V_3 -> V_8 -> V_216 -> V_217 [ V_210 -> V_125 ] == 0 &&
V_3 -> V_218 == 0 ) {
F_55 ( V_3 , L_5 ,
V_210 -> V_125 ) ;
V_164 = - V_35 ;
}
if ( V_210 -> V_124 != V_219 &&
V_3 -> V_8 -> V_216 -> V_220 [ V_210 -> V_124 ] == 0 &&
V_3 -> V_218 == 0 ) {
F_55 ( V_3 , L_6 ,
V_210 -> V_124 ) ;
V_164 = - V_35 ;
}
if ( V_210 -> V_121 == V_221 &&
V_211 == V_215 ) {
F_55 ( V_3 , L_7 ) ;
V_164 = - V_35 ;
}
if ( V_210 -> V_121 == V_122 &&
V_212 == V_219 ) {
F_55 ( V_3 , L_8 ) ;
V_164 = - V_35 ;
}
if ( V_212 == V_219 &&
V_211 == V_215 && V_17 ) {
F_55 ( V_3 , L_9 ) ;
V_164 = - V_35 ;
}
if ( V_210 -> V_121 == V_123 &&
( V_212 != V_211 ) ) {
F_55 ( V_3 , L_10 ) ;
V_164 = - V_35 ;
}
if ( V_210 -> V_121 == V_123 ) {
F_55 ( V_3 , L_11 ) ;
V_164 = - V_35 ;
}
if ( F_40 ( V_17 , V_210 -> V_222 . V_80 ) *
( 1 << V_210 -> V_222 . V_159 ) !=
F_40 ( V_17 , V_210 -> V_158 . V_80 ) *
( 1 << V_210 -> V_158 . V_159 ) ) {
F_55 ( V_3 , L_12 ) ;
V_164 = - V_35 ;
}
return V_164 ;
}
static bool F_88 ( struct V_223 * V_224 , bool V_225 ,
int V_226 , bool V_17 )
{
unsigned long V_32 ;
F_14 ( & V_224 -> V_38 , V_32 ) ;
if ( ! V_17 ) {
if ( V_224 -> V_227 == V_228 &&
V_224 -> V_229 == V_228 ) {
V_224 -> V_229 = V_230 ;
V_224 -> V_227 = V_230 ;
goto V_231;
} else
goto V_232;
}
if ( V_225 ) {
if ( V_224 -> V_227 == V_230 )
goto V_232;
if ( V_224 -> V_227 == V_228 )
V_224 -> V_227 = V_233 ;
if ( ! ( V_224 -> V_227 & ( 1 << V_226 ) ) ) {
V_224 -> V_227 |= 1 << V_226 ;
goto V_231;
} else
goto V_232;
} else {
if ( V_224 -> V_229 == V_230 )
goto V_232;
if ( V_224 -> V_229 == V_228 )
V_224 -> V_229 = V_233 ;
if ( ! ( V_224 -> V_229 & ( 1 << V_226 ) ) ) {
V_224 -> V_229 |= 1 << V_226 ;
goto V_231;
} else
goto V_232;
}
V_232:
F_15 ( & V_224 -> V_38 , V_32 ) ;
return false ;
V_231:
F_15 ( & V_224 -> V_38 , V_32 ) ;
return true ;
}
static bool F_89 ( struct V_223 * V_224 , bool V_225 ,
int V_226 )
{
unsigned long V_32 ;
bool V_234 = false ;
F_14 ( & V_224 -> V_38 , V_32 ) ;
if ( ! V_226 ) {
V_224 -> V_229 = V_228 ;
V_224 -> V_227 = V_228 ;
V_234 = true ;
goto V_75;
}
if ( V_225 ) {
V_224 -> V_227 &= ~ ( 1 << V_226 ) ;
if ( V_224 -> V_227 == V_233 )
V_224 -> V_227 = V_228 ;
} else {
V_224 -> V_229 &= ~ ( 1 << V_226 ) ;
if ( V_224 -> V_229 == V_233 )
V_224 -> V_229 = V_228 ;
}
V_234 = ( ( V_224 -> V_227 | V_224 -> V_229 ) ==
V_228 ) ;
V_75:
F_15 ( & V_224 -> V_38 , V_32 ) ;
return V_234 ;
}
static int F_90 ( struct V_2 * V_3 )
{
int V_235 ;
int V_236 ;
int V_237 ;
struct V_223 * V_238 ;
int V_33 ;
int V_239 ;
int V_6 ;
bool V_225 ;
bool V_17 = V_3 -> V_120 . V_213 == V_214 ;
V_238 = V_3 -> V_8 -> V_240 ;
if ( V_3 -> V_120 . V_121 == V_122 ) {
V_235 = V_3 -> V_120 . V_124 ;
V_6 = 2 * V_235 ;
V_225 = true ;
} else if ( V_3 -> V_120 . V_121 == V_221 ||
V_3 -> V_120 . V_121 == V_241 ) {
V_235 = V_3 -> V_120 . V_125 ;
V_6 = 2 * V_235 + 1 ;
V_225 = false ;
} else
return - V_35 ;
V_236 = F_87 ( V_235 ) ;
V_237 = F_64 ( V_235 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_120 . V_121 == V_241 ) {
for ( V_33 = 0 ; V_33 < V_3 -> V_8 -> V_242 ; V_33 ++ ) {
if ( F_88 ( & V_238 [ V_33 ] , V_225 ,
0 , V_17 ) )
goto V_243;
}
} else
for ( V_239 = 0 ; V_239 < V_3 -> V_8 -> V_242 ; V_239 += 8 ) {
int V_244 = V_239 + V_236 * 2 ;
for ( V_33 = V_244 ; V_33 < V_244 + 2 ; V_33 ++ ) {
if ( F_88 ( & V_238 [ V_33 ] ,
V_225 ,
0 ,
V_17 ) )
goto V_243;
}
}
return - V_35 ;
V_243:
V_3 -> V_11 = & V_238 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_75;
}
if ( V_235 == - 1 )
return - V_35 ;
for ( V_239 = 0 ; V_239 < V_3 -> V_8 -> V_242 ; V_239 += 8 ) {
int V_244 = V_239 + V_236 * 2 ;
if ( V_225 ) {
for ( V_33 = V_244 ; V_33 < V_244 + 2 ; V_33 ++ ) {
if ( F_88 ( & V_238 [ V_33 ] , V_225 ,
V_237 , V_17 ) )
goto V_245;
}
} else {
for ( V_33 = V_244 + 1 ; V_33 >= V_244 ; V_33 -- ) {
if ( F_88 ( & V_238 [ V_33 ] , V_225 ,
V_237 , V_17 ) )
goto V_245;
}
}
}
return - V_35 ;
V_245:
V_3 -> V_11 = & V_238 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_75:
if ( V_17 )
V_3 -> V_8 -> V_206 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_205 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 )
{
T_6 V_246 = V_3 -> V_4 . V_1 -> V_247 ;
if ( F_92 ( V_248 , V_246 ) && ! F_92 ( V_249 , V_246 ) ) {
V_3 -> V_120 = * V_3 -> V_8 -> V_216 -> V_250 ;
V_3 -> V_120 . V_124 = V_219 ;
V_3 -> V_120 . V_125 = V_3 -> V_8 -> V_216 ->
memcpy [ V_3 -> V_4 . V_251 ] ;
} else if ( F_92 ( V_248 , V_246 ) &&
F_92 ( V_249 , V_246 ) ) {
V_3 -> V_120 = * V_3 -> V_8 -> V_216 -> V_252 ;
} else {
F_55 ( V_3 , L_13 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
int V_164 = 0 ;
T_2 V_112 ;
struct V_223 * V_224 = V_3 -> V_11 ;
bool V_225 ;
struct V_14 * V_45 ;
struct V_14 * V_46 ;
F_57 ( V_3 ) ;
if ( ! F_20 ( & V_3 -> V_44 ) )
F_21 (d, _d, &d40c->client, node) {
F_11 ( V_3 , V_45 ) ;
F_17 ( V_45 ) ;
F_25 ( V_3 , V_45 ) ;
}
if ( V_224 == NULL ) {
F_55 ( V_3 , L_14 ) ;
return - V_35 ;
}
if ( V_224 -> V_227 == V_228 &&
V_224 -> V_229 == V_228 ) {
F_55 ( V_3 , L_15 ) ;
return - V_35 ;
}
if ( V_3 -> V_120 . V_121 == V_221 ||
V_3 -> V_120 . V_121 == V_241 ) {
V_112 = F_64 ( V_3 -> V_120 . V_125 ) ;
V_225 = false ;
} else if ( V_3 -> V_120 . V_121 == V_122 ) {
V_112 = F_64 ( V_3 -> V_120 . V_124 ) ;
V_225 = true ;
} else {
F_55 ( V_3 , L_16 ) ;
return - V_35 ;
}
V_164 = F_49 ( V_3 , V_103 ) ;
if ( V_164 ) {
F_55 ( V_3 , L_17 ) ;
return V_164 ;
}
if ( F_3 ( V_3 ) ) {
F_63 ( V_3 , false ) ;
V_3 -> V_8 -> V_206 [ V_3 -> V_6 ] = NULL ;
if ( ! F_89 ( V_224 , V_225 , V_112 ) ) {
if ( F_65 ( V_3 ) ) {
V_164 = F_49 ( V_3 ,
V_165 ) ;
if ( V_164 ) {
F_55 ( V_3 ,
L_18 ) ;
return V_164 ;
}
}
return 0 ;
}
} else {
( void ) F_89 ( V_224 , V_225 , 0 ) ;
}
V_164 = F_49 ( V_3 , V_105 ) ;
if ( V_164 ) {
F_55 ( V_3 , L_19 ) ;
return V_164 ;
}
V_3 -> V_11 = NULL ;
V_3 -> V_253 = false ;
V_3 -> V_8 -> V_205 [ V_224 -> V_12 ] = NULL ;
return 0 ;
}
static bool F_94 ( struct V_2 * V_3 )
{
void T_1 * V_126 = F_4 ( V_3 ) ;
bool V_254 = false ;
unsigned long V_32 ;
void T_1 * V_98 ;
T_2 V_97 ;
T_2 V_112 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( F_2 ( V_3 ) ) {
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_98 = V_3 -> V_8 -> V_9 + V_101 ;
else
V_98 = V_3 -> V_8 -> V_9 + V_102 ;
V_97 = ( F_50 ( V_98 ) &
F_51 ( V_3 -> V_11 -> V_12 ) ) >>
F_52 ( V_3 -> V_11 -> V_12 ) ;
if ( V_97 == V_104 || V_97 == V_105 )
V_254 = true ;
goto V_255;
}
if ( V_3 -> V_120 . V_121 == V_221 ||
V_3 -> V_120 . V_121 == V_241 ) {
V_112 = F_64 ( V_3 -> V_120 . V_125 ) ;
V_97 = F_50 ( V_126 + V_63 ) ;
} else if ( V_3 -> V_120 . V_121 == V_122 ) {
V_112 = F_64 ( V_3 -> V_120 . V_124 ) ;
V_97 = F_50 ( V_126 + V_59 ) ;
} else {
F_55 ( V_3 , L_16 ) ;
goto V_255;
}
V_97 = ( V_97 & F_60 ( V_112 ) ) >>
F_59 ( V_112 ) ;
if ( V_97 != V_165 )
V_254 = true ;
V_255:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_254 ;
}
static T_2 F_95 ( struct V_256 * V_4 )
{
struct V_2 * V_3 =
F_74 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_257 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_257 = F_68 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_257 ;
}
static int
F_96 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_90 * V_258 , struct V_90 * V_259 ,
unsigned int V_92 , T_7 V_260 ,
T_7 V_261 )
{
struct V_209 * V_262 = & V_4 -> V_120 ;
struct V_263 * V_222 = & V_262 -> V_222 ;
struct V_263 * V_158 = & V_262 -> V_158 ;
int V_34 ;
V_34 = F_97 ( V_258 , V_92 ,
V_260 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_264 . V_265 ,
V_222 -> V_159 ,
V_158 -> V_159 ) ;
V_34 = F_97 ( V_259 , V_92 ,
V_261 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_264 . V_161 ,
V_158 -> V_159 ,
V_222 -> V_159 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_98 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_90 * V_258 , struct V_90 * V_259 ,
unsigned int V_92 , T_7 V_260 ,
T_7 V_261 )
{
struct V_209 * V_262 = & V_4 -> V_120 ;
struct V_263 * V_222 = & V_262 -> V_222 ;
struct V_263 * V_158 = & V_262 -> V_158 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_69 )
V_32 |= V_266 | V_73 ;
V_34 = F_99 ( V_258 , V_92 , V_260 ,
V_43 -> V_30 . V_27 ,
F_100 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_150 ,
V_222 , V_158 , V_32 ) ;
V_34 = F_99 ( V_259 , V_92 , V_261 ,
V_43 -> V_30 . V_28 ,
F_100 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_151 ,
V_158 , V_222 , V_32 ) ;
F_101 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_102 ( struct V_2 * V_4 , struct V_90 * V_93 ,
unsigned int V_92 , unsigned long V_267 )
{
struct V_209 * V_262 = & V_4 -> V_120 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_46 ( V_93 , V_92 , V_262 -> V_222 . V_159 ,
V_262 -> V_158 . V_159 ) ;
if ( V_43 -> V_16 < 0 ) {
F_55 ( V_4 , L_20 ) ;
goto V_171;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_55 ( V_4 , L_21 ) ;
goto V_171;
}
V_43 -> V_68 = 0 ;
V_43 -> V_47 . V_32 = V_267 ;
V_43 -> V_47 . V_268 = F_73 ;
F_103 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_171:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static T_7
F_104 ( struct V_2 * V_4 , enum V_269 V_270 )
{
struct V_271 * V_272 = V_4 -> V_8 -> V_216 ;
struct V_209 * V_262 = & V_4 -> V_120 ;
T_7 V_114 = 0 ;
if ( V_4 -> V_218 )
return V_4 -> V_218 ;
if ( V_270 == V_273 )
V_114 = V_272 -> V_220 [ V_262 -> V_124 ] ;
else if ( V_270 == V_31 )
V_114 = V_272 -> V_217 [ V_262 -> V_125 ] ;
return V_114 ;
}
static struct V_168 *
F_105 ( struct V_256 * V_274 , struct V_90 * V_258 ,
struct V_90 * V_259 , unsigned int V_92 ,
enum V_269 V_270 , unsigned long V_267 )
{
struct V_2 * V_4 = F_74 ( V_274 , struct V_2 , V_4 ) ;
T_7 V_260 = 0 ;
T_7 V_261 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_55 ( V_4 , L_22 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_38 , V_32 ) ;
V_43 = F_102 ( V_4 , V_258 , V_92 , V_267 ) ;
if ( V_43 == NULL )
goto V_171;
if ( F_106 ( & V_258 [ V_92 - 1 ] ) == V_258 )
V_43 -> V_69 = true ;
if ( V_270 != V_275 ) {
T_7 V_276 = F_104 ( V_4 , V_270 ) ;
if ( V_270 == V_273 )
V_260 = V_276 ;
else if ( V_270 == V_31 )
V_261 = V_276 ;
}
if ( F_3 ( V_4 ) )
V_34 = F_96 ( V_4 , V_43 , V_258 , V_259 ,
V_92 , V_260 , V_261 ) ;
else
V_34 = F_98 ( V_4 , V_43 , V_258 , V_259 ,
V_92 , V_260 , V_261 ) ;
if ( V_34 ) {
F_55 ( V_4 , L_23 ,
F_3 ( V_4 ) ? L_24 : L_25 , V_34 ) ;
goto V_171;
}
F_15 ( & V_4 -> V_38 , V_32 ) ;
return & V_43 -> V_47 ;
V_171:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return NULL ;
}
bool F_107 ( struct V_256 * V_4 , void * V_173 )
{
struct V_209 * V_277 = V_173 ;
struct V_2 * V_3 =
F_74 ( V_4 , struct V_2 , V_4 ) ;
int V_171 ;
if ( V_173 ) {
V_171 = F_86 ( V_3 , V_277 ) ;
if ( ! V_171 )
V_3 -> V_120 = * V_277 ;
} else
V_171 = F_91 ( V_3 ) ;
if ( ! V_171 )
V_3 -> V_253 = true ;
return V_171 == 0 ;
}
static void F_108 ( struct V_2 * V_3 , int V_235 , bool V_27 )
{
bool V_278 = V_3 -> V_120 . V_278 ;
bool V_279 = V_3 -> V_120 . V_280 ;
T_2 V_281 = V_279 ? V_282 : V_283 ;
T_2 V_284 = V_278 ? V_285 : V_286 ;
T_2 V_112 = F_64 ( V_235 ) ;
T_2 V_287 = F_87 ( V_235 ) ;
T_2 V_288 = 1 << V_112 ;
if ( ! V_27 )
V_288 <<= 16 ;
F_30 ( V_288 , V_3 -> V_8 -> V_9 + V_281 + V_287 * 4 ) ;
F_30 ( V_288 , V_3 -> V_8 -> V_9 + V_284 + V_287 * 4 ) ;
}
static void F_109 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_166 < 3 )
return;
if ( ( V_3 -> V_120 . V_121 == V_122 ) ||
( V_3 -> V_120 . V_121 == V_123 ) )
F_108 ( V_3 , V_3 -> V_120 . V_124 , true ) ;
if ( ( V_3 -> V_120 . V_121 == V_221 ) ||
( V_3 -> V_120 . V_121 == V_123 ) )
F_108 ( V_3 , V_3 -> V_120 . V_125 , false ) ;
}
static int F_110 ( struct V_256 * V_4 )
{
int V_171 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_74 ( V_4 , struct V_2 , V_4 ) ;
bool V_289 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_3 -> V_176 = V_4 -> V_170 = 1 ;
if ( ! V_3 -> V_253 ) {
V_171 = F_91 ( V_3 ) ;
if ( V_171 ) {
F_55 ( V_3 , L_26 ) ;
goto V_290;
}
}
V_289 = ( V_3 -> V_11 == NULL ) ;
V_171 = F_90 ( V_3 ) ;
if ( V_171 ) {
F_55 ( V_3 , L_27 ) ;
goto V_290;
}
F_111 ( & V_3 -> V_120 , & V_3 -> V_150 ,
& V_3 -> V_151 , F_3 ( V_3 ) ) ;
F_109 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
F_112 ( & V_3 -> V_120 ,
& V_3 -> V_264 . V_265 , & V_3 -> V_264 . V_161 ) ;
if ( V_3 -> V_120 . V_121 == V_122 )
V_3 -> V_74 = V_3 -> V_8 -> V_291 +
V_3 -> V_120 . V_124 * V_292 ;
else
V_3 -> V_74 = V_3 -> V_8 -> V_291 +
V_3 -> V_120 . V_125 *
V_292 + V_293 ;
}
if ( V_289 )
F_67 ( V_3 ) ;
V_290:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_171 ;
}
static void F_113 ( struct V_256 * V_4 )
{
struct V_2 * V_3 =
F_74 ( V_4 , struct V_2 , V_4 ) ;
int V_171 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_55 ( V_3 , L_28 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_171 = F_93 ( V_3 ) ;
if ( V_171 )
F_55 ( V_3 , L_29 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static struct V_168 * F_114 ( struct V_256 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_267 )
{
struct V_90 V_294 ;
struct V_90 V_295 ;
F_115 ( & V_294 , 1 ) ;
F_115 ( & V_295 , 1 ) ;
F_116 ( & V_294 ) = V_28 ;
F_116 ( & V_295 ) = V_27 ;
F_48 ( & V_294 ) = V_23 ;
F_48 ( & V_295 ) = V_23 ;
return F_105 ( V_4 , & V_295 , & V_294 , 1 , V_275 , V_267 ) ;
}
static struct V_168 *
F_117 ( struct V_256 * V_4 ,
struct V_90 * V_294 , unsigned int V_296 ,
struct V_90 * V_295 , unsigned int V_297 ,
unsigned long V_267 )
{
if ( V_296 != V_297 )
return NULL ;
return F_105 ( V_4 , V_295 , V_294 , V_297 , V_275 , V_267 ) ;
}
static struct V_168 * F_118 ( struct V_256 * V_4 ,
struct V_90 * V_91 ,
unsigned int V_92 ,
enum V_269 V_270 ,
unsigned long V_267 )
{
if ( V_270 != V_273 && V_270 != V_31 )
return NULL ;
return F_105 ( V_4 , V_91 , V_91 , V_92 , V_270 , V_267 ) ;
}
static struct V_168 *
F_119 ( struct V_256 * V_4 , T_7 V_29 ,
T_8 V_298 , T_8 V_299 ,
enum V_269 V_270 )
{
unsigned int V_300 = V_298 / V_299 ;
struct V_168 * V_47 ;
struct V_90 * V_93 ;
int V_33 ;
V_93 = F_120 ( V_300 + 1 , sizeof( struct V_90 ) , V_301 ) ;
for ( V_33 = 0 ; V_33 < V_300 ; V_33 ++ ) {
F_116 ( & V_93 [ V_33 ] ) = V_29 ;
F_48 ( & V_93 [ V_33 ] ) = V_299 ;
V_29 += V_299 ;
}
V_93 [ V_300 ] . V_204 = 0 ;
V_93 [ V_300 ] . V_302 = 0 ;
V_93 [ V_300 ] . V_303 =
( ( unsigned long ) V_93 | 0x01 ) & ~ 0x02 ;
V_47 = F_105 ( V_4 , V_93 , V_93 , V_300 , V_270 ,
V_178 ) ;
F_10 ( V_93 ) ;
return V_47 ;
}
static enum V_304 F_121 ( struct V_256 * V_4 ,
T_3 V_170 ,
struct V_305 * V_306 )
{
struct V_2 * V_3 = F_74 ( V_4 , struct V_2 , V_4 ) ;
T_3 V_307 ;
T_3 V_308 ;
int V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_55 ( V_3 , L_30 ) ;
return - V_35 ;
}
V_308 = V_3 -> V_176 ;
V_307 = V_4 -> V_170 ;
if ( F_94 ( V_3 ) )
V_34 = V_309 ;
else
V_34 = F_122 ( V_170 , V_308 , V_307 ) ;
F_123 ( V_306 , V_308 , V_307 ,
F_95 ( V_4 ) ) ;
return V_34 ;
}
static void F_124 ( struct V_256 * V_4 )
{
struct V_2 * V_3 = F_74 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_55 ( V_3 , L_31 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( ! V_3 -> V_110 )
( void ) F_76 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static void F_125 ( struct V_256 * V_4 ,
struct V_310 * V_311 )
{
struct V_2 * V_3 = F_74 ( V_4 , struct V_2 , V_4 ) ;
struct V_209 * V_262 = & V_3 -> V_120 ;
enum V_312 V_313 ;
T_7 V_314 ;
T_2 V_315 ;
enum V_316 V_317 ;
int V_80 ;
if ( V_311 -> V_270 == V_273 ) {
T_7 V_318 =
V_3 -> V_8 -> V_216 -> V_220 [ V_262 -> V_124 ] ;
V_314 = V_311 -> V_319 ;
if ( V_318 )
F_61 ( V_3 -> V_8 -> V_5 ,
L_32
L_33 ,
V_318 , V_314 ) ;
if ( V_262 -> V_121 != V_122 )
F_61 ( V_3 -> V_8 -> V_5 ,
L_34
L_35 ,
V_262 -> V_121 ) ;
V_262 -> V_121 = V_122 ;
V_313 = V_311 -> V_320 ;
V_315 = V_311 -> V_321 ;
} else if ( V_311 -> V_270 == V_31 ) {
T_7 V_322 =
V_3 -> V_8 -> V_216 -> V_217 [ V_262 -> V_125 ] ;
V_314 = V_311 -> V_323 ;
if ( V_322 )
F_61 ( V_3 -> V_8 -> V_5 ,
L_36
L_33 ,
V_322 , V_314 ) ;
if ( V_262 -> V_121 != V_221 )
F_61 ( V_3 -> V_8 -> V_5 ,
L_37
L_38 ,
V_262 -> V_121 ) ;
V_262 -> V_121 = V_221 ;
V_313 = V_311 -> V_324 ;
V_315 = V_311 -> V_325 ;
} else {
F_126 ( V_3 -> V_8 -> V_5 ,
L_39 ,
V_311 -> V_270 ) ;
return;
}
switch ( V_313 ) {
case V_326 :
V_317 = V_327 ;
break;
case V_328 :
V_317 = V_329 ;
break;
case V_330 :
V_317 = V_331 ;
break;
case V_332 :
V_317 = V_333 ;
break;
default:
F_126 ( V_3 -> V_8 -> V_5 ,
L_40
L_41 ,
V_311 -> V_320 ) ;
return;
}
if ( F_3 ( V_3 ) ) {
if ( V_315 >= 16 )
V_80 = V_334 ;
else if ( V_315 >= 8 )
V_80 = V_335 ;
else if ( V_315 >= 4 )
V_80 = V_336 ;
else
V_80 = V_81 ;
} else {
if ( V_315 >= 16 )
V_80 = V_337 ;
else if ( V_315 >= 8 )
V_80 = V_338 ;
else if ( V_315 >= 4 )
V_80 = V_339 ;
else if ( V_315 >= 2 )
V_80 = V_340 ;
else
V_80 = V_82 ;
}
V_262 -> V_222 . V_159 = V_317 ;
V_262 -> V_222 . V_80 = V_80 ;
V_262 -> V_222 . V_341 = false ;
V_262 -> V_222 . V_342 = V_343 ;
V_262 -> V_158 . V_159 = V_317 ;
V_262 -> V_158 . V_80 = V_80 ;
V_262 -> V_158 . V_341 = false ;
V_262 -> V_158 . V_342 = V_343 ;
if ( F_3 ( V_3 ) )
F_112 ( V_262 , & V_3 -> V_264 . V_265 , & V_3 -> V_264 . V_161 ) ;
else
F_111 ( V_262 , & V_3 -> V_150 ,
& V_3 -> V_151 , false ) ;
V_3 -> V_218 = V_314 ;
V_3 -> V_344 = V_311 -> V_270 ;
F_61 ( V_3 -> V_8 -> V_5 ,
L_42
L_43 ,
F_127 ( V_4 ) ,
( V_311 -> V_270 == V_273 ) ? L_44 : L_45 ,
V_313 ,
V_315 ) ;
}
static int F_128 ( struct V_256 * V_4 , enum V_345 V_346 ,
unsigned long V_347 )
{
struct V_2 * V_3 = F_74 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_55 ( V_3 , L_31 ) ;
return - V_35 ;
}
switch ( V_346 ) {
case V_348 :
return F_72 ( V_3 ) ;
case V_349 :
return F_70 ( V_3 ) ;
case V_350 :
return F_71 ( V_3 ) ;
case V_351 :
F_125 ( V_4 ,
(struct V_310 * ) V_347 ) ;
return 0 ;
default:
break;
}
return - V_352 ;
}
static void T_9 F_129 ( struct V_200 * V_8 , struct V_353 * V_354 ,
struct V_2 * V_355 , int V_204 ,
int V_356 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_354 -> V_357 ) ;
for ( V_33 = V_204 ; V_33 < V_204 + V_356 ; V_33 ++ ) {
V_3 = & V_355 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_354 ;
F_130 ( & V_3 -> V_38 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_79 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_131 ( & V_3 -> V_172 , F_79 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_358 ,
& V_354 -> V_357 ) ;
}
}
static void F_132 ( struct V_200 * V_8 , struct V_353 * V_5 )
{
if ( F_92 ( V_249 , V_5 -> V_247 ) )
V_5 -> V_359 = F_118 ;
if ( F_92 ( V_248 , V_5 -> V_247 ) ) {
V_5 -> V_360 = F_114 ;
V_5 -> V_361 = 2 ;
}
if ( F_92 ( V_362 , V_5 -> V_247 ) )
V_5 -> V_363 = F_117 ;
if ( F_92 ( V_364 , V_5 -> V_247 ) )
V_5 -> V_365 = F_119 ;
V_5 -> V_366 = F_110 ;
V_5 -> V_367 = F_113 ;
V_5 -> V_368 = F_124 ;
V_5 -> V_369 = F_121 ;
V_5 -> V_370 = F_128 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_133 ( struct V_200 * V_8 ,
int V_371 )
{
int V_171 ;
F_129 ( V_8 , & V_8 -> V_372 , V_8 -> V_373 ,
0 , V_8 -> V_374 ) ;
F_134 ( V_8 -> V_372 . V_247 ) ;
F_135 ( V_249 , V_8 -> V_372 . V_247 ) ;
F_135 ( V_364 , V_8 -> V_372 . V_247 ) ;
F_132 ( V_8 , & V_8 -> V_372 ) ;
V_171 = F_136 ( & V_8 -> V_372 ) ;
if ( V_171 ) {
F_84 ( V_8 -> V_5 , L_46 ) ;
goto V_375;
}
F_129 ( V_8 , & V_8 -> V_376 , V_8 -> V_373 ,
V_8 -> V_374 , V_8 -> V_216 -> V_377 ) ;
F_134 ( V_8 -> V_376 . V_247 ) ;
F_135 ( V_248 , V_8 -> V_376 . V_247 ) ;
F_135 ( V_362 , V_8 -> V_376 . V_247 ) ;
F_132 ( V_8 , & V_8 -> V_376 ) ;
V_171 = F_136 ( & V_8 -> V_376 ) ;
if ( V_171 ) {
F_84 ( V_8 -> V_5 ,
L_47 ) ;
goto V_378;
}
F_129 ( V_8 , & V_8 -> V_379 , V_8 -> V_380 ,
0 , V_371 ) ;
F_134 ( V_8 -> V_379 . V_247 ) ;
F_135 ( V_249 , V_8 -> V_379 . V_247 ) ;
F_135 ( V_248 , V_8 -> V_379 . V_247 ) ;
F_135 ( V_362 , V_8 -> V_379 . V_247 ) ;
F_135 ( V_364 , V_8 -> V_372 . V_247 ) ;
F_132 ( V_8 , & V_8 -> V_379 ) ;
V_171 = F_136 ( & V_8 -> V_379 ) ;
if ( V_171 ) {
F_84 ( V_8 -> V_5 ,
L_48 ) ;
goto V_381;
}
return 0 ;
V_381:
F_137 ( & V_8 -> V_376 ) ;
V_378:
F_137 ( & V_8 -> V_372 ) ;
V_375:
return V_171 ;
}
static int T_9 F_138 ( struct V_200 * V_8 )
{
int V_33 ;
int V_382 = 0 ;
T_2 V_127 [ 2 ] ;
int V_383 = - 2 ;
V_127 [ 0 ] = F_50 ( V_8 -> V_9 + V_384 ) ;
V_127 [ 1 ] = F_50 ( V_8 -> V_9 + V_385 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_242 ; V_33 ++ ) {
V_8 -> V_240 [ V_33 ] . V_12 = V_33 ;
V_383 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_127 [ V_33 % 2 ] >> V_383 ) & 3 ) == 1 ) {
V_8 -> V_240 [ V_33 ] . V_227 = V_230 ;
V_8 -> V_240 [ V_33 ] . V_229 = V_230 ;
} else {
V_8 -> V_240 [ V_33 ] . V_227 = V_228 ;
V_8 -> V_240 [ V_33 ] . V_229 = V_228 ;
V_382 ++ ;
}
F_130 ( & V_8 -> V_240 [ V_33 ] . V_38 ) ;
}
for ( V_33 = 0 ; V_8 -> V_216 -> V_386 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_216 -> V_386 [ V_33 ] ;
V_8 -> V_240 [ V_4 ] . V_227 = V_230 ;
V_8 -> V_240 [ V_4 ] . V_229 = V_230 ;
V_382 -- ;
}
F_139 ( V_8 -> V_5 , L_49 ,
V_382 , V_8 -> V_242 ) ;
V_127 [ 0 ] = F_50 ( V_8 -> V_9 + V_387 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_242 ; V_33 ++ ) {
if ( V_8 -> V_240 [ V_33 ] . V_227 == V_228 &&
( V_127 [ 0 ] & 0x3 ) != 1 )
F_139 ( V_8 -> V_5 ,
L_50 ,
V_118 , V_33 , V_127 [ 0 ] & 0x3 ) ;
V_127 [ 0 ] = V_127 [ 0 ] >> 2 ;
}
return V_382 ;
}
static struct V_200 * T_9 F_140 ( struct V_388 * V_389 )
{
static const struct V_390 V_391 [] = {
{ . V_113 = V_392 , . V_127 = 0x0040 } ,
{ . V_113 = V_393 , . V_127 = 0x0000 } ,
{ . V_113 = V_394 , . V_127 = 0x0000 } ,
{ . V_113 = V_395 , . V_127 = 0x000d } ,
{ . V_113 = V_396 , . V_127 = 0x00f0 } ,
{ . V_113 = V_397 , . V_127 = 0x0005 } ,
{ . V_113 = V_398 , . V_127 = 0x00b1 }
} ;
struct V_271 * V_216 ;
struct V_399 * V_399 = NULL ;
void T_1 * V_9 = NULL ;
struct V_400 * V_164 = NULL ;
struct V_200 * V_8 = NULL ;
int V_374 = 0 ;
int V_242 ;
int V_33 ;
T_2 V_127 ;
T_2 V_166 ;
V_399 = F_141 ( & V_389 -> V_5 , NULL ) ;
if ( F_142 ( V_399 ) ) {
F_84 ( & V_389 -> V_5 , L_51 ) ;
goto V_401;
}
F_143 ( V_399 ) ;
V_164 = F_144 ( V_389 , V_402 , L_52 ) ;
if ( ! V_164 )
goto V_401;
if ( F_145 ( V_164 -> V_403 , F_146 ( V_164 ) ,
V_404 L_53 ) == NULL )
goto V_401;
V_9 = F_147 ( V_164 -> V_403 , F_146 ( V_164 ) ) ;
if ( ! V_9 )
goto V_401;
for ( V_33 = 0 ; V_33 < F_81 ( V_391 ) ; V_33 ++ ) {
if ( V_391 [ V_33 ] . V_127 !=
F_50 ( V_9 + V_391 [ V_33 ] . V_113 ) ) {
F_84 ( & V_389 -> V_5 ,
L_54 ,
V_391 [ V_33 ] . V_127 ,
V_391 [ V_33 ] . V_113 ,
F_50 ( V_9 + V_391 [ V_33 ] . V_113 ) ) ;
goto V_401;
}
}
V_127 = F_50 ( V_9 + V_405 ) ;
if ( ( V_127 & V_406 ) !=
V_407 ) {
F_84 ( & V_389 -> V_5 , L_55 ,
V_127 & V_406 ,
V_407 ) ;
goto V_401;
}
V_166 = ( V_127 & V_408 ) >>
V_409 ;
V_242 = 4 * ( F_50 ( V_9 + V_410 ) & 0x7 ) + 4 ;
F_139 ( & V_389 -> V_5 , L_56 ,
V_166 , V_164 -> V_403 ) ;
V_216 = V_389 -> V_5 . V_411 ;
for ( V_33 = 0 ; V_33 < V_216 -> V_412 ; V_33 ++ )
if ( V_216 -> V_220 [ V_33 ] != 0 )
V_374 ++ ;
for ( V_33 = 0 ; V_33 < V_216 -> V_412 ; V_33 ++ )
if ( V_216 -> V_217 [ V_33 ] != 0 )
V_374 ++ ;
V_8 = F_148 ( F_44 ( sizeof( struct V_200 ) , 4 ) +
( V_242 + V_374 + V_216 -> V_377 ) *
sizeof( struct V_2 ) , V_301 ) ;
if ( V_8 == NULL ) {
F_84 ( & V_389 -> V_5 , L_57 ) ;
goto V_401;
}
V_8 -> V_166 = V_166 ;
V_8 -> V_399 = V_399 ;
V_8 -> V_242 = V_242 ;
V_8 -> V_374 = V_374 ;
V_8 -> V_413 = V_164 -> V_403 ;
V_8 -> V_414 = F_146 ( V_164 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_216 = V_216 ;
V_8 -> V_5 = & V_389 -> V_5 ;
V_8 -> V_380 = ( ( void * ) V_8 ) + F_44 ( sizeof( struct V_200 ) , 4 ) ;
V_8 -> V_373 = & V_8 -> V_380 [ V_242 ] ;
V_8 -> V_240 = F_148 ( V_242 * sizeof( struct V_223 ) ,
V_301 ) ;
if ( ! V_8 -> V_240 )
goto V_401;
V_8 -> V_205 = F_148 ( V_242 *
sizeof( struct V_2 * ) ,
V_301 ) ;
if ( ! V_8 -> V_205 )
goto V_401;
if ( V_374 + V_216 -> V_377 ) {
V_8 -> V_206 = F_148 ( V_216 -> V_412 * 2 *
sizeof( struct V_2 * ) ,
V_301 ) ;
if ( ! V_8 -> V_206 )
goto V_401;
}
V_8 -> V_37 . V_40 = F_148 ( V_242 *
sizeof( struct V_14 * ) *
V_39 ,
V_301 ) ;
if ( ! V_8 -> V_37 . V_40 )
goto V_401;
V_8 -> V_48 = F_149 ( V_404 , sizeof( struct V_14 ) ,
0 , V_415 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_401;
return V_8 ;
V_401:
if ( ! F_142 ( V_399 ) ) {
F_150 ( V_399 ) ;
F_151 ( V_399 ) ;
}
if ( V_9 )
F_152 ( V_9 ) ;
if ( V_164 )
F_153 ( V_164 -> V_403 ,
F_146 ( V_164 ) ) ;
if ( V_9 )
F_152 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_206 ) ;
F_10 ( V_8 -> V_205 ) ;
F_10 ( V_8 -> V_240 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_154 ( struct V_200 * V_8 )
{
static const struct V_390 V_416 [] = {
{ . V_113 = V_417 , . V_127 = 0x0000ff01 } ,
{ . V_113 = V_418 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_419 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_420 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_421 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_183 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_185 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_187 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_189 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_182 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_184 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_186 , . V_127 = 0xFFFFFFFF } ,
{ . V_113 = V_188 , . V_127 = 0xFFFFFFFF }
} ;
int V_33 ;
T_2 V_422 [ 2 ] = { 0 , 0 } ;
T_2 V_423 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_424 = 0 ;
T_2 V_425 = 0 ;
for ( V_33 = 0 ; V_33 < F_81 ( V_416 ) ; V_33 ++ )
F_30 ( V_416 [ V_33 ] . V_127 ,
V_8 -> V_9 + V_416 [ V_33 ] . V_113 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_242 ; V_33 ++ ) {
V_423 [ V_33 % 2 ] = V_423 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_240 [ V_8 -> V_242 - V_33 - 1 ] . V_227
== V_230 ) {
V_423 [ V_33 % 2 ] |= 3 ;
continue;
}
V_424 = ( V_424 << 1 ) | 1 ;
V_425 = ( V_425 << 1 ) | 1 ;
V_422 [ V_33 % 2 ] = V_422 [ V_33 % 2 ] << 2 ;
V_422 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_422 [ 1 ] , V_8 -> V_9 + V_145 ) ;
F_30 ( V_422 [ 0 ] , V_8 -> V_9 + V_426 ) ;
F_30 ( V_423 [ 1 ] , V_8 -> V_9 + V_101 ) ;
F_30 ( V_423 [ 0 ] , V_8 -> V_9 + V_102 ) ;
F_30 ( V_424 , V_8 -> V_9 + V_427 ) ;
F_30 ( V_425 , V_8 -> V_9 + V_195 ) ;
}
static int T_9 F_155 ( struct V_200 * V_8 )
{
struct V_64 * V_65 = & V_8 -> V_37 ;
unsigned long * V_428 ;
int V_33 , V_239 ;
int V_34 = 0 ;
V_428 = F_6 ( sizeof( unsigned long ) * V_429 ,
V_301 ) ;
if ( ! V_428 ) {
V_34 = - V_25 ;
goto V_401;
}
V_8 -> V_37 . V_430 = V_431 * V_8 -> V_242 / V_432 ;
for ( V_33 = 0 ; V_33 < V_429 ; V_33 ++ ) {
V_428 [ V_33 ] = F_156 ( V_301 ,
V_8 -> V_37 . V_430 ) ;
if ( ! V_428 [ V_33 ] ) {
F_84 ( V_8 -> V_5 , L_58 ,
V_8 -> V_37 . V_430 ) ;
for ( V_239 = 0 ; V_239 < V_33 ; V_239 ++ )
F_157 ( V_428 [ V_239 ] , V_8 -> V_37 . V_430 ) ;
goto V_401;
}
if ( ( F_100 ( ( void * ) V_428 [ V_33 ] ) &
( V_433 - 1 ) ) == 0 )
break;
}
for ( V_239 = 0 ; V_239 < V_33 ; V_239 ++ )
F_157 ( V_428 [ V_239 ] , V_8 -> V_37 . V_430 ) ;
if ( V_33 < V_429 ) {
V_8 -> V_37 . V_8 = ( void * ) V_428 [ V_33 ] ;
} else {
F_158 ( V_8 -> V_5 ,
L_59 ,
V_118 , V_8 -> V_37 . V_430 ) ;
V_8 -> V_37 . V_434 = F_6 ( V_431 *
V_8 -> V_242 +
V_433 ,
V_301 ) ;
if ( ! V_8 -> V_37 . V_434 ) {
V_34 = - V_25 ;
goto V_401;
}
V_8 -> V_37 . V_8 = F_7 ( V_8 -> V_37 . V_434 ,
V_433 ) ;
}
V_65 -> V_29 = F_8 ( V_8 -> V_5 , V_65 -> V_8 ,
V_431 * V_8 -> V_242 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_65 -> V_29 ) ) {
V_65 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_401;
}
F_30 ( F_100 ( V_8 -> V_37 . V_8 ) ,
V_8 -> V_9 + V_435 ) ;
V_401:
F_10 ( V_428 ) ;
return V_34 ;
}
static int T_9 F_159 ( struct V_388 * V_389 )
{
int V_171 ;
int V_34 = - V_436 ;
struct V_200 * V_8 ;
struct V_400 * V_164 = NULL ;
int V_371 ;
T_2 V_127 ;
V_8 = F_140 ( V_389 ) ;
if ( ! V_8 )
goto V_401;
V_371 = F_138 ( V_8 ) ;
F_160 ( V_389 , V_8 ) ;
F_130 ( & V_8 -> V_201 ) ;
F_130 ( & V_8 -> V_100 ) ;
V_164 = F_144 ( V_389 , V_402 , L_60 ) ;
if ( ! V_164 ) {
V_34 = - V_436 ;
F_84 ( & V_389 -> V_5 , L_61 ) ;
goto V_401;
}
V_8 -> V_437 = F_146 ( V_164 ) ;
V_8 -> V_438 = V_164 -> V_403 ;
if ( F_145 ( V_164 -> V_403 , F_146 ( V_164 ) ,
V_404 L_62 ) == NULL ) {
V_34 = - V_108 ;
F_84 ( & V_389 -> V_5 ,
L_63 ,
V_164 -> V_403 , V_164 -> V_439 ) ;
goto V_401;
}
V_127 = F_50 ( V_8 -> V_9 + V_440 ) ;
if ( V_164 -> V_403 != V_127 && V_127 != 0 ) {
F_158 ( & V_389 -> V_5 ,
L_64 ,
V_118 , V_127 , V_164 -> V_403 ) ;
} else
F_30 ( V_164 -> V_403 , V_8 -> V_9 + V_440 ) ;
V_8 -> V_291 = F_147 ( V_164 -> V_403 , F_146 ( V_164 ) ) ;
if ( ! V_8 -> V_291 ) {
V_34 = - V_25 ;
F_84 ( & V_389 -> V_5 , L_65 ) ;
goto V_401;
}
V_34 = F_155 ( V_8 ) ;
if ( V_34 ) {
F_84 ( & V_389 -> V_5 , L_66 ) ;
goto V_401;
}
F_130 ( & V_8 -> V_37 . V_38 ) ;
V_8 -> V_179 = F_161 ( V_389 , 0 ) ;
V_34 = F_162 ( V_8 -> V_179 , F_80 , 0 , V_404 , V_8 ) ;
if ( V_34 ) {
F_84 ( & V_389 -> V_5 , L_67 ) ;
goto V_401;
}
V_171 = F_133 ( V_8 , V_371 ) ;
if ( V_171 )
goto V_401;
F_154 ( V_8 ) ;
F_139 ( V_8 -> V_5 , L_68 ) ;
return 0 ;
V_401:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_163 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_152 ( V_8 -> V_9 ) ;
if ( V_8 -> V_37 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_37 . V_29 ,
V_431 * V_8 -> V_242 ,
V_31 ) ;
if ( ! V_8 -> V_37 . V_434 && V_8 -> V_37 . V_8 )
F_157 ( ( unsigned long ) V_8 -> V_37 . V_8 ,
V_8 -> V_37 . V_430 ) ;
F_10 ( V_8 -> V_37 . V_434 ) ;
if ( V_8 -> V_438 )
F_153 ( V_8 -> V_438 ,
V_8 -> V_437 ) ;
if ( V_8 -> V_413 )
F_153 ( V_8 -> V_413 ,
V_8 -> V_414 ) ;
if ( V_8 -> V_399 ) {
F_150 ( V_8 -> V_399 ) ;
F_151 ( V_8 -> V_399 ) ;
}
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_206 ) ;
F_10 ( V_8 -> V_205 ) ;
F_10 ( V_8 -> V_240 ) ;
F_10 ( V_8 ) ;
}
F_84 ( & V_389 -> V_5 , L_69 ) ;
return V_34 ;
}
static int T_9 F_164 ( void )
{
return F_165 ( & V_441 , F_159 ) ;
}
