static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
F_4 ( & V_2 -> V_9 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_10 + V_11 ) ;
if ( V_7 & F_6 ( V_3 ) ) {
F_7 ( V_2 -> V_8 , L_2 ,
V_3 ) ;
F_8 ( & V_2 -> V_9 , V_6 ) ;
return - V_12 ;
}
F_9 ( V_7 | F_6 ( V_3 ) , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_2 -> V_9 , V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( & V_2 -> V_9 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_10 + V_11 ) ;
V_7 &= ~ F_6 ( V_3 ) ;
F_9 ( V_7 , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_2 -> V_9 , V_6 ) ;
F_3 ( V_2 -> V_8 , L_3 , V_3 ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
struct V_17 * V_18 ;
T_2 V_19 = F_12 ( V_16 ) ;
struct V_4 * V_5 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
if ( F_13 ( V_19 , & V_18 ) ) {
F_14 ( V_16 , L_4 ) ;
return - V_23 ;
}
V_5 = F_15 ( V_16 , sizeof( struct V_4 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
V_21 = F_16 ( V_14 , V_26 , 0 ) ;
if ( ! V_21 ) {
F_14 ( & V_14 -> V_16 , L_5 ) ;
return - V_12 ;
}
V_5 -> V_10 = F_17 ( V_16 , V_21 ) ;
if ( F_18 ( V_5 -> V_10 ) ) {
F_14 ( & V_14 -> V_16 , L_6 ) ;
return F_19 ( V_5 -> V_10 ) ;
}
V_22 = F_20 ( & V_5 -> V_2 , V_16 , 4 ,
V_5 -> V_10 + V_27 ,
V_5 -> V_10 + V_28 , NULL ,
V_5 -> V_10 + V_29 , NULL ,
V_30 ) ;
if ( V_22 ) {
F_14 ( & V_14 -> V_16 , L_7 ) ;
return V_22 ;
}
V_5 -> V_2 . V_31 = V_32 ;
V_5 -> V_2 . V_33 = F_1 ;
V_5 -> V_2 . free = F_10 ;
V_5 -> V_2 . V_34 = V_35 ;
#if F_21 ( V_36 )
V_5 -> V_2 . V_37 = V_14 -> V_16 . V_37 ;
#endif
V_22 = F_22 ( & V_5 -> V_2 , V_5 ) ;
if ( V_22 ) {
F_14 ( & V_14 -> V_16 , L_8 ) ;
return V_22 ;
}
F_23 ( V_14 , V_5 ) ;
F_9 ( 0 , V_5 -> V_10 + V_11 ) ;
F_9 ( 0 , V_5 -> V_10 + V_38 ) ;
F_3 ( & V_14 -> V_16 , L_9 ) ;
return V_22 ;
}
static int F_24 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = F_25 ( V_14 ) ;
F_26 ( & V_5 -> V_2 ) ;
return 0 ;
}
