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
static int F_52 ( struct V_2 * V_3 ,
enum V_104 V_105 )
{
T_2 V_106 ;
int V_33 ;
void T_1 * V_107 ;
int V_34 = 0 ;
unsigned long V_32 ;
T_2 V_108 ;
if ( V_105 == V_109 ) {
V_34 = F_52 ( V_3 , V_110 ) ;
if ( V_34 )
return V_34 ;
}
F_14 ( & V_3 -> V_8 -> V_111 , V_32 ) ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_107 = V_3 -> V_8 -> V_9 + V_112 ;
else
V_107 = V_3 -> V_8 -> V_9 + V_113 ;
if ( V_105 == V_110 ) {
V_106 = ( F_53 ( V_107 ) &
F_54 ( V_3 -> V_11 -> V_12 ) ) >>
F_55 ( V_3 -> V_11 -> V_12 ) ;
if ( V_106 == V_114 || V_106 == V_109 )
goto V_64;
}
V_108 = 0xffffffff & ~ ( F_54 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_108 | ( V_105 << F_55 ( V_3 -> V_11 -> V_12 ) ) ,
V_107 ) ;
if ( V_105 == V_110 ) {
for ( V_33 = 0 ; V_33 < V_115 ; V_33 ++ ) {
V_106 = ( F_53 ( V_107 ) &
F_54 ( V_3 -> V_11 -> V_12 ) ) >>
F_55 ( V_3 -> V_11 -> V_12 ) ;
F_56 () ;
F_57 ( 3 ) ;
if ( V_106 == V_109 ||
V_106 == V_114 )
break;
}
if ( V_33 == V_115 ) {
F_58 ( V_3 ,
L_1 ,
V_3 -> V_11 -> V_12 , V_3 -> V_6 ,
V_106 ) ;
F_59 () ;
V_34 = - V_116 ;
}
}
V_64:
F_15 ( & V_3 -> V_8 -> V_111 , V_32 ) ;
return V_34 ;
}
static void F_60 ( struct V_2 * V_3 )
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
if ( ! F_20 ( & V_3 -> V_117 ) )
F_21 (d40d, _d,
&d40c->prepare_queue, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
V_3 -> V_118 = 0 ;
}
static void F_61 ( struct V_2 * V_3 ,
enum V_119 V_120 , T_2 V_121 ,
int V_122 )
{
void T_1 * V_123 = F_4 ( V_3 ) + V_122 ;
int V_124 ;
T_2 V_106 ;
switch ( V_120 ) {
case V_125 :
F_30 ( ( V_125 << F_62 ( V_121 ) )
| ~ F_63 ( V_121 ) , V_123 ) ;
break;
case V_126 :
V_106 = ( F_53 ( V_123 ) & F_63 ( V_121 ) ) >>
F_62 ( V_121 ) ;
if ( V_106 == V_125 ||
V_106 == V_126 )
break;
F_30 ( ( V_126 << F_62 ( V_121 ) )
| ~ F_63 ( V_121 ) , V_123 ) ;
for ( V_124 = 0 ; V_124 < V_115 ; V_124 ++ ) {
V_106 = ( F_53 ( V_123 ) & F_63 ( V_121 ) ) >>
F_62 ( V_121 ) ;
F_56 () ;
F_57 ( 3 ) ;
if ( V_106 == V_125 )
break;
}
if ( V_124 == V_115 ) {
F_58 ( V_3 ,
L_2
L_3 , V_3 -> V_11 -> V_12 ,
V_3 -> V_6 , V_106 ) ;
}
break;
case V_127 :
V_124 = 100 ;
while ( -- V_124 ) {
F_30 ( ( V_127 <<
F_62 ( V_121 ) ) |
~ F_63 ( V_121 ) , V_123 ) ;
if ( F_53 ( V_123 ) & F_63 ( V_121 ) )
break;
}
if ( V_124 != 99 )
F_64 ( F_1 ( V_3 ) ,
L_4 ,
V_128 , V_122 == V_59 ? 'S' : 'D' ,
100 - V_124 ) ;
F_65 ( ! V_124 ) ;
break;
case V_129 :
F_66 () ;
break;
}
}
static void F_67 ( struct V_2 * V_3 ,
enum V_119 V_120 )
{
T_2 V_121 = F_68 ( V_3 -> V_77 . V_130 ) ;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_131 ) )
F_61 ( V_3 , V_120 , V_121 ,
V_59 ) ;
if ( V_3 -> V_77 . V_78 != V_79 )
F_61 ( V_3 , V_120 , V_121 ,
V_63 ) ;
}
static T_2 F_69 ( struct V_2 * V_3 )
{
void T_1 * V_132 = F_4 ( V_3 ) ;
T_2 V_133 ;
V_133 = F_53 ( V_132 + V_59 ) ;
V_133 |= F_53 ( V_132 + V_63 ) ;
return V_133 ;
}
static int
F_70 ( struct V_2 * V_3 , enum V_104 V_105 )
{
unsigned long V_32 ;
int V_34 = 0 ;
T_2 V_134 ;
void T_1 * V_107 ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_107 = V_3 -> V_8 -> V_9 + V_112 ;
else
V_107 = V_3 -> V_8 -> V_9 + V_113 ;
F_14 ( & V_3 -> V_11 -> V_37 , V_32 ) ;
switch ( V_105 ) {
case V_109 :
case V_110 :
V_134 = ( F_53 ( V_107 ) &
F_54 ( V_3 -> V_11 -> V_12 ) ) >>
F_55 ( V_3 -> V_11 -> V_12 ) ;
if ( V_134 == V_135 )
F_67 ( V_3 , V_126 ) ;
else
F_67 ( V_3 , V_125 ) ;
if ( ! F_69 ( V_3 ) && ( V_105 == V_109 ) )
V_34 = F_52 ( V_3 , V_105 ) ;
break;
case V_135 :
F_67 ( V_3 , V_127 ) ;
V_34 = F_52 ( V_3 , V_105 ) ;
break;
case V_114 :
F_66 () ;
break;
}
F_15 ( & V_3 -> V_11 -> V_37 , V_32 ) ;
return V_34 ;
}
static int F_71 ( struct V_2 * V_3 ,
enum V_104 V_105 )
{
if ( F_3 ( V_3 ) )
return F_70 ( V_3 , V_105 ) ;
else
return F_52 ( V_3 , V_105 ) ;
}
static T_2 F_72 ( struct V_2 * V_3 )
{
static const unsigned int V_136 [] = {
[ V_137 ]
= V_138 ,
[ V_139 ]
= V_140 ,
[ V_141 ]
= V_142 ,
} ;
static const unsigned int V_143 [] = {
[ V_144 ]
= V_145 ,
[ V_146 ]
= V_147 ,
[ V_148 ]
= V_149 ,
} ;
if ( F_2 ( V_3 ) )
return V_136 [ V_3 -> V_77 . V_150 ] ;
else
return V_143 [ V_3 -> V_77 . V_150 ] ;
}
static void F_73 ( struct V_2 * V_3 )
{
T_2 V_151 ;
T_2 V_152 ;
V_151 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_152 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_55 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_152 , V_3 -> V_8 -> V_9 + V_153 + V_151 ) ;
V_152 = F_72 ( V_3 ) << F_55 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_152 , V_3 -> V_8 -> V_9 + V_154 + V_151 ) ;
if ( F_3 ( V_3 ) ) {
int V_155 = ( V_3 -> V_11 -> V_12 << V_156 )
& V_157 ;
void T_1 * V_132 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_158 , V_132 + V_53 ) ;
F_30 ( V_3 -> V_159 , V_132 + V_60 ) ;
F_30 ( V_155 , V_132 + V_55 ) ;
F_30 ( V_155 , V_132 + V_61 ) ;
F_30 ( 0 , V_132 + V_59 ) ;
F_30 ( 0 , V_132 + V_63 ) ;
}
}
static T_2 F_74 ( struct V_2 * V_3 )
{
T_2 V_160 ;
if ( F_3 ( V_3 ) )
V_160 = ( F_53 ( & V_3 -> V_81 -> V_161 ) & V_162 )
>> V_163 ;
else {
T_2 V_133 = F_53 ( F_4 ( V_3 ) + V_61 ) ;
V_160 = ( V_133 & V_164 )
>> V_165 ;
}
return V_160 * V_3 -> V_77 . V_166 . V_167 ;
}
static bool F_75 ( struct V_2 * V_3 )
{
bool V_168 ;
if ( F_3 ( V_3 ) )
V_168 = F_53 ( & V_3 -> V_81 -> V_169 ) & V_170 ;
else
V_168 = F_53 ( F_4 ( V_3 ) + V_63 )
& V_171 ;
return V_168 ;
}
static int F_76 ( struct V_2 * V_3 )
{
int V_172 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_173 )
return 0 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
V_172 = F_71 ( V_3 , V_110 ) ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_172 ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_172 = 0 ;
unsigned long V_32 ;
if ( ! V_3 -> V_173 )
return 0 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
if ( F_74 ( V_3 ) || F_75 ( V_3 ) )
V_172 = F_71 ( V_3 , V_135 ) ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_172 ;
}
static T_3 F_81 ( struct V_174 * V_175 )
{
struct V_2 * V_3 = F_82 ( V_175 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_82 ( V_175 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
T_3 V_176 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_176 = F_83 ( V_175 ) ;
F_39 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_176 ;
}
static int F_84 ( struct V_2 * V_3 )
{
return F_71 ( V_3 , V_135 ) ;
}
static struct V_14 * F_85 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_177 ;
V_15 = F_41 ( V_3 ) ;
if ( V_15 != NULL ) {
if ( ! V_3 -> V_173 ) {
V_3 -> V_173 = true ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_36 ( V_3 , V_15 ) ;
V_177 = F_84 ( V_3 ) ;
if ( V_177 )
return NULL ;
}
return V_15 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_15 = F_37 ( V_3 ) ;
if ( V_15 == NULL )
return;
if ( V_15 -> V_70 ) {
if ( V_15 -> V_69 < V_15 -> V_16
&& ! F_75 ( V_3 )
&& ! F_74 ( V_3 ) ) {
F_16 ( V_3 , V_15 ) ;
F_36 ( V_3 , V_15 ) ;
( void ) F_84 ( V_3 ) ;
if ( V_15 -> V_69 == V_15 -> V_16 )
V_15 -> V_69 = 0 ;
}
} else {
F_16 ( V_3 , V_15 ) ;
if ( V_15 -> V_69 < V_15 -> V_16 ) {
F_36 ( V_3 , V_15 ) ;
( void ) F_84 ( V_3 ) ;
return;
}
if ( F_85 ( V_3 ) == NULL ) {
V_3 -> V_173 = false ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_31 ( V_3 , V_15 ) ;
}
V_3 -> V_118 ++ ;
F_87 ( & V_3 -> V_178 ) ;
}
static void F_88 ( unsigned long V_179 )
{
struct V_2 * V_3 = (struct V_2 * ) V_179 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
bool V_180 ;
T_4 V_181 ;
void * V_182 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_15 = F_42 ( V_3 ) ;
if ( V_15 == NULL ) {
V_15 = F_37 ( V_3 ) ;
if ( V_15 == NULL || ! V_15 -> V_70 )
goto V_177;
}
if ( ! V_15 -> V_70 )
F_89 ( & V_15 -> V_47 ) ;
if ( V_3 -> V_118 == 0 ) {
F_15 ( & V_3 -> V_37 , V_32 ) ;
return;
}
V_180 = ! ! ( V_15 -> V_47 . V_32 & V_183 ) ;
V_181 = V_15 -> V_47 . V_181 ;
V_182 = V_15 -> V_47 . V_182 ;
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
V_3 -> V_118 -- ;
if ( V_3 -> V_118 )
F_87 ( & V_3 -> V_178 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
if ( V_180 && V_181 )
V_181 ( V_182 ) ;
return;
V_177:
if ( V_3 -> V_118 > 0 )
V_3 -> V_118 -- ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static T_5 F_90 ( int V_184 , void * V_179 )
{
int V_33 ;
T_2 V_39 ;
T_2 V_185 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_186 * V_8 = V_179 ;
T_2 V_187 [ V_8 -> V_188 . V_189 ] ;
struct V_190 * V_191 = V_8 -> V_188 . V_191 ;
T_2 V_189 = V_8 -> V_188 . V_189 ;
F_14 ( & V_8 -> V_192 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_189 ; V_33 ++ )
V_187 [ V_33 ] = F_53 ( V_8 -> V_9 + V_191 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_91 ( ( unsigned long * ) V_187 ,
V_193 * V_189 , V_4 + 1 ) ;
if ( V_4 == V_193 * V_189 )
break;
V_185 = V_4 / V_193 ;
V_39 = V_4 & ( V_193 - 1 ) ;
if ( V_191 [ V_185 ] . V_194 == V_7 )
V_3 = V_8 -> V_195 [ V_39 ] ;
else
V_3 = V_8 -> V_196 [ V_191 [ V_185 ] . V_194 + V_39 ] ;
if ( ! V_3 ) {
continue;
}
F_30 ( F_92 ( V_39 ) , V_8 -> V_9 + V_191 [ V_185 ] . V_197 ) ;
F_93 ( & V_3 -> V_37 ) ;
if ( ! V_191 [ V_185 ] . V_198 )
F_86 ( V_3 ) ;
else
F_94 ( V_8 -> V_5 , L_5 ,
V_4 , V_191 [ V_185 ] . V_194 , V_39 ) ;
F_95 ( & V_3 -> V_37 ) ;
}
F_15 ( & V_8 -> V_192 , V_32 ) ;
return V_199 ;
}
static int F_96 ( struct V_2 * V_3 ,
struct V_200 * V_201 )
{
int V_172 = 0 ;
bool V_17 = V_201 -> V_202 == V_203 ;
if ( ! V_201 -> V_78 ) {
F_58 ( V_3 , L_6 ) ;
V_172 = - V_35 ;
}
if ( ( V_17 && V_201 -> V_130 > V_3 -> V_8 -> V_204 ) ||
( ! V_17 && V_201 -> V_130 > V_3 -> V_8 -> V_205 ) ||
( V_201 -> V_130 < 0 ) ) {
F_58 ( V_3 , L_7 , V_201 -> V_130 ) ;
V_172 = - V_35 ;
}
if ( V_201 -> V_78 == V_131 ) {
F_58 ( V_3 , L_8 ) ;
V_172 = - V_35 ;
}
if ( F_43 ( V_17 , V_201 -> V_206 . V_89 ) *
V_201 -> V_206 . V_167 !=
F_43 ( V_17 , V_201 -> V_166 . V_89 ) *
V_201 -> V_166 . V_167 ) {
F_58 ( V_3 , L_9 ) ;
V_172 = - V_35 ;
}
return V_172 ;
}
static bool F_97 ( struct V_207 * V_208 ,
bool V_209 , int V_210 , bool V_17 ,
bool * V_211 )
{
unsigned long V_32 ;
F_14 ( & V_208 -> V_37 , V_32 ) ;
* V_211 = ( ( V_208 -> V_212 | V_208 -> V_213 )
== V_214 ) ;
if ( ! V_17 ) {
if ( V_208 -> V_212 == V_214 &&
V_208 -> V_213 == V_214 ) {
V_208 -> V_213 = V_215 ;
V_208 -> V_212 = V_215 ;
goto V_216;
} else
goto V_217;
}
if ( V_209 ) {
if ( V_208 -> V_212 == V_215 )
goto V_217;
if ( V_208 -> V_212 == V_214 )
V_208 -> V_212 = V_218 ;
if ( ! ( V_208 -> V_212 & F_92 ( V_210 ) ) ) {
V_208 -> V_212 |= F_92 ( V_210 ) ;
goto V_216;
} else
goto V_217;
} else {
if ( V_208 -> V_213 == V_215 )
goto V_217;
if ( V_208 -> V_213 == V_214 )
V_208 -> V_213 = V_218 ;
if ( ! ( V_208 -> V_213 & F_92 ( V_210 ) ) ) {
V_208 -> V_213 |= F_92 ( V_210 ) ;
goto V_216;
} else
goto V_217;
}
V_217:
F_15 ( & V_208 -> V_37 , V_32 ) ;
return false ;
V_216:
F_15 ( & V_208 -> V_37 , V_32 ) ;
return true ;
}
static bool F_98 ( struct V_207 * V_208 , bool V_209 ,
int V_210 )
{
unsigned long V_32 ;
bool V_219 = false ;
F_14 ( & V_208 -> V_37 , V_32 ) ;
if ( ! V_210 ) {
V_208 -> V_213 = V_214 ;
V_208 -> V_212 = V_214 ;
V_219 = true ;
goto V_82;
}
if ( V_209 ) {
V_208 -> V_212 &= ~ F_92 ( V_210 ) ;
if ( V_208 -> V_212 == V_218 )
V_208 -> V_212 = V_214 ;
} else {
V_208 -> V_213 &= ~ F_92 ( V_210 ) ;
if ( V_208 -> V_213 == V_218 )
V_208 -> V_213 = V_214 ;
}
V_219 = ( ( V_208 -> V_212 | V_208 -> V_213 ) ==
V_214 ) ;
V_82:
F_15 ( & V_208 -> V_37 , V_32 ) ;
return V_219 ;
}
static int F_99 ( struct V_2 * V_3 , bool * V_220 )
{
int V_130 = V_3 -> V_77 . V_130 ;
int V_221 ;
int V_222 ;
struct V_207 * V_223 ;
int V_33 ;
int V_224 ;
int V_6 ;
int V_205 ;
bool V_209 ;
bool V_17 = V_3 -> V_77 . V_202 == V_203 ;
V_223 = V_3 -> V_8 -> V_225 ;
V_205 = V_3 -> V_8 -> V_205 ;
if ( V_3 -> V_77 . V_78 == V_79 ) {
V_6 = 2 * V_130 ;
V_209 = true ;
} else if ( V_3 -> V_77 . V_78 == V_226 ||
V_3 -> V_77 . V_78 == V_227 ) {
V_6 = 2 * V_130 + 1 ;
V_209 = false ;
} else
return - V_35 ;
V_221 = F_100 ( V_130 ) ;
V_222 = F_68 ( V_130 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_77 . V_78 == V_227 ) {
if ( V_3 -> V_77 . V_228 ) {
V_33 = V_3 -> V_77 . V_229 ;
if ( F_97 ( & V_223 [ V_33 ] , V_209 ,
0 , V_17 ,
V_220 ) )
goto V_230;
} else {
for ( V_33 = 0 ; V_33 < V_205 ; V_33 ++ ) {
if ( F_97 ( & V_223 [ V_33 ] , V_209 ,
0 , V_17 ,
V_220 ) )
goto V_230;
}
}
} else
for ( V_224 = 0 ; V_224 < V_3 -> V_8 -> V_205 ; V_224 += 8 ) {
int V_231 = V_224 + V_221 * 2 ;
for ( V_33 = V_231 ; V_33 < V_231 + 2 ; V_33 ++ ) {
if ( F_97 ( & V_223 [ V_33 ] ,
V_209 ,
0 ,
V_17 ,
V_220 ) )
goto V_230;
}
}
return - V_35 ;
V_230:
V_3 -> V_11 = & V_223 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_82;
}
if ( V_130 == - 1 )
return - V_35 ;
for ( V_224 = 0 ; V_224 < V_3 -> V_8 -> V_205 ; V_224 += 8 ) {
int V_231 = V_224 + V_221 * 2 ;
if ( V_3 -> V_77 . V_228 ) {
V_33 = V_3 -> V_77 . V_229 ;
if ( ( V_33 != V_231 ) && ( V_33 != V_231 + 1 ) ) {
F_101 ( F_1 ( V_3 ) ,
L_10 , V_33 ) ;
return - V_35 ;
}
if ( F_97 ( & V_223 [ V_33 ] , V_209 , V_222 ,
V_17 , V_220 ) )
goto V_232;
F_101 ( F_1 ( V_3 ) ,
L_11 , V_33 ) ;
return - V_35 ;
}
if ( V_209 ) {
for ( V_33 = V_231 ; V_33 < V_231 + 2 ; V_33 ++ ) {
if ( F_97 ( & V_223 [ V_33 ] , V_209 ,
V_222 , V_17 ,
V_220 ) )
goto V_232;
}
} else {
for ( V_33 = V_231 + 1 ; V_33 >= V_231 ; V_33 -- ) {
if ( F_97 ( & V_223 [ V_33 ] , V_209 ,
V_222 , V_17 ,
V_220 ) )
goto V_232;
}
}
}
return - V_35 ;
V_232:
V_3 -> V_11 = & V_223 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_82:
if ( V_17 )
V_3 -> V_8 -> V_196 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_195 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
T_6 V_233 = V_3 -> V_4 . V_1 -> V_234 ;
if ( F_103 ( V_235 , V_233 ) && ! F_103 ( V_236 , V_233 ) ) {
V_3 -> V_77 = V_237 ;
V_3 -> V_77 . V_130 = V_238 [ V_3 -> V_4 . V_239 ] ;
F_104 ( & V_3 -> V_77 ,
& V_3 -> V_240 . V_241 , & V_3 -> V_240 . V_169 ) ;
} else if ( F_103 ( V_235 , V_233 ) &&
F_103 ( V_236 , V_233 ) ) {
V_3 -> V_77 = V_242 ;
V_3 -> V_159 |= F_92 ( V_243 ) ;
V_3 -> V_158 |= F_92 ( V_244 ) ;
V_3 -> V_159 |= F_92 ( V_244 ) ;
} else {
F_58 ( V_3 , L_12 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_105 ( struct V_2 * V_3 )
{
int V_172 = 0 ;
T_2 V_121 = F_68 ( V_3 -> V_77 . V_130 ) ;
struct V_207 * V_208 = V_3 -> V_11 ;
bool V_209 ;
F_60 ( V_3 ) ;
if ( V_208 == NULL ) {
F_58 ( V_3 , L_13 ) ;
return - V_35 ;
}
if ( V_208 -> V_212 == V_214 &&
V_208 -> V_213 == V_214 ) {
F_58 ( V_3 , L_14 ) ;
return - V_35 ;
}
if ( V_3 -> V_77 . V_78 == V_226 ||
V_3 -> V_77 . V_78 == V_227 )
V_209 = false ;
else if ( V_3 -> V_77 . V_78 == V_79 )
V_209 = true ;
else {
F_58 ( V_3 , L_15 ) ;
return - V_35 ;
}
F_77 ( V_3 -> V_8 -> V_5 ) ;
V_172 = F_71 ( V_3 , V_109 ) ;
if ( V_172 ) {
F_58 ( V_3 , L_16 ) ;
goto V_82;
}
F_98 ( V_208 , V_209 , F_3 ( V_3 ) ? V_121 : 0 ) ;
if ( F_3 ( V_3 ) )
V_3 -> V_8 -> V_196 [ V_3 -> V_6 ] = NULL ;
else
V_3 -> V_8 -> V_195 [ V_208 -> V_12 ] = NULL ;
if ( V_3 -> V_173 ) {
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_173 = false ;
V_3 -> V_11 = NULL ;
V_3 -> V_245 = false ;
V_82:
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
return V_172 ;
}
static bool F_106 ( struct V_2 * V_3 )
{
void T_1 * V_132 = F_4 ( V_3 ) ;
bool V_246 = false ;
unsigned long V_32 ;
void T_1 * V_107 ;
T_2 V_106 ;
T_2 V_121 = F_68 ( V_3 -> V_77 . V_130 ) ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
if ( F_2 ( V_3 ) ) {
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_107 = V_3 -> V_8 -> V_9 + V_112 ;
else
V_107 = V_3 -> V_8 -> V_9 + V_113 ;
V_106 = ( F_53 ( V_107 ) &
F_54 ( V_3 -> V_11 -> V_12 ) ) >>
F_55 ( V_3 -> V_11 -> V_12 ) ;
if ( V_106 == V_114 || V_106 == V_109 )
V_246 = true ;
goto V_247;
}
if ( V_3 -> V_77 . V_78 == V_226 ||
V_3 -> V_77 . V_78 == V_227 ) {
V_106 = F_53 ( V_132 + V_63 ) ;
} else if ( V_3 -> V_77 . V_78 == V_79 ) {
V_106 = F_53 ( V_132 + V_59 ) ;
} else {
F_58 ( V_3 , L_15 ) ;
goto V_247;
}
V_106 = ( V_106 & F_63 ( V_121 ) ) >>
F_62 ( V_121 ) ;
if ( V_106 != V_135 )
V_246 = true ;
V_247:
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_246 ;
}
static T_2 F_107 ( struct V_248 * V_4 )
{
struct V_2 * V_3 =
F_82 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_249 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_249 = F_74 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_249 ;
}
static int
F_108 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_250 , struct V_99 * V_251 ,
unsigned int V_101 , T_7 V_252 ,
T_7 V_253 )
{
struct V_200 * V_254 = & V_4 -> V_77 ;
struct V_255 * V_206 = & V_254 -> V_206 ;
struct V_255 * V_166 = & V_254 -> V_166 ;
int V_34 ;
V_34 = F_109 ( V_250 , V_101 ,
V_252 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_240 . V_241 ,
V_206 -> V_167 ,
V_166 -> V_167 ) ;
V_34 = F_109 ( V_251 , V_101 ,
V_253 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_240 . V_169 ,
V_166 -> V_167 ,
V_206 -> V_167 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_110 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_250 , struct V_99 * V_251 ,
unsigned int V_101 , T_7 V_252 ,
T_7 V_253 )
{
struct V_200 * V_254 = & V_4 -> V_77 ;
struct V_255 * V_206 = & V_254 -> V_206 ;
struct V_255 * V_166 = & V_254 -> V_166 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_70 )
V_32 |= V_256 | V_80 ;
V_34 = F_111 ( V_250 , V_101 , V_252 ,
V_43 -> V_30 . V_27 ,
F_112 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_158 ,
V_206 , V_166 , V_32 ) ;
V_34 = F_111 ( V_251 , V_101 , V_253 ,
V_43 -> V_30 . V_28 ,
F_112 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_159 ,
V_166 , V_206 , V_32 ) ;
F_113 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_114 ( struct V_2 * V_4 , struct V_99 * V_102 ,
unsigned int V_101 , unsigned long V_257 )
{
struct V_200 * V_254 = & V_4 -> V_77 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_16 = F_49 ( V_102 , V_101 , V_254 -> V_206 . V_167 ,
V_254 -> V_166 . V_167 ) ;
if ( V_43 -> V_16 < 0 ) {
F_58 ( V_4 , L_17 ) ;
goto V_177;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_58 ( V_4 , L_18 ) ;
goto V_177;
}
V_43 -> V_69 = 0 ;
V_43 -> V_47 . V_32 = V_257 ;
V_43 -> V_47 . V_258 = F_81 ;
F_115 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_177:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static struct V_174 *
F_116 ( struct V_248 * V_259 , struct V_99 * V_250 ,
struct V_99 * V_251 , unsigned int V_101 ,
enum V_260 V_261 , unsigned long V_257 )
{
struct V_2 * V_4 = F_82 ( V_259 , struct V_2 , V_4 ) ;
T_7 V_252 = 0 ;
T_7 V_253 = 0 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_58 ( V_4 , L_19 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_37 , V_32 ) ;
V_43 = F_114 ( V_4 , V_250 , V_101 , V_257 ) ;
if ( V_43 == NULL )
goto V_177;
if ( F_117 ( & V_250 [ V_101 - 1 ] ) == V_250 )
V_43 -> V_70 = true ;
if ( V_261 == V_79 )
V_252 = V_4 -> V_262 ;
else if ( V_261 == V_226 )
V_253 = V_4 -> V_262 ;
if ( F_3 ( V_4 ) )
V_34 = F_108 ( V_4 , V_43 , V_250 , V_251 ,
V_101 , V_252 , V_253 ) ;
else
V_34 = F_110 ( V_4 , V_43 , V_250 , V_251 ,
V_101 , V_252 , V_253 ) ;
if ( V_34 ) {
F_58 ( V_4 , L_20 ,
F_3 ( V_4 ) ? L_21 : L_22 , V_34 ) ;
goto V_177;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_117 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return & V_43 -> V_47 ;
V_177:
if ( V_43 )
F_25 ( V_4 , V_43 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return NULL ;
}
bool F_118 ( struct V_248 * V_4 , void * V_179 )
{
struct V_200 * V_263 = V_179 ;
struct V_2 * V_3 =
F_82 ( V_4 , struct V_2 , V_4 ) ;
int V_177 ;
if ( V_179 ) {
V_177 = F_96 ( V_3 , V_263 ) ;
if ( ! V_177 )
V_3 -> V_77 = * V_263 ;
} else
V_177 = F_102 ( V_3 ) ;
if ( ! V_177 )
V_3 -> V_245 = true ;
return V_177 == 0 ;
}
static void F_119 ( struct V_2 * V_3 , int V_130 , bool V_27 )
{
bool V_264 = V_3 -> V_77 . V_264 ;
bool V_265 = V_3 -> V_77 . V_266 ;
T_2 V_267 ;
T_2 V_121 = F_68 ( V_130 ) ;
T_2 V_268 = F_100 ( V_130 ) ;
T_2 V_269 = F_92 ( V_121 ) ;
T_2 V_270 ;
struct V_271 * V_272 = & V_3 -> V_8 -> V_188 ;
V_267 = V_264 ? V_272 -> V_273 : V_272 -> V_274 ;
if ( ! V_27 && F_3 ( V_3 ) )
V_265 = false ;
V_270 = V_265 ? V_272 -> V_275 : V_272 -> V_276 ;
if ( ! V_27 )
V_269 <<= 16 ;
F_30 ( V_269 , V_3 -> V_8 -> V_9 + V_270 + V_268 * 4 ) ;
F_30 ( V_269 , V_3 -> V_8 -> V_9 + V_267 + V_268 * 4 ) ;
}
static void F_120 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_277 < 3 )
return;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_131 ) )
F_119 ( V_3 , V_3 -> V_77 . V_130 , true ) ;
if ( ( V_3 -> V_77 . V_78 == V_226 ) ||
( V_3 -> V_77 . V_78 == V_131 ) )
F_119 ( V_3 , V_3 -> V_77 . V_130 , false ) ;
}
static struct V_248 * F_121 ( struct V_278 * V_279 ,
struct V_280 * V_281 )
{
struct V_200 V_254 ;
T_6 V_233 ;
T_2 V_32 ;
memset ( & V_254 , 0 , sizeof( struct V_200 ) ) ;
F_122 ( V_233 ) ;
F_123 ( V_236 , V_233 ) ;
V_254 . V_130 = V_279 -> args [ 0 ] ;
V_32 = V_279 -> args [ 2 ] ;
switch ( F_124 ( V_32 ) ) {
case 0 : V_254 . V_202 = V_203 ; break;
case 1 : V_254 . V_202 = V_282 ; break;
}
switch ( F_125 ( V_32 ) ) {
case 0 :
V_254 . V_78 = V_226 ;
V_254 . V_166 . V_283 = F_126 ( V_32 ) ;
break;
case 1 :
V_254 . V_78 = V_79 ;
V_254 . V_206 . V_283 = F_126 ( V_32 ) ;
break;
}
if ( F_127 ( V_32 ) ) {
V_254 . V_229 = V_279 -> args [ 1 ] ;
V_254 . V_228 = true ;
}
if ( F_128 ( V_32 ) )
V_254 . V_266 = true ;
return F_129 ( V_233 , F_118 , & V_254 ) ;
}
static int F_130 ( struct V_248 * V_4 )
{
int V_177 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_82 ( V_4 , struct V_2 , V_4 ) ;
bool V_284 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_131 ( V_4 ) ;
if ( ! V_3 -> V_245 ) {
V_177 = F_102 ( V_3 ) ;
if ( V_177 ) {
F_58 ( V_3 , L_23 ) ;
goto V_285;
}
}
V_177 = F_99 ( V_3 , & V_284 ) ;
if ( V_177 ) {
F_58 ( V_3 , L_24 ) ;
V_3 -> V_245 = false ;
goto V_285;
}
F_77 ( V_3 -> V_8 -> V_5 ) ;
F_120 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
if ( V_3 -> V_77 . V_78 == V_79 )
V_3 -> V_81 = V_3 -> V_8 -> V_286 +
V_3 -> V_77 . V_130 * V_287 ;
else
V_3 -> V_81 = V_3 -> V_8 -> V_286 +
V_3 -> V_77 . V_130 *
V_287 + V_288 ;
V_3 -> V_158 |= F_92 ( V_289 ) ;
V_3 -> V_159 |= F_92 ( V_289 ) ;
}
F_64 ( F_1 ( V_3 ) , L_25 ,
F_3 ( V_3 ) ? L_26 : L_27 ,
V_3 -> V_11 -> V_12 ,
V_3 -> V_77 . V_228 ? L_28 : L_29 ) ;
if ( V_284 )
F_73 ( V_3 ) ;
V_285:
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_177 ;
}
static void F_132 ( struct V_248 * V_4 )
{
struct V_2 * V_3 =
F_82 ( V_4 , struct V_2 , V_4 ) ;
int V_177 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_30 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_177 = F_105 ( V_3 ) ;
if ( V_177 )
F_58 ( V_3 , L_31 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static struct V_174 * F_133 ( struct V_248 * V_4 ,
T_7 V_28 ,
T_7 V_27 ,
T_8 V_23 ,
unsigned long V_257 )
{
struct V_99 V_290 ;
struct V_99 V_291 ;
F_134 ( & V_290 , 1 ) ;
F_134 ( & V_291 , 1 ) ;
F_135 ( & V_290 ) = V_28 ;
F_135 ( & V_291 ) = V_27 ;
F_51 ( & V_290 ) = V_23 ;
F_51 ( & V_291 ) = V_23 ;
return F_116 ( V_4 , & V_291 , & V_290 , 1 , V_292 , V_257 ) ;
}
static struct V_174 *
F_136 ( struct V_248 * V_4 ,
struct V_99 * V_290 , unsigned int V_293 ,
struct V_99 * V_291 , unsigned int V_294 ,
unsigned long V_257 )
{
if ( V_293 != V_294 )
return NULL ;
return F_116 ( V_4 , V_291 , V_290 , V_294 , V_292 , V_257 ) ;
}
static struct V_174 *
F_137 ( struct V_248 * V_4 , struct V_99 * V_100 ,
unsigned int V_101 , enum V_260 V_261 ,
unsigned long V_257 , void * V_295 )
{
if ( ! F_138 ( V_261 ) )
return NULL ;
return F_116 ( V_4 , V_100 , V_100 , V_101 , V_261 , V_257 ) ;
}
static struct V_174 *
F_139 ( struct V_248 * V_4 , T_7 V_29 ,
T_8 V_296 , T_8 V_297 ,
enum V_260 V_261 , unsigned long V_32 )
{
unsigned int V_298 = V_296 / V_297 ;
struct V_174 * V_47 ;
struct V_99 * V_102 ;
int V_33 ;
V_102 = F_140 ( V_298 + 1 , sizeof( struct V_99 ) , V_24 ) ;
if ( ! V_102 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_298 ; V_33 ++ ) {
F_135 ( & V_102 [ V_33 ] ) = V_29 ;
F_51 ( & V_102 [ V_33 ] ) = V_297 ;
V_29 += V_297 ;
}
V_102 [ V_298 ] . V_194 = 0 ;
F_51 ( & V_102 [ V_298 ] ) = 0 ;
V_102 [ V_298 ] . V_299 =
( ( unsigned long ) V_102 | 0x01 ) & ~ 0x02 ;
V_47 = F_116 ( V_4 , V_102 , V_102 , V_298 , V_261 ,
V_183 ) ;
F_10 ( V_102 ) ;
return V_47 ;
}
static enum V_300 F_141 ( struct V_248 * V_4 ,
T_3 V_176 ,
struct V_301 * V_302 )
{
struct V_2 * V_3 = F_82 ( V_4 , struct V_2 , V_4 ) ;
enum V_300 V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_32 ) ;
return - V_35 ;
}
V_34 = F_142 ( V_4 , V_176 , V_302 ) ;
if ( V_34 != V_303 )
F_143 ( V_302 , F_107 ( V_4 ) ) ;
if ( F_106 ( V_3 ) )
V_34 = V_304 ;
return V_34 ;
}
static void F_144 ( struct V_248 * V_4 )
{
struct V_2 * V_3 = F_82 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_33 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_145 ( & V_3 -> V_87 , & V_3 -> V_88 ) ;
if ( ! V_3 -> V_173 )
( void ) F_85 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static void F_146 ( struct V_248 * V_4 )
{
unsigned long V_32 ;
struct V_2 * V_3 = F_82 ( V_4 , struct V_2 , V_4 ) ;
int V_34 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_77 ( V_3 -> V_8 -> V_5 ) ;
V_34 = F_71 ( V_3 , V_109 ) ;
if ( V_34 )
F_58 ( V_3 , L_34 ) ;
F_60 ( V_3 ) ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
if ( V_3 -> V_173 ) {
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_173 = false ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static int
F_147 ( struct V_2 * V_3 ,
struct V_255 * V_263 ,
T_2 V_305 )
{
int V_89 ;
if ( F_3 ( V_3 ) ) {
if ( V_305 >= 16 )
V_89 = V_306 ;
else if ( V_305 >= 8 )
V_89 = V_307 ;
else if ( V_305 >= 4 )
V_89 = V_308 ;
else
V_89 = V_90 ;
} else {
if ( V_305 >= 16 )
V_89 = V_309 ;
else if ( V_305 >= 8 )
V_89 = V_310 ;
else if ( V_305 >= 4 )
V_89 = V_311 ;
else
V_89 = V_91 ;
}
V_263 -> V_89 = V_89 ;
V_263 -> V_312 = V_313 ;
return 0 ;
}
static int F_148 ( struct V_248 * V_4 ,
struct V_314 * V_315 )
{
struct V_2 * V_3 = F_82 ( V_4 , struct V_2 , V_4 ) ;
struct V_200 * V_254 = & V_3 -> V_77 ;
enum V_316 V_317 , V_318 ;
T_7 V_319 ;
T_2 V_320 , V_321 ;
int V_34 ;
V_317 = V_315 -> V_317 ;
V_320 = V_315 -> V_320 ;
V_318 = V_315 -> V_318 ;
V_321 = V_315 -> V_321 ;
if ( V_315 -> V_261 == V_79 ) {
V_319 = V_315 -> V_322 ;
if ( V_254 -> V_78 != V_79 )
F_64 ( V_3 -> V_8 -> V_5 ,
L_35
L_36 ,
V_254 -> V_78 ) ;
V_254 -> V_78 = V_79 ;
if ( V_318 == V_323 )
V_318 = V_317 ;
if ( V_321 == 0 )
V_321 = V_320 ;
} else if ( V_315 -> V_261 == V_226 ) {
V_319 = V_315 -> V_324 ;
if ( V_254 -> V_78 != V_226 )
F_64 ( V_3 -> V_8 -> V_5 ,
L_37
L_38 ,
V_254 -> V_78 ) ;
V_254 -> V_78 = V_226 ;
if ( V_317 == V_323 )
V_317 = V_318 ;
if ( V_320 == 0 )
V_320 = V_321 ;
} else {
F_101 ( V_3 -> V_8 -> V_5 ,
L_39 ,
V_315 -> V_261 ) ;
return - V_35 ;
}
if ( V_319 <= 0 ) {
F_101 ( V_3 -> V_8 -> V_5 , L_40 ) ;
return - V_35 ;
}
if ( V_320 * V_317 != V_321 * V_318 ) {
F_101 ( V_3 -> V_8 -> V_5 ,
L_41 ,
V_320 ,
V_317 ,
V_321 ,
V_318 ) ;
return - V_35 ;
}
if ( V_320 > 16 ) {
V_320 = 16 ;
V_321 = V_320 * V_317 / V_318 ;
} else if ( V_321 > 16 ) {
V_321 = 16 ;
V_320 = V_321 * V_318 / V_317 ;
}
if ( V_317 <= V_323 ||
V_317 > V_325 ||
V_318 <= V_323 ||
V_318 > V_325 ||
! F_149 ( V_317 ) ||
! F_149 ( V_318 ) )
return - V_35 ;
V_254 -> V_206 . V_167 = V_317 ;
V_254 -> V_166 . V_167 = V_318 ;
V_34 = F_147 ( V_3 , & V_254 -> V_206 ,
V_320 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_147 ( V_3 , & V_254 -> V_166 ,
V_321 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_104 ( V_254 , & V_3 -> V_240 . V_241 , & V_3 -> V_240 . V_169 ) ;
else
F_150 ( V_254 , & V_3 -> V_158 , & V_3 -> V_159 ) ;
V_3 -> V_262 = V_319 ;
V_3 -> V_326 = V_315 -> V_261 ;
F_64 ( V_3 -> V_8 -> V_5 ,
L_42
L_43 ,
F_151 ( V_4 ) ,
( V_315 -> V_261 == V_79 ) ? L_44 : L_45 ,
V_317 , V_318 ,
V_320 , V_321 ) ;
return 0 ;
}
static int F_152 ( struct V_248 * V_4 , enum V_327 V_328 ,
unsigned long V_329 )
{
struct V_2 * V_3 = F_82 ( V_4 , struct V_2 , V_4 ) ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_33 ) ;
return - V_35 ;
}
switch ( V_328 ) {
case V_330 :
F_146 ( V_4 ) ;
return 0 ;
case V_331 :
return F_76 ( V_3 ) ;
case V_332 :
return F_80 ( V_3 ) ;
case V_333 :
return F_148 ( V_4 ,
(struct V_314 * ) V_329 ) ;
default:
break;
}
return - V_334 ;
}
static void T_9 F_153 ( struct V_186 * V_8 , struct V_335 * V_336 ,
struct V_2 * V_337 , int V_194 ,
int V_338 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_336 -> V_339 ) ;
for ( V_33 = V_194 ; V_33 < V_194 + V_338 ; V_33 ++ ) {
V_3 = & V_337 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_336 ;
F_154 ( & V_3 -> V_37 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_64 ) ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_88 ) ;
F_24 ( & V_3 -> V_87 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_117 ) ;
F_155 ( & V_3 -> V_178 , F_88 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_340 ,
& V_336 -> V_339 ) ;
}
}
static void F_156 ( struct V_186 * V_8 , struct V_335 * V_5 )
{
if ( F_103 ( V_236 , V_5 -> V_234 ) )
V_5 -> V_341 = F_137 ;
if ( F_103 ( V_235 , V_5 -> V_234 ) ) {
V_5 -> V_342 = F_133 ;
V_5 -> V_343 = 2 ;
}
if ( F_103 ( V_344 , V_5 -> V_234 ) )
V_5 -> V_345 = F_136 ;
if ( F_103 ( V_346 , V_5 -> V_234 ) )
V_5 -> V_347 = F_139 ;
V_5 -> V_348 = F_130 ;
V_5 -> V_349 = F_132 ;
V_5 -> V_350 = F_144 ;
V_5 -> V_351 = F_141 ;
V_5 -> V_352 = F_152 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_9 F_157 ( struct V_186 * V_8 ,
int V_353 )
{
int V_177 ;
F_153 ( V_8 , & V_8 -> V_354 , V_8 -> V_355 ,
0 , V_8 -> V_204 ) ;
F_122 ( V_8 -> V_354 . V_234 ) ;
F_123 ( V_236 , V_8 -> V_354 . V_234 ) ;
F_123 ( V_346 , V_8 -> V_354 . V_234 ) ;
F_156 ( V_8 , & V_8 -> V_354 ) ;
V_177 = F_158 ( & V_8 -> V_354 ) ;
if ( V_177 ) {
F_94 ( V_8 -> V_5 , L_46 ) ;
goto V_356;
}
F_153 ( V_8 , & V_8 -> V_357 , V_8 -> V_355 ,
V_8 -> V_204 , V_8 -> V_358 ) ;
F_122 ( V_8 -> V_357 . V_234 ) ;
F_123 ( V_235 , V_8 -> V_357 . V_234 ) ;
F_123 ( V_344 , V_8 -> V_357 . V_234 ) ;
F_156 ( V_8 , & V_8 -> V_357 ) ;
V_177 = F_158 ( & V_8 -> V_357 ) ;
if ( V_177 ) {
F_94 ( V_8 -> V_5 ,
L_47 ) ;
goto V_359;
}
F_153 ( V_8 , & V_8 -> V_360 , V_8 -> V_361 ,
0 , V_353 ) ;
F_122 ( V_8 -> V_360 . V_234 ) ;
F_123 ( V_236 , V_8 -> V_360 . V_234 ) ;
F_123 ( V_235 , V_8 -> V_360 . V_234 ) ;
F_123 ( V_344 , V_8 -> V_360 . V_234 ) ;
F_123 ( V_346 , V_8 -> V_354 . V_234 ) ;
F_156 ( V_8 , & V_8 -> V_360 ) ;
V_177 = F_158 ( & V_8 -> V_360 ) ;
if ( V_177 ) {
F_94 ( V_8 -> V_5 ,
L_48 ) ;
goto V_362;
}
return 0 ;
V_362:
F_159 ( & V_8 -> V_357 ) ;
V_359:
F_159 ( & V_8 -> V_354 ) ;
V_356:
return V_177 ;
}
static int F_160 ( struct V_1 * V_5 )
{
struct V_363 * V_364 = F_161 ( V_5 ) ;
struct V_186 * V_8 = F_162 ( V_364 ) ;
int V_34 ;
V_34 = F_163 ( V_5 ) ;
if ( V_34 )
return V_34 ;
if ( V_8 -> V_365 )
V_34 = F_164 ( V_8 -> V_365 ) ;
return V_34 ;
}
static int F_165 ( struct V_1 * V_5 )
{
struct V_363 * V_364 = F_161 ( V_5 ) ;
struct V_186 * V_8 = F_162 ( V_364 ) ;
int V_34 = 0 ;
if ( V_8 -> V_365 ) {
V_34 = F_166 ( V_8 -> V_365 ) ;
if ( V_34 )
return V_34 ;
}
return F_167 ( V_5 ) ;
}
static void F_168 ( void T_1 * V_366 , T_2 * V_367 ,
T_2 * V_368 , int V_12 , bool V_369 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ ) {
void T_1 * V_123 = V_366 + V_368 [ V_33 ] ;
if ( V_369 )
V_367 [ V_33 ] = F_169 ( V_123 ) ;
else
F_170 ( V_367 [ V_33 ] , V_123 ) ;
}
}
static void F_171 ( struct V_186 * V_8 , bool V_369 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_8 -> V_205 ; V_33 ++ ) {
void T_1 * V_123 ;
int V_39 ;
if ( V_8 -> V_225 [ V_33 ] . V_370 )
continue;
V_123 = V_8 -> V_9 + V_10 + V_33 * V_13 ;
V_39 = V_33 * F_172 ( V_371 ) ;
F_168 ( V_123 , & V_8 -> V_372 [ V_39 ] ,
V_371 ,
F_172 ( V_371 ) ,
V_369 ) ;
}
F_168 ( V_8 -> V_9 , V_8 -> V_373 ,
V_374 , F_172 ( V_374 ) ,
V_369 ) ;
if ( V_8 -> V_188 . V_367 )
F_168 ( V_8 -> V_9 , V_8 -> V_375 ,
V_8 -> V_188 . V_367 ,
V_8 -> V_188 . V_376 ,
V_369 ) ;
}
static int F_173 ( struct V_1 * V_5 )
{
struct V_363 * V_364 = F_161 ( V_5 ) ;
struct V_186 * V_8 = F_162 ( V_364 ) ;
F_171 ( V_8 , true ) ;
if ( V_8 -> V_277 != 1 )
F_170 ( V_8 -> V_377 ,
V_8 -> V_9 + V_378 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_5 )
{
struct V_363 * V_364 = F_161 ( V_5 ) ;
struct V_186 * V_8 = F_162 ( V_364 ) ;
F_171 ( V_8 , false ) ;
F_170 ( V_379 ,
V_8 -> V_9 + V_378 ) ;
return 0 ;
}
static int T_9 F_175 ( struct V_186 * V_8 )
{
int V_33 ;
int V_380 = 0 ;
T_2 V_133 [ 2 ] ;
int V_381 = - 2 ;
int V_382 = V_383 ;
V_133 [ 0 ] = F_53 ( V_8 -> V_9 + V_384 ) ;
V_133 [ 1 ] = F_53 ( V_8 -> V_9 + V_385 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_205 ; V_33 ++ ) {
V_8 -> V_225 [ V_33 ] . V_12 = V_33 ;
V_381 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_133 [ V_33 % 2 ] >> V_381 ) & 3 ) == 1 ) {
V_8 -> V_225 [ V_33 ] . V_212 = V_215 ;
V_8 -> V_225 [ V_33 ] . V_213 = V_215 ;
V_8 -> V_225 [ V_33 ] . V_370 = true ;
V_382 |= F_176 ( F_177 ( V_33 ) ,
V_386 ) ;
V_382 |= F_176 ( F_177 ( V_33 ) ,
V_387 ) ;
} else {
V_8 -> V_225 [ V_33 ] . V_212 = V_214 ;
V_8 -> V_225 [ V_33 ] . V_213 = V_214 ;
V_8 -> V_225 [ V_33 ] . V_370 = false ;
V_380 ++ ;
}
F_154 ( & V_8 -> V_225 [ V_33 ] . V_37 ) ;
}
for ( V_33 = 0 ; V_8 -> V_74 -> V_388 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_388 [ V_33 ] ;
V_8 -> V_225 [ V_4 ] . V_212 = V_215 ;
V_8 -> V_225 [ V_4 ] . V_213 = V_215 ;
V_8 -> V_225 [ V_4 ] . V_370 = true ;
V_382 |= F_176 ( F_177 ( V_4 ) ,
V_386 ) ;
V_382 |= F_176 ( F_177 ( V_4 ) ,
V_387 ) ;
V_380 -- ;
}
for ( V_33 = 0 ; V_33 < V_8 -> V_74 -> V_389 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_390 [ V_33 ] ;
V_8 -> V_225 [ V_4 ] . V_76 = true ;
}
F_178 ( V_8 -> V_5 , L_49 ,
V_380 , V_8 -> V_205 ) ;
V_133 [ 0 ] = F_53 ( V_8 -> V_9 + V_391 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_205 ; V_33 ++ ) {
if ( V_8 -> V_225 [ V_33 ] . V_212 == V_214 &&
( V_133 [ 0 ] & 0x3 ) != 1 )
F_178 ( V_8 -> V_5 ,
L_50 ,
V_128 , V_33 , V_133 [ 0 ] & 0x3 ) ;
V_133 [ 0 ] = V_133 [ 0 ] >> 2 ;
}
F_30 ( V_379 , V_8 -> V_9 + V_378 ) ;
V_8 -> V_377 = V_382 ;
return V_380 ;
}
static struct V_186 * T_9 F_179 ( struct V_363 * V_364 )
{
struct V_392 * V_74 = F_180 ( & V_364 -> V_5 ) ;
struct V_393 * V_393 = NULL ;
void T_1 * V_9 = NULL ;
struct V_394 * V_172 = NULL ;
struct V_186 * V_8 = NULL ;
int V_204 = 0 ;
int V_205 ;
int V_358 ;
int V_395 = - V_35 ;
int V_33 ;
T_2 V_396 ;
T_2 V_397 ;
T_10 V_277 ;
V_393 = F_181 ( & V_364 -> V_5 , NULL ) ;
if ( F_182 ( V_393 ) ) {
F_94 ( & V_364 -> V_5 , L_51 ) ;
goto V_398;
}
V_395 = F_183 ( V_393 ) ;
if ( V_395 ) {
F_94 ( & V_364 -> V_5 , L_52 ) ;
goto V_398;
}
V_172 = F_184 ( V_364 , V_399 , L_53 ) ;
if ( ! V_172 )
goto V_398;
if ( F_185 ( V_172 -> V_400 , F_186 ( V_172 ) ,
V_401 L_54 ) == NULL )
goto V_398;
V_9 = F_187 ( V_172 -> V_400 , F_186 ( V_172 ) ) ;
if ( ! V_9 )
goto V_398;
for ( V_396 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_396 |= ( F_53 ( V_9 + F_186 ( V_172 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_397 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_397 |= ( F_53 ( V_9 + F_186 ( V_172 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_397 != V_402 ) {
F_94 ( & V_364 -> V_5 , L_55 ) ;
goto V_398;
}
if ( F_188 ( V_396 ) != V_403 ) {
F_94 ( & V_364 -> V_5 , L_56 ,
F_188 ( V_396 ) ,
V_403 ) ;
goto V_398;
}
V_277 = F_189 ( V_396 ) ;
if ( V_277 < 2 ) {
F_94 ( & V_364 -> V_5 , L_57 , V_277 ) ;
goto V_398;
}
if ( V_74 -> V_404 )
V_205 = V_74 -> V_404 ;
else
V_205 = 4 * ( F_53 ( V_9 + V_405 ) & 0x7 ) + 4 ;
if ( V_74 -> V_406 )
V_358 = V_74 -> V_406 ;
else
V_358 = F_172 ( V_238 ) ;
V_204 = V_205 * V_407 ;
F_178 ( & V_364 -> V_5 ,
L_58 ,
V_277 , & V_172 -> V_400 , V_205 , V_204 ) ;
V_8 = F_190 ( F_47 ( sizeof( struct V_186 ) , 4 ) +
( V_205 + V_204 + V_358 ) *
sizeof( struct V_2 ) , V_408 ) ;
if ( V_8 == NULL ) {
F_94 ( & V_364 -> V_5 , L_59 ) ;
goto V_398;
}
V_8 -> V_277 = V_277 ;
V_8 -> V_393 = V_393 ;
V_8 -> V_358 = V_358 ;
V_8 -> V_205 = V_205 ;
V_8 -> V_204 = V_204 ;
V_8 -> V_409 = V_172 -> V_400 ;
V_8 -> V_410 = F_186 ( V_172 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_5 = & V_364 -> V_5 ;
V_8 -> V_361 = ( ( void * ) V_8 ) + F_47 ( sizeof( struct V_186 ) , 4 ) ;
V_8 -> V_355 = & V_8 -> V_361 [ V_205 ] ;
if ( V_8 -> V_74 -> V_404 == 14 ) {
V_8 -> V_188 . V_367 = V_411 ;
V_8 -> V_188 . V_376 = V_412 ;
V_8 -> V_188 . V_413 = V_414 ;
V_8 -> V_188 . V_415 = V_416 ;
V_8 -> V_188 . V_273 = V_417 ;
V_8 -> V_188 . V_274 = V_418 ;
V_8 -> V_188 . V_275 = V_419 ;
V_8 -> V_188 . V_276 = V_420 ;
V_8 -> V_188 . V_191 = V_421 ;
V_8 -> V_188 . V_189 = F_172 ( V_421 ) ;
V_8 -> V_188 . V_422 = V_423 ;
V_8 -> V_188 . V_424 = F_172 ( V_423 ) ;
} else {
if ( V_8 -> V_277 >= 3 ) {
V_8 -> V_188 . V_367 = V_425 ;
V_8 -> V_188 . V_376 = V_426 ;
}
V_8 -> V_188 . V_413 = V_427 ;
V_8 -> V_188 . V_415 = V_428 ;
V_8 -> V_188 . V_273 = V_429 ;
V_8 -> V_188 . V_274 = V_430 ;
V_8 -> V_188 . V_275 = V_431 ;
V_8 -> V_188 . V_276 = V_432 ;
V_8 -> V_188 . V_191 = V_433 ;
V_8 -> V_188 . V_189 = F_172 ( V_433 ) ;
V_8 -> V_188 . V_422 = V_434 ;
V_8 -> V_188 . V_424 = F_172 ( V_434 ) ;
}
V_8 -> V_225 = F_190 ( V_205 * sizeof( struct V_207 ) ,
V_408 ) ;
if ( ! V_8 -> V_225 )
goto V_398;
V_8 -> V_195 = F_190 ( V_205 *
sizeof( struct V_2 * ) ,
V_408 ) ;
if ( ! V_8 -> V_195 )
goto V_398;
V_8 -> V_196 = F_190 ( V_204 *
sizeof( struct V_2 * ) ,
V_408 ) ;
if ( ! V_8 -> V_196 )
goto V_398;
V_8 -> V_372 = F_6 ( V_8 -> V_205 *
sizeof( V_371 ) ,
V_408 ) ;
if ( ! V_8 -> V_372 )
goto V_398;
V_8 -> V_36 . V_40 =
F_190 ( V_205 * sizeof( struct V_14 * )
* V_38 , V_408 ) ;
if ( ! V_8 -> V_36 . V_40 )
goto V_398;
V_8 -> V_48 = F_191 ( V_401 , sizeof( struct V_14 ) ,
0 , V_435 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_398;
return V_8 ;
V_398:
if ( ! V_395 )
F_192 ( V_393 ) ;
if ( ! F_182 ( V_393 ) )
F_193 ( V_393 ) ;
if ( V_9 )
F_194 ( V_9 ) ;
if ( V_172 )
F_195 ( V_172 -> V_400 ,
F_186 ( V_172 ) ) ;
if ( V_9 )
F_194 ( V_9 ) ;
if ( V_8 ) {
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_372 ) ;
F_10 ( V_8 -> V_196 ) ;
F_10 ( V_8 -> V_195 ) ;
F_10 ( V_8 -> V_225 ) ;
F_10 ( V_8 ) ;
}
return NULL ;
}
static void T_9 F_196 ( struct V_186 * V_8 )
{
int V_33 ;
T_2 V_436 [ 2 ] = { 0 , 0 } ;
T_2 V_437 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_438 = 0 ;
T_2 V_439 = 0 ;
struct V_440 * V_441 = V_8 -> V_188 . V_422 ;
T_2 V_442 = V_8 -> V_188 . V_424 ;
for ( V_33 = 0 ; V_33 < V_442 ; V_33 ++ )
F_30 ( V_441 [ V_33 ] . V_133 ,
V_8 -> V_9 + V_441 [ V_33 ] . V_122 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_205 ; V_33 ++ ) {
V_437 [ V_33 % 2 ] = V_437 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_225 [ V_8 -> V_205 - V_33 - 1 ] . V_212
== V_215 ) {
V_437 [ V_33 % 2 ] |= 3 ;
continue;
}
V_438 = ( V_438 << 1 ) | 1 ;
V_439 = ( V_439 << 1 ) | 1 ;
V_436 [ V_33 % 2 ] = V_436 [ V_33 % 2 ] << 2 ;
V_436 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_436 [ 1 ] , V_8 -> V_9 + V_153 ) ;
F_30 ( V_436 [ 0 ] , V_8 -> V_9 + V_443 ) ;
F_30 ( V_437 [ 1 ] , V_8 -> V_9 + V_112 ) ;
F_30 ( V_437 [ 0 ] , V_8 -> V_9 + V_113 ) ;
F_30 ( V_438 , V_8 -> V_9 + V_8 -> V_188 . V_413 ) ;
F_30 ( V_439 , V_8 -> V_9 + V_8 -> V_188 . V_415 ) ;
V_8 -> V_188 . V_422 = NULL ;
V_8 -> V_188 . V_424 = 0 ;
}
static int T_9 F_197 ( struct V_186 * V_8 )
{
struct V_65 * V_66 = & V_8 -> V_36 ;
unsigned long * V_444 ;
int V_33 , V_224 ;
int V_34 = 0 ;
V_444 = F_6 ( sizeof( unsigned long ) * V_445 ,
V_408 ) ;
if ( ! V_444 ) {
V_34 = - V_25 ;
goto V_398;
}
V_8 -> V_36 . V_446 = V_447 * V_8 -> V_205 / V_448 ;
for ( V_33 = 0 ; V_33 < V_445 ; V_33 ++ ) {
V_444 [ V_33 ] = F_198 ( V_408 ,
V_8 -> V_36 . V_446 ) ;
if ( ! V_444 [ V_33 ] ) {
F_94 ( V_8 -> V_5 , L_60 ,
V_8 -> V_36 . V_446 ) ;
for ( V_224 = 0 ; V_224 < V_33 ; V_224 ++ )
F_199 ( V_444 [ V_224 ] , V_8 -> V_36 . V_446 ) ;
goto V_398;
}
if ( ( F_112 ( ( void * ) V_444 [ V_33 ] ) &
( V_449 - 1 ) ) == 0 )
break;
}
for ( V_224 = 0 ; V_224 < V_33 ; V_224 ++ )
F_199 ( V_444 [ V_224 ] , V_8 -> V_36 . V_446 ) ;
if ( V_33 < V_445 ) {
V_8 -> V_36 . V_8 = ( void * ) V_444 [ V_33 ] ;
} else {
F_200 ( V_8 -> V_5 ,
L_61 ,
V_128 , V_8 -> V_36 . V_446 ) ;
V_8 -> V_36 . V_450 = F_6 ( V_447 *
V_8 -> V_205 +
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
V_447 * V_8 -> V_205 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_66 -> V_29 ) ) {
V_66 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_398;
}
F_30 ( F_112 ( V_8 -> V_36 . V_8 ) ,
V_8 -> V_9 + V_451 ) ;
V_398:
F_10 ( V_444 ) ;
return V_34 ;
}
static int T_9 F_201 ( struct V_363 * V_364 ,
struct V_340 * V_452 )
{
struct V_392 * V_453 ;
int V_454 = 0 , V_455 = 0 , V_456 = 0 ;
const T_11 * V_457 ;
V_453 = F_202 ( & V_364 -> V_5 ,
sizeof( struct V_392 ) ,
V_408 ) ;
if ( ! V_453 )
return - V_25 ;
F_203 ( V_452 , L_62 , & V_454 ) ;
if ( V_454 > 0 )
V_453 -> V_404 = V_454 ;
V_457 = F_204 ( V_452 , L_63 , & V_455 ) ;
V_455 /= sizeof( * V_457 ) ;
if ( V_455 > V_458 || V_455 <= 0 ) {
F_94 ( & V_364 -> V_5 ,
L_64 ,
V_455 ) ;
return - V_35 ;
}
V_453 -> V_406 = V_455 ;
F_205 ( V_452 , L_63 ,
V_238 ,
V_455 ) ;
V_457 = F_204 ( V_452 , L_65 , & V_456 ) ;
V_456 /= sizeof( * V_457 ) ;
if ( V_456 >= V_459 || V_456 < 0 ) {
F_94 ( & V_364 -> V_5 ,
L_66 ,
V_456 ) ;
return - V_35 ;
}
F_205 ( V_452 , L_65 ,
V_453 -> V_388 ,
V_456 ) ;
V_453 -> V_388 [ V_456 ] = - 1 ;
V_364 -> V_5 . V_460 = V_453 ;
return 0 ;
}
static int T_9 F_206 ( struct V_363 * V_364 )
{
struct V_392 * V_74 = F_180 ( & V_364 -> V_5 ) ;
struct V_340 * V_452 = V_364 -> V_5 . V_461 ;
int V_34 = - V_462 ;
struct V_186 * V_8 = NULL ;
struct V_394 * V_172 = NULL ;
int V_353 ;
T_2 V_133 ;
if ( ! V_74 ) {
if ( V_452 ) {
if( F_201 ( V_364 , V_452 ) ) {
V_34 = - V_25 ;
goto V_398;
}
} else {
F_94 ( & V_364 -> V_5 , L_67 ) ;
goto V_398;
}
}
V_8 = F_179 ( V_364 ) ;
if ( ! V_8 )
goto V_398;
V_353 = F_175 ( V_8 ) ;
F_207 ( V_364 , V_8 ) ;
F_154 ( & V_8 -> V_192 ) ;
F_154 ( & V_8 -> V_111 ) ;
V_172 = F_184 ( V_364 , V_399 , L_68 ) ;
if ( ! V_172 ) {
V_34 = - V_462 ;
F_94 ( & V_364 -> V_5 , L_69 ) ;
goto V_398;
}
V_8 -> V_463 = F_186 ( V_172 ) ;
V_8 -> V_464 = V_172 -> V_400 ;
if ( F_185 ( V_172 -> V_400 , F_186 ( V_172 ) ,
V_401 L_70 ) == NULL ) {
V_34 = - V_116 ;
F_94 ( & V_364 -> V_5 , L_71 , V_172 ) ;
goto V_398;
}
V_133 = F_53 ( V_8 -> V_9 + V_465 ) ;
if ( V_172 -> V_400 != V_133 && V_133 != 0 ) {
F_200 ( & V_364 -> V_5 ,
L_72 ,
V_128 , V_133 , & V_172 -> V_400 ) ;
} else
F_30 ( V_172 -> V_400 , V_8 -> V_9 + V_465 ) ;
V_8 -> V_286 = F_187 ( V_172 -> V_400 , F_186 ( V_172 ) ) ;
if ( ! V_8 -> V_286 ) {
V_34 = - V_25 ;
F_94 ( & V_364 -> V_5 , L_73 ) ;
goto V_398;
}
if ( V_8 -> V_74 -> V_73 ) {
V_172 = F_184 ( V_364 , V_399 ,
L_74 ) ;
if ( ! V_172 ) {
V_34 = - V_462 ;
F_94 ( & V_364 -> V_5 ,
L_75 ) ;
goto V_398;
}
V_8 -> V_36 . V_8 = F_187 ( V_172 -> V_400 ,
F_186 ( V_172 ) ) ;
if ( ! V_8 -> V_36 . V_8 ) {
V_34 = - V_25 ;
F_94 ( & V_364 -> V_5 , L_76 ) ;
goto V_398;
}
F_30 ( V_172 -> V_400 , V_8 -> V_9 + V_451 ) ;
} else {
V_34 = F_197 ( V_8 ) ;
if ( V_34 ) {
F_94 ( & V_364 -> V_5 , L_77 ) ;
goto V_398;
}
}
F_154 ( & V_8 -> V_36 . V_37 ) ;
V_8 -> V_184 = F_208 ( V_364 , 0 ) ;
V_34 = F_209 ( V_8 -> V_184 , F_90 , 0 , V_401 , V_8 ) ;
if ( V_34 ) {
F_94 ( & V_364 -> V_5 , L_78 ) ;
goto V_398;
}
if ( V_8 -> V_74 -> V_73 ) {
V_8 -> V_365 = F_210 ( V_8 -> V_5 , L_74 ) ;
if ( F_182 ( V_8 -> V_365 ) ) {
F_94 ( & V_364 -> V_5 , L_79 ) ;
V_34 = F_211 ( V_8 -> V_365 ) ;
V_8 -> V_365 = NULL ;
goto V_398;
}
V_34 = F_166 ( V_8 -> V_365 ) ;
if ( V_34 ) {
F_94 ( & V_364 -> V_5 ,
L_80 ) ;
F_212 ( V_8 -> V_365 ) ;
V_8 -> V_365 = NULL ;
goto V_398;
}
}
F_170 ( V_379 , V_8 -> V_9 + V_378 ) ;
F_213 ( V_8 -> V_5 ) ;
F_214 ( V_8 -> V_5 , V_466 ) ;
F_215 ( V_8 -> V_5 ) ;
F_78 ( V_8 -> V_5 ) ;
F_216 ( V_8 -> V_5 ) ;
F_217 ( V_8 -> V_5 ) ;
V_34 = F_157 ( V_8 , V_353 ) ;
if ( V_34 )
goto V_398;
V_8 -> V_5 -> V_467 = & V_8 -> V_467 ;
V_34 = F_218 ( V_8 -> V_5 , V_98 ) ;
if ( V_34 ) {
F_94 ( & V_364 -> V_5 , L_81 ) ;
goto V_398;
}
F_196 ( V_8 ) ;
if ( V_452 ) {
V_34 = F_219 ( V_452 , F_121 , NULL ) ;
if ( V_34 )
F_101 ( & V_364 -> V_5 ,
L_82 ) ;
}
F_178 ( V_8 -> V_5 , L_83 ) ;
return 0 ;
V_398:
if ( V_8 ) {
if ( V_8 -> V_48 )
F_220 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_194 ( V_8 -> V_9 ) ;
if ( V_8 -> V_36 . V_8 && V_8 -> V_74 -> V_73 ) {
F_194 ( V_8 -> V_36 . V_8 ) ;
V_8 -> V_36 . V_8 = NULL ;
}
if ( V_8 -> V_36 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_36 . V_29 ,
V_447 * V_8 -> V_205 ,
V_31 ) ;
if ( ! V_8 -> V_36 . V_450 && V_8 -> V_36 . V_8 )
F_199 ( ( unsigned long ) V_8 -> V_36 . V_8 ,
V_8 -> V_36 . V_446 ) ;
F_10 ( V_8 -> V_36 . V_450 ) ;
if ( V_8 -> V_464 )
F_195 ( V_8 -> V_464 ,
V_8 -> V_463 ) ;
if ( V_8 -> V_409 )
F_195 ( V_8 -> V_409 ,
V_8 -> V_410 ) ;
if ( V_8 -> V_393 ) {
F_192 ( V_8 -> V_393 ) ;
F_193 ( V_8 -> V_393 ) ;
}
if ( V_8 -> V_365 ) {
F_164 ( V_8 -> V_365 ) ;
F_212 ( V_8 -> V_365 ) ;
}
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_196 ) ;
F_10 ( V_8 -> V_195 ) ;
F_10 ( V_8 -> V_225 ) ;
F_10 ( V_8 ) ;
}
F_94 ( & V_364 -> V_5 , L_84 ) ;
return V_34 ;
}
static int T_9 F_221 ( void )
{
return F_222 ( & V_468 , F_206 ) ;
}
