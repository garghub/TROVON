void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_2 -> V_4 , false , false ) ;
V_2 -> V_4 = NULL ;
}
static void F_3 ( struct V_5 * V_2 )
{
struct V_1 * V_6 = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( V_6 -> V_7 && V_2 -> V_8 ) {
F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
F_7 ( V_2 ) ;
if ( V_6 -> V_4 )
F_1 ( V_6 ) ;
V_6 -> V_4 = NULL ;
F_8 ( V_6 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_9 * * V_4 ;
if ( V_2 -> V_4 || V_2 -> V_7 )
return 0 ;
V_4 = F_10 ( & V_2 -> V_3 ) ;
if ( F_11 ( V_4 ) ) {
return F_12 ( V_4 ) ;
}
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_11 -> V_14 ;
T_1 V_15 ;
T_2 V_16 ;
int V_17 ;
V_16 = ( ( unsigned long ) V_13 -> V_18 - V_11 -> V_19 ) >>
V_20 ;
V_15 = F_14 ( V_2 -> V_3 . V_21 , V_22 ) ;
if ( V_16 > V_15 )
return V_23 ;
V_17 = F_15 ( V_11 , ( unsigned long ) V_13 -> V_18 ,
V_2 -> V_4 [ V_16 ] ) ;
switch ( V_17 ) {
case 0 :
return V_24 ;
case - V_25 :
return V_26 ;
case - V_27 :
return V_28 ;
case - V_29 :
case - V_30 :
return V_23 ;
default:
F_16 ( 1 ) ;
return V_23 ;
}
}
static struct V_5 * F_17 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
unsigned int * V_35 ,
unsigned long V_21 )
{
struct V_1 * V_2 ;
struct V_5 * V_36 ;
int V_37 ;
V_21 = F_18 ( V_21 , V_22 ) ;
V_2 = F_19 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return F_20 ( - V_25 ) ;
V_36 = & V_2 -> V_3 ;
V_37 = F_21 ( V_32 , V_36 , V_21 ) ;
if ( V_37 )
goto V_39;
V_37 = F_9 ( V_2 ) ;
if ( V_37 )
goto V_39;
V_37 = F_22 ( V_34 , V_36 , V_35 ) ;
if ( V_37 )
goto V_40;
F_23 ( V_36 ) ;
return V_36 ;
V_40:
F_7 ( V_36 ) ;
V_39:
F_8 ( V_2 ) ;
return F_20 ( V_37 ) ;
}
static int F_24 ( struct V_33 * V_34 , struct V_31 * V_32 ,
struct V_41 * args )
{
struct V_5 * V_36 ;
T_3 V_21 ;
T_3 V_42 = args -> V_43 * F_14 ( args -> V_44 , 8 ) ;
V_21 = args -> V_45 * V_42 ;
if ( V_21 == 0 )
return - V_30 ;
V_36 = F_17 ( V_32 , V_34 , & args -> V_35 , V_21 ) ;
if ( F_11 ( V_36 ) ) {
F_25 ( L_1 ) ;
return F_12 ( V_36 ) ;
}
args -> V_21 = V_36 -> V_21 ;
args -> V_42 = V_42 ;
F_25 ( L_2 , V_21 ) ;
return 0 ;
}
int F_26 ( struct V_33 * V_34 , struct V_31 * V_32 ,
T_4 V_35 , T_3 * V_46 )
{
int V_17 = 0 ;
struct V_5 * V_2 ;
V_2 = F_27 ( V_34 , V_35 ) ;
if ( ! V_2 )
return - V_47 ;
V_17 = F_28 ( V_2 ) ;
if ( V_17 )
goto V_48;
F_29 ( ! V_2 -> V_49 ) ;
V_2 -> V_49 -> V_50 = V_2 ;
* V_46 = F_30 ( & V_2 -> V_51 ) ;
V_48:
F_23 ( V_2 ) ;
return V_17 ;
}
static int T_5 F_31 ( void )
{
int V_17 ;
V_52 = F_32 ( & V_53 , NULL ) ;
if ( ! V_52 ) {
V_17 = - V_25 ;
goto V_39;
}
F_33 ( V_52 , L_3 ) ;
V_17 = F_34 ( V_52 , 0 ) ;
if ( V_17 )
goto V_54;
return 0 ;
V_54:
F_35 ( V_52 ) ;
V_39:
return V_17 ;
}
static void T_6 F_36 ( void )
{
F_37 ( V_52 ) ;
F_35 ( V_52 ) ;
}
