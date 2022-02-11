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
V_18 -> V_36 = F_24 ( V_19 , V_37 ) + 1 ;
V_32 = F_25 ( V_14 ) ;
if ( V_32 < 0 )
goto V_35;
V_32 = F_26 ( V_19 , V_14 ) ;
if ( V_32 )
goto V_38;
F_27 ( V_19 ) ;
F_28 ( V_19 , V_14 ) ;
F_29 ( V_14 ) ;
F_10 ( V_21 , V_18 -> V_3 , V_4 , V_14 ) ;
V_21 -> V_22 ++ ;
return 0 ;
V_38:
F_30 ( V_14 ) ;
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
static int F_31 ( struct V_5 * V_19 , T_2 V_4 )
{
struct V_5 * V_39 ;
struct V_17 * V_18 ;
struct V_40 * V_40 = F_32 ( V_19 ) ;
struct V_41 * V_42 = F_33 ( V_40 , V_43 ) ;
char V_27 [ V_44 ] ;
int V_32 ;
if ( V_4 >= V_45 )
return - V_46 ;
V_32 = F_17 ( V_19 , F_34 ( V_47 ) , V_4 ) ;
if ( V_32 < 0 )
return V_32 ;
switch ( V_42 -> V_48 ) {
case V_49 :
snprintf ( V_27 , V_44 , L_2 , V_19 -> V_27 , V_4 ) ;
break;
case V_50 :
snprintf ( V_27 , V_44 , L_3 , V_4 ) ;
break;
case V_51 :
snprintf ( V_27 , V_44 , L_4 , V_19 -> V_27 , V_4 ) ;
break;
case V_52 :
default:
snprintf ( V_27 , V_44 , L_5 , V_4 ) ;
}
V_39 = F_35 ( sizeof( struct V_17 ) , V_27 ,
V_53 , V_54 ) ;
if ( V_39 == NULL )
return - V_13 ;
F_36 ( V_39 , V_40 ) ;
V_39 -> V_55 = V_19 -> V_55 ;
V_18 = V_17 ( V_39 ) ;
V_18 -> V_3 = F_34 ( V_47 ) ;
V_18 -> V_4 = V_4 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_56 = NULL ;
V_18 -> V_23 = V_57 ;
V_39 -> V_58 = & V_59 ;
V_32 = F_20 ( V_39 ) ;
if ( V_32 < 0 )
goto V_60;
return 0 ;
V_60:
F_37 ( V_39 ) ;
return V_32 ;
}
static void F_38 ( struct V_5 * V_14 ,
struct V_5 * V_61 )
{
struct V_17 * V_18 = V_17 ( V_61 ) ;
if ( F_39 ( V_18 -> V_62 , V_14 -> V_63 ) )
return;
if ( F_40 ( V_61 , V_14 ) )
goto V_64;
if ( ! F_39 ( V_61 -> V_63 , V_18 -> V_62 ) &&
F_39 ( V_61 -> V_63 , V_14 -> V_63 ) )
F_41 ( V_14 , V_61 -> V_63 ) ;
if ( F_39 ( V_61 -> V_63 , V_18 -> V_62 ) &&
! F_39 ( V_61 -> V_63 , V_14 -> V_63 ) )
F_42 ( V_14 , V_61 -> V_63 ) ;
V_64:
F_43 ( V_18 -> V_62 , V_14 -> V_63 ) ;
}
static void F_44 ( struct V_5 * V_14 ,
struct V_5 * V_61 )
{
struct V_17 * V_18 = V_17 ( V_61 ) ;
V_61 -> V_65 = V_14 -> V_65 ;
V_61 -> V_66 = V_14 -> V_66 ;
if ( F_45 ( V_14 -> V_28 , V_18 -> V_3 ) )
V_61 -> V_67 = V_14 -> V_67 ;
else
V_61 -> V_67 = V_14 -> V_67 + V_68 ;
#if F_46 ( V_69 )
V_61 -> V_70 = V_14 -> V_70 ;
#endif
F_47 ( V_61 ) ;
}
static int F_48 ( struct V_5 * V_14 , unsigned long V_71 )
{
int V_32 = 0 ;
switch ( V_71 ) {
case V_72 :
F_49 ( V_14 ) ;
V_32 = F_50 ( V_14 ) ;
break;
case V_73 :
V_32 = F_50 ( V_14 ) ;
break;
case V_74 :
F_49 ( V_14 ) ;
break;
}
return V_32 ;
}
static int F_51 ( struct V_75 * V_76 , unsigned long V_71 ,
void * V_77 )
{
struct V_5 * V_14 = F_52 ( V_77 ) ;
struct V_1 * V_21 ;
struct V_20 * V_20 ;
int V_78 , V_79 ;
struct V_5 * V_61 ;
struct V_17 * V_18 ;
bool V_80 = false ;
F_53 ( V_81 ) ;
if ( V_37 ( V_14 ) ) {
int V_32 = F_48 ( V_14 , V_71 ) ;
if ( V_32 )
return F_54 ( V_32 ) ;
}
if ( ( V_71 == V_82 ) &&
( V_14 -> V_28 & V_83 ) ) {
F_18 ( L_6 ,
V_14 -> V_27 ) ;
F_21 ( V_14 , F_34 ( V_47 ) , 0 ) ;
}
V_20 = F_6 ( V_14 -> V_20 ) ;
if ( ! V_20 )
goto V_64;
V_21 = & V_20 -> V_21 ;
switch ( V_71 ) {
case V_84 :
F_55 (grp, i, vlandev)
F_28 ( V_14 , V_61 ) ;
break;
case V_85 :
F_55 (grp, i, vlandev) {
V_79 = V_61 -> V_23 ;
if ( ! ( V_79 & V_86 ) )
continue;
F_38 ( V_14 , V_61 ) ;
}
break;
case V_87 :
F_55 (grp, i, vlandev) {
if ( V_61 -> V_55 <= V_14 -> V_55 )
continue;
F_56 ( V_61 , V_14 -> V_55 ) ;
}
break;
case V_88 :
F_55 (grp, i, vlandev)
F_44 ( V_14 , V_61 ) ;
break;
case V_89 : {
struct V_5 * V_90 ;
F_53 ( V_91 ) ;
if ( V_14 -> V_28 & V_83 )
F_15 ( V_14 , F_34 ( V_47 ) , 0 ) ;
F_55 (grp, i, vlandev) {
V_79 = V_61 -> V_23 ;
if ( ! ( V_79 & V_86 ) )
continue;
V_18 = V_17 ( V_61 ) ;
if ( ! ( V_18 -> V_23 & V_92 ) )
F_57 ( & V_61 -> V_91 , & V_91 ) ;
}
F_58 ( & V_91 , false ) ;
F_59 (vlandev, tmp, &close_list, close_list) {
F_28 ( V_14 , V_61 ) ;
F_60 ( & V_61 -> V_91 ) ;
}
F_61 ( & V_91 ) ;
break;
}
case V_82 :
F_55 (grp, i, vlandev) {
V_79 = F_62 ( V_61 ) ;
if ( V_79 & V_86 )
continue;
V_18 = V_17 ( V_61 ) ;
if ( ! ( V_18 -> V_23 & V_92 ) )
F_63 ( V_61 , V_79 | V_86 ) ;
F_28 ( V_14 , V_61 ) ;
}
break;
case V_74 :
if ( V_14 -> V_93 != V_94 )
break;
F_55 (grp, i, vlandev) {
if ( V_20 -> V_95 == 1 )
V_80 = true ;
F_5 ( V_61 , & V_81 ) ;
if ( V_80 )
break;
}
F_64 ( & V_81 ) ;
break;
case V_96 :
if ( F_65 ( V_14 ) )
return V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
F_55 (grp, i, vlandev)
F_66 ( V_71 , V_61 ) ;
break;
}
V_64:
return V_101 ;
}
static int F_67 ( struct V_40 * V_40 , void T_3 * V_102 )
{
int V_32 ;
struct V_103 args ;
struct V_5 * V_14 = NULL ;
if ( F_68 ( & args , V_102 , sizeof( struct V_103 ) ) )
return - V_104 ;
args . V_105 [ 23 ] = 0 ;
args . V_106 . V_107 [ 23 ] = 0 ;
F_69 () ;
switch ( args . V_108 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_32 = - V_116 ;
V_14 = F_70 ( V_40 , args . V_105 ) ;
if ( ! V_14 )
goto V_64;
V_32 = - V_117 ;
if ( args . V_108 != V_112 && ! V_37 ( V_14 ) )
goto V_64;
}
switch ( args . V_108 ) {
case V_109 :
V_32 = - V_118 ;
if ( ! F_71 ( V_40 -> V_119 , V_120 ) )
break;
F_72 ( V_14 ,
args . V_106 . V_121 ,
args . V_122 ) ;
V_32 = 0 ;
break;
case V_110 :
V_32 = - V_118 ;
if ( ! F_71 ( V_40 -> V_119 , V_120 ) )
break;
V_32 = F_73 ( V_14 ,
args . V_106 . V_121 ,
args . V_122 ) ;
break;
case V_111 :
V_32 = - V_118 ;
if ( ! F_71 ( V_40 -> V_119 , V_120 ) )
break;
V_32 = F_74 ( V_14 ,
args . V_122 ? args . V_106 . V_123 : 0 ,
args . V_106 . V_123 ) ;
break;
case V_124 :
V_32 = - V_118 ;
if ( ! F_71 ( V_40 -> V_119 , V_120 ) )
break;
if ( ( args . V_106 . V_48 >= 0 ) &&
( args . V_106 . V_48 < V_125 ) ) {
struct V_41 * V_42 ;
V_42 = F_33 ( V_40 , V_43 ) ;
V_42 -> V_48 = args . V_106 . V_48 ;
V_32 = 0 ;
} else {
V_32 = - V_117 ;
}
break;
case V_112 :
V_32 = - V_118 ;
if ( ! F_71 ( V_40 -> V_119 , V_120 ) )
break;
V_32 = F_31 ( V_14 , args . V_106 . V_126 ) ;
break;
case V_113 :
V_32 = - V_118 ;
if ( ! F_71 ( V_40 -> V_119 , V_120 ) )
break;
F_5 ( V_14 , NULL ) ;
V_32 = 0 ;
break;
case V_114 :
V_32 = 0 ;
F_75 ( V_14 , args . V_106 . V_107 ) ;
if ( F_76 ( V_102 , & args ,
sizeof( struct V_103 ) ) )
V_32 = - V_104 ;
break;
case V_115 :
V_32 = 0 ;
args . V_106 . V_126 = F_77 ( V_14 ) ;
if ( F_76 ( V_102 , & args ,
sizeof( struct V_103 ) ) )
V_32 = - V_104 ;
break;
default:
V_32 = - V_30 ;
break;
}
V_64:
F_78 () ;
return V_32 ;
}
static struct V_127 * * F_79 ( struct V_127 * * V_16 ,
struct V_127 * V_128 )
{
struct V_127 * V_129 , * * V_130 = NULL ;
struct V_131 * V_132 ;
unsigned int V_133 , V_134 ;
const struct V_135 * V_136 ;
T_1 type ;
int V_137 = 1 ;
V_134 = F_80 ( V_128 ) ;
V_133 = V_134 + sizeof( * V_132 ) ;
V_132 = F_81 ( V_128 , V_134 ) ;
if ( F_82 ( V_128 , V_133 ) ) {
V_132 = F_83 ( V_128 , V_133 , V_134 ) ;
if ( F_84 ( ! V_132 ) )
goto V_64;
}
type = V_132 -> V_138 ;
F_85 () ;
V_136 = F_86 ( type ) ;
if ( ! V_136 )
goto V_139;
V_137 = 0 ;
for ( V_129 = * V_16 ; V_129 ; V_129 = V_129 -> V_140 ) {
struct V_131 * V_141 ;
if ( ! F_87 ( V_129 ) -> V_142 )
continue;
V_141 = (struct V_131 * ) ( V_129 -> V_143 + V_134 ) ;
if ( F_88 ( V_132 , V_141 ) )
F_87 ( V_129 ) -> V_142 = 0 ;
}
F_89 ( V_128 , sizeof( * V_132 ) ) ;
F_90 ( V_128 , V_132 , sizeof( * V_132 ) ) ;
V_130 = V_136 -> V_144 . V_145 ( V_16 , V_128 ) ;
V_139:
F_91 () ;
V_64:
F_87 ( V_128 ) -> V_137 |= V_137 ;
return V_130 ;
}
static int F_92 ( struct V_127 * V_128 , int V_146 )
{
struct V_131 * V_132 = (struct V_131 * ) ( V_128 -> V_143 + V_146 ) ;
T_1 type = V_132 -> V_138 ;
struct V_135 * V_136 ;
int V_32 = - V_147 ;
F_85 () ;
V_136 = F_93 ( type ) ;
if ( V_136 )
V_32 = V_136 -> V_144 . V_148 ( V_128 , V_146 + sizeof( * V_132 ) ) ;
F_91 () ;
return V_32 ;
}
static int T_4 F_94 ( struct V_40 * V_40 )
{
struct V_41 * V_42 = F_33 ( V_40 , V_43 ) ;
int V_32 ;
V_42 -> V_48 = V_51 ;
V_32 = F_95 ( V_40 ) ;
return V_32 ;
}
static void T_5 F_96 ( struct V_40 * V_40 )
{
F_97 ( V_40 ) ;
}
static int T_6 F_98 ( void )
{
int V_32 ;
unsigned int V_78 ;
F_18 ( L_7 , V_149 , V_150 ) ;
V_32 = F_99 ( & V_151 ) ;
if ( V_32 < 0 )
goto V_152;
V_32 = F_100 ( & V_153 ) ;
if ( V_32 < 0 )
goto V_154;
V_32 = F_101 () ;
if ( V_32 < 0 )
goto V_155;
V_32 = F_102 () ;
if ( V_32 < 0 )
goto V_156;
V_32 = F_103 () ;
if ( V_32 < 0 )
goto V_157;
for ( V_78 = 0 ; V_78 < F_104 ( V_158 ) ; V_78 ++ )
F_105 ( & V_158 [ V_78 ] ) ;
F_106 ( F_67 ) ;
return 0 ;
V_157:
F_107 () ;
V_156:
F_108 () ;
V_155:
F_109 ( & V_153 ) ;
V_154:
F_110 ( & V_151 ) ;
V_152:
return V_32 ;
}
static void T_7 F_111 ( void )
{
unsigned int V_78 ;
F_106 ( NULL ) ;
for ( V_78 = 0 ; V_78 < F_104 ( V_158 ) ; V_78 ++ )
F_112 ( & V_158 [ V_78 ] ) ;
F_113 () ;
F_109 ( & V_153 ) ;
F_110 ( & V_151 ) ;
F_114 () ;
F_107 () ;
F_108 () ;
}
