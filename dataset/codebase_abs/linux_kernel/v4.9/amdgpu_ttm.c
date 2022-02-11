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
int F_7 ( struct V_1 * V_6 )
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
if ( V_15 ) {
F_9 ( L_1
L_2 ) ;
goto V_24;
}
V_6 -> V_5 . V_25 . V_26 =
V_6 -> V_5 . V_17 . V_9 ;
V_10 = & V_6 -> V_5 . V_25 . V_8 ;
V_10 -> V_18 = V_27 ;
V_10 -> V_20 = sizeof( struct V_28 ) ;
V_10 -> V_22 = & V_29 ;
V_10 -> V_23 = & V_30 ;
V_15 = F_8 ( V_10 ) ;
if ( V_15 ) {
F_9 ( L_3 ) ;
goto V_31;
}
V_12 = V_6 -> V_5 . V_32 ;
V_14 = & V_12 -> V_33 . V_34 [ V_35 ] ;
V_15 = F_10 ( & V_12 -> V_33 , & V_6 -> V_5 . V_36 ,
V_14 , V_37 ) ;
if ( V_15 ) {
F_9 ( L_4 ) ;
goto V_38;
}
V_6 -> V_5 . V_16 = true ;
return 0 ;
V_38:
F_11 ( & V_6 -> V_5 . V_25 . V_8 ) ;
V_31:
F_11 ( & V_6 -> V_5 . V_17 ) ;
V_24:
return V_15 ;
}
static void F_12 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_16 ) {
F_13 ( V_6 -> V_5 . V_36 . V_33 ,
& V_6 -> V_5 . V_36 ) ;
F_11 ( & V_6 -> V_5 . V_25 . V_8 ) ;
F_11 ( & V_6 -> V_5 . V_17 ) ;
V_6 -> V_5 . V_16 = false ;
}
}
static int F_14 ( struct V_2 * V_3 , T_1 V_39 )
{
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_1 type ,
struct V_40 * V_41 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_42 :
V_41 -> V_39 = V_43 ;
V_41 -> V_44 = V_45 ;
V_41 -> V_46 = V_47 ;
break;
case V_48 :
V_41 -> V_49 = & V_50 ;
V_41 -> V_51 = V_6 -> V_52 . V_53 ;
V_41 -> V_44 = V_45 ;
V_41 -> V_46 = V_47 ;
V_41 -> V_39 = V_43 | V_54 ;
break;
case V_55 :
V_41 -> V_49 = & V_56 ;
V_41 -> V_51 = V_6 -> V_52 . V_57 ;
V_41 -> V_39 = V_58 |
V_43 ;
V_41 -> V_44 = V_59 | V_60 ;
V_41 -> V_46 = V_60 ;
break;
case V_61 :
case V_62 :
case V_63 :
V_41 -> V_49 = & V_56 ;
V_41 -> V_51 = 0 ;
V_41 -> V_39 = V_58 | V_54 ;
V_41 -> V_44 = V_59 ;
V_41 -> V_46 = V_59 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_64 ;
}
return 0 ;
}
static void F_16 ( struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
static struct V_71 V_72 = {
. V_73 = 0 ,
. V_74 = 0 ,
. V_39 = V_45 | V_75
} ;
unsigned V_76 ;
if ( ! F_17 ( V_66 ) ) {
V_68 -> V_68 = & V_72 ;
V_68 -> V_77 = & V_72 ;
V_68 -> V_78 = 1 ;
V_68 -> V_79 = 1 ;
return;
}
V_70 = F_2 ( V_66 , struct V_69 , V_80 ) ;
switch ( V_66 -> V_81 . V_82 ) {
case V_55 :
if ( V_70 -> V_6 -> V_5 . V_32 -> V_83 == false ) {
F_18 ( V_70 , V_84 ) ;
} else {
F_18 ( V_70 , V_85 ) ;
for ( V_76 = 0 ; V_76 < V_70 -> V_68 . V_78 ; ++ V_76 ) {
if ( ! ( V_70 -> V_72 [ V_76 ] . V_39 &
V_86 ) )
continue;
if ( V_70 -> V_72 [ V_76 ] . V_74 )
continue;
V_70 -> V_72 [ V_76 ] . V_74 =
V_70 -> V_6 -> V_52 . V_87 >> V_88 ;
}
}
break;
case V_48 :
default:
F_18 ( V_70 , V_84 ) ;
}
* V_68 = V_70 -> V_68 ;
}
static int F_19 ( struct V_65 * V_66 , struct V_89 * V_90 )
{
struct V_69 * V_70 = F_2 ( V_66 , struct V_69 , V_80 ) ;
if ( F_20 ( V_66 -> V_91 ) )
return - V_92 ;
return F_21 ( & V_70 -> V_93 . V_94 ,
V_90 -> V_95 ) ;
}
static void F_22 ( struct V_65 * V_66 ,
struct V_96 * V_97 )
{
struct V_96 * V_98 = & V_66 -> V_81 ;
F_23 ( V_98 -> V_99 != NULL ) ;
* V_98 = * V_97 ;
V_97 -> V_99 = NULL ;
}
static int F_24 ( struct V_65 * V_66 ,
bool V_100 , bool V_101 ,
struct V_96 * V_97 ,
struct V_96 * V_98 )
{
struct V_1 * V_6 ;
struct V_11 * V_12 ;
T_2 V_102 , V_103 ;
struct V_104 * V_104 ;
int V_15 ;
V_6 = F_1 ( V_66 -> V_3 ) ;
V_12 = V_6 -> V_5 . V_32 ;
switch ( V_98 -> V_82 ) {
case V_48 :
V_15 = F_25 ( V_66 , V_98 ) ;
if ( V_15 )
return V_15 ;
case V_55 :
V_102 = ( V_105 ) V_98 -> V_106 << V_88 ;
V_102 += V_66 -> V_3 -> V_41 [ V_98 -> V_82 ] . V_51 ;
break;
default:
F_9 ( L_6 , V_98 -> V_82 ) ;
return - V_64 ;
}
switch ( V_97 -> V_82 ) {
case V_48 :
V_15 = F_25 ( V_66 , V_97 ) ;
if ( V_15 )
return V_15 ;
case V_55 :
V_103 = ( V_105 ) V_97 -> V_106 << V_88 ;
V_103 += V_66 -> V_3 -> V_41 [ V_97 -> V_82 ] . V_51 ;
break;
default:
F_9 ( L_6 , V_98 -> V_82 ) ;
return - V_64 ;
}
if ( ! V_12 -> V_83 ) {
F_9 ( L_7 ) ;
return - V_64 ;
}
F_26 ( ( V_107 % V_108 ) != 0 ) ;
V_15 = F_27 ( V_12 , V_102 , V_103 ,
V_97 -> V_109 * V_107 ,
V_66 -> V_110 , & V_104 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_28 ( V_66 , V_104 , V_100 , V_97 ) ;
F_29 ( V_104 ) ;
return V_15 ;
}
static int F_30 ( struct V_65 * V_66 ,
bool V_100 , bool V_111 ,
bool V_101 ,
struct V_96 * V_97 )
{
struct V_1 * V_6 ;
struct V_96 * V_98 = & V_66 -> V_81 ;
struct V_96 V_112 ;
struct V_71 V_72 ;
struct V_67 V_68 ;
int V_15 ;
V_6 = F_1 ( V_66 -> V_3 ) ;
V_112 = * V_97 ;
V_112 . V_99 = NULL ;
V_68 . V_78 = 1 ;
V_68 . V_68 = & V_72 ;
V_68 . V_79 = 1 ;
V_68 . V_77 = & V_72 ;
V_72 . V_73 = 0 ;
V_72 . V_74 = V_6 -> V_52 . V_87 >> V_88 ;
V_72 . V_39 = V_45 | V_86 ;
V_15 = F_31 ( V_66 , & V_68 , & V_112 ,
V_111 , V_101 ) ;
if ( F_32 ( V_15 ) ) {
return V_15 ;
}
V_15 = F_33 ( V_66 -> V_91 , V_112 . V_68 ) ;
if ( F_32 ( V_15 ) ) {
goto V_113;
}
V_15 = F_34 ( V_66 -> V_91 , & V_112 ) ;
if ( F_32 ( V_15 ) ) {
goto V_113;
}
V_15 = F_24 ( V_66 , true , V_101 , & V_112 , V_98 ) ;
if ( F_32 ( V_15 ) ) {
goto V_113;
}
V_15 = F_35 ( V_66 , V_111 , V_101 , V_97 ) ;
V_113:
F_36 ( V_66 , & V_112 ) ;
return V_15 ;
}
static int F_37 ( struct V_65 * V_66 ,
bool V_100 , bool V_111 ,
bool V_101 ,
struct V_96 * V_97 )
{
struct V_1 * V_6 ;
struct V_96 * V_98 = & V_66 -> V_81 ;
struct V_96 V_112 ;
struct V_67 V_68 ;
struct V_71 V_72 ;
int V_15 ;
V_6 = F_1 ( V_66 -> V_3 ) ;
V_112 = * V_97 ;
V_112 . V_99 = NULL ;
V_68 . V_78 = 1 ;
V_68 . V_68 = & V_72 ;
V_68 . V_79 = 1 ;
V_68 . V_77 = & V_72 ;
V_72 . V_73 = 0 ;
V_72 . V_74 = V_6 -> V_52 . V_87 >> V_88 ;
V_72 . V_39 = V_45 | V_86 ;
V_15 = F_31 ( V_66 , & V_68 , & V_112 ,
V_111 , V_101 ) ;
if ( F_32 ( V_15 ) ) {
return V_15 ;
}
V_15 = F_35 ( V_66 , V_111 , V_101 , & V_112 ) ;
if ( F_32 ( V_15 ) ) {
goto V_113;
}
V_15 = F_24 ( V_66 , true , V_101 , V_97 , V_98 ) ;
if ( F_32 ( V_15 ) ) {
goto V_113;
}
V_113:
F_36 ( V_66 , & V_112 ) ;
return V_15 ;
}
static int F_38 ( struct V_65 * V_66 ,
bool V_100 , bool V_111 ,
bool V_101 ,
struct V_96 * V_97 )
{
struct V_1 * V_6 ;
struct V_69 * V_70 ;
struct V_96 * V_98 = & V_66 -> V_81 ;
int V_15 ;
V_70 = F_2 ( V_66 , struct V_69 , V_80 ) ;
if ( F_39 ( V_70 -> V_114 > 0 ) )
return - V_64 ;
V_6 = F_1 ( V_66 -> V_3 ) ;
if ( V_100 )
F_40 ( & V_6 -> V_115 ) ;
if ( V_98 -> V_82 == V_42 && V_66 -> V_91 == NULL ) {
F_22 ( V_66 , V_97 ) ;
return 0 ;
}
if ( ( V_98 -> V_82 == V_48 &&
V_97 -> V_82 == V_42 ) ||
( V_98 -> V_82 == V_42 &&
V_97 -> V_82 == V_48 ) ) {
F_22 ( V_66 , V_97 ) ;
return 0 ;
}
if ( V_6 -> V_5 . V_116 == NULL ||
V_6 -> V_5 . V_32 == NULL ||
! V_6 -> V_5 . V_32 -> V_83 ) {
goto memcpy;
}
if ( V_98 -> V_82 == V_55 &&
V_97 -> V_82 == V_42 ) {
V_15 = F_30 ( V_66 , V_100 , V_111 ,
V_101 , V_97 ) ;
} else if ( V_98 -> V_82 == V_42 &&
V_97 -> V_82 == V_55 ) {
V_15 = F_37 ( V_66 , V_100 , V_111 ,
V_101 , V_97 ) ;
} else {
V_15 = F_24 ( V_66 , V_100 , V_101 , V_97 , V_98 ) ;
}
if ( V_15 ) {
memcpy:
V_15 = F_41 ( V_66 , V_111 , V_101 , V_97 ) ;
if ( V_15 ) {
return V_15 ;
}
}
F_42 ( ( V_105 ) V_66 -> V_109 << V_88 , & V_6 -> V_117 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_96 * V_81 )
{
struct V_40 * V_41 = & V_3 -> V_41 [ V_81 -> V_82 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_81 -> V_118 . V_119 = NULL ;
V_81 -> V_118 . V_120 = 0 ;
V_81 -> V_118 . V_20 = V_81 -> V_109 << V_88 ;
V_81 -> V_118 . V_121 = 0 ;
V_81 -> V_118 . V_122 = false ;
if ( ! ( V_41 -> V_39 & V_43 ) )
return - V_64 ;
switch ( V_81 -> V_82 ) {
case V_42 :
return 0 ;
case V_48 :
break;
case V_55 :
V_81 -> V_118 . V_120 = V_81 -> V_106 << V_88 ;
if ( ( V_81 -> V_118 . V_120 + V_81 -> V_118 . V_20 ) > V_6 -> V_52 . V_123 )
return - V_64 ;
V_81 -> V_118 . V_121 = V_6 -> V_52 . V_124 ;
V_81 -> V_118 . V_122 = true ;
#ifdef F_44
if ( V_81 -> V_68 & V_60 )
V_81 -> V_118 . V_119 =
F_45 ( V_81 -> V_118 . V_121 + V_81 -> V_118 . V_120 ,
V_81 -> V_118 . V_20 ) ;
else
V_81 -> V_118 . V_119 =
F_46 ( V_81 -> V_118 . V_121 + V_81 -> V_118 . V_120 ,
V_81 -> V_118 . V_20 ) ;
V_81 -> V_118 . V_121 = ( V_81 -> V_118 . V_121 & 0x0ffffffffUL ) +
V_6 -> V_125 -> V_126 -> V_127 ;
#endif
break;
default:
return - V_64 ;
}
return 0 ;
}
static void F_47 ( struct V_2 * V_3 , struct V_96 * V_81 )
{
}
int F_48 ( struct V_128 * V_91 , struct V_129 * * V_130 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
unsigned int V_39 = 0 ;
unsigned V_133 = 0 ;
int V_15 ;
if ( ! ( V_132 -> V_134 & V_135 ) )
V_39 |= V_136 ;
if ( V_132 -> V_134 & V_137 ) {
unsigned long V_138 = V_132 -> V_139 + V_91 -> V_109 * V_107 ;
struct V_140 * V_141 ;
V_141 = F_49 ( V_132 -> V_142 , V_132 -> V_139 ) ;
if ( ! V_141 || V_141 -> V_143 || V_141 -> V_144 < V_138 )
return - V_92 ;
}
do {
unsigned V_109 = V_91 -> V_109 - V_133 ;
T_2 V_139 = V_132 -> V_139 + V_133 * V_107 ;
struct V_129 * * V_145 = V_130 + V_133 ;
struct V_146 V_147 ;
V_147 . V_148 = V_149 ;
F_50 ( & V_132 -> V_150 ) ;
F_51 ( & V_147 . V_151 , & V_132 -> V_152 ) ;
F_52 ( & V_132 -> V_150 ) ;
V_15 = F_53 ( V_139 , V_109 , V_39 , V_145 , NULL ) ;
F_50 ( & V_132 -> V_150 ) ;
F_54 ( & V_147 . V_151 ) ;
F_52 ( & V_132 -> V_150 ) ;
if ( V_15 < 0 )
goto V_153;
V_133 += V_15 ;
} while ( V_133 < V_91 -> V_109 );
return 0 ;
V_153:
V_153 ( V_130 , V_133 , 0 ) ;
return V_15 ;
}
static int F_55 ( struct V_128 * V_91 )
{
struct V_1 * V_6 = F_1 ( V_91 -> V_3 ) ;
struct V_131 * V_132 = ( void * ) V_91 ;
unsigned V_154 ;
int V_15 ;
int V_155 = ! ( V_132 -> V_134 & V_135 ) ;
enum V_156 V_157 = V_155 ?
V_158 : V_159 ;
V_15 = F_56 ( V_91 -> V_160 , V_91 -> V_130 , V_91 -> V_109 , 0 ,
V_91 -> V_109 << V_88 ,
V_161 ) ;
if ( V_15 )
goto V_162;
V_15 = - V_163 ;
V_154 = F_57 ( V_6 -> V_164 , V_91 -> V_160 -> V_165 , V_91 -> V_160 -> V_154 , V_157 ) ;
if ( V_154 != V_91 -> V_160 -> V_154 )
goto V_162;
F_58 ( V_91 -> V_160 , V_91 -> V_130 ,
V_132 -> V_91 . V_166 , V_91 -> V_109 ) ;
return 0 ;
V_162:
F_59 ( V_91 -> V_160 ) ;
return V_15 ;
}
static void F_60 ( struct V_128 * V_91 )
{
struct V_1 * V_6 = F_1 ( V_91 -> V_3 ) ;
struct V_131 * V_132 = ( void * ) V_91 ;
struct V_167 V_168 ;
int V_155 = ! ( V_132 -> V_134 & V_135 ) ;
enum V_156 V_157 = V_155 ?
V_158 : V_159 ;
if ( ! V_91 -> V_160 -> V_165 )
return;
F_61 ( V_6 -> V_164 , V_91 -> V_160 -> V_165 , V_91 -> V_160 -> V_154 , V_157 ) ;
F_62 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_129 * V_129 = F_63 ( & V_168 ) ;
if ( ! ( V_132 -> V_134 & V_135 ) )
F_64 ( V_129 ) ;
F_65 ( V_129 ) ;
F_66 ( V_129 ) ;
}
F_67 ( V_91 -> V_160 ) ;
}
static int F_68 ( struct V_128 * V_91 ,
struct V_96 * V_169 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
int V_15 ;
if ( V_132 -> V_139 ) {
V_15 = F_55 ( V_91 ) ;
if ( V_15 ) {
F_9 ( L_8 ) ;
return V_15 ;
}
}
if ( ! V_91 -> V_109 ) {
F_69 ( 1 , L_9 ,
V_91 -> V_109 , V_169 , V_91 ) ;
}
if ( V_169 -> V_82 == V_61 ||
V_169 -> V_82 == V_62 ||
V_169 -> V_82 == V_63 )
return - V_64 ;
return 0 ;
}
bool F_70 ( struct V_128 * V_91 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
return V_132 && ! F_71 ( & V_132 -> V_151 ) ;
}
int F_25 ( struct V_65 * V_66 , struct V_96 * V_169 )
{
struct V_128 * V_91 = V_66 -> V_91 ;
struct V_131 * V_132 = ( void * ) V_66 -> V_91 ;
T_1 V_39 ;
int V_15 ;
if ( ! V_91 || F_70 ( V_91 ) )
return 0 ;
V_15 = F_72 ( & V_66 -> V_3 -> V_41 [ V_48 ] , V_66 ,
NULL , V_169 ) ;
if ( V_15 ) {
F_9 ( L_10 , V_15 ) ;
return V_15 ;
}
V_39 = F_73 ( V_132 -> V_6 , V_91 , V_169 ) ;
V_132 -> V_120 = ( V_105 ) V_169 -> V_106 << V_88 ;
V_15 = F_74 ( V_132 -> V_6 , V_132 -> V_120 , V_91 -> V_109 ,
V_91 -> V_130 , V_132 -> V_91 . V_166 , V_39 ) ;
if ( V_15 ) {
F_9 ( L_11 ,
V_91 -> V_109 , V_132 -> V_120 ) ;
return V_15 ;
}
F_50 ( & V_132 -> V_6 -> V_170 ) ;
F_75 ( & V_132 -> V_151 , & V_132 -> V_6 -> V_171 ) ;
F_52 ( & V_132 -> V_6 -> V_170 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_6 )
{
struct V_131 * V_132 , * V_172 ;
struct V_96 V_169 ;
T_1 V_39 ;
int V_15 ;
V_169 . V_82 = V_48 ;
F_50 ( & V_6 -> V_170 ) ;
F_77 (gtt, tmp, &adev->gtt_list, list) {
V_39 = F_73 ( V_132 -> V_6 , & V_132 -> V_91 . V_91 , & V_169 ) ;
V_15 = F_74 ( V_6 , V_132 -> V_120 , V_132 -> V_91 . V_91 . V_109 ,
V_132 -> V_91 . V_91 . V_130 , V_132 -> V_91 . V_166 ,
V_39 ) ;
if ( V_15 ) {
F_52 ( & V_6 -> V_170 ) ;
F_9 ( L_11 ,
V_132 -> V_91 . V_91 . V_109 , V_132 -> V_120 ) ;
return V_15 ;
}
}
F_52 ( & V_6 -> V_170 ) ;
return 0 ;
}
static int F_78 ( struct V_128 * V_91 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
if ( V_132 -> V_139 )
F_60 ( V_91 ) ;
if ( ! F_70 ( V_91 ) )
return 0 ;
if ( V_132 -> V_6 -> V_173 . V_83 )
F_79 ( V_132 -> V_6 , V_132 -> V_120 , V_91 -> V_109 ) ;
F_50 ( & V_132 -> V_6 -> V_170 ) ;
F_80 ( & V_132 -> V_151 ) ;
F_52 ( & V_132 -> V_6 -> V_170 ) ;
return 0 ;
}
static void F_81 ( struct V_128 * V_91 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
F_82 ( & V_132 -> V_91 ) ;
F_59 ( V_132 ) ;
}
static struct V_128 * F_83 ( struct V_2 * V_3 ,
unsigned long V_20 , T_1 V_174 ,
struct V_129 * V_175 )
{
struct V_1 * V_6 ;
struct V_131 * V_132 ;
V_6 = F_1 ( V_3 ) ;
V_132 = F_84 ( sizeof( struct V_131 ) , V_161 ) ;
if ( V_132 == NULL ) {
return NULL ;
}
V_132 -> V_91 . V_91 . V_49 = & V_176 ;
V_132 -> V_6 = V_6 ;
if ( F_85 ( & V_132 -> V_91 , V_3 , V_20 , V_174 , V_175 ) ) {
F_59 ( V_132 ) ;
return NULL ;
}
F_86 ( & V_132 -> V_151 ) ;
return & V_132 -> V_91 . V_91 ;
}
static int F_87 ( struct V_128 * V_91 )
{
struct V_1 * V_6 ;
struct V_131 * V_132 = ( void * ) V_91 ;
unsigned V_76 ;
int V_15 ;
bool V_177 = ! ! ( V_91 -> V_174 & V_178 ) ;
if ( V_91 -> V_179 != V_180 )
return 0 ;
if ( V_132 && V_132 -> V_139 ) {
V_91 -> V_160 = F_84 ( sizeof( struct V_181 ) , V_161 ) ;
if ( ! V_91 -> V_160 )
return - V_163 ;
V_91 -> V_174 |= V_178 ;
V_91 -> V_179 = V_182 ;
return 0 ;
}
if ( V_177 && V_91 -> V_160 ) {
F_58 ( V_91 -> V_160 , V_91 -> V_130 ,
V_132 -> V_91 . V_166 , V_91 -> V_109 ) ;
V_91 -> V_179 = V_182 ;
return 0 ;
}
V_6 = F_1 ( V_91 -> V_3 ) ;
#ifdef F_88
if ( F_89 () ) {
return F_90 ( & V_132 -> V_91 , V_6 -> V_164 ) ;
}
#endif
V_15 = F_91 ( V_91 ) ;
if ( V_15 ) {
return V_15 ;
}
for ( V_76 = 0 ; V_76 < V_91 -> V_109 ; V_76 ++ ) {
V_132 -> V_91 . V_166 [ V_76 ] = F_92 ( V_6 -> V_183 , V_91 -> V_130 [ V_76 ] ,
0 , V_107 ,
V_184 ) ;
if ( F_93 ( V_6 -> V_183 , V_132 -> V_91 . V_166 [ V_76 ] ) ) {
while ( V_76 -- ) {
F_94 ( V_6 -> V_183 , V_132 -> V_91 . V_166 [ V_76 ] ,
V_107 , V_184 ) ;
V_132 -> V_91 . V_166 [ V_76 ] = 0 ;
}
F_95 ( V_91 ) ;
return - V_185 ;
}
}
return 0 ;
}
static void F_96 ( struct V_128 * V_91 )
{
struct V_1 * V_6 ;
struct V_131 * V_132 = ( void * ) V_91 ;
unsigned V_76 ;
bool V_177 = ! ! ( V_91 -> V_174 & V_178 ) ;
if ( V_132 && V_132 -> V_139 ) {
F_59 ( V_91 -> V_160 ) ;
V_91 -> V_174 &= ~ V_178 ;
return;
}
if ( V_177 )
return;
V_6 = F_1 ( V_91 -> V_3 ) ;
#ifdef F_88
if ( F_89 () ) {
F_97 ( & V_132 -> V_91 , V_6 -> V_164 ) ;
return;
}
#endif
for ( V_76 = 0 ; V_76 < V_91 -> V_109 ; V_76 ++ ) {
if ( V_132 -> V_91 . V_166 [ V_76 ] ) {
F_94 ( V_6 -> V_183 , V_132 -> V_91 . V_166 [ V_76 ] ,
V_107 , V_184 ) ;
}
}
F_95 ( V_91 ) ;
}
int F_98 ( struct V_128 * V_91 , T_2 V_119 ,
T_1 V_39 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
if ( V_132 == NULL )
return - V_64 ;
V_132 -> V_139 = V_119 ;
V_132 -> V_142 = V_149 -> V_186 ;
V_132 -> V_134 = V_39 ;
F_99 ( & V_132 -> V_150 ) ;
F_86 ( & V_132 -> V_152 ) ;
F_100 ( & V_132 -> V_187 , 0 ) ;
return 0 ;
}
struct V_188 * F_20 ( struct V_128 * V_91 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
if ( V_132 == NULL )
return NULL ;
return V_132 -> V_142 ;
}
bool F_101 ( struct V_128 * V_91 , unsigned long V_106 ,
unsigned long V_138 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
struct V_146 * V_189 ;
unsigned long V_20 ;
if ( V_132 == NULL || ! V_132 -> V_139 )
return false ;
V_20 = ( unsigned long ) V_132 -> V_91 . V_91 . V_109 * V_107 ;
if ( V_132 -> V_139 > V_138 || V_132 -> V_139 + V_20 <= V_106 )
return false ;
F_50 ( & V_132 -> V_150 ) ;
F_102 (entry, &gtt->guptasks, list) {
if ( V_189 -> V_148 == V_149 ) {
F_52 ( & V_132 -> V_150 ) ;
return false ;
}
}
F_52 ( & V_132 -> V_150 ) ;
F_103 ( & V_132 -> V_187 ) ;
return true ;
}
bool F_104 ( struct V_128 * V_91 ,
int * V_190 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
int V_191 = * V_190 ;
* V_190 = F_105 ( & V_132 -> V_187 ) ;
return V_191 != * V_190 ;
}
bool F_106 ( struct V_128 * V_91 )
{
struct V_131 * V_132 = ( void * ) V_91 ;
if ( V_132 == NULL )
return false ;
return ! ! ( V_132 -> V_134 & V_135 ) ;
}
T_1 F_73 ( struct V_1 * V_6 , struct V_128 * V_91 ,
struct V_96 * V_81 )
{
T_1 V_39 = 0 ;
if ( V_81 && V_81 -> V_82 != V_42 )
V_39 |= V_192 ;
if ( V_81 && V_81 -> V_82 == V_48 ) {
V_39 |= V_193 ;
if ( V_91 -> V_194 == V_195 )
V_39 |= V_196 ;
}
if ( V_6 -> V_197 >= V_198 )
V_39 |= V_199 ;
V_39 |= V_200 ;
if ( ! F_106 ( V_91 ) )
V_39 |= V_201 ;
return V_39 ;
}
static void F_107 ( struct V_65 * V_80 )
{
struct V_1 * V_6 = F_1 ( V_80 -> V_3 ) ;
unsigned V_76 , V_202 ;
for ( V_76 = 0 ; V_76 < V_203 ; ++ V_76 ) {
struct V_204 * V_205 = & V_6 -> V_5 . V_206 [ V_76 ] ;
for ( V_202 = 0 ; V_202 < V_207 ; ++ V_202 )
if ( & V_80 -> V_205 == V_205 -> V_205 [ V_202 ] )
V_205 -> V_205 [ V_202 ] = V_80 -> V_205 . V_208 ;
if ( & V_80 -> V_209 == V_205 -> V_210 )
V_205 -> V_210 = V_80 -> V_209 . V_208 ;
}
}
static struct V_204 * F_108 ( struct V_65 * V_80 )
{
struct V_1 * V_6 = F_1 ( V_80 -> V_3 ) ;
unsigned V_206 = F_109 ( F_110 ( V_80 -> V_109 ) ,
V_203 - 1 ) ;
return & V_6 -> V_5 . V_206 [ V_206 ] ;
}
static struct V_211 * F_111 ( struct V_65 * V_80 )
{
struct V_204 * V_205 = F_108 ( V_80 ) ;
struct V_211 * V_212 = V_205 -> V_205 [ V_80 -> V_81 . V_82 ] ;
V_205 -> V_205 [ V_80 -> V_81 . V_82 ] = & V_80 -> V_205 ;
while ( ( ++ V_205 ) -> V_205 [ V_80 -> V_81 . V_82 ] == V_212 )
V_205 -> V_205 [ V_80 -> V_81 . V_82 ] = & V_80 -> V_205 ;
return V_212 ;
}
static struct V_211 * F_112 ( struct V_65 * V_80 )
{
struct V_204 * V_205 = F_108 ( V_80 ) ;
struct V_211 * V_212 = V_205 -> V_210 ;
V_205 -> V_210 = & V_80 -> V_209 ;
while ( ( ++ V_205 ) -> V_210 == V_212 )
V_205 -> V_210 = & V_80 -> V_209 ;
return V_212 ;
}
int F_113 ( struct V_1 * V_6 )
{
unsigned V_76 , V_202 ;
int V_15 ;
V_15 = F_114 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_25 . V_8 . V_9 ,
& V_213 ,
V_6 -> V_125 -> V_214 -> V_215 ,
V_216 ,
V_6 -> V_217 ) ;
if ( V_15 ) {
F_9 ( L_12 , V_15 ) ;
return V_15 ;
}
for ( V_76 = 0 ; V_76 < V_203 ; ++ V_76 ) {
struct V_204 * V_205 = & V_6 -> V_5 . V_206 [ V_76 ] ;
for ( V_202 = 0 ; V_202 < V_207 ; ++ V_202 )
V_205 -> V_205 [ V_202 ] = & V_6 -> V_5 . V_3 . V_41 [ V_202 ] . V_205 ;
V_205 -> V_210 = & V_6 -> V_5 . V_3 . V_218 -> V_210 ;
}
for ( V_202 = 0 ; V_202 < V_207 ; ++ V_202 )
V_6 -> V_5 . V_219 . V_205 [ V_202 ] = NULL ;
V_6 -> V_5 . V_219 . V_210 = NULL ;
V_6 -> V_5 . V_220 = true ;
V_15 = F_115 ( & V_6 -> V_5 . V_3 , V_55 ,
V_6 -> V_52 . V_221 >> V_88 ) ;
if ( V_15 ) {
F_9 ( L_13 ) ;
return V_15 ;
}
F_116 ( V_6 , V_6 -> V_52 . V_123 ) ;
V_15 = F_117 ( V_6 , 256 * 1024 , V_107 , true ,
V_222 ,
V_223 ,
NULL , NULL , & V_6 -> V_224 ) ;
if ( V_15 ) {
return V_15 ;
}
V_15 = F_118 ( V_6 -> V_224 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_119 ( V_6 -> V_224 , V_222 , NULL ) ;
F_120 ( V_6 -> V_224 ) ;
if ( V_15 ) {
F_121 ( & V_6 -> V_224 ) ;
return V_15 ;
}
F_122 ( L_14 ,
( unsigned ) ( V_6 -> V_52 . V_221 / ( 1024 * 1024 ) ) ) ;
V_15 = F_115 ( & V_6 -> V_5 . V_3 , V_48 ,
V_6 -> V_52 . V_87 >> V_88 ) ;
if ( V_15 ) {
F_9 ( L_15 ) ;
return V_15 ;
}
F_122 ( L_16 ,
( unsigned ) ( V_6 -> V_52 . V_87 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_225 . V_81 . V_226 = V_6 -> V_225 . V_81 . V_226 << V_227 ;
V_6 -> V_225 . V_81 . V_228 = V_6 -> V_225 . V_81 . V_228 << V_227 ;
V_6 -> V_225 . V_81 . V_229 = V_6 -> V_225 . V_81 . V_229 << V_227 ;
V_6 -> V_225 . V_230 . V_226 = V_6 -> V_225 . V_230 . V_226 << V_231 ;
V_6 -> V_225 . V_230 . V_228 = V_6 -> V_225 . V_230 . V_228 << V_231 ;
V_6 -> V_225 . V_230 . V_229 = V_6 -> V_225 . V_230 . V_229 << V_231 ;
V_6 -> V_225 . V_232 . V_226 = V_6 -> V_225 . V_232 . V_226 << V_233 ;
V_6 -> V_225 . V_232 . V_228 = V_6 -> V_225 . V_232 . V_228 << V_233 ;
V_6 -> V_225 . V_232 . V_229 = V_6 -> V_225 . V_232 . V_229 << V_233 ;
V_15 = F_115 ( & V_6 -> V_5 . V_3 , V_61 ,
V_6 -> V_225 . V_81 . V_226 >> V_88 ) ;
if ( V_15 ) {
F_9 ( L_17 ) ;
return V_15 ;
}
V_15 = F_115 ( & V_6 -> V_5 . V_3 , V_62 ,
V_6 -> V_225 . V_230 . V_226 >> V_88 ) ;
if ( V_15 ) {
F_9 ( L_18 ) ;
return V_15 ;
}
V_15 = F_115 ( & V_6 -> V_5 . V_3 , V_63 ,
V_6 -> V_225 . V_232 . V_226 >> V_88 ) ;
if ( V_15 ) {
F_9 ( L_19 ) ;
return V_15 ;
}
V_15 = F_123 ( V_6 ) ;
if ( V_15 ) {
F_9 ( L_20 ) ;
return V_15 ;
}
return 0 ;
}
void F_124 ( struct V_1 * V_6 )
{
int V_15 ;
if ( ! V_6 -> V_5 . V_220 )
return;
F_125 ( V_6 ) ;
if ( V_6 -> V_224 ) {
V_15 = F_118 ( V_6 -> V_224 , false ) ;
if ( V_15 == 0 ) {
F_126 ( V_6 -> V_224 ) ;
F_120 ( V_6 -> V_224 ) ;
}
F_121 ( & V_6 -> V_224 ) ;
}
F_127 ( & V_6 -> V_5 . V_3 , V_55 ) ;
F_127 ( & V_6 -> V_5 . V_3 , V_48 ) ;
F_127 ( & V_6 -> V_5 . V_3 , V_61 ) ;
F_127 ( & V_6 -> V_5 . V_3 , V_62 ) ;
F_127 ( & V_6 -> V_5 . V_3 , V_63 ) ;
F_128 ( & V_6 -> V_5 . V_3 ) ;
F_129 ( V_6 ) ;
F_12 ( V_6 ) ;
V_6 -> V_5 . V_220 = false ;
F_122 ( L_21 ) ;
}
void F_116 ( struct V_1 * V_6 , V_105 V_20 )
{
struct V_40 * V_41 ;
if ( ! V_6 -> V_5 . V_220 )
return;
V_41 = & V_6 -> V_5 . V_3 . V_41 [ V_55 ] ;
V_41 -> V_20 = V_20 >> V_88 ;
}
int F_130 ( struct V_89 * V_90 , struct V_140 * V_141 )
{
struct V_234 * V_235 ;
struct V_1 * V_6 ;
if ( F_32 ( V_141 -> V_236 < V_216 ) )
return - V_64 ;
V_235 = V_90 -> V_95 ;
V_6 = V_235 -> V_237 -> V_164 -> V_238 ;
if ( V_6 == NULL )
return - V_64 ;
return F_131 ( V_90 , V_141 , & V_6 -> V_5 . V_3 ) ;
}
int F_27 ( struct V_11 * V_12 ,
T_2 V_239 ,
T_2 V_240 ,
T_1 V_241 ,
struct V_242 * V_110 ,
struct V_104 * * V_104 , bool V_243 )
{
struct V_1 * V_6 = V_12 -> V_6 ;
struct V_244 * V_245 ;
T_1 V_246 ;
unsigned V_247 , V_248 ;
unsigned V_76 ;
int V_15 ;
V_246 = V_6 -> V_5 . V_116 -> V_249 ;
V_247 = F_132 ( V_241 , V_246 ) ;
V_248 = V_247 * V_6 -> V_5 . V_116 -> V_250 ;
while ( V_248 & 0x7 )
V_248 ++ ;
V_15 = F_133 ( V_6 , V_248 * 4 , & V_245 ) ;
if ( V_15 )
return V_15 ;
if ( V_110 ) {
V_15 = F_134 ( V_6 , & V_245 -> V_251 , V_110 ,
V_252 ) ;
if ( V_15 ) {
F_9 ( L_22 , V_15 ) ;
goto V_253;
}
}
for ( V_76 = 0 ; V_76 < V_247 ; V_76 ++ ) {
T_1 V_254 = F_109 ( V_241 , V_246 ) ;
F_135 ( V_6 , & V_245 -> V_255 [ 0 ] , V_239 ,
V_240 , V_254 ) ;
V_239 += V_254 ;
V_240 += V_254 ;
V_241 -= V_254 ;
}
F_136 ( V_12 , & V_245 -> V_255 [ 0 ] ) ;
F_137 ( V_245 -> V_255 [ 0 ] . V_256 > V_248 ) ;
if ( V_243 ) {
V_15 = F_138 ( V_12 , V_245 -> V_257 , V_245 -> V_255 ,
NULL , NULL , V_104 ) ;
V_245 -> V_104 = F_139 ( * V_104 ) ;
if ( V_15 )
F_9 ( L_23 , V_15 ) ;
F_140 ( V_245 ) ;
} else {
V_15 = F_141 ( V_245 , V_12 , & V_6 -> V_5 . V_36 ,
V_252 , V_104 ) ;
if ( V_15 )
goto V_253;
}
return V_15 ;
V_253:
F_140 ( V_245 ) ;
return V_15 ;
}
int F_142 ( struct V_69 * V_66 ,
T_1 V_258 ,
struct V_242 * V_110 ,
struct V_104 * * V_104 )
{
struct V_1 * V_6 = V_66 -> V_6 ;
struct V_244 * V_245 ;
struct V_11 * V_12 = V_6 -> V_5 . V_32 ;
T_1 V_246 , V_241 ;
T_2 V_240 ;
unsigned int V_247 , V_248 ;
unsigned int V_76 ;
int V_15 ;
V_241 = V_66 -> V_80 . V_109 << V_88 ;
V_246 = V_6 -> V_5 . V_116 -> V_259 ;
V_247 = F_132 ( V_241 , V_246 ) ;
V_248 = V_247 * V_6 -> V_5 . V_116 -> V_260 ;
while ( V_248 & 0x7 )
V_248 ++ ;
V_15 = F_133 ( V_6 , V_248 * 4 , & V_245 ) ;
if ( V_15 )
return V_15 ;
if ( V_110 ) {
V_15 = F_134 ( V_6 , & V_245 -> V_251 , V_110 ,
V_252 ) ;
if ( V_15 ) {
F_9 ( L_22 , V_15 ) ;
goto V_253;
}
}
V_240 = V_66 -> V_80 . V_81 . V_106 << V_88 ;
for ( V_76 = 0 ; V_76 < V_247 ; V_76 ++ ) {
T_1 V_254 = F_109 ( V_241 , V_246 ) ;
F_143 ( V_6 , & V_245 -> V_255 [ 0 ] , V_258 ,
V_240 , V_254 ) ;
V_240 += V_254 ;
V_241 -= V_254 ;
}
F_136 ( V_12 , & V_245 -> V_255 [ 0 ] ) ;
F_137 ( V_245 -> V_255 [ 0 ] . V_256 > V_248 ) ;
V_15 = F_141 ( V_245 , V_12 , & V_6 -> V_5 . V_36 ,
V_252 , V_104 ) ;
if ( V_15 )
goto V_253;
return 0 ;
V_253:
F_140 ( V_245 ) ;
return V_15 ;
}
static int F_144 ( struct V_261 * V_262 , void * V_263 )
{
struct V_264 * V_265 = (struct V_264 * ) V_262 -> V_266 ;
unsigned V_267 = * ( int * ) V_265 -> V_268 -> V_263 ;
struct V_269 * V_164 = V_265 -> V_237 -> V_164 ;
struct V_1 * V_6 = V_164 -> V_238 ;
struct V_270 * V_186 = (struct V_270 * ) V_6 -> V_5 . V_3 . V_41 [ V_267 ] . V_271 ;
int V_272 ;
struct V_28 * V_218 = V_6 -> V_5 . V_3 . V_218 ;
F_50 ( & V_218 -> V_273 ) ;
V_272 = F_145 ( V_262 , V_186 ) ;
F_52 ( & V_218 -> V_273 ) ;
if ( V_267 == V_55 )
F_146 ( V_262 , L_24 ,
V_6 -> V_5 . V_3 . V_41 [ V_267 ] . V_20 ,
( V_105 ) F_147 ( & V_6 -> V_274 ) >> 20 ,
( V_105 ) F_147 ( & V_6 -> V_275 ) >> 20 ) ;
return V_272 ;
}
static T_3 F_148 ( struct V_89 * V_276 , char T_4 * V_277 ,
T_5 V_20 , T_6 * V_278 )
{
struct V_1 * V_6 = V_276 -> V_279 -> V_280 ;
T_3 V_281 = 0 ;
int V_15 ;
if ( V_20 & 0x3 || * V_278 & 0x3 )
return - V_64 ;
while ( V_20 ) {
unsigned long V_39 ;
T_1 V_282 ;
if ( * V_278 >= V_6 -> V_52 . V_283 )
return V_281 ;
F_149 ( & V_6 -> V_284 , V_39 ) ;
F_150 ( V_285 , ( ( T_1 ) * V_278 ) | 0x80000000 ) ;
F_150 ( V_286 , * V_278 >> 31 ) ;
V_282 = F_151 ( V_287 ) ;
F_152 ( & V_6 -> V_284 , V_39 ) ;
V_15 = F_153 ( V_282 , ( T_1 * ) V_277 ) ;
if ( V_15 )
return V_15 ;
V_281 += 4 ;
V_277 += 4 ;
* V_278 += 4 ;
V_20 -= 4 ;
}
return V_281 ;
}
static T_3 F_154 ( struct V_89 * V_276 , char T_4 * V_277 ,
T_5 V_20 , T_6 * V_278 )
{
struct V_1 * V_6 = V_276 -> V_279 -> V_280 ;
T_3 V_281 = 0 ;
int V_15 ;
while ( V_20 ) {
T_6 V_145 = * V_278 / V_107 ;
unsigned V_288 = * V_278 & ~ V_289 ;
T_5 V_290 = F_155 ( T_5 , V_20 , V_107 - V_288 ) ;
struct V_129 * V_129 ;
void * V_291 ;
if ( V_145 >= V_6 -> V_173 . V_292 )
return V_281 ;
V_129 = V_6 -> V_173 . V_130 [ V_145 ] ;
if ( V_129 ) {
V_291 = F_156 ( V_129 ) ;
V_291 += V_288 ;
V_15 = F_157 ( V_277 , V_291 , V_290 ) ;
F_158 ( V_6 -> V_173 . V_130 [ V_145 ] ) ;
} else
V_15 = F_159 ( V_277 , V_290 ) ;
if ( V_15 )
return - V_185 ;
V_281 += V_290 ;
V_277 += V_290 ;
* V_278 += V_290 ;
V_20 -= V_290 ;
}
return V_281 ;
}
static int F_123 ( struct V_1 * V_6 )
{
#if F_160 ( V_293 )
unsigned V_294 ;
struct V_295 * V_237 = V_6 -> V_125 -> V_296 ;
struct V_297 * V_298 , * V_299 = V_237 -> V_300 ;
V_298 = F_161 ( L_25 , V_301 | V_302 , V_299 ,
V_6 , & V_303 ) ;
if ( F_162 ( V_298 ) )
return F_163 ( V_298 ) ;
F_164 ( V_298 -> V_304 , V_6 -> V_52 . V_283 ) ;
V_6 -> V_5 . V_305 = V_298 ;
#ifdef F_165
V_298 = F_161 ( L_26 , V_301 | V_302 , V_299 ,
V_6 , & V_306 ) ;
if ( F_162 ( V_298 ) )
return F_163 ( V_298 ) ;
F_164 ( V_298 -> V_304 , V_6 -> V_52 . V_87 ) ;
V_6 -> V_5 . V_132 = V_298 ;
#endif
V_294 = F_166 ( V_307 ) ;
#ifdef F_88
if ( ! F_89 () )
-- V_294 ;
#endif
return F_167 ( V_6 , V_307 , V_294 ) ;
#else
return 0 ;
#endif
}
static void F_125 ( struct V_1 * V_6 )
{
#if F_160 ( V_293 )
F_168 ( V_6 -> V_5 . V_305 ) ;
V_6 -> V_5 . V_305 = NULL ;
#ifdef F_165
F_168 ( V_6 -> V_5 . V_132 ) ;
V_6 -> V_5 . V_132 = NULL ;
#endif
#endif
}
V_105 F_169 ( struct V_1 * V_6 )
{
return F_170 ( V_6 -> V_5 . V_17 . V_9 ) ;
}
