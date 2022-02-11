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
if ( ( type == V_12 && F_2 ( F_3 () , F_4 ( F_5 () , V_4 ) ) ) ||
( type == V_13 && F_6 ( F_7 ( F_5 () , V_4 ) ) ) )
break;
default:
if ( ! F_8 ( V_14 ) )
return - V_15 ;
}
return F_9 ( V_3 , type , V_4 , V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_16 )
{
if ( V_2 -> V_17 && V_2 -> V_17 -> V_18 )
V_2 -> V_17 -> V_18 ( V_2 , * ( int * ) V_16 ) ;
}
static int F_11 ( int type )
{
int V_19 ;
if ( type >= V_20 )
return - V_21 ;
V_19 = F_9 ( V_6 , type , 0 , NULL ) ;
if ( ! V_19 )
F_12 ( F_10 , & type ) ;
return V_19 ;
}
static int F_13 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
struct V_22 * V_22 )
{
if ( ! V_2 -> V_17 -> V_23 && ! V_2 -> V_17 -> V_24 )
return - V_25 ;
if ( V_2 -> V_17 -> V_24 )
return V_2 -> V_17 -> V_24 ( V_2 , type , V_4 ) ;
if ( F_14 ( V_22 ) )
return F_15 ( V_22 ) ;
return V_2 -> V_17 -> V_23 ( V_2 , type , V_4 , V_22 ) ;
}
static int F_16 ( struct V_1 * V_2 , int type , void T_2 * V_26 )
{
T_3 V_27 ;
F_17 ( & F_18 ( V_2 ) -> V_28 ) ;
if ( ! F_19 ( V_2 , type ) ) {
F_20 ( & F_18 ( V_2 ) -> V_28 ) ;
return - V_29 ;
}
V_27 = F_18 ( V_2 ) -> V_30 [ type ] . V_31 -> V_32 ;
F_20 ( & F_18 ( V_2 ) -> V_28 ) ;
if ( F_21 ( V_26 , & V_27 , sizeof( V_27 ) ) )
return - V_33 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int type , void T_2 * V_26 )
{
struct V_34 V_30 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_35 )
return - V_25 ;
V_19 = V_2 -> V_17 -> V_35 ( V_2 , type , & V_30 ) ;
if ( ! V_19 && F_21 ( V_26 , & V_30 , sizeof( V_30 ) ) )
return - V_33 ;
return V_19 ;
}
static int F_23 ( struct V_1 * V_2 , int type , void T_2 * V_26 )
{
struct V_34 V_30 ;
if ( F_24 ( & V_30 , V_26 , sizeof( V_30 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_36 )
return - V_25 ;
return V_2 -> V_17 -> V_36 ( V_2 , type , & V_30 ) ;
}
static void F_25 ( struct V_37 * V_38 , struct V_39 * V_40 )
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
static int F_26 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_59 V_60 ;
struct V_39 V_61 ;
struct V_37 V_62 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_63 )
return - V_25 ;
V_60 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_60 ) )
return - V_21 ;
V_19 = V_2 -> V_17 -> V_63 ( V_2 , V_60 , & V_61 ) ;
if ( V_19 )
return V_19 ;
F_25 ( & V_62 , & V_61 ) ;
if ( F_21 ( V_26 , & V_62 , sizeof( V_62 ) ) )
return - V_33 ;
return 0 ;
}
static void F_29 ( struct V_39 * V_38 , struct V_37 * V_40 )
{
V_38 -> V_42 = V_40 -> V_41 ;
V_38 -> V_44 = V_40 -> V_43 ;
V_38 -> V_46 = V_40 -> V_45 ;
V_38 -> V_48 = V_40 -> V_47 ;
V_38 -> V_50 = V_40 -> V_49 ;
V_38 -> V_52 = V_40 -> V_51 ;
V_38 -> V_54 = V_40 -> V_53 ;
V_38 -> V_56 = V_40 -> V_55 ;
V_38 -> V_64 = 0 ;
if ( V_40 -> V_57 & V_65 )
V_38 -> V_64 |= V_66 | V_67 ;
if ( V_40 -> V_57 & V_68 )
V_38 -> V_64 |= V_69 ;
if ( V_40 -> V_57 & V_70 )
V_38 -> V_64 |= V_71 | V_72 ;
if ( V_40 -> V_57 & V_73 )
V_38 -> V_64 |= V_74 ;
if ( V_40 -> V_57 & V_75 )
V_38 -> V_64 |= V_76 ;
if ( V_40 -> V_57 & V_77 )
V_38 -> V_64 |= V_78 ;
}
static int F_30 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_61 ;
struct V_37 V_62 ;
struct V_59 V_60 ;
if ( F_24 ( & V_62 , V_26 , sizeof( V_62 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_79 )
return - V_25 ;
V_60 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_60 ) )
return - V_21 ;
F_29 ( & V_61 , & V_62 ) ;
return V_2 -> V_17 -> V_79 ( V_2 , V_60 , & V_61 ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_3 , void T_2 * V_26 )
{
T_3 V_80 ;
if ( F_24 ( & V_80 , V_26 , sizeof( V_80 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_81 )
return - V_25 ;
return V_2 -> V_17 -> V_81 ( V_2 , V_80 , V_3 ) ;
}
static int F_32 ( struct V_1 * V_2 , void T_2 * V_26 )
{
struct V_82 V_83 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_84 )
return - V_25 ;
V_19 = V_2 -> V_17 -> V_84 ( V_2 , & V_83 ) ;
if ( ! V_19 && F_21 ( V_26 , & V_83 , sizeof( V_83 ) ) )
return - V_33 ;
return V_19 ;
}
static int F_33 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_61 ;
struct V_59 V_60 ;
if ( F_24 ( & V_61 , V_26 , sizeof( V_61 ) ) )
return - V_33 ;
if ( ! V_2 -> V_17 -> V_79 )
return - V_25 ;
V_60 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_60 ) )
return - V_21 ;
return V_2 -> V_17 -> V_79 ( V_2 , V_60 , & V_61 ) ;
}
static int F_34 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_26 )
{
struct V_39 V_61 ;
struct V_59 V_60 ;
int V_19 ;
if ( ! V_2 -> V_17 -> V_63 )
return - V_25 ;
V_60 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_60 ) )
return - V_21 ;
V_19 = V_2 -> V_17 -> V_63 ( V_2 , V_60 , & V_61 ) ;
if ( ! V_19 && F_21 ( V_26 , & V_61 , sizeof( V_61 ) ) )
return - V_33 ;
return V_19 ;
}
static int F_35 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_26 , struct V_22 * V_22 )
{
int V_19 ;
if ( type >= ( F_36 ( V_3 ) ? V_85 : V_20 ) )
return - V_21 ;
if ( ! V_2 -> V_17 )
return - V_25 ;
V_19 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_19 < 0 )
return V_19 ;
switch ( V_3 ) {
case V_86 :
return F_13 ( V_2 , type , V_3 , V_4 , V_22 ) ;
case V_87 :
if ( ! V_2 -> V_17 -> V_88 )
return - V_25 ;
return V_2 -> V_17 -> V_88 ( V_2 , type ) ;
case V_5 :
return F_16 ( V_2 , type , V_26 ) ;
case V_7 :
return F_22 ( V_2 , type , V_26 ) ;
case V_89 :
return F_23 ( V_2 , type , V_26 ) ;
case V_10 :
return F_26 ( V_2 , type , V_4 , V_26 ) ;
case V_90 :
return F_30 ( V_2 , type , V_4 , V_26 ) ;
case V_6 :
if ( ! V_2 -> V_17 -> V_18 )
return - V_25 ;
return V_2 -> V_17 -> V_18 ( V_2 , type ) ;
case V_91 :
case V_92 :
case V_93 :
return F_31 ( V_2 , V_3 , V_26 ) ;
case V_8 :
return F_32 ( V_2 , V_26 ) ;
case V_94 :
return F_33 ( V_2 , type , V_4 , V_26 ) ;
case V_11 :
return F_34 ( V_2 , type , V_4 , V_26 ) ;
case V_9 :
if ( V_2 -> V_95 & V_96 )
return - V_97 ;
return 0 ;
default:
return - V_21 ;
}
}
static int F_37 ( int V_3 )
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
static struct V_1 * F_38 ( const char T_2 * V_98 , int V_3 )
{
#ifdef F_39
struct V_99 * V_100 ;
struct V_1 * V_2 ;
struct V_101 * V_102 = F_40 ( V_98 ) ;
if ( F_14 ( V_102 ) )
return F_41 ( V_102 ) ;
V_100 = F_42 ( V_102 -> V_103 ) ;
F_43 ( V_102 ) ;
if ( F_14 ( V_100 ) )
return F_41 ( V_100 ) ;
if ( F_37 ( V_3 ) )
V_2 = F_44 ( V_100 ) ;
else
V_2 = F_45 ( V_100 ) ;
F_46 ( V_100 ) ;
if ( ! V_2 )
return F_47 ( - V_104 ) ;
return V_2 ;
#else
return F_47 ( - V_104 ) ;
#endif
}
