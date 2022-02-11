static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
memcpy ( V_6 , V_8 -> V_10 + V_3 , V_4 ) ;
* V_5 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_11 ,
T_2 V_4 , T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
memcpy ( V_8 -> V_10 + V_11 , V_6 , V_4 ) ;
* V_5 = V_4 ;
return 0 ;
}
static inline T_4 F_3 ( T_5 V_12 )
{
T_6 * V_13 ;
T_6 * V_14 ;
T_4 V_15 ;
T_4 V_16 ;
T_2 V_17 ;
int V_18 ;
V_13 = ( T_6 * ) ( F_4 ( V_12 + V_19 ) ) ;
V_14 = ( T_6 * ) ( F_4 ( V_12 + V_20 ) ) ;
V_18 = F_5 ( V_16 , V_14 ) ;
if ( V_18 )
return 0 ;
if ( V_16 != V_21 )
return 0 ;
V_15 = * V_13 ;
V_17 = ( V_15 & V_22 ) << V_23 ;
if ( V_17 > V_24 )
V_17 = V_24 ;
return V_17 ;
}
static int T_7 F_6 ( T_5 V_12 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_25 * V_26 ;
struct V_25 * V_27 ;
struct V_25 * V_28 ;
struct V_25 * V_29 ;
T_5 V_30 ;
T_2 V_17 , V_31 ;
static int V_32 ;
int V_33 = - V_34 ;
V_26 = F_7 ( sizeof( * V_26 ) , V_35 ) ;
if ( ! V_26 )
return - V_36 ;
V_26 -> V_37 = V_38 ;
V_26 -> V_39 = V_12 ;
V_26 -> V_40 = V_12 + V_41 - 1 ;
V_26 -> V_42 = V_43 | V_44 ;
if ( F_8 ( & V_45 , V_26 ) < 0 )
goto V_46;
V_17 = F_3 ( V_12 ) ;
if ( ! V_17 )
goto V_47;
if ( ! V_32 ) {
F_9 ( V_48 L_1 , V_49 ) ;
V_32 = 1 ;
}
V_33 = - V_36 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
goto V_47;
V_8 = F_7 ( sizeof( * V_8 ) , V_35 ) ;
if ( ! V_8 )
goto V_50;
V_2 -> V_9 = V_8 ;
V_8 -> V_25 . V_51 = V_26 ;
V_27 = F_7 ( sizeof( * V_27 ) , V_35 ) ;
if ( ! V_27 )
goto V_52;
V_27 -> V_37 = V_53 ;
V_27 -> V_39 = V_12 ;
V_27 -> V_40 = V_12 + V_54 - 1 ;
V_27 -> V_42 = V_44 ;
F_8 ( V_26 , V_27 ) ;
V_8 -> V_25 . V_55 = V_27 ;
V_28 = F_7 ( sizeof( * V_28 ) , V_35 ) ;
if ( ! V_28 )
goto V_56;
V_28 -> V_37 = V_57 ;
V_28 -> V_39 = V_12 + V_54 ;
V_28 -> V_40 = V_12 + V_17 - 1 ;
V_28 -> V_42 = V_44 ;
F_8 ( V_26 , V_28 ) ;
V_8 -> V_25 . V_58 = V_28 ;
V_29 = F_7 ( sizeof( * V_29 ) , V_35 ) ;
if ( ! V_29 )
goto V_59;
V_29 -> V_37 = V_60 ;
V_29 -> V_39 = V_12 + V_24 ;
V_29 -> V_40 = V_12 + V_24 + 3 ;
V_29 -> V_42 = V_44 ;
F_8 ( V_26 , V_29 ) ;
V_8 -> V_25 . V_61 = V_29 ;
V_8 -> V_12 = F_10 ( V_12 ) ;
V_8 -> V_17 = V_17 ;
V_30 = ( V_12 + V_54 + V_62 - 1 ) & ~ ( V_62 - 1 ) ;
V_31 = ( V_17 - ( V_30 - V_12 ) ) & ~ ( V_62 - 1 ) ;
V_8 -> V_10 = F_10 ( V_30 ) ;
V_2 -> type = V_63 ;
V_2 -> V_42 = V_64 ;
V_2 -> V_17 = V_31 ;
V_2 -> V_37 = ( char * ) V_38 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = F_1 ;
V_2 -> V_68 = F_2 ;
V_2 -> V_69 = 1 ;
V_33 = - V_70 ;
if ( F_11 ( V_2 , NULL , 0 ) ) {
F_9 ( V_71
L_2 ) ;
goto V_72;
}
F_9 ( V_48 L_3 ,
V_2 -> V_73 , V_38 , V_12 , V_17 >> 20 ) ;
V_8 -> V_74 = V_75 ;
V_75 = V_2 ;
return 0 ;
V_72:
F_12 ( V_29 ) ;
F_13 ( V_29 ) ;
V_59:
F_12 ( V_28 ) ;
F_13 ( V_28 ) ;
V_56:
F_12 ( V_27 ) ;
F_13 ( V_27 ) ;
V_52:
F_13 ( V_8 ) ;
V_50:
F_13 ( V_2 ) ;
V_47:
F_12 ( V_26 ) ;
V_46:
F_13 ( V_26 ) ;
return V_33 ;
}
static void T_8 F_14 ( void )
{
struct V_1 * V_2 = V_75 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_75 = V_8 -> V_74 ;
F_15 ( V_2 ) ;
F_12 ( V_8 -> V_25 . V_61 ) ;
F_13 ( V_8 -> V_25 . V_61 ) ;
F_12 ( V_8 -> V_25 . V_58 ) ;
F_13 ( V_8 -> V_25 . V_58 ) ;
F_12 ( V_8 -> V_25 . V_55 ) ;
F_13 ( V_8 -> V_25 . V_55 ) ;
F_12 ( V_8 -> V_25 . V_51 ) ;
F_13 ( V_8 -> V_25 . V_51 ) ;
F_13 ( V_8 ) ;
F_13 ( V_2 ) ;
}
static int T_7 F_16 ( void )
{
volatile T_9 * V_61 ;
T_4 V_76 = 0 ;
int V_77 = 0 ;
int V_78 ;
switch ( V_79 ) {
case V_80 :
V_61 = ( volatile T_9 * ) F_4 ( V_81 + V_82 ) ;
if ( * V_61 & V_83 )
V_76 = 2 ;
break;
case V_84 :
case V_85 :
V_61 = ( volatile T_9 * ) F_4 ( V_86 + V_87 ) ;
if ( * V_61 & V_88 )
V_76 = 2 ;
break;
default:
return - V_34 ;
break;
}
for ( V_78 = 0 ; V_78 < F_17 ( V_89 ) ; V_78 ++ )
if ( ! F_6 ( V_89 [ V_78 ] << V_76 ) )
V_77 ++ ;
return ( V_77 > 0 ) ? 0 : - V_34 ;
}
static void T_8 F_18 ( void )
{
while ( V_75 )
F_14 () ;
}
