static int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , const char * V_5 )
{
T_1 V_6 ;
if ( ! V_2 || ! V_2 -> V_7 -> V_8 )
return - V_9 ;
V_6 = F_2 ( V_2 -> V_7 -> V_8 + V_10 ) ;
if ( ( V_6 & V_4 ) != V_4 ) {
F_3 ( V_2 -> V_7 -> V_11 , L_1 , V_5 ) ;
return - V_9 ;
}
if ( V_3 < 0 || V_3 >= V_2 -> V_7 -> V_12 ) {
F_3 ( V_2 -> V_7 -> V_11 , L_2 , V_3 ) ;
return - V_13 ;
}
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_14 , const char * V_5 )
{
struct V_15 * V_16 ;
int V_17 ;
F_5 ( V_3 , V_2 -> V_7 -> V_8 + V_18 ) ;
F_6 ( V_14 , V_2 -> V_7 -> V_8 + V_19 ) ;
V_16 = F_7 ( & V_2 -> V_7 -> V_20 , struct V_15 , V_21 ) ;
V_17 = F_8 ( V_16 , V_22 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_2 ( V_2 -> V_7 -> V_8 + V_23 ) ;
if ( V_17 )
F_3 ( V_2 -> V_7 -> V_11 ,
L_3 , V_5 , V_17 ) ;
return - V_17 ;
}
int F_9 ( struct V_24 * V_25 , int V_3 , T_2 * V_26 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
unsigned int V_27 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_29 , L_4 ) ;
if ( V_28 )
return V_28 ;
if ( F_11 ( V_26 ) ) {
F_3 ( V_2 -> V_7 -> V_11 ,
L_5 ,
V_26 , V_3 ) ;
return - V_13 ;
}
V_27 = V_30 + V_3 * V_31 ;
F_12 ( F_13 ( V_26 ) , V_2 -> V_7 -> V_8 + V_27 ) ;
F_6 ( F_14 ( V_26 + 4 ) ,
V_2 -> V_7 -> V_8 + V_27 + V_32 ) ;
return F_4 ( V_2 , V_3 , V_33 , L_6 ) ;
}
int F_15 ( struct V_24 * V_25 , int V_3 , T_1 V_34 , T_2 V_35 ,
T_3 V_36 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
unsigned int V_27 ;
T_1 V_37 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_38 , L_7 ) ;
if ( V_28 )
return V_28 ;
if ( V_36 != F_16 ( V_39 ) )
return - V_9 ;
if ( V_34 > 4095 || V_35 > 7 ) {
F_3 ( V_2 -> V_7 -> V_11 ,
L_8 , V_3 ) ;
return - V_13 ;
}
V_37 = F_17 ( V_40 , V_34 ) |
F_17 ( V_41 , V_35 ) ;
V_27 = V_30 + V_3 * V_31 ;
F_6 ( V_37 , V_2 -> V_7 -> V_8 + V_27 + V_42 ) ;
return F_4 ( V_2 , V_3 , V_43 ,
L_7 ) ;
}
int F_18 ( struct V_24 * V_25 , int V_3 , bool V_44 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
unsigned int V_27 ;
T_2 V_45 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_46 ,
L_9 ) ;
if ( V_28 )
return V_28 ;
V_27 = V_30 + V_3 * V_31 +
V_47 ;
V_45 = F_19 ( V_2 -> V_7 -> V_8 + V_27 ) ;
V_45 &= ~ V_48 ;
V_45 |= F_17 ( V_48 , V_44 ) ;
F_5 ( V_45 , V_2 -> V_7 -> V_8 + V_27 ) ;
return F_4 ( V_2 , V_3 , V_49 ,
L_9 ) ;
}
int F_20 ( struct V_24 * V_25 , int V_3 ,
int V_50 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
unsigned int V_27 ;
T_2 V_45 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_51 ,
L_10 ) ;
if ( V_28 )
return V_28 ;
switch ( V_50 ) {
case V_52 :
case V_53 :
case V_54 :
break;
default:
return - V_13 ;
}
V_27 = V_30 + V_3 * V_31 +
V_47 ;
V_45 = F_19 ( V_2 -> V_7 -> V_8 + V_27 ) ;
V_45 &= ~ V_55 ;
V_45 |= F_17 ( V_55 , V_50 ) ;
F_5 ( V_45 , V_2 -> V_7 -> V_8 + V_27 ) ;
return F_4 ( V_2 , V_3 , V_56 ,
L_11 ) ;
}
int F_21 ( struct V_24 * V_25 , int V_3 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
unsigned int V_27 ;
T_1 V_37 ;
T_4 V_59 ;
T_1 V_60 ;
T_2 V_61 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , 0 , L_12 ) ;
if ( V_28 )
return V_28 ;
V_27 = V_30 + V_3 * V_31 ;
V_59 = F_22 ( V_2 -> V_7 -> V_8 + V_27 ) ;
V_60 = F_2 ( V_2 -> V_7 -> V_8 + V_27 + V_32 ) ;
V_61 = F_19 ( V_2 -> V_7 -> V_8 + V_27 + V_47 ) ;
V_37 = F_2 ( V_2 -> V_7 -> V_8 + V_27 + V_42 ) ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_3 = V_3 ;
F_23 ( V_59 , & V_58 -> V_26 [ 0 ] ) ;
F_24 ( V_60 , & V_58 -> V_26 [ 4 ] ) ;
V_58 -> V_34 = F_25 ( V_40 , V_37 ) ;
V_58 -> V_35 = F_25 ( V_41 , V_37 ) ;
V_58 -> V_62 = F_25 ( V_48 , V_61 ) ;
V_58 -> V_63 = F_25 ( V_55 , V_61 ) ;
return 0 ;
}
