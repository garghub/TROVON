static
enum V_1 F_1 ( enum V_2 type )
{
switch ( type ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
default:
F_2 ( L_1 ) ;
return V_7 ;
}
}
static
int F_3 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_9 -> V_14 -> V_15 . V_16 ;
int V_17 = 0 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
T_1 V_19 = V_13 -> V_20 . V_21 [ V_17 ] ;
T_2 V_22 ;
if ( ! ( V_9 -> V_23 . V_24 & F_4 ( V_19 ) ) )
V_19 = 0 ;
V_22 = F_5 ( V_9 -> V_25 . V_22 [ V_19 ] ) ;
V_11 -> V_26 . V_27 [ V_17 ] . V_19 = V_19 ;
V_11 -> V_26 . V_27 [ V_17 ] . V_22 = V_22 ;
if ( V_22 == V_28 ) {
F_6 ( & V_9 -> V_14 -> V_29 -> V_30 , L_2 ,
V_19 , V_9 -> V_31 ) ;
return - V_32 ;
}
}
V_11 -> V_33 = V_9 -> V_34 -> V_33 ;
return 0 ;
}
void
F_7 ( struct V_8 * V_9 , T_3 V_35 , T_1 * V_36 , T_2 V_37 )
{
struct V_38 * V_39 ;
if ( ! V_9 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_9 -> V_14 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_45 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_3 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_45 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
V_35 , V_36 , V_37 ) ;
}
}
F_11 ( & V_40 ) ;
}
void F_12 ( struct V_8 * V_9 )
{
struct V_38 * V_39 ;
struct V_10 V_11 ;
if ( ! V_9 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
F_3 ( V_9 , & V_11 ) ;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_9 -> V_14 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_46 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_4 ) ;
continue;
}
V_39 -> V_41 . V_11 = V_11 ;
V_39 -> V_43 -> V_44 -> V_46 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
& V_11 ) ;
}
}
F_11 ( & V_40 ) ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_38 * V_39 ;
if ( ! V_9 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_34 == V_9 -> V_34 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 || ! V_39 -> V_43 -> V_44 -> V_47 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_5 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_47 ( & V_39 -> V_41 , V_39 -> V_43 ) ;
}
}
F_11 ( & V_40 ) ;
}
static void F_14 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_3 V_17 ;
if ( ! V_49 -> V_51 )
return;
for ( V_17 = 0 ; V_17 < V_51 -> V_52 ; V_17 ++ ) {
struct V_53 * V_42 = V_49 -> V_42 ;
struct V_54 * V_55 ;
T_3 V_56 ;
V_55 = & V_51 -> V_55 [ V_17 ] ;
if ( ! V_55 )
continue;
V_56 = F_15 ( V_55 -> V_57 - 1 ) ;
F_16 ( & V_42 -> V_15 , V_56 , V_58 ) ;
}
F_17 ( V_49 -> V_51 ) ;
V_49 -> V_51 = NULL ;
}
void F_18 ( struct V_8 * V_9 , bool V_59 )
{
struct V_38 * V_39 ;
if ( ! V_9 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_34 == V_9 -> V_34 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 || ! V_39 -> V_43 -> V_44 -> V_60 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_6 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_60 ( & V_39 -> V_41 , V_39 -> V_43 ,
V_59 ) ;
F_14 ( & V_39 -> V_41 ) ;
}
}
F_11 ( & V_40 ) ;
}
void F_19 ( struct V_53 * V_42 , T_3 V_35 )
{
struct V_38 * V_39 ;
if ( ! V_42 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_42 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_61 ) {
F_10 ( & V_42 -> V_29 -> V_30 ,
L_7 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_61 ( & V_39 -> V_41 ,
V_39 -> V_43 , V_35 ) ;
}
}
F_11 ( & V_40 ) ;
}
void F_20 ( struct V_53 * V_42 , T_3 V_62 )
{
struct V_38 * V_39 ;
if ( ! V_42 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_42 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_63 ) {
F_10 ( & V_42 -> V_29 -> V_30 ,
L_8 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_63 ( & V_39 -> V_41 ,
V_39 -> V_43 , V_62 ) ;
}
}
F_11 ( & V_40 ) ;
}
int F_21 ( struct V_53 * V_42 , T_3 V_35 ,
enum V_2 type )
{
struct V_38 * V_39 ;
int V_64 = false ;
if ( ! V_42 )
return false ;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_42 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_65 ||
! ( V_39 -> V_43 -> type == type ) ) {
F_10 ( & V_42 -> V_29 -> V_30 ,
L_9 ) ;
continue;
}
V_64 = V_39 -> V_43 -> V_44 -> V_65 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
V_35 ) ;
break;
}
}
F_11 ( & V_40 ) ;
return V_64 ;
}
struct V_8 * F_22 ( struct V_53 * V_42 ,
enum V_1 type ,
struct V_8 * V_66 )
{
struct V_8 * V_9 ;
int V_17 = 0 ;
if ( V_66 ) {
for ( V_17 = 0 ; V_17 < V_42 -> V_67 ; V_17 ++ ) {
V_9 = V_42 -> V_9 [ V_17 ] ;
if ( V_9 == V_66 )
break;
}
}
for (; V_17 < V_42 -> V_67 ; V_17 ++ ) {
V_9 = V_42 -> V_9 [ V_17 ] ;
if ( V_9 && V_9 -> type == type )
return V_9 ;
}
return NULL ;
}
static
struct V_38 * F_23 ( struct V_53 * V_42 ,
struct V_68 * V_43 )
{
struct V_38 * V_39 ;
struct V_69 * V_70 = NULL ;
struct V_8 * V_9 = V_42 -> V_9 [ V_42 -> V_71 ] ;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( ( V_39 -> V_41 . V_42 == V_42 ) && ( V_39 -> V_43 == V_43 ) ) {
V_39 = NULL ;
goto V_72;
}
}
V_39 = F_24 ( sizeof( * V_39 ) , V_73 ) ;
if ( ! V_39 )
goto V_72;
V_39 -> V_41 . V_42 = ( void * ) V_42 ;
V_39 -> V_41 . V_34 = V_9 -> V_34 ;
V_39 -> V_41 . V_74 = V_42 -> V_29 ;
V_39 -> V_41 . V_75 = V_42 -> V_15 . V_76 ;
V_39 -> V_41 . V_77 = V_78 ;
V_39 -> V_41 . V_79 = V_42 -> V_15 . V_79 ;
V_39 -> V_41 . V_44 = & V_80 ;
V_39 -> V_41 . V_81 . V_82 = V_83 ;
V_39 -> V_41 . V_81 . V_84 = V_85 ;
V_39 -> V_41 . V_81 . V_86 = V_87 ;
V_39 -> V_41 . V_88 = V_42 -> V_15 . V_89 . V_88 ;
V_39 -> V_41 . V_90 = V_42 -> V_15 . V_89 . V_90 ;
V_39 -> V_41 . V_91 = V_42 -> V_15 . V_89 . V_91 ;
F_25 ( V_92 , & V_39 -> V_93 ) ;
if ( F_3 ( V_9 , & V_39 -> V_41 . V_11 ) ) {
F_17 ( V_39 ) ;
V_39 = NULL ;
goto V_72;
}
V_39 -> V_41 . V_94 = V_42 -> V_95 ;
V_39 -> V_41 . V_96 = & V_42 -> V_96 [ V_42 -> V_97 ] ;
V_70 = F_26 ( & V_39 -> V_41 . V_34 -> V_98 . V_99 ,
struct V_69 , V_99 ) ;
if ( V_70 )
F_27 ( V_39 -> V_41 . V_100 , V_70 -> V_101 ) ;
else
F_6 ( & V_42 -> V_29 -> V_30 , L_10 ) ;
V_39 -> V_43 = V_43 ;
F_28 ( & V_39 -> V_99 ) ;
F_29 ( & V_39 -> V_99 , & V_102 ) ;
V_72:
F_11 ( & V_40 ) ;
return V_39 ;
}
static
int F_30 ( struct V_53 * V_42 , struct V_68 * V_43 )
{
struct V_38 * V_39 , * V_103 ;
int V_104 = - V_105 ;
F_8 ( & V_40 ) ;
F_31 (cdev, tmp, &i40e_client_instances, list) {
if ( ( V_39 -> V_41 . V_42 != V_42 ) || ( V_39 -> V_43 != V_43 ) )
continue;
F_32 ( & V_42 -> V_29 -> V_30 , L_11 ,
V_43 -> V_106 , V_42 -> V_15 . V_76 ,
V_42 -> V_15 . V_107 . V_108 , V_42 -> V_15 . V_107 . V_109 ) ;
F_33 ( & V_39 -> V_99 ) ;
F_17 ( V_39 ) ;
V_104 = 0 ;
break;
}
F_11 ( & V_40 ) ;
return V_104 ;
}
void F_34 ( struct V_53 * V_42 )
{
struct V_38 * V_39 ;
struct V_68 * V_43 ;
int V_104 = 0 ;
if ( ! ( V_42 -> V_110 & V_111 ) )
return;
V_42 -> V_110 &= ~ V_111 ;
if ( F_35 ( V_112 , & V_42 -> V_93 ) ||
F_35 ( V_113 , & V_42 -> V_93 ) )
return;
F_8 ( & V_114 ) ;
F_9 (client, &i40e_clients, list) {
if ( ! F_35 ( V_115 , & V_43 -> V_93 ) )
continue;
if ( ! ( V_43 -> V_110 & V_116 ) ) {
if ( F_35 ( V_112 , & V_42 -> V_9 [ V_42 -> V_71 ] -> V_93 ) )
continue;
}
V_39 = F_23 ( V_42 , V_43 ) ;
if ( ! V_39 )
continue;
F_36 ( & V_43 -> V_117 ) ;
F_32 ( & V_42 -> V_29 -> V_30 , L_12 ,
V_43 -> V_106 , V_42 -> V_15 . V_76 ,
V_42 -> V_15 . V_107 . V_108 , V_42 -> V_15 . V_107 . V_109 ) ;
F_36 ( & V_39 -> V_117 ) ;
if ( V_43 -> V_44 && V_43 -> V_44 -> V_47 )
V_104 = V_43 -> V_44 -> V_47 ( & V_39 -> V_41 , V_43 ) ;
F_37 ( & V_39 -> V_117 ) ;
if ( ! V_104 ) {
F_25 ( V_118 , & V_39 -> V_93 ) ;
} else {
F_30 ( V_42 , V_43 ) ;
F_37 ( & V_43 -> V_117 ) ;
continue;
}
}
F_11 ( & V_114 ) ;
}
int F_38 ( struct V_53 * V_42 )
{
struct V_119 * V_49 ;
int V_104 = 0 ;
F_8 ( & V_120 ) ;
F_9 (ldev, &i40e_devices, list) {
if ( V_49 -> V_42 == V_42 ) {
V_104 = - V_121 ;
goto V_72;
}
}
V_49 = F_24 ( sizeof( * V_49 ) , V_73 ) ;
if ( ! V_49 ) {
V_104 = - V_122 ;
goto V_72;
}
V_49 -> V_42 = V_42 ;
F_28 ( & V_49 -> V_99 ) ;
F_29 ( & V_49 -> V_99 , & V_123 ) ;
F_32 ( & V_42 -> V_29 -> V_30 , L_13 ,
V_42 -> V_15 . V_76 , V_42 -> V_15 . V_107 . V_108 , V_42 -> V_15 . V_107 . V_109 ) ;
V_42 -> V_110 |= V_111 ;
F_39 ( V_42 ) ;
V_72:
F_11 ( & V_120 ) ;
return V_104 ;
}
int F_40 ( struct V_53 * V_42 )
{
struct V_119 * V_49 , * V_103 ;
int V_104 = - V_105 ;
F_8 ( & V_120 ) ;
F_31 (ldev, tmp, &i40e_devices, list) {
if ( V_49 -> V_42 == V_42 ) {
F_32 ( & V_42 -> V_29 -> V_30 , L_14 ,
V_42 -> V_15 . V_76 , V_42 -> V_15 . V_107 . V_108 ,
V_42 -> V_15 . V_107 . V_109 ) ;
F_33 ( & V_49 -> V_99 ) ;
F_17 ( V_49 ) ;
V_104 = 0 ;
break;
}
}
F_11 ( & V_120 ) ;
return V_104 ;
}
static int F_41 ( struct V_68 * V_43 )
{
struct V_38 * V_39 , * V_103 ;
struct V_53 * V_42 = NULL ;
int V_104 = 0 ;
F_42 ( V_124 ) ;
F_8 ( & V_40 ) ;
F_31 (cdev, tmp, &i40e_client_instances, list) {
if ( strncmp ( V_39 -> V_43 -> V_106 , V_43 -> V_106 ,
V_125 ) )
continue;
if ( F_35 ( V_118 , & V_39 -> V_93 ) ) {
if ( F_43 ( & V_39 -> V_117 ) > 0 ) {
V_104 = V_126 ;
goto V_72;
}
V_42 = (struct V_53 * ) V_39 -> V_41 . V_42 ;
if ( V_43 -> V_44 && V_43 -> V_44 -> V_60 )
V_43 -> V_44 -> V_60 ( & V_39 -> V_41 , V_43 ,
false ) ;
F_14 ( & V_39 -> V_41 ) ;
F_44 ( V_118 , & V_39 -> V_93 ) ;
F_45 ( & V_42 -> V_29 -> V_30 ,
L_15 ,
V_43 -> V_106 , V_42 -> V_15 . V_76 ) ;
}
F_33 ( & V_39 -> V_99 ) ;
F_29 ( & V_39 -> V_99 , & V_124 ) ;
F_37 ( & V_43 -> V_117 ) ;
F_32 ( & V_42 -> V_29 -> V_30 , L_16 ,
V_43 -> V_106 ) ;
}
V_72:
F_11 ( & V_40 ) ;
F_31 (cdev, tmp, &cdevs_tmp, list) {
F_17 ( V_39 ) ;
}
return V_104 ;
}
static int F_46 ( struct V_68 * V_43 )
{
struct V_119 * V_49 ;
struct V_53 * V_42 ;
int V_104 = 0 ;
F_8 ( & V_120 ) ;
F_9 (ldev, &i40e_devices, list) {
V_42 = V_49 -> V_42 ;
V_42 -> V_110 |= V_111 ;
F_39 ( V_42 ) ;
}
F_11 ( & V_120 ) ;
return V_104 ;
}
static int F_47 ( struct V_48 * V_49 ,
struct V_68 * V_43 ,
T_3 V_35 , T_1 * V_36 , T_2 V_37 )
{
struct V_53 * V_42 = V_49 -> V_42 ;
struct V_127 * V_15 = & V_42 -> V_15 ;
T_4 V_128 ;
V_128 = F_48 ( V_15 , V_35 , V_129 ,
0 , V_36 , V_37 , NULL ) ;
if ( V_128 )
F_6 ( & V_42 -> V_29 -> V_30 , L_17 ,
V_128 , V_15 -> V_89 . V_130 ) ;
return V_128 ;
}
static int F_49 ( struct V_48 * V_49 ,
struct V_68 * V_43 ,
struct V_50 * V_51 )
{
struct V_53 * V_42 = V_49 -> V_42 ;
struct V_127 * V_15 = & V_42 -> V_15 ;
struct V_54 * V_55 ;
T_3 V_57 , V_17 , V_56 , V_131 ;
T_3 V_132 ;
V_132 = sizeof( struct V_50 ) +
( sizeof( struct V_54 ) * ( V_51 -> V_52 - 1 ) ) ;
V_49 -> V_51 = F_24 ( V_132 , V_73 ) ;
V_49 -> V_51 -> V_52 = V_51 -> V_52 ;
for ( V_17 = 0 ; V_17 < V_51 -> V_52 ; V_17 ++ ) {
V_55 = & V_51 -> V_55 [ V_17 ] ;
if ( ! V_55 )
continue;
V_57 = V_55 -> V_57 ;
if ( ( V_57 >= ( V_42 -> V_97 + V_42 -> V_95 ) ) ||
( V_57 < V_42 -> V_97 ) )
goto V_128;
V_49 -> V_51 -> V_55 [ V_17 ] = * V_55 ;
V_56 = F_15 ( V_57 - 1 ) ;
if ( V_55 -> V_133 == V_134 ) {
F_16 ( V_15 , V_56 , V_58 ) ;
} else {
V_131 = ( V_55 -> V_133 &
V_58 ) |
( V_135 <<
V_136 ) ;
F_16 ( V_15 , V_56 , V_131 ) ;
V_131 = ( V_137 |
( V_57 << V_138 ) |
( V_55 -> V_139 <<
V_140 ) |
( V_141 <<
V_142 ) ) ;
F_16 ( V_15 , F_50 ( V_55 -> V_133 ) , V_131 ) ;
}
if ( V_55 -> V_143 != V_134 ) {
V_131 = ( V_144 |
( V_57 << V_145 ) |
( V_55 -> V_139 <<
V_146 ) ) ;
F_16 ( V_15 , V_147 , V_131 ) ;
}
}
return 0 ;
V_128:
F_17 ( V_49 -> V_51 ) ;
V_49 -> V_51 = NULL ;
return - V_32 ;
}
static void F_51 ( struct V_48 * V_49 ,
struct V_68 * V_43 ,
T_3 V_148 )
{
struct V_53 * V_42 = V_49 -> V_42 ;
switch ( V_148 ) {
case V_149 :
F_25 ( V_150 , & V_42 -> V_93 ) ;
break;
case V_151 :
F_25 ( V_150 , & V_42 -> V_93 ) ;
break;
default:
F_45 ( & V_42 -> V_29 -> V_30 ,
L_18 ,
V_43 -> V_106 , V_42 -> V_15 . V_76 , V_148 ) ;
break;
}
F_39 ( V_42 ) ;
}
static int F_52 ( struct V_48 * V_49 ,
struct V_68 * V_43 ,
bool V_152 , T_3 V_35 ,
T_3 V_153 , T_3 V_154 )
{
struct V_53 * V_42 = V_49 -> V_42 ;
struct V_8 * V_9 = V_42 -> V_9 [ V_42 -> V_71 ] ;
struct V_155 V_156 ;
bool V_157 = true ;
T_4 V_128 ;
if ( V_152 )
return - V_32 ;
V_156 . V_158 = V_42 -> V_159 ;
V_156 . V_160 = V_42 -> V_15 . V_76 ;
V_128 = F_53 ( & V_42 -> V_15 , & V_156 , NULL ) ;
V_156 . V_110 = V_161 ;
if ( V_128 ) {
F_32 ( & V_42 -> V_29 -> V_30 ,
L_19 ,
F_54 ( & V_42 -> V_15 , V_128 ) ,
F_55 ( & V_42 -> V_15 ,
V_42 -> V_15 . V_89 . V_130 ) ) ;
return - V_162 ;
}
if ( ( V_154 & V_163 ) &&
( V_153 & V_163 ) ) {
V_156 . V_25 . V_164 =
F_56 ( V_165 ) ;
V_156 . V_25 . V_166 |= V_167 ;
} else if ( ( V_154 & V_163 ) &&
! ( V_153 & V_163 ) ) {
V_156 . V_25 . V_164 =
F_56 ( V_165 ) ;
V_156 . V_25 . V_166 &= ~ V_167 ;
} else {
V_157 = false ;
F_45 ( & V_42 -> V_29 -> V_30 ,
L_20 ,
V_43 -> V_106 , V_42 -> V_15 . V_76 , V_153 ) ;
}
if ( V_157 ) {
V_128 = F_57 ( & V_9 -> V_14 -> V_15 , & V_156 , NULL ) ;
if ( V_128 ) {
F_32 ( & V_42 -> V_29 -> V_30 ,
L_21 ,
F_54 ( & V_42 -> V_15 , V_128 ) ,
F_55 ( & V_42 -> V_15 ,
V_42 -> V_15 . V_89 . V_130 ) ) ;
}
}
return V_128 ;
}
int F_58 ( struct V_68 * V_43 )
{
int V_104 = 0 ;
enum V_1 V_168 ;
if ( ! V_43 ) {
V_104 = - V_169 ;
goto V_72;
}
if ( strlen ( V_43 -> V_106 ) == 0 ) {
F_59 ( L_22 ) ;
V_104 = - V_169 ;
goto V_72;
}
F_8 ( & V_114 ) ;
if ( F_60 ( V_43 ) ) {
F_59 ( L_23 ,
V_43 -> V_106 ) ;
F_11 ( & V_114 ) ;
V_104 = - V_121 ;
goto V_72;
}
if ( ( V_43 -> V_81 . V_82 != V_83 ) ||
( V_43 -> V_81 . V_84 != V_85 ) ) {
F_59 ( L_24 ,
V_43 -> V_106 ) ;
F_59 ( L_25 ,
V_43 -> V_81 . V_82 , V_43 -> V_81 . V_84 ,
V_43 -> V_81 . V_86 ,
V_170 ) ;
F_11 ( & V_114 ) ;
V_104 = - V_169 ;
goto V_72;
}
V_168 = F_1 ( V_43 -> type ) ;
if ( V_168 == V_7 ) {
F_59 ( L_26 ,
V_43 -> V_106 , V_43 -> type ) ;
F_11 ( & V_114 ) ;
V_104 = - V_169 ;
goto V_72;
}
F_29 ( & V_43 -> V_99 , & V_171 ) ;
F_25 ( V_115 , & V_43 -> V_93 ) ;
F_11 ( & V_114 ) ;
if ( F_46 ( V_43 ) ) {
V_104 = - V_169 ;
goto V_72;
}
F_59 ( L_27 ,
V_43 -> V_106 , V_104 ) ;
V_72:
return V_104 ;
}
int F_61 ( struct V_68 * V_43 )
{
int V_104 = 0 ;
if ( ! V_43 || F_41 ( V_43 ) ) {
V_104 = - V_169 ;
goto V_72;
}
F_8 ( & V_114 ) ;
if ( ! F_60 ( V_43 ) ) {
F_59 ( L_28 ,
V_43 -> V_106 ) ;
F_11 ( & V_114 ) ;
V_104 = - V_105 ;
goto V_72;
}
if ( F_43 ( & V_43 -> V_117 ) == 0 ) {
F_44 ( V_115 , & V_43 -> V_93 ) ;
F_33 ( & V_43 -> V_99 ) ;
F_59 ( L_29 ,
V_43 -> V_106 , V_104 ) ;
} else {
V_104 = V_126 ;
F_2 ( L_30 ,
V_43 -> V_106 ) ;
}
F_11 ( & V_114 ) ;
V_72:
return V_104 ;
}
