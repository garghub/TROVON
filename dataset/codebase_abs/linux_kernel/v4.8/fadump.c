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
static int T_1 F_23 ( char * V_60 )
{
if ( ! V_60 )
return 1 ;
if ( strncmp ( V_60 , L_25 , 2 ) == 0 )
V_10 . V_20 = 1 ;
else if ( strncmp ( V_60 , L_26 , 3 ) == 0 )
V_10 . V_20 = 0 ;
return 0 ;
}
static int T_1 F_24 ( char * V_60 )
{
if ( V_60 )
V_10 . V_47 = F_25 ( V_60 , & V_60 ) ;
return 0 ;
}
static void F_26 ( struct V_22 * V_23 )
{
int V_61 ;
unsigned int V_62 ;
F_8 ( L_27 ) ;
do {
V_61 = F_27 ( V_10 . V_12 , 3 , 1 , NULL ,
V_63 , V_23 ,
sizeof( struct V_22 ) ) ;
V_62 = F_28 ( V_61 ) ;
if ( V_62 )
F_29 ( V_62 ) ;
} while ( V_62 );
switch ( V_61 ) {
case - 1 :
F_20 ( V_64 L_28
L_29 , V_61 ) ;
break;
case - 3 :
F_20 ( V_64 L_28
L_30 , V_61 ) ;
break;
case - 9 :
F_20 ( V_64 L_31
L_32 ) ;
V_10 . V_65 = 1 ;
break;
case 0 :
F_20 ( V_56 L_33
L_34 ) ;
V_10 . V_65 = 1 ;
break;
}
}
void F_30 ( struct V_66 * V_67 , const char * V_68 )
{
struct V_50 * V_69 = NULL ;
if ( ! V_10 . V_65 || ! V_10 . V_57 )
return;
V_69 = F_31 ( V_10 . V_57 ) ;
V_70 = F_32 () ;
V_69 -> V_70 = V_70 ;
F_33 () ;
if ( V_67 )
V_69 -> V_67 = * V_67 ;
else
F_34 ( & V_69 -> V_67 ) ;
V_69 -> V_71 = * V_72 ;
F_35 ( ( char * ) V_68 ) ;
}
static inline int F_36 ( T_3 V_73 )
{
int V_6 = - 1 ;
char V_68 [ 3 ] ;
if ( ( V_73 & V_74 ) == F_37 ( L_35 ) ) {
V_73 &= ~ V_74 ;
V_73 >>= 24 ;
V_68 [ 2 ] = '\0' ;
V_68 [ 1 ] = V_73 & 0xff ;
V_68 [ 0 ] = ( V_73 >> 8 ) & 0xff ;
sscanf ( V_68 , L_36 , & V_6 ) ;
if ( V_6 > 31 )
V_6 = - 1 ;
}
return V_6 ;
}
static inline void F_38 ( struct V_66 * V_67 , T_3 V_75 ,
T_3 V_76 )
{
int V_6 ;
V_6 = F_36 ( V_75 ) ;
if ( V_6 >= 0 )
V_67 -> V_77 [ V_6 ] = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_37 ) )
V_67 -> V_78 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_38 ) )
V_67 -> V_79 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_39 ) )
V_67 -> V_80 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_40 ) )
V_67 -> V_81 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_41 ) )
V_67 -> V_82 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_42 ) )
V_67 -> V_83 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_43 ) )
V_67 -> V_84 = ( unsigned long ) V_76 ;
else if ( V_75 == F_37 ( L_44 ) )
V_67 -> V_85 = ( unsigned long ) V_76 ;
}
static struct V_86 *
F_39 ( struct V_86 * V_87 , struct V_66 * V_67 )
{
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
while ( F_21 ( V_87 -> V_75 ) != F_37 ( L_45 ) ) {
F_38 ( V_67 , F_21 ( V_87 -> V_75 ) ,
F_21 ( V_87 -> V_88 ) ) ;
V_87 ++ ;
}
V_87 ++ ;
return V_87 ;
}
static V_15 * F_40 ( V_15 * V_89 , char * V_90 , unsigned type ,
void * V_4 , T_4 V_91 )
{
struct V_92 V_93 ;
V_93 . V_94 = strlen ( V_90 ) + 1 ;
V_93 . V_95 = V_91 ;
V_93 . V_96 = type ;
memcpy ( V_89 , & V_93 , sizeof( V_93 ) ) ;
V_89 += ( sizeof( V_93 ) + 3 ) / 4 ;
memcpy ( V_89 , V_90 , V_93 . V_94 ) ;
V_89 += ( V_93 . V_94 + 3 ) / 4 ;
memcpy ( V_89 , V_4 , V_93 . V_95 ) ;
V_89 += ( V_93 . V_95 + 3 ) / 4 ;
return V_89 ;
}
static void F_41 ( V_15 * V_89 )
{
struct V_92 V_93 ;
V_93 . V_94 = 0 ;
V_93 . V_95 = 0 ;
V_93 . V_96 = 0 ;
memcpy ( V_89 , & V_93 , sizeof( V_93 ) ) ;
}
static V_15 * F_42 ( V_15 * V_89 , struct V_66 * V_67 )
{
struct V_97 V_98 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
F_43 ( & V_98 . V_99 , V_67 ) ;
V_89 = F_40 ( V_89 , V_100 , V_101 ,
& V_98 , sizeof( V_98 ) ) ;
return V_89 ;
}
static void F_44 ( char * V_102 )
{
struct V_51 * V_103 ;
struct V_52 * V_104 ;
V_103 = (struct V_51 * ) V_102 ;
V_102 += sizeof( struct V_51 ) ;
V_104 = (struct V_52 * ) V_102 ;
if ( V_104 -> V_105 == V_106 ) {
V_104 -> V_107 = V_10 . V_108 ;
V_104 -> V_109 = V_104 -> V_107 ;
V_104 -> V_110 = V_10 . V_111 ;
V_104 -> V_112 = V_10 . V_111 ;
}
return;
}
static void * F_45 ( unsigned long V_8 )
{
void * V_113 ;
struct V_114 * V_114 ;
unsigned long V_115 , V_116 , V_6 ;
V_115 = F_46 ( V_8 ) ;
V_113 = ( void * ) F_47 ( V_117 | V_118 , V_115 ) ;
if ( ! V_113 )
return NULL ;
V_116 = 1 << V_115 ;
V_114 = F_48 ( V_113 ) ;
for ( V_6 = 0 ; V_6 < V_116 ; V_6 ++ )
F_49 ( V_114 + V_6 ) ;
return V_113 ;
}
static void F_50 ( unsigned long V_113 , unsigned long V_8 )
{
struct V_114 * V_114 ;
unsigned long V_115 , V_116 , V_6 ;
V_115 = F_46 ( V_8 ) ;
V_116 = 1 << V_115 ;
V_114 = F_48 ( V_113 ) ;
for ( V_6 = 0 ; V_6 < V_116 ; V_6 ++ )
F_51 ( V_114 + V_6 ) ;
F_52 ( V_114 , V_115 ) ;
}
static int T_1 F_53 ( const struct V_22 * V_23 )
{
struct V_119 * V_120 ;
struct V_86 * V_87 ;
struct V_50 * V_69 = NULL ;
void * V_113 ;
unsigned long V_24 ;
V_15 V_121 , * V_122 ;
struct V_66 V_67 ;
int V_6 , V_61 = 0 , V_123 = 0 ;
if ( ! V_23 -> V_31 . V_124 )
return - V_125 ;
V_24 = F_21 ( V_23 -> V_31 . V_42 ) ;
V_113 = F_31 ( V_24 ) ;
V_120 = V_113 ;
if ( F_21 ( V_120 -> V_126 ) != V_127 ) {
F_20 ( V_64 L_46 ) ;
return - V_128 ;
}
F_8 ( L_47 ) ;
F_8 ( L_48 , F_21 ( V_120 -> V_126 ) ) ;
F_8 ( L_49 , F_3 ( V_120 -> V_129 ) ) ;
V_113 += F_3 ( V_120 -> V_129 ) ;
V_121 = F_3 ( * ( ( T_2 * ) ( V_113 ) ) ) ;
F_8 ( L_50 , V_121 ) ;
V_113 += sizeof( V_15 ) ;
V_87 = (struct V_86 * ) V_113 ;
V_10 . V_111 = V_121 * sizeof( V_130 ) ;
V_10 . V_111 = F_18 ( V_10 . V_111 ) ;
V_122 = F_45 ( V_10 . V_111 ) ;
if ( ! V_122 ) {
F_20 ( V_64 L_51
L_52 , V_10 . V_111 ) ;
return - V_131 ;
}
V_10 . V_108 = F_54 ( V_122 ) ;
F_8 ( L_53 ,
( V_121 * sizeof( V_130 ) ) , V_122 ) ;
if ( V_10 . V_57 )
V_69 = F_31 ( V_10 . V_57 ) ;
for ( V_6 = 0 ; V_6 < V_121 ; V_6 ++ ) {
if ( F_21 ( V_87 -> V_75 ) != F_37 ( L_54 ) ) {
F_20 ( V_64 L_55 ) ;
V_61 = - V_128 ;
goto V_132;
}
V_123 = F_21 ( V_87 -> V_88 ) & V_133 ;
if ( V_69 && ! F_55 ( V_123 , & V_69 -> V_71 ) ) {
F_56 ( V_87 ) ;
continue;
}
F_8 ( L_56 , V_123 ) ;
if ( V_69 && V_69 -> V_70 == V_123 ) {
V_67 = V_69 -> V_67 ;
V_122 = F_42 ( V_122 , & V_67 ) ;
F_56 ( V_87 ) ;
} else {
V_87 ++ ;
V_87 = F_39 ( V_87 , & V_67 ) ;
V_122 = F_42 ( V_122 , & V_67 ) ;
}
}
F_41 ( V_122 ) ;
if ( V_69 ) {
F_8 ( L_57 ,
V_69 -> V_134 ) ;
F_44 ( ( char * ) F_31 ( V_69 -> V_134 ) ) ;
}
return 0 ;
V_132:
F_50 ( ( unsigned long ) F_31 ( V_10 . V_108 ) ,
V_10 . V_111 ) ;
V_10 . V_108 = 0 ;
V_10 . V_111 = 0 ;
return V_61 ;
}
static int T_1 F_57 ( const struct V_22 * V_13 )
{
struct V_50 * V_69 ;
int V_61 = 0 ;
if ( ! V_13 || ! V_10 . V_57 )
return - V_125 ;
if ( ( F_58 ( V_13 -> V_26 . V_29 ) == V_135 ) ||
( V_13 -> V_31 . V_136 != 0 ) ||
( V_13 -> V_44 . V_136 != 0 ) ) {
F_20 ( V_64 L_58 ) ;
return - V_125 ;
}
if ( ( V_13 -> V_44 . V_124 !=
V_13 -> V_44 . V_41 ) ||
! V_13 -> V_31 . V_124 ) {
F_20 ( V_64 L_59 ) ;
return - V_125 ;
}
V_69 = F_31 ( V_10 . V_57 ) ;
if ( V_69 -> V_126 != V_137 ) {
F_20 ( V_64 L_60 ) ;
return - V_125 ;
}
V_61 = F_53 ( V_13 ) ;
if ( V_61 )
return V_61 ;
V_134 = V_69 -> V_134 ;
return 0 ;
}
static inline void F_59 ( unsigned long long V_54 ,
unsigned long long V_138 )
{
if ( V_54 == V_138 )
return;
F_8 ( L_61 ,
V_139 , V_54 , V_138 - 1 , ( V_138 - V_54 ) ) ;
V_140 [ V_139 ] . V_54 = V_54 ;
V_140 [ V_139 ] . V_8 = V_138 - V_54 ;
V_139 ++ ;
}
static void F_60 ( unsigned long long V_141 ,
unsigned long long V_138 )
{
unsigned long long V_142 , V_143 ;
V_142 = V_10 . V_58 ;
V_143 = V_142 + V_10 . V_59 ;
if ( ( V_142 < V_138 ) && ( V_143 > V_141 ) ) {
if ( ( V_141 < V_142 ) && ( V_138 > V_143 ) ) {
F_59 ( V_141 , V_142 ) ;
F_59 ( V_143 , V_138 ) ;
} else if ( V_141 < V_142 ) {
F_59 ( V_141 , V_142 ) ;
} else if ( V_143 < V_138 ) {
F_59 ( V_143 , V_138 ) ;
}
} else
F_59 ( V_141 , V_138 ) ;
}
static int F_61 ( char * V_102 )
{
struct V_51 * V_103 ;
V_103 = (struct V_51 * ) V_102 ;
V_102 += sizeof( struct V_51 ) ;
memcpy ( V_103 -> V_144 , V_145 , V_146 ) ;
V_103 -> V_144 [ V_147 ] = V_148 ;
V_103 -> V_144 [ V_149 ] = V_150 ;
V_103 -> V_144 [ V_151 ] = V_152 ;
V_103 -> V_144 [ V_153 ] = V_154 ;
memset ( V_103 -> V_144 + V_155 , 0 , V_156 - V_155 ) ;
V_103 -> V_157 = V_158 ;
V_103 -> V_159 = V_160 ;
V_103 -> V_161 = V_152 ;
V_103 -> V_162 = 0 ;
V_103 -> V_163 = sizeof( struct V_51 ) ;
V_103 -> V_164 = 0 ;
V_103 -> V_165 = V_166 ;
V_103 -> V_167 = sizeof( struct V_51 ) ;
V_103 -> V_168 = sizeof( struct V_52 ) ;
V_103 -> V_169 = 0 ;
V_103 -> V_170 = 0 ;
V_103 -> V_171 = 0 ;
V_103 -> V_172 = 0 ;
return 0 ;
}
static void F_62 ( void )
{
struct V_173 * V_174 ;
unsigned long long V_141 , V_138 ;
F_8 ( L_62 ) ;
V_139 = 0 ;
F_59 ( V_46 , V_10 . V_21 ) ;
F_63 (memory, reg) {
V_141 = ( unsigned long long ) V_174 -> V_54 ;
V_138 = V_141 + ( unsigned long long ) V_174 -> V_8 ;
if ( V_141 == V_46 && V_138 >= V_10 . V_21 )
V_141 = V_10 . V_21 ;
F_60 ( V_141 , V_138 ) ;
}
}
static inline unsigned long F_64 ( unsigned long V_175 )
{
if ( V_175 > V_46 && V_175 < V_10 . V_21 )
return F_21 ( V_23 . V_44 . V_42 ) + V_175 ;
else
return V_175 ;
}
static int F_65 ( char * V_102 )
{
struct V_51 * V_103 ;
struct V_52 * V_104 ;
int V_6 ;
F_61 ( V_102 ) ;
V_103 = (struct V_51 * ) V_102 ;
V_102 += sizeof( struct V_51 ) ;
V_104 = (struct V_52 * ) V_102 ;
V_102 += sizeof( struct V_52 ) ;
V_104 -> V_105 = V_106 ;
V_104 -> V_176 = 0 ;
V_104 -> V_177 = 0 ;
V_104 -> V_178 = 0 ;
V_104 -> V_109 = 0 ;
V_104 -> V_107 = 0 ;
V_104 -> V_110 = 0 ;
V_104 -> V_112 = 0 ;
( V_103 -> V_169 ) ++ ;
V_104 = (struct V_52 * ) V_102 ;
V_102 += sizeof( struct V_52 ) ;
V_104 -> V_105 = V_106 ;
V_104 -> V_176 = 0 ;
V_104 -> V_177 = 0 ;
V_104 -> V_178 = 0 ;
V_104 -> V_107 = F_64 ( F_66 () ) ;
V_104 -> V_109 = V_104 -> V_107 ;
V_104 -> V_112 = V_179 ;
V_104 -> V_110 = V_179 ;
( V_103 -> V_169 ) ++ ;
for ( V_6 = 0 ; V_6 < V_139 ; V_6 ++ ) {
unsigned long long V_180 , V_181 ;
V_180 = V_140 [ V_6 ] . V_54 ;
V_181 = V_140 [ V_6 ] . V_8 ;
if ( ! V_181 )
continue;
V_104 = (struct V_52 * ) V_102 ;
V_102 += sizeof( struct V_52 ) ;
V_104 -> V_105 = V_182 ;
V_104 -> V_176 = V_183 | V_184 | V_185 ;
V_104 -> V_109 = V_180 ;
if ( V_180 == V_46 ) {
V_104 -> V_109 = F_21 ( V_23 . V_44 . V_42 ) ;
}
V_104 -> V_107 = V_180 ;
V_104 -> V_177 = ( unsigned long ) F_31 ( V_180 ) ;
V_104 -> V_110 = V_181 ;
V_104 -> V_112 = V_181 ;
V_104 -> V_178 = 0 ;
( V_103 -> V_169 ) ++ ;
}
return 0 ;
}
static unsigned long F_67 ( unsigned long V_24 )
{
struct V_50 * V_69 ;
if ( ! V_24 )
return 0 ;
V_10 . V_57 = V_24 ;
V_69 = F_31 ( V_24 ) ;
V_24 += sizeof( struct V_50 ) ;
memset ( V_69 , 0 , sizeof( struct V_50 ) ) ;
V_69 -> V_126 = V_137 ;
V_69 -> V_134 = V_24 ;
V_69 -> V_70 = V_186 ;
return V_24 ;
}
static void F_68 ( void )
{
unsigned long V_24 ;
void * V_113 ;
if ( ! V_10 . V_59 )
return;
F_62 () ;
V_24 = F_21 ( V_23 . V_44 . V_42 ) + F_21 ( V_23 . V_44 . V_41 ) ;
V_24 = F_67 ( V_24 ) ;
V_113 = F_31 ( V_24 ) ;
F_8 ( L_63 , V_24 ) ;
F_65 ( V_113 ) ;
F_26 ( & V_23 ) ;
}
static int F_69 ( struct V_22 * V_23 )
{
int V_61 = 0 ;
unsigned int V_62 ;
F_8 ( L_64 ) ;
do {
V_61 = F_27 ( V_10 . V_12 , 3 , 1 , NULL ,
V_187 , V_23 ,
sizeof( struct V_22 ) ) ;
V_62 = F_28 ( V_61 ) ;
if ( V_62 )
F_29 ( V_62 ) ;
} while ( V_62 );
if ( V_61 ) {
F_20 ( V_64 L_65
L_66 , V_61 ) ;
return V_61 ;
}
V_10 . V_65 = 0 ;
return 0 ;
}
static int F_70 ( struct V_22 * V_23 )
{
int V_61 = 0 ;
unsigned int V_62 ;
F_8 ( L_67 ) ;
do {
V_61 = F_27 ( V_10 . V_12 , 3 , 1 , NULL ,
V_188 , V_23 ,
sizeof( struct V_22 ) ) ;
V_62 = F_28 ( V_61 ) ;
if ( V_62 )
F_29 ( V_62 ) ;
} while ( V_62 );
if ( V_61 ) {
F_71 ( L_68 , V_61 ) ;
return V_61 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_72 ( void )
{
if ( V_10 . V_14 ) {
F_9 ( & V_23 ,
F_21 ( V_13 -> V_31 . V_42 ) ) ;
F_70 ( & V_23 ) ;
}
}
static void F_73 ( unsigned long V_189 , unsigned long V_138 )
{
unsigned long V_24 ;
unsigned long V_142 , V_143 ;
V_142 = V_10 . V_58 ;
V_143 = V_142 + V_10 . V_59 ;
for ( V_24 = V_189 ; V_24 < V_138 ; V_24 += V_190 ) {
if ( V_24 <= V_143 && ( ( V_24 + V_190 ) > V_142 ) )
continue;
F_74 ( F_75 ( V_24 >> V_191 ) ) ;
}
}
static void F_76 ( void )
{
unsigned long V_192 , V_193 ;
unsigned long V_42 ;
F_77 ( & V_194 ) ;
if ( ! V_10 . V_14 ) {
F_78 ( & V_194 ) ;
return;
}
V_42 = F_21 ( V_13 -> V_31 . V_42 ) ;
F_72 () ;
F_78 ( & V_194 ) ;
V_192 = V_10 . V_58 ;
V_193 = V_192 +
V_10 . V_59 ;
V_10 . V_58 = V_42 ;
V_10 . V_59 = F_16 () ;
F_73 ( V_192 , V_193 ) ;
if ( V_10 . V_108 ) {
F_50 (
( unsigned long ) F_31 ( V_10 . V_108 ) ,
V_10 . V_111 ) ;
V_10 . V_108 = 0 ;
V_10 . V_111 = 0 ;
}
F_9 ( & V_23 , V_10 . V_58 ) ;
}
static T_5 F_79 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
const char * V_89 , T_4 V_116 )
{
if ( ! V_10 . V_14 )
return - V_199 ;
if ( V_89 [ 0 ] == '1' ) {
F_80 () ;
F_76 () ;
} else
return - V_125 ;
return V_116 ;
}
static T_5 F_81 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
char * V_89 )
{
return sprintf ( V_89 , L_69 , V_10 . V_20 ) ;
}
static T_5 F_82 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
char * V_89 )
{
return sprintf ( V_89 , L_69 , V_10 . V_65 ) ;
}
static T_5 F_83 ( struct V_195 * V_196 ,
struct V_197 * V_198 ,
const char * V_89 , T_4 V_116 )
{
int V_200 = 0 ;
if ( ! V_10 . V_20 || V_13 )
return - V_199 ;
F_77 ( & V_194 ) ;
switch ( V_89 [ 0 ] ) {
case '0' :
if ( V_10 . V_65 == 0 ) {
V_200 = - V_125 ;
goto V_201;
}
F_69 ( & V_23 ) ;
break;
case '1' :
if ( V_10 . V_65 == 1 ) {
V_200 = - V_125 ;
goto V_201;
}
F_68 () ;
break;
default:
V_200 = - V_125 ;
break;
}
V_201:
F_78 ( & V_194 ) ;
return V_200 < 0 ? V_200 : V_116 ;
}
static int F_84 ( struct V_202 * V_203 , void * V_204 )
{
const struct V_22 * V_205 ;
if ( ! V_10 . V_20 )
return 0 ;
F_77 ( & V_194 ) ;
if ( V_13 )
V_205 = V_13 ;
else {
F_78 ( & V_194 ) ;
V_205 = & V_23 ;
}
F_85 ( V_203 ,
L_70
L_71 ,
F_21 ( V_205 -> V_31 . V_42 ) ,
F_21 ( V_205 -> V_31 . V_42 ) +
F_21 ( V_205 -> V_31 . V_41 ) - 1 ,
F_21 ( V_205 -> V_31 . V_41 ) ,
F_21 ( V_205 -> V_31 . V_124 ) ) ;
F_85 ( V_203 ,
L_72
L_71 ,
F_21 ( V_205 -> V_43 . V_42 ) ,
F_21 ( V_205 -> V_43 . V_42 ) +
F_21 ( V_205 -> V_43 . V_41 ) - 1 ,
F_21 ( V_205 -> V_43 . V_41 ) ,
F_21 ( V_205 -> V_43 . V_124 ) ) ;
F_85 ( V_203 ,
L_73
L_71 ,
F_21 ( V_205 -> V_44 . V_42 ) ,
F_21 ( V_205 -> V_44 . V_42 ) +
F_21 ( V_205 -> V_44 . V_41 ) - 1 ,
F_21 ( V_205 -> V_44 . V_41 ) ,
F_21 ( V_205 -> V_44 . V_124 ) ) ;
if ( ! V_13 ||
( V_10 . V_58 ==
F_21 ( V_205 -> V_31 . V_42 ) ) )
goto V_206;
F_85 ( V_203 ,
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
F_78 ( & V_194 ) ;
return 0 ;
}
static int F_86 ( struct V_207 * V_207 , struct V_208 * V_208 )
{
return F_87 ( V_208 , F_84 , V_207 -> V_209 ) ;
}
static void F_88 ( void )
{
struct V_210 * V_211 ;
int V_61 = 0 ;
V_61 = F_89 ( V_212 , & V_213 . V_198 ) ;
if ( V_61 )
F_20 ( V_64 L_75
L_76 , V_61 ) ;
V_61 = F_89 ( V_212 , & V_214 . V_198 ) ;
if ( V_61 )
F_20 ( V_64 L_75
L_77 , V_61 ) ;
V_211 = F_90 ( L_78 , 0444 ,
V_215 , NULL ,
& V_216 ) ;
if ( ! V_211 )
F_20 ( V_64 L_79
L_80 ) ;
if ( V_10 . V_14 ) {
V_61 = F_89 ( V_212 , & V_217 . V_198 ) ;
if ( V_61 )
F_20 ( V_64 L_75
L_81 , V_61 ) ;
}
return;
}
int T_1 F_91 ( void )
{
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_20 ( V_64 L_16
L_17 ) ;
return 0 ;
}
F_7 () ;
if ( V_10 . V_14 ) {
if ( F_57 ( V_13 ) < 0 )
F_76 () ;
}
else if ( V_10 . V_59 )
F_9 ( & V_23 , V_10 . V_58 ) ;
F_88 () ;
return 1 ;
}
