static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 , int V_5 )
{
return F_2 ( V_2 , V_3 , 0 ,
V_6 ,
( V_5 << 4 ) | V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
return ( F_4 ( V_2 , V_3 , 0 ,
V_7 ,
V_4 ) & 0xf0 ) >> 4 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_8 )
{
return 1 + F_4 ( V_2 , V_8 , 0 ,
V_9 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_8 , int V_10 )
{
if ( V_10 != F_5 ( V_2 , V_8 ) )
F_2 ( V_2 , V_8 , 0 ,
V_11 , V_10 - 1 ) ;
}
static void F_7 ( void )
{
int V_12 , V_13 ;
struct V_14 * V_15 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ ) {
V_15 = V_16 + V_12 ;
V_15 -> V_17 = 0 ;
V_15 -> V_18 = 0 ;
for ( V_13 = 0 ; V_13 < F_8 ( V_15 -> V_19 ) ; V_13 ++ )
if ( V_15 -> V_19 [ V_13 ] ) {
V_15 -> V_17 ++ ;
V_15 -> V_18 |= V_15 -> V_19 [ V_13 ] ;
}
}
}
static int F_9 ( int V_20 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ ) {
if ( V_16 [ V_12 ] . V_21 == V_20 )
break;
}
return V_12 ;
}
void F_10 ( int V_22 , char * V_23 , int V_24 )
{
int V_12 , V_13 ;
for ( V_12 = 0 , V_13 = 0 ; V_12 < F_8 ( V_25 ) ; V_12 ++ ) {
if ( V_22 & ( 1 << V_12 ) )
V_13 += snprintf ( V_23 + V_13 , V_24 - V_13 , L_1 ,
V_25 [ V_12 ] ) ;
}
V_23 [ V_13 ] = '\0' ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_22 , int V_17 )
{
int V_12 ;
int V_20 = 0 ;
int V_18 = 0 ;
char V_23 [ V_26 ] ;
if ( V_17 <= 2 )
return 0 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_27 ) ; V_12 ++ ) {
if ( V_22 & ( 1 << V_12 ) )
V_18 |= V_27 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ ) {
if ( V_17 == V_16 [ V_12 ] . V_17 &&
( V_18 & V_16 [ V_12 ] . V_18 ) ==
V_16 [ V_12 ] . V_18 ) {
V_20 = V_16 [ V_12 ] . V_21 ;
break;
}
}
if ( ! V_20 ) {
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ ) {
if ( V_17 == V_16 [ V_12 ] . V_17 ) {
V_20 = V_16 [ V_12 ] . V_21 ;
break;
}
}
}
F_10 ( V_22 , V_23 , sizeof( V_23 ) ) ;
F_12 ( & V_2 -> V_28 , L_2 ,
V_20 , V_17 , V_23 ) ;
return V_20 ;
}
static void F_13 ( struct V_29 * V_30 ,
T_1 V_3 )
{
#ifdef F_14
int V_12 ;
int V_5 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_5 = V_30 -> V_31 . V_32 (
V_30 -> V_33 , V_3 , V_12 ) ;
F_12 ( & V_30 -> V_33 -> V_28 , L_3 ,
V_5 , V_12 ) ;
}
#endif
}
static void F_15 ( struct V_29 * V_30 ,
T_1 V_3 ,
bool V_34 ,
int V_20 )
{
struct V_14 * V_35 ;
int V_12 ;
int V_36 ;
int V_37 ;
int V_38 [ 8 ] ;
V_37 = F_9 ( V_20 ) ;
V_35 = & V_16 [ V_37 ] ;
if ( V_39 [ V_20 ] [ 1 ] == 0 ) {
int V_40 = 0 ;
for ( V_12 = 0 ; V_12 < V_35 -> V_17 ; V_12 ++ ) {
while ( ! F_16 ( V_40 >= 8 ) &&
! V_35 -> V_19 [ 7 - V_40 ] )
V_40 ++ ;
V_39 [ V_20 ] [ V_12 ] = ( V_12 << 4 ) | V_40 ++ ;
}
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
if ( ! V_35 -> V_19 [ 7 - V_40 ] )
V_39 [ V_20 ] [ V_12 ++ ] = ( 0xf << 4 ) | V_40 ;
}
if ( V_34 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_17 ; V_12 ++ )
V_38 [ V_12 ] = ( V_12 << 4 ) | V_12 ;
for (; V_12 < 8 ; V_12 ++ )
V_38 [ V_12 ] = ( 0xf << 4 ) | V_12 ;
}
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
int V_41 = V_34 ? V_38 [ V_12 ] : V_39 [ V_20 ] [ V_12 ] ;
int V_40 = V_41 & 0x0f ;
int V_5 = ( V_41 & 0xf0 ) >> 4 ;
V_36 = V_30 -> V_31 . V_42 ( V_30 -> V_33 ,
V_3 , V_40 , V_5 ) ;
if ( V_36 ) {
F_12 ( & V_30 -> V_33 -> V_28 , L_4 ) ;
break;
}
}
}
int F_17 ( unsigned char V_43 )
{
struct V_44 * V_45 = V_46 ;
for (; V_45 -> V_47 ; V_45 ++ ) {
if ( V_45 -> V_47 == V_43 )
return V_45 -> V_18 ;
}
return 0 ;
}
static int F_18 ( int V_48 , unsigned char V_49 )
{
int V_50 = F_17 ( V_49 ) ;
int V_12 ;
if ( V_48 >= F_8 ( V_16 ) )
return - 1 ;
if ( V_50 ) {
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
if ( V_16 [ V_48 ] . V_19 [ 7 - V_12 ] == V_50 )
return V_12 ;
}
}
return - 1 ;
}
int F_19 ( int V_51 )
{
struct V_44 * V_45 = V_46 ;
for (; V_45 -> V_47 ; V_45 ++ ) {
if ( V_45 -> V_18 == V_51 )
return V_45 -> V_47 ;
}
return 0 ;
}
static int F_20 ( int V_48 , unsigned char V_52 )
{
int V_50 ;
if ( V_52 >= 8 )
return 0 ;
V_50 = V_16 [ V_48 ] . V_19 [ 7 - V_52 ] ;
return F_19 ( V_50 ) ;
}
static int F_21 ( int V_10 , unsigned char * V_47 )
{
int V_12 , V_53 = 0 , V_18 = 0 ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ ) {
int V_50 = F_17 ( V_47 [ V_12 ] ) ;
if ( V_50 ) {
V_18 |= V_50 ;
V_53 ++ ;
}
}
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ ) {
if ( ( V_10 == V_16 [ V_12 ] . V_17 ||
V_53 == V_16 [ V_12 ] . V_17 ) &&
( V_18 & V_16 [ V_12 ] . V_18 ) ==
V_16 [ V_12 ] . V_18 )
return V_16 [ V_12 ] . V_21 ;
}
return - 1 ;
}
static int F_22 ( struct V_29 * V_30 ,
T_1 V_3 ,
int V_10 , unsigned char * V_47 ,
int V_20 )
{
int V_48 = F_9 ( V_20 ) ;
int V_54 , V_40 ;
int V_55 [ 8 ] = { [ 0 ... 7 ] = 0xf } ;
for ( V_54 = 0 ; V_54 < V_10 ; V_54 ++ ) {
V_40 = F_18 ( V_48 , V_47 [ V_54 ] ) ;
if ( V_40 < 0 )
continue;
V_55 [ V_40 ] = V_54 ;
}
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ ) {
int V_36 ;
V_36 = V_30 -> V_31 . V_42 ( V_30 -> V_33 ,
V_3 , V_40 , V_55 [ V_40 ] ) ;
if ( V_36 )
return - V_56 ;
}
return 0 ;
}
static void F_23 ( unsigned char * V_47 , int V_20 )
{
int V_12 ;
int V_48 = F_9 ( V_20 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
if ( V_48 < F_8 ( V_16 ) &&
V_12 < V_16 [ V_48 ] . V_17 )
V_47 [ V_12 ] = F_20 ( V_48 , V_39 [ V_20 ] [ V_12 ] & 0x0f ) ;
else
V_47 [ V_12 ] = 0 ;
}
}
void F_24 ( struct V_29 * V_30 ,
T_1 V_3 , bool V_34 , int V_20 ,
int V_17 , unsigned char * V_47 ,
bool V_57 )
{
if ( ! V_34 && V_57 ) {
F_22 ( V_30 , V_3 ,
V_17 , V_47 , V_20 ) ;
} else {
F_15 ( V_30 , V_3 , V_34 , V_20 ) ;
F_23 ( V_47 , V_20 ) ;
}
F_13 ( V_30 , V_3 ) ;
}
int F_25 ( int V_20 )
{
int V_48 = F_9 ( V_20 ) ;
if ( V_48 >= F_8 ( V_16 ) )
V_48 = 0 ;
return V_16 [ V_48 ] . V_17 ;
}
struct V_14 * F_26 ( int V_20 )
{
return & V_16 [ F_9 ( V_20 ) ] ;
}
int F_27 ( struct V_1 * V_33 , int V_22 ,
int V_17 , bool V_57 , bool V_34 , unsigned char * V_47 )
{
int V_20 ;
if ( ! V_34 && V_57 )
V_20 = F_21 ( V_17 , V_47 ) ;
else
V_20 = F_11 ( V_33 ,
V_22 , V_17 ) ;
if ( V_20 < 0 )
V_20 = 0 ;
return V_20 ;
}
static int F_28 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = F_29 ( V_59 ) ;
struct V_29 * V_30 = V_63 -> V_64 ;
V_61 -> type = V_65 ;
V_61 -> V_66 = V_30 -> V_67 ;
V_61 -> V_68 . integer . V_69 = 0 ;
V_61 -> V_68 . integer . V_70 = V_71 ;
return 0 ;
}
static int F_30 ( struct V_29 * V_30 ,
struct V_14 * V_72 , int V_17 )
{
if ( V_72 -> V_17 != V_17 )
return - 1 ;
return V_73 ;
}
static void F_31 ( struct V_29 * V_74 ,
struct V_14 * V_72 ,
unsigned int * V_30 , int V_17 )
{
int V_66 = 0 ;
int V_43 ;
for ( V_43 = 7 ; V_43 >= 0 ; V_43 -- ) {
int V_51 = V_72 -> V_19 [ V_43 ] ;
if ( ! V_51 )
continue;
V_30 [ V_66 ++ ] = F_19 ( V_51 ) ;
}
F_16 ( V_66 != V_17 ) ;
}
static int F_32 ( int V_22 )
{
int V_12 ;
int V_18 = V_27 [ 0 ] ;
for ( V_12 = 0 ; V_12 < F_8 ( V_27 ) ; V_12 ++ ) {
if ( V_22 & ( 1 << V_12 ) )
V_18 |= V_27 [ V_12 ] ;
}
return V_18 ;
}
static int F_33 ( struct V_58 * V_59 , int V_75 ,
unsigned int V_76 , unsigned int T_2 * V_77 )
{
struct V_62 * V_63 = F_29 ( V_59 ) ;
struct V_29 * V_30 = V_63 -> V_64 ;
int V_78 = V_59 -> V_79 ;
unsigned int T_2 * V_80 ;
int V_10 , V_66 = 0 ;
unsigned long V_81 ;
int type ;
int V_22 , V_18 ;
if ( V_76 < 8 )
return - V_82 ;
if ( F_34 ( V_83 , V_77 ) )
return - V_84 ;
V_76 -= 8 ;
V_80 = V_77 + 2 ;
V_22 = V_30 -> V_31 . V_85 ( V_30 -> V_33 , V_78 ) ;
V_18 = F_32 ( V_22 ) ;
V_81 = F_35 ( V_18 ) ;
for ( V_10 = 2 ; V_10 <= V_81 ; V_10 ++ ) {
int V_12 ;
struct V_14 * V_72 ;
V_72 = V_16 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_16 ) ; V_12 ++ , V_72 ++ ) {
int V_86 = V_10 * 4 ;
unsigned int V_87 [ 8 ] ;
if ( V_72 -> V_17 != V_10 )
continue;
if ( ! ( V_72 -> V_18 == ( V_18 & V_72 -> V_18 ) ) )
continue;
type = V_30 -> V_31 . V_88 (
V_30 , V_72 , V_10 ) ;
if ( type < 0 )
return - V_89 ;
if ( V_76 < 8 )
return - V_82 ;
if ( F_34 ( type , V_80 ) ||
F_34 ( V_86 , V_80 + 1 ) )
return - V_84 ;
V_80 += 2 ;
V_76 -= 8 ;
V_66 += 8 ;
if ( V_76 < V_86 )
return - V_82 ;
V_76 -= V_86 ;
V_66 += V_86 ;
V_30 -> V_31 . V_90 ( V_30 , V_72 ,
V_87 , V_10 ) ;
if ( F_36 ( V_80 , V_87 , V_86 ) )
return - V_84 ;
V_80 += V_10 ;
}
}
if ( F_34 ( V_66 , V_77 + 1 ) )
return - V_84 ;
return 0 ;
}
static int F_37 ( struct V_58 * V_59 ,
struct V_91 * V_92 )
{
struct V_62 * V_63 = F_29 ( V_59 ) ;
struct V_29 * V_30 = V_63 -> V_64 ;
int V_78 = V_59 -> V_79 ;
unsigned char V_93 [ 8 ] ;
int V_12 ;
memset ( V_93 , 0 , sizeof( V_93 ) ) ;
V_30 -> V_31 . V_94 ( V_30 -> V_33 , V_78 , V_93 ) ;
for ( V_12 = 0 ; V_12 < sizeof( V_30 ) ; V_12 ++ )
V_92 -> V_68 . integer . V_68 [ V_12 ] = V_93 [ V_12 ] ;
return 0 ;
}
static int F_38 ( struct V_58 * V_59 ,
struct V_91 * V_92 )
{
struct V_62 * V_63 = F_29 ( V_59 ) ;
struct V_29 * V_74 = V_63 -> V_64 ;
int V_78 = V_59 -> V_79 ;
unsigned int V_95 ;
struct V_96 * V_97 ;
unsigned char V_30 [ 8 ] , V_98 [ 8 ] ;
int V_12 , V_36 , V_20 , V_99 = 0 ;
if ( ! V_74 -> V_31 . V_100 ( V_74 -> V_33 , V_78 ) )
return 0 ;
V_95 = F_39 ( V_59 , & V_92 -> V_101 ) ;
V_97 = F_40 ( V_63 , V_95 ) ;
if ( ! V_97 || ! V_97 -> V_102 )
return 0 ;
switch ( V_97 -> V_102 -> V_103 -> V_104 ) {
case V_105 :
case V_106 :
break;
case V_107 :
V_99 = 1 ;
break;
default:
return - V_108 ;
}
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_30 ) ; V_12 ++ )
V_30 [ V_12 ] = V_92 -> V_68 . integer . V_68 [ V_12 ] ;
V_74 -> V_31 . V_94 ( V_74 -> V_33 , V_78 , V_98 ) ;
if ( ! memcmp ( V_30 , V_98 , sizeof( V_30 ) ) )
return 0 ;
V_20 = F_21 ( F_8 ( V_30 ) , V_30 ) ;
if ( V_20 < 0 )
return - V_56 ;
if ( V_74 -> V_31 . V_109 ) {
V_36 = V_74 -> V_31 . V_109 ( V_74 , V_20 ,
F_8 ( V_30 ) , V_30 ) ;
if ( V_36 )
return V_36 ;
}
V_74 -> V_31 . V_110 ( V_74 -> V_33 , V_78 , V_30 , V_99 ) ;
return 0 ;
}
void F_41 ( struct V_1 * V_33 ,
struct V_29 * V_30 )
{
V_30 -> V_31 = V_111 ;
V_30 -> V_33 = V_33 ;
F_7 () ;
}
int F_42 ( struct V_112 * V_113 , int V_78 ,
struct V_29 * V_74 )
{
struct V_62 * V_30 ;
struct V_58 * V_114 ;
int V_36 , V_12 ;
V_36 = F_43 ( V_113 ,
V_115 ,
NULL , 0 , V_78 , & V_30 ) ;
if ( V_36 < 0 )
return V_36 ;
V_30 -> V_64 = V_74 ;
V_114 = V_30 -> V_114 ;
for ( V_12 = 0 ; V_12 < V_114 -> V_66 ; V_12 ++ )
V_114 -> V_116 [ V_12 ] . V_117 |= V_118 ;
V_114 -> V_63 = F_28 ;
V_114 -> V_119 = F_37 ;
V_114 -> V_120 = F_38 ;
V_114 -> V_77 . V_43 = F_33 ;
return 0 ;
}
