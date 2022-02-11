static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
int V_5 , V_6 , V_7 , V_8 [ 8 ] ;
T_1 V_9 ;
T_2 V_10 [ 4 ] , V_11 [ 5 ] , V_12 , V_13 [ 8 ] , V_14 [ 4 ] ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
V_10 [ 0 ] = ( ( V_4 [ 4 ] & 0xff ) >> 0 ) | ( ( V_4 [ 5 ] & 0x03 ) << 8 ) ;
V_10 [ 1 ] = ( ( V_4 [ 5 ] & 0xfc ) >> 2 ) | ( ( V_4 [ 2 ] & 0x0f ) << 6 ) ;
V_10 [ 2 ] = ( ( V_4 [ 2 ] & 0xf0 ) >> 4 ) | ( ( V_4 [ 3 ] & 0x3f ) << 4 ) ;
V_10 [ 3 ] = ( ( V_4 [ 3 ] & 0xc0 ) >> 6 ) | ( ( V_4 [ 0 ] & 0xff ) << 2 ) ;
V_9 = V_4 [ 1 ] ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
V_11 [ V_5 ] = V_10 [ 0 ] ;
for ( V_6 = 1 ; V_6 < V_15 ; V_6 ++ ) {
if ( V_10 [ V_6 ] == 0 )
continue;
V_12 = V_2 -> V_16 [ V_10 [ V_6 ] ] ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
V_11 [ V_5 ] ^= V_2 -> V_17 [ F_2 ( V_2 , V_12 + ( V_18 + V_5 ) * V_6 ) ] ;
}
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_11 [ V_5 ] )
V_14 [ V_5 ] = F_2 ( V_2 , V_2 -> V_16 [ V_11 [ V_5 ] ] + ( V_19 - V_18 - V_5 ) ) ;
}
V_7 = F_3 ( V_2 , NULL , NULL , 1019 , V_14 , 0 , V_8 , 0 , V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
int V_20 , V_21 , V_22 = 1015 - V_8 [ V_5 ] ;
T_1 V_23 ;
if ( V_22 >= V_24 && V_22 < 1019 )
continue;
if ( V_22 < V_24 ) {
V_22 = 10 * ( V_24 - 1 - V_22 ) - 6 ;
V_20 = ( V_22 >> 3 ) ^ 1 ;
V_21 = V_22 & 7 ;
if ( ( V_20 >= 0 && V_20 < V_25 ) || V_20 == ( V_25 + 1 ) ) {
V_23 = ( T_1 ) ( V_13 [ V_5 ] >> ( 2 + V_21 ) ) ;
V_9 ^= V_23 ;
if ( V_20 < V_25 )
V_3 [ V_20 ] ^= V_23 ;
}
V_20 = ( ( V_22 >> 3 ) + 1 ) ^ 1 ;
V_21 = ( V_21 + 10 ) & 7 ;
if ( V_21 == 0 )
V_21 = 8 ;
if ( ( V_20 >= 0 && V_20 < V_25 ) || V_20 == ( V_25 + 1 ) ) {
V_23 = ( T_1 ) ( V_13 [ V_5 ] << ( 8 - V_21 ) ) ;
V_9 ^= V_23 ;
if ( V_20 < V_25 )
V_3 [ V_20 ] ^= V_23 ;
}
}
}
return V_9 ? - V_26 : V_7 ;
}
static void F_4 ( struct V_27 * V_28 , unsigned short V_29 )
{
volatile char V_30 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
if ( F_5 ( V_28 ) )
V_30 = F_6 ( V_28 -> V_31 , V_32 ) ;
else if ( F_7 ( V_28 ) )
V_30 = F_6 ( V_28 -> V_31 , V_33 ) ;
else
V_30 = F_6 ( V_28 -> V_31 , V_34 ) ;
}
}
static int F_8 ( struct V_27 * V_28 )
{
void T_3 * V_35 = V_28 -> V_31 ;
unsigned long V_36 = V_37 + ( V_38 * 10 ) ;
if ( V_39 )
F_9 ( L_1 ) ;
if ( F_7 ( V_28 ) ) {
while ( ( F_6 ( V_35 , V_40 ) & V_41 ) != V_41 ) {
if ( F_10 ( V_37 , V_36 ) ) {
F_9 ( L_2 ) ;
return - V_42 ;
}
F_11 ( 1 ) ;
F_12 () ;
}
} else {
while ( ! ( F_6 ( V_35 , V_43 ) & V_44 ) ) {
if ( F_10 ( V_37 , V_36 ) ) {
F_9 ( L_2 ) ;
return - V_42 ;
}
F_11 ( 1 ) ;
F_12 () ;
}
}
return 0 ;
}
static inline int F_13 ( struct V_27 * V_28 )
{
void T_3 * V_35 = V_28 -> V_31 ;
int V_45 = 0 ;
if ( F_7 ( V_28 ) ) {
F_4 ( V_28 , 4 ) ;
if ( ( F_6 ( V_35 , V_40 ) & V_41 ) != V_41 )
V_45 = F_8 ( V_28 ) ;
} else {
F_4 ( V_28 , 4 ) ;
if ( ! ( F_6 ( V_35 , V_43 ) & V_44 ) )
V_45 = F_8 ( V_28 ) ;
F_4 ( V_28 , 2 ) ;
}
if ( V_39 )
F_9 ( L_3 ) ;
return V_45 ;
}
static void F_14 ( struct V_46 * V_47 , T_4 V_48 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
if ( V_39 )
F_9 ( L_4 , V_48 ) ;
F_15 ( V_48 , V_35 , V_52 ) ;
F_15 ( V_48 , V_35 , 2k_CDSN_IO ) ;
}
static T_4 F_16 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
T_4 V_45 ;
F_6 ( V_35 , V_52 ) ;
F_4 ( V_28 , 2 ) ;
V_45 = F_6 ( V_35 , 2k_CDSN_IO ) ;
if ( V_39 )
F_9 ( L_5 , V_45 ) ;
return V_45 ;
}
static void F_17 ( struct V_46 * V_47 , const T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
if ( V_39 )
F_9 ( L_6 , V_54 ) ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ ) {
F_18 ( V_53 [ V_5 ] , V_35 , V_55 + V_5 ) ;
if ( V_39 && V_5 < 16 )
F_9 ( L_7 , V_53 [ V_5 ] ) ;
}
if ( V_39 )
F_9 ( L_8 ) ;
}
static void F_19 ( struct V_46 * V_47 , T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
if ( V_39 )
F_9 ( L_9 , V_54 ) ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ ) {
V_53 [ V_5 ] = F_6 ( V_35 , 2k_CDSN_IO + V_5 ) ;
}
}
static void F_20 ( struct V_46 * V_47 , T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
if ( V_39 )
F_9 ( L_10 , V_54 ) ;
if ( F_21 ( ( ( ( unsigned long ) V_53 ) | V_54 ) & 3 ) ) {
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ ) {
* ( T_1 * ) ( & V_53 [ V_5 ] ) = F_6 ( V_35 , 2k_CDSN_IO + V_5 ) ;
}
} else {
for ( V_5 = 0 ; V_5 < V_54 ; V_5 += 4 ) {
* ( V_56 * ) ( & V_53 [ V_5 ] ) = F_22 ( V_35 + V_55 + V_5 ) ;
}
}
}
static int F_23 ( struct V_46 * V_47 , const T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ )
if ( V_53 [ V_5 ] != F_6 ( V_35 , 2k_CDSN_IO ) )
return - V_57 ;
return 0 ;
}
static T_2 T_5 F_24 ( struct V_46 * V_47 , int V_58 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
T_2 V_45 ;
F_25 ( V_47 , V_58 ) ;
F_26 ( V_47 , V_59 ,
V_60 | V_61 ) ;
F_26 ( V_47 , 0 , V_62 | V_61 ) ;
F_26 ( V_47 , V_63 , V_64 | V_61 ) ;
F_11 ( 50 ) ;
V_45 = V_50 -> V_65 ( V_47 ) << 8 ;
V_45 |= V_50 -> V_65 ( V_47 ) ;
if ( V_28 -> V_66 == V_67 && V_68 && ! V_58 ) {
union {
V_56 V_69 ;
T_1 V_70 [ 4 ] ;
} V_71 ;
void T_3 * V_35 = V_28 -> V_31 ;
F_26 ( V_47 , V_59 ,
V_60 | V_61 ) ;
F_26 ( V_47 , 0 , V_62 | V_61 ) ;
F_26 ( V_47 , V_63 ,
V_64 | V_61 ) ;
F_11 ( 50 ) ;
V_71 . V_69 = F_22 ( V_35 + V_55 ) ;
if ( ( ( V_71 . V_70 [ 0 ] << 8 ) | V_71 . V_70 [ 1 ] ) == V_45 ) {
F_9 ( V_72 L_11 ) ;
V_50 -> V_73 = & F_20 ;
}
}
return V_45 ;
}
static void T_5 F_27 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
T_2 V_74 ;
int V_5 ;
V_28 -> V_75 = 4 ;
V_74 = F_24 ( V_47 , 0 ) ;
for ( V_5 = 1 ; V_5 < 4 ; V_5 ++ ) {
if ( F_24 ( V_47 , V_5 ) != V_74 )
break;
}
V_28 -> V_75 = V_5 ;
F_9 ( V_76 L_12 , V_5 ) ;
}
static int F_28 ( struct V_46 * V_47 , struct V_49 * V_50 )
{
struct V_27 * V_28 = V_50 -> V_51 ;
int V_77 ;
F_13 ( V_28 ) ;
V_50 -> V_78 ( V_47 , V_79 , - 1 , - 1 ) ;
F_13 ( V_28 ) ;
V_77 = ( int ) V_50 -> V_65 ( V_47 ) ;
return V_77 ;
}
static void F_29 ( struct V_46 * V_47 , T_4 V_48 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
F_15 ( V_48 , V_35 , V_52 ) ;
F_15 ( V_48 , V_35 , V_80 ) ;
F_15 ( V_48 , V_35 , V_81 ) ;
}
static T_4 F_30 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
F_4 ( V_28 , 2 ) ;
F_6 ( V_35 , V_82 ) ;
return F_6 ( V_35 , V_83 ) ;
}
static void F_31 ( struct V_46 * V_47 , const T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ )
F_18 ( V_53 [ V_5 ] , V_35 , V_84 + V_5 ) ;
F_15 ( 0x00 , V_35 , V_81 ) ;
}
static void F_32 ( struct V_46 * V_47 , T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
F_6 ( V_35 , V_82 ) ;
for ( V_5 = 0 ; V_5 < V_54 - 1 ; V_5 ++ )
V_53 [ V_5 ] = F_6 ( V_35 , V_80 + ( V_5 & 0xff ) ) ;
V_53 [ V_5 ] = F_6 ( V_35 , V_83 ) ;
}
static int F_33 ( struct V_46 * V_47 , const T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
F_6 ( V_35 , V_82 ) ;
for ( V_5 = 0 ; V_5 < V_54 - 1 ; V_5 ++ )
if ( V_53 [ V_5 ] != F_6 ( V_35 , V_80 ) ) {
F_6 ( V_35 , V_83 ) ;
return V_5 ;
}
if ( V_53 [ V_5 ] != F_6 ( V_35 , V_83 ) )
return V_5 ;
return 0 ;
}
static T_4 F_34 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
T_4 V_45 ;
F_6 ( V_35 , V_85 ) ;
F_6 ( V_35 , V_85 ) ;
V_45 = F_6 ( V_35 , V_86 ) ;
if ( V_39 )
F_9 ( L_5 , V_45 ) ;
return V_45 ;
}
static void F_35 ( struct V_46 * V_47 , const T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
if ( V_39 )
F_9 ( L_6 , V_54 ) ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ ) {
F_18 ( V_53 [ V_5 ] , V_35 , V_84 + V_5 ) ;
if ( V_39 && V_5 < 16 )
F_9 ( L_7 , V_53 [ V_5 ] ) ;
}
if ( V_39 )
F_9 ( L_8 ) ;
}
static void F_36 ( struct V_46 * V_47 , T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
if ( V_39 )
F_9 ( L_9 , V_54 ) ;
F_6 ( V_35 , V_85 ) ;
F_6 ( V_35 , V_85 ) ;
for ( V_5 = 0 ; V_5 < V_54 - 2 ; V_5 ++ ) {
V_53 [ V_5 ] = F_6 ( V_35 , V_80 ) ;
if ( V_39 && V_5 < 16 )
F_9 ( L_7 , V_53 [ V_5 ] ) ;
}
V_53 [ V_54 - 2 ] = F_6 ( V_35 , V_86 ) ;
if ( V_39 && V_5 < 16 )
F_9 ( L_7 , V_53 [ V_54 - 2 ] ) ;
V_53 [ V_54 - 1 ] = F_6 ( V_35 , V_86 ) ;
if ( V_39 && V_5 < 16 )
F_9 ( L_7 , V_53 [ V_54 - 1 ] ) ;
if ( V_39 )
F_9 ( L_8 ) ;
}
static int F_37 ( struct V_46 * V_47 , const T_4 * V_53 , int V_54 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
if ( V_39 )
F_9 ( L_13 , V_54 ) ;
F_6 ( V_35 , V_85 ) ;
F_6 ( V_35 , V_85 ) ;
for ( V_5 = 0 ; V_5 < V_54 - 2 ; V_5 ++ )
if ( V_53 [ V_5 ] != F_6 ( V_35 , V_80 ) ) {
F_6 ( V_35 , V_86 ) ;
F_6 ( V_35 , V_86 ) ;
return V_5 ;
}
if ( V_53 [ V_54 - 2 ] != F_6 ( V_35 , V_86 ) )
return V_54 - 2 ;
if ( V_53 [ V_54 - 1 ] != F_6 ( V_35 , V_86 ) )
return V_54 - 1 ;
return 0 ;
}
static void F_38 ( struct V_46 * V_47 , int V_87 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int floor = 0 ;
if ( V_39 )
F_9 ( L_14 , V_87 ) ;
if ( V_87 == - 1 ) {
F_15 ( 0 , V_35 , V_88 ) ;
return;
}
floor = V_87 / V_28 -> V_75 ;
V_87 -= ( floor * V_28 -> V_75 ) ;
F_15 ( ( V_89 ) , V_35 , V_88 ) ;
V_50 -> V_78 ( V_47 , V_90 , - 1 , - 1 ) ;
V_28 -> V_91 = V_87 ;
V_28 -> V_92 = floor ;
}
static void F_25 ( struct V_46 * V_47 , int V_87 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int floor = 0 ;
if ( V_39 )
F_9 ( L_14 , V_87 ) ;
if ( V_87 == - 1 )
return;
floor = V_87 / V_28 -> V_75 ;
V_87 -= ( floor * V_28 -> V_75 ) ;
F_26 ( V_47 , V_63 , 0 | V_61 ) ;
F_15 ( floor , V_35 , V_93 ) ;
F_15 ( V_87 , V_35 , V_94 ) ;
F_26 ( V_47 , V_63 , V_64 | V_61 ) ;
V_28 -> V_91 = V_87 ;
V_28 -> V_92 = floor ;
}
static void F_26 ( struct V_46 * V_47 , int V_95 ,
unsigned int V_96 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
if ( V_96 & V_61 ) {
V_28 -> V_43 &= ~ V_97 ;
V_28 -> V_43 |= V_96 & V_97 ;
if ( V_39 )
F_9 ( L_15 , V_95 , V_28 -> V_43 ) ;
F_15 ( V_28 -> V_43 , V_35 , V_43 ) ;
F_4 ( V_28 , 4 ) ;
}
if ( V_95 != V_63 ) {
if ( F_39 ( V_28 ) )
F_14 ( V_47 , V_95 ) ;
else
F_29 ( V_47 , V_95 ) ;
}
}
static void F_40 ( struct V_46 * V_47 , unsigned V_98 , int V_99 , int V_100 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
if ( V_98 == V_101 ) {
F_15 ( 0x00 , V_35 , V_102 ) ;
F_15 ( 0x00 , V_35 , V_102 ) ;
}
if ( V_98 == V_103 ) {
int V_104 ;
if ( V_99 >= V_47 -> V_105 ) {
V_99 -= V_47 -> V_105 ;
V_104 = V_106 ;
} else if ( V_99 < 256 ) {
V_104 = V_107 ;
} else {
V_99 -= 256 ;
V_104 = V_108 ;
}
F_15 ( V_104 , V_35 , V_109 ) ;
}
F_15 ( V_98 , V_35 , V_109 ) ;
F_15 ( 0 , V_35 , V_102 ) ;
F_15 ( 0 , V_35 , V_102 ) ;
if ( V_99 != - 1 || V_100 != - 1 ) {
if ( V_99 != - 1 ) {
if ( V_50 -> V_110 & V_111 )
V_99 >>= 1 ;
F_15 ( V_99 , V_35 , V_112 ) ;
}
if ( V_100 != - 1 ) {
F_15 ( ( unsigned char ) ( V_100 & 0xff ) , V_35 , V_112 ) ;
F_15 ( ( unsigned char ) ( ( V_100 >> 8 ) & 0xff ) , V_35 , V_112 ) ;
if ( V_50 -> V_113 & 0x0c000000 ) {
F_15 ( ( unsigned char ) ( ( V_100 >> 16 ) & 0x0f ) , V_35 , V_112 ) ;
F_9 ( L_16 ) ;
}
}
F_15 ( 0 , V_35 , V_102 ) ;
F_15 ( 0 , V_35 , V_102 ) ;
if ( V_98 == V_107 || V_98 == V_108 ||
V_98 == V_106 || V_98 == V_59 )
F_15 ( 0 , V_35 , V_40 ) ;
}
switch ( V_98 ) {
case V_101 :
case V_114 :
case V_115 :
case V_103 :
case V_79 :
return;
case V_90 :
if ( V_50 -> V_116 )
break;
F_11 ( V_50 -> V_117 ) ;
F_15 ( V_79 , V_35 , V_109 ) ;
F_15 ( 0 , V_35 , V_102 ) ;
F_15 ( 0 , V_35 , V_102 ) ;
while ( ! ( V_50 -> V_65 ( V_47 ) & 0x40 ) ) ;
return;
default:
if ( ! V_50 -> V_116 ) {
F_11 ( V_50 -> V_117 ) ;
return;
}
}
F_41 ( 100 ) ;
while ( ! V_50 -> V_116 ( V_47 ) ) ;
}
static int F_42 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
if ( F_7 ( V_28 ) ) {
F_4 ( V_28 , 4 ) ;
if ( ( F_6 ( V_35 , V_40 ) & V_41 ) != V_41 ) {
if ( V_39 )
F_9 ( L_17 ) ;
return 0 ;
}
if ( V_39 )
F_9 ( L_18 ) ;
return 1 ;
} else {
F_4 ( V_28 , 4 ) ;
if ( ! ( F_6 ( V_35 , V_43 ) & V_44 ) ) {
if ( V_39 )
F_9 ( L_17 ) ;
return 0 ;
}
F_4 ( V_28 , 2 ) ;
if ( V_39 )
F_9 ( L_18 ) ;
return 1 ;
}
}
static int F_43 ( struct V_46 * V_47 , T_6 V_118 , int V_119 )
{
return 0 ;
}
static void F_44 ( struct V_46 * V_47 , int V_120 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
switch ( V_120 ) {
case V_121 :
F_15 ( V_122 , V_35 , V_123 ) ;
F_15 ( V_124 , V_35 , V_123 ) ;
break;
case V_125 :
F_15 ( V_122 , V_35 , V_123 ) ;
F_15 ( V_124 | V_126 , V_35 , V_123 ) ;
break;
}
}
static void F_45 ( struct V_46 * V_47 , int V_120 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
switch ( V_120 ) {
case V_121 :
F_15 ( V_122 , V_35 , V_127 ) ;
F_15 ( V_124 , V_35 , V_127 ) ;
break;
case V_125 :
F_15 ( V_122 , V_35 , V_127 ) ;
F_15 ( V_124 | V_126 , V_35 , V_127 ) ;
break;
}
}
static int F_46 ( struct V_46 * V_47 , const T_4 * V_128 , unsigned char * V_129 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
int V_5 ;
int V_130 = 1 ;
if ( F_39 ( V_28 ) ) {
F_15 ( V_28 -> V_43 & ~ V_131 , V_35 , V_43 ) ;
F_15 ( 0 , V_35 , 2k_CDSN_IO ) ;
F_15 ( 0 , V_35 , 2k_CDSN_IO ) ;
F_15 ( 0 , V_35 , 2k_CDSN_IO ) ;
F_15 ( V_28 -> V_43 , V_35 , V_43 ) ;
} else if ( F_7 ( V_28 ) ) {
F_15 ( 0 , V_35 , V_33 ) ;
F_15 ( 0 , V_35 , V_33 ) ;
F_15 ( 0 , V_35 , V_33 ) ;
} else {
F_15 ( 0 , V_35 , V_32 ) ;
F_15 ( 0 , V_35 , V_32 ) ;
F_15 ( 0 , V_35 , V_32 ) ;
}
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( F_7 ( V_28 ) )
V_129 [ V_5 ] = F_47 ( V_35 , V_132 + V_5 ) ;
else
V_129 [ V_5 ] = F_47 ( V_35 , V_133 + V_5 ) ;
if ( V_129 [ V_5 ] != V_134 [ V_5 ] )
V_130 = 0 ;
}
if ( F_7 ( V_28 ) )
F_15 ( V_135 , V_35 , V_127 ) ;
else
F_15 ( V_135 , V_35 , V_123 ) ;
#if 0
if (emptymatch) {
for (i = 0; i < 512; i++) {
if (dat[i] == 0xff)
continue;
emptymatch = 0;
break;
}
}
if (emptymatch)
memset(ecc_code, 0xff, 6);
#endif
return 0 ;
}
static int F_48 ( struct V_46 * V_47 , T_4 * V_128 ,
T_4 * V_136 , T_4 * V_137 )
{
int V_5 , V_45 = 0 ;
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
void T_3 * V_35 = V_28 -> V_31 ;
T_1 V_138 [ 6 ] ;
volatile T_4 V_30 ;
int V_130 = 1 ;
if ( F_39 ( V_28 ) ) {
V_30 = F_6 ( V_35 , 2k_ECCStatus ) ;
V_30 = F_6 ( V_35 , 2k_ECCStatus ) ;
V_30 = F_6 ( V_35 , 2k_ECCStatus ) ;
} else if ( F_7 ( V_28 ) ) {
V_30 = F_6 ( V_35 , V_127 ) ;
V_30 = F_6 ( V_35 , V_127 ) ;
V_30 = F_6 ( V_35 , V_127 ) ;
} else {
V_30 = F_6 ( V_35 , V_123 ) ;
V_30 = F_6 ( V_35 , V_123 ) ;
V_30 = F_6 ( V_35 , V_123 ) ;
}
if ( V_30 & 0x80 ) {
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( F_7 ( V_28 ) )
V_138 [ V_5 ] = F_47 ( V_35 , V_132 + V_5 ) ;
else
V_138 [ V_5 ] = F_47 ( V_35 , V_133 + V_5 ) ;
if ( V_138 [ V_5 ] != V_139 [ V_5 ] )
V_130 = 0 ;
}
if ( V_130 ) {
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( V_136 [ V_5 ] == 0xff )
continue;
V_130 = 0 ;
break;
}
}
if ( V_130 ) {
for ( V_5 = 0 ; V_5 < 512 ; V_5 ++ ) {
if ( V_128 [ V_5 ] == 0xff )
continue;
V_130 = 0 ;
break;
}
}
if ( ! V_130 )
V_45 = F_1 ( V_140 , V_128 , V_138 ) ;
if ( V_45 > 0 )
F_9 ( V_141 L_19 , V_45 ) ;
}
if ( F_7 ( V_28 ) )
F_15 ( V_135 , V_35 , V_127 ) ;
else
F_15 ( V_135 , V_35 , V_123 ) ;
if ( V_142 && ( V_45 == - V_26 ) ) {
F_9 ( V_141 L_20 ) ;
V_45 = 0 ;
}
return V_45 ;
}
static int T_5 F_49 ( struct V_46 * V_47 , T_4 * V_53 , const char * V_143 , int V_144 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
unsigned V_145 ;
int V_45 ;
T_7 V_146 ;
for ( V_145 = 0 ; V_145 < V_47 -> V_147 ; V_145 += V_47 -> V_148 ) {
V_45 = V_47 -> V_149 ( V_47 , V_145 , V_47 -> V_105 , & V_146 , V_53 ) ;
if ( V_146 != V_47 -> V_105 )
continue;
if ( V_45 ) {
F_9 ( V_150 L_21 , V_145 ) ;
}
if ( memcmp ( V_53 , V_143 , 6 ) )
continue;
F_9 ( V_72 L_22 , V_143 , V_145 ) ;
if ( V_28 -> V_151 == - 1 ) {
V_28 -> V_151 = V_145 >> V_50 -> V_152 ;
if ( ! V_144 )
return 1 ;
continue;
}
V_28 -> V_153 = V_145 >> V_50 -> V_152 ;
return 2 ;
}
if ( V_28 -> V_151 == - 1 ) {
F_9 ( V_150 L_23 , V_143 ) ;
return 0 ;
}
V_145 = V_28 -> V_151 << V_50 -> V_152 ;
V_45 = V_47 -> V_149 ( V_47 , V_145 , V_47 -> V_105 , & V_146 , V_53 ) ;
if ( V_146 != V_47 -> V_105 ) {
F_9 ( V_141 L_24 ) ;
return 0 ;
}
return 1 ;
}
static inline int T_5 F_50 ( struct V_46 * V_47 , struct V_154 * V_155 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
int V_45 = 0 ;
T_4 * V_53 ;
struct V_156 * V_157 ;
const unsigned V_158 = 1 << V_50 -> V_152 ;
int V_159 = 0 ;
unsigned V_160 , V_161 ;
int V_145 , V_162 ;
V_53 = F_51 ( V_47 -> V_105 , V_163 ) ;
if ( ! V_53 ) {
F_9 ( V_141 L_25 ) ;
return 0 ;
}
if ( ! ( V_162 = F_49 ( V_47 , V_53 , L_26 , 1 ) ) )
goto V_164;
V_157 = (struct V_156 * ) V_53 ;
F_52 ( & V_157 -> V_165 ) ;
F_52 ( & V_157 -> V_166 ) ;
F_53 ( & V_157 -> V_167 ) ;
F_9 ( V_72 L_27
L_28
L_29
L_30
L_31 ,
V_157 -> V_168 , V_157 -> V_165 ,
V_157 -> V_166 , V_157 -> V_167 ,
V_157 -> V_169 ) ;
V_160 = V_47 -> V_147 >> V_50 -> V_170 ;
V_161 = F_54 ( 32768U , V_47 -> V_148 - V_158 ) ;
if ( V_157 -> V_169 == 0x00 ) {
V_157 -> V_169 = 0xff ;
while ( V_160 > V_161 ) {
V_160 >>= 1 ;
V_161 = F_54 ( 32768U , ( V_161 << 1 ) + V_158 ) ;
V_157 -> V_169 -- ;
}
F_9 ( V_150 L_32 , V_157 -> V_169 ) ;
}
if ( V_157 -> V_169 != 0xff ) {
V_50 -> V_171 += ( 0xff - V_157 -> V_169 ) ;
V_47 -> V_148 <<= ( 0xff - V_157 -> V_169 ) ;
F_9 ( V_72 L_33 , V_47 -> V_148 ) ;
V_160 = V_47 -> V_147 >> V_50 -> V_171 ;
V_161 = F_54 ( 32768U , V_47 -> V_148 - V_158 ) ;
}
if ( V_160 > V_161 ) {
F_9 ( V_141 L_34 , V_157 -> V_169 ) ;
goto V_164;
}
V_145 = F_55 ( V_28 -> V_151 , V_28 -> V_153 ) ;
V_145 <<= V_50 -> V_152 ;
V_145 += V_47 -> V_148 ;
if ( V_172 == 1 ) {
V_155 [ 0 ] . V_173 = L_35 ;
V_155 [ 0 ] . V_174 = 0 ;
V_155 [ 0 ] . V_147 = V_145 ;
V_159 = 1 ;
}
V_155 [ V_159 ] . V_173 = L_36 ;
V_155 [ V_159 ] . V_174 = V_145 ;
V_155 [ V_159 ] . V_147 = ( V_157 -> V_165 - V_162 ) << V_50 -> V_171 ;
V_145 += V_155 [ V_159 ] . V_147 ;
V_159 ++ ;
if ( V_145 < V_47 -> V_147 ) {
V_155 [ V_159 ] . V_173 = L_37 ;
V_155 [ V_159 ] . V_174 = V_145 ;
V_155 [ V_159 ] . V_147 = V_47 -> V_147 - V_145 ;
V_159 ++ ;
}
V_45 = V_159 ;
V_164:
F_56 ( V_53 ) ;
return V_45 ;
}
static inline int T_5 F_57 ( struct V_46 * V_47 , struct V_154 * V_155 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
int V_45 = 0 ;
T_4 * V_53 ;
struct V_175 * V_157 ;
struct V_176 * V_177 ;
int V_159 = 0 ;
int V_160 ;
int V_178 , V_179 = 0 ;
int V_5 ;
int V_180 = V_47 -> V_147 ;
if ( V_181 )
V_180 -= ( V_182 << V_50 -> V_170 ) ;
V_53 = F_51 ( V_47 -> V_105 , V_163 ) ;
if ( ! V_53 ) {
F_9 ( V_141 L_25 ) ;
return 0 ;
}
if ( ! F_49 ( V_47 , V_53 , L_38 , 0 ) )
goto V_164;
V_28 -> V_153 = V_28 -> V_151 + ( 4096 >> V_50 -> V_152 ) ;
V_157 = (struct V_175 * ) V_53 ;
F_53 ( & V_157 -> V_183 ) ;
F_53 ( & V_157 -> V_184 ) ;
F_53 ( & V_157 -> V_185 ) ;
F_53 ( & V_157 -> V_186 ) ;
F_53 ( & V_157 -> V_187 ) ;
F_53 ( & V_157 -> V_188 ) ;
F_9 ( V_72 L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46 ,
V_157 -> V_189 , V_157 -> V_183 ,
V_157 -> V_184 ,
V_157 -> V_185 ,
V_157 -> V_186 , V_157 -> V_187 ,
( ( unsigned char * ) & V_157 -> V_190 ) [ 0 ] & 0xf ,
( ( unsigned char * ) & V_157 -> V_190 ) [ 1 ] & 0xf ,
( ( unsigned char * ) & V_157 -> V_190 ) [ 2 ] & 0xf ,
( ( unsigned char * ) & V_157 -> V_190 ) [ 3 ] & 0xf ,
V_157 -> V_188 ) ;
V_178 = V_50 -> V_170 + V_157 -> V_186 ;
V_160 = V_47 -> V_147 >> V_178 ;
if ( V_160 > 32768 ) {
F_9 ( V_141 L_47 , V_157 -> V_186 ) ;
goto V_164;
}
V_160 = V_28 -> V_75 << ( V_50 -> V_191 - V_50 -> V_170 ) ;
if ( V_181 && ( V_160 > V_47 -> V_148 ) ) {
F_9 ( V_141 L_48 ) ;
goto V_164;
}
for ( V_5 = 0 ; ( V_5 < 4 ) ; V_5 ++ ) {
V_177 = & ( V_157 -> V_192 [ V_5 ] ) ;
F_53 ( & V_177 -> V_193 ) ;
F_53 ( & V_177 -> V_194 ) ;
F_53 ( & V_177 -> V_195 ) ;
F_53 ( & V_177 -> V_196 ) ;
F_53 ( & V_177 -> V_197 ) ;
F_53 ( & V_177 -> V_198 ) ;
F_9 ( V_72 L_49
L_50
L_51
L_52
L_53
L_54 ,
V_5 , V_177 -> V_193 , V_177 -> V_194 ,
V_177 -> V_195 , V_177 -> V_196 ,
V_177 -> V_197 ) ;
if ( ( V_172 == 1 ) &&
( V_5 == 0 ) && ( V_177 -> V_194 > 0 ) ) {
V_155 [ 0 ] . V_173 = L_55 ;
V_155 [ 0 ] . V_174 = 0 ;
V_155 [ 0 ] . V_147 = V_47 -> V_148 * V_177 -> V_194 ;
V_159 = 1 ;
}
if ( V_177 -> V_196 & V_199 )
V_155 [ V_159 ] . V_173 = L_56 ;
else
V_155 [ V_159 ] . V_173 = L_36 ;
V_155 [ V_159 ] . V_174 = V_177 -> V_194 << V_178 ;
V_155 [ V_159 ] . V_147 = ( 1 + V_177 -> V_195 - V_177 -> V_194 ) << V_178 ;
V_159 ++ ;
if ( V_177 -> V_195 > V_179 )
V_179 = V_177 -> V_195 ;
if ( V_177 -> V_196 & V_200 )
break;
}
V_179 ++ ;
if ( ( V_179 << V_178 ) < V_180 ) {
V_155 [ V_159 ] . V_173 = L_37 ;
V_155 [ V_159 ] . V_174 = V_179 << V_178 ;
V_155 [ V_159 ] . V_147 = V_180 - V_155 [ V_159 ] . V_174 ;
V_159 ++ ;
}
V_45 = V_159 ;
V_164:
F_56 ( V_53 ) ;
return V_45 ;
}
static int T_5 F_58 ( struct V_46 * V_47 )
{
int V_45 , V_159 ;
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
struct V_154 V_155 [ 2 ] ;
memset ( ( char * ) V_155 , 0 , sizeof( V_155 ) ) ;
V_159 = F_50 ( V_47 , V_155 ) ;
if ( ! V_159 )
return - V_42 ;
V_50 -> V_201 -> V_110 = V_202 | V_203 |
V_204 | V_205 |
V_206 ;
V_50 -> V_201 -> V_207 = 7 ;
V_50 -> V_201 -> V_208 [ 0 ] = V_28 -> V_151 + 1 ;
if ( V_28 -> V_153 != - 1 ) {
V_50 -> V_209 -> V_110 = V_202 | V_203 |
V_204 | V_205 |
V_206 ;
V_50 -> V_209 -> V_207 = 7 ;
V_50 -> V_209 -> V_208 [ 0 ] = V_28 -> V_153 + 1 ;
} else {
V_50 -> V_209 = NULL ;
}
if ( ( V_45 = F_59 ( V_47 , NULL ) ) )
return V_45 ;
F_60 ( V_47 , NULL , 0 ) ;
if ( ! V_210 )
F_60 ( V_47 , V_155 , V_159 ) ;
return 0 ;
}
static int T_5 F_61 ( struct V_46 * V_47 )
{
int V_45 , V_159 ;
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
struct V_154 V_155 [ 5 ] ;
if ( V_50 -> V_211 > V_28 -> V_75 ) {
F_9 ( V_141 L_57 ) ;
return - V_42 ;
}
if ( F_7 ( V_28 ) ) {
V_50 -> V_201 -> V_110 = V_212 | V_202 ;
if ( V_181 )
V_50 -> V_201 -> V_110 |= V_205 ;
V_50 -> V_201 -> V_208 [ 0 ] = 2 ;
V_50 -> V_209 = NULL ;
} else {
V_50 -> V_201 -> V_110 = V_213 | V_203 | V_206 ;
if ( V_181 )
V_50 -> V_201 -> V_110 |= V_205 ;
V_50 -> V_201 -> V_145 = 8 ;
V_50 -> V_201 -> V_54 = 8 ;
V_50 -> V_201 -> V_207 = 7 ;
V_50 -> V_201 -> V_161 = V_182 ;
V_50 -> V_201 -> V_214 = 0x01 ;
V_50 -> V_201 -> V_215 = L_58 ;
V_50 -> V_209 -> V_110 = V_213 | V_203 | V_206 ;
if ( V_181 )
V_50 -> V_209 -> V_110 |= V_205 ;
V_50 -> V_209 -> V_145 = 8 ;
V_50 -> V_209 -> V_54 = 8 ;
V_50 -> V_209 -> V_207 = 7 ;
V_50 -> V_209 -> V_161 = V_182 ;
V_50 -> V_209 -> V_214 = 0x01 ;
V_50 -> V_209 -> V_215 = L_59 ;
}
if ( ( V_45 = F_59 ( V_47 , NULL ) ) )
return V_45 ;
memset ( ( char * ) V_155 , 0 , sizeof( V_155 ) ) ;
V_159 = F_57 ( V_47 , V_155 ) ;
if ( ! V_159 )
return - V_42 ;
F_60 ( V_47 , NULL , 0 ) ;
if ( ! V_210 )
F_60 ( V_47 , V_155 , V_159 ) ;
return 0 ;
}
static inline int T_5 F_62 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
V_50 -> V_65 = F_16 ;
V_50 -> V_216 = F_17 ;
V_50 -> V_73 = F_19 ;
V_50 -> V_217 = F_23 ;
V_50 -> V_218 = F_58 ;
V_28 -> V_43 = V_131 | V_219 ;
F_27 ( V_47 ) ;
V_47 -> V_173 = L_60 ;
return ( 4 * V_28 -> V_75 ) ;
}
static inline int T_5 F_63 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
V_50 -> V_65 = F_30 ;
V_50 -> V_216 = F_31 ;
V_50 -> V_73 = F_32 ;
V_50 -> V_217 = F_33 ;
F_6 ( V_28 -> V_31 , V_66 ) ;
F_6 ( V_28 -> V_31 , V_66 ) ;
F_6 ( V_28 -> V_31 , V_66 ) ;
if ( F_6 ( V_28 -> V_31 , V_66 ) != V_220 ) {
F_27 ( V_47 ) ;
V_47 -> V_173 = L_61 ;
V_50 -> V_218 = F_61 ;
return ( 4 * V_28 -> V_75 ) ;
} else {
V_28 -> V_75 = 1 ;
V_47 -> V_173 = L_62 ;
V_50 -> V_218 = F_58 ;
return 1 ;
}
}
static inline int T_5 F_64 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_27 * V_28 = V_50 -> V_51 ;
V_50 -> V_65 = F_34 ;
V_50 -> V_216 = F_35 ;
V_50 -> V_73 = F_36 ;
V_50 -> V_217 = F_37 ;
V_50 -> V_218 = F_61 ;
V_50 -> V_221 = NULL ;
V_50 -> V_222 = F_38 ;
V_50 -> V_78 = F_40 ;
V_50 -> V_4 . V_223 = F_45 ;
V_28 -> V_75 = 1 ;
V_47 -> V_173 = L_63 ;
return 1 ;
}
static int T_5 F_65 ( unsigned long V_224 )
{
unsigned char V_66 ;
struct V_46 * V_47 ;
struct V_49 * V_225 ;
struct V_27 * V_28 ;
void T_3 * V_31 ;
unsigned char V_226 ;
unsigned char V_12 , V_227 , V_228 ;
int V_229 , V_54 , V_211 ;
int V_45 = 0 ;
V_31 = F_66 ( V_224 , V_230 ) ;
if ( ! V_31 ) {
F_9 ( V_141 L_64 , V_230 , V_224 ) ;
return - V_42 ;
}
V_226 = F_6 ( V_31 , V_231 ) ;
F_15 ( V_232 | V_233 | V_234 , V_31 , V_231 ) ;
F_15 ( V_232 | V_233 | V_234 , V_31 , V_231 ) ;
F_15 ( V_232 | V_233 | V_235 , V_31 , V_231 ) ;
F_15 ( V_232 | V_233 | V_235 , V_31 , V_231 ) ;
V_66 = F_6 ( V_31 , V_66 ) ;
switch ( V_66 ) {
case V_67 :
V_229 = V_236 ;
break;
case V_220 :
V_229 = V_237 ;
break;
case V_238 :
case V_239 :
case 0 :
for ( V_12 = 0 ; ( V_12 < 4 ) ; V_12 ++ )
F_6 ( V_31 , V_240 ) ;
V_12 = V_234 | V_233 | V_241 | V_242 ;
F_15 ( V_12 , V_31 , V_243 ) ;
F_15 ( ~ V_12 , V_31 , V_244 ) ;
F_67 ( 1 ) ;
V_12 = V_235 | V_233 | V_241 | V_242 ;
F_15 ( V_12 , V_31 , V_243 ) ;
F_15 ( ~ V_12 , V_31 , V_244 ) ;
F_67 ( 1 ) ;
V_66 = F_6 ( V_31 , V_66 ) ;
switch ( V_66 ) {
case V_238 :
V_229 = V_245 ;
break;
case V_239 :
F_9 ( V_141 L_65 ) ;
default:
V_45 = - V_246 ;
goto V_247;
}
break;
default:
V_45 = - V_246 ;
goto V_247;
}
V_12 = F_47 ( V_31 , V_229 ) & V_248 ;
V_227 = F_47 ( V_31 , V_229 ) & V_248 ;
V_228 = F_47 ( V_31 , V_229 ) & V_248 ;
if ( ( V_12 == V_227 ) || ( V_12 != V_228 ) ) {
F_9 ( V_150 L_66 , V_224 ) ;
V_45 = - V_246 ;
goto V_247;
}
for ( V_47 = V_249 ; V_47 ; V_47 = V_28 -> V_250 ) {
unsigned char V_251 ;
unsigned char V_252 ;
V_225 = V_47 -> V_51 ;
V_28 = V_225 -> V_51 ;
if ( V_66 == V_238 ) {
V_251 = F_6 ( V_28 -> V_31 , V_253 ) ;
V_252 = F_6 ( V_31 , V_253 ) ;
} else {
V_251 = F_6 ( V_28 -> V_31 , V_254 ) ;
V_252 = F_6 ( V_31 , V_254 ) ;
}
if ( V_251 != V_252 )
continue;
if ( V_66 == V_238 ) {
F_15 ( ~ V_252 , V_31 , V_253 ) ;
V_251 = F_6 ( V_28 -> V_31 , V_253 ) ;
F_15 ( V_252 , V_31 , V_253 ) ;
} else {
F_15 ( ~ V_252 , V_31 , V_254 ) ;
V_251 = F_6 ( V_28 -> V_31 , V_254 ) ;
F_15 ( V_252 , V_31 , V_254 ) ;
}
V_252 = ~ V_252 ;
if ( V_251 == V_252 ) {
F_9 ( V_76 L_67 , V_28 -> V_224 , V_224 ) ;
goto V_247;
}
}
F_9 ( V_255 L_68 , V_224 ) ;
V_54 = sizeof( struct V_46 ) +
sizeof( struct V_49 ) + sizeof( struct V_27 ) + ( 2 * sizeof( struct V_256 ) ) ;
V_47 = F_68 ( V_54 , V_163 ) ;
if ( ! V_47 ) {
F_9 ( V_141 L_69 , V_54 ) ;
V_45 = - V_257 ;
goto V_258;
}
V_225 = (struct V_49 * ) ( V_47 + 1 ) ;
V_28 = (struct V_27 * ) ( V_225 + 1 ) ;
V_225 -> V_201 = (struct V_256 * ) ( V_28 + 1 ) ;
V_225 -> V_209 = V_225 -> V_201 + 1 ;
V_47 -> V_51 = V_225 ;
V_47 -> V_259 = V_260 ;
V_225 -> V_51 = V_28 ;
V_225 -> V_222 = F_25 ;
V_225 -> V_221 = F_26 ;
V_225 -> V_116 = F_42 ;
V_225 -> V_261 = F_28 ;
V_225 -> V_262 = F_43 ;
V_225 -> V_4 . V_223 = F_44 ;
V_225 -> V_4 . V_263 = F_46 ;
V_225 -> V_4 . V_264 = F_48 ;
V_225 -> V_4 . V_265 = & V_266 ;
V_225 -> V_4 . V_120 = V_267 ;
V_225 -> V_4 . V_147 = 512 ;
V_225 -> V_4 . V_268 = 6 ;
V_225 -> V_110 = V_269 ;
V_28 -> V_224 = V_224 ;
V_28 -> V_31 = V_31 ;
V_28 -> V_66 = V_66 ;
V_28 -> V_92 = - 1 ;
V_28 -> V_91 = - 1 ;
V_28 -> V_151 = - 1 ;
V_28 -> V_153 = - 1 ;
V_28 -> V_250 = V_249 ;
if ( V_66 == V_67 )
V_211 = F_62 ( V_47 ) ;
else if ( V_66 == V_238 )
V_211 = F_64 ( V_47 ) ;
else
V_211 = F_63 ( V_47 ) ;
if ( ( V_45 = F_69 ( V_47 , V_211 ) ) ) {
F_70 ( V_47 ) ;
F_56 ( V_47 ) ;
goto V_258;
}
V_249 = V_47 ;
return 0 ;
V_247:
F_15 ( V_226 , V_31 , V_231 ) ;
V_258:
F_71 ( V_31 ) ;
return V_45 ;
}
static void F_72 ( void )
{
struct V_46 * V_47 , * V_270 ;
struct V_49 * V_225 ;
struct V_27 * V_28 ;
for ( V_47 = V_249 ; V_47 ; V_47 = V_270 ) {
V_225 = V_47 -> V_51 ;
V_28 = V_225 -> V_51 ;
V_270 = V_28 -> V_250 ;
F_70 ( V_47 ) ;
F_71 ( V_28 -> V_31 ) ;
F_56 ( V_47 ) ;
}
}
static int T_5 F_73 ( void )
{
int V_5 , V_45 = 0 ;
V_140 = F_74 ( 10 , 0x409 , V_18 , 1 , V_15 ) ;
if ( ! V_140 ) {
F_9 ( V_141 L_70 ) ;
return - V_257 ;
}
if ( V_271 ) {
F_9 ( V_72 L_71 , V_271 ) ;
V_45 = F_65 ( V_271 ) ;
if ( V_45 < 0 )
goto V_272;
} else {
for ( V_5 = 0 ; ( V_273 [ V_5 ] != 0xffffffff ) ; V_5 ++ ) {
F_65 ( V_273 [ V_5 ] ) ;
}
}
if ( ! V_249 ) {
F_9 ( V_72 L_72 ) ;
V_45 = - V_246 ;
goto V_272;
}
return 0 ;
V_272:
F_75 ( V_140 ) ;
return V_45 ;
}
static void T_8 F_76 ( void )
{
F_72 () ;
if ( V_140 ) {
F_75 ( V_140 ) ;
}
}
