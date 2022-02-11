int F_1 ( struct V_1 * V_2 )
{
return - V_3 ;
}
void F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_3 ( V_2 , struct V_4 , V_6 ) ;
F_4 ( V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 . V_9 ) {
struct V_10 * V_11 = V_2 -> V_7 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_8 ;
F_5 ( & V_11 -> V_15 , & V_14 -> V_16 ) ;
F_6 ( V_14 -> V_17 ) ;
F_7 ( V_14 -> V_9 ) ;
V_14 -> V_9 = NULL ;
}
F_8 ( V_2 ) ;
}
int F_9 ( struct V_18 * V_7 , void * V_19 ,
struct V_20 * V_21 )
{
return - V_3 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_18 * V_7 = V_2 -> V_7 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 ;
struct V_22 * V_9 ;
int V_23 ;
V_14 = & V_2 -> V_8 ;
V_14 -> V_9 = F_11 ( sizeof( struct V_13 ) , V_24 ) ;
if ( V_14 -> V_9 == NULL )
return - V_25 ;
V_9 = V_14 -> V_9 ;
V_9 -> type = V_26 ;
V_9 -> V_27 = V_2 -> V_27 ;
V_9 -> V_28 = V_2 ;
V_14 -> V_17 = F_12 ( & V_11 -> V_29 ,
V_2 -> V_27 / V_30 , 0 , 0 ) ;
if ( ! V_14 -> V_17 ) {
F_13 ( L_1 , V_2 -> V_31 ) ;
V_23 = - V_32 ;
goto V_33;
}
V_14 -> V_17 = F_14 ( V_14 -> V_17 ,
V_2 -> V_27 / V_30 , 0 ) ;
if ( ! V_14 -> V_17 ) {
V_23 = - V_25 ;
goto V_33;
}
V_14 -> V_16 . V_34 = V_14 -> V_17 -> V_35 ;
V_23 = F_15 ( & V_11 -> V_15 , & V_14 -> V_16 ) ;
if ( V_23 ) {
F_13 ( L_2 ) ;
goto V_36;
}
return 0 ;
V_36:
F_6 ( V_14 -> V_17 ) ;
V_33:
F_7 ( V_14 -> V_9 ) ;
V_14 -> V_9 = NULL ;
return V_23 ;
}
int F_16 ( struct V_20 * V_21 , struct V_18 * V_7 ,
T_1 V_28 , T_2 * V_37 )
{
int V_23 = 0 ;
struct V_1 * V_2 ;
if ( ! ( V_7 -> V_38 -> V_39 & V_40 ) )
return - V_41 ;
F_17 ( & V_7 -> V_42 ) ;
V_2 = F_18 ( V_7 , V_21 , V_28 ) ;
if ( V_2 == NULL ) {
V_23 = - V_43 ;
goto V_44;
}
if ( ! V_2 -> V_8 . V_9 ) {
V_23 = F_10 ( V_2 ) ;
if ( V_23 )
goto V_45;
}
* V_37 = ( V_46 ) V_2 -> V_8 . V_16 . V_34 << V_47 ;
V_45:
F_19 ( V_2 ) ;
V_44:
F_20 ( & V_7 -> V_42 ) ;
return V_23 ;
}
static int F_21 ( struct V_20 * V_21 ,
struct V_18 * V_7 , T_2 V_27 , T_1 * V_48 )
{
struct V_4 * V_49 ;
int V_23 ;
T_3 V_28 ;
V_27 = F_22 ( V_27 , V_30 ) ;
V_49 = F_23 ( V_7 , V_27 , L_3 , 0 ) ;
if ( V_49 == NULL )
return - V_32 ;
if ( F_24 ( V_7 , & V_49 -> V_6 , V_27 ) != 0 ) {
F_4 ( V_7 , V_49 ) ;
return - V_25 ;
}
V_23 = F_25 ( V_21 , & V_49 -> V_6 , & V_28 ) ;
if ( V_23 ) {
F_8 ( & V_49 -> V_6 ) ;
F_4 ( V_7 , V_49 ) ;
return V_23 ;
}
F_19 ( & V_49 -> V_6 ) ;
* V_48 = V_28 ;
return 0 ;
}
int F_26 ( struct V_20 * V_21 , struct V_18 * V_7 ,
struct V_50 * args )
{
args -> V_51 = F_27 ( args -> V_52 * ( ( args -> V_53 + 7 ) / 8 ) , 64 ) ;
args -> V_27 = args -> V_51 * args -> V_54 ;
return F_21 ( V_21 , V_7 , args -> V_27 , & args -> V_28 ) ;
}
int F_28 ( struct V_20 * V_21 , struct V_18 * V_7 ,
T_1 V_28 )
{
return F_29 ( V_21 , V_28 ) ;
}
int F_30 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_4 * V_49 ;
int V_23 ;
unsigned long V_59 ;
T_4 V_60 ;
struct V_18 * V_7 ;
V_2 = V_56 -> V_61 ;
V_7 = V_2 -> V_7 ;
V_49 = F_3 ( V_2 , struct V_4 , V_6 ) ;
F_17 ( & V_7 -> V_42 ) ;
if ( V_49 -> V_62 == 0 ) {
V_23 = F_31 ( V_49 ) ;
if ( V_23 < 0 ) {
F_13 ( L_4 , V_23 ) ;
goto V_63;
}
V_49 -> V_62 = 1 ;
}
V_60 = ( ( unsigned long ) V_58 -> V_64 - V_56 -> V_65 )
>> V_47 ;
V_59 = ( V_49 -> V_66 . V_35 >> V_47 ) + V_60 ;
F_32 ( L_5 , ( void * ) ( V_49 -> V_66 . V_35 ) ) ;
F_32 ( L_6 , V_58 -> V_64 ,
V_59 , V_59 << V_47 ) ;
V_23 = F_33 ( V_56 , ( unsigned long ) V_58 -> V_64 , V_59 ) ;
V_63:
F_20 ( & V_7 -> V_42 ) ;
switch ( V_23 ) {
case 0 :
case - V_67 :
case - V_68 :
return V_69 ;
case - V_25 :
return V_70 ;
default:
return V_71 ;
}
}
