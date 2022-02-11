static inline void F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , unsigned int V_5 ,
struct V_6 * V_7 , T_1 V_8 ,
unsigned char V_9 )
{
unsigned char * V_10 , * V_11 , * V_12 , V_13 ;
unsigned int V_14 = V_7 -> V_15 ;
const unsigned int V_16 = ( V_8 % V_17 ) * V_18 ;
V_10 = V_3 + V_5 + ( V_8 / V_17 ) ;
V_12 = V_3 + V_5 + V_14 ;
F_2 ( V_10 >= V_12 ) ;
V_13 = ( * V_10 >> V_16 ) & V_19 ;
if ( F_3 ( ! V_20 [ V_9 * 4 + V_13 ] ) ) {
F_4 ( V_21 L_1
L_2 ,
( unsigned long long ) V_8 , V_13 , V_9 ) ;
F_4 ( V_21 L_3 ,
( unsigned long long ) V_2 -> V_22 ,
( unsigned long ) V_7 -> V_23 ) ;
F_4 ( V_21 L_4 ,
( unsigned long ) V_7 -> V_24 ,
( unsigned long ) V_7 -> V_15 ) ;
F_5 () ;
F_6 ( V_2 ) ;
return;
}
* V_10 ^= ( V_13 ^ V_9 ) << V_16 ;
if ( V_4 ) {
V_11 = V_4 + V_5 + ( V_8 / V_17 ) ;
V_13 = ( * V_11 >> V_16 ) & V_19 ;
* V_11 ^= ( V_13 ^ V_9 ) << V_16 ;
}
}
static inline unsigned char F_7 ( struct V_1 * V_2 ,
const unsigned char * V_25 ,
unsigned int V_14 , T_1 V_8 )
{
const unsigned char * V_26 , * V_12 ;
unsigned char V_13 ;
unsigned int V_16 ;
V_26 = V_25 + ( V_8 / V_17 ) ;
V_16 = ( V_8 % V_17 ) * V_18 ;
V_12 = V_25 + V_14 ;
F_8 ( V_2 -> V_27 , V_26 < V_12 ) ;
V_13 = ( * V_26 >> V_16 ) & V_19 ;
return V_13 ;
}
static inline T_2 F_9 ( const T_3 * V_28 , T_2 V_29 , T_4 V_30 )
{
T_2 V_31 ;
static const T_2 V_32 [] = {
[ 0 ] = 0xffffffffffffffffULL ,
[ 1 ] = 0xaaaaaaaaaaaaaaaaULL ,
[ 2 ] = 0x5555555555555555ULL ,
[ 3 ] = 0x0000000000000000ULL ,
} ;
V_31 = F_10 ( * V_28 ) ^ V_32 [ V_30 ] ;
V_31 &= ( V_31 >> 1 ) ;
V_31 &= V_29 ;
return V_31 ;
}
static T_1 F_11 ( const T_4 * V_33 , const unsigned int V_34 ,
T_1 V_35 , T_4 V_30 )
{
T_1 V_36 = ( V_35 << 1 ) & ( ( 8 * sizeof( T_2 ) ) - 1 ) ;
const T_3 * V_28 = ( ( T_3 * ) V_33 ) + ( V_35 >> 5 ) ;
const T_3 * V_12 = ( T_3 * ) ( V_33 + F_12 ( V_34 , sizeof( T_2 ) ) ) ;
T_2 V_31 ;
T_2 V_29 = 0x5555555555555555ULL ;
T_1 V_16 ;
F_2 ( V_30 > 3 ) ;
V_29 <<= V_36 ;
V_31 = F_9 ( V_28 , V_29 , V_30 ) ;
V_28 ++ ;
while( V_31 == 0 && V_28 < V_12 ) {
V_31 = F_9 ( V_28 , 0x5555555555555555ULL , V_30 ) ;
V_28 ++ ;
}
if ( V_28 == V_12 && ( V_34 & ( sizeof( T_2 ) - 1 ) ) )
V_31 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_34 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_31 == 0 )
return V_37 ;
V_28 -- ;
V_16 = F_13 ( V_31 ) ;
V_16 /= 2 ;
return ( ( ( const unsigned char * ) V_28 - V_33 ) * V_17 ) + V_16 ;
}
static T_1 F_14 ( struct V_1 * V_2 , const T_4 * V_25 ,
unsigned int V_14 , T_4 V_30 )
{
const T_4 * V_26 = V_25 ;
const T_4 * V_12 = V_25 + V_14 ;
const T_4 V_38 = V_30 << 2 ;
const T_4 V_39 = V_30 << 4 ;
const T_4 V_40 = V_30 << 6 ;
T_1 V_41 = 0 ;
for (; V_26 < V_12 ; V_26 ++ ) {
if ( ( ( * V_26 ) & 0x03 ) == V_30 )
V_41 ++ ;
if ( ( ( * V_26 ) & 0x0C ) == V_38 )
V_41 ++ ;
if ( ( ( * V_26 ) & 0x30 ) == V_39 )
V_41 ++ ;
if ( ( ( * V_26 ) & 0xC0 ) == V_40 )
V_41 ++ ;
}
return V_41 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_6 * V_7 = NULL ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_41 [ 4 ] , V_31 ;
int V_33 , V_46 ;
memset ( V_41 , 0 , 4 * sizeof( T_1 ) ) ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ )
V_41 [ V_46 ] += F_14 ( V_2 ,
V_7 -> V_48 -> V_49 +
V_7 -> V_24 ,
V_7 -> V_15 , V_46 ) ;
}
if ( V_41 [ 0 ] != V_2 -> V_50 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_5 ,
V_41 [ 0 ] , V_2 -> V_50 ) ;
return;
}
V_31 = V_2 -> V_51 - V_2 -> V_50 - V_2 -> V_52 ;
if ( V_41 [ 1 ] != V_31 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_6 ,
V_41 [ 1 ] , V_31 ) ;
return;
}
if ( V_41 [ 2 ] + V_41 [ 3 ] != V_2 -> V_52 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_7 ,
V_41 [ 2 ] + V_41 [ 3 ] , V_2 -> V_52 ) ;
return;
}
}
static inline int F_17 ( struct V_1 * V_2 , T_2 V_8 )
{
T_2 V_53 = V_2 -> V_54 ;
T_2 V_55 = V_53 + V_2 -> V_51 ;
return V_53 <= V_8 && V_8 < V_55 ;
}
struct V_1 * F_18 ( struct V_42 * V_43 , T_2 V_56 )
{
struct V_57 * * V_58 ;
struct V_1 * V_59 ;
F_19 ( & V_43 -> V_60 ) ;
V_58 = & V_43 -> V_61 . V_57 ;
while ( * V_58 ) {
V_59 = F_20 ( * V_58 , struct V_1 , V_62 ) ;
if ( V_56 < V_59 -> V_22 )
V_58 = & ( ( * V_58 ) -> V_63 ) ;
else if ( V_56 >= V_59 -> V_54 + V_59 -> V_51 )
V_58 = & ( ( * V_58 ) -> V_64 ) ;
else {
F_21 ( & V_43 -> V_60 ) ;
return V_59 ;
}
}
F_21 ( & V_43 -> V_60 ) ;
return NULL ;
}
struct V_1 * F_22 ( struct V_42 * V_43 )
{
const struct V_57 * V_65 ;
struct V_1 * V_2 ;
F_19 ( & V_43 -> V_60 ) ;
V_65 = F_23 ( & V_43 -> V_61 ) ;
V_2 = F_20 ( V_65 , struct V_1 , V_62 ) ;
F_21 ( & V_43 -> V_60 ) ;
return V_2 ;
}
struct V_1 * F_24 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
const struct V_57 * V_65 ;
F_19 ( & V_43 -> V_60 ) ;
V_65 = F_25 ( & V_2 -> V_62 ) ;
if ( V_65 == NULL )
V_65 = F_23 ( & V_43 -> V_61 ) ;
if ( F_3 ( & V_2 -> V_62 == V_65 ) ) {
F_21 ( & V_43 -> V_60 ) ;
return NULL ;
}
V_2 = F_20 ( V_65 , struct V_1 , V_62 ) ;
F_21 ( & V_43 -> V_60 ) ;
return V_2 ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_45 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
F_27 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
}
void F_28 ( struct V_42 * V_43 )
{
struct V_57 * V_65 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
while ( ( V_65 = F_23 ( & V_43 -> V_61 ) ) ) {
V_2 = F_20 ( V_65 , struct V_1 , V_62 ) ;
V_68 = V_2 -> V_69 ;
F_29 ( V_65 , & V_43 -> V_61 ) ;
if ( V_68 ) {
F_19 ( & V_68 -> V_70 ) ;
V_68 -> V_71 = NULL ;
F_21 ( & V_68 -> V_70 ) ;
F_30 ( V_68 ) ;
F_31 ( V_68 ) ;
}
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_47 ) ;
F_32 ( V_72 , V_2 ) ;
}
}
static void F_33 ( const struct V_1 * V_2 )
{
F_4 ( V_73 L_8 , ( unsigned long long ) V_2 -> V_22 ) ;
F_4 ( V_73 L_9 , V_2 -> V_45 ) ;
F_4 ( V_73 L_10 , ( unsigned long long ) V_2 -> V_54 ) ;
F_4 ( V_73 L_11 , V_2 -> V_51 ) ;
F_4 ( V_73 L_12 , V_2 -> V_74 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_6 * V_7 ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_75 , V_76 ;
int V_46 ;
if ( ! V_44 )
return - V_77 ;
V_2 -> V_47 = F_35 ( V_44 , sizeof( struct V_6 ) , V_78 ) ;
if ( ! V_2 -> V_47 )
return - V_79 ;
V_75 = V_2 -> V_74 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
V_7 -> V_80 = 0 ;
if ( V_44 == 1 ) {
V_76 = V_75 ;
V_7 -> V_24 = sizeof( struct V_81 ) ;
V_7 -> V_23 = 0 ;
V_7 -> V_15 = V_76 ;
} else if ( V_46 == 0 ) {
V_76 = V_43 -> V_82 . V_83 - sizeof( struct V_81 ) ;
V_7 -> V_24 = sizeof( struct V_81 ) ;
V_7 -> V_23 = 0 ;
V_7 -> V_15 = V_76 ;
} else if ( V_46 + 1 == V_44 ) {
V_76 = V_75 ;
V_7 -> V_24 = sizeof( struct V_84 ) ;
V_7 -> V_23 = V_2 -> V_74 - V_75 ;
V_7 -> V_15 = V_76 ;
} else {
V_76 = V_43 -> V_82 . V_83 -
sizeof( struct V_84 ) ;
V_7 -> V_24 = sizeof( struct V_84 ) ;
V_7 -> V_23 = V_2 -> V_74 - V_75 ;
V_7 -> V_15 = V_76 ;
}
V_75 -= V_76 ;
}
if ( V_75 ) {
F_6 ( V_2 ) ;
return - V_85 ;
}
V_7 = V_2 -> V_47 + ( V_44 - 1 ) ;
if ( ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 != V_2 -> V_51 ) {
if ( F_6 ( V_2 ) ) {
F_33 ( V_2 ) ;
F_16 ( V_43 , L_13 ,
V_7 -> V_23 , V_7 -> V_15 , V_7 -> V_24 ) ;
}
return - V_85 ;
}
return 0 ;
}
T_2 F_36 ( struct V_42 * V_43 )
{
T_2 V_86 = 0 ;
struct V_87 * V_87 = V_43 -> V_88 ;
struct V_89 * V_90 = F_37 ( V_87 ) ;
char V_33 [ sizeof( struct V_91 ) ] ;
struct V_92 V_93 ;
int error , V_94 ;
F_38 ( & V_43 -> V_95 ) ;
F_39 ( & V_93 , V_87 -> V_96 ) ;
for ( V_94 = 0 ; ; V_94 ++ ) {
T_5 V_97 = V_94 * sizeof( struct V_91 ) ;
if ( V_97 + sizeof( struct V_91 ) > F_40 ( V_87 ) )
break;
error = F_41 ( V_90 , & V_93 , V_33 , & V_97 ,
sizeof( struct V_91 ) ) ;
if ( error != sizeof( struct V_91 ) )
break;
V_86 += F_42 ( ( (struct V_91 * ) V_33 ) -> V_98 ) ;
}
F_43 ( & V_43 -> V_95 ) ;
return V_86 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_57 * * V_58 = & V_43 -> V_61 . V_57 , * V_99 = NULL ;
while ( * V_58 ) {
struct V_1 * V_59 = F_20 ( * V_58 , struct V_1 ,
V_62 ) ;
V_99 = * V_58 ;
if ( V_2 -> V_22 < V_59 -> V_22 )
V_58 = & ( ( * V_58 ) -> V_63 ) ;
else if ( V_2 -> V_22 > V_59 -> V_22 )
V_58 = & ( ( * V_58 ) -> V_64 ) ;
else
return;
}
F_45 ( & V_2 -> V_62 , V_99 , V_58 ) ;
F_46 ( & V_2 -> V_62 , & V_43 -> V_61 ) ;
}
static int F_47 ( struct V_89 * V_90 ,
struct V_92 * V_93 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
T_5 V_97 = V_43 -> V_101 * sizeof( struct V_91 ) ;
struct V_91 V_33 ;
int error ;
struct V_1 * V_2 ;
if ( V_97 >= F_40 ( & V_90 -> V_100 ) )
return 1 ;
error = F_41 ( V_90 , V_93 , ( char * ) & V_33 , & V_97 ,
sizeof( struct V_91 ) ) ;
if ( error != sizeof( struct V_91 ) )
return ( error == 0 ) ? 1 : error ;
V_2 = F_49 ( V_72 , V_78 ) ;
error = - V_79 ;
if ( ! V_2 )
return error ;
V_2 -> V_27 = V_43 ;
V_2 -> V_22 = F_50 ( V_33 . V_102 ) ;
V_2 -> V_45 = F_42 ( V_33 . V_103 ) ;
V_2 -> V_54 = F_50 ( V_33 . V_104 ) ;
V_2 -> V_51 = F_42 ( V_33 . V_98 ) ;
V_2 -> V_74 = F_42 ( V_33 . V_105 ) ;
error = F_34 ( V_2 ) ;
if ( error )
goto V_106;
error = F_51 ( V_43 , V_2 -> V_22 ,
& V_107 , V_108 , & V_2 -> V_69 ) ;
if ( error )
goto V_106;
V_2 -> V_69 -> V_71 = V_2 ;
V_2 -> V_109 &= ~ V_110 ;
if ( V_2 -> V_51 > V_43 -> V_111 )
V_43 -> V_111 = V_2 -> V_51 ;
F_19 ( & V_43 -> V_60 ) ;
F_44 ( V_2 ) ;
V_43 -> V_101 ++ ;
F_21 ( & V_43 -> V_60 ) ;
return error ;
V_106:
F_27 ( V_2 -> V_47 ) ;
F_32 ( V_72 , V_2 ) ;
return error ;
}
static int F_52 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
struct V_87 * V_87 = & V_90 -> V_100 ;
struct V_92 V_93 ;
int error ;
F_39 ( & V_93 , V_87 -> V_96 ) ;
do {
error = F_47 ( V_90 , & V_93 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_43 -> V_112 = 1 ;
return 0 ;
}
int F_53 ( struct V_42 * V_43 )
{
struct V_89 * V_90 = F_37 ( V_43 -> V_88 ) ;
struct V_67 * V_68 = V_90 -> V_113 ;
struct V_114 V_115 ;
int error = 0 ;
int V_116 = 0 ;
if ( ! V_43 -> V_112 ) {
F_38 ( & V_43 -> V_95 ) ;
if ( ! F_54 ( V_68 ) ) {
error = F_55 ( V_68 , V_117 , 0 , & V_115 ) ;
if ( error )
return error ;
V_116 = 1 ;
}
if ( ! V_43 -> V_112 )
error = F_52 ( V_90 ) ;
if ( V_116 )
F_56 ( & V_115 ) ;
F_43 ( & V_43 -> V_95 ) ;
}
return error ;
}
static void F_57 ( struct V_1 * V_2 , const void * V_33 )
{
const struct V_81 * V_118 = V_33 ;
T_1 V_119 ;
V_119 = F_42 ( V_118 -> V_119 ) ;
V_119 &= ~ V_120 ;
V_2 -> V_109 &= V_120 ;
V_2 -> V_109 |= V_119 ;
V_2 -> V_50 = F_42 ( V_118 -> V_121 ) ;
V_2 -> V_52 = F_42 ( V_118 -> V_122 ) ;
V_2 -> V_123 = F_50 ( V_118 -> V_124 ) ;
}
static void F_58 ( struct V_1 * V_2 , void * V_33 )
{
struct V_81 * V_118 = V_33 ;
V_118 -> V_119 = F_59 ( V_2 -> V_109 & ~ V_120 ) ;
V_118 -> V_121 = F_59 ( V_2 -> V_50 ) ;
V_118 -> V_122 = F_59 ( V_2 -> V_52 ) ;
V_118 -> V_125 = F_59 ( 0 ) ;
V_118 -> V_124 = F_60 ( V_2 -> V_123 ) ;
memset ( & V_118 -> V_126 , 0 , sizeof( V_118 -> V_126 ) ) ;
}
int F_61 ( struct V_114 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_128 -> V_71 ;
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_67 * V_68 = V_2 -> V_69 ;
unsigned int V_44 = V_2 -> V_45 ;
struct V_6 * V_7 ;
unsigned int V_46 , V_129 ;
int error ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
error = F_62 ( V_68 , V_2 -> V_22 + V_46 , 0 , & V_7 -> V_48 ) ;
if ( error )
goto V_106;
}
for ( V_129 = V_44 ; V_129 -- ; ) {
V_7 = V_2 -> V_47 + V_129 ;
error = F_63 ( V_43 , V_7 -> V_48 ) ;
if ( error )
goto V_106;
if ( F_64 ( V_43 , V_7 -> V_48 , V_129 ? V_130 :
V_131 ) ) {
error = - V_85 ;
goto V_106;
}
}
if ( ! ( V_2 -> V_109 & V_110 ) ) {
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ )
F_65 ( V_132 , & V_2 -> V_47 [ V_46 ] . V_80 ) ;
F_57 ( V_2 , ( V_2 -> V_47 [ 0 ] . V_48 ) -> V_49 ) ;
V_2 -> V_109 |= ( V_110 | V_133 ) ;
V_2 -> V_134 = V_2 -> V_50 ;
}
return 0 ;
V_106:
while ( V_46 -- ) {
V_7 = V_2 -> V_47 + V_46 ;
F_66 ( V_7 -> V_48 ) ;
V_7 -> V_48 = NULL ;
F_67 ( V_43 , ! V_7 -> V_66 ) ;
}
return error ;
}
void F_68 ( struct V_114 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_128 -> V_71 ;
int V_46 , V_44 = V_2 -> V_45 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
F_66 ( V_7 -> V_48 ) ;
V_7 -> V_48 = NULL ;
}
}
void F_69 ( struct V_42 * V_43 , T_2 V_5 ,
struct V_135 * V_136 ,
const struct V_6 * V_7 )
{
struct V_137 * V_138 = V_43 -> V_139 ;
struct V_140 * V_141 = V_138 -> V_142 ;
const unsigned int V_143 = V_43 -> V_82 . V_83 /
F_70 ( V_138 -> V_142 ) ;
T_2 V_56 ;
T_6 V_144 = 0 ;
T_6 V_145 = 0 ;
int V_146 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_15 ; V_46 ++ ) {
const T_4 * V_147 = V_136 -> V_49 + V_7 -> V_24 + V_46 ;
const T_4 * V_148 = V_7 -> V_66 + V_7 -> V_24 + V_46 ;
T_4 V_149 = ~ ( * V_147 | ( * V_147 >> 1 ) ) & ( * V_148 | ( * V_148 >> 1 ) ) ;
V_149 &= 0x55 ;
if ( V_149 == 0 )
continue;
V_56 = V_5 + ( ( V_7 -> V_23 + V_46 ) * V_17 ) ;
V_56 *= V_143 ;
while( V_149 ) {
if ( V_149 & 1 ) {
if ( V_145 == 0 )
goto V_150;
if ( ( V_144 + V_145 ) != V_56 ) {
V_146 = F_71 ( V_141 , V_144 ,
V_145 , V_78 ,
0 ) ;
if ( V_146 )
goto V_106;
V_145 = 0 ;
V_150:
V_144 = V_56 ;
}
V_145 += V_143 ;
}
V_149 >>= 2 ;
V_56 += V_143 ;
}
}
if ( V_145 ) {
V_146 = F_71 ( V_141 , V_144 , V_145 , V_78 , 0 ) ;
if ( V_146 )
goto V_106;
}
return;
V_106:
F_72 ( V_43 , L_14 , V_146 ) ;
V_43 -> V_151 . V_152 = 0 ;
}
struct V_153 * F_73 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
int error ;
F_2 ( V_90 -> V_154 != NULL ) ;
V_90 -> V_154 = F_74 ( sizeof( struct V_153 ) , V_78 ) ;
error = F_53 ( V_43 ) ;
if ( error )
F_72 ( V_43 , L_15 , error ) ;
return V_90 -> V_154 ;
}
static struct V_155 * F_75 ( struct V_89 * V_90 )
{
F_2 ( V_90 -> V_156 != NULL ) ;
V_90 -> V_156 = F_74 ( sizeof( struct V_155 ) , V_78 ) ;
return V_90 -> V_156 ;
}
static int F_76 ( const struct V_1 * V_2 , const struct V_89 * V_90 )
{
const struct V_155 * V_157 = V_90 -> V_156 ;
if ( V_2 -> V_109 & ( V_158 | V_159 ) )
return 0 ;
if ( V_2 -> V_134 >= V_157 -> V_160 )
return 1 ;
return 0 ;
}
static inline T_1 F_77 ( struct V_6 * V_7 , T_1 V_56 )
{
return ( V_7 -> V_23 * V_17 ) + V_56 ;
}
static void F_78 ( struct V_1 * V_2 , T_2 * V_161 , T_2 V_162 )
{
T_1 V_35 = 0 , V_8 ;
T_2 V_163 ;
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_67 * V_68 ;
struct V_89 * V_90 ;
int error ;
int V_164 = 0 ;
struct V_6 * V_7 ;
while ( V_35 < V_2 -> V_51 ) {
F_79 ( & V_43 -> V_165 ) ;
V_8 = F_80 ( V_2 , V_35 , V_166 , & V_7 ) ;
F_81 ( & V_43 -> V_165 ) ;
if ( V_8 == V_37 )
break;
V_8 = F_77 ( V_7 , V_8 ) ;
V_163 = V_8 + V_2 -> V_54 ;
V_35 = F_82 ( V_8 + 1 , V_35 + 1 ) ;
if ( * V_161 != V_167 && V_163 <= * V_161 )
continue;
if ( V_163 == V_162 )
continue;
* V_161 = V_163 ;
error = F_51 ( V_43 , V_163 , & V_168 , V_108 , & V_68 ) ;
if ( error )
continue;
V_90 = V_68 -> V_71 ;
if ( V_90 || F_83 ( V_169 , & V_68 -> V_170 ) == 0 )
F_31 ( V_68 ) ;
else
V_164 ++ ;
if ( V_164 > V_171 )
return;
}
V_2 -> V_109 &= ~ V_133 ;
return;
}
static int F_84 ( struct V_89 * V_90 , T_2 * V_161 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
struct V_1 * V_2 , * V_172 = NULL ;
struct V_155 * V_157 = V_90 -> V_156 ;
int error , V_173 , V_174 = V_175 ;
int V_176 = 0 ;
if ( V_90 -> V_177 && F_17 ( V_90 -> V_177 , V_90 -> V_178 ) )
V_2 = V_172 = V_90 -> V_177 ;
else
V_2 = V_172 = F_18 ( V_43 , V_90 -> V_178 ) ;
if ( V_2 == NULL )
return - V_179 ;
while ( V_176 < 3 ) {
V_173 = 0 ;
if ( F_54 ( V_2 -> V_69 ) ) {
V_173 = 1 ;
error = 0 ;
} else {
error = F_55 ( V_2 -> V_69 , V_180 ,
V_174 , & V_157 -> V_181 ) ;
}
switch ( error ) {
case 0 :
if ( F_76 ( V_2 , V_90 ) ) {
V_90 -> V_177 = V_2 ;
return 0 ;
}
if ( V_2 -> V_109 & V_133 )
F_78 ( V_2 , V_161 , V_90 -> V_182 ) ;
if ( ! V_173 )
F_56 ( & V_157 -> V_181 ) ;
case V_183 :
V_2 = F_24 ( V_2 ) ;
if ( V_2 == V_172 ) {
V_174 = 0 ;
V_176 ++ ;
}
break;
default:
return error ;
}
}
return - V_184 ;
}
static void F_85 ( struct V_89 * V_90 )
{
F_2 ( V_90 -> V_156 == NULL ) ;
F_27 ( V_90 -> V_156 ) ;
V_90 -> V_156 = NULL ;
}
int F_86 ( struct V_89 * V_90 , T_1 V_185 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
struct V_155 * V_157 ;
int error = 0 ;
T_2 V_161 = V_167 ;
int V_186 = 0 ;
V_157 = F_75 ( V_90 ) ;
if ( ! V_157 )
return - V_79 ;
V_157 -> V_160 = V_185 ;
if ( F_67 ( V_43 , V_185 ) ) {
error = - V_77 ;
goto V_187;
}
do {
error = F_84 ( V_90 , & V_161 ) ;
if ( error != - V_184 )
break;
if ( V_90 == F_37 ( V_43 -> V_88 ) && ! V_43 -> V_112 ) {
error = F_52 ( V_90 ) ;
if ( error )
break;
continue;
}
F_87 ( V_43 , NULL ) ;
} while ( V_186 ++ < 3 );
V_187:
if ( error )
F_85 ( V_90 ) ;
return error ;
}
void F_88 ( struct V_89 * V_90 )
{
struct V_155 * V_157 = V_90 -> V_156 ;
if ( V_157 -> V_181 . V_128 )
F_56 ( & V_157 -> V_181 ) ;
F_85 ( V_90 ) ;
}
static unsigned char F_89 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_6 * V_7 = NULL ;
T_1 V_44 , V_188 , V_189 ;
unsigned int V_33 ;
unsigned char type ;
V_44 = V_2 -> V_45 ;
V_188 = V_8 - V_2 -> V_54 ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_188 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_189 = V_188 - V_7 -> V_23 * V_17 ;
type = F_7 ( V_2 , V_7 -> V_48 -> V_49 + V_7 -> V_24 ,
V_7 -> V_15 , V_189 ) ;
return type ;
}
static T_1 F_80 ( struct V_1 * V_2 , T_1 V_35 ,
unsigned char V_30 ,
struct V_6 * * V_190 )
{
struct V_6 * V_7 = NULL ;
const T_1 V_44 = V_2 -> V_45 ;
T_1 V_56 = V_37 ;
unsigned int V_33 , V_46 ;
const T_4 * V_25 = NULL ;
* V_190 = NULL ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_35 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 ) {
V_35 -= V_7 -> V_23 * V_17 ;
goto V_191;
}
}
V_33 = 0 ;
V_35 = 0 ;
V_191:
for ( V_46 = 0 ; V_46 <= V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( F_90 ( V_132 , & V_7 -> V_80 ) &&
( V_30 == V_192 ) )
goto V_162;
V_25 = V_7 -> V_48 -> V_49 + V_7 -> V_24 ;
F_91 ( ! F_92 ( V_7 -> V_48 ) ) ;
if ( V_30 != V_166 && V_7 -> V_66 )
V_25 = V_7 -> V_66 + V_7 -> V_24 ;
V_56 = F_11 ( V_25 , V_7 -> V_15 , V_35 , V_30 ) ;
if ( V_56 != V_37 )
break;
if ( ( V_35 == 0 ) && ( V_30 == V_192 ) )
F_93 ( V_132 , & V_7 -> V_80 ) ;
V_162:
V_33 ++ ;
V_33 %= V_44 ;
V_35 = 0 ;
}
if ( V_56 != V_37 )
* V_190 = V_7 ;
return V_56 ;
}
static T_2 F_94 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_56 , bool V_193 , unsigned int * V_65 )
{
const unsigned int V_194 = * V_65 ;
T_1 V_35 ;
const T_4 * V_25 = NULL ;
* V_65 = 0 ;
V_25 = V_7 -> V_48 -> V_49 + V_7 -> V_24 ;
F_95 ( V_2 -> V_69 , V_7 -> V_48 , 1 ) ;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , V_7 -> V_66 , V_7 -> V_24 ,
V_7 , V_56 , V_193 ? V_195 : V_196 ) ;
( * V_65 ) ++ ;
V_35 = V_56 ;
while ( * V_65 < V_194 ) {
V_35 ++ ;
if ( V_35 >= ( V_7 -> V_15 * V_17 ) )
break;
if ( F_7 ( V_2 , V_25 , V_7 -> V_15 , V_35 ) !=
V_192 )
break;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , V_7 -> V_66 , V_7 -> V_24 ,
V_7 , V_35 , V_196 ) ;
( * V_65 ) ++ ;
}
V_56 = F_77 ( V_7 , V_56 ) ;
V_2 -> V_197 = V_56 + * V_65 - 1 ;
return V_2 -> V_54 + V_56 ;
}
static struct V_1 * F_96 ( struct V_42 * V_43 , T_2 V_198 ,
T_1 V_199 , unsigned char V_9 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = NULL ;
T_1 V_44 , V_200 , V_201 ;
unsigned int V_33 ;
V_2 = F_18 ( V_43 , V_198 ) ;
if ( ! V_2 ) {
if ( F_97 ( V_43 ) )
F_16 ( V_43 , L_16 , ( unsigned long long ) V_198 ) ;
return NULL ;
}
V_44 = V_2 -> V_45 ;
V_200 = V_198 - V_2 -> V_54 ;
while ( V_199 -- ) {
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_200 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_201 = V_200 - V_7 -> V_23 * V_17 ;
V_200 ++ ;
if ( ! V_7 -> V_66 ) {
V_7 -> V_66 = F_98 ( V_7 -> V_48 -> V_202 ,
V_78 | V_203 ) ;
memcpy ( V_7 -> V_66 + V_7 -> V_24 ,
V_7 -> V_48 -> V_49 + V_7 -> V_24 ,
V_7 -> V_15 ) ;
}
F_95 ( V_2 -> V_69 , V_7 -> V_48 , 1 ) ;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , NULL , V_7 -> V_24 ,
V_7 , V_201 , V_9 ) ;
}
return V_2 ;
}
int F_99 ( struct V_204 * V_205 , const struct V_67 * V_68 )
{
const struct V_1 * V_2 = V_68 -> V_71 ;
if ( V_2 == NULL )
return 0 ;
F_100 ( V_205 , L_17 ,
( unsigned long long ) V_2 -> V_22 , V_2 -> V_109 ,
V_2 -> V_50 , V_2 -> V_134 , V_2 -> V_52 ) ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
F_72 ( V_43 , L_18 ,
( unsigned long long ) V_2 -> V_22 ) ;
F_72 ( V_43 , L_19 ) ;
F_99 ( NULL , V_2 -> V_69 ) ;
V_2 -> V_109 |= V_159 ;
}
int F_102 ( struct V_89 * V_90 , T_2 * V_206 , unsigned int * V_207 ,
bool V_193 , T_2 * V_208 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
struct V_135 * V_209 ;
struct V_1 * V_2 ;
unsigned int V_210 ;
T_1 V_35 , V_56 ;
T_2 V_8 ;
int error ;
struct V_6 * V_7 ;
if ( V_90 -> V_156 == NULL )
return - V_211 ;
V_2 = V_90 -> V_177 ;
if ( ! V_193 && F_17 ( V_2 , V_90 -> V_178 ) )
V_35 = V_90 -> V_178 - V_2 -> V_54 ;
else
V_35 = V_2 -> V_197 ;
V_56 = F_80 ( V_2 , V_35 , V_192 , & V_7 ) ;
if ( V_56 == V_37 )
goto V_212;
V_8 = F_94 ( V_2 , V_7 , V_56 , V_193 , V_207 ) ;
V_210 = * V_207 ;
if ( V_193 )
V_210 -- ;
if ( ! V_193 ) {
V_90 -> V_178 = V_8 + V_210 - 1 ;
error = F_103 ( V_90 , & V_209 ) ;
if ( error == 0 ) {
struct V_213 * V_214 =
(struct V_213 * ) V_209 -> V_49 ;
F_95 ( V_90 -> V_113 , V_209 , 1 ) ;
V_214 -> V_215 = V_214 -> V_216 =
F_60 ( V_90 -> V_178 ) ;
F_66 ( V_209 ) ;
}
}
if ( V_2 -> V_50 < * V_207 )
goto V_212;
V_2 -> V_50 -= * V_207 ;
if ( V_193 ) {
V_2 -> V_52 ++ ;
* V_208 = V_2 -> V_123 ++ ;
if ( * V_208 == 0 )
* V_208 = V_2 -> V_123 ++ ;
}
F_95 ( V_2 -> V_69 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_58 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_104 ( V_43 , 0 , - ( V_217 ) * V_207 , V_193 ? 1 : 0 ) ;
if ( V_193 )
F_105 ( V_43 , V_8 , 1 ) ;
if ( V_210 )
F_106 ( V_90 , V_210 , V_90 -> V_100 . V_218 ,
V_90 -> V_100 . V_219 ) ;
V_2 -> V_134 -= * V_207 ;
F_107 ( V_90 , V_8 , * V_207 ,
V_193 ? V_195 : V_196 ) ;
* V_206 = V_8 ;
return 0 ;
V_212:
F_101 ( V_2 ) ;
return - V_85 ;
}
void F_108 ( struct V_89 * V_90 , T_2 V_198 , T_1 V_199 , int V_220 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
struct V_1 * V_2 ;
V_2 = F_96 ( V_43 , V_198 , V_199 , V_192 ) ;
if ( ! V_2 )
return;
F_107 ( V_90 , V_198 , V_199 , V_192 ) ;
V_2 -> V_50 += V_199 ;
F_95 ( V_2 -> V_69 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_58 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
if ( V_220 || V_90 -> V_221 )
F_109 ( V_90 , V_198 , V_199 ) ;
}
void F_110 ( struct V_89 * V_90 , T_2 V_198 , T_1 V_199 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
F_108 ( V_90 , V_198 , V_199 , 1 ) ;
F_104 ( V_43 , 0 , + V_199 , 0 ) ;
F_106 ( V_90 , - ( V_217 ) V_199 , V_90 -> V_100 . V_218 , V_90 -> V_100 . V_219 ) ;
}
void F_111 ( struct V_87 * V_87 )
{
struct V_89 * V_90 = F_37 ( V_87 ) ;
struct V_42 * V_43 = F_48 ( V_87 ) ;
struct V_1 * V_2 ;
T_2 V_222 = V_90 -> V_182 ;
V_2 = F_96 ( V_43 , V_222 , 1 , V_166 ) ;
if ( ! V_2 )
return;
F_107 ( V_90 , V_222 , 1 , V_166 ) ;
F_95 ( V_2 -> V_69 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_58 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
}
static void F_112 ( struct V_1 * V_2 , T_2 V_222 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_1 * V_223 ;
V_223 = F_96 ( V_43 , V_222 , 1 , V_192 ) ;
if ( ! V_223 )
return;
F_113 ( V_43 , V_2 == V_223 ) ;
if ( ! V_2 -> V_52 )
F_6 ( V_2 ) ;
V_2 -> V_52 -- ;
V_2 -> V_50 ++ ;
F_95 ( V_2 -> V_69 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_58 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_104 ( V_43 , 0 , + 1 , - 1 ) ;
}
void F_114 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
F_112 ( V_2 , V_90 -> V_182 ) ;
F_107 ( V_90 , V_90 -> V_182 , 1 , V_192 ) ;
F_106 ( V_90 , - 1 , V_90 -> V_100 . V_218 , V_90 -> V_100 . V_219 ) ;
F_109 ( V_90 , V_90 -> V_182 , 1 ) ;
}
int F_115 ( struct V_42 * V_43 , T_2 V_163 , unsigned int type )
{
struct V_1 * V_2 ;
struct V_114 V_224 ;
int error ;
error = F_53 ( V_43 ) ;
if ( error )
return error ;
error = - V_77 ;
V_2 = F_18 ( V_43 , V_163 ) ;
if ( ! V_2 )
goto V_106;
error = F_55 ( V_2 -> V_69 , V_117 , 0 , & V_224 ) ;
if ( error )
goto V_106;
if ( F_89 ( V_2 , V_163 ) != type )
error = - V_225 ;
F_56 ( & V_224 ) ;
V_106:
return error ;
}
void F_116 ( struct V_89 * V_90 , struct V_226 * V_227 ,
T_2 V_8 )
{
struct V_42 * V_43 = F_48 ( & V_90 -> V_100 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_31 ;
unsigned int V_228 ;
unsigned int V_46 ;
if ( F_67 ( V_43 , ! V_227 -> V_229 ) )
return;
if ( V_90 -> V_177 && F_17 ( V_90 -> V_177 , V_8 ) )
V_2 = V_90 -> V_177 ;
else
V_2 = F_18 ( V_43 , V_8 ) ;
if ( ! V_2 ) {
F_16 ( V_43 , L_20 , ( unsigned long long ) V_8 ) ;
return;
}
V_90 -> V_177 = V_2 ;
for ( V_46 = 0 ; V_46 < V_227 -> V_230 ; V_46 ++ )
if ( V_227 -> V_231 [ V_46 ] == V_2 )
return;
if ( V_227 -> V_230 == V_227 -> V_232 ) {
V_228 = V_227 -> V_232 + 10 ;
V_31 = F_35 ( V_228 , sizeof( struct V_1 * ) ,
V_78 | V_203 ) ;
if ( V_227 -> V_231 ) {
memcpy ( V_31 , V_227 -> V_231 ,
V_227 -> V_232 * sizeof( struct V_1 * ) ) ;
F_27 ( V_227 -> V_231 ) ;
}
V_227 -> V_232 = V_228 ;
V_227 -> V_231 = V_31 ;
}
V_227 -> V_231 [ V_227 -> V_230 ++ ] = V_2 ;
}
void F_117 ( struct V_226 * V_227 , unsigned int V_30 )
{
unsigned int V_46 ;
V_227 -> V_229 = F_35 ( V_227 -> V_230 , sizeof( struct V_114 ) ,
V_78 | V_203 ) ;
for ( V_46 = 0 ; V_46 < V_227 -> V_230 ; V_46 ++ )
F_118 ( V_227 -> V_231 [ V_46 ] -> V_69 ,
V_30 , 0 ,
& V_227 -> V_229 [ V_46 ] ) ;
}
void F_119 ( struct V_226 * V_227 )
{
unsigned int V_46 ;
F_27 ( V_227 -> V_231 ) ;
if ( V_227 -> V_229 ) {
for ( V_46 = 0 ; V_46 < V_227 -> V_230 ; V_46 ++ )
F_120 ( & V_227 -> V_229 [ V_46 ] ) ;
F_27 ( V_227 -> V_229 ) ;
}
}
