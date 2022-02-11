static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_7 == V_10 ) {
F_3 ( & V_2 -> V_11 ) ;
F_4 ( V_9 -> V_12 ) ;
F_5 ( V_13 | ( V_4 -> V_14 ) | V_15 | V_16 ,
F_6 ( V_9 -> V_17 ) ) ;
F_5 ( V_18 | V_19 ,
F_7 ( V_9 -> V_17 ) ) ;
F_8 ( & V_9 -> V_20 ) ;
F_9 ( V_9 -> V_12 ) ;
* V_5 = V_9 -> V_21 ;
F_10 ( & V_2 -> V_11 ) ;
return V_22 ;
}
return - V_23 ;
}
static T_1 F_11 ( int V_24 , void * V_25 )
{
struct V_8 * V_9 = (struct V_8 * ) V_25 ;
V_9 -> V_21 = F_12 ( F_13 ( V_9 -> V_17 ) ) &
V_26 ;
F_14 ( & V_9 -> V_20 ) ;
return V_27 ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = NULL ;
struct V_30 * V_31 ;
int V_32 = - V_33 ;
struct V_1 * V_34 = NULL ;
int V_24 ;
V_31 = F_16 ( V_29 , V_35 , 0 ) ;
if ( ! V_31 ) {
F_17 ( & V_29 -> V_36 , L_1 ) ;
V_32 = - V_37 ;
goto V_38;
}
V_34 = F_18 ( sizeof( struct V_8 ) ) ;
if ( ! V_34 ) {
F_17 ( & V_29 -> V_36 , L_2 ) ;
V_32 = - V_39 ;
goto V_38;
}
V_9 = F_2 ( V_34 ) ;
V_9 -> V_17 = F_19 ( V_31 -> V_40 , F_20 ( V_31 ) ) ;
if ( ! V_9 -> V_17 ) {
F_17 ( & V_29 -> V_36 , L_3 ) ;
V_32 = - V_37 ;
goto V_41;
}
V_9 -> V_12 = F_21 ( & V_29 -> V_36 , NULL ) ;
if ( F_22 ( V_9 -> V_12 ) ) {
F_17 ( & V_29 -> V_36 , L_4 ) ;
goto V_42;
}
V_24 = F_23 ( V_29 , 0 ) ;
if ( ( V_24 < 0 ) || ( V_24 >= V_43 ) ) {
F_17 ( & V_29 -> V_36 , L_5 ) ;
V_32 = - V_23 ;
goto V_44;
}
V_32 = F_24 ( V_24 , F_11 , 0 , V_45 , V_9 ) ;
if ( V_32 < 0 ) {
F_17 ( & V_29 -> V_36 , L_6 ) ;
goto V_44;
}
F_25 ( V_29 , V_34 ) ;
F_26 ( & V_9 -> V_20 ) ;
V_34 -> V_46 = V_45 ;
V_34 -> V_36 . V_47 = & V_29 -> V_36 ;
V_34 -> V_9 = & V_48 ;
V_34 -> V_49 = V_50 ;
V_34 -> V_51 = V_52 ;
V_34 -> V_53 = F_27 ( V_52 ) ;
V_32 = F_28 ( V_34 ) ;
if ( V_32 )
goto V_54;
F_29 ( & V_29 -> V_36 , L_7 , V_24 ) ;
return 0 ;
V_54:
F_30 ( V_24 , V_9 ) ;
V_44:
F_31 ( V_9 -> V_12 ) ;
V_42:
F_32 ( V_9 -> V_17 ) ;
V_41:
F_33 ( V_34 ) ;
V_38:
return V_32 ;
}
static int F_34 ( struct V_28 * V_29 )
{
struct V_1 * V_34 = F_35 ( V_29 ) ;
struct V_8 * V_9 = F_2 ( V_34 ) ;
int V_24 = F_23 ( V_29 , 0 ) ;
F_36 ( V_34 ) ;
F_30 ( V_24 , V_9 ) ;
F_25 ( V_29 , NULL ) ;
F_31 ( V_9 -> V_12 ) ;
F_32 ( V_9 -> V_17 ) ;
F_33 ( V_34 ) ;
return 0 ;
}
