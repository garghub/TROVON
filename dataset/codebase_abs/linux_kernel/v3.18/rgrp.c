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
int error = 0 ;
F_40 ( & V_93 -> V_97 ) ;
if ( V_93 -> V_98 )
goto V_67;
V_93 -> V_98 = F_41 ( V_99 , V_100 ) ;
if ( ! V_93 -> V_98 ) {
error = - V_101 ;
goto V_67;
}
F_42 ( & V_93 -> V_98 -> V_102 ) ;
V_67:
F_43 ( & V_93 -> V_97 ) ;
return error ;
}
static void F_44 ( struct V_103 * V_104 , const struct V_35 * V_36 )
{
F_45 ( V_104 , L_7 ,
( unsigned long long ) V_36 -> V_105 ,
( unsigned long long ) F_12 ( & V_36 -> V_38 ) ,
V_36 -> V_38 . V_14 , V_36 -> V_39 ) ;
}
static void F_46 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
if ( ! F_47 ( V_36 ) )
return;
V_22 = V_36 -> V_38 . V_22 ;
F_48 ( V_36 , V_106 ) ;
F_49 ( & V_36 -> V_102 , & V_22 -> V_107 ) ;
F_42 ( & V_36 -> V_102 ) ;
if ( V_36 -> V_39 ) {
struct V_9 * V_10 = F_2 ( & V_36 -> V_38 ) ;
F_3 ( V_36 -> V_38 . V_22 -> V_108 < V_36 -> V_39 ) ;
V_36 -> V_38 . V_22 -> V_108 -= V_36 -> V_39 ;
V_22 -> V_109 += V_36 -> V_39 ;
V_36 -> V_39 = 0 ;
F_50 ( V_110 , & V_10 -> V_111 ) ;
}
}
void F_51 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_28 ( & V_22 -> V_112 ) ;
F_46 ( V_36 ) ;
F_30 ( & V_22 -> V_112 ) ;
}
}
void F_52 ( struct V_92 * V_93 , T_5 * V_113 )
{
F_40 ( & V_93 -> V_97 ) ;
if ( V_93 -> V_98 && ( ( V_113 == NULL ) || ( F_53 ( V_113 ) <= 1 ) ) ) {
F_51 ( V_93 -> V_98 ) ;
F_3 ( V_93 -> V_98 -> V_39 ) ;
F_54 ( V_99 , V_93 -> V_98 ) ;
V_93 -> V_98 = NULL ;
}
F_43 ( & V_93 -> V_97 ) ;
}
static void F_55 ( struct V_69 * V_22 )
{
struct V_84 * V_59 ;
struct V_35 * V_36 ;
F_28 ( & V_22 -> V_112 ) ;
while ( ( V_59 = F_32 ( & V_22 -> V_107 ) ) ) {
V_36 = F_29 ( V_59 , struct V_35 , V_102 ) ;
F_46 ( V_36 ) ;
}
F_30 ( & V_22 -> V_112 ) ;
}
void F_56 ( struct V_74 * V_75 )
{
struct V_84 * V_59 ;
struct V_69 * V_22 ;
struct V_114 * V_115 ;
while ( ( V_59 = F_32 ( & V_75 -> V_88 ) ) ) {
V_22 = F_29 ( V_59 , struct V_69 , V_89 ) ;
V_115 = V_22 -> V_116 ;
F_49 ( V_59 , & V_75 -> V_88 ) ;
if ( V_115 ) {
F_28 ( & V_115 -> V_117 ) ;
V_115 -> V_118 = NULL ;
F_30 ( & V_115 -> V_117 ) ;
F_57 ( V_115 ) ;
F_58 ( V_115 ) ;
}
F_37 ( V_22 ) ;
F_38 ( V_22 -> V_78 ) ;
F_55 ( V_22 ) ;
F_54 ( V_119 , V_22 ) ;
}
}
static void F_59 ( const struct V_69 * V_22 )
{
F_60 ( L_8 , ( unsigned long long ) V_22 -> V_23 ) ;
F_60 ( L_9 , V_22 -> V_57 ) ;
F_60 ( L_10 , ( unsigned long long ) V_22 -> V_46 ) ;
F_60 ( L_11 , V_22 -> V_49 ) ;
F_60 ( L_12 , V_22 -> V_120 ) ;
}
static int F_61 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_121 , V_64 ;
int V_77 ;
if ( ! V_76 )
return - V_48 ;
V_22 -> V_78 = F_62 ( V_76 , sizeof( struct V_9 ) , V_100 ) ;
if ( ! V_22 -> V_78 )
return - V_101 ;
V_121 = V_22 -> V_120 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
V_10 -> V_111 = 0 ;
if ( V_76 == 1 ) {
V_64 = V_121 ;
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
V_64 = V_121 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_120 - V_121 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else {
V_64 = V_75 -> V_122 . V_123 -
sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_120 - V_121 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
}
V_121 -= V_64 ;
}
if ( V_121 ) {
F_7 ( V_22 ) ;
return - V_124 ;
}
V_10 = V_22 -> V_78 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_12 ) * V_15 != V_22 -> V_49 ) {
if ( F_7 ( V_22 ) ) {
F_59 ( V_22 ) ;
F_25 ( V_75 , L_13 ,
V_10 -> V_24 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_124 ;
}
return 0 ;
}
T_2 F_63 ( struct V_74 * V_75 )
{
T_2 V_125 = 0 ;
struct V_126 * V_126 = V_75 -> V_127 ;
struct V_92 * V_93 = F_64 ( V_126 ) ;
char V_40 [ sizeof( struct V_128 ) ] ;
int error , V_129 ;
for ( V_129 = 0 ; ; V_129 ++ ) {
T_6 V_130 = V_129 * sizeof( struct V_128 ) ;
if ( V_130 + sizeof( struct V_128 ) > F_65 ( V_126 ) )
break;
error = F_66 ( V_93 , V_40 , & V_130 ,
sizeof( struct V_128 ) ) ;
if ( error != sizeof( struct V_128 ) )
break;
V_125 += F_67 ( ( (struct V_128 * ) V_40 ) -> V_131 ) ;
}
return V_125 ;
}
static int F_68 ( struct V_69 * V_22 )
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
F_69 ( & V_22 -> V_89 , V_133 , V_132 ) ;
F_70 ( & V_22 -> V_89 , & V_75 -> V_88 ) ;
V_75 -> V_135 ++ ;
return 0 ;
}
static int F_71 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
const unsigned V_136 = V_75 -> V_122 . V_123 ;
T_6 V_130 = V_75 -> V_135 * sizeof( struct V_128 ) ;
struct V_128 V_40 ;
int error ;
struct V_69 * V_22 ;
if ( V_130 >= F_65 ( & V_93 -> V_94 ) )
return 1 ;
error = F_66 ( V_93 , ( char * ) & V_40 , & V_130 ,
sizeof( struct V_128 ) ) ;
if ( error != sizeof( struct V_128 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_41 ( V_119 , V_100 ) ;
error = - V_101 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_75 ;
V_22 -> V_23 = F_72 ( V_40 . V_137 ) ;
V_22 -> V_57 = F_67 ( V_40 . V_138 ) ;
V_22 -> V_46 = F_72 ( V_40 . V_139 ) ;
V_22 -> V_49 = F_67 ( V_40 . V_131 ) ;
V_22 -> V_120 = F_67 ( V_40 . V_140 ) ;
F_73 ( & V_22 -> V_112 ) ;
error = F_61 ( V_22 ) ;
if ( error )
goto V_141;
error = F_74 ( V_75 , V_22 -> V_23 ,
& V_142 , V_143 , & V_22 -> V_116 ) ;
if ( error )
goto V_141;
V_22 -> V_116 -> V_118 = V_22 ;
V_22 -> V_116 -> V_144 . V_66 = V_22 -> V_23 * V_136 ;
V_22 -> V_116 -> V_144 . V_7 = V_22 -> V_116 -> V_144 . V_66 + ( V_22 -> V_57 * V_136 ) - 1 ;
V_22 -> V_145 = (struct V_146 * ) V_22 -> V_116 -> V_147 . V_148 ;
V_22 -> V_149 &= ~ V_150 ;
if ( V_22 -> V_49 > V_75 -> V_151 )
V_75 -> V_151 = V_22 -> V_49 ;
F_28 ( & V_75 -> V_87 ) ;
error = F_68 ( V_22 ) ;
F_30 ( & V_75 -> V_87 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_58 ( V_22 -> V_116 ) ;
V_141:
F_38 ( V_22 -> V_78 ) ;
F_54 ( V_119 , V_22 ) ;
return error ;
}
static int F_75 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
int error ;
do {
error = F_71 ( V_93 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_75 -> V_152 = 1 ;
return 0 ;
}
int F_76 ( struct V_74 * V_75 )
{
struct V_92 * V_93 = F_64 ( V_75 -> V_127 ) ;
struct V_114 * V_115 = V_93 -> V_153 ;
struct V_154 V_155 ;
int error = 0 ;
int V_156 = 0 ;
if ( ! V_75 -> V_152 ) {
if ( ! F_77 ( V_115 ) ) {
error = F_78 ( V_115 , V_157 , 0 , & V_155 ) ;
if ( error )
return error ;
V_156 = 1 ;
}
if ( ! V_75 -> V_152 )
error = F_75 ( V_93 ) ;
if ( V_156 )
F_79 ( & V_155 ) ;
}
return error ;
}
static void F_80 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_158 = V_40 ;
T_4 V_159 ;
V_159 = F_67 ( V_158 -> V_159 ) ;
V_159 &= ~ V_160 ;
V_22 -> V_149 &= V_160 ;
V_22 -> V_149 |= V_159 ;
V_22 -> V_79 = F_67 ( V_158 -> V_161 ) ;
V_22 -> V_80 = F_67 ( V_158 -> V_162 ) ;
V_22 -> V_163 = F_72 ( V_158 -> V_164 ) ;
}
static void F_81 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_158 = V_40 ;
V_158 -> V_159 = F_82 ( V_22 -> V_149 & ~ V_160 ) ;
V_158 -> V_161 = F_82 ( V_22 -> V_79 ) ;
V_158 -> V_162 = F_82 ( V_22 -> V_80 ) ;
V_158 -> V_165 = F_82 ( 0 ) ;
V_158 -> V_164 = F_83 ( V_22 -> V_163 ) ;
memset ( & V_158 -> V_166 , 0 , sizeof( V_158 -> V_166 ) ) ;
}
static int F_84 ( struct V_69 * V_22 )
{
struct V_146 * V_167 = V_22 -> V_145 ;
struct V_53 * V_158 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_167 -> V_168 != V_158 -> V_159 || V_167 -> V_169 != V_158 -> V_161 ||
V_167 -> V_170 != V_158 -> V_162 ||
V_167 -> V_171 != V_158 -> V_164 )
return 0 ;
return 1 ;
}
static void F_85 ( struct V_146 * V_167 , const void * V_40 )
{
const struct V_53 * V_158 = V_40 ;
V_167 -> V_172 = F_82 ( V_173 ) ;
V_167 -> V_168 = V_158 -> V_159 ;
V_167 -> V_169 = V_158 -> V_161 ;
V_167 -> V_170 = V_158 -> V_162 ;
V_167 -> V_171 = V_158 -> V_164 ;
V_167 -> V_165 = 0UL ;
}
static void F_86 ( struct V_69 * V_22 , T_4 V_174 )
{
struct V_146 * V_167 = V_22 -> V_145 ;
T_4 V_175 = F_67 ( V_167 -> V_176 ) + V_174 ;
V_167 -> V_176 = F_82 ( V_175 ) ;
}
static T_4 F_87 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_177 , V_41 , V_73 = 0 ;
for ( V_177 = 0 , V_10 = V_22 -> V_78 ; V_177 < V_76 ; V_177 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_88 ( ! F_89 ( V_10 -> V_17 ) ) ;
while ( V_41 < V_10 -> V_12 * V_15 ) {
V_41 = F_13 ( V_26 , V_10 -> V_12 , V_41 ,
V_178 ) ;
if ( V_41 == V_43 )
break;
V_73 ++ ;
V_41 ++ ;
}
}
return V_73 ;
}
static int F_90 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_114 * V_115 = V_22 -> V_116 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_179 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_91 ( V_115 , V_22 -> V_23 + V_77 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_141;
}
for ( V_179 = V_76 ; V_179 -- ; ) {
V_10 = V_22 -> V_78 + V_179 ;
error = F_92 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_141;
if ( F_93 ( V_75 , V_10 -> V_17 , V_179 ? V_180 :
V_181 ) ) {
error = - V_124 ;
goto V_141;
}
}
if ( ! ( V_22 -> V_149 & V_150 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_50 ( V_110 , & V_22 -> V_78 [ V_77 ] . V_111 ) ;
F_80 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_149 |= ( V_150 | V_182 ) ;
V_22 -> V_183 = V_22 -> V_79 ;
V_22 -> V_109 = V_22 -> V_79 ;
}
if ( F_82 ( V_173 ) != V_22 -> V_145 -> V_172 ) {
V_22 -> V_145 -> V_176 = F_82 ( F_87 ( V_22 ) ) ;
F_85 ( V_22 -> V_145 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_184 . V_185 ) {
if ( ! F_84 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_124 ;
goto V_141;
}
if ( V_22 -> V_145 -> V_176 == 0 )
V_22 -> V_149 &= ~ V_182 ;
}
return 0 ;
V_141:
while ( V_77 -- ) {
V_10 = V_22 -> V_78 + V_77 ;
F_94 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_95 ( V_75 , ! V_10 -> V_25 ) ;
}
return error ;
}
static int F_96 ( struct V_69 * V_22 )
{
T_4 V_168 ;
if ( V_22 -> V_149 & V_150 )
return 0 ;
if ( F_82 ( V_173 ) != V_22 -> V_145 -> V_172 )
return F_90 ( V_22 ) ;
V_168 = F_67 ( V_22 -> V_145 -> V_168 ) ;
V_168 &= ~ V_160 ;
V_22 -> V_149 &= V_160 ;
V_22 -> V_149 |= ( V_168 | V_150 | V_182 ) ;
if ( V_22 -> V_145 -> V_176 == 0 )
V_22 -> V_149 &= ~ V_182 ;
V_22 -> V_79 = F_67 ( V_22 -> V_145 -> V_169 ) ;
V_22 -> V_183 = V_22 -> V_79 ;
V_22 -> V_80 = F_67 ( V_22 -> V_145 -> V_170 ) ;
V_22 -> V_163 = F_72 ( V_22 -> V_145 -> V_171 ) ;
return 0 ;
}
int F_97 ( struct V_154 * V_186 )
{
struct V_69 * V_22 = V_186 -> V_187 -> V_118 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_186 -> V_188 & V_189 && V_75 -> V_184 . V_185 )
return 0 ;
return F_90 ( V_22 ) ;
}
void F_98 ( struct V_154 * V_186 )
{
struct V_69 * V_22 = V_186 -> V_187 -> V_118 ;
int V_77 , V_76 = V_22 -> V_57 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
if ( V_10 -> V_17 ) {
F_94 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
int F_99 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_190 * V_191 ,
const struct V_9 * V_10 , unsigned V_192 , T_2 * V_193 )
{
struct V_194 * V_195 = V_75 -> V_196 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_197 = 0 ;
int V_198 ;
unsigned int V_77 ;
T_4 V_199 = 0 ;
T_1 V_200 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_201 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_201 += V_10 -> V_19 ;
V_201 += V_77 ;
if ( V_191 ) {
const T_1 * V_202 = V_191 -> V_18 + V_10 -> V_19 + V_77 ;
V_200 = ~ ( * V_202 | ( * V_202 >> 1 ) ) & ( * V_201 | ( * V_201 >> 1 ) ) ;
} else {
V_200 = ~ ( * V_201 | ( * V_201 >> 1 ) ) ;
}
V_200 &= 0x55 ;
if ( V_200 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_200 ) {
if ( V_200 & 1 ) {
if ( V_197 == 0 )
goto V_203;
if ( ( V_66 + V_197 ) != V_33 ) {
if ( V_197 >= V_192 ) {
V_198 = F_100 ( V_195 ,
V_66 , V_197 ,
V_100 , 0 ) ;
if ( V_198 )
goto V_141;
V_199 += V_197 ;
}
V_197 = 0 ;
V_203:
V_66 = V_33 ;
}
V_197 ++ ;
}
V_200 >>= 2 ;
V_33 ++ ;
}
}
if ( V_197 >= V_192 ) {
V_198 = F_100 ( V_195 , V_66 , V_197 , V_100 , 0 ) ;
if ( V_198 )
goto V_141;
V_199 += V_197 ;
}
if ( V_193 )
* V_193 = V_199 ;
return 0 ;
V_141:
if ( V_75 -> V_184 . V_204 )
F_101 ( V_75 , L_14 , V_198 ) ;
V_75 -> V_184 . V_204 = 0 ;
return - V_124 ;
}
int F_102 ( struct V_205 * V_206 , void T_8 * V_207 )
{
struct V_126 * V_126 = F_103 ( V_206 ) ;
struct V_74 * V_75 = F_36 ( V_126 ) ;
struct V_208 * V_209 = F_104 ( V_75 -> V_196 -> V_210 ) ;
struct V_190 * V_191 ;
struct V_69 * V_22 ;
struct V_69 * V_211 ;
struct V_154 V_186 ;
struct V_212 V_213 ;
int V_214 = 0 ;
T_2 V_215 ;
T_2 V_199 = 0 ;
T_2 V_66 , V_7 , V_192 ;
unsigned int V_77 ;
unsigned V_216 = V_75 -> V_122 . V_217 ;
if ( ! F_105 ( V_218 ) )
return - V_219 ;
if ( ! F_106 ( V_209 ) )
return - V_220 ;
if ( F_107 ( & V_213 , V_207 , sizeof( V_213 ) ) )
return - V_221 ;
V_214 = F_76 ( V_75 ) ;
if ( V_214 )
return V_214 ;
V_66 = V_213 . V_66 >> V_216 ;
V_7 = V_66 + ( V_213 . V_34 >> V_216 ) ;
V_192 = F_108 ( T_2 , V_213 . V_192 ,
V_209 -> V_222 . V_223 ) >> V_216 ;
if ( V_7 <= V_66 || V_192 > V_75 -> V_151 )
return - V_48 ;
V_22 = F_27 ( V_75 , V_66 , 0 ) ;
V_211 = F_27 ( V_75 , V_7 , 0 ) ;
if ( ( F_31 ( V_75 ) == F_33 ( V_211 ) )
&& ( V_66 > V_211 -> V_46 + V_211 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_214 = F_78 ( V_22 -> V_116 , V_224 , 0 , & V_186 ) ;
if ( V_214 )
goto V_67;
if ( ! ( V_22 -> V_149 & V_225 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_214 = F_99 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_192 ,
& V_215 ) ;
if ( V_214 ) {
F_79 ( & V_186 ) ;
goto V_67;
}
V_199 += V_215 ;
}
V_214 = F_109 ( V_75 , V_226 , 0 ) ;
if ( V_214 == 0 ) {
V_191 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_149 |= V_225 ;
F_110 ( V_22 -> V_116 , V_191 ) ;
F_81 ( V_22 , V_191 -> V_18 ) ;
F_85 ( V_22 -> V_145 , V_191 -> V_18 ) ;
F_111 ( V_75 ) ;
}
}
F_79 ( & V_186 ) ;
if ( V_22 == V_211 )
break;
V_22 = F_33 ( V_22 ) ;
}
V_67:
V_213 . V_34 = V_199 << V_216 ;
if ( F_112 ( V_207 , & V_213 , sizeof( V_213 ) ) )
return - V_221 ;
return V_214 ;
}
static void F_113 ( struct V_92 * V_93 )
{
struct V_84 * * V_132 , * V_133 = NULL ;
int V_227 ;
struct V_35 * V_36 = V_93 -> V_98 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_228 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_47 ( V_36 ) ) ;
F_28 ( & V_22 -> V_112 ) ;
V_132 = & V_22 -> V_107 . V_84 ;
while ( * V_132 ) {
struct V_35 * V_86 =
F_29 ( * V_132 , struct V_35 , V_102 ) ;
V_133 = * V_132 ;
V_227 = F_11 ( V_228 , V_36 -> V_39 , V_86 ) ;
if ( V_227 > 0 )
V_132 = & ( ( * V_132 ) -> V_91 ) ;
else if ( V_227 < 0 )
V_132 = & ( ( * V_132 ) -> V_90 ) ;
else {
F_30 ( & V_22 -> V_112 ) ;
F_88 ( 1 ) ;
return;
}
}
F_69 ( & V_36 -> V_102 , V_133 , V_132 ) ;
F_70 ( & V_36 -> V_102 , & V_22 -> V_107 ) ;
V_22 -> V_108 += V_36 -> V_39 ;
F_30 ( & V_22 -> V_112 ) ;
F_48 ( V_36 , V_229 ) ;
}
static void F_114 ( struct V_69 * V_22 , struct V_92 * V_93 ,
const struct V_230 * V_231 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_93 -> V_98 ;
T_4 V_232 ;
T_4 V_233 = V_22 -> V_183 - V_22 -> V_108 ;
int V_214 ;
struct V_126 * V_126 = & V_93 -> V_94 ;
if ( F_115 ( V_126 -> V_234 ) )
V_232 = 1 ;
else {
V_232 = F_108 ( T_4 , F_53 ( & V_36 -> V_235 ) , V_231 -> V_236 ) ;
V_232 = F_116 ( V_232 , V_237 , V_233 ) ;
}
if ( ( V_22 -> V_183 < V_22 -> V_108 ) || ( V_233 < V_232 ) )
return;
if ( F_26 ( V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_22 -> V_238 + V_22 -> V_46 ;
if ( F_88 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_214 = F_117 ( & V_2 , V_61 , & V_232 , V_93 , true , V_231 ) ;
if ( V_214 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_232 ;
V_36 -> V_105 = V_93 -> V_96 ;
F_113 ( V_93 ) ;
} else {
if ( V_41 == V_22 -> V_238 + V_22 -> V_46 )
V_22 -> V_238 = 0 ;
}
}
static T_2 F_118 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_92 * V_93 )
{
struct V_35 * V_36 ;
struct V_84 * V_59 ;
int V_227 ;
F_28 ( & V_22 -> V_112 ) ;
V_59 = V_22 -> V_107 . V_84 ;
while ( V_59 ) {
V_36 = F_29 ( V_59 , struct V_35 , V_102 ) ;
V_227 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_227 < 0 )
V_59 = V_59 -> V_90 ;
else if ( V_227 > 0 )
V_59 = V_59 -> V_91 ;
else
break;
}
if ( V_59 ) {
while ( ( F_11 ( V_44 , V_76 , V_36 ) == 0 ) && ( V_93 -> V_98 != V_36 ) ) {
V_44 = F_12 ( & V_36 -> V_38 ) + V_36 -> V_39 ;
V_59 = V_59 -> V_91 ;
if ( V_59 == NULL )
break;
V_36 = F_29 ( V_59 , struct V_35 , V_102 ) ;
}
}
F_30 ( & V_22 -> V_112 ) ;
return V_44 ;
}
static int F_119 ( struct V_1 * V_2 ,
const struct V_92 * V_93 ,
T_4 V_239 ,
struct V_240 * V_241 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_232 = 1 ;
T_2 V_242 ;
int V_214 ;
if ( V_239 ) {
V_232 = F_20 ( V_2 , V_239 ) ;
if ( V_232 <= V_241 -> V_34 )
goto V_141;
}
V_242 = F_118 ( V_2 -> V_22 , V_44 , V_232 , V_93 ) ;
if ( V_242 == V_44 ) {
if ( ! V_239 || V_232 >= V_239 )
return 0 ;
if ( V_232 > V_241 -> V_34 ) {
V_241 -> V_34 = V_232 ;
V_241 -> V_2 = * V_2 ;
}
V_141:
V_242 = V_44 + V_232 ;
}
V_214 = F_16 ( V_2 , V_242 ) ;
if ( V_214 < 0 )
return V_214 ;
return 1 ;
}
static int F_117 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_239 ,
const struct V_92 * V_93 , bool V_243 ,
const struct V_230 * V_231 )
{
struct V_190 * V_191 ;
int V_244 ;
T_4 V_245 ;
int V_246 = V_2 -> V_51 ;
T_4 V_247 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_248 = V_2 -> V_22 -> V_57 ;
int V_214 ;
struct V_9 * V_10 ;
struct V_240 V_241 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_248 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_120 ( V_110 , & V_10 -> V_111 ) &&
( V_30 == V_61 ) )
goto V_249;
V_191 = V_10 -> V_17 ;
V_26 = V_191 -> V_18 + V_10 -> V_19 ;
F_88 ( ! F_89 ( V_191 ) ) ;
if ( V_30 != V_178 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_245 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_250;
V_2 -> V_14 = V_14 ;
if ( V_93 == NULL )
return 0 ;
V_244 = V_2 -> V_51 ;
V_214 = F_119 ( V_2 , V_93 ,
V_239 ? * V_239 : 0 ,
& V_241 ) ;
if ( V_214 == 0 )
return 0 ;
if ( V_214 > 0 ) {
V_59 += ( V_2 -> V_51 - V_244 ) ;
goto V_251;
}
if ( V_214 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_244 ) ;
goto V_252;
}
return V_214 ;
V_250:
if ( ( V_30 == V_61 ) && V_245 == 0 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_121 ( V_110 , & V_10 -> V_111 ) ;
}
V_249:
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 )
V_2 -> V_51 = 0 ;
V_252:
if ( ( V_2 -> V_51 == 0 ) && V_243 )
break;
V_59 ++ ;
V_251:
if ( V_59 >= V_248 )
break;
}
if ( V_239 == NULL || V_30 != V_61 )
return - V_253 ;
if ( ( V_247 == 0 ) && ( V_246 == 0 ) &&
( * V_239 < V_2 -> V_22 -> V_109 ) )
V_2 -> V_22 -> V_109 = * V_239 ;
if ( V_241 . V_34 ) {
* V_2 = V_241 . V_2 ;
* V_239 = V_241 . V_34 ;
return 0 ;
}
return - V_253 ;
}
static void F_122 ( struct V_69 * V_22 , T_2 * V_254 , T_2 V_255 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_114 * V_115 ;
struct V_92 * V_93 ;
int error ;
int V_256 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_40 ( & V_75 -> V_257 ) ;
error = F_117 ( & V_2 , V_178 , NULL , NULL ,
true , NULL ) ;
F_43 ( & V_75 -> V_257 ) ;
if ( error == - V_253 )
break;
if ( F_17 ( error ) )
break;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_254 != V_258 && V_44 <= * V_254 )
continue;
if ( V_44 == V_255 )
continue;
* V_254 = V_44 ;
error = F_74 ( V_75 , V_44 , & V_259 , V_143 , & V_115 ) ;
if ( error )
continue;
V_93 = V_115 -> V_118 ;
if ( V_93 || F_123 ( V_260 , & V_115 -> V_261 ) == 0 )
F_58 ( V_115 ) ;
else
V_256 ++ ;
if ( V_256 > V_262 )
return;
}
V_22 -> V_149 &= ~ V_182 ;
return;
}
static bool F_124 ( const struct V_69 * V_22 , int V_263 )
{
const struct V_114 * V_115 = V_22 -> V_116 ;
const struct V_74 * V_75 = V_115 -> V_264 ;
struct V_265 * V_266 ;
T_9 V_267 , V_268 ;
T_9 V_269 , V_270 ;
T_9 V_271 ;
T_9 V_272 ;
T_9 V_273 ;
F_125 () ;
V_266 = & F_126 ( V_75 -> V_274 ) -> V_275 [ V_276 ] ;
V_269 = V_266 -> V_277 [ V_278 ] ;
V_267 = V_266 -> V_277 [ V_279 ] ;
V_273 = V_266 -> V_277 [ V_280 ] +
V_115 -> V_281 . V_277 [ V_280 ] ;
F_127 () ;
V_270 = V_115 -> V_281 . V_277 [ V_278 ] ;
V_268 = V_115 -> V_281 . V_277 [ V_279 ] ;
if ( ( V_268 < 1 ) || ( V_267 < 1 ) || ( V_269 == 0 ) )
return false ;
V_271 = V_269 - V_270 ;
V_272 = V_271 * V_271 ;
V_273 *= 2 ;
if ( V_268 < 8 || V_267 < 8 )
V_273 *= 2 ;
if ( V_263 == 1 )
V_273 *= 2 ;
return ( ( V_271 < 0 ) && ( V_272 > V_273 ) ) ;
}
static bool F_128 ( const struct V_35 * V_36 ,
T_2 V_282 )
{
T_2 V_283 ;
V_283 = F_129 ( F_130 ( F_131 () ,
V_36 -> V_38 . V_22 -> V_116 -> V_284 ) ) ;
return V_283 > ( V_282 * 1000 * 1000 ) ;
}
static T_4 F_132 ( const struct V_92 * V_93 )
{
const struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
T_4 V_255 ;
F_133 ( & V_255 , sizeof( V_255 ) ) ;
return V_255 % V_75 -> V_135 ;
}
static bool F_134 ( struct V_69 * * V_130 , const struct V_69 * V_285 )
{
struct V_69 * V_22 = * V_130 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_33 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_31 ( V_75 ) ;
* V_130 = V_22 ;
if ( V_22 != V_285 )
return true ;
return false ;
}
int F_135 ( struct V_92 * V_93 , const struct V_230 * V_231 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_285 = NULL ;
struct V_35 * V_36 = V_93 -> V_98 ;
int error = 0 , V_286 , V_287 = 0 ;
T_2 V_254 = V_258 ;
int V_263 = 0 ;
T_4 V_255 = 0 ;
if ( V_75 -> V_184 . V_185 )
V_287 |= V_189 ;
if ( F_95 ( V_75 , V_231 -> V_236 ) )
return - V_48 ;
if ( F_47 ( V_36 ) ) {
V_285 = V_36 -> V_38 . V_22 ;
} else if ( V_93 -> V_288 && F_26 ( V_93 -> V_288 , V_93 -> V_95 ) ) {
V_36 -> V_38 . V_22 = V_285 = V_93 -> V_288 ;
} else {
F_35 ( V_93 ) ;
V_36 -> V_38 . V_22 = V_285 = F_27 ( V_75 , V_93 -> V_95 , 1 ) ;
}
if ( F_115 ( V_93 -> V_94 . V_234 ) && ( V_231 -> V_289 & V_290 ) )
V_255 = F_132 ( V_93 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_291 ;
while ( V_263 < 3 ) {
V_286 = 1 ;
if ( ! F_77 ( V_36 -> V_38 . V_22 -> V_116 ) ) {
V_286 = 0 ;
if ( V_255 && V_255 -- )
goto V_292;
if ( ! F_47 ( V_36 ) && ( V_263 < 2 ) &&
F_128 ( V_36 , 1000 ) &&
F_124 ( V_36 -> V_38 . V_22 , V_263 ) )
goto V_292;
error = F_78 ( V_36 -> V_38 . V_22 -> V_116 ,
V_224 , V_287 ,
& V_36 -> V_293 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_47 ( V_36 ) && ( V_263 < 2 ) &&
F_124 ( V_36 -> V_38 . V_22 , V_263 ) )
goto V_294;
if ( V_75 -> V_184 . V_185 ) {
error = F_96 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_79 ( & V_36 -> V_293 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_149 & ( V_295 |
V_296 ) ) ||
( V_231 -> V_236 > V_36 -> V_38 . V_22 -> V_109 ) )
goto V_294;
if ( V_75 -> V_184 . V_185 )
F_90 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_47 ( V_36 ) )
F_114 ( V_36 -> V_38 . V_22 , V_93 , V_231 ) ;
if ( ! F_47 ( V_36 ) && ( V_263 < 1 ) )
goto V_297;
if ( V_36 -> V_38 . V_22 -> V_183 >= V_231 -> V_236 ) {
V_93 -> V_288 = V_36 -> V_38 . V_22 ;
return 0 ;
}
V_297:
if ( V_36 -> V_38 . V_22 -> V_149 & V_182 )
F_122 ( V_36 -> V_38 . V_22 , & V_254 ,
V_93 -> V_96 ) ;
V_294:
if ( F_47 ( V_36 ) )
F_51 ( V_36 ) ;
if ( ! V_286 )
F_79 ( & V_36 -> V_293 ) ;
V_292:
if ( F_134 ( & V_36 -> V_38 . V_22 , V_285 ) )
continue;
if ( V_255 )
continue;
V_263 ++ ;
if ( V_93 == F_64 ( V_75 -> V_127 ) && ! V_75 -> V_152 ) {
error = F_75 ( V_93 ) ;
if ( error )
return error ;
}
if ( V_263 == 2 )
F_136 ( V_75 , NULL , V_298 ) ;
}
return - V_253 ;
}
void F_137 ( struct V_92 * V_93 )
{
struct V_35 * V_36 = V_93 -> V_98 ;
if ( V_36 -> V_293 . V_187 )
F_79 ( & V_36 -> V_293 ) ;
}
static unsigned char F_138 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_214 ;
V_214 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_214 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_139 ( const struct V_1 * V_2 , bool V_299 ,
unsigned int * V_59 )
{
struct V_1 V_130 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_300 = * V_59 ;
T_2 V_44 ;
int V_214 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_110 ( V_2 -> V_22 -> V_116 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_299 ? V_301 : V_302 ) ;
V_44 ++ ;
while ( * V_59 < V_300 ) {
V_214 = F_16 ( & V_130 , V_44 ) ;
if ( V_214 || F_8 ( & V_130 ) != V_61 )
break;
F_110 ( V_130 . V_22 -> V_116 , F_2 ( & V_130 ) -> V_17 ) ;
F_1 ( & V_130 , true , V_302 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_140 ( struct V_74 * V_75 , T_2 V_303 ,
T_4 V_304 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 , * V_305 = NULL ;
V_2 . V_22 = F_27 ( V_75 , V_303 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_141 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_303 ) ;
return NULL ;
}
F_16 ( & V_2 , V_303 ) ;
while ( V_304 -- ) {
V_10 = F_2 ( & V_2 ) ;
if ( V_10 != V_305 ) {
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_142 ( V_10 -> V_17 -> V_68 ,
V_100 | V_306 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 ,
V_10 -> V_12 ) ;
}
F_110 ( V_2 . V_22 -> V_116 , V_10 -> V_17 ) ;
V_305 = V_10 ;
}
F_1 ( & V_2 , false , V_4 ) ;
F_18 ( & V_2 ) ;
}
return V_2 . V_22 ;
}
void F_143 ( struct V_103 * V_104 , const struct V_114 * V_115 )
{
struct V_69 * V_22 = V_115 -> V_118 ;
struct V_35 * V_307 ;
const struct V_84 * V_59 ;
if ( V_22 == NULL )
return;
F_45 ( V_104 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_149 ,
V_22 -> V_79 , V_22 -> V_183 , V_22 -> V_80 ,
V_22 -> V_108 , V_22 -> V_109 ) ;
F_28 ( & V_22 -> V_112 ) ;
for ( V_59 = F_32 ( & V_22 -> V_107 ) ; V_59 ; V_59 = F_34 ( & V_307 -> V_102 ) ) {
V_307 = F_29 ( V_59 , struct V_35 , V_102 ) ;
F_44 ( V_104 , V_307 ) ;
}
F_30 ( & V_22 -> V_112 ) ;
}
static void F_144 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_101 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_101 ( V_75 , L_18 ) ;
F_143 ( NULL , V_22 -> V_116 ) ;
V_22 -> V_149 |= V_296 ;
}
static void F_145 ( struct V_92 * V_93 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_93 -> V_98 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_308 ;
T_2 V_44 ;
int V_214 ;
F_28 ( & V_22 -> V_112 ) ;
if ( F_47 ( V_36 ) ) {
if ( F_146 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_214 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_308 = F_147 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_308 ;
V_22 -> V_108 -= V_308 ;
F_48 ( V_36 , V_309 ) ;
if ( V_36 -> V_39 && ! V_214 )
goto V_67;
}
F_46 ( V_36 ) ;
}
V_67:
F_30 ( & V_22 -> V_112 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
const struct V_92 * V_93 , bool V_299 )
{
T_2 V_41 ;
if ( F_47 ( V_93 -> V_98 ) ) {
* V_2 = V_93 -> V_98 -> V_38 ;
return;
}
if ( ! V_299 && F_26 ( V_2 -> V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_2 -> V_22 -> V_238 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_149 ( struct V_92 * V_93 , T_2 * V_310 , unsigned int * V_311 ,
bool V_299 , T_2 * V_312 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_190 * V_313 ;
struct V_1 V_2 = { . V_22 = V_93 -> V_288 , } ;
unsigned int V_314 ;
T_2 V_44 ;
int error ;
F_148 ( & V_2 , V_93 , V_299 ) ;
error = F_117 ( & V_2 , V_61 , NULL , V_93 , false , NULL ) ;
if ( error == - V_253 ) {
F_148 ( & V_2 , V_93 , V_299 ) ;
error = F_117 ( & V_2 , V_61 , NULL , NULL , false ,
NULL ) ;
}
if ( error ) {
F_101 ( V_75 , L_19 ,
( unsigned long long ) V_93 -> V_96 , error , * V_311 ,
F_120 ( V_110 , & V_2 . V_22 -> V_78 -> V_111 ) ,
V_2 . V_22 -> V_109 ) ;
goto V_315;
}
F_139 ( & V_2 , V_299 , V_311 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_238 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_47 ( V_93 -> V_98 ) )
F_145 ( V_93 , & V_2 , * V_311 ) ;
V_314 = * V_311 ;
if ( V_299 )
V_314 -- ;
if ( ! V_299 ) {
V_93 -> V_95 = V_44 + V_314 - 1 ;
error = F_150 ( V_93 , & V_313 ) ;
if ( error == 0 ) {
struct V_316 * V_317 =
(struct V_316 * ) V_313 -> V_18 ;
F_110 ( V_93 -> V_153 , V_313 ) ;
V_317 -> V_318 = V_317 -> V_319 =
F_83 ( V_93 -> V_95 ) ;
F_94 ( V_313 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_311 ) {
F_5 ( L_20 , * V_311 ) ;
goto V_315;
}
V_2 . V_22 -> V_79 -= * V_311 ;
if ( V_299 ) {
V_2 . V_22 -> V_80 ++ ;
* V_312 = V_2 . V_22 -> V_163 ++ ;
if ( * V_312 == 0 )
* V_312 = V_2 . V_22 -> V_163 ++ ;
}
F_110 ( V_2 . V_22 -> V_116 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_81 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_2 . V_22 -> V_145 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_151 ( V_75 , 0 , - ( T_9 ) * V_311 , V_299 ? 1 : 0 ) ;
if ( V_299 )
F_152 ( V_75 , V_44 , * V_311 ) ;
F_153 ( V_93 , * V_311 , V_93 -> V_94 . V_320 , V_93 -> V_94 . V_321 ) ;
V_2 . V_22 -> V_183 -= * V_311 ;
F_154 ( V_93 , V_2 . V_22 , V_44 , * V_311 ,
V_299 ? V_301 : V_302 ) ;
* V_310 = V_44 ;
return 0 ;
V_315:
F_144 ( V_2 . V_22 ) ;
return - V_124 ;
}
void F_155 ( struct V_92 * V_93 , T_2 V_303 , T_4 V_304 , int V_322 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
V_22 = F_140 ( V_75 , V_303 , V_304 , V_61 ) ;
if ( ! V_22 )
return;
F_154 ( V_93 , V_22 , V_303 , V_304 , V_61 ) ;
V_22 -> V_79 += V_304 ;
V_22 -> V_149 &= ~ V_225 ;
F_110 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_81 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_22 -> V_145 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_322 || V_93 -> V_323 )
F_156 ( V_93 , V_303 , V_304 ) ;
}
void F_157 ( struct V_92 * V_93 , T_2 V_303 , T_4 V_304 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
F_155 ( V_93 , V_303 , V_304 , 1 ) ;
F_151 ( V_75 , 0 , + V_304 , 0 ) ;
F_153 ( V_93 , - ( T_9 ) V_304 , V_93 -> V_94 . V_320 , V_93 -> V_94 . V_321 ) ;
}
void F_158 ( struct V_126 * V_126 )
{
struct V_92 * V_93 = F_64 ( V_126 ) ;
struct V_74 * V_75 = F_36 ( V_126 ) ;
struct V_69 * V_22 ;
T_2 V_324 = V_93 -> V_96 ;
V_22 = F_140 ( V_75 , V_324 , 1 , V_178 ) ;
if ( ! V_22 )
return;
F_154 ( V_93 , V_22 , V_324 , 1 , V_178 ) ;
F_110 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_81 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_22 -> V_145 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_86 ( V_22 , 1 ) ;
}
static void F_159 ( struct V_69 * V_22 , T_2 V_324 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_325 ;
V_325 = F_140 ( V_75 , V_324 , 1 , V_61 ) ;
if ( ! V_325 )
return;
F_160 ( V_75 , V_22 == V_325 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_110 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_81 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_22 -> V_145 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_86 ( V_22 , - 1 ) ;
F_151 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_161 ( struct V_69 * V_22 , struct V_92 * V_93 )
{
F_159 ( V_22 , V_93 -> V_96 ) ;
F_154 ( V_93 , V_22 , V_93 -> V_96 , 1 , V_61 ) ;
F_153 ( V_93 , - 1 , V_93 -> V_94 . V_320 , V_93 -> V_94 . V_321 ) ;
F_156 ( V_93 , V_93 -> V_96 , 1 ) ;
}
int F_162 ( struct V_74 * V_75 , T_2 V_326 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_154 V_327 ;
int error = - V_48 ;
V_22 = F_27 ( V_75 , V_326 , 1 ) ;
if ( ! V_22 )
goto V_141;
error = F_78 ( V_22 -> V_116 , V_157 , 0 , & V_327 ) ;
if ( error )
goto V_141;
if ( F_138 ( V_22 , V_326 ) != type )
error = - V_328 ;
F_79 ( & V_327 ) ;
V_141:
return error ;
}
void F_163 ( struct V_92 * V_93 , struct V_329 * V_330 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_331 ;
unsigned int V_77 ;
if ( F_95 ( V_75 , ! V_330 -> V_332 ) )
return;
if ( V_93 -> V_288 && F_26 ( V_93 -> V_288 , V_44 ) )
V_22 = V_93 -> V_288 ;
else
V_22 = F_27 ( V_75 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_25 ( V_75 , L_21 , ( unsigned long long ) V_44 ) ;
return;
}
V_93 -> V_288 = V_22 ;
for ( V_77 = 0 ; V_77 < V_330 -> V_333 ; V_77 ++ )
if ( V_330 -> V_334 [ V_77 ] == V_22 )
return;
if ( V_330 -> V_333 == V_330 -> V_335 ) {
V_331 = V_330 -> V_335 + 10 ;
V_31 = F_62 ( V_331 , sizeof( struct V_69 * ) ,
V_100 | V_306 ) ;
if ( V_330 -> V_334 ) {
memcpy ( V_31 , V_330 -> V_334 ,
V_330 -> V_335 * sizeof( struct V_69 * ) ) ;
F_38 ( V_330 -> V_334 ) ;
}
V_330 -> V_335 = V_331 ;
V_330 -> V_334 = V_31 ;
}
V_330 -> V_334 [ V_330 -> V_333 ++ ] = V_22 ;
}
void F_164 ( struct V_329 * V_330 , unsigned int V_30 )
{
unsigned int V_77 ;
V_330 -> V_332 = F_62 ( V_330 -> V_333 , sizeof( struct V_154 ) ,
V_100 | V_306 ) ;
for ( V_77 = 0 ; V_77 < V_330 -> V_333 ; V_77 ++ )
F_165 ( V_330 -> V_334 [ V_77 ] -> V_116 ,
V_30 , 0 ,
& V_330 -> V_332 [ V_77 ] ) ;
}
void F_166 ( struct V_329 * V_330 )
{
unsigned int V_77 ;
F_38 ( V_330 -> V_334 ) ;
if ( V_330 -> V_332 ) {
for ( V_77 = 0 ; V_77 < V_330 -> V_333 ; V_77 ++ )
F_167 ( & V_330 -> V_332 [ V_77 ] ) ;
F_38 ( V_330 -> V_332 ) ;
V_330 -> V_332 = NULL ;
}
}
