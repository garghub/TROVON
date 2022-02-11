static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_3 ) {
F_2 ( & V_2 -> V_3 -> V_4 ) ;
F_3 ( V_2 -> V_3 ) ;
F_4 ( V_2 -> V_3 ) ;
}
if ( V_2 -> V_5 ) {
F_2 ( & V_2 -> V_5 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_5 ) ;
}
F_5 ( V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( ! V_2 -> V_3 )
return - V_9 ;
V_8 = V_2 -> V_3 -> V_8 ;
switch ( V_2 -> V_10 ) {
case V_11 :
switch ( V_2 -> V_12 ) {
case V_13 :
V_2 -> V_14 = L_1 ;
return 0 ;
default:
F_7 ( V_8 -> V_8 , L_2 ,
V_2 -> V_12 ) ;
return - V_15 ;
}
case V_16 :
switch ( V_2 -> V_12 ) {
case V_17 :
V_2 -> V_14 = L_3 ;
return 0 ;
default:
F_7 ( V_8 -> V_8 , L_2 ,
V_2 -> V_12 ) ;
return - V_15 ;
}
default:
F_7 ( V_8 -> V_8 , L_4 ,
V_2 -> V_10 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_18 * V_3 ;
struct V_19 V_20 ;
struct V_21 * V_22 = NULL ;
struct F_8 * V_23 ;
T_1 V_24 ;
int V_25 , V_26 ;
V_3 = V_2 -> V_5 ;
V_8 = V_3 -> V_8 ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_27 = V_28 ;
V_20 . V_29 = 1 ;
V_20 . V_30 = V_31 ;
V_26 = F_9 ( V_3 , ( V_32 * ) & V_20 , sizeof( struct V_19 ) , 1 ) ;
if ( V_26 < 0 ) {
F_7 ( V_8 -> V_8 , L_5 ) ;
return V_26 ;
}
V_24 = sizeof( struct V_21 ) +
sizeof( struct F_8 ) ;
V_22 = F_10 ( V_24 , V_33 ) ;
if ( ! V_22 )
return - V_34 ;
V_25 = F_11 ( V_3 , ( V_32 * ) V_22 , V_24 ) ;
if ( V_25 < 0 || V_25 < sizeof( struct V_21 ) ) {
F_7 ( V_8 -> V_8 , L_6 ) ;
V_26 = - V_35 ;
goto V_36;
}
V_23 = (struct F_8 * ) V_22 -> V_37 ;
V_2 -> V_38 = V_23 -> V_38 ;
V_2 -> V_10 = V_23 -> V_10 ;
V_2 -> V_12 = V_23 -> V_12 ;
V_36:
F_4 ( V_22 ) ;
return V_26 ;
}
static void F_12 ( struct V_39 * V_40 )
{
struct V_7 * V_8 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_18 * V_5 ;
struct V_43 * V_44 ;
V_2 = F_13 ( V_40 , struct V_1 , V_45 ) ;
V_5 = V_2 -> V_5 ;
V_8 = V_5 -> V_8 ;
F_14 ( & V_8 -> V_46 ) ;
V_44 = F_15 ( V_8 , & V_47 ) ;
if ( ! V_44 ) {
F_16 ( & V_8 -> V_46 ) ;
F_17 ( V_8 -> V_8 , L_7 ) ;
goto V_36;
}
if ( F_18 ( V_5 , V_44 , NULL ) < 0 ) {
F_5 ( V_44 ) ;
F_16 ( & V_8 -> V_46 ) ;
F_7 ( V_8 -> V_8 , L_8 ) ;
goto V_36;
}
F_5 ( V_44 ) ;
F_16 ( & V_8 -> V_46 ) ;
if ( F_8 ( V_2 ) < 0 ) {
F_7 ( V_8 -> V_8 , L_9 ) ;
goto V_36;
}
F_17 ( V_8 -> V_8 , L_10 ,
V_2 -> V_38 , V_2 -> V_10 , V_2 -> V_12 ) ;
F_14 ( & V_8 -> V_46 ) ;
if ( F_19 ( V_5 ) < 0 ) {
F_16 ( & V_8 -> V_46 ) ;
F_7 ( V_8 -> V_8 , L_11 ) ;
goto V_36;
}
F_16 ( & V_8 -> V_46 ) ;
if ( F_6 ( V_2 ) < 0 ) {
F_7 ( V_8 -> V_8 , L_12 ) ;
return;
}
V_42 = F_20 ( V_8 , V_2 -> V_6 , V_2 -> V_3 ,
V_2 -> V_14 ) ;
if ( ! V_42 ) {
F_7 ( V_8 -> V_8 , L_13 ) ;
goto V_36;
}
V_42 -> V_48 = V_2 ;
return;
V_36:
F_14 ( & V_8 -> V_46 ) ;
F_1 ( V_2 ) ;
F_16 ( & V_8 -> V_46 ) ;
}
int F_21 ( struct V_7 * V_8 , struct V_43 * V_6 )
{
struct V_1 * V_2 ;
struct V_18 * V_5 , * V_3 ;
int V_26 ;
V_3 = F_22 ( V_8 , V_49 ) ;
if ( V_3 )
return 0 ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_2 ) {
V_26 = - V_34 ;
goto V_36;
}
V_2 -> V_6 = F_23 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
V_26 = - V_9 ;
goto V_36;
}
V_5 = F_24 ( V_8 , V_50 ) ;
if ( F_25 ( V_5 ) ) {
V_26 = F_26 ( V_5 ) ;
goto V_36;
}
F_27 ( & V_5 -> V_4 , & V_8 -> V_51 ) ;
V_2 -> V_5 = V_5 ;
V_3 = F_24 ( V_8 , V_50 ) ;
if ( F_25 ( V_3 ) ) {
V_26 = F_26 ( V_3 ) ;
goto V_36;
}
F_27 ( & V_3 -> V_4 , & V_8 -> V_51 ) ;
V_2 -> V_3 = V_3 ;
F_28 ( & V_2 -> V_45 , F_12 ) ;
F_29 ( & V_2 -> V_45 ) ;
return 0 ;
V_36:
F_1 ( V_2 ) ;
return V_26 ;
}
void F_30 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_18 * V_3 ;
struct V_41 * V_42 ;
V_3 = F_22 ( V_8 , V_49 ) ;
if ( ! V_3 )
return;
V_42 = V_3 -> V_52 ;
if ( ! V_42 )
return;
V_2 = (struct V_1 * ) V_42 -> V_48 ;
if ( V_2 )
F_31 ( & V_2 -> V_45 ) ;
V_42 -> V_48 = NULL ;
F_32 ( V_42 ) ;
F_14 ( & V_8 -> V_46 ) ;
F_1 ( V_2 ) ;
F_16 ( & V_8 -> V_46 ) ;
}
