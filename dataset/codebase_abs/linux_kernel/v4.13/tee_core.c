static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_1 -> V_9 , struct V_5 , V_10 ) ;
if ( ! F_3 ( V_6 ) )
return - V_11 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_12 ) ;
if ( ! V_8 ) {
V_4 = - V_13 ;
goto V_14;
}
V_8 -> V_6 = V_6 ;
F_5 ( & V_8 -> V_15 ) ;
V_3 -> V_16 = V_8 ;
V_4 = V_6 -> V_17 -> V_18 -> V_19 ( V_8 ) ;
if ( V_4 )
goto V_14;
return 0 ;
V_14:
F_6 ( V_8 ) ;
F_7 ( V_6 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_16 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_20 * V_21 ;
V_8 -> V_6 -> V_17 -> V_18 -> V_22 ( V_8 ) ;
F_9 ( & V_8 -> V_6 -> V_23 ) ;
F_10 (shm, &ctx->list_shm, link)
V_21 -> V_8 = NULL ;
F_11 ( & V_8 -> V_6 -> V_23 ) ;
F_6 ( V_8 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_24 T_1 * V_25 )
{
struct V_24 V_26 ;
V_8 -> V_6 -> V_17 -> V_18 -> V_27 ( V_8 -> V_6 , & V_26 ) ;
if ( F_13 ( V_25 , & V_26 , sizeof( V_26 ) ) )
return - V_28 ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 ,
struct V_29 T_1 * V_30 )
{
long V_31 ;
struct V_29 V_32 ;
struct V_20 * V_21 ;
if ( F_15 ( & V_32 , V_30 , sizeof( V_32 ) ) )
return - V_28 ;
if ( V_32 . V_33 )
return - V_11 ;
V_32 . V_34 = - 1 ;
V_21 = F_16 ( V_8 , V_32 . V_35 , V_36 | V_37 ) ;
if ( F_17 ( V_21 ) )
return F_18 ( V_21 ) ;
V_32 . V_34 = V_21 -> V_34 ;
V_32 . V_33 = V_21 -> V_33 ;
V_32 . V_35 = V_21 -> V_35 ;
if ( F_13 ( V_30 , & V_32 , sizeof( V_32 ) ) )
V_31 = - V_28 ;
else
V_31 = F_19 ( V_21 ) ;
F_20 ( V_21 ) ;
return V_31 ;
}
static int F_21 ( struct V_7 * V_8 , struct V_38 * V_39 ,
T_2 V_40 ,
struct V_41 T_1 * V_42 )
{
T_2 V_43 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
struct V_20 * V_21 ;
struct V_41 V_44 ;
if ( F_15 ( & V_44 , V_42 + V_43 , sizeof( V_44 ) ) )
return - V_28 ;
if ( V_44 . V_45 & ~ V_46 )
return - V_11 ;
V_39 [ V_43 ] . V_45 = V_44 . V_45 ;
switch ( V_44 . V_45 ) {
case V_47 :
case V_48 :
break;
case V_49 :
case V_50 :
V_39 [ V_43 ] . V_51 . V_52 . V_53 = V_44 . V_53 ;
V_39 [ V_43 ] . V_51 . V_52 . V_54 = V_44 . V_54 ;
V_39 [ V_43 ] . V_51 . V_52 . V_55 = V_44 . V_55 ;
break;
case V_56 :
case V_57 :
case V_58 :
V_21 = F_22 ( V_8 , V_44 . V_55 ) ;
if ( F_17 ( V_21 ) )
return F_18 ( V_21 ) ;
V_39 [ V_43 ] . V_51 . V_59 . V_60 = V_44 . V_53 ;
V_39 [ V_43 ] . V_51 . V_59 . V_35 = V_44 . V_54 ;
V_39 [ V_43 ] . V_51 . V_59 . V_21 = V_21 ;
break;
default:
return - V_11 ;
}
}
return 0 ;
}
static int F_23 ( struct V_41 T_1 * V_42 ,
T_2 V_40 , struct V_38 * V_39 )
{
T_2 V_43 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
struct V_41 T_1 * V_61 = V_42 + V_43 ;
struct V_38 * V_62 = V_39 + V_43 ;
switch ( V_62 -> V_45 ) {
case V_48 :
case V_50 :
if ( F_24 ( V_62 -> V_51 . V_52 . V_53 , & V_61 -> V_53 ) ||
F_24 ( V_62 -> V_51 . V_52 . V_54 , & V_61 -> V_54 ) ||
F_24 ( V_62 -> V_51 . V_52 . V_55 , & V_61 -> V_55 ) )
return - V_28 ;
break;
case V_57 :
case V_58 :
if ( F_24 ( ( V_63 ) V_62 -> V_51 . V_59 . V_35 , & V_61 -> V_54 ) )
return - V_28 ;
default:
break;
}
}
return 0 ;
}
static bool F_25 ( struct V_38 * V_64 )
{
switch ( V_64 -> V_45 & V_46 ) {
case V_56 :
case V_57 :
case V_58 :
return true ;
default:
return false ;
}
}
static int F_26 ( struct V_7 * V_8 ,
struct V_65 T_1 * V_66 )
{
int V_4 ;
T_2 V_43 ;
struct V_65 V_67 ;
struct V_68 T_1 * V_69 ;
struct V_68 V_70 ;
struct V_41 T_1 * V_42 = NULL ;
struct V_38 * V_39 = NULL ;
bool V_71 = false ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_72 )
return - V_11 ;
if ( F_15 ( & V_67 , V_66 , sizeof( V_67 ) ) )
return - V_28 ;
if ( V_67 . V_73 > V_74 ||
V_67 . V_73 < sizeof( struct V_68 ) )
return - V_11 ;
V_69 = F_27 ( V_67 . V_75 ) ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_28 ;
if ( sizeof( V_70 ) + F_28 ( V_70 . V_40 ) != V_67 . V_73 )
return - V_11 ;
if ( V_70 . V_40 ) {
V_39 = F_29 ( V_70 . V_40 , sizeof( struct V_38 ) ,
V_12 ) ;
if ( ! V_39 )
return - V_13 ;
V_42 = V_69 -> V_39 ;
V_4 = F_21 ( V_8 , V_39 , V_70 . V_40 , V_42 ) ;
if ( V_4 )
goto V_76;
}
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_72 ( V_8 , & V_70 , V_39 ) ;
if ( V_4 )
goto V_76;
V_71 = true ;
if ( F_24 ( V_70 . V_77 , & V_69 -> V_77 ) ||
F_24 ( V_70 . V_31 , & V_69 -> V_31 ) ||
F_24 ( V_70 . V_78 , & V_69 -> V_78 ) ) {
V_4 = - V_28 ;
goto V_76;
}
V_4 = F_23 ( V_42 , V_70 . V_40 , V_39 ) ;
V_76:
if ( V_4 && V_71 && V_8 -> V_6 -> V_17 -> V_18 -> V_79 )
V_8 -> V_6 -> V_17 -> V_18 -> V_79 ( V_8 , V_70 . V_77 ) ;
if ( V_39 ) {
for ( V_43 = 0 ; V_43 < V_70 . V_40 ; V_43 ++ )
if ( F_25 ( V_39 + V_43 ) &&
V_39 [ V_43 ] . V_51 . V_59 . V_21 )
F_20 ( V_39 [ V_43 ] . V_51 . V_59 . V_21 ) ;
F_6 ( V_39 ) ;
}
return V_4 ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_65 T_1 * V_66 )
{
int V_4 ;
T_2 V_43 ;
struct V_65 V_67 ;
struct V_80 T_1 * V_69 ;
struct V_80 V_70 ;
struct V_41 T_1 * V_42 = NULL ;
struct V_38 * V_39 = NULL ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_81 )
return - V_11 ;
if ( F_15 ( & V_67 , V_66 , sizeof( V_67 ) ) )
return - V_28 ;
if ( V_67 . V_73 > V_74 ||
V_67 . V_73 < sizeof( struct V_80 ) )
return - V_11 ;
V_69 = F_27 ( V_67 . V_75 ) ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_28 ;
if ( sizeof( V_70 ) + F_28 ( V_70 . V_40 ) != V_67 . V_73 )
return - V_11 ;
if ( V_70 . V_40 ) {
V_39 = F_29 ( V_70 . V_40 , sizeof( struct V_38 ) ,
V_12 ) ;
if ( ! V_39 )
return - V_13 ;
V_42 = V_69 -> V_39 ;
V_4 = F_21 ( V_8 , V_39 , V_70 . V_40 , V_42 ) ;
if ( V_4 )
goto V_76;
}
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_81 ( V_8 , & V_70 , V_39 ) ;
if ( V_4 )
goto V_76;
if ( F_24 ( V_70 . V_31 , & V_69 -> V_31 ) ||
F_24 ( V_70 . V_78 , & V_69 -> V_78 ) ) {
V_4 = - V_28 ;
goto V_76;
}
V_4 = F_23 ( V_42 , V_70 . V_40 , V_39 ) ;
V_76:
if ( V_39 ) {
for ( V_43 = 0 ; V_43 < V_70 . V_40 ; V_43 ++ )
if ( F_25 ( V_39 + V_43 ) &&
V_39 [ V_43 ] . V_51 . V_59 . V_21 )
F_20 ( V_39 [ V_43 ] . V_51 . V_59 . V_21 ) ;
F_6 ( V_39 ) ;
}
return V_4 ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_82 T_1 * V_69 )
{
struct V_82 V_70 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_83 )
return - V_11 ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_28 ;
return V_8 -> V_6 -> V_17 -> V_18 -> V_83 ( V_8 , V_70 . V_84 ,
V_70 . V_77 ) ;
}
static int
F_32 ( struct V_7 * V_8 ,
struct V_85 T_1 * V_69 )
{
struct V_85 V_70 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_79 )
return - V_11 ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_28 ;
return V_8 -> V_6 -> V_17 -> V_18 -> V_79 ( V_8 , V_70 . V_77 ) ;
}
static int F_33 ( struct V_7 * V_8 ,
struct V_41 T_1 * V_42 ,
T_2 V_40 , struct V_38 * V_39 )
{
T_2 V_43 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
struct V_41 V_44 ;
struct V_38 * V_62 = V_39 + V_43 ;
V_44 . V_45 = V_62 -> V_45 & V_46 ;
switch ( V_62 -> V_45 ) {
case V_49 :
case V_50 :
V_44 . V_53 = V_62 -> V_51 . V_52 . V_53 ;
V_44 . V_54 = V_62 -> V_51 . V_52 . V_54 ;
V_44 . V_55 = V_62 -> V_51 . V_52 . V_55 ;
break;
case V_56 :
case V_57 :
case V_58 :
V_44 . V_54 = V_62 -> V_51 . V_59 . V_35 ;
if ( ! V_62 -> V_51 . V_59 . V_21 ) {
V_44 . V_53 = 0 ;
V_44 . V_55 = ( V_63 ) - 1 ;
break;
}
V_44 . V_53 = V_62 -> V_51 . V_59 . V_60 ;
V_44 . V_55 = V_62 -> V_51 . V_59 . V_21 -> V_34 ;
break;
default:
V_44 . V_53 = 0 ;
V_44 . V_54 = 0 ;
V_44 . V_55 = 0 ;
break;
}
if ( F_13 ( V_42 + V_43 , & V_44 , sizeof( V_44 ) ) )
return - V_28 ;
}
return 0 ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_65 T_1 * V_66 )
{
int V_4 ;
struct V_65 V_67 ;
struct V_86 T_1 * V_69 ;
struct V_38 * V_39 ;
T_3 V_40 ;
T_3 V_87 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_88 )
return - V_11 ;
if ( F_15 ( & V_67 , V_66 , sizeof( V_67 ) ) )
return - V_28 ;
if ( V_67 . V_73 > V_74 ||
V_67 . V_73 < sizeof( struct V_86 ) )
return - V_11 ;
V_69 = F_27 ( V_67 . V_75 ) ;
if ( F_35 ( V_40 , & V_69 -> V_40 ) )
return - V_28 ;
if ( sizeof( * V_69 ) + F_28 ( V_40 ) != V_67 . V_73 )
return - V_11 ;
V_39 = F_29 ( V_40 , sizeof( struct V_38 ) , V_12 ) ;
if ( ! V_39 )
return - V_13 ;
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_88 ( V_8 , & V_87 , & V_40 , V_39 ) ;
if ( V_4 )
goto V_76;
if ( F_24 ( V_87 , & V_69 -> V_87 ) ||
F_24 ( V_40 , & V_69 -> V_40 ) ) {
V_4 = - V_28 ;
goto V_76;
}
V_4 = F_33 ( V_8 , V_69 -> V_39 , V_40 , V_39 ) ;
V_76:
F_6 ( V_39 ) ;
return V_4 ;
}
static int F_36 ( struct V_38 * V_39 , T_2 V_40 ,
struct V_41 T_1 * V_42 )
{
T_2 V_43 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
struct V_38 * V_62 = V_39 + V_43 ;
struct V_41 V_44 ;
if ( F_15 ( & V_44 , V_42 + V_43 , sizeof( V_44 ) ) )
return - V_28 ;
if ( V_44 . V_45 & ~ V_46 )
return - V_11 ;
V_62 -> V_45 = V_44 . V_45 ;
switch ( V_44 . V_45 ) {
case V_48 :
case V_50 :
V_62 -> V_51 . V_52 . V_53 = V_44 . V_53 ;
V_62 -> V_51 . V_52 . V_54 = V_44 . V_54 ;
V_62 -> V_51 . V_52 . V_55 = V_44 . V_55 ;
break;
case V_57 :
case V_58 :
V_62 -> V_51 . V_59 . V_21 = NULL ;
V_62 -> V_51 . V_59 . V_60 = 0 ;
V_62 -> V_51 . V_59 . V_35 = V_44 . V_54 ;
break;
default:
memset ( & V_62 -> V_51 , 0 , sizeof( V_62 -> V_51 ) ) ;
break;
}
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_65 T_1 * V_66 )
{
long V_4 ;
struct V_65 V_67 ;
struct V_89 T_1 * V_69 ;
struct V_38 * V_39 ;
T_3 V_40 ;
T_3 V_31 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_90 )
return - V_11 ;
if ( F_15 ( & V_67 , V_66 , sizeof( V_67 ) ) )
return - V_28 ;
if ( V_67 . V_73 > V_74 ||
V_67 . V_73 < sizeof( struct V_89 ) )
return - V_11 ;
V_69 = F_27 ( V_67 . V_75 ) ;
if ( F_35 ( V_31 , & V_69 -> V_31 ) ||
F_35 ( V_40 , & V_69 -> V_40 ) )
return - V_28 ;
if ( sizeof( * V_69 ) + F_28 ( V_40 ) > V_67 . V_73 )
return - V_11 ;
V_39 = F_29 ( V_40 , sizeof( struct V_38 ) , V_12 ) ;
if ( ! V_39 )
return - V_13 ;
V_4 = F_36 ( V_39 , V_40 , V_69 -> V_39 ) ;
if ( V_4 )
goto V_76;
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_90 ( V_8 , V_31 , V_40 , V_39 ) ;
V_76:
F_6 ( V_39 ) ;
return V_4 ;
}
static long F_38 ( struct V_2 * V_3 , unsigned int V_91 , unsigned long V_70 )
{
struct V_7 * V_8 = V_3 -> V_16 ;
void T_1 * V_69 = ( void T_1 * ) V_70 ;
switch ( V_91 ) {
case V_92 :
return F_12 ( V_8 , V_69 ) ;
case V_93 :
return F_14 ( V_8 , V_69 ) ;
case V_94 :
return F_26 ( V_8 , V_69 ) ;
case V_95 :
return F_30 ( V_8 , V_69 ) ;
case V_96 :
return F_31 ( V_8 , V_69 ) ;
case V_97 :
return F_32 ( V_8 , V_69 ) ;
case V_98 :
return F_34 ( V_8 , V_69 ) ;
case V_99 :
return F_37 ( V_8 , V_69 ) ;
default:
return - V_11 ;
}
}
static void F_39 ( struct V_100 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_101 , struct V_5 , V_101 ) ;
F_40 ( & V_102 ) ;
F_41 ( V_6 -> V_34 , V_103 ) ;
F_42 ( & V_102 ) ;
F_43 ( & V_6 -> V_23 ) ;
F_44 ( & V_6 -> V_104 ) ;
F_6 ( V_6 ) ;
}
struct V_5 * F_45 ( const struct V_105 * V_106 ,
struct V_100 * V_101 ,
struct V_107 * V_108 ,
void * V_109 )
{
struct V_5 * V_6 ;
void * V_31 ;
int V_4 ;
int V_110 = 0 ;
if ( ! V_106 || ! V_106 -> V_111 || ! V_106 -> V_18 ||
! V_106 -> V_18 -> V_27 || ! V_106 -> V_18 -> V_19 ||
! V_106 -> V_18 -> V_22 || ! V_108 )
return F_46 ( - V_11 ) ;
V_6 = F_4 ( sizeof( * V_6 ) , V_12 ) ;
if ( ! V_6 ) {
V_31 = F_46 ( - V_13 ) ;
goto V_14;
}
if ( V_106 -> V_33 & V_112 )
V_110 = V_113 / 2 ;
F_40 ( & V_102 ) ;
V_6 -> V_34 = F_47 ( V_103 , V_113 , V_110 ) ;
if ( V_6 -> V_34 < V_113 )
F_48 ( V_6 -> V_34 , V_103 ) ;
F_42 ( & V_102 ) ;
if ( V_6 -> V_34 >= V_113 ) {
V_31 = F_46 ( - V_13 ) ;
goto V_14;
}
snprintf ( V_6 -> V_111 , sizeof( V_6 -> V_111 ) , L_1 ,
V_106 -> V_33 & V_112 ? L_2 : L_3 ,
V_6 -> V_34 - V_110 ) ;
V_6 -> V_101 . V_114 = V_115 ;
V_6 -> V_101 . V_22 = F_39 ;
V_6 -> V_101 . V_116 = V_101 ;
V_6 -> V_101 . V_117 = F_49 ( F_50 ( V_118 ) , V_6 -> V_34 ) ;
V_4 = F_51 ( & V_6 -> V_101 , L_4 , V_6 -> V_111 ) ;
if ( V_4 ) {
V_31 = F_46 ( V_4 ) ;
goto V_119;
}
F_52 ( & V_6 -> V_10 , & V_120 ) ;
V_6 -> V_10 . V_121 = V_106 -> V_121 ;
V_6 -> V_10 . V_122 . V_116 = & V_6 -> V_101 . V_122 ;
F_53 ( & V_6 -> V_101 , V_109 ) ;
F_54 ( & V_6 -> V_101 ) ;
V_6 -> V_123 = 1 ;
F_55 ( & V_6 -> V_124 ) ;
F_56 ( & V_6 -> V_23 ) ;
F_57 ( & V_6 -> V_104 ) ;
V_6 -> V_17 = V_106 ;
V_6 -> V_108 = V_108 ;
return V_6 ;
V_119:
F_58 ( V_6 -> V_101 . V_117 , 1 ) ;
V_14:
F_59 ( L_5 ,
V_106 -> V_33 & V_112 ? L_6 : L_7 ) ;
if ( V_6 && V_6 -> V_34 < V_113 ) {
F_40 ( & V_102 ) ;
F_41 ( V_6 -> V_34 , V_103 ) ;
F_42 ( & V_102 ) ;
}
F_6 ( V_6 ) ;
return V_31 ;
}
static T_4 F_60 ( struct V_100 * V_101 ,
struct V_125 * V_45 , char * V_67 )
{
struct V_5 * V_6 = F_2 ( V_101 , struct V_5 , V_101 ) ;
struct V_24 V_26 ;
V_6 -> V_17 -> V_18 -> V_27 ( V_6 , & V_26 ) ;
return F_61 ( V_67 , V_126 , L_8 , V_26 . V_127 ) ;
}
int F_62 ( struct V_5 * V_6 )
{
int V_4 ;
if ( V_6 -> V_33 & V_128 ) {
F_63 ( & V_6 -> V_101 , L_9 ) ;
return - V_11 ;
}
V_4 = F_64 ( & V_6 -> V_10 , V_6 -> V_101 . V_117 , 1 ) ;
if ( V_4 ) {
F_63 ( & V_6 -> V_101 ,
L_10 ,
V_6 -> V_111 , F_50 ( V_6 -> V_101 . V_117 ) ,
F_65 ( V_6 -> V_101 . V_117 ) , V_4 ) ;
return V_4 ;
}
V_4 = F_66 ( & V_6 -> V_101 ) ;
if ( V_4 ) {
F_63 ( & V_6 -> V_101 ,
L_11 ,
V_6 -> V_111 , F_50 ( V_6 -> V_101 . V_117 ) ,
F_65 ( V_6 -> V_101 . V_117 ) , V_4 ) ;
goto V_129;
}
V_4 = F_67 ( & V_6 -> V_101 . V_122 , & V_130 ) ;
if ( V_4 ) {
F_63 ( & V_6 -> V_101 ,
L_12 , V_4 ) ;
goto V_131;
}
V_6 -> V_33 |= V_128 ;
return 0 ;
V_131:
F_68 ( & V_6 -> V_101 ) ;
V_129:
F_69 ( & V_6 -> V_10 ) ;
return V_4 ;
}
void F_7 ( struct V_5 * V_6 )
{
F_9 ( & V_6 -> V_23 ) ;
if ( ! F_70 ( ! V_6 -> V_17 ) ) {
V_6 -> V_123 -- ;
if ( ! V_6 -> V_123 ) {
V_6 -> V_17 = NULL ;
F_71 ( & V_6 -> V_124 ) ;
}
}
F_11 ( & V_6 -> V_23 ) ;
}
bool F_3 ( struct V_5 * V_6 )
{
F_9 ( & V_6 -> V_23 ) ;
if ( ! V_6 -> V_17 ) {
F_11 ( & V_6 -> V_23 ) ;
return false ;
}
V_6 -> V_123 ++ ;
F_11 ( & V_6 -> V_23 ) ;
return true ;
}
void F_72 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
if ( V_6 -> V_33 & V_128 ) {
F_73 ( & V_6 -> V_101 . V_122 , & V_130 ) ;
F_69 ( & V_6 -> V_10 ) ;
F_68 ( & V_6 -> V_101 ) ;
}
F_7 ( V_6 ) ;
F_74 ( & V_6 -> V_124 ) ;
V_6 -> V_108 = NULL ;
F_75 ( & V_6 -> V_101 ) ;
}
void * F_76 ( struct V_5 * V_6 )
{
return F_77 ( & V_6 -> V_101 ) ;
}
static int T_5 F_78 ( void )
{
int V_4 ;
V_115 = F_79 ( V_132 , L_13 ) ;
if ( F_17 ( V_115 ) ) {
F_59 ( L_14 ) ;
return F_18 ( V_115 ) ;
}
V_4 = F_80 ( & V_118 , 0 , V_113 , L_13 ) ;
if ( V_4 ) {
F_59 ( L_15 ) ;
F_81 ( V_115 ) ;
V_115 = NULL ;
}
return V_4 ;
}
static void T_6 F_82 ( void )
{
F_81 ( V_115 ) ;
V_115 = NULL ;
F_58 ( V_118 , V_113 ) ;
}
