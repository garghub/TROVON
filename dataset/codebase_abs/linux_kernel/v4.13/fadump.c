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
int F_6 ( T_3 V_20 , T_4 V_8 )
{
if ( ! V_10 . V_21 )
return 0 ;
return ( V_20 + V_8 ) > V_22 && V_20 <= V_10 . V_23 ;
}
int F_7 ( void )
{
return V_10 . V_14 ;
}
static int F_8 ( void )
{
struct V_24 * V_25 ;
unsigned long V_26 , V_27 ;
unsigned long V_28 = F_9 ( V_22 ) ;
unsigned long V_29 = F_9 ( V_22 + V_10 . V_23 ) ;
unsigned int V_30 = 0 ;
F_10 (memory, reg) {
V_26 = F_11 ( V_28 , F_12 ( V_25 ) ) ;
V_27 = F_13 ( V_29 , F_14 ( V_25 ) ) ;
if ( V_26 < V_27 ) {
if ( V_26 > V_28 )
break;
if ( V_27 == V_29 ) {
V_30 = 1 ;
break;
}
V_28 = V_27 + 1 ;
}
}
return V_30 ;
}
static void F_15 ( void )
{
F_16 ( L_5 ,
( V_10 . V_11 ? L_6 : L_7 ) ) ;
if ( ! V_10 . V_11 )
return;
F_16 ( L_8 ,
( V_10 . V_31 ? L_9 : L_10 ) ) ;
F_16 ( L_11 ,
( V_10 . V_14 ? L_9 : L_10 ) ) ;
F_16 ( L_12 ) ;
F_16 ( L_13 , V_10 . V_17 ) ;
F_16 ( L_14 , V_10 . V_19 ) ;
F_16 ( L_15 , V_10 . V_23 ) ;
}
static unsigned long F_17 ( struct V_32 * V_33 ,
unsigned long V_20 )
{
if ( ! V_33 )
return 0 ;
memset ( V_33 , 0 , sizeof( struct V_32 ) ) ;
V_20 = V_20 & V_34 ;
V_33 -> V_35 . V_36 = F_18 ( 0x00000001 ) ;
V_33 -> V_35 . V_37 = F_19 ( 3 ) ;
V_33 -> V_35 . V_38 = 0 ;
V_33 -> V_35 . V_39 =
F_18 ( ( V_15 ) F_20 ( struct V_32 , V_40 ) ) ;
V_33 -> V_35 . V_41 = 0 ;
V_33 -> V_35 . V_42 = 0 ;
V_33 -> V_35 . V_43 = 0 ;
V_33 -> V_35 . V_44 = 0 ;
V_33 -> V_35 . V_45 = 0 ;
V_33 -> V_40 . V_46 = F_18 ( V_47 ) ;
V_33 -> V_40 . V_48 = F_19 ( V_16 ) ;
V_33 -> V_40 . V_49 = 0 ;
V_33 -> V_40 . V_50 = F_21 ( V_10 . V_17 ) ;
V_33 -> V_40 . V_51 = F_21 ( V_20 ) ;
V_20 += V_10 . V_17 ;
V_33 -> V_52 . V_46 = F_18 ( V_47 ) ;
V_33 -> V_52 . V_48 = F_19 ( V_18 ) ;
V_33 -> V_52 . V_49 = 0 ;
V_33 -> V_52 . V_50 = F_21 ( V_10 . V_19 ) ;
V_33 -> V_52 . V_51 = F_21 ( V_20 ) ;
V_20 += V_10 . V_19 ;
V_33 -> V_53 . V_46 = F_18 ( V_47 ) ;
V_33 -> V_53 . V_48 = F_19 ( V_54 ) ;
V_33 -> V_53 . V_49 = F_21 ( V_22 ) ;
V_33 -> V_53 . V_50 = F_21 ( V_10 . V_23 ) ;
V_33 -> V_53 . V_51 = F_21 ( V_20 ) ;
V_20 += V_10 . V_23 ;
return V_20 ;
}
static inline unsigned long F_22 ( void )
{
int V_30 ;
unsigned long long V_55 , V_8 ;
if ( V_10 . V_56 )
F_23 ( L_16 ) ;
V_30 = F_24 ( V_57 , F_25 () ,
& V_8 , & V_55 ) ;
if ( V_30 == 0 && V_8 > 0 ) {
unsigned long V_58 ;
if ( V_10 . V_56 )
F_26 ( L_17 ) ;
V_10 . V_56 = ( unsigned long ) V_8 ;
V_58 = F_25 () / V_59 ;
if ( V_10 . V_56 > V_58 ) {
V_10 . V_56 = V_58 ;
F_26 ( L_18 ,
( V_10 . V_56 >> 20 ) ) ;
}
return V_10 . V_56 ;
} else if ( V_10 . V_56 ) {
return V_10 . V_56 ;
}
V_8 = F_25 () / 20 ;
V_8 = V_8 & ~ 0x0FFFFFFFUL ;
if ( V_60 && V_8 > V_60 )
V_8 = V_60 ;
return ( V_8 > V_61 ? V_8 : V_61 ) ;
}
static unsigned long F_27 ( void )
{
unsigned long V_8 = 0 ;
V_8 += V_10 . V_17 ;
V_8 += V_10 . V_19 ;
V_8 += V_10 . V_23 ;
V_8 += sizeof( struct V_62 ) ;
V_8 += sizeof( struct V_63 ) ;
V_8 += sizeof( struct V_64 ) ;
V_8 += sizeof( struct V_64 ) * ( F_28 ( V_65 ) + 2 ) ;
V_8 = F_29 ( V_8 ) ;
return V_8 ;
}
int T_1 F_30 ( void )
{
unsigned long V_55 , V_8 , V_66 ;
if ( ! V_10 . V_31 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_31 ( V_67 L_19
L_20 ) ;
V_10 . V_31 = 0 ;
return 0 ;
}
if ( V_13 )
V_10 . V_23 = F_32 ( V_13 -> V_53 . V_50 ) ;
else
V_10 . V_23 = F_22 () ;
if ( V_60 && V_60 < F_33 () ) {
V_8 = F_27 () ;
if ( ( V_60 + V_8 ) < F_33 () )
V_60 += V_8 ;
else
V_60 = F_33 () ;
F_31 ( V_67 L_21
L_22 , V_60 ) ;
}
if ( V_60 )
V_66 = V_60 ;
else
V_66 = F_33 () ;
if ( V_10 . V_14 ) {
F_31 ( V_67 L_23 ) ;
V_55 = V_10 . V_23 ;
V_8 = V_66 - V_55 ;
F_34 ( V_55 , V_8 ) ;
F_31 ( V_67 L_24
L_25 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_55 >> 20 ) ) ;
V_10 . V_68 =
F_32 ( V_13 -> V_53 . V_51 ) +
F_32 ( V_13 -> V_53 . V_50 ) ;
F_16 ( L_26 ,
( void * ) V_10 . V_68 ) ;
} else {
V_8 = F_27 () ;
for ( V_55 = V_10 . V_23 ;
V_55 <= ( V_66 - V_8 ) ;
V_55 += V_8 ) {
if ( F_35 ( V_55 , V_8 ) &&
! F_36 ( V_55 , V_8 ) )
break;
}
if ( ( V_55 > ( V_66 - V_8 ) ) ||
F_34 ( V_55 , V_8 ) ) {
F_37 ( L_27 ) ;
return 0 ;
}
F_26 ( L_28
L_29 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_55 >> 20 ) ,
( unsigned long ) ( F_25 () >> 20 ) ) ;
}
V_10 . V_69 = V_55 ;
V_10 . V_70 = V_8 ;
return 1 ;
}
unsigned long T_1 F_38 ( void )
{
return F_39 () / V_71 ;
}
static int T_1 F_40 ( char * V_72 )
{
if ( ! V_72 )
return 1 ;
if ( strncmp ( V_72 , L_30 , 2 ) == 0 )
V_10 . V_31 = 1 ;
else if ( strncmp ( V_72 , L_31 , 3 ) == 0 )
V_10 . V_31 = 0 ;
return 0 ;
}
static int T_1 F_41 ( char * V_72 )
{
if ( V_72 )
V_10 . V_56 = F_42 ( V_72 , & V_72 ) ;
return 0 ;
}
static int F_43 ( struct V_32 * V_33 )
{
int V_73 , V_74 ;
unsigned int V_75 ;
F_16 ( L_32 ) ;
do {
V_73 = F_44 ( V_10 . V_12 , 3 , 1 , NULL ,
V_76 , V_33 ,
sizeof( struct V_32 ) ) ;
V_75 = F_45 ( V_73 ) ;
if ( V_75 )
F_46 ( V_75 ) ;
} while ( V_75 );
V_74 = - V_77 ;
switch ( V_73 ) {
default:
F_37 ( L_33 , V_73 ) ;
break;
case - 1 :
F_31 ( V_78 L_34
L_35 , V_73 ) ;
break;
case - 3 :
if ( ! F_8 () )
F_37 ( L_36
L_37 ) ;
F_31 ( V_78 L_34
L_38 , V_73 ) ;
V_74 = - V_79 ;
break;
case - 9 :
F_31 ( V_78 L_39
L_40 ) ;
V_10 . V_21 = 1 ;
V_74 = - V_80 ;
break;
case 0 :
F_31 ( V_67 L_41
L_42 ) ;
V_10 . V_21 = 1 ;
V_74 = 0 ;
break;
}
return V_74 ;
}
void F_47 ( struct V_81 * V_82 , const char * V_83 )
{
struct V_62 * V_84 = NULL ;
int V_85 , V_86 ;
if ( ! V_10 . V_21 || ! V_10 . V_68 )
return;
V_86 = F_48 () ;
V_85 = F_49 ( & V_87 , - 1 , V_86 ) ;
if ( V_85 != - 1 ) {
while ( V_10 . V_21 )
F_50 () ;
return;
}
V_84 = F_51 ( V_10 . V_68 ) ;
V_84 -> V_87 = V_87 ;
F_52 () ;
if ( V_82 )
V_84 -> V_82 = * V_82 ;
else
F_53 ( & V_84 -> V_82 ) ;
V_84 -> V_88 = * V_89 ;
F_54 ( ( char * ) V_83 ) ;
}
static inline int F_55 ( T_3 V_90 )
{
int V_6 = - 1 ;
char V_83 [ 3 ] ;
if ( ( V_90 & V_91 ) == F_56 ( L_43 ) ) {
V_90 &= ~ V_91 ;
V_90 >>= 24 ;
V_83 [ 2 ] = '\0' ;
V_83 [ 1 ] = V_90 & 0xff ;
V_83 [ 0 ] = ( V_90 >> 8 ) & 0xff ;
sscanf ( V_83 , L_44 , & V_6 ) ;
if ( V_6 > 31 )
V_6 = - 1 ;
}
return V_6 ;
}
static inline void F_57 ( struct V_81 * V_82 , T_3 V_92 ,
T_3 V_93 )
{
int V_6 ;
V_6 = F_55 ( V_92 ) ;
if ( V_6 >= 0 )
V_82 -> V_94 [ V_6 ] = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_45 ) )
V_82 -> V_95 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_46 ) )
V_82 -> V_96 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_47 ) )
V_82 -> V_97 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_48 ) )
V_82 -> V_98 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_49 ) )
V_82 -> V_99 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_50 ) )
V_82 -> V_100 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_51 ) )
V_82 -> V_101 = ( unsigned long ) V_93 ;
else if ( V_92 == F_56 ( L_52 ) )
V_82 -> V_102 = ( unsigned long ) V_93 ;
}
static struct V_103 *
F_58 ( struct V_103 * V_104 , struct V_81 * V_82 )
{
memset ( V_82 , 0 , sizeof( struct V_81 ) ) ;
while ( F_32 ( V_104 -> V_92 ) != F_56 ( L_53 ) ) {
F_57 ( V_82 , F_32 ( V_104 -> V_92 ) ,
F_32 ( V_104 -> V_105 ) ) ;
V_104 ++ ;
}
V_104 ++ ;
return V_104 ;
}
static V_15 * F_59 ( V_15 * V_106 , struct V_81 * V_82 )
{
struct V_107 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_60 ( & V_108 . V_109 , V_82 ) ;
V_106 = F_61 ( V_106 , V_110 , V_111 ,
& V_108 , sizeof( V_108 ) ) ;
return V_106 ;
}
static void F_62 ( char * V_112 )
{
struct V_63 * V_113 ;
struct V_64 * V_114 ;
V_113 = (struct V_63 * ) V_112 ;
V_112 += sizeof( struct V_63 ) ;
V_114 = (struct V_64 * ) V_112 ;
if ( V_114 -> V_115 == V_116 ) {
V_114 -> V_117 = V_10 . V_118 ;
V_114 -> V_119 = V_114 -> V_117 ;
V_114 -> V_120 = V_10 . V_121 ;
V_114 -> V_122 = V_10 . V_121 ;
}
return;
}
static void * F_63 ( unsigned long V_8 )
{
void * V_123 ;
struct V_124 * V_124 ;
unsigned long V_125 , V_126 , V_6 ;
V_125 = F_64 ( V_8 ) ;
V_123 = ( void * ) F_65 ( V_127 | V_128 , V_125 ) ;
if ( ! V_123 )
return NULL ;
V_126 = 1 << V_125 ;
V_124 = F_66 ( V_123 ) ;
for ( V_6 = 0 ; V_6 < V_126 ; V_6 ++ )
F_67 ( V_124 + V_6 ) ;
return V_123 ;
}
static void F_68 ( unsigned long V_123 , unsigned long V_8 )
{
struct V_124 * V_124 ;
unsigned long V_125 , V_126 , V_6 ;
V_125 = F_64 ( V_8 ) ;
V_126 = 1 << V_125 ;
V_124 = F_66 ( V_123 ) ;
for ( V_6 = 0 ; V_6 < V_126 ; V_6 ++ )
F_69 ( V_124 + V_6 ) ;
F_70 ( V_124 , V_125 ) ;
}
static int T_1 F_71 ( const struct V_32 * V_33 )
{
struct V_129 * V_130 ;
struct V_103 * V_104 ;
struct V_62 * V_84 = NULL ;
void * V_123 ;
unsigned long V_20 ;
V_15 V_131 , * V_132 ;
struct V_81 V_82 ;
int V_6 , V_73 = 0 , V_133 = 0 ;
if ( ! V_33 -> V_40 . V_134 )
return - V_79 ;
V_20 = F_32 ( V_33 -> V_40 . V_51 ) ;
V_123 = F_51 ( V_20 ) ;
V_130 = V_123 ;
if ( F_32 ( V_130 -> V_135 ) != V_136 ) {
F_31 ( V_78 L_54 ) ;
return - V_137 ;
}
F_16 ( L_55 ) ;
F_16 ( L_56 , F_32 ( V_130 -> V_135 ) ) ;
F_16 ( L_57 , F_3 ( V_130 -> V_138 ) ) ;
V_123 += F_3 ( V_130 -> V_138 ) ;
V_131 = F_3 ( * ( ( T_2 * ) ( V_123 ) ) ) ;
F_16 ( L_58 , V_131 ) ;
V_123 += sizeof( V_15 ) ;
V_104 = (struct V_103 * ) V_123 ;
V_10 . V_121 = V_131 * sizeof( V_139 ) ;
V_10 . V_121 = F_29 ( V_10 . V_121 ) ;
V_132 = F_63 ( V_10 . V_121 ) ;
if ( ! V_132 ) {
F_31 ( V_78 L_59
L_60 , V_10 . V_121 ) ;
return - V_140 ;
}
V_10 . V_118 = F_72 ( V_132 ) ;
F_16 ( L_61 ,
( V_131 * sizeof( V_139 ) ) , V_132 ) ;
if ( V_10 . V_68 )
V_84 = F_51 ( V_10 . V_68 ) ;
for ( V_6 = 0 ; V_6 < V_131 ; V_6 ++ ) {
if ( F_32 ( V_104 -> V_92 ) != F_56 ( L_62 ) ) {
F_31 ( V_78 L_63 ) ;
V_73 = - V_137 ;
goto V_141;
}
V_133 = F_32 ( V_104 -> V_105 ) & V_142 ;
if ( V_84 && ! F_73 ( V_133 , & V_84 -> V_88 ) ) {
F_74 ( V_104 ) ;
continue;
}
F_16 ( L_64 , V_133 ) ;
if ( V_84 && V_84 -> V_87 == V_133 ) {
V_82 = V_84 -> V_82 ;
V_132 = F_59 ( V_132 , & V_82 ) ;
F_74 ( V_104 ) ;
} else {
V_104 ++ ;
V_104 = F_58 ( V_104 , & V_82 ) ;
V_132 = F_59 ( V_132 , & V_82 ) ;
}
}
F_75 ( V_132 ) ;
if ( V_84 ) {
F_16 ( L_65 ,
V_84 -> V_143 ) ;
F_62 ( ( char * ) F_51 ( V_84 -> V_143 ) ) ;
}
return 0 ;
V_141:
F_68 ( ( unsigned long ) F_51 ( V_10 . V_118 ) ,
V_10 . V_121 ) ;
V_10 . V_118 = 0 ;
V_10 . V_121 = 0 ;
return V_73 ;
}
static int T_1 F_76 ( const struct V_32 * V_13 )
{
struct V_62 * V_84 ;
int V_73 = 0 ;
if ( ! V_13 || ! V_10 . V_68 )
return - V_79 ;
if ( ( F_77 ( V_13 -> V_35 . V_38 ) == V_144 ) ||
( V_13 -> V_40 . V_145 != 0 ) ||
( V_13 -> V_53 . V_145 != 0 ) ) {
F_31 ( V_78 L_66 ) ;
return - V_79 ;
}
if ( ( V_13 -> V_53 . V_134 !=
V_13 -> V_53 . V_50 ) ||
! V_13 -> V_40 . V_134 ) {
F_31 ( V_78 L_67 ) ;
return - V_79 ;
}
V_84 = F_51 ( V_10 . V_68 ) ;
if ( V_84 -> V_135 != V_146 ) {
F_31 ( V_78 L_68 ) ;
return - V_79 ;
}
V_73 = F_71 ( V_13 ) ;
if ( V_73 )
return V_73 ;
V_143 = V_84 -> V_143 ;
return 0 ;
}
static inline void F_78 ( unsigned long long V_55 ,
unsigned long long V_147 )
{
if ( V_55 == V_147 )
return;
F_16 ( L_69 ,
V_148 , V_55 , V_147 - 1 , ( V_147 - V_55 ) ) ;
V_149 [ V_148 ] . V_55 = V_55 ;
V_149 [ V_148 ] . V_8 = V_147 - V_55 ;
V_148 ++ ;
}
static void F_79 ( unsigned long long V_150 ,
unsigned long long V_147 )
{
unsigned long long V_151 , V_152 ;
V_151 = V_10 . V_69 ;
V_152 = V_151 + V_10 . V_70 ;
if ( ( V_151 < V_147 ) && ( V_152 > V_150 ) ) {
if ( ( V_150 < V_151 ) && ( V_147 > V_152 ) ) {
F_78 ( V_150 , V_151 ) ;
F_78 ( V_152 , V_147 ) ;
} else if ( V_150 < V_151 ) {
F_78 ( V_150 , V_151 ) ;
} else if ( V_152 < V_147 ) {
F_78 ( V_152 , V_147 ) ;
}
} else
F_78 ( V_150 , V_147 ) ;
}
static int F_80 ( char * V_112 )
{
struct V_63 * V_113 ;
V_113 = (struct V_63 * ) V_112 ;
V_112 += sizeof( struct V_63 ) ;
memcpy ( V_113 -> V_153 , V_154 , V_155 ) ;
V_113 -> V_153 [ V_156 ] = V_157 ;
V_113 -> V_153 [ V_158 ] = V_159 ;
V_113 -> V_153 [ V_160 ] = V_161 ;
V_113 -> V_153 [ V_162 ] = V_163 ;
memset ( V_113 -> V_153 + V_164 , 0 , V_165 - V_164 ) ;
V_113 -> V_166 = V_167 ;
V_113 -> V_168 = V_169 ;
V_113 -> V_170 = V_161 ;
V_113 -> V_171 = 0 ;
V_113 -> V_172 = sizeof( struct V_63 ) ;
V_113 -> V_173 = 0 ;
#if F_81 ( V_174 )
V_113 -> V_175 = V_174 ;
#else
V_113 -> V_175 = 0 ;
#endif
V_113 -> V_176 = sizeof( struct V_63 ) ;
V_113 -> V_177 = sizeof( struct V_64 ) ;
V_113 -> V_178 = 0 ;
V_113 -> V_179 = 0 ;
V_113 -> V_180 = 0 ;
V_113 -> V_181 = 0 ;
return 0 ;
}
static void F_82 ( void )
{
struct V_24 * V_25 ;
unsigned long long V_150 , V_147 ;
F_16 ( L_70 ) ;
V_148 = 0 ;
F_78 ( V_22 , V_10 . V_23 ) ;
F_10 (memory, reg) {
V_150 = ( unsigned long long ) V_25 -> V_55 ;
V_147 = V_150 + ( unsigned long long ) V_25 -> V_8 ;
F_83 ( V_22 != 0 ) ;
if ( V_150 < V_10 . V_23 ) {
if ( V_147 > V_10 . V_23 )
V_150 = V_10 . V_23 ;
else
continue;
}
F_79 ( V_150 , V_147 ) ;
}
}
static inline unsigned long F_84 ( unsigned long V_182 )
{
if ( V_182 > V_22 && V_182 < V_10 . V_23 )
return F_32 ( V_33 . V_53 . V_51 ) + V_182 ;
else
return V_182 ;
}
static int F_85 ( char * V_112 )
{
struct V_63 * V_113 ;
struct V_64 * V_114 ;
int V_6 ;
F_80 ( V_112 ) ;
V_113 = (struct V_63 * ) V_112 ;
V_112 += sizeof( struct V_63 ) ;
V_114 = (struct V_64 * ) V_112 ;
V_112 += sizeof( struct V_64 ) ;
V_114 -> V_115 = V_116 ;
V_114 -> V_183 = 0 ;
V_114 -> V_184 = 0 ;
V_114 -> V_185 = 0 ;
V_114 -> V_119 = 0 ;
V_114 -> V_117 = 0 ;
V_114 -> V_120 = 0 ;
V_114 -> V_122 = 0 ;
( V_113 -> V_178 ) ++ ;
V_114 = (struct V_64 * ) V_112 ;
V_112 += sizeof( struct V_64 ) ;
V_114 -> V_115 = V_116 ;
V_114 -> V_183 = 0 ;
V_114 -> V_184 = 0 ;
V_114 -> V_185 = 0 ;
V_114 -> V_117 = F_84 ( F_86 () ) ;
V_114 -> V_119 = V_114 -> V_117 ;
V_114 -> V_122 = V_114 -> V_120 = V_186 ;
( V_113 -> V_178 ) ++ ;
for ( V_6 = 0 ; V_6 < V_148 ; V_6 ++ ) {
unsigned long long V_187 , V_188 ;
V_187 = V_149 [ V_6 ] . V_55 ;
V_188 = V_149 [ V_6 ] . V_8 ;
if ( ! V_188 )
continue;
V_114 = (struct V_64 * ) V_112 ;
V_112 += sizeof( struct V_64 ) ;
V_114 -> V_115 = V_189 ;
V_114 -> V_183 = V_190 | V_191 | V_192 ;
V_114 -> V_119 = V_187 ;
if ( V_187 == V_22 ) {
V_114 -> V_119 = F_32 ( V_33 . V_53 . V_51 ) ;
}
V_114 -> V_117 = V_187 ;
V_114 -> V_184 = ( unsigned long ) F_51 ( V_187 ) ;
V_114 -> V_120 = V_188 ;
V_114 -> V_122 = V_188 ;
V_114 -> V_185 = 0 ;
( V_113 -> V_178 ) ++ ;
}
return 0 ;
}
static unsigned long F_87 ( unsigned long V_20 )
{
struct V_62 * V_84 ;
if ( ! V_20 )
return 0 ;
V_10 . V_68 = V_20 ;
V_84 = F_51 ( V_20 ) ;
V_20 += sizeof( struct V_62 ) ;
memset ( V_84 , 0 , sizeof( struct V_62 ) ) ;
V_84 -> V_135 = V_146 ;
V_84 -> V_143 = V_20 ;
V_84 -> V_87 = V_193 ;
return V_20 ;
}
static int F_88 ( void )
{
unsigned long V_20 ;
void * V_123 ;
if ( ! V_10 . V_70 )
return - V_194 ;
F_82 () ;
V_20 = F_32 ( V_33 . V_53 . V_51 ) + F_32 ( V_33 . V_53 . V_50 ) ;
V_20 = F_87 ( V_20 ) ;
V_123 = F_51 ( V_20 ) ;
F_16 ( L_71 , V_20 ) ;
F_85 ( V_123 ) ;
return F_43 ( & V_33 ) ;
}
static int F_89 ( struct V_32 * V_33 )
{
int V_73 = 0 ;
unsigned int V_75 ;
F_16 ( L_72 ) ;
do {
V_73 = F_44 ( V_10 . V_12 , 3 , 1 , NULL ,
V_195 , V_33 ,
sizeof( struct V_32 ) ) ;
V_75 = F_45 ( V_73 ) ;
if ( V_75 )
F_46 ( V_75 ) ;
} while ( V_75 );
if ( V_73 ) {
F_31 ( V_78 L_73
L_74 , V_73 ) ;
return V_73 ;
}
V_10 . V_21 = 0 ;
return 0 ;
}
static int F_90 ( struct V_32 * V_33 )
{
int V_73 = 0 ;
unsigned int V_75 ;
F_16 ( L_75 ) ;
do {
V_73 = F_44 ( V_10 . V_12 , 3 , 1 , NULL ,
V_196 , V_33 ,
sizeof( struct V_32 ) ) ;
V_75 = F_45 ( V_73 ) ;
if ( V_75 )
F_46 ( V_75 ) ;
} while ( V_75 );
if ( V_73 ) {
F_37 ( L_76 , V_73 ) ;
return V_73 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_91 ( void )
{
if ( V_10 . V_14 ) {
F_17 ( & V_33 ,
F_32 ( V_13 -> V_40 . V_51 ) ) ;
F_90 ( & V_33 ) ;
}
}
static void F_92 ( unsigned long V_28 ,
unsigned long V_29 )
{
unsigned long V_197 ;
unsigned long V_198 = V_199 + V_200 ;
F_26 ( L_77 ,
F_93 ( V_28 ) , F_93 ( V_29 ) ) ;
for ( V_197 = V_28 ; V_197 < V_29 ; V_197 ++ ) {
F_94 ( F_95 ( V_197 ) ) ;
if ( F_96 ( V_199 , V_198 ) ) {
F_97 () ;
V_198 = V_199 + V_200 ;
}
}
}
static void F_98 ( unsigned long V_150 , unsigned long V_147 )
{
struct V_24 * V_25 ;
unsigned long V_26 , V_27 ;
unsigned long V_28 = F_9 ( V_150 ) ;
unsigned long V_29 = F_9 ( V_147 ) ;
F_10 (memory, reg) {
V_26 = F_11 ( V_28 , F_12 ( V_25 ) ) ;
V_27 = F_13 ( V_29 , F_14 ( V_25 ) ) ;
if ( V_26 < V_27 ) {
F_92 ( V_26 , V_27 ) ;
if ( V_27 == V_29 )
break;
V_28 = V_27 + 1 ;
}
}
}
static void F_99 ( unsigned long V_201 , unsigned long V_147 )
{
unsigned long V_151 , V_152 ;
V_151 = V_10 . V_69 ;
V_152 = V_151 + V_10 . V_70 ;
if ( V_201 < V_152 && V_147 > V_151 ) {
if ( V_201 < V_151 )
F_98 ( V_201 , V_151 ) ;
if ( V_147 > V_152 )
F_98 ( V_152 , V_147 ) ;
} else
F_98 ( V_201 , V_147 ) ;
}
static void F_100 ( void )
{
unsigned long V_202 , V_203 ;
unsigned long V_51 ;
F_101 ( & V_204 ) ;
if ( ! V_10 . V_14 ) {
F_102 ( & V_204 ) ;
return;
}
V_51 = F_32 ( V_13 -> V_40 . V_51 ) ;
F_91 () ;
F_102 ( & V_204 ) ;
V_202 = V_10 . V_69 ;
V_203 = V_202 +
V_10 . V_70 ;
V_10 . V_69 = V_51 ;
V_10 . V_70 = F_27 () ;
F_99 ( V_202 , V_203 ) ;
if ( V_10 . V_118 ) {
F_68 (
( unsigned long ) F_51 ( V_10 . V_118 ) ,
V_10 . V_121 ) ;
V_10 . V_118 = 0 ;
V_10 . V_121 = 0 ;
}
F_17 ( & V_33 , V_10 . V_69 ) ;
}
static T_5 F_103 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
const char * V_106 , T_6 V_126 )
{
if ( ! V_10 . V_14 )
return - V_209 ;
if ( V_106 [ 0 ] == '1' ) {
#ifdef F_104
F_105 () ;
#endif
F_100 () ;
} else
return - V_79 ;
return V_126 ;
}
static T_5 F_106 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
char * V_106 )
{
return sprintf ( V_106 , L_78 , V_10 . V_31 ) ;
}
static T_5 F_107 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
char * V_106 )
{
return sprintf ( V_106 , L_78 , V_10 . V_21 ) ;
}
static T_5 F_108 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
const char * V_106 , T_6 V_126 )
{
int V_30 = 0 ;
if ( ! V_10 . V_31 || V_13 )
return - V_209 ;
F_101 ( & V_204 ) ;
switch ( V_106 [ 0 ] ) {
case '0' :
if ( V_10 . V_21 == 0 ) {
goto V_210;
}
F_89 ( & V_33 ) ;
break;
case '1' :
if ( V_10 . V_21 == 1 ) {
V_30 = - V_80 ;
goto V_210;
}
V_30 = F_88 () ;
break;
default:
V_30 = - V_79 ;
break;
}
V_210:
F_102 ( & V_204 ) ;
return V_30 < 0 ? V_30 : V_126 ;
}
static int F_109 ( struct V_211 * V_212 , void * V_213 )
{
const struct V_32 * V_214 ;
if ( ! V_10 . V_31 )
return 0 ;
F_101 ( & V_204 ) ;
if ( V_13 )
V_214 = V_13 ;
else {
F_102 ( & V_204 ) ;
V_214 = & V_33 ;
}
F_110 ( V_212 ,
L_79
L_80 ,
F_32 ( V_214 -> V_40 . V_51 ) ,
F_32 ( V_214 -> V_40 . V_51 ) +
F_32 ( V_214 -> V_40 . V_50 ) - 1 ,
F_32 ( V_214 -> V_40 . V_50 ) ,
F_32 ( V_214 -> V_40 . V_134 ) ) ;
F_110 ( V_212 ,
L_81
L_80 ,
F_32 ( V_214 -> V_52 . V_51 ) ,
F_32 ( V_214 -> V_52 . V_51 ) +
F_32 ( V_214 -> V_52 . V_50 ) - 1 ,
F_32 ( V_214 -> V_52 . V_50 ) ,
F_32 ( V_214 -> V_52 . V_134 ) ) ;
F_110 ( V_212 ,
L_82
L_80 ,
F_32 ( V_214 -> V_53 . V_51 ) ,
F_32 ( V_214 -> V_53 . V_51 ) +
F_32 ( V_214 -> V_53 . V_50 ) - 1 ,
F_32 ( V_214 -> V_53 . V_50 ) ,
F_32 ( V_214 -> V_53 . V_134 ) ) ;
if ( ! V_13 ||
( V_10 . V_69 ==
F_32 ( V_214 -> V_40 . V_51 ) ) )
goto V_215;
F_110 ( V_212 ,
L_83
L_80 ,
( unsigned long long ) V_10 . V_69 ,
F_32 ( V_214 -> V_40 . V_51 ) - 1 ,
F_32 ( V_214 -> V_40 . V_51 ) -
V_10 . V_69 ,
F_32 ( V_214 -> V_40 . V_51 ) -
V_10 . V_69 ) ;
V_215:
if ( V_13 )
F_102 ( & V_204 ) ;
return 0 ;
}
static int F_111 ( struct V_216 * V_216 , struct V_217 * V_217 )
{
return F_112 ( V_217 , F_109 , V_216 -> V_218 ) ;
}
static void F_113 ( void )
{
struct V_219 * V_220 ;
int V_73 = 0 ;
V_73 = F_114 ( V_221 , & V_222 . V_208 ) ;
if ( V_73 )
F_31 ( V_78 L_84
L_85 , V_73 ) ;
V_73 = F_114 ( V_221 , & V_223 . V_208 ) ;
if ( V_73 )
F_31 ( V_78 L_84
L_86 , V_73 ) ;
V_220 = F_115 ( L_87 , 0444 ,
V_224 , NULL ,
& V_225 ) ;
if ( ! V_220 )
F_31 ( V_78 L_88
L_89 ) ;
if ( V_10 . V_14 ) {
V_73 = F_114 ( V_221 , & V_226 . V_208 ) ;
if ( V_73 )
F_31 ( V_78 L_84
L_90 , V_73 ) ;
}
return;
}
int T_1 F_116 ( void )
{
if ( ! V_10 . V_31 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_31 ( V_78 L_19
L_20 ) ;
return 0 ;
}
F_15 () ;
if ( V_10 . V_14 ) {
if ( F_76 ( V_13 ) < 0 )
F_100 () ;
}
else if ( V_10 . V_70 )
F_17 ( & V_33 , V_10 . V_69 ) ;
F_113 () ;
return 1 ;
}
