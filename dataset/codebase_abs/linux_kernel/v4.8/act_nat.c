static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_2 * V_4 ,
struct V_5 * * V_6 , int V_7 , int V_8 )
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
& V_24 , V_8 , false ) ;
if ( V_16 )
return V_16 ;
V_16 = V_25 ;
} else {
if ( V_8 )
return 0 ;
F_7 ( * V_6 , V_8 ) ;
if ( ! V_7 )
return - V_26 ;
}
V_19 = F_8 ( * V_6 ) ;
F_9 ( & V_19 -> V_27 ) ;
V_19 -> V_28 = V_15 -> V_28 ;
V_19 -> V_29 = V_15 -> V_29 ;
V_19 -> V_30 = V_15 -> V_30 ;
V_19 -> V_31 = V_15 -> V_31 ;
V_19 -> V_32 = V_15 -> V_33 ;
F_10 ( & V_19 -> V_27 ) ;
if ( V_16 == V_25 )
F_11 ( V_10 , * V_6 ) ;
return V_16 ;
}
static int V_18 ( struct V_34 * V_35 , const struct V_5 * V_6 ,
struct V_36 * V_37 )
{
struct V_18 * V_19 = F_8 ( V_6 ) ;
struct V_38 * V_39 ;
T_1 V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_40 ;
int V_41 ;
int V_33 ;
int V_42 ;
int V_43 ;
F_12 ( & V_19 -> V_27 ) ;
F_13 ( & V_19 -> V_44 ) ;
V_28 = V_19 -> V_28 ;
V_29 = V_19 -> V_29 ;
V_30 = V_19 -> V_30 ;
V_41 = V_19 -> V_31 & V_45 ;
V_33 = V_19 -> V_32 ;
F_14 ( & V_19 -> V_46 , V_35 ) ;
F_15 ( & V_19 -> V_27 ) ;
if ( F_16 ( V_33 == V_47 ) )
goto V_48;
V_43 = F_17 ( V_35 ) ;
if ( ! F_18 ( V_35 , sizeof( * V_39 ) + V_43 ) )
goto V_48;
V_39 = F_19 ( V_35 ) ;
if ( V_41 )
V_40 = V_39 -> V_49 ;
else
V_40 = V_39 -> V_50 ;
if ( ! ( ( V_28 ^ V_40 ) & V_30 ) ) {
if ( F_20 ( V_35 , sizeof( * V_39 ) + V_43 ) )
goto V_48;
V_29 &= V_30 ;
V_29 |= V_40 & ~ V_30 ;
V_39 = F_19 ( V_35 ) ;
if ( V_41 )
V_39 -> V_49 = V_29 ;
else
V_39 -> V_50 = V_29 ;
F_21 ( & V_39 -> V_51 , V_40 , V_29 ) ;
} else if ( ( V_39 -> V_52 & F_22 ( V_53 ) ) ||
V_39 -> V_54 != V_55 ) {
goto V_56;
}
V_42 = V_39 -> V_42 * 4 ;
switch ( V_39 -> V_52 & F_22 ( V_53 ) ? 0 : V_39 -> V_54 ) {
case V_57 :
{
struct V_58 * V_59 ;
if ( ! F_18 ( V_35 , V_42 + sizeof( * V_59 ) + V_43 ) ||
F_20 ( V_35 , V_42 + sizeof( * V_59 ) + V_43 ) )
goto V_48;
V_59 = ( void * ) ( F_23 ( V_35 ) + V_42 ) ;
F_24 ( & V_59 -> V_51 , V_35 , V_40 , V_29 ,
true ) ;
break;
}
case V_60 :
{
struct V_61 * V_62 ;
if ( ! F_18 ( V_35 , V_42 + sizeof( * V_62 ) + V_43 ) ||
F_20 ( V_35 , V_42 + sizeof( * V_62 ) + V_43 ) )
goto V_48;
V_62 = ( void * ) ( F_23 ( V_35 ) + V_42 ) ;
if ( V_62 -> V_51 || V_35 -> V_63 == V_64 ) {
F_24 ( & V_62 -> V_51 , V_35 , V_40 ,
V_29 , true ) ;
if ( ! V_62 -> V_51 )
V_62 -> V_51 = V_65 ;
}
break;
}
case V_55 :
{
struct V_66 * V_67 ;
if ( ! F_18 ( V_35 , V_42 + sizeof( * V_67 ) + V_43 ) )
goto V_48;
V_67 = ( void * ) ( F_23 ( V_35 ) + V_42 ) ;
if ( ( V_67 -> type != V_68 ) &&
( V_67 -> type != V_69 ) &&
( V_67 -> type != V_70 ) )
break;
if ( ! F_18 ( V_35 , V_42 + sizeof( * V_67 ) + sizeof( * V_39 ) +
V_43 ) )
goto V_48;
V_67 = ( void * ) ( F_23 ( V_35 ) + V_42 ) ;
V_39 = ( void * ) ( V_67 + 1 ) ;
if ( V_41 )
V_40 = V_39 -> V_50 ;
else
V_40 = V_39 -> V_49 ;
if ( ( V_28 ^ V_40 ) & V_30 )
break;
if ( F_20 ( V_35 , V_42 + sizeof( * V_67 ) +
sizeof( * V_39 ) + V_43 ) )
goto V_48;
V_67 = ( void * ) ( F_23 ( V_35 ) + V_42 ) ;
V_39 = ( void * ) ( V_67 + 1 ) ;
V_29 &= V_30 ;
V_29 |= V_40 & ~ V_30 ;
if ( V_41 )
V_39 -> V_50 = V_29 ;
else
V_39 -> V_49 = V_29 ;
F_24 ( & V_67 -> V_71 , V_35 , V_40 , V_29 ,
false ) ;
break;
}
default:
break;
}
V_56:
return V_33 ;
V_48:
F_12 ( & V_19 -> V_27 ) ;
V_19 -> V_72 . V_73 ++ ;
F_15 ( & V_19 -> V_27 ) ;
return V_47 ;
}
static int F_25 ( struct V_34 * V_35 , struct V_5 * V_6 ,
int V_8 , int V_74 )
{
unsigned char * V_75 = F_26 ( V_35 ) ;
struct V_18 * V_19 = F_8 ( V_6 ) ;
struct V_14 V_76 = {
. V_28 = V_19 -> V_28 ,
. V_29 = V_19 -> V_29 ,
. V_30 = V_19 -> V_30 ,
. V_31 = V_19 -> V_31 ,
. V_23 = V_19 -> V_77 ,
. V_33 = V_19 -> V_32 ,
. V_78 = V_19 -> V_79 - V_74 ,
. V_80 = V_19 -> V_81 - V_8 ,
} ;
struct V_82 V_83 ;
if ( F_27 ( V_35 , V_22 , sizeof( V_76 ) , & V_76 ) )
goto V_84;
F_28 ( & V_83 , & V_19 -> V_44 ) ;
if ( F_29 ( V_35 , V_85 , sizeof( V_83 ) , & V_83 , V_86 ) )
goto V_84;
return V_35 -> V_87 ;
V_84:
F_30 ( V_35 , V_75 ) ;
return - 1 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_34 * V_35 ,
struct V_88 * V_89 , int type ,
const struct V_90 * V_91 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_32 ( V_10 , V_35 , V_89 , type , V_91 ) ;
}
static int F_33 ( struct V_1 * V_1 , struct V_5 * * V_6 , T_2 V_23 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_34 ( V_10 , V_6 , V_23 ) ;
}
static T_3 int F_35 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_36 ( V_10 , & V_24 , V_92 ) ;
}
static void T_4 F_37 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_38 ( V_10 ) ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_24 , & V_93 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_24 , & V_93 ) ;
}
