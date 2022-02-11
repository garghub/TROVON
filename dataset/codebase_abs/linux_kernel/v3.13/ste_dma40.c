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
F_14 ( & V_3 -> V_8 -> V_36 . V_37 , V_32 ) ;
for ( V_33 = 1 ; V_33 < V_38 / 2 ; V_33 ++ ) {
int V_39 = V_3 -> V_11 -> V_12 * V_38 + V_33 ;
if ( ! V_3 -> V_8 -> V_36 . V_40 [ V_39 ] ) {
V_3 -> V_8 -> V_36 . V_40 [ V_39 ] = V_15 ;
V_15 -> V_41 ++ ;
V_34 = V_33 ;
break;
}
}
F_15 ( & V_3 -> V_8 -> V_36 . V_37 , V_32 ) ;
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
F_14 ( & V_3 -> V_8 -> V_36 . V_37 , V_32 ) ;
for ( V_33 = 1 ; V_33 < V_38 / 2 ; V_33 ++ ) {
int V_39 = V_3 -> V_11 -> V_12 * V_38 + V_33 ;
if ( V_3 -> V_8 -> V_36 . V_40 [ V_39 ] == V_15 ) {
V_3 -> V_8 -> V_36 . V_40 [ V_39 ] = NULL ;
V_15 -> V_41 -- ;
if ( V_15 -> V_41 == 0 ) {
V_34 = 0 ;
break;
}
}
}
F_15 ( & V_3 -> V_8 -> V_36 . V_37 , V_32 ) ;
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
static void F_31 ( struct V_2 * V_3 , struct V_14 * V_43 )
{
F_28 ( & V_43 -> V_42 , & V_3 -> V_64 ) ;
}
static void F_32 ( struct V_2 * V_4 , struct V_14 * V_43 )
{
struct V_65 * V_66 = & V_4 -> V_8 -> V_36 ;
struct V_67 * V_68 = & V_43 -> V_26 ;
int V_69 = V_43 -> V_69 ;
int V_16 = V_43 -> V_16 ;
bool V_70 = V_43 -> V_70 ;
int V_71 = - V_35 ;
int V_72 = 0 ;
bool V_73 = V_4 -> V_8 -> V_74 -> V_73 ;
bool V_75 ;
V_75 = V_70 && V_69 == 0 ;
if ( V_75 || ( V_16 - V_69 > 1 ) ) {
if ( ! ( V_4 -> V_11 -> V_76 &&
V_4 -> V_77 . V_78 == V_79 ) )
V_71 = F_13 ( V_4 , V_43 ) ;
V_72 = V_71 ;
}
if ( ! V_75 || V_71 == - V_35 ) {
unsigned int V_32 = 0 ;
if ( V_71 == - V_35 )
V_32 |= V_80 ;
F_33 ( V_4 -> V_81 ,
& V_68 -> V_28 [ V_69 ] ,
& V_68 -> V_27 [ V_69 ] ,
V_71 ,
V_32 ) ;
V_69 ++ ;
}
if ( V_71 < 0 )
goto V_82;
for (; V_69 < V_16 ; V_69 ++ ) {
unsigned int V_83 = V_4 -> V_11 -> V_12 * 1024 +
8 * V_71 * 2 ;
struct V_19 * V_84 = V_66 -> V_8 + V_83 ;
unsigned int V_32 = 0 ;
int V_85 ;
if ( V_69 + 1 < V_16 )
V_85 = F_13 ( V_4 , V_43 ) ;
else
V_85 = V_75 ? V_72 : - V_35 ;
if ( V_70 || V_85 == - V_35 )
V_32 |= V_80 ;
if ( V_75 && V_71 == V_72 ) {
F_33 ( V_4 -> V_81 ,
& V_68 -> V_28 [ V_69 ] ,
& V_68 -> V_27 [ V_69 ] ,
V_85 , V_32 ) ;
}
F_34 ( V_84 ,
& V_68 -> V_28 [ V_69 ] ,
& V_68 -> V_27 [ V_69 ] ,
V_85 , V_32 ) ;
if ( ! V_73 ) {
F_35 ( V_4 -> V_8 -> V_5 ,
V_66 -> V_29 , V_83 ,
2 * sizeof( struct V_19 ) ,
V_31 ) ;
}
V_71 = V_85 ;
if ( V_71 == - V_35 || V_71 == V_72 ) {
V_69 ++ ;
break;
}
}
V_82:
V_43 -> V_69 = V_69 ;
}
static void F_36 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
if ( F_2 ( V_3 ) ) {
F_29 ( V_3 , V_15 ) ;
V_15 -> V_69 = V_15 -> V_16 ;
} else
F_32 ( V_3 , V_15 ) ;
}
static struct V_14 * F_37 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_49 ) )
return NULL ;
V_45 = F_38 ( & V_3 -> V_49 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static void F_39 ( struct V_2 * V_3 , struct V_14 * V_43 )
{
F_17 ( V_43 ) ;
V_43 -> V_86 = false ;
F_28 ( & V_43 -> V_42 , & V_3 -> V_87 ) ;
}
static struct V_14 * F_40 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_87 ) )
return NULL ;
V_45 = F_38 ( & V_3 -> V_87 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static struct V_14 * F_41 ( struct V_2 * V_3 )
{
struct V_14 * V_45 ;
if ( F_20 ( & V_3 -> V_88 ) )
return NULL ;
V_45 = F_38 ( & V_3 -> V_88 ,
struct V_14 ,
V_42 ) ;
return V_45 ;
}
static struct V_14 * F_42 ( struct V_2 * V_3 )
{
if ( F_20 ( & V_3 -> V_64 ) )
return NULL ;
return F_38 ( & V_3 -> V_64 , struct V_14 , V_42 ) ;
}
static int F_43 ( bool V_17 , int V_89 )
{
if ( V_17 ) {
if ( V_89 == V_90 )
return 1 ;
} else {
if ( V_89 == V_91 )
return 1 ;
}
return 2 << V_89 ;
}
static int F_44 ( int V_23 , T_2 V_92 , T_2 V_93 )
{
int V_94 ;
T_2 V_95 = F_45 ( V_92 , V_93 ) ;
T_2 V_96 = F_46 ( V_92 , V_93 ) ;
T_2 V_97 = F_47 ( V_98 * V_96 , V_95 ) ;
if ( V_97 > V_98 )
V_97 -= V_95 ;
if ( ! F_48 ( V_23 , V_95 ) )
return - V_35 ;
if ( V_23 <= V_97 )
V_94 = 1 ;
else {
V_94 = V_23 / V_97 ;
if ( V_94 * V_97 < V_23 )
V_94 ++ ;
}
return V_94 ;
}
static int F_49 ( struct V_99 * V_100 , int V_101 ,
T_2 V_92 , T_2 V_93 )
{
struct V_99 * V_102 ;
int V_33 ;
int V_103 = 0 ;
int V_34 ;
F_50 (sgl, sg, sg_len, i) {
V_34 = F_44 ( F_51 ( V_102 ) ,
V_92 , V_93 ) ;
if ( V_34 < 0 )
return V_34 ;
V_103 += V_34 ;
}
return V_103 ;
}
static void F_52 ( void T_1 * V_104 , T_2 * V_105 ,
T_2 * V_106 , int V_12 , bool V_107 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ ) {
void T_1 * V_108 = V_104 + V_106 [ V_33 ] ;
if ( V_107 )
V_105 [ V_33 ] = F_53 ( V_108 ) ;
else
F_54 ( V_105 [ V_33 ] , V_108 ) ;
}
}
static void F_55 ( struct V_109 * V_8 , bool V_107 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
void T_1 * V_108 ;
int V_39 ;
if ( V_8 -> V_111 [ V_33 ] . V_112 )
continue;
V_108 = V_8 -> V_9 + V_10 + V_33 * V_13 ;
V_39 = V_33 * F_56 ( V_113 ) ;
F_52 ( V_108 , & V_8 -> V_114 [ V_39 ] ,
V_113 ,
F_56 ( V_113 ) ,
V_107 ) ;
}
F_52 ( V_8 -> V_9 , V_8 -> V_115 ,
V_116 , F_56 ( V_116 ) ,
V_107 ) ;
if ( V_8 -> V_117 . V_105 )
F_52 ( V_8 -> V_9 , V_8 -> V_118 ,
V_8 -> V_117 . V_105 ,
V_8 -> V_117 . V_119 ,
V_107 ) ;
}
static void F_55 ( struct V_109 * V_8 , bool V_107 )
{
}
static int F_57 ( struct V_2 * V_3 ,
enum V_120 V_121 )
{
T_2 V_122 ;
int V_33 ;
void T_1 * V_123 ;
int V_34 = 0 ;
unsigned long V_32 ;
T_2 V_124 ;
if ( V_121 == V_125 ) {
V_34 = F_57 ( V_3 , V_126 ) ;
if ( V_34 )
return V_34 ;
}
F_14 ( & V_3 -> V_8 -> V_127 , V_32 ) ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_123 = V_3 -> V_8 -> V_9 + V_128 ;
else
V_123 = V_3 -> V_8 -> V_9 + V_129 ;
if ( V_121 == V_126 ) {
V_122 = ( F_58 ( V_123 ) &
F_59 ( V_3 -> V_11 -> V_12 ) ) >>
F_60 ( V_3 -> V_11 -> V_12 ) ;
if ( V_122 == V_130 || V_122 == V_125 )
goto V_64;
}
V_124 = 0xffffffff & ~ ( F_59 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_124 | ( V_121 << F_60 ( V_3 -> V_11 -> V_12 ) ) ,
V_123 ) ;
if ( V_121 == V_126 ) {
for ( V_33 = 0 ; V_33 < V_131 ; V_33 ++ ) {
V_122 = ( F_58 ( V_123 ) &
F_59 ( V_3 -> V_11 -> V_12 ) ) >>
F_60 ( V_3 -> V_11 -> V_12 ) ;
F_61 () ;
F_62 ( 3 ) ;
if ( V_122 == V_125 ||
V_122 == V_130 )
break;
}
if ( V_33 == V_131 ) {
F_63 ( V_3 ,
L_1 ,
V_3 -> V_11 -> V_12 , V_3 -> V_6 ,
V_122 ) ;
F_64 () ;
V_34 = - V_132 ;
}
}
V_64:
F_15 ( & V_3 -> V_8 -> V_127 , V_32 ) ;
return V_34 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
struct V_14 * V_46 ;
while ( ( V_15 = F_42 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
while ( ( V_15 = F_37 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
while ( ( V_15 = F_41 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
while ( ( V_15 = F_40 ( V_3 ) ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
if ( ! F_20 ( & V_3 -> V_44 ) )
F_21 (d40d, _d, &d40c->client, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
if ( ! F_20 ( & V_3 -> V_133 ) )
F_21 (d40d, _d,
&d40c->prepare_queue, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
V_3 -> V_134 = 0 ;
}
static void F_66 ( struct V_2 * V_3 ,
enum V_135 V_136 , T_2 V_137 ,
int V_138 )
{
void T_1 * V_108 = F_4 ( V_3 ) + V_138 ;
int V_139 ;
T_2 V_122 ;
switch ( V_136 ) {
case V_140 :
F_30 ( ( V_140 << F_67 ( V_137 ) )
| ~ F_68 ( V_137 ) , V_108 ) ;
break;
case V_141 :
V_122 = ( F_58 ( V_108 ) & F_68 ( V_137 ) ) >>
F_67 ( V_137 ) ;
if ( V_122 == V_140 ||
V_122 == V_141 )
break;
F_30 ( ( V_141 << F_67 ( V_137 ) )
| ~ F_68 ( V_137 ) , V_108 ) ;
for ( V_139 = 0 ; V_139 < V_131 ; V_139 ++ ) {
V_122 = ( F_58 ( V_108 ) & F_68 ( V_137 ) ) >>
F_67 ( V_137 ) ;
F_61 () ;
F_62 ( 3 ) ;
if ( V_122 == V_140 )
break;
}
if ( V_139 == V_131 ) {
F_63 ( V_3 ,
L_2
L_3 , V_3 -> V_11 -> V_12 ,
V_3 -> V_6 , V_122 ) ;
}
break;
case V_142 :
V_139 = 100 ;
while ( -- V_139 ) {
F_30 ( ( V_142 <<
F_67 ( V_137 ) ) |
~ F_68 ( V_137 ) , V_108 ) ;
if ( F_58 ( V_108 ) & F_68 ( V_137 ) )
break;
}
if ( V_139 != 99 )
F_69 ( F_1 ( V_3 ) ,
L_4 ,
V_143 , V_138 == V_59 ? 'S' : 'D' ,
100 - V_139 ) ;
F_70 ( ! V_139 ) ;
break;
case V_144 :
F_71 () ;
break;
}
}
static void F_72 ( struct V_2 * V_3 ,
enum V_135 V_136 )
{
T_2 V_137 = F_73 ( V_3 -> V_77 . V_145 ) ;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_146 ) )
F_66 ( V_3 , V_136 , V_137 ,
V_59 ) ;
if ( V_3 -> V_77 . V_78 != V_79 )
F_66 ( V_3 , V_136 , V_137 ,
V_63 ) ;
}
static T_2 F_74 ( struct V_2 * V_3 )
{
void T_1 * V_147 = F_4 ( V_3 ) ;
T_2 V_148 ;
V_148 = F_58 ( V_147 + V_59 ) ;
V_148 |= F_58 ( V_147 + V_63 ) ;
return V_148 ;
}
static int
F_75 ( struct V_2 * V_3 , enum V_120 V_121 )
{
unsigned long V_32 ;
int V_34 = 0 ;
T_2 V_149 ;
void T_1 * V_123 ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_123 = V_3 -> V_8 -> V_9 + V_128 ;
else
V_123 = V_3 -> V_8 -> V_9 + V_129 ;
F_14 ( & V_3 -> V_11 -> V_37 , V_32 ) ;
switch ( V_121 ) {
case V_125 :
case V_126 :
V_149 = ( F_58 ( V_123 ) &
F_59 ( V_3 -> V_11 -> V_12 ) ) >>
F_60 ( V_3 -> V_11 -> V_12 ) ;
if ( V_149 == V_150 )
F_72 ( V_3 , V_141 ) ;
else
F_72 ( V_3 , V_140 ) ;
if ( ! F_74 ( V_3 ) && ( V_121 == V_125 ) )
V_34 = F_57 ( V_3 , V_121 ) ;
break;
case V_150 :
F_72 ( V_3 , V_142 ) ;
V_34 = F_57 ( V_3 , V_121 ) ;
break;
case V_130 :
F_71 () ;
break;
}
F_15 ( & V_3 -> V_11 -> V_37 , V_32 ) ;
return V_34 ;
}
static int F_76 ( struct V_2 * V_3 ,
enum V_120 V_121 )
{
if ( F_3 ( V_3 ) )
return F_75 ( V_3 , V_121 ) ;
else
return F_57 ( V_3 , V_121 ) ;
}
static T_2 F_77 ( struct V_2 * V_3 )
{
static const unsigned int V_151 [] = {
[ V_152 ]
= V_153 ,
[ V_154 ]
= V_155 ,
[ V_156 ]
= V_157 ,
} ;
static const unsigned int V_158 [] = {
[ V_159 ]
= V_160 ,
[ V_161 ]
= V_162 ,
[ V_163 ]
= V_164 ,
} ;
if ( F_2 ( V_3 ) )
return V_151 [ V_3 -> V_77 . V_165 ] ;
else
return V_158 [ V_3 -> V_77 . V_165 ] ;
}
static void F_78 ( struct V_2 * V_3 )
{
T_2 V_166 ;
T_2 V_167 ;
V_166 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_167 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_60 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_167 , V_3 -> V_8 -> V_9 + V_168 + V_166 ) ;
V_167 = F_77 ( V_3 ) << F_60 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_167 , V_3 -> V_8 -> V_9 + V_169 + V_166 ) ;
if ( F_3 ( V_3 ) ) {
int V_170 = ( V_3 -> V_11 -> V_12 << V_171 )
& V_172 ;
void T_1 * V_147 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_173 , V_147 + V_53 ) ;
F_30 ( V_3 -> V_174 , V_147 + V_60 ) ;
F_30 ( V_170 , V_147 + V_55 ) ;
F_30 ( V_170 , V_147 + V_61 ) ;
F_30 ( 0 , V_147 + V_59 ) ;
F_30 ( 0 , V_147 + V_63 ) ;
}
}
static T_2 F_79 ( struct V_2 * V_3 )
{
T_2 V_175 ;
if ( F_3 ( V_3 ) )
V_175 = ( F_58 ( & V_3 -> V_81 -> V_176 ) & V_177 )
>> V_178 ;
else {
T_2 V_148 = F_58 ( F_4 ( V_3 ) + V_61 ) ;
V_175 = ( V_148 & V_179 )
>> V_180 ;
}
return V_175 * V_3 -> V_77 . V_181 . V_182 ;
}
static bool F_80 ( struct V_2 * V_3 )
{
bool V_183 ;
if ( F_3 ( V_3 ) )
V_183 = F_58 ( & V_3 -> V_81 -> V_184 ) & V_185 ;
else
V_183 = F_58 ( F_4 ( V_3 ) + V_63 )
& V_186 ;
return V_183 ;
}
static int F_81 ( struct V_2 * V_3 )
{
int V_187 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_188 )
return 0 ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_187 = F_76 ( V_3 , V_126 ) ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_187 ;
}
static int F_85 ( struct V_2 * V_3 )
{
int V_187 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_188 )
return 0 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
if ( F_79 ( V_3 ) || F_80 ( V_3 ) )
V_187 = F_76 ( V_3 , V_150 ) ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_187 ;
}
static T_3 F_86 ( struct V_189 * V_190 )
{
struct V_2 * V_3 = F_87 ( V_190 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_87 ( V_190 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
T_3 V_191 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_191 = F_88 ( V_190 ) ;
F_39 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_191 ;
}
static int F_89 ( struct V_2 * V_3 )
{
return F_76 ( V_3 , V_150 ) ;
}
static struct V_14 * F_90 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_192 ;
V_15 = F_41 ( V_3 ) ;
if ( V_15 != NULL ) {
if ( ! V_3 -> V_188 ) {
V_3 -> V_188 = true ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_36 ( V_3 , V_15 ) ;
V_192 = F_89 ( V_3 ) ;
if ( V_192 )
return NULL ;
}
return V_15 ;
}
static void F_91 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_15 = F_37 ( V_3 ) ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_70 ) {
if ( V_15 -> V_69 < V_15 -> V_16
&& ! F_80 ( V_3 )
&& ! F_79 ( V_3 ) ) {
F_16 ( V_3 , V_15 ) ;
F_36 ( V_3 , V_15 ) ;
( void ) F_89 ( V_3 ) ;
if ( V_15 -> V_69 == V_15 -> V_16 )
V_15 -> V_69 = 0 ;
}
} else {
F_16 ( V_3 , V_15 ) ;
if ( V_15 -> V_69 < V_15 -> V_16 ) {
F_36 ( V_3 , V_15 ) ;
( void ) F_89 ( V_3 ) ;
return;
}
if ( F_90 ( V_3 ) == NULL ) {
V_3 -> V_188 = false ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_31 ( V_3 , V_15 ) ;
}
V_3 -> V_134 ++ ;
F_92 ( & V_3 -> V_193 ) ;
}
static void F_93 ( unsigned long V_194 )
{
struct V_2 * V_3 = (struct V_2 * ) V_194 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
T_4 V_195 ;
void * V_196 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_15 = F_42 ( V_3 ) ;
if ( V_15 == NULL ) {
V_15 = F_37 ( V_3 ) ;
if ( V_15 == NULL || ! V_15 -> V_70 )
goto V_192;
}
if ( ! V_15 -> V_70 )
F_94 ( & V_15 -> V_47 ) ;
if ( V_3 -> V_134 == 0 ) {
F_15 ( & V_3 -> V_37 , V_32 ) ;
return;
}
V_195 = V_15 -> V_47 . V_195 ;
V_196 = V_15 -> V_47 . V_196 ;
if ( ! V_15 -> V_70 ) {
if ( F_22 ( & V_15 -> V_47 ) ) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
} else if ( ! V_15 -> V_86 ) {
F_17 ( V_15 ) ;
F_16 ( V_3 , V_15 ) ;
F_28 ( & V_15 -> V_42 , & V_3 -> V_44 ) ;
V_15 -> V_86 = true ;
}
}
V_3 -> V_134 -- ;
if ( V_3 -> V_134 )
F_92 ( & V_3 -> V_193 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
if ( V_195 && ( V_15 -> V_47 . V_32 & V_197 ) )
V_195 ( V_196 ) ;
return;
V_192:
if ( V_3 -> V_134 > 0 )
V_3 -> V_134 -- ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static T_5 F_95 ( int V_198 , void * V_194 )
{
int V_33 ;
T_2 V_39 ;
T_2 V_199 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_109 * V_8 = V_194 ;
T_2 V_200 [ V_8 -> V_117 . V_201 ] ;
struct V_202 * V_203 = V_8 -> V_117 . V_203 ;
T_2 V_201 = V_8 -> V_117 . V_201 ;
F_14 ( & V_8 -> V_204 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_201 ; V_33 ++ )
V_200 [ V_33 ] = F_58 ( V_8 -> V_9 + V_203 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_96 ( ( unsigned long * ) V_200 ,
V_205 * V_201 , V_4 + 1 ) ;
if ( V_4 == V_205 * V_201 )
break;
V_199 = V_4 / V_205 ;
V_39 = V_4 & ( V_205 - 1 ) ;
if ( V_203 [ V_199 ] . V_206 == V_7 )
V_3 = V_8 -> V_207 [ V_39 ] ;
else
V_3 = V_8 -> V_208 [ V_203 [ V_199 ] . V_206 + V_39 ] ;
if ( ! V_3 ) {
continue;
}
F_30 ( F_97 ( V_39 ) , V_8 -> V_9 + V_203 [ V_199 ] . V_209 ) ;
F_98 ( & V_3 -> V_37 ) ;
if ( ! V_203 [ V_199 ] . V_210 )
F_91 ( V_3 ) ;
else
F_99 ( V_8 -> V_5 , L_5 ,
V_4 , V_203 [ V_199 ] . V_206 , V_39 ) ;
F_100 ( & V_3 -> V_37 ) ;
}
F_15 ( & V_8 -> V_204 , V_32 ) ;
return V_211 ;
}
static int F_101 ( struct V_2 * V_3 ,
struct V_212 * V_213 )
{
int V_187 = 0 ;
bool V_17 = V_213 -> V_214 == V_215 ;
if ( ! V_213 -> V_78 ) {
F_63 ( V_3 , L_6 ) ;
V_187 = - V_35 ;
}
if ( ( V_17 && V_213 -> V_145 > V_3 -> V_8 -> V_216 ) ||
( ! V_17 && V_213 -> V_145 > V_3 -> V_8 -> V_110 ) ||
( V_213 -> V_145 < 0 ) ) {
F_63 ( V_3 , L_7 , V_213 -> V_145 ) ;
V_187 = - V_35 ;
}
if ( V_213 -> V_78 == V_146 ) {
F_63 ( V_3 , L_8 ) ;
V_187 = - V_35 ;
}
if ( F_43 ( V_17 , V_213 -> V_217 . V_89 ) *
V_213 -> V_217 . V_182 !=
F_43 ( V_17 , V_213 -> V_181 . V_89 ) *
V_213 -> V_181 . V_182 ) {
F_63 ( V_3 , L_9 ) ;
V_187 = - V_35 ;
}
return V_187 ;
}
static bool F_102 ( struct V_218 * V_219 ,
bool V_220 , int V_221 , bool V_17 ,
bool * V_222 )
{
unsigned long V_32 ;
F_14 ( & V_219 -> V_37 , V_32 ) ;
* V_222 = ( ( V_219 -> V_223 | V_219 -> V_224 )
== V_225 ) ;
if ( ! V_17 ) {
if ( V_219 -> V_223 == V_225 &&
V_219 -> V_224 == V_225 ) {
V_219 -> V_224 = V_226 ;
V_219 -> V_223 = V_226 ;
goto V_227;
} else
goto V_228;
}
if ( V_220 ) {
if ( V_219 -> V_223 == V_226 )
goto V_228;
if ( V_219 -> V_223 == V_225 )
V_219 -> V_223 = V_229 ;
if ( ! ( V_219 -> V_223 & F_97 ( V_221 ) ) ) {
V_219 -> V_223 |= F_97 ( V_221 ) ;
goto V_227;
} else
goto V_228;
} else {
if ( V_219 -> V_224 == V_226 )
goto V_228;
if ( V_219 -> V_224 == V_225 )
V_219 -> V_224 = V_229 ;
if ( ! ( V_219 -> V_224 & F_97 ( V_221 ) ) ) {
V_219 -> V_224 |= F_97 ( V_221 ) ;
goto V_227;
} else
goto V_228;
}
V_228:
F_15 ( & V_219 -> V_37 , V_32 ) ;
return false ;
V_227:
F_15 ( & V_219 -> V_37 , V_32 ) ;
return true ;
}
static bool F_103 ( struct V_218 * V_219 , bool V_220 ,
int V_221 )
{
unsigned long V_32 ;
bool V_230 = false ;
F_14 ( & V_219 -> V_37 , V_32 ) ;
if ( ! V_221 ) {
V_219 -> V_224 = V_225 ;
V_219 -> V_223 = V_225 ;
V_230 = true ;
goto V_82;
}
if ( V_220 ) {
V_219 -> V_223 &= ~ F_97 ( V_221 ) ;
if ( V_219 -> V_223 == V_229 )
V_219 -> V_223 = V_225 ;
} else {
V_219 -> V_224 &= ~ F_97 ( V_221 ) ;
if ( V_219 -> V_224 == V_229 )
V_219 -> V_224 = V_225 ;
}
V_230 = ( ( V_219 -> V_223 | V_219 -> V_224 ) ==
V_225 ) ;
V_82:
F_15 ( & V_219 -> V_37 , V_32 ) ;
return V_230 ;
}
static int F_104 ( struct V_2 * V_3 , bool * V_231 )
{
int V_145 = V_3 -> V_77 . V_145 ;
int V_232 ;
int V_233 ;
struct V_218 * V_234 ;
int V_33 ;
int V_235 ;
int V_6 ;
int V_110 ;
bool V_220 ;
bool V_17 = V_3 -> V_77 . V_214 == V_215 ;
V_234 = V_3 -> V_8 -> V_111 ;
V_110 = V_3 -> V_8 -> V_110 ;
if ( V_3 -> V_77 . V_78 == V_79 ) {
V_6 = 2 * V_145 ;
V_220 = true ;
} else if ( V_3 -> V_77 . V_78 == V_236 ||
V_3 -> V_77 . V_78 == V_237 ) {
V_6 = 2 * V_145 + 1 ;
V_220 = false ;
} else
return - V_35 ;
V_232 = F_105 ( V_145 ) ;
V_233 = F_73 ( V_145 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_77 . V_78 == V_237 ) {
if ( V_3 -> V_77 . V_238 ) {
V_33 = V_3 -> V_77 . V_239 ;
if ( F_102 ( & V_234 [ V_33 ] , V_220 ,
0 , V_17 ,
V_231 ) )
goto V_240;
} else {
for ( V_33 = 0 ; V_33 < V_110 ; V_33 ++ ) {
if ( F_102 ( & V_234 [ V_33 ] , V_220 ,
0 , V_17 ,
V_231 ) )
goto V_240;
}
}
} else
for ( V_235 = 0 ; V_235 < V_3 -> V_8 -> V_110 ; V_235 += 8 ) {
int V_241 = V_235 + V_232 * 2 ;
for ( V_33 = V_241 ; V_33 < V_241 + 2 ; V_33 ++ ) {
if ( F_102 ( & V_234 [ V_33 ] ,
V_220 ,
0 ,
V_17 ,
V_231 ) )
goto V_240;
}
}
return - V_35 ;
V_240:
V_3 -> V_11 = & V_234 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_82;
}
if ( V_145 == - 1 )
return - V_35 ;
for ( V_235 = 0 ; V_235 < V_3 -> V_8 -> V_110 ; V_235 += 8 ) {
int V_241 = V_235 + V_232 * 2 ;
if ( V_3 -> V_77 . V_238 ) {
V_33 = V_3 -> V_77 . V_239 ;
if ( ( V_33 != V_241 ) && ( V_33 != V_241 + 1 ) ) {
F_106 ( F_1 ( V_3 ) ,
L_10 , V_33 ) ;
return - V_35 ;
}
if ( F_102 ( & V_234 [ V_33 ] , V_220 , V_233 ,
V_17 , V_231 ) )
goto V_242;
F_106 ( F_1 ( V_3 ) ,
L_11 , V_33 ) ;
return - V_35 ;
}
if ( V_220 ) {
for ( V_33 = V_241 ; V_33 < V_241 + 2 ; V_33 ++ ) {
if ( F_102 ( & V_234 [ V_33 ] , V_220 ,
V_233 , V_17 ,
V_231 ) )
goto V_242;
}
} else {
for ( V_33 = V_241 + 1 ; V_33 >= V_241 ; V_33 -- ) {
if ( F_102 ( & V_234 [ V_33 ] , V_220 ,
V_233 , V_17 ,
V_231 ) )
goto V_242;
}
}
}
return - V_35 ;
V_242:
V_3 -> V_11 = & V_234 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_82:
if ( V_17 )
V_3 -> V_8 -> V_208 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_207 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 )
{
T_6 V_243 = V_3 -> V_4 . V_1 -> V_244 ;
if ( F_108 ( V_245 , V_243 ) && ! F_108 ( V_246 , V_243 ) ) {
V_3 -> V_77 = V_247 ;
V_3 -> V_77 . V_145 = V_248 [ V_3 -> V_4 . V_249 ] ;
F_109 ( & V_3 -> V_77 ,
& V_3 -> V_250 . V_251 , & V_3 -> V_250 . V_184 ) ;
} else if ( F_108 ( V_245 , V_243 ) &&
F_108 ( V_246 , V_243 ) ) {
V_3 -> V_77 = V_252 ;
V_3 -> V_174 |= F_97 ( V_253 ) ;
V_3 -> V_173 |= F_97 ( V_254 ) ;
V_3 -> V_174 |= F_97 ( V_254 ) ;
} else {
F_63 ( V_3 , L_12 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
int V_187 = 0 ;
T_2 V_137 = F_73 ( V_3 -> V_77 . V_145 ) ;
struct V_218 * V_219 = V_3 -> V_11 ;
bool V_220 ;
F_65 ( V_3 ) ;
if ( V_219 == NULL ) {
F_63 ( V_3 , L_13 ) ;
return - V_35 ;
}
if ( V_219 -> V_223 == V_225 &&
V_219 -> V_224 == V_225 ) {
F_63 ( V_3 , L_14 ) ;
return - V_35 ;
}
if ( V_3 -> V_77 . V_78 == V_236 ||
V_3 -> V_77 . V_78 == V_237 )
V_220 = false ;
else if ( V_3 -> V_77 . V_78 == V_79 )
V_220 = true ;
else {
F_63 ( V_3 , L_15 ) ;
return - V_35 ;
}
F_82 ( V_3 -> V_8 -> V_5 ) ;
V_187 = F_76 ( V_3 , V_125 ) ;
if ( V_187 ) {
F_63 ( V_3 , L_16 ) ;
goto V_82;
}
F_103 ( V_219 , V_220 , F_3 ( V_3 ) ? V_137 : 0 ) ;
if ( F_3 ( V_3 ) )
V_3 -> V_8 -> V_208 [ V_3 -> V_6 ] = NULL ;
else
V_3 -> V_8 -> V_207 [ V_219 -> V_12 ] = NULL ;
if ( V_3 -> V_188 ) {
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_188 = false ;
V_3 -> V_11 = NULL ;
V_3 -> V_255 = false ;
V_82:
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
return V_187 ;
}
static bool F_111 ( struct V_2 * V_3 )
{
void T_1 * V_147 = F_4 ( V_3 ) ;
bool V_256 = false ;
unsigned long V_32 ;
void T_1 * V_123 ;
T_2 V_122 ;
T_2 V_137 = F_73 ( V_3 -> V_77 . V_145 ) ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
if ( F_2 ( V_3 ) ) {
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_123 = V_3 -> V_8 -> V_9 + V_128 ;
else
V_123 = V_3 -> V_8 -> V_9 + V_129 ;
V_122 = ( F_58 ( V_123 ) &
F_59 ( V_3 -> V_11 -> V_12 ) ) >>
F_60 ( V_3 -> V_11 -> V_12 ) ;
if ( V_122 == V_130 || V_122 == V_125 )
V_256 = true ;
goto V_257;
}
if ( V_3 -> V_77 . V_78 == V_236 ||
V_3 -> V_77 . V_78 == V_237 ) {
V_122 = F_58 ( V_147 + V_63 ) ;
} else if ( V_3 -> V_77 . V_78 == V_79 ) {
V_122 = F_58 ( V_147 + V_59 ) ;
} else {
F_63 ( V_3 , L_15 ) ;
goto V_257;
}
V_122 = ( V_122 & F_68 ( V_137 ) ) >>
F_67 ( V_137 ) ;
if ( V_122 != V_150 )
V_256 = true ;
V_257:
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_256 ;
}
static T_2 F_112 ( struct V_258 * V_4 )
{
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_259 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_259 = F_79 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_259 ;
}
static int
F_113 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_260 , struct V_99 * V_261 ,
unsigned int V_101 , T_7 V_262 ,
T_7 V_263 )
{
struct V_212 * V_264 = & V_4 -> V_77 ;
struct V_265 * V_217 = & V_264 -> V_217 ;
struct V_265 * V_181 = & V_264 -> V_181 ;
int V_34 ;
V_34 = F_114 ( V_260 , V_101 ,
V_262 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_250 . V_251 ,
V_217 -> V_182 ,
V_181 -> V_182 ) ;
V_34 = F_114 ( V_261 , V_101 ,
V_263 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_250 . V_184 ,
V_181 -> V_182 ,
V_217 -> V_182 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_115 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_260 , struct V_99 * V_261 ,
unsigned int V_101 , T_7 V_262 ,
T_7 V_263 )
{
struct V_212 * V_264 = & V_4 -> V_77 ;
struct V_265 * V_217 = & V_264 -> V_217 ;
struct V_265 * V_181 = & V_264 -> V_181 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_70 )
V_32 |= V_266 | V_80 ;
V_34 = F_116 ( V_260 , V_101 , V_262 ,
V_43 -> V_30 . V_27 ,
F_117 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_173 ,
V_217 , V_181 , V_32 ) ;
V_34 = F_116 ( V_261 , V_101 , V_263 ,
V_43 -> V_30 . V_28 ,
F_117 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_174 ,
V_181 , V_217 , V_32 ) ;
F_118 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_119 ( struct V_2 * V_4 , struct V_99 * V_102 ,
unsigned int V_101 , unsigned long V_267 )
{
struct V_212 * V_264 = & V_4 -> V_77 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_49 ( V_102 , V_101 , V_264 -> V_217 . V_182 ,
V_264 -> V_181 . V_182 ) ;
if ( V_43 -> V_16 < 0 ) {
F_63 ( V_4 , L_17 ) ;
goto V_192;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_63 ( V_4 , L_18 ) ;
goto V_192;
}
V_43 -> V_69 = 0 ;
V_43 -> V_47 . V_32 = V_267 ;
V_43 -> V_47 . V_268 = F_86 ;
F_120 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_192:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static struct V_189 *
F_121 ( struct V_258 * V_269 , struct V_99 * V_260 ,
struct V_99 * V_261 , unsigned int V_101 ,
enum V_270 V_271 , unsigned long V_267 )
{
struct V_2 * V_4 = F_87 ( V_269 , struct V_2 , V_4 ) ;
T_7 V_262 = 0 ;
T_7 V_263 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_63 ( V_4 , L_19 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_37 , V_32 ) ;
V_43 = F_119 ( V_4 , V_260 , V_101 , V_267 ) ;
if ( V_43 == NULL )
goto V_192;
if ( F_122 ( & V_260 [ V_101 - 1 ] ) == V_260 )
V_43 -> V_70 = true ;
if ( V_271 == V_79 )
V_262 = V_4 -> V_272 ;
else if ( V_271 == V_236 )
V_263 = V_4 -> V_272 ;
if ( F_3 ( V_4 ) )
V_34 = F_113 ( V_4 , V_43 , V_260 , V_261 ,
V_101 , V_262 , V_263 ) ;
else
V_34 = F_115 ( V_4 , V_43 , V_260 , V_261 ,
V_101 , V_262 , V_263 ) ;
if ( V_34 ) {
F_63 ( V_4 , L_20 ,
F_3 ( V_4 ) ? L_21 : L_22 , V_34 ) ;
goto V_192;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_133 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return & V_43 -> V_47 ;
V_192:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return NULL ;
}
bool F_123 ( struct V_258 * V_4 , void * V_194 )
{
struct V_212 * V_273 = V_194 ;
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
int V_192 ;
if ( V_194 ) {
V_192 = F_101 ( V_3 , V_273 ) ;
if ( ! V_192 )
V_3 -> V_77 = * V_273 ;
} else
V_192 = F_107 ( V_3 ) ;
if ( ! V_192 )
V_3 -> V_255 = true ;
return V_192 == 0 ;
}
static void F_124 ( struct V_2 * V_3 , int V_145 , bool V_27 )
{
bool V_274 = V_3 -> V_77 . V_274 ;
bool V_275 = V_3 -> V_77 . V_276 ;
T_2 V_277 ;
T_2 V_137 = F_73 ( V_145 ) ;
T_2 V_278 = F_105 ( V_145 ) ;
T_2 V_279 = F_97 ( V_137 ) ;
T_2 V_280 ;
struct V_281 * V_282 = & V_3 -> V_8 -> V_117 ;
V_277 = V_274 ? V_282 -> V_283 : V_282 -> V_284 ;
if ( ! V_27 && F_3 ( V_3 ) )
V_275 = false ;
V_280 = V_275 ? V_282 -> V_285 : V_282 -> V_286 ;
if ( ! V_27 )
V_279 <<= 16 ;
F_30 ( V_279 , V_3 -> V_8 -> V_9 + V_280 + V_278 * 4 ) ;
F_30 ( V_279 , V_3 -> V_8 -> V_9 + V_277 + V_278 * 4 ) ;
}
static void F_125 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_287 < 3 )
return;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_146 ) )
F_124 ( V_3 , V_3 -> V_77 . V_145 , true ) ;
if ( ( V_3 -> V_77 . V_78 == V_236 ) ||
( V_3 -> V_77 . V_78 == V_146 ) )
F_124 ( V_3 , V_3 -> V_77 . V_145 , false ) ;
}
static struct V_258 * F_126 ( struct V_288 * V_289 ,
struct V_290 * V_291 )
{
struct V_212 V_264 ;
T_6 V_243 ;
T_2 V_32 ;
memset ( & V_264 , 0 , sizeof( struct V_212 ) ) ;
F_127 ( V_243 ) ;
F_128 ( V_246 , V_243 ) ;
V_264 . V_145 = V_289 -> args [ 0 ] ;
V_32 = V_289 -> args [ 2 ] ;
switch ( F_129 ( V_32 ) ) {
case 0 : V_264 . V_214 = V_215 ; break;
case 1 : V_264 . V_214 = V_292 ; break;
}
switch ( F_130 ( V_32 ) ) {
case 0 :
V_264 . V_78 = V_236 ;
V_264 . V_181 . V_293 = F_131 ( V_32 ) ;
break;
case 1 :
V_264 . V_78 = V_79 ;
V_264 . V_217 . V_293 = F_131 ( V_32 ) ;
break;
}
if ( F_132 ( V_32 ) ) {
V_264 . V_239 = V_289 -> args [ 1 ] ;
V_264 . V_238 = true ;
}
return F_133 ( V_243 , F_123 , & V_264 ) ;
}
static int F_134 ( struct V_258 * V_4 )
{
int V_192 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
bool V_294 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_135 ( V_4 ) ;
if ( ! V_3 -> V_255 ) {
V_192 = F_107 ( V_3 ) ;
if ( V_192 ) {
F_63 ( V_3 , L_23 ) ;
goto V_295;
}
}
V_192 = F_104 ( V_3 , & V_294 ) ;
if ( V_192 ) {
F_63 ( V_3 , L_24 ) ;
V_3 -> V_255 = false ;
goto V_295;
}
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_125 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
if ( V_3 -> V_77 . V_78 == V_79 )
V_3 -> V_81 = V_3 -> V_8 -> V_296 +
V_3 -> V_77 . V_145 * V_297 ;
else
V_3 -> V_81 = V_3 -> V_8 -> V_296 +
V_3 -> V_77 . V_145 *
V_297 + V_298 ;
V_3 -> V_173 |= F_97 ( V_299 ) ;
V_3 -> V_174 |= F_97 ( V_299 ) ;
}
F_69 ( F_1 ( V_3 ) , L_25 ,
F_3 ( V_3 ) ? L_26 : L_27 ,
V_3 -> V_11 -> V_12 ,
V_3 -> V_77 . V_238 ? L_28 : L_29 ) ;
if ( V_294 )
F_78 ( V_3 ) ;
V_295:
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_192 ;
}
static void F_136 ( struct V_258 * V_4 )
{
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
int V_192 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_30 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_192 = F_110 ( V_3 ) ;
if ( V_192 )
F_63 ( V_3 , L_31 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static struct V_189 * F_137 ( struct V_258 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_267 )
{
struct V_99 V_300 ;
struct V_99 V_301 ;
F_138 ( & V_300 , 1 ) ;
F_138 ( & V_301 , 1 ) ;
F_139 ( & V_300 ) = V_28 ;
F_139 ( & V_301 ) = V_27 ;
F_51 ( & V_300 ) = V_23 ;
F_51 ( & V_301 ) = V_23 ;
return F_121 ( V_4 , & V_301 , & V_300 , 1 , V_302 , V_267 ) ;
}
static struct V_189 *
F_140 ( struct V_258 * V_4 ,
struct V_99 * V_300 , unsigned int V_303 ,
struct V_99 * V_301 , unsigned int V_304 ,
unsigned long V_267 )
{
if ( V_303 != V_304 )
return NULL ;
return F_121 ( V_4 , V_301 , V_300 , V_304 , V_302 , V_267 ) ;
}
static struct V_189 *
F_141 ( struct V_258 * V_4 , struct V_99 * V_100 ,
unsigned int V_101 , enum V_270 V_271 ,
unsigned long V_267 , void * V_305 )
{
if ( ! F_142 ( V_271 ) )
return NULL ;
return F_121 ( V_4 , V_100 , V_100 , V_101 , V_271 , V_267 ) ;
}
static struct V_189 *
F_143 ( struct V_258 * V_4 , T_7 V_29 ,
T_8 V_306 , T_8 V_307 ,
enum V_270 V_271 , unsigned long V_32 ,
void * V_305 )
{
unsigned int V_308 = V_306 / V_307 ;
struct V_189 * V_47 ;
struct V_99 * V_102 ;
int V_33 ;
V_102 = F_144 ( V_308 + 1 , sizeof( struct V_99 ) , V_24 ) ;
if ( ! V_102 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_308 ; V_33 ++ ) {
F_139 ( & V_102 [ V_33 ] ) = V_29 ;
F_51 ( & V_102 [ V_33 ] ) = V_307 ;
V_29 += V_307 ;
}
V_102 [ V_308 ] . V_206 = 0 ;
F_51 ( & V_102 [ V_308 ] ) = 0 ;
V_102 [ V_308 ] . V_309 =
( ( unsigned long ) V_102 | 0x01 ) & ~ 0x02 ;
V_47 = F_121 ( V_4 , V_102 , V_102 , V_308 , V_271 ,
V_197 ) ;
F_10 ( V_102 ) ;
return V_47 ;
}
static enum V_310 F_145 ( struct V_258 * V_4 ,
T_3 V_191 ,
struct V_311 * V_312 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
enum V_310 V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_32 ) ;
return - V_35 ;
}
V_34 = F_146 ( V_4 , V_191 , V_312 ) ;
if ( V_34 != V_313 )
F_147 ( V_312 , F_112 ( V_4 ) ) ;
if ( F_111 ( V_3 ) )
V_34 = V_314 ;
return V_34 ;
}
static void F_148 ( struct V_258 * V_4 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_33 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_149 ( & V_3 -> V_87 , & V_3 -> V_88 ) ;
if ( ! V_3 -> V_188 )
( void ) F_90 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static void F_150 ( struct V_258 * V_4 )
{
unsigned long V_32 ;
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
int V_34 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
V_34 = F_76 ( V_3 , V_125 ) ;
if ( V_34 )
F_63 ( V_3 , L_34 ) ;
F_65 ( V_3 ) ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
if ( V_3 -> V_188 ) {
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_188 = false ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static int
F_151 ( struct V_2 * V_3 ,
struct V_265 * V_273 ,
T_2 V_315 )
{
int V_89 ;
if ( F_3 ( V_3 ) ) {
if ( V_315 >= 16 )
V_89 = V_316 ;
else if ( V_315 >= 8 )
V_89 = V_317 ;
else if ( V_315 >= 4 )
V_89 = V_318 ;
else
V_89 = V_90 ;
} else {
if ( V_315 >= 16 )
V_89 = V_319 ;
else if ( V_315 >= 8 )
V_89 = V_320 ;
else if ( V_315 >= 4 )
V_89 = V_321 ;
else
V_89 = V_91 ;
}
V_273 -> V_89 = V_89 ;
V_273 -> V_322 = V_323 ;
return 0 ;
}
static int F_152 ( struct V_258 * V_4 ,
struct V_324 * V_325 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
struct V_212 * V_264 = & V_3 -> V_77 ;
enum V_326 V_327 , V_328 ;
T_7 V_329 ;
T_2 V_330 , V_331 ;
int V_34 ;
V_327 = V_325 -> V_327 ;
V_330 = V_325 -> V_330 ;
V_328 = V_325 -> V_328 ;
V_331 = V_325 -> V_331 ;
if ( V_325 -> V_271 == V_79 ) {
V_329 = V_325 -> V_332 ;
if ( V_264 -> V_78 != V_79 )
F_69 ( V_3 -> V_8 -> V_5 ,
L_35
L_36 ,
V_264 -> V_78 ) ;
V_264 -> V_78 = V_79 ;
if ( V_328 == V_333 )
V_328 = V_327 ;
if ( V_331 == 0 )
V_331 = V_330 ;
} else if ( V_325 -> V_271 == V_236 ) {
V_329 = V_325 -> V_334 ;
if ( V_264 -> V_78 != V_236 )
F_69 ( V_3 -> V_8 -> V_5 ,
L_37
L_38 ,
V_264 -> V_78 ) ;
V_264 -> V_78 = V_236 ;
if ( V_327 == V_333 )
V_327 = V_328 ;
if ( V_330 == 0 )
V_330 = V_331 ;
} else {
F_106 ( V_3 -> V_8 -> V_5 ,
L_39 ,
V_325 -> V_271 ) ;
return - V_35 ;
}
if ( V_329 <= 0 ) {
F_106 ( V_3 -> V_8 -> V_5 , L_40 ) ;
return - V_35 ;
}
if ( V_330 * V_327 != V_331 * V_328 ) {
F_106 ( V_3 -> V_8 -> V_5 ,
L_41 ,
V_330 ,
V_327 ,
V_331 ,
V_328 ) ;
return - V_35 ;
}
if ( V_330 > 16 ) {
V_330 = 16 ;
V_331 = V_330 * V_327 / V_328 ;
} else if ( V_331 > 16 ) {
V_331 = 16 ;
V_330 = V_331 * V_328 / V_327 ;
}
if ( V_327 <= V_333 ||
V_327 > V_335 ||
V_328 <= V_333 ||
V_328 > V_335 ||
! F_153 ( V_327 ) ||
! F_153 ( V_328 ) )
return - V_35 ;
V_264 -> V_217 . V_182 = V_327 ;
V_264 -> V_181 . V_182 = V_328 ;
V_34 = F_151 ( V_3 , & V_264 -> V_217 ,
V_330 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_151 ( V_3 , & V_264 -> V_181 ,
V_331 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_109 ( V_264 , & V_3 -> V_250 . V_251 , & V_3 -> V_250 . V_184 ) ;
else
F_154 ( V_264 , & V_3 -> V_173 , & V_3 -> V_174 ) ;
V_3 -> V_272 = V_329 ;
V_3 -> V_336 = V_325 -> V_271 ;
F_69 ( V_3 -> V_8 -> V_5 ,
L_42
L_43 ,
F_155 ( V_4 ) ,
( V_325 -> V_271 == V_79 ) ? L_44 : L_45 ,
V_327 , V_328 ,
V_330 , V_331 ) ;
return 0 ;
}
static int F_156 ( struct V_258 * V_4 , enum V_337 V_338 ,
unsigned long V_339 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_33 ) ;
return - V_35 ;
}
switch ( V_338 ) {
case V_340 :
F_150 ( V_4 ) ;
return 0 ;
case V_341 :
return F_81 ( V_3 ) ;
case V_342 :
return F_85 ( V_3 ) ;
case V_343 :
return F_152 ( V_4 ,
(struct V_324 * ) V_339 ) ;
default:
break;
}
return - V_344 ;
}
static void T_9 F_157 ( struct V_109 * V_8 , struct V_345 * V_346 ,
struct V_2 * V_347 , int V_206 ,
int V_348 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_346 -> V_349 ) ;
for ( V_33 = V_206 ; V_33 < V_206 + V_348 ; V_33 ++ ) {
V_3 = & V_347 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_346 ;
F_158 ( & V_3 -> V_37 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_64 ) ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_88 ) ;
F_24 ( & V_3 -> V_87 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_133 ) ;
F_159 ( & V_3 -> V_193 , F_93 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_350 ,
& V_346 -> V_349 ) ;
}
}
static void F_160 ( struct V_109 * V_8 , struct V_345 * V_5 )
{
if ( F_108 ( V_246 , V_5 -> V_244 ) )
V_5 -> V_351 = F_141 ;
if ( F_108 ( V_245 , V_5 -> V_244 ) ) {
V_5 -> V_352 = F_137 ;
V_5 -> V_353 = 2 ;
}
if ( F_108 ( V_354 , V_5 -> V_244 ) )
V_5 -> V_355 = F_140 ;
if ( F_108 ( V_356 , V_5 -> V_244 ) )
V_5 -> V_357 = F_143 ;
V_5 -> V_358 = F_134 ;
V_5 -> V_359 = F_136 ;
V_5 -> V_360 = F_148 ;
V_5 -> V_361 = F_145 ;
V_5 -> V_362 = F_156 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_161 ( struct V_109 * V_8 ,
int V_363 )
{
int V_192 ;
F_157 ( V_8 , & V_8 -> V_364 , V_8 -> V_365 ,
0 , V_8 -> V_216 ) ;
F_127 ( V_8 -> V_364 . V_244 ) ;
F_128 ( V_246 , V_8 -> V_364 . V_244 ) ;
F_128 ( V_356 , V_8 -> V_364 . V_244 ) ;
F_160 ( V_8 , & V_8 -> V_364 ) ;
V_192 = F_162 ( & V_8 -> V_364 ) ;
if ( V_192 ) {
F_99 ( V_8 -> V_5 , L_46 ) ;
goto V_366;
}
F_157 ( V_8 , & V_8 -> V_367 , V_8 -> V_365 ,
V_8 -> V_216 , V_8 -> V_368 ) ;
F_127 ( V_8 -> V_367 . V_244 ) ;
F_128 ( V_245 , V_8 -> V_367 . V_244 ) ;
F_128 ( V_354 , V_8 -> V_367 . V_244 ) ;
F_160 ( V_8 , & V_8 -> V_367 ) ;
V_192 = F_162 ( & V_8 -> V_367 ) ;
if ( V_192 ) {
F_99 ( V_8 -> V_5 ,
L_47 ) ;
goto V_369;
}
F_157 ( V_8 , & V_8 -> V_370 , V_8 -> V_371 ,
0 , V_363 ) ;
F_127 ( V_8 -> V_370 . V_244 ) ;
F_128 ( V_246 , V_8 -> V_370 . V_244 ) ;
F_128 ( V_245 , V_8 -> V_370 . V_244 ) ;
F_128 ( V_354 , V_8 -> V_370 . V_244 ) ;
F_128 ( V_356 , V_8 -> V_364 . V_244 ) ;
F_160 ( V_8 , & V_8 -> V_370 ) ;
V_192 = F_162 ( & V_8 -> V_370 ) ;
if ( V_192 ) {
F_99 ( V_8 -> V_5 ,
L_48 ) ;
goto V_372;
}
return 0 ;
V_372:
F_163 ( & V_8 -> V_367 ) ;
V_369:
F_163 ( & V_8 -> V_364 ) ;
V_366:
return V_192 ;
}
static int F_164 ( struct V_1 * V_5 )
{
struct V_373 * V_374 = F_165 ( V_5 ) ;
struct V_109 * V_8 = F_166 ( V_374 ) ;
int V_34 = 0 ;
if ( V_8 -> V_375 )
V_34 = F_167 ( V_8 -> V_375 ) ;
return V_34 ;
}
static int F_168 ( struct V_1 * V_5 )
{
struct V_373 * V_374 = F_165 ( V_5 ) ;
struct V_109 * V_8 = F_166 ( V_374 ) ;
F_55 ( V_8 , true ) ;
if ( V_8 -> V_287 != 1 )
F_54 ( V_8 -> V_376 ,
V_8 -> V_9 + V_377 ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_5 )
{
struct V_373 * V_374 = F_165 ( V_5 ) ;
struct V_109 * V_8 = F_166 ( V_374 ) ;
if ( V_8 -> V_378 )
F_55 ( V_8 , false ) ;
F_54 ( V_379 ,
V_8 -> V_9 + V_377 ) ;
return 0 ;
}
static int F_170 ( struct V_1 * V_5 )
{
struct V_373 * V_374 = F_165 ( V_5 ) ;
struct V_109 * V_8 = F_166 ( V_374 ) ;
int V_34 = 0 ;
if ( V_8 -> V_375 )
V_34 = F_171 ( V_8 -> V_375 ) ;
return V_34 ;
}
static int T_9 F_172 ( struct V_109 * V_8 )
{
int V_33 ;
int V_380 = 0 ;
T_2 V_148 [ 2 ] ;
int V_381 = - 2 ;
int V_382 = V_383 ;
V_148 [ 0 ] = F_58 ( V_8 -> V_9 + V_384 ) ;
V_148 [ 1 ] = F_58 ( V_8 -> V_9 + V_385 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
V_8 -> V_111 [ V_33 ] . V_12 = V_33 ;
V_381 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_148 [ V_33 % 2 ] >> V_381 ) & 3 ) == 1 ) {
V_8 -> V_111 [ V_33 ] . V_223 = V_226 ;
V_8 -> V_111 [ V_33 ] . V_224 = V_226 ;
V_8 -> V_111 [ V_33 ] . V_112 = true ;
V_382 |= F_173 ( F_174 ( V_33 ) ,
V_386 ) ;
V_382 |= F_173 ( F_174 ( V_33 ) ,
V_387 ) ;
} else {
V_8 -> V_111 [ V_33 ] . V_223 = V_225 ;
V_8 -> V_111 [ V_33 ] . V_224 = V_225 ;
V_8 -> V_111 [ V_33 ] . V_112 = false ;
V_380 ++ ;
}
F_158 ( & V_8 -> V_111 [ V_33 ] . V_37 ) ;
}
for ( V_33 = 0 ; V_8 -> V_74 -> V_388 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_388 [ V_33 ] ;
V_8 -> V_111 [ V_4 ] . V_223 = V_226 ;
V_8 -> V_111 [ V_4 ] . V_224 = V_226 ;
V_8 -> V_111 [ V_4 ] . V_112 = true ;
V_382 |= F_173 ( F_174 ( V_4 ) ,
V_386 ) ;
V_382 |= F_173 ( F_174 ( V_4 ) ,
V_387 ) ;
V_380 -- ;
}
for ( V_33 = 0 ; V_33 < V_8 -> V_74 -> V_389 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_390 [ V_33 ] ;
V_8 -> V_111 [ V_4 ] . V_76 = true ;
}
F_175 ( V_8 -> V_5 , L_49 ,
V_380 , V_8 -> V_110 ) ;
V_148 [ 0 ] = F_58 ( V_8 -> V_9 + V_391 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
if ( V_8 -> V_111 [ V_33 ] . V_223 == V_225 &&
( V_148 [ 0 ] & 0x3 ) != 1 )
F_175 ( V_8 -> V_5 ,
L_50 ,
V_143 , V_33 , V_148 [ 0 ] & 0x3 ) ;
V_148 [ 0 ] = V_148 [ 0 ] >> 2 ;
}
F_30 ( V_379 , V_8 -> V_9 + V_377 ) ;
V_8 -> V_376 = V_382 ;
return V_380 ;
}
static struct V_109 * T_9 F_176 ( struct V_373 * V_374 )
{
struct V_392 * V_74 = F_177 ( & V_374 -> V_5 ) ;
struct V_393 * V_393 = NULL ;
void T_1 * V_9 = NULL ;
struct V_394 * V_187 = NULL ;
struct V_109 * V_8 = NULL ;
int V_216 = 0 ;
int V_110 ;
int V_368 ;
int V_395 = - V_35 ;
int V_33 ;
T_2 V_396 ;
T_2 V_397 ;
T_10 V_287 ;
V_393 = F_178 ( & V_374 -> V_5 , NULL ) ;
if ( F_179 ( V_393 ) ) {
F_99 ( & V_374 -> V_5 , L_51 ) ;
goto V_398;
}
V_395 = F_180 ( V_393 ) ;
if ( V_395 ) {
F_99 ( & V_374 -> V_5 , L_52 ) ;
goto V_398;
}
V_187 = F_181 ( V_374 , V_399 , L_53 ) ;
if ( ! V_187 )
goto V_398;
if ( F_182 ( V_187 -> V_400 , F_183 ( V_187 ) ,
V_401 L_54 ) == NULL )
goto V_398;
V_9 = F_184 ( V_187 -> V_400 , F_183 ( V_187 ) ) ;
if ( ! V_9 )
goto V_398;
for ( V_396 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_396 |= ( F_58 ( V_9 + F_183 ( V_187 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_397 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_397 |= ( F_58 ( V_9 + F_183 ( V_187 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_397 != V_402 ) {
F_99 ( & V_374 -> V_5 , L_55 ) ;
goto V_398;
}
if ( F_185 ( V_396 ) != V_403 ) {
F_99 ( & V_374 -> V_5 , L_56 ,
F_185 ( V_396 ) ,
V_403 ) ;
goto V_398;
}
V_287 = F_186 ( V_396 ) ;
if ( V_287 < 2 ) {
F_99 ( & V_374 -> V_5 , L_57 , V_287 ) ;
goto V_398;
}
if ( V_74 -> V_404 )
V_110 = V_74 -> V_404 ;
else
V_110 = 4 * ( F_58 ( V_9 + V_405 ) & 0x7 ) + 4 ;
if ( V_74 -> V_406 )
V_368 = V_74 -> V_406 ;
else
V_368 = F_56 ( V_248 ) ;
V_216 = V_110 * V_407 ;
F_175 ( & V_374 -> V_5 ,
L_58 ,
V_287 , & V_187 -> V_400 , V_110 , V_216 ) ;
V_8 = F_187 ( F_47 ( sizeof( struct V_109 ) , 4 ) +
( V_110 + V_216 + V_368 ) *
sizeof( struct V_2 ) , V_408 ) ;
if ( V_8 == NULL ) {
F_99 ( & V_374 -> V_5 , L_59 ) ;
goto V_398;
}
V_8 -> V_287 = V_287 ;
V_8 -> V_393 = V_393 ;
V_8 -> V_368 = V_368 ;
V_8 -> V_110 = V_110 ;
V_8 -> V_216 = V_216 ;
V_8 -> V_409 = V_187 -> V_400 ;
V_8 -> V_410 = F_183 ( V_187 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_5 = & V_374 -> V_5 ;
V_8 -> V_371 = ( ( void * ) V_8 ) + F_47 ( sizeof( struct V_109 ) , 4 ) ;
V_8 -> V_365 = & V_8 -> V_371 [ V_110 ] ;
if ( V_8 -> V_74 -> V_404 == 14 ) {
V_8 -> V_117 . V_105 = V_411 ;
V_8 -> V_117 . V_119 = V_412 ;
V_8 -> V_117 . V_413 = V_414 ;
V_8 -> V_117 . V_415 = V_416 ;
V_8 -> V_117 . V_283 = V_417 ;
V_8 -> V_117 . V_284 = V_418 ;
V_8 -> V_117 . V_285 = V_419 ;
V_8 -> V_117 . V_286 = V_420 ;
V_8 -> V_117 . V_203 = V_421 ;
V_8 -> V_117 . V_201 = F_56 ( V_421 ) ;
V_8 -> V_117 . V_422 = V_423 ;
V_8 -> V_117 . V_424 = F_56 ( V_423 ) ;
} else {
if ( V_8 -> V_287 >= 3 ) {
V_8 -> V_117 . V_105 = V_425 ;
V_8 -> V_117 . V_119 = V_426 ;
}
V_8 -> V_117 . V_413 = V_427 ;
V_8 -> V_117 . V_415 = V_428 ;
V_8 -> V_117 . V_283 = V_429 ;
V_8 -> V_117 . V_284 = V_430 ;
V_8 -> V_117 . V_285 = V_431 ;
V_8 -> V_117 . V_286 = V_432 ;
V_8 -> V_117 . V_203 = V_433 ;
V_8 -> V_117 . V_201 = F_56 ( V_433 ) ;
V_8 -> V_117 . V_422 = V_434 ;
V_8 -> V_117 . V_424 = F_56 ( V_434 ) ;
}
V_8 -> V_111 = F_187 ( V_110 * sizeof( struct V_218 ) ,
V_408 ) ;
if ( ! V_8 -> V_111 )
goto V_398;
V_8 -> V_207 = F_187 ( V_110 *
sizeof( struct V_2 * ) ,
V_408 ) ;
if ( ! V_8 -> V_207 )
goto V_398;
V_8 -> V_208 = F_187 ( V_216 *
sizeof( struct V_2 * ) ,
V_408 ) ;
if ( ! V_8 -> V_208 )
goto V_398;
V_8 -> V_114 = F_6 ( V_8 -> V_110 *
sizeof( V_113 ) ,
V_408 ) ;
if ( ! V_8 -> V_114 )
goto V_398;
V_8 -> V_36 . V_40 =
F_187 ( V_110 * sizeof( struct V_14 * )
* V_38 , V_408 ) ;
if ( ! V_8 -> V_36 . V_40 )
goto V_398;
V_8 -> V_48 = F_188 ( V_401 , sizeof( struct V_14 ) ,
0 , V_435 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_398;
return V_8 ;
V_398:
if ( ! V_395 )
F_189 ( V_393 ) ;
if ( ! F_179 ( V_393 ) )
F_190 ( V_393 ) ;
if ( V_9 )
F_191 ( V_9 ) ;
if ( V_187 )
F_192 ( V_187 -> V_400 ,
F_183 ( V_187 ) ) ;
if ( V_9 )
F_191 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_114 ) ;
F_10 ( V_8 -> V_208 ) ;
F_10 ( V_8 -> V_207 ) ;
F_10 ( V_8 -> V_111 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_193 ( struct V_109 * V_8 )
{
int V_33 ;
T_2 V_436 [ 2 ] = { 0 , 0 } ;
T_2 V_437 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_438 = 0 ;
T_2 V_439 = 0 ;
struct V_440 * V_441 = V_8 -> V_117 . V_422 ;
T_2 V_442 = V_8 -> V_117 . V_424 ;
for ( V_33 = 0 ; V_33 < V_442 ; V_33 ++ )
F_30 ( V_441 [ V_33 ] . V_148 ,
V_8 -> V_9 + V_441 [ V_33 ] . V_138 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
V_437 [ V_33 % 2 ] = V_437 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_111 [ V_8 -> V_110 - V_33 - 1 ] . V_223
== V_226 ) {
V_437 [ V_33 % 2 ] |= 3 ;
continue;
}
V_438 = ( V_438 << 1 ) | 1 ;
V_439 = ( V_439 << 1 ) | 1 ;
V_436 [ V_33 % 2 ] = V_436 [ V_33 % 2 ] << 2 ;
V_436 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_436 [ 1 ] , V_8 -> V_9 + V_168 ) ;
F_30 ( V_436 [ 0 ] , V_8 -> V_9 + V_443 ) ;
F_30 ( V_437 [ 1 ] , V_8 -> V_9 + V_128 ) ;
F_30 ( V_437 [ 0 ] , V_8 -> V_9 + V_129 ) ;
F_30 ( V_438 , V_8 -> V_9 + V_8 -> V_117 . V_413 ) ;
F_30 ( V_439 , V_8 -> V_9 + V_8 -> V_117 . V_415 ) ;
V_8 -> V_117 . V_422 = NULL ;
V_8 -> V_117 . V_424 = 0 ;
}
static int T_9 F_194 ( struct V_109 * V_8 )
{
struct V_65 * V_66 = & V_8 -> V_36 ;
unsigned long * V_444 ;
int V_33 , V_235 ;
int V_34 = 0 ;
V_444 = F_6 ( sizeof( unsigned long ) * V_445 ,
V_408 ) ;
if ( ! V_444 ) {
V_34 = - V_25 ;
goto V_398;
}
V_8 -> V_36 . V_446 = V_447 * V_8 -> V_110 / V_448 ;
for ( V_33 = 0 ; V_33 < V_445 ; V_33 ++ ) {
V_444 [ V_33 ] = F_195 ( V_408 ,
V_8 -> V_36 . V_446 ) ;
if ( ! V_444 [ V_33 ] ) {
F_99 ( V_8 -> V_5 , L_60 ,
V_8 -> V_36 . V_446 ) ;
for ( V_235 = 0 ; V_235 < V_33 ; V_235 ++ )
F_196 ( V_444 [ V_235 ] , V_8 -> V_36 . V_446 ) ;
goto V_398;
}
if ( ( F_117 ( ( void * ) V_444 [ V_33 ] ) &
( V_449 - 1 ) ) == 0 )
break;
}
for ( V_235 = 0 ; V_235 < V_33 ; V_235 ++ )
F_196 ( V_444 [ V_235 ] , V_8 -> V_36 . V_446 ) ;
if ( V_33 < V_445 ) {
V_8 -> V_36 . V_8 = ( void * ) V_444 [ V_33 ] ;
} else {
F_197 ( V_8 -> V_5 ,
L_61 ,
V_143 , V_8 -> V_36 . V_446 ) ;
V_8 -> V_36 . V_450 = F_6 ( V_447 *
V_8 -> V_110 +
V_449 ,
V_408 ) ;
if ( ! V_8 -> V_36 . V_450 ) {
V_34 = - V_25 ;
goto V_398;
}
V_8 -> V_36 . V_8 = F_7 ( V_8 -> V_36 . V_450 ,
V_449 ) ;
}
V_66 -> V_29 = F_8 ( V_8 -> V_5 , V_66 -> V_8 ,
V_447 * V_8 -> V_110 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_66 -> V_29 ) ) {
V_66 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_398;
}
F_30 ( F_117 ( V_8 -> V_36 . V_8 ) ,
V_8 -> V_9 + V_451 ) ;
V_398:
F_10 ( V_444 ) ;
return V_34 ;
}
static int T_9 F_198 ( struct V_373 * V_374 ,
struct V_350 * V_452 )
{
struct V_392 * V_453 ;
int V_454 = 0 , V_455 = 0 , V_456 = 0 ;
const T_11 * V_457 ;
V_453 = F_199 ( & V_374 -> V_5 ,
sizeof( struct V_392 ) ,
V_408 ) ;
if ( ! V_453 )
return - V_25 ;
F_200 ( V_452 , L_62 , & V_454 ) ;
if ( V_454 > 0 )
V_453 -> V_404 = V_454 ;
V_457 = F_201 ( V_452 , L_63 , & V_455 ) ;
V_455 /= sizeof( * V_457 ) ;
if ( V_455 > V_458 || V_455 <= 0 ) {
F_99 ( & V_374 -> V_5 ,
L_64 ,
V_455 ) ;
return - V_35 ;
}
V_453 -> V_406 = V_455 ;
F_202 ( V_452 , L_63 ,
V_248 ,
V_455 ) ;
V_457 = F_201 ( V_452 , L_65 , & V_456 ) ;
V_456 /= sizeof( * V_457 ) ;
if ( V_456 >= V_459 || V_456 < 0 ) {
F_99 ( & V_374 -> V_5 ,
L_66 ,
V_456 ) ;
return - V_35 ;
}
F_202 ( V_452 , L_65 ,
V_453 -> V_388 ,
V_456 ) ;
V_453 -> V_388 [ V_456 ] = - 1 ;
V_374 -> V_5 . V_460 = V_453 ;
return 0 ;
}
static int T_9 F_203 ( struct V_373 * V_374 )
{
struct V_392 * V_74 = F_177 ( & V_374 -> V_5 ) ;
struct V_350 * V_452 = V_374 -> V_5 . V_461 ;
int V_34 = - V_462 ;
struct V_109 * V_8 = NULL ;
struct V_394 * V_187 = NULL ;
int V_363 ;
T_2 V_148 ;
if ( ! V_74 ) {
if ( V_452 ) {
if( F_198 ( V_374 , V_452 ) ) {
V_34 = - V_25 ;
goto V_398;
}
} else {
F_99 ( & V_374 -> V_5 , L_67 ) ;
goto V_398;
}
}
V_8 = F_176 ( V_374 ) ;
if ( ! V_8 )
goto V_398;
V_363 = F_172 ( V_8 ) ;
F_204 ( V_374 , V_8 ) ;
F_158 ( & V_8 -> V_204 ) ;
F_158 ( & V_8 -> V_127 ) ;
V_187 = F_181 ( V_374 , V_399 , L_68 ) ;
if ( ! V_187 ) {
V_34 = - V_462 ;
F_99 ( & V_374 -> V_5 , L_69 ) ;
goto V_398;
}
V_8 -> V_463 = F_183 ( V_187 ) ;
V_8 -> V_464 = V_187 -> V_400 ;
if ( F_182 ( V_187 -> V_400 , F_183 ( V_187 ) ,
V_401 L_70 ) == NULL ) {
V_34 = - V_132 ;
F_99 ( & V_374 -> V_5 , L_71 , V_187 ) ;
goto V_398;
}
V_148 = F_58 ( V_8 -> V_9 + V_465 ) ;
if ( V_187 -> V_400 != V_148 && V_148 != 0 ) {
F_197 ( & V_374 -> V_5 ,
L_72 ,
V_143 , V_148 , & V_187 -> V_400 ) ;
} else
F_30 ( V_187 -> V_400 , V_8 -> V_9 + V_465 ) ;
V_8 -> V_296 = F_184 ( V_187 -> V_400 , F_183 ( V_187 ) ) ;
if ( ! V_8 -> V_296 ) {
V_34 = - V_25 ;
F_99 ( & V_374 -> V_5 , L_73 ) ;
goto V_398;
}
if ( V_8 -> V_74 -> V_73 ) {
V_187 = F_181 ( V_374 , V_399 ,
L_74 ) ;
if ( ! V_187 ) {
V_34 = - V_462 ;
F_99 ( & V_374 -> V_5 ,
L_75 ) ;
goto V_398;
}
V_8 -> V_36 . V_8 = F_184 ( V_187 -> V_400 ,
F_183 ( V_187 ) ) ;
if ( ! V_8 -> V_36 . V_8 ) {
V_34 = - V_25 ;
F_99 ( & V_374 -> V_5 , L_76 ) ;
goto V_398;
}
F_30 ( V_187 -> V_400 , V_8 -> V_9 + V_451 ) ;
} else {
V_34 = F_194 ( V_8 ) ;
if ( V_34 ) {
F_99 ( & V_374 -> V_5 , L_77 ) ;
goto V_398;
}
}
F_158 ( & V_8 -> V_36 . V_37 ) ;
V_8 -> V_198 = F_205 ( V_374 , 0 ) ;
V_34 = F_206 ( V_8 -> V_198 , F_95 , 0 , V_401 , V_8 ) ;
if ( V_34 ) {
F_99 ( & V_374 -> V_5 , L_78 ) ;
goto V_398;
}
F_207 ( V_8 -> V_5 ) ;
F_208 ( V_8 -> V_5 , V_466 ) ;
F_209 ( V_8 -> V_5 ) ;
F_210 ( V_8 -> V_5 ) ;
F_211 ( V_8 -> V_5 ) ;
if ( V_8 -> V_74 -> V_73 ) {
V_8 -> V_375 = F_212 ( V_8 -> V_5 , L_74 ) ;
if ( F_179 ( V_8 -> V_375 ) ) {
F_99 ( & V_374 -> V_5 , L_79 ) ;
V_34 = F_213 ( V_8 -> V_375 ) ;
V_8 -> V_375 = NULL ;
goto V_398;
}
V_34 = F_171 ( V_8 -> V_375 ) ;
if ( V_34 ) {
F_99 ( & V_374 -> V_5 ,
L_80 ) ;
F_214 ( V_8 -> V_375 ) ;
V_8 -> V_375 = NULL ;
goto V_398;
}
}
V_8 -> V_378 = true ;
V_34 = F_161 ( V_8 , V_363 ) ;
if ( V_34 )
goto V_398;
V_8 -> V_5 -> V_467 = & V_8 -> V_467 ;
V_34 = F_215 ( V_8 -> V_5 , V_98 ) ;
if ( V_34 ) {
F_99 ( & V_374 -> V_5 , L_81 ) ;
goto V_398;
}
F_193 ( V_8 ) ;
if ( V_452 ) {
V_34 = F_216 ( V_452 , F_126 , NULL ) ;
if ( V_34 )
F_106 ( & V_374 -> V_5 ,
L_82 ) ;
}
F_175 ( V_8 -> V_5 , L_83 ) ;
return 0 ;
V_398:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_217 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_191 ( V_8 -> V_9 ) ;
if ( V_8 -> V_36 . V_8 && V_8 -> V_74 -> V_73 ) {
F_191 ( V_8 -> V_36 . V_8 ) ;
V_8 -> V_36 . V_8 = NULL ;
}
if ( V_8 -> V_36 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_36 . V_29 ,
V_447 * V_8 -> V_110 ,
V_31 ) ;
if ( ! V_8 -> V_36 . V_450 && V_8 -> V_36 . V_8 )
F_196 ( ( unsigned long ) V_8 -> V_36 . V_8 ,
V_8 -> V_36 . V_446 ) ;
F_10 ( V_8 -> V_36 . V_450 ) ;
if ( V_8 -> V_464 )
F_192 ( V_8 -> V_464 ,
V_8 -> V_463 ) ;
if ( V_8 -> V_409 )
F_192 ( V_8 -> V_409 ,
V_8 -> V_410 ) ;
if ( V_8 -> V_393 ) {
F_189 ( V_8 -> V_393 ) ;
F_190 ( V_8 -> V_393 ) ;
}
if ( V_8 -> V_375 ) {
F_167 ( V_8 -> V_375 ) ;
F_214 ( V_8 -> V_375 ) ;
}
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_208 ) ;
F_10 ( V_8 -> V_207 ) ;
F_10 ( V_8 -> V_111 ) ;
F_10 ( V_8 ) ;
}
F_99 ( & V_374 -> V_5 , L_84 ) ;
return V_34 ;
}
static int T_9 F_218 ( void )
{
return F_219 ( & V_468 , F_203 ) ;
}
