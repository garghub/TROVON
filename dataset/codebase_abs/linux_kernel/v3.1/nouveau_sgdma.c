static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
struct V_4 * * V_5 , struct V_4 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
F_2 ( V_9 -> V_11 , L_1 , V_3 ) ;
if ( V_9 -> V_5 )
return - V_12 ;
V_9 -> V_5 = F_3 ( sizeof( T_1 ) * V_3 , V_13 ) ;
if ( ! V_9 -> V_5 )
return - V_14 ;
V_9 -> V_15 = F_3 ( sizeof( bool ) * V_3 , V_13 ) ;
if ( ! V_9 -> V_15 ) {
F_4 ( V_9 -> V_5 ) ;
V_9 -> V_5 = NULL ;
return - V_14 ;
}
V_9 -> V_16 = 0 ;
while ( V_3 -- ) {
if ( 0 ) {
V_9 -> V_5 [ V_9 -> V_16 ] =
V_7 [ V_9 -> V_16 ] ;
V_9 -> V_15 [ V_9 -> V_16 ] = true ;
} else {
V_9 -> V_5 [ V_9 -> V_16 ] =
F_5 ( V_11 -> V_17 , V_5 [ V_9 -> V_16 ] , 0 ,
V_18 , V_19 ) ;
if ( F_6 ( V_11 -> V_17 ,
V_9 -> V_5 [ V_9 -> V_16 ] ) ) {
V_2 -> V_20 -> V_21 ( V_2 ) ;
return - V_22 ;
}
V_9 -> V_15 [ V_9 -> V_16 ] = false ;
}
V_9 -> V_16 ++ ;
}
return 0 ;
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 ;
if ( V_9 && V_9 -> V_5 ) {
V_11 = V_9 -> V_11 ;
F_2 ( V_11 , L_2 ) ;
if ( V_9 -> V_23 )
V_2 -> V_20 -> V_24 ( V_2 ) ;
while ( V_9 -> V_16 -- ) {
if ( ! V_9 -> V_15 [ V_9 -> V_16 ] )
F_8 ( V_11 -> V_17 , V_9 -> V_5 [ V_9 -> V_16 ] ,
V_18 , V_19 ) ;
}
F_4 ( V_9 -> V_5 ) ;
F_4 ( V_9 -> V_15 ) ;
V_9 -> V_5 = NULL ;
V_9 -> V_15 = NULL ;
V_9 -> V_16 = 0 ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
if ( V_2 ) {
F_2 ( V_9 -> V_11 , L_2 ) ;
if ( V_9 ) {
if ( V_9 -> V_5 )
V_2 -> V_20 -> V_21 ( V_2 ) ;
F_4 ( V_9 ) ;
}
}
}
static int
F_10 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_27 * V_28 = V_11 -> V_29 ;
struct V_30 * V_31 = V_28 -> V_32 . V_33 ;
unsigned V_34 , V_35 , V_36 ;
F_2 ( V_11 , L_3 , V_26 -> V_37 ) ;
V_9 -> V_38 = V_26 -> V_37 << V_39 ;
V_36 = ( V_9 -> V_38 >> V_40 ) + 2 ;
for ( V_34 = 0 ; V_34 < V_9 -> V_16 ; V_34 ++ ) {
T_1 V_41 = V_9 -> V_5 [ V_34 ] ;
T_2 V_42 = F_11 ( V_41 ) ;
for ( V_35 = 0 ; V_35 < V_18 / V_43 ; V_35 ++ , V_36 ++ ) {
F_12 ( V_31 , ( V_36 * 4 ) + 0 , V_42 | 3 ) ;
V_42 += V_43 ;
}
}
V_9 -> V_23 = true ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_27 * V_28 = V_11 -> V_29 ;
struct V_30 * V_31 = V_28 -> V_32 . V_33 ;
unsigned V_34 , V_35 , V_36 ;
F_2 ( V_11 , L_2 ) ;
if ( ! V_9 -> V_23 )
return 0 ;
V_36 = ( V_9 -> V_38 >> V_40 ) + 2 ;
for ( V_34 = 0 ; V_34 < V_9 -> V_16 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_18 / V_43 ; V_35 ++ , V_36 ++ )
F_12 ( V_31 , ( V_36 * 4 ) + 0 , 0x00000000 ) ;
}
V_9 -> V_23 = false ;
return 0 ;
}
static void
F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_15 ( V_11 , 0x100810 , 0x00000022 ) ;
if ( ! F_16 ( V_11 , 0x100810 , 0x00000100 , 0x00000100 ) )
F_17 ( V_11 , L_4 ,
F_18 ( V_11 , 0x100810 ) ) ;
F_15 ( V_11 , 0x100810 , 0x00000000 ) ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_27 * V_28 = V_9 -> V_11 -> V_29 ;
struct V_30 * V_44 = V_28 -> V_32 . V_33 ;
T_1 * V_45 = V_9 -> V_5 ;
T_3 V_36 = V_26 -> V_37 << 2 ;
T_3 V_46 = V_9 -> V_16 ;
V_9 -> V_38 = V_26 -> V_37 << V_39 ;
while ( V_46 -- ) {
F_12 ( V_44 , V_36 , ( * V_45 ++ >> 7 ) | 1 ) ;
V_36 += 4 ;
}
F_14 ( V_9 ) ;
V_9 -> V_23 = true ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_27 * V_28 = V_9 -> V_11 -> V_29 ;
struct V_30 * V_44 = V_28 -> V_32 . V_33 ;
T_3 V_36 = ( V_9 -> V_38 >> 12 ) << 2 ;
T_3 V_46 = V_9 -> V_16 ;
while ( V_46 -- ) {
F_12 ( V_44 , V_36 , 0x00000000 ) ;
V_36 += 4 ;
}
F_14 ( V_9 ) ;
V_9 -> V_23 = false ;
return 0 ;
}
static void
F_21 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_15 ( V_11 , 0x100814 , ( V_9 -> V_16 - 1 ) << 12 ) ;
F_15 ( V_11 , 0x100808 , V_9 -> V_38 | 0x20 ) ;
if ( ! F_16 ( V_11 , 0x100808 , 0x00000001 , 0x00000001 ) )
F_17 ( V_11 , L_5 ,
F_18 ( V_11 , 0x100808 ) ) ;
F_15 ( V_11 , 0x100808 , 0x00000000 ) ;
}
static void
F_22 ( struct V_30 * V_44 , T_1 * V_45 , T_3 V_47 , T_3 V_46 )
{
struct V_27 * V_28 = V_44 -> V_11 -> V_29 ;
T_1 V_48 = V_28 -> V_32 . V_48 . V_49 ;
T_3 V_36 , V_50 [ 4 ] ;
V_36 = V_47 >> 2 ;
V_47 &= ~ 0x0000000f ;
V_50 [ 0 ] = F_23 ( V_44 , V_47 + 0x0 ) ;
V_50 [ 1 ] = F_23 ( V_44 , V_47 + 0x4 ) ;
V_50 [ 2 ] = F_23 ( V_44 , V_47 + 0x8 ) ;
V_50 [ 3 ] = F_23 ( V_44 , V_47 + 0xc ) ;
while ( V_46 -- ) {
T_3 V_49 = V_45 ? ( * V_45 ++ >> 12 ) : ( V_48 >> 12 ) ;
switch ( V_36 ++ & 0x3 ) {
case 0 :
V_50 [ 0 ] &= ~ 0x07ffffff ;
V_50 [ 0 ] |= V_49 ;
break;
case 1 :
V_50 [ 0 ] &= ~ 0xf8000000 ;
V_50 [ 0 ] |= V_49 << 27 ;
V_50 [ 1 ] &= ~ 0x003fffff ;
V_50 [ 1 ] |= V_49 >> 5 ;
break;
case 2 :
V_50 [ 1 ] &= ~ 0xffc00000 ;
V_50 [ 1 ] |= V_49 << 22 ;
V_50 [ 2 ] &= ~ 0x0001ffff ;
V_50 [ 2 ] |= V_49 >> 10 ;
break;
case 3 :
V_50 [ 2 ] &= ~ 0xfffe0000 ;
V_50 [ 2 ] |= V_49 << 17 ;
V_50 [ 3 ] &= ~ 0x00000fff ;
V_50 [ 3 ] |= V_49 >> 15 ;
break;
}
}
V_50 [ 3 ] |= 0x40000000 ;
F_12 ( V_44 , V_47 + 0x0 , V_50 [ 0 ] ) ;
F_12 ( V_44 , V_47 + 0x4 , V_50 [ 1 ] ) ;
F_12 ( V_44 , V_47 + 0x8 , V_50 [ 2 ] ) ;
F_12 ( V_44 , V_47 + 0xc , V_50 [ 3 ] ) ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_27 * V_28 = V_9 -> V_11 -> V_29 ;
struct V_30 * V_44 = V_28 -> V_32 . V_33 ;
T_1 * V_45 = V_9 -> V_5 ;
T_3 V_36 = V_26 -> V_37 << 2 , V_50 [ 4 ] ;
T_3 V_46 = V_9 -> V_16 ;
int V_34 ;
V_9 -> V_38 = V_26 -> V_37 << V_39 ;
if ( V_36 & 0x0000000c ) {
T_3 V_51 = 4 - ( ( V_36 >> 2 ) & 0x3 ) ;
T_3 V_52 = ( V_46 > V_51 ) ? V_51 : V_46 ;
F_22 ( V_44 , V_45 , V_36 , V_52 ) ;
V_36 += ( V_52 << 2 ) ;
V_45 += V_52 ;
V_46 -= V_52 ;
}
while ( V_46 >= 4 ) {
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ )
V_50 [ V_34 ] = * V_45 ++ >> 12 ;
F_12 ( V_44 , V_36 + 0x0 , V_50 [ 0 ] >> 0 | V_50 [ 1 ] << 27 ) ;
F_12 ( V_44 , V_36 + 0x4 , V_50 [ 1 ] >> 5 | V_50 [ 2 ] << 22 ) ;
F_12 ( V_44 , V_36 + 0x8 , V_50 [ 2 ] >> 10 | V_50 [ 3 ] << 17 ) ;
F_12 ( V_44 , V_36 + 0xc , V_50 [ 3 ] >> 15 | 0x40000000 ) ;
V_36 += 0x10 ;
V_46 -= 4 ;
}
if ( V_46 )
F_22 ( V_44 , V_45 , V_36 , V_46 ) ;
F_21 ( V_9 ) ;
V_9 -> V_23 = true ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_27 * V_28 = V_9 -> V_11 -> V_29 ;
struct V_30 * V_44 = V_28 -> V_32 . V_33 ;
T_3 V_36 = ( V_9 -> V_38 >> 12 ) << 2 ;
T_3 V_46 = V_9 -> V_16 ;
if ( V_36 & 0x0000000c ) {
T_3 V_51 = 4 - ( ( V_36 >> 2 ) & 0x3 ) ;
T_3 V_52 = ( V_46 > V_51 ) ? V_51 : V_46 ;
F_22 ( V_44 , NULL , V_36 , V_52 ) ;
V_36 += ( V_52 << 2 ) ;
V_46 -= V_52 ;
}
while ( V_46 >= 4 ) {
F_12 ( V_44 , V_36 + 0x0 , 0x00000000 ) ;
F_12 ( V_44 , V_36 + 0x4 , 0x00000000 ) ;
F_12 ( V_44 , V_36 + 0x8 , 0x00000000 ) ;
F_12 ( V_44 , V_36 + 0xc , 0x00000000 ) ;
V_36 += 0x10 ;
V_46 -= 4 ;
}
if ( V_46 )
F_22 ( V_44 , NULL , V_36 , V_46 ) ;
F_21 ( V_9 ) ;
V_9 -> V_23 = false ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_53 * V_54 = V_26 -> V_55 ;
V_54 -> V_5 = V_9 -> V_5 ;
V_9 -> V_5 = ( T_1 * ) V_54 ;
V_9 -> V_23 = true ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 ;
struct V_53 * V_54 = (struct V_53 * ) V_9 -> V_5 ;
V_9 -> V_5 = V_54 -> V_5 ;
V_54 -> V_5 = NULL ;
V_9 -> V_23 = false ;
return 0 ;
}
struct V_1 *
F_28 ( struct V_10 * V_11 )
{
struct V_27 * V_28 = V_11 -> V_29 ;
struct V_8 * V_9 ;
V_9 = F_29 ( sizeof( * V_9 ) , V_13 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_11 = V_11 ;
V_9 -> V_56 . V_20 = V_28 -> V_32 . V_20 ;
return & V_9 -> V_56 ;
}
int
F_30 ( struct V_10 * V_11 )
{
struct V_27 * V_28 = V_11 -> V_29 ;
struct V_30 * V_31 = NULL ;
T_3 V_57 , V_58 ;
int V_59 ;
if ( V_28 -> V_60 >= V_61 && F_31 ( V_11 -> V_17 ) )
V_57 = 512 * 1024 * 1024 ;
else
V_57 = 64 * 1024 * 1024 ;
V_28 -> V_32 . V_48 . V_4 = F_32 ( V_62 | V_13 ) ;
if ( ! V_28 -> V_32 . V_48 . V_4 )
return - V_14 ;
V_28 -> V_32 . V_48 . V_49 =
F_5 ( V_11 -> V_17 , V_28 -> V_32 . V_48 . V_4 ,
0 , V_18 , V_19 ) ;
if ( F_6 ( V_11 -> V_17 , V_28 -> V_32 . V_48 . V_49 ) ) {
F_17 ( V_11 , L_6 ) ;
F_33 ( V_28 -> V_32 . V_48 . V_4 ) ;
V_28 -> V_32 . V_48 . V_4 = NULL ;
return - V_14 ;
}
if ( V_28 -> V_60 >= V_63 ) {
V_28 -> V_32 . V_64 = 0 ;
V_28 -> V_32 . V_57 = V_57 ;
V_28 -> V_32 . type = V_65 ;
V_28 -> V_32 . V_20 = & V_66 ;
} else
if ( 0 && F_31 ( V_11 -> V_17 ) &&
V_28 -> V_67 > 0x40 && V_28 -> V_67 != 0x45 ) {
if ( F_34 ( V_11 ) ) {
V_28 -> V_32 . V_20 = & V_68 ;
V_58 = 512 * 1024 ;
} else {
V_28 -> V_32 . V_20 = & V_69 ;
V_58 = 16 ;
}
V_59 = F_35 ( V_11 , NULL , V_57 / 1024 , V_58 ,
V_70 |
V_71 , & V_31 ) ;
if ( V_59 ) {
F_17 ( V_11 , L_7 , V_59 ) ;
return V_59 ;
}
V_28 -> V_32 . V_33 = V_31 ;
V_28 -> V_32 . V_64 = 0 ;
V_28 -> V_32 . V_57 = V_57 ;
V_28 -> V_32 . type = V_65 ;
} else {
V_59 = F_35 ( V_11 , NULL , ( V_57 / 1024 ) + 8 , 16 ,
V_70 |
V_71 , & V_31 ) ;
if ( V_59 ) {
F_17 ( V_11 , L_7 , V_59 ) ;
return V_59 ;
}
F_12 ( V_31 , 0 , V_72 |
( 1 << 12 ) |
( 0 << 13 ) |
( 0 << 14 ) |
( 2 << 16 ) ) ;
F_12 ( V_31 , 4 , V_57 - 1 ) ;
V_28 -> V_32 . V_33 = V_31 ;
V_28 -> V_32 . V_64 = 0 ;
V_28 -> V_32 . V_57 = V_57 ;
V_28 -> V_32 . type = V_73 ;
V_28 -> V_32 . V_20 = & V_74 ;
}
return 0 ;
}
void
F_36 ( struct V_10 * V_11 )
{
struct V_27 * V_28 = V_11 -> V_29 ;
F_37 ( NULL , & V_28 -> V_32 . V_33 ) ;
if ( V_28 -> V_32 . V_48 . V_4 ) {
F_8 ( V_11 -> V_17 , V_28 -> V_32 . V_48 . V_49 ,
V_18 , V_19 ) ;
F_33 ( V_28 -> V_32 . V_48 . V_4 ) ;
V_28 -> V_32 . V_48 . V_4 = NULL ;
}
}
T_2
F_38 ( struct V_10 * V_11 , T_2 V_38 )
{
struct V_27 * V_28 = V_11 -> V_29 ;
struct V_30 * V_31 = V_28 -> V_32 . V_33 ;
int V_36 = ( V_38 >> V_40 ) + 2 ;
F_39 ( V_28 -> V_60 >= V_63 ) ;
return ( F_23 ( V_31 , 4 * V_36 ) & ~ V_75 ) |
( V_38 & V_75 ) ;
}
