static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( V_2 -> V_8 , V_3 , V_5 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
return ( V_6 != V_5 ) ? - V_9 : 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_7 ( V_2 -> V_8 , V_3 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
return V_6 ;
}
static int F_8 ( const char * V_10 , int V_11 )
{
if ( V_10 ) {
if ( ! strcmp ( V_10 , L_1 ) )
return ( V_11 == V_12 || V_11 == V_13 ) ? 1 : 0 ;
else if ( ! strcmp ( V_10 , L_2 ) )
return ( V_11 == V_14 ) ? 1 : 0 ;
}
return ( V_11 >= V_12 && V_11 <= V_14 ) ? 1 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_15 ;
int V_6 ;
V_15 = V_16 | V_17 | V_18 ;
V_6 = F_6 ( V_2 , V_19 , V_15 ) ;
if ( V_6 )
return V_6 ;
V_15 = V_20 | V_21 ;
V_6 = F_6 ( V_2 , V_22 , V_15 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_5 ( V_2 , V_23 , & V_15 ) ;
return V_15 & V_24 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_5 ( V_2 , V_23 , & V_15 ) ;
return V_15 & V_25 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_26 )
{
F_6 ( V_2 , V_27 , V_26 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_11 , int V_28 )
{
T_1 V_29 = V_30 ;
T_1 V_31 = V_32 | V_33 ;
switch ( V_11 ) {
case 0x5 :
V_29 = V_12 ;
V_2 -> V_34 = & V_2 -> V_35 -> V_36 ;
break;
case 0xB :
if ( F_10 ( V_2 ) ) {
V_2 -> V_34 = & V_2 -> V_35 -> V_36 ;
V_29 = V_13 ;
} else if ( F_11 ( V_2 ) ) {
V_2 -> V_34 = & V_2 -> V_35 -> V_37 ;
V_29 = V_14 ;
V_31 = V_38 | V_39 ;
} else if ( V_28 ) {
V_29 = V_40 ;
V_31 = V_38 | V_39 ;
}
break;
default:
V_29 = V_30 ;
V_2 -> V_34 = NULL ;
break;
}
V_2 -> V_29 = V_29 ;
F_12 ( V_2 , V_31 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_5 ( V_2 , V_22 , & V_15 ) ;
V_15 |= V_21 ;
F_6 ( V_2 , V_22 , V_15 ) ;
}
static void F_15 ( struct V_41 * V_42 )
{
T_1 V_43 [ 2 ] , V_44 , V_45 ;
struct V_1 * V_2 =
F_16 ( V_42 , struct V_1 , V_46 . V_46 ) ;
if ( F_1 ( V_2 , V_47 , V_43 , 2 ) ) {
F_17 ( V_2 -> V_48 , L_3 ) ;
return;
}
V_44 = V_43 [ 0 ] & V_49 ;
V_45 = V_43 [ 0 ] & V_50 ;
F_13 ( V_2 , V_44 , V_45 ) ;
F_14 ( V_2 ) ;
F_18 ( & V_2 -> V_51 -> V_36 ) ;
F_18 ( & V_2 -> V_51 -> V_37 ) ;
F_18 ( & V_2 -> V_51 -> V_52 ) ;
}
static T_3 F_19 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
unsigned long V_55 = F_20 ( V_56 ) ;
F_21 ( V_2 -> V_57 , & V_2 -> V_46 , V_55 ) ;
return V_58 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_46 , F_15 ) ;
V_2 -> V_57 = F_24 ( L_4 ) ;
if ( ! V_2 -> V_57 ) {
F_17 ( V_2 -> V_48 , L_5 ) ;
return - V_59 ;
}
return F_25 ( V_2 -> V_8 -> V_53 ,
NULL ,
F_19 ,
V_60 ,
L_6 ,
V_2 ) ;
}
static int F_26 ( struct V_61 * V_51 ,
enum V_62 V_63 ,
union V_64 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_51 -> V_48 -> V_65 ) ;
if ( V_63 == V_66 )
V_15 -> V_67 = F_8 ( V_51 -> V_10 ,
V_2 -> V_29 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_51 ,
enum V_62 V_63 ,
union V_64 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_51 -> V_48 -> V_65 ) ;
T_1 V_68 ;
switch ( V_63 ) {
case V_69 :
if ( F_8 ( V_51 -> V_10 , V_2 -> V_29 ) ) {
F_5 ( V_2 , V_23 , & V_68 ) ;
if ( ( ( V_68 & V_70 ) >> 4 ) == V_71 )
V_15 -> V_67 = V_72 ;
else
V_15 -> V_67 = V_73 ;
} else {
V_15 -> V_67 = V_74 ;
}
break;
case V_75 :
F_5 ( V_2 , V_76 , & V_68 ) ;
V_68 = ( V_68 & V_77 ) >> 5 ;
if ( V_68 >= 0x1 && V_68 <= 0x3 )
V_15 -> V_67 = V_78 ;
else
V_15 -> V_67 = V_79 ;
break;
case V_80 :
if ( V_2 -> V_35 -> V_81 )
V_15 -> V_67 = V_2 -> V_35 -> V_81 () ;
break;
case V_82 :
if ( V_2 -> V_35 -> V_83 )
V_15 -> V_67 = V_2 -> V_35 -> V_83 () ;
break;
case V_84 :
if ( V_2 -> V_35 -> V_85 )
V_15 -> V_67 = V_2 -> V_35 -> V_85 () ;
break;
case V_86 :
if ( V_2 -> V_35 -> V_87 )
V_15 -> V_67 = V_2 -> V_35 -> V_87 () ;
break;
default:
break;
}
return 0 ;
}
static void F_29 ( struct V_61 * V_51 )
{
struct V_1 * V_2 = F_27 ( V_51 -> V_48 -> V_65 ) ;
T_1 V_15 ;
T_1 V_88 , V_89 ;
if ( F_8 ( V_51 -> V_10 , V_2 -> V_29 ) ) {
if ( V_2 -> V_34 ) {
V_88 = V_2 -> V_34 -> V_88 ;
V_89 = V_2 -> V_34 -> V_89 ;
V_15 = ( V_89 << 4 ) | V_88 ;
F_6 ( V_2 , V_90 , V_15 ) ;
}
}
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_91 * V_51 ;
V_51 = F_31 ( sizeof( * V_51 ) , V_92 ) ;
if ( ! V_51 )
goto V_93;
V_2 -> V_51 = V_51 ;
V_51 -> V_36 . V_10 = L_1 ;
V_51 -> V_36 . type = V_94 ;
V_51 -> V_36 . V_95 = V_96 ;
V_51 -> V_36 . V_97 = F_32 ( V_96 ) ;
V_51 -> V_36 . V_98 = F_26 ;
V_51 -> V_36 . V_99 = V_100 ;
V_51 -> V_36 . V_101 = F_32 ( V_100 ) ;
if ( F_33 ( V_2 -> V_48 , & V_51 -> V_36 ) )
goto V_102;
V_51 -> V_37 . V_10 = L_2 ;
V_51 -> V_37 . type = V_103 ;
V_51 -> V_37 . V_95 = V_96 ;
V_51 -> V_37 . V_97 = F_32 ( V_96 ) ;
V_51 -> V_37 . V_98 = F_26 ;
V_51 -> V_37 . V_99 = V_100 ;
V_51 -> V_37 . V_101 = F_32 ( V_100 ) ;
if ( F_33 ( V_2 -> V_48 , & V_51 -> V_37 ) )
goto V_102;
V_51 -> V_52 . V_10 = L_7 ;
V_51 -> V_52 . type = V_104 ;
V_51 -> V_52 . V_95 = V_105 ;
V_51 -> V_52 . V_97 = F_32 ( V_105 ) ;
V_51 -> V_52 . V_98 = F_28 ;
V_51 -> V_52 . V_106 = F_29 ;
if ( F_33 ( V_2 -> V_48 , & V_51 -> V_52 ) )
goto V_102;
return 0 ;
V_93:
return - V_59 ;
V_102:
F_34 ( V_51 ) ;
return - V_107 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_91 * V_51 = V_2 -> V_51 ;
if ( ! V_51 )
return;
F_36 ( & V_51 -> V_36 ) ;
F_36 ( & V_51 -> V_37 ) ;
F_36 ( & V_51 -> V_52 ) ;
F_34 ( V_51 ) ;
}
static int F_37 ( struct V_108 * V_109 , const struct V_110 * V_11 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( ! F_38 ( V_109 -> V_111 , V_112 ) )
return - V_9 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_8 = V_109 ;
V_2 -> V_48 = & V_109 -> V_48 ;
V_2 -> V_35 = V_109 -> V_48 . V_113 ;
F_39 ( V_109 , V_2 ) ;
F_40 ( & V_2 -> V_7 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 ) {
F_17 ( V_2 -> V_48 , L_8 , V_6 ) ;
goto error;
}
V_6 = F_22 ( V_2 ) ;
if ( V_6 ) {
F_17 ( V_2 -> V_48 , L_9 , V_6 ) ;
goto error;
}
V_6 = F_30 ( V_2 ) ;
if ( V_6 ) {
F_17 ( V_2 -> V_48 , L_10 , V_6 ) ;
goto error;
}
return 0 ;
error:
F_34 ( V_2 ) ;
return V_6 ;
}
static int T_4 F_41 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_42 ( V_109 ) ;
F_35 ( V_2 ) ;
F_43 ( V_2 -> V_8 -> V_53 , V_2 ) ;
F_44 ( V_2 -> V_57 ) ;
F_45 ( V_2 -> V_57 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
