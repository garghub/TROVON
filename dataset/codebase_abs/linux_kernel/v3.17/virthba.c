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
T_3 T_4 * V_40 ;
T_5 T_4 * V_41 ;
T_6 V_42 ;
unsigned long long V_43 ;
if ( V_39 == NULL )
return V_44 ;
V_39 -> V_45 ++ ;
V_40 = V_39 -> V_46 . V_47 -> V_48 ;
if ( ( ( F_20 ( & V_40 -> V_49 )
& V_50 ) != 0 )
&& ( ( F_20 ( & V_40 -> V_49 ) &
V_51 ) !=
0 ) ) {
V_39 -> V_52 ++ ;
V_42 = ~ V_53 ;
V_43 = F_21 ( V_39 -> V_54 , V_42 ) ;
}
if ( F_22 ( V_40 , V_55 ) ) {
V_39 -> V_56 ++ ;
return V_44 ;
}
V_41 = ( T_5 T_4 * )
( ( char T_4 * ) V_40 +
F_20 ( & V_40 -> V_57 ) ) + V_55 ;
F_23 ( F_20 ( & V_41 -> V_58 ) + 1 ,
& V_41 -> V_58 ) ;
F_24 ( & V_39 -> V_59 , 1 ) ;
F_25 ( & V_39 -> V_60 ) ;
return V_61 ;
}
static int
F_26 ( struct V_62 * V_63 , const struct V_64 * V_20 )
{
int error ;
struct V_32 * V_65 ;
struct V_1 * V_39 ;
int V_66 ;
int V_27 ;
T_7 V_67 = F_19 ;
T_3 T_4 * V_40 ;
T_5 T_4 * V_41 ;
T_6 V_42 ;
F_27 ( L_8 ) ;
F_27 ( L_9 , V_63 -> V_68 ,
V_63 -> V_69 ) ;
F_28 ( L_8 ) ;
F_28 ( L_9 , V_63 -> V_68 ,
V_63 -> V_69 ) ;
F_29 ( V_70 , V_71 ) ;
F_30 ( L_10 ) ;
V_65 = F_31 ( & V_72 ,
sizeof( struct V_1 ) ) ;
if ( V_65 == NULL )
return - V_73 ;
F_30 ( L_11 ,
V_65 , V_65 -> V_74 , V_65 -> V_23 ) ;
V_65 -> V_74 = V_75 ;
F_28 ( L_12 ,
( unsigned ) V_63 -> V_76 . V_77 . V_78 - 1 ,
( unsigned ) V_63 -> V_76 . V_77 . V_79 ,
( unsigned ) V_63 -> V_76 . V_77 . V_80 ,
( unsigned ) V_63 -> V_76 . V_77 . V_81 ,
( unsigned ) V_63 -> V_76 . V_77 . V_82 ) ;
V_65 -> V_78 = ( unsigned ) V_63 -> V_76 . V_77 . V_78 ;
V_65 -> V_79 = ( unsigned ) V_63 -> V_76 . V_77 . V_79 ;
V_65 -> V_80 = ( unsigned ) V_63 -> V_76 . V_77 . V_80 ;
V_65 -> V_81 = ( unsigned ) V_63 -> V_76 . V_77 . V_81 ;
V_65 -> V_83 =
( unsigned short ) ( V_63 -> V_76 . V_77 . V_82 >> 9 ) ;
V_65 -> V_84 =
( unsigned short ) ( V_63 -> V_76 . V_77 . V_82 / V_85 ) ;
if ( V_65 -> V_84 > V_86 )
V_65 -> V_84 = V_86 ;
F_28 ( L_13 ,
V_65 -> V_78 , V_65 -> V_79 , V_65 -> V_80 ,
V_65 -> V_81 , V_65 -> V_83 ,
V_65 -> V_84 ) ;
F_28 ( L_14 ,
V_65 -> V_87 , V_65 -> V_81 , V_65 -> V_83 ,
V_65 -> V_84 ) ;
F_30 ( L_15 ) ;
error = F_32 ( V_65 , & V_63 -> V_88 ) ;
if ( error ) {
F_3 ( L_16 , error ) ;
F_29 ( V_89 , V_90 ) ;
F_33 ( V_65 ) ;
return - V_73 ;
}
V_39 = (struct V_1 * ) V_65 -> V_91 ;
memset ( V_39 , 0 , sizeof( struct V_1 ) ) ;
for ( V_27 = 0 ; V_27 < V_92 ; V_27 ++ ) {
if ( V_93 [ V_27 ] . V_39 == NULL ) {
V_93 [ V_27 ] . V_39 = V_39 ;
break;
}
}
V_39 -> V_94 = - 1 ;
V_39 -> V_46 . V_47 = & V_63 -> V_47 ;
V_39 -> V_63 = V_63 ;
F_34 ( & V_39 -> V_46 . V_95 ) ;
F_30 ( L_17 ,
& V_63 -> V_88 , & V_63 -> V_47 ) ;
F_35 ( & V_39 -> V_60 ) ;
F_34 ( & V_39 -> V_7 ) ;
memset ( & V_39 -> V_9 , 0 , sizeof( V_39 -> V_9 ) ) ;
V_39 -> V_96 = false ;
V_39 -> V_97 = false ;
V_39 -> V_98 = V_63 -> V_98 ;
V_39 -> V_65 = V_65 ;
V_63 -> V_76 . V_65 = V_65 ;
F_36 ( & V_39 -> V_99 ,
V_100 ) ;
F_23 ( F_20 ( & V_39 -> V_46 . V_47 -> V_48 -> V_49 ) |
V_101 ,
& V_39 -> V_46 . V_47 -> V_48 -> V_49 ) ;
F_30 ( L_18 ,
V_39 -> V_46 . V_47 , & V_39 -> V_46 . V_102 ) ;
V_40 = V_39 -> V_46 . V_47 -> V_48 ;
V_41 = ( T_5 T_4 * )
( ( char T_4 * ) V_40 +
F_20 ( & V_40 -> V_57 ) ) + V_55 ;
V_39 -> V_54 = & V_41 -> V_103 ;
if ( ! F_37 ( & V_39 -> V_46 . V_102 ,
V_104 ,
V_39 , L_19 ) ) {
F_3 ( L_20 ) ;
F_29 ( V_89 , V_90 ) ;
F_33 ( V_65 ) ;
return - V_73 ;
}
F_28 ( L_21 ,
V_39 -> V_98 . V_105 ) ;
F_28 ( L_22 ,
V_39 -> V_98 . V_106 ) ;
F_28 ( L_23 ,
V_39 -> V_98 . V_107 ) ;
F_28 ( L_24 ,
V_39 -> V_98 . V_108 ) ;
F_28 ( L_25 , V_65 -> V_109 -> V_110 ) ;
V_39 -> V_94 =
V_39 -> V_98 . V_106 & V_111 ;
V_66 = F_38 ( V_39 -> V_94 , V_67 , V_112 ,
V_65 -> V_109 -> V_110 , V_39 ) ;
if ( V_66 != 0 ) {
F_3 ( L_26 ,
V_39 -> V_94 , V_66 ) ;
V_39 -> V_94 = - 1 ;
F_29 ( V_89 , V_90 ) ;
} else {
T_6 T_4 * V_113 =
& V_39 -> V_46 . V_47 -> V_48 -> V_49 ;
F_3 ( L_27 ,
V_39 -> V_94 ) ;
V_42 = ~ ( V_101 |
V_51 ) ;
F_21 ( V_113 , V_42 ) ;
V_42 = V_114 ;
F_39 ( V_113 , V_42 ) ;
V_115 = 4000000 ;
}
F_30 ( L_28 ) ;
F_40 ( V_65 ) ;
F_30 ( L_29 ) ;
F_28 ( L_30 , V_65 ) ;
F_29 ( V_116 , V_71 ) ;
return 0 ;
}
static void
F_41 ( struct V_62 * V_63 )
{
struct V_1 * V_39 ;
struct V_32 * V_65 =
(struct V_32 * ) V_63 -> V_76 . V_65 ;
F_28 ( L_9 , V_63 -> V_68 ,
V_63 -> V_69 ) ;
V_39 = (struct V_1 * ) V_65 -> V_91 ;
if ( V_39 -> V_94 != - 1 )
F_42 ( V_39 -> V_94 , V_39 ) ;
F_28 ( L_31 , V_63 ,
V_39 ) ;
F_30 ( L_32 , V_65 ,
V_65 -> V_74 ) ;
F_43 ( V_65 ) ;
F_30 ( L_33 ) ;
F_44 ( & V_39 -> V_46 . V_102 ) ;
F_30 ( L_34 ) ;
F_33 ( V_65 ) ;
F_28 ( L_35 ) ;
}
static int
F_45 ( T_8 V_117 ,
struct V_32 * V_65 ,
struct V_118 * V_119 )
{
struct V_33 * V_34 ;
struct V_1 * V_39 =
(struct V_1 * ) V_65 -> V_91 ;
int V_120 = 0xffff ;
T_9 V_121 ;
F_28 ( L_36 , V_117 ,
V_119 -> V_19 , V_119 -> V_20 , V_119 -> V_21 ) ;
if ( V_39 -> V_96 || V_39 -> V_97 ) {
F_30 ( L_37 ) ;
return V_122 ;
}
V_34 = F_17 ( V_123 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return V_122 ;
}
F_35 ( & V_121 ) ;
V_34 -> V_3 = V_124 ;
V_34 -> V_125 . V_126 = ( void * ) & V_121 ;
V_34 -> V_125 . V_120 = ( void * ) & V_120 ;
V_34 -> V_125 . V_127 = V_117 ;
V_34 -> V_125 . V_119 . V_19 = V_119 -> V_19 ;
V_34 -> V_125 . V_119 . V_20 = V_119 -> V_20 ;
V_34 -> V_125 . V_119 . V_21 = V_119 -> V_21 ;
V_34 -> V_125 . V_128 =
( void * ) ( T_1 )
F_5 ( V_39 , V_124 ,
( void * ) V_34 ) ;
F_46 ( V_39 -> V_46 . V_47 ,
V_34 , V_129 ,
& V_39 -> V_46 . V_95 ,
V_130 , ( T_6 ) NULL ,
V_131 , L_39 ) ;
F_28 ( L_40 ,
V_34 -> V_132 . V_126 ) ;
F_47 ( V_121 , V_120 != 0xffff ) ;
F_28 ( L_41 , V_34 -> V_125 . V_133 ) ;
F_14 ( V_34 ) ;
return V_134 ;
}
static int
F_48 ( T_10 V_135 , struct V_16 * V_136 )
{
struct V_33 * V_34 ;
struct V_1 * V_39 =
(struct V_1 * ) V_136 -> V_137 -> V_91 ;
int V_120 = 0xffff ;
T_9 V_121 ;
F_28 ( L_42 , V_135 ,
V_136 -> V_19 , V_136 -> V_20 , V_136 -> V_21 ) ;
if ( V_39 -> V_96 || V_39 -> V_97 ) {
F_30 ( L_37 ) ;
return V_122 ;
}
V_34 = F_17 ( V_123 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return V_122 ;
}
F_35 ( & V_121 ) ;
V_34 -> V_3 = V_138 ;
V_34 -> V_132 . V_126 = ( void * ) & V_121 ;
V_34 -> V_132 . V_120 = ( void * ) & V_120 ;
V_34 -> V_132 . V_135 = V_135 ;
V_34 -> V_132 . V_119 . V_19 = V_136 -> V_19 ;
V_34 -> V_132 . V_119 . V_20 = V_136 -> V_20 ;
V_34 -> V_132 . V_119 . V_21 = V_136 -> V_21 ;
V_34 -> V_132 . V_128 =
( void * ) ( T_1 )
F_5 ( V_39 ,
V_138 ,
( void * ) V_34 ) ;
F_46 ( V_39 -> V_46 . V_47 ,
V_34 , V_129 ,
& V_39 -> V_46 . V_95 ,
V_130 , ( T_6 ) NULL ,
V_131 , L_39 ) ;
F_28 ( L_43 ,
V_34 -> V_132 . V_126 ) ;
F_47 ( V_121 , V_120 != 0xffff ) ;
F_28 ( L_44 , V_34 -> V_132 . V_133 ) ;
F_14 ( V_34 ) ;
return V_134 ;
}
static int
F_49 ( struct V_139 * V_128 )
{
struct V_16 * V_136 ;
struct V_140 * V_141 ;
V_136 = V_128 -> V_142 ;
for ( V_141 = & ( (struct V_1 * ) V_136 -> V_137 -> V_91 ) -> V_143 ;
V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( ( V_136 -> V_19 == V_141 -> V_19 )
&& ( V_136 -> V_20 == V_141 -> V_20 )
&& ( V_136 -> V_21 == V_141 -> V_21 ) ) {
if ( F_50 ( & V_141 -> V_144 ) <
V_145 ) {
F_51 ( & V_141 -> V_144 ) ;
F_29 ( V_146 ,
V_71 ) ;
} else
F_24 ( & V_141 -> V_147 ,
V_148 ) ;
}
}
return F_48 ( V_149 , V_128 -> V_142 ) ;
}
static int
F_52 ( struct V_139 * V_128 )
{
struct V_16 * V_136 ;
struct V_140 * V_141 ;
V_136 = V_128 -> V_142 ;
for ( V_141 = & ( (struct V_1 * ) V_136 -> V_137 -> V_91 ) -> V_143 ;
V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( ( V_136 -> V_19 == V_141 -> V_19 )
&& ( V_136 -> V_20 == V_141 -> V_20 )
&& ( V_136 -> V_21 == V_141 -> V_21 ) ) {
if ( F_50 ( & V_141 -> V_144 ) <
V_145 ) {
F_51 ( & V_141 -> V_144 ) ;
F_29 ( V_146 ,
V_71 ) ;
} else
F_24 ( & V_141 -> V_147 ,
V_148 ) ;
}
}
return F_48 ( V_150 , V_128 -> V_142 ) ;
}
static int
F_53 ( struct V_139 * V_128 )
{
struct V_16 * V_136 ;
struct V_140 * V_141 ;
V_136 = V_128 -> V_142 ;
for ( V_141 = & ( (struct V_1 * ) V_136 -> V_137 -> V_91 ) -> V_143 ;
V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( ( V_136 -> V_19 == V_141 -> V_19 )
&& ( V_136 -> V_20 == V_141 -> V_20 )
&& ( V_136 -> V_21 == V_141 -> V_21 ) ) {
if ( F_50 ( & V_141 -> V_144 ) <
V_145 ) {
F_51 ( & V_141 -> V_144 ) ;
F_29 ( V_146 ,
V_71 ) ;
} else
F_24 ( & V_141 -> V_147 ,
V_148 ) ;
}
}
return F_48 ( V_151 , V_128 -> V_142 ) ;
}
static int
F_54 ( struct V_139 * V_128 )
{
F_3 ( L_45 ) ;
return V_134 ;
}
static const char *
F_55 ( struct V_32 * V_152 )
{
sprintf ( V_153 , L_46 , V_154 ) ;
return V_153 ;
}
static int
F_56 ( struct V_16 * V_155 , int V_156 , void T_11 * V_157 )
{
F_30 ( L_47 , V_156 ) ;
return - V_158 ;
}
static int
F_57 ( struct V_139 * V_128 ,
void (* F_58)( struct V_139 * ) )
{
struct V_16 * V_136 = V_128 -> V_142 ;
int V_6 ;
unsigned char V_159 ;
unsigned char * V_160 = V_128 -> V_161 ;
struct V_32 * V_65 = V_136 -> V_137 ;
struct V_33 * V_34 ;
unsigned int V_27 ;
struct V_1 * V_39 =
(struct V_1 * ) V_65 -> V_91 ;
struct V_162 * V_163 = NULL ;
struct V_162 * V_164 = NULL ;
int V_165 = 0 ;
if ( V_39 -> V_96 || V_39 -> V_97 ) {
F_30 ( L_48 ) ;
return V_166 ;
}
V_34 = F_17 ( V_123 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_38 ) ;
return 1 ;
}
V_34 -> V_3 = V_167 ;
V_6 =
F_1 ( V_39 , V_167 , ( void * ) V_128 ) ;
if ( V_6 != - 1 ) {
V_34 -> V_76 . V_128 = ( void * ) ( T_1 ) V_6 ;
} else {
F_3 ( L_49 ) ;
F_14 ( V_34 ) ;
return V_166 ;
}
V_128 -> V_168 = F_58 ;
V_34 -> V_76 . V_119 . V_19 = V_136 -> V_19 ;
V_34 -> V_76 . V_119 . V_20 = V_136 -> V_20 ;
V_34 -> V_76 . V_119 . V_21 = V_136 -> V_21 ;
V_34 -> V_76 . V_169 = V_128 -> V_170 ;
memcpy ( V_34 -> V_76 . V_161 , V_160 , V_171 ) ;
V_34 -> V_76 . V_172 = F_59 ( V_128 ) ;
if ( V_34 -> V_76 . V_172 > V_173 )
V_173 = V_34 -> V_76 . V_172 ;
if ( F_60 ( V_128 ) > V_86 ) {
F_3 ( L_50 ,
F_60 ( V_128 ) , V_86 ) ;
F_9 ( V_39 , ( T_1 ) V_6 ) ;
F_14 ( V_34 ) ;
return 1 ;
}
if ( F_60 ( V_128 ) == 0 ) {
if ( F_59 ( V_128 ) > 0 ) {
F_3 ( L_51 ) ;
F_61 ( F_60 ( V_128 ) == 0 ) ;
}
F_30 ( L_52 ,
F_62 ( V_128 ) , F_59 ( V_128 ) ) ;
} else {
V_164 = F_62 ( V_128 ) ;
F_63 (sgl, sg, scsi_sg_count(scsicmd), i) {
V_34 -> V_76 . V_174 [ V_27 ] . V_175 = F_64 ( V_163 ) ;
V_34 -> V_76 . V_174 [ V_27 ] . V_176 = V_163 -> V_176 ;
if ( ( V_27 != 0 ) && ( V_163 -> V_177 != 0 ) )
F_28 ( L_53 ,
V_163 -> V_177 ) ;
}
if ( V_165 ) {
F_3 ( L_54 ,
F_60 ( V_128 ) , V_34 -> V_76 . V_172 ) ;
F_63 (sgl, sg, scsi_sg_count(scsicmd), i) {
F_3 ( L_55 ,
V_27 , F_65 ( V_163 ) ,
( unsigned long long ) F_64 ( V_163 ) ,
V_163 -> V_177 , V_163 -> V_176 ) ;
}
F_3 ( L_56 ) ;
}
V_34 -> V_76 . V_178 = F_60 ( V_128 ) ;
}
V_159 = V_160 [ 0 ] ;
V_27 = F_46 ( V_39 -> V_46 . V_47 ,
V_34 , V_129 ,
& V_39 -> V_46 .
V_95 ,
V_130 ,
( T_6 ) NULL , V_179 , L_39 ) ;
if ( V_27 == 0 ) {
F_3 ( L_57 ) ;
F_14 ( V_34 ) ;
F_9 ( V_39 , ( T_1 ) V_6 ) ;
return V_166 ;
}
F_14 ( V_34 ) ;
return 0 ;
}
static int
F_66 ( struct V_16 * V_136 )
{
struct V_140 * V_141 ;
struct V_140 * V_180 ;
struct V_1 * V_39 ;
struct V_32 * V_65 = (struct V_32 * ) V_136 -> V_137 ;
V_39 = (struct V_1 * ) V_65 -> V_91 ;
if ( ! V_39 ) {
F_3 ( L_58 ) ;
return 0 ;
}
for ( V_141 = & V_39 -> V_143 ; V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( V_141 -> V_31 -> V_181 &&
( V_141 -> V_31 -> V_19 == V_136 -> V_19 ) &&
( V_141 -> V_31 -> V_20 == V_136 -> V_20 ) &&
( V_141 -> V_31 -> V_21 == V_136 -> V_21 ) )
return 0 ;
}
V_180 = F_17 ( sizeof( struct V_140 ) , V_35 ) ;
if ( ! V_180 ) {
F_3 ( L_59 ) ;
return 0 ;
}
V_180 -> V_19 = V_136 -> V_19 ;
V_180 -> V_20 = V_136 -> V_20 ;
V_180 -> V_21 = V_136 -> V_21 ;
V_180 -> V_181 = 1 ;
V_141 -> V_31 = V_180 ;
return 0 ;
}
static int
F_67 ( struct V_16 * V_136 )
{
return 0 ;
}
static void
F_68 ( struct V_16 * V_136 )
{
struct V_140 * V_141 , * V_182 ;
struct V_1 * V_39 ;
struct V_32 * V_65 = (struct V_32 * ) V_136 -> V_137 ;
V_39 = (struct V_1 * ) V_65 -> V_91 ;
if ( ! V_39 )
F_3 ( L_58 ) ;
for ( V_141 = & V_39 -> V_143 ; V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( V_141 -> V_31 -> V_181 &&
( V_141 -> V_31 -> V_19 == V_136 -> V_19 ) &&
( V_141 -> V_31 -> V_20 == V_136 -> V_20 ) &&
( V_141 -> V_31 -> V_21 == V_136 -> V_21 ) ) {
V_182 = V_141 -> V_31 ;
V_141 -> V_31 = V_141 -> V_31 -> V_31 ;
F_14 ( V_182 ) ;
return;
}
}
return;
}
static void
F_69 ( struct V_33 * V_34 , struct V_139 * V_128 )
{
struct V_140 * V_141 ;
struct V_16 * V_136 ;
struct V_183 * V_184 ;
V_136 = V_128 -> V_142 ;
memcpy ( V_128 -> V_185 , V_34 -> V_76 . V_186 , V_187 ) ;
V_184 = (struct V_183 * ) V_128 -> V_185 ;
if ( ( V_34 -> V_76 . V_161 [ 0 ] == V_188 ) &&
( F_70 ( V_34 -> V_76 . V_189 ) == V_190 ) &&
( V_34 -> V_76 . V_191 == V_192 ) )
return;
for ( V_141 = & ( (struct V_1 * ) V_136 -> V_137 -> V_91 ) -> V_143 ;
V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( ( V_136 -> V_19 != V_141 -> V_19 )
|| ( V_136 -> V_20 != V_141 -> V_20 )
|| ( V_136 -> V_21 != V_141 -> V_21 ) )
continue;
if ( F_50 ( & V_141 -> V_144 ) < V_145 ) {
F_51 ( & V_141 -> V_144 ) ;
F_3 ( L_60 ,
V_128 , V_34 -> V_76 . V_161 [ 0 ] ,
V_136 -> V_137 -> V_23 , V_136 -> V_20 ,
V_136 -> V_19 , V_136 -> V_21 ,
V_34 -> V_76 . V_189 , V_184 -> V_193 , V_184 -> V_194 ,
V_184 -> V_195 ,
V_184 -> V_196 ) ;
if ( F_50 ( & V_141 -> V_144 ) ==
V_145 ) {
F_3 ( L_61 ,
V_136 -> V_137 -> V_23 , V_136 -> V_20 ,
V_136 -> V_19 , V_136 -> V_21 ) ;
}
F_24 ( & V_141 -> V_147 , V_148 ) ;
}
}
}
static void
F_71 ( struct V_33 * V_34 , struct V_139 * V_128 )
{
struct V_16 * V_136 ;
unsigned char V_197 [ 36 ] ;
struct V_162 * V_163 ;
unsigned int V_27 ;
char * V_198 ;
char * V_199 ;
int V_200 = 0 ;
struct V_140 * V_141 ;
V_136 = V_128 -> V_142 ;
if ( ( V_34 -> V_76 . V_161 [ 0 ] == V_188 )
&& ( V_34 -> V_76 . V_172 >= V_201 ) ) {
if ( V_34 -> V_76 . V_202 == 0 )
return;
F_72 ( V_197 , V_34 -> V_76 . V_172 ,
V_136 -> V_21 ,
V_203 ,
V_204 ) ;
if ( F_60 ( V_128 ) == 0 ) {
if ( F_59 ( V_128 ) > 0 ) {
F_3 ( L_51 ) ;
F_61 ( F_60 ( V_128 ) ==
0 ) ;
}
memcpy ( F_62 ( V_128 ) , V_197 ,
V_34 -> V_76 . V_172 ) ;
return;
}
V_163 = F_62 ( V_128 ) ;
for ( V_27 = 0 ; V_27 < F_60 ( V_128 ) ; V_27 ++ ) {
F_73 ( L_62 ,
F_65 ( V_163 + V_27 ) , V_163 [ V_27 ] . V_176 ) ;
V_199 = F_74 ( F_65 ( V_163 + V_27 ) ) ;
V_198 = ( void * ) ( ( unsigned long ) V_199 |
V_163 [ V_27 ] . V_177 ) ;
memcpy ( V_198 , V_197 + V_200 , V_163 [ V_27 ] . V_176 ) ;
F_75 ( V_199 ) ;
V_200 += V_163 [ V_27 ] . V_176 ;
}
} else {
V_141 = & ( (struct V_1 * ) V_136 -> V_137 -> V_91 ) -> V_143 ;
for ( ; V_141 -> V_31 ; V_141 = V_141 -> V_31 ) {
if ( ( V_136 -> V_19 != V_141 -> V_19 )
|| ( V_136 -> V_20 != V_141 -> V_20 )
|| ( V_136 -> V_21 != V_141 -> V_21 ) )
continue;
if ( F_50 ( & V_141 -> V_147 ) > 0 ) {
F_76 ( & V_141 -> V_147 ) ;
if ( F_50 ( & V_141 -> V_147 ) == 0 ) {
F_3 ( L_63 ) ;
F_24 ( & V_141 -> V_144 , 0 ) ;
}
}
}
}
}
static void
F_77 ( struct V_33 * V_34 , struct V_139 * V_128 )
{
F_30 ( L_64 , V_34 , V_34 -> V_76 . V_205 ) ;
V_128 -> V_133 = V_34 -> V_76 . V_189 ;
if ( V_34 -> V_76 . V_189 )
F_69 ( V_34 , V_128 ) ;
else
F_71 ( V_34 , V_128 ) ;
if ( V_128 -> V_168 ) {
F_73 ( L_65 ) ;
V_128 -> V_168 ( V_128 ) ;
}
}
static inline void
F_78 ( struct V_33 * V_34 )
{
* ( int * ) V_34 -> V_125 . V_120 = V_34 -> V_125 . V_133 ;
F_79 ( ( T_9 * ) V_34 -> V_125 . V_126 ) ;
F_28 ( L_66 , V_34 -> V_125 . V_133 ) ;
}
static inline void
F_80 ( struct V_33 * V_34 )
{
* ( int * ) V_34 -> V_132 . V_120 =
V_34 -> V_132 . V_133 ;
F_79 ( ( T_9 * ) V_34 -> V_132 . V_126 ) ;
F_28 ( L_66 , V_34 -> V_132 . V_133 ) ;
}
static void
F_81 ( struct V_1 * V_39 , struct V_206 * V_207 ,
struct V_33 * V_34 )
{
unsigned long V_5 ;
int V_208 = 0 ;
struct V_139 * V_128 ;
struct V_32 * V_18 = V_39 -> V_65 ;
while ( 1 ) {
F_2 ( & V_39 -> V_46 . V_95 , V_5 ) ;
if ( ! F_82 ( V_207 -> V_47 -> V_48 ,
L_39 , NULL ) ) {
F_4 ( & V_39 -> V_46 . V_95 ,
V_5 ) ;
V_39 -> V_209 ++ ;
break;
}
V_208 = F_83 ( V_207 -> V_47 , V_34 ,
V_55 ) ;
F_84 ( V_207 -> V_47 -> V_48 ,
L_39 , NULL ) ;
F_4 ( & V_39 -> V_46 . V_95 , V_5 ) ;
if ( V_208 == 0 )
break;
if ( V_34 -> V_3 == V_167 ) {
V_128 = F_9 ( V_39 ,
( T_1 ) V_34 -> V_76 . V_128 ) ;
if ( ! V_128 )
break;
F_77 ( V_34 , V_128 ) ;
} else if ( V_34 -> V_3 == V_138 ) {
if ( ! F_9 ( V_39 ,
( T_1 ) V_34 -> V_132 . V_128 ) )
break;
F_80 ( V_34 ) ;
} else if ( V_34 -> V_3 == V_210 ) {
V_34 -> V_36 . V_211 = NULL ;
F_16 ( V_18 , V_34 ) ;
} else if ( V_34 -> V_3 == V_124 ) {
if ( ! F_9 ( V_39 ,
( T_1 ) V_34 -> V_125 . V_128 ) )
break;
F_78 ( V_34 ) ;
} else
F_3 ( L_67 , V_34 -> V_3 ) ;
}
}
static int
V_104 ( void * V_212 )
{
struct V_1 * V_39 = V_212 ;
struct V_206 * V_207 = & V_39 -> V_46 ;
struct V_33 * V_34 = NULL ;
const int V_213 = sizeof( struct V_33 ) ;
T_6 V_42 ;
unsigned long long V_43 ;
F_85 ( L_19 ) ;
V_34 = F_86 ( V_213 , V_35 ) ;
if ( V_34 == NULL ) {
F_3 ( L_68 ) ;
F_87 ( & V_207 -> V_102 . V_214 , 0 ) ;
return 0 ;
}
V_42 = V_53 ;
while ( 1 ) {
F_88 ( V_39 -> V_60 ,
( F_50 ( & V_39 -> V_59 ) == 1 ) ,
F_89 ( V_115 ) ) ;
F_24 ( & V_39 -> V_59 , 0 ) ;
F_81 ( V_39 , V_207 , V_34 ) ;
V_43 = F_39 ( V_39 -> V_54 , V_42 ) ;
if ( V_207 -> V_102 . V_215 )
break;
}
F_14 ( V_34 ) ;
F_30 ( L_69 ) ;
F_87 ( & V_207 -> V_102 . V_214 , 0 ) ;
}
static T_12 F_90 ( struct V_216 * V_216 ,
char T_11 * V_197 , T_13 V_217 , T_14 * V_177 )
{
T_12 V_218 = 0 ;
int V_219 = 0 ;
T_6 V_220 ;
int V_27 ;
struct V_1 * V_39 ;
char * V_221 ;
if ( V_217 > V_222 )
V_217 = V_222 ;
V_221 = F_17 ( V_217 , V_223 ) ;
if ( ! V_221 )
return - V_224 ;
for ( V_27 = 0 ; V_27 < V_92 ; V_27 ++ ) {
if ( V_93 [ V_27 ] . V_39 == NULL )
continue;
V_39 = V_93 [ V_27 ] . V_39 ;
V_219 += F_91 ( V_221 + V_219 ,
V_217 - V_219 , L_70 , V_173 ) ;
V_219 += F_91 ( V_221 + V_219 , V_217 - V_219 ,
L_71 ,
V_115 ) ;
V_219 += F_91 ( V_221 + V_219 , V_217 - V_219 ,
L_72 ,
V_39 -> V_45 ,
V_39 -> V_52 ) ;
V_219 += F_91 ( V_221 + V_219 ,
V_217 - V_219 , L_73 ,
V_39 -> V_56 ) ;
V_220 = F_92 ( ( V_225 void * )
V_39 -> V_54 ) ;
V_219 += F_91 ( V_221 + V_219 , V_217 - V_219 ,
L_74 ,
V_39 -> V_54 , V_220 ,
( V_226 ) F_20 ( V_39 -> V_54 ) ) ;
V_219 += F_91 ( V_221 + V_219 ,
V_217 - V_219 , L_75 ,
V_39 -> V_209 ) ;
V_219 += F_91 ( V_221 + V_219 , V_217 - V_219 , L_76 ) ;
}
V_218 = F_93 ( V_197 , V_217 , V_177 , V_221 , V_219 ) ;
F_14 ( V_221 ) ;
return V_218 ;
}
static T_12 F_94 ( struct V_216 * V_216 ,
const char T_11 * V_227 , T_13 V_228 , T_14 * V_229 )
{
char V_197 [ 4 ] ;
int V_27 , V_230 ;
struct V_1 * V_39 ;
T_6 T_4 * V_113 ;
T_6 V_42 ;
if ( V_228 >= F_95 ( V_197 ) )
return - V_158 ;
V_197 [ V_228 ] = '\0' ;
if ( F_96 ( V_197 , V_227 , V_228 ) ) {
F_3 ( L_77 ,
( int ) V_228 , V_197 , V_228 ) ;
return - V_231 ;
}
V_27 = F_97 ( V_197 , 10 , & V_230 ) ;
if ( V_27 != 0 ) {
F_3 ( L_78 ,
( int ) V_228 , V_197 ) ;
return - V_231 ;
}
for ( V_27 = 0 ; V_27 < V_92 ; V_27 ++ ) {
if ( V_93 [ V_27 ] . V_39 != NULL ) {
V_39 = V_93 [ V_27 ] . V_39 ;
V_113 =
& V_39 -> V_46 . V_47 -> V_48 -> V_49 ;
if ( V_230 == 1 ) {
V_42 = ~ ( V_101 |
V_51 ) ;
F_21 ( V_113 , V_42 ) ;
V_42 = V_114 ;
F_39 ( V_113 , V_42 ) ;
V_115 = 4000000 ;
} else {
V_42 = ~ ( V_114 |
V_51 ) ;
F_21 ( V_113 , V_42 ) ;
V_42 = V_101 ;
F_39 ( V_113 , V_42 ) ;
V_115 = 4000 ;
}
}
}
return V_228 ;
}
static int
F_98 ( struct V_62 * V_63 )
{
struct V_1 * V_39 =
(struct V_1 * ) ( (struct V_32 * ) V_63 -> V_76 .
V_65 ) -> V_91 ;
F_30 ( L_9 , V_63 -> V_68 ,
V_63 -> V_69 ) ;
if ( ! V_39 -> V_96 ) {
F_30 ( L_79 ) ;
return 1 ;
}
if ( V_39 -> V_97 ) {
F_3 ( L_80 ) ;
return 0 ;
}
V_39 -> V_97 = true ;
F_99 ( V_39 -> V_46 . V_47 -> V_48 ,
F_100 ( & V_63 -> V_88 ) ,
V_232 , NULL ) ;
if ( ! F_37 ( & V_39 -> V_46 . V_102 ,
V_104 ,
V_39 , L_19 ) ) {
F_3 ( L_20 ) ;
return 0 ;
}
V_39 -> V_96 = false ;
V_39 -> V_97 = false ;
return 1 ;
}
static void
V_100 ( struct V_24 * V_25 )
{
struct V_1 * V_39 ;
struct V_62 * V_63 ;
int V_27 ;
struct V_233 * V_234 = NULL ;
struct V_139 * V_128 = NULL ;
struct V_33 * V_34 ;
unsigned long V_5 ;
V_39 = F_101 ( V_25 , struct V_1 ,
V_99 ) ;
F_44 ( & V_39 -> V_46 . V_102 ) ;
F_2 ( & V_39 -> V_7 , V_5 ) ;
for ( V_27 = 0 ; V_27 < V_11 ; V_27 ++ ) {
V_234 = & ( V_39 -> V_9 [ V_27 ] ) ;
switch ( V_234 -> V_3 ) {
case V_167 :
V_128 = (struct V_139 * ) V_234 -> V_10 ;
V_128 -> V_133 = ( V_235 << 16 ) ;
if ( V_128 -> V_168 )
V_128 -> V_168 ( V_128 ) ;
break;
case V_138 :
V_34 = (struct V_33 * ) V_234 -> V_10 ;
F_30 ( L_81 , V_34 ,
V_34 -> V_132 . V_126 ) ;
* ( int * ) V_34 -> V_132 . V_120 =
V_236 ;
F_79 ( ( T_9 * )
V_34 -> V_132 . V_126 ) ;
break;
case V_124 :
V_34 = (struct V_33 * ) V_234 -> V_10 ;
* ( int * ) V_34 -> V_125 . V_120 =
V_237 ;
F_79 ( ( T_9 * )
V_34 -> V_125 . V_126 ) ;
break;
default:
if ( V_234 -> V_10 != NULL )
F_3 ( L_82 ,
V_234 -> V_3 ) ;
}
V_234 -> V_3 = 0 ;
V_234 -> V_10 = NULL ;
}
F_4 ( & V_39 -> V_7 , V_5 ) ;
V_63 = V_39 -> V_63 ;
F_30 ( L_9 , V_63 -> V_68 ,
V_63 -> V_69 ) ;
V_39 -> V_96 = true ;
V_39 -> V_97 = false ;
F_102 ( V_63 -> V_68 ,
V_63 -> V_69 , 0 ) ;
}
static int
F_103 ( struct V_62 * V_63 , T_15 V_238 )
{
struct V_1 * V_39 =
(struct V_1 * ) ( (struct V_32 * ) V_63 -> V_76 .
V_65 ) -> V_91 ;
F_30 ( L_83 ) ;
F_30 ( L_9 , V_63 -> V_68 ,
V_63 -> V_69 ) ;
if ( ! V_39 -> V_96 && ! V_39 -> V_97 ) {
V_39 -> V_97 = true ;
F_104 ( V_239 ,
& V_39 -> V_99 ) ;
} else if ( V_39 -> V_97 ) {
F_3 ( L_80 ) ;
return 0 ;
} else
F_3 ( L_84 ) ;
return 1 ;
}
static int T_16
F_105 ( char * V_240 )
{
F_30 ( L_85 , V_240 ) ;
return 1 ;
}
static void T_16
F_106 ( char * line )
{
char * V_31 = line ;
F_29 ( V_241 , V_71 ) ;
if ( line == NULL || ! * line )
return;
while ( ( line = V_31 ) != NULL ) {
V_31 = strchr ( line , ' ' ) ;
if ( V_31 != NULL )
* V_31 ++ = 0 ;
if ( ! F_105 ( line ) )
F_30 ( L_86 , line ) ;
}
F_29 ( V_242 , V_71 ) ;
}
static int T_16
F_107 ( void )
{
int error ;
int V_27 ;
if ( ! V_243 )
return - V_73 ;
F_28 ( L_87 ) ;
F_29 ( V_241 , V_71 ) ;
F_106 ( V_244 ) ;
error = F_108 ( & V_245 ) ;
if ( error < 0 ) {
F_3 ( L_88 , error ) ;
F_109 ( V_246 , error ,
V_90 ) ;
} else {
V_247 = F_110 ( L_89 , NULL ) ;
F_111 ( L_90 , V_248 , V_247 ,
NULL , & V_249 ) ;
F_112 ( L_91 , V_248 | V_250 ,
V_247 , & V_115 ) ;
F_111 ( L_92 , V_250 ,
V_247 , NULL ,
& V_251 ) ;
F_36 ( & V_252 , F_15 ) ;
F_34 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < V_92 ; V_27 ++ )
V_93 [ V_27 ] . V_39 = NULL ;
V_239 =
F_113 ( L_83 ) ;
if ( V_239 == NULL ) {
F_3 ( L_93 ) ;
F_29 ( V_246 ,
V_90 ) ;
error = - 1 ;
}
}
F_29 ( V_242 , V_71 ) ;
F_28 ( L_94 ) ;
return error ;
}
static T_12
F_114 ( struct V_142 * V_253 , struct V_254 * V_255 ,
const char * V_197 , T_13 V_228 )
{
struct V_118 V_119 ;
struct V_32 * V_18 = F_115 ( V_253 ) ;
int V_27 ;
V_27 = sscanf ( V_197 , L_95 , & V_119 . V_19 , & V_119 . V_20 , & V_119 . V_21 ) ;
if ( V_27 != 3 )
return V_27 ;
return F_45 ( V_256 , V_18 , & V_119 ) ;
}
static T_12
F_116 ( struct V_142 * V_253 , struct V_254 * V_255 ,
const char * V_197 , T_13 V_228 )
{
struct V_118 V_119 ;
struct V_32 * V_18 = F_115 ( V_253 ) ;
int V_27 ;
V_27 = sscanf ( V_197 , L_95 , & V_119 . V_19 , & V_119 . V_20 , & V_119 . V_21 ) ;
if ( V_27 != 3 )
return V_27 ;
return F_45 ( V_257 , V_18 , & V_119 ) ;
}
static void T_17
F_117 ( void )
{
F_28 ( L_96 ) ;
F_118 ( & V_245 ) ;
if ( V_239 ) {
F_119 ( V_239 ) ;
V_239 = NULL ;
}
F_120 ( V_247 ) ;
F_28 ( L_97 ) ;
}
