static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_5 , V_7 ,
NULL , 0 , NULL , 0 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_6 ;
V_6 = F_5 ( V_4 ) ;
if ( V_6 )
return V_6 ;
if ( F_6 ( & V_2 -> V_9 ) )
F_1 ( V_2 ) ;
V_6 = F_2 ( V_2 -> V_5 , V_10 ,
NULL , 0 , NULL , 0 ) ;
if ( V_6 ) {
F_3 ( V_4 ) ;
return V_6 ;
}
F_7 ( & V_2 -> V_9 , F_8 ( V_8 ) ) ;
return 0 ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_9 * V_9 = F_10 ( V_12 ) ;
struct V_1 * V_2 =
F_11 ( V_9 ,
struct V_1 ,
V_9 ) ;
F_1 ( V_2 ) ;
}
static T_2 F_12 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_18 )
{
struct V_1 * V_2 = F_13 ( V_14 ) ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_14 ( V_17 , 10 , & V_19 ) ;
if ( V_20 < 0 ) {
F_15 ( V_14 , L_1 , V_20 ) ;
return V_20 ;
}
if ( V_19 )
V_20 = F_4 ( V_2 , ( T_1 ) V_19 ) ;
else
V_20 = F_1 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return V_18 ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_5 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_20 ;
if ( V_4 -> V_26 != 1 )
return - V_27 ;
V_24 = & V_4 -> V_24 [ 0 ] ;
if ( V_24 -> V_28 != V_29 )
return - V_27 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_5 = F_18 ( V_4 , F_19 ( V_24 -> V_22 ) ,
NULL ) ;
if ( F_20 ( V_5 ) ) {
V_20 = F_21 ( V_5 ) ;
goto V_32;
}
F_22 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
F_23 ( V_4 , V_2 ) ;
V_20 = F_24 ( V_5 ) ;
if ( V_20 )
goto V_33;
V_2 -> V_34 = F_25 ( & V_35 , 0 , 0 , V_30 ) ;
if ( V_2 -> V_34 < 0 ) {
V_20 = V_2 -> V_34 ;
goto V_36;
}
V_14 = F_26 ( & V_37 , & V_4 -> V_14 ,
F_27 ( 0 , 0 ) , V_2 , L_2 , V_2 -> V_34 ) ;
if ( F_20 ( V_14 ) ) {
V_20 = - V_38 ;
goto V_39;
}
V_2 -> V_14 = V_14 ;
F_28 ( & V_2 -> V_9 , F_9 ) ;
F_3 ( V_4 ) ;
return 0 ;
V_39:
F_29 ( & V_35 , V_2 -> V_34 ) ;
V_36:
F_30 ( V_5 ) ;
V_33:
F_31 ( V_5 ) ;
V_32:
F_32 ( V_2 ) ;
return V_20 ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_34 ( V_4 ) ;
int V_6 ;
V_6 = F_5 ( V_4 ) ;
if ( V_6 )
F_35 ( V_4 ) ;
if ( F_6 ( & V_2 -> V_9 ) )
F_1 ( V_2 ) ;
F_36 ( V_2 -> V_14 ) ;
F_29 ( & V_35 , V_2 -> V_34 ) ;
F_30 ( V_2 -> V_5 ) ;
F_31 ( V_2 -> V_5 ) ;
F_32 ( V_2 ) ;
}
static T_4 int F_37 ( void )
{
int V_20 ;
V_20 = F_38 ( & V_37 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_39 ( & V_40 ) ;
if ( V_20 )
goto V_41;
return 0 ;
V_41:
F_40 ( & V_37 ) ;
return V_20 ;
}
static T_5 void F_41 ( void )
{
F_42 ( & V_40 ) ;
F_40 ( & V_37 ) ;
F_43 ( & V_35 ) ;
}
