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
if ( ! V_10 . V_66 || ! V_10 . V_57 )
return;
V_70 = F_33 ( V_10 . V_57 ) ;
V_71 = F_34 () ;
V_70 -> V_71 = V_71 ;
F_35 () ;
if ( V_68 )
V_70 -> V_68 = * V_68 ;
else
F_36 ( & V_70 -> V_68 ) ;
V_70 -> V_72 = * V_73 ;
F_37 ( ( char * ) V_69 ) ;
}
static inline int F_38 ( T_3 V_74 )
{
int V_6 = - 1 ;
char V_69 [ 3 ] ;
if ( ( V_74 & V_75 ) == F_39 ( L_35 ) ) {
V_74 &= ~ V_75 ;
V_74 >>= 24 ;
V_69 [ 2 ] = '\0' ;
V_69 [ 1 ] = V_74 & 0xff ;
V_69 [ 0 ] = ( V_74 >> 8 ) & 0xff ;
sscanf ( V_69 , L_36 , & V_6 ) ;
if ( V_6 > 31 )
V_6 = - 1 ;
}
return V_6 ;
}
static inline void F_40 ( struct V_67 * V_68 , T_3 V_76 ,
T_3 V_77 )
{
int V_6 ;
V_6 = F_38 ( V_76 ) ;
if ( V_6 >= 0 )
V_68 -> V_78 [ V_6 ] = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_37 ) )
V_68 -> V_79 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_38 ) )
V_68 -> V_80 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_39 ) )
V_68 -> V_81 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_40 ) )
V_68 -> V_82 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_41 ) )
V_68 -> V_83 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_42 ) )
V_68 -> V_84 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_43 ) )
V_68 -> V_85 = ( unsigned long ) V_77 ;
else if ( V_76 == F_39 ( L_44 ) )
V_68 -> V_86 = ( unsigned long ) V_77 ;
}
static struct V_87 *
F_41 ( struct V_87 * V_88 , struct V_67 * V_68 )
{
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
while ( F_21 ( V_88 -> V_76 ) != F_39 ( L_45 ) ) {
F_40 ( V_68 , F_21 ( V_88 -> V_76 ) ,
F_21 ( V_88 -> V_89 ) ) ;
V_88 ++ ;
}
V_88 ++ ;
return V_88 ;
}
static V_15 * F_42 ( V_15 * V_90 , char * V_91 , unsigned type ,
void * V_4 , T_4 V_92 )
{
struct V_93 V_94 ;
V_94 . V_95 = strlen ( V_91 ) + 1 ;
V_94 . V_96 = V_92 ;
V_94 . V_97 = type ;
memcpy ( V_90 , & V_94 , sizeof( V_94 ) ) ;
V_90 += ( sizeof( V_94 ) + 3 ) / 4 ;
memcpy ( V_90 , V_91 , V_94 . V_95 ) ;
V_90 += ( V_94 . V_95 + 3 ) / 4 ;
memcpy ( V_90 , V_4 , V_94 . V_96 ) ;
V_90 += ( V_94 . V_96 + 3 ) / 4 ;
return V_90 ;
}
static void F_43 ( V_15 * V_90 )
{
struct V_93 V_94 ;
V_94 . V_95 = 0 ;
V_94 . V_96 = 0 ;
V_94 . V_97 = 0 ;
memcpy ( V_90 , & V_94 , sizeof( V_94 ) ) ;
}
static V_15 * F_44 ( V_15 * V_90 , struct V_67 * V_68 )
{
struct V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_45 ( & V_99 . V_100 , V_68 ) ;
V_90 = F_42 ( V_90 , V_101 , V_102 ,
& V_99 , sizeof( V_99 ) ) ;
return V_90 ;
}
static void F_46 ( char * V_103 )
{
struct V_51 * V_104 ;
struct V_52 * V_105 ;
V_104 = (struct V_51 * ) V_103 ;
V_103 += sizeof( struct V_51 ) ;
V_105 = (struct V_52 * ) V_103 ;
if ( V_105 -> V_106 == V_107 ) {
V_105 -> V_108 = V_10 . V_109 ;
V_105 -> V_110 = V_105 -> V_108 ;
V_105 -> V_111 = V_10 . V_112 ;
V_105 -> V_113 = V_10 . V_112 ;
}
return;
}
static void * F_47 ( unsigned long V_8 )
{
void * V_114 ;
struct V_115 * V_115 ;
unsigned long V_116 , V_117 , V_6 ;
V_116 = F_48 ( V_8 ) ;
V_114 = ( void * ) F_49 ( V_118 | V_119 , V_116 ) ;
if ( ! V_114 )
return NULL ;
V_117 = 1 << V_116 ;
V_115 = F_50 ( V_114 ) ;
for ( V_6 = 0 ; V_6 < V_117 ; V_6 ++ )
F_51 ( V_115 + V_6 ) ;
return V_114 ;
}
static void F_52 ( unsigned long V_114 , unsigned long V_8 )
{
struct V_115 * V_115 ;
unsigned long V_116 , V_117 , V_6 ;
V_116 = F_48 ( V_8 ) ;
V_117 = 1 << V_116 ;
V_115 = F_50 ( V_114 ) ;
for ( V_6 = 0 ; V_6 < V_117 ; V_6 ++ )
F_53 ( V_115 + V_6 ) ;
F_54 ( V_115 , V_116 ) ;
}
static int T_1 F_55 ( const struct V_22 * V_23 )
{
struct V_120 * V_121 ;
struct V_87 * V_88 ;
struct V_50 * V_70 = NULL ;
void * V_114 ;
unsigned long V_24 ;
V_15 V_122 , * V_123 ;
struct V_67 V_68 ;
int V_6 , V_62 = 0 , V_124 = 0 ;
if ( ! V_23 -> V_31 . V_125 )
return - V_126 ;
V_24 = F_21 ( V_23 -> V_31 . V_42 ) ;
V_114 = F_33 ( V_24 ) ;
V_121 = V_114 ;
if ( F_21 ( V_121 -> V_127 ) != V_128 ) {
F_20 ( V_65 L_46 ) ;
return - V_129 ;
}
F_8 ( L_47 ) ;
F_8 ( L_48 , F_21 ( V_121 -> V_127 ) ) ;
F_8 ( L_49 , F_3 ( V_121 -> V_130 ) ) ;
V_114 += F_3 ( V_121 -> V_130 ) ;
V_122 = F_3 ( * ( ( T_2 * ) ( V_114 ) ) ) ;
F_8 ( L_50 , V_122 ) ;
V_114 += sizeof( V_15 ) ;
V_88 = (struct V_87 * ) V_114 ;
V_10 . V_112 = V_122 * sizeof( V_131 ) ;
V_10 . V_112 = F_18 ( V_10 . V_112 ) ;
V_123 = F_47 ( V_10 . V_112 ) ;
if ( ! V_123 ) {
F_20 ( V_65 L_51
L_52 , V_10 . V_112 ) ;
return - V_132 ;
}
V_10 . V_109 = F_56 ( V_123 ) ;
F_8 ( L_53 ,
( V_122 * sizeof( V_131 ) ) , V_123 ) ;
if ( V_10 . V_57 )
V_70 = F_33 ( V_10 . V_57 ) ;
for ( V_6 = 0 ; V_6 < V_122 ; V_6 ++ ) {
if ( F_21 ( V_88 -> V_76 ) != F_39 ( L_54 ) ) {
F_20 ( V_65 L_55 ) ;
V_62 = - V_129 ;
goto V_133;
}
V_124 = F_21 ( V_88 -> V_89 ) & V_134 ;
if ( V_70 && ! F_57 ( V_124 , & V_70 -> V_72 ) ) {
F_58 ( V_88 ) ;
continue;
}
F_8 ( L_56 , V_124 ) ;
if ( V_70 && V_70 -> V_71 == V_124 ) {
V_68 = V_70 -> V_68 ;
V_123 = F_44 ( V_123 , & V_68 ) ;
F_58 ( V_88 ) ;
} else {
V_88 ++ ;
V_88 = F_41 ( V_88 , & V_68 ) ;
V_123 = F_44 ( V_123 , & V_68 ) ;
}
}
F_43 ( V_123 ) ;
if ( V_70 ) {
F_8 ( L_57 ,
V_70 -> V_135 ) ;
F_46 ( ( char * ) F_33 ( V_70 -> V_135 ) ) ;
}
return 0 ;
V_133:
F_52 ( ( unsigned long ) F_33 ( V_10 . V_109 ) ,
V_10 . V_112 ) ;
V_10 . V_109 = 0 ;
V_10 . V_112 = 0 ;
return V_62 ;
}
static int T_1 F_59 ( const struct V_22 * V_13 )
{
struct V_50 * V_70 ;
int V_62 = 0 ;
if ( ! V_13 || ! V_10 . V_57 )
return - V_126 ;
if ( ( F_60 ( V_13 -> V_26 . V_29 ) == V_136 ) ||
( V_13 -> V_31 . V_137 != 0 ) ||
( V_13 -> V_44 . V_137 != 0 ) ) {
F_20 ( V_65 L_58 ) ;
return - V_126 ;
}
if ( ( V_13 -> V_44 . V_125 !=
V_13 -> V_44 . V_41 ) ||
! V_13 -> V_31 . V_125 ) {
F_20 ( V_65 L_59 ) ;
return - V_126 ;
}
V_70 = F_33 ( V_10 . V_57 ) ;
if ( V_70 -> V_127 != V_138 ) {
F_20 ( V_65 L_60 ) ;
return - V_126 ;
}
V_62 = F_55 ( V_13 ) ;
if ( V_62 )
return V_62 ;
V_135 = V_70 -> V_135 ;
return 0 ;
}
static inline void F_61 ( unsigned long long V_54 ,
unsigned long long V_139 )
{
if ( V_54 == V_139 )
return;
F_8 ( L_61 ,
V_140 , V_54 , V_139 - 1 , ( V_139 - V_54 ) ) ;
V_141 [ V_140 ] . V_54 = V_54 ;
V_141 [ V_140 ] . V_8 = V_139 - V_54 ;
V_140 ++ ;
}
static void F_62 ( unsigned long long V_142 ,
unsigned long long V_139 )
{
unsigned long long V_143 , V_144 ;
V_143 = V_10 . V_58 ;
V_144 = V_143 + V_10 . V_59 ;
if ( ( V_143 < V_139 ) && ( V_144 > V_142 ) ) {
if ( ( V_142 < V_143 ) && ( V_139 > V_144 ) ) {
F_61 ( V_142 , V_143 ) ;
F_61 ( V_144 , V_139 ) ;
} else if ( V_142 < V_143 ) {
F_61 ( V_142 , V_143 ) ;
} else if ( V_144 < V_139 ) {
F_61 ( V_144 , V_139 ) ;
}
} else
F_61 ( V_142 , V_139 ) ;
}
static int F_63 ( char * V_103 )
{
struct V_51 * V_104 ;
V_104 = (struct V_51 * ) V_103 ;
V_103 += sizeof( struct V_51 ) ;
memcpy ( V_104 -> V_145 , V_146 , V_147 ) ;
V_104 -> V_145 [ V_148 ] = V_149 ;
V_104 -> V_145 [ V_150 ] = V_151 ;
V_104 -> V_145 [ V_152 ] = V_153 ;
V_104 -> V_145 [ V_154 ] = V_155 ;
memset ( V_104 -> V_145 + V_156 , 0 , V_157 - V_156 ) ;
V_104 -> V_158 = V_159 ;
V_104 -> V_160 = V_161 ;
V_104 -> V_162 = V_153 ;
V_104 -> V_163 = 0 ;
V_104 -> V_164 = sizeof( struct V_51 ) ;
V_104 -> V_165 = 0 ;
#if F_64 ( V_166 )
V_104 -> V_167 = V_166 ;
#else
V_104 -> V_167 = 0 ;
#endif
V_104 -> V_168 = sizeof( struct V_51 ) ;
V_104 -> V_169 = sizeof( struct V_52 ) ;
V_104 -> V_170 = 0 ;
V_104 -> V_171 = 0 ;
V_104 -> V_172 = 0 ;
V_104 -> V_173 = 0 ;
return 0 ;
}
static void F_65 ( void )
{
struct V_174 * V_175 ;
unsigned long long V_142 , V_139 ;
F_8 ( L_62 ) ;
V_140 = 0 ;
F_61 ( V_46 , V_10 . V_21 ) ;
F_66 (memory, reg) {
V_142 = ( unsigned long long ) V_175 -> V_54 ;
V_139 = V_142 + ( unsigned long long ) V_175 -> V_8 ;
if ( V_142 == V_46 && V_139 >= V_10 . V_21 )
V_142 = V_10 . V_21 ;
F_62 ( V_142 , V_139 ) ;
}
}
static inline unsigned long F_67 ( unsigned long V_176 )
{
if ( V_176 > V_46 && V_176 < V_10 . V_21 )
return F_21 ( V_23 . V_44 . V_42 ) + V_176 ;
else
return V_176 ;
}
static int F_68 ( char * V_103 )
{
struct V_51 * V_104 ;
struct V_52 * V_105 ;
int V_6 ;
F_63 ( V_103 ) ;
V_104 = (struct V_51 * ) V_103 ;
V_103 += sizeof( struct V_51 ) ;
V_105 = (struct V_52 * ) V_103 ;
V_103 += sizeof( struct V_52 ) ;
V_105 -> V_106 = V_107 ;
V_105 -> V_177 = 0 ;
V_105 -> V_178 = 0 ;
V_105 -> V_179 = 0 ;
V_105 -> V_110 = 0 ;
V_105 -> V_108 = 0 ;
V_105 -> V_111 = 0 ;
V_105 -> V_113 = 0 ;
( V_104 -> V_170 ) ++ ;
V_105 = (struct V_52 * ) V_103 ;
V_103 += sizeof( struct V_52 ) ;
V_105 -> V_106 = V_107 ;
V_105 -> V_177 = 0 ;
V_105 -> V_178 = 0 ;
V_105 -> V_179 = 0 ;
V_105 -> V_108 = F_67 ( F_69 () ) ;
V_105 -> V_110 = V_105 -> V_108 ;
V_105 -> V_113 = V_180 ;
V_105 -> V_111 = V_180 ;
( V_104 -> V_170 ) ++ ;
for ( V_6 = 0 ; V_6 < V_140 ; V_6 ++ ) {
unsigned long long V_181 , V_182 ;
V_181 = V_141 [ V_6 ] . V_54 ;
V_182 = V_141 [ V_6 ] . V_8 ;
if ( ! V_182 )
continue;
V_105 = (struct V_52 * ) V_103 ;
V_103 += sizeof( struct V_52 ) ;
V_105 -> V_106 = V_183 ;
V_105 -> V_177 = V_184 | V_185 | V_186 ;
V_105 -> V_110 = V_181 ;
if ( V_181 == V_46 ) {
V_105 -> V_110 = F_21 ( V_23 . V_44 . V_42 ) ;
}
V_105 -> V_108 = V_181 ;
V_105 -> V_178 = ( unsigned long ) F_33 ( V_181 ) ;
V_105 -> V_111 = V_182 ;
V_105 -> V_113 = V_182 ;
V_105 -> V_179 = 0 ;
( V_104 -> V_170 ) ++ ;
}
return 0 ;
}
static unsigned long F_70 ( unsigned long V_24 )
{
struct V_50 * V_70 ;
if ( ! V_24 )
return 0 ;
V_10 . V_57 = V_24 ;
V_70 = F_33 ( V_24 ) ;
V_24 += sizeof( struct V_50 ) ;
memset ( V_70 , 0 , sizeof( struct V_50 ) ) ;
V_70 -> V_127 = V_138 ;
V_70 -> V_135 = V_24 ;
V_70 -> V_71 = V_187 ;
return V_24 ;
}
static void F_71 ( void )
{
unsigned long V_24 ;
void * V_114 ;
if ( ! V_10 . V_59 )
return;
F_65 () ;
V_24 = F_21 ( V_23 . V_44 . V_42 ) + F_21 ( V_23 . V_44 . V_41 ) ;
V_24 = F_70 ( V_24 ) ;
V_114 = F_33 ( V_24 ) ;
F_8 ( L_63 , V_24 ) ;
F_68 ( V_114 ) ;
F_28 ( & V_23 ) ;
}
static int F_72 ( struct V_22 * V_23 )
{
int V_62 = 0 ;
unsigned int V_63 ;
F_8 ( L_64 ) ;
do {
V_62 = F_29 ( V_10 . V_12 , 3 , 1 , NULL ,
V_188 , V_23 ,
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
static int F_73 ( struct V_22 * V_23 )
{
int V_62 = 0 ;
unsigned int V_63 ;
F_8 ( L_67 ) ;
do {
V_62 = F_29 ( V_10 . V_12 , 3 , 1 , NULL ,
V_189 , V_23 ,
sizeof( struct V_22 ) ) ;
V_63 = F_30 ( V_62 ) ;
if ( V_63 )
F_31 ( V_63 ) ;
} while ( V_63 );
if ( V_62 ) {
F_74 ( L_68 , V_62 ) ;
return V_62 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_75 ( void )
{
if ( V_10 . V_14 ) {
F_9 ( & V_23 ,
F_21 ( V_13 -> V_31 . V_42 ) ) ;
F_73 ( & V_23 ) ;
}
}
static void F_76 ( unsigned long V_190 , unsigned long V_139 )
{
unsigned long V_24 ;
unsigned long V_143 , V_144 ;
V_143 = V_10 . V_58 ;
V_144 = V_143 + V_10 . V_59 ;
for ( V_24 = V_190 ; V_24 < V_139 ; V_24 += V_60 ) {
if ( V_24 <= V_144 && ( ( V_24 + V_60 ) > V_143 ) )
continue;
F_77 ( F_78 ( V_24 >> V_191 ) ) ;
}
}
static void F_79 ( void )
{
unsigned long V_192 , V_193 ;
unsigned long V_42 ;
F_80 ( & V_194 ) ;
if ( ! V_10 . V_14 ) {
F_81 ( & V_194 ) ;
return;
}
V_42 = F_21 ( V_13 -> V_31 . V_42 ) ;
F_75 () ;
F_81 ( & V_194 ) ;
V_192 = V_10 . V_58 ;
V_193 = V_192 +
V_10 . V_59 ;
V_10 . V_58 = V_42 ;
V_10 . V_59 = F_16 () ;
F_76 ( V_192 , V_193 ) ;
if ( V_10 . V_109 ) {
F_52 (
( unsigned long ) F_33 ( V_10 . V_109 ) ,
V_10 . V_112 ) ;
V_10 . V_109 = 0 ;
V_10 . V_112 = 0 ;
}
F_9 ( & V_23 , V_10 . V_58 ) ;
}
static T_5 F_82 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
const char * V_90 , T_4 V_117 )
{
if ( ! V_10 . V_14 )
return - V_199 ;
if ( V_90 [ 0 ] == '1' ) {
#ifdef F_83
F_84 () ;
#endif
F_79 () ;
} else
return - V_126 ;
return V_117 ;
}
static T_5 F_85 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
char * V_90 )
{
return sprintf ( V_90 , L_69 , V_10 . V_20 ) ;
}
static T_5 F_86 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
char * V_90 )
{
return sprintf ( V_90 , L_69 , V_10 . V_66 ) ;
}
static T_5 F_87 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
const char * V_90 , T_4 V_117 )
{
int V_200 = 0 ;
if ( ! V_10 . V_20 || V_13 )
return - V_199 ;
F_80 ( & V_194 ) ;
switch ( V_90 [ 0 ] ) {
case '0' :
if ( V_10 . V_66 == 0 ) {
V_200 = - V_126 ;
goto V_201;
}
F_72 ( & V_23 ) ;
break;
case '1' :
if ( V_10 . V_66 == 1 ) {
V_200 = - V_126 ;
goto V_201;
}
F_71 () ;
break;
default:
V_200 = - V_126 ;
break;
}
V_201:
F_81 ( & V_194 ) ;
return V_200 < 0 ? V_200 : V_117 ;
}
static int F_88 ( struct V_202 * V_203 , void * V_204 )
{
const struct V_22 * V_205 ;
if ( ! V_10 . V_20 )
return 0 ;
F_80 ( & V_194 ) ;
if ( V_13 )
V_205 = V_13 ;
else {
F_81 ( & V_194 ) ;
V_205 = & V_23 ;
}
F_89 ( V_203 ,
L_70
L_71 ,
F_21 ( V_205 -> V_31 . V_42 ) ,
F_21 ( V_205 -> V_31 . V_42 ) +
F_21 ( V_205 -> V_31 . V_41 ) - 1 ,
F_21 ( V_205 -> V_31 . V_41 ) ,
F_21 ( V_205 -> V_31 . V_125 ) ) ;
F_89 ( V_203 ,
L_72
L_71 ,
F_21 ( V_205 -> V_43 . V_42 ) ,
F_21 ( V_205 -> V_43 . V_42 ) +
F_21 ( V_205 -> V_43 . V_41 ) - 1 ,
F_21 ( V_205 -> V_43 . V_41 ) ,
F_21 ( V_205 -> V_43 . V_125 ) ) ;
F_89 ( V_203 ,
L_73
L_71 ,
F_21 ( V_205 -> V_44 . V_42 ) ,
F_21 ( V_205 -> V_44 . V_42 ) +
F_21 ( V_205 -> V_44 . V_41 ) - 1 ,
F_21 ( V_205 -> V_44 . V_41 ) ,
F_21 ( V_205 -> V_44 . V_125 ) ) ;
if ( ! V_13 ||
( V_10 . V_58 ==
F_21 ( V_205 -> V_31 . V_42 ) ) )
goto V_206;
F_89 ( V_203 ,
L_74
L_71 ,
( unsigned long long ) V_10 . V_58 ,
F_21 ( V_205 -> V_31 . V_42 ) - 1 ,
F_21 ( V_205 -> V_31 . V_42 ) -
V_10 . V_58 ,
F_21 ( V_205 -> V_31 . V_42 ) -
V_10 . V_58 ) ;
V_206:
if ( V_13 )
F_81 ( & V_194 ) ;
return 0 ;
}
static int F_90 ( struct V_207 * V_207 , struct V_208 * V_208 )
{
return F_91 ( V_208 , F_88 , V_207 -> V_209 ) ;
}
static void F_92 ( void )
{
struct V_210 * V_211 ;
int V_62 = 0 ;
V_62 = F_93 ( V_212 , & V_213 . V_198 ) ;
if ( V_62 )
F_20 ( V_65 L_75
L_76 , V_62 ) ;
V_62 = F_93 ( V_212 , & V_214 . V_198 ) ;
if ( V_62 )
F_20 ( V_65 L_75
L_77 , V_62 ) ;
V_211 = F_94 ( L_78 , 0444 ,
V_215 , NULL ,
& V_216 ) ;
if ( ! V_211 )
F_20 ( V_65 L_79
L_80 ) ;
if ( V_10 . V_14 ) {
V_62 = F_93 ( V_212 , & V_217 . V_198 ) ;
if ( V_62 )
F_20 ( V_65 L_75
L_81 , V_62 ) ;
}
return;
}
int T_1 F_95 ( void )
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
if ( F_59 ( V_13 ) < 0 )
F_79 () ;
}
else if ( V_10 . V_59 )
F_9 ( & V_23 , V_10 . V_58 ) ;
F_92 () ;
return 1 ;
}
