static int F_1 ( struct V_1 * V_2 , int type , int V_3 ,
T_1 V_4 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
break;
case V_11 :
case V_12 :
if ( ( type == V_13 && F_2 ( F_3 () , F_4 ( F_5 () , V_4 ) ) ) ||
( type == V_14 && F_6 ( F_7 ( F_5 () , V_4 ) ) ) )
break;
default:
if ( ! F_8 ( V_15 ) )
return - V_16 ;
}
return F_9 ( V_3 , type , V_4 , V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_17 )
{
if ( V_2 -> V_18 && V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 ( V_2 , * ( int * ) V_17 ) ;
}
static int F_11 ( int type )
{
int V_20 ;
if ( type >= V_21 )
return - V_22 ;
V_20 = F_9 ( V_6 , type , 0 , NULL ) ;
if ( ! V_20 )
F_12 ( F_10 , & type ) ;
return V_20 ;
}
static int F_13 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
struct V_23 * V_23 )
{
if ( ! V_2 -> V_18 -> V_24 && ! V_2 -> V_18 -> V_25 )
return - V_26 ;
if ( V_2 -> V_18 -> V_25 )
return V_2 -> V_18 -> V_25 ( V_2 , type , V_4 ) ;
if ( F_14 ( V_23 ) )
return F_15 ( V_23 ) ;
return V_2 -> V_18 -> V_24 ( V_2 , type , V_4 , V_23 ) ;
}
static int F_16 ( struct V_1 * V_2 , int type , void T_2 * V_27 )
{
T_3 V_28 ;
F_17 ( & F_18 ( V_2 ) -> V_29 ) ;
if ( ! F_19 ( V_2 , type ) ) {
F_20 ( & F_18 ( V_2 ) -> V_29 ) ;
return - V_30 ;
}
V_28 = F_18 ( V_2 ) -> V_31 [ type ] . V_32 -> V_33 ;
F_20 ( & F_18 ( V_2 ) -> V_29 ) ;
if ( F_21 ( V_27 , & V_28 , sizeof( V_28 ) ) )
return - V_34 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int type , void T_2 * V_27 )
{
struct V_35 V_31 ;
int V_20 ;
if ( ! V_2 -> V_18 -> V_36 )
return - V_26 ;
V_20 = V_2 -> V_18 -> V_36 ( V_2 , type , & V_31 ) ;
if ( ! V_20 && F_21 ( V_27 , & V_31 , sizeof( V_31 ) ) )
return - V_34 ;
return V_20 ;
}
static int F_23 ( struct V_1 * V_2 , int type , void T_2 * V_27 )
{
struct V_35 V_31 ;
if ( F_24 ( & V_31 , V_27 , sizeof( V_31 ) ) )
return - V_34 ;
if ( ! V_2 -> V_18 -> V_37 )
return - V_26 ;
return V_2 -> V_18 -> V_37 ( V_2 , type , & V_31 ) ;
}
static void F_25 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
V_39 -> V_42 = V_41 -> V_43 ;
V_39 -> V_44 = V_41 -> V_45 ;
V_39 -> V_46 = V_41 -> V_47 ;
V_39 -> V_48 = V_41 -> V_49 ;
V_39 -> V_50 = V_41 -> V_51 ;
V_39 -> V_52 = V_41 -> V_53 ;
V_39 -> V_54 = V_41 -> V_55 ;
V_39 -> V_56 = V_41 -> V_57 ;
V_39 -> V_58 = V_59 ;
}
static int F_26 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_27 )
{
struct V_60 V_61 ;
struct V_40 V_62 ;
struct V_38 V_63 ;
int V_20 ;
if ( ! V_2 -> V_18 -> V_64 )
return - V_26 ;
V_61 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_61 ) )
return - V_22 ;
V_20 = V_2 -> V_18 -> V_64 ( V_2 , V_61 , & V_62 ) ;
if ( V_20 )
return V_20 ;
F_25 ( & V_63 , & V_62 ) ;
if ( F_21 ( V_27 , & V_63 , sizeof( V_63 ) ) )
return - V_34 ;
return 0 ;
}
static void F_29 ( struct V_40 * V_39 , struct V_38 * V_41 )
{
V_39 -> V_43 = V_41 -> V_42 ;
V_39 -> V_45 = V_41 -> V_44 ;
V_39 -> V_47 = V_41 -> V_46 ;
V_39 -> V_49 = V_41 -> V_48 ;
V_39 -> V_51 = V_41 -> V_50 ;
V_39 -> V_53 = V_41 -> V_52 ;
V_39 -> V_55 = V_41 -> V_54 ;
V_39 -> V_57 = V_41 -> V_56 ;
V_39 -> V_65 = 0 ;
if ( V_41 -> V_58 & V_66 )
V_39 -> V_65 |= V_67 | V_68 ;
if ( V_41 -> V_58 & V_69 )
V_39 -> V_65 |= V_70 ;
if ( V_41 -> V_58 & V_71 )
V_39 -> V_65 |= V_72 | V_73 ;
if ( V_41 -> V_58 & V_74 )
V_39 -> V_65 |= V_75 ;
if ( V_41 -> V_58 & V_76 )
V_39 -> V_65 |= V_77 ;
if ( V_41 -> V_58 & V_78 )
V_39 -> V_65 |= V_79 ;
}
static int F_30 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_27 )
{
struct V_40 V_62 ;
struct V_38 V_63 ;
struct V_60 V_61 ;
if ( F_24 ( & V_63 , V_27 , sizeof( V_63 ) ) )
return - V_34 ;
if ( ! V_2 -> V_18 -> V_80 )
return - V_26 ;
V_61 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_61 ) )
return - V_22 ;
F_29 ( & V_62 , & V_63 ) ;
return V_2 -> V_18 -> V_80 ( V_2 , V_61 , & V_62 ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_3 , void T_2 * V_27 )
{
T_3 V_81 ;
if ( F_24 ( & V_81 , V_27 , sizeof( V_81 ) ) )
return - V_34 ;
if ( ! V_2 -> V_18 -> V_82 )
return - V_26 ;
return V_2 -> V_18 -> V_82 ( V_2 , V_81 , V_3 ) ;
}
static int F_32 ( struct V_1 * V_2 , void T_2 * V_27 )
{
struct V_83 V_84 ;
int V_20 ;
if ( ! V_2 -> V_18 -> V_85 )
return - V_26 ;
V_20 = V_2 -> V_18 -> V_85 ( V_2 , & V_84 ) ;
if ( ! V_20 && F_21 ( V_27 , & V_84 , sizeof( V_84 ) ) )
return - V_34 ;
return V_20 ;
}
static int F_33 ( struct V_1 * V_2 , void T_2 * V_27 )
{
struct V_86 V_84 ;
int V_20 ;
if ( ! V_2 -> V_18 -> V_87 )
return - V_26 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( F_24 ( & V_84 , V_27 , 1 ) )
return - V_34 ;
switch ( V_84 . V_88 ) {
case V_89 :
break;
default:
return - V_22 ;
}
V_20 = V_2 -> V_18 -> V_87 ( V_2 , & V_84 ) ;
if ( ! V_20 && F_21 ( V_27 , & V_84 , sizeof( V_84 ) ) )
return - V_34 ;
return V_20 ;
}
static int F_34 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_27 )
{
struct V_40 V_62 ;
struct V_60 V_61 ;
if ( F_24 ( & V_62 , V_27 , sizeof( V_62 ) ) )
return - V_34 ;
if ( ! V_2 -> V_18 -> V_80 )
return - V_26 ;
V_61 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_61 ) )
return - V_22 ;
return V_2 -> V_18 -> V_80 ( V_2 , V_61 , & V_62 ) ;
}
static int F_35 ( struct V_1 * V_2 , int type , T_1 V_4 ,
void T_2 * V_27 )
{
struct V_40 V_62 ;
struct V_60 V_61 ;
int V_20 ;
if ( ! V_2 -> V_18 -> V_64 )
return - V_26 ;
V_61 = F_27 ( F_5 () , type , V_4 ) ;
if ( ! F_28 ( V_61 ) )
return - V_22 ;
V_20 = V_2 -> V_18 -> V_64 ( V_2 , V_61 , & V_62 ) ;
if ( ! V_20 && F_21 ( V_27 , & V_62 , sizeof( V_62 ) ) )
return - V_34 ;
return V_20 ;
}
static int F_36 ( struct V_1 * V_2 , int type , int V_3 , T_1 V_4 ,
void T_2 * V_27 , struct V_23 * V_23 )
{
int V_20 ;
if ( type >= ( F_37 ( V_3 ) ? V_90 : V_21 ) )
return - V_22 ;
if ( ! V_2 -> V_18 )
return - V_26 ;
V_20 = F_1 ( V_2 , type , V_3 , V_4 ) ;
if ( V_20 < 0 )
return V_20 ;
switch ( V_3 ) {
case V_91 :
return F_13 ( V_2 , type , V_3 , V_4 , V_23 ) ;
case V_92 :
if ( ! V_2 -> V_18 -> V_93 )
return - V_26 ;
return V_2 -> V_18 -> V_93 ( V_2 , type ) ;
case V_5 :
return F_16 ( V_2 , type , V_27 ) ;
case V_7 :
return F_22 ( V_2 , type , V_27 ) ;
case V_94 :
return F_23 ( V_2 , type , V_27 ) ;
case V_11 :
return F_26 ( V_2 , type , V_4 , V_27 ) ;
case V_95 :
return F_30 ( V_2 , type , V_4 , V_27 ) ;
case V_6 :
if ( ! V_2 -> V_18 -> V_19 )
return - V_26 ;
return V_2 -> V_18 -> V_19 ( V_2 , type ) ;
case V_96 :
case V_97 :
case V_98 :
return F_31 ( V_2 , V_3 , V_27 ) ;
case V_8 :
return F_32 ( V_2 , V_27 ) ;
case V_9 :
return F_33 ( V_2 , V_27 ) ;
case V_99 :
return F_34 ( V_2 , type , V_4 , V_27 ) ;
case V_12 :
return F_35 ( V_2 , type , V_4 , V_27 ) ;
case V_10 :
if ( V_2 -> V_100 & V_101 )
return - V_102 ;
return 0 ;
default:
return - V_22 ;
}
}
static int F_38 ( int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_7 :
case V_6 :
case V_8 :
case V_9 :
case V_12 :
case V_10 :
return 0 ;
}
return 1 ;
}
static struct V_1 * F_39 ( const char T_2 * V_103 , int V_3 )
{
#ifdef F_40
struct V_104 * V_105 ;
struct V_1 * V_2 ;
struct V_106 * V_107 = F_41 ( V_103 ) ;
if ( F_14 ( V_107 ) )
return F_42 ( V_107 ) ;
V_105 = F_43 ( V_107 -> V_108 ) ;
F_44 ( V_107 ) ;
if ( F_14 ( V_105 ) )
return F_42 ( V_105 ) ;
if ( F_38 ( V_3 ) )
V_2 = F_45 ( V_105 ) ;
else
V_2 = F_46 ( V_105 ) ;
F_47 ( V_105 ) ;
if ( ! V_2 )
return F_48 ( - V_109 ) ;
return V_2 ;
#else
return F_48 ( - V_109 ) ;
#endif
}
