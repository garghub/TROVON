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
V_15 = F_17 ( sizeof( * V_15 ) , V_35 ) ;
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
struct V_40 T_3 * V_40 ;
struct V_41 T_3 * V_42 ;
T_4 V_43 ;
unsigned long long V_44 ;
if ( V_39 == NULL )
return V_45 ;
V_39 -> V_46 ++ ;
V_40 = V_39 -> V_47 . V_48 -> V_49 ;
if ( ( ( F_20 ( & V_40 -> V_50 )
& V_51 ) != 0 ) &&
( ( F_20 ( & V_40 -> V_50 ) &
V_52 ) !=
0 ) ) {
V_39 -> V_53 ++ ;
V_43 = ~ V_54 ;
V_44 = F_21 ( V_39 -> V_55 , V_43 ) ;
}
if ( F_22 ( V_40 , V_56 ) ) {
V_39 -> V_57 ++ ;
return V_45 ;
}
V_42 = (struct V_41 T_3 * )
( ( char T_3 * ) V_40 +
F_20 ( & V_40 -> V_58 ) ) + V_56 ;
F_23 ( F_20 ( & V_42 -> V_59 ) + 1 ,
& V_42 -> V_59 ) ;
F_24 ( & V_39 -> V_60 , 1 ) ;
F_25 ( & V_39 -> V_61 ) ;
return V_62 ;
}
static int
F_26 ( struct V_63 * V_64 , const struct V_65 * V_20 )
{
int error ;
struct V_32 * V_66 ;
struct V_1 * V_39 ;
int V_67 ;
int V_27 ;
T_5 V_68 = F_19 ;
struct V_40 T_3 * V_40 ;
struct V_41 T_3 * V_42 ;
T_4 V_43 ;
F_27 ( L_8 ) ;
F_27 ( L_9 , V_64 -> V_69 ,
V_64 -> V_70 ) ;
F_28 ( L_8 ) ;
F_28 ( L_9 , V_64 -> V_69 ,
V_64 -> V_70 ) ;
F_29 ( V_71 , V_72 ) ;
F_30 ( L_10 ) ;
V_66 = F_31 ( & V_73 ,
sizeof( struct V_1 ) ) ;
if ( V_66 == NULL )
return - V_74 ;
F_30 ( L_11 ,
V_66 , V_66 -> V_75 , V_66 -> V_23 ) ;
V_66 -> V_75 = V_76 ;
F_28 ( L_12 ,
( unsigned ) V_64 -> V_77 . V_78 . V_79 - 1 ,
( unsigned ) V_64 -> V_77 . V_78 . V_80 ,
( unsigned ) V_64 -> V_77 . V_78 . V_81 ,
( unsigned ) V_64 -> V_77 . V_78 . V_82 ,
( unsigned ) V_64 -> V_77 . V_78 . V_83 ) ;
V_66 -> V_79 = ( unsigned ) V_64 -> V_77 . V_78 . V_79 ;
V_66 -> V_80 = ( unsigned ) V_64 -> V_77 . V_78 . V_80 ;
V_66 -> V_81 = ( unsigned ) V_64 -> V_77 . V_78 . V_81 ;
V_66 -> V_82 = ( unsigned ) V_64 -> V_77 . V_78 . V_82 ;
V_66 -> V_84 =
( unsigned short ) ( V_64 -> V_77 . V_78 . V_83 >> 9 ) ;
V_66 -> V_85 =
( unsigned short ) ( V_64 -> V_77 . V_78 . V_83 / V_86 ) ;
if ( V_66 -> V_85 > V_87 )
V_66 -> V_85 = V_87 ;
F_28 ( L_13 ,
V_66 -> V_79 , V_66 -> V_80 , V_66 -> V_81 ,
V_66 -> V_82 , V_66 -> V_84 ,
V_66 -> V_85 ) ;
F_28 ( L_14 ,
V_66 -> V_88 , V_66 -> V_82 , V_66 -> V_84 ,
V_66 -> V_85 ) ;
F_30 ( L_15 ) ;
error = F_32 ( V_66 , & V_64 -> V_89 ) ;
if ( error ) {
F_3 ( L_16 , error ) ;
F_29 ( V_90 , V_91 ) ;
F_33 ( V_66 ) ;
return - V_74 ;
}
V_39 = (struct V_1 * ) V_66 -> V_92 ;
memset ( V_39 , 0 , sizeof( struct V_1 ) ) ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_94 [ V_27 ] . V_39 == NULL ) {
V_94 [ V_27 ] . V_39 = V_39 ;
break;
}
}
V_39 -> V_95 = - 1 ;
V_39 -> V_47 . V_48 = & V_64 -> V_48 ;
V_39 -> V_64 = V_64 ;
F_34 ( & V_39 -> V_47 . V_96 ) ;
F_30 ( L_17 ,
& V_64 -> V_89 , & V_64 -> V_48 ) ;
F_35 ( & V_39 -> V_61 ) ;
F_34 ( & V_39 -> V_7 ) ;
memset ( & V_39 -> V_9 , 0 , sizeof( V_39 -> V_9 ) ) ;
V_39 -> V_97 = false ;
V_39 -> V_98 = false ;
V_39 -> V_99 = V_64 -> V_99 ;
V_39 -> V_66 = V_66 ;
V_64 -> V_77 . V_66 = V_66 ;
F_36 ( & V_39 -> V_100 ,
V_101 ) ;
F_23 ( F_20 ( & V_39 -> V_47 . V_48 -> V_49 -> V_50 ) |
V_102 ,
& V_39 -> V_47 . V_48 -> V_49 -> V_50 ) ;
F_30 ( L_18 ,
V_39 -> V_47 . V_48 , & V_39 -> V_47 . V_103 ) ;
V_40 = V_39 -> V_47 . V_48 -> V_49 ;
V_42 = (struct V_41 T_3 * )
( ( char T_3 * ) V_40 +
F_20 ( & V_40 -> V_58 ) ) + V_56 ;
V_39 -> V_55 = & V_42 -> V_50 ;
if ( ! F_37 ( & V_39 -> V_47 . V_103 ,
V_104 ,
V_39 , L_19 ) ) {
F_3 ( L_20 ) ;
F_29 ( V_90 , V_91 ) ;
F_33 ( V_66 ) ;
return - V_74 ;
}
F_28 ( L_21 ,
V_39 -> V_99 . V_105 ) ;
F_28 ( L_22 ,
V_39 -> V_99 . V_106 ) ;
F_28 ( L_23 ,
V_39 -> V_99 . V_107 ) ;
F_28 ( L_24 ,
V_39 -> V_99 . V_108 ) ;
F_28 ( L_25 , V_66 -> V_109 -> V_110 ) ;
V_39 -> V_95 =
V_39 -> V_99 . V_106 & V_111 ;
V_67 = F_38 ( V_39 -> V_95 , V_68 , V_112 ,
V_66 -> V_109 -> V_110 , V_39 ) ;
if ( V_67 != 0 ) {
F_3 ( L_26 ,
V_39 -> V_95 , V_67 ) ;
V_39 -> V_95 = - 1 ;
F_29 ( V_90 , V_91 ) ;
} else {
T_4 T_3 * V_113 =
& V_39 -> V_47 . V_48 -> V_49 -> V_50 ;
F_3 ( L_27 ,
V_39 -> V_95 ) ;
V_43 = ~ ( V_102 |
V_52 ) ;
F_21 ( V_113 , V_43 ) ;
V_43 = V_114 ;
F_39 ( V_113 , V_43 ) ;
V_115 = 4000000 ;
}
F_30 ( L_28 ) ;
F_40 ( V_66 ) ;
F_30 ( L_29 ) ;
F_28 ( L_30 , V_66 ) ;
F_29 ( V_116 , V_72 ) ;
return 0 ;
}
static void
F_41 ( struct V_63 * V_64 )
{
struct V_1 * V_39 ;
struct V_32 * V_66 =
(struct V_32 * ) V_64 -> V_77 . V_66 ;
F_28 ( L_9 , V_64 -> V_69 ,
V_64 -> V_70 ) ;
V_39 = (struct V_1 * ) V_66 -> V_92 ;
if ( V_39 -> V_95 != - 1 )
F_42 ( V_39 -> V_95 , V_39 ) ;
F_28 ( L_31 , V_64 ,
V_39 ) ;
F_30 ( L_32 , V_66 ,
V_66 -> V_75 ) ;
F_43 ( V_66 ) ;
F_30 ( L_33 ) ;
F_44 ( & V_39 -> V_47 . V_103 ) ;
F_30 ( L_34 ) ;
F_33 ( V_66 ) ;
F_28 ( L_35 ) ;
}
static int
F_45 ( enum V_117 V_118 ,
struct V_32 * V_66 ,
struct V_119 * V_120 )
{
struct V_33 * V_34 ;
struct V_1 * V_39 =
(struct V_1 * ) V_66 -> V_92 ;
int V_121 = 0xffff ;
T_6 V_122 ;
F_28 ( L_36 , V_118 ,
V_120 -> V_19 , V_120 -> V_20 , V_120 -> V_21 ) ;
if ( V_39 -> V_97 || V_39 -> V_98 ) {
F_30 ( L_37 ) ;
return V_123 ;
}
V_34 = F_17 ( V_124 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return V_123 ;
}
F_35 ( & V_122 ) ;
V_34 -> V_3 = V_125 ;
V_34 -> V_126 . V_127 = ( void * ) & V_122 ;
V_34 -> V_126 . V_121 = ( void * ) & V_121 ;
V_34 -> V_126 . V_128 = V_118 ;
V_34 -> V_126 . V_120 . V_19 = V_120 -> V_19 ;
V_34 -> V_126 . V_120 . V_20 = V_120 -> V_20 ;
V_34 -> V_126 . V_120 . V_21 = V_120 -> V_21 ;
V_34 -> V_126 . V_129 =
( void * ) ( T_1 )
F_5 ( V_39 , V_125 ,
( void * ) V_34 ) ;
F_46 ( V_39 -> V_47 . V_48 ,
V_34 , V_130 ,
& V_39 -> V_47 . V_96 ,
V_131 , ( T_4 ) NULL ,
V_132 , L_39 ) ;
F_28 ( L_40 ,
V_34 -> V_133 . V_127 ) ;
F_47 ( V_122 , V_121 != 0xffff ) ;
F_28 ( L_41 , V_34 -> V_126 . V_134 ) ;
F_14 ( V_34 ) ;
return V_135 ;
}
static int
F_48 ( enum V_136 V_137 ,
struct V_16 * V_138 )
{
struct V_33 * V_34 ;
struct V_1 * V_39 =
(struct V_1 * ) V_138 -> V_139 -> V_92 ;
int V_121 = 0xffff ;
T_6 V_122 ;
F_28 ( L_42 , V_137 ,
V_138 -> V_19 , V_138 -> V_20 , V_138 -> V_21 ) ;
if ( V_39 -> V_97 || V_39 -> V_98 ) {
F_30 ( L_37 ) ;
return V_123 ;
}
V_34 = F_17 ( V_124 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return V_123 ;
}
F_35 ( & V_122 ) ;
V_34 -> V_3 = V_140 ;
V_34 -> V_133 . V_127 = ( void * ) & V_122 ;
V_34 -> V_133 . V_121 = ( void * ) & V_121 ;
V_34 -> V_133 . V_137 = V_137 ;
V_34 -> V_133 . V_120 . V_19 = V_138 -> V_19 ;
V_34 -> V_133 . V_120 . V_20 = V_138 -> V_20 ;
V_34 -> V_133 . V_120 . V_21 = V_138 -> V_21 ;
V_34 -> V_133 . V_129 =
( void * ) ( T_1 )
F_5 ( V_39 ,
V_140 ,
( void * ) V_34 ) ;
F_46 ( V_39 -> V_47 . V_48 ,
V_34 , V_130 ,
& V_39 -> V_47 . V_96 ,
V_131 , ( T_4 ) NULL ,
V_132 , L_39 ) ;
F_28 ( L_43 ,
V_34 -> V_133 . V_127 ) ;
F_47 ( V_122 , V_121 != 0xffff ) ;
F_28 ( L_44 , V_34 -> V_133 . V_134 ) ;
F_14 ( V_34 ) ;
return V_135 ;
}
static int
F_49 ( struct V_141 * V_129 )
{
struct V_16 * V_138 ;
struct V_142 * V_143 ;
V_138 = V_129 -> V_144 ;
for ( V_143 = & ( (struct V_1 * ) V_138 -> V_139 -> V_92 ) -> V_145 ;
V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( ( V_138 -> V_19 == V_143 -> V_19 ) &&
( V_138 -> V_20 == V_143 -> V_20 ) &&
( V_138 -> V_21 == V_143 -> V_21 ) ) {
if ( F_50 ( & V_143 -> V_146 ) <
V_147 ) {
F_51 ( & V_143 -> V_146 ) ;
F_29 ( V_148 ,
V_72 ) ;
} else
F_24 ( & V_143 -> V_149 ,
V_150 ) ;
}
}
return F_48 ( V_151 , V_129 -> V_144 ) ;
}
static int
F_52 ( struct V_141 * V_129 )
{
struct V_16 * V_138 ;
struct V_142 * V_143 ;
V_138 = V_129 -> V_144 ;
for ( V_143 = & ( (struct V_1 * ) V_138 -> V_139 -> V_92 ) -> V_145 ;
V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( ( V_138 -> V_19 == V_143 -> V_19 ) &&
( V_138 -> V_20 == V_143 -> V_20 ) &&
( V_138 -> V_21 == V_143 -> V_21 ) ) {
if ( F_50 ( & V_143 -> V_146 ) <
V_147 ) {
F_51 ( & V_143 -> V_146 ) ;
F_29 ( V_148 ,
V_72 ) ;
} else
F_24 ( & V_143 -> V_149 ,
V_150 ) ;
}
}
return F_48 ( V_152 , V_129 -> V_144 ) ;
}
static int
F_53 ( struct V_141 * V_129 )
{
struct V_16 * V_138 ;
struct V_142 * V_143 ;
V_138 = V_129 -> V_144 ;
for ( V_143 = & ( (struct V_1 * ) V_138 -> V_139 -> V_92 ) -> V_145 ;
V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( ( V_138 -> V_19 == V_143 -> V_19 ) &&
( V_138 -> V_20 == V_143 -> V_20 ) &&
( V_138 -> V_21 == V_143 -> V_21 ) ) {
if ( F_50 ( & V_143 -> V_146 ) <
V_147 ) {
F_51 ( & V_143 -> V_146 ) ;
F_29 ( V_148 ,
V_72 ) ;
} else
F_24 ( & V_143 -> V_149 ,
V_150 ) ;
}
}
return F_48 ( V_153 , V_129 -> V_144 ) ;
}
static int
F_54 ( struct V_141 * V_129 )
{
F_3 ( L_45 ) ;
return V_135 ;
}
static const char *
F_55 ( struct V_32 * V_154 )
{
sprintf ( V_155 , L_46 , V_156 ) ;
return V_155 ;
}
static int
F_56 ( struct V_16 * V_157 , int V_158 , void T_7 * V_159 )
{
F_30 ( L_47 , V_158 ) ;
return - V_160 ;
}
static int
F_57 ( struct V_141 * V_129 ,
void (* F_58)( struct V_141 * ) )
{
struct V_16 * V_138 = V_129 -> V_144 ;
int V_6 ;
unsigned char V_161 ;
unsigned char * V_162 = V_129 -> V_163 ;
struct V_32 * V_66 = V_138 -> V_139 ;
struct V_33 * V_34 ;
unsigned int V_27 ;
struct V_1 * V_39 =
(struct V_1 * ) V_66 -> V_92 ;
struct V_164 * V_165 = NULL ;
struct V_164 * V_166 = NULL ;
int V_167 = 0 ;
if ( V_39 -> V_97 || V_39 -> V_98 ) {
F_30 ( L_48 ) ;
return V_168 ;
}
V_34 = F_17 ( V_124 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return 1 ;
}
V_34 -> V_3 = V_169 ;
V_6 =
F_1 ( V_39 , V_169 , ( void * ) V_129 ) ;
if ( V_6 != - 1 ) {
V_34 -> V_77 . V_129 = ( void * ) ( T_1 ) V_6 ;
} else {
F_3 ( L_49 ) ;
F_14 ( V_34 ) ;
return V_168 ;
}
V_129 -> V_170 = F_58 ;
V_34 -> V_77 . V_120 . V_19 = V_138 -> V_19 ;
V_34 -> V_77 . V_120 . V_20 = V_138 -> V_20 ;
V_34 -> V_77 . V_120 . V_21 = V_138 -> V_21 ;
V_34 -> V_77 . V_171 = V_129 -> V_172 ;
memcpy ( V_34 -> V_77 . V_163 , V_162 , V_173 ) ;
V_34 -> V_77 . V_174 = F_59 ( V_129 ) ;
if ( V_34 -> V_77 . V_174 > V_175 )
V_175 = V_34 -> V_77 . V_174 ;
if ( F_60 ( V_129 ) > V_87 ) {
F_3 ( L_50 ,
F_60 ( V_129 ) , V_87 ) ;
F_9 ( V_39 , ( T_1 ) V_6 ) ;
F_14 ( V_34 ) ;
return 1 ;
}
if ( F_60 ( V_129 ) == 0 ) {
if ( F_59 ( V_129 ) > 0 ) {
F_3 ( L_51 ) ;
F_61 ( F_60 ( V_129 ) == 0 ) ;
}
F_30 ( L_52 ,
F_62 ( V_129 ) , F_59 ( V_129 ) ) ;
} else {
V_166 = F_62 ( V_129 ) ;
F_63 (sgl, sg, scsi_sg_count(scsicmd), i) {
V_34 -> V_77 . V_176 [ V_27 ] . V_177 = F_64 ( V_165 ) ;
V_34 -> V_77 . V_176 [ V_27 ] . V_178 = V_165 -> V_178 ;
if ( ( V_27 != 0 ) && ( V_165 -> V_179 != 0 ) )
F_28 ( L_53 ,
V_165 -> V_179 ) ;
}
if ( V_167 ) {
F_3 ( L_54 ,
F_60 ( V_129 ) , V_34 -> V_77 . V_174 ) ;
F_63 (sgl, sg, scsi_sg_count(scsicmd), i) {
F_3 ( L_55 ,
V_27 , F_65 ( V_165 ) ,
( unsigned long long ) F_64 ( V_165 ) ,
V_165 -> V_179 , V_165 -> V_178 ) ;
}
F_3 ( L_56 ) ;
}
V_34 -> V_77 . V_180 = F_60 ( V_129 ) ;
}
V_161 = V_162 [ 0 ] ;
V_27 = F_46 ( V_39 -> V_47 . V_48 ,
V_34 , V_130 ,
& V_39 -> V_47 .
V_96 ,
V_131 ,
( T_4 ) NULL , V_181 , L_39 ) ;
if ( V_27 == 0 ) {
F_3 ( L_57 ) ;
F_14 ( V_34 ) ;
F_9 ( V_39 , ( T_1 ) V_6 ) ;
return V_168 ;
}
F_14 ( V_34 ) ;
return 0 ;
}
static int
F_66 ( struct V_16 * V_138 )
{
struct V_142 * V_143 ;
struct V_142 * V_182 ;
struct V_1 * V_39 ;
struct V_32 * V_66 = (struct V_32 * ) V_138 -> V_139 ;
V_39 = (struct V_1 * ) V_66 -> V_92 ;
if ( ! V_39 ) {
F_3 ( L_58 ) ;
return 0 ;
}
for ( V_143 = & V_39 -> V_145 ; V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( V_143 -> V_31 -> V_183 &&
( V_143 -> V_31 -> V_19 == V_138 -> V_19 ) &&
( V_143 -> V_31 -> V_20 == V_138 -> V_20 ) &&
( V_143 -> V_31 -> V_21 == V_138 -> V_21 ) )
return 0 ;
}
V_182 = F_17 ( sizeof( * V_182 ) , V_35 ) ;
if ( ! V_182 ) {
F_3 ( L_59 ) ;
return 0 ;
}
V_182 -> V_19 = V_138 -> V_19 ;
V_182 -> V_20 = V_138 -> V_20 ;
V_182 -> V_21 = V_138 -> V_21 ;
V_182 -> V_183 = 1 ;
V_143 -> V_31 = V_182 ;
return 0 ;
}
static int
F_67 ( struct V_16 * V_138 )
{
return 0 ;
}
static void
F_68 ( struct V_16 * V_138 )
{
struct V_142 * V_143 , * V_184 ;
struct V_1 * V_39 ;
struct V_32 * V_66 = (struct V_32 * ) V_138 -> V_139 ;
V_39 = (struct V_1 * ) V_66 -> V_92 ;
if ( ! V_39 )
F_3 ( L_58 ) ;
for ( V_143 = & V_39 -> V_145 ; V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( V_143 -> V_31 -> V_183 &&
( V_143 -> V_31 -> V_19 == V_138 -> V_19 ) &&
( V_143 -> V_31 -> V_20 == V_138 -> V_20 ) &&
( V_143 -> V_31 -> V_21 == V_138 -> V_21 ) ) {
V_184 = V_143 -> V_31 ;
V_143 -> V_31 = V_143 -> V_31 -> V_31 ;
F_14 ( V_184 ) ;
return;
}
}
}
static void
F_69 ( struct V_33 * V_34 , struct V_141 * V_129 )
{
struct V_142 * V_143 ;
struct V_16 * V_138 ;
struct V_185 * V_186 ;
V_138 = V_129 -> V_144 ;
memcpy ( V_129 -> V_187 , V_34 -> V_77 . V_188 , V_189 ) ;
V_186 = (struct V_185 * ) V_129 -> V_187 ;
if ( ( V_34 -> V_77 . V_163 [ 0 ] == V_190 ) &&
( F_70 ( V_34 -> V_77 . V_191 ) == V_192 ) &&
( V_34 -> V_77 . V_193 == V_194 ) )
return;
for ( V_143 = & ( (struct V_1 * ) V_138 -> V_139 -> V_92 ) -> V_145 ;
V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( ( V_138 -> V_19 != V_143 -> V_19 ) ||
( V_138 -> V_20 != V_143 -> V_20 ) ||
( V_138 -> V_21 != V_143 -> V_21 ) )
continue;
if ( F_50 ( & V_143 -> V_146 ) < V_147 ) {
F_51 ( & V_143 -> V_146 ) ;
F_3 ( L_60 ,
V_129 , V_34 -> V_77 . V_163 [ 0 ] ,
V_138 -> V_139 -> V_23 , V_138 -> V_20 ,
V_138 -> V_19 , V_138 -> V_21 ,
V_34 -> V_77 . V_191 , V_186 -> V_183 , V_186 -> V_195 ,
V_186 -> V_196 ,
V_186 -> V_197 ) ;
if ( F_50 ( & V_143 -> V_146 ) ==
V_147 ) {
F_3 ( L_61 ,
V_138 -> V_139 -> V_23 , V_138 -> V_20 ,
V_138 -> V_19 , V_138 -> V_21 ) ;
}
F_24 ( & V_143 -> V_149 , V_150 ) ;
}
}
}
static void
F_71 ( struct V_33 * V_34 , struct V_141 * V_129 )
{
struct V_16 * V_138 ;
unsigned char V_198 [ 36 ] ;
struct V_164 * V_165 ;
unsigned int V_27 ;
char * V_199 ;
char * V_200 ;
int V_201 = 0 ;
struct V_142 * V_143 ;
V_138 = V_129 -> V_144 ;
if ( ( V_34 -> V_77 . V_163 [ 0 ] == V_190 ) &&
( V_34 -> V_77 . V_174 >= V_202 ) ) {
if ( V_34 -> V_77 . V_203 == 0 )
return;
F_72 ( V_198 , V_34 -> V_77 . V_174 ,
V_138 -> V_21 ,
V_204 ,
V_205 ) ;
if ( F_60 ( V_129 ) == 0 ) {
if ( F_59 ( V_129 ) > 0 ) {
F_3 ( L_51 ) ;
F_61 ( F_60 ( V_129 ) ==
0 ) ;
}
memcpy ( F_62 ( V_129 ) , V_198 ,
V_34 -> V_77 . V_174 ) ;
return;
}
V_165 = F_62 ( V_129 ) ;
for ( V_27 = 0 ; V_27 < F_60 ( V_129 ) ; V_27 ++ ) {
F_73 ( L_62 ,
F_65 ( V_165 + V_27 ) , V_165 [ V_27 ] . V_178 ) ;
V_200 = F_74 ( F_65 ( V_165 + V_27 ) ) ;
V_199 = ( void * ) ( ( unsigned long ) V_200 |
V_165 [ V_27 ] . V_179 ) ;
memcpy ( V_199 , V_198 + V_201 , V_165 [ V_27 ] . V_178 ) ;
F_75 ( V_200 ) ;
V_201 += V_165 [ V_27 ] . V_178 ;
}
} else {
V_143 = & ( (struct V_1 * ) V_138 -> V_139 -> V_92 ) -> V_145 ;
for ( ; V_143 -> V_31 ; V_143 = V_143 -> V_31 ) {
if ( ( V_138 -> V_19 != V_143 -> V_19 ) ||
( V_138 -> V_20 != V_143 -> V_20 ) ||
( V_138 -> V_21 != V_143 -> V_21 ) )
continue;
if ( F_50 ( & V_143 -> V_149 ) > 0 ) {
F_76 ( & V_143 -> V_149 ) ;
if ( F_50 ( & V_143 -> V_149 ) == 0 ) {
F_3 ( L_63 ) ;
F_24 ( & V_143 -> V_146 , 0 ) ;
}
}
}
}
}
static void
F_77 ( struct V_33 * V_34 , struct V_141 * V_129 )
{
F_30 ( L_64 , V_34 , V_34 -> V_77 . V_206 ) ;
V_129 -> V_134 = V_34 -> V_77 . V_191 ;
if ( V_34 -> V_77 . V_191 )
F_69 ( V_34 , V_129 ) ;
else
F_71 ( V_34 , V_129 ) ;
if ( V_129 -> V_170 ) {
F_73 ( L_65 ) ;
V_129 -> V_170 ( V_129 ) ;
}
}
static inline void
F_78 ( struct V_33 * V_34 )
{
* ( int * ) V_34 -> V_126 . V_121 = V_34 -> V_126 . V_134 ;
F_79 ( ( T_6 * ) V_34 -> V_126 . V_127 ) ;
F_28 ( L_66 , V_34 -> V_126 . V_134 ) ;
}
static inline void
F_80 ( struct V_33 * V_34 )
{
* ( int * ) V_34 -> V_133 . V_121 =
V_34 -> V_133 . V_134 ;
F_79 ( ( T_6 * ) V_34 -> V_133 . V_127 ) ;
F_28 ( L_66 , V_34 -> V_133 . V_134 ) ;
}
static void
F_81 ( struct V_1 * V_39 , struct V_207 * V_208 ,
struct V_33 * V_34 )
{
unsigned long V_5 ;
int V_209 = 0 ;
struct V_141 * V_129 ;
struct V_32 * V_18 = V_39 -> V_66 ;
while ( 1 ) {
F_2 ( & V_39 -> V_47 . V_96 , V_5 ) ;
if ( ! F_82 ( V_208 -> V_48 -> V_49 ,
L_39 ) ) {
F_4 ( & V_39 -> V_47 . V_96 ,
V_5 ) ;
V_39 -> V_210 ++ ;
break;
}
V_209 = F_83 ( V_208 -> V_48 , V_34 ,
V_56 ) ;
F_84 ( V_208 -> V_48 -> V_49 , L_39 ) ;
F_4 ( & V_39 -> V_47 . V_96 , V_5 ) ;
if ( V_209 == 0 )
break;
if ( V_34 -> V_3 == V_169 ) {
V_129 = F_9 ( V_39 ,
( T_1 )
V_34 -> V_77 . V_129 ) ;
if ( ! V_129 )
break;
F_77 ( V_34 , V_129 ) ;
} else if ( V_34 -> V_3 == V_140 ) {
if ( ! F_9 ( V_39 ,
( T_1 ) V_34 -> V_133 . V_129 ) )
break;
F_80 ( V_34 ) ;
} else if ( V_34 -> V_3 == V_211 ) {
V_34 -> V_36 . V_212 = NULL ;
F_16 ( V_18 , V_34 ) ;
} else if ( V_34 -> V_3 == V_125 ) {
if ( ! F_9 ( V_39 ,
( T_1 )
V_34 -> V_126 . V_129 ) )
break;
F_78 ( V_34 ) ;
} else
F_3 ( L_67 , V_34 -> V_3 ) ;
}
}
static int
V_104 ( void * V_213 )
{
struct V_1 * V_39 = V_213 ;
struct V_207 * V_208 = & V_39 -> V_47 ;
struct V_33 * V_34 = NULL ;
const int V_214 = sizeof( struct V_33 ) ;
T_4 V_43 ;
unsigned long long V_44 ;
F_85 ( L_19 ) ;
V_34 = F_86 ( V_214 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_68 ) ;
F_87 ( & V_208 -> V_103 . V_215 , 0 ) ;
return 0 ;
}
V_43 = V_54 ;
while ( 1 ) {
F_88 ( V_39 -> V_61 ,
( F_50 ( & V_39 -> V_60 ) == 1 ) ,
F_89 ( V_115 ) ) ;
F_24 ( & V_39 -> V_60 , 0 ) ;
F_81 ( V_39 , V_208 , V_34 ) ;
V_44 = F_39 ( V_39 -> V_55 , V_43 ) ;
if ( V_208 -> V_103 . V_216 )
break;
}
F_14 ( V_34 ) ;
F_30 ( L_69 ) ;
F_87 ( & V_208 -> V_103 . V_215 , 0 ) ;
}
static T_8 F_90 ( struct V_217 * V_217 ,
char T_7 * V_198 , T_9 V_218 , T_10 * V_179 )
{
T_8 V_219 = 0 ;
int V_220 = 0 ;
T_4 V_221 ;
int V_27 ;
struct V_1 * V_39 ;
char * V_222 ;
if ( V_218 > V_223 )
V_218 = V_223 ;
V_222 = F_17 ( V_218 , V_224 ) ;
if ( ! V_222 )
return - V_225 ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_94 [ V_27 ] . V_39 == NULL )
continue;
V_39 = V_94 [ V_27 ] . V_39 ;
V_220 += F_91 ( V_222 + V_220 ,
V_218 - V_220 , L_70 ,
V_175 ) ;
V_220 += F_91 ( V_222 + V_220 , V_218 - V_220 ,
L_71 ,
V_115 ) ;
V_220 += F_91 ( V_222 + V_220 , V_218 - V_220 ,
L_72 ,
V_39 -> V_46 ,
V_39 -> V_53 ) ;
V_220 += F_91 ( V_222 + V_220 ,
V_218 - V_220 , L_73 ,
V_39 -> V_57 ) ;
V_221 = F_92 ( ( V_226 void * )
V_39 -> V_55 ) ;
V_220 += F_91 ( V_222 + V_220 , V_218 - V_220 ,
L_74 ,
V_39 -> V_55 , V_221 ,
( V_227 ) F_20 ( V_39 -> V_55 ) ) ;
V_220 += F_91 ( V_222 + V_220 ,
V_218 - V_220 , L_75 ,
V_39 -> V_210 ) ;
V_220 += F_91 ( V_222 + V_220 , V_218 - V_220 , L_76 ) ;
}
V_219 = F_93 ( V_198 , V_218 , V_179 , V_222 , V_220 ) ;
F_14 ( V_222 ) ;
return V_219 ;
}
static T_8 F_94 ( struct V_217 * V_217 , const char T_7 * V_228 ,
T_9 V_229 , T_10 * V_230 )
{
char V_198 [ 4 ] ;
int V_27 , V_231 ;
struct V_1 * V_39 ;
T_4 T_3 * V_232 ;
T_4 V_43 ;
if ( V_229 >= F_95 ( V_198 ) )
return - V_160 ;
V_198 [ V_229 ] = '\0' ;
if ( F_96 ( V_198 , V_228 , V_229 ) ) {
F_3 ( L_77 ,
( int ) V_229 , V_198 , V_229 ) ;
return - V_233 ;
}
V_27 = F_97 ( V_198 , 10 , & V_231 ) ;
if ( V_27 != 0 ) {
F_3 ( L_78 ,
( int ) V_229 , V_198 ) ;
return - V_233 ;
}
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
if ( V_94 [ V_27 ] . V_39 != NULL ) {
V_39 = V_94 [ V_27 ] . V_39 ;
V_232 =
& V_39 -> V_47 . V_48 -> V_49 -> V_50 ;
if ( V_231 == 1 ) {
V_43 = ~ ( V_102 |
V_52 ) ;
F_21 ( V_232 , V_43 ) ;
V_43 = V_114 ;
F_39 ( V_232 , V_43 ) ;
V_115 = 4000000 ;
} else {
V_43 = ~ ( V_114 |
V_52 ) ;
F_21 ( V_232 , V_43 ) ;
V_43 = V_102 ;
F_39 ( V_232 , V_43 ) ;
V_115 = 4000 ;
}
}
}
return V_229 ;
}
static int
F_98 ( struct V_63 * V_64 )
{
struct V_1 * V_39 =
(struct V_1 * ) ( (struct V_32 * ) V_64 -> V_77 .
V_66 ) -> V_92 ;
F_30 ( L_9 , V_64 -> V_69 ,
V_64 -> V_70 ) ;
if ( ! V_39 -> V_97 ) {
F_30 ( L_79 ) ;
return 1 ;
}
if ( V_39 -> V_98 ) {
F_3 ( L_80 ) ;
return 0 ;
}
V_39 -> V_98 = true ;
F_99 ( V_39 -> V_47 . V_48 -> V_49 ,
F_100 ( & V_64 -> V_89 ) ,
V_234 , NULL ) ;
if ( ! F_37 ( & V_39 -> V_47 . V_103 ,
V_104 ,
V_39 , L_19 ) ) {
F_3 ( L_20 ) ;
return 0 ;
}
V_39 -> V_97 = false ;
V_39 -> V_98 = false ;
return 1 ;
}
static void
V_101 ( struct V_24 * V_25 )
{
struct V_1 * V_39 ;
struct V_63 * V_64 ;
int V_27 ;
struct V_235 * V_236 = NULL ;
struct V_141 * V_129 = NULL ;
struct V_33 * V_34 ;
unsigned long V_5 ;
V_39 = F_101 ( V_25 , struct V_1 ,
V_100 ) ;
F_44 ( & V_39 -> V_47 . V_103 ) ;
F_2 ( & V_39 -> V_7 , V_5 ) ;
for ( V_27 = 0 ; V_27 < V_11 ; V_27 ++ ) {
V_236 = & V_39 -> V_9 [ V_27 ] ;
switch ( V_236 -> V_3 ) {
case V_169 :
V_129 = (struct V_141 * ) V_236 -> V_10 ;
V_129 -> V_134 = ( V_237 << 16 ) ;
if ( V_129 -> V_170 )
V_129 -> V_170 ( V_129 ) ;
break;
case V_140 :
V_34 = (struct V_33 * ) V_236 -> V_10 ;
F_30 ( L_81 , V_34 ,
V_34 -> V_133 . V_127 ) ;
* ( int * ) V_34 -> V_133 . V_121 =
V_238 ;
F_79 ( ( T_6 * )
V_34 -> V_133 . V_127 ) ;
break;
case V_125 :
V_34 = (struct V_33 * ) V_236 -> V_10 ;
* ( int * ) V_34 -> V_126 . V_121 =
V_239 ;
F_79 ( ( T_6 * )
V_34 -> V_126 . V_127 ) ;
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
V_64 = V_39 -> V_64 ;
F_30 ( L_9 , V_64 -> V_69 ,
V_64 -> V_70 ) ;
V_39 -> V_97 = true ;
V_39 -> V_98 = false ;
F_102 ( V_64 -> V_69 ,
V_64 -> V_70 , 0 ) ;
}
static int
F_103 ( struct V_63 * V_64 , T_11 V_240 )
{
int V_241 = 1 ;
struct V_1 * V_39 =
(struct V_1 * ) ( (struct V_32 * ) V_64 -> V_77 .
V_66 ) -> V_92 ;
F_30 ( L_83 ) ;
F_30 ( L_9 , V_64 -> V_69 ,
V_64 -> V_70 ) ;
if ( ! V_39 -> V_97 && ! V_39 -> V_98 ) {
V_39 -> V_98 = true ;
F_104 ( V_242 ,
& V_39 -> V_100 ) ;
} else if ( V_39 -> V_98 ) {
F_3 ( L_80 ) ;
V_241 = 0 ;
} else {
F_3 ( L_84 ) ;
}
return V_241 ;
}
static int T_12
F_105 ( char * V_243 )
{
F_30 ( L_85 , V_243 ) ;
return 1 ;
}
static void T_12
F_106 ( char * line )
{
char * V_31 = line ;
F_29 ( V_244 , V_72 ) ;
if ( line == NULL || ! * line )
return;
while ( ( line = V_31 ) != NULL ) {
V_31 = strchr ( line , ' ' ) ;
if ( V_31 != NULL )
* V_31 ++ = 0 ;
if ( ! F_105 ( line ) )
F_30 ( L_86 , line ) ;
}
F_29 ( V_245 , V_72 ) ;
}
static int T_12
F_107 ( void )
{
int error ;
int V_27 ;
if ( ! V_246 )
return - V_74 ;
F_28 ( L_87 ) ;
F_29 ( V_244 , V_72 ) ;
F_106 ( V_247 ) ;
error = F_108 ( & V_248 ) ;
if ( error < 0 ) {
F_3 ( L_88 , error ) ;
F_109 ( V_249 , error ,
V_91 ) ;
} else {
V_250 = F_110 ( L_89 , NULL ) ;
F_111 ( L_90 , V_251 , V_250 ,
NULL , & V_252 ) ;
F_112 ( L_91 , V_251 | V_253 ,
V_250 , & V_115 ) ;
F_111 ( L_92 , V_253 ,
V_250 , NULL ,
& V_254 ) ;
F_36 ( & V_255 , F_15 ) ;
F_34 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ )
V_94 [ V_27 ] . V_39 = NULL ;
V_242 =
F_113 ( L_83 ) ;
if ( V_242 == NULL ) {
F_3 ( L_93 ) ;
F_29 ( V_249 ,
V_91 ) ;
error = - 1 ;
}
}
F_29 ( V_245 , V_72 ) ;
F_28 ( L_94 ) ;
return error ;
}
static T_8
F_114 ( struct V_144 * V_256 , struct V_257 * V_258 ,
const char * V_198 , T_9 V_229 )
{
struct V_119 V_120 ;
struct V_32 * V_18 = F_115 ( V_256 ) ;
int V_27 ;
V_27 = sscanf ( V_198 , L_95 , & V_120 . V_19 , & V_120 . V_20 , & V_120 . V_21 ) ;
if ( V_27 != 3 )
return V_27 ;
return F_45 ( V_259 , V_18 , & V_120 ) ;
}
static T_8
F_116 ( struct V_144 * V_256 , struct V_257 * V_258 ,
const char * V_198 , T_9 V_229 )
{
struct V_119 V_120 ;
struct V_32 * V_18 = F_115 ( V_256 ) ;
int V_27 ;
V_27 = sscanf ( V_198 , L_95 , & V_120 . V_19 , & V_120 . V_20 , & V_120 . V_21 ) ;
if ( V_27 != 3 )
return V_27 ;
return F_45 ( V_260 , V_18 , & V_120 ) ;
}
static void T_13
F_117 ( void )
{
F_28 ( L_96 ) ;
F_118 ( & V_248 ) ;
if ( V_242 ) {
F_119 ( V_242 ) ;
V_242 = NULL ;
}
F_120 ( V_250 ) ;
F_28 ( L_97 ) ;
}
