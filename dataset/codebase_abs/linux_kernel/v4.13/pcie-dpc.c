static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_10 ;
F_2 ( V_7 , V_2 -> V_11 + V_12 , & V_10 ) ;
while ( V_10 & V_13 &&
! F_3 ( V_4 , V_3 ) ) {
F_4 ( 10 ) ;
F_2 ( V_7 , V_2 -> V_11 + V_12 , & V_10 ) ;
}
if ( V_10 & V_13 ) {
F_5 ( & V_7 -> V_8 , L_1 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_6 ( struct V_6 * V_7 )
{
unsigned long V_3 = V_4 + V_5 ;
T_1 V_15 ;
F_7 ( V_7 , V_16 , & V_15 ) ;
while ( V_15 & V_17 &&
! F_3 ( V_4 , V_3 ) ) {
F_4 ( 10 ) ;
F_7 ( V_7 , V_16 , & V_15 ) ;
}
if ( V_15 & V_17 )
F_5 ( & V_7 -> V_8 , L_2 ) ;
}
static void F_8 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 , struct V_1 , V_19 ) ;
struct V_6 * V_8 , * V_20 , * V_7 = V_2 -> V_8 -> V_9 ;
struct V_21 * V_22 = V_7 -> V_23 ;
F_10 () ;
F_11 (dev, temp, &parent->devices,
bus_list) {
F_12 ( V_8 ) ;
F_13 ( V_8 , NULL ) ;
if ( F_14 ( V_8 ) )
F_15 ( V_8 -> V_23 ,
F_13 , NULL ) ;
F_16 ( V_8 ) ;
F_17 ( V_8 ) ;
}
F_18 () ;
F_6 ( V_7 ) ;
if ( V_2 -> V_24 && F_1 ( V_2 ) )
return;
F_19 ( V_7 , V_2 -> V_11 + V_12 ,
V_25 | V_26 ) ;
}
static T_2 F_20 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_10 , V_29 ;
F_2 ( V_7 , V_2 -> V_11 + V_12 , & V_10 ) ;
F_2 ( V_7 , V_2 -> V_11 + V_30 ,
& V_29 ) ;
if ( ! V_10 || V_10 == ( T_1 ) ( ~ 0 ) )
return V_31 ;
F_21 ( & V_2 -> V_8 -> V_32 , L_3 ,
V_10 , V_29 ) ;
if ( V_10 & V_25 ) {
T_1 V_33 = ( V_10 >> 1 ) & 0x3 ;
T_1 V_34 = ( V_10 >> 5 ) & 0x3 ;
F_5 ( & V_2 -> V_8 -> V_32 , L_4 ,
( V_33 == 0 ) ? L_5 :
( V_33 == 1 ) ? L_6 :
( V_33 == 2 ) ? L_7 :
( V_34 == 0 ) ? L_8 :
( V_34 == 1 ) ? L_9 :
L_10 ) ;
F_22 ( & V_2 -> V_19 ) ;
}
return V_35 ;
}
static int F_23 ( struct V_36 * V_8 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_8 -> V_9 ;
int V_10 ;
T_1 V_37 , V_38 ;
V_2 = F_24 ( & V_8 -> V_32 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_11 = F_25 ( V_7 , V_41 ) ;
V_2 -> V_8 = V_8 ;
F_26 ( & V_2 -> V_19 , F_8 ) ;
F_27 ( V_8 , V_2 ) ;
V_10 = F_28 ( & V_8 -> V_32 , V_8 -> V_27 , F_20 , V_42 ,
L_11 , V_2 ) ;
if ( V_10 ) {
F_5 ( & V_8 -> V_32 , L_12 , V_8 -> V_27 ,
V_10 ) ;
return V_10 ;
}
F_2 ( V_7 , V_2 -> V_11 + V_43 , & V_38 ) ;
F_2 ( V_7 , V_2 -> V_11 + V_44 , & V_37 ) ;
V_2 -> V_24 = ( V_38 & V_45 ) ;
V_37 = ( V_37 & 0xfff4 ) | V_46 | V_47 ;
F_19 ( V_7 , V_2 -> V_11 + V_44 , V_37 ) ;
F_21 ( & V_8 -> V_32 , L_13 ,
V_38 & 0xf , F_29 ( V_38 , V_45 ) ,
F_29 ( V_38 , V_48 ) ,
F_29 ( V_38 , V_49 ) , ( V_38 >> 8 ) & 0xf ,
F_29 ( V_38 , V_50 ) ) ;
return V_10 ;
}
static void F_30 ( struct V_36 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_6 * V_7 = V_8 -> V_9 ;
T_1 V_37 ;
F_2 ( V_7 , V_2 -> V_11 + V_44 , & V_37 ) ;
V_37 &= ~ ( V_46 | V_47 ) ;
F_19 ( V_7 , V_2 -> V_11 + V_44 , V_37 ) ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_51 ) ;
}
