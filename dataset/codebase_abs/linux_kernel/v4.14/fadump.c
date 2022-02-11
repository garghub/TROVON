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
if ( ! V_10 . V_21 || ! V_10 . V_24 )
return 0 ;
return 1 ;
}
int F_8 ( void )
{
return V_10 . V_14 ;
}
static int F_9 ( void )
{
struct V_25 * V_26 ;
unsigned long V_27 , V_28 ;
unsigned long V_29 = F_10 ( V_22 ) ;
unsigned long V_30 = F_10 ( V_22 + V_10 . V_23 ) ;
unsigned int V_31 = 0 ;
F_11 (memory, reg) {
V_27 = F_12 ( V_29 , F_13 ( V_26 ) ) ;
V_28 = F_14 ( V_30 , F_15 ( V_26 ) ) ;
if ( V_27 < V_28 ) {
if ( V_27 > V_29 )
break;
if ( V_28 == V_30 ) {
V_31 = 1 ;
break;
}
V_29 = V_28 + 1 ;
}
}
return V_31 ;
}
static void F_16 ( void )
{
F_17 ( L_5 ,
( V_10 . V_11 ? L_6 : L_7 ) ) ;
if ( ! V_10 . V_11 )
return;
F_17 ( L_8 ,
( V_10 . V_32 ? L_9 : L_10 ) ) ;
F_17 ( L_11 ,
( V_10 . V_14 ? L_9 : L_10 ) ) ;
F_17 ( L_12 ) ;
F_17 ( L_13 , V_10 . V_17 ) ;
F_17 ( L_14 , V_10 . V_19 ) ;
F_17 ( L_15 , V_10 . V_23 ) ;
}
static unsigned long F_18 ( struct V_33 * V_34 ,
unsigned long V_20 )
{
if ( ! V_34 )
return 0 ;
memset ( V_34 , 0 , sizeof( struct V_33 ) ) ;
V_20 = V_20 & V_35 ;
V_34 -> V_36 . V_37 = F_19 ( 0x00000001 ) ;
V_34 -> V_36 . V_38 = F_20 ( 3 ) ;
V_34 -> V_36 . V_39 = 0 ;
V_34 -> V_36 . V_40 =
F_19 ( ( V_15 ) F_21 ( struct V_33 , V_41 ) ) ;
V_34 -> V_36 . V_42 = 0 ;
V_34 -> V_36 . V_43 = 0 ;
V_34 -> V_36 . V_44 = 0 ;
V_34 -> V_36 . V_45 = 0 ;
V_34 -> V_36 . V_46 = 0 ;
V_34 -> V_41 . V_47 = F_19 ( V_48 ) ;
V_34 -> V_41 . V_49 = F_20 ( V_16 ) ;
V_34 -> V_41 . V_50 = 0 ;
V_34 -> V_41 . V_51 = F_22 ( V_10 . V_17 ) ;
V_34 -> V_41 . V_52 = F_22 ( V_20 ) ;
V_20 += V_10 . V_17 ;
V_34 -> V_53 . V_47 = F_19 ( V_48 ) ;
V_34 -> V_53 . V_49 = F_20 ( V_18 ) ;
V_34 -> V_53 . V_50 = 0 ;
V_34 -> V_53 . V_51 = F_22 ( V_10 . V_19 ) ;
V_34 -> V_53 . V_52 = F_22 ( V_20 ) ;
V_20 += V_10 . V_19 ;
V_34 -> V_54 . V_47 = F_19 ( V_48 ) ;
V_34 -> V_54 . V_49 = F_20 ( V_55 ) ;
V_34 -> V_54 . V_50 = F_22 ( V_22 ) ;
V_34 -> V_54 . V_51 = F_22 ( V_10 . V_23 ) ;
V_34 -> V_54 . V_52 = F_22 ( V_20 ) ;
V_20 += V_10 . V_23 ;
return V_20 ;
}
static inline unsigned long F_23 ( void )
{
int V_31 ;
unsigned long long V_56 , V_8 ;
if ( V_10 . V_57 )
F_24 ( L_16 ) ;
V_31 = F_25 ( V_58 , F_26 () ,
& V_8 , & V_56 ) ;
if ( V_31 == 0 && V_8 > 0 ) {
unsigned long V_59 ;
if ( V_10 . V_57 )
F_27 ( L_17 ) ;
V_10 . V_57 = ( unsigned long ) V_8 ;
V_59 = F_26 () / V_60 ;
if ( V_10 . V_57 > V_59 ) {
V_10 . V_57 = V_59 ;
F_27 ( L_18 ,
( V_10 . V_57 >> 20 ) ) ;
}
return V_10 . V_57 ;
} else if ( V_10 . V_57 ) {
return V_10 . V_57 ;
}
V_8 = F_26 () / 20 ;
V_8 = V_8 & ~ 0x0FFFFFFFUL ;
if ( V_61 && V_8 > V_61 )
V_8 = V_61 ;
return ( V_8 > V_62 ? V_8 : V_62 ) ;
}
static unsigned long F_28 ( void )
{
unsigned long V_8 = 0 ;
V_8 += V_10 . V_17 ;
V_8 += V_10 . V_19 ;
V_8 += V_10 . V_23 ;
V_8 += sizeof( struct V_63 ) ;
V_8 += sizeof( struct V_64 ) ;
V_8 += sizeof( struct V_65 ) ;
V_8 += sizeof( struct V_65 ) * ( F_29 ( V_66 ) + 2 ) ;
V_8 = F_30 ( V_8 ) ;
return V_8 ;
}
int T_1 F_31 ( void )
{
unsigned long V_56 , V_8 , V_67 ;
if ( ! V_10 . V_32 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_32 ( V_68 L_19
L_20 ) ;
V_10 . V_32 = 0 ;
return 0 ;
}
if ( V_13 )
V_10 . V_23 = F_33 ( V_13 -> V_54 . V_51 ) ;
else
V_10 . V_23 = F_23 () ;
if ( V_61 && V_61 < F_34 () ) {
V_8 = F_28 () ;
if ( ( V_61 + V_8 ) < F_34 () )
V_61 += V_8 ;
else
V_61 = F_34 () ;
F_32 ( V_68 L_21
L_22 , V_61 ) ;
}
if ( V_61 )
V_67 = V_61 ;
else
V_67 = F_34 () ;
if ( V_10 . V_14 ) {
F_32 ( V_68 L_23 ) ;
V_56 = V_10 . V_23 ;
V_8 = V_67 - V_56 ;
F_35 ( V_56 , V_8 ) ;
F_32 ( V_68 L_24
L_25 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_56 >> 20 ) ) ;
V_10 . V_24 =
F_33 ( V_13 -> V_54 . V_52 ) +
F_33 ( V_13 -> V_54 . V_51 ) ;
F_17 ( L_26 ,
( void * ) V_10 . V_24 ) ;
} else {
V_8 = F_28 () ;
for ( V_56 = V_10 . V_23 ;
V_56 <= ( V_67 - V_8 ) ;
V_56 += V_8 ) {
if ( F_36 ( V_56 , V_8 ) &&
! F_37 ( V_56 , V_8 ) )
break;
}
if ( ( V_56 > ( V_67 - V_8 ) ) ||
F_35 ( V_56 , V_8 ) ) {
F_38 ( L_27 ) ;
return 0 ;
}
F_27 ( L_28
L_29 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_56 >> 20 ) ,
( unsigned long ) ( F_26 () >> 20 ) ) ;
}
V_10 . V_69 = V_56 ;
V_10 . V_70 = V_8 ;
return 1 ;
}
unsigned long T_1 F_39 ( void )
{
return F_40 () / V_71 ;
}
static int T_1 F_41 ( char * V_72 )
{
if ( ! V_72 )
return 1 ;
if ( strncmp ( V_72 , L_30 , 2 ) == 0 )
V_10 . V_32 = 1 ;
else if ( strncmp ( V_72 , L_31 , 3 ) == 0 )
V_10 . V_32 = 0 ;
return 0 ;
}
static int T_1 F_42 ( char * V_72 )
{
if ( V_72 )
V_10 . V_57 = F_43 ( V_72 , & V_72 ) ;
return 0 ;
}
static int F_44 ( struct V_33 * V_34 )
{
int V_73 , V_74 ;
unsigned int V_75 ;
F_17 ( L_32 ) ;
do {
V_73 = F_45 ( V_10 . V_12 , 3 , 1 , NULL ,
V_76 , V_34 ,
sizeof( struct V_33 ) ) ;
V_75 = F_46 ( V_73 ) ;
if ( V_75 )
F_47 ( V_75 ) ;
} while ( V_75 );
V_74 = - V_77 ;
switch ( V_73 ) {
default:
F_38 ( L_33 , V_73 ) ;
break;
case - 1 :
F_32 ( V_78 L_34
L_35 , V_73 ) ;
break;
case - 3 :
if ( ! F_9 () )
F_38 ( L_36
L_37 ) ;
F_32 ( V_78 L_34
L_38 , V_73 ) ;
V_74 = - V_79 ;
break;
case - 9 :
F_32 ( V_78 L_39
L_40 ) ;
V_10 . V_21 = 1 ;
V_74 = - V_80 ;
break;
case 0 :
F_32 ( V_68 L_41
L_42 ) ;
V_10 . V_21 = 1 ;
V_74 = 0 ;
break;
}
return V_74 ;
}
void F_48 ( struct V_81 * V_82 , const char * V_83 )
{
struct V_63 * V_84 = NULL ;
int V_85 , V_86 ;
if ( ! F_7 () )
return;
V_86 = F_49 () ;
V_85 = F_50 ( & V_87 , - 1 , V_86 ) ;
if ( V_85 != - 1 ) {
while ( V_10 . V_21 )
F_51 () ;
return;
}
V_84 = F_52 ( V_10 . V_24 ) ;
V_84 -> V_87 = V_87 ;
F_53 () ;
if ( V_82 )
V_84 -> V_82 = * V_82 ;
else
F_54 ( & V_84 -> V_82 ) ;
V_84 -> V_88 = * V_89 ;
F_55 ( ( char * ) V_83 ) ;
}
static inline int F_56 ( T_3 V_90 )
{
int V_6 = - 1 ;
char V_83 [ 3 ] ;
if ( ( V_90 & V_91 ) == F_57 ( L_43 ) ) {
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
static inline void F_58 ( struct V_81 * V_82 , T_3 V_92 ,
T_3 V_93 )
{
int V_6 ;
V_6 = F_56 ( V_92 ) ;
if ( V_6 >= 0 )
V_82 -> V_94 [ V_6 ] = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_45 ) )
V_82 -> V_95 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_46 ) )
V_82 -> V_96 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_47 ) )
V_82 -> V_97 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_48 ) )
V_82 -> V_98 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_49 ) )
V_82 -> V_99 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_50 ) )
V_82 -> V_100 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_51 ) )
V_82 -> V_101 = ( unsigned long ) V_93 ;
else if ( V_92 == F_57 ( L_52 ) )
V_82 -> V_102 = ( unsigned long ) V_93 ;
}
static struct V_103 *
F_59 ( struct V_103 * V_104 , struct V_81 * V_82 )
{
memset ( V_82 , 0 , sizeof( struct V_81 ) ) ;
while ( F_33 ( V_104 -> V_92 ) != F_57 ( L_53 ) ) {
F_58 ( V_82 , F_33 ( V_104 -> V_92 ) ,
F_33 ( V_104 -> V_105 ) ) ;
V_104 ++ ;
}
V_104 ++ ;
return V_104 ;
}
static V_15 * F_60 ( V_15 * V_106 , struct V_81 * V_82 )
{
struct V_107 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_61 ( & V_108 . V_109 , V_82 ) ;
V_106 = F_62 ( V_106 , V_110 , V_111 ,
& V_108 , sizeof( V_108 ) ) ;
return V_106 ;
}
static void F_63 ( char * V_112 )
{
struct V_64 * V_113 ;
struct V_65 * V_114 ;
V_113 = (struct V_64 * ) V_112 ;
V_112 += sizeof( struct V_64 ) ;
V_114 = (struct V_65 * ) V_112 ;
if ( V_114 -> V_115 == V_116 ) {
V_114 -> V_117 = V_10 . V_118 ;
V_114 -> V_119 = V_114 -> V_117 ;
V_114 -> V_120 = V_10 . V_121 ;
V_114 -> V_122 = V_10 . V_121 ;
}
return;
}
static void * F_64 ( unsigned long V_8 )
{
void * V_123 ;
struct V_124 * V_124 ;
unsigned long V_125 , V_126 , V_6 ;
V_125 = F_65 ( V_8 ) ;
V_123 = ( void * ) F_66 ( V_127 | V_128 , V_125 ) ;
if ( ! V_123 )
return NULL ;
V_126 = 1 << V_125 ;
V_124 = F_67 ( V_123 ) ;
for ( V_6 = 0 ; V_6 < V_126 ; V_6 ++ )
F_68 ( V_124 + V_6 ) ;
return V_123 ;
}
static void F_69 ( unsigned long V_123 , unsigned long V_8 )
{
struct V_124 * V_124 ;
unsigned long V_125 , V_126 , V_6 ;
V_125 = F_65 ( V_8 ) ;
V_126 = 1 << V_125 ;
V_124 = F_67 ( V_123 ) ;
for ( V_6 = 0 ; V_6 < V_126 ; V_6 ++ )
F_70 ( V_124 + V_6 ) ;
F_71 ( V_124 , V_125 ) ;
}
static int T_1 F_72 ( const struct V_33 * V_34 )
{
struct V_129 * V_130 ;
struct V_103 * V_104 ;
struct V_63 * V_84 = NULL ;
void * V_123 ;
unsigned long V_20 ;
V_15 V_131 , * V_132 ;
struct V_81 V_82 ;
int V_6 , V_73 = 0 , V_133 = 0 ;
if ( ! V_34 -> V_41 . V_134 )
return - V_79 ;
V_20 = F_33 ( V_34 -> V_41 . V_52 ) ;
V_123 = F_52 ( V_20 ) ;
V_130 = V_123 ;
if ( F_33 ( V_130 -> V_135 ) != V_136 ) {
F_32 ( V_78 L_54 ) ;
return - V_137 ;
}
F_17 ( L_55 ) ;
F_17 ( L_56 , F_33 ( V_130 -> V_135 ) ) ;
F_17 ( L_57 , F_3 ( V_130 -> V_138 ) ) ;
V_123 += F_3 ( V_130 -> V_138 ) ;
V_131 = F_3 ( * ( ( T_2 * ) ( V_123 ) ) ) ;
F_17 ( L_58 , V_131 ) ;
V_123 += sizeof( V_15 ) ;
V_104 = (struct V_103 * ) V_123 ;
V_10 . V_121 = V_131 * sizeof( V_139 ) ;
V_10 . V_121 = F_30 ( V_10 . V_121 ) ;
V_132 = F_64 ( V_10 . V_121 ) ;
if ( ! V_132 ) {
F_32 ( V_78 L_59
L_60 , V_10 . V_121 ) ;
return - V_140 ;
}
V_10 . V_118 = F_73 ( V_132 ) ;
F_17 ( L_61 ,
( V_131 * sizeof( V_139 ) ) , V_132 ) ;
if ( V_10 . V_24 )
V_84 = F_52 ( V_10 . V_24 ) ;
for ( V_6 = 0 ; V_6 < V_131 ; V_6 ++ ) {
if ( F_33 ( V_104 -> V_92 ) != F_57 ( L_62 ) ) {
F_32 ( V_78 L_63 ) ;
V_73 = - V_137 ;
goto V_141;
}
V_133 = F_33 ( V_104 -> V_105 ) & V_142 ;
if ( V_84 && ! F_74 ( V_133 , & V_84 -> V_88 ) ) {
F_75 ( V_104 ) ;
continue;
}
F_17 ( L_64 , V_133 ) ;
if ( V_84 && V_84 -> V_87 == V_133 ) {
V_82 = V_84 -> V_82 ;
V_132 = F_60 ( V_132 , & V_82 ) ;
F_75 ( V_104 ) ;
} else {
V_104 ++ ;
V_104 = F_59 ( V_104 , & V_82 ) ;
V_132 = F_60 ( V_132 , & V_82 ) ;
}
}
F_76 ( V_132 ) ;
if ( V_84 ) {
F_17 ( L_65 ,
V_84 -> V_143 ) ;
F_63 ( ( char * ) F_52 ( V_84 -> V_143 ) ) ;
}
return 0 ;
V_141:
F_69 ( ( unsigned long ) F_52 ( V_10 . V_118 ) ,
V_10 . V_121 ) ;
V_10 . V_118 = 0 ;
V_10 . V_121 = 0 ;
return V_73 ;
}
static int T_1 F_77 ( const struct V_33 * V_13 )
{
struct V_63 * V_84 ;
int V_73 = 0 ;
if ( ! V_13 || ! V_10 . V_24 )
return - V_79 ;
if ( ( F_78 ( V_13 -> V_36 . V_39 ) == V_144 ) ||
( V_13 -> V_41 . V_145 != 0 ) ||
( V_13 -> V_54 . V_145 != 0 ) ) {
F_32 ( V_78 L_66 ) ;
return - V_79 ;
}
if ( ( V_13 -> V_54 . V_134 !=
V_13 -> V_54 . V_51 ) ||
! V_13 -> V_41 . V_134 ) {
F_32 ( V_78 L_67 ) ;
return - V_79 ;
}
V_84 = F_52 ( V_10 . V_24 ) ;
if ( V_84 -> V_135 != V_146 ) {
F_32 ( V_78 L_68 ) ;
return - V_79 ;
}
V_73 = F_72 ( V_13 ) ;
if ( V_73 )
return V_73 ;
V_143 = V_84 -> V_143 ;
return 0 ;
}
static inline void F_79 ( unsigned long long V_56 ,
unsigned long long V_147 )
{
if ( V_56 == V_147 )
return;
F_17 ( L_69 ,
V_148 , V_56 , V_147 - 1 , ( V_147 - V_56 ) ) ;
V_149 [ V_148 ] . V_56 = V_56 ;
V_149 [ V_148 ] . V_8 = V_147 - V_56 ;
V_148 ++ ;
}
static void F_80 ( unsigned long long V_150 ,
unsigned long long V_147 )
{
unsigned long long V_151 , V_152 ;
V_151 = V_10 . V_69 ;
V_152 = V_151 + V_10 . V_70 ;
if ( ( V_151 < V_147 ) && ( V_152 > V_150 ) ) {
if ( ( V_150 < V_151 ) && ( V_147 > V_152 ) ) {
F_79 ( V_150 , V_151 ) ;
F_79 ( V_152 , V_147 ) ;
} else if ( V_150 < V_151 ) {
F_79 ( V_150 , V_151 ) ;
} else if ( V_152 < V_147 ) {
F_79 ( V_152 , V_147 ) ;
}
} else
F_79 ( V_150 , V_147 ) ;
}
static int F_81 ( char * V_112 )
{
struct V_64 * V_113 ;
V_113 = (struct V_64 * ) V_112 ;
V_112 += sizeof( struct V_64 ) ;
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
V_113 -> V_172 = sizeof( struct V_64 ) ;
V_113 -> V_173 = 0 ;
#if F_82 ( V_174 )
V_113 -> V_175 = V_174 ;
#else
V_113 -> V_175 = 0 ;
#endif
V_113 -> V_176 = sizeof( struct V_64 ) ;
V_113 -> V_177 = sizeof( struct V_65 ) ;
V_113 -> V_178 = 0 ;
V_113 -> V_179 = 0 ;
V_113 -> V_180 = 0 ;
V_113 -> V_181 = 0 ;
return 0 ;
}
static void F_83 ( void )
{
struct V_25 * V_26 ;
unsigned long long V_150 , V_147 ;
F_17 ( L_70 ) ;
V_148 = 0 ;
F_79 ( V_22 , V_10 . V_23 ) ;
F_11 (memory, reg) {
V_150 = ( unsigned long long ) V_26 -> V_56 ;
V_147 = V_150 + ( unsigned long long ) V_26 -> V_8 ;
F_84 ( V_22 != 0 ) ;
if ( V_150 < V_10 . V_23 ) {
if ( V_147 > V_10 . V_23 )
V_150 = V_10 . V_23 ;
else
continue;
}
F_80 ( V_150 , V_147 ) ;
}
}
static inline unsigned long F_85 ( unsigned long V_182 )
{
if ( V_182 > V_22 && V_182 < V_10 . V_23 )
return F_33 ( V_34 . V_54 . V_52 ) + V_182 ;
else
return V_182 ;
}
static int F_86 ( char * V_112 )
{
struct V_64 * V_113 ;
struct V_65 * V_114 ;
int V_6 ;
F_81 ( V_112 ) ;
V_113 = (struct V_64 * ) V_112 ;
V_112 += sizeof( struct V_64 ) ;
V_114 = (struct V_65 * ) V_112 ;
V_112 += sizeof( struct V_65 ) ;
V_114 -> V_115 = V_116 ;
V_114 -> V_183 = 0 ;
V_114 -> V_184 = 0 ;
V_114 -> V_185 = 0 ;
V_114 -> V_119 = 0 ;
V_114 -> V_117 = 0 ;
V_114 -> V_120 = 0 ;
V_114 -> V_122 = 0 ;
( V_113 -> V_178 ) ++ ;
V_114 = (struct V_65 * ) V_112 ;
V_112 += sizeof( struct V_65 ) ;
V_114 -> V_115 = V_116 ;
V_114 -> V_183 = 0 ;
V_114 -> V_184 = 0 ;
V_114 -> V_185 = 0 ;
V_114 -> V_117 = F_85 ( F_87 () ) ;
V_114 -> V_119 = V_114 -> V_117 ;
V_114 -> V_122 = V_114 -> V_120 = V_186 ;
( V_113 -> V_178 ) ++ ;
for ( V_6 = 0 ; V_6 < V_148 ; V_6 ++ ) {
unsigned long long V_187 , V_188 ;
V_187 = V_149 [ V_6 ] . V_56 ;
V_188 = V_149 [ V_6 ] . V_8 ;
if ( ! V_188 )
continue;
V_114 = (struct V_65 * ) V_112 ;
V_112 += sizeof( struct V_65 ) ;
V_114 -> V_115 = V_189 ;
V_114 -> V_183 = V_190 | V_191 | V_192 ;
V_114 -> V_119 = V_187 ;
if ( V_187 == V_22 ) {
V_114 -> V_119 = F_33 ( V_34 . V_54 . V_52 ) ;
}
V_114 -> V_117 = V_187 ;
V_114 -> V_184 = ( unsigned long ) F_52 ( V_187 ) ;
V_114 -> V_120 = V_188 ;
V_114 -> V_122 = V_188 ;
V_114 -> V_185 = 0 ;
( V_113 -> V_178 ) ++ ;
}
return 0 ;
}
static unsigned long F_88 ( unsigned long V_20 )
{
struct V_63 * V_84 ;
if ( ! V_20 )
return 0 ;
V_10 . V_24 = V_20 ;
V_84 = F_52 ( V_20 ) ;
V_20 += sizeof( struct V_63 ) ;
memset ( V_84 , 0 , sizeof( struct V_63 ) ) ;
V_84 -> V_135 = V_146 ;
V_84 -> V_143 = V_20 ;
V_84 -> V_87 = V_193 ;
return V_20 ;
}
static int F_89 ( void )
{
unsigned long V_20 ;
void * V_123 ;
if ( ! V_10 . V_70 )
return - V_194 ;
F_83 () ;
V_20 = F_33 ( V_34 . V_54 . V_52 ) + F_33 ( V_34 . V_54 . V_51 ) ;
V_20 = F_88 ( V_20 ) ;
V_123 = F_52 ( V_20 ) ;
F_17 ( L_71 , V_20 ) ;
F_86 ( V_123 ) ;
return F_44 ( & V_34 ) ;
}
static int F_90 ( struct V_33 * V_34 )
{
int V_73 = 0 ;
unsigned int V_75 ;
F_17 ( L_72 ) ;
do {
V_73 = F_45 ( V_10 . V_12 , 3 , 1 , NULL ,
V_195 , V_34 ,
sizeof( struct V_33 ) ) ;
V_75 = F_46 ( V_73 ) ;
if ( V_75 )
F_47 ( V_75 ) ;
} while ( V_75 );
if ( V_73 ) {
F_32 ( V_78 L_73
L_74 , V_73 ) ;
return V_73 ;
}
V_10 . V_21 = 0 ;
return 0 ;
}
static int F_91 ( struct V_33 * V_34 )
{
int V_73 = 0 ;
unsigned int V_75 ;
F_17 ( L_75 ) ;
do {
V_73 = F_45 ( V_10 . V_12 , 3 , 1 , NULL ,
V_196 , V_34 ,
sizeof( struct V_33 ) ) ;
V_75 = F_46 ( V_73 ) ;
if ( V_75 )
F_47 ( V_75 ) ;
} while ( V_75 );
if ( V_73 ) {
F_38 ( L_76 , V_73 ) ;
return V_73 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_92 ( void )
{
if ( V_10 . V_14 ) {
F_18 ( & V_34 ,
F_33 ( V_13 -> V_41 . V_52 ) ) ;
F_91 ( & V_34 ) ;
}
}
static void F_93 ( unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_197 ;
unsigned long V_198 = V_199 + V_200 ;
F_27 ( L_77 ,
F_94 ( V_29 ) , F_94 ( V_30 ) ) ;
for ( V_197 = V_29 ; V_197 < V_30 ; V_197 ++ ) {
F_95 ( F_96 ( V_197 ) ) ;
if ( F_97 ( V_199 , V_198 ) ) {
F_98 () ;
V_198 = V_199 + V_200 ;
}
}
}
static void F_99 ( unsigned long V_150 , unsigned long V_147 )
{
struct V_25 * V_26 ;
unsigned long V_27 , V_28 ;
unsigned long V_29 = F_10 ( V_150 ) ;
unsigned long V_30 = F_10 ( V_147 ) ;
F_11 (memory, reg) {
V_27 = F_12 ( V_29 , F_13 ( V_26 ) ) ;
V_28 = F_14 ( V_30 , F_15 ( V_26 ) ) ;
if ( V_27 < V_28 ) {
F_93 ( V_27 , V_28 ) ;
if ( V_28 == V_30 )
break;
V_29 = V_28 + 1 ;
}
}
}
static void F_100 ( unsigned long V_201 , unsigned long V_147 )
{
unsigned long V_151 , V_152 ;
V_151 = V_10 . V_69 ;
V_152 = V_151 + V_10 . V_70 ;
if ( V_201 < V_152 && V_147 > V_151 ) {
if ( V_201 < V_151 )
F_99 ( V_201 , V_151 ) ;
if ( V_147 > V_152 )
F_99 ( V_152 , V_147 ) ;
} else
F_99 ( V_201 , V_147 ) ;
}
static void F_101 ( void )
{
unsigned long V_202 , V_203 ;
unsigned long V_52 ;
F_102 ( & V_204 ) ;
if ( ! V_10 . V_14 ) {
F_103 ( & V_204 ) ;
return;
}
V_52 = F_33 ( V_13 -> V_41 . V_52 ) ;
F_92 () ;
F_103 ( & V_204 ) ;
V_202 = V_10 . V_69 ;
V_203 = V_202 +
V_10 . V_70 ;
V_10 . V_69 = V_52 ;
V_10 . V_70 = F_28 () ;
F_100 ( V_202 , V_203 ) ;
if ( V_10 . V_118 ) {
F_69 (
( unsigned long ) F_52 ( V_10 . V_118 ) ,
V_10 . V_121 ) ;
V_10 . V_118 = 0 ;
V_10 . V_121 = 0 ;
}
F_18 ( & V_34 , V_10 . V_69 ) ;
}
static T_5 F_104 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
const char * V_106 , T_6 V_126 )
{
if ( ! V_10 . V_14 )
return - V_209 ;
if ( V_106 [ 0 ] == '1' ) {
#ifdef F_105
F_106 () ;
#endif
F_101 () ;
} else
return - V_79 ;
return V_126 ;
}
static T_5 F_107 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
char * V_106 )
{
return sprintf ( V_106 , L_78 , V_10 . V_32 ) ;
}
static T_5 F_108 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
char * V_106 )
{
return sprintf ( V_106 , L_78 , V_10 . V_21 ) ;
}
static T_5 F_109 ( struct V_205 * V_206 ,
struct V_207 * V_208 ,
const char * V_106 , T_6 V_126 )
{
int V_31 = 0 ;
if ( ! V_10 . V_32 || V_13 )
return - V_209 ;
F_102 ( & V_204 ) ;
switch ( V_106 [ 0 ] ) {
case '0' :
if ( V_10 . V_21 == 0 ) {
goto V_210;
}
F_90 ( & V_34 ) ;
break;
case '1' :
if ( V_10 . V_21 == 1 ) {
V_31 = - V_80 ;
goto V_210;
}
V_31 = F_89 () ;
break;
default:
V_31 = - V_79 ;
break;
}
V_210:
F_103 ( & V_204 ) ;
return V_31 < 0 ? V_31 : V_126 ;
}
static int F_110 ( struct V_211 * V_212 , void * V_213 )
{
const struct V_33 * V_214 ;
if ( ! V_10 . V_32 )
return 0 ;
F_102 ( & V_204 ) ;
if ( V_13 )
V_214 = V_13 ;
else {
F_103 ( & V_204 ) ;
V_214 = & V_34 ;
}
F_111 ( V_212 ,
L_79
L_80 ,
F_33 ( V_214 -> V_41 . V_52 ) ,
F_33 ( V_214 -> V_41 . V_52 ) +
F_33 ( V_214 -> V_41 . V_51 ) - 1 ,
F_33 ( V_214 -> V_41 . V_51 ) ,
F_33 ( V_214 -> V_41 . V_134 ) ) ;
F_111 ( V_212 ,
L_81
L_80 ,
F_33 ( V_214 -> V_53 . V_52 ) ,
F_33 ( V_214 -> V_53 . V_52 ) +
F_33 ( V_214 -> V_53 . V_51 ) - 1 ,
F_33 ( V_214 -> V_53 . V_51 ) ,
F_33 ( V_214 -> V_53 . V_134 ) ) ;
F_111 ( V_212 ,
L_82
L_80 ,
F_33 ( V_214 -> V_54 . V_52 ) ,
F_33 ( V_214 -> V_54 . V_52 ) +
F_33 ( V_214 -> V_54 . V_51 ) - 1 ,
F_33 ( V_214 -> V_54 . V_51 ) ,
F_33 ( V_214 -> V_54 . V_134 ) ) ;
if ( ! V_13 ||
( V_10 . V_69 ==
F_33 ( V_214 -> V_41 . V_52 ) ) )
goto V_215;
F_111 ( V_212 ,
L_83
L_80 ,
( unsigned long long ) V_10 . V_69 ,
F_33 ( V_214 -> V_41 . V_52 ) - 1 ,
F_33 ( V_214 -> V_41 . V_52 ) -
V_10 . V_69 ,
F_33 ( V_214 -> V_41 . V_52 ) -
V_10 . V_69 ) ;
V_215:
if ( V_13 )
F_103 ( & V_204 ) ;
return 0 ;
}
static int F_112 ( struct V_216 * V_216 , struct V_217 * V_217 )
{
return F_113 ( V_217 , F_110 , V_216 -> V_218 ) ;
}
static void F_114 ( void )
{
struct V_219 * V_220 ;
int V_73 = 0 ;
V_73 = F_115 ( V_221 , & V_222 . V_208 ) ;
if ( V_73 )
F_32 ( V_78 L_84
L_85 , V_73 ) ;
V_73 = F_115 ( V_221 , & V_223 . V_208 ) ;
if ( V_73 )
F_32 ( V_78 L_84
L_86 , V_73 ) ;
V_220 = F_116 ( L_87 , 0444 ,
V_224 , NULL ,
& V_225 ) ;
if ( ! V_220 )
F_32 ( V_78 L_88
L_89 ) ;
if ( V_10 . V_14 ) {
V_73 = F_115 ( V_221 , & V_226 . V_208 ) ;
if ( V_73 )
F_32 ( V_78 L_84
L_90 , V_73 ) ;
}
return;
}
static int F_117 ( struct V_227 * V_228 ,
unsigned long V_229 , void * V_230 )
{
F_48 ( NULL , V_230 ) ;
return V_231 ;
}
int T_1 F_118 ( void )
{
if ( ! V_10 . V_32 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_32 ( V_78 L_19
L_20 ) ;
return 0 ;
}
F_16 () ;
if ( V_10 . V_14 ) {
if ( F_77 ( V_13 ) < 0 )
F_101 () ;
}
else if ( V_10 . V_70 )
F_18 ( & V_34 , V_10 . V_69 ) ;
F_114 () ;
F_119 ( & V_232 ,
& V_233 ) ;
return 1 ;
}
