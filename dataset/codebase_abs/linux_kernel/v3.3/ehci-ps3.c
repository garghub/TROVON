static void F_1 ( struct V_1 * V_2 )
{
enum T_1 {
V_3 = 0x084 ,
V_4 = 0x088 ,
V_5 = 0x08c ,
};
F_2 ( 0x01000020 , ( void V_6 * ) V_2 -> V_7 +
V_3 ) ;
F_2 ( 0x00000001 , ( void V_6 * ) V_2 -> V_7 +
V_5 ) ;
}
static int F_3 ( struct V_8 * V_9 )
{
int V_10 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_2 -> V_11 = 1 ;
V_2 -> V_12 = V_9 -> V_7 ;
V_2 -> V_7 = V_9 -> V_7 + F_5 ( V_2 , F_6 ( V_2 ,
& V_2 -> V_12 -> V_13 ) ) ;
F_7 ( V_2 , L_1 ) ;
F_8 ( V_2 , L_1 ) ;
V_2 -> V_14 = F_6 ( V_2 , & V_2 -> V_12 -> V_14 ) ;
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 )
return V_10 ;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_12 ( struct V_15 * V_16 )
{
int V_10 ;
struct V_8 * V_9 ;
unsigned int V_17 ;
static T_3 V_18 = F_13 ( 32 ) ;
if ( F_14 () ) {
V_10 = - V_19 ;
goto V_20;
}
V_10 = F_15 ( V_16 ) ;
if ( V_10 ) {
F_16 ( & V_16 -> V_21 , L_2 ,
V_22 , __LINE__ ) ;
goto V_23;
}
V_10 = F_17 ( V_16 -> V_24 ) ;
if ( V_10 ) {
F_16 ( & V_16 -> V_21 , L_3
L_4 , V_22 , __LINE__ , V_10 ) ;
F_18 ( L_5 ) ;
goto V_25;
}
V_10 = F_19 ( V_16 -> V_26 ) ;
if ( V_10 ) {
F_16 ( & V_16 -> V_21 , L_6 ,
V_22 , __LINE__ ) ;
V_10 = - V_27 ;
goto V_28;
}
F_16 ( & V_16 -> V_21 , L_7 , V_22 ,
__LINE__ , V_16 -> V_26 -> V_29 ) ;
V_10 = F_20 ( V_30 , V_16 -> V_31 , & V_17 ) ;
if ( V_10 ) {
F_16 ( & V_16 -> V_21 , L_8 ,
V_22 , __LINE__ , V_17 ) ;
V_10 = - V_27 ;
goto V_32;
}
V_16 -> V_21 . V_33 = & V_18 ;
V_9 = F_21 ( & V_34 , & V_16 -> V_21 , F_22 ( & V_16 -> V_21 ) ) ;
if ( ! V_9 ) {
F_16 ( & V_16 -> V_21 , L_9 , V_22 ,
__LINE__ ) ;
V_10 = - V_35 ;
goto V_36;
}
V_9 -> V_37 = V_16 -> V_26 -> V_29 ;
V_9 -> V_38 = V_16 -> V_26 -> V_39 ;
if ( ! F_23 ( V_9 -> V_37 , V_9 -> V_38 , V_40 ) )
F_16 ( & V_16 -> V_21 , L_10 ,
V_22 , __LINE__ ) ;
V_9 -> V_7 = F_24 ( V_16 -> V_26 -> V_29 , V_16 -> V_26 -> V_39 ) ;
if ( ! V_9 -> V_7 ) {
F_16 ( & V_16 -> V_21 , L_11 , V_22 ,
__LINE__ ) ;
V_10 = - V_27 ;
goto V_41;
}
F_16 ( & V_16 -> V_21 , L_12 , V_22 , __LINE__ ,
( unsigned long ) V_9 -> V_37 ) ;
F_16 ( & V_16 -> V_21 , L_13 , V_22 , __LINE__ ,
( unsigned long ) V_9 -> V_38 ) ;
F_16 ( & V_16 -> V_21 , L_14 , V_22 , __LINE__ ,
( unsigned long ) V_9 -> V_7 ) ;
F_16 ( & V_16 -> V_21 , L_15 , V_22 , __LINE__ ,
( unsigned long ) V_17 ) ;
F_25 ( V_16 , V_9 ) ;
V_10 = F_26 ( V_9 , V_17 , 0 ) ;
if ( V_10 ) {
F_16 ( & V_16 -> V_21 , L_16 ,
V_22 , __LINE__ , V_10 ) ;
goto V_42;
}
return V_10 ;
V_42:
F_27 ( V_9 -> V_7 ) ;
V_41:
F_28 ( V_9 -> V_37 , V_9 -> V_38 ) ;
F_29 ( V_9 ) ;
V_36:
F_30 ( V_17 ) ;
V_32:
F_31 ( V_16 -> V_26 ) ;
V_28:
F_32 ( V_16 -> V_24 ) ;
V_25:
F_33 ( V_16 ) ;
V_23:
V_20:
return V_10 ;
}
static int F_34 ( struct V_15 * V_16 )
{
unsigned int V_43 ;
struct V_8 * V_9 = F_35 ( V_16 ) ;
F_18 ( ! V_9 ) ;
F_16 ( & V_16 -> V_21 , L_17 , V_22 , __LINE__ , V_9 -> V_7 ) ;
F_16 ( & V_16 -> V_21 , L_18 , V_22 , __LINE__ , V_9 -> V_44 ) ;
V_43 = V_9 -> V_44 ;
F_36 ( V_9 ) ;
F_37 ( V_9 ) ;
F_25 ( V_16 , NULL ) ;
F_18 ( ! V_9 -> V_7 ) ;
F_27 ( V_9 -> V_7 ) ;
F_28 ( V_9 -> V_37 , V_9 -> V_38 ) ;
F_29 ( V_9 ) ;
F_30 ( V_43 ) ;
F_31 ( V_16 -> V_26 ) ;
F_32 ( V_16 -> V_24 ) ;
F_33 ( V_16 ) ;
return 0 ;
}
static int T_4 F_38 ( struct V_45 * V_46 )
{
return F_39 ( V_47 )
? F_40 ( V_46 )
: 0 ;
}
static void F_41 ( struct V_45 * V_46 )
{
if ( F_39 ( V_47 ) )
F_42 ( V_46 ) ;
}
