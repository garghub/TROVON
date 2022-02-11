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
case V_28 :
case V_29 :
default:
V_18 = V_25 ;
V_11 -> V_26 = F_5 ( V_18 , 0 ) ;
}
if ( V_11 -> V_30 -> V_31 != NULL )
F_6 ( V_11 ) ;
V_11 -> V_32 = NULL ;
F_2 ( V_13 , V_11 -> V_26 ) ;
V_15 = V_11 -> V_30 -> V_33 ;
if ( V_15 ) {
V_17 = V_15 -> V_17 ;
if ( ! V_11 -> V_26 && V_17 &&
( V_34 > V_11 -> V_30 -> V_35 ) ) {
F_7 ( V_17 , V_11 -> V_30 ) ;
} else if ( V_11 -> V_26 == V_36 && V_17 ) {
F_8 ( V_17 , V_11 -> V_30 ) ;
}
}
V_11 -> V_37 ( V_11 ) ;
}
void
F_9 ( void * V_1 , struct V_2 * V_3 )
{
struct V_10 * V_11 = (struct V_10 * ) V_3 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_11 -> V_26 = F_5 ( V_19 , V_38 ) ;
if ( V_11 -> V_30 -> V_31 != NULL )
F_6 ( V_11 ) ;
V_11 -> V_32 = NULL ;
if ( V_34 > V_11 -> V_30 -> V_35 ) {
V_15 = V_11 -> V_30 -> V_33 ;
if ( V_15 ) {
V_17 = V_15 -> V_17 ;
if ( V_17 )
F_7 ( V_17 , V_11 -> V_30 ) ;
}
}
V_11 -> V_37 ( V_11 ) ;
}
void
F_10 ( void * V_1 , struct V_2 * V_3 )
{
struct V_10 * V_11 = (struct V_10 * ) V_3 ;
struct V_12 * V_13 = V_1 ;
V_11 -> V_26 = F_5 ( V_25 , 0 ) ;
if ( V_11 -> V_30 -> V_31 != NULL )
F_6 ( V_11 ) ;
F_2 ( V_13 , V_11 -> V_26 ) ;
V_11 -> V_32 = NULL ;
}
void
F_11 ( void * V_13 , struct V_39 * V_40 ,
enum V_41 V_42 )
{
struct V_10 * V_11 = (struct V_10 * ) V_40 ;
T_3 * V_43 ;
V_11 -> V_44 . V_45 |= V_42 << 1 ;
F_12 ( V_46 , ( unsigned long * ) & V_11 -> V_44 . V_45 ) ;
V_43 = ( T_3 * ) V_11 -> V_44 . V_47 ;
V_11 -> V_44 . V_47 = NULL ;
if ( V_43 )
F_13 ( V_43 ) ;
}
static const char *
F_14 ( struct V_48 * V_49 )
{
static char V_50 [ 256 ] ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
snprintf ( V_50 , sizeof( V_50 ) ,
L_1 L_2 ,
V_13 -> V_53 , V_54 ) ;
return V_50 ;
}
static int
F_15 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_30 -> V_31 ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
T_4 V_58 ;
int V_59 = V_60 ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
V_56 = (struct V_55 * ) V_11 -> V_32 ;
if ( ! V_56 ) {
V_59 = V_62 ;
goto V_63;
}
if ( V_56 -> V_3 != (struct V_2 * ) V_11 ) {
V_59 = V_60 ;
goto V_63;
}
F_2 ( V_13 , V_56 -> V_64 ) ;
F_17 ( V_65 , V_13 , V_66 ,
L_3 ,
V_52 -> V_49 -> V_67 , V_11 , V_56 -> V_64 ) ;
( void ) F_18 ( V_56 ) ;
F_19 ( & V_13 -> V_61 , V_57 ) ;
V_58 = 10 ;
while ( (struct V_55 * ) V_11 -> V_32 == V_56 ) {
F_20 ( V_68 ) ;
F_21 ( V_58 ) ;
if ( V_58 < 4 * V_69 )
V_58 *= 2 ;
}
V_11 -> V_37 ( V_11 ) ;
F_2 ( V_13 , V_56 -> V_64 ) ;
F_17 ( V_65 , V_13 , V_66 ,
L_4 ,
V_52 -> V_49 -> V_67 , V_11 , V_56 -> V_64 ) ;
return V_62 ;
V_63:
F_19 ( & V_13 -> V_61 , V_57 ) ;
return V_59 ;
}
static T_5
F_22 ( struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_16 * V_17 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
T_5 V_59 = V_74 ;
struct V_75 V_76 ;
V_71 = F_23 ( & V_13 -> V_77 , (struct V_39 * ) V_11 ) ;
if ( ! V_71 ) {
F_17 ( V_78 , V_13 , V_66 ,
L_5 ) ;
V_59 = V_79 ;
goto V_63;
}
V_11 -> V_32 = NULL ;
V_11 -> V_44 . V_45 = 0 ;
V_73 = F_24 ( & V_17 -> V_80 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_25 ( V_71 , V_73 , V_76 ,
V_81 , V_82 ) ;
V_63:
return V_59 ;
}
static int
F_26 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_30 -> V_31 ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_14 * V_15 = V_11 -> V_30 -> V_33 ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_70 * V_71 ;
struct V_16 * V_17 ;
struct V_72 * V_73 ;
F_27 ( V_43 ) ;
int V_59 = V_62 ;
unsigned long V_57 ;
enum V_41 V_83 ;
struct V_75 V_76 ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
F_19 ( & V_13 -> V_61 , V_57 ) ;
V_59 = V_60 ;
goto V_63;
}
V_71 = F_23 ( & V_13 -> V_77 , (struct V_39 * ) V_11 ) ;
if ( ! V_71 ) {
F_17 ( V_78 , V_13 , V_66 ,
L_6 ) ;
F_19 ( & V_13 -> V_61 , V_57 ) ;
V_59 = V_60 ;
goto V_63;
}
V_11 -> V_32 = NULL ;
V_11 -> V_44 . V_47 = ( char * ) & V_43 ;
V_11 -> V_44 . V_45 = 0 ;
V_73 = F_24 ( & V_17 -> V_80 ) ;
F_28 ( V_11 -> V_30 -> V_84 , & V_76 ) ;
F_25 ( V_71 , V_73 , V_76 ,
V_85 , V_86 ) ;
F_19 ( & V_13 -> V_61 , V_57 ) ;
F_29 ( V_43 , F_30 ( V_46 ,
( unsigned long * ) & V_11 -> V_44 . V_45 ) ) ;
V_83 = V_11 -> V_44 . V_45 >> 1 ;
if ( V_83 != V_87 ) {
F_17 ( V_78 , V_13 , V_66 ,
L_7 , V_83 ) ;
V_59 = V_60 ;
}
V_63:
return V_59 ;
}
static int
F_31 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_30 -> V_31 ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_16 * V_17 ;
unsigned long V_57 ;
T_4 V_88 , V_59 , V_89 = 0 ;
F_27 ( V_43 ) ;
enum V_41 V_83 ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
V_17 = F_32 ( V_52 , V_88 ) ;
if ( V_17 ) {
V_11 -> V_44 . V_47 = ( char * ) & V_43 ;
V_59 = F_22 ( V_13 , V_11 , V_17 ) ;
if ( V_59 != V_74 ) {
V_89 ++ ;
continue;
}
F_19 ( & V_13 -> V_61 , V_57 ) ;
F_29 ( V_43 , F_30 ( V_46 ,
( unsigned long * ) & V_11 -> V_44 . V_45 ) ) ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
V_83 = V_11 -> V_44 . V_45 >> 1 ;
if ( V_83 != V_87 ) {
F_17 ( V_78 , V_13 , V_66 ,
L_8
L_9 , V_83 ) ;
V_89 ++ ;
}
}
}
F_19 ( & V_13 -> V_61 , V_57 ) ;
if ( V_89 )
return V_60 ;
return V_62 ;
}
static void
F_33 ( struct V_91 * V_92 )
{
V_92 -> V_33 = NULL ;
return;
}
void
F_34 ( struct V_12 * V_13 , struct V_93 * * V_17 ,
struct V_16 * * V_94 )
{
* V_94 = F_35 ( sizeof( struct V_16 ) , V_95 ) ;
if ( * V_94 == NULL )
return;
( * V_94 ) -> V_96 = V_13 -> V_96 ;
* V_17 = & ( * V_94 ) -> V_80 ;
( * V_94 ) -> V_97 = V_98 ;
F_36 ( & ( * V_94 ) -> V_99 , V_100 ) ;
V_13 -> V_101 |= V_102 ;
}
void
F_37 ( struct V_12 * V_13 , struct V_16 * V_94 )
{
struct V_103 * V_104 ;
T_6 V_105 ;
T_4 V_106 ;
char V_107 [ 32 ] , V_108 [ 16 ] ;
struct V_109 * V_96 = V_94 -> V_96 ;
F_38 ( V_94 -> V_97 == V_110 ) ;
V_94 -> V_111 = 1 ;
if ( V_94 -> V_97 == V_112 )
V_94 -> V_111 = 0 ;
V_94 -> V_97 = V_113 ;
V_104 = F_39 ( & V_94 -> V_80 ) ;
V_94 -> V_52 = V_104 -> V_52 ;
V_105 = F_40 ( & V_94 -> V_80 ) ;
V_106 = F_41 ( & V_94 -> V_80 ) ;
F_42 ( V_107 , V_105 ) ;
F_43 ( V_108 , V_106 ) ;
F_17 ( V_65 , V_13 , V_66 ,
L_10 ,
V_104 -> V_52 -> V_49 -> V_67 ,
V_108 , V_107 ) ;
if ( V_94 -> V_111 )
V_111 ( V_96 -> V_114 , & V_94 -> V_99 ) ;
}
void
F_44 ( struct V_16 * V_94 )
{
struct V_103 * V_104 ;
struct V_109 * V_96 = V_94 -> V_96 ;
V_94 -> V_73 = F_24 ( & V_94 -> V_80 ) ;
V_104 = F_39 ( & V_94 -> V_80 ) ;
V_94 -> V_97 = V_110 ;
V_94 -> V_111 = 1 ;
V_94 -> V_52 = V_104 -> V_52 ;
if ( V_94 -> V_111 )
V_111 ( V_96 -> V_114 , & V_94 -> V_99 ) ;
}
void
F_45 ( struct V_16 * V_94 )
{
struct V_103 * V_104 ;
struct V_12 * V_13 ;
struct V_109 * V_96 = V_94 -> V_96 ;
V_104 = F_39 ( & V_94 -> V_80 ) ;
V_13 = V_104 -> V_13 ;
if ( ( V_13 -> V_115 . V_57 & V_116 ) ||
( V_104 -> V_57 & V_116 ) ) {
V_94 -> V_97 = V_117 ;
return;
}
V_94 -> V_52 = V_104 -> V_52 ;
V_94 -> V_97 = V_112 ;
V_94 -> V_111 = 1 ;
if ( V_94 -> V_111 )
V_111 ( V_96 -> V_114 , & V_94 -> V_99 ) ;
}
int
F_46 ( struct V_12 * V_13 , struct V_51 * V_52 ,
struct V_30 * V_118 )
{
int error = 1 ;
F_47 ( & V_119 ) ;
if ( ! F_48 ( & V_120 , V_121 ) ) {
F_49 ( & V_119 ) ;
F_50 ( V_122 L_11 ) ;
goto V_63;
}
error = F_51 ( & V_120 , V_52 ,
& V_52 -> V_123 ) ;
if ( error ) {
F_49 ( & V_119 ) ;
F_50 ( V_122 L_12 ) ;
goto V_63;
}
F_49 ( & V_119 ) ;
V_52 -> V_49 = F_52 ( V_52 , V_13 ) ;
if ( ! V_52 -> V_49 ) {
error = 1 ;
goto V_124;
}
V_52 -> V_49 -> V_33 [ 0 ] = ( unsigned long ) V_52 ;
V_52 -> V_49 -> V_125 = V_52 -> V_123 ;
V_52 -> V_49 -> V_126 = - 1 ;
V_52 -> V_49 -> V_127 = V_90 ;
V_52 -> V_49 -> V_128 = V_129 ;
V_52 -> V_49 -> V_130 = 16 ;
V_52 -> V_49 -> V_131 = V_13 -> V_132 . V_133 ;
if ( V_52 -> V_104 -> V_134 == V_135 )
V_52 -> V_49 -> V_136 = V_137 ;
else
V_52 -> V_49 -> V_136 =
V_138 ;
error = F_53 ( V_52 -> V_49 , V_118 , & V_13 -> V_139 -> V_118 ) ;
if ( error ) {
F_50 ( V_122 L_13 , error ) ;
goto V_140;
}
return 0 ;
V_140:
F_54 ( V_52 -> V_49 ) ;
V_52 -> V_49 = NULL ;
V_124:
F_47 ( & V_119 ) ;
F_55 ( & V_120 , V_52 -> V_123 ) ;
F_49 ( & V_119 ) ;
V_63:
return error ;
}
void
F_56 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
F_2 ( V_13 , V_13 -> V_141 ) ;
F_17 ( V_65 , V_13 , V_66 , L_14 ,
V_52 -> V_49 -> V_67 ) ;
F_57 ( V_52 -> V_49 ) ;
F_58 ( V_52 -> V_49 ) ;
F_54 ( V_52 -> V_49 ) ;
F_47 ( & V_119 ) ;
F_55 ( & V_120 , V_52 -> V_123 ) ;
F_49 ( & V_119 ) ;
}
static void
F_59 ( struct V_142 * V_143 )
{
struct V_51 * V_52 =
F_60 ( V_143 , struct V_51 , V_144 ) ;
if ( V_52 -> V_104 -> V_134 != V_135 ) {
V_52 -> V_57 |= V_116 ;
F_61 ( V_52 -> V_145 ) ;
}
}
T_5
F_62 ( struct V_12 * V_13 , struct V_103 * V_104 )
{
int V_59 = V_74 ;
struct V_51 * V_52 ;
V_52 = F_35 ( sizeof( struct V_51 ) , V_95 ) ;
if ( V_52 == NULL ) {
V_59 = V_146 ;
goto V_147;
}
V_104 -> V_52 = V_52 ;
V_52 -> V_104 = V_104 ;
V_52 -> V_13 = V_13 ;
F_36 ( & V_52 -> V_144 , F_59 ) ;
F_63 ( & V_52 -> V_148 ) ;
F_63 ( & V_52 -> V_149 ) ;
V_147:
return V_59 ;
}
void
F_64 ( struct V_12 * V_13 , struct V_103 * V_104 )
{
struct V_51 * V_52 = V_104 -> V_52 ;
V_111 ( V_13 -> V_96 -> V_114 ,
& V_52 -> V_144 ) ;
}
void
F_65 ( struct V_51 * V_52 )
{
struct V_150 * V_151 , * V_152 ;
unsigned long V_57 ;
struct V_12 * V_13 = V_52 -> V_13 ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
F_66 (bp, bp_new, &im_port->binding_list,
list_entry) {
F_67 ( & V_151 -> V_153 ) ;
F_68 ( V_151 ) ;
}
F_38 ( ! F_69 ( & V_52 -> V_148 ) ) ;
F_19 ( & V_13 -> V_61 , V_57 ) ;
}
static void F_70 ( struct V_142 * V_143 )
{
struct V_109 * V_96 =
F_60 ( V_143 , struct V_109 , V_154 ) ;
struct V_155 * V_156 ;
struct V_12 * V_13 = V_96 -> V_13 ;
struct V_48 * V_49 = V_13 -> V_115 . V_52 -> V_49 ;
void * V_157 ;
unsigned long V_57 ;
while ( ! F_69 ( & V_13 -> V_158 ) ) {
F_16 ( & V_13 -> V_159 , V_57 ) ;
F_71 ( & V_13 -> V_158 , & V_156 ) ;
F_19 ( & V_13 -> V_159 , V_57 ) ;
V_157 = ( char * ) V_156 + sizeof( struct V_160 ) ;
F_72 ( V_49 , F_73 () ,
sizeof( struct V_155 ) -
sizeof( struct V_160 ) ,
( char * ) V_157 , V_161 ) ;
F_16 ( & V_13 -> V_159 , V_57 ) ;
F_74 ( & V_156 -> V_162 , & V_13 -> V_163 ) ;
F_19 ( & V_13 -> V_159 , V_57 ) ;
}
}
T_5
F_75 ( struct V_12 * V_13 )
{
struct V_109 * V_96 ;
V_96 = F_35 ( sizeof( struct V_109 ) , V_121 ) ;
if ( V_96 == NULL )
return V_146 ;
V_13 -> V_96 = V_96 ;
V_96 -> V_13 = V_13 ;
if ( F_76 ( V_13 ) != V_74 ) {
F_68 ( V_96 ) ;
return V_79 ;
}
F_36 ( & V_96 -> V_154 , F_70 ) ;
return V_74 ;
}
void
F_77 ( struct V_12 * V_13 )
{
if ( V_13 -> V_96 ) {
F_78 ( V_13 -> V_96 ) ;
F_68 ( V_13 -> V_96 ) ;
V_13 -> V_96 = NULL ;
}
}
struct V_48 *
F_52 ( struct V_51 * V_52 , struct V_12 * V_13 )
{
struct V_164 * V_165 ;
if ( V_52 -> V_104 -> V_134 == V_135 )
V_165 = & V_166 ;
else
V_165 = & V_167 ;
if ( V_168 != V_169 >> 1 )
V_165 -> V_170 = V_168 << 1 ;
V_165 -> V_171 = V_13 -> V_132 . V_172 ;
return F_79 ( V_165 , sizeof( unsigned long ) ) ;
}
void
F_80 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
if ( ! ( V_52 -> V_57 & V_116 ) )
F_81 ( V_13 -> V_96 -> V_114 ) ;
F_56 ( V_52 -> V_13 , V_52 ) ;
F_65 ( V_52 ) ;
F_68 ( V_52 ) ;
}
void
F_78 ( struct V_109 * V_96 )
{
if ( V_96 && V_96 -> V_114 ) {
F_81 ( V_96 -> V_114 ) ;
F_82 ( V_96 -> V_114 ) ;
V_96 -> V_114 = NULL ;
}
}
T_5
F_76 ( struct V_12 * V_13 )
{
struct V_109 * V_96 = V_13 -> V_96 ;
F_2 ( V_13 , 0 ) ;
snprintf ( V_96 -> V_173 , V_174 , L_15 ,
V_13 -> V_141 ) ;
V_96 -> V_114 = F_83 ( V_96 -> V_173 ) ;
if ( ! V_96 -> V_114 )
return V_79 ;
return V_74 ;
}
static int
F_84 ( struct V_91 * V_92 )
{
if ( V_92 -> V_175 )
F_85 ( V_92 , V_34 ) ;
else
F_86 ( V_92 , V_34 ) ;
return 0 ;
}
T_5
F_87 ( void )
{
V_137 =
F_88 ( & V_176 ) ;
if ( ! V_137 )
return V_146 ;
V_138 =
F_88 ( & V_177 ) ;
if ( ! V_138 ) {
F_89 ( V_137 ) ;
return V_146 ;
}
return V_74 ;
}
void
F_90 ( void )
{
if ( V_137 )
F_89 ( V_137 ) ;
if ( V_138 )
F_89 ( V_138 ) ;
}
void
F_7 ( struct V_16 * V_17 , struct V_91 * V_92 )
{
struct V_91 * V_178 ;
if ( ( ( V_179 - V_17 -> V_180 ) >
V_181 * V_69 ) &&
( ( V_179 - V_17 -> V_182 ) >
V_181 * V_69 ) ) {
F_91 (tmp_sdev, sdev->host) {
if ( V_34 > V_178 -> V_35 ) {
if ( V_178 -> V_183 != V_92 -> V_183 )
continue;
if ( V_178 -> V_184 )
F_92 ( V_178 ,
V_185 ,
V_178 -> V_35 + 1 ) ;
else
F_92 ( V_178 ,
V_186 ,
V_178 -> V_35 + 1 ) ;
V_17 -> V_180 = V_179 ;
}
}
}
}
void
F_8 ( struct V_16 * V_17 , struct V_91 * V_92 )
{
struct V_91 * V_178 ;
V_17 -> V_182 = V_179 ;
F_91 (tmp_sdev, sdev->host) {
if ( V_178 -> V_183 != V_92 -> V_183 )
continue;
F_93 ( V_178 , V_178 -> V_35 - 1 ) ;
}
}
struct V_16 *
F_32 ( struct V_51 * V_52 , int V_183 )
{
struct V_16 * V_17 = NULL ;
F_94 (itnim, &im_port->itnim_mapped_list, list_entry) {
if ( V_183 == V_17 -> V_187 )
return V_17 ;
}
return NULL ;
}
static int
F_95 ( struct V_91 * V_92 ,
struct V_188 * V_189 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_189 -> V_190 ;
struct V_191 * V_77 = V_15 -> V_17 -> V_73 -> V_77 ;
struct V_192 * V_193 = V_15 -> V_17 -> V_73 -> V_189 ;
struct V_194 * V_195 = F_96 ( V_77 ) ;
int V_88 = 0 , V_196 = - V_197 ;
for ( V_88 = 0 ; V_88 < V_198 ; V_88 ++ ) {
if ( V_195 [ V_88 ] . V_97 == V_199 &&
F_97 ( & V_195 [ V_88 ] . V_84 ) == V_92 -> V_84 &&
V_195 [ V_88 ] . V_200 == V_193 -> V_201 &&
V_195 [ V_88 ] . V_202 == ( T_1 ) V_193 -> V_203 . V_202 ) {
V_196 = V_74 ;
break;
}
}
return V_196 ;
}
static int
F_98 ( struct V_91 * V_92 )
{
struct V_188 * V_189 = F_99 ( F_100 ( V_92 ) ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_189 -> V_190 ;
struct V_191 * V_77 = V_15 -> V_17 -> V_73 -> V_77 ;
if ( ! V_189 || F_101 ( V_189 ) )
return - V_197 ;
if ( F_102 ( V_77 ) == V_204 ) {
if ( V_92 -> V_84 == 0 ) {
V_92 -> V_205 |= V_206 |
V_207 ;
goto V_208;
}
if ( F_95 ( V_92 , V_189 ) !=
V_74 )
return - V_197 ;
}
V_208:
V_92 -> V_33 = V_189 -> V_190 ;
return 0 ;
}
T_4
F_103 ( struct V_191 * V_77 )
{
struct V_209 * V_210 ;
T_4 V_211 = 0 ;
V_210 = F_35 ( sizeof( struct V_209 ) , V_121 ) ;
if ( ! V_210 )
return 0 ;
F_104 ( & V_77 -> V_212 , V_210 ) ;
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
F_105 ( struct V_51 * V_52 )
{
struct V_48 * V_31 = V_52 -> V_49 ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_103 * V_104 = V_52 -> V_104 ;
char V_226 [ V_227 ] ;
struct V_228 * V_229 = F_106 ( & V_13 -> V_77 ) ;
F_107 ( V_31 ) =
F_108 ( ( F_109 ( V_104 -> V_230 ) ) ) ;
F_110 ( V_31 ) =
F_108 ( ( F_111 ( V_104 -> V_230 ) ) ) ;
F_112 ( V_31 ) = F_113 ( & V_13 -> V_77 ) ;
F_114 ( V_31 ) = V_231 ;
memset ( F_115 ( V_31 ) , 0 ,
sizeof( F_115 ( V_31 ) ) ) ;
if ( V_232 & V_233 )
F_115 ( V_31 ) [ 2 ] = 1 ;
F_115 ( V_31 ) [ 7 ] = 1 ;
strncpy ( V_226 , V_13 -> V_234 . V_235 . V_236 . V_237 . V_238 . V_226 ,
V_227 ) ;
sprintf ( F_116 ( V_31 ) , L_16 , V_226 ) ;
F_117 ( V_31 ) = F_103 ( & V_13 -> V_77 ) ;
F_118 ( V_31 ) = V_229 -> V_239 . V_240 ;
}
static void
F_119 ( struct V_51 * V_52 , struct V_16 * V_17 )
{
struct V_241 V_242 ;
struct V_188 * V_188 ;
struct V_14 * V_15 ;
V_242 . V_243 =
F_108 ( F_120 ( & V_17 -> V_80 ) ) ;
V_242 . V_244 =
F_108 ( F_40 ( & V_17 -> V_80 ) ) ;
V_242 . V_245 =
F_121 ( F_41 ( & V_17 -> V_80 ) ) ;
V_242 . V_246 = V_247 ;
V_17 -> V_188 = V_188 =
F_122 ( V_52 -> V_49 , 0 , & V_242 ) ;
if ( ! V_188 )
return;
V_188 -> V_248 =
F_123 ( & V_17 -> V_80 ) ;
V_188 -> V_249 = F_124 ( & V_17 -> V_80 ) ;
V_15 = V_188 -> V_190 ;
V_15 -> V_17 = V_17 ;
V_242 . V_246 |= V_250 ;
if ( V_242 . V_246 != V_247 )
F_125 ( V_188 , V_242 . V_246 ) ;
if ( ( V_188 -> V_251 != - 1 )
&& ( V_188 -> V_251 < V_90 ) )
V_17 -> V_187 = V_188 -> V_251 ;
V_17 -> V_252 = V_188 -> V_252 ;
return;
}
static void
V_100 ( struct V_142 * V_143 )
{
struct V_16 * V_17 = F_60 ( V_143 , struct V_16 ,
V_99 ) ;
struct V_109 * V_96 = V_17 -> V_96 ;
struct V_12 * V_13 = V_96 -> V_13 ;
struct V_51 * V_52 ;
unsigned long V_57 ;
struct V_188 * V_188 ;
T_6 V_105 ;
T_4 V_106 ;
char V_107 [ 32 ] , V_108 [ 16 ] ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
V_52 = V_17 -> V_52 ;
F_2 ( V_13 , V_17 -> V_97 ) ;
switch ( V_17 -> V_97 ) {
case V_110 :
if ( ! V_17 -> V_188 ) {
F_19 ( & V_13 -> V_61 , V_57 ) ;
F_119 ( V_52 , V_17 ) ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
V_105 = F_40 ( & V_17 -> V_80 ) ;
V_106 = F_41 ( & V_17 -> V_80 ) ;
F_42 ( V_107 , V_105 ) ;
F_43 ( V_108 , V_106 ) ;
F_74 ( & V_17 -> V_153 ,
& V_52 -> V_148 ) ;
F_17 ( V_65 , V_13 , V_66 ,
L_17
L_18 ,
V_52 -> V_49 -> V_67 ,
V_17 -> V_187 ,
V_108 , V_107 ) ;
} else {
F_50 ( V_122
L_19 ,
V_253 ,
F_40 ( & V_17 -> V_80 ) ) ;
}
break;
case V_112 :
V_17 -> V_97 = V_117 ;
if ( V_17 -> V_188 ) {
V_188 = V_17 -> V_188 ;
( (struct V_14 * )
V_188 -> V_190 ) -> V_17 = NULL ;
V_17 -> V_188 = NULL ;
if ( ! ( V_52 -> V_104 -> V_57 & V_116 ) ) {
F_19 ( & V_13 -> V_61 , V_57 ) ;
V_188 -> V_254 =
F_126 ( & V_13 -> V_77 ) + 1 ;
F_127 ( V_188 ) ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
}
V_105 = F_40 ( & V_17 -> V_80 ) ;
V_106 = F_41 ( & V_17 -> V_80 ) ;
F_42 ( V_107 , V_105 ) ;
F_43 ( V_108 , V_106 ) ;
F_67 ( & V_17 -> V_153 ) ;
F_17 ( V_65 , V_13 , V_66 ,
L_20
L_18 ,
V_52 -> V_49 -> V_67 ,
V_17 -> V_187 ,
V_108 , V_107 ) ;
}
break;
case V_113 :
if ( V_17 -> V_188 ) {
V_188 = V_17 -> V_188 ;
( (struct V_14 * )
V_188 -> V_190 ) -> V_17 = NULL ;
V_17 -> V_188 = NULL ;
if ( ! ( V_52 -> V_104 -> V_57 & V_116 ) ) {
F_19 ( & V_13 -> V_61 , V_57 ) ;
V_188 -> V_254 =
F_126 ( & V_13 -> V_77 ) + 1 ;
F_127 ( V_188 ) ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
}
F_67 ( & V_17 -> V_153 ) ;
}
F_68 ( V_17 ) ;
break;
default:
F_38 ( 1 ) ;
break;
}
F_19 ( & V_13 -> V_61 , V_57 ) ;
}
static int
F_128 ( struct V_10 * V_11 , void (* V_208) ( struct V_10 * ) )
{
struct V_51 * V_52 =
(struct V_51 * ) V_11 -> V_30 -> V_31 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_30 -> V_33 ;
struct V_16 * V_17 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
int V_59 ;
int V_255 = 0 ;
struct V_188 * V_189 = F_99 ( F_100 ( V_11 -> V_30 ) ) ;
V_59 = F_101 ( V_189 ) ;
if ( V_59 ) {
V_11 -> V_26 = V_59 ;
V_208 ( V_11 ) ;
return 0 ;
}
V_255 = F_129 ( V_11 ) ;
if ( V_255 < 0 )
return V_256 ;
V_11 -> V_37 = V_208 ;
F_16 ( & V_13 -> V_61 , V_57 ) ;
if ( ! ( V_13 -> V_101 & V_257 ) ) {
F_50 ( V_122
L_21 ,
V_13 -> V_141 , V_11 , V_11 -> V_11 [ 0 ] ) ;
V_11 -> V_26 = F_5 ( V_258 , 0 ) ;
goto V_259;
}
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
V_11 -> V_26 = F_5 ( V_260 , 0 ) ;
goto V_259;
}
V_56 = F_130 ( & V_13 -> V_77 , (struct V_2 * ) V_11 ,
V_17 -> V_73 , V_255 ) ;
if ( ! V_56 ) {
F_50 ( V_122 L_22 ) ;
F_19 ( & V_13 -> V_61 , V_57 ) ;
F_6 ( V_11 ) ;
return V_256 ;
}
V_11 -> V_32 = ( char * ) V_56 ;
F_131 ( V_56 ) ;
F_19 ( & V_13 -> V_61 , V_57 ) ;
return 0 ;
V_259:
F_19 ( & V_13 -> V_61 , V_57 ) ;
F_6 ( V_11 ) ;
if ( V_208 )
V_208 ( V_11 ) ;
return 0 ;
}
