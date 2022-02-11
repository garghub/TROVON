void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 ( T_1 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(phy->base, r))
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
}
static T_2 F_3 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
T_3 V_13 ;
V_13 = F_4 ( V_12 ) ;
F_5 ( V_12 , V_13 ) ;
if ( ( V_13 & V_14 ) &&
V_13 & V_15 ) {
F_6 ( V_12 , V_16 ) ;
F_5 ( V_12 , V_14 |
V_15 ) ;
F_6 ( V_12 , V_17 ) ;
} else if ( V_13 & V_14 ) {
F_6 ( V_12 , V_18 ) ;
} else if ( V_13 & V_15 ) {
F_6 ( V_12 , V_17 ) ;
}
return V_19 ;
}
int F_7 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_20 * V_21 )
{
T_4 T_1 = 0 ;
T_3 V_13 ;
F_8 ( V_12 , 0xffffffff ) ;
V_13 = F_4 ( V_12 ) ;
F_5 ( V_12 , V_13 ) ;
T_1 = F_6 ( V_12 , V_17 ) ;
if ( T_1 )
return T_1 ;
F_9 ( V_2 -> V_22 , V_5 ) ;
F_10 ( V_2 -> V_22 , V_5 , 0x1 , 31 , 30 ) ;
F_11 ( V_2 -> V_22 , V_6 , 0xF0000000 ) ;
F_10 ( V_2 -> V_22 , V_7 , 0xB , 3 , 0 ) ;
F_10 ( V_2 -> V_22 , V_8 , 0x1 , 27 , 27 ) ;
T_1 = F_12 ( V_2 -> V_9 , NULL , F_3 ,
V_23 , L_1 , V_12 ) ;
if ( T_1 ) {
F_13 ( L_2 ) ;
F_6 ( V_12 , V_16 ) ;
return T_1 ;
}
F_14 ( V_12 ,
V_14 | V_15 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_16 ( V_2 -> V_9 , V_12 ) ;
F_6 ( V_12 , V_16 ) ;
}
int F_17 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_26 V_28 ;
V_27 = F_18 ( V_25 , V_29 , L_3 ) ;
if ( ! V_27 ) {
F_19 ( L_4 ) ;
V_27 = F_20 ( V_25 , V_29 , 0 ) ;
if ( ! V_27 ) {
F_13 ( L_5 ) ;
return - V_30 ;
}
V_28 . V_31 = V_27 -> V_31 + V_32 ;
V_28 . V_33 = V_28 . V_31 + V_34 - 1 ;
V_27 = & V_28 ;
}
V_2 -> V_22 = F_21 ( & V_25 -> V_35 , V_27 -> V_31 , F_22 ( V_27 ) ) ;
if ( ! V_2 -> V_22 ) {
F_13 ( L_6 ) ;
return - V_36 ;
}
V_2 -> V_9 = F_23 ( V_25 , 0 ) ;
if ( V_2 -> V_9 < 0 ) {
F_13 ( L_7 ) ;
return - V_37 ;
}
return 0 ;
}
