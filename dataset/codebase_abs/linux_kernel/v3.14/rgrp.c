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
V_23 -> V_107 += V_37 -> V_40 ;
V_37 -> V_40 = 0 ;
F_48 ( V_108 , & V_10 -> V_109 ) ;
}
}
void F_49 ( struct V_36 * V_37 )
{
struct V_70 * V_23 ;
V_23 = V_37 -> V_39 . V_23 ;
if ( V_23 ) {
F_28 ( & V_23 -> V_110 ) ;
F_44 ( V_37 ) ;
F_30 ( & V_23 -> V_110 ) ;
}
}
void F_50 ( struct V_93 * V_94 , T_5 * V_111 )
{
F_38 ( & V_94 -> V_95 ) ;
if ( V_94 -> V_96 && ( ( V_111 == NULL ) || ( F_51 ( V_111 ) <= 1 ) ) ) {
F_49 ( V_94 -> V_96 ) ;
F_3 ( V_94 -> V_96 -> V_40 ) ;
F_52 ( V_97 , V_94 -> V_96 ) ;
V_94 -> V_96 = NULL ;
}
F_41 ( & V_94 -> V_95 ) ;
}
static void F_53 ( struct V_70 * V_23 )
{
struct V_85 * V_60 ;
struct V_36 * V_37 ;
F_28 ( & V_23 -> V_110 ) ;
while ( ( V_60 = F_32 ( & V_23 -> V_105 ) ) ) {
V_37 = F_29 ( V_60 , struct V_36 , V_100 ) ;
F_44 ( V_37 ) ;
}
F_30 ( & V_23 -> V_110 ) ;
}
void F_54 ( struct V_75 * V_76 )
{
struct V_85 * V_60 ;
struct V_70 * V_23 ;
struct V_112 * V_113 ;
while ( ( V_60 = F_32 ( & V_76 -> V_89 ) ) ) {
V_23 = F_29 ( V_60 , struct V_70 , V_90 ) ;
V_113 = V_23 -> V_114 ;
F_47 ( V_60 , & V_76 -> V_89 ) ;
if ( V_113 ) {
F_28 ( & V_113 -> V_115 ) ;
V_113 -> V_116 = NULL ;
F_30 ( & V_113 -> V_115 ) ;
F_55 ( V_113 ) ;
F_56 ( V_113 ) ;
}
F_35 ( V_23 ) ;
F_36 ( V_23 -> V_79 ) ;
F_53 ( V_23 ) ;
F_52 ( V_117 , V_23 ) ;
}
}
static void F_57 ( const struct V_70 * V_23 )
{
F_5 ( V_118 L_9 , ( unsigned long long ) V_23 -> V_24 ) ;
F_5 ( V_118 L_10 , V_23 -> V_58 ) ;
F_5 ( V_118 L_11 , ( unsigned long long ) V_23 -> V_47 ) ;
F_5 ( V_118 L_12 , V_23 -> V_50 ) ;
F_5 ( V_118 L_13 , V_23 -> V_119 ) ;
}
static int F_58 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_9 * V_10 ;
T_4 V_77 = V_23 -> V_58 ;
T_4 V_120 , V_65 ;
int V_78 ;
if ( ! V_77 )
return - V_49 ;
V_23 -> V_79 = F_59 ( V_77 , sizeof( struct V_9 ) , V_98 ) ;
if ( ! V_23 -> V_79 )
return - V_99 ;
V_120 = V_23 -> V_119 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
V_10 = V_23 -> V_79 + V_78 ;
V_10 -> V_109 = 0 ;
if ( V_77 == 1 ) {
V_65 = V_120 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_25 = 0 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
} else if ( V_78 == 0 ) {
V_65 = V_76 -> V_121 . V_122 - sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_25 = 0 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
} else if ( V_78 + 1 == V_77 ) {
V_65 = V_120 ;
V_10 -> V_19 = sizeof( struct V_55 ) ;
V_10 -> V_25 = V_23 -> V_119 - V_120 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
} else {
V_65 = V_76 -> V_121 . V_122 -
sizeof( struct V_55 ) ;
V_10 -> V_19 = sizeof( struct V_55 ) ;
V_10 -> V_25 = V_23 -> V_119 - V_120 ;
V_10 -> V_12 = V_65 ;
V_10 -> V_53 = V_65 * V_15 ;
}
V_120 -= V_65 ;
}
if ( V_120 ) {
F_7 ( V_23 ) ;
return - V_123 ;
}
V_10 = V_23 -> V_79 + ( V_77 - 1 ) ;
if ( ( V_10 -> V_25 + V_10 -> V_12 ) * V_15 != V_23 -> V_50 ) {
if ( F_7 ( V_23 ) ) {
F_57 ( V_23 ) ;
F_25 ( V_76 , L_14 ,
V_10 -> V_25 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_123 ;
}
return 0 ;
}
T_2 F_60 ( struct V_75 * V_76 )
{
T_2 V_124 = 0 ;
struct V_125 * V_125 = V_76 -> V_126 ;
struct V_93 * V_94 = F_61 ( V_125 ) ;
char V_41 [ sizeof( struct V_127 ) ] ;
int error , V_128 ;
for ( V_128 = 0 ; ; V_128 ++ ) {
T_6 V_129 = V_128 * sizeof( struct V_127 ) ;
if ( V_129 + sizeof( struct V_127 ) > F_62 ( V_125 ) )
break;
error = F_63 ( V_94 , V_41 , & V_129 ,
sizeof( struct V_127 ) ) ;
if ( error != sizeof( struct V_127 ) )
break;
V_124 += F_64 ( ( (struct V_127 * ) V_41 ) -> V_130 ) ;
}
return V_124 ;
}
static int F_65 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_85 * * V_131 = & V_76 -> V_89 . V_85 , * V_132 = NULL ;
while ( * V_131 ) {
struct V_70 * V_87 = F_29 ( * V_131 , struct V_70 ,
V_90 ) ;
V_132 = * V_131 ;
if ( V_23 -> V_24 < V_87 -> V_24 )
V_131 = & ( ( * V_131 ) -> V_91 ) ;
else if ( V_23 -> V_24 > V_87 -> V_24 )
V_131 = & ( ( * V_131 ) -> V_92 ) ;
else
return - V_133 ;
}
F_66 ( & V_23 -> V_90 , V_132 , V_131 ) ;
F_67 ( & V_23 -> V_90 , & V_76 -> V_89 ) ;
V_76 -> V_134 ++ ;
return 0 ;
}
static int F_68 ( struct V_93 * V_94 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
const unsigned V_136 = V_76 -> V_121 . V_122 ;
T_6 V_129 = V_76 -> V_134 * sizeof( struct V_127 ) ;
struct V_127 V_41 ;
int error ;
struct V_70 * V_23 ;
if ( V_129 >= F_62 ( & V_94 -> V_135 ) )
return 1 ;
error = F_63 ( V_94 , ( char * ) & V_41 , & V_129 ,
sizeof( struct V_127 ) ) ;
if ( error != sizeof( struct V_127 ) )
return ( error == 0 ) ? 1 : error ;
V_23 = F_39 ( V_117 , V_98 ) ;
error = - V_99 ;
if ( ! V_23 )
return error ;
V_23 -> V_56 = V_76 ;
V_23 -> V_24 = F_70 ( V_41 . V_137 ) ;
V_23 -> V_58 = F_64 ( V_41 . V_138 ) ;
V_23 -> V_47 = F_70 ( V_41 . V_139 ) ;
V_23 -> V_50 = F_64 ( V_41 . V_130 ) ;
V_23 -> V_119 = F_64 ( V_41 . V_140 ) ;
F_71 ( & V_23 -> V_110 ) ;
error = F_58 ( V_23 ) ;
if ( error )
goto V_141;
error = F_72 ( V_76 , V_23 -> V_24 ,
& V_142 , V_143 , & V_23 -> V_114 ) ;
if ( error )
goto V_141;
V_23 -> V_114 -> V_116 = V_23 ;
V_23 -> V_114 -> V_144 . V_67 = V_23 -> V_24 * V_136 ;
V_23 -> V_114 -> V_144 . V_7 = V_23 -> V_114 -> V_144 . V_67 + ( V_23 -> V_58 * V_136 ) - 1 ;
V_23 -> V_145 = (struct V_146 * ) V_23 -> V_114 -> V_147 . V_148 ;
V_23 -> V_149 &= ~ V_150 ;
if ( V_23 -> V_50 > V_76 -> V_151 )
V_76 -> V_151 = V_23 -> V_50 ;
F_28 ( & V_76 -> V_88 ) ;
error = F_65 ( V_23 ) ;
F_30 ( & V_76 -> V_88 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_56 ( V_23 -> V_114 ) ;
V_141:
F_36 ( V_23 -> V_79 ) ;
F_52 ( V_117 , V_23 ) ;
return error ;
}
static int F_73 ( struct V_93 * V_94 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
int error ;
do {
error = F_68 ( V_94 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_76 -> V_152 = 1 ;
return 0 ;
}
int F_74 ( struct V_75 * V_76 )
{
struct V_93 * V_94 = F_61 ( V_76 -> V_126 ) ;
struct V_112 * V_113 = V_94 -> V_153 ;
struct V_154 V_155 ;
int error = 0 ;
int V_156 = 0 ;
if ( ! V_76 -> V_152 ) {
if ( ! F_75 ( V_113 ) ) {
error = F_76 ( V_113 , V_157 , 0 , & V_155 ) ;
if ( error )
return error ;
V_156 = 1 ;
}
if ( ! V_76 -> V_152 )
error = F_73 ( V_94 ) ;
if ( V_156 )
F_77 ( & V_155 ) ;
}
return error ;
}
static void F_78 ( struct V_70 * V_23 , const void * V_41 )
{
const struct V_54 * V_158 = V_41 ;
T_4 V_159 ;
V_159 = F_64 ( V_158 -> V_159 ) ;
V_159 &= ~ V_160 ;
V_23 -> V_149 &= V_160 ;
V_23 -> V_149 |= V_159 ;
V_23 -> V_80 = F_64 ( V_158 -> V_161 ) ;
V_23 -> V_81 = F_64 ( V_158 -> V_162 ) ;
V_23 -> V_163 = F_70 ( V_158 -> V_164 ) ;
}
static void F_79 ( struct V_70 * V_23 , void * V_41 )
{
struct V_54 * V_158 = V_41 ;
V_158 -> V_159 = F_80 ( V_23 -> V_149 & ~ V_160 ) ;
V_158 -> V_161 = F_80 ( V_23 -> V_80 ) ;
V_158 -> V_162 = F_80 ( V_23 -> V_81 ) ;
V_158 -> V_165 = F_80 ( 0 ) ;
V_158 -> V_164 = F_81 ( V_23 -> V_163 ) ;
memset ( & V_158 -> V_166 , 0 , sizeof( V_158 -> V_166 ) ) ;
}
static int F_82 ( struct V_70 * V_23 )
{
struct V_146 * V_167 = V_23 -> V_145 ;
struct V_54 * V_158 = (struct V_54 * ) V_23 -> V_79 [ 0 ] . V_17 -> V_18 ;
if ( V_167 -> V_168 != V_158 -> V_159 || V_167 -> V_169 != V_158 -> V_161 ||
V_167 -> V_170 != V_158 -> V_162 ||
V_167 -> V_171 != V_158 -> V_164 )
return 0 ;
return 1 ;
}
static void F_83 ( struct V_146 * V_167 , const void * V_41 )
{
const struct V_54 * V_158 = V_41 ;
V_167 -> V_172 = F_80 ( V_173 ) ;
V_167 -> V_168 = V_158 -> V_159 ;
V_167 -> V_169 = V_158 -> V_161 ;
V_167 -> V_170 = V_158 -> V_162 ;
V_167 -> V_171 = V_158 -> V_164 ;
V_167 -> V_165 = 0UL ;
}
static void F_84 ( struct V_70 * V_23 , T_4 V_174 )
{
struct V_146 * V_167 = V_23 -> V_145 ;
T_4 V_175 = F_64 ( V_167 -> V_176 ) + V_174 ;
V_167 -> V_176 = F_80 ( V_175 ) ;
}
static T_4 F_85 ( struct V_70 * V_23 )
{
struct V_9 * V_10 ;
const T_4 V_77 = V_23 -> V_58 ;
const T_1 * V_27 = NULL ;
T_4 V_177 , V_42 , V_74 = 0 ;
for ( V_177 = 0 , V_10 = V_23 -> V_79 ; V_177 < V_77 ; V_177 ++ , V_10 ++ ) {
V_42 = 0 ;
V_27 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_86 ( ! F_87 ( V_10 -> V_17 ) ) ;
while ( V_42 < V_10 -> V_12 * V_15 ) {
V_42 = F_13 ( V_27 , V_10 -> V_12 , V_42 ,
V_178 ) ;
if ( V_42 == V_44 )
break;
V_74 ++ ;
V_42 ++ ;
}
}
return V_74 ;
}
int F_88 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_112 * V_113 = V_23 -> V_114 ;
unsigned int V_77 = V_23 -> V_58 ;
struct V_9 * V_10 ;
unsigned int V_78 , V_179 ;
int error ;
if ( V_23 -> V_79 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
V_10 = V_23 -> V_79 + V_78 ;
error = F_89 ( V_113 , V_23 -> V_24 + V_78 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_141;
}
for ( V_179 = V_77 ; V_179 -- ; ) {
V_10 = V_23 -> V_79 + V_179 ;
error = F_90 ( V_76 , V_10 -> V_17 ) ;
if ( error )
goto V_141;
if ( F_91 ( V_76 , V_10 -> V_17 , V_179 ? V_180 :
V_181 ) ) {
error = - V_123 ;
goto V_141;
}
}
if ( ! ( V_23 -> V_149 & V_150 ) ) {
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
F_48 ( V_108 , & V_23 -> V_79 [ V_78 ] . V_109 ) ;
F_78 ( V_23 , ( V_23 -> V_79 [ 0 ] . V_17 ) -> V_18 ) ;
V_23 -> V_149 |= ( V_150 | V_182 ) ;
V_23 -> V_183 = V_23 -> V_80 ;
V_23 -> V_107 = V_23 -> V_80 ;
}
if ( F_80 ( V_173 ) != V_23 -> V_145 -> V_172 ) {
V_23 -> V_145 -> V_176 = F_80 ( F_85 ( V_23 ) ) ;
F_83 ( V_23 -> V_145 ,
V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_76 -> V_184 . V_185 ) {
if ( ! F_82 ( V_23 ) ) {
F_7 ( V_23 ) ;
error = - V_123 ;
goto V_141;
}
if ( V_23 -> V_145 -> V_176 == 0 )
V_23 -> V_149 &= ~ V_182 ;
}
return 0 ;
V_141:
while ( V_78 -- ) {
V_10 = V_23 -> V_79 + V_78 ;
F_92 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_93 ( V_76 , ! V_10 -> V_26 ) ;
}
return error ;
}
int F_94 ( struct V_70 * V_23 )
{
T_4 V_168 ;
if ( V_23 -> V_149 & V_150 )
return 0 ;
if ( F_80 ( V_173 ) != V_23 -> V_145 -> V_172 )
return F_88 ( V_23 ) ;
V_168 = F_64 ( V_23 -> V_145 -> V_168 ) ;
V_168 &= ~ V_160 ;
V_23 -> V_149 &= V_160 ;
V_23 -> V_149 |= ( V_168 | V_150 | V_182 ) ;
if ( V_23 -> V_145 -> V_176 == 0 )
V_23 -> V_149 &= ~ V_182 ;
V_23 -> V_80 = F_64 ( V_23 -> V_145 -> V_169 ) ;
V_23 -> V_183 = V_23 -> V_80 ;
V_23 -> V_81 = F_64 ( V_23 -> V_145 -> V_170 ) ;
V_23 -> V_163 = F_70 ( V_23 -> V_145 -> V_171 ) ;
return 0 ;
}
int F_95 ( struct V_154 * V_186 )
{
struct V_70 * V_23 = V_186 -> V_187 -> V_116 ;
struct V_75 * V_76 = V_23 -> V_56 ;
if ( V_186 -> V_188 & V_189 && V_76 -> V_184 . V_185 )
return 0 ;
return F_88 ( V_23 ) ;
}
void F_96 ( struct V_154 * V_186 )
{
struct V_70 * V_23 = V_186 -> V_187 -> V_116 ;
int V_78 , V_77 = V_23 -> V_58 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
struct V_9 * V_10 = V_23 -> V_79 + V_78 ;
if ( V_10 -> V_17 ) {
F_92 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
int F_97 ( struct V_75 * V_76 , T_2 V_14 ,
struct V_190 * V_191 ,
const struct V_9 * V_10 , unsigned V_192 , T_2 * V_193 )
{
struct V_194 * V_195 = V_76 -> V_196 ;
T_2 V_34 ;
T_7 V_67 = 0 ;
T_7 V_197 = 0 ;
int V_198 ;
unsigned int V_78 ;
T_4 V_199 = 0 ;
T_1 V_200 ;
for ( V_78 = 0 ; V_78 < V_10 -> V_12 ; V_78 ++ ) {
const T_1 * V_201 = V_10 -> V_26 ? V_10 -> V_26 : V_10 -> V_17 -> V_18 ;
V_201 += V_10 -> V_19 ;
V_201 += V_78 ;
if ( V_191 ) {
const T_1 * V_202 = V_191 -> V_18 + V_10 -> V_19 + V_78 ;
V_200 = ~ ( * V_202 | ( * V_202 >> 1 ) ) & ( * V_201 | ( * V_201 >> 1 ) ) ;
} else {
V_200 = ~ ( * V_201 | ( * V_201 >> 1 ) ) ;
}
V_200 &= 0x55 ;
if ( V_200 == 0 )
continue;
V_34 = V_14 + ( ( V_10 -> V_25 + V_78 ) * V_15 ) ;
while( V_200 ) {
if ( V_200 & 1 ) {
if ( V_197 == 0 )
goto V_203;
if ( ( V_67 + V_197 ) != V_34 ) {
if ( V_197 >= V_192 ) {
V_198 = F_98 ( V_195 ,
V_67 , V_197 ,
V_98 , 0 ) ;
if ( V_198 )
goto V_141;
V_199 += V_197 ;
}
V_197 = 0 ;
V_203:
V_67 = V_34 ;
}
V_197 ++ ;
}
V_200 >>= 2 ;
V_34 ++ ;
}
}
if ( V_197 >= V_192 ) {
V_198 = F_98 ( V_195 , V_67 , V_197 , V_98 , 0 ) ;
if ( V_198 )
goto V_141;
V_199 += V_197 ;
}
if ( V_193 )
* V_193 = V_199 ;
return 0 ;
V_141:
if ( V_76 -> V_184 . V_204 )
F_99 ( V_76 , L_15 , V_198 ) ;
V_76 -> V_184 . V_204 = 0 ;
return - V_123 ;
}
int F_100 ( struct V_205 * V_206 , void T_8 * V_207 )
{
struct V_125 * V_125 = F_101 ( V_206 ) ;
struct V_75 * V_76 = F_69 ( V_125 ) ;
struct V_208 * V_209 = F_102 ( V_76 -> V_196 -> V_210 ) ;
struct V_190 * V_191 ;
struct V_70 * V_23 ;
struct V_70 * V_211 ;
struct V_154 V_186 ;
struct V_212 V_213 ;
int V_214 = 0 ;
T_2 V_215 ;
T_2 V_199 = 0 ;
T_2 V_67 , V_7 , V_192 ;
unsigned int V_78 ;
unsigned V_216 = V_76 -> V_121 . V_217 ;
if ( ! F_103 ( V_218 ) )
return - V_219 ;
if ( ! F_104 ( V_209 ) )
return - V_220 ;
if ( F_105 ( & V_213 , V_207 , sizeof( V_213 ) ) )
return - V_221 ;
V_214 = F_74 ( V_76 ) ;
if ( V_214 )
return V_214 ;
V_67 = V_213 . V_67 >> V_216 ;
V_7 = V_67 + ( V_213 . V_35 >> V_216 ) ;
V_192 = F_106 ( T_2 , V_213 . V_192 ,
V_209 -> V_222 . V_223 ) >> V_216 ;
if ( V_7 <= V_67 || V_192 > V_76 -> V_151 )
return - V_49 ;
V_23 = F_27 ( V_76 , V_67 , 0 ) ;
V_211 = F_27 ( V_76 , V_7 , 0 ) ;
if ( ( F_31 ( V_76 ) == F_33 ( V_211 ) )
&& ( V_67 > V_211 -> V_47 + V_211 -> V_50 ) )
return - V_49 ;
while ( 1 ) {
V_214 = F_76 ( V_23 -> V_114 , V_224 , 0 , & V_186 ) ;
if ( V_214 )
goto V_68;
if ( ! ( V_23 -> V_149 & V_225 ) ) {
for ( V_78 = 0 ; V_78 < V_23 -> V_58 ; V_78 ++ ) {
struct V_9 * V_10 = V_23 -> V_79 + V_78 ;
V_214 = F_97 ( V_76 ,
V_23 -> V_47 , NULL , V_10 , V_192 ,
& V_215 ) ;
if ( V_214 ) {
F_77 ( & V_186 ) ;
goto V_68;
}
V_199 += V_215 ;
}
V_214 = F_107 ( V_76 , V_226 , 0 ) ;
if ( V_214 == 0 ) {
V_191 = V_23 -> V_79 [ 0 ] . V_17 ;
V_23 -> V_149 |= V_225 ;
F_108 ( V_23 -> V_114 , V_191 ) ;
F_79 ( V_23 , V_191 -> V_18 ) ;
F_83 ( V_23 -> V_145 , V_191 -> V_18 ) ;
F_109 ( V_76 ) ;
}
}
F_77 ( & V_186 ) ;
if ( V_23 == V_211 )
break;
V_23 = F_33 ( V_23 ) ;
}
V_68:
V_213 . V_35 = V_199 << V_216 ;
if ( F_110 ( V_207 , & V_213 , sizeof( V_213 ) ) )
return - V_221 ;
return V_214 ;
}
static void F_111 ( struct V_93 * V_94 )
{
struct V_85 * * V_131 , * V_132 = NULL ;
int V_227 ;
struct V_36 * V_37 = V_94 -> V_96 ;
struct V_70 * V_23 = V_37 -> V_39 . V_23 ;
T_2 V_228 = F_12 ( & V_37 -> V_39 ) ;
F_3 ( F_45 ( V_37 ) ) ;
F_28 ( & V_23 -> V_110 ) ;
V_131 = & V_23 -> V_105 . V_85 ;
while ( * V_131 ) {
struct V_36 * V_87 =
F_29 ( * V_131 , struct V_36 , V_100 ) ;
V_132 = * V_131 ;
V_227 = F_11 ( V_228 , V_37 -> V_40 , V_87 ) ;
if ( V_227 > 0 )
V_131 = & ( ( * V_131 ) -> V_92 ) ;
else if ( V_227 < 0 )
V_131 = & ( ( * V_131 ) -> V_91 ) ;
else {
F_30 ( & V_23 -> V_110 ) ;
F_86 ( 1 ) ;
return;
}
}
F_66 ( & V_37 -> V_100 , V_132 , V_131 ) ;
F_67 ( & V_37 -> V_100 , & V_23 -> V_105 ) ;
V_23 -> V_106 += V_37 -> V_40 ;
F_30 ( & V_23 -> V_110 ) ;
F_46 ( V_37 , V_229 ) ;
}
static void F_112 ( struct V_70 * V_23 , struct V_93 * V_94 ,
const struct V_230 * V_231 )
{
struct V_1 V_2 = { . V_23 = V_23 , } ;
T_2 V_42 ;
struct V_36 * V_37 = V_94 -> V_96 ;
T_4 V_232 ;
T_4 V_233 = V_23 -> V_183 - V_23 -> V_106 ;
int V_214 ;
struct V_125 * V_125 = & V_94 -> V_135 ;
if ( F_113 ( V_125 -> V_234 ) )
V_232 = 1 ;
else {
V_232 = F_106 ( T_4 , F_51 ( & V_37 -> V_235 ) , V_231 -> V_236 ) ;
V_232 = F_114 ( V_232 , V_237 , V_233 ) ;
}
if ( ( V_23 -> V_183 < V_23 -> V_106 ) || ( V_233 < V_232 ) )
return;
if ( F_26 ( V_23 , V_94 -> V_238 ) )
V_42 = V_94 -> V_238 ;
else
V_42 = V_23 -> V_239 + V_23 -> V_47 ;
if ( F_86 ( F_16 ( & V_2 , V_42 ) ) )
return;
V_214 = F_115 ( & V_2 , V_62 , & V_232 , V_94 , true , V_231 ) ;
if ( V_214 == 0 ) {
V_37 -> V_39 = V_2 ;
V_37 -> V_40 = V_232 ;
V_37 -> V_103 = V_94 -> V_240 ;
F_111 ( V_94 ) ;
} else {
if ( V_42 == V_23 -> V_239 + V_23 -> V_47 )
V_23 -> V_239 = 0 ;
}
}
static T_2 F_116 ( struct V_70 * V_23 , T_2 V_45 ,
T_4 V_77 ,
const struct V_93 * V_94 )
{
struct V_36 * V_37 ;
struct V_85 * V_60 ;
int V_227 ;
F_28 ( & V_23 -> V_110 ) ;
V_60 = V_23 -> V_105 . V_85 ;
while ( V_60 ) {
V_37 = F_29 ( V_60 , struct V_36 , V_100 ) ;
V_227 = F_11 ( V_45 , V_77 , V_37 ) ;
if ( V_227 < 0 )
V_60 = V_60 -> V_91 ;
else if ( V_227 > 0 )
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
F_30 ( & V_23 -> V_110 ) ;
return V_45 ;
}
static int F_117 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
T_4 V_241 ,
struct V_242 * V_243 )
{
T_2 V_45 = F_12 ( V_2 ) ;
T_4 V_232 = 1 ;
T_2 V_244 ;
int V_214 ;
if ( V_241 ) {
V_232 = F_20 ( V_2 , V_241 ) ;
if ( V_232 <= V_243 -> V_35 )
goto V_141;
}
V_244 = F_116 ( V_2 -> V_23 , V_45 , V_232 , V_94 ) ;
if ( V_244 == V_45 ) {
if ( ! V_241 || V_232 >= V_241 )
return 0 ;
if ( V_232 > V_243 -> V_35 ) {
V_243 -> V_35 = V_232 ;
V_243 -> V_2 = * V_2 ;
}
V_141:
V_244 = V_45 + V_232 ;
}
V_214 = F_16 ( V_2 , V_244 ) ;
if ( V_214 < 0 )
return V_214 ;
return 1 ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_31 , T_4 * V_241 ,
const struct V_93 * V_94 , bool V_245 ,
const struct V_230 * V_231 )
{
struct V_190 * V_191 ;
int V_246 ;
T_4 V_247 ;
int V_248 = V_2 -> V_52 ;
T_4 V_249 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_27 ;
int V_60 = 0 ;
int V_250 = V_2 -> V_23 -> V_58 ;
int V_214 ;
struct V_9 * V_10 ;
struct V_242 V_243 = { . V_2 . V_23 = V_2 -> V_23 , } ;
if ( V_2 -> V_14 != 0 )
V_250 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_118 ( V_108 , & V_10 -> V_109 ) &&
( V_31 == V_62 ) )
goto V_251;
V_191 = V_10 -> V_17 ;
V_27 = V_191 -> V_18 + V_10 -> V_19 ;
F_86 ( ! F_87 ( V_191 ) ) ;
if ( V_31 != V_178 && V_10 -> V_26 )
V_27 = V_10 -> V_26 + V_10 -> V_19 ;
V_247 = V_2 -> V_14 ;
V_14 = F_13 ( V_27 , V_10 -> V_12 , V_2 -> V_14 , V_31 ) ;
if ( V_14 == V_44 )
goto V_252;
V_2 -> V_14 = V_14 ;
if ( V_94 == NULL )
return 0 ;
V_246 = V_2 -> V_52 ;
V_214 = F_117 ( V_2 , V_94 ,
V_241 ? * V_241 : 0 ,
& V_243 ) ;
if ( V_214 == 0 )
return 0 ;
if ( V_214 > 0 ) {
V_60 += ( V_2 -> V_52 - V_246 ) ;
goto V_253;
}
if ( V_214 == - V_51 ) {
V_2 -> V_52 = 0 ;
V_2 -> V_14 = 0 ;
V_60 += ( V_2 -> V_52 - V_246 ) ;
goto V_254;
}
return V_214 ;
V_252:
if ( ( V_31 == V_62 ) && V_247 == 0 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_119 ( V_108 , & V_10 -> V_109 ) ;
}
V_251:
V_2 -> V_14 = 0 ;
V_2 -> V_52 ++ ;
if ( V_2 -> V_52 == V_2 -> V_23 -> V_58 )
V_2 -> V_52 = 0 ;
V_254:
if ( ( V_2 -> V_52 == 0 ) && V_245 )
break;
V_60 ++ ;
V_253:
if ( V_60 >= V_250 )
break;
}
if ( V_241 == NULL || V_31 != V_62 )
return - V_255 ;
if ( ( V_249 == 0 ) && ( V_248 == 0 ) &&
( * V_241 < V_2 -> V_23 -> V_107 ) )
V_2 -> V_23 -> V_107 = * V_241 ;
if ( V_243 . V_35 ) {
* V_2 = V_243 . V_2 ;
* V_241 = V_243 . V_35 ;
return 0 ;
}
return - V_255 ;
}
static void F_120 ( struct V_70 * V_23 , T_2 * V_256 , T_2 V_257 )
{
T_2 V_45 ;
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_112 * V_113 ;
struct V_93 * V_94 ;
int error ;
int V_258 = 0 ;
struct V_1 V_2 = { . V_23 = V_23 , . V_52 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_38 ( & V_76 -> V_259 ) ;
error = F_115 ( & V_2 , V_178 , NULL , NULL ,
true , NULL ) ;
F_41 ( & V_76 -> V_259 ) ;
if ( error == - V_255 )
break;
if ( F_17 ( error ) )
break;
V_45 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_45 + 1 ) )
break;
if ( * V_256 != V_260 && V_45 <= * V_256 )
continue;
if ( V_45 == V_257 )
continue;
* V_256 = V_45 ;
error = F_72 ( V_76 , V_45 , & V_261 , V_143 , & V_113 ) ;
if ( error )
continue;
V_94 = V_113 -> V_116 ;
if ( V_94 || F_121 ( V_262 , & V_113 -> V_263 ) == 0 )
F_56 ( V_113 ) ;
else
V_258 ++ ;
if ( V_258 > V_264 )
return;
}
V_23 -> V_149 &= ~ V_182 ;
return;
}
static bool F_122 ( const struct V_70 * V_23 , int V_265 )
{
const struct V_112 * V_113 = V_23 -> V_114 ;
const struct V_75 * V_76 = V_113 -> V_266 ;
struct V_267 * V_268 ;
T_9 V_269 , V_270 ;
T_9 V_271 , V_272 ;
T_9 V_273 ;
T_9 V_274 ;
T_9 V_275 ;
F_123 () ;
V_268 = & F_124 ( V_76 -> V_276 ) -> V_277 [ V_278 ] ;
V_271 = V_268 -> V_279 [ V_280 ] ;
V_269 = V_268 -> V_279 [ V_281 ] ;
V_275 = V_268 -> V_279 [ V_282 ] +
V_113 -> V_283 . V_279 [ V_282 ] ;
F_125 () ;
V_272 = V_113 -> V_283 . V_279 [ V_280 ] ;
V_270 = V_113 -> V_283 . V_279 [ V_281 ] ;
if ( ( V_270 < 1 ) || ( V_269 < 1 ) || ( V_271 == 0 ) )
return false ;
V_273 = V_271 - V_272 ;
V_274 = V_273 * V_273 ;
V_275 *= 2 ;
if ( V_270 < 8 || V_269 < 8 )
V_275 *= 2 ;
if ( V_265 == 1 )
V_275 *= 2 ;
return ( ( V_273 < 0 ) && ( V_274 > V_275 ) ) ;
}
static bool F_126 ( const struct V_36 * V_37 ,
T_2 V_284 )
{
T_2 V_285 ;
V_285 = F_127 ( F_128 ( F_129 () ,
V_37 -> V_39 . V_23 -> V_114 -> V_286 ) ) ;
return V_285 > ( V_284 * 1000 * 1000 ) ;
}
static T_4 F_130 ( const struct V_93 * V_94 )
{
const struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
T_4 V_257 ;
F_131 ( & V_257 , sizeof( V_257 ) ) ;
return V_257 % V_76 -> V_134 ;
}
static bool F_132 ( struct V_70 * * V_129 , const struct V_70 * V_287 )
{
struct V_70 * V_23 = * V_129 ;
struct V_75 * V_76 = V_23 -> V_56 ;
V_23 = F_33 ( V_23 ) ;
if ( V_23 == NULL )
V_23 = F_31 ( V_76 ) ;
* V_129 = V_23 ;
if ( V_23 != V_287 )
return true ;
return false ;
}
int F_133 ( struct V_93 * V_94 , const struct V_230 * V_231 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
struct V_70 * V_287 = NULL ;
struct V_36 * V_37 = V_94 -> V_96 ;
int error = 0 , V_288 , V_289 = 0 ;
T_2 V_256 = V_260 ;
int V_265 = 0 ;
T_4 V_257 = 0 ;
if ( V_76 -> V_184 . V_185 )
V_289 |= V_189 ;
if ( F_93 ( V_76 , V_231 -> V_236 ) )
return - V_49 ;
if ( F_45 ( V_37 ) ) {
V_287 = V_37 -> V_39 . V_23 ;
} else if ( V_94 -> V_290 && F_26 ( V_94 -> V_290 , V_94 -> V_238 ) ) {
V_37 -> V_39 . V_23 = V_287 = V_94 -> V_290 ;
} else {
V_37 -> V_39 . V_23 = V_287 = F_27 ( V_76 , V_94 -> V_238 , 1 ) ;
}
if ( F_113 ( V_94 -> V_135 . V_234 ) && ( V_231 -> V_291 & V_292 ) )
V_257 = F_130 ( V_94 ) ;
if ( V_37 -> V_39 . V_23 == NULL )
return - V_293 ;
while ( V_265 < 3 ) {
V_288 = 1 ;
if ( ! F_75 ( V_37 -> V_39 . V_23 -> V_114 ) ) {
V_288 = 0 ;
if ( V_257 && V_257 -- )
goto V_294;
if ( ! F_45 ( V_37 ) && ( V_265 < 2 ) &&
F_126 ( V_37 , 1000 ) &&
F_122 ( V_37 -> V_39 . V_23 , V_265 ) )
goto V_294;
error = F_76 ( V_37 -> V_39 . V_23 -> V_114 ,
V_224 , V_289 ,
& V_37 -> V_295 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_45 ( V_37 ) && ( V_265 < 2 ) &&
F_122 ( V_37 -> V_39 . V_23 , V_265 ) )
goto V_296;
if ( V_76 -> V_184 . V_185 ) {
error = F_94 ( V_37 -> V_39 . V_23 ) ;
if ( F_4 ( error ) ) {
F_77 ( & V_37 -> V_295 ) ;
return error ;
}
}
}
if ( ( V_37 -> V_39 . V_23 -> V_149 & ( V_297 |
V_298 ) ) ||
( V_231 -> V_236 > V_37 -> V_39 . V_23 -> V_107 ) )
goto V_296;
if ( V_76 -> V_184 . V_185 )
F_88 ( V_37 -> V_39 . V_23 ) ;
if ( ! F_45 ( V_37 ) )
F_112 ( V_37 -> V_39 . V_23 , V_94 , V_231 ) ;
if ( ! F_45 ( V_37 ) && ( V_265 < 1 ) )
goto V_299;
if ( V_37 -> V_39 . V_23 -> V_183 >= V_231 -> V_236 ) {
V_94 -> V_290 = V_37 -> V_39 . V_23 ;
return 0 ;
}
V_299:
if ( V_37 -> V_39 . V_23 -> V_149 & V_182 )
F_120 ( V_37 -> V_39 . V_23 , & V_256 ,
V_94 -> V_240 ) ;
V_296:
if ( F_45 ( V_37 ) )
F_49 ( V_37 ) ;
if ( ! V_288 )
F_77 ( & V_37 -> V_295 ) ;
V_294:
if ( F_132 ( & V_37 -> V_39 . V_23 , V_287 ) )
continue;
if ( V_257 )
continue;
V_265 ++ ;
if ( V_94 == F_61 ( V_76 -> V_126 ) && ! V_76 -> V_152 ) {
error = F_73 ( V_94 ) ;
if ( error )
return error ;
}
if ( V_265 == 2 )
F_134 ( V_76 , NULL ) ;
}
return - V_255 ;
}
void F_135 ( struct V_93 * V_94 )
{
struct V_36 * V_37 = V_94 -> V_96 ;
if ( V_37 -> V_295 . V_187 )
F_77 ( & V_37 -> V_295 ) ;
}
static unsigned char F_136 ( struct V_70 * V_23 , T_2 V_45 )
{
struct V_1 V_2 = { . V_23 = V_23 , } ;
int V_214 ;
V_214 = F_16 ( & V_2 , V_45 ) ;
F_17 ( V_214 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_137 ( const struct V_1 * V_2 , bool V_300 ,
unsigned int * V_60 )
{
struct V_1 V_129 = { . V_23 = V_2 -> V_23 , } ;
const unsigned int V_301 = * V_60 ;
T_2 V_45 ;
int V_214 ;
* V_60 = 1 ;
V_45 = F_12 ( V_2 ) ;
F_108 ( V_2 -> V_23 -> V_114 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_300 ? V_302 : V_303 ) ;
V_45 ++ ;
while ( * V_60 < V_301 ) {
V_214 = F_16 ( & V_129 , V_45 ) ;
if ( V_214 || F_8 ( & V_129 ) != V_62 )
break;
F_108 ( V_129 . V_23 -> V_114 , F_2 ( & V_129 ) -> V_17 ) ;
F_1 ( & V_129 , true , V_303 ) ;
( * V_60 ) ++ ;
V_45 ++ ;
}
}
static struct V_70 * F_138 ( struct V_75 * V_76 , T_2 V_304 ,
T_4 V_305 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 ;
V_2 . V_23 = F_27 ( V_76 , V_304 , 1 ) ;
if ( ! V_2 . V_23 ) {
if ( F_139 ( V_76 ) )
F_25 ( V_76 , L_16 , ( unsigned long long ) V_304 ) ;
return NULL ;
}
while ( V_305 -- ) {
F_16 ( & V_2 , V_304 ) ;
V_10 = F_2 ( & V_2 ) ;
V_304 ++ ;
if ( ! V_10 -> V_26 ) {
V_10 -> V_26 = F_140 ( V_10 -> V_17 -> V_69 ,
V_98 | V_306 ) ;
memcpy ( V_10 -> V_26 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 , V_10 -> V_12 ) ;
}
F_108 ( V_2 . V_23 -> V_114 , V_10 -> V_17 ) ;
F_1 ( & V_2 , false , V_4 ) ;
}
return V_2 . V_23 ;
}
void F_141 ( struct V_101 * V_102 , const struct V_112 * V_113 )
{
struct V_70 * V_23 = V_113 -> V_116 ;
struct V_36 * V_307 ;
const struct V_85 * V_60 ;
if ( V_23 == NULL )
return;
F_43 ( V_102 , L_17 ,
( unsigned long long ) V_23 -> V_24 , V_23 -> V_149 ,
V_23 -> V_80 , V_23 -> V_183 , V_23 -> V_81 ,
V_23 -> V_106 , V_23 -> V_107 ) ;
F_28 ( & V_23 -> V_110 ) ;
for ( V_60 = F_32 ( & V_23 -> V_105 ) ; V_60 ; V_60 = F_34 ( & V_307 -> V_100 ) ) {
V_307 = F_29 ( V_60 , struct V_36 , V_100 ) ;
F_42 ( V_102 , V_307 ) ;
}
F_30 ( & V_23 -> V_110 ) ;
}
static void F_142 ( struct V_70 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
F_99 ( V_76 , L_18 ,
( unsigned long long ) V_23 -> V_24 ) ;
F_99 ( V_76 , L_19 ) ;
F_141 ( NULL , V_23 -> V_114 ) ;
V_23 -> V_149 |= V_298 ;
}
static void F_143 ( struct V_93 * V_94 ,
const struct V_1 * V_2 , unsigned V_35 )
{
struct V_36 * V_37 = V_94 -> V_96 ;
struct V_70 * V_23 = V_2 -> V_23 ;
unsigned V_308 ;
T_2 V_45 ;
int V_214 ;
F_28 ( & V_23 -> V_110 ) ;
if ( F_45 ( V_37 ) ) {
if ( F_144 ( & V_37 -> V_39 , V_2 ) ) {
V_45 = F_12 ( V_2 ) ;
V_214 = F_16 ( & V_37 -> V_39 , V_45 + V_35 ) ;
V_308 = F_145 ( V_37 -> V_40 , V_35 ) ;
V_37 -> V_40 -= V_308 ;
V_23 -> V_106 -= V_308 ;
F_46 ( V_37 , V_309 ) ;
if ( V_37 -> V_40 && ! V_214 )
goto V_68;
}
F_44 ( V_37 ) ;
}
V_68:
F_30 ( & V_23 -> V_110 ) ;
}
static void F_146 ( struct V_1 * V_2 ,
const struct V_93 * V_94 , bool V_300 )
{
T_2 V_42 ;
if ( F_45 ( V_94 -> V_96 ) ) {
* V_2 = V_94 -> V_96 -> V_39 ;
return;
}
if ( ! V_300 && F_26 ( V_2 -> V_23 , V_94 -> V_238 ) )
V_42 = V_94 -> V_238 ;
else
V_42 = V_2 -> V_23 -> V_239 + V_2 -> V_23 -> V_47 ;
F_16 ( V_2 , V_42 ) ;
}
int F_147 ( struct V_93 * V_94 , T_2 * V_310 , unsigned int * V_311 ,
bool V_300 , T_2 * V_312 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
struct V_190 * V_313 ;
struct V_1 V_2 = { . V_23 = V_94 -> V_290 , } ;
unsigned int V_314 ;
T_2 V_45 ;
int error ;
F_146 ( & V_2 , V_94 , V_300 ) ;
error = F_115 ( & V_2 , V_62 , NULL , V_94 , false , NULL ) ;
if ( error == - V_255 ) {
F_146 ( & V_2 , V_94 , V_300 ) ;
error = F_115 ( & V_2 , V_62 , NULL , NULL , false ,
NULL ) ;
}
if ( error ) {
F_99 ( V_76 , L_20 ,
( unsigned long long ) V_94 -> V_240 , error , * V_311 ,
F_118 ( V_108 , & V_2 . V_23 -> V_79 -> V_109 ) ,
V_2 . V_23 -> V_107 ) ;
goto V_315;
}
F_137 ( & V_2 , V_300 , V_311 ) ;
V_45 = F_12 ( & V_2 ) ;
V_2 . V_23 -> V_239 = V_45 - V_2 . V_23 -> V_47 ;
if ( F_45 ( V_94 -> V_96 ) )
F_143 ( V_94 , & V_2 , * V_311 ) ;
V_314 = * V_311 ;
if ( V_300 )
V_314 -- ;
if ( ! V_300 ) {
V_94 -> V_238 = V_45 + V_314 - 1 ;
error = F_148 ( V_94 , & V_313 ) ;
if ( error == 0 ) {
struct V_316 * V_317 =
(struct V_316 * ) V_313 -> V_18 ;
F_108 ( V_94 -> V_153 , V_313 ) ;
V_317 -> V_318 = V_317 -> V_319 =
F_81 ( V_94 -> V_238 ) ;
F_92 ( V_313 ) ;
}
}
if ( V_2 . V_23 -> V_80 < * V_311 ) {
F_5 ( V_22 L_21 , * V_311 ) ;
goto V_315;
}
V_2 . V_23 -> V_80 -= * V_311 ;
if ( V_300 ) {
V_2 . V_23 -> V_81 ++ ;
* V_312 = V_2 . V_23 -> V_163 ++ ;
if ( * V_312 == 0 )
* V_312 = V_2 . V_23 -> V_163 ++ ;
}
F_108 ( V_2 . V_23 -> V_114 , V_2 . V_23 -> V_79 [ 0 ] . V_17 ) ;
F_79 ( V_2 . V_23 , V_2 . V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_83 ( V_2 . V_23 -> V_145 , V_2 . V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_149 ( V_76 , 0 , - ( T_9 ) * V_311 , V_300 ? 1 : 0 ) ;
if ( V_300 )
F_150 ( V_76 , V_45 , 1 ) ;
F_151 ( V_94 , * V_311 , V_94 -> V_135 . V_320 , V_94 -> V_135 . V_321 ) ;
V_2 . V_23 -> V_183 -= * V_311 ;
F_152 ( V_94 , V_2 . V_23 , V_45 , * V_311 ,
V_300 ? V_302 : V_303 ) ;
* V_310 = V_45 ;
return 0 ;
V_315:
F_142 ( V_2 . V_23 ) ;
return - V_123 ;
}
void F_153 ( struct V_93 * V_94 , T_2 V_304 , T_4 V_305 , int V_322 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
struct V_70 * V_23 ;
V_23 = F_138 ( V_76 , V_304 , V_305 , V_62 ) ;
if ( ! V_23 )
return;
F_152 ( V_94 , V_23 , V_304 , V_305 , V_62 ) ;
V_23 -> V_80 += V_305 ;
V_23 -> V_149 &= ~ V_225 ;
F_108 ( V_23 -> V_114 , V_23 -> V_79 [ 0 ] . V_17 ) ;
F_79 ( V_23 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_83 ( V_23 -> V_145 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
if ( V_322 || V_94 -> V_323 )
F_154 ( V_94 , V_304 , V_305 ) ;
}
void F_155 ( struct V_93 * V_94 , T_2 V_304 , T_4 V_305 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
F_153 ( V_94 , V_304 , V_305 , 1 ) ;
F_149 ( V_76 , 0 , + V_305 , 0 ) ;
F_151 ( V_94 , - ( T_9 ) V_305 , V_94 -> V_135 . V_320 , V_94 -> V_135 . V_321 ) ;
}
void F_156 ( struct V_125 * V_125 )
{
struct V_93 * V_94 = F_61 ( V_125 ) ;
struct V_75 * V_76 = F_69 ( V_125 ) ;
struct V_70 * V_23 ;
T_2 V_324 = V_94 -> V_240 ;
V_23 = F_138 ( V_76 , V_324 , 1 , V_178 ) ;
if ( ! V_23 )
return;
F_152 ( V_94 , V_23 , V_324 , 1 , V_178 ) ;
F_108 ( V_23 -> V_114 , V_23 -> V_79 [ 0 ] . V_17 ) ;
F_79 ( V_23 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_83 ( V_23 -> V_145 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_23 , 1 ) ;
}
static void F_157 ( struct V_70 * V_23 , T_2 V_324 )
{
struct V_75 * V_76 = V_23 -> V_56 ;
struct V_70 * V_325 ;
V_325 = F_138 ( V_76 , V_324 , 1 , V_62 ) ;
if ( ! V_325 )
return;
F_158 ( V_76 , V_23 == V_325 ) ;
if ( ! V_23 -> V_81 )
F_7 ( V_23 ) ;
V_23 -> V_81 -- ;
V_23 -> V_80 ++ ;
F_108 ( V_23 -> V_114 , V_23 -> V_79 [ 0 ] . V_17 ) ;
F_79 ( V_23 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_83 ( V_23 -> V_145 , V_23 -> V_79 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_23 , - 1 ) ;
F_149 ( V_76 , 0 , + 1 , - 1 ) ;
}
void F_159 ( struct V_70 * V_23 , struct V_93 * V_94 )
{
F_157 ( V_23 , V_94 -> V_240 ) ;
F_152 ( V_94 , V_23 , V_94 -> V_240 , 1 , V_62 ) ;
F_151 ( V_94 , - 1 , V_94 -> V_135 . V_320 , V_94 -> V_135 . V_321 ) ;
F_154 ( V_94 , V_94 -> V_240 , 1 ) ;
}
int F_160 ( struct V_75 * V_76 , T_2 V_326 , unsigned int type )
{
struct V_70 * V_23 ;
struct V_154 V_327 ;
int error = - V_49 ;
V_23 = F_27 ( V_76 , V_326 , 1 ) ;
if ( ! V_23 )
goto V_141;
error = F_76 ( V_23 -> V_114 , V_157 , 0 , & V_327 ) ;
if ( error )
goto V_141;
if ( F_136 ( V_23 , V_326 ) != type )
error = - V_328 ;
F_77 ( & V_327 ) ;
V_141:
return error ;
}
void F_161 ( struct V_93 * V_94 , struct V_329 * V_330 ,
T_2 V_45 )
{
struct V_75 * V_76 = F_69 ( & V_94 -> V_135 ) ;
struct V_70 * V_23 ;
struct V_70 * * V_32 ;
unsigned int V_331 ;
unsigned int V_78 ;
if ( F_93 ( V_76 , ! V_330 -> V_332 ) )
return;
if ( V_94 -> V_290 && F_26 ( V_94 -> V_290 , V_45 ) )
V_23 = V_94 -> V_290 ;
else
V_23 = F_27 ( V_76 , V_45 , 1 ) ;
if ( ! V_23 ) {
F_25 ( V_76 , L_22 , ( unsigned long long ) V_45 ) ;
return;
}
V_94 -> V_290 = V_23 ;
for ( V_78 = 0 ; V_78 < V_330 -> V_333 ; V_78 ++ )
if ( V_330 -> V_334 [ V_78 ] == V_23 )
return;
if ( V_330 -> V_333 == V_330 -> V_335 ) {
V_331 = V_330 -> V_335 + 10 ;
V_32 = F_59 ( V_331 , sizeof( struct V_70 * ) ,
V_98 | V_306 ) ;
if ( V_330 -> V_334 ) {
memcpy ( V_32 , V_330 -> V_334 ,
V_330 -> V_335 * sizeof( struct V_70 * ) ) ;
F_36 ( V_330 -> V_334 ) ;
}
V_330 -> V_335 = V_331 ;
V_330 -> V_334 = V_32 ;
}
V_330 -> V_334 [ V_330 -> V_333 ++ ] = V_23 ;
}
void F_162 ( struct V_329 * V_330 , unsigned int V_31 )
{
unsigned int V_78 ;
V_330 -> V_332 = F_59 ( V_330 -> V_333 , sizeof( struct V_154 ) ,
V_98 | V_306 ) ;
for ( V_78 = 0 ; V_78 < V_330 -> V_333 ; V_78 ++ )
F_163 ( V_330 -> V_334 [ V_78 ] -> V_114 ,
V_31 , 0 ,
& V_330 -> V_332 [ V_78 ] ) ;
}
void F_164 ( struct V_329 * V_330 )
{
unsigned int V_78 ;
F_36 ( V_330 -> V_334 ) ;
if ( V_330 -> V_332 ) {
for ( V_78 = 0 ; V_78 < V_330 -> V_333 ; V_78 ++ )
F_165 ( & V_330 -> V_332 [ V_78 ] ) ;
F_36 ( V_330 -> V_332 ) ;
V_330 -> V_332 = NULL ;
}
}
