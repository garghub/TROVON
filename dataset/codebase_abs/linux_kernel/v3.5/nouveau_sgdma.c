static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_2 ) {
F_2 ( V_4 -> V_5 , L_1 ) ;
F_3 ( & V_4 -> V_2 ) ;
F_4 ( V_4 ) ;
}
}
static int
F_5 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_8 * V_5 = V_4 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 ;
unsigned V_16 , V_17 , V_18 ;
F_2 ( V_5 , L_2 , V_7 -> V_19 ) ;
V_4 -> V_20 = V_7 -> V_19 << V_21 ;
V_18 = ( V_4 -> V_20 >> V_22 ) + 2 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_23 ; V_16 ++ ) {
T_1 V_24 = V_4 -> V_2 . V_25 [ V_16 ] ;
T_2 V_26 = F_6 ( V_24 ) ;
for ( V_17 = 0 ; V_17 < V_27 / V_28 ; V_17 ++ , V_18 ++ ) {
F_7 ( V_13 , ( V_18 * 4 ) + 0 , V_26 | 3 ) ;
V_26 += V_28 ;
}
}
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_8 * V_5 = V_4 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 ;
unsigned V_16 , V_17 , V_18 ;
F_2 ( V_5 , L_1 ) ;
if ( V_2 -> V_29 != V_30 )
return 0 ;
V_18 = ( V_4 -> V_20 >> V_22 ) + 2 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_23 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_27 / V_28 ; V_17 ++ , V_18 ++ )
F_7 ( V_13 , ( V_18 * 4 ) + 0 , 0x00000000 ) ;
}
return 0 ;
}
static void
F_9 ( struct V_3 * V_4 )
{
struct V_8 * V_5 = V_4 -> V_5 ;
F_10 ( V_5 , 0x100810 , 0x00000022 ) ;
if ( ! F_11 ( V_5 , 0x100810 , 0x00000100 , 0x00000100 ) )
F_12 ( V_5 , L_3 ,
F_13 ( V_5 , 0x100810 ) ) ;
F_10 ( V_5 , 0x100810 , 0x00000000 ) ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_10 = V_4 -> V_5 -> V_11 ;
struct V_12 * V_31 = V_10 -> V_14 . V_15 ;
T_1 * V_32 = V_4 -> V_2 . V_25 ;
T_3 V_18 = V_7 -> V_19 << 2 ;
T_3 V_33 = V_2 -> V_23 ;
V_4 -> V_20 = V_7 -> V_19 << V_21 ;
while ( V_33 -- ) {
F_7 ( V_31 , V_18 , ( * V_32 ++ >> 7 ) | 1 ) ;
V_18 += 4 ;
}
F_9 ( V_4 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_10 = V_4 -> V_5 -> V_11 ;
struct V_12 * V_31 = V_10 -> V_14 . V_15 ;
T_3 V_18 = ( V_4 -> V_20 >> 12 ) << 2 ;
T_3 V_33 = V_2 -> V_23 ;
while ( V_33 -- ) {
F_7 ( V_31 , V_18 , 0x00000000 ) ;
V_18 += 4 ;
}
F_9 ( V_4 ) ;
return 0 ;
}
static void
F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_8 * V_5 = V_4 -> V_5 ;
F_10 ( V_5 , 0x100814 , ( V_2 -> V_23 - 1 ) << 12 ) ;
F_10 ( V_5 , 0x100808 , V_4 -> V_20 | 0x20 ) ;
if ( ! F_11 ( V_5 , 0x100808 , 0x00000001 , 0x00000001 ) )
F_12 ( V_5 , L_4 ,
F_13 ( V_5 , 0x100808 ) ) ;
F_10 ( V_5 , 0x100808 , 0x00000000 ) ;
}
static void
F_17 ( struct V_12 * V_31 , T_1 * V_32 , T_3 V_34 , T_3 V_33 )
{
struct V_9 * V_10 = V_31 -> V_5 -> V_11 ;
T_1 V_35 = V_10 -> V_14 . V_35 . V_36 ;
T_3 V_18 , V_37 [ 4 ] ;
V_18 = V_34 >> 2 ;
V_34 &= ~ 0x0000000f ;
V_37 [ 0 ] = F_18 ( V_31 , V_34 + 0x0 ) ;
V_37 [ 1 ] = F_18 ( V_31 , V_34 + 0x4 ) ;
V_37 [ 2 ] = F_18 ( V_31 , V_34 + 0x8 ) ;
V_37 [ 3 ] = F_18 ( V_31 , V_34 + 0xc ) ;
while ( V_33 -- ) {
T_3 V_36 = V_32 ? ( * V_32 ++ >> 12 ) : ( V_35 >> 12 ) ;
switch ( V_18 ++ & 0x3 ) {
case 0 :
V_37 [ 0 ] &= ~ 0x07ffffff ;
V_37 [ 0 ] |= V_36 ;
break;
case 1 :
V_37 [ 0 ] &= ~ 0xf8000000 ;
V_37 [ 0 ] |= V_36 << 27 ;
V_37 [ 1 ] &= ~ 0x003fffff ;
V_37 [ 1 ] |= V_36 >> 5 ;
break;
case 2 :
V_37 [ 1 ] &= ~ 0xffc00000 ;
V_37 [ 1 ] |= V_36 << 22 ;
V_37 [ 2 ] &= ~ 0x0001ffff ;
V_37 [ 2 ] |= V_36 >> 10 ;
break;
case 3 :
V_37 [ 2 ] &= ~ 0xfffe0000 ;
V_37 [ 2 ] |= V_36 << 17 ;
V_37 [ 3 ] &= ~ 0x00000fff ;
V_37 [ 3 ] |= V_36 >> 15 ;
break;
}
}
V_37 [ 3 ] |= 0x40000000 ;
F_7 ( V_31 , V_34 + 0x0 , V_37 [ 0 ] ) ;
F_7 ( V_31 , V_34 + 0x4 , V_37 [ 1 ] ) ;
F_7 ( V_31 , V_34 + 0x8 , V_37 [ 2 ] ) ;
F_7 ( V_31 , V_34 + 0xc , V_37 [ 3 ] ) ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_10 = V_4 -> V_5 -> V_11 ;
struct V_12 * V_31 = V_10 -> V_14 . V_15 ;
T_1 * V_32 = V_4 -> V_2 . V_25 ;
T_3 V_18 = V_7 -> V_19 << 2 , V_37 [ 4 ] ;
T_3 V_33 = V_2 -> V_23 ;
int V_16 ;
V_4 -> V_20 = V_7 -> V_19 << V_21 ;
if ( V_18 & 0x0000000c ) {
T_3 V_38 = 4 - ( ( V_18 >> 2 ) & 0x3 ) ;
T_3 V_39 = ( V_33 > V_38 ) ? V_38 : V_33 ;
F_17 ( V_31 , V_32 , V_18 , V_39 ) ;
V_18 += ( V_39 << 2 ) ;
V_32 += V_39 ;
V_33 -= V_39 ;
}
while ( V_33 >= 4 ) {
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
V_37 [ V_16 ] = * V_32 ++ >> 12 ;
F_7 ( V_31 , V_18 + 0x0 , V_37 [ 0 ] >> 0 | V_37 [ 1 ] << 27 ) ;
F_7 ( V_31 , V_18 + 0x4 , V_37 [ 1 ] >> 5 | V_37 [ 2 ] << 22 ) ;
F_7 ( V_31 , V_18 + 0x8 , V_37 [ 2 ] >> 10 | V_37 [ 3 ] << 17 ) ;
F_7 ( V_31 , V_18 + 0xc , V_37 [ 3 ] >> 15 | 0x40000000 ) ;
V_18 += 0x10 ;
V_33 -= 4 ;
}
if ( V_33 )
F_17 ( V_31 , V_32 , V_18 , V_33 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_10 = V_4 -> V_5 -> V_11 ;
struct V_12 * V_31 = V_10 -> V_14 . V_15 ;
T_3 V_18 = ( V_4 -> V_20 >> 12 ) << 2 ;
T_3 V_33 = V_2 -> V_23 ;
if ( V_18 & 0x0000000c ) {
T_3 V_38 = 4 - ( ( V_18 >> 2 ) & 0x3 ) ;
T_3 V_39 = ( V_33 > V_38 ) ? V_38 : V_33 ;
F_17 ( V_31 , NULL , V_18 , V_39 ) ;
V_18 += ( V_39 << 2 ) ;
V_33 -= V_39 ;
}
while ( V_33 >= 4 ) {
F_7 ( V_31 , V_18 + 0x0 , 0x00000000 ) ;
F_7 ( V_31 , V_18 + 0x4 , 0x00000000 ) ;
F_7 ( V_31 , V_18 + 0x8 , 0x00000000 ) ;
F_7 ( V_31 , V_18 + 0xc , 0x00000000 ) ;
V_18 += 0x10 ;
V_33 -= 4 ;
}
if ( V_33 )
F_17 ( V_31 , NULL , V_18 , V_33 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_40 * V_41 = V_7 -> V_42 ;
if ( V_2 -> V_43 ) {
V_41 -> V_43 = V_2 -> V_43 ;
} else
V_41 -> V_44 = V_4 -> V_2 . V_25 ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 )
{
return 0 ;
}
struct V_1 *
F_23 ( struct V_45 * V_46 ,
unsigned long V_47 , T_2 V_48 ,
struct V_49 * V_50 )
{
struct V_9 * V_10 = F_24 ( V_46 ) ;
struct V_8 * V_5 = V_10 -> V_5 ;
struct V_3 * V_4 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 . V_2 . V_52 = V_10 -> V_14 . V_52 ;
if ( F_26 ( & V_4 -> V_2 , V_46 , V_47 , V_48 , V_50 ) ) {
F_4 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_2 . V_2 ;
}
int
F_27 ( struct V_8 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = NULL ;
T_3 V_53 , V_54 ;
int V_55 ;
if ( V_10 -> V_56 >= V_57 )
V_53 = 512 * 1024 * 1024 ;
else
V_53 = 128 * 1024 * 1024 ;
V_10 -> V_14 . V_35 . V_49 = F_28 ( V_58 | V_51 ) ;
if ( ! V_10 -> V_14 . V_35 . V_49 )
return - V_59 ;
V_10 -> V_14 . V_35 . V_36 =
F_29 ( V_5 -> V_60 , V_10 -> V_14 . V_35 . V_49 ,
0 , V_27 , V_61 ) ;
if ( F_30 ( V_5 -> V_60 , V_10 -> V_14 . V_35 . V_36 ) ) {
F_12 ( V_5 , L_5 ) ;
F_31 ( V_10 -> V_14 . V_35 . V_49 ) ;
V_10 -> V_14 . V_35 . V_49 = NULL ;
return - V_59 ;
}
if ( V_10 -> V_56 >= V_62 ) {
V_10 -> V_14 . V_63 = 0 ;
V_10 -> V_14 . V_53 = V_53 ;
V_10 -> V_14 . type = V_64 ;
V_10 -> V_14 . V_52 = & V_65 ;
} else
if ( 0 && F_32 ( V_5 -> V_60 ) &&
V_10 -> V_66 > 0x40 && V_10 -> V_66 != 0x45 ) {
if ( F_33 ( V_5 ) ) {
V_10 -> V_14 . V_52 = & V_67 ;
V_54 = 512 * 1024 ;
} else {
V_10 -> V_14 . V_52 = & V_68 ;
V_54 = 16 ;
}
V_55 = F_34 ( V_5 , NULL , V_53 / 1024 , V_54 ,
V_69 |
V_70 , & V_13 ) ;
if ( V_55 ) {
F_12 ( V_5 , L_6 , V_55 ) ;
return V_55 ;
}
V_10 -> V_14 . V_15 = V_13 ;
V_10 -> V_14 . V_63 = 0 ;
V_10 -> V_14 . V_53 = V_53 ;
V_10 -> V_14 . type = V_64 ;
} else {
V_55 = F_34 ( V_5 , NULL , ( V_53 / 1024 ) + 8 , 16 ,
V_69 |
V_70 , & V_13 ) ;
if ( V_55 ) {
F_12 ( V_5 , L_6 , V_55 ) ;
return V_55 ;
}
F_7 ( V_13 , 0 , V_71 |
( 1 << 12 ) |
( 0 << 13 ) |
( 0 << 14 ) |
( 2 << 16 ) ) ;
F_7 ( V_13 , 4 , V_53 - 1 ) ;
V_10 -> V_14 . V_15 = V_13 ;
V_10 -> V_14 . V_63 = 0 ;
V_10 -> V_14 . V_53 = V_53 ;
V_10 -> V_14 . type = V_72 ;
V_10 -> V_14 . V_52 = & V_73 ;
}
return 0 ;
}
void
F_35 ( struct V_8 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
F_36 ( NULL , & V_10 -> V_14 . V_15 ) ;
if ( V_10 -> V_14 . V_35 . V_49 ) {
F_37 ( V_5 -> V_60 , V_10 -> V_14 . V_35 . V_36 ,
V_27 , V_61 ) ;
F_31 ( V_10 -> V_14 . V_35 . V_49 ) ;
V_10 -> V_14 . V_35 . V_49 = NULL ;
}
}
T_2
F_38 ( struct V_8 * V_5 , T_2 V_20 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_14 . V_15 ;
int V_18 = ( V_20 >> V_22 ) + 2 ;
F_39 ( V_10 -> V_56 >= V_62 ) ;
return ( F_18 ( V_13 , 4 * V_18 ) & ~ V_74 ) |
( V_20 & V_74 ) ;
}
