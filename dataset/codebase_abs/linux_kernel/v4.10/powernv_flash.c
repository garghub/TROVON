static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
T_1 V_5 , T_2 V_6 , T_2 * V_7 , T_3 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
struct V_12 * V_13 = & V_2 -> V_13 ;
int V_14 ;
struct V_15 V_16 ;
int V_17 ;
F_2 ( V_13 , L_1 ,
V_18 , V_4 , V_5 , V_6 ) ;
V_14 = F_3 () ;
if ( V_14 < 0 ) {
if ( V_14 != - V_19 )
F_4 ( V_13 , L_2 ) ;
return V_14 ;
}
switch ( V_4 ) {
case V_20 :
V_17 = F_5 ( V_10 -> V_21 , V_5 , F_6 ( V_8 ) , V_6 , V_14 ) ;
break;
case V_22 :
V_17 = F_7 ( V_10 -> V_21 , V_5 , F_6 ( V_8 ) , V_6 , V_14 ) ;
break;
case V_23 :
V_17 = F_8 ( V_10 -> V_21 , V_5 , V_6 , V_14 ) ;
break;
default:
F_9 ( 1 ) ;
}
if ( V_17 != V_24 ) {
F_4 ( V_13 , L_3 ,
V_4 , V_17 ) ;
F_10 ( V_14 ) ;
return - V_25 ;
}
V_17 = F_11 ( V_14 , & V_16 ) ;
F_10 ( V_14 ) ;
if ( V_17 ) {
F_4 ( V_13 , L_4 , V_17 ) ;
return - V_25 ;
}
V_17 = F_12 ( V_16 ) ;
if ( V_17 == V_26 ) {
V_17 = 0 ;
if ( V_7 )
* V_7 = V_6 ;
} else {
V_17 = - V_25 ;
}
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_27 , T_2 V_6 ,
T_2 * V_7 , T_3 * V_8 )
{
return F_1 ( V_2 , V_20 , V_27 ,
V_6 , V_7 , V_8 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_28 , T_2 V_6 ,
T_2 * V_7 , const T_3 * V_8 )
{
return F_1 ( V_2 , V_22 , V_28 ,
V_6 , V_7 , ( T_3 * ) V_8 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_17 ;
V_30 -> V_31 = V_32 ;
V_17 = F_1 ( V_2 , V_23 , V_30 -> V_33 ,
V_30 -> V_6 , NULL , NULL ) ;
if ( V_17 ) {
V_30 -> V_34 = V_30 -> V_33 ;
V_30 -> V_31 = V_35 ;
} else {
V_30 -> V_31 = V_36 ;
}
F_16 ( V_30 ) ;
return V_17 ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
T_4 V_37 ;
T_5 V_38 ;
int V_17 ;
V_17 = F_18 ( V_13 -> V_39 , L_5 ,
& V_38 ) ;
if ( V_17 ) {
F_4 ( V_13 , L_6 ) ;
return V_17 ;
}
V_17 = F_19 ( V_13 -> V_39 , L_7 , & V_37 ) ;
if ( V_17 ) {
F_4 ( V_13 , L_8 ) ;
return V_17 ;
}
V_2 -> V_40 = F_20 ( V_13 -> V_39 , L_9 , NULL ) ;
V_2 -> type = V_41 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_44 = V_38 ;
V_2 -> V_45 = V_2 -> V_46 = 1 ;
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = F_15 ;
V_2 -> V_50 = F_13 ;
V_2 -> V_51 = F_14 ;
V_2 -> V_13 . V_52 = V_13 ;
return 0 ;
}
static int F_21 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = & V_54 -> V_13 ;
struct V_9 * V_55 ;
int V_56 ;
V_55 = F_22 ( V_13 , sizeof( * V_55 ) , V_57 ) ;
if ( ! V_55 ) {
V_56 = - V_58 ;
goto V_59;
}
V_55 -> V_2 . V_11 = V_55 ;
V_56 = F_18 ( V_13 -> V_39 , L_10 , & ( V_55 -> V_21 ) ) ;
if ( V_56 ) {
F_4 ( V_13 , L_11 ) ;
goto V_59;
}
V_56 = F_17 ( V_13 , & V_55 -> V_2 ) ;
if ( V_56 )
goto V_59;
F_23 ( V_13 , V_55 ) ;
V_56 = F_24 ( & V_55 -> V_2 , NULL , 0 ) ;
V_59:
return V_56 ;
}
static int F_25 ( struct V_53 * V_54 )
{
struct V_9 * V_55 = F_26 ( & ( V_54 -> V_13 ) ) ;
return F_27 ( & ( V_55 -> V_2 ) ) ;
}
