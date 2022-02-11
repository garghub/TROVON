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
static inline struct V_8 * F_3 ( const struct V_9 * V_10 )
{
return F_4 ( V_10 -> V_11 ) ;
}
bool F_5 ( const struct V_9 * V_10 )
{
return V_10 && ( V_10 -> V_12 & V_13 ) && F_6 ( V_10 ) ;
}
static unsigned int F_7 ( const struct V_1 * V_4 )
{
return V_4 -> V_14 * sizeof( struct V_15 ) ;
}
unsigned int F_8 ( const struct V_9 * V_10 )
{
return V_10 -> V_16 ;
}
bool F_9 ( const struct V_17 * V_18 , unsigned int V_16 )
{
if ( V_18 -> V_19 <= V_16 )
return false ;
if ( F_10 ( V_18 ) && F_11 ( V_18 ) <= V_16 )
return false ;
return true ;
}
static bool F_12 ( struct V_1 * V_4 , struct V_17 * V_18 ,
struct V_20 V_21 )
{
enum V_22 V_23 ;
bool V_24 = false ;
if ( ! F_13 ( V_18 , 12 ) )
return false ;
V_23 = V_4 -> V_25 ;
if ( V_23 == V_26 )
V_23 = F_14 ( V_18 ) -> V_27 ;
switch ( V_23 ) {
case V_28 : {
struct V_29 * V_30 = F_14 ( V_18 ) ;
V_18 -> V_31 = F_15 ( V_32 ) ;
F_16 ( & V_30 -> V_33 ,
F_15 ( V_30 -> V_34 << 8 ) ,
F_15 ( V_21 . V_34 << 8 ) ) ;
V_30 -> V_34 = V_21 . V_34 ;
V_24 = true ;
break;
}
case V_35 : {
struct V_36 * V_37 = F_17 ( V_18 ) ;
V_18 -> V_31 = F_15 ( V_38 ) ;
V_37 -> V_39 = V_21 . V_34 ;
V_24 = true ;
break;
}
case V_26 :
break;
}
return V_24 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_9 * V_10 ,
struct V_40 * V_41 , struct V_9 * V_42 )
{
struct V_2 * V_2 = F_19 ( V_10 ) ;
struct V_15 * V_43 ;
struct V_1 * V_4 ;
struct V_20 V_21 ;
struct V_9 * V_44 ;
struct V_8 * V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_16 ;
int V_48 ;
V_45 = F_3 ( V_10 ) ;
if ( ! V_45 || ! V_45 -> V_49 )
goto V_50;
if ( V_18 -> V_51 != V_52 )
goto V_50;
if ( ( V_18 = F_20 ( V_18 , V_53 ) ) == NULL )
goto V_50;
if ( ! F_13 ( V_18 , sizeof( * V_43 ) ) )
goto V_50;
V_43 = F_21 ( V_18 ) ;
V_21 = F_22 ( V_43 ) ;
F_23 ( V_18 , sizeof( * V_43 ) ) ;
F_24 ( V_18 ) ;
F_25 ( V_18 ) ;
V_4 = F_1 ( V_2 , V_21 . V_54 ) ;
if ( ! V_4 )
goto V_50;
V_44 = F_2 ( V_4 -> V_55 ) ;
if ( ! F_5 ( V_44 ) )
goto V_50;
if ( F_26 ( V_18 ) )
goto V_50;
F_27 ( V_18 ) ;
if ( V_21 . V_34 <= 1 )
goto V_50;
V_21 . V_34 -= 1 ;
V_47 = F_7 ( V_4 ) ;
V_16 = F_8 ( V_44 ) ;
if ( F_9 ( V_18 , V_16 - V_47 ) )
goto V_50;
V_46 = F_28 ( V_44 ) ;
if ( ! V_44 -> V_56 )
V_46 = 0 ;
if ( F_29 ( V_18 , V_46 + V_47 ) )
goto V_50;
V_18 -> V_10 = V_44 ;
V_18 -> V_31 = F_15 ( V_57 ) ;
if ( F_30 ( ! V_47 && V_21 . V_58 ) ) {
if ( ! F_12 ( V_4 , V_18 , V_21 ) )
goto V_50;
} else {
bool V_58 ;
int V_59 ;
F_31 ( V_18 , V_47 ) ;
F_24 ( V_18 ) ;
V_43 = F_21 ( V_18 ) ;
V_58 = V_21 . V_58 ;
for ( V_59 = V_4 -> V_14 - 1 ; V_59 >= 0 ; V_59 -- ) {
V_43 [ V_59 ] = F_32 ( V_4 -> V_60 [ V_59 ] , V_21 . V_34 , 0 , V_58 ) ;
V_58 = false ;
}
}
V_48 = F_33 ( V_4 -> V_61 , V_44 , V_4 -> V_62 , V_18 ) ;
if ( V_48 )
F_34 ( L_1 ,
V_63 , V_48 ) ;
return 0 ;
V_50:
F_35 ( V_18 ) ;
return V_64 ;
}
static struct V_1 * F_36 ( T_2 V_65 )
{
struct V_1 * V_4 ;
V_4 = F_37 ( sizeof( * V_4 ) + V_65 , V_66 ) ;
if ( V_4 )
V_4 -> V_67 = V_65 ;
return V_4 ;
}
static void F_38 ( struct V_1 * V_4 )
{
if ( V_4 )
F_39 ( V_4 , V_68 ) ;
}
static void F_40 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_69 , struct V_1 * V_70 ,
const struct V_71 * V_72 )
{
struct V_73 * V_74 = V_72 ? V_72 -> V_74 : NULL ;
unsigned V_75 = V_72 ? V_72 -> V_75 : 0 ;
int V_76 = V_70 ? V_77 : V_78 ;
struct V_1 * V_4 = V_70 ? V_70 : V_69 ;
unsigned V_79 = ( V_69 && V_70 ) ? V_80 : 0 ;
if ( V_4 && ( V_3 >= V_81 ) )
F_41 ( V_76 , V_3 , V_4 , V_74 , V_2 , V_75 , V_79 ) ;
}
static void F_42 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_9 * V_10 , struct V_1 * V_70 ,
const struct V_71 * V_72 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 , * V_69 = NULL ;
F_43 () ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_44 ( V_7 [ V_3 ] ) ;
if ( ! V_10 || ( V_4 && ( F_44 ( V_4 -> V_55 ) == V_10 ) ) ) {
F_45 ( V_7 [ V_3 ] , V_70 ) ;
V_69 = V_4 ;
}
F_40 ( V_2 , V_3 , V_69 , V_70 , V_72 ) ;
F_38 ( V_69 ) ;
}
static unsigned F_46 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_2 V_6 ;
unsigned V_3 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_81 ; V_3 < V_6 ;
V_3 ++ ) {
if ( ! F_44 ( V_7 [ V_3 ] ) )
return V_3 ;
}
return V_82 ;
}
static struct V_9 * F_47 ( struct V_2 * V_2 , void * V_83 )
{
struct V_9 * V_10 ;
struct V_84 * V_4 ;
struct V_85 V_86 ;
memcpy ( & V_86 , V_83 , sizeof( struct V_85 ) ) ;
V_4 = F_48 ( V_2 , V_86 . V_87 , 0 , 0 , 0 ) ;
if ( F_49 ( V_4 ) )
return F_50 ( V_4 ) ;
V_10 = V_4 -> V_88 . V_10 ;
F_51 ( V_10 ) ;
F_52 ( V_4 ) ;
return V_10 ;
}
static struct V_9 * F_47 ( struct V_2 * V_2 , void * V_83 )
{
return F_53 ( - V_89 ) ;
}
static struct V_9 * F_54 ( struct V_2 * V_2 , void * V_83 )
{
struct V_9 * V_10 ;
struct V_90 * V_88 ;
struct V_91 V_92 ;
int V_48 ;
if ( ! V_93 )
return F_53 ( - V_89 ) ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
memcpy ( & V_92 . V_86 , V_83 , sizeof( struct V_94 ) ) ;
V_48 = V_93 -> V_95 ( V_2 , NULL , & V_88 , & V_92 ) ;
if ( V_48 )
return F_53 ( V_48 ) ;
V_10 = V_88 -> V_10 ;
F_51 ( V_10 ) ;
F_55 ( V_88 ) ;
return V_10 ;
}
static struct V_9 * F_54 ( struct V_2 * V_2 , void * V_83 )
{
return F_53 ( - V_89 ) ;
}
static struct V_9 * F_56 ( struct V_2 * V_2 ,
struct V_96 * V_97 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_97 -> V_98 ) {
switch ( V_97 -> V_99 ) {
case V_100 :
V_10 = F_47 ( V_2 , V_97 -> V_101 ) ;
break;
case V_102 :
V_10 = F_54 ( V_2 , V_97 -> V_101 ) ;
break;
case V_103 :
break;
}
} else {
V_10 = F_57 ( V_2 , V_97 -> V_98 ) ;
}
if ( ! V_10 )
return F_53 ( - V_104 ) ;
return V_10 ;
}
static int F_58 ( struct V_96 * V_97 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_97 -> V_105 . V_106 ;
struct V_9 * V_10 = NULL ;
struct V_1 * V_4 , * V_69 ;
unsigned V_3 ;
int V_59 ;
int V_48 = - V_107 ;
V_3 = V_97 -> V_108 ;
if ( ( V_3 == V_82 ) &&
( V_97 -> V_109 & V_110 ) ) {
V_3 = F_46 ( V_2 ) ;
}
if ( V_3 < V_81 )
goto V_111;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_111;
if ( V_97 -> V_112 > V_113 )
goto V_111;
V_10 = F_56 ( V_2 , V_97 ) ;
if ( F_49 ( V_10 ) ) {
V_48 = F_59 ( V_10 ) ;
V_10 = NULL ;
goto V_111;
}
V_48 = - V_107 ;
if ( ! F_3 ( V_10 ) )
goto V_111;
V_48 = - V_107 ;
if ( ( V_97 -> V_99 == V_103 ) &&
( V_10 -> V_114 != V_97 -> V_115 ) )
goto V_111;
V_48 = - V_116 ;
if ( V_97 -> V_109 & V_117 )
goto V_111;
V_48 = - V_118 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_69 = F_44 ( V_7 [ V_3 ] ) ;
if ( ( V_97 -> V_109 & V_119 ) && V_69 )
goto V_111;
V_48 = - V_118 ;
if ( ! ( V_97 -> V_109 & V_80 ) && V_69 )
goto V_111;
V_48 = - V_120 ;
if ( ! ( V_97 -> V_109 & V_110 ) && ! V_69 )
goto V_111;
V_48 = - V_121 ;
V_4 = F_36 ( V_97 -> V_115 ) ;
if ( ! V_4 )
goto V_111;
V_4 -> V_14 = V_97 -> V_112 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_14 ; V_59 ++ )
V_4 -> V_60 [ V_59 ] = V_97 -> V_122 [ V_59 ] ;
V_4 -> V_123 = V_97 -> V_124 ;
F_60 ( V_4 -> V_55 , V_10 ) ;
V_4 -> V_25 = V_97 -> V_125 ;
V_4 -> V_61 = V_97 -> V_99 ;
memcpy ( V_4 -> V_62 , V_97 -> V_101 , V_97 -> V_115 ) ;
F_42 ( V_2 , V_3 , NULL , V_4 , & V_97 -> V_105 ) ;
F_61 ( V_10 ) ;
return 0 ;
V_111:
if ( V_10 )
F_61 ( V_10 ) ;
return V_48 ;
}
static int F_62 ( struct V_96 * V_97 )
{
struct V_2 * V_2 = V_97 -> V_105 . V_106 ;
unsigned V_3 ;
int V_48 = - V_107 ;
V_3 = V_97 -> V_108 ;
if ( V_3 < V_81 )
goto V_111;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_111;
F_42 ( V_2 , V_3 , NULL , NULL , & V_97 -> V_105 ) ;
V_48 = 0 ;
V_111:
return V_48 ;
}
static int F_63 ( struct V_9 * V_10 ,
struct V_8 * V_45 )
{
char V_126 [ sizeof( L_2 ) + V_127 ] ;
struct V_128 * V_129 ;
int V_59 ;
V_129 = F_64 ( & V_130 , sizeof( V_130 ) , V_66 ) ;
if ( ! V_129 )
goto V_131;
for ( V_59 = 0 ; V_59 < F_65 ( V_130 ) ; V_59 ++ )
V_129 [ V_59 ] . V_132 = ( char * ) V_45 + ( V_133 ) V_129 [ V_59 ] . V_132 ;
snprintf ( V_126 , sizeof( V_126 ) , L_3 , V_10 -> V_134 ) ;
V_45 -> V_135 = F_66 ( F_19 ( V_10 ) , V_126 , V_129 ) ;
if ( ! V_45 -> V_135 )
goto free;
return 0 ;
free:
F_67 ( V_129 ) ;
V_131:
return - V_136 ;
}
static void F_68 ( struct V_8 * V_45 )
{
struct V_128 * V_129 ;
V_129 = V_45 -> V_135 -> V_137 ;
F_69 ( V_45 -> V_135 ) ;
F_67 ( V_129 ) ;
}
static struct V_8 * F_70 ( struct V_9 * V_10 )
{
struct V_8 * V_45 ;
int V_48 = - V_121 ;
F_43 () ;
V_45 = F_37 ( sizeof( * V_45 ) , V_66 ) ;
if ( ! V_45 )
return F_53 ( V_48 ) ;
V_48 = F_63 ( V_10 , V_45 ) ;
if ( V_48 )
goto free;
F_45 ( V_10 -> V_11 , V_45 ) ;
return V_45 ;
free:
F_67 ( V_45 ) ;
return F_53 ( V_48 ) ;
}
static void F_71 ( struct V_9 * V_10 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_19 ( V_10 ) ;
struct V_8 * V_45 ;
unsigned V_3 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_44 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_44 ( V_4 -> V_55 ) != V_10 )
continue;
V_4 -> V_55 = NULL ;
}
V_45 = F_3 ( V_10 ) ;
if ( ! V_45 )
return;
F_68 ( V_45 ) ;
F_60 ( V_10 -> V_11 , NULL ) ;
F_39 ( V_45 , V_138 ) ;
}
static int F_72 ( struct V_139 * V_140 , unsigned long V_76 ,
void * V_141 )
{
struct V_9 * V_10 = F_73 ( V_141 ) ;
struct V_8 * V_45 ;
switch( V_76 ) {
case V_142 :
if ( ( V_10 -> type == V_143 ) ||
( V_10 -> type == V_144 ) ) {
V_45 = F_70 ( V_10 ) ;
if ( F_49 ( V_45 ) )
return F_74 ( F_59 ( V_45 ) ) ;
}
break;
case V_145 :
F_71 ( V_10 ) ;
break;
case V_146 :
V_45 = F_3 ( V_10 ) ;
if ( V_45 ) {
int V_48 ;
F_68 ( V_45 ) ;
V_48 = F_63 ( V_10 , V_45 ) ;
if ( V_48 )
return F_74 ( V_48 ) ;
}
break;
}
return V_147 ;
}
static int F_75 ( struct V_17 * V_18 ,
T_3 V_129 , const void * V_83 , int V_65 )
{
static const int V_148 [ V_149 + 1 ] = {
V_150 , V_151 , V_152 , V_153 ,
} ;
struct V_154 * V_155 ;
struct V_156 * V_157 ;
int V_158 = V_159 ;
V_155 = F_76 ( V_18 , V_160 , V_65 + 2 ) ;
if ( ! V_155 )
return - V_161 ;
if ( V_129 <= V_149 )
V_158 = V_148 [ V_129 ] ;
V_157 = F_77 ( V_155 ) ;
V_157 -> V_162 = V_158 ;
memcpy ( V_157 -> V_163 , V_83 , V_65 ) ;
return 0 ;
}
int F_78 ( struct V_17 * V_18 , int V_164 ,
T_3 V_165 , const T_4 V_54 [] )
{
struct V_154 * V_155 ;
struct V_15 * V_166 ;
bool V_58 ;
int V_59 ;
V_155 = F_76 ( V_18 , V_164 , V_165 * 4 ) ;
if ( ! V_155 )
return - V_161 ;
V_166 = F_77 ( V_155 ) ;
V_58 = true ;
for ( V_59 = V_165 - 1 ; V_59 >= 0 ; V_59 -- ) {
V_166 [ V_59 ] = F_32 ( V_54 [ V_59 ] , 0 , 0 , V_58 ) ;
V_58 = false ;
}
return 0 ;
}
int F_79 ( const struct V_154 * V_155 ,
T_4 V_167 , T_4 * V_165 , T_4 V_54 [] )
{
unsigned V_19 = F_80 ( V_155 ) ;
unsigned V_168 ;
struct V_15 * V_166 ;
bool V_58 ;
int V_59 ;
if ( V_19 & 3 )
return - V_107 ;
V_168 = V_19 / 4 ;
if ( V_168 > V_167 )
return - V_107 ;
V_166 = F_77 ( V_155 ) ;
V_58 = true ;
for ( V_59 = V_168 - 1 ; V_59 >= 0 ; V_59 -- , V_58 = false ) {
struct V_20 V_21 ;
V_21 = F_22 ( V_166 + V_59 ) ;
if ( ( V_21 . V_58 != V_58 ) || V_21 . V_34 || V_21 . V_169 )
return - V_107 ;
switch ( V_21 . V_54 ) {
case V_170 :
return - V_107 ;
}
V_54 [ V_59 ] = V_21 . V_54 ;
}
* V_165 = V_168 ;
return 0 ;
}
static int F_81 ( struct V_17 * V_18 , struct V_73 * V_74 ,
struct V_96 * V_97 )
{
struct V_171 * V_172 ;
struct V_154 * V_173 [ V_174 + 1 ] ;
int V_3 ;
int V_48 ;
V_48 = F_82 ( V_74 , sizeof( * V_172 ) , V_173 , V_174 , V_175 ) ;
if ( V_48 < 0 )
goto V_111;
V_48 = - V_107 ;
V_172 = F_83 ( V_74 ) ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
if ( V_172 -> V_176 != V_177 )
goto V_111;
if ( V_172 -> V_178 != 20 )
goto V_111;
if ( V_172 -> V_179 != 0 )
goto V_111;
if ( V_172 -> V_180 != 0 )
goto V_111;
if ( V_172 -> V_181 != V_182 )
goto V_111;
if ( V_172 -> V_183 != V_184 )
goto V_111;
if ( V_172 -> V_185 != V_186 )
goto V_111;
if ( V_172 -> V_187 != 0 )
goto V_111;
V_97 -> V_108 = V_82 ;
V_97 -> V_124 = V_172 -> V_188 ;
V_97 -> V_109 = V_74 -> V_189 ;
V_97 -> V_105 . V_75 = F_84 ( V_18 ) . V_75 ;
V_97 -> V_105 . V_74 = V_74 ;
V_97 -> V_105 . V_106 = F_85 ( V_18 -> V_190 ) ;
for ( V_3 = 0 ; V_3 <= V_174 ; V_3 ++ ) {
struct V_154 * V_155 = V_173 [ V_3 ] ;
if ( ! V_155 )
continue;
switch( V_3 ) {
case V_191 :
V_97 -> V_98 = F_86 ( V_155 ) ;
break;
case V_192 :
if ( F_79 ( V_155 , V_113 ,
& V_97 -> V_112 ,
V_97 -> V_122 ) )
goto V_111;
break;
case V_193 :
{
T_4 V_194 ;
if ( F_79 ( V_155 , 1 , & V_194 ,
& V_97 -> V_108 ) )
goto V_111;
if ( V_97 -> V_108 < V_81 )
goto V_111;
break;
}
case V_160 :
{
struct V_156 * V_157 = F_77 ( V_155 ) ;
if ( F_80 ( V_155 ) < F_87 ( struct V_156 , V_163 ) )
goto V_111;
V_97 -> V_115 = F_80 ( V_155 ) -
F_87 ( struct V_156 , V_163 ) ;
if ( V_97 -> V_115 > V_195 )
goto V_111;
switch( V_157 -> V_162 ) {
case V_153 :
V_97 -> V_99 = V_103 ;
break;
case V_150 :
V_97 -> V_99 = V_100 ;
if ( V_97 -> V_115 != 4 )
goto V_111;
break;
case V_151 :
V_97 -> V_99 = V_102 ;
if ( V_97 -> V_115 != 16 )
goto V_111;
break;
default:
goto V_111;
}
memcpy ( V_97 -> V_101 , V_157 -> V_163 , V_97 -> V_115 ) ;
break;
}
default:
goto V_111;
}
}
V_48 = 0 ;
V_111:
return V_48 ;
}
static int F_88 ( struct V_17 * V_18 , struct V_73 * V_74 )
{
struct V_96 V_97 ;
int V_48 ;
V_48 = F_81 ( V_18 , V_74 , & V_97 ) ;
if ( V_48 < 0 )
return V_48 ;
return F_62 ( & V_97 ) ;
}
static int F_89 ( struct V_17 * V_18 , struct V_73 * V_74 )
{
struct V_96 V_97 ;
int V_48 ;
V_48 = F_81 ( V_18 , V_74 , & V_97 ) ;
if ( V_48 < 0 )
return V_48 ;
return F_58 ( & V_97 ) ;
}
static int F_90 ( struct V_17 * V_18 , T_4 V_75 , T_4 V_196 , int V_76 ,
T_4 V_54 , struct V_1 * V_4 , int V_12 )
{
struct V_9 * V_10 ;
struct V_73 * V_74 ;
struct V_171 * V_172 ;
V_74 = F_91 ( V_18 , V_75 , V_196 , V_76 , sizeof( * V_172 ) , V_12 ) ;
if ( V_74 == NULL )
return - V_161 ;
V_172 = F_83 ( V_74 ) ;
V_172 -> V_176 = V_177 ;
V_172 -> V_178 = 20 ;
V_172 -> V_179 = 0 ;
V_172 -> V_180 = 0 ;
V_172 -> V_181 = V_182 ;
V_172 -> V_188 = V_4 -> V_123 ;
V_172 -> V_183 = V_184 ;
V_172 -> V_185 = V_186 ;
V_172 -> V_187 = 0 ;
if ( V_4 -> V_14 &&
F_78 ( V_18 , V_192 , V_4 -> V_14 , V_4 -> V_60 ) )
goto V_197;
if ( F_75 ( V_18 , V_4 -> V_61 , V_4 -> V_62 , V_4 -> V_67 ) )
goto V_197;
V_10 = F_44 ( V_4 -> V_55 ) ;
if ( V_10 && F_92 ( V_18 , V_191 , V_10 -> V_198 ) )
goto V_197;
if ( F_78 ( V_18 , V_193 , 1 , & V_54 ) )
goto V_197;
F_93 ( V_18 , V_74 ) ;
return 0 ;
V_197:
F_94 ( V_18 , V_74 ) ;
return - V_161 ;
}
static int F_95 ( struct V_17 * V_18 , struct V_199 * V_200 )
{
struct V_2 * V_2 = F_85 ( V_18 -> V_190 ) ;
struct V_1 T_1 * * V_7 ;
T_2 V_6 ;
unsigned int V_3 ;
F_43 () ;
V_3 = V_200 -> args [ 0 ] ;
if ( V_3 < V_81 )
V_3 = V_81 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_44 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_90 ( V_18 , F_84 ( V_200 -> V_18 ) . V_75 ,
V_200 -> V_74 -> V_201 , V_77 ,
V_3 , V_4 , V_202 ) < 0 )
break;
}
V_200 -> args [ 0 ] = V_3 ;
return V_18 -> V_19 ;
}
static inline T_2 F_96 ( struct V_1 * V_4 )
{
T_2 V_203 =
F_97 ( sizeof( struct V_171 ) )
+ F_98 ( 2 + V_4 -> V_67 )
+ F_98 ( 4 ) ;
if ( V_4 -> V_14 )
V_203 += F_98 ( V_4 -> V_14 * 4 ) ;
if ( V_4 -> V_55 )
V_203 += F_98 ( 4 ) ;
return V_203 ;
}
static void F_41 ( int V_76 , T_4 V_54 , struct V_1 * V_4 ,
struct V_73 * V_74 , struct V_2 * V_2 , T_4 V_75 ,
unsigned int V_79 )
{
struct V_17 * V_18 ;
T_4 V_196 = V_74 ? V_74 -> V_201 : 0 ;
int V_48 = - V_136 ;
V_18 = F_99 ( F_96 ( V_4 ) , V_66 ) ;
if ( V_18 == NULL )
goto V_111;
V_48 = F_90 ( V_18 , V_75 , V_196 , V_76 , V_54 , V_4 , V_79 ) ;
if ( V_48 < 0 ) {
F_100 ( V_48 == - V_161 ) ;
F_35 ( V_18 ) ;
goto V_111;
}
F_101 ( V_18 , V_2 , V_75 , V_204 , V_74 , V_66 ) ;
return;
V_111:
if ( V_48 < 0 )
F_102 ( V_2 , V_204 , V_48 ) ;
}
static int F_103 ( struct V_2 * V_2 , T_2 V_205 )
{
T_2 V_206 = sizeof( struct V_1 * ) * V_205 ;
T_2 V_207 ;
T_2 V_208 ;
struct V_1 T_1 * * V_165 = NULL , * * V_69 ;
struct V_1 * V_209 = NULL , * V_210 = NULL ;
unsigned V_3 ;
if ( V_206 ) {
V_165 = F_37 ( V_206 , V_66 | V_211 | V_212 ) ;
if ( ! V_165 )
V_165 = F_104 ( V_206 ) ;
if ( ! V_165 )
goto V_213;
}
if ( V_205 > V_214 ) {
struct V_9 * V_215 = V_2 -> V_216 ;
V_209 = F_36 ( V_215 -> V_114 ) ;
if ( ! V_209 )
goto V_217;
F_60 ( V_209 -> V_55 , V_215 ) ;
V_209 -> V_123 = V_218 ;
V_209 -> V_25 = V_28 ;
V_209 -> V_61 = V_103 ;
memcpy ( V_209 -> V_62 , V_215 -> V_219 , V_215 -> V_114 ) ;
}
if ( V_205 > V_220 ) {
struct V_9 * V_215 = V_2 -> V_216 ;
V_210 = F_36 ( V_215 -> V_114 ) ;
if ( ! V_210 )
goto V_221;
F_60 ( V_210 -> V_55 , V_215 ) ;
V_210 -> V_123 = V_218 ;
V_210 -> V_25 = V_35 ;
V_210 -> V_61 = V_103 ;
memcpy ( V_210 -> V_62 , V_215 -> V_219 , V_215 -> V_114 ) ;
}
F_105 () ;
V_69 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_207 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_205 ; V_3 < V_207 ; V_3 ++ )
F_42 ( V_2 , V_3 , NULL , NULL , NULL ) ;
V_208 = V_206 ;
if ( V_207 < V_205 )
V_208 = V_207 * sizeof( struct V_1 * ) ;
memcpy ( V_165 , V_69 , V_208 ) ;
if ( ( V_207 <= V_220 ) &&
( V_205 > V_220 ) ) {
F_60 ( V_165 [ V_220 ] , V_210 ) ;
V_210 = NULL ;
}
if ( ( V_207 <= V_214 ) &&
( V_205 > V_214 ) ) {
F_60 ( V_165 [ V_214 ] , V_209 ) ;
V_209 = NULL ;
}
V_2 -> V_5 . V_6 = V_205 ;
F_45 ( V_2 -> V_5 . V_7 , V_165 ) ;
F_106 () ;
F_38 ( V_210 ) ;
F_38 ( V_209 ) ;
if ( V_69 ) {
F_107 () ;
F_108 ( V_69 ) ;
}
return 0 ;
V_221:
F_38 ( V_209 ) ;
V_217:
F_108 ( V_165 ) ;
V_213:
return - V_121 ;
}
static int F_109 ( struct V_128 * V_129 , int V_222 ,
void T_5 * V_223 , T_2 * V_224 , T_6 * V_225 )
{
struct V_2 * V_2 = V_129 -> V_132 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_226 ;
struct V_128 V_227 = {
. V_228 = V_129 -> V_228 ,
. V_132 = & V_6 ,
. V_229 = sizeof( int ) ,
. V_230 = V_129 -> V_230 ,
. V_231 = & V_232 ,
. V_233 = & V_234 ,
} ;
V_226 = F_110 ( & V_227 , V_222 , V_223 , V_224 , V_225 ) ;
if ( V_222 && V_226 == 0 )
V_226 = F_103 ( V_2 , V_6 ) ;
return V_226 ;
}
static int F_111 ( struct V_2 * V_2 )
{
struct V_128 * V_129 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_129 = F_64 ( V_235 , sizeof( V_235 ) , V_66 ) ;
if ( V_129 == NULL )
return - V_121 ;
V_129 [ 0 ] . V_132 = V_2 ;
V_2 -> V_5 . V_236 = F_66 ( V_2 , L_4 , V_129 ) ;
if ( V_2 -> V_5 . V_236 == NULL ) {
F_67 ( V_129 ) ;
return - V_121 ;
}
return 0 ;
}
static void F_112 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_2 V_6 ;
struct V_128 * V_129 ;
unsigned int V_3 ;
V_129 = V_2 -> V_5 . V_236 -> V_137 ;
F_69 ( V_2 -> V_5 . V_236 ) ;
F_67 ( V_129 ) ;
F_105 () ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_44 ( V_7 [ V_3 ] ) ;
F_60 ( V_7 [ V_3 ] , NULL ) ;
F_38 ( V_4 ) ;
}
F_106 () ;
F_108 ( V_7 ) ;
}
static int T_7 F_113 ( void )
{
int V_48 ;
F_114 ( sizeof( struct V_15 ) != 4 ) ;
V_48 = F_115 ( & V_237 ) ;
if ( V_48 )
goto V_131;
V_48 = F_116 ( & V_238 ) ;
if ( V_48 )
goto V_239;
F_117 ( & V_240 ) ;
F_118 ( V_241 , V_77 , F_89 , NULL , NULL ) ;
F_118 ( V_241 , V_78 , F_88 , NULL , NULL ) ;
F_118 ( V_241 , V_242 , NULL , F_95 , NULL ) ;
V_48 = 0 ;
V_131:
return V_48 ;
V_239:
F_119 ( & V_237 ) ;
goto V_131;
}
static void T_8 F_120 ( void )
{
F_121 ( V_241 ) ;
F_122 ( & V_240 ) ;
F_123 ( & V_238 ) ;
F_119 ( & V_237 ) ;
}
