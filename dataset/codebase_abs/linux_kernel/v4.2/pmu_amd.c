static unsigned F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ )
if ( V_6 [ V_5 ] . V_7 == V_3
&& V_6 [ V_5 ] . V_4 == V_4 )
break;
if ( V_5 == F_2 ( V_6 ) )
return V_8 ;
return V_6 [ V_5 ] . V_9 ;
}
static unsigned F_3 ( int V_10 )
{
return V_8 ;
}
static bool F_4 ( struct V_11 * V_12 )
{
return true ;
}
static struct V_11 * F_5 ( struct V_1 * V_2 , int V_13 )
{
return F_6 ( V_2 , V_14 + V_13 , V_14 ) ;
}
static int F_7 ( struct V_15 * V_16 , unsigned V_10 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_10 &= ~ ( 3u << 30 ) ;
return ( V_10 >= V_2 -> V_17 ) ;
}
static struct V_11 * F_9 ( struct V_15 * V_16 , unsigned V_10 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_11 * V_18 ;
V_10 &= ~ ( 3u << 30 ) ;
if ( V_10 >= V_2 -> V_17 )
return NULL ;
V_18 = V_2 -> V_19 ;
return & V_18 [ V_10 ] ;
}
static bool F_10 ( struct V_15 * V_16 , T_2 V_20 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_21 = false ;
V_21 = F_6 ( V_2 , V_20 , V_22 ) ||
F_6 ( V_2 , V_20 , V_14 ) ;
return V_21 ;
}
static int F_11 ( struct V_15 * V_16 , T_2 V_20 , T_3 * V_23 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_11 * V_12 ;
V_12 = F_6 ( V_2 , V_20 , V_22 ) ;
if ( V_12 ) {
* V_23 = F_12 ( V_12 ) ;
return 0 ;
}
V_12 = F_6 ( V_2 , V_20 , V_14 ) ;
if ( V_12 ) {
* V_23 = V_12 -> V_7 ;
return 0 ;
}
return 1 ;
}
static int F_13 ( struct V_15 * V_16 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_11 * V_12 ;
T_2 V_20 = V_25 -> V_26 ;
T_3 V_23 = V_25 -> V_23 ;
V_12 = F_6 ( V_2 , V_20 , V_22 ) ;
if ( V_12 ) {
if ( ! V_25 -> V_27 )
V_23 = ( V_28 ) V_23 ;
V_12 -> V_29 += V_23 - F_12 ( V_12 ) ;
return 0 ;
}
V_12 = F_6 ( V_2 , V_20 , V_14 ) ;
if ( V_12 ) {
if ( V_23 == V_12 -> V_7 )
return 0 ;
if ( ! ( V_23 & V_2 -> V_30 ) ) {
F_14 ( V_12 , V_23 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_15 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_2 -> V_17 = V_31 ;
V_2 -> V_32 [ V_33 ] = ( ( T_3 ) 1 << 48 ) - 1 ;
V_2 -> V_30 = 0xffffffff00200000ull ;
V_2 -> V_32 [ V_34 ] = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
V_2 -> V_19 [ V_5 ] . type = V_33 ;
V_2 -> V_19 [ V_5 ] . V_16 = V_16 ;
V_2 -> V_19 [ V_5 ] . V_10 = V_5 ;
}
}
static void F_17 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_31 ; V_5 ++ ) {
struct V_11 * V_12 = & V_2 -> V_19 [ V_5 ] ;
F_18 ( V_12 ) ;
V_12 -> V_29 = V_12 -> V_7 = 0 ;
}
}
