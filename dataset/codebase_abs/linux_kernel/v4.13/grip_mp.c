static int F_1 ( T_1 V_1 )
{
int V_2 = V_1 ^ ( V_1 >> 16 ) ;
V_2 ^= V_2 >> 8 ;
V_2 ^= V_2 >> 4 ;
V_2 ^= V_2 >> 2 ;
V_2 ^= V_2 >> 1 ;
return V_2 & 1 ;
}
static inline int F_2 ( T_2 V_3 , T_2 V_4 , int V_5 , struct V_6 * V_7 , T_2 * V_8 )
{
int V_9 , V_10 ;
V_10 = F_3 ( V_7 , V_5 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
* V_8 = F_4 ( V_7 ) ;
if ( ( * V_8 & V_3 ) == V_3 &&
( ~ ( * V_8 ) & V_4 ) == V_4 )
return 1 ;
}
F_5 ( L_1 , V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_6 , int V_11 , int V_12 , T_1 * V_13 )
{
T_2 V_14 ;
T_2 V_15 ;
T_1 V_1 ;
int V_16 ;
int V_17 = 0 ;
int V_9 ;
* V_13 = 0 ;
V_14 = F_4 ( V_6 ) ;
if ( V_14 & 1 )
return V_18 ;
for ( V_9 = 0 ; V_9 < 64 ; V_9 ++ ) {
V_14 = F_4 ( V_6 ) ;
V_17 |= 1 << ( ( V_14 >> 4 ) & 3 ) ;
}
if ( V_17 == 1 ) {
V_14 = F_4 ( V_6 ) ;
V_17 = V_14 & 0xf0 ;
if ( V_14 & 0x31 )
return V_19 ;
F_7 ( V_6 ) ;
if ( ! F_2 ( 0x10 , 0 , 308 , V_6 , & V_14 ) )
return V_19 ;
} else
return V_18 ;
if ( V_14 & 0x20 ) {
V_17 |= V_14 >> 4 ;
if ( V_17 != 0xb )
return 0 ;
V_15 = 7 ;
V_16 = 3 ;
V_1 = ( V_20 | V_21 ) >> 28 ;
} else {
V_15 = 1 ;
V_16 = 1 ;
V_1 = ( V_20 | V_22 ) >> 28 ;
}
while ( 1 ) {
if ( ! F_2 ( 0 , 0x10 , 77 , V_6 , & V_14 ) )
return V_19 ;
V_14 = ( V_14 >> 5 ) & V_15 ;
if ( V_1 & V_20 )
break;
V_1 = ( V_1 << V_16 ) | V_14 ;
if ( ! F_2 ( 0x10 , 0 , 77 , V_6 , & V_14 ) )
return V_19 ;
}
if ( V_14 )
return V_19 ;
if ( V_16 == 3 ) {
V_1 = ( V_1 & 0xffff0000 ) | ( ( V_1 << 1 ) & 0xffff ) ;
V_1 = ( V_1 >> 2 ) | 0xf0000000 ;
}
if ( F_1 ( V_1 ) == 1 )
return V_19 ;
if ( ! F_2 ( 0x30 , 0 , 77 , V_6 , & V_14 ) )
return V_19 ;
V_14 = F_4 ( V_6 ) ;
if ( V_14 & 1 )
return V_19 ;
F_7 ( V_6 ) ;
if ( ! F_2 ( 0 , 0x20 , 77 , V_6 , & V_14 ) )
return V_19 ;
* V_13 = V_1 ;
if ( ( V_11 == 0 ) || ( ( V_11 & V_18 ) && ! ( V_1 & V_23 ) ) )
return V_24 ;
if ( V_1 & V_25 )
return V_24 | V_18 ;
if ( ! F_2 ( 0x20 , 0 , 77 , V_6 , & V_14 ) )
return V_24 | V_19 ;
V_14 = F_4 ( V_6 ) ;
if ( V_14 & 1 )
return V_24 | V_19 ;
F_7 ( V_6 ) ;
do {
if ( ! F_2 ( 0x20 , 0x10 , 116 , V_6 , & V_14 ) )
return V_24 | V_19 ;
if ( ! F_2 ( 0x30 , 0 , 193 , V_6 , & V_14 ) )
return V_24 | V_19 ;
if ( V_14 & 1 )
return V_24 | V_19 ;
if ( V_12 & 1 )
F_7 ( V_6 ) ;
V_12 >>= 1 ;
} while ( V_12 );
return V_24 | V_26 ;
}
static int F_8 ( struct V_6 * V_6 , int V_11 , int V_12 , T_1 * V_13 )
{
int V_27 ;
unsigned long V_28 ;
F_9 ( V_28 ) ;
V_27 = F_6 ( V_6 , V_11 , V_12 , V_13 ) ;
F_10 ( V_28 ) ;
return V_27 ;
}
static int F_11 ( struct V_6 * V_6 , T_1 * V_13 )
{
int V_9 ;
int V_28 , V_29 = 0 , V_30 = 0 ;
for ( V_9 = 0 ; V_9 < F_12 ( V_31 ) ; V_9 ++ ) {
if ( V_31 [ V_9 ] )
F_7 ( V_6 ) ;
F_13 ( V_32 ) ;
}
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ )
F_13 ( V_32 ) ;
while ( V_29 < 64 && V_30 < 8 ) {
V_28 = F_8 ( V_6 , V_19 , 0x27 , V_13 ) ;
if ( V_28 & V_26 )
return 1 ;
if ( V_28 & V_18 )
V_29 ++ ;
else
V_30 ++ ;
}
return 0 ;
}
static int F_14 ( struct V_33 * V_34 , int V_28 )
{
struct V_35 * V_36 ;
T_1 V_13 ;
int V_37 = 0 ;
int V_38 ;
V_28 &= V_19 | V_18 ;
V_28 = F_8 ( V_34 -> V_6 , V_28 , 0 , & V_13 ) ;
V_34 -> V_39 ++ ;
if ( V_13 & V_23 )
V_28 |= V_40 ;
if ( V_28 && ! ( V_28 & V_24 ) ) {
V_34 -> V_30 ++ ;
return V_28 ;
}
V_38 = ( ( V_13 >> 21 ) & 0xf ) - 1 ;
if ( ( V_38 < 0 ) || ( V_38 > 3 ) )
return V_28 ;
V_36 = V_34 -> V_36 [ V_38 ] ;
V_37 = ( V_13 >> 16 ) & 0x1f ;
if ( ! V_37 ) {
if ( V_36 -> V_41 ) {
F_15 ( V_42 L_2 ,
V_43 [ V_36 -> V_44 ] , V_38 ) ;
F_16 ( V_36 -> V_45 ) ;
V_36 -> V_41 = 0 ;
}
F_5 ( L_3 , V_38 ) ;
V_36 -> V_44 = V_46 ;
V_28 |= V_47 ;
return V_28 ;
}
if ( V_37 == 0x1f ) {
int V_48 = ( V_13 >> 8 ) & 0xf ;
V_36 -> V_49 = ( ~ V_13 ) & 0xff ;
V_36 -> V_50 = ( ( V_51 [ V_48 ] >> 2 ) & 3 ) - 1 ;
V_36 -> V_52 = ( V_51 [ V_48 ] & 3 ) - 1 ;
V_36 -> V_53 = 1 ;
if ( V_36 -> V_44 == V_46 )
V_28 |= V_47 ;
V_36 -> V_44 = V_54 ;
if ( ! V_36 -> V_41 ) {
F_5 ( L_4 , V_38 ) ;
if ( F_17 ( V_38 , V_34 ) ) {
V_36 -> V_44 = V_46 ;
V_36 -> V_53 = 0 ;
}
}
return V_28 ;
}
{
static int V_55 = 0 ;
if ( V_55 != V_37 ) {
F_15 ( V_42 L_5 ) ;
F_15 ( V_42 L_6 , V_37 , V_13 ) ;
V_55 = V_37 ;
}
}
return V_28 ;
}
static int F_18 ( struct V_33 * V_34 )
{
int V_28 , V_38 , V_56 = 0 , V_57 = 0 ;
V_28 = F_14 ( V_34 , 0 ) ;
if ( ! ( V_28 & V_24 ) )
return 0 ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
if ( V_34 -> V_36 [ V_38 ] -> V_44 == V_46 )
V_56 = 1 ;
if ( V_34 -> V_36 [ V_38 ] -> V_44 != V_58 )
V_57 = 1 ;
}
if ( ! V_57 )
return ( V_28 & V_40 ) ? 1 : 0 ;
return V_56 ? 0 : 1 ;
}
static int F_19 ( struct V_33 * V_34 )
{
int V_59 , V_60 = 0 , V_29 = 0 ;
T_1 V_13 ;
V_59 = F_11 ( V_34 -> V_6 , & V_13 ) ;
while ( ! V_59 && V_29 < 4 ) {
V_59 = F_11 ( V_34 -> V_6 , & V_13 ) ;
V_29 ++ ;
}
if ( V_59 )
F_5 ( L_7 ) ;
else {
F_5 ( L_8 ) ;
return 0 ;
}
for ( V_29 = 0 ; V_29 < 4096 ; V_29 ++ ) {
if ( F_18 ( V_34 ) ) {
V_60 = 1 ;
break;
}
}
F_5 ( L_9 , V_60 ) ;
return V_60 ;
}
static void F_20 ( struct V_33 * V_34 , int V_38 )
{
struct V_35 * V_36 = V_34 -> V_36 [ V_38 ] ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
F_21 ( V_36 -> V_45 , V_61 [ V_9 ] , ( V_36 -> V_49 >> V_9 ) & 1 ) ;
F_22 ( V_36 -> V_45 , V_62 , V_36 -> V_52 ) ;
F_22 ( V_36 -> V_45 , V_63 , V_36 -> V_50 ) ;
F_23 ( V_36 -> V_45 ) ;
V_36 -> V_53 = 0 ;
}
static void F_24 ( struct V_6 * V_6 )
{
struct V_33 * V_34 = F_25 ( V_6 ) ;
int V_9 , V_64 , V_28 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
V_28 = V_18 ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
V_28 = F_14 ( V_34 , V_28 ) ;
if ( ( V_28 & V_24 ) || ! ( V_28 & V_18 ) )
break;
}
if ( V_28 & V_40 )
break;
}
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
if ( V_34 -> V_36 [ V_9 ] -> V_53 )
F_20 ( V_34 , V_9 ) ;
}
static int F_26 ( struct V_65 * V_45 )
{
struct V_33 * V_34 = F_27 ( V_45 ) ;
F_28 ( V_34 -> V_6 ) ;
return 0 ;
}
static void F_29 ( struct V_65 * V_45 )
{
struct V_33 * V_34 = F_27 ( V_45 ) ;
F_30 ( V_34 -> V_6 ) ;
}
static int F_17 ( int V_38 , struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_36 [ V_38 ] ;
struct V_65 * V_65 ;
int V_66 , V_67 ;
int V_68 ;
V_36 -> V_45 = V_65 = F_31 () ;
if ( ! V_65 )
return - V_69 ;
V_65 -> V_70 = V_43 [ V_36 -> V_44 ] ;
V_65 -> V_71 . V_72 = V_73 ;
V_65 -> V_71 . V_74 = V_75 ;
V_65 -> V_71 . V_76 = 0x0100 + V_36 -> V_44 ;
V_65 -> V_71 . V_77 = 0x0100 ;
V_65 -> V_45 . V_78 = & V_34 -> V_6 -> V_45 ;
F_32 ( V_65 , V_34 ) ;
V_65 -> V_79 = F_26 ;
V_65 -> V_80 = F_29 ;
V_65 -> V_81 [ 0 ] = F_33 ( V_82 ) | F_33 ( V_83 ) ;
for ( V_66 = 0 ; ( V_67 = V_84 [ V_36 -> V_44 ] [ V_66 ] ) >= 0 ; V_66 ++ )
F_34 ( V_65 , V_67 , - 1 , 1 , 0 , 0 ) ;
for ( V_66 = 0 ; ( V_67 = V_85 [ V_36 -> V_44 ] [ V_66 ] ) >= 0 ; V_66 ++ )
if ( V_67 > 0 )
F_35 ( V_67 , V_65 -> V_86 ) ;
V_68 = F_36 ( V_36 -> V_45 ) ;
if ( V_68 ) {
F_37 ( V_36 -> V_45 ) ;
return V_68 ;
}
V_36 -> V_41 = 1 ;
if ( V_36 -> V_53 )
F_20 ( V_34 , V_38 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_6 , struct V_87 * V_88 )
{
struct V_33 * V_34 ;
int V_68 ;
if ( ! ( V_34 = F_39 ( sizeof( struct V_33 ) , V_89 ) ) )
return - V_69 ;
V_34 -> V_6 = V_6 ;
F_40 ( V_6 , V_34 ) ;
V_68 = F_41 ( V_6 , V_88 , V_90 ) ;
if ( V_68 )
goto V_91;
F_42 ( V_6 , F_24 ) ;
F_43 ( V_6 , 20 ) ;
if ( ! F_19 ( V_34 ) ) {
V_68 = - V_92 ;
goto V_93;
}
if ( ! V_34 -> V_36 [ 0 ] -> V_44 && ! V_34 -> V_36 [ 1 ] -> V_44 && ! V_34 -> V_36 [ 2 ] -> V_44 && ! V_34 -> V_36 [ 3 ] -> V_44 ) {
V_68 = - V_92 ;
goto V_93;
}
return 0 ;
V_93: F_44 ( V_6 ) ;
V_91: F_40 ( V_6 , NULL ) ;
F_45 ( V_34 ) ;
return V_68 ;
}
static void F_46 ( struct V_6 * V_6 )
{
struct V_33 * V_34 = F_25 ( V_6 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
if ( V_34 -> V_36 [ V_9 ] -> V_41 )
F_16 ( V_34 -> V_36 [ V_9 ] -> V_45 ) ;
F_44 ( V_6 ) ;
F_40 ( V_6 , NULL ) ;
F_45 ( V_34 ) ;
}
