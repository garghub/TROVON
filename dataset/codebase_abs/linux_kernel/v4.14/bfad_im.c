void
F_1 ( void * V_1 , struct V_2 * V_3 ,
enum V_4 V_5 , T_1 V_6 ,
int V_7 , T_1 * V_8 , T_2 V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_3 ;
struct V_12 * V_13 = V_1 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 = V_19 ;
switch ( V_5 ) {
case V_20 :
F_2 ( V_13 , V_6 ) ;
F_3 ( V_11 , 0 ) ;
if ( V_7 > 0 ) {
F_2 ( V_13 , V_7 ) ;
if ( V_7 > V_21 )
V_7 = V_21 ;
memcpy ( V_11 -> V_22 , V_8 , V_7 ) ;
}
if ( V_9 > 0 ) {
F_2 ( V_13 , V_9 ) ;
F_3 ( V_11 , V_9 ) ;
if ( ! V_7 && ( V_6 == V_23 ) &&
( F_4 ( V_11 ) - V_9 ) <
V_11 -> V_24 ) {
F_2 ( V_13 , 0 ) ;
V_18 = V_25 ;
}
}
V_11 -> V_26 = F_5 ( V_18 , V_6 ) ;
break;
case V_27 :
V_18 = V_28 ;
V_11 -> V_26 = F_5 ( V_18 , 0 ) ;
break;
case V_29 :
V_18 = V_30 ;
V_11 -> V_26 = F_5 ( V_18 , 0 ) ;
break;
default:
V_18 = V_25 ;
V_11 -> V_26 = F_5 ( V_18 , 0 ) ;
}
if ( V_11 -> V_31 -> V_32 != NULL )
F_6 ( V_11 ) ;
V_11 -> V_33 = NULL ;
F_2 ( V_13 , V_11 -> V_26 ) ;
V_15 = V_11 -> V_31 -> V_34 ;
if ( V_15 ) {
V_17 = V_15 -> V_17 ;
if ( ! V_11 -> V_26 && V_17 &&
( V_35 > V_11 -> V_31 -> V_36 ) ) {
F_7 ( V_17 , V_11 -> V_31 ) ;
} else if ( V_11 -> V_26 == V_37 && V_17 ) {
F_8 ( V_17 , V_11 -> V_31 ) ;
}
}
V_11 -> V_38 ( V_11 ) ;
}
void
F_9 ( void * V_1 , struct V_2 * V_3 )
{
struct V_10 * V_11 = (struct V_10 * ) V_3 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_11 -> V_26 = F_5 ( V_19 , V_39 ) ;
if ( V_11 -> V_31 -> V_32 != NULL )
F_6 ( V_11 ) ;
V_11 -> V_33 = NULL ;
if ( V_35 > V_11 -> V_31 -> V_36 ) {
V_15 = V_11 -> V_31 -> V_34 ;
if ( V_15 ) {
V_17 = V_15 -> V_17 ;
if ( V_17 )
F_7 ( V_17 , V_11 -> V_31 ) ;
}
}
V_11 -> V_38 ( V_11 ) ;
}
void
F_10 ( void * V_1 , struct V_2 * V_3 )
{
struct V_10 * V_11 = (struct V_10 * ) V_3 ;
struct V_12 * V_13 = V_1 ;
V_11 -> V_26 = F_5 ( V_25 , 0 ) ;
if ( V_11 -> V_31 -> V_32 != NULL )
F_6 ( V_11 ) ;
F_2 ( V_13 , V_11 -> V_26 ) ;
V_11 -> V_33 = NULL ;
}
void
F_11 ( void * V_13 , struct V_40 * V_41 ,
enum V_42 V_43 )
{
struct V_10 * V_11 = (struct V_10 * ) V_41 ;
T_3 * V_44 ;
V_11 -> V_45 . V_46 |= V_43 << 1 ;
F_12 ( V_47 , ( unsigned long * ) & V_11 -> V_45 . V_46 ) ;
V_44 = ( T_3 * ) V_11 -> V_45 . V_48 ;
V_11 -> V_45 . V_48 = NULL ;
if ( V_44 )
F_13 ( V_44 ) ;
}
static const char *
F_14 ( struct V_49 * V_50 )
{
static char V_51 [ 256 ] ;
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
snprintf ( V_51 , sizeof( V_51 ) ,
L_1 ,
V_13 -> V_54 , V_55 ) ;
return V_51 ;
}
static int
F_15 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = V_11 -> V_31 -> V_32 ;
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
T_4 V_59 ;
int V_60 = V_61 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_57 = (struct V_56 * ) V_11 -> V_33 ;
if ( ! V_57 ) {
V_60 = V_63 ;
goto V_64;
}
if ( V_57 -> V_3 != (struct V_2 * ) V_11 ) {
V_60 = V_61 ;
goto V_64;
}
F_2 ( V_13 , V_57 -> V_65 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_2 ,
V_53 -> V_50 -> V_68 , V_11 , V_57 -> V_65 ) ;
( void ) F_18 ( V_57 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_59 = 10 ;
while ( (struct V_56 * ) V_11 -> V_33 == V_57 ) {
F_20 ( V_69 ) ;
F_21 ( V_59 ) ;
if ( V_59 < 4 * V_70 )
V_59 *= 2 ;
}
V_11 -> V_38 ( V_11 ) ;
F_2 ( V_13 , V_57 -> V_65 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_3 ,
V_53 -> V_50 -> V_68 , V_11 , V_57 -> V_65 ) ;
return V_63 ;
V_64:
F_19 ( & V_13 -> V_62 , V_58 ) ;
return V_60 ;
}
static T_5
F_22 ( struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_16 * V_17 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
T_5 V_60 = V_75 ;
struct V_76 V_77 ;
V_72 = F_23 ( & V_13 -> V_78 , (struct V_40 * ) V_11 ) ;
if ( ! V_72 ) {
F_17 ( V_79 , V_13 , V_67 ,
L_4 ) ;
V_60 = V_80 ;
goto V_64;
}
V_11 -> V_33 = NULL ;
V_11 -> V_45 . V_46 = 0 ;
V_74 = F_24 ( & V_17 -> V_81 ) ;
if ( V_74 == NULL ) {
F_25 ( V_72 ) ;
F_17 ( V_79 , V_13 , V_67 ,
L_5 ) ;
V_60 = V_80 ;
goto V_64;
}
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
F_26 ( V_72 , V_74 , V_77 ,
V_82 , V_83 ) ;
V_64:
return V_60 ;
}
static int
F_27 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = V_11 -> V_31 -> V_32 ;
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_14 * V_15 = V_11 -> V_31 -> V_34 ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_71 * V_72 ;
struct V_16 * V_17 ;
struct V_73 * V_74 ;
F_28 ( V_44 ) ;
int V_60 = V_63 ;
unsigned long V_58 ;
enum V_42 V_84 ;
struct V_76 V_77 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_60 = V_61 ;
goto V_64;
}
V_72 = F_23 ( & V_13 -> V_78 , (struct V_40 * ) V_11 ) ;
if ( ! V_72 ) {
F_17 ( V_79 , V_13 , V_67 ,
L_6 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_60 = V_61 ;
goto V_64;
}
V_11 -> V_33 = NULL ;
V_11 -> V_45 . V_48 = ( char * ) & V_44 ;
V_11 -> V_45 . V_46 = 0 ;
V_74 = F_24 ( & V_17 -> V_81 ) ;
if ( V_74 == NULL ) {
F_25 ( V_72 ) ;
F_17 ( V_79 , V_13 , V_67 ,
L_7 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_60 = V_61 ;
goto V_64;
}
F_29 ( V_11 -> V_31 -> V_85 , & V_77 ) ;
F_26 ( V_72 , V_74 , V_77 ,
V_86 , V_87 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_30 ( V_44 , F_31 ( V_47 ,
( unsigned long * ) & V_11 -> V_45 . V_46 ) ) ;
V_84 = V_11 -> V_45 . V_46 >> 1 ;
if ( V_84 != V_88 ) {
F_17 ( V_79 , V_13 , V_67 ,
L_8 , V_84 ) ;
V_60 = V_61 ;
}
V_64:
return V_60 ;
}
static int
F_32 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = V_11 -> V_31 -> V_32 ;
struct V_89 * V_90 = V_89 ( V_11 -> V_31 ) ;
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_16 * V_17 ;
unsigned long V_58 ;
T_4 V_60 , V_91 = V_61 ;
F_28 ( V_44 ) ;
enum V_42 V_84 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_17 = F_33 ( V_53 , V_90 -> V_92 ) ;
if ( V_17 ) {
V_11 -> V_45 . V_48 = ( char * ) & V_44 ;
V_60 = F_22 ( V_13 , V_11 , V_17 ) ;
if ( V_60 == V_75 ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_30 ( V_44 , F_31 ( V_47 ,
( unsigned long * ) & V_11 -> V_45 . V_46 ) ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_84 = V_11 -> V_45 . V_46 >> 1 ;
if ( V_84 != V_88 )
F_17 ( V_79 , V_13 , V_67 ,
L_9
L_10 , V_84 ) ;
else
V_91 = V_63 ;
}
}
F_19 ( & V_13 -> V_62 , V_58 ) ;
return V_91 ;
}
static void
F_34 ( struct V_93 * V_94 )
{
V_94 -> V_34 = NULL ;
return;
}
int
F_35 ( struct V_12 * V_13 , struct V_95 * * V_17 ,
struct V_16 * * V_96 )
{
* V_96 = F_36 ( sizeof( struct V_16 ) , V_97 ) ;
if ( * V_96 == NULL )
return - V_98 ;
( * V_96 ) -> V_99 = V_13 -> V_99 ;
* V_17 = & ( * V_96 ) -> V_81 ;
( * V_96 ) -> V_100 = V_101 ;
F_37 ( & ( * V_96 ) -> V_102 , V_103 ) ;
V_13 -> V_104 |= V_105 ;
return 0 ;
}
void
F_38 ( struct V_12 * V_13 , struct V_16 * V_96 )
{
struct V_106 * V_107 ;
T_6 V_108 ;
T_4 V_109 ;
char V_110 [ 32 ] , V_111 [ 16 ] ;
struct V_112 * V_99 = V_96 -> V_99 ;
F_39 ( V_96 -> V_100 == V_113 ) ;
V_96 -> V_114 = 1 ;
if ( V_96 -> V_100 == V_115 )
V_96 -> V_114 = 0 ;
V_96 -> V_100 = V_116 ;
V_107 = F_40 ( & V_96 -> V_81 ) ;
V_96 -> V_53 = V_107 -> V_53 ;
V_108 = F_41 ( & V_96 -> V_81 ) ;
V_109 = F_42 ( & V_96 -> V_81 ) ;
F_43 ( V_110 , V_108 ) ;
F_44 ( V_111 , V_109 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_11 ,
V_107 -> V_53 -> V_50 -> V_68 ,
V_111 , V_110 ) ;
if ( V_96 -> V_114 )
V_114 ( V_99 -> V_117 , & V_96 -> V_102 ) ;
}
void
F_45 ( struct V_16 * V_96 )
{
struct V_106 * V_107 ;
struct V_112 * V_99 = V_96 -> V_99 ;
V_96 -> V_74 = F_24 ( & V_96 -> V_81 ) ;
V_107 = F_40 ( & V_96 -> V_81 ) ;
V_96 -> V_100 = V_113 ;
V_96 -> V_114 = 1 ;
V_96 -> V_53 = V_107 -> V_53 ;
if ( V_96 -> V_114 )
V_114 ( V_99 -> V_117 , & V_96 -> V_102 ) ;
}
void
F_46 ( struct V_16 * V_96 )
{
struct V_106 * V_107 ;
struct V_12 * V_13 ;
struct V_112 * V_99 = V_96 -> V_99 ;
V_107 = F_40 ( & V_96 -> V_81 ) ;
V_13 = V_107 -> V_13 ;
if ( ( V_13 -> V_118 . V_58 & V_119 ) ||
( V_107 -> V_58 & V_119 ) ) {
V_96 -> V_100 = V_120 ;
return;
}
V_96 -> V_53 = V_107 -> V_53 ;
V_96 -> V_100 = V_115 ;
V_96 -> V_114 = 1 ;
if ( V_96 -> V_114 )
V_114 ( V_99 -> V_117 , & V_96 -> V_102 ) ;
}
int
F_47 ( struct V_12 * V_13 , struct V_52 * V_53 ,
struct V_31 * V_121 )
{
int error = 1 ;
F_48 ( & V_122 ) ;
error = F_49 ( & V_123 , V_53 , 0 , 0 , V_124 ) ;
if ( error < 0 ) {
F_50 ( & V_122 ) ;
F_51 ( V_125 L_12 ) ;
goto V_64;
}
V_53 -> V_126 = error ;
F_50 ( & V_122 ) ;
V_53 -> V_50 = F_52 ( V_53 , V_13 ) ;
if ( ! V_53 -> V_50 ) {
error = 1 ;
goto V_127;
}
V_53 -> V_50 -> V_34 [ 0 ] = ( unsigned long ) V_53 ;
V_53 -> V_50 -> V_128 = V_53 -> V_126 ;
V_53 -> V_50 -> V_129 = - 1 ;
V_53 -> V_50 -> V_130 = V_131 ;
V_53 -> V_50 -> V_132 = V_133 ;
V_53 -> V_50 -> V_134 = 16 ;
V_53 -> V_50 -> V_135 = V_13 -> V_136 . V_137 ;
if ( V_53 -> V_107 -> V_138 == V_139 )
V_53 -> V_50 -> V_140 = V_141 ;
else
V_53 -> V_50 -> V_140 =
V_142 ;
error = F_53 ( V_53 -> V_50 , V_121 , & V_13 -> V_143 -> V_121 ) ;
if ( error ) {
F_51 ( V_125 L_13 , error ) ;
goto V_144;
}
return 0 ;
V_144:
F_54 ( V_53 -> V_50 ) ;
V_53 -> V_50 = NULL ;
V_127:
F_48 ( & V_122 ) ;
F_55 ( & V_123 , V_53 -> V_126 ) ;
F_50 ( & V_122 ) ;
V_64:
return error ;
}
void
F_56 ( struct V_12 * V_13 , struct V_52 * V_53 )
{
F_2 ( V_13 , V_13 -> V_145 ) ;
F_17 ( V_66 , V_13 , V_67 , L_14 ,
V_53 -> V_50 -> V_68 ) ;
F_57 ( V_53 -> V_50 ) ;
F_58 ( V_53 -> V_50 ) ;
F_54 ( V_53 -> V_50 ) ;
F_48 ( & V_122 ) ;
F_55 ( & V_123 , V_53 -> V_126 ) ;
F_50 ( & V_122 ) ;
}
static void
F_59 ( struct V_146 * V_147 )
{
struct V_52 * V_53 =
F_60 ( V_147 , struct V_52 , V_148 ) ;
if ( V_53 -> V_107 -> V_138 != V_139 ) {
V_53 -> V_58 |= V_119 ;
F_61 ( V_53 -> V_149 ) ;
}
}
T_5
F_62 ( struct V_12 * V_13 , struct V_106 * V_107 )
{
int V_60 = V_75 ;
struct V_52 * V_53 ;
V_53 = F_36 ( sizeof( struct V_52 ) , V_97 ) ;
if ( V_53 == NULL ) {
V_60 = V_150 ;
goto V_151;
}
V_107 -> V_53 = V_53 ;
V_53 -> V_107 = V_107 ;
V_53 -> V_13 = V_13 ;
F_37 ( & V_53 -> V_148 , F_59 ) ;
F_63 ( & V_53 -> V_152 ) ;
F_63 ( & V_53 -> V_153 ) ;
V_151:
return V_60 ;
}
void
F_64 ( struct V_12 * V_13 , struct V_106 * V_107 )
{
struct V_52 * V_53 = V_107 -> V_53 ;
V_114 ( V_13 -> V_99 -> V_117 ,
& V_53 -> V_148 ) ;
}
void
F_65 ( struct V_52 * V_53 )
{
struct V_154 * V_155 , * V_156 ;
unsigned long V_58 ;
struct V_12 * V_13 = V_53 -> V_13 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
F_66 (bp, bp_new, &im_port->binding_list,
list_entry) {
F_67 ( & V_155 -> V_157 ) ;
F_68 ( V_155 ) ;
}
F_39 ( ! F_69 ( & V_53 -> V_152 ) ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
}
static void F_70 ( struct V_146 * V_147 )
{
struct V_112 * V_99 =
F_60 ( V_147 , struct V_112 , V_158 ) ;
struct V_159 * V_160 ;
struct V_12 * V_13 = V_99 -> V_13 ;
struct V_49 * V_50 = V_13 -> V_118 . V_53 -> V_50 ;
void * V_161 ;
unsigned long V_58 ;
while ( ! F_69 ( & V_13 -> V_162 ) ) {
F_16 ( & V_13 -> V_163 , V_58 ) ;
F_71 ( & V_13 -> V_162 , & V_160 ) ;
F_19 ( & V_13 -> V_163 , V_58 ) ;
V_161 = ( char * ) V_160 + sizeof( struct V_164 ) ;
F_72 ( V_50 , F_73 () ,
sizeof( struct V_159 ) -
sizeof( struct V_164 ) ,
( char * ) V_161 , V_165 ) ;
F_16 ( & V_13 -> V_163 , V_58 ) ;
F_74 ( & V_160 -> V_166 , & V_13 -> V_167 ) ;
F_19 ( & V_13 -> V_163 , V_58 ) ;
}
}
T_5
F_75 ( struct V_12 * V_13 )
{
struct V_112 * V_99 ;
V_99 = F_36 ( sizeof( struct V_112 ) , V_124 ) ;
if ( V_99 == NULL )
return V_150 ;
V_13 -> V_99 = V_99 ;
V_99 -> V_13 = V_13 ;
if ( F_76 ( V_13 ) != V_75 ) {
F_68 ( V_99 ) ;
return V_80 ;
}
F_37 ( & V_99 -> V_158 , F_70 ) ;
return V_75 ;
}
void
F_77 ( struct V_12 * V_13 )
{
if ( V_13 -> V_99 ) {
F_78 ( V_13 -> V_99 ) ;
F_68 ( V_13 -> V_99 ) ;
V_13 -> V_99 = NULL ;
}
}
struct V_49 *
F_52 ( struct V_52 * V_53 , struct V_12 * V_13 )
{
struct V_168 * V_169 ;
if ( V_53 -> V_107 -> V_138 == V_139 )
V_169 = & V_170 ;
else
V_169 = & V_171 ;
if ( V_172 != V_173 >> 1 )
V_169 -> V_174 = V_172 << 1 ;
V_169 -> V_175 = V_13 -> V_136 . V_176 ;
return F_79 ( V_169 , sizeof( unsigned long ) ) ;
}
void
F_80 ( struct V_12 * V_13 , struct V_52 * V_53 )
{
if ( ! ( V_53 -> V_58 & V_119 ) )
F_81 ( V_13 -> V_99 -> V_117 ) ;
F_56 ( V_53 -> V_13 , V_53 ) ;
F_65 ( V_53 ) ;
F_68 ( V_53 ) ;
}
void
F_78 ( struct V_112 * V_99 )
{
if ( V_99 && V_99 -> V_117 ) {
F_81 ( V_99 -> V_117 ) ;
F_82 ( V_99 -> V_117 ) ;
V_99 -> V_117 = NULL ;
}
}
T_5
F_76 ( struct V_12 * V_13 )
{
struct V_112 * V_99 = V_13 -> V_99 ;
F_2 ( V_13 , 0 ) ;
snprintf ( V_99 -> V_177 , V_178 , L_15 ,
V_13 -> V_145 ) ;
V_99 -> V_117 = F_83 ( V_99 -> V_177 ) ;
if ( ! V_99 -> V_117 )
return V_80 ;
return V_75 ;
}
static int
F_84 ( struct V_93 * V_94 )
{
F_85 ( V_94 , V_35 ) ;
return 0 ;
}
T_5
F_86 ( void )
{
V_141 =
F_87 ( & V_179 ) ;
if ( ! V_141 )
return V_150 ;
V_142 =
F_87 ( & V_180 ) ;
if ( ! V_142 ) {
F_88 ( V_141 ) ;
return V_150 ;
}
return V_75 ;
}
void
F_89 ( void )
{
if ( V_141 )
F_88 ( V_141 ) ;
if ( V_142 )
F_88 ( V_142 ) ;
F_90 ( & V_123 ) ;
}
void
F_7 ( struct V_16 * V_17 , struct V_93 * V_94 )
{
struct V_93 * V_181 ;
if ( ( ( V_182 - V_17 -> V_183 ) >
V_184 * V_70 ) &&
( ( V_182 - V_17 -> V_185 ) >
V_184 * V_70 ) ) {
F_91 (tmp_sdev, sdev->host) {
if ( V_35 > V_181 -> V_36 ) {
if ( V_181 -> V_92 != V_94 -> V_92 )
continue;
F_85 ( V_181 ,
V_181 -> V_36 + 1 ) ;
V_17 -> V_183 = V_182 ;
}
}
}
}
void
F_8 ( struct V_16 * V_17 , struct V_93 * V_94 )
{
struct V_93 * V_181 ;
V_17 -> V_185 = V_182 ;
F_91 (tmp_sdev, sdev->host) {
if ( V_181 -> V_92 != V_94 -> V_92 )
continue;
F_92 ( V_181 , V_181 -> V_36 - 1 ) ;
}
}
struct V_16 *
F_33 ( struct V_52 * V_53 , int V_92 )
{
struct V_16 * V_17 = NULL ;
F_93 (itnim, &im_port->itnim_mapped_list, list_entry) {
if ( V_92 == V_17 -> V_186 )
return V_17 ;
}
return NULL ;
}
static int
F_94 ( struct V_93 * V_94 ,
struct V_187 * V_188 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_188 -> V_189 ;
struct V_190 * V_78 = V_15 -> V_17 -> V_74 -> V_78 ;
struct V_191 * V_192 = V_15 -> V_17 -> V_74 -> V_188 ;
struct V_193 * V_194 = F_95 ( V_78 ) ;
int V_195 = 0 , V_196 = - V_197 ;
for ( V_195 = 0 ; V_195 < V_198 ; V_195 ++ ) {
if ( V_194 [ V_195 ] . V_100 == V_199 &&
F_96 ( & V_194 [ V_195 ] . V_85 ) == V_94 -> V_85 &&
V_194 [ V_195 ] . V_200 == V_192 -> V_201 &&
V_194 [ V_195 ] . V_202 == ( T_1 ) V_192 -> V_203 . V_202 ) {
V_196 = V_75 ;
break;
}
}
return V_196 ;
}
static int
F_97 ( struct V_93 * V_94 )
{
struct V_187 * V_188 = F_98 ( V_89 ( V_94 ) ) ;
struct V_14 * V_15 ;
struct V_190 * V_78 ;
if ( ! V_188 || F_99 ( V_188 ) )
return - V_197 ;
V_15 = (struct V_14 * ) V_188 -> V_189 ;
V_78 = V_15 -> V_17 -> V_74 -> V_78 ;
if ( F_100 ( V_78 ) == V_204 ) {
if ( V_94 -> V_85 == 0 ) {
V_94 -> V_205 |= V_206 |
V_207 ;
goto V_208;
}
if ( F_94 ( V_94 , V_188 ) !=
V_75 )
return - V_197 ;
}
V_208:
V_94 -> V_34 = V_188 -> V_189 ;
return 0 ;
}
T_4
F_101 ( struct V_190 * V_78 )
{
struct V_209 * V_210 ;
T_4 V_211 = 0 ;
V_210 = F_36 ( sizeof( struct V_209 ) , V_124 ) ;
if ( ! V_210 )
return 0 ;
F_102 ( & V_78 -> V_212 , V_210 ) ;
if ( V_210 -> V_213 . V_214 == V_215 )
V_211 |= V_216 | V_217 |
V_218 | V_219 ;
else if ( V_210 -> V_213 . V_214 == V_220 ) {
if ( V_210 -> V_213 . V_221 ) {
V_211 |= V_217 |
V_218 |
V_219 | V_222 ;
} else {
V_211 |= V_217 |
V_218 |
V_219 ;
}
} else if ( V_210 -> V_213 . V_214 == V_223 ) {
V_211 |= V_218 | V_219 |
V_222 ;
} else if ( V_210 -> V_213 . V_214 == V_224 ) {
V_211 |= V_225 ;
}
F_68 ( V_210 ) ;
return V_211 ;
}
void
F_103 ( struct V_52 * V_53 )
{
struct V_49 * V_32 = V_53 -> V_50 ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_106 * V_107 = V_53 -> V_107 ;
char V_226 [ V_227 ] ;
struct V_228 * V_229 = F_104 ( & V_13 -> V_78 ) ;
F_105 ( V_32 ) =
F_106 ( ( F_107 ( V_107 -> V_230 ) ) ) ;
F_108 ( V_32 ) =
F_106 ( ( F_109 ( V_107 -> V_230 ) ) ) ;
F_110 ( V_32 ) = F_111 ( & V_13 -> V_78 ) ;
F_112 ( V_32 ) = V_231 ;
memset ( F_113 ( V_32 ) , 0 ,
sizeof( F_113 ( V_32 ) ) ) ;
if ( V_232 & V_233 )
F_113 ( V_32 ) [ 2 ] = 1 ;
F_113 ( V_32 ) [ 7 ] = 1 ;
F_114 ( V_226 , V_13 -> V_234 . V_235 . V_236 . V_237 . V_238 . V_226 ,
V_227 ) ;
sprintf ( F_115 ( V_32 ) , L_16 , V_226 ) ;
F_116 ( V_32 ) = F_101 ( & V_13 -> V_78 ) ;
F_117 ( V_32 ) = V_229 -> V_239 . V_240 ;
}
static void
F_118 ( struct V_52 * V_53 , struct V_16 * V_17 )
{
struct V_241 V_242 ;
struct V_187 * V_187 ;
struct V_14 * V_15 ;
V_242 . V_243 =
F_106 ( F_119 ( & V_17 -> V_81 ) ) ;
V_242 . V_244 =
F_106 ( F_41 ( & V_17 -> V_81 ) ) ;
V_242 . V_245 =
F_120 ( F_42 ( & V_17 -> V_81 ) ) ;
V_242 . V_246 = V_247 ;
V_17 -> V_187 = V_187 =
F_121 ( V_53 -> V_50 , 0 , & V_242 ) ;
if ( ! V_187 )
return;
V_187 -> V_248 =
F_122 ( & V_17 -> V_81 ) ;
V_187 -> V_249 = F_123 ( & V_17 -> V_81 ) ;
V_15 = V_187 -> V_189 ;
V_15 -> V_17 = V_17 ;
V_242 . V_246 |= V_250 ;
if ( V_242 . V_246 != V_247 )
F_124 ( V_187 , V_242 . V_246 ) ;
if ( ( V_187 -> V_251 != - 1 )
&& ( V_187 -> V_251 < V_131 ) )
V_17 -> V_186 = V_187 -> V_251 ;
V_17 -> V_252 = V_187 -> V_252 ;
return;
}
static void
V_103 ( struct V_146 * V_147 )
{
struct V_16 * V_17 = F_60 ( V_147 , struct V_16 ,
V_102 ) ;
struct V_112 * V_99 = V_17 -> V_99 ;
struct V_12 * V_13 = V_99 -> V_13 ;
struct V_52 * V_53 ;
unsigned long V_58 ;
struct V_187 * V_187 ;
T_6 V_108 ;
T_4 V_109 ;
char V_110 [ 32 ] , V_111 [ 16 ] ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_53 = V_17 -> V_53 ;
F_2 ( V_13 , V_17 -> V_100 ) ;
switch ( V_17 -> V_100 ) {
case V_113 :
if ( ! V_17 -> V_187 ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_118 ( V_53 , V_17 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_108 = F_41 ( & V_17 -> V_81 ) ;
V_109 = F_42 ( & V_17 -> V_81 ) ;
F_43 ( V_110 , V_108 ) ;
F_44 ( V_111 , V_109 ) ;
F_74 ( & V_17 -> V_157 ,
& V_53 -> V_152 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_17
L_18 ,
V_53 -> V_50 -> V_68 ,
V_17 -> V_186 ,
V_111 , V_110 ) ;
} else {
F_51 ( V_125
L_19 ,
V_253 ,
F_41 ( & V_17 -> V_81 ) ) ;
}
break;
case V_115 :
V_17 -> V_100 = V_120 ;
if ( V_17 -> V_187 ) {
V_187 = V_17 -> V_187 ;
( (struct V_14 * )
V_187 -> V_189 ) -> V_17 = NULL ;
V_17 -> V_187 = NULL ;
if ( ! ( V_53 -> V_107 -> V_58 & V_119 ) ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_187 -> V_254 =
F_125 ( & V_13 -> V_78 ) + 1 ;
F_126 ( V_187 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
}
V_108 = F_41 ( & V_17 -> V_81 ) ;
V_109 = F_42 ( & V_17 -> V_81 ) ;
F_43 ( V_110 , V_108 ) ;
F_44 ( V_111 , V_109 ) ;
F_67 ( & V_17 -> V_157 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_20
L_18 ,
V_53 -> V_50 -> V_68 ,
V_17 -> V_186 ,
V_111 , V_110 ) ;
}
break;
case V_116 :
if ( V_17 -> V_187 ) {
V_187 = V_17 -> V_187 ;
( (struct V_14 * )
V_187 -> V_189 ) -> V_17 = NULL ;
V_17 -> V_187 = NULL ;
if ( ! ( V_53 -> V_107 -> V_58 & V_119 ) ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_187 -> V_254 =
F_125 ( & V_13 -> V_78 ) + 1 ;
F_126 ( V_187 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
}
F_67 ( & V_17 -> V_157 ) ;
}
F_68 ( V_17 ) ;
break;
default:
F_39 ( 1 ) ;
break;
}
F_19 ( & V_13 -> V_62 , V_58 ) ;
}
static int
F_127 ( struct V_10 * V_11 , void (* V_208) ( struct V_10 * ) )
{
struct V_52 * V_53 =
(struct V_52 * ) V_11 -> V_31 -> V_32 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_31 -> V_34 ;
struct V_16 * V_17 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
int V_60 ;
int V_255 = 0 ;
struct V_187 * V_188 = F_98 ( V_89 ( V_11 -> V_31 ) ) ;
V_60 = F_99 ( V_188 ) ;
if ( V_60 ) {
V_11 -> V_26 = V_60 ;
V_208 ( V_11 ) ;
return 0 ;
}
if ( V_13 -> V_104 & V_256 ) {
if ( V_13 -> V_104 & V_257 )
V_11 -> V_26 = V_258 << 16 ;
else
V_11 -> V_26 = V_259 << 16 ;
V_208 ( V_11 ) ;
return 0 ;
}
V_255 = F_128 ( V_11 ) ;
if ( V_255 < 0 )
return V_260 ;
V_11 -> V_38 = V_208 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
if ( ! ( V_13 -> V_104 & V_261 ) ) {
F_51 ( V_125
L_21 ,
V_13 -> V_145 , V_11 , V_11 -> V_11 [ 0 ] ) ;
V_11 -> V_26 = F_5 ( V_258 , 0 ) ;
goto V_262;
}
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
V_11 -> V_26 = F_5 ( V_263 , 0 ) ;
goto V_262;
}
V_57 = F_129 ( & V_13 -> V_78 , (struct V_2 * ) V_11 ,
V_17 -> V_74 , V_255 ) ;
if ( ! V_57 ) {
F_51 ( V_125 L_22 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_6 ( V_11 ) ;
return V_260 ;
}
V_11 -> V_33 = ( char * ) V_57 ;
F_130 ( V_57 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
return 0 ;
V_262:
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_6 ( V_11 ) ;
if ( V_208 )
V_208 ( V_11 ) ;
return 0 ;
}
