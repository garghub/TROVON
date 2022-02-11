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
void F_35 ( struct V_69 * V_22 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
F_36 ( V_10 -> V_25 ) ;
V_10 -> V_25 = NULL ;
}
}
int F_37 ( struct V_92 * V_93 )
{
int error = 0 ;
F_38 ( & V_93 -> V_94 ) ;
if ( V_93 -> V_95 )
goto V_67;
V_93 -> V_95 = F_39 ( V_96 , V_97 ) ;
if ( ! V_93 -> V_95 ) {
error = - V_98 ;
goto V_67;
}
F_40 ( & V_93 -> V_95 -> V_99 ) ;
V_67:
F_41 ( & V_93 -> V_94 ) ;
return error ;
}
static void F_42 ( struct V_100 * V_101 , const struct V_35 * V_36 )
{
F_43 ( V_101 , L_7 ,
( unsigned long long ) V_36 -> V_102 ,
( unsigned long long ) F_12 ( & V_36 -> V_38 ) ,
V_36 -> V_38 . V_14 , V_36 -> V_39 ) ;
}
static void F_44 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
if ( ! F_45 ( V_36 ) )
return;
V_22 = V_36 -> V_38 . V_22 ;
F_46 ( V_36 , V_103 ) ;
F_47 ( & V_36 -> V_99 , & V_22 -> V_104 ) ;
F_40 ( & V_36 -> V_99 ) ;
if ( V_36 -> V_39 ) {
struct V_9 * V_10 = F_2 ( & V_36 -> V_38 ) ;
F_3 ( V_36 -> V_38 . V_22 -> V_105 < V_36 -> V_39 ) ;
V_36 -> V_38 . V_22 -> V_105 -= V_36 -> V_39 ;
V_22 -> V_106 += V_36 -> V_39 ;
V_36 -> V_39 = 0 ;
F_48 ( V_107 , & V_10 -> V_108 ) ;
}
}
void F_49 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_28 ( & V_22 -> V_109 ) ;
F_44 ( V_36 ) ;
F_30 ( & V_22 -> V_109 ) ;
}
}
void F_50 ( struct V_92 * V_93 , T_5 * V_110 )
{
F_38 ( & V_93 -> V_94 ) ;
if ( V_93 -> V_95 && ( ( V_110 == NULL ) || ( F_51 ( V_110 ) <= 1 ) ) ) {
F_49 ( V_93 -> V_95 ) ;
F_3 ( V_93 -> V_95 -> V_39 ) ;
F_52 ( V_96 , V_93 -> V_95 ) ;
V_93 -> V_95 = NULL ;
}
F_41 ( & V_93 -> V_94 ) ;
}
static void F_53 ( struct V_69 * V_22 )
{
struct V_84 * V_59 ;
struct V_35 * V_36 ;
F_28 ( & V_22 -> V_109 ) ;
while ( ( V_59 = F_32 ( & V_22 -> V_104 ) ) ) {
V_36 = F_29 ( V_59 , struct V_35 , V_99 ) ;
F_44 ( V_36 ) ;
}
F_30 ( & V_22 -> V_109 ) ;
}
void F_54 ( struct V_74 * V_75 )
{
struct V_84 * V_59 ;
struct V_69 * V_22 ;
struct V_111 * V_112 ;
while ( ( V_59 = F_32 ( & V_75 -> V_88 ) ) ) {
V_22 = F_29 ( V_59 , struct V_69 , V_89 ) ;
V_112 = V_22 -> V_113 ;
F_47 ( V_59 , & V_75 -> V_88 ) ;
if ( V_112 ) {
F_28 ( & V_112 -> V_114 ) ;
V_112 -> V_115 = NULL ;
F_30 ( & V_112 -> V_114 ) ;
F_55 ( V_112 ) ;
F_56 ( V_112 ) ;
}
F_35 ( V_22 ) ;
F_36 ( V_22 -> V_78 ) ;
F_53 ( V_22 ) ;
F_52 ( V_116 , V_22 ) ;
}
}
static void F_57 ( const struct V_69 * V_22 )
{
F_58 ( L_8 , ( unsigned long long ) V_22 -> V_23 ) ;
F_58 ( L_9 , V_22 -> V_57 ) ;
F_58 ( L_10 , ( unsigned long long ) V_22 -> V_46 ) ;
F_58 ( L_11 , V_22 -> V_49 ) ;
F_58 ( L_12 , V_22 -> V_117 ) ;
}
static int F_59 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_118 , V_64 ;
int V_77 ;
if ( ! V_76 )
return - V_48 ;
V_22 -> V_78 = F_60 ( V_76 , sizeof( struct V_9 ) , V_97 ) ;
if ( ! V_22 -> V_78 )
return - V_98 ;
V_118 = V_22 -> V_117 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
V_10 -> V_108 = 0 ;
if ( V_76 == 1 ) {
V_64 = V_118 ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 == 0 ) {
V_64 = V_75 -> V_119 . V_120 - sizeof( struct V_53 ) ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 + 1 == V_76 ) {
V_64 = V_118 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_117 - V_118 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else {
V_64 = V_75 -> V_119 . V_120 -
sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_117 - V_118 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
}
V_118 -= V_64 ;
}
if ( V_118 ) {
F_7 ( V_22 ) ;
return - V_121 ;
}
V_10 = V_22 -> V_78 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_12 ) * V_15 != V_22 -> V_49 ) {
if ( F_7 ( V_22 ) ) {
F_57 ( V_22 ) ;
F_25 ( V_75 , L_13 ,
V_10 -> V_24 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_121 ;
}
return 0 ;
}
T_2 F_61 ( struct V_74 * V_75 )
{
T_2 V_122 = 0 ;
struct V_123 * V_123 = V_75 -> V_124 ;
struct V_92 * V_93 = F_62 ( V_123 ) ;
char V_40 [ sizeof( struct V_125 ) ] ;
int error , V_126 ;
for ( V_126 = 0 ; ; V_126 ++ ) {
T_6 V_127 = V_126 * sizeof( struct V_125 ) ;
if ( V_127 + sizeof( struct V_125 ) > F_63 ( V_123 ) )
break;
error = F_64 ( V_93 , V_40 , & V_127 ,
sizeof( struct V_125 ) ) ;
if ( error != sizeof( struct V_125 ) )
break;
V_122 += F_65 ( ( (struct V_125 * ) V_40 ) -> V_128 ) ;
}
return V_122 ;
}
static int F_66 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_84 * * V_129 = & V_75 -> V_88 . V_84 , * V_130 = NULL ;
while ( * V_129 ) {
struct V_69 * V_86 = F_29 ( * V_129 , struct V_69 ,
V_89 ) ;
V_130 = * V_129 ;
if ( V_22 -> V_23 < V_86 -> V_23 )
V_129 = & ( ( * V_129 ) -> V_90 ) ;
else if ( V_22 -> V_23 > V_86 -> V_23 )
V_129 = & ( ( * V_129 ) -> V_91 ) ;
else
return - V_131 ;
}
F_67 ( & V_22 -> V_89 , V_130 , V_129 ) ;
F_68 ( & V_22 -> V_89 , & V_75 -> V_88 ) ;
V_75 -> V_132 ++ ;
return 0 ;
}
static int F_69 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
const unsigned V_134 = V_75 -> V_119 . V_120 ;
T_6 V_127 = V_75 -> V_132 * sizeof( struct V_125 ) ;
struct V_125 V_40 ;
int error ;
struct V_69 * V_22 ;
if ( V_127 >= F_63 ( & V_93 -> V_133 ) )
return 1 ;
error = F_64 ( V_93 , ( char * ) & V_40 , & V_127 ,
sizeof( struct V_125 ) ) ;
if ( error != sizeof( struct V_125 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_39 ( V_116 , V_97 ) ;
error = - V_98 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_75 ;
V_22 -> V_23 = F_71 ( V_40 . V_135 ) ;
V_22 -> V_57 = F_65 ( V_40 . V_136 ) ;
V_22 -> V_46 = F_71 ( V_40 . V_137 ) ;
V_22 -> V_49 = F_65 ( V_40 . V_128 ) ;
V_22 -> V_117 = F_65 ( V_40 . V_138 ) ;
F_72 ( & V_22 -> V_109 ) ;
error = F_59 ( V_22 ) ;
if ( error )
goto V_139;
error = F_73 ( V_75 , V_22 -> V_23 ,
& V_140 , V_141 , & V_22 -> V_113 ) ;
if ( error )
goto V_139;
V_22 -> V_113 -> V_115 = V_22 ;
V_22 -> V_113 -> V_142 . V_66 = V_22 -> V_23 * V_134 ;
V_22 -> V_113 -> V_142 . V_7 = V_22 -> V_113 -> V_142 . V_66 + ( V_22 -> V_57 * V_134 ) - 1 ;
V_22 -> V_143 = (struct V_144 * ) V_22 -> V_113 -> V_145 . V_146 ;
V_22 -> V_147 &= ~ V_148 ;
if ( V_22 -> V_49 > V_75 -> V_149 )
V_75 -> V_149 = V_22 -> V_49 ;
F_28 ( & V_75 -> V_87 ) ;
error = F_66 ( V_22 ) ;
F_30 ( & V_75 -> V_87 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_56 ( V_22 -> V_113 ) ;
V_139:
F_36 ( V_22 -> V_78 ) ;
F_52 ( V_116 , V_22 ) ;
return error ;
}
static int F_74 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
int error ;
do {
error = F_69 ( V_93 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_75 -> V_150 = 1 ;
return 0 ;
}
int F_75 ( struct V_74 * V_75 )
{
struct V_92 * V_93 = F_62 ( V_75 -> V_124 ) ;
struct V_111 * V_112 = V_93 -> V_151 ;
struct V_152 V_153 ;
int error = 0 ;
int V_154 = 0 ;
if ( ! V_75 -> V_150 ) {
if ( ! F_76 ( V_112 ) ) {
error = F_77 ( V_112 , V_155 , 0 , & V_153 ) ;
if ( error )
return error ;
V_154 = 1 ;
}
if ( ! V_75 -> V_150 )
error = F_74 ( V_93 ) ;
if ( V_154 )
F_78 ( & V_153 ) ;
}
return error ;
}
static void F_79 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_156 = V_40 ;
T_4 V_157 ;
V_157 = F_65 ( V_156 -> V_157 ) ;
V_157 &= ~ V_158 ;
V_22 -> V_147 &= V_158 ;
V_22 -> V_147 |= V_157 ;
V_22 -> V_79 = F_65 ( V_156 -> V_159 ) ;
V_22 -> V_80 = F_65 ( V_156 -> V_160 ) ;
V_22 -> V_161 = F_71 ( V_156 -> V_162 ) ;
}
static void F_80 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_156 = V_40 ;
V_156 -> V_157 = F_81 ( V_22 -> V_147 & ~ V_158 ) ;
V_156 -> V_159 = F_81 ( V_22 -> V_79 ) ;
V_156 -> V_160 = F_81 ( V_22 -> V_80 ) ;
V_156 -> V_163 = F_81 ( 0 ) ;
V_156 -> V_162 = F_82 ( V_22 -> V_161 ) ;
memset ( & V_156 -> V_164 , 0 , sizeof( V_156 -> V_164 ) ) ;
}
static int F_83 ( struct V_69 * V_22 )
{
struct V_144 * V_165 = V_22 -> V_143 ;
struct V_53 * V_156 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_165 -> V_166 != V_156 -> V_157 || V_165 -> V_167 != V_156 -> V_159 ||
V_165 -> V_168 != V_156 -> V_160 ||
V_165 -> V_169 != V_156 -> V_162 )
return 0 ;
return 1 ;
}
static void F_84 ( struct V_144 * V_165 , const void * V_40 )
{
const struct V_53 * V_156 = V_40 ;
V_165 -> V_170 = F_81 ( V_171 ) ;
V_165 -> V_166 = V_156 -> V_157 ;
V_165 -> V_167 = V_156 -> V_159 ;
V_165 -> V_168 = V_156 -> V_160 ;
V_165 -> V_169 = V_156 -> V_162 ;
V_165 -> V_163 = 0UL ;
}
static void F_85 ( struct V_69 * V_22 , T_4 V_172 )
{
struct V_144 * V_165 = V_22 -> V_143 ;
T_4 V_173 = F_65 ( V_165 -> V_174 ) + V_172 ;
V_165 -> V_174 = F_81 ( V_173 ) ;
}
static T_4 F_86 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_175 , V_41 , V_73 = 0 ;
for ( V_175 = 0 , V_10 = V_22 -> V_78 ; V_175 < V_76 ; V_175 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_87 ( ! F_88 ( V_10 -> V_17 ) ) ;
while ( V_41 < V_10 -> V_12 * V_15 ) {
V_41 = F_13 ( V_26 , V_10 -> V_12 , V_41 ,
V_176 ) ;
if ( V_41 == V_43 )
break;
V_73 ++ ;
V_41 ++ ;
}
}
return V_73 ;
}
static int F_89 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_111 * V_112 = V_22 -> V_113 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_177 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_90 ( V_112 , V_22 -> V_23 + V_77 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_139;
}
for ( V_177 = V_76 ; V_177 -- ; ) {
V_10 = V_22 -> V_78 + V_177 ;
error = F_91 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_139;
if ( F_92 ( V_75 , V_10 -> V_17 , V_177 ? V_178 :
V_179 ) ) {
error = - V_121 ;
goto V_139;
}
}
if ( ! ( V_22 -> V_147 & V_148 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_48 ( V_107 , & V_22 -> V_78 [ V_77 ] . V_108 ) ;
F_79 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_147 |= ( V_148 | V_180 ) ;
V_22 -> V_181 = V_22 -> V_79 ;
V_22 -> V_106 = V_22 -> V_79 ;
}
if ( F_81 ( V_171 ) != V_22 -> V_143 -> V_170 ) {
V_22 -> V_143 -> V_174 = F_81 ( F_86 ( V_22 ) ) ;
F_84 ( V_22 -> V_143 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_182 . V_183 ) {
if ( ! F_83 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_121 ;
goto V_139;
}
if ( V_22 -> V_143 -> V_174 == 0 )
V_22 -> V_147 &= ~ V_180 ;
}
return 0 ;
V_139:
while ( V_77 -- ) {
V_10 = V_22 -> V_78 + V_77 ;
F_93 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_94 ( V_75 , ! V_10 -> V_25 ) ;
}
return error ;
}
static int F_95 ( struct V_69 * V_22 )
{
T_4 V_166 ;
if ( V_22 -> V_147 & V_148 )
return 0 ;
if ( F_81 ( V_171 ) != V_22 -> V_143 -> V_170 )
return F_89 ( V_22 ) ;
V_166 = F_65 ( V_22 -> V_143 -> V_166 ) ;
V_166 &= ~ V_158 ;
V_22 -> V_147 &= V_158 ;
V_22 -> V_147 |= ( V_166 | V_148 | V_180 ) ;
if ( V_22 -> V_143 -> V_174 == 0 )
V_22 -> V_147 &= ~ V_180 ;
V_22 -> V_79 = F_65 ( V_22 -> V_143 -> V_167 ) ;
V_22 -> V_181 = V_22 -> V_79 ;
V_22 -> V_80 = F_65 ( V_22 -> V_143 -> V_168 ) ;
V_22 -> V_161 = F_71 ( V_22 -> V_143 -> V_169 ) ;
return 0 ;
}
int F_96 ( struct V_152 * V_184 )
{
struct V_69 * V_22 = V_184 -> V_185 -> V_115 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_184 -> V_186 & V_187 && V_75 -> V_182 . V_183 )
return 0 ;
return F_89 ( V_22 ) ;
}
void F_97 ( struct V_152 * V_184 )
{
struct V_69 * V_22 = V_184 -> V_185 -> V_115 ;
int V_77 , V_76 = V_22 -> V_57 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
if ( V_10 -> V_17 ) {
F_93 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
int F_98 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_188 * V_189 ,
const struct V_9 * V_10 , unsigned V_190 , T_2 * V_191 )
{
struct V_192 * V_193 = V_75 -> V_194 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_195 = 0 ;
int V_196 ;
unsigned int V_77 ;
T_4 V_197 = 0 ;
T_1 V_198 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_199 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_199 += V_10 -> V_19 ;
V_199 += V_77 ;
if ( V_189 ) {
const T_1 * V_200 = V_189 -> V_18 + V_10 -> V_19 + V_77 ;
V_198 = ~ ( * V_200 | ( * V_200 >> 1 ) ) & ( * V_199 | ( * V_199 >> 1 ) ) ;
} else {
V_198 = ~ ( * V_199 | ( * V_199 >> 1 ) ) ;
}
V_198 &= 0x55 ;
if ( V_198 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_198 ) {
if ( V_198 & 1 ) {
if ( V_195 == 0 )
goto V_201;
if ( ( V_66 + V_195 ) != V_33 ) {
if ( V_195 >= V_190 ) {
V_196 = F_99 ( V_193 ,
V_66 , V_195 ,
V_97 , 0 ) ;
if ( V_196 )
goto V_139;
V_197 += V_195 ;
}
V_195 = 0 ;
V_201:
V_66 = V_33 ;
}
V_195 ++ ;
}
V_198 >>= 2 ;
V_33 ++ ;
}
}
if ( V_195 >= V_190 ) {
V_196 = F_99 ( V_193 , V_66 , V_195 , V_97 , 0 ) ;
if ( V_196 )
goto V_139;
V_197 += V_195 ;
}
if ( V_191 )
* V_191 = V_197 ;
return 0 ;
V_139:
if ( V_75 -> V_182 . V_202 )
F_100 ( V_75 , L_14 , V_196 ) ;
V_75 -> V_182 . V_202 = 0 ;
return - V_121 ;
}
int F_101 ( struct V_203 * V_204 , void T_8 * V_205 )
{
struct V_123 * V_123 = F_102 ( V_204 ) ;
struct V_74 * V_75 = F_70 ( V_123 ) ;
struct V_206 * V_207 = F_103 ( V_75 -> V_194 -> V_208 ) ;
struct V_188 * V_189 ;
struct V_69 * V_22 ;
struct V_69 * V_209 ;
struct V_152 V_184 ;
struct V_210 V_211 ;
int V_212 = 0 ;
T_2 V_213 ;
T_2 V_197 = 0 ;
T_2 V_66 , V_7 , V_190 ;
unsigned int V_77 ;
unsigned V_214 = V_75 -> V_119 . V_215 ;
if ( ! F_104 ( V_216 ) )
return - V_217 ;
if ( ! F_105 ( V_207 ) )
return - V_218 ;
if ( F_106 ( & V_211 , V_205 , sizeof( V_211 ) ) )
return - V_219 ;
V_212 = F_75 ( V_75 ) ;
if ( V_212 )
return V_212 ;
V_66 = V_211 . V_66 >> V_214 ;
V_7 = V_66 + ( V_211 . V_34 >> V_214 ) ;
V_190 = F_107 ( T_2 , V_211 . V_190 ,
V_207 -> V_220 . V_221 ) >> V_214 ;
if ( V_7 <= V_66 || V_190 > V_75 -> V_149 )
return - V_48 ;
V_22 = F_27 ( V_75 , V_66 , 0 ) ;
V_209 = F_27 ( V_75 , V_7 , 0 ) ;
if ( ( F_31 ( V_75 ) == F_33 ( V_209 ) )
&& ( V_66 > V_209 -> V_46 + V_209 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_212 = F_77 ( V_22 -> V_113 , V_222 , 0 , & V_184 ) ;
if ( V_212 )
goto V_67;
if ( ! ( V_22 -> V_147 & V_223 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_212 = F_98 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_190 ,
& V_213 ) ;
if ( V_212 ) {
F_78 ( & V_184 ) ;
goto V_67;
}
V_197 += V_213 ;
}
V_212 = F_108 ( V_75 , V_224 , 0 ) ;
if ( V_212 == 0 ) {
V_189 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_147 |= V_223 ;
F_109 ( V_22 -> V_113 , V_189 ) ;
F_80 ( V_22 , V_189 -> V_18 ) ;
F_84 ( V_22 -> V_143 , V_189 -> V_18 ) ;
F_110 ( V_75 ) ;
}
}
F_78 ( & V_184 ) ;
if ( V_22 == V_209 )
break;
V_22 = F_33 ( V_22 ) ;
}
V_67:
V_211 . V_34 = V_197 << V_214 ;
if ( F_111 ( V_205 , & V_211 , sizeof( V_211 ) ) )
return - V_219 ;
return V_212 ;
}
static void F_112 ( struct V_92 * V_93 )
{
struct V_84 * * V_129 , * V_130 = NULL ;
int V_225 ;
struct V_35 * V_36 = V_93 -> V_95 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_226 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_45 ( V_36 ) ) ;
F_28 ( & V_22 -> V_109 ) ;
V_129 = & V_22 -> V_104 . V_84 ;
while ( * V_129 ) {
struct V_35 * V_86 =
F_29 ( * V_129 , struct V_35 , V_99 ) ;
V_130 = * V_129 ;
V_225 = F_11 ( V_226 , V_36 -> V_39 , V_86 ) ;
if ( V_225 > 0 )
V_129 = & ( ( * V_129 ) -> V_91 ) ;
else if ( V_225 < 0 )
V_129 = & ( ( * V_129 ) -> V_90 ) ;
else {
F_30 ( & V_22 -> V_109 ) ;
F_87 ( 1 ) ;
return;
}
}
F_67 ( & V_36 -> V_99 , V_130 , V_129 ) ;
F_68 ( & V_36 -> V_99 , & V_22 -> V_104 ) ;
V_22 -> V_105 += V_36 -> V_39 ;
F_30 ( & V_22 -> V_109 ) ;
F_46 ( V_36 , V_227 ) ;
}
static void F_113 ( struct V_69 * V_22 , struct V_92 * V_93 ,
const struct V_228 * V_229 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_93 -> V_95 ;
T_4 V_230 ;
T_4 V_231 = V_22 -> V_181 - V_22 -> V_105 ;
int V_212 ;
struct V_123 * V_123 = & V_93 -> V_133 ;
if ( F_114 ( V_123 -> V_232 ) )
V_230 = 1 ;
else {
V_230 = F_107 ( T_4 , F_51 ( & V_36 -> V_233 ) , V_229 -> V_234 ) ;
V_230 = F_115 ( V_230 , V_235 , V_231 ) ;
}
if ( ( V_22 -> V_181 < V_22 -> V_105 ) || ( V_231 < V_230 ) )
return;
if ( F_26 ( V_22 , V_93 -> V_236 ) )
V_41 = V_93 -> V_236 ;
else
V_41 = V_22 -> V_237 + V_22 -> V_46 ;
if ( F_87 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_212 = F_116 ( & V_2 , V_61 , & V_230 , V_93 , true , V_229 ) ;
if ( V_212 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_230 ;
V_36 -> V_102 = V_93 -> V_238 ;
F_112 ( V_93 ) ;
} else {
if ( V_41 == V_22 -> V_237 + V_22 -> V_46 )
V_22 -> V_237 = 0 ;
}
}
static T_2 F_117 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_92 * V_93 )
{
struct V_35 * V_36 ;
struct V_84 * V_59 ;
int V_225 ;
F_28 ( & V_22 -> V_109 ) ;
V_59 = V_22 -> V_104 . V_84 ;
while ( V_59 ) {
V_36 = F_29 ( V_59 , struct V_35 , V_99 ) ;
V_225 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_225 < 0 )
V_59 = V_59 -> V_90 ;
else if ( V_225 > 0 )
V_59 = V_59 -> V_91 ;
else
break;
}
if ( V_59 ) {
while ( ( F_11 ( V_44 , V_76 , V_36 ) == 0 ) && ( V_93 -> V_95 != V_36 ) ) {
V_44 = F_12 ( & V_36 -> V_38 ) + V_36 -> V_39 ;
V_59 = V_59 -> V_91 ;
if ( V_59 == NULL )
break;
V_36 = F_29 ( V_59 , struct V_35 , V_99 ) ;
}
}
F_30 ( & V_22 -> V_109 ) ;
return V_44 ;
}
static int F_118 ( struct V_1 * V_2 ,
const struct V_92 * V_93 ,
T_4 V_239 ,
struct V_240 * V_241 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_230 = 1 ;
T_2 V_242 ;
int V_212 ;
if ( V_239 ) {
V_230 = F_20 ( V_2 , V_239 ) ;
if ( V_230 <= V_241 -> V_34 )
goto V_139;
}
V_242 = F_117 ( V_2 -> V_22 , V_44 , V_230 , V_93 ) ;
if ( V_242 == V_44 ) {
if ( ! V_239 || V_230 >= V_239 )
return 0 ;
if ( V_230 > V_241 -> V_34 ) {
V_241 -> V_34 = V_230 ;
V_241 -> V_2 = * V_2 ;
}
V_139:
V_242 = V_44 + V_230 ;
}
V_212 = F_16 ( V_2 , V_242 ) ;
if ( V_212 < 0 )
return V_212 ;
return 1 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_239 ,
const struct V_92 * V_93 , bool V_243 ,
const struct V_228 * V_229 )
{
struct V_188 * V_189 ;
int V_244 ;
T_4 V_245 ;
int V_246 = V_2 -> V_51 ;
T_4 V_247 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_248 = V_2 -> V_22 -> V_57 ;
int V_212 ;
struct V_9 * V_10 ;
struct V_240 V_241 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_248 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_119 ( V_107 , & V_10 -> V_108 ) &&
( V_30 == V_61 ) )
goto V_249;
V_189 = V_10 -> V_17 ;
V_26 = V_189 -> V_18 + V_10 -> V_19 ;
F_87 ( ! F_88 ( V_189 ) ) ;
if ( V_30 != V_176 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_245 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_250;
V_2 -> V_14 = V_14 ;
if ( V_93 == NULL )
return 0 ;
V_244 = V_2 -> V_51 ;
V_212 = F_118 ( V_2 , V_93 ,
V_239 ? * V_239 : 0 ,
& V_241 ) ;
if ( V_212 == 0 )
return 0 ;
if ( V_212 > 0 ) {
V_59 += ( V_2 -> V_51 - V_244 ) ;
goto V_251;
}
if ( V_212 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_244 ) ;
goto V_252;
}
return V_212 ;
V_250:
if ( ( V_30 == V_61 ) && V_245 == 0 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_120 ( V_107 , & V_10 -> V_108 ) ;
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
( * V_239 < V_2 -> V_22 -> V_106 ) )
V_2 -> V_22 -> V_106 = * V_239 ;
if ( V_241 . V_34 ) {
* V_2 = V_241 . V_2 ;
* V_239 = V_241 . V_34 ;
return 0 ;
}
return - V_253 ;
}
static void F_121 ( struct V_69 * V_22 , T_2 * V_254 , T_2 V_255 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_111 * V_112 ;
struct V_92 * V_93 ;
int error ;
int V_256 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_38 ( & V_75 -> V_257 ) ;
error = F_116 ( & V_2 , V_176 , NULL , NULL ,
true , NULL ) ;
F_41 ( & V_75 -> V_257 ) ;
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
error = F_73 ( V_75 , V_44 , & V_259 , V_141 , & V_112 ) ;
if ( error )
continue;
V_93 = V_112 -> V_115 ;
if ( V_93 || F_122 ( V_260 , & V_112 -> V_261 ) == 0 )
F_56 ( V_112 ) ;
else
V_256 ++ ;
if ( V_256 > V_262 )
return;
}
V_22 -> V_147 &= ~ V_180 ;
return;
}
static bool F_123 ( const struct V_69 * V_22 , int V_263 )
{
const struct V_111 * V_112 = V_22 -> V_113 ;
const struct V_74 * V_75 = V_112 -> V_264 ;
struct V_265 * V_266 ;
T_9 V_267 , V_268 ;
T_9 V_269 , V_270 ;
T_9 V_271 ;
T_9 V_272 ;
T_9 V_273 ;
F_124 () ;
V_266 = & F_125 ( V_75 -> V_274 ) -> V_275 [ V_276 ] ;
V_269 = V_266 -> V_277 [ V_278 ] ;
V_267 = V_266 -> V_277 [ V_279 ] ;
V_273 = V_266 -> V_277 [ V_280 ] +
V_112 -> V_281 . V_277 [ V_280 ] ;
F_126 () ;
V_270 = V_112 -> V_281 . V_277 [ V_278 ] ;
V_268 = V_112 -> V_281 . V_277 [ V_279 ] ;
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
static bool F_127 ( const struct V_35 * V_36 ,
T_2 V_282 )
{
T_2 V_283 ;
V_283 = F_128 ( F_129 ( F_130 () ,
V_36 -> V_38 . V_22 -> V_113 -> V_284 ) ) ;
return V_283 > ( V_282 * 1000 * 1000 ) ;
}
static T_4 F_131 ( const struct V_92 * V_93 )
{
const struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
T_4 V_255 ;
F_132 ( & V_255 , sizeof( V_255 ) ) ;
return V_255 % V_75 -> V_132 ;
}
static bool F_133 ( struct V_69 * * V_127 , const struct V_69 * V_285 )
{
struct V_69 * V_22 = * V_127 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_33 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_31 ( V_75 ) ;
* V_127 = V_22 ;
if ( V_22 != V_285 )
return true ;
return false ;
}
int F_134 ( struct V_92 * V_93 , const struct V_228 * V_229 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
struct V_69 * V_285 = NULL ;
struct V_35 * V_36 = V_93 -> V_95 ;
int error = 0 , V_286 , V_287 = 0 ;
T_2 V_254 = V_258 ;
int V_263 = 0 ;
T_4 V_255 = 0 ;
if ( V_75 -> V_182 . V_183 )
V_287 |= V_187 ;
if ( F_94 ( V_75 , V_229 -> V_234 ) )
return - V_48 ;
if ( F_45 ( V_36 ) ) {
V_285 = V_36 -> V_38 . V_22 ;
} else if ( V_93 -> V_288 && F_26 ( V_93 -> V_288 , V_93 -> V_236 ) ) {
V_36 -> V_38 . V_22 = V_285 = V_93 -> V_288 ;
} else {
V_36 -> V_38 . V_22 = V_285 = F_27 ( V_75 , V_93 -> V_236 , 1 ) ;
}
if ( F_114 ( V_93 -> V_133 . V_232 ) && ( V_229 -> V_289 & V_290 ) )
V_255 = F_131 ( V_93 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_291 ;
while ( V_263 < 3 ) {
V_286 = 1 ;
if ( ! F_76 ( V_36 -> V_38 . V_22 -> V_113 ) ) {
V_286 = 0 ;
if ( V_255 && V_255 -- )
goto V_292;
if ( ! F_45 ( V_36 ) && ( V_263 < 2 ) &&
F_127 ( V_36 , 1000 ) &&
F_123 ( V_36 -> V_38 . V_22 , V_263 ) )
goto V_292;
error = F_77 ( V_36 -> V_38 . V_22 -> V_113 ,
V_222 , V_287 ,
& V_36 -> V_293 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_45 ( V_36 ) && ( V_263 < 2 ) &&
F_123 ( V_36 -> V_38 . V_22 , V_263 ) )
goto V_294;
if ( V_75 -> V_182 . V_183 ) {
error = F_95 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_78 ( & V_36 -> V_293 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_147 & ( V_295 |
V_296 ) ) ||
( V_229 -> V_234 > V_36 -> V_38 . V_22 -> V_106 ) )
goto V_294;
if ( V_75 -> V_182 . V_183 )
F_89 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_45 ( V_36 ) )
F_113 ( V_36 -> V_38 . V_22 , V_93 , V_229 ) ;
if ( ! F_45 ( V_36 ) && ( V_263 < 1 ) )
goto V_297;
if ( V_36 -> V_38 . V_22 -> V_181 >= V_229 -> V_234 ) {
V_93 -> V_288 = V_36 -> V_38 . V_22 ;
return 0 ;
}
V_297:
if ( V_36 -> V_38 . V_22 -> V_147 & V_180 )
F_121 ( V_36 -> V_38 . V_22 , & V_254 ,
V_93 -> V_238 ) ;
V_294:
if ( F_45 ( V_36 ) )
F_49 ( V_36 ) ;
if ( ! V_286 )
F_78 ( & V_36 -> V_293 ) ;
V_292:
if ( F_133 ( & V_36 -> V_38 . V_22 , V_285 ) )
continue;
if ( V_255 )
continue;
V_263 ++ ;
if ( V_93 == F_62 ( V_75 -> V_124 ) && ! V_75 -> V_150 ) {
error = F_74 ( V_93 ) ;
if ( error )
return error ;
}
if ( V_263 == 2 )
F_135 ( V_75 , NULL ) ;
}
return - V_253 ;
}
void F_136 ( struct V_92 * V_93 )
{
struct V_35 * V_36 = V_93 -> V_95 ;
if ( V_36 -> V_293 . V_185 )
F_78 ( & V_36 -> V_293 ) ;
}
static unsigned char F_137 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_212 ;
V_212 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_212 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_138 ( const struct V_1 * V_2 , bool V_298 ,
unsigned int * V_59 )
{
struct V_1 V_127 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_299 = * V_59 ;
T_2 V_44 ;
int V_212 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_109 ( V_2 -> V_22 -> V_113 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_298 ? V_300 : V_301 ) ;
V_44 ++ ;
while ( * V_59 < V_299 ) {
V_212 = F_16 ( & V_127 , V_44 ) ;
if ( V_212 || F_8 ( & V_127 ) != V_61 )
break;
F_109 ( V_127 . V_22 -> V_113 , F_2 ( & V_127 ) -> V_17 ) ;
F_1 ( & V_127 , true , V_301 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_139 ( struct V_74 * V_75 , T_2 V_302 ,
T_4 V_303 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 ;
V_2 . V_22 = F_27 ( V_75 , V_302 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_140 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_302 ) ;
return NULL ;
}
while ( V_303 -- ) {
F_16 ( & V_2 , V_302 ) ;
V_10 = F_2 ( & V_2 ) ;
V_302 ++ ;
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_141 ( V_10 -> V_17 -> V_68 ,
V_97 | V_304 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 , V_10 -> V_12 ) ;
}
F_109 ( V_2 . V_22 -> V_113 , V_10 -> V_17 ) ;
F_1 ( & V_2 , false , V_4 ) ;
}
return V_2 . V_22 ;
}
void F_142 ( struct V_100 * V_101 , const struct V_111 * V_112 )
{
struct V_69 * V_22 = V_112 -> V_115 ;
struct V_35 * V_305 ;
const struct V_84 * V_59 ;
if ( V_22 == NULL )
return;
F_43 ( V_101 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_147 ,
V_22 -> V_79 , V_22 -> V_181 , V_22 -> V_80 ,
V_22 -> V_105 , V_22 -> V_106 ) ;
F_28 ( & V_22 -> V_109 ) ;
for ( V_59 = F_32 ( & V_22 -> V_104 ) ; V_59 ; V_59 = F_34 ( & V_305 -> V_99 ) ) {
V_305 = F_29 ( V_59 , struct V_35 , V_99 ) ;
F_42 ( V_101 , V_305 ) ;
}
F_30 ( & V_22 -> V_109 ) ;
}
static void F_143 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_100 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_100 ( V_75 , L_18 ) ;
F_142 ( NULL , V_22 -> V_113 ) ;
V_22 -> V_147 |= V_296 ;
}
static void F_144 ( struct V_92 * V_93 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_93 -> V_95 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_306 ;
T_2 V_44 ;
int V_212 ;
F_28 ( & V_22 -> V_109 ) ;
if ( F_45 ( V_36 ) ) {
if ( F_145 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_212 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_306 = F_146 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_306 ;
V_22 -> V_105 -= V_306 ;
F_46 ( V_36 , V_307 ) ;
if ( V_36 -> V_39 && ! V_212 )
goto V_67;
}
F_44 ( V_36 ) ;
}
V_67:
F_30 ( & V_22 -> V_109 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
const struct V_92 * V_93 , bool V_298 )
{
T_2 V_41 ;
if ( F_45 ( V_93 -> V_95 ) ) {
* V_2 = V_93 -> V_95 -> V_38 ;
return;
}
if ( ! V_298 && F_26 ( V_2 -> V_22 , V_93 -> V_236 ) )
V_41 = V_93 -> V_236 ;
else
V_41 = V_2 -> V_22 -> V_237 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_148 ( struct V_92 * V_93 , T_2 * V_308 , unsigned int * V_309 ,
bool V_298 , T_2 * V_310 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
struct V_188 * V_311 ;
struct V_1 V_2 = { . V_22 = V_93 -> V_288 , } ;
unsigned int V_312 ;
T_2 V_44 ;
int error ;
F_147 ( & V_2 , V_93 , V_298 ) ;
error = F_116 ( & V_2 , V_61 , NULL , V_93 , false , NULL ) ;
if ( error == - V_253 ) {
F_147 ( & V_2 , V_93 , V_298 ) ;
error = F_116 ( & V_2 , V_61 , NULL , NULL , false ,
NULL ) ;
}
if ( error ) {
F_100 ( V_75 , L_19 ,
( unsigned long long ) V_93 -> V_238 , error , * V_309 ,
F_119 ( V_107 , & V_2 . V_22 -> V_78 -> V_108 ) ,
V_2 . V_22 -> V_106 ) ;
goto V_313;
}
F_138 ( & V_2 , V_298 , V_309 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_237 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_45 ( V_93 -> V_95 ) )
F_144 ( V_93 , & V_2 , * V_309 ) ;
V_312 = * V_309 ;
if ( V_298 )
V_312 -- ;
if ( ! V_298 ) {
V_93 -> V_236 = V_44 + V_312 - 1 ;
error = F_149 ( V_93 , & V_311 ) ;
if ( error == 0 ) {
struct V_314 * V_315 =
(struct V_314 * ) V_311 -> V_18 ;
F_109 ( V_93 -> V_151 , V_311 ) ;
V_315 -> V_316 = V_315 -> V_317 =
F_82 ( V_93 -> V_236 ) ;
F_93 ( V_311 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_309 ) {
F_5 ( L_20 , * V_309 ) ;
goto V_313;
}
V_2 . V_22 -> V_79 -= * V_309 ;
if ( V_298 ) {
V_2 . V_22 -> V_80 ++ ;
* V_310 = V_2 . V_22 -> V_161 ++ ;
if ( * V_310 == 0 )
* V_310 = V_2 . V_22 -> V_161 ++ ;
}
F_109 ( V_2 . V_22 -> V_113 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_80 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_2 . V_22 -> V_143 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_150 ( V_75 , 0 , - ( T_9 ) * V_309 , V_298 ? 1 : 0 ) ;
if ( V_298 )
F_151 ( V_75 , V_44 , * V_309 ) ;
F_152 ( V_93 , * V_309 , V_93 -> V_133 . V_318 , V_93 -> V_133 . V_319 ) ;
V_2 . V_22 -> V_181 -= * V_309 ;
F_153 ( V_93 , V_2 . V_22 , V_44 , * V_309 ,
V_298 ? V_300 : V_301 ) ;
* V_308 = V_44 ;
return 0 ;
V_313:
F_143 ( V_2 . V_22 ) ;
return - V_121 ;
}
void F_154 ( struct V_92 * V_93 , T_2 V_302 , T_4 V_303 , int V_320 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
struct V_69 * V_22 ;
V_22 = F_139 ( V_75 , V_302 , V_303 , V_61 ) ;
if ( ! V_22 )
return;
F_153 ( V_93 , V_22 , V_302 , V_303 , V_61 ) ;
V_22 -> V_79 += V_303 ;
V_22 -> V_147 &= ~ V_223 ;
F_109 ( V_22 -> V_113 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_80 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_22 -> V_143 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_320 || V_93 -> V_321 )
F_155 ( V_93 , V_302 , V_303 ) ;
}
void F_156 ( struct V_92 * V_93 , T_2 V_302 , T_4 V_303 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
F_154 ( V_93 , V_302 , V_303 , 1 ) ;
F_150 ( V_75 , 0 , + V_303 , 0 ) ;
F_152 ( V_93 , - ( T_9 ) V_303 , V_93 -> V_133 . V_318 , V_93 -> V_133 . V_319 ) ;
}
void F_157 ( struct V_123 * V_123 )
{
struct V_92 * V_93 = F_62 ( V_123 ) ;
struct V_74 * V_75 = F_70 ( V_123 ) ;
struct V_69 * V_22 ;
T_2 V_322 = V_93 -> V_238 ;
V_22 = F_139 ( V_75 , V_322 , 1 , V_176 ) ;
if ( ! V_22 )
return;
F_153 ( V_93 , V_22 , V_322 , 1 , V_176 ) ;
F_109 ( V_22 -> V_113 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_80 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_22 -> V_143 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_22 , 1 ) ;
}
static void F_158 ( struct V_69 * V_22 , T_2 V_322 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_323 ;
V_323 = F_139 ( V_75 , V_322 , 1 , V_61 ) ;
if ( ! V_323 )
return;
F_159 ( V_75 , V_22 == V_323 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_109 ( V_22 -> V_113 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_80 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_84 ( V_22 -> V_143 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_85 ( V_22 , - 1 ) ;
F_150 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_160 ( struct V_69 * V_22 , struct V_92 * V_93 )
{
F_158 ( V_22 , V_93 -> V_238 ) ;
F_153 ( V_93 , V_22 , V_93 -> V_238 , 1 , V_61 ) ;
F_152 ( V_93 , - 1 , V_93 -> V_133 . V_318 , V_93 -> V_133 . V_319 ) ;
F_155 ( V_93 , V_93 -> V_238 , 1 ) ;
}
int F_161 ( struct V_74 * V_75 , T_2 V_324 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_152 V_325 ;
int error = - V_48 ;
V_22 = F_27 ( V_75 , V_324 , 1 ) ;
if ( ! V_22 )
goto V_139;
error = F_77 ( V_22 -> V_113 , V_155 , 0 , & V_325 ) ;
if ( error )
goto V_139;
if ( F_137 ( V_22 , V_324 ) != type )
error = - V_326 ;
F_78 ( & V_325 ) ;
V_139:
return error ;
}
void F_162 ( struct V_92 * V_93 , struct V_327 * V_328 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_70 ( & V_93 -> V_133 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_329 ;
unsigned int V_77 ;
if ( F_94 ( V_75 , ! V_328 -> V_330 ) )
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
for ( V_77 = 0 ; V_77 < V_328 -> V_331 ; V_77 ++ )
if ( V_328 -> V_332 [ V_77 ] == V_22 )
return;
if ( V_328 -> V_331 == V_328 -> V_333 ) {
V_329 = V_328 -> V_333 + 10 ;
V_31 = F_60 ( V_329 , sizeof( struct V_69 * ) ,
V_97 | V_304 ) ;
if ( V_328 -> V_332 ) {
memcpy ( V_31 , V_328 -> V_332 ,
V_328 -> V_333 * sizeof( struct V_69 * ) ) ;
F_36 ( V_328 -> V_332 ) ;
}
V_328 -> V_333 = V_329 ;
V_328 -> V_332 = V_31 ;
}
V_328 -> V_332 [ V_328 -> V_331 ++ ] = V_22 ;
}
void F_163 ( struct V_327 * V_328 , unsigned int V_30 )
{
unsigned int V_77 ;
V_328 -> V_330 = F_60 ( V_328 -> V_331 , sizeof( struct V_152 ) ,
V_97 | V_304 ) ;
for ( V_77 = 0 ; V_77 < V_328 -> V_331 ; V_77 ++ )
F_164 ( V_328 -> V_332 [ V_77 ] -> V_113 ,
V_30 , 0 ,
& V_328 -> V_330 [ V_77 ] ) ;
}
void F_165 ( struct V_327 * V_328 )
{
unsigned int V_77 ;
F_36 ( V_328 -> V_332 ) ;
if ( V_328 -> V_330 ) {
for ( V_77 = 0 ; V_77 < V_328 -> V_331 ; V_77 ++ )
F_166 ( & V_328 -> V_330 [ V_77 ] ) ;
F_36 ( V_328 -> V_330 ) ;
V_328 -> V_330 = NULL ;
}
}
