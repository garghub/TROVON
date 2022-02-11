struct V_1 * F_1 ( struct V_2 * V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_1 * V_6 ;
T_1 V_7 , V_8 ;
switch ( V_4 -> V_9 ) {
case V_10 :
F_2 () ;
V_5 = F_3 ( V_2 , V_11 , V_4 -> V_12 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
F_5 () ;
break;
case V_13 :
if ( V_4 -> V_7 == 0xffff ||
V_4 -> V_8 == V_14 ||
V_4 -> V_8 == 0xffff )
break;
F_6 () ;
F_7 (net, tmp) {
if ( V_6 -> type != V_11 )
continue;
V_7 = F_8 ( V_6 ) -> F_9 ( V_6 ) ;
V_8 =
F_8 ( V_6 ) -> F_10 ( V_6 ) ;
if ( V_7 == V_4 -> V_7 &&
V_8 == V_4 -> V_8 ) {
V_5 = V_6 ;
F_4 ( V_5 ) ;
break;
}
}
F_11 () ;
break;
default:
F_12 ( L_1 ,
V_4 -> V_9 ) ;
break;
}
return V_5 ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
if ( V_17 ) {
V_16 -> V_17 = NULL ;
V_17 -> V_18 -> V_19 ( V_17 , 0 ) ;
}
return 0 ;
}
static int F_14 ( struct V_20 * V_21 , struct V_15 * V_16 ,
struct V_22 * V_23 , T_2 V_24 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
return V_17 -> V_18 -> V_25 ( V_21 , V_17 , V_23 , V_24 ) ;
}
static int F_15 ( struct V_15 * V_16 , struct V_26 * V_27 ,
int V_28 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
if ( V_17 -> V_18 -> V_29 )
return V_17 -> V_18 -> V_29 ( V_17 , V_27 , V_28 ) ;
return F_16 ( V_16 , V_27 , V_28 ) ;
}
static int F_17 ( struct V_15 * V_16 , struct V_26 * V_27 ,
int V_28 , int V_30 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
if ( V_28 < sizeof( V_27 -> V_31 ) )
return - V_32 ;
if ( V_27 -> V_31 == V_33 )
return V_17 -> V_18 -> V_34 ( V_17 , V_30 ) ;
return V_17 -> V_18 -> V_35 ( V_17 , V_27 , V_28 ) ;
}
static int F_18 ( struct V_16 * V_17 , struct V_36 T_3 * V_37 ,
unsigned int V_38 )
{
struct V_36 V_39 ;
int V_40 = - V_41 ;
struct V_1 * V_5 ;
if ( F_19 ( & V_39 , V_37 , sizeof( struct V_36 ) ) )
return - V_42 ;
V_39 . V_43 [ V_44 - 1 ] = 0 ;
F_20 ( F_21 ( V_17 ) , V_39 . V_43 ) ;
V_5 = F_22 ( F_21 ( V_17 ) , V_39 . V_43 ) ;
if ( ! V_5 )
return - V_45 ;
if ( V_5 -> type == V_11 && V_5 -> V_46 -> V_47 )
V_40 = V_5 -> V_46 -> V_47 ( V_5 , & V_39 , V_38 ) ;
if ( ! V_40 && F_23 ( V_37 , & V_39 , sizeof( struct V_36 ) ) )
V_40 = - V_42 ;
F_24 ( V_5 ) ;
return V_40 ;
}
static int F_25 ( struct V_15 * V_16 , unsigned int V_38 ,
unsigned long V_37 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
switch ( V_38 ) {
case V_48 :
return F_26 ( V_17 , (struct V_49 T_3 * ) V_37 ) ;
case V_50 :
return F_27 ( V_17 , (struct V_51 T_3 * ) V_37 ) ;
case V_52 :
case V_53 :
return F_18 ( V_17 , (struct V_36 T_3 * ) V_37 ,
V_38 ) ;
default:
if ( ! V_17 -> V_18 -> V_54 )
return - V_41 ;
return V_17 -> V_18 -> V_54 ( V_17 , V_38 , V_37 ) ;
}
}
static int F_28 ( struct V_2 * V_2 , struct V_15 * V_16 ,
int V_55 , int V_56 )
{
struct V_16 * V_17 ;
int V_57 ;
struct V_58 * V_58 ;
const struct V_59 * V_60 ;
if ( ! F_29 ( V_2 , & V_61 ) )
return - V_62 ;
switch ( V_16 -> type ) {
case V_63 :
V_58 = & V_64 ;
V_60 = & V_65 ;
break;
case V_66 :
V_58 = & V_67 ;
V_60 = & V_68 ;
break;
default:
V_57 = - V_69 ;
goto V_70;
}
V_57 = - V_71 ;
V_17 = F_30 ( V_2 , V_72 , V_73 , V_58 ) ;
if ( ! V_17 )
goto V_70;
V_57 = 0 ;
V_16 -> V_60 = V_60 ;
F_31 ( V_16 , V_17 ) ;
V_17 -> V_74 = V_72 ;
F_32 ( V_17 , V_75 ) ;
if ( V_17 -> V_18 -> V_76 )
V_17 -> V_18 -> V_76 ( V_17 ) ;
if ( V_17 -> V_18 -> V_77 ) {
V_57 = V_17 -> V_18 -> V_77 ( V_17 ) ;
if ( V_57 )
F_33 ( V_17 ) ;
}
V_70:
return V_57 ;
}
static int F_34 ( struct V_78 * V_79 , struct V_1 * V_5 ,
struct V_80 * V_81 , struct V_1 * V_82 )
{
if ( ! F_35 ( V_5 ) )
goto V_83;
F_36 ( L_2 , V_5 -> type , V_5 ) ;
#ifdef F_37
F_38 ( L_3 , V_84 , V_79 -> V_85 , V_79 -> V_24 ) ;
#endif
if ( ! F_29 ( F_39 ( V_5 ) , & V_61 ) )
goto V_83;
F_40 ( V_5 , V_79 ) ;
if ( V_5 -> type != V_11 )
goto V_83;
if ( V_79 -> V_86 != V_87 )
return F_41 ( V_5 , V_79 ) ;
V_83:
F_42 ( V_79 ) ;
return V_88 ;
}
static int T_4 F_43 ( void )
{
int V_57 = - V_32 ;
V_57 = F_44 ( & V_64 , 1 ) ;
if ( V_57 )
goto V_70;
V_57 = F_44 ( & V_67 , 1 ) ;
if ( V_57 )
goto V_89;
V_57 = F_45 ( & V_90 ) ;
if ( V_57 )
goto V_91;
F_46 ( & V_92 ) ;
V_57 = 0 ;
goto V_70;
V_91:
F_47 ( & V_67 ) ;
V_89:
F_47 ( & V_64 ) ;
V_70:
return V_57 ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_92 ) ;
F_50 ( V_72 ) ;
F_47 ( & V_67 ) ;
F_47 ( & V_64 ) ;
}
