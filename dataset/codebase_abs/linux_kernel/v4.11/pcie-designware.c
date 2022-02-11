int F_1 ( void T_1 * V_1 , int V_2 , T_2 * V_3 )
{
if ( ( V_4 ) V_1 & ( V_2 - 1 ) ) {
* V_3 = 0 ;
return V_5 ;
}
if ( V_2 == 4 ) {
* V_3 = F_2 ( V_1 ) ;
} else if ( V_2 == 2 ) {
* V_3 = F_3 ( V_1 ) ;
} else if ( V_2 == 1 ) {
* V_3 = F_4 ( V_1 ) ;
} else {
* V_3 = 0 ;
return V_5 ;
}
return V_6 ;
}
int F_5 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
if ( ( V_4 ) V_1 & ( V_2 - 1 ) )
return V_5 ;
if ( V_2 == 4 )
F_6 ( V_3 , V_1 ) ;
else if ( V_2 == 2 )
F_7 ( V_3 , V_1 ) ;
else if ( V_2 == 1 )
F_8 ( V_3 , V_1 ) ;
else
return V_5 ;
return V_6 ;
}
T_2 F_9 ( struct V_7 * V_8 , T_2 V_9 )
{
if ( V_8 -> V_10 -> V_11 )
return V_8 -> V_10 -> V_11 ( V_8 , V_9 ) ;
return F_2 ( V_8 -> V_12 + V_9 ) ;
}
void F_10 ( struct V_7 * V_8 , T_2 V_9 , T_2 V_3 )
{
if ( V_8 -> V_10 -> V_13 )
V_8 -> V_10 -> V_13 ( V_8 , V_9 , V_3 ) ;
else
F_6 ( V_3 , V_8 -> V_12 + V_9 ) ;
}
static T_2 F_11 ( struct V_7 * V_8 , T_2 V_14 , T_2 V_9 )
{
T_2 V_15 = F_12 ( V_14 ) ;
return F_9 ( V_8 , V_15 + V_9 ) ;
}
static void F_13 ( struct V_7 * V_8 , T_2 V_14 , T_2 V_9 ,
T_2 V_3 )
{
T_2 V_15 = F_12 ( V_14 ) ;
F_10 ( V_8 , V_15 + V_9 , V_3 ) ;
}
void F_14 ( struct V_7 * V_8 , int V_14 , int type ,
T_3 V_16 , T_3 V_17 , T_2 V_2 )
{
T_2 V_18 , V_3 ;
if ( V_8 -> V_19 ) {
F_13 ( V_8 , V_14 , V_20 ,
F_15 ( V_16 ) ) ;
F_13 ( V_8 , V_14 , V_21 ,
F_16 ( V_16 ) ) ;
F_13 ( V_8 , V_14 , V_22 ,
F_15 ( V_16 + V_2 - 1 ) ) ;
F_13 ( V_8 , V_14 , V_23 ,
F_15 ( V_17 ) ) ;
F_13 ( V_8 , V_14 , V_24 ,
F_16 ( V_17 ) ) ;
F_13 ( V_8 , V_14 , V_25 ,
type ) ;
F_13 ( V_8 , V_14 , V_26 ,
V_27 ) ;
} else {
F_10 ( V_8 , V_28 ,
V_29 | V_14 ) ;
F_10 ( V_8 , V_30 ,
F_15 ( V_16 ) ) ;
F_10 ( V_8 , V_31 ,
F_16 ( V_16 ) ) ;
F_10 ( V_8 , V_32 ,
F_15 ( V_16 + V_2 - 1 ) ) ;
F_10 ( V_8 , V_33 ,
F_15 ( V_17 ) ) ;
F_10 ( V_8 , V_34 ,
F_16 ( V_17 ) ) ;
F_10 ( V_8 , V_35 , type ) ;
F_10 ( V_8 , V_36 , V_27 ) ;
}
for ( V_18 = 0 ; V_18 < V_37 ; V_18 ++ ) {
if ( V_8 -> V_19 )
V_3 = F_11 ( V_8 , V_14 ,
V_26 ) ;
else
V_3 = F_9 ( V_8 , V_36 ) ;
if ( V_3 == V_27 )
return;
F_17 ( V_38 , V_39 ) ;
}
F_18 ( V_8 -> V_40 , L_1 ) ;
}
int F_19 ( struct V_7 * V_8 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_41 ; V_18 ++ ) {
if ( F_20 ( V_8 ) ) {
F_21 ( V_8 -> V_40 , L_2 ) ;
return 0 ;
}
F_17 ( V_42 , V_43 ) ;
}
F_18 ( V_8 -> V_40 , L_3 ) ;
return - V_44 ;
}
int F_20 ( struct V_7 * V_8 )
{
T_2 V_3 ;
if ( V_8 -> V_10 -> V_45 )
return V_8 -> V_10 -> V_45 ( V_8 ) ;
V_3 = F_2 ( V_8 -> V_12 + V_46 ) ;
return ( ( V_3 & V_47 ) &&
( ! ( V_3 & V_48 ) ) ) ;
}
void F_22 ( struct V_7 * V_8 )
{
int V_49 ;
T_2 V_3 ;
T_2 V_50 ;
struct V_51 * V_40 = V_8 -> V_40 ;
struct V_52 * V_53 = V_40 -> V_54 ;
V_49 = F_23 ( V_53 , L_4 , & V_50 ) ;
if ( V_49 )
V_50 = 0 ;
V_3 = F_9 ( V_8 , V_55 ) ;
V_3 &= ~ V_56 ;
switch ( V_50 ) {
case 1 :
V_3 |= V_57 ;
break;
case 2 :
V_3 |= V_58 ;
break;
case 4 :
V_3 |= V_59 ;
break;
case 8 :
V_3 |= V_60 ;
break;
default:
F_18 ( V_8 -> V_40 , L_5 , V_50 ) ;
return;
}
F_10 ( V_8 , V_55 , V_3 ) ;
V_3 = F_9 ( V_8 , V_61 ) ;
V_3 &= ~ V_62 ;
switch ( V_50 ) {
case 1 :
V_3 |= V_63 ;
break;
case 2 :
V_3 |= V_64 ;
break;
case 4 :
V_3 |= V_65 ;
break;
case 8 :
V_3 |= V_66 ;
break;
}
F_10 ( V_8 , V_61 , V_3 ) ;
}
