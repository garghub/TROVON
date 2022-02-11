static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( V_2 -> V_8 , V_3 , V_5 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
return ( V_6 != V_5 ) ? - V_9 : 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_6 ( V_2 -> V_8 , V_3 , V_5 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
return V_6 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static inline int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 )
{
return F_5 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_9 ( const char * V_10 , int V_11 )
{
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_1 ) )
return ( V_11 == V_12 || V_11 == V_13 ) ? 1 : 0 ;
else if ( ! strcmp ( V_10 , L_2 ) )
return ( V_11 == V_14 ) ? 1 : 0 ;
}
return ( V_11 >= V_12 && V_11 <= V_14 ) ? 1 : 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_15 ;
V_15 = V_16 | V_17 | V_18 ;
if ( F_8 ( V_2 , V_19 , & V_15 ) )
F_11 ( V_2 -> V_20 , L_3 , V_19 ) ;
V_15 = V_21 | V_22 ;
if ( F_8 ( V_2 , V_23 , & V_15 ) )
F_11 ( V_2 -> V_20 , L_3 , V_23 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_7 ( V_2 , V_24 , & V_15 ) ;
return ( V_15 & V_25 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_7 ( V_2 , V_24 , & V_15 ) ;
return ( V_15 & V_26 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_15 = V_27 ;
F_8 ( V_2 , V_28 , & V_15 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_11 , int V_29 )
{
T_1 V_30 = V_31 ;
T_1 V_32 = V_33 | V_34 ;
switch ( V_11 ) {
case 0x5 :
V_30 = V_12 ;
V_2 -> V_35 = & V_2 -> V_36 -> V_37 ;
break;
case 0xB :
if ( F_12 ( V_2 ) ) {
V_2 -> V_35 = & V_2 -> V_36 -> V_37 ;
V_30 = V_13 ;
} else if ( F_13 ( V_2 ) ) {
V_2 -> V_35 = & V_2 -> V_36 -> V_38 ;
V_30 = V_14 ;
V_32 = V_39 | V_40 ;
} else if ( V_29 ) {
V_30 = V_41 ;
V_32 = V_39 | V_40 ;
}
break;
default:
V_30 = V_31 ;
V_2 -> V_35 = NULL ;
break;
}
V_2 -> V_30 = V_30 ;
F_14 ( V_2 , V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_7 ( V_2 , V_23 , & V_15 ) ;
V_15 |= V_22 ;
F_8 ( V_2 , V_23 , & V_15 ) ;
}
static void F_17 ( struct V_42 * V_43 )
{
T_1 V_44 [ 2 ] , V_45 , V_46 ;
struct V_1 * V_2 =
F_18 ( V_43 , struct V_1 , V_47 . V_47 ) ;
if ( F_1 ( V_2 , V_48 , V_44 , 2 ) ) {
F_11 ( V_2 -> V_20 , L_4 ) ;
return;
}
V_45 = V_44 [ 0 ] & V_49 ;
V_46 = V_44 [ 0 ] & V_50 ;
F_15 ( V_2 , V_45 , V_46 ) ;
F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_51 -> V_37 ) ;
F_19 ( & V_2 -> V_51 -> V_38 ) ;
F_19 ( & V_2 -> V_51 -> V_52 ) ;
}
static T_3 F_20 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
unsigned long V_55 = F_21 ( V_56 ) ;
F_22 ( V_2 -> V_57 , & V_2 -> V_47 , V_55 ) ;
return V_58 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_47 , F_17 ) ;
V_2 -> V_57 = F_25 ( L_5 ) ;
if ( ! V_2 -> V_57 )
F_11 ( V_2 -> V_20 , L_6 ) ;
if ( F_26 ( V_2 -> V_8 -> V_53 ,
NULL ,
F_20 ,
V_59 , L_7 , V_2 ) ) {
F_11 ( V_2 -> V_20 , L_8 ) ;
}
}
static int F_27 ( struct V_60 * V_51 ,
enum V_61 V_62 ,
union V_63 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_51 -> V_20 -> V_64 ) ;
if ( V_62 == V_65 )
V_15 -> V_66 = F_9 ( V_51 -> V_10 ,
V_2 -> V_30 ) ;
return 0 ;
}
static int F_29 ( struct V_60 * V_51 ,
enum V_61 V_62 ,
union V_63 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_51 -> V_20 -> V_64 ) ;
T_1 V_67 ;
switch ( V_62 ) {
case V_68 :
if ( F_9 ( V_51 -> V_10 , V_2 -> V_30 ) ) {
F_7 ( V_2 , V_24 , & V_67 ) ;
if ( ( ( V_67 & V_69 ) >> 4 ) == V_70 )
V_15 -> V_66 = V_71 ;
else
V_15 -> V_66 = V_72 ;
} else {
V_15 -> V_66 = V_73 ;
}
break;
case V_74 :
F_7 ( V_2 , V_75 , & V_67 ) ;
V_67 = ( V_67 & V_76 ) >> 5 ;
if ( V_67 >= 0x1 && V_67 <= 0x3 )
V_15 -> V_66 = V_77 ;
else
V_15 -> V_66 = V_78 ;
break;
case V_79 :
if ( V_2 -> V_36 -> V_80 )
V_15 -> V_66 = V_2 -> V_36 -> V_80 () ;
break;
case V_81 :
if ( V_2 -> V_36 -> V_82 )
V_15 -> V_66 = V_2 -> V_36 -> V_82 () ;
break;
case V_83 :
if ( V_2 -> V_36 -> V_84 )
V_15 -> V_66 = V_2 -> V_36 -> V_84 () ;
break;
case V_85 :
if ( V_2 -> V_36 -> V_86 )
V_15 -> V_66 = V_2 -> V_36 -> V_86 () ;
break;
default:
break;
}
return 0 ;
}
static void F_30 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_28 ( V_51 -> V_20 -> V_64 ) ;
T_1 V_15 ;
T_1 V_87 , V_88 ;
if ( F_9 ( V_51 -> V_10 , V_2 -> V_30 ) ) {
if ( V_2 -> V_35 ) {
V_87 = V_2 -> V_35 -> V_87 ;
V_88 = V_2 -> V_35 -> V_88 ;
V_15 = ( V_88 << 4 ) | V_87 ;
F_8 ( V_2 , V_89 , & V_15 ) ;
}
}
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_90 * V_51 ;
V_51 = F_32 ( sizeof( * V_51 ) , V_91 ) ;
if ( ! V_51 )
goto V_92;
V_2 -> V_51 = V_51 ;
V_51 -> V_37 . V_10 = L_1 ;
V_51 -> V_37 . type = V_93 ;
V_51 -> V_37 . V_94 = V_95 ;
V_51 -> V_37 . V_96 = F_33 ( V_95 ) ;
V_51 -> V_37 . V_97 = F_27 ;
V_51 -> V_37 . V_98 = V_99 ;
V_51 -> V_37 . V_100 = F_33 ( V_99 ) ;
if ( F_34 ( V_2 -> V_20 , & V_51 -> V_37 ) )
goto V_101;
V_51 -> V_38 . V_10 = L_2 ;
V_51 -> V_38 . type = V_102 ;
V_51 -> V_38 . V_94 = V_95 ;
V_51 -> V_38 . V_96 = F_33 ( V_95 ) ;
V_51 -> V_38 . V_97 = F_27 ;
V_51 -> V_38 . V_98 = V_99 ;
V_51 -> V_38 . V_100 = F_33 ( V_99 ) ;
if ( F_34 ( V_2 -> V_20 , & V_51 -> V_38 ) )
goto V_101;
V_51 -> V_52 . V_10 = L_9 ;
V_51 -> V_52 . type = V_103 ;
V_51 -> V_52 . V_94 = V_104 ;
V_51 -> V_52 . V_96 = F_33 ( V_104 ) ;
V_51 -> V_52 . V_97 = F_29 ;
V_51 -> V_52 . V_105 = F_30 ;
if ( F_34 ( V_2 -> V_20 , & V_51 -> V_52 ) )
goto V_101;
return 0 ;
V_92:
return - V_106 ;
V_101:
F_35 ( V_51 ) ;
return - V_107 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_90 * V_51 = V_2 -> V_51 ;
if ( ! V_51 )
return;
F_37 ( & V_51 -> V_37 ) ;
F_37 ( & V_51 -> V_38 ) ;
F_37 ( & V_51 -> V_52 ) ;
F_35 ( V_51 ) ;
}
static int F_38 ( struct V_108 * V_109 , const struct V_110 * V_11 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( ! F_39 ( V_109 -> V_111 , V_112 ) )
return - V_9 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_8 = V_109 ;
V_2 -> V_20 = & V_109 -> V_20 ;
V_2 -> V_36 = V_109 -> V_20 . V_113 ;
F_40 ( V_109 , V_2 ) ;
F_41 ( & V_2 -> V_7 ) ;
F_10 ( V_2 ) ;
F_23 ( V_2 ) ;
V_6 = F_31 ( V_2 ) ;
if ( V_6 )
F_11 ( V_2 -> V_20 ,
L_10 , V_6 ) ;
return 0 ;
}
static int T_4 F_42 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_43 ( V_109 ) ;
F_36 ( V_2 ) ;
F_44 ( V_2 -> V_8 -> V_53 , V_2 ) ;
F_45 ( V_2 -> V_57 ) ;
F_46 ( V_2 -> V_57 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int T_5 F_47 ( void )
{
return F_48 ( & V_114 ) ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_114 ) ;
}
