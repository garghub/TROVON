static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_6 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_9 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_10 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned long V_13 ;
unsigned int V_14 ;
T_1 V_5 ;
F_12 ( & V_2 -> V_15 , V_13 ) ;
V_5 = V_2 -> V_16 ( V_2 , 0x0e ) ;
V_2 -> V_17 ( V_2 , 0xe , V_5 | 0x08 ) ;
V_10 -> V_18 = V_2 -> V_16 ( V_2 , 0x00 ) ;
V_10 -> V_19 = V_2 -> V_16 ( V_2 , 0x02 ) ;
V_10 -> V_20 = V_2 -> V_16 ( V_2 , 0x04 ) ;
V_10 -> V_21 = V_2 -> V_16 ( V_2 , 0x06 ) ;
V_10 -> V_22 = V_2 -> V_16 ( V_2 , 0x09 ) ;
V_10 -> V_23 = V_2 -> V_16 ( V_2 , 0x0a ) ;
V_10 -> V_24 = V_2 -> V_16 ( V_2 , 0x08 ) ;
V_14 = V_2 -> V_16 ( V_2 , 0x0f ) ;
V_2 -> V_17 ( V_2 , 0x0e , V_5 ) ;
F_13 ( & V_2 -> V_15 , V_13 ) ;
V_10 -> V_18 = F_14 ( V_10 -> V_18 ) ;
V_10 -> V_19 = F_14 ( V_10 -> V_19 ) ;
V_10 -> V_20 = F_14 ( V_10 -> V_20 ) ;
V_10 -> V_21 = F_14 ( V_10 -> V_21 ) ;
V_10 -> V_22 = F_14 ( V_10 -> V_22 ) ;
V_10 -> V_23 = F_14 ( V_10 -> V_23 ) ;
V_10 -> V_24 = F_14 ( V_10 -> V_24 ) ;
V_14 = F_14 ( V_14 ) ;
V_10 -> V_23 += ( V_14 * 100 ) ;
V_10 -> V_23 -= 1900 ;
V_10 -> V_22 -- ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_10 ( V_8 ) ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_25 , V_26 , V_27 , V_28 , V_29 , V_30 , V_14 , V_5 ;
unsigned long V_13 ;
unsigned int V_31 ;
V_31 = V_10 -> V_23 + 1900 ;
V_14 = V_31 / 100 ;
V_30 = V_31 % 100 ;
V_29 = V_10 -> V_22 + 1 ;
V_28 = V_10 -> V_21 ;
V_27 = V_10 -> V_20 ;
V_26 = V_10 -> V_19 ;
V_25 = V_10 -> V_18 ;
V_25 = F_16 ( V_25 ) ;
V_26 = F_16 ( V_26 ) ;
V_27 = F_16 ( V_27 ) ;
V_28 = F_16 ( V_28 ) ;
V_29 = F_16 ( V_29 ) ;
V_30 = F_16 ( V_30 ) ;
V_14 = F_16 ( V_14 ) ;
F_12 ( & V_2 -> V_15 , V_13 ) ;
V_5 = V_2 -> V_16 ( V_2 , 0x0e ) ;
V_2 -> V_17 ( V_2 , 0x0e , V_5 | 0x08 ) ;
V_2 -> V_17 ( V_2 , 0x00 , V_25 ) ;
V_2 -> V_17 ( V_2 , 0x02 , V_26 ) ;
V_2 -> V_17 ( V_2 , 0x04 , V_27 ) ;
V_2 -> V_17 ( V_2 , 0x06 , V_28 ) ;
V_2 -> V_17 ( V_2 , 0x09 , V_29 ) ;
V_2 -> V_17 ( V_2 , 0x0a , V_30 ) ;
V_2 -> V_17 ( V_2 , 0x0f , V_14 ) ;
V_2 -> V_17 ( V_2 , 0x0e , V_5 ) ;
F_13 ( & V_2 -> V_15 , V_13 ) ;
return 0 ;
}
static int T_2 F_17 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_18 ( sizeof( * V_2 ) , V_32 ) ;
int V_33 = - V_34 ;
if ( ! V_2 )
goto V_35;
F_19 ( & V_2 -> V_15 ) ;
V_2 -> V_36 = F_20 ( V_12 , V_37 , 0 ) ;
if ( ! V_2 -> V_36 ) {
V_2 -> V_36 = F_20 ( V_12 , V_38 , 0 ) ;
V_33 = - V_39 ;
if ( ! V_2 -> V_36 )
goto V_40;
}
if ( V_2 -> V_36 -> V_13 & V_38 ) {
V_2 -> V_4 = V_2 -> V_36 -> V_41 ;
V_2 -> V_16 = F_1 ;
V_2 -> V_17 = F_3 ;
} else if ( V_2 -> V_36 -> V_13 & V_37 ) {
V_2 -> V_6 = F_21 ( V_2 -> V_36 -> V_41 , F_22 ( V_2 -> V_36 ) ) ;
V_2 -> V_16 = F_5 ;
V_2 -> V_17 = F_7 ;
} else {
V_33 = - V_39 ;
goto V_40;
}
F_23 ( V_12 , V_2 ) ;
V_2 -> V_42 = F_24 ( L_1 , & V_12 -> V_8 ,
& V_43 , V_44 ) ;
if ( F_25 ( V_2 -> V_42 ) ) {
V_33 = F_26 ( V_2 -> V_42 ) ;
goto V_45;
}
V_33 = 0 ;
V_35:
return V_33 ;
V_45:
if ( V_2 -> V_36 -> V_13 & V_37 )
F_27 ( V_2 -> V_6 ) ;
V_40:
F_28 ( V_2 ) ;
goto V_35;
}
static int T_3 F_29 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_30 ( V_2 -> V_42 ) ;
if ( V_2 -> V_36 -> V_13 & V_37 )
F_27 ( V_2 -> V_6 ) ;
F_23 ( V_12 , NULL ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_46 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_46 ) ;
}
