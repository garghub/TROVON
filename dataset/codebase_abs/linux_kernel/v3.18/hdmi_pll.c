void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 ( T_1 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(pll->base, r))
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned long V_14 , int V_15 )
{
struct V_16 * V_17 = & V_2 -> V_18 ;
unsigned long V_19 ;
T_2 V_20 ;
V_14 /= 10000 ;
V_17 -> V_21 = V_22 ;
V_19 = V_14 / V_17 -> V_21 ;
if ( V_23 -> V_24 && V_15 <= 65000 )
V_17 -> V_25 = 3 ;
else
V_17 -> V_25 = V_26 ;
V_17 -> V_27 = V_15 * V_17 -> V_25 / V_19 ;
V_20 = ( V_15 - V_17 -> V_27 / V_17 -> V_25 * V_19 ) * 262144 ;
V_17 -> V_28 = V_17 -> V_25 * V_20 / V_19 ;
V_17 -> V_29 = V_15 > 1000 * 100 ;
V_17 -> V_30 = ( ( V_17 -> V_27 * V_14 / 10 ) / ( V_17 -> V_21 * 250 ) + 5 ) / 10 ;
V_17 -> V_31 = V_32 ;
F_4 ( L_1 , V_17 -> V_27 , V_17 -> V_28 ) ;
F_4 ( L_2 , V_17 -> V_29 , V_17 -> V_30 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 T_1 ;
struct V_16 * V_33 = & V_2 -> V_18 ;
F_6 ( V_2 -> V_34 , V_5 , 0x0 , 0 , 0 ) ;
T_1 = F_7 ( V_2 -> V_34 , V_8 ) ;
T_1 = F_8 ( T_1 , V_33 -> V_27 , 20 , 9 ) ;
T_1 = F_8 ( T_1 , V_33 -> V_21 - 1 , 8 , 1 ) ;
F_9 ( V_2 -> V_34 , V_8 , T_1 ) ;
T_1 = F_7 ( V_2 -> V_34 , V_9 ) ;
T_1 = F_8 ( T_1 , 0x0 , 12 , 12 ) ;
T_1 = F_8 ( T_1 , 0x1 , 13 , 13 ) ;
T_1 = F_8 ( T_1 , 0x0 , 14 , 14 ) ;
T_1 = F_8 ( T_1 , V_33 -> V_31 , 22 , 21 ) ;
if ( V_33 -> V_29 )
T_1 = F_8 ( T_1 , 0x4 , 3 , 1 ) ;
else
T_1 = F_8 ( T_1 , 0x2 , 3 , 1 ) ;
F_9 ( V_2 -> V_34 , V_9 , T_1 ) ;
F_6 ( V_2 -> V_34 , V_10 , V_33 -> V_30 , 17 , 10 ) ;
T_1 = F_7 ( V_2 -> V_34 , V_13 ) ;
T_1 = F_8 ( T_1 , V_33 -> V_25 , 24 , 18 ) ;
T_1 = F_8 ( T_1 , V_33 -> V_28 , 17 , 0 ) ;
F_9 ( V_2 -> V_34 , V_13 , T_1 ) ;
F_6 ( V_2 -> V_34 , V_7 , 0x1 , 0 , 0 ) ;
if ( F_10 ( V_2 -> V_34 , V_7 ,
0 , 0 , 0 ) != 0 ) {
F_11 ( L_3 ) ;
return - V_35 ;
}
if ( F_10 ( V_2 -> V_34 ,
V_6 , 1 , 1 , 1 ) != 1 ) {
F_11 ( L_4 ) ;
F_11 ( L_5 ,
F_7 ( V_2 -> V_34 , V_8 ) ) ;
F_11 ( L_6 ,
F_7 ( V_2 -> V_34 , V_9 ) ) ;
F_11 ( L_7 ,
F_7 ( V_2 -> V_34 , V_13 ) ) ;
return - V_35 ;
}
F_4 ( L_8 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_34 , V_5 , V_23 -> V_36 , 3 , 3 ) ;
if ( F_10 ( V_2 -> V_34 , V_6 , 0 , 0 , 1 )
!= 1 ) {
F_11 ( L_9 ) ;
return - V_35 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
T_3 T_1 = 0 ;
T_1 = F_14 ( V_38 , V_39 ) ;
if ( T_1 )
return T_1 ;
T_1 = F_14 ( V_38 , V_40 ) ;
if ( T_1 )
return T_1 ;
T_1 = F_12 ( V_2 ) ;
if ( T_1 )
return T_1 ;
T_1 = F_5 ( V_2 ) ;
if ( T_1 )
return T_1 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
F_14 ( V_38 , V_39 ) ;
}
static int F_16 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
const struct V_43 * V_45 ;
V_44 = F_17 ( & V_42 -> V_46 , sizeof( * V_44 ) , V_47 ) ;
if ( ! V_44 ) {
F_18 ( & V_42 -> V_46 , L_10 ) ;
return - V_48 ;
}
switch ( F_19 () ) {
case V_49 :
case V_50 :
case V_51 :
V_45 = & V_52 ;
break;
case V_53 :
V_45 = & V_54 ;
break;
default:
return - V_55 ;
}
memcpy ( V_44 , V_45 , sizeof( * V_44 ) ) ;
V_23 = V_44 ;
return 0 ;
}
int F_20 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
int T_1 ;
struct V_56 * V_57 ;
T_1 = F_16 ( V_42 ) ;
if ( T_1 )
return T_1 ;
V_57 = F_21 ( V_42 , V_58 , L_11 ) ;
if ( ! V_57 ) {
F_11 ( L_12 ) ;
return - V_59 ;
}
V_2 -> V_34 = F_22 ( & V_42 -> V_46 , V_57 ) ;
if ( F_23 ( V_2 -> V_34 ) ) {
F_11 ( L_13 ) ;
return F_24 ( V_2 -> V_34 ) ;
}
return 0 ;
}
