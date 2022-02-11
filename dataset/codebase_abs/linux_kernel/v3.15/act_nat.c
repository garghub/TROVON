static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_2 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 )
{
struct V_2 * V_9 [ V_10 + 1 ] ;
struct V_11 * V_12 ;
int V_13 = 0 , V_14 ;
struct V_15 * V_16 ;
if ( V_3 == NULL )
return - V_17 ;
V_14 = F_2 ( V_9 , V_10 , V_3 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_9 [ V_19 ] == NULL )
return - V_17 ;
V_12 = F_3 ( V_9 [ V_19 ] ) ;
if ( ! F_4 ( V_12 -> V_20 , V_6 , V_8 ) ) {
V_13 = F_5 ( V_12 -> V_20 , V_4 , V_6 , sizeof( * V_16 ) , V_8 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_21 ;
} else {
if ( V_8 )
return 0 ;
F_6 ( V_6 , V_8 ) ;
if ( ! V_7 )
return - V_22 ;
}
V_16 = F_7 ( V_6 ) ;
F_8 ( & V_16 -> V_23 ) ;
V_16 -> V_24 = V_12 -> V_24 ;
V_16 -> V_25 = V_12 -> V_25 ;
V_16 -> V_26 = V_12 -> V_26 ;
V_16 -> V_27 = V_12 -> V_27 ;
V_16 -> V_28 = V_12 -> V_29 ;
F_9 ( & V_16 -> V_23 ) ;
if ( V_13 == V_21 )
F_10 ( V_6 ) ;
return V_13 ;
}
static int V_15 ( struct V_30 * V_31 , const struct V_5 * V_6 ,
struct V_32 * V_33 )
{
struct V_15 * V_16 = V_6 -> V_34 ;
struct V_35 * V_36 ;
T_1 V_24 ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_37 ;
int V_38 ;
int V_29 ;
int V_39 ;
int V_40 ;
F_11 ( & V_16 -> V_23 ) ;
V_16 -> V_41 . V_42 = V_43 ;
V_24 = V_16 -> V_24 ;
V_25 = V_16 -> V_25 ;
V_26 = V_16 -> V_26 ;
V_38 = V_16 -> V_27 & V_44 ;
V_29 = V_16 -> V_28 ;
F_12 ( & V_16 -> V_45 , V_31 ) ;
F_13 ( & V_16 -> V_23 ) ;
if ( F_14 ( V_29 == V_46 ) )
goto V_47;
V_40 = F_15 ( V_31 ) ;
if ( ! F_16 ( V_31 , sizeof( * V_36 ) + V_40 ) )
goto V_47;
V_36 = F_17 ( V_31 ) ;
if ( V_38 )
V_37 = V_36 -> V_48 ;
else
V_37 = V_36 -> V_49 ;
if ( ! ( ( V_24 ^ V_37 ) & V_26 ) ) {
if ( F_18 ( V_31 ) &&
! F_19 ( V_31 , sizeof( * V_36 ) + V_40 ) &&
F_20 ( V_31 , 0 , 0 , V_50 ) )
goto V_47;
V_25 &= V_26 ;
V_25 |= V_37 & ~ V_26 ;
V_36 = F_17 ( V_31 ) ;
if ( V_38 )
V_36 -> V_48 = V_25 ;
else
V_36 -> V_49 = V_25 ;
F_21 ( & V_36 -> V_51 , V_37 , V_25 ) ;
} else if ( ( V_36 -> V_52 & F_22 ( V_53 ) ) ||
V_36 -> V_54 != V_55 ) {
goto V_56;
}
V_39 = V_36 -> V_39 * 4 ;
switch ( V_36 -> V_52 & F_22 ( V_53 ) ? 0 : V_36 -> V_54 ) {
case V_57 :
{
struct V_58 * V_59 ;
if ( ! F_16 ( V_31 , V_39 + sizeof( * V_59 ) + V_40 ) ||
( F_18 ( V_31 ) &&
! F_19 ( V_31 , V_39 + sizeof( * V_59 ) + V_40 ) &&
F_20 ( V_31 , 0 , 0 , V_50 ) ) )
goto V_47;
V_59 = ( void * ) ( F_23 ( V_31 ) + V_39 ) ;
F_24 ( & V_59 -> V_51 , V_31 , V_37 , V_25 , 1 ) ;
break;
}
case V_60 :
{
struct V_61 * V_62 ;
if ( ! F_16 ( V_31 , V_39 + sizeof( * V_62 ) + V_40 ) ||
( F_18 ( V_31 ) &&
! F_19 ( V_31 , V_39 + sizeof( * V_62 ) + V_40 ) &&
F_20 ( V_31 , 0 , 0 , V_50 ) ) )
goto V_47;
V_62 = ( void * ) ( F_23 ( V_31 ) + V_39 ) ;
if ( V_62 -> V_51 || V_31 -> V_63 == V_64 ) {
F_24 ( & V_62 -> V_51 , V_31 , V_37 ,
V_25 , 1 ) ;
if ( ! V_62 -> V_51 )
V_62 -> V_51 = V_65 ;
}
break;
}
case V_55 :
{
struct V_66 * V_67 ;
if ( ! F_16 ( V_31 , V_39 + sizeof( * V_67 ) + V_40 ) )
goto V_47;
V_67 = ( void * ) ( F_23 ( V_31 ) + V_39 ) ;
if ( ( V_67 -> type != V_68 ) &&
( V_67 -> type != V_69 ) &&
( V_67 -> type != V_70 ) )
break;
if ( ! F_16 ( V_31 , V_39 + sizeof( * V_67 ) + sizeof( * V_36 ) +
V_40 ) )
goto V_47;
V_67 = ( void * ) ( F_23 ( V_31 ) + V_39 ) ;
V_36 = ( void * ) ( V_67 + 1 ) ;
if ( V_38 )
V_37 = V_36 -> V_49 ;
else
V_37 = V_36 -> V_48 ;
if ( ( V_24 ^ V_37 ) & V_26 )
break;
if ( F_18 ( V_31 ) &&
! F_19 ( V_31 , V_39 + sizeof( * V_67 ) +
sizeof( * V_36 ) + V_40 ) &&
F_20 ( V_31 , 0 , 0 , V_50 ) )
goto V_47;
V_67 = ( void * ) ( F_23 ( V_31 ) + V_39 ) ;
V_36 = ( void * ) ( V_67 + 1 ) ;
V_25 &= V_26 ;
V_25 |= V_37 & ~ V_26 ;
if ( V_38 )
V_36 -> V_49 = V_25 ;
else
V_36 -> V_48 = V_25 ;
F_24 ( & V_67 -> V_71 , V_31 , V_37 , V_25 ,
0 ) ;
break;
}
default:
break;
}
V_56:
return V_29 ;
V_47:
F_11 ( & V_16 -> V_23 ) ;
V_16 -> V_72 . V_73 ++ ;
F_13 ( & V_16 -> V_23 ) ;
return V_46 ;
}
static int F_25 ( struct V_30 * V_31 , struct V_5 * V_6 ,
int V_8 , int V_74 )
{
unsigned char * V_75 = F_26 ( V_31 ) ;
struct V_15 * V_16 = V_6 -> V_34 ;
struct V_11 V_76 = {
. V_24 = V_16 -> V_24 ,
. V_25 = V_16 -> V_25 ,
. V_26 = V_16 -> V_26 ,
. V_27 = V_16 -> V_27 ,
. V_20 = V_16 -> V_77 ,
. V_29 = V_16 -> V_28 ,
. V_78 = V_16 -> V_79 - V_74 ,
. V_80 = V_16 -> V_81 - V_8 ,
} ;
struct V_82 V_83 ;
if ( F_27 ( V_31 , V_19 , sizeof( V_76 ) , & V_76 ) )
goto V_84;
V_83 . V_85 = F_28 ( V_43 - V_16 -> V_41 . V_85 ) ;
V_83 . V_42 = F_28 ( V_43 - V_16 -> V_41 . V_42 ) ;
V_83 . V_86 = F_28 ( V_16 -> V_41 . V_86 ) ;
if ( F_27 ( V_31 , V_87 , sizeof( V_83 ) , & V_83 ) )
goto V_84;
return V_31 -> V_88 ;
V_84:
F_29 ( V_31 , V_75 ) ;
return - 1 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_89 , V_90 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_89 ) ;
}
