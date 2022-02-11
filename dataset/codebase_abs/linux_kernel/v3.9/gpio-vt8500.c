static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 == V_9 )
return 0 ;
V_4 = F_3 ( V_6 -> V_10 + V_6 -> V_7 -> V_8 ) ;
V_4 |= F_4 ( V_3 ) ;
F_5 ( V_4 , V_6 -> V_10 + V_6 -> V_7 -> V_8 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 ;
if ( V_6 -> V_7 -> V_8 == V_9 )
return;
V_4 = F_3 ( V_6 -> V_10 + V_6 -> V_7 -> V_8 ) ;
V_4 &= ~ F_4 ( V_3 ) ;
F_5 ( V_4 , V_6 -> V_10 + V_6 -> V_7 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 = F_3 ( V_6 -> V_10 + V_6 -> V_7 -> V_11 ) ;
V_4 &= ~ F_4 ( V_3 ) ;
F_5 ( V_4 , V_6 -> V_10 + V_6 -> V_7 -> V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 = F_3 ( V_6 -> V_10 + V_6 -> V_7 -> V_11 ) ;
V_4 |= F_4 ( V_3 ) ;
F_5 ( V_4 , V_6 -> V_10 + V_6 -> V_7 -> V_11 ) ;
if ( V_12 ) {
V_4 = F_3 ( V_6 -> V_10 +
V_6 -> V_7 -> V_13 ) ;
V_4 |= F_4 ( V_3 ) ;
F_5 ( V_4 , V_6 -> V_10 +
V_6 -> V_7 -> V_13 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( F_3 ( V_6 -> V_10 + V_6 -> V_7 -> V_14 ) >>
V_3 ) & 1 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 ,
int V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 = F_3 ( V_6 -> V_10 +
V_6 -> V_7 -> V_13 ) ;
if ( V_12 )
V_4 |= F_4 ( V_3 ) ;
else
V_4 &= ~ F_4 ( V_3 ) ;
F_5 ( V_4 , V_6 -> V_10 + V_6 -> V_7 -> V_13 ) ;
}
static int F_11 ( struct V_1 * V_15 ,
const struct V_16 * V_17 , T_1 * V_18 )
{
if ( V_18 )
* V_18 = V_17 -> args [ 2 ] ;
return V_17 -> args [ 1 ] ;
}
static int F_12 ( struct V_19 * V_20 , void T_2 * V_10 ,
const struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_5 * V_25 ;
struct V_1 * V_2 ;
int V_26 ;
int V_27 = 0 ;
V_24 = F_13 ( & V_20 -> V_28 , sizeof( struct V_23 ) , V_29 ) ;
if ( ! V_24 ) {
F_14 ( & V_20 -> V_28 , L_1 ) ;
return - V_30 ;
}
V_24 -> V_2 = F_13 ( & V_20 -> V_28 ,
sizeof( struct V_5 ) * V_22 -> V_31 ,
V_29 ) ;
if ( ! V_24 -> V_2 ) {
F_14 ( & V_20 -> V_28 , L_2 ) ;
return - V_30 ;
}
V_24 -> V_32 = V_10 ;
V_24 -> V_31 = V_22 -> V_31 ;
F_15 ( V_20 , V_24 ) ;
V_25 = V_24 -> V_2 ;
for ( V_26 = 0 ; V_26 < V_22 -> V_31 ; V_26 ++ ) {
V_25 [ V_26 ] . V_10 = V_10 ;
V_25 [ V_26 ] . V_7 = & V_22 -> V_33 [ V_26 ] ;
V_2 = & V_25 [ V_26 ] . V_2 ;
V_2 -> V_34 = F_11 ;
V_2 -> V_35 = 3 ;
V_2 -> V_36 = V_20 -> V_28 . V_36 ;
V_2 -> V_37 = F_1 ;
V_2 -> free = F_6 ;
V_2 -> V_38 = F_7 ;
V_2 -> V_39 = F_8 ;
V_2 -> V_40 = F_9 ;
V_2 -> V_41 = F_10 ;
V_2 -> V_42 = 0 ;
V_2 -> V_10 = V_27 ;
V_2 -> V_43 = V_22 -> V_33 [ V_26 ] . V_43 ;
V_27 += V_22 -> V_33 [ V_26 ] . V_43 ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
int V_44 ;
void T_2 * V_45 ;
struct V_46 * V_47 ;
const struct V_48 * V_49 =
F_18 ( V_50 , & V_20 -> V_28 ) ;
if ( ! V_49 ) {
F_14 ( & V_20 -> V_28 , L_3 ) ;
return - V_51 ;
}
V_47 = F_19 ( V_20 , V_52 , 0 ) ;
if ( ! V_47 ) {
F_14 ( & V_20 -> V_28 , L_4 ) ;
return - V_51 ;
}
V_45 = F_20 ( & V_20 -> V_28 , V_47 ) ;
if ( ! V_45 ) {
F_14 ( & V_20 -> V_28 , L_5 ) ;
return - V_30 ;
}
V_44 = F_12 ( V_20 , V_45 , V_49 -> V_22 ) ;
return V_44 ;
}
static int F_21 ( struct V_19 * V_20 )
{
int V_26 ;
int V_44 ;
struct V_23 * V_24 = F_22 ( V_20 ) ;
struct V_5 * V_25 = V_24 -> V_2 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_31 ; V_26 ++ ) {
V_44 = F_23 ( & V_25 [ V_26 ] . V_2 ) ;
if ( V_44 )
F_24 ( & V_20 -> V_28 , L_6 ,
V_44 ) ;
}
return 0 ;
}
