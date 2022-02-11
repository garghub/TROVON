static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * * V_6 ;
unsigned int V_7 , V_8 ;
unsigned int V_9 ;
F_2 () ;
V_7 = F_3 ( V_3 ) ;
V_8 = V_4 / V_10 ;
V_6 = V_2 -> V_11 [ V_7 ] [ V_8 ] ;
if ( V_6 != NULL )
return 0 ;
V_9 = sizeof( struct V_5 * ) * V_10 ;
V_6 = F_4 ( V_9 , V_12 ) ;
if ( V_6 == NULL )
return - V_13 ;
V_2 -> V_11 [ V_7 ] [ V_8 ] = V_6 ;
return 0 ;
}
void F_5 ( struct V_5 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_17 ( V_14 ) ;
struct V_5 * V_19 = V_18 -> V_19 ;
struct V_20 * V_20 ;
struct V_1 * V_21 ;
T_2 V_4 = V_18 -> V_4 ;
F_2 () ;
V_20 = F_6 ( V_19 -> V_20 ) ;
F_7 ( ! V_20 ) ;
V_21 = & V_20 -> V_21 ;
V_21 -> V_22 -- ;
if ( V_18 -> V_23 & V_24 )
F_8 ( V_14 ) ;
if ( V_18 -> V_23 & V_25 )
F_9 ( V_14 ) ;
F_10 ( V_21 , V_18 -> V_3 , V_4 , NULL ) ;
F_11 ( V_19 , V_14 ) ;
F_12 ( V_14 , V_16 ) ;
if ( V_21 -> V_22 == 0 ) {
F_13 ( V_19 ) ;
F_14 ( V_19 ) ;
}
if ( V_4 )
F_15 ( V_19 , V_18 -> V_3 , V_4 ) ;
F_16 ( V_19 ) ;
}
int F_17 ( struct V_5 * V_19 ,
T_1 V_26 , T_2 V_4 )
{
const char * V_27 = V_19 -> V_27 ;
if ( V_19 -> V_28 & V_29 ) {
F_18 ( L_1 , V_27 ) ;
return - V_30 ;
}
if ( F_19 ( V_19 , V_26 , V_4 ) != NULL )
return - V_31 ;
return 0 ;
}
int F_20 ( struct V_5 * V_14 )
{
struct V_17 * V_18 = V_17 ( V_14 ) ;
struct V_5 * V_19 = V_18 -> V_19 ;
T_2 V_4 = V_18 -> V_4 ;
struct V_20 * V_20 ;
struct V_1 * V_21 ;
int V_32 ;
V_32 = F_21 ( V_19 , V_18 -> V_3 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_20 = F_6 ( V_19 -> V_20 ) ;
F_7 ( ! V_20 ) ;
V_21 = & V_20 -> V_21 ;
if ( V_21 -> V_22 == 0 ) {
V_32 = F_22 ( V_19 ) ;
if ( V_32 < 0 )
goto V_33;
V_32 = F_23 ( V_19 ) ;
if ( V_32 < 0 )
goto V_34;
}
V_32 = F_1 ( V_21 , V_18 -> V_3 , V_4 ) ;
if ( V_32 < 0 )
goto V_35;
V_32 = F_24 ( V_14 ) ;
if ( V_32 < 0 )
goto V_35;
V_32 = F_25 ( V_19 , V_14 ) ;
if ( V_32 )
goto V_36;
F_26 ( V_19 ) ;
F_27 ( V_19 , V_14 ) ;
F_28 ( V_14 ) ;
F_10 ( V_21 , V_18 -> V_3 , V_4 , V_14 ) ;
V_21 -> V_22 ++ ;
return 0 ;
V_36:
F_29 ( V_14 ) ;
V_35:
if ( V_21 -> V_22 == 0 )
F_13 ( V_19 ) ;
V_34:
if ( V_21 -> V_22 == 0 )
F_14 ( V_19 ) ;
V_33:
F_15 ( V_19 , V_18 -> V_3 , V_4 ) ;
return V_32 ;
}
static int F_30 ( struct V_5 * V_19 , T_2 V_4 )
{
struct V_5 * V_37 ;
struct V_17 * V_18 ;
struct V_38 * V_38 = F_31 ( V_19 ) ;
struct V_39 * V_40 = F_32 ( V_38 , V_41 ) ;
char V_27 [ V_42 ] ;
int V_32 ;
if ( V_4 >= V_43 )
return - V_44 ;
V_32 = F_17 ( V_19 , F_33 ( V_45 ) , V_4 ) ;
if ( V_32 < 0 )
return V_32 ;
switch ( V_40 -> V_46 ) {
case V_47 :
snprintf ( V_27 , V_42 , L_2 , V_19 -> V_27 , V_4 ) ;
break;
case V_48 :
snprintf ( V_27 , V_42 , L_3 , V_4 ) ;
break;
case V_49 :
snprintf ( V_27 , V_42 , L_4 , V_19 -> V_27 , V_4 ) ;
break;
case V_50 :
default:
snprintf ( V_27 , V_42 , L_5 , V_4 ) ;
}
V_37 = F_34 ( sizeof( struct V_17 ) , V_27 , V_51 ) ;
if ( V_37 == NULL )
return - V_13 ;
F_35 ( V_37 , V_38 ) ;
V_37 -> V_52 = V_19 -> V_52 ;
V_37 -> V_53 |= ( V_19 -> V_53 & V_54 ) ;
V_18 = V_17 ( V_37 ) ;
V_18 -> V_3 = F_33 ( V_45 ) ;
V_18 -> V_4 = V_4 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_55 = NULL ;
V_18 -> V_23 = V_56 ;
V_37 -> V_57 = & V_58 ;
V_32 = F_20 ( V_37 ) ;
if ( V_32 < 0 )
goto V_59;
return 0 ;
V_59:
F_36 ( V_37 ) ;
return V_32 ;
}
static void F_37 ( struct V_5 * V_14 ,
struct V_5 * V_60 )
{
struct V_17 * V_18 = V_17 ( V_60 ) ;
if ( F_38 ( V_18 -> V_61 , V_14 -> V_62 ) )
return;
if ( ! F_38 ( V_60 -> V_62 , V_18 -> V_61 ) &&
F_38 ( V_60 -> V_62 , V_14 -> V_62 ) )
F_39 ( V_14 , V_60 -> V_62 ) ;
if ( F_38 ( V_60 -> V_62 , V_18 -> V_61 ) &&
! F_38 ( V_60 -> V_62 , V_14 -> V_62 ) )
F_40 ( V_14 , V_60 -> V_62 ) ;
F_41 ( V_18 -> V_61 , V_14 -> V_62 ) ;
}
static void F_42 ( struct V_5 * V_14 ,
struct V_5 * V_60 )
{
struct V_17 * V_18 = V_17 ( V_60 ) ;
V_60 -> V_63 = V_14 -> V_63 ;
if ( F_43 ( V_14 -> V_28 , V_18 -> V_3 ) )
V_60 -> V_64 = V_14 -> V_64 ;
else
V_60 -> V_64 = V_14 -> V_64 + V_65 ;
#if F_44 ( V_66 )
V_60 -> V_67 = V_14 -> V_67 ;
#endif
F_45 ( V_60 ) ;
}
static void F_46 ( struct V_5 * V_14 , unsigned long V_68 )
{
switch ( V_68 ) {
case V_69 :
F_47 ( V_14 ) ;
if ( F_48 ( V_14 ) < 0 )
F_49 ( L_6 ,
V_14 -> V_27 ) ;
break;
case V_70 :
if ( F_48 ( V_14 ) < 0 )
F_49 ( L_7 , V_14 -> V_27 ) ;
break;
case V_71 :
F_47 ( V_14 ) ;
break;
}
}
static int F_50 ( struct V_72 * V_73 , unsigned long V_68 ,
void * V_74 )
{
struct V_5 * V_14 = F_51 ( V_74 ) ;
struct V_1 * V_21 ;
struct V_20 * V_20 ;
int V_75 , V_76 ;
struct V_5 * V_60 ;
struct V_17 * V_18 ;
bool V_77 = false ;
F_52 ( V_78 ) ;
if ( F_53 ( V_14 ) )
F_46 ( V_14 , V_68 ) ;
if ( ( V_68 == V_79 ) &&
( V_14 -> V_28 & V_80 ) ) {
F_18 ( L_8 ,
V_14 -> V_27 ) ;
F_21 ( V_14 , F_33 ( V_45 ) , 0 ) ;
}
V_20 = F_6 ( V_14 -> V_20 ) ;
if ( ! V_20 )
goto V_81;
V_21 = & V_20 -> V_21 ;
switch ( V_68 ) {
case V_82 :
F_54 (grp, i, vlandev)
F_27 ( V_14 , V_60 ) ;
break;
case V_83 :
F_54 (grp, i, vlandev) {
V_76 = V_60 -> V_23 ;
if ( ! ( V_76 & V_84 ) )
continue;
F_37 ( V_14 , V_60 ) ;
}
break;
case V_85 :
F_54 (grp, i, vlandev) {
if ( V_60 -> V_52 <= V_14 -> V_52 )
continue;
F_55 ( V_60 , V_14 -> V_52 ) ;
}
break;
case V_86 :
F_54 (grp, i, vlandev)
F_42 ( V_14 , V_60 ) ;
break;
case V_87 :
if ( V_14 -> V_28 & V_80 )
F_15 ( V_14 , F_33 ( V_45 ) , 0 ) ;
F_54 (grp, i, vlandev) {
V_76 = V_60 -> V_23 ;
if ( ! ( V_76 & V_84 ) )
continue;
V_18 = V_17 ( V_60 ) ;
if ( ! ( V_18 -> V_23 & V_88 ) )
F_56 ( V_60 , V_76 & ~ V_84 ) ;
F_27 ( V_14 , V_60 ) ;
}
break;
case V_79 :
F_54 (grp, i, vlandev) {
V_76 = V_60 -> V_23 ;
if ( V_76 & V_84 )
continue;
V_18 = V_17 ( V_60 ) ;
if ( ! ( V_18 -> V_23 & V_88 ) )
F_56 ( V_60 , V_76 | V_84 ) ;
F_27 ( V_14 , V_60 ) ;
}
break;
case V_71 :
if ( V_14 -> V_89 != V_90 )
break;
F_54 (grp, i, vlandev) {
if ( V_20 -> V_91 == 1 )
V_77 = true ;
F_5 ( V_60 , & V_78 ) ;
if ( V_77 )
break;
}
F_57 ( & V_78 ) ;
break;
case V_92 :
if ( F_58 ( V_14 ) )
return V_93 ;
break;
case V_94 :
case V_95 :
case V_96 :
F_54 (grp, i, vlandev)
F_59 ( V_68 , V_60 ) ;
break;
}
V_81:
return V_97 ;
}
static int F_60 ( struct V_38 * V_38 , void T_3 * V_98 )
{
int V_32 ;
struct V_99 args ;
struct V_5 * V_14 = NULL ;
if ( F_61 ( & args , V_98 , sizeof( struct V_99 ) ) )
return - V_100 ;
args . V_101 [ 23 ] = 0 ;
args . V_102 . V_103 [ 23 ] = 0 ;
F_62 () ;
switch ( args . V_104 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_32 = - V_112 ;
V_14 = F_63 ( V_38 , args . V_101 ) ;
if ( ! V_14 )
goto V_81;
V_32 = - V_113 ;
if ( args . V_104 != V_108 && ! F_53 ( V_14 ) )
goto V_81;
}
switch ( args . V_104 ) {
case V_105 :
V_32 = - V_114 ;
if ( ! F_64 ( V_38 -> V_115 , V_116 ) )
break;
F_65 ( V_14 ,
args . V_102 . V_117 ,
args . V_118 ) ;
V_32 = 0 ;
break;
case V_106 :
V_32 = - V_114 ;
if ( ! F_64 ( V_38 -> V_115 , V_116 ) )
break;
V_32 = F_66 ( V_14 ,
args . V_102 . V_117 ,
args . V_118 ) ;
break;
case V_107 :
V_32 = - V_114 ;
if ( ! F_64 ( V_38 -> V_115 , V_116 ) )
break;
V_32 = F_67 ( V_14 ,
args . V_118 ? args . V_102 . V_119 : 0 ,
args . V_102 . V_119 ) ;
break;
case V_120 :
V_32 = - V_114 ;
if ( ! F_64 ( V_38 -> V_115 , V_116 ) )
break;
if ( ( args . V_102 . V_46 >= 0 ) &&
( args . V_102 . V_46 < V_121 ) ) {
struct V_39 * V_40 ;
V_40 = F_32 ( V_38 , V_41 ) ;
V_40 -> V_46 = args . V_102 . V_46 ;
V_32 = 0 ;
} else {
V_32 = - V_113 ;
}
break;
case V_108 :
V_32 = - V_114 ;
if ( ! F_64 ( V_38 -> V_115 , V_116 ) )
break;
V_32 = F_30 ( V_14 , args . V_102 . V_122 ) ;
break;
case V_109 :
V_32 = - V_114 ;
if ( ! F_64 ( V_38 -> V_115 , V_116 ) )
break;
F_5 ( V_14 , NULL ) ;
V_32 = 0 ;
break;
case V_110 :
V_32 = 0 ;
F_68 ( V_14 , args . V_102 . V_103 ) ;
if ( F_69 ( V_98 , & args ,
sizeof( struct V_99 ) ) )
V_32 = - V_100 ;
break;
case V_111 :
V_32 = 0 ;
args . V_102 . V_122 = F_70 ( V_14 ) ;
if ( F_69 ( V_98 , & args ,
sizeof( struct V_99 ) ) )
V_32 = - V_100 ;
break;
default:
V_32 = - V_30 ;
break;
}
V_81:
F_71 () ;
return V_32 ;
}
static int T_4 F_72 ( struct V_38 * V_38 )
{
struct V_39 * V_40 = F_32 ( V_38 , V_41 ) ;
int V_32 ;
V_40 -> V_46 = V_49 ;
V_32 = F_73 ( V_38 ) ;
return V_32 ;
}
static void T_5 F_74 ( struct V_38 * V_38 )
{
F_75 ( V_38 ) ;
}
static int T_6 F_76 ( void )
{
int V_32 ;
F_18 ( L_9 , V_123 , V_124 ) ;
V_32 = F_77 ( & V_125 ) ;
if ( V_32 < 0 )
goto V_126;
V_32 = F_78 ( & V_127 ) ;
if ( V_32 < 0 )
goto V_128;
V_32 = F_79 () ;
if ( V_32 < 0 )
goto V_129;
V_32 = F_80 () ;
if ( V_32 < 0 )
goto V_130;
V_32 = F_81 () ;
if ( V_32 < 0 )
goto V_131;
F_82 ( F_60 ) ;
return 0 ;
V_131:
F_83 () ;
V_130:
F_84 () ;
V_129:
F_85 ( & V_127 ) ;
V_128:
F_86 ( & V_125 ) ;
V_126:
return V_32 ;
}
static void T_7 F_87 ( void )
{
F_82 ( NULL ) ;
F_88 () ;
F_85 ( & V_127 ) ;
F_86 ( & V_125 ) ;
F_89 () ;
F_83 () ;
F_84 () ;
}
