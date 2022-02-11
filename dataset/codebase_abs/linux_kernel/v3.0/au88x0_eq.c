static void F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_1 -> V_4 , 0x2b3c4 , V_2 ) ;
F_2 ( V_1 -> V_4 , 0x2b3c8 , V_3 ) ;
}
static inline T_2 F_3 ( T_2 V_5 )
{
if ( V_5 == ( T_2 ) - 32768 )
return 32767 ;
else
return - V_5 ;
}
static void F_4 ( T_1 * V_1 , T_2 V_6 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_10 = 0 , V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_9 ; V_11 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b000 + V_11 * 0x30 , V_6 [ V_10 + 0 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b004 + V_11 * 0x30 , V_6 [ V_10 + 1 ] ) ;
if ( V_7 -> V_12 == 0 ) {
F_2 ( V_1 -> V_4 , 0x2b008 + V_11 * 0x30 , V_6 [ V_10 + 2 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b00c + V_11 * 0x30 , V_6 [ V_10 + 3 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b010 + V_11 * 0x30 , V_6 [ V_10 + 4 ] ) ;
} else {
F_2 ( V_1 -> V_4 , 0x2b008 + V_11 * 0x30 , F_3 ( V_6 [ 2 + V_10 ] ) ) ;
F_2 ( V_1 -> V_4 , 0x2b00c + V_11 * 0x30 , F_3 ( V_6 [ 3 + V_10 ] ) ) ;
F_2 ( V_1 -> V_4 , 0x2b010 + V_11 * 0x30 , F_3 ( V_6 [ 4 + V_10 ] ) ) ;
}
V_10 += 5 ;
}
}
static void F_5 ( T_1 * V_1 , T_2 V_6 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_10 = 0 , V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_9 ; V_11 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b1e0 + V_11 * 0x30 , V_6 [ 0 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b1e4 + V_11 * 0x30 , V_6 [ 1 + V_10 ] ) ;
if ( V_7 -> V_12 == 0 ) {
F_2 ( V_1 -> V_4 , 0x2b1e8 + V_11 * 0x30 , V_6 [ 2 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b1ec + V_11 * 0x30 , V_6 [ 3 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b1f0 + V_11 * 0x30 , V_6 [ 4 + V_10 ] ) ;
} else {
F_2 ( V_1 -> V_4 , 0x2b1e8 + V_11 * 0x30 , F_3 ( V_6 [ 2 + V_10 ] ) ) ;
F_2 ( V_1 -> V_4 , 0x2b1ec + V_11 * 0x30 , F_3 ( V_6 [ 3 + V_10 ] ) ) ;
F_2 ( V_1 -> V_4 , 0x2b1f0 + V_11 * 0x30 , F_3 ( V_6 [ 4 + V_10 ] ) ) ;
}
V_10 += 5 ;
}
}
static void F_6 ( T_1 * V_1 , T_2 V_5 [] , T_2 V_13 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_10 = 0 , V_14 ;
F_2 ( V_1 -> V_4 , 0x2b3fc , V_5 [ 0 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b400 , V_5 [ 1 ] ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b014 + ( V_10 * 0xc ) , V_13 [ V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b018 + ( V_10 * 0xc ) , V_13 [ 1 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b01c + ( V_10 * 0xc ) , V_13 [ 2 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b020 + ( V_10 * 0xc ) , V_13 [ 3 + V_10 ] ) ;
V_10 += 4 ;
}
}
static void F_7 ( T_1 * V_1 , T_2 V_5 [] , T_2 V_13 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_10 = 0 , V_14 ;
F_2 ( V_1 -> V_4 , 0x2b404 , V_5 [ 0 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b408 , V_5 [ 1 ] ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b1f4 + ( V_10 * 0xc ) , V_13 [ V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b1f8 + ( V_10 * 0xc ) , V_13 [ 1 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b1fc + ( V_10 * 0xc ) , V_13 [ 2 + V_10 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b200 + ( V_10 * 0xc ) , V_13 [ 3 + V_10 ] ) ;
V_10 += 4 ;
}
}
static void F_8 ( T_1 * V_1 , T_2 V_5 , T_2 V_13 )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
if ( V_7 -> V_12 == 0 ) {
F_2 ( V_1 -> V_4 , 0x2b3d4 , V_5 ) ;
F_2 ( V_1 -> V_4 , 0x2b3ec , V_13 ) ;
} else {
F_2 ( V_1 -> V_4 , 0x2b3d4 , F_3 ( V_5 ) ) ;
F_2 ( V_1 -> V_4 , 0x2b3ec , F_3 ( V_13 ) ) ;
}
}
static void F_9 ( T_1 * V_1 , T_2 V_5 , T_2 V_13 )
{
F_2 ( V_1 -> V_4 , 0x2b3e0 , V_5 ) ;
F_2 ( V_1 -> V_4 , 0x2b3f8 , V_13 ) ;
}
static void
F_10 ( T_1 * V_1 , T_2 V_15 , T_2 V_13 )
{
F_2 ( V_1 -> V_4 , 0x2b02c + ( V_15 * 0x30 ) , V_13 ) ;
}
static void
F_11 ( T_1 * V_1 , T_2 V_15 , T_2 V_13 )
{
F_2 ( V_1 -> V_4 , 0x2b20c + ( V_15 * 0x30 ) , V_13 ) ;
}
static void F_12 ( T_1 * V_1 , T_2 V_5 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b02c + V_14 * 0x30 , V_5 [ V_14 ] ) ;
}
}
static void F_13 ( T_1 * V_1 , T_2 V_5 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b20c + V_14 * 0x30 , V_5 [ V_14 ] ) ;
}
}
static void F_14 ( T_1 * V_1 , T_2 V_5 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b028 + V_14 * 0x30 , V_5 [ V_14 ] ) ;
}
}
static void F_15 ( T_1 * V_1 , T_2 V_5 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b208 + V_14 * 0x30 , V_5 [ V_14 ] ) ;
}
}
static void F_16 ( T_1 * V_1 , T_2 V_16 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 ; V_10 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b024 + V_10 * V_17 , V_16 [ V_10 ] ) ;
}
F_2 ( V_1 -> V_4 , 0x2b3cc , V_16 [ V_7 -> V_9 ] ) ;
F_2 ( V_1 -> V_4 , 0x2b3d8 , V_16 [ V_7 -> V_9 + 1 ] ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 ; V_10 ++ ) {
F_2 ( V_1 -> V_4 , 0x2b204 + V_10 * V_17 ,
V_16 [ V_10 + ( V_7 -> V_9 + 2 ) ] ) ;
}
F_2 ( V_1 -> V_4 , 0x2b3e4 , V_16 [ 2 + ( V_7 -> V_9 * 2 ) ] ) ;
F_2 ( V_1 -> V_4 , 0x2b3f0 , V_16 [ 3 + ( V_7 -> V_9 * 2 ) ] ) ;
}
static void F_17 ( T_1 * V_1 , T_4 V_18 )
{
F_2 ( V_1 -> V_4 , 0x2b440 , V_18 ) ;
}
static void F_18 ( T_1 * V_1 , T_4 V_19 )
{
F_2 ( V_1 -> V_4 , 0x2b440 , ( ( V_19 & 0x1f ) << 3 ) | 0xb800 ) ;
}
static void F_19 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_4 , V_20 , 0xf001 ) ;
}
static void F_20 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_4 , V_20 , 0xf000 ) ;
}
static void F_21 ( T_1 * V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 0x8 ; V_10 ++ )
F_2 ( V_1 -> V_4 , V_21 + ( V_10 << 2 ) , 0x0 ) ;
for ( V_10 = 0 ; V_10 < 0x4 ; V_10 ++ )
F_2 ( V_1 -> V_4 , V_22 + ( V_10 << 2 ) , 0x0 ) ;
}
static void F_22 ( T_1 * V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 0x4 ; V_10 ++ )
F_2 ( V_1 -> V_4 , V_21 + ( V_10 << 2 ) , 0x0 ) ;
}
static void F_23 ( T_1 * V_1 )
{
F_17 ( V_1 , 0 ) ;
F_21 ( V_1 ) ;
F_2 ( V_1 -> V_4 , 0x2b3c0 , 0 ) ;
F_1 ( V_1 , 0 , 0 ) ;
F_4 ( V_1 , V_23 ) ;
F_5 ( V_1 , V_23 ) ;
F_14 ( V_1 , V_24 ) ;
F_15 ( V_1 , V_24 ) ;
F_12 ( V_1 , V_24 ) ;
F_13 ( V_1 , V_24 ) ;
F_8 ( V_1 , 0 , 0 ) ;
F_9 ( V_1 , 0 , 0 ) ;
F_6 ( V_1 , V_25 , V_26 ) ;
F_7 ( V_1 , V_25 , V_26 ) ;
F_16 ( V_1 , ( T_2 * ) V_27 ) ;
}
static void F_24 ( T_1 * V_1 )
{
F_1 ( V_1 , 0 , 0 ) ;
F_4 ( V_1 , V_28 ) ;
F_5 ( V_1 , V_28 ) ;
F_14 ( V_1 , V_29 ) ;
F_15 ( V_1 , V_29 ) ;
F_12 ( V_1 , V_29 ) ;
F_13 ( V_1 , V_29 ) ;
}
static void
F_25 ( T_1 * V_1 , T_5 * V_30 )
{
F_1 ( V_1 , 0xc , 0x7fe0 ) ;
F_4 ( V_1 , V_30 -> V_31 ) ;
F_5 ( V_1 , V_30 -> V_32 ) ;
F_14 ( V_1 , V_30 -> V_33 ) ;
F_13 ( V_1 , V_30 -> V_34 ) ;
F_12 ( V_1 , V_30 -> V_33 ) ;
F_15 ( V_1 , V_30 -> V_34 ) ;
}
static void F_26 ( T_1 * V_1 , T_2 V_16 [] )
{
T_3 * V_7 = & ( V_1 -> V_8 . V_9 ) ;
int V_10 ;
if ( V_7 -> V_9 <= 0 )
return;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 ; V_10 ++ )
V_16 [ V_10 ] = F_27 ( V_1 -> V_4 , 0x2B024 + V_10 * 0x30 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 ; V_10 ++ )
V_16 [ V_10 + V_7 -> V_9 ] =
F_27 ( V_1 -> V_4 , 0x2B204 + V_10 * 0x30 ) ;
}
static int F_28 ( T_1 * V_1 , T_2 V_15 , T_2 * V_2 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
if ( V_8 -> V_35 ) {
* V_2 = V_8 -> V_36 [ V_15 ] ;
return 0 ;
}
return 1 ;
}
static void F_29 ( T_1 * V_1 , T_2 V_15 , T_2 V_2 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
if ( V_8 -> V_35 == 0 )
return;
V_8 -> V_36 [ V_15 ] = V_2 ;
if ( V_8 -> V_37 )
return;
F_10 ( V_1 , V_15 , V_2 ) ;
}
static int F_30 ( T_1 * V_1 , T_2 V_15 , T_2 * V_2 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
if ( V_8 -> V_35 ) {
* V_2 = V_8 -> V_36 [ V_15 + V_8 -> V_38 ] ;
return 0 ;
}
return 1 ;
}
static void F_31 ( T_1 * V_1 , T_2 V_15 , T_2 V_2 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
if ( V_8 -> V_35 == 0 )
return;
V_8 -> V_36 [ V_15 + V_8 -> V_38 ] = V_2 ;
if ( V_8 -> V_37 )
return;
F_11 ( V_1 , V_15 , V_2 ) ;
}
static int F_32 ( T_1 * V_1 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
F_12 ( V_1 , V_8 -> V_36 ) ;
F_13 ( V_1 , & ( V_8 -> V_36 [ V_8 -> V_38 ] ) ) ;
return 0 ;
}
static int
F_33 ( T_1 * V_1 , T_2 V_39 [] , T_7 V_40 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
int V_10 ;
if ( ( ( V_8 -> V_38 ) * 2 != V_40 ) || ( V_8 -> V_35 == 0 ) )
return 1 ;
for ( V_10 = 0 ; V_10 < V_40 ; V_10 ++ ) {
V_8 -> V_36 [ V_10 ] = V_39 [ V_10 ] ;
}
if ( V_8 -> V_37 )
return 0 ;
return F_32 ( V_1 ) ;
}
static void
F_34 ( T_1 * V_1 , T_4 V_5 , T_4 V_13 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
T_4 V_41 , V_14 ;
V_8 -> V_42 = V_5 ;
V_8 -> V_43 = V_13 ;
if ( V_8 -> V_37 )
V_41 = V_8 -> V_44 ;
else
V_41 = V_8 -> V_45 ;
V_14 = ( V_41 * V_8 -> V_42 ) >> 0x10 ;
V_41 = ( V_41 * V_8 -> V_43 ) >> 0x10 ;
F_9 ( V_1 , V_14 , V_41 ) ;
}
static void F_35 ( T_1 * V_1 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
T_4 V_41 , V_14 ;
if ( V_8 -> V_37 )
V_41 = V_8 -> V_44 ;
else
V_41 = V_8 -> V_45 ;
V_14 = ( V_41 * V_8 -> V_42 ) >> 0x10 ;
V_41 = ( V_41 * V_8 -> V_43 ) >> 0x10 ;
F_9 ( V_1 , V_14 , V_41 ) ;
}
static void F_36 ( T_1 * V_1 )
{
if ( V_1 != NULL )
F_22 ( V_1 ) ;
}
static void F_37 ( T_1 * V_1 , T_4 V_46 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
if ( ( V_8 -> V_35 ) && ( V_46 == 0 ) ) {
F_32 ( V_1 ) ;
F_8 ( V_1 , V_8 -> V_12 , V_8 -> V_12 ) ;
} else {
F_12 ( V_1 , V_8 -> V_47 ) ;
F_13 ( V_1 , V_8 -> V_47 ) ;
F_8 ( V_1 , V_8 -> V_48 , V_8 -> V_48 ) ;
}
F_35 ( V_1 ) ;
}
static void F_38 ( T_1 * V_1 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
memcpy ( & ( V_8 -> V_30 ) , & V_49 , sizeof( T_5 ) ) ;
F_33 ( V_1 , V_50 , V_8 -> V_38 * 2 ) ;
}
static int F_39 ( T_1 * V_1 , T_2 * V_16 , int * V_40 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
if ( V_8 -> V_38 == 0 )
return 1 ;
* V_40 = V_8 -> V_38 * 2 ;
F_26 ( V_1 , V_16 ) ;
return 0 ;
}
static void F_40 ( T_1 * V_1 )
{
T_6 * V_8 = & ( V_1 -> V_8 ) ;
V_8 -> V_12 = 0 ;
V_8 -> V_45 = 0x5999 ;
V_8 -> V_48 = 0x5999 ;
V_8 -> V_44 = 0x5999 ;
V_8 -> V_38 = 0xa ;
V_8 -> V_9 . V_9 = V_8 -> V_38 ;
V_8 -> V_35 = 0x1 ;
V_8 -> V_37 = 0x0 ;
V_8 -> V_42 = 0xffff ;
V_8 -> V_43 = 0xffff ;
memset ( V_8 -> V_47 , 0 , sizeof( V_8 -> V_47 ) ) ;
F_23 ( V_1 ) ;
F_18 ( V_1 , 0x11 ) ;
F_38 ( V_1 ) ;
F_25 ( V_1 , & ( V_8 -> V_30 ) ) ;
F_37 ( V_1 , V_8 -> V_37 ) ;
F_34 ( V_1 , 0 , 0 ) ;
F_19 ( V_1 ) ;
}
static void F_41 ( T_1 * V_1 )
{
F_36 ( V_1 ) ;
F_24 ( V_1 ) ;
F_20 ( V_1 ) ;
}
static int
F_42 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
T_1 * V_1 = F_43 ( V_52 ) ;
T_6 * V_8 = & ( V_1 -> V_8 ) ;
V_54 -> V_55 . integer . V_55 [ 0 ] = V_8 -> V_37 ? 0 : 1 ;
return 0 ;
}
static int
F_44 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
T_1 * V_1 = F_43 ( V_52 ) ;
T_6 * V_8 = & ( V_1 -> V_8 ) ;
V_8 -> V_37 = V_54 -> V_55 . integer . V_55 [ 0 ] ? 0 : 1 ;
F_37 ( V_1 , V_8 -> V_37 ) ;
return 1 ;
}
static int
F_45 ( struct V_51 * V_52 , struct V_56 * V_57 )
{
V_57 -> type = V_58 ;
V_57 -> V_40 = 2 ;
V_57 -> V_55 . integer . V_59 = 0x0000 ;
V_57 -> V_55 . integer . V_60 = 0x7fff ;
return 0 ;
}
static int
F_46 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
T_1 * V_1 = F_43 ( V_52 ) ;
int V_10 = V_52 -> V_61 ;
T_2 V_62 = 0 , V_63 = 0 ;
F_28 ( V_1 , V_10 , & V_62 ) ;
F_30 ( V_1 , V_10 , & V_63 ) ;
V_54 -> V_55 . integer . V_55 [ 0 ] = V_62 ;
V_54 -> V_55 . integer . V_55 [ 1 ] = V_63 ;
return 0 ;
}
static int
F_47 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
T_1 * V_1 = F_43 ( V_52 ) ;
int V_64 = 0 , V_10 = V_52 -> V_61 ;
T_2 V_62 = 0 , V_63 = 0 ;
F_28 ( V_1 , V_10 , & V_62 ) ;
F_30 ( V_1 , V_10 , & V_63 ) ;
if ( V_62 != V_54 -> V_55 . integer . V_55 [ 0 ] ) {
F_29 ( V_1 , V_10 ,
V_54 -> V_55 . integer . V_55 [ 0 ] ) ;
V_64 = 1 ;
}
if ( V_63 != V_54 -> V_55 . integer . V_55 [ 1 ] ) {
F_31 ( V_1 , V_10 ,
V_54 -> V_55 . integer . V_55 [ 1 ] ) ;
V_64 = 1 ;
}
return V_64 ;
}
static int
F_48 ( struct V_51 * V_52 , struct V_56 * V_57 )
{
V_57 -> type = V_58 ;
V_57 -> V_40 = 20 ;
V_57 -> V_55 . integer . V_59 = 0x0000 ;
V_57 -> V_55 . integer . V_60 = 0x7fff ;
return 0 ;
}
static int
F_49 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
T_1 * V_1 = F_43 ( V_52 ) ;
int V_10 , V_40 = 0 ;
T_2 V_16 [ 20 ] ;
F_39 ( V_1 , V_16 , & V_40 ) ;
if ( V_40 != 20 ) {
F_50 ( V_65 L_1 , V_40 ) ;
return - 1 ;
}
for ( V_10 = 0 ; V_10 < 20 ; V_10 ++ )
V_54 -> V_55 . integer . V_55 [ V_10 ] = V_16 [ V_10 ] ;
return 0 ;
}
static int T_8 F_51 ( T_1 * V_1 )
{
struct V_51 * V_52 ;
int V_66 , V_10 ;
F_40 ( V_1 ) ;
if ( ( V_52 =
F_52 ( & V_67 , V_1 ) ) == NULL )
return - V_68 ;
V_52 -> V_61 = 0 ;
if ( ( V_66 = F_53 ( V_1 -> V_69 , V_52 ) ) < 0 )
return V_66 ;
for ( V_10 = 0 ; V_10 < 10 ; V_10 ++ ) {
if ( ( V_52 =
F_52 ( & V_70 , V_1 ) ) == NULL )
return - V_68 ;
snprintf ( V_52 -> V_71 . V_72 , sizeof( V_52 -> V_71 . V_72 ) ,
L_2 , V_73 [ V_10 ] ) ;
V_52 -> V_61 = V_10 ;
if ( ( V_66 = F_53 ( V_1 -> V_69 , V_52 ) ) < 0 )
return V_66 ;
}
if ( ( V_52 = F_52 ( & V_74 , V_1 ) ) == NULL )
return - V_68 ;
if ( ( V_66 = F_53 ( V_1 -> V_69 , V_52 ) ) < 0 )
return V_66 ;
return 0 ;
}
static int F_54 ( T_1 * V_1 )
{
F_41 ( V_1 ) ;
return 0 ;
}
