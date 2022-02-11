static inline void F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned char * V_4 , unsigned int V_5 ,
struct V_6 * V_7 , T_1 V_8 ,
unsigned char V_9 )
{
unsigned char * V_10 , * V_11 , * V_12 , V_13 ;
unsigned int V_14 = V_7 -> V_15 ;
const unsigned int V_16 = ( V_8 % V_17 ) * V_18 ;
V_10 = V_3 + V_5 + ( V_8 / V_17 ) ;
V_12 = V_3 + V_5 + V_14 ;
F_2 ( V_10 >= V_12 ) ;
V_13 = ( * V_10 >> V_16 ) & V_19 ;
if ( F_3 ( ! V_20 [ V_9 * 4 + V_13 ] ) ) {
F_4 ( V_21 L_1
L_2 ,
( unsigned long long ) V_8 , V_13 , V_9 ) ;
F_4 ( V_21 L_3 ,
( unsigned long long ) V_2 -> V_22 ,
( unsigned long ) V_7 -> V_23 ) ;
F_4 ( V_21 L_4 ,
( unsigned long ) V_7 -> V_24 ,
( unsigned long ) V_7 -> V_15 ) ;
F_5 () ;
F_6 ( V_2 ) ;
return;
}
* V_10 ^= ( V_13 ^ V_9 ) << V_16 ;
if ( V_4 ) {
V_11 = V_4 + V_5 + ( V_8 / V_17 ) ;
V_13 = ( * V_11 >> V_16 ) & V_19 ;
* V_11 ^= ( V_13 ^ V_9 ) << V_16 ;
}
}
static inline unsigned char F_7 ( struct V_1 * V_2 ,
const unsigned char * V_25 ,
unsigned int V_14 , T_1 V_8 )
{
const unsigned char * V_26 , * V_12 ;
unsigned char V_13 ;
unsigned int V_16 ;
V_26 = V_25 + ( V_8 / V_17 ) ;
V_16 = ( V_8 % V_17 ) * V_18 ;
V_12 = V_25 + V_14 ;
F_8 ( V_2 -> V_27 , V_26 < V_12 ) ;
V_13 = ( * V_26 >> V_16 ) & V_19 ;
return V_13 ;
}
static inline T_2 F_9 ( const T_3 * V_28 , T_2 V_29 , T_4 V_30 )
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
static T_1 F_11 ( const T_4 * V_33 , const unsigned int V_34 ,
T_1 V_35 , T_4 V_30 )
{
T_1 V_36 = ( V_35 << 1 ) & ( ( 8 * sizeof( T_2 ) ) - 1 ) ;
const T_3 * V_28 = ( ( T_3 * ) V_33 ) + ( V_35 >> 5 ) ;
const T_3 * V_12 = ( T_3 * ) ( V_33 + F_12 ( V_34 , sizeof( T_2 ) ) ) ;
T_2 V_31 ;
T_2 V_29 = 0x5555555555555555ULL ;
T_1 V_16 ;
F_2 ( V_30 > 3 ) ;
V_29 <<= V_36 ;
V_31 = F_9 ( V_28 , V_29 , V_30 ) ;
V_28 ++ ;
while( V_31 == 0 && V_28 < V_12 ) {
V_31 = F_9 ( V_28 , 0x5555555555555555ULL , V_30 ) ;
V_28 ++ ;
}
if ( V_28 == V_12 && ( V_34 & ( sizeof( T_2 ) - 1 ) ) )
V_31 &= ( ( ( T_2 ) ~ 0 ) >> ( 64 - 8 * ( V_34 & ( sizeof( T_2 ) - 1 ) ) ) ) ;
if ( V_31 == 0 )
return V_37 ;
V_28 -- ;
V_16 = F_13 ( V_31 ) ;
V_16 /= 2 ;
return ( ( ( const unsigned char * ) V_28 - V_33 ) * V_17 ) + V_16 ;
}
static T_1 F_14 ( struct V_1 * V_2 , const T_4 * V_25 ,
unsigned int V_14 , T_4 V_30 )
{
const T_4 * V_26 = V_25 ;
const T_4 * V_12 = V_25 + V_14 ;
const T_4 V_38 = V_30 << 2 ;
const T_4 V_39 = V_30 << 4 ;
const T_4 V_40 = V_30 << 6 ;
T_1 V_41 = 0 ;
for (; V_26 < V_12 ; V_26 ++ ) {
if ( ( ( * V_26 ) & 0x03 ) == V_30 )
V_41 ++ ;
if ( ( ( * V_26 ) & 0x0C ) == V_38 )
V_41 ++ ;
if ( ( ( * V_26 ) & 0x30 ) == V_39 )
V_41 ++ ;
if ( ( ( * V_26 ) & 0xC0 ) == V_40 )
V_41 ++ ;
}
return V_41 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_6 * V_7 = NULL ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_41 [ 4 ] , V_31 ;
int V_33 , V_46 ;
memset ( V_41 , 0 , 4 * sizeof( T_1 ) ) ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ )
V_41 [ V_46 ] += F_14 ( V_2 ,
V_7 -> V_48 -> V_49 +
V_7 -> V_24 ,
V_7 -> V_15 , V_46 ) ;
}
if ( V_41 [ 0 ] != V_2 -> V_50 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_5 ,
V_41 [ 0 ] , V_2 -> V_50 ) ;
return;
}
V_31 = V_2 -> V_51 - V_2 -> V_50 - V_2 -> V_52 ;
if ( V_41 [ 1 ] != V_31 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_6 ,
V_41 [ 1 ] , V_31 ) ;
return;
}
if ( V_41 [ 2 ] + V_41 [ 3 ] != V_2 -> V_52 ) {
if ( F_6 ( V_2 ) )
F_16 ( V_43 , L_7 ,
V_41 [ 2 ] + V_41 [ 3 ] , V_2 -> V_52 ) ;
return;
}
}
static inline int F_17 ( struct V_1 * V_2 , T_2 V_8 )
{
T_2 V_53 = V_2 -> V_54 ;
T_2 V_55 = V_53 + V_2 -> V_51 ;
return V_53 <= V_8 && V_8 < V_55 ;
}
struct V_1 * F_18 ( struct V_42 * V_43 , T_2 V_56 , bool V_57 )
{
struct V_58 * V_59 , * V_60 ;
struct V_1 * V_61 ;
F_19 ( & V_43 -> V_62 ) ;
V_59 = V_43 -> V_63 . V_58 ;
while ( V_59 ) {
V_61 = F_20 ( V_59 , struct V_1 , V_64 ) ;
V_60 = NULL ;
if ( V_56 < V_61 -> V_22 )
V_60 = V_59 -> V_65 ;
else if ( V_56 >= V_61 -> V_54 + V_61 -> V_51 )
V_60 = V_59 -> V_66 ;
if ( V_60 == NULL ) {
F_21 ( & V_43 -> V_62 ) ;
if ( V_57 ) {
if ( V_56 < V_61 -> V_22 )
return NULL ;
if ( V_56 >= V_61 -> V_54 + V_61 -> V_51 )
return NULL ;
}
return V_61 ;
}
V_59 = V_60 ;
}
F_21 ( & V_43 -> V_62 ) ;
return NULL ;
}
struct V_1 * F_22 ( struct V_42 * V_43 )
{
const struct V_58 * V_59 ;
struct V_1 * V_2 ;
F_19 ( & V_43 -> V_62 ) ;
V_59 = F_23 ( & V_43 -> V_63 ) ;
V_2 = F_20 ( V_59 , struct V_1 , V_64 ) ;
F_21 ( & V_43 -> V_62 ) ;
return V_2 ;
}
struct V_1 * F_24 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
const struct V_58 * V_59 ;
F_19 ( & V_43 -> V_62 ) ;
V_59 = F_25 ( & V_2 -> V_64 ) ;
if ( V_59 == NULL )
V_59 = F_23 ( & V_43 -> V_63 ) ;
if ( F_3 ( & V_2 -> V_64 == V_59 ) ) {
F_21 ( & V_43 -> V_62 ) ;
return NULL ;
}
V_2 = F_20 ( V_59 , struct V_1 , V_64 ) ;
F_21 ( & V_43 -> V_62 ) ;
return V_2 ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_45 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
F_27 ( V_7 -> V_67 ) ;
V_7 -> V_67 = NULL ;
}
}
void F_28 ( struct V_42 * V_43 )
{
struct V_58 * V_59 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
while ( ( V_59 = F_23 ( & V_43 -> V_63 ) ) ) {
V_2 = F_20 ( V_59 , struct V_1 , V_64 ) ;
V_69 = V_2 -> V_70 ;
F_29 ( V_59 , & V_43 -> V_63 ) ;
if ( V_69 ) {
F_19 ( & V_69 -> V_71 ) ;
V_69 -> V_72 = NULL ;
F_21 ( & V_69 -> V_71 ) ;
F_30 ( V_69 ) ;
F_31 ( V_69 ) ;
}
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_47 ) ;
F_32 ( V_73 , V_2 ) ;
}
}
static void F_33 ( const struct V_1 * V_2 )
{
F_4 ( V_74 L_8 , ( unsigned long long ) V_2 -> V_22 ) ;
F_4 ( V_74 L_9 , V_2 -> V_45 ) ;
F_4 ( V_74 L_10 , ( unsigned long long ) V_2 -> V_54 ) ;
F_4 ( V_74 L_11 , V_2 -> V_51 ) ;
F_4 ( V_74 L_12 , V_2 -> V_75 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_6 * V_7 ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_76 , V_77 ;
int V_46 ;
if ( ! V_44 )
return - V_78 ;
V_2 -> V_47 = F_35 ( V_44 , sizeof( struct V_6 ) , V_79 ) ;
if ( ! V_2 -> V_47 )
return - V_80 ;
V_76 = V_2 -> V_75 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
V_7 -> V_81 = 0 ;
if ( V_44 == 1 ) {
V_77 = V_76 ;
V_7 -> V_24 = sizeof( struct V_82 ) ;
V_7 -> V_23 = 0 ;
V_7 -> V_15 = V_77 ;
} else if ( V_46 == 0 ) {
V_77 = V_43 -> V_83 . V_84 - sizeof( struct V_82 ) ;
V_7 -> V_24 = sizeof( struct V_82 ) ;
V_7 -> V_23 = 0 ;
V_7 -> V_15 = V_77 ;
} else if ( V_46 + 1 == V_44 ) {
V_77 = V_76 ;
V_7 -> V_24 = sizeof( struct V_85 ) ;
V_7 -> V_23 = V_2 -> V_75 - V_76 ;
V_7 -> V_15 = V_77 ;
} else {
V_77 = V_43 -> V_83 . V_84 -
sizeof( struct V_85 ) ;
V_7 -> V_24 = sizeof( struct V_85 ) ;
V_7 -> V_23 = V_2 -> V_75 - V_76 ;
V_7 -> V_15 = V_77 ;
}
V_76 -= V_77 ;
}
if ( V_76 ) {
F_6 ( V_2 ) ;
return - V_86 ;
}
V_7 = V_2 -> V_47 + ( V_44 - 1 ) ;
if ( ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 != V_2 -> V_51 ) {
if ( F_6 ( V_2 ) ) {
F_33 ( V_2 ) ;
F_16 ( V_43 , L_13 ,
V_7 -> V_23 , V_7 -> V_15 , V_7 -> V_24 ) ;
}
return - V_86 ;
}
return 0 ;
}
T_2 F_36 ( struct V_42 * V_43 )
{
T_2 V_87 = 0 ;
struct V_88 * V_88 = V_43 -> V_89 ;
struct V_90 * V_91 = F_37 ( V_88 ) ;
char V_33 [ sizeof( struct V_92 ) ] ;
struct V_93 V_94 ;
int error , V_95 ;
F_38 ( & V_94 , V_88 -> V_96 ) ;
for ( V_95 = 0 ; ; V_95 ++ ) {
T_5 V_97 = V_95 * sizeof( struct V_92 ) ;
if ( V_97 + sizeof( struct V_92 ) > F_39 ( V_88 ) )
break;
error = F_40 ( V_91 , & V_94 , V_33 , & V_97 ,
sizeof( struct V_92 ) ) ;
if ( error != sizeof( struct V_92 ) )
break;
V_87 += F_41 ( ( (struct V_92 * ) V_33 ) -> V_98 ) ;
}
return V_87 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_58 * * V_99 = & V_43 -> V_63 . V_58 , * V_100 = NULL ;
while ( * V_99 ) {
struct V_1 * V_61 = F_20 ( * V_99 , struct V_1 ,
V_64 ) ;
V_100 = * V_99 ;
if ( V_2 -> V_22 < V_61 -> V_22 )
V_99 = & ( ( * V_99 ) -> V_65 ) ;
else if ( V_2 -> V_22 > V_61 -> V_22 )
V_99 = & ( ( * V_99 ) -> V_66 ) ;
else
return - V_101 ;
}
F_43 ( & V_2 -> V_64 , V_100 , V_99 ) ;
F_44 ( & V_2 -> V_64 , & V_43 -> V_63 ) ;
V_43 -> V_102 ++ ;
return 0 ;
}
static int F_45 ( struct V_90 * V_91 ,
struct V_93 * V_94 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
T_5 V_97 = V_43 -> V_102 * sizeof( struct V_92 ) ;
struct V_92 V_33 ;
int error ;
struct V_1 * V_2 ;
if ( V_97 >= F_39 ( & V_91 -> V_103 ) )
return 1 ;
error = F_40 ( V_91 , V_94 , ( char * ) & V_33 , & V_97 ,
sizeof( struct V_92 ) ) ;
if ( error != sizeof( struct V_92 ) )
return ( error == 0 ) ? 1 : error ;
V_2 = F_47 ( V_73 , V_79 ) ;
error = - V_80 ;
if ( ! V_2 )
return error ;
V_2 -> V_27 = V_43 ;
V_2 -> V_22 = F_48 ( V_33 . V_104 ) ;
V_2 -> V_45 = F_41 ( V_33 . V_105 ) ;
V_2 -> V_54 = F_48 ( V_33 . V_106 ) ;
V_2 -> V_51 = F_41 ( V_33 . V_98 ) ;
V_2 -> V_75 = F_41 ( V_33 . V_107 ) ;
error = F_34 ( V_2 ) ;
if ( error )
goto V_108;
error = F_49 ( V_43 , V_2 -> V_22 ,
& V_109 , V_110 , & V_2 -> V_70 ) ;
if ( error )
goto V_108;
V_2 -> V_70 -> V_72 = V_2 ;
V_2 -> V_111 &= ~ V_112 ;
if ( V_2 -> V_51 > V_43 -> V_113 )
V_43 -> V_113 = V_2 -> V_51 ;
F_19 ( & V_43 -> V_62 ) ;
error = F_42 ( V_2 ) ;
F_21 ( & V_43 -> V_62 ) ;
if ( ! error )
return 0 ;
error = 0 ;
F_31 ( V_2 -> V_70 ) ;
V_108:
F_27 ( V_2 -> V_47 ) ;
F_32 ( V_73 , V_2 ) ;
return error ;
}
static int F_50 ( struct V_90 * V_91 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
struct V_88 * V_88 = & V_91 -> V_103 ;
struct V_93 V_94 ;
int error ;
F_38 ( & V_94 , V_88 -> V_96 ) ;
do {
error = F_45 ( V_91 , & V_94 ) ;
} while ( error == 0 );
if ( error < 0 )
return error ;
V_43 -> V_114 = 1 ;
return 0 ;
}
int F_51 ( struct V_42 * V_43 )
{
struct V_90 * V_91 = F_37 ( V_43 -> V_89 ) ;
struct V_68 * V_69 = V_91 -> V_115 ;
struct V_116 V_117 ;
int error = 0 ;
int V_118 = 0 ;
if ( ! V_43 -> V_114 ) {
if ( ! F_52 ( V_69 ) ) {
error = F_53 ( V_69 , V_119 , 0 , & V_117 ) ;
if ( error )
return error ;
V_118 = 1 ;
}
if ( ! V_43 -> V_114 )
error = F_50 ( V_91 ) ;
if ( V_118 )
F_54 ( & V_117 ) ;
}
return error ;
}
static void F_55 ( struct V_1 * V_2 , const void * V_33 )
{
const struct V_82 * V_120 = V_33 ;
T_1 V_121 ;
V_121 = F_41 ( V_120 -> V_121 ) ;
V_121 &= ~ V_122 ;
V_2 -> V_111 &= V_122 ;
V_2 -> V_111 |= V_121 ;
V_2 -> V_50 = F_41 ( V_120 -> V_123 ) ;
V_2 -> V_52 = F_41 ( V_120 -> V_124 ) ;
V_2 -> V_125 = F_48 ( V_120 -> V_126 ) ;
}
static void F_56 ( struct V_1 * V_2 , void * V_33 )
{
struct V_82 * V_120 = V_33 ;
V_120 -> V_121 = F_57 ( V_2 -> V_111 & ~ V_122 ) ;
V_120 -> V_123 = F_57 ( V_2 -> V_50 ) ;
V_120 -> V_124 = F_57 ( V_2 -> V_52 ) ;
V_120 -> V_127 = F_57 ( 0 ) ;
V_120 -> V_126 = F_58 ( V_2 -> V_125 ) ;
memset ( & V_120 -> V_128 , 0 , sizeof( V_120 -> V_128 ) ) ;
}
int F_59 ( struct V_116 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 -> V_72 ;
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_68 * V_69 = V_2 -> V_70 ;
unsigned int V_44 = V_2 -> V_45 ;
struct V_6 * V_7 ;
unsigned int V_46 , V_131 ;
int error ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
error = F_60 ( V_69 , V_2 -> V_22 + V_46 , 0 , & V_7 -> V_48 ) ;
if ( error )
goto V_108;
}
for ( V_131 = V_44 ; V_131 -- ; ) {
V_7 = V_2 -> V_47 + V_131 ;
error = F_61 ( V_43 , V_7 -> V_48 ) ;
if ( error )
goto V_108;
if ( F_62 ( V_43 , V_7 -> V_48 , V_131 ? V_132 :
V_133 ) ) {
error = - V_86 ;
goto V_108;
}
}
if ( ! ( V_2 -> V_111 & V_112 ) ) {
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ )
F_63 ( V_134 , & V_2 -> V_47 [ V_46 ] . V_81 ) ;
F_55 ( V_2 , ( V_2 -> V_47 [ 0 ] . V_48 ) -> V_49 ) ;
V_2 -> V_111 |= ( V_112 | V_135 ) ;
V_2 -> V_136 = V_2 -> V_50 ;
}
return 0 ;
V_108:
while ( V_46 -- ) {
V_7 = V_2 -> V_47 + V_46 ;
F_64 ( V_7 -> V_48 ) ;
V_7 -> V_48 = NULL ;
F_65 ( V_43 , ! V_7 -> V_67 ) ;
}
return error ;
}
void F_66 ( struct V_116 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 -> V_72 ;
int V_46 , V_44 = V_2 -> V_45 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
F_64 ( V_7 -> V_48 ) ;
V_7 -> V_48 = NULL ;
}
}
int F_67 ( struct V_42 * V_43 , T_2 V_5 ,
struct V_137 * V_138 ,
const struct V_6 * V_7 , unsigned V_139 , T_2 * V_140 )
{
struct V_141 * V_142 = V_43 -> V_143 ;
struct V_144 * V_145 = V_142 -> V_146 ;
const unsigned int V_147 = V_43 -> V_83 . V_84 /
F_68 ( V_142 -> V_146 ) ;
T_2 V_56 ;
T_6 V_148 = 0 ;
T_6 V_149 = 0 ;
int V_150 ;
unsigned int V_46 ;
T_1 V_151 = 0 ;
T_4 V_152 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_15 ; V_46 ++ ) {
const T_4 * V_153 = V_7 -> V_67 ? V_7 -> V_67 : V_7 -> V_48 -> V_49 ;
V_153 += V_7 -> V_24 ;
V_153 += V_46 ;
if ( V_138 ) {
const T_4 * V_154 = V_138 -> V_49 + V_7 -> V_24 + V_46 ;
V_152 = ~ ( * V_154 | ( * V_154 >> 1 ) ) & ( * V_153 | ( * V_153 >> 1 ) ) ;
} else {
V_152 = ~ ( * V_153 | ( * V_153 >> 1 ) ) ;
}
V_152 &= 0x55 ;
if ( V_152 == 0 )
continue;
V_56 = V_5 + ( ( V_7 -> V_23 + V_46 ) * V_17 ) ;
V_56 *= V_147 ;
while( V_152 ) {
if ( V_152 & 1 ) {
if ( V_149 == 0 )
goto V_155;
if ( ( V_148 + V_149 ) != V_56 ) {
if ( V_149 >= V_139 ) {
V_150 = F_69 ( V_145 ,
V_148 , V_149 ,
V_79 , 0 ) ;
if ( V_150 )
goto V_108;
V_151 += V_149 ;
}
V_149 = 0 ;
V_155:
V_148 = V_56 ;
}
V_149 += V_147 ;
}
V_152 >>= 2 ;
V_56 += V_147 ;
}
}
if ( V_149 >= V_139 ) {
V_150 = F_69 ( V_145 , V_148 , V_149 , V_79 , 0 ) ;
if ( V_150 )
goto V_108;
V_151 += V_149 ;
}
if ( V_140 )
* V_140 = V_151 ;
return 0 ;
V_108:
if ( V_43 -> V_156 . V_157 )
F_70 ( V_43 , L_14 , V_150 ) ;
V_43 -> V_156 . V_157 = 0 ;
return - V_86 ;
}
int F_71 ( struct V_158 * V_159 , void T_7 * V_160 )
{
struct V_88 * V_88 = V_159 -> V_161 -> V_162 ;
struct V_42 * V_43 = F_46 ( V_88 ) ;
struct V_163 * V_164 = F_72 ( V_43 -> V_143 -> V_146 ) ;
struct V_137 * V_138 ;
struct V_1 * V_2 ;
struct V_1 * V_165 ;
struct V_116 V_129 ;
struct V_166 V_167 ;
int V_168 = 0 ;
T_2 V_169 ;
T_2 V_151 = 0 ;
unsigned int V_46 ;
if ( ! F_73 ( V_170 ) )
return - V_171 ;
if ( ! F_74 ( V_164 ) )
return - V_172 ;
if ( V_160 == NULL ) {
V_167 . V_148 = 0 ;
V_167 . V_34 = V_173 ;
V_167 . V_139 = 0 ;
} else if ( F_75 ( & V_167 , V_160 , sizeof( V_167 ) ) )
return - V_174 ;
V_168 = F_51 ( V_43 ) ;
if ( V_168 )
return V_168 ;
V_2 = F_18 ( V_43 , V_167 . V_148 , 0 ) ;
V_165 = F_18 ( V_43 , V_167 . V_148 + V_167 . V_34 , 0 ) ;
while ( 1 ) {
V_168 = F_53 ( V_2 -> V_70 , V_175 , 0 , & V_129 ) ;
if ( V_168 )
goto V_176;
if ( ! ( V_2 -> V_111 & V_177 ) ) {
for ( V_46 = 0 ; V_46 < V_2 -> V_45 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
V_168 = F_67 ( V_43 , V_2 -> V_54 , NULL , V_7 , V_167 . V_139 , & V_169 ) ;
if ( V_168 ) {
F_54 ( & V_129 ) ;
goto V_176;
}
V_151 += V_169 ;
}
V_168 = F_76 ( V_43 , V_178 , 0 ) ;
if ( V_168 == 0 ) {
V_138 = V_2 -> V_47 [ 0 ] . V_48 ;
V_2 -> V_111 |= V_177 ;
F_77 ( V_2 -> V_70 , V_138 , 1 ) ;
F_56 ( V_2 , V_138 -> V_49 ) ;
F_78 ( V_43 ) ;
}
}
F_54 ( & V_129 ) ;
if ( V_2 == V_165 )
break;
V_2 = F_24 ( V_2 ) ;
}
V_176:
V_167 . V_34 = V_151 << 9 ;
if ( V_160 && F_79 ( V_160 , & V_167 , sizeof( V_167 ) ) )
return - V_174 ;
return V_168 ;
}
struct V_179 * F_80 ( struct V_90 * V_91 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
int error ;
F_2 ( V_91 -> V_180 != NULL ) ;
V_91 -> V_180 = F_81 ( sizeof( struct V_179 ) , V_79 ) ;
error = F_51 ( V_43 ) ;
if ( error )
F_70 ( V_43 , L_15 , error ) ;
return V_91 -> V_180 ;
}
static struct V_181 * F_82 ( struct V_90 * V_91 )
{
F_2 ( V_91 -> V_182 != NULL ) ;
V_91 -> V_182 = F_81 ( sizeof( struct V_181 ) , V_79 ) ;
return V_91 -> V_182 ;
}
static int F_83 ( const struct V_1 * V_2 , const struct V_90 * V_91 )
{
const struct V_181 * V_183 = V_91 -> V_182 ;
if ( V_2 -> V_111 & ( V_184 | V_185 ) )
return 0 ;
if ( V_2 -> V_136 >= V_183 -> V_186 )
return 1 ;
return 0 ;
}
static inline T_1 F_84 ( struct V_6 * V_7 , T_1 V_56 )
{
return ( V_7 -> V_23 * V_17 ) + V_56 ;
}
static void F_85 ( struct V_1 * V_2 , T_2 * V_187 , T_2 V_188 )
{
T_1 V_35 = 0 , V_8 ;
T_2 V_189 ;
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_68 * V_69 ;
struct V_90 * V_91 ;
int error ;
int V_190 = 0 ;
struct V_6 * V_7 ;
while ( V_35 < V_2 -> V_51 ) {
F_86 ( & V_43 -> V_191 ) ;
V_8 = F_87 ( V_2 , V_35 , V_192 , & V_7 ) ;
F_88 ( & V_43 -> V_191 ) ;
if ( V_8 == V_37 )
break;
V_8 = F_84 ( V_7 , V_8 ) ;
V_189 = V_8 + V_2 -> V_54 ;
V_35 = F_89 ( V_8 + 1 , V_35 + 1 ) ;
if ( * V_187 != V_193 && V_189 <= * V_187 )
continue;
if ( V_189 == V_188 )
continue;
* V_187 = V_189 ;
error = F_49 ( V_43 , V_189 , & V_194 , V_110 , & V_69 ) ;
if ( error )
continue;
V_91 = V_69 -> V_72 ;
if ( V_91 || F_90 ( V_195 , & V_69 -> V_196 ) == 0 )
F_31 ( V_69 ) ;
else
V_190 ++ ;
if ( V_190 > V_197 )
return;
}
V_2 -> V_111 &= ~ V_135 ;
return;
}
static int F_91 ( struct V_90 * V_91 , T_2 * V_187 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
struct V_1 * V_2 , * V_198 = NULL ;
struct V_181 * V_183 = V_91 -> V_182 ;
int error , V_199 , V_200 = V_201 ;
int V_202 = 0 ;
if ( V_91 -> V_203 && F_17 ( V_91 -> V_203 , V_91 -> V_204 ) )
V_2 = V_198 = V_91 -> V_203 ;
else
V_2 = V_198 = F_18 ( V_43 , V_91 -> V_204 , 1 ) ;
if ( V_2 == NULL )
return - V_205 ;
while ( V_202 < 3 ) {
V_199 = 0 ;
if ( F_52 ( V_2 -> V_70 ) ) {
V_199 = 1 ;
error = 0 ;
} else {
error = F_53 ( V_2 -> V_70 , V_175 ,
V_200 , & V_183 -> V_206 ) ;
}
switch ( error ) {
case 0 :
if ( F_83 ( V_2 , V_91 ) ) {
V_91 -> V_203 = V_2 ;
return 0 ;
}
if ( V_2 -> V_111 & V_135 )
F_85 ( V_2 , V_187 , V_91 -> V_207 ) ;
if ( ! V_199 )
F_54 ( & V_183 -> V_206 ) ;
case V_208 :
V_2 = F_24 ( V_2 ) ;
if ( V_2 == V_198 ) {
V_200 = 0 ;
V_202 ++ ;
}
break;
default:
return error ;
}
}
return - V_209 ;
}
static void F_92 ( struct V_90 * V_91 )
{
F_2 ( V_91 -> V_182 == NULL ) ;
F_27 ( V_91 -> V_182 ) ;
V_91 -> V_182 = NULL ;
}
int F_93 ( struct V_90 * V_91 , T_1 V_210 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
struct V_181 * V_183 ;
int error = 0 ;
T_2 V_187 = V_193 ;
int V_211 = 0 ;
V_183 = F_82 ( V_91 ) ;
if ( ! V_183 )
return - V_80 ;
V_183 -> V_186 = V_210 ;
if ( F_65 ( V_43 , V_210 ) ) {
error = - V_78 ;
goto V_176;
}
do {
error = F_91 ( V_91 , & V_187 ) ;
if ( error != - V_209 )
break;
if ( V_91 == F_37 ( V_43 -> V_89 ) && ! V_43 -> V_114 ) {
error = F_50 ( V_91 ) ;
if ( error )
break;
continue;
}
F_94 ( V_43 , NULL ) ;
} while ( V_211 ++ < 3 );
V_176:
if ( error )
F_92 ( V_91 ) ;
return error ;
}
void F_95 ( struct V_90 * V_91 )
{
struct V_181 * V_183 = V_91 -> V_182 ;
if ( V_183 -> V_206 . V_130 )
F_54 ( & V_183 -> V_206 ) ;
F_92 ( V_91 ) ;
}
static unsigned char F_96 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_6 * V_7 = NULL ;
T_1 V_44 , V_212 , V_213 ;
unsigned int V_33 ;
unsigned char type ;
V_44 = V_2 -> V_45 ;
V_212 = V_8 - V_2 -> V_54 ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_212 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_213 = V_212 - V_7 -> V_23 * V_17 ;
type = F_7 ( V_2 , V_7 -> V_48 -> V_49 + V_7 -> V_24 ,
V_7 -> V_15 , V_213 ) ;
return type ;
}
static T_1 F_87 ( struct V_1 * V_2 , T_1 V_35 ,
unsigned char V_30 ,
struct V_6 * * V_214 )
{
struct V_6 * V_7 = NULL ;
const T_1 V_44 = V_2 -> V_45 ;
T_1 V_56 = V_37 ;
unsigned int V_33 , V_46 ;
const T_4 * V_25 = NULL ;
* V_214 = NULL ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_35 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 ) {
V_35 -= V_7 -> V_23 * V_17 ;
goto V_215;
}
}
V_33 = 0 ;
V_35 = 0 ;
V_215:
for ( V_46 = 0 ; V_46 <= V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( F_97 ( V_134 , & V_7 -> V_81 ) &&
( V_30 == V_216 ) )
goto V_188;
V_25 = V_7 -> V_48 -> V_49 + V_7 -> V_24 ;
F_98 ( ! F_99 ( V_7 -> V_48 ) ) ;
if ( V_30 != V_192 && V_7 -> V_67 )
V_25 = V_7 -> V_67 + V_7 -> V_24 ;
V_56 = F_11 ( V_25 , V_7 -> V_15 , V_35 , V_30 ) ;
if ( V_56 != V_37 )
break;
if ( ( V_35 == 0 ) && ( V_30 == V_216 ) )
F_100 ( V_134 , & V_7 -> V_81 ) ;
V_188:
V_33 ++ ;
V_33 %= V_44 ;
V_35 = 0 ;
}
if ( V_56 != V_37 )
* V_214 = V_7 ;
return V_56 ;
}
static T_2 F_101 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_56 , bool V_217 , unsigned int * V_59 )
{
const unsigned int V_218 = * V_59 ;
T_1 V_35 ;
const T_4 * V_25 = NULL ;
* V_59 = 0 ;
V_25 = V_7 -> V_48 -> V_49 + V_7 -> V_24 ;
F_77 ( V_2 -> V_70 , V_7 -> V_48 , 1 ) ;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , V_7 -> V_67 , V_7 -> V_24 ,
V_7 , V_56 , V_217 ? V_219 : V_220 ) ;
( * V_59 ) ++ ;
V_35 = V_56 ;
while ( * V_59 < V_218 ) {
V_35 ++ ;
if ( V_35 >= ( V_7 -> V_15 * V_17 ) )
break;
if ( F_7 ( V_2 , V_25 , V_7 -> V_15 , V_35 ) !=
V_216 )
break;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , V_7 -> V_67 , V_7 -> V_24 ,
V_7 , V_35 , V_220 ) ;
( * V_59 ) ++ ;
}
V_56 = F_84 ( V_7 , V_56 ) ;
V_2 -> V_221 = V_56 + * V_59 - 1 ;
return V_2 -> V_54 + V_56 ;
}
static struct V_1 * F_102 ( struct V_42 * V_43 , T_2 V_222 ,
T_1 V_223 , unsigned char V_9 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = NULL ;
T_1 V_44 , V_224 , V_225 ;
unsigned int V_33 ;
V_2 = F_18 ( V_43 , V_222 , 1 ) ;
if ( ! V_2 ) {
if ( F_103 ( V_43 ) )
F_16 ( V_43 , L_16 , ( unsigned long long ) V_222 ) ;
return NULL ;
}
V_44 = V_2 -> V_45 ;
V_224 = V_222 - V_2 -> V_54 ;
while ( V_223 -- ) {
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_224 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_225 = V_224 - V_7 -> V_23 * V_17 ;
V_224 ++ ;
if ( ! V_7 -> V_67 ) {
V_7 -> V_67 = F_104 ( V_7 -> V_48 -> V_226 ,
V_79 | V_227 ) ;
memcpy ( V_7 -> V_67 + V_7 -> V_24 ,
V_7 -> V_48 -> V_49 + V_7 -> V_24 ,
V_7 -> V_15 ) ;
}
F_77 ( V_2 -> V_70 , V_7 -> V_48 , 1 ) ;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , NULL , V_7 -> V_24 ,
V_7 , V_225 , V_9 ) ;
}
return V_2 ;
}
int F_105 ( struct V_228 * V_229 , const struct V_68 * V_69 )
{
const struct V_1 * V_2 = V_69 -> V_72 ;
if ( V_2 == NULL )
return 0 ;
F_106 ( V_229 , L_17 ,
( unsigned long long ) V_2 -> V_22 , V_2 -> V_111 ,
V_2 -> V_50 , V_2 -> V_136 , V_2 -> V_52 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
F_70 ( V_43 , L_18 ,
( unsigned long long ) V_2 -> V_22 ) ;
F_70 ( V_43 , L_19 ) ;
F_105 ( NULL , V_2 -> V_70 ) ;
V_2 -> V_111 |= V_185 ;
}
int F_108 ( struct V_90 * V_91 , T_2 * V_230 , unsigned int * V_231 ,
bool V_217 , T_2 * V_232 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
struct V_137 * V_233 ;
struct V_1 * V_2 ;
unsigned int V_234 ;
T_1 V_35 , V_56 ;
T_2 V_8 ;
int error ;
struct V_6 * V_7 ;
if ( V_91 -> V_182 == NULL )
return - V_235 ;
V_2 = V_91 -> V_203 ;
if ( ! V_217 && F_17 ( V_2 , V_91 -> V_204 ) )
V_35 = V_91 -> V_204 - V_2 -> V_54 ;
else
V_35 = V_2 -> V_221 ;
V_56 = F_87 ( V_2 , V_35 , V_216 , & V_7 ) ;
if ( V_56 == V_37 )
goto V_236;
V_8 = F_101 ( V_2 , V_7 , V_56 , V_217 , V_231 ) ;
V_234 = * V_231 ;
if ( V_217 )
V_234 -- ;
if ( ! V_217 ) {
V_91 -> V_204 = V_8 + V_234 - 1 ;
error = F_109 ( V_91 , & V_233 ) ;
if ( error == 0 ) {
struct V_237 * V_238 =
(struct V_237 * ) V_233 -> V_49 ;
F_77 ( V_91 -> V_115 , V_233 , 1 ) ;
V_238 -> V_239 = V_238 -> V_240 =
F_58 ( V_91 -> V_204 ) ;
F_64 ( V_233 ) ;
}
}
if ( V_2 -> V_50 < * V_231 )
goto V_236;
V_2 -> V_50 -= * V_231 ;
if ( V_217 ) {
V_2 -> V_52 ++ ;
* V_232 = V_2 -> V_125 ++ ;
if ( * V_232 == 0 )
* V_232 = V_2 -> V_125 ++ ;
}
F_77 ( V_2 -> V_70 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_56 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_110 ( V_43 , 0 , - ( V_241 ) * V_231 , V_217 ? 1 : 0 ) ;
if ( V_217 )
F_111 ( V_43 , V_8 , 1 ) ;
if ( V_234 )
F_112 ( V_91 , V_234 , V_91 -> V_103 . V_242 ,
V_91 -> V_103 . V_243 ) ;
V_2 -> V_136 -= * V_231 ;
F_113 ( V_91 , V_8 , * V_231 ,
V_217 ? V_219 : V_220 ) ;
* V_230 = V_8 ;
return 0 ;
V_236:
F_107 ( V_2 ) ;
return - V_86 ;
}
void F_114 ( struct V_90 * V_91 , T_2 V_222 , T_1 V_223 , int V_244 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
struct V_1 * V_2 ;
V_2 = F_102 ( V_43 , V_222 , V_223 , V_216 ) ;
if ( ! V_2 )
return;
F_113 ( V_91 , V_222 , V_223 , V_216 ) ;
V_2 -> V_50 += V_223 ;
V_2 -> V_111 &= ~ V_177 ;
F_77 ( V_2 -> V_70 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_56 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
if ( V_244 || V_91 -> V_245 )
F_115 ( V_91 , V_222 , V_223 ) ;
}
void F_116 ( struct V_90 * V_91 , T_2 V_222 , T_1 V_223 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
F_114 ( V_91 , V_222 , V_223 , 1 ) ;
F_110 ( V_43 , 0 , + V_223 , 0 ) ;
F_112 ( V_91 , - ( V_241 ) V_223 , V_91 -> V_103 . V_242 , V_91 -> V_103 . V_243 ) ;
}
void F_117 ( struct V_88 * V_88 )
{
struct V_90 * V_91 = F_37 ( V_88 ) ;
struct V_42 * V_43 = F_46 ( V_88 ) ;
struct V_1 * V_2 ;
T_2 V_246 = V_91 -> V_207 ;
V_2 = F_102 ( V_43 , V_246 , 1 , V_192 ) ;
if ( ! V_2 )
return;
F_113 ( V_91 , V_246 , 1 , V_192 ) ;
F_77 ( V_2 -> V_70 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_56 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
}
static void F_118 ( struct V_1 * V_2 , T_2 V_246 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_1 * V_247 ;
V_247 = F_102 ( V_43 , V_246 , 1 , V_216 ) ;
if ( ! V_247 )
return;
F_119 ( V_43 , V_2 == V_247 ) ;
if ( ! V_2 -> V_52 )
F_6 ( V_2 ) ;
V_2 -> V_52 -- ;
V_2 -> V_50 ++ ;
F_77 ( V_2 -> V_70 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_56 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_110 ( V_43 , 0 , + 1 , - 1 ) ;
}
void F_120 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
F_118 ( V_2 , V_91 -> V_207 ) ;
F_113 ( V_91 , V_91 -> V_207 , 1 , V_216 ) ;
F_112 ( V_91 , - 1 , V_91 -> V_103 . V_242 , V_91 -> V_103 . V_243 ) ;
F_115 ( V_91 , V_91 -> V_207 , 1 ) ;
}
int F_121 ( struct V_42 * V_43 , T_2 V_189 , unsigned int type )
{
struct V_1 * V_2 ;
struct V_116 V_248 ;
int error = - V_78 ;
V_2 = F_18 ( V_43 , V_189 , 1 ) ;
if ( ! V_2 )
goto V_108;
error = F_53 ( V_2 -> V_70 , V_119 , 0 , & V_248 ) ;
if ( error )
goto V_108;
if ( F_96 ( V_2 , V_189 ) != type )
error = - V_249 ;
F_54 ( & V_248 ) ;
V_108:
return error ;
}
void F_122 ( struct V_90 * V_91 , struct V_250 * V_251 ,
T_2 V_8 )
{
struct V_42 * V_43 = F_46 ( & V_91 -> V_103 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_31 ;
unsigned int V_252 ;
unsigned int V_46 ;
if ( F_65 ( V_43 , ! V_251 -> V_253 ) )
return;
if ( V_91 -> V_203 && F_17 ( V_91 -> V_203 , V_8 ) )
V_2 = V_91 -> V_203 ;
else
V_2 = F_18 ( V_43 , V_8 , 1 ) ;
if ( ! V_2 ) {
F_16 ( V_43 , L_20 , ( unsigned long long ) V_8 ) ;
return;
}
V_91 -> V_203 = V_2 ;
for ( V_46 = 0 ; V_46 < V_251 -> V_254 ; V_46 ++ )
if ( V_251 -> V_255 [ V_46 ] == V_2 )
return;
if ( V_251 -> V_254 == V_251 -> V_256 ) {
V_252 = V_251 -> V_256 + 10 ;
V_31 = F_35 ( V_252 , sizeof( struct V_1 * ) ,
V_79 | V_227 ) ;
if ( V_251 -> V_255 ) {
memcpy ( V_31 , V_251 -> V_255 ,
V_251 -> V_256 * sizeof( struct V_1 * ) ) ;
F_27 ( V_251 -> V_255 ) ;
}
V_251 -> V_256 = V_252 ;
V_251 -> V_255 = V_31 ;
}
V_251 -> V_255 [ V_251 -> V_254 ++ ] = V_2 ;
}
void F_123 ( struct V_250 * V_251 , unsigned int V_30 )
{
unsigned int V_46 ;
V_251 -> V_253 = F_35 ( V_251 -> V_254 , sizeof( struct V_116 ) ,
V_79 | V_227 ) ;
for ( V_46 = 0 ; V_46 < V_251 -> V_254 ; V_46 ++ )
F_124 ( V_251 -> V_255 [ V_46 ] -> V_70 ,
V_30 , 0 ,
& V_251 -> V_253 [ V_46 ] ) ;
}
void F_125 ( struct V_250 * V_251 )
{
unsigned int V_46 ;
F_27 ( V_251 -> V_255 ) ;
if ( V_251 -> V_253 ) {
for ( V_46 = 0 ; V_46 < V_251 -> V_254 ; V_46 ++ )
F_126 ( & V_251 -> V_253 [ V_46 ] ) ;
F_27 ( V_251 -> V_253 ) ;
}
}
