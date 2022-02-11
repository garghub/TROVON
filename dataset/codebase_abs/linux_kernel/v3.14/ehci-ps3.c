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
V_10 = F_5 ( V_9 ) ;
if ( V_10 )
return V_10 ;
F_1 ( V_2 ) ;
return V_10 ;
}
static int F_6 ( struct V_13 * V_14 )
{
int V_10 ;
struct V_8 * V_9 ;
unsigned int V_15 ;
static T_2 V_16 = F_7 ( 32 ) ;
if ( F_8 () ) {
V_10 = - V_17 ;
goto V_18;
}
V_10 = F_9 ( V_14 ) ;
if ( V_10 ) {
F_10 ( & V_14 -> V_19 , L_1 ,
V_20 , __LINE__ ) ;
goto V_21;
}
V_10 = F_11 ( V_14 -> V_22 ) ;
if ( V_10 ) {
F_10 ( & V_14 -> V_19 , L_2
L_3 , V_20 , __LINE__ , V_10 ) ;
F_12 ( L_4 ) ;
goto V_23;
}
V_10 = F_13 ( V_14 -> V_24 ) ;
if ( V_10 ) {
F_10 ( & V_14 -> V_19 , L_5 ,
V_20 , __LINE__ ) ;
V_10 = - V_25 ;
goto V_26;
}
F_10 ( & V_14 -> V_19 , L_6 , V_20 ,
__LINE__ , V_14 -> V_24 -> V_27 ) ;
V_10 = F_14 ( V_28 , V_14 -> V_29 , & V_15 ) ;
if ( V_10 ) {
F_10 ( & V_14 -> V_19 , L_7 ,
V_20 , __LINE__ , V_15 ) ;
V_10 = - V_25 ;
goto V_30;
}
V_14 -> V_19 . V_31 = & V_16 ;
V_9 = F_15 ( & V_32 , & V_14 -> V_19 , F_16 ( & V_14 -> V_19 ) ) ;
if ( ! V_9 ) {
F_10 ( & V_14 -> V_19 , L_8 , V_20 ,
__LINE__ ) ;
V_10 = - V_33 ;
goto V_34;
}
V_9 -> V_35 = V_14 -> V_24 -> V_27 ;
V_9 -> V_36 = V_14 -> V_24 -> V_37 ;
if ( ! F_17 ( V_9 -> V_35 , V_9 -> V_36 , V_38 ) )
F_10 ( & V_14 -> V_19 , L_9 ,
V_20 , __LINE__ ) ;
V_9 -> V_7 = F_18 ( V_14 -> V_24 -> V_27 , V_14 -> V_24 -> V_37 ) ;
if ( ! V_9 -> V_7 ) {
F_10 ( & V_14 -> V_19 , L_10 , V_20 ,
__LINE__ ) ;
V_10 = - V_25 ;
goto V_39;
}
F_10 ( & V_14 -> V_19 , L_11 , V_20 , __LINE__ ,
( unsigned long ) V_9 -> V_35 ) ;
F_10 ( & V_14 -> V_19 , L_12 , V_20 , __LINE__ ,
( unsigned long ) V_9 -> V_36 ) ;
F_10 ( & V_14 -> V_19 , L_13 , V_20 , __LINE__ ,
( unsigned long ) V_9 -> V_7 ) ;
F_10 ( & V_14 -> V_19 , L_14 , V_20 , __LINE__ ,
( unsigned long ) V_15 ) ;
F_19 ( V_14 , V_9 ) ;
V_10 = F_20 ( V_9 , V_15 , 0 ) ;
if ( V_10 ) {
F_10 ( & V_14 -> V_19 , L_15 ,
V_20 , __LINE__ , V_10 ) ;
goto V_40;
}
F_21 ( V_9 -> V_41 . V_42 ) ;
return V_10 ;
V_40:
F_22 ( V_9 -> V_7 ) ;
V_39:
F_23 ( V_9 -> V_35 , V_9 -> V_36 ) ;
F_24 ( V_9 ) ;
V_34:
F_25 ( V_15 ) ;
V_30:
F_26 ( V_14 -> V_24 ) ;
V_26:
F_27 ( V_14 -> V_22 ) ;
V_23:
F_28 ( V_14 ) ;
V_21:
V_18:
return V_10 ;
}
static int F_29 ( struct V_13 * V_14 )
{
unsigned int V_43 ;
struct V_8 * V_9 = F_30 ( V_14 ) ;
F_12 ( ! V_9 ) ;
F_10 ( & V_14 -> V_19 , L_16 , V_20 , __LINE__ , V_9 -> V_7 ) ;
F_10 ( & V_14 -> V_19 , L_17 , V_20 , __LINE__ , V_9 -> V_44 ) ;
V_43 = V_9 -> V_44 ;
F_31 ( V_9 ) ;
F_19 ( V_14 , NULL ) ;
F_12 ( ! V_9 -> V_7 ) ;
F_22 ( V_9 -> V_7 ) ;
F_23 ( V_9 -> V_35 , V_9 -> V_36 ) ;
F_24 ( V_9 ) ;
F_25 ( V_43 ) ;
F_26 ( V_14 -> V_24 ) ;
F_27 ( V_14 -> V_22 ) ;
F_28 ( V_14 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_45 * V_46 )
{
return F_33 ( V_47 )
? F_34 ( V_46 )
: 0 ;
}
static void F_35 ( struct V_45 * V_46 )
{
if ( F_33 ( V_47 ) )
F_36 ( V_46 ) ;
}
