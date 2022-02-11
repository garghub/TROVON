static int F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
return F_2 ( V_5 -> V_7 , V_3 , V_1 -> V_2 , V_5 -> V_8 ,
V_5 -> V_9 , V_5 -> V_10 , V_5 -> V_11 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
int V_12 ;
V_12 = F_4 ( V_5 -> V_13 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_5 -> V_14 ) ;
if ( V_12 )
goto V_15;
V_12 = F_5 ( V_5 -> V_16 ) ;
if ( V_12 )
goto V_17;
V_12 = F_5 ( V_5 -> V_18 ) ;
if ( V_12 )
goto V_19;
V_12 = F_6 ( V_5 -> V_8 ) ;
if ( V_12 ) {
F_7 ( V_5 -> V_7 ,
L_1 ) ;
goto V_20;
}
V_12 = F_8 ( & V_5 -> V_21 ,
F_9 ( 5000 ) ) ;
if ( ! V_12 ) {
F_7 ( V_5 -> V_7 , L_2 ) ;
F_10 ( V_5 -> V_8 ) ;
V_12 = - V_22 ;
goto V_20;
}
V_12 = 0 ;
V_20:
F_11 ( V_5 -> V_18 ) ;
V_19:
F_11 ( V_5 -> V_16 ) ;
V_17:
F_12 ( V_5 -> V_14 ) ;
V_15:
F_12 ( V_5 -> V_13 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
int V_12 ;
F_14 ( V_5 -> V_23 ,
F_15 ( V_5 -> V_24 ) ,
F_15 ( V_5 -> V_24 ) ) ;
V_12 = F_8 ( & V_5 -> V_25 ,
F_9 ( 5000 ) ) ;
if ( V_12 == 0 )
F_7 ( V_5 -> V_7 , L_3 ) ;
F_14 ( V_5 -> V_23 ,
F_15 ( V_5 -> V_24 ) ,
0 ) ;
V_12 = F_10 ( V_5 -> V_8 ) ;
if ( V_12 )
F_7 ( V_5 -> V_7 , L_4 , V_12 ) ;
return V_12 ;
}
static void * F_16 ( struct V_1 * V_1 , T_1 V_26 , int V_27 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_6 ;
int V_28 ;
V_28 = V_26 - V_5 -> V_29 ;
if ( V_28 < 0 || V_28 + V_27 > V_5 -> V_11 )
return NULL ;
return V_5 -> V_9 + V_28 ;
}
static T_2 F_17 ( int V_30 , void * V_7 )
{
struct V_4 * V_5 = V_7 ;
F_18 ( V_5 -> V_1 , V_31 ) ;
return V_32 ;
}
static T_2 F_19 ( int V_30 , void * V_7 )
{
struct V_4 * V_5 = V_7 ;
T_3 V_27 ;
char * V_33 ;
V_33 = F_20 ( V_34 , V_5 -> V_35 , & V_27 ) ;
if ( ! F_21 ( V_33 ) && V_27 > 0 && V_33 [ 0 ] )
F_7 ( V_5 -> V_7 , L_5 , V_33 ) ;
F_18 ( V_5 -> V_1 , V_36 ) ;
if ( ! F_21 ( V_33 ) )
V_33 [ 0 ] = '\0' ;
return V_32 ;
}
static T_2 F_22 ( int V_30 , void * V_7 )
{
return V_32 ;
}
static T_2 F_23 ( int V_30 , void * V_7 )
{
struct V_4 * V_5 = V_7 ;
F_24 ( & V_5 -> V_21 ) ;
return V_32 ;
}
static T_2 F_25 ( int V_30 , void * V_7 )
{
struct V_4 * V_5 = V_7 ;
F_24 ( & V_5 -> V_25 ) ;
return V_32 ;
}
static int F_26 ( struct V_4 * V_5 )
{
int V_12 ;
V_5 -> V_13 = F_27 ( V_5 -> V_7 , L_6 ) ;
if ( F_21 ( V_5 -> V_13 ) ) {
V_12 = F_28 ( V_5 -> V_13 ) ;
if ( V_12 != - V_37 )
F_7 ( V_5 -> V_7 , L_7 ) ;
return V_12 ;
}
if ( V_5 -> V_38 ) {
V_5 -> V_14 = F_27 ( V_5 -> V_7 , L_8 ) ;
if ( F_21 ( V_5 -> V_14 ) ) {
V_12 = F_28 ( V_5 -> V_14 ) ;
if ( V_12 != - V_37 )
F_7 ( V_5 -> V_7 ,
L_9 ) ;
return V_12 ;
}
}
return 0 ;
}
static int F_29 ( struct V_4 * V_5 )
{
V_5 -> V_16 = F_30 ( V_5 -> V_7 , L_10 ) ;
if ( F_21 ( V_5 -> V_16 ) )
return F_28 ( V_5 -> V_16 ) ;
F_31 ( V_5 -> V_16 , 100000 ) ;
V_5 -> V_18 = F_30 ( V_5 -> V_7 , L_11 ) ;
return F_32 ( V_5 -> V_18 ) ;
}
static int F_33 ( struct V_4 * V_5 ,
struct V_39 * V_40 ,
const char * V_41 ,
T_4 V_42 )
{
int V_12 ;
V_12 = F_34 ( V_40 , V_41 ) ;
if ( V_12 < 0 ) {
F_7 ( & V_40 -> V_7 , L_12 , V_41 ) ;
return V_12 ;
}
V_12 = F_35 ( & V_40 -> V_7 , V_12 ,
NULL , V_42 ,
V_43 ,
L_13 , V_5 ) ;
if ( V_12 )
F_7 ( & V_40 -> V_7 , L_14 , V_41 ) ;
return V_12 ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_44 * V_45 ;
struct V_46 V_47 ;
int V_12 ;
V_45 = F_37 ( V_5 -> V_7 -> V_48 , L_15 , 0 ) ;
if ( ! V_45 ) {
F_7 ( V_5 -> V_7 , L_16 ) ;
return - V_49 ;
}
V_12 = F_38 ( V_45 , 0 , & V_47 ) ;
if ( V_12 )
return V_12 ;
V_5 -> V_10 = V_5 -> V_29 = V_47 . V_50 ;
V_5 -> V_11 = F_39 ( & V_47 ) ;
V_5 -> V_9 = F_40 ( V_5 -> V_7 , V_5 -> V_10 , V_5 -> V_11 ) ;
if ( ! V_5 -> V_9 ) {
F_7 ( V_5 -> V_7 , L_17 ,
& V_47 . V_50 , V_5 -> V_11 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_41 ( struct V_39 * V_40 )
{
const struct V_52 * V_53 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_12 ;
V_53 = F_42 ( & V_40 -> V_7 ) ;
if ( ! V_53 )
return - V_49 ;
if ( ! F_43 () )
return - V_37 ;
V_1 = F_44 ( & V_40 -> V_7 , V_40 -> V_41 , & V_54 ,
V_53 -> V_55 , sizeof( * V_5 ) ) ;
if ( ! V_1 ) {
F_7 ( & V_40 -> V_7 , L_18 ) ;
return - V_56 ;
}
V_1 -> V_57 = & V_58 ;
V_5 = (struct V_4 * ) V_1 -> V_6 ;
V_5 -> V_7 = & V_40 -> V_7 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_8 = V_53 -> V_8 ;
V_5 -> V_35 = V_53 -> V_35 ;
V_5 -> V_38 = V_53 -> V_38 ;
F_45 ( V_40 , V_5 ) ;
F_46 ( & V_5 -> V_21 ) ;
F_46 ( & V_5 -> V_25 ) ;
V_12 = F_36 ( V_5 ) ;
if ( V_12 )
goto V_59;
V_12 = F_26 ( V_5 ) ;
if ( V_12 )
goto V_59;
V_12 = F_29 ( V_5 ) ;
if ( V_12 )
goto V_59;
V_12 = F_33 ( V_5 , V_40 , L_19 , F_17 ) ;
if ( V_12 < 0 )
goto V_59;
V_5 -> V_60 = V_12 ;
V_12 = F_33 ( V_5 , V_40 , L_20 , F_19 ) ;
if ( V_12 < 0 )
goto V_59;
V_5 -> V_61 = V_12 ;
V_12 = F_33 ( V_5 , V_40 , L_21 , F_22 ) ;
if ( V_12 < 0 )
goto V_59;
V_5 -> V_62 = V_12 ;
V_12 = F_33 ( V_5 , V_40 , L_22 , F_23 ) ;
if ( V_12 < 0 )
goto V_59;
V_5 -> V_63 = V_12 ;
V_12 = F_33 ( V_5 , V_40 , L_23 , F_25 ) ;
if ( V_12 < 0 )
goto V_59;
V_5 -> V_64 = V_12 ;
V_5 -> V_23 = F_47 ( & V_40 -> V_7 , L_24 ,
& V_5 -> V_24 ) ;
if ( F_21 ( V_5 -> V_23 ) ) {
V_12 = F_28 ( V_5 -> V_23 ) ;
goto V_59;
}
F_48 ( V_1 , & V_5 -> V_65 ) ;
F_49 ( V_1 , & V_5 -> V_66 ) ;
F_50 ( V_1 , & V_5 -> V_67 , V_53 -> V_68 ) ;
V_12 = F_51 ( V_1 ) ;
if ( V_12 )
goto V_59;
return 0 ;
V_59:
F_52 ( V_1 ) ;
return V_12 ;
}
static int F_53 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = F_54 ( V_40 ) ;
F_55 ( V_5 -> V_23 ) ;
F_56 ( V_5 -> V_1 ) ;
F_57 ( V_5 -> V_1 , & V_5 -> V_65 ) ;
F_58 ( V_5 -> V_1 , & V_5 -> V_66 ) ;
F_59 ( V_5 -> V_1 , & V_5 -> V_67 ) ;
F_52 ( V_5 -> V_1 ) ;
return 0 ;
}
