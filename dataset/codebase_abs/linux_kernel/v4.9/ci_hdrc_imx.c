static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_9 args ;
struct V_1 * V_10 ;
int V_11 ;
if ( ! F_2 ( V_7 , L_1 , NULL ) )
return NULL ;
V_10 = F_3 ( V_3 , sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return F_4 ( - V_13 ) ;
V_11 = F_5 ( V_7 , L_1 , L_2 ,
0 , & args ) ;
if ( V_11 ) {
F_6 ( V_3 , L_3 ,
V_11 ) ;
return F_4 ( V_11 ) ;
}
V_10 -> V_14 = args . args [ 0 ] ;
V_5 = F_7 ( args . V_7 ) ;
F_8 ( args . V_7 ) ;
if ( ! V_5 || ! F_9 ( V_5 ) )
return F_4 ( - V_15 ) ;
V_10 -> V_3 = & V_5 -> V_3 ;
if ( F_10 ( V_7 , L_4 , NULL ) )
V_10 -> V_16 = 1 ;
if ( F_10 ( V_7 , L_5 , NULL ) )
V_10 -> V_17 = 1 ;
if ( F_10 ( V_7 , L_6 , NULL ) )
V_10 -> V_18 = 1 ;
return V_10 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
int V_11 = 0 ;
V_10 -> V_20 = F_13 ( V_3 , L_7 ) ;
if ( F_14 ( V_10 -> V_20 ) ) {
V_10 -> V_21 = F_13 ( V_3 , NULL ) ;
if ( F_14 ( V_10 -> V_21 ) ) {
V_11 = F_15 ( V_10 -> V_21 ) ;
F_6 ( V_3 ,
L_8 ,
F_15 ( V_10 -> V_21 ) , F_15 ( V_10 -> V_20 ) ) ;
return V_11 ;
}
return V_11 ;
}
V_10 -> V_22 = F_13 ( V_3 , L_9 ) ;
if ( F_14 ( V_10 -> V_22 ) ) {
V_11 = F_15 ( V_10 -> V_22 ) ;
F_6 ( V_3 ,
L_10 , V_11 ) ;
return V_11 ;
}
V_10 -> V_23 = F_13 ( V_3 , L_11 ) ;
if ( F_14 ( V_10 -> V_23 ) ) {
V_11 = F_15 ( V_10 -> V_23 ) ;
F_6 ( V_3 ,
L_12 , V_11 ) ;
return V_11 ;
}
V_10 -> V_24 = true ;
return V_11 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
int V_11 = 0 ;
if ( V_10 -> V_24 ) {
V_11 = F_17 ( V_10 -> V_20 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_13 ,
V_11 ) ;
return V_11 ;
}
V_11 = F_17 ( V_10 -> V_22 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_14 ,
V_11 ) ;
F_18 ( V_10 -> V_20 ) ;
return V_11 ;
}
V_11 = F_17 ( V_10 -> V_23 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_15 ,
V_11 ) ;
F_18 ( V_10 -> V_22 ) ;
F_18 ( V_10 -> V_20 ) ;
return V_11 ;
}
} else {
V_11 = F_17 ( V_10 -> V_21 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_16 ,
V_11 ) ;
return V_11 ;
}
}
return V_11 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
if ( V_10 -> V_24 ) {
F_18 ( V_10 -> V_23 ) ;
F_18 ( V_10 -> V_22 ) ;
F_18 ( V_10 -> V_20 ) ;
} else {
F_18 ( V_10 -> V_21 ) ;
}
}
static int F_20 ( struct V_4 * V_25 )
{
struct V_19 * V_10 ;
struct V_26 V_27 = {
. V_28 = F_21 ( & V_25 -> V_3 ) ,
. V_29 = V_30 ,
} ;
int V_11 ;
const struct V_31 * V_32 ;
const struct V_33 * V_34 ;
V_32 = F_22 ( V_35 , & V_25 -> V_3 ) ;
if ( ! V_32 )
return - V_36 ;
V_34 = V_32 -> V_10 ;
V_10 = F_3 ( & V_25 -> V_3 , sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
F_23 ( V_25 , V_10 ) ;
V_10 -> V_37 = F_1 ( & V_25 -> V_3 ) ;
if ( F_14 ( V_10 -> V_37 ) )
return F_15 ( V_10 -> V_37 ) ;
V_11 = F_11 ( & V_25 -> V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_16 ( & V_25 -> V_3 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_38 = F_24 ( & V_25 -> V_3 , L_17 , 0 ) ;
if ( F_14 ( V_10 -> V_38 ) ) {
V_11 = F_15 ( V_10 -> V_38 ) ;
if ( V_11 == - V_36 )
V_11 = - V_39 ;
goto V_40;
}
V_27 . V_41 = V_10 -> V_38 ;
V_27 . V_42 |= V_34 -> V_42 ;
if ( V_27 . V_42 & V_43 )
V_10 -> V_44 = true ;
V_11 = F_25 ( V_10 -> V_37 ) ;
if ( V_11 ) {
F_6 ( & V_25 -> V_3 , L_18 , V_11 ) ;
goto V_40;
}
V_10 -> V_45 = F_26 ( & V_25 -> V_3 ,
V_25 -> V_46 , V_25 -> V_47 ,
& V_27 ) ;
if ( F_14 ( V_10 -> V_45 ) ) {
V_11 = F_15 ( V_10 -> V_45 ) ;
if ( V_11 != - V_15 )
F_6 ( & V_25 -> V_3 ,
L_19 , V_11 ) ;
goto V_40;
}
V_11 = F_27 ( V_10 -> V_37 ) ;
if ( V_11 ) {
F_6 ( & V_25 -> V_3 , L_20 , V_11 ) ;
goto V_48;
}
if ( V_10 -> V_44 ) {
F_28 ( & V_25 -> V_3 ) ;
F_29 ( & V_25 -> V_3 ) ;
}
F_30 ( & V_25 -> V_3 , true ) ;
return 0 ;
V_48:
F_31 ( V_10 -> V_45 ) ;
V_40:
F_19 ( & V_25 -> V_3 ) ;
return V_11 ;
}
static int F_32 ( struct V_4 * V_25 )
{
struct V_19 * V_10 = F_9 ( V_25 ) ;
if ( V_10 -> V_44 ) {
F_33 ( & V_25 -> V_3 ) ;
F_34 ( & V_25 -> V_3 ) ;
F_35 ( & V_25 -> V_3 ) ;
}
F_31 ( V_10 -> V_45 ) ;
F_19 ( & V_25 -> V_3 ) ;
return 0 ;
}
static void F_36 ( struct V_4 * V_25 )
{
F_32 ( V_25 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
F_38 ( V_3 , L_21 , V_49 ) ;
F_19 ( V_3 ) ;
V_10 -> V_50 = true ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
int V_11 = 0 ;
F_38 ( V_3 , L_21 , V_49 ) ;
if ( ! V_10 -> V_50 ) {
F_40 ( 1 ) ;
return 0 ;
}
V_11 = F_16 ( V_3 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_50 = false ;
V_11 = F_41 ( V_10 -> V_37 , false ) ;
if ( V_11 ) {
F_6 ( V_3 , L_22 , V_11 ) ;
goto V_51;
}
return 0 ;
V_51:
F_19 ( V_3 ) ;
return V_11 ;
}
static int F_42 ( struct V_2 * V_3 )
{
int V_11 ;
struct V_19 * V_10 = F_12 ( V_3 ) ;
if ( V_10 -> V_50 )
return 0 ;
if ( F_43 ( V_3 ) ) {
V_11 = F_41 ( V_10 -> V_37 , true ) ;
if ( V_11 ) {
F_6 ( V_3 , L_22 ,
V_11 ) ;
return V_11 ;
}
}
return F_37 ( V_3 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
int V_11 ;
V_11 = F_39 ( V_3 ) ;
if ( ! V_11 && V_10 -> V_44 ) {
F_34 ( V_3 ) ;
F_28 ( V_3 ) ;
F_29 ( V_3 ) ;
}
return V_11 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_12 ( V_3 ) ;
int V_11 ;
if ( V_10 -> V_50 ) {
F_40 ( 1 ) ;
return 0 ;
}
V_11 = F_41 ( V_10 -> V_37 , true ) ;
if ( V_11 ) {
F_6 ( V_3 , L_22 , V_11 ) ;
return V_11 ;
}
return F_37 ( V_3 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
return F_39 ( V_3 ) ;
}
