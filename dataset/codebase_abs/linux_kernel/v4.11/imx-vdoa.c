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
F_6 ( V_4 -> V_10 , L_5 ) ;
}
F_7 ( & V_6 -> V_17 ) ;
return V_11 ;
}
void F_8 ( struct V_5 * V_18 , T_3 V_19 , T_3 V_20 )
{
struct V_21 * V_22 , * V_23 ;
struct V_3 * V_4 = V_18 -> V_4 ;
T_2 V_7 ;
V_4 -> V_6 = V_18 ;
V_22 = & V_18 -> V_24 [ V_25 ] ;
V_23 = & V_18 -> V_24 [ V_26 ] ;
if ( V_23 -> V_27 == V_28 )
V_7 = V_29 ;
else
V_7 = 0 ;
F_2 ( V_7 , V_4 -> V_8 + V_30 ) ;
F_2 ( V_23 -> V_31 << 16 | V_23 -> V_32 ,
V_4 -> V_8 + V_33 ) ;
V_7 = V_19 ;
F_2 ( V_7 , V_4 -> V_8 + V_34 ) ;
F_2 ( V_22 -> V_35 << 16 | V_23 -> V_35 ,
V_4 -> V_8 + V_36 ) ;
if ( V_23 -> V_27 == V_37 ||
V_23 -> V_27 == V_38 )
V_7 = V_23 -> V_35 * V_23 -> V_31 ;
else
V_7 = 0 ;
F_2 ( V_7 , V_4 -> V_8 + V_39 ) ;
V_7 = V_20 ;
F_2 ( V_7 , V_4 -> V_8 + V_40 ) ;
V_7 = F_9 ( V_22 -> V_35 * V_22 -> V_31 , 4096 ) ;
F_2 ( V_7 , V_4 -> V_8 + V_41 ) ;
F_2 ( V_42 | V_43 , V_4 -> V_8 + V_9 ) ;
F_2 ( V_44 , V_4 -> V_8 + V_45 ) ;
}
int F_10 ( struct V_5 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
if ( ! F_11 ( & V_18 -> V_17 ,
F_12 ( 300 ) ) ) {
F_5 ( V_4 -> V_10 ,
L_6 ) ;
return - V_46 ;
}
return 0 ;
}
struct V_5 * F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_18 ;
int V_47 ;
V_18 = F_14 ( sizeof( * V_18 ) , V_48 ) ;
if ( ! V_18 )
return NULL ;
V_47 = F_15 ( V_4 -> V_49 ) ;
if ( V_47 ) {
F_16 ( V_18 ) ;
return NULL ;
}
F_17 ( & V_18 -> V_17 ) ;
V_18 -> V_4 = V_4 ;
return V_18 ;
}
void F_18 ( struct V_5 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_4 ;
F_19 ( V_4 -> V_49 ) ;
F_16 ( V_18 ) ;
}
int F_20 ( struct V_5 * V_18 ,
unsigned int V_32 , unsigned int V_31 ,
T_2 V_27 )
{
struct V_21 * V_22 ;
struct V_21 * V_23 ;
if ( V_32 < 16 || V_32 > 8192 || V_32 % 16 != 0 ||
V_31 < 16 || V_31 > 4096 || V_31 % 16 != 0 )
return - V_50 ;
if ( V_27 != V_28 &&
V_27 != V_37 )
return - V_50 ;
if ( ! V_18 )
return 0 ;
V_22 = & V_18 -> V_24 [ V_25 ] ;
V_23 = & V_18 -> V_24 [ V_26 ] ;
V_22 -> V_32 = V_32 ;
V_22 -> V_31 = V_31 ;
V_22 -> V_35 = V_32 ;
V_22 -> V_51 =
F_9 ( V_22 -> V_35 * V_31 , 4096 ) +
V_22 -> V_35 * V_31 / 2 ;
V_23 -> V_32 = V_32 ;
V_23 -> V_31 = V_31 ;
V_23 -> V_27 = V_27 ;
switch ( V_27 ) {
case V_28 :
V_23 -> V_35 = V_32 * 2 ;
V_23 -> V_51 = V_23 -> V_35 * V_31 ;
break;
case V_37 :
default:
V_23 -> V_35 = V_32 ;
V_23 -> V_51 =
V_23 -> V_35 * V_31 * 3 / 2 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_52 * V_53 )
{
struct V_3 * V_4 ;
struct V_54 * V_55 ;
F_22 ( & V_53 -> V_10 , F_23 ( 32 ) ) ;
V_4 = F_24 ( & V_53 -> V_10 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return - V_56 ;
V_4 -> V_10 = & V_53 -> V_10 ;
V_4 -> V_49 = F_25 ( V_4 -> V_10 , NULL ) ;
if ( F_26 ( V_4 -> V_49 ) ) {
F_5 ( V_4 -> V_10 , L_7 ) ;
return F_27 ( V_4 -> V_49 ) ;
}
V_55 = F_28 ( V_53 , V_57 , 0 ) ;
V_4 -> V_8 = F_29 ( V_4 -> V_10 , V_55 ) ;
if ( F_26 ( V_4 -> V_8 ) )
return F_27 ( V_4 -> V_8 ) ;
V_55 = F_28 ( V_53 , V_58 , 0 ) ;
V_4 -> V_1 = F_30 ( & V_53 -> V_10 , V_55 -> V_59 , NULL ,
F_1 , V_60 ,
L_8 , V_4 ) ;
if ( V_4 -> V_1 < 0 ) {
F_5 ( V_4 -> V_10 , L_9 ) ;
return V_4 -> V_1 ;
}
F_31 ( V_53 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_52 * V_53 )
{
return 0 ;
}
