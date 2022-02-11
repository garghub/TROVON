void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
unsigned long * V_6 )
{
T_1 V_7 = 1 ;
T_2 V_8 ;
int V_9 ;
if ( ! ( ( V_2 -> V_10 & V_11 ) ||
( V_2 -> V_10 & V_12 ) ||
( V_2 -> V_10 & V_13 ) ) )
return;
if ( V_2 -> V_10 & V_13 ) {
* V_6 = * V_6 / V_2 -> V_7 ;
return;
}
V_8 = F_2 ( V_2 -> V_14 + V_2 -> V_8 ) ;
if ( V_5 < 0 ) {
V_5 = V_8 >> V_4 -> V_15 ;
V_5 &= ( 1 << V_4 -> V_16 ) - 1 ;
}
if ( V_2 -> V_10 & V_11 )
for ( V_9 = 0 ; V_9 < V_4 -> V_17 ; V_9 ++ )
if ( V_5 == V_4 -> V_18 [ V_9 ] . V_19 )
V_7 = V_4 -> V_18 [ V_9 ] . div ;
if ( V_2 -> V_10 & V_12 )
if ( V_5 == V_4 -> V_20 . V_19 ) {
T_3 div ;
div = V_8 >> V_4 -> V_20 . V_15 ;
div &= ( 1 << V_4 -> V_20 . V_16 ) - 1 ;
V_7 = div + 1 ;
}
* V_6 = * V_6 / V_7 ;
}
T_3 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_8 ;
T_3 V_21 ;
V_8 = F_2 ( V_2 -> V_14 + V_2 -> V_8 ) ;
V_21 = V_8 >> V_4 -> V_15 ;
V_21 &= ( 1 << V_4 -> V_16 ) - 1 ;
if ( V_4 -> V_22 ) {
int V_23 = F_4 ( & V_2 -> V_24 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_23 ; V_9 ++ )
if ( V_4 -> V_22 [ V_9 ] == V_21 )
return V_9 ;
}
return V_21 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 V_19 )
{
unsigned long V_25 ;
T_2 V_8 ;
if ( V_4 -> V_22 )
V_19 = V_4 -> V_22 [ V_19 ] ;
F_6 ( V_2 -> V_26 , V_25 ) ;
V_8 = F_2 ( V_2 -> V_14 + V_2 -> V_8 ) ;
V_8 &= ~ F_7 ( V_4 -> V_16 + V_4 -> V_15 - 1 , V_4 -> V_15 ) ;
F_8 ( V_8 | ( V_19 << V_4 -> V_15 ) , V_2 -> V_14 + V_2 -> V_8 ) ;
F_9 ( V_2 -> V_26 , V_25 ) ;
return 0 ;
}
static void F_10 ( struct V_27 * V_24 )
{
struct V_28 * V_4 = F_11 ( V_24 ) ;
return F_12 ( & V_4 -> V_2 , V_4 -> V_29 ) ;
}
static int F_13 ( struct V_27 * V_24 )
{
struct V_28 * V_4 = F_11 ( V_24 ) ;
return F_14 ( & V_4 -> V_2 , V_4 -> V_29 ) ;
}
static int F_15 ( struct V_27 * V_24 )
{
struct V_28 * V_4 = F_11 ( V_24 ) ;
return F_16 ( & V_4 -> V_2 , V_4 -> V_29 ) ;
}
static T_3 F_17 ( struct V_27 * V_24 )
{
struct V_28 * V_4 = F_11 ( V_24 ) ;
return F_3 ( & V_4 -> V_2 , & V_4 -> V_30 ) ;
}
static int F_18 ( struct V_27 * V_24 , T_3 V_19 )
{
struct V_28 * V_4 = F_11 ( V_24 ) ;
return F_5 ( & V_4 -> V_2 , & V_4 -> V_30 , V_19 ) ;
}
static unsigned long F_19 ( struct V_27 * V_24 ,
unsigned long V_6 )
{
struct V_28 * V_4 = F_11 ( V_24 ) ;
F_1 ( & V_4 -> V_2 , & V_4 -> V_30 , - 1 ,
& V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_35 * V_30 = F_21 ( V_32 ) ;
int V_36 = 0 ;
if ( V_33 == V_37 ) {
V_30 -> V_38 = F_3 ( V_30 -> V_2 ,
V_30 -> V_4 ) ;
V_36 = F_5 ( V_30 -> V_2 , V_30 -> V_4 ,
V_30 -> V_39 ) ;
} else if ( V_33 == V_40 ) {
V_36 = F_5 ( V_30 -> V_2 , V_30 -> V_4 ,
V_30 -> V_38 ) ;
}
F_22 ( V_30 -> V_41 ) ;
return F_23 ( V_36 ) ;
}
int F_24 ( struct V_42 * V_42 , struct V_35 * V_43 )
{
V_43 -> V_44 . V_45 = F_20 ;
return F_25 ( V_42 , & V_43 -> V_44 ) ;
}
