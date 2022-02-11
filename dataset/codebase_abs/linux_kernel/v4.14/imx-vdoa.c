static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 ;
T_2 V_7 ;
F_2 ( 0 , V_4 -> V_8 + V_9 ) ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 ) {
F_3 ( V_4 -> V_10 ,
L_1 ) ;
return V_11 ;
}
V_7 = F_4 ( V_4 -> V_8 + V_12 ) ;
F_2 ( V_7 , V_4 -> V_8 + V_12 ) ;
if ( V_7 & V_13 ) {
V_7 = F_4 ( V_4 -> V_8 + V_14 ) & V_15 ;
F_5 ( V_4 -> V_10 , L_2 , V_7 ? L_3 : L_4 ) ;
} else if ( ! ( V_7 & V_16 ) ) {
F_3 ( V_4 -> V_10 , L_5 ) ;
}
V_6 -> V_17 ++ ;
F_6 ( & V_6 -> V_18 ) ;
return V_11 ;
}
int F_7 ( struct V_5 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_4 ;
if ( V_19 -> V_20 == V_19 -> V_17 )
return 0 ;
if ( ! F_8 ( & V_19 -> V_18 ,
F_9 ( 300 ) ) ) {
F_5 ( V_4 -> V_10 ,
L_6 ) ;
return - V_21 ;
}
return 0 ;
}
void F_10 ( struct V_5 * V_19 , T_3 V_22 , T_3 V_23 )
{
struct V_24 * V_25 , * V_26 ;
struct V_3 * V_4 = V_19 -> V_4 ;
T_2 V_7 ;
if ( V_4 -> V_6 )
F_7 ( V_4 -> V_6 ) ;
V_4 -> V_6 = V_19 ;
F_11 ( & V_19 -> V_18 ) ;
V_19 -> V_20 ++ ;
V_25 = & V_19 -> V_27 [ V_28 ] ;
V_26 = & V_19 -> V_27 [ V_29 ] ;
if ( V_26 -> V_30 == V_31 )
V_7 = V_32 ;
else
V_7 = 0 ;
F_2 ( V_7 , V_4 -> V_8 + V_33 ) ;
F_2 ( V_26 -> V_34 << 16 | V_26 -> V_35 ,
V_4 -> V_8 + V_36 ) ;
V_7 = V_22 ;
F_2 ( V_7 , V_4 -> V_8 + V_37 ) ;
F_2 ( V_25 -> V_38 << 16 | V_26 -> V_38 ,
V_4 -> V_8 + V_39 ) ;
if ( V_26 -> V_30 == V_40 ||
V_26 -> V_30 == V_41 )
V_7 = V_26 -> V_38 * V_26 -> V_34 ;
else
V_7 = 0 ;
F_2 ( V_7 , V_4 -> V_8 + V_42 ) ;
V_7 = V_23 ;
F_2 ( V_7 , V_4 -> V_8 + V_43 ) ;
V_7 = F_12 ( V_25 -> V_38 * V_25 -> V_34 , 4096 ) ;
F_2 ( V_7 , V_4 -> V_8 + V_44 ) ;
F_2 ( V_45 | V_46 , V_4 -> V_8 + V_9 ) ;
F_2 ( V_47 , V_4 -> V_8 + V_48 ) ;
}
struct V_5 * F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_19 ;
int V_49 ;
V_19 = F_14 ( sizeof( * V_19 ) , V_50 ) ;
if ( ! V_19 )
return NULL ;
V_49 = F_15 ( V_4 -> V_51 ) ;
if ( V_49 ) {
F_16 ( V_19 ) ;
return NULL ;
}
F_17 ( & V_19 -> V_18 ) ;
V_19 -> V_4 = V_4 ;
return V_19 ;
}
void F_18 ( struct V_5 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_4 ;
if ( V_4 -> V_6 == V_19 ) {
F_7 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_19 ( V_4 -> V_51 ) ;
F_16 ( V_19 ) ;
}
int F_20 ( struct V_5 * V_19 ,
unsigned int V_35 , unsigned int V_34 ,
T_2 V_30 )
{
struct V_24 * V_25 ;
struct V_24 * V_26 ;
if ( V_35 < 16 || V_35 > 8192 || V_35 % 16 != 0 ||
V_34 < 16 || V_34 > 4096 || V_34 % 16 != 0 )
return - V_52 ;
if ( V_30 != V_31 &&
V_30 != V_40 )
return - V_52 ;
if ( ! V_19 )
return 0 ;
V_25 = & V_19 -> V_27 [ V_28 ] ;
V_26 = & V_19 -> V_27 [ V_29 ] ;
V_25 -> V_35 = V_35 ;
V_25 -> V_34 = V_34 ;
V_25 -> V_38 = V_35 ;
V_25 -> V_53 =
F_12 ( V_25 -> V_38 * V_34 , 4096 ) +
V_25 -> V_38 * V_34 / 2 ;
V_26 -> V_35 = V_35 ;
V_26 -> V_34 = V_34 ;
V_26 -> V_30 = V_30 ;
switch ( V_30 ) {
case V_31 :
V_26 -> V_38 = V_35 * 2 ;
V_26 -> V_53 = V_26 -> V_38 * V_34 ;
break;
case V_40 :
default:
V_26 -> V_38 = V_35 ;
V_26 -> V_53 =
V_26 -> V_38 * V_34 * 3 / 2 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_54 * V_55 )
{
struct V_3 * V_4 ;
struct V_56 * V_57 ;
F_22 ( & V_55 -> V_10 , F_23 ( 32 ) ) ;
V_4 = F_24 ( & V_55 -> V_10 , sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return - V_58 ;
V_4 -> V_10 = & V_55 -> V_10 ;
V_4 -> V_51 = F_25 ( V_4 -> V_10 , NULL ) ;
if ( F_26 ( V_4 -> V_51 ) ) {
F_5 ( V_4 -> V_10 , L_7 ) ;
return F_27 ( V_4 -> V_51 ) ;
}
V_57 = F_28 ( V_55 , V_59 , 0 ) ;
V_4 -> V_8 = F_29 ( V_4 -> V_10 , V_57 ) ;
if ( F_26 ( V_4 -> V_8 ) )
return F_27 ( V_4 -> V_8 ) ;
V_57 = F_28 ( V_55 , V_60 , 0 ) ;
if ( ! V_57 )
return - V_52 ;
V_4 -> V_1 = F_30 ( & V_55 -> V_10 , V_57 -> V_61 , NULL ,
F_1 , V_62 ,
L_8 , V_4 ) ;
if ( V_4 -> V_1 < 0 ) {
F_5 ( V_4 -> V_10 , L_9 ) ;
return V_4 -> V_1 ;
}
F_31 ( V_55 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_54 * V_55 )
{
return 0 ;
}
