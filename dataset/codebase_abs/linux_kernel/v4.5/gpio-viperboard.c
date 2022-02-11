static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 , V_5 , error = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_9 -> V_12 ;
if ( V_7 -> V_13 & ( 1 << V_3 ) )
return ! ! ( V_7 -> V_14 & ( 1 << V_3 ) ) ;
F_3 ( & V_9 -> V_15 ) ;
V_11 -> V_16 = V_17 ;
V_11 -> V_18 = 0x00 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_19 = 0x00 ;
V_11 -> V_20 = 0x00 ;
V_11 -> V_21 = 0x00 ;
V_11 -> V_22 = 0x00 ;
V_11 -> V_23 = 0x00 ;
V_11 -> V_24 = 0x00 ;
V_11 -> V_5 = 0x00 ;
V_11 -> V_25 = 0x00 ;
V_4 = F_4 ( V_9 -> V_26 , F_5 ( V_9 -> V_26 , 0 ) ,
V_27 , V_28 , 0x0000 ,
0x0000 , V_11 , sizeof( struct V_10 ) ,
V_29 ) ;
if ( V_4 != sizeof( struct V_10 ) )
error = - V_30 ;
V_4 = F_4 ( V_9 -> V_26 , F_6 ( V_9 -> V_26 , 0 ) ,
V_27 , V_31 , 0x0000 ,
0x0000 , V_11 , sizeof( struct V_10 ) ,
V_29 ) ;
V_5 = V_11 -> V_5 & 0x01 ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 != sizeof( struct V_10 ) )
error = - V_30 ;
if ( error )
return error ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_9 -> V_12 ;
if ( V_7 -> V_13 & ( 1 << V_3 ) ) {
if ( V_32 )
V_7 -> V_14 |= ( 1 << V_3 ) ;
else
V_7 -> V_14 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_11 -> V_16 = V_33 ;
V_11 -> V_18 = 0x00 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_19 = 0x00 ;
V_11 -> V_20 = 0x00 ;
V_11 -> V_21 = 0x00 ;
V_11 -> V_22 = 0x00 ;
V_11 -> V_23 = V_32 ;
V_11 -> V_24 = 0x00 ;
V_11 -> V_5 = 0x00 ;
V_11 -> V_25 = 0x00 ;
V_4 = F_4 ( V_9 -> V_26 ,
F_5 ( V_9 -> V_26 , 0 ) ,
V_27 , V_28 ,
0x0000 , 0x0000 , V_11 ,
sizeof( struct V_10 ) , V_29 ) ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 != sizeof( struct V_10 ) )
F_9 ( V_2 -> V_34 , L_1 ) ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_9 -> V_12 ;
V_7 -> V_13 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_11 -> V_16 = V_35 ;
V_11 -> V_18 = V_36 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_19 = 0x00 ;
V_11 -> V_20 = 0x00 ;
V_11 -> V_21 = 0x00 ;
V_11 -> V_22 = 0x00 ;
V_11 -> V_23 = 0x00 ;
V_11 -> V_24 = 0x00 ;
V_11 -> V_5 = 0x00 ;
V_11 -> V_25 = 0x00 ;
V_4 = F_4 ( V_9 -> V_26 , F_5 ( V_9 -> V_26 , 0 ) ,
V_27 , V_28 , 0x0000 ,
0x0000 , V_11 , sizeof( struct V_10 ) ,
V_29 ) ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 != sizeof( struct V_10 ) )
return - V_30 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_9 -> V_12 ;
V_7 -> V_13 |= ( 1 << V_3 ) ;
if ( V_32 )
V_7 -> V_14 |= ( 1 << V_3 ) ;
else
V_7 -> V_14 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_11 -> V_16 = V_33 ;
V_11 -> V_18 = 0x00 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_19 = 0x00 ;
V_11 -> V_20 = 0x00 ;
V_11 -> V_21 = 0x00 ;
V_11 -> V_22 = 0x00 ;
V_11 -> V_23 = V_32 ;
V_11 -> V_24 = 0x00 ;
V_11 -> V_5 = 0x00 ;
V_11 -> V_25 = 0x00 ;
V_4 = F_4 ( V_9 -> V_26 , F_5 ( V_9 -> V_26 , 0 ) ,
V_27 , V_28 , 0x0000 ,
0x0000 , V_11 , sizeof( struct V_10 ) ,
V_29 ) ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 != sizeof( struct V_10 ) )
return - V_30 ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 , unsigned V_3 ,
unsigned V_37 )
{
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_12 ;
int V_4 ;
V_39 -> V_16 = V_40 ;
V_39 -> V_41 = F_13 ( V_37 << V_3 ) ;
V_39 -> V_42 = F_13 ( 0x0001 << V_3 ) ;
V_4 = F_4 ( V_9 -> V_26 , F_5 ( V_9 -> V_26 , 0 ) ,
V_43 , V_28 , 0x0000 ,
0x0000 , V_39 , sizeof( struct V_38 ) ,
V_29 ) ;
if ( V_4 != sizeof( struct V_38 ) )
return - V_30 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
T_1 V_41 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_12 ;
if ( V_7 -> V_44 & ( 1 << V_3 ) )
return V_7 -> V_45 & ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_4 = F_4 ( V_9 -> V_26 , F_6 ( V_9 -> V_26 , 0 ) ,
V_43 , V_31 , 0x0000 ,
0x0000 , V_39 , sizeof( struct V_38 ) ,
V_29 ) ;
V_41 = V_39 -> V_41 ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 != sizeof( struct V_38 ) )
return V_4 ;
V_7 -> V_45 = F_15 ( V_41 ) ;
return ( V_7 -> V_45 >> V_3 ) & 0x1 ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_12 ;
if ( V_7 -> V_44 & ( 1 << V_3 ) ) {
if ( V_32 )
V_7 -> V_45 |= ( 1 << V_3 ) ;
else
V_7 -> V_45 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_39 -> V_16 = V_46 ;
V_39 -> V_41 = F_13 ( V_32 << V_3 ) ;
V_39 -> V_42 = F_13 ( 0x0001 << V_3 ) ;
V_4 = F_4 ( V_9 -> V_26 ,
F_5 ( V_9 -> V_26 , 0 ) ,
V_43 , V_28 ,
0x0000 , 0x0000 , V_39 ,
sizeof( struct V_38 ) , V_29 ) ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 != sizeof( struct V_38 ) )
F_9 ( V_2 -> V_34 , L_1 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_7 -> V_44 &= ~ ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_4 = F_12 ( V_9 , V_3 , 0 ) ;
F_7 ( & V_9 -> V_15 ) ;
if ( V_4 )
F_9 ( V_2 -> V_34 , L_2 ) ;
return V_4 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_7 -> V_44 |= ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_15 ) ;
V_4 = F_12 ( V_9 , V_3 , 1 ) ;
if ( V_4 )
F_9 ( V_2 -> V_34 , L_3 ) ;
F_7 ( & V_9 -> V_15 ) ;
F_16 ( V_2 , V_3 , V_32 ) ;
return V_4 ;
}
static int F_19 ( struct V_47 * V_48 )
{
struct V_8 * V_9 = F_20 ( V_48 -> V_49 . V_34 ) ;
struct V_6 * V_50 ;
int V_4 ;
V_50 = F_21 ( & V_48 -> V_49 , sizeof( * V_50 ) , V_51 ) ;
if ( V_50 == NULL )
return - V_52 ;
V_50 -> V_9 = V_9 ;
V_50 -> V_53 . V_54 = L_4 ;
V_50 -> V_53 . V_34 = & V_48 -> V_49 ;
V_50 -> V_53 . V_55 = V_56 ;
V_50 -> V_53 . V_57 = - 1 ;
V_50 -> V_53 . V_58 = 16 ;
V_50 -> V_53 . V_59 = true ;
V_50 -> V_53 . V_60 = F_8 ;
V_50 -> V_53 . V_61 = F_1 ;
V_50 -> V_53 . V_62 = F_10 ;
V_50 -> V_53 . V_63 = F_11 ;
V_4 = F_22 ( & V_50 -> V_53 , V_50 ) ;
if ( V_4 < 0 ) {
F_9 ( V_50 -> V_53 . V_34 , L_5 ) ;
goto V_64;
}
V_50 -> V_65 . V_54 = L_6 ;
V_50 -> V_65 . V_34 = & V_48 -> V_49 ;
V_50 -> V_65 . V_55 = V_56 ;
V_50 -> V_65 . V_57 = - 1 ;
V_50 -> V_65 . V_58 = 16 ;
V_50 -> V_65 . V_59 = true ;
V_50 -> V_65 . V_60 = F_16 ;
V_50 -> V_65 . V_61 = F_14 ;
V_50 -> V_65 . V_62 = F_17 ;
V_50 -> V_65 . V_63 = F_18 ;
V_4 = F_22 ( & V_50 -> V_65 , V_50 ) ;
if ( V_4 < 0 ) {
F_9 ( V_50 -> V_65 . V_34 , L_7 ) ;
goto V_66;
}
F_23 ( V_48 , V_50 ) ;
return V_4 ;
V_66:
F_24 ( & V_50 -> V_53 ) ;
V_64:
return V_4 ;
}
static int F_25 ( struct V_47 * V_48 )
{
struct V_6 * V_50 = F_26 ( V_48 ) ;
F_24 ( & V_50 -> V_65 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
switch ( V_67 ) {
case 1000000 :
V_36 = V_68 ;
break;
case 100000 :
V_36 = V_69 ;
break;
case 10000 :
V_36 = V_70 ;
break;
case 1000 :
V_36 = V_71 ;
break;
case 100 :
V_36 = V_72 ;
break;
case 10 :
V_36 = V_73 ;
break;
default:
F_28 ( L_8 , V_67 ) ;
V_36 = V_71 ;
}
return F_29 ( & V_74 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_74 ) ;
}
