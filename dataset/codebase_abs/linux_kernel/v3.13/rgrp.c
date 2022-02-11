static inline void F_1 ( const struct V_1 * V_2 , bool V_3 ,
unsigned char V_4 )
{
unsigned char * V_5 , * V_6 , * V_7 , V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned int V_11 = V_10 -> V_12 ;
const unsigned int V_13 = ( V_2 -> V_14 % V_15 ) * V_16 ;
V_5 = V_10 -> V_17 -> V_18 + V_10 -> V_19 + ( V_2 -> V_14 / V_15 ) ;
V_7 = V_10 -> V_17 -> V_18 + V_10 -> V_19 + V_11 ;
F_3 ( V_5 >= V_7 ) ;
V_8 = ( * V_5 >> V_13 ) & V_20 ;
if ( F_4 ( ! V_21 [ V_4 * 4 + V_8 ] ) ) {
F_5 ( V_22 L_1
L_2 , V_2 -> V_14 , V_8 , V_4 ) ;
F_5 ( V_22 L_3 ,
( unsigned long long ) V_2 -> V_23 -> V_24 , V_10 -> V_25 ) ;
F_5 ( V_22 L_4 ,
V_10 -> V_19 , V_10 -> V_12 ) ;
F_6 () ;
F_7 ( V_2 -> V_23 ) ;
return;
}
* V_5 ^= ( V_8 ^ V_4 ) << V_13 ;
if ( V_3 && V_10 -> V_26 ) {
V_6 = V_10 -> V_26 + V_10 -> V_19 + ( V_2 -> V_14 / V_15 ) ;
V_8 = ( * V_6 >> V_13 ) & V_20 ;
* V_6 ^= ( V_8 ^ V_4 ) << V_13 ;
}
}
static inline T_1 F_8 ( const struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
const T_1 * V_27 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
const T_1 * V_28 ;
unsigned int V_13 ;
V_28 = V_27 + ( V_2 -> V_14 / V_15 ) ;
V_13 = ( V_2 -> V_14 % V_15 ) * V_16 ;
return ( * V_28 >> V_13 ) & V_20 ;
}
static inline T_2 F_9 ( const T_3 * V_29 , T_2 V_30 , T_1 V_31 )
{
T_2 V_32 ;
static const T_2 V_33 [] = {
[ 0 ] = 0xffffffffffffffffULL ,
[ 1 ] = 0xaaaaaaaaaaaaaaaaULL ,
[ 2 ] = 0x5555555555555555ULL ,
[ 3 ] = 0x0000000000000000ULL ,
} ;
V_32 = F_10 ( * V_29 ) ^ V_33 [ V_31 ] ;
V_32 &= ( V_32 >> 1 ) ;
V_32 &= V_30 ;
return V_32 ;
}
static inline int F_11 ( T_2 V_34 , T_4 V_35 , struct V_36 * V_37 )
{
T_2 V_38 = F_12 ( & V_37 -> V_39 ) ;
if ( V_34 >= V_38 + V_37 -> V_40 )
return 1 ;
if ( V_34 + V_35 - 1 < V_38 )
return - 1 ;
return 0 ;
}
static T_4 F_13 ( const T_1 * V_41 , const unsigned int V_35 ,
T_4 V_42 , T_1 V_31 )
{
T_4 V_43 = ( V_42 << 1 ) & ( ( 8 * sizeof( T_2 ) ) - 1 ) ;
const T_3 * V_29 = ( ( T_3 * ) V_41 ) + ( V_42 >> 5 ) ;
const T_3 * V_7 = ( T_3 * ) ( V_41 + F_14 ( V_35 , sizeof( T_2 ) ) ) ;
T_2 V_32 ;
T_2 V_30 = 0x5555555555555555ULL ;
T_4 V_13 ;
V_30 <<= V_43 ;
V_32 = F_9 ( V_29 , V_30 , V_31 ) ;
V_29 ++ ;
while( V_32 == 0 && V_29 < V_7 ) {
V_32 = F_9 ( V_29 , 0x5555555555555555ULL , V_31 ) ;
V_29 ++ ;
}
if ( V_29 == V_7 && ( V_35 & ( sizeof( T_2 ) - 1 ) ) )
V_32 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_35 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_32 == 0 )
return V_44 ;
V_29 -- ;
V_13 = F_15 ( V_32 ) ;
V_13 /= 2 ;
return ( ( ( const unsigned char * ) V_29 - V_41 ) * V_15 ) + V_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_45 )
{
T_2 V_46 = V_45 - V_2 -> V_23 -> V_47 ;
if ( F_17 ( V_46 > V_48 ) )
return - V_49 ;
if ( V_45 >= V_2 -> V_23 -> V_47 + V_2 -> V_23 -> V_50 )
return - V_51 ;
V_2 -> V_52 = 0 ;
V_2 -> V_14 = ( T_4 ) ( V_46 ) ;
if ( V_2 -> V_14 < F_2 ( V_2 ) -> V_53 )
return 0 ;
V_2 -> V_14 += ( sizeof( struct V_54 ) -
sizeof( struct V_55 ) ) * V_15 ;
V_2 -> V_52 = V_2 -> V_14 / V_2 -> V_23 -> V_56 -> V_57 ;
V_2 -> V_14 -= V_2 -> V_52 * V_2 -> V_23 -> V_56 -> V_57 ;
return 0 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 + 1 < F_2 ( V_2 ) -> V_53 ) {
V_2 -> V_14 ++ ;
return false ;
}
if ( V_2 -> V_52 == V_2 -> V_23 -> V_58 - 1 )
return true ;
V_2 -> V_14 = 0 ;
V_2 -> V_52 ++ ;
return false ;
}
static bool F_19 ( struct V_1 * V_2 , T_4 V_59 , T_4 * V_35 )
{
T_4 V_60 ;
T_1 V_61 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_61 = F_8 ( V_2 ) ;
if ( V_61 != V_62 )
return true ;
( * V_35 ) -- ;
if ( * V_35 == 0 )
return true ;
if ( F_18 ( V_2 ) )
return true ;
}
return false ;
}
static T_4 F_20 ( const struct V_1 * V_63 , T_4 V_35 )
{
struct V_1 V_2 = * V_63 ;
T_4 V_59 = V_2 . V_14 & 3 ;
T_4 V_64 = V_35 ;
T_4 V_65 ;
T_4 V_66 ;
T_1 * V_29 , * V_67 , * V_7 ;
T_2 V_45 ;
struct V_9 * V_10 ;
if ( V_59 &&
F_19 ( & V_2 , 4 - V_59 , & V_35 ) )
goto V_68;
V_59 = V_35 & 3 ;
while ( V_35 > 3 ) {
V_10 = F_2 ( & V_2 ) ;
V_67 = V_10 -> V_17 -> V_18 ;
if ( V_10 -> V_26 )
V_67 = V_10 -> V_26 ;
V_7 = V_67 + V_10 -> V_17 -> V_69 ;
V_67 += V_10 -> V_19 ;
F_3 ( V_2 . V_14 & 3 ) ;
V_67 += ( V_2 . V_14 / V_15 ) ;
V_65 = F_21 ( T_4 , V_35 / V_15 , ( V_7 - V_67 ) ) ;
V_29 = F_22 ( V_67 , 0 , V_65 ) ;
V_66 = ( ( V_29 == NULL ) ? V_65 : ( V_29 - V_67 ) ) ;
V_66 *= V_15 ;
F_3 ( V_35 < V_66 ) ;
V_35 -= V_66 ;
V_45 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_45 + V_66 ) ) {
V_59 = 0 ;
break;
}
if ( V_29 ) {
V_59 = 3 ;
break;
}
V_59 = V_35 & 3 ;
}
if ( V_59 )
F_19 ( & V_2 , V_59 , & V_35 ) ;
V_68:
return V_64 - V_35 ;
}
static T_4 F_23 ( struct V_70 * V_23 , const T_1 * V_27 ,
unsigned int V_11 , T_1 V_31 )
{
const T_1 * V_28 = V_27 ;
const T_1 * V_7 = V_27 + V_11 ;
const T_1 V_71 = V_31 << 2 ;
const T_1 V_72 = V_31 << 4 ;
const T_1 V_73 = V_31 << 6 ;
T_4 V_74 = 0 ;
for (; V_28 < V_7 ; V_28 ++ ) {
if ( ( ( * V_28 ) & 0x03 ) == V_31 )
V_74 ++ ;
if ( ( ( * V_28 ) & 0x0C ) == V_71 )
V_74 ++ ;
if ( ( ( * V_28 ) & 0x30 ) == V_72 )
V_74 ++ ;
if ( ( ( * V_28 ) & 0xC0 ) == V_73 )
V_74 ++ ;
}
return V_74 ;
}
void F_24 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_9 * V_10 = NULL ;
T_4 V_77 = V_23 -> V_58 ;
T_4 V_74 [ 4 ] , V_32 ;
int V_41 , V_78 ;
memset ( V_74 , 0 , 4 * sizeof( T_4 ) ) ;
for ( V_41 = 0 ; V_41 < V_77 ; V_41 ++ ) {
V_10 = V_23 -> V_79 + V_41 ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ )
V_74 [ V_78 ] += F_23 ( V_23 ,
V_10 -> V_17 -> V_18 +
V_10 -> V_19 ,
V_10 -> V_12 , V_78 ) ;
}
if ( V_74 [ 0 ] != V_23 -> V_80 ) {
if ( F_7 ( V_23 ) )
F_25 ( V_76 , L_5 ,
V_74 [ 0 ] , V_23 -> V_80 ) ;
return;
}
V_32 = V_23 -> V_50 - V_23 -> V_80 - V_23 -> V_81 ;
if ( V_74 [ 1 ] != V_32 ) {
if ( F_7 ( V_23 ) )
F_25 ( V_76 , L_6 ,
V_74 [ 1 ] , V_32 ) ;
return;
}
if ( V_74 [ 2 ] + V_74 [ 3 ] != V_23 -> V_81 ) {
if ( F_7 ( V_23 ) )
F_25 ( V_76 , L_7 ,
V_74 [ 2 ] + V_74 [ 3 ] , V_23 -> V_81 ) ;
return;
}
}
static inline int F_26 ( struct V_70 * V_23 , T_2 V_45 )
{
T_2 V_82 = V_23 -> V_47 ;
T_2 V_83 = V_82 + V_23 -> V_50 ;
return V_82 <= V_45 && V_45 < V_83 ;
}
struct V_70 * F_27 ( struct V_75 * V_76 , T_2 V_34 , bool V_84 )
{
struct V_85 * V_60 , * V_86 ;
struct V_70 * V_87 ;
F_28 ( & V_76 -> V_88 ) ;
V_60 = V_76 -> V_89 . V_85 ;
while ( V_60 ) {
V_87 = F_29 ( V_60 , struct V_70 , V_90 ) ;
V_86 = NULL ;
if ( V_34 < V_87 -> V_24 )
V_86 = V_60 -> V_91 ;
else if ( V_34 >= V_87 -> V_47 + V_87 -> V_50 )
V_86 = V_60 -> V_92 ;
if ( V_86 == NULL ) {
F_30 ( & V_76 -> V_88 ) ;
if ( V_84 ) {
if ( V_34 < V_87 -> V_24 )
return NULL ;
if ( V_34 >= V_87 -> V_47 + V_87 -> V_50 )
return NULL ;
}
return V_87 ;
}
V_60 = V_86 ;
}
F_30 ( & V_76 -> V_88 ) ;
return NULL ;
}
struct V_70 * F_31 ( struct V_75 * V_76 )
{
const struct V_85 * V_60 ;
struct V_70 * V_23 ;
F_28 ( & V_76 -> V_88 ) ;
V_60 = F_32 ( & V_76 -> V_89 ) ;
V_23 = F_29 ( V_60 , struct V_70 , V_90 ) ;
F_30 ( & V_76 -> V_88 ) ;
return V_23 ;
}
struct V_70 * F_33 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
const struct V_85 * V_60 ;
F_28 ( & V_76 -> V_88 ) ;
V_60 = F_34 ( & V_23 -> V_90 ) ;
if ( V_60 == NULL )
V_60 = F_32 ( & V_76 -> V_89 ) ;
if ( F_4 ( & V_23 -> V_90 == V_60 ) ) {
F_30 ( & V_76 -> V_88 ) ;
return NULL ;
}
V_23 = F_29 ( V_60 , struct V_70 , V_90 ) ;
F_30 ( & V_76 -> V_88 ) ;
return V_23 ;
}
void F_35 ( struct V_70 * V_23 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_23 -> V_58 ; V_78 ++ ) {
struct V_9 * V_10 = V_23 -> V_79 + V_78 ;
F_36 ( V_10 -> V_26 ) ;
V_10 -> V_26 = NULL ;
}
}
int F_37 ( struct V_93 * V_94 )
{
int error = 0 ;
F_38 ( & V_94 -> V_95 ) ;
if ( V_94 -> V_96 )
goto V_68;
V_94 -> V_96 = F_39 ( V_97 , V_98 ) ;
if ( ! V_94 -> V_96 ) {
error = - V_99 ;
goto V_68;
}
F_40 ( & V_94 -> V_96 -> V_100 ) ;
V_68:
F_41 ( & V_94 -> V_95 ) ;
return error ;
}
static void F_42 ( struct V_101 * V_102 , const struct V_36 * V_37 )
{
F_43 ( V_102 , L_8 ,
( unsigned long long ) V_37 -> V_103 ,
( unsigned long long ) F_12 ( & V_37 -> V_39 ) ,
V_37 -> V_39 . V_14 , V_37 -> V_40 ) ;
}
static void F_44 ( struct V_36 * V_37 )
{
struct V_70 * V_23 ;
if ( ! F_45 ( V_37 ) )
return;
V_23 = V_37 -> V_39 . V_23 ;
F_46 ( V_37 , V_104 ) ;
F_47 ( & V_37 -> V_100 , & V_23 -> V_105 ) ;
F_40 ( & V_37 -> V_100 ) ;
if ( V_37 -> V_40 ) {
struct V_9 * V_10 = F_2 ( & V_37 -> V_39 ) ;
F_3 ( V_37 -> V_39 . V_23 -> V_106 < V_37 -> V_40 ) ;
V_37 -> V_39 . V_23 -> V_106 -= V_37 -> V_40 ;
V_37 -> V_40 = 0 ;
F_48 ( V_107 , & V_10 -> V_108 ) ;
F_49 () ;
}
}
void F_50 ( struct V_36 * V_37 )
{
struct V_70 * V_23 ;
V_23 = V_37 -> V_39 . V_23 ;
if ( V_23 ) {
F_28 ( & V_23 -> V_109 ) ;
F_44 ( V_37 ) ;
F_30 ( & V_23 -> V_109 ) ;
}
}
void F_51 ( struct V_93 * V_94 , T_5 * V_110 )
{
F_38 ( & V_94 -> V_95 ) ;
if ( V_94 -> V_96 && ( ( V_110 == NULL ) || ( F_52 ( V_110 ) <= 1 ) ) ) {
F_50 ( V_94 -> V_96 ) ;
F_3 ( V_94 -> V_96 -> V_40 ) ;
F_53 ( V_97 , V_94 -> V_96 ) ;
V_94 -> V_96 = NULL ;
}
F_41 ( & V_94 -> V_95 ) ;
}
static void F_54 ( struct V_70 * V_23 )
{
struct V_85 * V_60 ;
struct V_36 * V_37 ;
F_28 ( & V_23 -> V_109 ) ;
while ( ( V_60 = F_32 ( & V_23 -> V_105 ) ) ) {
V_37 = F_29 ( V_60 , struct V_36 , V_100 ) ;
F_44 ( V_37 ) ;
}
F_30 ( & V_23 -> V_109 ) ;
}
void F_55 ( struct V_75 * V_76 )
{
struct V_85 * V_60 ;
struct V_70 * V_23 ;
struct V_111 * V_112 ;
while ( ( V_60 = F_32 ( & V_76 -> V_89 ) ) ) {
V_23 = F_29 ( V_60 , struct V_70 , V_90 ) ;
V_112 = V_23 -> V_113 ;
F_47 ( V_60 , & V_76 -> V_89 ) ;
if ( V_112 ) {
F_28 ( & V_112 -> V_114 ) ;
V_112 -> V_115 = NULL ;
F_30 ( & V_112 -> V_114 ) ;
F_56 ( V_112 ) ;
F_57 ( V_112 ) ;
}
F_35 ( V_23 ) ;
F_36 ( V_23 -> V_79 ) ;
F_54 ( V_23 ) ;
F_53 ( V_116 , V_23 ) ;
}
}
static void F_58 ( const struct V_70 * V_23 )
{
F_5 ( V_117 L_9 , ( unsigned long long ) V_23 -> V_24 ) ;
F_5 ( V_117 L_10 , V_23 -> V_58 ) ;
F_5 ( V_117 L_11 , ( unsigned long long ) V_23 -> V_47 ) ;
F_5 ( V_117 L_12 , V_23 -> V_50 ) ;
F_5 ( V_117 L_13 , V_23 -> V_118 ) ;
}
static int F_59 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_9 * V_10 ;
T_4 V_77 = V_23 -> V_58 ;
T_4 V_119 , V_65 ;
int V_78 ;
if ( ! V_77 )
return - V_49 ;
V_23 -> V_79 = F_60 ( V_77 , sizeof( struct V_9 ) , V_98 ) ;
if ( ! V_23 -> V_79 )
return - V_99 ;
V_119 = V_23 -> V_118 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
V_10 = V_23 -> V_79 + V_78 ;
V_10 -> V_108 = 0 ;
if ( V_77 == 1 ) {
V_65 = V_119 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_25 = 0 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
} else if ( V_78 == 0 ) {
V_65 = V_76 -> V_120 . V_121 - sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_25 = 0 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
} else if ( V_78 + 1 == V_77 ) {
V_65 = V_119 ;
V_10 -> V_19 = sizeof( struct V_55 ) ;
V_10 -> V_25 = V_23 -> V_118 - V_119 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
} else {
V_65 = V_76 -> V_120 . V_121 -
sizeof( struct V_55 ) ;
V_10 -> V_19 = sizeof( struct V_55 ) ;
V_10 -> V_25 = V_23 -> V_118 - V_119 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
}
V_119 -= V_65 ;
}
if ( V_119 ) {
F_7 ( V_23 ) ;
return - V_122 ;
}
V_10 = V_23 -> V_79 + ( V_77 - 1 ) ;
if ( ( V_10 -> V_25 + V_10 -> V_12 ) * V_15 != V_23 -> V_50 ) {
if ( F_7 ( V_23 ) ) {
F_58 ( V_23 ) ;
F_25 ( V_76 , L_14 ,
V_10 -> V_25 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_122 ;
}
return 0 ;
}
T_2 F_61 ( struct V_75 * V_76 )
{
T_2 V_123 = 0 ;
struct V_124 * V_124 = V_76 -> V_125 ;
struct V_93 * V_94 = F_62 ( V_124 ) ;
char V_41 [ sizeof( struct V_126 ) ] ;
int error , V_127 ;
for ( V_127 = 0 ; ; V_127 ++ ) {
T_6 V_128 = V_127 * sizeof( struct V_126 ) ;
if ( V_128 + sizeof( struct V_126 ) > F_63 ( V_124 ) )
break;
error = F_64 ( V_94 , V_41 , & V_128 ,
sizeof( struct V_126 ) ) ;
if ( error != sizeof( struct V_126 ) )
break;
V_123 += F_65 ( ( (struct V_126 * ) V_41 ) -> V_129 ) ;
}
return V_123 ;
}
static int F_66 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_85 * * V_130 = & V_76 -> V_89 . V_85 , * V_131 = NULL ;
while ( * V_130 ) {
struct V_70 * V_87 = F_29 ( * V_130 , struct V_70 ,
V_90 ) ;
V_131 = * V_130 ;
if ( V_23 -> V_24 < V_87 -> V_24 )
V_130 = & ( ( * V_130 ) -> V_91 ) ;
else if ( V_23 -> V_24 > V_87 -> V_24 )
V_130 = & ( ( * V_130 ) -> V_92 ) ;
else
return - V_132 ;
}
F_67 ( & V_23 -> V_90 , V_131 , V_130 ) ;
F_68 ( & V_23 -> V_90 , & V_76 -> V_89 ) ;
V_76 -> V_133 ++ ;
return 0 ;
}
static int F_69 ( struct V_93 * V_94 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
T_6 V_128 = V_76 -> V_133 * sizeof( struct V_126 ) ;
struct V_126 V_41 ;
int error ;
struct V_70 * V_23 ;
if ( V_128 >= F_63 ( & V_94 -> V_134 ) )
return 1 ;
error = F_64 ( V_94 , ( char * ) & V_41 , & V_128 ,
sizeof( struct V_126 ) ) ;
if ( error != sizeof( struct V_126 ) )
return ( error == 0 ) ? 1 : error ;
V_23 = F_39 ( V_116 , V_98 ) ;
error = - V_99 ;
if ( ! V_23 )
return error ;
V_23 -> V_56 = V_76 ;
V_23 -> V_24 = F_71 ( V_41 . V_135 ) ;
V_23 -> V_58 = F_65 ( V_41 . V_136 ) ;
V_23 -> V_47 = F_71 ( V_41 . V_137 ) ;
V_23 -> V_50 = F_65 ( V_41 . V_129 ) ;
V_23 -> V_118 = F_65 ( V_41 . V_138 ) ;
F_72 ( & V_23 -> V_109 ) ;
error = F_59 ( V_23 ) ;
if ( error )
goto V_139;
error = F_73 ( V_76 , V_23 -> V_24 ,
& V_140 , V_141 , & V_23 -> V_113 ) ;
if ( error )
goto V_139;
V_23 -> V_113 -> V_115 = V_23 ;
V_23 -> V_142 = (struct V_143 * ) V_23 -> V_113 -> V_144 . V_145 ;
V_23 -> V_146 &= ~ V_147 ;
if ( V_23 -> V_50 > V_76 -> V_148 )
V_76 -> V_148 = V_23 -> V_50 ;
F_28 ( & V_76 -> V_88 ) ;
error = F_66 ( V_23 ) ;
F_30 ( & V_76 -> V_88 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_57 ( V_23 -> V_113 ) ;
V_139:
F_36 ( V_23 -> V_79 ) ;
F_53 ( V_116 , V_23 ) ;
return error ;
}
static int F_74 ( struct V_93 * V_94 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
int error ;
do {
error = F_69 ( V_94 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_76 -> V_149 = 1 ;
return 0 ;
}
int F_75 ( struct V_75 * V_76 )
{
struct V_93 * V_94 = F_62 ( V_76 -> V_125 ) ;
struct V_111 * V_112 = V_94 -> V_150 ;
struct V_151 V_152 ;
int error = 0 ;
int V_153 = 0 ;
if ( ! V_76 -> V_149 ) {
if ( ! F_76 ( V_112 ) ) {
error = F_77 ( V_112 , V_154 , 0 , & V_152 ) ;
if ( error )
return error ;
V_153 = 1 ;
}
if ( ! V_76 -> V_149 )
error = F_74 ( V_94 ) ;
if ( V_153 )
F_78 ( & V_152 ) ;
}
return error ;
}
static void F_79 ( struct V_70 * V_23 , const void * V_41 )
{
const struct V_54 * V_155 = V_41 ;
T_4 V_156 ;
V_156 = F_65 ( V_155 -> V_156 ) ;
V_156 &= ~ V_157 ;
V_23 -> V_146 &= V_157 ;
V_23 -> V_146 |= V_156 ;
V_23 -> V_80 = F_65 ( V_155 -> V_158 ) ;
V_23 -> V_81 = F_65 ( V_155 -> V_159 ) ;
V_23 -> V_160 = F_71 ( V_155 -> V_161 ) ;
}
static void F_80 ( struct V_70 * V_23 , void * V_41 )
{
struct V_54 * V_155 = V_41 ;
V_155 -> V_156 = F_81 ( V_23 -> V_146 & ~ V_157 ) ;
V_155 -> V_158 = F_81 ( V_23 -> V_80 ) ;
V_155 -> V_159 = F_81 ( V_23 -> V_81 ) ;
V_155 -> V_162 = F_81 ( 0 ) ;
V_155 -> V_161 = F_82 ( V_23 -> V_160 ) ;
memset ( & V_155 -> V_163 , 0 , sizeof( V_155 -> V_163 ) ) ;
}
static int F_83 ( struct V_70 * V_23 )
{
struct V_143 * V_164 = V_23 -> V_142 ;
struct V_54 * V_155 = (struct V_54 * ) V_23 -> V_79 [ 0 ] . V_17 -> V_18 ;
if ( V_164 -> V_165 != V_155 -> V_156 || V_164 -> V_166 != V_155 -> V_158 ||
V_164 -> V_167 != V_155 -> V_159 ||
V_164 -> V_168 != V_155 -> V_161 )
return 0 ;
return 1 ;
}
static void F_84 ( struct V_143 * V_164 , const void * V_41 )
{
const struct V_54 * V_155 = V_41 ;
V_164 -> V_169 = F_81 ( V_170 ) ;
V_164 -> V_165 = V_155 -> V_156 ;
V_164 -> V_166 = V_155 -> V_158 ;
V_164 -> V_167 = V_155 -> V_159 ;
V_164 -> V_168 = V_155 -> V_161 ;
V_164 -> V_162 = 0UL ;
}
static void F_85 ( struct V_70 * V_23 , T_4 V_171 )
{
struct V_143 * V_164 = V_23 -> V_142 ;
T_4 V_172 = F_65 ( V_164 -> V_173 ) + V_171 ;
V_164 -> V_173 = F_81 ( V_172 ) ;
}
static T_4 F_86 ( struct V_70 * V_23 )
{
struct V_9 * V_10 ;
const T_4 V_77 = V_23 -> V_58 ;
const T_1 * V_27 = NULL ;
T_4 V_174 , V_42 , V_74 = 0 ;
for ( V_174 = 0 , V_10 = V_23 -> V_79 ; V_174 < V_77 ; V_174 ++ , V_10 ++ ) {
V_42 = 0 ;
V_27 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_87 ( ! F_88 ( V_10 -> V_17 ) ) ;
while ( V_42 < V_10 -> V_12 * V_15 ) {
V_42 = F_13 ( V_27 , V_10 -> V_12 , V_42 ,
V_175 ) ;
if ( V_42 == V_44 )
break;
V_74 ++ ;
V_42 ++ ;
}
}
return V_74 ;
}
int F_89 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_111 * V_112 = V_23 -> V_113 ;
unsigned int V_77 = V_23 -> V_58 ;
struct V_9 * V_10 ;
unsigned int V_78 , V_176 ;
int error ;
if ( V_23 -> V_79 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
V_10 = V_23 -> V_79 + V_78 ;
error = F_90 ( V_112 , V_23 -> V_24 + V_78 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_139;
}
for ( V_176 = V_77 ; V_176 -- ; ) {
V_10 = V_23 -> V_79 + V_176 ;
error = F_91 ( V_76 , V_10 -> V_17 ) ;
if ( error )
goto V_139;
if ( F_92 ( V_76 , V_10 -> V_17 , V_176 ? V_177 :
V_178 ) ) {
error = - V_122 ;
goto V_139;
}
}
if ( ! ( V_23 -> V_146 & V_147 ) ) {
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
F_48 ( V_107 , & V_23 -> V_79 [ V_78 ] . V_108 ) ;
F_79 ( V_23 , ( V_23 -> V_79 [ 0 ] . V_17 ) -> V_18 ) ;
V_23 -> V_146 |= ( V_147 | V_179 ) ;
V_23 -> V_180 = V_23 -> V_80 ;
}
if ( F_81 ( V_170 ) != V_23 -> V_142 -> V_169 ) {
V_23 -> V_142 -> V_173 = F_81 ( F_86 ( V_23 ) ) ;
F_84 ( V_23 -> V_142 ,
V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_76 -> V_181 . V_182 ) {
if ( ! F_83 ( V_23 ) ) {
F_7 ( V_23 ) ;
error = - V_122 ;
goto V_139;
}
if ( V_23 -> V_142 -> V_173 == 0 )
V_23 -> V_146 &= ~ V_179 ;
}
return 0 ;
V_139:
while ( V_78 -- ) {
V_10 = V_23 -> V_79 + V_78 ;
F_93 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_94 ( V_76 , ! V_10 -> V_26 ) ;
}
return error ;
}
int F_95 ( struct V_70 * V_23 )
{
T_4 V_165 ;
if ( V_23 -> V_146 & V_147 )
return 0 ;
if ( F_81 ( V_170 ) != V_23 -> V_142 -> V_169 )
return F_89 ( V_23 ) ;
V_165 = F_65 ( V_23 -> V_142 -> V_165 ) ;
V_165 &= ~ V_157 ;
V_23 -> V_146 &= V_157 ;
V_23 -> V_146 |= ( V_165 | V_147 | V_179 ) ;
if ( V_23 -> V_142 -> V_173 == 0 )
V_23 -> V_146 &= ~ V_179 ;
V_23 -> V_80 = F_65 ( V_23 -> V_142 -> V_166 ) ;
V_23 -> V_180 = V_23 -> V_80 ;
V_23 -> V_81 = F_65 ( V_23 -> V_142 -> V_167 ) ;
V_23 -> V_160 = F_71 ( V_23 -> V_142 -> V_168 ) ;
return 0 ;
}
int F_96 ( struct V_151 * V_183 )
{
struct V_70 * V_23 = V_183 -> V_184 -> V_115 ;
struct V_75 * V_76 = V_23 -> V_56 ;
if ( V_183 -> V_185 & V_186 && V_76 -> V_181 . V_182 )
return 0 ;
return F_89 ( (struct V_70 * ) V_183 -> V_184 -> V_115 ) ;
}
void F_97 ( struct V_151 * V_183 )
{
struct V_70 * V_23 = V_183 -> V_184 -> V_115 ;
int V_78 , V_77 = V_23 -> V_58 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
struct V_9 * V_10 = V_23 -> V_79 + V_78 ;
if ( V_10 -> V_17 ) {
F_93 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
int F_98 ( struct V_75 * V_76 , T_2 V_14 ,
struct V_187 * V_188 ,
const struct V_9 * V_10 , unsigned V_189 , T_2 * V_190 )
{
struct V_191 * V_192 = V_76 -> V_193 ;
T_2 V_34 ;
T_7 V_67 = 0 ;
T_7 V_194 = 0 ;
int V_195 ;
unsigned int V_78 ;
T_4 V_196 = 0 ;
T_1 V_197 ;
for ( V_78 = 0 ; V_78 < V_10 -> V_12 ; V_78 ++ ) {
const T_1 * V_198 = V_10 -> V_26 ? V_10 -> V_26 : V_10 -> V_17 -> V_18 ;
V_198 += V_10 -> V_19 ;
V_198 += V_78 ;
if ( V_188 ) {
const T_1 * V_199 = V_188 -> V_18 + V_10 -> V_19 + V_78 ;
V_197 = ~ ( * V_199 | ( * V_199 >> 1 ) ) & ( * V_198 | ( * V_198 >> 1 ) ) ;
} else {
V_197 = ~ ( * V_198 | ( * V_198 >> 1 ) ) ;
}
V_197 &= 0x55 ;
if ( V_197 == 0 )
continue;
V_34 = V_14 + ( ( V_10 -> V_25 + V_78 ) * V_15 ) ;
while( V_197 ) {
if ( V_197 & 1 ) {
if ( V_194 == 0 )
goto V_200;
if ( ( V_67 + V_194 ) != V_34 ) {
if ( V_194 >= V_189 ) {
V_195 = F_99 ( V_192 ,
V_67 , V_194 ,
V_98 , 0 ) ;
if ( V_195 )
goto V_139;
V_196 += V_194 ;
}
V_194 = 0 ;
V_200:
V_67 = V_34 ;
}
V_194 ++ ;
}
V_197 >>= 2 ;
V_34 ++ ;
}
}
if ( V_194 >= V_189 ) {
V_195 = F_99 ( V_192 , V_67 , V_194 , V_98 , 0 ) ;
if ( V_195 )
goto V_139;
V_196 += V_194 ;
}
if ( V_190 )
* V_190 = V_196 ;
return 0 ;
V_139:
if ( V_76 -> V_181 . V_201 )
F_100 ( V_76 , L_15 , V_195 ) ;
V_76 -> V_181 . V_201 = 0 ;
return - V_122 ;
}
int F_101 ( struct V_202 * V_203 , void T_8 * V_204 )
{
struct V_124 * V_124 = F_102 ( V_203 ) ;
struct V_75 * V_76 = F_70 ( V_124 ) ;
struct V_205 * V_206 = F_103 ( V_76 -> V_193 -> V_207 ) ;
struct V_187 * V_188 ;
struct V_70 * V_23 ;
struct V_70 * V_208 ;
struct V_151 V_183 ;
struct V_209 V_210 ;
int V_211 = 0 ;
T_2 V_212 ;
T_2 V_196 = 0 ;
T_2 V_67 , V_7 , V_189 ;
unsigned int V_78 ;
unsigned V_213 = V_76 -> V_120 . V_214 ;
if ( ! F_104 ( V_215 ) )
return - V_216 ;
if ( ! F_105 ( V_206 ) )
return - V_217 ;
if ( F_106 ( & V_210 , V_204 , sizeof( V_210 ) ) )
return - V_218 ;
V_211 = F_75 ( V_76 ) ;
if ( V_211 )
return V_211 ;
V_67 = V_210 . V_67 >> V_213 ;
V_7 = V_67 + ( V_210 . V_35 >> V_213 ) ;
V_189 = F_107 ( T_2 , V_210 . V_189 ,
V_206 -> V_219 . V_220 ) >> V_213 ;
if ( V_7 <= V_67 || V_189 > V_76 -> V_148 )
return - V_49 ;
V_23 = F_27 ( V_76 , V_67 , 0 ) ;
V_208 = F_27 ( V_76 , V_7 , 0 ) ;
if ( ( F_31 ( V_76 ) == F_33 ( V_208 ) )
&& ( V_67 > V_208 -> V_47 + V_208 -> V_50 ) )
return - V_49 ;
while ( 1 ) {
V_211 = F_77 ( V_23 -> V_113 , V_221 , 0 , & V_183 ) ;
if ( V_211 )
goto V_68;
if ( ! ( V_23 -> V_146 & V_222 ) ) {
for ( V_78 = 0 ; V_78 < V_23 -> V_58 ; V_78 ++ ) {
struct V_9 * V_10 = V_23 -> V_79 + V_78 ;
V_211 = F_98 ( V_76 ,
V_23 -> V_47 , NULL , V_10 , V_189 ,
& V_212 ) ;
if ( V_211 ) {
F_78 ( & V_183 ) ;
goto V_68;
}
V_196 += V_212 ;
}
V_211 = F_108 ( V_76 , V_223 , 0 ) ;
if ( V_211 == 0 ) {
V_188 = V_23 -> V_79 [ 0 ] . V_17 ;
V_23 -> V_146 |= V_222 ;
F_109 ( V_23 -> V_113 , V_188 ) ;
F_80 ( V_23 , V_188 -> V_18 ) ;
F_84 ( V_23 -> V_142 , V_188 -> V_18 ) ;
F_110 ( V_76 ) ;
}
}
F_78 ( & V_183 ) ;
if ( V_23 == V_208 )
break;
V_23 = F_33 ( V_23 ) ;
}
V_68:
V_210 . V_35 = V_196 << V_213 ;
if ( F_111 ( V_204 , & V_210 , sizeof( V_210 ) ) )
return - V_218 ;
return V_211 ;
}
static void F_112 ( struct V_93 * V_94 )
{
struct V_85 * * V_130 , * V_131 = NULL ;
int V_224 ;
struct V_36 * V_37 = V_94 -> V_96 ;
struct V_70 * V_23 = V_37 -> V_39 . V_23 ;
T_2 V_225 = F_12 ( & V_37 -> V_39 ) ;
F_3 ( F_45 ( V_37 ) ) ;
F_28 ( & V_23 -> V_109 ) ;
V_130 = & V_23 -> V_105 . V_85 ;
while ( * V_130 ) {
struct V_36 * V_87 =
F_29 ( * V_130 , struct V_36 , V_100 ) ;
V_131 = * V_130 ;
V_224 = F_11 ( V_225 , V_37 -> V_40 , V_87 ) ;
if ( V_224 > 0 )
V_130 = & ( ( * V_130 ) -> V_92 ) ;
else if ( V_224 < 0 )
V_130 = & ( ( * V_130 ) -> V_91 ) ;
else {
F_30 ( & V_23 -> V_109 ) ;
F_87 ( 1 ) ;
return;
}
}
F_67 ( & V_37 -> V_100 , V_131 , V_130 ) ;
F_68 ( & V_37 -> V_100 , & V_23 -> V_105 ) ;
V_23 -> V_106 += V_37 -> V_40 ;
F_30 ( & V_23 -> V_109 ) ;
F_46 ( V_37 , V_226 ) ;
}
static void F_113 ( struct V_70 * V_23 , struct V_93 * V_94 ,
const struct V_227 * V_228 )
{
struct V_1 V_2 = { . V_23 = V_23 , } ;
T_2 V_42 ;
struct V_36 * V_37 = V_94 -> V_96 ;
T_4 V_229 ;
T_4 V_230 = V_23 -> V_180 - V_23 -> V_106 ;
int V_211 ;
struct V_124 * V_124 = & V_94 -> V_134 ;
if ( F_114 ( V_124 -> V_231 ) )
V_229 = 1 ;
else {
V_229 = F_107 ( T_4 , F_52 ( & V_37 -> V_232 ) , V_228 -> V_233 ) ;
V_229 = F_115 ( V_229 , V_234 , V_230 ) ;
}
if ( ( V_23 -> V_180 < V_23 -> V_106 ) || ( V_230 < V_229 ) )
return;
if ( F_26 ( V_23 , V_94 -> V_235 ) )
V_42 = V_94 -> V_235 ;
else
V_42 = V_23 -> V_236 + V_23 -> V_47 ;
if ( F_87 ( F_16 ( & V_2 , V_42 ) ) )
return;
V_211 = F_116 ( & V_2 , V_62 , V_229 , V_94 , true ) ;
if ( V_211 == 0 ) {
V_37 -> V_39 = V_2 ;
V_37 -> V_40 = V_229 ;
V_37 -> V_103 = V_94 -> V_237 ;
F_112 ( V_94 ) ;
} else {
if ( V_42 == V_23 -> V_236 + V_23 -> V_47 )
V_23 -> V_236 = 0 ;
}
}
static T_2 F_117 ( struct V_70 * V_23 , T_2 V_45 ,
T_4 V_77 ,
const struct V_93 * V_94 )
{
struct V_36 * V_37 ;
struct V_85 * V_60 ;
int V_224 ;
F_28 ( & V_23 -> V_109 ) ;
V_60 = V_23 -> V_105 . V_85 ;
while ( V_60 ) {
V_37 = F_29 ( V_60 , struct V_36 , V_100 ) ;
V_224 = F_11 ( V_45 , V_77 , V_37 ) ;
if ( V_224 < 0 )
V_60 = V_60 -> V_91 ;
else if ( V_224 > 0 )
V_60 = V_60 -> V_92 ;
else
break;
}
if ( V_60 ) {
while ( ( F_11 ( V_45 , V_77 , V_37 ) == 0 ) && ( V_94 -> V_96 != V_37 ) ) {
V_45 = F_12 ( & V_37 -> V_39 ) + V_37 -> V_40 ;
V_60 = V_60 -> V_92 ;
if ( V_60 == NULL )
break;
V_37 = F_29 ( V_60 , struct V_36 , V_100 ) ;
}
}
F_30 ( & V_23 -> V_109 ) ;
return V_45 ;
}
static int F_118 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
T_4 V_238 )
{
T_2 V_45 = F_12 ( V_2 ) ;
T_4 V_229 = 1 ;
T_2 V_239 ;
int V_211 ;
if ( V_238 ) {
V_229 = F_20 ( V_2 , V_238 ) ;
V_239 = V_45 + V_229 ;
if ( V_229 < V_238 )
goto V_139;
}
V_239 = F_117 ( V_2 -> V_23 , V_45 , V_229 , V_94 ) ;
if ( V_239 == V_45 )
return 0 ;
V_139:
V_211 = F_16 ( V_2 , V_239 ) ;
if ( V_211 < 0 )
return V_211 ;
return 1 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_31 , T_4 V_238 ,
const struct V_93 * V_94 , bool V_240 )
{
struct V_187 * V_188 ;
int V_241 ;
T_4 V_242 ;
T_4 V_14 ;
T_1 * V_27 ;
int V_60 = 0 ;
int V_243 = V_2 -> V_23 -> V_58 ;
int V_211 ;
struct V_9 * V_10 ;
if ( V_2 -> V_14 != 0 )
V_243 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_119 ( V_107 , & V_10 -> V_108 ) &&
( V_31 == V_62 ) )
goto V_244;
V_188 = V_10 -> V_17 ;
V_27 = V_188 -> V_18 + V_10 -> V_19 ;
F_87 ( ! F_88 ( V_188 ) ) ;
if ( V_31 != V_175 && V_10 -> V_26 )
V_27 = V_10 -> V_26 + V_10 -> V_19 ;
V_242 = V_2 -> V_14 ;
V_14 = F_13 ( V_27 , V_10 -> V_12 , V_2 -> V_14 , V_31 ) ;
if ( V_14 == V_44 )
goto V_245;
V_2 -> V_14 = V_14 ;
if ( V_94 == NULL )
return 0 ;
V_241 = V_2 -> V_52 ;
V_211 = F_118 ( V_2 , V_94 , V_238 ) ;
if ( V_211 == 0 )
return 0 ;
if ( V_211 > 0 ) {
V_60 += ( V_2 -> V_52 - V_241 ) ;
goto V_246;
}
if ( V_211 == - V_51 ) {
V_2 -> V_52 = 0 ;
V_2 -> V_14 = 0 ;
V_60 += ( V_2 -> V_52 - V_241 ) ;
goto V_247;
}
return V_211 ;
V_245:
if ( ( V_31 == V_62 ) && V_242 == 0 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_120 ( V_107 , & V_10 -> V_108 ) ;
}
V_244:
V_2 -> V_14 = 0 ;
V_2 -> V_52 ++ ;
if ( V_2 -> V_52 == V_2 -> V_23 -> V_58 )
V_2 -> V_52 = 0 ;
V_247:
if ( ( V_2 -> V_52 == 0 ) && V_240 )
break;
V_60 ++ ;
V_246:
if ( V_60 >= V_243 )
break;
}
return - V_248 ;
}
static void F_121 ( struct V_70 * V_23 , T_2 * V_249 , T_2 V_250 )
{
T_2 V_45 ;
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_111 * V_112 ;
struct V_93 * V_94 ;
int error ;
int V_251 = 0 ;
struct V_1 V_2 = { . V_23 = V_23 , . V_52 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_38 ( & V_76 -> V_252 ) ;
error = F_116 ( & V_2 , V_175 , 0 , NULL , true ) ;
F_41 ( & V_76 -> V_252 ) ;
if ( error == - V_248 )
break;
if ( F_17 ( error ) )
break;
V_45 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_45 + 1 ) )
break;
if ( * V_249 != V_253 && V_45 <= * V_249 )
continue;
if ( V_45 == V_250 )
continue;
* V_249 = V_45 ;
error = F_73 ( V_76 , V_45 , & V_254 , V_141 , & V_112 ) ;
if ( error )
continue;
V_94 = V_112 -> V_115 ;
if ( V_94 || F_122 ( V_255 , & V_112 -> V_256 ) == 0 )
F_57 ( V_112 ) ;
else
V_251 ++ ;
if ( V_251 > V_257 )
return;
}
V_23 -> V_146 &= ~ V_179 ;
return;
}
static bool F_123 ( const struct V_70 * V_23 , int V_258 )
{
const struct V_111 * V_112 = V_23 -> V_113 ;
const struct V_75 * V_76 = V_112 -> V_259 ;
struct V_260 * V_261 ;
T_9 V_262 , V_263 ;
T_9 V_264 , V_265 ;
T_9 V_266 ;
T_9 V_267 ;
T_9 V_268 ;
F_124 () ;
V_261 = & F_125 ( V_76 -> V_269 ) -> V_270 [ V_271 ] ;
V_264 = V_261 -> V_272 [ V_273 ] ;
V_262 = V_261 -> V_272 [ V_274 ] ;
V_268 = V_261 -> V_272 [ V_275 ] +
V_112 -> V_276 . V_272 [ V_275 ] ;
F_126 () ;
V_265 = V_112 -> V_276 . V_272 [ V_273 ] ;
V_263 = V_112 -> V_276 . V_272 [ V_274 ] ;
if ( ( V_263 < 1 ) || ( V_262 < 1 ) || ( V_264 == 0 ) )
return false ;
V_266 = V_264 - V_265 ;
V_267 = V_266 * V_266 ;
V_268 *= 2 ;
if ( V_263 < 8 || V_262 < 8 )
V_268 *= 2 ;
if ( V_258 == 1 )
V_268 *= 2 ;
return ( ( V_266 < 0 ) && ( V_267 > V_268 ) ) ;
}
static bool F_127 ( const struct V_36 * V_37 ,
T_2 V_277 )
{
T_2 V_278 ;
V_278 = F_128 ( F_129 ( F_130 () ,
V_37 -> V_39 . V_23 -> V_113 -> V_279 ) ) ;
return V_278 > ( V_277 * 1000 * 1000 ) ;
}
static T_4 F_131 ( const struct V_93 * V_94 )
{
const struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
T_4 V_250 ;
F_132 ( & V_250 , sizeof( V_250 ) ) ;
return V_250 % V_76 -> V_133 ;
}
static bool F_133 ( struct V_70 * * V_128 , const struct V_70 * V_280 )
{
struct V_70 * V_23 = * V_128 ;
struct V_75 * V_76 = V_23 -> V_56 ;
V_23 = F_33 ( V_23 ) ;
if ( V_23 == NULL )
V_23 = F_31 ( V_76 ) ;
* V_128 = V_23 ;
if ( V_23 != V_280 )
return true ;
return false ;
}
int F_134 ( struct V_93 * V_94 , const struct V_227 * V_228 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
struct V_70 * V_280 = NULL ;
struct V_36 * V_37 = V_94 -> V_96 ;
int error = 0 , V_281 , V_282 = 0 ;
T_2 V_249 = V_253 ;
int V_258 = 0 ;
T_4 V_250 = 0 ;
if ( V_76 -> V_181 . V_182 )
V_282 |= V_186 ;
if ( F_94 ( V_76 , V_228 -> V_233 ) )
return - V_49 ;
if ( F_45 ( V_37 ) ) {
V_280 = V_37 -> V_39 . V_23 ;
} else if ( V_94 -> V_283 && F_26 ( V_94 -> V_283 , V_94 -> V_235 ) ) {
V_37 -> V_39 . V_23 = V_280 = V_94 -> V_283 ;
} else {
V_37 -> V_39 . V_23 = V_280 = F_27 ( V_76 , V_94 -> V_235 , 1 ) ;
}
if ( F_114 ( V_94 -> V_134 . V_231 ) && ( V_228 -> V_284 & V_285 ) )
V_250 = F_131 ( V_94 ) ;
if ( V_37 -> V_39 . V_23 == NULL )
return - V_286 ;
while ( V_258 < 3 ) {
V_281 = 1 ;
if ( ! F_76 ( V_37 -> V_39 . V_23 -> V_113 ) ) {
V_281 = 0 ;
if ( V_250 && V_250 -- )
goto V_287;
if ( ! F_45 ( V_37 ) && ( V_258 < 2 ) &&
F_127 ( V_37 , 1000 ) &&
F_123 ( V_37 -> V_39 . V_23 , V_258 ) )
goto V_287;
error = F_77 ( V_37 -> V_39 . V_23 -> V_113 ,
V_221 , V_282 ,
& V_37 -> V_288 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_45 ( V_37 ) && ( V_258 < 2 ) &&
F_123 ( V_37 -> V_39 . V_23 , V_258 ) )
goto V_289;
if ( V_76 -> V_181 . V_182 ) {
error = F_95 ( V_37 -> V_39 . V_23 ) ;
if ( F_4 ( error ) ) {
F_78 ( & V_37 -> V_288 ) ;
return error ;
}
}
}
if ( V_37 -> V_39 . V_23 -> V_146 & ( V_290 | V_291 ) )
goto V_289;
if ( V_76 -> V_181 . V_182 )
F_89 ( V_37 -> V_39 . V_23 ) ;
if ( ! F_45 ( V_37 ) )
F_113 ( V_37 -> V_39 . V_23 , V_94 , V_228 ) ;
if ( ! F_45 ( V_37 ) && ( V_258 < 1 ) )
goto V_292;
if ( V_37 -> V_39 . V_23 -> V_180 >= V_228 -> V_233 ) {
V_94 -> V_283 = V_37 -> V_39 . V_23 ;
return 0 ;
}
if ( F_45 ( V_37 ) )
F_50 ( V_37 ) ;
V_292:
if ( V_37 -> V_39 . V_23 -> V_146 & V_179 )
F_121 ( V_37 -> V_39 . V_23 , & V_249 ,
V_94 -> V_237 ) ;
V_289:
if ( ! V_281 )
F_78 ( & V_37 -> V_288 ) ;
V_287:
if ( F_133 ( & V_37 -> V_39 . V_23 , V_280 ) )
continue;
if ( V_250 )
continue;
V_258 ++ ;
if ( V_94 == F_62 ( V_76 -> V_125 ) && ! V_76 -> V_149 ) {
error = F_74 ( V_94 ) ;
if ( error )
return error ;
}
if ( V_258 == 2 )
F_135 ( V_76 , NULL ) ;
}
return - V_248 ;
}
void F_136 ( struct V_93 * V_94 )
{
struct V_36 * V_37 = V_94 -> V_96 ;
if ( V_37 -> V_288 . V_184 )
F_78 ( & V_37 -> V_288 ) ;
}
static unsigned char F_137 ( struct V_70 * V_23 , T_2 V_45 )
{
struct V_1 V_2 = { . V_23 = V_23 , } ;
int V_211 ;
V_211 = F_16 ( & V_2 , V_45 ) ;
F_17 ( V_211 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_138 ( const struct V_1 * V_2 , bool V_293 ,
unsigned int * V_60 )
{
struct V_1 V_128 = { . V_23 = V_2 -> V_23 , } ;
const unsigned int V_294 = * V_60 ;
T_2 V_45 ;
int V_211 ;
* V_60 = 1 ;
V_45 = F_12 ( V_2 ) ;
F_109 ( V_2 -> V_23 -> V_113 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_293 ? V_295 : V_296 ) ;
V_45 ++ ;
while ( * V_60 < V_294 ) {
V_211 = F_16 ( & V_128 , V_45 ) ;
if ( V_211 || F_8 ( & V_128 ) != V_62 )
break;
F_109 ( V_128 . V_23 -> V_113 , F_2 ( & V_128 ) -> V_17 ) ;
F_1 ( & V_128 , true , V_296 ) ;
( * V_60 ) ++ ;
V_45 ++ ;
}
}
static struct V_70 * F_139 ( struct V_75 * V_76 , T_2 V_297 ,
T_4 V_298 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 ;
V_2 . V_23 = F_27 ( V_76 , V_297 , 1 ) ;
if ( ! V_2 . V_23 ) {
if ( F_140 ( V_76 ) )
F_25 ( V_76 , L_16 , ( unsigned long long ) V_297 ) ;
return NULL ;
}
while ( V_298 -- ) {
F_16 ( & V_2 , V_297 ) ;
V_10 = F_2 ( & V_2 ) ;
V_297 ++ ;
if ( ! V_10 -> V_26 ) {
V_10 -> V_26 = F_141 ( V_10 -> V_17 -> V_69 ,
V_98 | V_299 ) ;
memcpy ( V_10 -> V_26 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 , V_10 -> V_12 ) ;
}
F_109 ( V_2 . V_23 -> V_113 , V_10 -> V_17 ) ;
F_1 ( & V_2 , false , V_4 ) ;
}
return V_2 . V_23 ;
}
int F_142 ( struct V_101 * V_102 , const struct V_111 * V_112 )
{
struct V_70 * V_23 = V_112 -> V_115 ;
struct V_36 * V_300 ;
const struct V_85 * V_60 ;
if ( V_23 == NULL )
return 0 ;
F_43 ( V_102 , L_17 ,
( unsigned long long ) V_23 -> V_24 , V_23 -> V_146 ,
V_23 -> V_80 , V_23 -> V_180 , V_23 -> V_81 ,
V_23 -> V_106 ) ;
F_28 ( & V_23 -> V_109 ) ;
for ( V_60 = F_32 ( & V_23 -> V_105 ) ; V_60 ; V_60 = F_34 ( & V_300 -> V_100 ) ) {
V_300 = F_29 ( V_60 , struct V_36 , V_100 ) ;
F_42 ( V_102 , V_300 ) ;
}
F_30 ( & V_23 -> V_109 ) ;
return 0 ;
}
static void F_143 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
F_100 ( V_76 , L_18 ,
( unsigned long long ) V_23 -> V_24 ) ;
F_100 ( V_76 , L_19 ) ;
F_142 ( NULL , V_23 -> V_113 ) ;
V_23 -> V_146 |= V_291 ;
}
static void F_144 ( struct V_93 * V_94 ,
const struct V_1 * V_2 , unsigned V_35 )
{
struct V_36 * V_37 = V_94 -> V_96 ;
struct V_70 * V_23 = V_2 -> V_23 ;
unsigned V_301 ;
T_2 V_45 ;
int V_211 ;
F_28 ( & V_23 -> V_109 ) ;
if ( F_45 ( V_37 ) ) {
if ( F_145 ( & V_37 -> V_39 , V_2 ) ) {
V_45 = F_12 ( V_2 ) ;
V_211 = F_16 ( & V_37 -> V_39 , V_45 + V_35 ) ;
V_301 = F_146 ( V_37 -> V_40 , V_35 ) ;
V_37 -> V_40 -= V_301 ;
V_23 -> V_106 -= V_301 ;
F_46 ( V_37 , V_302 ) ;
if ( V_37 -> V_40 && ! V_211 )
goto V_68;
}
F_44 ( V_37 ) ;
}
V_68:
F_30 ( & V_23 -> V_109 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
const struct V_93 * V_94 , bool V_293 )
{
T_2 V_42 ;
if ( F_45 ( V_94 -> V_96 ) ) {
* V_2 = V_94 -> V_96 -> V_39 ;
return;
}
if ( ! V_293 && F_26 ( V_2 -> V_23 , V_94 -> V_235 ) )
V_42 = V_94 -> V_235 ;
else
V_42 = V_2 -> V_23 -> V_236 + V_2 -> V_23 -> V_47 ;
F_16 ( V_2 , V_42 ) ;
}
int F_148 ( struct V_93 * V_94 , T_2 * V_303 , unsigned int * V_304 ,
bool V_293 , T_2 * V_305 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
struct V_187 * V_306 ;
struct V_1 V_2 = { . V_23 = V_94 -> V_283 , } ;
unsigned int V_307 ;
T_2 V_45 ;
int error ;
F_147 ( & V_2 , V_94 , V_293 ) ;
error = F_116 ( & V_2 , V_62 , 0 , V_94 , false ) ;
if ( error == - V_248 ) {
F_147 ( & V_2 , V_94 , V_293 ) ;
error = F_116 ( & V_2 , V_62 , 0 , NULL , false ) ;
}
if ( error ) {
F_100 ( V_76 , L_20 ,
( unsigned long long ) V_94 -> V_237 , error , * V_304 ,
F_119 ( V_107 , & V_2 . V_23 -> V_79 -> V_108 ) ) ;
goto V_308;
}
F_138 ( & V_2 , V_293 , V_304 ) ;
V_45 = F_12 ( & V_2 ) ;
V_2 . V_23 -> V_236 = V_45 - V_2 . V_23 -> V_47 ;
if ( F_45 ( V_94 -> V_96 ) )
F_144 ( V_94 , & V_2 , * V_304 ) ;
V_307 = * V_304 ;
if ( V_293 )
V_307 -- ;
if ( ! V_293 ) {
V_94 -> V_235 = V_45 + V_307 - 1 ;
error = F_149 ( V_94 , & V_306 ) ;
if ( error == 0 ) {
struct V_309 * V_310 =
(struct V_309 * ) V_306 -> V_18 ;
F_109 ( V_94 -> V_150 , V_306 ) ;
V_310 -> V_311 = V_310 -> V_312 =
F_82 ( V_94 -> V_235 ) ;
F_93 ( V_306 ) ;
}
}
if ( V_2 . V_23 -> V_80 < * V_304 ) {
F_5 ( V_22 L_21 , * V_304 ) ;
goto V_308;
}
V_2 . V_23 -> V_80 -= * V_304 ;
if ( V_293 ) {
V_2 . V_23 -> V_81 ++ ;
* V_305 = V_2 . V_23 -> V_160 ++ ;
if ( * V_305 == 0 )
* V_305 = V_2 . V_23 -> V_160 ++ ;
}
F_109 ( V_2 . V_23 -> V_113 , V_2 . V_23 -> V_79 [ 0 ] . V_17 ) ;
F_80 ( V_2 . V_23 , V_2 . V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_2 . V_23 -> V_142 , V_2 . V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_150 ( V_76 , 0 , - ( T_9 ) * V_304 , V_293 ? 1 : 0 ) ;
if ( V_293 )
F_151 ( V_76 , V_45 , 1 ) ;
F_152 ( V_94 , * V_304 , V_94 -> V_134 . V_313 , V_94 -> V_134 . V_314 ) ;
V_2 . V_23 -> V_180 -= * V_304 ;
F_153 ( V_94 , V_2 . V_23 , V_45 , * V_304 ,
V_293 ? V_295 : V_296 ) ;
* V_303 = V_45 ;
return 0 ;
V_308:
F_143 ( V_2 . V_23 ) ;
return - V_122 ;
}
void F_154 ( struct V_93 * V_94 , T_2 V_297 , T_4 V_298 , int V_315 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
struct V_70 * V_23 ;
V_23 = F_139 ( V_76 , V_297 , V_298 , V_62 ) ;
if ( ! V_23 )
return;
F_153 ( V_94 , V_23 , V_297 , V_298 , V_62 ) ;
V_23 -> V_80 += V_298 ;
V_23 -> V_146 &= ~ V_222 ;
F_109 ( V_23 -> V_113 , V_23 -> V_79 [ 0 ] . V_17 ) ;
F_80 ( V_23 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_23 -> V_142 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
if ( V_315 || V_94 -> V_316 )
F_155 ( V_94 , V_297 , V_298 ) ;
}
void F_156 ( struct V_93 * V_94 , T_2 V_297 , T_4 V_298 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
F_154 ( V_94 , V_297 , V_298 , 1 ) ;
F_150 ( V_76 , 0 , + V_298 , 0 ) ;
F_152 ( V_94 , - ( T_9 ) V_298 , V_94 -> V_134 . V_313 , V_94 -> V_134 . V_314 ) ;
}
void F_157 ( struct V_124 * V_124 )
{
struct V_93 * V_94 = F_62 ( V_124 ) ;
struct V_75 * V_76 = F_70 ( V_124 ) ;
struct V_70 * V_23 ;
T_2 V_317 = V_94 -> V_237 ;
V_23 = F_139 ( V_76 , V_317 , 1 , V_175 ) ;
if ( ! V_23 )
return;
F_153 ( V_94 , V_23 , V_317 , 1 , V_175 ) ;
F_109 ( V_23 -> V_113 , V_23 -> V_79 [ 0 ] . V_17 ) ;
F_80 ( V_23 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_23 -> V_142 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_23 , 1 ) ;
}
static void F_158 ( struct V_70 * V_23 , T_2 V_317 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_70 * V_318 ;
V_318 = F_139 ( V_76 , V_317 , 1 , V_62 ) ;
if ( ! V_318 )
return;
F_159 ( V_76 , V_23 == V_318 ) ;
if ( ! V_23 -> V_81 )
F_7 ( V_23 ) ;
V_23 -> V_81 -- ;
V_23 -> V_80 ++ ;
F_109 ( V_23 -> V_113 , V_23 -> V_79 [ 0 ] . V_17 ) ;
F_80 ( V_23 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_23 -> V_142 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_23 , - 1 ) ;
F_150 ( V_76 , 0 , + 1 , - 1 ) ;
}
void F_160 ( struct V_70 * V_23 , struct V_93 * V_94 )
{
F_158 ( V_23 , V_94 -> V_237 ) ;
F_153 ( V_94 , V_23 , V_94 -> V_237 , 1 , V_62 ) ;
F_152 ( V_94 , - 1 , V_94 -> V_134 . V_313 , V_94 -> V_134 . V_314 ) ;
F_155 ( V_94 , V_94 -> V_237 , 1 ) ;
}
int F_161 ( struct V_75 * V_76 , T_2 V_319 , unsigned int type )
{
struct V_70 * V_23 ;
struct V_151 V_320 ;
int error = - V_49 ;
V_23 = F_27 ( V_76 , V_319 , 1 ) ;
if ( ! V_23 )
goto V_139;
error = F_77 ( V_23 -> V_113 , V_154 , 0 , & V_320 ) ;
if ( error )
goto V_139;
if ( F_137 ( V_23 , V_319 ) != type )
error = - V_321 ;
F_78 ( & V_320 ) ;
V_139:
return error ;
}
void F_162 ( struct V_93 * V_94 , struct V_322 * V_323 ,
T_2 V_45 )
{
struct V_75 * V_76 = F_70 ( & V_94 -> V_134 ) ;
struct V_70 * V_23 ;
struct V_70 * * V_32 ;
unsigned int V_324 ;
unsigned int V_78 ;
if ( F_94 ( V_76 , ! V_323 -> V_325 ) )
return;
if ( V_94 -> V_283 && F_26 ( V_94 -> V_283 , V_45 ) )
V_23 = V_94 -> V_283 ;
else
V_23 = F_27 ( V_76 , V_45 , 1 ) ;
if ( ! V_23 ) {
F_25 ( V_76 , L_22 , ( unsigned long long ) V_45 ) ;
return;
}
V_94 -> V_283 = V_23 ;
for ( V_78 = 0 ; V_78 < V_323 -> V_326 ; V_78 ++ )
if ( V_323 -> V_327 [ V_78 ] == V_23 )
return;
if ( V_323 -> V_326 == V_323 -> V_328 ) {
V_324 = V_323 -> V_328 + 10 ;
V_32 = F_60 ( V_324 , sizeof( struct V_70 * ) ,
V_98 | V_299 ) ;
if ( V_323 -> V_327 ) {
memcpy ( V_32 , V_323 -> V_327 ,
V_323 -> V_328 * sizeof( struct V_70 * ) ) ;
F_36 ( V_323 -> V_327 ) ;
}
V_323 -> V_328 = V_324 ;
V_323 -> V_327 = V_32 ;
}
V_323 -> V_327 [ V_323 -> V_326 ++ ] = V_23 ;
}
void F_163 ( struct V_322 * V_323 , unsigned int V_31 )
{
unsigned int V_78 ;
V_323 -> V_325 = F_60 ( V_323 -> V_326 , sizeof( struct V_151 ) ,
V_98 | V_299 ) ;
for ( V_78 = 0 ; V_78 < V_323 -> V_326 ; V_78 ++ )
F_164 ( V_323 -> V_327 [ V_78 ] -> V_113 ,
V_31 , 0 ,
& V_323 -> V_325 [ V_78 ] ) ;
}
void F_165 ( struct V_322 * V_323 )
{
unsigned int V_78 ;
F_36 ( V_323 -> V_327 ) ;
if ( V_323 -> V_325 ) {
for ( V_78 = 0 ; V_78 < V_323 -> V_326 ; V_78 ++ )
F_166 ( & V_323 -> V_325 [ V_78 ] ) ;
F_36 ( V_323 -> V_325 ) ;
V_323 -> V_325 = NULL ;
}
}
