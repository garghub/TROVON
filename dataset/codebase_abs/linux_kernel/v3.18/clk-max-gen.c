static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_4 ( V_4 -> V_5 , V_4 -> V_6 ,
V_4 -> V_7 , V_4 -> V_7 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_5 , V_4 -> V_6 ,
V_4 -> V_7 , ~ V_4 -> V_7 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 ;
T_1 V_9 ;
V_8 = F_7 ( V_4 -> V_5 , V_4 -> V_6 , & V_9 ) ;
if ( V_8 < 0 )
return - V_10 ;
return V_9 & V_4 -> V_7 ;
}
static unsigned long F_8 ( struct V_2 * V_3 ,
unsigned long V_11 )
{
return 32768 ;
}
static struct V_12 * F_9 ( struct V_13 * V_14 ,
struct V_1 * V_4 )
{
struct V_12 * V_12 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_8 ;
V_12 = F_10 ( V_14 , V_3 ) ;
if ( F_11 ( V_12 ) )
return V_12 ;
V_8 = F_12 ( V_12 , V_3 -> V_15 -> V_16 , NULL ) ;
if ( V_8 )
return F_13 ( V_8 ) ;
return V_12 ;
}
int F_14 ( struct V_17 * V_18 , struct V_5 * V_5 ,
T_1 V_6 , struct V_19 * V_20 , int V_21 )
{
int V_22 , V_8 ;
struct V_1 * V_23 ;
struct V_12 * * V_24 ;
struct V_13 * V_14 = V_18 -> V_14 . V_25 ;
const char * V_26 ;
struct V_19 * V_15 ;
V_24 = F_15 ( V_14 , sizeof( struct V_12 * ) * V_21 , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
V_23 = F_15 ( V_14 , sizeof( struct V_1 )
* V_21 , V_27 ) ;
if ( ! V_23 )
return - V_28 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_23 [ V_22 ] . V_5 = V_5 ;
V_23 [ V_22 ] . V_7 = 1 << V_22 ;
V_23 [ V_22 ] . V_6 = V_6 ;
V_15 = F_15 ( V_14 , sizeof( * V_15 ) , V_27 ) ;
if ( ! V_15 )
return - V_28 ;
if ( V_14 -> V_29 &&
! F_16 ( V_14 -> V_29 ,
L_1 ,
V_22 , & V_26 ) )
V_15 -> V_16 = V_26 ;
else
V_15 -> V_16 = V_20 [ V_22 ] . V_16 ;
V_15 -> V_30 = V_20 [ V_22 ] . V_30 ;
V_15 -> V_31 = V_20 [ V_22 ] . V_31 ;
V_23 [ V_22 ] . V_3 . V_15 = V_15 ;
V_24 [ V_22 ] = F_9 ( V_14 , & V_23 [ V_22 ] ) ;
if ( F_11 ( V_24 [ V_22 ] ) ) {
V_8 = F_17 ( V_24 [ V_22 ] ) ;
F_18 ( V_14 , L_2 ,
V_23 [ V_22 ] . V_3 . V_15 -> V_16 ) ;
return V_8 ;
}
}
F_19 ( V_18 , V_24 ) ;
if ( V_14 -> V_29 ) {
struct V_32 * V_33 ;
V_33 = F_15 ( V_14 , sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_28 ;
V_33 -> V_34 = V_24 ;
V_33 -> V_35 = V_21 ;
V_8 = F_20 ( V_14 -> V_29 , V_36 ,
V_33 ) ;
if ( V_8 ) {
F_18 ( V_14 , L_3 ) ;
return V_8 ;
}
}
return 0 ;
}
int F_21 ( struct V_17 * V_18 , int V_21 )
{
struct V_13 * V_14 = V_18 -> V_14 . V_25 ;
if ( V_14 -> V_29 )
F_22 ( V_14 -> V_29 ) ;
return 0 ;
}
