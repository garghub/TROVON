static inline void F_1 ( const struct V_1 * V_2 , bool V_3 ,
unsigned char V_4 )
{
unsigned char * V_5 , * V_6 , * V_7 , V_8 ;
unsigned int V_9 = V_2 -> V_10 -> V_11 ;
const unsigned int V_12 = ( V_2 -> V_13 % V_14 ) * V_15 ;
V_5 = V_2 -> V_10 -> V_16 -> V_17 + V_2 -> V_10 -> V_18 + ( V_2 -> V_13 / V_14 ) ;
V_7 = V_2 -> V_10 -> V_16 -> V_17 + V_2 -> V_10 -> V_18 + V_9 ;
F_2 ( V_5 >= V_7 ) ;
V_8 = ( * V_5 >> V_12 ) & V_19 ;
if ( F_3 ( ! V_20 [ V_4 * 4 + V_8 ] ) ) {
F_4 ( V_21 L_1
L_2 , V_2 -> V_13 , V_8 , V_4 ) ;
F_4 ( V_21 L_3 ,
( unsigned long long ) V_2 -> V_22 -> V_23 ,
V_2 -> V_10 -> V_24 ) ;
F_4 ( V_21 L_4 ,
V_2 -> V_10 -> V_18 , V_2 -> V_10 -> V_11 ) ;
F_5 () ;
F_6 ( V_2 -> V_22 ) ;
return;
}
* V_5 ^= ( V_8 ^ V_4 ) << V_12 ;
if ( V_3 && V_2 -> V_10 -> V_25 ) {
V_6 = V_2 -> V_10 -> V_25 + V_2 -> V_10 -> V_18 + ( V_2 -> V_13 / V_14 ) ;
V_8 = ( * V_6 >> V_12 ) & V_19 ;
* V_6 ^= ( V_8 ^ V_4 ) << V_12 ;
}
}
static inline T_1 F_7 ( const struct V_1 * V_2 )
{
const T_1 * V_26 = V_2 -> V_10 -> V_16 -> V_17 + V_2 -> V_10 -> V_18 ;
const T_1 * V_27 ;
unsigned int V_12 ;
V_27 = V_26 + ( V_2 -> V_13 / V_14 ) ;
V_12 = ( V_2 -> V_13 % V_14 ) * V_15 ;
return ( * V_27 >> V_12 ) & V_19 ;
}
static inline T_2 F_8 ( const T_3 * V_28 , T_2 V_29 , T_1 V_30 )
{
T_2 V_31 ;
static const T_2 V_32 [] = {
[ 0 ] = 0xffffffffffffffffULL ,
[ 1 ] = 0xaaaaaaaaaaaaaaaaULL ,
[ 2 ] = 0x5555555555555555ULL ,
[ 3 ] = 0x0000000000000000ULL ,
} ;
V_31 = F_9 ( * V_28 ) ^ V_32 [ V_30 ] ;
V_31 &= ( V_31 >> 1 ) ;
V_31 &= V_29 ;
return V_31 ;
}
static inline int F_10 ( T_2 V_33 , T_4 V_34 , struct V_35 * V_36 )
{
T_2 V_37 = F_11 ( & V_36 -> V_38 ) ;
if ( V_33 >= V_37 + V_36 -> V_39 )
return 1 ;
if ( V_33 + V_34 - 1 < V_37 )
return - 1 ;
return 0 ;
}
static T_4 F_12 ( const T_1 * V_40 , const unsigned int V_34 ,
T_4 V_41 , T_1 V_30 )
{
T_4 V_42 = ( V_41 << 1 ) & ( ( 8 * sizeof( T_2 ) ) - 1 ) ;
const T_3 * V_28 = ( ( T_3 * ) V_40 ) + ( V_41 >> 5 ) ;
const T_3 * V_7 = ( T_3 * ) ( V_40 + F_13 ( V_34 , sizeof( T_2 ) ) ) ;
T_2 V_31 ;
T_2 V_29 = 0x5555555555555555ULL ;
T_4 V_12 ;
V_29 <<= V_42 ;
V_31 = F_8 ( V_28 , V_29 , V_30 ) ;
V_28 ++ ;
while( V_31 == 0 && V_28 < V_7 ) {
V_31 = F_8 ( V_28 , 0x5555555555555555ULL , V_30 ) ;
V_28 ++ ;
}
if ( V_28 == V_7 && ( V_34 & ( sizeof( T_2 ) - 1 ) ) )
V_31 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_34 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_31 == 0 )
return V_43 ;
V_28 -- ;
V_12 = F_14 ( V_31 ) ;
V_12 /= 2 ;
return ( ( ( const unsigned char * ) V_28 - V_40 ) * V_14 ) + V_12 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_44 )
{
T_2 V_45 = V_44 - V_2 -> V_22 -> V_46 ;
T_4 V_41 = ( T_4 ) V_45 ;
int V_47 ;
if ( F_16 ( V_45 > V_48 ) )
return - V_49 ;
if ( V_44 >= V_2 -> V_22 -> V_46 + V_2 -> V_22 -> V_50 )
return - V_51 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_22 -> V_52 ; V_47 ++ ) {
V_2 -> V_10 = V_2 -> V_22 -> V_53 + V_47 ;
if ( V_41 < ( V_2 -> V_10 -> V_24 + V_2 -> V_10 -> V_11 ) * V_14 ) {
V_2 -> V_13 = V_41 - ( V_2 -> V_10 -> V_24 * V_14 ) ;
break;
}
}
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 , T_4 V_54 , T_4 * V_34 )
{
T_2 V_44 ;
T_4 V_55 ;
T_1 V_56 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
V_56 = F_7 ( V_2 ) ;
if ( V_56 != V_57 )
return true ;
( * V_34 ) -- ;
if ( * V_34 == 0 )
return true ;
V_44 = F_11 ( V_2 ) ;
if ( F_15 ( V_2 , V_44 + 1 ) )
return true ;
}
return false ;
}
static T_4 F_18 ( const struct V_1 * V_58 , T_4 V_34 )
{
struct V_1 V_2 = * V_58 ;
T_4 V_54 = V_2 . V_13 & 3 ;
T_4 V_59 = V_34 ;
T_4 V_60 ;
T_4 V_61 ;
T_1 * V_28 , * V_62 , * V_7 ;
T_2 V_44 ;
if ( V_54 &&
F_17 ( & V_2 , 4 - V_54 , & V_34 ) )
goto V_63;
V_54 = V_34 & 3 ;
while ( V_34 > 3 ) {
V_62 = V_2 . V_10 -> V_16 -> V_17 ;
if ( V_2 . V_10 -> V_25 )
V_62 = V_2 . V_10 -> V_25 ;
V_7 = V_62 + V_2 . V_10 -> V_16 -> V_64 ;
V_62 += V_2 . V_10 -> V_18 ;
F_2 ( V_2 . V_13 & 3 ) ;
V_62 += ( V_2 . V_13 / V_14 ) ;
V_60 = F_19 ( T_4 , V_34 / V_14 , ( V_7 - V_62 ) ) ;
V_28 = F_20 ( V_62 , 0 , V_60 ) ;
V_61 = ( ( V_28 == NULL ) ? V_60 : ( V_28 - V_62 ) ) ;
V_61 *= V_14 ;
F_2 ( V_34 < V_61 ) ;
V_34 -= V_61 ;
V_44 = F_11 ( & V_2 ) ;
F_15 ( & V_2 , V_44 + V_61 ) ;
V_54 = 3 ;
if ( V_28 )
break;
V_54 = V_34 & 3 ;
}
if ( V_54 )
F_17 ( & V_2 , V_54 , & V_34 ) ;
V_63:
return V_59 - V_34 ;
}
static T_4 F_21 ( struct V_65 * V_22 , const T_1 * V_26 ,
unsigned int V_9 , T_1 V_30 )
{
const T_1 * V_27 = V_26 ;
const T_1 * V_7 = V_26 + V_9 ;
const T_1 V_66 = V_30 << 2 ;
const T_1 V_67 = V_30 << 4 ;
const T_1 V_68 = V_30 << 6 ;
T_4 V_69 = 0 ;
for (; V_27 < V_7 ; V_27 ++ ) {
if ( ( ( * V_27 ) & 0x03 ) == V_30 )
V_69 ++ ;
if ( ( ( * V_27 ) & 0x0C ) == V_66 )
V_69 ++ ;
if ( ( ( * V_27 ) & 0x30 ) == V_67 )
V_69 ++ ;
if ( ( ( * V_27 ) & 0xC0 ) == V_68 )
V_69 ++ ;
}
return V_69 ;
}
void F_22 ( struct V_65 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
struct V_73 * V_10 = NULL ;
T_4 V_74 = V_22 -> V_52 ;
T_4 V_69 [ 4 ] , V_31 ;
int V_40 , V_47 ;
memset ( V_69 , 0 , 4 * sizeof( T_4 ) ) ;
for ( V_40 = 0 ; V_40 < V_74 ; V_40 ++ ) {
V_10 = V_22 -> V_53 + V_40 ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ )
V_69 [ V_47 ] += F_21 ( V_22 ,
V_10 -> V_16 -> V_17 +
V_10 -> V_18 ,
V_10 -> V_11 , V_47 ) ;
}
if ( V_69 [ 0 ] != V_22 -> V_75 ) {
if ( F_6 ( V_22 ) )
F_23 ( V_71 , L_5 ,
V_69 [ 0 ] , V_22 -> V_75 ) ;
return;
}
V_31 = V_22 -> V_50 - V_22 -> V_75 - V_22 -> V_76 ;
if ( V_69 [ 1 ] != V_31 ) {
if ( F_6 ( V_22 ) )
F_23 ( V_71 , L_6 ,
V_69 [ 1 ] , V_31 ) ;
return;
}
if ( V_69 [ 2 ] + V_69 [ 3 ] != V_22 -> V_76 ) {
if ( F_6 ( V_22 ) )
F_23 ( V_71 , L_7 ,
V_69 [ 2 ] + V_69 [ 3 ] , V_22 -> V_76 ) ;
return;
}
}
static inline int F_24 ( struct V_65 * V_22 , T_2 V_44 )
{
T_2 V_77 = V_22 -> V_46 ;
T_2 V_78 = V_77 + V_22 -> V_50 ;
return V_77 <= V_44 && V_44 < V_78 ;
}
struct V_65 * F_25 ( struct V_70 * V_71 , T_2 V_33 , bool V_79 )
{
struct V_80 * V_55 , * V_81 ;
struct V_65 * V_82 ;
F_26 ( & V_71 -> V_83 ) ;
V_55 = V_71 -> V_84 . V_80 ;
while ( V_55 ) {
V_82 = F_27 ( V_55 , struct V_65 , V_85 ) ;
V_81 = NULL ;
if ( V_33 < V_82 -> V_23 )
V_81 = V_55 -> V_86 ;
else if ( V_33 >= V_82 -> V_46 + V_82 -> V_50 )
V_81 = V_55 -> V_87 ;
if ( V_81 == NULL ) {
F_28 ( & V_71 -> V_83 ) ;
if ( V_79 ) {
if ( V_33 < V_82 -> V_23 )
return NULL ;
if ( V_33 >= V_82 -> V_46 + V_82 -> V_50 )
return NULL ;
}
return V_82 ;
}
V_55 = V_81 ;
}
F_28 ( & V_71 -> V_83 ) ;
return NULL ;
}
struct V_65 * F_29 ( struct V_70 * V_71 )
{
const struct V_80 * V_55 ;
struct V_65 * V_22 ;
F_26 ( & V_71 -> V_83 ) ;
V_55 = F_30 ( & V_71 -> V_84 ) ;
V_22 = F_27 ( V_55 , struct V_65 , V_85 ) ;
F_28 ( & V_71 -> V_83 ) ;
return V_22 ;
}
struct V_65 * F_31 ( struct V_65 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
const struct V_80 * V_55 ;
F_26 ( & V_71 -> V_83 ) ;
V_55 = F_32 ( & V_22 -> V_85 ) ;
if ( V_55 == NULL )
V_55 = F_30 ( & V_71 -> V_84 ) ;
if ( F_3 ( & V_22 -> V_85 == V_55 ) ) {
F_28 ( & V_71 -> V_83 ) ;
return NULL ;
}
V_22 = F_27 ( V_55 , struct V_65 , V_85 ) ;
F_28 ( & V_71 -> V_83 ) ;
return V_22 ;
}
void F_33 ( struct V_65 * V_22 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_22 -> V_52 ; V_47 ++ ) {
struct V_73 * V_10 = V_22 -> V_53 + V_47 ;
F_34 ( V_10 -> V_25 ) ;
V_10 -> V_25 = NULL ;
}
}
int F_35 ( struct V_88 * V_89 )
{
struct V_35 * V_56 ;
if ( V_89 -> V_90 )
return 0 ;
V_56 = F_36 ( V_91 , V_92 ) ;
if ( ! V_56 )
return - V_93 ;
F_37 ( & V_56 -> V_94 ) ;
F_38 ( & V_89 -> V_95 ) ;
if ( V_89 -> V_90 )
F_39 ( V_91 , V_56 ) ;
else
V_89 -> V_90 = V_56 ;
F_40 ( & V_89 -> V_95 ) ;
return 0 ;
}
static void F_41 ( struct V_96 * V_97 , const struct V_35 * V_36 )
{
F_42 ( V_97 , L_8 ,
( unsigned long long ) V_36 -> V_98 ,
( unsigned long long ) F_11 ( & V_36 -> V_38 ) ,
V_36 -> V_38 . V_13 , V_36 -> V_39 ) ;
}
static void F_43 ( struct V_88 * V_89 , struct V_35 * V_36 )
{
struct V_65 * V_22 ;
if ( ! F_44 ( V_36 ) )
return;
V_22 = V_36 -> V_38 . V_22 ;
F_45 ( V_36 , V_99 ) ;
F_46 ( & V_36 -> V_94 , & V_22 -> V_100 ) ;
F_37 ( & V_36 -> V_94 ) ;
if ( V_36 -> V_39 ) {
F_2 ( V_36 -> V_38 . V_22 -> V_101 < V_36 -> V_39 ) ;
V_36 -> V_38 . V_22 -> V_101 -= V_36 -> V_39 ;
V_36 -> V_39 = 0 ;
F_47 ( V_102 , & V_36 -> V_38 . V_10 -> V_103 ) ;
F_48 () ;
}
}
void F_49 ( struct V_88 * V_89 , struct V_35 * V_36 )
{
struct V_65 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_26 ( & V_22 -> V_104 ) ;
F_43 ( V_89 , V_36 ) ;
F_28 ( & V_22 -> V_104 ) ;
}
}
void F_50 ( struct V_88 * V_89 )
{
F_38 ( & V_89 -> V_95 ) ;
if ( V_89 -> V_90 ) {
F_49 ( V_89 , V_89 -> V_90 ) ;
F_2 ( V_89 -> V_90 -> V_39 ) ;
F_39 ( V_91 , V_89 -> V_90 ) ;
V_89 -> V_90 = NULL ;
}
F_40 ( & V_89 -> V_95 ) ;
}
static void F_51 ( struct V_65 * V_22 )
{
struct V_80 * V_55 ;
struct V_35 * V_36 ;
F_26 ( & V_22 -> V_104 ) ;
while ( ( V_55 = F_30 ( & V_22 -> V_100 ) ) ) {
V_36 = F_27 ( V_55 , struct V_35 , V_94 ) ;
F_43 ( NULL , V_36 ) ;
}
F_28 ( & V_22 -> V_104 ) ;
}
void F_52 ( struct V_70 * V_71 )
{
struct V_80 * V_55 ;
struct V_65 * V_22 ;
struct V_105 * V_106 ;
while ( ( V_55 = F_30 ( & V_71 -> V_84 ) ) ) {
V_22 = F_27 ( V_55 , struct V_65 , V_85 ) ;
V_106 = V_22 -> V_107 ;
F_46 ( V_55 , & V_71 -> V_84 ) ;
if ( V_106 ) {
F_26 ( & V_106 -> V_108 ) ;
V_106 -> V_109 = NULL ;
F_28 ( & V_106 -> V_108 ) ;
F_53 ( V_106 ) ;
F_54 ( V_106 ) ;
}
F_33 ( V_22 ) ;
F_34 ( V_22 -> V_53 ) ;
F_51 ( V_22 ) ;
F_39 ( V_110 , V_22 ) ;
}
}
static void F_55 ( const struct V_65 * V_22 )
{
F_4 ( V_111 L_9 , ( unsigned long long ) V_22 -> V_23 ) ;
F_4 ( V_111 L_10 , V_22 -> V_52 ) ;
F_4 ( V_111 L_11 , ( unsigned long long ) V_22 -> V_46 ) ;
F_4 ( V_111 L_12 , V_22 -> V_50 ) ;
F_4 ( V_111 L_13 , V_22 -> V_112 ) ;
}
static int F_56 ( struct V_65 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
struct V_73 * V_10 ;
T_4 V_74 = V_22 -> V_52 ;
T_4 V_113 , V_60 ;
int V_47 ;
if ( ! V_74 )
return - V_49 ;
V_22 -> V_53 = F_57 ( V_74 , sizeof( struct V_73 ) , V_92 ) ;
if ( ! V_22 -> V_53 )
return - V_93 ;
V_113 = V_22 -> V_112 ;
for ( V_47 = 0 ; V_47 < V_74 ; V_47 ++ ) {
V_10 = V_22 -> V_53 + V_47 ;
V_10 -> V_103 = 0 ;
if ( V_74 == 1 ) {
V_60 = V_113 ;
V_10 -> V_18 = sizeof( struct V_114 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_11 = V_60 ;
} else if ( V_47 == 0 ) {
V_60 = V_71 -> V_115 . V_116 - sizeof( struct V_114 ) ;
V_10 -> V_18 = sizeof( struct V_114 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_11 = V_60 ;
} else if ( V_47 + 1 == V_74 ) {
V_60 = V_113 ;
V_10 -> V_18 = sizeof( struct V_117 ) ;
V_10 -> V_24 = V_22 -> V_112 - V_113 ;
V_10 -> V_11 = V_60 ;
} else {
V_60 = V_71 -> V_115 . V_116 -
sizeof( struct V_117 ) ;
V_10 -> V_18 = sizeof( struct V_117 ) ;
V_10 -> V_24 = V_22 -> V_112 - V_113 ;
V_10 -> V_11 = V_60 ;
}
V_113 -= V_60 ;
}
if ( V_113 ) {
F_6 ( V_22 ) ;
return - V_118 ;
}
V_10 = V_22 -> V_53 + ( V_74 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_11 ) * V_14 != V_22 -> V_50 ) {
if ( F_6 ( V_22 ) ) {
F_55 ( V_22 ) ;
F_23 ( V_71 , L_14 ,
V_10 -> V_24 , V_10 -> V_11 , V_10 -> V_18 ) ;
}
return - V_118 ;
}
return 0 ;
}
T_2 F_58 ( struct V_70 * V_71 )
{
T_2 V_119 = 0 ;
struct V_120 * V_120 = V_71 -> V_121 ;
struct V_88 * V_89 = F_59 ( V_120 ) ;
char V_40 [ sizeof( struct V_122 ) ] ;
int error , V_123 ;
for ( V_123 = 0 ; ; V_123 ++ ) {
T_5 V_124 = V_123 * sizeof( struct V_122 ) ;
if ( V_124 + sizeof( struct V_122 ) > F_60 ( V_120 ) )
break;
error = F_61 ( V_89 , V_40 , & V_124 ,
sizeof( struct V_122 ) ) ;
if ( error != sizeof( struct V_122 ) )
break;
V_119 += F_62 ( ( (struct V_122 * ) V_40 ) -> V_125 ) ;
}
return V_119 ;
}
static int F_63 ( struct V_65 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
struct V_80 * * V_126 = & V_71 -> V_84 . V_80 , * V_127 = NULL ;
while ( * V_126 ) {
struct V_65 * V_82 = F_27 ( * V_126 , struct V_65 ,
V_85 ) ;
V_127 = * V_126 ;
if ( V_22 -> V_23 < V_82 -> V_23 )
V_126 = & ( ( * V_126 ) -> V_86 ) ;
else if ( V_22 -> V_23 > V_82 -> V_23 )
V_126 = & ( ( * V_126 ) -> V_87 ) ;
else
return - V_128 ;
}
F_64 ( & V_22 -> V_85 , V_127 , V_126 ) ;
F_65 ( & V_22 -> V_85 , & V_71 -> V_84 ) ;
V_71 -> V_129 ++ ;
return 0 ;
}
static int F_66 ( struct V_88 * V_89 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
T_5 V_124 = V_71 -> V_129 * sizeof( struct V_122 ) ;
struct V_122 V_40 ;
int error ;
struct V_65 * V_22 ;
if ( V_124 >= F_60 ( & V_89 -> V_130 ) )
return 1 ;
error = F_61 ( V_89 , ( char * ) & V_40 , & V_124 ,
sizeof( struct V_122 ) ) ;
if ( error != sizeof( struct V_122 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_36 ( V_110 , V_92 ) ;
error = - V_93 ;
if ( ! V_22 )
return error ;
V_22 -> V_72 = V_71 ;
V_22 -> V_23 = F_68 ( V_40 . V_131 ) ;
V_22 -> V_52 = F_62 ( V_40 . V_132 ) ;
V_22 -> V_46 = F_68 ( V_40 . V_133 ) ;
V_22 -> V_50 = F_62 ( V_40 . V_125 ) ;
V_22 -> V_112 = F_62 ( V_40 . V_134 ) ;
F_69 ( & V_22 -> V_104 ) ;
error = F_56 ( V_22 ) ;
if ( error )
goto V_135;
error = F_70 ( V_71 , V_22 -> V_23 ,
& V_136 , V_137 , & V_22 -> V_107 ) ;
if ( error )
goto V_135;
V_22 -> V_107 -> V_109 = V_22 ;
V_22 -> V_138 = (struct V_139 * ) V_22 -> V_107 -> V_140 ;
V_22 -> V_141 &= ~ V_142 ;
if ( V_22 -> V_50 > V_71 -> V_143 )
V_71 -> V_143 = V_22 -> V_50 ;
F_26 ( & V_71 -> V_83 ) ;
error = F_63 ( V_22 ) ;
F_28 ( & V_71 -> V_83 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_54 ( V_22 -> V_107 ) ;
V_135:
F_34 ( V_22 -> V_53 ) ;
F_39 ( V_110 , V_22 ) ;
return error ;
}
static int F_71 ( struct V_88 * V_89 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
int error ;
do {
error = F_66 ( V_89 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_71 -> V_144 = 1 ;
return 0 ;
}
int F_72 ( struct V_70 * V_71 )
{
struct V_88 * V_89 = F_59 ( V_71 -> V_121 ) ;
struct V_105 * V_106 = V_89 -> V_145 ;
struct V_146 V_147 ;
int error = 0 ;
int V_148 = 0 ;
if ( ! V_71 -> V_144 ) {
if ( ! F_73 ( V_106 ) ) {
error = F_74 ( V_106 , V_149 , 0 , & V_147 ) ;
if ( error )
return error ;
V_148 = 1 ;
}
if ( ! V_71 -> V_144 )
error = F_71 ( V_89 ) ;
if ( V_148 )
F_75 ( & V_147 ) ;
}
return error ;
}
static void F_76 ( struct V_65 * V_22 , const void * V_40 )
{
const struct V_114 * V_150 = V_40 ;
T_4 V_151 ;
V_151 = F_62 ( V_150 -> V_151 ) ;
V_151 &= ~ V_152 ;
V_22 -> V_141 &= V_152 ;
V_22 -> V_141 |= V_151 ;
V_22 -> V_75 = F_62 ( V_150 -> V_153 ) ;
V_22 -> V_76 = F_62 ( V_150 -> V_154 ) ;
V_22 -> V_155 = F_68 ( V_150 -> V_156 ) ;
}
static void F_77 ( struct V_65 * V_22 , void * V_40 )
{
struct V_114 * V_150 = V_40 ;
V_150 -> V_151 = F_78 ( V_22 -> V_141 & ~ V_152 ) ;
V_150 -> V_153 = F_78 ( V_22 -> V_75 ) ;
V_150 -> V_154 = F_78 ( V_22 -> V_76 ) ;
V_150 -> V_157 = F_78 ( 0 ) ;
V_150 -> V_156 = F_79 ( V_22 -> V_155 ) ;
memset ( & V_150 -> V_158 , 0 , sizeof( V_150 -> V_158 ) ) ;
}
static int F_80 ( struct V_65 * V_22 )
{
struct V_139 * V_159 = V_22 -> V_138 ;
struct V_114 * V_150 = (struct V_114 * ) V_22 -> V_53 [ 0 ] . V_16 -> V_17 ;
if ( V_159 -> V_160 != V_150 -> V_151 || V_159 -> V_161 != V_150 -> V_153 ||
V_159 -> V_162 != V_150 -> V_154 ||
V_159 -> V_163 != V_150 -> V_156 )
return 0 ;
return 1 ;
}
static void F_81 ( struct V_139 * V_159 , const void * V_40 )
{
const struct V_114 * V_150 = V_40 ;
V_159 -> V_164 = F_78 ( V_165 ) ;
V_159 -> V_160 = V_150 -> V_151 ;
V_159 -> V_161 = V_150 -> V_153 ;
V_159 -> V_162 = V_150 -> V_154 ;
V_159 -> V_163 = V_150 -> V_156 ;
V_159 -> V_157 = 0UL ;
}
static void F_82 ( struct V_65 * V_22 , T_4 V_166 )
{
struct V_139 * V_159 = V_22 -> V_138 ;
T_4 V_167 = F_62 ( V_159 -> V_168 ) + V_166 ;
V_159 -> V_168 = F_78 ( V_167 ) ;
}
static T_4 F_83 ( struct V_65 * V_22 )
{
struct V_73 * V_10 ;
const T_4 V_74 = V_22 -> V_52 ;
const T_1 * V_26 = NULL ;
T_4 V_169 , V_41 , V_69 = 0 ;
for ( V_169 = 0 , V_10 = V_22 -> V_53 ; V_169 < V_74 ; V_169 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_16 -> V_17 + V_10 -> V_18 ;
F_84 ( ! F_85 ( V_10 -> V_16 ) ) ;
while ( V_41 < V_10 -> V_11 * V_14 ) {
V_41 = F_12 ( V_26 , V_10 -> V_11 , V_41 ,
V_170 ) ;
if ( V_41 == V_43 )
break;
V_69 ++ ;
V_41 ++ ;
}
}
return V_69 ;
}
int F_86 ( struct V_65 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
struct V_105 * V_106 = V_22 -> V_107 ;
unsigned int V_74 = V_22 -> V_52 ;
struct V_73 * V_10 ;
unsigned int V_47 , V_171 ;
int error ;
if ( V_22 -> V_53 [ 0 ] . V_16 != NULL )
return 0 ;
for ( V_47 = 0 ; V_47 < V_74 ; V_47 ++ ) {
V_10 = V_22 -> V_53 + V_47 ;
error = F_87 ( V_106 , V_22 -> V_23 + V_47 , 0 , & V_10 -> V_16 ) ;
if ( error )
goto V_135;
}
for ( V_171 = V_74 ; V_171 -- ; ) {
V_10 = V_22 -> V_53 + V_171 ;
error = F_88 ( V_71 , V_10 -> V_16 ) ;
if ( error )
goto V_135;
if ( F_89 ( V_71 , V_10 -> V_16 , V_171 ? V_172 :
V_173 ) ) {
error = - V_118 ;
goto V_135;
}
}
if ( ! ( V_22 -> V_141 & V_142 ) ) {
for ( V_47 = 0 ; V_47 < V_74 ; V_47 ++ )
F_47 ( V_102 , & V_22 -> V_53 [ V_47 ] . V_103 ) ;
F_76 ( V_22 , ( V_22 -> V_53 [ 0 ] . V_16 ) -> V_17 ) ;
V_22 -> V_141 |= ( V_142 | V_174 ) ;
V_22 -> V_175 = V_22 -> V_75 ;
}
if ( F_62 ( V_165 ) != V_22 -> V_138 -> V_164 ) {
V_22 -> V_138 -> V_168 = F_78 ( F_83 ( V_22 ) ) ;
F_81 ( V_22 -> V_138 ,
V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
}
else if ( V_71 -> V_176 . V_177 ) {
if ( ! F_80 ( V_22 ) ) {
F_6 ( V_22 ) ;
error = - V_118 ;
goto V_135;
}
if ( V_22 -> V_138 -> V_168 == 0 )
V_22 -> V_141 &= ~ V_174 ;
}
return 0 ;
V_135:
while ( V_47 -- ) {
V_10 = V_22 -> V_53 + V_47 ;
F_90 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
F_91 ( V_71 , ! V_10 -> V_25 ) ;
}
return error ;
}
int F_92 ( struct V_65 * V_22 )
{
T_4 V_160 ;
if ( V_22 -> V_141 & V_142 )
return 0 ;
if ( F_62 ( V_165 ) != V_22 -> V_138 -> V_164 )
return F_86 ( V_22 ) ;
V_160 = F_62 ( V_22 -> V_138 -> V_160 ) ;
V_160 &= ~ V_152 ;
V_22 -> V_141 &= V_152 ;
V_22 -> V_141 |= ( V_160 | V_142 | V_174 ) ;
if ( V_22 -> V_138 -> V_168 == 0 )
V_22 -> V_141 &= ~ V_174 ;
V_22 -> V_75 = F_62 ( V_22 -> V_138 -> V_161 ) ;
V_22 -> V_175 = V_22 -> V_75 ;
V_22 -> V_76 = F_62 ( V_22 -> V_138 -> V_162 ) ;
V_22 -> V_155 = F_68 ( V_22 -> V_138 -> V_163 ) ;
return 0 ;
}
int F_93 ( struct V_146 * V_178 )
{
struct V_65 * V_22 = V_178 -> V_179 -> V_109 ;
struct V_70 * V_71 = V_22 -> V_72 ;
if ( V_178 -> V_180 & V_181 && V_71 -> V_176 . V_177 )
return 0 ;
return F_86 ( (struct V_65 * ) V_178 -> V_179 -> V_109 ) ;
}
void F_94 ( struct V_146 * V_178 )
{
struct V_65 * V_22 = V_178 -> V_179 -> V_109 ;
int V_47 , V_74 = V_22 -> V_52 ;
for ( V_47 = 0 ; V_47 < V_74 ; V_47 ++ ) {
struct V_73 * V_10 = V_22 -> V_53 + V_47 ;
if ( V_10 -> V_16 ) {
F_90 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
}
}
}
int F_95 ( struct V_70 * V_71 , T_2 V_13 ,
struct V_182 * V_183 ,
const struct V_73 * V_10 , unsigned V_184 , T_2 * V_185 )
{
struct V_186 * V_187 = V_71 -> V_188 ;
struct V_189 * V_190 = V_187 -> V_191 ;
const unsigned int V_192 = V_71 -> V_115 . V_116 /
F_96 ( V_187 -> V_191 ) ;
T_2 V_33 ;
T_6 V_62 = 0 ;
T_6 V_193 = 0 ;
int V_194 ;
unsigned int V_47 ;
T_4 V_195 = 0 ;
T_1 V_196 ;
for ( V_47 = 0 ; V_47 < V_10 -> V_11 ; V_47 ++ ) {
const T_1 * V_197 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_16 -> V_17 ;
V_197 += V_10 -> V_18 ;
V_197 += V_47 ;
if ( V_183 ) {
const T_1 * V_198 = V_183 -> V_17 + V_10 -> V_18 + V_47 ;
V_196 = ~ ( * V_198 | ( * V_198 >> 1 ) ) & ( * V_197 | ( * V_197 >> 1 ) ) ;
} else {
V_196 = ~ ( * V_197 | ( * V_197 >> 1 ) ) ;
}
V_196 &= 0x55 ;
if ( V_196 == 0 )
continue;
V_33 = V_13 + ( ( V_10 -> V_24 + V_47 ) * V_14 ) ;
V_33 *= V_192 ;
while( V_196 ) {
if ( V_196 & 1 ) {
if ( V_193 == 0 )
goto V_199;
if ( ( V_62 + V_193 ) != V_33 ) {
if ( V_193 >= V_184 ) {
V_194 = F_97 ( V_190 ,
V_62 , V_193 ,
V_92 , 0 ) ;
if ( V_194 )
goto V_135;
V_195 += V_193 ;
}
V_193 = 0 ;
V_199:
V_62 = V_33 ;
}
V_193 += V_192 ;
}
V_196 >>= 2 ;
V_33 += V_192 ;
}
}
if ( V_193 >= V_184 ) {
V_194 = F_97 ( V_190 , V_62 , V_193 , V_92 , 0 ) ;
if ( V_194 )
goto V_135;
V_195 += V_193 ;
}
if ( V_185 )
* V_185 = V_195 ;
return 0 ;
V_135:
if ( V_71 -> V_176 . V_200 )
F_98 ( V_71 , L_15 , V_194 ) ;
V_71 -> V_176 . V_200 = 0 ;
return - V_118 ;
}
int F_99 ( struct V_201 * V_202 , void T_7 * V_203 )
{
struct V_120 * V_120 = V_202 -> V_204 -> V_205 ;
struct V_70 * V_71 = F_67 ( V_120 ) ;
struct V_206 * V_207 = F_100 ( V_71 -> V_188 -> V_191 ) ;
struct V_182 * V_183 ;
struct V_65 * V_22 ;
struct V_65 * V_208 ;
struct V_146 V_178 ;
struct V_209 V_210 ;
int V_211 = 0 ;
T_2 V_212 ;
T_2 V_195 = 0 ;
T_2 V_62 , V_7 , V_184 ;
unsigned int V_47 ;
unsigned V_213 = V_71 -> V_115 . V_214 ;
if ( ! F_101 ( V_215 ) )
return - V_216 ;
if ( ! F_102 ( V_207 ) )
return - V_217 ;
if ( F_103 ( & V_210 , V_203 , sizeof( V_210 ) ) )
return - V_218 ;
V_211 = F_72 ( V_71 ) ;
if ( V_211 )
return V_211 ;
V_62 = V_210 . V_62 >> V_213 ;
V_7 = V_62 + ( V_210 . V_34 >> V_213 ) ;
V_184 = F_104 ( T_2 , V_210 . V_184 ,
V_207 -> V_219 . V_220 ) >> V_213 ;
V_22 = F_25 ( V_71 , V_62 , 0 ) ;
V_208 = F_25 ( V_71 , V_7 - 1 , 0 ) ;
if ( V_7 <= V_62 ||
V_184 > V_71 -> V_143 ||
V_62 > V_208 -> V_46 + V_208 -> V_50 )
return - V_49 ;
while ( 1 ) {
V_211 = F_74 ( V_22 -> V_107 , V_221 , 0 , & V_178 ) ;
if ( V_211 )
goto V_63;
if ( ! ( V_22 -> V_141 & V_222 ) ) {
for ( V_47 = 0 ; V_47 < V_22 -> V_52 ; V_47 ++ ) {
struct V_73 * V_10 = V_22 -> V_53 + V_47 ;
V_211 = F_95 ( V_71 ,
V_22 -> V_46 , NULL , V_10 , V_184 ,
& V_212 ) ;
if ( V_211 ) {
F_75 ( & V_178 ) ;
goto V_63;
}
V_195 += V_212 ;
}
V_211 = F_105 ( V_71 , V_223 , 0 ) ;
if ( V_211 == 0 ) {
V_183 = V_22 -> V_53 [ 0 ] . V_16 ;
V_22 -> V_141 |= V_222 ;
F_106 ( V_22 -> V_107 , V_183 , 1 ) ;
F_77 ( V_22 , V_183 -> V_17 ) ;
F_81 ( V_22 -> V_138 , V_183 -> V_17 ) ;
F_107 ( V_71 ) ;
}
}
F_75 ( & V_178 ) ;
if ( V_22 == V_208 )
break;
V_22 = F_31 ( V_22 ) ;
}
V_63:
V_210 . V_34 = V_195 << 9 ;
if ( F_108 ( V_203 , & V_210 , sizeof( V_210 ) ) )
return - V_218 ;
return V_211 ;
}
static void F_109 ( struct V_88 * V_89 )
{
struct V_80 * * V_126 , * V_127 = NULL ;
int V_224 ;
struct V_35 * V_36 = V_89 -> V_90 ;
struct V_65 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_225 = F_11 ( & V_36 -> V_38 ) ;
F_2 ( F_44 ( V_36 ) ) ;
F_26 ( & V_22 -> V_104 ) ;
V_126 = & V_22 -> V_100 . V_80 ;
while ( * V_126 ) {
struct V_35 * V_82 =
F_27 ( * V_126 , struct V_35 , V_94 ) ;
V_127 = * V_126 ;
V_224 = F_10 ( V_225 , V_36 -> V_39 , V_82 ) ;
if ( V_224 > 0 )
V_126 = & ( ( * V_126 ) -> V_87 ) ;
else if ( V_224 < 0 )
V_126 = & ( ( * V_126 ) -> V_86 ) ;
else {
F_28 ( & V_22 -> V_104 ) ;
F_84 ( 1 ) ;
return;
}
}
F_64 ( & V_36 -> V_94 , V_127 , V_126 ) ;
F_65 ( & V_36 -> V_94 , & V_22 -> V_100 ) ;
V_22 -> V_101 += V_36 -> V_39 ;
F_28 ( & V_22 -> V_104 ) ;
F_45 ( V_36 , V_226 ) ;
}
static void F_110 ( struct V_65 * V_22 , struct V_88 * V_89 ,
unsigned V_227 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_89 -> V_90 ;
T_4 V_228 ;
T_4 V_229 = V_22 -> V_175 - V_22 -> V_101 ;
int V_211 ;
V_228 = F_104 ( T_4 , F_111 ( & V_36 -> V_230 ) , V_227 ) ;
V_228 = F_112 ( V_228 , V_231 , V_229 ) ;
if ( ( V_22 -> V_175 < V_22 -> V_101 ) || ( V_229 < V_228 ) )
return;
if ( F_24 ( V_22 , V_89 -> V_232 ) )
V_41 = V_89 -> V_232 ;
else
V_41 = V_22 -> V_233 + V_22 -> V_46 ;
if ( F_84 ( F_15 ( & V_2 , V_41 ) ) )
return;
V_211 = F_113 ( & V_2 , V_57 , V_228 , V_89 , true ) ;
if ( V_211 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_228 ;
V_36 -> V_98 = V_89 -> V_234 ;
F_109 ( V_89 ) ;
}
}
static T_2 F_114 ( struct V_65 * V_22 , T_2 V_44 ,
T_4 V_74 ,
const struct V_88 * V_89 )
{
struct V_35 * V_36 ;
struct V_80 * V_55 ;
int V_224 ;
F_26 ( & V_22 -> V_104 ) ;
V_55 = V_22 -> V_100 . V_80 ;
while ( V_55 ) {
V_36 = F_27 ( V_55 , struct V_35 , V_94 ) ;
V_224 = F_10 ( V_44 , V_74 , V_36 ) ;
if ( V_224 < 0 )
V_55 = V_55 -> V_86 ;
else if ( V_224 > 0 )
V_55 = V_55 -> V_87 ;
else
break;
}
if ( V_55 ) {
while ( ( F_10 ( V_44 , V_74 , V_36 ) == 0 ) && ( V_89 -> V_90 != V_36 ) ) {
V_44 = F_11 ( & V_36 -> V_38 ) + V_36 -> V_39 ;
V_55 = V_55 -> V_87 ;
if ( V_55 == NULL )
break;
V_36 = F_27 ( V_55 , struct V_35 , V_94 ) ;
}
}
F_28 ( & V_22 -> V_104 ) ;
return V_44 ;
}
static int F_115 ( struct V_1 * V_2 ,
const struct V_88 * V_89 ,
T_4 V_235 )
{
T_2 V_44 = F_11 ( V_2 ) ;
T_4 V_228 = 1 ;
T_2 V_236 ;
int V_211 ;
if ( V_235 ) {
V_228 = F_18 ( V_2 , V_235 ) ;
V_236 = V_44 + V_228 ;
if ( V_228 < V_235 )
goto V_135;
}
V_236 = F_114 ( V_2 -> V_22 , V_44 , V_228 , V_89 ) ;
if ( V_236 == V_44 )
return 0 ;
V_135:
V_211 = F_15 ( V_2 , V_236 ) ;
if ( V_211 < 0 )
return V_211 ;
return 1 ;
}
static int F_113 ( struct V_1 * V_2 , T_1 V_30 , T_4 V_235 ,
const struct V_88 * V_89 , bool V_237 )
{
struct V_182 * V_183 ;
struct V_73 * V_238 ;
T_4 V_239 ;
T_4 V_13 ;
T_1 * V_26 ;
int V_240 ;
int V_55 = 0 ;
int V_241 = V_2 -> V_22 -> V_52 ;
int V_211 ;
if ( V_2 -> V_13 != 0 )
V_241 ++ ;
while( 1 ) {
if ( F_116 ( V_102 , & V_2 -> V_10 -> V_103 ) &&
( V_30 == V_57 ) )
goto V_242;
V_183 = V_2 -> V_10 -> V_16 ;
V_26 = V_183 -> V_17 + V_2 -> V_10 -> V_18 ;
F_84 ( ! F_85 ( V_183 ) ) ;
if ( V_30 != V_170 && V_2 -> V_10 -> V_25 )
V_26 = V_2 -> V_10 -> V_25 + V_2 -> V_10 -> V_18 ;
V_239 = V_2 -> V_13 ;
V_13 = F_12 ( V_26 , V_2 -> V_10 -> V_11 , V_2 -> V_13 , V_30 ) ;
if ( V_13 == V_43 )
goto V_243;
V_2 -> V_13 = V_13 ;
if ( V_89 == NULL )
return 0 ;
V_238 = V_2 -> V_10 ;
V_211 = F_115 ( V_2 , V_89 , V_235 ) ;
if ( V_211 == 0 )
return 0 ;
if ( V_211 > 0 ) {
V_55 += ( V_2 -> V_10 - V_238 ) ;
goto V_244;
}
if ( V_211 == - V_51 ) {
V_240 = 0 ;
V_2 -> V_13 = 0 ;
V_55 += ( V_2 -> V_10 - V_238 ) ;
goto V_245;
}
return V_211 ;
V_243:
if ( ( V_30 == V_57 ) && V_239 == 0 )
F_117 ( V_102 , & V_2 -> V_10 -> V_103 ) ;
V_242:
V_2 -> V_13 = 0 ;
V_240 = V_2 -> V_10 - V_2 -> V_22 -> V_53 ;
V_240 ++ ;
if ( V_240 == V_2 -> V_22 -> V_52 )
V_240 = 0 ;
V_245:
V_2 -> V_10 = & V_2 -> V_22 -> V_53 [ V_240 ] ;
if ( ( V_240 == 0 ) && V_237 )
break;
V_55 ++ ;
V_244:
if ( V_55 >= V_241 )
break;
}
return - V_246 ;
}
static void F_118 ( struct V_65 * V_22 , T_2 * V_247 , T_2 V_248 )
{
T_2 V_44 ;
struct V_70 * V_71 = V_22 -> V_72 ;
struct V_105 * V_106 ;
struct V_88 * V_89 ;
int error ;
int V_249 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_10 = V_22 -> V_53 , . V_13 = 0 } ;
while ( 1 ) {
F_38 ( & V_71 -> V_250 ) ;
error = F_113 ( & V_2 , V_170 , 0 , NULL , true ) ;
F_40 ( & V_71 -> V_250 ) ;
if ( error == - V_246 )
break;
if ( F_16 ( error ) )
break;
V_44 = F_11 ( & V_2 ) ;
if ( F_15 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_247 != V_251 && V_44 <= * V_247 )
continue;
if ( V_44 == V_248 )
continue;
* V_247 = V_44 ;
error = F_70 ( V_71 , V_44 , & V_252 , V_137 , & V_106 ) ;
if ( error )
continue;
V_89 = V_106 -> V_109 ;
if ( V_89 || F_119 ( V_253 , & V_106 -> V_254 ) == 0 )
F_54 ( V_106 ) ;
else
V_249 ++ ;
if ( V_249 > V_255 )
return;
}
V_22 -> V_141 &= ~ V_174 ;
return;
}
static bool F_120 ( struct V_65 * * V_124 , const struct V_65 * V_256 )
{
struct V_65 * V_22 = * V_124 ;
V_22 = F_31 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_31 ( NULL ) ;
* V_124 = V_22 ;
if ( V_22 != V_256 )
return true ;
return false ;
}
int F_121 ( struct V_88 * V_89 , T_4 V_227 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
struct V_65 * V_256 = NULL ;
struct V_35 * V_36 = V_89 -> V_90 ;
int error = 0 , V_257 , V_258 = V_259 ;
T_2 V_247 = V_251 ;
int V_260 = 0 ;
if ( V_71 -> V_176 . V_177 )
V_258 |= V_181 ;
if ( F_91 ( V_71 , V_227 ) )
return - V_49 ;
if ( F_44 ( V_36 ) ) {
V_256 = V_36 -> V_38 . V_22 ;
V_258 = 0 ;
} else if ( V_89 -> V_261 && F_24 ( V_89 -> V_261 , V_89 -> V_232 ) ) {
V_36 -> V_38 . V_22 = V_256 = V_89 -> V_261 ;
} else {
V_36 -> V_38 . V_22 = V_256 = F_25 ( V_71 , V_89 -> V_232 , 1 ) ;
}
if ( V_36 -> V_38 . V_22 == NULL )
return - V_262 ;
while ( V_260 < 3 ) {
V_257 = 1 ;
if ( ! F_73 ( V_36 -> V_38 . V_22 -> V_107 ) ) {
V_257 = 0 ;
error = F_74 ( V_36 -> V_38 . V_22 -> V_107 ,
V_221 , V_258 ,
& V_36 -> V_263 ) ;
if ( error == V_264 )
goto V_265;
if ( F_3 ( error ) )
return error ;
if ( V_71 -> V_176 . V_177 ) {
error = F_92 ( V_36 -> V_38 . V_22 ) ;
if ( F_3 ( error ) ) {
F_75 ( & V_36 -> V_263 ) ;
return error ;
}
}
}
if ( V_36 -> V_38 . V_22 -> V_141 & ( V_266 | V_267 ) )
goto V_268;
if ( V_71 -> V_176 . V_177 )
F_86 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_44 ( V_36 ) )
F_110 ( V_36 -> V_38 . V_22 , V_89 , V_227 ) ;
if ( ! F_44 ( V_36 ) && ( V_260 < 1 ) )
goto V_269;
if ( V_36 -> V_38 . V_22 -> V_175 >= V_227 ) {
V_89 -> V_261 = V_36 -> V_38 . V_22 ;
return 0 ;
}
if ( F_44 ( V_36 ) )
F_49 ( V_89 , V_36 ) ;
V_269:
if ( V_36 -> V_38 . V_22 -> V_141 & V_174 )
F_118 ( V_36 -> V_38 . V_22 , & V_247 ,
V_89 -> V_234 ) ;
V_268:
if ( ! V_257 )
F_75 ( & V_36 -> V_263 ) ;
V_265:
if ( F_120 ( & V_36 -> V_38 . V_22 , V_256 ) )
continue;
V_258 &= ~ V_259 ;
V_260 ++ ;
if ( V_89 == F_59 ( V_71 -> V_121 ) && ! V_71 -> V_144 ) {
error = F_71 ( V_89 ) ;
if ( error )
return error ;
}
if ( V_260 == 2 )
F_122 ( V_71 , NULL ) ;
}
return - V_246 ;
}
void F_123 ( struct V_88 * V_89 )
{
struct V_35 * V_36 = V_89 -> V_90 ;
if ( V_36 -> V_263 . V_179 )
F_75 ( & V_36 -> V_263 ) ;
}
static unsigned char F_124 ( struct V_65 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_211 ;
V_211 = F_15 ( & V_2 , V_44 ) ;
F_16 ( V_211 != 0 ) ;
return F_7 ( & V_2 ) ;
}
static void F_125 ( const struct V_1 * V_2 , bool V_270 ,
unsigned int * V_55 )
{
struct V_1 V_124 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_271 = * V_55 ;
T_2 V_44 ;
int V_211 ;
* V_55 = 1 ;
V_44 = F_11 ( V_2 ) ;
F_106 ( V_2 -> V_22 -> V_107 , V_2 -> V_10 -> V_16 , 1 ) ;
F_1 ( V_2 , true , V_270 ? V_272 : V_273 ) ;
V_44 ++ ;
while ( * V_55 < V_271 ) {
V_211 = F_15 ( & V_124 , V_44 ) ;
if ( V_211 || F_7 ( & V_124 ) != V_57 )
break;
F_106 ( V_124 . V_22 -> V_107 , V_124 . V_10 -> V_16 , 1 ) ;
F_1 ( & V_124 , true , V_273 ) ;
( * V_55 ) ++ ;
V_44 ++ ;
}
}
static struct V_65 * F_126 ( struct V_70 * V_71 , T_2 V_274 ,
T_4 V_275 , unsigned char V_4 )
{
struct V_1 V_2 ;
V_2 . V_22 = F_25 ( V_71 , V_274 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_127 ( V_71 ) )
F_23 ( V_71 , L_16 , ( unsigned long long ) V_274 ) ;
return NULL ;
}
while ( V_275 -- ) {
F_15 ( & V_2 , V_274 ) ;
V_274 ++ ;
if ( ! V_2 . V_10 -> V_25 ) {
V_2 . V_10 -> V_25 = F_128 ( V_2 . V_10 -> V_16 -> V_64 ,
V_92 | V_276 ) ;
memcpy ( V_2 . V_10 -> V_25 + V_2 . V_10 -> V_18 ,
V_2 . V_10 -> V_16 -> V_17 + V_2 . V_10 -> V_18 ,
V_2 . V_10 -> V_11 ) ;
}
F_106 ( V_2 . V_22 -> V_107 , V_2 . V_10 -> V_16 , 1 ) ;
F_1 ( & V_2 , false , V_4 ) ;
}
return V_2 . V_22 ;
}
int F_129 ( struct V_96 * V_97 , const struct V_105 * V_106 )
{
struct V_65 * V_22 = V_106 -> V_109 ;
struct V_35 * V_277 ;
const struct V_80 * V_55 ;
if ( V_22 == NULL )
return 0 ;
F_42 ( V_97 , L_17 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_141 ,
V_22 -> V_75 , V_22 -> V_175 , V_22 -> V_76 ,
V_22 -> V_101 ) ;
F_26 ( & V_22 -> V_104 ) ;
for ( V_55 = F_30 ( & V_22 -> V_100 ) ; V_55 ; V_55 = F_32 ( & V_277 -> V_94 ) ) {
V_277 = F_27 ( V_55 , struct V_35 , V_94 ) ;
F_41 ( V_97 , V_277 ) ;
}
F_28 ( & V_22 -> V_104 ) ;
return 0 ;
}
static void F_130 ( struct V_65 * V_22 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
F_98 ( V_71 , L_18 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_98 ( V_71 , L_19 ) ;
F_129 ( NULL , V_22 -> V_107 ) ;
V_22 -> V_141 |= V_267 ;
}
static void F_131 ( struct V_88 * V_89 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_89 -> V_90 ;
struct V_65 * V_22 = V_2 -> V_22 ;
unsigned V_278 ;
T_2 V_44 ;
int V_211 ;
F_26 ( & V_22 -> V_104 ) ;
if ( F_44 ( V_36 ) ) {
if ( F_132 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_11 ( V_2 ) ;
V_211 = F_15 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_278 = F_133 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_278 ;
V_22 -> V_101 -= V_278 ;
F_45 ( V_36 , V_279 ) ;
if ( V_36 -> V_39 && ! V_211 )
goto V_63;
}
F_43 ( V_89 , V_36 ) ;
}
V_63:
F_28 ( & V_22 -> V_104 ) ;
}
int F_134 ( struct V_88 * V_89 , T_2 * V_280 , unsigned int * V_281 ,
bool V_270 , T_2 * V_282 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
struct V_182 * V_283 ;
struct V_1 V_2 = { . V_22 = V_89 -> V_261 , } ;
unsigned int V_284 ;
T_2 V_41 ;
T_2 V_44 ;
int error ;
if ( F_44 ( V_89 -> V_90 ) )
V_41 = F_11 ( & V_89 -> V_90 -> V_38 ) ;
else if ( ! V_270 && F_24 ( V_2 . V_22 , V_89 -> V_232 ) )
V_41 = V_89 -> V_232 ;
else
V_41 = V_2 . V_22 -> V_233 + V_2 . V_22 -> V_46 ;
F_15 ( & V_2 , V_41 ) ;
error = F_113 ( & V_2 , V_57 , 0 , V_89 , false ) ;
if ( error == - V_246 ) {
F_15 ( & V_2 , V_41 ) ;
error = F_113 ( & V_2 , V_57 , 0 , NULL , false ) ;
}
if ( error ) {
F_98 ( V_71 , L_20 ,
( unsigned long long ) V_89 -> V_234 , error , * V_281 ,
F_116 ( V_102 , & V_2 . V_22 -> V_53 -> V_103 ) ) ;
goto V_285;
}
F_125 ( & V_2 , V_270 , V_281 ) ;
V_44 = F_11 ( & V_2 ) ;
V_2 . V_22 -> V_233 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_44 ( V_89 -> V_90 ) )
F_131 ( V_89 , & V_2 , * V_281 ) ;
V_284 = * V_281 ;
if ( V_270 )
V_284 -- ;
if ( ! V_270 ) {
V_89 -> V_232 = V_44 + V_284 - 1 ;
error = F_135 ( V_89 , & V_283 ) ;
if ( error == 0 ) {
struct V_286 * V_287 =
(struct V_286 * ) V_283 -> V_17 ;
F_106 ( V_89 -> V_145 , V_283 , 1 ) ;
V_287 -> V_288 = V_287 -> V_289 =
F_79 ( V_89 -> V_232 ) ;
F_90 ( V_283 ) ;
}
}
if ( V_2 . V_22 -> V_75 < * V_281 ) {
F_4 ( V_21 L_21 , * V_281 ) ;
goto V_285;
}
V_2 . V_22 -> V_75 -= * V_281 ;
if ( V_270 ) {
V_2 . V_22 -> V_76 ++ ;
* V_282 = V_2 . V_22 -> V_155 ++ ;
if ( * V_282 == 0 )
* V_282 = V_2 . V_22 -> V_155 ++ ;
}
F_106 ( V_2 . V_22 -> V_107 , V_2 . V_22 -> V_53 [ 0 ] . V_16 , 1 ) ;
F_77 ( V_2 . V_22 , V_2 . V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_2 . V_22 -> V_138 , V_2 . V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_136 ( V_71 , 0 , - ( V_290 ) * V_281 , V_270 ? 1 : 0 ) ;
if ( V_270 )
F_137 ( V_71 , V_44 , 1 ) ;
if ( V_284 )
F_138 ( V_89 , V_284 , V_89 -> V_130 . V_291 ,
V_89 -> V_130 . V_292 ) ;
V_2 . V_22 -> V_175 -= * V_281 ;
F_139 ( V_89 , V_2 . V_22 , V_44 , * V_281 ,
V_270 ? V_272 : V_273 ) ;
* V_280 = V_44 ;
return 0 ;
V_285:
F_130 ( V_2 . V_22 ) ;
return - V_118 ;
}
void F_140 ( struct V_88 * V_89 , T_2 V_274 , T_4 V_275 , int V_293 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
struct V_65 * V_22 ;
V_22 = F_126 ( V_71 , V_274 , V_275 , V_57 ) ;
if ( ! V_22 )
return;
F_139 ( V_89 , V_22 , V_274 , V_275 , V_57 ) ;
V_22 -> V_75 += V_275 ;
V_22 -> V_141 &= ~ V_222 ;
F_106 ( V_22 -> V_107 , V_22 -> V_53 [ 0 ] . V_16 , 1 ) ;
F_77 ( V_22 , V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_22 -> V_138 , V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
if ( V_293 || V_89 -> V_294 )
F_141 ( V_89 , V_274 , V_275 ) ;
}
void F_142 ( struct V_88 * V_89 , T_2 V_274 , T_4 V_275 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
F_140 ( V_89 , V_274 , V_275 , 1 ) ;
F_136 ( V_71 , 0 , + V_275 , 0 ) ;
F_138 ( V_89 , - ( V_290 ) V_275 , V_89 -> V_130 . V_291 , V_89 -> V_130 . V_292 ) ;
}
void F_143 ( struct V_120 * V_120 )
{
struct V_88 * V_89 = F_59 ( V_120 ) ;
struct V_70 * V_71 = F_67 ( V_120 ) ;
struct V_65 * V_22 ;
T_2 V_295 = V_89 -> V_234 ;
V_22 = F_126 ( V_71 , V_295 , 1 , V_170 ) ;
if ( ! V_22 )
return;
F_139 ( V_89 , V_22 , V_295 , 1 , V_170 ) ;
F_106 ( V_22 -> V_107 , V_22 -> V_53 [ 0 ] . V_16 , 1 ) ;
F_77 ( V_22 , V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_22 -> V_138 , V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 , 1 ) ;
}
static void F_144 ( struct V_65 * V_22 , T_2 V_295 )
{
struct V_70 * V_71 = V_22 -> V_72 ;
struct V_65 * V_296 ;
V_296 = F_126 ( V_71 , V_295 , 1 , V_57 ) ;
if ( ! V_296 )
return;
F_145 ( V_71 , V_22 == V_296 ) ;
if ( ! V_22 -> V_76 )
F_6 ( V_22 ) ;
V_22 -> V_76 -- ;
V_22 -> V_75 ++ ;
F_106 ( V_22 -> V_107 , V_22 -> V_53 [ 0 ] . V_16 , 1 ) ;
F_77 ( V_22 , V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_22 -> V_138 , V_22 -> V_53 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 , - 1 ) ;
F_136 ( V_71 , 0 , + 1 , - 1 ) ;
}
void F_146 ( struct V_65 * V_22 , struct V_88 * V_89 )
{
F_144 ( V_22 , V_89 -> V_234 ) ;
F_139 ( V_89 , V_22 , V_89 -> V_234 , 1 , V_57 ) ;
F_138 ( V_89 , - 1 , V_89 -> V_130 . V_291 , V_89 -> V_130 . V_292 ) ;
F_141 ( V_89 , V_89 -> V_234 , 1 ) ;
}
int F_147 ( struct V_70 * V_71 , T_2 V_297 , unsigned int type )
{
struct V_65 * V_22 ;
struct V_146 V_298 ;
int error = - V_49 ;
V_22 = F_25 ( V_71 , V_297 , 1 ) ;
if ( ! V_22 )
goto V_135;
error = F_74 ( V_22 -> V_107 , V_149 , 0 , & V_298 ) ;
if ( error )
goto V_135;
if ( F_124 ( V_22 , V_297 ) != type )
error = - V_299 ;
F_75 ( & V_298 ) ;
V_135:
return error ;
}
void F_148 ( struct V_88 * V_89 , struct V_300 * V_301 ,
T_2 V_44 )
{
struct V_70 * V_71 = F_67 ( & V_89 -> V_130 ) ;
struct V_65 * V_22 ;
struct V_65 * * V_31 ;
unsigned int V_302 ;
unsigned int V_47 ;
if ( F_91 ( V_71 , ! V_301 -> V_303 ) )
return;
if ( V_89 -> V_261 && F_24 ( V_89 -> V_261 , V_44 ) )
V_22 = V_89 -> V_261 ;
else
V_22 = F_25 ( V_71 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_23 ( V_71 , L_22 , ( unsigned long long ) V_44 ) ;
return;
}
V_89 -> V_261 = V_22 ;
for ( V_47 = 0 ; V_47 < V_301 -> V_304 ; V_47 ++ )
if ( V_301 -> V_305 [ V_47 ] == V_22 )
return;
if ( V_301 -> V_304 == V_301 -> V_306 ) {
V_302 = V_301 -> V_306 + 10 ;
V_31 = F_57 ( V_302 , sizeof( struct V_65 * ) ,
V_92 | V_276 ) ;
if ( V_301 -> V_305 ) {
memcpy ( V_31 , V_301 -> V_305 ,
V_301 -> V_306 * sizeof( struct V_65 * ) ) ;
F_34 ( V_301 -> V_305 ) ;
}
V_301 -> V_306 = V_302 ;
V_301 -> V_305 = V_31 ;
}
V_301 -> V_305 [ V_301 -> V_304 ++ ] = V_22 ;
}
void F_149 ( struct V_300 * V_301 , unsigned int V_30 )
{
unsigned int V_47 ;
V_301 -> V_303 = F_57 ( V_301 -> V_304 , sizeof( struct V_146 ) ,
V_92 | V_276 ) ;
for ( V_47 = 0 ; V_47 < V_301 -> V_304 ; V_47 ++ )
F_150 ( V_301 -> V_305 [ V_47 ] -> V_107 ,
V_30 , 0 ,
& V_301 -> V_303 [ V_47 ] ) ;
}
void F_151 ( struct V_300 * V_301 )
{
unsigned int V_47 ;
F_34 ( V_301 -> V_305 ) ;
if ( V_301 -> V_303 ) {
for ( V_47 = 0 ; V_47 < V_301 -> V_304 ; V_47 ++ )
F_152 ( & V_301 -> V_303 [ V_47 ] ) ;
F_34 ( V_301 -> V_303 ) ;
V_301 -> V_303 = NULL ;
}
}
