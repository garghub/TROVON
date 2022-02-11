static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 , V_5 , error = 0 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_10 -> V_13 ;
if ( V_7 -> V_14 & ( 1 << V_3 ) )
return V_7 -> V_15 & ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_12 -> V_17 = V_18 ;
V_12 -> V_19 = 0x00 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_20 = 0x00 ;
V_12 -> V_21 = 0x00 ;
V_12 -> V_22 = 0x00 ;
V_12 -> V_23 = 0x00 ;
V_12 -> V_24 = 0x00 ;
V_12 -> V_25 = 0x00 ;
V_12 -> V_5 = 0x00 ;
V_12 -> V_26 = 0x00 ;
V_4 = F_4 ( V_10 -> V_27 , F_5 ( V_10 -> V_27 , 0 ) ,
V_28 , V_29 , 0x0000 ,
0x0000 , V_12 , sizeof( struct V_11 ) ,
V_30 ) ;
if ( V_4 != sizeof( struct V_11 ) )
error = - V_31 ;
V_4 = F_4 ( V_10 -> V_27 , F_6 ( V_10 -> V_27 , 0 ) ,
V_28 , V_32 , 0x0000 ,
0x0000 , V_12 , sizeof( struct V_11 ) ,
V_30 ) ;
V_5 = V_12 -> V_5 & 0x01 ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 != sizeof( struct V_11 ) )
error = - V_31 ;
if ( error )
return error ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_33 )
{
int V_4 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_10 -> V_13 ;
if ( V_7 -> V_14 & ( 1 << V_3 ) ) {
if ( V_33 )
V_7 -> V_15 |= ( 1 << V_3 ) ;
else
V_7 -> V_15 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_12 -> V_17 = V_34 ;
V_12 -> V_19 = 0x00 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_20 = 0x00 ;
V_12 -> V_21 = 0x00 ;
V_12 -> V_22 = 0x00 ;
V_12 -> V_23 = 0x00 ;
V_12 -> V_24 = V_33 ;
V_12 -> V_25 = 0x00 ;
V_12 -> V_5 = 0x00 ;
V_12 -> V_26 = 0x00 ;
V_4 = F_4 ( V_10 -> V_27 ,
F_5 ( V_10 -> V_27 , 0 ) ,
V_28 , V_29 ,
0x0000 , 0x0000 , V_12 ,
sizeof( struct V_11 ) , V_30 ) ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 != sizeof( struct V_11 ) )
F_9 ( V_2 -> V_35 , L_1 ) ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_10 -> V_13 ;
V_7 -> V_14 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_12 -> V_17 = V_36 ;
V_12 -> V_19 = V_37 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_20 = 0x00 ;
V_12 -> V_21 = 0x00 ;
V_12 -> V_22 = 0x00 ;
V_12 -> V_23 = 0x00 ;
V_12 -> V_24 = 0x00 ;
V_12 -> V_25 = 0x00 ;
V_12 -> V_5 = 0x00 ;
V_12 -> V_26 = 0x00 ;
V_4 = F_4 ( V_10 -> V_27 , F_5 ( V_10 -> V_27 , 0 ) ,
V_28 , V_29 , 0x0000 ,
0x0000 , V_12 , sizeof( struct V_11 ) ,
V_30 ) ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 != sizeof( struct V_11 ) )
return - V_31 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_33 )
{
int V_4 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_10 -> V_13 ;
V_7 -> V_14 |= ( 1 << V_3 ) ;
if ( V_33 )
V_7 -> V_15 |= ( 1 << V_3 ) ;
else
V_7 -> V_15 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_12 -> V_17 = V_34 ;
V_12 -> V_19 = 0x00 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_20 = 0x00 ;
V_12 -> V_21 = 0x00 ;
V_12 -> V_22 = 0x00 ;
V_12 -> V_23 = 0x00 ;
V_12 -> V_24 = V_33 ;
V_12 -> V_25 = 0x00 ;
V_12 -> V_5 = 0x00 ;
V_12 -> V_26 = 0x00 ;
V_4 = F_4 ( V_10 -> V_27 , F_5 ( V_10 -> V_27 , 0 ) ,
V_28 , V_29 , 0x0000 ,
0x0000 , V_12 , sizeof( struct V_11 ) ,
V_30 ) ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 != sizeof( struct V_11 ) )
return - V_31 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 , unsigned V_3 ,
unsigned V_38 )
{
struct V_39 * V_40 = (struct V_39 * ) V_10 -> V_13 ;
int V_4 ;
V_40 -> V_17 = V_41 ;
V_40 -> V_42 = F_13 ( V_38 << V_3 ) ;
V_40 -> V_43 = F_13 ( 0x0001 << V_3 ) ;
V_4 = F_4 ( V_10 -> V_27 , F_5 ( V_10 -> V_27 , 0 ) ,
V_44 , V_29 , 0x0000 ,
0x0000 , V_40 , sizeof( struct V_39 ) ,
V_30 ) ;
if ( V_4 != sizeof( struct V_39 ) )
return - V_31 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
T_1 V_42 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_45 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_39 * V_40 = (struct V_39 * ) V_10 -> V_13 ;
if ( V_7 -> V_46 & ( 1 << V_3 ) )
return V_7 -> V_47 & ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_4 = F_4 ( V_10 -> V_27 , F_6 ( V_10 -> V_27 , 0 ) ,
V_44 , V_32 , 0x0000 ,
0x0000 , V_40 , sizeof( struct V_39 ) ,
V_30 ) ;
V_42 = V_40 -> V_42 ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 != sizeof( struct V_39 ) )
return V_4 ;
V_7 -> V_47 = F_15 ( V_42 ) ;
return ( V_7 -> V_47 >> V_3 ) & 0x1 ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned V_3 , int V_33 )
{
int V_4 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_45 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_39 * V_40 = (struct V_39 * ) V_10 -> V_13 ;
if ( V_7 -> V_46 & ( 1 << V_3 ) ) {
if ( V_33 )
V_7 -> V_47 |= ( 1 << V_3 ) ;
else
V_7 -> V_47 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_40 -> V_17 = V_48 ;
V_40 -> V_42 = F_13 ( V_33 << V_3 ) ;
V_40 -> V_43 = F_13 ( 0x0001 << V_3 ) ;
V_4 = F_4 ( V_10 -> V_27 ,
F_5 ( V_10 -> V_27 , 0 ) ,
V_44 , V_29 ,
0x0000 , 0x0000 , V_40 ,
sizeof( struct V_39 ) , V_30 ) ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 != sizeof( struct V_39 ) )
F_9 ( V_2 -> V_35 , L_1 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_45 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
V_7 -> V_46 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_4 = F_12 ( V_10 , V_3 , 0 ) ;
F_7 ( & V_10 -> V_16 ) ;
if ( V_4 )
F_9 ( V_2 -> V_35 , L_2 ) ;
return V_4 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_3 , int V_33 )
{
int V_4 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_45 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
V_7 -> V_46 |= ( 1 << V_3 ) ;
F_3 ( & V_10 -> V_16 ) ;
V_4 = F_12 ( V_10 , V_3 , 1 ) ;
if ( V_4 )
F_9 ( V_2 -> V_35 , L_3 ) ;
F_7 ( & V_10 -> V_16 ) ;
F_16 ( V_2 , V_3 , V_33 ) ;
return V_4 ;
}
static int F_19 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 -> V_35 . V_51 ) ;
struct V_6 * V_52 ;
int V_4 ;
V_52 = F_21 ( & V_50 -> V_35 , sizeof( * V_52 ) , V_53 ) ;
if ( V_52 == NULL )
return - V_54 ;
V_52 -> V_10 = V_10 ;
V_52 -> V_8 . V_55 = L_4 ;
V_52 -> V_8 . V_35 = & V_50 -> V_35 ;
V_52 -> V_8 . V_56 = V_57 ;
V_52 -> V_8 . V_58 = - 1 ;
V_52 -> V_8 . V_59 = 16 ;
V_52 -> V_8 . V_60 = true ;
V_52 -> V_8 . V_61 = F_8 ;
V_52 -> V_8 . V_62 = F_1 ;
V_52 -> V_8 . V_63 = F_10 ;
V_52 -> V_8 . V_64 = F_11 ;
V_4 = F_22 ( & V_52 -> V_8 ) ;
if ( V_4 < 0 ) {
F_9 ( V_52 -> V_8 . V_35 , L_5 ) ;
goto V_65;
}
V_52 -> V_45 . V_55 = L_6 ;
V_52 -> V_45 . V_35 = & V_50 -> V_35 ;
V_52 -> V_45 . V_56 = V_57 ;
V_52 -> V_45 . V_58 = - 1 ;
V_52 -> V_45 . V_59 = 16 ;
V_52 -> V_45 . V_60 = true ;
V_52 -> V_45 . V_61 = F_16 ;
V_52 -> V_45 . V_62 = F_14 ;
V_52 -> V_45 . V_63 = F_17 ;
V_52 -> V_45 . V_64 = F_18 ;
V_4 = F_22 ( & V_52 -> V_45 ) ;
if ( V_4 < 0 ) {
F_9 ( V_52 -> V_45 . V_35 , L_7 ) ;
goto V_66;
}
F_23 ( V_50 , V_52 ) ;
return V_4 ;
V_66:
F_24 ( & V_52 -> V_8 ) ;
V_65:
return V_4 ;
}
static int F_25 ( struct V_49 * V_50 )
{
struct V_6 * V_52 = F_26 ( V_50 ) ;
F_24 ( & V_52 -> V_45 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
switch ( V_67 ) {
case 1000000 :
V_37 = V_68 ;
break;
case 100000 :
V_37 = V_69 ;
break;
case 10000 :
V_37 = V_70 ;
break;
case 1000 :
V_37 = V_71 ;
break;
case 100 :
V_37 = V_72 ;
break;
case 10 :
V_37 = V_73 ;
break;
default:
F_28 ( L_8 , V_67 ) ;
V_37 = V_71 ;
}
return F_29 ( & V_74 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_74 ) ;
}
