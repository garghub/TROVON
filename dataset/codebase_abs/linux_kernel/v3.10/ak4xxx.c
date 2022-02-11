static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 [ 0 ] ;
F_2 ( V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 [ 0 ] ;
F_4 ( V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_7 , unsigned char V_8 )
{
unsigned int V_9 ;
int V_10 ;
unsigned int V_11 ;
struct V_12 * V_13 = ( void * ) V_2 -> V_14 [ 0 ] ;
struct V_4 * V_5 = V_2 -> V_6 [ 0 ] ;
if ( F_6 ( V_3 < 0 || V_3 >= 4 ) )
return;
V_9 = F_7 ( V_5 ) ;
V_9 |= V_13 -> V_15 ;
V_9 &= ~ V_13 -> V_16 ;
if ( V_13 -> V_17 == V_13 -> V_18 ) {
if ( V_13 -> V_19 ) {
V_9 |= V_13 -> V_17 ;
} else {
V_9 &= ~ V_13 -> V_17 ;
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
}
} else {
V_9 &= ~ V_13 -> V_17 ;
V_9 |= V_13 -> V_18 ;
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
}
V_11 = ( V_13 -> V_20 << 6 ) | 0x20 | ( V_7 & 0x1f ) ;
V_11 = ( V_11 << 8 ) | V_8 ;
for ( V_10 = 15 ; V_10 >= 0 ; V_10 -- ) {
V_9 &= ~ V_13 -> V_21 ;
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
if ( V_11 & ( 1 << V_10 ) )
V_9 |= V_13 -> V_22 ;
else
V_9 &= ~ V_13 -> V_22 ;
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
V_9 |= V_13 -> V_21 ;
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
}
if ( V_13 -> V_17 == V_13 -> V_18 ) {
if ( V_13 -> V_19 ) {
V_9 &= ~ V_13 -> V_17 ;
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
}
V_9 |= V_13 -> V_17 ;
} else {
V_9 &= ~ V_13 -> V_17 ;
V_9 |= V_13 -> V_23 ;
}
F_8 ( V_5 , V_9 ) ;
F_9 ( 1 ) ;
}
int F_10 ( struct V_1 * V_2 , const struct V_1 * V_24 ,
const struct V_12 * V_25 , struct V_4 * V_5 )
{
struct V_12 * V_13 ;
if ( V_25 != NULL ) {
V_13 = F_11 ( sizeof( * V_13 ) , V_26 ) ;
if ( V_13 == NULL )
return - V_27 ;
* V_13 = * V_25 ;
} else {
V_13 = NULL ;
}
* V_2 = * V_24 ;
V_2 -> V_28 = V_5 -> V_28 ;
V_2 -> V_14 [ 0 ] = ( unsigned long ) V_13 ;
V_2 -> V_6 [ 0 ] = V_5 ;
if ( V_2 -> V_29 . V_30 == NULL )
V_2 -> V_29 . V_30 = F_1 ;
if ( V_2 -> V_29 . V_31 == NULL )
V_2 -> V_29 . V_31 = F_3 ;
if ( V_2 -> V_29 . V_32 == NULL )
V_2 -> V_29 . V_32 = F_5 ;
F_12 ( V_2 ) ;
return 0 ;
}
void F_13 ( struct V_4 * V_5 )
{
unsigned int V_33 ;
if ( V_5 -> V_34 == NULL )
return;
for ( V_33 = 0 ; V_33 < V_5 -> V_35 ; V_33 ++ ) {
struct V_1 * V_2 = & V_5 -> V_34 [ V_33 ] ;
F_14 ( ( void * ) V_2 -> V_14 [ 0 ] ) ;
}
F_14 ( V_5 -> V_34 ) ;
}
int F_15 ( struct V_4 * V_5 )
{
unsigned int V_33 ;
int V_36 ;
for ( V_33 = 0 ; V_33 < V_5 -> V_35 ; V_33 ++ ) {
struct V_1 * V_2 = & V_5 -> V_34 [ V_33 ] ;
V_36 = F_16 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static int T_1 F_17 ( void )
{
return 0 ;
}
static void T_2 F_18 ( void )
{
}
