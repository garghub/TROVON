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
F_27 ( & V_110 -> V_112 . V_113 ) ;
V_110 -> V_114 = NULL ;
F_29 ( & V_110 -> V_112 . V_113 ) ;
F_56 ( V_110 ) ;
F_57 ( V_110 ) ;
}
F_36 ( V_22 ) ;
F_37 ( V_22 -> V_78 ) ;
V_22 -> V_78 = NULL ;
F_54 ( V_22 ) ;
F_58 ( V_115 , V_22 ) ;
}
}
static void F_59 ( const struct V_69 * V_22 )
{
F_60 ( L_8 , ( unsigned long long ) V_22 -> V_23 ) ;
F_60 ( L_9 , V_22 -> V_57 ) ;
F_60 ( L_10 , ( unsigned long long ) V_22 -> V_46 ) ;
F_60 ( L_11 , V_22 -> V_49 ) ;
F_60 ( L_12 , V_22 -> V_116 ) ;
}
static int F_61 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_117 , V_64 ;
int V_77 ;
if ( ! V_76 )
return - V_48 ;
V_22 -> V_78 = F_62 ( V_76 , sizeof( struct V_9 ) , V_118 ) ;
if ( ! V_22 -> V_78 )
return - V_119 ;
V_117 = V_22 -> V_116 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
V_10 -> V_104 = 0 ;
if ( V_76 == 1 ) {
V_64 = V_117 ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 == 0 ) {
V_64 = V_75 -> V_120 . V_121 - sizeof( struct V_53 ) ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 + 1 == V_76 ) {
V_64 = V_117 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_116 - V_117 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else {
V_64 = V_75 -> V_120 . V_121 -
sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_116 - V_117 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
}
V_117 -= V_64 ;
}
if ( V_117 ) {
F_7 ( V_22 ) ;
return - V_122 ;
}
V_10 = V_22 -> V_78 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_12 ) * V_15 != V_22 -> V_49 ) {
if ( F_7 ( V_22 ) ) {
F_59 ( V_22 ) ;
F_25 ( V_75 , L_13 ,
V_10 -> V_24 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_122 ;
}
return 0 ;
}
T_2 F_63 ( struct V_74 * V_75 )
{
T_2 V_123 = 0 ;
struct V_124 * V_124 = V_75 -> V_125 ;
struct V_90 * V_91 = F_64 ( V_124 ) ;
char V_40 [ sizeof( struct V_126 ) ] ;
int error , V_127 ;
for ( V_127 = 0 ; ; V_127 ++ ) {
T_6 V_128 = V_127 * sizeof( struct V_126 ) ;
if ( V_128 + sizeof( struct V_126 ) > F_65 ( V_124 ) )
break;
error = F_66 ( V_91 , V_40 , & V_128 ,
sizeof( struct V_126 ) ) ;
if ( error != sizeof( struct V_126 ) )
break;
V_123 += F_67 ( ( (struct V_126 * ) V_40 ) -> V_129 ) ;
}
return V_123 ;
}
static int F_68 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_82 * * V_130 = & V_75 -> V_86 . V_82 , * V_131 = NULL ;
while ( * V_130 ) {
struct V_69 * V_84 = F_28 ( * V_130 , struct V_69 ,
V_87 ) ;
V_131 = * V_130 ;
if ( V_22 -> V_23 < V_84 -> V_23 )
V_130 = & ( ( * V_130 ) -> V_88 ) ;
else if ( V_22 -> V_23 > V_84 -> V_23 )
V_130 = & ( ( * V_130 ) -> V_89 ) ;
else
return - V_132 ;
}
F_69 ( & V_22 -> V_87 , V_131 , V_130 ) ;
F_70 ( & V_22 -> V_87 , & V_75 -> V_86 ) ;
V_75 -> V_133 ++ ;
return 0 ;
}
static int F_71 ( struct V_90 * V_91 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
const unsigned V_134 = V_75 -> V_120 . V_121 ;
T_6 V_128 = V_75 -> V_133 * sizeof( struct V_126 ) ;
struct V_126 V_40 ;
int error ;
struct V_69 * V_22 ;
if ( V_128 >= F_65 ( & V_91 -> V_92 ) )
return 1 ;
error = F_66 ( V_91 , ( char * ) & V_40 , & V_128 ,
sizeof( struct V_126 ) ) ;
if ( error != sizeof( struct V_126 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_72 ( V_115 , V_118 ) ;
error = - V_119 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_75 ;
V_22 -> V_23 = F_73 ( V_40 . V_135 ) ;
V_22 -> V_57 = F_67 ( V_40 . V_136 ) ;
V_22 -> V_46 = F_73 ( V_40 . V_137 ) ;
V_22 -> V_49 = F_67 ( V_40 . V_129 ) ;
V_22 -> V_116 = F_67 ( V_40 . V_138 ) ;
F_74 ( & V_22 -> V_105 ) ;
error = F_61 ( V_22 ) ;
if ( error )
goto V_139;
error = F_75 ( V_75 , V_22 -> V_23 ,
& V_140 , V_141 , & V_22 -> V_111 ) ;
if ( error )
goto V_139;
V_22 -> V_142 = (struct V_143 * ) V_22 -> V_111 -> V_144 . V_145 ;
V_22 -> V_146 &= ~ ( V_147 | V_148 ) ;
if ( V_22 -> V_49 > V_75 -> V_149 )
V_75 -> V_149 = V_22 -> V_49 ;
F_27 ( & V_75 -> V_85 ) ;
error = F_68 ( V_22 ) ;
F_29 ( & V_75 -> V_85 ) ;
if ( ! error ) {
V_22 -> V_111 -> V_114 = V_22 ;
V_22 -> V_111 -> V_150 . V_66 = ( V_22 -> V_23 * V_134 ) & V_151 ;
V_22 -> V_111 -> V_150 . V_7 = F_76 ( ( V_22 -> V_23 +
V_22 -> V_57 ) * V_134 ) - 1 ;
return 0 ;
}
error = 0 ;
F_57 ( V_22 -> V_111 ) ;
V_139:
F_37 ( V_22 -> V_78 ) ;
V_22 -> V_78 = NULL ;
F_58 ( V_115 , V_22 ) ;
return error ;
}
static void F_77 ( struct V_74 * V_75 )
{
struct V_69 * V_22 , * V_152 ;
int V_153 ;
V_22 = F_30 ( V_75 ) ;
for ( V_153 = 0 ; V_153 < V_75 -> V_154 . V_155 ; V_153 ++ )
V_22 = F_32 ( V_22 ) ;
V_152 = V_22 ;
do {
V_22 -> V_146 |= V_148 ;
for ( V_153 = 0 ; V_153 < V_75 -> V_156 ; V_153 ++ ) {
V_22 = F_32 ( V_22 ) ;
if ( ! V_22 || V_22 == V_152 )
break;
}
} while ( V_22 && V_22 != V_152 );
}
static int F_78 ( struct V_90 * V_91 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
int error ;
do {
error = F_71 ( V_91 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
F_77 ( V_75 ) ;
V_75 -> V_157 = 1 ;
return 0 ;
}
int F_79 ( struct V_74 * V_75 )
{
struct V_90 * V_91 = F_64 ( V_75 -> V_125 ) ;
struct V_109 * V_110 = V_91 -> V_158 ;
struct V_159 V_160 ;
int error = 0 ;
int V_161 = 0 ;
if ( ! V_75 -> V_157 ) {
if ( ! F_80 ( V_110 ) ) {
error = F_81 ( V_110 , V_162 , 0 , & V_160 ) ;
if ( error )
return error ;
V_161 = 1 ;
}
if ( ! V_75 -> V_157 )
error = F_78 ( V_91 ) ;
if ( V_161 )
F_82 ( & V_160 ) ;
}
return error ;
}
static void F_83 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_163 = V_40 ;
T_4 V_164 ;
V_164 = F_67 ( V_163 -> V_164 ) ;
V_164 &= ~ V_165 ;
V_22 -> V_146 &= V_165 ;
V_22 -> V_146 |= V_164 ;
V_22 -> V_79 = F_67 ( V_163 -> V_166 ) ;
V_22 -> V_80 = F_67 ( V_163 -> V_167 ) ;
V_22 -> V_168 = F_73 ( V_163 -> V_169 ) ;
}
static void F_84 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_163 = V_40 ;
V_163 -> V_164 = F_85 ( V_22 -> V_146 & ~ V_165 ) ;
V_163 -> V_166 = F_85 ( V_22 -> V_79 ) ;
V_163 -> V_167 = F_85 ( V_22 -> V_80 ) ;
V_163 -> V_170 = F_85 ( 0 ) ;
V_163 -> V_169 = F_86 ( V_22 -> V_168 ) ;
memset ( & V_163 -> V_171 , 0 , sizeof( V_163 -> V_171 ) ) ;
}
static int F_87 ( struct V_69 * V_22 )
{
struct V_143 * V_172 = V_22 -> V_142 ;
struct V_53 * V_163 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_172 -> V_173 != V_163 -> V_164 || V_172 -> V_174 != V_163 -> V_166 ||
V_172 -> V_175 != V_163 -> V_167 ||
V_172 -> V_176 != V_163 -> V_169 )
return 0 ;
return 1 ;
}
static void F_88 ( struct V_143 * V_172 , const void * V_40 )
{
const struct V_53 * V_163 = V_40 ;
V_172 -> V_177 = F_85 ( V_178 ) ;
V_172 -> V_173 = V_163 -> V_164 ;
V_172 -> V_174 = V_163 -> V_166 ;
V_172 -> V_175 = V_163 -> V_167 ;
V_172 -> V_176 = V_163 -> V_169 ;
V_172 -> V_170 = 0UL ;
}
static void F_89 ( struct V_69 * V_22 , T_4 V_179 )
{
struct V_143 * V_172 = V_22 -> V_142 ;
T_4 V_180 = F_67 ( V_172 -> V_181 ) + V_179 ;
V_172 -> V_181 = F_85 ( V_180 ) ;
}
static T_4 F_90 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_153 , V_41 , V_73 = 0 ;
for ( V_153 = 0 , V_10 = V_22 -> V_78 ; V_153 < V_76 ; V_153 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_91 ( ! F_92 ( V_10 -> V_17 ) ) ;
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
static int F_93 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_109 * V_110 = V_22 -> V_111 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_183 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_94 ( V_110 , V_22 -> V_23 + V_77 , 0 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_139;
}
for ( V_183 = V_76 ; V_183 -- ; ) {
V_10 = V_22 -> V_78 + V_183 ;
error = F_95 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_139;
if ( F_96 ( V_75 , V_10 -> V_17 , V_183 ? V_184 :
V_185 ) ) {
error = - V_122 ;
goto V_139;
}
}
if ( ! ( V_22 -> V_146 & V_147 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_47 ( V_103 , & V_22 -> V_78 [ V_77 ] . V_104 ) ;
F_83 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_146 |= ( V_147 | V_186 ) ;
V_22 -> V_187 = V_22 -> V_79 ;
V_22 -> V_102 = V_22 -> V_79 ;
}
if ( F_85 ( V_178 ) != V_22 -> V_142 -> V_177 ) {
V_22 -> V_142 -> V_181 = F_85 ( F_90 ( V_22 ) ) ;
F_88 ( V_22 -> V_142 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_188 . V_189 ) {
if ( ! F_87 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_122 ;
goto V_139;
}
if ( V_22 -> V_142 -> V_181 == 0 )
V_22 -> V_146 &= ~ V_186 ;
}
return 0 ;
V_139:
while ( V_77 -- ) {
V_10 = V_22 -> V_78 + V_77 ;
F_97 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_98 ( V_75 , ! V_10 -> V_25 ) ;
}
return error ;
}
static int F_99 ( struct V_69 * V_22 )
{
T_4 V_173 ;
if ( V_22 -> V_146 & V_147 )
return 0 ;
if ( F_85 ( V_178 ) != V_22 -> V_142 -> V_177 )
return F_93 ( V_22 ) ;
V_173 = F_67 ( V_22 -> V_142 -> V_173 ) ;
V_173 &= ~ V_165 ;
V_22 -> V_146 &= V_165 ;
V_22 -> V_146 |= ( V_173 | V_147 | V_186 ) ;
if ( V_22 -> V_142 -> V_181 == 0 )
V_22 -> V_146 &= ~ V_186 ;
V_22 -> V_79 = F_67 ( V_22 -> V_142 -> V_174 ) ;
V_22 -> V_187 = V_22 -> V_79 ;
V_22 -> V_80 = F_67 ( V_22 -> V_142 -> V_175 ) ;
V_22 -> V_168 = F_73 ( V_22 -> V_142 -> V_176 ) ;
return 0 ;
}
int F_100 ( struct V_159 * V_190 )
{
struct V_69 * V_22 = V_190 -> V_191 -> V_114 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_190 -> V_192 & V_193 && V_75 -> V_188 . V_189 )
return 0 ;
return F_93 ( V_22 ) ;
}
void F_101 ( struct V_69 * V_22 )
{
int V_77 , V_76 = V_22 -> V_57 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
if ( V_10 -> V_17 ) {
F_97 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
void F_102 ( struct V_159 * V_190 )
{
struct V_69 * V_22 = V_190 -> V_191 -> V_114 ;
int V_194 = F_103 ( V_195 , & V_190 -> V_191 -> V_196 ) |
F_103 ( V_197 , & V_190 -> V_191 -> V_196 ) ;
if ( V_22 && V_194 )
F_101 ( V_22 ) ;
}
int F_104 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_198 * V_199 ,
const struct V_9 * V_10 , unsigned V_200 , T_2 * V_201 )
{
struct V_202 * V_203 = V_75 -> V_204 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_205 = 0 ;
int V_206 ;
unsigned int V_77 ;
T_4 V_207 = 0 ;
T_1 V_208 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_209 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_209 += V_10 -> V_19 ;
V_209 += V_77 ;
if ( V_199 ) {
const T_1 * V_210 = V_199 -> V_18 + V_10 -> V_19 + V_77 ;
V_208 = ~ ( * V_210 | ( * V_210 >> 1 ) ) & ( * V_209 | ( * V_209 >> 1 ) ) ;
} else {
V_208 = ~ ( * V_209 | ( * V_209 >> 1 ) ) ;
}
V_208 &= 0x55 ;
if ( V_208 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_208 ) {
if ( V_208 & 1 ) {
if ( V_205 == 0 )
goto V_211;
if ( ( V_66 + V_205 ) != V_33 ) {
if ( V_205 >= V_200 ) {
V_206 = F_105 ( V_203 ,
V_66 , V_205 ,
V_118 , 0 ) ;
if ( V_206 )
goto V_139;
V_207 += V_205 ;
}
V_205 = 0 ;
V_211:
V_66 = V_33 ;
}
V_205 ++ ;
}
V_208 >>= 2 ;
V_33 ++ ;
}
}
if ( V_205 >= V_200 ) {
V_206 = F_105 ( V_203 , V_66 , V_205 , V_118 , 0 ) ;
if ( V_206 )
goto V_139;
V_207 += V_205 ;
}
if ( V_201 )
* V_201 = V_207 ;
return 0 ;
V_139:
if ( V_75 -> V_188 . V_212 )
F_106 ( V_75 , L_14 , V_206 ) ;
V_75 -> V_188 . V_212 = 0 ;
return - V_122 ;
}
int F_107 ( struct V_213 * V_214 , void T_8 * V_215 )
{
struct V_124 * V_124 = F_108 ( V_214 ) ;
struct V_74 * V_75 = F_35 ( V_124 ) ;
struct V_216 * V_217 = F_109 ( V_75 -> V_204 -> V_218 ) ;
struct V_198 * V_199 ;
struct V_69 * V_22 ;
struct V_69 * V_219 ;
struct V_159 V_190 ;
struct V_220 V_221 ;
int V_222 = 0 ;
T_2 V_223 ;
T_2 V_207 = 0 ;
T_2 V_66 , V_7 , V_200 ;
unsigned int V_77 ;
unsigned V_224 = V_75 -> V_120 . V_225 ;
if ( ! F_110 ( V_226 ) )
return - V_227 ;
if ( ! F_111 ( V_217 ) )
return - V_228 ;
if ( F_112 ( & V_221 , V_215 , sizeof( V_221 ) ) )
return - V_229 ;
V_222 = F_79 ( V_75 ) ;
if ( V_222 )
return V_222 ;
V_66 = V_221 . V_66 >> V_224 ;
V_7 = V_66 + ( V_221 . V_34 >> V_224 ) ;
V_200 = F_113 ( T_2 , V_221 . V_200 ,
V_217 -> V_230 . V_231 ) >> V_224 ;
if ( V_7 <= V_66 || V_200 > V_75 -> V_149 )
return - V_48 ;
V_22 = F_26 ( V_75 , V_66 , 0 ) ;
V_219 = F_26 ( V_75 , V_7 , 0 ) ;
if ( ( F_30 ( V_75 ) == F_32 ( V_219 ) )
&& ( V_66 > V_219 -> V_46 + V_219 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_222 = F_81 ( V_22 -> V_111 , V_232 , 0 , & V_190 ) ;
if ( V_222 )
goto V_67;
if ( ! ( V_22 -> V_146 & V_233 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_222 = F_104 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_200 ,
& V_223 ) ;
if ( V_222 ) {
F_82 ( & V_190 ) ;
goto V_67;
}
V_207 += V_223 ;
}
V_222 = F_114 ( V_75 , V_234 , 0 ) ;
if ( V_222 == 0 ) {
V_199 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_146 |= V_233 ;
F_115 ( V_22 -> V_111 , V_199 ) ;
F_84 ( V_22 , V_199 -> V_18 ) ;
F_88 ( V_22 -> V_142 , V_199 -> V_18 ) ;
F_116 ( V_75 ) ;
}
}
F_82 ( & V_190 ) ;
if ( V_22 == V_219 )
break;
V_22 = F_32 ( V_22 ) ;
}
V_67:
V_221 . V_34 = V_207 << V_224 ;
if ( F_117 ( V_215 , & V_221 , sizeof( V_221 ) ) )
return - V_229 ;
return V_222 ;
}
static void F_118 ( struct V_90 * V_91 )
{
struct V_82 * * V_130 , * V_131 = NULL ;
int V_235 ;
struct V_35 * V_36 = & V_91 -> V_108 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_236 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_43 ( V_36 ) ) ;
F_27 ( & V_22 -> V_105 ) ;
V_130 = & V_22 -> V_100 . V_82 ;
while ( * V_130 ) {
struct V_35 * V_84 =
F_28 ( * V_130 , struct V_35 , V_99 ) ;
V_131 = * V_130 ;
V_235 = F_11 ( V_236 , V_36 -> V_39 , V_84 ) ;
if ( V_235 > 0 )
V_130 = & ( ( * V_130 ) -> V_89 ) ;
else if ( V_235 < 0 )
V_130 = & ( ( * V_130 ) -> V_88 ) ;
else {
F_29 ( & V_22 -> V_105 ) ;
F_91 ( 1 ) ;
return;
}
}
F_69 ( & V_36 -> V_99 , V_131 , V_130 ) ;
F_70 ( & V_36 -> V_99 , & V_22 -> V_100 ) ;
V_22 -> V_101 += V_36 -> V_39 ;
F_29 ( & V_22 -> V_105 ) ;
F_44 ( V_36 , V_237 ) ;
}
static void F_119 ( struct V_69 * V_22 , struct V_90 * V_91 ,
const struct V_238 * V_239 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = & V_91 -> V_108 ;
T_4 V_240 ;
T_4 V_241 = V_22 -> V_187 - V_22 -> V_101 ;
int V_222 ;
struct V_124 * V_124 = & V_91 -> V_92 ;
if ( F_120 ( V_124 -> V_242 ) )
V_240 = 1 ;
else {
V_240 = F_113 ( T_4 , F_51 ( & V_36 -> V_243 ) , V_239 -> V_244 ) ;
V_240 = F_121 ( V_240 , V_245 , V_241 ) ;
}
if ( ( V_22 -> V_187 < V_22 -> V_101 ) || ( V_241 < V_240 ) )
return;
if ( F_122 ( V_22 , V_91 -> V_93 ) )
V_41 = V_91 -> V_93 ;
else
V_41 = V_22 -> V_246 + V_22 -> V_46 ;
if ( F_91 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_222 = F_123 ( & V_2 , V_61 , & V_240 , V_91 , true ) ;
if ( V_222 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_240 ;
V_36 -> V_97 = V_91 -> V_94 ;
F_118 ( V_91 ) ;
} else {
if ( V_41 == V_22 -> V_246 + V_22 -> V_46 )
V_22 -> V_246 = 0 ;
}
}
static T_2 F_124 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_90 * V_91 )
{
struct V_35 * V_36 ;
struct V_82 * V_59 ;
int V_235 ;
F_27 ( & V_22 -> V_105 ) ;
V_59 = V_22 -> V_100 . V_82 ;
while ( V_59 ) {
V_36 = F_28 ( V_59 , struct V_35 , V_99 ) ;
V_235 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_235 < 0 )
V_59 = V_59 -> V_88 ;
else if ( V_235 > 0 )
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
static int F_125 ( struct V_1 * V_2 ,
const struct V_90 * V_91 ,
T_4 V_247 ,
struct V_248 * V_249 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_240 = 1 ;
T_2 V_250 ;
int V_222 ;
if ( V_247 ) {
V_240 = F_20 ( V_2 , V_247 ) ;
if ( V_240 <= V_249 -> V_34 )
goto V_139;
}
V_250 = F_124 ( V_2 -> V_22 , V_44 , V_240 , V_91 ) ;
if ( V_250 == V_44 ) {
if ( ! V_247 || V_240 >= V_247 )
return 0 ;
if ( V_240 > V_249 -> V_34 ) {
V_249 -> V_34 = V_240 ;
V_249 -> V_2 = * V_2 ;
}
V_139:
V_250 = V_44 + V_240 ;
}
V_222 = F_16 ( V_2 , V_250 ) ;
if ( V_222 < 0 )
return V_222 ;
return 1 ;
}
static int F_123 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_247 ,
const struct V_90 * V_91 , bool V_251 )
{
struct V_198 * V_199 ;
int V_252 ;
T_4 V_253 ;
int V_254 = V_2 -> V_51 ;
T_4 V_255 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_256 = V_2 -> V_22 -> V_57 ;
int V_222 ;
struct V_9 * V_10 ;
struct V_248 V_249 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_256 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_103 ( V_103 , & V_10 -> V_104 ) &&
( V_30 == V_61 ) )
goto V_257;
V_199 = V_10 -> V_17 ;
V_26 = V_199 -> V_18 + V_10 -> V_19 ;
F_91 ( ! F_92 ( V_199 ) ) ;
if ( V_30 != V_182 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_253 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_258;
V_2 -> V_14 = V_14 ;
if ( V_91 == NULL )
return 0 ;
V_252 = V_2 -> V_51 ;
V_222 = F_125 ( V_2 , V_91 ,
V_247 ? * V_247 : 0 ,
& V_249 ) ;
if ( V_222 == 0 )
return 0 ;
if ( V_222 > 0 ) {
V_59 += ( V_2 -> V_51 - V_252 ) ;
goto V_259;
}
if ( V_222 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_252 ) ;
goto V_260;
}
return V_222 ;
V_258:
if ( ( V_30 == V_61 ) && V_253 == 0 )
F_126 ( V_103 , & V_10 -> V_104 ) ;
V_257:
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 )
V_2 -> V_51 = 0 ;
V_260:
if ( ( V_2 -> V_51 == 0 ) && V_251 )
break;
V_59 ++ ;
V_259:
if ( V_59 >= V_256 )
break;
}
if ( V_247 == NULL || V_30 != V_61 )
return - V_261 ;
if ( ( V_255 == 0 ) && ( V_254 == 0 ) &&
( * V_247 < V_2 -> V_22 -> V_102 ) )
V_2 -> V_22 -> V_102 = * V_247 ;
if ( V_249 . V_34 ) {
* V_2 = V_249 . V_2 ;
* V_247 = V_249 . V_34 ;
return 0 ;
}
return - V_261 ;
}
static void F_127 ( struct V_69 * V_22 , T_2 * V_262 , T_2 V_263 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_109 * V_110 ;
struct V_90 * V_91 ;
int error ;
int V_264 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_50 ( & V_75 -> V_265 ) ;
error = F_123 ( & V_2 , V_182 , NULL , NULL ,
true ) ;
F_52 ( & V_75 -> V_265 ) ;
if ( error == - V_261 )
break;
if ( F_17 ( error ) )
break;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_262 != V_266 && V_44 <= * V_262 )
continue;
if ( V_44 == V_263 )
continue;
* V_262 = V_44 ;
error = F_75 ( V_75 , V_44 , & V_267 , V_141 , & V_110 ) ;
if ( error )
continue;
V_91 = V_110 -> V_114 ;
if ( V_91 || F_128 ( V_268 , & V_110 -> V_269 ) == 0 )
F_57 ( V_110 ) ;
else
V_264 ++ ;
if ( V_264 > V_270 )
return;
}
V_22 -> V_146 &= ~ V_186 ;
return;
}
static bool F_129 ( const struct V_69 * V_22 , int V_271 )
{
const struct V_109 * V_110 = V_22 -> V_111 ;
const struct V_74 * V_75 = V_110 -> V_272 . V_273 ;
struct V_274 * V_275 ;
T_2 V_276 , V_277 ;
T_2 V_278 , V_279 = 0 ;
T_9 V_280 ;
T_2 V_281 ;
T_2 V_282 ;
int V_283 , V_284 = 0 ;
F_130 () ;
F_131 (cpu) {
V_275 = & F_132 ( V_75 -> V_285 , V_283 ) -> V_286 [ V_287 ] ;
if ( V_275 -> V_288 [ V_289 ] ) {
V_279 += V_275 -> V_288 [ V_289 ] ;
V_284 ++ ;
}
}
V_275 = & F_133 ( V_75 -> V_285 ) -> V_286 [ V_287 ] ;
if ( V_284 )
F_134 ( V_279 , V_284 ) ;
V_276 = V_275 -> V_288 [ V_290 ] ;
V_282 = V_275 -> V_288 [ V_291 ] +
V_110 -> V_292 . V_288 [ V_291 ] ;
F_135 () ;
V_278 = V_110 -> V_292 . V_288 [ V_289 ] ;
V_277 = V_110 -> V_292 . V_288 [ V_290 ] ;
if ( ( V_277 < 1 ) || ( V_276 < 1 ) || ( V_279 == 0 ) )
return false ;
V_280 = V_279 - V_278 ;
V_281 = V_280 * V_280 ;
V_282 *= 2 ;
if ( V_277 < 8 || V_276 < 8 )
V_282 *= 2 ;
if ( V_271 == 1 )
V_282 *= 2 ;
return ( ( V_280 < 0 ) && ( V_281 > V_282 ) ) ;
}
static bool F_136 ( const struct V_35 * V_36 ,
T_2 V_293 )
{
T_2 V_294 ;
V_294 = F_137 ( F_138 ( F_139 () ,
V_36 -> V_38 . V_22 -> V_111 -> V_295 ) ) ;
return V_294 > ( V_293 * 1000 * 1000 ) ;
}
static T_4 F_140 ( const struct V_90 * V_91 )
{
const struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
T_4 V_263 ;
F_141 ( & V_263 , sizeof( V_263 ) ) ;
return V_263 % V_75 -> V_133 ;
}
static bool F_142 ( struct V_69 * * V_128 , const struct V_69 * V_296 )
{
struct V_69 * V_22 = * V_128 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_32 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_30 ( V_75 ) ;
* V_128 = V_22 ;
if ( V_22 != V_296 )
return true ;
return false ;
}
static inline int F_143 ( struct V_69 * V_22 )
{
struct V_109 * V_110 = V_22 -> V_111 ;
if ( V_110 -> V_297 != V_298 && F_144 ( & V_110 -> V_299 ) &&
! F_103 ( V_300 , & V_110 -> V_196 ) &&
! F_103 ( V_195 , & V_110 -> V_196 ) )
return 1 ;
if ( V_22 -> V_146 & V_148 )
return 1 ;
return 0 ;
}
int F_145 ( struct V_90 * V_91 , struct V_238 * V_239 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_69 * V_296 = NULL ;
struct V_35 * V_36 = & V_91 -> V_108 ;
int error = 0 , V_301 , V_302 = 0 ;
T_2 V_262 = V_266 ;
int V_271 = 0 ;
T_4 V_263 = 0 ;
if ( V_75 -> V_188 . V_189 )
V_302 |= V_193 ;
if ( F_98 ( V_75 , V_239 -> V_244 ) )
return - V_48 ;
if ( F_43 ( V_36 ) ) {
V_296 = V_36 -> V_38 . V_22 ;
} else if ( V_91 -> V_303 && F_122 ( V_91 -> V_303 , V_91 -> V_93 ) ) {
V_36 -> V_38 . V_22 = V_296 = V_91 -> V_303 ;
} else {
F_34 ( V_91 ) ;
V_36 -> V_38 . V_22 = V_296 = F_26 ( V_75 , V_91 -> V_93 , 1 ) ;
}
if ( F_120 ( V_91 -> V_92 . V_242 ) && ( V_239 -> V_304 & V_305 ) )
V_263 = F_140 ( V_91 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_306 ;
while ( V_271 < 3 ) {
V_301 = 1 ;
if ( ! F_80 ( V_36 -> V_38 . V_22 -> V_111 ) ) {
V_301 = 0 ;
if ( V_263 && V_263 -- )
goto V_307;
if ( ! F_43 ( V_36 ) ) {
if ( V_271 == 0 &&
! F_143 ( V_36 -> V_38 . V_22 ) )
goto V_307;
if ( ( V_271 < 2 ) &&
F_136 ( V_36 , 1000 ) &&
F_129 ( V_36 -> V_38 . V_22 , V_271 ) )
goto V_307;
}
error = F_81 ( V_36 -> V_38 . V_22 -> V_111 ,
V_232 , V_302 ,
& V_36 -> V_308 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_43 ( V_36 ) && ( V_271 < 2 ) &&
F_129 ( V_36 -> V_38 . V_22 , V_271 ) )
goto V_309;
if ( V_75 -> V_188 . V_189 ) {
error = F_99 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_82 ( & V_36 -> V_308 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_146 & ( V_310 |
V_311 ) ) ||
( V_271 == 0 && V_239 -> V_244 > V_36 -> V_38 . V_22 -> V_102 ) )
goto V_309;
if ( V_75 -> V_188 . V_189 )
F_93 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_43 ( V_36 ) )
F_119 ( V_36 -> V_38 . V_22 , V_91 , V_239 ) ;
if ( ! F_43 ( V_36 ) && ( V_271 < 1 ) )
goto V_312;
if ( V_36 -> V_38 . V_22 -> V_187 >= V_239 -> V_244 ||
( V_271 == 2 && V_239 -> V_313 &&
V_36 -> V_38 . V_22 -> V_187 >= V_239 -> V_313 ) ) {
V_91 -> V_303 = V_36 -> V_38 . V_22 ;
V_239 -> V_314 = V_91 -> V_303 -> V_187 ;
return 0 ;
}
V_312:
if ( V_36 -> V_38 . V_22 -> V_146 & V_186 )
F_127 ( V_36 -> V_38 . V_22 , & V_262 ,
V_91 -> V_94 ) ;
V_309:
if ( F_43 ( V_36 ) )
F_48 ( V_36 ) ;
if ( ! V_301 )
F_82 ( & V_36 -> V_308 ) ;
V_307:
if ( F_142 ( & V_36 -> V_38 . V_22 , V_296 ) )
continue;
if ( V_263 )
continue;
V_271 ++ ;
if ( V_91 == F_64 ( V_75 -> V_125 ) && ! V_75 -> V_157 ) {
error = F_78 ( V_91 ) ;
if ( error )
return error ;
}
if ( V_271 == 2 )
F_146 ( V_75 , NULL , V_315 ) ;
}
return - V_261 ;
}
void F_147 ( struct V_90 * V_91 )
{
struct V_35 * V_36 = & V_91 -> V_108 ;
if ( F_148 ( & V_36 -> V_308 ) )
F_82 ( & V_36 -> V_308 ) ;
}
static unsigned char F_149 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_222 ;
V_222 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_222 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_150 ( const struct V_1 * V_2 , bool V_316 ,
unsigned int * V_59 )
{
struct V_1 V_128 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_317 = * V_59 ;
T_2 V_44 ;
int V_222 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_115 ( V_2 -> V_22 -> V_111 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_316 ? V_318 : V_319 ) ;
V_44 ++ ;
while ( * V_59 < V_317 ) {
V_222 = F_16 ( & V_128 , V_44 ) ;
if ( V_222 || F_8 ( & V_128 ) != V_61 )
break;
F_115 ( V_128 . V_22 -> V_111 , F_2 ( & V_128 ) -> V_17 ) ;
F_1 ( & V_128 , true , V_319 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_151 ( struct V_74 * V_75 , T_2 V_320 ,
T_4 V_321 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 , * V_322 = NULL ;
V_2 . V_22 = F_26 ( V_75 , V_320 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_152 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_320 ) ;
return NULL ;
}
F_16 ( & V_2 , V_320 ) ;
while ( V_321 -- ) {
V_10 = F_2 ( & V_2 ) ;
if ( V_10 != V_322 ) {
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_153 ( V_10 -> V_17 -> V_68 ,
V_118 | V_323 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 ,
V_10 -> V_12 ) ;
}
F_115 ( V_2 . V_22 -> V_111 , V_10 -> V_17 ) ;
V_322 = V_10 ;
}
F_1 ( & V_2 , false , V_4 ) ;
F_18 ( & V_2 ) ;
}
return V_2 . V_22 ;
}
void F_154 ( struct V_95 * V_96 , const struct V_109 * V_110 )
{
struct V_69 * V_22 = V_110 -> V_114 ;
struct V_35 * V_324 ;
const struct V_82 * V_59 ;
if ( V_22 == NULL )
return;
F_41 ( V_96 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_146 ,
V_22 -> V_79 , V_22 -> V_187 , V_22 -> V_80 ,
V_22 -> V_101 , V_22 -> V_102 ) ;
F_27 ( & V_22 -> V_105 ) ;
for ( V_59 = F_31 ( & V_22 -> V_100 ) ; V_59 ; V_59 = F_33 ( & V_324 -> V_99 ) ) {
V_324 = F_28 ( V_59 , struct V_35 , V_99 ) ;
F_40 ( V_96 , V_324 ) ;
}
F_29 ( & V_22 -> V_105 ) ;
}
static void F_155 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_106 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_106 ( V_75 , L_18 ) ;
F_154 ( NULL , V_22 -> V_111 ) ;
V_22 -> V_146 |= V_311 ;
}
static void F_156 ( struct V_90 * V_91 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = & V_91 -> V_108 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_325 ;
T_2 V_44 ;
int V_222 ;
F_27 ( & V_22 -> V_105 ) ;
if ( F_43 ( V_36 ) ) {
if ( F_157 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_222 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_325 = F_158 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_325 ;
V_22 -> V_101 -= V_325 ;
F_44 ( V_36 , V_326 ) ;
if ( V_36 -> V_39 && ! V_222 )
goto V_67;
F_159 ( V_327 , & V_36 -> V_243 ) ;
}
F_42 ( V_36 ) ;
}
V_67:
F_29 ( & V_22 -> V_105 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
const struct V_90 * V_91 , bool V_316 )
{
T_2 V_41 ;
if ( F_43 ( & V_91 -> V_108 ) ) {
* V_2 = V_91 -> V_108 . V_38 ;
return;
}
if ( ! V_316 && F_122 ( V_2 -> V_22 , V_91 -> V_93 ) )
V_41 = V_91 -> V_93 ;
else
V_41 = V_2 -> V_22 -> V_246 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_161 ( struct V_90 * V_91 , T_2 * V_328 , unsigned int * V_329 ,
bool V_316 , T_2 * V_330 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_198 * V_331 ;
struct V_1 V_2 = { . V_22 = V_91 -> V_303 , } ;
unsigned int V_332 ;
T_2 V_44 ;
int error ;
F_160 ( & V_2 , V_91 , V_316 ) ;
error = F_123 ( & V_2 , V_61 , NULL , V_91 , false ) ;
if ( error == - V_261 ) {
F_160 ( & V_2 , V_91 , V_316 ) ;
error = F_123 ( & V_2 , V_61 , NULL , NULL , false ) ;
}
if ( error ) {
F_106 ( V_75 , L_19 ,
( unsigned long long ) V_91 -> V_94 , error , * V_329 ,
F_103 ( V_103 , & V_2 . V_22 -> V_78 -> V_104 ) ,
V_2 . V_22 -> V_102 ) ;
goto V_333;
}
F_150 ( & V_2 , V_316 , V_329 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_246 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_43 ( & V_91 -> V_108 ) )
F_156 ( V_91 , & V_2 , * V_329 ) ;
V_332 = * V_329 ;
if ( V_316 )
V_332 -- ;
if ( ! V_316 ) {
V_91 -> V_93 = V_44 + V_332 - 1 ;
error = F_162 ( V_91 , & V_331 ) ;
if ( error == 0 ) {
struct V_334 * V_335 =
(struct V_334 * ) V_331 -> V_18 ;
F_115 ( V_91 -> V_158 , V_331 ) ;
V_335 -> V_336 = V_335 -> V_337 =
F_86 ( V_91 -> V_93 ) ;
F_97 ( V_331 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_329 ) {
F_5 ( L_20 , * V_329 ) ;
goto V_333;
}
V_2 . V_22 -> V_79 -= * V_329 ;
if ( V_316 ) {
V_2 . V_22 -> V_80 ++ ;
* V_330 = V_2 . V_22 -> V_168 ++ ;
if ( * V_330 == 0 )
* V_330 = V_2 . V_22 -> V_168 ++ ;
}
F_115 ( V_2 . V_22 -> V_111 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_84 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_88 ( V_2 . V_22 -> V_142 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_163 ( V_75 , 0 , - ( T_9 ) * V_329 , V_316 ? 1 : 0 ) ;
if ( V_316 )
F_164 ( V_75 , V_44 , * V_329 ) ;
F_165 ( V_91 , * V_329 , V_91 -> V_92 . V_338 , V_91 -> V_92 . V_339 ) ;
V_2 . V_22 -> V_187 -= * V_329 ;
F_166 ( V_91 , V_2 . V_22 , V_44 , * V_329 ,
V_316 ? V_318 : V_319 ) ;
* V_328 = V_44 ;
return 0 ;
V_333:
F_155 ( V_2 . V_22 ) ;
return - V_122 ;
}
void F_167 ( struct V_90 * V_91 , T_2 V_320 , T_4 V_321 , int V_340 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_69 * V_22 ;
V_22 = F_151 ( V_75 , V_320 , V_321 , V_61 ) ;
if ( ! V_22 )
return;
F_166 ( V_91 , V_22 , V_320 , V_321 , V_61 ) ;
V_22 -> V_79 += V_321 ;
V_22 -> V_146 &= ~ V_233 ;
F_115 ( V_22 -> V_111 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_84 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_88 ( V_22 -> V_142 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_340 || V_91 -> V_341 )
F_168 ( V_91 , V_320 , V_321 ) ;
}
void F_169 ( struct V_90 * V_91 , T_2 V_320 , T_4 V_321 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
F_167 ( V_91 , V_320 , V_321 , 1 ) ;
F_163 ( V_75 , 0 , + V_321 , 0 ) ;
F_165 ( V_91 , - ( T_9 ) V_321 , V_91 -> V_92 . V_338 , V_91 -> V_92 . V_339 ) ;
}
void F_170 ( struct V_124 * V_124 )
{
struct V_90 * V_91 = F_64 ( V_124 ) ;
struct V_74 * V_75 = F_35 ( V_124 ) ;
struct V_69 * V_22 ;
T_2 V_342 = V_91 -> V_94 ;
V_22 = F_151 ( V_75 , V_342 , 1 , V_182 ) ;
if ( ! V_22 )
return;
F_166 ( V_91 , V_22 , V_342 , 1 , V_182 ) ;
F_115 ( V_22 -> V_111 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_84 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_88 ( V_22 -> V_142 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 , 1 ) ;
}
static void F_171 ( struct V_69 * V_22 , T_2 V_342 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_343 ;
V_343 = F_151 ( V_75 , V_342 , 1 , V_61 ) ;
if ( ! V_343 )
return;
F_172 ( V_75 , V_22 == V_343 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_115 ( V_22 -> V_111 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_84 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_88 ( V_22 -> V_142 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_89 ( V_22 , - 1 ) ;
F_163 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_173 ( struct V_69 * V_22 , struct V_90 * V_91 )
{
F_171 ( V_22 , V_91 -> V_94 ) ;
F_166 ( V_91 , V_22 , V_91 -> V_94 , 1 , V_61 ) ;
F_165 ( V_91 , - 1 , V_91 -> V_92 . V_338 , V_91 -> V_92 . V_339 ) ;
F_168 ( V_91 , V_91 -> V_94 , 1 ) ;
}
int F_174 ( struct V_74 * V_75 , T_2 V_344 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_159 V_345 ;
int error = - V_48 ;
V_22 = F_26 ( V_75 , V_344 , 1 ) ;
if ( ! V_22 )
goto V_139;
error = F_81 ( V_22 -> V_111 , V_162 , 0 , & V_345 ) ;
if ( error )
goto V_139;
if ( F_149 ( V_22 , V_344 ) != type )
error = - V_346 ;
F_82 ( & V_345 ) ;
V_139:
return error ;
}
void F_175 ( struct V_90 * V_91 , struct V_347 * V_348 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_35 ( & V_91 -> V_92 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_349 ;
unsigned int V_77 ;
if ( F_98 ( V_75 , ! V_348 -> V_350 ) )
return;
if ( V_91 -> V_303 && F_122 ( V_91 -> V_303 , V_44 ) )
V_22 = V_91 -> V_303 ;
else
V_22 = F_26 ( V_75 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_25 ( V_75 , L_21 , ( unsigned long long ) V_44 ) ;
return;
}
V_91 -> V_303 = V_22 ;
for ( V_77 = 0 ; V_77 < V_348 -> V_351 ; V_77 ++ )
if ( V_348 -> V_352 [ V_77 ] == V_22 )
return;
if ( V_348 -> V_351 == V_348 -> V_353 ) {
V_349 = V_348 -> V_353 + 10 ;
V_31 = F_62 ( V_349 , sizeof( struct V_69 * ) ,
V_118 | V_323 ) ;
if ( V_348 -> V_352 ) {
memcpy ( V_31 , V_348 -> V_352 ,
V_348 -> V_353 * sizeof( struct V_69 * ) ) ;
F_37 ( V_348 -> V_352 ) ;
}
V_348 -> V_353 = V_349 ;
V_348 -> V_352 = V_31 ;
}
V_348 -> V_352 [ V_348 -> V_351 ++ ] = V_22 ;
}
void F_176 ( struct V_347 * V_348 , unsigned int V_30 )
{
unsigned int V_77 ;
V_348 -> V_350 = F_153 ( V_348 -> V_351 * sizeof( struct V_159 ) ,
V_118 | V_323 ) ;
for ( V_77 = 0 ; V_77 < V_348 -> V_351 ; V_77 ++ )
F_177 ( V_348 -> V_352 [ V_77 ] -> V_111 ,
V_30 , 0 ,
& V_348 -> V_350 [ V_77 ] ) ;
}
void F_178 ( struct V_347 * V_348 )
{
unsigned int V_77 ;
F_37 ( V_348 -> V_352 ) ;
if ( V_348 -> V_350 ) {
for ( V_77 = 0 ; V_77 < V_348 -> V_351 ; V_77 ++ )
F_179 ( & V_348 -> V_350 [ V_77 ] ) ;
F_37 ( V_348 -> V_350 ) ;
V_348 -> V_350 = NULL ;
}
}
