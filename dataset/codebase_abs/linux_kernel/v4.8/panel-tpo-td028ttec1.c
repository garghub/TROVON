static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
T_2 V_5 = V_6 | V_3 ;
V_4 = F_2 ( V_2 -> V_7 , ( T_1 * ) & V_5 ,
1 * sizeof( T_2 ) ) ;
if ( V_4 != 0 )
F_3 ( & V_2 -> V_7 -> V_8 ,
L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
int V_4 ;
T_2 V_5 [ 2 ] ;
V_5 [ 0 ] = V_6 | V_3 ;
V_5 [ 1 ] = V_10 | V_9 ;
V_4 = F_2 ( V_2 -> V_7 , ( T_1 * ) V_5 ,
2 * sizeof( T_2 ) ) ;
if ( V_4 != 0 )
F_3 ( & V_2 -> V_7 -> V_8 ,
L_2 , V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_9 )
{
int V_4 ;
T_2 V_5 [ 3 ] ;
V_5 [ 0 ] = V_6 | V_3 ;
V_5 [ 1 ] = V_10 | ( V_9 >> 8 ) ;
V_5 [ 2 ] = V_10 | ( V_9 & 0xff ) ;
V_4 = F_2 ( V_2 -> V_7 , ( T_1 * ) V_5 ,
3 * sizeof( T_2 ) ) ;
if ( V_4 != 0 )
F_3 ( & V_2 -> V_7 -> V_8 ,
L_3 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_11 * V_13 = V_2 -> V_13 ;
int V_14 ;
if ( F_8 ( V_12 ) )
return 0 ;
V_14 = V_13 -> V_15 . V_16 -> V_17 ( V_13 , V_12 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_11 * V_13 = V_2 -> V_13 ;
if ( ! F_8 ( V_12 ) )
return;
V_13 -> V_15 . V_16 -> V_18 ( V_13 , V_12 ) ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_11 * V_13 = V_2 -> V_13 ;
int V_14 ;
if ( ! F_8 ( V_12 ) )
return - V_19 ;
if ( F_11 ( V_12 ) )
return 0 ;
if ( V_2 -> V_20 )
V_13 -> V_15 . V_16 -> V_21 ( V_13 , V_2 -> V_20 ) ;
V_13 -> V_15 . V_16 -> V_22 ( V_13 , & V_2 -> V_23 ) ;
V_14 = V_13 -> V_15 . V_16 -> V_24 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_12 ( V_12 -> V_8 , L_4 ,
V_12 -> V_25 ) ;
V_14 |= F_1 ( V_2 , 0x00 ) ;
F_13 ( 1000 , 2000 ) ;
V_14 |= F_1 ( V_2 , 0x00 ) ;
F_13 ( 1000 , 2000 ) ;
V_14 |= F_1 ( V_2 , 0x00 ) ;
F_13 ( 1000 , 2000 ) ;
if ( V_14 ) {
F_14 ( V_12 -> V_8 , L_5 ) ;
goto V_26;
}
V_14 |= F_4 ( V_2 , V_27 , 0x17 ) ;
V_14 |= F_4 ( V_2 , V_28 , 0x80 ) ;
V_14 |= F_4 ( V_2 , V_29 , 0x00 ) ;
V_14 |= F_4 ( V_2 , V_27 , 0x16 ) ;
V_14 |= F_5 ( V_2 , V_30 , 0xfff9 ) ;
V_14 |= F_1 ( V_2 , V_31 ) ;
V_14 |= F_4 ( V_2 , V_32 , 0x01 ) ;
V_14 |= F_4 ( V_2 , V_33 , 0x00 ) ;
V_14 |= F_4 ( V_2 , V_34 , 0x60 ) ;
V_14 |= F_4 ( V_2 , V_35 , 0x10 ) ;
V_14 |= F_4 ( V_2 , V_36 , 0x56 ) ;
V_14 |= F_4 ( V_2 , V_37 , 0x33 ) ;
V_14 |= F_4 ( V_2 , V_38 , 0x11 ) ;
V_14 |= F_4 ( V_2 , V_38 , 0x11 ) ;
V_14 |= F_4 ( V_2 , V_39 , 0x02 ) ;
V_14 |= F_4 ( V_2 , V_40 , 0x2b ) ;
V_14 |= F_4 ( V_2 , V_41 , 0x40 ) ;
V_14 |= F_4 ( V_2 , V_42 , 0x03 ) ;
V_14 |= F_4 ( V_2 , V_43 , 0x04 ) ;
V_14 |= F_4 ( V_2 , V_44 , 0x04 ) ;
V_14 |= F_4 ( V_2 , V_45 , 0x00 ) ;
V_14 |= F_4 ( V_2 , V_46 , 0x11 ) ;
V_14 |= F_4 ( V_2 , V_47 , 0x11 ) ;
V_14 |= F_4 ( V_2 , V_48 , 0x11 ) ;
V_14 |= F_5 ( V_2 , V_49 , 0x2040 ) ;
V_14 |= F_5 ( V_2 , V_50 , 0x60c0 ) ;
V_14 |= F_5 ( V_2 , V_51 , 0x1020 ) ;
V_14 |= F_5 ( V_2 , V_52 , 0x60c0 ) ;
V_14 |= F_5 ( V_2 , V_53 , 0x5533 ) ;
V_14 |= F_4 ( V_2 , V_54 , 0x00 ) ;
V_14 |= F_4 ( V_2 , V_55 , 0x00 ) ;
V_14 |= F_4 ( V_2 , V_56 , 0x00 ) ;
V_14 |= F_5 ( V_2 , V_57 , 0x1f0 ) ;
V_14 |= F_4 ( V_2 , V_58 , 0x02 ) ;
V_14 |= F_5 ( V_2 , V_59 , 0x0804 ) ;
V_14 |= F_4 ( V_2 , V_60 , 0x01 ) ;
V_14 |= F_5 ( V_2 , V_61 , 0x0000 ) ;
V_14 |= F_5 ( V_2 , V_62 , 0x0d0e ) ;
V_14 |= F_5 ( V_2 , V_63 , 0x11a4 ) ;
V_14 |= F_4 ( V_2 , V_64 , 0x0e ) ;
V_14 |= F_1 ( V_2 , V_65 ) ;
V_12 -> V_25 = V_66 ;
V_26:
return V_14 ? - V_67 : 0 ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_11 * V_13 = V_2 -> V_13 ;
if ( ! F_11 ( V_12 ) )
return;
F_12 ( V_12 -> V_8 , L_6 ) ;
F_1 ( V_2 , V_68 ) ;
F_5 ( V_2 , V_30 , 0x8002 ) ;
F_1 ( V_2 , V_69 ) ;
F_4 ( V_2 , V_27 , 0x00 ) ;
V_13 -> V_15 . V_16 -> V_70 ( V_13 ) ;
V_12 -> V_25 = V_71 ;
}
static void F_16 ( struct V_11 * V_12 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_11 * V_13 = V_2 -> V_13 ;
V_2 -> V_23 = * V_73 ;
V_12 -> V_74 . V_73 = * V_73 ;
V_13 -> V_15 . V_16 -> V_22 ( V_13 , V_73 ) ;
}
static void F_17 ( struct V_11 * V_12 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
* V_73 = V_2 -> V_23 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_11 * V_13 = V_2 -> V_13 ;
return V_13 -> V_15 . V_16 -> V_75 ( V_13 , V_73 ) ;
}
static int F_19 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_8 . V_80 ;
struct V_1 * V_2 = F_20 ( & V_77 -> V_8 ) ;
struct V_11 * V_13 ;
V_13 = F_21 ( V_79 ) ;
if ( F_22 ( V_13 ) ) {
F_3 ( & V_77 -> V_8 , L_7 ) ;
return F_23 ( V_13 ) ;
}
V_2 -> V_13 = V_13 ;
return 0 ;
}
static int F_24 ( struct V_76 * V_77 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_14 ;
F_12 ( & V_77 -> V_8 , L_8 , V_81 ) ;
V_77 -> V_82 = 9 ;
V_77 -> V_83 = V_84 ;
V_14 = F_25 ( V_77 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_77 -> V_8 , L_9 , V_14 ) ;
return V_14 ;
}
V_2 = F_26 ( & V_77 -> V_8 , sizeof( * V_2 ) , V_85 ) ;
if ( V_2 == NULL )
return - V_86 ;
F_27 ( & V_77 -> V_8 , V_2 ) ;
V_2 -> V_7 = V_77 ;
if ( ! V_77 -> V_8 . V_80 )
return - V_19 ;
V_14 = F_19 ( V_77 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_23 = V_87 ;
V_12 = & V_2 -> V_12 ;
V_12 -> V_8 = & V_77 -> V_8 ;
V_12 -> V_88 = & V_89 ;
V_12 -> type = V_90 ;
V_12 -> V_91 = V_92 ;
V_12 -> V_74 . V_73 = V_2 -> V_23 ;
V_12 -> V_93 . V_16 . V_20 = V_2 -> V_20 ;
V_14 = F_28 ( V_12 ) ;
if ( V_14 ) {
F_3 ( & V_77 -> V_8 , L_10 ) ;
goto V_94;
}
return 0 ;
V_94:
F_29 ( V_2 -> V_13 ) ;
return V_14 ;
}
static int F_30 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_20 ( & V_77 -> V_8 ) ;
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_11 * V_13 = V_2 -> V_13 ;
F_12 ( & V_2 -> V_7 -> V_8 , L_8 , V_81 ) ;
F_31 ( V_12 ) ;
F_15 ( V_12 ) ;
F_9 ( V_12 ) ;
F_29 ( V_13 ) ;
return 0 ;
}
