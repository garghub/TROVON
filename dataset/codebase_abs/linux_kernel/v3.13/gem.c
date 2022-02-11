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
if ( ! ( V_6 -> V_15 -> V_16 & V_17 ) )
return - V_18 ;
F_8 ( & V_6 -> V_19 ) ;
V_2 = F_9 ( V_6 , V_10 , V_12 ) ;
if ( V_2 == NULL ) {
V_14 = - V_20 ;
goto V_21;
}
V_14 = F_10 ( V_2 ) ;
if ( V_14 )
goto V_22;
* V_13 = F_11 ( & V_2 -> V_23 ) ;
V_22:
F_12 ( V_2 ) ;
V_21:
F_13 ( & V_6 -> V_19 ) ;
return V_14 ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_7 * V_6 , T_2 V_24 , T_1 * V_25 )
{
struct V_3 * V_26 ;
int V_14 ;
T_3 V_12 ;
V_24 = F_15 ( V_24 , V_27 ) ;
V_26 = F_16 ( V_6 , V_24 , L_1 , 0 ) ;
if ( V_26 == NULL ) {
F_17 ( V_6 -> V_6 , L_2 , V_24 ) ;
return - V_28 ;
}
if ( F_18 ( V_6 , & V_26 -> V_5 , V_24 ) != 0 ) {
F_5 ( V_6 , V_26 ) ;
F_17 ( V_6 -> V_6 , L_3 , V_24 ) ;
return - V_29 ;
}
F_19 ( V_26 -> V_5 . V_30 -> V_31 , V_32 | V_33 ) ;
V_14 = F_20 ( V_10 , & V_26 -> V_5 , & V_12 ) ;
if ( V_14 ) {
F_17 ( V_6 -> V_6 , L_4 ,
& V_26 -> V_5 , V_24 ) ;
F_4 ( & V_26 -> V_5 ) ;
F_5 ( V_6 , V_26 ) ;
return V_14 ;
}
F_12 ( & V_26 -> V_5 ) ;
* V_25 = V_12 ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 , struct V_7 * V_6 ,
struct V_34 * args )
{
args -> V_35 = F_22 ( args -> V_36 * ( ( args -> V_37 + 7 ) / 8 ) , 64 ) ;
args -> V_24 = args -> V_35 * args -> V_38 ;
return F_14 ( V_10 , V_6 , args -> V_24 , & args -> V_12 ) ;
}
int F_23 ( struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_3 * V_26 ;
int V_14 ;
unsigned long V_43 ;
T_4 V_44 ;
struct V_7 * V_6 ;
struct V_45 * V_46 ;
V_2 = V_40 -> V_47 ;
V_6 = V_2 -> V_6 ;
V_46 = V_6 -> V_48 ;
V_26 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_8 ( & V_6 -> V_19 ) ;
if ( V_26 -> V_49 == 0 ) {
V_14 = F_24 ( V_26 ) ;
if ( V_14 < 0 ) {
F_17 ( V_6 -> V_6 , L_5 , V_14 ) ;
goto V_50;
}
V_26 -> V_49 = 1 ;
}
V_44 = ( ( unsigned long ) V_42 -> V_51 - V_40 -> V_52 )
>> V_53 ;
if ( V_26 -> V_54 )
V_43 = ( V_46 -> V_55 + V_26 -> V_13 ) >> V_53 ;
else
V_43 = F_25 ( V_26 -> V_56 [ V_44 ] ) ;
V_14 = F_26 ( V_40 , ( unsigned long ) V_42 -> V_51 , V_43 ) ;
V_50:
F_13 ( & V_6 -> V_19 ) ;
switch ( V_14 ) {
case 0 :
case - V_57 :
case - V_58 :
return V_59 ;
case - V_29 :
return V_60 ;
default:
return V_61 ;
}
}
static int F_27 ( struct V_9 * V_10 , struct V_7 * V_6 ,
int V_24 , T_3 * V_12 )
{
struct V_3 * V_4 = F_16 ( V_6 , V_24 , L_1 , 1 ) ;
if ( V_4 == NULL )
return - V_29 ;
F_28 ( V_6 , & V_4 -> V_5 , V_24 ) ;
if ( F_20 ( V_10 , & V_4 -> V_5 , V_12 ) == 0 )
return 0 ;
F_4 ( & V_4 -> V_5 ) ;
F_5 ( V_6 , V_4 ) ;
return - V_29 ;
}
int F_29 ( struct V_7 * V_6 , void * V_8 ,
struct V_9 * V_10 )
{
struct V_62 * args = V_8 ;
int V_14 ;
if ( args -> V_63 & V_64 ) {
V_14 = F_27 ( V_10 , V_6 , args -> V_24 ,
& args -> V_12 ) ;
if ( V_14 == 0 )
return 0 ;
args -> V_63 &= ~ V_64 ;
}
return F_14 ( V_10 , V_6 , args -> V_24 , & args -> V_12 ) ;
}
int F_30 ( struct V_7 * V_6 , void * V_8 ,
struct V_9 * V_10 )
{
struct V_65 * args = V_8 ;
return V_6 -> V_15 -> V_66 ( V_10 , V_6 ,
args -> V_12 , & args -> V_13 ) ;
}
