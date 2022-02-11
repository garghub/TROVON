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
struct V_69 * F_26 ( struct V_74 * V_75 , T_2 V_33 , bool V_81 )
{
struct V_82 * V_59 , * V_83 ;
struct V_69 * V_84 ;
F_27 ( & V_75 -> V_85 ) ;
V_59 = V_75 -> V_86 . V_82 ;
while ( V_59 ) {
V_84 = F_28 ( V_59 , struct V_69 , V_87 ) ;
V_83 = NULL ;
if ( V_33 < V_84 -> V_23 )
V_83 = V_59 -> V_88 ;
else if ( V_33 >= V_84 -> V_46 + V_84 -> V_49 )
V_83 = V_59 -> V_89 ;
if ( V_83 == NULL ) {
F_29 ( & V_75 -> V_85 ) ;
if ( V_81 ) {
if ( V_33 < V_84 -> V_23 )
return NULL ;
if ( V_33 >= V_84 -> V_46 + V_84 -> V_49 )
return NULL ;
}
return V_84 ;
}
V_59 = V_83 ;
}
F_29 ( & V_75 -> V_85 ) ;
return NULL ;
}
struct V_69 * F_30 ( struct V_74 * V_75 )
{
const struct V_82 * V_59 ;
struct V_69 * V_22 ;
F_27 ( & V_75 -> V_85 ) ;
V_59 = F_31 ( & V_75 -> V_86 ) ;
V_22 = F_28 ( V_59 , struct V_69 , V_87 ) ;
F_29 ( & V_75 -> V_85 ) ;
return V_22 ;
}
struct V_69 * F_32 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
const struct V_82 * V_59 ;
F_27 ( & V_75 -> V_85 ) ;
V_59 = F_33 ( & V_22 -> V_87 ) ;
if ( V_59 == NULL )
V_59 = F_31 ( & V_75 -> V_86 ) ;
if ( F_4 ( & V_22 -> V_87 == V_59 ) ) {
F_29 ( & V_75 -> V_85 ) ;
return NULL ;
}
V_22 = F_28 ( V_59 , struct V_69 , V_87 ) ;
F_29 ( & V_75 -> V_85 ) ;
return V_22 ;
}
void F_34 ( struct V_90 * V_91 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
if ( ! V_91 -> V_93 || F_26 ( V_75 , V_91 -> V_93 , 1 ) == NULL )
V_91 -> V_93 = V_91 -> V_94 ;
}
void F_36 ( struct V_69 * V_22 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
F_37 ( V_10 -> V_25 ) ;
V_10 -> V_25 = NULL ;
}
}
int F_38 ( struct V_90 * V_91 )
{
return F_39 ( V_91 ) ;
}
static void F_40 ( struct V_95 * V_96 , const struct V_35 * V_36 )
{
F_41 ( V_96 , L_7 ,
( unsigned long long ) V_36 -> V_97 ,
( unsigned long long ) F_12 ( & V_36 -> V_38 ) ,
V_36 -> V_38 . V_14 , V_36 -> V_39 ) ;
}
static void F_42 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
if ( ! F_43 ( V_36 ) )
return;
V_22 = V_36 -> V_38 . V_22 ;
F_44 ( V_36 , V_98 ) ;
F_45 ( & V_36 -> V_99 , & V_22 -> V_100 ) ;
F_46 ( & V_36 -> V_99 ) ;
if ( V_36 -> V_39 ) {
struct V_9 * V_10 = F_2 ( & V_36 -> V_38 ) ;
F_3 ( V_36 -> V_38 . V_22 -> V_101 < V_36 -> V_39 ) ;
V_36 -> V_38 . V_22 -> V_101 -= V_36 -> V_39 ;
V_22 -> V_102 += V_36 -> V_39 ;
V_36 -> V_39 = 0 ;
F_47 ( V_103 , & V_10 -> V_104 ) ;
}
}
void F_48 ( struct V_35 * V_36 )
{
struct V_69 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_27 ( & V_22 -> V_105 ) ;
F_42 ( V_36 ) ;
F_3 ( V_36 -> V_39 ) ;
F_29 ( & V_22 -> V_105 ) ;
}
}
void F_49 ( struct V_90 * V_91 , T_5 * V_106 )
{
F_50 ( & V_91 -> V_107 ) ;
if ( ( V_106 == NULL ) || ( F_51 ( V_106 ) <= 1 ) )
F_48 ( & V_91 -> V_108 ) ;
F_52 ( & V_91 -> V_107 ) ;
F_53 ( V_91 , V_106 ) ;
}
static void F_54 ( struct V_69 * V_22 )
{
struct V_82 * V_59 ;
struct V_35 * V_36 ;
F_27 ( & V_22 -> V_105 ) ;
while ( ( V_59 = F_31 ( & V_22 -> V_100 ) ) ) {
V_36 = F_28 ( V_59 , struct V_35 , V_99 ) ;
F_42 ( V_36 ) ;
}
F_29 ( & V_22 -> V_105 ) ;
}
void F_55 ( struct V_74 * V_75 )
{
struct V_82 * V_59 ;
struct V_69 * V_22 ;
struct V_109 * V_110 ;
while ( ( V_59 = F_31 ( & V_75 -> V_86 ) ) ) {
V_22 = F_28 ( V_59 , struct V_69 , V_87 ) ;
V_110 = V_22 -> V_111 ;
F_45 ( V_59 , & V_75 -> V_86 ) ;
if ( V_110 ) {
F_56 ( V_110 , V_22 ) ;
F_57 ( V_110 ) ;
}
F_36 ( V_22 ) ;
F_37 ( V_22 -> V_78 ) ;
V_22 -> V_78 = NULL ;
F_54 ( V_22 ) ;
F_58 ( V_112 , V_22 ) ;
}
}
static void F_59 ( const struct V_69 * V_22 )
{
F_60 ( L_8 , ( unsigned long long ) V_22 -> V_23 ) ;
F_60 ( L_9 , V_22 -> V_57 ) ;
F_60 ( L_10 , ( unsigned long long ) V_22 -> V_46 ) ;
F_60 ( L_11 , V_22 -> V_49 ) ;
F_60 ( L_12 , V_22 -> V_113 ) ;
}
static int F_61 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_114 , V_64 ;
int V_77 ;
if ( ! V_76 )
return - V_48 ;
V_22 -> V_78 = F_62 ( V_76 , sizeof( struct V_9 ) , V_115 ) ;
if ( ! V_22 -> V_78 )
return - V_116 ;
V_114 = V_22 -> V_113 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
V_10 -> V_104 = 0 ;
if ( V_76 == 1 ) {
V_64 = V_114 ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 == 0 ) {
V_64 = V_75 -> V_117 . V_118 - sizeof( struct V_53 ) ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 + 1 == V_76 ) {
V_64 = V_114 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_113 - V_114 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else {
V_64 = V_75 -> V_117 . V_118 -
sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_113 - V_114 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
}
V_114 -= V_64 ;
}
if ( V_114 ) {
F_7 ( V_22 ) ;
return - V_119 ;
}
V_10 = V_22 -> V_78 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_12 ) * V_15 != V_22 -> V_49 ) {
if ( F_7 ( V_22 ) ) {
F_59 ( V_22 ) ;
F_25 ( V_75 , L_13 ,
V_10 -> V_24 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_119 ;
}
return 0 ;
}
T_2 F_63 ( struct V_74 * V_75 )
{
T_2 V_120 = 0 ;
struct V_121 * V_121 = V_75 -> V_122 ;
struct V_90 * V_91 = F_64 ( V_121 ) ;
char V_40 [ sizeof( struct V_123 ) ] ;
int error , V_124 ;
for ( V_124 = 0 ; ; V_124 ++ ) {
T_6 V_125 = V_124 * sizeof( struct V_123 ) ;
if ( V_125 + sizeof( struct V_123 ) > F_65 ( V_121 ) )
break;
error = F_66 ( V_91 , V_40 , & V_125 ,
sizeof( struct V_123 ) ) ;
if ( error != sizeof( struct V_123 ) )
break;
V_120 += F_67 ( ( (struct V_123 * ) V_40 ) -> V_126 ) ;
}
return V_120 ;
}
static int F_68 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_82 * * V_127 = & V_75 -> V_86 . V_82 , * V_128 = NULL ;
while ( * V_127 ) {
struct V_69 * V_84 = F_28 ( * V_127 , struct V_69 ,
V_87 ) ;
V_128 = * V_127 ;
if ( V_22 -> V_23 < V_84 -> V_23 )
V_127 = & ( ( * V_127 ) -> V_88 ) ;
else if ( V_22 -> V_23 > V_84 -> V_23 )
V_127 = & ( ( * V_127 ) -> V_89 ) ;
else
return - V_129 ;
}
F_69 ( & V_22 -> V_87 , V_128 , V_127 ) ;
F_70 ( & V_22 -> V_87 , & V_75 -> V_86 ) ;
V_75 -> V_130 ++ ;
return 0 ;
}
static int F_71 ( struct V_90 * V_91 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
const unsigned V_131 = V_75 -> V_117 . V_118 ;
T_6 V_125 = V_75 -> V_130 * sizeof( struct V_123 ) ;
struct V_123 V_40 ;
int error ;
struct V_69 * V_22 ;
if ( V_125 >= F_65 ( & V_91 -> V_92 ) )
return 1 ;
error = F_66 ( V_91 , ( char * ) & V_40 , & V_125 ,
sizeof( struct V_123 ) ) ;
if ( error != sizeof( struct V_123 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_72 ( V_112 , V_115 ) ;
error = - V_116 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_75 ;
V_22 -> V_23 = F_73 ( V_40 . V_132 ) ;
V_22 -> V_57 = F_67 ( V_40 . V_133 ) ;
V_22 -> V_46 = F_73 ( V_40 . V_134 ) ;
V_22 -> V_49 = F_67 ( V_40 . V_126 ) ;
V_22 -> V_113 = F_67 ( V_40 . V_135 ) ;
F_74 ( & V_22 -> V_105 ) ;
error = F_61 ( V_22 ) ;
if ( error )
goto V_136;
error = F_75 ( V_75 , V_22 -> V_23 ,
& V_137 , V_138 , & V_22 -> V_111 ) ;
if ( error )
goto V_136;
V_22 -> V_139 = (struct V_140 * ) V_22 -> V_111 -> V_141 . V_142 ;
V_22 -> V_143 &= ~ ( V_144 | V_145 ) ;
if ( V_22 -> V_49 > V_75 -> V_146 )
V_75 -> V_146 = V_22 -> V_49 ;
F_27 ( & V_75 -> V_85 ) ;
error = F_68 ( V_22 ) ;
F_29 ( & V_75 -> V_85 ) ;
if ( ! error ) {
F_76 ( V_22 -> V_111 , V_22 ) ;
V_22 -> V_111 -> V_147 . V_66 = ( V_22 -> V_23 * V_131 ) & V_148 ;
V_22 -> V_111 -> V_147 . V_7 = F_77 ( ( V_22 -> V_23 +
V_22 -> V_57 ) * V_131 ) - 1 ;
return 0 ;
}
error = 0 ;
F_57 ( V_22 -> V_111 ) ;
V_136:
F_37 ( V_22 -> V_78 ) ;
V_22 -> V_78 = NULL ;
F_58 ( V_112 , V_22 ) ;
return error ;
}
static void F_78 ( struct V_74 * V_75 )
{
struct V_69 * V_22 , * V_149 ;
int V_150 ;
V_22 = F_30 ( V_75 ) ;
for ( V_150 = 0 ; V_150 < V_75 -> V_151 . V_152 ; V_150 ++ )
V_22 = F_32 ( V_22 ) ;
V_149 = V_22 ;
do {
V_22 -> V_143 |= V_145 ;
for ( V_150 = 0 ; V_150 < V_75 -> V_153 ; V_150 ++ ) {
V_22 = F_32 ( V_22 ) ;
if ( ! V_22 || V_22 == V_149 )
break;
}
} while ( V_22 && V_22 != V_149 );
}
static int F_79 ( struct V_90 * V_91 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
int error ;
do {
error = F_71 ( V_91 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
F_78 ( V_75 ) ;
V_75 -> V_154 = 1 ;
return 0 ;
}
int F_80 ( struct V_74 * V_75 )
{
struct V_90 * V_91 = F_64 ( V_75 -> V_122 ) ;
struct V_109 * V_110 = V_91 -> V_155 ;
struct V_156 V_157 ;
int error = 0 ;
int V_158 = 0 ;
if ( ! V_75 -> V_154 ) {
if ( ! F_81 ( V_110 ) ) {
error = F_82 ( V_110 , V_159 , 0 , & V_157 ) ;
if ( error )
return error ;
V_158 = 1 ;
}
if ( ! V_75 -> V_154 )
error = F_79 ( V_91 ) ;
if ( V_158 )
F_83 ( & V_157 ) ;
}
return error ;
}
static void F_84 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_160 = V_40 ;
T_4 V_161 ;
V_161 = F_67 ( V_160 -> V_161 ) ;
V_161 &= ~ V_162 ;
V_22 -> V_143 &= V_162 ;
V_22 -> V_143 |= V_161 ;
V_22 -> V_79 = F_67 ( V_160 -> V_163 ) ;
V_22 -> V_80 = F_67 ( V_160 -> V_164 ) ;
V_22 -> V_165 = F_73 ( V_160 -> V_166 ) ;
}
static void F_85 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_160 = V_40 ;
V_160 -> V_161 = F_86 ( V_22 -> V_143 & ~ V_162 ) ;
V_160 -> V_163 = F_86 ( V_22 -> V_79 ) ;
V_160 -> V_164 = F_86 ( V_22 -> V_80 ) ;
V_160 -> V_167 = F_86 ( 0 ) ;
V_160 -> V_166 = F_87 ( V_22 -> V_165 ) ;
memset ( & V_160 -> V_168 , 0 , sizeof( V_160 -> V_168 ) ) ;
}
static int F_88 ( struct V_69 * V_22 )
{
struct V_140 * V_169 = V_22 -> V_139 ;
struct V_53 * V_160 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_169 -> V_170 != V_160 -> V_161 || V_169 -> V_171 != V_160 -> V_163 ||
V_169 -> V_172 != V_160 -> V_164 ||
V_169 -> V_173 != V_160 -> V_166 )
return 0 ;
return 1 ;
}
static void F_89 ( struct V_140 * V_169 , const void * V_40 )
{
const struct V_53 * V_160 = V_40 ;
V_169 -> V_174 = F_86 ( V_175 ) ;
V_169 -> V_170 = V_160 -> V_161 ;
V_169 -> V_171 = V_160 -> V_163 ;
V_169 -> V_172 = V_160 -> V_164 ;
V_169 -> V_173 = V_160 -> V_166 ;
V_169 -> V_167 = 0UL ;
}
static void F_90 ( struct V_69 * V_22 , T_4 V_176 )
{
struct V_140 * V_169 = V_22 -> V_139 ;
T_4 V_177 = F_67 ( V_169 -> V_178 ) + V_176 ;
V_169 -> V_178 = F_86 ( V_177 ) ;
}
static T_4 F_91 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_150 , V_41 , V_73 = 0 ;
for ( V_150 = 0 , V_10 = V_22 -> V_78 ; V_150 < V_76 ; V_150 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_92 ( ! F_93 ( V_10 -> V_17 ) ) ;
while ( V_41 < V_10 -> V_12 * V_15 ) {
V_41 = F_13 ( V_26 , V_10 -> V_12 , V_41 ,
V_179 ) ;
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
struct V_109 * V_110 = V_22 -> V_111 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_180 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_95 ( V_110 , V_22 -> V_23 + V_77 , 0 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_136;
}
for ( V_180 = V_76 ; V_180 -- ; ) {
V_10 = V_22 -> V_78 + V_180 ;
error = F_96 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_136;
if ( F_97 ( V_75 , V_10 -> V_17 , V_180 ? V_181 :
V_182 ) ) {
error = - V_119 ;
goto V_136;
}
}
if ( ! ( V_22 -> V_143 & V_144 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_47 ( V_103 , & V_22 -> V_78 [ V_77 ] . V_104 ) ;
F_84 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_143 |= ( V_144 | V_183 ) ;
V_22 -> V_184 = V_22 -> V_79 ;
V_22 -> V_102 = V_22 -> V_79 ;
}
if ( F_86 ( V_175 ) != V_22 -> V_139 -> V_174 ) {
V_22 -> V_139 -> V_178 = F_86 ( F_91 ( V_22 ) ) ;
F_89 ( V_22 -> V_139 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_185 . V_186 ) {
if ( ! F_88 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_119 ;
goto V_136;
}
if ( V_22 -> V_139 -> V_178 == 0 )
V_22 -> V_143 &= ~ V_183 ;
}
return 0 ;
V_136:
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
T_4 V_170 ;
if ( V_22 -> V_143 & V_144 )
return 0 ;
if ( F_86 ( V_175 ) != V_22 -> V_139 -> V_174 )
return F_94 ( V_22 ) ;
V_170 = F_67 ( V_22 -> V_139 -> V_170 ) ;
V_170 &= ~ V_162 ;
V_22 -> V_143 &= V_162 ;
V_22 -> V_143 |= ( V_170 | V_144 | V_183 ) ;
if ( V_22 -> V_139 -> V_178 == 0 )
V_22 -> V_143 &= ~ V_183 ;
V_22 -> V_79 = F_67 ( V_22 -> V_139 -> V_171 ) ;
V_22 -> V_184 = V_22 -> V_79 ;
V_22 -> V_80 = F_67 ( V_22 -> V_139 -> V_172 ) ;
V_22 -> V_165 = F_73 ( V_22 -> V_139 -> V_173 ) ;
return 0 ;
}
int F_101 ( struct V_156 * V_187 )
{
struct V_69 * V_22 = V_187 -> V_188 -> V_189 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_187 -> V_190 & V_191 && V_75 -> V_185 . V_186 )
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
void F_103 ( struct V_156 * V_187 )
{
struct V_69 * V_22 = V_187 -> V_188 -> V_189 ;
int V_192 = F_104 ( V_193 , & V_187 -> V_188 -> V_194 ) |
F_104 ( V_195 , & V_187 -> V_188 -> V_194 ) ;
if ( V_22 && V_192 )
F_102 ( V_22 ) ;
}
int F_105 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_196 * V_197 ,
const struct V_9 * V_10 , unsigned V_198 , T_2 * V_199 )
{
struct V_200 * V_201 = V_75 -> V_202 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_203 = 0 ;
int V_204 ;
unsigned int V_77 ;
T_4 V_205 = 0 ;
T_1 V_206 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_207 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_207 += V_10 -> V_19 ;
V_207 += V_77 ;
if ( V_197 ) {
const T_1 * V_208 = V_197 -> V_18 + V_10 -> V_19 + V_77 ;
V_206 = ~ ( * V_208 | ( * V_208 >> 1 ) ) & ( * V_207 | ( * V_207 >> 1 ) ) ;
} else {
V_206 = ~ ( * V_207 | ( * V_207 >> 1 ) ) ;
}
V_206 &= 0x55 ;
if ( V_206 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_206 ) {
if ( V_206 & 1 ) {
if ( V_203 == 0 )
goto V_209;
if ( ( V_66 + V_203 ) != V_33 ) {
if ( V_203 >= V_198 ) {
V_204 = F_106 ( V_201 ,
V_66 , V_203 ,
V_115 , 0 ) ;
if ( V_204 )
goto V_136;
V_205 += V_203 ;
}
V_203 = 0 ;
V_209:
V_66 = V_33 ;
}
V_203 ++ ;
}
V_206 >>= 2 ;
V_33 ++ ;
}
}
if ( V_203 >= V_198 ) {
V_204 = F_106 ( V_201 , V_66 , V_203 , V_115 , 0 ) ;
if ( V_204 )
goto V_136;
V_205 += V_203 ;
}
if ( V_199 )
* V_199 = V_205 ;
return 0 ;
V_136:
if ( V_75 -> V_185 . V_210 )
F_107 ( V_75 , L_14 , V_204 ) ;
V_75 -> V_185 . V_210 = 0 ;
return - V_119 ;
}
int F_108 ( struct V_211 * V_212 , void T_8 * V_213 )
{
struct V_121 * V_121 = F_109 ( V_212 ) ;
struct V_74 * V_75 = F_35 ( V_121 ) ;
struct V_214 * V_215 = F_110 ( V_75 -> V_202 -> V_216 ) ;
struct V_196 * V_197 ;
struct V_69 * V_22 ;
struct V_69 * V_217 ;
struct V_156 V_187 ;
struct V_218 V_219 ;
int V_220 = 0 ;
T_2 V_221 ;
T_2 V_205 = 0 ;
T_2 V_66 , V_7 , V_198 ;
unsigned int V_77 ;
unsigned V_222 = V_75 -> V_117 . V_223 ;
if ( ! F_111 ( V_224 ) )
return - V_225 ;
if ( ! F_112 ( V_215 ) )
return - V_226 ;
if ( F_113 ( & V_219 , V_213 , sizeof( V_219 ) ) )
return - V_227 ;
V_220 = F_80 ( V_75 ) ;
if ( V_220 )
return V_220 ;
V_66 = V_219 . V_66 >> V_222 ;
V_7 = V_66 + ( V_219 . V_34 >> V_222 ) ;
V_198 = F_114 ( T_2 , V_219 . V_198 ,
V_215 -> V_228 . V_229 ) >> V_222 ;
if ( V_7 <= V_66 || V_198 > V_75 -> V_146 )
return - V_48 ;
V_22 = F_26 ( V_75 , V_66 , 0 ) ;
V_217 = F_26 ( V_75 , V_7 , 0 ) ;
if ( ( F_30 ( V_75 ) == F_32 ( V_217 ) )
&& ( V_66 > V_217 -> V_46 + V_217 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_220 = F_82 ( V_22 -> V_111 , V_230 , 0 , & V_187 ) ;
if ( V_220 )
goto V_67;
if ( ! ( V_22 -> V_143 & V_231 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_220 = F_105 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_198 ,
& V_221 ) ;
if ( V_220 ) {
F_83 ( & V_187 ) ;
goto V_67;
}
V_205 += V_221 ;
}
V_220 = F_115 ( V_75 , V_232 , 0 ) ;
if ( V_220 == 0 ) {
V_197 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_143 |= V_231 ;
F_116 ( V_22 -> V_111 , V_197 ) ;
F_85 ( V_22 , V_197 -> V_18 ) ;
F_89 ( V_22 -> V_139 , V_197 -> V_18 ) ;
F_117 ( V_75 ) ;
}
}
F_83 ( & V_187 ) ;
if ( V_22 == V_217 )
break;
V_22 = F_32 ( V_22 ) ;
}
V_67:
V_219 . V_34 = V_205 << V_222 ;
if ( F_118 ( V_213 , & V_219 , sizeof( V_219 ) ) )
return - V_227 ;
return V_220 ;
}
static void F_119 ( struct V_90 * V_91 )
{
struct V_82 * * V_127 , * V_128 = NULL ;
int V_233 ;
struct V_35 * V_36 = & V_91 -> V_108 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_234 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_43 ( V_36 ) ) ;
F_27 ( & V_22 -> V_105 ) ;
V_127 = & V_22 -> V_100 . V_82 ;
while ( * V_127 ) {
struct V_35 * V_84 =
F_28 ( * V_127 , struct V_35 , V_99 ) ;
V_128 = * V_127 ;
V_233 = F_11 ( V_234 , V_36 -> V_39 , V_84 ) ;
if ( V_233 > 0 )
V_127 = & ( ( * V_127 ) -> V_89 ) ;
else if ( V_233 < 0 )
V_127 = & ( ( * V_127 ) -> V_88 ) ;
else {
F_29 ( & V_22 -> V_105 ) ;
F_92 ( 1 ) ;
return;
}
}
F_69 ( & V_36 -> V_99 , V_128 , V_127 ) ;
F_70 ( & V_36 -> V_99 , & V_22 -> V_100 ) ;
V_22 -> V_101 += V_36 -> V_39 ;
F_29 ( & V_22 -> V_105 ) ;
F_44 ( V_36 , V_235 ) ;
}
static void F_120 ( struct V_69 * V_22 , struct V_90 * V_91 ,
const struct V_236 * V_237 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = & V_91 -> V_108 ;
T_4 V_238 ;
T_4 V_239 = V_22 -> V_184 - V_22 -> V_101 ;
int V_220 ;
struct V_121 * V_121 = & V_91 -> V_92 ;
if ( F_121 ( V_121 -> V_240 ) )
V_238 = 1 ;
else {
V_238 = F_114 ( T_4 , F_51 ( & V_36 -> V_241 ) , V_237 -> V_242 ) ;
V_238 = F_122 ( V_238 , V_243 , V_239 ) ;
}
if ( ( V_22 -> V_184 < V_22 -> V_101 ) || ( V_239 < V_238 ) )
return;
if ( F_123 ( V_22 , V_91 -> V_93 ) )
V_41 = V_91 -> V_93 ;
else
V_41 = V_22 -> V_244 + V_22 -> V_46 ;
if ( F_92 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_220 = F_124 ( & V_2 , V_61 , & V_238 , V_91 , true ) ;
if ( V_220 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_238 ;
V_36 -> V_97 = V_91 -> V_94 ;
F_119 ( V_91 ) ;
} else {
if ( V_41 == V_22 -> V_244 + V_22 -> V_46 )
V_22 -> V_244 = 0 ;
}
}
static T_2 F_125 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_90 * V_91 )
{
struct V_35 * V_36 ;
struct V_82 * V_59 ;
int V_233 ;
F_27 ( & V_22 -> V_105 ) ;
V_59 = V_22 -> V_100 . V_82 ;
while ( V_59 ) {
V_36 = F_28 ( V_59 , struct V_35 , V_99 ) ;
V_233 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_233 < 0 )
V_59 = V_59 -> V_88 ;
else if ( V_233 > 0 )
V_59 = V_59 -> V_89 ;
else
break;
}
if ( V_59 ) {
while ( ( F_11 ( V_44 , V_76 , V_36 ) == 0 ) && ( & V_91 -> V_108 != V_36 ) ) {
V_44 = F_12 ( & V_36 -> V_38 ) + V_36 -> V_39 ;
V_59 = V_59 -> V_89 ;
if ( V_59 == NULL )
break;
V_36 = F_28 ( V_59 , struct V_35 , V_99 ) ;
}
}
F_29 ( & V_22 -> V_105 ) ;
return V_44 ;
}
static int F_126 ( struct V_1 * V_2 ,
const struct V_90 * V_91 ,
T_4 V_245 ,
struct V_246 * V_247 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_238 = 1 ;
T_2 V_248 ;
int V_220 ;
if ( V_245 ) {
V_238 = F_20 ( V_2 , V_245 ) ;
if ( V_238 <= V_247 -> V_34 )
goto V_136;
}
V_248 = F_125 ( V_2 -> V_22 , V_44 , V_238 , V_91 ) ;
if ( V_248 == V_44 ) {
if ( ! V_245 || V_238 >= V_245 )
return 0 ;
if ( V_238 > V_247 -> V_34 ) {
V_247 -> V_34 = V_238 ;
V_247 -> V_2 = * V_2 ;
}
V_136:
V_248 = V_44 + V_238 ;
}
V_220 = F_16 ( V_2 , V_248 ) ;
if ( V_220 < 0 )
return V_220 ;
return 1 ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_245 ,
const struct V_90 * V_91 , bool V_249 )
{
struct V_196 * V_197 ;
int V_250 ;
T_4 V_251 ;
int V_252 = V_2 -> V_51 ;
T_4 V_253 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_254 = V_2 -> V_22 -> V_57 ;
int V_220 ;
struct V_9 * V_10 ;
struct V_246 V_247 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_254 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_104 ( V_103 , & V_10 -> V_104 ) &&
( V_30 == V_61 ) )
goto V_255;
V_197 = V_10 -> V_17 ;
V_26 = V_197 -> V_18 + V_10 -> V_19 ;
F_92 ( ! F_93 ( V_197 ) ) ;
if ( V_30 != V_179 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_251 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_256;
V_2 -> V_14 = V_14 ;
if ( V_91 == NULL )
return 0 ;
V_250 = V_2 -> V_51 ;
V_220 = F_126 ( V_2 , V_91 ,
V_245 ? * V_245 : 0 ,
& V_247 ) ;
if ( V_220 == 0 )
return 0 ;
if ( V_220 > 0 ) {
V_59 += ( V_2 -> V_51 - V_250 ) ;
goto V_257;
}
if ( V_220 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_250 ) ;
goto V_258;
}
return V_220 ;
V_256:
if ( ( V_30 == V_61 ) && V_251 == 0 )
F_127 ( V_103 , & V_10 -> V_104 ) ;
V_255:
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 )
V_2 -> V_51 = 0 ;
V_258:
if ( ( V_2 -> V_51 == 0 ) && V_249 )
break;
V_59 ++ ;
V_257:
if ( V_59 >= V_254 )
break;
}
if ( V_245 == NULL || V_30 != V_61 )
return - V_259 ;
if ( ( V_253 == 0 ) && ( V_252 == 0 ) &&
( * V_245 < V_2 -> V_22 -> V_102 ) )
V_2 -> V_22 -> V_102 = * V_245 ;
if ( V_247 . V_34 ) {
* V_2 = V_247 . V_2 ;
* V_245 = V_247 . V_34 ;
return 0 ;
}
return - V_259 ;
}
static void F_128 ( struct V_69 * V_22 , T_2 * V_260 , T_2 V_261 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_109 * V_110 ;
struct V_90 * V_91 ;
int error ;
int V_262 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_50 ( & V_75 -> V_263 ) ;
error = F_124 ( & V_2 , V_179 , NULL , NULL ,
true ) ;
F_52 ( & V_75 -> V_263 ) ;
if ( error == - V_259 )
break;
if ( F_17 ( error ) )
break;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_260 != V_264 && V_44 <= * V_260 )
continue;
if ( V_44 == V_261 )
continue;
* V_260 = V_44 ;
error = F_75 ( V_75 , V_44 , & V_265 , V_138 , & V_110 ) ;
if ( error )
continue;
V_91 = V_110 -> V_189 ;
if ( V_91 || F_129 ( V_266 , & V_110 -> V_267 ) == 0 )
F_57 ( V_110 ) ;
else
V_262 ++ ;
if ( V_262 > V_268 )
return;
}
V_22 -> V_143 &= ~ V_183 ;
return;
}
static bool F_130 ( const struct V_69 * V_22 , int V_269 )
{
const struct V_109 * V_110 = V_22 -> V_111 ;
const struct V_74 * V_75 = V_110 -> V_270 . V_271 ;
struct V_272 * V_273 ;
T_2 V_274 , V_275 ;
T_2 V_276 , V_277 = 0 ;
T_9 V_278 ;
T_2 V_279 ;
T_2 V_280 ;
int V_281 , V_282 = 0 ;
F_131 () ;
F_132 (cpu) {
V_273 = & F_133 ( V_75 -> V_283 , V_281 ) -> V_284 [ V_285 ] ;
if ( V_273 -> V_286 [ V_287 ] ) {
V_277 += V_273 -> V_286 [ V_287 ] ;
V_282 ++ ;
}
}
V_273 = & F_134 ( V_75 -> V_283 ) -> V_284 [ V_285 ] ;
if ( V_282 )
F_135 ( V_277 , V_282 ) ;
V_274 = V_273 -> V_286 [ V_288 ] ;
V_280 = V_273 -> V_286 [ V_289 ] +
V_110 -> V_290 . V_286 [ V_289 ] ;
F_136 () ;
V_276 = V_110 -> V_290 . V_286 [ V_287 ] ;
V_275 = V_110 -> V_290 . V_286 [ V_288 ] ;
if ( ( V_275 < 1 ) || ( V_274 < 1 ) || ( V_277 == 0 ) )
return false ;
V_278 = V_277 - V_276 ;
V_279 = V_278 * V_278 ;
V_280 *= 2 ;
if ( V_275 < 8 || V_274 < 8 )
V_280 *= 2 ;
if ( V_269 == 1 )
V_280 *= 2 ;
return ( ( V_278 < 0 ) && ( V_279 > V_280 ) ) ;
}
static bool F_137 ( const struct V_35 * V_36 ,
T_2 V_291 )
{
T_2 V_292 ;
V_292 = F_138 ( F_139 ( F_140 () ,
V_36 -> V_38 . V_22 -> V_111 -> V_293 ) ) ;
return V_292 > ( V_291 * 1000 * 1000 ) ;
}
static T_4 F_141 ( const struct V_90 * V_91 )
{
const struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
T_4 V_261 ;
F_142 ( & V_261 , sizeof( V_261 ) ) ;
return V_261 % V_75 -> V_130 ;
}
static bool F_143 ( struct V_69 * * V_125 , const struct V_69 * V_294 )
{
struct V_69 * V_22 = * V_125 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_32 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_30 ( V_75 ) ;
* V_125 = V_22 ;
if ( V_22 != V_294 )
return true ;
return false ;
}
static inline int F_144 ( struct V_69 * V_22 )
{
struct V_109 * V_110 = V_22 -> V_111 ;
if ( V_110 -> V_295 != V_296 && F_145 ( & V_110 -> V_297 ) &&
! F_104 ( V_298 , & V_110 -> V_194 ) &&
! F_104 ( V_193 , & V_110 -> V_194 ) )
return 1 ;
if ( V_22 -> V_143 & V_145 )
return 1 ;
return 0 ;
}
int F_146 ( struct V_90 * V_91 , struct V_236 * V_237 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_69 * V_294 = NULL ;
struct V_35 * V_36 = & V_91 -> V_108 ;
int error = 0 , V_299 , V_300 = 0 ;
T_2 V_260 = V_264 ;
int V_269 = 0 ;
T_4 V_261 = 0 ;
if ( V_75 -> V_185 . V_186 )
V_300 |= V_191 ;
if ( F_99 ( V_75 , V_237 -> V_242 ) )
return - V_48 ;
if ( F_43 ( V_36 ) ) {
V_294 = V_36 -> V_38 . V_22 ;
} else if ( V_91 -> V_301 && F_123 ( V_91 -> V_301 , V_91 -> V_93 ) ) {
V_36 -> V_38 . V_22 = V_294 = V_91 -> V_301 ;
} else {
F_34 ( V_91 ) ;
V_36 -> V_38 . V_22 = V_294 = F_26 ( V_75 , V_91 -> V_93 , 1 ) ;
}
if ( F_121 ( V_91 -> V_92 . V_240 ) && ( V_237 -> V_302 & V_303 ) )
V_261 = F_141 ( V_91 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_304 ;
while ( V_269 < 3 ) {
V_299 = 1 ;
if ( ! F_81 ( V_36 -> V_38 . V_22 -> V_111 ) ) {
V_299 = 0 ;
if ( V_261 && V_261 -- )
goto V_305;
if ( ! F_43 ( V_36 ) ) {
if ( V_269 == 0 &&
! F_144 ( V_36 -> V_38 . V_22 ) )
goto V_305;
if ( ( V_269 < 2 ) &&
F_137 ( V_36 , 1000 ) &&
F_130 ( V_36 -> V_38 . V_22 , V_269 ) )
goto V_305;
}
error = F_82 ( V_36 -> V_38 . V_22 -> V_111 ,
V_230 , V_300 ,
& V_36 -> V_306 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_43 ( V_36 ) && ( V_269 < 2 ) &&
F_130 ( V_36 -> V_38 . V_22 , V_269 ) )
goto V_307;
if ( V_75 -> V_185 . V_186 ) {
error = F_100 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_83 ( & V_36 -> V_306 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_143 & ( V_308 |
V_309 ) ) ||
( V_269 == 0 && V_237 -> V_242 > V_36 -> V_38 . V_22 -> V_102 ) )
goto V_307;
if ( V_75 -> V_185 . V_186 )
F_94 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_43 ( V_36 ) )
F_120 ( V_36 -> V_38 . V_22 , V_91 , V_237 ) ;
if ( ! F_43 ( V_36 ) && ( V_269 < 1 ) )
goto V_310;
if ( V_36 -> V_38 . V_22 -> V_184 >= V_237 -> V_242 ||
( V_269 == 2 && V_237 -> V_311 &&
V_36 -> V_38 . V_22 -> V_184 >= V_237 -> V_311 ) ) {
V_91 -> V_301 = V_36 -> V_38 . V_22 ;
V_237 -> V_312 = V_91 -> V_301 -> V_184 ;
return 0 ;
}
V_310:
if ( V_36 -> V_38 . V_22 -> V_143 & V_183 )
F_128 ( V_36 -> V_38 . V_22 , & V_260 ,
V_91 -> V_94 ) ;
V_307:
if ( F_43 ( V_36 ) )
F_48 ( V_36 ) ;
if ( ! V_299 )
F_83 ( & V_36 -> V_306 ) ;
V_305:
if ( F_143 ( & V_36 -> V_38 . V_22 , V_294 ) )
continue;
if ( V_261 )
continue;
V_269 ++ ;
if ( V_91 == F_64 ( V_75 -> V_122 ) && ! V_75 -> V_154 ) {
error = F_79 ( V_91 ) ;
if ( error )
return error ;
}
if ( V_269 == 2 )
F_147 ( V_75 , NULL , V_313 ) ;
}
return - V_259 ;
}
void F_148 ( struct V_90 * V_91 )
{
struct V_35 * V_36 = & V_91 -> V_108 ;
if ( F_149 ( & V_36 -> V_306 ) )
F_83 ( & V_36 -> V_306 ) ;
}
static unsigned char F_150 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_220 ;
V_220 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_220 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_151 ( const struct V_1 * V_2 , bool V_314 ,
unsigned int * V_59 )
{
struct V_1 V_125 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_315 = * V_59 ;
T_2 V_44 ;
int V_220 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_116 ( V_2 -> V_22 -> V_111 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_314 ? V_316 : V_317 ) ;
V_44 ++ ;
while ( * V_59 < V_315 ) {
V_220 = F_16 ( & V_125 , V_44 ) ;
if ( V_220 || F_8 ( & V_125 ) != V_61 )
break;
F_116 ( V_125 . V_22 -> V_111 , F_2 ( & V_125 ) -> V_17 ) ;
F_1 ( & V_125 , true , V_317 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_152 ( struct V_74 * V_75 , T_2 V_318 ,
T_4 V_319 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 , * V_320 = NULL ;
V_2 . V_22 = F_26 ( V_75 , V_318 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_153 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_318 ) ;
return NULL ;
}
F_16 ( & V_2 , V_318 ) ;
while ( V_319 -- ) {
V_10 = F_2 ( & V_2 ) ;
if ( V_10 != V_320 ) {
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_154 ( V_10 -> V_17 -> V_68 ,
V_115 | V_321 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 ,
V_10 -> V_12 ) ;
}
F_116 ( V_2 . V_22 -> V_111 , V_10 -> V_17 ) ;
V_320 = V_10 ;
}
F_1 ( & V_2 , false , V_4 ) ;
F_18 ( & V_2 ) ;
}
return V_2 . V_22 ;
}
void F_155 ( struct V_95 * V_96 , const struct V_109 * V_110 )
{
struct V_69 * V_22 = V_110 -> V_189 ;
struct V_35 * V_322 ;
const struct V_82 * V_59 ;
if ( V_22 == NULL )
return;
F_41 ( V_96 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_143 ,
V_22 -> V_79 , V_22 -> V_184 , V_22 -> V_80 ,
V_22 -> V_101 , V_22 -> V_102 ) ;
F_27 ( & V_22 -> V_105 ) ;
for ( V_59 = F_31 ( & V_22 -> V_100 ) ; V_59 ; V_59 = F_33 ( & V_322 -> V_99 ) ) {
V_322 = F_28 ( V_59 , struct V_35 , V_99 ) ;
F_40 ( V_96 , V_322 ) ;
}
F_29 ( & V_22 -> V_105 ) ;
}
static void F_156 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_107 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_107 ( V_75 , L_18 ) ;
F_155 ( NULL , V_22 -> V_111 ) ;
V_22 -> V_143 |= V_309 ;
}
static void F_157 ( struct V_90 * V_91 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = & V_91 -> V_108 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_323 ;
T_2 V_44 ;
int V_220 ;
F_27 ( & V_22 -> V_105 ) ;
if ( F_43 ( V_36 ) ) {
if ( F_158 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_220 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_323 = F_159 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_323 ;
V_22 -> V_101 -= V_323 ;
F_44 ( V_36 , V_324 ) ;
if ( V_36 -> V_39 && ! V_220 )
goto V_67;
F_160 ( V_325 , & V_36 -> V_241 ) ;
}
F_42 ( V_36 ) ;
}
V_67:
F_29 ( & V_22 -> V_105 ) ;
}
static void F_161 ( struct V_1 * V_2 ,
const struct V_90 * V_91 , bool V_314 )
{
T_2 V_41 ;
if ( F_43 ( & V_91 -> V_108 ) ) {
* V_2 = V_91 -> V_108 . V_38 ;
return;
}
if ( ! V_314 && F_123 ( V_2 -> V_22 , V_91 -> V_93 ) )
V_41 = V_91 -> V_93 ;
else
V_41 = V_2 -> V_22 -> V_244 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_162 ( struct V_90 * V_91 , T_2 * V_326 , unsigned int * V_327 ,
bool V_314 , T_2 * V_328 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_196 * V_329 ;
struct V_1 V_2 = { . V_22 = V_91 -> V_301 , } ;
unsigned int V_330 ;
T_2 V_44 ;
int error ;
F_161 ( & V_2 , V_91 , V_314 ) ;
error = F_124 ( & V_2 , V_61 , NULL , V_91 , false ) ;
if ( error == - V_259 ) {
F_161 ( & V_2 , V_91 , V_314 ) ;
error = F_124 ( & V_2 , V_61 , NULL , NULL , false ) ;
}
if ( error ) {
F_107 ( V_75 , L_19 ,
( unsigned long long ) V_91 -> V_94 , error , * V_327 ,
F_104 ( V_103 , & V_2 . V_22 -> V_78 -> V_104 ) ,
V_2 . V_22 -> V_102 ) ;
goto V_331;
}
F_151 ( & V_2 , V_314 , V_327 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_244 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_43 ( & V_91 -> V_108 ) )
F_157 ( V_91 , & V_2 , * V_327 ) ;
V_330 = * V_327 ;
if ( V_314 )
V_330 -- ;
if ( ! V_314 ) {
V_91 -> V_93 = V_44 + V_330 - 1 ;
error = F_163 ( V_91 , & V_329 ) ;
if ( error == 0 ) {
struct V_332 * V_333 =
(struct V_332 * ) V_329 -> V_18 ;
F_116 ( V_91 -> V_155 , V_329 ) ;
V_333 -> V_334 = V_333 -> V_335 =
F_87 ( V_91 -> V_93 ) ;
F_98 ( V_329 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_327 ) {
F_5 ( L_20 , * V_327 ) ;
goto V_331;
}
V_2 . V_22 -> V_79 -= * V_327 ;
if ( V_314 ) {
V_2 . V_22 -> V_80 ++ ;
* V_328 = V_2 . V_22 -> V_165 ++ ;
if ( * V_328 == 0 )
* V_328 = V_2 . V_22 -> V_165 ++ ;
}
F_116 ( V_2 . V_22 -> V_111 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_2 . V_22 -> V_139 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_164 ( V_75 , 0 , - ( T_9 ) * V_327 , V_314 ? 1 : 0 ) ;
if ( V_314 )
F_165 ( V_75 , V_44 , * V_327 ) ;
F_166 ( V_91 , * V_327 , V_91 -> V_92 . V_336 , V_91 -> V_92 . V_337 ) ;
V_2 . V_22 -> V_184 -= * V_327 ;
F_167 ( V_91 , V_2 . V_22 , V_44 , * V_327 ,
V_314 ? V_316 : V_317 ) ;
* V_326 = V_44 ;
return 0 ;
V_331:
F_156 ( V_2 . V_22 ) ;
return - V_119 ;
}
void F_168 ( struct V_90 * V_91 , T_2 V_318 , T_4 V_319 , int V_338 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_69 * V_22 ;
V_22 = F_152 ( V_75 , V_318 , V_319 , V_61 ) ;
if ( ! V_22 )
return;
F_167 ( V_91 , V_22 , V_318 , V_319 , V_61 ) ;
V_22 -> V_79 += V_319 ;
V_22 -> V_143 &= ~ V_231 ;
F_116 ( V_22 -> V_111 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 -> V_139 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_338 || V_91 -> V_339 )
F_169 ( V_91 , V_318 , V_319 ) ;
}
void F_170 ( struct V_90 * V_91 , T_2 V_318 , T_4 V_319 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
F_168 ( V_91 , V_318 , V_319 , 1 ) ;
F_164 ( V_75 , 0 , + V_319 , 0 ) ;
F_166 ( V_91 , - ( T_9 ) V_319 , V_91 -> V_92 . V_336 , V_91 -> V_92 . V_337 ) ;
}
void F_171 ( struct V_121 * V_121 )
{
struct V_90 * V_91 = F_64 ( V_121 ) ;
struct V_74 * V_75 = F_35 ( V_121 ) ;
struct V_69 * V_22 ;
T_2 V_340 = V_91 -> V_94 ;
V_22 = F_152 ( V_75 , V_340 , 1 , V_179 ) ;
if ( ! V_22 )
return;
F_167 ( V_91 , V_22 , V_340 , 1 , V_179 ) ;
F_116 ( V_22 -> V_111 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 -> V_139 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_90 ( V_22 , 1 ) ;
}
static void F_172 ( struct V_69 * V_22 , T_2 V_340 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_341 ;
V_341 = F_152 ( V_75 , V_340 , 1 , V_61 ) ;
if ( ! V_341 )
return;
F_173 ( V_75 , V_22 == V_341 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_116 ( V_22 -> V_111 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_85 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 -> V_139 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_90 ( V_22 , - 1 ) ;
F_164 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_174 ( struct V_69 * V_22 , struct V_90 * V_91 )
{
F_172 ( V_22 , V_91 -> V_94 ) ;
F_167 ( V_91 , V_22 , V_91 -> V_94 , 1 , V_61 ) ;
F_166 ( V_91 , - 1 , V_91 -> V_92 . V_336 , V_91 -> V_92 . V_337 ) ;
F_169 ( V_91 , V_91 -> V_94 , 1 ) ;
}
int F_175 ( struct V_74 * V_75 , T_2 V_342 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_156 V_343 ;
int error = - V_48 ;
V_22 = F_26 ( V_75 , V_342 , 1 ) ;
if ( ! V_22 )
goto V_136;
error = F_82 ( V_22 -> V_111 , V_159 , 0 , & V_343 ) ;
if ( error )
goto V_136;
if ( F_150 ( V_22 , V_342 ) != type )
error = - V_344 ;
F_83 ( & V_343 ) ;
V_136:
return error ;
}
void F_176 ( struct V_90 * V_91 , struct V_345 * V_346 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_347 ;
unsigned int V_77 ;
if ( F_99 ( V_75 , ! V_346 -> V_348 ) )
return;
if ( V_91 -> V_301 && F_123 ( V_91 -> V_301 , V_44 ) )
V_22 = V_91 -> V_301 ;
else
V_22 = F_26 ( V_75 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_25 ( V_75 , L_21 , ( unsigned long long ) V_44 ) ;
return;
}
V_91 -> V_301 = V_22 ;
for ( V_77 = 0 ; V_77 < V_346 -> V_349 ; V_77 ++ )
if ( V_346 -> V_350 [ V_77 ] == V_22 )
return;
if ( V_346 -> V_349 == V_346 -> V_351 ) {
V_347 = V_346 -> V_351 + 10 ;
V_31 = F_62 ( V_347 , sizeof( struct V_69 * ) ,
V_115 | V_321 ) ;
if ( V_346 -> V_350 ) {
memcpy ( V_31 , V_346 -> V_350 ,
V_346 -> V_351 * sizeof( struct V_69 * ) ) ;
F_37 ( V_346 -> V_350 ) ;
}
V_346 -> V_351 = V_347 ;
V_346 -> V_350 = V_31 ;
}
V_346 -> V_350 [ V_346 -> V_349 ++ ] = V_22 ;
}
void F_177 ( struct V_345 * V_346 , unsigned int V_30 )
{
unsigned int V_77 ;
V_346 -> V_348 = F_154 ( V_346 -> V_349 * sizeof( struct V_156 ) ,
V_115 | V_321 ) ;
for ( V_77 = 0 ; V_77 < V_346 -> V_349 ; V_77 ++ )
F_178 ( V_346 -> V_350 [ V_77 ] -> V_111 ,
V_30 , 0 ,
& V_346 -> V_348 [ V_77 ] ) ;
}
void F_179 ( struct V_345 * V_346 )
{
unsigned int V_77 ;
F_37 ( V_346 -> V_350 ) ;
if ( V_346 -> V_348 ) {
for ( V_77 = 0 ; V_77 < V_346 -> V_349 ; V_77 ++ )
F_180 ( & V_346 -> V_348 [ V_77 ] ) ;
F_37 ( V_346 -> V_348 ) ;
V_346 -> V_348 = NULL ;
}
}
