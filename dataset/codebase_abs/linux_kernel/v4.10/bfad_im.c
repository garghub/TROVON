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
struct V_52 * V_53 =
(struct V_52 * ) V_50 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_16 * V_17 ;
unsigned long V_58 ;
T_4 V_89 , V_60 , V_90 = 0 ;
F_28 ( V_44 ) ;
enum V_42 V_84 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
V_17 = F_33 ( V_53 , V_89 ) ;
if ( V_17 ) {
V_11 -> V_45 . V_48 = ( char * ) & V_44 ;
V_60 = F_22 ( V_13 , V_11 , V_17 ) ;
if ( V_60 != V_75 ) {
V_90 ++ ;
continue;
}
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_30 ( V_44 , F_31 ( V_47 ,
( unsigned long * ) & V_11 -> V_45 . V_46 ) ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_84 = V_11 -> V_45 . V_46 >> 1 ;
if ( V_84 != V_88 ) {
F_17 ( V_79 , V_13 , V_67 ,
L_9
L_10 , V_84 ) ;
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
F_34 ( struct V_92 * V_93 )
{
V_93 -> V_34 = NULL ;
return;
}
int
F_35 ( struct V_12 * V_13 , struct V_94 * * V_17 ,
struct V_16 * * V_95 )
{
* V_95 = F_36 ( sizeof( struct V_16 ) , V_96 ) ;
if ( * V_95 == NULL )
return - V_97 ;
( * V_95 ) -> V_98 = V_13 -> V_98 ;
* V_17 = & ( * V_95 ) -> V_81 ;
( * V_95 ) -> V_99 = V_100 ;
F_37 ( & ( * V_95 ) -> V_101 , V_102 ) ;
V_13 -> V_103 |= V_104 ;
return 0 ;
}
void
F_38 ( struct V_12 * V_13 , struct V_16 * V_95 )
{
struct V_105 * V_106 ;
T_6 V_107 ;
T_4 V_108 ;
char V_109 [ 32 ] , V_110 [ 16 ] ;
struct V_111 * V_98 = V_95 -> V_98 ;
F_39 ( V_95 -> V_99 == V_112 ) ;
V_95 -> V_113 = 1 ;
if ( V_95 -> V_99 == V_114 )
V_95 -> V_113 = 0 ;
V_95 -> V_99 = V_115 ;
V_106 = F_40 ( & V_95 -> V_81 ) ;
V_95 -> V_53 = V_106 -> V_53 ;
V_107 = F_41 ( & V_95 -> V_81 ) ;
V_108 = F_42 ( & V_95 -> V_81 ) ;
F_43 ( V_109 , V_107 ) ;
F_44 ( V_110 , V_108 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_11 ,
V_106 -> V_53 -> V_50 -> V_68 ,
V_110 , V_109 ) ;
if ( V_95 -> V_113 )
V_113 ( V_98 -> V_116 , & V_95 -> V_101 ) ;
}
void
F_45 ( struct V_16 * V_95 )
{
struct V_105 * V_106 ;
struct V_111 * V_98 = V_95 -> V_98 ;
V_95 -> V_74 = F_24 ( & V_95 -> V_81 ) ;
V_106 = F_40 ( & V_95 -> V_81 ) ;
V_95 -> V_99 = V_112 ;
V_95 -> V_113 = 1 ;
V_95 -> V_53 = V_106 -> V_53 ;
if ( V_95 -> V_113 )
V_113 ( V_98 -> V_116 , & V_95 -> V_101 ) ;
}
void
F_46 ( struct V_16 * V_95 )
{
struct V_105 * V_106 ;
struct V_12 * V_13 ;
struct V_111 * V_98 = V_95 -> V_98 ;
V_106 = F_40 ( & V_95 -> V_81 ) ;
V_13 = V_106 -> V_13 ;
if ( ( V_13 -> V_117 . V_58 & V_118 ) ||
( V_106 -> V_58 & V_118 ) ) {
V_95 -> V_99 = V_119 ;
return;
}
V_95 -> V_53 = V_106 -> V_53 ;
V_95 -> V_99 = V_114 ;
V_95 -> V_113 = 1 ;
if ( V_95 -> V_113 )
V_113 ( V_98 -> V_116 , & V_95 -> V_101 ) ;
}
int
F_47 ( struct V_12 * V_13 , struct V_52 * V_53 ,
struct V_31 * V_120 )
{
int error = 1 ;
F_48 ( & V_121 ) ;
error = F_49 ( & V_122 , V_53 , 0 , 0 , V_123 ) ;
if ( error < 0 ) {
F_50 ( & V_121 ) ;
F_51 ( V_124 L_12 ) ;
goto V_64;
}
V_53 -> V_125 = error ;
F_50 ( & V_121 ) ;
V_53 -> V_50 = F_52 ( V_53 , V_13 ) ;
if ( ! V_53 -> V_50 ) {
error = 1 ;
goto V_126;
}
V_53 -> V_50 -> V_34 [ 0 ] = ( unsigned long ) V_53 ;
V_53 -> V_50 -> V_127 = V_53 -> V_125 ;
V_53 -> V_50 -> V_128 = - 1 ;
V_53 -> V_50 -> V_129 = V_91 ;
V_53 -> V_50 -> V_130 = V_131 ;
V_53 -> V_50 -> V_132 = 16 ;
V_53 -> V_50 -> V_133 = V_13 -> V_134 . V_135 ;
if ( V_53 -> V_106 -> V_136 == V_137 )
V_53 -> V_50 -> V_138 = V_139 ;
else
V_53 -> V_50 -> V_138 =
V_140 ;
error = F_53 ( V_53 -> V_50 , V_120 , & V_13 -> V_141 -> V_120 ) ;
if ( error ) {
F_51 ( V_124 L_13 , error ) ;
goto V_142;
}
return 0 ;
V_142:
F_54 ( V_53 -> V_50 ) ;
V_53 -> V_50 = NULL ;
V_126:
F_48 ( & V_121 ) ;
F_55 ( & V_122 , V_53 -> V_125 ) ;
F_50 ( & V_121 ) ;
V_64:
return error ;
}
void
F_56 ( struct V_12 * V_13 , struct V_52 * V_53 )
{
F_2 ( V_13 , V_13 -> V_143 ) ;
F_17 ( V_66 , V_13 , V_67 , L_14 ,
V_53 -> V_50 -> V_68 ) ;
F_57 ( V_53 -> V_50 ) ;
F_58 ( V_53 -> V_50 ) ;
F_54 ( V_53 -> V_50 ) ;
F_48 ( & V_121 ) ;
F_55 ( & V_122 , V_53 -> V_125 ) ;
F_50 ( & V_121 ) ;
}
static void
F_59 ( struct V_144 * V_145 )
{
struct V_52 * V_53 =
F_60 ( V_145 , struct V_52 , V_146 ) ;
if ( V_53 -> V_106 -> V_136 != V_137 ) {
V_53 -> V_58 |= V_118 ;
F_61 ( V_53 -> V_147 ) ;
}
}
T_5
F_62 ( struct V_12 * V_13 , struct V_105 * V_106 )
{
int V_60 = V_75 ;
struct V_52 * V_53 ;
V_53 = F_36 ( sizeof( struct V_52 ) , V_96 ) ;
if ( V_53 == NULL ) {
V_60 = V_148 ;
goto V_149;
}
V_106 -> V_53 = V_53 ;
V_53 -> V_106 = V_106 ;
V_53 -> V_13 = V_13 ;
F_37 ( & V_53 -> V_146 , F_59 ) ;
F_63 ( & V_53 -> V_150 ) ;
F_63 ( & V_53 -> V_151 ) ;
V_149:
return V_60 ;
}
void
F_64 ( struct V_12 * V_13 , struct V_105 * V_106 )
{
struct V_52 * V_53 = V_106 -> V_53 ;
V_113 ( V_13 -> V_98 -> V_116 ,
& V_53 -> V_146 ) ;
}
void
F_65 ( struct V_52 * V_53 )
{
struct V_152 * V_153 , * V_154 ;
unsigned long V_58 ;
struct V_12 * V_13 = V_53 -> V_13 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
F_66 (bp, bp_new, &im_port->binding_list,
list_entry) {
F_67 ( & V_153 -> V_155 ) ;
F_68 ( V_153 ) ;
}
F_39 ( ! F_69 ( & V_53 -> V_150 ) ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
}
static void F_70 ( struct V_144 * V_145 )
{
struct V_111 * V_98 =
F_60 ( V_145 , struct V_111 , V_156 ) ;
struct V_157 * V_158 ;
struct V_12 * V_13 = V_98 -> V_13 ;
struct V_49 * V_50 = V_13 -> V_117 . V_53 -> V_50 ;
void * V_159 ;
unsigned long V_58 ;
while ( ! F_69 ( & V_13 -> V_160 ) ) {
F_16 ( & V_13 -> V_161 , V_58 ) ;
F_71 ( & V_13 -> V_160 , & V_158 ) ;
F_19 ( & V_13 -> V_161 , V_58 ) ;
V_159 = ( char * ) V_158 + sizeof( struct V_162 ) ;
F_72 ( V_50 , F_73 () ,
sizeof( struct V_157 ) -
sizeof( struct V_162 ) ,
( char * ) V_159 , V_163 ) ;
F_16 ( & V_13 -> V_161 , V_58 ) ;
F_74 ( & V_158 -> V_164 , & V_13 -> V_165 ) ;
F_19 ( & V_13 -> V_161 , V_58 ) ;
}
}
T_5
F_75 ( struct V_12 * V_13 )
{
struct V_111 * V_98 ;
V_98 = F_36 ( sizeof( struct V_111 ) , V_123 ) ;
if ( V_98 == NULL )
return V_148 ;
V_13 -> V_98 = V_98 ;
V_98 -> V_13 = V_13 ;
if ( F_76 ( V_13 ) != V_75 ) {
F_68 ( V_98 ) ;
return V_80 ;
}
F_37 ( & V_98 -> V_156 , F_70 ) ;
return V_75 ;
}
void
F_77 ( struct V_12 * V_13 )
{
if ( V_13 -> V_98 ) {
F_78 ( V_13 -> V_98 ) ;
F_68 ( V_13 -> V_98 ) ;
V_13 -> V_98 = NULL ;
}
}
struct V_49 *
F_52 ( struct V_52 * V_53 , struct V_12 * V_13 )
{
struct V_166 * V_167 ;
if ( V_53 -> V_106 -> V_136 == V_137 )
V_167 = & V_168 ;
else
V_167 = & V_169 ;
if ( V_170 != V_171 >> 1 )
V_167 -> V_172 = V_170 << 1 ;
V_167 -> V_173 = V_13 -> V_134 . V_174 ;
return F_79 ( V_167 , sizeof( unsigned long ) ) ;
}
void
F_80 ( struct V_12 * V_13 , struct V_52 * V_53 )
{
if ( ! ( V_53 -> V_58 & V_118 ) )
F_81 ( V_13 -> V_98 -> V_116 ) ;
F_56 ( V_53 -> V_13 , V_53 ) ;
F_65 ( V_53 ) ;
F_68 ( V_53 ) ;
}
void
F_78 ( struct V_111 * V_98 )
{
if ( V_98 && V_98 -> V_116 ) {
F_81 ( V_98 -> V_116 ) ;
F_82 ( V_98 -> V_116 ) ;
V_98 -> V_116 = NULL ;
}
}
T_5
F_76 ( struct V_12 * V_13 )
{
struct V_111 * V_98 = V_13 -> V_98 ;
F_2 ( V_13 , 0 ) ;
snprintf ( V_98 -> V_175 , V_176 , L_15 ,
V_13 -> V_143 ) ;
V_98 -> V_116 = F_83 ( V_98 -> V_175 ) ;
if ( ! V_98 -> V_116 )
return V_80 ;
return V_75 ;
}
static int
F_84 ( struct V_92 * V_93 )
{
F_85 ( V_93 , V_35 ) ;
return 0 ;
}
T_5
F_86 ( void )
{
V_139 =
F_87 ( & V_177 ) ;
if ( ! V_139 )
return V_148 ;
V_140 =
F_87 ( & V_178 ) ;
if ( ! V_140 ) {
F_88 ( V_139 ) ;
return V_148 ;
}
return V_75 ;
}
void
F_89 ( void )
{
if ( V_139 )
F_88 ( V_139 ) ;
if ( V_140 )
F_88 ( V_140 ) ;
F_90 ( & V_122 ) ;
}
void
F_7 ( struct V_16 * V_17 , struct V_92 * V_93 )
{
struct V_92 * V_179 ;
if ( ( ( V_180 - V_17 -> V_181 ) >
V_182 * V_70 ) &&
( ( V_180 - V_17 -> V_183 ) >
V_182 * V_70 ) ) {
F_91 (tmp_sdev, sdev->host) {
if ( V_35 > V_179 -> V_36 ) {
if ( V_179 -> V_184 != V_93 -> V_184 )
continue;
F_85 ( V_179 ,
V_179 -> V_36 + 1 ) ;
V_17 -> V_181 = V_180 ;
}
}
}
}
void
F_8 ( struct V_16 * V_17 , struct V_92 * V_93 )
{
struct V_92 * V_179 ;
V_17 -> V_183 = V_180 ;
F_91 (tmp_sdev, sdev->host) {
if ( V_179 -> V_184 != V_93 -> V_184 )
continue;
F_92 ( V_179 , V_179 -> V_36 - 1 ) ;
}
}
struct V_16 *
F_33 ( struct V_52 * V_53 , int V_184 )
{
struct V_16 * V_17 = NULL ;
F_93 (itnim, &im_port->itnim_mapped_list, list_entry) {
if ( V_184 == V_17 -> V_185 )
return V_17 ;
}
return NULL ;
}
static int
F_94 ( struct V_92 * V_93 ,
struct V_186 * V_187 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_187 -> V_188 ;
struct V_189 * V_78 = V_15 -> V_17 -> V_74 -> V_78 ;
struct V_190 * V_191 = V_15 -> V_17 -> V_74 -> V_187 ;
struct V_192 * V_193 = F_95 ( V_78 ) ;
int V_89 = 0 , V_194 = - V_195 ;
for ( V_89 = 0 ; V_89 < V_196 ; V_89 ++ ) {
if ( V_193 [ V_89 ] . V_99 == V_197 &&
F_96 ( & V_193 [ V_89 ] . V_85 ) == V_93 -> V_85 &&
V_193 [ V_89 ] . V_198 == V_191 -> V_199 &&
V_193 [ V_89 ] . V_200 == ( T_1 ) V_191 -> V_201 . V_200 ) {
V_194 = V_75 ;
break;
}
}
return V_194 ;
}
static int
F_97 ( struct V_92 * V_93 )
{
struct V_186 * V_187 = F_98 ( F_99 ( V_93 ) ) ;
struct V_14 * V_15 ;
struct V_189 * V_78 ;
if ( ! V_187 || F_100 ( V_187 ) )
return - V_195 ;
V_15 = (struct V_14 * ) V_187 -> V_188 ;
V_78 = V_15 -> V_17 -> V_74 -> V_78 ;
if ( F_101 ( V_78 ) == V_202 ) {
if ( V_93 -> V_85 == 0 ) {
V_93 -> V_203 |= V_204 |
V_205 ;
goto V_206;
}
if ( F_94 ( V_93 , V_187 ) !=
V_75 )
return - V_195 ;
}
V_206:
V_93 -> V_34 = V_187 -> V_188 ;
return 0 ;
}
T_4
F_102 ( struct V_189 * V_78 )
{
struct V_207 * V_208 ;
T_4 V_209 = 0 ;
V_208 = F_36 ( sizeof( struct V_207 ) , V_123 ) ;
if ( ! V_208 )
return 0 ;
F_103 ( & V_78 -> V_210 , V_208 ) ;
if ( V_208 -> V_211 . V_212 == V_213 )
V_209 |= V_214 | V_215 |
V_216 | V_217 ;
else if ( V_208 -> V_211 . V_212 == V_218 ) {
if ( V_208 -> V_211 . V_219 ) {
V_209 |= V_215 |
V_216 |
V_217 | V_220 ;
} else {
V_209 |= V_215 |
V_216 |
V_217 ;
}
} else if ( V_208 -> V_211 . V_212 == V_221 ) {
V_209 |= V_216 | V_217 |
V_220 ;
} else if ( V_208 -> V_211 . V_212 == V_222 ) {
V_209 |= V_223 ;
}
F_68 ( V_208 ) ;
return V_209 ;
}
void
F_104 ( struct V_52 * V_53 )
{
struct V_49 * V_32 = V_53 -> V_50 ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_105 * V_106 = V_53 -> V_106 ;
char V_224 [ V_225 ] ;
struct V_226 * V_227 = F_105 ( & V_13 -> V_78 ) ;
F_106 ( V_32 ) =
F_107 ( ( F_108 ( V_106 -> V_228 ) ) ) ;
F_109 ( V_32 ) =
F_107 ( ( F_110 ( V_106 -> V_228 ) ) ) ;
F_111 ( V_32 ) = F_112 ( & V_13 -> V_78 ) ;
F_113 ( V_32 ) = V_229 ;
memset ( F_114 ( V_32 ) , 0 ,
sizeof( F_114 ( V_32 ) ) ) ;
if ( V_230 & V_231 )
F_114 ( V_32 ) [ 2 ] = 1 ;
F_114 ( V_32 ) [ 7 ] = 1 ;
F_115 ( V_224 , V_13 -> V_232 . V_233 . V_234 . V_235 . V_236 . V_224 ,
V_225 ) ;
sprintf ( F_116 ( V_32 ) , L_16 , V_224 ) ;
F_117 ( V_32 ) = F_102 ( & V_13 -> V_78 ) ;
F_118 ( V_32 ) = V_227 -> V_237 . V_238 ;
}
static void
F_119 ( struct V_52 * V_53 , struct V_16 * V_17 )
{
struct V_239 V_240 ;
struct V_186 * V_186 ;
struct V_14 * V_15 ;
V_240 . V_241 =
F_107 ( F_120 ( & V_17 -> V_81 ) ) ;
V_240 . V_242 =
F_107 ( F_41 ( & V_17 -> V_81 ) ) ;
V_240 . V_243 =
F_121 ( F_42 ( & V_17 -> V_81 ) ) ;
V_240 . V_244 = V_245 ;
V_17 -> V_186 = V_186 =
F_122 ( V_53 -> V_50 , 0 , & V_240 ) ;
if ( ! V_186 )
return;
V_186 -> V_246 =
F_123 ( & V_17 -> V_81 ) ;
V_186 -> V_247 = F_124 ( & V_17 -> V_81 ) ;
V_15 = V_186 -> V_188 ;
V_15 -> V_17 = V_17 ;
V_240 . V_244 |= V_248 ;
if ( V_240 . V_244 != V_245 )
F_125 ( V_186 , V_240 . V_244 ) ;
if ( ( V_186 -> V_249 != - 1 )
&& ( V_186 -> V_249 < V_91 ) )
V_17 -> V_185 = V_186 -> V_249 ;
V_17 -> V_250 = V_186 -> V_250 ;
return;
}
static void
V_102 ( struct V_144 * V_145 )
{
struct V_16 * V_17 = F_60 ( V_145 , struct V_16 ,
V_101 ) ;
struct V_111 * V_98 = V_17 -> V_98 ;
struct V_12 * V_13 = V_98 -> V_13 ;
struct V_52 * V_53 ;
unsigned long V_58 ;
struct V_186 * V_186 ;
T_6 V_107 ;
T_4 V_108 ;
char V_109 [ 32 ] , V_110 [ 16 ] ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_53 = V_17 -> V_53 ;
F_2 ( V_13 , V_17 -> V_99 ) ;
switch ( V_17 -> V_99 ) {
case V_112 :
if ( ! V_17 -> V_186 ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_119 ( V_53 , V_17 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
V_107 = F_41 ( & V_17 -> V_81 ) ;
V_108 = F_42 ( & V_17 -> V_81 ) ;
F_43 ( V_109 , V_107 ) ;
F_44 ( V_110 , V_108 ) ;
F_74 ( & V_17 -> V_155 ,
& V_53 -> V_150 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_17
L_18 ,
V_53 -> V_50 -> V_68 ,
V_17 -> V_185 ,
V_110 , V_109 ) ;
} else {
F_51 ( V_124
L_19 ,
V_251 ,
F_41 ( & V_17 -> V_81 ) ) ;
}
break;
case V_114 :
V_17 -> V_99 = V_119 ;
if ( V_17 -> V_186 ) {
V_186 = V_17 -> V_186 ;
( (struct V_14 * )
V_186 -> V_188 ) -> V_17 = NULL ;
V_17 -> V_186 = NULL ;
if ( ! ( V_53 -> V_106 -> V_58 & V_118 ) ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_186 -> V_252 =
F_126 ( & V_13 -> V_78 ) + 1 ;
F_127 ( V_186 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
}
V_107 = F_41 ( & V_17 -> V_81 ) ;
V_108 = F_42 ( & V_17 -> V_81 ) ;
F_43 ( V_109 , V_107 ) ;
F_44 ( V_110 , V_108 ) ;
F_67 ( & V_17 -> V_155 ) ;
F_17 ( V_66 , V_13 , V_67 ,
L_20
L_18 ,
V_53 -> V_50 -> V_68 ,
V_17 -> V_185 ,
V_110 , V_109 ) ;
}
break;
case V_115 :
if ( V_17 -> V_186 ) {
V_186 = V_17 -> V_186 ;
( (struct V_14 * )
V_186 -> V_188 ) -> V_17 = NULL ;
V_17 -> V_186 = NULL ;
if ( ! ( V_53 -> V_106 -> V_58 & V_118 ) ) {
F_19 ( & V_13 -> V_62 , V_58 ) ;
V_186 -> V_252 =
F_126 ( & V_13 -> V_78 ) + 1 ;
F_127 ( V_186 ) ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
}
F_67 ( & V_17 -> V_155 ) ;
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
F_128 ( struct V_10 * V_11 , void (* V_206) ( struct V_10 * ) )
{
struct V_52 * V_53 =
(struct V_52 * ) V_11 -> V_31 -> V_32 -> V_34 [ 0 ] ;
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_31 -> V_34 ;
struct V_16 * V_17 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
int V_60 ;
int V_253 = 0 ;
struct V_186 * V_187 = F_98 ( F_99 ( V_11 -> V_31 ) ) ;
V_60 = F_100 ( V_187 ) ;
if ( V_60 ) {
V_11 -> V_26 = V_60 ;
V_206 ( V_11 ) ;
return 0 ;
}
if ( V_13 -> V_103 & V_254 ) {
if ( V_13 -> V_103 & V_255 )
V_11 -> V_26 = V_256 << 16 ;
else
V_11 -> V_26 = V_257 << 16 ;
V_206 ( V_11 ) ;
return 0 ;
}
V_253 = F_129 ( V_11 ) ;
if ( V_253 < 0 )
return V_258 ;
V_11 -> V_38 = V_206 ;
F_16 ( & V_13 -> V_62 , V_58 ) ;
if ( ! ( V_13 -> V_103 & V_259 ) ) {
F_51 ( V_124
L_21 ,
V_13 -> V_143 , V_11 , V_11 -> V_11 [ 0 ] ) ;
V_11 -> V_26 = F_5 ( V_256 , 0 ) ;
goto V_260;
}
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
V_11 -> V_26 = F_5 ( V_261 , 0 ) ;
goto V_260;
}
V_57 = F_130 ( & V_13 -> V_78 , (struct V_2 * ) V_11 ,
V_17 -> V_74 , V_253 ) ;
if ( ! V_57 ) {
F_51 ( V_124 L_22 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_6 ( V_11 ) ;
return V_258 ;
}
V_11 -> V_33 = ( char * ) V_57 ;
F_131 ( V_57 ) ;
F_19 ( & V_13 -> V_62 , V_58 ) ;
return 0 ;
V_260:
F_19 ( & V_13 -> V_62 , V_58 ) ;
F_6 ( V_11 ) ;
if ( V_206 )
V_206 ( V_11 ) ;
return 0 ;
}
