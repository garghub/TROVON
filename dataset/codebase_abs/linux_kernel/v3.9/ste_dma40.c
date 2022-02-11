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
T_2 V_97 = F_47 ( V_98 << V_96 , 1 << V_95 ) ;
if ( V_97 > V_98 )
V_97 -= ( 1 << V_95 ) ;
if ( ! F_48 ( V_23 , 1 << V_95 ) )
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
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_145 ) ) {
T_2 V_137 = F_73 ( V_3 -> V_77 . V_146 ) ;
F_66 ( V_3 , V_136 , V_137 ,
V_59 ) ;
}
if ( V_3 -> V_77 . V_78 != V_79 ) {
T_2 V_137 = F_73 ( V_3 -> V_77 . V_147 ) ;
F_66 ( V_3 , V_136 , V_137 ,
V_63 ) ;
}
}
static T_2 F_74 ( struct V_2 * V_3 )
{
void T_1 * V_148 = F_4 ( V_3 ) ;
T_2 V_149 ;
V_149 = F_58 ( V_148 + V_59 ) ;
V_149 |= F_58 ( V_148 + V_63 ) ;
return V_149 ;
}
static int
F_75 ( struct V_2 * V_3 , enum V_120 V_121 )
{
unsigned long V_32 ;
int V_34 = 0 ;
T_2 V_150 ;
void T_1 * V_123 ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_123 = V_3 -> V_8 -> V_9 + V_128 ;
else
V_123 = V_3 -> V_8 -> V_9 + V_129 ;
F_14 ( & V_3 -> V_11 -> V_37 , V_32 ) ;
switch ( V_121 ) {
case V_125 :
case V_126 :
V_150 = ( F_58 ( V_123 ) &
F_59 ( V_3 -> V_11 -> V_12 ) ) >>
F_60 ( V_3 -> V_11 -> V_12 ) ;
if ( V_150 == V_151 )
F_72 ( V_3 , V_141 ) ;
else
F_72 ( V_3 , V_140 ) ;
if ( ! F_74 ( V_3 ) && ( V_121 == V_125 ) )
V_34 = F_57 ( V_3 , V_121 ) ;
break;
case V_151 :
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
return V_152 [ V_3 -> V_77 . V_166 ] ;
else
return V_159 [ V_3 -> V_77 . V_166 ] ;
}
static void F_78 ( struct V_2 * V_3 )
{
T_2 V_167 ;
T_2 V_168 ;
V_167 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_168 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_60 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_168 , V_3 -> V_8 -> V_9 + V_169 + V_167 ) ;
V_168 = F_77 ( V_3 ) << F_60 ( V_3 -> V_11 -> V_12 ) ;
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
static T_2 F_79 ( struct V_2 * V_3 )
{
T_2 V_176 ;
if ( F_3 ( V_3 ) )
V_176 = ( F_58 ( & V_3 -> V_81 -> V_177 ) & V_178 )
>> V_179 ;
else {
T_2 V_149 = F_58 ( F_4 ( V_3 ) + V_61 ) ;
V_176 = ( V_149 & V_180 )
>> V_181 ;
}
return V_176 * ( 1 << V_3 -> V_77 . V_182 . V_183 ) ;
}
static bool F_80 ( struct V_2 * V_3 )
{
bool V_184 ;
if ( F_3 ( V_3 ) )
V_184 = F_58 ( & V_3 -> V_81 -> V_185 ) & V_186 ;
else
V_184 = F_58 ( F_4 ( V_3 ) + V_63 )
& V_187 ;
return V_184 ;
}
static int F_81 ( struct V_2 * V_3 )
{
int V_188 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_189 )
return 0 ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_188 = F_76 ( V_3 , V_126 ) ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_188 ;
}
static int F_85 ( struct V_2 * V_3 )
{
int V_188 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_189 )
return 0 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
if ( F_79 ( V_3 ) || F_80 ( V_3 ) )
V_188 = F_76 ( V_3 , V_151 ) ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_188 ;
}
static T_3 F_86 ( struct V_190 * V_191 )
{
struct V_2 * V_3 = F_87 ( V_191 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_87 ( V_191 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
T_3 V_192 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_192 = F_88 ( V_191 ) ;
F_39 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_192 ;
}
static int F_89 ( struct V_2 * V_3 )
{
return F_76 ( V_3 , V_151 ) ;
}
static struct V_14 * F_90 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_193 ;
V_15 = F_41 ( V_3 ) ;
if ( V_15 != NULL ) {
if ( ! V_3 -> V_189 ) {
V_3 -> V_189 = true ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_36 ( V_3 , V_15 ) ;
V_193 = F_89 ( V_3 ) ;
if ( V_193 )
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
if ( F_90 ( V_3 ) == NULL )
V_3 -> V_189 = false ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_17 ( V_15 ) ;
F_31 ( V_3 , V_15 ) ;
}
V_3 -> V_134 ++ ;
F_92 ( & V_3 -> V_194 ) ;
}
static void F_93 ( unsigned long V_195 )
{
struct V_2 * V_3 = (struct V_2 * ) V_195 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
T_4 V_196 ;
void * V_197 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_15 = F_42 ( V_3 ) ;
if ( V_15 == NULL ) {
V_15 = F_37 ( V_3 ) ;
if ( V_15 == NULL || ! V_15 -> V_70 )
goto V_193;
}
if ( ! V_15 -> V_70 )
F_94 ( & V_15 -> V_47 ) ;
if ( V_3 -> V_134 == 0 ) {
F_15 ( & V_3 -> V_37 , V_32 ) ;
return;
}
V_196 = V_15 -> V_47 . V_196 ;
V_197 = V_15 -> V_47 . V_197 ;
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
F_92 ( & V_3 -> V_194 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
if ( V_196 && ( V_15 -> V_47 . V_32 & V_198 ) )
V_196 ( V_197 ) ;
return;
V_193:
if ( V_3 -> V_134 > 0 )
V_3 -> V_134 -- ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static T_5 F_95 ( int V_199 , void * V_195 )
{
int V_33 ;
T_2 V_39 ;
T_2 V_200 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_109 * V_8 = V_195 ;
T_2 V_201 [ V_8 -> V_117 . V_202 ] ;
struct V_203 * V_204 = V_8 -> V_117 . V_204 ;
T_2 V_202 = V_8 -> V_117 . V_202 ;
F_14 ( & V_8 -> V_205 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_202 ; V_33 ++ )
V_201 [ V_33 ] = F_58 ( V_8 -> V_9 + V_204 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_96 ( ( unsigned long * ) V_201 ,
V_206 * V_202 , V_4 + 1 ) ;
if ( V_4 == V_206 * V_202 )
break;
V_200 = V_4 / V_206 ;
V_39 = V_4 & ( V_206 - 1 ) ;
if ( V_204 [ V_200 ] . V_207 == V_7 )
V_3 = V_8 -> V_208 [ V_39 ] ;
else
V_3 = V_8 -> V_209 [ V_204 [ V_200 ] . V_207 + V_39 ] ;
if ( ! V_3 ) {
continue;
}
F_30 ( 1 << V_39 , V_8 -> V_9 + V_204 [ V_200 ] . V_210 ) ;
F_97 ( & V_3 -> V_37 ) ;
if ( ! V_204 [ V_200 ] . V_211 )
F_91 ( V_3 ) ;
else
F_98 ( V_8 -> V_5 , L_5 ,
V_4 , V_204 [ V_200 ] . V_207 , V_39 ) ;
F_99 ( & V_3 -> V_37 ) ;
}
F_15 ( & V_8 -> V_205 , V_32 ) ;
return V_212 ;
}
static int F_100 ( struct V_2 * V_3 ,
struct V_213 * V_214 )
{
int V_188 = 0 ;
T_2 V_215 = F_101 ( V_214 -> V_147 ) ;
T_2 V_216 = F_101 ( V_214 -> V_146 ) ;
bool V_17 = V_214 -> V_217 == V_218 ;
if ( ! V_214 -> V_78 ) {
F_63 ( V_3 , L_6 ) ;
V_188 = - V_35 ;
}
if ( V_214 -> V_147 != V_219 &&
V_3 -> V_8 -> V_74 -> V_220 [ V_214 -> V_147 ] == 0 &&
V_3 -> V_221 == 0 ) {
F_63 ( V_3 , L_7 ,
V_214 -> V_147 ) ;
V_188 = - V_35 ;
}
if ( V_214 -> V_146 != V_222 &&
V_3 -> V_8 -> V_74 -> V_223 [ V_214 -> V_146 ] == 0 &&
V_3 -> V_221 == 0 ) {
F_63 ( V_3 , L_8 ,
V_214 -> V_146 ) ;
V_188 = - V_35 ;
}
if ( V_214 -> V_78 == V_224 &&
V_215 == V_219 ) {
F_63 ( V_3 , L_9 ) ;
V_188 = - V_35 ;
}
if ( V_214 -> V_78 == V_79 &&
V_216 == V_222 ) {
F_63 ( V_3 , L_10 ) ;
V_188 = - V_35 ;
}
if ( V_216 == V_222 &&
V_215 == V_219 && V_17 ) {
F_63 ( V_3 , L_11 ) ;
V_188 = - V_35 ;
}
if ( V_214 -> V_78 == V_145 &&
( V_216 != V_215 ) ) {
F_63 ( V_3 , L_12 ) ;
V_188 = - V_35 ;
}
if ( V_214 -> V_78 == V_145 ) {
F_63 ( V_3 , L_13 ) ;
V_188 = - V_35 ;
}
if ( F_43 ( V_17 , V_214 -> V_225 . V_89 ) *
( 1 << V_214 -> V_225 . V_183 ) !=
F_43 ( V_17 , V_214 -> V_182 . V_89 ) *
( 1 << V_214 -> V_182 . V_183 ) ) {
F_63 ( V_3 , L_14 ) ;
V_188 = - V_35 ;
}
return V_188 ;
}
static bool F_102 ( struct V_226 * V_227 ,
bool V_228 , int V_229 , bool V_17 ,
bool * V_230 )
{
unsigned long V_32 ;
F_14 ( & V_227 -> V_37 , V_32 ) ;
* V_230 = ( ( V_227 -> V_231 | V_227 -> V_232 )
== V_233 ) ;
if ( ! V_17 ) {
if ( V_227 -> V_231 == V_233 &&
V_227 -> V_232 == V_233 ) {
V_227 -> V_232 = V_234 ;
V_227 -> V_231 = V_234 ;
goto V_235;
} else
goto V_236;
}
if ( V_228 ) {
if ( V_227 -> V_231 == V_234 )
goto V_236;
if ( V_227 -> V_231 == V_233 )
V_227 -> V_231 = V_237 ;
if ( ! ( V_227 -> V_231 & ( 1 << V_229 ) ) ) {
V_227 -> V_231 |= 1 << V_229 ;
goto V_235;
} else
goto V_236;
} else {
if ( V_227 -> V_232 == V_234 )
goto V_236;
if ( V_227 -> V_232 == V_233 )
V_227 -> V_232 = V_237 ;
if ( ! ( V_227 -> V_232 & ( 1 << V_229 ) ) ) {
V_227 -> V_232 |= 1 << V_229 ;
goto V_235;
} else
goto V_236;
}
V_236:
F_15 ( & V_227 -> V_37 , V_32 ) ;
return false ;
V_235:
F_15 ( & V_227 -> V_37 , V_32 ) ;
return true ;
}
static bool F_103 ( struct V_226 * V_227 , bool V_228 ,
int V_229 )
{
unsigned long V_32 ;
bool V_238 = false ;
F_14 ( & V_227 -> V_37 , V_32 ) ;
if ( ! V_229 ) {
V_227 -> V_232 = V_233 ;
V_227 -> V_231 = V_233 ;
V_238 = true ;
goto V_82;
}
if ( V_228 ) {
V_227 -> V_231 &= ~ ( 1 << V_229 ) ;
if ( V_227 -> V_231 == V_237 )
V_227 -> V_231 = V_233 ;
} else {
V_227 -> V_232 &= ~ ( 1 << V_229 ) ;
if ( V_227 -> V_232 == V_237 )
V_227 -> V_232 = V_233 ;
}
V_238 = ( ( V_227 -> V_231 | V_227 -> V_232 ) ==
V_233 ) ;
V_82:
F_15 ( & V_227 -> V_37 , V_32 ) ;
return V_238 ;
}
static int F_104 ( struct V_2 * V_3 , bool * V_239 )
{
int V_240 ;
int V_241 ;
int V_242 ;
struct V_226 * V_243 ;
int V_33 ;
int V_244 ;
int V_6 ;
int V_110 ;
bool V_228 ;
bool V_17 = V_3 -> V_77 . V_217 == V_218 ;
V_243 = V_3 -> V_8 -> V_111 ;
V_110 = V_3 -> V_8 -> V_110 ;
if ( V_3 -> V_77 . V_78 == V_79 ) {
V_240 = V_3 -> V_77 . V_146 ;
V_6 = 2 * V_240 ;
V_228 = true ;
} else if ( V_3 -> V_77 . V_78 == V_224 ||
V_3 -> V_77 . V_78 == V_245 ) {
V_240 = V_3 -> V_77 . V_147 ;
V_6 = 2 * V_240 + 1 ;
V_228 = false ;
} else
return - V_35 ;
V_241 = F_101 ( V_240 ) ;
V_242 = F_73 ( V_240 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_77 . V_78 == V_245 ) {
if ( V_3 -> V_77 . V_246 ) {
V_33 = V_3 -> V_77 . V_247 ;
if ( F_102 ( & V_243 [ V_33 ] , V_228 ,
0 , V_17 ,
V_239 ) )
goto V_248;
} else {
for ( V_33 = 0 ; V_33 < V_110 ; V_33 ++ ) {
if ( F_102 ( & V_243 [ V_33 ] , V_228 ,
0 , V_17 ,
V_239 ) )
goto V_248;
}
}
} else
for ( V_244 = 0 ; V_244 < V_3 -> V_8 -> V_110 ; V_244 += 8 ) {
int V_249 = V_244 + V_241 * 2 ;
for ( V_33 = V_249 ; V_33 < V_249 + 2 ; V_33 ++ ) {
if ( F_102 ( & V_243 [ V_33 ] ,
V_228 ,
0 ,
V_17 ,
V_239 ) )
goto V_248;
}
}
return - V_35 ;
V_248:
V_3 -> V_11 = & V_243 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_82;
}
if ( V_240 == - 1 )
return - V_35 ;
for ( V_244 = 0 ; V_244 < V_3 -> V_8 -> V_110 ; V_244 += 8 ) {
int V_249 = V_244 + V_241 * 2 ;
if ( V_3 -> V_77 . V_246 ) {
V_33 = V_3 -> V_77 . V_247 ;
if ( ( V_33 != V_249 ) && ( V_33 != V_249 + 1 ) ) {
F_105 ( F_1 ( V_3 ) ,
L_15 , V_33 ) ;
return - V_35 ;
}
if ( F_102 ( & V_243 [ V_33 ] , V_228 , V_242 ,
V_17 , V_239 ) )
goto V_250;
F_105 ( F_1 ( V_3 ) ,
L_16 , V_33 ) ;
return - V_35 ;
}
if ( V_228 ) {
for ( V_33 = V_249 ; V_33 < V_249 + 2 ; V_33 ++ ) {
if ( F_102 ( & V_243 [ V_33 ] , V_228 ,
V_242 , V_17 ,
V_239 ) )
goto V_250;
}
} else {
for ( V_33 = V_249 + 1 ; V_33 >= V_249 ; V_33 -- ) {
if ( F_102 ( & V_243 [ V_33 ] , V_228 ,
V_242 , V_17 ,
V_239 ) )
goto V_250;
}
}
}
return - V_35 ;
V_250:
V_3 -> V_11 = & V_243 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_82:
if ( V_17 )
V_3 -> V_8 -> V_209 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_208 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 )
{
T_6 V_251 = V_3 -> V_4 . V_1 -> V_252 ;
if ( F_107 ( V_253 , V_251 ) && ! F_107 ( V_254 , V_251 ) ) {
V_3 -> V_77 = * V_3 -> V_8 -> V_74 -> V_255 ;
V_3 -> V_77 . V_146 = V_222 ;
V_3 -> V_77 . V_147 = V_3 -> V_8 -> V_74 ->
memcpy [ V_3 -> V_4 . V_256 ] ;
} else if ( F_107 ( V_253 , V_251 ) &&
F_107 ( V_254 , V_251 ) ) {
V_3 -> V_77 = * V_3 -> V_8 -> V_74 -> V_257 ;
} else {
F_63 ( V_3 , L_17 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_108 ( struct V_2 * V_3 )
{
int V_188 = 0 ;
T_2 V_137 ;
struct V_226 * V_227 = V_3 -> V_11 ;
bool V_228 ;
F_65 ( V_3 ) ;
if ( V_227 == NULL ) {
F_63 ( V_3 , L_18 ) ;
return - V_35 ;
}
if ( V_227 -> V_231 == V_233 &&
V_227 -> V_232 == V_233 ) {
F_63 ( V_3 , L_19 ) ;
return - V_35 ;
}
if ( V_3 -> V_77 . V_78 == V_224 ||
V_3 -> V_77 . V_78 == V_245 ) {
V_137 = F_73 ( V_3 -> V_77 . V_147 ) ;
V_228 = false ;
} else if ( V_3 -> V_77 . V_78 == V_79 ) {
V_137 = F_73 ( V_3 -> V_77 . V_146 ) ;
V_228 = true ;
} else {
F_63 ( V_3 , L_20 ) ;
return - V_35 ;
}
F_82 ( V_3 -> V_8 -> V_5 ) ;
V_188 = F_76 ( V_3 , V_125 ) ;
if ( V_188 ) {
F_63 ( V_3 , L_21 ) ;
goto V_82;
}
F_103 ( V_227 , V_228 , F_3 ( V_3 ) ? V_137 : 0 ) ;
if ( F_3 ( V_3 ) )
V_3 -> V_8 -> V_209 [ V_3 -> V_6 ] = NULL ;
else
V_3 -> V_8 -> V_208 [ V_227 -> V_12 ] = NULL ;
if ( V_3 -> V_189 ) {
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_189 = false ;
V_3 -> V_11 = NULL ;
V_3 -> V_258 = false ;
V_82:
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
return V_188 ;
}
static bool F_109 ( struct V_2 * V_3 )
{
void T_1 * V_148 = F_4 ( V_3 ) ;
bool V_259 = false ;
unsigned long V_32 ;
void T_1 * V_123 ;
T_2 V_122 ;
T_2 V_137 ;
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
V_259 = true ;
goto V_260;
}
if ( V_3 -> V_77 . V_78 == V_224 ||
V_3 -> V_77 . V_78 == V_245 ) {
V_137 = F_73 ( V_3 -> V_77 . V_147 ) ;
V_122 = F_58 ( V_148 + V_63 ) ;
} else if ( V_3 -> V_77 . V_78 == V_79 ) {
V_137 = F_73 ( V_3 -> V_77 . V_146 ) ;
V_122 = F_58 ( V_148 + V_59 ) ;
} else {
F_63 ( V_3 , L_20 ) ;
goto V_260;
}
V_122 = ( V_122 & F_68 ( V_137 ) ) >>
F_67 ( V_137 ) ;
if ( V_122 != V_151 )
V_259 = true ;
V_260:
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_259 ;
}
static T_2 F_110 ( struct V_261 * V_4 )
{
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_262 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_262 = F_79 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_262 ;
}
static int
F_111 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_263 , struct V_99 * V_264 ,
unsigned int V_101 , T_7 V_265 ,
T_7 V_266 )
{
struct V_213 * V_267 = & V_4 -> V_77 ;
struct V_268 * V_225 = & V_267 -> V_225 ;
struct V_268 * V_182 = & V_267 -> V_182 ;
int V_34 ;
V_34 = F_112 ( V_263 , V_101 ,
V_265 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_269 . V_270 ,
V_225 -> V_183 ,
V_182 -> V_183 ) ;
V_34 = F_112 ( V_264 , V_101 ,
V_266 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_269 . V_185 ,
V_182 -> V_183 ,
V_225 -> V_183 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_113 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_263 , struct V_99 * V_264 ,
unsigned int V_101 , T_7 V_265 ,
T_7 V_266 )
{
struct V_213 * V_267 = & V_4 -> V_77 ;
struct V_268 * V_225 = & V_267 -> V_225 ;
struct V_268 * V_182 = & V_267 -> V_182 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_70 )
V_32 |= V_271 | V_80 ;
V_34 = F_114 ( V_263 , V_101 , V_265 ,
V_43 -> V_30 . V_27 ,
F_115 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_174 ,
V_225 , V_182 , V_32 ) ;
V_34 = F_114 ( V_264 , V_101 , V_266 ,
V_43 -> V_30 . V_28 ,
F_115 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_175 ,
V_182 , V_225 , V_32 ) ;
F_116 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_117 ( struct V_2 * V_4 , struct V_99 * V_102 ,
unsigned int V_101 , unsigned long V_272 )
{
struct V_213 * V_267 = & V_4 -> V_77 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_49 ( V_102 , V_101 , V_267 -> V_225 . V_183 ,
V_267 -> V_182 . V_183 ) ;
if ( V_43 -> V_16 < 0 ) {
F_63 ( V_4 , L_22 ) ;
goto V_193;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_63 ( V_4 , L_23 ) ;
goto V_193;
}
V_43 -> V_69 = 0 ;
V_43 -> V_47 . V_32 = V_272 ;
V_43 -> V_47 . V_273 = F_86 ;
F_118 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_193:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static T_7
F_119 ( struct V_2 * V_4 , enum V_274 V_275 )
{
struct V_276 * V_277 = V_4 -> V_8 -> V_74 ;
struct V_213 * V_267 = & V_4 -> V_77 ;
T_7 V_108 = 0 ;
if ( V_4 -> V_221 )
return V_4 -> V_221 ;
if ( V_275 == V_278 )
V_108 = V_277 -> V_223 [ V_267 -> V_146 ] ;
else if ( V_275 == V_279 )
V_108 = V_277 -> V_220 [ V_267 -> V_147 ] ;
return V_108 ;
}
static struct V_190 *
F_120 ( struct V_261 * V_280 , struct V_99 * V_263 ,
struct V_99 * V_264 , unsigned int V_101 ,
enum V_274 V_275 , unsigned long V_272 )
{
struct V_2 * V_4 = F_87 ( V_280 , struct V_2 , V_4 ) ;
T_7 V_265 = 0 ;
T_7 V_266 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_63 ( V_4 , L_24 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_37 , V_32 ) ;
V_43 = F_117 ( V_4 , V_263 , V_101 , V_272 ) ;
if ( V_43 == NULL )
goto V_193;
if ( F_121 ( & V_263 [ V_101 - 1 ] ) == V_263 )
V_43 -> V_70 = true ;
if ( V_275 != V_281 ) {
T_7 V_282 = F_119 ( V_4 , V_275 ) ;
if ( V_275 == V_278 )
V_265 = V_282 ;
else if ( V_275 == V_279 )
V_266 = V_282 ;
}
if ( F_3 ( V_4 ) )
V_34 = F_111 ( V_4 , V_43 , V_263 , V_264 ,
V_101 , V_265 , V_266 ) ;
else
V_34 = F_113 ( V_4 , V_43 , V_263 , V_264 ,
V_101 , V_265 , V_266 ) ;
if ( V_34 ) {
F_63 ( V_4 , L_25 ,
F_3 ( V_4 ) ? L_26 : L_27 , V_34 ) ;
goto V_193;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_133 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return & V_43 -> V_47 ;
V_193:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return NULL ;
}
bool F_122 ( struct V_261 * V_4 , void * V_195 )
{
struct V_213 * V_283 = V_195 ;
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
int V_193 ;
if ( V_195 ) {
V_193 = F_100 ( V_3 , V_283 ) ;
if ( ! V_193 )
V_3 -> V_77 = * V_283 ;
} else
V_193 = F_106 ( V_3 ) ;
if ( ! V_193 )
V_3 -> V_258 = true ;
return V_193 == 0 ;
}
static void F_123 ( struct V_2 * V_3 , int V_240 , bool V_27 )
{
bool V_284 = V_3 -> V_77 . V_284 ;
bool V_285 = V_3 -> V_77 . V_286 ;
T_2 V_287 ;
T_2 V_137 = F_73 ( V_240 ) ;
T_2 V_288 = F_101 ( V_240 ) ;
T_2 V_289 = 1 << V_137 ;
T_2 V_290 ;
struct V_291 * V_292 = & V_3 -> V_8 -> V_117 ;
V_287 = V_284 ? V_292 -> V_293 : V_292 -> V_294 ;
if ( ! V_27 && F_3 ( V_3 ) )
V_285 = false ;
V_290 = V_285 ? V_292 -> V_295 : V_292 -> V_296 ;
if ( ! V_27 )
V_289 <<= 16 ;
F_30 ( V_289 , V_3 -> V_8 -> V_9 + V_290 + V_288 * 4 ) ;
F_30 ( V_289 , V_3 -> V_8 -> V_9 + V_287 + V_288 * 4 ) ;
}
static void F_124 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_297 < 3 )
return;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_145 ) )
F_123 ( V_3 , V_3 -> V_77 . V_146 , true ) ;
if ( ( V_3 -> V_77 . V_78 == V_224 ) ||
( V_3 -> V_77 . V_78 == V_145 ) )
F_123 ( V_3 , V_3 -> V_77 . V_147 , false ) ;
}
static int F_125 ( struct V_261 * V_4 )
{
int V_193 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
bool V_298 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_126 ( V_4 ) ;
if ( ! V_3 -> V_258 ) {
V_193 = F_106 ( V_3 ) ;
if ( V_193 ) {
F_63 ( V_3 , L_28 ) ;
goto V_299;
}
}
V_193 = F_104 ( V_3 , & V_298 ) ;
if ( V_193 ) {
F_63 ( V_3 , L_29 ) ;
V_3 -> V_258 = false ;
goto V_299;
}
F_82 ( V_3 -> V_8 -> V_5 ) ;
F_127 ( & V_3 -> V_77 , & V_3 -> V_174 ,
& V_3 -> V_175 , F_3 ( V_3 ) ) ;
F_124 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
F_128 ( & V_3 -> V_77 ,
& V_3 -> V_269 . V_270 , & V_3 -> V_269 . V_185 ) ;
if ( V_3 -> V_77 . V_78 == V_79 )
V_3 -> V_81 = V_3 -> V_8 -> V_300 +
V_3 -> V_77 . V_146 * V_301 ;
else
V_3 -> V_81 = V_3 -> V_8 -> V_300 +
V_3 -> V_77 . V_147 *
V_301 + V_302 ;
}
F_69 ( F_1 ( V_3 ) , L_30 ,
F_3 ( V_3 ) ? L_31 : L_32 ,
V_3 -> V_11 -> V_12 ,
V_3 -> V_77 . V_246 ? L_33 : L_34 ) ;
if ( V_298 )
F_78 ( V_3 ) ;
V_299:
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_193 ;
}
static void F_129 ( struct V_261 * V_4 )
{
struct V_2 * V_3 =
F_87 ( V_4 , struct V_2 , V_4 ) ;
int V_193 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_35 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_193 = F_108 ( V_3 ) ;
if ( V_193 )
F_63 ( V_3 , L_36 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static struct V_190 * F_130 ( struct V_261 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_272 )
{
struct V_99 V_303 ;
struct V_99 V_304 ;
F_131 ( & V_303 , 1 ) ;
F_131 ( & V_304 , 1 ) ;
F_132 ( & V_303 ) = V_28 ;
F_132 ( & V_304 ) = V_27 ;
F_51 ( & V_303 ) = V_23 ;
F_51 ( & V_304 ) = V_23 ;
return F_120 ( V_4 , & V_304 , & V_303 , 1 , V_305 , V_272 ) ;
}
static struct V_190 *
F_133 ( struct V_261 * V_4 ,
struct V_99 * V_303 , unsigned int V_306 ,
struct V_99 * V_304 , unsigned int V_307 ,
unsigned long V_272 )
{
if ( V_306 != V_307 )
return NULL ;
return F_120 ( V_4 , V_304 , V_303 , V_307 , V_305 , V_272 ) ;
}
static struct V_190 *
F_134 ( struct V_261 * V_4 , struct V_99 * V_100 ,
unsigned int V_101 , enum V_274 V_275 ,
unsigned long V_272 , void * V_308 )
{
if ( ! F_135 ( V_275 ) )
return NULL ;
return F_120 ( V_4 , V_100 , V_100 , V_101 , V_275 , V_272 ) ;
}
static struct V_190 *
F_136 ( struct V_261 * V_4 , T_7 V_29 ,
T_8 V_309 , T_8 V_310 ,
enum V_274 V_275 , unsigned long V_32 ,
void * V_308 )
{
unsigned int V_311 = V_309 / V_310 ;
struct V_190 * V_47 ;
struct V_99 * V_102 ;
int V_33 ;
V_102 = F_137 ( V_311 + 1 , sizeof( struct V_99 ) , V_24 ) ;
for ( V_33 = 0 ; V_33 < V_311 ; V_33 ++ ) {
F_132 ( & V_102 [ V_33 ] ) = V_29 ;
F_51 ( & V_102 [ V_33 ] ) = V_310 ;
V_29 += V_310 ;
}
V_102 [ V_311 ] . V_207 = 0 ;
F_51 ( & V_102 [ V_311 ] ) = 0 ;
V_102 [ V_311 ] . V_312 =
( ( unsigned long ) V_102 | 0x01 ) & ~ 0x02 ;
V_47 = F_120 ( V_4 , V_102 , V_102 , V_311 , V_275 ,
V_198 ) ;
F_10 ( V_102 ) ;
return V_47 ;
}
static enum V_313 F_138 ( struct V_261 * V_4 ,
T_3 V_192 ,
struct V_314 * V_315 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
enum V_313 V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_37 ) ;
return - V_35 ;
}
V_34 = F_139 ( V_4 , V_192 , V_315 ) ;
if ( V_34 != V_316 )
F_140 ( V_315 , F_110 ( V_4 ) ) ;
if ( F_109 ( V_3 ) )
V_34 = V_317 ;
return V_34 ;
}
static void F_141 ( struct V_261 * V_4 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_38 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_142 ( & V_3 -> V_87 , & V_3 -> V_88 ) ;
if ( ! V_3 -> V_189 )
( void ) F_90 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static void F_143 ( struct V_261 * V_4 )
{
unsigned long V_32 ;
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
int V_34 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_82 ( V_3 -> V_8 -> V_5 ) ;
V_34 = F_76 ( V_3 , V_125 ) ;
if ( V_34 )
F_63 ( V_3 , L_39 ) ;
F_65 ( V_3 ) ;
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
if ( V_3 -> V_189 ) {
F_83 ( V_3 -> V_8 -> V_5 ) ;
F_84 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_189 = false ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static int
F_144 ( struct V_2 * V_3 ,
struct V_268 * V_283 ,
enum V_318 V_319 ,
T_2 V_320 )
{
enum V_321 V_322 ;
int V_89 ;
switch ( V_319 ) {
case V_323 :
V_322 = V_324 ;
break;
case V_325 :
V_322 = V_326 ;
break;
case V_327 :
V_322 = V_328 ;
break;
case V_329 :
V_322 = V_330 ;
break;
default:
F_105 ( V_3 -> V_8 -> V_5 ,
L_40
L_41 ,
V_319 ) ;
return - V_35 ;
}
if ( F_3 ( V_3 ) ) {
if ( V_320 >= 16 )
V_89 = V_331 ;
else if ( V_320 >= 8 )
V_89 = V_332 ;
else if ( V_320 >= 4 )
V_89 = V_333 ;
else
V_89 = V_90 ;
} else {
if ( V_320 >= 16 )
V_89 = V_334 ;
else if ( V_320 >= 8 )
V_89 = V_335 ;
else if ( V_320 >= 4 )
V_89 = V_336 ;
else
V_89 = V_91 ;
}
V_283 -> V_183 = V_322 ;
V_283 -> V_89 = V_89 ;
V_283 -> V_337 = V_338 ;
return 0 ;
}
static int F_145 ( struct V_261 * V_4 ,
struct V_339 * V_340 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
struct V_213 * V_267 = & V_3 -> V_77 ;
enum V_318 V_341 , V_342 ;
T_7 V_343 ;
T_2 V_344 , V_345 ;
int V_34 ;
V_341 = V_340 -> V_341 ;
V_344 = V_340 -> V_344 ;
V_342 = V_340 -> V_342 ;
V_345 = V_340 -> V_345 ;
if ( V_340 -> V_275 == V_278 ) {
T_7 V_346 =
V_3 -> V_8 -> V_74 -> V_223 [ V_267 -> V_146 ] ;
V_343 = V_340 -> V_347 ;
if ( V_346 )
F_69 ( V_3 -> V_8 -> V_5 ,
L_42
L_43 ,
V_346 , V_343 ) ;
if ( V_267 -> V_78 != V_79 )
F_69 ( V_3 -> V_8 -> V_5 ,
L_44
L_45 ,
V_267 -> V_78 ) ;
V_267 -> V_78 = V_79 ;
if ( V_342 == V_348 )
V_342 = V_341 ;
if ( V_345 == 0 )
V_345 = V_344 ;
} else if ( V_340 -> V_275 == V_279 ) {
T_7 V_349 =
V_3 -> V_8 -> V_74 -> V_220 [ V_267 -> V_147 ] ;
V_343 = V_340 -> V_350 ;
if ( V_349 )
F_69 ( V_3 -> V_8 -> V_5 ,
L_46
L_43 ,
V_349 , V_343 ) ;
if ( V_267 -> V_78 != V_224 )
F_69 ( V_3 -> V_8 -> V_5 ,
L_47
L_48 ,
V_267 -> V_78 ) ;
V_267 -> V_78 = V_224 ;
if ( V_341 == V_348 )
V_341 = V_342 ;
if ( V_344 == 0 )
V_344 = V_345 ;
} else {
F_105 ( V_3 -> V_8 -> V_5 ,
L_49 ,
V_340 -> V_275 ) ;
return - V_35 ;
}
if ( V_344 * V_341 != V_345 * V_342 ) {
F_105 ( V_3 -> V_8 -> V_5 ,
L_50 ,
V_344 ,
V_341 ,
V_345 ,
V_342 ) ;
return - V_35 ;
}
if ( V_344 > 16 ) {
V_344 = 16 ;
V_345 = V_344 * V_341 / V_342 ;
} else if ( V_345 > 16 ) {
V_345 = 16 ;
V_344 = V_345 * V_342 / V_341 ;
}
V_34 = F_144 ( V_3 , & V_267 -> V_225 ,
V_341 ,
V_344 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_144 ( V_3 , & V_267 -> V_182 ,
V_342 ,
V_345 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_128 ( V_267 , & V_3 -> V_269 . V_270 , & V_3 -> V_269 . V_185 ) ;
else
F_127 ( V_267 , & V_3 -> V_174 ,
& V_3 -> V_175 , false ) ;
V_3 -> V_221 = V_343 ;
V_3 -> V_351 = V_340 -> V_275 ;
F_69 ( V_3 -> V_8 -> V_5 ,
L_51
L_52 ,
F_146 ( V_4 ) ,
( V_340 -> V_275 == V_278 ) ? L_53 : L_54 ,
V_341 , V_342 ,
V_344 , V_345 ) ;
return 0 ;
}
static int F_147 ( struct V_261 * V_4 , enum V_352 V_353 ,
unsigned long V_354 )
{
struct V_2 * V_3 = F_87 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_63 ( V_3 , L_38 ) ;
return - V_35 ;
}
switch ( V_353 ) {
case V_355 :
F_143 ( V_4 ) ;
return 0 ;
case V_356 :
return F_81 ( V_3 ) ;
case V_357 :
return F_85 ( V_3 ) ;
case V_358 :
return F_145 ( V_4 ,
(struct V_339 * ) V_354 ) ;
default:
break;
}
return - V_359 ;
}
static void T_9 F_148 ( struct V_109 * V_8 , struct V_360 * V_361 ,
struct V_2 * V_362 , int V_207 ,
int V_363 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_361 -> V_364 ) ;
for ( V_33 = V_207 ; V_33 < V_207 + V_363 ; V_33 ++ ) {
V_3 = & V_362 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_361 ;
F_149 ( & V_3 -> V_37 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_64 ) ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_88 ) ;
F_24 ( & V_3 -> V_87 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_133 ) ;
F_150 ( & V_3 -> V_194 , F_93 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_365 ,
& V_361 -> V_364 ) ;
}
}
static void F_151 ( struct V_109 * V_8 , struct V_360 * V_5 )
{
if ( F_107 ( V_254 , V_5 -> V_252 ) )
V_5 -> V_366 = F_134 ;
if ( F_107 ( V_253 , V_5 -> V_252 ) ) {
V_5 -> V_367 = F_130 ;
V_5 -> V_368 = 2 ;
}
if ( F_107 ( V_369 , V_5 -> V_252 ) )
V_5 -> V_370 = F_133 ;
if ( F_107 ( V_371 , V_5 -> V_252 ) )
V_5 -> V_372 = F_136 ;
V_5 -> V_373 = F_125 ;
V_5 -> V_374 = F_129 ;
V_5 -> V_375 = F_141 ;
V_5 -> V_376 = F_138 ;
V_5 -> V_377 = F_147 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_152 ( struct V_109 * V_8 ,
int V_378 )
{
int V_193 ;
F_148 ( V_8 , & V_8 -> V_379 , V_8 -> V_380 ,
0 , V_8 -> V_381 ) ;
F_153 ( V_8 -> V_379 . V_252 ) ;
F_154 ( V_254 , V_8 -> V_379 . V_252 ) ;
F_154 ( V_371 , V_8 -> V_379 . V_252 ) ;
F_151 ( V_8 , & V_8 -> V_379 ) ;
V_193 = F_155 ( & V_8 -> V_379 ) ;
if ( V_193 ) {
F_98 ( V_8 -> V_5 , L_55 ) ;
goto V_382;
}
F_148 ( V_8 , & V_8 -> V_383 , V_8 -> V_380 ,
V_8 -> V_381 , V_8 -> V_74 -> V_384 ) ;
F_153 ( V_8 -> V_383 . V_252 ) ;
F_154 ( V_253 , V_8 -> V_383 . V_252 ) ;
F_154 ( V_369 , V_8 -> V_383 . V_252 ) ;
F_151 ( V_8 , & V_8 -> V_383 ) ;
V_193 = F_155 ( & V_8 -> V_383 ) ;
if ( V_193 ) {
F_98 ( V_8 -> V_5 ,
L_56 ) ;
goto V_385;
}
F_148 ( V_8 , & V_8 -> V_386 , V_8 -> V_387 ,
0 , V_378 ) ;
F_153 ( V_8 -> V_386 . V_252 ) ;
F_154 ( V_254 , V_8 -> V_386 . V_252 ) ;
F_154 ( V_253 , V_8 -> V_386 . V_252 ) ;
F_154 ( V_369 , V_8 -> V_386 . V_252 ) ;
F_154 ( V_371 , V_8 -> V_379 . V_252 ) ;
F_151 ( V_8 , & V_8 -> V_386 ) ;
V_193 = F_155 ( & V_8 -> V_386 ) ;
if ( V_193 ) {
F_98 ( V_8 -> V_5 ,
L_57 ) ;
goto V_388;
}
return 0 ;
V_388:
F_156 ( & V_8 -> V_383 ) ;
V_385:
F_156 ( & V_8 -> V_379 ) ;
V_382:
return V_193 ;
}
static int F_157 ( struct V_1 * V_5 )
{
struct V_389 * V_390 = F_158 ( V_5 ) ;
struct V_109 * V_8 = F_159 ( V_390 ) ;
int V_34 = 0 ;
if ( V_8 -> V_391 )
V_34 = F_160 ( V_8 -> V_391 ) ;
return V_34 ;
}
static int F_161 ( struct V_1 * V_5 )
{
struct V_389 * V_390 = F_158 ( V_5 ) ;
struct V_109 * V_8 = F_159 ( V_390 ) ;
F_55 ( V_8 , true ) ;
if ( V_8 -> V_297 != 1 )
F_54 ( V_8 -> V_392 ,
V_8 -> V_9 + V_393 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_5 )
{
struct V_389 * V_390 = F_158 ( V_5 ) ;
struct V_109 * V_8 = F_159 ( V_390 ) ;
if ( V_8 -> V_394 )
F_55 ( V_8 , false ) ;
F_54 ( V_395 ,
V_8 -> V_9 + V_393 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_5 )
{
struct V_389 * V_390 = F_158 ( V_5 ) ;
struct V_109 * V_8 = F_159 ( V_390 ) ;
int V_34 = 0 ;
if ( V_8 -> V_391 )
V_34 = F_164 ( V_8 -> V_391 ) ;
return V_34 ;
}
static int T_9 F_165 ( struct V_109 * V_8 )
{
int V_33 ;
int V_396 = 0 ;
T_2 V_149 [ 2 ] ;
int V_397 = - 2 ;
int V_398 = V_399 ;
V_149 [ 0 ] = F_58 ( V_8 -> V_9 + V_400 ) ;
V_149 [ 1 ] = F_58 ( V_8 -> V_9 + V_401 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
V_8 -> V_111 [ V_33 ] . V_12 = V_33 ;
V_397 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_149 [ V_33 % 2 ] >> V_397 ) & 3 ) == 1 ) {
V_8 -> V_111 [ V_33 ] . V_231 = V_234 ;
V_8 -> V_111 [ V_33 ] . V_232 = V_234 ;
V_8 -> V_111 [ V_33 ] . V_112 = true ;
V_398 |= F_166 ( F_167 ( V_33 ) ,
V_402 ) ;
V_398 |= F_166 ( F_167 ( V_33 ) ,
V_403 ) ;
} else {
V_8 -> V_111 [ V_33 ] . V_231 = V_233 ;
V_8 -> V_111 [ V_33 ] . V_232 = V_233 ;
V_8 -> V_111 [ V_33 ] . V_112 = false ;
V_396 ++ ;
}
F_149 ( & V_8 -> V_111 [ V_33 ] . V_37 ) ;
}
for ( V_33 = 0 ; V_8 -> V_74 -> V_404 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_404 [ V_33 ] ;
V_8 -> V_111 [ V_4 ] . V_231 = V_234 ;
V_8 -> V_111 [ V_4 ] . V_232 = V_234 ;
V_8 -> V_111 [ V_4 ] . V_112 = true ;
V_398 |= F_166 ( F_167 ( V_4 ) ,
V_402 ) ;
V_398 |= F_166 ( F_167 ( V_4 ) ,
V_403 ) ;
V_396 -- ;
}
for ( V_33 = 0 ; V_33 < V_8 -> V_74 -> V_405 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_406 [ V_33 ] ;
V_8 -> V_111 [ V_4 ] . V_76 = true ;
}
F_168 ( V_8 -> V_5 , L_58 ,
V_396 , V_8 -> V_110 ) ;
V_149 [ 0 ] = F_58 ( V_8 -> V_9 + V_407 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
if ( V_8 -> V_111 [ V_33 ] . V_231 == V_233 &&
( V_149 [ 0 ] & 0x3 ) != 1 )
F_168 ( V_8 -> V_5 ,
L_59 ,
V_143 , V_33 , V_149 [ 0 ] & 0x3 ) ;
V_149 [ 0 ] = V_149 [ 0 ] >> 2 ;
}
F_30 ( V_395 , V_8 -> V_9 + V_393 ) ;
V_8 -> V_392 = V_398 ;
return V_396 ;
}
static struct V_109 * T_9 F_169 ( struct V_389 * V_390 )
{
struct V_276 * V_74 ;
struct V_408 * V_408 = NULL ;
void T_1 * V_9 = NULL ;
struct V_409 * V_188 = NULL ;
struct V_109 * V_8 = NULL ;
int V_381 = 0 ;
int V_110 ;
int V_410 = - V_35 ;
int V_33 ;
T_2 V_411 ;
T_2 V_412 ;
T_10 V_297 ;
V_408 = F_170 ( & V_390 -> V_5 , NULL ) ;
if ( F_171 ( V_408 ) ) {
F_98 ( & V_390 -> V_5 , L_60 ) ;
goto V_413;
}
V_410 = F_172 ( V_408 ) ;
if ( V_410 ) {
F_98 ( & V_390 -> V_5 , L_61 ) ;
goto V_413;
}
V_188 = F_173 ( V_390 , V_414 , L_62 ) ;
if ( ! V_188 )
goto V_413;
if ( F_174 ( V_188 -> V_415 , F_175 ( V_188 ) ,
V_416 L_63 ) == NULL )
goto V_413;
V_9 = F_176 ( V_188 -> V_415 , F_175 ( V_188 ) ) ;
if ( ! V_9 )
goto V_413;
for ( V_411 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_411 |= ( F_58 ( V_9 + F_175 ( V_188 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_412 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_412 |= ( F_58 ( V_9 + F_175 ( V_188 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_412 != V_417 ) {
F_98 ( & V_390 -> V_5 , L_64 ) ;
goto V_413;
}
if ( F_177 ( V_411 ) != V_418 ) {
F_98 ( & V_390 -> V_5 , L_65 ,
F_177 ( V_411 ) ,
V_418 ) ;
goto V_413;
}
V_297 = F_178 ( V_411 ) ;
V_74 = V_390 -> V_5 . V_419 ;
if ( V_74 -> V_420 )
V_110 = V_74 -> V_420 ;
else
V_110 = 4 * ( F_58 ( V_9 + V_421 ) & 0x7 ) + 4 ;
F_168 ( & V_390 -> V_5 , L_66 ,
V_297 , V_188 -> V_415 , V_110 ) ;
if ( V_297 < 2 ) {
F_98 ( & V_390 -> V_5 , L_67 ,
V_297 ) ;
goto V_413;
}
for ( V_33 = 0 ; V_33 < V_74 -> V_422 ; V_33 ++ )
if ( V_74 -> V_223 [ V_33 ] != 0 )
V_381 ++ ;
for ( V_33 = 0 ; V_33 < V_74 -> V_422 ; V_33 ++ )
if ( V_74 -> V_220 [ V_33 ] != 0 )
V_381 ++ ;
V_8 = F_179 ( F_47 ( sizeof( struct V_109 ) , 4 ) +
( V_110 + V_381 + V_74 -> V_384 ) *
sizeof( struct V_2 ) , V_423 ) ;
if ( V_8 == NULL ) {
F_98 ( & V_390 -> V_5 , L_68 ) ;
goto V_413;
}
V_8 -> V_297 = V_297 ;
V_8 -> V_408 = V_408 ;
V_8 -> V_110 = V_110 ;
V_8 -> V_381 = V_381 ;
V_8 -> V_424 = V_188 -> V_415 ;
V_8 -> V_425 = F_175 ( V_188 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_5 = & V_390 -> V_5 ;
V_8 -> V_387 = ( ( void * ) V_8 ) + F_47 ( sizeof( struct V_109 ) , 4 ) ;
V_8 -> V_380 = & V_8 -> V_387 [ V_110 ] ;
if ( V_8 -> V_74 -> V_420 == 14 ) {
V_8 -> V_117 . V_105 = V_426 ;
V_8 -> V_117 . V_119 = V_427 ;
V_8 -> V_117 . V_428 = V_429 ;
V_8 -> V_117 . V_430 = V_431 ;
V_8 -> V_117 . V_293 = V_432 ;
V_8 -> V_117 . V_294 = V_433 ;
V_8 -> V_117 . V_295 = V_434 ;
V_8 -> V_117 . V_296 = V_435 ;
V_8 -> V_117 . V_204 = V_436 ;
V_8 -> V_117 . V_202 = F_56 ( V_436 ) ;
V_8 -> V_117 . V_437 = V_438 ;
V_8 -> V_117 . V_439 = F_56 ( V_438 ) ;
} else {
if ( V_8 -> V_297 >= 3 ) {
V_8 -> V_117 . V_105 = V_440 ;
V_8 -> V_117 . V_119 = V_441 ;
}
V_8 -> V_117 . V_428 = V_442 ;
V_8 -> V_117 . V_430 = V_443 ;
V_8 -> V_117 . V_293 = V_444 ;
V_8 -> V_117 . V_294 = V_445 ;
V_8 -> V_117 . V_295 = V_446 ;
V_8 -> V_117 . V_296 = V_447 ;
V_8 -> V_117 . V_204 = V_448 ;
V_8 -> V_117 . V_202 = F_56 ( V_448 ) ;
V_8 -> V_117 . V_437 = V_449 ;
V_8 -> V_117 . V_439 = F_56 ( V_449 ) ;
}
V_8 -> V_111 = F_179 ( V_110 * sizeof( struct V_226 ) ,
V_423 ) ;
if ( ! V_8 -> V_111 )
goto V_413;
V_8 -> V_208 = F_179 ( V_110 *
sizeof( struct V_2 * ) ,
V_423 ) ;
if ( ! V_8 -> V_208 )
goto V_413;
if ( V_381 + V_74 -> V_384 ) {
V_8 -> V_209 = F_179 ( V_74 -> V_422 * 2 *
sizeof( struct V_2 * ) ,
V_423 ) ;
if ( ! V_8 -> V_209 )
goto V_413;
}
V_8 -> V_114 = F_6 ( V_8 -> V_110 *
sizeof( V_113 ) ,
V_423 ) ;
if ( ! V_8 -> V_114 )
goto V_413;
V_8 -> V_36 . V_40 =
F_179 ( V_110 * sizeof( struct V_14 * )
* V_38 , V_423 ) ;
if ( ! V_8 -> V_36 . V_40 )
goto V_413;
V_8 -> V_48 = F_180 ( V_416 , sizeof( struct V_14 ) ,
0 , V_450 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_413;
return V_8 ;
V_413:
if ( ! V_410 )
F_181 ( V_408 ) ;
if ( ! F_171 ( V_408 ) )
F_182 ( V_408 ) ;
if ( V_9 )
F_183 ( V_9 ) ;
if ( V_188 )
F_184 ( V_188 -> V_415 ,
F_175 ( V_188 ) ) ;
if ( V_9 )
F_183 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_114 ) ;
F_10 ( V_8 -> V_209 ) ;
F_10 ( V_8 -> V_208 ) ;
F_10 ( V_8 -> V_111 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_185 ( struct V_109 * V_8 )
{
int V_33 ;
T_2 V_451 [ 2 ] = { 0 , 0 } ;
T_2 V_452 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_453 = 0 ;
T_2 V_454 = 0 ;
struct V_455 * V_456 = V_8 -> V_117 . V_437 ;
T_2 V_457 = V_8 -> V_117 . V_439 ;
for ( V_33 = 0 ; V_33 < V_457 ; V_33 ++ )
F_30 ( V_456 [ V_33 ] . V_149 ,
V_8 -> V_9 + V_456 [ V_33 ] . V_138 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_110 ; V_33 ++ ) {
V_452 [ V_33 % 2 ] = V_452 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_111 [ V_8 -> V_110 - V_33 - 1 ] . V_231
== V_234 ) {
V_452 [ V_33 % 2 ] |= 3 ;
continue;
}
V_453 = ( V_453 << 1 ) | 1 ;
V_454 = ( V_454 << 1 ) | 1 ;
V_451 [ V_33 % 2 ] = V_451 [ V_33 % 2 ] << 2 ;
V_451 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_451 [ 1 ] , V_8 -> V_9 + V_169 ) ;
F_30 ( V_451 [ 0 ] , V_8 -> V_9 + V_458 ) ;
F_30 ( V_452 [ 1 ] , V_8 -> V_9 + V_128 ) ;
F_30 ( V_452 [ 0 ] , V_8 -> V_9 + V_129 ) ;
F_30 ( V_453 , V_8 -> V_9 + V_8 -> V_117 . V_428 ) ;
F_30 ( V_454 , V_8 -> V_9 + V_8 -> V_117 . V_430 ) ;
V_8 -> V_117 . V_437 = NULL ;
V_8 -> V_117 . V_439 = 0 ;
}
static int T_9 F_186 ( struct V_109 * V_8 )
{
struct V_65 * V_66 = & V_8 -> V_36 ;
unsigned long * V_459 ;
int V_33 , V_244 ;
int V_34 = 0 ;
V_459 = F_6 ( sizeof( unsigned long ) * V_460 ,
V_423 ) ;
if ( ! V_459 ) {
V_34 = - V_25 ;
goto V_413;
}
V_8 -> V_36 . V_461 = V_462 * V_8 -> V_110 / V_463 ;
for ( V_33 = 0 ; V_33 < V_460 ; V_33 ++ ) {
V_459 [ V_33 ] = F_187 ( V_423 ,
V_8 -> V_36 . V_461 ) ;
if ( ! V_459 [ V_33 ] ) {
F_98 ( V_8 -> V_5 , L_69 ,
V_8 -> V_36 . V_461 ) ;
for ( V_244 = 0 ; V_244 < V_33 ; V_244 ++ )
F_188 ( V_459 [ V_244 ] , V_8 -> V_36 . V_461 ) ;
goto V_413;
}
if ( ( F_115 ( ( void * ) V_459 [ V_33 ] ) &
( V_464 - 1 ) ) == 0 )
break;
}
for ( V_244 = 0 ; V_244 < V_33 ; V_244 ++ )
F_188 ( V_459 [ V_244 ] , V_8 -> V_36 . V_461 ) ;
if ( V_33 < V_460 ) {
V_8 -> V_36 . V_8 = ( void * ) V_459 [ V_33 ] ;
} else {
F_189 ( V_8 -> V_5 ,
L_70 ,
V_143 , V_8 -> V_36 . V_461 ) ;
V_8 -> V_36 . V_465 = F_6 ( V_462 *
V_8 -> V_110 +
V_464 ,
V_423 ) ;
if ( ! V_8 -> V_36 . V_465 ) {
V_34 = - V_25 ;
goto V_413;
}
V_8 -> V_36 . V_8 = F_7 ( V_8 -> V_36 . V_465 ,
V_464 ) ;
}
V_66 -> V_29 = F_8 ( V_8 -> V_5 , V_66 -> V_8 ,
V_462 * V_8 -> V_110 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_66 -> V_29 ) ) {
V_66 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_413;
}
F_30 ( F_115 ( V_8 -> V_36 . V_8 ) ,
V_8 -> V_9 + V_466 ) ;
V_413:
F_10 ( V_459 ) ;
return V_34 ;
}
static int T_9 F_190 ( struct V_389 * V_390 )
{
int V_193 ;
int V_34 = - V_467 ;
struct V_109 * V_8 ;
struct V_409 * V_188 = NULL ;
int V_378 ;
T_2 V_149 ;
V_8 = F_169 ( V_390 ) ;
if ( ! V_8 )
goto V_413;
V_378 = F_165 ( V_8 ) ;
F_191 ( V_390 , V_8 ) ;
F_149 ( & V_8 -> V_205 ) ;
F_149 ( & V_8 -> V_127 ) ;
V_188 = F_173 ( V_390 , V_414 , L_71 ) ;
if ( ! V_188 ) {
V_34 = - V_467 ;
F_98 ( & V_390 -> V_5 , L_72 ) ;
goto V_413;
}
V_8 -> V_468 = F_175 ( V_188 ) ;
V_8 -> V_469 = V_188 -> V_415 ;
if ( F_174 ( V_188 -> V_415 , F_175 ( V_188 ) ,
V_416 L_73 ) == NULL ) {
V_34 = - V_132 ;
F_98 ( & V_390 -> V_5 ,
L_74 ,
V_188 -> V_415 , V_188 -> V_470 ) ;
goto V_413;
}
V_149 = F_58 ( V_8 -> V_9 + V_471 ) ;
if ( V_188 -> V_415 != V_149 && V_149 != 0 ) {
F_189 ( & V_390 -> V_5 ,
L_75 ,
V_143 , V_149 , V_188 -> V_415 ) ;
} else
F_30 ( V_188 -> V_415 , V_8 -> V_9 + V_471 ) ;
V_8 -> V_300 = F_176 ( V_188 -> V_415 , F_175 ( V_188 ) ) ;
if ( ! V_8 -> V_300 ) {
V_34 = - V_25 ;
F_98 ( & V_390 -> V_5 , L_76 ) ;
goto V_413;
}
if ( V_8 -> V_74 -> V_73 ) {
V_188 = F_173 ( V_390 , V_414 ,
L_77 ) ;
if ( ! V_188 ) {
V_34 = - V_467 ;
F_98 ( & V_390 -> V_5 ,
L_78 ) ;
goto V_413;
}
V_8 -> V_36 . V_8 = F_176 ( V_188 -> V_415 ,
F_175 ( V_188 ) ) ;
if ( ! V_8 -> V_36 . V_8 ) {
V_34 = - V_25 ;
F_98 ( & V_390 -> V_5 , L_79 ) ;
goto V_413;
}
F_30 ( V_188 -> V_415 , V_8 -> V_9 + V_466 ) ;
} else {
V_34 = F_186 ( V_8 ) ;
if ( V_34 ) {
F_98 ( & V_390 -> V_5 , L_80 ) ;
goto V_413;
}
}
F_149 ( & V_8 -> V_36 . V_37 ) ;
V_8 -> V_199 = F_192 ( V_390 , 0 ) ;
V_34 = F_193 ( V_8 -> V_199 , F_95 , 0 , V_416 , V_8 ) ;
if ( V_34 ) {
F_98 ( & V_390 -> V_5 , L_81 ) ;
goto V_413;
}
F_194 ( V_8 -> V_5 ) ;
F_195 ( V_8 -> V_5 , V_472 ) ;
F_196 ( V_8 -> V_5 ) ;
F_197 ( V_8 -> V_5 ) ;
F_198 ( V_8 -> V_5 ) ;
if ( V_8 -> V_74 -> V_73 ) {
V_8 -> V_391 = F_199 ( V_8 -> V_5 , L_77 ) ;
if ( F_171 ( V_8 -> V_391 ) ) {
F_98 ( & V_390 -> V_5 , L_82 ) ;
V_8 -> V_391 = NULL ;
goto V_413;
}
V_34 = F_164 ( V_8 -> V_391 ) ;
if ( V_34 ) {
F_98 ( & V_390 -> V_5 ,
L_83 ) ;
F_200 ( V_8 -> V_391 ) ;
V_8 -> V_391 = NULL ;
goto V_413;
}
}
V_8 -> V_394 = true ;
V_193 = F_152 ( V_8 , V_378 ) ;
if ( V_193 )
goto V_413;
V_8 -> V_5 -> V_473 = & V_8 -> V_473 ;
V_193 = F_201 ( V_8 -> V_5 , V_98 ) ;
if ( V_193 ) {
F_98 ( & V_390 -> V_5 , L_84 ) ;
goto V_413;
}
F_185 ( V_8 ) ;
F_168 ( V_8 -> V_5 , L_85 ) ;
return 0 ;
V_413:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_202 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_183 ( V_8 -> V_9 ) ;
if ( V_8 -> V_36 . V_8 && V_8 -> V_74 -> V_73 ) {
F_183 ( V_8 -> V_36 . V_8 ) ;
V_8 -> V_36 . V_8 = NULL ;
}
if ( V_8 -> V_36 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_36 . V_29 ,
V_462 * V_8 -> V_110 ,
V_31 ) ;
if ( ! V_8 -> V_36 . V_465 && V_8 -> V_36 . V_8 )
F_188 ( ( unsigned long ) V_8 -> V_36 . V_8 ,
V_8 -> V_36 . V_461 ) ;
F_10 ( V_8 -> V_36 . V_465 ) ;
if ( V_8 -> V_469 )
F_184 ( V_8 -> V_469 ,
V_8 -> V_468 ) ;
if ( V_8 -> V_424 )
F_184 ( V_8 -> V_424 ,
V_8 -> V_425 ) ;
if ( V_8 -> V_408 ) {
F_181 ( V_8 -> V_408 ) ;
F_182 ( V_8 -> V_408 ) ;
}
if ( V_8 -> V_391 ) {
F_160 ( V_8 -> V_391 ) ;
F_200 ( V_8 -> V_391 ) ;
}
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_209 ) ;
F_10 ( V_8 -> V_208 ) ;
F_10 ( V_8 -> V_111 ) ;
F_10 ( V_8 ) ;
}
F_98 ( & V_390 -> V_5 , L_86 ) ;
return V_34 ;
}
static int T_9 F_203 ( void )
{
return F_204 ( & V_474 , F_190 ) ;
}
