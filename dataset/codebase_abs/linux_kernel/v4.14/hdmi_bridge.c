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
F_4 ( & V_6 -> V_11 -> V_4 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_12 ; V_9 ++ ) {
V_10 = F_5 ( V_6 -> V_13 [ V_9 ] ) ;
if ( V_10 ) {
F_6 ( V_4 -> V_4 , L_1 ,
V_8 -> V_14 [ V_9 ] , V_10 ) ;
}
}
if ( V_8 -> V_15 > 0 ) {
F_7 ( L_2 , V_6 -> V_16 ) ;
V_10 = F_8 ( V_6 -> V_17 [ 0 ] , V_6 -> V_16 ) ;
if ( V_10 ) {
F_6 ( V_4 -> V_4 , L_3 ,
V_8 -> V_18 [ 0 ] , V_10 ) ;
}
}
for ( V_9 = 0 ; V_9 < V_8 -> V_15 ; V_9 ++ ) {
V_10 = F_9 ( V_6 -> V_17 [ V_9 ] ) ;
if ( V_10 ) {
F_6 ( V_4 -> V_4 , L_4 ,
V_8 -> V_18 [ V_9 ] , V_10 ) ;
}
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 , V_10 ;
F_11 ( 16 + 4 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_15 ; V_9 ++ )
F_12 ( V_6 -> V_17 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_12 ; V_9 ++ ) {
V_10 = F_13 ( V_6 -> V_13 [ V_9 ] ) ;
if ( V_10 ) {
F_6 ( V_4 -> V_4 , L_5 ,
V_8 -> V_14 [ V_9 ] , V_10 ) ;
}
}
F_14 ( & V_6 -> V_11 -> V_4 ) ;
}
static void F_15 ( struct V_6 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_21 -> V_20 ;
const struct V_22 * V_23 = & V_20 -> V_24 -> V_25 ;
union V_26 V_27 ;
T_1 V_28 [ F_16 ( V_29 ) ] ;
T_2 V_30 ;
int V_31 ;
F_17 ( & V_27 . V_32 , V_23 , false ) ;
V_31 = F_18 ( & V_27 , V_28 , sizeof( V_28 ) ) ;
if ( V_31 < 0 ) {
F_6 ( & V_6 -> V_11 -> V_4 ,
L_6 ) ;
return;
}
F_19 ( V_6 , F_20 ( 0 ) ,
V_28 [ 3 ] |
V_28 [ 4 ] << 8 |
V_28 [ 5 ] << 16 |
V_28 [ 6 ] << 24 ) ;
F_19 ( V_6 , F_20 ( 1 ) ,
V_28 [ 7 ] |
V_28 [ 8 ] << 8 |
V_28 [ 9 ] << 16 |
V_28 [ 10 ] << 24 ) ;
F_19 ( V_6 , F_20 ( 2 ) ,
V_28 [ 11 ] |
V_28 [ 12 ] << 8 |
V_28 [ 13 ] << 16 |
V_28 [ 14 ] << 24 ) ;
F_19 ( V_6 , F_20 ( 3 ) ,
V_28 [ 15 ] |
V_28 [ 16 ] << 8 |
V_28 [ 1 ] << 24 ) ;
F_19 ( V_6 , V_33 ,
V_34 |
V_35 ) ;
V_30 = F_21 ( V_6 , V_36 ) ;
V_30 &= ~ V_37 ;
V_30 |= F_22 ( V_38 ) ;
F_19 ( V_6 , V_36 , V_30 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_39 * V_40 = V_6 -> V_40 ;
F_7 ( L_7 ) ;
if ( ! V_6 -> V_41 ) {
F_24 ( V_40 ) ;
F_2 ( V_2 ) ;
V_6 -> V_41 = true ;
if ( V_6 -> V_42 ) {
F_15 ( V_6 ) ;
F_25 ( V_6 ) ;
}
}
F_26 ( V_40 , V_6 -> V_16 ) ;
F_27 ( V_6 , true ) ;
if ( V_6 -> V_43 )
F_28 ( V_6 -> V_43 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_39 * V_40 = V_6 -> V_40 ;
if ( V_6 -> V_43 )
F_32 ( V_6 -> V_43 ) ;
F_7 ( L_8 ) ;
F_27 ( V_6 , false ) ;
F_33 ( V_40 ) ;
if ( V_6 -> V_41 ) {
F_10 ( V_2 ) ;
V_6 -> V_41 = false ;
if ( V_6 -> V_42 )
F_25 ( V_6 ) ;
F_34 ( V_40 ) ;
}
}
static void F_35 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_25 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_44 , V_45 , V_46 , V_47 ;
T_3 V_48 ;
V_23 = V_25 ;
V_6 -> V_16 = V_23 -> clock * 1000 ;
V_44 = V_23 -> V_49 - V_23 -> V_50 ;
V_45 = V_23 -> V_49 - V_23 -> V_50 + V_23 -> V_51 ;
V_46 = V_23 -> V_52 - V_23 -> V_53 - 1 ;
V_47 = V_23 -> V_52 - V_23 -> V_53 + V_23 -> V_54 - 1 ;
F_7 ( L_9 ,
V_23 -> V_49 , V_23 -> V_52 , V_44 , V_45 , V_46 , V_47 ) ;
F_19 ( V_6 , V_55 ,
F_36 ( V_23 -> V_49 - 1 ) |
F_37 ( V_23 -> V_52 - 1 ) ) ;
F_19 ( V_6 , V_56 ,
F_38 ( V_44 ) |
F_39 ( V_45 ) ) ;
F_19 ( V_6 , V_57 ,
F_40 ( V_46 ) |
F_41 ( V_47 ) ) ;
if ( V_23 -> V_58 & V_59 ) {
F_19 ( V_6 , V_60 ,
F_42 ( V_23 -> V_52 ) ) ;
F_19 ( V_6 , V_61 ,
F_43 ( V_46 + 1 ) |
F_44 ( V_47 + 1 ) ) ;
} else {
F_19 ( V_6 , V_60 ,
F_42 ( 0 ) ) ;
F_19 ( V_6 , V_61 ,
F_43 ( 0 ) |
F_44 ( 0 ) ) ;
}
V_48 = 0 ;
if ( V_23 -> V_58 & V_62 )
V_48 |= V_63 ;
if ( V_23 -> V_58 & V_64 )
V_48 |= V_65 ;
if ( V_23 -> V_58 & V_59 )
V_48 |= V_66 ;
F_7 ( L_10 , V_48 ) ;
F_19 ( V_6 , V_67 , V_48 ) ;
if ( V_6 -> V_42 )
F_25 ( V_6 ) ;
}
struct V_1 * F_45 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_5 ;
int V_10 ;
V_5 = F_46 ( V_6 -> V_4 -> V_4 ,
sizeof( * V_5 ) , V_68 ) ;
if ( ! V_5 ) {
V_10 = - V_69 ;
goto V_70;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_71 ;
V_2 -> V_72 = & V_73 ;
V_10 = F_47 ( V_6 -> V_21 , V_2 , NULL ) ;
if ( V_10 )
goto V_70;
return V_2 ;
V_70:
if ( V_2 )
F_1 ( V_2 ) ;
return F_48 ( V_10 ) ;
}
