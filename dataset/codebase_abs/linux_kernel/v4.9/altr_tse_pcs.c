static int F_1 ( void T_1 * V_1 , struct V_2 * V_3 )
{
int V_4 = 0 ;
T_2 V_5 ;
V_5 = F_2 ( V_1 + V_6 ) ;
V_5 |= V_7 ;
F_3 ( V_5 , V_1 + V_6 ) ;
while ( V_4 < V_8 ) {
V_5 = F_2 ( V_1 + V_6 ) ;
V_5 &= V_7 ;
if ( V_5 == 0 )
break;
V_4 ++ ;
F_4 ( 1 ) ;
}
if ( V_4 >= V_8 ) {
F_5 ( V_3 -> V_9 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
int F_6 ( void T_1 * V_1 , struct V_2 * V_3 )
{
int V_11 = 0 ;
F_3 ( V_12 , V_1 + V_13 ) ;
F_3 ( V_14 , V_1 + V_15 ) ;
F_3 ( V_16 , V_1 + V_17 ) ;
V_11 = F_1 ( V_1 , V_3 ) ;
if ( V_11 == 0 )
F_3 ( V_18 ,
V_3 -> V_19 + V_20 ) ;
return V_11 ;
}
static void F_7 ( unsigned long V_21 )
{
T_2 V_5 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_21 ;
void T_1 * V_22 = V_3 -> V_22 ;
void T_1 * V_19 = V_3 -> V_19 ;
V_5 = F_2 ( V_22 + V_23 ) ;
V_5 &= V_24 ;
if ( V_5 != 0 ) {
F_8 ( V_3 -> V_9 , L_2 ) ;
F_3 ( V_18 ,
V_19 + V_20 ) ;
} else {
F_9 ( & V_3 -> V_25 , V_26 +
F_10 ( V_27 ) ) ;
}
}
static void F_11 ( unsigned long V_21 )
{
T_2 V_5 = 0 ;
T_2 V_28 = 0 ;
T_2 V_29 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_21 ;
void T_1 * V_22 = V_3 -> V_22 ;
void T_1 * V_19 = V_3 -> V_19 ;
V_5 = F_2 ( V_22 + V_23 ) ;
V_5 &= V_30 ;
if ( V_5 != 0 ) {
F_8 ( V_3 -> V_9 , L_3 ) ;
V_5 = F_2 ( V_22 + V_31 ) ;
V_28 = V_5 & V_32 ;
V_29 = V_5 & V_33 ;
if ( V_28 == V_34 &&
V_29 == V_35 )
F_8 ( V_3 -> V_9 ,
L_4 ) ;
else if ( V_28 == V_36 &&
V_29 == V_35 )
F_8 ( V_3 -> V_9 ,
L_5 ) ;
else if ( V_28 == V_37 &&
V_29 == V_35 )
F_8 ( V_3 -> V_9 ,
L_6 ) ;
else if ( V_28 == V_34 &&
V_29 == V_38 )
F_5 ( V_3 -> V_9 ,
L_7 ) ;
else if ( V_28 == V_36 &&
V_29 == V_38 )
F_5 ( V_3 -> V_9 ,
L_7 ) ;
else if ( V_28 == V_37 &&
V_29 == V_38 )
F_5 ( V_3 -> V_9 ,
L_7 ) ;
else
F_5 ( V_3 -> V_9 ,
L_8 ) ;
if ( V_29 == V_35 &&
( V_28 == V_34 ||
V_28 == V_36 ||
V_28 == V_37 ) )
F_3 ( V_18 ,
V_19 + V_20 ) ;
} else {
V_5 = F_2 ( V_22 + V_6 ) ;
V_5 |= V_39 ;
F_3 ( V_5 , V_22 + V_6 ) ;
F_1 ( V_22 , V_3 ) ;
F_9 ( & V_3 -> V_25 , V_26 +
F_10 ( V_27 ) ) ;
}
}
static void F_12 ( unsigned long V_21 )
{
struct V_2 * V_3 = (struct V_2 * ) V_21 ;
if ( V_3 -> V_40 == V_41 )
F_11 ( V_21 ) ;
else if ( V_3 -> V_40 == V_42 )
F_7 ( V_21 ) ;
}
void F_13 ( struct V_2 * V_3 , struct V_43 * V_44 ,
unsigned int V_28 )
{
void T_1 * V_22 = V_3 -> V_22 ;
void T_1 * V_19 = V_3 -> V_19 ;
T_3 V_5 ;
F_3 ( V_18 ,
V_19 + V_20 ) ;
V_3 -> V_40 = V_44 -> V_40 ;
if ( V_44 -> V_40 == V_41 ) {
V_5 = F_2 ( V_22 + V_6 ) ;
V_5 |= V_45 ;
F_3 ( V_5 , V_22 + V_6 ) ;
V_5 = F_2 ( V_22 + V_13 ) ;
V_5 |= V_46 ;
F_3 ( V_5 , V_22 + V_13 ) ;
V_5 = F_2 ( V_22 + V_6 ) ;
V_5 |= V_39 ;
F_1 ( V_22 , V_3 ) ;
F_14 ( & V_3 -> V_25 ,
F_12 , ( unsigned long ) V_3 ) ;
F_9 ( & V_3 -> V_25 , V_26 +
F_10 ( V_27 ) ) ;
} else if ( V_44 -> V_40 == V_42 ) {
V_5 = F_2 ( V_22 + V_6 ) ;
V_5 &= ~ V_45 ;
F_3 ( V_5 , V_22 + V_6 ) ;
V_5 = F_2 ( V_22 + V_13 ) ;
V_5 &= ~ V_46 ;
F_3 ( V_5 , V_22 + V_13 ) ;
V_5 = F_2 ( V_22 + V_13 ) ;
V_5 &= ~ V_47 ;
switch ( V_28 ) {
case 1000 :
V_5 |= V_48 ;
break;
case 100 :
V_5 |= V_49 ;
break;
case 10 :
V_5 |= V_50 ;
break;
default:
return;
}
F_3 ( V_5 , V_22 + V_13 ) ;
F_1 ( V_22 , V_3 ) ;
F_14 ( & V_3 -> V_25 ,
F_12 , ( unsigned long ) V_3 ) ;
F_9 ( & V_3 -> V_25 , V_26 +
F_10 ( V_27 ) ) ;
}
}
