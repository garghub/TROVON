void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , - 1 ) ;
F_3 ( V_2 , 0 ) ;
}
struct V_3 *
F_4 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_5 * V_5 = F_5 ( V_2 ) ;
struct V_3 * V_6 ;
V_6 = F_6 ( V_5 , V_2 , V_4 , F_7 ( V_7 ) ) ;
if ( F_8 ( ! V_6 ) )
return NULL ;
if ( F_8 ( F_9 ( V_6 ) || F_10 ( V_6 ) ||
F_11 ( V_6 ) ) ) {
F_12 ( V_6 ) ;
F_13 () ;
}
memset ( V_6 -> V_8 , 0 , 1 << V_5 -> V_9 ) ;
V_6 -> V_10 = V_5 -> V_11 -> V_12 ;
V_6 -> V_13 = V_4 ;
F_14 ( V_6 ) ;
F_15 ( V_6 ) ;
F_16 ( V_6 -> V_14 ) ;
F_17 ( V_6 -> V_14 ) ;
return V_6 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 V_15 , int V_16 , int V_17 ,
struct V_3 * * V_18 , T_2 * V_19 )
{
struct V_3 * V_6 ;
struct V_5 * V_5 = F_5 ( V_2 ) ;
struct V_20 * V_20 ;
int V_21 ;
V_6 = F_6 ( V_5 , V_2 , V_4 , F_7 ( V_7 ) ) ;
if ( F_8 ( ! V_6 ) )
return - V_22 ;
V_21 = - V_23 ;
V_20 = V_6 -> V_14 ;
if ( F_10 ( V_6 ) || F_11 ( V_6 ) )
goto V_24;
if ( V_15 == 0 ) {
V_15 = V_4 ;
if ( V_5 -> V_25 != V_26 ) {
struct V_27 * V_28 = V_5 -> V_11 -> V_29 ;
V_21 = F_19 ( V_28 -> V_30 , V_4 ,
& V_15 ) ;
if ( F_8 ( V_21 ) ) {
F_12 ( V_6 ) ;
goto V_31;
}
}
}
if ( V_17 & V_32 ) {
if ( V_15 != * V_19 + 1 || ! F_20 ( V_6 ) ) {
V_21 = - V_33 ;
F_12 ( V_6 ) ;
goto V_31;
}
} else {
F_21 ( V_6 ) ;
}
if ( F_10 ( V_6 ) ) {
F_22 ( V_6 ) ;
V_21 = - V_23 ;
goto V_24;
}
F_14 ( V_6 ) ;
V_6 -> V_10 = V_5 -> V_11 -> V_12 ;
V_6 -> V_13 = V_15 ;
V_6 -> V_34 = V_35 ;
F_23 ( V_6 ) ;
F_24 ( V_16 , V_17 , V_6 ) ;
V_6 -> V_13 = V_4 ;
* V_19 = V_15 ;
V_21 = 0 ;
V_24:
* V_18 = V_6 ;
V_31:
F_16 ( V_20 ) ;
F_17 ( V_20 ) ;
return V_21 ;
}
void F_25 ( struct V_3 * V_6 )
{
struct V_1 * V_36 ;
struct V_20 * V_20 = V_6 -> V_14 ;
T_3 V_37 = F_26 ( V_20 ) ;
int V_38 ;
F_27 ( V_20 ) ;
F_28 ( V_20 ) ;
F_29 ( V_20 ) ;
F_30 ( V_6 ) ;
V_38 = F_31 ( V_20 ) ;
V_36 = V_20 -> V_36 ;
F_16 ( V_20 ) ;
F_17 ( V_20 ) ;
if ( ! V_38 && V_36 )
F_32 ( V_36 , V_37 , V_37 ) ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_3 * V_41 , * V_42 ;
struct V_5 * V_5 = F_5 ( V_2 ) ;
T_1 V_43 = V_40 -> V_43 , V_44 = V_40 -> V_44 ;
int V_21 ;
if ( V_43 == V_44 )
return 0 ;
V_41 = V_40 -> V_6 ;
V_40 -> V_45 = NULL ;
if ( V_5 -> V_9 == V_46 ) {
F_28 ( V_41 -> V_14 ) ;
V_47:
V_21 = F_34 ( V_48 & ~ V_49 ) ;
if ( V_21 )
goto V_50;
if ( F_8 ( V_43 != V_41 -> V_14 -> V_37 ) )
F_35 ( V_41 -> V_14 ,
L_1 ,
( unsigned long long ) V_43 ,
( unsigned long long ) V_44 ) ;
F_36 ( & V_2 -> V_51 ) ;
V_21 = F_37 ( & V_2 -> V_52 , V_44 , V_41 -> V_14 ) ;
F_38 ( & V_2 -> V_51 ) ;
F_39 () ;
if ( ! V_21 )
return 0 ;
else if ( V_21 != - V_23 )
goto V_50;
V_21 = F_32 ( V_2 , V_44 , V_44 ) ;
if ( ! V_21 )
goto V_47;
F_16 ( V_41 -> V_14 ) ;
}
V_42 = F_4 ( V_2 , V_44 ) ;
if ( ! V_42 )
return - V_22 ;
F_40 ( V_42 == V_41 ) ;
V_40 -> V_45 = V_42 ;
return 0 ;
V_50:
F_16 ( V_41 -> V_14 ) ;
return V_21 ;
}
void F_41 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_3 * V_41 = V_40 -> V_6 , * V_42 = V_40 -> V_45 ;
T_1 V_43 = V_40 -> V_43 , V_44 = V_40 -> V_44 ;
struct V_20 * V_53 ;
if ( V_43 == V_44 )
return;
if ( V_42 == NULL ) {
V_53 = V_41 -> V_14 ;
if ( F_8 ( V_43 != V_53 -> V_37 ) )
F_35 ( V_53 ,
L_1 ,
( unsigned long long ) V_43 ,
( unsigned long long ) V_44 ) ;
F_42 ( V_41 ) ;
F_36 ( & V_2 -> V_51 ) ;
F_43 ( & V_2 -> V_52 , V_43 ) ;
F_44 ( & V_2 -> V_52 , V_44 ,
V_54 ) ;
F_38 ( & V_2 -> V_51 ) ;
V_53 -> V_37 = V_41 -> V_13 = V_44 ;
F_16 ( V_53 ) ;
} else {
F_45 ( V_42 , V_41 ) ;
F_42 ( V_42 ) ;
V_42 -> V_13 = V_44 ;
V_40 -> V_6 = V_42 ;
F_25 ( V_41 ) ;
}
}
void F_46 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_3 * V_42 = V_40 -> V_45 ;
T_1 V_43 = V_40 -> V_43 , V_44 = V_40 -> V_44 ;
if ( V_43 == V_44 )
return;
if ( V_42 == NULL ) {
F_36 ( & V_2 -> V_51 ) ;
F_43 ( & V_2 -> V_52 , V_44 ) ;
F_38 ( & V_2 -> V_51 ) ;
F_16 ( V_40 -> V_6 -> V_14 ) ;
} else
F_12 ( V_42 ) ;
}
