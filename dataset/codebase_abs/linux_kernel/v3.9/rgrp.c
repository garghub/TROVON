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
static void F_42 ( struct V_91 * V_92 , struct V_35 * V_36 )
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
void F_48 ( struct V_91 * V_92 , struct V_35 * V_36 )
{
struct V_68 * V_22 ;
V_22 = V_36 -> V_38 . V_22 ;
if ( V_22 ) {
F_26 ( & V_22 -> V_107 ) ;
F_42 ( V_92 , V_36 ) ;
F_28 ( & V_22 -> V_107 ) ;
}
}
void F_49 ( struct V_91 * V_92 )
{
F_36 ( & V_92 -> V_93 ) ;
if ( V_92 -> V_94 ) {
F_48 ( V_92 , V_92 -> V_94 ) ;
F_2 ( V_92 -> V_94 -> V_39 ) ;
F_50 ( V_95 , V_92 -> V_94 ) ;
V_92 -> V_94 = NULL ;
}
F_39 ( & V_92 -> V_93 ) ;
}
static void F_51 ( struct V_68 * V_22 )
{
struct V_83 * V_58 ;
struct V_35 * V_36 ;
F_26 ( & V_22 -> V_107 ) ;
while ( ( V_58 = F_30 ( & V_22 -> V_103 ) ) ) {
V_36 = F_27 ( V_58 , struct V_35 , V_98 ) ;
F_42 ( NULL , V_36 ) ;
}
F_28 ( & V_22 -> V_107 ) ;
}
void F_52 ( struct V_73 * V_74 )
{
struct V_83 * V_58 ;
struct V_68 * V_22 ;
struct V_108 * V_109 ;
while ( ( V_58 = F_30 ( & V_74 -> V_87 ) ) ) {
V_22 = F_27 ( V_58 , struct V_68 , V_88 ) ;
V_109 = V_22 -> V_110 ;
F_45 ( V_58 , & V_74 -> V_87 ) ;
if ( V_109 ) {
F_26 ( & V_109 -> V_111 ) ;
V_109 -> V_112 = NULL ;
F_28 ( & V_109 -> V_111 ) ;
F_53 ( V_109 ) ;
F_54 ( V_109 ) ;
}
F_33 ( V_22 ) ;
F_34 ( V_22 -> V_52 ) ;
F_51 ( V_22 ) ;
F_50 ( V_113 , V_22 ) ;
}
}
static void F_55 ( const struct V_68 * V_22 )
{
F_4 ( V_114 L_9 , ( unsigned long long ) V_22 -> V_23 ) ;
F_4 ( V_114 L_10 , V_22 -> V_77 ) ;
F_4 ( V_114 L_11 , ( unsigned long long ) V_22 -> V_46 ) ;
F_4 ( V_114 L_12 , V_22 -> V_50 ) ;
F_4 ( V_114 L_13 , V_22 -> V_115 ) ;
}
static int F_56 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_75 * V_10 ;
T_4 V_76 = V_22 -> V_77 ;
T_4 V_116 , V_63 ;
int V_47 ;
if ( ! V_76 )
return - V_49 ;
V_22 -> V_52 = F_57 ( V_76 , sizeof( struct V_75 ) , V_96 ) ;
if ( ! V_22 -> V_52 )
return - V_97 ;
V_116 = V_22 -> V_115 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ ) {
V_10 = V_22 -> V_52 + V_47 ;
V_10 -> V_106 = 0 ;
if ( V_76 == 1 ) {
V_63 = V_116 ;
V_10 -> V_18 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_11 = V_63 ;
} else if ( V_47 == 0 ) {
V_63 = V_74 -> V_117 . V_118 - sizeof( struct V_53 ) ;
V_10 -> V_18 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_11 = V_63 ;
} else if ( V_47 + 1 == V_76 ) {
V_63 = V_116 ;
V_10 -> V_18 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_115 - V_116 ;
V_10 -> V_11 = V_63 ;
} else {
V_63 = V_74 -> V_117 . V_118 -
sizeof( struct V_54 ) ;
V_10 -> V_18 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_115 - V_116 ;
V_10 -> V_11 = V_63 ;
}
V_116 -= V_63 ;
}
if ( V_116 ) {
F_6 ( V_22 ) ;
return - V_119 ;
}
V_10 = V_22 -> V_52 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_11 ) * V_14 != V_22 -> V_50 ) {
if ( F_6 ( V_22 ) ) {
F_55 ( V_22 ) ;
F_23 ( V_74 , L_14 ,
V_10 -> V_24 , V_10 -> V_11 , V_10 -> V_18 ) ;
}
return - V_119 ;
}
return 0 ;
}
T_2 F_58 ( struct V_73 * V_74 )
{
T_2 V_120 = 0 ;
struct V_121 * V_121 = V_74 -> V_122 ;
struct V_91 * V_92 = F_59 ( V_121 ) ;
char V_40 [ sizeof( struct V_123 ) ] ;
int error , V_124 ;
for ( V_124 = 0 ; ; V_124 ++ ) {
T_5 V_125 = V_124 * sizeof( struct V_123 ) ;
if ( V_125 + sizeof( struct V_123 ) > F_60 ( V_121 ) )
break;
error = F_61 ( V_92 , V_40 , & V_125 ,
sizeof( struct V_123 ) ) ;
if ( error != sizeof( struct V_123 ) )
break;
V_120 += F_62 ( ( (struct V_123 * ) V_40 ) -> V_126 ) ;
}
return V_120 ;
}
static int F_63 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_83 * * V_127 = & V_74 -> V_87 . V_83 , * V_128 = NULL ;
while ( * V_127 ) {
struct V_68 * V_85 = F_27 ( * V_127 , struct V_68 ,
V_88 ) ;
V_128 = * V_127 ;
if ( V_22 -> V_23 < V_85 -> V_23 )
V_127 = & ( ( * V_127 ) -> V_89 ) ;
else if ( V_22 -> V_23 > V_85 -> V_23 )
V_127 = & ( ( * V_127 ) -> V_90 ) ;
else
return - V_129 ;
}
F_64 ( & V_22 -> V_88 , V_128 , V_127 ) ;
F_65 ( & V_22 -> V_88 , & V_74 -> V_87 ) ;
V_74 -> V_130 ++ ;
return 0 ;
}
static int F_66 ( struct V_91 * V_92 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
T_5 V_125 = V_74 -> V_130 * sizeof( struct V_123 ) ;
struct V_123 V_40 ;
int error ;
struct V_68 * V_22 ;
if ( V_125 >= F_60 ( & V_92 -> V_131 ) )
return 1 ;
error = F_61 ( V_92 , ( char * ) & V_40 , & V_125 ,
sizeof( struct V_123 ) ) ;
if ( error != sizeof( struct V_123 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_37 ( V_113 , V_96 ) ;
error = - V_97 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_74 ;
V_22 -> V_23 = F_68 ( V_40 . V_132 ) ;
V_22 -> V_77 = F_62 ( V_40 . V_133 ) ;
V_22 -> V_46 = F_68 ( V_40 . V_134 ) ;
V_22 -> V_50 = F_62 ( V_40 . V_126 ) ;
V_22 -> V_115 = F_62 ( V_40 . V_135 ) ;
F_69 ( & V_22 -> V_107 ) ;
error = F_56 ( V_22 ) ;
if ( error )
goto V_136;
error = F_70 ( V_74 , V_22 -> V_23 ,
& V_137 , V_138 , & V_22 -> V_110 ) ;
if ( error )
goto V_136;
V_22 -> V_110 -> V_112 = V_22 ;
V_22 -> V_139 = (struct V_140 * ) V_22 -> V_110 -> V_141 . V_142 ;
V_22 -> V_143 &= ~ V_144 ;
if ( V_22 -> V_50 > V_74 -> V_145 )
V_74 -> V_145 = V_22 -> V_50 ;
F_26 ( & V_74 -> V_86 ) ;
error = F_63 ( V_22 ) ;
F_28 ( & V_74 -> V_86 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_54 ( V_22 -> V_110 ) ;
V_136:
F_34 ( V_22 -> V_52 ) ;
F_50 ( V_113 , V_22 ) ;
return error ;
}
static int F_71 ( struct V_91 * V_92 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
int error ;
do {
error = F_66 ( V_92 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_74 -> V_146 = 1 ;
return 0 ;
}
int F_72 ( struct V_73 * V_74 )
{
struct V_91 * V_92 = F_59 ( V_74 -> V_122 ) ;
struct V_108 * V_109 = V_92 -> V_147 ;
struct V_148 V_149 ;
int error = 0 ;
int V_150 = 0 ;
if ( ! V_74 -> V_146 ) {
if ( ! F_73 ( V_109 ) ) {
error = F_74 ( V_109 , V_151 , 0 , & V_149 ) ;
if ( error )
return error ;
V_150 = 1 ;
}
if ( ! V_74 -> V_146 )
error = F_71 ( V_92 ) ;
if ( V_150 )
F_75 ( & V_149 ) ;
}
return error ;
}
static void F_76 ( struct V_68 * V_22 , const void * V_40 )
{
const struct V_53 * V_152 = V_40 ;
T_4 V_153 ;
V_153 = F_62 ( V_152 -> V_153 ) ;
V_153 &= ~ V_154 ;
V_22 -> V_143 &= V_154 ;
V_22 -> V_143 |= V_153 ;
V_22 -> V_78 = F_62 ( V_152 -> V_155 ) ;
V_22 -> V_79 = F_62 ( V_152 -> V_156 ) ;
V_22 -> V_157 = F_68 ( V_152 -> V_158 ) ;
}
static void F_77 ( struct V_68 * V_22 , void * V_40 )
{
struct V_53 * V_152 = V_40 ;
V_152 -> V_153 = F_78 ( V_22 -> V_143 & ~ V_154 ) ;
V_152 -> V_155 = F_78 ( V_22 -> V_78 ) ;
V_152 -> V_156 = F_78 ( V_22 -> V_79 ) ;
V_152 -> V_159 = F_78 ( 0 ) ;
V_152 -> V_158 = F_79 ( V_22 -> V_157 ) ;
memset ( & V_152 -> V_160 , 0 , sizeof( V_152 -> V_160 ) ) ;
}
static int F_80 ( struct V_68 * V_22 )
{
struct V_140 * V_161 = V_22 -> V_139 ;
struct V_53 * V_152 = (struct V_53 * ) V_22 -> V_52 [ 0 ] . V_16 -> V_17 ;
if ( V_161 -> V_162 != V_152 -> V_153 || V_161 -> V_163 != V_152 -> V_155 ||
V_161 -> V_164 != V_152 -> V_156 ||
V_161 -> V_165 != V_152 -> V_158 )
return 0 ;
return 1 ;
}
static void F_81 ( struct V_140 * V_161 , const void * V_40 )
{
const struct V_53 * V_152 = V_40 ;
V_161 -> V_166 = F_78 ( V_167 ) ;
V_161 -> V_162 = V_152 -> V_153 ;
V_161 -> V_163 = V_152 -> V_155 ;
V_161 -> V_164 = V_152 -> V_156 ;
V_161 -> V_165 = V_152 -> V_158 ;
V_161 -> V_159 = 0UL ;
}
static void F_82 ( struct V_68 * V_22 , T_4 V_168 )
{
struct V_140 * V_161 = V_22 -> V_139 ;
T_4 V_169 = F_62 ( V_161 -> V_170 ) + V_168 ;
V_161 -> V_170 = F_78 ( V_169 ) ;
}
static T_4 F_83 ( struct V_68 * V_22 )
{
struct V_75 * V_10 ;
const T_4 V_76 = V_22 -> V_77 ;
const T_1 * V_26 = NULL ;
T_4 V_171 , V_41 , V_72 = 0 ;
for ( V_171 = 0 , V_10 = V_22 -> V_52 ; V_171 < V_76 ; V_171 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_16 -> V_17 + V_10 -> V_18 ;
F_84 ( ! F_85 ( V_10 -> V_16 ) ) ;
while ( V_41 < V_10 -> V_11 * V_14 ) {
V_41 = F_12 ( V_26 , V_10 -> V_11 , V_41 ,
V_172 ) ;
if ( V_41 == V_43 )
break;
V_72 ++ ;
V_41 ++ ;
}
}
return V_72 ;
}
int F_86 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_108 * V_109 = V_22 -> V_110 ;
unsigned int V_76 = V_22 -> V_77 ;
struct V_75 * V_10 ;
unsigned int V_47 , V_173 ;
int error ;
if ( V_22 -> V_52 [ 0 ] . V_16 != NULL )
return 0 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ ) {
V_10 = V_22 -> V_52 + V_47 ;
error = F_87 ( V_109 , V_22 -> V_23 + V_47 , 0 , & V_10 -> V_16 ) ;
if ( error )
goto V_136;
}
for ( V_173 = V_76 ; V_173 -- ; ) {
V_10 = V_22 -> V_52 + V_173 ;
error = F_88 ( V_74 , V_10 -> V_16 ) ;
if ( error )
goto V_136;
if ( F_89 ( V_74 , V_10 -> V_16 , V_173 ? V_174 :
V_175 ) ) {
error = - V_119 ;
goto V_136;
}
}
if ( ! ( V_22 -> V_143 & V_144 ) ) {
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ )
F_46 ( V_105 , & V_22 -> V_52 [ V_47 ] . V_106 ) ;
F_76 ( V_22 , ( V_22 -> V_52 [ 0 ] . V_16 ) -> V_17 ) ;
V_22 -> V_143 |= ( V_144 | V_176 ) ;
V_22 -> V_177 = V_22 -> V_78 ;
}
if ( F_62 ( V_167 ) != V_22 -> V_139 -> V_166 ) {
V_22 -> V_139 -> V_170 = F_78 ( F_83 ( V_22 ) ) ;
F_81 ( V_22 -> V_139 ,
V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
}
else if ( V_74 -> V_178 . V_179 ) {
if ( ! F_80 ( V_22 ) ) {
F_6 ( V_22 ) ;
error = - V_119 ;
goto V_136;
}
if ( V_22 -> V_139 -> V_170 == 0 )
V_22 -> V_143 &= ~ V_176 ;
}
return 0 ;
V_136:
while ( V_47 -- ) {
V_10 = V_22 -> V_52 + V_47 ;
F_90 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
F_91 ( V_74 , ! V_10 -> V_25 ) ;
}
return error ;
}
int F_92 ( struct V_68 * V_22 )
{
T_4 V_162 ;
if ( V_22 -> V_143 & V_144 )
return 0 ;
if ( F_62 ( V_167 ) != V_22 -> V_139 -> V_166 )
return F_86 ( V_22 ) ;
V_162 = F_62 ( V_22 -> V_139 -> V_162 ) ;
V_162 &= ~ V_154 ;
V_22 -> V_143 &= V_154 ;
V_22 -> V_143 |= ( V_162 | V_144 | V_176 ) ;
if ( V_22 -> V_139 -> V_170 == 0 )
V_22 -> V_143 &= ~ V_176 ;
V_22 -> V_78 = F_62 ( V_22 -> V_139 -> V_163 ) ;
V_22 -> V_177 = V_22 -> V_78 ;
V_22 -> V_79 = F_62 ( V_22 -> V_139 -> V_164 ) ;
V_22 -> V_157 = F_68 ( V_22 -> V_139 -> V_165 ) ;
return 0 ;
}
int F_93 ( struct V_148 * V_180 )
{
struct V_68 * V_22 = V_180 -> V_181 -> V_112 ;
struct V_73 * V_74 = V_22 -> V_55 ;
if ( V_180 -> V_182 & V_183 && V_74 -> V_178 . V_179 )
return 0 ;
return F_86 ( (struct V_68 * ) V_180 -> V_181 -> V_112 ) ;
}
void F_94 ( struct V_148 * V_180 )
{
struct V_68 * V_22 = V_180 -> V_181 -> V_112 ;
int V_47 , V_76 = V_22 -> V_77 ;
for ( V_47 = 0 ; V_47 < V_76 ; V_47 ++ ) {
struct V_75 * V_10 = V_22 -> V_52 + V_47 ;
if ( V_10 -> V_16 ) {
F_90 ( V_10 -> V_16 ) ;
V_10 -> V_16 = NULL ;
}
}
}
int F_95 ( struct V_73 * V_74 , T_2 V_13 ,
struct V_184 * V_185 ,
const struct V_75 * V_10 , unsigned V_186 , T_2 * V_187 )
{
struct V_188 * V_189 = V_74 -> V_190 ;
T_2 V_33 ;
T_6 V_65 = 0 ;
T_6 V_191 = 0 ;
int V_192 ;
unsigned int V_47 ;
T_4 V_193 = 0 ;
T_1 V_194 ;
for ( V_47 = 0 ; V_47 < V_10 -> V_11 ; V_47 ++ ) {
const T_1 * V_195 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_16 -> V_17 ;
V_195 += V_10 -> V_18 ;
V_195 += V_47 ;
if ( V_185 ) {
const T_1 * V_196 = V_185 -> V_17 + V_10 -> V_18 + V_47 ;
V_194 = ~ ( * V_196 | ( * V_196 >> 1 ) ) & ( * V_195 | ( * V_195 >> 1 ) ) ;
} else {
V_194 = ~ ( * V_195 | ( * V_195 >> 1 ) ) ;
}
V_194 &= 0x55 ;
if ( V_194 == 0 )
continue;
V_33 = V_13 + ( ( V_10 -> V_24 + V_47 ) * V_14 ) ;
while( V_194 ) {
if ( V_194 & 1 ) {
if ( V_191 == 0 )
goto V_197;
if ( ( V_65 + V_191 ) != V_33 ) {
if ( V_191 >= V_186 ) {
V_192 = F_96 ( V_189 ,
V_65 , V_191 ,
V_96 , 0 ) ;
if ( V_192 )
goto V_136;
V_193 += V_191 ;
}
V_191 = 0 ;
V_197:
V_65 = V_33 ;
}
V_191 ++ ;
}
V_194 >>= 2 ;
V_33 ++ ;
}
}
if ( V_191 >= V_186 ) {
V_192 = F_96 ( V_189 , V_65 , V_191 , V_96 , 0 ) ;
if ( V_192 )
goto V_136;
V_193 += V_191 ;
}
if ( V_187 )
* V_187 = V_193 ;
return 0 ;
V_136:
if ( V_74 -> V_178 . V_198 )
F_97 ( V_74 , L_15 , V_192 ) ;
V_74 -> V_178 . V_198 = 0 ;
return - V_119 ;
}
int F_98 ( struct V_199 * V_200 , void T_7 * V_201 )
{
struct V_121 * V_121 = F_99 ( V_200 ) ;
struct V_73 * V_74 = F_67 ( V_121 ) ;
struct V_202 * V_203 = F_100 ( V_74 -> V_190 -> V_204 ) ;
struct V_184 * V_185 ;
struct V_68 * V_22 ;
struct V_68 * V_205 ;
struct V_148 V_180 ;
struct V_206 V_207 ;
int V_208 = 0 ;
T_2 V_209 ;
T_2 V_193 = 0 ;
T_2 V_65 , V_7 , V_186 ;
unsigned int V_47 ;
unsigned V_210 = V_74 -> V_117 . V_211 ;
if ( ! F_101 ( V_212 ) )
return - V_213 ;
if ( ! F_102 ( V_203 ) )
return - V_214 ;
if ( F_103 ( & V_207 , V_201 , sizeof( V_207 ) ) )
return - V_215 ;
V_208 = F_72 ( V_74 ) ;
if ( V_208 )
return V_208 ;
V_65 = V_207 . V_65 >> V_210 ;
V_7 = V_65 + ( V_207 . V_34 >> V_210 ) ;
V_186 = F_104 ( T_2 , V_207 . V_186 ,
V_203 -> V_216 . V_217 ) >> V_210 ;
V_22 = F_25 ( V_74 , V_65 , 0 ) ;
V_205 = F_25 ( V_74 , V_7 - 1 , 0 ) ;
if ( V_7 <= V_65 ||
V_186 > V_74 -> V_145 ||
V_65 > V_205 -> V_46 + V_205 -> V_50 )
return - V_49 ;
while ( 1 ) {
V_208 = F_74 ( V_22 -> V_110 , V_218 , 0 , & V_180 ) ;
if ( V_208 )
goto V_66;
if ( ! ( V_22 -> V_143 & V_219 ) ) {
for ( V_47 = 0 ; V_47 < V_22 -> V_77 ; V_47 ++ ) {
struct V_75 * V_10 = V_22 -> V_52 + V_47 ;
V_208 = F_95 ( V_74 ,
V_22 -> V_46 , NULL , V_10 , V_186 ,
& V_209 ) ;
if ( V_208 ) {
F_75 ( & V_180 ) ;
goto V_66;
}
V_193 += V_209 ;
}
V_208 = F_105 ( V_74 , V_220 , 0 ) ;
if ( V_208 == 0 ) {
V_185 = V_22 -> V_52 [ 0 ] . V_16 ;
V_22 -> V_143 |= V_219 ;
F_106 ( V_22 -> V_110 , V_185 ) ;
F_77 ( V_22 , V_185 -> V_17 ) ;
F_81 ( V_22 -> V_139 , V_185 -> V_17 ) ;
F_107 ( V_74 ) ;
}
}
F_75 ( & V_180 ) ;
if ( V_22 == V_205 )
break;
V_22 = F_31 ( V_22 ) ;
}
V_66:
V_207 . V_34 = V_193 << 9 ;
if ( F_108 ( V_201 , & V_207 , sizeof( V_207 ) ) )
return - V_215 ;
return V_208 ;
}
static void F_109 ( struct V_91 * V_92 )
{
struct V_83 * * V_127 , * V_128 = NULL ;
int V_221 ;
struct V_35 * V_36 = V_92 -> V_94 ;
struct V_68 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_222 = F_11 ( & V_36 -> V_38 ) ;
F_2 ( F_43 ( V_36 ) ) ;
F_26 ( & V_22 -> V_107 ) ;
V_127 = & V_22 -> V_103 . V_83 ;
while ( * V_127 ) {
struct V_35 * V_85 =
F_27 ( * V_127 , struct V_35 , V_98 ) ;
V_128 = * V_127 ;
V_221 = F_10 ( V_222 , V_36 -> V_39 , V_85 ) ;
if ( V_221 > 0 )
V_127 = & ( ( * V_127 ) -> V_90 ) ;
else if ( V_221 < 0 )
V_127 = & ( ( * V_127 ) -> V_89 ) ;
else {
F_28 ( & V_22 -> V_107 ) ;
F_84 ( 1 ) ;
return;
}
}
F_64 ( & V_36 -> V_98 , V_128 , V_127 ) ;
F_65 ( & V_36 -> V_98 , & V_22 -> V_103 ) ;
V_22 -> V_104 += V_36 -> V_39 ;
F_28 ( & V_22 -> V_107 ) ;
F_44 ( V_36 , V_223 ) ;
}
static void F_110 ( struct V_68 * V_22 , struct V_91 * V_92 ,
unsigned V_224 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_92 -> V_94 ;
T_4 V_225 ;
T_4 V_226 = V_22 -> V_177 - V_22 -> V_104 ;
int V_208 ;
V_225 = F_104 ( T_4 , F_111 ( & V_36 -> V_227 ) , V_224 ) ;
V_225 = F_112 ( V_225 , V_228 , V_226 ) ;
if ( ( V_22 -> V_177 < V_22 -> V_104 ) || ( V_226 < V_225 ) )
return;
if ( F_24 ( V_22 , V_92 -> V_229 ) )
V_41 = V_92 -> V_229 ;
else
V_41 = V_22 -> V_230 + V_22 -> V_46 ;
if ( F_84 ( F_15 ( & V_2 , V_41 ) ) )
return;
V_208 = F_113 ( & V_2 , V_60 , V_225 , V_92 , true ) ;
if ( V_208 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_225 ;
V_36 -> V_101 = V_92 -> V_231 ;
F_109 ( V_92 ) ;
} else {
if ( V_41 == V_22 -> V_230 + V_22 -> V_46 )
V_22 -> V_230 = 0 ;
}
}
static T_2 F_114 ( struct V_68 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_91 * V_92 )
{
struct V_35 * V_36 ;
struct V_83 * V_58 ;
int V_221 ;
F_26 ( & V_22 -> V_107 ) ;
V_58 = V_22 -> V_103 . V_83 ;
while ( V_58 ) {
V_36 = F_27 ( V_58 , struct V_35 , V_98 ) ;
V_221 = F_10 ( V_44 , V_76 , V_36 ) ;
if ( V_221 < 0 )
V_58 = V_58 -> V_89 ;
else if ( V_221 > 0 )
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
static int F_115 ( struct V_1 * V_2 ,
const struct V_91 * V_92 ,
T_4 V_232 )
{
T_2 V_44 = F_11 ( V_2 ) ;
T_4 V_225 = 1 ;
T_2 V_233 ;
int V_208 ;
if ( V_232 ) {
V_225 = F_18 ( V_2 , V_232 ) ;
V_233 = V_44 + V_225 ;
if ( V_225 < V_232 )
goto V_136;
}
V_233 = F_114 ( V_2 -> V_22 , V_44 , V_225 , V_92 ) ;
if ( V_233 == V_44 )
return 0 ;
V_136:
V_208 = F_15 ( V_2 , V_233 ) ;
if ( V_208 < 0 )
return V_208 ;
return 1 ;
}
static int F_113 ( struct V_1 * V_2 , T_1 V_30 , T_4 V_232 ,
const struct V_91 * V_92 , bool V_234 )
{
struct V_184 * V_185 ;
struct V_75 * V_235 ;
T_4 V_236 ;
T_4 V_13 ;
T_1 * V_26 ;
int V_237 ;
int V_58 = 0 ;
int V_238 = V_2 -> V_22 -> V_77 ;
int V_208 ;
if ( V_2 -> V_13 != 0 )
V_238 ++ ;
while( 1 ) {
if ( F_116 ( V_105 , & V_2 -> V_10 -> V_106 ) &&
( V_30 == V_60 ) )
goto V_239;
V_185 = V_2 -> V_10 -> V_16 ;
V_26 = V_185 -> V_17 + V_2 -> V_10 -> V_18 ;
F_84 ( ! F_85 ( V_185 ) ) ;
if ( V_30 != V_172 && V_2 -> V_10 -> V_25 )
V_26 = V_2 -> V_10 -> V_25 + V_2 -> V_10 -> V_18 ;
V_236 = V_2 -> V_13 ;
V_13 = F_12 ( V_26 , V_2 -> V_10 -> V_11 , V_2 -> V_13 , V_30 ) ;
if ( V_13 == V_43 )
goto V_240;
V_2 -> V_13 = V_13 ;
if ( V_92 == NULL )
return 0 ;
V_235 = V_2 -> V_10 ;
V_208 = F_115 ( V_2 , V_92 , V_232 ) ;
if ( V_208 == 0 )
return 0 ;
if ( V_208 > 0 ) {
V_58 += ( V_2 -> V_10 - V_235 ) ;
goto V_241;
}
if ( V_208 == - V_51 ) {
V_237 = 0 ;
V_2 -> V_13 = 0 ;
V_58 += ( V_2 -> V_10 - V_235 ) ;
goto V_242;
}
return V_208 ;
V_240:
if ( ( V_30 == V_60 ) && V_236 == 0 )
F_117 ( V_105 , & V_2 -> V_10 -> V_106 ) ;
V_239:
V_2 -> V_13 = 0 ;
V_237 = V_2 -> V_10 - V_2 -> V_22 -> V_52 ;
V_237 ++ ;
if ( V_237 == V_2 -> V_22 -> V_77 )
V_237 = 0 ;
V_242:
V_2 -> V_10 = & V_2 -> V_22 -> V_52 [ V_237 ] ;
if ( ( V_237 == 0 ) && V_234 )
break;
V_58 ++ ;
V_241:
if ( V_58 >= V_238 )
break;
}
return - V_243 ;
}
static void F_118 ( struct V_68 * V_22 , T_2 * V_244 , T_2 V_245 )
{
T_2 V_44 ;
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_108 * V_109 ;
struct V_91 * V_92 ;
int error ;
int V_246 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_10 = V_22 -> V_52 , . V_13 = 0 } ;
while ( 1 ) {
F_36 ( & V_74 -> V_247 ) ;
error = F_113 ( & V_2 , V_172 , 0 , NULL , true ) ;
F_39 ( & V_74 -> V_247 ) ;
if ( error == - V_243 )
break;
if ( F_16 ( error ) )
break;
V_44 = F_11 ( & V_2 ) ;
if ( F_15 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_244 != V_248 && V_44 <= * V_244 )
continue;
if ( V_44 == V_245 )
continue;
* V_244 = V_44 ;
error = F_70 ( V_74 , V_44 , & V_249 , V_138 , & V_109 ) ;
if ( error )
continue;
V_92 = V_109 -> V_112 ;
if ( V_92 || F_119 ( V_250 , & V_109 -> V_251 ) == 0 )
F_54 ( V_109 ) ;
else
V_246 ++ ;
if ( V_246 > V_252 )
return;
}
V_22 -> V_143 &= ~ V_176 ;
return;
}
static bool F_120 ( const struct V_68 * V_22 , int V_253 )
{
const struct V_108 * V_109 = V_22 -> V_110 ;
const struct V_73 * V_74 = V_109 -> V_254 ;
struct V_255 * V_256 ;
T_8 V_257 , V_258 ;
T_8 V_259 , V_260 ;
T_8 V_261 ;
T_8 V_262 ;
T_8 V_263 ;
F_121 () ;
V_256 = & F_122 ( V_74 -> V_264 ) -> V_265 [ V_266 ] ;
V_259 = V_256 -> V_267 [ V_268 ] ;
V_257 = V_256 -> V_267 [ V_269 ] ;
V_263 = V_256 -> V_267 [ V_270 ] +
V_109 -> V_271 . V_267 [ V_270 ] ;
F_123 () ;
V_260 = V_109 -> V_271 . V_267 [ V_268 ] ;
V_258 = V_109 -> V_271 . V_267 [ V_269 ] ;
if ( ( V_258 < 1 ) || ( V_257 < 1 ) || ( V_259 == 0 ) )
return false ;
V_261 = V_259 - V_260 ;
V_262 = V_261 * V_261 ;
V_263 *= 2 ;
if ( V_258 < 8 || V_257 < 8 )
V_263 *= 2 ;
if ( V_253 == 1 )
V_263 *= 2 ;
return ( ( V_261 < 0 ) && ( V_262 > V_263 ) ) ;
}
static bool F_124 ( const struct V_35 * V_36 ,
T_2 V_272 )
{
T_2 V_273 ;
V_273 = F_125 ( F_126 ( F_127 () ,
V_36 -> V_38 . V_22 -> V_110 -> V_274 ) ) ;
return V_273 > ( V_272 * 1000 * 1000 ) ;
}
static T_4 F_128 ( const struct V_91 * V_92 )
{
const struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
T_4 V_245 ;
F_129 ( & V_245 , sizeof( V_245 ) ) ;
return V_245 % V_74 -> V_130 ;
}
static bool F_130 ( struct V_68 * * V_125 , const struct V_68 * V_275 )
{
struct V_68 * V_22 = * V_125 ;
struct V_73 * V_74 = V_22 -> V_55 ;
V_22 = F_31 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_29 ( V_74 ) ;
* V_125 = V_22 ;
if ( V_22 != V_275 )
return true ;
return false ;
}
int F_131 ( struct V_91 * V_92 , T_4 V_224 , T_4 V_276 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
struct V_68 * V_275 = NULL ;
struct V_35 * V_36 = V_92 -> V_94 ;
int error = 0 , V_277 , V_278 = 0 ;
T_2 V_244 = V_248 ;
int V_253 = 0 ;
T_4 V_245 = 0 ;
if ( V_74 -> V_178 . V_179 )
V_278 |= V_183 ;
if ( F_91 ( V_74 , V_224 ) )
return - V_49 ;
if ( F_43 ( V_36 ) ) {
V_275 = V_36 -> V_38 . V_22 ;
V_278 = 0 ;
} else if ( V_92 -> V_279 && F_24 ( V_92 -> V_279 , V_92 -> V_229 ) ) {
V_36 -> V_38 . V_22 = V_275 = V_92 -> V_279 ;
} else {
V_36 -> V_38 . V_22 = V_275 = F_25 ( V_74 , V_92 -> V_229 , 1 ) ;
}
if ( F_132 ( V_92 -> V_131 . V_280 ) && ( V_276 & V_281 ) )
V_245 = F_128 ( V_92 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_282 ;
while ( V_253 < 3 ) {
V_277 = 1 ;
if ( ! F_73 ( V_36 -> V_38 . V_22 -> V_110 ) ) {
V_277 = 0 ;
if ( V_245 && V_245 -- )
goto V_283;
if ( ! F_43 ( V_36 ) && ( V_253 < 2 ) &&
F_124 ( V_36 , 1000 ) &&
F_120 ( V_36 -> V_38 . V_22 , V_253 ) )
goto V_283;
error = F_74 ( V_36 -> V_38 . V_22 -> V_110 ,
V_218 , V_278 ,
& V_36 -> V_284 ) ;
if ( F_3 ( error ) )
return error ;
if ( ! F_43 ( V_36 ) && ( V_253 < 2 ) &&
F_120 ( V_36 -> V_38 . V_22 , V_253 ) )
goto V_285;
if ( V_74 -> V_178 . V_179 ) {
error = F_92 ( V_36 -> V_38 . V_22 ) ;
if ( F_3 ( error ) ) {
F_75 ( & V_36 -> V_284 ) ;
return error ;
}
}
}
if ( V_36 -> V_38 . V_22 -> V_143 & ( V_286 | V_287 ) )
goto V_285;
if ( V_74 -> V_178 . V_179 )
F_86 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_43 ( V_36 ) )
F_110 ( V_36 -> V_38 . V_22 , V_92 , V_224 ) ;
if ( ! F_43 ( V_36 ) && ( V_253 < 1 ) )
goto V_288;
if ( V_36 -> V_38 . V_22 -> V_177 >= V_224 ) {
V_92 -> V_279 = V_36 -> V_38 . V_22 ;
return 0 ;
}
if ( F_43 ( V_36 ) )
F_48 ( V_92 , V_36 ) ;
V_288:
if ( V_36 -> V_38 . V_22 -> V_143 & V_176 )
F_118 ( V_36 -> V_38 . V_22 , & V_244 ,
V_92 -> V_231 ) ;
V_285:
if ( ! V_277 )
F_75 ( & V_36 -> V_284 ) ;
V_283:
if ( F_130 ( & V_36 -> V_38 . V_22 , V_275 ) )
continue;
if ( V_245 )
continue;
V_253 ++ ;
if ( V_92 == F_59 ( V_74 -> V_122 ) && ! V_74 -> V_146 ) {
error = F_71 ( V_92 ) ;
if ( error )
return error ;
}
if ( V_253 == 2 )
F_133 ( V_74 , NULL ) ;
}
return - V_243 ;
}
void F_134 ( struct V_91 * V_92 )
{
struct V_35 * V_36 = V_92 -> V_94 ;
if ( V_36 -> V_284 . V_181 )
F_75 ( & V_36 -> V_284 ) ;
}
static unsigned char F_135 ( struct V_68 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_208 ;
V_208 = F_15 ( & V_2 , V_44 ) ;
F_16 ( V_208 != 0 ) ;
return F_7 ( & V_2 ) ;
}
static void F_136 ( const struct V_1 * V_2 , bool V_289 ,
unsigned int * V_58 )
{
struct V_1 V_125 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_290 = * V_58 ;
T_2 V_44 ;
int V_208 ;
* V_58 = 1 ;
V_44 = F_11 ( V_2 ) ;
F_106 ( V_2 -> V_22 -> V_110 , V_2 -> V_10 -> V_16 ) ;
F_1 ( V_2 , true , V_289 ? V_291 : V_292 ) ;
V_44 ++ ;
while ( * V_58 < V_290 ) {
V_208 = F_15 ( & V_125 , V_44 ) ;
if ( V_208 || F_7 ( & V_125 ) != V_60 )
break;
F_106 ( V_125 . V_22 -> V_110 , V_125 . V_10 -> V_16 ) ;
F_1 ( & V_125 , true , V_292 ) ;
( * V_58 ) ++ ;
V_44 ++ ;
}
}
static struct V_68 * F_137 ( struct V_73 * V_74 , T_2 V_293 ,
T_4 V_294 , unsigned char V_4 )
{
struct V_1 V_2 ;
V_2 . V_22 = F_25 ( V_74 , V_293 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_138 ( V_74 ) )
F_23 ( V_74 , L_16 , ( unsigned long long ) V_293 ) ;
return NULL ;
}
while ( V_294 -- ) {
F_15 ( & V_2 , V_293 ) ;
V_293 ++ ;
if ( ! V_2 . V_10 -> V_25 ) {
V_2 . V_10 -> V_25 = F_139 ( V_2 . V_10 -> V_16 -> V_67 ,
V_96 | V_295 ) ;
memcpy ( V_2 . V_10 -> V_25 + V_2 . V_10 -> V_18 ,
V_2 . V_10 -> V_16 -> V_17 + V_2 . V_10 -> V_18 ,
V_2 . V_10 -> V_11 ) ;
}
F_106 ( V_2 . V_22 -> V_110 , V_2 . V_10 -> V_16 ) ;
F_1 ( & V_2 , false , V_4 ) ;
}
return V_2 . V_22 ;
}
int F_140 ( struct V_99 * V_100 , const struct V_108 * V_109 )
{
struct V_68 * V_22 = V_109 -> V_112 ;
struct V_35 * V_296 ;
const struct V_83 * V_58 ;
if ( V_22 == NULL )
return 0 ;
F_41 ( V_100 , L_17 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_143 ,
V_22 -> V_78 , V_22 -> V_177 , V_22 -> V_79 ,
V_22 -> V_104 ) ;
F_26 ( & V_22 -> V_107 ) ;
for ( V_58 = F_30 ( & V_22 -> V_103 ) ; V_58 ; V_58 = F_32 ( & V_296 -> V_98 ) ) {
V_296 = F_27 ( V_58 , struct V_35 , V_98 ) ;
F_40 ( V_100 , V_296 ) ;
}
F_28 ( & V_22 -> V_107 ) ;
return 0 ;
}
static void F_141 ( struct V_68 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
F_97 ( V_74 , L_18 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_97 ( V_74 , L_19 ) ;
F_140 ( NULL , V_22 -> V_110 ) ;
V_22 -> V_143 |= V_287 ;
}
static void F_142 ( struct V_91 * V_92 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_92 -> V_94 ;
struct V_68 * V_22 = V_2 -> V_22 ;
unsigned V_297 ;
T_2 V_44 ;
int V_208 ;
F_26 ( & V_22 -> V_107 ) ;
if ( F_43 ( V_36 ) ) {
if ( F_143 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_11 ( V_2 ) ;
V_208 = F_15 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_297 = F_144 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_297 ;
V_22 -> V_104 -= V_297 ;
F_44 ( V_36 , V_298 ) ;
if ( V_36 -> V_39 && ! V_208 )
goto V_66;
}
F_42 ( V_92 , V_36 ) ;
}
V_66:
F_28 ( & V_22 -> V_107 ) ;
}
int F_145 ( struct V_91 * V_92 , T_2 * V_299 , unsigned int * V_300 ,
bool V_289 , T_2 * V_301 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
struct V_184 * V_302 ;
struct V_1 V_2 = { . V_22 = V_92 -> V_279 , } ;
unsigned int V_303 ;
T_2 V_41 ;
T_2 V_44 ;
int error ;
if ( F_43 ( V_92 -> V_94 ) )
V_41 = F_11 ( & V_92 -> V_94 -> V_38 ) ;
else if ( ! V_289 && F_24 ( V_2 . V_22 , V_92 -> V_229 ) )
V_41 = V_92 -> V_229 ;
else
V_41 = V_2 . V_22 -> V_230 + V_2 . V_22 -> V_46 ;
F_15 ( & V_2 , V_41 ) ;
error = F_113 ( & V_2 , V_60 , 0 , V_92 , false ) ;
if ( error == - V_243 ) {
F_15 ( & V_2 , V_41 ) ;
error = F_113 ( & V_2 , V_60 , 0 , NULL , false ) ;
}
if ( error ) {
F_97 ( V_74 , L_20 ,
( unsigned long long ) V_92 -> V_231 , error , * V_300 ,
F_116 ( V_105 , & V_2 . V_22 -> V_52 -> V_106 ) ) ;
goto V_304;
}
F_136 ( & V_2 , V_289 , V_300 ) ;
V_44 = F_11 ( & V_2 ) ;
V_2 . V_22 -> V_230 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_43 ( V_92 -> V_94 ) )
F_142 ( V_92 , & V_2 , * V_300 ) ;
V_303 = * V_300 ;
if ( V_289 )
V_303 -- ;
if ( ! V_289 ) {
V_92 -> V_229 = V_44 + V_303 - 1 ;
error = F_146 ( V_92 , & V_302 ) ;
if ( error == 0 ) {
struct V_305 * V_306 =
(struct V_305 * ) V_302 -> V_17 ;
F_106 ( V_92 -> V_147 , V_302 ) ;
V_306 -> V_307 = V_306 -> V_308 =
F_79 ( V_92 -> V_229 ) ;
F_90 ( V_302 ) ;
}
}
if ( V_2 . V_22 -> V_78 < * V_300 ) {
F_4 ( V_21 L_21 , * V_300 ) ;
goto V_304;
}
V_2 . V_22 -> V_78 -= * V_300 ;
if ( V_289 ) {
V_2 . V_22 -> V_79 ++ ;
* V_301 = V_2 . V_22 -> V_157 ++ ;
if ( * V_301 == 0 )
* V_301 = V_2 . V_22 -> V_157 ++ ;
}
F_106 ( V_2 . V_22 -> V_110 , V_2 . V_22 -> V_52 [ 0 ] . V_16 ) ;
F_77 ( V_2 . V_22 , V_2 . V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_2 . V_22 -> V_139 , V_2 . V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_147 ( V_74 , 0 , - ( T_8 ) * V_300 , V_289 ? 1 : 0 ) ;
if ( V_289 )
F_148 ( V_74 , V_44 , 1 ) ;
if ( V_303 )
F_149 ( V_92 , V_303 , V_92 -> V_131 . V_309 ,
V_92 -> V_131 . V_310 ) ;
V_2 . V_22 -> V_177 -= * V_300 ;
F_150 ( V_92 , V_2 . V_22 , V_44 , * V_300 ,
V_289 ? V_291 : V_292 ) ;
* V_299 = V_44 ;
return 0 ;
V_304:
F_141 ( V_2 . V_22 ) ;
return - V_119 ;
}
void F_151 ( struct V_91 * V_92 , T_2 V_293 , T_4 V_294 , int V_311 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
struct V_68 * V_22 ;
V_22 = F_137 ( V_74 , V_293 , V_294 , V_60 ) ;
if ( ! V_22 )
return;
F_150 ( V_92 , V_22 , V_293 , V_294 , V_60 ) ;
V_22 -> V_78 += V_294 ;
V_22 -> V_143 &= ~ V_219 ;
F_106 ( V_22 -> V_110 , V_22 -> V_52 [ 0 ] . V_16 ) ;
F_77 ( V_22 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_22 -> V_139 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
if ( V_311 || V_92 -> V_312 )
F_152 ( V_92 , V_293 , V_294 ) ;
}
void F_153 ( struct V_91 * V_92 , T_2 V_293 , T_4 V_294 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
F_151 ( V_92 , V_293 , V_294 , 1 ) ;
F_147 ( V_74 , 0 , + V_294 , 0 ) ;
F_149 ( V_92 , - ( T_8 ) V_294 , V_92 -> V_131 . V_309 , V_92 -> V_131 . V_310 ) ;
}
void F_154 ( struct V_121 * V_121 )
{
struct V_91 * V_92 = F_59 ( V_121 ) ;
struct V_73 * V_74 = F_67 ( V_121 ) ;
struct V_68 * V_22 ;
T_2 V_313 = V_92 -> V_231 ;
V_22 = F_137 ( V_74 , V_313 , 1 , V_172 ) ;
if ( ! V_22 )
return;
F_150 ( V_92 , V_22 , V_313 , 1 , V_172 ) ;
F_106 ( V_22 -> V_110 , V_22 -> V_52 [ 0 ] . V_16 ) ;
F_77 ( V_22 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_22 -> V_139 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 , 1 ) ;
}
static void F_155 ( struct V_68 * V_22 , T_2 V_313 )
{
struct V_73 * V_74 = V_22 -> V_55 ;
struct V_68 * V_314 ;
V_314 = F_137 ( V_74 , V_313 , 1 , V_60 ) ;
if ( ! V_314 )
return;
F_156 ( V_74 , V_22 == V_314 ) ;
if ( ! V_22 -> V_79 )
F_6 ( V_22 ) ;
V_22 -> V_79 -- ;
V_22 -> V_78 ++ ;
F_106 ( V_22 -> V_110 , V_22 -> V_52 [ 0 ] . V_16 ) ;
F_77 ( V_22 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_81 ( V_22 -> V_139 , V_22 -> V_52 [ 0 ] . V_16 -> V_17 ) ;
F_82 ( V_22 , - 1 ) ;
F_147 ( V_74 , 0 , + 1 , - 1 ) ;
}
void F_157 ( struct V_68 * V_22 , struct V_91 * V_92 )
{
F_155 ( V_22 , V_92 -> V_231 ) ;
F_150 ( V_92 , V_22 , V_92 -> V_231 , 1 , V_60 ) ;
F_149 ( V_92 , - 1 , V_92 -> V_131 . V_309 , V_92 -> V_131 . V_310 ) ;
F_152 ( V_92 , V_92 -> V_231 , 1 ) ;
}
int F_158 ( struct V_73 * V_74 , T_2 V_315 , unsigned int type )
{
struct V_68 * V_22 ;
struct V_148 V_316 ;
int error = - V_49 ;
V_22 = F_25 ( V_74 , V_315 , 1 ) ;
if ( ! V_22 )
goto V_136;
error = F_74 ( V_22 -> V_110 , V_151 , 0 , & V_316 ) ;
if ( error )
goto V_136;
if ( F_135 ( V_22 , V_315 ) != type )
error = - V_317 ;
F_75 ( & V_316 ) ;
V_136:
return error ;
}
void F_159 ( struct V_91 * V_92 , struct V_318 * V_319 ,
T_2 V_44 )
{
struct V_73 * V_74 = F_67 ( & V_92 -> V_131 ) ;
struct V_68 * V_22 ;
struct V_68 * * V_31 ;
unsigned int V_320 ;
unsigned int V_47 ;
if ( F_91 ( V_74 , ! V_319 -> V_321 ) )
return;
if ( V_92 -> V_279 && F_24 ( V_92 -> V_279 , V_44 ) )
V_22 = V_92 -> V_279 ;
else
V_22 = F_25 ( V_74 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_23 ( V_74 , L_22 , ( unsigned long long ) V_44 ) ;
return;
}
V_92 -> V_279 = V_22 ;
for ( V_47 = 0 ; V_47 < V_319 -> V_322 ; V_47 ++ )
if ( V_319 -> V_323 [ V_47 ] == V_22 )
return;
if ( V_319 -> V_322 == V_319 -> V_324 ) {
V_320 = V_319 -> V_324 + 10 ;
V_31 = F_57 ( V_320 , sizeof( struct V_68 * ) ,
V_96 | V_295 ) ;
if ( V_319 -> V_323 ) {
memcpy ( V_31 , V_319 -> V_323 ,
V_319 -> V_324 * sizeof( struct V_68 * ) ) ;
F_34 ( V_319 -> V_323 ) ;
}
V_319 -> V_324 = V_320 ;
V_319 -> V_323 = V_31 ;
}
V_319 -> V_323 [ V_319 -> V_322 ++ ] = V_22 ;
}
void F_160 ( struct V_318 * V_319 , unsigned int V_30 )
{
unsigned int V_47 ;
V_319 -> V_321 = F_57 ( V_319 -> V_322 , sizeof( struct V_148 ) ,
V_96 | V_295 ) ;
for ( V_47 = 0 ; V_47 < V_319 -> V_322 ; V_47 ++ )
F_161 ( V_319 -> V_323 [ V_47 ] -> V_110 ,
V_30 , 0 ,
& V_319 -> V_321 [ V_47 ] ) ;
}
void F_162 ( struct V_318 * V_319 )
{
unsigned int V_47 ;
F_34 ( V_319 -> V_323 ) ;
if ( V_319 -> V_321 ) {
for ( V_47 = 0 ; V_47 < V_319 -> V_322 ; V_47 ++ )
F_163 ( & V_319 -> V_321 [ V_47 ] ) ;
F_34 ( V_319 -> V_321 ) ;
V_319 -> V_321 = NULL ;
}
}
