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
F_37 ( V_38 ) ;
return V_32 ;
}
static void F_38 ( struct V_5 * V_14 ,
struct V_5 * V_60 )
{
struct V_17 * V_18 = V_17 ( V_60 ) ;
if ( F_39 ( V_18 -> V_61 , V_14 -> V_62 ) )
return;
if ( F_40 ( V_60 , V_14 ) )
goto V_63;
if ( ! F_39 ( V_60 -> V_62 , V_18 -> V_61 ) &&
F_39 ( V_60 -> V_62 , V_14 -> V_62 ) )
F_41 ( V_14 , V_60 -> V_62 ) ;
if ( F_39 ( V_60 -> V_62 , V_18 -> V_61 ) &&
! F_39 ( V_60 -> V_62 , V_14 -> V_62 ) )
F_42 ( V_14 , V_60 -> V_62 ) ;
V_63:
F_43 ( V_18 -> V_61 , V_14 -> V_62 ) ;
}
static void F_44 ( struct V_5 * V_14 ,
struct V_5 * V_60 )
{
struct V_17 * V_18 = V_17 ( V_60 ) ;
V_60 -> V_64 = V_14 -> V_64 ;
V_60 -> V_65 = V_14 -> V_65 ;
if ( F_45 ( V_14 -> V_28 , V_18 -> V_3 ) )
V_60 -> V_66 = V_14 -> V_66 ;
else
V_60 -> V_66 = V_14 -> V_66 + V_67 ;
#if F_46 ( V_68 )
V_60 -> V_69 = V_14 -> V_69 ;
#endif
F_47 ( V_60 ) ;
}
static int F_48 ( struct V_5 * V_14 , unsigned long V_70 )
{
int V_32 = 0 ;
switch ( V_70 ) {
case V_71 :
F_49 ( V_14 ) ;
V_32 = F_50 ( V_14 ) ;
break;
case V_72 :
V_32 = F_50 ( V_14 ) ;
break;
case V_73 :
F_49 ( V_14 ) ;
break;
}
return V_32 ;
}
static int F_51 ( struct V_74 * V_75 , unsigned long V_70 ,
void * V_76 )
{
struct V_5 * V_14 = F_52 ( V_76 ) ;
struct V_1 * V_21 ;
struct V_20 * V_20 ;
int V_77 , V_78 ;
struct V_5 * V_60 ;
struct V_17 * V_18 ;
bool V_79 = false ;
F_53 ( V_80 ) ;
if ( F_54 ( V_14 ) ) {
int V_32 = F_48 ( V_14 , V_70 ) ;
if ( V_32 )
return F_55 ( V_32 ) ;
}
if ( ( V_70 == V_81 ) &&
( V_14 -> V_28 & V_82 ) ) {
F_18 ( L_6 ,
V_14 -> V_27 ) ;
F_21 ( V_14 , F_34 ( V_46 ) , 0 ) ;
}
V_20 = F_6 ( V_14 -> V_20 ) ;
if ( ! V_20 )
goto V_63;
V_21 = & V_20 -> V_21 ;
switch ( V_70 ) {
case V_83 :
F_56 (grp, i, vlandev)
F_28 ( V_14 , V_60 ) ;
break;
case V_84 :
F_56 (grp, i, vlandev) {
V_78 = V_60 -> V_23 ;
if ( ! ( V_78 & V_85 ) )
continue;
F_38 ( V_14 , V_60 ) ;
}
break;
case V_86 :
F_56 (grp, i, vlandev) {
if ( V_60 -> V_54 <= V_14 -> V_54 )
continue;
F_57 ( V_60 , V_14 -> V_54 ) ;
}
break;
case V_87 :
F_56 (grp, i, vlandev)
F_44 ( V_14 , V_60 ) ;
break;
case V_88 : {
struct V_5 * V_89 ;
F_53 ( V_90 ) ;
if ( V_14 -> V_28 & V_82 )
F_15 ( V_14 , F_34 ( V_46 ) , 0 ) ;
F_56 (grp, i, vlandev) {
V_78 = V_60 -> V_23 ;
if ( ! ( V_78 & V_85 ) )
continue;
V_18 = V_17 ( V_60 ) ;
if ( ! ( V_18 -> V_23 & V_91 ) )
F_58 ( & V_60 -> V_90 , & V_90 ) ;
}
F_59 ( & V_90 , false ) ;
F_60 (vlandev, tmp, &close_list, close_list) {
F_28 ( V_14 , V_60 ) ;
F_61 ( & V_60 -> V_90 ) ;
}
F_62 ( & V_90 ) ;
break;
}
case V_81 :
F_56 (grp, i, vlandev) {
V_78 = F_63 ( V_60 ) ;
if ( V_78 & V_85 )
continue;
V_18 = V_17 ( V_60 ) ;
if ( ! ( V_18 -> V_23 & V_91 ) )
F_64 ( V_60 , V_78 | V_85 ) ;
F_28 ( V_14 , V_60 ) ;
}
break;
case V_73 :
if ( V_14 -> V_92 != V_93 )
break;
F_56 (grp, i, vlandev) {
if ( V_20 -> V_94 == 1 )
V_79 = true ;
F_5 ( V_60 , & V_80 ) ;
if ( V_79 )
break;
}
F_65 ( & V_80 ) ;
break;
case V_95 :
if ( F_66 ( V_14 ) )
return V_96 ;
break;
case V_97 :
case V_98 :
case V_99 :
F_56 (grp, i, vlandev)
F_67 ( V_70 , V_60 ) ;
break;
}
V_63:
return V_100 ;
}
static int F_68 ( struct V_39 * V_39 , void T_3 * V_101 )
{
int V_32 ;
struct V_102 args ;
struct V_5 * V_14 = NULL ;
if ( F_69 ( & args , V_101 , sizeof( struct V_102 ) ) )
return - V_103 ;
args . V_104 [ 23 ] = 0 ;
args . V_105 . V_106 [ 23 ] = 0 ;
F_70 () ;
switch ( args . V_107 ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_32 = - V_115 ;
V_14 = F_71 ( V_39 , args . V_104 ) ;
if ( ! V_14 )
goto V_63;
V_32 = - V_116 ;
if ( args . V_107 != V_111 && ! F_54 ( V_14 ) )
goto V_63;
}
switch ( args . V_107 ) {
case V_108 :
V_32 = - V_117 ;
if ( ! F_72 ( V_39 -> V_118 , V_119 ) )
break;
F_73 ( V_14 ,
args . V_105 . V_120 ,
args . V_121 ) ;
V_32 = 0 ;
break;
case V_109 :
V_32 = - V_117 ;
if ( ! F_72 ( V_39 -> V_118 , V_119 ) )
break;
V_32 = F_74 ( V_14 ,
args . V_105 . V_120 ,
args . V_121 ) ;
break;
case V_110 :
V_32 = - V_117 ;
if ( ! F_72 ( V_39 -> V_118 , V_119 ) )
break;
V_32 = F_75 ( V_14 ,
args . V_121 ? args . V_105 . V_122 : 0 ,
args . V_105 . V_122 ) ;
break;
case V_123 :
V_32 = - V_117 ;
if ( ! F_72 ( V_39 -> V_118 , V_119 ) )
break;
if ( ( args . V_105 . V_47 >= 0 ) &&
( args . V_105 . V_47 < V_124 ) ) {
struct V_40 * V_41 ;
V_41 = F_33 ( V_39 , V_42 ) ;
V_41 -> V_47 = args . V_105 . V_47 ;
V_32 = 0 ;
} else {
V_32 = - V_116 ;
}
break;
case V_111 :
V_32 = - V_117 ;
if ( ! F_72 ( V_39 -> V_118 , V_119 ) )
break;
V_32 = F_31 ( V_14 , args . V_105 . V_125 ) ;
break;
case V_112 :
V_32 = - V_117 ;
if ( ! F_72 ( V_39 -> V_118 , V_119 ) )
break;
F_5 ( V_14 , NULL ) ;
V_32 = 0 ;
break;
case V_113 :
V_32 = 0 ;
F_76 ( V_14 , args . V_105 . V_106 ) ;
if ( F_77 ( V_101 , & args ,
sizeof( struct V_102 ) ) )
V_32 = - V_103 ;
break;
case V_114 :
V_32 = 0 ;
args . V_105 . V_125 = F_78 ( V_14 ) ;
if ( F_77 ( V_101 , & args ,
sizeof( struct V_102 ) ) )
V_32 = - V_103 ;
break;
default:
V_32 = - V_30 ;
break;
}
V_63:
F_79 () ;
return V_32 ;
}
static struct V_126 * * F_80 ( struct V_126 * * V_16 ,
struct V_126 * V_127 )
{
struct V_126 * V_128 , * * V_129 = NULL ;
struct V_130 * V_131 ;
unsigned int V_132 , V_133 ;
const struct V_134 * V_135 ;
T_1 type ;
int V_136 = 1 ;
V_133 = F_81 ( V_127 ) ;
V_132 = V_133 + sizeof( * V_131 ) ;
V_131 = F_82 ( V_127 , V_133 ) ;
if ( F_83 ( V_127 , V_132 ) ) {
V_131 = F_84 ( V_127 , V_132 , V_133 ) ;
if ( F_85 ( ! V_131 ) )
goto V_63;
}
type = V_131 -> V_137 ;
F_86 () ;
V_135 = F_87 ( type ) ;
if ( ! V_135 )
goto V_138;
V_136 = 0 ;
for ( V_128 = * V_16 ; V_128 ; V_128 = V_128 -> V_139 ) {
struct V_130 * V_140 ;
if ( ! F_88 ( V_128 ) -> V_141 )
continue;
V_140 = (struct V_130 * ) ( V_128 -> V_142 + V_133 ) ;
if ( F_89 ( V_131 , V_140 ) )
F_88 ( V_128 ) -> V_141 = 0 ;
}
F_90 ( V_127 , sizeof( * V_131 ) ) ;
F_91 ( V_127 , V_131 , sizeof( * V_131 ) ) ;
V_129 = F_92 ( V_135 -> V_143 . V_144 , V_16 , V_127 ) ;
V_138:
F_93 () ;
V_63:
F_88 ( V_127 ) -> V_136 |= V_136 ;
return V_129 ;
}
static int F_94 ( struct V_126 * V_127 , int V_145 )
{
struct V_130 * V_131 = (struct V_130 * ) ( V_127 -> V_142 + V_145 ) ;
T_1 type = V_131 -> V_137 ;
struct V_134 * V_135 ;
int V_32 = - V_146 ;
F_86 () ;
V_135 = F_95 ( type ) ;
if ( V_135 )
V_32 = V_135 -> V_143 . V_147 ( V_127 , V_145 + sizeof( * V_131 ) ) ;
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
unsigned int V_77 ;
F_18 ( L_7 , V_148 , V_149 ) ;
V_32 = F_101 ( & V_150 ) ;
if ( V_32 < 0 )
goto V_151;
V_32 = F_102 ( & V_152 ) ;
if ( V_32 < 0 )
goto V_153;
V_32 = F_103 () ;
if ( V_32 < 0 )
goto V_154;
V_32 = F_104 () ;
if ( V_32 < 0 )
goto V_155;
V_32 = F_105 () ;
if ( V_32 < 0 )
goto V_156;
for ( V_77 = 0 ; V_77 < F_106 ( V_157 ) ; V_77 ++ )
F_107 ( & V_157 [ V_77 ] ) ;
F_108 ( F_68 ) ;
return 0 ;
V_156:
F_109 () ;
V_155:
F_110 () ;
V_154:
F_111 ( & V_152 ) ;
V_153:
F_112 ( & V_150 ) ;
V_151:
return V_32 ;
}
static void T_7 F_113 ( void )
{
unsigned int V_77 ;
F_108 ( NULL ) ;
for ( V_77 = 0 ; V_77 < F_106 ( V_157 ) ; V_77 ++ )
F_114 ( & V_157 [ V_77 ] ) ;
F_115 () ;
F_111 ( & V_152 ) ;
F_112 ( & V_150 ) ;
F_116 () ;
F_109 () ;
F_110 () ;
}
