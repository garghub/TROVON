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
F_3 ( V_14 , V_1 + V_6 ) ;
F_3 ( V_15 , V_1 + V_16 ) ;
F_3 ( V_17 , V_1 + V_18 ) ;
V_11 = F_1 ( V_1 , V_3 ) ;
if ( V_11 == 0 )
F_3 ( V_19 ,
V_3 -> V_20 + V_21 ) ;
return V_11 ;
}
static void F_7 ( unsigned long V_22 )
{
T_2 V_5 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_22 ;
void T_1 * V_23 = V_3 -> V_23 ;
void T_1 * V_20 = V_3 -> V_20 ;
V_5 = F_2 ( V_23 + V_24 ) ;
V_5 &= V_25 ;
if ( V_5 != 0 ) {
F_8 ( V_3 -> V_9 , L_2 ) ;
F_3 ( V_19 ,
V_20 + V_21 ) ;
} else {
F_9 ( & V_3 -> V_26 , V_27 +
F_10 ( V_28 ) ) ;
}
}
static void F_11 ( unsigned long V_22 )
{
T_2 V_5 = 0 ;
T_2 V_29 = 0 ;
T_2 V_30 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_22 ;
void T_1 * V_23 = V_3 -> V_23 ;
void T_1 * V_20 = V_3 -> V_20 ;
V_5 = F_2 ( V_23 + V_24 ) ;
V_5 &= V_31 ;
if ( V_5 != 0 ) {
F_8 ( V_3 -> V_9 , L_3 ) ;
V_5 = F_2 ( V_23 + V_32 ) ;
V_29 = V_5 & V_33 ;
V_30 = V_5 & V_34 ;
if ( V_29 == V_35 &&
V_30 == V_36 )
F_8 ( V_3 -> V_9 ,
L_4 ) ;
else if ( V_29 == V_37 &&
V_30 == V_36 )
F_8 ( V_3 -> V_9 ,
L_5 ) ;
else if ( V_29 == V_38 &&
V_30 == V_36 )
F_8 ( V_3 -> V_9 ,
L_6 ) ;
else if ( V_29 == V_35 &&
V_30 == V_39 )
F_5 ( V_3 -> V_9 ,
L_7 ) ;
else if ( V_29 == V_37 &&
V_30 == V_39 )
F_5 ( V_3 -> V_9 ,
L_7 ) ;
else if ( V_29 == V_38 &&
V_30 == V_39 )
F_5 ( V_3 -> V_9 ,
L_7 ) ;
else
F_5 ( V_3 -> V_9 ,
L_8 ) ;
if ( V_30 == V_36 &&
( V_29 == V_35 ||
V_29 == V_37 ||
V_29 == V_38 ) )
F_3 ( V_19 ,
V_20 + V_21 ) ;
} else {
V_5 = F_2 ( V_23 + V_6 ) ;
V_5 |= V_40 ;
F_3 ( V_5 , V_23 + V_6 ) ;
F_1 ( V_23 , V_3 ) ;
F_9 ( & V_3 -> V_26 , V_27 +
F_10 ( V_28 ) ) ;
}
}
static void F_12 ( unsigned long V_22 )
{
struct V_2 * V_3 = (struct V_2 * ) V_22 ;
if ( V_3 -> V_41 == V_42 )
F_11 ( V_22 ) ;
else if ( V_3 -> V_41 == V_43 )
F_7 ( V_22 ) ;
}
void F_13 ( struct V_2 * V_3 , struct V_44 * V_45 ,
unsigned int V_29 )
{
void T_1 * V_23 = V_3 -> V_23 ;
void T_1 * V_20 = V_3 -> V_20 ;
T_3 V_5 ;
F_3 ( V_19 ,
V_20 + V_21 ) ;
V_3 -> V_41 = V_45 -> V_41 ;
if ( V_45 -> V_41 == V_42 ) {
V_5 = F_2 ( V_23 + V_6 ) ;
V_5 |= V_46 ;
F_3 ( V_5 , V_23 + V_6 ) ;
V_5 = F_2 ( V_23 + V_13 ) ;
V_5 |= V_47 ;
F_3 ( V_5 , V_23 + V_13 ) ;
V_5 = F_2 ( V_23 + V_6 ) ;
V_5 |= V_40 ;
F_1 ( V_23 , V_3 ) ;
F_14 ( & V_3 -> V_26 ,
F_12 , ( unsigned long ) V_3 ) ;
F_9 ( & V_3 -> V_26 , V_27 +
F_10 ( V_28 ) ) ;
} else if ( V_45 -> V_41 == V_43 ) {
V_5 = F_2 ( V_23 + V_6 ) ;
V_5 &= ~ V_46 ;
F_3 ( V_5 , V_23 + V_6 ) ;
V_5 = F_2 ( V_23 + V_13 ) ;
V_5 &= ~ V_47 ;
F_3 ( V_5 , V_23 + V_13 ) ;
V_5 = F_2 ( V_23 + V_13 ) ;
V_5 &= ~ V_48 ;
switch ( V_29 ) {
case 1000 :
V_5 |= V_49 ;
break;
case 100 :
V_5 |= V_50 ;
break;
case 10 :
V_5 |= V_51 ;
break;
default:
return;
}
F_3 ( V_5 , V_23 + V_13 ) ;
F_1 ( V_23 , V_3 ) ;
F_14 ( & V_3 -> V_26 ,
F_12 , ( unsigned long ) V_3 ) ;
F_9 ( & V_3 -> V_26 , V_27 +
F_10 ( V_28 ) ) ;
}
}
