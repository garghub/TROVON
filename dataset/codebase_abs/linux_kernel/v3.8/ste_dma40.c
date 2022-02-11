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
if ( V_117 == V_121 ) {
V_34 = F_55 ( V_3 , V_122 ) ;
if ( V_34 )
return V_34 ;
}
F_14 ( & V_3 -> V_8 -> V_123 , V_32 ) ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_119 = V_3 -> V_8 -> V_9 + V_124 ;
else
V_119 = V_3 -> V_8 -> V_9 + V_125 ;
if ( V_117 == V_122 ) {
V_118 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
if ( V_118 == V_126 || V_118 == V_121 )
goto V_127;
}
V_120 = 0xffffffff & ~ ( F_57 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_120 | ( V_117 << F_58 ( V_3 -> V_11 -> V_12 ) ) ,
V_119 ) ;
if ( V_117 == V_122 ) {
for ( V_33 = 0 ; V_33 < V_128 ; V_33 ++ ) {
V_118 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
F_59 () ;
F_60 ( 3 ) ;
if ( V_118 == V_121 ||
V_118 == V_126 )
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
F_15 ( & V_3 -> V_8 -> V_123 , V_32 ) ;
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
}
static void F_64 ( struct V_2 * V_3 ,
enum V_132 V_133 , T_2 V_134 ,
int V_135 )
{
void T_1 * V_103 = F_4 ( V_3 ) + V_135 ;
int V_136 ;
T_2 V_118 ;
switch ( V_133 ) {
case V_137 :
F_30 ( ( V_137 << F_65 ( V_134 ) )
| ~ F_66 ( V_134 ) , V_103 ) ;
break;
case V_138 :
V_118 = ( F_56 ( V_103 ) & F_66 ( V_134 ) ) >>
F_65 ( V_134 ) ;
if ( V_118 == V_137 ||
V_118 == V_138 )
break;
F_30 ( ( V_138 << F_65 ( V_134 ) )
| ~ F_66 ( V_134 ) , V_103 ) ;
for ( V_136 = 0 ; V_136 < V_128 ; V_136 ++ ) {
V_118 = ( F_56 ( V_103 ) & F_66 ( V_134 ) ) >>
F_65 ( V_134 ) ;
F_59 () ;
F_60 ( 3 ) ;
if ( V_118 == V_137 )
break;
}
if ( V_136 == V_128 ) {
F_61 ( V_3 ,
L_2
L_3 , V_3 -> V_11 -> V_12 ,
V_3 -> V_6 , V_118 ) ;
}
break;
case V_139 :
V_136 = 100 ;
while ( -- V_136 ) {
F_30 ( ( V_139 <<
F_65 ( V_134 ) ) |
~ F_66 ( V_134 ) , V_103 ) ;
if ( F_56 ( V_103 ) & F_66 ( V_134 ) )
break;
}
if ( V_136 != 99 )
F_67 ( F_1 ( V_3 ) ,
L_4 ,
V_140 , V_135 == V_59 ? 'S' : 'D' ,
100 - V_136 ) ;
F_68 ( ! V_136 ) ;
break;
case V_141 :
F_69 () ;
break;
}
}
static void F_70 ( struct V_2 * V_3 ,
enum V_132 V_133 )
{
if ( ( V_3 -> V_142 . V_143 == V_144 ) ||
( V_3 -> V_142 . V_143 == V_145 ) ) {
T_2 V_134 = F_71 ( V_3 -> V_142 . V_146 ) ;
F_64 ( V_3 , V_133 , V_134 ,
V_59 ) ;
}
if ( V_3 -> V_142 . V_143 != V_144 ) {
T_2 V_134 = F_71 ( V_3 -> V_142 . V_147 ) ;
F_64 ( V_3 , V_133 , V_134 ,
V_63 ) ;
}
}
static T_2 F_72 ( struct V_2 * V_3 )
{
void T_1 * V_148 = F_4 ( V_3 ) ;
T_2 V_149 ;
V_149 = F_56 ( V_148 + V_59 ) ;
V_149 |= F_56 ( V_148 + V_63 ) ;
return V_149 ;
}
static int
F_73 ( struct V_2 * V_3 , enum V_116 V_117 )
{
unsigned long V_32 ;
int V_34 = 0 ;
T_2 V_150 ;
void T_1 * V_119 ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_119 = V_3 -> V_8 -> V_9 + V_124 ;
else
V_119 = V_3 -> V_8 -> V_9 + V_125 ;
F_14 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
switch ( V_117 ) {
case V_121 :
case V_122 :
V_150 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
if ( V_150 == V_151 )
F_70 ( V_3 , V_138 ) ;
else
F_70 ( V_3 , V_137 ) ;
if ( ! F_72 ( V_3 ) && ( V_117 == V_121 ) )
V_34 = F_55 ( V_3 , V_117 ) ;
break;
case V_151 :
F_70 ( V_3 , V_139 ) ;
V_34 = F_55 ( V_3 , V_117 ) ;
break;
case V_126 :
F_69 () ;
break;
}
F_15 ( & V_3 -> V_11 -> V_38 , V_32 ) ;
return V_34 ;
}
static int F_74 ( struct V_2 * V_3 ,
enum V_116 V_117 )
{
if ( F_3 ( V_3 ) )
return F_73 ( V_3 , V_117 ) ;
else
return F_55 ( V_3 , V_117 ) ;
}
static T_2 F_75 ( struct V_2 * V_3 )
{
static const unsigned int V_152 [] = {
[ V_153 ]
= V_154 ,
[ V_155 ]
= V_156 ,
[ V_157 ]
= V_158 ,
} ;
static const unsigned int V_159 [] = {
[ V_160 ]
= V_161 ,
[ V_162 ]
= V_163 ,
[ V_164 ]
= V_165 ,
} ;
if ( F_2 ( V_3 ) )
return V_152 [ V_3 -> V_142 . V_166 ] ;
else
return V_159 [ V_3 -> V_142 . V_166 ] ;
}
static void F_76 ( struct V_2 * V_3 )
{
T_2 V_167 ;
T_2 V_168 ;
V_167 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_168 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_58 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_168 , V_3 -> V_8 -> V_9 + V_169 + V_167 ) ;
V_168 = F_75 ( V_3 ) << F_58 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_168 , V_3 -> V_8 -> V_9 + V_170 + V_167 ) ;
if ( F_3 ( V_3 ) ) {
int V_171 = ( V_3 -> V_11 -> V_12 << V_172 )
& V_173 ;
void T_1 * V_148 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_174 , V_148 + V_53 ) ;
F_30 ( V_3 -> V_175 , V_148 + V_60 ) ;
F_30 ( V_171 , V_148 + V_55 ) ;
F_30 ( V_171 , V_148 + V_61 ) ;
F_30 ( 0 , V_148 + V_59 ) ;
F_30 ( 0 , V_148 + V_63 ) ;
}
}
static T_2 F_77 ( struct V_2 * V_3 )
{
T_2 V_176 ;
if ( F_3 ( V_3 ) )
V_176 = ( F_56 ( & V_3 -> V_76 -> V_177 ) & V_178 )
>> V_179 ;
else {
T_2 V_149 = F_56 ( F_4 ( V_3 ) + V_61 ) ;
V_176 = ( V_149 & V_180 )
>> V_181 ;
}
return V_176 * ( 1 << V_3 -> V_142 . V_182 . V_183 ) ;
}
static bool F_78 ( struct V_2 * V_3 )
{
bool V_184 ;
if ( F_3 ( V_3 ) )
V_184 = F_56 ( & V_3 -> V_76 -> V_185 ) & V_186 ;
else
V_184 = F_56 ( F_4 ( V_3 ) + V_63 )
& V_187 ;
return V_184 ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_188 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_189 )
return 0 ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_188 = F_74 ( V_3 , V_122 ) ;
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_188 ;
}
static int F_83 ( struct V_2 * V_3 )
{
int V_188 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_189 )
return 0 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
if ( F_77 ( V_3 ) || F_78 ( V_3 ) )
V_188 = F_74 ( V_3 , V_151 ) ;
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_188 ;
}
static T_3 F_84 ( struct V_190 * V_191 )
{
struct V_2 * V_3 = F_85 ( V_191 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_85 ( V_191 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
T_3 V_192 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_192 = F_86 ( V_191 ) ;
F_38 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_192 ;
}
static int F_87 ( struct V_2 * V_3 )
{
return F_74 ( V_3 , V_151 ) ;
}
static struct V_14 * F_88 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_193 ;
V_15 = F_40 ( V_3 ) ;
if ( V_15 != NULL ) {
if ( ! V_3 -> V_189 ) {
V_3 -> V_189 = true ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
V_193 = F_87 ( V_3 ) ;
if ( V_193 )
return NULL ;
}
return V_15 ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_69 ) {
if ( V_15 -> V_68 < V_15 -> V_16
&& ! F_78 ( V_3 )
&& ! F_77 ( V_3 ) ) {
F_16 ( V_3 , V_15 ) ;
F_35 ( V_3 , V_15 ) ;
( void ) F_87 ( V_3 ) ;
if ( V_15 -> V_68 == V_15 -> V_16 )
V_15 -> V_68 = 0 ;
}
} else {
F_16 ( V_3 , V_15 ) ;
if ( V_15 -> V_68 < V_15 -> V_16 ) {
F_35 ( V_3 , V_15 ) ;
( void ) F_87 ( V_3 ) ;
return;
}
if ( F_88 ( V_3 ) == NULL )
V_3 -> V_189 = false ;
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_131 ++ ;
F_90 ( & V_3 -> V_194 ) ;
}
static void F_91 ( unsigned long V_195 )
{
struct V_2 * V_3 = (struct V_2 * ) V_195 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
T_4 V_196 ;
void * V_197 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_15 = F_36 ( V_3 ) ;
if ( V_15 == NULL )
goto V_193;
if ( ! V_15 -> V_69 )
F_92 ( & V_15 -> V_47 ) ;
if ( V_3 -> V_131 == 0 ) {
F_15 ( & V_3 -> V_38 , V_32 ) ;
return;
}
V_196 = V_15 -> V_47 . V_196 ;
V_197 = V_15 -> V_47 . V_197 ;
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
F_90 ( & V_3 -> V_194 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
if ( V_196 && ( V_15 -> V_47 . V_32 & V_198 ) )
V_196 ( V_197 ) ;
return;
V_193:
if ( V_3 -> V_131 > 0 )
V_3 -> V_131 -- ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static T_5 F_93 ( int V_199 , void * V_195 )
{
static const struct V_200 V_201 [] = {
{ V_202 , V_203 , false , 0 } ,
{ V_204 , V_205 , false , 32 } ,
{ V_206 , V_207 , false , 64 } ,
{ V_208 , V_209 , false , 96 } ,
{ V_210 , V_203 , true , 0 } ,
{ V_211 , V_205 , true , 32 } ,
{ V_212 , V_207 , true , 64 } ,
{ V_213 , V_209 , true , 96 } ,
{ V_214 , V_215 , false , V_7 } ,
{ V_216 , V_215 , true , V_7 } ,
} ;
int V_33 ;
T_2 V_217 [ F_54 ( V_201 ) ] ;
T_2 V_106 ;
T_2 V_218 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_104 * V_8 = V_195 ;
F_14 ( & V_8 -> V_219 , V_32 ) ;
for ( V_33 = 0 ; V_33 < F_54 ( V_201 ) ; V_33 ++ )
V_217 [ V_33 ] = F_56 ( V_8 -> V_9 + V_201 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_94 ( ( unsigned long * ) V_217 ,
V_220 * F_54 ( V_201 ) , V_4 + 1 ) ;
if ( V_4 == V_220 * F_54 ( V_201 ) )
break;
V_218 = V_4 / V_220 ;
V_106 = V_4 & ( V_220 - 1 ) ;
F_30 ( 1 << V_106 , V_8 -> V_9 + V_201 [ V_218 ] . V_221 ) ;
if ( V_201 [ V_218 ] . V_222 == V_7 )
V_3 = V_8 -> V_223 [ V_106 ] ;
else
V_3 = V_8 -> V_224 [ V_201 [ V_218 ] . V_222 + V_106 ] ;
F_95 ( & V_3 -> V_38 ) ;
if ( ! V_201 [ V_218 ] . V_225 )
F_89 ( V_3 ) ;
else
F_96 ( V_8 -> V_5 , L_5 ,
V_4 , V_201 [ V_218 ] . V_222 , V_106 ) ;
F_97 ( & V_3 -> V_38 ) ;
}
F_15 ( & V_8 -> V_219 , V_32 ) ;
return V_226 ;
}
static int F_98 ( struct V_2 * V_3 ,
struct V_227 * V_228 )
{
int V_188 = 0 ;
T_2 V_229 = F_99 ( V_228 -> V_147 ) ;
T_2 V_230 = F_99 ( V_228 -> V_146 ) ;
bool V_17 = V_228 -> V_231 == V_232 ;
if ( ! V_228 -> V_143 ) {
F_61 ( V_3 , L_6 ) ;
V_188 = - V_35 ;
}
if ( V_228 -> V_147 != V_233 &&
V_3 -> V_8 -> V_73 -> V_234 [ V_228 -> V_147 ] == 0 &&
V_3 -> V_235 == 0 ) {
F_61 ( V_3 , L_7 ,
V_228 -> V_147 ) ;
V_188 = - V_35 ;
}
if ( V_228 -> V_146 != V_236 &&
V_3 -> V_8 -> V_73 -> V_237 [ V_228 -> V_146 ] == 0 &&
V_3 -> V_235 == 0 ) {
F_61 ( V_3 , L_8 ,
V_228 -> V_146 ) ;
V_188 = - V_35 ;
}
if ( V_228 -> V_143 == V_238 &&
V_229 == V_233 ) {
F_61 ( V_3 , L_9 ) ;
V_188 = - V_35 ;
}
if ( V_228 -> V_143 == V_144 &&
V_230 == V_236 ) {
F_61 ( V_3 , L_10 ) ;
V_188 = - V_35 ;
}
if ( V_230 == V_236 &&
V_229 == V_233 && V_17 ) {
F_61 ( V_3 , L_11 ) ;
V_188 = - V_35 ;
}
if ( V_228 -> V_143 == V_145 &&
( V_230 != V_229 ) ) {
F_61 ( V_3 , L_12 ) ;
V_188 = - V_35 ;
}
if ( V_228 -> V_143 == V_145 ) {
F_61 ( V_3 , L_13 ) ;
V_188 = - V_35 ;
}
if ( F_41 ( V_17 , V_228 -> V_239 . V_84 ) *
( 1 << V_228 -> V_239 . V_183 ) !=
F_41 ( V_17 , V_228 -> V_182 . V_84 ) *
( 1 << V_228 -> V_182 . V_183 ) ) {
F_61 ( V_3 , L_14 ) ;
V_188 = - V_35 ;
}
return V_188 ;
}
static bool F_100 ( struct V_240 * V_241 ,
bool V_242 , int V_243 , bool V_17 ,
bool * V_244 )
{
unsigned long V_32 ;
F_14 ( & V_241 -> V_38 , V_32 ) ;
* V_244 = ( ( V_241 -> V_245 | V_241 -> V_246 )
== V_247 ) ;
if ( ! V_17 ) {
if ( V_241 -> V_245 == V_247 &&
V_241 -> V_246 == V_247 ) {
V_241 -> V_246 = V_248 ;
V_241 -> V_245 = V_248 ;
goto V_249;
} else
goto V_250;
}
if ( V_242 ) {
if ( V_241 -> V_245 == V_248 )
goto V_250;
if ( V_241 -> V_245 == V_247 )
V_241 -> V_245 = V_251 ;
if ( ! ( V_241 -> V_245 & ( 1 << V_243 ) ) ) {
V_241 -> V_245 |= 1 << V_243 ;
goto V_249;
} else
goto V_250;
} else {
if ( V_241 -> V_246 == V_248 )
goto V_250;
if ( V_241 -> V_246 == V_247 )
V_241 -> V_246 = V_251 ;
if ( ! ( V_241 -> V_246 & ( 1 << V_243 ) ) ) {
V_241 -> V_246 |= 1 << V_243 ;
goto V_249;
} else
goto V_250;
}
V_250:
F_15 ( & V_241 -> V_38 , V_32 ) ;
return false ;
V_249:
F_15 ( & V_241 -> V_38 , V_32 ) ;
return true ;
}
static bool F_101 ( struct V_240 * V_241 , bool V_242 ,
int V_243 )
{
unsigned long V_32 ;
bool V_252 = false ;
F_14 ( & V_241 -> V_38 , V_32 ) ;
if ( ! V_243 ) {
V_241 -> V_246 = V_247 ;
V_241 -> V_245 = V_247 ;
V_252 = true ;
goto V_77;
}
if ( V_242 ) {
V_241 -> V_245 &= ~ ( 1 << V_243 ) ;
if ( V_241 -> V_245 == V_251 )
V_241 -> V_245 = V_247 ;
} else {
V_241 -> V_246 &= ~ ( 1 << V_243 ) ;
if ( V_241 -> V_246 == V_251 )
V_241 -> V_246 = V_247 ;
}
V_252 = ( ( V_241 -> V_245 | V_241 -> V_246 ) ==
V_247 ) ;
V_77:
F_15 ( & V_241 -> V_38 , V_32 ) ;
return V_252 ;
}
static int F_102 ( struct V_2 * V_3 , bool * V_253 )
{
int V_254 ;
int V_255 ;
int V_256 ;
struct V_240 * V_257 ;
int V_33 ;
int V_258 ;
int V_6 ;
bool V_242 ;
bool V_17 = V_3 -> V_142 . V_231 == V_232 ;
V_257 = V_3 -> V_8 -> V_107 ;
if ( V_3 -> V_142 . V_143 == V_144 ) {
V_254 = V_3 -> V_142 . V_146 ;
V_6 = 2 * V_254 ;
V_242 = true ;
} else if ( V_3 -> V_142 . V_143 == V_238 ||
V_3 -> V_142 . V_143 == V_259 ) {
V_254 = V_3 -> V_142 . V_147 ;
V_6 = 2 * V_254 + 1 ;
V_242 = false ;
} else
return - V_35 ;
V_255 = F_99 ( V_254 ) ;
V_256 = F_71 ( V_254 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_142 . V_143 == V_259 ) {
for ( V_33 = 0 ; V_33 < V_3 -> V_8 -> V_105 ; V_33 ++ ) {
if ( F_100 ( & V_257 [ V_33 ] , V_242 ,
0 , V_17 ,
V_253 ) )
goto V_260;
}
} else
for ( V_258 = 0 ; V_258 < V_3 -> V_8 -> V_105 ; V_258 += 8 ) {
int V_261 = V_258 + V_255 * 2 ;
for ( V_33 = V_261 ; V_33 < V_261 + 2 ; V_33 ++ ) {
if ( F_100 ( & V_257 [ V_33 ] ,
V_242 ,
0 ,
V_17 ,
V_253 ) )
goto V_260;
}
}
return - V_35 ;
V_260:
V_3 -> V_11 = & V_257 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_77;
}
if ( V_254 == - 1 )
return - V_35 ;
for ( V_258 = 0 ; V_258 < V_3 -> V_8 -> V_105 ; V_258 += 8 ) {
int V_261 = V_258 + V_255 * 2 ;
if ( V_3 -> V_142 . V_262 ) {
V_33 = V_3 -> V_142 . V_263 ;
if ( ( V_33 != V_261 ) && ( V_33 != V_261 + 1 ) ) {
F_103 ( F_1 ( V_3 ) ,
L_15 , V_33 ) ;
return - V_35 ;
}
if ( F_100 ( & V_257 [ V_33 ] , V_242 , V_256 ,
V_17 , V_253 ) )
goto V_264;
F_103 ( F_1 ( V_3 ) ,
L_16 , V_33 ) ;
return - V_35 ;
}
if ( V_242 ) {
for ( V_33 = V_261 ; V_33 < V_261 + 2 ; V_33 ++ ) {
if ( F_100 ( & V_257 [ V_33 ] , V_242 ,
V_256 , V_17 ,
V_253 ) )
goto V_264;
}
} else {
for ( V_33 = V_261 + 1 ; V_33 >= V_261 ; V_33 -- ) {
if ( F_100 ( & V_257 [ V_33 ] , V_242 ,
V_256 , V_17 ,
V_253 ) )
goto V_264;
}
}
}
return - V_35 ;
V_264:
V_3 -> V_11 = & V_257 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_77:
if ( V_17 )
V_3 -> V_8 -> V_224 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_223 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 )
{
T_6 V_265 = V_3 -> V_4 . V_1 -> V_266 ;
if ( F_105 ( V_267 , V_265 ) && ! F_105 ( V_268 , V_265 ) ) {
V_3 -> V_142 = * V_3 -> V_8 -> V_73 -> V_269 ;
V_3 -> V_142 . V_146 = V_236 ;
V_3 -> V_142 . V_147 = V_3 -> V_8 -> V_73 ->
memcpy [ V_3 -> V_4 . V_270 ] ;
} else if ( F_105 ( V_267 , V_265 ) &&
F_105 ( V_268 , V_265 ) ) {
V_3 -> V_142 = * V_3 -> V_8 -> V_73 -> V_271 ;
} else {
F_61 ( V_3 , L_17 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_106 ( struct V_2 * V_3 )
{
int V_188 = 0 ;
T_2 V_134 ;
struct V_240 * V_241 = V_3 -> V_11 ;
bool V_242 ;
F_63 ( V_3 ) ;
if ( V_241 == NULL ) {
F_61 ( V_3 , L_18 ) ;
return - V_35 ;
}
if ( V_241 -> V_245 == V_247 &&
V_241 -> V_246 == V_247 ) {
F_61 ( V_3 , L_19 ) ;
return - V_35 ;
}
if ( V_3 -> V_142 . V_143 == V_238 ||
V_3 -> V_142 . V_143 == V_259 ) {
V_134 = F_71 ( V_3 -> V_142 . V_147 ) ;
V_242 = false ;
} else if ( V_3 -> V_142 . V_143 == V_144 ) {
V_134 = F_71 ( V_3 -> V_142 . V_146 ) ;
V_242 = true ;
} else {
F_61 ( V_3 , L_20 ) ;
return - V_35 ;
}
F_80 ( V_3 -> V_8 -> V_5 ) ;
V_188 = F_74 ( V_3 , V_121 ) ;
if ( V_188 ) {
F_61 ( V_3 , L_21 ) ;
goto V_77;
}
F_101 ( V_241 , V_242 , F_3 ( V_3 ) ? V_134 : 0 ) ;
if ( F_3 ( V_3 ) )
V_3 -> V_8 -> V_224 [ V_3 -> V_6 ] = NULL ;
else
V_3 -> V_8 -> V_223 [ V_241 -> V_12 ] = NULL ;
if ( V_3 -> V_189 ) {
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_189 = false ;
V_3 -> V_11 = NULL ;
V_3 -> V_272 = false ;
V_77:
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
return V_188 ;
}
static bool F_107 ( struct V_2 * V_3 )
{
void T_1 * V_148 = F_4 ( V_3 ) ;
bool V_273 = false ;
unsigned long V_32 ;
void T_1 * V_119 ;
T_2 V_118 ;
T_2 V_134 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
if ( F_2 ( V_3 ) ) {
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_119 = V_3 -> V_8 -> V_9 + V_124 ;
else
V_119 = V_3 -> V_8 -> V_9 + V_125 ;
V_118 = ( F_56 ( V_119 ) &
F_57 ( V_3 -> V_11 -> V_12 ) ) >>
F_58 ( V_3 -> V_11 -> V_12 ) ;
if ( V_118 == V_126 || V_118 == V_121 )
V_273 = true ;
goto V_274;
}
if ( V_3 -> V_142 . V_143 == V_238 ||
V_3 -> V_142 . V_143 == V_259 ) {
V_134 = F_71 ( V_3 -> V_142 . V_147 ) ;
V_118 = F_56 ( V_148 + V_63 ) ;
} else if ( V_3 -> V_142 . V_143 == V_144 ) {
V_134 = F_71 ( V_3 -> V_142 . V_146 ) ;
V_118 = F_56 ( V_148 + V_59 ) ;
} else {
F_61 ( V_3 , L_20 ) ;
goto V_274;
}
V_118 = ( V_118 & F_66 ( V_134 ) ) >>
F_65 ( V_134 ) ;
if ( V_118 != V_151 )
V_273 = true ;
V_274:
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_273 ;
}
static T_2 F_108 ( struct V_275 * V_4 )
{
struct V_2 * V_3 =
F_85 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_276 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_276 = F_77 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_276 ;
}
static int
F_109 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_94 * V_277 , struct V_94 * V_278 ,
unsigned int V_96 , T_7 V_279 ,
T_7 V_280 )
{
struct V_227 * V_281 = & V_4 -> V_142 ;
struct V_282 * V_239 = & V_281 -> V_239 ;
struct V_282 * V_182 = & V_281 -> V_182 ;
int V_34 ;
V_34 = F_110 ( V_277 , V_96 ,
V_279 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_283 . V_284 ,
V_239 -> V_183 ,
V_182 -> V_183 ) ;
V_34 = F_110 ( V_278 , V_96 ,
V_280 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_283 . V_185 ,
V_182 -> V_183 ,
V_239 -> V_183 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_111 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_94 * V_277 , struct V_94 * V_278 ,
unsigned int V_96 , T_7 V_279 ,
T_7 V_280 )
{
struct V_227 * V_281 = & V_4 -> V_142 ;
struct V_282 * V_239 = & V_281 -> V_239 ;
struct V_282 * V_182 = & V_281 -> V_182 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_69 )
V_32 |= V_285 | V_75 ;
V_34 = F_112 ( V_277 , V_96 , V_279 ,
V_43 -> V_30 . V_27 ,
F_113 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_174 ,
V_239 , V_182 , V_32 ) ;
V_34 = F_112 ( V_278 , V_96 , V_280 ,
V_43 -> V_30 . V_28 ,
F_113 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_175 ,
V_182 , V_239 , V_32 ) ;
F_114 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_115 ( struct V_2 * V_4 , struct V_94 * V_97 ,
unsigned int V_96 , unsigned long V_286 )
{
struct V_227 * V_281 = & V_4 -> V_142 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_47 ( V_97 , V_96 , V_281 -> V_239 . V_183 ,
V_281 -> V_182 . V_183 ) ;
if ( V_43 -> V_16 < 0 ) {
F_61 ( V_4 , L_22 ) ;
goto V_193;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_61 ( V_4 , L_23 ) ;
goto V_193;
}
V_43 -> V_68 = 0 ;
V_43 -> V_47 . V_32 = V_286 ;
V_43 -> V_47 . V_287 = F_84 ;
F_116 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_193:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static T_7
F_117 ( struct V_2 * V_4 , enum V_288 V_289 )
{
struct V_290 * V_291 = V_4 -> V_8 -> V_73 ;
struct V_227 * V_281 = & V_4 -> V_142 ;
T_7 V_103 = 0 ;
if ( V_4 -> V_235 )
return V_4 -> V_235 ;
if ( V_289 == V_292 )
V_103 = V_291 -> V_237 [ V_281 -> V_146 ] ;
else if ( V_289 == V_293 )
V_103 = V_291 -> V_234 [ V_281 -> V_147 ] ;
return V_103 ;
}
static struct V_190 *
F_118 ( struct V_275 * V_294 , struct V_94 * V_277 ,
struct V_94 * V_278 , unsigned int V_96 ,
enum V_288 V_289 , unsigned long V_286 )
{
struct V_2 * V_4 = F_85 ( V_294 , struct V_2 , V_4 ) ;
T_7 V_279 = 0 ;
T_7 V_280 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_61 ( V_4 , L_24 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_38 , V_32 ) ;
V_43 = F_115 ( V_4 , V_277 , V_96 , V_286 ) ;
if ( V_43 == NULL )
goto V_193;
if ( F_119 ( & V_277 [ V_96 - 1 ] ) == V_277 )
V_43 -> V_69 = true ;
if ( V_289 != V_295 ) {
T_7 V_296 = F_117 ( V_4 , V_289 ) ;
if ( V_289 == V_292 )
V_279 = V_296 ;
else if ( V_289 == V_293 )
V_280 = V_296 ;
}
if ( F_3 ( V_4 ) )
V_34 = F_109 ( V_4 , V_43 , V_277 , V_278 ,
V_96 , V_279 , V_280 ) ;
else
V_34 = F_111 ( V_4 , V_43 , V_277 , V_278 ,
V_96 , V_279 , V_280 ) ;
if ( V_34 ) {
F_61 ( V_4 , L_25 ,
F_3 ( V_4 ) ? L_26 : L_27 , V_34 ) ;
goto V_193;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_130 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return & V_43 -> V_47 ;
V_193:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_38 , V_32 ) ;
return NULL ;
}
bool F_120 ( struct V_275 * V_4 , void * V_195 )
{
struct V_227 * V_297 = V_195 ;
struct V_2 * V_3 =
F_85 ( V_4 , struct V_2 , V_4 ) ;
int V_193 ;
if ( V_195 ) {
V_193 = F_98 ( V_3 , V_297 ) ;
if ( ! V_193 )
V_3 -> V_142 = * V_297 ;
} else
V_193 = F_104 ( V_3 ) ;
if ( ! V_193 )
V_3 -> V_272 = true ;
return V_193 == 0 ;
}
static void F_121 ( struct V_2 * V_3 , int V_254 , bool V_27 )
{
bool V_298 = V_3 -> V_142 . V_298 ;
bool V_299 = V_3 -> V_142 . V_300 ;
T_2 V_301 = V_299 ? V_302 : V_303 ;
T_2 V_304 = V_298 ? V_305 : V_306 ;
T_2 V_134 = F_71 ( V_254 ) ;
T_2 V_307 = F_99 ( V_254 ) ;
T_2 V_308 = 1 << V_134 ;
if ( ! V_27 )
V_308 <<= 16 ;
F_30 ( V_308 , V_3 -> V_8 -> V_9 + V_301 + V_307 * 4 ) ;
F_30 ( V_308 , V_3 -> V_8 -> V_9 + V_304 + V_307 * 4 ) ;
}
static void F_122 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_113 < 3 )
return;
if ( ( V_3 -> V_142 . V_143 == V_144 ) ||
( V_3 -> V_142 . V_143 == V_145 ) )
F_121 ( V_3 , V_3 -> V_142 . V_146 , true ) ;
if ( ( V_3 -> V_142 . V_143 == V_238 ) ||
( V_3 -> V_142 . V_143 == V_145 ) )
F_121 ( V_3 , V_3 -> V_142 . V_147 , false ) ;
}
static int F_123 ( struct V_275 * V_4 )
{
int V_193 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_85 ( V_4 , struct V_2 , V_4 ) ;
bool V_309 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_124 ( V_4 ) ;
if ( ! V_3 -> V_272 ) {
V_193 = F_104 ( V_3 ) ;
if ( V_193 ) {
F_61 ( V_3 , L_28 ) ;
goto V_310;
}
}
V_193 = F_102 ( V_3 , & V_309 ) ;
if ( V_193 ) {
F_61 ( V_3 , L_29 ) ;
V_3 -> V_272 = false ;
goto V_310;
}
F_80 ( V_3 -> V_8 -> V_5 ) ;
F_125 ( & V_3 -> V_142 , & V_3 -> V_174 ,
& V_3 -> V_175 , F_3 ( V_3 ) ) ;
F_122 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
F_126 ( & V_3 -> V_142 ,
& V_3 -> V_283 . V_284 , & V_3 -> V_283 . V_185 ) ;
if ( V_3 -> V_142 . V_143 == V_144 )
V_3 -> V_76 = V_3 -> V_8 -> V_311 +
V_3 -> V_142 . V_146 * V_312 ;
else
V_3 -> V_76 = V_3 -> V_8 -> V_311 +
V_3 -> V_142 . V_147 *
V_312 + V_313 ;
}
F_67 ( F_1 ( V_3 ) , L_30 ,
F_3 ( V_3 ) ? L_31 : L_32 ,
V_3 -> V_11 -> V_12 ,
V_3 -> V_142 . V_262 ? L_33 : L_34 ) ;
if ( V_309 )
F_76 ( V_3 ) ;
V_310:
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
return V_193 ;
}
static void F_127 ( struct V_275 * V_4 )
{
struct V_2 * V_3 =
F_85 ( V_4 , struct V_2 , V_4 ) ;
int V_193 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_35 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
V_193 = F_106 ( V_3 ) ;
if ( V_193 )
F_61 ( V_3 , L_36 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static struct V_190 * F_128 ( struct V_275 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_286 )
{
struct V_94 V_314 ;
struct V_94 V_315 ;
F_129 ( & V_314 , 1 ) ;
F_129 ( & V_315 , 1 ) ;
F_130 ( & V_314 ) = V_28 ;
F_130 ( & V_315 ) = V_27 ;
F_49 ( & V_314 ) = V_23 ;
F_49 ( & V_315 ) = V_23 ;
return F_118 ( V_4 , & V_315 , & V_314 , 1 , V_316 , V_286 ) ;
}
static struct V_190 *
F_131 ( struct V_275 * V_4 ,
struct V_94 * V_314 , unsigned int V_317 ,
struct V_94 * V_315 , unsigned int V_318 ,
unsigned long V_286 )
{
if ( V_317 != V_318 )
return NULL ;
return F_118 ( V_4 , V_315 , V_314 , V_318 , V_316 , V_286 ) ;
}
static struct V_190 * F_132 ( struct V_275 * V_4 ,
struct V_94 * V_95 ,
unsigned int V_96 ,
enum V_288 V_289 ,
unsigned long V_286 ,
void * V_319 )
{
if ( V_289 != V_292 && V_289 != V_293 )
return NULL ;
return F_118 ( V_4 , V_95 , V_95 , V_96 , V_289 , V_286 ) ;
}
static struct V_190 *
F_133 ( struct V_275 * V_4 , T_7 V_29 ,
T_8 V_320 , T_8 V_321 ,
enum V_288 V_289 , unsigned long V_32 ,
void * V_319 )
{
unsigned int V_322 = V_320 / V_321 ;
struct V_190 * V_47 ;
struct V_94 * V_97 ;
int V_33 ;
V_97 = F_134 ( V_322 + 1 , sizeof( struct V_94 ) , V_24 ) ;
for ( V_33 = 0 ; V_33 < V_322 ; V_33 ++ ) {
F_130 ( & V_97 [ V_33 ] ) = V_29 ;
F_49 ( & V_97 [ V_33 ] ) = V_321 ;
V_29 += V_321 ;
}
V_97 [ V_322 ] . V_222 = 0 ;
F_49 ( & V_97 [ V_322 ] ) = 0 ;
V_97 [ V_322 ] . V_323 =
( ( unsigned long ) V_97 | 0x01 ) & ~ 0x02 ;
V_47 = F_118 ( V_4 , V_97 , V_97 , V_322 , V_289 ,
V_198 ) ;
F_10 ( V_97 ) ;
return V_47 ;
}
static enum V_324 F_135 ( struct V_275 * V_4 ,
T_3 V_192 ,
struct V_325 * V_326 )
{
struct V_2 * V_3 = F_85 ( V_4 , struct V_2 , V_4 ) ;
enum V_324 V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_37 ) ;
return - V_35 ;
}
V_34 = F_136 ( V_4 , V_192 , V_326 ) ;
if ( V_34 != V_327 )
F_137 ( V_326 , F_108 ( V_4 ) ) ;
if ( F_107 ( V_3 ) )
V_34 = V_328 ;
return V_34 ;
}
static void F_138 ( struct V_275 * V_4 )
{
struct V_2 * V_3 = F_85 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_38 ) ;
return;
}
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_139 ( & V_3 -> V_82 , & V_3 -> V_83 ) ;
if ( ! V_3 -> V_189 )
( void ) F_88 ( V_3 ) ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static void F_140 ( struct V_275 * V_4 )
{
unsigned long V_32 ;
struct V_2 * V_3 = F_85 ( V_4 , struct V_2 , V_4 ) ;
int V_34 ;
F_14 ( & V_3 -> V_38 , V_32 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
V_34 = F_74 ( V_3 , V_121 ) ;
if ( V_34 )
F_61 ( V_3 , L_39 ) ;
F_63 ( V_3 ) ;
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
if ( V_3 -> V_189 ) {
F_81 ( V_3 -> V_8 -> V_5 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_189 = false ;
F_15 ( & V_3 -> V_38 , V_32 ) ;
}
static int
F_141 ( struct V_2 * V_3 ,
struct V_282 * V_297 ,
enum V_329 V_330 ,
T_2 V_331 )
{
enum V_332 V_333 ;
int V_84 ;
switch ( V_330 ) {
case V_334 :
V_333 = V_335 ;
break;
case V_336 :
V_333 = V_337 ;
break;
case V_338 :
V_333 = V_339 ;
break;
case V_340 :
V_333 = V_341 ;
break;
default:
F_103 ( V_3 -> V_8 -> V_5 ,
L_40
L_41 ,
V_330 ) ;
return - V_35 ;
}
if ( F_3 ( V_3 ) ) {
if ( V_331 >= 16 )
V_84 = V_342 ;
else if ( V_331 >= 8 )
V_84 = V_343 ;
else if ( V_331 >= 4 )
V_84 = V_344 ;
else
V_84 = V_85 ;
} else {
if ( V_331 >= 16 )
V_84 = V_345 ;
else if ( V_331 >= 8 )
V_84 = V_346 ;
else if ( V_331 >= 4 )
V_84 = V_347 ;
else
V_84 = V_86 ;
}
V_297 -> V_183 = V_333 ;
V_297 -> V_84 = V_84 ;
V_297 -> V_348 = V_349 ;
return 0 ;
}
static int F_142 ( struct V_275 * V_4 ,
struct V_350 * V_351 )
{
struct V_2 * V_3 = F_85 ( V_4 , struct V_2 , V_4 ) ;
struct V_227 * V_281 = & V_3 -> V_142 ;
enum V_329 V_352 , V_353 ;
T_7 V_354 ;
T_2 V_355 , V_356 ;
int V_34 ;
V_352 = V_351 -> V_352 ;
V_355 = V_351 -> V_355 ;
V_353 = V_351 -> V_353 ;
V_356 = V_351 -> V_356 ;
if ( V_351 -> V_289 == V_292 ) {
T_7 V_357 =
V_3 -> V_8 -> V_73 -> V_237 [ V_281 -> V_146 ] ;
V_354 = V_351 -> V_358 ;
if ( V_357 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_42
L_43 ,
V_357 , V_354 ) ;
if ( V_281 -> V_143 != V_144 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_44
L_45 ,
V_281 -> V_143 ) ;
V_281 -> V_143 = V_144 ;
if ( V_353 == V_359 )
V_353 = V_352 ;
if ( V_356 == 0 )
V_356 = V_355 ;
} else if ( V_351 -> V_289 == V_293 ) {
T_7 V_360 =
V_3 -> V_8 -> V_73 -> V_234 [ V_281 -> V_147 ] ;
V_354 = V_351 -> V_361 ;
if ( V_360 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_46
L_43 ,
V_360 , V_354 ) ;
if ( V_281 -> V_143 != V_238 )
F_67 ( V_3 -> V_8 -> V_5 ,
L_47
L_48 ,
V_281 -> V_143 ) ;
V_281 -> V_143 = V_238 ;
if ( V_352 == V_359 )
V_352 = V_353 ;
if ( V_355 == 0 )
V_355 = V_356 ;
} else {
F_103 ( V_3 -> V_8 -> V_5 ,
L_49 ,
V_351 -> V_289 ) ;
return - V_35 ;
}
if ( V_355 * V_352 != V_356 * V_353 ) {
F_103 ( V_3 -> V_8 -> V_5 ,
L_50 ,
V_355 ,
V_352 ,
V_356 ,
V_353 ) ;
return - V_35 ;
}
V_34 = F_141 ( V_3 , & V_281 -> V_239 ,
V_352 ,
V_355 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_141 ( V_3 , & V_281 -> V_182 ,
V_353 ,
V_356 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_126 ( V_281 , & V_3 -> V_283 . V_284 , & V_3 -> V_283 . V_185 ) ;
else
F_125 ( V_281 , & V_3 -> V_174 ,
& V_3 -> V_175 , false ) ;
V_3 -> V_235 = V_354 ;
V_3 -> V_362 = V_351 -> V_289 ;
F_67 ( V_3 -> V_8 -> V_5 ,
L_51
L_52 ,
F_143 ( V_4 ) ,
( V_351 -> V_289 == V_292 ) ? L_53 : L_54 ,
V_352 , V_353 ,
V_355 , V_356 ) ;
return 0 ;
}
static int F_144 ( struct V_275 * V_4 , enum V_363 V_364 ,
unsigned long V_365 )
{
struct V_2 * V_3 = F_85 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_61 ( V_3 , L_38 ) ;
return - V_35 ;
}
switch ( V_364 ) {
case V_366 :
F_140 ( V_4 ) ;
return 0 ;
case V_367 :
return F_79 ( V_3 ) ;
case V_368 :
return F_83 ( V_3 ) ;
case V_369 :
return F_142 ( V_4 ,
(struct V_350 * ) V_365 ) ;
default:
break;
}
return - V_370 ;
}
static void T_9 F_145 ( struct V_104 * V_8 , struct V_371 * V_372 ,
struct V_2 * V_373 , int V_222 ,
int V_374 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_372 -> V_375 ) ;
for ( V_33 = V_222 ; V_33 < V_222 + V_374 ; V_33 ++ ) {
V_3 = & V_373 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_372 ;
F_146 ( & V_3 -> V_38 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_83 ) ;
F_24 ( & V_3 -> V_82 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_130 ) ;
F_147 ( & V_3 -> V_194 , F_91 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_376 ,
& V_372 -> V_375 ) ;
}
}
static void F_148 ( struct V_104 * V_8 , struct V_371 * V_5 )
{
if ( F_105 ( V_268 , V_5 -> V_266 ) )
V_5 -> V_377 = F_132 ;
if ( F_105 ( V_267 , V_5 -> V_266 ) ) {
V_5 -> V_378 = F_128 ;
V_5 -> V_379 = 2 ;
}
if ( F_105 ( V_380 , V_5 -> V_266 ) )
V_5 -> V_381 = F_131 ;
if ( F_105 ( V_382 , V_5 -> V_266 ) )
V_5 -> V_383 = F_133 ;
V_5 -> V_384 = F_123 ;
V_5 -> V_385 = F_127 ;
V_5 -> V_386 = F_138 ;
V_5 -> V_387 = F_135 ;
V_5 -> V_388 = F_144 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_149 ( struct V_104 * V_8 ,
int V_389 )
{
int V_193 ;
F_145 ( V_8 , & V_8 -> V_390 , V_8 -> V_391 ,
0 , V_8 -> V_392 ) ;
F_150 ( V_8 -> V_390 . V_266 ) ;
F_151 ( V_268 , V_8 -> V_390 . V_266 ) ;
F_151 ( V_382 , V_8 -> V_390 . V_266 ) ;
F_148 ( V_8 , & V_8 -> V_390 ) ;
V_193 = F_152 ( & V_8 -> V_390 ) ;
if ( V_193 ) {
F_96 ( V_8 -> V_5 , L_55 ) ;
goto V_393;
}
F_145 ( V_8 , & V_8 -> V_394 , V_8 -> V_391 ,
V_8 -> V_392 , V_8 -> V_73 -> V_395 ) ;
F_150 ( V_8 -> V_394 . V_266 ) ;
F_151 ( V_267 , V_8 -> V_394 . V_266 ) ;
F_151 ( V_380 , V_8 -> V_394 . V_266 ) ;
F_148 ( V_8 , & V_8 -> V_394 ) ;
V_193 = F_152 ( & V_8 -> V_394 ) ;
if ( V_193 ) {
F_96 ( V_8 -> V_5 ,
L_56 ) ;
goto V_396;
}
F_145 ( V_8 , & V_8 -> V_397 , V_8 -> V_398 ,
0 , V_389 ) ;
F_150 ( V_8 -> V_397 . V_266 ) ;
F_151 ( V_268 , V_8 -> V_397 . V_266 ) ;
F_151 ( V_267 , V_8 -> V_397 . V_266 ) ;
F_151 ( V_380 , V_8 -> V_397 . V_266 ) ;
F_151 ( V_382 , V_8 -> V_390 . V_266 ) ;
F_148 ( V_8 , & V_8 -> V_397 ) ;
V_193 = F_152 ( & V_8 -> V_397 ) ;
if ( V_193 ) {
F_96 ( V_8 -> V_5 ,
L_57 ) ;
goto V_399;
}
return 0 ;
V_399:
F_153 ( & V_8 -> V_394 ) ;
V_396:
F_153 ( & V_8 -> V_390 ) ;
V_393:
return V_193 ;
}
static int F_154 ( struct V_1 * V_5 )
{
struct V_400 * V_401 = F_155 ( V_5 ) ;
struct V_104 * V_8 = F_156 ( V_401 ) ;
int V_34 = 0 ;
if ( ! F_157 ( V_5 ) )
return - V_129 ;
if ( V_8 -> V_402 )
V_34 = F_158 ( V_8 -> V_402 ) ;
return V_34 ;
}
static int F_159 ( struct V_1 * V_5 )
{
struct V_400 * V_401 = F_155 ( V_5 ) ;
struct V_104 * V_8 = F_156 ( V_401 ) ;
F_53 ( V_8 , true ) ;
if ( V_8 -> V_113 != 1 )
F_52 ( V_8 -> V_403 ,
V_8 -> V_9 + V_404 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_5 )
{
struct V_400 * V_401 = F_155 ( V_5 ) ;
struct V_104 * V_8 = F_156 ( V_401 ) ;
if ( V_8 -> V_405 )
F_53 ( V_8 , false ) ;
F_52 ( V_406 ,
V_8 -> V_9 + V_404 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_5 )
{
struct V_400 * V_401 = F_155 ( V_5 ) ;
struct V_104 * V_8 = F_156 ( V_401 ) ;
int V_34 = 0 ;
if ( V_8 -> V_402 )
V_34 = F_162 ( V_8 -> V_402 ) ;
return V_34 ;
}
static int T_9 F_163 ( struct V_104 * V_8 )
{
int V_33 ;
int V_407 = 0 ;
T_2 V_149 [ 2 ] ;
int V_408 = - 2 ;
int V_409 = V_410 ;
V_149 [ 0 ] = F_56 ( V_8 -> V_9 + V_411 ) ;
V_149 [ 1 ] = F_56 ( V_8 -> V_9 + V_412 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
V_8 -> V_107 [ V_33 ] . V_12 = V_33 ;
V_408 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_149 [ V_33 % 2 ] >> V_408 ) & 3 ) == 1 ) {
V_8 -> V_107 [ V_33 ] . V_245 = V_248 ;
V_8 -> V_107 [ V_33 ] . V_246 = V_248 ;
V_8 -> V_107 [ V_33 ] . V_108 = true ;
V_409 |= F_164 ( F_165 ( V_33 ) ,
V_413 ) ;
V_409 |= F_164 ( F_165 ( V_33 ) ,
V_414 ) ;
} else {
V_8 -> V_107 [ V_33 ] . V_245 = V_247 ;
V_8 -> V_107 [ V_33 ] . V_246 = V_247 ;
V_8 -> V_107 [ V_33 ] . V_108 = false ;
V_407 ++ ;
}
F_146 ( & V_8 -> V_107 [ V_33 ] . V_38 ) ;
}
for ( V_33 = 0 ; V_8 -> V_73 -> V_415 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_73 -> V_415 [ V_33 ] ;
V_8 -> V_107 [ V_4 ] . V_245 = V_248 ;
V_8 -> V_107 [ V_4 ] . V_246 = V_248 ;
V_8 -> V_107 [ V_4 ] . V_108 = true ;
V_409 |= F_164 ( F_165 ( V_4 ) ,
V_413 ) ;
V_409 |= F_164 ( F_165 ( V_4 ) ,
V_414 ) ;
V_407 -- ;
}
F_166 ( V_8 -> V_5 , L_58 ,
V_407 , V_8 -> V_105 ) ;
V_149 [ 0 ] = F_56 ( V_8 -> V_9 + V_416 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
if ( V_8 -> V_107 [ V_33 ] . V_245 == V_247 &&
( V_149 [ 0 ] & 0x3 ) != 1 )
F_166 ( V_8 -> V_5 ,
L_59 ,
V_140 , V_33 , V_149 [ 0 ] & 0x3 ) ;
V_149 [ 0 ] = V_149 [ 0 ] >> 2 ;
}
F_30 ( V_406 , V_8 -> V_9 + V_404 ) ;
V_8 -> V_403 = V_409 ;
return V_407 ;
}
static struct V_104 * T_9 F_167 ( struct V_400 * V_401 )
{
struct V_290 * V_73 ;
struct V_417 * V_417 = NULL ;
void T_1 * V_9 = NULL ;
struct V_418 * V_188 = NULL ;
struct V_104 * V_8 = NULL ;
int V_392 = 0 ;
int V_105 ;
int V_419 = - V_35 ;
int V_33 ;
T_2 V_420 ;
T_2 V_421 ;
T_10 V_113 ;
V_417 = F_168 ( & V_401 -> V_5 , NULL ) ;
if ( F_169 ( V_417 ) ) {
F_96 ( & V_401 -> V_5 , L_60 ) ;
goto V_422;
}
V_419 = F_170 ( V_417 ) ;
if ( V_419 ) {
F_96 ( & V_401 -> V_5 , L_61 ) ;
goto V_422;
}
V_188 = F_171 ( V_401 , V_423 , L_62 ) ;
if ( ! V_188 )
goto V_422;
if ( F_172 ( V_188 -> V_424 , F_173 ( V_188 ) ,
V_425 L_63 ) == NULL )
goto V_422;
V_9 = F_174 ( V_188 -> V_424 , F_173 ( V_188 ) ) ;
if ( ! V_9 )
goto V_422;
for ( V_420 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_420 |= ( F_56 ( V_9 + F_173 ( V_188 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_421 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_421 |= ( F_56 ( V_9 + F_173 ( V_188 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_421 != V_426 ) {
F_96 ( & V_401 -> V_5 , L_64 ) ;
goto V_422;
}
if ( F_175 ( V_420 ) != V_427 ) {
F_96 ( & V_401 -> V_5 , L_65 ,
F_175 ( V_420 ) ,
V_427 ) ;
goto V_422;
}
V_113 = F_176 ( V_420 ) ;
V_105 = 4 * ( F_56 ( V_9 + V_428 ) & 0x7 ) + 4 ;
F_166 ( & V_401 -> V_5 , L_66 ,
V_113 , V_188 -> V_424 ) ;
if ( V_113 < 2 ) {
F_96 ( & V_401 -> V_5 , L_67 ,
V_113 ) ;
goto V_422;
}
V_73 = V_401 -> V_5 . V_429 ;
for ( V_33 = 0 ; V_33 < V_73 -> V_430 ; V_33 ++ )
if ( V_73 -> V_237 [ V_33 ] != 0 )
V_392 ++ ;
for ( V_33 = 0 ; V_33 < V_73 -> V_430 ; V_33 ++ )
if ( V_73 -> V_234 [ V_33 ] != 0 )
V_392 ++ ;
V_8 = F_177 ( F_45 ( sizeof( struct V_104 ) , 4 ) +
( V_105 + V_392 + V_73 -> V_395 ) *
sizeof( struct V_2 ) , V_431 ) ;
if ( V_8 == NULL ) {
F_96 ( & V_401 -> V_5 , L_68 ) ;
goto V_422;
}
V_8 -> V_113 = V_113 ;
V_8 -> V_417 = V_417 ;
V_8 -> V_105 = V_105 ;
V_8 -> V_392 = V_392 ;
V_8 -> V_432 = V_188 -> V_424 ;
V_8 -> V_433 = F_173 ( V_188 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_73 = V_73 ;
V_8 -> V_5 = & V_401 -> V_5 ;
V_8 -> V_398 = ( ( void * ) V_8 ) + F_45 ( sizeof( struct V_104 ) , 4 ) ;
V_8 -> V_391 = & V_8 -> V_398 [ V_105 ] ;
V_8 -> V_107 = F_177 ( V_105 * sizeof( struct V_240 ) ,
V_431 ) ;
if ( ! V_8 -> V_107 )
goto V_422;
V_8 -> V_223 = F_177 ( V_105 *
sizeof( struct V_2 * ) ,
V_431 ) ;
if ( ! V_8 -> V_223 )
goto V_422;
if ( V_392 + V_73 -> V_395 ) {
V_8 -> V_224 = F_177 ( V_73 -> V_430 * 2 *
sizeof( struct V_2 * ) ,
V_431 ) ;
if ( ! V_8 -> V_224 )
goto V_422;
}
V_8 -> V_110 = F_6 ( V_8 -> V_105 *
sizeof( V_109 ) ,
V_431 ) ;
if ( ! V_8 -> V_110 )
goto V_422;
V_8 -> V_37 . V_40 =
F_177 ( V_105 * sizeof( struct V_14 * )
* V_39 , V_431 ) ;
if ( ! V_8 -> V_37 . V_40 )
goto V_422;
V_8 -> V_48 = F_178 ( V_425 , sizeof( struct V_14 ) ,
0 , V_434 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_422;
return V_8 ;
V_422:
if ( ! V_419 )
F_179 ( V_417 ) ;
if ( ! F_169 ( V_417 ) )
F_180 ( V_417 ) ;
if ( V_9 )
F_181 ( V_9 ) ;
if ( V_188 )
F_182 ( V_188 -> V_424 ,
F_173 ( V_188 ) ) ;
if ( V_9 )
F_181 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_110 ) ;
F_10 ( V_8 -> V_224 ) ;
F_10 ( V_8 -> V_223 ) ;
F_10 ( V_8 -> V_107 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_183 ( struct V_104 * V_8 )
{
static struct V_435 V_436 [] = {
{ . V_135 = V_404 , . V_149 = V_406 } ,
{ . V_135 = V_437 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_438 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_439 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_440 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_203 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_205 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_207 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_209 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_202 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_204 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_206 , . V_149 = 0xFFFFFFFF } ,
{ . V_135 = V_208 , . V_149 = 0xFFFFFFFF }
} ;
int V_33 ;
T_2 V_441 [ 2 ] = { 0 , 0 } ;
T_2 V_442 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_443 = 0 ;
T_2 V_444 = 0 ;
for ( V_33 = 0 ; V_33 < F_54 ( V_436 ) ; V_33 ++ )
F_30 ( V_436 [ V_33 ] . V_149 ,
V_8 -> V_9 + V_436 [ V_33 ] . V_135 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_105 ; V_33 ++ ) {
V_442 [ V_33 % 2 ] = V_442 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_107 [ V_8 -> V_105 - V_33 - 1 ] . V_245
== V_248 ) {
V_442 [ V_33 % 2 ] |= 3 ;
continue;
}
V_443 = ( V_443 << 1 ) | 1 ;
V_444 = ( V_444 << 1 ) | 1 ;
V_441 [ V_33 % 2 ] = V_441 [ V_33 % 2 ] << 2 ;
V_441 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_441 [ 1 ] , V_8 -> V_9 + V_169 ) ;
F_30 ( V_441 [ 0 ] , V_8 -> V_9 + V_445 ) ;
F_30 ( V_442 [ 1 ] , V_8 -> V_9 + V_124 ) ;
F_30 ( V_442 [ 0 ] , V_8 -> V_9 + V_125 ) ;
F_30 ( V_443 , V_8 -> V_9 + V_446 ) ;
F_30 ( V_444 , V_8 -> V_9 + V_215 ) ;
}
static int T_9 F_184 ( struct V_104 * V_8 )
{
struct V_64 * V_65 = & V_8 -> V_37 ;
unsigned long * V_447 ;
int V_33 , V_258 ;
int V_34 = 0 ;
V_447 = F_6 ( sizeof( unsigned long ) * V_448 ,
V_431 ) ;
if ( ! V_447 ) {
V_34 = - V_25 ;
goto V_422;
}
V_8 -> V_37 . V_449 = V_450 * V_8 -> V_105 / V_451 ;
for ( V_33 = 0 ; V_33 < V_448 ; V_33 ++ ) {
V_447 [ V_33 ] = F_185 ( V_431 ,
V_8 -> V_37 . V_449 ) ;
if ( ! V_447 [ V_33 ] ) {
F_96 ( V_8 -> V_5 , L_69 ,
V_8 -> V_37 . V_449 ) ;
for ( V_258 = 0 ; V_258 < V_33 ; V_258 ++ )
F_186 ( V_447 [ V_258 ] , V_8 -> V_37 . V_449 ) ;
goto V_422;
}
if ( ( F_113 ( ( void * ) V_447 [ V_33 ] ) &
( V_452 - 1 ) ) == 0 )
break;
}
for ( V_258 = 0 ; V_258 < V_33 ; V_258 ++ )
F_186 ( V_447 [ V_258 ] , V_8 -> V_37 . V_449 ) ;
if ( V_33 < V_448 ) {
V_8 -> V_37 . V_8 = ( void * ) V_447 [ V_33 ] ;
} else {
F_187 ( V_8 -> V_5 ,
L_70 ,
V_140 , V_8 -> V_37 . V_449 ) ;
V_8 -> V_37 . V_453 = F_6 ( V_450 *
V_8 -> V_105 +
V_452 ,
V_431 ) ;
if ( ! V_8 -> V_37 . V_453 ) {
V_34 = - V_25 ;
goto V_422;
}
V_8 -> V_37 . V_8 = F_7 ( V_8 -> V_37 . V_453 ,
V_452 ) ;
}
V_65 -> V_29 = F_8 ( V_8 -> V_5 , V_65 -> V_8 ,
V_450 * V_8 -> V_105 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_65 -> V_29 ) ) {
V_65 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_422;
}
F_30 ( F_113 ( V_8 -> V_37 . V_8 ) ,
V_8 -> V_9 + V_454 ) ;
V_422:
F_10 ( V_447 ) ;
return V_34 ;
}
static int T_9 F_188 ( struct V_400 * V_401 )
{
int V_193 ;
int V_34 = - V_455 ;
struct V_104 * V_8 ;
struct V_418 * V_188 = NULL ;
int V_389 ;
T_2 V_149 ;
V_8 = F_167 ( V_401 ) ;
if ( ! V_8 )
goto V_422;
V_389 = F_163 ( V_8 ) ;
F_189 ( V_401 , V_8 ) ;
F_146 ( & V_8 -> V_219 ) ;
F_146 ( & V_8 -> V_123 ) ;
V_188 = F_171 ( V_401 , V_423 , L_71 ) ;
if ( ! V_188 ) {
V_34 = - V_455 ;
F_96 ( & V_401 -> V_5 , L_72 ) ;
goto V_422;
}
V_8 -> V_456 = F_173 ( V_188 ) ;
V_8 -> V_457 = V_188 -> V_424 ;
if ( F_172 ( V_188 -> V_424 , F_173 ( V_188 ) ,
V_425 L_73 ) == NULL ) {
V_34 = - V_129 ;
F_96 ( & V_401 -> V_5 ,
L_74 ,
V_188 -> V_424 , V_188 -> V_458 ) ;
goto V_422;
}
V_149 = F_56 ( V_8 -> V_9 + V_459 ) ;
if ( V_188 -> V_424 != V_149 && V_149 != 0 ) {
F_187 ( & V_401 -> V_5 ,
L_75 ,
V_140 , V_149 , V_188 -> V_424 ) ;
} else
F_30 ( V_188 -> V_424 , V_8 -> V_9 + V_459 ) ;
V_8 -> V_311 = F_174 ( V_188 -> V_424 , F_173 ( V_188 ) ) ;
if ( ! V_8 -> V_311 ) {
V_34 = - V_25 ;
F_96 ( & V_401 -> V_5 , L_76 ) ;
goto V_422;
}
if ( V_8 -> V_73 -> V_72 ) {
V_188 = F_171 ( V_401 , V_423 ,
L_77 ) ;
if ( ! V_188 ) {
V_34 = - V_455 ;
F_96 ( & V_401 -> V_5 ,
L_78 ) ;
goto V_422;
}
V_8 -> V_37 . V_8 = F_174 ( V_188 -> V_424 ,
F_173 ( V_188 ) ) ;
if ( ! V_8 -> V_37 . V_8 ) {
V_34 = - V_25 ;
F_96 ( & V_401 -> V_5 , L_79 ) ;
goto V_422;
}
F_30 ( V_188 -> V_424 , V_8 -> V_9 + V_454 ) ;
} else {
V_34 = F_184 ( V_8 ) ;
if ( V_34 ) {
F_96 ( & V_401 -> V_5 , L_80 ) ;
goto V_422;
}
}
F_146 ( & V_8 -> V_37 . V_38 ) ;
V_8 -> V_199 = F_190 ( V_401 , 0 ) ;
V_34 = F_191 ( V_8 -> V_199 , F_93 , 0 , V_425 , V_8 ) ;
if ( V_34 ) {
F_96 ( & V_401 -> V_5 , L_81 ) ;
goto V_422;
}
F_192 ( V_8 -> V_5 ) ;
F_193 ( V_8 -> V_5 , V_460 ) ;
F_194 ( V_8 -> V_5 ) ;
F_195 ( V_8 -> V_5 ) ;
F_196 ( V_8 -> V_5 ) ;
if ( V_8 -> V_73 -> V_72 ) {
V_8 -> V_402 = F_197 ( V_8 -> V_5 , L_77 ) ;
if ( F_169 ( V_8 -> V_402 ) ) {
F_96 ( & V_401 -> V_5 , L_82 ) ;
V_8 -> V_402 = NULL ;
goto V_422;
}
V_34 = F_162 ( V_8 -> V_402 ) ;
if ( V_34 ) {
F_96 ( & V_401 -> V_5 ,
L_83 ) ;
F_198 ( V_8 -> V_402 ) ;
V_8 -> V_402 = NULL ;
goto V_422;
}
}
V_8 -> V_405 = true ;
V_193 = F_149 ( V_8 , V_389 ) ;
if ( V_193 )
goto V_422;
F_183 ( V_8 ) ;
F_166 ( V_8 -> V_5 , L_84 ) ;
return 0 ;
V_422:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_199 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_181 ( V_8 -> V_9 ) ;
if ( V_8 -> V_37 . V_8 && V_8 -> V_73 -> V_72 ) {
F_181 ( V_8 -> V_37 . V_8 ) ;
V_8 -> V_37 . V_8 = NULL ;
}
if ( V_8 -> V_37 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_37 . V_29 ,
V_450 * V_8 -> V_105 ,
V_31 ) ;
if ( ! V_8 -> V_37 . V_453 && V_8 -> V_37 . V_8 )
F_186 ( ( unsigned long ) V_8 -> V_37 . V_8 ,
V_8 -> V_37 . V_449 ) ;
F_10 ( V_8 -> V_37 . V_453 ) ;
if ( V_8 -> V_457 )
F_182 ( V_8 -> V_457 ,
V_8 -> V_456 ) ;
if ( V_8 -> V_432 )
F_182 ( V_8 -> V_432 ,
V_8 -> V_433 ) ;
if ( V_8 -> V_417 ) {
F_200 ( V_8 -> V_417 ) ;
F_180 ( V_8 -> V_417 ) ;
}
if ( V_8 -> V_402 ) {
F_158 ( V_8 -> V_402 ) ;
F_198 ( V_8 -> V_402 ) ;
}
F_10 ( V_8 -> V_37 . V_40 ) ;
F_10 ( V_8 -> V_224 ) ;
F_10 ( V_8 -> V_223 ) ;
F_10 ( V_8 -> V_107 ) ;
F_10 ( V_8 ) ;
}
F_96 ( & V_401 -> V_5 , L_85 ) ;
return V_34 ;
}
static int T_9 F_201 ( void )
{
return F_202 ( & V_461 , F_188 ) ;
}
