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
if ( ! V_5 )
return F_4 ( - V_15 ) ;
V_10 -> V_3 = & V_5 -> V_3 ;
if ( F_9 ( V_7 , L_4 , NULL ) )
V_10 -> V_16 = 1 ;
if ( F_9 ( V_7 , L_5 , NULL ) )
V_10 -> V_17 = 1 ;
return V_10 ;
}
static int F_10 ( struct V_4 * V_18 )
{
struct V_19 * V_10 ;
struct V_20 V_21 = {
. V_22 = F_11 ( & V_18 -> V_3 ) ,
. V_23 = V_24 ,
. V_25 = V_26 ,
} ;
int V_11 ;
const struct V_27 * V_28 =
F_12 ( V_29 , & V_18 -> V_3 ) ;
const struct V_30 * V_31 = V_28 -> V_10 ;
V_10 = F_3 ( & V_18 -> V_3 , sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_10 -> V_32 = F_1 ( & V_18 -> V_3 ) ;
if ( F_13 ( V_10 -> V_32 ) )
return F_14 ( V_10 -> V_32 ) ;
V_10 -> V_33 = F_15 ( & V_18 -> V_3 , NULL ) ;
if ( F_13 ( V_10 -> V_33 ) ) {
F_6 ( & V_18 -> V_3 ,
L_6 , F_14 ( V_10 -> V_33 ) ) ;
return F_14 ( V_10 -> V_33 ) ;
}
V_11 = F_16 ( V_10 -> V_33 ) ;
if ( V_11 ) {
F_6 ( & V_18 -> V_3 ,
L_7 , V_11 ) ;
return V_11 ;
}
V_10 -> V_34 = F_17 ( & V_18 -> V_3 , L_8 , 0 ) ;
if ( F_13 ( V_10 -> V_34 ) ) {
V_11 = F_14 ( V_10 -> V_34 ) ;
if ( V_11 == - V_35 )
V_11 = - V_36 ;
goto V_37;
}
V_21 . V_38 = V_10 -> V_34 ;
V_21 . V_25 |= V_31 -> V_25 ;
if ( V_21 . V_25 & V_39 )
V_10 -> V_40 = true ;
V_11 = F_18 ( & V_18 -> V_3 , F_19 ( 32 ) ) ;
if ( V_11 )
goto V_37;
V_11 = F_20 ( V_10 -> V_32 ) ;
if ( V_11 ) {
F_6 ( & V_18 -> V_3 , L_9 , V_11 ) ;
goto V_37;
}
V_10 -> V_41 = F_21 ( & V_18 -> V_3 ,
V_18 -> V_42 , V_18 -> V_43 ,
& V_21 ) ;
if ( F_13 ( V_10 -> V_41 ) ) {
V_11 = F_14 ( V_10 -> V_41 ) ;
F_6 ( & V_18 -> V_3 ,
L_10 ,
V_11 ) ;
goto V_37;
}
V_11 = F_22 ( V_10 -> V_32 ) ;
if ( V_11 ) {
F_6 ( & V_18 -> V_3 , L_11 , V_11 ) ;
goto V_44;
}
F_23 ( V_18 , V_10 ) ;
if ( V_10 -> V_40 ) {
F_24 ( & V_18 -> V_3 ) ;
F_25 ( & V_18 -> V_3 ) ;
}
F_26 ( & V_18 -> V_3 , true ) ;
return 0 ;
V_44:
F_27 ( V_10 -> V_41 ) ;
V_37:
F_28 ( V_10 -> V_33 ) ;
return V_11 ;
}
static int F_29 ( struct V_4 * V_18 )
{
struct V_19 * V_10 = F_30 ( V_18 ) ;
if ( V_10 -> V_40 ) {
F_31 ( & V_18 -> V_3 ) ;
F_32 ( & V_18 -> V_3 ) ;
F_33 ( & V_18 -> V_3 ) ;
}
F_27 ( V_10 -> V_41 ) ;
F_28 ( V_10 -> V_33 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_35 ( V_3 ) ;
F_36 ( V_3 , L_12 , V_45 ) ;
F_28 ( V_10 -> V_33 ) ;
V_10 -> V_46 = true ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_35 ( V_3 ) ;
int V_11 = 0 ;
F_36 ( V_3 , L_12 , V_45 ) ;
if ( ! V_10 -> V_46 ) {
F_38 ( 1 ) ;
return 0 ;
}
V_11 = F_16 ( V_10 -> V_33 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_46 = false ;
V_11 = F_39 ( V_10 -> V_32 , false ) ;
if ( V_11 ) {
F_6 ( V_3 , L_13 , V_11 ) ;
goto V_47;
}
return 0 ;
V_47:
F_28 ( V_10 -> V_33 ) ;
return V_11 ;
}
static int F_40 ( struct V_2 * V_3 )
{
int V_11 ;
struct V_19 * V_10 = F_35 ( V_3 ) ;
if ( V_10 -> V_46 )
return 0 ;
if ( F_41 ( V_3 ) ) {
V_11 = F_39 ( V_10 -> V_32 , true ) ;
if ( V_11 ) {
F_6 ( V_3 , L_13 ,
V_11 ) ;
return V_11 ;
}
}
return F_34 ( V_3 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_35 ( V_3 ) ;
int V_11 ;
V_11 = F_37 ( V_3 ) ;
if ( ! V_11 && V_10 -> V_40 ) {
F_32 ( V_3 ) ;
F_24 ( V_3 ) ;
F_25 ( V_3 ) ;
}
return V_11 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_19 * V_10 = F_35 ( V_3 ) ;
int V_11 ;
if ( V_10 -> V_46 ) {
F_38 ( 1 ) ;
return 0 ;
}
V_11 = F_39 ( V_10 -> V_32 , true ) ;
if ( V_11 ) {
F_6 ( V_3 , L_13 , V_11 ) ;
return V_11 ;
}
return F_34 ( V_3 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
return F_37 ( V_3 ) ;
}
