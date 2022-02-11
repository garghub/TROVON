static int F_1 ( struct V_1 * V_2 , int type , int V_3 ,
T_1 V_4 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
break;
case V_10 :
case V_11 :
if ( ( type == V_12 && F_2 () == V_4 ) ||
( type == V_13 && F_3 ( V_4 ) ) )
break;
default:
if ( ! F_4 ( V_14 ) )
return - V_15 ;
}
return F_5 ( V_3 , type , V_4 , V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 , void * V_16 )
{
if ( V_2 -> V_17 && V_2 -> V_17 -> V_18 )
V_2 -> V_17 -> V_18 ( V_2 , * ( int * ) V_16 , 1 ) ;
}
static int F_7 ( int type )
{
int V_19 ;
if ( type >= V_20 )
return - V_21 ;
V_19 = F_5 ( V_6 , type , 0 , NULL ) ;
if ( ! V_19 )
F_8 ( F_6 , & type ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
struct V_22 * V_22 )
{
if ( ! V_2 -> V_17 -> V_23 && ! V_2 -> V_17 -> V_24 )
return - V_25 ;
if ( V_2 -> V_17 -> V_24 )
return V_2 -> V_17 -> V_24 ( V_2 , type , V_4 ) ;
if ( F_10 ( V_22 ) )
return F_11 ( V_22 ) ;
return V_2 -> V_17 -> V_23 ( V_2 , type , V_4 , V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 , int type , void T_2 * V_26 )
{
T_3 V_27 ;
F_13 ( & F_14 ( V_2 ) -> V_28 ) ;
if ( ! F_15 ( V_2 , type ) ) {
F_16 ( & F_14 ( V_2 ) -> V_28 ) ;
return - V_29 ;
}
V_27 = F_14 ( V_2 ) -> V_30 [ type ] . V_31 -> V_32 ;
F_16 ( & F_14 ( V_2 ) -> V_28 ) ;
if ( F_17 ( V_26 , & V_27 , sizeof( V_27 ) ) )
return - V_33 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int type , void T_2 * V_26 )
{
struct V_34 V_30 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_35 )
return - V_25 ;
V_19 = V_2 -> V_17 -> V_35 ( V_2 , type , & V_30 ) ;
if ( ! V_19 && F_17 ( V_26 , & V_30 , sizeof( V_30 ) ) )
return - V_33 ;
return V_19 ;
}
static int F_19 ( struct V_1 * V_2 , int type , void T_2 * V_26 )
{
struct V_34 V_30 ;
if ( F_20 ( & V_30 , V_26 , sizeof( V_30 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_36 )
return - V_25 ;
return V_2 -> V_17 -> V_36 ( V_2 , type , & V_30 ) ;
}
static void F_21 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
V_38 -> V_41 = V_40 -> V_42 ;
V_38 -> V_43 = V_40 -> V_44 ;
V_38 -> V_45 = V_40 -> V_46 ;
V_38 -> V_47 = V_40 -> V_48 ;
V_38 -> V_49 = V_40 -> V_50 ;
V_38 -> V_51 = V_40 -> V_52 ;
V_38 -> V_53 = V_40 -> V_54 ;
V_38 -> V_55 = V_40 -> V_56 ;
V_38 -> V_57 = V_58 ;
}
static int F_22 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_59 ;
struct V_37 V_60 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_61 )
return - V_25 ;
V_19 = V_2 -> V_17 -> V_61 ( V_2 , type , V_4 , & V_59 ) ;
if ( V_19 )
return V_19 ;
F_21 ( & V_60 , & V_59 ) ;
if ( F_17 ( V_26 , & V_60 , sizeof( V_60 ) ) )
return - V_33 ;
return 0 ;
}
static void F_23 ( struct V_39 * V_38 , struct V_37 * V_40 )
{
V_38 -> V_42 = V_40 -> V_41 ;
V_38 -> V_44 = V_40 -> V_43 ;
V_38 -> V_46 = V_40 -> V_45 ;
V_38 -> V_48 = V_40 -> V_47 ;
V_38 -> V_50 = V_40 -> V_49 ;
V_38 -> V_52 = V_40 -> V_51 ;
V_38 -> V_54 = V_40 -> V_53 ;
V_38 -> V_56 = V_40 -> V_55 ;
V_38 -> V_62 = 0 ;
if ( V_40 -> V_57 & V_63 )
V_38 -> V_62 |= V_64 | V_65 ;
if ( V_40 -> V_57 & V_66 )
V_38 -> V_62 |= V_67 ;
if ( V_40 -> V_57 & V_68 )
V_38 -> V_62 |= V_69 | V_70 ;
if ( V_40 -> V_57 & V_71 )
V_38 -> V_62 |= V_72 ;
if ( V_40 -> V_57 & V_73 )
V_38 -> V_62 |= V_74 ;
if ( V_40 -> V_57 & V_75 )
V_38 -> V_62 |= V_76 ;
}
static int F_24 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_59 ;
struct V_37 V_60 ;
if ( F_20 ( & V_60 , V_26 , sizeof( V_60 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_77 )
return - V_25 ;
F_23 ( & V_59 , & V_60 ) ;
return V_2 -> V_17 -> V_77 ( V_2 , type , V_4 , & V_59 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_3 , void T_2 * V_26 )
{
T_3 V_78 ;
if ( F_20 ( & V_78 , V_26 , sizeof( V_78 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_79 )
return - V_25 ;
return V_2 -> V_17 -> V_79 ( V_2 , V_78 , V_3 ) ;
}
static int F_26 ( struct V_1 * V_2 , void T_2 * V_26 )
{
struct V_80 V_81 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_82 )
return - V_25 ;
V_19 = V_2 -> V_17 -> V_82 ( V_2 , & V_81 ) ;
if ( ! V_19 && F_17 ( V_26 , & V_81 , sizeof( V_81 ) ) )
return - V_33 ;
return V_19 ;
}
static int F_27 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_59 ;
if ( F_20 ( & V_59 , V_26 , sizeof( V_59 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_77 )
return - V_25 ;
return V_2 -> V_17 -> V_77 ( V_2 , type , V_4 , & V_59 ) ;
}
static int F_28 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_59 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_61 )
return - V_25 ;
V_19 = V_2 -> V_17 -> V_61 ( V_2 , type , V_4 , & V_59 ) ;
if ( ! V_19 && F_17 ( V_26 , & V_59 , sizeof( V_59 ) ) )
return - V_33 ;
return V_19 ;
}
static int F_29 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_26 , struct V_22 * V_22 )
{
int V_19 ;
if ( type >= ( F_30 ( V_3 ) ? V_83 : V_20 ) )
return - V_21 ;
if ( ! V_2 -> V_17 )
return - V_25 ;
V_19 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_19 < 0 )
return V_19 ;
switch ( V_3 ) {
case V_84 :
return F_9 ( V_2 , type , V_3 , V_4 , V_22 ) ;
case V_85 :
if ( ! V_2 -> V_17 -> V_86 )
return - V_25 ;
return V_2 -> V_17 -> V_86 ( V_2 , type ) ;
case V_5 :
return F_12 ( V_2 , type , V_26 ) ;
case V_7 :
return F_18 ( V_2 , type , V_26 ) ;
case V_87 :
return F_19 ( V_2 , type , V_26 ) ;
case V_10 :
return F_22 ( V_2 , type , V_4 , V_26 ) ;
case V_88 :
return F_24 ( V_2 , type , V_4 , V_26 ) ;
case V_6 :
if ( ! V_2 -> V_17 -> V_18 )
return - V_25 ;
return V_2 -> V_17 -> V_18 ( V_2 , type , 1 ) ;
case V_89 :
case V_90 :
case V_91 :
return F_25 ( V_2 , V_3 , V_26 ) ;
case V_8 :
return F_26 ( V_2 , V_26 ) ;
case V_92 :
return F_27 ( V_2 , type , V_4 , V_26 ) ;
case V_11 :
return F_28 ( V_2 , type , V_4 , V_26 ) ;
case V_9 :
if ( V_2 -> V_93 & V_94 )
return - V_95 ;
F_31 ( V_2 , V_96 ) ;
return 0 ;
default:
return - V_21 ;
}
}
static int F_32 ( int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_7 :
case V_6 :
case V_8 :
case V_11 :
case V_9 :
return 0 ;
}
return 1 ;
}
static struct V_1 * F_33 ( const char T_2 * V_97 , int V_3 )
{
#ifdef F_34
struct V_98 * V_99 ;
struct V_1 * V_2 ;
char * V_100 = F_35 ( V_97 ) ;
if ( F_10 ( V_100 ) )
return F_36 ( V_100 ) ;
V_99 = F_37 ( V_100 ) ;
F_38 ( V_100 ) ;
if ( F_10 ( V_99 ) )
return F_36 ( V_99 ) ;
if ( F_32 ( V_3 ) )
V_2 = F_39 ( V_99 ) ;
else
V_2 = F_40 ( V_99 ) ;
F_41 ( V_99 ) ;
if ( ! V_2 )
return F_42 ( - V_101 ) ;
return V_2 ;
#else
return F_42 ( - V_101 ) ;
#endif
}
