int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
const T_2 * V_5 ;
int V_6 , V_7 ;
int V_8 ;
const T_2 * V_9 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_9 = F_2 ( V_1 , L_2 , NULL ) ;
if ( ! V_9 )
return 1 ;
V_10 . V_11 = 1 ;
V_10 . V_12 = F_3 ( * V_9 ) ;
V_13 = F_2 ( V_1 , L_3 , NULL ) ;
if ( V_13 )
V_10 . V_14 = 1 ;
V_5 = F_2 ( V_1 , L_4 ,
& V_8 ) ;
if ( ! V_5 )
return 1 ;
V_7 = V_8 / ( 3 * sizeof( V_15 ) ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ , V_5 += 3 ) {
V_15 type = ( V_15 ) F_4 ( V_5 , 1 ) ;
switch ( type ) {
case V_16 :
V_10 . V_17 =
F_5 ( & V_5 [ 1 ] , 2 ) ;
break;
case V_18 :
V_10 . V_19 =
F_5 ( & V_5 [ 1 ] , 2 ) ;
break;
}
}
return 1 ;
}
int F_6 ( void )
{
return V_10 . V_14 ;
}
static void F_7 ( void )
{
F_8 ( L_5 ,
( V_10 . V_11 ? L_6 : L_7 ) ) ;
if ( ! V_10 . V_11 )
return;
F_8 ( L_8 ,
( V_10 . V_20 ? L_9 : L_10 ) ) ;
F_8 ( L_11 ,
( V_10 . V_14 ? L_9 : L_10 ) ) ;
F_8 ( L_12 ) ;
F_8 ( L_13 , V_10 . V_17 ) ;
F_8 ( L_14 , V_10 . V_19 ) ;
F_8 ( L_15 , V_10 . V_21 ) ;
}
static unsigned long F_9 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
if ( ! V_23 )
return 0 ;
memset ( V_23 , 0 , sizeof( struct V_22 ) ) ;
V_24 = V_24 & V_25 ;
V_23 -> V_26 . V_27 = F_10 ( 0x00000001 ) ;
V_23 -> V_26 . V_28 = F_11 ( 3 ) ;
V_23 -> V_26 . V_29 = 0 ;
V_23 -> V_26 . V_30 =
F_10 ( ( V_15 ) F_12 ( struct V_22 , V_31 ) ) ;
V_23 -> V_26 . V_32 = 0 ;
V_23 -> V_26 . V_33 = 0 ;
V_23 -> V_26 . V_34 = 0 ;
V_23 -> V_26 . V_35 = 0 ;
V_23 -> V_26 . V_36 = 0 ;
V_23 -> V_31 . V_37 = F_10 ( V_38 ) ;
V_23 -> V_31 . V_39 = F_11 ( V_16 ) ;
V_23 -> V_31 . V_40 = 0 ;
V_23 -> V_31 . V_41 = F_13 ( V_10 . V_17 ) ;
V_23 -> V_31 . V_42 = F_13 ( V_24 ) ;
V_24 += V_10 . V_17 ;
V_23 -> V_43 . V_37 = F_10 ( V_38 ) ;
V_23 -> V_43 . V_39 = F_11 ( V_18 ) ;
V_23 -> V_43 . V_40 = 0 ;
V_23 -> V_43 . V_41 = F_13 ( V_10 . V_19 ) ;
V_23 -> V_43 . V_42 = F_13 ( V_24 ) ;
V_24 += V_10 . V_19 ;
V_23 -> V_44 . V_37 = F_10 ( V_38 ) ;
V_23 -> V_44 . V_39 = F_11 ( V_45 ) ;
V_23 -> V_44 . V_40 = F_13 ( V_46 ) ;
V_23 -> V_44 . V_41 = F_13 ( V_10 . V_21 ) ;
V_23 -> V_44 . V_42 = F_13 ( V_24 ) ;
V_24 += V_10 . V_21 ;
return V_24 ;
}
static inline unsigned long F_14 ( void )
{
unsigned long V_8 ;
if ( V_10 . V_47 )
return V_10 . V_47 ;
V_8 = F_15 () / 20 ;
V_8 = V_8 & ~ 0x0FFFFFFFUL ;
if ( V_48 && V_8 > V_48 )
V_8 = V_48 ;
return ( V_8 > V_49 ? V_8 : V_49 ) ;
}
static unsigned long F_16 ( void )
{
unsigned long V_8 = 0 ;
V_8 += V_10 . V_17 ;
V_8 += V_10 . V_19 ;
V_8 += V_10 . V_21 ;
V_8 += sizeof( struct V_50 ) ;
V_8 += sizeof( struct V_51 ) ;
V_8 += sizeof( struct V_52 ) ;
V_8 += sizeof( struct V_52 ) * ( F_17 ( V_53 ) + 2 ) ;
V_8 = F_18 ( V_8 ) ;
return V_8 ;
}
int T_1 F_19 ( void )
{
unsigned long V_54 , V_8 , V_55 ;
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_20 ( V_56 L_16
L_17 ) ;
V_10 . V_20 = 0 ;
return 0 ;
}
if ( V_13 )
V_10 . V_21 = F_21 ( V_13 -> V_44 . V_41 ) ;
else
V_10 . V_21 = F_14 () ;
if ( V_48 && V_48 < F_15 () ) {
V_8 = F_16 () ;
if ( ( V_48 + V_8 ) < F_15 () )
V_48 += V_8 ;
else
V_48 = F_15 () ;
F_20 ( V_56 L_18
L_19 , V_48 ) ;
}
if ( V_48 )
V_55 = V_48 ;
else
V_55 = F_15 () ;
if ( V_10 . V_14 ) {
F_20 ( V_56 L_20 ) ;
V_54 = V_10 . V_21 ;
V_8 = V_55 - V_54 ;
F_22 ( V_54 , V_8 ) ;
F_20 ( V_56 L_21
L_22 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_54 >> 20 ) ) ;
V_10 . V_57 =
F_21 ( V_13 -> V_44 . V_42 ) +
F_21 ( V_13 -> V_44 . V_41 ) ;
F_8 ( L_23 ,
( void * ) V_10 . V_57 ) ;
} else {
V_8 = F_16 () ;
V_54 = V_55 - V_8 ;
F_22 ( V_54 , V_8 ) ;
F_20 ( V_56 L_21
L_24 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_54 >> 20 ) ) ;
}
V_10 . V_58 = V_54 ;
V_10 . V_59 = V_8 ;
return 1 ;
}
unsigned long T_1 F_23 ( void )
{
return F_24 () / V_60 ;
}
static int T_1 F_25 ( char * V_61 )
{
if ( ! V_61 )
return 1 ;
if ( strncmp ( V_61 , L_25 , 2 ) == 0 )
V_10 . V_20 = 1 ;
else if ( strncmp ( V_61 , L_26 , 3 ) == 0 )
V_10 . V_20 = 0 ;
return 0 ;
}
static int T_1 F_26 ( char * V_61 )
{
if ( V_61 )
V_10 . V_47 = F_27 ( V_61 , & V_61 ) ;
return 0 ;
}
static void F_28 ( struct V_22 * V_23 )
{
int V_62 ;
unsigned int V_63 ;
F_8 ( L_27 ) ;
do {
V_62 = F_29 ( V_10 . V_12 , 3 , 1 , NULL ,
V_64 , V_23 ,
sizeof( struct V_22 ) ) ;
V_63 = F_30 ( V_62 ) ;
if ( V_63 )
F_31 ( V_63 ) ;
} while ( V_63 );
switch ( V_62 ) {
case - 1 :
F_20 ( V_65 L_28
L_29 , V_62 ) ;
break;
case - 3 :
F_20 ( V_65 L_28
L_30 , V_62 ) ;
break;
case - 9 :
F_20 ( V_65 L_31
L_32 ) ;
V_10 . V_66 = 1 ;
break;
case 0 :
F_20 ( V_56 L_33
L_34 ) ;
V_10 . V_66 = 1 ;
break;
}
}
void F_32 ( struct V_67 * V_68 , const char * V_69 )
{
struct V_50 * V_70 = NULL ;
int V_71 , V_72 ;
if ( ! V_10 . V_66 || ! V_10 . V_57 )
return;
V_72 = F_33 () ;
V_71 = F_34 ( & V_73 , - 1 , V_72 ) ;
if ( V_71 != - 1 ) {
while ( V_10 . V_66 )
F_35 () ;
return;
}
V_70 = F_36 ( V_10 . V_57 ) ;
V_70 -> V_73 = V_73 ;
F_37 () ;
if ( V_68 )
V_70 -> V_68 = * V_68 ;
else
F_38 ( & V_70 -> V_68 ) ;
V_70 -> V_74 = * V_75 ;
F_39 ( ( char * ) V_69 ) ;
}
static inline int F_40 ( T_3 V_76 )
{
int V_6 = - 1 ;
char V_69 [ 3 ] ;
if ( ( V_76 & V_77 ) == F_41 ( L_35 ) ) {
V_76 &= ~ V_77 ;
V_76 >>= 24 ;
V_69 [ 2 ] = '\0' ;
V_69 [ 1 ] = V_76 & 0xff ;
V_69 [ 0 ] = ( V_76 >> 8 ) & 0xff ;
sscanf ( V_69 , L_36 , & V_6 ) ;
if ( V_6 > 31 )
V_6 = - 1 ;
}
return V_6 ;
}
static inline void F_42 ( struct V_67 * V_68 , T_3 V_78 ,
T_3 V_79 )
{
int V_6 ;
V_6 = F_40 ( V_78 ) ;
if ( V_6 >= 0 )
V_68 -> V_80 [ V_6 ] = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_37 ) )
V_68 -> V_81 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_38 ) )
V_68 -> V_82 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_39 ) )
V_68 -> V_83 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_40 ) )
V_68 -> V_84 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_41 ) )
V_68 -> V_85 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_42 ) )
V_68 -> V_86 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_43 ) )
V_68 -> V_87 = ( unsigned long ) V_79 ;
else if ( V_78 == F_41 ( L_44 ) )
V_68 -> V_88 = ( unsigned long ) V_79 ;
}
static struct V_89 *
F_43 ( struct V_89 * V_90 , struct V_67 * V_68 )
{
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
while ( F_21 ( V_90 -> V_78 ) != F_41 ( L_45 ) ) {
F_42 ( V_68 , F_21 ( V_90 -> V_78 ) ,
F_21 ( V_90 -> V_91 ) ) ;
V_90 ++ ;
}
V_90 ++ ;
return V_90 ;
}
static V_15 * F_44 ( V_15 * V_92 , char * V_93 , unsigned type ,
void * V_4 , T_4 V_94 )
{
struct V_95 V_96 ;
V_96 . V_97 = strlen ( V_93 ) + 1 ;
V_96 . V_98 = V_94 ;
V_96 . V_99 = type ;
memcpy ( V_92 , & V_96 , sizeof( V_96 ) ) ;
V_92 += ( sizeof( V_96 ) + 3 ) / 4 ;
memcpy ( V_92 , V_93 , V_96 . V_97 ) ;
V_92 += ( V_96 . V_97 + 3 ) / 4 ;
memcpy ( V_92 , V_4 , V_96 . V_98 ) ;
V_92 += ( V_96 . V_98 + 3 ) / 4 ;
return V_92 ;
}
static void F_45 ( V_15 * V_92 )
{
struct V_95 V_96 ;
V_96 . V_97 = 0 ;
V_96 . V_98 = 0 ;
V_96 . V_99 = 0 ;
memcpy ( V_92 , & V_96 , sizeof( V_96 ) ) ;
}
static V_15 * F_46 ( V_15 * V_92 , struct V_67 * V_68 )
{
struct V_100 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_47 ( & V_101 . V_102 , V_68 ) ;
V_92 = F_44 ( V_92 , V_103 , V_104 ,
& V_101 , sizeof( V_101 ) ) ;
return V_92 ;
}
static void F_48 ( char * V_105 )
{
struct V_51 * V_106 ;
struct V_52 * V_107 ;
V_106 = (struct V_51 * ) V_105 ;
V_105 += sizeof( struct V_51 ) ;
V_107 = (struct V_52 * ) V_105 ;
if ( V_107 -> V_108 == V_109 ) {
V_107 -> V_110 = V_10 . V_111 ;
V_107 -> V_112 = V_107 -> V_110 ;
V_107 -> V_113 = V_10 . V_114 ;
V_107 -> V_115 = V_10 . V_114 ;
}
return;
}
static void * F_49 ( unsigned long V_8 )
{
void * V_116 ;
struct V_117 * V_117 ;
unsigned long V_118 , V_119 , V_6 ;
V_118 = F_50 ( V_8 ) ;
V_116 = ( void * ) F_51 ( V_120 | V_121 , V_118 ) ;
if ( ! V_116 )
return NULL ;
V_119 = 1 << V_118 ;
V_117 = F_52 ( V_116 ) ;
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ )
F_53 ( V_117 + V_6 ) ;
return V_116 ;
}
static void F_54 ( unsigned long V_116 , unsigned long V_8 )
{
struct V_117 * V_117 ;
unsigned long V_118 , V_119 , V_6 ;
V_118 = F_50 ( V_8 ) ;
V_119 = 1 << V_118 ;
V_117 = F_52 ( V_116 ) ;
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ )
F_55 ( V_117 + V_6 ) ;
F_56 ( V_117 , V_118 ) ;
}
static int T_1 F_57 ( const struct V_22 * V_23 )
{
struct V_122 * V_123 ;
struct V_89 * V_90 ;
struct V_50 * V_70 = NULL ;
void * V_116 ;
unsigned long V_24 ;
V_15 V_124 , * V_125 ;
struct V_67 V_68 ;
int V_6 , V_62 = 0 , V_126 = 0 ;
if ( ! V_23 -> V_31 . V_127 )
return - V_128 ;
V_24 = F_21 ( V_23 -> V_31 . V_42 ) ;
V_116 = F_36 ( V_24 ) ;
V_123 = V_116 ;
if ( F_21 ( V_123 -> V_129 ) != V_130 ) {
F_20 ( V_65 L_46 ) ;
return - V_131 ;
}
F_8 ( L_47 ) ;
F_8 ( L_48 , F_21 ( V_123 -> V_129 ) ) ;
F_8 ( L_49 , F_3 ( V_123 -> V_132 ) ) ;
V_116 += F_3 ( V_123 -> V_132 ) ;
V_124 = F_3 ( * ( ( T_2 * ) ( V_116 ) ) ) ;
F_8 ( L_50 , V_124 ) ;
V_116 += sizeof( V_15 ) ;
V_90 = (struct V_89 * ) V_116 ;
V_10 . V_114 = V_124 * sizeof( V_133 ) ;
V_10 . V_114 = F_18 ( V_10 . V_114 ) ;
V_125 = F_49 ( V_10 . V_114 ) ;
if ( ! V_125 ) {
F_20 ( V_65 L_51
L_52 , V_10 . V_114 ) ;
return - V_134 ;
}
V_10 . V_111 = F_58 ( V_125 ) ;
F_8 ( L_53 ,
( V_124 * sizeof( V_133 ) ) , V_125 ) ;
if ( V_10 . V_57 )
V_70 = F_36 ( V_10 . V_57 ) ;
for ( V_6 = 0 ; V_6 < V_124 ; V_6 ++ ) {
if ( F_21 ( V_90 -> V_78 ) != F_41 ( L_54 ) ) {
F_20 ( V_65 L_55 ) ;
V_62 = - V_131 ;
goto V_135;
}
V_126 = F_21 ( V_90 -> V_91 ) & V_136 ;
if ( V_70 && ! F_59 ( V_126 , & V_70 -> V_74 ) ) {
F_60 ( V_90 ) ;
continue;
}
F_8 ( L_56 , V_126 ) ;
if ( V_70 && V_70 -> V_73 == V_126 ) {
V_68 = V_70 -> V_68 ;
V_125 = F_46 ( V_125 , & V_68 ) ;
F_60 ( V_90 ) ;
} else {
V_90 ++ ;
V_90 = F_43 ( V_90 , & V_68 ) ;
V_125 = F_46 ( V_125 , & V_68 ) ;
}
}
F_45 ( V_125 ) ;
if ( V_70 ) {
F_8 ( L_57 ,
V_70 -> V_137 ) ;
F_48 ( ( char * ) F_36 ( V_70 -> V_137 ) ) ;
}
return 0 ;
V_135:
F_54 ( ( unsigned long ) F_36 ( V_10 . V_111 ) ,
V_10 . V_114 ) ;
V_10 . V_111 = 0 ;
V_10 . V_114 = 0 ;
return V_62 ;
}
static int T_1 F_61 ( const struct V_22 * V_13 )
{
struct V_50 * V_70 ;
int V_62 = 0 ;
if ( ! V_13 || ! V_10 . V_57 )
return - V_128 ;
if ( ( F_62 ( V_13 -> V_26 . V_29 ) == V_138 ) ||
( V_13 -> V_31 . V_139 != 0 ) ||
( V_13 -> V_44 . V_139 != 0 ) ) {
F_20 ( V_65 L_58 ) ;
return - V_128 ;
}
if ( ( V_13 -> V_44 . V_127 !=
V_13 -> V_44 . V_41 ) ||
! V_13 -> V_31 . V_127 ) {
F_20 ( V_65 L_59 ) ;
return - V_128 ;
}
V_70 = F_36 ( V_10 . V_57 ) ;
if ( V_70 -> V_129 != V_140 ) {
F_20 ( V_65 L_60 ) ;
return - V_128 ;
}
V_62 = F_57 ( V_13 ) ;
if ( V_62 )
return V_62 ;
V_137 = V_70 -> V_137 ;
return 0 ;
}
static inline void F_63 ( unsigned long long V_54 ,
unsigned long long V_141 )
{
if ( V_54 == V_141 )
return;
F_8 ( L_61 ,
V_142 , V_54 , V_141 - 1 , ( V_141 - V_54 ) ) ;
V_143 [ V_142 ] . V_54 = V_54 ;
V_143 [ V_142 ] . V_8 = V_141 - V_54 ;
V_142 ++ ;
}
static void F_64 ( unsigned long long V_144 ,
unsigned long long V_141 )
{
unsigned long long V_145 , V_146 ;
V_145 = V_10 . V_58 ;
V_146 = V_145 + V_10 . V_59 ;
if ( ( V_145 < V_141 ) && ( V_146 > V_144 ) ) {
if ( ( V_144 < V_145 ) && ( V_141 > V_146 ) ) {
F_63 ( V_144 , V_145 ) ;
F_63 ( V_146 , V_141 ) ;
} else if ( V_144 < V_145 ) {
F_63 ( V_144 , V_145 ) ;
} else if ( V_146 < V_141 ) {
F_63 ( V_146 , V_141 ) ;
}
} else
F_63 ( V_144 , V_141 ) ;
}
static int F_65 ( char * V_105 )
{
struct V_51 * V_106 ;
V_106 = (struct V_51 * ) V_105 ;
V_105 += sizeof( struct V_51 ) ;
memcpy ( V_106 -> V_147 , V_148 , V_149 ) ;
V_106 -> V_147 [ V_150 ] = V_151 ;
V_106 -> V_147 [ V_152 ] = V_153 ;
V_106 -> V_147 [ V_154 ] = V_155 ;
V_106 -> V_147 [ V_156 ] = V_157 ;
memset ( V_106 -> V_147 + V_158 , 0 , V_159 - V_158 ) ;
V_106 -> V_160 = V_161 ;
V_106 -> V_162 = V_163 ;
V_106 -> V_164 = V_155 ;
V_106 -> V_165 = 0 ;
V_106 -> V_166 = sizeof( struct V_51 ) ;
V_106 -> V_167 = 0 ;
#if F_66 ( V_168 )
V_106 -> V_169 = V_168 ;
#else
V_106 -> V_169 = 0 ;
#endif
V_106 -> V_170 = sizeof( struct V_51 ) ;
V_106 -> V_171 = sizeof( struct V_52 ) ;
V_106 -> V_172 = 0 ;
V_106 -> V_173 = 0 ;
V_106 -> V_174 = 0 ;
V_106 -> V_175 = 0 ;
return 0 ;
}
static void F_67 ( void )
{
struct V_176 * V_177 ;
unsigned long long V_144 , V_141 ;
F_8 ( L_62 ) ;
V_142 = 0 ;
F_63 ( V_46 , V_10 . V_21 ) ;
F_68 (memory, reg) {
V_144 = ( unsigned long long ) V_177 -> V_54 ;
V_141 = V_144 + ( unsigned long long ) V_177 -> V_8 ;
if ( V_144 == V_46 && V_141 >= V_10 . V_21 )
V_144 = V_10 . V_21 ;
F_64 ( V_144 , V_141 ) ;
}
}
static inline unsigned long F_69 ( unsigned long V_178 )
{
if ( V_178 > V_46 && V_178 < V_10 . V_21 )
return F_21 ( V_23 . V_44 . V_42 ) + V_178 ;
else
return V_178 ;
}
static int F_70 ( char * V_105 )
{
struct V_51 * V_106 ;
struct V_52 * V_107 ;
int V_6 ;
F_65 ( V_105 ) ;
V_106 = (struct V_51 * ) V_105 ;
V_105 += sizeof( struct V_51 ) ;
V_107 = (struct V_52 * ) V_105 ;
V_105 += sizeof( struct V_52 ) ;
V_107 -> V_108 = V_109 ;
V_107 -> V_179 = 0 ;
V_107 -> V_180 = 0 ;
V_107 -> V_181 = 0 ;
V_107 -> V_112 = 0 ;
V_107 -> V_110 = 0 ;
V_107 -> V_113 = 0 ;
V_107 -> V_115 = 0 ;
( V_106 -> V_172 ) ++ ;
V_107 = (struct V_52 * ) V_105 ;
V_105 += sizeof( struct V_52 ) ;
V_107 -> V_108 = V_109 ;
V_107 -> V_179 = 0 ;
V_107 -> V_180 = 0 ;
V_107 -> V_181 = 0 ;
V_107 -> V_110 = F_69 ( F_71 () ) ;
V_107 -> V_112 = V_107 -> V_110 ;
V_107 -> V_115 = V_182 ;
V_107 -> V_113 = V_182 ;
( V_106 -> V_172 ) ++ ;
for ( V_6 = 0 ; V_6 < V_142 ; V_6 ++ ) {
unsigned long long V_183 , V_184 ;
V_183 = V_143 [ V_6 ] . V_54 ;
V_184 = V_143 [ V_6 ] . V_8 ;
if ( ! V_184 )
continue;
V_107 = (struct V_52 * ) V_105 ;
V_105 += sizeof( struct V_52 ) ;
V_107 -> V_108 = V_185 ;
V_107 -> V_179 = V_186 | V_187 | V_188 ;
V_107 -> V_112 = V_183 ;
if ( V_183 == V_46 ) {
V_107 -> V_112 = F_21 ( V_23 . V_44 . V_42 ) ;
}
V_107 -> V_110 = V_183 ;
V_107 -> V_180 = ( unsigned long ) F_36 ( V_183 ) ;
V_107 -> V_113 = V_184 ;
V_107 -> V_115 = V_184 ;
V_107 -> V_181 = 0 ;
( V_106 -> V_172 ) ++ ;
}
return 0 ;
}
static unsigned long F_72 ( unsigned long V_24 )
{
struct V_50 * V_70 ;
if ( ! V_24 )
return 0 ;
V_10 . V_57 = V_24 ;
V_70 = F_36 ( V_24 ) ;
V_24 += sizeof( struct V_50 ) ;
memset ( V_70 , 0 , sizeof( struct V_50 ) ) ;
V_70 -> V_129 = V_140 ;
V_70 -> V_137 = V_24 ;
V_70 -> V_73 = V_189 ;
return V_24 ;
}
static void F_73 ( void )
{
unsigned long V_24 ;
void * V_116 ;
if ( ! V_10 . V_59 )
return;
F_67 () ;
V_24 = F_21 ( V_23 . V_44 . V_42 ) + F_21 ( V_23 . V_44 . V_41 ) ;
V_24 = F_72 ( V_24 ) ;
V_116 = F_36 ( V_24 ) ;
F_8 ( L_63 , V_24 ) ;
F_70 ( V_116 ) ;
F_28 ( & V_23 ) ;
}
static int F_74 ( struct V_22 * V_23 )
{
int V_62 = 0 ;
unsigned int V_63 ;
F_8 ( L_64 ) ;
do {
V_62 = F_29 ( V_10 . V_12 , 3 , 1 , NULL ,
V_190 , V_23 ,
sizeof( struct V_22 ) ) ;
V_63 = F_30 ( V_62 ) ;
if ( V_63 )
F_31 ( V_63 ) ;
} while ( V_63 );
if ( V_62 ) {
F_20 ( V_65 L_65
L_66 , V_62 ) ;
return V_62 ;
}
V_10 . V_66 = 0 ;
return 0 ;
}
static int F_75 ( struct V_22 * V_23 )
{
int V_62 = 0 ;
unsigned int V_63 ;
F_8 ( L_67 ) ;
do {
V_62 = F_29 ( V_10 . V_12 , 3 , 1 , NULL ,
V_191 , V_23 ,
sizeof( struct V_22 ) ) ;
V_63 = F_30 ( V_62 ) ;
if ( V_63 )
F_31 ( V_63 ) ;
} while ( V_63 );
if ( V_62 ) {
F_76 ( L_68 , V_62 ) ;
return V_62 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_77 ( void )
{
if ( V_10 . V_14 ) {
F_9 ( & V_23 ,
F_21 ( V_13 -> V_31 . V_42 ) ) ;
F_75 ( & V_23 ) ;
}
}
static void F_78 ( unsigned long V_192 , unsigned long V_141 )
{
unsigned long V_24 ;
unsigned long V_145 , V_146 ;
V_145 = V_10 . V_58 ;
V_146 = V_145 + V_10 . V_59 ;
for ( V_24 = V_192 ; V_24 < V_141 ; V_24 += V_60 ) {
if ( V_24 <= V_146 && ( ( V_24 + V_60 ) > V_145 ) )
continue;
F_79 ( F_80 ( V_24 >> V_193 ) ) ;
}
}
static void F_81 ( void )
{
unsigned long V_194 , V_195 ;
unsigned long V_42 ;
F_82 ( & V_196 ) ;
if ( ! V_10 . V_14 ) {
F_83 ( & V_196 ) ;
return;
}
V_42 = F_21 ( V_13 -> V_31 . V_42 ) ;
F_77 () ;
F_83 ( & V_196 ) ;
V_194 = V_10 . V_58 ;
V_195 = V_194 +
V_10 . V_59 ;
V_10 . V_58 = V_42 ;
V_10 . V_59 = F_16 () ;
F_78 ( V_194 , V_195 ) ;
if ( V_10 . V_111 ) {
F_54 (
( unsigned long ) F_36 ( V_10 . V_111 ) ,
V_10 . V_114 ) ;
V_10 . V_111 = 0 ;
V_10 . V_114 = 0 ;
}
F_9 ( & V_23 , V_10 . V_58 ) ;
}
static T_5 F_84 ( struct V_197 * V_198 ,
struct V_199 * V_200 ,
const char * V_92 , T_4 V_119 )
{
if ( ! V_10 . V_14 )
return - V_201 ;
if ( V_92 [ 0 ] == '1' ) {
#ifdef F_85
F_86 () ;
#endif
F_81 () ;
} else
return - V_128 ;
return V_119 ;
}
static T_5 F_87 ( struct V_197 * V_198 ,
struct V_199 * V_200 ,
char * V_92 )
{
return sprintf ( V_92 , L_69 , V_10 . V_20 ) ;
}
static T_5 F_88 ( struct V_197 * V_198 ,
struct V_199 * V_200 ,
char * V_92 )
{
return sprintf ( V_92 , L_69 , V_10 . V_66 ) ;
}
static T_5 F_89 ( struct V_197 * V_198 ,
struct V_199 * V_200 ,
const char * V_92 , T_4 V_119 )
{
int V_202 = 0 ;
if ( ! V_10 . V_20 || V_13 )
return - V_201 ;
F_82 ( & V_196 ) ;
switch ( V_92 [ 0 ] ) {
case '0' :
if ( V_10 . V_66 == 0 ) {
V_202 = - V_128 ;
goto V_203;
}
F_74 ( & V_23 ) ;
break;
case '1' :
if ( V_10 . V_66 == 1 ) {
V_202 = - V_128 ;
goto V_203;
}
F_73 () ;
break;
default:
V_202 = - V_128 ;
break;
}
V_203:
F_83 ( & V_196 ) ;
return V_202 < 0 ? V_202 : V_119 ;
}
static int F_90 ( struct V_204 * V_205 , void * V_206 )
{
const struct V_22 * V_207 ;
if ( ! V_10 . V_20 )
return 0 ;
F_82 ( & V_196 ) ;
if ( V_13 )
V_207 = V_13 ;
else {
F_83 ( & V_196 ) ;
V_207 = & V_23 ;
}
F_91 ( V_205 ,
L_70
L_71 ,
F_21 ( V_207 -> V_31 . V_42 ) ,
F_21 ( V_207 -> V_31 . V_42 ) +
F_21 ( V_207 -> V_31 . V_41 ) - 1 ,
F_21 ( V_207 -> V_31 . V_41 ) ,
F_21 ( V_207 -> V_31 . V_127 ) ) ;
F_91 ( V_205 ,
L_72
L_71 ,
F_21 ( V_207 -> V_43 . V_42 ) ,
F_21 ( V_207 -> V_43 . V_42 ) +
F_21 ( V_207 -> V_43 . V_41 ) - 1 ,
F_21 ( V_207 -> V_43 . V_41 ) ,
F_21 ( V_207 -> V_43 . V_127 ) ) ;
F_91 ( V_205 ,
L_73
L_71 ,
F_21 ( V_207 -> V_44 . V_42 ) ,
F_21 ( V_207 -> V_44 . V_42 ) +
F_21 ( V_207 -> V_44 . V_41 ) - 1 ,
F_21 ( V_207 -> V_44 . V_41 ) ,
F_21 ( V_207 -> V_44 . V_127 ) ) ;
if ( ! V_13 ||
( V_10 . V_58 ==
F_21 ( V_207 -> V_31 . V_42 ) ) )
goto V_208;
F_91 ( V_205 ,
L_74
L_71 ,
( unsigned long long ) V_10 . V_58 ,
F_21 ( V_207 -> V_31 . V_42 ) - 1 ,
F_21 ( V_207 -> V_31 . V_42 ) -
V_10 . V_58 ,
F_21 ( V_207 -> V_31 . V_42 ) -
V_10 . V_58 ) ;
V_208:
if ( V_13 )
F_83 ( & V_196 ) ;
return 0 ;
}
static int F_92 ( struct V_209 * V_209 , struct V_210 * V_210 )
{
return F_93 ( V_210 , F_90 , V_209 -> V_211 ) ;
}
static void F_94 ( void )
{
struct V_212 * V_213 ;
int V_62 = 0 ;
V_62 = F_95 ( V_214 , & V_215 . V_200 ) ;
if ( V_62 )
F_20 ( V_65 L_75
L_76 , V_62 ) ;
V_62 = F_95 ( V_214 , & V_216 . V_200 ) ;
if ( V_62 )
F_20 ( V_65 L_75
L_77 , V_62 ) ;
V_213 = F_96 ( L_78 , 0444 ,
V_217 , NULL ,
& V_218 ) ;
if ( ! V_213 )
F_20 ( V_65 L_79
L_80 ) ;
if ( V_10 . V_14 ) {
V_62 = F_95 ( V_214 , & V_219 . V_200 ) ;
if ( V_62 )
F_20 ( V_65 L_75
L_81 , V_62 ) ;
}
return;
}
int T_1 F_97 ( void )
{
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_20 ( V_65 L_16
L_17 ) ;
return 0 ;
}
F_7 () ;
if ( V_10 . V_14 ) {
if ( F_61 ( V_13 ) < 0 )
F_81 () ;
}
else if ( V_10 . V_59 )
F_9 ( & V_23 , V_10 . V_58 ) ;
F_94 () ;
return 1 ;
}
