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
memcpy ( V_18 -> V_61 , V_14 -> V_62 , V_63 ) ;
}
static void F_41 ( struct V_5 * V_14 ,
struct V_5 * V_60 )
{
V_60 -> V_64 = V_14 -> V_64 ;
if ( V_14 -> V_28 & V_65 )
V_60 -> V_66 = V_14 -> V_66 ;
else
V_60 -> V_66 = V_14 -> V_66 + V_67 ;
#if F_42 ( V_68 )
V_60 -> V_69 = V_14 -> V_69 ;
#endif
F_43 ( V_60 ) ;
}
static void F_44 ( struct V_5 * V_14 , unsigned long V_70 )
{
switch ( V_70 ) {
case V_71 :
F_45 ( V_14 ) ;
if ( F_46 ( V_14 ) < 0 )
F_47 ( L_6 ,
V_14 -> V_27 ) ;
break;
case V_72 :
if ( F_46 ( V_14 ) < 0 )
F_47 ( L_7 , V_14 -> V_27 ) ;
break;
case V_73 :
F_45 ( V_14 ) ;
break;
}
}
static int F_48 ( struct V_74 * V_75 , unsigned long V_70 ,
void * V_76 )
{
struct V_5 * V_14 = F_49 ( V_76 ) ;
struct V_1 * V_21 ;
struct V_20 * V_20 ;
int V_77 , V_78 ;
struct V_5 * V_60 ;
struct V_17 * V_18 ;
bool V_79 = false ;
F_50 ( V_80 ) ;
if ( F_51 ( V_14 ) )
F_44 ( V_14 , V_70 ) ;
if ( ( V_70 == V_81 ) &&
( V_14 -> V_28 & V_82 ) ) {
F_18 ( L_8 ,
V_14 -> V_27 ) ;
F_21 ( V_14 , F_33 ( V_45 ) , 0 ) ;
}
V_20 = F_6 ( V_14 -> V_20 ) ;
if ( ! V_20 )
goto V_83;
V_21 = & V_20 -> V_21 ;
switch ( V_70 ) {
case V_84 :
F_52 (grp, i, vlandev)
F_27 ( V_14 , V_60 ) ;
break;
case V_85 :
F_52 (grp, i, vlandev) {
V_78 = V_60 -> V_23 ;
if ( ! ( V_78 & V_86 ) )
continue;
F_37 ( V_14 , V_60 ) ;
}
break;
case V_87 :
F_52 (grp, i, vlandev) {
if ( V_60 -> V_52 <= V_14 -> V_52 )
continue;
F_53 ( V_60 , V_14 -> V_52 ) ;
}
break;
case V_88 :
F_52 (grp, i, vlandev)
F_41 ( V_14 , V_60 ) ;
break;
case V_89 :
if ( V_14 -> V_28 & V_82 )
F_15 ( V_14 , F_33 ( V_45 ) , 0 ) ;
F_52 (grp, i, vlandev) {
V_78 = V_60 -> V_23 ;
if ( ! ( V_78 & V_86 ) )
continue;
V_18 = V_17 ( V_60 ) ;
if ( ! ( V_18 -> V_23 & V_90 ) )
F_54 ( V_60 , V_78 & ~ V_86 ) ;
F_27 ( V_14 , V_60 ) ;
}
break;
case V_81 :
F_52 (grp, i, vlandev) {
V_78 = V_60 -> V_23 ;
if ( V_78 & V_86 )
continue;
V_18 = V_17 ( V_60 ) ;
if ( ! ( V_18 -> V_23 & V_90 ) )
F_54 ( V_60 , V_78 | V_86 ) ;
F_27 ( V_14 , V_60 ) ;
}
break;
case V_73 :
if ( V_14 -> V_91 != V_92 )
break;
F_52 (grp, i, vlandev) {
if ( V_20 -> V_93 == 1 )
V_79 = true ;
F_5 ( V_60 , & V_80 ) ;
if ( V_79 )
break;
}
F_55 ( & V_80 ) ;
break;
case V_94 :
if ( F_56 ( V_14 ) )
return V_95 ;
break;
case V_96 :
case V_97 :
case V_98 :
F_52 (grp, i, vlandev)
F_57 ( V_70 , V_60 ) ;
break;
}
V_83:
return V_99 ;
}
static int F_58 ( struct V_38 * V_38 , void T_3 * V_100 )
{
int V_32 ;
struct V_101 args ;
struct V_5 * V_14 = NULL ;
if ( F_59 ( & args , V_100 , sizeof( struct V_101 ) ) )
return - V_102 ;
args . V_103 [ 23 ] = 0 ;
args . V_104 . V_105 [ 23 ] = 0 ;
F_60 () ;
switch ( args . V_106 ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_32 = - V_114 ;
V_14 = F_61 ( V_38 , args . V_103 ) ;
if ( ! V_14 )
goto V_83;
V_32 = - V_115 ;
if ( args . V_106 != V_110 && ! F_51 ( V_14 ) )
goto V_83;
}
switch ( args . V_106 ) {
case V_107 :
V_32 = - V_116 ;
if ( ! F_62 ( V_38 -> V_117 , V_118 ) )
break;
F_63 ( V_14 ,
args . V_104 . V_119 ,
args . V_120 ) ;
V_32 = 0 ;
break;
case V_108 :
V_32 = - V_116 ;
if ( ! F_62 ( V_38 -> V_117 , V_118 ) )
break;
V_32 = F_64 ( V_14 ,
args . V_104 . V_119 ,
args . V_120 ) ;
break;
case V_109 :
V_32 = - V_116 ;
if ( ! F_62 ( V_38 -> V_117 , V_118 ) )
break;
V_32 = F_65 ( V_14 ,
args . V_120 ? args . V_104 . V_121 : 0 ,
args . V_104 . V_121 ) ;
break;
case V_122 :
V_32 = - V_116 ;
if ( ! F_62 ( V_38 -> V_117 , V_118 ) )
break;
if ( ( args . V_104 . V_46 >= 0 ) &&
( args . V_104 . V_46 < V_123 ) ) {
struct V_39 * V_40 ;
V_40 = F_32 ( V_38 , V_41 ) ;
V_40 -> V_46 = args . V_104 . V_46 ;
V_32 = 0 ;
} else {
V_32 = - V_115 ;
}
break;
case V_110 :
V_32 = - V_116 ;
if ( ! F_62 ( V_38 -> V_117 , V_118 ) )
break;
V_32 = F_30 ( V_14 , args . V_104 . V_124 ) ;
break;
case V_111 :
V_32 = - V_116 ;
if ( ! F_62 ( V_38 -> V_117 , V_118 ) )
break;
F_5 ( V_14 , NULL ) ;
V_32 = 0 ;
break;
case V_112 :
V_32 = 0 ;
F_66 ( V_14 , args . V_104 . V_105 ) ;
if ( F_67 ( V_100 , & args ,
sizeof( struct V_101 ) ) )
V_32 = - V_102 ;
break;
case V_113 :
V_32 = 0 ;
args . V_104 . V_124 = F_68 ( V_14 ) ;
if ( F_67 ( V_100 , & args ,
sizeof( struct V_101 ) ) )
V_32 = - V_102 ;
break;
default:
V_32 = - V_30 ;
break;
}
V_83:
F_69 () ;
return V_32 ;
}
static int T_4 F_70 ( struct V_38 * V_38 )
{
struct V_39 * V_40 = F_32 ( V_38 , V_41 ) ;
int V_32 ;
V_40 -> V_46 = V_49 ;
V_32 = F_71 ( V_38 ) ;
return V_32 ;
}
static void T_5 F_72 ( struct V_38 * V_38 )
{
F_73 ( V_38 ) ;
}
static int T_6 F_74 ( void )
{
int V_32 ;
F_18 ( L_9 , V_125 , V_126 ) ;
V_32 = F_75 ( & V_127 ) ;
if ( V_32 < 0 )
goto V_128;
V_32 = F_76 ( & V_129 ) ;
if ( V_32 < 0 )
goto V_130;
V_32 = F_77 () ;
if ( V_32 < 0 )
goto V_131;
V_32 = F_78 () ;
if ( V_32 < 0 )
goto V_132;
V_32 = F_79 () ;
if ( V_32 < 0 )
goto V_133;
F_80 ( F_58 ) ;
return 0 ;
V_133:
F_81 () ;
V_132:
F_82 () ;
V_131:
F_83 ( & V_129 ) ;
V_130:
F_84 ( & V_127 ) ;
V_128:
return V_32 ;
}
static void T_7 F_85 ( void )
{
F_80 ( NULL ) ;
F_86 () ;
F_83 ( & V_129 ) ;
F_84 ( & V_127 ) ;
F_87 () ;
F_81 () ;
F_82 () ;
}
