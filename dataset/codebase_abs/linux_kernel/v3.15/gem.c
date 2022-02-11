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
F_8 ( & V_6 -> V_15 ) ;
V_2 = F_9 ( V_6 , V_10 , V_12 ) ;
if ( V_2 == NULL ) {
V_14 = - V_16 ;
goto V_17;
}
V_14 = F_10 ( V_2 ) ;
if ( V_14 )
goto V_18;
* V_13 = F_11 ( & V_2 -> V_19 ) ;
V_18:
F_12 ( V_2 ) ;
V_17:
F_13 ( & V_6 -> V_15 ) ;
return V_14 ;
}
int F_14 ( struct V_9 * V_10 , struct V_7 * V_6 , T_3 V_20 ,
T_4 * V_21 , int V_22 , T_4 V_23 )
{
struct V_3 * V_24 ;
int V_14 ;
T_4 V_12 ;
V_20 = F_15 ( V_20 , V_25 ) ;
V_24 = F_16 ( V_6 , V_20 , L_1 , 0 , V_25 ) ;
if ( V_24 == NULL ) {
F_17 ( V_6 -> V_6 , L_2 , V_20 ) ;
return - V_26 ;
}
if ( F_18 ( V_6 , & V_24 -> V_5 , V_20 ) != 0 ) {
F_5 ( V_6 , V_24 ) ;
F_17 ( V_6 -> V_6 , L_3 , V_20 ) ;
return - V_27 ;
}
F_19 ( V_24 -> V_5 . V_28 -> V_29 , V_30 | V_31 ) ;
V_14 = F_20 ( V_10 , & V_24 -> V_5 , & V_12 ) ;
if ( V_14 ) {
F_17 ( V_6 -> V_6 , L_4 ,
& V_24 -> V_5 , V_20 ) ;
F_4 ( & V_24 -> V_5 ) ;
F_5 ( V_6 , V_24 ) ;
return V_14 ;
}
F_12 ( & V_24 -> V_5 ) ;
* V_21 = V_12 ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 , struct V_7 * V_6 ,
struct V_32 * args )
{
args -> V_33 = F_22 ( args -> V_34 * ( ( args -> V_35 + 7 ) / 8 ) , 64 ) ;
args -> V_20 = args -> V_33 * args -> V_36 ;
return F_14 ( V_10 , V_6 , args -> V_20 , & args -> V_12 , 0 ,
V_25 ) ;
}
int F_23 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
int V_14 ;
unsigned long V_41 ;
T_5 V_42 ;
struct V_7 * V_6 ;
struct V_43 * V_44 ;
V_2 = V_38 -> V_45 ;
V_6 = V_2 -> V_6 ;
V_44 = V_6 -> V_46 ;
V_24 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_8 ( & V_6 -> V_15 ) ;
if ( V_24 -> V_47 == 0 ) {
V_14 = F_24 ( V_24 ) ;
if ( V_14 < 0 ) {
F_17 ( V_6 -> V_6 , L_5 , V_14 ) ;
goto V_48;
}
V_24 -> V_47 = 1 ;
}
V_42 = ( ( unsigned long ) V_40 -> V_49 - V_38 -> V_50 )
>> V_51 ;
if ( V_24 -> V_22 )
V_41 = ( V_44 -> V_52 + V_24 -> V_13 ) >> V_51 ;
else
V_41 = F_25 ( V_24 -> V_53 [ V_42 ] ) ;
V_14 = F_26 ( V_38 , ( unsigned long ) V_40 -> V_49 , V_41 ) ;
V_48:
F_13 ( & V_6 -> V_15 ) ;
switch ( V_14 ) {
case 0 :
case - V_54 :
case - V_55 :
return V_56 ;
case - V_27 :
return V_57 ;
default:
return V_58 ;
}
}
