static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_11 + V_12 ) & 0x3 ;
return V_6 -> V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_14 = V_7 [ 0 ] ;
unsigned int V_15 = V_7 [ 1 ] ;
V_4 -> V_16 = F_2 ( V_9 -> V_11 + V_17 ) ;
if ( V_14 ) {
V_4 -> V_16 &= ~ V_14 ;
V_4 -> V_16 |= ( V_15 & V_14 ) ;
F_4 ( V_4 -> V_16 , V_9 -> V_11 + V_17 ) ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( V_7 [ 0 ] ,
V_9 -> V_11 + V_18 +
V_19 ) ;
if ( V_7 [ 0 ] ) {
V_9 -> V_20 = V_21 ;
} else {
V_9 -> V_20 = V_22 ;
}
return V_6 -> V_13 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_23 = 0 , V_24 , V_25 , V_26 = 0 ;
V_24 = F_7 ( V_6 -> V_27 ) ;
if ( V_9 -> V_20 == V_21 ) {
V_25 = 0x80000000 ;
if ( ( * V_7 < 0 ) || ( * V_7 > 16384 ) ) {
F_8 ( L_1 ) ;
}
}
else {
V_25 = 0 ;
if ( ( * V_7 < 0 ) || ( * V_7 > 8192 ) ) {
F_8 ( L_1 ) ;
}
}
if ( ( V_24 < 0 ) || ( V_24 > 7 ) ) {
F_8 ( L_2 ) ;
}
V_26 = F_2 ( V_9 -> V_11 + V_18 ) ;
while ( V_26 == 0 ) {
V_26 = F_2 ( V_9 -> V_11 + V_18 ) ;
V_26 = ( V_26 >> 8 ) & 1 ;
}
if ( V_26 ) {
V_23 =
( unsigned int ) ( ( unsigned int ) ( V_24 & 0xFF ) |
( unsigned int ) ( ( * V_7 << 0x8 ) & 0x7FFFFF00L ) |
( unsigned int ) ( V_25 ) ) ;
F_4 ( V_23 ,
V_9 -> V_11 + V_18 +
V_28 ) ;
}
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_23 = 0 ;
V_9 -> V_29 = V_30 ;
if ( V_7 [ 0 ] == V_31 ) {
V_9 -> V_32 = V_31 ;
F_4 ( 0x0 , V_9 -> V_11 + V_33 + V_34 ) ;
if ( V_7 [ 1 ] == 1 ) {
F_4 ( 0x02 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
} else {
F_4 ( 0x0 , V_9 -> V_11 + V_33 + V_34 ) ;
}
F_4 ( V_7 [ 2 ] ,
V_9 -> V_11 + V_33 +
V_35 ) ;
F_4 ( V_7 [ 3 ] ,
V_9 -> V_11 + V_33 +
V_36 ) ;
V_23 = F_2 ( V_9 -> V_11 + V_33 + V_34 ) | 0xFFF819E0UL ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
}
else if ( V_7 [ 0 ] == V_37 ) {
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = V_23 & 0xFFFFF9FEUL ;
F_4 ( V_23 , V_9 -> V_11 + V_33 + V_34 ) ;
V_9 -> V_32 = V_37 ;
if ( V_7 [ 1 ] == 1 ) {
F_4 ( 0x02 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
} else {
F_4 ( 0x0 , V_9 -> V_11 + V_33 + V_34 ) ;
}
F_4 ( V_7 [ 2 ] ,
V_9 -> V_11 + V_33 +
V_35 ) ;
F_4 ( V_7 [ 3 ] ,
V_9 -> V_11 + V_33 +
V_36 ) ;
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 =
( V_23 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_4 ( V_23 , V_9 -> V_11 + V_33 + V_34 ) ;
}
return V_6 -> V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_23 = 0 ;
int V_38 ;
if ( V_9 -> V_32 == V_31 ) {
if ( V_7 [ 1 ] == 1 ) {
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = ( V_23 & 0xFFFFF9FFUL ) | 0x1UL ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
}
else if ( V_7 [ 1 ] == 0 )
{
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = V_23 & 0xFFFFF9FEUL ;
F_4 ( 0x0 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
} else if ( V_7 [ 1 ] == 2 ) {
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = ( V_23 & 0xFFFFF9FFUL ) | 0x200UL ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
}
}
if ( V_9 -> V_32 == V_37 ) {
if ( V_7 [ 1 ] == 1 ) {
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = ( V_23 & 0xFFFFF9FFUL ) | 0x1UL ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = V_23 & 0xFFFFF9FEUL ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
}
else if ( V_7 [ 1 ] == 2 ) {
V_23 =
F_2 ( V_9 -> V_11 + V_33 +
V_34 ) ;
V_23 = ( V_23 & 0xFFFFF9FFUL ) | 0x200UL ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 +
V_34 ) ;
}
}
V_38 = F_2 ( V_9 -> V_11 + V_33 +
V_39 ) & 0x1 ;
return V_6 -> V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_32 == V_31 ) {
V_7 [ 0 ] =
F_2 ( V_9 -> V_11 + V_33 +
V_39 ) & 0x1 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_11 + V_33 ) ;
}
else if ( V_9 -> V_32 == V_37 ) {
V_7 [ 0 ] =
F_2 ( V_9 -> V_11 + V_33 +
V_39 ) & 0x1 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_11 + V_33 ) ;
}
else if ( ( V_9 -> V_32 != V_37 )
&& ( V_9 -> V_32 != V_31 ) ) {
F_8 ( L_3 ) ;
}
return V_6 -> V_13 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_40 = 0 , V_41 = 0 ;
unsigned int V_23 = 0 , V_25 , V_26 = 0 ;
F_4 ( 0x0 , V_9 -> V_11 + V_17 ) ;
F_4 ( 1 , V_9 -> V_11 + V_18 +
V_19 ) ;
V_25 = 0x80000000 ;
for ( V_40 = 0 ; V_40 <= 7 ; V_40 ++ ) {
V_26 = F_2 ( V_9 -> V_11 + V_18 ) ;
while ( V_26 == 0 ) {
V_26 =
F_2 ( V_9 -> V_11 + V_18 ) ;
V_26 = ( V_26 >> 8 ) & 1 ;
}
if ( V_26 ) {
V_23 =
( unsigned int ) ( ( unsigned int ) ( V_40 & 0xFF ) |
( unsigned int ) ( ( V_41 << 0x8 ) & 0x7FFFFF00L ) |
( unsigned int ) ( V_25 ) ) ;
F_4 ( V_23 ,
V_9 -> V_11 + V_18 +
V_28 ) ;
}
}
return 0 ;
}
static void F_13 ( int V_42 , void * V_43 )
{
int V_41 ;
struct V_1 * V_2 = V_43 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_44 ;
unsigned long V_23 ;
V_23 =
F_2 ( V_9 -> V_11 + V_33 + V_34 ) ;
V_23 = ( V_23 & 0xFFFFF9FDul ) ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 + V_34 ) ;
V_44 =
F_2 ( V_9 -> V_11 + V_33 +
V_45 ) & 0x1 ;
if ( ( ! V_44 ) ) {
F_14 ( V_2 , L_4 ) ;
return;
}
F_15 ( V_46 , V_9 -> V_29 , 0 ) ;
V_23 =
F_2 ( V_9 -> V_11 + V_33 + V_34 ) ;
V_23 = ( ( V_23 & 0xFFFFF9FDul ) | 1 << 1 ) ;
F_4 ( V_23 ,
V_9 -> V_11 + V_33 + V_34 ) ;
V_41 = F_2 ( V_9 -> V_11 + V_33 +
V_39 ) & 0x1 ;
return;
}
