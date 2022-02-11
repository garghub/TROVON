static int
F_1 ( struct V_1 * V_2 , char V_3 , void * V_4 )
{
unsigned long V_5 ;
int V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
V_6 = V_2 -> V_8 ;
while ( V_2 -> V_9 [ V_6 ] . V_10 != NULL ) {
V_6 = ( V_6 + 1 ) % V_11 ;
if ( V_6 == ( int ) V_2 -> V_8 ) {
F_3 ( L_1 ,
V_6 ) ;
F_4 ( & V_2 -> V_7 , V_5 ) ;
return - 1 ;
}
}
V_2 -> V_9 [ V_6 ] . V_3 = V_3 ;
V_2 -> V_9 [ V_6 ] . V_10 = V_4 ;
V_2 -> V_8 = ( V_6 + 1 ) % V_11 ;
F_4 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static unsigned int
F_5 ( struct V_1 * V_2 , char V_3 ,
void * V_4 )
{
int V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
while ( V_6 == - 1 ) {
F_3 ( L_2 ) ;
F_6 ( V_12 ) ;
F_7 ( F_8 ( 10 ) ) ;
V_6 = F_1 ( V_2 , V_3 , V_4 ) ;
}
return ( unsigned int ) V_6 ;
}
static void *
F_9 ( struct V_1 * V_2 , T_1 V_13 )
{
unsigned long V_5 ;
void * V_10 = NULL ;
if ( V_13 >= V_11 ) {
F_3 ( L_3 ,
( unsigned long ) V_13 , V_11 ) ;
} else {
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_9 [ V_13 ] . V_10 == NULL )
F_3 ( L_4 ,
( unsigned long ) V_13 ) ;
V_10 = V_2 -> V_9 [ V_13 ] . V_10 ;
V_2 -> V_9 [ V_13 ] . V_3 = 0 ;
V_2 -> V_9 [ V_13 ] . V_10 = NULL ;
F_4 ( & V_2 -> V_7 , V_5 ) ;
}
return V_10 ;
}
static inline void
F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int error ;
V_17 = F_11 ( V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 , V_15 -> V_21 ) ;
if ( V_17 ) {
if ( ! ( V_15 -> V_22 ) )
F_12 ( V_17 ) ;
} else if ( V_15 -> V_22 ) {
error =
F_13 ( V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 ,
V_15 -> V_21 ) ;
if ( error )
F_3 ( L_5 ,
V_15 -> V_18 -> V_23 , V_15 -> V_19 , V_15 -> V_20 ,
V_15 -> V_21 ) ;
} else
F_3 ( L_6 ,
V_15 -> V_19 , V_15 -> V_20 , V_15 -> V_21 ) ;
F_14 ( V_15 ) ;
}
static void
F_15 ( struct V_24 * V_25 )
{
struct V_14 * V_15 ;
struct V_14 * V_26 ;
int V_27 = 0 ;
unsigned long V_5 ;
F_2 ( & V_28 , V_5 ) ;
V_26 = V_29 ;
V_29 = NULL ;
V_30 = 0 ;
F_4 ( & V_28 , V_5 ) ;
while ( V_26 ) {
V_15 = V_26 ;
V_26 = V_15 -> V_31 ;
F_10 ( V_15 ) ;
V_27 ++ ;
}
}
static void
F_16 ( struct V_32 * V_18 , struct V_33 * V_34 )
{
struct V_14 * V_15 ;
unsigned long V_5 ;
V_15 = F_17 ( sizeof( struct V_14 ) , V_35 ) ;
if ( V_15 ) {
V_15 -> V_22 = V_34 -> V_36 . V_22 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_34 -> V_36 . V_19 ;
V_15 -> V_20 = V_34 -> V_36 . V_20 ;
V_15 -> V_21 = V_34 -> V_36 . V_21 ;
F_18 ( V_15 ) ;
} else {
F_3 ( L_7 ,
V_18 -> V_23 , V_34 -> V_36 . V_19 ,
V_34 -> V_36 . V_20 , V_34 -> V_36 . V_21 ) ;
}
}
static T_2
F_19 ( int V_37 , void * V_38 )
{
struct V_1 * V_39 = (struct V_1 * ) V_38 ;
struct V_40 T_3 * V_41 ;
struct V_42 T_3 * V_43 ;
T_4 V_44 ;
unsigned long long V_45 ;
if ( V_39 == NULL )
return V_46 ;
V_39 -> V_47 ++ ;
V_41 = V_39 -> V_48 . V_49 -> V_50 ;
if ( ( ( F_20 ( & V_41 -> V_51 )
& V_52 ) != 0 )
&& ( ( F_20 ( & V_41 -> V_51 ) &
V_53 ) !=
0 ) ) {
V_39 -> V_54 ++ ;
V_44 = ~ V_55 ;
V_45 = F_21 ( V_39 -> V_56 , V_44 ) ;
}
if ( F_22 ( V_41 , V_57 ) ) {
V_39 -> V_58 ++ ;
return V_46 ;
}
V_43 = (struct V_42 T_3 * )
( ( char T_3 * ) V_41 +
F_20 ( & V_41 -> V_59 ) ) + V_57 ;
F_23 ( F_20 ( & V_43 -> V_60 ) + 1 ,
& V_43 -> V_60 ) ;
F_24 ( & V_39 -> V_61 , 1 ) ;
F_25 ( & V_39 -> V_62 ) ;
return V_63 ;
}
static int
F_26 ( struct V_64 * V_65 , const struct V_66 * V_20 )
{
int error ;
struct V_32 * V_67 ;
struct V_1 * V_39 ;
int V_68 ;
int V_27 ;
T_5 V_69 = F_19 ;
struct V_40 T_3 * V_41 ;
struct V_42 T_3 * V_43 ;
T_4 V_44 ;
F_27 ( L_8 ) ;
F_27 ( L_9 , V_65 -> V_70 ,
V_65 -> V_71 ) ;
F_28 ( L_8 ) ;
F_28 ( L_9 , V_65 -> V_70 ,
V_65 -> V_71 ) ;
F_29 ( V_72 , V_73 ) ;
F_30 ( L_10 ) ;
V_67 = F_31 ( & V_74 ,
sizeof( struct V_1 ) ) ;
if ( V_67 == NULL )
return - V_75 ;
F_30 ( L_11 ,
V_67 , V_67 -> V_76 , V_67 -> V_23 ) ;
V_67 -> V_76 = V_77 ;
F_28 ( L_12 ,
( unsigned ) V_65 -> V_78 . V_79 . V_80 - 1 ,
( unsigned ) V_65 -> V_78 . V_79 . V_81 ,
( unsigned ) V_65 -> V_78 . V_79 . V_82 ,
( unsigned ) V_65 -> V_78 . V_79 . V_83 ,
( unsigned ) V_65 -> V_78 . V_79 . V_84 ) ;
V_67 -> V_80 = ( unsigned ) V_65 -> V_78 . V_79 . V_80 ;
V_67 -> V_81 = ( unsigned ) V_65 -> V_78 . V_79 . V_81 ;
V_67 -> V_82 = ( unsigned ) V_65 -> V_78 . V_79 . V_82 ;
V_67 -> V_83 = ( unsigned ) V_65 -> V_78 . V_79 . V_83 ;
V_67 -> V_85 =
( unsigned short ) ( V_65 -> V_78 . V_79 . V_84 >> 9 ) ;
V_67 -> V_86 =
( unsigned short ) ( V_65 -> V_78 . V_79 . V_84 / V_87 ) ;
if ( V_67 -> V_86 > V_88 )
V_67 -> V_86 = V_88 ;
F_28 ( L_13 ,
V_67 -> V_80 , V_67 -> V_81 , V_67 -> V_82 ,
V_67 -> V_83 , V_67 -> V_85 ,
V_67 -> V_86 ) ;
F_28 ( L_14 ,
V_67 -> V_89 , V_67 -> V_83 , V_67 -> V_85 ,
V_67 -> V_86 ) ;
F_30 ( L_15 ) ;
error = F_32 ( V_67 , & V_65 -> V_90 ) ;
if ( error ) {
F_3 ( L_16 , error ) ;
F_29 ( V_91 , V_92 ) ;
F_33 ( V_67 ) ;
return - V_75 ;
}
V_39 = (struct V_1 * ) V_67 -> V_93 ;
memset ( V_39 , 0 , sizeof( struct V_1 ) ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( V_95 [ V_27 ] . V_39 == NULL ) {
V_95 [ V_27 ] . V_39 = V_39 ;
break;
}
}
V_39 -> V_96 = - 1 ;
V_39 -> V_48 . V_49 = & V_65 -> V_49 ;
V_39 -> V_65 = V_65 ;
F_34 ( & V_39 -> V_48 . V_97 ) ;
F_30 ( L_17 ,
& V_65 -> V_90 , & V_65 -> V_49 ) ;
F_35 ( & V_39 -> V_62 ) ;
F_34 ( & V_39 -> V_7 ) ;
memset ( & V_39 -> V_9 , 0 , sizeof( V_39 -> V_9 ) ) ;
V_39 -> V_98 = false ;
V_39 -> V_99 = false ;
V_39 -> V_100 = V_65 -> V_100 ;
V_39 -> V_67 = V_67 ;
V_65 -> V_78 . V_67 = V_67 ;
F_36 ( & V_39 -> V_101 ,
V_102 ) ;
F_23 ( F_20 ( & V_39 -> V_48 . V_49 -> V_50 -> V_51 ) |
V_103 ,
& V_39 -> V_48 . V_49 -> V_50 -> V_51 ) ;
F_30 ( L_18 ,
V_39 -> V_48 . V_49 , & V_39 -> V_48 . V_104 ) ;
V_41 = V_39 -> V_48 . V_49 -> V_50 ;
V_43 = (struct V_42 T_3 * )
( ( char T_3 * ) V_41 +
F_20 ( & V_41 -> V_59 ) ) + V_57 ;
V_39 -> V_56 = & V_43 -> V_51 ;
if ( ! F_37 ( & V_39 -> V_48 . V_104 ,
V_105 ,
V_39 , L_19 ) ) {
F_3 ( L_20 ) ;
F_29 ( V_91 , V_92 ) ;
F_33 ( V_67 ) ;
return - V_75 ;
}
F_28 ( L_21 ,
V_39 -> V_100 . V_106 ) ;
F_28 ( L_22 ,
V_39 -> V_100 . V_107 ) ;
F_28 ( L_23 ,
V_39 -> V_100 . V_108 ) ;
F_28 ( L_24 ,
V_39 -> V_100 . V_109 ) ;
F_28 ( L_25 , V_67 -> V_110 -> V_111 ) ;
V_39 -> V_96 =
V_39 -> V_100 . V_107 & V_112 ;
V_68 = F_38 ( V_39 -> V_96 , V_69 , V_113 ,
V_67 -> V_110 -> V_111 , V_39 ) ;
if ( V_68 != 0 ) {
F_3 ( L_26 ,
V_39 -> V_96 , V_68 ) ;
V_39 -> V_96 = - 1 ;
F_29 ( V_91 , V_92 ) ;
} else {
T_4 T_3 * V_114 =
& V_39 -> V_48 . V_49 -> V_50 -> V_51 ;
F_3 ( L_27 ,
V_39 -> V_96 ) ;
V_44 = ~ ( V_103 |
V_53 ) ;
F_21 ( V_114 , V_44 ) ;
V_44 = V_115 ;
F_39 ( V_114 , V_44 ) ;
V_116 = 4000000 ;
}
F_30 ( L_28 ) ;
F_40 ( V_67 ) ;
F_30 ( L_29 ) ;
F_28 ( L_30 , V_67 ) ;
F_29 ( V_117 , V_73 ) ;
return 0 ;
}
static void
F_41 ( struct V_64 * V_65 )
{
struct V_1 * V_39 ;
struct V_32 * V_67 =
(struct V_32 * ) V_65 -> V_78 . V_67 ;
F_28 ( L_9 , V_65 -> V_70 ,
V_65 -> V_71 ) ;
V_39 = (struct V_1 * ) V_67 -> V_93 ;
if ( V_39 -> V_96 != - 1 )
F_42 ( V_39 -> V_96 , V_39 ) ;
F_28 ( L_31 , V_65 ,
V_39 ) ;
F_30 ( L_32 , V_67 ,
V_67 -> V_76 ) ;
F_43 ( V_67 ) ;
F_30 ( L_33 ) ;
F_44 ( & V_39 -> V_48 . V_104 ) ;
F_30 ( L_34 ) ;
F_33 ( V_67 ) ;
F_28 ( L_35 ) ;
}
static int
F_45 ( enum V_118 V_119 ,
struct V_32 * V_67 ,
struct V_120 * V_121 )
{
struct V_33 * V_34 ;
struct V_1 * V_39 =
(struct V_1 * ) V_67 -> V_93 ;
int V_122 = 0xffff ;
T_6 V_123 ;
F_28 ( L_36 , V_119 ,
V_121 -> V_19 , V_121 -> V_20 , V_121 -> V_21 ) ;
if ( V_39 -> V_98 || V_39 -> V_99 ) {
F_30 ( L_37 ) ;
return V_124 ;
}
V_34 = F_17 ( V_125 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return V_124 ;
}
F_35 ( & V_123 ) ;
V_34 -> V_3 = V_126 ;
V_34 -> V_127 . V_128 = ( void * ) & V_123 ;
V_34 -> V_127 . V_122 = ( void * ) & V_122 ;
V_34 -> V_127 . V_129 = V_119 ;
V_34 -> V_127 . V_121 . V_19 = V_121 -> V_19 ;
V_34 -> V_127 . V_121 . V_20 = V_121 -> V_20 ;
V_34 -> V_127 . V_121 . V_21 = V_121 -> V_21 ;
V_34 -> V_127 . V_130 =
( void * ) ( T_1 )
F_5 ( V_39 , V_126 ,
( void * ) V_34 ) ;
F_46 ( V_39 -> V_48 . V_49 ,
V_34 , V_131 ,
& V_39 -> V_48 . V_97 ,
V_132 , ( T_4 ) NULL ,
V_133 , L_39 ) ;
F_28 ( L_40 ,
V_34 -> V_134 . V_128 ) ;
F_47 ( V_123 , V_122 != 0xffff ) ;
F_28 ( L_41 , V_34 -> V_127 . V_135 ) ;
F_14 ( V_34 ) ;
return V_136 ;
}
static int
F_48 ( enum V_137 V_138 ,
struct V_16 * V_139 )
{
struct V_33 * V_34 ;
struct V_1 * V_39 =
(struct V_1 * ) V_139 -> V_140 -> V_93 ;
int V_122 = 0xffff ;
T_6 V_123 ;
F_28 ( L_42 , V_138 ,
V_139 -> V_19 , V_139 -> V_20 , V_139 -> V_21 ) ;
if ( V_39 -> V_98 || V_39 -> V_99 ) {
F_30 ( L_37 ) ;
return V_124 ;
}
V_34 = F_17 ( V_125 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return V_124 ;
}
F_35 ( & V_123 ) ;
V_34 -> V_3 = V_141 ;
V_34 -> V_134 . V_128 = ( void * ) & V_123 ;
V_34 -> V_134 . V_122 = ( void * ) & V_122 ;
V_34 -> V_134 . V_138 = V_138 ;
V_34 -> V_134 . V_121 . V_19 = V_139 -> V_19 ;
V_34 -> V_134 . V_121 . V_20 = V_139 -> V_20 ;
V_34 -> V_134 . V_121 . V_21 = V_139 -> V_21 ;
V_34 -> V_134 . V_130 =
( void * ) ( T_1 )
F_5 ( V_39 ,
V_141 ,
( void * ) V_34 ) ;
F_46 ( V_39 -> V_48 . V_49 ,
V_34 , V_131 ,
& V_39 -> V_48 . V_97 ,
V_132 , ( T_4 ) NULL ,
V_133 , L_39 ) ;
F_28 ( L_43 ,
V_34 -> V_134 . V_128 ) ;
F_47 ( V_123 , V_122 != 0xffff ) ;
F_28 ( L_44 , V_34 -> V_134 . V_135 ) ;
F_14 ( V_34 ) ;
return V_136 ;
}
static int
F_49 ( struct V_142 * V_130 )
{
struct V_16 * V_139 ;
struct V_143 * V_144 ;
V_139 = V_130 -> V_145 ;
for ( V_144 = & ( (struct V_1 * ) V_139 -> V_140 -> V_93 ) -> V_146 ;
V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( ( V_139 -> V_19 == V_144 -> V_19 )
&& ( V_139 -> V_20 == V_144 -> V_20 )
&& ( V_139 -> V_21 == V_144 -> V_21 ) ) {
if ( F_50 ( & V_144 -> V_147 ) <
V_148 ) {
F_51 ( & V_144 -> V_147 ) ;
F_29 ( V_149 ,
V_73 ) ;
} else
F_24 ( & V_144 -> V_150 ,
V_151 ) ;
}
}
return F_48 ( V_152 , V_130 -> V_145 ) ;
}
static int
F_52 ( struct V_142 * V_130 )
{
struct V_16 * V_139 ;
struct V_143 * V_144 ;
V_139 = V_130 -> V_145 ;
for ( V_144 = & ( (struct V_1 * ) V_139 -> V_140 -> V_93 ) -> V_146 ;
V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( ( V_139 -> V_19 == V_144 -> V_19 )
&& ( V_139 -> V_20 == V_144 -> V_20 )
&& ( V_139 -> V_21 == V_144 -> V_21 ) ) {
if ( F_50 ( & V_144 -> V_147 ) <
V_148 ) {
F_51 ( & V_144 -> V_147 ) ;
F_29 ( V_149 ,
V_73 ) ;
} else
F_24 ( & V_144 -> V_150 ,
V_151 ) ;
}
}
return F_48 ( V_153 , V_130 -> V_145 ) ;
}
static int
F_53 ( struct V_142 * V_130 )
{
struct V_16 * V_139 ;
struct V_143 * V_144 ;
V_139 = V_130 -> V_145 ;
for ( V_144 = & ( (struct V_1 * ) V_139 -> V_140 -> V_93 ) -> V_146 ;
V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( ( V_139 -> V_19 == V_144 -> V_19 )
&& ( V_139 -> V_20 == V_144 -> V_20 )
&& ( V_139 -> V_21 == V_144 -> V_21 ) ) {
if ( F_50 ( & V_144 -> V_147 ) <
V_148 ) {
F_51 ( & V_144 -> V_147 ) ;
F_29 ( V_149 ,
V_73 ) ;
} else
F_24 ( & V_144 -> V_150 ,
V_151 ) ;
}
}
return F_48 ( V_154 , V_130 -> V_145 ) ;
}
static int
F_54 ( struct V_142 * V_130 )
{
F_3 ( L_45 ) ;
return V_136 ;
}
static const char *
F_55 ( struct V_32 * V_155 )
{
sprintf ( V_156 , L_46 , V_157 ) ;
return V_156 ;
}
static int
F_56 ( struct V_16 * V_158 , int V_159 , void T_7 * V_160 )
{
F_30 ( L_47 , V_159 ) ;
return - V_161 ;
}
static int
F_57 ( struct V_142 * V_130 ,
void (* F_58)( struct V_142 * ) )
{
struct V_16 * V_139 = V_130 -> V_145 ;
int V_6 ;
unsigned char V_162 ;
unsigned char * V_163 = V_130 -> V_164 ;
struct V_32 * V_67 = V_139 -> V_140 ;
struct V_33 * V_34 ;
unsigned int V_27 ;
struct V_1 * V_39 =
(struct V_1 * ) V_67 -> V_93 ;
struct V_165 * V_166 = NULL ;
struct V_165 * V_167 = NULL ;
int V_168 = 0 ;
if ( V_39 -> V_98 || V_39 -> V_99 ) {
F_30 ( L_48 ) ;
return V_169 ;
}
V_34 = F_17 ( V_125 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return 1 ;
}
V_34 -> V_3 = V_170 ;
V_6 =
F_1 ( V_39 , V_170 , ( void * ) V_130 ) ;
if ( V_6 != - 1 ) {
V_34 -> V_78 . V_130 = ( void * ) ( T_1 ) V_6 ;
} else {
F_3 ( L_49 ) ;
F_14 ( V_34 ) ;
return V_169 ;
}
V_130 -> V_171 = F_58 ;
V_34 -> V_78 . V_121 . V_19 = V_139 -> V_19 ;
V_34 -> V_78 . V_121 . V_20 = V_139 -> V_20 ;
V_34 -> V_78 . V_121 . V_21 = V_139 -> V_21 ;
V_34 -> V_78 . V_172 = V_130 -> V_173 ;
memcpy ( V_34 -> V_78 . V_164 , V_163 , V_174 ) ;
V_34 -> V_78 . V_175 = F_59 ( V_130 ) ;
if ( V_34 -> V_78 . V_175 > V_176 )
V_176 = V_34 -> V_78 . V_175 ;
if ( F_60 ( V_130 ) > V_88 ) {
F_3 ( L_50 ,
F_60 ( V_130 ) , V_88 ) ;
F_9 ( V_39 , ( T_1 ) V_6 ) ;
F_14 ( V_34 ) ;
return 1 ;
}
if ( F_60 ( V_130 ) == 0 ) {
if ( F_59 ( V_130 ) > 0 ) {
F_3 ( L_51 ) ;
F_61 ( F_60 ( V_130 ) == 0 ) ;
}
F_30 ( L_52 ,
F_62 ( V_130 ) , F_59 ( V_130 ) ) ;
} else {
V_167 = F_62 ( V_130 ) ;
F_63 (sgl, sg, scsi_sg_count(scsicmd), i) {
V_34 -> V_78 . V_177 [ V_27 ] . V_178 = F_64 ( V_166 ) ;
V_34 -> V_78 . V_177 [ V_27 ] . V_179 = V_166 -> V_179 ;
if ( ( V_27 != 0 ) && ( V_166 -> V_180 != 0 ) )
F_28 ( L_53 ,
V_166 -> V_180 ) ;
}
if ( V_168 ) {
F_3 ( L_54 ,
F_60 ( V_130 ) , V_34 -> V_78 . V_175 ) ;
F_63 (sgl, sg, scsi_sg_count(scsicmd), i) {
F_3 ( L_55 ,
V_27 , F_65 ( V_166 ) ,
( unsigned long long ) F_64 ( V_166 ) ,
V_166 -> V_180 , V_166 -> V_179 ) ;
}
F_3 ( L_56 ) ;
}
V_34 -> V_78 . V_181 = F_60 ( V_130 ) ;
}
V_162 = V_163 [ 0 ] ;
V_27 = F_46 ( V_39 -> V_48 . V_49 ,
V_34 , V_131 ,
& V_39 -> V_48 .
V_97 ,
V_132 ,
( T_4 ) NULL , V_182 , L_39 ) ;
if ( V_27 == 0 ) {
F_3 ( L_57 ) ;
F_14 ( V_34 ) ;
F_9 ( V_39 , ( T_1 ) V_6 ) ;
return V_169 ;
}
F_14 ( V_34 ) ;
return 0 ;
}
static int
F_66 ( struct V_16 * V_139 )
{
struct V_143 * V_144 ;
struct V_143 * V_183 ;
struct V_1 * V_39 ;
struct V_32 * V_67 = (struct V_32 * ) V_139 -> V_140 ;
V_39 = (struct V_1 * ) V_67 -> V_93 ;
if ( ! V_39 ) {
F_3 ( L_58 ) ;
return 0 ;
}
for ( V_144 = & V_39 -> V_146 ; V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( V_144 -> V_31 -> V_184 &&
( V_144 -> V_31 -> V_19 == V_139 -> V_19 ) &&
( V_144 -> V_31 -> V_20 == V_139 -> V_20 ) &&
( V_144 -> V_31 -> V_21 == V_139 -> V_21 ) )
return 0 ;
}
V_183 = F_17 ( sizeof( struct V_143 ) , V_35 ) ;
if ( ! V_183 ) {
F_3 ( L_59 ) ;
return 0 ;
}
V_183 -> V_19 = V_139 -> V_19 ;
V_183 -> V_20 = V_139 -> V_20 ;
V_183 -> V_21 = V_139 -> V_21 ;
V_183 -> V_184 = 1 ;
V_144 -> V_31 = V_183 ;
return 0 ;
}
static int
F_67 ( struct V_16 * V_139 )
{
return 0 ;
}
static void
F_68 ( struct V_16 * V_139 )
{
struct V_143 * V_144 , * V_185 ;
struct V_1 * V_39 ;
struct V_32 * V_67 = (struct V_32 * ) V_139 -> V_140 ;
V_39 = (struct V_1 * ) V_67 -> V_93 ;
if ( ! V_39 )
F_3 ( L_58 ) ;
for ( V_144 = & V_39 -> V_146 ; V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( V_144 -> V_31 -> V_184 &&
( V_144 -> V_31 -> V_19 == V_139 -> V_19 ) &&
( V_144 -> V_31 -> V_20 == V_139 -> V_20 ) &&
( V_144 -> V_31 -> V_21 == V_139 -> V_21 ) ) {
V_185 = V_144 -> V_31 ;
V_144 -> V_31 = V_144 -> V_31 -> V_31 ;
F_14 ( V_185 ) ;
return;
}
}
}
static void
F_69 ( struct V_33 * V_34 , struct V_142 * V_130 )
{
struct V_143 * V_144 ;
struct V_16 * V_139 ;
struct V_186 * V_187 ;
V_139 = V_130 -> V_145 ;
memcpy ( V_130 -> V_188 , V_34 -> V_78 . V_189 , V_190 ) ;
V_187 = (struct V_186 * ) V_130 -> V_188 ;
if ( ( V_34 -> V_78 . V_164 [ 0 ] == V_191 ) &&
( F_70 ( V_34 -> V_78 . V_192 ) == V_193 ) &&
( V_34 -> V_78 . V_194 == V_195 ) )
return;
for ( V_144 = & ( (struct V_1 * ) V_139 -> V_140 -> V_93 ) -> V_146 ;
V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( ( V_139 -> V_19 != V_144 -> V_19 )
|| ( V_139 -> V_20 != V_144 -> V_20 )
|| ( V_139 -> V_21 != V_144 -> V_21 ) )
continue;
if ( F_50 ( & V_144 -> V_147 ) < V_148 ) {
F_51 ( & V_144 -> V_147 ) ;
F_3 ( L_60 ,
V_130 , V_34 -> V_78 . V_164 [ 0 ] ,
V_139 -> V_140 -> V_23 , V_139 -> V_20 ,
V_139 -> V_19 , V_139 -> V_21 ,
V_34 -> V_78 . V_192 , V_187 -> V_184 , V_187 -> V_196 ,
V_187 -> V_197 ,
V_187 -> V_198 ) ;
if ( F_50 ( & V_144 -> V_147 ) ==
V_148 ) {
F_3 ( L_61 ,
V_139 -> V_140 -> V_23 , V_139 -> V_20 ,
V_139 -> V_19 , V_139 -> V_21 ) ;
}
F_24 ( & V_144 -> V_150 , V_151 ) ;
}
}
}
static void
F_71 ( struct V_33 * V_34 , struct V_142 * V_130 )
{
struct V_16 * V_139 ;
unsigned char V_199 [ 36 ] ;
struct V_165 * V_166 ;
unsigned int V_27 ;
char * V_200 ;
char * V_201 ;
int V_202 = 0 ;
struct V_143 * V_144 ;
V_139 = V_130 -> V_145 ;
if ( ( V_34 -> V_78 . V_164 [ 0 ] == V_191 )
&& ( V_34 -> V_78 . V_175 >= V_203 ) ) {
if ( V_34 -> V_78 . V_204 == 0 )
return;
F_72 ( V_199 , V_34 -> V_78 . V_175 ,
V_139 -> V_21 ,
V_205 ,
V_206 ) ;
if ( F_60 ( V_130 ) == 0 ) {
if ( F_59 ( V_130 ) > 0 ) {
F_3 ( L_51 ) ;
F_61 ( F_60 ( V_130 ) ==
0 ) ;
}
memcpy ( F_62 ( V_130 ) , V_199 ,
V_34 -> V_78 . V_175 ) ;
return;
}
V_166 = F_62 ( V_130 ) ;
for ( V_27 = 0 ; V_27 < F_60 ( V_130 ) ; V_27 ++ ) {
F_73 ( L_62 ,
F_65 ( V_166 + V_27 ) , V_166 [ V_27 ] . V_179 ) ;
V_201 = F_74 ( F_65 ( V_166 + V_27 ) ) ;
V_200 = ( void * ) ( ( unsigned long ) V_201 |
V_166 [ V_27 ] . V_180 ) ;
memcpy ( V_200 , V_199 + V_202 , V_166 [ V_27 ] . V_179 ) ;
F_75 ( V_201 ) ;
V_202 += V_166 [ V_27 ] . V_179 ;
}
} else {
V_144 = & ( (struct V_1 * ) V_139 -> V_140 -> V_93 ) -> V_146 ;
for ( ; V_144 -> V_31 ; V_144 = V_144 -> V_31 ) {
if ( ( V_139 -> V_19 != V_144 -> V_19 )
|| ( V_139 -> V_20 != V_144 -> V_20 )
|| ( V_139 -> V_21 != V_144 -> V_21 ) )
continue;
if ( F_50 ( & V_144 -> V_150 ) > 0 ) {
F_76 ( & V_144 -> V_150 ) ;
if ( F_50 ( & V_144 -> V_150 ) == 0 ) {
F_3 ( L_63 ) ;
F_24 ( & V_144 -> V_147 , 0 ) ;
}
}
}
}
}
static void
F_77 ( struct V_33 * V_34 , struct V_142 * V_130 )
{
F_30 ( L_64 , V_34 , V_34 -> V_78 . V_207 ) ;
V_130 -> V_135 = V_34 -> V_78 . V_192 ;
if ( V_34 -> V_78 . V_192 )
F_69 ( V_34 , V_130 ) ;
else
F_71 ( V_34 , V_130 ) ;
if ( V_130 -> V_171 ) {
F_73 ( L_65 ) ;
V_130 -> V_171 ( V_130 ) ;
}
}
static inline void
F_78 ( struct V_33 * V_34 )
{
* ( int * ) V_34 -> V_127 . V_122 = V_34 -> V_127 . V_135 ;
F_79 ( ( T_6 * ) V_34 -> V_127 . V_128 ) ;
F_28 ( L_66 , V_34 -> V_127 . V_135 ) ;
}
static inline void
F_80 ( struct V_33 * V_34 )
{
* ( int * ) V_34 -> V_134 . V_122 =
V_34 -> V_134 . V_135 ;
F_79 ( ( T_6 * ) V_34 -> V_134 . V_128 ) ;
F_28 ( L_66 , V_34 -> V_134 . V_135 ) ;
}
static void
F_81 ( struct V_1 * V_39 , struct V_208 * V_209 ,
struct V_33 * V_34 )
{
unsigned long V_5 ;
int V_210 = 0 ;
struct V_142 * V_130 ;
struct V_32 * V_18 = V_39 -> V_67 ;
while ( 1 ) {
F_2 ( & V_39 -> V_48 . V_97 , V_5 ) ;
if ( ! F_82 ( V_209 -> V_49 -> V_50 ,
L_39 ) ) {
F_4 ( & V_39 -> V_48 . V_97 ,
V_5 ) ;
V_39 -> V_211 ++ ;
break;
}
V_210 = F_83 ( V_209 -> V_49 , V_34 ,
V_57 ) ;
F_84 ( V_209 -> V_49 -> V_50 , L_39 ) ;
F_4 ( & V_39 -> V_48 . V_97 , V_5 ) ;
if ( V_210 == 0 )
break;
if ( V_34 -> V_3 == V_170 ) {
V_130 = F_9 ( V_39 ,
( T_1 ) V_34 -> V_78 . V_130 ) ;
if ( ! V_130 )
break;
F_77 ( V_34 , V_130 ) ;
} else if ( V_34 -> V_3 == V_141 ) {
if ( ! F_9 ( V_39 ,
( T_1 ) V_34 -> V_134 . V_130 ) )
break;
F_80 ( V_34 ) ;
} else if ( V_34 -> V_3 == V_212 ) {
V_34 -> V_36 . V_213 = NULL ;
F_16 ( V_18 , V_34 ) ;
} else if ( V_34 -> V_3 == V_126 ) {
if ( ! F_9 ( V_39 ,
( T_1 ) V_34 -> V_127 . V_130 ) )
break;
F_78 ( V_34 ) ;
} else
F_3 ( L_67 , V_34 -> V_3 ) ;
}
}
static int
V_105 ( void * V_214 )
{
struct V_1 * V_39 = V_214 ;
struct V_208 * V_209 = & V_39 -> V_48 ;
struct V_33 * V_34 = NULL ;
const int V_215 = sizeof( struct V_33 ) ;
T_4 V_44 ;
unsigned long long V_45 ;
F_85 ( L_19 ) ;
V_34 = F_86 ( V_215 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_68 ) ;
F_87 ( & V_209 -> V_104 . V_216 , 0 ) ;
return 0 ;
}
V_44 = V_55 ;
while ( 1 ) {
F_88 ( V_39 -> V_62 ,
( F_50 ( & V_39 -> V_61 ) == 1 ) ,
F_89 ( V_116 ) ) ;
F_24 ( & V_39 -> V_61 , 0 ) ;
F_81 ( V_39 , V_209 , V_34 ) ;
V_45 = F_39 ( V_39 -> V_56 , V_44 ) ;
if ( V_209 -> V_104 . V_217 )
break;
}
F_14 ( V_34 ) ;
F_30 ( L_69 ) ;
F_87 ( & V_209 -> V_104 . V_216 , 0 ) ;
}
static T_8 F_90 ( struct V_218 * V_218 ,
char T_7 * V_199 , T_9 V_219 , T_10 * V_180 )
{
T_8 V_220 = 0 ;
int V_221 = 0 ;
T_4 V_222 ;
int V_27 ;
struct V_1 * V_39 ;
char * V_223 ;
if ( V_219 > V_224 )
V_219 = V_224 ;
V_223 = F_17 ( V_219 , V_225 ) ;
if ( ! V_223 )
return - V_226 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( V_95 [ V_27 ] . V_39 == NULL )
continue;
V_39 = V_95 [ V_27 ] . V_39 ;
V_221 += F_91 ( V_223 + V_221 ,
V_219 - V_221 , L_70 , V_176 ) ;
V_221 += F_91 ( V_223 + V_221 , V_219 - V_221 ,
L_71 ,
V_116 ) ;
V_221 += F_91 ( V_223 + V_221 , V_219 - V_221 ,
L_72 ,
V_39 -> V_47 ,
V_39 -> V_54 ) ;
V_221 += F_91 ( V_223 + V_221 ,
V_219 - V_221 , L_73 ,
V_39 -> V_58 ) ;
V_222 = F_92 ( ( V_227 void * )
V_39 -> V_56 ) ;
V_221 += F_91 ( V_223 + V_221 , V_219 - V_221 ,
L_74 ,
V_39 -> V_56 , V_222 ,
( V_228 ) F_20 ( V_39 -> V_56 ) ) ;
V_221 += F_91 ( V_223 + V_221 ,
V_219 - V_221 , L_75 ,
V_39 -> V_211 ) ;
V_221 += F_91 ( V_223 + V_221 , V_219 - V_221 , L_76 ) ;
}
V_220 = F_93 ( V_199 , V_219 , V_180 , V_223 , V_221 ) ;
F_14 ( V_223 ) ;
return V_220 ;
}
static T_8 F_94 ( struct V_218 * V_218 ,
const char T_7 * V_229 , T_9 V_230 , T_10 * V_231 )
{
char V_199 [ 4 ] ;
int V_27 , V_232 ;
struct V_1 * V_39 ;
T_4 T_3 * V_114 ;
T_4 V_44 ;
if ( V_230 >= F_95 ( V_199 ) )
return - V_161 ;
V_199 [ V_230 ] = '\0' ;
if ( F_96 ( V_199 , V_229 , V_230 ) ) {
F_3 ( L_77 ,
( int ) V_230 , V_199 , V_230 ) ;
return - V_233 ;
}
V_27 = F_97 ( V_199 , 10 , & V_232 ) ;
if ( V_27 != 0 ) {
F_3 ( L_78 ,
( int ) V_230 , V_199 ) ;
return - V_233 ;
}
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( V_95 [ V_27 ] . V_39 != NULL ) {
V_39 = V_95 [ V_27 ] . V_39 ;
V_114 =
& V_39 -> V_48 . V_49 -> V_50 -> V_51 ;
if ( V_232 == 1 ) {
V_44 = ~ ( V_103 |
V_53 ) ;
F_21 ( V_114 , V_44 ) ;
V_44 = V_115 ;
F_39 ( V_114 , V_44 ) ;
V_116 = 4000000 ;
} else {
V_44 = ~ ( V_115 |
V_53 ) ;
F_21 ( V_114 , V_44 ) ;
V_44 = V_103 ;
F_39 ( V_114 , V_44 ) ;
V_116 = 4000 ;
}
}
}
return V_230 ;
}
static int
F_98 ( struct V_64 * V_65 )
{
struct V_1 * V_39 =
(struct V_1 * ) ( (struct V_32 * ) V_65 -> V_78 .
V_67 ) -> V_93 ;
F_30 ( L_9 , V_65 -> V_70 ,
V_65 -> V_71 ) ;
if ( ! V_39 -> V_98 ) {
F_30 ( L_79 ) ;
return 1 ;
}
if ( V_39 -> V_99 ) {
F_3 ( L_80 ) ;
return 0 ;
}
V_39 -> V_99 = true ;
F_99 ( V_39 -> V_48 . V_49 -> V_50 ,
F_100 ( & V_65 -> V_90 ) ,
V_234 , NULL ) ;
if ( ! F_37 ( & V_39 -> V_48 . V_104 ,
V_105 ,
V_39 , L_19 ) ) {
F_3 ( L_20 ) ;
return 0 ;
}
V_39 -> V_98 = false ;
V_39 -> V_99 = false ;
return 1 ;
}
static void
V_102 ( struct V_24 * V_25 )
{
struct V_1 * V_39 ;
struct V_64 * V_65 ;
int V_27 ;
struct V_235 * V_236 = NULL ;
struct V_142 * V_130 = NULL ;
struct V_33 * V_34 ;
unsigned long V_5 ;
V_39 = F_101 ( V_25 , struct V_1 ,
V_101 ) ;
F_44 ( & V_39 -> V_48 . V_104 ) ;
F_2 ( & V_39 -> V_7 , V_5 ) ;
for ( V_27 = 0 ; V_27 < V_11 ; V_27 ++ ) {
V_236 = & ( V_39 -> V_9 [ V_27 ] ) ;
switch ( V_236 -> V_3 ) {
case V_170 :
V_130 = (struct V_142 * ) V_236 -> V_10 ;
V_130 -> V_135 = ( V_237 << 16 ) ;
if ( V_130 -> V_171 )
V_130 -> V_171 ( V_130 ) ;
break;
case V_141 :
V_34 = (struct V_33 * ) V_236 -> V_10 ;
F_30 ( L_81 , V_34 ,
V_34 -> V_134 . V_128 ) ;
* ( int * ) V_34 -> V_134 . V_122 =
V_238 ;
F_79 ( ( T_6 * )
V_34 -> V_134 . V_128 ) ;
break;
case V_126 :
V_34 = (struct V_33 * ) V_236 -> V_10 ;
* ( int * ) V_34 -> V_127 . V_122 =
V_239 ;
F_79 ( ( T_6 * )
V_34 -> V_127 . V_128 ) ;
break;
default:
if ( V_236 -> V_10 != NULL )
F_3 ( L_82 ,
V_236 -> V_3 ) ;
}
V_236 -> V_3 = 0 ;
V_236 -> V_10 = NULL ;
}
F_4 ( & V_39 -> V_7 , V_5 ) ;
V_65 = V_39 -> V_65 ;
F_30 ( L_9 , V_65 -> V_70 ,
V_65 -> V_71 ) ;
V_39 -> V_98 = true ;
V_39 -> V_99 = false ;
F_102 ( V_65 -> V_70 ,
V_65 -> V_71 , 0 ) ;
}
static int
F_103 ( struct V_64 * V_65 , T_11 V_240 )
{
struct V_1 * V_39 =
(struct V_1 * ) ( (struct V_32 * ) V_65 -> V_78 .
V_67 ) -> V_93 ;
F_30 ( L_83 ) ;
F_30 ( L_9 , V_65 -> V_70 ,
V_65 -> V_71 ) ;
if ( ! V_39 -> V_98 && ! V_39 -> V_99 ) {
V_39 -> V_99 = true ;
F_104 ( V_241 ,
& V_39 -> V_101 ) ;
} else if ( V_39 -> V_99 ) {
F_3 ( L_80 ) ;
return 0 ;
} else
F_3 ( L_84 ) ;
return 1 ;
}
static int T_12
F_105 ( char * V_242 )
{
F_30 ( L_85 , V_242 ) ;
return 1 ;
}
static void T_12
F_106 ( char * line )
{
char * V_31 = line ;
F_29 ( V_243 , V_73 ) ;
if ( line == NULL || ! * line )
return;
while ( ( line = V_31 ) != NULL ) {
V_31 = strchr ( line , ' ' ) ;
if ( V_31 != NULL )
* V_31 ++ = 0 ;
if ( ! F_105 ( line ) )
F_30 ( L_86 , line ) ;
}
F_29 ( V_244 , V_73 ) ;
}
static int T_12
F_107 ( void )
{
int error ;
int V_27 ;
if ( ! V_245 )
return - V_75 ;
F_28 ( L_87 ) ;
F_29 ( V_243 , V_73 ) ;
F_106 ( V_246 ) ;
error = F_108 ( & V_247 ) ;
if ( error < 0 ) {
F_3 ( L_88 , error ) ;
F_109 ( V_248 , error ,
V_92 ) ;
} else {
V_249 = F_110 ( L_89 , NULL ) ;
F_111 ( L_90 , V_250 , V_249 ,
NULL , & V_251 ) ;
F_112 ( L_91 , V_250 | V_252 ,
V_249 , & V_116 ) ;
F_111 ( L_92 , V_252 ,
V_249 , NULL ,
& V_253 ) ;
F_36 ( & V_254 , F_15 ) ;
F_34 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ )
V_95 [ V_27 ] . V_39 = NULL ;
V_241 =
F_113 ( L_83 ) ;
if ( V_241 == NULL ) {
F_3 ( L_93 ) ;
F_29 ( V_248 ,
V_92 ) ;
error = - 1 ;
}
}
F_29 ( V_244 , V_73 ) ;
F_28 ( L_94 ) ;
return error ;
}
static T_8
F_114 ( struct V_145 * V_255 , struct V_256 * V_257 ,
const char * V_199 , T_9 V_230 )
{
struct V_120 V_121 ;
struct V_32 * V_18 = F_115 ( V_255 ) ;
int V_27 ;
V_27 = sscanf ( V_199 , L_95 , & V_121 . V_19 , & V_121 . V_20 , & V_121 . V_21 ) ;
if ( V_27 != 3 )
return V_27 ;
return F_45 ( V_258 , V_18 , & V_121 ) ;
}
static T_8
F_116 ( struct V_145 * V_255 , struct V_256 * V_257 ,
const char * V_199 , T_9 V_230 )
{
struct V_120 V_121 ;
struct V_32 * V_18 = F_115 ( V_255 ) ;
int V_27 ;
V_27 = sscanf ( V_199 , L_95 , & V_121 . V_19 , & V_121 . V_20 , & V_121 . V_21 ) ;
if ( V_27 != 3 )
return V_27 ;
return F_45 ( V_259 , V_18 , & V_121 ) ;
}
static void T_13
F_117 ( void )
{
F_28 ( L_96 ) ;
F_118 ( & V_247 ) ;
if ( V_241 ) {
F_119 ( V_241 ) ;
V_241 = NULL ;
}
F_120 ( V_249 ) ;
F_28 ( L_97 ) ;
}
