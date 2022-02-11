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
int V_47 = 0 ;
if ( ! V_9 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_34 == V_9 -> V_34 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 || ! V_39 -> V_43 -> V_44 -> V_48 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_5 ) ;
continue;
}
if ( ! ( F_14 ( V_49 ,
& V_39 -> V_50 ) ) ) {
V_47 = V_39 -> V_43 -> V_44 -> V_48 ( & V_39 -> V_41 ,
V_39 -> V_43 ) ;
if ( ! V_47 )
F_15 ( V_49 ,
& V_39 -> V_50 ) ;
}
}
}
F_11 ( & V_40 ) ;
}
static void F_16 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_54 ;
T_3 V_17 ;
if ( ! V_52 -> V_54 )
return;
for ( V_17 = 0 ; V_17 < V_54 -> V_55 ; V_17 ++ ) {
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_57 * V_58 ;
T_3 V_59 ;
V_58 = & V_54 -> V_58 [ V_17 ] ;
if ( ! V_58 )
continue;
V_59 = F_17 ( V_58 -> V_60 - 1 ) ;
F_18 ( & V_42 -> V_15 , V_59 , V_61 ) ;
}
F_19 ( V_52 -> V_54 ) ;
V_52 -> V_54 = NULL ;
}
void F_20 ( struct V_8 * V_9 , bool V_62 )
{
struct V_38 * V_39 ;
if ( ! V_9 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_34 == V_9 -> V_34 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 || ! V_39 -> V_43 -> V_44 -> V_63 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_6 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_63 ( & V_39 -> V_41 , V_39 -> V_43 ,
V_62 ) ;
F_16 ( & V_39 -> V_41 ) ;
}
}
F_11 ( & V_40 ) ;
}
void F_21 ( struct V_56 * V_42 , T_3 V_35 )
{
struct V_38 * V_39 ;
if ( ! V_42 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_42 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_64 ) {
F_10 ( & V_42 -> V_29 -> V_30 ,
L_7 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_64 ( & V_39 -> V_41 ,
V_39 -> V_43 , V_35 ) ;
}
}
F_11 ( & V_40 ) ;
}
void F_22 ( struct V_56 * V_42 , T_3 V_65 )
{
struct V_38 * V_39 ;
if ( ! V_42 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_42 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_66 ) {
F_10 ( & V_42 -> V_29 -> V_30 ,
L_8 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_66 ( & V_39 -> V_41 ,
V_39 -> V_43 , V_65 ) ;
}
}
F_11 ( & V_40 ) ;
}
int F_23 ( struct V_56 * V_42 , T_3 V_35 ,
enum V_2 type )
{
struct V_38 * V_39 ;
int V_67 = false ;
if ( ! V_42 )
return false ;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_42 == V_42 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 ||
! V_39 -> V_43 -> V_44 -> V_68 ||
! ( V_39 -> V_43 -> type == type ) ) {
F_10 ( & V_42 -> V_29 -> V_30 ,
L_9 ) ;
continue;
}
V_67 = V_39 -> V_43 -> V_44 -> V_68 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
V_35 ) ;
break;
}
}
F_11 ( & V_40 ) ;
return V_67 ;
}
struct V_8 * F_24 ( struct V_56 * V_42 ,
enum V_1 type ,
struct V_8 * V_69 )
{
struct V_8 * V_9 ;
int V_17 = 0 ;
if ( V_69 ) {
for ( V_17 = 0 ; V_17 < V_42 -> V_70 ; V_17 ++ ) {
V_9 = V_42 -> V_9 [ V_17 ] ;
if ( V_9 == V_69 )
break;
}
}
for (; V_17 < V_42 -> V_70 ; V_17 ++ ) {
V_9 = V_42 -> V_9 [ V_17 ] ;
if ( V_9 && V_9 -> type == type )
return V_9 ;
}
return NULL ;
}
static
struct V_38 * F_25 ( struct V_56 * V_42 ,
struct V_71 * V_43 ,
bool * V_72 )
{
struct V_38 * V_39 ;
struct V_73 * V_74 = NULL ;
struct V_8 * V_9 = V_42 -> V_9 [ V_42 -> V_75 ] ;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( ( V_39 -> V_41 . V_42 == V_42 ) && ( V_39 -> V_43 == V_43 ) ) {
* V_72 = true ;
goto V_76;
}
}
V_39 = F_26 ( sizeof( * V_39 ) , V_77 ) ;
if ( ! V_39 )
goto V_76;
V_39 -> V_41 . V_42 = ( void * ) V_42 ;
V_39 -> V_41 . V_34 = V_9 -> V_34 ;
V_39 -> V_41 . V_78 = V_42 -> V_29 ;
V_39 -> V_41 . V_79 = V_42 -> V_15 . V_80 ;
V_39 -> V_41 . V_81 = V_82 ;
V_39 -> V_41 . V_83 = V_42 -> V_15 . V_83 ;
V_39 -> V_41 . V_44 = & V_84 ;
V_39 -> V_41 . V_85 . V_86 = V_87 ;
V_39 -> V_41 . V_85 . V_88 = V_89 ;
V_39 -> V_41 . V_85 . V_90 = V_91 ;
V_39 -> V_41 . V_92 = V_42 -> V_15 . V_93 . V_92 ;
V_39 -> V_41 . V_94 = V_42 -> V_15 . V_93 . V_94 ;
V_39 -> V_41 . V_95 = V_42 -> V_15 . V_93 . V_95 ;
F_15 ( V_96 , & V_39 -> V_50 ) ;
if ( F_3 ( V_9 , & V_39 -> V_41 . V_11 ) ) {
F_19 ( V_39 ) ;
V_39 = NULL ;
goto V_76;
}
V_39 -> V_41 . V_97 = V_42 -> V_98 ;
V_39 -> V_41 . V_99 = & V_42 -> V_99 [ V_42 -> V_100 ] ;
V_74 = F_27 ( & V_39 -> V_41 . V_34 -> V_101 . V_102 ,
struct V_73 , V_102 ) ;
if ( V_74 )
F_28 ( V_39 -> V_41 . V_103 , V_74 -> V_104 ) ;
else
F_6 ( & V_42 -> V_29 -> V_30 , L_10 ) ;
V_39 -> V_43 = V_43 ;
F_29 ( & V_39 -> V_102 ) ;
F_30 ( & V_39 -> V_102 , & V_105 ) ;
V_76:
F_11 ( & V_40 ) ;
return V_39 ;
}
static
int F_31 ( struct V_56 * V_42 , struct V_71 * V_43 )
{
struct V_38 * V_39 , * V_106 ;
int V_47 = - V_107 ;
F_8 ( & V_40 ) ;
F_32 (cdev, tmp, &i40e_client_instances, list) {
if ( ( V_39 -> V_41 . V_42 != V_42 ) || ( V_39 -> V_43 != V_43 ) )
continue;
F_33 ( & V_42 -> V_29 -> V_30 , L_11 ,
V_43 -> V_108 , V_42 -> V_15 . V_80 ,
V_42 -> V_15 . V_109 . V_110 , V_42 -> V_15 . V_109 . V_111 ) ;
F_34 ( & V_39 -> V_102 ) ;
F_19 ( V_39 ) ;
V_47 = 0 ;
break;
}
F_11 ( & V_40 ) ;
return V_47 ;
}
void F_35 ( struct V_56 * V_42 )
{
struct V_38 * V_39 ;
struct V_71 * V_43 ;
bool V_72 = false ;
int V_47 = 0 ;
if ( ! ( V_42 -> V_112 & V_113 ) )
return;
V_42 -> V_112 &= ~ V_113 ;
if ( F_14 ( V_114 , & V_42 -> V_50 ) ||
F_14 ( V_115 , & V_42 -> V_50 ) )
return;
F_8 ( & V_116 ) ;
F_9 (client, &i40e_clients, list) {
if ( ! F_14 ( V_117 , & V_43 -> V_50 ) )
continue;
if ( ! ( V_43 -> V_112 & V_118 ) ) {
if ( F_14 ( V_114 , & V_42 -> V_9 [ V_42 -> V_75 ] -> V_50 ) )
continue;
} else {
F_36 ( & V_42 -> V_29 -> V_30 , L_12 ,
V_43 -> V_108 ) ;
}
V_39 = F_25 ( V_42 , V_43 , & V_72 ) ;
if ( ! V_39 )
continue;
if ( ! V_72 ) {
F_37 ( & V_43 -> V_119 ) ;
F_33 ( & V_42 -> V_29 -> V_30 , L_13 ,
V_43 -> V_108 , V_42 -> V_15 . V_80 ,
V_42 -> V_15 . V_109 . V_110 , V_42 -> V_15 . V_109 . V_111 ) ;
}
F_37 ( & V_39 -> V_119 ) ;
if ( V_43 -> V_44 && V_43 -> V_44 -> V_48 )
V_47 = V_43 -> V_44 -> V_48 ( & V_39 -> V_41 , V_43 ) ;
F_38 ( & V_39 -> V_119 ) ;
if ( ! V_47 ) {
F_15 ( V_49 , & V_39 -> V_50 ) ;
} else {
F_31 ( V_42 , V_43 ) ;
F_38 ( & V_43 -> V_119 ) ;
continue;
}
}
F_11 ( & V_116 ) ;
}
int F_39 ( struct V_56 * V_42 )
{
struct V_120 * V_52 ;
int V_47 = 0 ;
F_8 ( & V_121 ) ;
F_9 (ldev, &i40e_devices, list) {
if ( V_52 -> V_42 == V_42 ) {
V_47 = - V_122 ;
goto V_76;
}
}
V_52 = F_26 ( sizeof( * V_52 ) , V_77 ) ;
if ( ! V_52 ) {
V_47 = - V_123 ;
goto V_76;
}
V_52 -> V_42 = V_42 ;
F_29 ( & V_52 -> V_102 ) ;
F_30 ( & V_52 -> V_102 , & V_124 ) ;
F_33 ( & V_42 -> V_29 -> V_30 , L_14 ,
V_42 -> V_15 . V_80 , V_42 -> V_15 . V_109 . V_110 , V_42 -> V_15 . V_109 . V_111 ) ;
V_42 -> V_112 |= V_113 ;
F_40 ( V_42 ) ;
V_76:
F_11 ( & V_121 ) ;
return V_47 ;
}
int F_41 ( struct V_56 * V_42 )
{
struct V_120 * V_52 , * V_106 ;
int V_47 = - V_107 ;
F_8 ( & V_121 ) ;
F_32 (ldev, tmp, &i40e_devices, list) {
if ( V_52 -> V_42 == V_42 ) {
F_33 ( & V_42 -> V_29 -> V_30 , L_15 ,
V_42 -> V_15 . V_80 , V_42 -> V_15 . V_109 . V_110 ,
V_42 -> V_15 . V_109 . V_111 ) ;
F_34 ( & V_52 -> V_102 ) ;
F_19 ( V_52 ) ;
V_47 = 0 ;
break;
}
}
F_11 ( & V_121 ) ;
return V_47 ;
}
static int F_42 ( struct V_71 * V_43 )
{
struct V_38 * V_39 , * V_106 ;
struct V_56 * V_42 = NULL ;
int V_47 = 0 ;
F_43 ( V_125 ) ;
F_8 ( & V_40 ) ;
F_32 (cdev, tmp, &i40e_client_instances, list) {
if ( strncmp ( V_39 -> V_43 -> V_108 , V_43 -> V_108 ,
V_126 ) )
continue;
if ( F_14 ( V_49 , & V_39 -> V_50 ) ) {
if ( F_44 ( & V_39 -> V_119 ) > 0 ) {
V_47 = V_127 ;
goto V_76;
}
V_42 = (struct V_56 * ) V_39 -> V_41 . V_42 ;
if ( V_43 -> V_44 && V_43 -> V_44 -> V_63 )
V_43 -> V_44 -> V_63 ( & V_39 -> V_41 , V_43 ,
false ) ;
F_16 ( & V_39 -> V_41 ) ;
F_45 ( V_49 , & V_39 -> V_50 ) ;
F_36 ( & V_42 -> V_29 -> V_30 ,
L_16 ,
V_43 -> V_108 , V_42 -> V_15 . V_80 ) ;
}
F_34 ( & V_39 -> V_102 ) ;
F_30 ( & V_39 -> V_102 , & V_125 ) ;
F_38 ( & V_43 -> V_119 ) ;
F_33 ( & V_42 -> V_29 -> V_30 , L_17 ,
V_43 -> V_108 ) ;
}
V_76:
F_11 ( & V_40 ) ;
F_32 (cdev, tmp, &cdevs_tmp, list) {
F_19 ( V_39 ) ;
}
return V_47 ;
}
static int F_46 ( struct V_71 * V_43 )
{
struct V_120 * V_52 ;
struct V_56 * V_42 ;
int V_47 = 0 ;
F_8 ( & V_121 ) ;
F_9 (ldev, &i40e_devices, list) {
V_42 = V_52 -> V_42 ;
V_42 -> V_112 |= V_113 ;
F_40 ( V_42 ) ;
}
F_11 ( & V_121 ) ;
return V_47 ;
}
static int F_47 ( struct V_51 * V_52 ,
struct V_71 * V_43 ,
T_3 V_35 , T_1 * V_36 , T_2 V_37 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_128 * V_15 = & V_42 -> V_15 ;
T_4 V_129 ;
V_129 = F_48 ( V_15 , V_35 , V_130 ,
0 , V_36 , V_37 , NULL ) ;
if ( V_129 )
F_6 ( & V_42 -> V_29 -> V_30 , L_18 ,
V_129 , V_15 -> V_93 . V_131 ) ;
return V_129 ;
}
static int F_49 ( struct V_51 * V_52 ,
struct V_71 * V_43 ,
struct V_53 * V_54 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_128 * V_15 = & V_42 -> V_15 ;
struct V_57 * V_58 ;
T_3 V_60 , V_17 , V_59 , V_132 ;
T_3 V_133 ;
V_133 = sizeof( struct V_53 ) +
( sizeof( struct V_57 ) * ( V_54 -> V_55 - 1 ) ) ;
V_52 -> V_54 = F_26 ( V_133 , V_77 ) ;
V_52 -> V_54 -> V_55 = V_54 -> V_55 ;
for ( V_17 = 0 ; V_17 < V_54 -> V_55 ; V_17 ++ ) {
V_58 = & V_54 -> V_58 [ V_17 ] ;
if ( ! V_58 )
continue;
V_60 = V_58 -> V_60 ;
if ( ( V_60 >= ( V_42 -> V_100 + V_42 -> V_98 ) ) ||
( V_60 < V_42 -> V_100 ) )
goto V_129;
V_52 -> V_54 -> V_58 [ V_17 ] = * V_58 ;
V_59 = F_17 ( V_60 - 1 ) ;
if ( V_58 -> V_134 == V_135 ) {
F_18 ( V_15 , V_59 , V_61 ) ;
} else {
V_132 = ( V_58 -> V_134 &
V_61 ) |
( V_136 <<
V_137 ) ;
F_18 ( V_15 , V_59 , V_132 ) ;
V_132 = ( V_138 |
( V_60 << V_139 ) |
( V_58 -> V_140 <<
V_141 ) |
( V_142 <<
V_143 ) ) ;
F_18 ( V_15 , F_50 ( V_58 -> V_134 ) , V_132 ) ;
}
if ( V_58 -> V_144 != V_135 ) {
V_132 = ( V_145 |
( V_60 << V_146 ) |
( V_58 -> V_140 <<
V_147 ) ) ;
F_18 ( V_15 , V_148 , V_132 ) ;
}
}
return 0 ;
V_129:
F_19 ( V_52 -> V_54 ) ;
V_52 -> V_54 = NULL ;
return - V_32 ;
}
static void F_51 ( struct V_51 * V_52 ,
struct V_71 * V_43 ,
T_3 V_149 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
switch ( V_149 ) {
case V_150 :
F_15 ( V_151 , & V_42 -> V_50 ) ;
break;
case V_152 :
F_15 ( V_151 , & V_42 -> V_50 ) ;
break;
default:
F_36 ( & V_42 -> V_29 -> V_30 ,
L_19 ,
V_43 -> V_108 , V_42 -> V_15 . V_80 , V_149 ) ;
break;
}
F_40 ( V_42 ) ;
}
static int F_52 ( struct V_51 * V_52 ,
struct V_71 * V_43 ,
bool V_153 , T_3 V_35 ,
T_3 V_154 , T_3 V_155 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_8 * V_9 = V_42 -> V_9 [ V_42 -> V_75 ] ;
struct V_156 V_157 ;
bool V_158 = true ;
T_4 V_129 ;
if ( V_153 )
return - V_32 ;
V_157 . V_159 = V_42 -> V_160 ;
V_157 . V_161 = V_42 -> V_15 . V_80 ;
V_129 = F_53 ( & V_42 -> V_15 , & V_157 , NULL ) ;
V_157 . V_112 = V_162 ;
if ( V_129 ) {
F_33 ( & V_42 -> V_29 -> V_30 ,
L_20 ,
F_54 ( & V_42 -> V_15 , V_129 ) ,
F_55 ( & V_42 -> V_15 ,
V_42 -> V_15 . V_93 . V_131 ) ) ;
return - V_163 ;
}
if ( ( V_155 & V_164 ) &&
( V_154 & V_164 ) ) {
V_157 . V_25 . V_165 =
F_56 ( V_166 ) ;
V_157 . V_25 . V_167 |= V_168 ;
} else if ( ( V_155 & V_164 ) &&
! ( V_154 & V_164 ) ) {
V_157 . V_25 . V_165 =
F_56 ( V_166 ) ;
V_157 . V_25 . V_167 &= ~ V_168 ;
} else {
V_158 = false ;
F_36 ( & V_42 -> V_29 -> V_30 ,
L_21 ,
V_43 -> V_108 , V_42 -> V_15 . V_80 , V_154 ) ;
}
if ( V_158 ) {
V_129 = F_57 ( & V_9 -> V_14 -> V_15 , & V_157 , NULL ) ;
if ( V_129 ) {
F_33 ( & V_42 -> V_29 -> V_30 ,
L_22 ,
F_54 ( & V_42 -> V_15 , V_129 ) ,
F_55 ( & V_42 -> V_15 ,
V_42 -> V_15 . V_93 . V_131 ) ) ;
}
}
return V_129 ;
}
int F_58 ( struct V_71 * V_43 )
{
int V_47 = 0 ;
enum V_1 V_169 ;
if ( ! V_43 ) {
V_47 = - V_170 ;
goto V_76;
}
if ( strlen ( V_43 -> V_108 ) == 0 ) {
F_59 ( L_23 ) ;
V_47 = - V_170 ;
goto V_76;
}
F_8 ( & V_116 ) ;
if ( F_60 ( V_43 ) ) {
F_59 ( L_24 ,
V_43 -> V_108 ) ;
F_11 ( & V_116 ) ;
V_47 = - V_122 ;
goto V_76;
}
if ( ( V_43 -> V_85 . V_86 != V_87 ) ||
( V_43 -> V_85 . V_88 != V_89 ) ) {
F_59 ( L_25 ,
V_43 -> V_108 ) ;
F_59 ( L_26 ,
V_43 -> V_85 . V_86 , V_43 -> V_85 . V_88 ,
V_43 -> V_85 . V_90 ,
V_171 ) ;
F_11 ( & V_116 ) ;
V_47 = - V_170 ;
goto V_76;
}
V_169 = F_1 ( V_43 -> type ) ;
if ( V_169 == V_7 ) {
F_59 ( L_27 ,
V_43 -> V_108 , V_43 -> type ) ;
F_11 ( & V_116 ) ;
V_47 = - V_170 ;
goto V_76;
}
F_30 ( & V_43 -> V_102 , & V_172 ) ;
F_15 ( V_117 , & V_43 -> V_50 ) ;
F_11 ( & V_116 ) ;
if ( F_46 ( V_43 ) ) {
V_47 = - V_170 ;
goto V_76;
}
F_59 ( L_28 ,
V_43 -> V_108 , V_47 ) ;
V_76:
return V_47 ;
}
int F_61 ( struct V_71 * V_43 )
{
int V_47 = 0 ;
F_8 ( & V_116 ) ;
if ( ! V_43 || F_42 ( V_43 ) ) {
V_47 = - V_170 ;
goto V_76;
}
if ( ! F_60 ( V_43 ) ) {
F_59 ( L_29 ,
V_43 -> V_108 ) ;
F_11 ( & V_116 ) ;
V_47 = - V_107 ;
goto V_76;
}
if ( F_44 ( & V_43 -> V_119 ) == 0 ) {
F_45 ( V_117 , & V_43 -> V_50 ) ;
F_34 ( & V_43 -> V_102 ) ;
F_59 ( L_30 ,
V_43 -> V_108 , V_47 ) ;
} else {
V_47 = V_127 ;
F_2 ( L_31 ,
V_43 -> V_108 ) ;
}
V_76:
F_11 ( & V_116 ) ;
return V_47 ;
}
