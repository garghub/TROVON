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
int V_47 ;
unsigned long long V_48 , V_8 ;
V_47 = F_15 ( V_49 , F_16 () ,
& V_8 , & V_48 ) ;
if ( V_47 == 0 && V_8 > 0 ) {
V_10 . V_50 = ( unsigned long ) V_8 ;
return V_10 . V_50 ;
}
V_8 = F_17 () / 20 ;
V_8 = V_8 & ~ 0x0FFFFFFFUL ;
if ( V_51 && V_8 > V_51 )
V_8 = V_51 ;
return ( V_8 > V_52 ? V_8 : V_52 ) ;
}
static unsigned long F_18 ( void )
{
unsigned long V_8 = 0 ;
V_8 += V_10 . V_17 ;
V_8 += V_10 . V_19 ;
V_8 += V_10 . V_21 ;
V_8 += sizeof( struct V_53 ) ;
V_8 += sizeof( struct V_54 ) ;
V_8 += sizeof( struct V_55 ) ;
V_8 += sizeof( struct V_55 ) * ( F_19 ( V_56 ) + 2 ) ;
V_8 = F_20 ( V_8 ) ;
return V_8 ;
}
int T_1 F_21 ( void )
{
unsigned long V_48 , V_8 , V_57 ;
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_22 ( V_58 L_16
L_17 ) ;
V_10 . V_20 = 0 ;
return 0 ;
}
if ( V_13 )
V_10 . V_21 = F_23 ( V_13 -> V_44 . V_41 ) ;
else
V_10 . V_21 = F_14 () ;
if ( V_51 && V_51 < F_17 () ) {
V_8 = F_18 () ;
if ( ( V_51 + V_8 ) < F_17 () )
V_51 += V_8 ;
else
V_51 = F_17 () ;
F_22 ( V_58 L_18
L_19 , V_51 ) ;
}
if ( V_51 )
V_57 = V_51 ;
else
V_57 = F_17 () ;
if ( V_10 . V_14 ) {
F_22 ( V_58 L_20 ) ;
V_48 = V_10 . V_21 ;
V_8 = V_57 - V_48 ;
F_24 ( V_48 , V_8 ) ;
F_22 ( V_58 L_21
L_22 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_48 >> 20 ) ) ;
V_10 . V_59 =
F_23 ( V_13 -> V_44 . V_42 ) +
F_23 ( V_13 -> V_44 . V_41 ) ;
F_8 ( L_23 ,
( void * ) V_10 . V_59 ) ;
} else {
V_8 = F_18 () ;
for ( V_48 = V_10 . V_21 ;
V_48 <= ( V_57 - V_8 ) ;
V_48 += V_8 ) {
if ( F_25 ( V_48 , V_8 ) &&
! F_26 ( V_48 , V_8 ) )
break;
}
if ( ( V_48 > ( V_57 - V_8 ) ) ||
F_24 ( V_48 , V_8 ) ) {
F_27 ( L_24 ) ;
return 0 ;
}
F_28 ( L_25
L_26 ,
( unsigned long ) ( V_8 >> 20 ) ,
( unsigned long ) ( V_48 >> 20 ) ,
( unsigned long ) ( F_16 () >> 20 ) ) ;
}
V_10 . V_60 = V_48 ;
V_10 . V_61 = V_8 ;
return 1 ;
}
unsigned long T_1 F_29 ( void )
{
return F_30 () / V_62 ;
}
static int T_1 F_31 ( char * V_63 )
{
if ( ! V_63 )
return 1 ;
if ( strncmp ( V_63 , L_27 , 2 ) == 0 )
V_10 . V_20 = 1 ;
else if ( strncmp ( V_63 , L_28 , 3 ) == 0 )
V_10 . V_20 = 0 ;
return 0 ;
}
static void F_32 ( struct V_22 * V_23 )
{
int V_64 ;
unsigned int V_65 ;
F_8 ( L_29 ) ;
do {
V_64 = F_33 ( V_10 . V_12 , 3 , 1 , NULL ,
V_66 , V_23 ,
sizeof( struct V_22 ) ) ;
V_65 = F_34 ( V_64 ) ;
if ( V_65 )
F_35 ( V_65 ) ;
} while ( V_65 );
switch ( V_64 ) {
case - 1 :
F_22 ( V_67 L_30
L_31 , V_64 ) ;
break;
case - 3 :
F_22 ( V_67 L_30
L_32 , V_64 ) ;
break;
case - 9 :
F_22 ( V_67 L_33
L_34 ) ;
V_10 . V_68 = 1 ;
break;
case 0 :
F_22 ( V_58 L_35
L_36 ) ;
V_10 . V_68 = 1 ;
break;
}
}
void F_36 ( struct V_69 * V_70 , const char * V_71 )
{
struct V_53 * V_72 = NULL ;
int V_73 , V_74 ;
if ( ! V_10 . V_68 || ! V_10 . V_59 )
return;
V_74 = F_37 () ;
V_73 = F_38 ( & V_75 , - 1 , V_74 ) ;
if ( V_73 != - 1 ) {
while ( V_10 . V_68 )
F_39 () ;
return;
}
V_72 = F_40 ( V_10 . V_59 ) ;
V_72 -> V_75 = V_75 ;
F_41 () ;
if ( V_70 )
V_72 -> V_70 = * V_70 ;
else
F_42 ( & V_72 -> V_70 ) ;
V_72 -> V_76 = * V_77 ;
F_43 ( ( char * ) V_71 ) ;
}
static inline int F_44 ( T_3 V_78 )
{
int V_6 = - 1 ;
char V_71 [ 3 ] ;
if ( ( V_78 & V_79 ) == F_45 ( L_37 ) ) {
V_78 &= ~ V_79 ;
V_78 >>= 24 ;
V_71 [ 2 ] = '\0' ;
V_71 [ 1 ] = V_78 & 0xff ;
V_71 [ 0 ] = ( V_78 >> 8 ) & 0xff ;
sscanf ( V_71 , L_38 , & V_6 ) ;
if ( V_6 > 31 )
V_6 = - 1 ;
}
return V_6 ;
}
static inline void F_46 ( struct V_69 * V_70 , T_3 V_80 ,
T_3 V_81 )
{
int V_6 ;
V_6 = F_44 ( V_80 ) ;
if ( V_6 >= 0 )
V_70 -> V_82 [ V_6 ] = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_39 ) )
V_70 -> V_83 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_40 ) )
V_70 -> V_84 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_41 ) )
V_70 -> V_85 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_42 ) )
V_70 -> V_86 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_43 ) )
V_70 -> V_87 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_44 ) )
V_70 -> V_88 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_45 ) )
V_70 -> V_89 = ( unsigned long ) V_81 ;
else if ( V_80 == F_45 ( L_46 ) )
V_70 -> V_90 = ( unsigned long ) V_81 ;
}
static struct V_91 *
F_47 ( struct V_91 * V_92 , struct V_69 * V_70 )
{
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
while ( F_23 ( V_92 -> V_80 ) != F_45 ( L_47 ) ) {
F_46 ( V_70 , F_23 ( V_92 -> V_80 ) ,
F_23 ( V_92 -> V_93 ) ) ;
V_92 ++ ;
}
V_92 ++ ;
return V_92 ;
}
static V_15 * F_48 ( V_15 * V_94 , struct V_69 * V_70 )
{
struct V_95 V_96 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
F_49 ( & V_96 . V_97 , V_70 ) ;
V_94 = F_50 ( V_94 , V_98 , V_99 ,
& V_96 , sizeof( V_96 ) ) ;
return V_94 ;
}
static void F_51 ( char * V_100 )
{
struct V_54 * V_101 ;
struct V_55 * V_102 ;
V_101 = (struct V_54 * ) V_100 ;
V_100 += sizeof( struct V_54 ) ;
V_102 = (struct V_55 * ) V_100 ;
if ( V_102 -> V_103 == V_104 ) {
V_102 -> V_105 = V_10 . V_106 ;
V_102 -> V_107 = V_102 -> V_105 ;
V_102 -> V_108 = V_10 . V_109 ;
V_102 -> V_110 = V_10 . V_109 ;
}
return;
}
static void * F_52 ( unsigned long V_8 )
{
void * V_111 ;
struct V_112 * V_112 ;
unsigned long V_113 , V_114 , V_6 ;
V_113 = F_53 ( V_8 ) ;
V_111 = ( void * ) F_54 ( V_115 | V_116 , V_113 ) ;
if ( ! V_111 )
return NULL ;
V_114 = 1 << V_113 ;
V_112 = F_55 ( V_111 ) ;
for ( V_6 = 0 ; V_6 < V_114 ; V_6 ++ )
F_56 ( V_112 + V_6 ) ;
return V_111 ;
}
static void F_57 ( unsigned long V_111 , unsigned long V_8 )
{
struct V_112 * V_112 ;
unsigned long V_113 , V_114 , V_6 ;
V_113 = F_53 ( V_8 ) ;
V_114 = 1 << V_113 ;
V_112 = F_55 ( V_111 ) ;
for ( V_6 = 0 ; V_6 < V_114 ; V_6 ++ )
F_58 ( V_112 + V_6 ) ;
F_59 ( V_112 , V_113 ) ;
}
static int T_1 F_60 ( const struct V_22 * V_23 )
{
struct V_117 * V_118 ;
struct V_91 * V_92 ;
struct V_53 * V_72 = NULL ;
void * V_111 ;
unsigned long V_24 ;
V_15 V_119 , * V_120 ;
struct V_69 V_70 ;
int V_6 , V_64 = 0 , V_121 = 0 ;
if ( ! V_23 -> V_31 . V_122 )
return - V_123 ;
V_24 = F_23 ( V_23 -> V_31 . V_42 ) ;
V_111 = F_40 ( V_24 ) ;
V_118 = V_111 ;
if ( F_23 ( V_118 -> V_124 ) != V_125 ) {
F_22 ( V_67 L_48 ) ;
return - V_126 ;
}
F_8 ( L_49 ) ;
F_8 ( L_50 , F_23 ( V_118 -> V_124 ) ) ;
F_8 ( L_51 , F_3 ( V_118 -> V_127 ) ) ;
V_111 += F_3 ( V_118 -> V_127 ) ;
V_119 = F_3 ( * ( ( T_2 * ) ( V_111 ) ) ) ;
F_8 ( L_52 , V_119 ) ;
V_111 += sizeof( V_15 ) ;
V_92 = (struct V_91 * ) V_111 ;
V_10 . V_109 = V_119 * sizeof( V_128 ) ;
V_10 . V_109 = F_20 ( V_10 . V_109 ) ;
V_120 = F_52 ( V_10 . V_109 ) ;
if ( ! V_120 ) {
F_22 ( V_67 L_53
L_54 , V_10 . V_109 ) ;
return - V_129 ;
}
V_10 . V_106 = F_61 ( V_120 ) ;
F_8 ( L_55 ,
( V_119 * sizeof( V_128 ) ) , V_120 ) ;
if ( V_10 . V_59 )
V_72 = F_40 ( V_10 . V_59 ) ;
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ ) {
if ( F_23 ( V_92 -> V_80 ) != F_45 ( L_56 ) ) {
F_22 ( V_67 L_57 ) ;
V_64 = - V_126 ;
goto V_130;
}
V_121 = F_23 ( V_92 -> V_93 ) & V_131 ;
if ( V_72 && ! F_62 ( V_121 , & V_72 -> V_76 ) ) {
F_63 ( V_92 ) ;
continue;
}
F_8 ( L_58 , V_121 ) ;
if ( V_72 && V_72 -> V_75 == V_121 ) {
V_70 = V_72 -> V_70 ;
V_120 = F_48 ( V_120 , & V_70 ) ;
F_63 ( V_92 ) ;
} else {
V_92 ++ ;
V_92 = F_47 ( V_92 , & V_70 ) ;
V_120 = F_48 ( V_120 , & V_70 ) ;
}
}
F_64 ( V_120 ) ;
if ( V_72 ) {
F_8 ( L_59 ,
V_72 -> V_132 ) ;
F_51 ( ( char * ) F_40 ( V_72 -> V_132 ) ) ;
}
return 0 ;
V_130:
F_57 ( ( unsigned long ) F_40 ( V_10 . V_106 ) ,
V_10 . V_109 ) ;
V_10 . V_106 = 0 ;
V_10 . V_109 = 0 ;
return V_64 ;
}
static int T_1 F_65 ( const struct V_22 * V_13 )
{
struct V_53 * V_72 ;
int V_64 = 0 ;
if ( ! V_13 || ! V_10 . V_59 )
return - V_123 ;
if ( ( F_66 ( V_13 -> V_26 . V_29 ) == V_133 ) ||
( V_13 -> V_31 . V_134 != 0 ) ||
( V_13 -> V_44 . V_134 != 0 ) ) {
F_22 ( V_67 L_60 ) ;
return - V_123 ;
}
if ( ( V_13 -> V_44 . V_122 !=
V_13 -> V_44 . V_41 ) ||
! V_13 -> V_31 . V_122 ) {
F_22 ( V_67 L_61 ) ;
return - V_123 ;
}
V_72 = F_40 ( V_10 . V_59 ) ;
if ( V_72 -> V_124 != V_135 ) {
F_22 ( V_67 L_62 ) ;
return - V_123 ;
}
V_64 = F_60 ( V_13 ) ;
if ( V_64 )
return V_64 ;
V_132 = V_72 -> V_132 ;
return 0 ;
}
static inline void F_67 ( unsigned long long V_48 ,
unsigned long long V_136 )
{
if ( V_48 == V_136 )
return;
F_8 ( L_63 ,
V_137 , V_48 , V_136 - 1 , ( V_136 - V_48 ) ) ;
V_138 [ V_137 ] . V_48 = V_48 ;
V_138 [ V_137 ] . V_8 = V_136 - V_48 ;
V_137 ++ ;
}
static void F_68 ( unsigned long long V_139 ,
unsigned long long V_136 )
{
unsigned long long V_140 , V_141 ;
V_140 = V_10 . V_60 ;
V_141 = V_140 + V_10 . V_61 ;
if ( ( V_140 < V_136 ) && ( V_141 > V_139 ) ) {
if ( ( V_139 < V_140 ) && ( V_136 > V_141 ) ) {
F_67 ( V_139 , V_140 ) ;
F_67 ( V_141 , V_136 ) ;
} else if ( V_139 < V_140 ) {
F_67 ( V_139 , V_140 ) ;
} else if ( V_141 < V_136 ) {
F_67 ( V_141 , V_136 ) ;
}
} else
F_67 ( V_139 , V_136 ) ;
}
static int F_69 ( char * V_100 )
{
struct V_54 * V_101 ;
V_101 = (struct V_54 * ) V_100 ;
V_100 += sizeof( struct V_54 ) ;
memcpy ( V_101 -> V_142 , V_143 , V_144 ) ;
V_101 -> V_142 [ V_145 ] = V_146 ;
V_101 -> V_142 [ V_147 ] = V_148 ;
V_101 -> V_142 [ V_149 ] = V_150 ;
V_101 -> V_142 [ V_151 ] = V_152 ;
memset ( V_101 -> V_142 + V_153 , 0 , V_154 - V_153 ) ;
V_101 -> V_155 = V_156 ;
V_101 -> V_157 = V_158 ;
V_101 -> V_159 = V_150 ;
V_101 -> V_160 = 0 ;
V_101 -> V_161 = sizeof( struct V_54 ) ;
V_101 -> V_162 = 0 ;
#if F_70 ( V_163 )
V_101 -> V_164 = V_163 ;
#else
V_101 -> V_164 = 0 ;
#endif
V_101 -> V_165 = sizeof( struct V_54 ) ;
V_101 -> V_166 = sizeof( struct V_55 ) ;
V_101 -> V_167 = 0 ;
V_101 -> V_168 = 0 ;
V_101 -> V_169 = 0 ;
V_101 -> V_170 = 0 ;
return 0 ;
}
static void F_71 ( void )
{
struct V_171 * V_172 ;
unsigned long long V_139 , V_136 ;
F_8 ( L_64 ) ;
V_137 = 0 ;
F_67 ( V_46 , V_10 . V_21 ) ;
F_72 (memory, reg) {
V_139 = ( unsigned long long ) V_172 -> V_48 ;
V_136 = V_139 + ( unsigned long long ) V_172 -> V_8 ;
if ( V_139 == V_46 && V_136 >= V_10 . V_21 )
V_139 = V_10 . V_21 ;
F_68 ( V_139 , V_136 ) ;
}
}
static inline unsigned long F_73 ( unsigned long V_173 )
{
if ( V_173 > V_46 && V_173 < V_10 . V_21 )
return F_23 ( V_23 . V_44 . V_42 ) + V_173 ;
else
return V_173 ;
}
static int F_74 ( char * V_100 )
{
struct V_54 * V_101 ;
struct V_55 * V_102 ;
int V_6 ;
F_69 ( V_100 ) ;
V_101 = (struct V_54 * ) V_100 ;
V_100 += sizeof( struct V_54 ) ;
V_102 = (struct V_55 * ) V_100 ;
V_100 += sizeof( struct V_55 ) ;
V_102 -> V_103 = V_104 ;
V_102 -> V_174 = 0 ;
V_102 -> V_175 = 0 ;
V_102 -> V_176 = 0 ;
V_102 -> V_107 = 0 ;
V_102 -> V_105 = 0 ;
V_102 -> V_108 = 0 ;
V_102 -> V_110 = 0 ;
( V_101 -> V_167 ) ++ ;
V_102 = (struct V_55 * ) V_100 ;
V_100 += sizeof( struct V_55 ) ;
V_102 -> V_103 = V_104 ;
V_102 -> V_174 = 0 ;
V_102 -> V_175 = 0 ;
V_102 -> V_176 = 0 ;
V_102 -> V_105 = F_73 ( F_75 () ) ;
V_102 -> V_107 = V_102 -> V_105 ;
V_102 -> V_110 = V_177 ;
V_102 -> V_108 = V_177 ;
( V_101 -> V_167 ) ++ ;
for ( V_6 = 0 ; V_6 < V_137 ; V_6 ++ ) {
unsigned long long V_178 , V_179 ;
V_178 = V_138 [ V_6 ] . V_48 ;
V_179 = V_138 [ V_6 ] . V_8 ;
if ( ! V_179 )
continue;
V_102 = (struct V_55 * ) V_100 ;
V_100 += sizeof( struct V_55 ) ;
V_102 -> V_103 = V_180 ;
V_102 -> V_174 = V_181 | V_182 | V_183 ;
V_102 -> V_107 = V_178 ;
if ( V_178 == V_46 ) {
V_102 -> V_107 = F_23 ( V_23 . V_44 . V_42 ) ;
}
V_102 -> V_105 = V_178 ;
V_102 -> V_175 = ( unsigned long ) F_40 ( V_178 ) ;
V_102 -> V_108 = V_179 ;
V_102 -> V_110 = V_179 ;
V_102 -> V_176 = 0 ;
( V_101 -> V_167 ) ++ ;
}
return 0 ;
}
static unsigned long F_76 ( unsigned long V_24 )
{
struct V_53 * V_72 ;
if ( ! V_24 )
return 0 ;
V_10 . V_59 = V_24 ;
V_72 = F_40 ( V_24 ) ;
V_24 += sizeof( struct V_53 ) ;
memset ( V_72 , 0 , sizeof( struct V_53 ) ) ;
V_72 -> V_124 = V_135 ;
V_72 -> V_132 = V_24 ;
V_72 -> V_75 = V_184 ;
return V_24 ;
}
static void F_77 ( void )
{
unsigned long V_24 ;
void * V_111 ;
if ( ! V_10 . V_61 )
return;
F_71 () ;
V_24 = F_23 ( V_23 . V_44 . V_42 ) + F_23 ( V_23 . V_44 . V_41 ) ;
V_24 = F_76 ( V_24 ) ;
V_111 = F_40 ( V_24 ) ;
F_8 ( L_65 , V_24 ) ;
F_74 ( V_111 ) ;
F_32 ( & V_23 ) ;
}
static int F_78 ( struct V_22 * V_23 )
{
int V_64 = 0 ;
unsigned int V_65 ;
F_8 ( L_66 ) ;
do {
V_64 = F_33 ( V_10 . V_12 , 3 , 1 , NULL ,
V_185 , V_23 ,
sizeof( struct V_22 ) ) ;
V_65 = F_34 ( V_64 ) ;
if ( V_65 )
F_35 ( V_65 ) ;
} while ( V_65 );
if ( V_64 ) {
F_22 ( V_67 L_67
L_68 , V_64 ) ;
return V_64 ;
}
V_10 . V_68 = 0 ;
return 0 ;
}
static int F_79 ( struct V_22 * V_23 )
{
int V_64 = 0 ;
unsigned int V_65 ;
F_8 ( L_69 ) ;
do {
V_64 = F_33 ( V_10 . V_12 , 3 , 1 , NULL ,
V_186 , V_23 ,
sizeof( struct V_22 ) ) ;
V_65 = F_34 ( V_64 ) ;
if ( V_65 )
F_35 ( V_65 ) ;
} while ( V_65 );
if ( V_64 ) {
F_27 ( L_70 , V_64 ) ;
return V_64 ;
}
V_10 . V_14 = 0 ;
V_13 = NULL ;
return 0 ;
}
void F_80 ( void )
{
if ( V_10 . V_14 ) {
F_9 ( & V_23 ,
F_23 ( V_13 -> V_31 . V_42 ) ) ;
F_79 ( & V_23 ) ;
}
}
static void F_81 ( unsigned long V_187 , unsigned long V_136 )
{
unsigned long V_24 ;
unsigned long V_140 , V_141 ;
V_140 = V_10 . V_60 ;
V_141 = V_140 + V_10 . V_61 ;
for ( V_24 = V_187 ; V_24 < V_136 ; V_24 += V_62 ) {
if ( V_24 <= V_141 && ( ( V_24 + V_62 ) > V_140 ) )
continue;
F_82 ( F_83 ( V_24 >> V_188 ) ) ;
}
}
static void F_84 ( void )
{
unsigned long V_189 , V_190 ;
unsigned long V_42 ;
F_85 ( & V_191 ) ;
if ( ! V_10 . V_14 ) {
F_86 ( & V_191 ) ;
return;
}
V_42 = F_23 ( V_13 -> V_31 . V_42 ) ;
F_80 () ;
F_86 ( & V_191 ) ;
V_189 = V_10 . V_60 ;
V_190 = V_189 +
V_10 . V_61 ;
V_10 . V_60 = V_42 ;
V_10 . V_61 = F_18 () ;
F_81 ( V_189 , V_190 ) ;
if ( V_10 . V_106 ) {
F_57 (
( unsigned long ) F_40 ( V_10 . V_106 ) ,
V_10 . V_109 ) ;
V_10 . V_106 = 0 ;
V_10 . V_109 = 0 ;
}
F_9 ( & V_23 , V_10 . V_60 ) ;
}
static T_4 F_87 ( struct V_192 * V_193 ,
struct V_194 * V_195 ,
const char * V_94 , T_5 V_114 )
{
if ( ! V_10 . V_14 )
return - V_196 ;
if ( V_94 [ 0 ] == '1' ) {
#ifdef F_88
F_89 () ;
#endif
F_84 () ;
} else
return - V_123 ;
return V_114 ;
}
static T_4 F_90 ( struct V_192 * V_193 ,
struct V_194 * V_195 ,
char * V_94 )
{
return sprintf ( V_94 , L_71 , V_10 . V_20 ) ;
}
static T_4 F_91 ( struct V_192 * V_193 ,
struct V_194 * V_195 ,
char * V_94 )
{
return sprintf ( V_94 , L_71 , V_10 . V_68 ) ;
}
static T_4 F_92 ( struct V_192 * V_193 ,
struct V_194 * V_195 ,
const char * V_94 , T_5 V_114 )
{
int V_47 = 0 ;
if ( ! V_10 . V_20 || V_13 )
return - V_196 ;
F_85 ( & V_191 ) ;
switch ( V_94 [ 0 ] ) {
case '0' :
if ( V_10 . V_68 == 0 ) {
V_47 = - V_123 ;
goto V_197;
}
F_78 ( & V_23 ) ;
break;
case '1' :
if ( V_10 . V_68 == 1 ) {
V_47 = - V_123 ;
goto V_197;
}
F_77 () ;
break;
default:
V_47 = - V_123 ;
break;
}
V_197:
F_86 ( & V_191 ) ;
return V_47 < 0 ? V_47 : V_114 ;
}
static int F_93 ( struct V_198 * V_199 , void * V_200 )
{
const struct V_22 * V_201 ;
if ( ! V_10 . V_20 )
return 0 ;
F_85 ( & V_191 ) ;
if ( V_13 )
V_201 = V_13 ;
else {
F_86 ( & V_191 ) ;
V_201 = & V_23 ;
}
F_94 ( V_199 ,
L_72
L_73 ,
F_23 ( V_201 -> V_31 . V_42 ) ,
F_23 ( V_201 -> V_31 . V_42 ) +
F_23 ( V_201 -> V_31 . V_41 ) - 1 ,
F_23 ( V_201 -> V_31 . V_41 ) ,
F_23 ( V_201 -> V_31 . V_122 ) ) ;
F_94 ( V_199 ,
L_74
L_73 ,
F_23 ( V_201 -> V_43 . V_42 ) ,
F_23 ( V_201 -> V_43 . V_42 ) +
F_23 ( V_201 -> V_43 . V_41 ) - 1 ,
F_23 ( V_201 -> V_43 . V_41 ) ,
F_23 ( V_201 -> V_43 . V_122 ) ) ;
F_94 ( V_199 ,
L_75
L_73 ,
F_23 ( V_201 -> V_44 . V_42 ) ,
F_23 ( V_201 -> V_44 . V_42 ) +
F_23 ( V_201 -> V_44 . V_41 ) - 1 ,
F_23 ( V_201 -> V_44 . V_41 ) ,
F_23 ( V_201 -> V_44 . V_122 ) ) ;
if ( ! V_13 ||
( V_10 . V_60 ==
F_23 ( V_201 -> V_31 . V_42 ) ) )
goto V_202;
F_94 ( V_199 ,
L_76
L_73 ,
( unsigned long long ) V_10 . V_60 ,
F_23 ( V_201 -> V_31 . V_42 ) - 1 ,
F_23 ( V_201 -> V_31 . V_42 ) -
V_10 . V_60 ,
F_23 ( V_201 -> V_31 . V_42 ) -
V_10 . V_60 ) ;
V_202:
if ( V_13 )
F_86 ( & V_191 ) ;
return 0 ;
}
static int F_95 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_96 ( V_204 , F_93 , V_203 -> V_205 ) ;
}
static void F_97 ( void )
{
struct V_206 * V_207 ;
int V_64 = 0 ;
V_64 = F_98 ( V_208 , & V_209 . V_195 ) ;
if ( V_64 )
F_22 ( V_67 L_77
L_78 , V_64 ) ;
V_64 = F_98 ( V_208 , & V_210 . V_195 ) ;
if ( V_64 )
F_22 ( V_67 L_77
L_79 , V_64 ) ;
V_207 = F_99 ( L_80 , 0444 ,
V_211 , NULL ,
& V_212 ) ;
if ( ! V_207 )
F_22 ( V_67 L_81
L_82 ) ;
if ( V_10 . V_14 ) {
V_64 = F_98 ( V_208 , & V_213 . V_195 ) ;
if ( V_64 )
F_22 ( V_67 L_77
L_83 , V_64 ) ;
}
return;
}
int T_1 F_100 ( void )
{
if ( ! V_10 . V_20 )
return 0 ;
if ( ! V_10 . V_11 ) {
F_22 ( V_67 L_16
L_17 ) ;
return 0 ;
}
F_7 () ;
if ( V_10 . V_14 ) {
if ( F_65 ( V_13 ) < 0 )
F_84 () ;
}
else if ( V_10 . V_61 )
F_9 ( & V_23 , V_10 . V_60 ) ;
F_97 () ;
return 1 ;
}
