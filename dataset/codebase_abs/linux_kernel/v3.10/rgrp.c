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
T_4 V_47 ;
if ( F_16 ( V_45 > V_48 ) )
return - V_49 ;
if ( V_44 >= V_2 -> V_22 -> V_46 + V_2 -> V_22 -> V_50 )
return - V_51 ;
V_2 -> V_10 = V_2 -> V_22 -> V_52 ;
V_2 -> V_13 = ( T_4 ) ( V_45 ) ;
if ( V_2 -> V_13 < ( V_2 -> V_10 -> V_24 + V_2 -> V_10 -> V_11 ) * V_14 )
return 0 ;
V_2 -> V_13 += ( sizeof( struct V_53 ) -
sizeof( struct V_54 ) ) * V_14 ;
V_47 = V_2 -> V_13 / V_2 -> V_22 -> V_55 -> V_56 ;
V_2 -> V_13 -= V_47 * V_2 -> V_22 -> V_55 -> V_56 ;
V_2 -> V_10 += V_47 ;
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 , T_4 V_57 , T_4 * V_34 )
{
T_2 V_44 ;
T_4 V_58 ;
T_1 V_59 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_59 = F_7 ( V_2 ) ;
if ( V_59 != V_60 )
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
static T_4 F_18 ( const struct V_1 * V_61 , T_4 V_34 )
{
struct V_1 V_2 = * V_61 ;
T_4 V_57 = V_2 . V_13 & 3 ;
T_4 V_62 = V_34 ;
T_4 V_63 ;
T_4 V_64 ;
T_1 * V_28 , * V_65 , * V_7 ;
T_2 V_44 ;
if ( V_57 &&
F_17 ( & V_2 , 4 - V_57 , & V_34 ) )
goto V_66;
V_57 = V_34 & 3 ;
while ( V_34 > 3 ) {
V_65 = V_2 . V_10 -> V_16 -> V_17 ;
if ( V_2 . V_10 -> V_25 )
V_65 = V_2 . V_10 -> V_25 ;
V_7 = V_65 + V_2 . V_10 -> V_16 -> V_67 ;
V_65 += V_2 . V_10 -> V_18 ;
F_2 ( V_2 . V_13 & 3 ) ;
V_65 += ( V_2 . V_13 / V_14 ) ;
V_63 = F_19 ( T_4 , V_34 / V_14 , ( V_7 - V_65 ) ) ;
V_28 = F_20 ( V_65 , 0 , V_63 ) ;
V_64 = ( ( V_28 == NULL ) ? V_63 : ( V_28 - V_65 ) ) ;
V_64 *= V_14 ;
F_2 ( V_34 < V_64 ) ;
V_34 -= V_64 ;
V_44 = F_11 ( & V_2 ) ;
if ( F_15 ( & V_2 , V_44 + V_64 ) ) {
V_57 = 0 ;
break;
}
if ( V_28 ) {
V_57 = 3 ;
break;
}
V_57 = V_34 & 3 ;
}
if ( V_57 )
F_17 ( & V_2 , V_57 , & V_34 ) ;
V_66:
return V_62 - V_34 ;
}
static T_4 F_21 ( struct V_68 * V_22 , const T_1 * V_26 ,
unsigned int V_9 , T_1 V_30 )
{
const T_1 * V_27 = V_26 ;
const T_1 * V_7 = V_26 + V_9 ;
const T_1 V_69 = V_30 << 2 ;
const T_1 V_70 = V_30 << 4 ;
const T_1 V_71 = V_30 << 6 ;
T_4 V_72 = 0 ;
for (; V_27 < V_7 ; V_27 ++ ) {
if ( ( ( * V_27 ) & 0x03 ) == V_30 )
V_72 ++ ;
if ( ( ( * V_27 ) & 0x0C ) == V_69 )
V_72 ++ ;
if ( ( ( * V_27 ) & 0x30 ) == V_70 )
V_72 ++ ;
if ( ( ( * V_27 ) & 0xC0 ) == V_71 )
V_72 ++ ;
}
return V_72 ;
}
void F_22 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_75 * V_10 = NULL ;
T_4 V_76 = V_22 -> V_77 ;
T_4 V_72 [ 4 ] , V_31 ;
int V_40 , V_47 ;
memset ( V_72 , 0 , 4 * sizeof( T_4 ) ) ;
for ( V_40 = 0 ; V_40 < V_76 ; V_40 ++ ) {
V_10 = V_22 -> V_52 + V_40 ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ )
V_72 [ V_47 ] += F_21 ( V_22 ,
V_10 -> V_16 -> V_17 +
V_10 -> V_18 ,
V_10 -> V_11 , V_47 ) ;
}
if ( V_72 [ 0 ] != V_22 -> V_78 ) {
if ( F_6 ( V_22 ) )
F_23 ( V_74 , L_5 ,
V_72 [ 0 ] , V_22 -> V_78 ) ;
return;
}
V_31 = V_22 -> V_50 - V_22 -> V_78 - V_22 -> V_79 ;
if ( V_72 [ 1 ] != V_31 ) {
if ( F_6 ( V_22 ) )
F_23 ( V_74 , L_6 ,
V_72 [ 1 ] , V_31 ) ;
return;
}
if ( V_72 [ 2 ] + V_72 [ 3 ] != V_22 -> V_79 ) {
if ( F_6 ( V_22 ) )
F_23 ( V_74 , L_7 ,
V_72 [ 2 ] + V_72 [ 3 ] , V_22 -> V_79 ) ;
return;
}
}
static inline int F_24 ( struct V_68 * V_22 , T_2 V_44 )
{
T_2 V_80 = V_22 -> V_46 ;
T_2 V_81 = V_80 + V_22 -> V_50 ;
return V_80 <= V_44 && V_44 < V_81 ;
}
struct V_68 * F_25 ( struct V_73 * V_74 , T_2 V_33 , bool V_82 )
{
struct V_83 * V_58 , * V_84 ;
struct V_68 * V_85 ;
F_26 ( & V_74 -> V_86 ) ;
V_58 = V_74 -> V_87 . V_83 ;
while ( V_58 ) {
V_85 = F_27 ( V_58 , struct V_68 , V_88 ) ;
V_84 = NULL ;
if ( V_33 < V_85 -> V_23 )
V_84 = V_58 -> V_89 ;
else if ( V_33 >= V_85 -> V_46 + V_85 -> V_50 )
V_84 = V_58 -> V_90 ;
if ( V_84 == NULL ) {
F_28 ( & V_74 -> V_86 ) ;
if ( V_82 ) {
if ( V_33 < V_85 -> V_23 )
return NULL ;
if ( V_33 >= V_85 -> V_46 + V_85 -> V_50 )
return NULL ;
}
return V_85 ;
}
V_58 = V_84 ;
}
F_28 ( & V_74 -> V_86 ) ;
return NULL ;
}
struct V_68 * F_29 ( struct V_73 * V_74 )
{
const struct V_83 * V_58 ;
struct V_68 * V_22 ;
F_26 ( & V_74 -> V_86 ) ;
V_58 = F_30 ( & V_74 -> V_87 ) ;
V_22 = F_27 ( V_58 , struct V_68 , V_88 ) ;
F_28 ( & V_74 -> V_86 ) ;
return V_22 ;
}
struct V_68 * F_31 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
const struct V_83 * V_58 ;
F_26 ( & V_74 -> V_86 ) ;
V_58 = F_32 ( & V_22 -> V_88 ) ;
if ( V_58 == NULL )
V_58 = F_30 ( & V_74 -> V_87 ) ;
if ( F_3 ( & V_22 -> V_88 == V_58 ) ) {
F_28 ( & V_74 -> V_86 ) ;
return NULL ;
}
V_22 = F_27 ( V_58 , struct V_68 , V_88 ) ;
F_28 ( & V_74 -> V_86 ) ;
return V_22 ;
}
void F_33 ( struct V_68 * V_22 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_22 -> V_77 ; V_47 ++ ) {
struct V_75 * V_10 = V_22 -> V_52 + V_47 ;
F_34 ( V_10 -> V_25 ) ;
V_10 -> V_25 = NULL ;
}
}
int F_35 ( struct V_91 * V_92 )
{
int error = 0 ;
F_36 ( & V_92 -> V_93 ) ;
if ( V_92 -> V_94 )
goto V_66;
V_92 -> V_94 = F_37 ( V_95 , V_96 ) ;
if ( ! V_92 -> V_94 ) {
error = - V_97 ;
goto V_66;
}
F_38 ( & V_92 -> V_94 -> V_98 ) ;
V_66:
F_39 ( & V_92 -> V_93 ) ;
return error ;
}
static void F_40 ( struct V_99 * V_100 , const struct V_35 * V_36 )
{
F_41 ( V_100 , L_8 ,
( unsigned long long ) V_36 -> V_101 ,
( unsigned long long ) F_11 ( & V_36 -> V_38 ) ,
V_36 -> V_38 . V_13 , V_36 -> V_39 ) ;
}
static void F_42 ( struct V_35 * V_36 )
{
struct V_68 * V_22 ;
if ( ! F_43 ( V_36 ) )
return;
V_22 = V_36 -> V_38 . V_22 ;
F_44 ( V_36 , V_102 ) ;
F_45 ( & V_36 -> V_98 , & V_22 -> V_103 ) ;
F_38 ( & V_36 -> V_98 ) ;
if ( V_36 -> V_39 ) {
F_2 ( V_36 -> V_38 . V_22 -> V_104 < V_36 -> V_39 ) ;
V_36 -> V_38 . V_22 -> V_104 -= V_36 -> V_39 ;
V_36 -> V_39 = 0 ;
F_46 ( V_105 , & V_36 -> V_38 . V_10 -> V_106 ) ;
F_47 () ;
}
}
void F_48 ( struct V_35 * V_36 )
{
struct V_68 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_26 ( & V_22 -> V_107 ) ;
F_42 ( V_36 ) ;
F_28 ( & V_22 -> V_107 ) ;
}
}
void F_49 ( struct V_91 * V_92 )
{
struct V_108 * V_108 = & V_92 -> V_109 ;
F_36 ( & V_92 -> V_93 ) ;
if ( V_92 -> V_94 && F_50 ( & V_108 -> V_110 ) <= 1 ) {
F_48 ( V_92 -> V_94 ) ;
F_2 ( V_92 -> V_94 -> V_39 ) ;
F_51 ( V_95 , V_92 -> V_94 ) ;
V_92 -> V_94 = NULL ;
}
F_39 ( & V_92 -> V_93 ) ;
}
static void F_52 ( struct V_68 * V_22 )
{
struct V_83 * V_58 ;
struct V_35 * V_36 ;
F_26 ( & V_22 -> V_107 ) ;
while ( ( V_58 = F_30 ( & V_22 -> V_103 ) ) ) {
V_36 = F_27 ( V_58 , struct V_35 , V_98 ) ;
F_42 ( V_36 ) ;
}
F_28 ( & V_22 -> V_107 ) ;
}
void F_53 ( struct V_73 * V_74 )
{
struct V_83 * V_58 ;
struct V_68 * V_22 ;
struct V_111 * V_112 ;
while ( ( V_58 = F_30 ( & V_74 -> V_87 ) ) ) {
V_22 = F_27 ( V_58 , struct V_68 , V_88 ) ;
V_112 = V_22 -> V_113 ;
F_45 ( V_58 , & V_74 -> V_87 ) ;
if ( V_112 ) {
F_26 ( & V_112 -> V_114 ) ;
V_112 -> V_115 = NULL ;
F_28 ( & V_112 -> V_114 ) ;
F_54 ( V_112 ) ;
F_55 ( V_112 ) ;
}
F_33 ( V_22 ) ;
F_34 ( V_22 -> V_52 ) ;
F_52 ( V_22 ) ;
F_51 ( V_116 , V_22 ) ;
}
}
static void F_56 ( const struct V_68 * V_22 )
{
F_4 ( V_117 L_9 , ( unsigned long long ) V_22 -> V_23 ) ;
F_4 ( V_117 L_10 , V_22 -> V_77 ) ;
F_4 ( V_117 L_11 , ( unsigned long long ) V_22 -> V_46 ) ;
F_4 ( V_117 L_12 , V_22 -> V_50 ) ;
F_4 ( V_117 L_13 , V_22 -> V_118 ) ;
}
static int F_57 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_75 * V_10 ;
T_4 V_76 = V_22 -> V_77 ;
T_4 V_119 , V_63 ;
int V_47 ;
if ( ! V_76 )
return - V_49 ;
V_22 -> V_52 = F_58 ( V_76 , sizeof( struct V_75 ) , V_96 ) ;
if ( ! V_22 -> V_52 )
return - V_97 ;
V_119 = V_22 -> V_118 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ ) {
V_10 = V_22 -> V_52 + V_47 ;
V_10 -> V_106 = 0 ;
if ( V_76 == 1 ) {
V_63 = V_119 ;
V_10 -> V_18 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_11 = V_63 ;
} else if ( V_47 == 0 ) {
V_63 = V_74 -> V_120 . V_121 - sizeof( struct V_53 ) ;
V_10 -> V_18 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_11 = V_63 ;
} else if ( V_47 + 1 == V_76 ) {
V_63 = V_119 ;
V_10 -> V_18 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_118 - V_119 ;
V_10 -> V_11 = V_63 ;
} else {
V_63 = V_74 -> V_120 . V_121 -
sizeof( struct V_54 ) ;
V_10 -> V_18 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_118 - V_119 ;
V_10 -> V_11 = V_63 ;
}
V_119 -= V_63 ;
}
if ( V_119 ) {
F_6 ( V_22 ) ;
return - V_122 ;
}
V_10 = V_22 -> V_52 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_11 ) * V_14 != V_22 -> V_50 ) {
if ( F_6 ( V_22 ) ) {
F_56 ( V_22 ) ;
F_23 ( V_74 , L_14 ,
V_10 -> V_24 , V_10 -> V_11 , V_10 -> V_18 ) ;
}
return - V_122 ;
}
return 0 ;
}
T_2 F_59 ( struct V_73 * V_74 )
{
T_2 V_123 = 0 ;
struct V_108 * V_108 = V_74 -> V_124 ;
struct V_91 * V_92 = F_60 ( V_108 ) ;
char V_40 [ sizeof( struct V_125 ) ] ;
int error , V_126 ;
for ( V_126 = 0 ; ; V_126 ++ ) {
T_5 V_127 = V_126 * sizeof( struct V_125 ) ;
if ( V_127 + sizeof( struct V_125 ) > F_61 ( V_108 ) )
break;
error = F_62 ( V_92 , V_40 , & V_127 ,
sizeof( struct V_125 ) ) ;
if ( error != sizeof( struct V_125 ) )
break;
V_123 += F_63 ( ( (struct V_125 * ) V_40 ) -> V_128 ) ;
}
return V_123 ;
}
static int F_64 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_83 * * V_129 = & V_74 -> V_87 . V_83 , * V_130 = NULL ;
while ( * V_129 ) {
struct V_68 * V_85 = F_27 ( * V_129 , struct V_68 ,
V_88 ) ;
V_130 = * V_129 ;
if ( V_22 -> V_23 < V_85 -> V_23 )
V_129 = & ( ( * V_129 ) -> V_89 ) ;
else if ( V_22 -> V_23 > V_85 -> V_23 )
V_129 = & ( ( * V_129 ) -> V_90 ) ;
else
return - V_131 ;
}
F_65 ( & V_22 -> V_88 , V_130 , V_129 ) ;
F_66 ( & V_22 -> V_88 , & V_74 -> V_87 ) ;
V_74 -> V_132 ++ ;
return 0 ;
}
static int F_67 ( struct V_91 * V_92 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
T_5 V_127 = V_74 -> V_132 * sizeof( struct V_125 ) ;
struct V_125 V_40 ;
int error ;
struct V_68 * V_22 ;
if ( V_127 >= F_61 ( & V_92 -> V_109 ) )
return 1 ;
error = F_62 ( V_92 , ( char * ) & V_40 , & V_127 ,
sizeof( struct V_125 ) ) ;
if ( error != sizeof( struct V_125 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_37 ( V_116 , V_96 ) ;
error = - V_97 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_74 ;
V_22 -> V_23 = F_69 ( V_40 . V_133 ) ;
V_22 -> V_77 = F_63 ( V_40 . V_134 ) ;
V_22 -> V_46 = F_69 ( V_40 . V_135 ) ;
V_22 -> V_50 = F_63 ( V_40 . V_128 ) ;
V_22 -> V_118 = F_63 ( V_40 . V_136 ) ;
F_70 ( & V_22 -> V_107 ) ;
error = F_57 ( V_22 ) ;
if ( error )
goto V_137;
error = F_71 ( V_74 , V_22 -> V_23 ,
& V_138 , V_139 , & V_22 -> V_113 ) ;
if ( error )
goto V_137;
V_22 -> V_113 -> V_115 = V_22 ;
V_22 -> V_140 = (struct V_141 * ) V_22 -> V_113 -> V_142 . V_143 ;
V_22 -> V_144 &= ~ V_145 ;
if ( V_22 -> V_50 > V_74 -> V_146 )
V_74 -> V_146 = V_22 -> V_50 ;
F_26 ( & V_74 -> V_86 ) ;
error = F_64 ( V_22 ) ;
F_28 ( & V_74 -> V_86 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_55 ( V_22 -> V_113 ) ;
V_137:
F_34 ( V_22 -> V_52 ) ;
F_51 ( V_116 , V_22 ) ;
return error ;
}
static int F_72 ( struct V_91 * V_92 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
int error ;
do {
error = F_67 ( V_92 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_74 -> V_147 = 1 ;
return 0 ;
}
int F_73 ( struct V_73 * V_74 )
{
struct V_91 * V_92 = F_60 ( V_74 -> V_124 ) ;
struct V_111 * V_112 = V_92 -> V_148 ;
struct V_149 V_150 ;
int error = 0 ;
int V_151 = 0 ;
if ( ! V_74 -> V_147 ) {
if ( ! F_74 ( V_112 ) ) {
error = F_75 ( V_112 , V_152 , 0 , & V_150 ) ;
if ( error )
return error ;
V_151 = 1 ;
}
if ( ! V_74 -> V_147 )
error = F_72 ( V_92 ) ;
if ( V_151 )
F_76 ( & V_150 ) ;
}
return error ;
}
static void F_77 ( struct V_68 * V_22 , const void * V_40 )
{
const struct V_53 * V_153 = V_40 ;
T_4 V_154 ;
V_154 = F_63 ( V_153 -> V_154 ) ;
V_154 &= ~ V_155 ;
V_22 -> V_144 &= V_155 ;
V_22 -> V_144 |= V_154 ;
V_22 -> V_78 = F_63 ( V_153 -> V_156 ) ;
V_22 -> V_79 = F_63 ( V_153 -> V_157 ) ;
V_22 -> V_158 = F_69 ( V_153 -> V_159 ) ;
}
static void F_78 ( struct V_68 * V_22 , void * V_40 )
{
struct V_53 * V_153 = V_40 ;
V_153 -> V_154 = F_79 ( V_22 -> V_144 & ~ V_155 ) ;
V_153 -> V_156 = F_79 ( V_22 -> V_78 ) ;
V_153 -> V_157 = F_79 ( V_22 -> V_79 ) ;
V_153 -> V_160 = F_79 ( 0 ) ;
V_153 -> V_159 = F_80 ( V_22 -> V_158 ) ;
memset ( & V_153 -> V_161 , 0 , sizeof( V_153 -> V_161 ) ) ;
}
static int F_81 ( struct V_68 * V_22 )
{
struct V_141 * V_162 = V_22 -> V_140 ;
struct V_53 * V_153 = (struct V_53 * ) V_22 -> V_52 [ 0 ] . V_16 -> V_17 ;
if ( V_162 -> V_163 != V_153 -> V_154 || V_162 -> V_164 != V_153 -> V_156 ||
V_162 -> V_165 != V_153 -> V_157 ||
V_162 -> V_166 != V_153 -> V_159 )
return 0 ;
return 1 ;
}
static void F_82 ( struct V_141 * V_162 , const void * V_40 )
{
const struct V_53 * V_153 = V_40 ;
V_162 -> V_167 = F_79 ( V_168 ) ;
V_162 -> V_163 = V_153 -> V_154 ;
V_162 -> V_164 = V_153 -> V_156 ;
V_162 -> V_165 = V_153 -> V_157 ;
V_162 -> V_166 = V_153 -> V_159 ;
V_162 -> V_160 = 0UL ;
}
static void F_83 ( struct V_68 * V_22 , T_4 V_169 )
{
struct V_141 * V_162 = V_22 -> V_140 ;
T_4 V_170 = F_63 ( V_162 -> V_171 ) + V_169 ;
V_162 -> V_171 = F_79 ( V_170 ) ;
}
static T_4 F_84 ( struct V_68 * V_22 )
{
struct V_75 * V_10 ;
const T_4 V_76 = V_22 -> V_77 ;
const T_1 * V_26 = NULL ;
T_4 V_172 , V_41 , V_72 = 0 ;
for ( V_172 = 0 , V_10 = V_22 -> V_52 ; V_172 < V_76 ; V_172 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_16 -> V_17 + V_10 -> V_18 ;
F_85 ( ! F_86 ( V_10 -> V_16 ) ) ;
while ( V_41 < V_10 -> V_11 * V_14 ) {
V_41 = F_12 ( V_26 , V_10 -> V_11 , V_41 ,
V_173 ) ;
if ( V_41 == V_43 )
break;
V_72 ++ ;
V_41 ++ ;
}
}
return V_72 ;
}
int F_87 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_111 * V_112 = V_22 -> V_113 ;
unsigned int V_76 = V_22 -> V_77 ;
struct V_75 * V_10 ;
unsigned int V_47 , V_174 ;
int error ;
if ( V_22 -> V_52 [ 0 ] . V_16 != NULL )
return 0 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ ) {
V_10 = V_22 -> V_52 + V_47 ;
error = F_88 ( V_112 , V_22 -> V_23 + V_47 , 0 , & V_10 -> V_16 ) ;
if ( error )
goto V_137;
}
for ( V_174 = V_76 ; V_174 -- ; ) {
V_10 = V_22 -> V_52 + V_174 ;
error = F_89 ( V_74 , V_10 -> V_16 ) ;
if ( error )
goto V_137;
if ( F_90 ( V_74 , V_10 -> V_16 , V_174 ? V_175 :
V_176 ) ) {
error = - V_122 ;
goto V_137;
}
}
if ( ! ( V_22 -> V_144 & V_145 ) ) {
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ )
F_46 ( V_105 , & V_22 -> V_52 [ V_47 ] . V_106 ) ;
F_77 ( V_22 , ( V_22 -> V_52 [ 0 ] . V_16 ) -> V_17 ) ;
V_22 -> V_144 |= ( V_145 | V_177 ) ;
V_22 -> V_178 = V_22 -> V_78 ;
}
if ( F_63 ( V_168 ) != V_22 -> V_140 -> V_167 ) {
V_22 -> V_140 -> V_171 = F_79 ( F_84 ( V_22 ) ) ;
F_82 ( V_22 -> V_140 ,
V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
}
else if ( V_74 -> V_179 . V_180 ) {
if ( ! F_81 ( V_22 ) ) {
F_6 ( V_22 ) ;
error = - V_122 ;
goto V_137;
}
if ( V_22 -> V_140 -> V_171 == 0 )
V_22 -> V_144 &= ~ V_177 ;
}
return 0 ;
V_137:
while ( V_47 -- ) {
V_10 = V_22 -> V_52 + V_47 ;
F_91 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
F_92 ( V_74 , ! V_10 -> V_25 ) ;
}
return error ;
}
int F_93 ( struct V_68 * V_22 )
{
T_4 V_163 ;
if ( V_22 -> V_144 & V_145 )
return 0 ;
if ( F_63 ( V_168 ) != V_22 -> V_140 -> V_167 )
return F_87 ( V_22 ) ;
V_163 = F_63 ( V_22 -> V_140 -> V_163 ) ;
V_163 &= ~ V_155 ;
V_22 -> V_144 &= V_155 ;
V_22 -> V_144 |= ( V_163 | V_145 | V_177 ) ;
if ( V_22 -> V_140 -> V_171 == 0 )
V_22 -> V_144 &= ~ V_177 ;
V_22 -> V_78 = F_63 ( V_22 -> V_140 -> V_164 ) ;
V_22 -> V_178 = V_22 -> V_78 ;
V_22 -> V_79 = F_63 ( V_22 -> V_140 -> V_165 ) ;
V_22 -> V_158 = F_69 ( V_22 -> V_140 -> V_166 ) ;
return 0 ;
}
int F_94 ( struct V_149 * V_181 )
{
struct V_68 * V_22 = V_181 -> V_182 -> V_115 ;
struct V_73 * V_74 = V_22 -> V_55 ;
if ( V_181 -> V_183 & V_184 && V_74 -> V_179 . V_180 )
return 0 ;
return F_87 ( (struct V_68 * ) V_181 -> V_182 -> V_115 ) ;
}
void F_95 ( struct V_149 * V_181 )
{
struct V_68 * V_22 = V_181 -> V_182 -> V_115 ;
int V_47 , V_76 = V_22 -> V_77 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ ) {
struct V_75 * V_10 = V_22 -> V_52 + V_47 ;
if ( V_10 -> V_16 ) {
F_91 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
}
}
}
int F_96 ( struct V_73 * V_74 , T_2 V_13 ,
struct V_185 * V_186 ,
const struct V_75 * V_10 , unsigned V_187 , T_2 * V_188 )
{
struct V_189 * V_190 = V_74 -> V_191 ;
T_2 V_33 ;
T_6 V_65 = 0 ;
T_6 V_192 = 0 ;
int V_193 ;
unsigned int V_47 ;
T_4 V_194 = 0 ;
T_1 V_195 ;
for ( V_47 = 0 ; V_47 < V_10 -> V_11 ; V_47 ++ ) {
const T_1 * V_196 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_16 -> V_17 ;
V_196 += V_10 -> V_18 ;
V_196 += V_47 ;
if ( V_186 ) {
const T_1 * V_197 = V_186 -> V_17 + V_10 -> V_18 + V_47 ;
V_195 = ~ ( * V_197 | ( * V_197 >> 1 ) ) & ( * V_196 | ( * V_196 >> 1 ) ) ;
} else {
V_195 = ~ ( * V_196 | ( * V_196 >> 1 ) ) ;
}
V_195 &= 0x55 ;
if ( V_195 == 0 )
continue;
V_33 = V_13 + ( ( V_10 -> V_24 + V_47 ) * V_14 ) ;
while( V_195 ) {
if ( V_195 & 1 ) {
if ( V_192 == 0 )
goto V_198;
if ( ( V_65 + V_192 ) != V_33 ) {
if ( V_192 >= V_187 ) {
V_193 = F_97 ( V_190 ,
V_65 , V_192 ,
V_96 , 0 ) ;
if ( V_193 )
goto V_137;
V_194 += V_192 ;
}
V_192 = 0 ;
V_198:
V_65 = V_33 ;
}
V_192 ++ ;
}
V_195 >>= 2 ;
V_33 ++ ;
}
}
if ( V_192 >= V_187 ) {
V_193 = F_97 ( V_190 , V_65 , V_192 , V_96 , 0 ) ;
if ( V_193 )
goto V_137;
V_194 += V_192 ;
}
if ( V_188 )
* V_188 = V_194 ;
return 0 ;
V_137:
if ( V_74 -> V_179 . V_199 )
F_98 ( V_74 , L_15 , V_193 ) ;
V_74 -> V_179 . V_199 = 0 ;
return - V_122 ;
}
int F_99 ( struct V_200 * V_201 , void T_7 * V_202 )
{
struct V_108 * V_108 = F_100 ( V_201 ) ;
struct V_73 * V_74 = F_68 ( V_108 ) ;
struct V_203 * V_204 = F_101 ( V_74 -> V_191 -> V_205 ) ;
struct V_185 * V_186 ;
struct V_68 * V_22 ;
struct V_68 * V_206 ;
struct V_149 V_181 ;
struct V_207 V_208 ;
int V_209 = 0 ;
T_2 V_210 ;
T_2 V_194 = 0 ;
T_2 V_65 , V_7 , V_187 ;
unsigned int V_47 ;
unsigned V_211 = V_74 -> V_120 . V_212 ;
if ( ! F_102 ( V_213 ) )
return - V_214 ;
if ( ! F_103 ( V_204 ) )
return - V_215 ;
if ( F_104 ( & V_208 , V_202 , sizeof( V_208 ) ) )
return - V_216 ;
V_209 = F_73 ( V_74 ) ;
if ( V_209 )
return V_209 ;
V_65 = V_208 . V_65 >> V_211 ;
V_7 = V_65 + ( V_208 . V_34 >> V_211 ) ;
V_187 = F_105 ( T_2 , V_208 . V_187 ,
V_204 -> V_217 . V_218 ) >> V_211 ;
V_22 = F_25 ( V_74 , V_65 , 0 ) ;
V_206 = F_25 ( V_74 , V_7 - 1 , 0 ) ;
if ( V_7 <= V_65 ||
V_187 > V_74 -> V_146 ||
V_65 > V_206 -> V_46 + V_206 -> V_50 )
return - V_49 ;
while ( 1 ) {
V_209 = F_75 ( V_22 -> V_113 , V_219 , 0 , & V_181 ) ;
if ( V_209 )
goto V_66;
if ( ! ( V_22 -> V_144 & V_220 ) ) {
for ( V_47 = 0 ; V_47 < V_22 -> V_77 ; V_47 ++ ) {
struct V_75 * V_10 = V_22 -> V_52 + V_47 ;
V_209 = F_96 ( V_74 ,
V_22 -> V_46 , NULL , V_10 , V_187 ,
& V_210 ) ;
if ( V_209 ) {
F_76 ( & V_181 ) ;
goto V_66;
}
V_194 += V_210 ;
}
V_209 = F_106 ( V_74 , V_221 , 0 ) ;
if ( V_209 == 0 ) {
V_186 = V_22 -> V_52 [ 0 ] . V_16 ;
V_22 -> V_144 |= V_220 ;
F_107 ( V_22 -> V_113 , V_186 ) ;
F_78 ( V_22 , V_186 -> V_17 ) ;
F_82 ( V_22 -> V_140 , V_186 -> V_17 ) ;
F_108 ( V_74 ) ;
}
}
F_76 ( & V_181 ) ;
if ( V_22 == V_206 )
break;
V_22 = F_31 ( V_22 ) ;
}
V_66:
V_208 . V_34 = V_194 << 9 ;
if ( F_109 ( V_202 , & V_208 , sizeof( V_208 ) ) )
return - V_216 ;
return V_209 ;
}
static void F_110 ( struct V_91 * V_92 )
{
struct V_83 * * V_129 , * V_130 = NULL ;
int V_222 ;
struct V_35 * V_36 = V_92 -> V_94 ;
struct V_68 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_223 = F_11 ( & V_36 -> V_38 ) ;
F_2 ( F_43 ( V_36 ) ) ;
F_26 ( & V_22 -> V_107 ) ;
V_129 = & V_22 -> V_103 . V_83 ;
while ( * V_129 ) {
struct V_35 * V_85 =
F_27 ( * V_129 , struct V_35 , V_98 ) ;
V_130 = * V_129 ;
V_222 = F_10 ( V_223 , V_36 -> V_39 , V_85 ) ;
if ( V_222 > 0 )
V_129 = & ( ( * V_129 ) -> V_90 ) ;
else if ( V_222 < 0 )
V_129 = & ( ( * V_129 ) -> V_89 ) ;
else {
F_28 ( & V_22 -> V_107 ) ;
F_85 ( 1 ) ;
return;
}
}
F_65 ( & V_36 -> V_98 , V_130 , V_129 ) ;
F_66 ( & V_36 -> V_98 , & V_22 -> V_103 ) ;
V_22 -> V_104 += V_36 -> V_39 ;
F_28 ( & V_22 -> V_107 ) ;
F_44 ( V_36 , V_224 ) ;
}
static void F_111 ( struct V_68 * V_22 , struct V_91 * V_92 ,
unsigned V_225 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_92 -> V_94 ;
T_4 V_226 ;
T_4 V_227 = V_22 -> V_178 - V_22 -> V_104 ;
int V_209 ;
struct V_108 * V_108 = & V_92 -> V_109 ;
if ( F_112 ( V_108 -> V_228 ) )
V_226 = 1 ;
else {
V_226 = F_105 ( T_4 , F_50 ( & V_36 -> V_229 ) , V_225 ) ;
V_226 = F_113 ( V_226 , V_230 , V_227 ) ;
}
if ( ( V_22 -> V_178 < V_22 -> V_104 ) || ( V_227 < V_226 ) )
return;
if ( F_24 ( V_22 , V_92 -> V_231 ) )
V_41 = V_92 -> V_231 ;
else
V_41 = V_22 -> V_232 + V_22 -> V_46 ;
if ( F_85 ( F_15 ( & V_2 , V_41 ) ) )
return;
V_209 = F_114 ( & V_2 , V_60 , V_226 , V_92 , true ) ;
if ( V_209 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_226 ;
V_36 -> V_101 = V_92 -> V_233 ;
F_110 ( V_92 ) ;
} else {
if ( V_41 == V_22 -> V_232 + V_22 -> V_46 )
V_22 -> V_232 = 0 ;
}
}
static T_2 F_115 ( struct V_68 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_91 * V_92 )
{
struct V_35 * V_36 ;
struct V_83 * V_58 ;
int V_222 ;
F_26 ( & V_22 -> V_107 ) ;
V_58 = V_22 -> V_103 . V_83 ;
while ( V_58 ) {
V_36 = F_27 ( V_58 , struct V_35 , V_98 ) ;
V_222 = F_10 ( V_44 , V_76 , V_36 ) ;
if ( V_222 < 0 )
V_58 = V_58 -> V_89 ;
else if ( V_222 > 0 )
V_58 = V_58 -> V_90 ;
else
break;
}
if ( V_58 ) {
while ( ( F_10 ( V_44 , V_76 , V_36 ) == 0 ) && ( V_92 -> V_94 != V_36 ) ) {
V_44 = F_11 ( & V_36 -> V_38 ) + V_36 -> V_39 ;
V_58 = V_58 -> V_90 ;
if ( V_58 == NULL )
break;
V_36 = F_27 ( V_58 , struct V_35 , V_98 ) ;
}
}
F_28 ( & V_22 -> V_107 ) ;
return V_44 ;
}
static int F_116 ( struct V_1 * V_2 ,
const struct V_91 * V_92 ,
T_4 V_234 )
{
T_2 V_44 = F_11 ( V_2 ) ;
T_4 V_226 = 1 ;
T_2 V_235 ;
int V_209 ;
if ( V_234 ) {
V_226 = F_18 ( V_2 , V_234 ) ;
V_235 = V_44 + V_226 ;
if ( V_226 < V_234 )
goto V_137;
}
V_235 = F_115 ( V_2 -> V_22 , V_44 , V_226 , V_92 ) ;
if ( V_235 == V_44 )
return 0 ;
V_137:
V_209 = F_15 ( V_2 , V_235 ) ;
if ( V_209 < 0 )
return V_209 ;
return 1 ;
}
static int F_114 ( struct V_1 * V_2 , T_1 V_30 , T_4 V_234 ,
const struct V_91 * V_92 , bool V_236 )
{
struct V_185 * V_186 ;
struct V_75 * V_237 ;
T_4 V_238 ;
T_4 V_13 ;
T_1 * V_26 ;
int V_239 ;
int V_58 = 0 ;
int V_240 = V_2 -> V_22 -> V_77 ;
int V_209 ;
if ( V_2 -> V_13 != 0 )
V_240 ++ ;
while( 1 ) {
if ( F_117 ( V_105 , & V_2 -> V_10 -> V_106 ) &&
( V_30 == V_60 ) )
goto V_241;
V_186 = V_2 -> V_10 -> V_16 ;
V_26 = V_186 -> V_17 + V_2 -> V_10 -> V_18 ;
F_85 ( ! F_86 ( V_186 ) ) ;
if ( V_30 != V_173 && V_2 -> V_10 -> V_25 )
V_26 = V_2 -> V_10 -> V_25 + V_2 -> V_10 -> V_18 ;
V_238 = V_2 -> V_13 ;
V_13 = F_12 ( V_26 , V_2 -> V_10 -> V_11 , V_2 -> V_13 , V_30 ) ;
if ( V_13 == V_43 )
goto V_242;
V_2 -> V_13 = V_13 ;
if ( V_92 == NULL )
return 0 ;
V_237 = V_2 -> V_10 ;
V_209 = F_116 ( V_2 , V_92 , V_234 ) ;
if ( V_209 == 0 )
return 0 ;
if ( V_209 > 0 ) {
V_58 += ( V_2 -> V_10 - V_237 ) ;
goto V_243;
}
if ( V_209 == - V_51 ) {
V_239 = 0 ;
V_2 -> V_13 = 0 ;
V_58 += ( V_2 -> V_10 - V_237 ) ;
goto V_244;
}
return V_209 ;
V_242:
if ( ( V_30 == V_60 ) && V_238 == 0 )
F_118 ( V_105 , & V_2 -> V_10 -> V_106 ) ;
V_241:
V_2 -> V_13 = 0 ;
V_239 = V_2 -> V_10 - V_2 -> V_22 -> V_52 ;
V_239 ++ ;
if ( V_239 == V_2 -> V_22 -> V_77 )
V_239 = 0 ;
V_244:
V_2 -> V_10 = & V_2 -> V_22 -> V_52 [ V_239 ] ;
if ( ( V_239 == 0 ) && V_236 )
break;
V_58 ++ ;
V_243:
if ( V_58 >= V_240 )
break;
}
return - V_245 ;
}
static void F_119 ( struct V_68 * V_22 , T_2 * V_246 , T_2 V_247 )
{
T_2 V_44 ;
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_111 * V_112 ;
struct V_91 * V_92 ;
int error ;
int V_248 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_10 = V_22 -> V_52 , . V_13 = 0 } ;
while ( 1 ) {
F_36 ( & V_74 -> V_249 ) ;
error = F_114 ( & V_2 , V_173 , 0 , NULL , true ) ;
F_39 ( & V_74 -> V_249 ) ;
if ( error == - V_245 )
break;
if ( F_16 ( error ) )
break;
V_44 = F_11 ( & V_2 ) ;
if ( F_15 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_246 != V_250 && V_44 <= * V_246 )
continue;
if ( V_44 == V_247 )
continue;
* V_246 = V_44 ;
error = F_71 ( V_74 , V_44 , & V_251 , V_139 , & V_112 ) ;
if ( error )
continue;
V_92 = V_112 -> V_115 ;
if ( V_92 || F_120 ( V_252 , & V_112 -> V_253 ) == 0 )
F_55 ( V_112 ) ;
else
V_248 ++ ;
if ( V_248 > V_254 )
return;
}
V_22 -> V_144 &= ~ V_177 ;
return;
}
static bool F_121 ( const struct V_68 * V_22 , int V_255 )
{
const struct V_111 * V_112 = V_22 -> V_113 ;
const struct V_73 * V_74 = V_112 -> V_256 ;
struct V_257 * V_258 ;
T_8 V_259 , V_260 ;
T_8 V_261 , V_262 ;
T_8 V_263 ;
T_8 V_264 ;
T_8 V_265 ;
F_122 () ;
V_258 = & F_123 ( V_74 -> V_266 ) -> V_267 [ V_268 ] ;
V_261 = V_258 -> V_269 [ V_270 ] ;
V_259 = V_258 -> V_269 [ V_271 ] ;
V_265 = V_258 -> V_269 [ V_272 ] +
V_112 -> V_273 . V_269 [ V_272 ] ;
F_124 () ;
V_262 = V_112 -> V_273 . V_269 [ V_270 ] ;
V_260 = V_112 -> V_273 . V_269 [ V_271 ] ;
if ( ( V_260 < 1 ) || ( V_259 < 1 ) || ( V_261 == 0 ) )
return false ;
V_263 = V_261 - V_262 ;
V_264 = V_263 * V_263 ;
V_265 *= 2 ;
if ( V_260 < 8 || V_259 < 8 )
V_265 *= 2 ;
if ( V_255 == 1 )
V_265 *= 2 ;
return ( ( V_263 < 0 ) && ( V_264 > V_265 ) ) ;
}
static bool F_125 ( const struct V_35 * V_36 ,
T_2 V_274 )
{
T_2 V_275 ;
V_275 = F_126 ( F_127 ( F_128 () ,
V_36 -> V_38 . V_22 -> V_113 -> V_276 ) ) ;
return V_275 > ( V_274 * 1000 * 1000 ) ;
}
static T_4 F_129 ( const struct V_91 * V_92 )
{
const struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
T_4 V_247 ;
F_130 ( & V_247 , sizeof( V_247 ) ) ;
return V_247 % V_74 -> V_132 ;
}
static bool F_131 ( struct V_68 * * V_127 , const struct V_68 * V_277 )
{
struct V_68 * V_22 = * V_127 ;
struct V_73 * V_74 = V_22 -> V_55 ;
V_22 = F_31 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_29 ( V_74 ) ;
* V_127 = V_22 ;
if ( V_22 != V_277 )
return true ;
return false ;
}
int F_132 ( struct V_91 * V_92 , T_4 V_225 , T_4 V_278 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
struct V_68 * V_277 = NULL ;
struct V_35 * V_36 = V_92 -> V_94 ;
int error = 0 , V_279 , V_280 = 0 ;
T_2 V_246 = V_250 ;
int V_255 = 0 ;
T_4 V_247 = 0 ;
if ( V_74 -> V_179 . V_180 )
V_280 |= V_184 ;
if ( F_92 ( V_74 , V_225 ) )
return - V_49 ;
if ( F_43 ( V_36 ) ) {
V_277 = V_36 -> V_38 . V_22 ;
V_280 = 0 ;
} else if ( V_92 -> V_281 && F_24 ( V_92 -> V_281 , V_92 -> V_231 ) ) {
V_36 -> V_38 . V_22 = V_277 = V_92 -> V_281 ;
} else {
V_36 -> V_38 . V_22 = V_277 = F_25 ( V_74 , V_92 -> V_231 , 1 ) ;
}
if ( F_112 ( V_92 -> V_109 . V_228 ) && ( V_278 & V_282 ) )
V_247 = F_129 ( V_92 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_283 ;
while ( V_255 < 3 ) {
V_279 = 1 ;
if ( ! F_74 ( V_36 -> V_38 . V_22 -> V_113 ) ) {
V_279 = 0 ;
if ( V_247 && V_247 -- )
goto V_284;
if ( ! F_43 ( V_36 ) && ( V_255 < 2 ) &&
F_125 ( V_36 , 1000 ) &&
F_121 ( V_36 -> V_38 . V_22 , V_255 ) )
goto V_284;
error = F_75 ( V_36 -> V_38 . V_22 -> V_113 ,
V_219 , V_280 ,
& V_36 -> V_285 ) ;
if ( F_3 ( error ) )
return error ;
if ( ! F_43 ( V_36 ) && ( V_255 < 2 ) &&
F_121 ( V_36 -> V_38 . V_22 , V_255 ) )
goto V_286;
if ( V_74 -> V_179 . V_180 ) {
error = F_93 ( V_36 -> V_38 . V_22 ) ;
if ( F_3 ( error ) ) {
F_76 ( & V_36 -> V_285 ) ;
return error ;
}
}
}
if ( V_36 -> V_38 . V_22 -> V_144 & ( V_287 | V_288 ) )
goto V_286;
if ( V_74 -> V_179 . V_180 )
F_87 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_43 ( V_36 ) )
F_111 ( V_36 -> V_38 . V_22 , V_92 , V_225 ) ;
if ( ! F_43 ( V_36 ) && ( V_255 < 1 ) )
goto V_289;
if ( V_36 -> V_38 . V_22 -> V_178 >= V_225 ) {
V_92 -> V_281 = V_36 -> V_38 . V_22 ;
return 0 ;
}
if ( F_43 ( V_36 ) )
F_48 ( V_36 ) ;
V_289:
if ( V_36 -> V_38 . V_22 -> V_144 & V_177 )
F_119 ( V_36 -> V_38 . V_22 , & V_246 ,
V_92 -> V_233 ) ;
V_286:
if ( ! V_279 )
F_76 ( & V_36 -> V_285 ) ;
V_284:
if ( F_131 ( & V_36 -> V_38 . V_22 , V_277 ) )
continue;
if ( V_247 )
continue;
V_255 ++ ;
if ( V_92 == F_60 ( V_74 -> V_124 ) && ! V_74 -> V_147 ) {
error = F_72 ( V_92 ) ;
if ( error )
return error ;
}
if ( V_255 == 2 )
F_133 ( V_74 , NULL ) ;
}
return - V_245 ;
}
void F_134 ( struct V_91 * V_92 )
{
struct V_35 * V_36 = V_92 -> V_94 ;
if ( V_36 -> V_285 . V_182 )
F_76 ( & V_36 -> V_285 ) ;
}
static unsigned char F_135 ( struct V_68 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_209 ;
V_209 = F_15 ( & V_2 , V_44 ) ;
F_16 ( V_209 != 0 ) ;
return F_7 ( & V_2 ) ;
}
static void F_136 ( const struct V_1 * V_2 , bool V_290 ,
unsigned int * V_58 )
{
struct V_1 V_127 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_291 = * V_58 ;
T_2 V_44 ;
int V_209 ;
* V_58 = 1 ;
V_44 = F_11 ( V_2 ) ;
F_107 ( V_2 -> V_22 -> V_113 , V_2 -> V_10 -> V_16 ) ;
F_1 ( V_2 , true , V_290 ? V_292 : V_293 ) ;
V_44 ++ ;
while ( * V_58 < V_291 ) {
V_209 = F_15 ( & V_127 , V_44 ) ;
if ( V_209 || F_7 ( & V_127 ) != V_60 )
break;
F_107 ( V_127 . V_22 -> V_113 , V_127 . V_10 -> V_16 ) ;
F_1 ( & V_127 , true , V_293 ) ;
( * V_58 ) ++ ;
V_44 ++ ;
}
}
static struct V_68 * F_137 ( struct V_73 * V_74 , T_2 V_294 ,
T_4 V_295 , unsigned char V_4 )
{
struct V_1 V_2 ;
V_2 . V_22 = F_25 ( V_74 , V_294 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_138 ( V_74 ) )
F_23 ( V_74 , L_16 , ( unsigned long long ) V_294 ) ;
return NULL ;
}
while ( V_295 -- ) {
F_15 ( & V_2 , V_294 ) ;
V_294 ++ ;
if ( ! V_2 . V_10 -> V_25 ) {
V_2 . V_10 -> V_25 = F_139 ( V_2 . V_10 -> V_16 -> V_67 ,
V_96 | V_296 ) ;
memcpy ( V_2 . V_10 -> V_25 + V_2 . V_10 -> V_18 ,
V_2 . V_10 -> V_16 -> V_17 + V_2 . V_10 -> V_18 ,
V_2 . V_10 -> V_11 ) ;
}
F_107 ( V_2 . V_22 -> V_113 , V_2 . V_10 -> V_16 ) ;
F_1 ( & V_2 , false , V_4 ) ;
}
return V_2 . V_22 ;
}
int F_140 ( struct V_99 * V_100 , const struct V_111 * V_112 )
{
struct V_68 * V_22 = V_112 -> V_115 ;
struct V_35 * V_297 ;
const struct V_83 * V_58 ;
if ( V_22 == NULL )
return 0 ;
F_41 ( V_100 , L_17 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_144 ,
V_22 -> V_78 , V_22 -> V_178 , V_22 -> V_79 ,
V_22 -> V_104 ) ;
F_26 ( & V_22 -> V_107 ) ;
for ( V_58 = F_30 ( & V_22 -> V_103 ) ; V_58 ; V_58 = F_32 ( & V_297 -> V_98 ) ) {
V_297 = F_27 ( V_58 , struct V_35 , V_98 ) ;
F_40 ( V_100 , V_297 ) ;
}
F_28 ( & V_22 -> V_107 ) ;
return 0 ;
}
static void F_141 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
F_98 ( V_74 , L_18 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_98 ( V_74 , L_19 ) ;
F_140 ( NULL , V_22 -> V_113 ) ;
V_22 -> V_144 |= V_288 ;
}
static void F_142 ( struct V_91 * V_92 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_92 -> V_94 ;
struct V_68 * V_22 = V_2 -> V_22 ;
unsigned V_298 ;
T_2 V_44 ;
int V_209 ;
F_26 ( & V_22 -> V_107 ) ;
if ( F_43 ( V_36 ) ) {
if ( F_143 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_11 ( V_2 ) ;
V_209 = F_15 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_298 = F_144 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_298 ;
V_22 -> V_104 -= V_298 ;
F_44 ( V_36 , V_299 ) ;
if ( V_36 -> V_39 && ! V_209 )
goto V_66;
}
F_42 ( V_36 ) ;
}
V_66:
F_28 ( & V_22 -> V_107 ) ;
}
int F_145 ( struct V_91 * V_92 , T_2 * V_300 , unsigned int * V_301 ,
bool V_290 , T_2 * V_302 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
struct V_185 * V_303 ;
struct V_1 V_2 = { . V_22 = V_92 -> V_281 , } ;
unsigned int V_304 ;
T_2 V_41 ;
T_2 V_44 ;
int error ;
if ( F_43 ( V_92 -> V_94 ) )
V_41 = F_11 ( & V_92 -> V_94 -> V_38 ) ;
else if ( ! V_290 && F_24 ( V_2 . V_22 , V_92 -> V_231 ) )
V_41 = V_92 -> V_231 ;
else
V_41 = V_2 . V_22 -> V_232 + V_2 . V_22 -> V_46 ;
F_15 ( & V_2 , V_41 ) ;
error = F_114 ( & V_2 , V_60 , 0 , V_92 , false ) ;
if ( error == - V_245 ) {
F_15 ( & V_2 , V_41 ) ;
error = F_114 ( & V_2 , V_60 , 0 , NULL , false ) ;
}
if ( error ) {
F_98 ( V_74 , L_20 ,
( unsigned long long ) V_92 -> V_233 , error , * V_301 ,
F_117 ( V_105 , & V_2 . V_22 -> V_52 -> V_106 ) ) ;
goto V_305;
}
F_136 ( & V_2 , V_290 , V_301 ) ;
V_44 = F_11 ( & V_2 ) ;
V_2 . V_22 -> V_232 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_43 ( V_92 -> V_94 ) )
F_142 ( V_92 , & V_2 , * V_301 ) ;
V_304 = * V_301 ;
if ( V_290 )
V_304 -- ;
if ( ! V_290 ) {
V_92 -> V_231 = V_44 + V_304 - 1 ;
error = F_146 ( V_92 , & V_303 ) ;
if ( error == 0 ) {
struct V_306 * V_307 =
(struct V_306 * ) V_303 -> V_17 ;
F_107 ( V_92 -> V_148 , V_303 ) ;
V_307 -> V_308 = V_307 -> V_309 =
F_80 ( V_92 -> V_231 ) ;
F_91 ( V_303 ) ;
}
}
if ( V_2 . V_22 -> V_78 < * V_301 ) {
F_4 ( V_21 L_21 , * V_301 ) ;
goto V_305;
}
V_2 . V_22 -> V_78 -= * V_301 ;
if ( V_290 ) {
V_2 . V_22 -> V_79 ++ ;
* V_302 = V_2 . V_22 -> V_158 ++ ;
if ( * V_302 == 0 )
* V_302 = V_2 . V_22 -> V_158 ++ ;
}
F_107 ( V_2 . V_22 -> V_113 , V_2 . V_22 -> V_52 [ 0 ] . V_16 ) ;
F_78 ( V_2 . V_22 , V_2 . V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_2 . V_22 -> V_140 , V_2 . V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_147 ( V_74 , 0 , - ( T_8 ) * V_301 , V_290 ? 1 : 0 ) ;
if ( V_290 )
F_148 ( V_74 , V_44 , 1 ) ;
F_149 ( V_92 , * V_301 , V_92 -> V_109 . V_310 , V_92 -> V_109 . V_311 ) ;
V_2 . V_22 -> V_178 -= * V_301 ;
F_150 ( V_92 , V_2 . V_22 , V_44 , * V_301 ,
V_290 ? V_292 : V_293 ) ;
* V_300 = V_44 ;
return 0 ;
V_305:
F_141 ( V_2 . V_22 ) ;
return - V_122 ;
}
void F_151 ( struct V_91 * V_92 , T_2 V_294 , T_4 V_295 , int V_312 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
struct V_68 * V_22 ;
V_22 = F_137 ( V_74 , V_294 , V_295 , V_60 ) ;
if ( ! V_22 )
return;
F_150 ( V_92 , V_22 , V_294 , V_295 , V_60 ) ;
V_22 -> V_78 += V_295 ;
V_22 -> V_144 &= ~ V_220 ;
F_107 ( V_22 -> V_113 , V_22 -> V_52 [ 0 ] . V_16 ) ;
F_78 ( V_22 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 -> V_140 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
if ( V_312 || V_92 -> V_313 )
F_152 ( V_92 , V_294 , V_295 ) ;
}
void F_153 ( struct V_91 * V_92 , T_2 V_294 , T_4 V_295 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
F_151 ( V_92 , V_294 , V_295 , 1 ) ;
F_147 ( V_74 , 0 , + V_295 , 0 ) ;
F_149 ( V_92 , - ( T_8 ) V_295 , V_92 -> V_109 . V_310 , V_92 -> V_109 . V_311 ) ;
}
void F_154 ( struct V_108 * V_108 )
{
struct V_91 * V_92 = F_60 ( V_108 ) ;
struct V_73 * V_74 = F_68 ( V_108 ) ;
struct V_68 * V_22 ;
T_2 V_314 = V_92 -> V_233 ;
V_22 = F_137 ( V_74 , V_314 , 1 , V_173 ) ;
if ( ! V_22 )
return;
F_150 ( V_92 , V_22 , V_314 , 1 , V_173 ) ;
F_107 ( V_22 -> V_113 , V_22 -> V_52 [ 0 ] . V_16 ) ;
F_78 ( V_22 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 -> V_140 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_83 ( V_22 , 1 ) ;
}
static void F_155 ( struct V_68 * V_22 , T_2 V_314 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_68 * V_315 ;
V_315 = F_137 ( V_74 , V_314 , 1 , V_60 ) ;
if ( ! V_315 )
return;
F_156 ( V_74 , V_22 == V_315 ) ;
if ( ! V_22 -> V_79 )
F_6 ( V_22 ) ;
V_22 -> V_79 -- ;
V_22 -> V_78 ++ ;
F_107 ( V_22 -> V_113 , V_22 -> V_52 [ 0 ] . V_16 ) ;
F_78 ( V_22 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 -> V_140 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_83 ( V_22 , - 1 ) ;
F_147 ( V_74 , 0 , + 1 , - 1 ) ;
}
void F_157 ( struct V_68 * V_22 , struct V_91 * V_92 )
{
F_155 ( V_22 , V_92 -> V_233 ) ;
F_150 ( V_92 , V_22 , V_92 -> V_233 , 1 , V_60 ) ;
F_149 ( V_92 , - 1 , V_92 -> V_109 . V_310 , V_92 -> V_109 . V_311 ) ;
F_152 ( V_92 , V_92 -> V_233 , 1 ) ;
}
int F_158 ( struct V_73 * V_74 , T_2 V_316 , unsigned int type )
{
struct V_68 * V_22 ;
struct V_149 V_317 ;
int error = - V_49 ;
V_22 = F_25 ( V_74 , V_316 , 1 ) ;
if ( ! V_22 )
goto V_137;
error = F_75 ( V_22 -> V_113 , V_152 , 0 , & V_317 ) ;
if ( error )
goto V_137;
if ( F_135 ( V_22 , V_316 ) != type )
error = - V_318 ;
F_76 ( & V_317 ) ;
V_137:
return error ;
}
void F_159 ( struct V_91 * V_92 , struct V_319 * V_320 ,
T_2 V_44 )
{
struct V_73 * V_74 = F_68 ( & V_92 -> V_109 ) ;
struct V_68 * V_22 ;
struct V_68 * * V_31 ;
unsigned int V_321 ;
unsigned int V_47 ;
if ( F_92 ( V_74 , ! V_320 -> V_322 ) )
return;
if ( V_92 -> V_281 && F_24 ( V_92 -> V_281 , V_44 ) )
V_22 = V_92 -> V_281 ;
else
V_22 = F_25 ( V_74 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_23 ( V_74 , L_22 , ( unsigned long long ) V_44 ) ;
return;
}
V_92 -> V_281 = V_22 ;
for ( V_47 = 0 ; V_47 < V_320 -> V_323 ; V_47 ++ )
if ( V_320 -> V_324 [ V_47 ] == V_22 )
return;
if ( V_320 -> V_323 == V_320 -> V_325 ) {
V_321 = V_320 -> V_325 + 10 ;
V_31 = F_58 ( V_321 , sizeof( struct V_68 * ) ,
V_96 | V_296 ) ;
if ( V_320 -> V_324 ) {
memcpy ( V_31 , V_320 -> V_324 ,
V_320 -> V_325 * sizeof( struct V_68 * ) ) ;
F_34 ( V_320 -> V_324 ) ;
}
V_320 -> V_325 = V_321 ;
V_320 -> V_324 = V_31 ;
}
V_320 -> V_324 [ V_320 -> V_323 ++ ] = V_22 ;
}
void F_160 ( struct V_319 * V_320 , unsigned int V_30 )
{
unsigned int V_47 ;
V_320 -> V_322 = F_58 ( V_320 -> V_323 , sizeof( struct V_149 ) ,
V_96 | V_296 ) ;
for ( V_47 = 0 ; V_47 < V_320 -> V_323 ; V_47 ++ )
F_161 ( V_320 -> V_324 [ V_47 ] -> V_113 ,
V_30 , 0 ,
& V_320 -> V_322 [ V_47 ] ) ;
}
void F_162 ( struct V_319 * V_320 )
{
unsigned int V_47 ;
F_34 ( V_320 -> V_324 ) ;
if ( V_320 -> V_322 ) {
for ( V_47 = 0 ; V_47 < V_320 -> V_323 ; V_47 ++ )
F_163 ( & V_320 -> V_322 [ V_47 ] ) ;
F_34 ( V_320 -> V_322 ) ;
V_320 -> V_322 = NULL ;
}
}
