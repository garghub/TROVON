static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( 0 , 0 ) ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
#define F_3 0xD0810600
#define F_4 (1 << 11)
#define F_5 0xD0810900
#define F_5 0xD0810900
#define F_6 0x7000
#define F_7 12
#define F_8 0
#define F_9 1
#define F_10 2
if ( V_7 == NULL ) {
F_11 ( 1 ) ;
return;
}
F_12 ( V_7 , 0xD0 , F_3 ) ;
F_13 ( V_7 , 0xD4 , & V_8 ) ;
if ( F_14 ( V_2 ) )
V_4 -> V_10 = V_8 & F_4 ;
F_15 ( L_1 ,
V_4 -> V_10 ? L_2 : L_3 ) ;
if ( V_4 -> V_10 ) {
V_4 -> V_11 = true ;
V_4 -> V_12 = false ;
} else {
V_4 -> V_12 = true ;
V_4 -> V_11 = false ;
}
V_4 -> V_13 = V_8 ;
F_12 ( V_7 , 0xD0 , F_5 ) ;
F_13 ( V_7 , 0xD4 , & V_8 ) ;
F_16 ( V_2 -> V_2 , L_4 , V_8 ) ;
V_9 = ( V_8 & F_6 ) >> F_7 ;
V_4 -> V_14 = V_8 ;
switch ( V_9 ) {
case F_8 :
V_4 -> V_15 = 200 ;
break;
case F_9 :
V_4 -> V_15 = 100 ;
break;
case F_10 :
V_4 -> V_15 = 166 ;
break;
default:
F_17 ( V_2 -> V_2 , L_5 ,
V_9 ) ;
V_4 -> V_15 = 0 ;
}
F_16 ( V_2 -> V_2 , L_6 , V_4 -> V_15 ) ;
F_18 ( V_7 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
T_1 V_16 = 0 ;
struct V_6 * V_17 = F_2 ( 0 , F_20 ( 2 , 0 ) ) ;
if ( V_17 == NULL ) {
F_11 ( 1 ) ;
return;
}
F_13 ( V_17 , 0x08 , & V_16 ) ;
V_4 -> V_16 = ( V_18 ) V_16 ;
F_18 ( V_17 ) ;
F_16 ( V_4 -> V_2 -> V_2 , L_7 ,
V_4 -> V_16 ) ;
}
static int F_21 ( T_2 V_19 , struct V_20 * V_21 )
{
void T_3 * V_22 ;
V_22 = F_22 ( V_19 , sizeof( * V_21 ) ) ;
if ( V_22 == NULL )
return - 1 ;
F_23 ( V_21 , V_22 , sizeof( * V_21 ) ) ;
F_24 ( V_22 ) ;
return 0 ;
}
static int F_25 ( T_2 V_19 , struct V_23 * V_21 )
{
void T_3 * V_22 ;
V_22 = F_22 ( V_19 , sizeof( * V_21 ) ) ;
if ( ! V_22 )
return - 1 ;
F_23 ( V_21 , V_22 , sizeof( * V_21 ) ) ;
F_24 ( V_22 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , T_2 V_19 )
{
struct V_20 V_21 ;
void T_3 * V_24 ;
struct V_25 V_26 ;
T_4 V_27 ;
if ( F_21 ( V_19 , & V_21 ) )
return - 1 ;
V_24 = F_22 ( V_19 + sizeof( V_21 ) , V_21 . V_28 - sizeof( V_21 ) ) ;
if ( ! V_24 )
return - 1 ;
F_23 ( & V_26 , V_24 , sizeof( V_26 ) ) ;
F_24 ( V_24 ) ;
V_27 = V_26 . V_29 . V_30 ;
V_4 -> V_31 . V_27 = V_27 ;
V_4 -> V_31 . V_32 = V_26 . V_29 . V_33 ;
V_4 -> V_31 . V_34 = V_26 . V_35 [ V_27 ] . V_34 ;
V_4 -> V_31 . V_36 =
V_26 . V_35 [ V_27 ] . V_36 ;
V_4 -> V_31 . V_37 =
V_26 . V_35 [ V_27 ] . V_37 ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 , T_2 V_19 )
{
struct V_20 V_21 ;
void T_3 * V_24 ;
struct V_38 V_26 ;
T_4 V_27 ;
if ( F_21 ( V_19 , & V_21 ) )
return - 1 ;
V_24 = F_22 ( V_19 + sizeof( V_21 ) , V_21 . V_28 - sizeof( V_21 ) ) ;
if ( ! V_24 )
return - 1 ;
F_23 ( & V_26 , V_24 , sizeof( V_26 ) ) ;
F_24 ( V_24 ) ;
V_27 = V_26 . V_29 . V_30 ;
V_4 -> V_31 . V_27 = V_27 ;
V_4 -> V_31 . V_32 = V_26 . V_29 . V_33 ;
V_4 -> V_31 . V_34 = V_26 . V_35 [ V_27 ] . V_34 ;
V_4 -> V_31 . V_36 =
V_26 . V_35 [ V_27 ] . V_36 ;
V_4 -> V_31 . V_37 =
V_26 . V_35 [ V_27 ] . V_37 ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , T_2 V_19 )
{
struct V_23 V_21 ;
void T_3 * V_24 ;
struct V_39 * V_26 ;
struct V_40 * V_41 = & V_4 -> V_31 . V_34 ;
struct V_42 * V_43 ;
int V_44 = - 1 ;
if ( F_25 ( V_19 , & V_21 ) )
return - 1 ;
V_26 = F_29 ( sizeof( * V_26 ) * V_21 . V_45 , V_46 ) ;
if ( ! V_26 )
return - 1 ;
V_24 = F_22 ( V_19 + sizeof( V_21 ) ,
sizeof( * V_26 ) * V_21 . V_45 ) ;
if ( ! V_24 )
goto V_47;
F_23 ( V_26 , V_24 , sizeof( * V_26 ) ) ;
F_24 ( V_24 ) ;
V_4 -> V_31 . V_27 = V_21 . V_48 ;
V_4 -> V_31 . V_37 =
V_26 [ V_21 . V_48 ] . V_37 ;
V_43 = & V_26 [ V_21 . V_48 ] . V_34 ;
V_41 -> V_49 = V_43 -> V_49 ;
V_41 -> V_50 = V_43 -> V_50 ;
V_41 -> V_51 = V_43 -> V_51 ;
V_41 -> V_52 = V_43 -> V_52 ;
V_41 -> V_53 = V_43 -> V_53 ;
V_41 -> V_54 = V_43 -> V_54 ;
V_41 -> V_55 = V_43 -> V_55 ;
V_41 -> V_56 = V_43 -> V_56 ;
V_41 -> V_57 = V_43 -> V_57 ;
V_41 -> V_58 = V_43 -> V_58 ;
V_41 -> V_59 = V_43 -> V_59 ;
V_41 -> V_60 = V_43 -> V_60 ;
V_41 -> V_61 = V_43 -> V_61 ;
V_41 -> V_62 = V_43 -> V_62 ;
V_41 -> V_63 = V_43 -> V_63 ;
V_41 -> V_64 = V_43 -> V_64 ;
V_41 -> V_65 = V_43 -> V_65 ;
V_44 = 0 ;
V_47:
F_30 ( V_26 ) ;
return V_44 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_19 ;
T_4 T_3 * V_22 ;
struct V_66 V_66 ;
struct V_6 * V_17 = F_2 ( 0 , F_20 ( 2 , 0 ) ) ;
int V_44 = - 1 ;
F_13 ( V_17 , 0xFC , & V_19 ) ;
F_18 ( V_17 ) ;
F_16 ( V_2 -> V_2 , L_8 , V_19 ) ;
if ( ! V_19 )
goto V_47;
V_22 = F_22 ( V_19 , sizeof( V_66 ) ) ;
if ( ! V_22 )
goto V_47;
F_23 ( & V_66 , V_22 , sizeof( V_66 ) ) ;
F_24 ( V_22 ) ;
if ( memcmp ( & V_66 . V_67 , L_9 , 4 ) )
goto V_47;
F_16 ( V_2 -> V_2 , L_10 , V_66 . V_68 ) ;
switch ( V_66 . V_68 ) {
case 0x00 :
V_44 = F_26 ( V_4 , V_19 ) ;
break;
case 0x01 :
V_44 = F_27 ( V_4 , V_19 ) ;
break;
case 0x10 :
V_44 = F_28 ( V_4 , V_19 ) ;
break;
default:
F_32 ( V_2 -> V_2 , L_11 ) ;
}
V_47:
if ( V_44 )
F_32 ( V_2 -> V_2 , L_12 ) ;
else
V_4 -> V_69 = true ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_1 ( V_2 ) ;
F_31 ( V_4 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
