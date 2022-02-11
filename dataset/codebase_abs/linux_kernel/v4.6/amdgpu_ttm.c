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
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
V_6 -> V_5 . V_16 = false ;
V_10 = & V_6 -> V_5 . V_17 ;
V_10 -> V_18 = V_19 ;
V_10 -> V_20 = sizeof( struct V_21 ) ;
V_10 -> V_22 = & F_3 ;
V_10 -> V_23 = & F_5 ;
V_15 = F_8 ( V_10 ) ;
if ( V_15 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_15 ;
}
V_6 -> V_5 . V_24 . V_25 =
V_6 -> V_5 . V_17 . V_9 ;
V_10 = & V_6 -> V_5 . V_24 . V_8 ;
V_10 -> V_18 = V_26 ;
V_10 -> V_20 = sizeof( struct V_27 ) ;
V_10 -> V_22 = & V_28 ;
V_10 -> V_23 = & V_29 ;
V_15 = F_8 ( V_10 ) ;
if ( V_15 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_17 ) ;
return V_15 ;
}
V_12 = V_6 -> V_5 . V_30 ;
V_14 = & V_12 -> V_31 . V_32 [ V_33 ] ;
V_15 = F_11 ( & V_12 -> V_31 , & V_6 -> V_5 . V_34 ,
V_14 , V_35 ) ;
if ( V_15 != 0 ) {
F_9 ( L_4 ) ;
F_10 ( & V_6 -> V_5 . V_17 ) ;
F_10 ( & V_6 -> V_5 . V_24 . V_8 ) ;
return V_15 ;
}
V_6 -> V_5 . V_16 = true ;
return 0 ;
}
static void F_12 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_16 ) {
F_13 ( V_6 -> V_5 . V_34 . V_31 ,
& V_6 -> V_5 . V_34 ) ;
F_10 ( & V_6 -> V_5 . V_24 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_17 ) ;
V_6 -> V_5 . V_16 = false ;
}
}
static int F_14 ( struct V_2 * V_3 , T_1 V_36 )
{
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_1 type ,
struct V_37 * V_38 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_39 :
V_38 -> V_36 = V_40 ;
V_38 -> V_41 = V_42 ;
V_38 -> V_43 = V_44 ;
break;
case V_45 :
V_38 -> V_46 = & V_47 ;
V_38 -> V_48 = V_6 -> V_49 . V_50 ;
V_38 -> V_41 = V_42 ;
V_38 -> V_43 = V_44 ;
V_38 -> V_36 = V_40 | V_51 ;
break;
case V_52 :
V_38 -> V_46 = & V_47 ;
V_38 -> V_48 = V_6 -> V_49 . V_53 ;
V_38 -> V_36 = V_54 |
V_40 ;
V_38 -> V_41 = V_55 | V_56 ;
V_38 -> V_43 = V_56 ;
break;
case V_57 :
case V_58 :
case V_59 :
V_38 -> V_46 = & V_47 ;
V_38 -> V_48 = 0 ;
V_38 -> V_36 = V_54 | V_51 ;
V_38 -> V_41 = V_55 ;
V_38 -> V_43 = V_55 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_60 ;
}
return 0 ;
}
static void F_16 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 ;
static struct V_67 V_68 = {
. V_69 = 0 ,
. V_70 = 0 ,
. V_36 = V_42 | V_71
} ;
if ( ! F_17 ( V_62 ) ) {
V_64 -> V_64 = & V_68 ;
V_64 -> V_72 = & V_68 ;
V_64 -> V_73 = 1 ;
V_64 -> V_74 = 1 ;
return;
}
V_66 = F_2 ( V_62 , struct V_65 , V_75 ) ;
switch ( V_62 -> V_76 . V_77 ) {
case V_52 :
if ( V_66 -> V_6 -> V_5 . V_30 -> V_78 == false )
F_18 ( V_66 , V_79 ) ;
else
F_18 ( V_66 , V_80 ) ;
break;
case V_45 :
default:
F_18 ( V_66 , V_79 ) ;
}
* V_64 = V_66 -> V_64 ;
}
static int F_19 ( struct V_61 * V_62 , struct V_81 * V_82 )
{
struct V_65 * V_66 = F_2 ( V_62 , struct V_65 , V_75 ) ;
if ( F_20 ( V_62 -> V_83 ) )
return - V_84 ;
return F_21 ( & V_66 -> V_85 . V_86 , V_82 ) ;
}
static void F_22 ( struct V_61 * V_62 ,
struct V_87 * V_88 )
{
struct V_87 * V_89 = & V_62 -> V_76 ;
F_23 ( V_89 -> V_90 != NULL ) ;
* V_89 = * V_88 ;
V_88 -> V_90 = NULL ;
}
static int F_24 ( struct V_61 * V_62 ,
bool V_91 , bool V_92 ,
struct V_87 * V_88 ,
struct V_87 * V_89 )
{
struct V_1 * V_6 ;
struct V_11 * V_12 ;
T_2 V_93 , V_94 ;
struct V_95 * V_95 ;
int V_15 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
V_12 = V_6 -> V_5 . V_30 ;
V_93 = V_89 -> V_96 << V_97 ;
V_94 = V_88 -> V_96 << V_97 ;
switch ( V_89 -> V_77 ) {
case V_52 :
V_93 += V_6 -> V_49 . V_53 ;
break;
case V_45 :
V_93 += V_6 -> V_49 . V_50 ;
break;
default:
F_9 ( L_6 , V_89 -> V_77 ) ;
return - V_60 ;
}
switch ( V_88 -> V_77 ) {
case V_52 :
V_94 += V_6 -> V_49 . V_53 ;
break;
case V_45 :
V_94 += V_6 -> V_49 . V_50 ;
break;
default:
F_9 ( L_6 , V_89 -> V_77 ) ;
return - V_60 ;
}
if ( ! V_12 -> V_78 ) {
F_9 ( L_7 ) ;
return - V_60 ;
}
F_25 ( ( V_98 % V_99 ) != 0 ) ;
V_15 = F_26 ( V_12 , V_93 , V_94 ,
V_88 -> V_100 * V_98 ,
V_62 -> V_101 , & V_95 ) ;
V_15 = F_27 ( V_62 , V_95 ,
V_91 , V_92 , V_88 ) ;
F_28 ( V_95 ) ;
return V_15 ;
}
static int F_29 ( struct V_61 * V_62 ,
bool V_91 , bool V_102 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_87 * V_89 = & V_62 -> V_76 ;
struct V_87 V_103 ;
struct V_67 V_68 ;
struct V_63 V_64 ;
int V_15 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
V_103 = * V_88 ;
V_103 . V_90 = NULL ;
V_64 . V_73 = 1 ;
V_64 . V_64 = & V_68 ;
V_64 . V_74 = 1 ;
V_64 . V_72 = & V_68 ;
V_68 . V_69 = 0 ;
V_68 . V_70 = 0 ;
V_68 . V_36 = V_42 | V_104 ;
V_15 = F_30 ( V_62 , & V_64 , & V_103 ,
V_102 , V_92 ) ;
if ( F_31 ( V_15 ) ) {
return V_15 ;
}
V_15 = F_32 ( V_62 -> V_83 , V_103 . V_64 ) ;
if ( F_31 ( V_15 ) ) {
goto V_105;
}
V_15 = F_33 ( V_62 -> V_83 , & V_103 ) ;
if ( F_31 ( V_15 ) ) {
goto V_105;
}
V_15 = F_24 ( V_62 , true , V_92 , & V_103 , V_89 ) ;
if ( F_31 ( V_15 ) ) {
goto V_105;
}
V_15 = F_34 ( V_62 , true , V_92 , V_88 ) ;
V_105:
F_35 ( V_62 , & V_103 ) ;
return V_15 ;
}
static int F_36 ( struct V_61 * V_62 ,
bool V_91 , bool V_102 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_87 * V_89 = & V_62 -> V_76 ;
struct V_87 V_103 ;
struct V_63 V_64 ;
struct V_67 V_68 ;
int V_15 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
V_103 = * V_88 ;
V_103 . V_90 = NULL ;
V_64 . V_73 = 1 ;
V_64 . V_64 = & V_68 ;
V_64 . V_74 = 1 ;
V_64 . V_72 = & V_68 ;
V_68 . V_69 = 0 ;
V_68 . V_70 = 0 ;
V_68 . V_36 = V_42 | V_104 ;
V_15 = F_30 ( V_62 , & V_64 , & V_103 ,
V_102 , V_92 ) ;
if ( F_31 ( V_15 ) ) {
return V_15 ;
}
V_15 = F_34 ( V_62 , true , V_92 , & V_103 ) ;
if ( F_31 ( V_15 ) ) {
goto V_105;
}
V_15 = F_24 ( V_62 , true , V_92 , V_88 , V_89 ) ;
if ( F_31 ( V_15 ) ) {
goto V_105;
}
V_105:
F_35 ( V_62 , & V_103 ) ;
return V_15 ;
}
static int F_37 ( struct V_61 * V_62 ,
bool V_91 , bool V_102 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_65 * V_106 ;
struct V_87 * V_89 = & V_62 -> V_76 ;
int V_15 ;
V_106 = F_2 ( V_62 , struct V_65 , V_75 ) ;
if ( F_38 ( V_106 -> V_107 > 0 ) )
return - V_60 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
if ( V_89 -> V_77 == V_39 && V_62 -> V_83 == NULL ) {
F_22 ( V_62 , V_88 ) ;
return 0 ;
}
if ( ( V_89 -> V_77 == V_45 &&
V_88 -> V_77 == V_39 ) ||
( V_89 -> V_77 == V_39 &&
V_88 -> V_77 == V_45 ) ) {
F_22 ( V_62 , V_88 ) ;
return 0 ;
}
if ( V_6 -> V_5 . V_108 == NULL ||
V_6 -> V_5 . V_30 == NULL ||
! V_6 -> V_5 . V_30 -> V_78 ) {
goto memcpy;
}
if ( V_89 -> V_77 == V_52 &&
V_88 -> V_77 == V_39 ) {
V_15 = F_29 ( V_62 , V_91 , V_102 ,
V_92 , V_88 ) ;
} else if ( V_89 -> V_77 == V_39 &&
V_88 -> V_77 == V_52 ) {
V_15 = F_36 ( V_62 , V_91 , V_102 ,
V_92 , V_88 ) ;
} else {
V_15 = F_24 ( V_62 , V_91 , V_92 , V_88 , V_89 ) ;
}
if ( V_15 ) {
memcpy:
V_15 = F_39 ( V_62 , V_91 , V_92 , V_88 ) ;
if ( V_15 ) {
return V_15 ;
}
}
F_40 ( ( V_109 ) V_62 -> V_100 << V_97 , & V_6 -> V_110 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_87 * V_76 )
{
struct V_37 * V_38 = & V_3 -> V_38 [ V_76 -> V_77 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_76 -> V_111 . V_112 = NULL ;
V_76 -> V_111 . V_113 = 0 ;
V_76 -> V_111 . V_20 = V_76 -> V_100 << V_97 ;
V_76 -> V_111 . V_114 = 0 ;
V_76 -> V_111 . V_115 = false ;
if ( ! ( V_38 -> V_36 & V_40 ) )
return - V_60 ;
switch ( V_76 -> V_77 ) {
case V_39 :
return 0 ;
case V_45 :
break;
case V_52 :
V_76 -> V_111 . V_113 = V_76 -> V_96 << V_97 ;
if ( ( V_76 -> V_111 . V_113 + V_76 -> V_111 . V_20 ) > V_6 -> V_49 . V_116 )
return - V_60 ;
V_76 -> V_111 . V_114 = V_6 -> V_49 . V_117 ;
V_76 -> V_111 . V_115 = true ;
#ifdef F_42
if ( V_76 -> V_64 & V_56 )
V_76 -> V_111 . V_112 =
F_43 ( V_76 -> V_111 . V_114 + V_76 -> V_111 . V_113 ,
V_76 -> V_111 . V_20 ) ;
else
V_76 -> V_111 . V_112 =
F_44 ( V_76 -> V_111 . V_114 + V_76 -> V_111 . V_113 ,
V_76 -> V_111 . V_20 ) ;
V_76 -> V_111 . V_114 = ( V_76 -> V_111 . V_114 & 0x0ffffffffUL ) +
V_6 -> V_118 -> V_119 -> V_120 ;
#endif
break;
default:
return - V_60 ;
}
return 0 ;
}
static void F_45 ( struct V_2 * V_3 , struct V_87 * V_76 )
{
}
int F_46 ( struct V_121 * V_83 , struct V_122 * * V_123 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
int V_126 = ! ( V_125 -> V_127 & V_128 ) ;
unsigned V_129 = 0 ;
int V_15 ;
if ( V_125 -> V_127 & V_130 ) {
unsigned long V_131 = V_125 -> V_132 + V_83 -> V_100 * V_98 ;
struct V_133 * V_134 ;
V_134 = F_47 ( V_125 -> V_135 , V_125 -> V_132 ) ;
if ( ! V_134 || V_134 -> V_136 || V_134 -> V_137 < V_131 )
return - V_84 ;
}
do {
unsigned V_100 = V_83 -> V_100 - V_129 ;
T_2 V_132 = V_125 -> V_132 + V_129 * V_98 ;
struct V_122 * * V_138 = V_123 + V_129 ;
struct V_139 V_140 ;
V_140 . V_141 = V_142 ;
F_48 ( & V_125 -> V_143 ) ;
F_49 ( & V_140 . V_144 , & V_125 -> V_145 ) ;
F_50 ( & V_125 -> V_143 ) ;
V_15 = F_51 ( V_132 , V_100 , V_126 , 0 , V_138 , NULL ) ;
F_48 ( & V_125 -> V_143 ) ;
F_52 ( & V_140 . V_144 ) ;
F_50 ( & V_125 -> V_143 ) ;
if ( V_15 < 0 )
goto V_146;
V_129 += V_15 ;
} while ( V_129 < V_83 -> V_100 );
return 0 ;
V_146:
V_146 ( V_123 , V_129 , 0 ) ;
return V_15 ;
}
static int F_53 ( struct V_121 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_124 * V_125 = ( void * ) V_83 ;
unsigned V_147 ;
int V_15 ;
int V_126 = ! ( V_125 -> V_127 & V_128 ) ;
enum V_148 V_149 = V_126 ?
V_150 : V_151 ;
V_15 = F_54 ( V_83 -> V_152 , V_83 -> V_123 , V_83 -> V_100 , 0 ,
V_83 -> V_100 << V_97 ,
V_153 ) ;
if ( V_15 )
goto V_154;
V_15 = - V_155 ;
V_147 = F_55 ( V_6 -> V_156 , V_83 -> V_152 -> V_157 , V_83 -> V_152 -> V_147 , V_149 ) ;
if ( V_147 != V_83 -> V_152 -> V_147 )
goto V_154;
F_56 ( V_83 -> V_152 , V_83 -> V_123 ,
V_125 -> V_83 . V_158 , V_83 -> V_100 ) ;
return 0 ;
V_154:
F_57 ( V_83 -> V_152 ) ;
return V_15 ;
}
static void F_58 ( struct V_121 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_124 * V_125 = ( void * ) V_83 ;
struct V_159 V_160 ;
int V_126 = ! ( V_125 -> V_127 & V_128 ) ;
enum V_148 V_149 = V_126 ?
V_150 : V_151 ;
if ( ! V_83 -> V_152 -> V_157 )
return;
F_59 ( V_6 -> V_156 , V_83 -> V_152 -> V_157 , V_83 -> V_152 -> V_147 , V_149 ) ;
F_60 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_122 * V_122 = F_61 ( & V_160 ) ;
if ( ! ( V_125 -> V_127 & V_128 ) )
F_62 ( V_122 ) ;
F_63 ( V_122 ) ;
F_64 ( V_122 ) ;
}
F_65 ( V_83 -> V_152 ) ;
}
static int F_66 ( struct V_121 * V_83 ,
struct V_87 * V_161 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
T_1 V_36 = F_67 ( V_125 -> V_6 , V_83 , V_161 ) ;
int V_15 ;
if ( V_125 -> V_132 ) {
V_15 = F_53 ( V_83 ) ;
if ( V_15 ) {
F_9 ( L_8 ) ;
return V_15 ;
}
}
V_125 -> V_113 = ( unsigned long ) ( V_161 -> V_96 << V_97 ) ;
if ( ! V_83 -> V_100 ) {
F_68 ( 1 , L_9 ,
V_83 -> V_100 , V_161 , V_83 ) ;
}
if ( V_161 -> V_77 == V_57 ||
V_161 -> V_77 == V_58 ||
V_161 -> V_77 == V_59 )
return - V_60 ;
V_15 = F_69 ( V_125 -> V_6 , V_125 -> V_113 , V_83 -> V_100 ,
V_83 -> V_123 , V_125 -> V_83 . V_158 , V_36 ) ;
if ( V_15 ) {
F_9 ( L_10 ,
V_83 -> V_100 , ( unsigned ) V_125 -> V_113 ) ;
return V_15 ;
}
return 0 ;
}
static int F_70 ( struct V_121 * V_83 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
if ( V_125 -> V_6 -> V_162 . V_78 )
F_71 ( V_125 -> V_6 , V_125 -> V_113 , V_83 -> V_100 ) ;
if ( V_125 -> V_132 )
F_58 ( V_83 ) ;
return 0 ;
}
static void F_72 ( struct V_121 * V_83 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
F_73 ( & V_125 -> V_83 ) ;
F_57 ( V_125 ) ;
}
static struct V_121 * F_74 ( struct V_2 * V_3 ,
unsigned long V_20 , T_1 V_163 ,
struct V_122 * V_164 )
{
struct V_1 * V_6 ;
struct V_124 * V_125 ;
V_6 = F_1 ( V_3 ) ;
V_125 = F_75 ( sizeof( struct V_124 ) , V_153 ) ;
if ( V_125 == NULL ) {
return NULL ;
}
V_125 -> V_83 . V_83 . V_46 = & V_165 ;
V_125 -> V_6 = V_6 ;
if ( F_76 ( & V_125 -> V_83 , V_3 , V_20 , V_163 , V_164 ) ) {
F_57 ( V_125 ) ;
return NULL ;
}
return & V_125 -> V_83 . V_83 ;
}
static int F_77 ( struct V_121 * V_83 )
{
struct V_1 * V_6 ;
struct V_124 * V_125 = ( void * ) V_83 ;
unsigned V_166 ;
int V_15 ;
bool V_167 = ! ! ( V_83 -> V_163 & V_168 ) ;
if ( V_83 -> V_169 != V_170 )
return 0 ;
if ( V_125 && V_125 -> V_132 ) {
V_83 -> V_152 = F_75 ( sizeof( struct V_171 ) , V_153 ) ;
if ( ! V_83 -> V_152 )
return - V_155 ;
V_83 -> V_163 |= V_168 ;
V_83 -> V_169 = V_172 ;
return 0 ;
}
if ( V_167 && V_83 -> V_152 ) {
F_56 ( V_83 -> V_152 , V_83 -> V_123 ,
V_125 -> V_83 . V_158 , V_83 -> V_100 ) ;
V_83 -> V_169 = V_172 ;
return 0 ;
}
V_6 = F_1 ( V_83 -> V_3 ) ;
#ifdef F_78
if ( F_79 () ) {
return F_80 ( & V_125 -> V_83 , V_6 -> V_156 ) ;
}
#endif
V_15 = F_81 ( V_83 ) ;
if ( V_15 ) {
return V_15 ;
}
for ( V_166 = 0 ; V_166 < V_83 -> V_100 ; V_166 ++ ) {
V_125 -> V_83 . V_158 [ V_166 ] = F_82 ( V_6 -> V_173 , V_83 -> V_123 [ V_166 ] ,
0 , V_98 ,
V_174 ) ;
if ( F_83 ( V_6 -> V_173 , V_125 -> V_83 . V_158 [ V_166 ] ) ) {
while ( V_166 -- ) {
F_84 ( V_6 -> V_173 , V_125 -> V_83 . V_158 [ V_166 ] ,
V_98 , V_174 ) ;
V_125 -> V_83 . V_158 [ V_166 ] = 0 ;
}
F_85 ( V_83 ) ;
return - V_175 ;
}
}
return 0 ;
}
static void F_86 ( struct V_121 * V_83 )
{
struct V_1 * V_6 ;
struct V_124 * V_125 = ( void * ) V_83 ;
unsigned V_166 ;
bool V_167 = ! ! ( V_83 -> V_163 & V_168 ) ;
if ( V_125 && V_125 -> V_132 ) {
F_57 ( V_83 -> V_152 ) ;
V_83 -> V_163 &= ~ V_168 ;
return;
}
if ( V_167 )
return;
V_6 = F_1 ( V_83 -> V_3 ) ;
#ifdef F_78
if ( F_79 () ) {
F_87 ( & V_125 -> V_83 , V_6 -> V_156 ) ;
return;
}
#endif
for ( V_166 = 0 ; V_166 < V_83 -> V_100 ; V_166 ++ ) {
if ( V_125 -> V_83 . V_158 [ V_166 ] ) {
F_84 ( V_6 -> V_173 , V_125 -> V_83 . V_158 [ V_166 ] ,
V_98 , V_174 ) ;
}
}
F_85 ( V_83 ) ;
}
int F_88 ( struct V_121 * V_83 , T_2 V_112 ,
T_1 V_36 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
if ( V_125 == NULL )
return - V_60 ;
V_125 -> V_132 = V_112 ;
V_125 -> V_135 = V_142 -> V_176 ;
V_125 -> V_127 = V_36 ;
F_89 ( & V_125 -> V_143 ) ;
F_90 ( & V_125 -> V_145 ) ;
F_91 ( & V_125 -> V_177 , 0 ) ;
return 0 ;
}
struct V_178 * F_20 ( struct V_121 * V_83 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
if ( V_125 == NULL )
return NULL ;
return V_125 -> V_135 ;
}
bool F_92 ( struct V_121 * V_83 , unsigned long V_96 ,
unsigned long V_131 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
struct V_139 * V_179 ;
unsigned long V_20 ;
if ( V_125 == NULL || ! V_125 -> V_132 )
return false ;
V_20 = ( unsigned long ) V_125 -> V_83 . V_83 . V_100 * V_98 ;
if ( V_125 -> V_132 > V_131 || V_125 -> V_132 + V_20 <= V_96 )
return false ;
F_48 ( & V_125 -> V_143 ) ;
F_93 (entry, &gtt->guptasks, list) {
if ( V_179 -> V_141 == V_142 ) {
F_50 ( & V_125 -> V_143 ) ;
return false ;
}
}
F_50 ( & V_125 -> V_143 ) ;
F_94 ( & V_125 -> V_177 ) ;
return true ;
}
bool F_95 ( struct V_121 * V_83 ,
int * V_180 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
int V_181 = * V_180 ;
* V_180 = F_96 ( & V_125 -> V_177 ) ;
return V_181 != * V_180 ;
}
bool F_97 ( struct V_121 * V_83 )
{
struct V_124 * V_125 = ( void * ) V_83 ;
if ( V_125 == NULL )
return false ;
return ! ! ( V_125 -> V_127 & V_128 ) ;
}
T_1 F_67 ( struct V_1 * V_6 , struct V_121 * V_83 ,
struct V_87 * V_76 )
{
T_1 V_36 = 0 ;
if ( V_76 && V_76 -> V_77 != V_39 )
V_36 |= V_182 ;
if ( V_76 && V_76 -> V_77 == V_45 ) {
V_36 |= V_183 ;
if ( V_83 -> V_184 == V_185 )
V_36 |= V_186 ;
}
if ( V_6 -> V_187 >= V_188 )
V_36 |= V_189 ;
V_36 |= V_190 ;
if ( ! F_97 ( V_83 ) )
V_36 |= V_191 ;
return V_36 ;
}
int F_98 ( struct V_1 * V_6 )
{
int V_15 ;
V_15 = F_7 ( V_6 ) ;
if ( V_15 ) {
return V_15 ;
}
V_15 = F_99 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_24 . V_8 . V_9 ,
& V_192 ,
V_6 -> V_118 -> V_193 -> V_194 ,
V_195 ,
V_6 -> V_196 ) ;
if ( V_15 ) {
F_9 ( L_11 , V_15 ) ;
return V_15 ;
}
V_6 -> V_5 . V_197 = true ;
V_15 = F_100 ( & V_6 -> V_5 . V_3 , V_52 ,
V_6 -> V_49 . V_198 >> V_97 ) ;
if ( V_15 ) {
F_9 ( L_12 ) ;
return V_15 ;
}
F_101 ( V_6 , V_6 -> V_49 . V_116 ) ;
V_15 = F_102 ( V_6 , 256 * 1024 , V_98 , true ,
V_199 ,
V_200 ,
NULL , NULL , & V_6 -> V_201 ) ;
if ( V_15 ) {
return V_15 ;
}
V_15 = F_103 ( V_6 -> V_201 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_104 ( V_6 -> V_201 , V_199 , NULL ) ;
F_105 ( V_6 -> V_201 ) ;
if ( V_15 ) {
F_106 ( & V_6 -> V_201 ) ;
return V_15 ;
}
F_107 ( L_13 ,
( unsigned ) ( V_6 -> V_49 . V_198 / ( 1024 * 1024 ) ) ) ;
V_15 = F_100 ( & V_6 -> V_5 . V_3 , V_45 ,
V_6 -> V_49 . V_202 >> V_97 ) ;
if ( V_15 ) {
F_9 ( L_14 ) ;
return V_15 ;
}
F_107 ( L_15 ,
( unsigned ) ( V_6 -> V_49 . V_202 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_203 . V_76 . V_204 = V_6 -> V_203 . V_76 . V_204 << V_205 ;
V_6 -> V_203 . V_76 . V_206 = V_6 -> V_203 . V_76 . V_206 << V_205 ;
V_6 -> V_203 . V_76 . V_207 = V_6 -> V_203 . V_76 . V_207 << V_205 ;
V_6 -> V_203 . V_208 . V_204 = V_6 -> V_203 . V_208 . V_204 << V_209 ;
V_6 -> V_203 . V_208 . V_206 = V_6 -> V_203 . V_208 . V_206 << V_209 ;
V_6 -> V_203 . V_208 . V_207 = V_6 -> V_203 . V_208 . V_207 << V_209 ;
V_6 -> V_203 . V_210 . V_204 = V_6 -> V_203 . V_210 . V_204 << V_211 ;
V_6 -> V_203 . V_210 . V_206 = V_6 -> V_203 . V_210 . V_206 << V_211 ;
V_6 -> V_203 . V_210 . V_207 = V_6 -> V_203 . V_210 . V_207 << V_211 ;
V_15 = F_100 ( & V_6 -> V_5 . V_3 , V_57 ,
V_6 -> V_203 . V_76 . V_204 >> V_97 ) ;
if ( V_15 ) {
F_9 ( L_16 ) ;
return V_15 ;
}
V_15 = F_100 ( & V_6 -> V_5 . V_3 , V_58 ,
V_6 -> V_203 . V_208 . V_204 >> V_97 ) ;
if ( V_15 ) {
F_9 ( L_17 ) ;
return V_15 ;
}
V_15 = F_100 ( & V_6 -> V_5 . V_3 , V_59 ,
V_6 -> V_203 . V_210 . V_204 >> V_97 ) ;
if ( V_15 ) {
F_9 ( L_18 ) ;
return V_15 ;
}
V_15 = F_108 ( V_6 ) ;
if ( V_15 ) {
F_9 ( L_19 ) ;
return V_15 ;
}
return 0 ;
}
void F_109 ( struct V_1 * V_6 )
{
int V_15 ;
if ( ! V_6 -> V_5 . V_197 )
return;
F_110 ( V_6 ) ;
if ( V_6 -> V_201 ) {
V_15 = F_103 ( V_6 -> V_201 , false ) ;
if ( V_15 == 0 ) {
F_111 ( V_6 -> V_201 ) ;
F_105 ( V_6 -> V_201 ) ;
}
F_106 ( & V_6 -> V_201 ) ;
}
F_112 ( & V_6 -> V_5 . V_3 , V_52 ) ;
F_112 ( & V_6 -> V_5 . V_3 , V_45 ) ;
F_112 ( & V_6 -> V_5 . V_3 , V_57 ) ;
F_112 ( & V_6 -> V_5 . V_3 , V_58 ) ;
F_112 ( & V_6 -> V_5 . V_3 , V_59 ) ;
F_113 ( & V_6 -> V_5 . V_3 ) ;
F_114 ( V_6 ) ;
F_12 ( V_6 ) ;
V_6 -> V_5 . V_197 = false ;
F_107 ( L_20 ) ;
}
void F_101 ( struct V_1 * V_6 , V_109 V_20 )
{
struct V_37 * V_38 ;
if ( ! V_6 -> V_5 . V_197 )
return;
V_38 = & V_6 -> V_5 . V_3 . V_38 [ V_52 ] ;
V_38 -> V_20 = V_20 >> V_97 ;
}
int F_115 ( struct V_81 * V_82 , struct V_133 * V_134 )
{
struct V_212 * V_213 ;
struct V_1 * V_6 ;
if ( F_31 ( V_134 -> V_214 < V_195 ) )
return - V_60 ;
V_213 = V_82 -> V_215 ;
V_6 = V_213 -> V_216 -> V_156 -> V_217 ;
if ( V_6 == NULL )
return - V_60 ;
return F_116 ( V_82 , V_134 , & V_6 -> V_5 . V_3 ) ;
}
int F_26 ( struct V_11 * V_12 ,
T_2 V_218 ,
T_2 V_219 ,
T_1 V_220 ,
struct V_221 * V_101 ,
struct V_95 * * V_95 )
{
struct V_1 * V_6 = V_12 -> V_6 ;
struct V_222 * V_223 ;
T_1 V_224 ;
unsigned V_225 , V_226 ;
unsigned V_166 ;
int V_15 ;
V_224 = V_6 -> V_5 . V_108 -> V_227 ;
V_225 = F_117 ( V_220 , V_224 ) ;
V_226 = V_225 * V_6 -> V_5 . V_108 -> V_228 ;
while ( V_226 & 0x7 )
V_226 ++ ;
V_15 = F_118 ( V_6 , V_226 * 4 , & V_223 ) ;
if ( V_15 )
return V_15 ;
if ( V_101 ) {
V_15 = F_119 ( V_6 , & V_223 -> V_229 , V_101 ,
V_230 ) ;
if ( V_15 ) {
F_9 ( L_21 , V_15 ) ;
goto V_231;
}
}
for ( V_166 = 0 ; V_166 < V_225 ; V_166 ++ ) {
T_1 V_232 = F_120 ( V_220 , V_224 ) ;
F_121 ( V_6 , & V_223 -> V_233 [ 0 ] , V_218 ,
V_219 , V_232 ) ;
V_218 += V_232 ;
V_219 += V_232 ;
V_220 -= V_232 ;
}
F_122 ( V_12 , & V_223 -> V_233 [ 0 ] ) ;
F_123 ( V_223 -> V_233 [ 0 ] . V_234 > V_226 ) ;
V_15 = F_124 ( V_223 , V_12 , & V_6 -> V_5 . V_34 ,
V_230 , V_95 ) ;
if ( V_15 )
goto V_231;
return 0 ;
V_231:
F_125 ( V_223 ) ;
return V_15 ;
}
static int F_126 ( struct V_235 * V_236 , void * V_237 )
{
struct V_238 * V_239 = (struct V_238 * ) V_236 -> V_240 ;
unsigned V_241 = * ( int * ) V_239 -> V_242 -> V_237 ;
struct V_243 * V_156 = V_239 -> V_216 -> V_156 ;
struct V_1 * V_6 = V_156 -> V_217 ;
struct V_244 * V_176 = (struct V_244 * ) V_6 -> V_5 . V_3 . V_38 [ V_241 ] . V_245 ;
int V_246 ;
struct V_27 * V_247 = V_6 -> V_5 . V_3 . V_247 ;
F_48 ( & V_247 -> V_248 ) ;
V_246 = F_127 ( V_236 , V_176 ) ;
F_50 ( & V_247 -> V_248 ) ;
if ( V_241 == V_52 )
F_128 ( V_236 , L_22 ,
V_6 -> V_5 . V_3 . V_38 [ V_241 ] . V_20 ,
( V_109 ) F_129 ( & V_6 -> V_249 ) >> 20 ,
( V_109 ) F_129 ( & V_6 -> V_250 ) >> 20 ) ;
return V_246 ;
}
static T_3 F_130 ( struct V_81 * V_251 , char T_4 * V_252 ,
T_5 V_20 , T_6 * V_253 )
{
struct V_1 * V_6 = V_251 -> V_254 -> V_255 ;
T_3 V_256 = 0 ;
int V_15 ;
if ( V_20 & 0x3 || * V_253 & 0x3 )
return - V_60 ;
while ( V_20 ) {
unsigned long V_36 ;
T_1 V_257 ;
if ( * V_253 >= V_6 -> V_49 . V_258 )
return V_256 ;
F_131 ( & V_6 -> V_259 , V_36 ) ;
F_132 ( V_260 , ( ( T_1 ) * V_253 ) | 0x80000000 ) ;
F_132 ( V_261 , * V_253 >> 31 ) ;
V_257 = F_133 ( V_262 ) ;
F_134 ( & V_6 -> V_259 , V_36 ) ;
V_15 = F_135 ( V_257 , ( T_1 * ) V_252 ) ;
if ( V_15 )
return V_15 ;
V_256 += 4 ;
V_252 += 4 ;
* V_253 += 4 ;
V_20 -= 4 ;
}
return V_256 ;
}
static T_3 F_136 ( struct V_81 * V_251 , char T_4 * V_252 ,
T_5 V_20 , T_6 * V_253 )
{
struct V_1 * V_6 = V_251 -> V_254 -> V_255 ;
T_3 V_256 = 0 ;
int V_15 ;
while ( V_20 ) {
T_6 V_138 = * V_253 / V_98 ;
unsigned V_263 = * V_253 & ~ V_264 ;
T_5 V_265 = F_137 ( T_5 , V_20 , V_98 - V_263 ) ;
struct V_122 * V_122 ;
void * V_266 ;
if ( V_138 >= V_6 -> V_162 . V_267 )
return V_256 ;
V_122 = V_6 -> V_162 . V_123 [ V_138 ] ;
if ( V_122 ) {
V_266 = F_138 ( V_122 ) ;
V_266 += V_263 ;
V_15 = F_139 ( V_252 , V_266 , V_265 ) ;
F_140 ( V_6 -> V_162 . V_123 [ V_138 ] ) ;
} else
V_15 = F_141 ( V_252 , V_265 ) ;
if ( V_15 )
return - V_175 ;
V_256 += V_265 ;
V_252 += V_265 ;
* V_253 += V_265 ;
V_20 -= V_265 ;
}
return V_256 ;
}
static int F_108 ( struct V_1 * V_6 )
{
#if F_142 ( V_268 )
unsigned V_269 ;
struct V_270 * V_216 = V_6 -> V_118 -> V_271 ;
struct V_272 * V_273 , * V_274 = V_216 -> V_275 ;
V_273 = F_143 ( L_23 , V_276 | V_277 , V_274 ,
V_6 , & V_278 ) ;
if ( F_144 ( V_273 ) )
return F_145 ( V_273 ) ;
F_146 ( V_273 -> V_279 , V_6 -> V_49 . V_258 ) ;
V_6 -> V_5 . V_280 = V_273 ;
V_273 = F_143 ( L_24 , V_276 | V_277 , V_274 ,
V_6 , & V_281 ) ;
if ( F_144 ( V_273 ) )
return F_145 ( V_273 ) ;
F_146 ( V_273 -> V_279 , V_6 -> V_49 . V_202 ) ;
V_6 -> V_5 . V_125 = V_273 ;
V_269 = F_147 ( V_282 ) ;
#ifdef F_78
if ( ! F_79 () )
-- V_269 ;
#endif
return F_148 ( V_6 , V_282 , V_269 ) ;
#else
return 0 ;
#endif
}
static void F_110 ( struct V_1 * V_6 )
{
#if F_142 ( V_268 )
F_149 ( V_6 -> V_5 . V_280 ) ;
V_6 -> V_5 . V_280 = NULL ;
F_149 ( V_6 -> V_5 . V_125 ) ;
V_6 -> V_5 . V_125 = NULL ;
#endif
}
