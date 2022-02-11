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
L_1 L_2 ,
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
L_3 ,
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
L_4 ,
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
L_5 ) ;
V_60 = V_80 ;
goto V_64;
}
V_11 -> V_33 = NULL ;
V_11 -> V_45 . V_46 = 0 ;
V_74 = F_24 ( & V_17 -> V_81 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
F_25 ( V_72 , V_74 , V_77 ,
V_82 , V_83 ) ;
V_64:
return V_60 ;
}
static int
F_26 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = V_11 -> V_31 -> V_32 ;
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_14 * V_15 = V_11 -> V_31 -> V_34 ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_71 * V_72 ;
struct V_16 * V_17 ;
struct V_73 * V_74 ;
F_27 ( V_44 ) ;
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
F_28 ( V_11 -> V_31 -> V_85 , & V_77 ) ;
F_25 ( V_72 , V_74 , V_77 ,
V_86 , V_87 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_29 ( V_44 , F_30 ( V_47 ,
( unsigned long * ) & V_11 -> V_45 . V_46 ) ) ;
V_84 = V_11 -> V_45 . V_46 >> 1 ;
if ( V_84 != V_88 ) {
F_17 ( V_79 , V_13 , V_67 ,
L_7 , V_84 ) ;
V_60 = V_61 ;
}
V_64:
return V_60 ;
}
static int
F_31 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = V_11 -> V_31 -> V_32 ;
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_16 * V_17 ;
unsigned long V_58 ;
T_4 V_89 , V_60 , V_90 = 0 ;
F_27 ( V_44 ) ;
enum V_42 V_84 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
V_17 = F_32 ( V_53 , V_89 ) ;
if ( V_17 ) {
V_11 -> V_45 . V_48 = ( char * ) & V_44 ;
V_60 = F_22 ( V_13 , V_11 , V_17 ) ;
if ( V_60 != V_75 ) {
V_90 ++ ;
continue;
}
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_29 ( V_44 , F_30 ( V_47 ,
( unsigned long * ) & V_11 -> V_45 . V_46 ) ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_84 = V_11 -> V_45 . V_46 >> 1 ;
if ( V_84 != V_88 ) {
F_17 ( V_79 , V_13 , V_67 ,
L_8
L_9 , V_84 ) ;
V_90 ++ ;
}
}
}
F_19 ( & V_13 -> V_62 , V_58 ) ;
if ( V_90 )
return V_61 ;
return V_63 ;
}
static void
F_33 ( struct V_92 * V_93 )
{
V_93 -> V_34 = NULL ;
return;
}
void
F_34 ( struct V_12 * V_13 , struct V_94 * * V_17 ,
struct V_16 * * V_95 )
{
* V_95 = F_35 ( sizeof( struct V_16 ) , V_96 ) ;
if ( * V_95 == NULL )
return;
( * V_95 ) -> V_97 = V_13 -> V_97 ;
* V_17 = & ( * V_95 ) -> V_81 ;
( * V_95 ) -> V_98 = V_99 ;
F_36 ( & ( * V_95 ) -> V_100 , V_101 ) ;
V_13 -> V_102 |= V_103 ;
}
void
F_37 ( struct V_12 * V_13 , struct V_16 * V_95 )
{
struct V_104 * V_105 ;
T_6 V_106 ;
T_4 V_107 ;
char V_108 [ 32 ] , V_109 [ 16 ] ;
struct V_110 * V_97 = V_95 -> V_97 ;
F_38 ( V_95 -> V_98 == V_111 ) ;
V_95 -> V_112 = 1 ;
if ( V_95 -> V_98 == V_113 )
V_95 -> V_112 = 0 ;
V_95 -> V_98 = V_114 ;
V_105 = F_39 ( & V_95 -> V_81 ) ;
V_95 -> V_53 = V_105 -> V_53 ;
V_106 = F_40 ( & V_95 -> V_81 ) ;
V_107 = F_41 ( & V_95 -> V_81 ) ;
F_42 ( V_108 , V_106 ) ;
F_43 ( V_109 , V_107 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_10 ,
V_105 -> V_53 -> V_50 -> V_68 ,
V_109 , V_108 ) ;
if ( V_95 -> V_112 )
V_112 ( V_97 -> V_115 , & V_95 -> V_100 ) ;
}
void
F_44 ( struct V_16 * V_95 )
{
struct V_104 * V_105 ;
struct V_110 * V_97 = V_95 -> V_97 ;
V_95 -> V_74 = F_24 ( & V_95 -> V_81 ) ;
V_105 = F_39 ( & V_95 -> V_81 ) ;
V_95 -> V_98 = V_111 ;
V_95 -> V_112 = 1 ;
V_95 -> V_53 = V_105 -> V_53 ;
if ( V_95 -> V_112 )
V_112 ( V_97 -> V_115 , & V_95 -> V_100 ) ;
}
void
F_45 ( struct V_16 * V_95 )
{
struct V_104 * V_105 ;
struct V_12 * V_13 ;
struct V_110 * V_97 = V_95 -> V_97 ;
V_105 = F_39 ( & V_95 -> V_81 ) ;
V_13 = V_105 -> V_13 ;
if ( ( V_13 -> V_116 . V_58 & V_117 ) ||
( V_105 -> V_58 & V_117 ) ) {
V_95 -> V_98 = V_118 ;
return;
}
V_95 -> V_53 = V_105 -> V_53 ;
V_95 -> V_98 = V_113 ;
V_95 -> V_112 = 1 ;
if ( V_95 -> V_112 )
V_112 ( V_97 -> V_115 , & V_95 -> V_100 ) ;
}
int
F_46 ( struct V_12 * V_13 , struct V_52 * V_53 ,
struct V_31 * V_119 )
{
int error = 1 ;
F_47 ( & V_120 ) ;
error = F_48 ( & V_121 , V_53 , 0 , 0 , V_122 ) ;
if ( error < 0 ) {
F_49 ( & V_120 ) ;
F_50 ( V_123 L_11 ) ;
goto V_64;
}
V_53 -> V_124 = error ;
F_49 ( & V_120 ) ;
V_53 -> V_50 = F_51 ( V_53 , V_13 ) ;
if ( ! V_53 -> V_50 ) {
error = 1 ;
goto V_125;
}
V_53 -> V_50 -> V_34 [ 0 ] = ( unsigned long ) V_53 ;
V_53 -> V_50 -> V_126 = V_53 -> V_124 ;
V_53 -> V_50 -> V_127 = - 1 ;
V_53 -> V_50 -> V_128 = V_91 ;
V_53 -> V_50 -> V_129 = V_130 ;
V_53 -> V_50 -> V_131 = 16 ;
V_53 -> V_50 -> V_132 = V_13 -> V_133 . V_134 ;
if ( V_53 -> V_105 -> V_135 == V_136 )
V_53 -> V_50 -> V_137 = V_138 ;
else
V_53 -> V_50 -> V_137 =
V_139 ;
error = F_52 ( V_53 -> V_50 , V_119 , & V_13 -> V_140 -> V_119 ) ;
if ( error ) {
F_50 ( V_123 L_12 , error ) ;
goto V_141;
}
return 0 ;
V_141:
F_53 ( V_53 -> V_50 ) ;
V_53 -> V_50 = NULL ;
V_125:
F_47 ( & V_120 ) ;
F_54 ( & V_121 , V_53 -> V_124 ) ;
F_49 ( & V_120 ) ;
V_64:
return error ;
}
void
F_55 ( struct V_12 * V_13 , struct V_52 * V_53 )
{
F_2 ( V_13 , V_13 -> V_142 ) ;
F_17 ( V_66 , V_13 , V_67 , L_13 ,
V_53 -> V_50 -> V_68 ) ;
F_56 ( V_53 -> V_50 ) ;
F_57 ( V_53 -> V_50 ) ;
F_53 ( V_53 -> V_50 ) ;
F_47 ( & V_120 ) ;
F_54 ( & V_121 , V_53 -> V_124 ) ;
F_49 ( & V_120 ) ;
}
static void
F_58 ( struct V_143 * V_144 )
{
struct V_52 * V_53 =
F_59 ( V_144 , struct V_52 , V_145 ) ;
if ( V_53 -> V_105 -> V_135 != V_136 ) {
V_53 -> V_58 |= V_117 ;
F_60 ( V_53 -> V_146 ) ;
}
}
T_5
F_61 ( struct V_12 * V_13 , struct V_104 * V_105 )
{
int V_60 = V_75 ;
struct V_52 * V_53 ;
V_53 = F_35 ( sizeof( struct V_52 ) , V_96 ) ;
if ( V_53 == NULL ) {
V_60 = V_147 ;
goto V_148;
}
V_105 -> V_53 = V_53 ;
V_53 -> V_105 = V_105 ;
V_53 -> V_13 = V_13 ;
F_36 ( & V_53 -> V_145 , F_58 ) ;
F_62 ( & V_53 -> V_149 ) ;
F_62 ( & V_53 -> V_150 ) ;
V_148:
return V_60 ;
}
void
F_63 ( struct V_12 * V_13 , struct V_104 * V_105 )
{
struct V_52 * V_53 = V_105 -> V_53 ;
V_112 ( V_13 -> V_97 -> V_115 ,
& V_53 -> V_145 ) ;
}
void
F_64 ( struct V_52 * V_53 )
{
struct V_151 * V_152 , * V_153 ;
unsigned long V_58 ;
struct V_12 * V_13 = V_53 -> V_13 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
F_65 (bp, bp_new, &im_port->binding_list,
list_entry) {
F_66 ( & V_152 -> V_154 ) ;
F_67 ( V_152 ) ;
}
F_38 ( ! F_68 ( & V_53 -> V_149 ) ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
}
static void F_69 ( struct V_143 * V_144 )
{
struct V_110 * V_97 =
F_59 ( V_144 , struct V_110 , V_155 ) ;
struct V_156 * V_157 ;
struct V_12 * V_13 = V_97 -> V_13 ;
struct V_49 * V_50 = V_13 -> V_116 . V_53 -> V_50 ;
void * V_158 ;
unsigned long V_58 ;
while ( ! F_68 ( & V_13 -> V_159 ) ) {
F_16 ( & V_13 -> V_160 , V_58 ) ;
F_70 ( & V_13 -> V_159 , & V_157 ) ;
F_19 ( & V_13 -> V_160 , V_58 ) ;
V_158 = ( char * ) V_157 + sizeof( struct V_161 ) ;
F_71 ( V_50 , F_72 () ,
sizeof( struct V_156 ) -
sizeof( struct V_161 ) ,
( char * ) V_158 , V_162 ) ;
F_16 ( & V_13 -> V_160 , V_58 ) ;
F_73 ( & V_157 -> V_163 , & V_13 -> V_164 ) ;
F_19 ( & V_13 -> V_160 , V_58 ) ;
}
}
T_5
F_74 ( struct V_12 * V_13 )
{
struct V_110 * V_97 ;
V_97 = F_35 ( sizeof( struct V_110 ) , V_122 ) ;
if ( V_97 == NULL )
return V_147 ;
V_13 -> V_97 = V_97 ;
V_97 -> V_13 = V_13 ;
if ( F_75 ( V_13 ) != V_75 ) {
F_67 ( V_97 ) ;
return V_80 ;
}
F_36 ( & V_97 -> V_155 , F_69 ) ;
return V_75 ;
}
void
F_76 ( struct V_12 * V_13 )
{
if ( V_13 -> V_97 ) {
F_77 ( V_13 -> V_97 ) ;
F_67 ( V_13 -> V_97 ) ;
V_13 -> V_97 = NULL ;
}
}
struct V_49 *
F_51 ( struct V_52 * V_53 , struct V_12 * V_13 )
{
struct V_165 * V_166 ;
if ( V_53 -> V_105 -> V_135 == V_136 )
V_166 = & V_167 ;
else
V_166 = & V_168 ;
if ( V_169 != V_170 >> 1 )
V_166 -> V_171 = V_169 << 1 ;
V_166 -> V_172 = V_13 -> V_133 . V_173 ;
return F_78 ( V_166 , sizeof( unsigned long ) ) ;
}
void
F_79 ( struct V_12 * V_13 , struct V_52 * V_53 )
{
if ( ! ( V_53 -> V_58 & V_117 ) )
F_80 ( V_13 -> V_97 -> V_115 ) ;
F_55 ( V_53 -> V_13 , V_53 ) ;
F_64 ( V_53 ) ;
F_67 ( V_53 ) ;
}
void
F_77 ( struct V_110 * V_97 )
{
if ( V_97 && V_97 -> V_115 ) {
F_80 ( V_97 -> V_115 ) ;
F_81 ( V_97 -> V_115 ) ;
V_97 -> V_115 = NULL ;
}
}
T_5
F_75 ( struct V_12 * V_13 )
{
struct V_110 * V_97 = V_13 -> V_97 ;
F_2 ( V_13 , 0 ) ;
snprintf ( V_97 -> V_174 , V_175 , L_14 ,
V_13 -> V_142 ) ;
V_97 -> V_115 = F_82 ( V_97 -> V_174 ) ;
if ( ! V_97 -> V_115 )
return V_80 ;
return V_75 ;
}
static int
F_83 ( struct V_92 * V_93 )
{
F_84 ( V_93 , V_35 ) ;
return 0 ;
}
T_5
F_85 ( void )
{
V_138 =
F_86 ( & V_176 ) ;
if ( ! V_138 )
return V_147 ;
V_139 =
F_86 ( & V_177 ) ;
if ( ! V_139 ) {
F_87 ( V_138 ) ;
return V_147 ;
}
return V_75 ;
}
void
F_88 ( void )
{
if ( V_138 )
F_87 ( V_138 ) ;
if ( V_139 )
F_87 ( V_139 ) ;
}
void
F_7 ( struct V_16 * V_17 , struct V_92 * V_93 )
{
struct V_92 * V_178 ;
if ( ( ( V_179 - V_17 -> V_180 ) >
V_181 * V_70 ) &&
( ( V_179 - V_17 -> V_182 ) >
V_181 * V_70 ) ) {
F_89 (tmp_sdev, sdev->host) {
if ( V_35 > V_178 -> V_36 ) {
if ( V_178 -> V_183 != V_93 -> V_183 )
continue;
F_84 ( V_178 ,
V_178 -> V_36 + 1 ) ;
V_17 -> V_180 = V_179 ;
}
}
}
}
void
F_8 ( struct V_16 * V_17 , struct V_92 * V_93 )
{
struct V_92 * V_178 ;
V_17 -> V_182 = V_179 ;
F_89 (tmp_sdev, sdev->host) {
if ( V_178 -> V_183 != V_93 -> V_183 )
continue;
F_90 ( V_178 , V_178 -> V_36 - 1 ) ;
}
}
struct V_16 *
F_32 ( struct V_52 * V_53 , int V_183 )
{
struct V_16 * V_17 = NULL ;
F_91 (itnim, &im_port->itnim_mapped_list, list_entry) {
if ( V_183 == V_17 -> V_184 )
return V_17 ;
}
return NULL ;
}
static int
F_92 ( struct V_92 * V_93 ,
struct V_185 * V_186 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_186 -> V_187 ;
struct V_188 * V_78 = V_15 -> V_17 -> V_74 -> V_78 ;
struct V_189 * V_190 = V_15 -> V_17 -> V_74 -> V_186 ;
struct V_191 * V_192 = F_93 ( V_78 ) ;
int V_89 = 0 , V_193 = - V_194 ;
for ( V_89 = 0 ; V_89 < V_195 ; V_89 ++ ) {
if ( V_192 [ V_89 ] . V_98 == V_196 &&
F_94 ( & V_192 [ V_89 ] . V_85 ) == V_93 -> V_85 &&
V_192 [ V_89 ] . V_197 == V_190 -> V_198 &&
V_192 [ V_89 ] . V_199 == ( T_1 ) V_190 -> V_200 . V_199 ) {
V_193 = V_75 ;
break;
}
}
return V_193 ;
}
static int
F_95 ( struct V_92 * V_93 )
{
struct V_185 * V_186 = F_96 ( F_97 ( V_93 ) ) ;
struct V_14 * V_15 ;
struct V_188 * V_78 ;
if ( ! V_186 || F_98 ( V_186 ) )
return - V_194 ;
V_15 = (struct V_14 * ) V_186 -> V_187 ;
V_78 = V_15 -> V_17 -> V_74 -> V_78 ;
if ( F_99 ( V_78 ) == V_201 ) {
if ( V_93 -> V_85 == 0 ) {
V_93 -> V_202 |= V_203 |
V_204 ;
goto V_205;
}
if ( F_92 ( V_93 , V_186 ) !=
V_75 )
return - V_194 ;
}
V_205:
V_93 -> V_34 = V_186 -> V_187 ;
return 0 ;
}
T_4
F_100 ( struct V_188 * V_78 )
{
struct V_206 * V_207 ;
T_4 V_208 = 0 ;
V_207 = F_35 ( sizeof( struct V_206 ) , V_122 ) ;
if ( ! V_207 )
return 0 ;
F_101 ( & V_78 -> V_209 , V_207 ) ;
if ( V_207 -> V_210 . V_211 == V_212 )
V_208 |= V_213 | V_214 |
V_215 | V_216 ;
else if ( V_207 -> V_210 . V_211 == V_217 ) {
if ( V_207 -> V_210 . V_218 ) {
V_208 |= V_214 |
V_215 |
V_216 | V_219 ;
} else {
V_208 |= V_214 |
V_215 |
V_216 ;
}
} else if ( V_207 -> V_210 . V_211 == V_220 ) {
V_208 |= V_215 | V_216 |
V_219 ;
} else if ( V_207 -> V_210 . V_211 == V_221 ) {
V_208 |= V_222 ;
}
F_67 ( V_207 ) ;
return V_208 ;
}
void
F_102 ( struct V_52 * V_53 )
{
struct V_49 * V_32 = V_53 -> V_50 ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_104 * V_105 = V_53 -> V_105 ;
char V_223 [ V_224 ] ;
struct V_225 * V_226 = F_103 ( & V_13 -> V_78 ) ;
F_104 ( V_32 ) =
F_105 ( ( F_106 ( V_105 -> V_227 ) ) ) ;
F_107 ( V_32 ) =
F_105 ( ( F_108 ( V_105 -> V_227 ) ) ) ;
F_109 ( V_32 ) = F_110 ( & V_13 -> V_78 ) ;
F_111 ( V_32 ) = V_228 ;
memset ( F_112 ( V_32 ) , 0 ,
sizeof( F_112 ( V_32 ) ) ) ;
if ( V_229 & V_230 )
F_112 ( V_32 ) [ 2 ] = 1 ;
F_112 ( V_32 ) [ 7 ] = 1 ;
F_113 ( V_223 , V_13 -> V_231 . V_232 . V_233 . V_234 . V_235 . V_223 ,
V_224 ) ;
sprintf ( F_114 ( V_32 ) , L_15 , V_223 ) ;
F_115 ( V_32 ) = F_100 ( & V_13 -> V_78 ) ;
F_116 ( V_32 ) = V_226 -> V_236 . V_237 ;
}
static void
F_117 ( struct V_52 * V_53 , struct V_16 * V_17 )
{
struct V_238 V_239 ;
struct V_185 * V_185 ;
struct V_14 * V_15 ;
V_239 . V_240 =
F_105 ( F_118 ( & V_17 -> V_81 ) ) ;
V_239 . V_241 =
F_105 ( F_40 ( & V_17 -> V_81 ) ) ;
V_239 . V_242 =
F_119 ( F_41 ( & V_17 -> V_81 ) ) ;
V_239 . V_243 = V_244 ;
V_17 -> V_185 = V_185 =
F_120 ( V_53 -> V_50 , 0 , & V_239 ) ;
if ( ! V_185 )
return;
V_185 -> V_245 =
F_121 ( & V_17 -> V_81 ) ;
V_185 -> V_246 = F_122 ( & V_17 -> V_81 ) ;
V_15 = V_185 -> V_187 ;
V_15 -> V_17 = V_17 ;
V_239 . V_243 |= V_247 ;
if ( V_239 . V_243 != V_244 )
F_123 ( V_185 , V_239 . V_243 ) ;
if ( ( V_185 -> V_248 != - 1 )
&& ( V_185 -> V_248 < V_91 ) )
V_17 -> V_184 = V_185 -> V_248 ;
V_17 -> V_249 = V_185 -> V_249 ;
return;
}
static void
V_101 ( struct V_143 * V_144 )
{
struct V_16 * V_17 = F_59 ( V_144 , struct V_16 ,
V_100 ) ;
struct V_110 * V_97 = V_17 -> V_97 ;
struct V_12 * V_13 = V_97 -> V_13 ;
struct V_52 * V_53 ;
unsigned long V_58 ;
struct V_185 * V_185 ;
T_6 V_106 ;
T_4 V_107 ;
char V_108 [ 32 ] , V_109 [ 16 ] ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_53 = V_17 -> V_53 ;
F_2 ( V_13 , V_17 -> V_98 ) ;
switch ( V_17 -> V_98 ) {
case V_111 :
if ( ! V_17 -> V_185 ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_117 ( V_53 , V_17 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_106 = F_40 ( & V_17 -> V_81 ) ;
V_107 = F_41 ( & V_17 -> V_81 ) ;
F_42 ( V_108 , V_106 ) ;
F_43 ( V_109 , V_107 ) ;
F_73 ( & V_17 -> V_154 ,
& V_53 -> V_149 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_16
L_17 ,
V_53 -> V_50 -> V_68 ,
V_17 -> V_184 ,
V_109 , V_108 ) ;
} else {
F_50 ( V_123
L_18 ,
V_250 ,
F_40 ( & V_17 -> V_81 ) ) ;
}
break;
case V_113 :
V_17 -> V_98 = V_118 ;
if ( V_17 -> V_185 ) {
V_185 = V_17 -> V_185 ;
( (struct V_14 * )
V_185 -> V_187 ) -> V_17 = NULL ;
V_17 -> V_185 = NULL ;
if ( ! ( V_53 -> V_105 -> V_58 & V_117 ) ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_185 -> V_251 =
F_124 ( & V_13 -> V_78 ) + 1 ;
F_125 ( V_185 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
}
V_106 = F_40 ( & V_17 -> V_81 ) ;
V_107 = F_41 ( & V_17 -> V_81 ) ;
F_42 ( V_108 , V_106 ) ;
F_43 ( V_109 , V_107 ) ;
F_66 ( & V_17 -> V_154 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_19
L_17 ,
V_53 -> V_50 -> V_68 ,
V_17 -> V_184 ,
V_109 , V_108 ) ;
}
break;
case V_114 :
if ( V_17 -> V_185 ) {
V_185 = V_17 -> V_185 ;
( (struct V_14 * )
V_185 -> V_187 ) -> V_17 = NULL ;
V_17 -> V_185 = NULL ;
if ( ! ( V_53 -> V_105 -> V_58 & V_117 ) ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_185 -> V_251 =
F_124 ( & V_13 -> V_78 ) + 1 ;
F_125 ( V_185 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
}
F_66 ( & V_17 -> V_154 ) ;
}
F_67 ( V_17 ) ;
break;
default:
F_38 ( 1 ) ;
break;
}
F_19 ( & V_13 -> V_62 , V_58 ) ;
}
static int
F_126 ( struct V_10 * V_11 , void (* V_205) ( struct V_10 * ) )
{
struct V_52 * V_53 =
(struct V_52 * ) V_11 -> V_31 -> V_32 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_31 -> V_34 ;
struct V_16 * V_17 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
int V_60 ;
int V_252 = 0 ;
struct V_185 * V_186 = F_96 ( F_97 ( V_11 -> V_31 ) ) ;
V_60 = F_98 ( V_186 ) ;
if ( V_60 ) {
V_11 -> V_26 = V_60 ;
V_205 ( V_11 ) ;
return 0 ;
}
if ( V_13 -> V_102 & V_253 ) {
if ( V_13 -> V_102 & V_254 )
V_11 -> V_26 = V_255 << 16 ;
else
V_11 -> V_26 = V_256 << 16 ;
V_205 ( V_11 ) ;
return 0 ;
}
V_252 = F_127 ( V_11 ) ;
if ( V_252 < 0 )
return V_257 ;
V_11 -> V_38 = V_205 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
if ( ! ( V_13 -> V_102 & V_258 ) ) {
F_50 ( V_123
L_20 ,
V_13 -> V_142 , V_11 , V_11 -> V_11 [ 0 ] ) ;
V_11 -> V_26 = F_5 ( V_255 , 0 ) ;
goto V_259;
}
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
V_11 -> V_26 = F_5 ( V_260 , 0 ) ;
goto V_259;
}
V_57 = F_128 ( & V_13 -> V_78 , (struct V_2 * ) V_11 ,
V_17 -> V_74 , V_252 ) ;
if ( ! V_57 ) {
F_50 ( V_123 L_21 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_6 ( V_11 ) ;
return V_257 ;
}
V_11 -> V_33 = ( char * ) V_57 ;
F_129 ( V_57 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
return 0 ;
V_259:
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_6 ( V_11 ) ;
if ( V_205 )
V_205 ( V_11 ) ;
return 0 ;
}
