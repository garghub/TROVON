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
return F_38 ( & V_3 -> V_49 , struct V_14 , V_42 ) ;
}
static void F_39 ( struct V_2 * V_3 , struct V_14 * V_43 )
{
F_17 ( V_43 ) ;
V_43 -> V_86 = false ;
F_28 ( & V_43 -> V_42 , & V_3 -> V_87 ) ;
}
static struct V_14 * F_40 ( struct V_2 * V_3 )
{
return F_38 ( & V_3 -> V_87 , struct V_14 ,
V_42 ) ;
}
static struct V_14 * F_41 ( struct V_2 * V_3 )
{
return F_38 ( & V_3 -> V_88 , struct V_14 , V_42 ) ;
}
static struct V_14 * F_42 ( struct V_2 * V_3 )
{
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
goto V_115;
}
V_108 = 0xffffffff & ~ ( F_54 ( V_3 -> V_11 -> V_12 ) ) ;
F_30 ( V_108 | ( V_105 << F_55 ( V_3 -> V_11 -> V_12 ) ) ,
V_107 ) ;
if ( V_105 == V_110 ) {
for ( V_33 = 0 ; V_33 < V_116 ; V_33 ++ ) {
V_106 = ( F_53 ( V_107 ) &
F_54 ( V_3 -> V_11 -> V_12 ) ) >>
F_55 ( V_3 -> V_11 -> V_12 ) ;
F_56 () ;
F_57 ( 3 ) ;
if ( V_106 == V_109 ||
V_106 == V_114 )
break;
}
if ( V_33 == V_116 ) {
F_58 ( V_3 ,
L_1 ,
V_3 -> V_11 -> V_12 , V_3 -> V_6 ,
V_106 ) ;
F_59 () ;
V_34 = - V_117 ;
}
}
V_115:
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
if ( ! F_20 ( & V_3 -> V_118 ) )
F_21 (d40d, _d,
&d40c->prepare_queue, node) {
F_17 ( V_15 ) ;
F_25 ( V_3 , V_15 ) ;
}
V_3 -> V_119 = 0 ;
}
static void F_61 ( struct V_2 * V_3 ,
enum V_120 V_121 , T_2 V_122 ,
int V_123 )
{
void T_1 * V_124 = F_4 ( V_3 ) + V_123 ;
int V_125 ;
T_2 V_106 ;
switch ( V_121 ) {
case V_126 :
F_30 ( ( V_126 << F_62 ( V_122 ) )
| ~ F_63 ( V_122 ) , V_124 ) ;
break;
case V_127 :
V_106 = ( F_53 ( V_124 ) & F_63 ( V_122 ) ) >>
F_62 ( V_122 ) ;
if ( V_106 == V_126 ||
V_106 == V_127 )
break;
F_30 ( ( V_127 << F_62 ( V_122 ) )
| ~ F_63 ( V_122 ) , V_124 ) ;
for ( V_125 = 0 ; V_125 < V_116 ; V_125 ++ ) {
V_106 = ( F_53 ( V_124 ) & F_63 ( V_122 ) ) >>
F_62 ( V_122 ) ;
F_56 () ;
F_57 ( 3 ) ;
if ( V_106 == V_126 )
break;
}
if ( V_125 == V_116 ) {
F_58 ( V_3 ,
L_2
L_3 , V_3 -> V_11 -> V_12 ,
V_3 -> V_6 , V_106 ) ;
}
break;
case V_128 :
V_125 = 100 ;
while ( -- V_125 ) {
F_30 ( ( V_128 <<
F_62 ( V_122 ) ) |
~ F_63 ( V_122 ) , V_124 ) ;
if ( F_53 ( V_124 ) & F_63 ( V_122 ) )
break;
}
if ( V_125 != 99 )
F_64 ( F_1 ( V_3 ) ,
L_4 ,
V_129 , V_123 == V_59 ? 'S' : 'D' ,
100 - V_125 ) ;
F_65 ( ! V_125 ) ;
break;
case V_130 :
F_66 () ;
break;
}
}
static void F_67 ( struct V_2 * V_3 ,
enum V_120 V_121 )
{
T_2 V_122 = F_68 ( V_3 -> V_77 . V_131 ) ;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_132 ) )
F_61 ( V_3 , V_121 , V_122 ,
V_59 ) ;
if ( V_3 -> V_77 . V_78 != V_79 )
F_61 ( V_3 , V_121 , V_122 ,
V_63 ) ;
}
static T_2 F_69 ( struct V_2 * V_3 )
{
void T_1 * V_133 = F_4 ( V_3 ) ;
T_2 V_134 ;
V_134 = F_53 ( V_133 + V_59 ) ;
V_134 |= F_53 ( V_133 + V_63 ) ;
return V_134 ;
}
static int
F_70 ( struct V_2 * V_3 , enum V_104 V_105 )
{
unsigned long V_32 ;
int V_34 = 0 ;
T_2 V_135 ;
void T_1 * V_107 ;
if ( V_3 -> V_11 -> V_12 % 2 == 0 )
V_107 = V_3 -> V_8 -> V_9 + V_112 ;
else
V_107 = V_3 -> V_8 -> V_9 + V_113 ;
F_14 ( & V_3 -> V_11 -> V_37 , V_32 ) ;
switch ( V_105 ) {
case V_109 :
case V_110 :
V_135 = ( F_53 ( V_107 ) &
F_54 ( V_3 -> V_11 -> V_12 ) ) >>
F_55 ( V_3 -> V_11 -> V_12 ) ;
if ( V_135 == V_136 )
F_67 ( V_3 , V_127 ) ;
else
F_67 ( V_3 , V_126 ) ;
if ( ! F_69 ( V_3 ) && ( V_105 == V_109 ) )
V_34 = F_52 ( V_3 , V_105 ) ;
break;
case V_136 :
F_67 ( V_3 , V_128 ) ;
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
static const unsigned int V_137 [] = {
[ V_138 ]
= V_139 ,
[ V_140 ]
= V_141 ,
[ V_142 ]
= V_143 ,
} ;
static const unsigned int V_144 [] = {
[ V_145 ]
= V_146 ,
[ V_147 ]
= V_148 ,
[ V_149 ]
= V_150 ,
} ;
if ( F_2 ( V_3 ) )
return V_137 [ V_3 -> V_77 . V_151 ] ;
else
return V_144 [ V_3 -> V_77 . V_151 ] ;
}
static void F_73 ( struct V_2 * V_3 )
{
T_2 V_152 ;
T_2 V_153 ;
V_152 = ( V_3 -> V_11 -> V_12 % 2 ) * 4 ;
V_153 = ( ( T_2 ) ( F_3 ( V_3 ) ) + 1 ) <<
F_55 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_153 , V_3 -> V_8 -> V_9 + V_154 + V_152 ) ;
V_153 = F_72 ( V_3 ) << F_55 ( V_3 -> V_11 -> V_12 ) ;
F_30 ( V_153 , V_3 -> V_8 -> V_9 + V_155 + V_152 ) ;
if ( F_3 ( V_3 ) ) {
int V_156 = ( V_3 -> V_11 -> V_12 << V_157 )
& V_158 ;
void T_1 * V_133 = F_4 ( V_3 ) ;
F_30 ( V_3 -> V_159 , V_133 + V_53 ) ;
F_30 ( V_3 -> V_160 , V_133 + V_60 ) ;
F_30 ( V_156 , V_133 + V_55 ) ;
F_30 ( V_156 , V_133 + V_61 ) ;
F_30 ( 0 , V_133 + V_59 ) ;
F_30 ( 0 , V_133 + V_63 ) ;
}
}
static T_2 F_74 ( struct V_2 * V_3 )
{
T_2 V_161 ;
if ( F_3 ( V_3 ) )
V_161 = ( F_53 ( & V_3 -> V_81 -> V_162 ) & V_163 )
>> V_164 ;
else {
T_2 V_134 = F_53 ( F_4 ( V_3 ) + V_61 ) ;
V_161 = ( V_134 & V_165 )
>> V_166 ;
}
return V_161 * V_3 -> V_77 . V_167 . V_168 ;
}
static bool F_75 ( struct V_2 * V_3 )
{
bool V_169 ;
if ( F_3 ( V_3 ) )
V_169 = F_53 ( & V_3 -> V_81 -> V_170 ) & V_171 ;
else
V_169 = F_53 ( F_4 ( V_3 ) + V_63 )
& V_172 ;
return V_169 ;
}
static int F_76 ( struct V_173 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 , struct V_2 , V_4 ) ;
int V_174 = 0 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_5 ) ;
return - V_35 ;
}
if ( ! V_3 -> V_175 )
return 0 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
V_174 = F_71 ( V_3 , V_110 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_174 ;
}
static int F_81 ( struct V_173 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 , struct V_2 , V_4 ) ;
int V_174 = 0 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_5 ) ;
return - V_35 ;
}
if ( ! V_3 -> V_175 )
return 0 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
if ( F_74 ( V_3 ) || F_75 ( V_3 ) )
V_174 = F_71 ( V_3 , V_136 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_174 ;
}
static T_3 F_82 ( struct V_176 * V_177 )
{
struct V_2 * V_3 = F_77 ( V_177 -> V_4 ,
struct V_2 ,
V_4 ) ;
struct V_14 * V_15 = F_77 ( V_177 , struct V_14 , V_47 ) ;
unsigned long V_32 ;
T_3 V_178 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_178 = F_83 ( V_177 ) ;
F_39 ( V_3 , V_15 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_178 ;
}
static int F_84 ( struct V_2 * V_3 )
{
return F_71 ( V_3 , V_136 ) ;
}
static struct V_14 * F_85 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
int V_179 ;
V_15 = F_41 ( V_3 ) ;
if ( V_15 != NULL ) {
if ( ! V_3 -> V_175 ) {
V_3 -> V_175 = true ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_27 ( V_3 , V_15 ) ;
F_36 ( V_3 , V_15 ) ;
V_179 = F_84 ( V_3 ) ;
if ( V_179 )
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
V_3 -> V_175 = false ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
}
F_17 ( V_15 ) ;
F_31 ( V_3 , V_15 ) ;
}
V_3 -> V_119 ++ ;
F_87 ( & V_3 -> V_180 ) ;
}
static void F_88 ( unsigned long V_181 )
{
struct V_2 * V_3 = (struct V_2 * ) V_181 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
bool V_182 ;
struct V_183 V_184 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_15 = F_42 ( V_3 ) ;
if ( V_15 == NULL ) {
V_15 = F_37 ( V_3 ) ;
if ( V_15 == NULL || ! V_15 -> V_70 )
goto V_185;
}
if ( ! V_15 -> V_70 )
F_89 ( & V_15 -> V_47 ) ;
if ( V_3 -> V_119 == 0 ) {
F_15 ( & V_3 -> V_37 , V_32 ) ;
return;
}
V_182 = ! ! ( V_15 -> V_47 . V_32 & V_186 ) ;
F_90 ( & V_15 -> V_47 , & V_184 ) ;
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
V_3 -> V_119 -- ;
if ( V_3 -> V_119 )
F_87 ( & V_3 -> V_180 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
if ( V_182 )
F_91 ( & V_184 , NULL ) ;
return;
V_185:
if ( V_3 -> V_119 > 0 )
V_3 -> V_119 -- ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static T_4 F_92 ( int V_187 , void * V_181 )
{
int V_33 ;
T_2 V_39 ;
T_2 V_188 ;
long V_4 = - 1 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
struct V_189 * V_8 = V_181 ;
T_2 V_190 [ V_8 -> V_191 . V_192 ] ;
struct V_193 * V_194 = V_8 -> V_191 . V_194 ;
T_2 V_192 = V_8 -> V_191 . V_192 ;
F_14 ( & V_8 -> V_195 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_192 ; V_33 ++ )
V_190 [ V_33 ] = F_53 ( V_8 -> V_9 + V_194 [ V_33 ] . V_27 ) ;
for (; ; ) {
V_4 = F_93 ( ( unsigned long * ) V_190 ,
V_196 * V_192 , V_4 + 1 ) ;
if ( V_4 == V_196 * V_192 )
break;
V_188 = V_4 / V_196 ;
V_39 = V_4 & ( V_196 - 1 ) ;
if ( V_194 [ V_188 ] . V_197 == V_7 )
V_3 = V_8 -> V_198 [ V_39 ] ;
else
V_3 = V_8 -> V_199 [ V_194 [ V_188 ] . V_197 + V_39 ] ;
if ( ! V_3 ) {
continue;
}
F_30 ( F_94 ( V_39 ) , V_8 -> V_9 + V_194 [ V_188 ] . V_200 ) ;
F_95 ( & V_3 -> V_37 ) ;
if ( ! V_194 [ V_188 ] . V_201 )
F_86 ( V_3 ) ;
else
F_96 ( V_8 -> V_5 , L_6 ,
V_4 , V_194 [ V_188 ] . V_197 , V_39 ) ;
F_97 ( & V_3 -> V_37 ) ;
}
F_15 ( & V_8 -> V_195 , V_32 ) ;
return V_202 ;
}
static int F_98 ( struct V_2 * V_3 ,
struct V_203 * V_204 )
{
int V_174 = 0 ;
bool V_17 = V_204 -> V_205 == V_206 ;
if ( ! V_204 -> V_78 ) {
F_58 ( V_3 , L_7 ) ;
V_174 = - V_35 ;
}
if ( ( V_17 && V_204 -> V_131 > V_3 -> V_8 -> V_207 ) ||
( ! V_17 && V_204 -> V_131 > V_3 -> V_8 -> V_208 ) ||
( V_204 -> V_131 < 0 ) ) {
F_58 ( V_3 , L_8 , V_204 -> V_131 ) ;
V_174 = - V_35 ;
}
if ( V_204 -> V_78 == V_132 ) {
F_58 ( V_3 , L_9 ) ;
V_174 = - V_35 ;
}
if ( F_43 ( V_17 , V_204 -> V_209 . V_89 ) *
V_204 -> V_209 . V_168 !=
F_43 ( V_17 , V_204 -> V_167 . V_89 ) *
V_204 -> V_167 . V_168 ) {
F_58 ( V_3 , L_10 ) ;
V_174 = - V_35 ;
}
return V_174 ;
}
static bool F_99 ( struct V_210 * V_211 ,
bool V_212 , int V_213 , bool V_17 ,
bool * V_214 )
{
unsigned long V_32 ;
F_14 ( & V_211 -> V_37 , V_32 ) ;
* V_214 = ( ( V_211 -> V_215 | V_211 -> V_216 )
== V_217 ) ;
if ( ! V_17 ) {
if ( V_211 -> V_215 == V_217 &&
V_211 -> V_216 == V_217 ) {
V_211 -> V_216 = V_218 ;
V_211 -> V_215 = V_218 ;
goto V_219;
} else
goto V_220;
}
if ( V_212 ) {
if ( V_211 -> V_215 == V_218 )
goto V_220;
if ( V_211 -> V_215 == V_217 )
V_211 -> V_215 = V_221 ;
if ( ! ( V_211 -> V_215 & F_94 ( V_213 ) ) ) {
V_211 -> V_215 |= F_94 ( V_213 ) ;
goto V_219;
} else
goto V_220;
} else {
if ( V_211 -> V_216 == V_218 )
goto V_220;
if ( V_211 -> V_216 == V_217 )
V_211 -> V_216 = V_221 ;
if ( ! ( V_211 -> V_216 & F_94 ( V_213 ) ) ) {
V_211 -> V_216 |= F_94 ( V_213 ) ;
goto V_219;
}
}
V_220:
F_15 ( & V_211 -> V_37 , V_32 ) ;
return false ;
V_219:
F_15 ( & V_211 -> V_37 , V_32 ) ;
return true ;
}
static bool F_100 ( struct V_210 * V_211 , bool V_212 ,
int V_213 )
{
unsigned long V_32 ;
bool V_222 = false ;
F_14 ( & V_211 -> V_37 , V_32 ) ;
if ( ! V_213 ) {
V_211 -> V_216 = V_217 ;
V_211 -> V_215 = V_217 ;
V_222 = true ;
goto V_115;
}
if ( V_212 ) {
V_211 -> V_215 &= ~ F_94 ( V_213 ) ;
if ( V_211 -> V_215 == V_221 )
V_211 -> V_215 = V_217 ;
} else {
V_211 -> V_216 &= ~ F_94 ( V_213 ) ;
if ( V_211 -> V_216 == V_221 )
V_211 -> V_216 = V_217 ;
}
V_222 = ( ( V_211 -> V_215 | V_211 -> V_216 ) ==
V_217 ) ;
V_115:
F_15 ( & V_211 -> V_37 , V_32 ) ;
return V_222 ;
}
static int F_101 ( struct V_2 * V_3 , bool * V_223 )
{
int V_131 = V_3 -> V_77 . V_131 ;
int V_224 ;
int V_225 ;
struct V_210 * V_226 ;
int V_33 ;
int V_227 ;
int V_6 ;
int V_208 ;
bool V_212 ;
bool V_17 = V_3 -> V_77 . V_205 == V_206 ;
V_226 = V_3 -> V_8 -> V_228 ;
V_208 = V_3 -> V_8 -> V_208 ;
if ( V_3 -> V_77 . V_78 == V_79 ) {
V_6 = 2 * V_131 ;
V_212 = true ;
} else if ( V_3 -> V_77 . V_78 == V_229 ||
V_3 -> V_77 . V_78 == V_230 ) {
V_6 = 2 * V_131 + 1 ;
V_212 = false ;
} else
return - V_35 ;
V_224 = F_102 ( V_131 ) ;
V_225 = F_68 ( V_131 ) ;
if ( ! V_17 ) {
if ( V_3 -> V_77 . V_78 == V_230 ) {
if ( V_3 -> V_77 . V_231 ) {
V_33 = V_3 -> V_77 . V_232 ;
if ( F_99 ( & V_226 [ V_33 ] , V_212 ,
0 , V_17 ,
V_223 ) )
goto V_233;
} else {
for ( V_33 = 0 ; V_33 < V_208 ; V_33 ++ ) {
if ( F_99 ( & V_226 [ V_33 ] , V_212 ,
0 , V_17 ,
V_223 ) )
goto V_233;
}
}
} else
for ( V_227 = 0 ; V_227 < V_3 -> V_8 -> V_208 ; V_227 += 8 ) {
int V_234 = V_227 + V_224 * 2 ;
for ( V_33 = V_234 ; V_33 < V_234 + 2 ; V_33 ++ ) {
if ( F_99 ( & V_226 [ V_33 ] ,
V_212 ,
0 ,
V_17 ,
V_223 ) )
goto V_233;
}
}
return - V_35 ;
V_233:
V_3 -> V_11 = & V_226 [ V_33 ] ;
V_3 -> V_6 = V_7 ;
goto V_235;
}
if ( V_131 == - 1 )
return - V_35 ;
for ( V_227 = 0 ; V_227 < V_3 -> V_8 -> V_208 ; V_227 += 8 ) {
int V_234 = V_227 + V_224 * 2 ;
if ( V_3 -> V_77 . V_231 ) {
V_33 = V_3 -> V_77 . V_232 ;
if ( ( V_33 != V_234 ) && ( V_33 != V_234 + 1 ) ) {
F_103 ( F_1 ( V_3 ) ,
L_11 , V_33 ) ;
return - V_35 ;
}
if ( F_99 ( & V_226 [ V_33 ] , V_212 , V_225 ,
V_17 , V_223 ) )
goto V_236;
F_103 ( F_1 ( V_3 ) ,
L_12 , V_33 ) ;
return - V_35 ;
}
if ( V_212 ) {
for ( V_33 = V_234 ; V_33 < V_234 + 2 ; V_33 ++ ) {
if ( F_99 ( & V_226 [ V_33 ] , V_212 ,
V_225 , V_17 ,
V_223 ) )
goto V_236;
}
} else {
for ( V_33 = V_234 + 1 ; V_33 >= V_234 ; V_33 -- ) {
if ( F_99 ( & V_226 [ V_33 ] , V_212 ,
V_225 , V_17 ,
V_223 ) )
goto V_236;
}
}
}
return - V_35 ;
V_236:
V_3 -> V_11 = & V_226 [ V_33 ] ;
V_3 -> V_6 = V_6 ;
V_235:
if ( V_17 )
V_3 -> V_8 -> V_199 [ V_3 -> V_6 ] = V_3 ;
else
V_3 -> V_8 -> V_198 [ V_3 -> V_11 -> V_12 ] = V_3 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 )
{
T_5 V_237 = V_3 -> V_4 . V_1 -> V_238 ;
if ( F_105 ( V_239 , V_237 ) && ! F_105 ( V_240 , V_237 ) ) {
V_3 -> V_77 = V_241 ;
V_3 -> V_77 . V_131 = V_242 [ V_3 -> V_4 . V_243 ] ;
F_106 ( & V_3 -> V_77 ,
& V_3 -> V_244 . V_245 , & V_3 -> V_244 . V_170 ) ;
} else if ( F_105 ( V_239 , V_237 ) &&
F_105 ( V_240 , V_237 ) ) {
V_3 -> V_77 = V_246 ;
V_3 -> V_160 |= F_94 ( V_247 ) ;
V_3 -> V_159 |= F_94 ( V_248 ) ;
V_3 -> V_160 |= F_94 ( V_248 ) ;
} else {
F_58 ( V_3 , L_13 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_107 ( struct V_2 * V_3 )
{
int V_174 = 0 ;
T_2 V_122 = F_68 ( V_3 -> V_77 . V_131 ) ;
struct V_210 * V_211 = V_3 -> V_11 ;
bool V_212 ;
F_60 ( V_3 ) ;
if ( V_211 == NULL ) {
F_58 ( V_3 , L_14 ) ;
return - V_35 ;
}
if ( V_211 -> V_215 == V_217 &&
V_211 -> V_216 == V_217 ) {
F_58 ( V_3 , L_15 ) ;
return - V_35 ;
}
if ( V_3 -> V_77 . V_78 == V_229 ||
V_3 -> V_77 . V_78 == V_230 )
V_212 = false ;
else if ( V_3 -> V_77 . V_78 == V_79 )
V_212 = true ;
else {
F_58 ( V_3 , L_16 ) ;
return - V_35 ;
}
F_78 ( V_3 -> V_8 -> V_5 ) ;
V_174 = F_71 ( V_3 , V_109 ) ;
if ( V_174 ) {
F_58 ( V_3 , L_17 ) ;
goto V_249;
}
F_100 ( V_211 , V_212 , F_3 ( V_3 ) ? V_122 : 0 ) ;
if ( F_3 ( V_3 ) )
V_3 -> V_8 -> V_199 [ V_3 -> V_6 ] = NULL ;
else
V_3 -> V_8 -> V_198 [ V_211 -> V_12 ] = NULL ;
if ( V_3 -> V_175 ) {
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_175 = false ;
V_3 -> V_11 = NULL ;
V_3 -> V_250 = false ;
V_249:
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
return V_174 ;
}
static bool F_108 ( struct V_2 * V_3 )
{
void T_1 * V_133 = F_4 ( V_3 ) ;
bool V_251 = false ;
unsigned long V_32 ;
void T_1 * V_107 ;
T_2 V_106 ;
T_2 V_122 = F_68 ( V_3 -> V_77 . V_131 ) ;
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
V_251 = true ;
goto V_115;
}
if ( V_3 -> V_77 . V_78 == V_229 ||
V_3 -> V_77 . V_78 == V_230 ) {
V_106 = F_53 ( V_133 + V_63 ) ;
} else if ( V_3 -> V_77 . V_78 == V_79 ) {
V_106 = F_53 ( V_133 + V_59 ) ;
} else {
F_58 ( V_3 , L_16 ) ;
goto V_115;
}
V_106 = ( V_106 & F_63 ( V_122 ) ) >>
F_62 ( V_122 ) ;
if ( V_106 != V_136 )
V_251 = true ;
V_115:
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_251 ;
}
static T_2 F_109 ( struct V_173 * V_4 )
{
struct V_2 * V_3 =
F_77 ( V_4 , struct V_2 , V_4 ) ;
T_2 V_252 ;
unsigned long V_32 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_252 = F_74 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_252 ;
}
static int
F_110 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_253 , struct V_99 * V_254 ,
unsigned int V_101 , T_6 V_255 ,
T_6 V_256 )
{
struct V_203 * V_257 = & V_4 -> V_77 ;
struct V_258 * V_209 = & V_257 -> V_209 ;
struct V_258 * V_167 = & V_257 -> V_167 ;
int V_34 ;
V_34 = F_111 ( V_253 , V_101 ,
V_255 ,
V_43 -> V_26 . V_27 ,
V_4 -> V_244 . V_245 ,
V_209 -> V_168 ,
V_167 -> V_168 ) ;
V_34 = F_111 ( V_254 , V_101 ,
V_256 ,
V_43 -> V_26 . V_28 ,
V_4 -> V_244 . V_170 ,
V_167 -> V_168 ,
V_209 -> V_168 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static int
F_112 ( struct V_2 * V_4 , struct V_14 * V_43 ,
struct V_99 * V_253 , struct V_99 * V_254 ,
unsigned int V_101 , T_6 V_255 ,
T_6 V_256 )
{
struct V_203 * V_257 = & V_4 -> V_77 ;
struct V_258 * V_209 = & V_257 -> V_209 ;
struct V_258 * V_167 = & V_257 -> V_167 ;
unsigned long V_32 = 0 ;
int V_34 ;
if ( V_43 -> V_70 )
V_32 |= V_259 | V_80 ;
V_34 = F_113 ( V_253 , V_101 , V_255 ,
V_43 -> V_30 . V_27 ,
F_114 ( V_43 -> V_30 . V_27 ) ,
V_4 -> V_159 ,
V_209 , V_167 , V_32 ) ;
V_34 = F_113 ( V_254 , V_101 , V_256 ,
V_43 -> V_30 . V_28 ,
F_114 ( V_43 -> V_30 . V_28 ) ,
V_4 -> V_160 ,
V_167 , V_209 , V_32 ) ;
F_115 ( V_4 -> V_8 -> V_5 , V_43 -> V_21 . V_29 ,
V_43 -> V_21 . V_23 , V_31 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
static struct V_14 *
F_116 ( struct V_2 * V_4 , struct V_99 * V_102 ,
unsigned int V_101 , unsigned long V_260 )
{
struct V_203 * V_257 ;
struct V_14 * V_43 ;
int V_34 ;
V_43 = F_19 ( V_4 ) ;
if ( ! V_43 )
return NULL ;
V_257 = & V_4 -> V_77 ;
V_43 -> V_16 = F_49 ( V_102 , V_101 , V_257 -> V_209 . V_168 ,
V_257 -> V_167 . V_168 ) ;
if ( V_43 -> V_16 < 0 ) {
F_58 ( V_4 , L_18 ) ;
goto V_261;
}
V_34 = F_5 ( V_4 , V_43 , V_43 -> V_16 ) ;
if ( V_34 < 0 ) {
F_58 ( V_4 , L_19 ) ;
goto V_261;
}
V_43 -> V_69 = 0 ;
V_43 -> V_47 . V_32 = V_260 ;
V_43 -> V_47 . V_262 = F_82 ;
F_117 ( & V_43 -> V_47 , & V_4 -> V_4 ) ;
return V_43 ;
V_261:
F_25 ( V_4 , V_43 ) ;
return NULL ;
}
static struct V_176 *
F_118 ( struct V_173 * V_263 , struct V_99 * V_253 ,
struct V_99 * V_254 , unsigned int V_101 ,
enum V_264 V_265 , unsigned long V_260 )
{
struct V_2 * V_4 = F_77 ( V_263 , struct V_2 , V_4 ) ;
T_6 V_255 ;
T_6 V_256 ;
struct V_14 * V_43 ;
unsigned long V_32 ;
int V_34 ;
if ( ! V_4 -> V_11 ) {
F_58 ( V_4 , L_20 ) ;
return NULL ;
}
F_14 ( & V_4 -> V_37 , V_32 ) ;
V_43 = F_116 ( V_4 , V_253 , V_101 , V_260 ) ;
if ( V_43 == NULL )
goto V_115;
if ( F_119 ( & V_253 [ V_101 - 1 ] ) == V_253 )
V_43 -> V_70 = true ;
V_255 = 0 ;
V_256 = 0 ;
if ( V_265 == V_79 )
V_255 = V_4 -> V_266 ;
else if ( V_265 == V_229 )
V_256 = V_4 -> V_266 ;
if ( F_3 ( V_4 ) )
V_34 = F_110 ( V_4 , V_43 , V_253 , V_254 ,
V_101 , V_255 , V_256 ) ;
else
V_34 = F_112 ( V_4 , V_43 , V_253 , V_254 ,
V_101 , V_255 , V_256 ) ;
if ( V_34 ) {
F_58 ( V_4 , L_21 ,
F_3 ( V_4 ) ? L_22 : L_23 , V_34 ) ;
goto V_261;
}
F_28 ( & V_43 -> V_42 , & V_4 -> V_118 ) ;
F_15 ( & V_4 -> V_37 , V_32 ) ;
return & V_43 -> V_47 ;
V_261:
F_25 ( V_4 , V_43 ) ;
V_115:
F_15 ( & V_4 -> V_37 , V_32 ) ;
return NULL ;
}
bool F_120 ( struct V_173 * V_4 , void * V_181 )
{
struct V_203 * V_267 = V_181 ;
struct V_2 * V_3 =
F_77 ( V_4 , struct V_2 , V_4 ) ;
int V_179 ;
if ( V_181 ) {
V_179 = F_98 ( V_3 , V_267 ) ;
if ( ! V_179 )
V_3 -> V_77 = * V_267 ;
} else
V_179 = F_104 ( V_3 ) ;
if ( ! V_179 )
V_3 -> V_250 = true ;
return V_179 == 0 ;
}
static void F_121 ( struct V_2 * V_3 , int V_131 , bool V_27 )
{
bool V_268 = V_3 -> V_77 . V_268 ;
bool V_269 = V_3 -> V_77 . V_270 ;
T_2 V_271 ;
T_2 V_122 = F_68 ( V_131 ) ;
T_2 V_272 = F_102 ( V_131 ) ;
T_2 V_273 = F_94 ( V_122 ) ;
T_2 V_274 ;
struct V_275 * V_276 = & V_3 -> V_8 -> V_191 ;
V_271 = V_268 ? V_276 -> V_277 : V_276 -> V_278 ;
if ( ! V_27 && F_3 ( V_3 ) )
V_269 = false ;
V_274 = V_269 ? V_276 -> V_279 : V_276 -> V_280 ;
if ( ! V_27 )
V_273 <<= 16 ;
F_30 ( V_273 , V_3 -> V_8 -> V_9 + V_274 + V_272 * 4 ) ;
F_30 ( V_273 , V_3 -> V_8 -> V_9 + V_271 + V_272 * 4 ) ;
}
static void F_122 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 -> V_281 < 3 )
return;
if ( ( V_3 -> V_77 . V_78 == V_79 ) ||
( V_3 -> V_77 . V_78 == V_132 ) )
F_121 ( V_3 , V_3 -> V_77 . V_131 , true ) ;
if ( ( V_3 -> V_77 . V_78 == V_229 ) ||
( V_3 -> V_77 . V_78 == V_132 ) )
F_121 ( V_3 , V_3 -> V_77 . V_131 , false ) ;
}
static struct V_173 * F_123 ( struct V_282 * V_283 ,
struct V_284 * V_285 )
{
struct V_203 V_257 ;
T_5 V_237 ;
T_2 V_32 ;
memset ( & V_257 , 0 , sizeof( struct V_203 ) ) ;
F_124 ( V_237 ) ;
F_125 ( V_240 , V_237 ) ;
V_257 . V_131 = V_283 -> args [ 0 ] ;
V_32 = V_283 -> args [ 2 ] ;
switch ( F_126 ( V_32 ) ) {
case 0 : V_257 . V_205 = V_206 ; break;
case 1 : V_257 . V_205 = V_286 ; break;
}
switch ( F_127 ( V_32 ) ) {
case 0 :
V_257 . V_78 = V_229 ;
V_257 . V_167 . V_287 = F_128 ( V_32 ) ;
break;
case 1 :
V_257 . V_78 = V_79 ;
V_257 . V_209 . V_287 = F_128 ( V_32 ) ;
break;
}
if ( F_129 ( V_32 ) ) {
V_257 . V_232 = V_283 -> args [ 1 ] ;
V_257 . V_231 = true ;
}
if ( F_130 ( V_32 ) )
V_257 . V_270 = true ;
return F_131 ( V_237 , F_120 , & V_257 ) ;
}
static int F_132 ( struct V_173 * V_4 )
{
int V_179 ;
unsigned long V_32 ;
struct V_2 * V_3 =
F_77 ( V_4 , struct V_2 , V_4 ) ;
bool V_288 ;
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_133 ( V_4 ) ;
if ( ! V_3 -> V_250 ) {
V_179 = F_104 ( V_3 ) ;
if ( V_179 ) {
F_58 ( V_3 , L_24 ) ;
goto V_249;
}
}
V_179 = F_101 ( V_3 , & V_288 ) ;
if ( V_179 ) {
F_58 ( V_3 , L_25 ) ;
V_3 -> V_250 = false ;
goto V_249;
}
F_78 ( V_3 -> V_8 -> V_5 ) ;
F_122 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
if ( V_3 -> V_77 . V_78 == V_79 )
V_3 -> V_81 = V_3 -> V_8 -> V_289 +
V_3 -> V_77 . V_131 * V_290 ;
else
V_3 -> V_81 = V_3 -> V_8 -> V_289 +
V_3 -> V_77 . V_131 *
V_290 + V_291 ;
V_3 -> V_159 |= F_94 ( V_292 ) ;
V_3 -> V_160 |= F_94 ( V_292 ) ;
}
F_64 ( F_1 ( V_3 ) , L_26 ,
F_3 ( V_3 ) ? L_27 : L_28 ,
V_3 -> V_11 -> V_12 ,
V_3 -> V_77 . V_231 ? L_29 : L_30 ) ;
if ( V_288 )
F_73 ( V_3 ) ;
V_249:
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return V_179 ;
}
static void F_134 ( struct V_173 * V_4 )
{
struct V_2 * V_3 =
F_77 ( V_4 , struct V_2 , V_4 ) ;
int V_179 ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_31 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
V_179 = F_107 ( V_3 ) ;
if ( V_179 )
F_58 ( V_3 , L_32 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static struct V_176 * F_135 ( struct V_173 * V_4 ,
T_6 V_28 ,
T_6 V_27 ,
T_7 V_23 ,
unsigned long V_260 )
{
struct V_99 V_293 ;
struct V_99 V_294 ;
F_136 ( & V_293 , 1 ) ;
F_136 ( & V_294 , 1 ) ;
F_137 ( & V_293 ) = V_28 ;
F_137 ( & V_294 ) = V_27 ;
F_51 ( & V_293 ) = V_23 ;
F_51 ( & V_294 ) = V_23 ;
return F_118 ( V_4 , & V_294 , & V_293 , 1 ,
V_230 , V_260 ) ;
}
static struct V_176 *
F_138 ( struct V_173 * V_4 ,
struct V_99 * V_293 , unsigned int V_295 ,
struct V_99 * V_294 , unsigned int V_296 ,
unsigned long V_260 )
{
if ( V_295 != V_296 )
return NULL ;
return F_118 ( V_4 , V_294 , V_293 , V_296 ,
V_230 , V_260 ) ;
}
static struct V_176 *
F_139 ( struct V_173 * V_4 , struct V_99 * V_100 ,
unsigned int V_101 , enum V_264 V_265 ,
unsigned long V_260 , void * V_297 )
{
if ( ! F_140 ( V_265 ) )
return NULL ;
return F_118 ( V_4 , V_100 , V_100 , V_101 , V_265 , V_260 ) ;
}
static struct V_176 *
F_141 ( struct V_173 * V_4 , T_6 V_29 ,
T_7 V_298 , T_7 V_299 ,
enum V_264 V_265 , unsigned long V_32 )
{
unsigned int V_300 = V_298 / V_299 ;
struct V_176 * V_47 ;
struct V_99 * V_102 ;
int V_33 ;
V_102 = F_142 ( V_300 + 1 , sizeof( struct V_99 ) , V_24 ) ;
if ( ! V_102 )
return NULL ;
for ( V_33 = 0 ; V_33 < V_300 ; V_33 ++ ) {
F_137 ( & V_102 [ V_33 ] ) = V_29 ;
F_51 ( & V_102 [ V_33 ] ) = V_299 ;
V_29 += V_299 ;
}
F_143 ( V_102 , V_300 + 1 , V_102 ) ;
V_47 = F_118 ( V_4 , V_102 , V_102 , V_300 , V_265 ,
V_186 ) ;
F_10 ( V_102 ) ;
return V_47 ;
}
static enum V_301 F_144 ( struct V_173 * V_4 ,
T_3 V_178 ,
struct V_302 * V_303 )
{
struct V_2 * V_3 = F_77 ( V_4 , struct V_2 , V_4 ) ;
enum V_301 V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_33 ) ;
return - V_35 ;
}
V_34 = F_145 ( V_4 , V_178 , V_303 ) ;
if ( V_34 != V_304 && V_303 )
F_146 ( V_303 , F_109 ( V_4 ) ) ;
if ( F_108 ( V_3 ) )
V_34 = V_305 ;
return V_34 ;
}
static void F_147 ( struct V_173 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 , struct V_2 , V_4 ) ;
unsigned long V_32 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_5 ) ;
return;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_148 ( & V_3 -> V_87 , & V_3 -> V_88 ) ;
if ( ! V_3 -> V_175 )
( void ) F_85 ( V_3 ) ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
}
static int F_149 ( struct V_173 * V_4 )
{
unsigned long V_32 ;
struct V_2 * V_3 = F_77 ( V_4 , struct V_2 , V_4 ) ;
int V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_5 ) ;
return - V_35 ;
}
F_14 ( & V_3 -> V_37 , V_32 ) ;
F_78 ( V_3 -> V_8 -> V_5 ) ;
V_34 = F_71 ( V_3 , V_109 ) ;
if ( V_34 )
F_58 ( V_3 , L_34 ) ;
F_60 ( V_3 ) ;
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
if ( V_3 -> V_175 ) {
F_79 ( V_3 -> V_8 -> V_5 ) ;
F_80 ( V_3 -> V_8 -> V_5 ) ;
}
V_3 -> V_175 = false ;
F_15 ( & V_3 -> V_37 , V_32 ) ;
return 0 ;
}
static int
F_150 ( struct V_2 * V_3 ,
struct V_258 * V_267 ,
T_2 V_306 )
{
int V_89 ;
if ( F_3 ( V_3 ) ) {
if ( V_306 >= 16 )
V_89 = V_307 ;
else if ( V_306 >= 8 )
V_89 = V_308 ;
else if ( V_306 >= 4 )
V_89 = V_309 ;
else
V_89 = V_90 ;
} else {
if ( V_306 >= 16 )
V_89 = V_310 ;
else if ( V_306 >= 8 )
V_89 = V_311 ;
else if ( V_306 >= 4 )
V_89 = V_312 ;
else
V_89 = V_91 ;
}
V_267 -> V_89 = V_89 ;
V_267 -> V_313 = V_314 ;
return 0 ;
}
static int F_151 ( struct V_173 * V_4 ,
struct V_315 * V_316 )
{
struct V_2 * V_3 = F_77 ( V_4 , struct V_2 , V_4 ) ;
struct V_203 * V_257 = & V_3 -> V_77 ;
enum V_317 V_318 , V_319 ;
T_6 V_320 ;
T_2 V_321 , V_322 ;
int V_34 ;
if ( V_3 -> V_11 == NULL ) {
F_58 ( V_3 , L_5 ) ;
return - V_35 ;
}
V_318 = V_316 -> V_318 ;
V_321 = V_316 -> V_321 ;
V_319 = V_316 -> V_319 ;
V_322 = V_316 -> V_322 ;
if ( V_316 -> V_265 == V_79 ) {
V_320 = V_316 -> V_323 ;
if ( V_257 -> V_78 != V_79 )
F_64 ( V_3 -> V_8 -> V_5 ,
L_35
L_36 ,
V_257 -> V_78 ) ;
V_257 -> V_78 = V_79 ;
if ( V_319 == V_324 )
V_319 = V_318 ;
if ( V_322 == 0 )
V_322 = V_321 ;
} else if ( V_316 -> V_265 == V_229 ) {
V_320 = V_316 -> V_325 ;
if ( V_257 -> V_78 != V_229 )
F_64 ( V_3 -> V_8 -> V_5 ,
L_37
L_38 ,
V_257 -> V_78 ) ;
V_257 -> V_78 = V_229 ;
if ( V_318 == V_324 )
V_318 = V_319 ;
if ( V_321 == 0 )
V_321 = V_322 ;
} else {
F_103 ( V_3 -> V_8 -> V_5 ,
L_39 ,
V_316 -> V_265 ) ;
return - V_35 ;
}
if ( V_320 <= 0 ) {
F_103 ( V_3 -> V_8 -> V_5 , L_40 ) ;
return - V_35 ;
}
if ( V_321 * V_318 != V_322 * V_319 ) {
F_103 ( V_3 -> V_8 -> V_5 ,
L_41 ,
V_321 ,
V_318 ,
V_322 ,
V_319 ) ;
return - V_35 ;
}
if ( V_321 > 16 ) {
V_321 = 16 ;
V_322 = V_321 * V_318 / V_319 ;
} else if ( V_322 > 16 ) {
V_322 = 16 ;
V_321 = V_322 * V_319 / V_318 ;
}
if ( V_318 <= V_324 ||
V_318 > V_326 ||
V_319 <= V_324 ||
V_319 > V_326 ||
! F_152 ( V_318 ) ||
! F_152 ( V_319 ) )
return - V_35 ;
V_257 -> V_209 . V_168 = V_318 ;
V_257 -> V_167 . V_168 = V_319 ;
V_34 = F_150 ( V_3 , & V_257 -> V_209 ,
V_321 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_150 ( V_3 , & V_257 -> V_167 ,
V_322 ) ;
if ( V_34 )
return V_34 ;
if ( F_3 ( V_3 ) )
F_106 ( V_257 , & V_3 -> V_244 . V_245 , & V_3 -> V_244 . V_170 ) ;
else
F_153 ( V_257 , & V_3 -> V_159 , & V_3 -> V_160 ) ;
V_3 -> V_266 = V_320 ;
V_3 -> V_327 = V_316 -> V_265 ;
F_64 ( V_3 -> V_8 -> V_5 ,
L_42
L_43 ,
F_154 ( V_4 ) ,
( V_316 -> V_265 == V_79 ) ? L_44 : L_45 ,
V_318 , V_319 ,
V_321 , V_322 ) ;
return 0 ;
}
static void T_8 F_155 ( struct V_189 * V_8 , struct V_328 * V_329 ,
struct V_2 * V_330 , int V_197 ,
int V_331 )
{
int V_33 = 0 ;
struct V_2 * V_3 ;
F_24 ( & V_329 -> V_332 ) ;
for ( V_33 = V_197 ; V_33 < V_197 + V_331 ; V_33 ++ ) {
V_3 = & V_330 [ V_33 ] ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_1 = V_329 ;
F_156 ( & V_3 -> V_37 ) ;
V_3 -> V_6 = V_7 ;
F_24 ( & V_3 -> V_64 ) ;
F_24 ( & V_3 -> V_49 ) ;
F_24 ( & V_3 -> V_88 ) ;
F_24 ( & V_3 -> V_87 ) ;
F_24 ( & V_3 -> V_44 ) ;
F_24 ( & V_3 -> V_118 ) ;
F_157 ( & V_3 -> V_180 , F_88 ,
( unsigned long ) V_3 ) ;
F_28 ( & V_3 -> V_4 . V_333 ,
& V_329 -> V_332 ) ;
}
}
static void F_158 ( struct V_189 * V_8 , struct V_328 * V_5 )
{
if ( F_105 ( V_240 , V_5 -> V_238 ) ) {
V_5 -> V_334 = F_139 ;
V_5 -> V_335 = F_94 ( V_79 ) | F_94 ( V_229 ) ;
}
if ( F_105 ( V_239 , V_5 -> V_238 ) ) {
V_5 -> V_336 = F_135 ;
V_5 -> V_335 = F_94 ( V_230 ) ;
V_5 -> V_337 = V_338 ;
}
if ( F_105 ( V_339 , V_5 -> V_238 ) )
V_5 -> V_340 = F_138 ;
if ( F_105 ( V_341 , V_5 -> V_238 ) )
V_5 -> V_342 = F_141 ;
V_5 -> V_343 = F_132 ;
V_5 -> V_344 = F_134 ;
V_5 -> V_345 = F_147 ;
V_5 -> V_346 = F_144 ;
V_5 -> V_347 = F_151 ;
V_5 -> V_348 = F_76 ;
V_5 -> V_349 = F_81 ;
V_5 -> V_350 = F_149 ;
V_5 -> V_351 = V_352 ;
V_5 -> V_5 = V_8 -> V_5 ;
}
static int T_8 F_159 ( struct V_189 * V_8 ,
int V_353 )
{
int V_179 ;
F_155 ( V_8 , & V_8 -> V_354 , V_8 -> V_355 ,
0 , V_8 -> V_207 ) ;
F_124 ( V_8 -> V_354 . V_238 ) ;
F_125 ( V_240 , V_8 -> V_354 . V_238 ) ;
F_125 ( V_341 , V_8 -> V_354 . V_238 ) ;
F_158 ( V_8 , & V_8 -> V_354 ) ;
V_179 = F_160 ( & V_8 -> V_354 ) ;
if ( V_179 ) {
F_96 ( V_8 -> V_5 , L_46 ) ;
goto exit;
}
F_155 ( V_8 , & V_8 -> V_356 , V_8 -> V_355 ,
V_8 -> V_207 , V_8 -> V_357 ) ;
F_124 ( V_8 -> V_356 . V_238 ) ;
F_125 ( V_239 , V_8 -> V_356 . V_238 ) ;
F_125 ( V_339 , V_8 -> V_356 . V_238 ) ;
F_158 ( V_8 , & V_8 -> V_356 ) ;
V_179 = F_160 ( & V_8 -> V_356 ) ;
if ( V_179 ) {
F_96 ( V_8 -> V_5 ,
L_47 ) ;
goto V_358;
}
F_155 ( V_8 , & V_8 -> V_359 , V_8 -> V_360 ,
0 , V_353 ) ;
F_124 ( V_8 -> V_359 . V_238 ) ;
F_125 ( V_240 , V_8 -> V_359 . V_238 ) ;
F_125 ( V_239 , V_8 -> V_359 . V_238 ) ;
F_125 ( V_339 , V_8 -> V_359 . V_238 ) ;
F_125 ( V_341 , V_8 -> V_354 . V_238 ) ;
F_158 ( V_8 , & V_8 -> V_359 ) ;
V_179 = F_160 ( & V_8 -> V_359 ) ;
if ( V_179 ) {
F_96 ( V_8 -> V_5 ,
L_48 ) ;
goto V_361;
}
return 0 ;
V_361:
F_161 ( & V_8 -> V_356 ) ;
V_358:
F_161 ( & V_8 -> V_354 ) ;
exit:
return V_179 ;
}
static int F_162 ( struct V_1 * V_5 )
{
struct V_362 * V_363 = F_163 ( V_5 ) ;
struct V_189 * V_8 = F_164 ( V_363 ) ;
int V_34 ;
V_34 = F_165 ( V_5 ) ;
if ( V_34 )
return V_34 ;
if ( V_8 -> V_364 )
V_34 = F_166 ( V_8 -> V_364 ) ;
return V_34 ;
}
static int F_167 ( struct V_1 * V_5 )
{
struct V_362 * V_363 = F_163 ( V_5 ) ;
struct V_189 * V_8 = F_164 ( V_363 ) ;
int V_34 = 0 ;
if ( V_8 -> V_364 ) {
V_34 = F_168 ( V_8 -> V_364 ) ;
if ( V_34 )
return V_34 ;
}
return F_169 ( V_5 ) ;
}
static void F_170 ( void T_1 * V_365 , T_2 * V_366 ,
T_2 * V_367 , int V_12 , bool V_368 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ ) {
void T_1 * V_124 = V_365 + V_367 [ V_33 ] ;
if ( V_368 )
V_366 [ V_33 ] = F_171 ( V_124 ) ;
else
F_172 ( V_366 [ V_33 ] , V_124 ) ;
}
}
static void F_173 ( struct V_189 * V_8 , bool V_368 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_8 -> V_208 ; V_33 ++ ) {
void T_1 * V_124 ;
int V_39 ;
if ( V_8 -> V_228 [ V_33 ] . V_369 )
continue;
V_124 = V_8 -> V_9 + V_10 + V_33 * V_13 ;
V_39 = V_33 * F_174 ( V_370 ) ;
F_170 ( V_124 , & V_8 -> V_371 [ V_39 ] ,
V_370 ,
F_174 ( V_370 ) ,
V_368 ) ;
}
F_170 ( V_8 -> V_9 , V_8 -> V_372 ,
V_373 , F_174 ( V_373 ) ,
V_368 ) ;
if ( V_8 -> V_191 . V_366 )
F_170 ( V_8 -> V_9 , V_8 -> V_374 ,
V_8 -> V_191 . V_366 ,
V_8 -> V_191 . V_375 ,
V_368 ) ;
}
static int F_175 ( struct V_1 * V_5 )
{
struct V_362 * V_363 = F_163 ( V_5 ) ;
struct V_189 * V_8 = F_164 ( V_363 ) ;
F_173 ( V_8 , true ) ;
if ( V_8 -> V_281 != 1 )
F_172 ( V_8 -> V_376 ,
V_8 -> V_9 + V_377 ) ;
return 0 ;
}
static int F_176 ( struct V_1 * V_5 )
{
struct V_362 * V_363 = F_163 ( V_5 ) ;
struct V_189 * V_8 = F_164 ( V_363 ) ;
F_173 ( V_8 , false ) ;
F_172 ( V_378 ,
V_8 -> V_9 + V_377 ) ;
return 0 ;
}
static int T_8 F_177 ( struct V_189 * V_8 )
{
int V_33 ;
int V_379 = 0 ;
T_2 V_134 [ 2 ] ;
int V_380 = - 2 ;
int V_381 = V_382 ;
V_134 [ 0 ] = F_53 ( V_8 -> V_9 + V_383 ) ;
V_134 [ 1 ] = F_53 ( V_8 -> V_9 + V_384 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_208 ; V_33 ++ ) {
V_8 -> V_228 [ V_33 ] . V_12 = V_33 ;
V_380 += 2 * ( ( V_33 % 2 ) == 0 ) ;
if ( ( ( V_134 [ V_33 % 2 ] >> V_380 ) & 3 ) == 1 ) {
V_8 -> V_228 [ V_33 ] . V_215 = V_218 ;
V_8 -> V_228 [ V_33 ] . V_216 = V_218 ;
V_8 -> V_228 [ V_33 ] . V_369 = true ;
V_381 |= F_178 ( F_179 ( V_33 ) ,
V_385 ) ;
V_381 |= F_178 ( F_179 ( V_33 ) ,
V_386 ) ;
} else {
V_8 -> V_228 [ V_33 ] . V_215 = V_217 ;
V_8 -> V_228 [ V_33 ] . V_216 = V_217 ;
V_8 -> V_228 [ V_33 ] . V_369 = false ;
V_379 ++ ;
}
F_156 ( & V_8 -> V_228 [ V_33 ] . V_37 ) ;
}
for ( V_33 = 0 ; V_8 -> V_74 -> V_387 [ V_33 ] != - 1 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_387 [ V_33 ] ;
V_8 -> V_228 [ V_4 ] . V_215 = V_218 ;
V_8 -> V_228 [ V_4 ] . V_216 = V_218 ;
V_8 -> V_228 [ V_4 ] . V_369 = true ;
V_381 |= F_178 ( F_179 ( V_4 ) ,
V_385 ) ;
V_381 |= F_178 ( F_179 ( V_4 ) ,
V_386 ) ;
V_379 -- ;
}
for ( V_33 = 0 ; V_33 < V_8 -> V_74 -> V_388 ; V_33 ++ ) {
int V_4 = V_8 -> V_74 -> V_389 [ V_33 ] ;
V_8 -> V_228 [ V_4 ] . V_76 = true ;
}
F_180 ( V_8 -> V_5 , L_49 ,
V_379 , V_8 -> V_208 ) ;
V_134 [ 0 ] = F_53 ( V_8 -> V_9 + V_390 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_208 ; V_33 ++ ) {
if ( V_8 -> V_228 [ V_33 ] . V_215 == V_217 &&
( V_134 [ 0 ] & 0x3 ) != 1 )
F_180 ( V_8 -> V_5 ,
L_50 ,
V_129 , V_33 , V_134 [ 0 ] & 0x3 ) ;
V_134 [ 0 ] = V_134 [ 0 ] >> 2 ;
}
F_30 ( V_378 , V_8 -> V_9 + V_377 ) ;
V_8 -> V_376 = V_381 ;
return V_379 ;
}
static struct V_189 * T_8 F_181 ( struct V_362 * V_363 )
{
struct V_391 * V_74 = F_182 ( & V_363 -> V_5 ) ;
struct V_392 * V_392 ;
void T_1 * V_9 ;
struct V_393 * V_174 ;
struct V_189 * V_8 ;
int V_207 ;
int V_208 ;
int V_357 ;
int V_394 = - V_35 ;
int V_33 ;
T_2 V_395 ;
T_2 V_396 ;
T_9 V_281 ;
V_392 = F_183 ( & V_363 -> V_5 , NULL ) ;
if ( F_184 ( V_392 ) ) {
F_96 ( & V_363 -> V_5 , L_51 ) ;
goto V_397;
}
V_394 = F_185 ( V_392 ) ;
if ( V_394 ) {
F_96 ( & V_363 -> V_5 , L_52 ) ;
goto V_398;
}
V_174 = F_186 ( V_363 , V_399 , L_53 ) ;
if ( ! V_174 )
goto V_398;
if ( F_187 ( V_174 -> V_400 , F_188 ( V_174 ) ,
V_401 L_54 ) == NULL )
goto V_402;
V_9 = F_189 ( V_174 -> V_400 , F_188 ( V_174 ) ) ;
if ( ! V_9 )
goto V_402;
for ( V_395 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_395 |= ( F_53 ( V_9 + F_188 ( V_174 ) - 0x20 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
for ( V_396 = 0 , V_33 = 0 ; V_33 < 4 ; V_33 ++ )
V_396 |= ( F_53 ( V_9 + F_188 ( V_174 ) - 0x10 + 4 * V_33 )
& 255 ) << ( V_33 * 8 ) ;
if ( V_396 != V_403 ) {
F_96 ( & V_363 -> V_5 , L_55 ) ;
goto V_404;
}
if ( F_190 ( V_395 ) != V_405 ) {
F_96 ( & V_363 -> V_5 , L_56 ,
F_190 ( V_395 ) ,
V_405 ) ;
goto V_404;
}
V_281 = F_191 ( V_395 ) ;
if ( V_281 < 2 ) {
F_96 ( & V_363 -> V_5 , L_57 , V_281 ) ;
goto V_404;
}
if ( V_74 -> V_406 )
V_208 = V_74 -> V_406 ;
else
V_208 = 4 * ( F_53 ( V_9 + V_407 ) & 0x7 ) + 4 ;
if ( V_74 -> V_408 )
V_357 = V_74 -> V_408 ;
else
V_357 = F_174 ( V_242 ) ;
V_207 = V_208 * V_409 ;
F_180 ( & V_363 -> V_5 ,
L_58 ,
V_281 , & V_174 -> V_400 , V_208 , V_207 ) ;
V_8 = F_192 ( F_47 ( sizeof( struct V_189 ) , 4 ) +
( V_208 + V_207 + V_357 ) *
sizeof( struct V_2 ) , V_410 ) ;
if ( V_8 == NULL )
goto V_404;
V_8 -> V_281 = V_281 ;
V_8 -> V_392 = V_392 ;
V_8 -> V_357 = V_357 ;
V_8 -> V_208 = V_208 ;
V_8 -> V_207 = V_207 ;
V_8 -> V_411 = V_174 -> V_400 ;
V_8 -> V_412 = F_188 ( V_174 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_5 = & V_363 -> V_5 ;
V_8 -> V_360 = ( ( void * ) V_8 ) + F_47 ( sizeof( struct V_189 ) , 4 ) ;
V_8 -> V_355 = & V_8 -> V_360 [ V_208 ] ;
if ( V_8 -> V_74 -> V_406 == 14 ) {
V_8 -> V_191 . V_366 = V_413 ;
V_8 -> V_191 . V_375 = V_414 ;
V_8 -> V_191 . V_415 = V_416 ;
V_8 -> V_191 . V_417 = V_418 ;
V_8 -> V_191 . V_277 = V_419 ;
V_8 -> V_191 . V_278 = V_420 ;
V_8 -> V_191 . V_279 = V_421 ;
V_8 -> V_191 . V_280 = V_422 ;
V_8 -> V_191 . V_194 = V_423 ;
V_8 -> V_191 . V_192 = F_174 ( V_423 ) ;
V_8 -> V_191 . V_424 = V_425 ;
V_8 -> V_191 . V_426 = F_174 ( V_425 ) ;
} else {
if ( V_8 -> V_281 >= 3 ) {
V_8 -> V_191 . V_366 = V_427 ;
V_8 -> V_191 . V_375 = V_428 ;
}
V_8 -> V_191 . V_415 = V_429 ;
V_8 -> V_191 . V_417 = V_430 ;
V_8 -> V_191 . V_277 = V_431 ;
V_8 -> V_191 . V_278 = V_432 ;
V_8 -> V_191 . V_279 = V_433 ;
V_8 -> V_191 . V_280 = V_434 ;
V_8 -> V_191 . V_194 = V_435 ;
V_8 -> V_191 . V_192 = F_174 ( V_435 ) ;
V_8 -> V_191 . V_424 = V_436 ;
V_8 -> V_191 . V_426 = F_174 ( V_436 ) ;
}
V_8 -> V_228 = F_142 ( V_208 ,
sizeof( * V_8 -> V_228 ) ,
V_410 ) ;
if ( ! V_8 -> V_228 )
goto V_437;
V_8 -> V_198 = F_142 ( V_208 ,
sizeof( * V_8 -> V_198 ) ,
V_410 ) ;
if ( ! V_8 -> V_198 )
goto V_438;
V_8 -> V_199 = F_142 ( V_207 ,
sizeof( * V_8 -> V_199 ) ,
V_410 ) ;
if ( ! V_8 -> V_199 )
goto V_439;
V_8 -> V_371 = F_193 ( V_8 -> V_208 ,
sizeof( V_370 ) ,
V_410 ) ;
if ( ! V_8 -> V_371 )
goto V_440;
V_8 -> V_36 . V_40 = F_142 ( V_208
* V_38 ,
sizeof( * V_8 -> V_36 . V_40 ) ,
V_410 ) ;
if ( ! V_8 -> V_36 . V_40 )
goto V_441;
V_8 -> V_48 = F_194 ( V_401 , sizeof( struct V_14 ) ,
0 , V_442 ,
NULL ) ;
if ( V_8 -> V_48 == NULL )
goto V_443;
return V_8 ;
V_443:
F_10 ( V_8 -> V_36 . V_40 ) ;
V_441:
F_10 ( V_8 -> V_371 ) ;
V_440:
F_10 ( V_8 -> V_199 ) ;
V_439:
F_10 ( V_8 -> V_198 ) ;
V_438:
F_10 ( V_8 -> V_228 ) ;
V_437:
F_10 ( V_8 ) ;
V_404:
F_195 ( V_9 ) ;
V_402:
F_196 ( V_174 -> V_400 , F_188 ( V_174 ) ) ;
V_397:
if ( ! V_394 )
V_398:
F_197 ( V_392 ) ;
if ( ! F_184 ( V_392 ) )
F_198 ( V_392 ) ;
return NULL ;
}
static void T_8 F_199 ( struct V_189 * V_8 )
{
int V_33 ;
T_2 V_444 [ 2 ] = { 0 , 0 } ;
T_2 V_445 [ 2 ] = { 0xFFFFFFFF , 0xFFFFFFFF } ;
T_2 V_446 = 0 ;
T_2 V_447 = 0 ;
struct V_448 * V_449 = V_8 -> V_191 . V_424 ;
T_2 V_450 = V_8 -> V_191 . V_426 ;
for ( V_33 = 0 ; V_33 < V_450 ; V_33 ++ )
F_30 ( V_449 [ V_33 ] . V_134 ,
V_8 -> V_9 + V_449 [ V_33 ] . V_123 ) ;
for ( V_33 = 0 ; V_33 < V_8 -> V_208 ; V_33 ++ ) {
V_445 [ V_33 % 2 ] = V_445 [ V_33 % 2 ] << 2 ;
if ( V_8 -> V_228 [ V_8 -> V_208 - V_33 - 1 ] . V_215
== V_218 ) {
V_445 [ V_33 % 2 ] |= 3 ;
continue;
}
V_446 = ( V_446 << 1 ) | 1 ;
V_447 = ( V_447 << 1 ) | 1 ;
V_444 [ V_33 % 2 ] = V_444 [ V_33 % 2 ] << 2 ;
V_444 [ V_33 % 2 ] |= 1 ;
}
F_30 ( V_444 [ 1 ] , V_8 -> V_9 + V_154 ) ;
F_30 ( V_444 [ 0 ] , V_8 -> V_9 + V_451 ) ;
F_30 ( V_445 [ 1 ] , V_8 -> V_9 + V_112 ) ;
F_30 ( V_445 [ 0 ] , V_8 -> V_9 + V_113 ) ;
F_30 ( V_446 , V_8 -> V_9 + V_8 -> V_191 . V_415 ) ;
F_30 ( V_447 , V_8 -> V_9 + V_8 -> V_191 . V_417 ) ;
V_8 -> V_191 . V_424 = NULL ;
V_8 -> V_191 . V_426 = 0 ;
}
static int T_8 F_200 ( struct V_189 * V_8 )
{
struct V_65 * V_66 = & V_8 -> V_36 ;
unsigned long * V_452 ;
int V_33 , V_227 ;
int V_34 ;
V_452 = F_193 ( V_453 ,
sizeof( * V_452 ) ,
V_410 ) ;
if ( ! V_452 )
return - V_25 ;
V_8 -> V_36 . V_454 = V_455 * V_8 -> V_208 / V_456 ;
for ( V_33 = 0 ; V_33 < V_453 ; V_33 ++ ) {
V_452 [ V_33 ] = F_201 ( V_410 ,
V_8 -> V_36 . V_454 ) ;
if ( ! V_452 [ V_33 ] ) {
F_96 ( V_8 -> V_5 , L_59 ,
V_8 -> V_36 . V_454 ) ;
V_34 = - V_25 ;
for ( V_227 = 0 ; V_227 < V_33 ; V_227 ++ )
F_202 ( V_452 [ V_227 ] , V_8 -> V_36 . V_454 ) ;
goto V_457;
}
if ( ( F_114 ( ( void * ) V_452 [ V_33 ] ) &
( V_458 - 1 ) ) == 0 )
break;
}
for ( V_227 = 0 ; V_227 < V_33 ; V_227 ++ )
F_202 ( V_452 [ V_227 ] , V_8 -> V_36 . V_454 ) ;
if ( V_33 < V_453 ) {
V_8 -> V_36 . V_8 = ( void * ) V_452 [ V_33 ] ;
} else {
F_203 ( V_8 -> V_5 ,
L_60 ,
V_129 , V_8 -> V_36 . V_454 ) ;
V_8 -> V_36 . V_459 = F_6 ( V_455 *
V_8 -> V_208 +
V_458 ,
V_410 ) ;
if ( ! V_8 -> V_36 . V_459 ) {
V_34 = - V_25 ;
goto V_457;
}
V_8 -> V_36 . V_8 = F_7 ( V_8 -> V_36 . V_459 ,
V_458 ) ;
}
V_66 -> V_29 = F_8 ( V_8 -> V_5 , V_66 -> V_8 ,
V_455 * V_8 -> V_208 ,
V_31 ) ;
if ( F_9 ( V_8 -> V_5 , V_66 -> V_29 ) ) {
V_66 -> V_29 = 0 ;
V_34 = - V_25 ;
goto V_457;
}
F_30 ( F_114 ( V_8 -> V_36 . V_8 ) ,
V_8 -> V_9 + V_460 ) ;
V_34 = 0 ;
V_457:
F_10 ( V_452 ) ;
return V_34 ;
}
static int T_8 F_204 ( struct V_362 * V_363 ,
struct V_333 * V_461 )
{
struct V_391 * V_462 ;
int V_463 = 0 , V_464 = 0 , V_465 = 0 ;
const T_10 * V_466 ;
V_462 = F_205 ( & V_363 -> V_5 , sizeof( * V_462 ) , V_410 ) ;
if ( ! V_462 )
return - V_25 ;
F_206 ( V_461 , L_61 , & V_463 ) ;
if ( V_463 > 0 )
V_462 -> V_406 = V_463 ;
V_466 = F_207 ( V_461 , L_62 , & V_464 ) ;
V_464 /= sizeof( * V_466 ) ;
if ( V_464 > V_467 || V_464 <= 0 ) {
F_96 ( & V_363 -> V_5 ,
L_63 ,
V_464 ) ;
return - V_35 ;
}
V_462 -> V_408 = V_464 ;
F_208 ( V_461 , L_62 ,
V_242 ,
V_464 ) ;
V_466 = F_207 ( V_461 , L_64 , & V_465 ) ;
V_465 /= sizeof( * V_466 ) ;
if ( V_465 >= V_468 || V_465 < 0 ) {
F_96 ( & V_363 -> V_5 ,
L_65 ,
V_465 ) ;
return - V_35 ;
}
F_208 ( V_461 , L_64 ,
V_462 -> V_387 ,
V_465 ) ;
V_462 -> V_387 [ V_465 ] = - 1 ;
V_363 -> V_5 . V_469 = V_462 ;
return 0 ;
}
static int T_8 F_209 ( struct V_362 * V_363 )
{
struct V_391 * V_74 = F_182 ( & V_363 -> V_5 ) ;
struct V_333 * V_461 = V_363 -> V_5 . V_470 ;
int V_34 = - V_471 ;
struct V_189 * V_8 ;
struct V_393 * V_174 ;
int V_353 ;
T_2 V_134 ;
if ( ! V_74 ) {
if ( V_461 ) {
if ( F_204 ( V_363 , V_461 ) ) {
V_34 = - V_25 ;
goto V_472;
}
} else {
F_96 ( & V_363 -> V_5 , L_66 ) ;
goto V_472;
}
}
V_8 = F_181 ( V_363 ) ;
if ( ! V_8 )
goto V_472;
V_353 = F_177 ( V_8 ) ;
F_210 ( V_363 , V_8 ) ;
F_156 ( & V_8 -> V_195 ) ;
F_156 ( & V_8 -> V_111 ) ;
V_174 = F_186 ( V_363 , V_399 , L_67 ) ;
if ( ! V_174 ) {
V_34 = - V_471 ;
F_96 ( & V_363 -> V_5 , L_68 ) ;
goto V_473;
}
V_8 -> V_474 = F_188 ( V_174 ) ;
V_8 -> V_475 = V_174 -> V_400 ;
if ( F_187 ( V_174 -> V_400 , F_188 ( V_174 ) ,
V_401 L_69 ) == NULL ) {
V_34 = - V_117 ;
F_96 ( & V_363 -> V_5 , L_70 , V_174 ) ;
goto V_473;
}
V_134 = F_53 ( V_8 -> V_9 + V_476 ) ;
if ( V_174 -> V_400 != V_134 && V_134 != 0 ) {
F_203 ( & V_363 -> V_5 ,
L_71 ,
V_129 , V_134 , & V_174 -> V_400 ) ;
} else
F_30 ( V_174 -> V_400 , V_8 -> V_9 + V_476 ) ;
V_8 -> V_289 = F_189 ( V_174 -> V_400 , F_188 ( V_174 ) ) ;
if ( ! V_8 -> V_289 ) {
V_34 = - V_25 ;
F_96 ( & V_363 -> V_5 , L_72 ) ;
goto V_473;
}
if ( V_8 -> V_74 -> V_73 ) {
V_174 = F_186 ( V_363 , V_399 ,
L_73 ) ;
if ( ! V_174 ) {
V_34 = - V_471 ;
F_96 ( & V_363 -> V_5 ,
L_74 ) ;
goto V_473;
}
V_8 -> V_36 . V_8 = F_189 ( V_174 -> V_400 ,
F_188 ( V_174 ) ) ;
if ( ! V_8 -> V_36 . V_8 ) {
V_34 = - V_25 ;
F_96 ( & V_363 -> V_5 , L_75 ) ;
goto V_473;
}
F_30 ( V_174 -> V_400 , V_8 -> V_9 + V_460 ) ;
} else {
V_34 = F_200 ( V_8 ) ;
if ( V_34 ) {
F_96 ( & V_363 -> V_5 , L_76 ) ;
goto V_473;
}
}
F_156 ( & V_8 -> V_36 . V_37 ) ;
V_8 -> V_187 = F_211 ( V_363 , 0 ) ;
V_34 = F_212 ( V_8 -> V_187 , F_92 , 0 , V_401 , V_8 ) ;
if ( V_34 ) {
F_96 ( & V_363 -> V_5 , L_77 ) ;
goto V_473;
}
if ( V_8 -> V_74 -> V_73 ) {
V_8 -> V_364 = F_213 ( V_8 -> V_5 , L_73 ) ;
if ( F_184 ( V_8 -> V_364 ) ) {
F_96 ( & V_363 -> V_5 , L_78 ) ;
V_34 = F_214 ( V_8 -> V_364 ) ;
V_8 -> V_364 = NULL ;
goto V_473;
}
V_34 = F_168 ( V_8 -> V_364 ) ;
if ( V_34 ) {
F_96 ( & V_363 -> V_5 ,
L_79 ) ;
F_215 ( V_8 -> V_364 ) ;
V_8 -> V_364 = NULL ;
goto V_473;
}
}
F_172 ( V_378 , V_8 -> V_9 + V_377 ) ;
F_216 ( V_8 -> V_5 ) ;
F_217 ( V_8 -> V_5 , V_477 ) ;
F_218 ( V_8 -> V_5 ) ;
F_79 ( V_8 -> V_5 ) ;
F_219 ( V_8 -> V_5 ) ;
F_220 ( V_8 -> V_5 ) ;
V_34 = F_159 ( V_8 , V_353 ) ;
if ( V_34 )
goto V_473;
V_8 -> V_5 -> V_478 = & V_8 -> V_478 ;
V_34 = F_221 ( V_8 -> V_5 , V_98 ) ;
if ( V_34 ) {
F_96 ( & V_363 -> V_5 , L_80 ) ;
goto V_473;
}
F_199 ( V_8 ) ;
if ( V_461 ) {
V_34 = F_222 ( V_461 , F_123 , NULL ) ;
if ( V_34 )
F_103 ( & V_363 -> V_5 ,
L_81 ) ;
}
F_180 ( V_8 -> V_5 , L_82 ) ;
return 0 ;
V_473:
F_223 ( V_8 -> V_48 ) ;
if ( V_8 -> V_9 )
F_195 ( V_8 -> V_9 ) ;
if ( V_8 -> V_36 . V_8 && V_8 -> V_74 -> V_73 ) {
F_195 ( V_8 -> V_36 . V_8 ) ;
V_8 -> V_36 . V_8 = NULL ;
}
if ( V_8 -> V_36 . V_29 )
F_12 ( V_8 -> V_5 , V_8 -> V_36 . V_29 ,
V_455 * V_8 -> V_208 ,
V_31 ) ;
if ( ! V_8 -> V_36 . V_459 && V_8 -> V_36 . V_8 )
F_202 ( ( unsigned long ) V_8 -> V_36 . V_8 ,
V_8 -> V_36 . V_454 ) ;
F_10 ( V_8 -> V_36 . V_459 ) ;
if ( V_8 -> V_475 )
F_196 ( V_8 -> V_475 ,
V_8 -> V_474 ) ;
if ( V_8 -> V_411 )
F_196 ( V_8 -> V_411 ,
V_8 -> V_412 ) ;
if ( V_8 -> V_392 ) {
F_197 ( V_8 -> V_392 ) ;
F_198 ( V_8 -> V_392 ) ;
}
if ( V_8 -> V_364 ) {
F_166 ( V_8 -> V_364 ) ;
F_215 ( V_8 -> V_364 ) ;
}
F_10 ( V_8 -> V_36 . V_40 ) ;
F_10 ( V_8 -> V_199 ) ;
F_10 ( V_8 -> V_198 ) ;
F_10 ( V_8 -> V_228 ) ;
F_10 ( V_8 ) ;
V_472:
F_96 ( & V_363 -> V_5 , L_83 ) ;
return V_34 ;
}
static int T_8 F_224 ( void )
{
return F_225 ( & V_479 , F_209 ) ;
}
