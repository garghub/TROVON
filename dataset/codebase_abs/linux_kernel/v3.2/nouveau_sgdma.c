static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
struct V_4 * * V_5 , struct V_4 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
int V_12 ;
F_2 ( V_9 -> V_11 , L_1 , V_3 ) ;
V_9 -> V_5 = V_7 ;
V_9 -> V_13 = V_3 ;
V_9 -> V_14 = true ;
if ( 0 ) {
V_9 -> V_14 = false ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_3 ; V_12 ++ ) {
V_9 -> V_5 [ V_12 ] = F_3 ( V_11 -> V_15 , V_5 [ V_12 ] , 0 ,
V_16 , V_17 ) ;
if ( F_4 ( V_11 -> V_15 , V_9 -> V_5 [ V_12 ] ) ) {
V_9 -> V_13 = -- V_12 ;
V_2 -> V_18 -> V_19 ( V_2 ) ;
return - V_20 ;
}
}
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
if ( V_9 -> V_21 )
V_2 -> V_18 -> V_22 ( V_2 ) ;
if ( V_9 -> V_14 ) {
while ( V_9 -> V_13 -- ) {
F_6 ( V_11 -> V_15 , V_9 -> V_5 [ V_9 -> V_13 ] ,
V_16 , V_17 ) ;
}
V_9 -> V_14 = false ;
}
V_9 -> V_5 = NULL ;
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
if ( V_2 ) {
F_2 ( V_9 -> V_11 , L_2 ) ;
if ( V_9 ) {
if ( V_9 -> V_5 )
V_2 -> V_18 -> V_19 ( V_2 ) ;
F_8 ( V_9 ) ;
}
}
}
static int
F_9 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_28 * V_29 = V_26 -> V_30 . V_31 ;
unsigned V_12 , V_32 , V_33 ;
F_2 ( V_11 , L_3 , V_24 -> V_34 ) ;
V_9 -> V_35 = V_24 -> V_34 << V_36 ;
V_33 = ( V_9 -> V_35 >> V_37 ) + 2 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ ) {
T_1 V_38 = V_9 -> V_5 [ V_12 ] ;
T_2 V_39 = F_10 ( V_38 ) ;
for ( V_32 = 0 ; V_32 < V_16 / V_40 ; V_32 ++ , V_33 ++ ) {
F_11 ( V_29 , ( V_33 * 4 ) + 0 , V_39 | 3 ) ;
V_39 += V_40 ;
}
}
V_9 -> V_21 = true ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_28 * V_29 = V_26 -> V_30 . V_31 ;
unsigned V_12 , V_32 , V_33 ;
F_2 ( V_11 , L_2 ) ;
if ( ! V_9 -> V_21 )
return 0 ;
V_33 = ( V_9 -> V_35 >> V_37 ) + 2 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ ) {
for ( V_32 = 0 ; V_32 < V_16 / V_40 ; V_32 ++ , V_33 ++ )
F_11 ( V_29 , ( V_33 * 4 ) + 0 , 0x00000000 ) ;
}
V_9 -> V_21 = false ;
return 0 ;
}
static void
F_13 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_14 ( V_11 , 0x100810 , 0x00000022 ) ;
if ( ! F_15 ( V_11 , 0x100810 , 0x00000100 , 0x00000100 ) )
F_16 ( V_11 , L_4 ,
F_17 ( V_11 , 0x100810 ) ) ;
F_14 ( V_11 , 0x100810 , 0x00000000 ) ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_25 * V_26 = V_9 -> V_11 -> V_27 ;
struct V_28 * V_41 = V_26 -> V_30 . V_31 ;
T_1 * V_42 = V_9 -> V_5 ;
T_3 V_33 = V_24 -> V_34 << 2 ;
T_3 V_43 = V_9 -> V_13 ;
V_9 -> V_35 = V_24 -> V_34 << V_36 ;
while ( V_43 -- ) {
F_11 ( V_41 , V_33 , ( * V_42 ++ >> 7 ) | 1 ) ;
V_33 += 4 ;
}
F_13 ( V_9 ) ;
V_9 -> V_21 = true ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_25 * V_26 = V_9 -> V_11 -> V_27 ;
struct V_28 * V_41 = V_26 -> V_30 . V_31 ;
T_3 V_33 = ( V_9 -> V_35 >> 12 ) << 2 ;
T_3 V_43 = V_9 -> V_13 ;
while ( V_43 -- ) {
F_11 ( V_41 , V_33 , 0x00000000 ) ;
V_33 += 4 ;
}
F_13 ( V_9 ) ;
V_9 -> V_21 = false ;
return 0 ;
}
static void
F_20 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_14 ( V_11 , 0x100814 , ( V_9 -> V_13 - 1 ) << 12 ) ;
F_14 ( V_11 , 0x100808 , V_9 -> V_35 | 0x20 ) ;
if ( ! F_15 ( V_11 , 0x100808 , 0x00000001 , 0x00000001 ) )
F_16 ( V_11 , L_5 ,
F_17 ( V_11 , 0x100808 ) ) ;
F_14 ( V_11 , 0x100808 , 0x00000000 ) ;
}
static void
F_21 ( struct V_28 * V_41 , T_1 * V_42 , T_3 V_44 , T_3 V_43 )
{
struct V_25 * V_26 = V_41 -> V_11 -> V_27 ;
T_1 V_45 = V_26 -> V_30 . V_45 . V_46 ;
T_3 V_33 , V_47 [ 4 ] ;
V_33 = V_44 >> 2 ;
V_44 &= ~ 0x0000000f ;
V_47 [ 0 ] = F_22 ( V_41 , V_44 + 0x0 ) ;
V_47 [ 1 ] = F_22 ( V_41 , V_44 + 0x4 ) ;
V_47 [ 2 ] = F_22 ( V_41 , V_44 + 0x8 ) ;
V_47 [ 3 ] = F_22 ( V_41 , V_44 + 0xc ) ;
while ( V_43 -- ) {
T_3 V_46 = V_42 ? ( * V_42 ++ >> 12 ) : ( V_45 >> 12 ) ;
switch ( V_33 ++ & 0x3 ) {
case 0 :
V_47 [ 0 ] &= ~ 0x07ffffff ;
V_47 [ 0 ] |= V_46 ;
break;
case 1 :
V_47 [ 0 ] &= ~ 0xf8000000 ;
V_47 [ 0 ] |= V_46 << 27 ;
V_47 [ 1 ] &= ~ 0x003fffff ;
V_47 [ 1 ] |= V_46 >> 5 ;
break;
case 2 :
V_47 [ 1 ] &= ~ 0xffc00000 ;
V_47 [ 1 ] |= V_46 << 22 ;
V_47 [ 2 ] &= ~ 0x0001ffff ;
V_47 [ 2 ] |= V_46 >> 10 ;
break;
case 3 :
V_47 [ 2 ] &= ~ 0xfffe0000 ;
V_47 [ 2 ] |= V_46 << 17 ;
V_47 [ 3 ] &= ~ 0x00000fff ;
V_47 [ 3 ] |= V_46 >> 15 ;
break;
}
}
V_47 [ 3 ] |= 0x40000000 ;
F_11 ( V_41 , V_44 + 0x0 , V_47 [ 0 ] ) ;
F_11 ( V_41 , V_44 + 0x4 , V_47 [ 1 ] ) ;
F_11 ( V_41 , V_44 + 0x8 , V_47 [ 2 ] ) ;
F_11 ( V_41 , V_44 + 0xc , V_47 [ 3 ] ) ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_25 * V_26 = V_9 -> V_11 -> V_27 ;
struct V_28 * V_41 = V_26 -> V_30 . V_31 ;
T_1 * V_42 = V_9 -> V_5 ;
T_3 V_33 = V_24 -> V_34 << 2 , V_47 [ 4 ] ;
T_3 V_43 = V_9 -> V_13 ;
int V_12 ;
V_9 -> V_35 = V_24 -> V_34 << V_36 ;
if ( V_33 & 0x0000000c ) {
T_3 V_48 = 4 - ( ( V_33 >> 2 ) & 0x3 ) ;
T_3 V_49 = ( V_43 > V_48 ) ? V_48 : V_43 ;
F_21 ( V_41 , V_42 , V_33 , V_49 ) ;
V_33 += ( V_49 << 2 ) ;
V_42 += V_49 ;
V_43 -= V_49 ;
}
while ( V_43 >= 4 ) {
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_47 [ V_12 ] = * V_42 ++ >> 12 ;
F_11 ( V_41 , V_33 + 0x0 , V_47 [ 0 ] >> 0 | V_47 [ 1 ] << 27 ) ;
F_11 ( V_41 , V_33 + 0x4 , V_47 [ 1 ] >> 5 | V_47 [ 2 ] << 22 ) ;
F_11 ( V_41 , V_33 + 0x8 , V_47 [ 2 ] >> 10 | V_47 [ 3 ] << 17 ) ;
F_11 ( V_41 , V_33 + 0xc , V_47 [ 3 ] >> 15 | 0x40000000 ) ;
V_33 += 0x10 ;
V_43 -= 4 ;
}
if ( V_43 )
F_21 ( V_41 , V_42 , V_33 , V_43 ) ;
F_20 ( V_9 ) ;
V_9 -> V_21 = true ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_25 * V_26 = V_9 -> V_11 -> V_27 ;
struct V_28 * V_41 = V_26 -> V_30 . V_31 ;
T_3 V_33 = ( V_9 -> V_35 >> 12 ) << 2 ;
T_3 V_43 = V_9 -> V_13 ;
if ( V_33 & 0x0000000c ) {
T_3 V_48 = 4 - ( ( V_33 >> 2 ) & 0x3 ) ;
T_3 V_49 = ( V_43 > V_48 ) ? V_48 : V_43 ;
F_21 ( V_41 , NULL , V_33 , V_49 ) ;
V_33 += ( V_49 << 2 ) ;
V_43 -= V_49 ;
}
while ( V_43 >= 4 ) {
F_11 ( V_41 , V_33 + 0x0 , 0x00000000 ) ;
F_11 ( V_41 , V_33 + 0x4 , 0x00000000 ) ;
F_11 ( V_41 , V_33 + 0x8 , 0x00000000 ) ;
F_11 ( V_41 , V_33 + 0xc , 0x00000000 ) ;
V_33 += 0x10 ;
V_43 -= 4 ;
}
if ( V_43 )
F_21 ( V_41 , NULL , V_33 , V_43 ) ;
F_20 ( V_9 ) ;
V_9 -> V_21 = false ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_50 * V_51 = V_24 -> V_52 ;
V_51 -> V_5 = V_9 -> V_5 ;
V_9 -> V_5 = ( T_1 * ) V_51 ;
V_9 -> V_21 = true ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_50 * V_51 = (struct V_50 * ) V_9 -> V_5 ;
V_9 -> V_5 = V_51 -> V_5 ;
V_51 -> V_5 = NULL ;
V_9 -> V_21 = false ;
return 0 ;
}
struct V_1 *
F_27 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_8 * V_9 ;
V_9 = F_28 ( sizeof( * V_9 ) , V_53 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_11 = V_11 ;
V_9 -> V_54 . V_18 = V_26 -> V_30 . V_18 ;
return & V_9 -> V_54 ;
}
int
F_29 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_28 * V_29 = NULL ;
T_3 V_55 , V_56 ;
int V_57 ;
if ( V_26 -> V_58 >= V_59 && F_30 ( V_11 -> V_15 ) )
V_55 = 512 * 1024 * 1024 ;
else
V_55 = 64 * 1024 * 1024 ;
V_26 -> V_30 . V_45 . V_4 = F_31 ( V_60 | V_53 ) ;
if ( ! V_26 -> V_30 . V_45 . V_4 )
return - V_61 ;
V_26 -> V_30 . V_45 . V_46 =
F_3 ( V_11 -> V_15 , V_26 -> V_30 . V_45 . V_4 ,
0 , V_16 , V_17 ) ;
if ( F_4 ( V_11 -> V_15 , V_26 -> V_30 . V_45 . V_46 ) ) {
F_16 ( V_11 , L_6 ) ;
F_32 ( V_26 -> V_30 . V_45 . V_4 ) ;
V_26 -> V_30 . V_45 . V_4 = NULL ;
return - V_61 ;
}
if ( V_26 -> V_58 >= V_62 ) {
V_26 -> V_30 . V_63 = 0 ;
V_26 -> V_30 . V_55 = V_55 ;
V_26 -> V_30 . type = V_64 ;
V_26 -> V_30 . V_18 = & V_65 ;
} else
if ( 0 && F_30 ( V_11 -> V_15 ) &&
V_26 -> V_66 > 0x40 && V_26 -> V_66 != 0x45 ) {
if ( F_33 ( V_11 ) ) {
V_26 -> V_30 . V_18 = & V_67 ;
V_56 = 512 * 1024 ;
} else {
V_26 -> V_30 . V_18 = & V_68 ;
V_56 = 16 ;
}
V_57 = F_34 ( V_11 , NULL , V_55 / 1024 , V_56 ,
V_69 |
V_70 , & V_29 ) ;
if ( V_57 ) {
F_16 ( V_11 , L_7 , V_57 ) ;
return V_57 ;
}
V_26 -> V_30 . V_31 = V_29 ;
V_26 -> V_30 . V_63 = 0 ;
V_26 -> V_30 . V_55 = V_55 ;
V_26 -> V_30 . type = V_64 ;
} else {
V_57 = F_34 ( V_11 , NULL , ( V_55 / 1024 ) + 8 , 16 ,
V_69 |
V_70 , & V_29 ) ;
if ( V_57 ) {
F_16 ( V_11 , L_7 , V_57 ) ;
return V_57 ;
}
F_11 ( V_29 , 0 , V_71 |
( 1 << 12 ) |
( 0 << 13 ) |
( 0 << 14 ) |
( 2 << 16 ) ) ;
F_11 ( V_29 , 4 , V_55 - 1 ) ;
V_26 -> V_30 . V_31 = V_29 ;
V_26 -> V_30 . V_63 = 0 ;
V_26 -> V_30 . V_55 = V_55 ;
V_26 -> V_30 . type = V_72 ;
V_26 -> V_30 . V_18 = & V_73 ;
}
return 0 ;
}
void
F_35 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_11 -> V_27 ;
F_36 ( NULL , & V_26 -> V_30 . V_31 ) ;
if ( V_26 -> V_30 . V_45 . V_4 ) {
F_6 ( V_11 -> V_15 , V_26 -> V_30 . V_45 . V_46 ,
V_16 , V_17 ) ;
F_32 ( V_26 -> V_30 . V_45 . V_4 ) ;
V_26 -> V_30 . V_45 . V_4 = NULL ;
}
}
T_2
F_37 ( struct V_10 * V_11 , T_2 V_35 )
{
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_28 * V_29 = V_26 -> V_30 . V_31 ;
int V_33 = ( V_35 >> V_37 ) + 2 ;
F_38 ( V_26 -> V_58 >= V_62 ) ;
return ( F_22 ( V_29 , 4 * V_33 ) & ~ V_74 ) |
( V_35 & V_74 ) ;
}
