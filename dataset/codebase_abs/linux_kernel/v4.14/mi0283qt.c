static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
T_1 V_9 ;
int V_10 ;
F_2 ( L_1 ) ;
V_10 = F_3 ( V_2 -> V_11 ) ;
if ( V_10 ) {
F_4 ( V_7 , L_2 , V_10 ) ;
return V_10 ;
}
if ( F_5 ( V_2 ) )
return 0 ;
F_6 ( V_2 ) ;
V_10 = F_7 ( V_2 , V_12 ) ;
if ( V_10 ) {
F_4 ( V_7 , L_3 , V_10 ) ;
F_8 ( V_2 -> V_11 ) ;
return V_10 ;
}
F_9 ( 20 ) ;
F_7 ( V_2 , V_13 ) ;
F_7 ( V_2 , V_14 , 0x00 , 0x83 , 0x30 ) ;
F_7 ( V_2 , V_15 , 0x64 , 0x03 , 0x12 , 0x81 ) ;
F_7 ( V_2 , V_16 , 0x85 , 0x01 , 0x79 ) ;
F_7 ( V_2 , V_17 , 0x39 , 0x2c , 0x00 , 0x34 , 0x02 ) ;
F_7 ( V_2 , V_18 , 0x20 ) ;
F_7 ( V_2 , V_19 , 0x00 , 0x00 ) ;
F_7 ( V_2 , V_20 , 0x26 ) ;
F_7 ( V_2 , V_21 , 0x11 ) ;
F_7 ( V_2 , V_22 , 0x35 , 0x3e ) ;
F_7 ( V_2 , V_23 , 0xbe ) ;
F_7 ( V_2 , V_24 , 0x55 ) ;
switch ( V_2 -> V_25 ) {
default:
V_9 = V_26 | V_27 |
V_28 ;
break;
case 90 :
V_9 = V_27 ;
break;
case 180 :
V_9 = V_26 ;
break;
case 270 :
V_9 = V_28 ;
break;
}
V_9 |= V_29 ;
F_7 ( V_2 , V_30 , V_9 ) ;
F_7 ( V_2 , V_31 , 0x00 , 0x1b ) ;
F_7 ( V_2 , V_32 , 0x08 ) ;
F_7 ( V_2 , V_33 , 0x01 ) ;
F_7 ( V_2 , V_34 ,
0x1f , 0x1a , 0x18 , 0x0a , 0x0f , 0x06 , 0x45 , 0x87 ,
0x32 , 0x0a , 0x07 , 0x02 , 0x07 , 0x05 , 0x00 ) ;
F_7 ( V_2 , V_35 ,
0x00 , 0x25 , 0x27 , 0x05 , 0x10 , 0x09 , 0x3a , 0x78 ,
0x4d , 0x05 , 0x18 , 0x0d , 0x38 , 0x3a , 0x1f ) ;
F_7 ( V_2 , V_36 , 0x07 ) ;
F_7 ( V_2 , V_37 , 0x0a , 0x82 , 0x27 , 0x00 ) ;
F_7 ( V_2 , V_38 ) ;
F_9 ( 100 ) ;
F_7 ( V_2 , V_39 ) ;
F_9 ( 100 ) ;
return 0 ;
}
static void F_10 ( void * V_40 )
{
struct V_1 * V_2 = V_40 ;
F_2 ( L_1 ) ;
F_8 ( V_2 -> V_11 ) ;
}
static int F_11 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = & V_42 -> V_7 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
T_2 V_25 = 0 ;
int V_10 ;
V_2 = F_12 ( V_7 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_47 = F_13 ( V_7 , L_4 , V_48 ) ;
if ( F_14 ( V_2 -> V_47 ) ) {
F_4 ( V_7 , L_5 ) ;
return F_15 ( V_2 -> V_47 ) ;
}
V_44 = F_13 ( V_7 , L_6 , V_49 ) ;
if ( F_14 ( V_44 ) ) {
F_4 ( V_7 , L_7 ) ;
return F_15 ( V_44 ) ;
}
V_2 -> V_11 = F_16 ( V_7 , L_8 ) ;
if ( F_14 ( V_2 -> V_11 ) )
return F_15 ( V_2 -> V_11 ) ;
V_2 -> V_50 = F_17 ( V_7 ) ;
if ( F_14 ( V_2 -> V_50 ) )
return F_15 ( V_2 -> V_50 ) ;
F_18 ( V_7 , L_9 , & V_25 ) ;
V_10 = F_19 ( V_42 , V_2 , V_44 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_20 ( & V_42 -> V_7 , V_2 , & V_51 ,
& V_52 , & V_53 , V_25 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_21 ( V_7 , F_10 , V_2 ) ;
if ( V_10 ) {
F_10 ( V_2 ) ;
return V_10 ;
}
V_4 = & V_2 -> V_5 ;
V_10 = F_22 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_23 ( V_42 , V_2 ) ;
F_24 ( L_10 ,
V_4 -> V_8 -> V_54 -> V_55 , F_25 ( V_7 ) ,
V_42 -> V_56 / 1000000 ,
V_4 -> V_8 -> V_57 -> V_58 ) ;
return 0 ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_27 ( V_42 ) ;
F_28 ( & V_2 -> V_5 ) ;
}
static int T_3 F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
int V_10 ;
V_10 = F_31 ( & V_2 -> V_5 ) ;
if ( V_10 )
return V_10 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
int V_10 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 )
return V_10 ;
return F_33 ( & V_2 -> V_5 ) ;
}
