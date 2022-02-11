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
V_93 = ( V_96 ) V_89 -> V_97 << V_98 ;
V_94 = ( V_96 ) V_88 -> V_97 << V_98 ;
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
F_25 ( ( V_99 % V_100 ) != 0 ) ;
V_15 = F_26 ( V_12 , V_93 , V_94 ,
V_88 -> V_101 * V_99 ,
V_62 -> V_102 , & V_95 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_27 ( V_62 , V_95 , V_91 , V_88 ) ;
F_28 ( V_95 ) ;
return V_15 ;
}
static int F_29 ( struct V_61 * V_62 ,
bool V_91 , bool V_103 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_87 * V_89 = & V_62 -> V_76 ;
struct V_87 V_104 ;
struct V_67 V_68 ;
struct V_63 V_64 ;
int V_15 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
V_104 = * V_88 ;
V_104 . V_90 = NULL ;
V_64 . V_73 = 1 ;
V_64 . V_64 = & V_68 ;
V_64 . V_74 = 1 ;
V_64 . V_72 = & V_68 ;
V_68 . V_69 = 0 ;
V_68 . V_70 = 0 ;
V_68 . V_36 = V_42 | V_105 ;
V_15 = F_30 ( V_62 , & V_64 , & V_104 ,
V_103 , V_92 ) ;
if ( F_31 ( V_15 ) ) {
return V_15 ;
}
V_15 = F_32 ( V_62 -> V_83 , V_104 . V_64 ) ;
if ( F_31 ( V_15 ) ) {
goto V_106;
}
V_15 = F_33 ( V_62 -> V_83 , & V_104 ) ;
if ( F_31 ( V_15 ) ) {
goto V_106;
}
V_15 = F_24 ( V_62 , true , V_92 , & V_104 , V_89 ) ;
if ( F_31 ( V_15 ) ) {
goto V_106;
}
V_15 = F_34 ( V_62 , true , V_103 , V_92 , V_88 ) ;
V_106:
F_35 ( V_62 , & V_104 ) ;
return V_15 ;
}
static int F_36 ( struct V_61 * V_62 ,
bool V_91 , bool V_103 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_87 * V_89 = & V_62 -> V_76 ;
struct V_87 V_104 ;
struct V_63 V_64 ;
struct V_67 V_68 ;
int V_15 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
V_104 = * V_88 ;
V_104 . V_90 = NULL ;
V_64 . V_73 = 1 ;
V_64 . V_64 = & V_68 ;
V_64 . V_74 = 1 ;
V_64 . V_72 = & V_68 ;
V_68 . V_69 = 0 ;
V_68 . V_70 = 0 ;
V_68 . V_36 = V_42 | V_105 ;
V_15 = F_30 ( V_62 , & V_64 , & V_104 ,
V_103 , V_92 ) ;
if ( F_31 ( V_15 ) ) {
return V_15 ;
}
V_15 = F_34 ( V_62 , true , V_103 , V_92 , & V_104 ) ;
if ( F_31 ( V_15 ) ) {
goto V_106;
}
V_15 = F_24 ( V_62 , true , V_92 , V_88 , V_89 ) ;
if ( F_31 ( V_15 ) ) {
goto V_106;
}
V_106:
F_35 ( V_62 , & V_104 ) ;
return V_15 ;
}
static int F_37 ( struct V_61 * V_62 ,
bool V_91 , bool V_103 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_65 * V_107 ;
struct V_87 * V_89 = & V_62 -> V_76 ;
int V_15 ;
V_107 = F_2 ( V_62 , struct V_65 , V_75 ) ;
if ( F_38 ( V_107 -> V_108 > 0 ) )
return - V_60 ;
V_6 = F_1 ( V_62 -> V_3 ) ;
if ( V_91 )
F_39 ( & V_6 -> V_109 ) ;
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
if ( V_6 -> V_5 . V_110 == NULL ||
V_6 -> V_5 . V_30 == NULL ||
! V_6 -> V_5 . V_30 -> V_78 ) {
goto memcpy;
}
if ( V_89 -> V_77 == V_52 &&
V_88 -> V_77 == V_39 ) {
V_15 = F_29 ( V_62 , V_91 , V_103 ,
V_92 , V_88 ) ;
} else if ( V_89 -> V_77 == V_39 &&
V_88 -> V_77 == V_52 ) {
V_15 = F_36 ( V_62 , V_91 , V_103 ,
V_92 , V_88 ) ;
} else {
V_15 = F_24 ( V_62 , V_91 , V_92 , V_88 , V_89 ) ;
}
if ( V_15 ) {
memcpy:
V_15 = F_40 ( V_62 , V_91 , V_103 ,
V_92 , V_88 ) ;
if ( V_15 ) {
return V_15 ;
}
}
F_41 ( ( V_96 ) V_62 -> V_101 << V_98 , & V_6 -> V_111 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_87 * V_76 )
{
struct V_37 * V_38 = & V_3 -> V_38 [ V_76 -> V_77 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_76 -> V_112 . V_113 = NULL ;
V_76 -> V_112 . V_114 = 0 ;
V_76 -> V_112 . V_20 = V_76 -> V_101 << V_98 ;
V_76 -> V_112 . V_115 = 0 ;
V_76 -> V_112 . V_116 = false ;
if ( ! ( V_38 -> V_36 & V_40 ) )
return - V_60 ;
switch ( V_76 -> V_77 ) {
case V_39 :
return 0 ;
case V_45 :
break;
case V_52 :
V_76 -> V_112 . V_114 = V_76 -> V_97 << V_98 ;
if ( ( V_76 -> V_112 . V_114 + V_76 -> V_112 . V_20 ) > V_6 -> V_49 . V_117 )
return - V_60 ;
V_76 -> V_112 . V_115 = V_6 -> V_49 . V_118 ;
V_76 -> V_112 . V_116 = true ;
#ifdef F_43
if ( V_76 -> V_64 & V_56 )
V_76 -> V_112 . V_113 =
F_44 ( V_76 -> V_112 . V_115 + V_76 -> V_112 . V_114 ,
V_76 -> V_112 . V_20 ) ;
else
V_76 -> V_112 . V_113 =
F_45 ( V_76 -> V_112 . V_115 + V_76 -> V_112 . V_114 ,
V_76 -> V_112 . V_20 ) ;
V_76 -> V_112 . V_115 = ( V_76 -> V_112 . V_115 & 0x0ffffffffUL ) +
V_6 -> V_119 -> V_120 -> V_121 ;
#endif
break;
default:
return - V_60 ;
}
return 0 ;
}
static void F_46 ( struct V_2 * V_3 , struct V_87 * V_76 )
{
}
int F_47 ( struct V_122 * V_83 , struct V_123 * * V_124 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
int V_127 = ! ( V_126 -> V_128 & V_129 ) ;
unsigned V_130 = 0 ;
int V_15 ;
if ( V_126 -> V_128 & V_131 ) {
unsigned long V_132 = V_126 -> V_133 + V_83 -> V_101 * V_99 ;
struct V_134 * V_135 ;
V_135 = F_48 ( V_126 -> V_136 , V_126 -> V_133 ) ;
if ( ! V_135 || V_135 -> V_137 || V_135 -> V_138 < V_132 )
return - V_84 ;
}
do {
unsigned V_101 = V_83 -> V_101 - V_130 ;
T_2 V_133 = V_126 -> V_133 + V_130 * V_99 ;
struct V_123 * * V_139 = V_124 + V_130 ;
struct V_140 V_141 ;
V_141 . V_142 = V_143 ;
F_49 ( & V_126 -> V_144 ) ;
F_50 ( & V_141 . V_145 , & V_126 -> V_146 ) ;
F_51 ( & V_126 -> V_144 ) ;
V_15 = F_52 ( V_133 , V_101 , V_127 , 0 , V_139 , NULL ) ;
F_49 ( & V_126 -> V_144 ) ;
F_53 ( & V_141 . V_145 ) ;
F_51 ( & V_126 -> V_144 ) ;
if ( V_15 < 0 )
goto V_147;
V_130 += V_15 ;
} while ( V_130 < V_83 -> V_101 );
return 0 ;
V_147:
V_147 ( V_124 , V_130 , 0 ) ;
return V_15 ;
}
static int F_54 ( struct V_122 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_125 * V_126 = ( void * ) V_83 ;
unsigned V_148 ;
int V_15 ;
int V_127 = ! ( V_126 -> V_128 & V_129 ) ;
enum V_149 V_150 = V_127 ?
V_151 : V_152 ;
V_15 = F_55 ( V_83 -> V_153 , V_83 -> V_124 , V_83 -> V_101 , 0 ,
V_83 -> V_101 << V_98 ,
V_154 ) ;
if ( V_15 )
goto V_155;
V_15 = - V_156 ;
V_148 = F_56 ( V_6 -> V_157 , V_83 -> V_153 -> V_158 , V_83 -> V_153 -> V_148 , V_150 ) ;
if ( V_148 != V_83 -> V_153 -> V_148 )
goto V_155;
F_57 ( V_83 -> V_153 , V_83 -> V_124 ,
V_126 -> V_83 . V_159 , V_83 -> V_101 ) ;
return 0 ;
V_155:
F_58 ( V_83 -> V_153 ) ;
return V_15 ;
}
static void F_59 ( struct V_122 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_125 * V_126 = ( void * ) V_83 ;
struct V_160 V_161 ;
int V_127 = ! ( V_126 -> V_128 & V_129 ) ;
enum V_149 V_150 = V_127 ?
V_151 : V_152 ;
if ( ! V_83 -> V_153 -> V_158 )
return;
F_60 ( V_6 -> V_157 , V_83 -> V_153 -> V_158 , V_83 -> V_153 -> V_148 , V_150 ) ;
F_61 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_123 * V_123 = F_62 ( & V_161 ) ;
if ( ! ( V_126 -> V_128 & V_129 ) )
F_63 ( V_123 ) ;
F_64 ( V_123 ) ;
F_65 ( V_123 ) ;
}
F_66 ( V_83 -> V_153 ) ;
}
static int F_67 ( struct V_122 * V_83 ,
struct V_87 * V_162 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
T_1 V_36 = F_68 ( V_126 -> V_6 , V_83 , V_162 ) ;
int V_15 ;
if ( V_126 -> V_133 ) {
V_15 = F_54 ( V_83 ) ;
if ( V_15 ) {
F_9 ( L_8 ) ;
return V_15 ;
}
}
V_126 -> V_114 = ( unsigned long ) ( V_162 -> V_97 << V_98 ) ;
if ( ! V_83 -> V_101 ) {
F_69 ( 1 , L_9 ,
V_83 -> V_101 , V_162 , V_83 ) ;
}
if ( V_162 -> V_77 == V_57 ||
V_162 -> V_77 == V_58 ||
V_162 -> V_77 == V_59 )
return - V_60 ;
V_15 = F_70 ( V_126 -> V_6 , V_126 -> V_114 , V_83 -> V_101 ,
V_83 -> V_124 , V_126 -> V_83 . V_159 , V_36 ) ;
if ( V_15 ) {
F_9 ( L_10 ,
V_83 -> V_101 , ( unsigned ) V_126 -> V_114 ) ;
return V_15 ;
}
return 0 ;
}
static int F_71 ( struct V_122 * V_83 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
if ( V_126 -> V_6 -> V_163 . V_78 )
F_72 ( V_126 -> V_6 , V_126 -> V_114 , V_83 -> V_101 ) ;
if ( V_126 -> V_133 )
F_59 ( V_83 ) ;
return 0 ;
}
static void F_73 ( struct V_122 * V_83 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
F_74 ( & V_126 -> V_83 ) ;
F_58 ( V_126 ) ;
}
static struct V_122 * F_75 ( struct V_2 * V_3 ,
unsigned long V_20 , T_1 V_164 ,
struct V_123 * V_165 )
{
struct V_1 * V_6 ;
struct V_125 * V_126 ;
V_6 = F_1 ( V_3 ) ;
V_126 = F_76 ( sizeof( struct V_125 ) , V_154 ) ;
if ( V_126 == NULL ) {
return NULL ;
}
V_126 -> V_83 . V_83 . V_46 = & V_166 ;
V_126 -> V_6 = V_6 ;
if ( F_77 ( & V_126 -> V_83 , V_3 , V_20 , V_164 , V_165 ) ) {
F_58 ( V_126 ) ;
return NULL ;
}
return & V_126 -> V_83 . V_83 ;
}
static int F_78 ( struct V_122 * V_83 )
{
struct V_1 * V_6 ;
struct V_125 * V_126 = ( void * ) V_83 ;
unsigned V_167 ;
int V_15 ;
bool V_168 = ! ! ( V_83 -> V_164 & V_169 ) ;
if ( V_83 -> V_170 != V_171 )
return 0 ;
if ( V_126 && V_126 -> V_133 ) {
V_83 -> V_153 = F_76 ( sizeof( struct V_172 ) , V_154 ) ;
if ( ! V_83 -> V_153 )
return - V_156 ;
V_83 -> V_164 |= V_169 ;
V_83 -> V_170 = V_173 ;
return 0 ;
}
if ( V_168 && V_83 -> V_153 ) {
F_57 ( V_83 -> V_153 , V_83 -> V_124 ,
V_126 -> V_83 . V_159 , V_83 -> V_101 ) ;
V_83 -> V_170 = V_173 ;
return 0 ;
}
V_6 = F_1 ( V_83 -> V_3 ) ;
#ifdef F_79
if ( F_80 () ) {
return F_81 ( & V_126 -> V_83 , V_6 -> V_157 ) ;
}
#endif
V_15 = F_82 ( V_83 ) ;
if ( V_15 ) {
return V_15 ;
}
for ( V_167 = 0 ; V_167 < V_83 -> V_101 ; V_167 ++ ) {
V_126 -> V_83 . V_159 [ V_167 ] = F_83 ( V_6 -> V_174 , V_83 -> V_124 [ V_167 ] ,
0 , V_99 ,
V_175 ) ;
if ( F_84 ( V_6 -> V_174 , V_126 -> V_83 . V_159 [ V_167 ] ) ) {
while ( V_167 -- ) {
F_85 ( V_6 -> V_174 , V_126 -> V_83 . V_159 [ V_167 ] ,
V_99 , V_175 ) ;
V_126 -> V_83 . V_159 [ V_167 ] = 0 ;
}
F_86 ( V_83 ) ;
return - V_176 ;
}
}
return 0 ;
}
static void F_87 ( struct V_122 * V_83 )
{
struct V_1 * V_6 ;
struct V_125 * V_126 = ( void * ) V_83 ;
unsigned V_167 ;
bool V_168 = ! ! ( V_83 -> V_164 & V_169 ) ;
if ( V_126 && V_126 -> V_133 ) {
F_58 ( V_83 -> V_153 ) ;
V_83 -> V_164 &= ~ V_169 ;
return;
}
if ( V_168 )
return;
V_6 = F_1 ( V_83 -> V_3 ) ;
#ifdef F_79
if ( F_80 () ) {
F_88 ( & V_126 -> V_83 , V_6 -> V_157 ) ;
return;
}
#endif
for ( V_167 = 0 ; V_167 < V_83 -> V_101 ; V_167 ++ ) {
if ( V_126 -> V_83 . V_159 [ V_167 ] ) {
F_85 ( V_6 -> V_174 , V_126 -> V_83 . V_159 [ V_167 ] ,
V_99 , V_175 ) ;
}
}
F_86 ( V_83 ) ;
}
int F_89 ( struct V_122 * V_83 , T_2 V_113 ,
T_1 V_36 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
if ( V_126 == NULL )
return - V_60 ;
V_126 -> V_133 = V_113 ;
V_126 -> V_136 = V_143 -> V_177 ;
V_126 -> V_128 = V_36 ;
F_90 ( & V_126 -> V_144 ) ;
F_91 ( & V_126 -> V_146 ) ;
F_92 ( & V_126 -> V_178 , 0 ) ;
return 0 ;
}
struct V_179 * F_20 ( struct V_122 * V_83 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
if ( V_126 == NULL )
return NULL ;
return V_126 -> V_136 ;
}
bool F_93 ( struct V_122 * V_83 , unsigned long V_97 ,
unsigned long V_132 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
struct V_140 * V_180 ;
unsigned long V_20 ;
if ( V_126 == NULL || ! V_126 -> V_133 )
return false ;
V_20 = ( unsigned long ) V_126 -> V_83 . V_83 . V_101 * V_99 ;
if ( V_126 -> V_133 > V_132 || V_126 -> V_133 + V_20 <= V_97 )
return false ;
F_49 ( & V_126 -> V_144 ) ;
F_94 (entry, &gtt->guptasks, list) {
if ( V_180 -> V_142 == V_143 ) {
F_51 ( & V_126 -> V_144 ) ;
return false ;
}
}
F_51 ( & V_126 -> V_144 ) ;
F_95 ( & V_126 -> V_178 ) ;
return true ;
}
bool F_96 ( struct V_122 * V_83 ,
int * V_181 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
int V_182 = * V_181 ;
* V_181 = F_97 ( & V_126 -> V_178 ) ;
return V_182 != * V_181 ;
}
bool F_98 ( struct V_122 * V_83 )
{
struct V_125 * V_126 = ( void * ) V_83 ;
if ( V_126 == NULL )
return false ;
return ! ! ( V_126 -> V_128 & V_129 ) ;
}
T_1 F_68 ( struct V_1 * V_6 , struct V_122 * V_83 ,
struct V_87 * V_76 )
{
T_1 V_36 = 0 ;
if ( V_76 && V_76 -> V_77 != V_39 )
V_36 |= V_183 ;
if ( V_76 && V_76 -> V_77 == V_45 ) {
V_36 |= V_184 ;
if ( V_83 -> V_185 == V_186 )
V_36 |= V_187 ;
}
if ( V_6 -> V_188 >= V_189 )
V_36 |= V_190 ;
V_36 |= V_191 ;
if ( ! F_98 ( V_83 ) )
V_36 |= V_192 ;
return V_36 ;
}
static void F_99 ( struct V_61 * V_75 )
{
struct V_1 * V_6 = F_1 ( V_75 -> V_3 ) ;
unsigned V_167 , V_193 ;
for ( V_167 = 0 ; V_167 < V_194 ; ++ V_167 ) {
struct V_195 * V_196 = & V_6 -> V_5 . V_197 [ V_167 ] ;
for ( V_193 = 0 ; V_193 < V_198 ; ++ V_193 )
if ( & V_75 -> V_196 == V_196 -> V_196 [ V_193 ] )
V_196 -> V_196 [ V_193 ] = V_75 -> V_196 . V_199 ;
if ( & V_75 -> V_200 == V_196 -> V_201 )
V_196 -> V_201 = V_75 -> V_200 . V_199 ;
}
}
static struct V_195 * F_100 ( struct V_61 * V_75 )
{
struct V_1 * V_6 = F_1 ( V_75 -> V_3 ) ;
unsigned V_197 = F_101 ( F_102 ( V_75 -> V_101 ) ,
V_194 - 1 ) ;
return & V_6 -> V_5 . V_197 [ V_197 ] ;
}
static struct V_202 * F_103 ( struct V_61 * V_75 )
{
struct V_195 * V_196 = F_100 ( V_75 ) ;
struct V_202 * V_203 = V_196 -> V_196 [ V_75 -> V_76 . V_77 ] ;
V_196 -> V_196 [ V_75 -> V_76 . V_77 ] = & V_75 -> V_196 ;
while ( ( ++ V_196 ) -> V_196 [ V_75 -> V_76 . V_77 ] == V_203 )
V_196 -> V_196 [ V_75 -> V_76 . V_77 ] = & V_75 -> V_196 ;
return V_203 ;
}
static struct V_202 * F_104 ( struct V_61 * V_75 )
{
struct V_195 * V_196 = F_100 ( V_75 ) ;
struct V_202 * V_203 = V_196 -> V_201 ;
V_196 -> V_201 = & V_75 -> V_200 ;
while ( ( ++ V_196 ) -> V_201 == V_203 )
V_196 -> V_201 = & V_75 -> V_200 ;
return V_203 ;
}
int F_105 ( struct V_1 * V_6 )
{
unsigned V_167 , V_193 ;
int V_15 ;
V_15 = F_7 ( V_6 ) ;
if ( V_15 ) {
return V_15 ;
}
V_15 = F_106 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_24 . V_8 . V_9 ,
& V_204 ,
V_6 -> V_119 -> V_205 -> V_206 ,
V_207 ,
V_6 -> V_208 ) ;
if ( V_15 ) {
F_9 ( L_11 , V_15 ) ;
return V_15 ;
}
for ( V_167 = 0 ; V_167 < V_194 ; ++ V_167 ) {
struct V_195 * V_196 = & V_6 -> V_5 . V_197 [ V_167 ] ;
for ( V_193 = 0 ; V_193 < V_198 ; ++ V_193 )
V_196 -> V_196 [ V_193 ] = & V_6 -> V_5 . V_3 . V_38 [ V_193 ] . V_196 ;
V_196 -> V_201 = & V_6 -> V_5 . V_3 . V_209 -> V_201 ;
}
for ( V_193 = 0 ; V_193 < V_198 ; ++ V_193 )
V_6 -> V_5 . V_210 . V_196 [ V_193 ] = NULL ;
V_6 -> V_5 . V_210 . V_201 = NULL ;
V_6 -> V_5 . V_211 = true ;
V_15 = F_107 ( & V_6 -> V_5 . V_3 , V_52 ,
V_6 -> V_49 . V_212 >> V_98 ) ;
if ( V_15 ) {
F_9 ( L_12 ) ;
return V_15 ;
}
F_108 ( V_6 , V_6 -> V_49 . V_117 ) ;
V_15 = F_109 ( V_6 , 256 * 1024 , V_99 , true ,
V_213 ,
V_214 ,
NULL , NULL , & V_6 -> V_215 ) ;
if ( V_15 ) {
return V_15 ;
}
V_15 = F_110 ( V_6 -> V_215 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_111 ( V_6 -> V_215 , V_213 , NULL ) ;
F_112 ( V_6 -> V_215 ) ;
if ( V_15 ) {
F_113 ( & V_6 -> V_215 ) ;
return V_15 ;
}
F_114 ( L_13 ,
( unsigned ) ( V_6 -> V_49 . V_212 / ( 1024 * 1024 ) ) ) ;
V_15 = F_107 ( & V_6 -> V_5 . V_3 , V_45 ,
V_6 -> V_49 . V_216 >> V_98 ) ;
if ( V_15 ) {
F_9 ( L_14 ) ;
return V_15 ;
}
F_114 ( L_15 ,
( unsigned ) ( V_6 -> V_49 . V_216 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_217 . V_76 . V_218 = V_6 -> V_217 . V_76 . V_218 << V_219 ;
V_6 -> V_217 . V_76 . V_220 = V_6 -> V_217 . V_76 . V_220 << V_219 ;
V_6 -> V_217 . V_76 . V_221 = V_6 -> V_217 . V_76 . V_221 << V_219 ;
V_6 -> V_217 . V_222 . V_218 = V_6 -> V_217 . V_222 . V_218 << V_223 ;
V_6 -> V_217 . V_222 . V_220 = V_6 -> V_217 . V_222 . V_220 << V_223 ;
V_6 -> V_217 . V_222 . V_221 = V_6 -> V_217 . V_222 . V_221 << V_223 ;
V_6 -> V_217 . V_224 . V_218 = V_6 -> V_217 . V_224 . V_218 << V_225 ;
V_6 -> V_217 . V_224 . V_220 = V_6 -> V_217 . V_224 . V_220 << V_225 ;
V_6 -> V_217 . V_224 . V_221 = V_6 -> V_217 . V_224 . V_221 << V_225 ;
V_15 = F_107 ( & V_6 -> V_5 . V_3 , V_57 ,
V_6 -> V_217 . V_76 . V_218 >> V_98 ) ;
if ( V_15 ) {
F_9 ( L_16 ) ;
return V_15 ;
}
V_15 = F_107 ( & V_6 -> V_5 . V_3 , V_58 ,
V_6 -> V_217 . V_222 . V_218 >> V_98 ) ;
if ( V_15 ) {
F_9 ( L_17 ) ;
return V_15 ;
}
V_15 = F_107 ( & V_6 -> V_5 . V_3 , V_59 ,
V_6 -> V_217 . V_224 . V_218 >> V_98 ) ;
if ( V_15 ) {
F_9 ( L_18 ) ;
return V_15 ;
}
V_15 = F_115 ( V_6 ) ;
if ( V_15 ) {
F_9 ( L_19 ) ;
return V_15 ;
}
return 0 ;
}
void F_116 ( struct V_1 * V_6 )
{
int V_15 ;
if ( ! V_6 -> V_5 . V_211 )
return;
F_117 ( V_6 ) ;
if ( V_6 -> V_215 ) {
V_15 = F_110 ( V_6 -> V_215 , false ) ;
if ( V_15 == 0 ) {
F_118 ( V_6 -> V_215 ) ;
F_112 ( V_6 -> V_215 ) ;
}
F_113 ( & V_6 -> V_215 ) ;
}
F_119 ( & V_6 -> V_5 . V_3 , V_52 ) ;
F_119 ( & V_6 -> V_5 . V_3 , V_45 ) ;
F_119 ( & V_6 -> V_5 . V_3 , V_57 ) ;
F_119 ( & V_6 -> V_5 . V_3 , V_58 ) ;
F_119 ( & V_6 -> V_5 . V_3 , V_59 ) ;
F_120 ( & V_6 -> V_5 . V_3 ) ;
F_121 ( V_6 ) ;
F_12 ( V_6 ) ;
V_6 -> V_5 . V_211 = false ;
F_114 ( L_20 ) ;
}
void F_108 ( struct V_1 * V_6 , V_96 V_20 )
{
struct V_37 * V_38 ;
if ( ! V_6 -> V_5 . V_211 )
return;
V_38 = & V_6 -> V_5 . V_3 . V_38 [ V_52 ] ;
V_38 -> V_20 = V_20 >> V_98 ;
}
int F_122 ( struct V_81 * V_82 , struct V_134 * V_135 )
{
struct V_226 * V_227 ;
struct V_1 * V_6 ;
if ( F_31 ( V_135 -> V_228 < V_207 ) )
return - V_60 ;
V_227 = V_82 -> V_229 ;
V_6 = V_227 -> V_230 -> V_157 -> V_231 ;
if ( V_6 == NULL )
return - V_60 ;
return F_123 ( V_82 , V_135 , & V_6 -> V_5 . V_3 ) ;
}
int F_26 ( struct V_11 * V_12 ,
T_2 V_232 ,
T_2 V_233 ,
T_1 V_234 ,
struct V_235 * V_102 ,
struct V_95 * * V_95 )
{
struct V_1 * V_6 = V_12 -> V_6 ;
struct V_236 * V_237 ;
T_1 V_238 ;
unsigned V_239 , V_240 ;
unsigned V_167 ;
int V_15 ;
V_238 = V_6 -> V_5 . V_110 -> V_241 ;
V_239 = F_124 ( V_234 , V_238 ) ;
V_240 = V_239 * V_6 -> V_5 . V_110 -> V_242 ;
while ( V_240 & 0x7 )
V_240 ++ ;
V_15 = F_125 ( V_6 , V_240 * 4 , & V_237 ) ;
if ( V_15 )
return V_15 ;
if ( V_102 ) {
V_15 = F_126 ( V_6 , & V_237 -> V_243 , V_102 ,
V_244 ) ;
if ( V_15 ) {
F_9 ( L_21 , V_15 ) ;
goto V_245;
}
}
for ( V_167 = 0 ; V_167 < V_239 ; V_167 ++ ) {
T_1 V_246 = F_101 ( V_234 , V_238 ) ;
F_127 ( V_6 , & V_237 -> V_247 [ 0 ] , V_232 ,
V_233 , V_246 ) ;
V_232 += V_246 ;
V_233 += V_246 ;
V_234 -= V_246 ;
}
F_128 ( V_12 , & V_237 -> V_247 [ 0 ] ) ;
F_129 ( V_237 -> V_247 [ 0 ] . V_248 > V_240 ) ;
V_15 = F_130 ( V_237 , V_12 , & V_6 -> V_5 . V_34 ,
V_244 , V_95 ) ;
if ( V_15 )
goto V_245;
return 0 ;
V_245:
F_131 ( V_237 ) ;
return V_15 ;
}
static int F_132 ( struct V_249 * V_250 , void * V_251 )
{
struct V_252 * V_253 = (struct V_252 * ) V_250 -> V_254 ;
unsigned V_255 = * ( int * ) V_253 -> V_256 -> V_251 ;
struct V_257 * V_157 = V_253 -> V_230 -> V_157 ;
struct V_1 * V_6 = V_157 -> V_231 ;
struct V_258 * V_177 = (struct V_258 * ) V_6 -> V_5 . V_3 . V_38 [ V_255 ] . V_259 ;
int V_260 ;
struct V_27 * V_209 = V_6 -> V_5 . V_3 . V_209 ;
F_49 ( & V_209 -> V_261 ) ;
V_260 = F_133 ( V_250 , V_177 ) ;
F_51 ( & V_209 -> V_261 ) ;
if ( V_255 == V_52 )
F_134 ( V_250 , L_22 ,
V_6 -> V_5 . V_3 . V_38 [ V_255 ] . V_20 ,
( V_96 ) F_135 ( & V_6 -> V_262 ) >> 20 ,
( V_96 ) F_135 ( & V_6 -> V_263 ) >> 20 ) ;
return V_260 ;
}
static T_3 F_136 ( struct V_81 * V_264 , char T_4 * V_265 ,
T_5 V_20 , T_6 * V_266 )
{
struct V_1 * V_6 = V_264 -> V_267 -> V_268 ;
T_3 V_269 = 0 ;
int V_15 ;
if ( V_20 & 0x3 || * V_266 & 0x3 )
return - V_60 ;
while ( V_20 ) {
unsigned long V_36 ;
T_1 V_270 ;
if ( * V_266 >= V_6 -> V_49 . V_271 )
return V_269 ;
F_137 ( & V_6 -> V_272 , V_36 ) ;
F_138 ( V_273 , ( ( T_1 ) * V_266 ) | 0x80000000 ) ;
F_138 ( V_274 , * V_266 >> 31 ) ;
V_270 = F_139 ( V_275 ) ;
F_140 ( & V_6 -> V_272 , V_36 ) ;
V_15 = F_141 ( V_270 , ( T_1 * ) V_265 ) ;
if ( V_15 )
return V_15 ;
V_269 += 4 ;
V_265 += 4 ;
* V_266 += 4 ;
V_20 -= 4 ;
}
return V_269 ;
}
static T_3 F_142 ( struct V_81 * V_264 , char T_4 * V_265 ,
T_5 V_20 , T_6 * V_266 )
{
struct V_1 * V_6 = V_264 -> V_267 -> V_268 ;
T_3 V_269 = 0 ;
int V_15 ;
while ( V_20 ) {
T_6 V_139 = * V_266 / V_99 ;
unsigned V_276 = * V_266 & ~ V_277 ;
T_5 V_278 = F_143 ( T_5 , V_20 , V_99 - V_276 ) ;
struct V_123 * V_123 ;
void * V_279 ;
if ( V_139 >= V_6 -> V_163 . V_280 )
return V_269 ;
V_123 = V_6 -> V_163 . V_124 [ V_139 ] ;
if ( V_123 ) {
V_279 = F_144 ( V_123 ) ;
V_279 += V_276 ;
V_15 = F_145 ( V_265 , V_279 , V_278 ) ;
F_146 ( V_6 -> V_163 . V_124 [ V_139 ] ) ;
} else
V_15 = F_147 ( V_265 , V_278 ) ;
if ( V_15 )
return - V_176 ;
V_269 += V_278 ;
V_265 += V_278 ;
* V_266 += V_278 ;
V_20 -= V_278 ;
}
return V_269 ;
}
static int F_115 ( struct V_1 * V_6 )
{
#if F_148 ( V_281 )
unsigned V_282 ;
struct V_283 * V_230 = V_6 -> V_119 -> V_284 ;
struct V_285 * V_286 , * V_287 = V_230 -> V_288 ;
V_286 = F_149 ( L_23 , V_289 | V_290 , V_287 ,
V_6 , & V_291 ) ;
if ( F_150 ( V_286 ) )
return F_151 ( V_286 ) ;
F_152 ( V_286 -> V_292 , V_6 -> V_49 . V_271 ) ;
V_6 -> V_5 . V_293 = V_286 ;
#ifdef F_153
V_286 = F_149 ( L_24 , V_289 | V_290 , V_287 ,
V_6 , & V_294 ) ;
if ( F_150 ( V_286 ) )
return F_151 ( V_286 ) ;
F_152 ( V_286 -> V_292 , V_6 -> V_49 . V_216 ) ;
V_6 -> V_5 . V_126 = V_286 ;
#endif
V_282 = F_154 ( V_295 ) ;
#ifdef F_79
if ( ! F_80 () )
-- V_282 ;
#endif
return F_155 ( V_6 , V_295 , V_282 ) ;
#else
return 0 ;
#endif
}
static void F_117 ( struct V_1 * V_6 )
{
#if F_148 ( V_281 )
F_156 ( V_6 -> V_5 . V_293 ) ;
V_6 -> V_5 . V_293 = NULL ;
#ifdef F_153
F_156 ( V_6 -> V_5 . V_126 ) ;
V_6 -> V_5 . V_126 = NULL ;
#endif
#endif
}
