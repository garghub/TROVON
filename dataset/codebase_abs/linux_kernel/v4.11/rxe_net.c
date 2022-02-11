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
T_1 F_7 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 ) ;
}
T_1 F_8 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 ) ;
}
struct V_13 * F_9 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
V_3 = V_4 -> V_3 ;
if ( F_10 ( V_3 ) )
V_3 = F_11 ( V_3 ) ;
return V_3 -> V_14 . V_15 ;
}
int F_12 ( struct V_1 * V_4 , union V_16 * V_17 )
{
int V_18 ;
unsigned char V_19 [ V_20 ] ;
F_13 ( (struct V_21 * ) V_17 -> V_22 , V_19 ) ;
V_18 = F_14 ( V_4 -> V_3 , V_19 ) ;
return V_18 ;
}
int F_15 ( struct V_1 * V_4 , union V_16 * V_17 )
{
int V_18 ;
unsigned char V_19 [ V_20 ] ;
F_13 ( (struct V_21 * ) V_17 -> V_22 , V_19 ) ;
V_18 = F_16 ( V_4 -> V_3 , V_19 ) ;
return V_18 ;
}
static struct V_23 * F_17 ( struct V_2 * V_3 ,
struct V_24 * V_25 ,
struct V_24 * V_26 )
{
struct V_27 * V_28 ;
struct V_29 V_30 = { { 0 } } ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_31 = V_3 -> V_32 ;
memcpy ( & V_30 . V_25 , V_25 , sizeof( * V_25 ) ) ;
memcpy ( & V_30 . V_26 , V_26 , sizeof( * V_26 ) ) ;
V_30 . V_33 = V_34 ;
V_28 = F_18 ( & V_35 , & V_30 ) ;
if ( F_19 ( V_28 ) ) {
F_20 ( L_1 , & V_26 -> V_36 ) ;
return NULL ;
}
return & V_28 -> V_12 ;
}
static struct V_23 * F_21 ( struct V_2 * V_3 ,
struct V_21 * V_25 ,
struct V_21 * V_26 )
{
struct V_23 * V_37 ;
struct V_38 V_39 = { { 0 } } ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_40 = V_3 -> V_32 ;
memcpy ( & V_39 . V_25 , V_25 , sizeof( * V_25 ) ) ;
memcpy ( & V_39 . V_26 , V_26 , sizeof( * V_26 ) ) ;
V_39 . V_41 = V_34 ;
if ( F_22 ( V_42 -> V_43 ( F_23 ( V_44 . V_45 -> V_46 ) ,
V_44 . V_45 -> V_46 , & V_37 , & V_39 ) ) ) {
F_20 ( L_2 , V_26 ) ;
goto V_47;
}
if ( F_22 ( V_37 -> error ) ) {
F_24 ( L_2 , V_26 ) ;
goto V_47;
}
return V_37 ;
V_47:
F_25 ( V_37 ) ;
return NULL ;
}
static struct V_23 * F_21 ( struct V_2 * V_3 ,
struct V_21 * V_25 ,
struct V_21 * V_26 )
{
return NULL ;
}
static int F_26 ( struct V_48 * V_46 , struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_2 * V_3 = V_50 -> V_14 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_53 * V_54 = F_27 ( V_50 ) ;
if ( ! V_4 )
goto V_55;
if ( F_28 ( V_50 ) ) {
F_24 ( L_3 ) ;
goto V_55;
}
V_52 = F_29 ( V_50 ) ;
V_54 -> V_4 = V_4 ;
V_54 -> V_56 = 1 ;
V_54 -> V_57 = ( V_58 * ) ( V_52 + 1 ) ;
V_54 -> V_59 = V_60 ;
V_54 -> V_61 = F_30 ( V_52 -> V_62 ) - sizeof( * V_52 ) ;
return F_31 ( V_50 ) ;
V_55:
F_32 ( V_50 ) ;
return 0 ;
}
static struct V_63 * F_33 ( struct V_64 * V_64 , T_2 V_65 ,
bool V_66 )
{
int V_18 ;
struct V_63 * V_48 ;
struct V_67 V_68 = { } ;
struct V_69 V_70 = { } ;
if ( V_66 ) {
V_68 . V_71 = V_72 ;
V_68 . V_73 = 1 ;
} else {
V_68 . V_71 = V_74 ;
}
V_68 . V_75 = V_65 ;
V_18 = F_34 ( V_64 , & V_68 , & V_48 ) ;
if ( V_18 < 0 ) {
F_24 ( L_4 , V_18 ) ;
return F_35 ( V_18 ) ;
}
V_70 . V_76 = 1 ;
V_70 . V_77 = F_26 ;
F_36 ( V_64 , V_48 , & V_70 ) ;
return V_48 ;
}
void F_37 ( struct V_63 * V_46 )
{
if ( V_46 )
F_38 ( V_46 ) ;
}
static void F_39 ( struct V_49 * V_50 , T_2 V_78 ,
T_2 V_79 )
{
struct V_51 * V_52 ;
F_40 ( V_50 , sizeof( * V_52 ) ) ;
F_41 ( V_50 ) ;
V_52 = F_29 ( V_50 ) ;
V_52 -> V_80 = V_79 ;
V_52 -> V_81 = V_78 ;
V_52 -> V_62 = F_42 ( V_50 -> V_62 ) ;
V_52 -> V_82 = 0 ;
}
static void F_43 ( struct V_23 * V_12 , struct V_49 * V_50 ,
T_3 V_25 , T_3 V_26 , T_4 V_83 ,
T_4 V_84 , T_4 V_85 , T_2 V_86 , bool V_87 )
{
struct V_88 * V_89 ;
F_44 ( V_50 , V_87 ) ;
F_45 ( V_50 ) ;
F_46 ( V_50 , V_12 ) ;
memset ( F_47 ( V_50 ) , 0 , sizeof( * F_47 ( V_50 ) ) ) ;
F_48 ( V_50 , sizeof( struct V_88 ) ) ;
F_49 ( V_50 ) ;
V_89 = F_50 ( V_50 ) ;
V_89 -> V_90 = V_91 ;
V_89 -> V_92 = sizeof( struct V_88 ) >> 2 ;
V_89 -> V_93 = V_86 ;
V_89 -> V_94 = V_83 ;
V_89 -> V_84 = V_84 ;
V_89 -> V_26 = V_26 ;
V_89 -> V_25 = V_25 ;
V_89 -> V_85 = V_85 ;
F_51 ( F_52 ( V_12 -> V_14 ) , V_89 ,
F_53 ( V_50 ) -> V_95 ? : 1 ) ;
V_89 -> V_96 = F_42 ( V_50 -> V_62 ) ;
F_54 ( V_89 ) ;
}
static void F_55 ( struct V_23 * V_12 , struct V_49 * V_50 ,
struct V_21 * V_25 , struct V_21 * V_26 ,
T_4 V_83 , T_4 V_97 , T_4 V_85 )
{
struct V_98 * V_99 ;
memset ( & ( F_47 ( V_50 ) -> V_100 ) , 0 , sizeof( F_47 ( V_50 ) -> V_100 ) ) ;
F_47 ( V_50 ) -> V_101 &= ~ ( V_102 | V_103
| V_104 ) ;
F_46 ( V_50 , V_12 ) ;
F_40 ( V_50 , sizeof( * V_99 ) ) ;
F_49 ( V_50 ) ;
V_99 = F_56 ( V_50 ) ;
F_57 ( V_99 , V_97 , F_58 ( 0 ) ) ;
V_99 -> V_105 = F_42 ( V_50 -> V_62 ) ;
V_99 -> V_106 = V_83 ;
V_99 -> V_107 = V_85 ;
V_99 -> V_26 = * V_26 ;
V_99 -> V_25 = * V_25 ;
V_99 -> V_105 = F_42 ( V_50 -> V_62 - sizeof( * V_99 ) ) ;
}
static int F_59 ( struct V_1 * V_4 , struct V_53 * V_54 ,
struct V_49 * V_50 , struct V_108 * V_109 )
{
struct V_23 * V_12 ;
bool V_87 = false ;
T_2 V_86 = F_42 ( V_110 ) ;
struct V_24 * V_25 = & V_109 -> V_111 . V_112 . V_113 ;
struct V_24 * V_26 = & V_109 -> V_114 . V_112 . V_113 ;
V_12 = F_17 ( V_4 -> V_3 , V_25 , V_26 ) ;
if ( ! V_12 ) {
F_24 ( L_5 ) ;
return - V_115 ;
}
if ( ! memcmp ( V_25 , V_26 , sizeof( * V_26 ) ) )
V_54 -> V_59 |= V_116 ;
F_39 ( V_50 , F_42 ( V_117 ) ,
F_42 ( V_118 ) ) ;
F_43 ( V_12 , V_50 , V_25 -> V_36 , V_26 -> V_36 , V_34 ,
V_109 -> V_119 . V_120 , V_109 -> V_119 . V_107 , V_86 , V_87 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_4 , struct V_53 * V_54 ,
struct V_49 * V_50 , struct V_108 * V_109 )
{
struct V_23 * V_12 ;
struct V_21 * V_25 = & V_109 -> V_111 . V_121 . V_122 ;
struct V_21 * V_26 = & V_109 -> V_114 . V_121 . V_122 ;
V_12 = F_21 ( V_4 -> V_3 , V_25 , V_26 ) ;
if ( ! V_12 ) {
F_24 ( L_5 ) ;
return - V_115 ;
}
if ( ! memcmp ( V_25 , V_26 , sizeof( * V_26 ) ) )
V_54 -> V_59 |= V_116 ;
F_39 ( V_50 , F_42 ( V_117 ) ,
F_42 ( V_118 ) ) ;
F_55 ( V_12 , V_50 , V_25 , V_26 , V_34 ,
V_109 -> V_119 . V_120 ,
V_109 -> V_119 . V_107 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_4 , struct V_53 * V_54 ,
struct V_49 * V_50 , T_5 * V_123 )
{
int V_18 = 0 ;
struct V_108 * V_109 = F_62 ( V_54 ) ;
if ( V_109 -> V_124 == V_125 )
V_18 = F_59 ( V_4 , V_54 , V_50 , V_109 ) ;
else if ( V_109 -> V_124 == V_126 )
V_18 = F_60 ( V_4 , V_54 , V_50 , V_109 ) ;
* V_123 = F_63 ( V_54 , V_50 ) ;
return V_18 ;
}
static void F_64 ( struct V_49 * V_50 )
{
struct V_48 * V_46 = V_50 -> V_46 ;
struct V_127 * V_128 = V_46 -> V_129 ;
int V_130 = F_65 ( & V_128 -> V_130 ) ;
if ( F_22 ( V_128 -> V_131 &&
V_130 < V_132 ) )
F_66 ( & V_128 -> V_133 . V_134 , 1 ) ;
}
int F_67 ( struct V_1 * V_4 , struct V_53 * V_54 , struct V_49 * V_50 )
{
struct V_49 * V_135 ;
struct V_108 * V_109 ;
int V_18 ;
V_109 = F_62 ( V_54 ) ;
V_135 = F_68 ( V_50 , V_136 ) ;
if ( ! V_135 )
return - V_137 ;
V_135 -> V_138 = F_64 ;
V_135 -> V_46 = V_54 -> V_128 -> V_46 -> V_46 ;
if ( V_109 -> V_124 == V_125 ) {
V_18 = F_69 ( F_52 ( F_70 ( V_50 ) -> V_14 ) , V_135 -> V_46 , V_135 ) ;
} else if ( V_109 -> V_124 == V_126 ) {
V_18 = F_71 ( F_52 ( F_70 ( V_50 ) -> V_14 ) , V_135 -> V_46 , V_135 ) ;
} else {
F_24 ( L_6 , V_109 -> V_124 ) ;
F_32 ( V_135 ) ;
return - V_139 ;
}
if ( F_22 ( F_72 ( V_18 ) ) ) {
F_73 ( L_7 , V_18 ) ;
return - V_140 ;
}
F_74 ( & V_54 -> V_128 -> V_130 ) ;
F_32 ( V_50 ) ;
return 0 ;
}
int F_75 ( struct V_49 * V_50 )
{
return F_31 ( V_50 ) ;
}
static inline int F_76 ( struct V_1 * V_4 , struct V_108 * V_109 )
{
return V_4 -> V_65 . V_141 == V_109 -> V_119 . V_142 . V_143 . V_144 ;
}
struct V_49 * F_77 ( struct V_1 * V_4 , struct V_108 * V_109 ,
int V_61 , struct V_53 * V_54 )
{
unsigned int V_145 ;
struct V_49 * V_50 ;
if ( V_109 -> V_124 == V_125 )
V_145 = V_146 + sizeof( struct V_51 ) +
sizeof( struct V_88 ) ;
else
V_145 = V_146 + sizeof( struct V_51 ) +
sizeof( struct V_98 ) ;
V_50 = F_78 ( V_61 + V_145 + F_79 ( V_4 -> V_3 ) ,
V_136 ) ;
if ( F_22 ( ! V_50 ) )
return NULL ;
F_80 ( V_50 , V_145 + F_79 ( V_4 -> V_3 ) ) ;
V_50 -> V_14 = V_4 -> V_3 ;
if ( V_109 -> V_124 == V_125 )
V_50 -> V_94 = F_42 ( V_147 ) ;
else
V_50 -> V_94 = F_42 ( V_148 ) ;
V_54 -> V_4 = V_4 ;
V_54 -> V_56 = 1 ;
V_54 -> V_57 = F_81 ( V_50 , V_61 ) ;
V_54 -> V_59 |= V_60 ;
memset ( V_54 -> V_57 , 0 , V_61 ) ;
return V_50 ;
}
const char * F_82 ( struct V_1 * V_4 , unsigned int V_56 )
{
return V_4 -> V_3 -> V_7 ;
}
enum V_149 F_83 ( struct V_1 * V_4 , unsigned int V_56 )
{
return V_150 ;
}
struct V_1 * F_84 ( struct V_2 * V_3 )
{
int V_18 ;
struct V_1 * V_4 = NULL ;
V_4 = (struct V_1 * ) F_85 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
V_18 = F_86 ( V_4 , V_3 -> V_151 ) ;
if ( V_18 ) {
F_87 ( & V_4 -> V_8 ) ;
return NULL ;
}
F_2 ( & V_6 ) ;
F_88 ( & V_4 -> V_152 , & V_153 ) ;
F_4 ( & V_6 ) ;
return V_4 ;
}
void F_89 ( void )
{
F_2 ( & V_6 ) ;
while ( ! F_90 ( & V_153 ) ) {
struct V_1 * V_4 =
F_91 ( & V_153 , struct V_1 , V_152 ) ;
F_92 ( & V_4 -> V_152 ) ;
F_4 ( & V_6 ) ;
F_93 ( V_4 ) ;
F_2 ( & V_6 ) ;
}
F_4 ( & V_6 ) ;
}
static void F_94 ( struct V_1 * V_4 ,
enum V_154 V_155 )
{
struct V_156 V_157 ;
V_157 . V_13 = & V_4 -> V_8 ;
V_157 . V_158 . V_56 = 1 ;
V_157 . V_155 = V_155 ;
F_95 ( & V_157 ) ;
}
void F_96 ( struct V_1 * V_4 )
{
struct V_159 * V_65 ;
V_65 = & V_4 -> V_65 ;
V_65 -> V_160 . V_161 = V_162 ;
V_65 -> V_160 . V_163 = V_164 ;
F_94 ( V_4 , V_165 ) ;
F_97 ( L_8 , V_4 -> V_8 . V_7 ) ;
}
void F_98 ( struct V_1 * V_4 )
{
struct V_159 * V_65 ;
V_65 = & V_4 -> V_65 ;
V_65 -> V_160 . V_161 = V_166 ;
V_65 -> V_160 . V_163 = V_167 ;
F_94 ( V_4 , V_168 ) ;
F_97 ( L_9 , V_4 -> V_8 . V_7 ) ;
}
static int F_99 ( struct V_169 * V_170 ,
unsigned long V_155 ,
void * V_171 )
{
struct V_2 * V_3 = F_100 ( V_171 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
goto V_172;
switch ( V_155 ) {
case V_173 :
F_92 ( & V_4 -> V_152 ) ;
F_93 ( V_4 ) ;
break;
case V_174 :
F_96 ( V_4 ) ;
break;
case V_175 :
F_98 ( V_4 ) ;
break;
case V_176 :
F_97 ( L_10 , V_3 -> V_7 , V_3 -> V_151 ) ;
F_101 ( V_4 , V_3 -> V_151 ) ;
break;
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
default:
F_97 ( L_11 ,
V_155 , V_3 -> V_7 ) ;
break;
}
V_172:
return V_183 ;
}
static int F_102 ( void )
{
V_44 . V_184 = F_33 ( & V_35 ,
F_42 ( V_118 ) , false ) ;
if ( F_19 ( V_44 . V_184 ) ) {
V_44 . V_184 = NULL ;
F_24 ( L_12 ) ;
return - 1 ;
}
return 0 ;
}
static int F_103 ( void )
{
#if F_104 ( V_185 )
V_44 . V_45 = F_33 ( & V_35 ,
F_42 ( V_118 ) , true ) ;
if ( F_19 ( V_44 . V_45 ) ) {
V_44 . V_45 = NULL ;
F_24 ( L_13 ) ;
return - 1 ;
}
#endif
return 0 ;
}
void F_105 ( void )
{
F_37 ( V_44 . V_45 ) ;
F_37 ( V_44 . V_184 ) ;
F_106 ( & V_186 ) ;
}
int F_107 ( void )
{
int V_18 ;
V_44 . V_45 = NULL ;
V_18 = F_102 () ;
if ( V_18 )
return V_18 ;
V_18 = F_103 () ;
if ( V_18 )
goto V_187;
V_18 = F_108 ( & V_186 ) ;
if ( V_18 ) {
F_24 ( L_14 ) ;
goto V_187;
}
return 0 ;
V_187:
F_105 () ;
return V_18 ;
}
