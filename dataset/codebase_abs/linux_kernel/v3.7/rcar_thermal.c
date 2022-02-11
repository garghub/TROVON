static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_3 ) ;
F_4 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 , T_1 V_9 )
{
unsigned long V_4 ;
T_1 V_10 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
V_10 = F_3 ( V_2 -> V_7 + V_3 ) ;
V_10 &= ~ V_8 ;
V_10 |= ( V_9 & V_8 ) ;
F_6 ( V_10 , V_2 -> V_7 + V_3 ) ;
F_4 ( & V_2 -> V_6 , V_4 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
unsigned long * V_13 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
int V_10 , V_15 , V_16 , V_17 ;
V_17 = - 200 ;
while ( 1 ) {
if ( V_2 -> V_18 < 1 || V_2 -> V_18 > 12 ) {
F_8 ( V_2 -> V_19 ,
L_1 , V_2 -> V_18 ) ;
V_2 -> V_18 = 4 ;
return - V_20 ;
}
V_15 = ( V_2 -> V_18 * 15 ) - 60 ;
V_16 = V_15 + 15 ;
F_5 ( V_2 , V_21 , V_22 , V_2 -> V_18 ) ;
F_9 ( 300 ) ;
V_10 = F_1 ( V_2 , V_23 ) & V_24 ;
V_10 = ( V_10 * 5 ) - 65 ;
F_10 ( V_2 -> V_19 , L_2 ,
V_2 -> V_18 , V_15 , V_16 , V_10 ) ;
if ( V_17 == V_10 )
break;
if ( V_10 <= V_15 ) {
V_17 = V_15 ;
V_2 -> V_18 -- ;
} else if ( V_10 >= V_16 ) {
V_17 = V_16 ;
V_2 -> V_18 ++ ;
} else {
V_17 = V_10 ;
break;
}
}
* V_13 = V_17 ;
return 0 ;
}
static int F_11 ( struct V_25 * V_26 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_5 ;
V_28 = F_12 ( V_26 , V_29 , 0 ) ;
if ( ! V_28 ) {
F_8 ( & V_26 -> V_19 , L_3 ) ;
return - V_30 ;
}
V_2 = F_13 ( & V_26 -> V_19 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_8 ( & V_26 -> V_19 , L_4 ) ;
return - V_32 ;
}
V_2 -> V_18 = 4 ;
V_2 -> V_19 = & V_26 -> V_19 ;
F_14 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = F_15 ( & V_26 -> V_19 ,
V_28 -> V_33 , F_16 ( V_28 ) ) ;
if ( ! V_2 -> V_7 ) {
F_8 ( & V_26 -> V_19 , L_5 ) ;
V_5 = - V_32 ;
goto V_34;
}
V_12 = F_17 ( L_6 , 0 , 0 , V_2 ,
& V_35 , 0 , 0 ) ;
if ( F_18 ( V_12 ) ) {
F_8 ( & V_26 -> V_19 , L_7 ) ;
V_5 = F_19 ( V_12 ) ;
goto V_36;
}
F_20 ( V_26 , V_12 ) ;
F_21 ( & V_26 -> V_19 , L_8 ) ;
return 0 ;
V_36:
F_22 ( & V_26 -> V_19 , V_2 -> V_7 ) ;
V_34:
F_23 ( & V_26 -> V_19 , V_2 ) ;
return V_5 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_25 ( V_26 ) ;
struct V_1 * V_2 = V_12 -> V_14 ;
F_26 ( V_12 ) ;
F_20 ( V_26 , NULL ) ;
F_22 ( & V_26 -> V_19 , V_2 -> V_7 ) ;
F_23 ( & V_26 -> V_19 , V_2 ) ;
return 0 ;
}
