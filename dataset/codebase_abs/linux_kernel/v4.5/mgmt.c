static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 < F_2 ( V_2 ) )
return V_2 [ V_1 ] ;
return V_3 ;
}
static int F_3 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 , int V_9 )
{
return F_4 ( V_4 , V_6 , V_10 , V_7 , V_8 ,
V_9 , NULL ) ;
}
static int F_5 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 , int V_9 , struct V_11 * V_12 )
{
return F_4 ( V_4 , V_6 , V_10 , V_7 , V_8 ,
V_9 , V_12 ) ;
}
static int F_6 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 , struct V_11 * V_12 )
{
return F_4 ( V_4 , V_6 , V_10 , V_7 , V_8 ,
V_13 , V_12 ) ;
}
static int F_7 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 , T_2 V_8 ,
struct V_11 * V_12 )
{
return F_4 ( V_4 , V_6 , V_10 , V_7 , V_8 ,
V_14 , V_12 ) ;
}
static T_1 F_8 ( T_1 V_15 )
{
if ( V_15 == V_16 )
return V_17 ;
else
return V_18 ;
}
static int F_9 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_20 )
{
struct V_21 V_22 ;
F_10 ( L_1 , V_19 ) ;
V_22 . V_23 = V_24 ;
V_22 . V_25 = F_11 ( V_26 ) ;
return F_12 ( V_19 , V_27 , V_28 , 0 ,
& V_22 , sizeof( V_22 ) ) ;
}
static int F_13 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_20 )
{
struct V_29 * V_22 ;
T_2 V_30 , V_31 ;
T_3 V_32 ;
int V_33 , V_34 ;
F_10 ( L_1 , V_19 ) ;
if ( F_14 ( V_19 , V_14 ) ) {
V_30 = F_2 ( V_35 ) ;
V_31 = F_2 ( V_36 ) ;
} else {
V_30 = F_2 ( V_37 ) ;
V_31 = F_2 ( V_38 ) ;
}
V_32 = sizeof( * V_22 ) + ( ( V_30 + V_31 ) * sizeof( T_2 ) ) ;
V_22 = F_15 ( V_32 , V_39 ) ;
if ( ! V_22 )
return - V_40 ;
V_22 -> V_30 = F_11 ( V_30 ) ;
V_22 -> V_31 = F_11 ( V_31 ) ;
if ( F_14 ( V_19 , V_14 ) ) {
T_4 * V_41 = V_22 -> V_42 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ , V_41 ++ )
F_16 ( V_35 [ V_33 ] , V_41 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_41 ++ )
F_16 ( V_36 [ V_33 ] , V_41 ) ;
} else {
T_4 * V_41 = V_22 -> V_42 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ , V_41 ++ )
F_16 ( V_37 [ V_33 ] , V_41 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_41 ++ )
F_16 ( V_38 [ V_33 ] , V_41 ) ;
}
V_34 = F_12 ( V_19 , V_27 , V_43 , 0 ,
V_22 , V_32 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static int F_18 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_20 )
{
struct V_44 * V_22 ;
struct V_5 * V_45 ;
T_3 V_46 ;
T_2 V_47 ;
int V_34 ;
F_10 ( L_1 , V_19 ) ;
F_19 ( & V_48 ) ;
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( V_45 -> V_49 == V_50 &&
! F_21 ( V_45 , V_51 ) )
V_47 ++ ;
}
V_46 = sizeof( * V_22 ) + ( 2 * V_47 ) ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 ) {
F_22 ( & V_48 ) ;
return - V_40 ;
}
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( F_21 ( V_45 , V_53 ) ||
F_21 ( V_45 , V_54 ) ||
F_21 ( V_45 , V_55 ) )
continue;
if ( F_23 ( V_56 , & V_45 -> V_57 ) )
continue;
if ( V_45 -> V_49 == V_50 &&
! F_21 ( V_45 , V_51 ) ) {
V_22 -> V_58 [ V_47 ++ ] = F_11 ( V_45 -> V_59 ) ;
F_10 ( L_2 , V_45 -> V_59 ) ;
}
}
V_22 -> V_60 = F_11 ( V_47 ) ;
V_46 = sizeof( * V_22 ) + ( 2 * V_47 ) ;
F_22 ( & V_48 ) ;
V_34 = F_12 ( V_19 , V_27 , V_61 ,
0 , V_22 , V_46 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static int F_24 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_62 * V_22 ;
struct V_5 * V_45 ;
T_3 V_46 ;
T_2 V_47 ;
int V_34 ;
F_10 ( L_1 , V_19 ) ;
F_19 ( & V_48 ) ;
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( V_45 -> V_49 == V_50 &&
F_21 ( V_45 , V_51 ) )
V_47 ++ ;
}
V_46 = sizeof( * V_22 ) + ( 2 * V_47 ) ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 ) {
F_22 ( & V_48 ) ;
return - V_40 ;
}
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( F_21 ( V_45 , V_53 ) ||
F_21 ( V_45 , V_54 ) ||
F_21 ( V_45 , V_55 ) )
continue;
if ( F_23 ( V_56 , & V_45 -> V_57 ) )
continue;
if ( V_45 -> V_49 == V_50 &&
F_21 ( V_45 , V_51 ) ) {
V_22 -> V_58 [ V_47 ++ ] = F_11 ( V_45 -> V_59 ) ;
F_10 ( L_2 , V_45 -> V_59 ) ;
}
}
V_22 -> V_60 = F_11 ( V_47 ) ;
V_46 = sizeof( * V_22 ) + ( 2 * V_47 ) ;
F_22 ( & V_48 ) ;
V_34 = F_12 ( V_19 , V_27 ,
V_63 , 0 , V_22 , V_46 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static int F_25 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_64 * V_22 ;
struct V_5 * V_45 ;
T_3 V_46 ;
T_2 V_47 ;
int V_34 ;
F_10 ( L_1 , V_19 ) ;
F_19 ( & V_48 ) ;
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( V_45 -> V_49 == V_50 || V_45 -> V_49 == V_65 )
V_47 ++ ;
}
V_46 = sizeof( * V_22 ) + ( sizeof( V_22 -> V_66 [ 0 ] ) * V_47 ) ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 ) {
F_22 ( & V_48 ) ;
return - V_40 ;
}
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( F_21 ( V_45 , V_53 ) ||
F_21 ( V_45 , V_54 ) ||
F_21 ( V_45 , V_55 ) )
continue;
if ( F_23 ( V_56 , & V_45 -> V_57 ) )
continue;
if ( V_45 -> V_49 == V_50 ) {
if ( F_21 ( V_45 , V_51 ) )
V_22 -> V_66 [ V_47 ] . type = 0x01 ;
else
V_22 -> V_66 [ V_47 ] . type = 0x00 ;
} else if ( V_45 -> V_49 == V_65 ) {
V_22 -> V_66 [ V_47 ] . type = 0x02 ;
} else {
continue;
}
V_22 -> V_66 [ V_47 ] . V_67 = V_45 -> V_67 ;
V_22 -> V_66 [ V_47 ++ ] . V_58 = F_11 ( V_45 -> V_59 ) ;
F_10 ( L_2 , V_45 -> V_59 ) ;
}
V_22 -> V_60 = F_11 ( V_47 ) ;
V_46 = sizeof( * V_22 ) + ( sizeof( V_22 -> V_66 [ 0 ] ) * V_47 ) ;
F_22 ( & V_48 ) ;
F_26 ( V_19 , V_68 ) ;
F_27 ( V_19 , V_69 ) ;
F_27 ( V_19 , V_70 ) ;
V_34 = F_12 ( V_19 , V_27 ,
V_71 , 0 , V_22 , V_46 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static bool F_28 ( struct V_5 * V_6 )
{
if ( F_23 ( V_72 , & V_6 -> V_57 ) &&
! F_21 ( V_6 , V_73 ) )
return false ;
if ( F_23 ( V_74 , & V_6 -> V_57 ) &&
! F_29 ( & V_6 -> V_75 , V_76 ) )
return false ;
return true ;
}
static T_5 F_30 ( struct V_5 * V_6 )
{
T_6 V_77 = 0 ;
if ( F_23 ( V_72 , & V_6 -> V_57 ) &&
! F_21 ( V_6 , V_73 ) )
V_77 |= V_78 ;
if ( F_23 ( V_74 , & V_6 -> V_57 ) &&
! F_29 ( & V_6 -> V_75 , V_76 ) )
V_77 |= V_79 ;
return F_31 ( V_77 ) ;
}
static int F_32 ( struct V_5 * V_6 , struct V_11 * V_80 )
{
T_5 V_77 = F_30 ( V_6 ) ;
return F_6 ( V_81 , V_6 , & V_77 ,
sizeof( V_77 ) , V_80 ) ;
}
static int F_33 ( struct V_11 * V_19 , T_2 V_41 , struct V_5 * V_6 )
{
T_5 V_77 = F_30 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_41 , 0 , & V_77 ,
sizeof( V_77 ) ) ;
}
static int F_34 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_82 V_22 ;
T_6 V_77 = 0 ;
F_10 ( L_3 , V_19 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_84 = F_11 ( V_6 -> V_84 ) ;
if ( F_23 ( V_72 , & V_6 -> V_57 ) )
V_77 |= V_78 ;
if ( V_6 -> V_85 )
V_77 |= V_79 ;
V_22 . V_86 = F_31 ( V_77 ) ;
V_22 . V_87 = F_30 ( V_6 ) ;
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_88 , 0 ,
& V_22 , sizeof( V_22 ) ) ;
}
static T_6 F_37 ( struct V_5 * V_6 )
{
T_6 V_89 = 0 ;
V_89 |= V_90 ;
V_89 |= V_91 ;
V_89 |= V_92 ;
V_89 |= V_93 ;
V_89 |= V_94 ;
if ( F_38 ( V_6 ) ) {
if ( V_6 -> V_95 >= V_96 )
V_89 |= V_97 ;
V_89 |= V_98 ;
V_89 |= V_99 ;
if ( F_39 ( V_6 ) ) {
V_89 |= V_100 ;
V_89 |= V_101 ;
}
if ( F_40 ( V_6 ) )
V_89 |= V_102 ;
}
if ( F_41 ( V_6 ) ) {
V_89 |= V_103 ;
V_89 |= V_104 ;
V_89 |= V_102 ;
V_89 |= V_105 ;
V_89 |= V_106 ;
}
if ( F_23 ( V_72 , & V_6 -> V_57 ) ||
V_6 -> V_85 )
V_89 |= V_107 ;
return V_89 ;
}
static T_6 F_42 ( struct V_5 * V_6 )
{
T_6 V_89 = 0 ;
if ( F_43 ( V_6 ) )
V_89 |= V_90 ;
if ( F_21 ( V_6 , V_108 ) )
V_89 |= V_93 ;
if ( F_21 ( V_6 , V_109 ) )
V_89 |= V_97 ;
if ( F_21 ( V_6 , V_110 ) )
V_89 |= V_94 ;
if ( F_21 ( V_6 , V_111 ) )
V_89 |= V_91 ;
if ( F_21 ( V_6 , V_112 ) )
V_89 |= V_98 ;
if ( F_21 ( V_6 , V_113 ) )
V_89 |= V_103 ;
if ( F_21 ( V_6 , V_114 ) )
V_89 |= V_99 ;
if ( F_21 ( V_6 , V_115 ) )
V_89 |= V_100 ;
if ( F_21 ( V_6 , V_116 ) )
V_89 |= V_101 ;
if ( F_21 ( V_6 , V_117 ) )
V_89 |= V_104 ;
if ( F_21 ( V_6 , V_118 ) )
V_89 |= V_102 ;
if ( F_21 ( V_6 , V_119 ) )
V_89 |= V_92 ;
if ( F_21 ( V_6 , V_120 ) )
V_89 |= V_105 ;
if ( F_21 ( V_6 , V_121 ) ||
! F_21 ( V_6 , V_112 ) ||
! F_29 ( & V_6 -> V_122 , V_76 ) ) {
if ( F_29 ( & V_6 -> V_123 , V_76 ) )
V_89 |= V_106 ;
}
return V_89 ;
}
static struct V_124 * F_44 ( T_2 V_41 , struct V_5 * V_6 )
{
return F_45 ( V_10 , V_41 , V_6 ) ;
}
static struct V_124 * F_46 ( T_2 V_41 ,
struct V_5 * V_6 ,
const void * V_7 )
{
return F_47 ( V_10 , V_41 , V_6 , V_7 ) ;
}
T_1 F_48 ( struct V_5 * V_6 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_126 , V_6 ) ;
if ( V_125 ) {
struct V_127 * V_128 = V_125 -> V_129 ;
if ( V_128 -> V_130 == 0x01 )
return V_131 ;
else if ( V_128 -> V_130 == 0x02 )
return V_132 ;
} else {
if ( F_21 ( V_6 , V_133 ) )
return V_132 ;
else if ( F_21 ( V_6 , V_110 ) )
return V_131 ;
}
return 0 ;
}
bool F_49 ( struct V_5 * V_6 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_134 , V_6 ) ;
if ( V_125 ) {
struct V_127 * V_128 = V_125 -> V_129 ;
return V_128 -> V_130 ;
}
return F_21 ( V_6 , V_108 ) ;
}
static void F_50 ( struct V_135 * V_136 )
{
struct V_5 * V_6 = F_51 ( V_136 , struct V_5 ,
V_137 . V_136 ) ;
struct V_138 V_139 ;
if ( ! F_52 ( V_6 , V_140 ) )
return;
F_53 ( & V_139 , V_6 ) ;
F_35 ( V_6 ) ;
F_54 ( & V_139 ) ;
F_55 ( & V_139 ) ;
F_36 ( V_6 ) ;
F_56 ( & V_139 , NULL ) ;
}
static void F_57 ( struct V_135 * V_136 )
{
struct V_5 * V_6 = F_51 ( V_136 , struct V_5 ,
F_57 . V_136 ) ;
struct V_138 V_139 ;
F_10 ( L_4 ) ;
F_58 ( V_6 , V_141 ) ;
if ( ! F_21 ( V_6 , V_117 ) )
return;
F_53 ( & V_139 , V_6 ) ;
F_59 ( & V_139 ) ;
F_56 ( & V_139 , NULL ) ;
}
static void F_60 ( struct V_11 * V_19 , struct V_5 * V_6 )
{
if ( F_61 ( V_6 , V_142 ) )
return;
F_62 ( & V_6 -> V_137 , F_50 ) ;
F_62 ( & V_6 -> F_57 , F_57 ) ;
F_63 ( V_6 , V_111 ) ;
}
static int F_64 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_143 V_22 ;
F_10 ( L_3 , V_19 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_122 , & V_6 -> V_122 ) ;
V_22 . V_23 = V_6 -> V_95 ;
V_22 . V_84 = F_11 ( V_6 -> V_84 ) ;
V_22 . V_144 = F_31 ( F_37 ( V_6 ) ) ;
V_22 . V_145 = F_31 ( F_42 ( V_6 ) ) ;
memcpy ( V_22 . V_146 , V_6 -> V_146 , 3 ) ;
memcpy ( V_22 . V_83 , V_6 -> V_147 , sizeof( V_6 -> V_147 ) ) ;
memcpy ( V_22 . V_148 , V_6 -> V_148 , sizeof( V_6 -> V_148 ) ) ;
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_149 , 0 , & V_22 ,
sizeof( V_22 ) ) ;
}
static int F_66 ( struct V_11 * V_19 , T_2 V_41 , struct V_5 * V_6 )
{
T_5 V_89 = F_31 ( F_42 ( V_6 ) ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_41 , 0 , & V_89 ,
sizeof( V_89 ) ) ;
}
static void F_67 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
F_10 ( L_5 , V_6 -> V_83 , V_150 ) ;
if ( F_68 ( V_6 ) == 0 ) {
F_69 ( & V_6 -> V_151 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_151 . V_136 ) ;
}
}
void F_71 ( struct V_11 * V_19 , struct V_5 * V_6 , T_1 V_153 )
{
struct V_154 V_155 ;
V_155 . V_153 = V_153 ;
F_7 ( V_156 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
}
void F_72 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_1 V_153 )
{
struct V_157 V_155 ;
V_155 . V_153 = V_153 ;
F_7 ( V_158 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
}
static void F_73 ( struct V_5 * V_6 )
{
if ( V_6 -> V_159 ) {
V_6 -> V_159 = 0 ;
F_69 ( & V_6 -> V_160 ) ;
}
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
struct V_161 * V_162 ;
bool V_163 ;
int V_34 ;
F_53 ( & V_139 , V_6 ) ;
if ( F_23 ( V_164 , & V_6 -> V_165 ) ||
F_23 ( V_166 , & V_6 -> V_165 ) ) {
T_1 V_167 = 0x00 ;
F_75 ( & V_139 , V_168 , 1 , & V_167 ) ;
}
F_76 ( V_6 , NULL , 0x00 , false ) ;
if ( F_21 ( V_6 , V_169 ) )
F_77 ( & V_139 ) ;
V_163 = F_78 ( & V_139 ) ;
F_20 (conn, &hdev->conn_hash.list, list) {
F_79 ( & V_139 , V_162 , 0x15 ) ;
}
V_34 = F_56 ( & V_139 , F_67 ) ;
if ( ! V_34 && V_163 )
F_80 ( V_6 , V_170 ) ;
return V_34 ;
}
static int F_81 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_171 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_171 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_171 ,
V_173 ) ;
goto V_174;
}
if ( ! ! V_128 -> V_130 == F_43 ( V_6 ) ) {
V_34 = F_66 ( V_19 , V_171 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_171 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
if ( V_128 -> V_130 ) {
F_70 ( V_6 -> V_152 , & V_6 -> V_175 ) ;
V_34 = 0 ;
} else {
V_34 = F_74 ( V_6 ) ;
if ( ! V_34 )
F_84 ( V_6 -> V_152 , & V_6 -> V_151 ,
V_176 ) ;
if ( V_34 == - V_177 ) {
F_69 ( & V_6 -> V_151 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_151 . V_136 ) ;
V_34 = 0 ;
}
}
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_85 ( struct V_5 * V_6 , struct V_11 * V_80 )
{
T_5 V_155 = F_31 ( F_42 ( V_6 ) ) ;
return F_6 ( V_178 , V_6 , & V_155 ,
sizeof( V_155 ) , V_80 ) ;
}
int F_86 ( struct V_5 * V_6 )
{
return F_85 ( V_6 , NULL ) ;
}
static void F_87 ( struct V_124 * V_125 , void * V_7 )
{
struct V_179 * V_180 = V_7 ;
F_66 ( V_125 -> V_19 , V_125 -> V_41 , V_180 -> V_6 ) ;
F_88 ( & V_125 -> V_181 ) ;
if ( V_180 -> V_19 == NULL ) {
V_180 -> V_19 = V_125 -> V_19 ;
F_89 ( V_180 -> V_19 ) ;
}
F_90 ( V_125 ) ;
}
static void F_91 ( struct V_124 * V_125 , void * V_7 )
{
T_1 * V_150 = V_7 ;
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , * V_150 ) ;
F_92 ( V_125 ) ;
}
static void F_93 ( struct V_124 * V_125 , void * V_7 )
{
if ( V_125 -> V_182 ) {
T_1 * V_150 = V_7 ;
V_125 -> V_182 ( V_125 , * V_150 ) ;
F_92 ( V_125 ) ;
return;
}
F_91 ( V_125 , V_7 ) ;
}
static int F_94 ( struct V_124 * V_125 , T_1 V_150 )
{
return F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_150 ,
V_125 -> V_129 , V_125 -> V_183 ) ;
}
static int F_95 ( struct V_124 * V_125 , T_1 V_150 )
{
return F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_150 ,
V_125 -> V_129 , sizeof( struct V_184 ) ) ;
}
static T_1 F_96 ( struct V_5 * V_6 )
{
if ( ! F_38 ( V_6 ) )
return V_185 ;
else if ( ! F_21 ( V_6 , V_112 ) )
return V_186 ;
else
return V_187 ;
}
static T_1 F_97 ( struct V_5 * V_6 )
{
if ( ! F_41 ( V_6 ) )
return V_185 ;
else if ( ! F_21 ( V_6 , V_113 ) )
return V_186 ;
else
return V_187 ;
}
void F_98 ( struct V_5 * V_6 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_7 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_126 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_189 ) ;
F_63 ( V_6 , V_133 ) ;
goto V_190;
}
if ( F_21 ( V_6 , V_110 ) &&
V_6 -> V_191 > 0 ) {
int V_192 = F_99 ( V_6 -> V_191 * 1000 ) ;
F_84 ( V_6 -> V_152 , & V_6 -> V_193 , V_192 ) ;
}
F_66 ( V_125 -> V_19 , V_126 , V_6 ) ;
F_85 ( V_6 , V_125 -> V_19 ) ;
V_190:
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_100 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_194 * V_128 = V_7 ;
struct V_124 * V_125 ;
T_2 V_195 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_21 ( V_6 , V_113 ) &&
! F_21 ( V_6 , V_112 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_126 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_126 ,
V_172 ) ;
V_195 = F_101 ( V_128 -> V_195 ) ;
if ( ( V_128 -> V_130 == 0x00 && V_195 > 0 ) ||
( V_128 -> V_130 == 0x02 && V_195 == 0 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_126 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) && V_195 > 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_126 ,
V_196 ) ;
goto V_174;
}
if ( F_44 ( V_126 , V_6 ) ||
F_44 ( V_134 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_126 ,
V_173 ) ;
goto V_174;
}
if ( ! F_21 ( V_6 , V_108 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_126 ,
V_186 ) ;
goto V_174;
}
if ( ! F_43 ( V_6 ) ) {
bool V_197 = false ;
if ( ! ! V_128 -> V_130 != F_21 ( V_6 , V_110 ) ) {
F_102 ( V_6 , V_110 ) ;
V_197 = true ;
}
V_34 = F_66 ( V_19 , V_126 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( ! ! V_128 -> V_130 == F_21 ( V_6 , V_110 ) &&
( V_128 -> V_130 == 0x02 ) == F_21 ( V_6 ,
V_133 ) ) {
F_69 ( & V_6 -> V_193 ) ;
V_6 -> V_191 = V_195 ;
if ( V_128 -> V_130 && V_6 -> V_191 > 0 ) {
int V_192 = F_99 ( V_6 -> V_191 * 1000 ) ;
F_84 ( V_6 -> V_152 ,
& V_6 -> V_193 , V_192 ) ;
}
V_34 = F_66 ( V_19 , V_126 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_126 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
F_69 ( & V_6 -> V_193 ) ;
V_6 -> V_191 = V_195 ;
if ( V_128 -> V_130 )
F_58 ( V_6 , V_110 ) ;
else
F_63 ( V_6 , V_110 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_133 ) ;
else
F_63 ( V_6 , V_133 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_198 ) ;
V_34 = 0 ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
void F_103 ( struct V_5 * V_6 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_7 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_134 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_189 ) ;
goto V_190;
}
F_66 ( V_125 -> V_19 , V_134 , V_6 ) ;
F_85 ( V_6 , V_125 -> V_19 ) ;
V_190:
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_104 ( struct V_5 * V_6 ,
struct V_11 * V_19 , T_1 V_130 )
{
bool V_197 = false ;
int V_34 ;
if ( ! ! V_130 != F_21 ( V_6 , V_108 ) )
V_197 = true ;
if ( V_130 ) {
F_58 ( V_6 , V_108 ) ;
} else {
F_63 ( V_6 , V_108 ) ;
F_63 ( V_6 , V_110 ) ;
}
V_34 = F_66 ( V_19 , V_134 , V_6 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_197 ) {
F_105 ( V_6 ) ;
F_106 ( V_6 ) ;
return F_85 ( V_6 , V_19 ) ;
}
return 0 ;
}
static int F_107 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_21 ( V_6 , V_113 ) &&
! F_21 ( V_6 , V_112 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_134 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_134 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_104 ( V_6 , V_19 , V_128 -> V_130 ) ;
goto V_174;
}
if ( F_44 ( V_126 , V_6 ) ||
F_44 ( V_134 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_134 ,
V_173 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_134 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
if ( V_128 -> V_130 ) {
F_58 ( V_6 , V_108 ) ;
} else {
if ( V_6 -> V_191 > 0 )
F_69 ( & V_6 -> V_193 ) ;
F_63 ( V_6 , V_133 ) ;
F_63 ( V_6 , V_110 ) ;
F_63 ( V_6 , V_108 ) ;
}
F_70 ( V_6 -> V_152 , & V_6 -> V_199 ) ;
V_34 = 0 ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_108 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
bool V_197 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_200 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_130 )
V_197 = ! F_61 ( V_6 , V_111 ) ;
else
V_197 = F_52 ( V_6 , V_111 ) ;
V_34 = F_66 ( V_19 , V_200 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_109 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
T_1 V_130 , V_150 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
V_150 = F_96 ( V_6 ) ;
if ( V_150 )
return F_82 ( V_19 , V_6 -> V_59 , V_201 ,
V_150 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_201 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_197 = false ;
if ( ! ! V_128 -> V_130 != F_21 ( V_6 , V_114 ) ) {
F_102 ( V_6 , V_114 ) ;
V_197 = true ;
}
V_34 = F_66 ( V_19 , V_201 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( F_44 ( V_201 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_201 ,
V_173 ) ;
goto V_174;
}
V_130 = ! ! V_128 -> V_130 ;
if ( F_23 ( V_202 , & V_6 -> V_165 ) == V_130 ) {
V_34 = F_66 ( V_19 , V_201 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_201 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_34 = F_110 ( V_6 , V_203 , sizeof( V_130 ) , & V_130 ) ;
if ( V_34 < 0 ) {
F_92 ( V_125 ) ;
goto V_174;
}
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_111 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
V_150 = F_96 ( V_6 ) ;
if ( V_150 )
return F_82 ( V_19 , V_6 -> V_59 , V_204 , V_150 ) ;
if ( ! F_39 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_204 ,
V_185 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_204 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_197 ;
if ( V_128 -> V_130 ) {
V_197 = ! F_61 ( V_6 ,
V_115 ) ;
} else {
V_197 = F_52 ( V_6 ,
V_115 ) ;
if ( ! V_197 )
V_197 = F_52 ( V_6 ,
V_116 ) ;
else
F_63 ( V_6 , V_116 ) ;
}
V_34 = F_66 ( V_19 , V_204 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( F_44 ( V_204 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_204 ,
V_173 ) ;
goto V_174;
}
if ( ! ! V_128 -> V_130 == F_21 ( V_6 , V_115 ) ) {
V_34 = F_66 ( V_19 , V_204 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_204 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
if ( ! V_128 -> V_130 && F_21 ( V_6 , V_205 ) )
F_110 ( V_6 , V_206 ,
sizeof( V_128 -> V_130 ) , & V_128 -> V_130 ) ;
V_34 = F_110 ( V_6 , V_207 , 1 , & V_128 -> V_130 ) ;
if ( V_34 < 0 ) {
F_92 ( V_125 ) ;
goto V_174;
}
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_112 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
bool V_197 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
V_150 = F_96 ( V_6 ) ;
if ( V_150 )
return F_82 ( V_19 , V_6 -> V_59 , V_208 , V_150 ) ;
if ( ! F_39 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_208 ,
V_185 ) ;
if ( ! F_21 ( V_6 , V_115 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_208 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_208 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_204 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_208 ,
V_173 ) ;
goto V_188;
}
if ( V_128 -> V_130 ) {
V_197 = ! F_61 ( V_6 , V_116 ) ;
} else {
if ( F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_208 ,
V_186 ) ;
goto V_188;
}
V_197 = F_52 ( V_6 , V_116 ) ;
}
V_34 = F_66 ( V_19 , V_208 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_113 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
struct V_179 V_180 = { NULL , V_6 } ;
F_35 ( V_6 ) ;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_114 ( V_209 , V_6 , F_91 ,
& V_189 ) ;
goto V_188;
}
F_114 ( V_209 , V_6 , F_87 , & V_180 ) ;
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
if ( F_21 ( V_6 , V_113 ) ) {
struct V_138 V_139 ;
F_53 ( & V_139 , V_6 ) ;
F_116 ( & V_139 , 0x00 ) ;
F_117 ( & V_139 , 0x00 ) ;
F_56 ( & V_139 , NULL ) ;
F_106 ( V_6 ) ;
}
V_188:
F_36 ( V_6 ) ;
}
static int F_118 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_210 V_211 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
T_1 V_130 , V_212 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_185 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_172 ) ;
if ( ! F_21 ( V_6 , V_112 ) ) {
if ( V_128 -> V_130 == 0x01 )
return F_66 ( V_19 , V_209 , V_6 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_186 ) ;
}
F_35 ( V_6 ) ;
V_130 = ! ! V_128 -> V_130 ;
V_212 = F_119 ( V_6 ) ;
if ( ! V_130 )
F_76 ( V_6 , NULL , 0x00 , true ) ;
if ( ! F_43 ( V_6 ) || V_130 == V_212 ) {
bool V_197 = false ;
if ( V_130 != F_21 ( V_6 , V_113 ) ) {
F_102 ( V_6 , V_113 ) ;
V_197 = true ;
}
if ( ! V_130 && F_21 ( V_6 , V_117 ) ) {
F_63 ( V_6 , V_117 ) ;
V_197 = true ;
}
V_34 = F_66 ( V_19 , V_209 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_188;
}
if ( F_44 ( V_209 , V_6 ) ||
F_44 ( V_213 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_209 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
if ( V_130 ) {
V_211 . V_214 = V_130 ;
V_211 . V_215 = 0x00 ;
} else {
if ( F_21 ( V_6 , V_169 ) )
F_77 ( & V_139 ) ;
}
F_75 ( & V_139 , V_216 , sizeof( V_211 ) ,
& V_211 ) ;
V_34 = F_56 ( & V_139 , F_113 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_120 ( struct V_5 * V_6 )
{
struct V_124 * V_125 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
switch ( V_125 -> V_41 ) {
case V_217 :
case V_218 :
case V_219 :
case V_171 :
return true ;
}
}
return false ;
}
static T_1 F_121 ( const T_1 * V_220 )
{
T_6 V_130 ;
if ( memcmp ( V_220 , V_221 , 12 ) )
return 128 ;
V_130 = F_122 ( & V_220 [ 12 ] ) ;
if ( V_130 > 0xffff )
return 32 ;
return 16 ;
}
static void F_123 ( struct V_5 * V_6 , T_2 V_222 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_222 , V_6 ) ;
if ( ! V_125 )
goto V_188;
F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 ,
F_1 ( V_150 ) , V_6 -> V_146 , 3 ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static void F_124 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
F_10 ( L_7 , V_150 ) ;
F_123 ( V_6 , V_217 , V_150 ) ;
}
static int F_125 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_223 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
struct V_224 * V_220 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_120 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_217 ,
V_173 ) ;
goto V_174;
}
V_220 = F_15 ( sizeof( * V_220 ) , V_39 ) ;
if ( ! V_220 ) {
V_34 = - V_40 ;
goto V_174;
}
memcpy ( V_220 -> V_220 , V_128 -> V_220 , 16 ) ;
V_220 -> V_225 = V_128 -> V_225 ;
V_220 -> V_226 = F_121 ( V_128 -> V_220 ) ;
F_126 ( & V_220 -> V_181 , & V_6 -> V_227 ) ;
F_53 ( & V_139 , V_6 ) ;
F_55 ( & V_139 ) ;
F_54 ( & V_139 ) ;
V_34 = F_56 ( & V_139 , F_124 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_177 )
goto V_174;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_217 , 0 ,
V_6 -> V_146 , 3 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_217 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_34 = 0 ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_127 ( struct V_5 * V_6 )
{
if ( ! F_43 ( V_6 ) )
return false ;
if ( ! F_61 ( V_6 , V_140 ) ) {
F_84 ( V_6 -> V_228 , & V_6 -> V_137 ,
V_229 ) ;
return true ;
}
return false ;
}
static void F_128 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
F_10 ( L_7 , V_150 ) ;
F_123 ( V_6 , V_218 , V_150 ) ;
}
static int F_129 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_230 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_224 * V_180 , * V_231 ;
T_1 V_232 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_138 V_139 ;
int V_34 , V_233 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_120 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_218 ,
V_173 ) ;
goto V_188;
}
if ( memcmp ( V_128 -> V_220 , V_232 , 16 ) == 0 ) {
F_130 ( V_6 ) ;
if ( F_127 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_218 ,
0 , V_6 -> V_146 , 3 ) ;
goto V_188;
}
goto V_234;
}
V_233 = 0 ;
F_131 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_180 -> V_220 , V_128 -> V_220 , 16 ) != 0 )
continue;
F_88 ( & V_180 -> V_181 ) ;
F_17 ( V_180 ) ;
V_233 ++ ;
}
if ( V_233 == 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_218 ,
V_172 ) ;
goto V_188;
}
V_234:
F_53 ( & V_139 , V_6 ) ;
F_55 ( & V_139 ) ;
F_54 ( & V_139 ) ;
V_34 = F_56 ( & V_139 , F_128 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_177 )
goto V_188;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_218 , 0 ,
V_6 -> V_146 , 3 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_218 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_34 = 0 ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_132 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
F_10 ( L_7 , V_150 ) ;
F_123 ( V_6 , V_219 , V_150 ) ;
}
static int F_133 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_235 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_219 ,
V_185 ) ;
F_35 ( V_6 ) ;
if ( F_120 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_219 ,
V_173 ) ;
goto V_188;
}
if ( ( V_128 -> V_236 & 0x03 ) != 0 || ( V_128 -> V_237 & 0xe0 ) != 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_219 ,
V_172 ) ;
goto V_188;
}
V_6 -> V_238 = V_128 -> V_237 ;
V_6 -> V_239 = V_128 -> V_236 ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_219 , 0 ,
V_6 -> V_146 , 3 ) ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
if ( F_52 ( V_6 , V_140 ) ) {
F_36 ( V_6 ) ;
F_134 ( & V_6 -> V_137 ) ;
F_35 ( V_6 ) ;
F_54 ( & V_139 ) ;
}
F_55 ( & V_139 ) ;
V_34 = F_56 ( & V_139 , F_132 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_177 )
goto V_188;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_219 , 0 ,
V_6 -> V_146 , 3 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_219 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_34 = 0 ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_135 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_240 * V_128 = V_7 ;
const T_2 V_241 = ( ( V_242 - sizeof( * V_128 ) ) /
sizeof( struct V_243 ) ) ;
T_2 V_244 , V_245 ;
bool V_197 ;
int V_33 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_246 ,
V_185 ) ;
V_244 = F_101 ( V_128 -> V_244 ) ;
if ( V_244 > V_241 ) {
F_136 ( L_8 ,
V_244 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_246 ,
V_172 ) ;
}
V_245 = sizeof( * V_128 ) + V_244 *
sizeof( struct V_243 ) ;
if ( V_245 != V_8 ) {
F_136 ( L_9 ,
V_245 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_246 ,
V_172 ) ;
}
if ( V_128 -> V_247 != 0x00 && V_128 -> V_247 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_246 ,
V_172 ) ;
F_10 ( L_10 , V_6 -> V_83 , V_128 -> V_247 ,
V_244 ) ;
for ( V_33 = 0 ; V_33 < V_244 ; V_33 ++ ) {
struct V_243 * V_248 = & V_128 -> V_249 [ V_33 ] ;
if ( V_248 -> V_250 . type != V_251 || V_248 -> type > 0x08 )
return F_82 ( V_19 , V_6 -> V_59 ,
V_246 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_137 ( V_6 ) ;
if ( V_128 -> V_247 )
V_197 = ! F_61 ( V_6 , V_119 ) ;
else
V_197 = F_52 ( V_6 ,
V_119 ) ;
if ( V_197 )
F_85 ( V_6 , NULL ) ;
for ( V_33 = 0 ; V_33 < V_244 ; V_33 ++ ) {
struct V_243 * V_248 = & V_128 -> V_249 [ V_33 ] ;
if ( V_248 -> type == V_252 )
continue;
F_138 ( V_6 , NULL , & V_248 -> V_250 . V_122 , V_248 -> V_130 ,
V_248 -> type , V_248 -> V_253 , NULL ) ;
}
F_12 ( V_19 , V_6 -> V_59 , V_246 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int F_139 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_254 , struct V_11 * V_12 )
{
struct V_255 V_155 ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = V_254 ;
return F_7 ( V_256 , V_6 , & V_155 , sizeof( V_155 ) ,
V_12 ) ;
}
static int F_140 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_257 * V_128 = V_7 ;
struct V_258 V_22 ;
struct V_259 * V_260 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
T_1 V_254 ;
int V_34 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_250 . V_122 , & V_128 -> V_250 . V_122 ) ;
V_22 . V_250 . type = V_128 -> V_250 . type ;
if ( ! F_141 ( V_128 -> V_250 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_261 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_128 -> V_262 != 0x00 && V_128 -> V_262 != 0x01 )
return F_12 ( V_19 , V_6 -> V_59 , V_261 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_261 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( V_128 -> V_250 . type == V_251 ) {
if ( V_128 -> V_262 )
V_162 = F_142 ( V_6 , V_263 ,
& V_128 -> V_250 . V_122 ) ;
else
V_162 = NULL ;
V_34 = F_143 ( V_6 , & V_128 -> V_250 . V_122 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_261 ,
V_264 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
goto V_265;
}
V_254 = F_8 ( V_128 -> V_250 . type ) ;
F_144 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ) ;
V_34 = F_145 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_261 ,
V_264 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
V_162 = F_146 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ) ;
if ( ! V_162 ) {
F_147 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ) ;
goto V_265;
}
F_148 ( V_162 ) ;
F_149 ( V_266 , & V_162 -> V_165 ) ;
V_260 = F_150 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ) ;
if ( V_260 ) {
if ( V_260 -> V_267 )
V_260 -> V_268 = V_269 ;
else
V_260 -> V_268 = V_270 ;
}
if ( ! V_128 -> V_262 )
V_162 = NULL ;
V_265:
if ( ! V_162 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_261 , 0 ,
& V_22 , sizeof( V_22 ) ) ;
F_139 ( V_6 , & V_128 -> V_250 . V_122 , V_128 -> V_250 . type , V_19 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_261 , V_6 , V_128 ,
sizeof( * V_128 ) ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_125 -> V_182 = F_95 ;
V_34 = F_151 ( V_162 , V_271 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int V_262 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_272 * V_128 = V_7 ;
struct V_273 V_22 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_4 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_250 . V_122 , & V_128 -> V_250 . V_122 ) ;
V_22 . V_250 . type = V_128 -> V_250 . type ;
if ( ! F_141 ( V_128 -> V_250 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_274 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_23 ( V_275 , & V_6 -> V_165 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_274 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_174;
}
if ( F_44 ( V_274 , V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_274 ,
V_173 , & V_22 , sizeof( V_22 ) ) ;
goto V_174;
}
if ( V_128 -> V_250 . type == V_251 )
V_162 = F_142 ( V_6 , V_263 ,
& V_128 -> V_250 . V_122 ) ;
else
V_162 = F_146 ( V_6 , & V_128 -> V_250 . V_122 ,
F_8 ( V_128 -> V_250 . type ) ) ;
if ( ! V_162 || V_162 -> V_276 == V_277 || V_162 -> V_276 == V_278 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_274 ,
V_279 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_274 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_94 ;
V_34 = F_152 ( V_162 , V_271 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static T_1 F_153 ( T_1 V_280 , T_1 V_254 )
{
switch ( V_280 ) {
case V_281 :
switch ( V_254 ) {
case V_17 :
return V_16 ;
default:
return V_282 ;
}
default:
return V_251 ;
}
}
static int F_154 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_20 )
{
struct V_283 * V_22 ;
struct V_161 * V_284 ;
T_3 V_46 ;
int V_34 ;
T_2 V_33 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_285 ,
V_196 ) ;
goto V_188;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_23 ( V_286 , & V_284 -> V_165 ) )
V_33 ++ ;
}
V_46 = sizeof( * V_22 ) + ( V_33 * sizeof( struct V_184 ) ) ;
V_22 = F_15 ( V_46 , V_39 ) ;
if ( ! V_22 ) {
V_34 = - V_40 ;
goto V_188;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_23 ( V_286 , & V_284 -> V_165 ) )
continue;
F_65 ( & V_22 -> V_250 [ V_33 ] . V_122 , & V_284 -> V_287 ) ;
V_22 -> V_250 [ V_33 ] . type = F_153 ( V_284 -> type , V_284 -> V_288 ) ;
if ( V_284 -> type == V_289 || V_284 -> type == V_290 )
continue;
V_33 ++ ;
}
V_22 -> V_291 = F_11 ( V_33 ) ;
V_46 = sizeof( * V_22 ) + ( V_33 * sizeof( struct V_184 ) ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_285 , 0 , V_22 ,
V_46 ) ;
F_17 ( V_22 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_155 ( struct V_11 * V_19 , struct V_5 * V_6 ,
struct V_292 * V_128 )
{
struct V_124 * V_125 ;
int V_34 ;
V_125 = F_83 ( V_19 , V_293 , V_6 , V_128 ,
sizeof( * V_128 ) ) ;
if ( ! V_125 )
return - V_40 ;
V_34 = F_110 ( V_6 , V_294 ,
sizeof( V_128 -> V_250 . V_122 ) , & V_128 -> V_250 . V_122 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
return V_34 ;
}
static int F_156 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_162 ;
struct V_295 * V_128 = V_7 ;
struct V_296 V_297 ;
struct V_124 * V_125 ;
int V_34 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_298 ,
V_196 ) ;
goto V_174;
}
V_162 = F_142 ( V_6 , V_263 , & V_128 -> V_250 . V_122 ) ;
if ( ! V_162 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_298 ,
V_279 ) ;
goto V_174;
}
if ( V_162 -> V_299 == V_300 && V_128 -> V_253 != 16 ) {
struct V_292 V_301 ;
memcpy ( & V_301 . V_250 , & V_128 -> V_250 , sizeof( V_301 . V_250 ) ) ;
F_136 ( L_11 ) ;
V_34 = F_155 ( V_19 , V_6 , & V_301 ) ;
if ( V_34 >= 0 )
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_298 ,
V_172 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_298 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_95 ;
F_65 ( & V_297 . V_122 , & V_128 -> V_250 . V_122 ) ;
V_297 . V_253 = V_128 -> V_253 ;
memcpy ( V_297 . V_302 , V_128 -> V_302 , sizeof( V_297 . V_302 ) ) ;
V_34 = F_110 ( V_6 , V_303 , sizeof( V_297 ) , & V_297 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_157 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_304 * V_128 = V_7 ;
F_10 ( L_4 ) ;
if ( V_128 -> V_305 > V_306 )
return F_12 ( V_19 , V_6 -> V_59 , V_307 ,
V_172 , NULL , 0 ) ;
F_35 ( V_6 ) ;
V_6 -> V_305 = V_128 -> V_305 ;
F_10 ( L_12 , V_6 -> V_83 ,
V_6 -> V_305 ) ;
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_307 , 0 ,
NULL , 0 ) ;
}
static struct V_124 * F_158 ( struct V_161 * V_162 )
{
struct V_5 * V_6 = V_162 -> V_6 ;
struct V_124 * V_125 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_125 -> V_41 != V_308 )
continue;
if ( V_125 -> V_309 != V_162 )
continue;
return V_125 ;
}
return NULL ;
}
static int F_159 ( struct V_124 * V_125 , T_1 V_150 )
{
struct V_310 V_22 ;
struct V_161 * V_162 = V_125 -> V_309 ;
int V_34 ;
F_65 ( & V_22 . V_250 . V_122 , & V_162 -> V_287 ) ;
V_22 . V_250 . type = F_153 ( V_162 -> type , V_162 -> V_288 ) ;
V_34 = F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_308 ,
V_150 , & V_22 , sizeof( V_22 ) ) ;
V_162 -> V_311 = NULL ;
V_162 -> V_312 = NULL ;
V_162 -> V_313 = NULL ;
F_160 ( V_162 ) ;
F_161 ( V_266 , & V_162 -> V_165 ) ;
F_162 ( V_162 ) ;
return V_34 ;
}
void F_163 ( struct V_161 * V_162 , bool V_314 )
{
T_1 V_150 = V_314 ? V_187 : V_3 ;
struct V_124 * V_125 ;
V_125 = F_158 ( V_162 ) ;
if ( V_125 ) {
V_125 -> V_182 ( V_125 , V_150 ) ;
F_92 ( V_125 ) ;
}
}
static void F_164 ( struct V_161 * V_162 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_13 , V_150 ) ;
V_125 = F_158 ( V_162 ) ;
if ( ! V_125 ) {
F_10 ( L_14 ) ;
return;
}
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
static void F_165 ( struct V_161 * V_162 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_13 , V_150 ) ;
if ( ! V_150 )
return;
V_125 = F_158 ( V_162 ) ;
if ( ! V_125 ) {
F_10 ( L_14 ) ;
return;
}
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
static int F_166 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_315 * V_128 = V_7 ;
struct V_310 V_22 ;
struct V_124 * V_125 ;
T_1 V_316 , V_317 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_4 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_250 . V_122 , & V_128 -> V_250 . V_122 ) ;
V_22 . V_250 . type = V_128 -> V_250 . type ;
if ( ! F_141 ( V_128 -> V_250 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_128 -> V_318 > V_306 )
return F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( F_167 ( V_6 , & V_128 -> V_250 . V_122 , V_128 -> V_250 . type ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_319 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
V_316 = V_320 ;
V_317 = V_321 ;
if ( V_128 -> V_250 . type == V_251 ) {
V_162 = F_168 ( V_6 , & V_128 -> V_250 . V_122 , V_316 ,
V_317 ) ;
} else {
T_1 V_254 = F_8 ( V_128 -> V_250 . type ) ;
struct V_259 * V_322 ;
V_322 = F_169 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ) ;
if ( V_322 -> V_268 == V_269 )
V_322 -> V_268 = V_270 ;
V_162 = F_170 ( V_6 , & V_128 -> V_250 . V_122 ,
V_254 , V_316 ,
V_323 ) ;
}
if ( F_171 ( V_162 ) ) {
int V_150 ;
if ( F_172 ( V_162 ) == - V_324 )
V_150 = V_173 ;
else if ( F_172 ( V_162 ) == - V_325 )
V_150 = V_185 ;
else if ( F_172 ( V_162 ) == - V_326 )
V_150 = V_186 ;
else
V_150 = V_327 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_150 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
if ( V_162 -> V_311 ) {
F_160 ( V_162 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_173 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_308 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
F_160 ( V_162 ) ;
goto V_188;
}
V_125 -> V_182 = F_159 ;
if ( V_128 -> V_250 . type == V_251 ) {
V_162 -> V_311 = F_164 ;
V_162 -> V_312 = F_164 ;
V_162 -> V_313 = F_164 ;
} else {
V_162 -> V_311 = F_165 ;
V_162 -> V_312 = F_165 ;
V_162 -> V_313 = F_165 ;
}
V_162 -> V_305 = V_128 -> V_318 ;
V_125 -> V_309 = F_173 ( V_162 ) ;
if ( ( V_162 -> V_276 == V_328 || V_162 -> V_276 == V_329 ) &&
F_174 ( V_162 , V_316 , V_317 , true ) ) {
V_125 -> V_182 ( V_125 , 0 ) ;
F_92 ( V_125 ) ;
}
V_34 = 0 ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_175 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_184 * V_250 = V_7 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_330 ,
V_196 ) ;
goto V_188;
}
V_125 = F_44 ( V_308 , V_6 ) ;
if ( ! V_125 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_330 ,
V_172 ) ;
goto V_188;
}
V_162 = V_125 -> V_309 ;
if ( F_29 ( & V_250 -> V_122 , & V_162 -> V_287 ) != 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_330 ,
V_172 ) ;
goto V_188;
}
V_125 -> V_182 ( V_125 , V_331 ) ;
F_92 ( V_125 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_330 , 0 ,
V_250 , sizeof( * V_250 ) ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_176 ( struct V_11 * V_19 , struct V_5 * V_6 ,
struct V_184 * V_250 , T_2 V_222 ,
T_2 V_332 , T_5 V_333 )
{
struct V_124 * V_125 ;
struct V_161 * V_162 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_222 ,
V_196 , V_250 ,
sizeof( * V_250 ) ) ;
goto V_265;
}
if ( V_250 -> type == V_251 )
V_162 = F_142 ( V_6 , V_263 , & V_250 -> V_122 ) ;
else
V_162 = F_146 ( V_6 , & V_250 -> V_122 ,
F_8 ( V_250 -> type ) ) ;
if ( ! V_162 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_222 ,
V_279 , V_250 ,
sizeof( * V_250 ) ) ;
goto V_265;
}
if ( V_250 -> type == V_16 || V_250 -> type == V_282 ) {
V_34 = F_177 ( V_162 , V_222 , V_333 ) ;
if ( ! V_34 )
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_222 ,
V_187 , V_250 ,
sizeof( * V_250 ) ) ;
else
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_222 ,
V_3 , V_250 ,
sizeof( * V_250 ) ) ;
goto V_265;
}
V_125 = F_83 ( V_19 , V_222 , V_6 , V_250 , sizeof( * V_250 ) ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_265;
}
V_125 -> V_182 = F_95 ;
if ( V_332 == V_334 ) {
struct V_335 V_128 ;
F_65 ( & V_128 . V_122 , & V_250 -> V_122 ) ;
V_128 . V_333 = V_333 ;
V_34 = F_110 ( V_6 , V_332 , sizeof( V_128 ) , & V_128 ) ;
} else
V_34 = F_110 ( V_6 , V_332 , sizeof( V_250 -> V_122 ) ,
& V_250 -> V_122 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_265:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_178 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_292 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_250 ,
V_293 ,
V_294 , 0 ) ;
}
static int F_179 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_336 * V_128 = V_7 ;
F_10 ( L_4 ) ;
if ( V_8 != sizeof( * V_128 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_337 ,
V_172 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_250 ,
V_337 ,
V_338 , 0 ) ;
}
static int F_180 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_339 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_250 ,
V_340 ,
V_341 , 0 ) ;
}
static int F_181 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_342 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_250 ,
V_343 ,
V_334 , V_128 -> V_333 ) ;
}
static int F_182 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_344 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_250 ,
V_345 ,
V_346 , 0 ) ;
}
static void F_183 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
struct V_347 * V_128 ;
struct V_124 * V_125 ;
F_10 ( L_7 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_348 , V_6 ) ;
if ( ! V_125 )
goto V_188;
V_128 = V_125 -> V_129 ;
if ( V_150 )
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_348 ,
F_1 ( V_150 ) ) ;
else
F_12 ( V_125 -> V_19 , V_6 -> V_59 , V_348 , 0 ,
V_128 , sizeof( * V_128 ) ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_184 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_347 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_147 , V_128 -> V_83 , sizeof( V_6 -> V_147 ) ) &&
! memcmp ( V_6 -> V_148 , V_128 -> V_148 ,
sizeof( V_6 -> V_148 ) ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_348 , 0 ,
V_7 , V_8 ) ;
goto V_174;
}
memcpy ( V_6 -> V_148 , V_128 -> V_148 , sizeof( V_6 -> V_148 ) ) ;
if ( ! F_43 ( V_6 ) ) {
memcpy ( V_6 -> V_147 , V_128 -> V_83 , sizeof( V_6 -> V_147 ) ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_348 , 0 ,
V_7 , V_8 ) ;
if ( V_34 < 0 )
goto V_174;
V_34 = F_6 ( V_349 , V_6 ,
V_7 , V_8 , V_19 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_348 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
memcpy ( V_6 -> V_147 , V_128 -> V_83 , sizeof( V_6 -> V_147 ) ) ;
F_53 ( & V_139 , V_6 ) ;
if ( F_38 ( V_6 ) ) {
F_185 ( & V_139 ) ;
F_54 ( & V_139 ) ;
}
if ( F_41 ( V_6 ) )
F_117 ( & V_139 , V_6 -> V_350 ) ;
V_34 = F_56 ( & V_139 , F_183 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_186 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 , struct V_351 * V_352 )
{
struct V_353 V_354 ;
T_3 V_32 = sizeof( V_354 ) ;
struct V_124 * V_125 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
V_125 = F_44 ( V_355 , V_6 ) ;
if ( ! V_125 )
return;
if ( V_150 || ! V_352 ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_355 ,
V_150 ? F_1 ( V_150 ) : V_3 ) ;
goto remove;
}
memset ( & V_354 , 0 , sizeof( V_354 ) ) ;
if ( V_41 == V_356 ) {
struct V_357 * V_22 = ( void * ) V_352 -> V_7 ;
if ( V_352 -> V_8 < sizeof( * V_22 ) ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 ,
V_355 ,
V_3 ) ;
goto remove;
}
memcpy ( V_354 . V_358 , V_22 -> V_359 , sizeof( V_22 -> V_359 ) ) ;
memcpy ( V_354 . V_360 , V_22 -> rand , sizeof( V_22 -> rand ) ) ;
V_32 -= sizeof( V_354 . V_361 ) + sizeof( V_354 . V_362 ) ;
} else {
struct V_363 * V_22 = ( void * ) V_352 -> V_7 ;
if ( V_352 -> V_8 < sizeof( * V_22 ) ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 ,
V_355 ,
V_3 ) ;
goto remove;
}
memcpy ( V_354 . V_358 , V_22 -> V_358 , sizeof( V_22 -> V_358 ) ) ;
memcpy ( V_354 . V_360 , V_22 -> V_360 , sizeof( V_22 -> V_360 ) ) ;
memcpy ( V_354 . V_361 , V_22 -> V_361 , sizeof( V_22 -> V_361 ) ) ;
memcpy ( V_354 . V_362 , V_22 -> V_362 , sizeof( V_22 -> V_362 ) ) ;
}
F_12 ( V_125 -> V_19 , V_6 -> V_59 , V_355 ,
V_187 , & V_354 , V_32 ) ;
remove:
F_92 ( V_125 ) ;
}
static int F_187 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_355 ,
V_196 ) ;
goto V_188;
}
if ( ! F_39 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_355 ,
V_185 ) ;
goto V_188;
}
if ( F_44 ( V_355 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_355 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_355 , V_6 , NULL , 0 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
if ( F_188 ( V_6 ) )
F_75 ( & V_139 , V_364 , 0 , NULL ) ;
else
F_75 ( & V_139 , V_356 , 0 , NULL ) ;
V_34 = F_189 ( & V_139 , F_186 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_190 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_184 * V_250 = V_7 ;
int V_34 ;
F_10 ( L_17 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_250 -> type ) )
return F_12 ( V_19 , V_6 -> V_59 ,
V_365 ,
V_172 ,
V_250 , sizeof( * V_250 ) ) ;
F_35 ( V_6 ) ;
if ( V_8 == V_366 ) {
struct V_367 * V_128 = V_7 ;
T_1 V_150 ;
if ( V_128 -> V_250 . type != V_251 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_365 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
V_34 = F_191 ( V_6 , & V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type , V_128 -> V_359 ,
V_128 -> rand , NULL , NULL ) ;
if ( V_34 < 0 )
V_150 = V_3 ;
else
V_150 = V_187 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_365 , V_150 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
} else if ( V_8 == V_368 ) {
struct V_369 * V_128 = V_7 ;
T_1 * V_360 , * V_358 , * V_362 , * V_361 ;
T_1 V_150 ;
if ( F_192 ( V_128 -> V_250 . type ) ) {
if ( memcmp ( V_128 -> V_360 , V_370 , 16 ) ||
memcmp ( V_128 -> V_358 , V_370 , 16 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_365 ,
V_172 ,
V_250 , sizeof( * V_250 ) ) ;
goto V_188;
}
V_360 = NULL ;
V_358 = NULL ;
} else {
if ( ! memcmp ( V_128 -> V_360 , V_370 , 16 ) ||
! memcmp ( V_128 -> V_358 , V_370 , 16 ) ) {
V_360 = NULL ;
V_358 = NULL ;
} else {
V_360 = V_128 -> V_360 ;
V_358 = V_128 -> V_358 ;
}
}
if ( ! memcmp ( V_128 -> V_362 , V_370 , 16 ) ||
! memcmp ( V_128 -> V_361 , V_370 , 16 ) ) {
V_362 = NULL ;
V_361 = NULL ;
} else {
V_362 = V_128 -> V_362 ;
V_361 = V_128 -> V_361 ;
}
V_34 = F_191 ( V_6 , & V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type , V_358 , V_360 ,
V_361 , V_362 ) ;
if ( V_34 < 0 )
V_150 = V_3 ;
else
V_150 = V_187 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_365 ,
V_150 , & V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
} else {
F_136 ( L_18 , V_8 ) ;
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_365 ,
V_172 ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_193 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_371 * V_128 = V_7 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( V_128 -> V_250 . type != V_251 )
return F_12 ( V_19 , V_6 -> V_59 ,
V_372 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_29 ( & V_128 -> V_250 . V_122 , V_76 ) ) {
F_194 ( V_6 ) ;
V_150 = V_187 ;
goto V_265;
}
V_34 = F_195 ( V_6 , & V_128 -> V_250 . V_122 , V_128 -> V_250 . type ) ;
if ( V_34 < 0 )
V_150 = V_172 ;
else
V_150 = V_187 ;
V_265:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_372 ,
V_150 , & V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
void F_196 ( struct V_5 * V_6 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_373 , V_6 ) ;
if ( ! V_125 )
V_125 = F_44 ( V_374 , V_6 ) ;
if ( ! V_125 )
V_125 = F_44 ( V_375 , V_6 ) ;
if ( V_125 ) {
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
F_36 ( V_6 ) ;
}
static bool F_197 ( struct V_5 * V_6 , T_8 type ,
T_8 * F_1 )
{
switch ( type ) {
case V_376 :
* F_1 = F_97 ( V_6 ) ;
if ( * F_1 )
return false ;
break;
case V_377 :
* F_1 = F_97 ( V_6 ) ;
if ( * F_1 )
return false ;
case V_378 :
* F_1 = F_96 ( V_6 ) ;
if ( * F_1 )
return false ;
break;
default:
* F_1 = V_172 ;
return false ;
}
return true ;
}
static int F_198 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_2 V_379 , void * V_7 , T_2 V_8 )
{
struct V_380 * V_128 = V_7 ;
struct V_124 * V_125 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_379 ,
V_196 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( V_6 -> V_381 . V_276 != V_382 ||
F_21 ( V_6 , V_383 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_379 , V_173 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( ! F_197 ( V_6 , V_128 -> type , & V_150 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_379 , V_150 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
F_199 ( V_6 ) ;
V_6 -> V_381 . type = V_128 -> type ;
V_6 -> V_381 . V_384 = false ;
if ( V_379 == V_375 )
V_6 -> V_381 . V_385 = true ;
else
V_6 -> V_381 . V_385 = false ;
V_125 = F_83 ( V_19 , V_379 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_94 ;
F_80 ( V_6 , V_386 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_387 ) ;
V_34 = 0 ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_200 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
return F_198 ( V_19 , V_6 , V_373 ,
V_7 , V_8 ) ;
}
static int F_201 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
return F_198 ( V_19 , V_6 ,
V_375 ,
V_7 , V_8 ) ;
}
static int F_202 ( struct V_124 * V_125 ,
T_1 V_150 )
{
return F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_150 ,
V_125 -> V_129 , 1 ) ;
}
static int F_203 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_388 * V_128 = V_7 ;
struct V_124 * V_125 ;
const T_2 V_389 = ( ( V_242 - sizeof( * V_128 ) ) / 16 ) ;
T_2 V_390 , V_245 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_374 ,
V_196 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( V_6 -> V_381 . V_276 != V_382 ||
F_21 ( V_6 , V_383 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_374 ,
V_173 , & V_128 -> type ,
sizeof( V_128 -> type ) ) ;
goto V_174;
}
V_390 = F_101 ( V_128 -> V_390 ) ;
if ( V_390 > V_389 ) {
F_136 ( L_20 ,
V_390 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_374 ,
V_172 , & V_128 -> type ,
sizeof( V_128 -> type ) ) ;
goto V_174;
}
V_245 = sizeof( * V_128 ) + V_390 * 16 ;
if ( V_245 != V_8 ) {
F_136 ( L_21 ,
V_245 , V_8 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_374 ,
V_172 , & V_128 -> type ,
sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( ! F_197 ( V_6 , V_128 -> type , & V_150 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_374 ,
V_150 , & V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_374 ,
V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_202 ;
F_199 ( V_6 ) ;
V_6 -> V_381 . V_391 = true ;
V_6 -> V_381 . type = V_128 -> type ;
V_6 -> V_381 . V_392 = V_128 -> V_392 ;
V_6 -> V_381 . V_390 = V_390 ;
if ( V_390 > 0 ) {
V_6 -> V_381 . V_227 = F_204 ( V_128 -> V_227 , V_390 * 16 ,
V_39 ) ;
if ( ! V_6 -> V_381 . V_227 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_374 ,
V_3 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
F_92 ( V_125 ) ;
goto V_174;
}
}
F_80 ( V_6 , V_386 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_387 ) ;
V_34 = 0 ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
void F_205 ( struct V_5 * V_6 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_393 , V_6 ) ;
if ( V_125 ) {
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
F_36 ( V_6 ) ;
}
static int F_206 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_394 * V_395 = V_7 ;
struct V_124 * V_125 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_207 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_393 ,
V_186 , & V_395 -> type ,
sizeof( V_395 -> type ) ) ;
goto V_188;
}
if ( V_6 -> V_381 . type != V_395 -> type ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_393 ,
V_172 ,
& V_395 -> type , sizeof( V_395 -> type ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_393 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_125 -> V_182 = F_94 ;
F_80 ( V_6 , V_170 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_387 ) ;
V_34 = 0 ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_208 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_396 * V_128 = V_7 ;
struct V_397 * V_398 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_207 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_399 ,
V_3 , & V_128 -> V_250 ,
sizeof( V_128 -> V_250 ) ) ;
goto V_174;
}
V_398 = F_209 ( V_6 , & V_128 -> V_250 . V_122 ) ;
if ( ! V_398 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_399 ,
V_172 , & V_128 -> V_250 ,
sizeof( V_128 -> V_250 ) ) ;
goto V_174;
}
if ( V_128 -> V_400 ) {
V_398 -> V_401 = V_402 ;
F_88 ( & V_398 -> V_181 ) ;
} else {
V_398 -> V_401 = V_403 ;
F_210 ( V_6 , V_398 ) ;
}
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_399 , 0 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_211 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_404 * V_128 = V_7 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_128 -> V_250 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_405 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_212 ( & V_6 -> V_406 , & V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type ) ;
if ( V_34 < 0 ) {
V_150 = V_3 ;
goto V_265;
}
F_7 ( V_407 , V_6 , & V_128 -> V_250 , sizeof( V_128 -> V_250 ) ,
V_19 ) ;
V_150 = V_187 ;
V_265:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_405 , V_150 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_213 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_408 * V_128 = V_7 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_128 -> V_250 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_409 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_214 ( & V_6 -> V_406 , & V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type ) ;
if ( V_34 < 0 ) {
V_150 = V_172 ;
goto V_265;
}
F_7 ( V_410 , V_6 , & V_128 -> V_250 , sizeof( V_128 -> V_250 ) ,
V_19 ) ;
V_150 = V_187 ;
V_265:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_409 , V_150 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_215 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_411 * V_128 = V_7 ;
struct V_138 V_139 ;
int V_34 ;
T_9 V_412 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
V_412 = F_101 ( V_128 -> V_412 ) ;
if ( V_412 > 0x0002 )
return F_82 ( V_19 , V_6 -> V_59 , V_413 ,
V_172 ) ;
F_35 ( V_6 ) ;
V_6 -> V_414 = V_412 ;
V_6 -> V_415 = F_101 ( V_128 -> V_416 ) ;
V_6 -> V_417 = F_101 ( V_128 -> V_418 ) ;
V_6 -> V_419 = F_101 ( V_128 -> V_23 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_413 , 0 ,
NULL , 0 ) ;
F_53 ( & V_139 , V_6 ) ;
F_54 ( & V_139 ) ;
F_56 ( & V_139 , NULL ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_216 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 )
{
F_10 ( L_19 , V_150 ) ;
}
static void F_217 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 )
{
struct V_179 V_180 = { NULL , V_6 } ;
struct V_138 V_139 ;
T_1 V_153 ;
struct V_420 * V_421 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_114 ( V_213 , V_6 ,
F_91 , & V_189 ) ;
goto V_188;
}
if ( F_21 ( V_6 , V_169 ) )
F_58 ( V_6 , V_117 ) ;
else
F_63 ( V_6 , V_117 ) ;
F_114 ( V_213 , V_6 , F_87 ,
& V_180 ) ;
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
if ( F_21 ( V_6 , V_117 ) ||
F_218 ( & V_6 -> V_422 ) )
goto V_188;
V_153 = V_6 -> V_350 ;
if ( ! V_153 ) {
V_421 = F_219 ( & V_6 -> V_422 ,
struct V_420 , V_181 ) ;
if ( ! V_421 )
goto V_188;
V_153 = V_421 -> V_153 ;
}
F_53 ( & V_139 , V_6 ) ;
V_34 = F_220 ( & V_139 , V_153 , true ) ;
if ( ! V_34 )
V_34 = F_56 ( & V_139 , F_216 ) ;
if ( V_34 )
F_136 ( L_22 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_221 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
T_1 V_130 , V_150 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
V_150 = F_97 ( V_6 ) ;
if ( V_150 )
return F_82 ( V_19 , V_6 -> V_59 , V_213 ,
V_150 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_213 ,
V_172 ) ;
F_35 ( V_6 ) ;
V_130 = ! ! V_128 -> V_130 ;
if ( ! F_43 ( V_6 ) ||
( V_130 == F_21 ( V_6 , V_117 ) &&
( V_128 -> V_130 == 0x02 ) == F_21 ( V_6 , V_423 ) ) ||
F_222 ( V_6 , V_281 ) > 0 ||
( F_21 ( V_6 , V_424 ) &&
V_6 -> V_425 == V_426 ) ) {
bool V_197 ;
if ( V_128 -> V_130 ) {
V_6 -> V_350 = 0x00 ;
V_197 = ! F_61 ( V_6 , V_117 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_423 ) ;
else
F_63 ( V_6 , V_423 ) ;
} else {
V_197 = F_52 ( V_6 , V_117 ) ;
F_63 ( V_6 , V_423 ) ;
}
V_34 = F_66 ( V_19 , V_213 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_188;
}
if ( F_44 ( V_213 , V_6 ) ||
F_44 ( V_209 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_213 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_213 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_423 ) ;
else
F_63 ( V_6 , V_423 ) ;
F_73 ( V_6 ) ;
if ( V_130 ) {
V_6 -> V_350 = 0x00 ;
F_116 ( & V_139 , 0x00 ) ;
F_117 ( & V_139 , 0x00 ) ;
F_59 ( & V_139 ) ;
} else {
F_77 ( & V_139 ) ;
}
V_34 = F_56 ( & V_139 , F_217 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_223 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_427 * V_128 = V_7 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_428 ,
V_185 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_428 ,
V_186 ) ;
if ( F_29 ( & V_128 -> V_122 , V_76 ) ) {
if ( ! F_29 ( & V_128 -> V_122 , V_429 ) )
return F_82 ( V_19 , V_6 -> V_59 ,
V_428 ,
V_172 ) ;
if ( ( V_128 -> V_122 . V_430 [ 5 ] & 0xc0 ) != 0xc0 )
return F_82 ( V_19 , V_6 -> V_59 ,
V_428 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_65 ( & V_6 -> V_123 , & V_128 -> V_122 ) ;
V_34 = F_66 ( V_19 , V_428 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_224 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_431 * V_128 = V_7 ;
T_9 V_432 , V_433 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_434 ,
V_185 ) ;
V_432 = F_101 ( V_128 -> V_432 ) ;
if ( V_432 < 0x0004 || V_432 > 0x4000 )
return F_82 ( V_19 , V_6 -> V_59 , V_434 ,
V_172 ) ;
V_433 = F_101 ( V_128 -> V_433 ) ;
if ( V_433 < 0x0004 || V_433 > 0x4000 )
return F_82 ( V_19 , V_6 -> V_59 , V_434 ,
V_172 ) ;
if ( V_433 > V_432 )
return F_82 ( V_19 , V_6 -> V_59 , V_434 ,
V_172 ) ;
F_35 ( V_6 ) ;
V_6 -> V_435 = V_432 ;
V_6 -> V_436 = V_433 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_434 , 0 ,
NULL , 0 ) ;
if ( F_21 ( V_6 , V_424 ) &&
V_6 -> V_381 . V_276 == V_382 ) {
struct V_138 V_139 ;
F_53 ( & V_139 , V_6 ) ;
F_225 ( & V_139 ) ;
F_226 ( & V_139 ) ;
F_56 ( & V_139 , NULL ) ;
}
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_227 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 )
{
struct V_124 * V_125 ;
F_10 ( L_7 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_437 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_437 ,
F_1 ( V_150 ) ) ;
} else {
struct V_127 * V_128 = V_125 -> V_129 ;
if ( V_128 -> V_130 )
F_58 ( V_6 , V_109 ) ;
else
F_63 ( V_6 , V_109 ) ;
F_66 ( V_125 -> V_19 , V_437 , V_6 ) ;
F_85 ( V_6 , V_125 -> V_19 ) ;
}
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_228 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_21 ( V_6 , V_112 ) ||
V_6 -> V_95 < V_96 )
return F_82 ( V_19 , V_6 -> V_59 , V_437 ,
V_185 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_437 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_437 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_437 ,
V_173 ) ;
goto V_188;
}
if ( ! ! V_128 -> V_130 == F_21 ( V_6 , V_109 ) ) {
V_34 = F_66 ( V_19 , V_437 ,
V_6 ) ;
goto V_188;
}
if ( ! F_43 ( V_6 ) ) {
F_102 ( V_6 , V_109 ) ;
V_34 = F_66 ( V_19 , V_437 ,
V_6 ) ;
F_85 ( V_6 , V_19 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_437 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
F_229 ( & V_139 , V_128 -> V_130 ) ;
V_34 = F_56 ( & V_139 , F_227 ) ;
if ( V_34 < 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_437 ,
V_3 ) ;
F_92 ( V_125 ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_230 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
struct V_124 * V_125 ;
F_10 ( L_7 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_438 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_63 ( V_6 , V_112 ) ;
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_189 ) ;
} else {
F_66 ( V_125 -> V_19 , V_438 , V_6 ) ;
F_85 ( V_6 , V_125 -> V_19 ) ;
}
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_231 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) || ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_185 ) ;
if ( ! F_21 ( V_6 , V_113 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_130 == F_21 ( V_6 , V_112 ) ) {
V_34 = F_66 ( V_19 , V_438 , V_6 ) ;
goto V_188;
}
if ( ! F_43 ( V_6 ) ) {
if ( ! V_128 -> V_130 ) {
F_63 ( V_6 , V_110 ) ;
F_63 ( V_6 , V_115 ) ;
F_63 ( V_6 , V_114 ) ;
F_63 ( V_6 , V_109 ) ;
F_63 ( V_6 , V_116 ) ;
}
F_102 ( V_6 , V_112 ) ;
V_34 = F_66 ( V_19 , V_438 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_188;
}
if ( ! V_128 -> V_130 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_186 ) ;
goto V_188;
} else {
if ( ! F_21 ( V_6 , V_112 ) &&
( F_29 ( & V_6 -> V_123 , V_76 ) ||
F_21 ( V_6 , V_118 ) ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_186 ) ;
goto V_188;
}
}
if ( F_44 ( V_438 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_438 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_58 ( V_6 , V_112 ) ;
F_53 ( & V_139 , V_6 ) ;
F_229 ( & V_139 , false ) ;
F_232 ( & V_139 ) ;
F_116 ( & V_139 , V_6 -> V_350 ) ;
V_34 = F_56 ( & V_139 , F_230 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_233 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
struct V_124 * V_125 ;
struct V_127 * V_128 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_439 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 ,
F_1 ( V_150 ) ) ;
goto remove;
}
V_128 = V_125 -> V_129 ;
switch ( V_128 -> V_130 ) {
case 0x00 :
F_63 ( V_6 , V_118 ) ;
F_63 ( V_6 , V_440 ) ;
break;
case 0x01 :
F_58 ( V_6 , V_118 ) ;
F_63 ( V_6 , V_440 ) ;
break;
case 0x02 :
F_58 ( V_6 , V_118 ) ;
F_58 ( V_6 , V_440 ) ;
break;
}
F_66 ( V_125 -> V_19 , V_439 , V_6 ) ;
F_85 ( V_6 , V_125 -> V_19 ) ;
remove:
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_234 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
T_1 V_130 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_40 ( V_6 ) &&
! F_21 ( V_6 , V_113 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_185 ) ;
if ( F_21 ( V_6 , V_112 ) &&
F_40 ( V_6 ) &&
! F_21 ( V_6 , V_115 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) || ! F_40 ( V_6 ) ||
! F_21 ( V_6 , V_112 ) ) {
bool V_197 ;
if ( V_128 -> V_130 ) {
V_197 = ! F_61 ( V_6 ,
V_118 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_440 ) ;
else
F_63 ( V_6 , V_440 ) ;
} else {
V_197 = F_52 ( V_6 ,
V_118 ) ;
F_63 ( V_6 , V_440 ) ;
}
V_34 = F_66 ( V_19 , V_439 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( F_44 ( V_439 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_173 ) ;
goto V_174;
}
V_130 = ! ! V_128 -> V_130 ;
if ( V_130 == F_21 ( V_6 , V_118 ) &&
( V_128 -> V_130 == 0x02 ) == F_21 ( V_6 , V_440 ) ) {
V_34 = F_66 ( V_19 , V_439 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_439 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
F_53 ( & V_139 , V_6 ) ;
F_75 ( & V_139 , V_441 , 1 , & V_130 ) ;
V_34 = F_56 ( & V_139 , F_233 ) ;
if ( V_34 < 0 ) {
F_92 ( V_125 ) ;
goto V_174;
}
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_235 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_127 * V_128 = V_7 ;
bool V_197 , V_442 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_443 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_130 )
V_197 = ! F_61 ( V_6 , V_119 ) ;
else
V_197 = F_52 ( V_6 ,
V_119 ) ;
if ( V_128 -> V_130 == 0x02 )
V_442 = ! F_61 ( V_6 ,
V_205 ) ;
else
V_442 = F_52 ( V_6 ,
V_205 ) ;
if ( F_43 ( V_6 ) && V_442 &&
F_21 ( V_6 , V_115 ) ) {
T_1 V_444 = ( V_128 -> V_130 == 0x02 ) ? 0x01 : 0x00 ;
F_110 ( V_6 , V_206 ,
sizeof( V_444 ) , & V_444 ) ;
}
V_34 = F_66 ( V_19 , V_443 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_236 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_445 ,
T_2 V_8 )
{
struct V_446 * V_128 = V_445 ;
bool V_197 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_447 ,
V_185 ) ;
if ( V_128 -> V_448 != 0x00 && V_128 -> V_448 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_447 ,
V_172 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_447 ,
V_186 ) ;
F_35 ( V_6 ) ;
F_58 ( V_6 , V_449 ) ;
if ( V_128 -> V_448 ) {
V_197 = ! F_61 ( V_6 , V_120 ) ;
memcpy ( V_6 -> V_450 , V_128 -> V_450 , sizeof( V_6 -> V_450 ) ) ;
F_58 ( V_6 , V_141 ) ;
} else {
V_197 = F_52 ( V_6 , V_120 ) ;
memset ( V_6 -> V_450 , 0 , sizeof( V_6 -> V_450 ) ) ;
F_63 ( V_6 , V_141 ) ;
}
V_34 = F_66 ( V_19 , V_447 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_237 ( struct V_451 * V_450 )
{
switch ( V_450 -> V_250 . type ) {
case V_16 :
return true ;
case V_282 :
if ( ( V_450 -> V_250 . V_122 . V_430 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_238 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_445 ,
T_2 V_8 )
{
struct V_452 * V_128 = V_445 ;
const T_2 V_453 = ( ( V_242 - sizeof( * V_128 ) ) /
sizeof( struct V_451 ) ) ;
T_2 V_454 , V_245 ;
int V_33 , V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_455 ,
V_185 ) ;
V_454 = F_101 ( V_128 -> V_454 ) ;
if ( V_454 > V_453 ) {
F_136 ( L_23 , V_454 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_455 ,
V_172 ) ;
}
V_245 = sizeof( * V_128 ) + V_454 * sizeof( struct V_451 ) ;
if ( V_245 != V_8 ) {
F_136 ( L_24 ,
V_245 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_455 ,
V_172 ) ;
}
F_10 ( L_25 , V_6 -> V_83 , V_454 ) ;
for ( V_33 = 0 ; V_33 < V_454 ; V_33 ++ ) {
struct V_451 * V_248 = & V_128 -> V_456 [ V_33 ] ;
if ( ! F_237 ( V_248 ) )
return F_82 ( V_19 , V_6 -> V_59 ,
V_455 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_239 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_454 ; V_33 ++ ) {
struct V_451 * V_450 = & V_128 -> V_456 [ V_33 ] ;
F_240 ( V_6 , & V_450 -> V_250 . V_122 ,
F_8 ( V_450 -> V_250 . type ) , V_450 -> V_130 ,
V_76 ) ;
}
F_58 ( V_6 , V_449 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_455 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_241 ( struct V_457 * V_248 )
{
if ( V_248 -> V_458 != 0x00 && V_248 -> V_458 != 0x01 )
return false ;
switch ( V_248 -> V_250 . type ) {
case V_16 :
return true ;
case V_282 :
if ( ( V_248 -> V_250 . V_122 . V_430 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_242 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_445 , T_2 V_8 )
{
struct V_459 * V_128 = V_445 ;
const T_2 V_241 = ( ( V_242 - sizeof( * V_128 ) ) /
sizeof( struct V_457 ) ) ;
T_2 V_244 , V_245 ;
int V_33 , V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_460 ,
V_185 ) ;
V_244 = F_101 ( V_128 -> V_244 ) ;
if ( V_244 > V_241 ) {
F_136 ( L_26 , V_244 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_460 ,
V_172 ) ;
}
V_245 = sizeof( * V_128 ) + V_244 *
sizeof( struct V_457 ) ;
if ( V_245 != V_8 ) {
F_136 ( L_27 ,
V_245 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_460 ,
V_172 ) ;
}
F_10 ( L_28 , V_6 -> V_83 , V_244 ) ;
for ( V_33 = 0 ; V_33 < V_244 ; V_33 ++ ) {
struct V_457 * V_248 = & V_128 -> V_249 [ V_33 ] ;
if ( ! F_241 ( V_248 ) )
return F_82 ( V_19 , V_6 -> V_59 ,
V_460 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_243 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_244 ; V_33 ++ ) {
struct V_457 * V_248 = & V_128 -> V_249 [ V_33 ] ;
T_1 type , V_461 ;
switch ( V_248 -> type ) {
case V_462 :
V_461 = 0x00 ;
type = V_248 -> V_458 ? V_463 : V_464 ;
break;
case V_465 :
V_461 = 0x01 ;
type = V_248 -> V_458 ? V_463 : V_464 ;
break;
case V_466 :
V_461 = 0x00 ;
type = V_467 ;
break;
case V_468 :
V_461 = 0x01 ;
type = V_467 ;
break;
case V_469 :
V_461 = 0x00 ;
type = V_470 ;
default:
continue;
}
F_244 ( V_6 , & V_248 -> V_250 . V_122 ,
F_8 ( V_248 -> V_250 . type ) , type , V_461 ,
V_248 -> V_130 , V_248 -> V_471 , V_248 -> V_472 , V_248 -> rand ) ;
}
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_460 , 0 ,
NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_245 ( struct V_124 * V_125 , T_1 V_150 )
{
struct V_161 * V_162 = V_125 -> V_309 ;
struct V_473 V_22 ;
int V_34 ;
memcpy ( & V_22 . V_250 , V_125 -> V_129 , sizeof( V_22 . V_250 ) ) ;
if ( V_150 == V_187 ) {
V_22 . V_392 = V_162 -> V_392 ;
V_22 . V_474 = V_162 -> V_474 ;
V_22 . V_475 = V_162 -> V_475 ;
} else {
V_22 . V_392 = V_476 ;
V_22 . V_474 = V_477 ;
V_22 . V_475 = V_477 ;
}
V_34 = F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_478 ,
V_150 , & V_22 , sizeof( V_22 ) ) ;
F_160 ( V_162 ) ;
F_162 ( V_162 ) ;
return V_34 ;
}
static void F_246 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_41 )
{
struct V_479 * V_128 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
T_2 V_480 ;
T_1 V_150 ;
F_10 ( L_7 , V_1 ) ;
F_35 ( V_6 ) ;
V_128 = F_247 ( V_6 , V_481 ) ;
if ( ! V_128 ) {
V_128 = F_247 ( V_6 , V_482 ) ;
V_150 = V_187 ;
} else {
V_150 = F_1 ( V_1 ) ;
}
if ( ! V_128 ) {
F_136 ( L_29 ) ;
goto V_188;
}
V_480 = F_101 ( V_128 -> V_480 ) ;
V_162 = F_248 ( V_6 , V_480 ) ;
if ( ! V_162 ) {
F_136 ( L_30 , V_480 ) ;
goto V_188;
}
V_125 = F_46 ( V_478 , V_6 , V_162 ) ;
if ( ! V_125 )
goto V_188;
V_125 -> V_182 ( V_125 , V_150 ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_249 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_483 * V_128 = V_7 ;
struct V_473 V_22 ;
struct V_161 * V_162 ;
unsigned long V_484 ;
int V_34 = 0 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_250 . V_122 , & V_128 -> V_250 . V_122 ) ;
V_22 . V_250 . type = V_128 -> V_250 . type ;
if ( ! F_141 ( V_128 -> V_250 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_478 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_478 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( V_128 -> V_250 . type == V_251 )
V_162 = F_142 ( V_6 , V_263 ,
& V_128 -> V_250 . V_122 ) ;
else
V_162 = F_142 ( V_6 , V_281 , & V_128 -> V_250 . V_122 ) ;
if ( ! V_162 || V_162 -> V_276 != V_328 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_478 ,
V_279 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( F_46 ( V_478 , V_6 , V_162 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_478 ,
V_173 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_484 = V_6 -> V_485 +
F_250 ( V_6 -> V_486 -
V_6 -> V_485 ) ;
if ( F_251 ( V_487 , V_162 -> V_488 +
F_99 ( V_484 ) ) ||
! V_162 -> V_488 ) {
struct V_138 V_139 ;
struct V_489 V_490 ;
struct V_479 V_491 ;
struct V_124 * V_125 ;
F_53 ( & V_139 , V_6 ) ;
V_491 . V_480 = F_11 ( V_162 -> V_480 ) ;
F_75 ( & V_139 , V_481 , sizeof( V_491 ) ,
& V_491 ) ;
if ( ! F_192 ( V_128 -> V_250 . type ) ||
V_162 -> V_474 == V_477 ) {
V_490 . V_480 = F_11 ( V_162 -> V_480 ) ;
V_490 . type = 0x00 ;
F_75 ( & V_139 , V_482 ,
sizeof( V_490 ) , & V_490 ) ;
}
if ( V_162 -> V_475 == V_477 ) {
V_490 . V_480 = F_11 ( V_162 -> V_480 ) ;
V_490 . type = 0x01 ;
F_75 ( & V_139 , V_482 ,
sizeof( V_490 ) , & V_490 ) ;
}
V_34 = F_56 ( & V_139 , F_246 ) ;
if ( V_34 < 0 )
goto V_188;
V_125 = F_83 ( V_19 , V_478 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_252 ( V_162 ) ;
V_125 -> V_309 = F_173 ( V_162 ) ;
V_125 -> V_182 = F_245 ;
V_162 -> V_488 = V_487 ;
} else {
V_22 . V_392 = V_162 -> V_392 ;
V_22 . V_474 = V_162 -> V_474 ;
V_22 . V_475 = V_162 -> V_475 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_478 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_253 ( struct V_124 * V_125 , T_1 V_150 )
{
struct V_161 * V_162 = V_125 -> V_309 ;
struct V_492 V_22 ;
struct V_5 * V_6 ;
int V_34 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
memcpy ( & V_22 . V_250 , & V_125 -> V_129 , sizeof( V_22 . V_250 ) ) ;
if ( V_150 )
goto V_314;
V_6 = F_254 ( V_125 -> V_58 ) ;
if ( V_6 ) {
V_22 . V_493 = F_31 ( V_6 -> clock ) ;
F_255 ( V_6 ) ;
}
if ( V_162 ) {
V_22 . V_494 = F_31 ( V_162 -> clock ) ;
V_22 . V_495 = F_11 ( V_162 -> V_496 ) ;
}
V_314:
V_34 = F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_150 , & V_22 ,
sizeof( V_22 ) ) ;
if ( V_162 ) {
F_160 ( V_162 ) ;
F_162 ( V_162 ) ;
}
return V_34 ;
}
static void F_256 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
struct V_497 * V_211 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
F_35 ( V_6 ) ;
V_211 = F_247 ( V_6 , V_498 ) ;
if ( ! V_211 )
goto V_188;
if ( V_211 -> V_499 ) {
T_2 V_480 = F_101 ( V_211 -> V_480 ) ;
V_162 = F_248 ( V_6 , V_480 ) ;
} else {
V_162 = NULL ;
}
V_125 = F_46 ( V_500 , V_6 , V_162 ) ;
if ( ! V_125 )
goto V_188;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_257 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_501 * V_128 = V_7 ;
struct V_492 V_22 ;
struct V_497 V_211 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_250 . V_122 , & V_128 -> V_250 . V_122 ) ;
V_22 . V_250 . type = V_128 -> V_250 . type ;
if ( V_128 -> V_250 . type != V_251 )
return F_12 ( V_19 , V_6 -> V_59 , V_500 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_500 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( F_29 ( & V_128 -> V_250 . V_122 , V_76 ) ) {
V_162 = F_142 ( V_6 , V_263 ,
& V_128 -> V_250 . V_122 ) ;
if ( ! V_162 || V_162 -> V_276 != V_328 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_500 ,
V_279 ,
& V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
} else {
V_162 = NULL ;
}
V_125 = F_83 ( V_19 , V_500 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_125 -> V_182 = F_253 ;
F_53 ( & V_139 , V_6 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
F_75 ( & V_139 , V_498 , sizeof( V_211 ) , & V_211 ) ;
if ( V_162 ) {
F_252 ( V_162 ) ;
V_125 -> V_309 = F_173 ( V_162 ) ;
V_211 . V_480 = F_11 ( V_162 -> V_480 ) ;
V_211 . V_499 = 0x01 ;
F_75 ( & V_139 , V_498 , sizeof( V_211 ) , & V_211 ) ;
}
V_34 = F_56 ( & V_139 , F_256 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_258 ( struct V_5 * V_6 , T_7 * V_250 , T_1 type )
{
struct V_161 * V_162 ;
V_162 = F_142 ( V_6 , V_281 , V_250 ) ;
if ( ! V_162 )
return false ;
if ( V_162 -> V_288 != type )
return false ;
if ( V_162 -> V_276 != V_328 )
return false ;
return true ;
}
static int F_259 ( struct V_5 * V_6 , T_7 * V_250 ,
T_1 V_254 , T_1 V_268 )
{
struct V_259 * V_260 ;
V_260 = F_169 ( V_6 , V_250 , V_254 ) ;
if ( ! V_260 )
return - V_502 ;
if ( V_260 -> V_268 == V_268 )
return 0 ;
F_260 ( & V_260 -> V_503 ) ;
switch ( V_268 ) {
case V_270 :
case V_504 :
if ( V_260 -> V_267 )
F_261 ( & V_260 -> V_503 , & V_6 -> V_505 ) ;
break;
case V_506 :
if ( V_260 -> V_267 )
F_261 ( & V_260 -> V_503 , & V_6 -> V_505 ) ;
else
F_261 ( & V_260 -> V_503 , & V_6 -> V_507 ) ;
break;
case V_508 :
case V_509 :
if ( ! F_258 ( V_6 , V_250 , V_254 ) )
F_261 ( & V_260 -> V_503 , & V_6 -> V_505 ) ;
break;
}
V_260 -> V_268 = V_268 ;
F_10 ( L_31 , V_250 , V_254 ,
V_268 ) ;
return 0 ;
}
static void F_262 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_7 * V_122 , T_1 type , T_1 V_503 )
{
struct V_510 V_155 ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = type ;
V_155 . V_503 = V_503 ;
F_7 ( V_511 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
}
static int F_263 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_512 * V_128 = V_7 ;
T_1 V_513 , V_254 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_128 -> V_250 . type ) ||
! F_29 ( & V_128 -> V_250 . V_122 , V_76 ) )
return F_12 ( V_19 , V_6 -> V_59 , V_514 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
if ( V_128 -> V_503 != 0x00 && V_128 -> V_503 != 0x01 && V_128 -> V_503 != 0x02 )
return F_12 ( V_19 , V_6 -> V_59 , V_514 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_250 . type == V_251 ) {
if ( V_128 -> V_503 != 0x01 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_514 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
V_34 = F_212 ( & V_6 -> V_515 , & V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type ) ;
if ( V_34 )
goto V_188;
F_105 ( V_6 ) ;
goto V_516;
}
V_254 = F_8 ( V_128 -> V_250 . type ) ;
if ( V_128 -> V_503 == 0x02 )
V_513 = V_509 ;
else if ( V_128 -> V_503 == 0x01 )
V_513 = V_508 ;
else
V_513 = V_506 ;
if ( ! F_264 ( & V_128 -> V_250 . V_122 , V_254 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_514 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
if ( F_259 ( V_6 , & V_128 -> V_250 . V_122 , V_254 ,
V_513 ) < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_514 ,
V_3 , & V_128 -> V_250 ,
sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
F_106 ( V_6 ) ;
V_516:
F_262 ( V_19 , V_6 , & V_128 -> V_250 . V_122 , V_128 -> V_250 . type , V_128 -> V_503 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_514 ,
V_187 , & V_128 -> V_250 ,
sizeof( V_128 -> V_250 ) ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_265 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_7 * V_122 , T_1 type )
{
struct V_517 V_155 ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = type ;
F_7 ( V_518 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
}
static int F_266 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_519 * V_128 = V_7 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_29 ( & V_128 -> V_250 . V_122 , V_76 ) ) {
struct V_259 * V_260 ;
T_1 V_254 ;
if ( ! F_141 ( V_128 -> V_250 . type ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_520 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
if ( V_128 -> V_250 . type == V_251 ) {
V_34 = F_214 ( & V_6 -> V_515 ,
& V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type ) ;
if ( V_34 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_520 ,
V_172 ,
& V_128 -> V_250 ,
sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
F_105 ( V_6 ) ;
F_265 ( V_19 , V_6 , & V_128 -> V_250 . V_122 ,
V_128 -> V_250 . type ) ;
goto V_314;
}
V_254 = F_8 ( V_128 -> V_250 . type ) ;
if ( ! F_264 ( & V_128 -> V_250 . V_122 , V_254 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_520 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
V_260 = F_150 ( V_6 , & V_128 -> V_250 . V_122 ,
V_254 ) ;
if ( ! V_260 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_520 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
if ( V_260 -> V_268 == V_270 ||
V_260 -> V_268 == V_269 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_520 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
F_88 ( & V_260 -> V_503 ) ;
F_88 ( & V_260 -> V_181 ) ;
F_17 ( V_260 ) ;
F_106 ( V_6 ) ;
F_265 ( V_19 , V_6 , & V_128 -> V_250 . V_122 , V_128 -> V_250 . type ) ;
} else {
struct V_259 * V_322 , * V_231 ;
struct V_521 * V_430 , * V_522 ;
if ( V_128 -> V_250 . type ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_520 ,
V_172 ,
& V_128 -> V_250 , sizeof( V_128 -> V_250 ) ) ;
goto V_188;
}
F_131 (b, btmp, &hdev->whitelist, list) {
F_265 ( V_19 , V_6 , & V_430 -> V_122 , V_430 -> V_523 ) ;
F_88 ( & V_430 -> V_181 ) ;
F_17 ( V_430 ) ;
}
F_105 ( V_6 ) ;
F_131 (p, tmp, &hdev->le_conn_params, list) {
if ( V_322 -> V_268 == V_270 )
continue;
F_265 ( V_19 , V_6 , & V_322 -> V_250 , V_322 -> V_254 ) ;
if ( V_322 -> V_267 ) {
V_322 -> V_268 = V_269 ;
continue;
}
F_88 ( & V_322 -> V_503 ) ;
F_88 ( & V_322 -> V_181 ) ;
F_17 ( V_322 ) ;
}
F_10 ( L_32 ) ;
F_106 ( V_6 ) ;
}
V_314:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_520 ,
V_187 , & V_128 -> V_250 ,
sizeof( V_128 -> V_250 ) ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_267 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_524 * V_128 = V_7 ;
const T_2 V_525 = ( ( V_242 - sizeof( * V_128 ) ) /
sizeof( struct V_526 ) ) ;
T_2 V_527 , V_245 ;
int V_33 ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_528 ,
V_185 ) ;
V_527 = F_101 ( V_128 -> V_527 ) ;
if ( V_527 > V_525 ) {
F_136 ( L_33 ,
V_527 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_528 ,
V_172 ) ;
}
V_245 = sizeof( * V_128 ) + V_527 *
sizeof( struct V_526 ) ;
if ( V_245 != V_8 ) {
F_136 ( L_34 ,
V_245 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_528 ,
V_172 ) ;
}
F_10 ( L_35 , V_6 -> V_83 , V_527 ) ;
F_35 ( V_6 ) ;
F_268 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_527 ; V_33 ++ ) {
struct V_526 * V_129 = & V_128 -> V_260 [ V_33 ] ;
struct V_259 * V_529 ;
T_2 V_530 , V_531 , V_532 , V_195 ;
T_1 V_254 ;
F_10 ( L_36 , & V_129 -> V_250 . V_122 ,
V_129 -> V_250 . type ) ;
if ( V_129 -> V_250 . type == V_16 ) {
V_254 = V_17 ;
} else if ( V_129 -> V_250 . type == V_282 ) {
V_254 = V_18 ;
} else {
F_136 ( L_37 ) ;
continue;
}
V_530 = F_269 ( V_129 -> V_533 ) ;
V_531 = F_269 ( V_129 -> V_534 ) ;
V_532 = F_269 ( V_129 -> V_532 ) ;
V_195 = F_269 ( V_129 -> V_195 ) ;
F_10 ( L_38 ,
V_530 , V_531 , V_532 , V_195 ) ;
if ( F_270 ( V_530 , V_531 , V_532 , V_195 ) < 0 ) {
F_136 ( L_37 ) ;
continue;
}
V_529 = F_169 ( V_6 , & V_129 -> V_250 . V_122 ,
V_254 ) ;
if ( ! V_529 ) {
F_136 ( L_39 ) ;
continue;
}
V_529 -> V_535 = V_530 ;
V_529 -> V_536 = V_531 ;
V_529 -> V_537 = V_532 ;
V_529 -> V_538 = V_195 ;
}
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_528 , 0 ,
NULL , 0 ) ;
}
static int F_271 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_539 * V_128 = V_7 ;
bool V_197 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_540 ,
V_186 ) ;
if ( V_128 -> V_541 != 0x00 && V_128 -> V_541 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_540 ,
V_172 ) ;
if ( ! F_23 ( V_72 , & V_6 -> V_57 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_540 ,
V_185 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_541 )
V_197 = ! F_61 ( V_6 , V_73 ) ;
else
V_197 = F_52 ( V_6 , V_73 ) ;
V_34 = F_33 ( V_19 , V_540 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( ! V_197 )
goto V_188;
V_34 = F_32 ( V_6 , V_19 ) ;
if ( F_21 ( V_6 , V_51 ) == F_28 ( V_6 ) ) {
F_272 ( V_6 ) ;
if ( F_273 ( V_6 , V_51 ) ) {
F_58 ( V_6 , V_54 ) ;
F_58 ( V_6 , V_542 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_175 ) ;
} else {
F_149 ( V_543 , & V_6 -> V_165 ) ;
F_274 ( V_6 ) ;
}
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_275 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_544 * V_128 = V_7 ;
bool V_197 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_545 ,
V_186 ) ;
if ( ! F_29 ( & V_128 -> V_122 , V_76 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_545 ,
V_172 ) ;
if ( ! V_6 -> V_85 )
return F_82 ( V_19 , V_6 -> V_59 , V_545 ,
V_185 ) ;
F_35 ( V_6 ) ;
V_197 = ! ! F_29 ( & V_6 -> V_75 , & V_128 -> V_122 ) ;
F_65 ( & V_6 -> V_75 , & V_128 -> V_122 ) ;
V_34 = F_33 ( V_19 , V_545 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( ! V_197 )
goto V_188;
if ( F_21 ( V_6 , V_51 ) )
V_34 = F_32 ( V_6 , V_19 ) ;
if ( F_28 ( V_6 ) ) {
F_272 ( V_6 ) ;
F_63 ( V_6 , V_51 ) ;
F_58 ( V_6 , V_54 ) ;
F_58 ( V_6 , V_542 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_175 ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static inline T_2 F_276 ( T_1 * V_546 , T_2 V_547 , T_1 type , T_1 * V_7 ,
T_1 V_20 )
{
V_546 [ V_547 ++ ] = sizeof( type ) + V_20 ;
V_546 [ V_547 ++ ] = type ;
memcpy ( & V_546 [ V_547 ] , V_7 , V_20 ) ;
V_547 += V_20 ;
return V_547 ;
}
static void F_277 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 , struct V_351 * V_352 )
{
const struct V_548 * V_395 ;
struct V_549 * V_354 ;
T_1 * V_550 , * V_551 , * V_552 , * V_553 ;
struct V_124 * V_125 ;
T_2 V_547 ;
int V_34 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
V_125 = F_44 ( V_554 , V_6 ) ;
if ( ! V_125 )
return;
V_395 = V_125 -> V_129 ;
if ( V_150 ) {
V_150 = F_1 ( V_150 ) ;
V_547 = 0 ;
V_550 = NULL ;
V_551 = NULL ;
V_552 = NULL ;
V_553 = NULL ;
} else if ( V_41 == V_356 ) {
struct V_357 * V_22 ;
if ( V_352 -> V_8 != sizeof( * V_22 ) ) {
V_150 = V_3 ;
V_547 = 0 ;
} else {
V_150 = V_187 ;
V_22 = ( void * ) V_352 -> V_7 ;
V_547 = 5 + 18 + 18 ;
V_550 = V_22 -> V_359 ;
V_551 = V_22 -> rand ;
V_552 = NULL ;
V_553 = NULL ;
}
} else {
struct V_363 * V_22 ;
if ( V_352 -> V_8 != sizeof( * V_22 ) ) {
V_150 = V_3 ;
V_547 = 0 ;
} else {
V_150 = V_187 ;
V_22 = ( void * ) V_352 -> V_7 ;
if ( F_21 ( V_6 , V_440 ) ) {
V_547 = 5 + 18 + 18 ;
V_550 = NULL ;
V_551 = NULL ;
} else {
V_547 = 5 + 18 + 18 + 18 + 18 ;
V_550 = V_22 -> V_358 ;
V_551 = V_22 -> V_360 ;
}
V_552 = V_22 -> V_361 ;
V_553 = V_22 -> V_362 ;
}
}
V_354 = F_15 ( sizeof( * V_354 ) + V_547 , V_39 ) ;
if ( ! V_354 )
goto V_265;
if ( V_150 )
goto V_555;
V_547 = F_276 ( V_354 -> V_546 , 0 , V_556 ,
V_6 -> V_146 , 3 ) ;
if ( V_550 && V_551 ) {
V_547 = F_276 ( V_354 -> V_546 , V_547 ,
V_557 , V_550 , 16 ) ;
V_547 = F_276 ( V_354 -> V_546 , V_547 ,
V_558 , V_551 , 16 ) ;
}
if ( V_552 && V_553 ) {
V_547 = F_276 ( V_354 -> V_546 , V_547 ,
V_559 , V_552 , 16 ) ;
V_547 = F_276 ( V_354 -> V_546 , V_547 ,
V_560 , V_553 , 16 ) ;
}
V_555:
V_354 -> type = V_395 -> type ;
V_354 -> V_547 = F_11 ( V_547 ) ;
V_34 = F_12 ( V_125 -> V_19 , V_6 -> V_59 ,
V_554 , V_150 ,
V_354 , sizeof( * V_354 ) + V_547 ) ;
if ( V_34 < 0 || V_150 )
goto V_265;
F_26 ( V_125 -> V_19 , V_561 ) ;
V_34 = F_5 ( V_562 , V_6 ,
V_354 , sizeof( * V_354 ) + V_547 ,
V_561 , V_125 -> V_19 ) ;
V_265:
F_17 ( V_354 ) ;
F_92 ( V_125 ) ;
}
static int F_278 ( struct V_5 * V_6 , struct V_11 * V_19 ,
struct V_548 * V_128 )
{
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
V_125 = F_83 ( V_19 , V_554 , V_6 ,
V_128 , sizeof( * V_128 ) ) ;
if ( ! V_125 )
return - V_40 ;
F_53 ( & V_139 , V_6 ) ;
if ( F_188 ( V_6 ) )
F_75 ( & V_139 , V_364 , 0 , NULL ) ;
else
F_75 ( & V_139 , V_356 , 0 , NULL ) ;
V_34 = F_189 ( & V_139 , F_277 ) ;
if ( V_34 < 0 ) {
F_92 ( V_125 ) ;
return V_34 ;
}
return 0 ;
}
static int F_279 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_548 * V_128 = V_7 ;
struct V_549 * V_22 ;
T_3 V_46 ;
T_2 V_547 ;
T_1 V_150 , V_165 , V_563 , V_250 [ 7 ] , V_359 [ 16 ] , rand [ 16 ] ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) ) {
switch ( V_128 -> type ) {
case F_280 ( V_251 ) :
V_150 = F_96 ( V_6 ) ;
if ( V_150 )
V_547 = 0 ;
else
V_547 = 5 ;
break;
case ( F_280 ( V_16 ) | F_280 ( V_282 ) ) :
V_150 = F_97 ( V_6 ) ;
if ( V_150 )
V_547 = 0 ;
else
V_547 = 9 + 3 + 18 + 18 + 3 ;
break;
default:
V_150 = V_172 ;
V_547 = 0 ;
break;
}
} else {
V_150 = V_196 ;
V_547 = 0 ;
}
V_46 = sizeof( * V_22 ) + V_547 ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 )
return - V_40 ;
if ( V_150 )
goto V_314;
F_35 ( V_6 ) ;
V_547 = 0 ;
switch ( V_128 -> type ) {
case F_280 ( V_251 ) :
if ( F_21 ( V_6 , V_115 ) ) {
V_34 = F_278 ( V_6 , V_19 , V_128 ) ;
F_36 ( V_6 ) ;
if ( ! V_34 )
goto V_265;
V_150 = V_3 ;
goto V_314;
} else {
V_547 = F_276 ( V_22 -> V_546 , V_547 ,
V_556 ,
V_6 -> V_146 , 3 ) ;
}
break;
case ( F_280 ( V_16 ) | F_280 ( V_282 ) ) :
if ( F_21 ( V_6 , V_118 ) &&
F_281 ( V_6 , V_359 , rand ) < 0 ) {
F_36 ( V_6 ) ;
V_150 = V_3 ;
goto V_314;
}
if ( F_21 ( V_6 , V_120 ) ) {
F_36 ( V_6 ) ;
V_150 = V_186 ;
goto V_314;
}
if ( F_21 ( V_6 , V_121 ) ||
! F_29 ( & V_6 -> V_122 , V_76 ) ||
( ! F_21 ( V_6 , V_112 ) &&
F_29 ( & V_6 -> V_123 , V_76 ) ) ) {
memcpy ( V_250 , & V_6 -> V_123 , 6 ) ;
V_250 [ 6 ] = 0x01 ;
} else {
memcpy ( V_250 , & V_6 -> V_122 , 6 ) ;
V_250 [ 6 ] = 0x00 ;
}
V_547 = F_276 ( V_22 -> V_546 , V_547 , V_564 ,
V_250 , sizeof( V_250 ) ) ;
if ( F_21 ( V_6 , V_117 ) )
V_563 = 0x02 ;
else
V_563 = 0x01 ;
V_547 = F_276 ( V_22 -> V_546 , V_547 , V_565 ,
& V_563 , sizeof( V_563 ) ) ;
if ( F_21 ( V_6 , V_118 ) ) {
V_547 = F_276 ( V_22 -> V_546 , V_547 ,
V_566 ,
V_359 , sizeof( V_359 ) ) ;
V_547 = F_276 ( V_22 -> V_546 , V_547 ,
V_567 ,
rand , sizeof( rand ) ) ;
}
V_165 = F_48 ( V_6 ) ;
if ( ! F_21 ( V_6 , V_112 ) )
V_165 |= V_568 ;
V_547 = F_276 ( V_22 -> V_546 , V_547 , V_569 ,
& V_165 , sizeof( V_165 ) ) ;
break;
}
F_36 ( V_6 ) ;
F_26 ( V_19 , V_561 ) ;
V_150 = V_187 ;
V_314:
V_22 -> type = V_128 -> type ;
V_22 -> V_547 = F_11 ( V_547 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_554 ,
V_150 , V_22 , sizeof( * V_22 ) + V_547 ) ;
if ( V_34 < 0 || V_150 )
goto V_265;
V_34 = F_5 ( V_562 , V_6 ,
V_22 , sizeof( * V_22 ) + V_547 ,
V_561 , V_19 ) ;
V_265:
F_17 ( V_22 ) ;
return V_34 ;
}
static T_6 F_282 ( struct V_5 * V_6 )
{
T_6 V_165 = 0 ;
V_165 |= V_570 ;
V_165 |= V_571 ;
V_165 |= V_572 ;
V_165 |= V_573 ;
if ( V_6 -> V_574 != V_477 )
V_165 |= V_575 ;
return V_165 ;
}
static int F_283 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_576 * V_22 ;
T_3 V_46 ;
int V_34 ;
struct V_420 * V_421 ;
T_6 V_577 ;
T_1 * V_153 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_578 ,
V_186 ) ;
F_35 ( V_6 ) ;
V_46 = sizeof( * V_22 ) + V_6 -> V_579 ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 ) {
F_36 ( V_6 ) ;
return - V_40 ;
}
V_577 = F_282 ( V_6 ) ;
V_22 -> V_577 = F_31 ( V_577 ) ;
V_22 -> V_580 = V_581 ;
V_22 -> V_582 = V_581 ;
V_22 -> V_583 = V_584 ;
V_22 -> V_585 = V_6 -> V_579 ;
V_153 = V_22 -> V_153 ;
F_20 (adv_instance, &hdev->adv_instances, list) {
* V_153 = V_421 -> V_153 ;
V_153 ++ ;
}
F_36 ( V_6 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_578 ,
V_187 , V_22 , V_46 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static bool F_284 ( struct V_5 * V_6 , T_6 V_586 , T_1 * V_7 ,
T_1 V_8 , bool V_587 )
{
T_1 V_588 = V_581 ;
int V_33 , V_589 ;
bool V_590 = false ;
bool V_591 = false ;
if ( V_587 ) {
if ( V_586 & ( V_571 |
V_572 |
V_573 ) ) {
V_590 = true ;
V_588 -= 3 ;
}
if ( V_586 & V_575 ) {
V_591 = true ;
V_588 -= 3 ;
}
}
if ( V_8 > V_588 )
return false ;
for ( V_33 = 0 , V_589 = 0 ; V_33 < V_8 ; V_33 += ( V_589 + 1 ) ) {
V_589 = V_7 [ V_33 ] ;
if ( V_590 && V_7 [ V_33 + 1 ] == V_569 )
return false ;
if ( V_591 && V_7 [ V_33 + 1 ] == V_592 )
return false ;
if ( V_33 + V_589 >= V_8 )
return false ;
}
return true ;
}
static void F_285 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 )
{
struct V_124 * V_125 ;
struct V_593 * V_128 ;
struct V_594 V_22 ;
struct V_420 * V_421 , * V_595 ;
T_1 V_153 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_596 , V_6 ) ;
F_131 (adv_instance, n, &hdev->adv_instances, list) {
if ( ! V_421 -> V_597 )
continue;
if ( ! V_150 ) {
V_421 -> V_597 = false ;
continue;
}
V_153 = V_421 -> V_153 ;
if ( V_6 -> V_350 == V_153 )
F_73 ( V_6 ) ;
F_286 ( V_6 , V_153 ) ;
F_72 ( V_125 ? V_125 -> V_19 : NULL , V_6 , V_153 ) ;
}
if ( ! V_125 )
goto V_188;
V_128 = V_125 -> V_129 ;
V_22 . V_153 = V_128 -> V_153 ;
if ( V_150 )
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 ,
F_1 ( V_150 ) ) ;
else
F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 ,
F_1 ( V_150 ) , & V_22 , sizeof( V_22 ) ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_287 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_593 * V_128 = V_7 ;
struct V_594 V_22 ;
T_6 V_165 ;
T_6 V_577 ;
T_1 V_150 ;
T_2 V_195 , V_598 ;
unsigned int V_599 = V_6 -> V_579 ;
T_1 V_600 = 0 ;
struct V_420 * V_601 ;
int V_34 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
V_150 = F_97 ( V_6 ) ;
if ( V_150 )
return F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_150 ) ;
if ( V_128 -> V_153 < 1 || V_128 -> V_153 > V_584 )
return F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_172 ) ;
V_165 = F_288 ( V_128 -> V_165 ) ;
V_195 = F_101 ( V_128 -> V_195 ) ;
V_598 = F_101 ( V_128 -> V_598 ) ;
V_577 = F_282 ( V_6 ) ;
if ( V_165 & ~ V_577 )
return F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_195 && ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_186 ) ;
goto V_188;
}
if ( F_44 ( V_596 , V_6 ) ||
F_44 ( V_602 , V_6 ) ||
F_44 ( V_209 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_173 ) ;
goto V_188;
}
if ( ! F_284 ( V_6 , V_165 , V_128 -> V_7 , V_128 -> V_603 , true ) ||
! F_284 ( V_6 , V_165 , V_128 -> V_7 + V_128 -> V_603 ,
V_128 -> V_604 , false ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_172 ) ;
goto V_188;
}
V_34 = F_289 ( V_6 , V_128 -> V_153 , V_165 ,
V_128 -> V_603 , V_128 -> V_7 ,
V_128 -> V_604 ,
V_128 -> V_7 + V_128 -> V_603 ,
V_195 , V_598 ) ;
if ( V_34 < 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_596 ,
V_3 ) ;
goto V_188;
}
if ( V_6 -> V_579 > V_599 )
F_71 ( V_19 , V_6 , V_128 -> V_153 ) ;
if ( V_6 -> V_350 == V_128 -> V_153 ) {
F_73 ( V_6 ) ;
V_601 = F_290 ( V_6 , V_128 -> V_153 ) ;
if ( V_601 )
V_600 = V_601 -> V_153 ;
} else if ( ! V_6 -> V_159 ) {
V_600 = V_128 -> V_153 ;
}
if ( ! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) ||
! V_600 ) {
V_22 . V_153 = V_128 -> V_153 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_596 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_596 , V_6 , V_7 ,
V_20 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
V_34 = F_220 ( & V_139 , V_600 , true ) ;
if ( ! V_34 )
V_34 = F_56 ( & V_139 , F_285 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_291 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 )
{
struct V_124 * V_125 ;
struct V_605 * V_128 ;
struct V_606 V_22 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_602 , V_6 ) ;
if ( ! V_125 )
goto V_188;
V_128 = V_125 -> V_129 ;
V_22 . V_153 = V_128 -> V_153 ;
F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_187 ,
& V_22 , sizeof( V_22 ) ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_292 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_605 * V_128 = V_7 ;
struct V_606 V_22 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_153 && ! F_293 ( V_6 , V_128 -> V_153 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 ,
V_602 ,
V_172 ) ;
goto V_188;
}
if ( F_44 ( V_596 , V_6 ) ||
F_44 ( V_602 , V_6 ) ||
F_44 ( V_209 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_602 ,
V_173 ) ;
goto V_188;
}
if ( F_218 ( & V_6 -> V_422 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_602 ,
V_172 ) ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
F_76 ( V_6 , & V_139 , V_128 -> V_153 , true ) ;
if ( F_218 ( & V_6 -> V_422 ) )
F_77 ( & V_139 ) ;
if ( F_294 ( & V_139 . V_607 ) ||
! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) ) {
V_22 . V_153 = V_128 -> V_153 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_602 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_602 , V_6 , V_7 ,
V_20 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_34 = F_56 ( & V_139 , F_291 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static T_1 F_295 ( T_6 V_586 , bool V_587 )
{
T_1 V_588 = V_581 ;
if ( V_587 ) {
if ( V_586 & ( V_571 |
V_572 |
V_573 ) )
V_588 -= 3 ;
if ( V_586 & V_575 )
V_588 -= 3 ;
}
return V_588 ;
}
static int F_296 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_608 * V_128 = V_7 ;
struct V_609 V_22 ;
T_6 V_165 , V_577 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_610 ,
V_186 ) ;
if ( V_128 -> V_153 < 1 || V_128 -> V_153 > V_584 )
return F_82 ( V_19 , V_6 -> V_59 , V_610 ,
V_172 ) ;
V_165 = F_288 ( V_128 -> V_165 ) ;
V_577 = F_282 ( V_6 ) ;
if ( V_165 & ~ V_577 )
return F_82 ( V_19 , V_6 -> V_59 , V_610 ,
V_172 ) ;
V_22 . V_153 = V_128 -> V_153 ;
V_22 . V_165 = V_128 -> V_165 ;
V_22 . V_580 = F_295 ( V_165 , true ) ;
V_22 . V_582 = F_295 ( V_165 , false ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_610 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
return V_34 ;
}
void F_274 ( struct V_5 * V_6 )
{
struct V_611 V_155 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_612 , V_6 ,
NULL , 0 , V_70 ) ;
V_155 . type = 0x01 ;
} else {
F_3 ( V_613 , V_6 , NULL , 0 ,
V_69 ) ;
V_155 . type = 0x00 ;
}
break;
case V_65 :
V_155 . type = 0x02 ;
break;
default:
return;
}
V_155 . V_67 = V_6 -> V_67 ;
F_3 ( V_614 , V_6 , & V_155 , sizeof( V_155 ) ,
V_68 ) ;
}
void F_272 ( struct V_5 * V_6 )
{
struct V_611 V_155 ;
T_1 V_150 = V_615 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
F_114 ( 0 , V_6 , F_93 , & V_150 ) ;
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_616 , V_6 ,
NULL , 0 , V_70 ) ;
V_155 . type = 0x01 ;
} else {
F_3 ( V_617 , V_6 , NULL , 0 ,
V_69 ) ;
V_155 . type = 0x00 ;
}
break;
case V_65 :
V_155 . type = 0x02 ;
break;
default:
return;
}
V_155 . V_67 = V_6 -> V_67 ;
F_3 ( V_618 , V_6 , & V_155 , sizeof( V_155 ) ,
V_68 ) ;
}
static void F_297 ( struct V_5 * V_6 )
{
struct V_259 * V_322 ;
F_20 (p, &hdev->le_conn_params, list) {
F_260 ( & V_322 -> V_503 ) ;
switch ( V_322 -> V_268 ) {
case V_508 :
case V_509 :
F_261 ( & V_322 -> V_503 , & V_6 -> V_505 ) ;
break;
case V_506 :
F_261 ( & V_322 -> V_503 , & V_6 -> V_507 ) ;
break;
default:
break;
}
}
}
void F_298 ( struct V_5 * V_6 , int V_34 )
{
struct V_179 V_180 = { NULL , V_6 } ;
F_10 ( L_40 , V_34 ) ;
F_35 ( V_6 ) ;
if ( ! V_34 ) {
F_297 ( V_6 ) ;
F_106 ( V_6 ) ;
}
F_114 ( V_171 , V_6 , F_87 , & V_180 ) ;
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
F_36 ( V_6 ) ;
}
void F_299 ( struct V_5 * V_6 )
{
struct V_179 V_180 = { NULL , V_6 } ;
T_1 V_150 , V_619 [] = { 0 , 0 , 0 } ;
F_114 ( V_171 , V_6 , F_87 , & V_180 ) ;
if ( F_21 ( V_6 , V_620 ) )
V_150 = V_615 ;
else
V_150 = V_196 ;
F_114 ( 0 , V_6 , F_93 , & V_150 ) ;
if ( memcmp ( V_6 -> V_146 , V_619 , sizeof( V_619 ) ) != 0 )
F_6 ( V_621 , V_6 ,
V_619 , sizeof( V_619 ) , NULL ) ;
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
}
void F_300 ( struct V_5 * V_6 , int V_34 )
{
struct V_124 * V_125 ;
T_1 V_150 ;
V_125 = F_44 ( V_171 , V_6 ) ;
if ( ! V_125 )
return;
if ( V_34 == - V_622 )
V_150 = V_623 ;
else
V_150 = V_3 ;
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_171 , V_150 ) ;
F_92 ( V_125 ) ;
}
void F_301 ( struct V_5 * V_6 , struct V_624 * V_248 ,
bool V_625 )
{
struct V_626 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_627 = V_625 ;
F_65 ( & V_155 . V_248 . V_250 . V_122 , & V_248 -> V_122 ) ;
V_155 . V_248 . V_250 . type = V_251 ;
V_155 . V_248 . type = V_248 -> type ;
memcpy ( V_155 . V_248 . V_130 , V_248 -> V_130 , V_628 ) ;
V_155 . V_248 . V_253 = V_248 -> V_253 ;
F_7 ( V_629 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
static T_1 F_302 ( struct V_630 * V_631 )
{
switch ( V_631 -> type ) {
case V_463 :
case V_464 :
if ( V_631 -> V_461 )
return V_465 ;
return V_462 ;
case V_467 :
if ( V_631 -> V_461 )
return V_468 ;
return V_466 ;
case V_470 :
return V_469 ;
}
return V_462 ;
}
void F_303 ( struct V_5 * V_6 , struct V_630 * V_248 , bool V_625 )
{
struct V_632 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_248 -> V_523 == V_18 &&
( V_248 -> V_122 . V_430 [ 5 ] & 0xc0 ) != 0xc0 )
V_155 . V_627 = 0x00 ;
else
V_155 . V_627 = V_625 ;
F_65 ( & V_155 . V_248 . V_250 . V_122 , & V_248 -> V_122 ) ;
V_155 . V_248 . V_250 . type = F_153 ( V_281 , V_248 -> V_523 ) ;
V_155 . V_248 . type = F_302 ( V_248 ) ;
V_155 . V_248 . V_471 = V_248 -> V_471 ;
V_155 . V_248 . V_472 = V_248 -> V_472 ;
V_155 . V_248 . rand = V_248 -> rand ;
if ( V_248 -> type == V_463 )
V_155 . V_248 . V_458 = 1 ;
memcpy ( V_155 . V_248 . V_130 , V_248 -> V_130 , V_248 -> V_471 ) ;
memset ( V_155 . V_248 . V_130 + V_248 -> V_471 , 0 ,
sizeof( V_155 . V_248 . V_130 ) - V_248 -> V_471 ) ;
F_7 ( V_633 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_304 ( struct V_5 * V_6 , struct V_634 * V_450 , bool V_625 )
{
struct V_635 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_627 = V_625 ;
F_65 ( & V_155 . V_636 , & V_450 -> V_636 ) ;
F_65 ( & V_155 . V_450 . V_250 . V_122 , & V_450 -> V_122 ) ;
V_155 . V_450 . V_250 . type = F_153 ( V_281 , V_450 -> V_254 ) ;
memcpy ( V_155 . V_450 . V_130 , V_450 -> V_130 , sizeof( V_450 -> V_130 ) ) ;
F_7 ( V_637 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_305 ( struct V_5 * V_6 , struct V_638 * V_639 ,
bool V_625 )
{
struct V_640 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_639 -> V_523 == V_18 &&
( V_639 -> V_122 . V_430 [ 5 ] & 0xc0 ) != 0xc0 )
V_155 . V_627 = 0x00 ;
else
V_155 . V_627 = V_625 ;
F_65 ( & V_155 . V_248 . V_250 . V_122 , & V_639 -> V_122 ) ;
V_155 . V_248 . V_250 . type = F_153 ( V_281 , V_639 -> V_523 ) ;
V_155 . V_248 . type = V_639 -> type ;
memcpy ( V_155 . V_248 . V_130 , V_639 -> V_130 , sizeof( V_639 -> V_130 ) ) ;
F_7 ( V_641 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_306 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_523 , T_1 V_627 , T_2 V_533 ,
T_2 V_534 , T_2 V_532 , T_2 V_195 )
{
struct V_642 V_155 ;
if ( ! F_264 ( V_122 , V_523 ) )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = F_153 ( V_281 , V_523 ) ;
V_155 . V_627 = V_627 ;
V_155 . V_533 = F_11 ( V_533 ) ;
V_155 . V_534 = F_11 ( V_534 ) ;
V_155 . V_532 = F_11 ( V_532 ) ;
V_155 . V_195 = F_11 ( V_195 ) ;
F_7 ( V_643 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_307 ( struct V_5 * V_6 , struct V_161 * V_162 ,
T_6 V_165 , T_1 * V_83 , T_1 V_644 )
{
char V_645 [ 512 ] ;
struct V_646 * V_155 = ( void * ) V_645 ;
T_2 V_547 = 0 ;
F_65 ( & V_155 -> V_250 . V_122 , & V_162 -> V_287 ) ;
V_155 -> V_250 . type = F_153 ( V_162 -> type , V_162 -> V_288 ) ;
V_155 -> V_165 = F_308 ( V_165 ) ;
if ( V_162 -> V_647 > 0 ) {
memcpy ( & V_155 -> V_546 [ V_547 ] ,
V_162 -> V_648 , V_162 -> V_647 ) ;
V_547 = V_162 -> V_647 ;
} else {
if ( V_644 > 0 )
V_547 = F_276 ( V_155 -> V_546 , 0 , V_649 ,
V_83 , V_644 ) ;
if ( memcmp ( V_162 -> V_146 , L_41 , 3 ) != 0 )
V_547 = F_276 ( V_155 -> V_546 , V_547 ,
V_556 ,
V_162 -> V_146 , 3 ) ;
}
V_155 -> V_547 = F_11 ( V_547 ) ;
F_7 ( V_650 , V_6 , V_645 ,
sizeof( * V_155 ) + V_547 , NULL ) ;
}
static void F_309 ( struct V_124 * V_125 , void * V_7 )
{
struct V_11 * * V_19 = V_7 ;
V_125 -> V_182 ( V_125 , 0 ) ;
* V_19 = V_125 -> V_19 ;
F_89 ( * V_19 ) ;
F_92 ( V_125 ) ;
}
static void F_310 ( struct V_124 * V_125 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_257 * V_128 = V_125 -> V_129 ;
F_139 ( V_6 , & V_128 -> V_250 . V_122 , V_128 -> V_250 . type , V_125 -> V_19 ) ;
V_125 -> V_182 ( V_125 , 0 ) ;
F_92 ( V_125 ) ;
}
bool F_311 ( struct V_5 * V_6 )
{
struct V_124 * V_125 ;
struct V_127 * V_128 ;
V_125 = F_44 ( V_171 , V_6 ) ;
if ( ! V_125 )
return false ;
V_128 = V_125 -> V_129 ;
if ( ! V_128 -> V_130 )
return true ;
return false ;
}
void F_312 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_651 ,
bool V_652 )
{
struct V_653 V_155 ;
struct V_11 * V_19 = NULL ;
if ( F_311 ( V_6 ) && F_68 ( V_6 ) == 1 ) {
F_69 ( & V_6 -> V_151 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_151 . V_136 ) ;
}
if ( ! V_652 )
return;
if ( V_280 != V_263 && V_280 != V_281 )
return;
F_114 ( V_274 , V_6 , F_309 , & V_19 ) ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = F_153 ( V_280 , V_254 ) ;
V_155 . V_651 = V_651 ;
F_7 ( V_654 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
if ( V_19 )
F_115 ( V_19 ) ;
F_114 ( V_261 , V_6 , F_310 ,
V_6 ) ;
}
void F_313 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_150 )
{
T_1 V_523 = F_153 ( V_280 , V_254 ) ;
struct V_272 * V_128 ;
struct V_124 * V_125 ;
F_114 ( V_261 , V_6 , F_310 ,
V_6 ) ;
V_125 = F_44 ( V_274 , V_6 ) ;
if ( ! V_125 )
return;
V_128 = V_125 -> V_129 ;
if ( F_29 ( V_122 , & V_128 -> V_250 . V_122 ) )
return;
if ( V_128 -> V_250 . type != V_523 )
return;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
void F_314 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_280 ,
T_1 V_254 , T_1 V_150 )
{
struct V_655 V_155 ;
if ( F_311 ( V_6 ) && F_68 ( V_6 ) == 1 ) {
F_69 ( & V_6 -> V_151 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_151 . V_136 ) ;
}
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = F_153 ( V_280 , V_254 ) ;
V_155 . V_150 = F_1 ( V_150 ) ;
F_7 ( V_656 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_315 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_657 )
{
struct V_658 V_155 ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = V_251 ;
V_155 . V_657 = V_657 ;
F_7 ( V_659 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_316 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_150 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_298 , V_6 ) ;
if ( ! V_125 )
return;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
void F_317 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_150 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_293 , V_6 ) ;
if ( ! V_125 )
return;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
int F_318 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_6 V_660 ,
T_1 V_661 )
{
struct V_662 V_155 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = F_153 ( V_280 , V_254 ) ;
V_155 . V_661 = V_661 ;
V_155 . V_660 = F_31 ( V_660 ) ;
return F_7 ( V_663 , V_6 , & V_155 , sizeof( V_155 ) ,
NULL ) ;
}
int F_319 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 )
{
struct V_664 V_155 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = F_153 ( V_280 , V_254 ) ;
return F_7 ( V_665 , V_6 , & V_155 , sizeof( V_155 ) ,
NULL ) ;
}
static int F_320 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_150 ,
T_1 V_41 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_41 , V_6 ) ;
if ( ! V_125 )
return - V_666 ;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
return 0 ;
}
int F_321 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_280 , V_254 ,
V_150 , V_337 ) ;
}
int F_322 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_280 , V_254 ,
V_150 ,
V_340 ) ;
}
int F_323 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_280 , V_254 ,
V_150 , V_343 ) ;
}
int F_324 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_280 , V_254 ,
V_150 ,
V_345 ) ;
}
int F_325 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_280 , T_1 V_254 , T_6 V_333 ,
T_1 V_667 )
{
struct V_668 V_155 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_65 ( & V_155 . V_250 . V_122 , V_122 ) ;
V_155 . V_250 . type = F_153 ( V_280 , V_254 ) ;
V_155 . V_333 = F_308 ( V_333 ) ;
V_155 . V_667 = V_667 ;
return F_7 ( V_669 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_326 ( struct V_161 * V_162 , T_1 V_1 )
{
struct V_670 V_155 ;
struct V_124 * V_125 ;
T_1 V_150 = F_1 ( V_1 ) ;
F_65 ( & V_155 . V_250 . V_122 , & V_162 -> V_287 ) ;
V_155 . V_250 . type = F_153 ( V_162 -> type , V_162 -> V_288 ) ;
V_155 . V_150 = V_150 ;
V_125 = F_158 ( V_162 ) ;
F_7 ( V_671 , V_162 -> V_6 , & V_155 , sizeof( V_155 ) ,
V_125 ? V_125 -> V_19 : NULL ) ;
if ( V_125 ) {
V_125 -> V_182 ( V_125 , V_150 ) ;
F_92 ( V_125 ) ;
}
}
void F_327 ( struct V_5 * V_6 , T_1 V_150 )
{
struct V_179 V_180 = { NULL , V_6 } ;
bool V_197 ;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_114 ( V_201 , V_6 ,
F_91 , & V_189 ) ;
return;
}
if ( F_23 ( V_202 , & V_6 -> V_165 ) )
V_197 = ! F_61 ( V_6 , V_114 ) ;
else
V_197 = F_52 ( V_6 , V_114 ) ;
F_114 ( V_201 , V_6 , F_87 ,
& V_180 ) ;
if ( V_197 )
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
}
static void F_328 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_672 V_128 ;
if ( ! F_329 ( V_6 ) )
return;
memset ( V_6 -> V_546 , 0 , sizeof( V_6 -> V_546 ) ) ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_75 ( V_139 , V_673 , sizeof( V_128 ) , & V_128 ) ;
}
void F_330 ( struct V_5 * V_6 , T_1 V_674 , T_1 V_150 )
{
struct V_179 V_180 = { NULL , V_6 } ;
struct V_138 V_139 ;
bool V_197 = false ;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
if ( V_674 && F_52 ( V_6 ,
V_115 ) ) {
F_63 ( V_6 , V_116 ) ;
F_85 ( V_6 , NULL ) ;
}
F_114 ( V_204 , V_6 , F_91 ,
& V_189 ) ;
return;
}
if ( V_674 ) {
V_197 = ! F_61 ( V_6 , V_115 ) ;
} else {
V_197 = F_52 ( V_6 , V_115 ) ;
if ( ! V_197 )
V_197 = F_52 ( V_6 ,
V_116 ) ;
else
F_63 ( V_6 , V_116 ) ;
}
F_114 ( V_204 , V_6 , F_87 , & V_180 ) ;
if ( V_197 )
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
F_53 ( & V_139 , V_6 ) ;
if ( F_21 ( V_6 , V_115 ) ) {
if ( F_21 ( V_6 , V_205 ) )
F_75 ( & V_139 , V_206 ,
sizeof( V_674 ) , & V_674 ) ;
F_54 ( & V_139 ) ;
} else {
F_328 ( & V_139 ) ;
}
F_56 ( & V_139 , NULL ) ;
}
static void F_331 ( struct V_124 * V_125 , void * V_7 )
{
struct V_179 * V_180 = V_7 ;
if ( V_180 -> V_19 == NULL ) {
V_180 -> V_19 = V_125 -> V_19 ;
F_89 ( V_180 -> V_19 ) ;
}
}
void F_332 ( struct V_5 * V_6 , T_1 * V_146 ,
T_1 V_150 )
{
struct V_179 V_180 = { NULL , V_6 , F_1 (status) } ;
F_114 ( V_219 , V_6 , F_331 , & V_180 ) ;
F_114 ( V_217 , V_6 , F_331 , & V_180 ) ;
F_114 ( V_218 , V_6 , F_331 , & V_180 ) ;
if ( ! V_150 )
F_6 ( V_621 , V_6 ,
V_146 , 3 , NULL ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
}
void F_333 ( struct V_5 * V_6 , T_1 * V_83 , T_1 V_150 )
{
struct V_347 V_155 ;
struct V_124 * V_125 ;
if ( V_150 )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
memcpy ( V_155 . V_83 , V_83 , V_675 ) ;
memcpy ( V_155 . V_148 , V_6 -> V_148 , V_676 ) ;
V_125 = F_44 ( V_348 , V_6 ) ;
if ( ! V_125 ) {
memcpy ( V_6 -> V_147 , V_83 , sizeof( V_6 -> V_147 ) ) ;
if ( F_44 ( V_171 , V_6 ) )
return;
}
F_6 ( V_349 , V_6 , & V_155 , sizeof( V_155 ) ,
V_125 ? V_125 -> V_19 : NULL ) ;
}
static void F_334 ( struct V_5 * V_6 )
{
if ( ! F_21 ( V_6 , V_424 ) )
return;
if ( F_251 ( V_487 + V_677 ,
V_6 -> V_381 . V_678 +
V_6 -> V_381 . V_679 ) )
return;
F_84 ( V_6 -> V_152 , & V_6 -> V_680 ,
V_677 ) ;
}
static bool F_335 ( struct V_5 * V_6 , T_10 V_392 , T_1 * V_546 ,
T_2 V_547 , T_1 * V_681 , T_1 V_604 )
{
if ( V_6 -> V_381 . V_392 != V_476 &&
( V_392 == V_476 ||
( V_392 < V_6 -> V_381 . V_392 &&
! F_23 ( V_682 , & V_6 -> V_57 ) ) ) )
return false ;
if ( V_6 -> V_381 . V_390 != 0 ) {
if ( ! F_336 ( V_546 , V_547 , V_6 -> V_381 . V_390 ,
V_6 -> V_381 . V_227 ) &&
! F_336 ( V_681 , V_604 ,
V_6 -> V_381 . V_390 ,
V_6 -> V_381 . V_227 ) )
return false ;
}
if ( F_23 ( V_682 , & V_6 -> V_57 ) ) {
F_334 ( V_6 ) ;
if ( V_6 -> V_381 . V_392 != V_476 &&
V_392 < V_6 -> V_381 . V_392 )
return false ;
}
return true ;
}
void F_337 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_280 ,
T_1 V_254 , T_1 * V_146 , T_10 V_392 , T_6 V_165 ,
T_1 * V_546 , T_2 V_547 , T_1 * V_681 , T_1 V_604 )
{
char V_645 [ 512 ] ;
struct V_683 * V_155 = ( void * ) V_645 ;
T_3 V_684 ;
if ( ! F_207 ( V_6 ) ) {
if ( V_280 == V_263 )
return;
if ( V_280 == V_281 && F_218 ( & V_6 -> V_507 ) )
return;
}
if ( V_6 -> V_381 . V_391 ) {
if ( ! F_335 ( V_6 , V_392 , V_546 , V_547 , V_681 ,
V_604 ) )
return;
}
if ( V_6 -> V_381 . V_385 ) {
if ( V_146 ) {
if ( ! ( V_146 [ 1 ] & 0x20 ) )
return;
} else {
T_1 * V_165 = F_338 ( V_546 , V_547 , V_569 , NULL ) ;
if ( ! V_165 || ! ( V_165 [ 0 ] & V_132 ) )
return;
}
}
if ( sizeof( * V_155 ) + V_547 + V_604 + 5 > sizeof( V_645 ) )
return;
memset ( V_645 , 0 , sizeof( V_645 ) ) ;
if ( V_392 == V_476 && ! V_6 -> V_381 . V_384 &&
V_280 == V_263 )
V_392 = 0 ;
F_65 ( & V_155 -> V_250 . V_122 , V_122 ) ;
V_155 -> V_250 . type = F_153 ( V_280 , V_254 ) ;
V_155 -> V_392 = V_392 ;
V_155 -> V_165 = F_31 ( V_165 ) ;
if ( V_547 > 0 )
memcpy ( V_155 -> V_546 , V_546 , V_547 ) ;
if ( V_146 && ! F_338 ( V_155 -> V_546 , V_547 , V_556 ,
NULL ) )
V_547 = F_276 ( V_155 -> V_546 , V_547 , V_556 ,
V_146 , 3 ) ;
if ( V_604 > 0 )
memcpy ( V_155 -> V_546 + V_547 , V_681 , V_604 ) ;
V_155 -> V_547 = F_11 ( V_547 + V_604 ) ;
V_684 = sizeof( * V_155 ) + V_547 + V_604 ;
F_7 ( V_685 , V_6 , V_155 , V_684 , NULL ) ;
}
void F_339 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_280 ,
T_1 V_254 , T_10 V_392 , T_1 * V_83 , T_1 V_644 )
{
struct V_683 * V_155 ;
char V_645 [ sizeof( * V_155 ) + V_675 + 2 ] ;
T_2 V_547 ;
V_155 = (struct V_683 * ) V_645 ;
memset ( V_645 , 0 , sizeof( V_645 ) ) ;
F_65 ( & V_155 -> V_250 . V_122 , V_122 ) ;
V_155 -> V_250 . type = F_153 ( V_280 , V_254 ) ;
V_155 -> V_392 = V_392 ;
V_547 = F_276 ( V_155 -> V_546 , 0 , V_649 , V_83 ,
V_644 ) ;
V_155 -> V_547 = F_11 ( V_547 ) ;
F_7 ( V_685 , V_6 , V_155 , sizeof( * V_155 ) + V_547 , NULL ) ;
}
void F_340 ( struct V_5 * V_6 , T_1 V_686 )
{
struct V_687 V_155 ;
F_10 ( L_42 , V_6 -> V_83 , V_686 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . type = V_6 -> V_381 . type ;
V_155 . V_686 = V_686 ;
F_7 ( V_688 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
int F_341 ( void )
{
return F_342 ( & V_689 ) ;
}
void F_343 ( void )
{
F_344 ( & V_689 ) ;
}
