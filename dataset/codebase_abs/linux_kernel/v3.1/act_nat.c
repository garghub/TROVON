static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , int V_6 , int V_7 )
{
struct V_1 * V_8 [ V_9 + 1 ] ;
struct V_10 * V_11 ;
int V_12 = 0 , V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
if ( V_2 == NULL )
return - V_18 ;
V_13 = F_2 ( V_8 , V_9 , V_2 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_8 [ V_20 ] == NULL )
return - V_18 ;
V_11 = F_3 ( V_8 [ V_20 ] ) ;
V_17 = F_4 ( V_11 -> V_21 , V_5 , V_7 , & V_22 ) ;
if ( ! V_17 ) {
V_17 = F_5 ( V_11 -> V_21 , V_3 , V_5 , sizeof( * V_15 ) , V_7 ,
& V_23 , & V_22 ) ;
if ( F_6 ( V_17 ) )
return F_7 ( V_17 ) ;
V_15 = F_8 ( V_17 ) ;
V_12 = V_24 ;
} else {
V_15 = F_8 ( V_17 ) ;
if ( ! V_6 ) {
F_9 ( V_17 , V_7 , & V_22 ) ;
return - V_25 ;
}
}
F_10 ( & V_15 -> V_26 ) ;
V_15 -> V_27 = V_11 -> V_27 ;
V_15 -> V_28 = V_11 -> V_28 ;
V_15 -> V_29 = V_11 -> V_29 ;
V_15 -> V_30 = V_11 -> V_30 ;
V_15 -> V_31 = V_11 -> V_32 ;
F_11 ( & V_15 -> V_26 ) ;
if ( V_12 == V_24 )
F_12 ( V_17 , & V_22 ) ;
return V_12 ;
}
static int F_13 ( struct V_4 * V_5 , int V_7 )
{
struct V_14 * V_15 = V_5 -> V_33 ;
return F_9 ( & V_15 -> V_34 , V_7 , & V_22 ) ;
}
static int V_14 ( struct V_35 * V_36 , const struct V_4 * V_5 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = V_5 -> V_33 ;
struct V_39 * V_40 ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_29 ;
T_1 V_41 ;
int V_42 ;
int V_32 ;
int V_43 ;
int V_44 ;
F_14 ( & V_15 -> V_26 ) ;
V_15 -> V_45 . V_46 = V_47 ;
V_27 = V_15 -> V_27 ;
V_28 = V_15 -> V_28 ;
V_29 = V_15 -> V_29 ;
V_42 = V_15 -> V_30 & V_48 ;
V_32 = V_15 -> V_31 ;
F_15 ( & V_15 -> V_49 , V_36 ) ;
F_16 ( & V_15 -> V_26 ) ;
if ( F_17 ( V_32 == V_50 ) )
goto V_51;
V_44 = F_18 ( V_36 ) ;
if ( ! F_19 ( V_36 , sizeof( * V_40 ) + V_44 ) )
goto V_51;
V_40 = F_20 ( V_36 ) ;
if ( V_42 )
V_41 = V_40 -> V_52 ;
else
V_41 = V_40 -> V_53 ;
if ( ! ( ( V_27 ^ V_41 ) & V_29 ) ) {
if ( F_21 ( V_36 ) &&
! F_22 ( V_36 , sizeof( * V_40 ) + V_44 ) &&
F_23 ( V_36 , 0 , 0 , V_54 ) )
goto V_51;
V_28 &= V_29 ;
V_28 |= V_41 & ~ V_29 ;
V_40 = F_20 ( V_36 ) ;
if ( V_42 )
V_40 -> V_52 = V_28 ;
else
V_40 -> V_53 = V_28 ;
F_24 ( & V_40 -> V_55 , V_41 , V_28 ) ;
} else if ( ( V_40 -> V_56 & F_25 ( V_57 ) ) ||
V_40 -> V_58 != V_59 ) {
goto V_60;
}
V_43 = V_40 -> V_43 * 4 ;
switch ( V_40 -> V_56 & F_25 ( V_57 ) ? 0 : V_40 -> V_58 ) {
case V_61 :
{
struct V_62 * V_63 ;
if ( ! F_19 ( V_36 , V_43 + sizeof( * V_63 ) + V_44 ) ||
( F_21 ( V_36 ) &&
! F_22 ( V_36 , V_43 + sizeof( * V_63 ) + V_44 ) &&
F_23 ( V_36 , 0 , 0 , V_54 ) ) )
goto V_51;
V_63 = ( void * ) ( F_26 ( V_36 ) + V_43 ) ;
F_27 ( & V_63 -> V_55 , V_36 , V_41 , V_28 , 1 ) ;
break;
}
case V_64 :
{
struct V_65 * V_66 ;
if ( ! F_19 ( V_36 , V_43 + sizeof( * V_66 ) + V_44 ) ||
( F_21 ( V_36 ) &&
! F_22 ( V_36 , V_43 + sizeof( * V_66 ) + V_44 ) &&
F_23 ( V_36 , 0 , 0 , V_54 ) ) )
goto V_51;
V_66 = ( void * ) ( F_26 ( V_36 ) + V_43 ) ;
if ( V_66 -> V_55 || V_36 -> V_67 == V_68 ) {
F_27 ( & V_66 -> V_55 , V_36 , V_41 ,
V_28 , 1 ) ;
if ( ! V_66 -> V_55 )
V_66 -> V_55 = V_69 ;
}
break;
}
case V_59 :
{
struct V_70 * V_71 ;
if ( ! F_19 ( V_36 , V_43 + sizeof( * V_71 ) + V_44 ) )
goto V_51;
V_71 = ( void * ) ( F_26 ( V_36 ) + V_43 ) ;
if ( ( V_71 -> type != V_72 ) &&
( V_71 -> type != V_73 ) &&
( V_71 -> type != V_74 ) )
break;
if ( ! F_19 ( V_36 , V_43 + sizeof( * V_71 ) + sizeof( * V_40 ) +
V_44 ) )
goto V_51;
V_71 = ( void * ) ( F_26 ( V_36 ) + V_43 ) ;
V_40 = ( void * ) ( V_71 + 1 ) ;
if ( V_42 )
V_41 = V_40 -> V_53 ;
else
V_41 = V_40 -> V_52 ;
if ( ( V_27 ^ V_41 ) & V_29 )
break;
if ( F_21 ( V_36 ) &&
! F_22 ( V_36 , V_43 + sizeof( * V_71 ) +
sizeof( * V_40 ) + V_44 ) &&
F_23 ( V_36 , 0 , 0 , V_54 ) )
goto V_51;
V_71 = ( void * ) ( F_26 ( V_36 ) + V_43 ) ;
V_40 = ( void * ) ( V_71 + 1 ) ;
V_28 &= V_29 ;
V_28 |= V_41 & ~ V_29 ;
if ( V_42 )
V_40 -> V_53 = V_28 ;
else
V_40 -> V_52 = V_28 ;
F_27 ( & V_71 -> V_75 , V_36 , V_41 , V_28 ,
0 ) ;
break;
}
default:
break;
}
V_60:
return V_32 ;
V_51:
F_14 ( & V_15 -> V_26 ) ;
V_15 -> V_76 . V_77 ++ ;
F_16 ( & V_15 -> V_26 ) ;
return V_50 ;
}
static int F_28 ( struct V_35 * V_36 , struct V_4 * V_5 ,
int V_7 , int V_78 )
{
unsigned char * V_79 = F_29 ( V_36 ) ;
struct V_14 * V_15 = V_5 -> V_33 ;
struct V_10 V_80 = {
. V_27 = V_15 -> V_27 ,
. V_28 = V_15 -> V_28 ,
. V_29 = V_15 -> V_29 ,
. V_30 = V_15 -> V_30 ,
. V_21 = V_15 -> V_81 ,
. V_32 = V_15 -> V_31 ,
. V_82 = V_15 -> V_83 - V_78 ,
. V_84 = V_15 -> V_85 - V_7 ,
} ;
struct V_86 V_87 ;
F_30 ( V_36 , V_20 , sizeof( V_80 ) , & V_80 ) ;
V_87 . V_88 = F_31 ( V_47 - V_15 -> V_45 . V_88 ) ;
V_87 . V_46 = F_31 ( V_47 - V_15 -> V_45 . V_46 ) ;
V_87 . V_89 = F_31 ( V_15 -> V_45 . V_89 ) ;
F_30 ( V_36 , V_90 , sizeof( V_87 ) , & V_87 ) ;
return V_36 -> V_91 ;
V_92:
F_32 ( V_36 , V_79 ) ;
return - 1 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_93 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_93 ) ;
}
