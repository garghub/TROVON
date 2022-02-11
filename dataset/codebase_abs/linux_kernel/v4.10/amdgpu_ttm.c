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
if ( V_5 -> V_12 . V_29 -> V_83 == false ) {
F_18 ( V_70 , V_84 ) ;
} else {
F_18 ( V_70 , V_85 ) ;
for ( V_76 = 0 ; V_76 < V_70 -> V_68 . V_78 ; ++ V_76 ) {
if ( ! ( V_70 -> V_72 [ V_76 ] . V_38 &
V_86 ) )
continue;
if ( V_70 -> V_72 [ V_76 ] . V_74 )
continue;
V_70 -> V_72 [ V_76 ] . V_74 =
V_5 -> V_51 . V_87 >> V_88 ;
}
}
break;
case V_47 :
default:
F_18 ( V_70 , V_84 ) ;
}
* V_68 = V_70 -> V_68 ;
}
static int F_19 ( struct V_65 * V_66 , struct V_89 * V_90 )
{
struct V_69 * V_70 = F_17 ( V_66 , struct V_69 , V_80 ) ;
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
struct V_100 * V_99 ,
struct V_96 * V_81 ,
T_2 * V_101 )
{
int V_11 ;
switch ( V_81 -> V_82 ) {
case V_47 :
V_11 = F_25 ( V_66 , V_81 ) ;
if ( V_11 )
return V_11 ;
case V_54 :
* V_101 = V_99 -> V_102 << V_88 ;
* V_101 += V_66 -> V_37 -> V_40 [ V_81 -> V_82 ] . V_50 ;
break;
default:
F_7 ( L_6 , V_81 -> V_82 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_26 ( struct V_65 * V_66 ,
bool V_103 , bool V_104 ,
struct V_96 * V_97 ,
struct V_96 * V_98 )
{
struct V_4 * V_5 = F_14 ( V_66 -> V_37 ) ;
struct V_7 * V_8 = V_5 -> V_12 . V_29 ;
struct V_100 * V_105 , * V_106 ;
T_2 V_107 , V_108 , V_109 , V_110 ;
unsigned long V_111 ;
struct V_112 * V_113 = NULL ;
int V_11 ;
F_27 ( ( V_114 % V_115 ) != 0 ) ;
if ( ! V_8 -> V_83 ) {
F_7 ( L_7 ) ;
return - V_64 ;
}
V_105 = V_98 -> V_99 ;
V_11 = F_24 ( V_66 , V_105 , V_98 , & V_107 ) ;
if ( V_11 )
return V_11 ;
V_108 = V_105 -> V_17 ;
V_106 = V_97 -> V_99 ;
V_11 = F_24 ( V_66 , V_106 , V_97 , & V_109 ) ;
if ( V_11 )
return V_11 ;
V_110 = V_106 -> V_17 ;
V_111 = V_97 -> V_111 ;
while ( V_111 ) {
unsigned long V_116 = F_28 ( V_108 , V_110 ) ;
struct V_112 * V_117 ;
V_11 = F_29 ( V_8 , V_107 , V_109 ,
V_116 * V_114 ,
V_66 -> V_118 , & V_117 , false ) ;
if ( V_11 )
goto error;
F_30 ( V_113 ) ;
V_113 = V_117 ;
V_111 -= V_116 ;
if ( ! V_111 )
break;
V_108 -= V_116 ;
if ( ! V_108 ) {
V_11 = F_24 ( V_66 , ++ V_105 , V_98 ,
& V_107 ) ;
if ( V_11 )
goto error;
V_108 = V_105 -> V_17 ;
} else {
V_107 += V_116 * V_114 ;
}
V_110 -= V_116 ;
if ( ! V_110 ) {
V_11 = F_24 ( V_66 , ++ V_106 , V_97 ,
& V_109 ) ;
if ( V_11 )
goto error;
V_110 = V_106 -> V_17 ;
} else {
V_109 += V_116 * V_114 ;
}
}
V_11 = F_31 ( V_66 , V_113 , V_103 , V_97 ) ;
F_30 ( V_113 ) ;
return V_11 ;
error:
if ( V_113 )
F_32 ( V_113 , false ) ;
F_30 ( V_113 ) ;
return V_11 ;
}
static int F_33 ( struct V_65 * V_66 ,
bool V_103 , bool V_119 ,
bool V_104 ,
struct V_96 * V_97 )
{
struct V_4 * V_5 ;
struct V_96 * V_98 = & V_66 -> V_81 ;
struct V_96 V_120 ;
struct V_71 V_72 ;
struct V_67 V_68 ;
int V_11 ;
V_5 = F_14 ( V_66 -> V_37 ) ;
V_120 = * V_97 ;
V_120 . V_99 = NULL ;
V_68 . V_78 = 1 ;
V_68 . V_68 = & V_72 ;
V_68 . V_79 = 1 ;
V_68 . V_77 = & V_72 ;
V_72 . V_73 = 0 ;
V_72 . V_74 = V_5 -> V_51 . V_87 >> V_88 ;
V_72 . V_38 = V_44 | V_86 ;
V_11 = F_34 ( V_66 , & V_68 , & V_120 ,
V_119 , V_104 ) ;
if ( F_35 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_36 ( V_66 -> V_91 , V_120 . V_68 ) ;
if ( F_35 ( V_11 ) ) {
goto V_121;
}
V_11 = F_37 ( V_66 -> V_91 , & V_120 ) ;
if ( F_35 ( V_11 ) ) {
goto V_121;
}
V_11 = F_26 ( V_66 , true , V_104 , & V_120 , V_98 ) ;
if ( F_35 ( V_11 ) ) {
goto V_121;
}
V_11 = F_38 ( V_66 , V_119 , V_104 , V_97 ) ;
V_121:
F_39 ( V_66 , & V_120 ) ;
return V_11 ;
}
static int F_40 ( struct V_65 * V_66 ,
bool V_103 , bool V_119 ,
bool V_104 ,
struct V_96 * V_97 )
{
struct V_4 * V_5 ;
struct V_96 * V_98 = & V_66 -> V_81 ;
struct V_96 V_120 ;
struct V_67 V_68 ;
struct V_71 V_72 ;
int V_11 ;
V_5 = F_14 ( V_66 -> V_37 ) ;
V_120 = * V_97 ;
V_120 . V_99 = NULL ;
V_68 . V_78 = 1 ;
V_68 . V_68 = & V_72 ;
V_68 . V_79 = 1 ;
V_68 . V_77 = & V_72 ;
V_72 . V_73 = 0 ;
V_72 . V_74 = V_5 -> V_51 . V_87 >> V_88 ;
V_72 . V_38 = V_44 | V_86 ;
V_11 = F_34 ( V_66 , & V_68 , & V_120 ,
V_119 , V_104 ) ;
if ( F_35 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_38 ( V_66 , V_119 , V_104 , & V_120 ) ;
if ( F_35 ( V_11 ) ) {
goto V_121;
}
V_11 = F_26 ( V_66 , true , V_104 , V_97 , V_98 ) ;
if ( F_35 ( V_11 ) ) {
goto V_121;
}
V_121:
F_39 ( V_66 , & V_120 ) ;
return V_11 ;
}
static int F_41 ( struct V_65 * V_66 ,
bool V_103 , bool V_119 ,
bool V_104 ,
struct V_96 * V_97 )
{
struct V_4 * V_5 ;
struct V_69 * V_70 ;
struct V_96 * V_98 = & V_66 -> V_81 ;
int V_11 ;
V_70 = F_17 ( V_66 , struct V_69 , V_80 ) ;
if ( F_42 ( V_70 -> V_122 > 0 ) )
return - V_64 ;
V_5 = F_14 ( V_66 -> V_37 ) ;
if ( V_103 )
F_43 ( & V_5 -> V_123 ) ;
if ( V_98 -> V_82 == V_41 && V_66 -> V_91 == NULL ) {
F_22 ( V_66 , V_97 ) ;
return 0 ;
}
if ( ( V_98 -> V_82 == V_47 &&
V_97 -> V_82 == V_41 ) ||
( V_98 -> V_82 == V_41 &&
V_97 -> V_82 == V_47 ) ) {
F_22 ( V_66 , V_97 ) ;
return 0 ;
}
if ( V_5 -> V_12 . V_124 == NULL ||
V_5 -> V_12 . V_29 == NULL ||
! V_5 -> V_12 . V_29 -> V_83 ) {
goto memcpy;
}
if ( V_98 -> V_82 == V_54 &&
V_97 -> V_82 == V_41 ) {
V_11 = F_33 ( V_66 , V_103 , V_119 ,
V_104 , V_97 ) ;
} else if ( V_98 -> V_82 == V_41 &&
V_97 -> V_82 == V_54 ) {
V_11 = F_40 ( V_66 , V_103 , V_119 ,
V_104 , V_97 ) ;
} else {
V_11 = F_26 ( V_66 , V_103 , V_104 , V_97 , V_98 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_44 ( V_66 , V_119 , V_104 , V_97 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_45 ( ( V_125 ) V_66 -> V_111 << V_88 , & V_5 -> V_126 ) ;
return 0 ;
}
static int F_46 ( struct V_36 * V_37 , struct V_96 * V_81 )
{
struct V_39 * V_40 = & V_37 -> V_40 [ V_81 -> V_82 ] ;
struct V_4 * V_5 = F_14 ( V_37 ) ;
V_81 -> V_127 . V_101 = NULL ;
V_81 -> V_127 . V_128 = 0 ;
V_81 -> V_127 . V_17 = V_81 -> V_111 << V_88 ;
V_81 -> V_127 . V_129 = 0 ;
V_81 -> V_127 . V_130 = false ;
if ( ! ( V_40 -> V_38 & V_42 ) )
return - V_64 ;
switch ( V_81 -> V_82 ) {
case V_41 :
return 0 ;
case V_47 :
break;
case V_54 :
V_81 -> V_127 . V_128 = V_81 -> V_102 << V_88 ;
if ( ( V_81 -> V_127 . V_128 + V_81 -> V_127 . V_17 ) > V_5 -> V_51 . V_131 )
return - V_64 ;
V_81 -> V_127 . V_129 = V_5 -> V_51 . V_132 ;
V_81 -> V_127 . V_130 = true ;
#ifdef F_47
if ( V_81 -> V_68 & V_59 )
V_81 -> V_127 . V_101 =
F_48 ( V_81 -> V_127 . V_129 + V_81 -> V_127 . V_128 ,
V_81 -> V_127 . V_17 ) ;
else
V_81 -> V_127 . V_101 =
F_49 ( V_81 -> V_127 . V_129 + V_81 -> V_127 . V_128 ,
V_81 -> V_127 . V_17 ) ;
V_81 -> V_127 . V_129 = ( V_81 -> V_127 . V_129 & 0x0ffffffffUL ) +
V_5 -> V_133 -> V_134 -> V_135 ;
#endif
break;
default:
return - V_64 ;
}
return 0 ;
}
static void F_50 ( struct V_36 * V_37 , struct V_96 * V_81 )
{
}
int F_51 ( struct V_136 * V_91 , struct V_137 * * V_138 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
unsigned int V_38 = 0 ;
unsigned V_141 = 0 ;
int V_11 ;
if ( ! ( V_140 -> V_142 & V_143 ) )
V_38 |= V_144 ;
if ( V_140 -> V_142 & V_145 ) {
unsigned long V_146 = V_140 -> V_147 + V_91 -> V_111 * V_114 ;
struct V_148 * V_149 ;
V_149 = F_52 ( V_140 -> V_150 , V_140 -> V_147 ) ;
if ( ! V_149 || V_149 -> V_151 || V_149 -> V_152 < V_146 )
return - V_92 ;
}
do {
unsigned V_111 = V_91 -> V_111 - V_141 ;
T_2 V_147 = V_140 -> V_147 + V_141 * V_114 ;
struct V_137 * * V_153 = V_138 + V_141 ;
struct V_154 V_155 ;
V_155 . V_156 = V_157 ;
F_53 ( & V_140 -> V_158 ) ;
F_54 ( & V_155 . V_159 , & V_140 -> V_160 ) ;
F_55 ( & V_140 -> V_158 ) ;
V_11 = F_56 ( V_147 , V_111 , V_38 , V_153 , NULL ) ;
F_53 ( & V_140 -> V_158 ) ;
F_57 ( & V_155 . V_159 ) ;
F_55 ( & V_140 -> V_158 ) ;
if ( V_11 < 0 )
goto V_161;
V_141 += V_11 ;
} while ( V_141 < V_91 -> V_111 );
return 0 ;
V_161:
V_161 ( V_138 , V_141 , 0 ) ;
return V_11 ;
}
static int F_58 ( struct V_136 * V_91 )
{
struct V_4 * V_5 = F_14 ( V_91 -> V_37 ) ;
struct V_139 * V_140 = ( void * ) V_91 ;
unsigned V_162 ;
int V_11 ;
int V_163 = ! ( V_140 -> V_142 & V_143 ) ;
enum V_164 V_165 = V_163 ?
V_166 : V_167 ;
V_11 = F_59 ( V_91 -> V_168 , V_91 -> V_138 , V_91 -> V_111 , 0 ,
V_91 -> V_111 << V_88 ,
V_169 ) ;
if ( V_11 )
goto V_170;
V_11 = - V_171 ;
V_162 = F_60 ( V_5 -> V_172 , V_91 -> V_168 -> V_173 , V_91 -> V_168 -> V_162 , V_165 ) ;
if ( V_162 != V_91 -> V_168 -> V_162 )
goto V_170;
F_61 ( V_91 -> V_168 , V_91 -> V_138 ,
V_140 -> V_91 . V_174 , V_91 -> V_111 ) ;
return 0 ;
V_170:
F_62 ( V_91 -> V_168 ) ;
return V_11 ;
}
static void F_63 ( struct V_136 * V_91 )
{
struct V_4 * V_5 = F_14 ( V_91 -> V_37 ) ;
struct V_139 * V_140 = ( void * ) V_91 ;
struct V_175 V_176 ;
int V_163 = ! ( V_140 -> V_142 & V_143 ) ;
enum V_164 V_165 = V_163 ?
V_166 : V_167 ;
if ( ! V_91 -> V_168 -> V_173 )
return;
F_64 ( V_5 -> V_172 , V_91 -> V_168 -> V_173 , V_91 -> V_168 -> V_162 , V_165 ) ;
F_65 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_137 * V_137 = F_66 ( & V_176 ) ;
if ( ! ( V_140 -> V_142 & V_143 ) )
F_67 ( V_137 ) ;
F_68 ( V_137 ) ;
F_69 ( V_137 ) ;
}
F_70 ( V_91 -> V_168 ) ;
}
static int F_71 ( struct V_136 * V_91 ,
struct V_96 * V_177 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
int V_11 ;
if ( V_140 -> V_147 ) {
V_11 = F_58 ( V_91 ) ;
if ( V_11 ) {
F_7 ( L_8 ) ;
return V_11 ;
}
}
if ( ! V_91 -> V_111 ) {
F_72 ( 1 , L_9 ,
V_91 -> V_111 , V_177 , V_91 ) ;
}
if ( V_177 -> V_82 == V_60 ||
V_177 -> V_82 == V_61 ||
V_177 -> V_82 == V_62 )
return - V_64 ;
return 0 ;
}
bool F_73 ( struct V_136 * V_91 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
return V_140 && ! F_74 ( & V_140 -> V_159 ) ;
}
int F_25 ( struct V_65 * V_66 , struct V_96 * V_177 )
{
struct V_136 * V_91 = V_66 -> V_91 ;
struct V_139 * V_140 = ( void * ) V_66 -> V_91 ;
T_1 V_38 ;
int V_11 ;
if ( ! V_91 || F_73 ( V_91 ) )
return 0 ;
V_11 = F_75 ( & V_66 -> V_37 -> V_40 [ V_47 ] , V_66 ,
NULL , V_177 ) ;
if ( V_11 ) {
F_7 ( L_10 , V_11 ) ;
return V_11 ;
}
V_38 = F_76 ( V_140 -> V_5 , V_91 , V_177 ) ;
V_140 -> V_128 = ( V_125 ) V_177 -> V_102 << V_88 ;
V_11 = F_77 ( V_140 -> V_5 , V_140 -> V_128 , V_91 -> V_111 ,
V_91 -> V_138 , V_140 -> V_91 . V_174 , V_38 ) ;
if ( V_11 ) {
F_7 ( L_11 ,
V_91 -> V_111 , V_140 -> V_128 ) ;
return V_11 ;
}
F_53 ( & V_140 -> V_5 -> V_178 ) ;
F_78 ( & V_140 -> V_159 , & V_140 -> V_5 -> V_179 ) ;
F_55 ( & V_140 -> V_5 -> V_178 ) ;
return 0 ;
}
int F_79 ( struct V_4 * V_5 )
{
struct V_139 * V_140 , * V_180 ;
struct V_96 V_177 ;
T_1 V_38 ;
int V_11 ;
V_177 . V_82 = V_47 ;
F_53 ( & V_5 -> V_178 ) ;
F_80 (gtt, tmp, &adev->gtt_list, list) {
V_38 = F_76 ( V_140 -> V_5 , & V_140 -> V_91 . V_91 , & V_177 ) ;
V_11 = F_77 ( V_5 , V_140 -> V_128 , V_140 -> V_91 . V_91 . V_111 ,
V_140 -> V_91 . V_91 . V_138 , V_140 -> V_91 . V_174 ,
V_38 ) ;
if ( V_11 ) {
F_55 ( & V_5 -> V_178 ) ;
F_7 ( L_11 ,
V_140 -> V_91 . V_91 . V_111 , V_140 -> V_128 ) ;
return V_11 ;
}
}
F_55 ( & V_5 -> V_178 ) ;
return 0 ;
}
static int F_81 ( struct V_136 * V_91 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
if ( V_140 -> V_147 )
F_63 ( V_91 ) ;
if ( ! F_73 ( V_91 ) )
return 0 ;
if ( V_140 -> V_5 -> V_181 . V_83 )
F_82 ( V_140 -> V_5 , V_140 -> V_128 , V_91 -> V_111 ) ;
F_53 ( & V_140 -> V_5 -> V_178 ) ;
F_83 ( & V_140 -> V_159 ) ;
F_55 ( & V_140 -> V_5 -> V_178 ) ;
return 0 ;
}
static void F_84 ( struct V_136 * V_91 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
F_85 ( & V_140 -> V_91 ) ;
F_62 ( V_140 ) ;
}
static struct V_136 * F_86 ( struct V_36 * V_37 ,
unsigned long V_17 , T_1 V_182 ,
struct V_137 * V_183 )
{
struct V_4 * V_5 ;
struct V_139 * V_140 ;
V_5 = F_14 ( V_37 ) ;
V_140 = F_87 ( sizeof( struct V_139 ) , V_169 ) ;
if ( V_140 == NULL ) {
return NULL ;
}
V_140 -> V_91 . V_91 . V_48 = & V_184 ;
V_140 -> V_5 = V_5 ;
if ( F_88 ( & V_140 -> V_91 , V_37 , V_17 , V_182 , V_183 ) ) {
F_62 ( V_140 ) ;
return NULL ;
}
F_89 ( & V_140 -> V_159 ) ;
return & V_140 -> V_91 . V_91 ;
}
static int F_90 ( struct V_136 * V_91 )
{
struct V_4 * V_5 ;
struct V_139 * V_140 = ( void * ) V_91 ;
unsigned V_76 ;
int V_11 ;
bool V_185 = ! ! ( V_91 -> V_182 & V_186 ) ;
if ( V_91 -> V_187 != V_188 )
return 0 ;
if ( V_140 && V_140 -> V_147 ) {
V_91 -> V_168 = F_87 ( sizeof( struct V_189 ) , V_169 ) ;
if ( ! V_91 -> V_168 )
return - V_171 ;
V_91 -> V_182 |= V_186 ;
V_91 -> V_187 = V_190 ;
return 0 ;
}
if ( V_185 && V_91 -> V_168 ) {
F_61 ( V_91 -> V_168 , V_91 -> V_138 ,
V_140 -> V_91 . V_174 , V_91 -> V_111 ) ;
V_91 -> V_187 = V_190 ;
return 0 ;
}
V_5 = F_14 ( V_91 -> V_37 ) ;
#ifdef F_91
if ( F_92 () ) {
return F_93 ( & V_140 -> V_91 , V_5 -> V_172 ) ;
}
#endif
V_11 = F_94 ( V_91 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_76 = 0 ; V_76 < V_91 -> V_111 ; V_76 ++ ) {
V_140 -> V_91 . V_174 [ V_76 ] = F_95 ( V_5 -> V_191 , V_91 -> V_138 [ V_76 ] ,
0 , V_114 ,
V_192 ) ;
if ( F_96 ( V_5 -> V_191 , V_140 -> V_91 . V_174 [ V_76 ] ) ) {
while ( V_76 -- ) {
F_97 ( V_5 -> V_191 , V_140 -> V_91 . V_174 [ V_76 ] ,
V_114 , V_192 ) ;
V_140 -> V_91 . V_174 [ V_76 ] = 0 ;
}
F_98 ( V_91 ) ;
return - V_193 ;
}
}
return 0 ;
}
static void F_99 ( struct V_136 * V_91 )
{
struct V_4 * V_5 ;
struct V_139 * V_140 = ( void * ) V_91 ;
unsigned V_76 ;
bool V_185 = ! ! ( V_91 -> V_182 & V_186 ) ;
if ( V_140 && V_140 -> V_147 ) {
F_62 ( V_91 -> V_168 ) ;
V_91 -> V_182 &= ~ V_186 ;
return;
}
if ( V_185 )
return;
V_5 = F_14 ( V_91 -> V_37 ) ;
#ifdef F_91
if ( F_92 () ) {
F_100 ( & V_140 -> V_91 , V_5 -> V_172 ) ;
return;
}
#endif
for ( V_76 = 0 ; V_76 < V_91 -> V_111 ; V_76 ++ ) {
if ( V_140 -> V_91 . V_174 [ V_76 ] ) {
F_97 ( V_5 -> V_191 , V_140 -> V_91 . V_174 [ V_76 ] ,
V_114 , V_192 ) ;
}
}
F_98 ( V_91 ) ;
}
int F_101 ( struct V_136 * V_91 , T_2 V_101 ,
T_1 V_38 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
if ( V_140 == NULL )
return - V_64 ;
V_140 -> V_147 = V_101 ;
V_140 -> V_150 = V_157 -> V_194 ;
V_140 -> V_142 = V_38 ;
F_102 ( & V_140 -> V_158 ) ;
F_89 ( & V_140 -> V_160 ) ;
F_103 ( & V_140 -> V_195 , 0 ) ;
return 0 ;
}
struct V_196 * F_20 ( struct V_136 * V_91 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
if ( V_140 == NULL )
return NULL ;
return V_140 -> V_150 ;
}
bool F_104 ( struct V_136 * V_91 , unsigned long V_102 ,
unsigned long V_146 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
struct V_154 * V_197 ;
unsigned long V_17 ;
if ( V_140 == NULL || ! V_140 -> V_147 )
return false ;
V_17 = ( unsigned long ) V_140 -> V_91 . V_91 . V_111 * V_114 ;
if ( V_140 -> V_147 > V_146 || V_140 -> V_147 + V_17 <= V_102 )
return false ;
F_53 ( & V_140 -> V_158 ) ;
F_105 (entry, &gtt->guptasks, list) {
if ( V_197 -> V_156 == V_157 ) {
F_55 ( & V_140 -> V_158 ) ;
return false ;
}
}
F_55 ( & V_140 -> V_158 ) ;
F_106 ( & V_140 -> V_195 ) ;
return true ;
}
bool F_107 ( struct V_136 * V_91 ,
int * V_198 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
int V_199 = * V_198 ;
* V_198 = F_108 ( & V_140 -> V_195 ) ;
return V_199 != * V_198 ;
}
bool F_109 ( struct V_136 * V_91 )
{
struct V_139 * V_140 = ( void * ) V_91 ;
if ( V_140 == NULL )
return false ;
return ! ! ( V_140 -> V_142 & V_143 ) ;
}
T_1 F_76 ( struct V_4 * V_5 , struct V_136 * V_91 ,
struct V_96 * V_81 )
{
T_1 V_38 = 0 ;
if ( V_81 && V_81 -> V_82 != V_41 )
V_38 |= V_200 ;
if ( V_81 && V_81 -> V_82 == V_47 ) {
V_38 |= V_201 ;
if ( V_91 -> V_202 == V_203 )
V_38 |= V_204 ;
}
if ( V_5 -> V_205 >= V_206 )
V_38 |= V_207 ;
V_38 |= V_208 ;
if ( ! F_109 ( V_91 ) )
V_38 |= V_209 ;
return V_38 ;
}
static void F_110 ( struct V_65 * V_80 )
{
struct V_4 * V_5 = F_14 ( V_80 -> V_37 ) ;
unsigned V_76 , V_210 ;
for ( V_76 = 0 ; V_76 < V_211 ; ++ V_76 ) {
struct V_212 * V_213 = & V_5 -> V_12 . V_214 [ V_76 ] ;
for ( V_210 = 0 ; V_210 < V_215 ; ++ V_210 )
if ( & V_80 -> V_213 == V_213 -> V_213 [ V_210 ] )
V_213 -> V_213 [ V_210 ] = V_80 -> V_213 . V_216 ;
if ( & V_80 -> V_217 == V_213 -> V_218 )
V_213 -> V_218 = V_80 -> V_217 . V_216 ;
}
}
static struct V_212 * F_111 ( struct V_65 * V_80 )
{
struct V_4 * V_5 = F_14 ( V_80 -> V_37 ) ;
unsigned V_214 = F_28 ( F_112 ( V_80 -> V_111 ) ,
V_211 - 1 ) ;
return & V_5 -> V_12 . V_214 [ V_214 ] ;
}
static struct V_219 * F_113 ( struct V_65 * V_80 )
{
struct V_212 * V_213 = F_111 ( V_80 ) ;
struct V_219 * V_220 = V_213 -> V_213 [ V_80 -> V_81 . V_82 ] ;
V_213 -> V_213 [ V_80 -> V_81 . V_82 ] = & V_80 -> V_213 ;
while ( ( ++ V_213 ) -> V_213 [ V_80 -> V_81 . V_82 ] == V_220 )
V_213 -> V_213 [ V_80 -> V_81 . V_82 ] = & V_80 -> V_213 ;
return V_220 ;
}
static struct V_219 * F_114 ( struct V_65 * V_80 )
{
struct V_212 * V_213 = F_111 ( V_80 ) ;
struct V_219 * V_220 = V_213 -> V_218 ;
V_213 -> V_218 = & V_80 -> V_217 ;
while ( ( ++ V_213 ) -> V_218 == V_220 )
V_213 -> V_218 = & V_80 -> V_217 ;
return V_220 ;
}
static bool F_115 ( struct V_65 * V_66 ,
const struct V_71 * V_221 )
{
if ( V_66 -> V_81 . V_82 == V_54 &&
V_66 -> V_81 . V_102 == V_222 ) {
unsigned long V_111 = V_66 -> V_81 . V_111 ;
struct V_100 * V_223 = V_66 -> V_81 . V_99 ;
while ( V_111 ) {
if ( V_221 -> V_73 < ( V_223 -> V_102 + V_223 -> V_17 ) &&
! ( V_221 -> V_74 && V_221 -> V_74 <= V_223 -> V_102 ) )
return true ;
V_111 -= V_223 -> V_17 ;
++ V_223 ;
}
return false ;
}
return F_116 ( V_66 , V_221 ) ;
}
int F_117 ( struct V_4 * V_5 )
{
unsigned V_76 , V_210 ;
int V_11 ;
V_11 = F_5 ( V_5 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_118 ( & V_5 -> V_12 . V_37 ,
V_5 -> V_12 . V_22 . V_2 . V_3 ,
& V_224 ,
V_5 -> V_133 -> V_225 -> V_226 ,
V_227 ,
V_5 -> V_228 ) ;
if ( V_11 ) {
F_7 ( L_12 , V_11 ) ;
return V_11 ;
}
for ( V_76 = 0 ; V_76 < V_211 ; ++ V_76 ) {
struct V_212 * V_213 = & V_5 -> V_12 . V_214 [ V_76 ] ;
for ( V_210 = 0 ; V_210 < V_215 ; ++ V_210 )
V_213 -> V_213 [ V_210 ] = & V_5 -> V_12 . V_37 . V_40 [ V_210 ] . V_213 ;
V_213 -> V_218 = & V_5 -> V_12 . V_37 . V_229 -> V_218 ;
}
for ( V_210 = 0 ; V_210 < V_215 ; ++ V_210 )
V_5 -> V_12 . V_230 . V_213 [ V_210 ] = NULL ;
V_5 -> V_12 . V_230 . V_218 = NULL ;
V_5 -> V_12 . V_231 = true ;
V_11 = F_119 ( & V_5 -> V_12 . V_37 , V_54 ,
V_5 -> V_51 . V_232 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_13 ) ;
return V_11 ;
}
F_120 ( V_5 , V_5 -> V_51 . V_131 ) ;
V_11 = F_121 ( V_5 , 256 * 1024 , V_114 , true ,
V_233 ,
V_234 |
V_235 ,
NULL , NULL , & V_5 -> V_236 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_122 ( V_5 -> V_236 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_123 ( V_5 -> V_236 , V_233 , NULL ) ;
F_124 ( V_5 -> V_236 ) ;
if ( V_11 ) {
F_125 ( & V_5 -> V_236 ) ;
return V_11 ;
}
F_126 ( L_14 ,
( unsigned ) ( V_5 -> V_51 . V_232 / ( 1024 * 1024 ) ) ) ;
V_11 = F_119 ( & V_5 -> V_12 . V_37 , V_47 ,
V_5 -> V_51 . V_87 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_15 ) ;
return V_11 ;
}
F_126 ( L_16 ,
( unsigned ) ( V_5 -> V_51 . V_87 / ( 1024 * 1024 ) ) ) ;
V_5 -> V_237 . V_81 . V_238 = V_5 -> V_237 . V_81 . V_238 << V_239 ;
V_5 -> V_237 . V_81 . V_240 = V_5 -> V_237 . V_81 . V_240 << V_239 ;
V_5 -> V_237 . V_81 . V_241 = V_5 -> V_237 . V_81 . V_241 << V_239 ;
V_5 -> V_237 . V_242 . V_238 = V_5 -> V_237 . V_242 . V_238 << V_243 ;
V_5 -> V_237 . V_242 . V_240 = V_5 -> V_237 . V_242 . V_240 << V_243 ;
V_5 -> V_237 . V_242 . V_241 = V_5 -> V_237 . V_242 . V_241 << V_243 ;
V_5 -> V_237 . V_244 . V_238 = V_5 -> V_237 . V_244 . V_238 << V_245 ;
V_5 -> V_237 . V_244 . V_240 = V_5 -> V_237 . V_244 . V_240 << V_245 ;
V_5 -> V_237 . V_244 . V_241 = V_5 -> V_237 . V_244 . V_241 << V_245 ;
V_11 = F_119 ( & V_5 -> V_12 . V_37 , V_60 ,
V_5 -> V_237 . V_81 . V_238 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_17 ) ;
return V_11 ;
}
V_11 = F_119 ( & V_5 -> V_12 . V_37 , V_61 ,
V_5 -> V_237 . V_242 . V_238 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_18 ) ;
return V_11 ;
}
V_11 = F_119 ( & V_5 -> V_12 . V_37 , V_62 ,
V_5 -> V_237 . V_244 . V_238 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_19 ) ;
return V_11 ;
}
V_11 = F_127 ( V_5 ) ;
if ( V_11 ) {
F_7 ( L_20 ) ;
return V_11 ;
}
return 0 ;
}
void F_128 ( struct V_4 * V_5 )
{
int V_11 ;
if ( ! V_5 -> V_12 . V_231 )
return;
F_129 ( V_5 ) ;
if ( V_5 -> V_236 ) {
V_11 = F_122 ( V_5 -> V_236 , false ) ;
if ( V_11 == 0 ) {
F_130 ( V_5 -> V_236 ) ;
F_124 ( V_5 -> V_236 ) ;
}
F_125 ( & V_5 -> V_236 ) ;
}
F_131 ( & V_5 -> V_12 . V_37 , V_54 ) ;
F_131 ( & V_5 -> V_12 . V_37 , V_47 ) ;
F_131 ( & V_5 -> V_12 . V_37 , V_60 ) ;
F_131 ( & V_5 -> V_12 . V_37 , V_61 ) ;
F_131 ( & V_5 -> V_12 . V_37 , V_62 ) ;
F_132 ( & V_5 -> V_12 . V_37 ) ;
F_133 ( V_5 ) ;
F_10 ( V_5 ) ;
V_5 -> V_12 . V_231 = false ;
F_126 ( L_21 ) ;
}
void F_120 ( struct V_4 * V_5 , V_125 V_17 )
{
struct V_39 * V_40 ;
if ( ! V_5 -> V_12 . V_231 )
return;
V_40 = & V_5 -> V_12 . V_37 . V_40 [ V_54 ] ;
V_40 -> V_17 = V_17 >> V_88 ;
}
int F_134 ( struct V_89 * V_90 , struct V_148 * V_149 )
{
struct V_246 * V_247 ;
struct V_4 * V_5 ;
if ( F_35 ( V_149 -> V_248 < V_227 ) )
return - V_64 ;
V_247 = V_90 -> V_95 ;
V_5 = V_247 -> V_249 -> V_172 -> V_250 ;
if ( V_5 == NULL )
return - V_64 ;
return F_135 ( V_90 , V_149 , & V_5 -> V_12 . V_37 ) ;
}
int F_29 ( struct V_7 * V_8 ,
T_2 V_251 ,
T_2 V_252 ,
T_1 V_253 ,
struct V_254 * V_118 ,
struct V_112 * * V_113 , bool V_255 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_256 * V_257 ;
T_1 V_258 ;
unsigned V_259 , V_260 ;
unsigned V_76 ;
int V_11 ;
V_258 = V_5 -> V_12 . V_124 -> V_261 ;
V_259 = F_136 ( V_253 , V_258 ) ;
V_260 = V_259 * V_5 -> V_12 . V_124 -> V_262 ;
while ( V_260 & 0x7 )
V_260 ++ ;
V_11 = F_137 ( V_5 , V_260 * 4 , & V_257 ) ;
if ( V_11 )
return V_11 ;
if ( V_118 ) {
V_11 = F_138 ( V_5 , & V_257 -> V_263 , V_118 ,
V_264 ) ;
if ( V_11 ) {
F_7 ( L_22 , V_11 ) ;
goto V_265;
}
}
for ( V_76 = 0 ; V_76 < V_259 ; V_76 ++ ) {
T_1 V_266 = F_28 ( V_253 , V_258 ) ;
F_139 ( V_5 , & V_257 -> V_267 [ 0 ] , V_251 ,
V_252 , V_266 ) ;
V_251 += V_266 ;
V_252 += V_266 ;
V_253 -= V_266 ;
}
F_140 ( V_8 , & V_257 -> V_267 [ 0 ] ) ;
F_141 ( V_257 -> V_267 [ 0 ] . V_268 > V_260 ) ;
if ( V_255 ) {
V_11 = F_142 ( V_8 , V_257 -> V_269 , V_257 -> V_267 ,
NULL , NULL , V_113 ) ;
V_257 -> V_113 = F_143 ( * V_113 ) ;
if ( V_11 )
F_7 ( L_23 , V_11 ) ;
F_144 ( V_257 ) ;
} else {
V_11 = F_145 ( V_257 , V_8 , & V_5 -> V_12 . V_33 ,
V_264 , V_113 ) ;
if ( V_11 )
goto V_265;
}
return V_11 ;
V_265:
F_144 ( V_257 ) ;
return V_11 ;
}
int F_146 ( struct V_69 * V_66 ,
T_1 V_270 ,
struct V_254 * V_118 ,
struct V_112 * * V_113 )
{
struct V_4 * V_5 = F_14 ( V_66 -> V_80 . V_37 ) ;
T_1 V_258 = V_5 -> V_12 . V_124 -> V_271 ;
struct V_7 * V_8 = V_5 -> V_12 . V_29 ;
struct V_100 * V_99 ;
unsigned long V_111 ;
unsigned int V_259 , V_260 ;
struct V_256 * V_257 ;
int V_11 ;
if ( ! V_8 -> V_83 ) {
F_7 ( L_24 ) ;
return - V_64 ;
}
V_111 = V_66 -> V_80 . V_111 ;
V_99 = V_66 -> V_80 . V_81 . V_99 ;
V_259 = 0 ;
while ( V_111 ) {
T_1 V_253 = V_99 -> V_17 << V_88 ;
V_259 += F_136 ( V_253 , V_258 ) ;
V_111 -= V_99 -> V_17 ;
++ V_99 ;
}
V_260 = V_259 * V_5 -> V_12 . V_124 -> V_272 ;
V_260 += 64 ;
V_11 = F_137 ( V_5 , V_260 * 4 , & V_257 ) ;
if ( V_11 )
return V_11 ;
if ( V_118 ) {
V_11 = F_138 ( V_5 , & V_257 -> V_263 , V_118 ,
V_264 ) ;
if ( V_11 ) {
F_7 ( L_22 , V_11 ) ;
goto V_265;
}
}
V_111 = V_66 -> V_80 . V_111 ;
V_99 = V_66 -> V_80 . V_81 . V_99 ;
while ( V_111 ) {
T_1 V_253 = V_99 -> V_17 << V_88 ;
T_2 V_273 ;
V_11 = F_24 ( & V_66 -> V_80 , V_99 ,
& V_66 -> V_80 . V_81 , & V_273 ) ;
if ( V_11 )
return V_11 ;
while ( V_253 ) {
T_1 V_266 = F_28 ( V_253 , V_258 ) ;
F_147 ( V_5 , & V_257 -> V_267 [ 0 ] , V_270 ,
V_273 , V_266 ) ;
V_273 += V_266 ;
V_253 -= V_266 ;
}
V_111 -= V_99 -> V_17 ;
++ V_99 ;
}
F_140 ( V_8 , & V_257 -> V_267 [ 0 ] ) ;
F_141 ( V_257 -> V_267 [ 0 ] . V_268 > V_260 ) ;
V_11 = F_145 ( V_257 , V_8 , & V_5 -> V_12 . V_33 ,
V_264 , V_113 ) ;
if ( V_11 )
goto V_265;
return 0 ;
V_265:
F_144 ( V_257 ) ;
return V_11 ;
}
static int F_148 ( struct V_274 * V_275 , void * V_276 )
{
struct V_277 * V_223 = (struct V_277 * ) V_275 -> V_278 ;
unsigned V_279 = * ( int * ) V_223 -> V_280 -> V_276 ;
struct V_281 * V_172 = V_223 -> V_249 -> V_172 ;
struct V_4 * V_5 = V_172 -> V_250 ;
struct V_282 * V_194 = (struct V_282 * ) V_5 -> V_12 . V_37 . V_40 [ V_279 ] . V_283 ;
int V_284 ;
struct V_25 * V_229 = V_5 -> V_12 . V_37 . V_229 ;
F_53 ( & V_229 -> V_285 ) ;
V_284 = F_149 ( V_275 , V_194 ) ;
F_55 ( & V_229 -> V_285 ) ;
if ( V_279 == V_54 )
F_150 ( V_275 , L_25 ,
V_5 -> V_12 . V_37 . V_40 [ V_279 ] . V_17 ,
( V_125 ) F_151 ( & V_5 -> V_286 ) >> 20 ,
( V_125 ) F_151 ( & V_5 -> V_287 ) >> 20 ) ;
return V_284 ;
}
static T_3 F_152 ( struct V_89 * V_288 , char T_4 * V_289 ,
T_5 V_17 , T_6 * V_290 )
{
struct V_4 * V_5 = F_153 ( V_288 ) -> V_291 ;
T_3 V_292 = 0 ;
int V_11 ;
if ( V_17 & 0x3 || * V_290 & 0x3 )
return - V_64 ;
while ( V_17 ) {
unsigned long V_38 ;
T_1 V_293 ;
if ( * V_290 >= V_5 -> V_51 . V_294 )
return V_292 ;
F_154 ( & V_5 -> V_295 , V_38 ) ;
F_155 ( V_296 , ( ( T_1 ) * V_290 ) | 0x80000000 ) ;
F_155 ( V_297 , * V_290 >> 31 ) ;
V_293 = F_156 ( V_298 ) ;
F_157 ( & V_5 -> V_295 , V_38 ) ;
V_11 = F_158 ( V_293 , ( T_1 * ) V_289 ) ;
if ( V_11 )
return V_11 ;
V_292 += 4 ;
V_289 += 4 ;
* V_290 += 4 ;
V_17 -= 4 ;
}
return V_292 ;
}
static T_3 F_159 ( struct V_89 * V_288 , char T_4 * V_289 ,
T_5 V_17 , T_6 * V_290 )
{
struct V_4 * V_5 = F_153 ( V_288 ) -> V_291 ;
T_3 V_292 = 0 ;
int V_11 ;
while ( V_17 ) {
T_6 V_153 = * V_290 / V_114 ;
unsigned V_299 = * V_290 & ~ V_300 ;
T_5 V_301 = F_160 ( T_5 , V_17 , V_114 - V_299 ) ;
struct V_137 * V_137 ;
void * V_302 ;
if ( V_153 >= V_5 -> V_181 . V_303 )
return V_292 ;
V_137 = V_5 -> V_181 . V_138 [ V_153 ] ;
if ( V_137 ) {
V_302 = F_161 ( V_137 ) ;
V_302 += V_299 ;
V_11 = F_162 ( V_289 , V_302 , V_301 ) ;
F_163 ( V_5 -> V_181 . V_138 [ V_153 ] ) ;
} else
V_11 = F_164 ( V_289 , V_301 ) ;
if ( V_11 )
return - V_193 ;
V_292 += V_301 ;
V_289 += V_301 ;
* V_290 += V_301 ;
V_17 -= V_301 ;
}
return V_292 ;
}
static int F_127 ( struct V_4 * V_5 )
{
#if F_165 ( V_304 )
unsigned V_305 ;
struct V_306 * V_249 = V_5 -> V_133 -> V_307 ;
struct V_308 * V_309 , * V_310 = V_249 -> V_311 ;
V_309 = F_166 ( L_26 , V_312 | V_313 , V_310 ,
V_5 , & V_314 ) ;
if ( F_167 ( V_309 ) )
return F_168 ( V_309 ) ;
F_169 ( V_309 -> V_315 , V_5 -> V_51 . V_294 ) ;
V_5 -> V_12 . V_316 = V_309 ;
#ifdef F_170
V_309 = F_166 ( L_27 , V_312 | V_313 , V_310 ,
V_5 , & V_317 ) ;
if ( F_167 ( V_309 ) )
return F_168 ( V_309 ) ;
F_169 ( V_309 -> V_315 , V_5 -> V_51 . V_87 ) ;
V_5 -> V_12 . V_140 = V_309 ;
#endif
V_305 = F_171 ( V_318 ) ;
#ifdef F_91
if ( ! F_92 () )
-- V_305 ;
#endif
return F_172 ( V_5 , V_318 , V_305 ) ;
#else
return 0 ;
#endif
}
static void F_129 ( struct V_4 * V_5 )
{
#if F_165 ( V_304 )
F_173 ( V_5 -> V_12 . V_316 ) ;
V_5 -> V_12 . V_316 = NULL ;
#ifdef F_170
F_173 ( V_5 -> V_12 . V_140 ) ;
V_5 -> V_12 . V_140 = NULL ;
#endif
#endif
}
