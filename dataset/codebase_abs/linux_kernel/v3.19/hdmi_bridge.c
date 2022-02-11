static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_11 ; V_9 ++ ) {
V_10 = F_6 ( V_6 -> V_12 [ V_9 ] ) ;
if ( V_10 ) {
F_7 ( V_5 -> V_5 , L_1 ,
V_8 -> V_13 [ V_9 ] , V_10 ) ;
}
}
if ( V_8 -> V_14 > 0 ) {
F_8 ( L_2 , V_6 -> V_15 ) ;
V_10 = F_9 ( V_6 -> V_16 [ 0 ] , V_6 -> V_15 ) ;
if ( V_10 ) {
F_7 ( V_5 -> V_5 , L_3 ,
V_8 -> V_17 [ 0 ] , V_10 ) ;
}
}
for ( V_9 = 0 ; V_9 < V_8 -> V_14 ; V_9 ++ ) {
V_10 = F_10 ( V_6 -> V_16 [ V_9 ] ) ;
if ( V_10 ) {
F_7 ( V_5 -> V_5 , L_4 ,
V_8 -> V_17 [ V_9 ] , V_10 ) ;
}
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 , V_10 ;
F_12 ( 16 + 4 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_14 ; V_9 ++ )
F_13 ( V_6 -> V_16 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_11 ; V_9 ++ ) {
V_10 = F_14 ( V_6 -> V_12 [ V_9 ] ) ;
if ( V_10 ) {
F_7 ( V_5 -> V_5 , L_5 ,
V_8 -> V_13 [ V_9 ] , V_10 ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
F_8 ( L_6 ) ;
if ( ! V_6 -> F_5 ) {
F_5 ( V_2 ) ;
V_6 -> F_5 = true ;
F_16 ( V_6 ) ;
}
V_19 -> V_20 -> V_21 ( V_19 , V_6 -> V_15 ) ;
F_17 ( V_6 , true ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
}
static void F_19 ( struct V_1 * V_2 )
{
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
F_8 ( L_7 ) ;
F_17 ( V_6 , false ) ;
V_19 -> V_20 -> V_22 ( V_19 ) ;
if ( V_6 -> F_5 ) {
F_11 ( V_2 ) ;
V_6 -> F_5 = false ;
F_16 ( V_6 ) ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
int V_26 , V_27 , V_28 , V_29 ;
T_1 V_30 ;
V_24 = V_25 ;
V_6 -> V_15 = V_24 -> clock * 1000 ;
V_6 -> V_31 = F_22 ( V_24 ) > 1 ;
V_26 = V_24 -> V_32 - V_24 -> V_33 ;
V_27 = V_24 -> V_32 - V_24 -> V_33 + V_24 -> V_34 ;
V_28 = V_24 -> V_35 - V_24 -> V_36 - 1 ;
V_29 = V_24 -> V_35 - V_24 -> V_36 + V_24 -> V_37 - 1 ;
F_8 ( L_8 ,
V_24 -> V_32 , V_24 -> V_35 , V_26 , V_27 , V_28 , V_29 ) ;
F_23 ( V_6 , V_38 ,
F_24 ( V_24 -> V_32 - 1 ) |
F_25 ( V_24 -> V_35 - 1 ) ) ;
F_23 ( V_6 , V_39 ,
F_26 ( V_26 ) |
F_27 ( V_27 ) ) ;
F_23 ( V_6 , V_40 ,
F_28 ( V_28 ) |
F_29 ( V_29 ) ) ;
if ( V_24 -> V_41 & V_42 ) {
F_23 ( V_6 , V_43 ,
F_30 ( V_24 -> V_35 ) ) ;
F_23 ( V_6 , V_44 ,
F_31 ( V_28 + 1 ) |
F_32 ( V_29 + 1 ) ) ;
} else {
F_23 ( V_6 , V_43 ,
F_30 ( 0 ) ) ;
F_23 ( V_6 , V_44 ,
F_31 ( 0 ) |
F_32 ( 0 ) ) ;
}
V_30 = 0 ;
if ( V_24 -> V_41 & V_45 )
V_30 |= V_46 ;
if ( V_24 -> V_41 & V_47 )
V_30 |= V_48 ;
if ( V_24 -> V_41 & V_42 )
V_30 |= V_49 ;
F_8 ( L_9 , V_30 ) ;
F_23 ( V_6 , V_50 , V_30 ) ;
F_16 ( V_6 ) ;
}
struct V_1 * F_33 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
int V_10 ;
V_3 = F_34 ( sizeof( * V_3 ) , V_51 ) ;
if ( ! V_3 ) {
V_10 = - V_52 ;
goto V_53;
}
V_3 -> V_6 = V_6 ;
V_2 = & V_3 -> V_54 ;
F_35 ( V_6 -> V_5 , V_2 , & V_55 ) ;
return V_2 ;
V_53:
if ( V_2 )
F_1 ( V_2 ) ;
return F_36 ( V_10 ) ;
}
