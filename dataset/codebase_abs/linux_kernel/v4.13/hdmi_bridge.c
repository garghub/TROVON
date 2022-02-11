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
static void F_13 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 -> V_19 ;
const struct V_21 * V_22 = & V_19 -> V_23 -> V_24 ;
union V_25 V_26 ;
T_1 V_27 [ F_14 ( V_28 ) ] ;
T_2 V_29 ;
int V_30 ;
F_15 ( & V_26 . V_31 , V_22 ) ;
V_30 = F_16 ( & V_26 , V_27 , sizeof( V_27 ) ) ;
if ( V_30 < 0 ) {
F_5 ( & V_6 -> V_32 -> V_4 ,
L_6 ) ;
return;
}
F_17 ( V_6 , F_18 ( 0 ) ,
V_27 [ 3 ] |
V_27 [ 4 ] << 8 |
V_27 [ 5 ] << 16 |
V_27 [ 6 ] << 24 ) ;
F_17 ( V_6 , F_18 ( 1 ) ,
V_27 [ 7 ] |
V_27 [ 8 ] << 8 |
V_27 [ 9 ] << 16 |
V_27 [ 10 ] << 24 ) ;
F_17 ( V_6 , F_18 ( 2 ) ,
V_27 [ 11 ] |
V_27 [ 12 ] << 8 |
V_27 [ 13 ] << 16 |
V_27 [ 14 ] << 24 ) ;
F_17 ( V_6 , F_18 ( 3 ) ,
V_27 [ 15 ] |
V_27 [ 16 ] << 8 |
V_27 [ 1 ] << 24 ) ;
F_17 ( V_6 , V_33 ,
V_34 |
V_35 ) ;
V_29 = F_19 ( V_6 , V_36 ) ;
V_29 &= ~ V_37 ;
V_29 |= F_20 ( V_38 ) ;
F_17 ( V_6 , V_36 , V_29 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_39 * V_40 = V_6 -> V_40 ;
F_6 ( L_7 ) ;
if ( ! V_6 -> V_41 ) {
F_22 ( V_40 ) ;
F_2 ( V_2 ) ;
V_6 -> V_41 = true ;
if ( V_6 -> V_42 ) {
F_13 ( V_6 ) ;
F_23 ( V_6 ) ;
}
}
F_24 ( V_40 , V_6 -> V_15 ) ;
F_25 ( V_6 , true ) ;
if ( V_6 -> V_43 )
F_26 ( V_6 -> V_43 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_39 * V_40 = V_6 -> V_40 ;
if ( V_6 -> V_43 )
F_30 ( V_6 -> V_43 ) ;
F_6 ( L_8 ) ;
F_25 ( V_6 , false ) ;
F_31 ( V_40 ) ;
if ( V_6 -> V_41 ) {
F_9 ( V_2 ) ;
V_6 -> V_41 = false ;
if ( V_6 -> V_42 )
F_23 ( V_6 ) ;
F_32 ( V_40 ) ;
}
}
static void F_33 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_21 * V_24 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_44 , V_45 , V_46 , V_47 ;
T_3 V_48 ;
V_22 = V_24 ;
V_6 -> V_15 = V_22 -> clock * 1000 ;
V_44 = V_22 -> V_49 - V_22 -> V_50 ;
V_45 = V_22 -> V_49 - V_22 -> V_50 + V_22 -> V_51 ;
V_46 = V_22 -> V_52 - V_22 -> V_53 - 1 ;
V_47 = V_22 -> V_52 - V_22 -> V_53 + V_22 -> V_54 - 1 ;
F_6 ( L_9 ,
V_22 -> V_49 , V_22 -> V_52 , V_44 , V_45 , V_46 , V_47 ) ;
F_17 ( V_6 , V_55 ,
F_34 ( V_22 -> V_49 - 1 ) |
F_35 ( V_22 -> V_52 - 1 ) ) ;
F_17 ( V_6 , V_56 ,
F_36 ( V_44 ) |
F_37 ( V_45 ) ) ;
F_17 ( V_6 , V_57 ,
F_38 ( V_46 ) |
F_39 ( V_47 ) ) ;
if ( V_22 -> V_58 & V_59 ) {
F_17 ( V_6 , V_60 ,
F_40 ( V_22 -> V_52 ) ) ;
F_17 ( V_6 , V_61 ,
F_41 ( V_46 + 1 ) |
F_42 ( V_47 + 1 ) ) ;
} else {
F_17 ( V_6 , V_60 ,
F_40 ( 0 ) ) ;
F_17 ( V_6 , V_61 ,
F_41 ( 0 ) |
F_42 ( 0 ) ) ;
}
V_48 = 0 ;
if ( V_22 -> V_58 & V_62 )
V_48 |= V_63 ;
if ( V_22 -> V_58 & V_64 )
V_48 |= V_65 ;
if ( V_22 -> V_58 & V_59 )
V_48 |= V_66 ;
F_6 ( L_10 , V_48 ) ;
F_17 ( V_6 , V_67 , V_48 ) ;
if ( V_6 -> V_42 )
F_23 ( V_6 ) ;
}
struct V_1 * F_43 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_5 ;
int V_10 ;
V_5 = F_44 ( V_6 -> V_4 -> V_4 ,
sizeof( * V_5 ) , V_68 ) ;
if ( ! V_5 ) {
V_10 = - V_69 ;
goto V_70;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_71 ;
V_2 -> V_72 = & V_73 ;
V_10 = F_45 ( V_6 -> V_20 , V_2 , NULL ) ;
if ( V_10 )
goto V_70;
return V_2 ;
V_70:
if ( V_2 )
F_1 ( V_2 ) ;
return F_46 ( V_10 ) ;
}
