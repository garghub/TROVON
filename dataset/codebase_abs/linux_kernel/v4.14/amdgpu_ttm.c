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
F_8 ( & V_5 -> V_12 . V_29 ) ;
V_8 = V_5 -> V_12 . V_30 ;
V_10 = & V_8 -> V_31 . V_32 [ V_33 ] ;
V_11 = F_9 ( & V_8 -> V_31 , & V_5 -> V_12 . V_34 ,
V_10 , V_35 ) ;
if ( V_11 ) {
F_7 ( L_4 ) ;
goto V_36;
}
V_5 -> V_12 . V_13 = true ;
return 0 ;
V_36:
F_10 ( & V_5 -> V_12 . V_22 . V_2 ) ;
V_28:
F_10 ( & V_5 -> V_12 . V_14 ) ;
V_21:
return V_11 ;
}
static void F_11 ( struct V_4 * V_5 )
{
if ( V_5 -> V_12 . V_13 ) {
F_12 ( V_5 -> V_12 . V_34 . V_31 ,
& V_5 -> V_12 . V_34 ) ;
F_13 ( & V_5 -> V_12 . V_29 ) ;
F_10 ( & V_5 -> V_12 . V_22 . V_2 ) ;
F_10 ( & V_5 -> V_12 . V_14 ) ;
V_5 -> V_12 . V_13 = false ;
}
}
static int F_14 ( struct V_37 * V_38 , T_1 V_39 )
{
return 0 ;
}
static int F_15 ( struct V_37 * V_38 , T_1 type ,
struct V_40 * V_41 )
{
struct V_4 * V_5 ;
V_5 = F_16 ( V_38 ) ;
switch ( type ) {
case V_42 :
V_41 -> V_39 = V_43 ;
V_41 -> V_44 = V_45 ;
V_41 -> V_46 = V_47 ;
break;
case V_48 :
V_41 -> V_49 = & V_50 ;
V_41 -> V_51 = V_5 -> V_52 . V_53 ;
V_41 -> V_44 = V_45 ;
V_41 -> V_46 = V_47 ;
V_41 -> V_39 = V_43 | V_54 ;
break;
case V_55 :
V_41 -> V_49 = & V_56 ;
V_41 -> V_51 = V_5 -> V_52 . V_57 ;
V_41 -> V_39 = V_58 |
V_43 ;
V_41 -> V_44 = V_59 | V_60 ;
V_41 -> V_46 = V_60 ;
break;
case V_61 :
case V_62 :
case V_63 :
V_41 -> V_49 = & V_64 ;
V_41 -> V_51 = 0 ;
V_41 -> V_39 = V_58 | V_54 ;
V_41 -> V_44 = V_59 ;
V_41 -> V_46 = V_59 ;
break;
default:
F_7 ( L_5 , ( unsigned ) type ) ;
return - V_65 ;
}
return 0 ;
}
static void F_17 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_4 * V_5 = F_16 ( V_67 -> V_38 ) ;
struct V_70 * V_71 ;
static const struct V_72 V_73 = {
. V_74 = 0 ,
. V_75 = 0 ,
. V_39 = V_45 | V_76
} ;
if ( ! F_18 ( V_67 ) ) {
V_69 -> V_69 = & V_73 ;
V_69 -> V_77 = & V_73 ;
V_69 -> V_78 = 1 ;
V_69 -> V_79 = 1 ;
return;
}
V_71 = F_19 ( V_67 , struct V_70 , V_80 ) ;
switch ( V_67 -> V_81 . V_82 ) {
case V_55 :
if ( V_5 -> V_12 . V_83 &&
V_5 -> V_12 . V_30 &&
V_5 -> V_12 . V_30 -> V_84 == false ) {
F_20 ( V_71 , V_85 ) ;
} else if ( V_5 -> V_52 . V_86 < V_5 -> V_52 . V_87 &&
! ( V_71 -> V_39 & V_88 ) ) {
unsigned V_74 = V_5 -> V_52 . V_86 >> V_89 ;
struct V_90 * V_91 = V_67 -> V_81 . V_92 ;
unsigned long V_93 ;
for ( V_93 = V_67 -> V_81 . V_94 ;
V_93 ;
V_93 -= V_91 -> V_17 , V_91 ++ ) {
if ( V_91 -> V_95 < V_74 )
break;
}
if ( ! V_93 )
goto V_96;
F_20 ( V_71 , V_97 |
V_98 ) ;
V_71 -> V_73 [ 0 ] . V_74 = V_74 ;
V_71 -> V_73 [ 0 ] . V_75 = 0 ;
V_71 -> V_69 . V_77 = & V_71 -> V_73 [ 1 ] ;
V_71 -> V_69 . V_79 = 1 ;
} else {
V_96:
F_20 ( V_71 , V_98 ) ;
}
break;
case V_48 :
default:
F_20 ( V_71 , V_85 ) ;
}
* V_69 = V_71 -> V_69 ;
}
static int F_21 ( struct V_66 * V_67 , struct V_99 * V_100 )
{
struct V_70 * V_71 = F_19 ( V_67 , struct V_70 , V_80 ) ;
if ( F_22 ( V_67 -> V_101 ) )
return - V_102 ;
return F_23 ( & V_71 -> V_103 . V_104 ,
V_100 -> V_105 ) ;
}
static void F_24 ( struct V_66 * V_67 ,
struct V_106 * V_107 )
{
struct V_106 * V_108 = & V_67 -> V_81 ;
F_25 ( V_108 -> V_92 != NULL ) ;
* V_108 = * V_107 ;
V_107 -> V_92 = NULL ;
}
static T_2 F_26 ( struct V_66 * V_67 ,
struct V_90 * V_92 ,
struct V_106 * V_81 )
{
T_2 V_109 = 0 ;
if ( V_81 -> V_82 != V_48 ||
F_27 ( V_81 ) ) {
V_109 = V_92 -> V_95 << V_89 ;
V_109 += V_67 -> V_38 -> V_41 [ V_81 -> V_82 ] . V_51 ;
}
return V_109 ;
}
static int F_28 ( struct V_66 * V_67 ,
bool V_110 , bool V_111 ,
struct V_106 * V_107 ,
struct V_106 * V_108 )
{
struct V_4 * V_5 = F_16 ( V_67 -> V_38 ) ;
struct V_7 * V_8 = V_5 -> V_12 . V_30 ;
struct V_90 * V_112 , * V_113 ;
T_2 V_114 , V_115 , V_116 , V_117 ;
unsigned long V_94 ;
struct V_118 * V_119 = NULL ;
int V_11 ;
F_29 ( ( V_120 % V_121 ) != 0 ) ;
if ( ! V_8 -> V_84 ) {
F_7 ( L_6 ) ;
return - V_65 ;
}
V_112 = V_108 -> V_92 ;
V_115 = V_112 -> V_17 ;
V_114 = F_26 ( V_67 , V_112 , V_108 ) ;
V_113 = V_107 -> V_92 ;
V_117 = V_113 -> V_17 ;
V_116 = F_26 ( V_67 , V_113 , V_107 ) ;
V_94 = V_107 -> V_94 ;
F_30 ( & V_5 -> V_12 . V_29 ) ;
while ( V_94 ) {
unsigned long V_122 = F_31 ( F_31 ( V_115 , V_117 ) ,
( V_123 ) V_124 ) ;
T_2 V_125 = V_114 , V_126 = V_116 ;
struct V_118 * V_127 ;
if ( V_108 -> V_82 == V_48 &&
! F_27 ( V_108 ) ) {
V_11 = F_32 ( V_67 , V_108 , V_122 ,
V_114 , 0 , V_8 , & V_125 ) ;
if ( V_11 )
goto error;
}
if ( V_107 -> V_82 == V_48 &&
! F_27 ( V_107 ) ) {
V_11 = F_32 ( V_67 , V_107 , V_122 ,
V_116 , 1 , V_8 , & V_126 ) ;
if ( V_11 )
goto error;
}
V_11 = F_33 ( V_8 , V_125 , V_126 ,
V_122 * V_120 ,
V_67 -> V_128 , & V_127 , false , true ) ;
if ( V_11 )
goto error;
F_34 ( V_119 ) ;
V_119 = V_127 ;
V_94 -= V_122 ;
if ( ! V_94 )
break;
V_115 -= V_122 ;
if ( ! V_115 ) {
V_114 = F_26 ( V_67 , ++ V_112 , V_108 ) ;
V_115 = V_112 -> V_17 ;
} else {
V_114 += V_122 * V_120 ;
}
V_117 -= V_122 ;
if ( ! V_117 ) {
V_116 = F_26 ( V_67 , ++ V_113 , V_107 ) ;
V_117 = V_113 -> V_17 ;
} else {
V_116 += V_122 * V_120 ;
}
}
F_35 ( & V_5 -> V_12 . V_29 ) ;
V_11 = F_36 ( V_67 , V_119 , V_110 , V_107 ) ;
F_34 ( V_119 ) ;
return V_11 ;
error:
F_35 ( & V_5 -> V_12 . V_29 ) ;
if ( V_119 )
F_37 ( V_119 , false ) ;
F_34 ( V_119 ) ;
return V_11 ;
}
static int F_38 ( struct V_66 * V_67 ,
bool V_110 , bool V_129 ,
bool V_111 ,
struct V_106 * V_107 )
{
struct V_4 * V_5 ;
struct V_106 * V_108 = & V_67 -> V_81 ;
struct V_106 V_130 ;
struct V_72 V_73 ;
struct V_68 V_69 ;
int V_11 ;
V_5 = F_16 ( V_67 -> V_38 ) ;
V_130 = * V_107 ;
V_130 . V_92 = NULL ;
V_69 . V_78 = 1 ;
V_69 . V_69 = & V_73 ;
V_69 . V_79 = 1 ;
V_69 . V_77 = & V_73 ;
V_73 . V_74 = 0 ;
V_73 . V_75 = 0 ;
V_73 . V_39 = V_45 | V_131 ;
V_11 = F_39 ( V_67 , & V_69 , & V_130 ,
V_129 , V_111 ) ;
if ( F_40 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_41 ( V_67 -> V_101 , V_130 . V_69 ) ;
if ( F_40 ( V_11 ) ) {
goto V_132;
}
V_11 = F_42 ( V_67 -> V_101 , & V_130 ) ;
if ( F_40 ( V_11 ) ) {
goto V_132;
}
V_11 = F_28 ( V_67 , true , V_111 , & V_130 , V_108 ) ;
if ( F_40 ( V_11 ) ) {
goto V_132;
}
V_11 = F_43 ( V_67 , V_129 , V_111 , V_107 ) ;
V_132:
F_44 ( V_67 , & V_130 ) ;
return V_11 ;
}
static int F_45 ( struct V_66 * V_67 ,
bool V_110 , bool V_129 ,
bool V_111 ,
struct V_106 * V_107 )
{
struct V_4 * V_5 ;
struct V_106 * V_108 = & V_67 -> V_81 ;
struct V_106 V_130 ;
struct V_68 V_69 ;
struct V_72 V_73 ;
int V_11 ;
V_5 = F_16 ( V_67 -> V_38 ) ;
V_130 = * V_107 ;
V_130 . V_92 = NULL ;
V_69 . V_78 = 1 ;
V_69 . V_69 = & V_73 ;
V_69 . V_79 = 1 ;
V_69 . V_77 = & V_73 ;
V_73 . V_74 = 0 ;
V_73 . V_75 = 0 ;
V_73 . V_39 = V_45 | V_131 ;
V_11 = F_39 ( V_67 , & V_69 , & V_130 ,
V_129 , V_111 ) ;
if ( F_40 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_43 ( V_67 , V_129 , V_111 , & V_130 ) ;
if ( F_40 ( V_11 ) ) {
goto V_132;
}
V_11 = F_28 ( V_67 , true , V_111 , V_107 , V_108 ) ;
if ( F_40 ( V_11 ) ) {
goto V_132;
}
V_132:
F_44 ( V_67 , & V_130 ) ;
return V_11 ;
}
static int F_46 ( struct V_66 * V_67 ,
bool V_110 , bool V_129 ,
bool V_111 ,
struct V_106 * V_107 )
{
struct V_4 * V_5 ;
struct V_70 * V_71 ;
struct V_106 * V_108 = & V_67 -> V_81 ;
int V_11 ;
V_71 = F_19 ( V_67 , struct V_70 , V_80 ) ;
if ( F_47 ( V_71 -> V_133 > 0 ) )
return - V_65 ;
V_5 = F_16 ( V_67 -> V_38 ) ;
if ( V_108 -> V_82 == V_42 && V_67 -> V_101 == NULL ) {
F_24 ( V_67 , V_107 ) ;
return 0 ;
}
if ( ( V_108 -> V_82 == V_48 &&
V_107 -> V_82 == V_42 ) ||
( V_108 -> V_82 == V_42 &&
V_107 -> V_82 == V_48 ) ) {
F_24 ( V_67 , V_107 ) ;
return 0 ;
}
if ( V_5 -> V_12 . V_83 == NULL ||
V_5 -> V_12 . V_30 == NULL ||
! V_5 -> V_12 . V_30 -> V_84 ) {
goto memcpy;
}
if ( V_108 -> V_82 == V_55 &&
V_107 -> V_82 == V_42 ) {
V_11 = F_38 ( V_67 , V_110 , V_129 ,
V_111 , V_107 ) ;
} else if ( V_108 -> V_82 == V_42 &&
V_107 -> V_82 == V_55 ) {
V_11 = F_45 ( V_67 , V_110 , V_129 ,
V_111 , V_107 ) ;
} else {
V_11 = F_28 ( V_67 , V_110 , V_111 , V_107 , V_108 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_48 ( V_67 , V_129 , V_111 , V_107 ) ;
if ( V_11 ) {
return V_11 ;
}
}
if ( V_67 -> type == V_134 &&
V_107 -> V_82 == V_55 &&
V_108 -> V_82 != V_55 ) {
V_71 -> V_39 &= ~ V_88 ;
}
F_49 ( ( V_123 ) V_67 -> V_94 << V_89 , & V_5 -> V_135 ) ;
return 0 ;
}
static int F_50 ( struct V_37 * V_38 , struct V_106 * V_81 )
{
struct V_40 * V_41 = & V_38 -> V_41 [ V_81 -> V_82 ] ;
struct V_4 * V_5 = F_16 ( V_38 ) ;
V_81 -> V_136 . V_109 = NULL ;
V_81 -> V_136 . V_137 = 0 ;
V_81 -> V_136 . V_17 = V_81 -> V_94 << V_89 ;
V_81 -> V_136 . V_138 = 0 ;
V_81 -> V_136 . V_139 = false ;
if ( ! ( V_41 -> V_39 & V_43 ) )
return - V_65 ;
switch ( V_81 -> V_82 ) {
case V_42 :
return 0 ;
case V_48 :
break;
case V_55 :
V_81 -> V_136 . V_137 = V_81 -> V_95 << V_89 ;
if ( ( V_81 -> V_136 . V_137 + V_81 -> V_136 . V_17 ) > V_5 -> V_52 . V_86 )
return - V_65 ;
V_81 -> V_136 . V_138 = V_5 -> V_52 . V_140 ;
V_81 -> V_136 . V_139 = true ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static void F_51 ( struct V_37 * V_38 , struct V_106 * V_81 )
{
}
static unsigned long F_52 ( struct V_66 * V_67 ,
unsigned long V_141 )
{
struct V_90 * V_142 = V_67 -> V_81 . V_92 ;
T_2 V_17 = V_142 -> V_17 ;
T_2 V_137 = V_141 ;
V_141 = F_53 ( V_137 , V_17 ) ;
V_142 += V_137 ;
return ( V_67 -> V_81 . V_136 . V_138 >> V_89 ) + V_142 -> V_95 + V_141 ;
}
int F_54 ( struct V_143 * V_101 , struct V_144 * * V_145 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
unsigned int V_39 = 0 ;
unsigned V_147 = 0 ;
int V_11 ;
if ( ! ( V_96 -> V_148 & V_149 ) )
V_39 |= V_150 ;
if ( V_96 -> V_148 & V_151 ) {
unsigned long V_152 = V_96 -> V_153 + V_101 -> V_94 * V_120 ;
struct V_154 * V_155 ;
V_155 = F_55 ( V_96 -> V_156 , V_96 -> V_153 ) ;
if ( ! V_155 || V_155 -> V_157 || V_155 -> V_158 < V_152 )
return - V_102 ;
}
do {
unsigned V_94 = V_101 -> V_94 - V_147 ;
T_2 V_153 = V_96 -> V_153 + V_147 * V_120 ;
struct V_144 * * V_159 = V_145 + V_147 ;
struct V_160 V_161 ;
V_161 . V_162 = V_163 ;
F_56 ( & V_96 -> V_164 ) ;
F_57 ( & V_161 . V_165 , & V_96 -> V_166 ) ;
F_58 ( & V_96 -> V_164 ) ;
V_11 = F_59 ( V_153 , V_94 , V_39 , V_159 , NULL ) ;
F_56 ( & V_96 -> V_164 ) ;
F_60 ( & V_161 . V_165 ) ;
F_58 ( & V_96 -> V_164 ) ;
if ( V_11 < 0 )
goto V_167;
V_147 += V_11 ;
} while ( V_147 < V_101 -> V_94 );
return 0 ;
V_167:
V_167 ( V_145 , V_147 , 0 ) ;
return V_11 ;
}
static void F_61 ( struct V_143 * V_101 )
{
struct V_4 * V_5 = F_16 ( V_101 -> V_38 ) ;
struct V_146 * V_96 = ( void * ) V_101 ;
unsigned V_168 ;
if ( F_40 ( F_62 () ) ) {
for ( V_168 = 0 ; V_168 < V_101 -> V_94 ; V_168 ++ ) {
F_63 (
V_5 ,
V_96 -> V_101 . V_169 [ V_168 ] ,
F_64 ( V_101 -> V_145 [ V_168 ] ) ) ;
}
}
}
static void F_65 ( struct V_143 * V_101 )
{
struct V_4 * V_5 = F_16 ( V_101 -> V_38 ) ;
struct V_146 * V_96 = ( void * ) V_101 ;
unsigned V_168 ;
if ( F_40 ( F_66 () ) ) {
for ( V_168 = 0 ; V_168 < V_101 -> V_94 ; V_168 ++ ) {
F_67 (
V_5 ,
V_96 -> V_101 . V_169 [ V_168 ] ,
F_64 ( V_101 -> V_145 [ V_168 ] ) ) ;
}
}
}
static int F_68 ( struct V_143 * V_101 )
{
struct V_4 * V_5 = F_16 ( V_101 -> V_38 ) ;
struct V_146 * V_96 = ( void * ) V_101 ;
unsigned V_170 ;
int V_11 ;
int V_171 = ! ( V_96 -> V_148 & V_149 ) ;
enum V_172 V_173 = V_171 ?
V_174 : V_175 ;
V_11 = F_69 ( V_101 -> V_176 , V_101 -> V_145 , V_101 -> V_94 , 0 ,
V_101 -> V_94 << V_89 ,
V_177 ) ;
if ( V_11 )
goto V_178;
V_11 = - V_179 ;
V_170 = F_70 ( V_5 -> V_180 , V_101 -> V_176 -> V_181 , V_101 -> V_176 -> V_170 , V_173 ) ;
if ( V_170 != V_101 -> V_176 -> V_170 )
goto V_178;
F_71 ( V_101 -> V_176 , V_101 -> V_145 ,
V_96 -> V_101 . V_169 , V_101 -> V_94 ) ;
F_61 ( V_101 ) ;
return 0 ;
V_178:
F_72 ( V_101 -> V_176 ) ;
return V_11 ;
}
static void F_73 ( struct V_143 * V_101 )
{
struct V_4 * V_5 = F_16 ( V_101 -> V_38 ) ;
struct V_146 * V_96 = ( void * ) V_101 ;
struct V_182 V_183 ;
int V_171 = ! ( V_96 -> V_148 & V_149 ) ;
enum V_172 V_173 = V_171 ?
V_174 : V_175 ;
if ( ! V_101 -> V_176 -> V_181 )
return;
F_74 ( V_5 -> V_180 , V_101 -> V_176 -> V_181 , V_101 -> V_176 -> V_170 , V_173 ) ;
F_75 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_144 * V_144 = F_76 ( & V_183 ) ;
if ( ! ( V_96 -> V_148 & V_149 ) )
F_77 ( V_144 ) ;
F_78 ( V_144 ) ;
F_79 ( V_144 ) ;
}
F_65 ( V_101 ) ;
F_80 ( V_101 -> V_176 ) ;
}
static int F_81 ( struct V_143 * V_101 ,
struct V_106 * V_184 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
T_2 V_39 ;
int V_11 = 0 ;
if ( V_96 -> V_153 ) {
V_11 = F_68 ( V_101 ) ;
if ( V_11 ) {
F_7 ( L_7 ) ;
return V_11 ;
}
}
if ( ! V_101 -> V_94 ) {
F_82 ( 1 , L_8 ,
V_101 -> V_94 , V_184 , V_101 ) ;
}
if ( V_184 -> V_82 == V_61 ||
V_184 -> V_82 == V_62 ||
V_184 -> V_82 == V_63 )
return - V_65 ;
if ( ! F_27 ( V_184 ) )
return 0 ;
F_56 ( & V_96 -> V_5 -> V_185 ) ;
V_39 = F_83 ( V_96 -> V_5 , V_101 , V_184 ) ;
V_96 -> V_137 = ( V_123 ) V_184 -> V_95 << V_89 ;
V_11 = F_84 ( V_96 -> V_5 , V_96 -> V_137 , V_101 -> V_94 ,
V_101 -> V_145 , V_96 -> V_101 . V_169 , V_39 ) ;
if ( V_11 ) {
F_7 ( L_9 ,
V_101 -> V_94 , V_96 -> V_137 ) ;
goto V_186;
}
F_85 ( & V_96 -> V_165 , & V_96 -> V_5 -> V_187 ) ;
V_186:
F_58 ( & V_96 -> V_5 -> V_185 ) ;
return V_11 ;
}
bool F_86 ( struct V_143 * V_101 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
return V_96 && ! F_87 ( & V_96 -> V_165 ) ;
}
int F_88 ( struct V_66 * V_67 , struct V_106 * V_184 )
{
struct V_4 * V_5 = F_16 ( V_67 -> V_38 ) ;
struct V_143 * V_101 = V_67 -> V_101 ;
struct V_106 V_188 ;
struct V_68 V_69 ;
struct V_72 V_73 ;
int V_11 ;
if ( ! V_101 || F_86 ( V_101 ) )
return 0 ;
V_188 = V_67 -> V_81 ;
V_188 . V_92 = NULL ;
V_69 . V_78 = 1 ;
V_69 . V_69 = & V_73 ;
V_69 . V_79 = 1 ;
V_69 . V_77 = & V_73 ;
V_73 . V_74 = 0 ;
V_73 . V_75 = V_5 -> V_52 . V_189 >> V_89 ;
V_73 . V_39 = V_67 -> V_81 . V_69 | V_131 ;
V_11 = F_39 ( V_67 , & V_69 , & V_188 , true , false ) ;
if ( F_40 ( V_11 ) )
return V_11 ;
V_11 = F_43 ( V_67 , true , false , & V_188 ) ;
if ( F_40 ( V_11 ) )
F_44 ( V_67 , & V_188 ) ;
else
V_67 -> V_137 = ( V_67 -> V_81 . V_95 << V_89 ) +
V_67 -> V_38 -> V_41 [ V_67 -> V_81 . V_82 ] . V_51 ;
return V_11 ;
}
int F_89 ( struct V_4 * V_5 )
{
struct V_146 * V_96 , * V_188 ;
struct V_106 V_184 ;
T_2 V_39 ;
int V_11 ;
V_184 . V_82 = V_48 ;
F_56 ( & V_5 -> V_185 ) ;
F_90 (gtt, tmp, &adev->gtt_list, list) {
V_39 = F_83 ( V_96 -> V_5 , & V_96 -> V_101 . V_101 , & V_184 ) ;
V_11 = F_84 ( V_5 , V_96 -> V_137 , V_96 -> V_101 . V_101 . V_94 ,
V_96 -> V_101 . V_101 . V_145 , V_96 -> V_101 . V_169 ,
V_39 ) ;
if ( V_11 ) {
F_58 ( & V_5 -> V_185 ) ;
F_7 ( L_9 ,
V_96 -> V_101 . V_101 . V_94 , V_96 -> V_137 ) ;
return V_11 ;
}
}
F_58 ( & V_5 -> V_185 ) ;
return 0 ;
}
static int F_91 ( struct V_143 * V_101 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
int V_11 ;
if ( V_96 -> V_153 )
F_73 ( V_101 ) ;
if ( ! F_86 ( V_101 ) )
return 0 ;
F_56 ( & V_96 -> V_5 -> V_185 ) ;
V_11 = F_92 ( V_96 -> V_5 , V_96 -> V_137 , V_101 -> V_94 ) ;
if ( V_11 ) {
F_7 ( L_10 ,
V_96 -> V_101 . V_101 . V_94 , V_96 -> V_137 ) ;
goto V_190;
}
F_93 ( & V_96 -> V_165 ) ;
V_190:
F_58 ( & V_96 -> V_5 -> V_185 ) ;
return V_11 ;
}
static void F_94 ( struct V_143 * V_101 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
F_95 ( & V_96 -> V_101 ) ;
F_72 ( V_96 ) ;
}
static struct V_143 * F_96 ( struct V_37 * V_38 ,
unsigned long V_17 , T_1 V_191 ,
struct V_144 * V_192 )
{
struct V_4 * V_5 ;
struct V_146 * V_96 ;
V_5 = F_16 ( V_38 ) ;
V_96 = F_97 ( sizeof( struct V_146 ) , V_177 ) ;
if ( V_96 == NULL ) {
return NULL ;
}
V_96 -> V_101 . V_101 . V_49 = & V_193 ;
V_96 -> V_5 = V_5 ;
if ( F_98 ( & V_96 -> V_101 , V_38 , V_17 , V_191 , V_192 ) ) {
F_72 ( V_96 ) ;
return NULL ;
}
F_99 ( & V_96 -> V_165 ) ;
return & V_96 -> V_101 . V_101 ;
}
static int F_100 ( struct V_143 * V_101 )
{
struct V_4 * V_5 = F_16 ( V_101 -> V_38 ) ;
struct V_146 * V_96 = ( void * ) V_101 ;
unsigned V_168 ;
int V_11 ;
bool V_194 = ! ! ( V_101 -> V_191 & V_195 ) ;
if ( V_101 -> V_196 != V_197 )
return 0 ;
if ( V_96 && V_96 -> V_153 ) {
V_101 -> V_176 = F_97 ( sizeof( struct V_198 ) , V_177 ) ;
if ( ! V_101 -> V_176 )
return - V_179 ;
V_101 -> V_191 |= V_195 ;
V_101 -> V_196 = V_199 ;
return 0 ;
}
if ( V_194 && V_101 -> V_176 ) {
F_71 ( V_101 -> V_176 , V_101 -> V_145 ,
V_96 -> V_101 . V_169 , V_101 -> V_94 ) ;
V_101 -> V_196 = V_199 ;
V_11 = 0 ;
goto V_200;
}
#ifdef F_101
if ( F_102 () ) {
V_11 = F_103 ( & V_96 -> V_101 , V_5 -> V_180 ) ;
goto V_200;
}
#endif
V_11 = F_104 ( V_101 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_168 = 0 ; V_168 < V_101 -> V_94 ; V_168 ++ ) {
V_96 -> V_101 . V_169 [ V_168 ] = F_105 ( V_5 -> V_201 , V_101 -> V_145 [ V_168 ] ,
0 , V_120 ,
V_202 ) ;
if ( F_106 ( V_5 -> V_201 , V_96 -> V_101 . V_169 [ V_168 ] ) ) {
while ( V_168 -- ) {
F_107 ( V_5 -> V_201 , V_96 -> V_101 . V_169 [ V_168 ] ,
V_120 , V_202 ) ;
V_96 -> V_101 . V_169 [ V_168 ] = 0 ;
}
F_108 ( V_101 ) ;
return - V_203 ;
}
}
V_11 = 0 ;
V_200:
if ( F_109 ( ! V_11 ) )
F_61 ( V_101 ) ;
return V_11 ;
}
static void F_110 ( struct V_143 * V_101 )
{
struct V_4 * V_5 ;
struct V_146 * V_96 = ( void * ) V_101 ;
unsigned V_168 ;
bool V_194 = ! ! ( V_101 -> V_191 & V_195 ) ;
if ( V_96 && V_96 -> V_153 ) {
F_72 ( V_101 -> V_176 ) ;
V_101 -> V_191 &= ~ V_195 ;
return;
}
if ( V_194 )
return;
V_5 = F_16 ( V_101 -> V_38 ) ;
F_65 ( V_101 ) ;
#ifdef F_101
if ( F_102 () ) {
F_111 ( & V_96 -> V_101 , V_5 -> V_180 ) ;
return;
}
#endif
for ( V_168 = 0 ; V_168 < V_101 -> V_94 ; V_168 ++ ) {
if ( V_96 -> V_101 . V_169 [ V_168 ] ) {
F_107 ( V_5 -> V_201 , V_96 -> V_101 . V_169 [ V_168 ] ,
V_120 , V_202 ) ;
}
}
F_108 ( V_101 ) ;
}
int F_112 ( struct V_143 * V_101 , T_2 V_109 ,
T_1 V_39 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
if ( V_96 == NULL )
return - V_65 ;
V_96 -> V_153 = V_109 ;
V_96 -> V_156 = V_163 -> V_142 ;
V_96 -> V_148 = V_39 ;
F_113 ( & V_96 -> V_164 ) ;
F_99 ( & V_96 -> V_166 ) ;
F_114 ( & V_96 -> V_204 , 0 ) ;
return 0 ;
}
struct V_205 * F_22 ( struct V_143 * V_101 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
if ( V_96 == NULL )
return NULL ;
return V_96 -> V_156 ;
}
bool F_115 ( struct V_143 * V_101 , unsigned long V_95 ,
unsigned long V_152 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
struct V_160 * V_206 ;
unsigned long V_17 ;
if ( V_96 == NULL || ! V_96 -> V_153 )
return false ;
V_17 = ( unsigned long ) V_96 -> V_101 . V_101 . V_94 * V_120 ;
if ( V_96 -> V_153 > V_152 || V_96 -> V_153 + V_17 <= V_95 )
return false ;
F_56 ( & V_96 -> V_164 ) ;
F_116 (entry, &gtt->guptasks, list) {
if ( V_206 -> V_162 == V_163 ) {
F_58 ( & V_96 -> V_164 ) ;
return false ;
}
}
F_58 ( & V_96 -> V_164 ) ;
F_117 ( & V_96 -> V_204 ) ;
return true ;
}
bool F_118 ( struct V_143 * V_101 ,
int * V_207 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
int V_208 = * V_207 ;
* V_207 = F_119 ( & V_96 -> V_204 ) ;
return V_208 != * V_207 ;
}
bool F_120 ( struct V_143 * V_101 )
{
struct V_146 * V_96 = ( void * ) V_101 ;
if ( V_96 == NULL )
return false ;
return ! ! ( V_96 -> V_148 & V_149 ) ;
}
T_2 F_83 ( struct V_4 * V_5 , struct V_143 * V_101 ,
struct V_106 * V_81 )
{
T_2 V_39 = 0 ;
if ( V_81 && V_81 -> V_82 != V_42 )
V_39 |= V_209 ;
if ( V_81 && V_81 -> V_82 == V_48 ) {
V_39 |= V_210 ;
if ( V_101 -> V_211 == V_212 )
V_39 |= V_213 ;
}
V_39 |= V_5 -> V_214 . V_215 ;
V_39 |= V_216 ;
if ( ! F_120 ( V_101 ) )
V_39 |= V_217 ;
return V_39 ;
}
static bool F_121 ( struct V_66 * V_67 ,
const struct V_72 * V_218 )
{
unsigned long V_94 = V_67 -> V_81 . V_94 ;
struct V_90 * V_91 = V_67 -> V_81 . V_92 ;
if ( V_67 -> V_81 . V_95 != V_219 )
return F_122 ( V_67 , V_218 ) ;
switch ( V_67 -> V_81 . V_82 ) {
case V_48 :
return true ;
case V_55 :
while ( V_94 ) {
if ( V_218 -> V_74 < ( V_91 -> V_95 + V_91 -> V_17 ) &&
! ( V_218 -> V_75 && V_218 -> V_75 <= V_91 -> V_95 ) )
return true ;
V_94 -= V_91 -> V_17 ;
++ V_91 ;
}
break;
default:
break;
}
return F_122 ( V_67 , V_218 ) ;
}
static int F_123 ( struct V_66 * V_67 ,
unsigned long V_137 ,
void * V_220 , int V_221 , int V_171 )
{
struct V_70 * V_71 = F_19 ( V_67 , struct V_70 , V_80 ) ;
struct V_4 * V_5 = F_16 ( V_71 -> V_80 . V_38 ) ;
struct V_90 * V_222 = V_71 -> V_80 . V_81 . V_92 ;
T_1 V_223 = 0 ;
int V_224 = 0 ;
T_2 V_225 ;
unsigned long V_39 ;
if ( V_67 -> V_81 . V_82 != V_55 )
return - V_226 ;
while ( V_137 >= ( V_222 -> V_17 << V_89 ) ) {
V_137 -= V_222 -> V_17 << V_89 ;
++ V_222 ;
}
V_225 = ( V_222 -> V_95 << V_89 ) + V_137 ;
while ( V_221 && V_225 < V_5 -> V_52 . V_227 ) {
T_2 V_228 = V_225 & ~ ( T_2 ) 3 ;
T_1 V_229 = 4 - ( V_225 & 3 ) ;
T_1 V_230 = ( V_225 & 3 ) * 8 ;
T_1 V_231 = 0xffffffff << V_230 ;
if ( V_221 < V_229 ) {
V_231 &= 0xffffffff >> ( V_229 - V_221 ) * 8 ;
V_229 = V_221 ;
}
F_124 ( & V_5 -> V_232 , V_39 ) ;
F_125 ( V_233 , ( ( T_1 ) V_228 ) | 0x80000000 ) ;
F_125 ( V_234 , V_228 >> 31 ) ;
if ( ! V_171 || V_231 != 0xffffffff )
V_223 = F_126 ( V_235 ) ;
if ( V_171 ) {
V_223 &= ~ V_231 ;
V_223 |= ( * ( T_1 * ) V_220 << V_230 ) & V_231 ;
F_125 ( V_235 , V_223 ) ;
}
F_127 ( & V_5 -> V_232 , V_39 ) ;
if ( ! V_171 ) {
V_223 = ( V_223 & V_231 ) >> V_230 ;
memcpy ( V_220 , & V_223 , V_229 ) ;
}
V_224 += V_229 ;
V_220 = ( V_236 * ) V_220 + V_229 ;
V_225 += V_229 ;
V_221 -= V_229 ;
if ( V_225 >= ( V_222 -> V_95 + V_222 -> V_17 ) << V_89 ) {
++ V_222 ;
V_225 = ( V_222 -> V_95 << V_89 ) ;
}
}
return V_224 ;
}
int F_128 ( struct V_4 * V_5 )
{
T_2 V_237 ;
int V_11 ;
V_123 V_238 ;
V_11 = F_5 ( V_5 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_129 ( & V_5 -> V_12 . V_38 ,
V_5 -> V_12 . V_22 . V_2 . V_3 ,
& V_239 ,
V_5 -> V_240 -> V_241 -> V_242 ,
V_243 ,
V_5 -> V_244 ) ;
if ( V_11 ) {
F_7 ( L_11 , V_11 ) ;
return V_11 ;
}
V_5 -> V_12 . V_245 = true ;
V_11 = F_130 ( & V_5 -> V_12 . V_38 , V_55 ,
V_5 -> V_52 . V_87 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_12 ) ;
return V_11 ;
}
V_238 = ( V_123 ) V_246 * 1024 * 1024 ;
if ( V_246 > 0 &&
V_238 <= V_5 -> V_52 . V_86 )
V_5 -> V_52 . V_86 = V_238 ;
F_131 ( V_5 , V_5 -> V_52 . V_86 ) ;
V_11 = F_132 ( V_5 , V_5 -> V_52 . V_247 , V_120 ,
V_97 ,
& V_5 -> V_248 ,
NULL , NULL ) ;
if ( V_11 )
return V_11 ;
F_133 ( L_13 ,
( unsigned ) ( V_5 -> V_52 . V_87 / ( 1024 * 1024 ) ) ) ;
if ( V_249 == - 1 )
V_237 = F_134 ( ( V_250 << 20 ) ,
V_5 -> V_52 . V_227 ) ;
else
V_237 = ( T_2 ) V_249 << 20 ;
V_11 = F_130 ( & V_5 -> V_12 . V_38 , V_48 , V_237 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_14 ) ;
return V_11 ;
}
F_133 ( L_15 ,
( unsigned ) ( V_237 / ( 1024 * 1024 ) ) ) ;
V_5 -> V_251 . V_81 . V_252 = V_5 -> V_251 . V_81 . V_252 << V_253 ;
V_5 -> V_251 . V_81 . V_254 = V_5 -> V_251 . V_81 . V_254 << V_253 ;
V_5 -> V_251 . V_81 . V_255 = V_5 -> V_251 . V_81 . V_255 << V_253 ;
V_5 -> V_251 . V_256 . V_252 = V_5 -> V_251 . V_256 . V_252 << V_257 ;
V_5 -> V_251 . V_256 . V_254 = V_5 -> V_251 . V_256 . V_254 << V_257 ;
V_5 -> V_251 . V_256 . V_255 = V_5 -> V_251 . V_256 . V_255 << V_257 ;
V_5 -> V_251 . V_258 . V_252 = V_5 -> V_251 . V_258 . V_252 << V_259 ;
V_5 -> V_251 . V_258 . V_254 = V_5 -> V_251 . V_258 . V_254 << V_259 ;
V_5 -> V_251 . V_258 . V_255 = V_5 -> V_251 . V_258 . V_255 << V_259 ;
if ( V_5 -> V_251 . V_81 . V_252 ) {
V_11 = F_130 ( & V_5 -> V_12 . V_38 , V_61 ,
V_5 -> V_251 . V_81 . V_252 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_16 ) ;
return V_11 ;
}
}
if ( V_5 -> V_251 . V_256 . V_252 ) {
V_11 = F_130 ( & V_5 -> V_12 . V_38 , V_62 ,
V_5 -> V_251 . V_256 . V_252 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_17 ) ;
return V_11 ;
}
}
if ( V_5 -> V_251 . V_258 . V_252 ) {
V_11 = F_130 ( & V_5 -> V_12 . V_38 , V_63 ,
V_5 -> V_251 . V_258 . V_252 >> V_89 ) ;
if ( V_11 ) {
F_7 ( L_18 ) ;
return V_11 ;
}
}
V_11 = F_135 ( V_5 ) ;
if ( V_11 ) {
F_7 ( L_19 ) ;
return V_11 ;
}
return 0 ;
}
void F_136 ( struct V_4 * V_5 )
{
int V_11 ;
if ( ! V_5 -> V_12 . V_245 )
return;
F_137 ( V_5 ) ;
if ( V_5 -> V_248 ) {
V_11 = F_138 ( V_5 -> V_248 , true ) ;
if ( V_11 == 0 ) {
F_139 ( V_5 -> V_248 ) ;
F_140 ( V_5 -> V_248 ) ;
}
F_141 ( & V_5 -> V_248 ) ;
}
F_142 ( & V_5 -> V_12 . V_38 , V_55 ) ;
F_142 ( & V_5 -> V_12 . V_38 , V_48 ) ;
if ( V_5 -> V_251 . V_81 . V_252 )
F_142 ( & V_5 -> V_12 . V_38 , V_61 ) ;
if ( V_5 -> V_251 . V_256 . V_252 )
F_142 ( & V_5 -> V_12 . V_38 , V_62 ) ;
if ( V_5 -> V_251 . V_258 . V_252 )
F_142 ( & V_5 -> V_12 . V_38 , V_63 ) ;
F_143 ( & V_5 -> V_12 . V_38 ) ;
F_144 ( V_5 ) ;
F_11 ( V_5 ) ;
V_5 -> V_12 . V_245 = false ;
F_133 ( L_20 ) ;
}
void F_131 ( struct V_4 * V_5 , V_123 V_17 )
{
struct V_40 * V_41 ;
if ( ! V_5 -> V_12 . V_245 )
return;
V_41 = & V_5 -> V_12 . V_38 . V_41 [ V_55 ] ;
V_41 -> V_17 = V_17 >> V_89 ;
}
int F_145 ( struct V_99 * V_100 , struct V_154 * V_155 )
{
struct V_260 * V_261 ;
struct V_4 * V_5 ;
if ( F_40 ( V_155 -> V_262 < V_243 ) )
return - V_65 ;
V_261 = V_100 -> V_105 ;
V_5 = V_261 -> V_263 -> V_180 -> V_264 ;
if ( V_5 == NULL )
return - V_65 ;
return F_146 ( V_100 , V_155 , & V_5 -> V_12 . V_38 ) ;
}
static int F_32 ( struct V_66 * V_67 ,
struct V_106 * V_81 , unsigned V_94 ,
T_2 V_137 , unsigned V_265 ,
struct V_7 * V_8 ,
T_2 * V_109 )
{
struct V_146 * V_96 = ( void * ) V_67 -> V_101 ;
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_143 * V_101 = V_67 -> V_101 ;
struct V_266 * V_267 ;
unsigned V_268 , V_269 ;
T_3 * V_169 ;
struct V_118 * V_119 ;
T_2 V_270 , V_271 ;
T_2 V_39 ;
int V_11 ;
F_25 ( V_5 -> V_12 . V_83 -> V_272 <
V_124 * 8 ) ;
* V_109 = V_5 -> V_52 . V_53 ;
* V_109 += ( V_123 ) V_265 * V_124 *
V_121 ;
V_268 = V_5 -> V_12 . V_83 -> V_273 ;
while ( V_268 & 0x7 )
V_268 ++ ;
V_269 = V_94 * 8 ;
V_11 = F_147 ( V_5 , V_268 * 4 + V_269 , & V_267 ) ;
if ( V_11 )
return V_11 ;
V_270 = V_268 * 4 ;
V_270 += V_267 -> V_274 [ 0 ] . V_275 ;
V_271 = V_5 -> V_214 . V_276 ;
V_271 += V_265 * V_124 * 8 ;
F_148 ( V_5 , & V_267 -> V_274 [ 0 ] , V_270 ,
V_271 , V_269 ) ;
F_149 ( V_8 , & V_267 -> V_274 [ 0 ] ) ;
F_150 ( V_267 -> V_274 [ 0 ] . V_277 > V_268 ) ;
V_169 = & V_96 -> V_101 . V_169 [ V_137 >> V_89 ] ;
V_39 = F_83 ( V_5 , V_101 , V_81 ) ;
V_11 = F_151 ( V_5 , 0 , V_94 , V_169 , V_39 ,
& V_267 -> V_274 [ 0 ] . V_278 [ V_268 ] ) ;
if ( V_11 )
goto V_279;
V_11 = F_152 ( V_267 , V_8 , & V_5 -> V_12 . V_34 ,
V_280 , & V_119 ) ;
if ( V_11 )
goto V_279;
F_34 ( V_119 ) ;
return V_11 ;
V_279:
F_153 ( V_267 ) ;
return V_11 ;
}
int F_33 ( struct V_7 * V_8 , T_2 V_281 ,
T_2 V_282 , T_1 V_283 ,
struct V_284 * V_128 ,
struct V_118 * * V_119 , bool V_285 ,
bool V_286 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_266 * V_267 ;
T_1 V_287 ;
unsigned V_288 , V_268 ;
unsigned V_168 ;
int V_11 ;
V_287 = V_5 -> V_12 . V_83 -> V_272 ;
V_288 = F_154 ( V_283 , V_287 ) ;
V_268 = V_288 * V_5 -> V_12 . V_83 -> V_273 ;
while ( V_268 & 0x7 )
V_268 ++ ;
V_11 = F_147 ( V_5 , V_268 * 4 , & V_267 ) ;
if ( V_11 )
return V_11 ;
V_267 -> V_286 = V_286 ;
if ( V_128 ) {
V_11 = F_155 ( V_5 , & V_267 -> V_289 , V_128 ,
V_280 ) ;
if ( V_11 ) {
F_7 ( L_21 , V_11 ) ;
goto V_279;
}
}
for ( V_168 = 0 ; V_168 < V_288 ; V_168 ++ ) {
T_1 V_290 = F_31 ( V_283 , V_287 ) ;
F_148 ( V_5 , & V_267 -> V_274 [ 0 ] , V_281 ,
V_282 , V_290 ) ;
V_281 += V_290 ;
V_282 += V_290 ;
V_283 -= V_290 ;
}
F_149 ( V_8 , & V_267 -> V_274 [ 0 ] ) ;
F_150 ( V_267 -> V_274 [ 0 ] . V_277 > V_268 ) ;
if ( V_285 ) {
V_11 = F_156 ( V_8 , V_267 -> V_291 , V_267 -> V_274 ,
NULL , V_119 ) ;
V_267 -> V_119 = F_157 ( * V_119 ) ;
if ( V_11 )
F_7 ( L_22 , V_11 ) ;
F_153 ( V_267 ) ;
} else {
V_11 = F_152 ( V_267 , V_8 , & V_5 -> V_12 . V_34 ,
V_280 , V_119 ) ;
if ( V_11 )
goto V_279;
}
return V_11 ;
V_279:
F_153 ( V_267 ) ;
return V_11 ;
}
int F_158 ( struct V_70 * V_67 ,
T_2 V_292 ,
struct V_284 * V_128 ,
struct V_118 * * V_119 )
{
struct V_4 * V_5 = F_16 ( V_67 -> V_80 . V_38 ) ;
T_1 V_287 = V_5 -> V_12 . V_83 -> V_293 ;
struct V_7 * V_8 = V_5 -> V_12 . V_30 ;
struct V_90 * V_92 ;
unsigned long V_94 ;
unsigned int V_288 , V_268 ;
struct V_266 * V_267 ;
int V_11 ;
if ( ! V_8 -> V_84 ) {
F_7 ( L_23 ) ;
return - V_65 ;
}
if ( V_67 -> V_80 . V_81 . V_82 == V_48 ) {
V_11 = F_88 ( & V_67 -> V_80 , & V_67 -> V_80 . V_81 ) ;
if ( V_11 )
return V_11 ;
}
V_94 = V_67 -> V_80 . V_94 ;
V_92 = V_67 -> V_80 . V_81 . V_92 ;
V_288 = 0 ;
while ( V_94 ) {
T_1 V_283 = V_92 -> V_17 << V_89 ;
V_288 += F_154 ( V_283 , V_287 ) ;
V_94 -= V_92 -> V_17 ;
++ V_92 ;
}
V_268 = V_288 * 10 ;
V_268 += 64 ;
V_11 = F_147 ( V_5 , V_268 * 4 , & V_267 ) ;
if ( V_11 )
return V_11 ;
if ( V_128 ) {
V_11 = F_155 ( V_5 , & V_267 -> V_289 , V_128 ,
V_280 ) ;
if ( V_11 ) {
F_7 ( L_21 , V_11 ) ;
goto V_279;
}
}
V_94 = V_67 -> V_80 . V_94 ;
V_92 = V_67 -> V_80 . V_81 . V_92 ;
while ( V_94 ) {
T_1 V_283 = V_92 -> V_17 << V_89 ;
T_2 V_271 ;
F_159 ( V_283 & 0x7 , L_24 ) ;
V_271 = F_26 ( & V_67 -> V_80 , V_92 , & V_67 -> V_80 . V_81 ) ;
while ( V_283 ) {
T_1 V_290 = F_31 ( V_283 , V_287 ) ;
F_160 ( V_5 , & V_267 -> V_274 [ 0 ] ,
V_271 , 0 ,
V_290 >> 3 , 0 ,
V_292 ) ;
V_271 += V_290 ;
V_283 -= V_290 ;
}
V_94 -= V_92 -> V_17 ;
++ V_92 ;
}
F_149 ( V_8 , & V_267 -> V_274 [ 0 ] ) ;
F_150 ( V_267 -> V_274 [ 0 ] . V_277 > V_268 ) ;
V_11 = F_152 ( V_267 , V_8 , & V_5 -> V_12 . V_34 ,
V_280 , V_119 ) ;
if ( V_11 )
goto V_279;
return 0 ;
V_279:
F_153 ( V_267 ) ;
return V_11 ;
}
static int F_161 ( struct V_294 * V_295 , void * V_296 )
{
struct V_297 * V_91 = (struct V_297 * ) V_295 -> V_298 ;
unsigned V_299 = * ( int * ) V_91 -> V_300 -> V_296 ;
struct V_301 * V_180 = V_91 -> V_263 -> V_180 ;
struct V_4 * V_5 = V_180 -> V_264 ;
struct V_40 * V_41 = & V_5 -> V_12 . V_38 . V_41 [ V_299 ] ;
struct V_302 V_159 = F_162 ( V_295 ) ;
V_41 -> V_49 -> V_303 ( V_41 , & V_159 ) ;
return 0 ;
}
static T_4 F_163 ( struct V_99 * V_304 , char T_5 * V_220 ,
T_6 V_17 , T_7 * V_225 )
{
struct V_4 * V_5 = F_164 ( V_304 ) -> V_305 ;
T_4 V_306 = 0 ;
int V_11 ;
if ( V_17 & 0x3 || * V_225 & 0x3 )
return - V_65 ;
if ( * V_225 >= V_5 -> V_52 . V_227 )
return - V_307 ;
while ( V_17 ) {
unsigned long V_39 ;
T_1 V_223 ;
if ( * V_225 >= V_5 -> V_52 . V_227 )
return V_306 ;
F_124 ( & V_5 -> V_232 , V_39 ) ;
F_125 ( V_233 , ( ( T_1 ) * V_225 ) | 0x80000000 ) ;
F_125 ( V_234 , * V_225 >> 31 ) ;
V_223 = F_126 ( V_235 ) ;
F_127 ( & V_5 -> V_232 , V_39 ) ;
V_11 = F_165 ( V_223 , ( T_1 * ) V_220 ) ;
if ( V_11 )
return V_11 ;
V_306 += 4 ;
V_220 += 4 ;
* V_225 += 4 ;
V_17 -= 4 ;
}
return V_306 ;
}
static T_4 F_166 ( struct V_99 * V_304 , char T_5 * V_220 ,
T_6 V_17 , T_7 * V_225 )
{
struct V_4 * V_5 = F_164 ( V_304 ) -> V_305 ;
T_4 V_306 = 0 ;
int V_11 ;
while ( V_17 ) {
T_7 V_159 = * V_225 / V_120 ;
unsigned V_308 = * V_225 & ~ V_309 ;
T_6 V_310 = F_167 ( T_6 , V_17 , V_120 - V_308 ) ;
struct V_144 * V_144 ;
void * V_278 ;
if ( V_159 >= V_5 -> V_214 . V_311 )
return V_306 ;
V_144 = V_5 -> V_214 . V_145 [ V_159 ] ;
if ( V_144 ) {
V_278 = F_168 ( V_144 ) ;
V_278 += V_308 ;
V_11 = F_169 ( V_220 , V_278 , V_310 ) ;
F_170 ( V_5 -> V_214 . V_145 [ V_159 ] ) ;
} else
V_11 = F_171 ( V_220 , V_310 ) ;
if ( V_11 )
return - V_203 ;
V_306 += V_310 ;
V_220 += V_310 ;
* V_225 += V_310 ;
V_17 -= V_310 ;
}
return V_306 ;
}
static int F_135 ( struct V_4 * V_5 )
{
#if F_172 ( V_312 )
unsigned V_313 ;
struct V_314 * V_263 = V_5 -> V_240 -> V_315 ;
struct V_316 * V_317 , * V_318 = V_263 -> V_319 ;
V_317 = F_173 ( L_25 , V_320 | V_321 , V_318 ,
V_5 , & V_322 ) ;
if ( F_174 ( V_317 ) )
return F_175 ( V_317 ) ;
F_176 ( V_317 -> V_323 , V_5 -> V_52 . V_227 ) ;
V_5 -> V_12 . V_324 = V_317 ;
#ifdef F_177
V_317 = F_173 ( L_26 , V_320 | V_321 , V_318 ,
V_5 , & V_325 ) ;
if ( F_174 ( V_317 ) )
return F_175 ( V_317 ) ;
F_176 ( V_317 -> V_323 , V_5 -> V_52 . V_189 ) ;
V_5 -> V_12 . V_96 = V_317 ;
#endif
V_313 = F_178 ( V_326 ) ;
#ifdef F_101
if ( ! F_102 () )
-- V_313 ;
#endif
return F_179 ( V_5 , V_326 , V_313 ) ;
#else
return 0 ;
#endif
}
static void F_137 ( struct V_4 * V_5 )
{
#if F_172 ( V_312 )
F_180 ( V_5 -> V_12 . V_324 ) ;
V_5 -> V_12 . V_324 = NULL ;
#ifdef F_177
F_180 ( V_5 -> V_12 . V_96 ) ;
V_5 -> V_12 . V_96 = NULL ;
#endif
#endif
}
