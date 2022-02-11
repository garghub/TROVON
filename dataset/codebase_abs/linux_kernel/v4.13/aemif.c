static inline unsigned int F_1 ( void T_1 * V_1 , int V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_1 * V_1 ,
int V_2 , unsigned long V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static int F_5 ( int V_4 , unsigned long V_5 , int V_6 )
{
int V_7 ;
V_7 = F_6 ( ( V_4 * V_5 ) , V_8 ) - 1 ;
F_7 ( L_1 , V_9 , V_7 , V_5 , V_4 ) ;
if ( V_7 < 0 )
V_7 = 0 ;
else if ( V_7 > V_6 )
V_7 = - V_10 ;
return V_7 ;
}
static int F_8 ( struct V_11 * V_12 ,
void T_1 * V_1 , unsigned V_13 ,
unsigned long V_14 )
{
unsigned V_15 , V_16 ;
int V_17 , V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
unsigned V_2 = V_24 + V_13 * 4 ;
if ( ! V_12 )
return 0 ;
V_14 /= 1000 ;
V_17 = F_5 ( V_12 -> V_17 , V_14 , V_25 ) ;
V_18 = F_5 ( V_12 -> V_18 , V_14 , V_26 ) ;
V_19 = F_5 ( V_12 -> V_19 , V_14 , V_27 ) ;
V_20 = F_5 ( V_12 -> V_20 , V_14 , V_28 ) ;
V_21 = F_5 ( V_12 -> V_21 , V_14 , V_29 ) ;
V_22 = F_5 ( V_12 -> V_22 , V_14 , V_30 ) ;
V_23 = F_5 ( V_12 -> V_23 , V_14 , V_31 ) ;
if ( V_17 < 0 || V_18 < 0 || V_19 < 0 || V_20 < 0 ||
V_21 < 0 || V_22 < 0 || V_23 < 0 ) {
F_9 ( L_2 , V_9 ) ;
return - V_10 ;
}
V_15 = F_10 ( V_17 ) | F_11 ( V_18 ) | F_12 ( V_19 ) | F_13 ( V_20 ) |
F_14 ( V_21 ) | F_15 ( V_22 ) | F_16 ( V_23 ) ;
V_16 = F_17 ( V_1 + V_2 ) ;
V_16 &= ~ V_32 ;
V_16 |= V_15 ;
F_18 ( V_16 , V_1 + V_2 ) ;
return 0 ;
}
int F_19 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_20 ( & V_34 -> V_37 ) ;
T_2 V_16 ;
unsigned long V_14 ;
struct V_38 * V_39 ;
void T_1 * V_1 ;
struct V_5 * V_5 ;
int V_40 = 0 ;
V_5 = F_21 ( & V_34 -> V_37 , L_3 ) ;
if ( F_22 ( V_5 ) ) {
V_40 = F_23 ( V_5 ) ;
F_24 ( & V_34 -> V_37 , L_4 , V_40 ) ;
return V_40 ;
}
V_40 = F_25 ( V_5 ) ;
if ( V_40 < 0 ) {
F_24 ( & V_34 -> V_37 , L_5 ,
V_40 ) ;
goto V_41;
}
V_39 = F_26 ( V_34 , V_42 , 1 ) ;
if ( ! V_39 ) {
F_27 ( & V_34 -> V_37 , L_6 ) ;
V_40 = - V_43 ;
goto V_44;
}
V_1 = F_28 ( V_39 -> V_45 , F_29 ( V_39 ) ) ;
if ( ! V_1 ) {
F_27 ( & V_34 -> V_37 , L_7 , V_39 ) ;
V_40 = - V_43 ;
goto V_44;
}
V_16 = F_1 ( V_1 , V_24 + V_34 -> V_46 * 4 ) ;
V_16 &= ~ ( V_47 | V_48 | V_49 ) ;
if ( V_36 -> V_50 & V_51 )
V_16 |= 0x1 ;
F_3 ( V_1 , V_24 + V_34 -> V_46 * 4 , V_16 ) ;
V_14 = F_30 ( V_5 ) ;
if ( V_36 -> V_52 )
V_40 = F_8 ( V_36 -> V_52 , V_1 , V_34 -> V_46 ,
V_14 ) ;
if ( V_40 < 0 )
F_24 ( & V_34 -> V_37 , L_8 ) ;
F_31 ( V_1 ) ;
V_44:
F_32 ( V_5 ) ;
V_41:
F_33 ( V_5 ) ;
return V_40 ;
}
