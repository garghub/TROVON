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
if ( ! V_6 -> F_2 ) {
F_2 ( V_2 ) ;
V_6 -> F_2 = true ;
F_14 ( V_6 ) ;
}
V_19 -> V_20 -> V_21 ( V_19 , V_6 -> V_15 ) ;
F_15 ( V_6 , true ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static void F_17 ( struct V_1 * V_2 )
{
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
F_6 ( L_7 ) ;
F_15 ( V_6 , false ) ;
V_19 -> V_20 -> V_22 ( V_19 ) ;
if ( V_6 -> F_2 ) {
F_9 ( V_2 ) ;
V_6 -> F_2 = false ;
F_14 ( V_6 ) ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_26 , V_27 , V_28 , V_29 ;
T_1 V_30 ;
V_24 = V_25 ;
V_6 -> V_15 = V_24 -> clock * 1000 ;
V_6 -> V_31 = F_20 ( V_24 ) > 1 ;
V_26 = V_24 -> V_32 - V_24 -> V_33 ;
V_27 = V_24 -> V_32 - V_24 -> V_33 + V_24 -> V_34 ;
V_28 = V_24 -> V_35 - V_24 -> V_36 - 1 ;
V_29 = V_24 -> V_35 - V_24 -> V_36 + V_24 -> V_37 - 1 ;
F_6 ( L_8 ,
V_24 -> V_32 , V_24 -> V_35 , V_26 , V_27 , V_28 , V_29 ) ;
F_21 ( V_6 , V_38 ,
F_22 ( V_24 -> V_32 - 1 ) |
F_23 ( V_24 -> V_35 - 1 ) ) ;
F_21 ( V_6 , V_39 ,
F_24 ( V_26 ) |
F_25 ( V_27 ) ) ;
F_21 ( V_6 , V_40 ,
F_26 ( V_28 ) |
F_27 ( V_29 ) ) ;
if ( V_24 -> V_41 & V_42 ) {
F_21 ( V_6 , V_43 ,
F_28 ( V_24 -> V_35 ) ) ;
F_21 ( V_6 , V_44 ,
F_29 ( V_28 + 1 ) |
F_30 ( V_29 + 1 ) ) ;
} else {
F_21 ( V_6 , V_43 ,
F_28 ( 0 ) ) ;
F_21 ( V_6 , V_44 ,
F_29 ( 0 ) |
F_30 ( 0 ) ) ;
}
V_30 = 0 ;
if ( V_24 -> V_41 & V_45 )
V_30 |= V_46 ;
if ( V_24 -> V_41 & V_47 )
V_30 |= V_48 ;
if ( V_24 -> V_41 & V_42 )
V_30 |= V_49 ;
F_6 ( L_9 , V_30 ) ;
F_21 ( V_6 , V_50 , V_30 ) ;
F_14 ( V_6 ) ;
}
struct V_1 * F_31 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_5 ;
int V_10 ;
V_5 = F_32 ( V_6 -> V_4 -> V_4 ,
sizeof( * V_5 ) , V_51 ) ;
if ( ! V_5 ) {
V_10 = - V_52 ;
goto V_53;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_54 ;
V_2 -> V_20 = & V_55 ;
V_10 = F_33 ( V_6 -> V_4 , V_2 ) ;
if ( V_10 )
goto V_53;
return V_2 ;
V_53:
if ( V_2 )
F_1 ( V_2 ) ;
return F_34 ( V_10 ) ;
}
