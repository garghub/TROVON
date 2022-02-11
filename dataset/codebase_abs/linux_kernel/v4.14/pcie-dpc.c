static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
struct V_10 * V_8 = & V_2 -> V_8 -> V_10 ;
T_1 V_11 ;
F_2 ( V_7 , V_2 -> V_12 + V_13 , & V_11 ) ;
while ( V_11 & V_14 &&
! F_3 ( V_4 , V_3 ) ) {
F_4 ( 10 ) ;
F_2 ( V_7 , V_2 -> V_12 + V_13 , & V_11 ) ;
}
if ( V_11 & V_14 ) {
F_5 ( V_8 , L_1 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
struct V_10 * V_8 = & V_2 -> V_8 -> V_10 ;
T_1 V_16 ;
F_7 ( V_7 , V_17 , & V_16 ) ;
while ( V_16 & V_18 &&
! F_3 ( V_4 , V_3 ) ) {
F_4 ( 10 ) ;
F_7 ( V_7 , V_17 , & V_16 ) ;
}
if ( V_16 & V_18 )
F_5 ( V_8 , L_2 ) ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_9 ( V_20 , struct V_1 , V_20 ) ;
struct V_6 * V_8 , * V_21 , * V_7 = V_2 -> V_8 -> V_9 ;
struct V_22 * V_23 = V_7 -> V_24 ;
F_10 () ;
F_11 (dev, temp, &parent->devices,
bus_list) {
F_12 ( V_8 ) ;
F_13 ( V_8 , NULL ) ;
if ( F_14 ( V_8 ) )
F_15 ( V_8 -> V_24 ,
F_13 , NULL ) ;
F_16 ( V_8 ) ;
F_17 ( V_8 ) ;
}
F_18 () ;
F_6 ( V_2 ) ;
if ( V_2 -> V_25 && F_1 ( V_2 ) )
return;
if ( V_2 -> V_25 && V_2 -> V_26 ) {
F_19 ( V_7 ,
V_2 -> V_12 + V_27 ,
V_2 -> V_26 ) ;
V_2 -> V_26 = 0 ;
}
F_20 ( V_7 , V_2 -> V_12 + V_13 ,
V_28 | V_29 ) ;
}
static void F_21 ( struct V_10 * V_8 ,
struct V_30 * V_31 )
{
F_22 ( V_8 , L_3 ,
V_31 -> V_32 , V_31 -> V_33 , V_31 -> V_34 , V_31 -> V_35 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_10 * V_8 = & V_2 -> V_8 -> V_10 ;
int V_38 ;
T_2 V_11 ;
F_22 ( V_8 , L_4 ,
V_37 -> V_11 , V_37 -> V_39 ) ;
F_22 ( V_8 , L_5 ,
V_37 -> V_40 , V_37 -> V_41 , V_37 -> V_42 ) ;
V_11 = ( V_37 -> V_11 & ~ V_37 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < F_24 ( V_43 ) ; V_38 ++ ) {
if ( ! ( V_11 & ( 1 << V_38 ) ) )
continue;
F_22 ( V_8 , L_6 , V_38 , V_43 [ V_38 ] ,
V_37 -> V_44 == V_38 ? L_7 : L_8 ) ;
}
F_21 ( V_8 , & V_37 -> V_45 ) ;
if ( V_37 -> V_46 == 4 )
return;
F_22 ( V_8 , L_9 , V_37 -> V_47 ) ;
for ( V_38 = 0 ; V_38 < V_37 -> V_46 - 5 ; V_38 ++ )
F_22 ( V_8 , L_10 , V_38 ,
V_37 -> V_48 [ V_38 ] ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
struct V_10 * V_8 = & V_2 -> V_8 -> V_10 ;
int V_38 ;
T_1 V_49 ;
T_1 V_11 ;
F_26 ( V_7 , V_2 -> V_12 + V_27 ,
& V_37 -> V_11 ) ;
F_26 ( V_7 , V_2 -> V_12 + V_50 ,
& V_37 -> V_39 ) ;
F_26 ( V_7 , V_2 -> V_12 + V_51 ,
& V_37 -> V_40 ) ;
F_26 ( V_7 , V_2 -> V_12 + V_52 ,
& V_37 -> V_41 ) ;
F_26 ( V_7 , V_2 -> V_12 + V_53 ,
& V_37 -> V_42 ) ;
F_2 ( V_7 , V_2 -> V_12 + V_13 , & V_11 ) ;
V_37 -> V_44 = ( V_11 & 0x1f00 ) >> 8 ;
F_2 ( V_7 , V_2 -> V_12 + V_54 , & V_49 ) ;
V_37 -> V_46 = ( V_49 & V_55 ) >> 8 ;
if ( V_37 -> V_46 < 4 || V_37 -> V_46 > 9 ) {
F_22 ( V_8 , L_11 ,
V_37 -> V_46 ) ;
return;
}
F_26 ( V_7 ,
V_2 -> V_12 + V_56 ,
& V_37 -> V_45 . V_32 ) ;
F_26 ( V_7 ,
V_2 -> V_12 + V_56 + 4 ,
& V_37 -> V_45 . V_33 ) ;
F_26 ( V_7 ,
V_2 -> V_12 + V_56 + 8 ,
& V_37 -> V_45 . V_34 ) ;
F_26 ( V_7 ,
V_2 -> V_12 + V_56 + 12 ,
& V_37 -> V_45 . V_35 ) ;
if ( V_37 -> V_46 == 4 )
return;
F_26 ( V_7 ,
V_2 -> V_12 + V_57 ,
& V_37 -> V_47 ) ;
for ( V_38 = 0 ; V_38 < V_37 -> V_46 - 5 ; V_38 ++ )
F_26 ( V_7 ,
V_2 -> V_12 + V_58 ,
& V_37 -> V_48 [ V_38 ] ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_36 V_59 ;
F_25 ( V_2 , & V_59 ) ;
F_23 ( V_2 , & V_59 ) ;
V_2 -> V_26 = V_59 . V_11 ;
}
static T_3 F_28 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
struct V_10 * V_8 = & V_2 -> V_8 -> V_10 ;
T_1 V_11 , V_62 ;
F_2 ( V_7 , V_2 -> V_12 + V_13 , & V_11 ) ;
F_2 ( V_7 , V_2 -> V_12 + V_63 ,
& V_62 ) ;
if ( ! V_11 || V_11 == ( T_1 ) ( ~ 0 ) )
return V_64 ;
F_29 ( V_8 , L_12 ,
V_11 , V_62 ) ;
if ( V_11 & V_28 ) {
T_1 V_65 = ( V_11 >> 1 ) & 0x3 ;
T_1 V_66 = ( V_11 >> 5 ) & 0x3 ;
F_5 ( V_8 , L_13 ,
( V_65 == 0 ) ? L_14 :
( V_65 == 1 ) ? L_15 :
( V_65 == 2 ) ? L_16 :
( V_66 == 0 ) ? L_17 :
( V_66 == 1 ) ? L_18 :
L_19 ) ;
if ( V_65 == 3 && V_66 == 0 )
F_27 ( V_2 ) ;
F_30 ( & V_2 -> V_20 ) ;
}
return V_67 ;
}
static int F_31 ( struct V_68 * V_8 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_8 -> V_9 ;
struct V_10 * V_10 = & V_8 -> V_10 ;
int V_11 ;
T_1 V_69 , V_49 ;
V_2 = F_32 ( V_10 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_12 = F_33 ( V_7 , V_72 ) ;
V_2 -> V_8 = V_8 ;
F_34 ( & V_2 -> V_20 , F_8 ) ;
F_35 ( V_8 , V_2 ) ;
V_11 = F_36 ( V_10 , V_8 -> V_60 , F_28 , V_73 ,
L_20 , V_2 ) ;
if ( V_11 ) {
F_5 ( V_10 , L_21 , V_8 -> V_60 ,
V_11 ) ;
return V_11 ;
}
F_2 ( V_7 , V_2 -> V_12 + V_54 , & V_49 ) ;
F_2 ( V_7 , V_2 -> V_12 + V_74 , & V_69 ) ;
V_2 -> V_25 = ( V_49 & V_75 ) ;
V_69 = ( V_69 & 0xfff4 ) | V_76 | V_77 ;
F_20 ( V_7 , V_2 -> V_12 + V_74 , V_69 ) ;
F_29 ( V_10 , L_22 ,
V_49 & 0xf , F_37 ( V_49 , V_75 ) ,
F_37 ( V_49 , V_78 ) ,
F_37 ( V_49 , V_79 ) , ( V_49 >> 8 ) & 0xf ,
F_37 ( V_49 , V_80 ) ) ;
return V_11 ;
}
static void F_38 ( struct V_68 * V_8 )
{
struct V_1 * V_2 = F_39 ( V_8 ) ;
struct V_6 * V_7 = V_8 -> V_9 ;
T_1 V_69 ;
F_2 ( V_7 , V_2 -> V_12 + V_74 , & V_69 ) ;
V_69 &= ~ ( V_76 | V_77 ) ;
F_20 ( V_7 , V_2 -> V_12 + V_74 , V_69 ) ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_81 ) ;
}
