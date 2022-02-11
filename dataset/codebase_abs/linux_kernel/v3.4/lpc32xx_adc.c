static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_7 == 0 ) {
F_3 ( & V_2 -> V_10 ) ;
F_4 ( V_9 -> V_11 ) ;
F_5 ( V_12 | ( V_4 -> V_13 ) | V_14 | V_15 ,
F_6 ( V_9 -> V_16 ) ) ;
F_5 ( V_17 | V_18 ,
F_7 ( V_9 -> V_16 ) ) ;
F_8 ( & V_9 -> V_19 ) ;
F_9 ( V_9 -> V_11 ) ;
* V_5 = V_9 -> V_20 ;
F_10 ( & V_2 -> V_10 ) ;
return V_21 ;
}
return - V_22 ;
}
static T_1 F_11 ( int V_23 , void * V_24 )
{
struct V_8 * V_9 = (struct V_8 * ) V_24 ;
V_9 -> V_20 = F_12 ( F_13 ( V_9 -> V_16 ) ) &
V_25 ;
F_14 ( & V_9 -> V_19 ) ;
return V_26 ;
}
static int T_2 F_15 ( struct V_27 * V_28 )
{
struct V_8 * V_9 = NULL ;
struct V_29 * V_30 ;
int V_31 = - V_32 ;
struct V_1 * V_33 = NULL ;
int V_23 ;
V_30 = F_16 ( V_28 , V_34 , 0 ) ;
if ( ! V_30 ) {
F_17 ( & V_28 -> V_35 , L_1 ) ;
V_31 = - V_36 ;
goto V_37;
}
V_33 = F_18 ( sizeof( struct V_8 ) ) ;
if ( ! V_33 ) {
F_17 ( & V_28 -> V_35 , L_2 ) ;
V_31 = - V_38 ;
goto V_37;
}
V_9 = F_2 ( V_33 ) ;
V_9 -> V_16 = F_19 ( V_30 -> V_39 , V_30 -> V_40 - V_30 -> V_39 + 1 ) ;
if ( ! V_9 -> V_16 ) {
F_17 ( & V_28 -> V_35 , L_3 ) ;
V_31 = - V_36 ;
goto V_41;
}
V_9 -> V_11 = F_20 ( & V_28 -> V_35 , NULL ) ;
if ( F_21 ( V_9 -> V_11 ) ) {
F_17 ( & V_28 -> V_35 , L_4 ) ;
goto V_42;
}
V_23 = F_22 ( V_28 , 0 ) ;
if ( ( V_23 < 0 ) || ( V_23 >= V_43 ) ) {
F_17 ( & V_28 -> V_35 , L_5 ) ;
V_31 = - V_22 ;
goto V_44;
}
V_31 = F_23 ( V_23 , F_11 , 0 , V_45 , V_9 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_28 -> V_35 , L_6 ) ;
goto V_44;
}
F_24 ( V_28 , V_33 ) ;
F_25 ( & V_9 -> V_19 ) ;
V_33 -> V_46 = V_45 ;
V_33 -> V_35 . V_47 = & V_28 -> V_35 ;
V_33 -> V_9 = & V_48 ;
V_33 -> V_49 = V_50 ;
V_33 -> V_51 = V_52 ;
V_33 -> V_53 = F_26 ( V_52 ) ;
V_31 = F_27 ( V_33 ) ;
if ( V_31 )
goto V_54;
F_28 ( & V_28 -> V_35 , L_7 , V_23 ) ;
return 0 ;
V_54:
F_29 ( V_23 , V_33 ) ;
V_44:
F_30 ( V_9 -> V_11 ) ;
V_42:
F_31 ( V_9 -> V_16 ) ;
V_41:
F_32 ( V_33 ) ;
V_37:
return V_31 ;
}
static int T_3 F_33 ( struct V_27 * V_28 )
{
struct V_1 * V_33 = F_34 ( V_28 ) ;
struct V_8 * V_9 = F_2 ( V_33 ) ;
int V_23 = F_22 ( V_28 , 0 ) ;
F_35 ( V_33 ) ;
F_29 ( V_23 , V_33 ) ;
F_24 ( V_28 , NULL ) ;
F_30 ( V_9 -> V_11 ) ;
F_31 ( V_9 -> V_16 ) ;
F_32 ( V_33 ) ;
return 0 ;
}
