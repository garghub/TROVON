static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
V_5 -> V_8 += V_5 -> V_9 ;
V_5 -> V_8 %= V_5 -> V_9 * V_5 -> V_10 ;
F_2 ( V_3 ) ;
}
static bool F_3 ( struct V_11 * V_12 , void * V_13 )
{
struct V_14 * V_1 = V_13 ;
if ( V_1 -> V_15 == F_4 ( V_12 ) ) {
V_12 -> V_16 = V_1 ;
return true ;
}
return false ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_7 ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
T_1 V_23 ;
int V_24 ;
V_24 = F_6 ( V_3 -> V_6 ,
V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
F_7 ( V_3 , & V_26 ) ;
V_5 = F_8 ( sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
F_9 ( V_23 ) ;
F_10 ( V_29 , V_23 ) ;
F_10 ( V_30 , V_23 ) ;
V_22 = F_11 ( V_20 , V_3 ) ;
V_5 -> V_31 . V_32 = V_22 -> V_33 ;
V_5 -> V_31 . V_34 = V_22 -> V_34 ;
if ( V_3 -> V_35 == V_36 )
V_5 -> V_31 . V_15 = V_37 ;
else
V_5 -> V_31 . V_15 = V_38 ;
V_5 -> V_11 = F_12 ( V_23 , F_3 ,
& V_5 -> V_31 ) ;
if ( ! V_5 -> V_11 ) {
F_13 ( V_5 ) ;
return - V_39 ;
}
V_3 -> V_6 -> V_7 = V_5 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
F_15 ( V_5 -> V_11 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_40 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_11 * V_12 = V_5 -> V_11 ;
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_45 ;
V_5 -> V_8 = 0 ;
V_45 = V_42 -> V_46 ( V_12 , V_6 -> V_47 ,
V_5 -> V_9 * V_5 -> V_10 ,
V_5 -> V_9 ,
V_5 -> V_31 . V_15 ) ;
if ( ! V_45 )
return - V_39 ;
V_45 -> V_48 = F_1 ;
V_45 -> V_49 = V_3 ;
F_17 ( V_45 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_40 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
F_19 ( V_5 -> V_11 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_40 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
F_21 ( V_3 , & V_3 -> V_52 ) ;
V_5 -> V_10 = F_22 ( V_51 ) ;
V_5 -> V_9 = F_23 ( V_51 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
F_21 ( V_3 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , int V_53 )
{
int V_24 ;
V_24 = 0 ;
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
V_24 = F_16 ( V_3 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
F_18 ( V_3 ) ;
break;
default:
V_24 = - V_39 ;
break;
}
return V_24 ;
}
static T_2 F_26 ( struct V_2 * V_3 )
{
struct V_40 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_27 ( V_6 , V_5 -> V_8 ) ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_60 * V_61 )
{
struct V_40 * V_6 = V_3 -> V_6 ;
return F_29 ( V_3 -> V_62 -> V_63 -> V_64 , V_61 ,
V_6 -> V_65 ,
V_6 -> V_47 ,
V_6 -> V_66 ) ;
}
static int F_30 ( struct V_67 * V_62 , int V_35 )
{
struct V_2 * V_3 = V_62 -> V_68 [ V_35 ] . V_3 ;
struct V_69 * V_70 = & V_3 -> V_52 ;
T_3 V_71 = V_26 . V_72 ;
V_70 -> V_64 . type = V_73 ;
V_70 -> V_64 . V_64 = V_62 -> V_63 -> V_64 ;
V_70 -> V_7 = NULL ;
V_70 -> V_74 = F_31 ( V_62 -> V_63 -> V_64 , V_71 ,
& V_70 -> V_75 , V_27 ) ;
V_70 -> V_76 = V_71 ;
return ( V_70 -> V_74 == NULL ) ? - V_28 : 0 ;
}
static void F_32 ( struct V_67 * V_62 )
{
struct V_2 * V_3 ;
struct V_69 * V_70 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
V_3 = V_62 -> V_68 [ V_35 ] . V_3 ;
if ( ! V_3 )
continue;
V_70 = & V_3 -> V_52 ;
if ( ! V_70 -> V_74 )
continue;
F_33 ( V_62 -> V_63 -> V_64 , V_70 -> V_76 , V_70 -> V_74 ,
V_70 -> V_75 ) ;
V_70 -> V_74 = NULL ;
}
}
static int F_34 ( struct V_17 * V_5 )
{
struct V_77 * V_63 = V_5 -> V_63 -> V_77 ;
struct V_67 * V_62 = V_5 -> V_62 ;
int V_24 = 0 ;
if ( ! V_63 -> V_64 -> V_78 )
V_63 -> V_64 -> V_78 = & V_79 ;
if ( ! V_63 -> V_64 -> V_80 )
V_63 -> V_64 -> V_80 = 0xffffffff ;
if ( V_62 -> V_68 [ V_36 ] . V_3 ) {
V_24 = F_30 ( V_62 ,
V_36 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_62 -> V_68 [ V_81 ] . V_3 ) {
V_24 = F_30 ( V_62 ,
V_81 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int T_4 F_35 ( struct V_82 * V_83 )
{
return F_36 ( & V_83 -> V_64 , & V_84 ) ;
}
static int T_5 F_37 ( struct V_82 * V_83 )
{
F_38 ( & V_83 -> V_64 ) ;
return 0 ;
}
