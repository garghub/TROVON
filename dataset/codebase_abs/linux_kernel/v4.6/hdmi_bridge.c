void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_11 ; V_9 ++ ) {
V_10 = F_4 ( V_6 -> V_12 [ V_9 ] ) ;
if ( V_10 ) {
F_5 ( V_4 -> V_4 , L_1 ,
V_8 -> V_13 [ V_9 ] , V_10 ) ;
}
}
if ( V_8 -> V_14 > 0 ) {
F_6 ( L_2 , V_6 -> V_15 ) ;
V_10 = F_7 ( V_6 -> V_16 [ 0 ] , V_6 -> V_15 ) ;
if ( V_10 ) {
F_5 ( V_4 -> V_4 , L_3 ,
V_8 -> V_17 [ 0 ] , V_10 ) ;
}
}
for ( V_9 = 0 ; V_9 < V_8 -> V_14 ; V_9 ++ ) {
V_10 = F_8 ( V_6 -> V_16 [ V_9 ] ) ;
if ( V_10 ) {
F_5 ( V_4 -> V_4 , L_4 ,
V_8 -> V_17 [ V_9 ] , V_10 ) ;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 , V_10 ;
F_10 ( 16 + 4 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_14 ; V_9 ++ )
F_11 ( V_6 -> V_16 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_11 ; V_9 ++ ) {
V_10 = F_12 ( V_6 -> V_12 [ V_9 ] ) ;
if ( V_10 ) {
F_5 ( V_4 -> V_4 , L_5 ,
V_8 -> V_13 [ V_9 ] , V_10 ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
F_6 ( L_6 ) ;
if ( ! V_6 -> V_20 ) {
F_14 ( V_19 ) ;
F_2 ( V_2 ) ;
V_6 -> V_20 = true ;
F_15 ( V_6 ) ;
}
F_16 ( V_19 , V_6 -> V_15 ) ;
F_17 ( V_6 , true ) ;
if ( V_6 -> V_21 )
F_18 ( V_6 -> V_21 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
}
static void F_20 ( struct V_1 * V_2 )
{
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
if ( V_6 -> V_21 )
F_22 ( V_6 -> V_21 ) ;
F_6 ( L_7 ) ;
F_17 ( V_6 , false ) ;
F_23 ( V_19 ) ;
if ( V_6 -> V_20 ) {
F_9 ( V_2 ) ;
V_6 -> V_20 = false ;
F_15 ( V_6 ) ;
F_24 ( V_19 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_24 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_25 , V_26 , V_27 , V_28 ;
T_1 V_29 ;
V_23 = V_24 ;
V_6 -> V_15 = V_23 -> clock * 1000 ;
V_25 = V_23 -> V_30 - V_23 -> V_31 ;
V_26 = V_23 -> V_30 - V_23 -> V_31 + V_23 -> V_32 ;
V_27 = V_23 -> V_33 - V_23 -> V_34 - 1 ;
V_28 = V_23 -> V_33 - V_23 -> V_34 + V_23 -> V_35 - 1 ;
F_6 ( L_8 ,
V_23 -> V_30 , V_23 -> V_33 , V_25 , V_26 , V_27 , V_28 ) ;
F_26 ( V_6 , V_36 ,
F_27 ( V_23 -> V_30 - 1 ) |
F_28 ( V_23 -> V_33 - 1 ) ) ;
F_26 ( V_6 , V_37 ,
F_29 ( V_25 ) |
F_30 ( V_26 ) ) ;
F_26 ( V_6 , V_38 ,
F_31 ( V_27 ) |
F_32 ( V_28 ) ) ;
if ( V_23 -> V_39 & V_40 ) {
F_26 ( V_6 , V_41 ,
F_33 ( V_23 -> V_33 ) ) ;
F_26 ( V_6 , V_42 ,
F_34 ( V_27 + 1 ) |
F_35 ( V_28 + 1 ) ) ;
} else {
F_26 ( V_6 , V_41 ,
F_33 ( 0 ) ) ;
F_26 ( V_6 , V_42 ,
F_34 ( 0 ) |
F_35 ( 0 ) ) ;
}
V_29 = 0 ;
if ( V_23 -> V_39 & V_43 )
V_29 |= V_44 ;
if ( V_23 -> V_39 & V_45 )
V_29 |= V_46 ;
if ( V_23 -> V_39 & V_40 )
V_29 |= V_47 ;
F_6 ( L_9 , V_29 ) ;
F_26 ( V_6 , V_48 , V_29 ) ;
F_15 ( V_6 ) ;
}
struct V_1 * F_36 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_5 ;
int V_10 ;
V_5 = F_37 ( V_6 -> V_4 -> V_4 ,
sizeof( * V_5 ) , V_49 ) ;
if ( ! V_5 ) {
V_10 = - V_50 ;
goto V_51;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_52 ;
V_2 -> V_53 = & V_54 ;
V_10 = F_38 ( V_6 -> V_4 , V_2 ) ;
if ( V_10 )
goto V_51;
return V_2 ;
V_51:
if ( V_2 )
F_1 ( V_2 ) ;
return F_39 ( V_10 ) ;
}
