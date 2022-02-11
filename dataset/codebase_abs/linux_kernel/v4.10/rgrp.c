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
F_5 ( L_1 ,
V_2 -> V_14 , V_8 , V_4 ) ;
F_5 ( L_2 ,
( unsigned long long ) V_2 -> V_22 -> V_23 , V_10 -> V_24 ) ;
F_5 ( L_3 ,
V_10 -> V_19 , V_10 -> V_12 ) ;
F_6 () ;
F_7 ( V_2 -> V_22 ) ;
return;
}
* V_5 ^= ( V_8 ^ V_4 ) << V_13 ;
if ( V_3 && V_10 -> V_25 ) {
V_6 = V_10 -> V_25 + V_10 -> V_19 + ( V_2 -> V_14 / V_15 ) ;
V_8 = ( * V_6 >> V_13 ) & V_20 ;
* V_6 ^= ( V_8 ^ V_4 ) << V_13 ;
}
}
static inline T_1 F_8 ( const struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
const T_1 * V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
const T_1 * V_27 ;
unsigned int V_13 ;
V_27 = V_26 + ( V_2 -> V_14 / V_15 ) ;
V_13 = ( V_2 -> V_14 % V_15 ) * V_16 ;
return ( * V_27 >> V_13 ) & V_20 ;
}
static inline T_2 F_9 ( const T_3 * V_28 , T_2 V_29 , T_1 V_30 )
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
static inline int F_11 ( T_2 V_33 , T_4 V_34 , struct V_35 * V_36 )
{
T_2 V_37 = F_12 ( & V_36 -> V_38 ) ;
if ( V_33 >= V_37 + V_36 -> V_39 )
return 1 ;
if ( V_33 + V_34 - 1 < V_37 )
return - 1 ;
return 0 ;
}
static T_4 F_13 ( const T_1 * V_40 , const unsigned int V_34 ,
T_4 V_41 , T_1 V_30 )
{
T_4 V_42 = ( V_41 << 1 ) & ( ( 8 * sizeof( T_2 ) ) - 1 ) ;
const T_3 * V_28 = ( ( T_3 * ) V_40 ) + ( V_41 >> 5 ) ;
const T_3 * V_7 = ( T_3 * ) ( V_40 + F_14 ( V_34 , sizeof( T_2 ) ) ) ;
T_2 V_31 ;
T_2 V_29 = 0x5555555555555555ULL ;
T_4 V_13 ;
V_29 <<= V_42 ;
V_31 = F_9 ( V_28 , V_29 , V_30 ) ;
V_28 ++ ;
while( V_31 == 0 && V_28 < V_7 ) {
V_31 = F_9 ( V_28 , 0x5555555555555555ULL , V_30 ) ;
V_28 ++ ;
}
if ( V_28 == V_7 && ( V_34 & ( sizeof( T_2 ) - 1 ) ) )
V_31 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_34 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_31 == 0 )
return V_43 ;
V_28 -- ;
V_13 = F_15 ( V_31 ) ;
V_13 /= 2 ;
return ( ( ( const unsigned char * ) V_28 - V_40 ) * V_15 ) + V_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_44 )
{
T_2 V_45 = V_44 - V_2 -> V_22 -> V_46 ;
if ( F_17 ( V_45 > V_47 ) )
return - V_48 ;
if ( V_44 >= V_2 -> V_22 -> V_46 + V_2 -> V_22 -> V_49 )
return - V_50 ;
V_2 -> V_51 = 0 ;
V_2 -> V_14 = ( T_4 ) ( V_45 ) ;
if ( V_2 -> V_14 < F_2 ( V_2 ) -> V_52 )
return 0 ;
V_2 -> V_14 += ( sizeof( struct V_53 ) -
sizeof( struct V_54 ) ) * V_15 ;
V_2 -> V_51 = V_2 -> V_14 / V_2 -> V_22 -> V_55 -> V_56 ;
V_2 -> V_14 -= V_2 -> V_51 * V_2 -> V_22 -> V_55 -> V_56 ;
return 0 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 + 1 < F_2 ( V_2 ) -> V_52 ) {
V_2 -> V_14 ++ ;
return false ;
}
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 - 1 )
return true ;
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
return false ;
}
static bool F_19 ( struct V_1 * V_2 , T_4 V_58 , T_4 * V_34 )
{
T_4 V_59 ;
T_1 V_60 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
V_60 = F_8 ( V_2 ) ;
if ( V_60 != V_61 )
return true ;
( * V_34 ) -- ;
if ( * V_34 == 0 )
return true ;
if ( F_18 ( V_2 ) )
return true ;
}
return false ;
}
static T_4 F_20 ( const struct V_1 * V_62 , T_4 V_34 )
{
struct V_1 V_2 = * V_62 ;
T_4 V_58 = V_2 . V_14 & 3 ;
T_4 V_63 = V_34 ;
T_4 V_64 ;
T_4 V_65 ;
T_1 * V_28 , * V_66 , * V_7 ;
T_2 V_44 ;
struct V_9 * V_10 ;
if ( V_58 &&
F_19 ( & V_2 , 4 - V_58 , & V_34 ) )
goto V_67;
V_58 = V_34 & 3 ;
while ( V_34 > 3 ) {
V_10 = F_2 ( & V_2 ) ;
V_66 = V_10 -> V_17 -> V_18 ;
if ( V_10 -> V_25 )
V_66 = V_10 -> V_25 ;
V_7 = V_66 + V_10 -> V_17 -> V_68 ;
V_66 += V_10 -> V_19 ;
F_3 ( V_2 . V_14 & 3 ) ;
V_66 += ( V_2 . V_14 / V_15 ) ;
V_64 = F_21 ( T_4 , V_34 / V_15 , ( V_7 - V_66 ) ) ;
V_28 = F_22 ( V_66 , 0 , V_64 ) ;
V_65 = ( ( V_28 == NULL ) ? V_64 : ( V_28 - V_66 ) ) ;
V_65 *= V_15 ;
F_3 ( V_34 < V_65 ) ;
V_34 -= V_65 ;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + V_65 ) ) {
V_58 = 0 ;
break;
}
if ( V_28 ) {
V_58 = 3 ;
break;
}
V_58 = V_34 & 3 ;
}
if ( V_58 )
F_19 ( & V_2 , V_58 , & V_34 ) ;
V_67:
return V_63 - V_34 ;
}
static T_4 F_23 ( struct V_69 * V_22 , const T_1 * V_26 ,
unsigned int V_11 , T_1 V_30 )
{
const T_1 * V_27 = V_26 ;
const T_1 * V_7 = V_26 + V_11 ;
const T_1 V_70 = V_30 << 2 ;
const T_1 V_71 = V_30 << 4 ;
const T_1 V_72 = V_30 << 6 ;
T_4 V_73 = 0 ;
for (; V_27 < V_7 ; V_27 ++ ) {
if ( ( ( * V_27 ) & 0x03 ) == V_30 )
V_73 ++ ;
if ( ( ( * V_27 ) & 0x0C ) == V_70 )
V_73 ++ ;
if ( ( ( * V_27 ) & 0x30 ) == V_71 )
V_73 ++ ;
if ( ( ( * V_27 ) & 0xC0 ) == V_72 )
V_73 ++ ;
}
return V_73 ;
}
void F_24 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 = NULL ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_73 [ 4 ] , V_31 ;
int V_40 , V_77 ;
memset ( V_73 , 0 , 4 * sizeof( T_4 ) ) ;
for ( V_40 = 0 ; V_40 < V_76 ; V_40 ++ ) {
V_10 = V_22 -> V_78 + V_40 ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ )
V_73 [ V_77 ] += F_23 ( V_22 ,
V_10 -> V_17 -> V_18 +
V_10 -> V_19 ,
V_10 -> V_12 , V_77 ) ;
}
if ( V_73 [ 0 ] != V_22 -> V_79 ) {
if ( F_7 ( V_22 ) )
F_25 ( V_75 , L_4 ,
V_73 [ 0 ] , V_22 -> V_79 ) ;
return;
}
V_31 = V_22 -> V_49 - V_22 -> V_79 - V_22 -> V_80 ;
if ( V_73 [ 1 ] != V_31 ) {
if ( F_7 ( V_22 ) )
F_25 ( V_75 , L_5 ,
V_73 [ 1 ] , V_31 ) ;
return;
}
if ( V_73 [ 2 ] + V_73 [ 3 ] != V_22 -> V_80 ) {
if ( F_7 ( V_22 ) )
F_25 ( V_75 , L_6 ,
V_73 [ 2 ] + V_73 [ 3 ] , V_22 -> V_80 ) ;
return;
}
}
static inline int F_26 ( struct V_69 * V_22 , T_2 V_44 )
{
T_2 V_81 = V_22 -> V_46 ;
T_2 V_82 = V_81 + V_22 -> V_49 ;
return V_81 <= V_44 && V_44 < V_82 ;
}
struct V_69 * F_27 ( struct V_74 * V_75 , T_2 V_33 , bool V_83 )
{
struct V_84 * V_59 , * V_85 ;
struct V_69 * V_86 ;
F_28 ( & V_75 -> V_87 ) ;
V_59 = V_75 -> V_88 . V_84 ;
while ( V_59 ) {
V_86 = F_29 ( V_59 , struct V_69 , V_89 ) ;
V_85 = NULL ;
if ( V_33 < V_86 -> V_23 )
V_85 = V_59 -> V_90 ;
else if ( V_33 >= V_86 -> V_46 + V_86 -> V_49 )
V_85 = V_59 -> V_91 ;
if ( V_85 == NULL ) {
F_30 ( & V_75 -> V_87 ) ;
if ( V_83 ) {
if ( V_33 < V_86 -> V_23 )
return NULL ;
if ( V_33 >= V_86 -> V_46 + V_86 -> V_49 )
return NULL ;
}
return V_86 ;
}
V_59 = V_85 ;
}
F_30 ( & V_75 -> V_87 ) ;
return NULL ;
}
struct V_69 * F_31 ( struct V_74 * V_75 )
{
const struct V_84 * V_59 ;
struct V_69 * V_22 ;
F_28 ( & V_75 -> V_87 ) ;
V_59 = F_32 ( & V_75 -> V_88 ) ;
V_22 = F_29 ( V_59 , struct V_69 , V_89 ) ;
F_30 ( & V_75 -> V_87 ) ;
return V_22 ;
}
struct V_69 * F_33 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
const struct V_84 * V_59 ;
F_28 ( & V_75 -> V_87 ) ;
V_59 = F_34 ( & V_22 -> V_89 ) ;
if ( V_59 == NULL )
V_59 = F_32 ( & V_75 -> V_88 ) ;
if ( F_4 ( & V_22 -> V_89 == V_59 ) ) {
F_30 ( & V_75 -> V_87 ) ;
return NULL ;
}
V_22 = F_29 ( V_59 , struct V_69 , V_89 ) ;
F_30 ( & V_75 -> V_87 ) ;
return V_22 ;
}
void F_35 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
if ( ! V_93 -> V_95 || F_27 ( V_75 , V_93 -> V_95 , 1 ) == NULL )
V_93 -> V_95 = V_93 -> V_96 ;
}
void F_37 ( struct V_69 * V_22 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
F_38 ( V_10 -> V_25 ) ;
V_10 -> V_25 = NULL ;
}
}
int F_39 ( struct V_92 * V_93 )
{
return F_40 ( V_93 ) ;
}
static void F_41 ( struct V_97 * V_98 , const struct V_35 * V_36 )
{
F_42 ( V_98 , L_7 ,
( unsigned long long ) V_36 -> V_99 ,
( unsigned long long ) F_12 ( & V_36 -> V_38 ) ,
V_36 -> V_38 . V_14 , V_36 -> V_39 ) ;
}
static void F_43 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
if ( ! F_44 ( V_36 ) )
return;
V_22 = V_36 -> V_38 . V_22 ;
F_45 ( V_36 , V_100 ) ;
F_46 ( & V_36 -> V_101 , & V_22 -> V_102 ) ;
F_47 ( & V_36 -> V_101 ) ;
if ( V_36 -> V_39 ) {
struct V_9 * V_10 = F_2 ( & V_36 -> V_38 ) ;
F_3 ( V_36 -> V_38 . V_22 -> V_103 < V_36 -> V_39 ) ;
V_36 -> V_38 . V_22 -> V_103 -= V_36 -> V_39 ;
V_22 -> V_104 += V_36 -> V_39 ;
V_36 -> V_39 = 0 ;
F_48 ( V_105 , & V_10 -> V_106 ) ;
}
}
void F_49 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_28 ( & V_22 -> V_107 ) ;
F_43 ( V_36 ) ;
F_3 ( V_36 -> V_39 ) ;
F_30 ( & V_22 -> V_107 ) ;
}
}
void F_50 ( struct V_92 * V_93 , T_5 * V_108 )
{
F_51 ( & V_93 -> V_109 ) ;
if ( ( V_108 == NULL ) || ( F_52 ( V_108 ) <= 1 ) )
F_49 ( & V_93 -> V_110 ) ;
F_53 ( & V_93 -> V_109 ) ;
F_54 ( V_93 , V_108 ) ;
}
static void F_55 ( struct V_69 * V_22 )
{
struct V_84 * V_59 ;
struct V_35 * V_36 ;
F_28 ( & V_22 -> V_107 ) ;
while ( ( V_59 = F_32 ( & V_22 -> V_102 ) ) ) {
V_36 = F_29 ( V_59 , struct V_35 , V_101 ) ;
F_43 ( V_36 ) ;
}
F_30 ( & V_22 -> V_107 ) ;
}
void F_56 ( struct V_74 * V_75 )
{
struct V_84 * V_59 ;
struct V_69 * V_22 ;
struct V_111 * V_112 ;
while ( ( V_59 = F_32 ( & V_75 -> V_88 ) ) ) {
V_22 = F_29 ( V_59 , struct V_69 , V_89 ) ;
V_112 = V_22 -> V_113 ;
F_46 ( V_59 , & V_75 -> V_88 ) ;
if ( V_112 ) {
F_28 ( & V_112 -> V_114 . V_115 ) ;
V_112 -> V_116 = NULL ;
F_30 ( & V_112 -> V_114 . V_115 ) ;
F_57 ( V_112 ) ;
F_58 ( V_112 ) ;
}
F_37 ( V_22 ) ;
F_38 ( V_22 -> V_78 ) ;
V_22 -> V_78 = NULL ;
F_55 ( V_22 ) ;
F_59 ( V_117 , V_22 ) ;
}
}
static void F_60 ( const struct V_69 * V_22 )
{
F_61 ( L_8 , ( unsigned long long ) V_22 -> V_23 ) ;
F_61 ( L_9 , V_22 -> V_57 ) ;
F_61 ( L_10 , ( unsigned long long ) V_22 -> V_46 ) ;
F_61 ( L_11 , V_22 -> V_49 ) ;
F_61 ( L_12 , V_22 -> V_118 ) ;
}
static int F_62 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_119 , V_64 ;
int V_77 ;
if ( ! V_76 )
return - V_48 ;
V_22 -> V_78 = F_63 ( V_76 , sizeof( struct V_9 ) , V_120 ) ;
if ( ! V_22 -> V_78 )
return - V_121 ;
V_119 = V_22 -> V_118 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
V_10 -> V_106 = 0 ;
if ( V_76 == 1 ) {
V_64 = V_119 ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 == 0 ) {
V_64 = V_75 -> V_122 . V_123 - sizeof( struct V_53 ) ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 + 1 == V_76 ) {
V_64 = V_119 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_118 - V_119 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else {
V_64 = V_75 -> V_122 . V_123 -
sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_118 - V_119 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
}
V_119 -= V_64 ;
}
if ( V_119 ) {
F_7 ( V_22 ) ;
return - V_124 ;
}
V_10 = V_22 -> V_78 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_12 ) * V_15 != V_22 -> V_49 ) {
if ( F_7 ( V_22 ) ) {
F_60 ( V_22 ) ;
F_25 ( V_75 , L_13 ,
V_10 -> V_24 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_124 ;
}
return 0 ;
}
T_2 F_64 ( struct V_74 * V_75 )
{
T_2 V_125 = 0 ;
struct V_126 * V_126 = V_75 -> V_127 ;
struct V_92 * V_93 = F_65 ( V_126 ) ;
char V_40 [ sizeof( struct V_128 ) ] ;
int error , V_129 ;
for ( V_129 = 0 ; ; V_129 ++ ) {
T_6 V_130 = V_129 * sizeof( struct V_128 ) ;
if ( V_130 + sizeof( struct V_128 ) > F_66 ( V_126 ) )
break;
error = F_67 ( V_93 , V_40 , & V_130 ,
sizeof( struct V_128 ) ) ;
if ( error != sizeof( struct V_128 ) )
break;
V_125 += F_68 ( ( (struct V_128 * ) V_40 ) -> V_131 ) ;
}
return V_125 ;
}
static int F_69 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_84 * * V_132 = & V_75 -> V_88 . V_84 , * V_133 = NULL ;
while ( * V_132 ) {
struct V_69 * V_86 = F_29 ( * V_132 , struct V_69 ,
V_89 ) ;
V_133 = * V_132 ;
if ( V_22 -> V_23 < V_86 -> V_23 )
V_132 = & ( ( * V_132 ) -> V_90 ) ;
else if ( V_22 -> V_23 > V_86 -> V_23 )
V_132 = & ( ( * V_132 ) -> V_91 ) ;
else
return - V_134 ;
}
F_70 ( & V_22 -> V_89 , V_133 , V_132 ) ;
F_71 ( & V_22 -> V_89 , & V_75 -> V_88 ) ;
V_75 -> V_135 ++ ;
return 0 ;
}
static int F_72 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
const unsigned V_136 = V_75 -> V_122 . V_123 ;
T_6 V_130 = V_75 -> V_135 * sizeof( struct V_128 ) ;
struct V_128 V_40 ;
int error ;
struct V_69 * V_22 ;
if ( V_130 >= F_66 ( & V_93 -> V_94 ) )
return 1 ;
error = F_67 ( V_93 , ( char * ) & V_40 , & V_130 ,
sizeof( struct V_128 ) ) ;
if ( error != sizeof( struct V_128 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_73 ( V_117 , V_120 ) ;
error = - V_121 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_75 ;
V_22 -> V_23 = F_74 ( V_40 . V_137 ) ;
V_22 -> V_57 = F_68 ( V_40 . V_138 ) ;
V_22 -> V_46 = F_74 ( V_40 . V_139 ) ;
V_22 -> V_49 = F_68 ( V_40 . V_131 ) ;
V_22 -> V_118 = F_68 ( V_40 . V_140 ) ;
F_75 ( & V_22 -> V_107 ) ;
error = F_62 ( V_22 ) ;
if ( error )
goto V_141;
error = F_76 ( V_75 , V_22 -> V_23 ,
& V_142 , V_143 , & V_22 -> V_113 ) ;
if ( error )
goto V_141;
V_22 -> V_144 = (struct V_145 * ) V_22 -> V_113 -> V_146 . V_147 ;
V_22 -> V_148 &= ~ ( V_149 | V_150 ) ;
if ( V_22 -> V_49 > V_75 -> V_151 )
V_75 -> V_151 = V_22 -> V_49 ;
F_28 ( & V_75 -> V_87 ) ;
error = F_69 ( V_22 ) ;
F_30 ( & V_75 -> V_87 ) ;
if ( ! error ) {
V_22 -> V_113 -> V_116 = V_22 ;
V_22 -> V_113 -> V_152 . V_66 = ( V_22 -> V_23 * V_136 ) & V_153 ;
V_22 -> V_113 -> V_152 . V_7 = F_77 ( ( V_22 -> V_23 +
V_22 -> V_57 ) * V_136 ) - 1 ;
return 0 ;
}
error = 0 ;
F_58 ( V_22 -> V_113 ) ;
V_141:
F_38 ( V_22 -> V_78 ) ;
V_22 -> V_78 = NULL ;
F_59 ( V_117 , V_22 ) ;
return error ;
}
static void F_78 ( struct V_74 * V_75 )
{
struct V_69 * V_22 , * V_81 ;
int V_154 ;
V_22 = F_31 ( V_75 ) ;
for ( V_154 = 0 ; V_154 < V_75 -> V_155 . V_156 ; V_154 ++ )
V_22 = F_33 ( V_22 ) ;
V_81 = V_22 ;
do {
V_22 -> V_148 |= V_150 ;
for ( V_154 = 0 ; V_154 < V_75 -> V_157 ; V_154 ++ ) {
V_22 = F_33 ( V_22 ) ;
if ( ! V_22 || V_22 == V_81 )
break;
}
} while ( V_22 && V_22 != V_81 );
}
static int F_79 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
int error ;
do {
error = F_72 ( V_93 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
F_78 ( V_75 ) ;
V_75 -> V_158 = 1 ;
return 0 ;
}
int F_80 ( struct V_74 * V_75 )
{
struct V_92 * V_93 = F_65 ( V_75 -> V_127 ) ;
struct V_111 * V_112 = V_93 -> V_159 ;
struct V_160 V_161 ;
int error = 0 ;
int V_162 = 0 ;
if ( ! V_75 -> V_158 ) {
if ( ! F_81 ( V_112 ) ) {
error = F_82 ( V_112 , V_163 , 0 , & V_161 ) ;
if ( error )
return error ;
V_162 = 1 ;
}
if ( ! V_75 -> V_158 )
error = F_79 ( V_93 ) ;
if ( V_162 )
F_83 ( & V_161 ) ;
}
return error ;
}
static void F_84 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_164 = V_40 ;
T_4 V_165 ;
V_165 = F_68 ( V_164 -> V_165 ) ;
V_165 &= ~ V_166 ;
V_22 -> V_148 &= V_166 ;
V_22 -> V_148 |= V_165 ;
V_22 -> V_79 = F_68 ( V_164 -> V_167 ) ;
V_22 -> V_80 = F_68 ( V_164 -> V_168 ) ;
V_22 -> V_169 = F_74 ( V_164 -> V_170 ) ;
}
static void F_85 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_164 = V_40 ;
V_164 -> V_165 = F_86 ( V_22 -> V_148 & ~ V_166 ) ;
V_164 -> V_167 = F_86 ( V_22 -> V_79 ) ;
V_164 -> V_168 = F_86 ( V_22 -> V_80 ) ;
V_164 -> V_171 = F_86 ( 0 ) ;
V_164 -> V_170 = F_87 ( V_22 -> V_169 ) ;
memset ( & V_164 -> V_172 , 0 , sizeof( V_164 -> V_172 ) ) ;
}
static int F_88 ( struct V_69 * V_22 )
{
struct V_145 * V_173 = V_22 -> V_144 ;
struct V_53 * V_164 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_173 -> V_174 != V_164 -> V_165 || V_173 -> V_175 != V_164 -> V_167 ||
V_173 -> V_176 != V_164 -> V_168 ||
V_173 -> V_177 != V_164 -> V_170 )
return 0 ;
return 1 ;
}
static void F_89 ( struct V_145 * V_173 , const void * V_40 )
{
const struct V_53 * V_164 = V_40 ;
V_173 -> V_178 = F_86 ( V_179 ) ;
V_173 -> V_174 = V_164 -> V_165 ;
V_173 -> V_175 = V_164 -> V_167 ;
V_173 -> V_176 = V_164 -> V_168 ;
V_173 -> V_177 = V_164 -> V_170 ;
V_173 -> V_171 = 0UL ;
}
static void F_90 ( struct V_69 * V_22 , T_4 V_180 )
{
struct V_145 * V_173 = V_22 -> V_144 ;
T_4 V_181 = F_68 ( V_173 -> V_182 ) + V_180 ;
V_173 -> V_182 = F_86 ( V_181 ) ;
}
static T_4 F_91 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_154 , V_41 , V_73 = 0 ;
for ( V_154 = 0 , V_10 = V_22 -> V_78 ; V_154 < V_76 ; V_154 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_92 ( ! F_93 ( V_10 -> V_17 ) ) ;
while ( V_41 < V_10 -> V_12 * V_15 ) {
V_41 = F_13 ( V_26 , V_10 -> V_12 , V_41 ,
V_183 ) ;
if ( V_41 == V_43 )
break;
V_73 ++ ;
V_41 ++ ;
}
}
return V_73 ;
}
static int F_94 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_111 * V_112 = V_22 -> V_113 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_184 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_95 ( V_112 , V_22 -> V_23 + V_77 , 0 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_141;
}
for ( V_184 = V_76 ; V_184 -- ; ) {
V_10 = V_22 -> V_78 + V_184 ;
error = F_96 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_141;
if ( F_97 ( V_75 , V_10 -> V_17 , V_184 ? V_185 :
V_186 ) ) {
error = - V_124 ;
goto V_141;
}
}
if ( ! ( V_22 -> V_148 & V_149 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_48 ( V_105 , & V_22 -> V_78 [ V_77 ] . V_106 ) ;
F_84 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_148 |= ( V_149 | V_187 ) ;
V_22 -> V_188 = V_22 -> V_79 ;
V_22 -> V_104 = V_22 -> V_79 ;
}
if ( F_86 ( V_179 ) != V_22 -> V_144 -> V_178 ) {
V_22 -> V_144 -> V_182 = F_86 ( F_91 ( V_22 ) ) ;
F_89 ( V_22 -> V_144 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_189 . V_190 ) {
if ( ! F_88 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_124 ;
goto V_141;
}
if ( V_22 -> V_144 -> V_182 == 0 )
V_22 -> V_148 &= ~ V_187 ;
}
return 0 ;
V_141:
while ( V_77 -- ) {
V_10 = V_22 -> V_78 + V_77 ;
F_98 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_99 ( V_75 , ! V_10 -> V_25 ) ;
}
return error ;
}
static int F_100 ( struct V_69 * V_22 )
{
T_4 V_174 ;
if ( V_22 -> V_148 & V_149 )
return 0 ;
if ( F_86 ( V_179 ) != V_22 -> V_144 -> V_178 )
return F_94 ( V_22 ) ;
V_174 = F_68 ( V_22 -> V_144 -> V_174 ) ;
V_174 &= ~ V_166 ;
V_22 -> V_148 &= V_166 ;
V_22 -> V_148 |= ( V_174 | V_149 | V_187 ) ;
if ( V_22 -> V_144 -> V_182 == 0 )
V_22 -> V_148 &= ~ V_187 ;
V_22 -> V_79 = F_68 ( V_22 -> V_144 -> V_175 ) ;
V_22 -> V_188 = V_22 -> V_79 ;
V_22 -> V_80 = F_68 ( V_22 -> V_144 -> V_176 ) ;
V_22 -> V_169 = F_74 ( V_22 -> V_144 -> V_177 ) ;
return 0 ;
}
int F_101 ( struct V_160 * V_191 )
{
struct V_69 * V_22 = V_191 -> V_192 -> V_116 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_191 -> V_193 & V_194 && V_75 -> V_189 . V_190 )
return 0 ;
return F_94 ( V_22 ) ;
}
void F_102 ( struct V_69 * V_22 )
{
int V_77 , V_76 = V_22 -> V_57 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
if ( V_10 -> V_17 ) {
F_98 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
void F_103 ( struct V_160 * V_191 )
{
struct V_69 * V_22 = V_191 -> V_192 -> V_116 ;
int V_195 = F_104 ( V_196 , & V_191 -> V_192 -> V_197 ) |
F_104 ( V_198 , & V_191 -> V_192 -> V_197 ) ;
if ( V_22 && V_195 )
F_102 ( V_22 ) ;
}
int F_105 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_199 * V_200 ,
const struct V_9 * V_10 , unsigned V_201 , T_2 * V_202 )
{
struct V_203 * V_204 = V_75 -> V_205 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_206 = 0 ;
int V_207 ;
unsigned int V_77 ;
T_4 V_208 = 0 ;
T_1 V_209 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_210 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_210 += V_10 -> V_19 ;
V_210 += V_77 ;
if ( V_200 ) {
const T_1 * V_211 = V_200 -> V_18 + V_10 -> V_19 + V_77 ;
V_209 = ~ ( * V_211 | ( * V_211 >> 1 ) ) & ( * V_210 | ( * V_210 >> 1 ) ) ;
} else {
V_209 = ~ ( * V_210 | ( * V_210 >> 1 ) ) ;
}
V_209 &= 0x55 ;
if ( V_209 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_209 ) {
if ( V_209 & 1 ) {
if ( V_206 == 0 )
goto V_212;
if ( ( V_66 + V_206 ) != V_33 ) {
if ( V_206 >= V_201 ) {
V_207 = F_106 ( V_204 ,
V_66 , V_206 ,
V_120 , 0 ) ;
if ( V_207 )
goto V_141;
V_208 += V_206 ;
}
V_206 = 0 ;
V_212:
V_66 = V_33 ;
}
V_206 ++ ;
}
V_209 >>= 2 ;
V_33 ++ ;
}
}
if ( V_206 >= V_201 ) {
V_207 = F_106 ( V_204 , V_66 , V_206 , V_120 , 0 ) ;
if ( V_207 )
goto V_141;
V_208 += V_206 ;
}
if ( V_202 )
* V_202 = V_208 ;
return 0 ;
V_141:
if ( V_75 -> V_189 . V_213 )
F_107 ( V_75 , L_14 , V_207 ) ;
V_75 -> V_189 . V_213 = 0 ;
return - V_124 ;
}
int F_108 ( struct V_214 * V_215 , void T_8 * V_216 )
{
struct V_126 * V_126 = F_109 ( V_215 ) ;
struct V_74 * V_75 = F_36 ( V_126 ) ;
struct V_217 * V_218 = F_110 ( V_75 -> V_205 -> V_219 ) ;
struct V_199 * V_200 ;
struct V_69 * V_22 ;
struct V_69 * V_220 ;
struct V_160 V_191 ;
struct V_221 V_222 ;
int V_223 = 0 ;
T_2 V_224 ;
T_2 V_208 = 0 ;
T_2 V_66 , V_7 , V_201 ;
unsigned int V_77 ;
unsigned V_225 = V_75 -> V_122 . V_226 ;
if ( ! F_111 ( V_227 ) )
return - V_228 ;
if ( ! F_112 ( V_218 ) )
return - V_229 ;
if ( F_113 ( & V_222 , V_216 , sizeof( V_222 ) ) )
return - V_230 ;
V_223 = F_80 ( V_75 ) ;
if ( V_223 )
return V_223 ;
V_66 = V_222 . V_66 >> V_225 ;
V_7 = V_66 + ( V_222 . V_34 >> V_225 ) ;
V_201 = F_114 ( T_2 , V_222 . V_201 ,
V_218 -> V_231 . V_232 ) >> V_225 ;
if ( V_7 <= V_66 || V_201 > V_75 -> V_151 )
return - V_48 ;
V_22 = F_27 ( V_75 , V_66 , 0 ) ;
V_220 = F_27 ( V_75 , V_7 , 0 ) ;
if ( ( F_31 ( V_75 ) == F_33 ( V_220 ) )
&& ( V_66 > V_220 -> V_46 + V_220 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_223 = F_82 ( V_22 -> V_113 , V_233 , 0 , & V_191 ) ;
if ( V_223 )
goto V_67;
if ( ! ( V_22 -> V_148 & V_234 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_223 = F_105 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_201 ,
& V_224 ) ;
if ( V_223 ) {
F_83 ( & V_191 ) ;
goto V_67;
}
V_208 += V_224 ;
}
V_223 = F_115 ( V_75 , V_235 , 0 ) ;
if ( V_223 == 0 ) {
V_200 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_148 |= V_234 ;
F_116 ( V_22 -> V_113 , V_200 ) ;
F_85 ( V_22 , V_200 -> V_18 ) ;
F_89 ( V_22 -> V_144 , V_200 -> V_18 ) ;
F_117 ( V_75 ) ;
}
}
F_83 ( & V_191 ) ;
if ( V_22 == V_220 )
break;
V_22 = F_33 ( V_22 ) ;
}
V_67:
V_222 . V_34 = V_208 << V_225 ;
if ( F_118 ( V_216 , & V_222 , sizeof( V_222 ) ) )
return - V_230 ;
return V_223 ;
}
static void F_119 ( struct V_92 * V_93 )
{
struct V_84 * * V_132 , * V_133 = NULL ;
int V_236 ;
struct V_35 * V_36 = & V_93 -> V_110 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_237 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_44 ( V_36 ) ) ;
F_28 ( & V_22 -> V_107 ) ;
V_132 = & V_22 -> V_102 . V_84 ;
while ( * V_132 ) {
struct V_35 * V_86 =
F_29 ( * V_132 , struct V_35 , V_101 ) ;
V_133 = * V_132 ;
V_236 = F_11 ( V_237 , V_36 -> V_39 , V_86 ) ;
if ( V_236 > 0 )
V_132 = & ( ( * V_132 ) -> V_91 ) ;
else if ( V_236 < 0 )
V_132 = & ( ( * V_132 ) -> V_90 ) ;
else {
F_30 ( & V_22 -> V_107 ) ;
F_92 ( 1 ) ;
return;
}
}
F_70 ( & V_36 -> V_101 , V_133 , V_132 ) ;
F_71 ( & V_36 -> V_101 , & V_22 -> V_102 ) ;
V_22 -> V_103 += V_36 -> V_39 ;
F_30 ( & V_22 -> V_107 ) ;
F_45 ( V_36 , V_238 ) ;
}
static void F_120 ( struct V_69 * V_22 , struct V_92 * V_93 ,
const struct V_239 * V_240 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = & V_93 -> V_110 ;
T_4 V_241 ;
T_4 V_242 = V_22 -> V_188 - V_22 -> V_103 ;
int V_223 ;
struct V_126 * V_126 = & V_93 -> V_94 ;
if ( F_121 ( V_126 -> V_243 ) )
V_241 = 1 ;
else {
V_241 = F_114 ( T_4 , F_52 ( & V_36 -> V_244 ) , V_240 -> V_245 ) ;
V_241 = F_122 ( V_241 , V_246 , V_242 ) ;
}
if ( ( V_22 -> V_188 < V_22 -> V_103 ) || ( V_242 < V_241 ) )
return;
if ( F_26 ( V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_22 -> V_247 + V_22 -> V_46 ;
if ( F_92 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_223 = F_123 ( & V_2 , V_61 , & V_241 , V_93 , true ) ;
if ( V_223 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_241 ;
V_36 -> V_99 = V_93 -> V_96 ;
F_119 ( V_93 ) ;
} else {
if ( V_41 == V_22 -> V_247 + V_22 -> V_46 )
V_22 -> V_247 = 0 ;
}
}
static T_2 F_124 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_92 * V_93 )
{
struct V_35 * V_36 ;
struct V_84 * V_59 ;
int V_236 ;
F_28 ( & V_22 -> V_107 ) ;
V_59 = V_22 -> V_102 . V_84 ;
while ( V_59 ) {
V_36 = F_29 ( V_59 , struct V_35 , V_101 ) ;
V_236 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_236 < 0 )
V_59 = V_59 -> V_90 ;
else if ( V_236 > 0 )
V_59 = V_59 -> V_91 ;
else
break;
}
if ( V_59 ) {
while ( ( F_11 ( V_44 , V_76 , V_36 ) == 0 ) && ( & V_93 -> V_110 != V_36 ) ) {
V_44 = F_12 ( & V_36 -> V_38 ) + V_36 -> V_39 ;
V_59 = V_59 -> V_91 ;
if ( V_59 == NULL )
break;
V_36 = F_29 ( V_59 , struct V_35 , V_101 ) ;
}
}
F_30 ( & V_22 -> V_107 ) ;
return V_44 ;
}
static int F_125 ( struct V_1 * V_2 ,
const struct V_92 * V_93 ,
T_4 V_248 ,
struct V_249 * V_250 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_241 = 1 ;
T_2 V_251 ;
int V_223 ;
if ( V_248 ) {
V_241 = F_20 ( V_2 , V_248 ) ;
if ( V_241 <= V_250 -> V_34 )
goto V_141;
}
V_251 = F_124 ( V_2 -> V_22 , V_44 , V_241 , V_93 ) ;
if ( V_251 == V_44 ) {
if ( ! V_248 || V_241 >= V_248 )
return 0 ;
if ( V_241 > V_250 -> V_34 ) {
V_250 -> V_34 = V_241 ;
V_250 -> V_2 = * V_2 ;
}
V_141:
V_251 = V_44 + V_241 ;
}
V_223 = F_16 ( V_2 , V_251 ) ;
if ( V_223 < 0 )
return V_223 ;
return 1 ;
}
static int F_123 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_248 ,
const struct V_92 * V_93 , bool V_252 )
{
struct V_199 * V_200 ;
int V_253 ;
T_4 V_254 ;
int V_255 = V_2 -> V_51 ;
T_4 V_256 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_257 = V_2 -> V_22 -> V_57 ;
int V_223 ;
struct V_9 * V_10 ;
struct V_249 V_250 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_257 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_104 ( V_105 , & V_10 -> V_106 ) &&
( V_30 == V_61 ) )
goto V_258;
V_200 = V_10 -> V_17 ;
V_26 = V_200 -> V_18 + V_10 -> V_19 ;
F_92 ( ! F_93 ( V_200 ) ) ;
if ( V_30 != V_183 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_254 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_259;
V_2 -> V_14 = V_14 ;
if ( V_93 == NULL )
return 0 ;
V_253 = V_2 -> V_51 ;
V_223 = F_125 ( V_2 , V_93 ,
V_248 ? * V_248 : 0 ,
& V_250 ) ;
if ( V_223 == 0 )
return 0 ;
if ( V_223 > 0 ) {
V_59 += ( V_2 -> V_51 - V_253 ) ;
goto V_260;
}
if ( V_223 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_253 ) ;
goto V_261;
}
return V_223 ;
V_259:
if ( ( V_30 == V_61 ) && V_254 == 0 )
F_126 ( V_105 , & V_10 -> V_106 ) ;
V_258:
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 )
V_2 -> V_51 = 0 ;
V_261:
if ( ( V_2 -> V_51 == 0 ) && V_252 )
break;
V_59 ++ ;
V_260:
if ( V_59 >= V_257 )
break;
}
if ( V_248 == NULL || V_30 != V_61 )
return - V_262 ;
if ( ( V_256 == 0 ) && ( V_255 == 0 ) &&
( * V_248 < V_2 -> V_22 -> V_104 ) )
V_2 -> V_22 -> V_104 = * V_248 ;
if ( V_250 . V_34 ) {
* V_2 = V_250 . V_2 ;
* V_248 = V_250 . V_34 ;
return 0 ;
}
return - V_262 ;
}
static void F_127 ( struct V_69 * V_22 , T_2 * V_263 , T_2 V_264 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_111 * V_112 ;
struct V_92 * V_93 ;
int error ;
int V_265 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_51 ( & V_75 -> V_266 ) ;
error = F_123 ( & V_2 , V_183 , NULL , NULL ,
true ) ;
F_53 ( & V_75 -> V_266 ) ;
if ( error == - V_262 )
break;
if ( F_17 ( error ) )
break;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_263 != V_267 && V_44 <= * V_263 )
continue;
if ( V_44 == V_264 )
continue;
* V_263 = V_44 ;
error = F_76 ( V_75 , V_44 , & V_268 , V_143 , & V_112 ) ;
if ( error )
continue;
V_93 = V_112 -> V_116 ;
if ( V_93 || F_128 ( V_269 , & V_112 -> V_270 ) == 0 )
F_58 ( V_112 ) ;
else
V_265 ++ ;
if ( V_265 > V_271 )
return;
}
V_22 -> V_148 &= ~ V_187 ;
return;
}
static bool F_129 ( const struct V_69 * V_22 , int V_272 )
{
const struct V_111 * V_112 = V_22 -> V_113 ;
const struct V_74 * V_75 = V_112 -> V_273 . V_274 ;
struct V_275 * V_276 ;
T_2 V_277 , V_278 ;
T_2 V_279 , V_280 = 0 ;
T_9 V_281 ;
T_2 V_282 ;
T_2 V_283 ;
int V_284 , V_285 = 0 ;
F_130 () ;
F_131 (cpu) {
V_276 = & F_132 ( V_75 -> V_286 , V_284 ) -> V_287 [ V_288 ] ;
if ( V_276 -> V_289 [ V_290 ] ) {
V_280 += V_276 -> V_289 [ V_290 ] ;
V_285 ++ ;
}
}
V_276 = & F_133 ( V_75 -> V_286 ) -> V_287 [ V_288 ] ;
if ( V_285 )
F_134 ( V_280 , V_285 ) ;
V_277 = V_276 -> V_289 [ V_291 ] ;
V_283 = V_276 -> V_289 [ V_292 ] +
V_112 -> V_293 . V_289 [ V_292 ] ;
F_135 () ;
V_279 = V_112 -> V_293 . V_289 [ V_290 ] ;
V_278 = V_112 -> V_293 . V_289 [ V_291 ] ;
if ( ( V_278 < 1 ) || ( V_277 < 1 ) || ( V_280 == 0 ) )
return false ;
V_281 = V_280 - V_279 ;
V_282 = V_281 * V_281 ;
V_283 *= 2 ;
if ( V_278 < 8 || V_277 < 8 )
V_283 *= 2 ;
if ( V_272 == 1 )
V_283 *= 2 ;
return ( ( V_281 < 0 ) && ( V_282 > V_283 ) ) ;
}
static bool F_136 ( const struct V_35 * V_36 ,
T_2 V_294 )
{
T_2 V_295 ;
V_295 = F_137 ( F_138 ( F_139 () ,
V_36 -> V_38 . V_22 -> V_113 -> V_296 ) ) ;
return V_295 > ( V_294 * 1000 * 1000 ) ;
}
static T_4 F_140 ( const struct V_92 * V_93 )
{
const struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
T_4 V_264 ;
F_141 ( & V_264 , sizeof( V_264 ) ) ;
return V_264 % V_75 -> V_135 ;
}
static bool F_142 ( struct V_69 * * V_130 , const struct V_69 * V_297 )
{
struct V_69 * V_22 = * V_130 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_33 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_31 ( V_75 ) ;
* V_130 = V_22 ;
if ( V_22 != V_297 )
return true ;
return false ;
}
static inline int F_143 ( struct V_69 * V_22 )
{
struct V_111 * V_112 = V_22 -> V_113 ;
if ( V_112 -> V_298 != V_299 && F_144 ( & V_112 -> V_300 ) &&
! F_104 ( V_301 , & V_112 -> V_197 ) &&
! F_104 ( V_196 , & V_112 -> V_197 ) )
return 1 ;
if ( V_22 -> V_148 & V_150 )
return 1 ;
return 0 ;
}
int F_145 ( struct V_92 * V_93 , struct V_239 * V_240 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_297 = NULL ;
struct V_35 * V_36 = & V_93 -> V_110 ;
int error = 0 , V_302 , V_303 = 0 ;
T_2 V_263 = V_267 ;
int V_272 = 0 ;
T_4 V_264 = 0 ;
if ( V_75 -> V_189 . V_190 )
V_303 |= V_194 ;
if ( F_99 ( V_75 , V_240 -> V_245 ) )
return - V_48 ;
if ( F_44 ( V_36 ) ) {
V_297 = V_36 -> V_38 . V_22 ;
} else if ( V_93 -> V_304 && F_26 ( V_93 -> V_304 , V_93 -> V_95 ) ) {
V_36 -> V_38 . V_22 = V_297 = V_93 -> V_304 ;
} else {
F_35 ( V_93 ) ;
V_36 -> V_38 . V_22 = V_297 = F_27 ( V_75 , V_93 -> V_95 , 1 ) ;
}
if ( F_121 ( V_93 -> V_94 . V_243 ) && ( V_240 -> V_305 & V_306 ) )
V_264 = F_140 ( V_93 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_307 ;
while ( V_272 < 3 ) {
V_302 = 1 ;
if ( ! F_81 ( V_36 -> V_38 . V_22 -> V_113 ) ) {
V_302 = 0 ;
if ( V_264 && V_264 -- )
goto V_308;
if ( ! F_44 ( V_36 ) ) {
if ( V_272 == 0 &&
! F_143 ( V_36 -> V_38 . V_22 ) )
goto V_308;
if ( ( V_272 < 2 ) &&
F_136 ( V_36 , 1000 ) &&
F_129 ( V_36 -> V_38 . V_22 , V_272 ) )
goto V_308;
}
error = F_82 ( V_36 -> V_38 . V_22 -> V_113 ,
V_233 , V_303 ,
& V_36 -> V_309 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_44 ( V_36 ) && ( V_272 < 2 ) &&
F_129 ( V_36 -> V_38 . V_22 , V_272 ) )
goto V_310;
if ( V_75 -> V_189 . V_190 ) {
error = F_100 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_83 ( & V_36 -> V_309 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_148 & ( V_311 |
V_312 ) ) ||
( V_272 == 0 && V_240 -> V_245 > V_36 -> V_38 . V_22 -> V_104 ) )
goto V_310;
if ( V_75 -> V_189 . V_190 )
F_94 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_44 ( V_36 ) )
F_120 ( V_36 -> V_38 . V_22 , V_93 , V_240 ) ;
if ( ! F_44 ( V_36 ) && ( V_272 < 1 ) )
goto V_313;
if ( V_36 -> V_38 . V_22 -> V_188 >= V_240 -> V_245 ||
( V_272 == 2 && V_240 -> V_314 &&
V_36 -> V_38 . V_22 -> V_188 >= V_240 -> V_314 ) ) {
V_93 -> V_304 = V_36 -> V_38 . V_22 ;
V_240 -> V_315 = V_93 -> V_304 -> V_188 ;
return 0 ;
}
V_313:
if ( V_36 -> V_38 . V_22 -> V_148 & V_187 )
F_127 ( V_36 -> V_38 . V_22 , & V_263 ,
V_93 -> V_96 ) ;
V_310:
if ( F_44 ( V_36 ) )
F_49 ( V_36 ) ;
if ( ! V_302 )
F_83 ( & V_36 -> V_309 ) ;
V_308:
if ( F_142 ( & V_36 -> V_38 . V_22 , V_297 ) )
continue;
if ( V_264 )
continue;
V_272 ++ ;
if ( V_93 == F_65 ( V_75 -> V_127 ) && ! V_75 -> V_158 ) {
error = F_79 ( V_93 ) ;
if ( error )
return error ;
}
if ( V_272 == 2 )
F_146 ( V_75 , NULL , V_316 ) ;
}
return - V_262 ;
}
void F_147 ( struct V_92 * V_93 )
{
struct V_35 * V_36 = & V_93 -> V_110 ;
if ( F_148 ( & V_36 -> V_309 ) )
F_83 ( & V_36 -> V_309 ) ;
}
static unsigned char F_149 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_223 ;
V_223 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_223 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_150 ( const struct V_1 * V_2 , bool V_317 ,
unsigned int * V_59 )
{
struct V_1 V_130 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_318 = * V_59 ;
T_2 V_44 ;
int V_223 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_116 ( V_2 -> V_22 -> V_113 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_317 ? V_319 : V_320 ) ;
V_44 ++ ;
while ( * V_59 < V_318 ) {
V_223 = F_16 ( & V_130 , V_44 ) ;
if ( V_223 || F_8 ( & V_130 ) != V_61 )
break;
F_116 ( V_130 . V_22 -> V_113 , F_2 ( & V_130 ) -> V_17 ) ;
F_1 ( & V_130 , true , V_320 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_151 ( struct V_74 * V_75 , T_2 V_321 ,
T_4 V_322 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 , * V_323 = NULL ;
V_2 . V_22 = F_27 ( V_75 , V_321 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_152 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_321 ) ;
return NULL ;
}
F_16 ( & V_2 , V_321 ) ;
while ( V_322 -- ) {
V_10 = F_2 ( & V_2 ) ;
if ( V_10 != V_323 ) {
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_153 ( V_10 -> V_17 -> V_68 ,
V_120 | V_324 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 ,
V_10 -> V_12 ) ;
}
F_116 ( V_2 . V_22 -> V_113 , V_10 -> V_17 ) ;
V_323 = V_10 ;
}
F_1 ( & V_2 , false , V_4 ) ;
F_18 ( & V_2 ) ;
}
return V_2 . V_22 ;
}
void F_154 ( struct V_97 * V_98 , const struct V_111 * V_112 )
{
struct V_69 * V_22 = V_112 -> V_116 ;
struct V_35 * V_325 ;
const struct V_84 * V_59 ;
if ( V_22 == NULL )
return;
F_42 ( V_98 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_148 ,
V_22 -> V_79 , V_22 -> V_188 , V_22 -> V_80 ,
V_22 -> V_103 , V_22 -> V_104 ) ;
F_28 ( & V_22 -> V_107 ) ;
for ( V_59 = F_32 ( & V_22 -> V_102 ) ; V_59 ; V_59 = F_34 ( & V_325 -> V_101 ) ) {
V_325 = F_29 ( V_59 , struct V_35 , V_101 ) ;
F_41 ( V_98 , V_325 ) ;
}
F_30 ( & V_22 -> V_107 ) ;
}
static void F_155 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_107 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_107 ( V_75 , L_18 ) ;
F_154 ( NULL , V_22 -> V_113 ) ;
V_22 -> V_148 |= V_312 ;
}
static void F_156 ( struct V_92 * V_93 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = & V_93 -> V_110 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_326 ;
T_2 V_44 ;
int V_223 ;
F_28 ( & V_22 -> V_107 ) ;
if ( F_44 ( V_36 ) ) {
if ( F_157 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_223 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_326 = F_158 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_326 ;
V_22 -> V_103 -= V_326 ;
F_45 ( V_36 , V_327 ) ;
if ( V_36 -> V_39 && ! V_223 )
goto V_67;
F_159 ( V_328 , & V_36 -> V_244 ) ;
}
F_43 ( V_36 ) ;
}
V_67:
F_30 ( & V_22 -> V_107 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
const struct V_92 * V_93 , bool V_317 )
{
T_2 V_41 ;
if ( F_44 ( & V_93 -> V_110 ) ) {
* V_2 = V_93 -> V_110 . V_38 ;
return;
}
if ( ! V_317 && F_26 ( V_2 -> V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_2 -> V_22 -> V_247 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_161 ( struct V_92 * V_93 , T_2 * V_329 , unsigned int * V_330 ,
bool V_317 , T_2 * V_331 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_199 * V_332 ;
struct V_1 V_2 = { . V_22 = V_93 -> V_304 , } ;
unsigned int V_333 ;
T_2 V_44 ;
int error ;
F_160 ( & V_2 , V_93 , V_317 ) ;
error = F_123 ( & V_2 , V_61 , NULL , V_93 , false ) ;
if ( error == - V_262 ) {
F_160 ( & V_2 , V_93 , V_317 ) ;
error = F_123 ( & V_2 , V_61 , NULL , NULL , false ) ;
}
if ( error ) {
F_107 ( V_75 , L_19 ,
( unsigned long long ) V_93 -> V_96 , error , * V_330 ,
F_104 ( V_105 , & V_2 . V_22 -> V_78 -> V_106 ) ,
V_2 . V_22 -> V_104 ) ;
goto V_334;
}
F_150 ( & V_2 , V_317 , V_330 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_247 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_44 ( & V_93 -> V_110 ) )
F_156 ( V_93 , & V_2 , * V_330 ) ;
V_333 = * V_330 ;
if ( V_317 )
V_333 -- ;
if ( ! V_317 ) {
V_93 -> V_95 = V_44 + V_333 - 1 ;
error = F_162 ( V_93 , & V_332 ) ;
if ( error == 0 ) {
struct V_335 * V_336 =
(struct V_335 * ) V_332 -> V_18 ;
F_116 ( V_93 -> V_159 , V_332 ) ;
V_336 -> V_337 = V_336 -> V_338 =
F_87 ( V_93 -> V_95 ) ;
F_98 ( V_332 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_330 ) {
F_5 ( L_20 , * V_330 ) ;
goto V_334;
}
V_2 . V_22 -> V_79 -= * V_330 ;
if ( V_317 ) {
V_2 . V_22 -> V_80 ++ ;
* V_331 = V_2 . V_22 -> V_169 ++ ;
if ( * V_331 == 0 )
* V_331 = V_2 . V_22 -> V_169 ++ ;
}
F_116 ( V_2 . V_22 -> V_113 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_2 . V_22 -> V_144 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_163 ( V_75 , 0 , - ( T_9 ) * V_330 , V_317 ? 1 : 0 ) ;
if ( V_317 )
F_164 ( V_75 , V_44 , * V_330 ) ;
F_165 ( V_93 , * V_330 , V_93 -> V_94 . V_339 , V_93 -> V_94 . V_340 ) ;
V_2 . V_22 -> V_188 -= * V_330 ;
F_166 ( V_93 , V_2 . V_22 , V_44 , * V_330 ,
V_317 ? V_319 : V_320 ) ;
* V_329 = V_44 ;
return 0 ;
V_334:
F_155 ( V_2 . V_22 ) ;
return - V_124 ;
}
void F_167 ( struct V_92 * V_93 , T_2 V_321 , T_4 V_322 , int V_341 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
V_22 = F_151 ( V_75 , V_321 , V_322 , V_61 ) ;
if ( ! V_22 )
return;
F_166 ( V_93 , V_22 , V_321 , V_322 , V_61 ) ;
V_22 -> V_79 += V_322 ;
V_22 -> V_148 &= ~ V_234 ;
F_116 ( V_22 -> V_113 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 -> V_144 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_341 || V_93 -> V_342 )
F_168 ( V_93 , V_321 , V_322 ) ;
}
void F_169 ( struct V_92 * V_93 , T_2 V_321 , T_4 V_322 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
F_167 ( V_93 , V_321 , V_322 , 1 ) ;
F_163 ( V_75 , 0 , + V_322 , 0 ) ;
F_165 ( V_93 , - ( T_9 ) V_322 , V_93 -> V_94 . V_339 , V_93 -> V_94 . V_340 ) ;
}
void F_170 ( struct V_126 * V_126 )
{
struct V_92 * V_93 = F_65 ( V_126 ) ;
struct V_74 * V_75 = F_36 ( V_126 ) ;
struct V_69 * V_22 ;
T_2 V_343 = V_93 -> V_96 ;
V_22 = F_151 ( V_75 , V_343 , 1 , V_183 ) ;
if ( ! V_22 )
return;
F_166 ( V_93 , V_22 , V_343 , 1 , V_183 ) ;
F_116 ( V_22 -> V_113 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 -> V_144 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_90 ( V_22 , 1 ) ;
}
static void F_171 ( struct V_69 * V_22 , T_2 V_343 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_344 ;
V_344 = F_151 ( V_75 , V_343 , 1 , V_61 ) ;
if ( ! V_344 )
return;
F_172 ( V_75 , V_22 == V_344 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_116 ( V_22 -> V_113 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 -> V_144 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_90 ( V_22 , - 1 ) ;
F_163 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_173 ( struct V_69 * V_22 , struct V_92 * V_93 )
{
F_171 ( V_22 , V_93 -> V_96 ) ;
F_166 ( V_93 , V_22 , V_93 -> V_96 , 1 , V_61 ) ;
F_165 ( V_93 , - 1 , V_93 -> V_94 . V_339 , V_93 -> V_94 . V_340 ) ;
F_168 ( V_93 , V_93 -> V_96 , 1 ) ;
}
int F_174 ( struct V_74 * V_75 , T_2 V_345 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_160 V_346 ;
int error = - V_48 ;
V_22 = F_27 ( V_75 , V_345 , 1 ) ;
if ( ! V_22 )
goto V_141;
error = F_82 ( V_22 -> V_113 , V_163 , 0 , & V_346 ) ;
if ( error )
goto V_141;
if ( F_149 ( V_22 , V_345 ) != type )
error = - V_347 ;
F_83 ( & V_346 ) ;
V_141:
return error ;
}
void F_175 ( struct V_92 * V_93 , struct V_348 * V_349 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_350 ;
unsigned int V_77 ;
if ( F_99 ( V_75 , ! V_349 -> V_351 ) )
return;
if ( V_93 -> V_304 && F_26 ( V_93 -> V_304 , V_44 ) )
V_22 = V_93 -> V_304 ;
else
V_22 = F_27 ( V_75 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_25 ( V_75 , L_21 , ( unsigned long long ) V_44 ) ;
return;
}
V_93 -> V_304 = V_22 ;
for ( V_77 = 0 ; V_77 < V_349 -> V_352 ; V_77 ++ )
if ( V_349 -> V_353 [ V_77 ] == V_22 )
return;
if ( V_349 -> V_352 == V_349 -> V_354 ) {
V_350 = V_349 -> V_354 + 10 ;
V_31 = F_63 ( V_350 , sizeof( struct V_69 * ) ,
V_120 | V_324 ) ;
if ( V_349 -> V_353 ) {
memcpy ( V_31 , V_349 -> V_353 ,
V_349 -> V_354 * sizeof( struct V_69 * ) ) ;
F_38 ( V_349 -> V_353 ) ;
}
V_349 -> V_354 = V_350 ;
V_349 -> V_353 = V_31 ;
}
V_349 -> V_353 [ V_349 -> V_352 ++ ] = V_22 ;
}
void F_176 ( struct V_348 * V_349 , unsigned int V_30 )
{
unsigned int V_77 ;
V_349 -> V_351 = F_153 ( V_349 -> V_352 * sizeof( struct V_160 ) ,
V_120 | V_324 ) ;
for ( V_77 = 0 ; V_77 < V_349 -> V_352 ; V_77 ++ )
F_177 ( V_349 -> V_353 [ V_77 ] -> V_113 ,
V_30 , 0 ,
& V_349 -> V_351 [ V_77 ] ) ;
}
void F_178 ( struct V_348 * V_349 )
{
unsigned int V_77 ;
F_38 ( V_349 -> V_353 ) ;
if ( V_349 -> V_351 ) {
for ( V_77 = 0 ; V_77 < V_349 -> V_352 ; V_77 ++ )
F_179 ( & V_349 -> V_351 [ V_77 ] ) ;
F_38 ( V_349 -> V_351 ) ;
V_349 -> V_351 = NULL ;
}
}
