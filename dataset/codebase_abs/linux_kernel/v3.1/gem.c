int F_1 ( struct V_1 * V_2 )
{
return - V_3 ;
}
void F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_3 ( V_2 , struct V_4 , V_6 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 -> V_7 , V_5 ) ;
}
int F_6 ( struct V_8 * V_7 , void * V_9 ,
struct V_10 * V_11 )
{
return - V_3 ;
}
int F_7 ( struct V_10 * V_11 , struct V_8 * V_7 ,
T_1 V_12 , T_2 * V_13 )
{
int V_14 = 0 ;
struct V_1 * V_2 ;
if ( ! ( V_7 -> V_15 -> V_16 & V_17 ) )
return - V_18 ;
F_8 ( & V_7 -> V_19 ) ;
V_2 = F_9 ( V_7 , V_11 , V_12 ) ;
if ( V_2 == NULL ) {
V_14 = - V_20 ;
goto V_21;
}
if ( ! V_2 -> V_22 . V_23 ) {
V_14 = F_10 ( V_2 ) ;
if ( V_14 )
goto V_24;
}
* V_13 = ( V_25 ) V_2 -> V_22 . V_26 . V_27 << V_28 ;
V_24:
F_11 ( V_2 ) ;
V_21:
F_12 ( & V_7 -> V_19 ) ;
return V_14 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_8 * V_7 , T_2 V_29 , T_1 * V_30 )
{
struct V_4 * V_31 ;
int V_14 ;
T_3 V_12 ;
V_29 = F_14 ( V_29 , V_32 ) ;
V_31 = F_15 ( V_7 , V_29 , L_1 , 0 ) ;
if ( V_31 == NULL ) {
F_16 ( V_7 -> V_7 , L_2 , V_29 ) ;
return - V_33 ;
}
if ( F_17 ( V_7 , & V_31 -> V_6 , V_29 ) != 0 ) {
F_5 ( V_7 , V_31 ) ;
F_16 ( V_7 -> V_7 , L_3 , V_29 ) ;
return - V_34 ;
}
V_14 = F_18 ( V_11 , & V_31 -> V_6 , & V_12 ) ;
if ( V_14 ) {
F_16 ( V_7 -> V_7 , L_4 ,
& V_31 -> V_6 , V_29 ) ;
F_19 ( & V_31 -> V_6 ) ;
F_5 ( V_7 , V_31 ) ;
return V_14 ;
}
F_11 ( & V_31 -> V_6 ) ;
* V_30 = V_12 ;
return 0 ;
}
int F_20 ( struct V_10 * V_11 , struct V_8 * V_7 ,
struct V_35 * args )
{
args -> V_36 = F_21 ( args -> V_37 * ( ( args -> V_38 + 7 ) / 8 ) , 64 ) ;
args -> V_29 = args -> V_36 * args -> V_39 ;
return F_13 ( V_11 , V_7 , args -> V_29 , & args -> V_12 ) ;
}
int F_22 ( struct V_10 * V_11 , struct V_8 * V_7 ,
T_1 V_12 )
{
return F_23 ( V_11 , V_12 ) ;
}
int F_24 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_4 * V_31 ;
int V_14 ;
unsigned long V_44 ;
T_4 V_45 ;
struct V_8 * V_7 ;
struct V_46 * V_47 ;
V_2 = V_41 -> V_48 ;
V_7 = V_2 -> V_7 ;
V_47 = V_7 -> V_49 ;
V_31 = F_3 ( V_2 , struct V_4 , V_6 ) ;
F_8 ( & V_7 -> V_19 ) ;
if ( V_31 -> V_50 == 0 ) {
V_14 = F_25 ( V_31 ) ;
if ( V_14 < 0 ) {
F_16 ( V_7 -> V_7 , L_5 , V_14 ) ;
goto V_51;
}
V_31 -> V_50 = 1 ;
}
V_45 = ( ( unsigned long ) V_43 -> V_52 - V_41 -> V_53 )
>> V_28 ;
if ( V_31 -> V_54 )
V_44 = ( V_47 -> V_55 + V_31 -> V_13 ) >> V_28 ;
else
V_44 = F_26 ( V_31 -> V_56 [ V_45 ] ) ;
V_14 = F_27 ( V_41 , ( unsigned long ) V_43 -> V_52 , V_44 ) ;
V_51:
F_12 ( & V_7 -> V_19 ) ;
switch ( V_14 ) {
case 0 :
case - V_57 :
case - V_58 :
return V_59 ;
case - V_34 :
return V_60 ;
default:
return V_61 ;
}
}
static int F_28 ( struct V_10 * V_11 , struct V_8 * V_7 ,
int V_29 , T_3 * V_12 )
{
struct V_4 * V_5 = F_15 ( V_7 , V_29 , L_1 , 1 ) ;
if ( V_5 == NULL )
return - V_34 ;
if ( F_29 ( V_7 , & V_5 -> V_6 , V_29 ) != 0 )
goto V_62;
if ( F_18 ( V_11 , & V_5 -> V_6 , V_12 ) == 0 )
return 0 ;
V_62:
F_5 ( V_7 , V_5 ) ;
return - V_34 ;
}
int F_30 ( struct V_8 * V_7 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_63 * args = V_9 ;
int V_14 ;
if ( args -> V_64 & V_65 ) {
V_14 = F_28 ( V_11 , V_7 , args -> V_29 ,
& args -> V_12 ) ;
if ( V_14 == 0 )
return 0 ;
args -> V_64 &= ~ V_65 ;
}
return F_13 ( V_11 , V_7 , args -> V_29 , & args -> V_12 ) ;
}
int F_31 ( struct V_8 * V_7 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_66 * args = V_9 ;
return V_7 -> V_15 -> V_67 ( V_11 , V_7 ,
args -> V_12 , & args -> V_13 ) ;
}
