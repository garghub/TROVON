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
V_18 = F_4 ( V_12 -> V_22 , V_6 , V_8 , & V_23 ) ;
if ( ! V_18 ) {
V_18 = F_5 ( V_12 -> V_22 , V_4 , V_6 , sizeof( * V_16 ) , V_8 ,
& V_24 , & V_23 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_13 = V_25 ;
} else {
if ( V_8 )
return 0 ;
F_8 ( V_18 , V_8 , & V_23 ) ;
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
if ( V_13 == V_25 )
F_12 ( V_18 , & V_23 ) ;
return V_13 ;
}
static int F_13 ( struct V_5 * V_6 , int V_8 )
{
struct V_15 * V_16 = V_6 -> V_34 ;
return F_8 ( & V_16 -> V_35 , V_8 , & V_23 ) ;
}
static int V_15 ( struct V_36 * V_37 , const struct V_5 * V_6 ,
struct V_38 * V_39 )
{
struct V_15 * V_16 = V_6 -> V_34 ;
struct V_40 * V_41 ;
T_1 V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_42 ;
int V_43 ;
int V_33 ;
int V_44 ;
int V_45 ;
F_14 ( & V_16 -> V_27 ) ;
V_16 -> V_46 . V_47 = V_48 ;
V_28 = V_16 -> V_28 ;
V_29 = V_16 -> V_29 ;
V_30 = V_16 -> V_30 ;
V_43 = V_16 -> V_31 & V_49 ;
V_33 = V_16 -> V_32 ;
F_15 ( & V_16 -> V_50 , V_37 ) ;
F_16 ( & V_16 -> V_27 ) ;
if ( F_17 ( V_33 == V_51 ) )
goto V_52;
V_45 = F_18 ( V_37 ) ;
if ( ! F_19 ( V_37 , sizeof( * V_41 ) + V_45 ) )
goto V_52;
V_41 = F_20 ( V_37 ) ;
if ( V_43 )
V_42 = V_41 -> V_53 ;
else
V_42 = V_41 -> V_54 ;
if ( ! ( ( V_28 ^ V_42 ) & V_30 ) ) {
if ( F_21 ( V_37 ) &&
! F_22 ( V_37 , sizeof( * V_41 ) + V_45 ) &&
F_23 ( V_37 , 0 , 0 , V_55 ) )
goto V_52;
V_29 &= V_30 ;
V_29 |= V_42 & ~ V_30 ;
V_41 = F_20 ( V_37 ) ;
if ( V_43 )
V_41 -> V_53 = V_29 ;
else
V_41 -> V_54 = V_29 ;
F_24 ( & V_41 -> V_56 , V_42 , V_29 ) ;
} else if ( ( V_41 -> V_57 & F_25 ( V_58 ) ) ||
V_41 -> V_59 != V_60 ) {
goto V_61;
}
V_44 = V_41 -> V_44 * 4 ;
switch ( V_41 -> V_57 & F_25 ( V_58 ) ? 0 : V_41 -> V_59 ) {
case V_62 :
{
struct V_63 * V_64 ;
if ( ! F_19 ( V_37 , V_44 + sizeof( * V_64 ) + V_45 ) ||
( F_21 ( V_37 ) &&
! F_22 ( V_37 , V_44 + sizeof( * V_64 ) + V_45 ) &&
F_23 ( V_37 , 0 , 0 , V_55 ) ) )
goto V_52;
V_64 = ( void * ) ( F_26 ( V_37 ) + V_44 ) ;
F_27 ( & V_64 -> V_56 , V_37 , V_42 , V_29 , 1 ) ;
break;
}
case V_65 :
{
struct V_66 * V_67 ;
if ( ! F_19 ( V_37 , V_44 + sizeof( * V_67 ) + V_45 ) ||
( F_21 ( V_37 ) &&
! F_22 ( V_37 , V_44 + sizeof( * V_67 ) + V_45 ) &&
F_23 ( V_37 , 0 , 0 , V_55 ) ) )
goto V_52;
V_67 = ( void * ) ( F_26 ( V_37 ) + V_44 ) ;
if ( V_67 -> V_56 || V_37 -> V_68 == V_69 ) {
F_27 ( & V_67 -> V_56 , V_37 , V_42 ,
V_29 , 1 ) ;
if ( ! V_67 -> V_56 )
V_67 -> V_56 = V_70 ;
}
break;
}
case V_60 :
{
struct V_71 * V_72 ;
if ( ! F_19 ( V_37 , V_44 + sizeof( * V_72 ) + V_45 ) )
goto V_52;
V_72 = ( void * ) ( F_26 ( V_37 ) + V_44 ) ;
if ( ( V_72 -> type != V_73 ) &&
( V_72 -> type != V_74 ) &&
( V_72 -> type != V_75 ) )
break;
if ( ! F_19 ( V_37 , V_44 + sizeof( * V_72 ) + sizeof( * V_41 ) +
V_45 ) )
goto V_52;
V_72 = ( void * ) ( F_26 ( V_37 ) + V_44 ) ;
V_41 = ( void * ) ( V_72 + 1 ) ;
if ( V_43 )
V_42 = V_41 -> V_54 ;
else
V_42 = V_41 -> V_53 ;
if ( ( V_28 ^ V_42 ) & V_30 )
break;
if ( F_21 ( V_37 ) &&
! F_22 ( V_37 , V_44 + sizeof( * V_72 ) +
sizeof( * V_41 ) + V_45 ) &&
F_23 ( V_37 , 0 , 0 , V_55 ) )
goto V_52;
V_72 = ( void * ) ( F_26 ( V_37 ) + V_44 ) ;
V_41 = ( void * ) ( V_72 + 1 ) ;
V_29 &= V_30 ;
V_29 |= V_42 & ~ V_30 ;
if ( V_43 )
V_41 -> V_54 = V_29 ;
else
V_41 -> V_53 = V_29 ;
F_27 ( & V_72 -> V_76 , V_37 , V_42 , V_29 ,
0 ) ;
break;
}
default:
break;
}
V_61:
return V_33 ;
V_52:
F_14 ( & V_16 -> V_27 ) ;
V_16 -> V_77 . V_78 ++ ;
F_16 ( & V_16 -> V_27 ) ;
return V_51 ;
}
static int F_28 ( struct V_36 * V_37 , struct V_5 * V_6 ,
int V_8 , int V_79 )
{
unsigned char * V_80 = F_29 ( V_37 ) ;
struct V_15 * V_16 = V_6 -> V_34 ;
struct V_11 V_81 = {
. V_28 = V_16 -> V_28 ,
. V_29 = V_16 -> V_29 ,
. V_30 = V_16 -> V_30 ,
. V_31 = V_16 -> V_31 ,
. V_22 = V_16 -> V_82 ,
. V_33 = V_16 -> V_32 ,
. V_83 = V_16 -> V_84 - V_79 ,
. V_85 = V_16 -> V_86 - V_8 ,
} ;
struct V_87 V_88 ;
if ( F_30 ( V_37 , V_21 , sizeof( V_81 ) , & V_81 ) )
goto V_89;
V_88 . V_90 = F_31 ( V_48 - V_16 -> V_46 . V_90 ) ;
V_88 . V_47 = F_31 ( V_48 - V_16 -> V_46 . V_47 ) ;
V_88 . V_91 = F_31 ( V_16 -> V_46 . V_91 ) ;
if ( F_30 ( V_37 , V_92 , sizeof( V_88 ) , & V_88 ) )
goto V_89;
return V_37 -> V_93 ;
V_89:
F_32 ( V_37 , V_80 ) ;
return - 1 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_94 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_94 ) ;
}
