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
struct V_1 * F_18 ( struct V_42 * V_43 , T_2 V_56 )
{
struct V_1 * V_2 ;
F_19 ( & V_43 -> V_57 ) ;
F_20 (rgd, &sdp->sd_rindex_mru_list, rd_list_mru) {
if ( F_17 ( V_2 , V_56 ) ) {
F_21 ( & V_2 -> V_58 , & V_43 -> V_59 ) ;
F_22 ( & V_43 -> V_57 ) ;
return V_2 ;
}
}
F_22 ( & V_43 -> V_57 ) ;
return NULL ;
}
struct V_1 * F_23 ( struct V_42 * V_43 )
{
F_8 ( V_43 , ! F_24 ( & V_43 -> V_60 ) ) ;
return F_25 ( V_43 -> V_60 . V_61 , struct V_1 , V_62 ) ;
}
struct V_1 * F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_62 . V_61 == & V_2 -> V_27 -> V_60 )
return NULL ;
return F_25 ( V_2 -> V_62 . V_61 , struct V_1 , V_62 ) ;
}
static void F_27 ( struct V_42 * V_43 )
{
struct V_63 * V_64 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
F_19 ( & V_43 -> V_57 ) ;
V_43 -> V_67 = NULL ;
F_22 ( & V_43 -> V_57 ) ;
V_64 = & V_43 -> V_60 ;
while ( ! F_24 ( V_64 ) ) {
V_2 = F_25 ( V_64 -> V_61 , struct V_1 , V_62 ) ;
V_66 = V_2 -> V_68 ;
F_28 ( & V_2 -> V_62 ) ;
F_28 ( & V_2 -> V_58 ) ;
if ( V_66 ) {
V_66 -> V_69 = NULL ;
F_29 ( V_66 ) ;
F_30 ( V_66 ) ;
}
F_31 ( V_2 -> V_47 ) ;
F_32 ( V_70 , V_2 ) ;
}
}
void F_33 ( struct V_42 * V_43 )
{
F_34 ( & V_43 -> V_71 ) ;
F_27 ( V_43 ) ;
F_35 ( & V_43 -> V_71 ) ;
}
static void F_36 ( const struct V_1 * V_2 )
{
F_4 ( V_72 L_8 , ( unsigned long long ) V_2 -> V_22 ) ;
F_4 ( V_72 L_9 , V_2 -> V_45 ) ;
F_4 ( V_72 L_10 , ( unsigned long long ) V_2 -> V_54 ) ;
F_4 ( V_72 L_11 , V_2 -> V_51 ) ;
F_4 ( V_72 L_12 , V_2 -> V_73 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_6 * V_7 ;
T_1 V_44 = V_2 -> V_45 ;
T_1 V_74 , V_75 ;
int V_46 ;
if ( ! V_44 )
return - V_76 ;
V_2 -> V_47 = F_38 ( V_44 , sizeof( struct V_6 ) , V_77 ) ;
if ( ! V_2 -> V_47 )
return - V_78 ;
V_74 = V_2 -> V_73 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
V_7 -> V_79 = 0 ;
if ( V_44 == 1 ) {
V_75 = V_74 ;
V_7 -> V_24 = sizeof( struct V_80 ) ;
V_7 -> V_23 = 0 ;
V_7 -> V_15 = V_75 ;
} else if ( V_46 == 0 ) {
V_75 = V_43 -> V_81 . V_82 - sizeof( struct V_80 ) ;
V_7 -> V_24 = sizeof( struct V_80 ) ;
V_7 -> V_23 = 0 ;
V_7 -> V_15 = V_75 ;
} else if ( V_46 + 1 == V_44 ) {
V_75 = V_74 ;
V_7 -> V_24 = sizeof( struct V_83 ) ;
V_7 -> V_23 = V_2 -> V_73 - V_74 ;
V_7 -> V_15 = V_75 ;
} else {
V_75 = V_43 -> V_81 . V_82 -
sizeof( struct V_83 ) ;
V_7 -> V_24 = sizeof( struct V_83 ) ;
V_7 -> V_23 = V_2 -> V_73 - V_74 ;
V_7 -> V_15 = V_75 ;
}
V_74 -= V_75 ;
}
if ( V_74 ) {
F_6 ( V_2 ) ;
return - V_84 ;
}
V_7 = V_2 -> V_47 + ( V_44 - 1 ) ;
if ( ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 != V_2 -> V_51 ) {
if ( F_6 ( V_2 ) ) {
F_36 ( V_2 ) ;
F_16 ( V_43 , L_13 ,
V_7 -> V_23 , V_7 -> V_15 , V_7 -> V_24 ) ;
}
return - V_84 ;
}
return 0 ;
}
T_2 F_39 ( struct V_42 * V_43 )
{
T_2 V_85 = 0 ;
struct V_86 * V_86 = V_43 -> V_87 ;
struct V_88 * V_89 = F_40 ( V_86 ) ;
char V_33 [ sizeof( struct V_90 ) ] ;
struct V_91 V_92 ;
int error , V_93 ;
F_34 ( & V_43 -> V_71 ) ;
F_41 ( & V_92 , V_86 -> V_94 ) ;
for ( V_93 = 0 ; ; V_93 ++ ) {
T_5 V_95 = V_93 * sizeof( struct V_90 ) ;
if ( V_95 + sizeof( struct V_90 ) > F_42 ( V_86 ) )
break;
error = F_43 ( V_89 , & V_92 , V_33 , & V_95 ,
sizeof( struct V_90 ) ) ;
if ( error != sizeof( struct V_90 ) )
break;
V_85 += F_44 ( ( (struct V_90 * ) V_33 ) -> V_96 ) ;
}
F_35 ( & V_43 -> V_71 ) ;
return V_85 ;
}
static void F_45 ( struct V_1 * V_2 , const void * V_33 )
{
const struct V_90 * V_97 = V_33 ;
V_2 -> V_22 = F_46 ( V_97 -> V_98 ) ;
V_2 -> V_45 = F_44 ( V_97 -> V_99 ) ;
V_2 -> V_54 = F_46 ( V_97 -> V_100 ) ;
V_2 -> V_51 = F_44 ( V_97 -> V_96 ) ;
V_2 -> V_73 = F_44 ( V_97 -> V_101 ) ;
}
static int F_47 ( struct V_88 * V_89 ,
struct V_91 * V_92 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
T_5 V_95 = V_43 -> V_103 * sizeof( struct V_90 ) ;
char V_33 [ sizeof( struct V_90 ) ] ;
int error ;
struct V_1 * V_2 ;
error = F_43 ( V_89 , V_92 , V_33 , & V_95 ,
sizeof( struct V_90 ) ) ;
if ( ! error )
return 0 ;
if ( error != sizeof( struct V_90 ) ) {
if ( error > 0 )
error = - V_84 ;
return error ;
}
V_2 = F_49 ( V_70 , V_77 ) ;
error = - V_78 ;
if ( ! V_2 )
return error ;
F_50 ( & V_2 -> V_104 ) ;
F_51 ( & V_2 -> V_105 , & V_106 ) ;
V_2 -> V_27 = V_43 ;
F_52 ( & V_2 -> V_62 , & V_43 -> V_60 ) ;
F_52 ( & V_2 -> V_58 , & V_43 -> V_59 ) ;
F_45 ( V_2 , V_33 ) ;
error = F_37 ( V_2 ) ;
if ( error )
return error ;
error = F_53 ( V_43 , V_2 -> V_22 ,
& V_107 , V_108 , & V_2 -> V_68 ) ;
if ( error )
return error ;
V_2 -> V_68 -> V_69 = V_2 ;
V_2 -> V_109 &= ~ V_110 ;
return error ;
}
int F_54 ( struct V_88 * V_89 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_86 * V_86 = & V_89 -> V_102 ;
struct V_91 V_92 ;
T_2 V_111 = F_42 ( V_86 ) ;
struct V_1 * V_2 ;
unsigned int V_112 = 0 ;
int error ;
F_55 ( V_111 , sizeof( struct V_90 ) ) ;
F_27 ( V_43 ) ;
F_41 ( & V_92 , V_86 -> V_94 ) ;
for ( V_43 -> V_103 = 0 ; V_43 -> V_103 < V_111 ; V_43 -> V_103 ++ ) {
error = F_47 ( V_89 , & V_92 ) ;
if ( error ) {
F_27 ( V_43 ) ;
return error ;
}
}
F_20 (rgd, &sdp->sd_rindex_list, rd_list)
if ( V_2 -> V_51 > V_112 )
V_112 = V_2 -> V_51 ;
V_43 -> V_113 = V_112 ;
V_43 -> V_114 = 1 ;
return 0 ;
}
int F_56 ( struct V_42 * V_43 , struct V_115 * V_116 )
{
struct V_88 * V_89 = F_40 ( V_43 -> V_87 ) ;
struct V_65 * V_66 = V_89 -> V_117 ;
int error ;
error = F_57 ( V_66 , V_118 , 0 , V_116 ) ;
if ( error )
return error ;
if ( ! V_43 -> V_114 ) {
F_34 ( & V_43 -> V_71 ) ;
if ( ! V_43 -> V_114 ) {
error = F_54 ( V_89 ) ;
if ( error )
F_58 ( V_116 ) ;
}
F_35 ( & V_43 -> V_71 ) ;
}
return error ;
}
static void F_59 ( struct V_1 * V_2 , const void * V_33 )
{
const struct V_80 * V_97 = V_33 ;
T_1 V_119 ;
V_119 = F_44 ( V_97 -> V_119 ) ;
V_119 &= ~ V_120 ;
V_2 -> V_109 &= V_120 ;
V_2 -> V_109 |= V_119 ;
V_2 -> V_50 = F_44 ( V_97 -> V_121 ) ;
V_2 -> V_52 = F_44 ( V_97 -> V_122 ) ;
V_2 -> V_123 = F_46 ( V_97 -> V_124 ) ;
}
static void F_60 ( struct V_1 * V_2 , void * V_33 )
{
struct V_80 * V_97 = V_33 ;
V_97 -> V_119 = F_61 ( V_2 -> V_109 & ~ V_120 ) ;
V_97 -> V_121 = F_61 ( V_2 -> V_50 ) ;
V_97 -> V_122 = F_61 ( V_2 -> V_52 ) ;
V_97 -> V_125 = F_61 ( 0 ) ;
V_97 -> V_124 = F_62 ( V_2 -> V_123 ) ;
memset ( & V_97 -> V_126 , 0 , sizeof( V_97 -> V_126 ) ) ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_65 * V_66 = V_2 -> V_68 ;
unsigned int V_44 = V_2 -> V_45 ;
struct V_6 * V_7 ;
unsigned int V_46 , V_127 ;
int error ;
F_34 ( & V_2 -> V_104 ) ;
F_19 ( & V_43 -> V_57 ) ;
if ( V_2 -> V_128 ) {
V_2 -> V_128 ++ ;
F_22 ( & V_43 -> V_57 ) ;
F_35 ( & V_2 -> V_104 ) ;
return 0 ;
}
F_22 ( & V_43 -> V_57 ) ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
error = F_64 ( V_66 , V_2 -> V_22 + V_46 , 0 , & V_7 -> V_48 ) ;
if ( error )
goto V_129;
}
for ( V_127 = V_44 ; V_127 -- ; ) {
V_7 = V_2 -> V_47 + V_127 ;
error = F_65 ( V_43 , V_7 -> V_48 ) ;
if ( error )
goto V_129;
if ( F_66 ( V_43 , V_7 -> V_48 , V_127 ? V_130 :
V_131 ) ) {
error = - V_84 ;
goto V_129;
}
}
if ( ! ( V_2 -> V_109 & V_110 ) ) {
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ )
F_67 ( V_132 , & V_2 -> V_47 [ V_46 ] . V_79 ) ;
F_59 ( V_2 , ( V_2 -> V_47 [ 0 ] . V_48 ) -> V_49 ) ;
V_2 -> V_109 |= ( V_110 | V_133 ) ;
}
F_19 ( & V_43 -> V_57 ) ;
V_2 -> V_134 = V_2 -> V_50 ;
V_2 -> V_128 ++ ;
F_22 ( & V_43 -> V_57 ) ;
F_35 ( & V_2 -> V_104 ) ;
return 0 ;
V_129:
while ( V_46 -- ) {
V_7 = V_2 -> V_47 + V_46 ;
F_68 ( V_7 -> V_48 ) ;
V_7 -> V_48 = NULL ;
F_69 ( V_43 , ! V_7 -> V_135 ) ;
}
F_35 ( & V_2 -> V_104 ) ;
return error ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
F_19 ( & V_43 -> V_57 ) ;
F_69 ( V_2 -> V_27 , V_2 -> V_128 ) ;
V_2 -> V_128 ++ ;
F_22 ( & V_43 -> V_57 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
int V_46 , V_44 = V_2 -> V_45 ;
F_19 ( & V_43 -> V_57 ) ;
F_69 ( V_2 -> V_27 , V_2 -> V_128 ) ;
if ( -- V_2 -> V_128 ) {
F_22 ( & V_43 -> V_57 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
F_31 ( V_7 -> V_135 ) ;
V_7 -> V_135 = NULL ;
F_68 ( V_7 -> V_48 ) ;
V_7 -> V_48 = NULL ;
}
F_22 ( & V_43 -> V_57 ) ;
}
static void F_72 ( struct V_42 * V_43 , T_2 V_5 ,
const struct V_6 * V_7 )
{
struct V_136 * V_137 = V_43 -> V_138 ;
struct V_139 * V_140 = V_137 -> V_141 ;
const unsigned int V_142 = V_43 -> V_81 . V_82 /
F_73 ( V_137 -> V_141 ) ;
T_2 V_56 ;
T_6 V_143 = 0 ;
T_6 V_144 = 0 ;
int V_145 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_15 ; V_46 ++ ) {
const T_4 * V_146 = V_7 -> V_48 -> V_49 + V_7 -> V_24 + V_46 ;
const T_4 * V_147 = V_7 -> V_135 + V_7 -> V_24 + V_46 ;
T_4 V_148 = ~ ( * V_146 | ( * V_146 >> 1 ) ) & ( * V_147 | ( * V_147 >> 1 ) ) ;
V_148 &= 0x55 ;
if ( V_148 == 0 )
continue;
V_56 = V_5 + ( ( V_7 -> V_23 + V_46 ) * V_17 ) ;
V_56 *= V_142 ;
while( V_148 ) {
if ( V_148 & 1 ) {
if ( V_144 == 0 )
goto V_149;
if ( ( V_143 + V_144 ) != V_56 ) {
V_145 = F_74 ( V_140 , V_143 ,
V_144 , V_77 ,
0 ) ;
if ( V_145 )
goto V_129;
V_144 = 0 ;
V_149:
V_143 = V_56 ;
}
V_144 += V_142 ;
}
V_148 >>= 2 ;
V_56 += V_142 ;
}
}
if ( V_144 ) {
V_145 = F_74 ( V_140 , V_143 , V_144 , V_77 , 0 ) ;
if ( V_145 )
goto V_129;
}
return;
V_129:
F_75 ( V_43 , L_14 , V_145 ) ;
V_43 -> V_150 . V_151 = 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
unsigned int V_44 = V_2 -> V_45 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
struct V_6 * V_7 = V_2 -> V_47 + V_46 ;
if ( ! V_7 -> V_135 )
continue;
if ( V_43 -> V_150 . V_151 )
F_72 ( V_43 , V_2 -> V_54 , V_7 ) ;
F_67 ( V_132 , & V_7 -> V_79 ) ;
memcpy ( V_7 -> V_135 + V_7 -> V_24 ,
V_7 -> V_48 -> V_49 + V_7 -> V_24 , V_7 -> V_15 ) ;
}
F_19 ( & V_43 -> V_57 ) ;
V_2 -> V_134 = V_2 -> V_50 ;
F_22 ( & V_43 -> V_57 ) ;
}
struct V_152 * F_77 ( struct V_88 * V_89 )
{
F_2 ( V_89 -> V_153 != NULL ) ;
V_89 -> V_153 = F_78 ( sizeof( struct V_152 ) , V_77 ) ;
return V_89 -> V_153 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_152 * V_154 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
int V_155 = 0 ;
if ( V_2 -> V_109 & ( V_156 | V_157 ) )
return 0 ;
F_19 ( & V_43 -> V_57 ) ;
if ( V_2 -> V_134 >= V_154 -> V_158 ) {
V_154 -> V_159 = V_2 ;
V_155 = 1 ;
}
F_22 ( & V_43 -> V_57 ) ;
return V_155 ;
}
static void F_80 ( struct V_1 * V_2 , T_2 * V_160 , T_2 V_161 )
{
T_1 V_35 = 0 , V_8 ;
T_2 V_162 ;
struct V_42 * V_43 = V_2 -> V_27 ;
unsigned int V_163 ;
struct V_65 * V_66 ;
struct V_88 * V_89 ;
int error ;
int V_164 = 0 ;
while ( V_35 < V_2 -> V_51 ) {
F_81 ( & V_43 -> V_165 ) ;
V_163 = 1 ;
V_8 = F_82 ( V_2 , V_35 , V_166 ,
V_166 , & V_163 ) ;
F_83 ( & V_43 -> V_165 ) ;
if ( V_8 == V_37 )
break;
V_162 = V_8 + V_2 -> V_54 ;
V_35 = F_84 ( V_8 + 1 , V_35 + 1 ) ;
if ( * V_160 != V_167 && V_162 <= * V_160 )
continue;
if ( V_162 == V_161 )
continue;
* V_160 = V_162 ;
error = F_53 ( V_43 , V_162 , & V_168 , V_108 , & V_66 ) ;
if ( error )
continue;
V_89 = V_66 -> V_69 ;
if ( V_89 || F_85 ( V_169 , & V_66 -> V_170 ) == 0 )
F_30 ( V_66 ) ;
else
V_164 ++ ;
if ( V_164 > V_171 )
return;
}
V_2 -> V_109 &= ~ V_133 ;
return;
}
static struct V_1 * F_86 ( struct V_1 * V_172 )
{
struct V_42 * V_43 = V_172 -> V_27 ;
struct V_63 * V_64 ;
struct V_1 * V_2 ;
F_19 ( & V_43 -> V_57 ) ;
V_64 = & V_43 -> V_59 ;
if ( F_3 ( V_172 -> V_58 . V_61 == V_64 ) ) {
F_22 ( & V_43 -> V_57 ) ;
return NULL ;
}
V_2 = F_25 ( V_172 -> V_58 . V_61 , struct V_1 , V_58 ) ;
F_22 ( & V_43 -> V_57 ) ;
return V_2 ;
}
static struct V_1 * F_87 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
unsigned int V_173 = F_88 ( V_43 ) ;
unsigned int V_174 = 0 , V_46 ;
F_19 ( & V_43 -> V_57 ) ;
V_2 = V_43 -> V_67 ;
if ( ! V_2 ) {
if ( V_43 -> V_103 >= V_173 )
V_174 = V_43 -> V_103 * V_43 -> V_175 -> V_176 / V_173 ;
for ( V_46 = 0 , V_2 = F_23 ( V_43 ) ; V_46 < V_174 ;
V_46 ++ , V_2 = F_26 ( V_2 ) )
;
V_43 -> V_67 = V_2 ;
}
F_22 ( & V_43 -> V_57 ) ;
return V_2 ;
}
static void F_89 ( struct V_42 * V_43 , struct V_1 * V_2 )
{
F_19 ( & V_43 -> V_57 ) ;
V_43 -> V_67 = V_2 ;
F_22 ( & V_43 -> V_57 ) ;
}
static int F_90 ( struct V_88 * V_89 , T_2 * V_160 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_1 * V_2 , * V_177 = NULL ;
struct V_152 * V_154 = V_89 -> V_153 ;
int V_178 = V_179 ;
int V_180 = 0 ;
int V_181 = 0 ;
int error , V_182 ;
V_2 = F_18 ( V_43 , V_89 -> V_183 ) ;
while ( V_2 ) {
V_182 = 0 ;
if ( F_91 ( V_2 -> V_68 ) ) {
V_182 = 1 ;
error = 0 ;
} else {
error = F_57 ( V_2 -> V_68 , V_184 ,
V_179 , & V_154 -> V_185 ) ;
}
switch ( error ) {
case 0 :
if ( F_79 ( V_2 , V_154 ) )
goto V_186;
if ( V_2 -> V_109 & V_133 )
F_80 ( V_2 , V_160 , V_89 -> V_187 ) ;
if ( ! V_182 )
F_58 ( & V_154 -> V_185 ) ;
case V_188 :
V_2 = F_86 ( V_2 ) ;
break;
default:
return error ;
}
}
V_177 = V_2 = F_87 ( V_43 ) ;
for (; ; ) {
V_182 = 0 ;
if ( F_91 ( V_2 -> V_68 ) ) {
V_182 = 1 ;
error = 0 ;
} else {
error = F_57 ( V_2 -> V_68 , V_184 , V_178 ,
& V_154 -> V_185 ) ;
}
switch ( error ) {
case 0 :
if ( F_79 ( V_2 , V_154 ) )
goto V_186;
if ( V_2 -> V_109 & V_133 )
F_80 ( V_2 , V_160 , V_89 -> V_187 ) ;
if ( ! V_182 )
F_58 ( & V_154 -> V_185 ) ;
break;
case V_188 :
V_180 ++ ;
break;
default:
return error ;
}
V_2 = F_26 ( V_2 ) ;
if ( ! V_2 )
V_2 = F_23 ( V_43 ) ;
if ( V_2 == V_177 ) {
if ( ++ V_181 >= 3 )
return - V_189 ;
if ( ! V_180 )
V_181 ++ ;
V_178 = 0 ;
if ( V_181 == 2 )
F_92 ( V_43 , NULL ) ;
}
}
V_186:
if ( V_177 ) {
F_19 ( & V_43 -> V_57 ) ;
F_21 ( & V_2 -> V_58 , & V_43 -> V_59 ) ;
F_22 ( & V_43 -> V_57 ) ;
V_2 = F_26 ( V_2 ) ;
if ( ! V_2 )
V_2 = F_23 ( V_43 ) ;
F_89 ( V_43 , V_2 ) ;
}
return 0 ;
}
int F_93 ( struct V_88 * V_89 , int V_190 ,
char * V_191 , unsigned int line )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_152 * V_154 = V_89 -> V_153 ;
int error = 0 ;
T_2 V_160 = V_167 ;
int V_192 = 0 ;
if ( F_69 ( V_43 , V_154 -> V_158 ) )
return - V_76 ;
if ( V_190 ) {
if ( V_89 != F_40 ( V_43 -> V_87 ) )
error = F_56 ( V_43 , & V_154 -> V_193 ) ;
else if ( ! V_43 -> V_103 )
error = F_54 ( V_89 ) ;
if ( error )
return error ;
}
V_194:
do {
error = F_90 ( V_89 , & V_160 ) ;
if ( error ) {
if ( V_89 == F_40 ( V_43 -> V_87 ) &&
! V_43 -> V_114 ) {
error = F_54 ( V_89 ) ;
if ( error )
return error ;
goto V_194;
}
F_92 ( V_43 , NULL ) ;
}
} while ( error && V_192 ++ < 3 );
if ( error ) {
if ( V_190 && V_89 != F_40 ( V_43 -> V_87 ) )
F_58 ( & V_154 -> V_193 ) ;
return error ;
}
V_154 -> V_195 = V_191 ;
V_154 -> V_196 = line ;
return 0 ;
}
void F_94 ( struct V_88 * V_89 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_152 * V_154 = V_89 -> V_153 ;
if ( F_69 ( V_43 , V_154 -> V_197 <= V_154 -> V_158 ) == - 1 )
F_75 ( V_43 , L_15
L_16 ,
V_154 -> V_197 , V_154 -> V_158 , V_154 -> V_195 ,
V_154 -> V_196 ) ;
V_154 -> V_159 = NULL ;
if ( V_154 -> V_185 . V_198 )
F_58 ( & V_154 -> V_185 ) ;
if ( V_89 != F_40 ( V_43 -> V_87 ) && V_154 -> V_193 . V_198 )
F_58 ( & V_154 -> V_193 ) ;
}
static unsigned char F_95 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_6 * V_7 = NULL ;
T_1 V_44 , V_199 , V_200 ;
unsigned int V_33 ;
unsigned char type ;
V_44 = V_2 -> V_45 ;
V_199 = V_8 - V_2 -> V_54 ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_199 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_200 = V_199 - V_7 -> V_23 * V_17 ;
type = F_7 ( V_2 , V_7 -> V_48 -> V_49 + V_7 -> V_24 ,
V_7 -> V_15 , V_200 ) ;
return type ;
}
static T_1 F_82 ( struct V_1 * V_2 , T_1 V_35 ,
unsigned char V_201 , unsigned char V_9 ,
unsigned int * V_163 )
{
struct V_6 * V_7 = NULL ;
const T_1 V_44 = V_2 -> V_45 ;
T_1 V_56 = V_37 ;
unsigned int V_33 , V_46 ;
const unsigned int V_202 = * V_163 ;
const T_4 * V_25 = NULL ;
* V_163 = 0 ;
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_35 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 ) {
V_35 -= V_7 -> V_23 * V_17 ;
goto V_203;
}
}
V_33 = 0 ;
V_35 = 0 ;
V_203:
for ( V_46 = 0 ; V_46 <= V_44 ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( F_96 ( V_132 , & V_7 -> V_79 ) &&
( V_201 == V_204 ) )
goto V_161;
V_25 = V_7 -> V_48 -> V_49 + V_7 -> V_24 ;
if ( V_201 != V_166 && V_7 -> V_135 )
V_25 = V_7 -> V_135 + V_7 -> V_24 ;
V_56 = F_11 ( V_25 , V_7 -> V_15 , V_35 , V_201 ) ;
if ( V_56 != V_37 )
break;
if ( ( V_35 == 0 ) && ( V_201 == V_204 ) )
F_97 ( V_132 , & V_7 -> V_79 ) ;
V_161:
V_33 ++ ;
V_33 %= V_44 ;
V_35 = 0 ;
}
if ( V_56 == V_37 )
return V_56 ;
* V_163 = 1 ;
if ( V_201 == V_9 )
goto V_186;
F_98 ( V_2 -> V_68 , V_7 -> V_48 , 1 ) ;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , V_7 -> V_135 , V_7 -> V_24 ,
V_7 , V_56 , V_9 ) ;
V_35 = V_56 ;
while ( * V_163 < V_202 ) {
V_35 ++ ;
if ( V_35 >= ( V_7 -> V_15 * V_17 ) )
break;
if ( F_7 ( V_2 , V_25 , V_7 -> V_15 , V_35 ) !=
V_204 )
break;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , V_7 -> V_135 , V_7 -> V_24 ,
V_7 , V_35 , V_9 ) ;
( * V_163 ) ++ ;
}
V_186:
return ( V_7 -> V_23 * V_17 ) + V_56 ;
}
static struct V_1 * F_99 ( struct V_42 * V_43 , T_2 V_205 ,
T_1 V_206 , unsigned char V_9 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = NULL ;
T_1 V_44 , V_207 , V_208 ;
unsigned int V_33 ;
V_2 = F_18 ( V_43 , V_205 ) ;
if ( ! V_2 ) {
if ( F_100 ( V_43 ) )
F_16 ( V_43 , L_17 , ( unsigned long long ) V_205 ) ;
return NULL ;
}
V_44 = V_2 -> V_45 ;
V_207 = V_205 - V_2 -> V_54 ;
while ( V_206 -- ) {
for ( V_33 = 0 ; V_33 < V_44 ; V_33 ++ ) {
V_7 = V_2 -> V_47 + V_33 ;
if ( V_207 < ( V_7 -> V_23 + V_7 -> V_15 ) * V_17 )
break;
}
F_8 ( V_2 -> V_27 , V_33 < V_44 ) ;
V_208 = V_207 - V_7 -> V_23 * V_17 ;
V_207 ++ ;
if ( ! V_7 -> V_135 ) {
V_7 -> V_135 = F_101 ( V_7 -> V_48 -> V_209 ,
V_77 | V_210 ) ;
memcpy ( V_7 -> V_135 + V_7 -> V_24 ,
V_7 -> V_48 -> V_49 + V_7 -> V_24 ,
V_7 -> V_15 ) ;
}
F_98 ( V_2 -> V_68 , V_7 -> V_48 , 1 ) ;
F_1 ( V_2 , V_7 -> V_48 -> V_49 , NULL , V_7 -> V_24 ,
V_7 , V_208 , V_9 ) ;
}
return V_2 ;
}
int F_102 ( struct V_211 * V_212 , const struct V_65 * V_66 )
{
const struct V_1 * V_2 = V_66 -> V_69 ;
if ( V_2 == NULL )
return 0 ;
F_103 ( V_212 , L_18 ,
( unsigned long long ) V_2 -> V_22 , V_2 -> V_109 ,
V_2 -> V_50 , V_2 -> V_134 , V_2 -> V_52 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
F_75 ( V_43 , L_19 ,
( unsigned long long ) V_2 -> V_22 ) ;
F_75 ( V_43 , L_20 ) ;
F_102 ( NULL , V_2 -> V_68 ) ;
V_2 -> V_109 |= V_157 ;
}
int F_105 ( struct V_88 * V_89 , T_2 * V_213 , unsigned int * V_163 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_214 * V_215 ;
struct V_152 * V_154 = V_89 -> V_153 ;
struct V_1 * V_2 ;
T_1 V_35 , V_56 ;
T_2 V_8 ;
int error ;
if ( V_154 == NULL )
return - V_216 ;
V_2 = V_154 -> V_159 ;
if ( F_17 ( V_2 , V_89 -> V_183 ) )
V_35 = V_89 -> V_183 - V_2 -> V_54 ;
else
V_35 = V_2 -> V_217 ;
V_56 = F_82 ( V_2 , V_35 , V_204 , V_218 , V_163 ) ;
if ( V_56 == V_37 )
goto V_219;
V_2 -> V_217 = V_56 ;
V_8 = V_2 -> V_54 + V_56 ;
V_89 -> V_183 = V_8 ;
error = F_106 ( V_89 , & V_215 ) ;
if ( error == 0 ) {
struct V_220 * V_221 = (struct V_220 * ) V_215 -> V_49 ;
F_98 ( V_89 -> V_117 , V_215 , 1 ) ;
V_221 -> V_222 = V_221 -> V_223 = F_62 ( V_89 -> V_183 ) ;
F_68 ( V_215 ) ;
}
if ( V_2 -> V_50 < * V_163 )
goto V_219;
V_2 -> V_50 -= * V_163 ;
F_98 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_60 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
V_154 -> V_197 += * V_163 ;
F_107 ( V_43 , 0 , - ( V_224 ) * V_163 , 0 ) ;
F_108 ( V_89 , * V_163 , V_89 -> V_102 . V_225 , V_89 -> V_102 . V_226 ) ;
F_19 ( & V_43 -> V_57 ) ;
V_2 -> V_134 -= * V_163 ;
F_22 ( & V_43 -> V_57 ) ;
F_109 ( V_89 , V_8 , * V_163 , V_218 ) ;
* V_213 = V_8 ;
return 0 ;
V_219:
F_104 ( V_2 ) ;
return - V_84 ;
}
int F_110 ( struct V_88 * V_227 , T_2 * V_213 , T_2 * V_228 )
{
struct V_42 * V_43 = F_48 ( & V_227 -> V_102 ) ;
struct V_152 * V_154 = V_227 -> V_153 ;
struct V_1 * V_2 = V_154 -> V_159 ;
T_1 V_56 ;
T_2 V_8 ;
unsigned int V_163 = 1 ;
V_56 = F_82 ( V_2 , V_2 -> V_217 ,
V_204 , V_229 , & V_163 ) ;
if ( V_56 == V_37 )
goto V_219;
V_2 -> V_217 = V_56 ;
V_8 = V_2 -> V_54 + V_56 ;
if ( V_2 -> V_50 == 0 )
goto V_219;
V_2 -> V_50 -- ;
V_2 -> V_52 ++ ;
* V_228 = V_2 -> V_123 ++ ;
if ( * V_228 == 0 )
* V_228 = V_2 -> V_123 ++ ;
F_98 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_60 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
V_154 -> V_197 ++ ;
F_107 ( V_43 , 0 , - 1 , + 1 ) ;
F_111 ( V_43 , V_8 , 1 ) ;
F_19 ( & V_43 -> V_57 ) ;
V_2 -> V_134 -- ;
F_22 ( & V_43 -> V_57 ) ;
F_109 ( V_227 , V_8 , 1 , V_229 ) ;
* V_213 = V_8 ;
return 0 ;
V_219:
F_104 ( V_2 ) ;
return - V_84 ;
}
void F_112 ( struct V_88 * V_89 , T_2 V_205 , T_1 V_206 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_1 * V_2 ;
V_2 = F_99 ( V_43 , V_205 , V_206 , V_204 ) ;
if ( ! V_2 )
return;
F_109 ( V_89 , V_205 , V_206 , V_204 ) ;
V_2 -> V_50 += V_206 ;
F_98 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_60 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_113 ( V_2 ) ;
if ( V_89 -> V_230 )
F_114 ( V_89 , V_205 , V_206 ) ;
}
void F_115 ( struct V_88 * V_89 , T_2 V_205 , T_1 V_206 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
F_112 ( V_89 , V_205 , V_206 ) ;
F_107 ( V_43 , 0 , + V_206 , 0 ) ;
F_108 ( V_89 , - ( V_224 ) V_206 , V_89 -> V_102 . V_225 , V_89 -> V_102 . V_226 ) ;
}
void F_116 ( struct V_88 * V_89 , T_2 V_205 , T_1 V_206 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
struct V_1 * V_2 ;
V_2 = F_99 ( V_43 , V_205 , V_206 , V_204 ) ;
if ( ! V_2 )
return;
F_109 ( V_89 , V_205 , V_206 , V_204 ) ;
V_2 -> V_50 += V_206 ;
F_98 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_60 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_113 ( V_2 ) ;
F_114 ( V_89 , V_205 , V_206 ) ;
}
void F_117 ( struct V_88 * V_89 , T_2 V_205 , T_1 V_206 )
{
struct V_42 * V_43 = F_48 ( & V_89 -> V_102 ) ;
F_116 ( V_89 , V_205 , V_206 ) ;
F_107 ( V_43 , 0 , + V_206 , 0 ) ;
F_108 ( V_89 , - ( V_224 ) V_206 , V_89 -> V_102 . V_225 , V_89 -> V_102 . V_226 ) ;
}
void F_118 ( struct V_86 * V_86 )
{
struct V_88 * V_89 = F_40 ( V_86 ) ;
struct V_42 * V_43 = F_48 ( V_86 ) ;
struct V_1 * V_2 ;
T_2 V_231 = V_89 -> V_187 ;
V_2 = F_99 ( V_43 , V_231 , 1 , V_166 ) ;
if ( ! V_2 )
return;
F_109 ( V_89 , V_231 , 1 , V_166 ) ;
F_98 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_60 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_113 ( V_2 ) ;
}
static void F_119 ( struct V_1 * V_2 , T_2 V_231 )
{
struct V_42 * V_43 = V_2 -> V_27 ;
struct V_1 * V_232 ;
V_232 = F_99 ( V_43 , V_231 , 1 , V_204 ) ;
if ( ! V_232 )
return;
F_120 ( V_43 , V_2 == V_232 ) ;
if ( ! V_2 -> V_52 )
F_6 ( V_2 ) ;
V_2 -> V_52 -- ;
V_2 -> V_50 ++ ;
F_98 ( V_2 -> V_68 , V_2 -> V_47 [ 0 ] . V_48 , 1 ) ;
F_60 ( V_2 , V_2 -> V_47 [ 0 ] . V_48 -> V_49 ) ;
F_107 ( V_43 , 0 , + 1 , - 1 ) ;
F_113 ( V_2 ) ;
}
void F_121 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
F_119 ( V_2 , V_89 -> V_187 ) ;
F_109 ( V_89 , V_89 -> V_187 , 1 , V_204 ) ;
F_108 ( V_89 , - 1 , V_89 -> V_102 . V_225 , V_89 -> V_102 . V_226 ) ;
F_114 ( V_89 , V_89 -> V_187 , 1 ) ;
}
int F_122 ( struct V_42 * V_43 , T_2 V_162 , unsigned int type )
{
struct V_1 * V_2 ;
struct V_115 V_116 , V_233 ;
struct V_88 * V_89 = F_40 ( V_43 -> V_87 ) ;
int V_234 = 0 ;
int error ;
if ( ! F_91 ( V_89 -> V_117 ) ) {
error = F_56 ( V_43 , & V_116 ) ;
if ( error )
goto V_129;
V_234 = 1 ;
}
error = - V_76 ;
V_2 = F_18 ( V_43 , V_162 ) ;
if ( ! V_2 )
goto V_235;
error = F_57 ( V_2 -> V_68 , V_118 , 0 , & V_233 ) ;
if ( error )
goto V_235;
if ( F_95 ( V_2 , V_162 ) != type )
error = - V_236 ;
F_58 ( & V_233 ) ;
V_235:
if ( V_234 )
F_58 ( & V_116 ) ;
V_129:
return error ;
}
void F_123 ( struct V_42 * V_43 , struct V_237 * V_238 ,
T_2 V_8 )
{
struct V_1 * V_2 ;
struct V_1 * * V_31 ;
unsigned int V_239 ;
unsigned int V_46 ;
if ( F_69 ( V_43 , ! V_238 -> V_240 ) )
return;
V_2 = F_18 ( V_43 , V_8 ) ;
if ( ! V_2 ) {
if ( F_100 ( V_43 ) )
F_16 ( V_43 , L_17 , ( unsigned long long ) V_8 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_238 -> V_241 ; V_46 ++ )
if ( V_238 -> V_242 [ V_46 ] == V_2 )
return;
if ( V_238 -> V_241 == V_238 -> V_243 ) {
V_239 = V_238 -> V_243 + 10 ;
V_31 = F_38 ( V_239 , sizeof( struct V_1 * ) ,
V_77 | V_210 ) ;
if ( V_238 -> V_242 ) {
memcpy ( V_31 , V_238 -> V_242 ,
V_238 -> V_243 * sizeof( struct V_1 * ) ) ;
F_31 ( V_238 -> V_242 ) ;
}
V_238 -> V_243 = V_239 ;
V_238 -> V_242 = V_31 ;
}
V_238 -> V_242 [ V_238 -> V_241 ++ ] = V_2 ;
}
void F_124 ( struct V_237 * V_238 , unsigned int V_30 )
{
unsigned int V_46 ;
V_238 -> V_240 = F_38 ( V_238 -> V_241 , sizeof( struct V_115 ) ,
V_77 | V_210 ) ;
for ( V_46 = 0 ; V_46 < V_238 -> V_241 ; V_46 ++ )
F_125 ( V_238 -> V_242 [ V_46 ] -> V_68 ,
V_30 , 0 ,
& V_238 -> V_240 [ V_46 ] ) ;
}
void F_126 ( struct V_237 * V_238 )
{
unsigned int V_46 ;
F_31 ( V_238 -> V_242 ) ;
if ( V_238 -> V_240 ) {
for ( V_46 = 0 ; V_46 < V_238 -> V_241 ; V_46 ++ )
F_127 ( & V_238 -> V_240 [ V_46 ] ) ;
F_31 ( V_238 -> V_240 ) ;
}
}
