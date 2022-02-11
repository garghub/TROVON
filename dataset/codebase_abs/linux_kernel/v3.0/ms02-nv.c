static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_3 + V_4 > V_2 -> V_10 )
return - V_11 ;
memcpy ( V_6 , V_8 -> V_12 + V_3 , V_4 ) ;
* V_5 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_13 ,
T_2 V_4 , T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_13 + V_4 > V_2 -> V_10 )
return - V_11 ;
memcpy ( V_8 -> V_12 + V_13 , V_6 , V_4 ) ;
* V_5 = V_4 ;
return 0 ;
}
static inline T_4 F_3 ( T_5 V_14 )
{
T_6 * V_15 ;
T_6 * V_16 ;
T_4 V_17 ;
T_4 V_18 ;
T_2 V_10 ;
int V_19 ;
V_15 = ( T_6 * ) ( F_4 ( V_14 + V_20 ) ) ;
V_16 = ( T_6 * ) ( F_4 ( V_14 + V_21 ) ) ;
V_19 = F_5 ( V_18 , V_16 ) ;
if ( V_19 )
return 0 ;
if ( V_18 != V_22 )
return 0 ;
V_17 = * V_15 ;
V_10 = ( V_17 & V_23 ) << V_24 ;
if ( V_10 > V_25 )
V_10 = V_25 ;
return V_10 ;
}
static int T_7 F_6 ( T_5 V_14 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_26 * V_27 ;
struct V_26 * V_28 ;
struct V_26 * V_29 ;
struct V_26 * V_30 ;
T_5 V_31 ;
T_2 V_10 , V_32 ;
static int V_33 ;
int V_34 = - V_35 ;
V_27 = F_7 ( sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 )
return - V_37 ;
V_27 -> V_38 = V_39 ;
V_27 -> V_40 = V_14 ;
V_27 -> V_41 = V_14 + V_42 - 1 ;
V_27 -> V_43 = V_44 | V_45 ;
if ( F_8 ( & V_46 , V_27 ) < 0 )
goto V_47;
V_10 = F_3 ( V_14 ) ;
if ( ! V_10 )
goto V_48;
if ( ! V_33 ) {
F_9 ( V_49 L_1 , V_50 ) ;
V_33 = 1 ;
}
V_34 = - V_37 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
goto V_48;
V_8 = F_7 ( sizeof( * V_8 ) , V_36 ) ;
if ( ! V_8 )
goto V_51;
V_2 -> V_9 = V_8 ;
V_8 -> V_26 . V_52 = V_27 ;
V_28 = F_7 ( sizeof( * V_28 ) , V_36 ) ;
if ( ! V_28 )
goto V_53;
V_28 -> V_38 = V_54 ;
V_28 -> V_40 = V_14 ;
V_28 -> V_41 = V_14 + V_55 - 1 ;
V_28 -> V_43 = V_45 ;
F_8 ( V_27 , V_28 ) ;
V_8 -> V_26 . V_56 = V_28 ;
V_29 = F_7 ( sizeof( * V_29 ) , V_36 ) ;
if ( ! V_29 )
goto V_57;
V_29 -> V_38 = V_58 ;
V_29 -> V_40 = V_14 + V_55 ;
V_29 -> V_41 = V_14 + V_10 - 1 ;
V_29 -> V_43 = V_45 ;
F_8 ( V_27 , V_29 ) ;
V_8 -> V_26 . V_59 = V_29 ;
V_30 = F_7 ( sizeof( * V_30 ) , V_36 ) ;
if ( ! V_30 )
goto V_60;
V_30 -> V_38 = V_61 ;
V_30 -> V_40 = V_14 + V_25 ;
V_30 -> V_41 = V_14 + V_25 + 3 ;
V_30 -> V_43 = V_45 ;
F_8 ( V_27 , V_30 ) ;
V_8 -> V_26 . V_62 = V_30 ;
V_8 -> V_14 = F_10 ( V_14 ) ;
V_8 -> V_10 = V_10 ;
V_31 = ( V_14 + V_55 + V_63 - 1 ) & ~ ( V_63 - 1 ) ;
V_32 = ( V_10 - ( V_31 - V_14 ) ) & ~ ( V_63 - 1 ) ;
V_8 -> V_12 = F_10 ( V_31 ) ;
V_2 -> type = V_64 ;
V_2 -> V_43 = V_65 ;
V_2 -> V_10 = V_32 ;
V_2 -> V_38 = ( char * ) V_39 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = F_1 ;
V_2 -> V_69 = F_2 ;
V_2 -> V_70 = 1 ;
V_34 = - V_71 ;
if ( F_11 ( V_2 , NULL , 0 ) ) {
F_9 ( V_72
L_2 ) ;
goto V_73;
}
F_9 ( V_49 L_3 ,
V_2 -> V_74 , V_39 , V_14 , V_10 >> 20 ) ;
V_8 -> V_75 = V_76 ;
V_76 = V_2 ;
return 0 ;
V_73:
F_12 ( V_30 ) ;
F_13 ( V_30 ) ;
V_60:
F_12 ( V_29 ) ;
F_13 ( V_29 ) ;
V_57:
F_12 ( V_28 ) ;
F_13 ( V_28 ) ;
V_53:
F_13 ( V_8 ) ;
V_51:
F_13 ( V_2 ) ;
V_48:
F_12 ( V_27 ) ;
V_47:
F_13 ( V_27 ) ;
return V_34 ;
}
static void T_8 F_14 ( void )
{
struct V_1 * V_2 = V_76 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_76 = V_8 -> V_75 ;
F_15 ( V_2 ) ;
F_12 ( V_8 -> V_26 . V_62 ) ;
F_13 ( V_8 -> V_26 . V_62 ) ;
F_12 ( V_8 -> V_26 . V_59 ) ;
F_13 ( V_8 -> V_26 . V_59 ) ;
F_12 ( V_8 -> V_26 . V_56 ) ;
F_13 ( V_8 -> V_26 . V_56 ) ;
F_12 ( V_8 -> V_26 . V_52 ) ;
F_13 ( V_8 -> V_26 . V_52 ) ;
F_13 ( V_8 ) ;
F_13 ( V_2 ) ;
}
static int T_7 F_16 ( void )
{
volatile T_9 * V_62 ;
T_4 V_77 = 0 ;
int V_78 = 0 ;
int V_79 ;
switch ( V_80 ) {
case V_81 :
V_62 = ( volatile T_9 * ) F_4 ( V_82 + V_83 ) ;
if ( * V_62 & V_84 )
V_77 = 2 ;
break;
case V_85 :
case V_86 :
V_62 = ( volatile T_9 * ) F_4 ( V_87 + V_88 ) ;
if ( * V_62 & V_89 )
V_77 = 2 ;
break;
default:
return - V_35 ;
break;
}
for ( V_79 = 0 ; V_79 < F_17 ( V_90 ) ; V_79 ++ )
if ( ! F_6 ( V_90 [ V_79 ] << V_77 ) )
V_78 ++ ;
return ( V_78 > 0 ) ? 0 : - V_35 ;
}
static void T_8 F_18 ( void )
{
while ( V_76 )
F_14 () ;
}
