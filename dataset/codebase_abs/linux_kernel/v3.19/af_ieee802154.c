struct V_1 *
F_1 ( struct V_2 * V_2 , const struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_1 * V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 [ V_10 ] ;
switch ( V_4 -> V_11 ) {
case V_12 :
F_2 ( V_9 , V_4 -> V_13 ) ;
F_3 () ;
V_5 = F_4 ( V_2 , V_14 , V_9 ) ;
if ( V_5 )
F_5 ( V_5 ) ;
F_6 () ;
break;
case V_15 :
if ( V_4 -> V_7 == F_7 ( V_16 ) ||
V_4 -> V_8 == F_7 ( V_17 ) ||
V_4 -> V_8 == F_7 ( V_18 ) )
break;
F_8 () ;
F_9 (net, tmp) {
if ( V_6 -> type != V_14 )
continue;
V_7 = F_10 ( V_6 ) -> F_11 ( V_6 ) ;
V_8 =
F_10 ( V_6 ) -> F_12 ( V_6 ) ;
if ( V_7 == V_4 -> V_7 &&
V_8 == V_4 -> V_8 ) {
V_5 = V_6 ;
F_5 ( V_5 ) ;
break;
}
}
F_13 () ;
break;
default:
F_14 ( L_1 ,
V_4 -> V_11 ) ;
break;
}
return V_5 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_21 ) {
V_20 -> V_21 = NULL ;
V_21 -> V_22 -> V_23 ( V_21 , 0 ) ;
}
return 0 ;
}
static int F_16 ( struct V_24 * V_25 , struct V_19 * V_20 ,
struct V_26 * V_27 , T_3 V_28 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
return V_21 -> V_22 -> V_29 ( V_25 , V_21 , V_27 , V_28 ) ;
}
static int F_17 ( struct V_19 * V_20 , struct V_30 * V_31 ,
int V_32 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_21 -> V_22 -> V_33 )
return V_21 -> V_22 -> V_33 ( V_21 , V_31 , V_32 ) ;
return F_18 ( V_20 , V_31 , V_32 ) ;
}
static int F_19 ( struct V_19 * V_20 , struct V_30 * V_31 ,
int V_32 , int V_34 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_32 < sizeof( V_31 -> V_35 ) )
return - V_36 ;
if ( V_31 -> V_35 == V_37 )
return V_21 -> V_22 -> V_38 ( V_21 , V_34 ) ;
return V_21 -> V_22 -> V_39 ( V_21 , V_31 , V_32 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_40 T_4 * V_41 ,
unsigned int V_42 )
{
struct V_40 V_43 ;
int V_44 = - V_45 ;
struct V_1 * V_5 ;
if ( F_21 ( & V_43 , V_41 , sizeof( struct V_40 ) ) )
return - V_46 ;
V_43 . V_47 [ V_48 - 1 ] = 0 ;
F_22 ( F_23 ( V_21 ) , V_43 . V_47 ) ;
V_5 = F_24 ( F_23 ( V_21 ) , V_43 . V_47 ) ;
if ( ! V_5 )
return - V_49 ;
if ( V_5 -> type == V_14 && V_5 -> V_50 -> V_51 )
V_44 = V_5 -> V_50 -> V_51 ( V_5 , & V_43 , V_42 ) ;
if ( ! V_44 && F_25 ( V_41 , & V_43 , sizeof( struct V_40 ) ) )
V_44 = - V_46 ;
F_26 ( V_5 ) ;
return V_44 ;
}
static int F_27 ( struct V_19 * V_20 , unsigned int V_42 ,
unsigned long V_41 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
switch ( V_42 ) {
case V_52 :
return F_28 ( V_21 , (struct V_53 T_4 * ) V_41 ) ;
case V_54 :
return F_29 ( V_21 , (struct V_55 T_4 * ) V_41 ) ;
case V_56 :
case V_57 :
return F_20 ( V_21 , (struct V_40 T_4 * ) V_41 ,
V_42 ) ;
default:
if ( ! V_21 -> V_22 -> V_58 )
return - V_45 ;
return V_21 -> V_22 -> V_58 ( V_21 , V_42 , V_41 ) ;
}
}
static int F_30 ( struct V_2 * V_2 , struct V_19 * V_20 ,
int V_59 , int V_60 )
{
struct V_20 * V_21 ;
int V_61 ;
struct V_62 * V_62 ;
const struct V_63 * V_64 ;
if ( ! F_31 ( V_2 , & V_65 ) )
return - V_66 ;
switch ( V_20 -> type ) {
case V_67 :
V_62 = & V_68 ;
V_64 = & V_69 ;
break;
case V_70 :
V_62 = & V_71 ;
V_64 = & V_72 ;
break;
default:
V_61 = - V_73 ;
goto V_74;
}
V_61 = - V_75 ;
V_21 = F_32 ( V_2 , V_76 , V_77 , V_62 ) ;
if ( ! V_21 )
goto V_74;
V_61 = 0 ;
V_20 -> V_64 = V_64 ;
F_33 ( V_20 , V_21 ) ;
V_21 -> V_78 = V_76 ;
F_34 ( V_21 , V_79 ) ;
if ( V_21 -> V_22 -> V_80 )
V_21 -> V_22 -> V_80 ( V_21 ) ;
if ( V_21 -> V_22 -> V_81 ) {
V_61 = V_21 -> V_22 -> V_81 ( V_21 ) ;
if ( V_61 )
F_35 ( V_21 ) ;
}
V_74:
return V_61 ;
}
static int F_36 ( struct V_82 * V_83 , struct V_1 * V_5 ,
struct V_84 * V_85 , struct V_1 * V_86 )
{
if ( ! F_37 ( V_5 ) )
goto V_87;
F_38 ( L_2 , V_5 -> type , V_5 ) ;
#ifdef F_39
F_40 ( L_3 ,
V_88 , V_83 -> V_89 , V_83 -> V_28 ) ;
#endif
if ( ! F_31 ( F_41 ( V_5 ) , & V_65 ) )
goto V_87;
F_42 ( V_5 , V_83 ) ;
if ( V_5 -> type != V_14 )
goto V_87;
if ( V_83 -> V_90 != V_91 )
return F_43 ( V_5 , V_83 ) ;
V_87:
F_44 ( V_83 ) ;
return V_92 ;
}
static int T_5 F_45 ( void )
{
int V_61 = - V_36 ;
V_61 = F_46 ( & V_68 , 1 ) ;
if ( V_61 )
goto V_74;
V_61 = F_46 ( & V_71 , 1 ) ;
if ( V_61 )
goto V_93;
V_61 = F_47 ( & V_94 ) ;
if ( V_61 )
goto V_95;
F_48 ( & V_96 ) ;
V_61 = 0 ;
goto V_74;
V_95:
F_49 ( & V_71 ) ;
V_93:
F_49 ( & V_68 ) ;
V_74:
return V_61 ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_96 ) ;
F_52 ( V_76 ) ;
F_49 ( & V_71 ) ;
F_49 ( & V_68 ) ;
}
