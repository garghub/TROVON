void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 -> V_6 , V_4 ) ;
}
int F_6 ( struct V_7 * V_6 , void * V_8 ,
struct V_9 * V_10 )
{
return - V_11 ;
}
int F_7 ( struct V_9 * V_10 , struct V_7 * V_6 ,
T_1 V_12 , T_2 * V_13 )
{
int V_14 = 0 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_10 , V_12 ) ;
if ( V_2 == NULL )
return - V_15 ;
V_14 = F_9 ( V_2 ) ;
if ( V_14 )
goto V_16;
* V_13 = F_10 ( & V_2 -> V_17 ) ;
V_16:
F_11 ( V_2 ) ;
return V_14 ;
}
int F_12 ( struct V_9 * V_10 , struct V_7 * V_6 , T_3 V_18 ,
T_4 * V_19 , int V_20 , T_4 V_21 )
{
struct V_3 * V_22 ;
int V_14 ;
T_4 V_12 ;
V_18 = F_13 ( V_18 , V_23 ) ;
V_22 = F_14 ( V_6 , V_18 , L_1 , 0 , V_23 ) ;
if ( V_22 == NULL ) {
F_15 ( V_6 -> V_6 , L_2 , V_18 ) ;
return - V_24 ;
}
if ( F_16 ( V_6 , & V_22 -> V_5 , V_18 ) != 0 ) {
F_5 ( V_6 , V_22 ) ;
F_15 ( V_6 -> V_6 , L_3 , V_18 ) ;
return - V_25 ;
}
F_17 ( V_22 -> V_5 . V_26 -> V_27 , V_28 | V_29 ) ;
V_14 = F_18 ( V_10 , & V_22 -> V_5 , & V_12 ) ;
if ( V_14 ) {
F_15 ( V_6 -> V_6 , L_4 ,
& V_22 -> V_5 , V_18 ) ;
F_4 ( & V_22 -> V_5 ) ;
F_5 ( V_6 , V_22 ) ;
return V_14 ;
}
F_11 ( & V_22 -> V_5 ) ;
* V_19 = V_12 ;
return 0 ;
}
int F_19 ( struct V_9 * V_10 , struct V_7 * V_6 ,
struct V_30 * args )
{
args -> V_31 = F_20 ( args -> V_32 * ( ( args -> V_33 + 7 ) / 8 ) , 64 ) ;
args -> V_18 = args -> V_31 * args -> V_34 ;
return F_12 ( V_10 , V_6 , args -> V_18 , & args -> V_12 , 0 ,
V_23 ) ;
}
int F_21 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_1 * V_2 ;
struct V_3 * V_22 ;
int V_14 ;
unsigned long V_39 ;
T_5 V_40 ;
struct V_7 * V_6 ;
struct V_41 * V_42 ;
V_2 = V_36 -> V_43 ;
V_6 = V_2 -> V_6 ;
V_42 = V_6 -> V_44 ;
V_22 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_22 ( & V_42 -> V_45 ) ;
if ( V_22 -> V_46 == 0 ) {
V_14 = F_23 ( V_22 ) ;
if ( V_14 < 0 ) {
F_15 ( V_6 -> V_6 , L_5 , V_14 ) ;
goto V_47;
}
V_22 -> V_46 = 1 ;
}
V_40 = ( V_38 -> V_48 - V_36 -> V_49 ) >> V_50 ;
if ( V_22 -> V_20 )
V_39 = ( V_42 -> V_51 + V_22 -> V_13 ) >> V_50 ;
else
V_39 = F_24 ( V_22 -> V_52 [ V_40 ] ) ;
V_14 = F_25 ( V_36 , V_38 -> V_48 , V_39 ) ;
V_47:
F_26 ( & V_42 -> V_45 ) ;
switch ( V_14 ) {
case 0 :
case - V_53 :
case - V_54 :
return V_55 ;
case - V_25 :
return V_56 ;
default:
return V_57 ;
}
}
