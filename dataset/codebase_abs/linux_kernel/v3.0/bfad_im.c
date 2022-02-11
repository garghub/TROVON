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
struct V_53 * V_54 = & V_13 -> V_54 ;
struct V_55 * V_56 = & V_54 -> V_56 ;
char V_57 [ V_58 ] ;
F_15 ( V_54 , V_57 ) ;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
if ( V_56 -> V_59 && ! V_56 -> V_60 )
snprintf ( V_50 , sizeof( V_50 ) ,
L_1 L_2 ,
V_57 , V_13 -> V_61 , V_62 ) ;
else
snprintf ( V_50 , sizeof( V_50 ) ,
L_3 L_2 ,
V_57 , V_13 -> V_61 , V_62 ) ;
return V_50 ;
}
static int
F_16 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_30 -> V_31 ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_63 * V_64 ;
unsigned long V_65 ;
T_4 V_66 ;
int V_67 = V_68 ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
V_64 = (struct V_63 * ) V_11 -> V_32 ;
if ( ! V_64 ) {
V_67 = V_70 ;
goto V_71;
}
if ( V_64 -> V_3 != (struct V_2 * ) V_11 ) {
V_67 = V_68 ;
goto V_71;
}
F_2 ( V_13 , V_64 -> V_72 ) ;
F_18 ( V_73 , V_13 , V_74 ,
L_4 ,
V_52 -> V_49 -> V_75 , V_11 , V_64 -> V_72 ) ;
( void ) F_19 ( V_64 ) ;
F_20 ( & V_13 -> V_69 , V_65 ) ;
V_66 = 10 ;
while ( (struct V_63 * ) V_11 -> V_32 == V_64 ) {
F_21 ( V_76 ) ;
F_22 ( V_66 ) ;
if ( V_66 < 4 * V_77 )
V_66 *= 2 ;
}
V_11 -> V_37 ( V_11 ) ;
F_2 ( V_13 , V_64 -> V_72 ) ;
F_18 ( V_73 , V_13 , V_74 ,
L_5 ,
V_52 -> V_49 -> V_75 , V_11 , V_64 -> V_72 ) ;
return V_70 ;
V_71:
F_20 ( & V_13 -> V_69 , V_65 ) ;
return V_67 ;
}
static T_5
F_23 ( struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_16 * V_17 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
T_5 V_67 = V_82 ;
struct V_83 V_84 ;
V_79 = F_24 ( & V_13 -> V_54 , (struct V_39 * ) V_11 ) ;
if ( ! V_79 ) {
F_18 ( V_85 , V_13 , V_74 ,
L_6 ) ;
V_67 = V_86 ;
goto V_71;
}
V_11 -> V_32 = NULL ;
V_11 -> V_44 . V_45 = 0 ;
V_81 = F_25 ( & V_17 -> V_87 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_26 ( V_79 , V_81 , V_84 ,
V_88 , V_89 ) ;
V_71:
return V_67 ;
}
static int
F_27 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_30 -> V_31 ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_14 * V_15 = V_11 -> V_30 -> V_33 ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_78 * V_79 ;
struct V_16 * V_17 ;
struct V_80 * V_81 ;
F_28 ( V_43 ) ;
int V_67 = V_70 ;
unsigned long V_65 ;
enum V_41 V_90 ;
struct V_83 V_84 ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
F_20 ( & V_13 -> V_69 , V_65 ) ;
V_67 = V_68 ;
goto V_71;
}
V_79 = F_24 ( & V_13 -> V_54 , (struct V_39 * ) V_11 ) ;
if ( ! V_79 ) {
F_18 ( V_85 , V_13 , V_74 ,
L_7 ) ;
F_20 ( & V_13 -> V_69 , V_65 ) ;
V_67 = V_68 ;
goto V_71;
}
V_11 -> V_32 = NULL ;
V_11 -> V_44 . V_47 = ( char * ) & V_43 ;
V_11 -> V_44 . V_45 = 0 ;
V_81 = F_25 ( & V_17 -> V_87 ) ;
F_29 ( V_11 -> V_30 -> V_91 , & V_84 ) ;
F_26 ( V_79 , V_81 , V_84 ,
V_92 , V_93 ) ;
F_20 ( & V_13 -> V_69 , V_65 ) ;
F_30 ( V_43 , F_31 ( V_46 ,
( unsigned long * ) & V_11 -> V_44 . V_45 ) ) ;
V_90 = V_11 -> V_44 . V_45 >> 1 ;
if ( V_90 != V_94 ) {
F_18 ( V_85 , V_13 , V_74 ,
L_8 , V_90 ) ;
V_67 = V_68 ;
}
V_71:
return V_67 ;
}
static int
F_32 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_11 -> V_30 -> V_31 ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_16 * V_17 ;
unsigned long V_65 ;
T_4 V_95 , V_67 , V_96 = 0 ;
F_28 ( V_43 ) ;
enum V_41 V_90 ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
V_17 = F_33 ( V_52 , V_95 ) ;
if ( V_17 ) {
V_11 -> V_44 . V_47 = ( char * ) & V_43 ;
V_67 = F_23 ( V_13 , V_11 , V_17 ) ;
if ( V_67 != V_82 ) {
V_96 ++ ;
continue;
}
F_20 ( & V_13 -> V_69 , V_65 ) ;
F_30 ( V_43 , F_31 ( V_46 ,
( unsigned long * ) & V_11 -> V_44 . V_45 ) ) ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
V_90 = V_11 -> V_44 . V_45 >> 1 ;
if ( V_90 != V_94 ) {
F_18 ( V_85 , V_13 , V_74 ,
L_9
L_10 , V_90 ) ;
V_96 ++ ;
}
}
}
F_20 ( & V_13 -> V_69 , V_65 ) ;
if ( V_96 )
return V_68 ;
return V_70 ;
}
static void
F_34 ( struct V_98 * V_99 )
{
V_99 -> V_33 = NULL ;
return;
}
void
F_35 ( struct V_12 * V_13 , struct V_100 * * V_17 ,
struct V_16 * * V_101 )
{
* V_101 = F_36 ( sizeof( struct V_16 ) , V_102 ) ;
if ( * V_101 == NULL )
return;
( * V_101 ) -> V_103 = V_13 -> V_103 ;
* V_17 = & ( * V_101 ) -> V_87 ;
( * V_101 ) -> V_104 = V_105 ;
F_37 ( & ( * V_101 ) -> V_106 , V_107 ) ;
V_13 -> V_108 |= V_109 ;
}
void
F_38 ( struct V_12 * V_13 , struct V_16 * V_101 )
{
struct V_110 * V_111 ;
T_6 V_112 ;
T_4 V_113 ;
char V_114 [ 32 ] , V_115 [ 16 ] ;
struct V_116 * V_103 = V_101 -> V_103 ;
F_39 ( V_101 -> V_104 == V_117 ) ;
V_101 -> V_118 = 1 ;
if ( V_101 -> V_104 == V_119 )
V_101 -> V_118 = 0 ;
V_101 -> V_104 = V_120 ;
V_111 = F_40 ( & V_101 -> V_87 ) ;
V_101 -> V_52 = V_111 -> V_52 ;
V_112 = F_41 ( & V_101 -> V_87 ) ;
V_113 = F_42 ( & V_101 -> V_87 ) ;
F_43 ( V_114 , V_112 ) ;
F_44 ( V_115 , V_113 ) ;
F_18 ( V_73 , V_13 , V_74 ,
L_11 ,
V_111 -> V_52 -> V_49 -> V_75 ,
V_115 , V_114 ) ;
if ( V_101 -> V_118 )
V_118 ( V_103 -> V_121 , & V_101 -> V_106 ) ;
}
void
F_45 ( struct V_16 * V_101 )
{
struct V_110 * V_111 ;
struct V_116 * V_103 = V_101 -> V_103 ;
V_101 -> V_81 = F_25 ( & V_101 -> V_87 ) ;
V_111 = F_40 ( & V_101 -> V_87 ) ;
V_101 -> V_104 = V_117 ;
V_101 -> V_118 = 1 ;
V_101 -> V_52 = V_111 -> V_52 ;
if ( V_101 -> V_118 )
V_118 ( V_103 -> V_121 , & V_101 -> V_106 ) ;
}
void
F_46 ( struct V_16 * V_101 )
{
struct V_110 * V_111 ;
struct V_12 * V_13 ;
struct V_116 * V_103 = V_101 -> V_103 ;
V_111 = F_40 ( & V_101 -> V_87 ) ;
V_13 = V_111 -> V_13 ;
if ( ( V_13 -> V_122 . V_65 & V_123 ) ||
( V_111 -> V_65 & V_123 ) ) {
V_101 -> V_104 = V_124 ;
return;
}
V_101 -> V_52 = V_111 -> V_52 ;
V_101 -> V_104 = V_119 ;
V_101 -> V_118 = 1 ;
if ( V_101 -> V_118 )
V_118 ( V_103 -> V_121 , & V_101 -> V_106 ) ;
}
int
F_47 ( struct V_12 * V_13 , struct V_51 * V_52 ,
struct V_30 * V_125 )
{
int error = 1 ;
F_48 ( & V_126 ) ;
if ( ! F_49 ( & V_127 , V_128 ) ) {
F_50 ( & V_126 ) ;
F_51 ( V_129 L_12 ) ;
goto V_71;
}
error = F_52 ( & V_127 , V_52 ,
& V_52 -> V_130 ) ;
if ( error ) {
F_50 ( & V_126 ) ;
F_51 ( V_129 L_13 ) ;
goto V_71;
}
F_50 ( & V_126 ) ;
V_52 -> V_49 = F_53 ( V_52 , V_13 ) ;
if ( ! V_52 -> V_49 ) {
error = 1 ;
goto V_131;
}
V_52 -> V_49 -> V_33 [ 0 ] = ( unsigned long ) V_52 ;
V_52 -> V_49 -> V_132 = V_52 -> V_130 ;
V_52 -> V_49 -> V_133 = - 1 ;
V_52 -> V_49 -> V_134 = V_97 ;
V_52 -> V_49 -> V_135 = V_136 ;
V_52 -> V_49 -> V_137 = 16 ;
V_52 -> V_49 -> V_138 = V_13 -> V_139 . V_140 ;
if ( V_52 -> V_111 -> V_141 == V_142 )
V_52 -> V_49 -> V_143 = V_144 ;
else
V_52 -> V_49 -> V_143 =
V_145 ;
error = F_54 ( V_52 -> V_49 , V_125 , & V_13 -> V_146 -> V_125 ) ;
if ( error ) {
F_51 ( V_129 L_14 , error ) ;
goto V_147;
}
F_55 ( V_52 ) ;
return 0 ;
V_147:
F_56 ( V_52 -> V_49 ) ;
V_52 -> V_49 = NULL ;
V_131:
F_48 ( & V_126 ) ;
F_57 ( & V_127 , V_52 -> V_130 ) ;
F_50 ( & V_126 ) ;
V_71:
return error ;
}
void
F_58 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
F_2 ( V_13 , V_13 -> V_148 ) ;
F_18 ( V_73 , V_13 , V_74 , L_15 ,
V_52 -> V_49 -> V_75 ) ;
F_59 ( V_52 -> V_49 ) ;
F_60 ( V_52 -> V_49 ) ;
F_56 ( V_52 -> V_49 ) ;
F_48 ( & V_126 ) ;
F_57 ( & V_127 , V_52 -> V_130 ) ;
F_50 ( & V_126 ) ;
}
static void
F_61 ( struct V_149 * V_150 )
{
struct V_51 * V_52 =
F_62 ( V_150 , struct V_51 , V_151 ) ;
if ( V_52 -> V_111 -> V_141 != V_142 ) {
V_52 -> V_65 |= V_123 ;
F_63 ( V_52 -> V_152 ) ;
}
}
T_5
F_64 ( struct V_12 * V_13 , struct V_110 * V_111 )
{
int V_67 = V_82 ;
struct V_51 * V_52 ;
V_52 = F_36 ( sizeof( struct V_51 ) , V_102 ) ;
if ( V_52 == NULL ) {
V_67 = V_153 ;
goto V_154;
}
V_111 -> V_52 = V_52 ;
V_52 -> V_111 = V_111 ;
V_52 -> V_13 = V_13 ;
F_37 ( & V_52 -> V_151 , F_61 ) ;
F_65 ( & V_52 -> V_155 ) ;
F_65 ( & V_52 -> V_156 ) ;
V_154:
return V_67 ;
}
void
F_66 ( struct V_12 * V_13 , struct V_110 * V_111 )
{
struct V_51 * V_52 = V_111 -> V_52 ;
V_118 ( V_13 -> V_103 -> V_121 ,
& V_52 -> V_151 ) ;
}
void
F_67 ( struct V_51 * V_52 )
{
struct V_157 * V_158 , * V_159 ;
unsigned long V_65 ;
struct V_12 * V_13 = V_52 -> V_13 ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
F_68 (bp, bp_new, &im_port->binding_list,
list_entry) {
F_69 ( & V_158 -> V_160 ) ;
F_70 ( V_158 ) ;
}
F_39 ( ! F_71 ( & V_52 -> V_155 ) ) ;
F_20 ( & V_13 -> V_69 , V_65 ) ;
}
T_5
F_72 ( struct V_12 * V_13 )
{
struct V_116 * V_103 ;
T_5 V_67 = V_82 ;
V_103 = F_36 ( sizeof( struct V_116 ) , V_128 ) ;
if ( V_103 == NULL ) {
V_67 = V_153 ;
goto V_154;
}
V_13 -> V_103 = V_103 ;
V_103 -> V_13 = V_13 ;
if ( F_73 ( V_13 ) != V_82 ) {
F_70 ( V_103 ) ;
V_67 = V_86 ;
}
V_154:
return V_67 ;
}
void
F_74 ( struct V_12 * V_13 )
{
if ( V_13 -> V_103 ) {
F_75 ( V_13 -> V_103 ) ;
F_70 ( V_13 -> V_103 ) ;
V_13 -> V_103 = NULL ;
}
}
struct V_48 *
F_53 ( struct V_51 * V_52 , struct V_12 * V_13 )
{
struct V_161 * V_162 ;
if ( V_52 -> V_111 -> V_141 == V_142 )
V_162 = & V_163 ;
else
V_162 = & V_164 ;
V_162 -> V_165 = V_13 -> V_139 . V_166 ;
return F_76 ( V_162 , sizeof( unsigned long ) ) ;
}
void
F_77 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
if ( ! ( V_52 -> V_65 & V_123 ) )
F_78 ( V_13 -> V_103 -> V_121 ) ;
F_58 ( V_52 -> V_13 , V_52 ) ;
F_67 ( V_52 ) ;
F_70 ( V_52 ) ;
}
void
F_75 ( struct V_116 * V_103 )
{
if ( V_103 && V_103 -> V_121 ) {
F_78 ( V_103 -> V_121 ) ;
F_79 ( V_103 -> V_121 ) ;
V_103 -> V_121 = NULL ;
}
}
T_5
F_73 ( struct V_12 * V_13 )
{
struct V_116 * V_103 = V_13 -> V_103 ;
F_2 ( V_13 , 0 ) ;
snprintf ( V_103 -> V_167 , V_168 , L_16 ,
V_13 -> V_148 ) ;
V_103 -> V_121 = F_80 ( V_103 -> V_167 ) ;
if ( ! V_103 -> V_121 )
return V_86 ;
return V_82 ;
}
static int
F_81 ( struct V_98 * V_99 )
{
if ( V_99 -> V_169 )
F_82 ( V_99 , V_34 ) ;
else
F_83 ( V_99 , V_34 ) ;
return 0 ;
}
T_5
F_84 ( void )
{
V_144 =
F_85 ( & V_170 ) ;
if ( ! V_144 )
return V_153 ;
V_145 =
F_85 ( & V_171 ) ;
if ( ! V_145 ) {
F_86 ( V_144 ) ;
return V_153 ;
}
return V_82 ;
}
void
F_87 ( void )
{
if ( V_144 )
F_86 ( V_144 ) ;
if ( V_145 )
F_86 ( V_145 ) ;
}
void
F_7 ( struct V_16 * V_17 , struct V_98 * V_99 )
{
struct V_98 * V_172 ;
if ( ( ( V_173 - V_17 -> V_174 ) >
V_175 * V_77 ) &&
( ( V_173 - V_17 -> V_176 ) >
V_175 * V_77 ) ) {
F_88 (tmp_sdev, sdev->host) {
if ( V_34 > V_172 -> V_35 ) {
if ( V_172 -> V_177 != V_99 -> V_177 )
continue;
if ( V_172 -> V_178 )
F_89 ( V_172 ,
V_179 ,
V_172 -> V_35 + 1 ) ;
else
F_89 ( V_172 ,
V_180 ,
V_172 -> V_35 + 1 ) ;
V_17 -> V_174 = V_173 ;
}
}
}
}
void
F_8 ( struct V_16 * V_17 , struct V_98 * V_99 )
{
struct V_98 * V_172 ;
V_17 -> V_176 = V_173 ;
F_88 (tmp_sdev, sdev->host) {
if ( V_172 -> V_177 != V_99 -> V_177 )
continue;
F_90 ( V_172 , V_172 -> V_35 - 1 ) ;
}
}
struct V_16 *
F_33 ( struct V_51 * V_52 , int V_177 )
{
struct V_16 * V_17 = NULL ;
F_91 (itnim, &im_port->itnim_mapped_list, list_entry) {
if ( V_177 == V_17 -> V_181 )
return V_17 ;
}
return NULL ;
}
static int
F_92 ( struct V_98 * V_99 )
{
struct V_182 * V_183 = F_93 ( F_94 ( V_99 ) ) ;
if ( ! V_183 || F_95 ( V_183 ) )
return - V_184 ;
V_99 -> V_33 = V_183 -> V_185 ;
return 0 ;
}
static T_4
F_96 ( struct V_53 * V_54 )
{
struct V_186 * V_187 ;
T_4 V_188 = 0 ;
V_187 = F_36 ( sizeof( struct V_186 ) , V_128 ) ;
if ( ! V_187 )
return 0 ;
F_97 ( & V_54 -> V_56 , V_187 ) ;
if ( V_187 -> V_189 . V_190 == V_191 ) {
if ( V_187 -> V_189 . V_192 ) {
V_188 |= V_193 |
V_194 |
V_195 | V_196 ;
} else {
V_188 |= V_193 |
V_194 |
V_195 ;
}
} else if ( V_187 -> V_189 . V_190 == V_197 ) {
V_188 |= V_194 | V_195 |
V_196 ;
} else if ( V_187 -> V_189 . V_190 == V_198 ) {
V_188 |= V_199 ;
}
F_70 ( V_187 ) ;
return V_188 ;
}
void
F_55 ( struct V_51 * V_52 )
{
struct V_48 * V_31 = V_52 -> V_49 ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_110 * V_111 = V_52 -> V_111 ;
char V_200 [ V_201 ] ;
struct V_202 * V_203 = F_98 ( & V_13 -> V_54 ) ;
F_99 ( V_31 ) =
F_100 ( ( F_101 ( V_111 -> V_204 ) ) ) ;
F_102 ( V_31 ) =
F_100 ( ( F_103 ( V_111 -> V_204 ) ) ) ;
F_104 ( V_31 ) = F_105 ( & V_13 -> V_54 ) ;
F_106 ( V_31 ) = V_205 ;
memset ( F_107 ( V_31 ) , 0 ,
sizeof( F_107 ( V_31 ) ) ) ;
if ( V_206 & V_207 )
F_107 ( V_31 ) [ 2 ] = 1 ;
F_107 ( V_31 ) [ 7 ] = 1 ;
strncpy ( V_200 , V_13 -> V_208 . V_209 . V_210 . V_211 . V_212 . V_200 ,
V_201 ) ;
sprintf ( F_108 ( V_31 ) , L_17 , V_200 ) ;
F_109 ( V_31 ) = F_96 ( & V_13 -> V_54 ) ;
F_110 ( V_31 ) = V_203 -> V_213 . V_214 ;
}
static void
F_111 ( struct V_51 * V_52 , struct V_16 * V_17 )
{
struct V_215 V_216 ;
struct V_182 * V_182 ;
struct V_14 * V_15 ;
V_216 . V_217 =
F_100 ( F_112 ( & V_17 -> V_87 ) ) ;
V_216 . V_218 =
F_100 ( F_41 ( & V_17 -> V_87 ) ) ;
V_216 . V_219 =
F_113 ( F_42 ( & V_17 -> V_87 ) ) ;
V_216 . V_220 = V_221 ;
V_17 -> V_182 = V_182 =
F_114 ( V_52 -> V_49 , 0 , & V_216 ) ;
if ( ! V_182 )
return;
V_182 -> V_222 =
F_115 ( & V_17 -> V_87 ) ;
V_182 -> V_223 = F_116 ( & V_17 -> V_87 ) ;
V_15 = V_182 -> V_185 ;
V_15 -> V_17 = V_17 ;
V_216 . V_220 |= V_224 ;
if ( V_216 . V_220 != V_221 )
F_117 ( V_182 , V_216 . V_220 ) ;
if ( ( V_182 -> V_225 != - 1 )
&& ( V_182 -> V_225 < V_97 ) )
V_17 -> V_181 = V_182 -> V_225 ;
return;
}
static void
V_107 ( struct V_149 * V_150 )
{
struct V_16 * V_17 = F_62 ( V_150 , struct V_16 ,
V_106 ) ;
struct V_116 * V_103 = V_17 -> V_103 ;
struct V_12 * V_13 = V_103 -> V_13 ;
struct V_51 * V_52 ;
unsigned long V_65 ;
struct V_182 * V_182 ;
T_6 V_112 ;
T_4 V_113 ;
char V_114 [ 32 ] , V_115 [ 16 ] ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
V_52 = V_17 -> V_52 ;
F_2 ( V_13 , V_17 -> V_104 ) ;
switch ( V_17 -> V_104 ) {
case V_117 :
if ( ! V_17 -> V_182 ) {
F_20 ( & V_13 -> V_69 , V_65 ) ;
F_111 ( V_52 , V_17 ) ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
V_112 = F_41 ( & V_17 -> V_87 ) ;
V_113 = F_42 ( & V_17 -> V_87 ) ;
F_43 ( V_114 , V_112 ) ;
F_44 ( V_115 , V_113 ) ;
F_118 ( & V_17 -> V_160 ,
& V_52 -> V_155 ) ;
F_18 ( V_73 , V_13 , V_74 ,
L_18
L_19 ,
V_52 -> V_49 -> V_75 ,
V_17 -> V_181 ,
V_115 , V_114 ) ;
} else {
F_51 ( V_129
L_20 ,
V_226 ,
F_41 ( & V_17 -> V_87 ) ) ;
}
break;
case V_119 :
V_17 -> V_104 = V_124 ;
if ( V_17 -> V_182 ) {
V_182 = V_17 -> V_182 ;
( (struct V_14 * )
V_182 -> V_185 ) -> V_17 = NULL ;
V_17 -> V_182 = NULL ;
if ( ! ( V_52 -> V_111 -> V_65 & V_123 ) ) {
F_20 ( & V_13 -> V_69 , V_65 ) ;
V_182 -> V_227 =
F_119 ( & V_13 -> V_54 ) + 1 ;
F_120 ( V_182 ) ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
}
V_112 = F_41 ( & V_17 -> V_87 ) ;
V_113 = F_42 ( & V_17 -> V_87 ) ;
F_43 ( V_114 , V_112 ) ;
F_44 ( V_115 , V_113 ) ;
F_69 ( & V_17 -> V_160 ) ;
F_18 ( V_73 , V_13 , V_74 ,
L_21
L_19 ,
V_52 -> V_49 -> V_75 ,
V_17 -> V_181 ,
V_115 , V_114 ) ;
}
break;
case V_120 :
if ( V_17 -> V_182 ) {
V_182 = V_17 -> V_182 ;
( (struct V_14 * )
V_182 -> V_185 ) -> V_17 = NULL ;
V_17 -> V_182 = NULL ;
if ( ! ( V_52 -> V_111 -> V_65 & V_123 ) ) {
F_20 ( & V_13 -> V_69 , V_65 ) ;
V_182 -> V_227 =
F_119 ( & V_13 -> V_54 ) + 1 ;
F_120 ( V_182 ) ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
}
F_69 ( & V_17 -> V_160 ) ;
}
F_70 ( V_17 ) ;
break;
default:
F_39 ( 1 ) ;
break;
}
F_20 ( & V_13 -> V_69 , V_65 ) ;
}
static int
F_121 ( struct V_10 * V_11 , void (* F_122) ( struct V_10 * ) )
{
struct V_51 * V_52 =
(struct V_51 * ) V_11 -> V_30 -> V_31 -> V_33 [ 0 ] ;
struct V_12 * V_13 = V_52 -> V_13 ;
struct V_14 * V_15 = V_11 -> V_30 -> V_33 ;
struct V_16 * V_17 ;
struct V_63 * V_64 ;
unsigned long V_65 ;
int V_67 ;
int V_228 = 0 ;
struct V_182 * V_183 = F_93 ( F_94 ( V_11 -> V_30 ) ) ;
V_67 = F_95 ( V_183 ) ;
if ( V_67 ) {
V_11 -> V_26 = V_67 ;
F_122 ( V_11 ) ;
return 0 ;
}
V_228 = F_123 ( V_11 ) ;
if ( V_228 < 0 )
return V_229 ;
V_11 -> V_37 = F_122 ;
F_17 ( & V_13 -> V_69 , V_65 ) ;
if ( ! ( V_13 -> V_108 & V_230 ) ) {
F_51 ( V_129
L_22 ,
V_13 -> V_148 , V_11 , V_11 -> V_11 [ 0 ] ) ;
V_11 -> V_26 = F_5 ( V_231 , 0 ) ;
goto V_232;
}
V_17 = V_15 -> V_17 ;
if ( ! V_17 ) {
V_11 -> V_26 = F_5 ( V_233 , 0 ) ;
goto V_232;
}
V_64 = F_124 ( & V_13 -> V_54 , (struct V_2 * ) V_11 ,
V_17 -> V_81 , V_228 ) ;
if ( ! V_64 ) {
F_51 ( V_129 L_23 ) ;
F_20 ( & V_13 -> V_69 , V_65 ) ;
F_6 ( V_11 ) ;
return V_229 ;
}
V_11 -> V_32 = ( char * ) V_64 ;
F_125 ( V_64 ) ;
F_20 ( & V_13 -> V_69 , V_65 ) ;
return 0 ;
V_232:
F_20 ( & V_13 -> V_69 , V_65 ) ;
F_6 ( V_11 ) ;
if ( F_122 )
F_122 ( V_11 ) ;
return 0 ;
}
