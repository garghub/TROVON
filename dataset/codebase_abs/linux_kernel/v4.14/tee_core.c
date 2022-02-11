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
if ( V_8 -> V_6 -> V_17 -> V_28 & V_29 )
V_26 . V_30 |= V_31 ;
if ( F_13 ( V_25 , & V_26 , sizeof( V_26 ) ) )
return - V_32 ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 ,
struct V_33 T_1 * V_34 )
{
long V_35 ;
struct V_33 V_36 ;
struct V_20 * V_21 ;
if ( F_15 ( & V_36 , V_34 , sizeof( V_36 ) ) )
return - V_32 ;
if ( V_36 . V_28 )
return - V_11 ;
V_36 . V_37 = - 1 ;
V_21 = F_16 ( V_8 , V_36 . V_38 , V_39 | V_40 ) ;
if ( F_17 ( V_21 ) )
return F_18 ( V_21 ) ;
V_36 . V_37 = V_21 -> V_37 ;
V_36 . V_28 = V_21 -> V_28 ;
V_36 . V_38 = V_21 -> V_38 ;
if ( F_13 ( V_34 , & V_36 , sizeof( V_36 ) ) )
V_35 = - V_32 ;
else
V_35 = F_19 ( V_21 ) ;
F_20 ( V_21 ) ;
return V_35 ;
}
static int F_21 ( struct V_7 * V_8 , struct V_41 * V_42 ,
T_2 V_43 ,
struct V_44 T_1 * V_45 )
{
T_2 V_46 ;
for ( V_46 = 0 ; V_46 < V_43 ; V_46 ++ ) {
struct V_20 * V_21 ;
struct V_44 V_47 ;
if ( F_15 ( & V_47 , V_45 + V_46 , sizeof( V_47 ) ) )
return - V_32 ;
if ( V_47 . V_48 & ~ V_49 )
return - V_11 ;
V_42 [ V_46 ] . V_48 = V_47 . V_48 ;
switch ( V_47 . V_48 ) {
case V_50 :
case V_51 :
break;
case V_52 :
case V_53 :
V_42 [ V_46 ] . V_54 . V_55 . V_56 = V_47 . V_56 ;
V_42 [ V_46 ] . V_54 . V_55 . V_57 = V_47 . V_57 ;
V_42 [ V_46 ] . V_54 . V_55 . V_58 = V_47 . V_58 ;
break;
case V_59 :
case V_60 :
case V_61 :
V_21 = F_22 ( V_8 , V_47 . V_58 ) ;
if ( F_17 ( V_21 ) )
return F_18 ( V_21 ) ;
V_42 [ V_46 ] . V_54 . V_62 . V_63 = V_47 . V_56 ;
V_42 [ V_46 ] . V_54 . V_62 . V_38 = V_47 . V_57 ;
V_42 [ V_46 ] . V_54 . V_62 . V_21 = V_21 ;
break;
default:
return - V_11 ;
}
}
return 0 ;
}
static int F_23 ( struct V_44 T_1 * V_45 ,
T_2 V_43 , struct V_41 * V_42 )
{
T_2 V_46 ;
for ( V_46 = 0 ; V_46 < V_43 ; V_46 ++ ) {
struct V_44 T_1 * V_64 = V_45 + V_46 ;
struct V_41 * V_65 = V_42 + V_46 ;
switch ( V_65 -> V_48 ) {
case V_51 :
case V_53 :
if ( F_24 ( V_65 -> V_54 . V_55 . V_56 , & V_64 -> V_56 ) ||
F_24 ( V_65 -> V_54 . V_55 . V_57 , & V_64 -> V_57 ) ||
F_24 ( V_65 -> V_54 . V_55 . V_58 , & V_64 -> V_58 ) )
return - V_32 ;
break;
case V_60 :
case V_61 :
if ( F_24 ( ( V_66 ) V_65 -> V_54 . V_62 . V_38 , & V_64 -> V_57 ) )
return - V_32 ;
default:
break;
}
}
return 0 ;
}
static bool F_25 ( struct V_41 * V_67 )
{
switch ( V_67 -> V_48 & V_49 ) {
case V_59 :
case V_60 :
case V_61 :
return true ;
default:
return false ;
}
}
static int F_26 ( struct V_7 * V_8 ,
struct V_68 T_1 * V_69 )
{
int V_4 ;
T_2 V_46 ;
struct V_68 V_70 ;
struct V_71 T_1 * V_72 ;
struct V_71 V_73 ;
struct V_44 T_1 * V_45 = NULL ;
struct V_41 * V_42 = NULL ;
bool V_74 = false ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_75 )
return - V_11 ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_32 ;
if ( V_70 . V_76 > V_77 ||
V_70 . V_76 < sizeof( struct V_71 ) )
return - V_11 ;
V_72 = F_27 ( V_70 . V_78 ) ;
if ( F_15 ( & V_73 , V_72 , sizeof( V_73 ) ) )
return - V_32 ;
if ( sizeof( V_73 ) + F_28 ( V_73 . V_43 ) != V_70 . V_76 )
return - V_11 ;
if ( V_73 . V_43 ) {
V_42 = F_29 ( V_73 . V_43 , sizeof( struct V_41 ) ,
V_12 ) ;
if ( ! V_42 )
return - V_13 ;
V_45 = V_72 -> V_42 ;
V_4 = F_21 ( V_8 , V_42 , V_73 . V_43 , V_45 ) ;
if ( V_4 )
goto V_79;
}
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_75 ( V_8 , & V_73 , V_42 ) ;
if ( V_4 )
goto V_79;
V_74 = true ;
if ( F_24 ( V_73 . V_80 , & V_72 -> V_80 ) ||
F_24 ( V_73 . V_35 , & V_72 -> V_35 ) ||
F_24 ( V_73 . V_81 , & V_72 -> V_81 ) ) {
V_4 = - V_32 ;
goto V_79;
}
V_4 = F_23 ( V_45 , V_73 . V_43 , V_42 ) ;
V_79:
if ( V_4 && V_74 && V_8 -> V_6 -> V_17 -> V_18 -> V_82 )
V_8 -> V_6 -> V_17 -> V_18 -> V_82 ( V_8 , V_73 . V_80 ) ;
if ( V_42 ) {
for ( V_46 = 0 ; V_46 < V_73 . V_43 ; V_46 ++ )
if ( F_25 ( V_42 + V_46 ) &&
V_42 [ V_46 ] . V_54 . V_62 . V_21 )
F_20 ( V_42 [ V_46 ] . V_54 . V_62 . V_21 ) ;
F_6 ( V_42 ) ;
}
return V_4 ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_68 T_1 * V_69 )
{
int V_4 ;
T_2 V_46 ;
struct V_68 V_70 ;
struct V_83 T_1 * V_72 ;
struct V_83 V_73 ;
struct V_44 T_1 * V_45 = NULL ;
struct V_41 * V_42 = NULL ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_84 )
return - V_11 ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_32 ;
if ( V_70 . V_76 > V_77 ||
V_70 . V_76 < sizeof( struct V_83 ) )
return - V_11 ;
V_72 = F_27 ( V_70 . V_78 ) ;
if ( F_15 ( & V_73 , V_72 , sizeof( V_73 ) ) )
return - V_32 ;
if ( sizeof( V_73 ) + F_28 ( V_73 . V_43 ) != V_70 . V_76 )
return - V_11 ;
if ( V_73 . V_43 ) {
V_42 = F_29 ( V_73 . V_43 , sizeof( struct V_41 ) ,
V_12 ) ;
if ( ! V_42 )
return - V_13 ;
V_45 = V_72 -> V_42 ;
V_4 = F_21 ( V_8 , V_42 , V_73 . V_43 , V_45 ) ;
if ( V_4 )
goto V_79;
}
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_84 ( V_8 , & V_73 , V_42 ) ;
if ( V_4 )
goto V_79;
if ( F_24 ( V_73 . V_35 , & V_72 -> V_35 ) ||
F_24 ( V_73 . V_81 , & V_72 -> V_81 ) ) {
V_4 = - V_32 ;
goto V_79;
}
V_4 = F_23 ( V_45 , V_73 . V_43 , V_42 ) ;
V_79:
if ( V_42 ) {
for ( V_46 = 0 ; V_46 < V_73 . V_43 ; V_46 ++ )
if ( F_25 ( V_42 + V_46 ) &&
V_42 [ V_46 ] . V_54 . V_62 . V_21 )
F_20 ( V_42 [ V_46 ] . V_54 . V_62 . V_21 ) ;
F_6 ( V_42 ) ;
}
return V_4 ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_85 T_1 * V_72 )
{
struct V_85 V_73 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_86 )
return - V_11 ;
if ( F_15 ( & V_73 , V_72 , sizeof( V_73 ) ) )
return - V_32 ;
return V_8 -> V_6 -> V_17 -> V_18 -> V_86 ( V_8 , V_73 . V_87 ,
V_73 . V_80 ) ;
}
static int
F_32 ( struct V_7 * V_8 ,
struct V_88 T_1 * V_72 )
{
struct V_88 V_73 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_82 )
return - V_11 ;
if ( F_15 ( & V_73 , V_72 , sizeof( V_73 ) ) )
return - V_32 ;
return V_8 -> V_6 -> V_17 -> V_18 -> V_82 ( V_8 , V_73 . V_80 ) ;
}
static int F_33 ( struct V_7 * V_8 ,
struct V_44 T_1 * V_45 ,
T_2 V_43 , struct V_41 * V_42 )
{
T_2 V_46 ;
for ( V_46 = 0 ; V_46 < V_43 ; V_46 ++ ) {
struct V_44 V_47 ;
struct V_41 * V_65 = V_42 + V_46 ;
V_47 . V_48 = V_65 -> V_48 & V_49 ;
switch ( V_65 -> V_48 ) {
case V_52 :
case V_53 :
V_47 . V_56 = V_65 -> V_54 . V_55 . V_56 ;
V_47 . V_57 = V_65 -> V_54 . V_55 . V_57 ;
V_47 . V_58 = V_65 -> V_54 . V_55 . V_58 ;
break;
case V_59 :
case V_60 :
case V_61 :
V_47 . V_57 = V_65 -> V_54 . V_62 . V_38 ;
if ( ! V_65 -> V_54 . V_62 . V_21 ) {
V_47 . V_56 = 0 ;
V_47 . V_58 = ( V_66 ) - 1 ;
break;
}
V_47 . V_56 = V_65 -> V_54 . V_62 . V_63 ;
V_47 . V_58 = V_65 -> V_54 . V_62 . V_21 -> V_37 ;
break;
default:
V_47 . V_56 = 0 ;
V_47 . V_57 = 0 ;
V_47 . V_58 = 0 ;
break;
}
if ( F_13 ( V_45 + V_46 , & V_47 , sizeof( V_47 ) ) )
return - V_32 ;
}
return 0 ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_68 T_1 * V_69 )
{
int V_4 ;
struct V_68 V_70 ;
struct V_89 T_1 * V_72 ;
struct V_41 * V_42 ;
T_3 V_43 ;
T_3 V_90 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_91 )
return - V_11 ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_32 ;
if ( V_70 . V_76 > V_77 ||
V_70 . V_76 < sizeof( struct V_89 ) )
return - V_11 ;
V_72 = F_27 ( V_70 . V_78 ) ;
if ( F_35 ( V_43 , & V_72 -> V_43 ) )
return - V_32 ;
if ( sizeof( * V_72 ) + F_28 ( V_43 ) != V_70 . V_76 )
return - V_11 ;
V_42 = F_29 ( V_43 , sizeof( struct V_41 ) , V_12 ) ;
if ( ! V_42 )
return - V_13 ;
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_91 ( V_8 , & V_90 , & V_43 , V_42 ) ;
if ( V_4 )
goto V_79;
if ( F_24 ( V_90 , & V_72 -> V_90 ) ||
F_24 ( V_43 , & V_72 -> V_43 ) ) {
V_4 = - V_32 ;
goto V_79;
}
V_4 = F_33 ( V_8 , V_72 -> V_42 , V_43 , V_42 ) ;
V_79:
F_6 ( V_42 ) ;
return V_4 ;
}
static int F_36 ( struct V_41 * V_42 , T_2 V_43 ,
struct V_44 T_1 * V_45 )
{
T_2 V_46 ;
for ( V_46 = 0 ; V_46 < V_43 ; V_46 ++ ) {
struct V_41 * V_65 = V_42 + V_46 ;
struct V_44 V_47 ;
if ( F_15 ( & V_47 , V_45 + V_46 , sizeof( V_47 ) ) )
return - V_32 ;
if ( V_47 . V_48 & ~ V_49 )
return - V_11 ;
V_65 -> V_48 = V_47 . V_48 ;
switch ( V_47 . V_48 ) {
case V_51 :
case V_53 :
V_65 -> V_54 . V_55 . V_56 = V_47 . V_56 ;
V_65 -> V_54 . V_55 . V_57 = V_47 . V_57 ;
V_65 -> V_54 . V_55 . V_58 = V_47 . V_58 ;
break;
case V_60 :
case V_61 :
V_65 -> V_54 . V_62 . V_21 = NULL ;
V_65 -> V_54 . V_62 . V_63 = 0 ;
V_65 -> V_54 . V_62 . V_38 = V_47 . V_57 ;
break;
default:
memset ( & V_65 -> V_54 , 0 , sizeof( V_65 -> V_54 ) ) ;
break;
}
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_68 T_1 * V_69 )
{
long V_4 ;
struct V_68 V_70 ;
struct V_92 T_1 * V_72 ;
struct V_41 * V_42 ;
T_3 V_43 ;
T_3 V_35 ;
if ( ! V_8 -> V_6 -> V_17 -> V_18 -> V_93 )
return - V_11 ;
if ( F_15 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_32 ;
if ( V_70 . V_76 > V_77 ||
V_70 . V_76 < sizeof( struct V_92 ) )
return - V_11 ;
V_72 = F_27 ( V_70 . V_78 ) ;
if ( F_35 ( V_35 , & V_72 -> V_35 ) ||
F_35 ( V_43 , & V_72 -> V_43 ) )
return - V_32 ;
if ( sizeof( * V_72 ) + F_28 ( V_43 ) > V_70 . V_76 )
return - V_11 ;
V_42 = F_29 ( V_43 , sizeof( struct V_41 ) , V_12 ) ;
if ( ! V_42 )
return - V_13 ;
V_4 = F_36 ( V_42 , V_43 , V_72 -> V_42 ) ;
if ( V_4 )
goto V_79;
V_4 = V_8 -> V_6 -> V_17 -> V_18 -> V_93 ( V_8 , V_35 , V_43 , V_42 ) ;
V_79:
F_6 ( V_42 ) ;
return V_4 ;
}
static long F_38 ( struct V_2 * V_3 , unsigned int V_94 , unsigned long V_73 )
{
struct V_7 * V_8 = V_3 -> V_16 ;
void T_1 * V_72 = ( void T_1 * ) V_73 ;
switch ( V_94 ) {
case V_95 :
return F_12 ( V_8 , V_72 ) ;
case V_96 :
return F_14 ( V_8 , V_72 ) ;
case V_97 :
return F_26 ( V_8 , V_72 ) ;
case V_98 :
return F_30 ( V_8 , V_72 ) ;
case V_99 :
return F_31 ( V_8 , V_72 ) ;
case V_100 :
return F_32 ( V_8 , V_72 ) ;
case V_101 :
return F_34 ( V_8 , V_72 ) ;
case V_102 :
return F_37 ( V_8 , V_72 ) ;
default:
return - V_11 ;
}
}
static void F_39 ( struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_104 , struct V_5 , V_104 ) ;
F_40 ( & V_105 ) ;
F_41 ( V_6 -> V_37 , V_106 ) ;
F_42 ( & V_105 ) ;
F_43 ( & V_6 -> V_23 ) ;
F_44 ( & V_6 -> V_107 ) ;
F_6 ( V_6 ) ;
}
struct V_5 * F_45 ( const struct V_108 * V_109 ,
struct V_103 * V_104 ,
struct V_110 * V_111 ,
void * V_112 )
{
struct V_5 * V_6 ;
void * V_35 ;
int V_4 ;
int V_113 = 0 ;
if ( ! V_109 || ! V_109 -> V_114 || ! V_109 -> V_18 ||
! V_109 -> V_18 -> V_27 || ! V_109 -> V_18 -> V_19 ||
! V_109 -> V_18 -> V_22 || ! V_111 )
return F_46 ( - V_11 ) ;
V_6 = F_4 ( sizeof( * V_6 ) , V_12 ) ;
if ( ! V_6 ) {
V_35 = F_46 ( - V_13 ) ;
goto V_14;
}
if ( V_109 -> V_28 & V_29 )
V_113 = V_115 / 2 ;
F_40 ( & V_105 ) ;
V_6 -> V_37 = F_47 ( V_106 , V_115 , V_113 ) ;
if ( V_6 -> V_37 < V_115 )
F_48 ( V_6 -> V_37 , V_106 ) ;
F_42 ( & V_105 ) ;
if ( V_6 -> V_37 >= V_115 ) {
V_35 = F_46 ( - V_13 ) ;
goto V_14;
}
snprintf ( V_6 -> V_114 , sizeof( V_6 -> V_114 ) , L_1 ,
V_109 -> V_28 & V_29 ? L_2 : L_3 ,
V_6 -> V_37 - V_113 ) ;
V_6 -> V_104 . V_116 = V_117 ;
V_6 -> V_104 . V_22 = F_39 ;
V_6 -> V_104 . V_118 = V_104 ;
V_6 -> V_104 . V_119 = F_49 ( F_50 ( V_120 ) , V_6 -> V_37 ) ;
V_4 = F_51 ( & V_6 -> V_104 , L_4 , V_6 -> V_114 ) ;
if ( V_4 ) {
V_35 = F_46 ( V_4 ) ;
goto V_121;
}
F_52 ( & V_6 -> V_10 , & V_122 ) ;
V_6 -> V_10 . V_123 = V_109 -> V_123 ;
V_6 -> V_10 . V_124 . V_118 = & V_6 -> V_104 . V_124 ;
F_53 ( & V_6 -> V_104 , V_112 ) ;
F_54 ( & V_6 -> V_104 ) ;
V_6 -> V_125 = 1 ;
F_55 ( & V_6 -> V_126 ) ;
F_56 ( & V_6 -> V_23 ) ;
F_57 ( & V_6 -> V_107 ) ;
V_6 -> V_17 = V_109 ;
V_6 -> V_111 = V_111 ;
return V_6 ;
V_121:
F_58 ( V_6 -> V_104 . V_119 , 1 ) ;
V_14:
F_59 ( L_5 ,
V_109 -> V_28 & V_29 ? L_6 : L_7 ) ;
if ( V_6 && V_6 -> V_37 < V_115 ) {
F_40 ( & V_105 ) ;
F_41 ( V_6 -> V_37 , V_106 ) ;
F_42 ( & V_105 ) ;
}
F_6 ( V_6 ) ;
return V_35 ;
}
static T_4 F_60 ( struct V_103 * V_104 ,
struct V_127 * V_48 , char * V_70 )
{
struct V_5 * V_6 = F_2 ( V_104 , struct V_5 , V_104 ) ;
struct V_24 V_26 ;
V_6 -> V_17 -> V_18 -> V_27 ( V_6 , & V_26 ) ;
return F_61 ( V_70 , V_128 , L_8 , V_26 . V_129 ) ;
}
int F_62 ( struct V_5 * V_6 )
{
int V_4 ;
if ( V_6 -> V_28 & V_130 ) {
F_63 ( & V_6 -> V_104 , L_9 ) ;
return - V_11 ;
}
V_4 = F_64 ( & V_6 -> V_10 , V_6 -> V_104 . V_119 , 1 ) ;
if ( V_4 ) {
F_63 ( & V_6 -> V_104 ,
L_10 ,
V_6 -> V_114 , F_50 ( V_6 -> V_104 . V_119 ) ,
F_65 ( V_6 -> V_104 . V_119 ) , V_4 ) ;
return V_4 ;
}
V_4 = F_66 ( & V_6 -> V_104 ) ;
if ( V_4 ) {
F_63 ( & V_6 -> V_104 ,
L_11 ,
V_6 -> V_114 , F_50 ( V_6 -> V_104 . V_119 ) ,
F_65 ( V_6 -> V_104 . V_119 ) , V_4 ) ;
goto V_131;
}
V_4 = F_67 ( & V_6 -> V_104 . V_124 , & V_132 ) ;
if ( V_4 ) {
F_63 ( & V_6 -> V_104 ,
L_12 , V_4 ) ;
goto V_133;
}
V_6 -> V_28 |= V_130 ;
return 0 ;
V_133:
F_68 ( & V_6 -> V_104 ) ;
V_131:
F_69 ( & V_6 -> V_10 ) ;
return V_4 ;
}
void F_7 ( struct V_5 * V_6 )
{
F_9 ( & V_6 -> V_23 ) ;
if ( ! F_70 ( ! V_6 -> V_17 ) ) {
V_6 -> V_125 -- ;
if ( ! V_6 -> V_125 ) {
V_6 -> V_17 = NULL ;
F_71 ( & V_6 -> V_126 ) ;
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
V_6 -> V_125 ++ ;
F_11 ( & V_6 -> V_23 ) ;
return true ;
}
void F_72 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
if ( V_6 -> V_28 & V_130 ) {
F_73 ( & V_6 -> V_104 . V_124 , & V_132 ) ;
F_69 ( & V_6 -> V_10 ) ;
F_68 ( & V_6 -> V_104 ) ;
}
F_7 ( V_6 ) ;
F_74 ( & V_6 -> V_126 ) ;
V_6 -> V_111 = NULL ;
F_75 ( & V_6 -> V_104 ) ;
}
void * F_76 ( struct V_5 * V_6 )
{
return F_77 ( & V_6 -> V_104 ) ;
}
static int T_5 F_78 ( void )
{
int V_4 ;
V_117 = F_79 ( V_134 , L_13 ) ;
if ( F_17 ( V_117 ) ) {
F_59 ( L_14 ) ;
return F_18 ( V_117 ) ;
}
V_4 = F_80 ( & V_120 , 0 , V_115 , L_13 ) ;
if ( V_4 ) {
F_59 ( L_15 ) ;
F_81 ( V_117 ) ;
V_117 = NULL ;
}
return V_4 ;
}
static void T_6 F_82 ( void )
{
F_81 ( V_117 ) ;
V_117 = NULL ;
F_58 ( V_120 , V_115 ) ;
}
