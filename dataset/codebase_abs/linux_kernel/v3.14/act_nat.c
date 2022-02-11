static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_2 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 )
{
struct V_2 * V_9 [ V_10 + 1 ] ;
struct V_11 * V_12 ;
int V_13 = 0 , V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
if ( V_3 == NULL )
return - V_19 ;
V_14 = F_2 ( V_9 , V_10 , V_3 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_9 [ V_21 ] == NULL )
return - V_19 ;
V_12 = F_3 ( V_9 [ V_21 ] ) ;
V_18 = F_4 ( V_12 -> V_22 , V_6 , V_8 ) ;
if ( ! V_18 ) {
V_18 = F_5 ( V_12 -> V_22 , V_4 , V_6 , sizeof( * V_16 ) , V_8 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_13 = V_23 ;
} else {
if ( V_8 )
return 0 ;
F_8 ( V_18 , V_8 , V_6 -> V_24 -> V_25 ) ;
if ( ! V_7 )
return - V_26 ;
}
V_16 = F_9 ( V_18 ) ;
F_10 ( & V_16 -> V_27 ) ;
V_16 -> V_28 = V_12 -> V_28 ;
V_16 -> V_29 = V_12 -> V_29 ;
V_16 -> V_30 = V_12 -> V_30 ;
V_16 -> V_31 = V_12 -> V_31 ;
V_16 -> V_32 = V_12 -> V_33 ;
F_11 ( & V_16 -> V_27 ) ;
if ( V_13 == V_23 )
F_12 ( V_18 , V_6 -> V_24 -> V_25 ) ;
return V_13 ;
}
static int F_13 ( struct V_5 * V_6 , int V_8 )
{
struct V_15 * V_16 = V_6 -> V_34 ;
return F_8 ( & V_16 -> V_35 , V_8 , & V_36 ) ;
}
static int V_15 ( struct V_37 * V_38 , const struct V_5 * V_6 ,
struct V_39 * V_40 )
{
struct V_15 * V_16 = V_6 -> V_34 ;
struct V_41 * V_42 ;
T_1 V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_43 ;
int V_44 ;
int V_33 ;
int V_45 ;
int V_46 ;
F_14 ( & V_16 -> V_27 ) ;
V_16 -> V_47 . V_48 = V_49 ;
V_28 = V_16 -> V_28 ;
V_29 = V_16 -> V_29 ;
V_30 = V_16 -> V_30 ;
V_44 = V_16 -> V_31 & V_50 ;
V_33 = V_16 -> V_32 ;
F_15 ( & V_16 -> V_51 , V_38 ) ;
F_16 ( & V_16 -> V_27 ) ;
if ( F_17 ( V_33 == V_52 ) )
goto V_53;
V_46 = F_18 ( V_38 ) ;
if ( ! F_19 ( V_38 , sizeof( * V_42 ) + V_46 ) )
goto V_53;
V_42 = F_20 ( V_38 ) ;
if ( V_44 )
V_43 = V_42 -> V_54 ;
else
V_43 = V_42 -> V_55 ;
if ( ! ( ( V_28 ^ V_43 ) & V_30 ) ) {
if ( F_21 ( V_38 ) &&
! F_22 ( V_38 , sizeof( * V_42 ) + V_46 ) &&
F_23 ( V_38 , 0 , 0 , V_56 ) )
goto V_53;
V_29 &= V_30 ;
V_29 |= V_43 & ~ V_30 ;
V_42 = F_20 ( V_38 ) ;
if ( V_44 )
V_42 -> V_54 = V_29 ;
else
V_42 -> V_55 = V_29 ;
F_24 ( & V_42 -> V_57 , V_43 , V_29 ) ;
} else if ( ( V_42 -> V_58 & F_25 ( V_59 ) ) ||
V_42 -> V_60 != V_61 ) {
goto V_62;
}
V_45 = V_42 -> V_45 * 4 ;
switch ( V_42 -> V_58 & F_25 ( V_59 ) ? 0 : V_42 -> V_60 ) {
case V_63 :
{
struct V_64 * V_65 ;
if ( ! F_19 ( V_38 , V_45 + sizeof( * V_65 ) + V_46 ) ||
( F_21 ( V_38 ) &&
! F_22 ( V_38 , V_45 + sizeof( * V_65 ) + V_46 ) &&
F_23 ( V_38 , 0 , 0 , V_56 ) ) )
goto V_53;
V_65 = ( void * ) ( F_26 ( V_38 ) + V_45 ) ;
F_27 ( & V_65 -> V_57 , V_38 , V_43 , V_29 , 1 ) ;
break;
}
case V_66 :
{
struct V_67 * V_68 ;
if ( ! F_19 ( V_38 , V_45 + sizeof( * V_68 ) + V_46 ) ||
( F_21 ( V_38 ) &&
! F_22 ( V_38 , V_45 + sizeof( * V_68 ) + V_46 ) &&
F_23 ( V_38 , 0 , 0 , V_56 ) ) )
goto V_53;
V_68 = ( void * ) ( F_26 ( V_38 ) + V_45 ) ;
if ( V_68 -> V_57 || V_38 -> V_69 == V_70 ) {
F_27 ( & V_68 -> V_57 , V_38 , V_43 ,
V_29 , 1 ) ;
if ( ! V_68 -> V_57 )
V_68 -> V_57 = V_71 ;
}
break;
}
case V_61 :
{
struct V_72 * V_73 ;
if ( ! F_19 ( V_38 , V_45 + sizeof( * V_73 ) + V_46 ) )
goto V_53;
V_73 = ( void * ) ( F_26 ( V_38 ) + V_45 ) ;
if ( ( V_73 -> type != V_74 ) &&
( V_73 -> type != V_75 ) &&
( V_73 -> type != V_76 ) )
break;
if ( ! F_19 ( V_38 , V_45 + sizeof( * V_73 ) + sizeof( * V_42 ) +
V_46 ) )
goto V_53;
V_73 = ( void * ) ( F_26 ( V_38 ) + V_45 ) ;
V_42 = ( void * ) ( V_73 + 1 ) ;
if ( V_44 )
V_43 = V_42 -> V_55 ;
else
V_43 = V_42 -> V_54 ;
if ( ( V_28 ^ V_43 ) & V_30 )
break;
if ( F_21 ( V_38 ) &&
! F_22 ( V_38 , V_45 + sizeof( * V_73 ) +
sizeof( * V_42 ) + V_46 ) &&
F_23 ( V_38 , 0 , 0 , V_56 ) )
goto V_53;
V_73 = ( void * ) ( F_26 ( V_38 ) + V_45 ) ;
V_42 = ( void * ) ( V_73 + 1 ) ;
V_29 &= V_30 ;
V_29 |= V_43 & ~ V_30 ;
if ( V_44 )
V_42 -> V_55 = V_29 ;
else
V_42 -> V_54 = V_29 ;
F_27 ( & V_73 -> V_77 , V_38 , V_43 , V_29 ,
0 ) ;
break;
}
default:
break;
}
V_62:
return V_33 ;
V_53:
F_14 ( & V_16 -> V_27 ) ;
V_16 -> V_78 . V_79 ++ ;
F_16 ( & V_16 -> V_27 ) ;
return V_52 ;
}
static int F_28 ( struct V_37 * V_38 , struct V_5 * V_6 ,
int V_8 , int V_80 )
{
unsigned char * V_81 = F_29 ( V_38 ) ;
struct V_15 * V_16 = V_6 -> V_34 ;
struct V_11 V_82 = {
. V_28 = V_16 -> V_28 ,
. V_29 = V_16 -> V_29 ,
. V_30 = V_16 -> V_30 ,
. V_31 = V_16 -> V_31 ,
. V_22 = V_16 -> V_83 ,
. V_33 = V_16 -> V_32 ,
. V_84 = V_16 -> V_85 - V_80 ,
. V_86 = V_16 -> V_87 - V_8 ,
} ;
struct V_88 V_89 ;
if ( F_30 ( V_38 , V_21 , sizeof( V_82 ) , & V_82 ) )
goto V_90;
V_89 . V_91 = F_31 ( V_49 - V_16 -> V_47 . V_91 ) ;
V_89 . V_48 = F_31 ( V_49 - V_16 -> V_47 . V_48 ) ;
V_89 . V_92 = F_31 ( V_16 -> V_47 . V_92 ) ;
if ( F_30 ( V_38 , V_93 , sizeof( V_89 ) , & V_89 ) )
goto V_90;
return V_38 -> V_94 ;
V_90:
F_32 ( V_38 , V_81 ) ;
return - 1 ;
}
static int T_2 F_33 ( void )
{
int V_14 = F_34 ( & V_36 , V_95 ) ;
if ( V_14 )
return V_14 ;
return F_35 ( & V_96 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_96 ) ;
F_38 ( & V_36 ) ;
}
