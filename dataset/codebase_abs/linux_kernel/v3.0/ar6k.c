void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
F_4 ( V_2 ) ;
}
struct V_3 * F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( V_2 ) ;
V_4 = F_6 ( & V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_6 ) {
F_9 ( V_2 -> V_7 ) ;
V_2 -> V_6 = false ;
}
F_10 ( V_2 ) ;
if ( F_11 ( & V_2 -> V_8 ) ) {
F_12 ( & V_2 -> V_8 ) ;
}
}
int F_13 ( struct V_1 * V_2 )
{
T_1 V_9 [ V_10 ] ;
int V_11 = 0 ;
int V_12 ;
T_2 V_13 ;
do {
F_14 ( & V_2 -> V_14 ) ;
F_15 ( & V_2 -> V_5 ) ;
F_16 ( & V_2 -> V_8 ) ;
F_17 ( & V_13 , sizeof( T_2 ) ) ;
V_13 . V_15 = V_16 ;
V_13 . V_17 = V_18 ;
V_13 . V_19 = V_2 ;
V_11 = F_18 ( V_2 -> V_7 , & V_13 ) ;
if ( V_11 ) {
break;
}
V_2 -> V_6 = true ;
V_11 = F_19 ( V_2 -> V_7 , V_20 ,
& V_2 -> V_21 , sizeof( V_2 -> V_21 ) ) ;
if ( V_11 ) {
F_20 ( false ) ;
break;
}
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ ) {
struct V_3 * V_23 ;
V_23 = & V_2 -> V_24 [ V_12 ] . V_25 ;
F_21 ( V_23 ,
V_2 ,
V_2 -> V_24 [ V_12 ] . V_26 ,
V_27 ,
0 ) ;
F_1 ( V_2 , V_23 ) ;
}
V_11 = F_19 ( V_2 -> V_7 , V_28 ,
V_9 , sizeof( V_9 ) ) ;
if ( V_11 ) {
F_20 ( false ) ;
break;
}
V_2 -> V_29 = V_9 [ V_30 ] ;
F_20 ( ( V_2 -> V_29 & ( V_2 -> V_29 - 1 ) ) == 0 ) ;
V_2 -> V_31 = V_2 -> V_29 - 1 ;
F_22 ( V_32 , ( L_1 ,
V_2 -> V_29 , V_2 -> V_21 . V_33 [ V_34 ] ) ) ;
V_2 -> V_35 = NULL ;
F_19 ( V_2 -> V_7 ,
V_36 ,
& V_2 -> V_35 ,
sizeof( V_2 -> V_35 ) ) ;
V_2 -> V_37 = V_38 ;
F_19 ( V_2 -> V_7 ,
V_39 ,
& V_2 -> V_37 ,
sizeof( V_2 -> V_37 ) ) ;
switch ( V_2 -> V_37 ) {
case V_40 :
F_22 ( V_41 , ( L_2 ) ) ;
F_19 ( V_2 -> V_7 ,
V_42 ,
& V_2 -> V_43 ,
sizeof( V_2 -> V_43 ) ) ;
if ( V_2 -> V_43 . V_44 > 0 ) {
F_22 ( V_41 ,
( L_3 ,
V_2 -> V_43 . V_44 ) ) ;
V_2 -> V_45 = true ;
}
break;
case V_38 :
F_22 ( V_32 , ( L_4 ) ) ;
break;
default:
F_20 ( false ) ;
}
V_2 -> V_46 = NULL ;
F_19 ( V_2 -> V_7 ,
V_47 ,
& V_2 -> V_46 ,
sizeof( V_2 -> V_46 ) ) ;
F_22 ( V_32 , ( L_5 ,
( unsigned long ) V_2 -> V_35 , ( unsigned long ) V_2 -> V_46 ) ) ;
V_11 = F_23 ( V_2 ) ;
if ( V_11 ) {
break;
}
V_11 = F_24 ( V_2 ) ;
} while ( false );
if ( V_11 ) {
if ( V_2 -> V_6 ) {
F_9 ( V_2 -> V_7 ) ;
V_2 -> V_6 = false ;
}
}
return V_11 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_48 V_49 ;
F_2 ( V_2 ) ;
V_2 -> V_50 . V_51 = F_26 ( 0x01 ) |
F_27 ( 0x01 ) |
F_28 ( 0x01 ) ;
if ( NULL == V_2 -> V_35 ) {
V_2 -> V_50 . V_51 |= F_29 ( 0x01 ) ;
} else {
V_2 -> V_50 . V_51 &= ~ F_29 ( 0x01 ) ;
}
V_2 -> V_50 . V_52 = F_30 ( 0x00 ) ;
V_2 -> V_50 . V_53 =
F_31 ( 0x01 ) |
F_32 ( 0x01 ) ;
V_2 -> V_50 . V_54 =
F_33 ( V_55 ) ;
memcpy ( & V_49 , & V_2 -> V_50 , V_56 ) ;
F_4 ( V_2 ) ;
V_11 = F_34 ( V_2 -> V_7 ,
V_57 ,
& V_49 . V_51 ,
V_56 ,
V_58 ,
NULL ) ;
if ( V_11 ) {
F_22 ( V_59 ,
( L_6 , V_11 ) ) ;
}
return V_11 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_48 V_49 ;
F_2 ( V_2 ) ;
V_2 -> V_50 . V_51 = 0 ;
V_2 -> V_50 . V_52 = 0 ;
V_2 -> V_50 . V_53 = 0 ;
V_2 -> V_50 . V_54 = 0 ;
memcpy ( & V_49 , & V_2 -> V_50 , V_56 ) ;
F_4 ( V_2 ) ;
return F_34 ( V_2 -> V_7 ,
V_57 ,
& V_49 . V_51 ,
V_56 ,
V_58 ,
NULL ) ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
F_23 ( V_2 ) ;
#ifdef F_36
V_60 = F_25 ( V_2 ) ;
F_37 ( V_2 -> V_7 ) ;
#else
F_37 ( V_2 -> V_7 ) ;
V_60 = F_25 ( V_2 ) ;
#endif
return V_60 ;
}
int F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_7 ) ;
return F_23 ( V_2 ) ;
}
static void F_40 ( void * V_61 , struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
F_22 ( V_62 , ( L_7 , ( unsigned long ) V_2 ) ) ;
if ( V_4 -> V_63 ) {
F_22 ( V_59 ,
( L_8 , V_4 -> V_63 ) ) ;
}
F_1 ( V_2 , V_4 ) ;
F_22 ( V_62 , ( L_9 ) ) ;
}
static int F_41 ( struct V_1 * V_2 , bool V_64 , bool V_65 )
{
int V_11 = 0 ;
struct V_3 * V_23 = NULL ;
F_22 ( V_32 , ( L_10 ,
V_64 , V_65 ) ) ;
do {
if ( V_65 ) {
V_23 = F_5 ( V_2 ) ;
if ( NULL == V_23 ) {
V_11 = V_66 ;
F_20 ( false ) ;
break;
}
V_23 -> V_67 = F_40 ;
V_23 -> V_68 = V_2 ;
V_11 = V_2 -> V_46 ( V_2 -> V_7 ,
V_64 ? V_69 : V_70 ,
V_23 ) ;
break;
}
V_11 = V_2 -> V_46 ( V_2 -> V_7 ,
V_64 ? V_69 : V_70 ,
NULL ) ;
} while ( false );
if ( V_11 && ( V_23 != NULL ) ) {
F_1 ( V_2 , V_23 ) ;
}
return V_11 ;
}
static int F_42 ( struct V_1 * V_2 , bool V_64 , bool V_65 )
{
int V_11 = 0 ;
struct V_3 * V_23 = NULL ;
struct V_48 V_49 ;
F_2 ( V_2 ) ;
if ( V_64 ) {
V_2 -> V_50 . V_51 |= F_29 ( 0x01 ) ;
} else {
V_2 -> V_50 . V_51 &= ~ F_29 ( 0x01 ) ;
}
memcpy ( & V_49 , & V_2 -> V_50 , V_56 ) ;
F_4 ( V_2 ) ;
do {
if ( V_65 ) {
V_23 = F_5 ( V_2 ) ;
if ( NULL == V_23 ) {
V_11 = V_66 ;
F_20 ( false ) ;
break;
}
memcpy ( V_23 -> V_71 , & V_49 , V_56 ) ;
V_23 -> V_67 = F_40 ;
V_23 -> V_68 = V_2 ;
F_34 ( V_2 -> V_7 ,
V_57 ,
V_23 -> V_71 ,
V_56 ,
V_72 ,
V_23 ) ;
break;
}
V_11 = F_34 ( V_2 -> V_7 ,
V_57 ,
& V_49 . V_51 ,
V_56 ,
V_58 ,
NULL ) ;
} while ( false );
if ( V_11 && ( V_23 != NULL ) ) {
F_1 ( V_2 , V_23 ) ;
}
return V_11 ;
}
int F_43 ( struct V_1 * V_2 , bool V_65 )
{
if ( NULL == V_2 -> V_46 ) {
return F_42 ( V_2 , false , V_65 ) ;
} else {
return F_41 ( V_2 , false , V_65 ) ;
}
}
int F_44 ( struct V_1 * V_2 , bool V_65 )
{
if ( NULL == V_2 -> V_46 ) {
return F_42 ( V_2 , true , V_65 ) ;
} else {
return F_41 ( V_2 , true , V_65 ) ;
}
}
int F_45 ( struct V_1 * V_2 , T_1 V_73 , bool * V_74 )
{
int V_11 = 0 ;
T_3 V_75 = 0x0 ;
T_1 V_76 = 0x0 ;
if( V_73 < 100 )
{
V_73 = 100 ;
}
V_76 = V_73 / 100 ;
do
{
V_11 = F_34 ( V_2 -> V_7 ,
V_77 ,
& V_75 ,
sizeof( T_3 ) ,
V_78 ,
NULL ) ;
if ( V_11 )
{
F_22 ( V_79 , ( L_11 , V_11 ) ) ;
break;
}
V_75 = ! V_11 ? ( V_75 & ( 1 << 0 ) ) : 0 ;
if( ! V_75 )
{
V_11 = 0 ;
* V_74 = false ;
break;
}
else
{
* V_74 = true ;
}
F_46 ( 100 ) ;
V_76 -- ;
}while( V_76 );
return V_11 ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_48 * V_82 )
{
F_22 ( V_83 , ( L_12 ) ) ;
if ( V_81 != NULL ) {
F_22 ( V_83 ,
( L_13 , V_81 -> V_75 ) ) ;
F_22 ( V_83 ,
( L_14 , V_81 -> V_84 ) ) ;
F_22 ( V_83 ,
( L_15 , V_81 -> V_85 ) ) ;
F_22 ( V_83 ,
( L_16 , V_81 -> V_86 ) ) ;
F_22 ( V_83 ,
( L_17 , V_81 -> V_87 ) ) ;
F_22 ( V_83 ,
( L_18 , V_81 -> V_88 ) ) ;
F_22 ( V_83 ,
( L_19 , V_81 -> V_89 [ 0 ] ) ) ;
F_22 ( V_83 ,
( L_20 , V_81 -> V_89 [ 1 ] ) ) ;
if ( V_2 -> V_21 . V_90 != 0 ) {
F_22 ( V_83 ,
( L_21 , V_81 -> V_91 ) ) ;
F_22 ( V_83 ,
( L_22 , V_81 -> V_92 ) ) ;
F_22 ( V_83 ,
( L_23 , V_81 -> V_93 [ 0 ] ) ) ;
F_22 ( V_83 ,
( L_24 , V_81 -> V_93 [ 1 ] ) ) ;
}
}
if ( V_82 != NULL ) {
F_22 ( V_83 ,
( L_25 , V_82 -> V_51 ) ) ;
F_22 ( V_83 ,
( L_26 , V_82 -> V_54 ) ) ;
}
F_22 ( V_83 , ( L_27 ) ) ;
}
static struct V_94 * F_48 ( struct V_95 * V_61 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
F_2 ( V_2 ) ;
V_97 = F_49 ( & V_2 -> V_14 ) ;
F_4 ( V_2 ) ;
if ( V_97 != NULL ) {
return F_50 ( V_97 , struct V_94 , V_98 ) ;
}
return NULL ;
}
static void F_51 ( struct V_95 * V_61 , struct V_94 * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
F_2 ( V_2 ) ;
F_52 ( & V_2 -> V_14 , & V_99 -> V_98 ) ;
F_4 ( V_2 ) ;
}
int F_53 ( struct V_94 * V_99 , bool V_100 )
{
T_3 * V_101 = NULL ;
int V_12 , V_102 ;
T_1 V_103 ;
V_101 = V_99 -> V_104 ;
if ( V_101 == NULL ) {
F_20 ( false ) ;
return V_105 ;
}
V_102 = ( int ) V_99 -> V_106 ;
for ( V_12 = 0 ; V_12 < V_99 -> V_107 ; V_12 ++ ) {
V_103 = F_54 ( ( int ) V_99 -> V_108 [ V_12 ] . V_109 , V_102 ) ;
if ( V_103 != ( int ) V_99 -> V_108 [ V_12 ] . V_109 ) {
F_20 ( false ) ;
return V_105 ;
}
if ( V_100 ) {
memcpy ( V_99 -> V_108 [ V_12 ] . V_71 , V_101 , V_103 ) ;
} else {
memcpy ( V_101 , V_99 -> V_108 [ V_12 ] . V_71 , V_103 ) ;
}
V_101 += V_103 ;
V_102 -= V_103 ;
}
return 0 ;
}
static void F_55 ( void * V_61 , struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
struct V_94 * V_99 = (struct V_94 * ) V_4 -> V_110 ;
F_22 ( V_111 , ( L_28 , ( unsigned long ) V_2 ) ) ;
V_99 -> V_112 = V_4 -> V_63 ;
F_1 ( V_2 , V_4 ) ;
V_99 -> V_113 ( V_99 ) ;
F_22 ( V_111 , ( L_29 ) ) ;
}
static int F_56 ( struct V_95 * V_61 , struct V_94 * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
int V_11 = 0 ;
struct V_3 * V_23 = NULL ;
T_1 V_114 = V_99 -> V_115 ;
do {
if ( V_99 -> V_106 > V_116 ) {
F_22 ( V_59 ,
( L_30 , V_99 -> V_106 ) ) ;
break;
}
if ( V_99 -> V_106 == 0 ) {
F_20 ( false ) ;
break;
}
if ( V_114 & V_117 ) {
V_23 = F_5 ( V_2 ) ;
if ( NULL == V_23 ) {
V_11 = V_66 ;
break;
}
V_23 -> V_110 = V_99 ;
V_23 -> V_67 = F_55 ;
V_23 -> V_68 = V_2 ;
}
if ( V_114 & V_118 ) {
if ( V_99 -> V_119 == V_2 -> V_21 . V_120 [ V_34 ] . V_121 ) {
V_99 -> V_119 += V_2 -> V_21 . V_120 [ V_34 ] . V_122 - V_99 -> V_106 ;
}
}
V_11 = F_34 ( V_2 -> V_7 ,
V_99 -> V_119 ,
F_57 ( V_99 ) -> V_123 ,
V_99 -> V_106 ,
V_114 ,
( V_114 & V_117 ) ? V_23 : NULL ) ;
} while ( false );
if ( ( V_11 != V_124 ) && V_11 && ( V_114 & V_117 ) ) {
if ( V_23 != NULL ) {
F_1 ( V_2 , V_23 ) ;
}
V_99 -> V_112 = V_11 ;
V_99 -> V_113 ( V_99 ) ;
V_11 = 0 ;
}
return V_11 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_94 * V_99 ;
while ( 1 ) {
V_99 = F_48 ( (struct V_95 * ) V_2 ) ;
if ( NULL == V_99 ) {
break;
}
F_58 ( V_99 ) ;
}
}
static int F_59 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
int V_125 , V_126 ;
int V_12 ;
struct V_127 * V_128 ;
struct V_94 * V_99 ;
V_125 = sizeof( struct V_127 ) +
2 * ( F_60 () ) + V_116 ;
V_126 = sizeof( struct V_94 ) +
( V_129 - 1 ) * ( sizeof( struct V_130 ) ) ;
for ( V_12 = 0 ; V_12 < V_131 ; V_12 ++ ) {
V_99 = (struct V_94 * ) F_61 ( V_126 + V_125 ) ;
if ( NULL == V_99 ) {
V_11 = V_66 ;
break;
}
F_17 ( V_99 , V_126 ) ;
V_128 = (struct V_127 * ) ( ( T_3 * ) V_99 + V_126 ) ;
F_17 ( V_128 , sizeof( struct V_127 ) ) ;
V_128 -> V_123 = & V_128 -> V_132 [ 0 ] ;
V_128 -> V_123 = F_62 ( V_128 -> V_123 ) ;
V_99 -> V_133 [ 0 ] = V_128 ;
V_99 -> V_134 = V_135 ;
V_99 -> V_104 = V_128 -> V_123 ;
F_51 ( (struct V_95 * ) V_2 , V_99 ) ;
}
if ( V_11 ) {
F_10 ( V_2 ) ;
} else {
V_2 -> V_136 . V_137 = F_48 ;
V_2 -> V_136 . V_138 = F_51 ;
V_2 -> V_136 . V_139 = F_56 ;
if ( V_2 -> V_21 . V_140 == V_141 ) {
F_22 ( V_41 , ( L_31 ) ) ;
V_2 -> V_136 . V_142 = V_143 ;
V_2 -> V_136 . V_144 = V_145 ;
} else {
V_2 -> V_136 . V_142 = V_129 ;
V_2 -> V_136 . V_144 = V_116 ;
}
V_2 -> V_146 = true ;
}
return V_11 ;
}
int F_63 ( struct V_1 * V_2 )
{
if( NULL != V_2 )
{
F_10 ( V_2 ) ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 , int V_147 )
{
int V_11 ;
if ( V_2 -> V_21 . V_148 & V_149 ) {
F_22 ( V_41 , ( L_32 ) ) ;
return V_150 ;
}
V_11 = F_19 ( V_2 -> V_7 ,
V_151 ,
& V_2 -> V_136 ,
sizeof( V_2 -> V_136 ) ) ;
if ( V_11 ) {
F_22 ( V_41 ,
( L_33 , V_11 ) ) ;
V_11 = F_59 ( V_2 ) ;
if ( ! V_11 ) {
F_22 ( V_83 ,
( L_34 ,
F_65 ( V_2 ) , F_66 ( V_2 ) ) ) ;
}
} else {
F_22 ( V_83 ,
( L_35 ,
F_65 ( V_2 ) , F_66 ( V_2 ) ) ) ;
}
if ( ! V_11 ) {
V_2 -> V_152 = V_2 -> V_136 . V_144 ;
if ( V_2 -> V_21 . V_140 == V_141 ) {
F_22 ( V_41 , ( L_36 ) ) ;
V_2 -> V_153 = 0 ;
} else {
if ( V_2 -> V_21 . V_120 [ 0 ] . V_121 != 0 ) {
V_2 -> V_153 = V_2 -> V_21 . V_120 [ 0 ] . V_122 ;
} else {
V_2 -> V_153 = V_154 ;
}
if ( V_2 -> V_153 > V_2 -> V_136 . V_144 ) {
V_2 -> V_153 = V_2 -> V_136 . V_144 ;
}
}
F_22 ( V_83 ,
( L_37 ,
F_67 ( V_2 ) , F_68 ( V_2 ) ) ) ;
}
return V_11 ;
}
int F_69 ( struct V_1 * V_2 , struct V_94 * V_155 , bool V_156 , bool V_157 )
{
int V_11 ;
if ( V_156 ) {
V_155 -> V_115 = ( V_157 ) ? V_158 : V_159 ;
V_155 -> V_119 = V_2 -> V_21 . V_33 [ V_34 ] ;
F_20 ( V_155 -> V_106 <= ( T_1 ) F_67 ( V_2 ) ) ;
} else {
T_1 V_160 ;
V_155 -> V_115 = ( V_157 ) ? V_161 : V_162 ;
F_20 ( V_155 -> V_106 <= ( T_1 ) F_68 ( V_2 ) ) ;
if ( V_155 -> V_106 > V_154 ) {
V_155 -> V_119 = V_2 -> V_21 . V_120 [ V_34 ] . V_121 ;
V_160 = V_2 -> V_21 . V_120 [ V_34 ] . V_122 ;
} else {
V_155 -> V_119 = V_2 -> V_21 . V_33 [ V_34 ] ;
V_160 = V_154 ;
}
if ( ! V_2 -> V_146 ) {
V_155 -> V_119 += ( V_160 - V_155 -> V_106 ) ;
}
}
F_22 ( V_111 | V_163 ,
( L_38 ,
V_155 -> V_107 ,
V_155 -> V_106 ,
V_155 -> V_119 ,
V_157 ? L_39 : L_40 ,
( V_156 ) ? L_41 : L_42 ) ) ;
V_11 = F_70 ( V_155 ) ;
if ( V_11 ) {
if ( V_157 ) {
V_155 -> V_112 = V_11 ;
V_155 -> V_113 ( V_155 ) ;
return 0 ;
}
return V_11 ;
}
V_11 = V_2 -> V_136 . V_139 ( V_2 -> V_146 ? V_2 : V_2 -> V_7 ,
V_155 ) ;
if ( ! V_157 ) {
V_155 -> V_112 = V_11 ;
F_71 ( V_155 ) ;
} else {
if ( V_11 == V_124 ) {
V_11 = 0 ;
}
}
return V_11 ;
}
static void F_72 ( struct V_164 * V_165 )
{
T_3 * V_71 = V_166 ;
#if V_167 < 4
#error "Buffer processing list depth is not deep enough!!"
#endif
F_73 ( V_165 , V_168 , V_71 ) ;
F_73 ( V_165 , V_169 , V_71 ) ;
F_73 ( V_165 , V_170 , V_71 ) ;
F_73 ( V_165 , V_171 , V_71 ) ;
}
static void F_74 ( bool V_172 )
{
T_4 * V_173 = ( T_4 * ) V_166 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < ( V_174 / 2 ) ; V_12 ++ ) {
if ( ! V_172 ) {
V_173 [ V_12 ] = ( T_4 ) V_12 ;
} else {
V_173 [ V_12 ] = 0 ;
}
}
}
static bool F_75 ( T_4 * V_173 , int V_109 )
{
int V_12 ;
T_4 V_175 ;
bool V_176 = true ;
V_175 = V_173 [ 0 ] ;
V_175 = ~ V_175 ;
for ( V_12 = 0 ; V_12 < ( V_109 / 2 ) ; V_12 ++ , V_175 ++ ) {
if ( ( T_4 ) V_173 [ V_12 ] != ( T_4 ) ~ V_175 ) {
V_176 = false ;
F_22 ( V_59 , ( L_43 ,
V_173 [ V_12 ] , ( ( T_4 ) ~ V_175 ) , V_12 , V_109 ) ) ;
F_22 ( V_59 , ( L_44 ,
V_173 [ V_12 ] , V_173 [ V_12 + 1 ] , V_173 [ V_12 + 2 ] , V_173 [ V_12 + 3 ] ) ) ;
break;
}
}
return V_176 ;
}
static bool F_76 ( void )
{
int V_12 ;
bool V_176 = true ;
struct V_164 V_177 [ V_167 ] ;
F_72 ( V_177 ) ;
for ( V_12 = 0 ; V_12 < V_167 ; V_12 ++ ) {
V_176 = F_75 ( ( T_4 * ) V_177 [ V_12 ] . V_71 , V_177 [ V_12 ] . V_103 ) ;
if ( ! V_176 ) {
F_22 ( V_59 , ( L_45 ,
( T_1 ) V_177 [ V_12 ] . V_71 , V_177 [ V_12 ] . V_103 ) ) ;
break;
}
}
return V_176 ;
}
static T_4 F_77 ( void )
{
T_3 * V_71 ;
struct V_164 V_177 [ V_167 ] ;
F_74 ( V_178 ) ;
F_72 ( V_177 ) ;
V_71 = & ( V_177 [ V_167 - 1 ] . V_71 [ ( V_177 [ V_167 - 1 ] . V_103 ) - 2 ] ) ;
return ( T_4 ) V_71 [ 0 ] | ( ( T_4 ) V_71 [ 1 ] << 8 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_179 )
{
int V_11 = 0 ;
T_1 V_114 = V_162 ;
struct V_164 V_180 [ V_167 ] ;
int V_12 ;
int V_181 = 0 ;
int V_182 ;
int V_183 = 0 ;
F_22 ( V_184 , ( L_46 , V_179 ) ) ;
F_74 ( V_178 ) ;
F_72 ( V_180 ) ;
for ( V_12 = 0 ; V_12 < V_167 ; V_12 ++ ) {
V_182 = ( V_180 [ V_12 ] . V_103 + ( V_185 [ V_179 ] - 1 ) ) &
( ~ ( V_185 [ V_179 ] - 1 ) ) ;
V_11 = F_34 ( V_2 -> V_7 ,
V_186 [ V_179 ] ,
V_180 [ V_12 ] . V_71 ,
V_182 ,
V_114 ,
NULL ) ;
if ( V_11 ) {
break;
}
V_181 += V_180 [ V_12 ] . V_103 ;
V_183 += V_182 ;
}
F_22 ( V_184 , ( L_47 , V_181 , V_183 , V_179 ) ) ;
return V_11 ;
}
static int F_79 ( struct V_1 * V_2 , int V_179 , int * V_187 )
{
int V_11 = 0 ;
int V_188 = V_189 ;
T_3 V_190 = 0 ;
T_1 V_191 ;
while ( true ) {
V_191 = V_192 + ( V_10 + V_179 ) * 4 ;
V_11 = F_34 ( V_2 -> V_7 , V_191 , & V_190 , sizeof( V_190 ) ,
V_193 , NULL ) ;
if ( V_11 ) {
F_22 ( V_59 ,
( L_48 , V_179 ) ) ;
V_11 = V_194 ;
break;
}
if ( V_190 ) {
break;
}
V_188 -- ;
if ( V_188 <= 0 ) {
F_22 ( V_59 ,
( L_49 , V_179 , V_191 ) ) ;
V_11 = V_194 ;
break;
}
F_46 ( 1000 ) ;
}
if ( V_11 == 0 ) {
* V_187 = V_190 ;
}
return V_11 ;
}
static int F_80 ( struct V_1 * V_2 , int V_179 )
{
int V_11 = 0 ;
T_1 V_114 = V_195 ;
struct V_164 V_196 [ V_167 ] ;
int V_197 ;
int V_190 ;
int V_12 ;
int V_181 = 0 ;
int V_182 ;
int V_183 = 0 ;
F_22 ( V_184 , ( L_50 , V_179 ) ) ;
F_74 ( V_198 ) ;
F_72 ( V_196 ) ;
V_197 = 0 ;
while ( V_197 < V_167 ) {
V_11 = F_79 ( V_2 , V_179 , & V_190 ) ;
if ( V_11 ) {
break;
}
F_22 ( V_184 , ( L_51 , V_190 , V_179 ) ) ;
for ( V_12 = 0 ; V_12 < V_190 ; V_12 ++ ) {
F_20 ( V_197 < V_167 ) ;
V_182 = ( V_196 [ V_197 ] . V_103 + ( V_185 [ V_179 ] - 1 ) ) &
( ~ ( V_185 [ V_179 ] - 1 ) ) ;
V_11 = F_34 ( V_2 -> V_7 ,
V_186 [ V_179 ] ,
V_196 [ V_197 ] . V_71 ,
V_182 ,
V_114 ,
NULL ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_52 ,
V_196 [ V_197 ] . V_103 , V_179 , V_186 [ V_179 ] ) ) ;
break;
}
V_183 += V_182 ;
V_181 += V_196 [ V_197 ] . V_103 ;
V_197 ++ ;
}
if ( V_11 ) {
break;
}
V_190 = 0 ;
}
if ( V_181 != V_199 ) {
F_20 ( false ) ;
} else {
F_22 ( V_184 , ( L_53 ,
V_179 , V_181 , V_183 ) ) ;
}
return V_11 ;
}
static int F_81 ( struct V_1 * V_2 , int V_179 )
{
int V_11 ;
do {
V_11 = F_78 ( V_2 , V_179 ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_54 , V_11 , V_179 ) ) ;
break;
}
V_11 = F_80 ( V_2 , V_179 ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_55 , V_11 , V_179 ) ) ;
break;
}
if ( ! F_76 () ) {
F_22 ( V_59 , ( L_56 , V_179 ) ) ;
V_11 = V_194 ;
break;
}
F_22 ( V_184 , ( L_57 , V_179 ) ) ;
} while ( false );
return V_11 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_12 ;
int V_11 ;
int V_190 = 0 ;
T_3 V_200 [ 4 ] ;
int V_201 ;
int V_125 ;
T_4 V_202 ;
F_22 ( V_184 , ( L_58 ) ) ;
do {
V_11 = F_19 ( V_2 -> V_7 , V_20 ,
V_186 , sizeof( V_186 ) ) ;
if ( V_11 ) {
F_20 ( false ) ;
break;
}
V_11 = F_19 ( V_2 -> V_7 , V_28 ,
V_185 , sizeof( V_185 ) ) ;
if ( V_11 ) {
F_20 ( false ) ;
break;
}
V_185 [ 0 ] = V_185 [ 1 ] ;
F_22 ( V_184 , ( L_59 , V_185 [ 0 ] ) ) ;
if ( V_185 [ 1 ] > V_203 ) {
F_22 ( V_184 , ( L_60 ,
V_185 [ 1 ] , V_203 ) ) ;
break;
}
F_22 ( V_184 , ( L_61 ) ) ;
V_11 = F_79 ( V_2 , 0 , & V_190 ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_62 ) ) ;
break;
}
F_22 ( V_184 , ( L_63 ) ) ;
V_11 = F_34 ( V_2 -> V_7 ,
V_204 ,
V_200 ,
4 ,
V_78 ,
NULL ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_64 ) ) ;
break;
}
V_201 = V_200 [ 0 ] ;
V_125 = ( int ) ( ( ( T_4 ) V_200 [ 2 ] << 8 ) | ( T_4 ) V_200 [ 1 ] ) ;
F_22 ( V_184 ,
( L_65 ,
V_201 , V_125 , ( V_201 * V_125 ) , V_174 ) ) ;
if ( ( V_201 * V_125 ) < V_174 ) {
F_22 ( V_59 , ( L_66 ,
V_174 , ( V_201 * V_125 ) ) ) ;
V_11 = V_194 ;
break;
}
V_202 = F_77 () ;
V_11 = F_34 ( V_2 -> V_7 ,
V_204 + 4 ,
( T_3 * ) & V_202 ,
2 ,
V_58 ,
NULL ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_67 ) ) ;
break;
}
F_22 ( V_184 , ( L_68 , V_202 ) ) ;
V_202 = ( T_4 ) V_185 [ 1 ] ;
V_202 = V_202 - 1 ;
V_11 = F_34 ( V_2 -> V_7 ,
V_204 + 6 ,
( T_3 * ) & V_202 ,
2 ,
V_58 ,
NULL ) ;
if ( V_11 ) {
F_22 ( V_59 , ( L_69 ) ) ;
break;
}
F_22 ( V_184 , ( L_70 , V_202 ) ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ ) {
V_11 = F_81 ( V_2 , V_12 ) ;
if ( V_11 ) {
break;
}
}
} while ( false );
if ( V_11 == 0 ) {
F_22 ( V_184 , ( L_71 ) ) ;
} else {
F_22 ( V_184 , ( L_72 ) ) ;
}
return V_194 ;
}
