static void F_1 ( int V_1 , T_1 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_11 ;
if ( ( F_2 () ) ) {
F_3 ( & V_9 -> V_12 , V_11 ) ;
if ( ( V_2 == V_13 ) &&
( V_9 -> V_14 == V_7 -> V_15 - 1 ) ) {
F_4 ( & V_9 -> V_12 , V_11 ) ;
return;
}
if ( V_9 -> V_14 >= 0 ) {
if ( V_2 & V_16 ) {
V_9 -> V_14 = 0 ;
} else if ( V_2 & V_13 ) {
V_9 -> V_14 = V_7 -> V_15 - 1 ;
} else if ( ++ V_9 -> V_14 >= V_7 -> V_15 ) {
V_9 -> V_14 = 0 ;
}
}
F_4 ( & V_9 -> V_12 , V_11 ) ;
}
F_5 ( V_5 ) ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_19 * V_20 = V_5 -> V_10 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
V_22 = F_7 ( V_20 -> V_24 , V_5 ) ;
if ( ! V_22 )
return 0 ;
F_8 ( V_5 , & V_5 -> V_25 ) ;
V_7 -> V_26 = F_9 ( V_18 ) ;
if ( V_9 -> V_22 )
return 0 ;
V_9 -> V_22 = V_22 ;
V_23 = F_10 ( V_22 -> V_27 , V_22 -> V_28 ,
F_1 , V_5 , & V_9 -> V_29 ) ;
if ( ! V_23 ) {
F_11 ( V_9 -> V_29 , V_9 -> V_29 ) ;
}
return V_23 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_9 -> V_22 == NULL )
return 0 ;
F_13 ( V_9 -> V_29 , V_9 -> V_29 ) ;
F_14 ( V_9 -> V_29 ) ;
V_9 -> V_22 = NULL ;
F_8 ( V_5 , NULL ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_21 * V_22 = V_9 -> V_22 ;
struct V_30 V_31 ;
int V_32 ;
if ( ! V_9 -> V_22 )
return 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_33 = V_22 -> V_33 ;
V_31 . V_34 = V_22 -> V_27 ;
V_31 . V_35 = V_22 -> V_35 ;
if ( V_5 -> V_36 == V_37 ) {
V_31 . V_38 = V_39 ;
V_31 . V_40 = V_41 ;
V_31 . V_42 = V_43 ;
V_31 . V_44 = V_7 -> V_45 ;
V_31 . V_46 = V_22 -> V_47 ;
V_31 . V_48 = V_49 ;
V_31 . V_50 = V_22 -> V_51 ;
} else {
V_31 . V_38 = V_41 ;
V_31 . V_40 = V_39 ;
V_31 . V_42 = V_52 ;
V_31 . V_44 = V_22 -> V_47 ;
V_31 . V_46 = V_7 -> V_45 ;
V_31 . V_53 = V_49 ;
V_31 . V_54 = V_22 -> V_51 ;
}
V_32 = F_16 ( V_5 ) ;
V_31 . V_55 = V_32 >> V_22 -> V_33 ;
V_31 . V_56 = V_7 -> V_15 ;
F_17 ( V_9 -> V_29 , & V_31 ) ;
if ( ( F_2 () ) )
F_18 ( V_9 -> V_29 , V_57 |
V_13 | V_16 ) ;
else if ( ! V_5 -> V_7 -> V_58 )
F_18 ( V_9 -> V_29 , V_57 ) ;
else {
F_19 ( V_9 -> V_29 , V_16 ) ;
}
if ( ! ( F_20 () ) ) {
F_21 ( V_9 -> V_29 ,
V_59 ) ;
F_22 ( V_9 -> V_29 ,
V_59 ) ;
}
return 0 ;
}
static int F_23 ( struct V_4 * V_5 , int V_60 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_21 * V_22 = V_9 -> V_22 ;
unsigned long V_11 ;
int V_61 = 0 ;
F_3 ( & V_9 -> V_12 , V_11 ) ;
switch ( V_60 ) {
case V_62 :
case V_63 :
case V_64 :
V_9 -> V_14 = 0 ;
if ( V_22 -> V_65 )
V_22 -> V_65 ( V_5 ) ;
F_24 ( V_9 -> V_29 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
V_9 -> V_14 = - 1 ;
F_25 ( V_9 -> V_29 ) ;
break;
default:
V_61 = - V_69 ;
}
F_4 ( & V_9 -> V_12 , V_11 ) ;
return V_61 ;
}
static T_2 F_26 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_70 ;
T_2 V_71 ;
if ( F_2 () ) {
V_71 = V_9 -> V_14 * V_7 -> V_72 ;
} else if ( V_5 -> V_36 == V_73 ) {
V_70 = F_27 ( V_9 -> V_29 ) ;
V_71 = F_28 ( V_7 , V_70 - V_7 -> V_45 ) ;
} else {
V_70 = F_29 ( V_9 -> V_29 ) ;
V_71 = F_28 ( V_7 , V_70 - V_7 -> V_45 ) ;
}
if ( V_71 >= V_7 -> V_74 )
V_71 = 0 ;
return V_71 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 ;
int V_61 ;
F_31 ( V_5 , & V_75 ) ;
V_61 = F_32 ( V_7 ,
V_76 ) ;
if ( V_61 < 0 )
goto V_77;
V_9 = F_33 ( sizeof( * V_9 ) , V_78 ) ;
if ( V_9 == NULL ) {
V_61 = - V_79 ;
goto V_77;
}
F_34 ( & V_9 -> V_12 ) ;
V_7 -> V_10 = V_9 ;
V_77:
return V_61 ;
}
static int F_35 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_36 ( V_7 -> V_10 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 ,
struct V_80 * V_81 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
return F_38 ( V_5 -> V_82 -> V_83 -> V_84 , V_81 ,
V_7 -> V_85 ,
V_7 -> V_45 ,
V_7 -> V_26 ) ;
}
static int F_39 ( struct V_86 * V_82 ,
int V_36 )
{
struct V_4 * V_5 = V_82 -> V_87 [ V_36 ] . V_5 ;
struct V_88 * V_89 = & V_5 -> V_25 ;
T_4 V_90 = V_75 . V_91 ;
V_89 -> V_84 . type = V_92 ;
V_89 -> V_84 . V_84 = V_82 -> V_83 -> V_84 ;
V_89 -> V_10 = NULL ;
V_89 -> V_93 = F_40 ( V_82 -> V_83 -> V_84 , V_90 ,
& V_89 -> V_94 , V_78 ) ;
if ( ! V_89 -> V_93 )
return - V_79 ;
V_89 -> V_32 = V_90 ;
return 0 ;
}
static void F_41 ( struct V_86 * V_82 )
{
struct V_4 * V_5 ;
struct V_88 * V_89 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_5 = V_82 -> V_87 [ V_36 ] . V_5 ;
if ( ! V_5 )
continue;
V_89 = & V_5 -> V_25 ;
if ( ! V_89 -> V_93 )
continue;
F_42 ( V_82 -> V_83 -> V_84 , V_89 -> V_32 ,
V_89 -> V_93 , V_89 -> V_94 ) ;
V_89 -> V_93 = NULL ;
}
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_95 * V_83 = V_20 -> V_83 -> V_95 ;
struct V_86 * V_82 = V_20 -> V_82 ;
int V_61 = 0 ;
if ( ! V_83 -> V_84 -> V_96 )
V_83 -> V_84 -> V_96 = & V_97 ;
if ( ! V_83 -> V_84 -> V_98 )
V_83 -> V_84 -> V_98 = F_44 ( 64 ) ;
if ( V_82 -> V_87 [ V_37 ] . V_5 ) {
V_61 = F_39 ( V_82 ,
V_37 ) ;
if ( V_61 )
goto V_77;
}
if ( V_82 -> V_87 [ V_73 ] . V_5 ) {
V_61 = F_39 ( V_82 ,
V_73 ) ;
if ( V_61 )
goto V_77;
}
V_77:
if ( V_61 )
F_41 ( V_82 ) ;
return V_61 ;
}
static T_5 int F_45 ( struct V_99 * V_100 )
{
return F_46 ( & V_100 -> V_84 ,
& V_101 ) ;
}
static int T_6 F_47 ( struct V_99 * V_100 )
{
F_48 ( & V_100 -> V_84 ) ;
return 0 ;
}
