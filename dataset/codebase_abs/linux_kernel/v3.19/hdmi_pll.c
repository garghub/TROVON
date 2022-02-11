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
void F_3 ( struct V_1 * V_2 ,
unsigned long V_14 , struct V_15 * V_16 )
{
unsigned long V_17 , V_18 , V_19 ;
unsigned long V_20 , V_21 ;
unsigned long V_22 ;
unsigned V_23 , V_24 , V_25 , V_26 , V_27 ;
unsigned long V_28 ;
const struct V_29 * V_30 = V_2 -> V_2 . V_30 ;
V_28 = F_4 ( V_2 -> V_2 . V_28 ) ;
F_5 ( L_1 , V_28 , V_14 ) ;
V_20 = V_14 * 10 ;
V_23 = F_6 ( V_28 , V_30 -> V_31 ) ;
V_17 = V_28 / V_23 ;
V_22 = F_7 ( V_30 -> V_32 , V_17 ) ;
V_26 = F_6 ( V_22 , V_20 ) ;
if ( V_26 == 0 )
V_26 = 1 ;
V_21 = V_20 * V_26 ;
V_24 = V_21 / V_17 ;
V_18 = V_17 * V_24 ;
if ( F_8 ( V_21 - V_18 > V_17 ) )
V_25 = 0 ;
else
V_25 = ( V_33 ) F_9 ( 262144ull * ( V_21 - V_18 ) , V_17 ) ;
if ( V_25 > 0 )
V_18 += ( V_33 ) F_9 ( ( V_34 ) V_25 * V_17 , 262144 ) ;
V_19 = V_18 / V_26 ;
V_27 = F_6 ( V_17 * V_24 , 250000000 ) ;
F_5 ( L_2 ,
V_23 , V_24 , V_25 , V_26 , V_27 ) ;
F_5 ( L_3 , V_17 , V_18 , V_19 ) ;
V_16 -> V_23 = V_23 ;
V_16 -> V_24 = V_24 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_35 [ 0 ] = V_26 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_17 = V_17 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 [ 0 ] = V_19 ;
}
static int F_10 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_11 ( V_37 , struct V_1 , V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
T_2 T_1 = 0 ;
T_1 = F_12 ( V_39 , V_40 ) ;
if ( T_1 )
return T_1 ;
return 0 ;
}
static void F_13 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_11 ( V_37 , struct V_1 , V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
F_12 ( V_39 , V_41 ) ;
}
static int F_14 ( struct V_42 * V_43 , struct V_1 * V_44 )
{
struct V_36 * V_2 = & V_44 -> V_2 ;
struct V_45 * V_45 ;
int T_1 ;
V_45 = F_15 ( & V_43 -> V_46 , L_4 ) ;
if ( F_16 ( V_45 ) ) {
F_17 ( L_5 ) ;
return F_18 ( V_45 ) ;
}
V_2 -> V_47 = L_6 ;
V_2 -> V_48 = V_44 -> V_48 ;
V_2 -> V_28 = V_45 ;
switch ( F_19 () ) {
case V_49 :
case V_50 :
case V_51 :
V_2 -> V_30 = & V_52 ;
break;
case V_53 :
V_2 -> V_30 = & V_54 ;
break;
default:
return - V_55 ;
}
V_2 -> V_56 = & V_57 ;
T_1 = F_20 ( V_2 ) ;
if ( T_1 )
return T_1 ;
return 0 ;
}
int F_21 ( struct V_42 * V_43 , struct V_1 * V_2 ,
struct V_38 * V_39 )
{
int T_1 ;
struct V_58 * V_59 ;
V_2 -> V_39 = V_39 ;
V_59 = F_22 ( V_43 , V_60 , L_7 ) ;
if ( ! V_59 ) {
F_17 ( L_8 ) ;
return - V_61 ;
}
V_2 -> V_48 = F_23 ( & V_43 -> V_46 , V_59 ) ;
if ( F_16 ( V_2 -> V_48 ) ) {
F_17 ( L_9 ) ;
return F_18 ( V_2 -> V_48 ) ;
}
T_1 = F_14 ( V_43 , V_2 ) ;
if ( T_1 ) {
F_17 ( L_10 ) ;
return T_1 ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_44 )
{
struct V_36 * V_2 = & V_44 -> V_2 ;
F_25 ( V_2 ) ;
}
