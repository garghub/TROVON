static int
F_1 ( struct V_1 * V_2 , char V_3 , void * V_4 )
{
unsigned long V_5 ;
int V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
V_6 = V_2 -> V_8 ;
while ( V_2 -> V_9 [ V_6 ] . V_10 ) {
V_6 = ( V_6 + 1 ) % V_11 ;
if ( V_6 == ( int ) V_2 -> V_8 ) {
F_3 ( & V_2 -> V_7 , V_5 ) ;
return - 1 ;
}
}
V_2 -> V_9 [ V_6 ] . V_3 = V_3 ;
V_2 -> V_9 [ V_6 ] . V_10 = V_4 ;
V_2 -> V_8 = ( V_6 + 1 ) % V_11 ;
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static unsigned int
F_4 ( struct V_1 * V_2 , char V_3 ,
void * V_4 )
{
int V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
while ( V_6 == - 1 ) {
F_5 ( V_12 ) ;
F_6 ( F_7 ( 10 ) ) ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
}
return ( unsigned int ) V_6 ;
}
static void *
F_8 ( struct V_1 * V_2 , T_1 V_13 )
{
unsigned long V_5 ;
void * V_10 = NULL ;
if ( V_13 < V_11 ) {
F_2 ( & V_2 -> V_7 , V_5 ) ;
V_10 = V_2 -> V_9 [ V_13 ] . V_10 ;
V_2 -> V_9 [ V_13 ] . V_3 = 0 ;
V_2 -> V_9 [ V_13 ] . V_10 = NULL ;
F_3 ( & V_2 -> V_7 , V_5 ) ;
}
return V_10 ;
}
static inline void
F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int error ;
V_17 = F_10 ( V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 , V_15 -> V_21 ) ;
if ( V_17 ) {
if ( ! ( V_15 -> V_22 ) )
F_11 ( V_17 ) ;
} else if ( V_15 -> V_22 ) {
error =
F_12 ( V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 ,
V_15 -> V_21 ) ;
}
F_13 ( V_15 ) ;
}
static void
F_14 ( struct V_23 * V_24 )
{
struct V_14 * V_15 ;
struct V_14 * V_25 ;
int V_26 = 0 ;
unsigned long V_5 ;
F_2 ( & V_27 , V_5 ) ;
V_25 = V_28 ;
V_28 = NULL ;
V_29 = 0 ;
F_3 ( & V_27 , V_5 ) ;
while ( V_25 ) {
V_15 = V_25 ;
V_25 = V_15 -> V_30 ;
F_9 ( V_15 ) ;
V_26 ++ ;
}
}
static void
F_15 ( struct V_31 * V_18 , struct V_32 * V_33 )
{
struct V_14 * V_15 ;
unsigned long V_5 ;
V_15 = F_16 ( sizeof( * V_15 ) , V_34 ) ;
if ( V_15 ) {
V_15 -> V_22 = V_33 -> V_35 . V_22 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_33 -> V_35 . V_19 ;
V_15 -> V_20 = V_33 -> V_35 . V_20 ;
V_15 -> V_21 = V_33 -> V_35 . V_21 ;
F_17 ( V_15 ) ;
}
}
static T_2
F_18 ( int V_36 , void * V_37 )
{
struct V_1 * V_38 = (struct V_1 * ) V_37 ;
struct V_39 T_3 * V_39 ;
struct V_40 T_3 * V_41 ;
T_4 V_42 ;
unsigned long long V_43 ;
if ( ! V_38 )
return V_44 ;
V_38 -> V_45 ++ ;
V_39 = V_38 -> V_46 . V_47 -> V_48 ;
if ( ( ( F_19 ( & V_39 -> V_49 )
& V_50 ) != 0 ) &&
( ( F_19 ( & V_39 -> V_49 ) &
V_51 ) !=
0 ) ) {
V_38 -> V_52 ++ ;
V_42 = ~ V_53 ;
V_43 = F_20 ( V_38 -> V_54 , V_42 ) ;
}
if ( F_21 ( V_39 , V_55 ) ) {
V_38 -> V_56 ++ ;
return V_44 ;
}
V_41 = (struct V_40 T_3 * )
( ( char T_3 * ) V_39 +
F_19 ( & V_39 -> V_57 ) ) + V_55 ;
F_22 ( F_19 ( & V_41 -> V_58 ) + 1 ,
& V_41 -> V_58 ) ;
F_23 ( & V_38 -> V_59 , 1 ) ;
F_24 ( & V_38 -> V_60 ) ;
return V_61 ;
}
static int
F_25 ( struct V_62 * V_63 , const struct V_64 * V_20 )
{
int error ;
struct V_31 * V_65 ;
struct V_1 * V_38 ;
int V_66 ;
int V_26 ;
T_5 V_67 = F_18 ;
struct V_39 T_3 * V_39 ;
struct V_40 T_3 * V_41 ;
T_4 V_42 ;
F_26 ( V_68 , V_69 ) ;
V_65 = F_27 ( & V_70 ,
sizeof( struct V_1 ) ) ;
if ( ! V_65 )
return - V_71 ;
V_65 -> V_72 = V_73 ;
V_65 -> V_74 = ( unsigned ) V_63 -> V_75 . V_76 . V_74 ;
V_65 -> V_77 = ( unsigned ) V_63 -> V_75 . V_76 . V_77 ;
V_65 -> V_78 = ( unsigned ) V_63 -> V_75 . V_76 . V_78 ;
V_65 -> V_79 = ( unsigned ) V_63 -> V_75 . V_76 . V_79 ;
V_65 -> V_80 =
( unsigned short ) ( V_63 -> V_75 . V_76 . V_81 >> 9 ) ;
V_65 -> V_82 =
( unsigned short ) ( V_63 -> V_75 . V_76 . V_81 / V_83 ) ;
if ( V_65 -> V_82 > V_84 )
V_65 -> V_82 = V_84 ;
error = F_28 ( V_65 , & V_63 -> V_85 ) ;
if ( error ) {
F_26 ( V_86 , V_87 ) ;
F_29 ( V_65 ) ;
return - V_71 ;
}
V_38 = (struct V_1 * ) V_65 -> V_88 ;
memset ( V_38 , 0 , sizeof( struct V_1 ) ) ;
for ( V_26 = 0 ; V_26 < V_89 ; V_26 ++ ) {
if ( ! V_90 [ V_26 ] . V_38 ) {
V_90 [ V_26 ] . V_38 = V_38 ;
break;
}
}
V_38 -> V_91 = - 1 ;
V_38 -> V_46 . V_47 = & V_63 -> V_47 ;
V_38 -> V_63 = V_63 ;
F_30 ( & V_38 -> V_46 . V_92 ) ;
F_31 ( & V_38 -> V_60 ) ;
F_30 ( & V_38 -> V_7 ) ;
memset ( & V_38 -> V_9 , 0 , sizeof( V_38 -> V_9 ) ) ;
V_38 -> V_93 = false ;
V_38 -> V_94 = false ;
V_38 -> V_95 = V_63 -> V_95 ;
V_38 -> V_65 = V_65 ;
V_63 -> V_75 . V_65 = V_65 ;
F_32 ( & V_38 -> V_96 ,
V_97 ) ;
F_22 ( F_19 ( & V_38 -> V_46 . V_47 -> V_48 -> V_49 ) |
V_98 ,
& V_38 -> V_46 . V_47 -> V_48 -> V_49 ) ;
V_39 = V_38 -> V_46 . V_47 -> V_48 ;
V_41 = (struct V_40 T_3 * )
( ( char T_3 * ) V_39 +
F_19 ( & V_39 -> V_57 ) ) + V_55 ;
V_38 -> V_54 = & V_41 -> V_49 ;
if ( ! F_33 ( & V_38 -> V_46 . V_99 ,
V_100 ,
V_38 , L_1 ) ) {
F_26 ( V_86 , V_87 ) ;
F_29 ( V_65 ) ;
return - V_71 ;
}
V_38 -> V_91 =
V_38 -> V_95 . V_101 & V_102 ;
V_66 = F_34 ( V_38 -> V_91 , V_67 , V_103 ,
V_65 -> V_104 -> V_105 , V_38 ) ;
if ( V_66 != 0 ) {
V_38 -> V_91 = - 1 ;
F_26 ( V_86 , V_87 ) ;
} else {
T_4 T_3 * V_106 =
& V_38 -> V_46 . V_47 -> V_48 -> V_49 ;
V_42 = ~ ( V_98 |
V_51 ) ;
F_20 ( V_106 , V_42 ) ;
V_42 = V_107 ;
F_35 ( V_106 , V_42 ) ;
V_108 = 4000000 ;
}
F_36 ( V_65 ) ;
F_26 ( V_109 , V_69 ) ;
return 0 ;
}
static void
F_37 ( struct V_62 * V_63 )
{
struct V_1 * V_38 ;
struct V_31 * V_65 =
(struct V_31 * ) V_63 -> V_75 . V_65 ;
V_38 = (struct V_1 * ) V_65 -> V_88 ;
if ( V_38 -> V_91 != - 1 )
F_38 ( V_38 -> V_91 , V_38 ) ;
F_39 ( V_65 ) ;
F_40 ( & V_38 -> V_46 . V_99 ) ;
F_29 ( V_65 ) ;
}
static int
F_41 ( enum V_110 V_111 ,
struct V_31 * V_65 ,
struct V_112 * V_113 )
{
struct V_32 * V_33 ;
struct V_1 * V_38 =
(struct V_1 * ) V_65 -> V_88 ;
int V_114 = 0xffff ;
T_6 V_115 ;
if ( V_38 -> V_93 || V_38 -> V_94 )
return V_116 ;
V_33 = F_16 ( V_117 , V_34 ) ;
if ( ! V_33 )
return V_116 ;
F_31 ( & V_115 ) ;
V_33 -> V_3 = V_118 ;
V_33 -> V_119 . V_120 = ( void * ) & V_115 ;
V_33 -> V_119 . V_114 = ( void * ) & V_114 ;
V_33 -> V_119 . V_121 = V_111 ;
V_33 -> V_119 . V_113 . V_19 = V_113 -> V_19 ;
V_33 -> V_119 . V_113 . V_20 = V_113 -> V_20 ;
V_33 -> V_119 . V_113 . V_21 = V_113 -> V_21 ;
V_33 -> V_119 . V_122 =
( void * ) ( T_1 )
F_4 ( V_38 , V_118 ,
( void * ) V_33 ) ;
F_42 ( V_38 -> V_46 . V_47 ,
V_33 , V_123 ,
& V_38 -> V_46 . V_92 ,
V_124 , ( T_4 ) NULL ,
V_125 , L_2 ) ;
F_43 ( V_115 , V_114 != 0xffff ) ;
F_13 ( V_33 ) ;
return V_126 ;
}
static int
F_44 ( enum V_127 V_128 ,
struct V_16 * V_129 )
{
struct V_32 * V_33 ;
struct V_1 * V_38 =
(struct V_1 * ) V_129 -> V_130 -> V_88 ;
int V_114 = 0xffff ;
T_6 V_115 ;
if ( V_38 -> V_93 || V_38 -> V_94 )
return V_116 ;
V_33 = F_16 ( V_117 , V_34 ) ;
if ( ! V_33 )
return V_116 ;
F_31 ( & V_115 ) ;
V_33 -> V_3 = V_131 ;
V_33 -> V_132 . V_120 = ( void * ) & V_115 ;
V_33 -> V_132 . V_114 = ( void * ) & V_114 ;
V_33 -> V_132 . V_128 = V_128 ;
V_33 -> V_132 . V_113 . V_19 = V_129 -> V_19 ;
V_33 -> V_132 . V_113 . V_20 = V_129 -> V_20 ;
V_33 -> V_132 . V_113 . V_21 = V_129 -> V_21 ;
V_33 -> V_132 . V_122 =
( void * ) ( T_1 )
F_4 ( V_38 ,
V_131 ,
( void * ) V_33 ) ;
F_42 ( V_38 -> V_46 . V_47 ,
V_33 , V_123 ,
& V_38 -> V_46 . V_92 ,
V_124 , ( T_4 ) NULL ,
V_125 , L_2 ) ;
F_43 ( V_115 , V_114 != 0xffff ) ;
F_13 ( V_33 ) ;
return V_126 ;
}
static int
F_45 ( struct V_133 * V_122 )
{
struct V_16 * V_129 ;
struct V_134 * V_135 ;
V_129 = V_122 -> V_136 ;
for ( V_135 = & ( (struct V_1 * ) V_129 -> V_130 -> V_88 ) -> V_137 ;
V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( ( V_129 -> V_19 == V_135 -> V_19 ) &&
( V_129 -> V_20 == V_135 -> V_20 ) &&
( V_129 -> V_21 == V_135 -> V_21 ) ) {
if ( F_46 ( & V_135 -> V_138 ) <
V_139 ) {
F_47 ( & V_135 -> V_138 ) ;
F_26 ( V_140 ,
V_69 ) ;
} else
F_23 ( & V_135 -> V_141 ,
V_142 ) ;
}
}
return F_44 ( V_143 , V_122 -> V_136 ) ;
}
static int
F_48 ( struct V_133 * V_122 )
{
struct V_16 * V_129 ;
struct V_134 * V_135 ;
V_129 = V_122 -> V_136 ;
for ( V_135 = & ( (struct V_1 * ) V_129 -> V_130 -> V_88 ) -> V_137 ;
V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( ( V_129 -> V_19 == V_135 -> V_19 ) &&
( V_129 -> V_20 == V_135 -> V_20 ) &&
( V_129 -> V_21 == V_135 -> V_21 ) ) {
if ( F_46 ( & V_135 -> V_138 ) <
V_139 ) {
F_47 ( & V_135 -> V_138 ) ;
F_26 ( V_140 ,
V_69 ) ;
} else
F_23 ( & V_135 -> V_141 ,
V_142 ) ;
}
}
return F_44 ( V_144 , V_122 -> V_136 ) ;
}
static int
F_49 ( struct V_133 * V_122 )
{
struct V_16 * V_129 ;
struct V_134 * V_135 ;
V_129 = V_122 -> V_136 ;
for ( V_135 = & ( (struct V_1 * ) V_129 -> V_130 -> V_88 ) -> V_137 ;
V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( ( V_129 -> V_19 == V_135 -> V_19 ) &&
( V_129 -> V_20 == V_135 -> V_20 ) &&
( V_129 -> V_21 == V_135 -> V_21 ) ) {
if ( F_46 ( & V_135 -> V_138 ) <
V_139 ) {
F_47 ( & V_135 -> V_138 ) ;
F_26 ( V_140 ,
V_69 ) ;
} else
F_23 ( & V_135 -> V_141 ,
V_142 ) ;
}
}
return F_44 ( V_145 , V_122 -> V_136 ) ;
}
static int
F_50 ( struct V_133 * V_122 )
{
return V_126 ;
}
static const char *
F_51 ( struct V_31 * V_146 )
{
sprintf ( V_147 , L_3 , V_148 ) ;
return V_147 ;
}
static int
F_52 ( struct V_16 * V_149 , int V_150 , void T_7 * V_151 )
{
return - V_152 ;
}
static int
F_53 ( struct V_133 * V_122 ,
void (* F_54)( struct V_133 * ) )
{
struct V_16 * V_129 = V_122 -> V_136 ;
int V_6 ;
unsigned char V_153 ;
unsigned char * V_154 = V_122 -> V_155 ;
struct V_31 * V_65 = V_129 -> V_130 ;
struct V_32 * V_33 ;
unsigned int V_26 ;
struct V_1 * V_38 =
(struct V_1 * ) V_65 -> V_88 ;
struct V_156 * V_157 = NULL ;
struct V_156 * V_158 = NULL ;
int V_159 = 0 ;
if ( V_38 -> V_93 || V_38 -> V_94 )
return V_160 ;
V_33 = F_16 ( V_117 , V_34 ) ;
if ( ! V_33 )
return 1 ;
V_33 -> V_3 = V_161 ;
V_6 =
F_1 ( V_38 , V_161 , ( void * ) V_122 ) ;
if ( V_6 != - 1 ) {
V_33 -> V_75 . V_122 = ( void * ) ( T_1 ) V_6 ;
} else {
F_13 ( V_33 ) ;
return V_160 ;
}
V_122 -> V_162 = F_54 ;
V_33 -> V_75 . V_113 . V_19 = V_129 -> V_19 ;
V_33 -> V_75 . V_113 . V_20 = V_129 -> V_20 ;
V_33 -> V_75 . V_113 . V_21 = V_129 -> V_21 ;
V_33 -> V_75 . V_163 = V_122 -> V_164 ;
memcpy ( V_33 -> V_75 . V_155 , V_154 , V_165 ) ;
V_33 -> V_75 . V_166 = F_55 ( V_122 ) ;
if ( V_33 -> V_75 . V_166 > V_167 )
V_167 = V_33 -> V_75 . V_166 ;
if ( F_56 ( V_122 ) > V_84 ) {
F_8 ( V_38 , ( T_1 ) V_6 ) ;
F_13 ( V_33 ) ;
return 1 ;
}
if ( F_56 ( V_122 ) == 0 ) {
if ( F_55 ( V_122 ) > 0 ) {
F_57 ( F_56 ( V_122 ) == 0 ) ;
}
} else {
V_158 = F_58 ( V_122 ) ;
F_59 (sgl, sg, scsi_sg_count(scsicmd), i) {
V_33 -> V_75 . V_168 [ V_26 ] . V_169 = F_60 ( V_157 ) ;
V_33 -> V_75 . V_168 [ V_26 ] . V_170 = V_157 -> V_170 ;
}
if ( V_159 ) {
}
V_33 -> V_75 . V_171 = F_56 ( V_122 ) ;
}
V_153 = V_154 [ 0 ] ;
V_26 = F_42 ( V_38 -> V_46 . V_47 ,
V_33 , V_123 ,
& V_38 -> V_46 .
V_92 ,
V_124 ,
( T_4 ) NULL , V_172 , L_2 ) ;
if ( V_26 == 0 ) {
F_13 ( V_33 ) ;
F_8 ( V_38 , ( T_1 ) V_6 ) ;
return V_160 ;
}
F_13 ( V_33 ) ;
return 0 ;
}
static int
F_61 ( struct V_16 * V_129 )
{
struct V_134 * V_135 ;
struct V_134 * V_173 ;
struct V_1 * V_38 ;
struct V_31 * V_65 = (struct V_31 * ) V_129 -> V_130 ;
V_38 = (struct V_1 * ) V_65 -> V_88 ;
if ( ! V_38 )
return 0 ;
for ( V_135 = & V_38 -> V_137 ; V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( V_135 -> V_30 -> V_174 &&
( V_135 -> V_30 -> V_19 == V_129 -> V_19 ) &&
( V_135 -> V_30 -> V_20 == V_129 -> V_20 ) &&
( V_135 -> V_30 -> V_21 == V_129 -> V_21 ) )
return 0 ;
}
V_173 = F_16 ( sizeof( * V_173 ) , V_34 ) ;
if ( ! V_173 )
return 0 ;
V_173 -> V_19 = V_129 -> V_19 ;
V_173 -> V_20 = V_129 -> V_20 ;
V_173 -> V_21 = V_129 -> V_21 ;
V_173 -> V_174 = 1 ;
V_135 -> V_30 = V_173 ;
return 0 ;
}
static int
F_62 ( struct V_16 * V_129 )
{
return 0 ;
}
static void
F_63 ( struct V_16 * V_129 )
{
struct V_134 * V_135 , * V_175 ;
struct V_1 * V_38 ;
struct V_31 * V_65 = (struct V_31 * ) V_129 -> V_130 ;
V_38 = (struct V_1 * ) V_65 -> V_88 ;
for ( V_135 = & V_38 -> V_137 ; V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( V_135 -> V_30 -> V_174 &&
( V_135 -> V_30 -> V_19 == V_129 -> V_19 ) &&
( V_135 -> V_30 -> V_20 == V_129 -> V_20 ) &&
( V_135 -> V_30 -> V_21 == V_129 -> V_21 ) ) {
V_175 = V_135 -> V_30 ;
V_135 -> V_30 = V_135 -> V_30 -> V_30 ;
F_13 ( V_175 ) ;
return;
}
}
}
static void
F_64 ( struct V_32 * V_33 , struct V_133 * V_122 )
{
struct V_134 * V_135 ;
struct V_16 * V_129 ;
struct V_176 * V_177 ;
V_129 = V_122 -> V_136 ;
memcpy ( V_122 -> V_178 , V_33 -> V_75 . V_179 , V_180 ) ;
V_177 = (struct V_176 * ) V_122 -> V_178 ;
if ( ( V_33 -> V_75 . V_155 [ 0 ] == V_181 ) &&
( F_65 ( V_33 -> V_75 . V_182 ) == V_183 ) &&
( V_33 -> V_75 . V_184 == V_185 ) )
return;
for ( V_135 = & ( (struct V_1 * ) V_129 -> V_130 -> V_88 ) -> V_137 ;
V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( ( V_129 -> V_19 != V_135 -> V_19 ) ||
( V_129 -> V_20 != V_135 -> V_20 ) ||
( V_129 -> V_21 != V_135 -> V_21 ) )
continue;
if ( F_46 ( & V_135 -> V_138 ) < V_139 ) {
F_47 ( & V_135 -> V_138 ) ;
F_23 ( & V_135 -> V_141 , V_142 ) ;
}
}
}
static void
F_66 ( struct V_32 * V_33 , struct V_133 * V_122 )
{
struct V_16 * V_129 ;
unsigned char V_186 [ 36 ] ;
struct V_156 * V_157 ;
unsigned int V_26 ;
char * V_187 ;
char * V_188 ;
int V_189 = 0 ;
struct V_134 * V_135 ;
V_129 = V_122 -> V_136 ;
if ( ( V_33 -> V_75 . V_155 [ 0 ] == V_181 ) &&
( V_33 -> V_75 . V_166 >= V_190 ) ) {
if ( V_33 -> V_75 . V_191 == 0 )
return;
F_67 ( V_186 , V_33 -> V_75 . V_166 ,
V_129 -> V_21 ,
V_192 ,
V_193 ) ;
if ( F_56 ( V_122 ) == 0 ) {
if ( F_55 ( V_122 ) > 0 ) {
F_57 ( F_56 ( V_122 ) ==
0 ) ;
}
memcpy ( F_58 ( V_122 ) , V_186 ,
V_33 -> V_75 . V_166 ) ;
return;
}
V_157 = F_58 ( V_122 ) ;
for ( V_26 = 0 ; V_26 < F_56 ( V_122 ) ; V_26 ++ ) {
V_188 = F_68 ( F_69 ( V_157 + V_26 ) ) ;
V_187 = ( void * ) ( ( unsigned long ) V_188 |
V_157 [ V_26 ] . V_194 ) ;
memcpy ( V_187 , V_186 + V_189 , V_157 [ V_26 ] . V_170 ) ;
F_70 ( V_188 ) ;
V_189 += V_157 [ V_26 ] . V_170 ;
}
} else {
V_135 = & ( (struct V_1 * ) V_129 -> V_130 -> V_88 ) -> V_137 ;
for ( ; V_135 -> V_30 ; V_135 = V_135 -> V_30 ) {
if ( ( V_129 -> V_19 != V_135 -> V_19 ) ||
( V_129 -> V_20 != V_135 -> V_20 ) ||
( V_129 -> V_21 != V_135 -> V_21 ) )
continue;
if ( F_46 ( & V_135 -> V_141 ) > 0 ) {
F_71 ( & V_135 -> V_141 ) ;
if ( F_46 ( & V_135 -> V_141 ) == 0 ) {
F_23 ( & V_135 -> V_138 , 0 ) ;
}
}
}
}
}
static void
F_72 ( struct V_32 * V_33 , struct V_133 * V_122 )
{
V_122 -> V_195 = V_33 -> V_75 . V_182 ;
if ( V_33 -> V_75 . V_182 )
F_64 ( V_33 , V_122 ) ;
else
F_66 ( V_33 , V_122 ) ;
if ( V_122 -> V_162 )
V_122 -> V_162 ( V_122 ) ;
}
static inline void
F_73 ( struct V_32 * V_33 )
{
* ( int * ) V_33 -> V_119 . V_114 = V_33 -> V_119 . V_195 ;
F_74 ( ( T_6 * ) V_33 -> V_119 . V_120 ) ;
}
static inline void
F_75 ( struct V_32 * V_33 )
{
* ( int * ) V_33 -> V_132 . V_114 =
V_33 -> V_132 . V_195 ;
F_74 ( ( T_6 * ) V_33 -> V_132 . V_120 ) ;
}
static void
F_76 ( struct V_1 * V_38 , struct V_196 * V_197 ,
struct V_32 * V_33 )
{
unsigned long V_5 ;
int V_198 = 0 ;
struct V_133 * V_122 ;
struct V_31 * V_18 = V_38 -> V_65 ;
while ( 1 ) {
F_2 ( & V_38 -> V_46 . V_92 , V_5 ) ;
if ( ! F_77 ( V_197 -> V_47 -> V_48 ,
L_2 ) ) {
F_3 ( & V_38 -> V_46 . V_92 ,
V_5 ) ;
V_38 -> V_199 ++ ;
break;
}
V_198 = F_78 ( V_197 -> V_47 , V_33 ,
V_55 ) ;
F_79 ( V_197 -> V_47 -> V_48 , L_2 ) ;
F_3 ( & V_38 -> V_46 . V_92 , V_5 ) ;
if ( V_198 == 0 )
break;
if ( V_33 -> V_3 == V_161 ) {
V_122 = F_8 ( V_38 ,
( T_1 )
V_33 -> V_75 . V_122 ) ;
if ( ! V_122 )
break;
F_72 ( V_33 , V_122 ) ;
} else if ( V_33 -> V_3 == V_131 ) {
if ( ! F_8 ( V_38 ,
( T_1 ) V_33 -> V_132 . V_122 ) )
break;
F_75 ( V_33 ) ;
} else if ( V_33 -> V_3 == V_200 ) {
V_33 -> V_35 . V_201 = NULL ;
F_15 ( V_18 , V_33 ) ;
} else if ( V_33 -> V_3 == V_118 ) {
if ( ! F_8 ( V_38 ,
( T_1 )
V_33 -> V_119 . V_122 ) )
break;
F_73 ( V_33 ) ;
}
}
}
static int
V_100 ( void * V_202 )
{
struct V_1 * V_38 = V_202 ;
struct V_196 * V_197 = & V_38 -> V_46 ;
struct V_32 * V_33 = NULL ;
const int V_203 = sizeof( struct V_32 ) ;
T_4 V_42 ;
unsigned long long V_43 ;
F_80 ( L_1 ) ;
V_33 = F_81 ( V_203 , V_34 ) ;
if ( ! V_33 ) {
F_82 ( & V_197 -> V_99 . V_204 , 0 ) ;
return 0 ;
}
V_42 = V_53 ;
while ( 1 ) {
if ( F_83 () )
break;
F_84 ( V_38 -> V_60 ,
( F_46 ( & V_38 -> V_59 ) == 1 ) ,
F_85 ( V_108 ) ) ;
F_23 ( & V_38 -> V_59 , 0 ) ;
F_76 ( V_38 , V_197 , V_33 ) ;
V_43 = F_35 ( V_38 -> V_54 , V_42 ) ;
}
F_13 ( V_33 ) ;
F_82 ( & V_197 -> V_99 . V_204 , 0 ) ;
}
static T_8 F_86 ( struct V_205 * V_205 ,
char T_7 * V_186 , T_9 V_206 , T_10 * V_194 )
{
T_8 V_207 = 0 ;
int V_208 = 0 ;
T_4 V_209 ;
int V_26 ;
struct V_1 * V_38 ;
char * V_210 ;
if ( V_206 > V_211 )
V_206 = V_211 ;
V_210 = F_16 ( V_206 , V_212 ) ;
if ( ! V_210 )
return - V_213 ;
for ( V_26 = 0 ; V_26 < V_89 ; V_26 ++ ) {
if ( ! V_90 [ V_26 ] . V_38 )
continue;
V_38 = V_90 [ V_26 ] . V_38 ;
V_208 += F_87 ( V_210 + V_208 ,
V_206 - V_208 , L_4 ,
V_167 ) ;
V_208 += F_87 ( V_210 + V_208 , V_206 - V_208 ,
L_5 ,
V_108 ) ;
V_208 += F_87 ( V_210 + V_208 , V_206 - V_208 ,
L_6 ,
V_38 -> V_45 ,
V_38 -> V_52 ) ;
V_208 += F_87 ( V_210 + V_208 ,
V_206 - V_208 , L_7 ,
V_38 -> V_56 ) ;
V_209 = F_88 ( ( V_214 void * )
V_38 -> V_54 ) ;
V_208 += F_87 ( V_210 + V_208 , V_206 - V_208 ,
L_8 ,
V_38 -> V_54 , V_209 ,
( V_215 ) F_19 ( V_38 -> V_54 ) ) ;
V_208 += F_87 ( V_210 + V_208 ,
V_206 - V_208 , L_9 ,
V_38 -> V_199 ) ;
V_208 += F_87 ( V_210 + V_208 , V_206 - V_208 , L_10 ) ;
}
V_207 = F_89 ( V_186 , V_206 , V_194 , V_210 , V_208 ) ;
F_13 ( V_210 ) ;
return V_207 ;
}
static T_8 F_90 ( struct V_205 * V_205 , const char T_7 * V_216 ,
T_9 V_217 , T_10 * V_218 )
{
char V_186 [ 4 ] ;
int V_26 , V_219 ;
struct V_1 * V_38 ;
T_4 T_3 * V_106 ;
T_4 V_42 ;
if ( V_217 >= F_91 ( V_186 ) )
return - V_152 ;
V_186 [ V_217 ] = '\0' ;
if ( F_92 ( V_186 , V_216 , V_217 ) )
return - V_220 ;
V_26 = F_93 ( V_186 , 10 , & V_219 ) ;
if ( V_26 != 0 )
return - V_220 ;
for ( V_26 = 0 ; V_26 < V_89 ; V_26 ++ ) {
if ( V_90 [ V_26 ] . V_38 ) {
V_38 = V_90 [ V_26 ] . V_38 ;
V_106 =
& V_38 -> V_46 . V_47 -> V_48 -> V_49 ;
if ( V_219 == 1 ) {
V_42 = ~ ( V_98 |
V_51 ) ;
F_20 ( V_106 , V_42 ) ;
V_42 = V_107 ;
F_35 ( V_106 , V_42 ) ;
V_108 = 4000000 ;
} else {
V_42 = ~ ( V_107 |
V_51 ) ;
F_20 ( V_106 , V_42 ) ;
V_42 = V_98 ;
F_35 ( V_106 , V_42 ) ;
V_108 = 4000 ;
}
}
}
return V_217 ;
}
static int
F_94 ( struct V_62 * V_63 )
{
struct V_1 * V_38 =
(struct V_1 * ) ( (struct V_31 * ) V_63 -> V_75 .
V_65 ) -> V_88 ;
if ( ! V_38 -> V_93 )
return 1 ;
if ( V_38 -> V_94 )
return 0 ;
V_38 -> V_94 = true ;
F_95 ( V_38 -> V_46 . V_47 -> V_48 ,
F_96 ( & V_63 -> V_85 ) ,
V_221 , NULL ) ;
if ( ! F_33 ( & V_38 -> V_46 . V_99 ,
V_100 ,
V_38 , L_1 ) ) {
return 0 ;
}
V_38 -> V_93 = false ;
V_38 -> V_94 = false ;
return 1 ;
}
static void
V_97 ( struct V_23 * V_24 )
{
struct V_1 * V_38 ;
struct V_62 * V_63 ;
int V_26 ;
struct V_222 * V_223 = NULL ;
struct V_133 * V_122 = NULL ;
struct V_32 * V_33 ;
unsigned long V_5 ;
V_38 = F_97 ( V_24 , struct V_1 ,
V_96 ) ;
F_40 ( & V_38 -> V_46 . V_99 ) ;
F_2 ( & V_38 -> V_7 , V_5 ) ;
for ( V_26 = 0 ; V_26 < V_11 ; V_26 ++ ) {
V_223 = & V_38 -> V_9 [ V_26 ] ;
switch ( V_223 -> V_3 ) {
case V_161 :
V_122 = (struct V_133 * ) V_223 -> V_10 ;
V_122 -> V_195 = V_224 << 16 ;
if ( V_122 -> V_162 )
V_122 -> V_162 ( V_122 ) ;
break;
case V_131 :
V_33 = (struct V_32 * ) V_223 -> V_10 ;
F_74 ( ( T_6 * )
V_33 -> V_132 . V_120 ) ;
* ( int * ) V_33 -> V_132 . V_114 =
V_225 ;
break;
case V_118 :
V_33 = (struct V_32 * ) V_223 -> V_10 ;
* ( int * ) V_33 -> V_119 . V_114 =
V_226 ;
F_74 ( ( T_6 * )
V_33 -> V_119 . V_120 ) ;
break;
default:
break;
}
V_223 -> V_3 = 0 ;
V_223 -> V_10 = NULL ;
}
F_3 ( & V_38 -> V_7 , V_5 ) ;
V_63 = V_38 -> V_63 ;
V_38 -> V_93 = true ;
V_38 -> V_94 = false ;
F_98 ( V_63 -> V_227 ,
V_63 -> V_228 , 0 ) ;
}
static int
F_99 ( struct V_62 * V_63 , T_11 V_229 )
{
int V_230 = 1 ;
struct V_1 * V_38 =
(struct V_1 * ) ( (struct V_31 * ) V_63 -> V_75 .
V_65 ) -> V_88 ;
if ( ! V_38 -> V_93 && ! V_38 -> V_94 ) {
V_38 -> V_94 = true ;
F_100 ( V_231 ,
& V_38 -> V_96 ) ;
} else if ( V_38 -> V_94 ) {
V_230 = 0 ;
}
return V_230 ;
}
static int T_12
F_101 ( char * V_232 )
{
return 1 ;
}
static void T_12
F_102 ( char * line )
{
char * V_30 = line ;
F_26 ( V_233 , V_69 ) ;
if ( ! line || ! * line )
return;
while ( ( line = V_30 ) ) {
V_30 = strchr ( line , ' ' ) ;
if ( V_30 )
* V_30 ++ = 0 ;
F_101 ( line ) ;
}
F_26 ( V_234 , V_69 ) ;
}
static int T_12
F_103 ( void )
{
int error ;
int V_26 ;
if ( ! V_235 )
return - V_71 ;
F_26 ( V_233 , V_69 ) ;
F_102 ( V_236 ) ;
error = F_104 ( & V_237 ) ;
if ( error < 0 ) {
F_105 ( V_238 , error ,
V_87 ) ;
} else {
V_239 = F_106 ( L_11 , NULL ) ;
F_107 ( L_12 , V_240 , V_239 ,
NULL , & V_241 ) ;
F_108 ( L_13 , V_240 | V_242 ,
V_239 , & V_108 ) ;
F_107 ( L_14 , V_242 ,
V_239 , NULL ,
& V_243 ) ;
F_32 ( & V_244 , F_14 ) ;
F_30 ( & V_27 ) ;
for ( V_26 = 0 ; V_26 < V_89 ; V_26 ++ )
V_90 [ V_26 ] . V_38 = NULL ;
V_231 =
F_109 ( L_15 ) ;
if ( ! V_231 ) {
F_26 ( V_238 ,
V_87 ) ;
error = - 1 ;
}
}
F_26 ( V_234 , V_69 ) ;
return error ;
}
static T_8
F_110 ( struct V_136 * V_245 , struct V_246 * V_247 ,
const char * V_186 , T_9 V_217 )
{
struct V_112 V_113 ;
struct V_31 * V_18 = F_111 ( V_245 ) ;
int V_26 ;
V_26 = sscanf ( V_186 , L_16 , & V_113 . V_19 , & V_113 . V_20 , & V_113 . V_21 ) ;
if ( V_26 != 3 )
return V_26 ;
return F_41 ( V_248 , V_18 , & V_113 ) ;
}
static T_8
F_112 ( struct V_136 * V_245 , struct V_246 * V_247 ,
const char * V_186 , T_9 V_217 )
{
struct V_112 V_113 ;
struct V_31 * V_18 = F_111 ( V_245 ) ;
int V_26 ;
V_26 = sscanf ( V_186 , L_16 , & V_113 . V_19 , & V_113 . V_20 , & V_113 . V_21 ) ;
if ( V_26 != 3 )
return V_26 ;
return F_41 ( V_249 , V_18 , & V_113 ) ;
}
static void T_13
F_113 ( void )
{
F_114 ( & V_237 ) ;
if ( V_231 ) {
F_115 ( V_231 ) ;
V_231 = NULL ;
}
F_116 ( V_239 ) ;
}
