static struct V_1 * F_1 ( struct V_2 * V_2 , unsigned V_3 )
{
struct V_1 * V_4 = NULL ;
if ( V_3 < V_2 -> V_5 . V_6 ) {
struct V_1 T_1 * * V_7 =
F_2 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_2 ( V_7 [ V_3 ] ) ;
}
return V_4 ;
}
bool F_3 ( const struct V_8 * V_9 )
{
return V_9 && ( V_9 -> V_10 & V_11 ) && F_4 ( V_9 ) ;
}
static T_2 * F_5 ( struct V_1 * V_4 , struct V_12 * V_13 )
{
T_2 * V_14 = F_6 ( ( T_2 * ) & V_4 -> V_15 [ V_4 -> V_16 ] , V_17 ) ;
int V_18 = V_13 - V_4 -> V_15 ;
return V_14 + V_4 -> V_19 * V_18 ;
}
static const T_2 * F_7 ( const struct V_1 * V_4 ,
const struct V_12 * V_13 )
{
return F_5 ( (struct V_1 * ) V_4 , (struct V_12 * ) V_13 ) ;
}
static unsigned int F_8 ( const struct V_12 * V_13 )
{
return V_13 -> V_20 * sizeof( struct V_21 ) ;
}
unsigned int F_9 ( const struct V_8 * V_9 )
{
return V_9 -> V_22 ;
}
bool F_10 ( const struct V_23 * V_24 , unsigned int V_22 )
{
if ( V_24 -> V_25 <= V_22 )
return false ;
if ( F_11 ( V_24 ) && F_12 ( V_24 , V_22 ) )
return false ;
return true ;
}
void F_13 ( struct V_8 * V_9 ,
const struct V_23 * V_24 )
{
struct V_26 * V_27 ;
if ( V_24 -> V_28 == F_14 ( V_29 ) ) {
V_27 = F_15 ( V_9 ) ;
if ( V_27 )
F_16 ( V_27 , V_24 -> V_25 ,
V_30 ,
V_31 ) ;
} else if ( V_24 -> V_28 == F_14 ( V_32 ) ) {
F_17 ( F_18 ( V_9 ) , V_33 , V_24 -> V_25 ) ;
#if F_19 ( V_34 )
} else if ( V_24 -> V_28 == F_14 ( V_35 ) ) {
struct V_36 * V_37 = F_20 ( V_9 ) ;
if ( V_37 )
F_21 ( F_18 ( V_9 ) , V_37 ,
V_33 , V_24 -> V_25 ) ;
#endif
}
}
static T_3 F_22 ( struct V_1 * V_4 , struct V_23 * V_24 )
{
struct V_38 V_39 ;
unsigned int V_40 = 0 ;
struct V_21 * V_41 ;
bool V_42 = false ;
int V_43 ;
T_3 V_44 = 0 ;
for ( V_43 = 0 ; V_43 < V_45 ;
V_43 ++ ) {
V_40 += sizeof( * V_41 ) ;
if ( ! F_23 ( V_24 , V_40 ) )
break;
V_41 = F_24 ( V_24 ) + V_43 ;
V_39 = F_25 ( V_41 ) ;
if ( F_26 ( V_39 . V_46 >= V_47 ) ) {
V_44 = F_27 ( V_39 . V_46 , V_44 ) ;
if ( V_42 )
break;
} else if ( V_39 . V_46 == V_48 ) {
V_42 = true ;
}
if ( ! V_39 . V_49 )
continue;
if ( F_23 ( V_24 , V_40 + sizeof( struct V_50 ) ) ) {
const struct V_50 * V_51 ;
V_51 = ( const struct V_50 * ) ( V_41 + 1 ) ;
if ( V_51 -> V_52 == 4 ) {
V_44 = F_28 ( F_29 ( V_51 -> V_53 ) ,
F_29 ( V_51 -> V_54 ) ,
V_51 -> V_28 , V_44 ) ;
} else if ( V_51 -> V_52 == 6 &&
F_23 ( V_24 , V_40 +
sizeof( struct V_55 ) ) ) {
const struct V_55 * V_56 ;
V_56 = ( const struct V_55 * ) ( V_41 + 1 ) ;
V_44 = F_30 ( & V_56 -> V_53 , V_44 ) ;
V_44 = F_30 ( & V_56 -> V_54 , V_44 ) ;
V_44 = F_27 ( V_56 -> V_57 , V_44 ) ;
}
}
break;
}
return V_44 ;
}
static struct V_12 * F_31 ( struct V_1 * V_4 ,
struct V_23 * V_24 )
{
int V_58 = F_32 ( V_4 -> V_59 ) ;
T_3 V_44 = 0 ;
int V_18 = 0 ;
int V_60 = 0 ;
if ( V_4 -> V_16 == 1 )
goto V_61;
if ( V_58 <= 0 )
return NULL ;
V_44 = F_22 ( V_4 , V_24 ) ;
V_18 = V_44 % V_58 ;
if ( V_58 == V_4 -> V_16 )
goto V_61;
F_33 (rt) {
if ( V_13 -> V_62 & ( V_63 | V_64 ) )
continue;
if ( V_60 == V_18 )
return V_13 ;
V_60 ++ ;
} F_34 ( V_4 ) ;
V_61:
return & V_4 -> V_15 [ V_18 ] ;
}
static bool F_35 ( struct V_1 * V_4 , struct V_23 * V_24 ,
struct V_38 V_39 )
{
enum V_65 V_66 ;
bool V_67 = false ;
if ( ! F_23 ( V_24 , 12 ) )
return false ;
V_66 = V_4 -> V_68 ;
if ( V_66 == V_69 )
V_66 = F_36 ( V_24 ) -> V_52 ;
switch ( V_66 ) {
case V_70 : {
struct V_50 * V_71 = F_36 ( V_24 ) ;
V_24 -> V_28 = F_14 ( V_32 ) ;
F_37 ( & V_71 -> V_72 ,
F_14 ( V_71 -> V_73 << 8 ) ,
F_14 ( V_39 . V_73 << 8 ) ) ;
V_71 -> V_73 = V_39 . V_73 ;
V_67 = true ;
break;
}
case V_74 : {
struct V_55 * V_75 = F_38 ( V_24 ) ;
V_24 -> V_28 = F_14 ( V_35 ) ;
V_75 -> V_76 = V_39 . V_73 ;
V_67 = true ;
break;
}
case V_69 :
break;
}
return V_67 ;
}
static int F_39 ( struct V_23 * V_24 , struct V_8 * V_9 ,
struct V_77 * V_78 , struct V_8 * V_79 )
{
struct V_2 * V_2 = F_18 ( V_9 ) ;
struct V_21 * V_41 ;
struct V_1 * V_4 ;
struct V_12 * V_13 ;
struct V_38 V_39 ;
struct V_8 * V_80 ;
struct V_26 * V_81 ;
struct V_26 * V_27 ;
unsigned int V_82 ;
unsigned int V_83 ;
unsigned int V_22 ;
int V_84 ;
V_27 = F_15 ( V_9 ) ;
if ( ! V_27 )
goto V_85;
F_16 ( V_27 , V_24 -> V_25 , V_86 ,
V_87 ) ;
if ( ! V_27 -> V_88 ) {
F_40 ( V_27 , V_89 ) ;
goto V_85;
}
if ( V_24 -> V_90 != V_91 )
goto V_84;
if ( ( V_24 = F_41 ( V_24 , V_92 ) ) == NULL )
goto V_84;
if ( ! F_23 ( V_24 , sizeof( * V_41 ) ) )
goto V_84;
V_41 = F_24 ( V_24 ) ;
V_39 = F_25 ( V_41 ) ;
V_4 = F_1 ( V_2 , V_39 . V_46 ) ;
if ( ! V_4 ) {
F_40 ( V_27 , V_93 ) ;
goto V_85;
}
V_13 = F_31 ( V_4 , V_24 ) ;
if ( ! V_13 )
goto V_84;
F_42 ( V_24 , sizeof( * V_41 ) ) ;
F_43 ( V_24 ) ;
F_44 ( V_24 ) ;
if ( F_45 ( V_24 ) )
goto V_84;
F_46 ( V_24 ) ;
if ( V_39 . V_73 <= 1 )
goto V_84;
V_39 . V_73 -= 1 ;
V_80 = F_2 ( V_13 -> V_94 ) ;
if ( ! F_3 ( V_80 ) )
goto V_95;
V_83 = F_8 ( V_13 ) ;
V_22 = F_9 ( V_80 ) ;
if ( F_10 ( V_24 , V_22 - V_83 ) )
goto V_95;
V_82 = F_47 ( V_80 ) ;
if ( ! V_80 -> V_96 )
V_82 = 0 ;
if ( F_48 ( V_24 , V_82 + V_83 ) )
goto V_95;
V_24 -> V_9 = V_80 ;
V_24 -> V_28 = F_14 ( V_29 ) ;
if ( F_49 ( ! V_83 && V_39 . V_49 ) ) {
if ( ! F_35 ( V_4 , V_24 , V_39 ) )
goto V_84;
} else {
bool V_49 ;
int V_97 ;
F_50 ( V_24 , V_83 ) ;
F_43 ( V_24 ) ;
V_41 = F_24 ( V_24 ) ;
V_49 = V_39 . V_49 ;
for ( V_97 = V_13 -> V_20 - 1 ; V_97 >= 0 ; V_97 -- ) {
V_41 [ V_97 ] = F_51 ( V_13 -> V_98 [ V_97 ] ,
V_39 . V_73 , 0 , V_49 ) ;
V_49 = false ;
}
}
F_13 ( V_80 , V_24 ) ;
if ( V_13 -> V_99 == V_100 )
V_84 = F_52 ( V_101 , V_80 ,
V_80 -> V_102 , V_24 ) ;
else
V_84 = F_52 ( V_13 -> V_99 , V_80 ,
F_7 ( V_4 , V_13 ) , V_24 ) ;
if ( V_84 )
F_53 ( L_1 ,
V_103 , V_84 ) ;
return 0 ;
V_95:
V_81 = V_80 ? F_15 ( V_80 ) : NULL ;
if ( V_81 )
F_40 ( V_81 , V_104 ) ;
goto V_85;
V_84:
F_40 ( V_27 , V_105 ) ;
V_85:
F_54 ( V_24 ) ;
return V_106 ;
}
static struct V_1 * F_55 ( int V_107 , T_2 V_108 )
{
T_2 V_109 = F_56 ( V_108 , V_17 ) ;
struct V_1 * V_4 ;
V_4 = F_57 ( F_56 ( sizeof( * V_4 ) + V_107 * sizeof( * V_4 -> V_15 ) ,
V_17 ) +
V_107 * V_109 ,
V_110 ) ;
if ( V_4 ) {
V_4 -> V_16 = V_107 ;
V_4 -> V_59 = V_107 ;
V_4 -> V_19 = V_109 ;
}
return V_4 ;
}
static void F_58 ( struct V_1 * V_4 )
{
if ( V_4 )
F_59 ( V_4 , V_111 ) ;
}
static void F_60 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_112 , struct V_1 * V_113 ,
const struct V_114 * V_115 )
{
struct V_116 * V_117 = V_115 ? V_115 -> V_117 : NULL ;
unsigned V_118 = V_115 ? V_115 -> V_118 : 0 ;
int V_119 = V_113 ? V_120 : V_121 ;
struct V_1 * V_4 = V_113 ? V_113 : V_112 ;
unsigned V_122 = ( V_112 && V_113 ) ? V_123 : 0 ;
if ( V_4 && ( V_3 >= V_47 ) )
F_61 ( V_119 , V_3 , V_4 , V_117 , V_2 , V_118 , V_122 ) ;
}
static void F_62 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_113 ,
const struct V_114 * V_115 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 ;
F_63 () ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_64 ( V_7 [ V_3 ] ) ;
F_65 ( V_7 [ V_3 ] , V_113 ) ;
F_60 ( V_2 , V_3 , V_4 , V_113 , V_115 ) ;
F_58 ( V_4 ) ;
}
static unsigned F_66 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned V_3 ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_47 ; V_3 < V_6 ;
V_3 ++ ) {
if ( ! F_64 ( V_7 [ V_3 ] ) )
return V_3 ;
}
return V_124 ;
}
static struct V_8 * F_67 ( struct V_2 * V_2 ,
const void * V_125 )
{
struct V_8 * V_9 ;
struct V_126 * V_4 ;
struct V_127 V_54 ;
memcpy ( & V_54 , V_125 , sizeof( struct V_127 ) ) ;
V_4 = F_68 ( V_2 , V_54 . V_128 , 0 , 0 , 0 ) ;
if ( F_69 ( V_4 ) )
return F_70 ( V_4 ) ;
V_9 = V_4 -> V_129 . V_9 ;
F_71 ( V_9 ) ;
F_72 ( V_4 ) ;
return V_9 ;
}
static struct V_8 * F_67 ( struct V_2 * V_2 ,
const void * V_125 )
{
return F_73 ( - V_130 ) ;
}
static struct V_8 * F_74 ( struct V_2 * V_2 ,
const void * V_125 )
{
struct V_8 * V_9 ;
struct V_131 * V_129 ;
struct V_132 V_133 ;
int V_84 ;
if ( ! V_134 )
return F_73 ( - V_130 ) ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
memcpy ( & V_133 . V_54 , V_125 , sizeof( struct V_135 ) ) ;
V_84 = V_134 -> V_136 ( V_2 , NULL , & V_129 , & V_133 ) ;
if ( V_84 )
return F_73 ( V_84 ) ;
V_9 = V_129 -> V_9 ;
F_71 ( V_9 ) ;
F_75 ( V_129 ) ;
return V_9 ;
}
static struct V_8 * F_74 ( struct V_2 * V_2 ,
const void * V_125 )
{
return F_73 ( - V_130 ) ;
}
static struct V_8 * F_76 ( struct V_2 * V_2 ,
struct V_1 * V_4 ,
struct V_12 * V_13 , int V_137 )
{
struct V_8 * V_9 = NULL ;
if ( ! V_137 ) {
switch ( V_13 -> V_99 ) {
case V_138 :
V_9 = F_67 ( V_2 , F_7 ( V_4 , V_13 ) ) ;
break;
case V_139 :
V_9 = F_74 ( V_2 , F_7 ( V_4 , V_13 ) ) ;
break;
case V_101 :
break;
}
} else {
V_9 = F_77 ( V_2 , V_137 ) ;
}
if ( ! V_9 )
return F_73 ( - V_140 ) ;
if ( F_69 ( V_9 ) )
return V_9 ;
F_78 ( V_9 ) ;
return V_9 ;
}
static int F_79 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_12 * V_13 , int V_137 )
{
struct V_8 * V_9 = NULL ;
int V_84 = - V_140 ;
V_9 = F_76 ( V_2 , V_4 , V_13 , V_137 ) ;
if ( F_69 ( V_9 ) ) {
V_84 = F_80 ( V_9 ) ;
V_9 = NULL ;
goto V_141;
}
V_84 = - V_142 ;
if ( ! F_15 ( V_9 ) )
goto V_141;
if ( ( V_13 -> V_99 == V_101 ) &&
( V_9 -> V_143 != V_13 -> V_144 ) )
goto V_141;
F_81 ( V_13 -> V_94 , V_9 ) ;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
V_13 -> V_62 |= V_63 ;
} else {
unsigned int V_10 ;
V_10 = F_82 ( V_9 ) ;
if ( ! ( V_10 & ( V_145 | V_146 ) ) )
V_13 -> V_62 |= V_64 ;
}
return 0 ;
V_141:
return V_84 ;
}
static int F_83 ( struct V_147 * V_148 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = V_148 -> V_149 . V_150 ;
struct V_12 * V_13 = V_4 -> V_15 ;
int V_84 ;
int V_97 ;
if ( ! V_13 )
return - V_151 ;
V_84 = - V_142 ;
if ( V_148 -> V_152 > V_153 )
goto V_141;
V_13 -> V_20 = V_148 -> V_152 ;
for ( V_97 = 0 ; V_97 < V_13 -> V_20 ; V_97 ++ )
V_13 -> V_98 [ V_97 ] = V_148 -> V_154 [ V_97 ] ;
V_13 -> V_99 = V_148 -> V_155 ;
memcpy ( F_5 ( V_4 , V_13 ) , V_148 -> V_156 , V_148 -> V_157 ) ;
V_13 -> V_144 = V_148 -> V_157 ;
V_84 = F_79 ( V_2 , V_4 , V_13 , V_148 -> V_158 ) ;
if ( V_84 )
goto V_141;
if ( V_13 -> V_62 & ( V_63 | V_64 ) )
V_4 -> V_59 -- ;
return 0 ;
V_141:
return V_84 ;
}
static int F_84 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_12 * V_13 , int V_137 , struct V_159 * V_160 ,
struct V_159 * V_161 )
{
int V_84 = - V_151 ;
if ( ! V_13 )
goto V_141;
if ( V_161 ) {
V_84 = F_85 ( V_161 , V_153 ,
& V_13 -> V_20 , V_13 -> V_98 ) ;
if ( V_84 )
goto V_141;
}
if ( V_160 ) {
V_84 = F_86 ( V_160 , & V_13 -> V_144 , & V_13 -> V_99 ,
F_5 ( V_4 , V_13 ) ) ;
if ( V_84 )
goto V_141;
} else {
V_13 -> V_99 = V_100 ;
}
V_84 = F_79 ( V_2 , V_4 , V_13 , V_137 ) ;
if ( V_84 )
goto V_141;
return 0 ;
V_141:
return V_84 ;
}
static int F_87 ( struct V_162 * V_163 , int V_25 ,
T_2 V_164 , T_2 * V_165 )
{
int V_166 = 0 ;
int V_167 = V_25 ;
if ( ! V_163 ) {
* V_165 = V_164 ;
return 1 ;
}
* V_165 = 0 ;
while ( F_88 ( V_163 , V_167 ) ) {
struct V_159 * V_168 , * V_169 = F_89 ( V_163 ) ;
int V_170 ;
V_170 = F_90 ( V_163 ) ;
V_168 = F_91 ( V_169 , V_170 , V_171 ) ;
if ( V_168 && F_92 ( V_168 ) >=
F_93 ( struct V_172 , V_173 ) ) {
int V_174 = F_92 ( V_168 ) -
F_93 ( struct V_172 , V_173 ) ;
if ( V_174 <= V_175 )
* V_165 = F_94 ( V_176 , * V_165 ,
V_174 ) ;
}
V_166 ++ ;
V_163 = F_95 ( V_163 , & V_167 ) ;
}
return V_167 > 0 ? 0 : V_166 ;
}
static int F_96 ( struct V_147 * V_148 ,
struct V_1 * V_4 )
{
struct V_162 * V_163 = V_148 -> V_177 ;
struct V_159 * V_178 , * V_179 ;
int V_167 = V_148 -> V_180 ;
int V_166 = 0 ;
int V_84 = 0 ;
F_97 (rt) {
int V_170 ;
V_178 = NULL ;
V_179 = NULL ;
V_84 = - V_142 ;
if ( ! F_88 ( V_163 , V_167 ) )
goto V_141;
if ( V_163 -> V_181 || V_163 -> V_182 )
goto V_141;
V_170 = F_90 ( V_163 ) ;
if ( V_170 > 0 ) {
struct V_159 * V_169 = F_89 ( V_163 ) ;
V_178 = F_91 ( V_169 , V_170 , V_171 ) ;
V_179 = F_91 ( V_169 , V_170 , V_183 ) ;
}
V_84 = F_84 ( V_148 -> V_149 . V_150 , V_4 , V_13 ,
V_163 -> V_184 , V_178 , V_179 ) ;
if ( V_84 )
goto V_141;
if ( V_13 -> V_62 & ( V_63 | V_64 ) )
V_4 -> V_59 -- ;
V_163 = F_95 ( V_163 , & V_167 ) ;
V_166 ++ ;
} F_34 ( V_4 ) ;
V_4 -> V_16 = V_166 ;
return 0 ;
V_141:
return V_84 ;
}
static int F_98 ( struct V_147 * V_148 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_148 -> V_149 . V_150 ;
struct V_1 * V_4 , * V_112 ;
int V_84 = - V_142 ;
T_2 V_165 ;
unsigned V_3 ;
int V_166 ;
V_3 = V_148 -> V_185 ;
if ( ( V_3 == V_124 ) &&
( V_148 -> V_186 & V_187 ) ) {
V_3 = F_66 ( V_2 ) ;
}
if ( V_3 < V_47 )
goto V_141;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_141;
V_84 = - V_188 ;
if ( V_148 -> V_186 & V_189 )
goto V_141;
V_84 = - V_190 ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
V_112 = F_64 ( V_7 [ V_3 ] ) ;
if ( ( V_148 -> V_186 & V_191 ) && V_112 )
goto V_141;
V_84 = - V_190 ;
if ( ! ( V_148 -> V_186 & V_123 ) && V_112 )
goto V_141;
V_84 = - V_192 ;
if ( ! ( V_148 -> V_186 & V_187 ) && ! V_112 )
goto V_141;
V_84 = - V_142 ;
V_166 = F_87 ( V_148 -> V_177 , V_148 -> V_180 ,
V_148 -> V_157 , & V_165 ) ;
if ( V_166 == 0 )
goto V_141;
V_84 = - V_151 ;
V_4 = F_55 ( V_166 , V_165 ) ;
if ( ! V_4 )
goto V_141;
V_4 -> V_193 = V_148 -> V_194 ;
V_4 -> V_68 = V_148 -> V_195 ;
if ( V_148 -> V_177 )
V_84 = F_96 ( V_148 , V_4 ) ;
else
V_84 = F_83 ( V_148 , V_4 ) ;
if ( V_84 )
goto V_196;
F_62 ( V_2 , V_3 , V_4 , & V_148 -> V_149 ) ;
return 0 ;
V_196:
F_58 ( V_4 ) ;
V_141:
return V_84 ;
}
static int F_99 ( struct V_147 * V_148 )
{
struct V_2 * V_2 = V_148 -> V_149 . V_150 ;
unsigned V_3 ;
int V_84 = - V_142 ;
V_3 = V_148 -> V_185 ;
if ( V_3 < V_47 )
goto V_141;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_141;
F_62 ( V_2 , V_3 , NULL , & V_148 -> V_149 ) ;
V_84 = 0 ;
V_141:
return V_84 ;
}
static void F_100 ( struct V_26 * V_27 ,
struct V_197 * V_198 )
{
struct V_199 * V_200 ;
int V_97 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
F_101 (i) {
struct V_197 V_201 ;
unsigned int V_202 ;
V_200 = F_102 ( V_27 -> V_198 , V_97 ) ;
do {
V_202 = F_103 ( & V_200 -> V_203 ) ;
V_201 = V_200 -> V_198 ;
} while ( F_104 ( & V_200 -> V_203 , V_202 ) );
V_198 -> V_86 += V_201 . V_86 ;
V_198 -> V_87 += V_201 . V_87 ;
V_198 -> V_30 += V_201 . V_30 ;
V_198 -> V_31 += V_201 . V_31 ;
V_198 -> V_105 += V_201 . V_105 ;
V_198 -> V_104 += V_201 . V_104 ;
V_198 -> V_89 += V_201 . V_89 ;
V_198 -> V_204 += V_201 . V_204 ;
V_198 -> V_93 += V_201 . V_93 ;
}
}
static int F_105 ( struct V_23 * V_24 ,
const struct V_8 * V_9 )
{
struct V_197 * V_198 ;
struct V_26 * V_27 ;
struct V_159 * V_168 ;
V_27 = F_15 ( V_9 ) ;
if ( ! V_27 )
return - V_205 ;
V_168 = F_106 ( V_24 , V_206 ,
sizeof( struct V_197 ) ,
V_207 ) ;
if ( ! V_168 )
return - V_208 ;
V_198 = F_107 ( V_168 ) ;
F_100 ( V_27 , V_198 ) ;
return 0 ;
}
static T_4 F_108 ( const struct V_8 * V_9 )
{
struct V_26 * V_27 ;
V_27 = F_15 ( V_9 ) ;
if ( ! V_27 )
return 0 ;
return F_109 ( sizeof( struct V_197 ) ) ;
}
static int F_110 ( struct V_23 * V_24 , struct V_26 * V_27 ,
T_3 V_118 , T_3 V_209 , int V_119 ,
unsigned int V_10 , int type )
{
struct V_116 * V_117 ;
struct V_210 * V_211 ;
bool V_212 = false ;
V_117 = F_111 ( V_24 , V_118 , V_209 , V_119 , sizeof( struct V_210 ) ,
V_10 ) ;
if ( ! V_117 )
return - V_208 ;
if ( type == V_213 )
V_212 = true ;
V_211 = F_112 ( V_117 ) ;
V_211 -> V_214 = V_215 ;
if ( F_113 ( V_24 , V_216 , V_27 -> V_9 -> V_217 ) < 0 )
goto V_218;
if ( ( V_212 || type == V_219 ) &&
F_113 ( V_24 , V_219 ,
V_27 -> V_88 ) < 0 )
goto V_218;
F_114 ( V_24 , V_117 ) ;
return 0 ;
V_218:
F_115 ( V_24 , V_117 ) ;
return - V_208 ;
}
static int F_116 ( int type )
{
int V_220 = F_117 ( sizeof( struct V_210 ) )
+ F_118 ( 4 ) ;
bool V_212 = false ;
if ( type == V_213 )
V_212 = true ;
if ( V_212 || type == V_219 )
V_220 += F_118 ( 4 ) ;
return V_220 ;
}
static void F_119 ( struct V_2 * V_2 , int type ,
struct V_26 * V_27 )
{
struct V_23 * V_24 ;
int V_84 = - V_221 ;
V_24 = F_120 ( F_116 ( type ) , V_110 ) ;
if ( ! V_24 )
goto V_141;
V_84 = F_110 ( V_24 , V_27 , 0 , 0 , V_222 ,
0 , type ) ;
if ( V_84 < 0 ) {
F_121 ( V_84 == - V_208 ) ;
F_54 ( V_24 ) ;
goto V_141;
}
F_122 ( V_24 , V_2 , 0 , V_223 , NULL , V_110 ) ;
return;
V_141:
if ( V_84 < 0 )
F_123 ( V_2 , V_223 , V_84 ) ;
}
static int F_124 ( struct V_23 * V_224 ,
struct V_116 * V_117 )
{
struct V_2 * V_2 = F_125 ( V_224 -> V_225 ) ;
struct V_159 * V_226 [ V_227 + 1 ] ;
struct V_210 * V_211 ;
struct V_8 * V_9 ;
struct V_26 * V_27 ;
struct V_23 * V_24 ;
int V_217 ;
int V_84 ;
V_84 = F_126 ( V_117 , sizeof( * V_211 ) , V_226 , V_227 ,
V_228 ) ;
if ( V_84 < 0 )
goto V_141;
V_84 = - V_142 ;
if ( ! V_226 [ V_216 ] )
goto V_141;
V_217 = F_127 ( V_226 [ V_216 ] ) ;
V_9 = F_128 ( V_2 , V_217 ) ;
if ( ! V_9 )
goto V_141;
V_27 = F_15 ( V_9 ) ;
if ( ! V_27 )
goto V_141;
V_84 = - V_221 ;
V_24 = F_120 ( F_116 ( V_213 ) , V_110 ) ;
if ( ! V_24 )
goto V_141;
V_84 = F_110 ( V_24 , V_27 ,
F_129 ( V_224 ) . V_118 ,
V_117 -> V_229 , V_222 , 0 ,
V_213 ) ;
if ( V_84 < 0 ) {
F_121 ( V_84 == - V_208 ) ;
F_54 ( V_24 ) ;
goto V_141;
}
V_84 = F_130 ( V_24 , V_2 , F_129 ( V_224 ) . V_118 ) ;
V_141:
return V_84 ;
}
static int F_131 ( struct V_23 * V_24 ,
struct V_230 * V_231 )
{
struct V_2 * V_2 = F_125 ( V_24 -> V_225 ) ;
struct V_232 * V_233 ;
struct V_8 * V_9 ;
struct V_26 * V_27 ;
int V_234 , V_235 ;
int V_236 , V_237 ;
V_237 = V_231 -> args [ 0 ] ;
V_235 = V_234 = V_231 -> args [ 1 ] ;
for ( V_236 = V_237 ; V_236 < V_238 ; V_236 ++ , V_235 = 0 ) {
V_234 = 0 ;
V_233 = & V_2 -> V_239 [ V_236 ] ;
F_132 () ;
V_231 -> V_209 = V_2 -> V_240 ;
F_133 (dev, head, index_hlist) {
if ( V_234 < V_235 )
goto V_241;
V_27 = F_15 ( V_9 ) ;
if ( ! V_27 )
goto V_241;
if ( F_110 ( V_24 , V_27 ,
F_129 ( V_231 -> V_24 ) . V_118 ,
V_231 -> V_117 -> V_229 ,
V_222 ,
V_242 ,
V_213 ) < 0 ) {
F_134 () ;
goto V_243;
}
F_135 ( V_231 , F_136 ( V_24 ) ) ;
V_241:
V_234 ++ ;
}
F_134 () ;
}
V_243:
V_231 -> args [ 0 ] = V_236 ;
V_231 -> args [ 1 ] = V_234 ;
return V_24 -> V_25 ;
}
static int F_137 ( struct V_244 * V_245 , int V_246 ,
void T_5 * V_247 ,
T_4 * V_248 , T_6 * V_249 )
{
int V_250 = * ( int * ) V_245 -> V_251 ;
int V_252 = F_138 ( V_245 , V_246 , V_247 , V_248 , V_249 ) ;
if ( V_246 ) {
struct V_26 * V_27 = V_245 -> V_253 ;
int V_97 = ( int * ) V_245 -> V_251 - ( int * ) V_27 ;
struct V_2 * V_2 = V_245 -> V_254 ;
int V_255 = * ( int * ) V_245 -> V_251 ;
if ( V_97 == F_93 ( struct V_26 , V_88 ) &&
V_255 != V_250 ) {
F_119 ( V_2 ,
V_219 ,
V_27 ) ;
}
}
return V_252 ;
}
static int F_139 ( struct V_8 * V_9 ,
struct V_26 * V_27 )
{
char V_256 [ sizeof( L_2 ) + V_257 ] ;
struct V_2 * V_2 = F_18 ( V_9 ) ;
struct V_244 * V_258 ;
int V_97 ;
V_258 = F_140 ( & V_259 , sizeof( V_259 ) , V_110 ) ;
if ( ! V_258 )
goto V_61;
for ( V_97 = 0 ; V_97 < F_141 ( V_259 ) ; V_97 ++ ) {
V_258 [ V_97 ] . V_251 = ( char * ) V_27 + ( V_260 ) V_258 [ V_97 ] . V_251 ;
V_258 [ V_97 ] . V_253 = V_27 ;
V_258 [ V_97 ] . V_254 = V_2 ;
}
snprintf ( V_256 , sizeof( V_256 ) , L_3 , V_9 -> V_261 ) ;
V_27 -> V_262 = F_142 ( F_18 ( V_9 ) , V_256 , V_258 ) ;
if ( ! V_27 -> V_262 )
goto free;
return 0 ;
free:
F_143 ( V_258 ) ;
V_61:
return - V_221 ;
}
static void F_144 ( struct V_26 * V_27 )
{
struct V_244 * V_258 ;
V_258 = V_27 -> V_262 -> V_263 ;
F_145 ( V_27 -> V_262 ) ;
F_143 ( V_258 ) ;
}
static struct V_26 * F_146 ( struct V_8 * V_9 )
{
struct V_26 * V_27 ;
int V_84 = - V_151 ;
int V_97 ;
F_63 () ;
V_27 = F_57 ( sizeof( * V_27 ) , V_110 ) ;
if ( ! V_27 )
return F_73 ( V_84 ) ;
V_27 -> V_198 = F_147 ( struct V_199 ) ;
if ( ! V_27 -> V_198 )
goto free;
F_101 (i) {
struct V_199 * V_264 ;
V_264 = F_102 ( V_27 -> V_198 , V_97 ) ;
F_148 ( & V_264 -> V_203 ) ;
}
V_84 = F_139 ( V_9 , V_27 ) ;
if ( V_84 )
goto free;
V_27 -> V_9 = V_9 ;
F_65 ( V_9 -> V_265 , V_27 ) ;
return V_27 ;
free:
F_149 ( V_27 -> V_198 ) ;
F_143 ( V_27 ) ;
return F_73 ( V_84 ) ;
}
static void F_150 ( struct V_266 * V_233 )
{
struct V_26 * V_27 = F_151 ( V_233 , struct V_26 , V_267 ) ;
F_149 ( V_27 -> V_198 ) ;
F_143 ( V_27 ) ;
}
static void F_152 ( struct V_8 * V_9 , int V_119 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_18 ( V_9 ) ;
unsigned int V_62 = V_63 | V_64 ;
unsigned int V_58 ;
unsigned V_3 ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_64 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_58 = 0 ;
F_97 (rt) {
if ( F_64 ( V_13 -> V_94 ) != V_9 )
goto V_268;
switch ( V_119 ) {
case V_269 :
case V_270 :
V_13 -> V_62 |= V_63 ;
case V_271 :
V_13 -> V_62 |= V_64 ;
break;
}
if ( V_119 == V_270 )
F_81 ( V_13 -> V_94 , NULL ) ;
V_268:
if ( ! ( V_13 -> V_62 & V_62 ) )
V_58 ++ ;
} F_34 ( V_4 ) ;
F_153 ( V_4 -> V_59 , V_58 ) ;
}
}
static void F_154 ( struct V_8 * V_9 , unsigned int V_62 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_18 ( V_9 ) ;
unsigned V_3 ;
int V_58 ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_64 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_58 = 0 ;
F_97 (rt) {
struct V_8 * V_94 =
F_64 ( V_13 -> V_94 ) ;
if ( ! ( V_13 -> V_62 & V_62 ) ) {
V_58 ++ ;
continue;
}
if ( V_94 != V_9 )
continue;
V_58 ++ ;
V_13 -> V_62 &= ~ V_62 ;
} F_34 ( V_4 ) ;
F_32 ( V_4 -> V_59 ) = V_58 ;
}
}
static int F_155 ( struct V_272 * V_273 , unsigned long V_119 ,
void * V_274 )
{
struct V_8 * V_9 = F_156 ( V_274 ) ;
struct V_26 * V_27 ;
unsigned int V_10 ;
if ( V_119 == V_275 ) {
if ( V_9 -> type == V_276 ||
V_9 -> type == V_277 ||
V_9 -> type == V_278 ||
V_9 -> type == V_279 ||
V_9 -> type == V_280 ) {
V_27 = F_146 ( V_9 ) ;
if ( F_69 ( V_27 ) )
return F_157 ( F_80 ( V_27 ) ) ;
}
return V_281 ;
}
V_27 = F_15 ( V_9 ) ;
if ( ! V_27 )
return V_281 ;
switch ( V_119 ) {
case V_269 :
F_152 ( V_9 , V_119 ) ;
break;
case V_282 :
V_10 = F_82 ( V_9 ) ;
if ( V_10 & ( V_145 | V_146 ) )
F_154 ( V_9 , V_63 | V_64 ) ;
else
F_154 ( V_9 , V_63 ) ;
break;
case V_271 :
V_10 = F_82 ( V_9 ) ;
if ( V_10 & ( V_145 | V_146 ) )
F_154 ( V_9 , V_63 | V_64 ) ;
else
F_152 ( V_9 , V_119 ) ;
break;
case V_270 :
F_152 ( V_9 , V_119 ) ;
V_27 = F_15 ( V_9 ) ;
if ( V_27 ) {
F_144 ( V_27 ) ;
F_81 ( V_9 -> V_265 , NULL ) ;
F_158 ( & V_27 -> V_267 , F_150 ) ;
}
break;
case V_283 :
V_27 = F_15 ( V_9 ) ;
if ( V_27 ) {
int V_84 ;
F_144 ( V_27 ) ;
V_84 = F_139 ( V_9 , V_27 ) ;
if ( V_84 )
return F_157 ( V_84 ) ;
}
break;
}
return V_281 ;
}
static int F_159 ( struct V_23 * V_24 ,
T_2 V_258 , const void * V_125 , int V_284 )
{
static const int V_285 [ V_286 + 1 ] = {
V_287 , V_288 , V_289 , V_290 ,
} ;
struct V_159 * V_168 ;
struct V_172 * V_160 ;
int V_291 = V_292 ;
V_168 = F_160 ( V_24 , V_171 , V_284 + 2 ) ;
if ( ! V_168 )
return - V_208 ;
if ( V_258 <= V_286 )
V_291 = V_285 [ V_258 ] ;
V_160 = F_107 ( V_168 ) ;
V_160 -> V_293 = V_291 ;
memcpy ( V_160 -> V_173 , V_125 , V_284 ) ;
return 0 ;
}
int F_161 ( struct V_23 * V_24 , int V_294 ,
T_2 V_295 , const T_3 V_46 [] )
{
struct V_159 * V_168 ;
struct V_21 * V_296 ;
bool V_49 ;
int V_97 ;
V_168 = F_160 ( V_24 , V_294 , V_295 * 4 ) ;
if ( ! V_168 )
return - V_208 ;
V_296 = F_107 ( V_168 ) ;
V_49 = true ;
for ( V_97 = V_295 - 1 ; V_97 >= 0 ; V_97 -- ) {
V_296 [ V_97 ] = F_51 ( V_46 [ V_97 ] , 0 , 0 , V_49 ) ;
V_49 = false ;
}
return 0 ;
}
int F_85 ( const struct V_159 * V_168 ,
T_3 V_297 , T_2 * V_295 , T_3 V_46 [] )
{
unsigned V_25 = F_92 ( V_168 ) ;
unsigned V_298 ;
struct V_21 * V_296 ;
bool V_49 ;
int V_97 ;
if ( V_25 & 3 )
return - V_142 ;
V_298 = V_25 / 4 ;
if ( V_298 > V_297 )
return - V_142 ;
V_296 = F_107 ( V_168 ) ;
V_49 = true ;
for ( V_97 = V_298 - 1 ; V_97 >= 0 ; V_97 -- , V_49 = false ) {
struct V_38 V_39 ;
V_39 = F_25 ( V_296 + V_97 ) ;
if ( ( V_39 . V_49 != V_49 ) || V_39 . V_73 || V_39 . V_299 )
return - V_142 ;
switch ( V_39 . V_46 ) {
case V_300 :
return - V_142 ;
}
V_46 [ V_97 ] = V_39 . V_46 ;
}
* V_295 = V_298 ;
return 0 ;
}
int F_86 ( const struct V_159 * V_168 , T_2 * V_174 ,
T_2 * V_301 , T_2 V_302 [] )
{
struct V_172 * V_160 = F_107 ( V_168 ) ;
int V_84 = - V_142 ;
int V_284 ;
if ( F_92 ( V_168 ) < F_93 ( struct V_172 , V_173 ) )
goto V_141;
V_284 = F_92 ( V_168 ) -
F_93 ( struct V_172 , V_173 ) ;
if ( V_284 > V_175 )
goto V_141;
switch ( V_160 -> V_293 ) {
case V_290 :
* V_301 = V_101 ;
break;
case V_287 :
* V_301 = V_138 ;
if ( V_284 != 4 )
goto V_141;
break;
case V_288 :
* V_301 = V_139 ;
if ( V_284 != 16 )
goto V_141;
break;
default:
goto V_141;
}
memcpy ( V_302 , V_160 -> V_173 , V_284 ) ;
* V_174 = V_284 ;
V_84 = 0 ;
V_141:
return V_84 ;
}
static int F_162 ( struct V_23 * V_24 , struct V_116 * V_117 ,
struct V_147 * V_148 )
{
struct V_303 * V_304 ;
struct V_159 * V_226 [ V_305 + 1 ] ;
int V_3 ;
int V_84 ;
V_84 = F_126 ( V_117 , sizeof( * V_304 ) , V_226 , V_305 , V_306 ) ;
if ( V_84 < 0 )
goto V_141;
V_84 = - V_142 ;
V_304 = F_112 ( V_117 ) ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
if ( V_304 -> V_307 != V_215 )
goto V_141;
if ( V_304 -> V_308 != 20 )
goto V_141;
if ( V_304 -> V_309 != 0 )
goto V_141;
if ( V_304 -> V_310 != 0 )
goto V_141;
if ( V_304 -> V_311 != V_312 )
goto V_141;
if ( V_304 -> V_313 != V_314 )
goto V_141;
if ( V_304 -> V_315 != V_316 )
goto V_141;
if ( V_304 -> V_317 != 0 )
goto V_141;
V_148 -> V_185 = V_124 ;
V_148 -> V_194 = V_304 -> V_318 ;
V_148 -> V_155 = V_100 ;
V_148 -> V_186 = V_117 -> V_319 ;
V_148 -> V_149 . V_118 = F_129 ( V_24 ) . V_118 ;
V_148 -> V_149 . V_117 = V_117 ;
V_148 -> V_149 . V_150 = F_125 ( V_24 -> V_225 ) ;
for ( V_3 = 0 ; V_3 <= V_305 ; V_3 ++ ) {
struct V_159 * V_168 = V_226 [ V_3 ] ;
if ( ! V_168 )
continue;
switch ( V_3 ) {
case V_320 :
V_148 -> V_158 = F_163 ( V_168 ) ;
break;
case V_183 :
if ( F_85 ( V_168 , V_153 ,
& V_148 -> V_152 ,
V_148 -> V_154 ) )
goto V_141;
break;
case V_321 :
{
T_2 V_322 ;
if ( F_85 ( V_168 , 1 , & V_322 ,
& V_148 -> V_185 ) )
goto V_141;
if ( V_148 -> V_185 < V_47 )
goto V_141;
break;
}
case V_171 :
{
if ( F_86 ( V_168 , & V_148 -> V_157 ,
& V_148 -> V_155 , V_148 -> V_156 ) )
goto V_141;
break;
}
case V_323 :
{
V_148 -> V_177 = F_107 ( V_168 ) ;
V_148 -> V_180 = F_92 ( V_168 ) ;
break;
}
default:
goto V_141;
}
}
V_84 = 0 ;
V_141:
return V_84 ;
}
static int F_164 ( struct V_23 * V_24 , struct V_116 * V_117 )
{
struct V_147 V_148 ;
int V_84 ;
V_84 = F_162 ( V_24 , V_117 , & V_148 ) ;
if ( V_84 < 0 )
return V_84 ;
return F_99 ( & V_148 ) ;
}
static int F_165 ( struct V_23 * V_24 , struct V_116 * V_117 )
{
struct V_147 V_148 ;
int V_84 ;
V_84 = F_162 ( V_24 , V_117 , & V_148 ) ;
if ( V_84 < 0 )
return V_84 ;
return F_98 ( & V_148 ) ;
}
static int F_166 ( struct V_23 * V_24 , T_3 V_118 , T_3 V_209 , int V_119 ,
T_3 V_46 , struct V_1 * V_4 , int V_10 )
{
struct V_8 * V_9 ;
struct V_116 * V_117 ;
struct V_303 * V_304 ;
V_117 = F_111 ( V_24 , V_118 , V_209 , V_119 , sizeof( * V_304 ) , V_10 ) ;
if ( V_117 == NULL )
return - V_208 ;
V_304 = F_112 ( V_117 ) ;
V_304 -> V_307 = V_215 ;
V_304 -> V_308 = 20 ;
V_304 -> V_309 = 0 ;
V_304 -> V_310 = 0 ;
V_304 -> V_311 = V_312 ;
V_304 -> V_318 = V_4 -> V_193 ;
V_304 -> V_313 = V_314 ;
V_304 -> V_315 = V_316 ;
V_304 -> V_317 = 0 ;
if ( F_161 ( V_24 , V_321 , 1 , & V_46 ) )
goto V_218;
if ( V_4 -> V_16 == 1 ) {
const struct V_12 * V_13 = V_4 -> V_15 ;
if ( V_13 -> V_20 &&
F_161 ( V_24 , V_183 , V_13 -> V_20 ,
V_13 -> V_98 ) )
goto V_218;
if ( V_13 -> V_99 != V_100 &&
F_159 ( V_24 , V_13 -> V_99 , F_7 ( V_4 , V_13 ) ,
V_13 -> V_144 ) )
goto V_218;
V_9 = F_64 ( V_13 -> V_94 ) ;
if ( V_9 && F_167 ( V_24 , V_320 , V_9 -> V_217 ) )
goto V_218;
if ( V_13 -> V_62 & V_64 )
V_304 -> V_317 |= V_64 ;
if ( V_13 -> V_62 & V_63 )
V_304 -> V_317 |= V_63 ;
} else {
struct V_162 * V_163 ;
struct V_159 * V_324 ;
int V_325 = 0 ;
int V_326 = 0 ;
V_324 = F_168 ( V_24 , V_323 ) ;
if ( ! V_324 )
goto V_218;
F_33 (rt) {
V_163 = F_169 ( V_24 , sizeof( * V_163 ) ) ;
if ( ! V_163 )
goto V_218;
V_9 = F_64 ( V_13 -> V_94 ) ;
if ( V_9 )
V_163 -> V_184 = V_9 -> V_217 ;
if ( V_13 -> V_62 & V_64 ) {
V_163 -> V_182 |= V_64 ;
V_326 ++ ;
}
if ( V_13 -> V_62 & V_63 ) {
V_163 -> V_182 |= V_63 ;
V_325 ++ ;
}
if ( V_13 -> V_20 && F_161 ( V_24 , V_183 ,
V_13 -> V_20 ,
V_13 -> V_98 ) )
goto V_218;
if ( V_13 -> V_99 != V_100 &&
F_159 ( V_24 , V_13 -> V_99 ,
F_7 ( V_4 , V_13 ) ,
V_13 -> V_144 ) )
goto V_218;
V_163 -> V_327 = F_170 ( V_24 ) - ( void * ) V_163 ;
} F_34 ( V_4 ) ;
if ( V_326 == V_4 -> V_16 )
V_304 -> V_317 |= V_64 ;
if ( V_325 == V_4 -> V_16 )
V_304 -> V_317 |= V_63 ;
F_171 ( V_24 , V_324 ) ;
}
F_114 ( V_24 , V_117 ) ;
return 0 ;
V_218:
F_115 ( V_24 , V_117 ) ;
return - V_208 ;
}
static int F_172 ( struct V_23 * V_24 , struct V_230 * V_231 )
{
struct V_2 * V_2 = F_125 ( V_24 -> V_225 ) ;
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned int V_3 ;
F_63 () ;
V_3 = V_231 -> args [ 0 ] ;
if ( V_3 < V_47 )
V_3 = V_47 ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_64 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_166 ( V_24 , F_129 ( V_231 -> V_24 ) . V_118 ,
V_231 -> V_117 -> V_229 , V_120 ,
V_3 , V_4 , V_242 ) < 0 )
break;
}
V_231 -> args [ 0 ] = V_3 ;
return V_24 -> V_25 ;
}
static inline T_4 F_173 ( struct V_1 * V_4 )
{
T_4 V_328 =
F_117 ( sizeof( struct V_303 ) )
+ F_118 ( 4 ) ;
if ( V_4 -> V_16 == 1 ) {
struct V_12 * V_13 = V_4 -> V_15 ;
if ( V_13 -> V_94 )
V_328 += F_118 ( 4 ) ;
if ( V_13 -> V_99 != V_100 )
V_328 += F_118 ( 2 + V_13 -> V_144 ) ;
if ( V_13 -> V_20 )
V_328 += F_118 ( V_13 -> V_20 * 4 ) ;
} else {
T_4 V_329 = 0 ;
F_33 (rt) {
V_329 += F_118 ( sizeof( struct V_162 ) ) ;
if ( V_13 -> V_99 != V_100 )
V_329 += F_118 ( 2 + V_13 -> V_144 ) ;
if ( V_13 -> V_20 )
V_329 += F_118 ( V_13 -> V_20 * 4 ) ;
} F_34 ( V_4 ) ;
V_328 += F_118 ( V_329 ) ;
}
return V_328 ;
}
static void F_61 ( int V_119 , T_3 V_46 , struct V_1 * V_4 ,
struct V_116 * V_117 , struct V_2 * V_2 , T_3 V_118 ,
unsigned int V_122 )
{
struct V_23 * V_24 ;
T_3 V_209 = V_117 ? V_117 -> V_229 : 0 ;
int V_84 = - V_221 ;
V_24 = F_120 ( F_173 ( V_4 ) , V_110 ) ;
if ( V_24 == NULL )
goto V_141;
V_84 = F_166 ( V_24 , V_118 , V_209 , V_119 , V_46 , V_4 , V_122 ) ;
if ( V_84 < 0 ) {
F_121 ( V_84 == - V_208 ) ;
F_54 ( V_24 ) ;
goto V_141;
}
F_122 ( V_24 , V_2 , V_118 , V_330 , V_117 , V_110 ) ;
return;
V_141:
if ( V_84 < 0 )
F_123 ( V_2 , V_330 , V_84 ) ;
}
static int F_174 ( struct V_2 * V_2 , T_4 V_331 )
{
T_4 V_220 = sizeof( struct V_1 * ) * V_331 ;
T_4 V_332 ;
T_4 V_333 ;
struct V_1 T_1 * * V_295 = NULL , * * V_112 ;
struct V_1 * V_334 = NULL , * V_335 = NULL ;
unsigned V_3 ;
if ( V_220 ) {
V_295 = F_57 ( V_220 , V_110 | V_336 | V_337 ) ;
if ( ! V_295 )
V_295 = F_175 ( V_220 ) ;
if ( ! V_295 )
goto V_338;
}
if ( V_331 > V_339 ) {
struct V_8 * V_340 = V_2 -> V_341 ;
V_334 = F_55 ( 1 , V_340 -> V_143 ) ;
if ( ! V_334 )
goto V_342;
F_81 ( V_334 -> V_15 -> V_94 , V_340 ) ;
V_334 -> V_193 = V_343 ;
V_334 -> V_68 = V_70 ;
V_334 -> V_15 -> V_99 = V_101 ;
V_334 -> V_15 -> V_144 = V_340 -> V_143 ;
memcpy ( F_5 ( V_334 , V_334 -> V_15 ) , V_340 -> V_102 ,
V_340 -> V_143 ) ;
}
if ( V_331 > V_344 ) {
struct V_8 * V_340 = V_2 -> V_341 ;
V_335 = F_55 ( 1 , V_340 -> V_143 ) ;
if ( ! V_335 )
goto V_345;
F_81 ( V_335 -> V_15 -> V_94 , V_340 ) ;
V_335 -> V_193 = V_343 ;
V_335 -> V_68 = V_74 ;
V_335 -> V_15 -> V_99 = V_101 ;
V_335 -> V_15 -> V_144 = V_340 -> V_143 ;
memcpy ( F_5 ( V_335 , V_335 -> V_15 ) , V_340 -> V_102 ,
V_340 -> V_143 ) ;
}
F_176 () ;
V_112 = F_64 ( V_2 -> V_5 . V_7 ) ;
V_332 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_331 ; V_3 < V_332 ; V_3 ++ )
F_62 ( V_2 , V_3 , NULL , NULL ) ;
V_333 = V_220 ;
if ( V_332 < V_331 )
V_333 = V_332 * sizeof( struct V_1 * ) ;
memcpy ( V_295 , V_112 , V_333 ) ;
if ( ( V_332 <= V_344 ) &&
( V_331 > V_344 ) ) {
F_81 ( V_295 [ V_344 ] , V_335 ) ;
V_335 = NULL ;
}
if ( ( V_332 <= V_339 ) &&
( V_331 > V_339 ) ) {
F_81 ( V_295 [ V_339 ] , V_334 ) ;
V_334 = NULL ;
}
V_2 -> V_5 . V_6 = V_331 ;
F_65 ( V_2 -> V_5 . V_7 , V_295 ) ;
F_177 () ;
F_58 ( V_335 ) ;
F_58 ( V_334 ) ;
if ( V_112 ) {
F_178 () ;
F_179 ( V_112 ) ;
}
return 0 ;
V_345:
F_58 ( V_334 ) ;
V_342:
F_179 ( V_295 ) ;
V_338:
return - V_151 ;
}
static int F_180 ( struct V_244 * V_258 , int V_246 ,
void T_5 * V_247 , T_4 * V_248 , T_6 * V_249 )
{
struct V_2 * V_2 = V_258 -> V_251 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_252 ;
struct V_244 V_346 = {
. V_347 = V_258 -> V_347 ,
. V_251 = & V_6 ,
. V_348 = sizeof( int ) ,
. V_349 = V_258 -> V_349 ,
. V_253 = & V_350 ,
. V_254 = & V_351 ,
} ;
V_252 = F_181 ( & V_346 , V_246 , V_247 , V_248 , V_249 ) ;
if ( V_246 && V_252 == 0 )
V_252 = F_174 ( V_2 , V_6 ) ;
return V_252 ;
}
static int F_182 ( struct V_2 * V_2 )
{
struct V_244 * V_258 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_258 = F_140 ( V_352 , sizeof( V_352 ) , V_110 ) ;
if ( V_258 == NULL )
return - V_151 ;
V_258 [ 0 ] . V_251 = V_2 ;
V_2 -> V_5 . V_245 = F_142 ( V_2 , L_4 , V_258 ) ;
if ( V_2 -> V_5 . V_245 == NULL ) {
F_143 ( V_258 ) ;
return - V_151 ;
}
return 0 ;
}
static void F_183 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
struct V_244 * V_258 ;
unsigned int V_3 ;
V_258 = V_2 -> V_5 . V_245 -> V_263 ;
F_145 ( V_2 -> V_5 . V_245 ) ;
F_143 ( V_258 ) ;
F_176 () ;
V_7 = F_64 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_64 ( V_7 [ V_3 ] ) ;
F_81 ( V_7 [ V_3 ] , NULL ) ;
F_60 ( V_2 , V_3 , V_4 , NULL , NULL ) ;
F_58 ( V_4 ) ;
}
F_177 () ;
F_179 ( V_7 ) ;
}
static int T_7 F_184 ( void )
{
int V_84 ;
F_185 ( sizeof( struct V_21 ) != 4 ) ;
V_84 = F_186 ( & V_353 ) ;
if ( V_84 )
goto V_61;
V_84 = F_187 ( & V_354 ) ;
if ( V_84 )
goto V_355;
F_188 ( & V_356 ) ;
F_189 ( & V_357 ) ;
F_190 ( V_358 , V_120 , F_165 , NULL , NULL ) ;
F_190 ( V_358 , V_121 , F_164 , NULL , NULL ) ;
F_190 ( V_358 , V_359 , NULL , F_172 , NULL ) ;
F_190 ( V_358 , V_360 , F_124 ,
F_131 , NULL ) ;
V_84 = 0 ;
V_61:
return V_84 ;
V_355:
F_191 ( & V_353 ) ;
goto V_61;
}
static void T_8 F_192 ( void )
{
F_193 ( V_358 ) ;
F_194 ( & V_357 ) ;
F_195 ( & V_356 ) ;
F_196 ( & V_354 ) ;
F_191 ( & V_353 ) ;
}
