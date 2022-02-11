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
if ( ! F_11 ( V_46 ,
& V_39 -> V_47 ) ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 , L_4 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_45 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
V_35 , V_36 , V_37 ) ;
}
}
F_12 ( & V_40 ) ;
}
void F_13 ( struct V_8 * V_9 )
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
! V_39 -> V_43 -> V_44 -> V_48 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_5 ) ;
continue;
}
if ( ! F_11 ( V_46 ,
& V_39 -> V_47 ) ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 , L_6 ) ;
continue;
}
V_39 -> V_41 . V_11 = V_11 ;
V_39 -> V_43 -> V_44 -> V_48 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
& V_11 ) ;
}
}
F_12 ( & V_40 ) ;
}
void F_14 ( struct V_8 * V_9 )
{
struct V_38 * V_39 ;
int V_49 = 0 ;
if ( ! V_9 )
return;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( V_39 -> V_41 . V_34 == V_9 -> V_34 ) {
if ( ! V_39 -> V_43 ||
! V_39 -> V_43 -> V_44 || ! V_39 -> V_43 -> V_44 -> V_50 ) {
F_10 ( & V_9 -> V_14 -> V_29 -> V_30 ,
L_7 ) ;
continue;
}
if ( ! ( F_11 ( V_46 ,
& V_39 -> V_47 ) ) ) {
V_49 = V_39 -> V_43 -> V_44 -> V_50 ( & V_39 -> V_41 ,
V_39 -> V_43 ) ;
if ( ! V_49 )
F_15 ( V_46 ,
& V_39 -> V_47 ) ;
}
}
}
F_12 ( & V_40 ) ;
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
L_8 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_63 ( & V_39 -> V_41 , V_39 -> V_43 ,
V_62 ) ;
F_21 ( V_46 , & V_39 -> V_47 ) ;
F_16 ( & V_39 -> V_41 ) ;
}
}
F_12 ( & V_40 ) ;
}
void F_22 ( struct V_56 * V_42 , T_3 V_35 )
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
L_9 ) ;
continue;
}
if ( ! F_11 ( V_46 ,
& V_39 -> V_47 ) ) {
F_10 ( & V_42 -> V_29 -> V_30 , L_10 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_64 ( & V_39 -> V_41 ,
V_39 -> V_43 , V_35 ) ;
}
}
F_12 ( & V_40 ) ;
}
void F_23 ( struct V_56 * V_42 , T_3 V_65 )
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
L_11 ) ;
continue;
}
if ( ! F_11 ( V_46 ,
& V_39 -> V_47 ) ) {
F_10 ( & V_42 -> V_29 -> V_30 , L_12 ) ;
continue;
}
V_39 -> V_43 -> V_44 -> V_66 ( & V_39 -> V_41 ,
V_39 -> V_43 , V_65 ) ;
}
}
F_12 ( & V_40 ) ;
}
int F_24 ( struct V_56 * V_42 , T_3 V_35 ,
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
L_13 ) ;
continue;
}
if ( ! F_11 ( V_46 ,
& V_39 -> V_47 ) ) {
F_10 ( & V_42 -> V_29 -> V_30 , L_14 ) ;
continue;
}
V_67 = V_39 -> V_43 -> V_44 -> V_68 ( & V_39 -> V_41 ,
V_39 -> V_43 ,
V_35 ) ;
break;
}
}
F_12 ( & V_40 ) ;
return V_67 ;
}
static
struct V_38 * F_25 ( struct V_56 * V_42 ,
struct V_69 * V_43 ,
bool * V_70 )
{
struct V_38 * V_39 ;
struct V_71 * V_72 = NULL ;
struct V_8 * V_9 = V_42 -> V_9 [ V_42 -> V_73 ] ;
F_8 ( & V_40 ) ;
F_9 (cdev, &i40e_client_instances, list) {
if ( ( V_39 -> V_41 . V_42 == V_42 ) && ( V_39 -> V_43 == V_43 ) ) {
* V_70 = true ;
goto V_74;
}
}
V_39 = F_26 ( sizeof( * V_39 ) , V_75 ) ;
if ( ! V_39 )
goto V_74;
V_39 -> V_41 . V_42 = ( void * ) V_42 ;
V_39 -> V_41 . V_34 = V_9 -> V_34 ;
V_39 -> V_41 . V_76 = V_42 -> V_29 ;
V_39 -> V_41 . V_77 = V_42 -> V_15 . V_78 ;
V_39 -> V_41 . V_79 = V_80 ;
V_39 -> V_41 . V_81 = V_42 -> V_15 . V_81 ;
V_39 -> V_41 . V_44 = & V_82 ;
V_39 -> V_41 . V_83 . V_84 = V_85 ;
V_39 -> V_41 . V_83 . V_86 = V_87 ;
V_39 -> V_41 . V_83 . V_88 = V_89 ;
V_39 -> V_41 . V_90 = V_42 -> V_15 . V_91 . V_90 ;
V_39 -> V_41 . V_92 = V_42 -> V_15 . V_91 . V_92 ;
V_39 -> V_41 . V_93 = V_42 -> V_15 . V_91 . V_93 ;
F_15 ( V_94 , & V_39 -> V_47 ) ;
if ( F_3 ( V_9 , & V_39 -> V_41 . V_11 ) ) {
F_19 ( V_39 ) ;
V_39 = NULL ;
goto V_74;
}
V_39 -> V_41 . V_95 = V_42 -> V_96 ;
V_39 -> V_41 . V_97 = & V_42 -> V_97 [ V_42 -> V_98 ] ;
V_72 = F_27 ( & V_39 -> V_41 . V_34 -> V_99 . V_100 ,
struct V_71 , V_100 ) ;
if ( V_72 )
F_28 ( V_39 -> V_41 . V_101 , V_72 -> V_102 ) ;
else
F_6 ( & V_42 -> V_29 -> V_30 , L_15 ) ;
V_39 -> V_43 = V_43 ;
F_29 ( & V_39 -> V_100 ) ;
F_30 ( & V_39 -> V_100 , & V_103 ) ;
V_74:
F_12 ( & V_40 ) ;
return V_39 ;
}
static
int F_31 ( struct V_56 * V_42 , struct V_69 * V_43 )
{
struct V_38 * V_39 , * V_104 ;
int V_49 = - V_105 ;
F_8 ( & V_40 ) ;
F_32 (cdev, tmp, &i40e_client_instances, list) {
if ( ( V_39 -> V_41 . V_42 != V_42 ) || ( V_39 -> V_43 != V_43 ) )
continue;
F_33 ( & V_42 -> V_29 -> V_30 , L_16 ,
V_43 -> V_106 , V_42 -> V_15 . V_78 ,
V_42 -> V_15 . V_107 . V_108 , V_42 -> V_15 . V_107 . V_109 ) ;
F_34 ( & V_39 -> V_100 ) ;
F_19 ( V_39 ) ;
V_49 = 0 ;
break;
}
F_12 ( & V_40 ) ;
return V_49 ;
}
void F_35 ( struct V_56 * V_42 )
{
struct V_38 * V_39 ;
struct V_69 * V_43 ;
bool V_70 = false ;
int V_49 = 0 ;
if ( ! ( V_42 -> V_110 & V_111 ) )
return;
V_42 -> V_110 &= ~ V_111 ;
if ( F_11 ( V_112 , & V_42 -> V_47 ) ||
F_11 ( V_113 , & V_42 -> V_47 ) )
return;
F_8 ( & V_114 ) ;
F_9 (client, &i40e_clients, list) {
if ( ! F_11 ( V_115 , & V_43 -> V_47 ) )
continue;
if ( ! ( V_43 -> V_110 & V_116 ) ) {
if ( F_11 ( V_112 , & V_42 -> V_9 [ V_42 -> V_73 ] -> V_47 ) )
continue;
} else {
F_36 ( & V_42 -> V_29 -> V_30 , L_17 ,
V_43 -> V_106 ) ;
}
V_39 = F_25 ( V_42 , V_43 , & V_70 ) ;
if ( ! V_39 )
continue;
if ( ! V_70 ) {
F_33 ( & V_42 -> V_29 -> V_30 , L_18 ,
V_43 -> V_106 , V_42 -> V_15 . V_78 ,
V_42 -> V_15 . V_107 . V_108 , V_42 -> V_15 . V_107 . V_109 ) ;
}
F_8 ( & V_40 ) ;
if ( ! F_11 ( V_46 ,
& V_39 -> V_47 ) ) {
if ( V_43 -> V_44 && V_43 -> V_44 -> V_50 )
V_49 = V_43 -> V_44 -> V_50 ( & V_39 -> V_41 ,
V_43 ) ;
if ( ! V_49 ) {
F_15 ( V_46 ,
& V_39 -> V_47 ) ;
} else {
F_31 ( V_42 , V_43 ) ;
}
}
F_12 ( & V_40 ) ;
}
F_12 ( & V_114 ) ;
}
int F_37 ( struct V_56 * V_42 )
{
struct V_117 * V_52 ;
int V_49 = 0 ;
F_8 ( & V_118 ) ;
F_9 (ldev, &i40e_devices, list) {
if ( V_52 -> V_42 == V_42 ) {
V_49 = - V_119 ;
goto V_74;
}
}
V_52 = F_26 ( sizeof( * V_52 ) , V_75 ) ;
if ( ! V_52 ) {
V_49 = - V_120 ;
goto V_74;
}
V_52 -> V_42 = V_42 ;
F_29 ( & V_52 -> V_100 ) ;
F_30 ( & V_52 -> V_100 , & V_121 ) ;
F_33 ( & V_42 -> V_29 -> V_30 , L_19 ,
V_42 -> V_15 . V_78 , V_42 -> V_15 . V_107 . V_108 , V_42 -> V_15 . V_107 . V_109 ) ;
V_42 -> V_110 |= V_111 ;
F_38 ( V_42 ) ;
V_74:
F_12 ( & V_118 ) ;
return V_49 ;
}
int F_39 ( struct V_56 * V_42 )
{
struct V_117 * V_52 , * V_104 ;
int V_49 = - V_105 ;
F_8 ( & V_118 ) ;
F_32 (ldev, tmp, &i40e_devices, list) {
if ( V_52 -> V_42 == V_42 ) {
F_33 ( & V_42 -> V_29 -> V_30 , L_20 ,
V_42 -> V_15 . V_78 , V_42 -> V_15 . V_107 . V_108 ,
V_42 -> V_15 . V_107 . V_109 ) ;
F_34 ( & V_52 -> V_100 ) ;
F_19 ( V_52 ) ;
V_49 = 0 ;
break;
}
}
F_12 ( & V_118 ) ;
return V_49 ;
}
static int F_40 ( struct V_69 * V_43 )
{
struct V_38 * V_39 , * V_104 ;
struct V_56 * V_42 ;
int V_49 = 0 ;
F_41 ( V_122 ) ;
F_8 ( & V_40 ) ;
F_32 (cdev, tmp, &i40e_client_instances, list) {
if ( strncmp ( V_39 -> V_43 -> V_106 , V_43 -> V_106 ,
V_123 ) )
continue;
V_42 = (struct V_56 * ) V_39 -> V_41 . V_42 ;
if ( F_11 ( V_46 , & V_39 -> V_47 ) ) {
if ( V_43 -> V_44 && V_43 -> V_44 -> V_63 )
V_43 -> V_44 -> V_63 ( & V_39 -> V_41 , V_43 ,
false ) ;
F_16 ( & V_39 -> V_41 ) ;
F_21 ( V_46 , & V_39 -> V_47 ) ;
F_36 ( & V_42 -> V_29 -> V_30 ,
L_21 ,
V_43 -> V_106 , V_42 -> V_15 . V_78 ) ;
}
F_42 ( & V_39 -> V_100 , & V_122 ) ;
F_33 ( & V_42 -> V_29 -> V_30 , L_22 ,
V_43 -> V_106 ) ;
}
F_12 ( & V_40 ) ;
F_32 (cdev, tmp, &cdevs_tmp, list) {
F_19 ( V_39 ) ;
}
return V_49 ;
}
static int F_43 ( struct V_69 * V_43 )
{
struct V_117 * V_52 ;
struct V_56 * V_42 ;
int V_49 = 0 ;
F_8 ( & V_118 ) ;
F_9 (ldev, &i40e_devices, list) {
V_42 = V_52 -> V_42 ;
V_42 -> V_110 |= V_111 ;
F_38 ( V_42 ) ;
}
F_12 ( & V_118 ) ;
return V_49 ;
}
static int F_44 ( struct V_51 * V_52 ,
struct V_69 * V_43 ,
T_3 V_35 , T_1 * V_36 , T_2 V_37 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_124 * V_15 = & V_42 -> V_15 ;
T_4 V_125 ;
V_125 = F_45 ( V_15 , V_35 , V_126 ,
0 , V_36 , V_37 , NULL ) ;
if ( V_125 )
F_6 ( & V_42 -> V_29 -> V_30 , L_23 ,
V_125 , V_15 -> V_91 . V_127 ) ;
return V_125 ;
}
static int F_46 ( struct V_51 * V_52 ,
struct V_69 * V_43 ,
struct V_53 * V_54 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_124 * V_15 = & V_42 -> V_15 ;
struct V_57 * V_58 ;
T_3 V_60 , V_17 , V_59 , V_128 ;
T_3 V_129 ;
V_129 = sizeof( struct V_53 ) +
( sizeof( struct V_57 ) * ( V_54 -> V_55 - 1 ) ) ;
V_52 -> V_54 = F_26 ( V_129 , V_75 ) ;
V_52 -> V_54 -> V_55 = V_54 -> V_55 ;
for ( V_17 = 0 ; V_17 < V_54 -> V_55 ; V_17 ++ ) {
V_58 = & V_54 -> V_58 [ V_17 ] ;
if ( ! V_58 )
continue;
V_60 = V_58 -> V_60 ;
if ( ( V_60 >= ( V_42 -> V_98 + V_42 -> V_96 ) ) ||
( V_60 < V_42 -> V_98 ) )
goto V_125;
V_52 -> V_54 -> V_58 [ V_17 ] = * V_58 ;
V_59 = F_17 ( V_60 - 1 ) ;
if ( V_58 -> V_130 == V_131 ) {
F_18 ( V_15 , V_59 , V_61 ) ;
} else {
V_128 = ( V_58 -> V_130 &
V_61 ) |
( V_132 <<
V_133 ) ;
F_18 ( V_15 , V_59 , V_128 ) ;
V_128 = ( V_134 |
( V_60 << V_135 ) |
( V_58 -> V_136 <<
V_137 ) |
( V_138 <<
V_139 ) ) ;
F_18 ( V_15 , F_47 ( V_58 -> V_130 ) , V_128 ) ;
}
if ( V_58 -> V_140 != V_131 ) {
V_128 = ( V_141 |
( V_60 << V_142 ) |
( V_58 -> V_136 <<
V_143 ) ) ;
F_18 ( V_15 , V_144 , V_128 ) ;
}
}
F_48 ( V_15 ) ;
return 0 ;
V_125:
F_19 ( V_52 -> V_54 ) ;
V_52 -> V_54 = NULL ;
return - V_32 ;
}
static void F_49 ( struct V_51 * V_52 ,
struct V_69 * V_43 ,
T_3 V_145 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
switch ( V_145 ) {
case V_146 :
F_15 ( V_147 , & V_42 -> V_47 ) ;
break;
case V_148 :
F_15 ( V_147 , & V_42 -> V_47 ) ;
break;
default:
F_36 ( & V_42 -> V_29 -> V_30 ,
L_24 ,
V_43 -> V_106 , V_42 -> V_15 . V_78 , V_145 ) ;
break;
}
F_38 ( V_42 ) ;
}
static int F_50 ( struct V_51 * V_52 ,
struct V_69 * V_43 ,
bool V_149 , T_3 V_35 ,
T_3 V_150 , T_3 V_151 )
{
struct V_56 * V_42 = V_52 -> V_42 ;
struct V_8 * V_9 = V_42 -> V_9 [ V_42 -> V_73 ] ;
struct V_152 V_153 ;
bool V_154 = true ;
T_4 V_125 ;
if ( V_149 )
return - V_32 ;
V_153 . V_155 = V_42 -> V_156 ;
V_153 . V_157 = V_42 -> V_15 . V_78 ;
V_125 = F_51 ( & V_42 -> V_15 , & V_153 , NULL ) ;
V_153 . V_110 = V_158 ;
if ( V_125 ) {
F_33 ( & V_42 -> V_29 -> V_30 ,
L_25 ,
F_52 ( & V_42 -> V_15 , V_125 ) ,
F_53 ( & V_42 -> V_15 ,
V_42 -> V_15 . V_91 . V_127 ) ) ;
return - V_159 ;
}
if ( ( V_151 & V_160 ) &&
( V_150 & V_160 ) ) {
V_153 . V_25 . V_161 =
F_54 ( V_162 ) ;
V_153 . V_25 . V_163 |= V_164 ;
} else if ( ( V_151 & V_160 ) &&
! ( V_150 & V_160 ) ) {
V_153 . V_25 . V_161 =
F_54 ( V_162 ) ;
V_153 . V_25 . V_163 &= ~ V_164 ;
} else {
V_154 = false ;
F_36 ( & V_42 -> V_29 -> V_30 ,
L_26 ,
V_43 -> V_106 , V_42 -> V_15 . V_78 , V_150 ) ;
}
if ( V_154 ) {
V_125 = F_55 ( & V_9 -> V_14 -> V_15 , & V_153 , NULL ) ;
if ( V_125 ) {
F_33 ( & V_42 -> V_29 -> V_30 ,
L_27 ,
F_52 ( & V_42 -> V_15 , V_125 ) ,
F_53 ( & V_42 -> V_15 ,
V_42 -> V_15 . V_91 . V_127 ) ) ;
}
}
return V_125 ;
}
int F_56 ( struct V_69 * V_43 )
{
int V_49 = 0 ;
enum V_1 V_165 ;
if ( ! V_43 ) {
V_49 = - V_166 ;
goto V_74;
}
if ( strlen ( V_43 -> V_106 ) == 0 ) {
F_57 ( L_28 ) ;
V_49 = - V_166 ;
goto V_74;
}
F_8 ( & V_114 ) ;
if ( F_58 ( V_43 ) ) {
F_57 ( L_29 ,
V_43 -> V_106 ) ;
F_12 ( & V_114 ) ;
V_49 = - V_119 ;
goto V_74;
}
if ( ( V_43 -> V_83 . V_84 != V_85 ) ||
( V_43 -> V_83 . V_86 != V_87 ) ) {
F_57 ( L_30 ,
V_43 -> V_106 ) ;
F_57 ( L_31 ,
V_43 -> V_83 . V_84 , V_43 -> V_83 . V_86 ,
V_43 -> V_83 . V_88 ,
V_167 ) ;
F_12 ( & V_114 ) ;
V_49 = - V_166 ;
goto V_74;
}
V_165 = F_1 ( V_43 -> type ) ;
if ( V_165 == V_7 ) {
F_57 ( L_32 ,
V_43 -> V_106 , V_43 -> type ) ;
F_12 ( & V_114 ) ;
V_49 = - V_166 ;
goto V_74;
}
F_30 ( & V_43 -> V_100 , & V_168 ) ;
F_15 ( V_115 , & V_43 -> V_47 ) ;
F_12 ( & V_114 ) ;
if ( F_43 ( V_43 ) ) {
V_49 = - V_166 ;
goto V_74;
}
F_57 ( L_33 ,
V_43 -> V_106 , V_49 ) ;
V_74:
return V_49 ;
}
int F_59 ( struct V_69 * V_43 )
{
int V_49 = 0 ;
F_8 ( & V_114 ) ;
if ( ! V_43 || F_40 ( V_43 ) ) {
V_49 = - V_166 ;
goto V_74;
}
if ( ! F_58 ( V_43 ) ) {
F_57 ( L_34 ,
V_43 -> V_106 ) ;
V_49 = - V_105 ;
goto V_74;
}
F_21 ( V_115 , & V_43 -> V_47 ) ;
F_34 ( & V_43 -> V_100 ) ;
F_57 ( L_35 ,
V_43 -> V_106 , V_49 ) ;
V_74:
F_12 ( & V_114 ) ;
return V_49 ;
}
