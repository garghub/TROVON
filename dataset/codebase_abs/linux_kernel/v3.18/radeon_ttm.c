static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
static int F_12 ( struct V_2 * V_3 , T_1 V_26 )
{
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_1 type ,
struct V_27 * V_28 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_29 :
V_28 -> V_26 = V_30 ;
V_28 -> V_31 = V_32 ;
V_28 -> V_33 = V_34 ;
break;
case V_35 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_40 ;
V_28 -> V_31 = V_32 ;
V_28 -> V_33 = V_34 ;
V_28 -> V_26 = V_30 | V_41 ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
if ( ! V_6 -> V_44 -> V_45 ) {
F_9 ( L_4 ,
( unsigned ) type ) ;
return - V_46 ;
}
if ( ! V_6 -> V_44 -> V_45 -> V_47 )
V_28 -> V_26 = V_30 ;
V_28 -> V_31 = V_48 |
V_49 ;
V_28 -> V_33 = V_49 ;
}
#endif
break;
case V_50 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_51 ;
V_28 -> V_26 = V_52 |
V_30 ;
V_28 -> V_31 = V_48 | V_49 ;
V_28 -> V_33 = V_49 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_46 ;
}
return 0 ;
}
static void F_14 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
static struct V_57 V_58 = {
. V_59 = 0 ,
. V_60 = 0 ,
. V_26 = V_32 | V_61
} ;
struct V_62 * V_63 ;
if ( ! F_15 ( V_54 ) ) {
V_56 -> V_56 = & V_58 ;
V_56 -> V_64 = & V_58 ;
V_56 -> V_65 = 1 ;
V_56 -> V_66 = 1 ;
return;
}
V_63 = F_2 ( V_54 , struct V_62 , V_67 ) ;
switch ( V_54 -> V_68 . V_69 ) {
case V_50 :
if ( V_63 -> V_6 -> V_70 [ V_71 ] . V_72 == false )
F_16 ( V_63 , V_73 ) ;
else
F_16 ( V_63 , V_74 ) ;
break;
case V_35 :
default:
F_16 ( V_63 , V_73 ) ;
}
* V_56 = V_63 -> V_56 ;
}
static int F_17 ( struct V_53 * V_54 , struct V_75 * V_76 )
{
struct V_62 * V_63 = F_2 ( V_54 , struct V_62 , V_67 ) ;
return F_18 ( & V_63 -> V_77 . V_78 , V_76 ) ;
}
static void F_19 ( struct V_53 * V_54 ,
struct V_79 * V_80 )
{
struct V_79 * V_81 = & V_54 -> V_68 ;
F_20 ( V_81 -> V_82 != NULL ) ;
* V_81 = * V_80 ;
V_80 -> V_82 = NULL ;
}
static int F_21 ( struct V_53 * V_54 ,
bool V_83 , bool V_84 ,
struct V_79 * V_80 ,
struct V_79 * V_81 )
{
struct V_1 * V_6 ;
T_2 V_85 , V_86 ;
struct V_87 * V_88 ;
unsigned V_89 ;
int V_11 , V_90 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_90 = F_22 ( V_6 ) ;
V_85 = V_81 -> V_91 << V_92 ;
V_86 = V_80 -> V_91 << V_92 ;
switch ( V_81 -> V_69 ) {
case V_50 :
V_85 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_85 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_81 -> V_69 ) ;
return - V_46 ;
}
switch ( V_80 -> V_69 ) {
case V_50 :
V_86 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_86 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_81 -> V_69 ) ;
return - V_46 ;
}
if ( ! V_6 -> V_70 [ V_90 ] . V_72 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_23 ( ( V_93 % V_94 ) != 0 ) ;
V_89 = V_80 -> V_89 * ( V_93 / V_94 ) ;
V_88 = F_24 ( V_6 , V_85 , V_86 , V_89 , V_54 -> V_95 ) ;
if ( F_25 ( V_88 ) )
return F_26 ( V_88 ) ;
V_11 = F_27 ( V_54 , & V_88 -> V_96 ,
V_83 , V_84 , V_80 ) ;
F_28 ( & V_88 ) ;
return V_11 ;
}
static int F_29 ( struct V_53 * V_54 ,
bool V_83 , bool V_97 ,
bool V_84 ,
struct V_79 * V_80 )
{
struct V_1 * V_6 ;
struct V_79 * V_81 = & V_54 -> V_68 ;
struct V_79 V_98 ;
struct V_57 V_58 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_98 = * V_80 ;
V_98 . V_82 = NULL ;
V_56 . V_65 = 1 ;
V_56 . V_56 = & V_58 ;
V_56 . V_66 = 1 ;
V_56 . V_64 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_99 ;
V_11 = F_30 ( V_54 , & V_56 , & V_98 ,
V_97 , V_84 ) ;
if ( F_31 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_32 ( V_54 -> V_100 , V_98 . V_56 ) ;
if ( F_31 ( V_11 ) ) {
goto V_101;
}
V_11 = F_33 ( V_54 -> V_100 , & V_98 ) ;
if ( F_31 ( V_11 ) ) {
goto V_101;
}
V_11 = F_21 ( V_54 , true , V_84 , & V_98 , V_81 ) ;
if ( F_31 ( V_11 ) ) {
goto V_101;
}
V_11 = F_34 ( V_54 , true , V_84 , V_80 ) ;
V_101:
F_35 ( V_54 , & V_98 ) ;
return V_11 ;
}
static int F_36 ( struct V_53 * V_54 ,
bool V_83 , bool V_97 ,
bool V_84 ,
struct V_79 * V_80 )
{
struct V_1 * V_6 ;
struct V_79 * V_81 = & V_54 -> V_68 ;
struct V_79 V_98 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_98 = * V_80 ;
V_98 . V_82 = NULL ;
V_56 . V_65 = 1 ;
V_56 . V_56 = & V_58 ;
V_56 . V_66 = 1 ;
V_56 . V_64 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_99 ;
V_11 = F_30 ( V_54 , & V_56 , & V_98 ,
V_97 , V_84 ) ;
if ( F_31 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_34 ( V_54 , true , V_84 , & V_98 ) ;
if ( F_31 ( V_11 ) ) {
goto V_101;
}
V_11 = F_21 ( V_54 , true , V_84 , V_80 , V_81 ) ;
if ( F_31 ( V_11 ) ) {
goto V_101;
}
V_101:
F_35 ( V_54 , & V_98 ) ;
return V_11 ;
}
static int F_37 ( struct V_53 * V_54 ,
bool V_83 , bool V_97 ,
bool V_84 ,
struct V_79 * V_80 )
{
struct V_1 * V_6 ;
struct V_79 * V_81 = & V_54 -> V_68 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_81 -> V_69 == V_29 && V_54 -> V_100 == NULL ) {
F_19 ( V_54 , V_80 ) ;
return 0 ;
}
if ( ( V_81 -> V_69 == V_35 &&
V_80 -> V_69 == V_29 ) ||
( V_81 -> V_69 == V_29 &&
V_80 -> V_69 == V_35 ) ) {
F_19 ( V_54 , V_80 ) ;
return 0 ;
}
if ( ! V_6 -> V_70 [ F_22 ( V_6 ) ] . V_72 ||
V_6 -> V_102 -> V_103 . V_103 == NULL ) {
goto memcpy;
}
if ( V_81 -> V_69 == V_50 &&
V_80 -> V_69 == V_29 ) {
V_11 = F_29 ( V_54 , V_83 , V_97 ,
V_84 , V_80 ) ;
} else if ( V_81 -> V_69 == V_29 &&
V_80 -> V_69 == V_50 ) {
V_11 = F_36 ( V_54 , V_83 , V_97 ,
V_84 , V_80 ) ;
} else {
V_11 = F_21 ( V_54 , V_83 , V_84 , V_80 , V_81 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_38 ( V_54 , V_83 , V_84 , V_80 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_39 ( ( V_104 ) V_54 -> V_89 << V_92 , & V_6 -> V_105 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_79 * V_68 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_68 -> V_69 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_68 -> V_106 . V_107 = NULL ;
V_68 -> V_106 . V_108 = 0 ;
V_68 -> V_106 . V_16 = V_68 -> V_89 << V_92 ;
V_68 -> V_106 . V_96 = 0 ;
V_68 -> V_106 . V_109 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_68 -> V_69 ) {
case V_29 :
return 0 ;
case V_35 :
#if V_42
if ( V_6 -> V_26 & V_43 ) {
V_68 -> V_106 . V_108 = V_68 -> V_91 << V_92 ;
V_68 -> V_106 . V_96 = V_6 -> V_39 . V_110 ;
V_68 -> V_106 . V_109 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_68 -> V_106 . V_108 = V_68 -> V_91 << V_92 ;
if ( ( V_68 -> V_106 . V_108 + V_68 -> V_106 . V_16 ) > V_6 -> V_39 . V_111 )
return - V_46 ;
V_68 -> V_106 . V_96 = V_6 -> V_39 . V_112 ;
V_68 -> V_106 . V_109 = true ;
#ifdef F_41
if ( V_68 -> V_56 & V_49 )
V_68 -> V_106 . V_107 =
F_42 ( V_68 -> V_106 . V_96 + V_68 -> V_106 . V_108 ,
V_68 -> V_106 . V_16 ) ;
else
V_68 -> V_106 . V_107 =
F_43 ( V_68 -> V_106 . V_96 + V_68 -> V_106 . V_108 ,
V_68 -> V_106 . V_16 ) ;
V_68 -> V_106 . V_96 = ( V_68 -> V_106 . V_96 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_113 -> V_114 ;
#endif
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_44 ( struct V_2 * V_3 , struct V_79 * V_68 )
{
}
static int F_45 ( struct V_115 * V_100 )
{
struct V_1 * V_6 = F_1 ( V_100 -> V_3 ) ;
struct V_116 * V_117 = ( void * ) V_100 ;
unsigned V_118 = 0 , V_119 ;
int V_11 ;
int V_120 = ! ( V_117 -> V_121 & V_122 ) ;
enum V_123 V_124 = V_120 ?
V_125 : V_126 ;
if ( V_127 -> V_128 != V_117 -> V_129 )
return - V_130 ;
if ( V_117 -> V_121 & V_131 ) {
unsigned long V_132 = V_117 -> V_133 + V_100 -> V_89 * V_93 ;
struct V_134 * V_135 ;
V_135 = F_46 ( V_117 -> V_129 , V_117 -> V_133 ) ;
if ( ! V_135 || V_135 -> V_136 || V_135 -> V_137 < V_132 )
return - V_130 ;
}
do {
unsigned V_89 = V_100 -> V_89 - V_118 ;
T_2 V_133 = V_117 -> V_133 + V_118 * V_93 ;
struct V_138 * * V_139 = V_100 -> V_139 + V_118 ;
V_11 = F_47 ( V_127 , V_127 -> V_128 , V_133 , V_89 ,
V_120 , 0 , V_139 , NULL ) ;
if ( V_11 < 0 )
goto V_140;
V_118 += V_11 ;
} while ( V_118 < V_100 -> V_89 );
V_11 = F_48 ( V_100 -> V_141 , V_100 -> V_139 , V_100 -> V_89 , 0 ,
V_100 -> V_89 << V_92 ,
V_142 ) ;
if ( V_11 )
goto V_143;
V_11 = - V_144 ;
V_119 = F_49 ( V_6 -> V_145 , V_100 -> V_141 -> V_146 , V_100 -> V_141 -> V_119 , V_124 ) ;
if ( V_119 != V_100 -> V_141 -> V_119 )
goto V_143;
F_50 ( V_100 -> V_141 , V_100 -> V_139 ,
V_117 -> V_100 . V_147 , V_100 -> V_89 ) ;
return 0 ;
V_143:
F_51 ( V_100 -> V_141 ) ;
V_140:
V_140 ( V_100 -> V_139 , V_118 , 0 ) ;
return V_11 ;
}
static void F_52 ( struct V_115 * V_100 )
{
struct V_1 * V_6 = F_1 ( V_100 -> V_3 ) ;
struct V_116 * V_117 = ( void * ) V_100 ;
struct V_148 * V_141 ;
int V_149 ;
int V_120 = ! ( V_117 -> V_121 & V_122 ) ;
enum V_123 V_124 = V_120 ?
V_125 : V_126 ;
F_53 ( V_6 -> V_145 , V_100 -> V_141 -> V_146 , V_100 -> V_141 -> V_119 , V_124 ) ;
F_54 (ttm->sg->sgl, sg, ttm->sg->nents, i) {
struct V_138 * V_138 = F_55 ( V_141 ) ;
if ( ! ( V_117 -> V_121 & V_122 ) )
F_56 ( V_138 ) ;
F_57 ( V_138 ) ;
F_58 ( V_138 ) ;
}
F_59 ( V_100 -> V_141 ) ;
}
static int F_60 ( struct V_115 * V_100 ,
struct V_79 * V_150 )
{
struct V_116 * V_117 = ( void * ) V_100 ;
T_1 V_26 = V_151 | V_152 |
V_153 ;
int V_11 ;
if ( V_117 -> V_133 ) {
F_45 ( V_100 ) ;
V_26 &= ~ V_153 ;
}
V_117 -> V_108 = ( unsigned long ) ( V_150 -> V_91 << V_92 ) ;
if ( ! V_100 -> V_89 ) {
F_61 ( 1 , L_8 ,
V_100 -> V_89 , V_150 , V_100 ) ;
}
if ( V_100 -> V_154 == V_155 )
V_26 |= V_156 ;
V_11 = F_62 ( V_117 -> V_6 , V_117 -> V_108 , V_100 -> V_89 ,
V_100 -> V_139 , V_117 -> V_100 . V_147 , V_26 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_100 -> V_89 , ( unsigned ) V_117 -> V_108 ) ;
return V_11 ;
}
return 0 ;
}
static int F_63 ( struct V_115 * V_100 )
{
struct V_116 * V_117 = ( void * ) V_100 ;
F_64 ( V_117 -> V_6 , V_117 -> V_108 , V_100 -> V_89 ) ;
if ( V_117 -> V_133 )
F_52 ( V_100 ) ;
return 0 ;
}
static void F_65 ( struct V_115 * V_100 )
{
struct V_116 * V_117 = ( void * ) V_100 ;
F_66 ( & V_117 -> V_100 ) ;
F_51 ( V_117 ) ;
}
static struct V_115 * F_67 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_157 ,
struct V_138 * V_158 )
{
struct V_1 * V_6 ;
struct V_116 * V_117 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_68 ( V_3 , V_6 -> V_44 -> V_45 -> V_159 ,
V_16 , V_157 , V_158 ) ;
}
#endif
V_117 = F_69 ( sizeof( struct V_116 ) , V_142 ) ;
if ( V_117 == NULL ) {
return NULL ;
}
V_117 -> V_100 . V_100 . V_36 = & V_160 ;
V_117 -> V_6 = V_6 ;
if ( F_70 ( & V_117 -> V_100 , V_3 , V_16 , V_157 , V_158 ) ) {
F_51 ( V_117 ) ;
return NULL ;
}
return & V_117 -> V_100 . V_100 ;
}
static struct V_116 * F_71 ( struct V_115 * V_100 )
{
if ( ! V_100 || V_100 -> V_36 != & V_160 )
return NULL ;
return (struct V_116 * ) V_100 ;
}
static int F_72 ( struct V_115 * V_100 )
{
struct V_116 * V_117 = F_71 ( V_100 ) ;
struct V_1 * V_6 ;
unsigned V_149 ;
int V_11 ;
bool V_161 = ! ! ( V_100 -> V_157 & V_162 ) ;
if ( V_100 -> V_163 != V_164 )
return 0 ;
if ( V_117 && V_117 -> V_133 ) {
V_100 -> V_141 = F_73 ( 1 , sizeof( struct V_165 ) , V_142 ) ;
if ( ! V_100 -> V_141 )
return - V_144 ;
V_100 -> V_157 |= V_162 ;
V_100 -> V_163 = V_166 ;
return 0 ;
}
if ( V_161 && V_100 -> V_141 ) {
F_50 ( V_100 -> V_141 , V_100 -> V_139 ,
V_117 -> V_100 . V_147 , V_100 -> V_89 ) ;
V_100 -> V_163 = V_166 ;
return 0 ;
}
V_6 = F_1 ( V_100 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_74 ( V_100 ) ;
}
#endif
#ifdef F_75
if ( F_76 () ) {
return F_77 ( & V_117 -> V_100 , V_6 -> V_145 ) ;
}
#endif
V_11 = F_78 ( V_100 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_149 = 0 ; V_149 < V_100 -> V_89 ; V_149 ++ ) {
V_117 -> V_100 . V_147 [ V_149 ] = F_79 ( V_6 -> V_167 , V_100 -> V_139 [ V_149 ] ,
0 , V_93 ,
V_168 ) ;
if ( F_80 ( V_6 -> V_167 , V_117 -> V_100 . V_147 [ V_149 ] ) ) {
while ( -- V_149 ) {
F_81 ( V_6 -> V_167 , V_117 -> V_100 . V_147 [ V_149 ] ,
V_93 , V_168 ) ;
V_117 -> V_100 . V_147 [ V_149 ] = 0 ;
}
F_82 ( V_100 ) ;
return - V_169 ;
}
}
return 0 ;
}
static void F_83 ( struct V_115 * V_100 )
{
struct V_1 * V_6 ;
struct V_116 * V_117 = F_71 ( V_100 ) ;
unsigned V_149 ;
bool V_161 = ! ! ( V_100 -> V_157 & V_162 ) ;
if ( V_117 && V_117 -> V_133 ) {
F_51 ( V_100 -> V_141 ) ;
V_100 -> V_157 &= ~ V_162 ;
return;
}
if ( V_161 )
return;
V_6 = F_1 ( V_100 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
F_84 ( V_100 ) ;
return;
}
#endif
#ifdef F_75
if ( F_76 () ) {
F_85 ( & V_117 -> V_100 , V_6 -> V_145 ) ;
return;
}
#endif
for ( V_149 = 0 ; V_149 < V_100 -> V_89 ; V_149 ++ ) {
if ( V_117 -> V_100 . V_147 [ V_149 ] ) {
F_81 ( V_6 -> V_167 , V_117 -> V_100 . V_147 [ V_149 ] ,
V_93 , V_168 ) ;
}
}
F_82 ( V_100 ) ;
}
int F_86 ( struct V_115 * V_100 , T_2 V_107 ,
T_1 V_26 )
{
struct V_116 * V_117 = F_71 ( V_100 ) ;
if ( V_117 == NULL )
return - V_46 ;
V_117 -> V_133 = V_107 ;
V_117 -> V_129 = V_127 -> V_128 ;
V_117 -> V_121 = V_26 ;
return 0 ;
}
bool F_87 ( struct V_115 * V_100 )
{
struct V_116 * V_117 = F_71 ( V_100 ) ;
if ( V_117 == NULL )
return false ;
return ! ! V_117 -> V_133 ;
}
bool F_88 ( struct V_115 * V_100 )
{
struct V_116 * V_117 = F_71 ( V_100 ) ;
if ( V_117 == NULL )
return false ;
return ! ! ( V_117 -> V_121 & V_122 ) ;
}
int F_89 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_90 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_170 ,
V_6 -> V_44 -> V_171 -> V_172 ,
V_173 ,
V_6 -> V_174 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_175 = true ;
V_11 = F_91 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_176 >> V_92 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_92 ( V_6 , V_6 -> V_39 . V_111 ) ;
V_11 = F_93 ( V_6 , 256 * 1024 , V_93 , true ,
V_177 , 0 , NULL ,
NULL , & V_6 -> V_178 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_94 ( V_6 -> V_178 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_95 ( V_6 -> V_178 , V_177 , NULL ) ;
F_96 ( V_6 -> V_178 ) ;
if ( V_11 ) {
F_97 ( & V_6 -> V_178 ) ;
return V_11 ;
}
F_98 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_176 / ( 1024 * 1024 ) ) ) ;
V_11 = F_91 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_179 >> V_92 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_98 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_179 / ( 1024 * 1024 ) ) ) ;
V_11 = F_99 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_100 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_175 )
return;
F_101 ( V_6 ) ;
if ( V_6 -> V_178 ) {
V_11 = F_94 ( V_6 -> V_178 , false ) ;
if ( V_11 == 0 ) {
F_102 ( V_6 -> V_178 ) ;
F_96 ( V_6 -> V_178 ) ;
}
F_97 ( & V_6 -> V_178 ) ;
}
F_103 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_103 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_104 ( & V_6 -> V_5 . V_3 ) ;
F_105 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_175 = false ;
F_98 ( L_16 ) ;
}
void F_92 ( struct V_1 * V_6 , V_104 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_175 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_92 ;
}
static int F_106 ( struct V_134 * V_135 , struct V_180 * V_181 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_135 -> V_182 ;
if ( V_54 == NULL ) {
return V_183 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_107 ( & V_6 -> V_184 . V_185 ) ;
V_11 = V_186 -> V_187 ( V_135 , V_181 ) ;
F_108 ( & V_6 -> V_184 . V_185 ) ;
return V_11 ;
}
int F_109 ( struct V_75 * V_76 , struct V_134 * V_135 )
{
struct V_188 * V_189 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_31 ( V_135 -> V_190 < V_173 ) ) {
return - V_46 ;
}
V_189 = V_76 -> V_191 ;
V_6 = V_189 -> V_192 -> V_145 -> V_193 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_110 ( V_76 , V_135 , & V_6 -> V_5 . V_3 ) ;
if ( F_31 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_31 ( V_186 == NULL ) ) {
V_186 = V_135 -> V_194 ;
V_195 = * V_186 ;
V_195 . V_187 = & F_106 ;
}
V_135 -> V_194 = & V_195 ;
return 0 ;
}
static int F_111 ( struct V_196 * V_197 , void * V_198 )
{
struct V_199 * V_200 = (struct V_199 * ) V_197 -> V_201 ;
unsigned V_202 = * ( int * ) V_200 -> V_203 -> V_198 ;
struct V_204 * V_145 = V_200 -> V_192 -> V_145 ;
struct V_1 * V_6 = V_145 -> V_193 ;
struct V_205 * V_128 = (struct V_205 * ) V_6 -> V_5 . V_3 . V_28 [ V_202 ] . V_206 ;
int V_207 ;
struct V_23 * V_208 = V_6 -> V_5 . V_3 . V_208 ;
F_112 ( & V_208 -> V_209 ) ;
V_207 = F_113 ( V_197 , V_128 ) ;
F_114 ( & V_208 -> V_209 ) ;
return V_207 ;
}
static int F_115 ( struct V_210 * V_210 , struct V_75 * V_211 )
{
struct V_1 * V_6 = V_210 -> V_212 ;
F_116 ( V_210 , V_6 -> V_39 . V_213 ) ;
V_211 -> V_191 = V_210 -> V_212 ;
return 0 ;
}
static T_3 F_117 ( struct V_75 * V_214 , char T_4 * V_215 ,
T_5 V_16 , T_6 * V_216 )
{
struct V_1 * V_6 = V_214 -> V_191 ;
T_3 V_217 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_216 & 0x3 )
return - V_46 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_218 ;
if ( * V_216 >= V_6 -> V_39 . V_213 )
return V_217 ;
F_118 ( & V_6 -> V_219 , V_26 ) ;
F_119 ( V_220 , ( ( T_1 ) * V_216 ) | 0x80000000 ) ;
if ( V_6 -> V_221 >= V_222 )
F_119 ( V_223 , * V_216 >> 31 ) ;
V_218 = F_120 ( V_224 ) ;
F_121 ( & V_6 -> V_219 , V_26 ) ;
V_11 = F_122 ( V_218 , ( T_1 * ) V_215 ) ;
if ( V_11 )
return V_11 ;
V_217 += 4 ;
V_215 += 4 ;
* V_216 += 4 ;
V_16 -= 4 ;
}
return V_217 ;
}
static int F_123 ( struct V_210 * V_210 , struct V_75 * V_211 )
{
struct V_1 * V_6 = V_210 -> V_212 ;
F_116 ( V_210 , V_6 -> V_39 . V_179 ) ;
V_211 -> V_191 = V_210 -> V_212 ;
return 0 ;
}
static T_3 F_124 ( struct V_75 * V_214 , char T_4 * V_215 ,
T_5 V_16 , T_6 * V_216 )
{
struct V_1 * V_6 = V_214 -> V_191 ;
T_3 V_217 = 0 ;
int V_11 ;
while ( V_16 ) {
T_6 V_225 = * V_216 / V_93 ;
unsigned V_226 = * V_216 & ~ V_227 ;
T_5 V_228 = F_125 ( T_5 , V_16 , V_93 - V_226 ) ;
struct V_138 * V_138 ;
void * V_229 ;
if ( V_225 >= V_6 -> V_230 . V_231 )
return V_217 ;
V_138 = V_6 -> V_230 . V_139 [ V_225 ] ;
if ( V_138 ) {
V_229 = F_126 ( V_138 ) ;
V_229 += V_226 ;
V_11 = F_127 ( V_215 , V_229 , V_228 ) ;
F_128 ( V_6 -> V_230 . V_139 [ V_225 ] ) ;
} else
V_11 = F_129 ( V_215 , V_228 ) ;
if ( V_11 )
return - V_169 ;
V_217 += V_228 ;
V_215 += V_228 ;
* V_216 += V_228 ;
V_16 -= V_228 ;
}
return V_217 ;
}
static int F_99 ( struct V_1 * V_6 )
{
#if F_130 ( V_232 )
unsigned V_233 ;
struct V_234 * V_192 = V_6 -> V_44 -> V_235 ;
struct V_236 * V_237 , * V_238 = V_192 -> V_239 ;
V_237 = F_131 ( L_17 , V_240 | V_241 , V_238 ,
V_6 , & V_242 ) ;
if ( F_25 ( V_237 ) )
return F_26 ( V_237 ) ;
V_6 -> V_5 . V_243 = V_237 ;
V_237 = F_131 ( L_18 , V_240 | V_241 , V_238 ,
V_6 , & V_244 ) ;
if ( F_25 ( V_237 ) )
return F_26 ( V_237 ) ;
V_6 -> V_5 . V_117 = V_237 ;
V_233 = F_132 ( V_245 ) ;
#ifdef F_75
if ( ! F_76 () )
-- V_233 ;
#endif
return F_133 ( V_6 , V_245 , V_233 ) ;
#else
return 0 ;
#endif
}
static void F_101 ( struct V_1 * V_6 )
{
#if F_130 ( V_232 )
F_134 ( V_6 -> V_5 . V_243 ) ;
V_6 -> V_5 . V_243 = NULL ;
F_134 ( V_6 -> V_5 . V_117 ) ;
V_6 -> V_5 . V_117 = NULL ;
#endif
}
