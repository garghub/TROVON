static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
T_1 V_6 = 1 ;
T_2 V_7 ;
if ( ! ( ( V_2 -> V_8 & V_9 ) ||
( V_2 -> V_8 & V_10 ) ||
( V_2 -> V_8 & V_11 ) ) )
return 1 ;
if ( V_2 -> V_8 & V_11 )
return V_2 -> V_6 ;
V_7 = F_2 ( V_2 -> V_12 + V_2 -> V_7 ) ;
if ( V_5 < 0 ) {
V_5 = V_7 >> V_4 -> V_13 ;
V_5 &= ( 1 << V_4 -> V_14 ) - 1 ;
}
if ( V_2 -> V_8 & V_9 ) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_16 ; V_15 ++ )
if ( V_5 == V_4 -> V_17 [ V_15 ] . V_18 )
V_6 = V_4 -> V_17 [ V_15 ] . div ;
}
if ( V_2 -> V_8 & V_10 ) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_19 ; V_15 ++ )
if ( V_5 == V_4 -> V_20 [ V_15 ] . V_18 ) {
T_3 div ;
div = V_7 >> V_4 -> V_20 [ V_15 ] . V_13 ;
div &= ( 1 << V_4 -> V_20 [ V_15 ] . V_14 ) - 1 ;
V_6 = div + 1 ;
}
}
return V_6 ;
}
unsigned long F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
unsigned long V_21 )
{
return V_21 / F_1 ( V_2 , V_4 , V_5 ) ;
}
static unsigned long F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
unsigned long V_21 )
{
return V_21 * F_1 ( V_2 , V_4 , V_5 ) ;
}
T_3 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_7 ;
T_3 V_22 ;
V_7 = F_2 ( V_2 -> V_12 + V_2 -> V_7 ) ;
V_22 = V_7 >> V_4 -> V_13 ;
V_22 &= ( 1 << V_4 -> V_14 ) - 1 ;
if ( V_4 -> V_23 ) {
int V_24 = F_6 ( & V_2 -> V_25 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ )
if ( V_4 -> V_23 [ V_15 ] == V_22 )
return V_15 ;
}
return V_22 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 V_18 )
{
unsigned long V_26 ;
T_2 V_7 ;
if ( V_4 -> V_23 )
V_18 = V_4 -> V_23 [ V_18 ] ;
F_8 ( V_2 -> V_27 , V_26 ) ;
V_7 = F_2 ( V_2 -> V_12 + V_2 -> V_7 ) ;
V_7 &= ~ F_9 ( V_4 -> V_14 + V_4 -> V_13 - 1 , V_4 -> V_13 ) ;
F_10 ( V_7 | ( V_18 << V_4 -> V_13 ) , V_2 -> V_12 + V_2 -> V_7 ) ;
F_11 ( V_2 -> V_27 , V_26 ) ;
return 0 ;
}
static void F_12 ( struct V_28 * V_25 )
{
struct V_29 * V_4 = F_13 ( V_25 ) ;
return F_14 ( & V_4 -> V_2 , V_4 -> V_30 ) ;
}
static int F_15 ( struct V_28 * V_25 )
{
struct V_29 * V_4 = F_13 ( V_25 ) ;
return F_16 ( & V_4 -> V_2 , V_4 -> V_30 ) ;
}
static int F_17 ( struct V_28 * V_25 )
{
struct V_29 * V_4 = F_13 ( V_25 ) ;
return F_18 ( & V_4 -> V_2 , V_4 -> V_30 ) ;
}
static T_3 F_19 ( struct V_28 * V_25 )
{
struct V_29 * V_4 = F_13 ( V_25 ) ;
return F_5 ( & V_4 -> V_2 , & V_4 -> V_31 ) ;
}
static int F_20 ( struct V_28 * V_25 , T_3 V_18 )
{
struct V_29 * V_4 = F_13 ( V_25 ) ;
return F_7 ( & V_4 -> V_2 , & V_4 -> V_31 , V_18 ) ;
}
static unsigned long F_21 ( struct V_28 * V_25 ,
unsigned long V_21 )
{
struct V_29 * V_4 = F_13 ( V_25 ) ;
return F_3 ( & V_4 -> V_2 , & V_4 -> V_31 , - 1 ,
V_21 ) ;
}
static int F_22 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_36 * V_31 = F_23 ( V_33 ) ;
int V_37 = 0 ;
if ( V_34 == V_38 ) {
V_31 -> V_39 = F_5 ( V_31 -> V_2 ,
V_31 -> V_4 ) ;
V_37 = F_7 ( V_31 -> V_2 , V_31 -> V_4 ,
V_31 -> V_40 ) ;
} else if ( V_34 == V_41 ) {
V_37 = F_7 ( V_31 -> V_2 , V_31 -> V_4 ,
V_31 -> V_39 ) ;
}
F_24 ( V_31 -> V_42 ) ;
return F_25 ( V_37 ) ;
}
int F_26 ( struct V_43 * V_43 , struct V_36 * V_44 )
{
V_44 -> V_45 . V_46 = F_22 ;
return F_27 ( V_43 , & V_44 -> V_45 ) ;
}
