static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
T_1 V_6 ;
F_2 ( V_2 , V_7 , & V_6 ) ;
while ( V_6 & V_8 &&
! F_3 ( V_4 , V_3 ) ) {
F_4 ( 10 ) ;
F_2 ( V_2 , V_7 , & V_6 ) ;
}
if ( V_6 & V_8 )
F_5 ( & V_2 -> V_9 , L_1 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_9 , * V_14 , * V_2 = V_13 -> V_9 -> V_15 ;
struct V_16 * V_17 = V_2 -> V_18 ;
F_8 () ;
F_9 (dev, temp, &parent->devices,
bus_list) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_12 ( V_9 ) ;
}
F_13 () ;
F_1 ( V_2 ) ;
F_14 ( V_2 , V_13 -> V_19 + V_20 ,
V_21 | V_22 ) ;
}
static T_2 F_15 ( int V_23 , void * V_24 )
{
struct V_12 * V_13 = (struct V_12 * ) V_24 ;
struct V_1 * V_2 = V_13 -> V_9 -> V_15 ;
T_1 V_25 , V_26 ;
F_16 ( V_2 , V_13 -> V_19 + V_20 , & V_25 ) ;
F_16 ( V_2 , V_13 -> V_19 + V_27 ,
& V_26 ) ;
if ( ! V_25 )
return V_28 ;
F_17 ( & V_13 -> V_9 -> V_29 , L_2 ,
V_25 , V_26 ) ;
if ( V_25 & V_21 ) {
T_1 V_30 = ( V_25 >> 1 ) & 0x3 ;
F_5 ( & V_13 -> V_9 -> V_29 , L_3 ,
( V_30 == 0 ) ? L_4 :
( V_30 == 1 ) ? L_5 :
( V_30 == 2 ) ? L_6 : L_7 ) ;
F_18 ( & V_13 -> V_11 ) ;
}
return V_31 ;
}
static int F_19 ( struct V_32 * V_9 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 = V_9 -> V_15 ;
int V_25 ;
T_1 V_33 , V_34 ;
V_13 = F_20 ( sizeof( * V_13 ) , V_35 ) ;
if ( ! V_13 )
return - V_36 ;
V_13 -> V_19 = F_21 ( V_2 , V_37 ) ;
V_13 -> V_9 = V_9 ;
F_22 ( & V_13 -> V_11 , F_6 ) ;
F_23 ( V_9 , V_13 ) ;
V_25 = F_24 ( V_9 -> V_23 , F_15 , V_38 , L_8 , V_13 ) ;
if ( V_25 ) {
F_5 ( & V_9 -> V_29 , L_9 , V_9 -> V_23 ,
V_25 ) ;
goto V_39;
}
F_16 ( V_2 , V_13 -> V_19 + V_40 , & V_34 ) ;
F_16 ( V_2 , V_13 -> V_19 + V_41 , & V_33 ) ;
V_33 |= V_42 | V_43 ;
F_14 ( V_2 , V_13 -> V_19 + V_41 , V_33 ) ;
F_17 ( & V_9 -> V_29 , L_10 ,
V_34 & 0xf , F_25 ( V_34 , V_44 ) ,
F_25 ( V_34 , V_45 ) ,
F_25 ( V_34 , V_46 ) , ( V_34 >> 8 ) & 0xf ,
F_25 ( V_34 , V_47 ) ) ;
return V_25 ;
V_39:
F_26 ( V_13 ) ;
return V_25 ;
}
static void F_27 ( struct V_32 * V_9 )
{
struct V_12 * V_13 = F_28 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_15 ;
T_1 V_33 ;
F_16 ( V_2 , V_13 -> V_19 + V_41 , & V_33 ) ;
V_33 &= ~ ( V_42 | V_43 ) ;
F_14 ( V_2 , V_13 -> V_19 + V_41 , V_33 ) ;
F_29 ( V_9 -> V_23 , V_13 ) ;
F_26 ( V_13 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_48 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_48 ) ;
}
