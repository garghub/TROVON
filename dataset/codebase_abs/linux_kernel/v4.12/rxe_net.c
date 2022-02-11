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
if ( ! V_33 || ! ( V_33 -> V_50 && V_33 -> V_51 -> V_52 ( V_33 , 0 ) ) ) {
if ( V_33 )
F_22 ( V_33 ) ;
if ( V_48 -> V_53 == V_54 ) {
struct V_20 * V_21 ;
struct V_20 * V_22 ;
V_21 = & V_48 -> V_55 . V_56 . V_57 ;
V_22 = & V_48 -> V_58 . V_56 . V_57 ;
V_33 = F_14 ( V_4 -> V_3 , V_21 , V_22 ) ;
} else if ( V_48 -> V_53 == V_59 ) {
struct V_17 * V_60 ;
struct V_17 * V_61 ;
V_60 = & V_48 -> V_55 . V_62 . V_63 ;
V_61 = & V_48 -> V_58 . V_62 . V_63 ;
V_33 = F_18 ( V_4 -> V_3 , V_60 , V_61 ) ;
}
}
return V_33 ;
}
static int F_26 ( struct V_64 * V_43 , struct V_65 * V_66 )
{
struct V_67 * V_68 ;
struct V_2 * V_3 = V_66 -> V_10 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_69 * V_70 = F_27 ( V_66 ) ;
if ( ! V_4 )
goto V_71;
if ( F_28 ( V_66 ) ) {
F_21 ( L_3 ) ;
goto V_71;
}
V_68 = F_29 ( V_66 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 = ( V_74 * ) ( V_68 + 1 ) ;
V_70 -> V_75 = V_76 ;
V_70 -> V_77 = F_30 ( V_68 -> V_78 ) - sizeof( * V_68 ) ;
return F_31 ( V_66 ) ;
V_71:
F_32 ( V_66 ) ;
return 0 ;
}
static struct V_79 * F_33 ( struct V_80 * V_80 , T_1 V_81 ,
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
V_14 = F_34 ( V_80 , & V_84 , & V_64 ) ;
if ( V_14 < 0 ) {
F_21 ( L_4 , V_14 ) ;
return F_35 ( V_14 ) ;
}
V_86 . V_92 = 1 ;
V_86 . V_93 = F_26 ;
F_36 ( V_80 , V_64 , & V_86 ) ;
return V_64 ;
}
void F_37 ( struct V_79 * V_43 )
{
if ( V_43 )
F_38 ( V_43 ) ;
}
static void F_39 ( struct V_65 * V_66 , T_1 V_94 ,
T_1 V_95 )
{
struct V_67 * V_68 ;
F_40 ( V_66 , sizeof( * V_68 ) ) ;
F_41 ( V_66 ) ;
V_68 = F_29 ( V_66 ) ;
V_68 -> V_96 = V_95 ;
V_68 -> V_97 = V_94 ;
V_68 -> V_78 = F_42 ( V_66 -> V_78 ) ;
V_68 -> V_52 = 0 ;
}
static void F_43 ( struct V_19 * V_33 , struct V_65 * V_66 ,
T_2 V_21 , T_2 V_22 , T_3 V_98 ,
T_3 V_99 , T_3 V_100 , T_1 V_101 , bool V_102 )
{
struct V_103 * V_104 ;
F_44 ( V_66 , V_102 ) ;
F_45 ( V_66 ) ;
F_46 ( V_66 , F_47 ( V_33 ) ) ;
memset ( F_48 ( V_66 ) , 0 , sizeof( * F_48 ( V_66 ) ) ) ;
F_49 ( V_66 , sizeof( struct V_103 ) ) ;
F_50 ( V_66 ) ;
V_104 = F_51 ( V_66 ) ;
V_104 -> V_105 = V_106 ;
V_104 -> V_107 = sizeof( struct V_103 ) >> 2 ;
V_104 -> V_108 = V_101 ;
V_104 -> V_109 = V_98 ;
V_104 -> V_99 = V_99 ;
V_104 -> V_22 = V_22 ;
V_104 -> V_21 = V_21 ;
V_104 -> V_100 = V_100 ;
F_52 ( F_53 ( V_33 -> V_10 ) , V_104 ,
F_54 ( V_66 ) -> V_110 ? : 1 ) ;
V_104 -> V_111 = F_42 ( V_66 -> V_78 ) ;
F_55 ( V_104 ) ;
}
static void F_56 ( struct V_19 * V_33 , struct V_65 * V_66 ,
struct V_17 * V_21 , struct V_17 * V_22 ,
T_3 V_98 , T_3 V_112 , T_3 V_100 )
{
struct V_113 * V_114 ;
memset ( & ( F_48 ( V_66 ) -> V_115 ) , 0 , sizeof( F_48 ( V_66 ) -> V_115 ) ) ;
F_48 ( V_66 ) -> V_116 &= ~ ( V_117 | V_118
| V_119 ) ;
F_46 ( V_66 , V_33 ) ;
F_40 ( V_66 , sizeof( * V_114 ) ) ;
F_50 ( V_66 ) ;
V_114 = F_57 ( V_66 ) ;
F_58 ( V_114 , V_112 , F_59 ( 0 ) ) ;
V_114 -> V_120 = F_42 ( V_66 -> V_78 ) ;
V_114 -> V_121 = V_98 ;
V_114 -> V_122 = V_100 ;
V_114 -> V_22 = * V_22 ;
V_114 -> V_21 = * V_21 ;
V_114 -> V_120 = F_42 ( V_66 -> V_78 - sizeof( * V_114 ) ) ;
}
static int F_60 ( struct V_1 * V_4 , struct V_69 * V_70 ,
struct V_65 * V_66 , struct V_47 * V_48 )
{
struct V_45 * V_46 = V_70 -> V_46 ;
struct V_19 * V_33 ;
bool V_102 = false ;
T_1 V_101 = F_42 ( V_123 ) ;
struct V_20 * V_21 = & V_48 -> V_55 . V_56 . V_57 ;
struct V_20 * V_22 = & V_48 -> V_58 . V_56 . V_57 ;
V_33 = F_23 ( V_4 , V_46 , V_48 ) ;
if ( ! V_33 ) {
F_21 ( L_5 ) ;
return - V_124 ;
}
if ( ! memcmp ( V_21 , V_22 , sizeof( * V_22 ) ) )
V_70 -> V_75 |= V_125 ;
F_39 ( V_66 , F_42 ( V_126 ) ,
F_42 ( V_127 ) ) ;
F_43 ( V_33 , V_66 , V_21 -> V_32 , V_22 -> V_32 , V_30 ,
V_48 -> V_128 . V_129 , V_48 -> V_128 . V_122 , V_101 , V_102 ) ;
if ( F_24 ( V_46 ) == V_49 )
F_61 ( V_46 -> V_43 -> V_43 , V_33 ) ;
else
F_22 ( V_33 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_4 , struct V_69 * V_70 ,
struct V_65 * V_66 , struct V_47 * V_48 )
{
struct V_45 * V_46 = V_70 -> V_46 ;
struct V_19 * V_33 = NULL ;
struct V_17 * V_21 = & V_48 -> V_55 . V_62 . V_63 ;
struct V_17 * V_22 = & V_48 -> V_58 . V_62 . V_63 ;
V_33 = F_23 ( V_4 , V_46 , V_48 ) ;
if ( ! V_33 ) {
F_21 ( L_5 ) ;
return - V_124 ;
}
if ( ! memcmp ( V_21 , V_22 , sizeof( * V_22 ) ) )
V_70 -> V_75 |= V_125 ;
F_39 ( V_66 , F_42 ( V_126 ) ,
F_42 ( V_127 ) ) ;
F_56 ( V_33 , V_66 , V_21 , V_22 , V_30 ,
V_48 -> V_128 . V_129 ,
V_48 -> V_128 . V_122 ) ;
if ( F_24 ( V_46 ) == V_49 )
F_61 ( V_46 -> V_43 -> V_43 , V_33 ) ;
else
F_22 ( V_33 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_4 , struct V_69 * V_70 ,
struct V_65 * V_66 , T_4 * V_130 )
{
int V_14 = 0 ;
struct V_47 * V_48 = F_64 ( V_70 ) ;
if ( V_48 -> V_53 == V_54 )
V_14 = F_60 ( V_4 , V_70 , V_66 , V_48 ) ;
else if ( V_48 -> V_53 == V_59 )
V_14 = F_62 ( V_4 , V_70 , V_66 , V_48 ) ;
* V_130 = F_65 ( V_70 , V_66 ) ;
return V_14 ;
}
static void F_66 ( struct V_65 * V_66 )
{
struct V_64 * V_43 = V_66 -> V_43 ;
struct V_45 * V_46 = V_43 -> V_131 ;
int V_132 = F_67 ( & V_46 -> V_132 ) ;
if ( F_19 ( V_46 -> V_133 &&
V_132 < V_134 ) )
F_68 ( & V_46 -> V_135 . V_136 , 1 ) ;
}
int F_69 ( struct V_1 * V_4 , struct V_69 * V_70 , struct V_65 * V_66 )
{
struct V_65 * V_137 ;
struct V_47 * V_48 ;
int V_14 ;
V_48 = F_64 ( V_70 ) ;
V_137 = F_70 ( V_66 , V_138 ) ;
if ( ! V_137 )
return - V_139 ;
V_137 -> V_140 = F_66 ;
V_137 -> V_43 = V_70 -> V_46 -> V_43 -> V_43 ;
if ( V_48 -> V_53 == V_54 ) {
V_14 = F_71 ( F_53 ( F_72 ( V_66 ) -> V_10 ) , V_137 -> V_43 , V_137 ) ;
} else if ( V_48 -> V_53 == V_59 ) {
V_14 = F_73 ( F_53 ( F_72 ( V_66 ) -> V_10 ) , V_137 -> V_43 , V_137 ) ;
} else {
F_21 ( L_6 , V_48 -> V_53 ) ;
F_32 ( V_137 ) ;
return - V_141 ;
}
if ( F_19 ( F_74 ( V_14 ) ) ) {
F_75 ( L_7 , V_14 ) ;
return - V_142 ;
}
F_76 ( & V_70 -> V_46 -> V_132 ) ;
F_32 ( V_66 ) ;
return 0 ;
}
int F_77 ( struct V_65 * V_66 )
{
return F_31 ( V_66 ) ;
}
static inline int F_78 ( struct V_1 * V_4 , struct V_47 * V_48 )
{
return V_4 -> V_81 . V_143 == V_48 -> V_128 . V_144 . V_145 . V_146 ;
}
struct V_65 * F_79 ( struct V_1 * V_4 , struct V_47 * V_48 ,
int V_77 , struct V_69 * V_70 )
{
unsigned int V_147 ;
struct V_65 * V_66 ;
if ( V_48 -> V_53 == V_54 )
V_147 = V_148 + sizeof( struct V_67 ) +
sizeof( struct V_103 ) ;
else
V_147 = V_148 + sizeof( struct V_67 ) +
sizeof( struct V_113 ) ;
V_66 = F_80 ( V_77 + V_147 + F_81 ( V_4 -> V_3 ) ,
V_138 ) ;
if ( F_19 ( ! V_66 ) )
return NULL ;
F_82 ( V_66 , V_147 + F_81 ( V_4 -> V_3 ) ) ;
V_66 -> V_10 = V_4 -> V_3 ;
if ( V_48 -> V_53 == V_54 )
V_66 -> V_109 = F_42 ( V_149 ) ;
else
V_66 -> V_109 = F_42 ( V_150 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 = F_83 ( V_66 , V_77 ) ;
V_70 -> V_75 |= V_76 ;
memset ( V_70 -> V_73 , 0 , V_77 ) ;
return V_66 ;
}
const char * F_84 ( struct V_1 * V_4 , unsigned int V_72 )
{
return V_4 -> V_3 -> V_7 ;
}
enum V_151 F_85 ( struct V_1 * V_4 , unsigned int V_72 )
{
return V_152 ;
}
struct V_1 * F_86 ( struct V_2 * V_3 )
{
int V_14 ;
struct V_1 * V_4 = NULL ;
V_4 = (struct V_1 * ) F_87 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
V_14 = F_88 ( V_4 , V_3 -> V_153 ) ;
if ( V_14 ) {
F_89 ( & V_4 -> V_8 ) ;
return NULL ;
}
F_2 ( & V_6 ) ;
F_90 ( & V_4 -> V_154 , & V_155 ) ;
F_4 ( & V_6 ) ;
return V_4 ;
}
void F_91 ( void )
{
F_2 ( & V_6 ) ;
while ( ! F_92 ( & V_155 ) ) {
struct V_1 * V_4 =
F_93 ( & V_155 , struct V_1 , V_154 ) ;
F_94 ( & V_4 -> V_154 ) ;
F_4 ( & V_6 ) ;
F_95 ( V_4 ) ;
F_2 ( & V_6 ) ;
}
F_4 ( & V_6 ) ;
}
static void F_96 ( struct V_1 * V_4 ,
enum V_156 V_157 )
{
struct V_158 V_159 ;
V_159 . V_9 = & V_4 -> V_8 ;
V_159 . V_160 . V_72 = 1 ;
V_159 . V_157 = V_157 ;
F_97 ( & V_159 ) ;
}
void F_98 ( struct V_1 * V_4 )
{
struct V_161 * V_81 ;
V_81 = & V_4 -> V_81 ;
V_81 -> V_162 . V_163 = V_164 ;
V_81 -> V_162 . V_165 = V_166 ;
F_96 ( V_4 , V_167 ) ;
F_99 ( L_8 , V_4 -> V_8 . V_7 ) ;
}
void F_100 ( struct V_1 * V_4 )
{
struct V_161 * V_81 ;
V_81 = & V_4 -> V_81 ;
V_81 -> V_162 . V_163 = V_168 ;
V_81 -> V_162 . V_165 = V_169 ;
F_96 ( V_4 , V_170 ) ;
F_99 ( L_9 , V_4 -> V_8 . V_7 ) ;
}
static int F_101 ( struct V_171 * V_172 ,
unsigned long V_157 ,
void * V_173 )
{
struct V_2 * V_3 = F_102 ( V_173 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
goto V_174;
switch ( V_157 ) {
case V_175 :
F_94 ( & V_4 -> V_154 ) ;
F_95 ( V_4 ) ;
break;
case V_176 :
F_98 ( V_4 ) ;
break;
case V_177 :
F_100 ( V_4 ) ;
break;
case V_178 :
F_99 ( L_10 , V_3 -> V_7 , V_3 -> V_153 ) ;
F_103 ( V_4 , V_3 -> V_153 ) ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
default:
F_99 ( L_11 ,
V_157 , V_3 -> V_7 ) ;
break;
}
V_174:
return V_185 ;
}
static int F_104 ( void )
{
V_41 . V_186 = F_33 ( & V_31 ,
F_42 ( V_127 ) , false ) ;
if ( F_16 ( V_41 . V_186 ) ) {
V_41 . V_186 = NULL ;
F_21 ( L_12 ) ;
return - 1 ;
}
return 0 ;
}
static int F_105 ( void )
{
#if F_106 ( V_187 )
V_41 . V_42 = F_33 ( & V_31 ,
F_42 ( V_127 ) , true ) ;
if ( F_16 ( V_41 . V_42 ) ) {
V_41 . V_42 = NULL ;
F_21 ( L_13 ) ;
return - 1 ;
}
#endif
return 0 ;
}
void F_107 ( void )
{
F_37 ( V_41 . V_42 ) ;
F_37 ( V_41 . V_186 ) ;
F_108 ( & V_188 ) ;
}
int F_109 ( void )
{
int V_14 ;
V_41 . V_42 = NULL ;
V_14 = F_104 () ;
if ( V_14 )
return V_14 ;
V_14 = F_105 () ;
if ( V_14 )
goto V_189;
V_14 = F_110 ( & V_188 ) ;
if ( V_14 ) {
F_21 ( L_14 ) ;
goto V_189;
}
return 0 ;
V_189:
F_107 () ;
return V_14 ;
}
