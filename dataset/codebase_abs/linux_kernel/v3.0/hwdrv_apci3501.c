int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 ;
V_9 = F_2 ( V_6 -> V_10 ) ;
V_8 = V_7 [ 0 ] ;
* V_7 = F_3 ( V_11 -> V_12 + V_13 ) ;
if ( V_8 == 0 ) {
* V_7 = ( * V_7 >> V_9 ) & 0x1 ;
}
else {
if ( V_8 == 1 ) {
* V_7 = * V_7 & 0x3 ;
}
else {
F_4 ( L_1 ) ;
}
}
return V_6 -> V_14 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_6 ( V_2 ,
L_2 ) ;
return - V_15 ;
}
if ( V_7 [ 0 ] ) {
V_11 -> V_16 = V_17 ;
}
else {
V_11 -> V_16 = V_18 ;
}
return V_6 -> V_14 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 , V_19 ;
unsigned int V_9 = F_2 ( V_6 -> V_10 ) ;
if ( V_11 -> V_16 ) {
V_8 = F_3 ( V_11 -> V_12 + V_20 ) ;
}
else {
V_8 = 0 ;
}
if ( V_7 [ 3 ] == 0 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ( V_7 [ 0 ] << V_9 ) | V_8 ;
F_8 ( V_7 [ 0 ] , V_11 -> V_12 + V_20 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
V_7 [ 0 ] = ( V_7 [ 0 ] << ( 2 * V_7 [ 2 ] ) ) | V_8 ;
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 + V_20 ) ;
}
else {
F_4 ( L_3 ) ;
}
}
}
else {
if ( V_7 [ 3 ] == 1 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x1 ;
V_19 = 1 ;
V_19 = V_19 << V_9 ;
V_8 = V_8 | V_19 ;
V_7 [ 0 ] =
( V_7 [ 0 ] << V_9 ) ^
0xffffffff ;
V_7 [ 0 ] = V_7 [ 0 ] & V_8 ;
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 + V_20 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x3 ;
V_19 = 3 ;
V_19 = V_19 << 2 * V_7 [ 2 ] ;
V_8 = V_8 | V_19 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 2 *
V_7 [ 2 ] ) ) ^
0xffffffff ) & V_8 ;
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 +
V_20 ) ;
}
else {
F_4 ( L_3 ) ;
}
}
}
else {
F_4 ( L_4 ) ;
return - V_15 ;
}
}
return V_6 -> V_14 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 ;
V_9 = F_2 ( V_6 -> V_10 ) ;
V_8 = V_7 [ 0 ] ;
* V_7 = F_3 ( V_11 -> V_12 + V_20 ) ;
if ( V_8 == 0 ) {
* V_7 = ( * V_7 >> V_9 ) & 0x1 ;
}
else {
if ( V_8 == 1 ) {
* V_7 = * V_7 & 0x3 ;
}
else {
F_4 ( L_1 ) ;
}
}
return V_6 -> V_14 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_8 ( V_7 [ 0 ] ,
V_11 -> V_12 + V_21 +
V_22 ) ;
if ( V_7 [ 0 ] ) {
V_11 -> V_23 = V_24 ;
} else {
V_11 -> V_23 = V_25 ;
}
return V_6 -> V_14 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_26 = 0 , V_27 , V_28 , V_29 = 0 ;
V_27 = F_2 ( V_6 -> V_10 ) ;
if ( V_11 -> V_23 == V_24 ) {
V_28 = 0x80000000 ;
if ( ( * V_7 < 0 ) || ( * V_7 > 16384 ) ) {
F_4 ( L_5 ) ;
}
}
else {
V_28 = 0 ;
if ( ( * V_7 < 0 ) || ( * V_7 > 8192 ) ) {
F_4 ( L_5 ) ;
}
}
if ( ( V_27 < 0 ) || ( V_27 > 7 ) ) {
F_4 ( L_6 ) ;
}
V_29 = F_3 ( V_11 -> V_12 + V_21 ) ;
while ( V_29 == 0 ) {
V_29 = F_3 ( V_11 -> V_12 + V_21 ) ;
V_29 = ( V_29 >> 8 ) & 1 ;
}
if ( V_29 ) {
V_26 =
( unsigned int ) ( ( unsigned int ) ( V_27 & 0xFF ) |
( unsigned int ) ( ( * V_7 << 0x8 ) & 0x7FFFFF00L ) |
( unsigned int ) ( V_28 ) ) ;
F_8 ( V_26 ,
V_11 -> V_12 + V_21 +
V_30 ) ;
}
return V_6 -> V_14 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_26 = 0 ;
V_11 -> V_31 = V_32 ;
if ( V_7 [ 0 ] == V_33 ) {
V_11 -> V_34 = V_33 ;
F_8 ( 0x0 , V_11 -> V_12 + V_35 + V_36 ) ;
if ( V_7 [ 1 ] == 1 ) {
F_8 ( 0x02 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
} else {
F_8 ( 0x0 , V_11 -> V_12 + V_35 + V_36 ) ;
}
F_8 ( V_7 [ 2 ] ,
V_11 -> V_12 + V_35 +
V_37 ) ;
F_8 ( V_7 [ 3 ] ,
V_11 -> V_12 + V_35 +
V_38 ) ;
V_26 = F_3 ( V_11 -> V_12 + V_35 + V_36 ) | 0xFFF819E0UL ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
}
else if ( V_7 [ 0 ] == V_39 ) {
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = V_26 & 0xFFFFF9FEUL ;
F_8 ( V_26 , V_11 -> V_12 + V_35 + V_36 ) ;
V_11 -> V_34 = V_39 ;
if ( V_7 [ 1 ] == 1 ) {
F_8 ( 0x02 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
} else {
F_8 ( 0x0 , V_11 -> V_12 + V_35 + V_36 ) ;
}
F_8 ( V_7 [ 2 ] ,
V_11 -> V_12 + V_35 +
V_37 ) ;
F_8 ( V_7 [ 3 ] ,
V_11 -> V_12 + V_35 +
V_38 ) ;
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 =
( V_26 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_8 ( V_26 , V_11 -> V_12 + V_35 + V_36 ) ;
}
return V_6 -> V_14 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_26 = 0 ;
int V_40 ;
if ( V_11 -> V_34 == V_33 ) {
if ( V_7 [ 1 ] == 1 ) {
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x1UL ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
}
else if ( V_7 [ 1 ] == 0 )
{
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = V_26 & 0xFFFFF9FEUL ;
F_8 ( 0x0 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
} else if ( V_7 [ 1 ] == 2 ) {
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x200UL ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
}
}
if ( V_11 -> V_34 == V_39 ) {
if ( V_7 [ 1 ] == 1 ) {
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x1UL ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = V_26 & 0xFFFFF9FEUL ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
}
else if ( V_7 [ 1 ] == 2 ) {
V_26 =
F_3 ( V_11 -> V_12 + V_35 +
V_36 ) ;
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x200UL ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 +
V_36 ) ;
}
}
V_40 = F_3 ( V_11 -> V_12 + V_35 +
V_41 ) & 0x1 ;
return V_6 -> V_14 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_11 -> V_34 == V_33 ) {
V_7 [ 0 ] =
F_3 ( V_11 -> V_12 + V_35 +
V_41 ) & 0x1 ;
V_7 [ 1 ] = F_3 ( V_11 -> V_12 + V_35 ) ;
}
else if ( V_11 -> V_34 == V_39 ) {
V_7 [ 0 ] =
F_3 ( V_11 -> V_12 + V_35 +
V_41 ) & 0x1 ;
V_7 [ 1 ] = F_3 ( V_11 -> V_12 + V_35 ) ;
}
else if ( ( V_11 -> V_34 != V_39 )
&& ( V_11 -> V_34 != V_33 ) ) {
F_4 ( L_7 ) ;
}
return V_6 -> V_14 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_42 = 0 , V_43 = 0 ;
unsigned int V_26 = 0 , V_28 , V_29 = 0 ;
F_8 ( 0x0 , V_11 -> V_12 + V_20 ) ;
F_8 ( 1 , V_11 -> V_12 + V_21 +
V_22 ) ;
V_28 = 0x80000000 ;
for ( V_42 = 0 ; V_42 <= 7 ; V_42 ++ ) {
V_29 = F_3 ( V_11 -> V_12 + V_21 ) ;
while ( V_29 == 0 ) {
V_29 =
F_3 ( V_11 -> V_12 + V_21 ) ;
V_29 = ( V_29 >> 8 ) & 1 ;
}
if ( V_29 ) {
V_26 =
( unsigned int ) ( ( unsigned int ) ( V_42 & 0xFF ) |
( unsigned int ) ( ( V_43 << 0x8 ) & 0x7FFFFF00L ) |
( unsigned int ) ( V_28 ) ) ;
F_8 ( V_26 ,
V_11 -> V_12 + V_21 +
V_30 ) ;
}
}
return 0 ;
}
void F_16 ( int V_44 , void * V_45 )
{
int V_43 ;
struct V_1 * V_2 = V_45 ;
unsigned int V_46 ;
unsigned long V_26 ;
V_26 =
F_3 ( V_11 -> V_12 + V_35 + V_36 ) ;
V_26 = ( V_26 & 0xFFFFF9FDul ) ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 + V_36 ) ;
V_46 =
F_3 ( V_11 -> V_12 + V_35 +
V_47 ) & 0x1 ;
if ( ( ! V_46 ) ) {
F_6 ( V_2 , L_8 ) ;
return;
}
F_17 ( V_48 , V_11 -> V_31 , 0 ) ;
V_26 =
F_3 ( V_11 -> V_12 + V_35 + V_36 ) ;
V_26 = ( ( V_26 & 0xFFFFF9FDul ) | 1 << 1 ) ;
F_8 ( V_26 ,
V_11 -> V_12 + V_35 + V_36 ) ;
V_43 = F_3 ( V_11 -> V_12 + V_35 +
V_41 ) & 0x1 ;
return;
}
