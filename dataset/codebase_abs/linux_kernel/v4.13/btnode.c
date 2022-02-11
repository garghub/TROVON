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
memset ( V_6 -> V_8 , 0 , F_14 ( V_5 ) ) ;
V_6 -> V_9 = V_5 -> V_10 -> V_11 ;
V_6 -> V_12 = V_4 ;
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
F_17 ( V_6 -> V_13 ) ;
F_18 ( V_6 -> V_13 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 V_14 , int V_15 , int V_16 ,
struct V_3 * * V_17 , T_2 * V_18 )
{
struct V_3 * V_6 ;
struct V_5 * V_5 = F_5 ( V_2 ) ;
struct V_19 * V_19 ;
int V_20 ;
V_6 = F_6 ( V_5 , V_2 , V_4 , F_7 ( V_7 ) ) ;
if ( F_8 ( ! V_6 ) )
return - V_21 ;
V_20 = - V_22 ;
V_19 = V_6 -> V_13 ;
if ( F_10 ( V_6 ) || F_11 ( V_6 ) )
goto V_23;
if ( V_14 == 0 ) {
V_14 = V_4 ;
if ( V_5 -> V_24 != V_25 ) {
struct V_26 * V_27 = V_5 -> V_10 -> V_28 ;
V_20 = F_20 ( V_27 -> V_29 , V_4 ,
& V_14 ) ;
if ( F_8 ( V_20 ) ) {
F_12 ( V_6 ) ;
goto V_30;
}
}
}
if ( V_16 & V_31 ) {
if ( V_14 != * V_18 + 1 || ! F_21 ( V_6 ) ) {
V_20 = - V_32 ;
F_12 ( V_6 ) ;
goto V_30;
}
} else {
F_22 ( V_6 ) ;
}
if ( F_10 ( V_6 ) ) {
F_23 ( V_6 ) ;
V_20 = - V_22 ;
goto V_23;
}
F_15 ( V_6 ) ;
V_6 -> V_9 = V_5 -> V_10 -> V_11 ;
V_6 -> V_12 = V_14 ;
V_6 -> V_33 = V_34 ;
F_24 ( V_6 ) ;
F_25 ( V_15 , V_16 , V_6 ) ;
V_6 -> V_12 = V_4 ;
* V_18 = V_14 ;
V_20 = 0 ;
V_23:
* V_17 = V_6 ;
V_30:
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
return V_20 ;
}
void F_26 ( struct V_3 * V_6 )
{
struct V_1 * V_35 ;
struct V_19 * V_19 = V_6 -> V_13 ;
T_3 V_36 = F_27 ( V_19 ) ;
int V_37 ;
F_28 ( V_19 ) ;
F_29 ( V_19 ) ;
F_30 ( V_19 ) ;
F_31 ( V_6 ) ;
V_37 = F_32 ( V_19 ) ;
V_35 = V_19 -> V_35 ;
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
if ( ! V_37 && V_35 )
F_33 ( V_35 , V_36 , V_36 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_3 * V_40 , * V_41 ;
struct V_5 * V_5 = F_5 ( V_2 ) ;
T_1 V_42 = V_39 -> V_42 , V_43 = V_39 -> V_43 ;
int V_20 ;
if ( V_42 == V_43 )
return 0 ;
V_40 = V_39 -> V_6 ;
V_39 -> V_44 = NULL ;
if ( V_5 -> V_45 == V_46 ) {
F_29 ( V_40 -> V_13 ) ;
V_47:
V_20 = F_35 ( V_48 & ~ V_49 ) ;
if ( V_20 )
goto V_50;
if ( F_8 ( V_42 != V_40 -> V_13 -> V_36 ) )
F_36 ( V_40 -> V_13 ,
L_1 ,
( unsigned long long ) V_42 ,
( unsigned long long ) V_43 ) ;
F_37 ( & V_2 -> V_51 ) ;
V_20 = F_38 ( & V_2 -> V_52 , V_43 , V_40 -> V_13 ) ;
F_39 ( & V_2 -> V_51 ) ;
F_40 () ;
if ( ! V_20 )
return 0 ;
else if ( V_20 != - V_22 )
goto V_50;
V_20 = F_33 ( V_2 , V_43 , V_43 ) ;
if ( ! V_20 )
goto V_47;
F_17 ( V_40 -> V_13 ) ;
}
V_41 = F_4 ( V_2 , V_43 ) ;
if ( ! V_41 )
return - V_21 ;
F_41 ( V_41 == V_40 ) ;
V_39 -> V_44 = V_41 ;
return 0 ;
V_50:
F_17 ( V_40 -> V_13 ) ;
return V_20 ;
}
void F_42 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_3 * V_40 = V_39 -> V_6 , * V_41 = V_39 -> V_44 ;
T_1 V_42 = V_39 -> V_42 , V_43 = V_39 -> V_43 ;
struct V_19 * V_53 ;
if ( V_42 == V_43 )
return;
if ( V_41 == NULL ) {
V_53 = V_40 -> V_13 ;
if ( F_8 ( V_42 != V_53 -> V_36 ) )
F_36 ( V_53 ,
L_1 ,
( unsigned long long ) V_42 ,
( unsigned long long ) V_43 ) ;
F_43 ( V_40 ) ;
F_37 ( & V_2 -> V_51 ) ;
F_44 ( & V_2 -> V_52 , V_42 ) ;
F_45 ( & V_2 -> V_52 , V_43 ,
V_54 ) ;
F_39 ( & V_2 -> V_51 ) ;
V_53 -> V_36 = V_40 -> V_12 = V_43 ;
F_17 ( V_53 ) ;
} else {
F_46 ( V_41 , V_40 ) ;
F_43 ( V_41 ) ;
V_41 -> V_12 = V_43 ;
V_39 -> V_6 = V_41 ;
F_26 ( V_40 ) ;
}
}
void F_47 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_3 * V_41 = V_39 -> V_44 ;
T_1 V_42 = V_39 -> V_42 , V_43 = V_39 -> V_43 ;
if ( V_42 == V_43 )
return;
if ( V_41 == NULL ) {
F_37 ( & V_2 -> V_51 ) ;
F_44 ( & V_2 -> V_52 , V_43 ) ;
F_39 ( & V_2 -> V_51 ) ;
F_17 ( V_39 -> V_6 -> V_13 ) ;
} else
F_12 ( V_41 ) ;
}
