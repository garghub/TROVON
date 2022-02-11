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
V_39 -> V_56 |= ( V_19 -> V_56 & V_57 ) ;
V_18 = V_17 ( V_39 ) ;
V_18 -> V_3 = F_34 ( V_47 ) ;
V_18 -> V_4 = V_4 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_58 = NULL ;
V_18 -> V_23 = V_59 ;
V_39 -> V_60 = & V_61 ;
V_32 = F_20 ( V_39 ) ;
if ( V_32 < 0 )
goto V_62;
return 0 ;
V_62:
F_37 ( V_39 ) ;
return V_32 ;
}
static void F_38 ( struct V_5 * V_14 ,
struct V_5 * V_63 )
{
struct V_17 * V_18 = V_17 ( V_63 ) ;
if ( F_39 ( V_18 -> V_64 , V_14 -> V_65 ) )
return;
if ( ! F_39 ( V_63 -> V_65 , V_18 -> V_64 ) &&
F_39 ( V_63 -> V_65 , V_14 -> V_65 ) )
F_40 ( V_14 , V_63 -> V_65 ) ;
if ( F_39 ( V_63 -> V_65 , V_18 -> V_64 ) &&
! F_39 ( V_63 -> V_65 , V_14 -> V_65 ) )
F_41 ( V_14 , V_63 -> V_65 ) ;
F_42 ( V_18 -> V_64 , V_14 -> V_65 ) ;
}
static void F_43 ( struct V_5 * V_14 ,
struct V_5 * V_63 )
{
struct V_17 * V_18 = V_17 ( V_63 ) ;
V_63 -> V_66 = V_14 -> V_66 ;
if ( F_44 ( V_14 -> V_28 , V_18 -> V_3 ) )
V_63 -> V_67 = V_14 -> V_67 ;
else
V_63 -> V_67 = V_14 -> V_67 + V_68 ;
#if F_45 ( V_69 )
V_63 -> V_70 = V_14 -> V_70 ;
#endif
F_46 ( V_63 ) ;
}
static int F_47 ( struct V_5 * V_14 , unsigned long V_71 )
{
int V_32 = 0 ;
switch ( V_71 ) {
case V_72 :
F_48 ( V_14 ) ;
V_32 = F_49 ( V_14 ) ;
break;
case V_73 :
V_32 = F_49 ( V_14 ) ;
break;
case V_74 :
F_48 ( V_14 ) ;
break;
}
return V_32 ;
}
static int F_50 ( struct V_75 * V_76 , unsigned long V_71 ,
void * V_77 )
{
struct V_5 * V_14 = F_51 ( V_77 ) ;
struct V_1 * V_21 ;
struct V_20 * V_20 ;
int V_78 , V_79 ;
struct V_5 * V_63 ;
struct V_17 * V_18 ;
bool V_80 = false ;
F_52 ( V_81 ) ;
if ( V_37 ( V_14 ) ) {
int V_32 = F_47 ( V_14 , V_71 ) ;
if ( V_32 )
return F_53 ( V_32 ) ;
}
if ( ( V_71 == V_82 ) &&
( V_14 -> V_28 & V_83 ) ) {
F_18 ( L_6 ,
V_14 -> V_27 ) ;
F_21 ( V_14 , F_34 ( V_47 ) , 0 ) ;
}
V_20 = F_6 ( V_14 -> V_20 ) ;
if ( ! V_20 )
goto V_84;
V_21 = & V_20 -> V_21 ;
switch ( V_71 ) {
case V_85 :
F_54 (grp, i, vlandev)
F_28 ( V_14 , V_63 ) ;
break;
case V_86 :
F_54 (grp, i, vlandev) {
V_79 = V_63 -> V_23 ;
if ( ! ( V_79 & V_87 ) )
continue;
F_38 ( V_14 , V_63 ) ;
}
break;
case V_88 :
F_54 (grp, i, vlandev) {
if ( V_63 -> V_55 <= V_14 -> V_55 )
continue;
F_55 ( V_63 , V_14 -> V_55 ) ;
}
break;
case V_89 :
F_54 (grp, i, vlandev)
F_43 ( V_14 , V_63 ) ;
break;
case V_90 : {
struct V_5 * V_91 ;
F_52 ( V_92 ) ;
if ( V_14 -> V_28 & V_83 )
F_15 ( V_14 , F_34 ( V_47 ) , 0 ) ;
F_54 (grp, i, vlandev) {
V_79 = V_63 -> V_23 ;
if ( ! ( V_79 & V_87 ) )
continue;
V_18 = V_17 ( V_63 ) ;
if ( ! ( V_18 -> V_23 & V_93 ) )
F_56 ( & V_63 -> V_92 , & V_92 ) ;
}
F_57 ( & V_92 , false ) ;
F_58 (vlandev, tmp, &close_list, close_list) {
F_28 ( V_14 , V_63 ) ;
F_59 ( & V_63 -> V_92 ) ;
}
F_60 ( & V_92 ) ;
break;
}
case V_82 :
F_54 (grp, i, vlandev) {
V_79 = F_61 ( V_63 ) ;
if ( V_79 & V_87 )
continue;
V_18 = V_17 ( V_63 ) ;
if ( ! ( V_18 -> V_23 & V_93 ) )
F_62 ( V_63 , V_79 | V_87 ) ;
F_28 ( V_14 , V_63 ) ;
}
break;
case V_74 :
if ( V_14 -> V_94 != V_95 )
break;
F_54 (grp, i, vlandev) {
if ( V_20 -> V_96 == 1 )
V_80 = true ;
F_5 ( V_63 , & V_81 ) ;
if ( V_80 )
break;
}
F_63 ( & V_81 ) ;
break;
case V_97 :
if ( F_64 ( V_14 ) )
return V_98 ;
break;
case V_99 :
case V_100 :
case V_101 :
F_54 (grp, i, vlandev)
F_65 ( V_71 , V_63 ) ;
break;
}
V_84:
return V_102 ;
}
static int F_66 ( struct V_40 * V_40 , void T_3 * V_103 )
{
int V_32 ;
struct V_104 args ;
struct V_5 * V_14 = NULL ;
if ( F_67 ( & args , V_103 , sizeof( struct V_104 ) ) )
return - V_105 ;
args . V_106 [ 23 ] = 0 ;
args . V_107 . V_108 [ 23 ] = 0 ;
F_68 () ;
switch ( args . V_109 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_32 = - V_117 ;
V_14 = F_69 ( V_40 , args . V_106 ) ;
if ( ! V_14 )
goto V_84;
V_32 = - V_118 ;
if ( args . V_109 != V_113 && ! V_37 ( V_14 ) )
goto V_84;
}
switch ( args . V_109 ) {
case V_110 :
V_32 = - V_119 ;
if ( ! F_70 ( V_40 -> V_120 , V_121 ) )
break;
F_71 ( V_14 ,
args . V_107 . V_122 ,
args . V_123 ) ;
V_32 = 0 ;
break;
case V_111 :
V_32 = - V_119 ;
if ( ! F_70 ( V_40 -> V_120 , V_121 ) )
break;
V_32 = F_72 ( V_14 ,
args . V_107 . V_122 ,
args . V_123 ) ;
break;
case V_112 :
V_32 = - V_119 ;
if ( ! F_70 ( V_40 -> V_120 , V_121 ) )
break;
V_32 = F_73 ( V_14 ,
args . V_123 ? args . V_107 . V_124 : 0 ,
args . V_107 . V_124 ) ;
break;
case V_125 :
V_32 = - V_119 ;
if ( ! F_70 ( V_40 -> V_120 , V_121 ) )
break;
if ( ( args . V_107 . V_48 >= 0 ) &&
( args . V_107 . V_48 < V_126 ) ) {
struct V_41 * V_42 ;
V_42 = F_33 ( V_40 , V_43 ) ;
V_42 -> V_48 = args . V_107 . V_48 ;
V_32 = 0 ;
} else {
V_32 = - V_118 ;
}
break;
case V_113 :
V_32 = - V_119 ;
if ( ! F_70 ( V_40 -> V_120 , V_121 ) )
break;
V_32 = F_31 ( V_14 , args . V_107 . V_127 ) ;
break;
case V_114 :
V_32 = - V_119 ;
if ( ! F_70 ( V_40 -> V_120 , V_121 ) )
break;
F_5 ( V_14 , NULL ) ;
V_32 = 0 ;
break;
case V_115 :
V_32 = 0 ;
F_74 ( V_14 , args . V_107 . V_108 ) ;
if ( F_75 ( V_103 , & args ,
sizeof( struct V_104 ) ) )
V_32 = - V_105 ;
break;
case V_116 :
V_32 = 0 ;
args . V_107 . V_127 = F_76 ( V_14 ) ;
if ( F_75 ( V_103 , & args ,
sizeof( struct V_104 ) ) )
V_32 = - V_105 ;
break;
default:
V_32 = - V_30 ;
break;
}
V_84:
F_77 () ;
return V_32 ;
}
static struct V_128 * * F_78 ( struct V_128 * * V_16 ,
struct V_128 * V_129 )
{
struct V_128 * V_130 , * * V_131 = NULL ;
struct V_132 * V_133 ;
unsigned int V_134 , V_135 ;
const struct V_136 * V_137 ;
T_1 type ;
int V_138 = 1 ;
V_135 = F_79 ( V_129 ) ;
V_134 = V_135 + sizeof( * V_133 ) ;
V_133 = F_80 ( V_129 , V_135 ) ;
if ( F_81 ( V_129 , V_134 ) ) {
V_133 = F_82 ( V_129 , V_134 , V_135 ) ;
if ( F_83 ( ! V_133 ) )
goto V_84;
}
type = V_133 -> V_139 ;
F_84 () ;
V_137 = F_85 ( type ) ;
if ( ! V_137 )
goto V_140;
V_138 = 0 ;
for ( V_130 = * V_16 ; V_130 ; V_130 = V_130 -> V_141 ) {
struct V_132 * V_142 ;
if ( ! F_86 ( V_130 ) -> V_143 )
continue;
V_142 = (struct V_132 * ) ( V_130 -> V_144 + V_135 ) ;
if ( F_87 ( V_133 , V_142 ) )
F_86 ( V_130 ) -> V_143 = 0 ;
}
F_88 ( V_129 , sizeof( * V_133 ) ) ;
F_89 ( V_129 , V_133 , sizeof( * V_133 ) ) ;
V_131 = V_137 -> V_145 . V_146 ( V_16 , V_129 ) ;
V_140:
F_90 () ;
V_84:
F_86 ( V_129 ) -> V_138 |= V_138 ;
return V_131 ;
}
static int F_91 ( struct V_128 * V_129 , int V_147 )
{
struct V_132 * V_133 = (struct V_132 * ) ( V_129 -> V_144 + V_147 ) ;
T_1 type = V_133 -> V_139 ;
struct V_136 * V_137 ;
int V_32 = - V_148 ;
F_84 () ;
V_137 = F_92 ( type ) ;
if ( V_137 )
V_32 = V_137 -> V_145 . V_149 ( V_129 , V_147 + sizeof( * V_133 ) ) ;
F_90 () ;
return V_32 ;
}
static int T_4 F_93 ( struct V_40 * V_40 )
{
struct V_41 * V_42 = F_33 ( V_40 , V_43 ) ;
int V_32 ;
V_42 -> V_48 = V_51 ;
V_32 = F_94 ( V_40 ) ;
return V_32 ;
}
static void T_5 F_95 ( struct V_40 * V_40 )
{
F_96 ( V_40 ) ;
}
static int T_6 F_97 ( void )
{
int V_32 ;
unsigned int V_78 ;
F_18 ( L_7 , V_150 , V_151 ) ;
V_32 = F_98 ( & V_152 ) ;
if ( V_32 < 0 )
goto V_153;
V_32 = F_99 ( & V_154 ) ;
if ( V_32 < 0 )
goto V_155;
V_32 = F_100 () ;
if ( V_32 < 0 )
goto V_156;
V_32 = F_101 () ;
if ( V_32 < 0 )
goto V_157;
V_32 = F_102 () ;
if ( V_32 < 0 )
goto V_158;
for ( V_78 = 0 ; V_78 < F_103 ( V_159 ) ; V_78 ++ )
F_104 ( & V_159 [ V_78 ] ) ;
F_105 ( F_66 ) ;
return 0 ;
V_158:
F_106 () ;
V_157:
F_107 () ;
V_156:
F_108 ( & V_154 ) ;
V_155:
F_109 ( & V_152 ) ;
V_153:
return V_32 ;
}
static void T_7 F_110 ( void )
{
unsigned int V_78 ;
F_105 ( NULL ) ;
for ( V_78 = 0 ; V_78 < F_103 ( V_159 ) ; V_78 ++ )
F_111 ( & V_159 [ V_78 ] ) ;
F_112 () ;
F_108 ( & V_154 ) ;
F_109 ( & V_152 ) ;
F_113 () ;
F_106 () ;
F_107 () ;
}
