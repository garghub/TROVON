static inline void F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
struct V_4 * V_5 , T_1 V_6 ,
unsigned char V_7 )
{
unsigned char * V_8 , * V_9 , * V_10 , V_11 ;
unsigned int V_12 = V_5 -> V_13 ;
const unsigned int V_14 = ( V_6 % V_15 ) * V_16 ;
V_8 = V_5 -> V_17 -> V_18 + V_5 -> V_19 + ( V_6 / V_15 ) ;
V_10 = V_5 -> V_17 -> V_18 + V_5 -> V_19 + V_12 ;
F_2 ( V_8 >= V_10 ) ;
V_11 = ( * V_8 >> V_14 ) & V_20 ;
if ( F_3 ( ! V_21 [ V_7 * 4 + V_11 ] ) ) {
F_4 ( V_22 L_1
L_2 ,
( unsigned long long ) V_6 , V_11 , V_7 ) ;
F_4 ( V_22 L_3 ,
( unsigned long long ) V_2 -> V_23 ,
( unsigned long ) V_5 -> V_24 ) ;
F_4 ( V_22 L_4 ,
( unsigned long ) V_5 -> V_19 ,
( unsigned long ) V_5 -> V_13 ) ;
F_5 () ;
F_6 ( V_2 ) ;
return;
}
* V_8 ^= ( V_11 ^ V_7 ) << V_14 ;
if ( V_3 ) {
V_9 = V_3 + V_5 -> V_19 + ( V_6 / V_15 ) ;
V_11 = ( * V_9 >> V_14 ) & V_20 ;
* V_9 ^= ( V_11 ^ V_7 ) << V_14 ;
}
}
static inline unsigned char F_7 ( struct V_1 * V_2 ,
const unsigned char * V_25 ,
unsigned int V_12 , T_1 V_6 )
{
const unsigned char * V_26 , * V_10 ;
unsigned char V_11 ;
unsigned int V_14 ;
V_26 = V_25 + ( V_6 / V_15 ) ;
V_14 = ( V_6 % V_15 ) * V_16 ;
V_10 = V_25 + V_12 ;
F_8 ( V_2 -> V_27 , V_26 < V_10 ) ;
V_11 = ( * V_26 >> V_14 ) & V_20 ;
return V_11 ;
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
const T_3 * V_10 = ( T_3 * ) ( V_33 + F_12 ( V_34 , sizeof( T_2 ) ) ) ;
T_2 V_31 ;
T_2 V_29 = 0x5555555555555555ULL ;
T_1 V_14 ;
F_2 ( V_30 > 3 ) ;
V_29 <<= V_36 ;
V_31 = F_9 ( V_28 , V_29 , V_30 ) ;
V_28 ++ ;
while( V_31 == 0 && V_28 < V_10 ) {
V_31 = F_9 ( V_28 , 0x5555555555555555ULL , V_30 ) ;
V_28 ++ ;
}
if ( V_28 == V_10 && ( V_34 & ( sizeof( T_2 ) - 1 ) ) )
V_31 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_34 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_31 == 0 )
return V_37 ;
V_28 -- ;
V_14 = F_13 ( V_31 ) ;
V_14 /= 2 ;
return ( ( ( const unsigned char * ) V_28 - V_33 ) * V_15 ) + V_14 ;
}
static T_1 F_14 ( struct V_1 * V_2 , const T_4 * V_25 ,
unsigned int V_12 , T_4 V_30 )
{
const T_4 * V_26 = V_25 ;
const T_4 * V_10 = V_25 + V_12 ;
const T_4 V_38 = V_30 << 2 ;
const T_4 V_39 = V_30 << 4 ;
const T_4 V_40 = V_30 << 6 ;
T_1 V_41 = 0 ;
for (; V_26 < V_10 ; V_26 ++ ) {
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
struct V_4 * V_5 = NULL ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_41 [ 4 ] , V_31 ;
int V_33 , V_46 ;
memset ( V_41 , 0 , 4 * sizeof( T_1 ) ) ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_5 = V_2 -> V_47 + V_33 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ )
V_41 [ V_46 ] += F_14 ( V_2 ,
V_5 -> V_17 -> V_18 +
V_5 -> V_19 ,
V_5 -> V_13 , V_46 ) ;
}
if ( V_41 [ 0 ] != V_2 -> V_48 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_5 ,
V_41 [ 0 ] , V_2 -> V_48 ) ;
return;
}
V_31 = V_2 -> V_49 - V_2 -> V_48 - V_2 -> V_50 ;
if ( V_41 [ 1 ] != V_31 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_6 ,
V_41 [ 1 ] , V_31 ) ;
return;
}
if ( V_41 [ 2 ] + V_41 [ 3 ] != V_2 -> V_50 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_7 ,
V_41 [ 2 ] + V_41 [ 3 ] , V_2 -> V_50 ) ;
return;
}
}
static inline int F_17 ( struct V_1 * V_2 , T_2 V_6 )
{
T_2 V_51 = V_2 -> V_52 ;
T_2 V_53 = V_51 + V_2 -> V_49 ;
return V_51 <= V_6 && V_6 < V_53 ;
}
struct V_1 * F_18 ( struct V_42 * V_43 , T_2 V_54 , bool V_55 )
{
struct V_56 * V_57 , * V_58 ;
struct V_1 * V_59 ;
F_19 ( & V_43 -> V_60 ) ;
V_57 = V_43 -> V_61 . V_56 ;
while ( V_57 ) {
V_59 = F_20 ( V_57 , struct V_1 , V_62 ) ;
V_58 = NULL ;
if ( V_54 < V_59 -> V_23 )
V_58 = V_57 -> V_63 ;
else if ( V_54 >= V_59 -> V_52 + V_59 -> V_49 )
V_58 = V_57 -> V_64 ;
if ( V_58 == NULL ) {
F_21 ( & V_43 -> V_60 ) ;
if ( V_55 ) {
if ( V_54 < V_59 -> V_23 )
return NULL ;
if ( V_54 >= V_59 -> V_52 + V_59 -> V_49 )
return NULL ;
}
return V_59 ;
}
V_57 = V_58 ;
}
F_21 ( & V_43 -> V_60 ) ;
return NULL ;
}
struct V_1 * F_22 ( struct V_42 * V_43 )
{
const struct V_56 * V_57 ;
struct V_1 * V_2 ;
F_19 ( & V_43 -> V_60 ) ;
V_57 = F_23 ( & V_43 -> V_61 ) ;
V_2 = F_20 ( V_57 , struct V_1 , V_62 ) ;
F_21 ( & V_43 -> V_60 ) ;
return V_2 ;
}
struct V_1 * F_24 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
const struct V_56 * V_57 ;
F_19 ( & V_43 -> V_60 ) ;
V_57 = F_25 ( & V_2 -> V_62 ) ;
if ( V_57 == NULL )
V_57 = F_23 ( & V_43 -> V_61 ) ;
if ( F_3 ( & V_2 -> V_62 == V_57 ) ) {
F_21 ( & V_43 -> V_60 ) ;
return NULL ;
}
V_2 = F_20 ( V_57 , struct V_1 , V_62 ) ;
F_21 ( & V_43 -> V_60 ) ;
return V_2 ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_45 ; V_46 ++ ) {
struct V_4 * V_5 = V_2 -> V_47 + V_46 ;
F_27 ( V_5 -> V_65 ) ;
V_5 -> V_65 = NULL ;
}
}
void F_28 ( struct V_42 * V_43 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
while ( ( V_57 = F_23 ( & V_43 -> V_61 ) ) ) {
V_2 = F_20 ( V_57 , struct V_1 , V_62 ) ;
V_67 = V_2 -> V_68 ;
F_29 ( V_57 , & V_43 -> V_61 ) ;
if ( V_67 ) {
F_19 ( & V_67 -> V_69 ) ;
V_67 -> V_70 = NULL ;
F_21 ( & V_67 -> V_69 ) ;
F_30 ( V_67 ) ;
F_31 ( V_67 ) ;
}
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_47 ) ;
F_32 ( V_71 , V_2 ) ;
}
}
static void F_33 ( const struct V_1 * V_2 )
{
F_4 ( V_72 L_8 , ( unsigned long long ) V_2 -> V_23 ) ;
F_4 ( V_72 L_9 , V_2 -> V_45 ) ;
F_4 ( V_72 L_10 , ( unsigned long long ) V_2 -> V_52 ) ;
F_4 ( V_72 L_11 , V_2 -> V_49 ) ;
F_4 ( V_72 L_12 , V_2 -> V_73 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_4 * V_5 ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_74 , V_75 ;
int V_46 ;
if ( ! V_44 )
return - V_76 ;
V_2 -> V_47 = F_35 ( V_44 , sizeof( struct V_4 ) , V_77 ) ;
if ( ! V_2 -> V_47 )
return - V_78 ;
V_74 = V_2 -> V_73 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_5 = V_2 -> V_47 + V_46 ;
V_5 -> V_79 = 0 ;
if ( V_44 == 1 ) {
V_75 = V_74 ;
V_5 -> V_19 = sizeof( struct V_80 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_13 = V_75 ;
} else if ( V_46 == 0 ) {
V_75 = V_43 -> V_81 . V_82 - sizeof( struct V_80 ) ;
V_5 -> V_19 = sizeof( struct V_80 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_13 = V_75 ;
} else if ( V_46 + 1 == V_44 ) {
V_75 = V_74 ;
V_5 -> V_19 = sizeof( struct V_83 ) ;
V_5 -> V_24 = V_2 -> V_73 - V_74 ;
V_5 -> V_13 = V_75 ;
} else {
V_75 = V_43 -> V_81 . V_82 -
sizeof( struct V_83 ) ;
V_5 -> V_19 = sizeof( struct V_83 ) ;
V_5 -> V_24 = V_2 -> V_73 - V_74 ;
V_5 -> V_13 = V_75 ;
}
V_74 -= V_75 ;
}
if ( V_74 ) {
F_6 ( V_2 ) ;
return - V_84 ;
}
V_5 = V_2 -> V_47 + ( V_44 - 1 ) ;
if ( ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 != V_2 -> V_49 ) {
if ( F_6 ( V_2 ) ) {
F_33 ( V_2 ) ;
F_16 ( V_43 , L_13 ,
V_5 -> V_24 , V_5 -> V_13 , V_5 -> V_19 ) ;
}
return - V_84 ;
}
return 0 ;
}
T_2 F_36 ( struct V_42 * V_43 )
{
T_2 V_85 = 0 ;
struct V_86 * V_86 = V_43 -> V_87 ;
struct V_88 * V_89 = F_37 ( V_86 ) ;
char V_33 [ sizeof( struct V_90 ) ] ;
int error , V_91 ;
for ( V_91 = 0 ; ; V_91 ++ ) {
T_5 V_92 = V_91 * sizeof( struct V_90 ) ;
if ( V_92 + sizeof( struct V_90 ) > F_38 ( V_86 ) )
break;
error = F_39 ( V_89 , V_33 , & V_92 ,
sizeof( struct V_90 ) ) ;
if ( error != sizeof( struct V_90 ) )
break;
V_85 += F_40 ( ( (struct V_90 * ) V_33 ) -> V_93 ) ;
}
return V_85 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_56 * * V_94 = & V_43 -> V_61 . V_56 , * V_95 = NULL ;
while ( * V_94 ) {
struct V_1 * V_59 = F_20 ( * V_94 , struct V_1 ,
V_62 ) ;
V_95 = * V_94 ;
if ( V_2 -> V_23 < V_59 -> V_23 )
V_94 = & ( ( * V_94 ) -> V_63 ) ;
else if ( V_2 -> V_23 > V_59 -> V_23 )
V_94 = & ( ( * V_94 ) -> V_64 ) ;
else
return - V_96 ;
}
F_42 ( & V_2 -> V_62 , V_95 , V_94 ) ;
F_43 ( & V_2 -> V_62 , & V_43 -> V_61 ) ;
V_43 -> V_97 ++ ;
return 0 ;
}
static int F_44 ( struct V_88 * V_89 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
T_5 V_92 = V_43 -> V_97 * sizeof( struct V_90 ) ;
struct V_90 V_33 ;
int error ;
struct V_1 * V_2 ;
if ( V_92 >= F_38 ( & V_89 -> V_98 ) )
return 1 ;
error = F_39 ( V_89 , ( char * ) & V_33 , & V_92 ,
sizeof( struct V_90 ) ) ;
if ( error != sizeof( struct V_90 ) )
return ( error == 0 ) ? 1 : error ;
V_2 = F_46 ( V_71 , V_77 ) ;
error = - V_78 ;
if ( ! V_2 )
return error ;
V_2 -> V_27 = V_43 ;
V_2 -> V_23 = F_47 ( V_33 . V_99 ) ;
V_2 -> V_45 = F_40 ( V_33 . V_100 ) ;
V_2 -> V_52 = F_47 ( V_33 . V_101 ) ;
V_2 -> V_49 = F_40 ( V_33 . V_93 ) ;
V_2 -> V_73 = F_40 ( V_33 . V_102 ) ;
error = F_34 ( V_2 ) ;
if ( error )
goto V_103;
error = F_48 ( V_43 , V_2 -> V_23 ,
& V_104 , V_105 , & V_2 -> V_68 ) ;
if ( error )
goto V_103;
V_2 -> V_68 -> V_70 = V_2 ;
V_2 -> V_106 &= ~ V_107 ;
if ( V_2 -> V_49 > V_43 -> V_108 )
V_43 -> V_108 = V_2 -> V_49 ;
F_19 ( & V_43 -> V_60 ) ;
error = F_41 ( V_2 ) ;
F_21 ( & V_43 -> V_60 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_31 ( V_2 -> V_68 ) ;
V_103:
F_27 ( V_2 -> V_47 ) ;
F_32 ( V_71 , V_2 ) ;
return error ;
}
static int F_49 ( struct V_88 * V_89 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
int error ;
do {
error = F_44 ( V_89 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_43 -> V_109 = 1 ;
return 0 ;
}
int F_50 ( struct V_42 * V_43 )
{
struct V_88 * V_89 = F_37 ( V_43 -> V_87 ) ;
struct V_66 * V_67 = V_89 -> V_110 ;
struct V_111 V_112 ;
int error = 0 ;
int V_113 = 0 ;
if ( ! V_43 -> V_109 ) {
if ( ! F_51 ( V_67 ) ) {
error = F_52 ( V_67 , V_114 , 0 , & V_112 ) ;
if ( error )
return error ;
V_113 = 1 ;
}
if ( ! V_43 -> V_109 )
error = F_49 ( V_89 ) ;
if ( V_113 )
F_53 ( & V_112 ) ;
}
return error ;
}
static void F_54 ( struct V_1 * V_2 , const void * V_33 )
{
const struct V_80 * V_115 = V_33 ;
T_1 V_116 ;
V_116 = F_40 ( V_115 -> V_116 ) ;
V_116 &= ~ V_117 ;
V_2 -> V_106 &= V_117 ;
V_2 -> V_106 |= V_116 ;
V_2 -> V_48 = F_40 ( V_115 -> V_118 ) ;
V_2 -> V_50 = F_40 ( V_115 -> V_119 ) ;
V_2 -> V_120 = F_47 ( V_115 -> V_121 ) ;
}
static void F_55 ( struct V_1 * V_2 , void * V_33 )
{
struct V_80 * V_115 = V_33 ;
V_115 -> V_116 = F_56 ( V_2 -> V_106 & ~ V_117 ) ;
V_115 -> V_118 = F_56 ( V_2 -> V_48 ) ;
V_115 -> V_119 = F_56 ( V_2 -> V_50 ) ;
V_115 -> V_122 = F_56 ( 0 ) ;
V_115 -> V_121 = F_57 ( V_2 -> V_120 ) ;
memset ( & V_115 -> V_123 , 0 , sizeof( V_115 -> V_123 ) ) ;
}
int F_58 ( struct V_111 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_125 -> V_70 ;
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_66 * V_67 = V_2 -> V_68 ;
unsigned int V_44 = V_2 -> V_45 ;
struct V_4 * V_5 ;
unsigned int V_46 , V_126 ;
int error ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_5 = V_2 -> V_47 + V_46 ;
error = F_59 ( V_67 , V_2 -> V_23 + V_46 , 0 , & V_5 -> V_17 ) ;
if ( error )
goto V_103;
}
for ( V_126 = V_44 ; V_126 -- ; ) {
V_5 = V_2 -> V_47 + V_126 ;
error = F_60 ( V_43 , V_5 -> V_17 ) ;
if ( error )
goto V_103;
if ( F_61 ( V_43 , V_5 -> V_17 , V_126 ? V_127 :
V_128 ) ) {
error = - V_84 ;
goto V_103;
}
}
if ( ! ( V_2 -> V_106 & V_107 ) ) {
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ )
F_62 ( V_129 , & V_2 -> V_47 [ V_46 ] . V_79 ) ;
F_54 ( V_2 , ( V_2 -> V_47 [ 0 ] . V_17 ) -> V_18 ) ;
V_2 -> V_106 |= ( V_107 | V_130 ) ;
V_2 -> V_131 = V_2 -> V_48 ;
}
return 0 ;
V_103:
while ( V_46 -- ) {
V_5 = V_2 -> V_47 + V_46 ;
F_63 ( V_5 -> V_17 ) ;
V_5 -> V_17 = NULL ;
F_64 ( V_43 , ! V_5 -> V_65 ) ;
}
return error ;
}
void F_65 ( struct V_111 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_125 -> V_70 ;
int V_46 , V_44 = V_2 -> V_45 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
struct V_4 * V_5 = V_2 -> V_47 + V_46 ;
F_63 ( V_5 -> V_17 ) ;
V_5 -> V_17 = NULL ;
}
}
int F_66 ( struct V_42 * V_43 , T_2 V_132 ,
struct V_133 * V_134 ,
const struct V_4 * V_5 , unsigned V_135 , T_2 * V_136 )
{
struct V_137 * V_138 = V_43 -> V_139 ;
struct V_140 * V_141 = V_138 -> V_142 ;
const unsigned int V_143 = V_43 -> V_81 . V_82 /
F_67 ( V_138 -> V_142 ) ;
T_2 V_54 ;
T_6 V_144 = 0 ;
T_6 V_145 = 0 ;
int V_146 ;
unsigned int V_46 ;
T_1 V_147 = 0 ;
T_4 V_148 ;
for ( V_46 = 0 ; V_46 < V_5 -> V_13 ; V_46 ++ ) {
const T_4 * V_149 = V_5 -> V_65 ? V_5 -> V_65 : V_5 -> V_17 -> V_18 ;
V_149 += V_5 -> V_19 ;
V_149 += V_46 ;
if ( V_134 ) {
const T_4 * V_150 = V_134 -> V_18 + V_5 -> V_19 + V_46 ;
V_148 = ~ ( * V_150 | ( * V_150 >> 1 ) ) & ( * V_149 | ( * V_149 >> 1 ) ) ;
} else {
V_148 = ~ ( * V_149 | ( * V_149 >> 1 ) ) ;
}
V_148 &= 0x55 ;
if ( V_148 == 0 )
continue;
V_54 = V_132 + ( ( V_5 -> V_24 + V_46 ) * V_15 ) ;
V_54 *= V_143 ;
while( V_148 ) {
if ( V_148 & 1 ) {
if ( V_145 == 0 )
goto V_151;
if ( ( V_144 + V_145 ) != V_54 ) {
if ( V_145 >= V_135 ) {
V_146 = F_68 ( V_141 ,
V_144 , V_145 ,
V_77 , 0 ) ;
if ( V_146 )
goto V_103;
V_147 += V_145 ;
}
V_145 = 0 ;
V_151:
V_144 = V_54 ;
}
V_145 += V_143 ;
}
V_148 >>= 2 ;
V_54 += V_143 ;
}
}
if ( V_145 >= V_135 ) {
V_146 = F_68 ( V_141 , V_144 , V_145 , V_77 , 0 ) ;
if ( V_146 )
goto V_103;
V_147 += V_145 ;
}
if ( V_136 )
* V_136 = V_147 ;
return 0 ;
V_103:
if ( V_43 -> V_152 . V_153 )
F_69 ( V_43 , L_14 , V_146 ) ;
V_43 -> V_152 . V_153 = 0 ;
return - V_84 ;
}
int F_70 ( struct V_154 * V_155 , void T_7 * V_156 )
{
struct V_86 * V_86 = V_155 -> V_157 -> V_158 ;
struct V_42 * V_43 = F_45 ( V_86 ) ;
struct V_159 * V_160 = F_71 ( V_43 -> V_139 -> V_142 ) ;
struct V_133 * V_134 ;
struct V_1 * V_2 ;
struct V_1 * V_161 ;
struct V_111 V_124 ;
struct V_162 V_163 ;
int V_164 = 0 ;
T_2 V_165 ;
T_2 V_147 = 0 ;
unsigned int V_46 ;
if ( ! F_72 ( V_166 ) )
return - V_167 ;
if ( ! F_73 ( V_160 ) )
return - V_168 ;
if ( V_156 == NULL ) {
V_163 . V_144 = 0 ;
V_163 . V_34 = V_169 ;
V_163 . V_135 = 0 ;
} else if ( F_74 ( & V_163 , V_156 , sizeof( V_163 ) ) )
return - V_170 ;
V_164 = F_50 ( V_43 ) ;
if ( V_164 )
return V_164 ;
V_2 = F_18 ( V_43 , V_163 . V_144 , 0 ) ;
V_161 = F_18 ( V_43 , V_163 . V_144 + V_163 . V_34 , 0 ) ;
while ( 1 ) {
V_164 = F_52 ( V_2 -> V_68 , V_171 , 0 , & V_124 ) ;
if ( V_164 )
goto V_172;
if ( ! ( V_2 -> V_106 & V_173 ) ) {
for ( V_46 = 0 ; V_46 < V_2 -> V_45 ; V_46 ++ ) {
struct V_4 * V_5 = V_2 -> V_47 + V_46 ;
V_164 = F_66 ( V_43 , V_2 -> V_52 , NULL , V_5 , V_163 . V_135 , & V_165 ) ;
if ( V_164 ) {
F_53 ( & V_124 ) ;
goto V_172;
}
V_147 += V_165 ;
}
V_164 = F_75 ( V_43 , V_174 , 0 ) ;
if ( V_164 == 0 ) {
V_134 = V_2 -> V_47 [ 0 ] . V_17 ;
V_2 -> V_106 |= V_173 ;
F_76 ( V_2 -> V_68 , V_134 , 1 ) ;
F_55 ( V_2 , V_134 -> V_18 ) ;
F_77 ( V_43 ) ;
}
}
F_53 ( & V_124 ) ;
if ( V_2 == V_161 )
break;
V_2 = F_24 ( V_2 ) ;
}
V_172:
V_163 . V_34 = V_147 << 9 ;
if ( V_156 && F_78 ( V_156 , & V_163 , sizeof( V_163 ) ) )
return - V_170 ;
return V_164 ;
}
struct V_175 * F_79 ( struct V_88 * V_89 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
int error ;
F_2 ( V_89 -> V_176 != NULL ) ;
V_89 -> V_176 = F_80 ( sizeof( struct V_175 ) , V_77 ) ;
error = F_50 ( V_43 ) ;
if ( error )
F_69 ( V_43 , L_15 , error ) ;
return V_89 -> V_176 ;
}
static int F_81 ( struct V_88 * V_89 )
{
F_2 ( V_89 -> V_177 != NULL ) ;
V_89 -> V_177 = F_46 ( V_178 , V_77 ) ;
if ( ! V_89 -> V_177 )
return - V_78 ;
return 0 ;
}
static int F_82 ( const struct V_1 * V_2 , const struct V_88 * V_89 )
{
const struct V_179 * V_180 = V_89 -> V_177 ;
if ( V_2 -> V_106 & ( V_181 | V_182 ) )
return 0 ;
if ( V_2 -> V_131 >= V_180 -> V_183 )
return 1 ;
return 0 ;
}
static inline T_1 F_83 ( struct V_4 * V_5 , T_1 V_54 )
{
return ( V_5 -> V_24 * V_15 ) + V_54 ;
}
static void F_84 ( struct V_1 * V_2 , T_2 * V_184 , T_2 V_185 )
{
T_1 V_35 = 0 , V_6 ;
T_2 V_186 ;
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_66 * V_67 ;
struct V_88 * V_89 ;
int error ;
int V_187 = 0 ;
struct V_4 * V_5 ;
while ( V_35 < V_2 -> V_49 ) {
F_85 ( & V_43 -> V_188 ) ;
V_6 = F_86 ( V_2 , V_35 , V_189 , & V_5 ) ;
F_87 ( & V_43 -> V_188 ) ;
if ( V_6 == V_37 )
break;
V_6 = F_83 ( V_5 , V_6 ) ;
V_186 = V_6 + V_2 -> V_52 ;
V_35 = F_88 ( V_6 + 1 , V_35 + 1 ) ;
if ( * V_184 != V_190 && V_186 <= * V_184 )
continue;
if ( V_186 == V_185 )
continue;
* V_184 = V_186 ;
error = F_48 ( V_43 , V_186 , & V_191 , V_105 , & V_67 ) ;
if ( error )
continue;
V_89 = V_67 -> V_70 ;
if ( V_89 || F_89 ( V_192 , & V_67 -> V_193 ) == 0 )
F_31 ( V_67 ) ;
else
V_187 ++ ;
if ( V_187 > V_194 )
return;
}
V_2 -> V_106 &= ~ V_130 ;
return;
}
static int F_90 ( struct V_88 * V_89 , T_2 * V_184 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
struct V_1 * V_2 , * V_195 = NULL ;
struct V_179 * V_180 = V_89 -> V_177 ;
int error , V_196 , V_197 = V_198 ;
int V_199 = 0 ;
if ( V_89 -> V_200 && F_17 ( V_89 -> V_200 , V_89 -> V_201 ) )
V_2 = V_195 = V_89 -> V_200 ;
else
V_2 = V_195 = F_18 ( V_43 , V_89 -> V_201 , 1 ) ;
if ( V_2 == NULL )
return - V_202 ;
while ( V_199 < 3 ) {
V_196 = 0 ;
if ( F_51 ( V_2 -> V_68 ) ) {
V_196 = 1 ;
error = 0 ;
} else {
error = F_52 ( V_2 -> V_68 , V_171 ,
V_197 , & V_180 -> V_203 ) ;
}
switch ( error ) {
case 0 :
if ( F_82 ( V_2 , V_89 ) ) {
V_89 -> V_200 = V_2 ;
return 0 ;
}
if ( V_2 -> V_106 & V_130 )
F_84 ( V_2 , V_184 , V_89 -> V_204 ) ;
if ( ! V_196 )
F_53 ( & V_180 -> V_203 ) ;
case V_205 :
V_2 = F_24 ( V_2 ) ;
if ( V_2 == V_195 ) {
V_197 = 0 ;
V_199 ++ ;
}
break;
default:
return error ;
}
}
return - V_206 ;
}
static void F_91 ( struct V_88 * V_89 )
{
F_2 ( V_89 -> V_177 == NULL ) ;
F_32 ( V_178 , V_89 -> V_177 ) ;
V_89 -> V_177 = NULL ;
}
int F_92 ( struct V_88 * V_89 , T_1 V_207 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
struct V_179 * V_180 ;
int error ;
T_2 V_184 = V_190 ;
int V_208 = 0 ;
error = F_81 ( V_89 ) ;
if ( error )
return error ;
V_180 = V_89 -> V_177 ;
V_180 -> V_183 = V_207 ;
if ( F_64 ( V_43 , V_207 ) ) {
error = - V_76 ;
goto V_172;
}
do {
error = F_90 ( V_89 , & V_184 ) ;
if ( error != - V_206 )
break;
if ( V_89 == F_37 ( V_43 -> V_87 ) && ! V_43 -> V_109 ) {
error = F_49 ( V_89 ) ;
if ( error )
break;
continue;
}
F_93 ( V_43 , NULL ) ;
} while ( V_208 ++ < 3 );
V_172:
if ( error )
F_91 ( V_89 ) ;
return error ;
}
void F_94 ( struct V_88 * V_89 )
{
struct V_179 * V_180 = V_89 -> V_177 ;
if ( V_180 -> V_203 . V_125 )
F_53 ( & V_180 -> V_203 ) ;
F_91 ( V_89 ) ;
}
static unsigned char F_95 ( struct V_1 * V_2 , T_2 V_6 )
{
struct V_4 * V_5 = NULL ;
T_1 V_44 , V_209 , V_210 ;
unsigned int V_33 ;
unsigned char type ;
V_44 = V_2 -> V_45 ;
V_209 = V_6 - V_2 -> V_52 ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_5 = V_2 -> V_47 + V_33 ;
if ( V_209 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_210 = V_209 - V_5 -> V_24 * V_15 ;
type = F_7 ( V_2 , V_5 -> V_17 -> V_18 + V_5 -> V_19 ,
V_5 -> V_13 , V_210 ) ;
return type ;
}
static T_1 F_86 ( struct V_1 * V_2 , T_1 V_35 , unsigned char V_30 ,
struct V_4 * * V_211 )
{
struct V_4 * V_5 = NULL ;
const T_1 V_44 = V_2 -> V_45 ;
T_1 V_212 = V_37 ;
unsigned int V_33 , V_46 ;
const T_4 * V_25 = NULL ;
* V_211 = NULL ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_5 = V_2 -> V_47 + V_33 ;
if ( V_35 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 ) {
V_35 -= V_5 -> V_24 * V_15 ;
goto V_213;
}
}
V_33 = 0 ;
V_35 = 0 ;
V_213:
for ( V_46 = 0 ; V_46 <= V_44 ; V_46 ++ ) {
V_5 = V_2 -> V_47 + V_33 ;
if ( F_96 ( V_129 , & V_5 -> V_79 ) &&
( V_30 == V_214 ) )
goto V_185;
V_25 = V_5 -> V_17 -> V_18 + V_5 -> V_19 ;
F_97 ( ! F_98 ( V_5 -> V_17 ) ) ;
if ( V_30 != V_189 && V_5 -> V_65 )
V_25 = V_5 -> V_65 + V_5 -> V_19 ;
V_212 = F_11 ( V_25 , V_5 -> V_13 , V_35 , V_30 ) ;
if ( V_212 != V_37 )
break;
if ( ( V_35 == 0 ) && ( V_30 == V_214 ) )
F_99 ( V_129 , & V_5 -> V_79 ) ;
V_185:
V_33 ++ ;
V_33 %= V_44 ;
V_35 = 0 ;
}
if ( V_212 != V_37 )
* V_211 = V_5 ;
return V_212 ;
}
static T_2 F_100 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_1 V_54 , bool V_215 , unsigned int * V_57 )
{
const unsigned int V_216 = * V_57 ;
T_1 V_35 ;
const T_4 * V_25 = NULL ;
* V_57 = 0 ;
V_25 = V_5 -> V_17 -> V_18 + V_5 -> V_19 ;
F_76 ( V_2 -> V_68 , V_5 -> V_17 , 1 ) ;
F_1 ( V_2 , V_5 -> V_65 , V_5 , V_54 ,
V_215 ? V_217 : V_218 ) ;
( * V_57 ) ++ ;
V_35 = V_54 ;
while ( * V_57 < V_216 ) {
V_35 ++ ;
if ( V_35 >= ( V_5 -> V_13 * V_15 ) )
break;
if ( F_7 ( V_2 , V_25 , V_5 -> V_13 , V_35 ) !=
V_214 )
break;
F_1 ( V_2 , V_5 -> V_65 , V_5 , V_35 , V_218 ) ;
( * V_57 ) ++ ;
}
V_54 = F_83 ( V_5 , V_54 ) ;
V_2 -> V_219 = V_54 + * V_57 - 1 ;
return V_2 -> V_52 + V_54 ;
}
static struct V_1 * F_101 ( struct V_42 * V_43 , T_2 V_220 ,
T_1 V_221 , unsigned char V_7 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = NULL ;
T_1 V_44 , V_222 , V_223 ;
unsigned int V_33 ;
V_2 = F_18 ( V_43 , V_220 , 1 ) ;
if ( ! V_2 ) {
if ( F_102 ( V_43 ) )
F_16 ( V_43 , L_16 , ( unsigned long long ) V_220 ) ;
return NULL ;
}
V_44 = V_2 -> V_45 ;
V_222 = V_220 - V_2 -> V_52 ;
while ( V_221 -- ) {
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_5 = V_2 -> V_47 + V_33 ;
if ( V_222 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_223 = V_222 - V_5 -> V_24 * V_15 ;
V_222 ++ ;
if ( ! V_5 -> V_65 ) {
V_5 -> V_65 = F_103 ( V_5 -> V_17 -> V_224 ,
V_77 | V_225 ) ;
memcpy ( V_5 -> V_65 + V_5 -> V_19 ,
V_5 -> V_17 -> V_18 + V_5 -> V_19 ,
V_5 -> V_13 ) ;
}
F_76 ( V_2 -> V_68 , V_5 -> V_17 , 1 ) ;
F_1 ( V_2 , NULL , V_5 , V_223 , V_7 ) ;
}
return V_2 ;
}
int F_104 ( struct V_226 * V_227 , const struct V_66 * V_67 )
{
const struct V_1 * V_2 = V_67 -> V_70 ;
if ( V_2 == NULL )
return 0 ;
F_105 ( V_227 , L_17 ,
( unsigned long long ) V_2 -> V_23 , V_2 -> V_106 ,
V_2 -> V_48 , V_2 -> V_131 , V_2 -> V_50 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
F_69 ( V_43 , L_18 ,
( unsigned long long ) V_2 -> V_23 ) ;
F_69 ( V_43 , L_19 ) ;
F_104 ( NULL , V_2 -> V_68 ) ;
V_2 -> V_106 |= V_182 ;
}
int F_107 ( struct V_88 * V_89 , T_2 * V_228 , unsigned int * V_229 ,
bool V_215 , T_2 * V_230 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
struct V_133 * V_231 ;
struct V_1 * V_2 ;
unsigned int V_232 ;
T_1 V_35 , V_54 ;
T_2 V_6 ;
int error ;
struct V_4 * V_5 ;
if ( V_89 -> V_177 == NULL )
return - V_233 ;
V_2 = V_89 -> V_200 ;
if ( ! V_215 && F_17 ( V_2 , V_89 -> V_201 ) )
V_35 = V_89 -> V_201 - V_2 -> V_52 ;
else
V_35 = V_2 -> V_219 ;
V_54 = F_86 ( V_2 , V_35 , V_214 , & V_5 ) ;
if ( V_54 == V_37 )
goto V_234;
V_6 = F_100 ( V_2 , V_5 , V_54 , V_215 , V_229 ) ;
V_232 = * V_229 ;
if ( V_215 )
V_232 -- ;
if ( ! V_215 ) {
V_89 -> V_201 = V_6 + V_232 - 1 ;
error = F_108 ( V_89 , & V_231 ) ;
if ( error == 0 ) {
struct V_235 * V_236 =
(struct V_235 * ) V_231 -> V_18 ;
F_76 ( V_89 -> V_110 , V_231 , 1 ) ;
V_236 -> V_237 = V_236 -> V_238 =
F_57 ( V_89 -> V_201 ) ;
F_63 ( V_231 ) ;
}
}
if ( V_2 -> V_48 < * V_229 )
goto V_234;
V_2 -> V_48 -= * V_229 ;
if ( V_215 ) {
V_2 -> V_50 ++ ;
* V_230 = V_2 -> V_120 ++ ;
if ( * V_230 == 0 )
* V_230 = V_2 -> V_120 ++ ;
}
F_76 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_17 , 1 ) ;
F_55 ( V_2 , V_2 -> V_47 [ 0 ] . V_17 -> V_18 ) ;
F_109 ( V_43 , 0 , - ( V_239 ) * V_229 , V_215 ? 1 : 0 ) ;
if ( V_215 )
F_110 ( V_43 , V_6 , 1 ) ;
if ( V_232 )
F_111 ( V_89 , V_232 , V_89 -> V_98 . V_240 ,
V_89 -> V_98 . V_241 ) ;
V_2 -> V_131 -= * V_229 ;
F_112 ( V_89 , V_2 , V_6 , * V_229 ,
V_215 ? V_217 : V_218 ) ;
* V_228 = V_6 ;
return 0 ;
V_234:
F_106 ( V_2 ) ;
return - V_84 ;
}
void F_113 ( struct V_88 * V_89 , T_2 V_220 , T_1 V_221 , int V_242 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
struct V_1 * V_2 ;
V_2 = F_101 ( V_43 , V_220 , V_221 , V_214 ) ;
if ( ! V_2 )
return;
F_112 ( V_89 , V_2 , V_220 , V_221 , V_214 ) ;
V_2 -> V_48 += V_221 ;
V_2 -> V_106 &= ~ V_173 ;
F_76 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_17 , 1 ) ;
F_55 ( V_2 , V_2 -> V_47 [ 0 ] . V_17 -> V_18 ) ;
if ( V_242 || V_89 -> V_243 )
F_114 ( V_89 , V_220 , V_221 ) ;
}
void F_115 ( struct V_88 * V_89 , T_2 V_220 , T_1 V_221 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
F_113 ( V_89 , V_220 , V_221 , 1 ) ;
F_109 ( V_43 , 0 , + V_221 , 0 ) ;
F_111 ( V_89 , - ( V_239 ) V_221 , V_89 -> V_98 . V_240 , V_89 -> V_98 . V_241 ) ;
}
void F_116 ( struct V_86 * V_86 )
{
struct V_88 * V_89 = F_37 ( V_86 ) ;
struct V_42 * V_43 = F_45 ( V_86 ) ;
struct V_1 * V_2 ;
T_2 V_244 = V_89 -> V_204 ;
V_2 = F_101 ( V_43 , V_244 , 1 , V_189 ) ;
if ( ! V_2 )
return;
F_112 ( V_89 , V_2 , V_244 , 1 , V_189 ) ;
F_76 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_17 , 1 ) ;
F_55 ( V_2 , V_2 -> V_47 [ 0 ] . V_17 -> V_18 ) ;
}
static void F_117 ( struct V_1 * V_2 , T_2 V_244 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_1 * V_245 ;
V_245 = F_101 ( V_43 , V_244 , 1 , V_214 ) ;
if ( ! V_245 )
return;
F_118 ( V_43 , V_2 == V_245 ) ;
if ( ! V_2 -> V_50 )
F_6 ( V_2 ) ;
V_2 -> V_50 -- ;
V_2 -> V_48 ++ ;
F_76 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_17 , 1 ) ;
F_55 ( V_2 , V_2 -> V_47 [ 0 ] . V_17 -> V_18 ) ;
F_109 ( V_43 , 0 , + 1 , - 1 ) ;
}
void F_119 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
F_117 ( V_2 , V_89 -> V_204 ) ;
F_112 ( V_89 , V_2 , V_89 -> V_204 , 1 , V_214 ) ;
F_111 ( V_89 , - 1 , V_89 -> V_98 . V_240 , V_89 -> V_98 . V_241 ) ;
F_114 ( V_89 , V_89 -> V_204 , 1 ) ;
}
int F_120 ( struct V_42 * V_43 , T_2 V_186 , unsigned int type )
{
struct V_1 * V_2 ;
struct V_111 V_246 ;
int error = - V_76 ;
V_2 = F_18 ( V_43 , V_186 , 1 ) ;
if ( ! V_2 )
goto V_103;
error = F_52 ( V_2 -> V_68 , V_114 , 0 , & V_246 ) ;
if ( error )
goto V_103;
if ( F_95 ( V_2 , V_186 ) != type )
error = - V_247 ;
F_53 ( & V_246 ) ;
V_103:
return error ;
}
void F_121 ( struct V_88 * V_89 , struct V_248 * V_249 ,
T_2 V_6 )
{
struct V_42 * V_43 = F_45 ( & V_89 -> V_98 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_31 ;
unsigned int V_250 ;
unsigned int V_46 ;
if ( F_64 ( V_43 , ! V_249 -> V_251 ) )
return;
if ( V_89 -> V_200 && F_17 ( V_89 -> V_200 , V_6 ) )
V_2 = V_89 -> V_200 ;
else
V_2 = F_18 ( V_43 , V_6 , 1 ) ;
if ( ! V_2 ) {
F_16 ( V_43 , L_20 , ( unsigned long long ) V_6 ) ;
return;
}
V_89 -> V_200 = V_2 ;
for ( V_46 = 0 ; V_46 < V_249 -> V_252 ; V_46 ++ )
if ( V_249 -> V_253 [ V_46 ] == V_2 )
return;
if ( V_249 -> V_252 == V_249 -> V_254 ) {
V_250 = V_249 -> V_254 + 10 ;
V_31 = F_35 ( V_250 , sizeof( struct V_1 * ) ,
V_77 | V_225 ) ;
if ( V_249 -> V_253 ) {
memcpy ( V_31 , V_249 -> V_253 ,
V_249 -> V_254 * sizeof( struct V_1 * ) ) ;
F_27 ( V_249 -> V_253 ) ;
}
V_249 -> V_254 = V_250 ;
V_249 -> V_253 = V_31 ;
}
V_249 -> V_253 [ V_249 -> V_252 ++ ] = V_2 ;
}
void F_122 ( struct V_248 * V_249 , unsigned int V_30 )
{
unsigned int V_46 ;
V_249 -> V_251 = F_35 ( V_249 -> V_252 , sizeof( struct V_111 ) ,
V_77 | V_225 ) ;
for ( V_46 = 0 ; V_46 < V_249 -> V_252 ; V_46 ++ )
F_123 ( V_249 -> V_253 [ V_46 ] -> V_68 ,
V_30 , 0 ,
& V_249 -> V_251 [ V_46 ] ) ;
}
void F_124 ( struct V_248 * V_249 )
{
unsigned int V_46 ;
F_27 ( V_249 -> V_253 ) ;
if ( V_249 -> V_251 ) {
for ( V_46 = 0 ; V_46 < V_249 -> V_252 ; V_46 ++ )
F_125 ( & V_249 -> V_251 [ V_46 ] ) ;
F_27 ( V_249 -> V_251 ) ;
}
}
