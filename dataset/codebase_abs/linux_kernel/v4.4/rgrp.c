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
F_28 ( & V_115 -> V_117 . V_118 ) ;
V_115 -> V_119 = NULL ;
F_30 ( & V_115 -> V_117 . V_118 ) ;
F_57 ( V_115 ) ;
F_58 ( V_115 ) ;
}
F_37 ( V_22 ) ;
F_38 ( V_22 -> V_78 ) ;
F_55 ( V_22 ) ;
F_54 ( V_120 , V_22 ) ;
}
}
static void F_59 ( const struct V_69 * V_22 )
{
F_60 ( L_8 , ( unsigned long long ) V_22 -> V_23 ) ;
F_60 ( L_9 , V_22 -> V_57 ) ;
F_60 ( L_10 , ( unsigned long long ) V_22 -> V_46 ) ;
F_60 ( L_11 , V_22 -> V_49 ) ;
F_60 ( L_12 , V_22 -> V_121 ) ;
}
static int F_61 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_9 * V_10 ;
T_4 V_76 = V_22 -> V_57 ;
T_4 V_122 , V_64 ;
int V_77 ;
if ( ! V_76 )
return - V_48 ;
V_22 -> V_78 = F_62 ( V_76 , sizeof( struct V_9 ) , V_100 ) ;
if ( ! V_22 -> V_78 )
return - V_101 ;
V_122 = V_22 -> V_121 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
V_10 -> V_111 = 0 ;
if ( V_76 == 1 ) {
V_64 = V_122 ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 == 0 ) {
V_64 = V_75 -> V_123 . V_124 - sizeof( struct V_53 ) ;
V_10 -> V_19 = sizeof( struct V_53 ) ;
V_10 -> V_24 = 0 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else if ( V_77 + 1 == V_76 ) {
V_64 = V_122 ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_121 - V_122 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
} else {
V_64 = V_75 -> V_123 . V_124 -
sizeof( struct V_54 ) ;
V_10 -> V_19 = sizeof( struct V_54 ) ;
V_10 -> V_24 = V_22 -> V_121 - V_122 ;
V_10 -> V_12 = V_64 ;
V_10 -> V_52 = V_64 * V_15 ;
}
V_122 -= V_64 ;
}
if ( V_122 ) {
F_7 ( V_22 ) ;
return - V_125 ;
}
V_10 = V_22 -> V_78 + ( V_76 - 1 ) ;
if ( ( V_10 -> V_24 + V_10 -> V_12 ) * V_15 != V_22 -> V_49 ) {
if ( F_7 ( V_22 ) ) {
F_59 ( V_22 ) ;
F_25 ( V_75 , L_13 ,
V_10 -> V_24 , V_10 -> V_12 , V_10 -> V_19 ) ;
}
return - V_125 ;
}
return 0 ;
}
T_2 F_63 ( struct V_74 * V_75 )
{
T_2 V_126 = 0 ;
struct V_127 * V_127 = V_75 -> V_128 ;
struct V_92 * V_93 = F_64 ( V_127 ) ;
char V_40 [ sizeof( struct V_129 ) ] ;
int error , V_130 ;
for ( V_130 = 0 ; ; V_130 ++ ) {
T_6 V_131 = V_130 * sizeof( struct V_129 ) ;
if ( V_131 + sizeof( struct V_129 ) > F_65 ( V_127 ) )
break;
error = F_66 ( V_93 , V_40 , & V_131 ,
sizeof( struct V_129 ) ) ;
if ( error != sizeof( struct V_129 ) )
break;
V_126 += F_67 ( ( (struct V_129 * ) V_40 ) -> V_132 ) ;
}
return V_126 ;
}
static int F_68 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_84 * * V_133 = & V_75 -> V_88 . V_84 , * V_134 = NULL ;
while ( * V_133 ) {
struct V_69 * V_86 = F_29 ( * V_133 , struct V_69 ,
V_89 ) ;
V_134 = * V_133 ;
if ( V_22 -> V_23 < V_86 -> V_23 )
V_133 = & ( ( * V_133 ) -> V_90 ) ;
else if ( V_22 -> V_23 > V_86 -> V_23 )
V_133 = & ( ( * V_133 ) -> V_91 ) ;
else
return - V_135 ;
}
F_69 ( & V_22 -> V_89 , V_134 , V_133 ) ;
F_70 ( & V_22 -> V_89 , & V_75 -> V_88 ) ;
V_75 -> V_136 ++ ;
return 0 ;
}
static int F_71 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
const unsigned V_137 = V_75 -> V_123 . V_124 ;
T_6 V_131 = V_75 -> V_136 * sizeof( struct V_129 ) ;
struct V_129 V_40 ;
int error ;
struct V_69 * V_22 ;
if ( V_131 >= F_65 ( & V_93 -> V_94 ) )
return 1 ;
error = F_66 ( V_93 , ( char * ) & V_40 , & V_131 ,
sizeof( struct V_129 ) ) ;
if ( error != sizeof( struct V_129 ) )
return ( error == 0 ) ? 1 : error ;
V_22 = F_41 ( V_120 , V_100 ) ;
error = - V_101 ;
if ( ! V_22 )
return error ;
V_22 -> V_55 = V_75 ;
V_22 -> V_23 = F_72 ( V_40 . V_138 ) ;
V_22 -> V_57 = F_67 ( V_40 . V_139 ) ;
V_22 -> V_46 = F_72 ( V_40 . V_140 ) ;
V_22 -> V_49 = F_67 ( V_40 . V_132 ) ;
V_22 -> V_121 = F_67 ( V_40 . V_141 ) ;
F_73 ( & V_22 -> V_112 ) ;
error = F_61 ( V_22 ) ;
if ( error )
goto V_142;
error = F_74 ( V_75 , V_22 -> V_23 ,
& V_143 , V_144 , & V_22 -> V_116 ) ;
if ( error )
goto V_142;
V_22 -> V_116 -> V_119 = V_22 ;
V_22 -> V_116 -> V_145 . V_66 = ( V_22 -> V_23 * V_137 ) & V_146 ;
V_22 -> V_116 -> V_145 . V_7 = F_75 ( ( V_22 -> V_23 +
V_22 -> V_57 ) * V_137 ) - 1 ;
V_22 -> V_147 = (struct V_148 * ) V_22 -> V_116 -> V_149 . V_150 ;
V_22 -> V_151 &= ~ ( V_152 | V_153 ) ;
if ( V_22 -> V_49 > V_75 -> V_154 )
V_75 -> V_154 = V_22 -> V_49 ;
F_28 ( & V_75 -> V_87 ) ;
error = F_68 ( V_22 ) ;
F_30 ( & V_75 -> V_87 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_58 ( V_22 -> V_116 ) ;
V_142:
F_38 ( V_22 -> V_78 ) ;
F_54 ( V_120 , V_22 ) ;
return error ;
}
static void F_76 ( struct V_74 * V_75 )
{
struct V_69 * V_22 , * V_81 ;
int V_155 ;
V_22 = F_31 ( V_75 ) ;
for ( V_155 = 0 ; V_155 < V_75 -> V_156 . V_157 ; V_155 ++ )
V_22 = F_33 ( V_22 ) ;
V_81 = V_22 ;
do {
V_22 -> V_151 |= V_153 ;
for ( V_155 = 0 ; V_155 < V_75 -> V_158 ; V_155 ++ ) {
V_22 = F_33 ( V_22 ) ;
if ( ! V_22 || V_22 == V_81 )
break;
}
} while ( V_22 && V_22 != V_81 );
}
static int F_77 ( struct V_92 * V_93 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
int error ;
do {
error = F_71 ( V_93 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
F_76 ( V_75 ) ;
V_75 -> V_159 = 1 ;
return 0 ;
}
int F_78 ( struct V_74 * V_75 )
{
struct V_92 * V_93 = F_64 ( V_75 -> V_128 ) ;
struct V_114 * V_115 = V_93 -> V_160 ;
struct V_161 V_162 ;
int error = 0 ;
int V_163 = 0 ;
if ( ! V_75 -> V_159 ) {
if ( ! F_79 ( V_115 ) ) {
error = F_80 ( V_115 , V_164 , 0 , & V_162 ) ;
if ( error )
return error ;
V_163 = 1 ;
}
if ( ! V_75 -> V_159 )
error = F_77 ( V_93 ) ;
if ( V_163 )
F_81 ( & V_162 ) ;
}
return error ;
}
static void F_82 ( struct V_69 * V_22 , const void * V_40 )
{
const struct V_53 * V_165 = V_40 ;
T_4 V_166 ;
V_166 = F_67 ( V_165 -> V_166 ) ;
V_166 &= ~ V_167 ;
V_22 -> V_151 &= V_167 ;
V_22 -> V_151 |= V_166 ;
V_22 -> V_79 = F_67 ( V_165 -> V_168 ) ;
V_22 -> V_80 = F_67 ( V_165 -> V_169 ) ;
V_22 -> V_170 = F_72 ( V_165 -> V_171 ) ;
}
static void F_83 ( struct V_69 * V_22 , void * V_40 )
{
struct V_53 * V_165 = V_40 ;
V_165 -> V_166 = F_84 ( V_22 -> V_151 & ~ V_167 ) ;
V_165 -> V_168 = F_84 ( V_22 -> V_79 ) ;
V_165 -> V_169 = F_84 ( V_22 -> V_80 ) ;
V_165 -> V_172 = F_84 ( 0 ) ;
V_165 -> V_171 = F_85 ( V_22 -> V_170 ) ;
memset ( & V_165 -> V_173 , 0 , sizeof( V_165 -> V_173 ) ) ;
}
static int F_86 ( struct V_69 * V_22 )
{
struct V_148 * V_174 = V_22 -> V_147 ;
struct V_53 * V_165 = (struct V_53 * ) V_22 -> V_78 [ 0 ] . V_17 -> V_18 ;
if ( V_174 -> V_175 != V_165 -> V_166 || V_174 -> V_176 != V_165 -> V_168 ||
V_174 -> V_177 != V_165 -> V_169 ||
V_174 -> V_178 != V_165 -> V_171 )
return 0 ;
return 1 ;
}
static void F_87 ( struct V_148 * V_174 , const void * V_40 )
{
const struct V_53 * V_165 = V_40 ;
V_174 -> V_179 = F_84 ( V_180 ) ;
V_174 -> V_175 = V_165 -> V_166 ;
V_174 -> V_176 = V_165 -> V_168 ;
V_174 -> V_177 = V_165 -> V_169 ;
V_174 -> V_178 = V_165 -> V_171 ;
V_174 -> V_172 = 0UL ;
}
static void F_88 ( struct V_69 * V_22 , T_4 V_181 )
{
struct V_148 * V_174 = V_22 -> V_147 ;
T_4 V_182 = F_67 ( V_174 -> V_183 ) + V_181 ;
V_174 -> V_183 = F_84 ( V_182 ) ;
}
static T_4 F_89 ( struct V_69 * V_22 )
{
struct V_9 * V_10 ;
const T_4 V_76 = V_22 -> V_57 ;
const T_1 * V_26 = NULL ;
T_4 V_155 , V_41 , V_73 = 0 ;
for ( V_155 = 0 , V_10 = V_22 -> V_78 ; V_155 < V_76 ; V_155 ++ , V_10 ++ ) {
V_41 = 0 ;
V_26 = V_10 -> V_17 -> V_18 + V_10 -> V_19 ;
F_90 ( ! F_91 ( V_10 -> V_17 ) ) ;
while ( V_41 < V_10 -> V_12 * V_15 ) {
V_41 = F_13 ( V_26 , V_10 -> V_12 , V_41 ,
V_184 ) ;
if ( V_41 == V_43 )
break;
V_73 ++ ;
V_41 ++ ;
}
}
return V_73 ;
}
static int F_92 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_114 * V_115 = V_22 -> V_116 ;
unsigned int V_76 = V_22 -> V_57 ;
struct V_9 * V_10 ;
unsigned int V_77 , V_185 ;
int error ;
if ( V_22 -> V_78 [ 0 ] . V_17 != NULL )
return 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_10 = V_22 -> V_78 + V_77 ;
error = F_93 ( V_115 , V_22 -> V_23 + V_77 , 0 , & V_10 -> V_17 ) ;
if ( error )
goto V_142;
}
for ( V_185 = V_76 ; V_185 -- ; ) {
V_10 = V_22 -> V_78 + V_185 ;
error = F_94 ( V_75 , V_10 -> V_17 ) ;
if ( error )
goto V_142;
if ( F_95 ( V_75 , V_10 -> V_17 , V_185 ? V_186 :
V_187 ) ) {
error = - V_125 ;
goto V_142;
}
}
if ( ! ( V_22 -> V_151 & V_152 ) ) {
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_50 ( V_110 , & V_22 -> V_78 [ V_77 ] . V_111 ) ;
F_82 ( V_22 , ( V_22 -> V_78 [ 0 ] . V_17 ) -> V_18 ) ;
V_22 -> V_151 |= ( V_152 | V_188 ) ;
V_22 -> V_189 = V_22 -> V_79 ;
V_22 -> V_109 = V_22 -> V_79 ;
}
if ( F_84 ( V_180 ) != V_22 -> V_147 -> V_179 ) {
V_22 -> V_147 -> V_183 = F_84 ( F_89 ( V_22 ) ) ;
F_87 ( V_22 -> V_147 ,
V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
}
else if ( V_75 -> V_190 . V_191 ) {
if ( ! F_86 ( V_22 ) ) {
F_7 ( V_22 ) ;
error = - V_125 ;
goto V_142;
}
if ( V_22 -> V_147 -> V_183 == 0 )
V_22 -> V_151 &= ~ V_188 ;
}
return 0 ;
V_142:
while ( V_77 -- ) {
V_10 = V_22 -> V_78 + V_77 ;
F_96 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
F_97 ( V_75 , ! V_10 -> V_25 ) ;
}
return error ;
}
static int F_98 ( struct V_69 * V_22 )
{
T_4 V_175 ;
if ( V_22 -> V_151 & V_152 )
return 0 ;
if ( F_84 ( V_180 ) != V_22 -> V_147 -> V_179 )
return F_92 ( V_22 ) ;
V_175 = F_67 ( V_22 -> V_147 -> V_175 ) ;
V_175 &= ~ V_167 ;
V_22 -> V_151 &= V_167 ;
V_22 -> V_151 |= ( V_175 | V_152 | V_188 ) ;
if ( V_22 -> V_147 -> V_183 == 0 )
V_22 -> V_151 &= ~ V_188 ;
V_22 -> V_79 = F_67 ( V_22 -> V_147 -> V_176 ) ;
V_22 -> V_189 = V_22 -> V_79 ;
V_22 -> V_80 = F_67 ( V_22 -> V_147 -> V_177 ) ;
V_22 -> V_170 = F_72 ( V_22 -> V_147 -> V_178 ) ;
return 0 ;
}
int F_99 ( struct V_161 * V_192 )
{
struct V_69 * V_22 = V_192 -> V_193 -> V_119 ;
struct V_74 * V_75 = V_22 -> V_55 ;
if ( V_192 -> V_194 & V_195 && V_75 -> V_190 . V_191 )
return 0 ;
return F_92 ( V_22 ) ;
}
void F_100 ( struct V_69 * V_22 )
{
int V_77 , V_76 = V_22 -> V_57 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
if ( V_10 -> V_17 ) {
F_96 ( V_10 -> V_17 ) ;
V_10 -> V_17 = NULL ;
}
}
}
void F_101 ( struct V_161 * V_192 )
{
struct V_69 * V_22 = V_192 -> V_193 -> V_119 ;
int V_196 = F_102 ( V_197 , & V_192 -> V_193 -> V_198 ) |
F_102 ( V_199 , & V_192 -> V_193 -> V_198 ) ;
if ( V_22 && V_196 )
F_100 ( V_22 ) ;
}
int F_103 ( struct V_74 * V_75 , T_2 V_14 ,
struct V_200 * V_201 ,
const struct V_9 * V_10 , unsigned V_202 , T_2 * V_203 )
{
struct V_204 * V_205 = V_75 -> V_206 ;
T_2 V_33 ;
T_7 V_66 = 0 ;
T_7 V_207 = 0 ;
int V_208 ;
unsigned int V_77 ;
T_4 V_209 = 0 ;
T_1 V_210 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_12 ; V_77 ++ ) {
const T_1 * V_211 = V_10 -> V_25 ? V_10 -> V_25 : V_10 -> V_17 -> V_18 ;
V_211 += V_10 -> V_19 ;
V_211 += V_77 ;
if ( V_201 ) {
const T_1 * V_212 = V_201 -> V_18 + V_10 -> V_19 + V_77 ;
V_210 = ~ ( * V_212 | ( * V_212 >> 1 ) ) & ( * V_211 | ( * V_211 >> 1 ) ) ;
} else {
V_210 = ~ ( * V_211 | ( * V_211 >> 1 ) ) ;
}
V_210 &= 0x55 ;
if ( V_210 == 0 )
continue;
V_33 = V_14 + ( ( V_10 -> V_24 + V_77 ) * V_15 ) ;
while( V_210 ) {
if ( V_210 & 1 ) {
if ( V_207 == 0 )
goto V_213;
if ( ( V_66 + V_207 ) != V_33 ) {
if ( V_207 >= V_202 ) {
V_208 = F_104 ( V_205 ,
V_66 , V_207 ,
V_100 , 0 ) ;
if ( V_208 )
goto V_142;
V_209 += V_207 ;
}
V_207 = 0 ;
V_213:
V_66 = V_33 ;
}
V_207 ++ ;
}
V_210 >>= 2 ;
V_33 ++ ;
}
}
if ( V_207 >= V_202 ) {
V_208 = F_104 ( V_205 , V_66 , V_207 , V_100 , 0 ) ;
if ( V_208 )
goto V_142;
V_209 += V_207 ;
}
if ( V_203 )
* V_203 = V_209 ;
return 0 ;
V_142:
if ( V_75 -> V_190 . V_214 )
F_105 ( V_75 , L_14 , V_208 ) ;
V_75 -> V_190 . V_214 = 0 ;
return - V_125 ;
}
int F_106 ( struct V_215 * V_216 , void T_8 * V_217 )
{
struct V_127 * V_127 = F_107 ( V_216 ) ;
struct V_74 * V_75 = F_36 ( V_127 ) ;
struct V_218 * V_219 = F_108 ( V_75 -> V_206 -> V_220 ) ;
struct V_200 * V_201 ;
struct V_69 * V_22 ;
struct V_69 * V_221 ;
struct V_161 V_192 ;
struct V_222 V_223 ;
int V_224 = 0 ;
T_2 V_225 ;
T_2 V_209 = 0 ;
T_2 V_66 , V_7 , V_202 ;
unsigned int V_77 ;
unsigned V_226 = V_75 -> V_123 . V_227 ;
if ( ! F_109 ( V_228 ) )
return - V_229 ;
if ( ! F_110 ( V_219 ) )
return - V_230 ;
if ( F_111 ( & V_223 , V_217 , sizeof( V_223 ) ) )
return - V_231 ;
V_224 = F_78 ( V_75 ) ;
if ( V_224 )
return V_224 ;
V_66 = V_223 . V_66 >> V_226 ;
V_7 = V_66 + ( V_223 . V_34 >> V_226 ) ;
V_202 = F_112 ( T_2 , V_223 . V_202 ,
V_219 -> V_232 . V_233 ) >> V_226 ;
if ( V_7 <= V_66 || V_202 > V_75 -> V_154 )
return - V_48 ;
V_22 = F_27 ( V_75 , V_66 , 0 ) ;
V_221 = F_27 ( V_75 , V_7 , 0 ) ;
if ( ( F_31 ( V_75 ) == F_33 ( V_221 ) )
&& ( V_66 > V_221 -> V_46 + V_221 -> V_49 ) )
return - V_48 ;
while ( 1 ) {
V_224 = F_80 ( V_22 -> V_116 , V_234 , 0 , & V_192 ) ;
if ( V_224 )
goto V_67;
if ( ! ( V_22 -> V_151 & V_235 ) ) {
for ( V_77 = 0 ; V_77 < V_22 -> V_57 ; V_77 ++ ) {
struct V_9 * V_10 = V_22 -> V_78 + V_77 ;
V_224 = F_103 ( V_75 ,
V_22 -> V_46 , NULL , V_10 , V_202 ,
& V_225 ) ;
if ( V_224 ) {
F_81 ( & V_192 ) ;
goto V_67;
}
V_209 += V_225 ;
}
V_224 = F_113 ( V_75 , V_236 , 0 ) ;
if ( V_224 == 0 ) {
V_201 = V_22 -> V_78 [ 0 ] . V_17 ;
V_22 -> V_151 |= V_235 ;
F_114 ( V_22 -> V_116 , V_201 ) ;
F_83 ( V_22 , V_201 -> V_18 ) ;
F_87 ( V_22 -> V_147 , V_201 -> V_18 ) ;
F_115 ( V_75 ) ;
}
}
F_81 ( & V_192 ) ;
if ( V_22 == V_221 )
break;
V_22 = F_33 ( V_22 ) ;
}
V_67:
V_223 . V_34 = V_209 << V_226 ;
if ( F_116 ( V_217 , & V_223 , sizeof( V_223 ) ) )
return - V_231 ;
return V_224 ;
}
static void F_117 ( struct V_92 * V_93 )
{
struct V_84 * * V_133 , * V_134 = NULL ;
int V_237 ;
struct V_35 * V_36 = V_93 -> V_98 ;
struct V_69 * V_22 = V_36 -> V_38 . V_22 ;
T_2 V_238 = F_12 ( & V_36 -> V_38 ) ;
F_3 ( F_47 ( V_36 ) ) ;
F_28 ( & V_22 -> V_112 ) ;
V_133 = & V_22 -> V_107 . V_84 ;
while ( * V_133 ) {
struct V_35 * V_86 =
F_29 ( * V_133 , struct V_35 , V_102 ) ;
V_134 = * V_133 ;
V_237 = F_11 ( V_238 , V_36 -> V_39 , V_86 ) ;
if ( V_237 > 0 )
V_133 = & ( ( * V_133 ) -> V_91 ) ;
else if ( V_237 < 0 )
V_133 = & ( ( * V_133 ) -> V_90 ) ;
else {
F_30 ( & V_22 -> V_112 ) ;
F_90 ( 1 ) ;
return;
}
}
F_69 ( & V_36 -> V_102 , V_134 , V_133 ) ;
F_70 ( & V_36 -> V_102 , & V_22 -> V_107 ) ;
V_22 -> V_108 += V_36 -> V_39 ;
F_30 ( & V_22 -> V_112 ) ;
F_48 ( V_36 , V_239 ) ;
}
static void F_118 ( struct V_69 * V_22 , struct V_92 * V_93 ,
const struct V_240 * V_241 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
T_2 V_41 ;
struct V_35 * V_36 = V_93 -> V_98 ;
T_4 V_242 ;
T_4 V_243 = V_22 -> V_189 - V_22 -> V_108 ;
int V_224 ;
struct V_127 * V_127 = & V_93 -> V_94 ;
if ( F_119 ( V_127 -> V_244 ) )
V_242 = 1 ;
else {
V_242 = F_112 ( T_4 , F_53 ( & V_36 -> V_245 ) , V_241 -> V_246 ) ;
V_242 = F_120 ( V_242 , V_247 , V_243 ) ;
}
if ( ( V_22 -> V_189 < V_22 -> V_108 ) || ( V_243 < V_242 ) )
return;
if ( F_26 ( V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_22 -> V_248 + V_22 -> V_46 ;
if ( F_90 ( F_16 ( & V_2 , V_41 ) ) )
return;
V_224 = F_121 ( & V_2 , V_61 , & V_242 , V_93 , true , V_241 ) ;
if ( V_224 == 0 ) {
V_36 -> V_38 = V_2 ;
V_36 -> V_39 = V_242 ;
V_36 -> V_105 = V_93 -> V_96 ;
F_117 ( V_93 ) ;
} else {
if ( V_41 == V_22 -> V_248 + V_22 -> V_46 )
V_22 -> V_248 = 0 ;
}
}
static T_2 F_122 ( struct V_69 * V_22 , T_2 V_44 ,
T_4 V_76 ,
const struct V_92 * V_93 )
{
struct V_35 * V_36 ;
struct V_84 * V_59 ;
int V_237 ;
F_28 ( & V_22 -> V_112 ) ;
V_59 = V_22 -> V_107 . V_84 ;
while ( V_59 ) {
V_36 = F_29 ( V_59 , struct V_35 , V_102 ) ;
V_237 = F_11 ( V_44 , V_76 , V_36 ) ;
if ( V_237 < 0 )
V_59 = V_59 -> V_90 ;
else if ( V_237 > 0 )
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
static int F_123 ( struct V_1 * V_2 ,
const struct V_92 * V_93 ,
T_4 V_249 ,
struct V_250 * V_251 )
{
T_2 V_44 = F_12 ( V_2 ) ;
T_4 V_242 = 1 ;
T_2 V_252 ;
int V_224 ;
if ( V_249 ) {
V_242 = F_20 ( V_2 , V_249 ) ;
if ( V_242 <= V_251 -> V_34 )
goto V_142;
}
V_252 = F_122 ( V_2 -> V_22 , V_44 , V_242 , V_93 ) ;
if ( V_252 == V_44 ) {
if ( ! V_249 || V_242 >= V_249 )
return 0 ;
if ( V_242 > V_251 -> V_34 ) {
V_251 -> V_34 = V_242 ;
V_251 -> V_2 = * V_2 ;
}
V_142:
V_252 = V_44 + V_242 ;
}
V_224 = F_16 ( V_2 , V_252 ) ;
if ( V_224 < 0 )
return V_224 ;
return 1 ;
}
static int F_121 ( struct V_1 * V_2 , T_1 V_30 , T_4 * V_249 ,
const struct V_92 * V_93 , bool V_253 ,
const struct V_240 * V_241 )
{
struct V_200 * V_201 ;
int V_254 ;
T_4 V_255 ;
int V_256 = V_2 -> V_51 ;
T_4 V_257 = V_2 -> V_14 ;
T_4 V_14 ;
T_1 * V_26 ;
int V_59 = 0 ;
int V_258 = V_2 -> V_22 -> V_57 ;
int V_224 ;
struct V_9 * V_10 ;
struct V_250 V_251 = { . V_2 . V_22 = V_2 -> V_22 , } ;
if ( V_2 -> V_14 != 0 )
V_258 ++ ;
while( 1 ) {
V_10 = F_2 ( V_2 ) ;
if ( F_102 ( V_110 , & V_10 -> V_111 ) &&
( V_30 == V_61 ) )
goto V_259;
V_201 = V_10 -> V_17 ;
V_26 = V_201 -> V_18 + V_10 -> V_19 ;
F_90 ( ! F_91 ( V_201 ) ) ;
if ( V_30 != V_184 && V_10 -> V_25 )
V_26 = V_10 -> V_25 + V_10 -> V_19 ;
V_255 = V_2 -> V_14 ;
V_14 = F_13 ( V_26 , V_10 -> V_12 , V_2 -> V_14 , V_30 ) ;
if ( V_14 == V_43 )
goto V_260;
V_2 -> V_14 = V_14 ;
if ( V_93 == NULL )
return 0 ;
V_254 = V_2 -> V_51 ;
V_224 = F_123 ( V_2 , V_93 ,
V_249 ? * V_249 : 0 ,
& V_251 ) ;
if ( V_224 == 0 )
return 0 ;
if ( V_224 > 0 ) {
V_59 += ( V_2 -> V_51 - V_254 ) ;
goto V_261;
}
if ( V_224 == - V_50 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_14 = 0 ;
V_59 += ( V_2 -> V_51 - V_254 ) ;
goto V_262;
}
return V_224 ;
V_260:
if ( ( V_30 == V_61 ) && V_255 == 0 )
F_124 ( V_110 , & V_10 -> V_111 ) ;
V_259:
V_2 -> V_14 = 0 ;
V_2 -> V_51 ++ ;
if ( V_2 -> V_51 == V_2 -> V_22 -> V_57 )
V_2 -> V_51 = 0 ;
V_262:
if ( ( V_2 -> V_51 == 0 ) && V_253 )
break;
V_59 ++ ;
V_261:
if ( V_59 >= V_258 )
break;
}
if ( V_249 == NULL || V_30 != V_61 )
return - V_263 ;
if ( ( V_257 == 0 ) && ( V_256 == 0 ) &&
( * V_249 < V_2 -> V_22 -> V_109 ) )
V_2 -> V_22 -> V_109 = * V_249 ;
if ( V_251 . V_34 ) {
* V_2 = V_251 . V_2 ;
* V_249 = V_251 . V_34 ;
return 0 ;
}
return - V_263 ;
}
static void F_125 ( struct V_69 * V_22 , T_2 * V_264 , T_2 V_265 )
{
T_2 V_44 ;
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_114 * V_115 ;
struct V_92 * V_93 ;
int error ;
int V_266 = 0 ;
struct V_1 V_2 = { . V_22 = V_22 , . V_51 = 0 , . V_14 = 0 } ;
while ( 1 ) {
F_40 ( & V_75 -> V_267 ) ;
error = F_121 ( & V_2 , V_184 , NULL , NULL ,
true , NULL ) ;
F_43 ( & V_75 -> V_267 ) ;
if ( error == - V_263 )
break;
if ( F_17 ( error ) )
break;
V_44 = F_12 ( & V_2 ) ;
if ( F_16 ( & V_2 , V_44 + 1 ) )
break;
if ( * V_264 != V_268 && V_44 <= * V_264 )
continue;
if ( V_44 == V_265 )
continue;
* V_264 = V_44 ;
error = F_74 ( V_75 , V_44 , & V_269 , V_144 , & V_115 ) ;
if ( error )
continue;
V_93 = V_115 -> V_119 ;
if ( V_93 || F_126 ( V_270 , & V_115 -> V_271 ) == 0 )
F_58 ( V_115 ) ;
else
V_266 ++ ;
if ( V_266 > V_272 )
return;
}
V_22 -> V_151 &= ~ V_188 ;
return;
}
static bool F_127 ( const struct V_69 * V_22 , int V_273 )
{
const struct V_114 * V_115 = V_22 -> V_116 ;
const struct V_74 * V_75 = V_115 -> V_274 . V_275 ;
struct V_276 * V_277 ;
T_2 V_278 , V_279 ;
T_2 V_280 , V_281 = 0 ;
T_9 V_282 ;
T_2 V_283 ;
T_2 V_284 ;
int V_285 , V_286 = 0 ;
F_128 () ;
F_129 (cpu) {
V_277 = & F_130 ( V_75 -> V_287 , V_285 ) -> V_288 [ V_289 ] ;
if ( V_277 -> V_290 [ V_291 ] ) {
V_281 += V_277 -> V_290 [ V_291 ] ;
V_286 ++ ;
}
}
V_277 = & F_131 ( V_75 -> V_287 ) -> V_288 [ V_289 ] ;
if ( V_286 )
F_132 ( V_281 , V_286 ) ;
V_278 = V_277 -> V_290 [ V_292 ] ;
V_284 = V_277 -> V_290 [ V_293 ] +
V_115 -> V_294 . V_290 [ V_293 ] ;
F_133 () ;
V_280 = V_115 -> V_294 . V_290 [ V_291 ] ;
V_279 = V_115 -> V_294 . V_290 [ V_292 ] ;
if ( ( V_279 < 1 ) || ( V_278 < 1 ) || ( V_281 == 0 ) )
return false ;
V_282 = V_281 - V_280 ;
V_283 = V_282 * V_282 ;
V_284 *= 2 ;
if ( V_279 < 8 || V_278 < 8 )
V_284 *= 2 ;
if ( V_273 == 1 )
V_284 *= 2 ;
return ( ( V_282 < 0 ) && ( V_283 > V_284 ) ) ;
}
static bool F_134 ( const struct V_35 * V_36 ,
T_2 V_295 )
{
T_2 V_296 ;
V_296 = F_135 ( F_136 ( F_137 () ,
V_36 -> V_38 . V_22 -> V_116 -> V_297 ) ) ;
return V_296 > ( V_295 * 1000 * 1000 ) ;
}
static T_4 F_138 ( const struct V_92 * V_93 )
{
const struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
T_4 V_265 ;
F_139 ( & V_265 , sizeof( V_265 ) ) ;
return V_265 % V_75 -> V_136 ;
}
static bool F_140 ( struct V_69 * * V_131 , const struct V_69 * V_298 )
{
struct V_69 * V_22 = * V_131 ;
struct V_74 * V_75 = V_22 -> V_55 ;
V_22 = F_33 ( V_22 ) ;
if ( V_22 == NULL )
V_22 = F_31 ( V_75 ) ;
* V_131 = V_22 ;
if ( V_22 != V_298 )
return true ;
return false ;
}
static inline int F_141 ( struct V_69 * V_22 )
{
struct V_114 * V_115 = V_22 -> V_116 ;
if ( V_115 -> V_299 != V_300 && F_142 ( & V_115 -> V_301 ) &&
! F_102 ( V_302 , & V_115 -> V_198 ) &&
! F_102 ( V_197 , & V_115 -> V_198 ) )
return 1 ;
if ( V_22 -> V_151 & V_153 )
return 1 ;
return 0 ;
}
int F_143 ( struct V_92 * V_93 , struct V_240 * V_241 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_298 = NULL ;
struct V_35 * V_36 = V_93 -> V_98 ;
int error = 0 , V_303 , V_304 = 0 ;
T_2 V_264 = V_268 ;
int V_273 = 0 ;
T_4 V_265 = 0 ;
if ( V_75 -> V_190 . V_191 )
V_304 |= V_195 ;
if ( F_97 ( V_75 , V_241 -> V_246 ) )
return - V_48 ;
if ( F_47 ( V_36 ) ) {
V_298 = V_36 -> V_38 . V_22 ;
} else if ( V_93 -> V_305 && F_26 ( V_93 -> V_305 , V_93 -> V_95 ) ) {
V_36 -> V_38 . V_22 = V_298 = V_93 -> V_305 ;
} else {
F_35 ( V_93 ) ;
V_36 -> V_38 . V_22 = V_298 = F_27 ( V_75 , V_93 -> V_95 , 1 ) ;
}
if ( F_119 ( V_93 -> V_94 . V_244 ) && ( V_241 -> V_306 & V_307 ) )
V_265 = F_138 ( V_93 ) ;
if ( V_36 -> V_38 . V_22 == NULL )
return - V_308 ;
while ( V_273 < 3 ) {
V_303 = 1 ;
if ( ! F_79 ( V_36 -> V_38 . V_22 -> V_116 ) ) {
V_303 = 0 ;
if ( V_265 && V_265 -- )
goto V_309;
if ( ! F_47 ( V_36 ) ) {
if ( V_273 == 0 &&
! F_141 ( V_36 -> V_38 . V_22 ) )
goto V_309;
if ( ( V_273 < 2 ) &&
F_134 ( V_36 , 1000 ) &&
F_127 ( V_36 -> V_38 . V_22 , V_273 ) )
goto V_309;
}
error = F_80 ( V_36 -> V_38 . V_22 -> V_116 ,
V_234 , V_304 ,
& V_36 -> V_310 ) ;
if ( F_4 ( error ) )
return error ;
if ( ! F_47 ( V_36 ) && ( V_273 < 2 ) &&
F_127 ( V_36 -> V_38 . V_22 , V_273 ) )
goto V_311;
if ( V_75 -> V_190 . V_191 ) {
error = F_98 ( V_36 -> V_38 . V_22 ) ;
if ( F_4 ( error ) ) {
F_81 ( & V_36 -> V_310 ) ;
return error ;
}
}
}
if ( ( V_36 -> V_38 . V_22 -> V_151 & ( V_312 |
V_313 ) ) ||
( V_273 == 0 && V_241 -> V_246 > V_36 -> V_38 . V_22 -> V_109 ) )
goto V_311;
if ( V_75 -> V_190 . V_191 )
F_92 ( V_36 -> V_38 . V_22 ) ;
if ( ! F_47 ( V_36 ) )
F_118 ( V_36 -> V_38 . V_22 , V_93 , V_241 ) ;
if ( ! F_47 ( V_36 ) && ( V_273 < 1 ) )
goto V_314;
if ( V_36 -> V_38 . V_22 -> V_189 >= V_241 -> V_246 ||
( V_273 == 2 && V_241 -> V_315 &&
V_36 -> V_38 . V_22 -> V_189 >= V_241 -> V_315 ) ) {
V_93 -> V_305 = V_36 -> V_38 . V_22 ;
V_241 -> V_316 = V_93 -> V_305 -> V_189 ;
return 0 ;
}
V_314:
if ( V_36 -> V_38 . V_22 -> V_151 & V_188 )
F_125 ( V_36 -> V_38 . V_22 , & V_264 ,
V_93 -> V_96 ) ;
V_311:
if ( F_47 ( V_36 ) )
F_51 ( V_36 ) ;
if ( ! V_303 )
F_81 ( & V_36 -> V_310 ) ;
V_309:
if ( F_140 ( & V_36 -> V_38 . V_22 , V_298 ) )
continue;
if ( V_265 )
continue;
V_273 ++ ;
if ( V_93 == F_64 ( V_75 -> V_128 ) && ! V_75 -> V_159 ) {
error = F_77 ( V_93 ) ;
if ( error )
return error ;
}
if ( V_273 == 2 )
F_144 ( V_75 , NULL , V_317 ) ;
}
return - V_263 ;
}
void F_145 ( struct V_92 * V_93 )
{
struct V_35 * V_36 = V_93 -> V_98 ;
if ( V_36 -> V_310 . V_193 )
F_81 ( & V_36 -> V_310 ) ;
}
static unsigned char F_146 ( struct V_69 * V_22 , T_2 V_44 )
{
struct V_1 V_2 = { . V_22 = V_22 , } ;
int V_224 ;
V_224 = F_16 ( & V_2 , V_44 ) ;
F_17 ( V_224 != 0 ) ;
return F_8 ( & V_2 ) ;
}
static void F_147 ( const struct V_1 * V_2 , bool V_318 ,
unsigned int * V_59 )
{
struct V_1 V_131 = { . V_22 = V_2 -> V_22 , } ;
const unsigned int V_319 = * V_59 ;
T_2 V_44 ;
int V_224 ;
* V_59 = 1 ;
V_44 = F_12 ( V_2 ) ;
F_114 ( V_2 -> V_22 -> V_116 , F_2 ( V_2 ) -> V_17 ) ;
F_1 ( V_2 , true , V_318 ? V_320 : V_321 ) ;
V_44 ++ ;
while ( * V_59 < V_319 ) {
V_224 = F_16 ( & V_131 , V_44 ) ;
if ( V_224 || F_8 ( & V_131 ) != V_61 )
break;
F_114 ( V_131 . V_22 -> V_116 , F_2 ( & V_131 ) -> V_17 ) ;
F_1 ( & V_131 , true , V_321 ) ;
( * V_59 ) ++ ;
V_44 ++ ;
}
}
static struct V_69 * F_148 ( struct V_74 * V_75 , T_2 V_322 ,
T_4 V_323 , unsigned char V_4 )
{
struct V_1 V_2 ;
struct V_9 * V_10 , * V_324 = NULL ;
V_2 . V_22 = F_27 ( V_75 , V_322 , 1 ) ;
if ( ! V_2 . V_22 ) {
if ( F_149 ( V_75 ) )
F_25 ( V_75 , L_15 , ( unsigned long long ) V_322 ) ;
return NULL ;
}
F_16 ( & V_2 , V_322 ) ;
while ( V_323 -- ) {
V_10 = F_2 ( & V_2 ) ;
if ( V_10 != V_324 ) {
if ( ! V_10 -> V_25 ) {
V_10 -> V_25 = F_150 ( V_10 -> V_17 -> V_68 ,
V_100 | V_325 ) ;
memcpy ( V_10 -> V_25 + V_10 -> V_19 ,
V_10 -> V_17 -> V_18 + V_10 -> V_19 ,
V_10 -> V_12 ) ;
}
F_114 ( V_2 . V_22 -> V_116 , V_10 -> V_17 ) ;
V_324 = V_10 ;
}
F_1 ( & V_2 , false , V_4 ) ;
F_18 ( & V_2 ) ;
}
return V_2 . V_22 ;
}
void F_151 ( struct V_103 * V_104 , const struct V_114 * V_115 )
{
struct V_69 * V_22 = V_115 -> V_119 ;
struct V_35 * V_326 ;
const struct V_84 * V_59 ;
if ( V_22 == NULL )
return;
F_45 ( V_104 , L_16 ,
( unsigned long long ) V_22 -> V_23 , V_22 -> V_151 ,
V_22 -> V_79 , V_22 -> V_189 , V_22 -> V_80 ,
V_22 -> V_108 , V_22 -> V_109 ) ;
F_28 ( & V_22 -> V_112 ) ;
for ( V_59 = F_32 ( & V_22 -> V_107 ) ; V_59 ; V_59 = F_34 ( & V_326 -> V_102 ) ) {
V_326 = F_29 ( V_59 , struct V_35 , V_102 ) ;
F_44 ( V_104 , V_326 ) ;
}
F_30 ( & V_22 -> V_112 ) ;
}
static void F_152 ( struct V_69 * V_22 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
F_105 ( V_75 , L_17 ,
( unsigned long long ) V_22 -> V_23 ) ;
F_105 ( V_75 , L_18 ) ;
F_151 ( NULL , V_22 -> V_116 ) ;
V_22 -> V_151 |= V_313 ;
}
static void F_153 ( struct V_92 * V_93 ,
const struct V_1 * V_2 , unsigned V_34 )
{
struct V_35 * V_36 = V_93 -> V_98 ;
struct V_69 * V_22 = V_2 -> V_22 ;
unsigned V_327 ;
T_2 V_44 ;
int V_224 ;
F_28 ( & V_22 -> V_112 ) ;
if ( F_47 ( V_36 ) ) {
if ( F_154 ( & V_36 -> V_38 , V_2 ) ) {
V_44 = F_12 ( V_2 ) ;
V_224 = F_16 ( & V_36 -> V_38 , V_44 + V_34 ) ;
V_327 = F_155 ( V_36 -> V_39 , V_34 ) ;
V_36 -> V_39 -= V_327 ;
V_22 -> V_108 -= V_327 ;
F_48 ( V_36 , V_328 ) ;
if ( V_36 -> V_39 && ! V_224 )
goto V_67;
F_156 ( V_329 , & V_36 -> V_245 ) ;
}
F_46 ( V_36 ) ;
}
V_67:
F_30 ( & V_22 -> V_112 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
const struct V_92 * V_93 , bool V_318 )
{
T_2 V_41 ;
if ( F_47 ( V_93 -> V_98 ) ) {
* V_2 = V_93 -> V_98 -> V_38 ;
return;
}
if ( ! V_318 && F_26 ( V_2 -> V_22 , V_93 -> V_95 ) )
V_41 = V_93 -> V_95 ;
else
V_41 = V_2 -> V_22 -> V_248 + V_2 -> V_22 -> V_46 ;
F_16 ( V_2 , V_41 ) ;
}
int F_158 ( struct V_92 * V_93 , T_2 * V_330 , unsigned int * V_331 ,
bool V_318 , T_2 * V_332 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_200 * V_333 ;
struct V_1 V_2 = { . V_22 = V_93 -> V_305 , } ;
unsigned int V_334 ;
T_2 V_44 ;
int error ;
F_157 ( & V_2 , V_93 , V_318 ) ;
error = F_121 ( & V_2 , V_61 , NULL , V_93 , false , NULL ) ;
if ( error == - V_263 ) {
F_157 ( & V_2 , V_93 , V_318 ) ;
error = F_121 ( & V_2 , V_61 , NULL , NULL , false ,
NULL ) ;
}
if ( error ) {
F_105 ( V_75 , L_19 ,
( unsigned long long ) V_93 -> V_96 , error , * V_331 ,
F_102 ( V_110 , & V_2 . V_22 -> V_78 -> V_111 ) ,
V_2 . V_22 -> V_109 ) ;
goto V_335;
}
F_147 ( & V_2 , V_318 , V_331 ) ;
V_44 = F_12 ( & V_2 ) ;
V_2 . V_22 -> V_248 = V_44 - V_2 . V_22 -> V_46 ;
if ( F_47 ( V_93 -> V_98 ) )
F_153 ( V_93 , & V_2 , * V_331 ) ;
V_334 = * V_331 ;
if ( V_318 )
V_334 -- ;
if ( ! V_318 ) {
V_93 -> V_95 = V_44 + V_334 - 1 ;
error = F_159 ( V_93 , & V_333 ) ;
if ( error == 0 ) {
struct V_336 * V_337 =
(struct V_336 * ) V_333 -> V_18 ;
F_114 ( V_93 -> V_160 , V_333 ) ;
V_337 -> V_338 = V_337 -> V_339 =
F_85 ( V_93 -> V_95 ) ;
F_96 ( V_333 ) ;
}
}
if ( V_2 . V_22 -> V_79 < * V_331 ) {
F_5 ( L_20 , * V_331 ) ;
goto V_335;
}
V_2 . V_22 -> V_79 -= * V_331 ;
if ( V_318 ) {
V_2 . V_22 -> V_80 ++ ;
* V_332 = V_2 . V_22 -> V_170 ++ ;
if ( * V_332 == 0 )
* V_332 = V_2 . V_22 -> V_170 ++ ;
}
F_114 ( V_2 . V_22 -> V_116 , V_2 . V_22 -> V_78 [ 0 ] . V_17 ) ;
F_83 ( V_2 . V_22 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_87 ( V_2 . V_22 -> V_147 , V_2 . V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_160 ( V_75 , 0 , - ( T_9 ) * V_331 , V_318 ? 1 : 0 ) ;
if ( V_318 )
F_161 ( V_75 , V_44 , * V_331 ) ;
F_162 ( V_93 , * V_331 , V_93 -> V_94 . V_340 , V_93 -> V_94 . V_341 ) ;
V_2 . V_22 -> V_189 -= * V_331 ;
F_163 ( V_93 , V_2 . V_22 , V_44 , * V_331 ,
V_318 ? V_320 : V_321 ) ;
* V_330 = V_44 ;
return 0 ;
V_335:
F_152 ( V_2 . V_22 ) ;
return - V_125 ;
}
void F_164 ( struct V_92 * V_93 , T_2 V_322 , T_4 V_323 , int V_342 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
V_22 = F_148 ( V_75 , V_322 , V_323 , V_61 ) ;
if ( ! V_22 )
return;
F_163 ( V_93 , V_22 , V_322 , V_323 , V_61 ) ;
V_22 -> V_79 += V_323 ;
V_22 -> V_151 &= ~ V_235 ;
F_114 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_83 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_87 ( V_22 -> V_147 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
if ( V_342 || V_93 -> V_343 )
F_165 ( V_93 , V_322 , V_323 ) ;
}
void F_166 ( struct V_92 * V_93 , T_2 V_322 , T_4 V_323 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
F_164 ( V_93 , V_322 , V_323 , 1 ) ;
F_160 ( V_75 , 0 , + V_323 , 0 ) ;
F_162 ( V_93 , - ( T_9 ) V_323 , V_93 -> V_94 . V_340 , V_93 -> V_94 . V_341 ) ;
}
void F_167 ( struct V_127 * V_127 )
{
struct V_92 * V_93 = F_64 ( V_127 ) ;
struct V_74 * V_75 = F_36 ( V_127 ) ;
struct V_69 * V_22 ;
T_2 V_344 = V_93 -> V_96 ;
V_22 = F_148 ( V_75 , V_344 , 1 , V_184 ) ;
if ( ! V_22 )
return;
F_163 ( V_93 , V_22 , V_344 , 1 , V_184 ) ;
F_114 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_83 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_87 ( V_22 -> V_147 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_88 ( V_22 , 1 ) ;
}
static void F_168 ( struct V_69 * V_22 , T_2 V_344 )
{
struct V_74 * V_75 = V_22 -> V_55 ;
struct V_69 * V_345 ;
V_345 = F_148 ( V_75 , V_344 , 1 , V_61 ) ;
if ( ! V_345 )
return;
F_169 ( V_75 , V_22 == V_345 ) ;
if ( ! V_22 -> V_80 )
F_7 ( V_22 ) ;
V_22 -> V_80 -- ;
V_22 -> V_79 ++ ;
F_114 ( V_22 -> V_116 , V_22 -> V_78 [ 0 ] . V_17 ) ;
F_83 ( V_22 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_87 ( V_22 -> V_147 , V_22 -> V_78 [ 0 ] . V_17 -> V_18 ) ;
F_88 ( V_22 , - 1 ) ;
F_160 ( V_75 , 0 , + 1 , - 1 ) ;
}
void F_170 ( struct V_69 * V_22 , struct V_92 * V_93 )
{
F_168 ( V_22 , V_93 -> V_96 ) ;
F_163 ( V_93 , V_22 , V_93 -> V_96 , 1 , V_61 ) ;
F_162 ( V_93 , - 1 , V_93 -> V_94 . V_340 , V_93 -> V_94 . V_341 ) ;
F_165 ( V_93 , V_93 -> V_96 , 1 ) ;
}
int F_171 ( struct V_74 * V_75 , T_2 V_346 , unsigned int type )
{
struct V_69 * V_22 ;
struct V_161 V_347 ;
int error = - V_48 ;
V_22 = F_27 ( V_75 , V_346 , 1 ) ;
if ( ! V_22 )
goto V_142;
error = F_80 ( V_22 -> V_116 , V_164 , 0 , & V_347 ) ;
if ( error )
goto V_142;
if ( F_146 ( V_22 , V_346 ) != type )
error = - V_348 ;
F_81 ( & V_347 ) ;
V_142:
return error ;
}
void F_172 ( struct V_92 * V_93 , struct V_349 * V_350 ,
T_2 V_44 )
{
struct V_74 * V_75 = F_36 ( & V_93 -> V_94 ) ;
struct V_69 * V_22 ;
struct V_69 * * V_31 ;
unsigned int V_351 ;
unsigned int V_77 ;
if ( F_97 ( V_75 , ! V_350 -> V_352 ) )
return;
if ( V_93 -> V_305 && F_26 ( V_93 -> V_305 , V_44 ) )
V_22 = V_93 -> V_305 ;
else
V_22 = F_27 ( V_75 , V_44 , 1 ) ;
if ( ! V_22 ) {
F_25 ( V_75 , L_21 , ( unsigned long long ) V_44 ) ;
return;
}
V_93 -> V_305 = V_22 ;
for ( V_77 = 0 ; V_77 < V_350 -> V_353 ; V_77 ++ )
if ( V_350 -> V_354 [ V_77 ] == V_22 )
return;
if ( V_350 -> V_353 == V_350 -> V_355 ) {
V_351 = V_350 -> V_355 + 10 ;
V_31 = F_62 ( V_351 , sizeof( struct V_69 * ) ,
V_100 | V_325 ) ;
if ( V_350 -> V_354 ) {
memcpy ( V_31 , V_350 -> V_354 ,
V_350 -> V_355 * sizeof( struct V_69 * ) ) ;
F_38 ( V_350 -> V_354 ) ;
}
V_350 -> V_355 = V_351 ;
V_350 -> V_354 = V_31 ;
}
V_350 -> V_354 [ V_350 -> V_353 ++ ] = V_22 ;
}
void F_173 ( struct V_349 * V_350 , unsigned int V_30 )
{
unsigned int V_77 ;
V_350 -> V_352 = F_62 ( V_350 -> V_353 , sizeof( struct V_161 ) ,
V_100 | V_325 ) ;
for ( V_77 = 0 ; V_77 < V_350 -> V_353 ; V_77 ++ )
F_174 ( V_350 -> V_354 [ V_77 ] -> V_116 ,
V_30 , 0 ,
& V_350 -> V_352 [ V_77 ] ) ;
}
void F_175 ( struct V_349 * V_350 )
{
unsigned int V_77 ;
F_38 ( V_350 -> V_354 ) ;
if ( V_350 -> V_352 ) {
for ( V_77 = 0 ; V_77 < V_350 -> V_353 ; V_77 ++ )
F_176 ( & V_350 -> V_352 [ V_77 ] ) ;
F_38 ( V_350 -> V_352 ) ;
V_350 -> V_352 = NULL ;
}
}
