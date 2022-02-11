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
struct V_1 * V_2 = F_8 ( V_12 ) ;
int V_10 , V_14 , V_15 , V_16 ;
V_16 = - 200 ;
while ( 1 ) {
if ( V_2 -> V_17 < 1 || V_2 -> V_17 > 12 ) {
F_9 ( V_2 -> V_18 ,
L_1 , V_2 -> V_17 ) ;
V_2 -> V_17 = 4 ;
return - V_19 ;
}
V_14 = ( V_2 -> V_17 * 15 ) - 60 ;
V_15 = V_14 + 15 ;
F_5 ( V_2 , V_20 , V_21 , V_2 -> V_17 ) ;
F_10 ( 300 ) ;
V_10 = F_1 ( V_2 , V_22 ) & V_23 ;
V_10 = ( V_10 * 5 ) - 65 ;
F_11 ( V_2 -> V_18 , L_2 ,
V_2 -> V_17 , V_14 , V_15 , V_10 ) ;
if ( V_16 == V_10 )
break;
if ( V_10 <= V_14 ) {
V_16 = V_14 ;
V_2 -> V_17 -- ;
} else if ( V_10 >= V_15 ) {
V_16 = V_15 ;
V_2 -> V_17 ++ ;
} else {
V_16 = V_10 ;
break;
}
}
* V_13 = F_12 ( V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
V_27 = F_14 ( V_25 , V_28 , 0 ) ;
if ( ! V_27 ) {
F_9 ( & V_25 -> V_18 , L_3 ) ;
return - V_29 ;
}
V_2 = F_15 ( & V_25 -> V_18 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 ) {
F_9 ( & V_25 -> V_18 , L_4 ) ;
return - V_31 ;
}
V_2 -> V_17 = 4 ;
V_2 -> V_18 = & V_25 -> V_18 ;
F_16 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = F_17 ( & V_25 -> V_18 ,
V_27 -> V_32 , F_18 ( V_27 ) ) ;
if ( ! V_2 -> V_7 ) {
F_9 ( & V_25 -> V_18 , L_5 ) ;
return - V_31 ;
}
V_12 = F_19 ( L_6 , 0 , 0 , V_2 ,
& V_33 , NULL , 0 , 0 ) ;
if ( F_20 ( V_12 ) ) {
F_9 ( & V_25 -> V_18 , L_7 ) ;
return F_21 ( V_12 ) ;
}
F_22 ( V_25 , V_12 ) ;
F_23 ( & V_25 -> V_18 , L_8 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_11 * V_12 = F_25 ( V_25 ) ;
F_26 ( V_12 ) ;
F_22 ( V_25 , NULL ) ;
return 0 ;
}
