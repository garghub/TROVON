static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_2 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
struct V_2 * V_12 [ V_13 + 1 ] ;
struct V_14 * V_15 ;
int V_16 = 0 , V_17 ;
struct V_18 * V_19 ;
if ( V_3 == NULL )
return - V_20 ;
V_17 = F_3 ( V_12 , V_13 , V_3 , V_21 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_12 [ V_22 ] == NULL )
return - V_20 ;
V_15 = F_4 ( V_12 [ V_22 ] ) ;
if ( ! F_5 ( V_10 , V_15 -> V_23 , V_6 , V_8 ) ) {
V_16 = F_6 ( V_10 , V_15 -> V_23 , V_4 , V_6 ,
sizeof( * V_19 ) , V_8 , false ) ;
if ( V_16 )
return V_16 ;
V_16 = V_24 ;
} else {
if ( V_8 )
return 0 ;
F_7 ( V_6 , V_8 ) ;
if ( ! V_7 )
return - V_25 ;
}
V_19 = F_8 ( V_6 ) ;
F_9 ( & V_19 -> V_26 ) ;
V_19 -> V_27 = V_15 -> V_27 ;
V_19 -> V_28 = V_15 -> V_28 ;
V_19 -> V_29 = V_15 -> V_29 ;
V_19 -> V_30 = V_15 -> V_30 ;
V_19 -> V_31 = V_15 -> V_32 ;
F_10 ( & V_19 -> V_26 ) ;
if ( V_16 == V_24 )
F_11 ( V_10 , V_6 ) ;
return V_16 ;
}
static int V_18 ( struct V_33 * V_34 , const struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_18 * V_19 = V_6 -> V_37 ;
struct V_38 * V_39 ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_29 ;
T_1 V_40 ;
int V_41 ;
int V_32 ;
int V_42 ;
int V_43 ;
F_12 ( & V_19 -> V_26 ) ;
V_19 -> V_44 . V_45 = V_46 ;
V_27 = V_19 -> V_27 ;
V_28 = V_19 -> V_28 ;
V_29 = V_19 -> V_29 ;
V_41 = V_19 -> V_30 & V_47 ;
V_32 = V_19 -> V_31 ;
F_13 ( & V_19 -> V_48 , V_34 ) ;
F_14 ( & V_19 -> V_26 ) ;
if ( F_15 ( V_32 == V_49 ) )
goto V_50;
V_43 = F_16 ( V_34 ) ;
if ( ! F_17 ( V_34 , sizeof( * V_39 ) + V_43 ) )
goto V_50;
V_39 = F_18 ( V_34 ) ;
if ( V_41 )
V_40 = V_39 -> V_51 ;
else
V_40 = V_39 -> V_52 ;
if ( ! ( ( V_27 ^ V_40 ) & V_29 ) ) {
if ( F_19 ( V_34 , sizeof( * V_39 ) + V_43 ) )
goto V_50;
V_28 &= V_29 ;
V_28 |= V_40 & ~ V_29 ;
V_39 = F_18 ( V_34 ) ;
if ( V_41 )
V_39 -> V_51 = V_28 ;
else
V_39 -> V_52 = V_28 ;
F_20 ( & V_39 -> V_53 , V_40 , V_28 ) ;
} else if ( ( V_39 -> V_54 & F_21 ( V_55 ) ) ||
V_39 -> V_56 != V_57 ) {
goto V_58;
}
V_42 = V_39 -> V_42 * 4 ;
switch ( V_39 -> V_54 & F_21 ( V_55 ) ? 0 : V_39 -> V_56 ) {
case V_59 :
{
struct V_60 * V_61 ;
if ( ! F_17 ( V_34 , V_42 + sizeof( * V_61 ) + V_43 ) ||
F_19 ( V_34 , V_42 + sizeof( * V_61 ) + V_43 ) )
goto V_50;
V_61 = ( void * ) ( F_22 ( V_34 ) + V_42 ) ;
F_23 ( & V_61 -> V_53 , V_34 , V_40 , V_28 ,
true ) ;
break;
}
case V_62 :
{
struct V_63 * V_64 ;
if ( ! F_17 ( V_34 , V_42 + sizeof( * V_64 ) + V_43 ) ||
F_19 ( V_34 , V_42 + sizeof( * V_64 ) + V_43 ) )
goto V_50;
V_64 = ( void * ) ( F_22 ( V_34 ) + V_42 ) ;
if ( V_64 -> V_53 || V_34 -> V_65 == V_66 ) {
F_23 ( & V_64 -> V_53 , V_34 , V_40 ,
V_28 , true ) ;
if ( ! V_64 -> V_53 )
V_64 -> V_53 = V_67 ;
}
break;
}
case V_57 :
{
struct V_68 * V_69 ;
if ( ! F_17 ( V_34 , V_42 + sizeof( * V_69 ) + V_43 ) )
goto V_50;
V_69 = ( void * ) ( F_22 ( V_34 ) + V_42 ) ;
if ( ( V_69 -> type != V_70 ) &&
( V_69 -> type != V_71 ) &&
( V_69 -> type != V_72 ) )
break;
if ( ! F_17 ( V_34 , V_42 + sizeof( * V_69 ) + sizeof( * V_39 ) +
V_43 ) )
goto V_50;
V_69 = ( void * ) ( F_22 ( V_34 ) + V_42 ) ;
V_39 = ( void * ) ( V_69 + 1 ) ;
if ( V_41 )
V_40 = V_39 -> V_52 ;
else
V_40 = V_39 -> V_51 ;
if ( ( V_27 ^ V_40 ) & V_29 )
break;
if ( F_19 ( V_34 , V_42 + sizeof( * V_69 ) +
sizeof( * V_39 ) + V_43 ) )
goto V_50;
V_69 = ( void * ) ( F_22 ( V_34 ) + V_42 ) ;
V_39 = ( void * ) ( V_69 + 1 ) ;
V_28 &= V_29 ;
V_28 |= V_40 & ~ V_29 ;
if ( V_41 )
V_39 -> V_52 = V_28 ;
else
V_39 -> V_51 = V_28 ;
F_23 ( & V_69 -> V_73 , V_34 , V_40 , V_28 ,
false ) ;
break;
}
default:
break;
}
V_58:
return V_32 ;
V_50:
F_12 ( & V_19 -> V_26 ) ;
V_19 -> V_74 . V_75 ++ ;
F_14 ( & V_19 -> V_26 ) ;
return V_49 ;
}
static int F_24 ( struct V_33 * V_34 , struct V_5 * V_6 ,
int V_8 , int V_76 )
{
unsigned char * V_77 = F_25 ( V_34 ) ;
struct V_18 * V_19 = V_6 -> V_37 ;
struct V_14 V_78 = {
. V_27 = V_19 -> V_27 ,
. V_28 = V_19 -> V_28 ,
. V_29 = V_19 -> V_29 ,
. V_30 = V_19 -> V_30 ,
. V_23 = V_19 -> V_79 ,
. V_32 = V_19 -> V_31 ,
. V_80 = V_19 -> V_81 - V_76 ,
. V_82 = V_19 -> V_83 - V_8 ,
} ;
struct V_84 V_85 ;
if ( F_26 ( V_34 , V_22 , sizeof( V_78 ) , & V_78 ) )
goto V_86;
V_85 . V_87 = F_27 ( V_46 - V_19 -> V_44 . V_87 ) ;
V_85 . V_45 = F_27 ( V_46 - V_19 -> V_44 . V_45 ) ;
V_85 . V_88 = F_27 ( V_19 -> V_44 . V_88 ) ;
if ( F_26 ( V_34 , V_89 , sizeof( V_85 ) , & V_85 ) )
goto V_86;
return V_34 -> V_90 ;
V_86:
F_28 ( V_34 , V_77 ) ;
return - 1 ;
}
static int F_29 ( struct V_1 * V_1 , struct V_33 * V_34 ,
struct V_91 * V_92 , int type ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_30 ( V_10 , V_34 , V_92 , type , V_6 ) ;
}
static int F_31 ( struct V_1 * V_1 , struct V_5 * V_6 , T_2 V_23 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_32 ( V_10 , V_6 , V_23 ) ;
}
static T_3 int F_33 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_34 ( V_10 , & V_93 , V_94 ) ;
}
static void T_4 F_35 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_36 ( V_10 ) ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_93 , & V_95 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_93 , & V_95 ) ;
}
