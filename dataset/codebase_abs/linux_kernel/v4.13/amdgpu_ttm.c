static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_5 -> V_12 . V_13 = false ;
V_6 = & V_5 -> V_12 . V_14 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_17 = sizeof( struct V_18 ) ;
V_6 -> V_19 = & F_1 ;
V_6 -> V_20 = & F_3 ;
V_11 = F_6 ( V_6 ) ;
if ( V_11 ) {
F_7 ( L_1
L_2 ) ;
goto V_21;
}
V_5 -> V_12 . V_22 . V_23 =
V_5 -> V_12 . V_14 . V_3 ;
V_6 = & V_5 -> V_12 . V_22 . V_2 ;
V_6 -> V_15 = V_24 ;
V_6 -> V_17 = sizeof( struct V_25 ) ;
V_6 -> V_19 = & V_26 ;
V_6 -> V_20 = & V_27 ;
V_11 = F_6 ( V_6 ) ;
if ( V_11 ) {
F_7 ( L_3 ) ;
goto V_28;
}
V_8 = V_5 -> V_12 . V_29 ;
V_10 = & V_8 -> V_30 . V_31 [ V_32 ] ;
V_11 = F_8 ( & V_8 -> V_30 , & V_5 -> V_12 . V_33 ,
V_10 , V_34 ) ;
if ( V_11 ) {
F_7 ( L_4 ) ;
goto V_35;
}
V_5 -> V_12 . V_13 = true ;
return 0 ;
V_35:
F_9 ( & V_5 -> V_12 . V_22 . V_2 ) ;
V_28:
F_9 ( & V_5 -> V_12 . V_14 ) ;
V_21:
return V_11 ;
}
static void F_10 ( struct V_4 * V_5 )
{
if ( V_5 -> V_12 . V_13 ) {
F_11 ( V_5 -> V_12 . V_33 . V_30 ,
& V_5 -> V_12 . V_33 ) ;
F_9 ( & V_5 -> V_12 . V_22 . V_2 ) ;
F_9 ( & V_5 -> V_12 . V_14 ) ;
V_5 -> V_12 . V_13 = false ;
}
}
static int F_12 ( struct V_36 * V_37 , T_1 V_38 )
{
return 0 ;
}
static int F_13 ( struct V_36 * V_37 , T_1 type ,
struct V_39 * V_40 )
{
struct V_4 * V_5 ;
V_5 = F_14 ( V_37 ) ;
switch ( type ) {
case V_41 :
V_40 -> V_38 = V_42 ;
V_40 -> V_43 = V_44 ;
V_40 -> V_45 = V_46 ;
break;
case V_47 :
V_40 -> V_48 = & V_49 ;
V_40 -> V_50 = V_5 -> V_51 . V_52 ;
V_40 -> V_43 = V_44 ;
V_40 -> V_45 = V_46 ;
V_40 -> V_38 = V_42 | V_53 ;
break;
case V_54 :
V_40 -> V_48 = & V_55 ;
V_40 -> V_50 = V_5 -> V_51 . V_56 ;
V_40 -> V_38 = V_57 |
V_42 ;
V_40 -> V_43 = V_58 | V_59 ;
V_40 -> V_45 = V_59 ;
break;
case V_60 :
case V_61 :
case V_62 :
V_40 -> V_48 = & V_63 ;
V_40 -> V_50 = 0 ;
V_40 -> V_38 = V_57 | V_53 ;
V_40 -> V_43 = V_58 ;
V_40 -> V_45 = V_58 ;
break;
default:
F_7 ( L_5 , ( unsigned ) type ) ;
return - V_64 ;
}
return 0 ;
}
static void F_15 ( struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_4 * V_5 = F_14 ( V_66 -> V_37 ) ;
struct V_69 * V_70 ;
static struct V_71 V_72 = {
. V_73 = 0 ,
. V_74 = 0 ,
. V_38 = V_44 | V_75
} ;
unsigned V_76 ;
if ( ! F_16 ( V_66 ) ) {
V_68 -> V_68 = & V_72 ;
V_68 -> V_77 = & V_72 ;
V_68 -> V_78 = 1 ;
V_68 -> V_79 = 1 ;
return;
}
V_70 = F_17 ( V_66 , struct V_69 , V_80 ) ;
switch ( V_66 -> V_81 . V_82 ) {
case V_54 :
if ( V_5 -> V_12 . V_83 &&
V_5 -> V_12 . V_29 &&
V_5 -> V_12 . V_29 -> V_84 == false ) {
F_18 ( V_70 , V_85 ) ;
} else {
F_18 ( V_70 , V_86 ) ;
for ( V_76 = 0 ; V_76 < V_70 -> V_68 . V_78 ; ++ V_76 ) {
if ( ! ( V_70 -> V_72 [ V_76 ] . V_38 &
V_87 ) )
continue;
if ( V_70 -> V_72 [ V_76 ] . V_74 )
continue;
V_70 -> V_72 [ V_76 ] . V_74 =
V_5 -> V_51 . V_88 >> V_89 ;
}
}
break;
case V_47 :
default:
F_18 ( V_70 , V_85 ) ;
}
* V_68 = V_70 -> V_68 ;
}
static int F_19 ( struct V_65 * V_66 , struct V_90 * V_91 )
{
struct V_69 * V_70 = F_17 ( V_66 , struct V_69 , V_80 ) ;
if ( F_20 ( V_66 -> V_92 ) )
return - V_93 ;
return F_21 ( & V_70 -> V_94 . V_95 ,
V_91 -> V_96 ) ;
}
static void F_22 ( struct V_65 * V_66 ,
struct V_97 * V_98 )
{
struct V_97 * V_99 = & V_66 -> V_81 ;
F_23 ( V_99 -> V_100 != NULL ) ;
* V_99 = * V_98 ;
V_98 -> V_100 = NULL ;
}
static int F_24 ( struct V_65 * V_66 ,
struct V_101 * V_100 ,
struct V_97 * V_81 ,
T_2 * V_102 )
{
int V_11 ;
switch ( V_81 -> V_82 ) {
case V_47 :
V_11 = F_25 ( V_66 , V_81 ) ;
if ( V_11 )
return V_11 ;
case V_54 :
* V_102 = V_100 -> V_103 << V_89 ;
* V_102 += V_66 -> V_37 -> V_40 [ V_81 -> V_82 ] . V_50 ;
break;
default:
F_7 ( L_6 , V_81 -> V_82 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_26 ( struct V_65 * V_66 ,
bool V_104 , bool V_105 ,
struct V_97 * V_98 ,
struct V_97 * V_99 )
{
struct V_4 * V_5 = F_14 ( V_66 -> V_37 ) ;
struct V_7 * V_8 = V_5 -> V_12 . V_29 ;
struct V_101 * V_106 , * V_107 ;
T_2 V_108 , V_109 , V_110 , V_111 ;
unsigned long V_112 ;
struct V_113 * V_114 = NULL ;
int V_11 ;
F_27 ( ( V_115 % V_116 ) != 0 ) ;
if ( ! V_8 -> V_84 ) {
F_7 ( L_7 ) ;
return - V_64 ;
}
V_106 = V_99 -> V_100 ;
V_11 = F_24 ( V_66 , V_106 , V_99 , & V_108 ) ;
if ( V_11 )
return V_11 ;
V_109 = V_106 -> V_17 ;
V_107 = V_98 -> V_100 ;
V_11 = F_24 ( V_66 , V_107 , V_98 , & V_110 ) ;
if ( V_11 )
return V_11 ;
V_111 = V_107 -> V_17 ;
V_112 = V_98 -> V_112 ;
while ( V_112 ) {
unsigned long V_117 = F_28 ( V_109 , V_111 ) ;
struct V_113 * V_118 ;
V_11 = F_29 ( V_8 , V_108 , V_110 ,
V_117 * V_115 ,
V_66 -> V_119 , & V_118 , false ) ;
if ( V_11 )
goto error;
F_30 ( V_114 ) ;
V_114 = V_118 ;
V_112 -= V_117 ;
if ( ! V_112 )
break;
V_109 -= V_117 ;
if ( ! V_109 ) {
V_11 = F_24 ( V_66 , ++ V_106 , V_99 ,
& V_108 ) ;
if ( V_11 )
goto error;
V_109 = V_106 -> V_17 ;
} else {
V_108 += V_117 * V_115 ;
}
V_111 -= V_117 ;
if ( ! V_111 ) {
V_11 = F_24 ( V_66 , ++ V_107 , V_98 ,
& V_110 ) ;
if ( V_11 )
goto error;
V_111 = V_107 -> V_17 ;
} else {
V_110 += V_117 * V_115 ;
}
}
V_11 = F_31 ( V_66 , V_114 , V_104 , V_98 ) ;
F_30 ( V_114 ) ;
return V_11 ;
error:
if ( V_114 )
F_32 ( V_114 , false ) ;
F_30 ( V_114 ) ;
return V_11 ;
}
static int F_33 ( struct V_65 * V_66 ,
bool V_104 , bool V_120 ,
bool V_105 ,
struct V_97 * V_98 )
{
struct V_4 * V_5 ;
struct V_97 * V_99 = & V_66 -> V_81 ;
struct V_97 V_121 ;
struct V_71 V_72 ;
struct V_67 V_68 ;
int V_11 ;
V_5 = F_14 ( V_66 -> V_37 ) ;
V_121 = * V_98 ;
V_121 . V_100 = NULL ;
V_68 . V_78 = 1 ;
V_68 . V_68 = & V_72 ;
V_68 . V_79 = 1 ;
V_68 . V_77 = & V_72 ;
V_72 . V_73 = 0 ;
V_72 . V_74 = V_5 -> V_51 . V_88 >> V_89 ;
V_72 . V_38 = V_44 | V_87 ;
V_11 = F_34 ( V_66 , & V_68 , & V_121 ,
V_120 , V_105 ) ;
if ( F_35 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_36 ( V_66 -> V_92 , V_121 . V_68 ) ;
if ( F_35 ( V_11 ) ) {
goto V_122;
}
V_11 = F_37 ( V_66 -> V_92 , & V_121 ) ;
if ( F_35 ( V_11 ) ) {
goto V_122;
}
V_11 = F_26 ( V_66 , true , V_105 , & V_121 , V_99 ) ;
if ( F_35 ( V_11 ) ) {
goto V_122;
}
V_11 = F_38 ( V_66 , V_120 , V_105 , V_98 ) ;
V_122:
F_39 ( V_66 , & V_121 ) ;
return V_11 ;
}
static int F_40 ( struct V_65 * V_66 ,
bool V_104 , bool V_120 ,
bool V_105 ,
struct V_97 * V_98 )
{
struct V_4 * V_5 ;
struct V_97 * V_99 = & V_66 -> V_81 ;
struct V_97 V_121 ;
struct V_67 V_68 ;
struct V_71 V_72 ;
int V_11 ;
V_5 = F_14 ( V_66 -> V_37 ) ;
V_121 = * V_98 ;
V_121 . V_100 = NULL ;
V_68 . V_78 = 1 ;
V_68 . V_68 = & V_72 ;
V_68 . V_79 = 1 ;
V_68 . V_77 = & V_72 ;
V_72 . V_73 = 0 ;
V_72 . V_74 = V_5 -> V_51 . V_88 >> V_89 ;
V_72 . V_38 = V_44 | V_87 ;
V_11 = F_34 ( V_66 , & V_68 , & V_121 ,
V_120 , V_105 ) ;
if ( F_35 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_38 ( V_66 , V_120 , V_105 , & V_121 ) ;
if ( F_35 ( V_11 ) ) {
goto V_122;
}
V_11 = F_26 ( V_66 , true , V_105 , V_98 , V_99 ) ;
if ( F_35 ( V_11 ) ) {
goto V_122;
}
V_122:
F_39 ( V_66 , & V_121 ) ;
return V_11 ;
}
static int F_41 ( struct V_65 * V_66 ,
bool V_104 , bool V_120 ,
bool V_105 ,
struct V_97 * V_98 )
{
struct V_4 * V_5 ;
struct V_69 * V_70 ;
struct V_97 * V_99 = & V_66 -> V_81 ;
int V_11 ;
V_70 = F_17 ( V_66 , struct V_69 , V_80 ) ;
if ( F_42 ( V_70 -> V_123 > 0 ) )
return - V_64 ;
V_5 = F_14 ( V_66 -> V_37 ) ;
if ( V_99 -> V_82 == V_41 && V_66 -> V_92 == NULL ) {
F_22 ( V_66 , V_98 ) ;
return 0 ;
}
if ( ( V_99 -> V_82 == V_47 &&
V_98 -> V_82 == V_41 ) ||
( V_99 -> V_82 == V_41 &&
V_98 -> V_82 == V_47 ) ) {
F_22 ( V_66 , V_98 ) ;
return 0 ;
}
if ( V_5 -> V_12 . V_83 == NULL ||
V_5 -> V_12 . V_29 == NULL ||
! V_5 -> V_12 . V_29 -> V_84 ) {
goto memcpy;
}
if ( V_99 -> V_82 == V_54 &&
V_98 -> V_82 == V_41 ) {
V_11 = F_33 ( V_66 , V_104 , V_120 ,
V_105 , V_98 ) ;
} else if ( V_99 -> V_82 == V_41 &&
V_98 -> V_82 == V_54 ) {
V_11 = F_40 ( V_66 , V_104 , V_120 ,
V_105 , V_98 ) ;
} else {
V_11 = F_26 ( V_66 , V_104 , V_105 , V_98 , V_99 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_43 ( V_66 , V_120 , V_105 , V_98 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_44 ( ( V_124 ) V_66 -> V_112 << V_89 , & V_5 -> V_125 ) ;
return 0 ;
}
static int F_45 ( struct V_36 * V_37 , struct V_97 * V_81 )
{
struct V_39 * V_40 = & V_37 -> V_40 [ V_81 -> V_82 ] ;
struct V_4 * V_5 = F_14 ( V_37 ) ;
V_81 -> V_126 . V_102 = NULL ;
V_81 -> V_126 . V_127 = 0 ;
V_81 -> V_126 . V_17 = V_81 -> V_112 << V_89 ;
V_81 -> V_126 . V_128 = 0 ;
V_81 -> V_126 . V_129 = false ;
if ( ! ( V_40 -> V_38 & V_42 ) )
return - V_64 ;
switch ( V_81 -> V_82 ) {
case V_41 :
return 0 ;
case V_47 :
break;
case V_54 :
V_81 -> V_126 . V_127 = V_81 -> V_103 << V_89 ;
if ( ( V_81 -> V_126 . V_127 + V_81 -> V_126 . V_17 ) > V_5 -> V_51 . V_130 )
return - V_64 ;
V_81 -> V_126 . V_128 = V_5 -> V_51 . V_131 ;
V_81 -> V_126 . V_129 = true ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static void F_46 ( struct V_36 * V_37 , struct V_97 * V_81 )
{
}
static unsigned long F_47 ( struct V_65 * V_66 ,
unsigned long V_132 )
{
struct V_101 * V_133 = V_66 -> V_81 . V_100 ;
T_2 V_17 = V_133 -> V_17 ;
T_2 V_127 = V_132 ;
V_132 = F_48 ( V_127 , V_17 ) ;
V_133 += V_127 ;
return ( V_66 -> V_81 . V_126 . V_128 >> V_89 ) + V_133 -> V_103 + V_132 ;
}
int F_49 ( struct V_134 * V_92 , struct V_135 * * V_136 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
unsigned int V_38 = 0 ;
unsigned V_139 = 0 ;
int V_11 ;
if ( ! ( V_138 -> V_140 & V_141 ) )
V_38 |= V_142 ;
if ( V_138 -> V_140 & V_143 ) {
unsigned long V_144 = V_138 -> V_145 + V_92 -> V_112 * V_115 ;
struct V_146 * V_147 ;
V_147 = F_50 ( V_138 -> V_148 , V_138 -> V_145 ) ;
if ( ! V_147 || V_147 -> V_149 || V_147 -> V_150 < V_144 )
return - V_93 ;
}
do {
unsigned V_112 = V_92 -> V_112 - V_139 ;
T_2 V_145 = V_138 -> V_145 + V_139 * V_115 ;
struct V_135 * * V_151 = V_136 + V_139 ;
struct V_152 V_153 ;
V_153 . V_154 = V_155 ;
F_51 ( & V_138 -> V_156 ) ;
F_52 ( & V_153 . V_157 , & V_138 -> V_158 ) ;
F_53 ( & V_138 -> V_156 ) ;
V_11 = F_54 ( V_145 , V_112 , V_38 , V_151 , NULL ) ;
F_51 ( & V_138 -> V_156 ) ;
F_55 ( & V_153 . V_157 ) ;
F_53 ( & V_138 -> V_156 ) ;
if ( V_11 < 0 )
goto V_159;
V_139 += V_11 ;
} while ( V_139 < V_92 -> V_112 );
return 0 ;
V_159:
V_159 ( V_136 , V_139 , 0 ) ;
return V_11 ;
}
static int F_56 ( struct V_134 * V_92 )
{
struct V_4 * V_5 = F_14 ( V_92 -> V_37 ) ;
struct V_137 * V_138 = ( void * ) V_92 ;
unsigned V_160 ;
int V_11 ;
int V_161 = ! ( V_138 -> V_140 & V_141 ) ;
enum V_162 V_163 = V_161 ?
V_164 : V_165 ;
V_11 = F_57 ( V_92 -> V_166 , V_92 -> V_136 , V_92 -> V_112 , 0 ,
V_92 -> V_112 << V_89 ,
V_167 ) ;
if ( V_11 )
goto V_168;
V_11 = - V_169 ;
V_160 = F_58 ( V_5 -> V_170 , V_92 -> V_166 -> V_171 , V_92 -> V_166 -> V_160 , V_163 ) ;
if ( V_160 != V_92 -> V_166 -> V_160 )
goto V_168;
F_59 ( V_92 -> V_166 , V_92 -> V_136 ,
V_138 -> V_92 . V_172 , V_92 -> V_112 ) ;
return 0 ;
V_168:
F_60 ( V_92 -> V_166 ) ;
return V_11 ;
}
static void F_61 ( struct V_134 * V_92 )
{
struct V_4 * V_5 = F_14 ( V_92 -> V_37 ) ;
struct V_137 * V_138 = ( void * ) V_92 ;
struct V_173 V_174 ;
int V_161 = ! ( V_138 -> V_140 & V_141 ) ;
enum V_162 V_163 = V_161 ?
V_164 : V_165 ;
if ( ! V_92 -> V_166 -> V_171 )
return;
F_62 ( V_5 -> V_170 , V_92 -> V_166 -> V_171 , V_92 -> V_166 -> V_160 , V_163 ) ;
F_63 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_135 * V_135 = F_64 ( & V_174 ) ;
if ( ! ( V_138 -> V_140 & V_141 ) )
F_65 ( V_135 ) ;
F_66 ( V_135 ) ;
F_67 ( V_135 ) ;
}
F_68 ( V_92 -> V_166 ) ;
}
static int F_69 ( struct V_134 * V_92 ,
struct V_97 * V_175 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
int V_11 ;
if ( V_138 -> V_145 ) {
V_11 = F_56 ( V_92 ) ;
if ( V_11 ) {
F_7 ( L_8 ) ;
return V_11 ;
}
}
if ( ! V_92 -> V_112 ) {
F_70 ( 1 , L_9 ,
V_92 -> V_112 , V_175 , V_92 ) ;
}
if ( V_175 -> V_82 == V_60 ||
V_175 -> V_82 == V_61 ||
V_175 -> V_82 == V_62 )
return - V_64 ;
return 0 ;
}
bool F_71 ( struct V_134 * V_92 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
return V_138 && ! F_72 ( & V_138 -> V_157 ) ;
}
int F_25 ( struct V_65 * V_66 , struct V_97 * V_175 )
{
struct V_134 * V_92 = V_66 -> V_92 ;
struct V_137 * V_138 = ( void * ) V_66 -> V_92 ;
T_2 V_38 ;
int V_11 ;
if ( ! V_92 || F_71 ( V_92 ) )
return 0 ;
V_11 = F_73 ( & V_66 -> V_37 -> V_40 [ V_47 ] , V_66 ,
NULL , V_175 ) ;
if ( V_11 ) {
F_7 ( L_10 , V_11 ) ;
return V_11 ;
}
F_51 ( & V_138 -> V_5 -> V_176 ) ;
V_38 = F_74 ( V_138 -> V_5 , V_92 , V_175 ) ;
V_138 -> V_127 = ( V_124 ) V_175 -> V_103 << V_89 ;
V_11 = F_75 ( V_138 -> V_5 , V_138 -> V_127 , V_92 -> V_112 ,
V_92 -> V_136 , V_138 -> V_92 . V_172 , V_38 ) ;
if ( V_11 ) {
F_7 ( L_11 ,
V_92 -> V_112 , V_138 -> V_127 ) ;
goto V_177;
}
F_76 ( & V_138 -> V_157 , & V_138 -> V_5 -> V_178 ) ;
V_177:
F_53 ( & V_138 -> V_5 -> V_176 ) ;
return V_11 ;
}
int F_77 ( struct V_4 * V_5 )
{
struct V_137 * V_138 , * V_179 ;
struct V_97 V_175 ;
T_2 V_38 ;
int V_11 ;
V_175 . V_82 = V_47 ;
F_51 ( & V_5 -> V_176 ) ;
F_78 (gtt, tmp, &adev->gtt_list, list) {
V_38 = F_74 ( V_138 -> V_5 , & V_138 -> V_92 . V_92 , & V_175 ) ;
V_11 = F_75 ( V_5 , V_138 -> V_127 , V_138 -> V_92 . V_92 . V_112 ,
V_138 -> V_92 . V_92 . V_136 , V_138 -> V_92 . V_172 ,
V_38 ) ;
if ( V_11 ) {
F_53 ( & V_5 -> V_176 ) ;
F_7 ( L_11 ,
V_138 -> V_92 . V_92 . V_112 , V_138 -> V_127 ) ;
return V_11 ;
}
}
F_53 ( & V_5 -> V_176 ) ;
return 0 ;
}
static int F_79 ( struct V_134 * V_92 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
int V_11 ;
if ( V_138 -> V_145 )
F_61 ( V_92 ) ;
if ( ! F_71 ( V_92 ) )
return 0 ;
F_51 ( & V_138 -> V_5 -> V_176 ) ;
V_11 = F_80 ( V_138 -> V_5 , V_138 -> V_127 , V_92 -> V_112 ) ;
if ( V_11 ) {
F_7 ( L_12 ,
V_138 -> V_92 . V_92 . V_112 , V_138 -> V_127 ) ;
goto V_180;
}
F_81 ( & V_138 -> V_157 ) ;
V_180:
F_53 ( & V_138 -> V_5 -> V_176 ) ;
return V_11 ;
}
static void F_82 ( struct V_134 * V_92 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
F_83 ( & V_138 -> V_92 ) ;
F_60 ( V_138 ) ;
}
static struct V_134 * F_84 ( struct V_36 * V_37 ,
unsigned long V_17 , T_1 V_181 ,
struct V_135 * V_182 )
{
struct V_4 * V_5 ;
struct V_137 * V_138 ;
V_5 = F_14 ( V_37 ) ;
V_138 = F_85 ( sizeof( struct V_137 ) , V_167 ) ;
if ( V_138 == NULL ) {
return NULL ;
}
V_138 -> V_92 . V_92 . V_48 = & V_183 ;
V_138 -> V_5 = V_5 ;
if ( F_86 ( & V_138 -> V_92 , V_37 , V_17 , V_181 , V_182 ) ) {
F_60 ( V_138 ) ;
return NULL ;
}
F_87 ( & V_138 -> V_157 ) ;
return & V_138 -> V_92 . V_92 ;
}
static int F_88 ( struct V_134 * V_92 )
{
struct V_4 * V_5 ;
struct V_137 * V_138 = ( void * ) V_92 ;
unsigned V_76 ;
int V_11 ;
bool V_184 = ! ! ( V_92 -> V_181 & V_185 ) ;
if ( V_92 -> V_186 != V_187 )
return 0 ;
if ( V_138 && V_138 -> V_145 ) {
V_92 -> V_166 = F_85 ( sizeof( struct V_188 ) , V_167 ) ;
if ( ! V_92 -> V_166 )
return - V_169 ;
V_92 -> V_181 |= V_185 ;
V_92 -> V_186 = V_189 ;
return 0 ;
}
if ( V_184 && V_92 -> V_166 ) {
F_59 ( V_92 -> V_166 , V_92 -> V_136 ,
V_138 -> V_92 . V_172 , V_92 -> V_112 ) ;
V_92 -> V_186 = V_189 ;
return 0 ;
}
V_5 = F_14 ( V_92 -> V_37 ) ;
#ifdef F_89
if ( F_90 () ) {
return F_91 ( & V_138 -> V_92 , V_5 -> V_170 ) ;
}
#endif
V_11 = F_92 ( V_92 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_76 = 0 ; V_76 < V_92 -> V_112 ; V_76 ++ ) {
V_138 -> V_92 . V_172 [ V_76 ] = F_93 ( V_5 -> V_190 , V_92 -> V_136 [ V_76 ] ,
0 , V_115 ,
V_191 ) ;
if ( F_94 ( V_5 -> V_190 , V_138 -> V_92 . V_172 [ V_76 ] ) ) {
while ( V_76 -- ) {
F_95 ( V_5 -> V_190 , V_138 -> V_92 . V_172 [ V_76 ] ,
V_115 , V_191 ) ;
V_138 -> V_92 . V_172 [ V_76 ] = 0 ;
}
F_96 ( V_92 ) ;
return - V_192 ;
}
}
return 0 ;
}
static void F_97 ( struct V_134 * V_92 )
{
struct V_4 * V_5 ;
struct V_137 * V_138 = ( void * ) V_92 ;
unsigned V_76 ;
bool V_184 = ! ! ( V_92 -> V_181 & V_185 ) ;
if ( V_138 && V_138 -> V_145 ) {
F_60 ( V_92 -> V_166 ) ;
V_92 -> V_181 &= ~ V_185 ;
return;
}
if ( V_184 )
return;
V_5 = F_14 ( V_92 -> V_37 ) ;
#ifdef F_89
if ( F_90 () ) {
F_98 ( & V_138 -> V_92 , V_5 -> V_170 ) ;
return;
}
#endif
for ( V_76 = 0 ; V_76 < V_92 -> V_112 ; V_76 ++ ) {
if ( V_138 -> V_92 . V_172 [ V_76 ] ) {
F_95 ( V_5 -> V_190 , V_138 -> V_92 . V_172 [ V_76 ] ,
V_115 , V_191 ) ;
}
}
F_96 ( V_92 ) ;
}
int F_99 ( struct V_134 * V_92 , T_2 V_102 ,
T_1 V_38 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
if ( V_138 == NULL )
return - V_64 ;
V_138 -> V_145 = V_102 ;
V_138 -> V_148 = V_155 -> V_133 ;
V_138 -> V_140 = V_38 ;
F_100 ( & V_138 -> V_156 ) ;
F_87 ( & V_138 -> V_158 ) ;
F_101 ( & V_138 -> V_193 , 0 ) ;
return 0 ;
}
struct V_194 * F_20 ( struct V_134 * V_92 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
if ( V_138 == NULL )
return NULL ;
return V_138 -> V_148 ;
}
bool F_102 ( struct V_134 * V_92 , unsigned long V_103 ,
unsigned long V_144 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
struct V_152 * V_195 ;
unsigned long V_17 ;
if ( V_138 == NULL || ! V_138 -> V_145 )
return false ;
V_17 = ( unsigned long ) V_138 -> V_92 . V_92 . V_112 * V_115 ;
if ( V_138 -> V_145 > V_144 || V_138 -> V_145 + V_17 <= V_103 )
return false ;
F_51 ( & V_138 -> V_156 ) ;
F_103 (entry, &gtt->guptasks, list) {
if ( V_195 -> V_154 == V_155 ) {
F_53 ( & V_138 -> V_156 ) ;
return false ;
}
}
F_53 ( & V_138 -> V_156 ) ;
F_104 ( & V_138 -> V_193 ) ;
return true ;
}
bool F_105 ( struct V_134 * V_92 ,
int * V_196 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
int V_197 = * V_196 ;
* V_196 = F_106 ( & V_138 -> V_193 ) ;
return V_197 != * V_196 ;
}
bool F_107 ( struct V_134 * V_92 )
{
struct V_137 * V_138 = ( void * ) V_92 ;
if ( V_138 == NULL )
return false ;
return ! ! ( V_138 -> V_140 & V_141 ) ;
}
T_2 F_74 ( struct V_4 * V_5 , struct V_134 * V_92 ,
struct V_97 * V_81 )
{
T_2 V_38 = 0 ;
if ( V_81 && V_81 -> V_82 != V_41 )
V_38 |= V_198 ;
if ( V_81 && V_81 -> V_82 == V_47 ) {
V_38 |= V_199 ;
if ( V_92 -> V_200 == V_201 )
V_38 |= V_202 ;
}
V_38 |= V_5 -> V_203 . V_204 ;
V_38 |= V_205 ;
if ( ! F_107 ( V_92 ) )
V_38 |= V_206 ;
return V_38 ;
}
static bool F_108 ( struct V_65 * V_66 ,
const struct V_71 * V_207 )
{
unsigned long V_112 = V_66 -> V_81 . V_112 ;
struct V_101 * V_208 = V_66 -> V_81 . V_100 ;
if ( V_66 -> V_81 . V_103 != V_209 )
return F_109 ( V_66 , V_207 ) ;
switch ( V_66 -> V_81 . V_82 ) {
case V_47 :
return true ;
case V_54 :
while ( V_112 ) {
if ( V_207 -> V_73 < ( V_208 -> V_103 + V_208 -> V_17 ) &&
! ( V_207 -> V_74 && V_207 -> V_74 <= V_208 -> V_103 ) )
return true ;
V_112 -= V_208 -> V_17 ;
++ V_208 ;
}
break;
default:
break;
}
return F_109 ( V_66 , V_207 ) ;
}
int F_110 ( struct V_4 * V_5 )
{
int V_11 ;
V_11 = F_5 ( V_5 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_111 ( & V_5 -> V_12 . V_37 ,
V_5 -> V_12 . V_22 . V_2 . V_3 ,
& V_210 ,
V_5 -> V_211 -> V_212 -> V_213 ,
V_214 ,
V_5 -> V_215 ) ;
if ( V_11 ) {
F_7 ( L_13 , V_11 ) ;
return V_11 ;
}
V_5 -> V_12 . V_216 = true ;
V_11 = F_112 ( & V_5 -> V_12 . V_37 , V_54 ,
V_5 -> V_51 . V_217 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_14 ) ;
return V_11 ;
}
F_113 ( V_5 , V_5 -> V_51 . V_130 ) ;
V_11 = F_114 ( V_5 , V_5 -> V_51 . V_218 , V_115 , true ,
V_219 ,
V_220 |
V_221 ,
NULL , NULL , & V_5 -> V_222 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_115 ( V_5 -> V_222 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_116 ( V_5 -> V_222 , V_219 , NULL ) ;
F_117 ( V_5 -> V_222 ) ;
if ( V_11 ) {
F_118 ( & V_5 -> V_222 ) ;
return V_11 ;
}
F_119 ( L_15 ,
( unsigned ) ( V_5 -> V_51 . V_217 / ( 1024 * 1024 ) ) ) ;
V_11 = F_112 ( & V_5 -> V_12 . V_37 , V_47 ,
V_5 -> V_51 . V_88 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_16 ) ;
return V_11 ;
}
F_119 ( L_17 ,
( unsigned ) ( V_5 -> V_51 . V_88 / ( 1024 * 1024 ) ) ) ;
V_5 -> V_223 . V_81 . V_224 = V_5 -> V_223 . V_81 . V_224 << V_225 ;
V_5 -> V_223 . V_81 . V_226 = V_5 -> V_223 . V_81 . V_226 << V_225 ;
V_5 -> V_223 . V_81 . V_227 = V_5 -> V_223 . V_81 . V_227 << V_225 ;
V_5 -> V_223 . V_228 . V_224 = V_5 -> V_223 . V_228 . V_224 << V_229 ;
V_5 -> V_223 . V_228 . V_226 = V_5 -> V_223 . V_228 . V_226 << V_229 ;
V_5 -> V_223 . V_228 . V_227 = V_5 -> V_223 . V_228 . V_227 << V_229 ;
V_5 -> V_223 . V_230 . V_224 = V_5 -> V_223 . V_230 . V_224 << V_231 ;
V_5 -> V_223 . V_230 . V_226 = V_5 -> V_223 . V_230 . V_226 << V_231 ;
V_5 -> V_223 . V_230 . V_227 = V_5 -> V_223 . V_230 . V_227 << V_231 ;
if ( V_5 -> V_223 . V_81 . V_224 ) {
V_11 = F_112 ( & V_5 -> V_12 . V_37 , V_60 ,
V_5 -> V_223 . V_81 . V_224 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_18 ) ;
return V_11 ;
}
}
if ( V_5 -> V_223 . V_228 . V_224 ) {
V_11 = F_112 ( & V_5 -> V_12 . V_37 , V_61 ,
V_5 -> V_223 . V_228 . V_224 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_19 ) ;
return V_11 ;
}
}
if ( V_5 -> V_223 . V_230 . V_224 ) {
V_11 = F_112 ( & V_5 -> V_12 . V_37 , V_62 ,
V_5 -> V_223 . V_230 . V_224 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_20 ) ;
return V_11 ;
}
}
V_11 = F_120 ( V_5 ) ;
if ( V_11 ) {
F_7 ( L_21 ) ;
return V_11 ;
}
return 0 ;
}
void F_121 ( struct V_4 * V_5 )
{
int V_11 ;
if ( ! V_5 -> V_12 . V_216 )
return;
F_122 ( V_5 ) ;
if ( V_5 -> V_222 ) {
V_11 = F_115 ( V_5 -> V_222 , true ) ;
if ( V_11 == 0 ) {
F_123 ( V_5 -> V_222 ) ;
F_117 ( V_5 -> V_222 ) ;
}
F_118 ( & V_5 -> V_222 ) ;
}
F_124 ( & V_5 -> V_12 . V_37 , V_54 ) ;
F_124 ( & V_5 -> V_12 . V_37 , V_47 ) ;
if ( V_5 -> V_223 . V_81 . V_224 )
F_124 ( & V_5 -> V_12 . V_37 , V_60 ) ;
if ( V_5 -> V_223 . V_228 . V_224 )
F_124 ( & V_5 -> V_12 . V_37 , V_61 ) ;
if ( V_5 -> V_223 . V_230 . V_224 )
F_124 ( & V_5 -> V_12 . V_37 , V_62 ) ;
F_125 ( & V_5 -> V_12 . V_37 ) ;
F_126 ( V_5 ) ;
F_10 ( V_5 ) ;
V_5 -> V_12 . V_216 = false ;
F_119 ( L_22 ) ;
}
void F_113 ( struct V_4 * V_5 , V_124 V_17 )
{
struct V_39 * V_40 ;
if ( ! V_5 -> V_12 . V_216 )
return;
V_40 = & V_5 -> V_12 . V_37 . V_40 [ V_54 ] ;
V_40 -> V_17 = V_17 >> V_89 ;
}
int F_127 ( struct V_90 * V_91 , struct V_146 * V_147 )
{
struct V_232 * V_233 ;
struct V_4 * V_5 ;
if ( F_35 ( V_147 -> V_234 < V_214 ) )
return - V_64 ;
V_233 = V_91 -> V_96 ;
V_5 = V_233 -> V_235 -> V_170 -> V_236 ;
if ( V_5 == NULL )
return - V_64 ;
return F_128 ( V_91 , V_147 , & V_5 -> V_12 . V_37 ) ;
}
int F_29 ( struct V_7 * V_8 ,
T_2 V_237 ,
T_2 V_238 ,
T_1 V_239 ,
struct V_240 * V_119 ,
struct V_113 * * V_114 , bool V_241 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_242 * V_243 ;
T_1 V_244 ;
unsigned V_245 , V_246 ;
unsigned V_76 ;
int V_11 ;
V_244 = V_5 -> V_12 . V_83 -> V_247 ;
V_245 = F_129 ( V_239 , V_244 ) ;
V_246 = V_245 * V_5 -> V_12 . V_83 -> V_248 ;
while ( V_246 & 0x7 )
V_246 ++ ;
V_11 = F_130 ( V_5 , V_246 * 4 , & V_243 ) ;
if ( V_11 )
return V_11 ;
if ( V_119 ) {
V_11 = F_131 ( V_5 , & V_243 -> V_249 , V_119 ,
V_250 ) ;
if ( V_11 ) {
F_7 ( L_23 , V_11 ) ;
goto V_251;
}
}
for ( V_76 = 0 ; V_76 < V_245 ; V_76 ++ ) {
T_1 V_252 = F_28 ( V_239 , V_244 ) ;
F_132 ( V_5 , & V_243 -> V_253 [ 0 ] , V_237 ,
V_238 , V_252 ) ;
V_237 += V_252 ;
V_238 += V_252 ;
V_239 -= V_252 ;
}
F_133 ( V_8 , & V_243 -> V_253 [ 0 ] ) ;
F_134 ( V_243 -> V_253 [ 0 ] . V_254 > V_246 ) ;
if ( V_241 ) {
V_11 = F_135 ( V_8 , V_243 -> V_255 , V_243 -> V_253 ,
NULL , V_114 ) ;
V_243 -> V_114 = F_136 ( * V_114 ) ;
if ( V_11 )
F_7 ( L_24 , V_11 ) ;
F_137 ( V_243 ) ;
} else {
V_11 = F_138 ( V_243 , V_8 , & V_5 -> V_12 . V_33 ,
V_250 , V_114 ) ;
if ( V_11 )
goto V_251;
}
return V_11 ;
V_251:
F_137 ( V_243 ) ;
return V_11 ;
}
int F_139 ( struct V_69 * V_66 ,
T_1 V_256 ,
struct V_240 * V_119 ,
struct V_113 * * V_114 )
{
struct V_4 * V_5 = F_14 ( V_66 -> V_80 . V_37 ) ;
T_1 V_244 = V_5 -> V_12 . V_83 -> V_257 ;
struct V_7 * V_8 = V_5 -> V_12 . V_29 ;
struct V_101 * V_100 ;
unsigned long V_112 ;
unsigned int V_245 , V_246 ;
struct V_242 * V_243 ;
int V_11 ;
if ( ! V_8 -> V_84 ) {
F_7 ( L_25 ) ;
return - V_64 ;
}
V_112 = V_66 -> V_80 . V_112 ;
V_100 = V_66 -> V_80 . V_81 . V_100 ;
V_245 = 0 ;
while ( V_112 ) {
T_1 V_239 = V_100 -> V_17 << V_89 ;
V_245 += F_129 ( V_239 , V_244 ) ;
V_112 -= V_100 -> V_17 ;
++ V_100 ;
}
V_246 = V_245 * V_5 -> V_12 . V_83 -> V_258 ;
V_246 += 64 ;
V_11 = F_130 ( V_5 , V_246 * 4 , & V_243 ) ;
if ( V_11 )
return V_11 ;
if ( V_119 ) {
V_11 = F_131 ( V_5 , & V_243 -> V_249 , V_119 ,
V_250 ) ;
if ( V_11 ) {
F_7 ( L_23 , V_11 ) ;
goto V_251;
}
}
V_112 = V_66 -> V_80 . V_112 ;
V_100 = V_66 -> V_80 . V_81 . V_100 ;
while ( V_112 ) {
T_1 V_239 = V_100 -> V_17 << V_89 ;
T_2 V_259 ;
V_11 = F_24 ( & V_66 -> V_80 , V_100 ,
& V_66 -> V_80 . V_81 , & V_259 ) ;
if ( V_11 )
return V_11 ;
while ( V_239 ) {
T_1 V_252 = F_28 ( V_239 , V_244 ) ;
F_140 ( V_5 , & V_243 -> V_253 [ 0 ] , V_256 ,
V_259 , V_252 ) ;
V_259 += V_252 ;
V_239 -= V_252 ;
}
V_112 -= V_100 -> V_17 ;
++ V_100 ;
}
F_133 ( V_8 , & V_243 -> V_253 [ 0 ] ) ;
F_134 ( V_243 -> V_253 [ 0 ] . V_254 > V_246 ) ;
V_11 = F_138 ( V_243 , V_8 , & V_5 -> V_12 . V_33 ,
V_250 , V_114 ) ;
if ( V_11 )
goto V_251;
return 0 ;
V_251:
F_137 ( V_243 ) ;
return V_11 ;
}
static int F_141 ( struct V_260 * V_261 , void * V_262 )
{
struct V_263 * V_208 = (struct V_263 * ) V_261 -> V_264 ;
unsigned V_265 = * ( int * ) V_208 -> V_266 -> V_262 ;
struct V_267 * V_170 = V_208 -> V_235 -> V_170 ;
struct V_4 * V_5 = V_170 -> V_236 ;
struct V_268 * V_133 = (struct V_268 * ) V_5 -> V_12 . V_37 . V_40 [ V_265 ] . V_269 ;
struct V_25 * V_270 = V_5 -> V_12 . V_37 . V_270 ;
struct V_271 V_151 = F_142 ( V_261 ) ;
F_51 ( & V_270 -> V_272 ) ;
F_143 ( V_133 , & V_151 ) ;
F_53 ( & V_270 -> V_272 ) ;
switch ( V_265 ) {
case V_54 :
F_144 ( V_261 , L_26 ,
V_5 -> V_12 . V_37 . V_40 [ V_265 ] . V_17 ,
( V_124 ) F_145 ( & V_5 -> V_273 ) >> 20 ,
( V_124 ) F_145 ( & V_5 -> V_274 ) >> 20 ) ;
break;
case V_47 :
F_146 ( V_261 , & V_5 -> V_12 . V_37 . V_40 [ V_47 ] ) ;
break;
}
return 0 ;
}
static T_3 F_147 ( struct V_90 * V_275 , char T_4 * V_276 ,
T_5 V_17 , T_6 * V_277 )
{
struct V_4 * V_5 = F_148 ( V_275 ) -> V_278 ;
T_3 V_279 = 0 ;
int V_11 ;
if ( V_17 & 0x3 || * V_277 & 0x3 )
return - V_64 ;
if ( * V_277 >= V_5 -> V_51 . V_280 )
return - V_281 ;
while ( V_17 ) {
unsigned long V_38 ;
T_1 V_282 ;
if ( * V_277 >= V_5 -> V_51 . V_280 )
return V_279 ;
F_149 ( & V_5 -> V_283 , V_38 ) ;
F_150 ( V_284 , ( ( T_1 ) * V_277 ) | 0x80000000 ) ;
F_150 ( V_285 , * V_277 >> 31 ) ;
V_282 = F_151 ( V_286 ) ;
F_152 ( & V_5 -> V_283 , V_38 ) ;
V_11 = F_153 ( V_282 , ( T_1 * ) V_276 ) ;
if ( V_11 )
return V_11 ;
V_279 += 4 ;
V_276 += 4 ;
* V_277 += 4 ;
V_17 -= 4 ;
}
return V_279 ;
}
static T_3 F_154 ( struct V_90 * V_275 , char T_4 * V_276 ,
T_5 V_17 , T_6 * V_277 )
{
struct V_4 * V_5 = F_148 ( V_275 ) -> V_278 ;
T_3 V_279 = 0 ;
int V_11 ;
while ( V_17 ) {
T_6 V_151 = * V_277 / V_115 ;
unsigned V_287 = * V_277 & ~ V_288 ;
T_5 V_289 = F_155 ( T_5 , V_17 , V_115 - V_287 ) ;
struct V_135 * V_135 ;
void * V_290 ;
if ( V_151 >= V_5 -> V_203 . V_291 )
return V_279 ;
V_135 = V_5 -> V_203 . V_136 [ V_151 ] ;
if ( V_135 ) {
V_290 = F_156 ( V_135 ) ;
V_290 += V_287 ;
V_11 = F_157 ( V_276 , V_290 , V_289 ) ;
F_158 ( V_5 -> V_203 . V_136 [ V_151 ] ) ;
} else
V_11 = F_159 ( V_276 , V_289 ) ;
if ( V_11 )
return - V_192 ;
V_279 += V_289 ;
V_276 += V_289 ;
* V_277 += V_289 ;
V_17 -= V_289 ;
}
return V_279 ;
}
static int F_120 ( struct V_4 * V_5 )
{
#if F_160 ( V_292 )
unsigned V_293 ;
struct V_294 * V_235 = V_5 -> V_211 -> V_295 ;
struct V_296 * V_297 , * V_298 = V_235 -> V_299 ;
V_297 = F_161 ( L_27 , V_300 | V_301 , V_298 ,
V_5 , & V_302 ) ;
if ( F_162 ( V_297 ) )
return F_163 ( V_297 ) ;
F_164 ( V_297 -> V_303 , V_5 -> V_51 . V_280 ) ;
V_5 -> V_12 . V_304 = V_297 ;
#ifdef F_165
V_297 = F_161 ( L_28 , V_300 | V_301 , V_298 ,
V_5 , & V_305 ) ;
if ( F_162 ( V_297 ) )
return F_163 ( V_297 ) ;
F_164 ( V_297 -> V_303 , V_5 -> V_51 . V_88 ) ;
V_5 -> V_12 . V_138 = V_297 ;
#endif
V_293 = F_166 ( V_306 ) ;
#ifdef F_89
if ( ! F_90 () )
-- V_293 ;
#endif
return F_167 ( V_5 , V_306 , V_293 ) ;
#else
return 0 ;
#endif
}
static void F_122 ( struct V_4 * V_5 )
{
#if F_160 ( V_292 )
F_168 ( V_5 -> V_12 . V_304 ) ;
V_5 -> V_12 . V_304 = NULL ;
#ifdef F_165
F_168 ( V_5 -> V_12 . V_138 ) ;
V_5 -> V_12 . V_138 = NULL ;
#endif
#endif
}
