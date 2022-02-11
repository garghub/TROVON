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
struct V_5 * V_23 ;
struct V_1 * V_2 ;
int V_24 ;
int V_25 = 0 ;
V_23 = F_13 ( & V_20 -> V_26 ,
sizeof( struct V_5 ) * V_22 -> V_27 ,
V_28 ) ;
if ( ! V_23 ) {
F_14 ( L_1 , V_29 ) ;
return - V_30 ;
}
for ( V_24 = 0 ; V_24 < V_22 -> V_27 ; V_24 ++ ) {
V_23 [ V_24 ] . V_10 = V_10 ;
V_23 [ V_24 ] . V_7 = & V_22 -> V_31 [ V_24 ] ;
V_2 = & V_23 [ V_24 ] . V_2 ;
V_2 -> V_32 = F_11 ;
V_2 -> V_33 = 3 ;
V_2 -> V_34 = V_20 -> V_26 . V_34 ;
V_2 -> V_35 = F_1 ;
V_2 -> free = F_6 ;
V_2 -> V_36 = F_7 ;
V_2 -> V_37 = F_8 ;
V_2 -> V_38 = F_9 ;
V_2 -> V_39 = F_10 ;
V_2 -> V_40 = 0 ;
V_2 -> V_10 = V_25 ;
V_2 -> V_41 = V_22 -> V_31 [ V_24 ] . V_41 ;
V_25 += V_22 -> V_31 [ V_24 ] . V_41 ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static int T_3 F_16 ( struct V_19 * V_20 )
{
void T_2 * V_42 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 =
F_17 ( V_47 , & V_20 -> V_26 ) ;
if ( ! V_46 ) {
F_18 ( & V_20 -> V_26 , L_2 ) ;
return - V_48 ;
}
V_44 = V_20 -> V_26 . V_34 ;
if ( ! V_44 ) {
F_18 ( & V_20 -> V_26 , L_3 ) ;
return - V_49 ;
}
V_42 = F_19 ( V_44 , 0 ) ;
if ( ! V_42 ) {
F_18 ( & V_20 -> V_26 , L_4 ) ;
F_20 ( V_44 ) ;
return - V_30 ;
}
F_12 ( V_20 , V_42 , V_46 -> V_22 ) ;
return 0 ;
}
