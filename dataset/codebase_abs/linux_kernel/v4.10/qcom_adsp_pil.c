static int F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
T_1 V_7 ;
T_2 V_8 ;
bool V_9 ;
int V_10 ;
V_10 = F_2 ( V_11 , V_3 -> V_12 , V_3 -> V_13 ) ;
if ( V_10 ) {
F_3 ( & V_1 -> V_14 , L_1 ) ;
return V_10 ;
}
V_10 = F_4 ( V_3 , & V_7 , & V_8 , & V_9 ) ;
if ( V_10 ) {
F_3 ( & V_1 -> V_14 , L_2 ) ;
return V_10 ;
}
if ( V_9 ) {
V_5 -> V_15 = V_7 ;
V_10 = F_5 ( V_11 , V_5 -> V_16 , V_8 ) ;
if ( V_10 ) {
F_3 ( & V_1 -> V_14 , L_3 ) ;
return V_10 ;
}
}
return F_6 ( V_1 , V_3 , V_1 -> V_2 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
int V_10 ;
V_10 = F_8 ( V_5 -> V_17 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_9 ( V_5 -> V_18 ) ;
if ( V_10 )
goto V_19;
V_10 = F_10 ( V_11 ) ;
if ( V_10 ) {
F_3 ( V_5 -> V_14 ,
L_4 ) ;
goto V_20;
}
V_10 = F_11 ( & V_5 -> V_21 ,
F_12 ( 5000 ) ) ;
if ( ! V_10 ) {
F_3 ( V_5 -> V_14 , L_5 ) ;
F_13 ( V_11 ) ;
V_10 = - V_22 ;
goto V_20;
}
V_10 = 0 ;
V_20:
F_14 ( V_5 -> V_18 ) ;
V_19:
F_15 ( V_5 -> V_17 ) ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
int V_10 ;
F_17 ( V_5 -> V_23 ,
F_18 ( V_5 -> V_24 ) ,
F_18 ( V_5 -> V_24 ) ) ;
V_10 = F_11 ( & V_5 -> V_25 ,
F_12 ( 5000 ) ) ;
if ( V_10 == 0 )
F_3 ( V_5 -> V_14 , L_6 ) ;
F_17 ( V_5 -> V_23 ,
F_18 ( V_5 -> V_24 ) ,
0 ) ;
V_10 = F_13 ( V_11 ) ;
if ( V_10 )
F_3 ( V_5 -> V_14 , L_7 , V_10 ) ;
return V_10 ;
}
static void * F_19 ( struct V_1 * V_1 , T_3 V_26 , int V_27 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
int V_28 ;
V_28 = V_26 - V_5 -> V_15 ;
if ( V_28 < 0 || V_28 + V_27 > V_5 -> V_29 )
return NULL ;
return V_5 -> V_30 + V_28 ;
}
static T_4 F_20 ( int V_31 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
F_21 ( V_5 -> V_1 , V_32 ) ;
return V_33 ;
}
static T_4 F_22 ( int V_31 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
T_2 V_27 ;
char * V_34 ;
V_34 = F_23 ( V_35 , V_36 , & V_27 ) ;
if ( ! F_24 ( V_34 ) && V_27 > 0 && V_34 [ 0 ] )
F_3 ( V_5 -> V_14 , L_8 , V_34 ) ;
F_21 ( V_5 -> V_1 , V_37 ) ;
if ( ! F_24 ( V_34 ) )
V_34 [ 0 ] = '\0' ;
return V_33 ;
}
static T_4 F_25 ( int V_31 , void * V_14 )
{
return V_33 ;
}
static T_4 F_26 ( int V_31 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
F_27 ( & V_5 -> V_21 ) ;
return V_33 ;
}
static T_4 F_28 ( int V_31 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
F_27 ( & V_5 -> V_25 ) ;
return V_33 ;
}
static int F_29 ( struct V_4 * V_5 )
{
int V_10 ;
V_5 -> V_17 = F_30 ( V_5 -> V_14 , L_9 ) ;
if ( F_24 ( V_5 -> V_17 ) ) {
V_10 = F_31 ( V_5 -> V_17 ) ;
if ( V_10 != - V_38 )
F_3 ( V_5 -> V_14 , L_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 )
{
V_5 -> V_18 = F_33 ( V_5 -> V_14 , L_11 ) ;
if ( F_24 ( V_5 -> V_18 ) )
return F_31 ( V_5 -> V_18 ) ;
F_34 ( V_5 -> V_18 , 100000 ) ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_5 V_42 )
{
int V_10 ;
V_10 = F_36 ( V_40 , V_41 ) ;
if ( V_10 < 0 ) {
F_3 ( & V_40 -> V_14 , L_12 , V_41 ) ;
return V_10 ;
}
V_10 = F_37 ( & V_40 -> V_14 , V_10 ,
NULL , V_42 ,
V_43 ,
L_13 , V_5 ) ;
if ( V_10 )
F_3 ( & V_40 -> V_14 , L_14 , V_41 ) ;
return V_10 ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_44 * V_45 ;
struct V_46 V_47 ;
int V_10 ;
V_45 = F_39 ( V_5 -> V_14 -> V_48 , L_15 , 0 ) ;
if ( ! V_45 ) {
F_3 ( V_5 -> V_14 , L_16 ) ;
return - V_49 ;
}
V_10 = F_40 ( V_45 , 0 , & V_47 ) ;
if ( V_10 )
return V_10 ;
V_5 -> V_16 = V_5 -> V_15 = V_47 . V_50 ;
V_5 -> V_29 = F_41 ( & V_47 ) ;
V_5 -> V_30 = F_42 ( V_5 -> V_14 , V_5 -> V_16 , V_5 -> V_29 ) ;
if ( ! V_5 -> V_30 ) {
F_3 ( V_5 -> V_14 , L_17 ,
& V_47 . V_50 , V_5 -> V_29 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_43 ( struct V_39 * V_40 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_10 ;
if ( ! F_44 () )
return - V_38 ;
if ( ! F_45 ( V_11 ) ) {
F_3 ( & V_40 -> V_14 , L_18 ) ;
return - V_52 ;
}
V_1 = F_46 ( & V_40 -> V_14 , V_40 -> V_41 , & V_53 ,
V_54 , sizeof( * V_5 ) ) ;
if ( ! V_1 ) {
F_3 ( & V_40 -> V_14 , L_19 ) ;
return - V_55 ;
}
V_1 -> V_56 = & V_57 ;
V_5 = (struct V_4 * ) V_1 -> V_6 ;
V_5 -> V_14 = & V_40 -> V_14 ;
V_5 -> V_1 = V_1 ;
F_47 ( V_40 , V_5 ) ;
F_48 ( & V_5 -> V_21 ) ;
F_48 ( & V_5 -> V_25 ) ;
V_10 = F_38 ( V_5 ) ;
if ( V_10 )
goto V_58;
V_10 = F_29 ( V_5 ) ;
if ( V_10 )
goto V_58;
V_10 = F_32 ( V_5 ) ;
if ( V_10 )
goto V_58;
V_10 = F_35 ( V_5 , V_40 , L_20 , F_20 ) ;
if ( V_10 < 0 )
goto V_58;
V_5 -> V_59 = V_10 ;
V_10 = F_35 ( V_5 , V_40 , L_21 , F_22 ) ;
if ( V_10 < 0 )
goto V_58;
V_5 -> V_60 = V_10 ;
V_10 = F_35 ( V_5 , V_40 , L_22 , F_25 ) ;
if ( V_10 < 0 )
goto V_58;
V_5 -> V_61 = V_10 ;
V_10 = F_35 ( V_5 , V_40 , L_23 , F_26 ) ;
if ( V_10 < 0 )
goto V_58;
V_5 -> V_62 = V_10 ;
V_10 = F_35 ( V_5 , V_40 , L_24 , F_28 ) ;
if ( V_10 < 0 )
goto V_58;
V_5 -> V_63 = V_10 ;
V_5 -> V_23 = F_49 ( & V_40 -> V_14 , L_25 ,
& V_5 -> V_24 ) ;
if ( F_24 ( V_5 -> V_23 ) ) {
V_10 = F_31 ( V_5 -> V_23 ) ;
goto V_58;
}
V_10 = F_50 ( V_1 ) ;
if ( V_10 )
goto V_58;
return 0 ;
V_58:
F_51 ( V_1 ) ;
return V_10 ;
}
static int F_52 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = F_53 ( V_40 ) ;
F_54 ( V_5 -> V_23 ) ;
F_55 ( V_5 -> V_1 ) ;
F_51 ( V_5 -> V_1 ) ;
return 0 ;
}
