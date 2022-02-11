static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_2 , & V_4 -> V_6 ) ;
F_3 ( V_2 , V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 )
{
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_11 ;
T_1 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
if ( ! V_4 -> V_15 ) {
F_6 ( V_2 -> V_2 , L_1 ) ;
return - V_16 ;
}
V_12 = V_4 -> V_15 -> V_17 ;
V_14 = V_18 ;
V_11 = V_4 -> V_19 ;
V_13 = ( V_11 * V_20 ) / V_21 ;
V_13 *= V_14 ;
V_13 /= V_12 ;
V_13 /= V_14 ;
if ( V_13 > ( unsigned long long ) V_22 ||
V_13 < ( unsigned long long ) V_23 )
return - V_24 ;
else {
V_13 &= V_25 ;
F_7 ( V_26 ,
( V_13 << V_27 ) | ( V_13 ) ) ;
}
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_28 ) ;
int V_29 = V_9 -> V_30 . V_31 ;
if ( V_29 < 1 )
V_29 = 1 ;
F_10 ( V_2 , V_29 ) ;
V_10 = V_29 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_32 ;
struct V_33 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_33 ) ) ;
V_30 . V_34 = 100 ;
V_30 . type = V_35 ;
V_28 = F_12 ( L_2 ,
NULL , ( void * ) V_2 , & V_36 , & V_30 ) ;
if ( F_13 ( V_28 ) )
return F_14 ( V_28 ) ;
V_32 = F_5 ( V_2 ) ;
if ( V_32 < 0 ) {
F_15 ( V_28 ) ;
V_28 = NULL ;
return V_32 ;
}
V_28 -> V_30 . V_31 = 100 ;
V_28 -> V_30 . V_34 = 100 ;
F_16 ( V_28 ) ;
V_4 -> V_8 = V_28 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_37 = F_18 ( V_38 ) ;
V_37 &= ~ 3 ;
V_37 |= 1 ;
F_19 ( V_37 , V_38 ) ;
F_18 ( V_38 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_4 -> V_43 = F_21 ( V_44 ) ;
V_4 -> V_45 = F_21 ( V_46 ) ;
V_4 -> V_47 = F_21 ( V_48 ) ;
V_4 -> V_49 = F_21 ( V_50 ) ;
V_4 -> V_51 = F_21 ( V_52 ) ;
V_4 -> V_53 = F_21 ( V_54 ) ;
V_4 -> V_55 = F_21 ( V_56 ) ;
V_4 -> V_57 = F_21 ( V_58 ) ;
F_22 ( & V_2 -> V_59 . V_60 ) ;
F_23 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_24 ( V_40 ) )
V_40 -> V_61 -> V_62 ( V_40 ) ;
}
F_23 (connector, &dev->mode_config.connector_list, head)
V_42 -> V_61 -> V_62 ( V_42 ) ;
F_25 ( & V_2 -> V_59 . V_60 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
int V_63 ;
F_27 ( V_4 -> V_43 , V_44 ) ;
F_27 ( V_4 -> V_45 , V_46 ) ;
F_27 ( V_4 -> V_47 , V_48 ) ;
F_27 ( V_4 -> V_49 , V_50 ) ;
F_27 ( V_4 -> V_51 , V_52 ) ;
F_27 ( V_4 -> V_53 , V_54 ) ;
F_27 ( V_4 -> V_55 , V_56 ) ;
F_27 ( V_4 -> V_57 , V_58 ) ;
F_27 ( 0x80000000 , V_64 ) ;
F_22 ( & V_2 -> V_59 . V_60 ) ;
F_23 (crtc, &dev->mode_config.crtc_list, head)
if ( F_24 ( V_40 ) )
V_40 -> V_61 -> V_65 ( V_40 ) ;
F_23 (connector, &dev->mode_config.connector_list, head)
V_42 -> V_61 -> V_65 ( V_42 ) ;
F_25 ( & V_2 -> V_59 . V_60 ) ;
if ( V_4 -> V_66 ) {
F_27 ( 0 , V_67 ) ;
do {
V_63 = F_21 ( V_68 ) ;
} while ( V_63 & 0x80000000 );
F_27 ( 0x58000000 , V_69 ) ;
F_27 ( 0 , V_70 ) ;
F_28 ( 4 ) ;
F_27 ( 0x0 , V_71 ) ;
F_28 ( 8 ) ;
F_27 ( 0 , V_72 ) ;
} else {
F_27 ( V_73 , V_74 ) ;
F_27 ( 0x0 , V_71 ) ;
F_27 ( 0x2faf0000 , V_26 ) ;
while ( F_29 ( 0x70008 ) & 0x40000000 )
F_30 () ;
while ( ( F_21 ( V_75 ) & V_76 )
!= V_76 )
F_30 () ;
F_27 ( 0 , V_77 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_2 clock ;
struct V_78 * V_79 = F_34 ( 0 , 0 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_35 ( V_79 , 0xD0 , 0xD0050300 ) ;
F_36 ( V_79 , 0xD4 , & clock ) ;
F_37 ( V_79 ) ;
switch ( clock & 0x07 ) {
case 0 :
V_4 -> V_19 = 100 ;
break;
case 1 :
V_4 -> V_19 = 133 ;
break;
case 2 :
V_4 -> V_19 = 150 ;
break;
case 3 :
V_4 -> V_19 = 178 ;
break;
case 4 :
V_4 -> V_19 = 200 ;
break;
case 5 :
case 6 :
case 7 :
V_4 -> V_19 = 266 ;
default:
V_4 -> V_19 = 0 ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
