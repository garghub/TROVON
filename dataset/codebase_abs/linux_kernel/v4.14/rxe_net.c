struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_1 * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (rxe, &rxe_dev_list, list) {
if ( V_4 -> V_3 == V_3 ) {
V_5 = V_4 ;
break;
}
}
F_4 ( & V_6 ) ;
return V_5 ;
}
struct V_1 * F_5 ( const char * V_7 )
{
struct V_1 * V_4 ;
struct V_1 * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (rxe, &rxe_dev_list, list) {
if ( ! strcmp ( V_7 , V_4 -> V_8 . V_7 ) ) {
V_5 = V_4 ;
break;
}
}
F_4 ( & V_6 ) ;
return V_5 ;
}
struct V_9 * F_6 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
V_3 = V_4 -> V_3 ;
if ( F_7 ( V_3 ) )
V_3 = F_8 ( V_3 ) ;
return V_3 -> V_10 . V_11 ;
}
int F_9 ( struct V_1 * V_4 , union V_12 * V_13 )
{
int V_14 ;
unsigned char V_15 [ V_16 ] ;
F_10 ( (struct V_17 * ) V_13 -> V_18 , V_15 ) ;
V_14 = F_11 ( V_4 -> V_3 , V_15 ) ;
return V_14 ;
}
int F_12 ( struct V_1 * V_4 , union V_12 * V_13 )
{
int V_14 ;
unsigned char V_15 [ V_16 ] ;
F_10 ( (struct V_17 * ) V_13 -> V_18 , V_15 ) ;
V_14 = F_13 ( V_4 -> V_3 , V_15 ) ;
return V_14 ;
}
static struct V_19 * F_14 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
struct V_20 * V_22 )
{
struct V_23 * V_24 ;
struct V_25 V_26 = { { 0 } } ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_27 = V_3 -> V_28 ;
memcpy ( & V_26 . V_21 , V_21 , sizeof( * V_21 ) ) ;
memcpy ( & V_26 . V_22 , V_22 , sizeof( * V_22 ) ) ;
V_26 . V_29 = V_30 ;
V_24 = F_15 ( & V_31 , & V_26 ) ;
if ( F_16 ( V_24 ) ) {
F_17 ( L_1 , & V_22 -> V_32 ) ;
return NULL ;
}
return & V_24 -> V_33 ;
}
static struct V_19 * F_18 ( struct V_2 * V_3 ,
struct V_17 * V_21 ,
struct V_17 * V_22 )
{
struct V_19 * V_34 ;
struct V_35 V_36 = { { 0 } } ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_37 = V_3 -> V_28 ;
memcpy ( & V_36 . V_21 , V_21 , sizeof( * V_21 ) ) ;
memcpy ( & V_36 . V_22 , V_22 , sizeof( * V_22 ) ) ;
V_36 . V_38 = V_30 ;
if ( F_19 ( V_39 -> V_40 ( F_20 ( V_41 . V_42 -> V_43 ) ,
V_41 . V_42 -> V_43 , & V_34 , & V_36 ) ) ) {
F_17 ( L_2 , V_22 ) ;
goto V_44;
}
if ( F_19 ( V_34 -> error ) ) {
F_21 ( L_2 , V_22 ) ;
goto V_44;
}
return V_34 ;
V_44:
F_22 ( V_34 ) ;
return NULL ;
}
static struct V_19 * F_18 ( struct V_2 * V_3 ,
struct V_17 * V_21 ,
struct V_17 * V_22 )
{
return NULL ;
}
static struct V_19 * F_23 ( struct V_1 * V_4 ,
struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_19 * V_33 = NULL ;
if ( F_24 ( V_46 ) == V_49 )
V_33 = F_25 ( V_46 -> V_43 -> V_43 ) ;
if ( ! V_33 || ! F_26 ( V_33 , V_46 -> V_50 ) ) {
if ( V_33 )
F_22 ( V_33 ) ;
if ( V_48 -> V_51 == V_52 ) {
struct V_20 * V_21 ;
struct V_20 * V_22 ;
V_21 = & V_48 -> V_53 . V_54 . V_55 ;
V_22 = & V_48 -> V_56 . V_54 . V_55 ;
V_33 = F_14 ( V_4 -> V_3 , V_21 , V_22 ) ;
} else if ( V_48 -> V_51 == V_57 ) {
struct V_17 * V_58 ;
struct V_17 * V_59 ;
V_58 = & V_48 -> V_53 . V_60 . V_61 ;
V_59 = & V_48 -> V_56 . V_60 . V_61 ;
V_33 = F_18 ( V_4 -> V_3 , V_58 , V_59 ) ;
#if F_27 ( V_62 )
if ( V_33 )
V_46 -> V_50 =
F_28 ( (struct V_63 * ) V_33 ) ;
#endif
}
}
return V_33 ;
}
static int F_29 ( struct V_64 * V_43 , struct V_65 * V_66 )
{
struct V_67 * V_68 ;
struct V_2 * V_3 = V_66 -> V_10 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_69 * V_70 = F_30 ( V_66 ) ;
if ( ! V_4 )
goto V_71;
if ( F_31 ( V_66 ) ) {
F_21 ( L_3 ) ;
goto V_71;
}
V_68 = F_32 ( V_66 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 = ( V_74 * ) ( V_68 + 1 ) ;
V_70 -> V_75 = V_76 ;
V_70 -> V_77 = F_33 ( V_68 -> V_78 ) - sizeof( * V_68 ) ;
return F_34 ( V_66 ) ;
V_71:
F_35 ( V_66 ) ;
return 0 ;
}
static struct V_79 * F_36 ( struct V_80 * V_80 , T_1 V_81 ,
bool V_82 )
{
int V_14 ;
struct V_79 * V_64 ;
struct V_83 V_84 = { } ;
struct V_85 V_86 = { } ;
if ( V_82 ) {
V_84 . V_87 = V_88 ;
V_84 . V_89 = 1 ;
} else {
V_84 . V_87 = V_90 ;
}
V_84 . V_91 = V_81 ;
V_14 = F_37 ( V_80 , & V_84 , & V_64 ) ;
if ( V_14 < 0 ) {
F_21 ( L_4 , V_14 ) ;
return F_38 ( V_14 ) ;
}
V_86 . V_92 = 1 ;
V_86 . V_93 = F_29 ;
F_39 ( V_80 , V_64 , & V_86 ) ;
return V_64 ;
}
void F_40 ( struct V_79 * V_43 )
{
if ( V_43 )
F_41 ( V_43 ) ;
}
static void F_42 ( struct V_65 * V_66 , T_1 V_94 ,
T_1 V_95 )
{
struct V_67 * V_68 ;
F_43 ( V_66 , sizeof( * V_68 ) ) ;
F_44 ( V_66 ) ;
V_68 = F_32 ( V_66 ) ;
V_68 -> V_96 = V_95 ;
V_68 -> V_97 = V_94 ;
V_68 -> V_78 = F_45 ( V_66 -> V_78 ) ;
V_68 -> V_98 = 0 ;
}
static void F_46 ( struct V_19 * V_33 , struct V_65 * V_66 ,
T_2 V_21 , T_2 V_22 , T_3 V_99 ,
T_3 V_100 , T_3 V_101 , T_1 V_102 , bool V_103 )
{
struct V_104 * V_105 ;
F_47 ( V_66 , V_103 ) ;
F_48 ( V_66 ) ;
F_49 ( V_66 , F_50 ( V_33 ) ) ;
memset ( F_51 ( V_66 ) , 0 , sizeof( * F_51 ( V_66 ) ) ) ;
F_52 ( V_66 , sizeof( struct V_104 ) ) ;
F_53 ( V_66 ) ;
V_105 = F_54 ( V_66 ) ;
V_105 -> V_106 = V_107 ;
V_105 -> V_108 = sizeof( struct V_104 ) >> 2 ;
V_105 -> V_109 = V_102 ;
V_105 -> V_110 = V_99 ;
V_105 -> V_100 = V_100 ;
V_105 -> V_22 = V_22 ;
V_105 -> V_21 = V_21 ;
V_105 -> V_101 = V_101 ;
F_55 ( F_56 ( V_33 -> V_10 ) , V_105 ,
F_57 ( V_66 ) -> V_111 ? : 1 ) ;
V_105 -> V_112 = F_45 ( V_66 -> V_78 ) ;
F_58 ( V_105 ) ;
}
static void F_59 ( struct V_19 * V_33 , struct V_65 * V_66 ,
struct V_17 * V_21 , struct V_17 * V_22 ,
T_3 V_99 , T_3 V_113 , T_3 V_101 )
{
struct V_114 * V_115 ;
memset ( & ( F_51 ( V_66 ) -> V_116 ) , 0 , sizeof( F_51 ( V_66 ) -> V_116 ) ) ;
F_51 ( V_66 ) -> V_117 &= ~ ( V_118 | V_119
| V_120 ) ;
F_49 ( V_66 , F_50 ( V_33 ) ) ;
F_43 ( V_66 , sizeof( * V_115 ) ) ;
F_53 ( V_66 ) ;
V_115 = F_60 ( V_66 ) ;
F_61 ( V_115 , V_113 , F_62 ( 0 ) ) ;
V_115 -> V_121 = F_45 ( V_66 -> V_78 ) ;
V_115 -> V_122 = V_99 ;
V_115 -> V_123 = V_101 ;
V_115 -> V_22 = * V_22 ;
V_115 -> V_21 = * V_21 ;
V_115 -> V_121 = F_45 ( V_66 -> V_78 - sizeof( * V_115 ) ) ;
}
static int F_63 ( struct V_1 * V_4 , struct V_69 * V_70 ,
struct V_65 * V_66 , struct V_47 * V_48 )
{
struct V_45 * V_46 = V_70 -> V_46 ;
struct V_19 * V_33 ;
bool V_103 = false ;
T_1 V_102 = F_45 ( V_124 ) ;
struct V_20 * V_21 = & V_48 -> V_53 . V_54 . V_55 ;
struct V_20 * V_22 = & V_48 -> V_56 . V_54 . V_55 ;
V_33 = F_23 ( V_4 , V_46 , V_48 ) ;
if ( ! V_33 ) {
F_21 ( L_5 ) ;
return - V_125 ;
}
if ( ! memcmp ( V_21 , V_22 , sizeof( * V_22 ) ) )
V_70 -> V_75 |= V_126 ;
F_42 ( V_66 , F_45 ( V_127 ) ,
F_45 ( V_128 ) ) ;
F_46 ( V_33 , V_66 , V_21 -> V_32 , V_22 -> V_32 , V_30 ,
V_48 -> V_129 . V_130 , V_48 -> V_129 . V_123 , V_102 , V_103 ) ;
if ( F_24 ( V_46 ) == V_49 )
F_64 ( V_46 -> V_43 -> V_43 , V_33 ) ;
else
F_22 ( V_33 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_4 , struct V_69 * V_70 ,
struct V_65 * V_66 , struct V_47 * V_48 )
{
struct V_45 * V_46 = V_70 -> V_46 ;
struct V_19 * V_33 ;
struct V_17 * V_21 = & V_48 -> V_53 . V_60 . V_61 ;
struct V_17 * V_22 = & V_48 -> V_56 . V_60 . V_61 ;
V_33 = F_23 ( V_4 , V_46 , V_48 ) ;
if ( ! V_33 ) {
F_21 ( L_5 ) ;
return - V_125 ;
}
if ( ! memcmp ( V_21 , V_22 , sizeof( * V_22 ) ) )
V_70 -> V_75 |= V_126 ;
F_42 ( V_66 , F_45 ( V_127 ) ,
F_45 ( V_128 ) ) ;
F_59 ( V_33 , V_66 , V_21 , V_22 , V_30 ,
V_48 -> V_129 . V_130 ,
V_48 -> V_129 . V_123 ) ;
if ( F_24 ( V_46 ) == V_49 )
F_64 ( V_46 -> V_43 -> V_43 , V_33 ) ;
else
F_22 ( V_33 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_4 , struct V_69 * V_70 ,
struct V_65 * V_66 , T_4 * V_131 )
{
int V_14 = 0 ;
struct V_47 * V_48 = F_67 ( V_70 ) ;
if ( V_48 -> V_51 == V_52 )
V_14 = F_63 ( V_4 , V_70 , V_66 , V_48 ) ;
else if ( V_48 -> V_51 == V_57 )
V_14 = F_65 ( V_4 , V_70 , V_66 , V_48 ) ;
* V_131 = F_68 ( V_70 , V_66 ) ;
return V_14 ;
}
static void F_69 ( struct V_65 * V_66 )
{
struct V_64 * V_43 = V_66 -> V_43 ;
struct V_45 * V_46 = V_43 -> V_132 ;
int V_133 = F_70 ( & V_46 -> V_133 ) ;
if ( F_19 ( V_46 -> V_134 &&
V_133 < V_135 ) )
F_71 ( & V_46 -> V_136 . V_137 , 1 ) ;
F_72 ( V_46 ) ;
}
int F_73 ( struct V_1 * V_4 , struct V_69 * V_70 , struct V_65 * V_66 )
{
struct V_65 * V_138 ;
struct V_47 * V_48 ;
int V_14 ;
V_48 = F_67 ( V_70 ) ;
V_138 = F_74 ( V_66 , V_139 ) ;
if ( ! V_138 )
return - V_140 ;
V_138 -> V_141 = F_69 ;
V_138 -> V_43 = V_70 -> V_46 -> V_43 -> V_43 ;
F_75 ( V_70 -> V_46 ) ;
F_76 ( & V_70 -> V_46 -> V_133 ) ;
if ( V_48 -> V_51 == V_52 ) {
V_14 = F_77 ( F_56 ( F_78 ( V_66 ) -> V_10 ) , V_138 -> V_43 , V_138 ) ;
} else if ( V_48 -> V_51 == V_57 ) {
V_14 = F_79 ( F_56 ( F_78 ( V_66 ) -> V_10 ) , V_138 -> V_43 , V_138 ) ;
} else {
F_21 ( L_6 , V_48 -> V_51 ) ;
F_80 ( & V_70 -> V_46 -> V_133 ) ;
F_72 ( V_70 -> V_46 ) ;
F_35 ( V_138 ) ;
return - V_142 ;
}
if ( F_19 ( F_81 ( V_14 ) ) ) {
F_82 ( L_7 , V_14 ) ;
return - V_143 ;
}
F_35 ( V_66 ) ;
return 0 ;
}
int F_83 ( struct V_65 * V_66 )
{
return F_34 ( V_66 ) ;
}
static inline int F_84 ( struct V_1 * V_4 , struct V_47 * V_48 )
{
return V_4 -> V_81 . V_144 == V_48 -> V_129 . V_145 . V_146 . V_147 ;
}
struct V_65 * F_85 ( struct V_1 * V_4 , struct V_47 * V_48 ,
int V_77 , struct V_69 * V_70 )
{
unsigned int V_148 ;
struct V_65 * V_66 ;
if ( V_48 -> V_51 == V_52 )
V_148 = V_149 + sizeof( struct V_67 ) +
sizeof( struct V_104 ) ;
else
V_148 = V_149 + sizeof( struct V_67 ) +
sizeof( struct V_114 ) ;
V_66 = F_86 ( V_77 + V_148 + F_87 ( V_4 -> V_3 ) ,
V_139 ) ;
if ( F_19 ( ! V_66 ) )
return NULL ;
F_88 ( V_66 , V_148 + F_87 ( V_4 -> V_3 ) ) ;
V_66 -> V_10 = V_4 -> V_3 ;
if ( V_48 -> V_51 == V_52 )
V_66 -> V_110 = F_45 ( V_150 ) ;
else
V_66 -> V_110 = F_45 ( V_151 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 = F_89 ( V_66 , V_77 ) ;
V_70 -> V_75 |= V_76 ;
memset ( V_70 -> V_73 , 0 , V_77 ) ;
return V_66 ;
}
const char * F_90 ( struct V_1 * V_4 , unsigned int V_72 )
{
return V_4 -> V_3 -> V_7 ;
}
enum V_152 F_91 ( struct V_1 * V_4 , unsigned int V_72 )
{
return V_153 ;
}
struct V_1 * F_92 ( struct V_2 * V_3 )
{
int V_14 ;
struct V_1 * V_4 = NULL ;
V_4 = (struct V_1 * ) F_93 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
V_14 = F_94 ( V_4 , V_3 -> V_154 ) ;
if ( V_14 ) {
F_95 ( & V_4 -> V_8 ) ;
return NULL ;
}
F_2 ( & V_6 ) ;
F_96 ( & V_4 -> V_155 , & V_156 ) ;
F_4 ( & V_6 ) ;
return V_4 ;
}
void F_97 ( void )
{
F_2 ( & V_6 ) ;
while ( ! F_98 ( & V_156 ) ) {
struct V_1 * V_4 =
F_99 ( & V_156 , struct V_1 , V_155 ) ;
F_100 ( & V_4 -> V_155 ) ;
F_4 ( & V_6 ) ;
F_101 ( V_4 ) ;
F_2 ( & V_6 ) ;
}
F_4 ( & V_6 ) ;
}
static void F_102 ( struct V_1 * V_4 ,
enum V_157 V_158 )
{
struct V_159 V_160 ;
V_160 . V_9 = & V_4 -> V_8 ;
V_160 . V_161 . V_72 = 1 ;
V_160 . V_158 = V_158 ;
F_103 ( & V_160 ) ;
}
void F_104 ( struct V_1 * V_4 )
{
struct V_162 * V_81 ;
V_81 = & V_4 -> V_81 ;
V_81 -> V_163 . V_164 = V_165 ;
V_81 -> V_163 . V_166 = V_167 ;
F_102 ( V_4 , V_168 ) ;
F_105 ( L_8 , V_4 -> V_8 . V_7 ) ;
}
void F_106 ( struct V_1 * V_4 )
{
struct V_162 * V_81 ;
V_81 = & V_4 -> V_81 ;
V_81 -> V_163 . V_164 = V_169 ;
V_81 -> V_163 . V_166 = V_170 ;
F_102 ( V_4 , V_171 ) ;
F_105 ( L_9 , V_4 -> V_8 . V_7 ) ;
}
static int F_107 ( struct V_172 * V_173 ,
unsigned long V_158 ,
void * V_174 )
{
struct V_2 * V_3 = F_108 ( V_174 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
goto V_175;
switch ( V_158 ) {
case V_176 :
F_100 ( & V_4 -> V_155 ) ;
F_101 ( V_4 ) ;
break;
case V_177 :
F_104 ( V_4 ) ;
break;
case V_178 :
F_106 ( V_4 ) ;
break;
case V_179 :
F_105 ( L_10 , V_3 -> V_7 , V_3 -> V_154 ) ;
F_109 ( V_4 , V_3 -> V_154 ) ;
break;
case V_180 :
if ( F_110 ( V_3 ) && F_111 ( V_3 ) )
F_104 ( V_4 ) ;
else
F_106 ( V_4 ) ;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
default:
F_105 ( L_11 ,
V_158 , V_3 -> V_7 ) ;
break;
}
V_175:
return V_186 ;
}
static int F_112 ( void )
{
V_41 . V_187 = F_36 ( & V_31 ,
F_45 ( V_128 ) , false ) ;
if ( F_16 ( V_41 . V_187 ) ) {
V_41 . V_187 = NULL ;
F_21 ( L_12 ) ;
return - 1 ;
}
return 0 ;
}
static int F_113 ( void )
{
#if F_27 ( V_62 )
V_41 . V_42 = F_36 ( & V_31 ,
F_45 ( V_128 ) , true ) ;
if ( F_16 ( V_41 . V_42 ) ) {
V_41 . V_42 = NULL ;
F_21 ( L_13 ) ;
return - 1 ;
}
#endif
return 0 ;
}
void F_114 ( void )
{
F_40 ( V_41 . V_42 ) ;
F_40 ( V_41 . V_187 ) ;
F_115 ( & V_188 ) ;
}
int F_116 ( void )
{
int V_14 ;
V_41 . V_42 = NULL ;
V_14 = F_112 () ;
if ( V_14 )
return V_14 ;
V_14 = F_113 () ;
if ( V_14 )
goto V_189;
V_14 = F_117 ( & V_188 ) ;
if ( V_14 ) {
F_21 ( L_14 ) ;
goto V_189;
}
return 0 ;
V_189:
F_114 () ;
return V_14 ;
}
