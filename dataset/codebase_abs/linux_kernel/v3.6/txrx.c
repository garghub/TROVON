static inline T_1 F_1 ( T_1 V_1 )
{
return V_1 & V_2 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return V_1 >> V_3 ;
}
static T_1 F_3 ( struct V_4 * V_5 , struct V_6 * V_7 ,
T_2 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_11 * V_12 ;
T_2 V_13 , V_14 = - 1 ;
T_1 * V_15 ;
* V_8 = 0 ;
V_15 = V_5 -> V_16 ;
V_12 = (struct V_11 * ) ( V_15 + sizeof( struct V_17 ) ) ;
if ( F_5 ( V_12 -> V_18 ) )
return V_19 ;
for ( V_13 = 0 ; V_13 < V_10 -> V_20 ; V_13 ++ ) {
if ( memcmp ( V_12 -> V_18 , V_10 -> V_21 [ V_13 ] . V_22 ,
V_23 ) == 0 ) {
* V_8 = V_13 + 1 ;
V_10 -> V_21 [ V_13 ] . V_24 ++ ;
return V_10 -> V_21 [ V_13 ] . V_25 ;
}
if ( ( V_14 == - 1 ) && ! V_10 -> V_21 [ V_13 ] . V_24 )
V_14 = V_13 ;
}
if ( V_14 == - 1 ) {
V_14 = V_10 -> V_20 ;
V_10 -> V_20 ++ ;
if ( V_10 -> V_20 > V_26 )
return V_27 ;
}
memcpy ( V_10 -> V_21 [ V_14 ] . V_22 , V_12 -> V_18 , V_23 ) ;
for ( V_13 = V_19 ; V_13 <= V_28 ; V_13 ++ ) {
if ( ! V_10 -> V_29 [ V_13 ] ) {
V_10 -> V_21 [ V_14 ] . V_25 = V_13 ;
break;
}
if ( V_13 == V_28 ) {
V_10 -> V_21 [ V_14 ] . V_25 = V_10 -> V_30 ;
V_10 -> V_30 ++ ;
if ( V_10 -> V_30 > V_28 )
V_10 -> V_30 = V_19 ;
}
}
* V_8 = V_14 + 1 ;
V_10 -> V_21 [ V_14 ] . V_24 ++ ;
return V_10 -> V_21 [ V_14 ] . V_25 ;
}
static bool F_6 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_4 * V_5 ,
T_2 * V_35 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
bool V_36 = false ;
struct V_11 * V_15 = (struct V_11 * ) V_5 -> V_16 ;
T_1 V_37 = 0 , V_38 , * V_39 ;
T_3 V_40 ;
struct V_41 * V_42 ;
if ( V_32 -> V_43 & V_44 ) {
F_7 ( & V_32 -> V_45 ) ;
if ( ! F_8 ( & V_32 -> V_46 ) )
* V_35 |= V_47 ;
else if ( V_32 -> V_43 & V_48 )
* V_35 |= V_49 ;
* V_35 |= V_50 ;
F_9 ( & V_32 -> V_45 ) ;
return false ;
} else if ( ! V_32 -> V_51 )
return false ;
if ( F_10 ( V_52 , & V_34 -> V_35 ) ) {
V_40 = F_11 ( V_15 -> V_53 ) ;
if ( F_12 ( V_40 ) ) {
V_39 = ( T_1 * ) ( V_15 + 1 ) ;
} else {
V_42 = (struct V_41 * )
( V_15 + 1 ) ;
V_40 = F_11 ( V_42 -> V_54 ) ;
V_39 = ( T_1 * ) ( V_42 + 1 ) ;
}
if ( V_40 == V_55 )
V_37 = F_13 (
V_39 , 0 ) ;
}
V_38 = F_14 ( V_37 ) ;
if ( ( V_32 -> V_51 & ( 1 << V_38 ) ) == 0 )
return false ;
F_7 ( & V_32 -> V_45 ) ;
V_36 = F_8 ( & V_32 -> V_46 ) ;
F_15 ( & V_32 -> V_46 , V_5 ) ;
F_9 ( & V_32 -> V_45 ) ;
if ( V_36 ) {
F_16 ( V_10 -> V_56 ,
V_34 -> V_57 ,
V_32 -> V_58 , 1 , 0 ) ;
}
* V_35 |= V_50 ;
return true ;
}
static bool F_17 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_4 * V_5 ,
T_2 * V_35 )
{
bool V_59 = false ;
struct V_9 * V_10 = V_34 -> V_10 ;
if ( V_32 -> V_43 & V_60 ) {
F_7 ( & V_32 -> V_45 ) ;
if ( ! F_8 ( & V_32 -> V_61 ) )
* V_35 |= V_47 ;
F_9 ( & V_32 -> V_45 ) ;
return false ;
}
F_7 ( & V_32 -> V_45 ) ;
V_59 = F_8 ( & V_32 -> V_61 ) ;
F_15 ( & V_32 -> V_61 , V_5 ) ;
F_9 ( & V_32 -> V_45 ) ;
if ( V_59 )
F_18 ( V_10 -> V_56 ,
V_34 -> V_57 ,
V_32 -> V_58 , 1 ) ;
return true ;
}
static bool F_19 ( struct V_33 * V_34 , struct V_4 * V_5 ,
T_2 * V_35 )
{
struct V_11 * V_15 = (struct V_11 * ) V_5 -> V_16 ;
struct V_31 * V_32 = NULL ;
bool V_62 = false ;
struct V_9 * V_10 = V_34 -> V_10 ;
if ( F_5 ( V_15 -> V_18 ) ) {
T_1 V_63 = 0 ;
bool V_64 = false ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
if ( V_10 -> V_66 [ V_63 ] . V_43 & V_67 ) {
V_64 = true ;
break;
}
}
if ( V_64 ) {
if ( ! F_10 ( V_68 , & V_34 -> V_35 ) ) {
bool V_69 = false ;
F_7 ( & V_10 -> V_70 ) ;
V_69 =
F_8 ( & V_10 -> V_71 ) ;
F_15 ( & V_10 -> V_71 , V_5 ) ;
F_9 ( & V_10 -> V_70 ) ;
if ( V_69 )
F_18 ( V_10 -> V_56 ,
V_34 -> V_57 ,
V_72 , 1 ) ;
V_62 = true ;
} else {
F_7 ( & V_10 -> V_70 ) ;
if ( ! F_8 ( & V_10 -> V_71 ) )
* V_35 |= V_47 ;
F_9 ( & V_10 -> V_70 ) ;
}
}
} else {
V_32 = F_20 ( V_34 , V_15 -> V_18 ) ;
if ( ! V_32 ) {
F_21 ( V_5 ) ;
return true ;
}
if ( V_32 -> V_43 & V_67 ) {
V_62 = F_6 ( V_32 ,
V_34 , V_5 , V_35 ) ;
if ( ! ( * V_35 & V_50 ) )
V_62 = F_17 ( V_32 ,
V_34 , V_5 , V_35 ) ;
}
}
return V_62 ;
}
int F_22 ( void * V_73 , struct V_4 * V_5 ,
enum V_74 V_75 )
{
struct V_9 * V_10 = V_73 ;
int V_76 = 0 ;
struct V_77 * V_78 = NULL ;
if ( F_23 ( V_10 -> V_79 == V_80 ) )
return - V_81 ;
F_7 ( & V_10 -> V_82 ) ;
F_24 ( V_83 ,
L_1 , V_84 ,
V_5 , V_5 -> V_85 , V_75 ) ;
if ( F_10 ( V_86 , & V_10 -> V_87 ) && ( V_75 == V_10 -> V_88 ) ) {
V_78 = NULL ;
F_25 ( L_2 ,
V_5 , V_5 -> V_85 ) ;
} else
V_78 = F_26 ( V_10 ) ;
if ( V_78 == NULL ) {
F_9 ( & V_10 -> V_82 ) ;
V_76 = - V_89 ;
goto V_90;
}
V_10 -> V_29 [ V_75 ] ++ ;
if ( V_75 != V_10 -> V_88 )
V_10 -> V_91 ++ ;
F_9 ( & V_10 -> V_82 ) ;
V_78 -> V_5 = V_5 ;
V_78 -> V_8 = 0 ;
F_27 ( & V_78 -> V_92 , V_78 , V_5 -> V_16 , V_5 -> V_85 ,
V_75 , V_93 ) ;
V_78 -> V_92 . V_5 = V_5 ;
F_28 ( V_10 -> V_94 , & V_78 -> V_92 ) ;
return 0 ;
V_90:
F_21 ( V_5 ) ;
return V_76 ;
}
int F_29 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
struct V_77 * V_78 = NULL ;
enum V_74 V_75 = V_27 ;
struct V_33 * V_34 = F_30 ( V_7 ) ;
T_2 V_8 = 0 ;
T_3 V_95 = V_96 ;
T_1 V_97 = 99 ;
bool V_98 = false ;
int V_99 ;
struct V_100 V_101 ;
void * V_102 ;
T_1 V_103 = 0 , V_104 = 0 , V_105 = V_5 -> V_106 ;
T_1 V_107 = 0 ;
T_2 V_35 = 0 ;
F_24 ( V_83 ,
L_3 , V_84 ,
V_5 , V_5 -> V_16 , V_5 -> V_85 ) ;
if ( ! F_10 ( V_108 , & V_34 -> V_35 ) )
goto V_109;
if ( F_23 ( V_10 -> V_79 != V_110 ) )
goto V_109;
if ( ! F_10 ( V_111 , & V_10 -> V_87 ) )
goto V_109;
if ( V_34 -> V_112 == V_113 ) {
if ( F_19 ( V_34 , V_5 , & V_35 ) )
return 0 ;
}
if ( F_10 ( V_114 , & V_10 -> V_87 ) ) {
if ( ( V_7 -> V_115 & V_116 ) &&
( V_105 == V_117 ) ) {
V_103 = V_5 -> V_103 -
( F_31 ( V_5 ) - V_5 -> V_118 ) +
sizeof( struct V_41 ) ;
V_104 = V_5 -> V_119 + V_103 ;
}
if ( F_32 ( V_5 ) < V_7 -> V_120 ) {
struct V_4 * V_121 = V_5 ;
V_5 = F_33 ( V_5 , V_7 -> V_120 ) ;
F_34 ( V_121 ) ;
if ( V_5 == NULL ) {
V_34 -> V_122 . V_123 ++ ;
return 0 ;
}
}
if ( F_35 ( V_10 -> V_56 , V_5 ) ) {
F_25 ( L_4 ) ;
goto V_109;
}
if ( ( V_7 -> V_115 & V_116 ) &&
( V_105 == V_117 ) ) {
V_101 . V_103 = V_103 ;
V_101 . V_104 = V_104 ;
V_101 . V_124 = V_125 ;
V_107 = V_126 ;
V_102 = & V_101 ;
} else {
V_107 = 0 ;
V_102 = NULL ;
}
V_99 = F_36 ( V_10 -> V_56 , V_5 ,
V_127 , V_35 , 0 ,
V_107 ,
V_102 , V_34 -> V_57 ) ;
if ( V_99 ) {
F_37 ( L_5
, V_99 ) ;
goto V_109;
}
if ( ( V_34 -> V_112 == V_128 ) &&
V_10 -> V_129 && F_10 ( V_108 , & V_34 -> V_35 ) )
V_98 = true ;
else {
V_99 = F_38 ( V_10 -> V_56 ,
V_34 -> V_57 , V_5 ,
0 , F_10 ( V_52 , & V_34 -> V_35 ) , & V_97 ) ;
if ( V_99 )
goto V_109;
}
} else
goto V_109;
F_7 ( & V_10 -> V_82 ) ;
if ( V_98 )
V_75 = F_3 ( V_5 , V_7 , & V_8 ) ;
else
V_75 = V_10 -> V_130 [ V_97 ] ;
if ( V_75 == 0 || V_75 == V_27 ) {
F_25 ( L_6 , V_75 ) ;
F_9 ( & V_10 -> V_82 ) ;
goto V_109;
}
V_78 = F_26 ( V_10 ) ;
if ( ! V_78 ) {
F_9 ( & V_10 -> V_82 ) ;
goto V_109;
}
V_10 -> V_29 [ V_75 ] ++ ;
V_10 -> V_91 ++ ;
F_9 ( & V_10 -> V_82 ) ;
if ( ! F_39 ( ( unsigned long ) V_5 -> V_16 - V_131 , 4 ) &&
F_40 ( V_5 ) ) {
struct V_4 * V_132 ;
V_132 = F_41 ( V_5 , V_131 , 0 , V_133 ) ;
if ( V_132 == NULL )
goto V_109;
F_34 ( V_5 ) ;
V_5 = V_132 ;
}
V_78 -> V_5 = V_5 ;
V_78 -> V_8 = V_8 ;
F_27 ( & V_78 -> V_92 , V_78 , V_5 -> V_16 , V_5 -> V_85 ,
V_75 , V_95 ) ;
V_78 -> V_92 . V_5 = V_5 ;
F_42 ( V_134 , V_84 , L_7 ,
V_5 -> V_16 , V_5 -> V_85 ) ;
F_28 ( V_10 -> V_94 , & V_78 -> V_92 ) ;
return 0 ;
V_109:
F_21 ( V_5 ) ;
V_34 -> V_122 . V_123 ++ ;
V_34 -> V_122 . V_135 ++ ;
return 0 ;
}
void F_43 ( void * V_73 , T_1 V_38 , bool V_136 )
{
struct V_9 * V_10 = V_73 ;
enum V_74 V_75 ;
int V_13 ;
V_75 = V_10 -> V_130 [ V_38 ] ;
if ( ! F_10 ( V_114 , & V_10 -> V_87 ) )
goto V_137;
F_7 ( & V_10 -> V_82 ) ;
V_10 -> V_138 [ V_38 ] = V_136 ;
if ( V_136 ) {
if ( V_10 -> V_139 [ V_38 ] >
V_10 -> V_140 )
V_10 -> V_140 =
V_10 -> V_139 [ V_38 ] ;
} else {
if ( V_10 -> V_140 ==
V_10 -> V_139 [ V_38 ] ) {
V_10 -> V_140 = 0 ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
if ( V_10 -> V_138 [ V_13 ] &&
( V_10 -> V_139 [ V_13 ] >
V_10 -> V_140 ) )
V_10 -> V_140 =
V_10 -> V_139 [ V_13 ] ;
}
}
}
F_9 ( & V_10 -> V_82 ) ;
V_137:
F_44 ( V_10 -> V_94 , V_75 , V_136 ) ;
}
enum V_142 F_45 ( struct V_94 * V_143 ,
struct V_144 * V_145 )
{
struct V_9 * V_10 = V_143 -> V_7 -> V_10 ;
struct V_33 * V_34 ;
enum V_74 V_146 = V_145 -> V_146 ;
enum V_142 V_147 = V_148 ;
if ( V_146 == V_10 -> V_88 ) {
F_46 ( V_86 , & V_10 -> V_87 ) ;
F_25 ( L_8 ) ;
return V_147 ;
}
if ( V_145 -> V_149 . V_150 . V_151 == V_93 )
return V_147 ;
if ( V_10 -> V_139 [ V_10 -> V_152 [ V_146 ] ] <
V_10 -> V_140 &&
V_10 -> V_153 <=
V_143 -> V_146 [ V_146 ] . V_154 )
V_147 = V_155 ;
F_7 ( & V_10 -> V_156 ) ;
F_47 (vif, &ar->vif_list, list) {
if ( V_34 -> V_112 == V_128 ||
V_147 != V_155 ) {
F_9 ( & V_10 -> V_156 ) ;
F_46 ( V_157 , & V_34 -> V_35 ) ;
F_48 ( V_34 -> V_158 ) ;
return V_147 ;
}
}
F_9 ( & V_10 -> V_156 ) ;
return V_147 ;
}
static void F_49 ( struct V_33 * V_34 ,
enum V_74 V_75 , T_2 V_8 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
T_2 V_13 ;
if ( V_34 -> V_112 != V_128 )
return;
if ( ! V_10 -> V_129 )
return;
if ( V_75 == V_10 -> V_88 )
return;
if ( V_8 == 0 )
return;
V_8 -- ;
V_10 -> V_21 [ V_8 ] . V_24 -- ;
if ( V_10 -> V_21 [ V_8 ] . V_24 )
return;
if ( V_8 != ( V_10 -> V_20 - 1 ) )
return;
for ( V_13 = V_10 -> V_20 ; V_13 > 0 ; V_13 -- ) {
if ( V_10 -> V_21 [ V_13 - 1 ] . V_24 )
break;
memset ( & V_10 -> V_21 [ V_13 - 1 ] , 0 ,
sizeof( struct V_159 ) ) ;
V_10 -> V_20 -- ;
}
}
void F_50 ( struct V_94 * V_143 ,
struct V_160 * V_161 )
{
struct V_9 * V_10 = V_143 -> V_7 -> V_10 ;
struct V_162 V_163 ;
struct V_144 * V_145 ;
struct V_4 * V_5 ;
struct V_77 * V_77 ;
T_2 V_8 = 0 ;
int V_76 ;
enum V_74 V_75 ;
bool V_164 = false ;
bool V_165 [ V_166 ] = { false } ;
T_1 V_167 ;
struct V_33 * V_34 ;
F_51 ( & V_163 ) ;
F_7 ( & V_10 -> V_82 ) ;
while ( ! F_52 ( V_161 ) ) {
V_145 = F_53 ( V_161 , struct V_144 ,
V_168 ) ;
F_54 ( & V_145 -> V_168 ) ;
V_77 = (struct V_77 * ) V_145 -> V_169 ;
if ( ! V_77 )
goto V_170;
V_76 = V_145 -> V_76 ;
V_5 = V_77 -> V_5 ;
V_75 = V_145 -> V_146 ;
V_8 = V_77 -> V_8 ;
if ( ! V_5 || ! V_5 -> V_16 )
goto V_170;
F_55 ( & V_163 , V_5 ) ;
if ( ! V_76 && ( V_145 -> V_171 != V_5 -> V_85 ) )
goto V_170;
V_10 -> V_29 [ V_75 ] -- ;
if ( V_75 != V_10 -> V_88 )
V_10 -> V_91 -- ;
if ( V_75 == V_10 -> V_88 ) {
if ( F_10 ( V_86 , & V_10 -> V_87 ) )
F_56 ( V_86 , & V_10 -> V_87 ) ;
if ( V_10 -> V_29 [ V_75 ] == 0 )
V_164 = true ;
}
if ( V_75 == V_10 -> V_88 ) {
V_167 = F_57 (
(struct V_172 * ) V_145 -> V_173 ) ;
} else {
V_167 = F_58 (
(struct V_17 * ) V_145 -> V_173 ) ;
}
V_34 = F_59 ( V_10 , V_167 ) ;
if ( ! V_34 ) {
F_60 ( V_10 , V_77 ) ;
continue;
}
if ( V_76 ) {
if ( V_76 == - V_174 )
V_165 [ V_167 ] = true ;
V_34 -> V_122 . V_175 ++ ;
if ( V_76 != - V_176 && V_76 != - V_174 )
F_37 ( L_9 , V_76 ) ;
F_24 ( V_83 ,
L_10 ,
V_84 , V_5 , V_145 -> V_173 , V_145 -> V_171 ,
V_75 , L_11 ) ;
} else {
F_24 ( V_83 ,
L_10 ,
V_84 , V_5 , V_145 -> V_173 , V_145 -> V_171 ,
V_75 , L_12 ) ;
V_165 [ V_167 ] = false ;
V_34 -> V_122 . V_177 ++ ;
V_34 -> V_122 . V_178 += V_5 -> V_85 ;
}
F_49 ( V_34 , V_75 , V_8 ) ;
F_60 ( V_10 , V_77 ) ;
if ( F_10 ( V_157 , & V_34 -> V_35 ) )
F_56 ( V_157 , & V_34 -> V_35 ) ;
}
F_9 ( & V_10 -> V_82 ) ;
F_61 ( & V_163 ) ;
F_7 ( & V_10 -> V_156 ) ;
F_47 (vif, &ar->vif_list, list) {
if ( F_10 ( V_108 , & V_34 -> V_35 ) &&
! V_165 [ V_34 -> V_57 ] ) {
F_9 ( & V_10 -> V_156 ) ;
F_62 ( V_34 -> V_158 ) ;
F_7 ( & V_10 -> V_156 ) ;
}
}
F_9 ( & V_10 -> V_156 ) ;
if ( V_164 )
F_63 ( & V_10 -> V_179 ) ;
return;
V_170:
F_64 ( 1 ) ;
F_9 ( & V_10 -> V_82 ) ;
return;
}
void F_65 ( struct V_9 * V_10 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ )
F_66 ( V_10 -> V_94 , V_10 -> V_130 [ V_13 ] ,
V_96 ) ;
}
static void F_67 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
if ( ! V_5 )
return;
V_5 -> V_7 = V_7 ;
if ( ! ( V_5 -> V_7 -> V_35 & V_180 ) ) {
F_21 ( V_5 ) ;
return;
}
V_5 -> V_181 = F_68 ( V_5 , V_5 -> V_7 ) ;
F_69 ( V_5 ) ;
}
static void F_70 ( struct V_162 * V_182 , T_3 V_183 )
{
struct V_4 * V_5 ;
while ( V_183 ) {
V_5 = F_71 ( V_184 ) ;
if ( ! V_5 ) {
F_25 ( L_13 ) ;
return;
}
F_15 ( V_182 , V_5 ) ;
V_183 -- ;
}
}
static struct V_4 * F_72 ( struct V_185 * V_186 )
{
struct V_4 * V_5 = NULL ;
if ( F_73 ( & V_186 -> V_187 ) <
( V_188 >> 2 ) )
F_70 ( & V_186 -> V_187 ,
V_188 ) ;
V_5 = F_74 ( & V_186 -> V_187 ) ;
return V_5 ;
}
void F_75 ( struct V_94 * V_143 , enum V_74 V_146 )
{
struct V_9 * V_10 = V_143 -> V_7 -> V_10 ;
struct V_4 * V_5 ;
int V_189 ;
int V_190 ;
struct V_144 * V_145 ;
struct V_160 V_191 ;
V_190 = V_192 -
F_76 ( V_10 -> V_94 , V_146 ) ;
if ( V_190 <= 0 )
return;
F_77 ( & V_191 ) ;
F_24 ( V_193 ,
L_14 ,
V_84 , V_190 , V_146 ) ;
for ( V_189 = 0 ; V_189 < V_190 ; V_189 ++ ) {
V_5 = F_71 ( V_184 ) ;
if ( ! V_5 )
break;
V_145 = (struct V_144 * ) V_5 -> V_118 ;
if ( ! F_39 ( ( unsigned long ) V_5 -> V_16 , 4 ) )
V_5 -> V_16 = F_78 ( V_5 -> V_16 - 4 , 4 ) ;
F_79 ( V_145 , V_5 , V_5 -> V_16 ,
V_184 , V_146 ) ;
V_145 -> V_5 = V_5 ;
F_80 ( & V_145 -> V_168 , & V_191 ) ;
}
if ( ! F_52 ( & V_191 ) )
F_81 ( V_10 -> V_94 , & V_191 ) ;
}
void F_82 ( struct V_9 * V_10 , int V_194 )
{
struct V_144 * V_145 ;
struct V_4 * V_5 ;
while ( V_194 ) {
V_5 = F_71 ( V_195 ) ;
if ( ! V_5 )
return;
V_145 = (struct V_144 * ) V_5 -> V_118 ;
if ( ! F_39 ( ( unsigned long ) V_5 -> V_16 , 4 ) )
V_5 -> V_16 = F_78 ( V_5 -> V_16 - 4 , 4 ) ;
F_79 ( V_145 , V_5 , V_5 -> V_16 ,
V_195 , 0 ) ;
V_145 -> V_5 = V_5 ;
F_7 ( & V_10 -> V_82 ) ;
F_80 ( & V_145 -> V_168 , & V_10 -> V_196 ) ;
F_9 ( & V_10 -> V_82 ) ;
V_194 -- ;
}
}
struct V_144 * F_83 ( struct V_94 * V_143 ,
enum V_74 V_146 ,
int V_85 )
{
struct V_9 * V_10 = V_143 -> V_7 -> V_10 ;
struct V_144 * V_145 = NULL ;
struct V_160 * V_197 ;
int V_198 = 0 , V_199 = 0 ;
F_24 ( V_193 , L_15 ,
V_84 , V_146 , V_85 ) ;
if ( ( V_85 <= V_184 ) ||
( V_85 > V_195 ) )
return NULL ;
F_7 ( & V_10 -> V_82 ) ;
if ( F_52 ( & V_10 -> V_196 ) ) {
F_9 ( & V_10 -> V_82 ) ;
V_198 = V_200 ;
goto V_201;
}
V_145 = F_53 ( & V_10 -> V_196 ,
struct V_144 , V_168 ) ;
F_54 ( & V_145 -> V_168 ) ;
F_84 (pkt_pos, &ar->amsdu_rx_buffer_queue)
V_199 ++ ;
V_198 = V_200 - V_199 ;
F_9 ( & V_10 -> V_82 ) ;
V_145 -> V_146 = V_146 ;
V_201:
if ( V_198 >= V_202 )
F_82 ( V_10 , V_198 ) ;
return V_145 ;
}
static void F_85 ( struct V_185 * V_186 ,
struct V_203 * V_203 , struct V_4 * V_5 )
{
struct V_4 * V_204 ;
struct V_11 * V_205 ;
T_3 V_206 , V_207 , V_208 , V_209 ;
T_1 * V_210 ;
V_208 = sizeof( struct V_11 ) ;
V_210 = V_5 -> V_16 + V_208 ;
V_209 = V_5 -> V_85 - V_208 ;
while ( V_209 > V_208 ) {
V_205 = (struct V_11 * ) V_210 ;
V_207 = F_86 ( V_205 -> V_53 ) ;
if ( V_207 < V_211 ||
V_207 > V_212 ) {
F_25 ( L_16 ,
V_207 ) ;
break;
}
V_206 = V_207 + V_208 ;
V_204 = F_72 ( V_186 ) ;
if ( ! V_204 ) {
F_25 ( L_17 ) ;
break;
}
memcpy ( V_204 -> V_16 , V_210 , V_206 ) ;
F_87 ( V_204 , V_206 ) ;
if ( F_88 ( V_204 ) ) {
F_25 ( L_18 ) ;
F_21 ( V_204 ) ;
break;
}
F_15 ( & V_203 -> V_182 , V_204 ) ;
if ( ( V_209 - V_206 ) == 0 )
break;
V_206 = F_89 ( V_206 , 4 ) ;
V_210 += V_206 ;
V_209 -= V_206 ;
}
F_21 ( V_5 ) ;
}
static void F_90 ( struct V_213 * V_214 , T_1 V_215 ,
T_3 V_216 , T_1 V_217 )
{
struct V_4 * V_5 ;
struct V_203 * V_203 ;
struct V_218 * V_219 ;
T_3 V_220 , V_221 , V_222 ;
struct V_223 * V_224 ;
V_203 = & V_214 -> V_225 [ V_215 ] ;
V_224 = & V_214 -> V_226 [ V_215 ] ;
F_7 ( & V_203 -> V_82 ) ;
V_220 = F_91 ( V_203 -> V_227 , V_203 -> V_228 ) ;
V_222 = V_216 ? V_216 : V_203 -> V_227 ;
V_221 = F_91 ( V_222 , V_203 -> V_228 ) ;
do {
V_219 = & V_203 -> V_229 [ V_220 ] ;
if ( ( V_217 == 1 ) && ( ! V_219 -> V_5 ) )
break;
if ( V_219 -> V_5 ) {
if ( V_219 -> V_230 )
F_85 ( V_214 -> V_185 , V_203 ,
V_219 -> V_5 ) ;
else
F_15 ( & V_203 -> V_182 , V_219 -> V_5 ) ;
V_219 -> V_5 = NULL ;
} else
V_224 -> V_231 ++ ;
V_203 -> V_227 = F_92 ( V_203 -> V_227 ) ;
V_220 = F_91 ( V_203 -> V_227 , V_203 -> V_228 ) ;
} while ( V_220 != V_221 );
F_9 ( & V_203 -> V_82 ) ;
V_224 -> V_232 += F_73 ( & V_203 -> V_182 ) ;
while ( ( V_5 = F_74 ( & V_203 -> V_182 ) ) )
F_67 ( V_214 -> V_7 , V_5 ) ;
}
static bool F_93 ( struct V_213 * V_214 , T_1 V_215 ,
T_3 V_216 ,
bool V_230 , struct V_4 * V_233 )
{
struct V_203 * V_203 ;
struct V_223 * V_224 ;
struct V_4 * V_5 ;
struct V_218 * V_219 ;
T_3 V_220 , V_234 , V_235 , V_236 ;
bool V_237 = false ;
T_3 V_238 ;
V_203 = & V_214 -> V_225 [ V_215 ] ;
V_224 = & V_214 -> V_226 [ V_215 ] ;
V_224 -> V_239 ++ ;
if ( ! V_203 -> V_240 ) {
if ( V_230 ) {
F_85 ( V_214 -> V_185 , V_203 , V_233 ) ;
V_237 = true ;
V_224 -> V_241 ++ ;
while ( ( V_5 = F_74 ( & V_203 -> V_182 ) ) )
F_67 ( V_214 -> V_7 ,
V_5 ) ;
}
return V_237 ;
}
V_234 = V_203 -> V_227 ;
V_235 = V_216 ;
V_236 = ( V_234 + V_203 -> V_228 - 1 ) & V_242 ;
if ( ( ( V_234 < V_236 ) && ( V_235 < V_234 || V_235 > V_236 ) ) ||
( ( V_234 > V_236 ) && ( V_235 > V_236 ) && ( V_235 < V_234 ) ) ) {
V_238 = ( V_236 + V_203 -> V_228 - 1 ) &
V_242 ;
if ( ( ( V_236 < V_238 ) &&
( V_235 < V_236 || V_235 > V_238 ) ) ||
( ( V_236 > V_238 ) && ( V_235 > V_238 ) &&
( V_235 < V_236 ) ) ) {
F_90 ( V_214 , V_215 , 0 , 0 ) ;
F_7 ( & V_203 -> V_82 ) ;
if ( V_235 >= V_203 -> V_228 - 1 )
V_203 -> V_227 = V_235 - ( V_203 -> V_228 - 1 ) ;
else
V_203 -> V_227 = V_242 -
( V_203 -> V_228 - 2 - V_235 ) ;
F_9 ( & V_203 -> V_82 ) ;
} else {
if ( V_235 >= V_203 -> V_228 - 1 )
V_234 = V_235 - ( V_203 -> V_228 - 1 ) ;
else
V_234 = V_242 -
( V_203 -> V_228 - 2 - V_235 ) ;
F_90 ( V_214 , V_215 , V_234 , 0 ) ;
}
V_224 -> V_243 ++ ;
}
V_220 = F_91 ( V_216 , V_203 -> V_228 ) ;
V_219 = & V_203 -> V_229 [ V_220 ] ;
F_7 ( & V_203 -> V_82 ) ;
F_21 ( V_219 -> V_5 ) ;
V_224 -> V_244 ++ ;
V_219 -> V_5 = V_233 ;
V_237 = true ;
V_219 -> V_230 = V_230 ;
V_219 -> V_216 = V_216 ;
if ( V_219 -> V_230 )
V_224 -> V_241 ++ ;
else
V_224 -> V_245 ++ ;
F_9 ( & V_203 -> V_82 ) ;
F_90 ( V_214 , V_215 , 0 , 1 ) ;
if ( V_214 -> V_246 )
return V_237 ;
F_7 ( & V_203 -> V_82 ) ;
for ( V_220 = 0 ; V_220 < V_203 -> V_228 ; V_220 ++ ) {
if ( V_203 -> V_229 [ V_220 ] . V_5 ) {
V_214 -> V_246 = true ;
F_94 ( & V_214 -> V_247 ,
( V_248 + ( V_249 * V_250 ) / 1000 ) ) ;
V_203 -> V_251 = true ;
break;
}
}
F_9 ( & V_203 -> V_82 ) ;
return V_237 ;
}
static void F_95 ( struct V_33 * V_34 ,
struct V_31 * V_32 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
bool V_36 , V_252 ;
T_2 V_253 , V_35 ;
struct V_4 * V_5 = NULL ;
V_253 = ( V_32 -> V_51 >> V_254 ) &
V_255 ;
if ( ! V_253 )
V_253 = V_256 ;
F_7 ( & V_32 -> V_45 ) ;
V_36 = F_8 ( & V_32 -> V_46 ) ;
F_9 ( & V_32 -> V_45 ) ;
V_252 = V_36 ;
while ( ( ! V_36 ) && ( V_253 ) ) {
F_7 ( & V_32 -> V_45 ) ;
V_5 = F_74 ( & V_32 -> V_46 ) ;
V_36 = F_8 ( & V_32 -> V_46 ) ;
F_9 ( & V_32 -> V_45 ) ;
V_32 -> V_43 |= V_44 ;
V_253 -- ;
if ( ( V_36 ) || ( ! V_253 ) )
V_32 -> V_43 |= V_48 ;
F_29 ( V_5 , V_34 -> V_158 ) ;
V_32 -> V_43 &= ~ ( V_44 ) ;
V_32 -> V_43 &= ~ ( V_48 ) ;
}
if ( V_36 ) {
if ( V_252 )
V_35 = V_257 ;
else
V_35 = 0 ;
F_16 ( V_10 -> V_56 ,
V_34 -> V_57 ,
V_32 -> V_58 , 0 , V_35 ) ;
}
return;
}
void F_96 ( struct V_94 * V_143 , struct V_144 * V_145 )
{
struct V_9 * V_10 = V_143 -> V_7 -> V_10 ;
struct V_4 * V_5 = V_145 -> V_169 ;
struct V_258 * V_102 ;
struct V_17 * V_259 ;
int V_260 ;
T_1 V_261 , V_262 = 0 ;
T_1 V_263 ;
int V_76 = V_145 -> V_76 ;
enum V_74 V_264 = V_145 -> V_146 ;
bool V_230 , V_265 , V_266 = false ;
bool V_267 = false ;
struct V_31 * V_32 = NULL ;
struct V_4 * V_268 = NULL ;
struct V_11 * V_15 = NULL ;
struct V_33 * V_34 ;
struct V_213 * V_269 ;
T_3 V_216 , V_270 ;
T_1 V_215 , V_167 ;
F_24 ( V_193 ,
L_19 ,
V_84 , V_10 , V_264 , V_5 , V_145 -> V_173 ,
V_145 -> V_171 , V_76 ) ;
if ( V_76 || ! ( V_5 -> V_16 + V_131 ) ) {
F_21 ( V_5 ) ;
return;
}
F_87 ( V_5 , V_145 -> V_171 + V_131 ) ;
F_97 ( V_5 , V_131 ) ;
F_42 ( V_134 , V_84 , L_20 ,
V_5 -> V_16 , V_5 -> V_85 ) ;
if ( V_264 == V_10 -> V_88 ) {
if ( F_10 ( V_114 , & V_10 -> V_87 ) ) {
F_98 ( V_10 ) ;
F_99 ( V_10 -> V_56 , V_5 ) ;
return;
}
V_167 =
F_57 ( (struct V_172 * ) V_5 -> V_16 ) ;
} else {
V_167 =
F_58 ( (struct V_17 * ) V_5 -> V_16 ) ;
}
V_34 = F_59 ( V_10 , V_167 ) ;
if ( ! V_34 ) {
F_21 ( V_5 ) ;
return;
}
F_7 ( & V_34 -> V_271 ) ;
V_34 -> V_122 . V_272 ++ ;
V_34 -> V_122 . V_273 += V_145 -> V_171 ;
F_9 ( & V_34 -> V_271 ) ;
V_5 -> V_7 = V_34 -> V_158 ;
if ( ! F_10 ( V_114 , & V_10 -> V_87 ) ) {
if ( V_274 > 0 )
F_97 ( V_5 , V_274 ) ;
F_67 ( V_34 -> V_158 , V_5 ) ;
return;
}
F_98 ( V_10 ) ;
V_260 = sizeof( struct V_11 ) + sizeof( struct V_17 ) +
sizeof( struct V_41 ) ;
V_259 = (struct V_17 * ) V_5 -> V_16 ;
if ( V_34 -> V_112 != V_113 &&
( ( V_145 -> V_171 < V_260 ) ||
( V_145 -> V_171 > V_275 ) ) ) {
F_100 ( L_21 ) ;
V_34 -> V_122 . V_276 ++ ;
V_34 -> V_122 . V_277 ++ ;
F_21 ( V_5 ) ;
return;
}
if ( V_34 -> V_112 == V_113 ) {
V_261 = F_101 ( V_259 ) ;
V_266 = ! ! ( ( V_259 -> V_149 >> V_278 ) &
V_279 ) ;
V_270 = sizeof( struct V_17 ) ;
V_267 = ! ! ( F_102 ( V_259 -> V_280 ) & V_281 ) ;
switch ( V_261 ) {
case 0 :
break;
case V_282 :
V_270 += sizeof( struct V_283 ) ;
break;
case V_126 :
V_270 += sizeof( struct V_258 ) ;
break;
default:
break;
}
V_15 = (struct V_11 * ) ( V_5 -> V_16 + V_270 ) ;
V_32 = F_20 ( V_34 , V_15 -> V_284 ) ;
if ( ! V_32 ) {
F_21 ( V_5 ) ;
return;
}
V_265 = ! ! ( V_32 -> V_43 & V_67 ) ;
if ( V_266 )
V_32 -> V_43 |= V_67 ;
else
V_32 -> V_43 &= ~ V_67 ;
if ( ( V_32 -> V_43 & V_67 ) && V_267 )
F_95 ( V_34 , V_32 ) ;
if ( V_265 ^ ! ! ( V_32 -> V_43 & V_67 ) ) {
if ( ! ( V_32 -> V_43 & V_67 ) ) {
struct V_4 * V_285 = NULL ;
bool V_36 ;
struct V_286 * V_287 ;
T_1 V_220 ;
F_7 ( & V_32 -> V_45 ) ;
while ( V_32 -> V_288 > 0 ) {
V_287 = F_53 (
& V_32 -> V_289 ,
struct V_286 ,
V_168 ) ;
F_54 ( & V_287 -> V_168 ) ;
V_32 -> V_288 -- ;
F_9 ( & V_32 -> V_45 ) ;
V_220 = V_34 -> V_57 ;
F_103 ( V_10 -> V_56 ,
V_220 ,
V_287 -> V_290 ,
V_287 -> V_291 ,
V_287 -> V_292 ,
V_287 -> V_173 ,
V_287 -> V_85 ,
V_287 -> V_293 ) ;
F_104 ( V_287 ) ;
F_7 ( & V_32 -> V_45 ) ;
}
V_32 -> V_288 = 0 ;
while ( ( V_285 = F_74 ( & V_32 -> V_61 ) ) ) {
F_9 ( & V_32 -> V_45 ) ;
F_29 ( V_285 , V_34 -> V_158 ) ;
F_7 ( & V_32 -> V_45 ) ;
}
V_36 = F_8 ( & V_32 -> V_46 ) ;
while ( ( V_285 = F_74 ( & V_32 -> V_46 ) ) ) {
F_9 ( & V_32 -> V_45 ) ;
F_29 ( V_285 , V_34 -> V_158 ) ;
F_7 ( & V_32 -> V_45 ) ;
}
F_9 ( & V_32 -> V_45 ) ;
if ( ! V_36 )
F_16 (
V_10 -> V_56 ,
V_34 -> V_57 ,
V_32 -> V_58 , 0 , 0 ) ;
F_18 ( V_10 -> V_56 , V_34 -> V_57 ,
V_32 -> V_58 , 0 ) ;
}
}
if ( ( V_145 -> V_171 < V_260 ) ||
( V_145 -> V_171 >
V_275 ) ) {
F_21 ( V_5 ) ;
return;
}
}
V_230 = F_105 ( V_259 ) ? true : false ;
V_215 = F_106 ( V_259 ) ;
V_216 = F_107 ( V_259 ) ;
V_261 = F_101 ( V_259 ) ;
V_262 = F_108 ( V_259 ) ;
V_263 =
( F_102 ( V_259 -> V_280 ) >> V_294 )
& V_295 ;
F_97 ( V_5 , sizeof( struct V_17 ) ) ;
switch ( V_261 ) {
case V_282 :
F_97 ( V_5 , sizeof( struct V_283 ) ) ;
break;
case V_126 :
V_102 = (struct V_258 * ) V_5 -> V_16 ;
if ( V_102 -> V_124 & 0x1 ) {
V_5 -> V_106 = V_296 ;
V_5 -> V_105 = ( V_297 V_298 ) V_102 -> V_105 ;
}
F_97 ( V_5 , sizeof( struct V_258 ) ) ;
break;
default:
break;
}
F_97 ( V_5 , V_263 ) ;
if ( V_262 )
V_76 = F_109 ( V_10 -> V_56 , V_5 ) ;
else if ( ! V_230 )
V_76 = F_88 ( V_5 ) ;
if ( V_76 ) {
F_21 ( V_5 ) ;
return;
}
if ( ! ( V_34 -> V_158 -> V_35 & V_180 ) ) {
F_21 ( V_5 ) ;
return;
}
if ( V_34 -> V_112 == V_113 ) {
V_15 = (struct V_11 * ) V_5 -> V_16 ;
if ( F_5 ( V_15 -> V_18 ) )
V_268 = F_110 ( V_5 , V_133 ) ;
else {
V_32 = F_20 ( V_34 , V_15 -> V_18 ) ;
if ( V_32 && V_10 -> V_299 ) {
V_268 = V_5 ;
V_5 = NULL ;
} else if ( V_32 && ! V_10 -> V_299 ) {
F_21 ( V_5 ) ;
V_5 = NULL ;
}
}
if ( V_268 )
F_29 ( V_268 , V_34 -> V_158 ) ;
if ( V_5 == NULL ) {
return;
}
}
V_15 = (struct V_11 * ) V_5 -> V_16 ;
if ( F_111 ( V_15 -> V_18 ) ) {
if ( V_34 -> V_112 == V_113 ) {
V_32 = F_20 ( V_34 , V_15 -> V_284 ) ;
if ( ! V_32 )
return;
V_269 = V_32 -> V_269 ;
} else
V_269 = V_34 -> V_300 -> V_269 ;
if ( F_93 ( V_269 , V_215 , V_216 ,
V_230 , V_5 ) ) {
return;
}
} else if ( ! F_112 ( V_15 -> V_18 ) )
V_34 -> V_122 . V_301 ++ ;
F_67 ( V_34 -> V_158 , V_5 ) ;
}
static void F_113 ( unsigned long V_302 )
{
T_1 V_13 , V_303 ;
struct V_213 * V_269 = (struct V_213 * ) V_302 ;
struct V_203 * V_203 ;
struct V_223 * V_224 ;
for ( V_13 = 0 ; V_13 < V_304 ; V_13 ++ ) {
V_203 = & V_269 -> V_225 [ V_13 ] ;
V_224 = & V_269 -> V_226 [ V_13 ] ;
if ( ! V_203 -> V_240 || ! V_203 -> V_251 )
continue;
V_224 -> V_305 ++ ;
F_24 ( V_306 ,
L_22 ,
V_203 -> V_227 ,
( ( V_203 -> V_227 + V_203 -> V_228 - 1 ) &
V_242 ) ) ;
F_90 ( V_269 , V_13 , 0 , 0 ) ;
}
V_269 -> V_246 = false ;
for ( V_13 = 0 ; V_13 < V_304 ; V_13 ++ ) {
V_203 = & V_269 -> V_225 [ V_13 ] ;
if ( V_203 -> V_240 && V_203 -> V_229 ) {
F_7 ( & V_203 -> V_82 ) ;
for ( V_303 = 0 ; V_303 < V_203 -> V_228 ; V_303 ++ ) {
if ( V_203 -> V_229 [ V_303 ] . V_5 ) {
V_269 -> V_246 = true ;
V_203 -> V_251 = true ;
break;
}
}
F_9 ( & V_203 -> V_82 ) ;
if ( V_303 >= V_203 -> V_228 )
V_203 -> V_251 = false ;
}
}
if ( V_269 -> V_246 )
F_94 ( & V_269 -> V_247 ,
V_248 + F_114 ( V_250 ) ) ;
}
static void F_115 ( struct V_213 * V_269 , T_1 V_215 )
{
struct V_203 * V_203 ;
struct V_223 * V_224 ;
if ( ! V_269 || V_215 >= V_304 )
return;
V_203 = & V_269 -> V_225 [ V_215 ] ;
V_224 = & V_269 -> V_226 [ V_215 ] ;
if ( V_203 -> V_240 )
F_90 ( V_269 , V_215 , 0 , 0 ) ;
V_203 -> V_240 = false ;
V_203 -> V_251 = false ;
V_203 -> V_307 = 0 ;
V_203 -> V_227 = 0 ;
V_203 -> V_228 = 0 ;
F_104 ( V_203 -> V_229 ) ;
V_203 -> V_229 = NULL ;
memset ( V_224 , 0 , sizeof( struct V_223 ) ) ;
}
void F_116 ( struct V_33 * V_34 , T_1 V_1 , T_3 V_216 ,
T_1 V_307 )
{
struct V_31 * V_308 ;
struct V_213 * V_269 = NULL ;
struct V_203 * V_203 ;
struct V_223 * V_224 ;
T_3 V_309 ;
T_1 V_215 , V_58 ;
if ( V_34 -> V_112 == V_113 ) {
V_58 = F_2 ( V_1 ) ;
V_308 = F_117 ( V_34 -> V_10 , V_58 ) ;
if ( V_308 )
V_269 = V_308 -> V_269 ;
} else
V_269 = V_34 -> V_300 -> V_269 ;
if ( ! V_269 )
return;
V_215 = F_1 ( V_1 ) ;
if ( V_215 >= V_304 )
return;
V_203 = & V_269 -> V_225 [ V_215 ] ;
V_224 = & V_269 -> V_226 [ V_215 ] ;
if ( V_307 < V_310 || V_307 > V_311 )
F_24 ( V_193 , L_23 ,
V_84 , V_307 , V_215 ) ;
if ( V_203 -> V_240 )
F_115 ( V_269 , V_215 ) ;
V_203 -> V_227 = V_216 ;
V_309 = F_118 ( V_307 ) * sizeof( struct V_218 ) ;
V_203 -> V_229 = F_119 ( V_309 , V_312 ) ;
if ( ! V_203 -> V_229 )
return;
V_203 -> V_307 = V_307 ;
V_203 -> V_228 = F_118 ( V_307 ) ;
if ( ! F_8 ( & V_203 -> V_182 ) )
return;
V_203 -> V_240 = true ;
}
void F_120 ( struct V_33 * V_34 , struct V_185 * V_185 ,
struct V_213 * V_269 )
{
struct V_203 * V_203 ;
T_1 V_13 ;
V_269 -> V_313 = V_314 ;
V_269 -> V_7 = V_34 -> V_158 ;
F_121 ( & V_269 -> V_247 ) ;
V_269 -> V_247 . V_315 = F_113 ;
V_269 -> V_247 . V_16 = ( unsigned long ) V_269 ;
V_269 -> V_185 = V_185 ;
V_269 -> V_246 = false ;
for ( V_13 = 0 ; V_13 < V_304 ; V_13 ++ ) {
V_203 = & V_269 -> V_225 [ V_13 ] ;
V_203 -> V_240 = false ;
V_203 -> V_251 = false ;
F_51 ( & V_203 -> V_182 ) ;
F_122 ( & V_203 -> V_82 ) ;
}
}
struct V_185 * F_123 ( struct V_33 * V_34 )
{
struct V_185 * V_186 = NULL ;
V_186 = F_119 ( sizeof( struct V_185 ) , V_312 ) ;
if ( ! V_186 ) {
F_25 ( L_24 ) ;
return NULL ;
}
V_186 -> V_269 = F_119 ( sizeof( struct V_213 ) , V_312 ) ;
if ( ! V_186 -> V_269 ) {
F_25 ( L_25 ) ;
F_104 ( V_186 ) ;
return NULL ;
}
F_120 ( V_34 , V_186 , V_186 -> V_269 ) ;
F_51 ( & V_186 -> V_187 ) ;
F_70 ( & V_186 -> V_187 , V_188 ) ;
return V_186 ;
}
void F_124 ( struct V_33 * V_34 , T_1 V_1 )
{
struct V_31 * V_308 ;
struct V_203 * V_203 ;
struct V_213 * V_269 = NULL ;
T_1 V_215 , V_58 ;
if ( V_34 -> V_112 == V_113 ) {
V_58 = F_2 ( V_1 ) ;
V_308 = F_117 ( V_34 -> V_10 , V_58 ) ;
if ( V_308 )
V_269 = V_308 -> V_269 ;
} else
V_269 = V_34 -> V_300 -> V_269 ;
if ( ! V_269 )
return;
V_215 = F_1 ( V_1 ) ;
if ( V_215 >= V_304 )
return;
V_203 = & V_269 -> V_225 [ V_215 ] ;
if ( V_203 -> V_240 )
F_115 ( V_269 , V_215 ) ;
}
void F_125 ( struct V_213 * V_269 )
{
T_1 V_215 ;
if ( ! V_269 )
return;
if ( V_269 -> V_246 ) {
F_126 ( & V_269 -> V_247 ) ;
V_269 -> V_246 = false ;
}
for ( V_215 = 0 ; V_215 < V_304 ; V_215 ++ )
F_115 ( V_269 , V_215 ) ;
}
void F_127 ( struct V_9 * V_10 )
{
struct V_144 * V_145 , * V_316 ;
F_7 ( & V_10 -> V_82 ) ;
if ( F_52 ( & V_10 -> V_196 ) ) {
F_9 ( & V_10 -> V_82 ) ;
return;
}
F_128 (packet, tmp_pkt, &ar->amsdu_rx_buffer_queue,
list) {
F_54 ( & V_145 -> V_168 ) ;
F_9 ( & V_10 -> V_82 ) ;
F_21 ( V_145 -> V_169 ) ;
F_7 ( & V_10 -> V_82 ) ;
}
F_9 ( & V_10 -> V_82 ) ;
}
void F_129 ( struct V_185 * V_185 )
{
if ( ! V_185 )
return;
F_125 ( V_185 -> V_269 ) ;
F_130 ( & V_185 -> V_187 ) ;
F_104 ( V_185 -> V_269 ) ;
F_104 ( V_185 ) ;
}
