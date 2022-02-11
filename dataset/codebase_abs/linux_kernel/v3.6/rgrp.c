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
static inline int F_11 ( T_2 V_33 , T_1 V_34 , struct V_35 * V_36 )
{
T_2 V_37 = F_12 ( V_36 ) ;
if ( V_33 >= V_37 + V_36 -> V_38 )
return 1 ;
if ( V_33 + V_34 - 1 < V_37 )
return - 1 ;
return 0 ;
}
static struct V_35 * F_13 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_40 * * V_41 ;
int V_42 ;
T_2 V_43 = V_39 + V_2 -> V_44 ;
F_14 ( & V_2 -> V_45 ) ;
V_41 = & V_2 -> V_46 . V_40 ;
while ( * V_41 ) {
struct V_35 * V_47 =
F_15 ( * V_41 , struct V_35 , V_48 ) ;
V_42 = F_11 ( V_43 , 1 , V_47 ) ;
if ( V_42 < 0 )
V_41 = & ( ( * V_41 ) -> V_49 ) ;
else if ( V_42 > 0 )
V_41 = & ( ( * V_41 ) -> V_50 ) ;
else {
F_16 ( & V_2 -> V_45 ) ;
return V_47 ;
}
}
F_16 ( & V_2 -> V_45 ) ;
return NULL ;
}
static T_1 F_17 ( const T_4 * V_51 , const unsigned int V_34 ,
T_1 V_52 , T_4 V_30 )
{
T_1 V_53 = ( V_52 << 1 ) & ( ( 8 * sizeof( T_2 ) ) - 1 ) ;
const T_3 * V_28 = ( ( T_3 * ) V_51 ) + ( V_52 >> 5 ) ;
const T_3 * V_10 = ( T_3 * ) ( V_51 + F_18 ( V_34 , sizeof( T_2 ) ) ) ;
T_2 V_31 ;
T_2 V_29 = 0x5555555555555555ULL ;
T_1 V_14 ;
F_2 ( V_30 > 3 ) ;
V_29 <<= V_53 ;
V_31 = F_9 ( V_28 , V_29 , V_30 ) ;
V_28 ++ ;
while( V_31 == 0 && V_28 < V_10 ) {
V_31 = F_9 ( V_28 , 0x5555555555555555ULL , V_30 ) ;
V_28 ++ ;
}
if ( V_28 == V_10 && ( V_34 & ( sizeof( T_2 ) - 1 ) ) )
V_31 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_34 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_31 == 0 )
return V_54 ;
V_28 -- ;
V_14 = F_19 ( V_31 ) ;
V_14 /= 2 ;
return ( ( ( const unsigned char * ) V_28 - V_51 ) * V_15 ) + V_14 ;
}
static T_1 F_20 ( struct V_1 * V_2 , const T_4 * V_25 ,
unsigned int V_12 , T_4 V_30 )
{
const T_4 * V_26 = V_25 ;
const T_4 * V_10 = V_25 + V_12 ;
const T_4 V_55 = V_30 << 2 ;
const T_4 V_56 = V_30 << 4 ;
const T_4 V_57 = V_30 << 6 ;
T_1 V_58 = 0 ;
for (; V_26 < V_10 ; V_26 ++ ) {
if ( ( ( * V_26 ) & 0x03 ) == V_30 )
V_58 ++ ;
if ( ( ( * V_26 ) & 0x0C ) == V_55 )
V_58 ++ ;
if ( ( ( * V_26 ) & 0x30 ) == V_56 )
V_58 ++ ;
if ( ( ( * V_26 ) & 0xC0 ) == V_57 )
V_58 ++ ;
}
return V_58 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
struct V_4 * V_5 = NULL ;
T_1 V_61 = V_2 -> V_62 ;
T_1 V_58 [ 4 ] , V_31 ;
int V_51 , V_63 ;
memset ( V_58 , 0 , 4 * sizeof( T_1 ) ) ;
for ( V_51 = 0 ; V_51 < V_61 ; V_51 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ )
V_58 [ V_63 ] += F_20 ( V_2 ,
V_5 -> V_17 -> V_18 +
V_5 -> V_19 ,
V_5 -> V_13 , V_63 ) ;
}
if ( V_58 [ 0 ] != V_2 -> V_65 ) {
if ( F_6 ( V_2 ) )
F_22 ( V_60 , L_5 ,
V_58 [ 0 ] , V_2 -> V_65 ) ;
return;
}
V_31 = V_2 -> V_66 - V_2 -> V_65 - V_2 -> V_67 ;
if ( V_58 [ 1 ] != V_31 ) {
if ( F_6 ( V_2 ) )
F_22 ( V_60 , L_6 ,
V_58 [ 1 ] , V_31 ) ;
return;
}
if ( V_58 [ 2 ] + V_58 [ 3 ] != V_2 -> V_67 ) {
if ( F_6 ( V_2 ) )
F_22 ( V_60 , L_7 ,
V_58 [ 2 ] + V_58 [ 3 ] , V_2 -> V_67 ) ;
return;
}
}
static inline int F_23 ( struct V_1 * V_2 , T_2 V_6 )
{
T_2 V_68 = V_2 -> V_44 ;
T_2 V_69 = V_68 + V_2 -> V_66 ;
return V_68 <= V_6 && V_6 < V_69 ;
}
struct V_1 * F_24 ( struct V_59 * V_60 , T_2 V_33 , bool V_70 )
{
struct V_40 * V_71 , * V_72 ;
struct V_1 * V_47 ;
F_14 ( & V_60 -> V_73 ) ;
V_71 = V_60 -> V_74 . V_40 ;
while ( V_71 ) {
V_47 = F_15 ( V_71 , struct V_1 , V_75 ) ;
V_72 = NULL ;
if ( V_33 < V_47 -> V_23 )
V_72 = V_71 -> V_49 ;
else if ( V_33 >= V_47 -> V_44 + V_47 -> V_66 )
V_72 = V_71 -> V_50 ;
if ( V_72 == NULL ) {
F_16 ( & V_60 -> V_73 ) ;
if ( V_70 ) {
if ( V_33 < V_47 -> V_23 )
return NULL ;
if ( V_33 >= V_47 -> V_44 + V_47 -> V_66 )
return NULL ;
}
return V_47 ;
}
V_71 = V_72 ;
}
F_16 ( & V_60 -> V_73 ) ;
return NULL ;
}
struct V_1 * F_25 ( struct V_59 * V_60 )
{
const struct V_40 * V_71 ;
struct V_1 * V_2 ;
F_14 ( & V_60 -> V_73 ) ;
V_71 = F_26 ( & V_60 -> V_74 ) ;
V_2 = F_15 ( V_71 , struct V_1 , V_75 ) ;
F_16 ( & V_60 -> V_73 ) ;
return V_2 ;
}
struct V_1 * F_27 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
const struct V_40 * V_71 ;
F_14 ( & V_60 -> V_73 ) ;
V_71 = F_28 ( & V_2 -> V_75 ) ;
if ( V_71 == NULL )
V_71 = F_26 ( & V_60 -> V_74 ) ;
if ( F_3 ( & V_2 -> V_75 == V_71 ) ) {
F_16 ( & V_60 -> V_73 ) ;
return NULL ;
}
V_2 = F_15 ( V_71 , struct V_1 , V_75 ) ;
F_16 ( & V_60 -> V_73 ) ;
return V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_62 ; V_63 ++ ) {
struct V_4 * V_5 = V_2 -> V_64 + V_63 ;
F_30 ( V_5 -> V_76 ) ;
V_5 -> V_76 = NULL ;
}
}
int F_31 ( struct V_77 * V_78 )
{
int error = 0 ;
struct V_35 * V_79 ;
if ( V_78 -> V_80 )
return 0 ;
V_79 = F_32 ( V_81 , V_82 ) ;
if ( ! V_79 )
error = - V_83 ;
F_33 ( & V_78 -> V_84 ) ;
if ( V_78 -> V_80 )
F_34 ( V_81 , V_79 ) ;
else
V_78 -> V_80 = V_79 ;
F_35 ( & V_78 -> V_84 ) ;
return error ;
}
static void F_36 ( struct V_85 * V_86 , struct V_35 * V_36 )
{
F_37 ( V_86 , L_8 ,
V_36 -> V_87 -> V_23 , F_12 ( V_36 ) , V_36 -> V_88 ,
V_36 -> V_38 ) ;
}
static void F_38 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
if ( ! F_39 ( V_36 ) )
return;
V_2 = V_36 -> V_87 ;
F_40 ( NULL , V_36 , V_89 ) ;
if ( ! F_41 ( & V_2 -> V_46 ) )
F_42 ( & V_36 -> V_48 , & V_2 -> V_46 ) ;
F_2 ( ! V_2 -> V_90 ) ;
V_2 -> V_90 -- ;
if ( V_36 -> V_38 ) {
F_2 ( V_36 -> V_87 -> V_91 < V_36 -> V_38 ) ;
V_36 -> V_87 -> V_91 -= V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
F_43 ( V_92 , & V_36 -> V_93 -> V_94 ) ;
F_44 () ;
}
V_36 -> V_93 = NULL ;
V_36 -> V_88 = 0 ;
}
void F_45 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
if ( ! F_39 ( V_36 ) )
return;
V_2 = V_36 -> V_87 ;
F_14 ( & V_2 -> V_45 ) ;
F_38 ( V_36 ) ;
F_16 ( & V_2 -> V_45 ) ;
}
void F_46 ( struct V_77 * V_78 )
{
F_33 ( & V_78 -> V_84 ) ;
if ( V_78 -> V_80 ) {
F_45 ( V_78 -> V_80 ) ;
F_40 ( V_78 , V_78 -> V_80 , V_95 ) ;
F_2 ( V_78 -> V_80 -> V_38 ) ;
F_34 ( V_81 , V_78 -> V_80 ) ;
V_78 -> V_80 = NULL ;
}
F_35 ( & V_78 -> V_84 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_40 * V_71 ;
struct V_35 * V_36 ;
F_14 ( & V_2 -> V_45 ) ;
while ( ( V_71 = F_26 ( & V_2 -> V_46 ) ) ) {
V_36 = F_15 ( V_71 , struct V_35 , V_48 ) ;
F_38 ( V_36 ) ;
}
F_16 ( & V_2 -> V_45 ) ;
}
void F_48 ( struct V_59 * V_60 )
{
struct V_40 * V_71 ;
struct V_1 * V_2 ;
struct V_96 * V_97 ;
while ( ( V_71 = F_26 ( & V_60 -> V_74 ) ) ) {
V_2 = F_15 ( V_71 , struct V_1 , V_75 ) ;
V_97 = V_2 -> V_98 ;
F_42 ( V_71 , & V_60 -> V_74 ) ;
if ( V_97 ) {
F_14 ( & V_97 -> V_99 ) ;
V_97 -> V_100 = NULL ;
F_16 ( & V_97 -> V_99 ) ;
F_49 ( V_97 ) ;
F_50 ( V_97 ) ;
}
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_64 ) ;
F_47 ( V_2 ) ;
F_34 ( V_101 , V_2 ) ;
}
}
static void F_51 ( const struct V_1 * V_2 )
{
F_4 ( V_102 L_9 , ( unsigned long long ) V_2 -> V_23 ) ;
F_4 ( V_102 L_10 , V_2 -> V_62 ) ;
F_4 ( V_102 L_11 , ( unsigned long long ) V_2 -> V_44 ) ;
F_4 ( V_102 L_12 , V_2 -> V_66 ) ;
F_4 ( V_102 L_13 , V_2 -> V_103 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
struct V_4 * V_5 ;
T_1 V_61 = V_2 -> V_62 ;
T_1 V_104 , V_105 ;
int V_63 ;
if ( ! V_61 )
return - V_106 ;
V_2 -> V_64 = F_53 ( V_61 , sizeof( struct V_4 ) , V_82 ) ;
if ( ! V_2 -> V_64 )
return - V_83 ;
V_104 = V_2 -> V_103 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
V_5 = V_2 -> V_64 + V_63 ;
V_5 -> V_94 = 0 ;
if ( V_61 == 1 ) {
V_105 = V_104 ;
V_5 -> V_19 = sizeof( struct V_107 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_13 = V_105 ;
} else if ( V_63 == 0 ) {
V_105 = V_60 -> V_108 . V_109 - sizeof( struct V_107 ) ;
V_5 -> V_19 = sizeof( struct V_107 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_13 = V_105 ;
} else if ( V_63 + 1 == V_61 ) {
V_105 = V_104 ;
V_5 -> V_19 = sizeof( struct V_110 ) ;
V_5 -> V_24 = V_2 -> V_103 - V_104 ;
V_5 -> V_13 = V_105 ;
} else {
V_105 = V_60 -> V_108 . V_109 -
sizeof( struct V_110 ) ;
V_5 -> V_19 = sizeof( struct V_110 ) ;
V_5 -> V_24 = V_2 -> V_103 - V_104 ;
V_5 -> V_13 = V_105 ;
}
V_104 -= V_105 ;
}
if ( V_104 ) {
F_6 ( V_2 ) ;
return - V_111 ;
}
V_5 = V_2 -> V_64 + ( V_61 - 1 ) ;
if ( ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 != V_2 -> V_66 ) {
if ( F_6 ( V_2 ) ) {
F_51 ( V_2 ) ;
F_22 ( V_60 , L_14 ,
V_5 -> V_24 , V_5 -> V_13 , V_5 -> V_19 ) ;
}
return - V_111 ;
}
return 0 ;
}
T_2 F_54 ( struct V_59 * V_60 )
{
T_2 V_112 = 0 ;
struct V_113 * V_113 = V_60 -> V_114 ;
struct V_77 * V_78 = F_55 ( V_113 ) ;
char V_51 [ sizeof( struct V_115 ) ] ;
int error , V_116 ;
for ( V_116 = 0 ; ; V_116 ++ ) {
T_5 V_117 = V_116 * sizeof( struct V_115 ) ;
if ( V_117 + sizeof( struct V_115 ) > F_56 ( V_113 ) )
break;
error = F_57 ( V_78 , V_51 , & V_117 ,
sizeof( struct V_115 ) ) ;
if ( error != sizeof( struct V_115 ) )
break;
V_112 += F_58 ( ( (struct V_115 * ) V_51 ) -> V_118 ) ;
}
return V_112 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
struct V_40 * * V_41 = & V_60 -> V_74 . V_40 , * V_119 = NULL ;
while ( * V_41 ) {
struct V_1 * V_47 = F_15 ( * V_41 , struct V_1 ,
V_75 ) ;
V_119 = * V_41 ;
if ( V_2 -> V_23 < V_47 -> V_23 )
V_41 = & ( ( * V_41 ) -> V_49 ) ;
else if ( V_2 -> V_23 > V_47 -> V_23 )
V_41 = & ( ( * V_41 ) -> V_50 ) ;
else
return - V_120 ;
}
F_60 ( & V_2 -> V_75 , V_119 , V_41 ) ;
F_61 ( & V_2 -> V_75 , & V_60 -> V_74 ) ;
V_60 -> V_121 ++ ;
return 0 ;
}
static int F_62 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
T_5 V_117 = V_60 -> V_121 * sizeof( struct V_115 ) ;
struct V_115 V_51 ;
int error ;
struct V_1 * V_2 ;
if ( V_117 >= F_56 ( & V_78 -> V_122 ) )
return 1 ;
error = F_57 ( V_78 , ( char * ) & V_51 , & V_117 ,
sizeof( struct V_115 ) ) ;
if ( error != sizeof( struct V_115 ) )
return ( error == 0 ) ? 1 : error ;
V_2 = F_32 ( V_101 , V_82 ) ;
error = - V_83 ;
if ( ! V_2 )
return error ;
V_2 -> V_27 = V_60 ;
V_2 -> V_23 = F_64 ( V_51 . V_123 ) ;
V_2 -> V_62 = F_58 ( V_51 . V_124 ) ;
V_2 -> V_44 = F_64 ( V_51 . V_125 ) ;
V_2 -> V_66 = F_58 ( V_51 . V_118 ) ;
V_2 -> V_103 = F_58 ( V_51 . V_126 ) ;
F_65 ( & V_2 -> V_45 ) ;
error = F_52 ( V_2 ) ;
if ( error )
goto V_127;
error = F_66 ( V_60 , V_2 -> V_23 ,
& V_128 , V_129 , & V_2 -> V_98 ) ;
if ( error )
goto V_127;
V_2 -> V_98 -> V_100 = V_2 ;
V_2 -> V_130 = (struct V_131 * ) V_2 -> V_98 -> V_132 ;
V_2 -> V_133 &= ~ V_134 ;
if ( V_2 -> V_66 > V_60 -> V_135 )
V_60 -> V_135 = V_2 -> V_66 ;
F_14 ( & V_60 -> V_73 ) ;
error = F_59 ( V_2 ) ;
F_16 ( & V_60 -> V_73 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_50 ( V_2 -> V_98 ) ;
V_127:
F_30 ( V_2 -> V_64 ) ;
F_34 ( V_101 , V_2 ) ;
return error ;
}
static int F_67 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
int error ;
do {
error = F_62 ( V_78 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_60 -> V_136 = 1 ;
return 0 ;
}
int F_68 ( struct V_59 * V_60 )
{
struct V_77 * V_78 = F_55 ( V_60 -> V_114 ) ;
struct V_96 * V_97 = V_78 -> V_137 ;
struct V_138 V_139 ;
int error = 0 ;
int V_140 = 0 ;
if ( ! V_60 -> V_136 ) {
if ( ! F_69 ( V_97 ) ) {
error = F_70 ( V_97 , V_141 , 0 , & V_139 ) ;
if ( error )
return error ;
V_140 = 1 ;
}
if ( ! V_60 -> V_136 )
error = F_67 ( V_78 ) ;
if ( V_140 )
F_71 ( & V_139 ) ;
}
return error ;
}
static void F_72 ( struct V_1 * V_2 , const void * V_51 )
{
const struct V_107 * V_142 = V_51 ;
T_1 V_143 ;
V_143 = F_58 ( V_142 -> V_143 ) ;
V_143 &= ~ V_144 ;
V_2 -> V_133 &= V_144 ;
V_2 -> V_133 |= V_143 ;
V_2 -> V_65 = F_58 ( V_142 -> V_145 ) ;
V_2 -> V_67 = F_58 ( V_142 -> V_146 ) ;
V_2 -> V_147 = F_64 ( V_142 -> V_148 ) ;
}
static void F_73 ( struct V_1 * V_2 , void * V_51 )
{
struct V_107 * V_142 = V_51 ;
V_142 -> V_143 = F_74 ( V_2 -> V_133 & ~ V_144 ) ;
V_142 -> V_145 = F_74 ( V_2 -> V_65 ) ;
V_142 -> V_146 = F_74 ( V_2 -> V_67 ) ;
V_142 -> V_149 = F_74 ( 0 ) ;
V_142 -> V_148 = F_75 ( V_2 -> V_147 ) ;
memset ( & V_142 -> V_150 , 0 , sizeof( V_142 -> V_150 ) ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_131 * V_151 = V_2 -> V_130 ;
struct V_107 * V_142 = (struct V_107 * ) V_2 -> V_64 [ 0 ] . V_17 -> V_18 ;
if ( V_151 -> V_152 != V_142 -> V_143 || V_151 -> V_153 != V_142 -> V_145 ||
V_151 -> V_154 != V_142 -> V_146 ||
V_151 -> V_155 != V_142 -> V_148 )
return 0 ;
return 1 ;
}
static void F_77 ( struct V_131 * V_151 , const void * V_51 )
{
const struct V_107 * V_142 = V_51 ;
V_151 -> V_156 = F_74 ( V_157 ) ;
V_151 -> V_152 = V_142 -> V_143 ;
V_151 -> V_153 = V_142 -> V_145 ;
V_151 -> V_154 = V_142 -> V_146 ;
V_151 -> V_155 = V_142 -> V_148 ;
V_151 -> V_149 = 0UL ;
}
static void F_78 ( struct V_1 * V_2 , T_1 V_158 )
{
struct V_131 * V_151 = V_2 -> V_130 ;
T_1 V_159 = F_58 ( V_151 -> V_160 ) + V_158 ;
V_151 -> V_160 = F_74 ( V_159 ) ;
}
static T_1 F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
const T_1 V_61 = V_2 -> V_62 ;
const T_4 * V_25 = NULL ;
T_1 V_161 , V_52 , V_58 = 0 ;
for ( V_161 = 0 , V_5 = V_2 -> V_64 ; V_161 < V_61 ; V_161 ++ , V_5 ++ ) {
V_52 = 0 ;
V_25 = V_5 -> V_17 -> V_18 + V_5 -> V_19 ;
F_80 ( ! F_81 ( V_5 -> V_17 ) ) ;
while ( V_52 < V_5 -> V_13 * V_15 ) {
V_52 = F_17 ( V_25 , V_5 -> V_13 , V_52 ,
V_162 ) ;
if ( V_52 == V_54 )
break;
V_58 ++ ;
V_52 ++ ;
}
}
return V_58 ;
}
int F_82 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
struct V_96 * V_97 = V_2 -> V_98 ;
unsigned int V_61 = V_2 -> V_62 ;
struct V_4 * V_5 ;
unsigned int V_63 , V_163 ;
int error ;
if ( V_2 -> V_64 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
V_5 = V_2 -> V_64 + V_63 ;
error = F_83 ( V_97 , V_2 -> V_23 + V_63 , 0 , & V_5 -> V_17 ) ;
if ( error )
goto V_127;
}
for ( V_163 = V_61 ; V_163 -- ; ) {
V_5 = V_2 -> V_64 + V_163 ;
error = F_84 ( V_60 , V_5 -> V_17 ) ;
if ( error )
goto V_127;
if ( F_85 ( V_60 , V_5 -> V_17 , V_163 ? V_164 :
V_165 ) ) {
error = - V_111 ;
goto V_127;
}
}
if ( ! ( V_2 -> V_133 & V_134 ) ) {
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ )
F_43 ( V_92 , & V_2 -> V_64 [ V_63 ] . V_94 ) ;
F_72 ( V_2 , ( V_2 -> V_64 [ 0 ] . V_17 ) -> V_18 ) ;
V_2 -> V_133 |= ( V_134 | V_166 ) ;
V_2 -> V_167 = V_2 -> V_65 ;
}
if ( F_58 ( V_157 ) != V_2 -> V_130 -> V_156 ) {
V_2 -> V_130 -> V_160 = F_74 ( F_79 ( V_2 ) ) ;
F_77 ( V_2 -> V_130 ,
V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_60 -> V_168 . V_169 ) {
if ( ! F_76 ( V_2 ) ) {
F_6 ( V_2 ) ;
error = - V_111 ;
goto V_127;
}
if ( V_2 -> V_130 -> V_160 == 0 )
V_2 -> V_133 &= ~ V_166 ;
}
return 0 ;
V_127:
while ( V_63 -- ) {
V_5 = V_2 -> V_64 + V_63 ;
F_86 ( V_5 -> V_17 ) ;
V_5 -> V_17 = NULL ;
F_87 ( V_60 , ! V_5 -> V_76 ) ;
}
return error ;
}
int F_88 ( struct V_1 * V_2 )
{
T_1 V_152 ;
if ( V_2 -> V_133 & V_134 )
return 0 ;
if ( F_58 ( V_157 ) != V_2 -> V_130 -> V_156 )
return F_82 ( V_2 ) ;
V_152 = F_58 ( V_2 -> V_130 -> V_152 ) ;
V_152 &= ~ V_144 ;
V_2 -> V_133 &= V_144 ;
V_2 -> V_133 |= ( V_152 | V_134 | V_166 ) ;
if ( V_2 -> V_130 -> V_160 == 0 )
V_2 -> V_133 &= ~ V_166 ;
V_2 -> V_65 = F_58 ( V_2 -> V_130 -> V_153 ) ;
V_2 -> V_167 = V_2 -> V_65 ;
V_2 -> V_67 = F_58 ( V_2 -> V_130 -> V_154 ) ;
V_2 -> V_147 = F_64 ( V_2 -> V_130 -> V_155 ) ;
return 0 ;
}
int F_89 ( struct V_138 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_171 -> V_100 ;
struct V_59 * V_60 = V_2 -> V_27 ;
if ( V_170 -> V_172 & V_173 && V_60 -> V_168 . V_169 )
return 0 ;
return F_82 ( (struct V_1 * ) V_170 -> V_171 -> V_100 ) ;
}
void F_90 ( struct V_138 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_171 -> V_100 ;
int V_63 , V_61 = V_2 -> V_62 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
struct V_4 * V_5 = V_2 -> V_64 + V_63 ;
if ( V_5 -> V_17 ) {
F_86 ( V_5 -> V_17 ) ;
V_5 -> V_17 = NULL ;
}
}
}
int F_91 ( struct V_59 * V_60 , T_2 V_174 ,
struct V_175 * V_176 ,
const struct V_4 * V_5 , unsigned V_177 , T_2 * V_178 )
{
struct V_179 * V_180 = V_60 -> V_181 ;
struct V_182 * V_183 = V_180 -> V_184 ;
const unsigned int V_185 = V_60 -> V_108 . V_109 /
F_92 ( V_180 -> V_184 ) ;
T_2 V_33 ;
T_6 V_186 = 0 ;
T_6 V_187 = 0 ;
int V_188 ;
unsigned int V_63 ;
T_1 V_189 = 0 ;
T_4 V_190 ;
for ( V_63 = 0 ; V_63 < V_5 -> V_13 ; V_63 ++ ) {
const T_4 * V_191 = V_5 -> V_76 ? V_5 -> V_76 : V_5 -> V_17 -> V_18 ;
V_191 += V_5 -> V_19 ;
V_191 += V_63 ;
if ( V_176 ) {
const T_4 * V_192 = V_176 -> V_18 + V_5 -> V_19 + V_63 ;
V_190 = ~ ( * V_192 | ( * V_192 >> 1 ) ) & ( * V_191 | ( * V_191 >> 1 ) ) ;
} else {
V_190 = ~ ( * V_191 | ( * V_191 >> 1 ) ) ;
}
V_190 &= 0x55 ;
if ( V_190 == 0 )
continue;
V_33 = V_174 + ( ( V_5 -> V_24 + V_63 ) * V_15 ) ;
V_33 *= V_185 ;
while( V_190 ) {
if ( V_190 & 1 ) {
if ( V_187 == 0 )
goto V_193;
if ( ( V_186 + V_187 ) != V_33 ) {
if ( V_187 >= V_177 ) {
V_188 = F_93 ( V_183 ,
V_186 , V_187 ,
V_82 , 0 ) ;
if ( V_188 )
goto V_127;
V_189 += V_187 ;
}
V_187 = 0 ;
V_193:
V_186 = V_33 ;
}
V_187 += V_185 ;
}
V_190 >>= 2 ;
V_33 += V_185 ;
}
}
if ( V_187 >= V_177 ) {
V_188 = F_93 ( V_183 , V_186 , V_187 , V_82 , 0 ) ;
if ( V_188 )
goto V_127;
V_189 += V_187 ;
}
if ( V_178 )
* V_178 = V_189 ;
return 0 ;
V_127:
if ( V_60 -> V_168 . V_194 )
F_94 ( V_60 , L_15 , V_188 ) ;
V_60 -> V_168 . V_194 = 0 ;
return - V_111 ;
}
int F_95 ( struct V_195 * V_196 , void T_7 * V_197 )
{
struct V_113 * V_113 = V_196 -> V_198 -> V_199 ;
struct V_59 * V_60 = F_63 ( V_113 ) ;
struct V_200 * V_201 = F_96 ( V_60 -> V_181 -> V_184 ) ;
struct V_175 * V_176 ;
struct V_1 * V_2 ;
struct V_1 * V_202 ;
struct V_138 V_170 ;
struct V_203 V_204 ;
int V_205 = 0 ;
T_2 V_206 ;
T_2 V_189 = 0 ;
unsigned int V_63 ;
if ( ! F_97 ( V_207 ) )
return - V_208 ;
if ( ! F_98 ( V_201 ) )
return - V_209 ;
if ( V_197 == NULL ) {
V_204 . V_186 = 0 ;
V_204 . V_34 = V_210 ;
V_204 . V_177 = 0 ;
} else if ( F_99 ( & V_204 , V_197 , sizeof( V_204 ) ) )
return - V_211 ;
V_205 = F_68 ( V_60 ) ;
if ( V_205 )
return V_205 ;
V_2 = F_24 ( V_60 , V_204 . V_186 , 0 ) ;
V_202 = F_24 ( V_60 , V_204 . V_186 + V_204 . V_34 , 0 ) ;
while ( 1 ) {
V_205 = F_70 ( V_2 -> V_98 , V_212 , 0 , & V_170 ) ;
if ( V_205 )
goto V_213;
if ( ! ( V_2 -> V_133 & V_214 ) ) {
for ( V_63 = 0 ; V_63 < V_2 -> V_62 ; V_63 ++ ) {
struct V_4 * V_5 = V_2 -> V_64 + V_63 ;
V_205 = F_91 ( V_60 , V_2 -> V_44 , NULL , V_5 , V_204 . V_177 , & V_206 ) ;
if ( V_205 ) {
F_71 ( & V_170 ) ;
goto V_213;
}
V_189 += V_206 ;
}
V_205 = F_100 ( V_60 , V_215 , 0 ) ;
if ( V_205 == 0 ) {
V_176 = V_2 -> V_64 [ 0 ] . V_17 ;
V_2 -> V_133 |= V_214 ;
F_101 ( V_2 -> V_98 , V_176 , 1 ) ;
F_73 ( V_2 , V_176 -> V_18 ) ;
F_77 ( V_2 -> V_130 , V_176 -> V_18 ) ;
F_102 ( V_60 ) ;
}
}
F_71 ( & V_170 ) ;
if ( V_2 == V_202 )
break;
V_2 = F_27 ( V_2 ) ;
}
V_213:
V_204 . V_34 = V_189 << 9 ;
if ( V_197 && F_103 ( V_197 , & V_204 , sizeof( V_204 ) ) )
return - V_211 ;
return V_205 ;
}
static struct V_35 * F_104 ( struct V_4 * V_5 ,
struct V_77 * V_78 , T_1 V_216 ,
int V_217 )
{
struct V_40 * * V_41 , * V_119 = NULL ;
int V_42 ;
struct V_35 * V_36 = V_78 -> V_80 ;
struct V_1 * V_2 = V_36 -> V_87 ;
T_2 V_218 = F_105 ( V_5 , V_216 ) + V_2 -> V_44 ;
F_14 ( & V_2 -> V_45 ) ;
V_41 = & V_2 -> V_46 . V_40 ;
F_2 ( ! V_78 -> V_80 ) ;
F_2 ( F_39 ( V_36 ) ) ;
while ( * V_41 ) {
struct V_35 * V_47 =
F_15 ( * V_41 , struct V_35 , V_48 ) ;
V_119 = * V_41 ;
V_42 = F_11 ( V_218 , V_217 , V_47 ) ;
if ( V_42 > 0 )
V_41 = & ( ( * V_41 ) -> V_50 ) ;
else if ( V_42 < 0 )
V_41 = & ( ( * V_41 ) -> V_49 ) ;
else {
F_16 ( & V_2 -> V_45 ) ;
return NULL ;
}
}
V_36 = V_78 -> V_80 ;
V_36 -> V_38 = V_217 ;
V_36 -> V_88 = V_216 ;
V_36 -> V_93 = V_5 ;
F_60 ( & V_36 -> V_48 , V_119 , V_41 ) ;
F_61 ( & V_36 -> V_48 , & V_2 -> V_46 ) ;
V_2 -> V_91 += V_217 ;
V_2 -> V_90 ++ ;
F_16 ( & V_2 -> V_45 ) ;
F_40 ( V_78 , V_36 , V_219 ) ;
return V_36 ;
}
static T_1 F_106 ( struct V_1 * V_2 )
{
return V_2 -> V_167 - V_2 -> V_91 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_4 * V_5 = V_2 -> V_64 ;
const T_1 V_61 = V_2 -> V_62 ;
T_1 V_33 ;
unsigned int V_51 , V_63 , V_220 ;
T_4 * V_25 = NULL ;
T_4 * V_28 , * V_10 , * V_221 ;
T_1 V_52 , V_222 ;
struct V_35 * V_36 ;
T_1 V_223 , V_224 ;
int V_225 ;
if ( F_23 ( V_2 , V_78 -> V_226 ) )
V_52 = V_78 -> V_226 - V_2 -> V_44 ;
else
V_52 = V_2 -> V_227 ;
for ( V_51 = 0 ; V_51 < V_61 ; V_51 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
if ( V_52 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 ) {
V_52 -= V_5 -> V_24 * V_15 ;
goto V_228;
}
}
V_51 = 0 ;
V_52 = 0 ;
V_228:
V_225 = F_108 ( int , F_109 ( & V_78 -> V_80 -> V_229 ) ,
( V_230 * V_2 -> V_62 ) ) ;
V_223 = ( V_225 *
( 1 + ( V_231 * V_2 -> V_90 ) ) ) /
V_15 ;
V_223 = F_18 ( V_223 , sizeof( T_2 ) ) ;
V_224 = F_106 ( V_2 ) ;
if ( V_223 * V_15 > V_224 )
V_223 = V_224 >> V_16 ;
for ( V_63 = 0 ; V_63 <= V_61 ; V_63 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
if ( F_110 ( V_92 , & V_5 -> V_94 ) )
goto V_232;
F_80 ( ! F_81 ( V_5 -> V_17 ) ) ;
if ( V_5 -> V_76 )
V_25 = V_5 -> V_76 + V_5 -> V_19 ;
else
V_25 = V_5 -> V_17 -> V_18 + V_5 -> V_19 ;
V_28 = V_25 + F_18 ( V_52 >> V_16 , sizeof( T_2 ) ) ;
V_10 = ( V_25 + V_5 -> V_13 ) ;
while ( V_28 < V_10 ) {
V_222 = 0 ;
if ( ( V_28 + V_223 ) <= V_10 )
V_220 = V_223 ;
else
V_220 = V_10 - V_28 ;
F_2 ( ! V_220 ) ;
V_221 = F_111 ( V_28 , 0 , V_220 ) ;
if ( V_221 == NULL )
V_222 = V_220 ;
else if ( ( V_221 - V_28 ) * V_15 >=
V_78 -> V_80 -> V_233 )
V_222 = ( V_221 - V_28 ) ;
if ( V_222 ) {
V_33 = ( ( V_28 - V_25 ) * V_15 ) ;
F_2 ( V_33 >= V_5 -> V_13 * V_15 ) ;
V_36 = F_104 ( V_5 , V_78 , V_33 ,
V_222 * V_15 ) ;
if ( F_112 ( V_36 ) )
return F_113 ( V_36 ) ;
if ( V_36 )
return 0 ;
}
V_28 += F_18 ( V_220 , sizeof( T_2 ) ) ;
}
V_232:
V_51 ++ ;
V_51 %= V_61 ;
V_52 = 0 ;
}
return V_54 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_35 * V_36 = V_78 -> V_80 ;
if ( V_2 -> V_133 & ( V_234 | V_235 ) )
return 0 ;
if ( F_106 ( V_2 ) >= V_230 &&
F_107 ( V_2 , V_78 ) != V_54 )
return 1 ;
if ( F_106 ( V_2 ) >= V_36 -> V_233 )
return 1 ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , T_2 * V_236 , T_2 V_232 )
{
T_1 V_52 = 0 , V_6 ;
T_2 V_237 ;
struct V_59 * V_60 = V_2 -> V_27 ;
struct V_96 * V_97 ;
struct V_77 * V_78 ;
int error ;
int V_238 = 0 ;
struct V_4 * V_5 ;
while ( V_52 < V_2 -> V_66 ) {
F_33 ( & V_60 -> V_239 ) ;
V_6 = F_116 ( V_2 , V_52 , V_162 , & V_5 ) ;
F_35 ( & V_60 -> V_239 ) ;
if ( V_6 == V_54 )
break;
V_6 = F_105 ( V_5 , V_6 ) ;
V_237 = V_6 + V_2 -> V_44 ;
V_52 = F_117 ( V_6 + 1 , V_52 + 1 ) ;
if ( * V_236 != V_240 && V_237 <= * V_236 )
continue;
if ( V_237 == V_232 )
continue;
* V_236 = V_237 ;
error = F_66 ( V_60 , V_237 , & V_241 , V_129 , & V_97 ) ;
if ( error )
continue;
V_78 = V_97 -> V_100 ;
if ( V_78 || F_118 ( V_242 , & V_97 -> V_243 ) == 0 )
F_50 ( V_97 ) ;
else
V_238 ++ ;
if ( V_238 > V_244 )
return;
}
V_2 -> V_133 &= ~ V_166 ;
return;
}
int F_119 ( struct V_77 * V_78 , T_1 V_245 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
struct V_1 * V_246 = NULL ;
struct V_35 * V_36 = V_78 -> V_80 ;
int error = 0 , V_247 , V_248 = V_249 ;
T_2 V_236 = V_240 ;
int V_250 = 0 ;
if ( V_60 -> V_168 . V_169 )
V_248 |= V_173 ;
V_36 -> V_233 = V_245 ;
if ( F_87 ( V_60 , V_245 ) ) {
error = - V_106 ;
goto V_213;
}
if ( F_39 ( V_36 ) ) {
V_246 = V_36 -> V_87 ;
V_248 = 0 ;
} else if ( V_78 -> V_251 && F_23 ( V_78 -> V_251 , V_78 -> V_226 ) ) {
V_36 -> V_87 = V_246 = V_78 -> V_251 ;
} else {
V_36 -> V_87 = V_246 = F_24 ( V_60 , V_78 -> V_226 , 1 ) ;
}
if ( V_36 -> V_87 == NULL )
return - V_252 ;
while ( V_250 < 3 ) {
V_247 = 0 ;
if ( F_69 ( V_36 -> V_87 -> V_98 ) ) {
V_247 = 1 ;
error = 0 ;
} else if ( ! V_250 && ! F_39 ( V_36 ) &&
V_36 -> V_87 -> V_90 > V_253 ) {
error = V_254 ;
} else {
error = F_70 ( V_36 -> V_87 -> V_98 ,
V_212 , V_248 ,
& V_36 -> V_255 ) ;
if ( ! error && V_60 -> V_168 . V_169 ) {
error = F_88 ( V_36 -> V_87 ) ;
if ( error ) {
F_71 ( & V_36 -> V_255 ) ;
return error ;
}
}
}
switch ( error ) {
case 0 :
if ( F_39 ( V_36 ) ) {
if ( F_106 ( V_36 -> V_87 ) +
V_36 -> V_38 >= V_36 -> V_233 ) {
V_78 -> V_251 = V_36 -> V_87 ;
return 0 ;
}
F_45 ( V_36 ) ;
}
if ( F_114 ( V_36 -> V_87 , V_78 ) ) {
if ( V_60 -> V_168 . V_169 )
F_82 ( V_36 -> V_87 ) ;
V_78 -> V_251 = V_36 -> V_87 ;
return 0 ;
}
if ( V_36 -> V_87 -> V_133 & V_166 ) {
if ( V_60 -> V_168 . V_169 )
F_82 ( V_36 -> V_87 ) ;
F_115 ( V_36 -> V_87 , & V_236 ,
V_78 -> V_256 ) ;
}
if ( ! V_247 )
F_71 ( & V_36 -> V_255 ) ;
case V_254 :
V_36 -> V_87 = F_27 ( V_36 -> V_87 ) ;
V_36 -> V_87 = V_36 -> V_87 ? : V_246 ;
if ( V_36 -> V_87 != V_246 )
break;
V_248 &= ~ V_249 ;
V_250 ++ ;
if ( V_78 == F_55 ( V_60 -> V_114 ) &&
! V_60 -> V_136 ) {
error = F_67 ( V_78 ) ;
if ( error )
goto V_213;
} else if ( V_250 == 2 )
F_120 ( V_60 , NULL ) ;
break;
default:
goto V_213;
}
}
error = - V_257 ;
V_213:
if ( error )
V_36 -> V_233 = 0 ;
return error ;
}
void F_121 ( struct V_77 * V_78 )
{
struct V_35 * V_36 = V_78 -> V_80 ;
if ( ! V_36 )
return;
if ( ! V_36 -> V_38 )
F_45 ( V_36 ) ;
if ( V_36 -> V_255 . V_171 )
F_71 ( & V_36 -> V_255 ) ;
V_36 -> V_233 = 0 ;
}
static unsigned char F_122 ( struct V_1 * V_2 , T_2 V_6 )
{
struct V_4 * V_5 = NULL ;
T_1 V_61 , V_258 , V_259 ;
unsigned int V_51 ;
unsigned char type ;
V_61 = V_2 -> V_62 ;
V_258 = V_6 - V_2 -> V_44 ;
for ( V_51 = 0 ; V_51 < V_61 ; V_51 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
if ( V_258 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 )
break;
}
F_8 ( V_2 -> V_27 , V_51 < V_61 ) ;
V_259 = V_258 - V_5 -> V_24 * V_15 ;
type = F_7 ( V_2 , V_5 -> V_17 -> V_18 + V_5 -> V_19 ,
V_5 -> V_13 , V_259 ) ;
return type ;
}
static T_1 F_116 ( struct V_1 * V_2 , T_1 V_52 , unsigned char V_30 ,
struct V_4 * * V_260 )
{
struct V_4 * V_5 = NULL ;
const T_1 V_61 = V_2 -> V_62 ;
T_1 V_216 = V_54 ;
unsigned int V_51 , V_63 ;
const T_4 * V_25 = NULL ;
* V_260 = NULL ;
for ( V_51 = 0 ; V_51 < V_61 ; V_51 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
if ( V_52 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 ) {
V_52 -= V_5 -> V_24 * V_15 ;
goto V_228;
}
}
V_51 = 0 ;
V_52 = 0 ;
V_228:
for ( V_63 = 0 ; V_63 <= V_61 ; V_63 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
if ( F_110 ( V_92 , & V_5 -> V_94 ) &&
( V_30 == V_261 ) )
goto V_232;
V_25 = V_5 -> V_17 -> V_18 + V_5 -> V_19 ;
F_80 ( ! F_81 ( V_5 -> V_17 ) ) ;
if ( V_30 != V_162 && V_5 -> V_76 )
V_25 = V_5 -> V_76 + V_5 -> V_19 ;
while ( 1 ) {
struct V_35 * V_36 ;
T_1 V_39 ;
V_216 = F_17 ( V_25 , V_5 -> V_13 , V_52 , V_30 ) ;
if ( V_216 == V_54 )
break;
V_39 = F_105 ( V_5 , V_216 ) ;
V_36 = F_13 ( V_2 , V_39 ) ;
if ( V_36 == NULL )
break;
F_2 ( V_36 -> V_93 != V_5 ) ;
V_216 = V_54 ;
V_52 = V_36 -> V_88 + V_36 -> V_38 ;
if ( V_52 >= V_5 -> V_13 * V_15 )
break;
}
if ( V_216 != V_54 )
break;
if ( ( V_52 == 0 ) && ( V_30 == V_261 ) )
F_123 ( V_92 , & V_5 -> V_94 ) ;
V_232:
V_51 ++ ;
V_51 %= V_61 ;
V_52 = 0 ;
}
if ( V_216 != V_54 )
* V_260 = V_5 ;
return V_216 ;
}
static T_2 F_124 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_1 V_33 , bool V_262 , unsigned int * V_71 )
{
const unsigned int V_263 = * V_71 ;
T_1 V_52 , V_39 ;
const T_4 * V_25 = NULL ;
struct V_35 * V_36 ;
* V_71 = 0 ;
V_25 = V_5 -> V_17 -> V_18 + V_5 -> V_19 ;
F_101 ( V_2 -> V_98 , V_5 -> V_17 , 1 ) ;
F_1 ( V_2 , V_5 -> V_76 , V_5 , V_33 ,
V_262 ? V_264 : V_265 ) ;
( * V_71 ) ++ ;
V_52 = V_33 ;
while ( * V_71 < V_263 ) {
V_52 ++ ;
if ( V_52 >= ( V_5 -> V_13 * V_15 ) )
break;
V_39 = F_105 ( V_5 , V_52 ) ;
V_36 = F_13 ( V_2 , V_39 ) ;
if ( V_36 )
break;
if ( F_7 ( V_2 , V_25 , V_5 -> V_13 , V_52 ) !=
V_261 )
break;
F_1 ( V_2 , V_5 -> V_76 , V_5 , V_52 , V_265 ) ;
( * V_71 ) ++ ;
}
V_33 = F_105 ( V_5 , V_33 ) ;
V_2 -> V_227 = V_33 + * V_71 - 1 ;
return V_2 -> V_44 + V_33 ;
}
static struct V_1 * F_125 ( struct V_59 * V_60 , T_2 V_266 ,
T_1 V_267 , unsigned char V_7 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = NULL ;
T_1 V_61 , V_268 , V_269 ;
unsigned int V_51 ;
V_2 = F_24 ( V_60 , V_266 , 1 ) ;
if ( ! V_2 ) {
if ( F_126 ( V_60 ) )
F_22 ( V_60 , L_16 , ( unsigned long long ) V_266 ) ;
return NULL ;
}
V_61 = V_2 -> V_62 ;
V_268 = V_266 - V_2 -> V_44 ;
while ( V_267 -- ) {
for ( V_51 = 0 ; V_51 < V_61 ; V_51 ++ ) {
V_5 = V_2 -> V_64 + V_51 ;
if ( V_268 < ( V_5 -> V_24 + V_5 -> V_13 ) * V_15 )
break;
}
F_8 ( V_2 -> V_27 , V_51 < V_61 ) ;
V_269 = V_268 - V_5 -> V_24 * V_15 ;
V_268 ++ ;
if ( ! V_5 -> V_76 ) {
V_5 -> V_76 = F_127 ( V_5 -> V_17 -> V_270 ,
V_82 | V_271 ) ;
memcpy ( V_5 -> V_76 + V_5 -> V_19 ,
V_5 -> V_17 -> V_18 + V_5 -> V_19 ,
V_5 -> V_13 ) ;
}
F_101 ( V_2 -> V_98 , V_5 -> V_17 , 1 ) ;
F_1 ( V_2 , NULL , V_5 , V_269 , V_7 ) ;
}
return V_2 ;
}
int F_128 ( struct V_85 * V_86 , const struct V_96 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_100 ;
struct V_35 * V_272 ;
const struct V_40 * V_71 ;
if ( V_2 == NULL )
return 0 ;
F_37 ( V_86 , L_17 ,
( unsigned long long ) V_2 -> V_23 , V_2 -> V_133 ,
V_2 -> V_65 , V_2 -> V_167 , V_2 -> V_67 ,
V_2 -> V_91 ) ;
F_14 ( & V_2 -> V_45 ) ;
for ( V_71 = F_26 ( & V_2 -> V_46 ) ; V_71 ; V_71 = F_28 ( & V_272 -> V_48 ) ) {
V_272 = F_15 ( V_71 , struct V_35 , V_48 ) ;
F_36 ( V_86 , V_272 ) ;
}
F_16 ( & V_2 -> V_45 ) ;
return 0 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
F_94 ( V_60 , L_18 ,
( unsigned long long ) V_2 -> V_23 ) ;
F_94 ( V_60 , L_19 ) ;
F_128 ( NULL , V_2 -> V_98 ) ;
V_2 -> V_133 |= V_235 ;
}
static T_2 F_130 ( struct V_77 * V_78 , bool V_262 ,
unsigned int * V_273 )
{
struct V_35 * V_36 = V_78 -> V_80 ;
struct V_1 * V_2 = V_36 -> V_87 ;
struct V_4 * V_5 ;
T_2 V_274 = F_12 ( V_36 ) ;
const unsigned int V_263 = * V_273 ;
V_5 = V_36 -> V_93 ;
F_101 ( V_2 -> V_98 , V_5 -> V_17 , 1 ) ;
for ( * V_273 = 0 ; * V_273 < V_263 && V_36 -> V_38 ; ( * V_273 ) ++ ) {
if ( F_7 ( V_2 , V_5 -> V_17 -> V_18 + V_5 -> V_19 ,
V_5 -> V_13 , V_36 -> V_88 ) != V_261 )
break;
F_1 ( V_2 , V_5 -> V_76 , V_5 , V_36 -> V_88 ,
V_262 ? V_264 : V_265 ) ;
V_36 -> V_88 ++ ;
V_36 -> V_38 -- ;
F_2 ( ! V_2 -> V_91 ) ;
V_2 -> V_91 -- ;
V_262 = false ;
}
F_40 ( V_78 , V_36 , V_275 ) ;
if ( ! V_36 -> V_38 || * V_273 != V_263 )
F_45 ( V_36 ) ;
return V_274 ;
}
int F_131 ( struct V_77 * V_78 , T_2 * V_276 , unsigned int * V_273 ,
bool V_262 , T_2 * V_277 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
struct V_175 * V_278 ;
struct V_1 * V_2 ;
unsigned int V_279 ;
T_1 V_52 , V_33 ;
T_2 V_6 ;
int error ;
struct V_4 * V_5 ;
if ( V_78 -> V_80 -> V_233 == 0 )
return - V_280 ;
if ( F_39 ( V_78 -> V_80 ) ) {
F_2 ( ! V_78 -> V_80 -> V_38 ) ;
V_2 = V_78 -> V_80 -> V_87 ;
V_6 = F_130 ( V_78 , V_262 , V_273 ) ;
if ( * V_273 )
goto V_281;
}
V_2 = V_78 -> V_251 ;
if ( ! V_262 && F_23 ( V_2 , V_78 -> V_226 ) )
V_52 = V_78 -> V_226 - V_2 -> V_44 ;
else
V_52 = V_2 -> V_227 ;
V_33 = F_116 ( V_2 , V_52 , V_261 , & V_5 ) ;
if ( V_33 == V_54 ) {
F_4 ( V_22 L_20 , * V_273 ) ;
F_4 ( V_22 L_21 ,
F_110 ( V_92 , & V_2 -> V_64 -> V_94 ) ) ;
goto V_282;
}
V_6 = F_124 ( V_2 , V_5 , V_33 , V_262 , V_273 ) ;
V_281:
V_279 = * V_273 ;
if ( V_262 )
V_279 -- ;
if ( ! V_262 ) {
V_78 -> V_226 = V_6 + V_279 - 1 ;
error = F_132 ( V_78 , & V_278 ) ;
if ( error == 0 ) {
struct V_283 * V_284 =
(struct V_283 * ) V_278 -> V_18 ;
F_101 ( V_78 -> V_137 , V_278 , 1 ) ;
V_284 -> V_285 = V_284 -> V_286 =
F_75 ( V_78 -> V_226 ) ;
F_86 ( V_278 ) ;
}
}
if ( V_2 -> V_65 < * V_273 ) {
F_4 ( V_22 L_22 , * V_273 ) ;
goto V_282;
}
V_2 -> V_65 -= * V_273 ;
if ( V_262 ) {
V_2 -> V_67 ++ ;
* V_277 = V_2 -> V_147 ++ ;
if ( * V_277 == 0 )
* V_277 = V_2 -> V_147 ++ ;
}
F_101 ( V_2 -> V_98 , V_2 -> V_64 [ 0 ] . V_17 , 1 ) ;
F_73 ( V_2 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_77 ( V_2 -> V_130 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_133 ( V_60 , 0 , - ( V_287 ) * V_273 , V_262 ? 1 : 0 ) ;
if ( V_262 )
F_134 ( V_60 , V_6 , 1 ) ;
if ( V_279 )
F_135 ( V_78 , V_279 , V_78 -> V_122 . V_288 ,
V_78 -> V_122 . V_289 ) ;
V_2 -> V_167 -= * V_273 ;
F_136 ( V_78 , V_2 , V_6 , * V_273 ,
V_262 ? V_264 : V_265 ) ;
* V_276 = V_6 ;
return 0 ;
V_282:
F_129 ( V_2 ) ;
return - V_111 ;
}
void F_137 ( struct V_77 * V_78 , T_2 V_266 , T_1 V_267 , int V_290 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
struct V_1 * V_2 ;
V_2 = F_125 ( V_60 , V_266 , V_267 , V_261 ) ;
if ( ! V_2 )
return;
F_136 ( V_78 , V_2 , V_266 , V_267 , V_261 ) ;
V_2 -> V_65 += V_267 ;
V_2 -> V_133 &= ~ V_214 ;
F_101 ( V_2 -> V_98 , V_2 -> V_64 [ 0 ] . V_17 , 1 ) ;
F_73 ( V_2 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_77 ( V_2 -> V_130 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
if ( V_290 || V_78 -> V_291 )
F_138 ( V_78 , V_266 , V_267 ) ;
}
void F_139 ( struct V_77 * V_78 , T_2 V_266 , T_1 V_267 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
F_137 ( V_78 , V_266 , V_267 , 1 ) ;
F_133 ( V_60 , 0 , + V_267 , 0 ) ;
F_135 ( V_78 , - ( V_287 ) V_267 , V_78 -> V_122 . V_288 , V_78 -> V_122 . V_289 ) ;
}
void F_140 ( struct V_113 * V_113 )
{
struct V_77 * V_78 = F_55 ( V_113 ) ;
struct V_59 * V_60 = F_63 ( V_113 ) ;
struct V_1 * V_2 ;
T_2 V_292 = V_78 -> V_256 ;
V_2 = F_125 ( V_60 , V_292 , 1 , V_162 ) ;
if ( ! V_2 )
return;
F_136 ( V_78 , V_2 , V_292 , 1 , V_162 ) ;
F_101 ( V_2 -> V_98 , V_2 -> V_64 [ 0 ] . V_17 , 1 ) ;
F_73 ( V_2 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_77 ( V_2 -> V_130 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_78 ( V_2 , 1 ) ;
}
static void F_141 ( struct V_1 * V_2 , T_2 V_292 )
{
struct V_59 * V_60 = V_2 -> V_27 ;
struct V_1 * V_293 ;
V_293 = F_125 ( V_60 , V_292 , 1 , V_261 ) ;
if ( ! V_293 )
return;
F_142 ( V_60 , V_2 == V_293 ) ;
if ( ! V_2 -> V_67 )
F_6 ( V_2 ) ;
V_2 -> V_67 -- ;
V_2 -> V_65 ++ ;
F_101 ( V_2 -> V_98 , V_2 -> V_64 [ 0 ] . V_17 , 1 ) ;
F_73 ( V_2 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_77 ( V_2 -> V_130 , V_2 -> V_64 [ 0 ] . V_17 -> V_18 ) ;
F_78 ( V_2 , - 1 ) ;
F_133 ( V_60 , 0 , + 1 , - 1 ) ;
}
void F_143 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
F_141 ( V_2 , V_78 -> V_256 ) ;
F_136 ( V_78 , V_2 , V_78 -> V_256 , 1 , V_261 ) ;
F_135 ( V_78 , - 1 , V_78 -> V_122 . V_288 , V_78 -> V_122 . V_289 ) ;
F_138 ( V_78 , V_78 -> V_256 , 1 ) ;
}
int F_144 ( struct V_59 * V_60 , T_2 V_237 , unsigned int type )
{
struct V_1 * V_2 ;
struct V_138 V_294 ;
int error = - V_106 ;
V_2 = F_24 ( V_60 , V_237 , 1 ) ;
if ( ! V_2 )
goto V_127;
error = F_70 ( V_2 -> V_98 , V_141 , 0 , & V_294 ) ;
if ( error )
goto V_127;
if ( F_122 ( V_2 , V_237 ) != type )
error = - V_295 ;
F_71 ( & V_294 ) ;
V_127:
return error ;
}
void F_145 ( struct V_77 * V_78 , struct V_296 * V_297 ,
T_2 V_6 )
{
struct V_59 * V_60 = F_63 ( & V_78 -> V_122 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_31 ;
unsigned int V_298 ;
unsigned int V_63 ;
if ( F_87 ( V_60 , ! V_297 -> V_299 ) )
return;
if ( V_78 -> V_251 && F_23 ( V_78 -> V_251 , V_6 ) )
V_2 = V_78 -> V_251 ;
else
V_2 = F_24 ( V_60 , V_6 , 1 ) ;
if ( ! V_2 ) {
F_22 ( V_60 , L_23 , ( unsigned long long ) V_6 ) ;
return;
}
V_78 -> V_251 = V_2 ;
for ( V_63 = 0 ; V_63 < V_297 -> V_300 ; V_63 ++ )
if ( V_297 -> V_301 [ V_63 ] == V_2 )
return;
if ( V_297 -> V_300 == V_297 -> V_302 ) {
V_298 = V_297 -> V_302 + 10 ;
V_31 = F_53 ( V_298 , sizeof( struct V_1 * ) ,
V_82 | V_271 ) ;
if ( V_297 -> V_301 ) {
memcpy ( V_31 , V_297 -> V_301 ,
V_297 -> V_302 * sizeof( struct V_1 * ) ) ;
F_30 ( V_297 -> V_301 ) ;
}
V_297 -> V_302 = V_298 ;
V_297 -> V_301 = V_31 ;
}
V_297 -> V_301 [ V_297 -> V_300 ++ ] = V_2 ;
}
void F_146 ( struct V_296 * V_297 , unsigned int V_30 )
{
unsigned int V_63 ;
V_297 -> V_299 = F_53 ( V_297 -> V_300 , sizeof( struct V_138 ) ,
V_82 | V_271 ) ;
for ( V_63 = 0 ; V_63 < V_297 -> V_300 ; V_63 ++ )
F_147 ( V_297 -> V_301 [ V_63 ] -> V_98 ,
V_30 , 0 ,
& V_297 -> V_299 [ V_63 ] ) ;
}
void F_148 ( struct V_296 * V_297 )
{
unsigned int V_63 ;
F_30 ( V_297 -> V_301 ) ;
if ( V_297 -> V_299 ) {
for ( V_63 = 0 ; V_63 < V_297 -> V_300 ; V_63 ++ )
F_149 ( & V_297 -> V_299 [ V_63 ] ) ;
F_30 ( V_297 -> V_299 ) ;
V_297 -> V_299 = NULL ;
}
}
