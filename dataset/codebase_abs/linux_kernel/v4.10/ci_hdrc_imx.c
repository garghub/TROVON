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
if ( F_11 ( V_7 ) == V_19 )
V_10 -> V_20 = 1 ;
return V_10 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
int V_11 = 0 ;
V_10 -> V_22 = F_14 ( V_3 , L_7 ) ;
if ( F_15 ( V_10 -> V_22 ) ) {
V_10 -> V_23 = F_14 ( V_3 , NULL ) ;
if ( F_15 ( V_10 -> V_23 ) ) {
V_11 = F_16 ( V_10 -> V_23 ) ;
F_6 ( V_3 ,
L_8 ,
F_16 ( V_10 -> V_23 ) , F_16 ( V_10 -> V_22 ) ) ;
return V_11 ;
}
return V_11 ;
}
V_10 -> V_24 = F_14 ( V_3 , L_9 ) ;
if ( F_15 ( V_10 -> V_24 ) ) {
V_11 = F_16 ( V_10 -> V_24 ) ;
F_6 ( V_3 ,
L_10 , V_11 ) ;
return V_11 ;
}
V_10 -> V_25 = F_14 ( V_3 , L_11 ) ;
if ( F_15 ( V_10 -> V_25 ) ) {
V_11 = F_16 ( V_10 -> V_25 ) ;
F_6 ( V_3 ,
L_12 , V_11 ) ;
return V_11 ;
}
V_10 -> V_26 = true ;
return V_11 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
int V_11 = 0 ;
if ( V_10 -> V_26 ) {
V_11 = F_18 ( V_10 -> V_22 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_13 ,
V_11 ) ;
return V_11 ;
}
V_11 = F_18 ( V_10 -> V_24 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_14 ,
V_11 ) ;
F_19 ( V_10 -> V_22 ) ;
return V_11 ;
}
V_11 = F_18 ( V_10 -> V_25 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_15 ,
V_11 ) ;
F_19 ( V_10 -> V_24 ) ;
F_19 ( V_10 -> V_22 ) ;
return V_11 ;
}
} else {
V_11 = F_18 ( V_10 -> V_23 ) ;
if ( V_11 ) {
F_6 ( V_3 ,
L_16 ,
V_11 ) ;
return V_11 ;
}
}
return V_11 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
if ( V_10 -> V_26 ) {
F_19 ( V_10 -> V_25 ) ;
F_19 ( V_10 -> V_24 ) ;
F_19 ( V_10 -> V_22 ) ;
} else {
F_19 ( V_10 -> V_23 ) ;
}
}
static int F_21 ( struct V_4 * V_27 )
{
struct V_21 * V_10 ;
struct V_28 V_29 = {
. V_30 = F_22 ( & V_27 -> V_3 ) ,
. V_31 = V_32 ,
} ;
int V_11 ;
const struct V_33 * V_34 ;
const struct V_35 * V_36 ;
V_34 = F_23 ( V_37 , & V_27 -> V_3 ) ;
if ( ! V_34 )
return - V_38 ;
V_36 = V_34 -> V_10 ;
V_10 = F_3 ( & V_27 -> V_3 , sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
F_24 ( V_27 , V_10 ) ;
V_10 -> V_39 = F_1 ( & V_27 -> V_3 ) ;
if ( F_15 ( V_10 -> V_39 ) )
return F_16 ( V_10 -> V_39 ) ;
V_11 = F_12 ( & V_27 -> V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_17 ( & V_27 -> V_3 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_40 = F_25 ( & V_27 -> V_3 , L_17 , 0 ) ;
if ( F_15 ( V_10 -> V_40 ) ) {
V_11 = F_16 ( V_10 -> V_40 ) ;
if ( V_11 == - V_38 )
V_11 = - V_41 ;
goto V_42;
}
V_29 . V_43 = V_10 -> V_40 ;
V_29 . V_44 |= V_36 -> V_44 ;
if ( V_29 . V_44 & V_45 )
V_10 -> V_46 = true ;
V_11 = F_26 ( V_10 -> V_39 ) ;
if ( V_11 ) {
F_6 ( & V_27 -> V_3 , L_18 , V_11 ) ;
goto V_42;
}
V_10 -> V_47 = F_27 ( & V_27 -> V_3 ,
V_27 -> V_48 , V_27 -> V_49 ,
& V_29 ) ;
if ( F_15 ( V_10 -> V_47 ) ) {
V_11 = F_16 ( V_10 -> V_47 ) ;
if ( V_11 != - V_15 )
F_6 ( & V_27 -> V_3 ,
L_19 , V_11 ) ;
goto V_42;
}
V_11 = F_28 ( V_10 -> V_39 ) ;
if ( V_11 ) {
F_6 ( & V_27 -> V_3 , L_20 , V_11 ) ;
goto V_50;
}
if ( V_10 -> V_46 ) {
F_29 ( & V_27 -> V_3 ) ;
F_30 ( & V_27 -> V_3 ) ;
}
F_31 ( & V_27 -> V_3 , true ) ;
return 0 ;
V_50:
F_32 ( V_10 -> V_47 ) ;
V_42:
F_20 ( & V_27 -> V_3 ) ;
return V_11 ;
}
static int F_33 ( struct V_4 * V_27 )
{
struct V_21 * V_10 = F_9 ( V_27 ) ;
if ( V_10 -> V_46 ) {
F_34 ( & V_27 -> V_3 ) ;
F_35 ( & V_27 -> V_3 ) ;
F_36 ( & V_27 -> V_3 ) ;
}
F_32 ( V_10 -> V_47 ) ;
F_20 ( & V_27 -> V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_4 * V_27 )
{
F_33 ( V_27 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
F_39 ( V_3 , L_21 , V_51 ) ;
F_20 ( V_3 ) ;
V_10 -> V_52 = true ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
int V_11 = 0 ;
F_39 ( V_3 , L_21 , V_51 ) ;
if ( ! V_10 -> V_52 ) {
F_41 ( 1 ) ;
return 0 ;
}
V_11 = F_17 ( V_3 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_52 = false ;
V_11 = F_42 ( V_10 -> V_39 , false ) ;
if ( V_11 ) {
F_6 ( V_3 , L_22 , V_11 ) ;
goto V_53;
}
return 0 ;
V_53:
F_20 ( V_3 ) ;
return V_11 ;
}
static int F_43 ( struct V_2 * V_3 )
{
int V_11 ;
struct V_21 * V_10 = F_13 ( V_3 ) ;
if ( V_10 -> V_52 )
return 0 ;
if ( F_44 ( V_3 ) ) {
V_11 = F_42 ( V_10 -> V_39 , true ) ;
if ( V_11 ) {
F_6 ( V_3 , L_22 ,
V_11 ) ;
return V_11 ;
}
}
return F_38 ( V_3 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
int V_11 ;
V_11 = F_40 ( V_3 ) ;
if ( ! V_11 && V_10 -> V_46 ) {
F_35 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( V_3 ) ;
}
return V_11 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_21 * V_10 = F_13 ( V_3 ) ;
int V_11 ;
if ( V_10 -> V_52 ) {
F_41 ( 1 ) ;
return 0 ;
}
V_11 = F_42 ( V_10 -> V_39 , true ) ;
if ( V_11 ) {
F_6 ( V_3 , L_22 , V_11 ) ;
return V_11 ;
}
return F_38 ( V_3 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
return F_40 ( V_3 ) ;
}
