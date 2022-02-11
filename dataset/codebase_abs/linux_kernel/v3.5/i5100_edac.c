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
static void F_45 ( struct V_11 * V_12 ,
int V_13 ,
unsigned V_27 ,
unsigned V_14 ,
unsigned long V_28 ,
unsigned V_29 ,
unsigned V_30 ,
const char * V_31 )
{
char V_32 [ 80 ] ;
snprintf ( V_32 , sizeof( V_32 ) ,
L_16 ,
V_27 , V_29 , V_30 ) ;
F_46 ( V_33 , V_12 ,
0 , 0 , V_28 ,
V_13 , V_14 , - 1 ,
V_31 , V_32 , NULL ) ;
}
static void F_47 ( struct V_11 * V_12 ,
int V_13 ,
unsigned V_27 ,
unsigned V_14 ,
unsigned long V_28 ,
unsigned V_29 ,
unsigned V_30 ,
const char * V_31 )
{
char V_32 [ 80 ] ;
snprintf ( V_32 , sizeof( V_32 ) ,
L_16 ,
V_27 , V_29 , V_30 ) ;
F_46 ( V_34 , V_12 ,
0 , 0 , V_28 ,
V_13 , V_14 , - 1 ,
V_31 , V_32 , NULL ) ;
}
static void F_48 ( struct V_11 * V_12 , int V_13 ,
T_1 V_35 , T_1 V_36 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_37 * V_38 = ( V_13 ) ? V_16 -> V_39 : V_16 -> V_40 ;
T_1 V_41 ;
T_1 V_42 ;
unsigned V_28 = 0 ;
unsigned V_43 = 0 ;
unsigned V_44 ;
unsigned V_27 ;
unsigned V_14 ;
unsigned V_29 ;
unsigned V_30 ;
F_49 ( V_38 , V_45 , & V_41 ) ;
if ( F_24 ( V_41 ) ) {
F_49 ( V_38 , V_46 , & V_42 ) ;
V_28 = V_42 ;
F_49 ( V_38 , V_47 , & V_42 ) ;
V_43 = F_33 ( V_42 ) ;
}
if ( F_25 ( V_41 ) ) {
const char * V_31 ;
F_49 ( V_38 , V_48 , & V_42 ) ;
V_44 = F_34 ( V_42 ) ;
V_27 = F_35 ( V_42 ) ;
V_14 = F_36 ( V_42 ) ;
F_49 ( V_38 , V_49 , & V_42 ) ;
V_29 = F_38 ( V_42 ) ;
V_30 = F_39 ( V_42 ) ;
if ( ! V_44 )
V_31 = F_41 ( V_35 ) ;
else
V_31 = F_41 ( V_36 ) ;
F_45 ( V_12 , V_13 , V_27 , V_14 , V_28 , V_29 , V_30 , V_31 ) ;
}
if ( F_26 ( V_41 ) ) {
const char * V_31 ;
F_49 ( V_38 , V_50 , & V_42 ) ;
V_44 = F_27 ( V_42 ) ;
V_27 = F_28 ( V_42 ) ;
V_14 = F_29 ( V_42 ) ;
F_49 ( V_38 , V_51 , & V_42 ) ;
V_29 = F_31 ( V_42 ) ;
V_30 = F_32 ( V_42 ) ;
if ( ! V_44 )
V_31 = F_41 ( V_35 ) ;
else
V_31 = F_41 ( V_36 ) ;
F_47 ( V_12 , V_13 , V_27 , V_14 , V_28 , V_29 , V_30 , V_31 ) ;
}
F_50 ( V_38 , V_45 , V_41 ) ;
}
static void F_51 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_41 , V_42 ;
F_49 ( V_16 -> V_1 , V_52 , & V_41 ) ;
if ( F_14 ( V_41 ) ) {
F_49 ( V_16 -> V_1 , V_53 , & V_42 ) ;
F_48 ( V_12 , F_13 ( V_41 ) ,
F_14 ( V_41 ) ,
F_15 ( V_42 ) ) ;
F_50 ( V_16 -> V_1 , V_53 , V_42 ) ;
}
F_50 ( V_16 -> V_1 , V_52 , V_41 ) ;
}
static void F_52 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_53 ( V_55 ,
struct V_56 ,
V_55 ) ;
struct V_15 * V_16 = F_53 ( V_57 ,
struct V_15 ,
V_57 ) ;
T_1 V_41 ;
F_49 ( V_16 -> V_1 , V_58 , & V_41 ) ;
if ( V_16 -> V_59 ) {
F_49 ( V_16 -> V_1 , V_58 , & V_41 ) ;
if ( F_3 ( V_41 ) ) {
V_41 |= V_60 ;
F_50 ( V_16 -> V_1 , V_58 , V_41 ) ;
F_49 ( V_16 -> V_1 , V_58 , & V_41 ) ;
}
F_54 ( & ( V_16 -> V_57 ) ,
V_61 ) ;
}
}
static int F_55 ( struct V_11 * V_12 , T_1 V_62 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_41 ;
F_49 ( V_16 -> V_1 , V_58 , & V_41 ) ;
if ( V_62 ) {
V_16 -> V_59 = 1 ;
V_41 |= V_60 ;
F_54 ( & ( V_16 -> V_57 ) ,
V_61 ) ;
} else {
V_16 -> V_59 = 0 ;
V_41 &= ~ V_60 ;
F_56 ( & ( V_16 -> V_57 ) ) ;
}
F_50 ( V_16 -> V_1 , V_58 , V_41 ) ;
F_49 ( V_16 -> V_1 , V_58 , & V_41 ) ;
V_62 = 5900000 * F_1 ( V_41 ) ;
return V_62 ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_41 ;
F_49 ( V_16 -> V_1 , V_58 , & V_41 ) ;
return 5900000 * F_1 ( V_41 ) ;
}
static struct V_37 * F_58 ( unsigned V_63 ,
unsigned V_64 ,
unsigned V_65 )
{
struct V_37 * V_66 = NULL ;
while ( 1 ) {
V_66 = F_59 ( V_63 , V_64 , V_66 ) ;
if ( ! V_66 )
break;
if ( F_60 ( V_66 -> V_67 ) == V_65 )
break;
}
return V_66 ;
}
static unsigned long T_3 F_61 ( struct V_11 * V_12 ,
int V_25 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
const unsigned V_68 = F_43 ( V_12 , V_25 ) ;
const unsigned V_13 = F_44 ( V_12 , V_25 ) ;
unsigned V_69 ;
if ( ! V_16 -> V_70 [ V_13 ] [ V_68 ] . V_71 )
return 0ULL ;
V_69 =
V_72 +
V_16 -> V_70 [ V_13 ] [ V_68 ] . V_73 +
V_16 -> V_70 [ V_13 ] [ V_68 ] . V_74 +
V_16 -> V_70 [ V_13 ] [ V_68 ] . V_75 ;
return ( unsigned long )
( ( unsigned long long ) ( 1ULL << V_69 ) / V_76 ) ;
}
static void T_3 F_62 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_37 * V_77 [ 2 ] = { V_16 -> V_40 , V_16 -> V_39 } ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_78 ; V_10 ++ ) {
int V_19 ;
struct V_37 * V_38 = V_77 [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_79 ; V_19 ++ ) {
const unsigned V_80 =
( V_19 < 4 ) ? V_81 + V_19 * 2 :
V_82 + ( V_19 - 4 ) * 2 ;
T_2 V_83 ;
F_63 ( V_38 , V_80 , & V_83 ) ;
V_16 -> V_70 [ V_10 ] [ V_19 ] . V_71 = F_18 ( V_83 ) ;
V_16 -> V_70 [ V_10 ] [ V_19 ] . V_84 = F_19 ( V_83 ) ;
V_16 -> V_70 [ V_10 ] [ V_19 ] . V_85 = 4 + 4 * F_20 ( V_83 ) ;
V_16 -> V_70 [ V_10 ] [ V_19 ] . V_75 = 2 + F_21 ( V_83 ) ;
V_16 -> V_70 [ V_10 ] [ V_19 ] . V_74 = 13 + F_22 ( V_83 ) ;
V_16 -> V_70 [ V_10 ] [ V_19 ] . V_73 = 10 + F_23 ( V_83 ) ;
}
}
}
static int F_64 ( const struct V_11 * V_12 ,
T_4 V_86 , T_4 V_87 , T_4 V_80 , T_4 * V_88 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 V_83 ;
unsigned long V_89 ;
F_63 ( V_16 -> V_1 , V_90 , & V_83 ) ;
if ( F_6 ( V_83 ) )
return - 1 ;
F_50 ( V_16 -> V_1 , V_91 ,
F_8 ( 0xa , 1 , V_86 * 4 + V_87 , V_80 ,
0 , 0 ) ) ;
V_89 = V_92 + V_93 / 10 ;
F_65 ( 100 ) ;
while ( 1 ) {
F_63 ( V_16 -> V_1 , V_90 , & V_83 ) ;
if ( ! F_6 ( V_83 ) )
break;
F_65 ( 100 ) ;
}
if ( ! F_4 ( V_83 ) || F_5 ( V_83 ) )
return - 1 ;
* V_88 = F_7 ( V_83 ) ;
return 0 ;
}
static void T_3 F_66 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_94 ; V_19 ++ )
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
static void T_3 F_67 ( struct V_37 * V_38 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_78 ; V_10 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
T_4 V_14 ;
if ( F_64 ( V_12 , V_10 , V_19 , 5 , & V_14 ) < 0 )
V_16 -> V_21 [ V_10 ] [ V_19 ] = 0 ;
else
V_16 -> V_21 [ V_10 ] [ V_19 ] = ( V_14 & 3 ) + 1 ;
}
}
F_66 ( V_12 ) ;
}
static void T_3 F_68 ( struct V_37 * V_38 ,
struct V_11 * V_12 )
{
T_2 V_83 ;
T_1 V_41 ;
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_37 * V_77 [ 2 ] = { V_16 -> V_40 , V_16 -> V_39 } ;
int V_10 ;
F_63 ( V_38 , V_95 , & V_83 ) ;
V_16 -> V_96 = ( V_97 ) F_9 ( V_83 ) * 256 * 1024 * 1024 ;
F_63 ( V_38 , V_98 , & V_83 ) ;
V_16 -> V_99 [ 0 ] . V_100 = ( V_97 ) F_10 ( V_83 ) << 28 ;
V_16 -> V_99 [ 0 ] . V_101 [ 1 ] = F_11 ( V_83 ) ;
V_16 -> V_99 [ 0 ] . V_101 [ 0 ] = F_12 ( V_83 ) ;
F_63 ( V_38 , V_102 , & V_83 ) ;
V_16 -> V_99 [ 1 ] . V_100 = ( V_97 ) F_10 ( V_83 ) << 28 ;
V_16 -> V_99 [ 1 ] . V_101 [ 1 ] = F_11 ( V_83 ) ;
V_16 -> V_99 [ 1 ] . V_101 [ 0 ] = F_12 ( V_83 ) ;
F_63 ( V_38 , V_103 , & V_83 ) ;
V_16 -> V_104 [ 0 ] = V_83 ;
F_63 ( V_38 , V_105 , & V_83 ) ;
V_16 -> V_104 [ 1 ] = V_83 ;
for ( V_10 = 0 ; V_10 < V_78 ; V_10 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < 5 ; V_19 ++ ) {
int V_106 ;
F_49 ( V_77 [ V_10 ] , V_107 + V_19 * 4 , & V_41 ) ;
V_16 -> V_108 [ V_10 ] [ V_19 ] . V_100 =
( V_97 ) F_16 ( V_41 ) << 28 ;
for ( V_106 = 0 ; V_106 < V_94 ; V_106 ++ )
V_16 -> V_108 [ V_10 ] [ V_19 ] . V_14 [ V_106 ] =
F_17 ( V_41 , V_106 ) ;
}
}
F_62 ( V_12 ) ;
}
static void T_3 F_69 ( struct V_11 * V_12 )
{
int V_10 ;
struct V_15 * V_16 = V_12 -> V_17 ;
for ( V_10 = 0 ; V_10 < V_12 -> V_109 ; V_10 ++ ) {
struct V_110 * V_111 ;
const unsigned long V_112 = F_61 ( V_12 , V_10 ) ;
const unsigned V_13 = F_44 ( V_12 , V_10 ) ;
const unsigned V_14 = F_43 ( V_12 , V_10 ) ;
if ( ! V_112 )
continue;
V_111 = F_70 ( V_12 -> V_113 , V_12 -> V_114 , V_12 -> V_115 ,
V_13 , V_14 , 0 ) ;
V_111 -> V_116 = V_112 ;
if ( V_112 ) {
V_111 -> V_117 = 32 ;
V_111 -> V_118 = ( V_16 -> V_70 [ V_13 ] [ V_14 ] . V_85 == 4 ) ?
V_119 : V_120 ;
V_111 -> V_121 = V_122 ;
V_111 -> V_123 = V_124 ;
snprintf ( V_111 -> V_125 , sizeof( V_111 -> V_125 ) ,
L_17 ,
F_40 ( V_12 , V_13 , V_14 ) ) ;
}
F_71 ( L_18 ,
V_13 , V_14 , ( long ) F_72 ( V_112 ) ) ;
}
}
static int T_3 F_73 ( struct V_37 * V_38 ,
const struct V_126 * V_127 )
{
int V_128 ;
struct V_11 * V_12 ;
struct V_129 V_113 [ 2 ] ;
struct V_15 * V_16 ;
struct V_37 * V_40 , * V_39 ;
int V_66 = 0 ;
T_1 V_41 ;
int V_130 ;
if ( F_60 ( V_38 -> V_67 ) != 1 )
return - V_131 ;
V_128 = F_74 ( V_38 ) ;
if ( V_128 < 0 ) {
V_66 = V_128 ;
goto V_132;
}
F_49 ( V_38 , V_58 , & V_41 ) ;
if ( ! F_2 ( V_41 ) ) {
F_75 ( V_133 L_19 ) ;
V_66 = - V_131 ;
goto V_134;
}
F_49 ( V_38 , V_135 , & V_41 ) ;
V_130 = ! ! ( V_41 & ( 1 << 8 ) ) * 2 + 4 ;
F_49 ( V_38 , V_136 , & V_41 ) ;
V_41 &= ~ V_9 ;
F_50 ( V_38 , V_136 , V_41 ) ;
V_40 = F_58 ( V_137 ,
V_138 , 0 ) ;
if ( ! V_40 ) {
V_66 = - V_131 ;
goto V_134;
}
V_128 = F_74 ( V_40 ) ;
if ( V_128 < 0 ) {
V_66 = V_128 ;
goto V_139;
}
V_39 = F_58 ( V_137 ,
V_140 , 0 ) ;
if ( ! V_39 ) {
V_66 = - V_131 ;
goto V_141;
}
V_128 = F_74 ( V_39 ) ;
if ( V_128 < 0 ) {
V_66 = V_128 ;
goto V_142;
}
V_113 [ 0 ] . type = V_143 ;
V_113 [ 0 ] . V_144 = 2 ;
V_113 [ 0 ] . V_145 = false ;
V_113 [ 1 ] . type = V_146 ;
V_113 [ 1 ] . V_144 = V_130 ;
V_113 [ 1 ] . V_145 = true ;
V_12 = F_76 ( 0 , F_42 ( V_113 ) , V_113 ,
sizeof( * V_16 ) ) ;
if ( ! V_12 ) {
V_66 = - V_147 ;
goto V_148;
}
V_12 -> V_149 = & V_38 -> V_149 ;
V_16 = V_12 -> V_17 ;
V_16 -> V_26 = V_130 ;
V_16 -> V_1 = V_38 ;
V_16 -> V_40 = V_40 ;
V_16 -> V_39 = V_39 ;
F_77 ( & ( V_16 -> V_57 ) , F_52 ) ;
F_49 ( V_38 , V_58 , & V_41 ) ;
if ( F_1 ( V_41 ) ) {
V_16 -> V_59 = 1 ;
F_54 ( & ( V_16 -> V_57 ) ,
V_61 ) ;
}
F_67 ( V_38 , V_12 ) ;
F_68 ( V_38 , V_12 ) ;
V_12 -> V_150 = V_151 ;
V_12 -> V_152 = V_153 ;
V_12 -> V_154 = V_153 ;
V_12 -> V_155 = L_20 ;
V_12 -> V_156 = L_21 ;
V_12 -> V_157 = L_22 ;
V_12 -> V_158 = F_78 ( V_38 ) ;
V_12 -> V_159 = NULL ;
V_12 -> V_160 = F_51 ;
V_12 -> V_161 = F_55 ;
V_12 -> V_162 = F_57 ;
F_69 ( V_12 ) ;
switch ( V_163 ) {
case V_164 :
case V_165 :
break;
default:
V_163 = V_164 ;
break;
}
if ( F_79 ( V_12 ) ) {
V_66 = - V_131 ;
goto V_166;
}
return V_66 ;
V_166:
V_16 -> V_59 = 0 ;
F_80 ( & ( V_16 -> V_57 ) ) ;
F_81 ( V_12 ) ;
V_148:
F_82 ( V_39 ) ;
V_142:
F_83 ( V_39 ) ;
V_141:
F_82 ( V_40 ) ;
V_139:
F_83 ( V_40 ) ;
V_134:
F_82 ( V_38 ) ;
V_132:
return V_66 ;
}
static void T_5 F_84 ( struct V_37 * V_38 )
{
struct V_11 * V_12 ;
struct V_15 * V_16 ;
V_12 = F_85 ( & V_38 -> V_149 ) ;
if ( ! V_12 )
return;
V_16 = V_12 -> V_17 ;
V_16 -> V_59 = 0 ;
F_80 ( & ( V_16 -> V_57 ) ) ;
F_82 ( V_38 ) ;
F_82 ( V_16 -> V_40 ) ;
F_82 ( V_16 -> V_39 ) ;
F_83 ( V_16 -> V_40 ) ;
F_83 ( V_16 -> V_39 ) ;
F_81 ( V_12 ) ;
}
static int T_6 F_86 ( void )
{
int V_167 ;
V_167 = F_87 ( & V_168 ) ;
return ( V_167 < 0 ) ? V_167 : 0 ;
}
static void T_7 F_88 ( void )
{
F_89 ( & V_168 ) ;
}
