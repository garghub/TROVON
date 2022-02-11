static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_6 ;
return 0 ;
}
static void F_2 ( int V_5 )
{
F_3 ( V_7 -> V_8 [ 0 ] , V_5 & 1 ) ;
F_3 ( V_7 -> V_8 [ 1 ] , V_5 >> 1 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 . integer . V_5 [ 0 ] ;
V_6 = V_5 ;
if ( ! V_9 )
F_2 ( V_5 ) ;
return 0 ;
}
static void F_5 ( int V_10 )
{
F_6 ( L_1 , V_11 , V_10 ) ;
V_9 = V_10 ;
F_7 ( V_7 -> V_12 , V_10 ) ;
if ( V_10 && V_7 -> V_8 [ 0 ] > 0 )
F_2 ( V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_9 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_5 ( V_4 -> V_5 . integer . V_5 [ 0 ] ) ;
return 0 ;
}
void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_7 -> V_12 > 0 ) {
F_6 ( L_2 , V_11 ) ;
F_11 ( V_16 , V_17 ,
F_12 ( V_17 ) ) ;
}
if ( V_7 -> V_8 [ 0 ] > 0 ) {
F_6 ( L_3 , V_11 ) ;
F_11 ( V_16 , V_18 ,
F_12 ( V_18 ) ) ;
}
}
static int F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = V_20 -> V_23 ;
struct V_24 * V_25 = V_14 -> V_25 ;
struct V_24 * V_26 = V_14 -> V_26 ;
int V_27 ;
V_27 = F_14 ( V_26 , V_28 |
V_29 |
V_30 ) ;
if ( V_27 ) {
F_15 ( L_4 , V_11 ) ;
return V_27 ;
}
V_27 = F_14 ( V_25 , V_28 |
V_29 |
V_30 ) ;
if ( V_27 ) {
F_15 ( L_5 , V_11 ) ;
return V_27 ;
}
V_27 = F_16 ( V_25 , 0 ,
V_31 , V_32 ) ;
if ( V_27 ) {
F_15 ( L_6 , V_11 ) ;
return V_27 ;
}
if ( V_7 -> V_33 ) {
V_27 = F_16 ( V_26 , V_34 ,
0 , V_35 ) ;
if ( V_27 ) {
F_15 ( L_7 ,
V_11 ) ;
return V_27 ;
}
}
if ( V_7 -> V_36 ) {
int V_37 ;
V_37 = F_17 ( V_38 ) / V_31 ;
V_37 -- ;
V_27 = F_18 ( V_26 , V_39 ,
V_37 ) ;
}
return 0 ;
}
static int F_19 ( struct V_40 * V_41 )
{
if ( V_41 -> V_42 )
V_41 -> V_42 () ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 ,
struct V_40 * V_41 )
{
int V_27 ;
if ( V_7 -> V_8 [ 0 ] > 0 ) {
V_27 = F_21 ( V_41 -> V_8 [ 0 ] , L_8 ) ;
if ( V_27 ) {
F_22 ( V_44 , L_9 ) ;
return V_27 ;
}
V_27 = F_21 ( V_41 -> V_8 [ 1 ] , L_10 ) ;
if ( V_27 ) {
F_22 ( V_44 , L_11 ) ;
F_23 ( V_7 -> V_8 [ 0 ] ) ;
return V_27 ;
}
F_24 ( V_41 -> V_8 [ 0 ] , 0 ) ;
F_24 ( V_41 -> V_8 [ 1 ] , 0 ) ;
}
if ( V_7 -> V_12 > 0 ) {
V_27 = F_21 ( V_41 -> V_12 , L_12 ) ;
if ( V_27 ) {
F_22 ( V_44 , L_13 ,
V_41 -> V_12 , V_27 ) ;
goto V_45;
}
F_5 ( 0 ) ;
}
return 0 ;
V_45:
if ( V_41 -> V_8 [ 0 ] > 0 ) {
F_23 ( V_41 -> V_8 [ 0 ] ) ;
F_23 ( V_41 -> V_8 [ 1 ] ) ;
}
return V_27 ;
}
static void F_25 ( struct V_40 * V_41 )
{
if ( V_41 -> V_8 [ 0 ] > 0 ) {
F_23 ( V_41 -> V_8 [ 0 ] ) ;
F_23 ( V_41 -> V_8 [ 1 ] ) ;
}
if ( V_41 -> V_12 > 0 )
F_23 ( V_41 -> V_12 ) ;
}
static int F_26 ( struct V_43 * V_44 )
{
F_19 ( V_7 ) ;
return 0 ;
}
int T_1 F_27 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_46 * V_50 ;
int V_27 ;
V_49 -> V_51 -> V_52 = & V_53 ;
V_7 = V_47 -> V_44 . V_54 ;
if ( ! V_7 ) {
F_22 ( & V_47 -> V_44 , L_14 ) ;
return - V_55 ;
}
F_19 ( V_7 ) ;
V_38 = F_28 ( & V_47 -> V_44 , L_15 ) ;
if ( F_29 ( V_38 ) ) {
F_22 ( & V_47 -> V_44 , L_16 ) ;
return - V_55 ;
}
F_30 ( & V_47 -> V_44 , L_17 , F_17 ( V_38 ) ) ;
V_27 = F_20 ( & V_47 -> V_44 , V_7 ) ;
if ( V_27 )
goto V_56;
V_50 = F_31 ( L_18 , - 1 ) ;
if ( ! V_50 ) {
F_22 ( & V_47 -> V_44 , L_19 ) ;
V_27 = - V_57 ;
goto V_58;
}
F_32 ( V_50 , V_49 ) ;
V_27 = F_33 ( V_50 ) ;
if ( V_27 ) {
F_22 ( & V_47 -> V_44 , L_20 ) ;
goto V_59;
}
F_32 ( V_47 , V_50 ) ;
return 0 ;
V_59:
F_34 ( V_50 ) ;
V_58:
F_25 ( V_7 ) ;
V_56:
F_35 ( V_38 ) ;
return V_27 ;
}
int T_2 F_36 ( struct V_46 * V_47 )
{
struct V_46 * V_50 = F_37 ( V_47 ) ;
F_38 ( V_50 ) ;
F_25 ( V_7 ) ;
F_35 ( V_38 ) ;
return 0 ;
}
