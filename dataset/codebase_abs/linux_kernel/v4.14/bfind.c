int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
void * V_5 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = NULL ;
V_5 = F_2 ( V_2 -> V_7 * 2 + 4 , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
V_4 -> V_10 = V_5 ;
V_4 -> V_11 = V_5 + V_2 -> V_7 + 2 ;
F_3 ( V_12 , L_1 ,
V_2 -> V_13 , F_4 ( 0 ) ) ;
F_5 ( & V_2 -> V_14 ) ;
return 0 ;
}
void F_6 ( struct V_3 * V_4 )
{
F_7 ( V_4 -> V_6 ) ;
F_8 ( V_4 -> V_10 ) ;
F_3 ( V_12 , L_2 ,
V_4 -> V_2 -> V_13 , F_4 ( 0 ) ) ;
F_9 ( & V_4 -> V_2 -> V_14 ) ;
V_4 -> V_2 = NULL ;
}
int F_10 ( struct V_15 * V_6 , struct V_3 * V_4 )
{
int V_16 ;
T_1 V_17 , V_18 , V_19 ;
int V_20 ;
int V_21 , V_22 ;
int V_23 ;
V_21 = 0 ;
V_22 = V_6 -> V_24 - 1 ;
V_23 = - V_25 ;
do {
V_20 = ( V_22 + V_21 ) / 2 ;
V_18 = F_11 ( V_6 , V_20 , & V_17 ) ;
V_19 = F_12 ( V_6 , V_20 ) ;
if ( V_19 == 0 ) {
V_23 = - V_26 ;
goto V_27;
}
F_13 ( V_6 , V_4 -> V_11 , V_17 , V_19 ) ;
V_16 = V_6 -> V_2 -> V_28 ( V_4 -> V_11 , V_4 -> V_10 ) ;
if ( ! V_16 ) {
V_22 = V_20 ;
V_23 = 0 ;
goto V_29;
}
if ( V_16 < 0 )
V_21 = V_20 + 1 ;
else
V_22 = V_20 - 1 ;
} while ( V_21 <= V_22 );
if ( V_20 != V_22 && V_22 >= 0 ) {
V_18 = F_11 ( V_6 , V_22 , & V_17 ) ;
V_19 = F_12 ( V_6 , V_22 ) ;
if ( V_19 == 0 ) {
V_23 = - V_26 ;
goto V_27;
}
F_13 ( V_6 , V_4 -> V_11 , V_17 , V_19 ) ;
}
V_29:
V_4 -> V_30 = V_22 ;
V_4 -> V_31 = V_17 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = V_17 + V_19 ;
V_4 -> V_34 = V_18 - V_19 ;
V_27:
return V_23 ;
}
int F_14 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_6 ;
T_2 V_35 , V_36 ;
T_3 V_37 ;
int V_38 , V_23 ;
V_2 = V_4 -> V_2 ;
if ( V_4 -> V_6 )
F_7 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
V_35 = V_2 -> V_39 ;
if ( ! V_35 )
return - V_25 ;
V_38 = V_2 -> V_40 ;
V_23 = 0 ;
V_36 = 0 ;
for (; ; ) {
V_6 = F_15 ( V_2 , V_35 ) ;
if ( F_16 ( V_6 ) ) {
V_23 = F_17 ( V_6 ) ;
V_6 = NULL ;
break;
}
if ( V_6 -> V_38 != V_38 )
goto V_41;
if ( V_6 -> type != ( -- V_38 ? V_42 : V_43 ) )
goto V_41;
V_6 -> V_36 = V_36 ;
V_23 = F_10 ( V_6 , V_4 ) ;
if ( ! V_38 )
break;
if ( V_4 -> V_30 < 0 )
goto V_44;
V_36 = V_35 ;
F_13 ( V_6 , & V_37 , V_4 -> V_33 , 4 ) ;
V_35 = F_18 ( V_37 ) ;
F_7 ( V_6 ) ;
}
V_4 -> V_6 = V_6 ;
return V_23 ;
V_41:
F_19 ( L_3 ,
V_38 , V_6 -> V_38 , V_6 -> type , V_35 , V_36 ) ;
V_23 = - V_45 ;
V_44:
F_7 ( V_6 ) ;
return V_23 ;
}
int F_20 ( struct V_3 * V_4 , void * V_20 , int V_46 )
{
int V_23 ;
V_23 = F_14 ( V_4 ) ;
if ( V_23 )
return V_23 ;
if ( V_4 -> V_34 > V_46 )
return - V_26 ;
F_13 ( V_4 -> V_6 , V_20 , V_4 -> V_33 , V_4 -> V_34 ) ;
return 0 ;
}
int F_21 ( struct V_3 * V_4 , int V_47 )
{
struct V_1 * V_2 ;
struct V_15 * V_6 ;
int V_48 , V_23 = 0 ;
T_1 V_17 , V_18 , V_19 ;
V_6 = V_4 -> V_6 ;
V_2 = V_6 -> V_2 ;
if ( V_47 < 0 ) {
V_47 = - V_47 ;
while ( V_47 > V_4 -> V_30 ) {
V_47 -= V_4 -> V_30 + 1 ;
V_4 -> V_30 = V_6 -> V_24 - 1 ;
V_48 = V_6 -> V_49 ;
if ( ! V_48 ) {
V_23 = - V_25 ;
goto V_50;
}
F_7 ( V_6 ) ;
V_6 = F_15 ( V_2 , V_48 ) ;
if ( F_16 ( V_6 ) ) {
V_23 = F_17 ( V_6 ) ;
V_6 = NULL ;
goto V_50;
}
}
V_4 -> V_30 -= V_47 ;
} else {
while ( V_47 >= V_6 -> V_24 - V_4 -> V_30 ) {
V_47 -= V_6 -> V_24 - V_4 -> V_30 ;
V_4 -> V_30 = 0 ;
V_48 = V_6 -> V_51 ;
if ( ! V_48 ) {
V_23 = - V_25 ;
goto V_50;
}
F_7 ( V_6 ) ;
V_6 = F_15 ( V_2 , V_48 ) ;
if ( F_16 ( V_6 ) ) {
V_23 = F_17 ( V_6 ) ;
V_6 = NULL ;
goto V_50;
}
}
V_4 -> V_30 += V_47 ;
}
V_18 = F_11 ( V_6 , V_4 -> V_30 , & V_17 ) ;
V_19 = F_12 ( V_6 , V_4 -> V_30 ) ;
if ( V_19 == 0 ) {
V_23 = - V_26 ;
goto V_50;
}
V_4 -> V_31 = V_17 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = V_17 + V_19 ;
V_4 -> V_34 = V_18 - V_19 ;
F_13 ( V_6 , V_4 -> V_11 , V_17 , V_19 ) ;
V_50:
V_4 -> V_6 = V_6 ;
return V_23 ;
}
