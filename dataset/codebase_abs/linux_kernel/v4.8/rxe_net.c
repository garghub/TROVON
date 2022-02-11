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
struct V_69 V_70 ;
struct V_71 V_72 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
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
V_72 . V_78 = NULL ;
V_72 . V_79 = 1 ;
V_72 . V_80 = F_25 ;
V_72 . V_81 = NULL ;
F_35 ( V_66 , V_50 , & V_72 ) ;
return V_50 ;
}
void F_36 ( struct V_65 * V_48 )
{
if ( V_48 )
F_37 ( V_48 ) ;
}
static void F_38 ( struct V_51 * V_52 , T_2 V_82 ,
T_2 V_83 )
{
struct V_53 * V_54 ;
F_39 ( V_52 , sizeof( * V_54 ) ) ;
F_40 ( V_52 ) ;
V_54 = F_28 ( V_52 ) ;
V_54 -> V_84 = V_83 ;
V_54 -> V_85 = V_82 ;
V_54 -> V_64 = F_41 ( V_52 -> V_64 ) ;
V_54 -> V_86 = 0 ;
}
static void F_42 ( struct V_25 * V_12 , struct V_51 * V_52 ,
T_3 V_27 , T_3 V_28 , T_4 V_87 ,
T_4 V_88 , T_4 V_89 , T_2 V_90 , bool V_91 )
{
struct V_92 * V_93 ;
F_43 ( V_52 , V_91 ) ;
F_44 ( V_52 ) ;
F_45 ( V_52 , V_12 ) ;
memset ( F_46 ( V_52 ) , 0 , sizeof( * F_46 ( V_52 ) ) ) ;
F_47 ( V_52 , sizeof( struct V_92 ) ) ;
F_48 ( V_52 ) ;
V_93 = F_49 ( V_52 ) ;
V_93 -> V_94 = V_95 ;
V_93 -> V_96 = sizeof( struct V_92 ) >> 2 ;
V_93 -> V_97 = V_90 ;
V_93 -> V_98 = V_87 ;
V_93 -> V_88 = V_88 ;
V_93 -> V_28 = V_28 ;
V_93 -> V_27 = V_27 ;
V_93 -> V_89 = V_89 ;
F_50 ( F_51 ( V_12 -> V_16 ) , V_93 ,
F_52 ( V_52 ) -> V_99 ? : 1 ) ;
V_93 -> V_100 = F_41 ( V_52 -> V_64 ) ;
F_53 ( V_93 ) ;
}
static void F_54 ( struct V_25 * V_12 , struct V_51 * V_52 ,
struct V_23 * V_27 , struct V_23 * V_28 ,
T_4 V_87 , T_4 V_101 , T_4 V_89 )
{
struct V_102 * V_103 ;
memset ( & ( F_46 ( V_52 ) -> V_104 ) , 0 , sizeof( F_46 ( V_52 ) -> V_104 ) ) ;
F_46 ( V_52 ) -> V_105 &= ~ ( V_106 | V_107
| V_108 ) ;
F_45 ( V_52 , V_12 ) ;
F_39 ( V_52 , sizeof( * V_103 ) ) ;
F_48 ( V_52 ) ;
V_103 = F_55 ( V_52 ) ;
F_56 ( V_103 , V_101 , F_57 ( 0 ) ) ;
V_103 -> V_109 = F_41 ( V_52 -> V_64 ) ;
V_103 -> V_110 = V_87 ;
V_103 -> V_111 = V_89 ;
V_103 -> V_28 = * V_28 ;
V_103 -> V_27 = * V_27 ;
V_103 -> V_109 = F_41 ( V_52 -> V_64 - sizeof( * V_103 ) ) ;
}
static int F_58 ( struct V_1 * V_4 , struct V_51 * V_52 , struct V_112 * V_113 )
{
struct V_25 * V_12 ;
bool V_91 = false ;
T_2 V_90 = F_41 ( V_114 ) ;
struct V_26 * V_27 = & V_113 -> V_115 . V_116 . V_117 ;
struct V_26 * V_28 = & V_113 -> V_118 . V_116 . V_117 ;
struct V_55 * V_56 = F_26 ( V_52 ) ;
V_12 = F_16 ( V_4 -> V_3 , V_27 , V_28 ) ;
if ( ! V_12 ) {
F_23 ( L_5 ) ;
return - V_119 ;
}
if ( ! memcmp ( V_27 , V_28 , sizeof( * V_28 ) ) )
V_56 -> V_61 |= V_120 ;
F_38 ( V_52 , F_41 ( V_121 ) ,
F_41 ( V_122 ) ) ;
F_42 ( V_12 , V_52 , V_27 -> V_38 , V_28 -> V_38 , V_36 ,
V_113 -> V_123 . V_124 , V_113 -> V_123 . V_111 , V_90 , V_91 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_4 , struct V_51 * V_52 , struct V_112 * V_113 )
{
struct V_25 * V_12 ;
struct V_23 * V_27 = & V_113 -> V_115 . V_125 . V_126 ;
struct V_23 * V_28 = & V_113 -> V_118 . V_125 . V_126 ;
struct V_55 * V_56 = F_26 ( V_52 ) ;
V_12 = F_20 ( V_4 -> V_3 , V_27 , V_28 ) ;
if ( ! V_12 ) {
F_23 ( L_5 ) ;
return - V_119 ;
}
if ( ! memcmp ( V_27 , V_28 , sizeof( * V_28 ) ) )
V_56 -> V_61 |= V_120 ;
F_38 ( V_52 , F_41 ( V_121 ) ,
F_41 ( V_122 ) ) ;
F_54 ( V_12 , V_52 , V_27 , V_28 , V_36 ,
V_113 -> V_123 . V_124 ,
V_113 -> V_123 . V_111 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_4 , struct V_55 * V_56 ,
struct V_51 * V_52 , T_5 * V_127 )
{
int V_20 = 0 ;
struct V_112 * V_113 = F_61 ( V_56 ) ;
if ( V_113 -> V_128 == V_129 )
V_20 = F_58 ( V_4 , V_52 , V_113 ) ;
else if ( V_113 -> V_128 == V_130 )
V_20 = F_59 ( V_4 , V_52 , V_113 ) ;
* V_127 = F_62 ( V_56 , V_52 ) ;
return V_20 ;
}
static void F_63 ( struct V_51 * V_52 )
{
struct V_50 * V_48 = V_52 -> V_48 ;
struct V_131 * V_132 = V_48 -> V_78 ;
int V_133 = F_64 ( & V_132 -> V_133 ) ;
if ( F_21 ( V_132 -> V_134 &&
V_133 < V_135 ) )
F_65 ( & V_132 -> V_136 . V_137 , 1 ) ;
}
static int F_66 ( struct V_1 * V_4 , struct V_55 * V_56 ,
struct V_51 * V_52 )
{
struct V_51 * V_138 ;
struct V_112 * V_113 ;
int V_20 ;
V_113 = F_61 ( V_56 ) ;
V_138 = F_67 ( V_52 , V_139 ) ;
if ( ! V_138 )
return - V_140 ;
V_138 -> V_141 = F_63 ;
V_138 -> V_48 = V_56 -> V_132 -> V_48 -> V_48 ;
if ( V_113 -> V_128 == V_129 ) {
V_20 = F_68 ( F_51 ( F_69 ( V_52 ) -> V_16 ) , V_138 -> V_48 , V_138 ) ;
} else if ( V_113 -> V_128 == V_130 ) {
V_20 = F_70 ( F_51 ( F_69 ( V_52 ) -> V_16 ) , V_138 -> V_48 , V_138 ) ;
} else {
F_23 ( L_6 , V_113 -> V_128 ) ;
F_31 ( V_138 ) ;
return - V_142 ;
}
if ( F_21 ( F_71 ( V_20 ) ) ) {
F_72 ( L_7 , V_20 ) ;
return - V_143 ;
}
F_31 ( V_52 ) ;
return 0 ;
}
static int F_73 ( struct V_51 * V_52 )
{
return F_30 ( V_52 ) ;
}
static inline int F_74 ( struct V_1 * V_4 , struct V_112 * V_113 )
{
return V_4 -> V_67 . F_8 == V_113 -> V_123 . V_144 . V_145 . V_146 ;
}
static struct V_51 * F_75 ( struct V_1 * V_4 , struct V_112 * V_113 ,
int V_63 , struct V_55 * V_56 )
{
unsigned int V_147 ;
struct V_51 * V_52 ;
if ( V_113 -> V_128 == V_129 )
V_147 = V_148 + sizeof( struct V_53 ) +
sizeof( struct V_92 ) ;
else
V_147 = V_148 + sizeof( struct V_53 ) +
sizeof( struct V_102 ) ;
V_52 = F_76 ( V_63 + V_147 + F_77 ( V_4 -> V_3 ) ,
V_139 ) ;
if ( F_21 ( ! V_52 ) )
return NULL ;
F_78 ( V_52 , V_147 + F_77 ( V_4 -> V_3 ) ) ;
V_52 -> V_16 = V_4 -> V_3 ;
if ( V_113 -> V_128 == V_129 )
V_52 -> V_98 = F_41 ( V_149 ) ;
else
V_52 -> V_98 = F_41 ( V_150 ) ;
V_56 -> V_4 = V_4 ;
V_56 -> V_58 = 1 ;
V_56 -> V_59 = F_79 ( V_52 , V_63 ) ;
V_56 -> V_61 |= V_62 ;
memset ( V_56 -> V_59 , 0 , V_63 ) ;
return V_52 ;
}
static char * F_80 ( struct V_1 * V_4 , unsigned int V_58 )
{
return V_4 -> V_3 -> V_7 ;
}
static enum V_151 F_81 ( struct V_1 * V_4 ,
unsigned int V_58 )
{
return V_152 ;
}
struct V_1 * F_82 ( struct V_2 * V_3 )
{
int V_20 ;
struct V_1 * V_4 = NULL ;
V_4 = (struct V_1 * ) F_83 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_153 = & V_153 ;
V_4 -> V_3 = V_3 ;
V_20 = F_84 ( V_4 , V_3 -> V_154 ) ;
if ( V_20 ) {
F_85 ( & V_4 -> V_8 ) ;
return NULL ;
}
F_2 ( & V_6 ) ;
F_86 ( & V_155 , & V_4 -> V_156 ) ;
F_4 ( & V_6 ) ;
return V_4 ;
}
void F_87 ( void )
{
F_2 ( & V_6 ) ;
while ( ! F_88 ( & V_155 ) ) {
struct V_1 * V_4 =
F_89 ( & V_155 , struct V_1 , V_156 ) ;
F_90 ( & V_4 -> V_156 ) ;
F_4 ( & V_6 ) ;
F_91 ( V_4 ) ;
F_2 ( & V_6 ) ;
}
F_4 ( & V_6 ) ;
}
static void F_92 ( struct V_1 * V_4 ,
enum V_157 V_158 )
{
struct V_159 V_160 ;
V_160 . V_13 = & V_4 -> V_8 ;
V_160 . V_161 . V_58 = 1 ;
V_160 . V_158 = V_158 ;
F_93 ( & V_160 ) ;
}
void F_94 ( struct V_1 * V_4 )
{
struct V_162 * V_67 ;
V_67 = & V_4 -> V_67 ;
V_67 -> V_163 . V_164 = V_165 ;
V_67 -> V_163 . V_166 = V_167 ;
F_92 ( V_4 , V_168 ) ;
F_95 ( L_8 , V_4 -> V_8 . V_7 ) ;
return;
}
void F_96 ( struct V_1 * V_4 )
{
struct V_162 * V_67 ;
V_67 = & V_4 -> V_67 ;
V_67 -> V_163 . V_164 = V_169 ;
V_67 -> V_163 . V_166 = V_170 ;
F_92 ( V_4 , V_171 ) ;
F_95 ( L_9 , V_4 -> V_8 . V_7 ) ;
return;
}
static int F_97 ( struct V_172 * V_173 ,
unsigned long V_158 ,
void * V_174 )
{
struct V_2 * V_3 = F_98 ( V_174 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
goto V_175;
switch ( V_158 ) {
case V_176 :
F_90 ( & V_4 -> V_156 ) ;
F_91 ( V_4 ) ;
break;
case V_177 :
F_94 ( V_4 ) ;
break;
case V_178 :
F_96 ( V_4 ) ;
break;
case V_179 :
F_95 ( L_10 , V_3 -> V_7 , V_3 -> V_154 ) ;
F_99 ( V_4 , V_3 -> V_154 ) ;
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
default:
F_95 ( L_11 ,
V_158 , V_3 -> V_7 ) ;
break;
}
V_175:
return V_186 ;
}
int F_100 ( void )
{
F_101 ( & V_6 ) ;
V_46 . V_187 = F_32 ( & V_37 ,
F_41 ( V_122 ) , false ) ;
if ( F_18 ( V_46 . V_187 ) ) {
V_46 . V_187 = NULL ;
F_23 ( L_12 ) ;
return - 1 ;
}
return 0 ;
}
int F_102 ( void )
{
#if F_103 ( V_188 )
F_101 ( & V_6 ) ;
V_46 . V_47 = F_32 ( & V_37 ,
F_41 ( V_122 ) , true ) ;
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
F_36 ( V_46 . V_187 ) ;
F_105 ( & V_189 ) ;
}
