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
if ( V_5 -> V_12 . V_123 == NULL ||
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
V_11 = F_43 ( V_66 , V_119 , V_104 , V_97 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_44 ( ( V_124 ) V_66 -> V_111 << V_88 , & V_5 -> V_125 ) ;
return 0 ;
}
static int F_45 ( struct V_36 * V_37 , struct V_96 * V_81 )
{
struct V_39 * V_40 = & V_37 -> V_40 [ V_81 -> V_82 ] ;
struct V_4 * V_5 = F_14 ( V_37 ) ;
V_81 -> V_126 . V_101 = NULL ;
V_81 -> V_126 . V_127 = 0 ;
V_81 -> V_126 . V_17 = V_81 -> V_111 << V_88 ;
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
if ( V_81 -> V_102 == V_130 )
return - V_64 ;
V_81 -> V_126 . V_127 = V_81 -> V_102 << V_88 ;
if ( ( V_81 -> V_126 . V_127 + V_81 -> V_126 . V_17 ) > V_5 -> V_51 . V_131 )
return - V_64 ;
V_81 -> V_126 . V_128 = V_5 -> V_51 . V_132 ;
V_81 -> V_126 . V_129 = true ;
#ifdef F_46
if ( V_81 -> V_68 & V_59 )
V_81 -> V_126 . V_101 =
F_47 ( V_81 -> V_126 . V_128 + V_81 -> V_126 . V_127 ,
V_81 -> V_126 . V_17 ) ;
else
V_81 -> V_126 . V_101 =
F_48 ( V_81 -> V_126 . V_128 + V_81 -> V_126 . V_127 ,
V_81 -> V_126 . V_17 ) ;
if ( ! V_81 -> V_126 . V_101 )
return - V_133 ;
V_81 -> V_126 . V_128 = ( V_81 -> V_126 . V_128 & 0x0ffffffffUL ) +
V_5 -> V_134 -> V_135 -> V_136 ;
#endif
break;
default:
return - V_64 ;
}
return 0 ;
}
static void F_49 ( struct V_36 * V_37 , struct V_96 * V_81 )
{
}
int F_50 ( struct V_137 * V_91 , struct V_138 * * V_139 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
unsigned int V_38 = 0 ;
unsigned V_142 = 0 ;
int V_11 ;
if ( ! ( V_141 -> V_143 & V_144 ) )
V_38 |= V_145 ;
if ( V_141 -> V_143 & V_146 ) {
unsigned long V_147 = V_141 -> V_148 + V_91 -> V_111 * V_114 ;
struct V_149 * V_150 ;
V_150 = F_51 ( V_141 -> V_151 , V_141 -> V_148 ) ;
if ( ! V_150 || V_150 -> V_152 || V_150 -> V_153 < V_147 )
return - V_92 ;
}
do {
unsigned V_111 = V_91 -> V_111 - V_142 ;
T_2 V_148 = V_141 -> V_148 + V_142 * V_114 ;
struct V_138 * * V_154 = V_139 + V_142 ;
struct V_155 V_156 ;
V_156 . V_157 = V_158 ;
F_52 ( & V_141 -> V_159 ) ;
F_53 ( & V_156 . V_160 , & V_141 -> V_161 ) ;
F_54 ( & V_141 -> V_159 ) ;
V_11 = F_55 ( V_148 , V_111 , V_38 , V_154 , NULL ) ;
F_52 ( & V_141 -> V_159 ) ;
F_56 ( & V_156 . V_160 ) ;
F_54 ( & V_141 -> V_159 ) ;
if ( V_11 < 0 )
goto V_162;
V_142 += V_11 ;
} while ( V_142 < V_91 -> V_111 );
return 0 ;
V_162:
V_162 ( V_139 , V_142 , 0 ) ;
return V_11 ;
}
static int F_57 ( struct V_137 * V_91 )
{
struct V_4 * V_5 = F_14 ( V_91 -> V_37 ) ;
struct V_140 * V_141 = ( void * ) V_91 ;
unsigned V_163 ;
int V_11 ;
int V_164 = ! ( V_141 -> V_143 & V_144 ) ;
enum V_165 V_166 = V_164 ?
V_167 : V_168 ;
V_11 = F_58 ( V_91 -> V_169 , V_91 -> V_139 , V_91 -> V_111 , 0 ,
V_91 -> V_111 << V_88 ,
V_170 ) ;
if ( V_11 )
goto V_171;
V_11 = - V_133 ;
V_163 = F_59 ( V_5 -> V_172 , V_91 -> V_169 -> V_173 , V_91 -> V_169 -> V_163 , V_166 ) ;
if ( V_163 != V_91 -> V_169 -> V_163 )
goto V_171;
F_60 ( V_91 -> V_169 , V_91 -> V_139 ,
V_141 -> V_91 . V_174 , V_91 -> V_111 ) ;
return 0 ;
V_171:
F_61 ( V_91 -> V_169 ) ;
return V_11 ;
}
static void F_62 ( struct V_137 * V_91 )
{
struct V_4 * V_5 = F_14 ( V_91 -> V_37 ) ;
struct V_140 * V_141 = ( void * ) V_91 ;
struct V_175 V_176 ;
int V_164 = ! ( V_141 -> V_143 & V_144 ) ;
enum V_165 V_166 = V_164 ?
V_167 : V_168 ;
if ( ! V_91 -> V_169 -> V_173 )
return;
F_63 ( V_5 -> V_172 , V_91 -> V_169 -> V_173 , V_91 -> V_169 -> V_163 , V_166 ) ;
F_64 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_138 * V_138 = F_65 ( & V_176 ) ;
if ( ! ( V_141 -> V_143 & V_144 ) )
F_66 ( V_138 ) ;
F_67 ( V_138 ) ;
F_68 ( V_138 ) ;
}
F_69 ( V_91 -> V_169 ) ;
}
static int F_70 ( struct V_137 * V_91 ,
struct V_96 * V_177 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
int V_11 ;
if ( V_141 -> V_148 ) {
V_11 = F_57 ( V_91 ) ;
if ( V_11 ) {
F_7 ( L_8 ) ;
return V_11 ;
}
}
if ( ! V_91 -> V_111 ) {
F_71 ( 1 , L_9 ,
V_91 -> V_111 , V_177 , V_91 ) ;
}
if ( V_177 -> V_82 == V_60 ||
V_177 -> V_82 == V_61 ||
V_177 -> V_82 == V_62 )
return - V_64 ;
return 0 ;
}
bool F_72 ( struct V_137 * V_91 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
return V_141 && ! F_73 ( & V_141 -> V_160 ) ;
}
int F_25 ( struct V_65 * V_66 , struct V_96 * V_177 )
{
struct V_137 * V_91 = V_66 -> V_91 ;
struct V_140 * V_141 = ( void * ) V_66 -> V_91 ;
T_1 V_38 ;
int V_11 ;
if ( ! V_91 || F_72 ( V_91 ) )
return 0 ;
V_11 = F_74 ( & V_66 -> V_37 -> V_40 [ V_47 ] , V_66 ,
NULL , V_177 ) ;
if ( V_11 ) {
F_7 ( L_10 , V_11 ) ;
return V_11 ;
}
V_38 = F_75 ( V_141 -> V_5 , V_91 , V_177 ) ;
V_141 -> V_127 = ( V_124 ) V_177 -> V_102 << V_88 ;
V_11 = F_76 ( V_141 -> V_5 , V_141 -> V_127 , V_91 -> V_111 ,
V_91 -> V_139 , V_141 -> V_91 . V_174 , V_38 ) ;
if ( V_11 ) {
F_7 ( L_11 ,
V_91 -> V_111 , V_141 -> V_127 ) ;
return V_11 ;
}
F_52 ( & V_141 -> V_5 -> V_178 ) ;
F_77 ( & V_141 -> V_160 , & V_141 -> V_5 -> V_179 ) ;
F_54 ( & V_141 -> V_5 -> V_178 ) ;
return 0 ;
}
int F_78 ( struct V_4 * V_5 )
{
struct V_140 * V_141 , * V_180 ;
struct V_96 V_177 ;
T_1 V_38 ;
int V_11 ;
V_177 . V_82 = V_47 ;
F_52 ( & V_5 -> V_178 ) ;
F_79 (gtt, tmp, &adev->gtt_list, list) {
V_38 = F_75 ( V_141 -> V_5 , & V_141 -> V_91 . V_91 , & V_177 ) ;
V_11 = F_76 ( V_5 , V_141 -> V_127 , V_141 -> V_91 . V_91 . V_111 ,
V_141 -> V_91 . V_91 . V_139 , V_141 -> V_91 . V_174 ,
V_38 ) ;
if ( V_11 ) {
F_54 ( & V_5 -> V_178 ) ;
F_7 ( L_11 ,
V_141 -> V_91 . V_91 . V_111 , V_141 -> V_127 ) ;
return V_11 ;
}
}
F_54 ( & V_5 -> V_178 ) ;
return 0 ;
}
static int F_80 ( struct V_137 * V_91 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
if ( V_141 -> V_148 )
F_62 ( V_91 ) ;
if ( ! F_72 ( V_91 ) )
return 0 ;
if ( V_141 -> V_5 -> V_181 . V_83 )
F_81 ( V_141 -> V_5 , V_141 -> V_127 , V_91 -> V_111 ) ;
F_52 ( & V_141 -> V_5 -> V_178 ) ;
F_82 ( & V_141 -> V_160 ) ;
F_54 ( & V_141 -> V_5 -> V_178 ) ;
return 0 ;
}
static void F_83 ( struct V_137 * V_91 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
F_84 ( & V_141 -> V_91 ) ;
F_61 ( V_141 ) ;
}
static struct V_137 * F_85 ( struct V_36 * V_37 ,
unsigned long V_17 , T_1 V_182 ,
struct V_138 * V_183 )
{
struct V_4 * V_5 ;
struct V_140 * V_141 ;
V_5 = F_14 ( V_37 ) ;
V_141 = F_86 ( sizeof( struct V_140 ) , V_170 ) ;
if ( V_141 == NULL ) {
return NULL ;
}
V_141 -> V_91 . V_91 . V_48 = & V_184 ;
V_141 -> V_5 = V_5 ;
if ( F_87 ( & V_141 -> V_91 , V_37 , V_17 , V_182 , V_183 ) ) {
F_61 ( V_141 ) ;
return NULL ;
}
F_88 ( & V_141 -> V_160 ) ;
return & V_141 -> V_91 . V_91 ;
}
static int F_89 ( struct V_137 * V_91 )
{
struct V_4 * V_5 ;
struct V_140 * V_141 = ( void * ) V_91 ;
unsigned V_76 ;
int V_11 ;
bool V_185 = ! ! ( V_91 -> V_182 & V_186 ) ;
if ( V_91 -> V_187 != V_188 )
return 0 ;
if ( V_141 && V_141 -> V_148 ) {
V_91 -> V_169 = F_86 ( sizeof( struct V_189 ) , V_170 ) ;
if ( ! V_91 -> V_169 )
return - V_133 ;
V_91 -> V_182 |= V_186 ;
V_91 -> V_187 = V_190 ;
return 0 ;
}
if ( V_185 && V_91 -> V_169 ) {
F_60 ( V_91 -> V_169 , V_91 -> V_139 ,
V_141 -> V_91 . V_174 , V_91 -> V_111 ) ;
V_91 -> V_187 = V_190 ;
return 0 ;
}
V_5 = F_14 ( V_91 -> V_37 ) ;
#ifdef F_90
if ( F_91 () ) {
return F_92 ( & V_141 -> V_91 , V_5 -> V_172 ) ;
}
#endif
V_11 = F_93 ( V_91 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_76 = 0 ; V_76 < V_91 -> V_111 ; V_76 ++ ) {
V_141 -> V_91 . V_174 [ V_76 ] = F_94 ( V_5 -> V_191 , V_91 -> V_139 [ V_76 ] ,
0 , V_114 ,
V_192 ) ;
if ( F_95 ( V_5 -> V_191 , V_141 -> V_91 . V_174 [ V_76 ] ) ) {
while ( V_76 -- ) {
F_96 ( V_5 -> V_191 , V_141 -> V_91 . V_174 [ V_76 ] ,
V_114 , V_192 ) ;
V_141 -> V_91 . V_174 [ V_76 ] = 0 ;
}
F_97 ( V_91 ) ;
return - V_193 ;
}
}
return 0 ;
}
static void F_98 ( struct V_137 * V_91 )
{
struct V_4 * V_5 ;
struct V_140 * V_141 = ( void * ) V_91 ;
unsigned V_76 ;
bool V_185 = ! ! ( V_91 -> V_182 & V_186 ) ;
if ( V_141 && V_141 -> V_148 ) {
F_61 ( V_91 -> V_169 ) ;
V_91 -> V_182 &= ~ V_186 ;
return;
}
if ( V_185 )
return;
V_5 = F_14 ( V_91 -> V_37 ) ;
#ifdef F_90
if ( F_91 () ) {
F_99 ( & V_141 -> V_91 , V_5 -> V_172 ) ;
return;
}
#endif
for ( V_76 = 0 ; V_76 < V_91 -> V_111 ; V_76 ++ ) {
if ( V_141 -> V_91 . V_174 [ V_76 ] ) {
F_96 ( V_5 -> V_191 , V_141 -> V_91 . V_174 [ V_76 ] ,
V_114 , V_192 ) ;
}
}
F_97 ( V_91 ) ;
}
int F_100 ( struct V_137 * V_91 , T_2 V_101 ,
T_1 V_38 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
if ( V_141 == NULL )
return - V_64 ;
V_141 -> V_148 = V_101 ;
V_141 -> V_151 = V_158 -> V_194 ;
V_141 -> V_143 = V_38 ;
F_101 ( & V_141 -> V_159 ) ;
F_88 ( & V_141 -> V_161 ) ;
F_102 ( & V_141 -> V_195 , 0 ) ;
return 0 ;
}
struct V_196 * F_20 ( struct V_137 * V_91 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
if ( V_141 == NULL )
return NULL ;
return V_141 -> V_151 ;
}
bool F_103 ( struct V_137 * V_91 , unsigned long V_102 ,
unsigned long V_147 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
struct V_155 * V_197 ;
unsigned long V_17 ;
if ( V_141 == NULL || ! V_141 -> V_148 )
return false ;
V_17 = ( unsigned long ) V_141 -> V_91 . V_91 . V_111 * V_114 ;
if ( V_141 -> V_148 > V_147 || V_141 -> V_148 + V_17 <= V_102 )
return false ;
F_52 ( & V_141 -> V_159 ) ;
F_104 (entry, &gtt->guptasks, list) {
if ( V_197 -> V_157 == V_158 ) {
F_54 ( & V_141 -> V_159 ) ;
return false ;
}
}
F_54 ( & V_141 -> V_159 ) ;
F_105 ( & V_141 -> V_195 ) ;
return true ;
}
bool F_106 ( struct V_137 * V_91 ,
int * V_198 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
int V_199 = * V_198 ;
* V_198 = F_107 ( & V_141 -> V_195 ) ;
return V_199 != * V_198 ;
}
bool F_108 ( struct V_137 * V_91 )
{
struct V_140 * V_141 = ( void * ) V_91 ;
if ( V_141 == NULL )
return false ;
return ! ! ( V_141 -> V_143 & V_144 ) ;
}
T_1 F_75 ( struct V_4 * V_5 , struct V_137 * V_91 ,
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
if ( ! F_108 ( V_91 ) )
V_38 |= V_209 ;
return V_38 ;
}
static bool F_109 ( struct V_65 * V_66 ,
const struct V_71 * V_210 )
{
if ( V_66 -> V_81 . V_82 == V_54 &&
V_66 -> V_81 . V_102 == V_130 ) {
unsigned long V_111 = V_66 -> V_81 . V_111 ;
struct V_100 * V_211 = V_66 -> V_81 . V_99 ;
while ( V_111 ) {
if ( V_210 -> V_73 < ( V_211 -> V_102 + V_211 -> V_17 ) &&
! ( V_210 -> V_74 && V_210 -> V_74 <= V_211 -> V_102 ) )
return true ;
V_111 -= V_211 -> V_17 ;
++ V_211 ;
}
return false ;
}
return F_110 ( V_66 , V_210 ) ;
}
int F_111 ( struct V_4 * V_5 )
{
int V_11 ;
V_11 = F_5 ( V_5 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_112 ( & V_5 -> V_12 . V_37 ,
V_5 -> V_12 . V_22 . V_2 . V_3 ,
& V_212 ,
V_5 -> V_134 -> V_213 -> V_214 ,
V_215 ,
V_5 -> V_216 ) ;
if ( V_11 ) {
F_7 ( L_12 , V_11 ) ;
return V_11 ;
}
V_5 -> V_12 . V_217 = true ;
V_11 = F_113 ( & V_5 -> V_12 . V_37 , V_54 ,
V_5 -> V_51 . V_218 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_13 ) ;
return V_11 ;
}
F_114 ( V_5 , V_5 -> V_51 . V_131 ) ;
V_11 = F_115 ( V_5 , 256 * 1024 , V_114 , true ,
V_219 ,
V_220 |
V_221 ,
NULL , NULL , & V_5 -> V_222 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_116 ( V_5 -> V_222 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_117 ( V_5 -> V_222 , V_219 , NULL ) ;
F_118 ( V_5 -> V_222 ) ;
if ( V_11 ) {
F_119 ( & V_5 -> V_222 ) ;
return V_11 ;
}
F_120 ( L_14 ,
( unsigned ) ( V_5 -> V_51 . V_218 / ( 1024 * 1024 ) ) ) ;
V_11 = F_113 ( & V_5 -> V_12 . V_37 , V_47 ,
V_5 -> V_51 . V_87 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_15 ) ;
return V_11 ;
}
F_120 ( L_16 ,
( unsigned ) ( V_5 -> V_51 . V_87 / ( 1024 * 1024 ) ) ) ;
V_5 -> V_223 . V_81 . V_224 = V_5 -> V_223 . V_81 . V_224 << V_225 ;
V_5 -> V_223 . V_81 . V_226 = V_5 -> V_223 . V_81 . V_226 << V_225 ;
V_5 -> V_223 . V_81 . V_227 = V_5 -> V_223 . V_81 . V_227 << V_225 ;
V_5 -> V_223 . V_228 . V_224 = V_5 -> V_223 . V_228 . V_224 << V_229 ;
V_5 -> V_223 . V_228 . V_226 = V_5 -> V_223 . V_228 . V_226 << V_229 ;
V_5 -> V_223 . V_228 . V_227 = V_5 -> V_223 . V_228 . V_227 << V_229 ;
V_5 -> V_223 . V_230 . V_224 = V_5 -> V_223 . V_230 . V_224 << V_231 ;
V_5 -> V_223 . V_230 . V_226 = V_5 -> V_223 . V_230 . V_226 << V_231 ;
V_5 -> V_223 . V_230 . V_227 = V_5 -> V_223 . V_230 . V_227 << V_231 ;
V_11 = F_113 ( & V_5 -> V_12 . V_37 , V_60 ,
V_5 -> V_223 . V_81 . V_224 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_17 ) ;
return V_11 ;
}
V_11 = F_113 ( & V_5 -> V_12 . V_37 , V_61 ,
V_5 -> V_223 . V_228 . V_224 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_18 ) ;
return V_11 ;
}
V_11 = F_113 ( & V_5 -> V_12 . V_37 , V_62 ,
V_5 -> V_223 . V_230 . V_224 >> V_88 ) ;
if ( V_11 ) {
F_7 ( L_19 ) ;
return V_11 ;
}
V_11 = F_121 ( V_5 ) ;
if ( V_11 ) {
F_7 ( L_20 ) ;
return V_11 ;
}
return 0 ;
}
void F_122 ( struct V_4 * V_5 )
{
int V_11 ;
if ( ! V_5 -> V_12 . V_217 )
return;
F_123 ( V_5 ) ;
if ( V_5 -> V_222 ) {
V_11 = F_116 ( V_5 -> V_222 , false ) ;
if ( V_11 == 0 ) {
F_124 ( V_5 -> V_222 ) ;
F_118 ( V_5 -> V_222 ) ;
}
F_119 ( & V_5 -> V_222 ) ;
}
F_125 ( & V_5 -> V_12 . V_37 , V_54 ) ;
F_125 ( & V_5 -> V_12 . V_37 , V_47 ) ;
F_125 ( & V_5 -> V_12 . V_37 , V_60 ) ;
F_125 ( & V_5 -> V_12 . V_37 , V_61 ) ;
F_125 ( & V_5 -> V_12 . V_37 , V_62 ) ;
F_126 ( & V_5 -> V_12 . V_37 ) ;
F_127 ( V_5 ) ;
F_10 ( V_5 ) ;
V_5 -> V_12 . V_217 = false ;
F_120 ( L_21 ) ;
}
void F_114 ( struct V_4 * V_5 , V_124 V_17 )
{
struct V_39 * V_40 ;
if ( ! V_5 -> V_12 . V_217 )
return;
V_40 = & V_5 -> V_12 . V_37 . V_40 [ V_54 ] ;
V_40 -> V_17 = V_17 >> V_88 ;
}
int F_128 ( struct V_89 * V_90 , struct V_149 * V_150 )
{
struct V_232 * V_233 ;
struct V_4 * V_5 ;
if ( F_35 ( V_150 -> V_234 < V_215 ) )
return - V_64 ;
V_233 = V_90 -> V_95 ;
V_5 = V_233 -> V_235 -> V_172 -> V_236 ;
if ( V_5 == NULL )
return - V_64 ;
return F_129 ( V_90 , V_150 , & V_5 -> V_12 . V_37 ) ;
}
int F_29 ( struct V_7 * V_8 ,
T_2 V_237 ,
T_2 V_238 ,
T_1 V_239 ,
struct V_240 * V_118 ,
struct V_112 * * V_113 , bool V_241 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_242 * V_243 ;
T_1 V_244 ;
unsigned V_245 , V_246 ;
unsigned V_76 ;
int V_11 ;
V_244 = V_5 -> V_12 . V_123 -> V_247 ;
V_245 = F_130 ( V_239 , V_244 ) ;
V_246 = V_245 * V_5 -> V_12 . V_123 -> V_248 ;
while ( V_246 & 0x7 )
V_246 ++ ;
V_11 = F_131 ( V_5 , V_246 * 4 , & V_243 ) ;
if ( V_11 )
return V_11 ;
if ( V_118 ) {
V_11 = F_132 ( V_5 , & V_243 -> V_249 , V_118 ,
V_250 ) ;
if ( V_11 ) {
F_7 ( L_22 , V_11 ) ;
goto V_251;
}
}
for ( V_76 = 0 ; V_76 < V_245 ; V_76 ++ ) {
T_1 V_252 = F_28 ( V_239 , V_244 ) ;
F_133 ( V_5 , & V_243 -> V_253 [ 0 ] , V_237 ,
V_238 , V_252 ) ;
V_237 += V_252 ;
V_238 += V_252 ;
V_239 -= V_252 ;
}
F_134 ( V_8 , & V_243 -> V_253 [ 0 ] ) ;
F_135 ( V_243 -> V_253 [ 0 ] . V_254 > V_246 ) ;
if ( V_241 ) {
V_11 = F_136 ( V_8 , V_243 -> V_255 , V_243 -> V_253 ,
NULL , V_113 ) ;
V_243 -> V_113 = F_137 ( * V_113 ) ;
if ( V_11 )
F_7 ( L_23 , V_11 ) ;
F_138 ( V_243 ) ;
} else {
V_11 = F_139 ( V_243 , V_8 , & V_5 -> V_12 . V_33 ,
V_250 , V_113 ) ;
if ( V_11 )
goto V_251;
}
return V_11 ;
V_251:
F_138 ( V_243 ) ;
return V_11 ;
}
int F_140 ( struct V_69 * V_66 ,
T_1 V_256 ,
struct V_240 * V_118 ,
struct V_112 * * V_113 )
{
struct V_4 * V_5 = F_14 ( V_66 -> V_80 . V_37 ) ;
T_1 V_244 = V_5 -> V_12 . V_123 -> V_257 ;
struct V_7 * V_8 = V_5 -> V_12 . V_29 ;
struct V_100 * V_99 ;
unsigned long V_111 ;
unsigned int V_245 , V_246 ;
struct V_242 * V_243 ;
int V_11 ;
if ( ! V_8 -> V_83 ) {
F_7 ( L_24 ) ;
return - V_64 ;
}
V_111 = V_66 -> V_80 . V_111 ;
V_99 = V_66 -> V_80 . V_81 . V_99 ;
V_245 = 0 ;
while ( V_111 ) {
T_1 V_239 = V_99 -> V_17 << V_88 ;
V_245 += F_130 ( V_239 , V_244 ) ;
V_111 -= V_99 -> V_17 ;
++ V_99 ;
}
V_246 = V_245 * V_5 -> V_12 . V_123 -> V_258 ;
V_246 += 64 ;
V_11 = F_131 ( V_5 , V_246 * 4 , & V_243 ) ;
if ( V_11 )
return V_11 ;
if ( V_118 ) {
V_11 = F_132 ( V_5 , & V_243 -> V_249 , V_118 ,
V_250 ) ;
if ( V_11 ) {
F_7 ( L_22 , V_11 ) ;
goto V_251;
}
}
V_111 = V_66 -> V_80 . V_111 ;
V_99 = V_66 -> V_80 . V_81 . V_99 ;
while ( V_111 ) {
T_1 V_239 = V_99 -> V_17 << V_88 ;
T_2 V_259 ;
V_11 = F_24 ( & V_66 -> V_80 , V_99 ,
& V_66 -> V_80 . V_81 , & V_259 ) ;
if ( V_11 )
return V_11 ;
while ( V_239 ) {
T_1 V_252 = F_28 ( V_239 , V_244 ) ;
F_141 ( V_5 , & V_243 -> V_253 [ 0 ] , V_256 ,
V_259 , V_252 ) ;
V_259 += V_252 ;
V_239 -= V_252 ;
}
V_111 -= V_99 -> V_17 ;
++ V_99 ;
}
F_134 ( V_8 , & V_243 -> V_253 [ 0 ] ) ;
F_135 ( V_243 -> V_253 [ 0 ] . V_254 > V_246 ) ;
V_11 = F_139 ( V_243 , V_8 , & V_5 -> V_12 . V_33 ,
V_250 , V_113 ) ;
if ( V_11 )
goto V_251;
return 0 ;
V_251:
F_138 ( V_243 ) ;
return V_11 ;
}
static int F_142 ( struct V_260 * V_261 , void * V_262 )
{
struct V_263 * V_211 = (struct V_263 * ) V_261 -> V_264 ;
unsigned V_265 = * ( int * ) V_211 -> V_266 -> V_262 ;
struct V_267 * V_172 = V_211 -> V_235 -> V_172 ;
struct V_4 * V_5 = V_172 -> V_236 ;
struct V_268 * V_194 = (struct V_268 * ) V_5 -> V_12 . V_37 . V_40 [ V_265 ] . V_269 ;
struct V_25 * V_270 = V_5 -> V_12 . V_37 . V_270 ;
struct V_271 V_154 = F_143 ( V_261 ) ;
F_52 ( & V_270 -> V_272 ) ;
F_144 ( V_194 , & V_154 ) ;
F_54 ( & V_270 -> V_272 ) ;
if ( V_265 == V_54 )
F_145 ( V_261 , L_25 ,
V_5 -> V_12 . V_37 . V_40 [ V_265 ] . V_17 ,
( V_124 ) F_146 ( & V_5 -> V_273 ) >> 20 ,
( V_124 ) F_146 ( & V_5 -> V_274 ) >> 20 ) ;
return 0 ;
}
static T_3 F_147 ( struct V_89 * V_275 , char T_4 * V_276 ,
T_5 V_17 , T_6 * V_277 )
{
struct V_4 * V_5 = F_148 ( V_275 ) -> V_278 ;
T_3 V_279 = 0 ;
int V_11 ;
if ( V_17 & 0x3 || * V_277 & 0x3 )
return - V_64 ;
while ( V_17 ) {
unsigned long V_38 ;
T_1 V_280 ;
if ( * V_277 >= V_5 -> V_51 . V_281 )
return V_279 ;
F_149 ( & V_5 -> V_282 , V_38 ) ;
F_150 ( V_283 , ( ( T_1 ) * V_277 ) | 0x80000000 ) ;
F_150 ( V_284 , * V_277 >> 31 ) ;
V_280 = F_151 ( V_285 ) ;
F_152 ( & V_5 -> V_282 , V_38 ) ;
V_11 = F_153 ( V_280 , ( T_1 * ) V_276 ) ;
if ( V_11 )
return V_11 ;
V_279 += 4 ;
V_276 += 4 ;
* V_277 += 4 ;
V_17 -= 4 ;
}
return V_279 ;
}
static T_3 F_154 ( struct V_89 * V_275 , char T_4 * V_276 ,
T_5 V_17 , T_6 * V_277 )
{
struct V_4 * V_5 = F_148 ( V_275 ) -> V_278 ;
T_3 V_279 = 0 ;
int V_11 ;
while ( V_17 ) {
T_6 V_154 = * V_277 / V_114 ;
unsigned V_286 = * V_277 & ~ V_287 ;
T_5 V_288 = F_155 ( T_5 , V_17 , V_114 - V_286 ) ;
struct V_138 * V_138 ;
void * V_289 ;
if ( V_154 >= V_5 -> V_181 . V_290 )
return V_279 ;
V_138 = V_5 -> V_181 . V_139 [ V_154 ] ;
if ( V_138 ) {
V_289 = F_156 ( V_138 ) ;
V_289 += V_286 ;
V_11 = F_157 ( V_276 , V_289 , V_288 ) ;
F_158 ( V_5 -> V_181 . V_139 [ V_154 ] ) ;
} else
V_11 = F_159 ( V_276 , V_288 ) ;
if ( V_11 )
return - V_193 ;
V_279 += V_288 ;
V_276 += V_288 ;
* V_277 += V_288 ;
V_17 -= V_288 ;
}
return V_279 ;
}
static int F_121 ( struct V_4 * V_5 )
{
#if F_160 ( V_291 )
unsigned V_292 ;
struct V_293 * V_235 = V_5 -> V_134 -> V_294 ;
struct V_295 * V_296 , * V_297 = V_235 -> V_298 ;
V_296 = F_161 ( L_26 , V_299 | V_300 , V_297 ,
V_5 , & V_301 ) ;
if ( F_162 ( V_296 ) )
return F_163 ( V_296 ) ;
F_164 ( V_296 -> V_302 , V_5 -> V_51 . V_281 ) ;
V_5 -> V_12 . V_303 = V_296 ;
#ifdef F_165
V_296 = F_161 ( L_27 , V_299 | V_300 , V_297 ,
V_5 , & V_304 ) ;
if ( F_162 ( V_296 ) )
return F_163 ( V_296 ) ;
F_164 ( V_296 -> V_302 , V_5 -> V_51 . V_87 ) ;
V_5 -> V_12 . V_141 = V_296 ;
#endif
V_292 = F_166 ( V_305 ) ;
#ifdef F_90
if ( ! F_91 () )
-- V_292 ;
#endif
return F_167 ( V_5 , V_305 , V_292 ) ;
#else
return 0 ;
#endif
}
static void F_123 ( struct V_4 * V_5 )
{
#if F_160 ( V_291 )
F_168 ( V_5 -> V_12 . V_303 ) ;
V_5 -> V_12 . V_303 = NULL ;
#ifdef F_165
F_168 ( V_5 -> V_12 . V_141 ) ;
V_5 -> V_12 . V_141 = NULL ;
#endif
#endif
}
