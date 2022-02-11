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
V_18 -> V_36 = F_24 ( V_19 ) + 1 ;
V_32 = F_25 ( V_14 ) ;
if ( V_32 < 0 )
goto V_35;
V_32 = F_26 ( V_19 , V_14 ) ;
if ( V_32 )
goto V_37;
F_27 ( V_19 ) ;
F_28 ( V_19 , V_14 ) ;
F_29 ( V_14 ) ;
F_10 ( V_21 , V_18 -> V_3 , V_4 , V_14 ) ;
V_21 -> V_22 ++ ;
return 0 ;
V_37:
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
struct V_5 * V_38 ;
struct V_17 * V_18 ;
struct V_39 * V_39 = F_32 ( V_19 ) ;
struct V_40 * V_41 = F_33 ( V_39 , V_42 ) ;
char V_27 [ V_43 ] ;
int V_32 ;
if ( V_4 >= V_44 )
return - V_45 ;
V_32 = F_17 ( V_19 , F_34 ( V_46 ) , V_4 ) ;
if ( V_32 < 0 )
return V_32 ;
switch ( V_41 -> V_47 ) {
case V_48 :
snprintf ( V_27 , V_43 , L_2 , V_19 -> V_27 , V_4 ) ;
break;
case V_49 :
snprintf ( V_27 , V_43 , L_3 , V_4 ) ;
break;
case V_50 :
snprintf ( V_27 , V_43 , L_4 , V_19 -> V_27 , V_4 ) ;
break;
case V_51 :
default:
snprintf ( V_27 , V_43 , L_5 , V_4 ) ;
}
V_38 = F_35 ( sizeof( struct V_17 ) , V_27 ,
V_52 , V_53 ) ;
if ( V_38 == NULL )
return - V_13 ;
F_36 ( V_38 , V_39 ) ;
V_38 -> V_54 = V_19 -> V_54 ;
V_18 = V_17 ( V_38 ) ;
V_18 -> V_3 = F_34 ( V_46 ) ;
V_18 -> V_4 = V_4 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_55 = NULL ;
V_18 -> V_23 = V_56 ;
V_38 -> V_57 = & V_58 ;
V_32 = F_20 ( V_38 ) ;
if ( V_32 < 0 )
goto V_59;
return 0 ;
V_59:
if ( V_38 -> V_60 == V_61 )
F_37 ( V_38 ) ;
return V_32 ;
}
static void F_38 ( struct V_5 * V_14 ,
struct V_5 * V_62 )
{
struct V_17 * V_18 = V_17 ( V_62 ) ;
if ( F_39 ( V_18 -> V_63 , V_14 -> V_64 ) )
return;
if ( F_40 ( V_62 , V_14 ) )
goto V_65;
if ( ! F_39 ( V_62 -> V_64 , V_18 -> V_63 ) &&
F_39 ( V_62 -> V_64 , V_14 -> V_64 ) )
F_41 ( V_14 , V_62 -> V_64 ) ;
if ( F_39 ( V_62 -> V_64 , V_18 -> V_63 ) &&
! F_39 ( V_62 -> V_64 , V_14 -> V_64 ) )
F_42 ( V_14 , V_62 -> V_64 ) ;
V_65:
F_43 ( V_18 -> V_63 , V_14 -> V_64 ) ;
}
static void F_44 ( struct V_5 * V_14 ,
struct V_5 * V_62 )
{
struct V_17 * V_18 = V_17 ( V_62 ) ;
V_62 -> V_66 = V_14 -> V_66 ;
V_62 -> V_67 = V_14 -> V_67 ;
if ( F_45 ( V_14 -> V_28 , V_18 -> V_3 ) )
V_62 -> V_68 = V_14 -> V_68 ;
else
V_62 -> V_68 = V_14 -> V_68 + V_69 ;
#if F_46 ( V_70 )
V_62 -> V_71 = V_14 -> V_71 ;
#endif
F_47 ( V_62 ) ;
}
static int F_48 ( struct V_5 * V_14 , unsigned long V_72 )
{
int V_32 = 0 ;
switch ( V_72 ) {
case V_73 :
F_49 ( V_14 ) ;
V_32 = F_50 ( V_14 ) ;
break;
case V_74 :
V_32 = F_50 ( V_14 ) ;
break;
case V_75 :
F_49 ( V_14 ) ;
break;
}
return V_32 ;
}
static int F_51 ( struct V_76 * V_77 , unsigned long V_72 ,
void * V_78 )
{
struct V_5 * V_14 = F_52 ( V_78 ) ;
struct V_1 * V_21 ;
struct V_20 * V_20 ;
int V_79 , V_80 ;
struct V_5 * V_62 ;
struct V_17 * V_18 ;
bool V_81 = false ;
F_53 ( V_82 ) ;
if ( F_54 ( V_14 ) ) {
int V_32 = F_48 ( V_14 , V_72 ) ;
if ( V_32 )
return F_55 ( V_32 ) ;
}
if ( ( V_72 == V_83 ) &&
( V_14 -> V_28 & V_84 ) ) {
F_18 ( L_6 ,
V_14 -> V_27 ) ;
F_21 ( V_14 , F_34 ( V_46 ) , 0 ) ;
}
V_20 = F_6 ( V_14 -> V_20 ) ;
if ( ! V_20 )
goto V_65;
V_21 = & V_20 -> V_21 ;
switch ( V_72 ) {
case V_85 :
F_56 (grp, i, vlandev)
F_28 ( V_14 , V_62 ) ;
break;
case V_86 :
F_56 (grp, i, vlandev) {
V_80 = V_62 -> V_23 ;
if ( ! ( V_80 & V_87 ) )
continue;
F_38 ( V_14 , V_62 ) ;
}
break;
case V_88 :
F_56 (grp, i, vlandev) {
if ( V_62 -> V_54 <= V_14 -> V_54 )
continue;
F_57 ( V_62 , V_14 -> V_54 ) ;
}
break;
case V_89 :
F_56 (grp, i, vlandev)
F_44 ( V_14 , V_62 ) ;
break;
case V_90 : {
struct V_5 * V_91 ;
F_53 ( V_92 ) ;
if ( V_14 -> V_28 & V_84 )
F_15 ( V_14 , F_34 ( V_46 ) , 0 ) ;
F_56 (grp, i, vlandev) {
V_80 = V_62 -> V_23 ;
if ( ! ( V_80 & V_87 ) )
continue;
V_18 = V_17 ( V_62 ) ;
if ( ! ( V_18 -> V_23 & V_93 ) )
F_58 ( & V_62 -> V_92 , & V_92 ) ;
}
F_59 ( & V_92 , false ) ;
F_60 (vlandev, tmp, &close_list, close_list) {
F_28 ( V_14 , V_62 ) ;
F_61 ( & V_62 -> V_92 ) ;
}
F_62 ( & V_92 ) ;
break;
}
case V_83 :
F_56 (grp, i, vlandev) {
V_80 = F_63 ( V_62 ) ;
if ( V_80 & V_87 )
continue;
V_18 = V_17 ( V_62 ) ;
if ( ! ( V_18 -> V_23 & V_93 ) )
F_64 ( V_62 , V_80 | V_87 ) ;
F_28 ( V_14 , V_62 ) ;
}
break;
case V_75 :
if ( V_14 -> V_60 != V_94 )
break;
F_56 (grp, i, vlandev) {
if ( V_20 -> V_95 == 1 )
V_81 = true ;
F_5 ( V_62 , & V_82 ) ;
if ( V_81 )
break;
}
F_65 ( & V_82 ) ;
break;
case V_96 :
if ( F_66 ( V_14 ) )
return V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
F_56 (grp, i, vlandev)
F_67 ( V_72 , V_62 ) ;
break;
}
V_65:
return V_101 ;
}
static int F_68 ( struct V_39 * V_39 , void T_3 * V_102 )
{
int V_32 ;
struct V_103 args ;
struct V_5 * V_14 = NULL ;
if ( F_69 ( & args , V_102 , sizeof( struct V_103 ) ) )
return - V_104 ;
args . V_105 [ sizeof( args . V_105 ) - 1 ] = 0 ;
args . V_106 . V_107 [ sizeof( args . V_106 . V_107 ) - 1 ] = 0 ;
F_70 () ;
switch ( args . V_108 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_32 = - V_116 ;
V_14 = F_71 ( V_39 , args . V_105 ) ;
if ( ! V_14 )
goto V_65;
V_32 = - V_117 ;
if ( args . V_108 != V_112 && ! F_54 ( V_14 ) )
goto V_65;
}
switch ( args . V_108 ) {
case V_109 :
V_32 = - V_118 ;
if ( ! F_72 ( V_39 -> V_119 , V_120 ) )
break;
F_73 ( V_14 ,
args . V_106 . V_121 ,
args . V_122 ) ;
V_32 = 0 ;
break;
case V_110 :
V_32 = - V_118 ;
if ( ! F_72 ( V_39 -> V_119 , V_120 ) )
break;
V_32 = F_74 ( V_14 ,
args . V_106 . V_121 ,
args . V_122 ) ;
break;
case V_111 :
V_32 = - V_118 ;
if ( ! F_72 ( V_39 -> V_119 , V_120 ) )
break;
V_32 = F_75 ( V_14 ,
args . V_122 ? args . V_106 . V_123 : 0 ,
args . V_106 . V_123 ) ;
break;
case V_124 :
V_32 = - V_118 ;
if ( ! F_72 ( V_39 -> V_119 , V_120 ) )
break;
if ( args . V_106 . V_47 < V_125 ) {
struct V_40 * V_41 ;
V_41 = F_33 ( V_39 , V_42 ) ;
V_41 -> V_47 = args . V_106 . V_47 ;
V_32 = 0 ;
} else {
V_32 = - V_117 ;
}
break;
case V_112 :
V_32 = - V_118 ;
if ( ! F_72 ( V_39 -> V_119 , V_120 ) )
break;
V_32 = F_31 ( V_14 , args . V_106 . V_126 ) ;
break;
case V_113 :
V_32 = - V_118 ;
if ( ! F_72 ( V_39 -> V_119 , V_120 ) )
break;
F_5 ( V_14 , NULL ) ;
V_32 = 0 ;
break;
case V_114 :
V_32 = 0 ;
F_76 ( V_14 , args . V_106 . V_107 ) ;
if ( F_77 ( V_102 , & args ,
sizeof( struct V_103 ) ) )
V_32 = - V_104 ;
break;
case V_115 :
V_32 = 0 ;
args . V_106 . V_126 = F_78 ( V_14 ) ;
if ( F_77 ( V_102 , & args ,
sizeof( struct V_103 ) ) )
V_32 = - V_104 ;
break;
default:
V_32 = - V_30 ;
break;
}
V_65:
F_79 () ;
return V_32 ;
}
static struct V_127 * * F_80 ( struct V_127 * * V_16 ,
struct V_127 * V_128 )
{
struct V_127 * V_129 , * * V_130 = NULL ;
struct V_131 * V_132 ;
unsigned int V_133 , V_134 ;
const struct V_135 * V_136 ;
T_1 type ;
int V_137 = 1 ;
V_134 = F_81 ( V_128 ) ;
V_133 = V_134 + sizeof( * V_132 ) ;
V_132 = F_82 ( V_128 , V_134 ) ;
if ( F_83 ( V_128 , V_133 ) ) {
V_132 = F_84 ( V_128 , V_133 , V_134 ) ;
if ( F_85 ( ! V_132 ) )
goto V_65;
}
type = V_132 -> V_138 ;
F_86 () ;
V_136 = F_87 ( type ) ;
if ( ! V_136 )
goto V_139;
V_137 = 0 ;
for ( V_129 = * V_16 ; V_129 ; V_129 = V_129 -> V_140 ) {
struct V_131 * V_141 ;
if ( ! F_88 ( V_129 ) -> V_142 )
continue;
V_141 = (struct V_131 * ) ( V_129 -> V_143 + V_134 ) ;
if ( F_89 ( V_132 , V_141 ) )
F_88 ( V_129 ) -> V_142 = 0 ;
}
F_90 ( V_128 , sizeof( * V_132 ) ) ;
F_91 ( V_128 , V_132 , sizeof( * V_132 ) ) ;
V_130 = F_92 ( V_136 -> V_144 . V_145 , V_16 , V_128 ) ;
V_139:
F_93 () ;
V_65:
F_88 ( V_128 ) -> V_137 |= V_137 ;
return V_130 ;
}
static int F_94 ( struct V_127 * V_128 , int V_146 )
{
struct V_131 * V_132 = (struct V_131 * ) ( V_128 -> V_143 + V_146 ) ;
T_1 type = V_132 -> V_138 ;
struct V_135 * V_136 ;
int V_32 = - V_147 ;
F_86 () ;
V_136 = F_95 ( type ) ;
if ( V_136 )
V_32 = V_136 -> V_144 . V_148 ( V_128 , V_146 + sizeof( * V_132 ) ) ;
F_93 () ;
return V_32 ;
}
static int T_4 F_96 ( struct V_39 * V_39 )
{
struct V_40 * V_41 = F_33 ( V_39 , V_42 ) ;
int V_32 ;
V_41 -> V_47 = V_50 ;
V_32 = F_97 ( V_39 ) ;
return V_32 ;
}
static void T_5 F_98 ( struct V_39 * V_39 )
{
F_99 ( V_39 ) ;
}
static int T_6 F_100 ( void )
{
int V_32 ;
unsigned int V_79 ;
F_18 ( L_7 , V_149 , V_150 ) ;
V_32 = F_101 ( & V_151 ) ;
if ( V_32 < 0 )
goto V_152;
V_32 = F_102 ( & V_153 ) ;
if ( V_32 < 0 )
goto V_154;
V_32 = F_103 () ;
if ( V_32 < 0 )
goto V_155;
V_32 = F_104 () ;
if ( V_32 < 0 )
goto V_156;
V_32 = F_105 () ;
if ( V_32 < 0 )
goto V_157;
for ( V_79 = 0 ; V_79 < F_106 ( V_158 ) ; V_79 ++ )
F_107 ( & V_158 [ V_79 ] ) ;
F_108 ( F_68 ) ;
return 0 ;
V_157:
F_109 () ;
V_156:
F_110 () ;
V_155:
F_111 ( & V_153 ) ;
V_154:
F_112 ( & V_151 ) ;
V_152:
return V_32 ;
}
static void T_7 F_113 ( void )
{
unsigned int V_79 ;
F_108 ( NULL ) ;
for ( V_79 = 0 ; V_79 < F_106 ( V_158 ) ; V_79 ++ )
F_114 ( & V_158 [ V_79 ] ) ;
F_115 () ;
F_111 ( & V_153 ) ;
F_112 ( & V_151 ) ;
F_116 () ;
F_109 () ;
F_110 () ;
}
