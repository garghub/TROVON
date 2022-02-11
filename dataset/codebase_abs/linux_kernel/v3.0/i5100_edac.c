static inline T_1 F_1 ( T_1 V_1 )
{
return V_1 >> 7 & 1 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return V_1 >> 5 & 1 ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return V_1 >> 4 & 1 ;
}
static inline T_2 F_4 ( T_2 V_2 )
{
return V_2 >> 15 & 1 ;
}
static inline T_2 F_5 ( T_2 V_2 )
{
return V_2 >> 13 & 1 ;
}
static inline T_2 F_6 ( T_2 V_2 )
{
return V_2 >> 12 & 1 ;
}
static inline T_2 F_7 ( T_2 V_2 )
{
return V_2 & ( ( 1 << 8 ) - 1 ) ;
}
static inline T_1 F_8 ( T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 )
{
return ( ( V_3 & ( ( 1 << 4 ) - 1 ) ) << 28 ) |
( ( V_4 & 1 ) << 27 ) |
( ( V_5 & ( ( 1 << 3 ) - 1 ) ) << 24 ) |
( ( V_6 & ( ( 1 << 8 ) - 1 ) ) << 16 ) |
( ( V_7 & ( ( 1 << 8 ) - 1 ) ) << 8 ) |
( V_8 & 1 ) ;
}
static inline T_2 F_9 ( T_2 V_2 )
{
return V_2 >> 12 & ( ( 1 << 4 ) - 1 ) ;
}
static inline T_2 F_10 ( T_2 V_2 )
{
return V_2 >> 4 & ( ( 1 << 12 ) - 1 ) ;
}
static inline T_2 F_11 ( T_2 V_2 )
{
return V_2 >> 1 & 1 ;
}
static inline T_2 F_12 ( T_2 V_2 )
{
return V_2 & 1 ;
}
static inline T_1 F_13 ( T_1 V_2 )
{
return V_2 >> 28 & 1 ;
}
static inline T_1 F_14 ( T_1 V_2 )
{
return V_2 & V_9 ;
}
static inline T_1 F_15 ( T_1 V_2 )
{
return F_14 ( V_2 ) ;
}
static inline T_1 F_16 ( T_1 V_2 )
{
return V_2 >> 16 & ( ( 1 << 11 ) - 1 ) ;
}
static inline T_1 F_17 ( T_1 V_2 , T_1 V_10 )
{
return V_2 >> ( 4 * V_10 ) & ( ( 1 << 2 ) - 1 ) ;
}
static inline T_2 F_18 ( T_2 V_2 )
{
return V_2 >> 10 & 1 ;
}
static inline T_2 F_19 ( T_2 V_2 )
{
return V_2 >> 9 & 1 ;
}
static inline T_2 F_20 ( T_2 V_2 )
{
return V_2 >> 8 & 1 ;
}
static inline T_2 F_21 ( T_2 V_2 )
{
return V_2 >> 6 & 1 ;
}
static inline T_2 F_22 ( T_2 V_2 )
{
return V_2 >> 2 & ( ( 1 << 2 ) - 1 ) ;
}
static inline T_2 F_23 ( T_2 V_2 )
{
return V_2 & ( ( 1 << 2 ) - 1 ) ;
}
static inline T_1 F_24 ( T_1 V_2 )
{
return V_2 >> 2 & 1 ;
}
static inline T_1 F_25 ( T_1 V_2 )
{
return V_2 >> 1 & 1 ;
}
static inline T_1 F_26 ( T_1 V_2 )
{
return V_2 & 1 ;
}
static inline T_1 F_27 ( T_1 V_2 )
{
return V_2 >> 15 & ( ( 1 << 5 ) - 1 ) ;
}
static inline T_1 F_28 ( T_1 V_2 )
{
return V_2 >> 12 & ( ( 1 << 3 ) - 1 ) ;
}
static inline T_1 F_29 ( T_1 V_2 )
{
return V_2 >> 8 & ( ( 1 << 3 ) - 1 ) ;
}
static inline T_1 F_30 ( T_1 V_2 )
{
return V_2 & ( ( 1 << 8 ) - 1 ) ;
}
static inline T_1 F_31 ( T_1 V_2 )
{
return V_2 >> 16 & ( ( 1 << 13 ) - 1 ) ;
}
static inline T_1 F_32 ( T_1 V_2 )
{
return V_2 & ( ( 1 << 16 ) - 1 ) ;
}
static inline T_1 F_33 ( T_1 V_2 )
{
return V_2 & ( ( 1 << 18 ) - 1 ) ;
}
static inline T_1 F_34 ( T_1 V_2 )
{
return F_27 ( V_2 ) ;
}
static inline T_1 F_35 ( T_1 V_2 )
{
return F_28 ( V_2 ) ;
}
static inline T_1 F_36 ( T_1 V_2 )
{
return F_29 ( V_2 ) ;
}
static inline T_1 F_37 ( T_1 V_2 )
{
return F_30 ( V_2 ) ;
}
static inline T_1 F_38 ( T_1 V_2 )
{
return F_31 ( V_2 ) ;
}
static inline T_1 F_39 ( T_1 V_2 )
{
return F_32 ( V_2 ) ;
}
static int F_40 ( const struct V_11 * V_12 ,
int V_13 , int V_14 )
{
const struct V_15 * V_16 = V_12 -> V_17 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
int V_19 ;
const int V_20 = V_16 -> V_21 [ V_13 ] [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
if ( V_16 -> V_22 [ V_10 ] [ V_19 ] == V_14 )
return V_10 * 2 + V_13 ;
}
return - 1 ;
}
static const char * F_41 ( unsigned V_23 )
{
static const char * V_24 [] = {
L_1 ,
L_2 ,
L_1 ,
L_1 ,
L_3 ,
L_4 ,
L_5 ,
L_1 ,
L_1 ,
L_1 ,
L_6 ,
L_7 ,
L_8 ,
L_1 ,
L_9 ,
L_10 ,
L_11 ,
L_1 ,
L_12 ,
L_1 ,
L_13 ,
L_14 ,
} ;
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < F_42 ( V_24 ) ; V_10 ++ )
if ( 1 << V_10 & V_23 )
return V_24 [ V_10 ] ;
return L_15 ;
}
static int F_43 ( const struct V_11 * V_12 , int V_25 )
{
const struct V_15 * V_16 = V_12 -> V_17 ;
return V_25 % V_16 -> V_26 ;
}
static int F_44 ( const struct V_11 * V_12 , int V_25 )
{
const struct V_15 * V_16 = V_12 -> V_17 ;
return V_25 / V_16 -> V_26 ;
}
static unsigned F_45 ( const struct V_11 * V_12 ,
int V_13 , int V_14 )
{
const struct V_15 * V_16 = V_12 -> V_17 ;
return V_13 * V_16 -> V_26 + V_14 ;
}
static void F_46 ( struct V_11 * V_12 ,
int V_13 ,
unsigned V_27 ,
unsigned V_14 ,
unsigned long V_28 ,
unsigned V_29 ,
unsigned V_30 ,
const char * V_31 )
{
const int V_25 = F_45 ( V_12 , V_13 , V_14 ) ;
F_47 ( V_32
L_16
L_17 ,
V_13 , V_27 , V_14 , V_28 , V_29 , V_30 ,
V_25 , V_12 -> V_33 [ V_25 ] . V_34 [ 0 ] . V_35 , V_31 ) ;
V_12 -> V_36 ++ ;
V_12 -> V_33 [ V_25 ] . V_36 ++ ;
V_12 -> V_33 [ V_25 ] . V_34 [ 0 ] . V_36 ++ ;
}
static void F_48 ( struct V_11 * V_12 ,
int V_13 ,
unsigned V_27 ,
unsigned V_14 ,
unsigned long V_28 ,
unsigned V_29 ,
unsigned V_30 ,
const char * V_31 )
{
const int V_25 = F_45 ( V_12 , V_13 , V_14 ) ;
F_47 ( V_32
L_18
L_17 ,
V_13 , V_27 , V_14 , V_28 , V_29 , V_30 ,
V_25 , V_12 -> V_33 [ V_25 ] . V_34 [ 0 ] . V_35 , V_31 ) ;
V_12 -> V_37 ++ ;
V_12 -> V_33 [ V_25 ] . V_37 ++ ;
}
static void F_49 ( struct V_11 * V_12 , int V_13 ,
T_1 V_38 , T_1 V_39 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_40 * V_41 = ( V_13 ) ? V_16 -> V_42 : V_16 -> V_43 ;
T_1 V_44 ;
T_1 V_45 ;
unsigned V_28 = 0 ;
unsigned V_46 = 0 ;
unsigned V_47 ;
unsigned V_27 ;
unsigned V_14 ;
unsigned V_29 ;
unsigned V_30 ;
F_50 ( V_41 , V_48 , & V_44 ) ;
if ( F_24 ( V_44 ) ) {
F_50 ( V_41 , V_49 , & V_45 ) ;
V_28 = V_45 ;
F_50 ( V_41 , V_50 , & V_45 ) ;
V_46 = F_33 ( V_45 ) ;
}
if ( F_25 ( V_44 ) ) {
const char * V_31 ;
F_50 ( V_41 , V_51 , & V_45 ) ;
V_47 = F_34 ( V_45 ) ;
V_27 = F_35 ( V_45 ) ;
V_14 = F_36 ( V_45 ) ;
F_50 ( V_41 , V_52 , & V_45 ) ;
V_29 = F_38 ( V_45 ) ;
V_30 = F_39 ( V_45 ) ;
if ( ! V_47 )
V_31 = F_41 ( V_38 ) ;
else
V_31 = F_41 ( V_39 ) ;
F_46 ( V_12 , V_13 , V_27 , V_14 , V_28 , V_29 , V_30 , V_31 ) ;
}
if ( F_26 ( V_44 ) ) {
const char * V_31 ;
F_50 ( V_41 , V_53 , & V_45 ) ;
V_47 = F_27 ( V_45 ) ;
V_27 = F_28 ( V_45 ) ;
V_14 = F_29 ( V_45 ) ;
F_50 ( V_41 , V_54 , & V_45 ) ;
V_29 = F_31 ( V_45 ) ;
V_30 = F_32 ( V_45 ) ;
if ( ! V_47 )
V_31 = F_41 ( V_38 ) ;
else
V_31 = F_41 ( V_39 ) ;
F_48 ( V_12 , V_13 , V_27 , V_14 , V_28 , V_29 , V_30 , V_31 ) ;
}
F_51 ( V_41 , V_48 , V_44 ) ;
}
static void F_52 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_44 ;
F_50 ( V_16 -> V_1 , V_55 , & V_44 ) ;
if ( F_14 ( V_44 ) ) {
T_1 V_45 ;
F_50 ( V_16 -> V_1 , V_56 , & V_45 ) ;
if ( V_45 )
F_51 ( V_16 -> V_1 , V_56 ,
V_45 ) ;
F_51 ( V_16 -> V_1 , V_55 , V_44 ) ;
F_49 ( V_12 , F_13 ( V_44 ) ,
F_14 ( V_44 ) ,
F_15 ( V_45 ) ) ;
}
}
static void F_53 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_54 ( V_58 ,
struct V_59 ,
V_58 ) ;
struct V_15 * V_16 = F_54 ( V_60 ,
struct V_15 ,
V_60 ) ;
T_1 V_44 ;
F_50 ( V_16 -> V_1 , V_61 , & V_44 ) ;
if ( V_16 -> V_62 ) {
F_50 ( V_16 -> V_1 , V_61 , & V_44 ) ;
if ( F_3 ( V_44 ) ) {
V_44 |= V_63 ;
F_51 ( V_16 -> V_1 , V_61 , V_44 ) ;
F_50 ( V_16 -> V_1 , V_61 , & V_44 ) ;
}
F_55 ( & ( V_16 -> V_60 ) ,
V_64 ) ;
}
}
static int F_56 ( struct V_11 * V_12 , T_1 V_65 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_44 ;
F_50 ( V_16 -> V_1 , V_61 , & V_44 ) ;
if ( V_65 ) {
V_16 -> V_62 = 1 ;
V_44 |= V_63 ;
F_55 ( & ( V_16 -> V_60 ) ,
V_64 ) ;
} else {
V_16 -> V_62 = 0 ;
V_44 &= ~ V_63 ;
F_57 ( & ( V_16 -> V_60 ) ) ;
}
F_51 ( V_16 -> V_1 , V_61 , V_44 ) ;
F_50 ( V_16 -> V_1 , V_61 , & V_44 ) ;
V_65 = 5900000 * F_1 ( V_44 ) ;
return V_65 ;
}
static int F_58 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_44 ;
F_50 ( V_16 -> V_1 , V_61 , & V_44 ) ;
return 5900000 * F_1 ( V_44 ) ;
}
static struct V_40 * F_59 ( unsigned V_66 ,
unsigned V_67 ,
unsigned V_68 )
{
struct V_40 * V_69 = NULL ;
while ( 1 ) {
V_69 = F_60 ( V_66 , V_67 , V_69 ) ;
if ( ! V_69 )
break;
if ( F_61 ( V_69 -> V_70 ) == V_68 )
break;
}
return V_69 ;
}
static unsigned long T_3 F_62 ( struct V_11 * V_12 ,
int V_25 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
const unsigned V_71 = F_43 ( V_12 , V_25 ) ;
const unsigned V_13 = F_44 ( V_12 , V_25 ) ;
unsigned V_72 ;
if ( ! V_16 -> V_73 [ V_13 ] [ V_71 ] . V_74 )
return 0ULL ;
V_72 =
V_75 +
V_16 -> V_73 [ V_13 ] [ V_71 ] . V_76 +
V_16 -> V_73 [ V_13 ] [ V_71 ] . V_77 +
V_16 -> V_73 [ V_13 ] [ V_71 ] . V_78 ;
return ( unsigned long )
( ( unsigned long long ) ( 1ULL << V_72 ) / V_79 ) ;
}
static void T_3 F_63 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_40 * V_80 [ 2 ] = { V_16 -> V_43 , V_16 -> V_42 } ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) {
int V_19 ;
struct V_40 * V_41 = V_80 [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_82 ; V_19 ++ ) {
const unsigned V_83 =
( V_19 < 4 ) ? V_84 + V_19 * 2 :
V_85 + ( V_19 - 4 ) * 2 ;
T_2 V_86 ;
F_64 ( V_41 , V_83 , & V_86 ) ;
V_16 -> V_73 [ V_10 ] [ V_19 ] . V_74 = F_18 ( V_86 ) ;
V_16 -> V_73 [ V_10 ] [ V_19 ] . V_87 = F_19 ( V_86 ) ;
V_16 -> V_73 [ V_10 ] [ V_19 ] . V_88 = 4 + 4 * F_20 ( V_86 ) ;
V_16 -> V_73 [ V_10 ] [ V_19 ] . V_78 = 2 + F_21 ( V_86 ) ;
V_16 -> V_73 [ V_10 ] [ V_19 ] . V_77 = 13 + F_22 ( V_86 ) ;
V_16 -> V_73 [ V_10 ] [ V_19 ] . V_76 = 10 + F_23 ( V_86 ) ;
}
}
}
static int F_65 ( const struct V_11 * V_12 ,
T_4 V_89 , T_4 V_90 , T_4 V_83 , T_4 * V_91 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 V_86 ;
unsigned long V_92 ;
F_64 ( V_16 -> V_1 , V_93 , & V_86 ) ;
if ( F_6 ( V_86 ) )
return - 1 ;
F_51 ( V_16 -> V_1 , V_94 ,
F_8 ( 0xa , 1 , V_89 * 4 + V_90 , V_83 ,
0 , 0 ) ) ;
V_92 = V_95 + V_96 / 10 ;
F_66 ( 100 ) ;
while ( 1 ) {
F_64 ( V_16 -> V_1 , V_93 , & V_86 ) ;
if ( ! F_6 ( V_86 ) )
break;
F_66 ( 100 ) ;
}
if ( ! F_4 ( V_86 ) || F_5 ( V_86 ) )
return - 1 ;
* V_91 = F_7 ( V_86 ) ;
return 0 ;
}
static void T_3 F_67 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_97 ; V_19 ++ )
V_16 -> V_22 [ V_10 ] [ V_19 ] = - 1 ;
}
if ( V_16 -> V_26 == 4 ) {
V_16 -> V_22 [ 0 ] [ 0 ] = 0 ;
V_16 -> V_22 [ 0 ] [ 1 ] = 3 ;
V_16 -> V_22 [ 1 ] [ 0 ] = 1 ;
V_16 -> V_22 [ 1 ] [ 1 ] = 2 ;
V_16 -> V_22 [ 2 ] [ 0 ] = 2 ;
V_16 -> V_22 [ 3 ] [ 0 ] = 3 ;
} else {
V_16 -> V_22 [ 0 ] [ 0 ] = 0 ;
V_16 -> V_22 [ 0 ] [ 1 ] = 1 ;
V_16 -> V_22 [ 1 ] [ 0 ] = 2 ;
V_16 -> V_22 [ 1 ] [ 1 ] = 3 ;
V_16 -> V_22 [ 2 ] [ 0 ] = 4 ;
V_16 -> V_22 [ 2 ] [ 1 ] = 5 ;
}
}
static void T_3 F_68 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
T_4 V_14 ;
if ( F_65 ( V_12 , V_10 , V_19 , 5 , & V_14 ) < 0 )
V_16 -> V_21 [ V_10 ] [ V_19 ] = 0 ;
else
V_16 -> V_21 [ V_10 ] [ V_19 ] = ( V_14 & 3 ) + 1 ;
}
}
F_67 ( V_12 ) ;
}
static void T_3 F_69 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
T_2 V_86 ;
T_1 V_44 ;
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_40 * V_80 [ 2 ] = { V_16 -> V_43 , V_16 -> V_42 } ;
int V_10 ;
F_64 ( V_41 , V_98 , & V_86 ) ;
V_16 -> V_99 = ( V_100 ) F_9 ( V_86 ) * 256 * 1024 * 1024 ;
F_64 ( V_41 , V_101 , & V_86 ) ;
V_16 -> V_102 [ 0 ] . V_103 = ( V_100 ) F_10 ( V_86 ) << 28 ;
V_16 -> V_102 [ 0 ] . V_104 [ 1 ] = F_11 ( V_86 ) ;
V_16 -> V_102 [ 0 ] . V_104 [ 0 ] = F_12 ( V_86 ) ;
F_64 ( V_41 , V_105 , & V_86 ) ;
V_16 -> V_102 [ 1 ] . V_103 = ( V_100 ) F_10 ( V_86 ) << 28 ;
V_16 -> V_102 [ 1 ] . V_104 [ 1 ] = F_11 ( V_86 ) ;
V_16 -> V_102 [ 1 ] . V_104 [ 0 ] = F_12 ( V_86 ) ;
F_64 ( V_41 , V_106 , & V_86 ) ;
V_16 -> V_107 [ 0 ] = V_86 ;
F_64 ( V_41 , V_108 , & V_86 ) ;
V_16 -> V_107 [ 1 ] = V_86 ;
for ( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < 5 ; V_19 ++ ) {
int V_109 ;
F_50 ( V_80 [ V_10 ] , V_110 + V_19 * 4 , & V_44 ) ;
V_16 -> V_111 [ V_10 ] [ V_19 ] . V_103 =
( V_100 ) F_16 ( V_44 ) << 28 ;
for ( V_109 = 0 ; V_109 < V_97 ; V_109 ++ )
V_16 -> V_111 [ V_10 ] [ V_19 ] . V_14 [ V_109 ] =
F_17 ( V_44 , V_109 ) ;
}
}
F_63 ( V_12 ) ;
}
static void T_3 F_70 ( struct V_11 * V_12 )
{
int V_10 ;
unsigned long V_112 = 0UL ;
struct V_15 * V_16 = V_12 -> V_17 ;
for ( V_10 = 0 ; V_10 < V_12 -> V_113 ; V_10 ++ ) {
const unsigned long V_114 = F_62 ( V_12 , V_10 ) ;
const unsigned V_13 = F_44 ( V_12 , V_10 ) ;
const unsigned V_14 = F_43 ( V_12 , V_10 ) ;
if ( ! V_114 )
continue;
V_12 -> V_33 [ V_10 ] . V_115 = V_112 ;
V_12 -> V_33 [ V_10 ] . V_116 = V_112 + V_114 - 1 ;
V_12 -> V_33 [ V_10 ] . V_117 = 0UL ;
V_12 -> V_33 [ V_10 ] . V_118 = V_114 ;
V_12 -> V_33 [ V_10 ] . V_119 = 32 ;
V_12 -> V_33 [ V_10 ] . V_120 = V_10 ;
V_12 -> V_33 [ V_10 ] . V_121 =
( V_16 -> V_73 [ V_13 ] [ V_14 ] . V_88 == 4 ) ? V_122 : V_123 ;
V_12 -> V_33 [ V_10 ] . V_37 = 0 ;
V_12 -> V_33 [ V_10 ] . V_36 = 0 ;
V_12 -> V_33 [ V_10 ] . V_124 = V_125 ;
V_12 -> V_33 [ V_10 ] . V_126 = V_127 ;
V_12 -> V_33 [ V_10 ] . V_12 = V_12 ;
V_12 -> V_33 [ V_10 ] . V_128 = 1 ;
V_12 -> V_33 [ V_10 ] . V_34 [ 0 ] . V_129 = 0 ;
V_12 -> V_33 [ V_10 ] . V_34 [ 0 ] . V_36 = 0 ;
V_12 -> V_33 [ V_10 ] . V_34 [ 0 ] . V_25 = V_12 -> V_33 + V_10 ;
snprintf ( V_12 -> V_33 [ V_10 ] . V_34 [ 0 ] . V_35 ,
sizeof( V_12 -> V_33 [ V_10 ] . V_34 [ 0 ] . V_35 ) ,
L_19 , F_40 ( V_12 , V_13 , V_14 ) ) ;
V_112 += V_114 ;
}
}
static int T_3 F_71 ( struct V_40 * V_41 ,
const struct V_130 * V_131 )
{
int V_132 ;
struct V_11 * V_12 ;
struct V_15 * V_16 ;
struct V_40 * V_43 , * V_42 ;
int V_69 = 0 ;
T_1 V_44 ;
int V_133 ;
if ( F_61 ( V_41 -> V_70 ) != 1 )
return - V_134 ;
V_132 = F_72 ( V_41 ) ;
if ( V_132 < 0 ) {
V_69 = V_132 ;
goto V_135;
}
F_50 ( V_41 , V_61 , & V_44 ) ;
if ( ! F_2 ( V_44 ) ) {
F_47 ( V_136 L_20 ) ;
V_69 = - V_134 ;
goto V_137;
}
F_50 ( V_41 , V_138 , & V_44 ) ;
V_133 = ! ! ( V_44 & ( 1 << 8 ) ) * 2 + 4 ;
F_50 ( V_41 , V_139 , & V_44 ) ;
V_44 &= ~ V_9 ;
F_51 ( V_41 , V_139 , V_44 ) ;
V_43 = F_59 ( V_140 ,
V_141 , 0 ) ;
if ( ! V_43 ) {
V_69 = - V_134 ;
goto V_137;
}
V_132 = F_72 ( V_43 ) ;
if ( V_132 < 0 ) {
V_69 = V_132 ;
goto V_142;
}
V_42 = F_59 ( V_140 ,
V_143 , 0 ) ;
if ( ! V_42 ) {
V_69 = - V_134 ;
goto V_144;
}
V_132 = F_72 ( V_42 ) ;
if ( V_132 < 0 ) {
V_69 = V_132 ;
goto V_145;
}
V_12 = F_73 ( sizeof( * V_16 ) , V_133 * 2 , 1 , 0 ) ;
if ( ! V_12 ) {
V_69 = - V_146 ;
goto V_147;
}
V_12 -> V_148 = & V_41 -> V_148 ;
V_16 = V_12 -> V_17 ;
V_16 -> V_26 = V_133 ;
V_16 -> V_1 = V_41 ;
V_16 -> V_43 = V_43 ;
V_16 -> V_42 = V_42 ;
F_74 ( & ( V_16 -> V_60 ) , F_53 ) ;
F_50 ( V_41 , V_61 , & V_44 ) ;
if ( F_1 ( V_44 ) ) {
V_16 -> V_62 = 1 ;
F_55 ( & ( V_16 -> V_60 ) ,
V_64 ) ;
}
F_68 ( V_41 , V_12 ) ;
F_69 ( V_41 , V_12 ) ;
V_12 -> V_149 = V_150 ;
V_12 -> V_151 = V_152 ;
V_12 -> V_153 = V_152 ;
V_12 -> V_154 = L_21 ;
V_12 -> V_155 = L_22 ;
V_12 -> V_156 = L_23 ;
V_12 -> V_157 = F_75 ( V_41 ) ;
V_12 -> V_158 = NULL ;
V_12 -> V_159 = F_52 ;
V_12 -> V_160 = F_56 ;
V_12 -> V_161 = F_58 ;
F_70 ( V_12 ) ;
switch ( V_162 ) {
case V_163 :
case V_164 :
break;
default:
V_162 = V_163 ;
break;
}
if ( F_76 ( V_12 ) ) {
V_69 = - V_134 ;
goto V_165;
}
return V_69 ;
V_165:
V_16 -> V_62 = 0 ;
F_77 ( & ( V_16 -> V_60 ) ) ;
F_78 ( V_12 ) ;
V_147:
F_79 ( V_42 ) ;
V_145:
F_80 ( V_42 ) ;
V_144:
F_79 ( V_43 ) ;
V_142:
F_80 ( V_43 ) ;
V_137:
F_79 ( V_41 ) ;
V_135:
return V_69 ;
}
static void T_5 F_81 ( struct V_40 * V_41 )
{
struct V_11 * V_12 ;
struct V_15 * V_16 ;
V_12 = F_82 ( & V_41 -> V_148 ) ;
if ( ! V_12 )
return;
V_16 = V_12 -> V_17 ;
V_16 -> V_62 = 0 ;
F_77 ( & ( V_16 -> V_60 ) ) ;
F_79 ( V_41 ) ;
F_79 ( V_16 -> V_43 ) ;
F_79 ( V_16 -> V_42 ) ;
F_80 ( V_16 -> V_43 ) ;
F_80 ( V_16 -> V_42 ) ;
F_78 ( V_12 ) ;
}
static int T_6 F_83 ( void )
{
int V_166 ;
V_166 = F_84 ( & V_167 ) ;
return ( V_166 < 0 ) ? V_166 : 0 ;
}
static void T_7 F_85 ( void )
{
F_86 ( & V_167 ) ;
}
