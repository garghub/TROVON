static int F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
bool V_7 = false ;
V_5 = F_2 ( sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_11 = - V_12 ;
F_4 ( & V_1 -> V_13 ) ;
F_5 ( & V_5 -> V_14 , & V_1 -> V_15 ) ;
V_7 = ! V_1 -> V_16 ;
if ( V_7 ) {
V_6 = F_6 ( V_1 , V_17 ,
V_18 , V_18 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_19 , L_1 ,
V_6 ) ;
goto V_20;
}
}
if ( ! ( V_1 -> V_16 & ( 1 << V_3 ) ) ) {
V_6 = F_6 ( V_1 , V_21 ,
1 << V_3 , 1 << V_3 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_19 ,
L_2 , V_6 ) ;
goto V_20;
}
V_1 -> V_16 |= 1 << V_3 ;
}
if ( V_7 ) {
V_6 = F_6 ( V_1 , V_17 ,
V_22 |
V_23 ,
V_22 |
V_23 ) ;
if ( V_6 != 0 ) {
F_7 ( V_1 -> V_19 , L_3 ,
V_6 ) ;
goto V_20;
}
}
F_8 ( & V_1 -> V_13 ) ;
F_9 ( & V_5 -> V_10 , F_10 ( 500 ) ) ;
F_4 ( & V_1 -> V_13 ) ;
F_11 ( & V_5 -> V_14 ) ;
V_6 = V_5 -> V_11 ;
V_20:
F_8 ( & V_1 -> V_13 ) ;
F_12 ( V_5 ) ;
return V_6 ;
}
static T_1 F_13 ( int V_24 , void * V_25 )
{
struct V_1 * V_1 = V_25 ;
struct V_4 * V_5 ;
int V_6 , V_3 , V_11 ;
V_6 = F_14 ( V_1 , V_26 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 ,
L_4 , V_6 ) ;
return V_27 ;
}
V_3 = ( ( V_6 & V_28 )
>> V_29 ) - 1 ;
if ( V_3 == 14 )
V_3 = V_30 ;
V_11 = V_6 & V_31 ;
F_4 ( & V_1 -> V_13 ) ;
F_6 ( V_1 , V_21 ,
1 << V_3 , 0 ) ;
V_1 -> V_16 &= ~ ( 1 << V_3 ) ;
if ( ! V_1 -> V_16 )
F_15 ( V_1 , V_17 , 0 ) ;
F_16 (req, &wm831x->auxadc_pending, list) {
if ( V_5 -> V_3 == V_3 ) {
V_5 -> V_11 = V_11 ;
F_17 ( & V_5 -> V_10 ) ;
}
}
F_8 ( & V_1 -> V_13 ) ;
return V_32 ;
}
static int F_18 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
int V_6 , V_33 , V_34 ;
F_4 ( & V_1 -> V_13 ) ;
V_6 = F_6 ( V_1 , V_17 ,
V_18 , V_18 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 , L_1 , V_6 ) ;
goto V_20;
}
V_33 = V_3 ;
V_6 = F_15 ( V_1 , V_21 ,
1 << V_33 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 , L_2 , V_6 ) ;
goto V_20;
}
V_6 = F_6 ( V_1 , V_17 ,
V_22 , V_22 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 , L_3 , V_6 ) ;
goto V_35;
}
V_34 = 5 ;
while ( V_34 ) {
F_19 ( 1 ) ;
V_6 = F_14 ( V_1 ,
V_36 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 ,
L_5 , V_6 ) ;
goto V_35;
}
if ( V_6 & V_37 ) {
F_15 ( V_1 ,
V_36 ,
V_37 ) ;
break;
} else {
F_7 ( V_1 -> V_19 ,
L_6 ) ;
V_6 = - V_38 ;
goto V_35;
}
}
V_6 = F_14 ( V_1 , V_26 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 ,
L_4 , V_6 ) ;
goto V_35;
}
V_33 = ( ( V_6 & V_28 )
>> V_29 ) - 1 ;
if ( V_33 == 14 )
V_33 = V_30 ;
if ( V_33 != V_3 ) {
F_7 ( V_1 -> V_19 , L_7 ,
V_33 , V_3 ) ;
V_6 = - V_39 ;
} else {
V_6 &= V_31 ;
}
V_35:
F_6 ( V_1 , V_17 , V_18 , 0 ) ;
V_20:
F_8 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_20 ( struct V_1 * V_1 , enum V_2 V_3 )
{
return V_1 -> V_40 ( V_1 , V_3 ) ;
}
int F_21 ( struct V_1 * V_1 , enum V_2 V_3 )
{
int V_6 ;
V_6 = F_20 ( V_1 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 *= 1465 ;
return V_6 ;
}
void F_22 ( struct V_1 * V_1 )
{
int V_6 ;
F_23 ( & V_1 -> V_13 ) ;
F_24 ( & V_1 -> V_15 ) ;
if ( V_1 -> V_24 ) {
V_1 -> V_40 = F_1 ;
V_6 = F_25 ( F_26 ( V_1 ,
V_41 ) ,
NULL , F_13 ,
V_42 ,
L_8 , V_1 ) ;
if ( V_6 < 0 ) {
F_7 ( V_1 -> V_19 , L_9 ,
V_6 ) ;
V_1 -> V_40 = NULL ;
}
}
if ( ! V_1 -> V_40 )
V_1 -> V_40 = F_18 ;
}
