void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
unsigned long * V_6 )
{
T_1 V_7 = 1 ;
T_2 V_8 ;
int V_9 ;
if ( ! ( ( V_2 -> V_10 & V_11 ) ||
( V_2 -> V_10 & V_12 ) ) )
return;
V_8 = F_2 ( V_2 -> V_13 + V_2 -> V_8 ) ;
if ( V_5 < 0 ) {
V_5 = V_8 >> V_4 -> V_14 ;
V_5 &= ( 1 << V_4 -> V_15 ) - 1 ;
}
if ( V_2 -> V_10 & V_11 )
for ( V_9 = 0 ; V_9 < V_4 -> V_16 ; V_9 ++ )
if ( V_5 == V_4 -> V_17 [ V_9 ] . V_18 )
V_7 = V_4 -> V_17 [ V_9 ] . div ;
if ( V_2 -> V_10 & V_12 )
if ( V_5 == V_4 -> V_19 . V_18 ) {
T_3 div ;
div = V_8 >> V_4 -> V_19 . V_14 ;
div &= ( 1 << V_4 -> V_19 . V_15 ) - 1 ;
V_7 = div + 1 ;
}
* V_6 = * V_6 / V_7 ;
}
T_3 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_8 ;
T_3 V_20 ;
V_8 = F_2 ( V_2 -> V_13 + V_2 -> V_8 ) ;
V_20 = V_8 >> V_4 -> V_14 ;
V_20 &= ( 1 << V_4 -> V_15 ) - 1 ;
if ( V_4 -> V_21 ) {
int V_22 = F_4 ( & V_2 -> V_23 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ )
if ( V_4 -> V_21 [ V_9 ] == V_20 )
return V_9 ;
}
return V_20 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 V_18 )
{
unsigned long V_24 ;
T_2 V_8 ;
if ( V_4 -> V_21 )
V_18 = V_4 -> V_21 [ V_18 ] ;
F_6 ( V_2 -> V_25 , V_24 ) ;
V_8 = F_2 ( V_2 -> V_13 + V_2 -> V_8 ) ;
V_8 &= ~ F_7 ( V_4 -> V_15 + V_4 -> V_14 - 1 , V_4 -> V_14 ) ;
F_8 ( V_8 | ( V_18 << V_4 -> V_14 ) , V_2 -> V_13 + V_2 -> V_8 ) ;
F_9 ( V_2 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_10 ( struct V_26 * V_23 )
{
struct V_27 * V_4 = F_11 ( V_23 ) ;
return F_12 ( & V_4 -> V_2 , V_4 -> V_28 ) ;
}
static int F_13 ( struct V_26 * V_23 )
{
struct V_27 * V_4 = F_11 ( V_23 ) ;
return F_14 ( & V_4 -> V_2 , V_4 -> V_28 ) ;
}
static int F_15 ( struct V_26 * V_23 )
{
struct V_27 * V_4 = F_11 ( V_23 ) ;
return F_16 ( & V_4 -> V_2 , V_4 -> V_28 ) ;
}
static T_3 F_17 ( struct V_26 * V_23 )
{
struct V_27 * V_4 = F_11 ( V_23 ) ;
return F_3 ( & V_4 -> V_2 , & V_4 -> V_29 ) ;
}
static int F_18 ( struct V_26 * V_23 , T_3 V_18 )
{
struct V_27 * V_4 = F_11 ( V_23 ) ;
return F_5 ( & V_4 -> V_2 , & V_4 -> V_29 , V_18 ) ;
}
static unsigned long F_19 ( struct V_26 * V_23 ,
unsigned long V_6 )
{
struct V_27 * V_4 = F_11 ( V_23 ) ;
F_1 ( & V_4 -> V_2 , & V_4 -> V_29 , - 1 ,
& V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_34 * V_29 = F_21 ( V_31 ) ;
int V_35 = 0 ;
if ( V_32 == V_36 ) {
V_29 -> V_37 = F_3 ( V_29 -> V_2 ,
V_29 -> V_4 ) ;
V_35 = F_5 ( V_29 -> V_2 , V_29 -> V_4 ,
V_29 -> V_38 ) ;
} else if ( V_32 == V_39 ) {
V_35 = F_5 ( V_29 -> V_2 , V_29 -> V_4 ,
V_29 -> V_37 ) ;
}
F_22 ( V_29 -> V_40 ) ;
return F_23 ( V_35 ) ;
}
int F_24 ( struct V_41 * V_41 , struct V_34 * V_42 )
{
V_42 -> V_43 . V_44 = F_20 ;
return F_25 ( V_41 , & V_42 -> V_43 ) ;
}
