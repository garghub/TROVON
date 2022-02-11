int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
T_2 * V_5 ;
int V_6 , V_7 ;
unsigned long V_8 ;
const int * V_9 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_9 = F_2 ( V_1 , L_2 , NULL ) ;
if ( ! V_9 )
return 0 ;
V_10 . V_11 = 1 ;
V_10 . V_12 = * V_9 ;
V_13 = F_2 ( V_1 , L_3 , NULL ) ;
if ( V_13 )
V_10 . V_14 = 1 ;
V_5 = F_2 ( V_1 , L_4 ,
& V_8 ) ;
if ( ! V_5 )
return 0 ;
V_7 = V_8 / ( 3 * sizeof( V_15 ) ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ , V_5 += 3 ) {
V_15 type = ( V_15 ) F_3 ( V_5 , 1 ) ;
switch ( type ) {
case V_16 :
V_10 . V_17 =
F_4 ( & V_5 [ 1 ] , 2 ) ;
break;
case V_18 :
V_10 . V_19 =
F_4 ( & V_5 [ 1 ] , 2 ) ;
break;
}
}
return 1 ;
}
int F_5 ( void )
{
return V_10 . V_14 ;
}
static void F_6 ( void )
{
F_7 ( L_5 ,
( V_10 . V_11 ? L_6 : L_7 ) ) ;
if ( ! V_10 . V_11 )
return;
F_7 ( L_8 ,
( V_10 . V_20 ? L_9 : L_10 ) ) ;
F_7 ( L_11 ,
( V_10 . V_14 ? L_9 : L_10 ) ) ;
F_7 ( L_12 ) ;
F_7 ( L_13 , V_10 . V_17 ) ;
F_7 ( L_14 , V_10 . V_19 ) ;
F_7 ( L_15 , V_10 . V_21 ) ;
}
static unsigned long F_8 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
if ( ! V_23 )
return 0 ;
memset ( V_23 , 0 , sizeof( struct V_22 ) ) ;
V_24 = V_24 & V_25 ;
V_23 -> V_26 . V_27 = 0x00000001 ;
V_23 -> V_26 . V_28 = 3 ;
V_23 -> V_26 . V_29 = 0 ;
V_23 -> V_26 . V_30 =
( V_15 ) F_9 ( struct V_22 , V_31 ) ;
V_23 -> V_26 . V_32 = 0 ;
V_23 -> V_26 . V_33 = 0 ;
V_23 -> V_26 . V_34 = 0 ;
V_23 -> V_26 . V_35 = 0 ;
V_23 -> V_26 . V_36 = 0 ;
V_23 -> V_31 . V_37 = V_38 ;
V_23 -> V_31 . V_39 = V_16 ;
V_23 -> V_31 . V_40 = 0 ;
V_23 -> V_31 . V_41 = V_10 . V_17 ;
V_23 -> V_31 . V_42 = V_24 ;
V_24 += V_10 . V_17 ;
V_23 -> V_43 . V_37 = V_38 ;
V_23 -> V_43 . V_39 = V_18 ;
V_23 -> V_43 . V_40 = 0 ;
V_23 -> V_43 . V_41 = V_10 . V_19 ;
V_23 -> V_43 . V_42 = V_24 ;
V_24 += V_10 . V_19 ;
V_23 -> V_44 . V_37 = V_38 ;
V_23 -> V_44 . V_39 = V_45 ;
V_23 -> V_44 . V_40 = V_46 ;
V_23 -> V_44 . V_41 = V_10 . V_21 ;
V_23 -> V_44 . V_42 = V_24 ;
V_24 += V_10 . V_21 ;
return V_24 ;
}
static inline unsigned long F_10 ( void )
{
unsigned long V_8 ;
if ( V_10 . V_47 )
return V_10 . V_47 ;
V_8 = F_11 () / 20 ;
V_8 = V_8 & ~ 0x0FFFFFFFUL ;
if ( V_48 && V_8 > V_48 )
V_8 = V_48 ;
return ( V_8 > V_49 ? V_8 : V_49 ) ;
}
static unsigned long F_12 ( void )
{
unsigned long V_8 = 0 ;
V_8 += V_10 . V_17 ;
V_8 += V_10 . V_19 ;
V_8 += V_10 . V_21 ;
V_8 += sizeof( struct V_50 ) ;
V_8 += sizeof( struct V_51 ) ;
V_8 += sizeof( struct V_52 ) ;
V_8 += sizeof( struct V_52 ) * ( F_13 ( V_53 ) + 2 ) ;
V_8 = F_14 ( V_8 ) ;
return V_8 ;
}
int T_1 F_15 ( void )
{
unsigned long V_54 , V_8 , V_55 ;
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_16 ( V_56 L_16
L_17 ) ;
V_10 . V_20 = 0 ;
return 0 ;
}
if ( V_13 )
V_10 . V_21 = V_13 -> V_44 . V_41 ;
else
V_10 . V_21 = F_10 () ;
if ( V_48 && V_48 < F_11 () ) {
V_8 = F_12 () ;
if ( ( V_48 + V_8 ) < F_11 () )
V_48 += V_8 ;
else
V_48 = F_11 () ;
F_16 ( V_56 L_18
L_19 ,
( unsigned long long ) V_48 ) ;
}
if ( V_48 )
V_55 = V_48 ;
else
V_55 = F_11 () ;
if ( V_10 . V_14 ) {
F_16 ( V_56 L_20 ) ;
V_54 = V_10 . V_21 ;
V_8 = V_55 - V_54 ;
F_17 ( V_54 , V_8 ) ;
F_16 ( V_56 L_21
L_22 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_54 >> 20 ) ) ;
V_10 . V_57 =
V_13 -> V_44 . V_42 +
V_13 -> V_44 . V_41 ;
F_7 ( L_23 ,
( void * ) V_10 . V_57 ) ;
} else {
V_8 = F_12 () ;
V_54 = V_55 - V_8 ;
F_17 ( V_54 , V_8 ) ;
F_16 ( V_56 L_21
L_24 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_54 >> 20 ) ) ;
}
V_10 . V_58 = V_54 ;
V_10 . V_59 = V_8 ;
return 1 ;
}
static int T_1 F_18 ( char * V_60 )
{
if ( ! V_60 )
return 1 ;
if ( strncmp ( V_60 , L_25 , 2 ) == 0 )
V_10 . V_20 = 1 ;
else if ( strncmp ( V_60 , L_26 , 3 ) == 0 )
V_10 . V_20 = 0 ;
return 0 ;
}
static int T_1 F_19 ( char * V_60 )
{
if ( V_60 )
V_10 . V_47 = F_20 ( V_60 , & V_60 ) ;
return 0 ;
}
static void F_21 ( struct V_22 * V_23 )
{
int V_61 ;
unsigned int V_62 ;
F_7 ( L_27 ) ;
do {
V_61 = F_22 ( V_10 . V_12 , 3 , 1 , NULL ,
V_63 , V_23 ,
sizeof( struct V_22 ) ) ;
V_62 = F_23 ( V_61 ) ;
if ( V_62 )
F_24 ( V_62 ) ;
} while ( V_62 );
switch ( V_61 ) {
case - 1 :
F_16 ( V_64 L_28
L_29 , V_61 ) ;
break;
case - 3 :
F_16 ( V_64 L_28
L_30 , V_61 ) ;
break;
case - 9 :
F_16 ( V_64 L_31
L_32 ) ;
V_10 . V_65 = 1 ;
break;
case 0 :
F_16 ( V_56 L_33
L_34 ) ;
V_10 . V_65 = 1 ;
break;
}
}
void F_25 ( struct V_66 * V_67 , const char * V_68 )
{
struct V_50 * V_69 = NULL ;
if ( ! V_10 . V_65 || ! V_10 . V_57 )
return;
V_69 = F_26 ( V_10 . V_57 ) ;
V_70 = F_27 () ;
V_69 -> V_70 = V_70 ;
F_28 () ;
if ( V_67 )
V_69 -> V_67 = * V_67 ;
else
F_29 ( & V_69 -> V_67 ) ;
V_69 -> V_71 = * V_71 ;
F_30 ( ( char * ) V_68 ) ;
}
static inline int F_31 ( T_3 V_72 )
{
int V_6 = - 1 ;
char V_68 [ 3 ] ;
if ( ( V_72 & V_73 ) == F_32 ( L_35 ) ) {
V_72 &= ~ V_73 ;
V_72 >>= 24 ;
V_68 [ 2 ] = '\0' ;
V_68 [ 1 ] = V_72 & 0xff ;
V_68 [ 0 ] = ( V_72 >> 8 ) & 0xff ;
sscanf ( V_68 , L_36 , & V_6 ) ;
if ( V_6 > 31 )
V_6 = - 1 ;
}
return V_6 ;
}
static inline void F_33 ( struct V_66 * V_67 , T_3 V_74 ,
T_3 V_75 )
{
int V_6 ;
V_6 = F_31 ( V_74 ) ;
if ( V_6 >= 0 )
V_67 -> V_76 [ V_6 ] = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_37 ) )
V_67 -> V_77 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_38 ) )
V_67 -> V_78 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_39 ) )
V_67 -> V_79 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_40 ) )
V_67 -> V_80 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_41 ) )
V_67 -> V_81 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_42 ) )
V_67 -> V_82 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_43 ) )
V_67 -> V_83 = ( unsigned long ) V_75 ;
else if ( V_74 == F_32 ( L_44 ) )
V_67 -> V_84 = ( unsigned long ) V_75 ;
}
static struct V_85 *
F_34 ( struct V_85 * V_86 , struct V_66 * V_67 )
{
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
while ( V_86 -> V_74 != F_32 ( L_45 ) ) {
F_33 ( V_67 , V_86 -> V_74 ,
V_86 -> V_87 ) ;
V_86 ++ ;
}
V_86 ++ ;
return V_86 ;
}
static V_15 * F_35 ( V_15 * V_88 , char * V_89 , unsigned type ,
void * V_4 , T_4 V_90 )
{
struct V_91 V_92 ;
V_92 . V_93 = strlen ( V_89 ) + 1 ;
V_92 . V_94 = V_90 ;
V_92 . V_95 = type ;
memcpy ( V_88 , & V_92 , sizeof( V_92 ) ) ;
V_88 += ( sizeof( V_92 ) + 3 ) / 4 ;
memcpy ( V_88 , V_89 , V_92 . V_93 ) ;
V_88 += ( V_92 . V_93 + 3 ) / 4 ;
memcpy ( V_88 , V_4 , V_92 . V_94 ) ;
V_88 += ( V_92 . V_94 + 3 ) / 4 ;
return V_88 ;
}
static void F_36 ( V_15 * V_88 )
{
struct V_91 V_92 ;
V_92 . V_93 = 0 ;
V_92 . V_94 = 0 ;
V_92 . V_95 = 0 ;
memcpy ( V_88 , & V_92 , sizeof( V_92 ) ) ;
}
static V_15 * F_37 ( V_15 * V_88 , struct V_66 * V_67 )
{
struct V_96 V_97 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
F_38 ( & V_97 . V_98 , V_67 ) ;
V_88 = F_35 ( V_88 , V_99 , V_100 ,
& V_97 , sizeof( V_97 ) ) ;
return V_88 ;
}
static void F_39 ( char * V_101 )
{
struct V_51 * V_102 ;
struct V_52 * V_103 ;
V_102 = (struct V_51 * ) V_101 ;
V_101 += sizeof( struct V_51 ) ;
V_103 = (struct V_52 * ) V_101 ;
if ( V_103 -> V_104 == V_105 ) {
V_103 -> V_106 = V_10 . V_107 ;
V_103 -> V_108 = V_103 -> V_106 ;
V_103 -> V_109 = V_10 . V_110 ;
V_103 -> V_111 = V_10 . V_110 ;
}
return;
}
static void * F_40 ( unsigned long V_8 )
{
void * V_112 ;
struct V_113 * V_113 ;
unsigned long V_114 , V_115 , V_6 ;
V_114 = F_41 ( V_8 ) ;
V_112 = ( void * ) F_42 ( V_116 | V_117 , V_114 ) ;
if ( ! V_112 )
return NULL ;
V_115 = 1 << V_114 ;
V_113 = F_43 ( V_112 ) ;
for ( V_6 = 0 ; V_6 < V_115 ; V_6 ++ )
F_44 ( V_113 + V_6 ) ;
return V_112 ;
}
static void F_45 ( unsigned long V_112 , unsigned long V_8 )
{
struct V_113 * V_113 ;
unsigned long V_114 , V_115 , V_6 ;
V_114 = F_41 ( V_8 ) ;
V_115 = 1 << V_114 ;
V_113 = F_43 ( V_112 ) ;
for ( V_6 = 0 ; V_6 < V_115 ; V_6 ++ )
F_46 ( V_113 + V_6 ) ;
F_47 ( V_113 , V_114 ) ;
}
static int T_1 F_48 ( const struct V_22 * V_23 )
{
struct V_118 * V_119 ;
struct V_85 * V_86 ;
struct V_50 * V_69 = NULL ;
void * V_112 ;
unsigned long V_24 ;
V_15 V_120 , * V_121 ;
struct V_66 V_67 ;
int V_6 , V_61 = 0 , V_122 = 0 ;
if ( ! V_23 -> V_31 . V_123 )
return - V_124 ;
V_24 = V_23 -> V_31 . V_42 ;
V_112 = F_26 ( V_24 ) ;
V_119 = V_112 ;
if ( V_119 -> V_125 != V_126 ) {
F_16 ( V_64 L_46 ) ;
return - V_127 ;
}
F_7 ( L_47 ) ;
F_7 ( L_48 , V_119 -> V_125 ) ;
F_7 ( L_49 , V_119 -> V_128 ) ;
V_112 += V_119 -> V_128 ;
V_120 = * ( ( V_15 * ) ( V_112 ) ) ;
F_7 ( L_50 , V_120 ) ;
V_112 += sizeof( V_15 ) ;
V_86 = (struct V_85 * ) V_112 ;
V_10 . V_110 = V_120 * sizeof( V_129 ) ;
V_10 . V_110 = F_14 ( V_10 . V_110 ) ;
V_121 = F_40 ( V_10 . V_110 ) ;
if ( ! V_121 ) {
F_16 ( V_64 L_51
L_52 , V_10 . V_110 ) ;
return - V_130 ;
}
V_10 . V_107 = F_49 ( V_121 ) ;
F_7 ( L_53 ,
( V_120 * sizeof( V_129 ) ) , V_121 ) ;
if ( V_10 . V_57 )
V_69 = F_26 ( V_10 . V_57 ) ;
for ( V_6 = 0 ; V_6 < V_120 ; V_6 ++ ) {
if ( V_86 -> V_74 != F_32 ( L_54 ) ) {
F_16 ( V_64 L_55 ) ;
V_61 = - V_127 ;
goto V_131;
}
V_122 = V_86 -> V_87 & V_132 ;
if ( ! F_50 ( V_122 , & V_69 -> V_71 ) ) {
F_51 ( V_86 ) ;
continue;
}
F_7 ( L_56 , V_122 ) ;
if ( V_69 && V_69 -> V_70 == V_122 ) {
V_67 = V_69 -> V_67 ;
V_121 = F_37 ( V_121 , & V_67 ) ;
F_51 ( V_86 ) ;
} else {
V_86 ++ ;
V_86 = F_34 ( V_86 , & V_67 ) ;
V_121 = F_37 ( V_121 , & V_67 ) ;
}
}
F_36 ( V_121 ) ;
F_7 ( L_57 ,
V_69 -> V_133 ) ;
F_39 ( ( char * ) F_26 ( V_69 -> V_133 ) ) ;
return 0 ;
V_131:
F_45 ( ( unsigned long ) F_26 ( V_10 . V_107 ) ,
V_10 . V_110 ) ;
V_10 . V_107 = 0 ;
V_10 . V_110 = 0 ;
return V_61 ;
}
static int T_1 F_52 ( const struct V_22 * V_13 )
{
struct V_50 * V_69 ;
int V_61 = 0 ;
if ( ! V_13 || ! V_10 . V_57 )
return - V_124 ;
if ( ( V_13 -> V_26 . V_29 == V_134 ) ||
( V_13 -> V_31 . V_135 != 0 ) ||
( V_13 -> V_44 . V_135 != 0 ) ) {
F_16 ( V_64 L_58 ) ;
return - V_124 ;
}
if ( ( V_13 -> V_44 . V_123 !=
V_13 -> V_44 . V_41 ) ||
! V_13 -> V_31 . V_123 ) {
F_16 ( V_64 L_59 ) ;
return - V_124 ;
}
V_69 = F_26 ( V_10 . V_57 ) ;
if ( V_69 -> V_125 != V_136 ) {
F_16 ( V_64 L_60 ) ;
return - V_124 ;
}
V_61 = F_48 ( V_13 ) ;
if ( V_61 )
return V_61 ;
V_133 = V_69 -> V_133 ;
return 0 ;
}
static inline void F_53 ( unsigned long long V_54 ,
unsigned long long V_137 )
{
if ( V_54 == V_137 )
return;
F_7 ( L_61 ,
V_138 , V_54 , V_137 - 1 , ( V_137 - V_54 ) ) ;
V_139 [ V_138 ] . V_54 = V_54 ;
V_139 [ V_138 ] . V_8 = V_137 - V_54 ;
V_138 ++ ;
}
static void F_54 ( unsigned long long V_140 ,
unsigned long long V_137 )
{
unsigned long long V_141 , V_142 ;
V_141 = V_10 . V_58 ;
V_142 = V_141 + V_10 . V_59 ;
if ( ( V_141 < V_137 ) && ( V_142 > V_140 ) ) {
if ( ( V_140 < V_141 ) && ( V_137 > V_142 ) ) {
F_53 ( V_140 , V_141 ) ;
F_53 ( V_142 , V_137 ) ;
} else if ( V_140 < V_141 ) {
F_53 ( V_140 , V_141 ) ;
} else if ( V_142 < V_137 ) {
F_53 ( V_142 , V_137 ) ;
}
} else
F_53 ( V_140 , V_137 ) ;
}
static int F_55 ( char * V_101 )
{
struct V_51 * V_102 ;
V_102 = (struct V_51 * ) V_101 ;
V_101 += sizeof( struct V_51 ) ;
memcpy ( V_102 -> V_143 , V_144 , V_145 ) ;
V_102 -> V_143 [ V_146 ] = V_147 ;
V_102 -> V_143 [ V_148 ] = V_149 ;
V_102 -> V_143 [ V_150 ] = V_151 ;
V_102 -> V_143 [ V_152 ] = V_153 ;
memset ( V_102 -> V_143 + V_154 , 0 , V_155 - V_154 ) ;
V_102 -> V_156 = V_157 ;
V_102 -> V_158 = V_159 ;
V_102 -> V_160 = V_151 ;
V_102 -> V_161 = 0 ;
V_102 -> V_162 = sizeof( struct V_51 ) ;
V_102 -> V_163 = 0 ;
V_102 -> V_164 = V_165 ;
V_102 -> V_166 = sizeof( struct V_51 ) ;
V_102 -> V_167 = sizeof( struct V_52 ) ;
V_102 -> V_168 = 0 ;
V_102 -> V_169 = 0 ;
V_102 -> V_170 = 0 ;
V_102 -> V_171 = 0 ;
return 0 ;
}
static void F_56 ( void )
{
struct V_172 * V_173 ;
unsigned long long V_140 , V_137 ;
F_7 ( L_62 ) ;
V_138 = 0 ;
F_53 ( V_46 , V_10 . V_21 ) ;
F_57 (memory, reg) {
V_140 = ( unsigned long long ) V_173 -> V_54 ;
V_137 = V_140 + ( unsigned long long ) V_173 -> V_8 ;
if ( V_140 == V_46 && V_137 >= V_10 . V_21 )
V_140 = V_10 . V_21 ;
F_54 ( V_140 , V_137 ) ;
}
}
static inline unsigned long F_58 ( unsigned long V_174 )
{
if ( V_174 > V_46 && V_174 < V_10 . V_21 )
return V_23 . V_44 . V_42 + V_174 ;
else
return V_174 ;
}
static int F_59 ( char * V_101 )
{
struct V_51 * V_102 ;
struct V_52 * V_103 ;
int V_6 ;
F_55 ( V_101 ) ;
V_102 = (struct V_51 * ) V_101 ;
V_101 += sizeof( struct V_51 ) ;
V_103 = (struct V_52 * ) V_101 ;
V_101 += sizeof( struct V_52 ) ;
V_103 -> V_104 = V_105 ;
V_103 -> V_175 = 0 ;
V_103 -> V_176 = 0 ;
V_103 -> V_177 = 0 ;
V_103 -> V_108 = 0 ;
V_103 -> V_106 = 0 ;
V_103 -> V_109 = 0 ;
V_103 -> V_111 = 0 ;
( V_102 -> V_168 ) ++ ;
V_103 = (struct V_52 * ) V_101 ;
V_101 += sizeof( struct V_52 ) ;
V_103 -> V_104 = V_105 ;
V_103 -> V_175 = 0 ;
V_103 -> V_176 = 0 ;
V_103 -> V_177 = 0 ;
V_103 -> V_106 = F_58 ( F_60 () ) ;
V_103 -> V_108 = V_103 -> V_106 ;
V_103 -> V_111 = V_178 ;
V_103 -> V_109 = V_178 ;
( V_102 -> V_168 ) ++ ;
for ( V_6 = 0 ; V_6 < V_138 ; V_6 ++ ) {
unsigned long long V_179 , V_180 ;
V_179 = V_139 [ V_6 ] . V_54 ;
V_180 = V_139 [ V_6 ] . V_8 ;
if ( ! V_180 )
continue;
V_103 = (struct V_52 * ) V_101 ;
V_101 += sizeof( struct V_52 ) ;
V_103 -> V_104 = V_181 ;
V_103 -> V_175 = V_182 | V_183 | V_184 ;
V_103 -> V_108 = V_179 ;
if ( V_179 == V_46 ) {
V_103 -> V_108 = V_23 . V_44 . V_42 ;
}
V_103 -> V_106 = V_179 ;
V_103 -> V_176 = ( unsigned long ) F_26 ( V_179 ) ;
V_103 -> V_109 = V_180 ;
V_103 -> V_111 = V_180 ;
V_103 -> V_177 = 0 ;
( V_102 -> V_168 ) ++ ;
}
return 0 ;
}
static unsigned long F_61 ( unsigned long V_24 )
{
struct V_50 * V_69 ;
if ( ! V_24 )
return 0 ;
V_10 . V_57 = V_24 ;
V_69 = F_26 ( V_24 ) ;
V_24 += sizeof( struct V_50 ) ;
memset ( V_69 , 0 , sizeof( struct V_50 ) ) ;
V_69 -> V_125 = V_136 ;
V_69 -> V_133 = V_24 ;
V_69 -> V_70 = V_185 ;
return V_24 ;
}
static void F_62 ( void )
{
unsigned long V_24 ;
void * V_112 ;
if ( ! V_10 . V_59 )
return;
F_56 () ;
V_24 = V_23 . V_44 . V_42 + V_23 . V_44 . V_41 ;
V_24 = F_61 ( V_24 ) ;
V_112 = F_26 ( V_24 ) ;
F_7 ( L_63 , V_24 ) ;
F_59 ( V_112 ) ;
F_21 ( & V_23 ) ;
}
static int F_63 ( struct V_22 * V_23 )
{
int V_61 = 0 ;
unsigned int V_62 ;
F_7 ( L_64 ) ;
do {
V_61 = F_22 ( V_10 . V_12 , 3 , 1 , NULL ,
V_186 , V_23 ,
sizeof( struct V_22 ) ) ;
V_62 = F_23 ( V_61 ) ;
if ( V_62 )
F_24 ( V_62 ) ;
} while ( V_62 );
if ( V_61 ) {
F_16 ( V_64 L_65
L_66 , V_61 ) ;
return V_61 ;
}
V_10 . V_65 = 0 ;
return 0 ;
}
static int F_64 ( struct V_22 * V_23 )
{
int V_61 = 0 ;
unsigned int V_62 ;
F_7 ( L_67 ) ;
do {
V_61 = F_22 ( V_10 . V_12 , 3 , 1 , NULL ,
V_187 , V_23 ,
sizeof( struct V_22 ) ) ;
V_62 = F_23 ( V_61 ) ;
if ( V_62 )
F_24 ( V_62 ) ;
} while ( V_62 );
if ( V_61 ) {
F_16 ( V_64 L_68
L_69 , V_61 ) ;
return V_61 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_65 ( void )
{
if ( V_10 . V_14 ) {
F_8 ( & V_23 ,
V_13 -> V_31 . V_42 ) ;
F_64 ( & V_23 ) ;
}
}
static void F_66 ( unsigned long V_188 , unsigned long V_137 )
{
unsigned long V_24 ;
unsigned long V_141 , V_142 ;
V_141 = V_10 . V_58 ;
V_142 = V_141 + V_10 . V_59 ;
for ( V_24 = V_188 ; V_24 < V_137 ; V_24 += V_189 ) {
if ( V_24 <= V_142 && ( ( V_24 + V_189 ) > V_141 ) )
continue;
F_46 ( F_67 ( V_24 >> V_190 ) ) ;
F_68 ( F_67 ( V_24 >> V_190 ) ) ;
F_69 ( ( unsigned long ) F_26 ( V_24 ) ) ;
V_191 ++ ;
}
}
static void F_70 ( void )
{
unsigned long V_192 , V_193 ;
unsigned long V_42 ;
F_71 ( & V_194 ) ;
if ( ! V_10 . V_14 ) {
F_72 ( & V_194 ) ;
return;
}
V_42 = V_13 -> V_31 . V_42 ;
F_65 () ;
F_72 ( & V_194 ) ;
V_192 = V_10 . V_58 ;
V_193 = V_192 +
V_10 . V_59 ;
V_10 . V_58 = V_42 ;
V_10 . V_59 = F_12 () ;
F_66 ( V_192 , V_193 ) ;
if ( V_10 . V_107 ) {
F_45 (
( unsigned long ) F_26 ( V_10 . V_107 ) ,
V_10 . V_110 ) ;
V_10 . V_107 = 0 ;
V_10 . V_110 = 0 ;
}
F_8 ( & V_23 , V_10 . V_58 ) ;
}
static T_5 F_73 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
const char * V_88 , T_4 V_115 )
{
if ( ! V_10 . V_14 )
return - V_199 ;
if ( V_88 [ 0 ] == '1' ) {
F_74 () ;
F_70 () ;
} else
return - V_124 ;
return V_115 ;
}
static T_5 F_75 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
char * V_88 )
{
return sprintf ( V_88 , L_70 , V_10 . V_20 ) ;
}
static T_5 F_76 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
char * V_88 )
{
return sprintf ( V_88 , L_70 , V_10 . V_65 ) ;
}
static T_5 F_77 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
const char * V_88 , T_4 V_115 )
{
int V_200 = 0 ;
if ( ! V_10 . V_20 || V_13 )
return - V_199 ;
F_71 ( & V_194 ) ;
switch ( V_88 [ 0 ] ) {
case '0' :
if ( V_10 . V_65 == 0 ) {
V_200 = - V_124 ;
goto V_201;
}
F_63 ( & V_23 ) ;
break;
case '1' :
if ( V_10 . V_65 == 1 ) {
V_200 = - V_124 ;
goto V_201;
}
F_62 () ;
break;
default:
V_200 = - V_124 ;
break;
}
V_201:
F_72 ( & V_194 ) ;
return V_200 < 0 ? V_200 : V_115 ;
}
static int F_78 ( struct V_202 * V_203 , void * V_204 )
{
const struct V_22 * V_205 ;
if ( ! V_10 . V_20 )
return 0 ;
F_71 ( & V_194 ) ;
if ( V_13 )
V_205 = V_13 ;
else {
F_72 ( & V_194 ) ;
V_205 = & V_23 ;
}
F_79 ( V_203 ,
L_71
L_72 ,
V_205 -> V_31 . V_42 ,
V_205 -> V_31 . V_42 +
V_205 -> V_31 . V_41 - 1 ,
V_205 -> V_31 . V_41 ,
V_205 -> V_31 . V_123 ) ;
F_79 ( V_203 ,
L_73
L_72 ,
V_205 -> V_43 . V_42 ,
V_205 -> V_43 . V_42 +
V_205 -> V_43 . V_41 - 1 ,
V_205 -> V_43 . V_41 ,
V_205 -> V_43 . V_123 ) ;
F_79 ( V_203 ,
L_74
L_72 ,
V_205 -> V_44 . V_42 ,
V_205 -> V_44 . V_42 +
V_205 -> V_44 . V_41 - 1 ,
V_205 -> V_44 . V_41 ,
V_205 -> V_44 . V_123 ) ;
if ( ! V_13 ||
( V_10 . V_58 ==
V_205 -> V_31 . V_42 ) )
goto V_206;
F_79 ( V_203 ,
L_75
L_72 ,
( unsigned long long ) V_10 . V_58 ,
V_205 -> V_31 . V_42 - 1 ,
V_205 -> V_31 . V_42 -
V_10 . V_58 ,
V_205 -> V_31 . V_42 -
V_10 . V_58 ) ;
V_206:
if ( V_13 )
F_72 ( & V_194 ) ;
return 0 ;
}
static int F_80 ( struct V_207 * V_207 , struct V_208 * V_208 )
{
return F_81 ( V_208 , F_78 , V_207 -> V_209 ) ;
}
static void F_82 ( void )
{
struct V_210 * V_211 ;
int V_61 = 0 ;
V_61 = F_83 ( V_212 , & V_213 . V_198 ) ;
if ( V_61 )
F_16 ( V_64 L_76
L_77 , V_61 ) ;
V_61 = F_83 ( V_212 , & V_214 . V_198 ) ;
if ( V_61 )
F_16 ( V_64 L_76
L_78 , V_61 ) ;
V_211 = F_84 ( L_79 , 0444 ,
V_215 , NULL ,
& V_216 ) ;
if ( ! V_211 )
F_16 ( V_64 L_80
L_81 ) ;
if ( V_10 . V_14 ) {
V_61 = F_83 ( V_212 , & V_217 . V_198 ) ;
if ( V_61 )
F_16 ( V_64 L_76
L_82 , V_61 ) ;
}
return;
}
int T_1 F_85 ( void )
{
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_16 ( V_64 L_16
L_17 ) ;
return 0 ;
}
F_6 () ;
if ( V_10 . V_14 ) {
if ( F_52 ( V_13 ) < 0 )
F_70 () ;
}
else if ( V_10 . V_59 )
F_8 ( & V_23 , V_10 . V_58 ) ;
F_82 () ;
return 1 ;
}
