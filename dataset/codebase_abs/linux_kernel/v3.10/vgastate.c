static inline unsigned char F_1 ( void T_1 * V_1 , unsigned short V_2 ,
unsigned char V_3 )
{
F_2 ( V_1 , V_2 + 0x4 , V_3 ) ;
return F_3 ( V_1 , V_2 + 0x5 ) ;
}
static inline void F_4 ( void T_1 * V_1 , unsigned short V_2 ,
unsigned char V_3 , unsigned char V_4 )
{
F_2 ( V_1 , V_2 + 0x4 , V_3 ) ;
F_2 ( V_1 , V_2 + 0x5 , V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 , void T_1 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
int V_11 ;
T_2 V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ;
unsigned short V_2 ;
V_12 = F_3 ( V_6 -> V_20 , V_21 ) ;
V_2 = ( V_12 & 1 ) ? 0x3d0 : 0x3b0 ;
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_2 ( V_6 -> V_20 , V_22 , 0x00 ) ;
V_13 = F_6 ( V_6 -> V_20 , 0x10 ) ;
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_2 ( V_6 -> V_20 , V_22 , 0x20 ) ;
if ( V_13 & 1 )
return;
V_14 = F_7 ( V_6 -> V_20 , V_23 ) ;
V_15 = F_7 ( V_6 -> V_20 , V_24 ) ;
V_16 = F_7 ( V_6 -> V_20 , V_25 ) ;
V_18 = F_8 ( V_6 -> V_20 , V_26 ) ;
V_19 = F_8 ( V_6 -> V_20 , V_27 ) ;
V_17 = F_8 ( V_6 -> V_20 , V_28 ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x1 ) ;
F_9 ( V_6 -> V_20 , V_28 , V_17 | 1 << 5 ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x3 ) ;
if ( V_6 -> V_30 & V_31 ) {
F_9 ( V_6 -> V_20 , V_26 , 0x4 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x2 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < 4 * 8192 ; V_11 ++ )
V_9 -> V_32 [ V_11 ] = F_3 ( V_7 , V_11 ) ;
}
if ( V_6 -> V_30 & V_33 ) {
F_9 ( V_6 -> V_20 , V_26 , 0x8 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x3 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_34 ; V_11 ++ )
V_9 -> V_35 [ V_11 ] = F_3 ( V_7 , V_11 ) ;
}
if ( V_6 -> V_30 & V_36 ) {
F_9 ( V_6 -> V_20 , V_26 , 0x1 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < 8192 ; V_11 ++ )
V_9 -> V_37 [ V_11 ] = F_3 ( V_7 , V_11 ) ;
F_9 ( V_6 -> V_20 , V_26 , 0x2 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x1 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < 8192 ; V_11 ++ )
V_9 -> V_37 [ 8192 + V_11 ] = F_3 ( V_7 + 2 * 8192 , V_11 ) ;
}
F_9 ( V_6 -> V_20 , V_26 , V_18 ) ;
F_9 ( V_6 -> V_20 , V_27 , V_19 ) ;
F_10 ( V_6 -> V_20 , V_23 , V_14 ) ;
F_10 ( V_6 -> V_20 , V_24 , V_15 ) ;
F_10 ( V_6 -> V_20 , V_25 , V_16 ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x1 ) ;
F_9 ( V_6 -> V_20 , V_28 , V_17 & ~ ( 1 << 5 ) ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x3 ) ;
F_9 ( V_6 -> V_20 , V_28 , V_17 ) ;
}
static void F_11 ( struct V_5 * V_6 , void T_1 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
int V_11 ;
T_2 V_38 , V_39 , V_14 , V_15 , V_16 , V_40 ;
T_2 V_17 , V_18 , V_19 ;
V_38 = F_7 ( V_6 -> V_20 , V_41 ) ;
V_39 = F_7 ( V_6 -> V_20 , V_42 ) ;
V_14 = F_7 ( V_6 -> V_20 , V_23 ) ;
V_15 = F_7 ( V_6 -> V_20 , V_24 ) ;
V_16 = F_7 ( V_6 -> V_20 , V_25 ) ;
V_40 = F_7 ( V_6 -> V_20 , V_43 ) ;
V_18 = F_8 ( V_6 -> V_20 , V_26 ) ;
V_19 = F_8 ( V_6 -> V_20 , V_27 ) ;
V_17 = F_8 ( V_6 -> V_20 , V_28 ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x1 ) ;
F_9 ( V_6 -> V_20 , V_28 , V_17 | 1 << 5 ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x3 ) ;
if ( V_6 -> V_44 == 4 ) {
F_10 ( V_6 -> V_20 , V_42 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_43 , 0xff ) ;
F_10 ( V_6 -> V_20 , V_41 , 0x00 ) ;
}
if ( V_6 -> V_30 & V_31 ) {
F_9 ( V_6 -> V_20 , V_26 , 0x4 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x2 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < 4 * 8192 ; V_11 ++ )
F_2 ( V_7 , V_11 , V_9 -> V_32 [ V_11 ] ) ;
}
if ( V_6 -> V_30 & V_33 ) {
F_9 ( V_6 -> V_20 , V_26 , 0x8 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x3 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_34 ; V_11 ++ )
F_2 ( V_7 , V_11 , V_9 -> V_35 [ V_11 ] ) ;
}
if ( V_6 -> V_30 & V_36 ) {
F_9 ( V_6 -> V_20 , V_26 , 0x1 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < 8192 ; V_11 ++ )
F_2 ( V_7 , V_11 , V_9 -> V_37 [ V_11 ] ) ;
F_9 ( V_6 -> V_20 , V_26 , 0x2 ) ;
F_9 ( V_6 -> V_20 , V_27 , 0x6 ) ;
F_10 ( V_6 -> V_20 , V_23 , 0x1 ) ;
F_10 ( V_6 -> V_20 , V_24 , 0x0 ) ;
F_10 ( V_6 -> V_20 , V_25 , 0x5 ) ;
for ( V_11 = 0 ; V_11 < 8192 ; V_11 ++ )
F_2 ( V_7 , V_11 , V_9 -> V_37 [ 8192 + V_11 ] ) ;
}
F_9 ( V_6 -> V_20 , V_29 , 0x1 ) ;
F_9 ( V_6 -> V_20 , V_28 , V_17 & ~ ( 1 << 5 ) ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x3 ) ;
F_10 ( V_6 -> V_20 , V_41 , V_38 ) ;
F_10 ( V_6 -> V_20 , V_42 , V_39 ) ;
F_10 ( V_6 -> V_20 , V_23 , V_14 ) ;
F_10 ( V_6 -> V_20 , V_24 , V_15 ) ;
F_10 ( V_6 -> V_20 , V_25 , V_16 ) ;
F_10 ( V_6 -> V_20 , V_43 , V_40 ) ;
F_9 ( V_6 -> V_20 , V_28 , V_17 ) ;
F_9 ( V_6 -> V_20 , V_26 , V_18 ) ;
F_9 ( V_6 -> V_20 , V_27 , V_19 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
unsigned short V_2 ;
int V_11 ;
V_9 -> V_12 = F_3 ( V_6 -> V_20 , V_21 ) ;
if ( V_9 -> V_12 & 1 )
V_2 = 0x3d0 ;
else
V_2 = 0x3b0 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_45 ; V_11 ++ )
V_9 -> V_46 [ V_11 ] = F_1 ( V_6 -> V_20 , V_2 , V_11 ) ;
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_2 ( V_6 -> V_20 , V_22 , 0x00 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_47 ; V_11 ++ ) {
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
V_9 -> V_48 [ V_11 ] = F_6 ( V_6 -> V_20 , V_11 ) ;
}
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_2 ( V_6 -> V_20 , V_22 , 0x20 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_49 ; V_11 ++ )
V_9 -> V_50 [ V_11 ] = F_7 ( V_6 -> V_20 , V_11 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_51 ; V_11 ++ )
V_9 -> V_52 [ V_11 ] = F_8 ( V_6 -> V_20 , V_11 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
unsigned short V_2 ;
int V_11 ;
F_2 ( V_6 -> V_20 , V_53 , V_9 -> V_12 ) ;
if ( V_9 -> V_12 & 1 )
V_2 = 0x3d0 ;
else
V_2 = 0x3b0 ;
F_9 ( V_6 -> V_20 , V_28 ,
V_9 -> V_52 [ V_28 ] | 0x20 ) ;
F_9 ( V_6 -> V_20 , V_29 , 0x01 ) ;
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_2 ( V_6 -> V_20 , V_22 , 0x00 ) ;
for ( V_11 = 2 ; V_11 < V_6 -> V_51 ; V_11 ++ )
F_9 ( V_6 -> V_20 , V_11 , V_9 -> V_52 [ V_11 ] ) ;
F_4 ( V_6 -> V_20 , V_2 , 17 , V_9 -> V_46 [ 17 ] & ~ 0x80 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_45 ; V_11 ++ )
F_4 ( V_6 -> V_20 , V_2 , V_11 , V_9 -> V_46 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_49 ; V_11 ++ )
F_10 ( V_6 -> V_20 , V_11 , V_9 -> V_50 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_47 ; V_11 ++ ) {
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_14 ( V_6 -> V_20 , V_11 , V_9 -> V_48 [ V_11 ] ) ;
}
F_9 ( V_6 -> V_20 , V_29 , 0x03 ) ;
F_9 ( V_6 -> V_20 , V_28 ,
V_9 -> V_52 [ V_28 ] & ~ ( 1 << 5 ) ) ;
F_3 ( V_6 -> V_20 , V_2 + 0xa ) ;
F_2 ( V_6 -> V_20 , V_22 , 0x20 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
int V_11 ;
F_2 ( V_6 -> V_20 , V_54 , 0xff ) ;
F_2 ( V_6 -> V_20 , V_55 , 0x00 ) ;
for ( V_11 = 0 ; V_11 < 768 ; V_11 ++ )
V_9 -> V_56 [ V_11 ] = F_3 ( V_6 -> V_20 , V_57 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
int V_11 ;
F_2 ( V_6 -> V_20 , V_54 , 0xff ) ;
F_2 ( V_6 -> V_20 , V_58 , 0x00 ) ;
for ( V_11 = 0 ; V_11 < 768 ; V_11 ++ )
F_2 ( V_6 -> V_20 , V_57 , V_9 -> V_56 [ V_11 ] ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 != NULL ) {
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 ;
F_18 ( V_9 -> V_32 ) ;
F_18 ( V_9 -> V_35 ) ;
F_18 ( V_9 -> V_37 ) ;
F_18 ( V_9 -> V_56 ) ;
F_18 ( V_9 -> V_48 ) ;
F_19 ( V_9 ) ;
V_6 -> V_10 = NULL ;
}
}
int F_20 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
V_9 = F_21 ( sizeof( struct V_8 ) , V_59 ) ;
if ( V_9 == NULL )
return 1 ;
V_6 -> V_10 = ( void * ) V_9 ;
if ( V_6 -> V_30 & V_60 ) {
V_9 -> V_56 = F_22 ( 768 ) ;
if ( ! V_9 -> V_56 ) {
F_17 ( V_6 ) ;
return 1 ;
}
F_15 ( V_6 ) ;
}
if ( V_6 -> V_30 & V_61 ) {
int V_62 ;
if ( V_6 -> V_47 < 21 )
V_6 -> V_47 = 21 ;
if ( V_6 -> V_45 < 25 )
V_6 -> V_45 = 25 ;
if ( V_6 -> V_49 < 9 )
V_6 -> V_49 = 9 ;
if ( V_6 -> V_51 < 5 )
V_6 -> V_51 = 5 ;
V_62 = V_6 -> V_47 + V_6 -> V_45 +
V_6 -> V_49 + V_6 -> V_51 ;
V_9 -> V_48 = F_22 ( V_62 ) ;
if ( ! V_9 -> V_48 ) {
F_17 ( V_6 ) ;
return 1 ;
}
V_9 -> V_46 = V_9 -> V_48 + V_6 -> V_47 ;
V_9 -> V_50 = V_9 -> V_46 + V_6 -> V_45 ;
V_9 -> V_52 = V_9 -> V_50 + V_6 -> V_49 ;
F_12 ( V_6 ) ;
}
if ( V_6 -> V_30 & V_63 ) {
void T_1 * V_7 ;
if ( V_6 -> V_34 && V_6 -> V_34 < 4 * 8192 ) {
F_17 ( V_6 ) ;
return 1 ;
}
if ( ! V_6 -> V_34 )
V_6 -> V_34 = 8 * 8192 ;
if ( ! V_6 -> V_64 )
V_6 -> V_64 = 0xA0000 ;
V_7 = F_23 ( V_6 -> V_64 , V_6 -> V_34 ) ;
if ( ! V_7 ) {
F_17 ( V_6 ) ;
return 1 ;
}
if ( V_6 -> V_30 & V_31 ) {
V_9 -> V_32 = F_22 ( 4 * 8192 ) ;
if ( ! V_9 -> V_32 ) {
F_24 ( V_7 ) ;
F_17 ( V_6 ) ;
return 1 ;
}
}
if ( V_6 -> V_30 & V_33 ) {
V_9 -> V_35 = F_22 ( V_6 -> V_34 ) ;
if ( ! V_9 -> V_35 ) {
F_24 ( V_7 ) ;
F_17 ( V_6 ) ;
return 1 ;
}
}
if ( V_6 -> V_30 & V_36 ) {
V_9 -> V_37 = F_22 ( 8192 * 2 ) ;
if ( ! V_9 -> V_37 ) {
F_24 ( V_7 ) ;
F_17 ( V_6 ) ;
return 1 ;
}
}
F_5 ( V_6 , V_7 ) ;
F_24 ( V_7 ) ;
}
return 0 ;
}
int F_25 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 == NULL )
return 1 ;
if ( V_6 -> V_30 & V_61 )
F_13 ( V_6 ) ;
if ( V_6 -> V_30 & V_63 ) {
void T_1 * V_7 = F_23 ( V_6 -> V_64 , V_6 -> V_34 ) ;
if ( ! V_7 ) {
F_17 ( V_6 ) ;
return 1 ;
}
F_11 ( V_6 , V_7 ) ;
F_24 ( V_7 ) ;
}
if ( V_6 -> V_30 & V_60 )
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
