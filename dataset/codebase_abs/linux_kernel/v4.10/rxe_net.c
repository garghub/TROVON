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
static T_1 F_6 ( struct V_2 * V_3 )
{
unsigned char * V_9 = V_3 -> V_10 ;
T_1 V_11 ;
unsigned char * V_12 = ( unsigned char * ) & V_11 ;
V_12 [ 0 ] = V_9 [ 0 ] ^ 2 ;
V_12 [ 1 ] = V_9 [ 1 ] ;
V_12 [ 2 ] = V_9 [ 2 ] ;
V_12 [ 3 ] = 0xff ;
V_12 [ 4 ] = 0xfe ;
V_12 [ 5 ] = V_9 [ 3 ] ;
V_12 [ 6 ] = V_9 [ 4 ] ;
V_12 [ 7 ] = V_9 [ 5 ] ;
return V_11 ;
}
static T_1 F_7 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 ) ;
}
static T_1 F_8 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 ) ;
}
static struct V_13 * F_9 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
V_3 = V_4 -> V_3 ;
if ( V_3 -> V_14 & V_15 )
V_3 = F_10 ( V_3 ) ;
return V_3 -> V_16 . V_17 ;
}
static int F_11 ( struct V_1 * V_4 , union V_18 * V_19 )
{
int V_20 ;
unsigned char V_21 [ V_22 ] ;
F_12 ( (struct V_23 * ) V_19 -> V_24 , V_21 ) ;
V_20 = F_13 ( V_4 -> V_3 , V_21 ) ;
return V_20 ;
}
static int F_14 ( struct V_1 * V_4 , union V_18 * V_19 )
{
int V_20 ;
unsigned char V_21 [ V_22 ] ;
F_12 ( (struct V_23 * ) V_19 -> V_24 , V_21 ) ;
V_20 = F_15 ( V_4 -> V_3 , V_21 ) ;
return V_20 ;
}
static struct V_25 * F_16 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_26 * V_28 )
{
struct V_29 * V_30 ;
struct V_31 V_32 = { { 0 } } ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_33 = V_3 -> V_34 ;
memcpy ( & V_32 . V_27 , V_27 , sizeof( * V_27 ) ) ;
memcpy ( & V_32 . V_28 , V_28 , sizeof( * V_28 ) ) ;
V_32 . V_35 = V_36 ;
V_30 = F_17 ( & V_37 , & V_32 ) ;
if ( F_18 ( V_30 ) ) {
F_19 ( L_1 , & V_28 -> V_38 ) ;
return NULL ;
}
return & V_30 -> V_12 ;
}
static struct V_25 * F_20 ( struct V_2 * V_3 ,
struct V_23 * V_27 ,
struct V_23 * V_28 )
{
struct V_25 * V_39 ;
struct V_40 V_41 = { { 0 } } ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_42 = V_3 -> V_34 ;
memcpy ( & V_41 . V_27 , V_27 , sizeof( * V_27 ) ) ;
memcpy ( & V_41 . V_28 , V_28 , sizeof( * V_28 ) ) ;
V_41 . V_43 = V_36 ;
if ( F_21 ( V_44 -> V_45 ( F_22 ( V_46 . V_47 -> V_48 ) ,
V_46 . V_47 -> V_48 , & V_39 , & V_41 ) ) ) {
F_19 ( L_2 , V_28 ) ;
goto V_49;
}
if ( F_21 ( V_39 -> error ) ) {
F_23 ( L_2 , V_28 ) ;
goto V_49;
}
return V_39 ;
V_49:
F_24 ( V_39 ) ;
return NULL ;
}
static struct V_25 * F_20 ( struct V_2 * V_3 ,
struct V_23 * V_27 ,
struct V_23 * V_28 )
{
return NULL ;
}
static int F_25 ( struct V_50 * V_48 , struct V_51 * V_52 )
{
struct V_53 * V_54 ;
struct V_2 * V_3 = V_52 -> V_16 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_55 * V_56 = F_26 ( V_52 ) ;
if ( ! V_4 )
goto V_57;
if ( F_27 ( V_52 ) ) {
F_23 ( L_3 ) ;
goto V_57;
}
V_54 = F_28 ( V_52 ) ;
V_56 -> V_4 = V_4 ;
V_56 -> V_58 = 1 ;
V_56 -> V_59 = ( V_60 * ) ( V_54 + 1 ) ;
V_56 -> V_61 = V_62 ;
V_56 -> V_63 = F_29 ( V_54 -> V_64 ) - sizeof( * V_54 ) ;
return F_30 ( V_52 ) ;
V_57:
F_31 ( V_52 ) ;
return 0 ;
}
static struct V_65 * F_32 ( struct V_66 * V_66 , T_2 V_67 ,
bool V_68 )
{
int V_20 ;
struct V_65 * V_50 ;
struct V_69 V_70 = { 0 } ;
struct V_71 V_72 = { 0 } ;
if ( V_68 ) {
V_70 . V_73 = V_74 ;
V_70 . V_75 = 1 ;
} else {
V_70 . V_73 = V_76 ;
}
V_70 . V_77 = V_67 ;
V_20 = F_33 ( V_66 , & V_70 , & V_50 ) ;
if ( V_20 < 0 ) {
F_23 ( L_4 , V_20 ) ;
return F_34 ( V_20 ) ;
}
V_72 . V_78 = 1 ;
V_72 . V_79 = F_25 ;
F_35 ( V_66 , V_50 , & V_72 ) ;
return V_50 ;
}
void F_36 ( struct V_65 * V_48 )
{
if ( V_48 )
F_37 ( V_48 ) ;
}
static void F_38 ( struct V_51 * V_52 , T_2 V_80 ,
T_2 V_81 )
{
struct V_53 * V_54 ;
F_39 ( V_52 , sizeof( * V_54 ) ) ;
F_40 ( V_52 ) ;
V_54 = F_28 ( V_52 ) ;
V_54 -> V_82 = V_81 ;
V_54 -> V_83 = V_80 ;
V_54 -> V_64 = F_41 ( V_52 -> V_64 ) ;
V_54 -> V_84 = 0 ;
}
static void F_42 ( struct V_25 * V_12 , struct V_51 * V_52 ,
T_3 V_27 , T_3 V_28 , T_4 V_85 ,
T_4 V_86 , T_4 V_87 , T_2 V_88 , bool V_89 )
{
struct V_90 * V_91 ;
F_43 ( V_52 , V_89 ) ;
F_44 ( V_52 ) ;
F_45 ( V_52 , V_12 ) ;
memset ( F_46 ( V_52 ) , 0 , sizeof( * F_46 ( V_52 ) ) ) ;
F_47 ( V_52 , sizeof( struct V_90 ) ) ;
F_48 ( V_52 ) ;
V_91 = F_49 ( V_52 ) ;
V_91 -> V_92 = V_93 ;
V_91 -> V_94 = sizeof( struct V_90 ) >> 2 ;
V_91 -> V_95 = V_88 ;
V_91 -> V_96 = V_85 ;
V_91 -> V_86 = V_86 ;
V_91 -> V_28 = V_28 ;
V_91 -> V_27 = V_27 ;
V_91 -> V_87 = V_87 ;
F_50 ( F_51 ( V_12 -> V_16 ) , V_91 ,
F_52 ( V_52 ) -> V_97 ? : 1 ) ;
V_91 -> V_98 = F_41 ( V_52 -> V_64 ) ;
F_53 ( V_91 ) ;
}
static void F_54 ( struct V_25 * V_12 , struct V_51 * V_52 ,
struct V_23 * V_27 , struct V_23 * V_28 ,
T_4 V_85 , T_4 V_99 , T_4 V_87 )
{
struct V_100 * V_101 ;
memset ( & ( F_46 ( V_52 ) -> V_102 ) , 0 , sizeof( F_46 ( V_52 ) -> V_102 ) ) ;
F_46 ( V_52 ) -> V_103 &= ~ ( V_104 | V_105
| V_106 ) ;
F_45 ( V_52 , V_12 ) ;
F_39 ( V_52 , sizeof( * V_101 ) ) ;
F_48 ( V_52 ) ;
V_101 = F_55 ( V_52 ) ;
F_56 ( V_101 , V_99 , F_57 ( 0 ) ) ;
V_101 -> V_107 = F_41 ( V_52 -> V_64 ) ;
V_101 -> V_108 = V_85 ;
V_101 -> V_109 = V_87 ;
V_101 -> V_28 = * V_28 ;
V_101 -> V_27 = * V_27 ;
V_101 -> V_107 = F_41 ( V_52 -> V_64 - sizeof( * V_101 ) ) ;
}
static int F_58 ( struct V_1 * V_4 , struct V_55 * V_56 ,
struct V_51 * V_52 , struct V_110 * V_111 )
{
struct V_25 * V_12 ;
bool V_89 = false ;
T_2 V_88 = F_41 ( V_112 ) ;
struct V_26 * V_27 = & V_111 -> V_113 . V_114 . V_115 ;
struct V_26 * V_28 = & V_111 -> V_116 . V_114 . V_115 ;
V_12 = F_16 ( V_4 -> V_3 , V_27 , V_28 ) ;
if ( ! V_12 ) {
F_23 ( L_5 ) ;
return - V_117 ;
}
if ( ! memcmp ( V_27 , V_28 , sizeof( * V_28 ) ) )
V_56 -> V_61 |= V_118 ;
F_38 ( V_52 , F_41 ( V_119 ) ,
F_41 ( V_120 ) ) ;
F_42 ( V_12 , V_52 , V_27 -> V_38 , V_28 -> V_38 , V_36 ,
V_111 -> V_121 . V_122 , V_111 -> V_121 . V_109 , V_88 , V_89 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_4 , struct V_55 * V_56 ,
struct V_51 * V_52 , struct V_110 * V_111 )
{
struct V_25 * V_12 ;
struct V_23 * V_27 = & V_111 -> V_113 . V_123 . V_124 ;
struct V_23 * V_28 = & V_111 -> V_116 . V_123 . V_124 ;
V_12 = F_20 ( V_4 -> V_3 , V_27 , V_28 ) ;
if ( ! V_12 ) {
F_23 ( L_5 ) ;
return - V_117 ;
}
if ( ! memcmp ( V_27 , V_28 , sizeof( * V_28 ) ) )
V_56 -> V_61 |= V_118 ;
F_38 ( V_52 , F_41 ( V_119 ) ,
F_41 ( V_120 ) ) ;
F_54 ( V_12 , V_52 , V_27 , V_28 , V_36 ,
V_111 -> V_121 . V_122 ,
V_111 -> V_121 . V_109 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_4 , struct V_55 * V_56 ,
struct V_51 * V_52 , T_5 * V_125 )
{
int V_20 = 0 ;
struct V_110 * V_111 = F_61 ( V_56 ) ;
if ( V_111 -> V_126 == V_127 )
V_20 = F_58 ( V_4 , V_56 , V_52 , V_111 ) ;
else if ( V_111 -> V_126 == V_128 )
V_20 = F_59 ( V_4 , V_56 , V_52 , V_111 ) ;
* V_125 = F_62 ( V_56 , V_52 ) ;
return V_20 ;
}
static void F_63 ( struct V_51 * V_52 )
{
struct V_50 * V_48 = V_52 -> V_48 ;
struct V_129 * V_130 = V_48 -> V_131 ;
int V_132 = F_64 ( & V_130 -> V_132 ) ;
if ( F_21 ( V_130 -> V_133 &&
V_132 < V_134 ) )
F_65 ( & V_130 -> V_135 . V_136 , 1 ) ;
}
static int F_66 ( struct V_1 * V_4 , struct V_55 * V_56 ,
struct V_51 * V_52 )
{
struct V_51 * V_137 ;
struct V_110 * V_111 ;
int V_20 ;
V_111 = F_61 ( V_56 ) ;
V_137 = F_67 ( V_52 , V_138 ) ;
if ( ! V_137 )
return - V_139 ;
V_137 -> V_140 = F_63 ;
V_137 -> V_48 = V_56 -> V_130 -> V_48 -> V_48 ;
if ( V_111 -> V_126 == V_127 ) {
V_20 = F_68 ( F_51 ( F_69 ( V_52 ) -> V_16 ) , V_137 -> V_48 , V_137 ) ;
} else if ( V_111 -> V_126 == V_128 ) {
V_20 = F_70 ( F_51 ( F_69 ( V_52 ) -> V_16 ) , V_137 -> V_48 , V_137 ) ;
} else {
F_23 ( L_6 , V_111 -> V_126 ) ;
F_31 ( V_137 ) ;
return - V_141 ;
}
if ( F_21 ( F_71 ( V_20 ) ) ) {
F_72 ( L_7 , V_20 ) ;
return - V_142 ;
}
F_73 ( & V_56 -> V_130 -> V_132 ) ;
F_31 ( V_52 ) ;
return 0 ;
}
static int F_74 ( struct V_51 * V_52 )
{
return F_30 ( V_52 ) ;
}
static inline int F_75 ( struct V_1 * V_4 , struct V_110 * V_111 )
{
return V_4 -> V_67 . F_8 == V_111 -> V_121 . V_143 . V_144 . V_145 ;
}
static struct V_51 * F_76 ( struct V_1 * V_4 , struct V_110 * V_111 ,
int V_63 , struct V_55 * V_56 )
{
unsigned int V_146 ;
struct V_51 * V_52 ;
if ( V_111 -> V_126 == V_127 )
V_146 = V_147 + sizeof( struct V_53 ) +
sizeof( struct V_90 ) ;
else
V_146 = V_147 + sizeof( struct V_53 ) +
sizeof( struct V_100 ) ;
V_52 = F_77 ( V_63 + V_146 + F_78 ( V_4 -> V_3 ) ,
V_138 ) ;
if ( F_21 ( ! V_52 ) )
return NULL ;
F_79 ( V_52 , V_146 + F_78 ( V_4 -> V_3 ) ) ;
V_52 -> V_16 = V_4 -> V_3 ;
if ( V_111 -> V_126 == V_127 )
V_52 -> V_96 = F_41 ( V_148 ) ;
else
V_52 -> V_96 = F_41 ( V_149 ) ;
V_56 -> V_4 = V_4 ;
V_56 -> V_58 = 1 ;
V_56 -> V_59 = F_80 ( V_52 , V_63 ) ;
V_56 -> V_61 |= V_62 ;
memset ( V_56 -> V_59 , 0 , V_63 ) ;
return V_52 ;
}
static char * F_81 ( struct V_1 * V_4 , unsigned int V_58 )
{
return V_4 -> V_3 -> V_7 ;
}
static enum V_150 F_82 ( struct V_1 * V_4 ,
unsigned int V_58 )
{
return V_151 ;
}
struct V_1 * F_83 ( struct V_2 * V_3 )
{
int V_20 ;
struct V_1 * V_4 = NULL ;
V_4 = (struct V_1 * ) F_84 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_152 = & V_152 ;
V_4 -> V_3 = V_3 ;
V_20 = F_85 ( V_4 , V_3 -> V_153 ) ;
if ( V_20 ) {
F_86 ( & V_4 -> V_8 ) ;
return NULL ;
}
F_2 ( & V_6 ) ;
F_87 ( & V_4 -> V_154 , & V_155 ) ;
F_4 ( & V_6 ) ;
return V_4 ;
}
void F_88 ( void )
{
F_2 ( & V_6 ) ;
while ( ! F_89 ( & V_155 ) ) {
struct V_1 * V_4 =
F_90 ( & V_155 , struct V_1 , V_154 ) ;
F_91 ( & V_4 -> V_154 ) ;
F_4 ( & V_6 ) ;
F_92 ( V_4 ) ;
F_2 ( & V_6 ) ;
}
F_4 ( & V_6 ) ;
}
static void F_93 ( struct V_1 * V_4 ,
enum V_156 V_157 )
{
struct V_158 V_159 ;
V_159 . V_13 = & V_4 -> V_8 ;
V_159 . V_160 . V_58 = 1 ;
V_159 . V_157 = V_157 ;
F_94 ( & V_159 ) ;
}
void F_95 ( struct V_1 * V_4 )
{
struct V_161 * V_67 ;
V_67 = & V_4 -> V_67 ;
V_67 -> V_162 . V_163 = V_164 ;
V_67 -> V_162 . V_165 = V_166 ;
F_93 ( V_4 , V_167 ) ;
F_96 ( L_8 , V_4 -> V_8 . V_7 ) ;
}
void F_97 ( struct V_1 * V_4 )
{
struct V_161 * V_67 ;
V_67 = & V_4 -> V_67 ;
V_67 -> V_162 . V_163 = V_168 ;
V_67 -> V_162 . V_165 = V_169 ;
F_93 ( V_4 , V_170 ) ;
F_96 ( L_9 , V_4 -> V_8 . V_7 ) ;
}
static int F_98 ( struct V_171 * V_172 ,
unsigned long V_157 ,
void * V_173 )
{
struct V_2 * V_3 = F_99 ( V_173 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
goto V_174;
switch ( V_157 ) {
case V_175 :
F_91 ( & V_4 -> V_154 ) ;
F_92 ( V_4 ) ;
break;
case V_176 :
F_95 ( V_4 ) ;
break;
case V_177 :
F_97 ( V_4 ) ;
break;
case V_178 :
F_96 ( L_10 , V_3 -> V_7 , V_3 -> V_153 ) ;
F_100 ( V_4 , V_3 -> V_153 ) ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
default:
F_96 ( L_11 ,
V_157 , V_3 -> V_7 ) ;
break;
}
V_174:
return V_185 ;
}
int F_101 ( void )
{
V_46 . V_186 = F_32 ( & V_37 ,
F_41 ( V_120 ) , false ) ;
if ( F_18 ( V_46 . V_186 ) ) {
V_46 . V_186 = NULL ;
F_23 ( L_12 ) ;
return - 1 ;
}
return 0 ;
}
int F_102 ( void )
{
#if F_103 ( V_187 )
V_46 . V_47 = F_32 ( & V_37 ,
F_41 ( V_120 ) , true ) ;
if ( F_18 ( V_46 . V_47 ) ) {
V_46 . V_47 = NULL ;
F_23 ( L_13 ) ;
return - 1 ;
}
#endif
return 0 ;
}
void F_104 ( void )
{
F_36 ( V_46 . V_47 ) ;
F_36 ( V_46 . V_186 ) ;
F_105 ( & V_188 ) ;
}
int F_106 ( void )
{
int V_20 ;
V_46 . V_47 = NULL ;
V_20 = F_101 () ;
if ( V_20 )
return V_20 ;
V_20 = F_102 () ;
if ( V_20 )
goto V_189;
V_20 = F_107 ( & V_188 ) ;
if ( V_20 ) {
F_23 ( L_14 ) ;
goto V_189;
}
return 0 ;
V_189:
F_104 () ;
return V_20 ;
}
