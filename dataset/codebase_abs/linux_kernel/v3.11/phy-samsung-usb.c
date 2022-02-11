int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 -> V_6 , L_1 ) ;
if ( ! V_4 ) {
F_3 ( V_2 -> V_5 , L_2 ) ;
return - V_7 ;
}
V_2 -> V_8 = F_4 ( V_4 , 0 ) ;
if ( V_2 -> V_8 == NULL ) {
F_3 ( V_2 -> V_5 , L_3 ) ;
goto V_9;
}
V_2 -> V_10 = F_4 ( V_4 , 1 ) ;
if ( V_2 -> V_10 == NULL )
F_5 ( V_2 -> V_5 , L_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
V_9:
F_6 ( V_4 ) ;
return - V_11 ;
}
void F_7 ( struct V_1 * V_2 , bool V_12 )
{
void T_1 * V_13 = NULL ;
T_2 V_14 ;
T_2 V_15 = 0 ;
if ( ! V_2 -> V_8 ) {
F_5 ( V_2 -> V_5 , L_5 ) ;
return;
}
if ( V_2 -> V_16 == V_17 ) {
V_13 = V_2 -> V_8 + V_2 -> V_18 -> V_19 ;
V_15 = V_2 -> V_18 -> V_20 ;
} else if ( V_2 -> V_16 == V_21 ) {
V_13 = V_2 -> V_8 + V_2 -> V_18 -> V_22 ;
V_15 = V_2 -> V_18 -> V_23 ;
}
V_14 = F_8 ( V_13 ) ;
if ( V_12 )
V_14 &= ~ V_15 ;
else
V_14 |= V_15 ;
F_9 ( V_14 , V_13 ) ;
if ( V_2 -> V_18 -> V_24 == V_25 ) {
F_9 ( V_14 , V_2 -> V_8 + V_26 ) ;
F_9 ( V_14 , V_2 -> V_8 + V_27 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
T_2 V_13 ;
if ( ! V_2 -> V_10 ) {
F_5 ( V_2 -> V_5 , L_6 ) ;
return;
}
V_13 = F_8 ( V_2 -> V_10 ) ;
if ( V_2 -> V_16 == V_17 )
V_13 &= ~ V_28 ;
else if ( V_2 -> V_16 == V_21 )
V_13 |= V_28 ;
F_9 ( V_13 , V_2 -> V_10 ) ;
}
int F_11 ( struct V_29 * V_30 ,
enum V_31 V_16 )
{
struct V_1 * V_2 = F_12 ( V_30 ) ;
V_2 -> V_16 = V_16 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
unsigned int V_33 ;
switch ( V_32 ) {
case 12 * V_34 :
V_33 = V_35 ;
break;
case 24 * V_34 :
V_33 = V_36 ;
break;
case 48 * V_34 :
V_33 = V_37 ;
break;
default:
F_3 ( V_2 -> V_5 ,
L_7 , V_32 ) ;
return - V_38 ;
}
return V_33 ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
unsigned int V_33 ;
switch ( V_32 ) {
case 9600 * V_39 :
V_33 = V_40 ;
break;
case 10 * V_34 :
V_33 = V_41 ;
break;
case 12 * V_34 :
V_33 = V_42 ;
break;
case 19200 * V_39 :
V_33 = V_43 ;
break;
case 20 * V_34 :
V_33 = V_44 ;
break;
case 24 * V_34 :
V_33 = V_45 ;
break;
case 50 * V_34 :
V_33 = V_46 ;
break;
default:
F_3 ( V_2 -> V_5 ,
L_7 , V_32 ) ;
return - V_38 ;
}
return V_33 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
unsigned long V_32 ;
int V_49 ;
if ( V_2 -> V_18 -> V_24 == V_50 )
V_48 = F_16 ( V_2 -> V_5 , L_8 ) ;
else
V_48 = F_16 ( V_2 -> V_5 , L_9 ) ;
if ( F_17 ( V_48 ) ) {
F_3 ( V_2 -> V_5 , L_10 ) ;
return F_18 ( V_48 ) ;
}
V_32 = F_19 ( V_48 ) ;
V_49 = V_2 -> V_18 -> V_51 ( V_2 , V_32 ) ;
F_20 ( V_48 ) ;
return V_49 ;
}
