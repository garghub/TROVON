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
V_22 -> V_149 &= ~ ( V_150 | V_151 ) ;
if ( V_22 -> V_49 > V_75 -> V_152 )
V_75 -> V_152 = V_22 -> V_49 ;
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
static void F_75 ( struct V_74 * V_75 )
{
struct V_69 * V_22 , * V_81 ;
int V_153 ;
V_22 = F_31 ( V_75 ) ;
for ( V_153 = 0 ; V_153 < V_75 -> V_154 . V_155 ; V_153 ++ )
V_22 = F_33 ( V_22 ) ;
V_81 = V_22 ;
do {
V_22 -> V_149 |= V_151 ;
for ( V_153 = 0 ; V_153 < V_75 -> V_156 ; V_153 ++ ) {
V_22 = F_33 ( V_22 ) ;
if ( V_22 == V_81 )
break;
}
} while ( V_22 != V_81 );
}
static int F_76 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
int error ;
do {
error = F_71 ( V_93 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
F_75 ( V_75 ) ;
V_75 -> V_157 = 1 ;
return 0 ;
}
int F_77 ( struct V_74 * V_75 )
{
struct V_92 * V_93 = F_64 ( V_75 -> V_127 ) ;
struct V_114 * V_115 = V_93 -> V_158 ;
struct V_159 V_160 ;
int error = 0 ;
int V_161 = 0 ;
if ( ! V_75 -> V_157 ) {
if ( ! F_78 ( V_115 ) ) {
error = F_79 ( V_115 , V_162 , 0 , & V_160 ) ;
if ( error )
return error ;
V_161 = 1 ;
}
if ( ! V_75 -> V_157 )
error = F_76 ( V_93 ) ;
if ( V_161 )
F_80 ( & V_160 ) ;
}
return error ;
}
static void F_81 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_163 = V_40 ;
T_4 V_164 ;
V_164 = F_67 ( V_163 -> V_164 ) ;
V_164 &= ~ V_165 ;
V_22 -> V_149 &= V_165 ;
V_22 -> V_149 |= V_164 ;
V_22 -> V_79 = F_67 ( V_163 -> V_166 ) ;
V_22 -> V_80 = F_67 ( V_163 -> V_167 ) ;
V_22 -> V_168 = F_72 ( V_163 -> V_169 ) ;
}
static void F_82 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_163 = V_40 ;
V_163 -> V_164 = F_83 ( V_22 -> V_149 & ~ V_165 ) ;
V_163 -> V_166 = F_83 ( V_22 -> V_79 ) ;
V_163 -> V_167 = F_83 ( V_22 -> V_80 ) ;
V_163 -> V_170 = F_83 ( 0 ) ;
V_163 -> V_169 = F_84 ( V_22 -> V_168 ) ;
memset ( & V_163 -> V_171 , 0 , sizeof( V_163 -> V_171 ) ) ;
}
static int F_85 ( struct V_69 * V_22 )
{
struct V_146 * V_172 = V_22 -> V_145 ;
struct V_53 * V_163 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_172 -> V_173 != V_163 -> V_164 || V_172 -> V_174 != V_163 -> V_166 ||
V_172 -> V_175 != V_163 -> V_167 ||
V_172 -> V_176 != V_163 -> V_169 )
return 0 ;
return 1 ;
}
static void F_86 ( struct V_146 * V_172 , const void * V_40 )
{
const struct V_53 * V_163 = V_40 ;
V_172 -> V_177 = F_83 ( V_178 ) ;
V_172 -> V_173 = V_163 -> V_164 ;
V_172 -> V_174 = V_163 -> V_166 ;
V_172 -> V_175 = V_163 -> V_167 ;
V_172 -> V_176 = V_163 -> V_169 ;
V_172 -> V_170 = 0UL ;
}
static void F_87 ( struct V_69 * V_22 , T_4 V_179 )
{
struct V_146 * V_172 = V_22 -> V_145 ;
T_4 V_180 = F_67 ( V_172 -> V_181 ) + V_179 ;
V_172 -> V_181 = F_83 ( V_180 ) ;
}
static T_4 F_88 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_153 , V_41 , V_73 = 0 ;
for ( V_153 = 0 , V_10 = V_22 -> V_78 ; V_153 < V_76 ; V_153 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_89 ( ! F_90 ( V_10 -> V_17 ) ) ;
while ( V_41 < V_10 -> V_12 * V_15 ) {
V_41 = F_13 ( V_26 , V_10 -> V_12 , V_41 ,
V_182 ) ;
if ( V_41 == V_43 )
break;
V_73 ++ ;
V_41 ++ ;
}
}
return V_73 ;
}
static int F_91 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_114 * V_115 = V_22 -> V_116 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_183 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_92 ( V_115 , V_22 -> V_23 + V_77 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_141;
}
for ( V_183 = V_76 ; V_183 -- ; ) {
V_10 = V_22 -> V_78 + V_183 ;
error = F_93 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_141;
if ( F_94 ( V_75 , V_10 -> V_17 , V_183 ? V_184 :
V_185 ) ) {
error = - V_124 ;
goto V_141;
}
}
if ( ! ( V_22 -> V_149 & V_150 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_50 ( V_110 , & V_22 -> V_78 [ V_77 ] . V_111 ) ;
F_81 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_149 |= ( V_150 | V_186 ) ;
V_22 -> V_187 = V_22 -> V_79 ;
V_22 -> V_109 = V_22 -> V_79 ;
}
if ( F_83 ( V_178 ) != V_22 -> V_145 -> V_177 ) {
V_22 -> V_145 -> V_181 = F_83 ( F_88 ( V_22 ) ) ;
F_86 ( V_22 -> V_145 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_188 . V_189 ) {
if ( ! F_85 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_124 ;
goto V_141;
}
if ( V_22 -> V_145 -> V_181 == 0 )
V_22 -> V_149 &= ~ V_186 ;
}
return 0 ;
V_141:
while ( V_77 -- ) {
V_10 = V_22 -> V_78 + V_77 ;
F_95 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_96 ( V_75 , ! V_10 -> V_25 ) ;
}
return error ;
}
static int F_97 ( struct V_69 * V_22 )
{
T_4 V_173 ;
if ( V_22 -> V_149 & V_150 )
return 0 ;
if ( F_83 ( V_178 ) != V_22 -> V_145 -> V_177 )
return F_91 ( V_22 ) ;
V_173 = F_67 ( V_22 -> V_145 -> V_173 ) ;
V_173 &= ~ V_165 ;
V_22 -> V_149 &= V_165 ;
V_22 -> V_149 |= ( V_173 | V_150 | V_186 ) ;
if ( V_22 -> V_145 -> V_181 == 0 )
V_22 -> V_149 &= ~ V_186 ;
V_22 -> V_79 = F_67 ( V_22 -> V_145 -> V_174 ) ;
V_22 -> V_187 = V_22 -> V_79 ;
V_22 -> V_80 = F_67 ( V_22 -> V_145 -> V_175 ) ;
V_22 -> V_168 = F_72 ( V_22 -> V_145 -> V_176 ) ;
return 0 ;
}
int F_98 ( struct V_159 * V_190 )
{
struct V_69 * V_22 = V_190 -> V_191 -> V_118 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_190 -> V_192 & V_193 && V_75 -> V_188 . V_189 )
return 0 ;
return F_91 ( V_22 ) ;
}
void F_99 ( struct V_159 * V_190 )
{
struct V_69 * V_22 = V_190 -> V_191 -> V_118 ;
int V_77 , V_76 = V_22 -> V_57 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
if ( V_10 -> V_17 ) {
F_95 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
int F_100 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_194 * V_195 ,
const struct V_9 * V_10 , unsigned V_196 , T_2 * V_197 )
{
struct V_198 * V_199 = V_75 -> V_200 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_201 = 0 ;
int V_202 ;
unsigned int V_77 ;
T_4 V_203 = 0 ;
T_1 V_204 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_205 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_205 += V_10 -> V_19 ;
V_205 += V_77 ;
if ( V_195 ) {
const T_1 * V_206 = V_195 -> V_18 + V_10 -> V_19 + V_77 ;
V_204 = ~ ( * V_206 | ( * V_206 >> 1 ) ) & ( * V_205 | ( * V_205 >> 1 ) ) ;
} else {
V_204 = ~ ( * V_205 | ( * V_205 >> 1 ) ) ;
}
V_204 &= 0x55 ;
if ( V_204 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_204 ) {
if ( V_204 & 1 ) {
if ( V_201 == 0 )
goto V_207;
if ( ( V_66 + V_201 ) != V_33 ) {
if ( V_201 >= V_196 ) {
V_202 = F_101 ( V_199 ,
V_66 , V_201 ,
V_100 , 0 ) ;
if ( V_202 )
goto V_141;
V_203 += V_201 ;
}
V_201 = 0 ;
V_207:
V_66 = V_33 ;
}
V_201 ++ ;
}
V_204 >>= 2 ;
V_33 ++ ;
}
}
if ( V_201 >= V_196 ) {
V_202 = F_101 ( V_199 , V_66 , V_201 , V_100 , 0 ) ;
if ( V_202 )
goto V_141;
V_203 += V_201 ;
}
if ( V_197 )
* V_197 = V_203 ;
return 0 ;
V_141:
if ( V_75 -> V_188 . V_208 )
F_102 ( V_75 , L_14 , V_202 ) ;
V_75 -> V_188 . V_208 = 0 ;
return - V_124 ;
}
int F_103 ( struct V_209 * V_210 , void T_8 * V_211 )
{
struct V_126 * V_126 = F_104 ( V_210 ) ;
struct V_74 * V_75 = F_36 ( V_126 ) ;
struct V_212 * V_213 = F_105 ( V_75 -> V_200 -> V_214 ) ;
struct V_194 * V_195 ;
struct V_69 * V_22 ;
struct V_69 * V_215 ;
struct V_159 V_190 ;
struct V_216 V_217 ;
int V_218 = 0 ;
T_2 V_219 ;
T_2 V_203 = 0 ;
T_2 V_66 , V_7 , V_196 ;
unsigned int V_77 ;
unsigned V_220 = V_75 -> V_122 . V_221 ;
if ( ! F_106 ( V_222 ) )
return - V_223 ;
if ( ! F_107 ( V_213 ) )
return - V_224 ;
if ( F_108 ( & V_217 , V_211 , sizeof( V_217 ) ) )
return - V_225 ;
V_218 = F_77 ( V_75 ) ;
if ( V_218 )
return V_218 ;
V_66 = V_217 . V_66 >> V_220 ;
V_7 = V_66 + ( V_217 . V_34 >> V_220 ) ;
V_196 = F_109 ( T_2 , V_217 . V_196 ,
V_213 -> V_226 . V_227 ) >> V_220 ;
if ( V_7 <= V_66 || V_196 > V_75 -> V_152 )
return - V_48 ;
V_22 = F_27 ( V_75 , V_66 , 0 ) ;
V_215 = F_27 ( V_75 , V_7 , 0 ) ;
if ( ( F_31 ( V_75 ) == F_33 ( V_215 ) )
&& ( V_66 > V_215 -> V_46 + V_215 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_218 = F_79 ( V_22 -> V_116 , V_228 , 0 , & V_190 ) ;
if ( V_218 )
goto V_67;
if ( ! ( V_22 -> V_149 & V_229 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_218 = F_100 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_196 ,
& V_219 ) ;
if ( V_218 ) {
F_80 ( & V_190 ) ;
goto V_67;
}
V_203 += V_219 ;
}
V_218 = F_110 ( V_75 , V_230 , 0 ) ;
if ( V_218 == 0 ) {
V_195 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_149 |= V_229 ;
F_111 ( V_22 -> V_116 , V_195 ) ;
F_82 ( V_22 , V_195 -> V_18 ) ;
F_86 ( V_22 -> V_145 , V_195 -> V_18 ) ;
F_112 ( V_75 ) ;
}
}
F_80 ( & V_190 ) ;
if ( V_22 == V_215 )
break;
V_22 = F_33 ( V_22 ) ;
}
V_67:
V_217 . V_34 = V_203 << V_220 ;
if ( F_113 ( V_211 , & V_217 , sizeof( V_217 ) ) )
return - V_225 ;
return V_218 ;
}
static void F_114 ( struct V_92 * V_93 )
{
struct V_84 * * V_132 , * V_133 = NULL ;
int V_231 ;
struct V_35 * V_36 = V_93 -> V_98 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_232 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_47 ( V_36 ) ) ;
F_28 ( & V_22 -> V_112 ) ;
V_132 = & V_22 -> V_107 . V_84 ;
while ( * V_132 ) {
struct V_35 * V_86 =
F_29 ( * V_132 , struct V_35 , V_102 ) ;
V_133 = * V_132 ;
V_231 = F_11 ( V_232 , V_36 -> V_39 , V_86 ) ;
if ( V_231 > 0 )
V_132 = & ( ( * V_132 ) -> V_91 ) ;
else if ( V_231 < 0 )
V_132 = & ( ( * V_132 ) -> V_90 ) ;
else {
F_30 ( & V_22 -> V_112 ) ;
F_89 ( 1 ) ;
return;
}
}
F_69 ( & V_36 -> V_102 , V_133 , V_132 ) ;
F_70 ( & V_36 -> V_102 , & V_22 -> V_107 ) ;
V_22 -> V_108 += V_36 -> V_39 ;
F_30 ( & V_22 -> V_112 ) ;
F_48 ( V_36 , V_233 ) ;
}
static void F_115 ( struct V_69 * V_22 , struct V_92 * V_93 ,
const struct V_234 * V_235 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_93 -> V_98 ;
T_4 V_236 ;
T_4 V_237 = V_22 -> V_187 - V_22 -> V_108 ;
int V_218 ;
struct V_126 * V_126 = & V_93 -> V_94 ;
if ( F_116 ( V_126 -> V_238 ) )
V_236 = 1 ;
else {
V_236 = F_109 ( T_4 , F_53 ( & V_36 -> V_239 ) , V_235 -> V_240 ) ;
V_236 = F_117 ( V_236 , V_241 , V_237 ) ;
}
if ( ( V_22 -> V_187 < V_22 -> V_108 ) || ( V_237 < V_236 ) )
return;
if ( F_26 ( V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_22 -> V_242 + V_22 -> V_46 ;
if ( F_89 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_218 = F_118 ( & V_2 , V_61 , & V_236 , V_93 , true , V_235 ) ;
if ( V_218 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_236 ;
V_36 -> V_105 = V_93 -> V_96 ;
F_114 ( V_93 ) ;
} else {
if ( V_41 == V_22 -> V_242 + V_22 -> V_46 )
V_22 -> V_242 = 0 ;
}
}
static T_2 F_119 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_92 * V_93 )
{
struct V_35 * V_36 ;
struct V_84 * V_59 ;
int V_231 ;
F_28 ( & V_22 -> V_112 ) ;
V_59 = V_22 -> V_107 . V_84 ;
while ( V_59 ) {
V_36 = F_29 ( V_59 , struct V_35 , V_102 ) ;
V_231 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_231 < 0 )
V_59 = V_59 -> V_90 ;
else if ( V_231 > 0 )
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
static int F_120 ( struct V_1 * V_2 ,
const struct V_92 * V_93 ,
T_4 V_243 ,
struct V_244 * V_245 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_236 = 1 ;
T_2 V_246 ;
int V_218 ;
if ( V_243 ) {
V_236 = F_20 ( V_2 , V_243 ) ;
if ( V_236 <= V_245 -> V_34 )
goto V_141;
}
V_246 = F_119 ( V_2 -> V_22 , V_44 , V_236 , V_93 ) ;
if ( V_246 == V_44 ) {
if ( ! V_243 || V_236 >= V_243 )
return 0 ;
if ( V_236 > V_245 -> V_34 ) {
V_245 -> V_34 = V_236 ;
V_245 -> V_2 = * V_2 ;
}
V_141:
V_246 = V_44 + V_236 ;
}
V_218 = F_16 ( V_2 , V_246 ) ;
if ( V_218 < 0 )
return V_218 ;
return 1 ;
}
static int F_118 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_243 ,
const struct V_92 * V_93 , bool V_247 ,
const struct V_234 * V_235 )
{
struct V_194 * V_195 ;
int V_248 ;
T_4 V_249 ;
int V_250 = V_2 -> V_51 ;
T_4 V_251 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_252 = V_2 -> V_22 -> V_57 ;
int V_218 ;
struct V_9 * V_10 ;
struct V_244 V_245 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_252 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_121 ( V_110 , & V_10 -> V_111 ) &&
( V_30 == V_61 ) )
goto V_253;
V_195 = V_10 -> V_17 ;
V_26 = V_195 -> V_18 + V_10 -> V_19 ;
F_89 ( ! F_90 ( V_195 ) ) ;
if ( V_30 != V_182 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_249 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_254;
V_2 -> V_14 = V_14 ;
if ( V_93 == NULL )
return 0 ;
V_248 = V_2 -> V_51 ;
V_218 = F_120 ( V_2 , V_93 ,
V_243 ? * V_243 : 0 ,
& V_245 ) ;
if ( V_218 == 0 )
return 0 ;
if ( V_218 > 0 ) {
V_59 += ( V_2 -> V_51 - V_248 ) ;
goto V_255;
}
if ( V_218 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_248 ) ;
goto V_256;
}
return V_218 ;
V_254:
if ( ( V_30 == V_61 ) && V_249 == 0 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_122 ( V_110 , & V_10 -> V_111 ) ;
}
V_253:
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 )
V_2 -> V_51 = 0 ;
V_256:
if ( ( V_2 -> V_51 == 0 ) && V_247 )
break;
V_59 ++ ;
V_255:
if ( V_59 >= V_252 )
break;
}
if ( V_243 == NULL || V_30 != V_61 )
return - V_257 ;
if ( ( V_251 == 0 ) && ( V_250 == 0 ) &&
( * V_243 < V_2 -> V_22 -> V_109 ) )
V_2 -> V_22 -> V_109 = * V_243 ;
if ( V_245 . V_34 ) {
* V_2 = V_245 . V_2 ;
* V_243 = V_245 . V_34 ;
return 0 ;
}
return - V_257 ;
}
static void F_123 ( struct V_69 * V_22 , T_2 * V_258 , T_2 V_259 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_114 * V_115 ;
struct V_92 * V_93 ;
int error ;
int V_260 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_40 ( & V_75 -> V_261 ) ;
error = F_118 ( & V_2 , V_182 , NULL , NULL ,
true , NULL ) ;
F_43 ( & V_75 -> V_261 ) ;
if ( error == - V_257 )
break;
if ( F_17 ( error ) )
break;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_258 != V_262 && V_44 <= * V_258 )
continue;
if ( V_44 == V_259 )
continue;
* V_258 = V_44 ;
error = F_74 ( V_75 , V_44 , & V_263 , V_143 , & V_115 ) ;
if ( error )
continue;
V_93 = V_115 -> V_118 ;
if ( V_93 || F_124 ( V_264 , & V_115 -> V_265 ) == 0 )
F_58 ( V_115 ) ;
else
V_260 ++ ;
if ( V_260 > V_266 )
return;
}
V_22 -> V_149 &= ~ V_186 ;
return;
}
static bool F_125 ( const struct V_69 * V_22 , int V_267 )
{
const struct V_114 * V_115 = V_22 -> V_116 ;
const struct V_74 * V_75 = V_115 -> V_268 ;
struct V_269 * V_270 ;
T_9 V_271 , V_272 ;
T_9 V_273 , V_274 ;
T_9 V_275 ;
T_9 V_276 ;
T_9 V_277 ;
F_126 () ;
V_270 = & F_127 ( V_75 -> V_278 ) -> V_279 [ V_280 ] ;
V_273 = V_270 -> V_281 [ V_282 ] ;
V_271 = V_270 -> V_281 [ V_283 ] ;
V_277 = V_270 -> V_281 [ V_284 ] +
V_115 -> V_285 . V_281 [ V_284 ] ;
F_128 () ;
V_274 = V_115 -> V_285 . V_281 [ V_282 ] ;
V_272 = V_115 -> V_285 . V_281 [ V_283 ] ;
if ( ( V_272 < 1 ) || ( V_271 < 1 ) || ( V_273 == 0 ) )
return false ;
V_275 = V_273 - V_274 ;
V_276 = V_275 * V_275 ;
V_277 *= 2 ;
if ( V_272 < 8 || V_271 < 8 )
V_277 *= 2 ;
if ( V_267 == 1 )
V_277 *= 2 ;
return ( ( V_275 < 0 ) && ( V_276 > V_277 ) ) ;
}
static bool F_129 ( const struct V_35 * V_36 ,
T_2 V_286 )
{
T_2 V_287 ;
V_287 = F_130 ( F_131 ( F_132 () ,
V_36 -> V_38 . V_22 -> V_116 -> V_288 ) ) ;
return V_287 > ( V_286 * 1000 * 1000 ) ;
}
static T_4 F_133 ( const struct V_92 * V_93 )
{
const struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
T_4 V_259 ;
F_134 ( & V_259 , sizeof( V_259 ) ) ;
return V_259 % V_75 -> V_135 ;
}
static bool F_135 ( struct V_69 * * V_130 , const struct V_69 * V_289 )
{
struct V_69 * V_22 = * V_130 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_33 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_31 ( V_75 ) ;
* V_130 = V_22 ;
if ( V_22 != V_289 )
return true ;
return false ;
}
static inline int F_136 ( struct V_69 * V_22 )
{
struct V_114 * V_115 = V_22 -> V_116 ;
if ( V_115 -> V_290 != V_291 && F_137 ( & V_115 -> V_292 ) &&
! F_121 ( V_293 , & V_115 -> V_294 ) &&
! F_121 ( V_295 , & V_115 -> V_294 ) )
return 1 ;
if ( V_22 -> V_149 & V_151 )
return 1 ;
return 0 ;
}
int F_138 ( struct V_92 * V_93 , const struct V_234 * V_235 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_289 = NULL ;
struct V_35 * V_36 = V_93 -> V_98 ;
int error = 0 , V_296 , V_297 = 0 ;
T_2 V_258 = V_262 ;
int V_267 = 0 ;
T_4 V_259 = 0 ;
if ( V_75 -> V_188 . V_189 )
V_297 |= V_193 ;
if ( F_96 ( V_75 , V_235 -> V_240 ) )
return - V_48 ;
if ( F_47 ( V_36 ) ) {
V_289 = V_36 -> V_38 . V_22 ;
} else if ( V_93 -> V_298 && F_26 ( V_93 -> V_298 , V_93 -> V_95 ) ) {
V_36 -> V_38 . V_22 = V_289 = V_93 -> V_298 ;
} else {
F_35 ( V_93 ) ;
V_36 -> V_38 . V_22 = V_289 = F_27 ( V_75 , V_93 -> V_95 , 1 ) ;
}
if ( F_116 ( V_93 -> V_94 . V_238 ) && ( V_235 -> V_299 & V_300 ) )
V_259 = F_133 ( V_93 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_301 ;
while ( V_267 < 3 ) {
V_296 = 1 ;
if ( ! F_78 ( V_36 -> V_38 . V_22 -> V_116 ) ) {
V_296 = 0 ;
if ( V_259 && V_259 -- )
goto V_302;
if ( ! F_47 ( V_36 ) ) {
if ( V_267 == 0 &&
! F_136 ( V_36 -> V_38 . V_22 ) )
goto V_302;
if ( ( V_267 < 2 ) &&
F_129 ( V_36 , 1000 ) &&
F_125 ( V_36 -> V_38 . V_22 , V_267 ) )
goto V_302;
}
error = F_79 ( V_36 -> V_38 . V_22 -> V_116 ,
V_228 , V_297 ,
& V_36 -> V_303 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_47 ( V_36 ) && ( V_267 < 2 ) &&
F_125 ( V_36 -> V_38 . V_22 , V_267 ) )
goto V_304;
if ( V_75 -> V_188 . V_189 ) {
error = F_97 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_80 ( & V_36 -> V_303 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_149 & ( V_305 |
V_306 ) ) ||
( V_235 -> V_240 > V_36 -> V_38 . V_22 -> V_109 ) )
goto V_304;
if ( V_75 -> V_188 . V_189 )
F_91 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_47 ( V_36 ) )
F_115 ( V_36 -> V_38 . V_22 , V_93 , V_235 ) ;
if ( ! F_47 ( V_36 ) && ( V_267 < 1 ) )
goto V_307;
if ( V_36 -> V_38 . V_22 -> V_187 >= V_235 -> V_240 ) {
V_93 -> V_298 = V_36 -> V_38 . V_22 ;
return 0 ;
}
V_307:
if ( V_36 -> V_38 . V_22 -> V_149 & V_186 )
F_123 ( V_36 -> V_38 . V_22 , & V_258 ,
V_93 -> V_96 ) ;
V_304:
if ( F_47 ( V_36 ) )
F_51 ( V_36 ) ;
if ( ! V_296 )
F_80 ( & V_36 -> V_303 ) ;
V_302:
if ( F_135 ( & V_36 -> V_38 . V_22 , V_289 ) )
continue;
if ( V_259 )
continue;
V_267 ++ ;
if ( V_93 == F_64 ( V_75 -> V_127 ) && ! V_75 -> V_157 ) {
error = F_76 ( V_93 ) ;
if ( error )
return error ;
}
if ( V_267 == 2 )
F_139 ( V_75 , NULL , V_308 ) ;
}
return - V_257 ;
}
void F_140 ( struct V_92 * V_93 )
{
struct V_35 * V_36 = V_93 -> V_98 ;
if ( V_36 -> V_303 . V_191 )
F_80 ( & V_36 -> V_303 ) ;
}
static unsigned char F_141 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_218 ;
V_218 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_218 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_142 ( const struct V_1 * V_2 , bool V_309 ,
unsigned int * V_59 )
{
struct V_1 V_130 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_310 = * V_59 ;
T_2 V_44 ;
int V_218 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_111 ( V_2 -> V_22 -> V_116 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_309 ? V_311 : V_312 ) ;
V_44 ++ ;
while ( * V_59 < V_310 ) {
V_218 = F_16 ( & V_130 , V_44 ) ;
if ( V_218 || F_8 ( & V_130 ) != V_61 )
break;
F_111 ( V_130 . V_22 -> V_116 , F_2 ( & V_130 ) -> V_17 ) ;
F_1 ( & V_130 , true , V_312 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_143 ( struct V_74 * V_75 , T_2 V_313 ,
T_4 V_314 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 , * V_315 = NULL ;
V_2 . V_22 = F_27 ( V_75 , V_313 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_144 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_313 ) ;
return NULL ;
}
F_16 ( & V_2 , V_313 ) ;
while ( V_314 -- ) {
V_10 = F_2 ( & V_2 ) ;
if ( V_10 != V_315 ) {
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_145 ( V_10 -> V_17 -> V_68 ,
V_100 | V_316 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 ,
V_10 -> V_12 ) ;
}
F_111 ( V_2 . V_22 -> V_116 , V_10 -> V_17 ) ;
V_315 = V_10 ;
}
F_1 ( & V_2 , false , V_4 ) ;
F_18 ( & V_2 ) ;
}
return V_2 . V_22 ;
}
void F_146 ( struct V_103 * V_104 , const struct V_114 * V_115 )
{
struct V_69 * V_22 = V_115 -> V_118 ;
struct V_35 * V_317 ;
const struct V_84 * V_59 ;
if ( V_22 == NULL )
return;
F_45 ( V_104 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_149 ,
V_22 -> V_79 , V_22 -> V_187 , V_22 -> V_80 ,
V_22 -> V_108 , V_22 -> V_109 ) ;
F_28 ( & V_22 -> V_112 ) ;
for ( V_59 = F_32 ( & V_22 -> V_107 ) ; V_59 ; V_59 = F_34 ( & V_317 -> V_102 ) ) {
V_317 = F_29 ( V_59 , struct V_35 , V_102 ) ;
F_44 ( V_104 , V_317 ) ;
}
F_30 ( & V_22 -> V_112 ) ;
}
static void F_147 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_102 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_102 ( V_75 , L_18 ) ;
F_146 ( NULL , V_22 -> V_116 ) ;
V_22 -> V_149 |= V_306 ;
}
static void F_148 ( struct V_92 * V_93 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_93 -> V_98 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_318 ;
T_2 V_44 ;
int V_218 ;
F_28 ( & V_22 -> V_112 ) ;
if ( F_47 ( V_36 ) ) {
if ( F_149 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_218 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_318 = F_150 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_318 ;
V_22 -> V_108 -= V_318 ;
F_48 ( V_36 , V_319 ) ;
if ( V_36 -> V_39 && ! V_218 )
goto V_67;
F_151 ( V_320 , & V_36 -> V_239 ) ;
}
F_46 ( V_36 ) ;
}
V_67:
F_30 ( & V_22 -> V_112 ) ;
}
static void F_152 ( struct V_1 * V_2 ,
const struct V_92 * V_93 , bool V_309 )
{
T_2 V_41 ;
if ( F_47 ( V_93 -> V_98 ) ) {
* V_2 = V_93 -> V_98 -> V_38 ;
return;
}
if ( ! V_309 && F_26 ( V_2 -> V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_2 -> V_22 -> V_242 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_153 ( struct V_92 * V_93 , T_2 * V_321 , unsigned int * V_322 ,
bool V_309 , T_2 * V_323 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_194 * V_324 ;
struct V_1 V_2 = { . V_22 = V_93 -> V_298 , } ;
unsigned int V_325 ;
T_2 V_44 ;
int error ;
F_152 ( & V_2 , V_93 , V_309 ) ;
error = F_118 ( & V_2 , V_61 , NULL , V_93 , false , NULL ) ;
if ( error == - V_257 ) {
F_152 ( & V_2 , V_93 , V_309 ) ;
error = F_118 ( & V_2 , V_61 , NULL , NULL , false ,
NULL ) ;
}
if ( error ) {
F_102 ( V_75 , L_19 ,
( unsigned long long ) V_93 -> V_96 , error , * V_322 ,
F_121 ( V_110 , & V_2 . V_22 -> V_78 -> V_111 ) ,
V_2 . V_22 -> V_109 ) ;
goto V_326;
}
F_142 ( & V_2 , V_309 , V_322 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_242 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_47 ( V_93 -> V_98 ) )
F_148 ( V_93 , & V_2 , * V_322 ) ;
V_325 = * V_322 ;
if ( V_309 )
V_325 -- ;
if ( ! V_309 ) {
V_93 -> V_95 = V_44 + V_325 - 1 ;
error = F_154 ( V_93 , & V_324 ) ;
if ( error == 0 ) {
struct V_327 * V_328 =
(struct V_327 * ) V_324 -> V_18 ;
F_111 ( V_93 -> V_158 , V_324 ) ;
V_328 -> V_329 = V_328 -> V_330 =
F_84 ( V_93 -> V_95 ) ;
F_95 ( V_324 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_322 ) {
F_5 ( L_20 , * V_322 ) ;
goto V_326;
}
V_2 . V_22 -> V_79 -= * V_322 ;
if ( V_309 ) {
V_2 . V_22 -> V_80 ++ ;
* V_323 = V_2 . V_22 -> V_168 ++ ;
if ( * V_323 == 0 )
* V_323 = V_2 . V_22 -> V_168 ++ ;
}
F_111 ( V_2 . V_22 -> V_116 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_82 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_86 ( V_2 . V_22 -> V_145 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_155 ( V_75 , 0 , - ( T_9 ) * V_322 , V_309 ? 1 : 0 ) ;
if ( V_309 )
F_156 ( V_75 , V_44 , * V_322 ) ;
F_157 ( V_93 , * V_322 , V_93 -> V_94 . V_331 , V_93 -> V_94 . V_332 ) ;
V_2 . V_22 -> V_187 -= * V_322 ;
F_158 ( V_93 , V_2 . V_22 , V_44 , * V_322 ,
V_309 ? V_311 : V_312 ) ;
* V_321 = V_44 ;
return 0 ;
V_326:
F_147 ( V_2 . V_22 ) ;
return - V_124 ;
}
void F_159 ( struct V_92 * V_93 , T_2 V_313 , T_4 V_314 , int V_333 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
V_22 = F_143 ( V_75 , V_313 , V_314 , V_61 ) ;
if ( ! V_22 )
return;
F_158 ( V_93 , V_22 , V_313 , V_314 , V_61 ) ;
V_22 -> V_79 += V_314 ;
V_22 -> V_149 &= ~ V_229 ;
F_111 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_82 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_86 ( V_22 -> V_145 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_333 || V_93 -> V_334 )
F_160 ( V_93 , V_313 , V_314 ) ;
}
void F_161 ( struct V_92 * V_93 , T_2 V_313 , T_4 V_314 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
F_159 ( V_93 , V_313 , V_314 , 1 ) ;
F_155 ( V_75 , 0 , + V_314 , 0 ) ;
F_157 ( V_93 , - ( T_9 ) V_314 , V_93 -> V_94 . V_331 , V_93 -> V_94 . V_332 ) ;
}
void F_162 ( struct V_126 * V_126 )
{
struct V_92 * V_93 = F_64 ( V_126 ) ;
struct V_74 * V_75 = F_36 ( V_126 ) ;
struct V_69 * V_22 ;
T_2 V_335 = V_93 -> V_96 ;
V_22 = F_143 ( V_75 , V_335 , 1 , V_182 ) ;
if ( ! V_22 )
return;
F_158 ( V_93 , V_22 , V_335 , 1 , V_182 ) ;
F_111 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_82 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_86 ( V_22 -> V_145 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_87 ( V_22 , 1 ) ;
}
static void F_163 ( struct V_69 * V_22 , T_2 V_335 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_336 ;
V_336 = F_143 ( V_75 , V_335 , 1 , V_61 ) ;
if ( ! V_336 )
return;
F_164 ( V_75 , V_22 == V_336 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_111 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_82 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_86 ( V_22 -> V_145 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_87 ( V_22 , - 1 ) ;
F_155 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_165 ( struct V_69 * V_22 , struct V_92 * V_93 )
{
F_163 ( V_22 , V_93 -> V_96 ) ;
F_158 ( V_93 , V_22 , V_93 -> V_96 , 1 , V_61 ) ;
F_157 ( V_93 , - 1 , V_93 -> V_94 . V_331 , V_93 -> V_94 . V_332 ) ;
F_160 ( V_93 , V_93 -> V_96 , 1 ) ;
}
int F_166 ( struct V_74 * V_75 , T_2 V_337 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_159 V_338 ;
int error = - V_48 ;
V_22 = F_27 ( V_75 , V_337 , 1 ) ;
if ( ! V_22 )
goto V_141;
error = F_79 ( V_22 -> V_116 , V_162 , 0 , & V_338 ) ;
if ( error )
goto V_141;
if ( F_141 ( V_22 , V_337 ) != type )
error = - V_339 ;
F_80 ( & V_338 ) ;
V_141:
return error ;
}
void F_167 ( struct V_92 * V_93 , struct V_340 * V_341 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_342 ;
unsigned int V_77 ;
if ( F_96 ( V_75 , ! V_341 -> V_343 ) )
return;
if ( V_93 -> V_298 && F_26 ( V_93 -> V_298 , V_44 ) )
V_22 = V_93 -> V_298 ;
else
V_22 = F_27 ( V_75 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_25 ( V_75 , L_21 , ( unsigned long long ) V_44 ) ;
return;
}
V_93 -> V_298 = V_22 ;
for ( V_77 = 0 ; V_77 < V_341 -> V_344 ; V_77 ++ )
if ( V_341 -> V_345 [ V_77 ] == V_22 )
return;
if ( V_341 -> V_344 == V_341 -> V_346 ) {
V_342 = V_341 -> V_346 + 10 ;
V_31 = F_62 ( V_342 , sizeof( struct V_69 * ) ,
V_100 | V_316 ) ;
if ( V_341 -> V_345 ) {
memcpy ( V_31 , V_341 -> V_345 ,
V_341 -> V_346 * sizeof( struct V_69 * ) ) ;
F_38 ( V_341 -> V_345 ) ;
}
V_341 -> V_346 = V_342 ;
V_341 -> V_345 = V_31 ;
}
V_341 -> V_345 [ V_341 -> V_344 ++ ] = V_22 ;
}
void F_168 ( struct V_340 * V_341 , unsigned int V_30 )
{
unsigned int V_77 ;
V_341 -> V_343 = F_62 ( V_341 -> V_344 , sizeof( struct V_159 ) ,
V_100 | V_316 ) ;
for ( V_77 = 0 ; V_77 < V_341 -> V_344 ; V_77 ++ )
F_169 ( V_341 -> V_345 [ V_77 ] -> V_116 ,
V_30 , 0 ,
& V_341 -> V_343 [ V_77 ] ) ;
}
void F_170 ( struct V_340 * V_341 )
{
unsigned int V_77 ;
F_38 ( V_341 -> V_345 ) ;
if ( V_341 -> V_343 ) {
for ( V_77 = 0 ; V_77 < V_341 -> V_344 ; V_77 ++ )
F_171 ( & V_341 -> V_343 [ V_77 ] ) ;
F_38 ( V_341 -> V_343 ) ;
V_341 -> V_343 = NULL ;
}
}
