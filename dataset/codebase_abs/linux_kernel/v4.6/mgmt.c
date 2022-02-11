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
if ( V_197 ) {
if ( F_43 ( V_6 ) &&
F_21 ( V_6 , V_117 ) &&
F_21 ( V_6 , V_110 ) &&
F_21 ( V_6 , V_201 ) )
F_70 ( V_6 -> V_152 ,
& V_6 -> V_198 ) ;
V_34 = F_85 ( V_6 , V_19 ) ;
}
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
return F_82 ( V_19 , V_6 -> V_59 , V_202 ,
V_150 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_202 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_197 = false ;
if ( ! ! V_128 -> V_130 != F_21 ( V_6 , V_114 ) ) {
F_102 ( V_6 , V_114 ) ;
V_197 = true ;
}
V_34 = F_66 ( V_19 , V_202 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( F_44 ( V_202 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_202 ,
V_173 ) ;
goto V_174;
}
V_130 = ! ! V_128 -> V_130 ;
if ( F_23 ( V_203 , & V_6 -> V_165 ) == V_130 ) {
V_34 = F_66 ( V_19 , V_202 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_202 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_34 = F_110 ( V_6 , V_204 , sizeof( V_130 ) , & V_130 ) ;
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
return F_82 ( V_19 , V_6 -> V_59 , V_205 , V_150 ) ;
if ( ! F_39 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_205 ,
V_185 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_205 ,
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
V_34 = F_66 ( V_19 , V_205 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( F_44 ( V_205 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_205 ,
V_173 ) ;
goto V_174;
}
if ( ! ! V_128 -> V_130 == F_21 ( V_6 , V_115 ) ) {
V_34 = F_66 ( V_19 , V_205 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_205 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
if ( ! V_128 -> V_130 && F_21 ( V_6 , V_206 ) )
F_110 ( V_6 , V_207 ,
sizeof( V_128 -> V_130 ) , & V_128 -> V_130 ) ;
V_34 = F_110 ( V_6 , V_208 , 1 , & V_128 -> V_130 ) ;
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
return F_82 ( V_19 , V_6 -> V_59 , V_209 , V_150 ) ;
if ( ! F_39 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_185 ) ;
if ( ! F_21 ( V_6 , V_115 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_205 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_173 ) ;
goto V_188;
}
if ( V_128 -> V_130 ) {
V_197 = ! F_61 ( V_6 , V_116 ) ;
} else {
if ( F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_209 ,
V_186 ) ;
goto V_188;
}
V_197 = F_52 ( V_6 , V_116 ) ;
}
V_34 = F_66 ( V_19 , V_209 , V_6 ) ;
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
F_114 ( V_210 , V_6 , F_91 ,
& V_189 ) ;
goto V_188;
}
F_114 ( V_210 , V_6 , F_87 , & V_180 ) ;
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
struct V_211 V_212 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
T_1 V_130 , V_213 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_210 ,
V_185 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_210 ,
V_172 ) ;
if ( ! F_21 ( V_6 , V_112 ) ) {
if ( V_128 -> V_130 == 0x01 )
return F_66 ( V_19 , V_210 , V_6 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_210 ,
V_186 ) ;
}
F_35 ( V_6 ) ;
V_130 = ! ! V_128 -> V_130 ;
V_213 = F_119 ( V_6 ) ;
if ( ! V_130 )
F_76 ( V_6 , NULL , 0x00 , true ) ;
if ( ! F_43 ( V_6 ) || V_130 == V_213 ) {
bool V_197 = false ;
if ( V_130 != F_21 ( V_6 , V_113 ) ) {
F_102 ( V_6 , V_113 ) ;
V_197 = true ;
}
if ( ! V_130 && F_21 ( V_6 , V_117 ) ) {
F_63 ( V_6 , V_117 ) ;
V_197 = true ;
}
V_34 = F_66 ( V_19 , V_210 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_188;
}
if ( F_44 ( V_210 , V_6 ) ||
F_44 ( V_214 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_210 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_210 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
if ( V_130 ) {
V_212 . V_215 = V_130 ;
V_212 . V_216 = 0x00 ;
} else {
if ( F_21 ( V_6 , V_169 ) )
F_77 ( & V_139 ) ;
}
F_75 ( & V_139 , V_217 , sizeof( V_212 ) ,
& V_212 ) ;
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
case V_218 :
case V_219 :
case V_220 :
case V_171 :
return true ;
}
}
return false ;
}
static T_1 F_121 ( const T_1 * V_221 )
{
T_6 V_130 ;
if ( memcmp ( V_221 , V_222 , 12 ) )
return 128 ;
V_130 = F_122 ( & V_221 [ 12 ] ) ;
if ( V_130 > 0xffff )
return 32 ;
return 16 ;
}
static void F_123 ( struct V_5 * V_6 , T_2 V_223 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_223 , V_6 ) ;
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
F_123 ( V_6 , V_218 , V_150 ) ;
}
static int F_125 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_224 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
struct V_225 * V_221 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_120 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_218 ,
V_173 ) ;
goto V_174;
}
V_221 = F_15 ( sizeof( * V_221 ) , V_39 ) ;
if ( ! V_221 ) {
V_34 = - V_40 ;
goto V_174;
}
memcpy ( V_221 -> V_221 , V_128 -> V_221 , 16 ) ;
V_221 -> V_226 = V_128 -> V_226 ;
V_221 -> V_227 = F_121 ( V_128 -> V_221 ) ;
F_126 ( & V_221 -> V_181 , & V_6 -> V_228 ) ;
F_53 ( & V_139 , V_6 ) ;
F_55 ( & V_139 ) ;
F_54 ( & V_139 ) ;
V_34 = F_56 ( & V_139 , F_124 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_177 )
goto V_174;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_218 , 0 ,
V_6 -> V_146 , 3 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_218 , V_6 , V_7 , V_8 ) ;
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
F_84 ( V_6 -> V_229 , & V_6 -> V_137 ,
V_230 ) ;
return true ;
}
return false ;
}
static void F_128 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
F_10 ( L_7 , V_150 ) ;
F_123 ( V_6 , V_219 , V_150 ) ;
}
static int F_129 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_231 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_225 * V_180 , * V_232 ;
T_1 V_233 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_138 V_139 ;
int V_34 , V_234 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_120 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_219 ,
V_173 ) ;
goto V_188;
}
if ( memcmp ( V_128 -> V_221 , V_233 , 16 ) == 0 ) {
F_130 ( V_6 ) ;
if ( F_127 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_219 ,
0 , V_6 -> V_146 , 3 ) ;
goto V_188;
}
goto V_235;
}
V_234 = 0 ;
F_131 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_180 -> V_221 , V_128 -> V_221 , 16 ) != 0 )
continue;
F_88 ( & V_180 -> V_181 ) ;
F_17 ( V_180 ) ;
V_234 ++ ;
}
if ( V_234 == 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_219 ,
V_172 ) ;
goto V_188;
}
V_235:
F_53 ( & V_139 , V_6 ) ;
F_55 ( & V_139 ) ;
F_54 ( & V_139 ) ;
V_34 = F_56 ( & V_139 , F_128 ) ;
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
static void F_132 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
F_10 ( L_7 , V_150 ) ;
F_123 ( V_6 , V_220 , V_150 ) ;
}
static int F_133 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_236 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_220 ,
V_185 ) ;
F_35 ( V_6 ) ;
if ( F_120 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_220 ,
V_173 ) ;
goto V_188;
}
if ( ( V_128 -> V_237 & 0x03 ) != 0 || ( V_128 -> V_238 & 0xe0 ) != 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_220 ,
V_172 ) ;
goto V_188;
}
V_6 -> V_239 = V_128 -> V_238 ;
V_6 -> V_240 = V_128 -> V_237 ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_220 , 0 ,
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
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_220 , 0 ,
V_6 -> V_146 , 3 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_220 , V_6 , V_7 , V_8 ) ;
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
struct V_241 * V_128 = V_7 ;
const T_2 V_242 = ( ( V_243 - sizeof( * V_128 ) ) /
sizeof( struct V_244 ) ) ;
T_2 V_245 , V_246 ;
bool V_197 ;
int V_33 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_247 ,
V_185 ) ;
V_245 = F_101 ( V_128 -> V_245 ) ;
if ( V_245 > V_242 ) {
F_136 ( L_8 ,
V_245 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_247 ,
V_172 ) ;
}
V_246 = sizeof( * V_128 ) + V_245 *
sizeof( struct V_244 ) ;
if ( V_246 != V_8 ) {
F_136 ( L_9 ,
V_246 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_247 ,
V_172 ) ;
}
if ( V_128 -> V_248 != 0x00 && V_128 -> V_248 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_247 ,
V_172 ) ;
F_10 ( L_10 , V_6 -> V_83 , V_128 -> V_248 ,
V_245 ) ;
for ( V_33 = 0 ; V_33 < V_245 ; V_33 ++ ) {
struct V_244 * V_249 = & V_128 -> V_250 [ V_33 ] ;
if ( V_249 -> V_251 . type != V_252 || V_249 -> type > 0x08 )
return F_82 ( V_19 , V_6 -> V_59 ,
V_247 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_137 ( V_6 ) ;
if ( V_128 -> V_248 )
V_197 = ! F_61 ( V_6 , V_119 ) ;
else
V_197 = F_52 ( V_6 ,
V_119 ) ;
if ( V_197 )
F_85 ( V_6 , NULL ) ;
for ( V_33 = 0 ; V_33 < V_245 ; V_33 ++ ) {
struct V_244 * V_249 = & V_128 -> V_250 [ V_33 ] ;
if ( V_249 -> type == V_253 )
continue;
F_138 ( V_6 , NULL , & V_249 -> V_251 . V_122 , V_249 -> V_130 ,
V_249 -> type , V_249 -> V_254 , NULL ) ;
}
F_12 ( V_19 , V_6 -> V_59 , V_247 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int F_139 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_255 , struct V_11 * V_12 )
{
struct V_256 V_155 ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = V_255 ;
return F_7 ( V_257 , V_6 , & V_155 , sizeof( V_155 ) ,
V_12 ) ;
}
static int F_140 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_258 * V_128 = V_7 ;
struct V_259 V_22 ;
struct V_260 * V_261 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
T_1 V_255 ;
int V_34 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_251 . V_122 , & V_128 -> V_251 . V_122 ) ;
V_22 . V_251 . type = V_128 -> V_251 . type ;
if ( ! F_141 ( V_128 -> V_251 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_262 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_128 -> V_263 != 0x00 && V_128 -> V_263 != 0x01 )
return F_12 ( V_19 , V_6 -> V_59 , V_262 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_262 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( V_128 -> V_251 . type == V_252 ) {
if ( V_128 -> V_263 )
V_162 = F_142 ( V_6 , V_264 ,
& V_128 -> V_251 . V_122 ) ;
else
V_162 = NULL ;
V_34 = F_143 ( V_6 , & V_128 -> V_251 . V_122 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_262 ,
V_265 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
goto V_266;
}
V_255 = F_8 ( V_128 -> V_251 . type ) ;
F_144 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ) ;
V_34 = F_145 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_262 ,
V_265 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
V_162 = F_146 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ) ;
if ( ! V_162 ) {
F_147 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ) ;
goto V_266;
}
F_148 ( V_162 ) ;
F_149 ( V_267 , & V_162 -> V_165 ) ;
V_261 = F_150 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ) ;
if ( V_261 ) {
if ( V_261 -> V_268 )
V_261 -> V_269 = V_270 ;
else
V_261 -> V_269 = V_271 ;
}
if ( ! V_128 -> V_263 )
V_162 = NULL ;
V_266:
if ( ! V_162 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_262 , 0 ,
& V_22 , sizeof( V_22 ) ) ;
F_139 ( V_6 , & V_128 -> V_251 . V_122 , V_128 -> V_251 . type , V_19 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_262 , V_6 , V_128 ,
sizeof( * V_128 ) ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_125 -> V_182 = F_95 ;
V_34 = F_151 ( V_162 , V_272 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int V_263 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_273 * V_128 = V_7 ;
struct V_274 V_22 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_4 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_251 . V_122 , & V_128 -> V_251 . V_122 ) ;
V_22 . V_251 . type = V_128 -> V_251 . type ;
if ( ! F_141 ( V_128 -> V_251 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_275 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_23 ( V_276 , & V_6 -> V_165 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_275 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_174;
}
if ( F_44 ( V_275 , V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_275 ,
V_173 , & V_22 , sizeof( V_22 ) ) ;
goto V_174;
}
if ( V_128 -> V_251 . type == V_252 )
V_162 = F_142 ( V_6 , V_264 ,
& V_128 -> V_251 . V_122 ) ;
else
V_162 = F_146 ( V_6 , & V_128 -> V_251 . V_122 ,
F_8 ( V_128 -> V_251 . type ) ) ;
if ( ! V_162 || V_162 -> V_277 == V_278 || V_162 -> V_277 == V_279 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_275 ,
V_280 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_275 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_94 ;
V_34 = F_152 ( V_162 , V_272 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static T_1 F_153 ( T_1 V_281 , T_1 V_255 )
{
switch ( V_281 ) {
case V_282 :
switch ( V_255 ) {
case V_17 :
return V_16 ;
default:
return V_283 ;
}
default:
return V_252 ;
}
}
static int F_154 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_20 )
{
struct V_284 * V_22 ;
struct V_161 * V_285 ;
T_3 V_46 ;
int V_34 ;
T_2 V_33 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_286 ,
V_196 ) ;
goto V_188;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_23 ( V_287 , & V_285 -> V_165 ) )
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
if ( ! F_23 ( V_287 , & V_285 -> V_165 ) )
continue;
F_65 ( & V_22 -> V_251 [ V_33 ] . V_122 , & V_285 -> V_288 ) ;
V_22 -> V_251 [ V_33 ] . type = F_153 ( V_285 -> type , V_285 -> V_289 ) ;
if ( V_285 -> type == V_290 || V_285 -> type == V_291 )
continue;
V_33 ++ ;
}
V_22 -> V_292 = F_11 ( V_33 ) ;
V_46 = sizeof( * V_22 ) + ( V_33 * sizeof( struct V_184 ) ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_286 , 0 , V_22 ,
V_46 ) ;
F_17 ( V_22 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_155 ( struct V_11 * V_19 , struct V_5 * V_6 ,
struct V_293 * V_128 )
{
struct V_124 * V_125 ;
int V_34 ;
V_125 = F_83 ( V_19 , V_294 , V_6 , V_128 ,
sizeof( * V_128 ) ) ;
if ( ! V_125 )
return - V_40 ;
V_34 = F_110 ( V_6 , V_295 ,
sizeof( V_128 -> V_251 . V_122 ) , & V_128 -> V_251 . V_122 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
return V_34 ;
}
static int F_156 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_162 ;
struct V_296 * V_128 = V_7 ;
struct V_297 V_298 ;
struct V_124 * V_125 ;
int V_34 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_299 ,
V_196 ) ;
goto V_174;
}
V_162 = F_142 ( V_6 , V_264 , & V_128 -> V_251 . V_122 ) ;
if ( ! V_162 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_299 ,
V_280 ) ;
goto V_174;
}
if ( V_162 -> V_300 == V_301 && V_128 -> V_254 != 16 ) {
struct V_293 V_302 ;
memcpy ( & V_302 . V_251 , & V_128 -> V_251 , sizeof( V_302 . V_251 ) ) ;
F_136 ( L_11 ) ;
V_34 = F_155 ( V_19 , V_6 , & V_302 ) ;
if ( V_34 >= 0 )
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_299 ,
V_172 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_299 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_95 ;
F_65 ( & V_298 . V_122 , & V_128 -> V_251 . V_122 ) ;
V_298 . V_254 = V_128 -> V_254 ;
memcpy ( V_298 . V_303 , V_128 -> V_303 , sizeof( V_298 . V_303 ) ) ;
V_34 = F_110 ( V_6 , V_304 , sizeof( V_298 ) , & V_298 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_157 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_305 * V_128 = V_7 ;
F_10 ( L_4 ) ;
if ( V_128 -> V_306 > V_307 )
return F_12 ( V_19 , V_6 -> V_59 , V_308 ,
V_172 , NULL , 0 ) ;
F_35 ( V_6 ) ;
V_6 -> V_306 = V_128 -> V_306 ;
F_10 ( L_12 , V_6 -> V_83 ,
V_6 -> V_306 ) ;
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_308 , 0 ,
NULL , 0 ) ;
}
static struct V_124 * F_158 ( struct V_161 * V_162 )
{
struct V_5 * V_6 = V_162 -> V_6 ;
struct V_124 * V_125 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_125 -> V_41 != V_309 )
continue;
if ( V_125 -> V_310 != V_162 )
continue;
return V_125 ;
}
return NULL ;
}
static int F_159 ( struct V_124 * V_125 , T_1 V_150 )
{
struct V_311 V_22 ;
struct V_161 * V_162 = V_125 -> V_310 ;
int V_34 ;
F_65 ( & V_22 . V_251 . V_122 , & V_162 -> V_288 ) ;
V_22 . V_251 . type = F_153 ( V_162 -> type , V_162 -> V_289 ) ;
V_34 = F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_309 ,
V_150 , & V_22 , sizeof( V_22 ) ) ;
V_162 -> V_312 = NULL ;
V_162 -> V_313 = NULL ;
V_162 -> V_314 = NULL ;
F_160 ( V_162 ) ;
F_161 ( V_267 , & V_162 -> V_165 ) ;
F_162 ( V_162 ) ;
return V_34 ;
}
void F_163 ( struct V_161 * V_162 , bool V_315 )
{
T_1 V_150 = V_315 ? V_187 : V_3 ;
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
struct V_316 * V_128 = V_7 ;
struct V_311 V_22 ;
struct V_124 * V_125 ;
T_1 V_317 , V_318 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_4 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_251 . V_122 , & V_128 -> V_251 . V_122 ) ;
V_22 . V_251 . type = V_128 -> V_251 . type ;
if ( ! F_141 ( V_128 -> V_251 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_309 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_128 -> V_319 > V_307 )
return F_12 ( V_19 , V_6 -> V_59 , V_309 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_309 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( F_167 ( V_6 , & V_128 -> V_251 . V_122 , V_128 -> V_251 . type ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_309 ,
V_320 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
V_317 = V_321 ;
V_318 = V_322 ;
if ( V_128 -> V_251 . type == V_252 ) {
V_162 = F_168 ( V_6 , & V_128 -> V_251 . V_122 , V_317 ,
V_318 ) ;
} else {
T_1 V_255 = F_8 ( V_128 -> V_251 . type ) ;
struct V_260 * V_323 ;
V_323 = F_169 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ) ;
if ( V_323 -> V_269 == V_270 )
V_323 -> V_269 = V_271 ;
V_162 = F_170 ( V_6 , & V_128 -> V_251 . V_122 ,
V_255 , V_317 ,
V_324 ) ;
}
if ( F_171 ( V_162 ) ) {
int V_150 ;
if ( F_172 ( V_162 ) == - V_325 )
V_150 = V_173 ;
else if ( F_172 ( V_162 ) == - V_326 )
V_150 = V_185 ;
else if ( F_172 ( V_162 ) == - V_327 )
V_150 = V_186 ;
else
V_150 = V_328 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_309 ,
V_150 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
if ( V_162 -> V_312 ) {
F_160 ( V_162 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_309 ,
V_173 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_309 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
F_160 ( V_162 ) ;
goto V_188;
}
V_125 -> V_182 = F_159 ;
if ( V_128 -> V_251 . type == V_252 ) {
V_162 -> V_312 = F_164 ;
V_162 -> V_313 = F_164 ;
V_162 -> V_314 = F_164 ;
} else {
V_162 -> V_312 = F_165 ;
V_162 -> V_313 = F_165 ;
V_162 -> V_314 = F_165 ;
}
V_162 -> V_306 = V_128 -> V_319 ;
V_125 -> V_310 = F_173 ( V_162 ) ;
if ( ( V_162 -> V_277 == V_329 || V_162 -> V_277 == V_330 ) &&
F_174 ( V_162 , V_317 , V_318 , true ) ) {
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
struct V_184 * V_251 = V_7 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_331 ,
V_196 ) ;
goto V_188;
}
V_125 = F_44 ( V_309 , V_6 ) ;
if ( ! V_125 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_331 ,
V_172 ) ;
goto V_188;
}
V_162 = V_125 -> V_310 ;
if ( F_29 ( & V_251 -> V_122 , & V_162 -> V_288 ) != 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_331 ,
V_172 ) ;
goto V_188;
}
V_125 -> V_182 ( V_125 , V_332 ) ;
F_92 ( V_125 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_331 , 0 ,
V_251 , sizeof( * V_251 ) ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_176 ( struct V_11 * V_19 , struct V_5 * V_6 ,
struct V_184 * V_251 , T_2 V_223 ,
T_2 V_333 , T_5 V_334 )
{
struct V_124 * V_125 ;
struct V_161 * V_162 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_223 ,
V_196 , V_251 ,
sizeof( * V_251 ) ) ;
goto V_266;
}
if ( V_251 -> type == V_252 )
V_162 = F_142 ( V_6 , V_264 , & V_251 -> V_122 ) ;
else
V_162 = F_146 ( V_6 , & V_251 -> V_122 ,
F_8 ( V_251 -> type ) ) ;
if ( ! V_162 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_223 ,
V_280 , V_251 ,
sizeof( * V_251 ) ) ;
goto V_266;
}
if ( V_251 -> type == V_16 || V_251 -> type == V_283 ) {
V_34 = F_177 ( V_162 , V_223 , V_334 ) ;
if ( ! V_34 )
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_223 ,
V_187 , V_251 ,
sizeof( * V_251 ) ) ;
else
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_223 ,
V_3 , V_251 ,
sizeof( * V_251 ) ) ;
goto V_266;
}
V_125 = F_83 ( V_19 , V_223 , V_6 , V_251 , sizeof( * V_251 ) ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_266;
}
V_125 -> V_182 = F_95 ;
if ( V_333 == V_335 ) {
struct V_336 V_128 ;
F_65 ( & V_128 . V_122 , & V_251 -> V_122 ) ;
V_128 . V_334 = V_334 ;
V_34 = F_110 ( V_6 , V_333 , sizeof( V_128 ) , & V_128 ) ;
} else
V_34 = F_110 ( V_6 , V_333 , sizeof( V_251 -> V_122 ) ,
& V_251 -> V_122 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_266:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_178 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_293 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_251 ,
V_294 ,
V_295 , 0 ) ;
}
static int F_179 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_337 * V_128 = V_7 ;
F_10 ( L_4 ) ;
if ( V_8 != sizeof( * V_128 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_338 ,
V_172 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_251 ,
V_338 ,
V_339 , 0 ) ;
}
static int F_180 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_340 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_251 ,
V_341 ,
V_342 , 0 ) ;
}
static int F_181 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_343 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_251 ,
V_344 ,
V_335 , V_128 -> V_334 ) ;
}
static int F_182 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_345 * V_128 = V_7 ;
F_10 ( L_4 ) ;
return F_176 ( V_19 , V_6 , & V_128 -> V_251 ,
V_346 ,
V_347 , 0 ) ;
}
static void F_183 ( struct V_5 * V_6 , T_1 V_150 , T_2 V_41 )
{
struct V_348 * V_128 ;
struct V_124 * V_125 ;
F_10 ( L_7 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_349 , V_6 ) ;
if ( ! V_125 )
goto V_188;
V_128 = V_125 -> V_129 ;
if ( V_150 )
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_349 ,
F_1 ( V_150 ) ) ;
else
F_12 ( V_125 -> V_19 , V_6 -> V_59 , V_349 , 0 ,
V_128 , sizeof( * V_128 ) ) ;
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
}
static int F_184 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_348 * V_128 = V_7 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_147 , V_128 -> V_83 , sizeof( V_6 -> V_147 ) ) &&
! memcmp ( V_6 -> V_148 , V_128 -> V_148 ,
sizeof( V_6 -> V_148 ) ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_349 , 0 ,
V_7 , V_8 ) ;
goto V_174;
}
memcpy ( V_6 -> V_148 , V_128 -> V_148 , sizeof( V_6 -> V_148 ) ) ;
if ( ! F_43 ( V_6 ) ) {
memcpy ( V_6 -> V_147 , V_128 -> V_83 , sizeof( V_6 -> V_147 ) ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_349 , 0 ,
V_7 , V_8 ) ;
if ( V_34 < 0 )
goto V_174;
V_34 = F_6 ( V_350 , V_6 ,
V_7 , V_8 , V_19 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_349 , V_6 , V_7 , V_8 ) ;
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
F_117 ( & V_139 , V_6 -> V_351 ) ;
V_34 = F_56 ( & V_139 , F_183 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_186 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 , struct V_352 * V_353 )
{
struct V_354 V_355 ;
T_3 V_32 = sizeof( V_355 ) ;
struct V_124 * V_125 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
V_125 = F_44 ( V_356 , V_6 ) ;
if ( ! V_125 )
return;
if ( V_150 || ! V_353 ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_356 ,
V_150 ? F_1 ( V_150 ) : V_3 ) ;
goto remove;
}
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
if ( V_41 == V_357 ) {
struct V_358 * V_22 = ( void * ) V_353 -> V_7 ;
if ( V_353 -> V_8 < sizeof( * V_22 ) ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 ,
V_356 ,
V_3 ) ;
goto remove;
}
memcpy ( V_355 . V_359 , V_22 -> V_360 , sizeof( V_22 -> V_360 ) ) ;
memcpy ( V_355 . V_361 , V_22 -> rand , sizeof( V_22 -> rand ) ) ;
V_32 -= sizeof( V_355 . V_362 ) + sizeof( V_355 . V_363 ) ;
} else {
struct V_364 * V_22 = ( void * ) V_353 -> V_7 ;
if ( V_353 -> V_8 < sizeof( * V_22 ) ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 ,
V_356 ,
V_3 ) ;
goto remove;
}
memcpy ( V_355 . V_359 , V_22 -> V_359 , sizeof( V_22 -> V_359 ) ) ;
memcpy ( V_355 . V_361 , V_22 -> V_361 , sizeof( V_22 -> V_361 ) ) ;
memcpy ( V_355 . V_362 , V_22 -> V_362 , sizeof( V_22 -> V_362 ) ) ;
memcpy ( V_355 . V_363 , V_22 -> V_363 , sizeof( V_22 -> V_363 ) ) ;
}
F_12 ( V_125 -> V_19 , V_6 -> V_59 , V_356 ,
V_187 , & V_355 , V_32 ) ;
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
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_356 ,
V_196 ) ;
goto V_188;
}
if ( ! F_39 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_356 ,
V_185 ) ;
goto V_188;
}
if ( F_44 ( V_356 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_356 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_356 , V_6 , NULL , 0 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
if ( F_188 ( V_6 ) )
F_75 ( & V_139 , V_365 , 0 , NULL ) ;
else
F_75 ( & V_139 , V_357 , 0 , NULL ) ;
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
struct V_184 * V_251 = V_7 ;
int V_34 ;
F_10 ( L_17 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_251 -> type ) )
return F_12 ( V_19 , V_6 -> V_59 ,
V_366 ,
V_172 ,
V_251 , sizeof( * V_251 ) ) ;
F_35 ( V_6 ) ;
if ( V_8 == V_367 ) {
struct V_368 * V_128 = V_7 ;
T_1 V_150 ;
if ( V_128 -> V_251 . type != V_252 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_366 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
V_34 = F_191 ( V_6 , & V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type , V_128 -> V_360 ,
V_128 -> rand , NULL , NULL ) ;
if ( V_34 < 0 )
V_150 = V_3 ;
else
V_150 = V_187 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_366 , V_150 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
} else if ( V_8 == V_369 ) {
struct V_370 * V_128 = V_7 ;
T_1 * V_361 , * V_359 , * V_363 , * V_362 ;
T_1 V_150 ;
if ( F_192 ( V_128 -> V_251 . type ) ) {
if ( memcmp ( V_128 -> V_361 , V_371 , 16 ) ||
memcmp ( V_128 -> V_359 , V_371 , 16 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_366 ,
V_172 ,
V_251 , sizeof( * V_251 ) ) ;
goto V_188;
}
V_361 = NULL ;
V_359 = NULL ;
} else {
if ( ! memcmp ( V_128 -> V_361 , V_371 , 16 ) ||
! memcmp ( V_128 -> V_359 , V_371 , 16 ) ) {
V_361 = NULL ;
V_359 = NULL ;
} else {
V_361 = V_128 -> V_361 ;
V_359 = V_128 -> V_359 ;
}
}
if ( ! memcmp ( V_128 -> V_363 , V_371 , 16 ) ||
! memcmp ( V_128 -> V_362 , V_371 , 16 ) ) {
V_363 = NULL ;
V_362 = NULL ;
} else {
V_363 = V_128 -> V_363 ;
V_362 = V_128 -> V_362 ;
}
V_34 = F_191 ( V_6 , & V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type , V_359 , V_361 ,
V_362 , V_363 ) ;
if ( V_34 < 0 )
V_150 = V_3 ;
else
V_150 = V_187 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_366 ,
V_150 , & V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
} else {
F_136 ( L_18 , V_8 ) ;
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_366 ,
V_172 ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_193 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_372 * V_128 = V_7 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( V_128 -> V_251 . type != V_252 )
return F_12 ( V_19 , V_6 -> V_59 ,
V_373 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_29 ( & V_128 -> V_251 . V_122 , V_76 ) ) {
F_194 ( V_6 ) ;
V_150 = V_187 ;
goto V_266;
}
V_34 = F_195 ( V_6 , & V_128 -> V_251 . V_122 , V_128 -> V_251 . type ) ;
if ( V_34 < 0 )
V_150 = V_172 ;
else
V_150 = V_187 ;
V_266:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_373 ,
V_150 , & V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
void F_196 ( struct V_5 * V_6 , T_1 V_150 )
{
struct V_124 * V_125 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_374 , V_6 ) ;
if ( ! V_125 )
V_125 = F_44 ( V_375 , V_6 ) ;
if ( ! V_125 )
V_125 = F_44 ( V_376 , V_6 ) ;
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
case V_377 :
* F_1 = F_97 ( V_6 ) ;
if ( * F_1 )
return false ;
break;
case V_378 :
* F_1 = F_97 ( V_6 ) ;
if ( * F_1 )
return false ;
case V_379 :
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
T_2 V_380 , void * V_7 , T_2 V_8 )
{
struct V_381 * V_128 = V_7 ;
struct V_124 * V_125 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_380 ,
V_196 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( V_6 -> V_382 . V_277 != V_383 ||
F_21 ( V_6 , V_384 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_380 , V_173 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( ! F_197 ( V_6 , V_128 -> type , & V_150 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_380 , V_150 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
F_199 ( V_6 ) ;
V_6 -> V_382 . type = V_128 -> type ;
V_6 -> V_382 . V_385 = false ;
if ( V_380 == V_376 )
V_6 -> V_382 . V_386 = true ;
else
V_6 -> V_382 . V_386 = false ;
V_125 = F_83 ( V_19 , V_380 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_94 ;
F_80 ( V_6 , V_387 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_388 ) ;
V_34 = 0 ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_200 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
return F_198 ( V_19 , V_6 , V_374 ,
V_7 , V_8 ) ;
}
static int F_201 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
return F_198 ( V_19 , V_6 ,
V_376 ,
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
struct V_389 * V_128 = V_7 ;
struct V_124 * V_125 ;
const T_2 V_390 = ( ( V_243 - sizeof( * V_128 ) ) / 16 ) ;
T_2 V_391 , V_246 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_375 ,
V_196 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( V_6 -> V_382 . V_277 != V_383 ||
F_21 ( V_6 , V_384 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_375 ,
V_173 , & V_128 -> type ,
sizeof( V_128 -> type ) ) ;
goto V_174;
}
V_391 = F_101 ( V_128 -> V_391 ) ;
if ( V_391 > V_390 ) {
F_136 ( L_20 ,
V_391 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_375 ,
V_172 , & V_128 -> type ,
sizeof( V_128 -> type ) ) ;
goto V_174;
}
V_246 = sizeof( * V_128 ) + V_391 * 16 ;
if ( V_246 != V_8 ) {
F_136 ( L_21 ,
V_246 , V_8 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_375 ,
V_172 , & V_128 -> type ,
sizeof( V_128 -> type ) ) ;
goto V_174;
}
if ( ! F_197 ( V_6 , V_128 -> type , & V_150 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_375 ,
V_150 , & V_128 -> type , sizeof( V_128 -> type ) ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_375 ,
V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
V_125 -> V_182 = F_202 ;
F_199 ( V_6 ) ;
V_6 -> V_382 . V_392 = true ;
V_6 -> V_382 . type = V_128 -> type ;
V_6 -> V_382 . V_393 = V_128 -> V_393 ;
V_6 -> V_382 . V_391 = V_391 ;
if ( V_391 > 0 ) {
V_6 -> V_382 . V_228 = F_204 ( V_128 -> V_228 , V_391 * 16 ,
V_39 ) ;
if ( ! V_6 -> V_382 . V_228 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_375 ,
V_3 ,
& V_128 -> type , sizeof( V_128 -> type ) ) ;
F_92 ( V_125 ) ;
goto V_174;
}
}
F_80 ( V_6 , V_387 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_388 ) ;
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
V_125 = F_44 ( V_394 , V_6 ) ;
if ( V_125 ) {
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
F_36 ( V_6 ) ;
}
static int F_206 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_395 * V_396 = V_7 ;
struct V_124 * V_125 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_207 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_394 ,
V_186 , & V_396 -> type ,
sizeof( V_396 -> type ) ) ;
goto V_188;
}
if ( V_6 -> V_382 . type != V_396 -> type ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_394 ,
V_172 ,
& V_396 -> type , sizeof( V_396 -> type ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_394 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_125 -> V_182 = F_94 ;
F_80 ( V_6 , V_170 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_388 ) ;
V_34 = 0 ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_208 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_397 * V_128 = V_7 ;
struct V_398 * V_399 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_207 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_400 ,
V_3 , & V_128 -> V_251 ,
sizeof( V_128 -> V_251 ) ) ;
goto V_174;
}
V_399 = F_209 ( V_6 , & V_128 -> V_251 . V_122 ) ;
if ( ! V_399 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_400 ,
V_172 , & V_128 -> V_251 ,
sizeof( V_128 -> V_251 ) ) ;
goto V_174;
}
if ( V_128 -> V_401 ) {
V_399 -> V_402 = V_403 ;
F_88 ( & V_399 -> V_181 ) ;
} else {
V_399 -> V_402 = V_404 ;
F_210 ( V_6 , V_399 ) ;
}
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_400 , 0 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
V_174:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_211 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_405 * V_128 = V_7 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_128 -> V_251 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_406 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_212 ( & V_6 -> V_407 , & V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type ) ;
if ( V_34 < 0 ) {
V_150 = V_3 ;
goto V_266;
}
F_7 ( V_408 , V_6 , & V_128 -> V_251 , sizeof( V_128 -> V_251 ) ,
V_19 ) ;
V_150 = V_187 ;
V_266:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_406 , V_150 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_213 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_409 * V_128 = V_7 ;
T_1 V_150 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_128 -> V_251 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_410 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_214 ( & V_6 -> V_407 , & V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type ) ;
if ( V_34 < 0 ) {
V_150 = V_172 ;
goto V_266;
}
F_7 ( V_411 , V_6 , & V_128 -> V_251 , sizeof( V_128 -> V_251 ) ,
V_19 ) ;
V_150 = V_187 ;
V_266:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_410 , V_150 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_215 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_412 * V_128 = V_7 ;
struct V_138 V_139 ;
int V_34 ;
T_9 V_413 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
V_413 = F_101 ( V_128 -> V_413 ) ;
if ( V_413 > 0x0002 )
return F_82 ( V_19 , V_6 -> V_59 , V_414 ,
V_172 ) ;
F_35 ( V_6 ) ;
V_6 -> V_415 = V_413 ;
V_6 -> V_416 = F_101 ( V_128 -> V_417 ) ;
V_6 -> V_418 = F_101 ( V_128 -> V_419 ) ;
V_6 -> V_420 = F_101 ( V_128 -> V_23 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_414 , 0 ,
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
struct V_421 * V_422 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_114 ( V_214 , V_6 ,
F_91 , & V_189 ) ;
goto V_188;
}
if ( F_21 ( V_6 , V_169 ) )
F_58 ( V_6 , V_117 ) ;
else
F_63 ( V_6 , V_117 ) ;
F_114 ( V_214 , V_6 , F_87 ,
& V_180 ) ;
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
if ( F_21 ( V_6 , V_117 ) ||
F_218 ( & V_6 -> V_423 ) )
goto V_188;
V_153 = V_6 -> V_351 ;
if ( ! V_153 ) {
V_422 = F_219 ( & V_6 -> V_423 ,
struct V_421 , V_181 ) ;
if ( ! V_422 )
goto V_188;
V_153 = V_422 -> V_153 ;
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
return F_82 ( V_19 , V_6 -> V_59 , V_214 ,
V_150 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_214 ,
V_172 ) ;
F_35 ( V_6 ) ;
V_130 = ! ! V_128 -> V_130 ;
if ( ! F_43 ( V_6 ) ||
( V_130 == F_21 ( V_6 , V_117 ) &&
( V_128 -> V_130 == 0x02 ) == F_21 ( V_6 , V_424 ) ) ||
F_222 ( V_6 , V_282 ) > 0 ||
( F_21 ( V_6 , V_425 ) &&
V_6 -> V_426 == V_427 ) ) {
bool V_197 ;
if ( V_128 -> V_130 ) {
V_6 -> V_351 = 0x00 ;
V_197 = ! F_61 ( V_6 , V_117 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_424 ) ;
else
F_63 ( V_6 , V_424 ) ;
} else {
V_197 = F_52 ( V_6 , V_117 ) ;
F_63 ( V_6 , V_424 ) ;
}
V_34 = F_66 ( V_19 , V_214 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_188;
}
if ( F_44 ( V_214 , V_6 ) ||
F_44 ( V_210 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_214 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_214 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_424 ) ;
else
F_63 ( V_6 , V_424 ) ;
F_73 ( V_6 ) ;
if ( V_130 ) {
V_6 -> V_351 = 0x00 ;
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
struct V_428 * V_128 = V_7 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_429 ,
V_185 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_429 ,
V_186 ) ;
if ( F_29 ( & V_128 -> V_122 , V_76 ) ) {
if ( ! F_29 ( & V_128 -> V_122 , V_430 ) )
return F_82 ( V_19 , V_6 -> V_59 ,
V_429 ,
V_172 ) ;
if ( ( V_128 -> V_122 . V_431 [ 5 ] & 0xc0 ) != 0xc0 )
return F_82 ( V_19 , V_6 -> V_59 ,
V_429 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_65 ( & V_6 -> V_123 , & V_128 -> V_122 ) ;
V_34 = F_66 ( V_19 , V_429 , V_6 ) ;
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
struct V_432 * V_128 = V_7 ;
T_9 V_433 , V_434 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_435 ,
V_185 ) ;
V_433 = F_101 ( V_128 -> V_433 ) ;
if ( V_433 < 0x0004 || V_433 > 0x4000 )
return F_82 ( V_19 , V_6 -> V_59 , V_435 ,
V_172 ) ;
V_434 = F_101 ( V_128 -> V_434 ) ;
if ( V_434 < 0x0004 || V_434 > 0x4000 )
return F_82 ( V_19 , V_6 -> V_59 , V_435 ,
V_172 ) ;
if ( V_434 > V_433 )
return F_82 ( V_19 , V_6 -> V_59 , V_435 ,
V_172 ) ;
F_35 ( V_6 ) ;
V_6 -> V_436 = V_433 ;
V_6 -> V_437 = V_434 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_435 , 0 ,
NULL , 0 ) ;
if ( F_21 ( V_6 , V_425 ) &&
V_6 -> V_382 . V_277 == V_383 ) {
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
V_125 = F_44 ( V_438 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_438 ,
F_1 ( V_150 ) ) ;
} else {
struct V_127 * V_128 = V_125 -> V_129 ;
if ( V_128 -> V_130 )
F_58 ( V_6 , V_109 ) ;
else
F_63 ( V_6 , V_109 ) ;
F_66 ( V_125 -> V_19 , V_438 , V_6 ) ;
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
return F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_185 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_438 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_438 ,
V_173 ) ;
goto V_188;
}
if ( ! ! V_128 -> V_130 == F_21 ( V_6 , V_109 ) ) {
V_34 = F_66 ( V_19 , V_438 ,
V_6 ) ;
goto V_188;
}
if ( ! F_43 ( V_6 ) ) {
F_102 ( V_6 , V_109 ) ;
V_34 = F_66 ( V_19 , V_438 ,
V_6 ) ;
F_85 ( V_6 , V_19 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_438 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
F_229 ( & V_139 , V_128 -> V_130 ) ;
V_34 = F_56 ( & V_139 , F_227 ) ;
if ( V_34 < 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_438 ,
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
V_125 = F_44 ( V_439 , V_6 ) ;
if ( ! V_125 )
goto V_188;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
F_63 ( V_6 , V_112 ) ;
F_82 ( V_125 -> V_19 , V_125 -> V_58 , V_125 -> V_41 , V_189 ) ;
} else {
F_66 ( V_125 -> V_19 , V_439 , V_6 ) ;
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
return F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_185 ) ;
if ( ! F_21 ( V_6 , V_113 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_130 == F_21 ( V_6 , V_112 ) ) {
V_34 = F_66 ( V_19 , V_439 , V_6 ) ;
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
V_34 = F_66 ( V_19 , V_439 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_188;
}
if ( ! V_128 -> V_130 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_186 ) ;
goto V_188;
} else {
if ( ! F_21 ( V_6 , V_112 ) &&
( F_29 ( & V_6 -> V_123 , V_76 ) ||
F_21 ( V_6 , V_118 ) ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_186 ) ;
goto V_188;
}
}
if ( F_44 ( V_439 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_439 ,
V_173 ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_439 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_58 ( V_6 , V_112 ) ;
F_53 ( & V_139 , V_6 ) ;
F_229 ( & V_139 , false ) ;
F_232 ( & V_139 ) ;
F_116 ( & V_139 , V_6 -> V_351 ) ;
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
V_125 = F_44 ( V_440 , V_6 ) ;
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
F_63 ( V_6 , V_441 ) ;
break;
case 0x01 :
F_58 ( V_6 , V_118 ) ;
F_63 ( V_6 , V_441 ) ;
break;
case 0x02 :
F_58 ( V_6 , V_118 ) ;
F_58 ( V_6 , V_441 ) ;
break;
}
F_66 ( V_125 -> V_19 , V_440 , V_6 ) ;
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
return F_82 ( V_19 , V_6 -> V_59 , V_440 ,
V_185 ) ;
if ( F_21 ( V_6 , V_112 ) &&
F_40 ( V_6 ) &&
! F_21 ( V_6 , V_115 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_440 ,
V_186 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_440 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) || ! F_40 ( V_6 ) ||
! F_21 ( V_6 , V_112 ) ) {
bool V_197 ;
if ( V_128 -> V_130 ) {
V_197 = ! F_61 ( V_6 ,
V_118 ) ;
if ( V_128 -> V_130 == 0x02 )
F_58 ( V_6 , V_441 ) ;
else
F_63 ( V_6 , V_441 ) ;
} else {
V_197 = F_52 ( V_6 ,
V_118 ) ;
F_63 ( V_6 , V_441 ) ;
}
V_34 = F_66 ( V_19 , V_440 , V_6 ) ;
if ( V_34 < 0 )
goto V_174;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
goto V_174;
}
if ( F_44 ( V_440 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_440 ,
V_173 ) ;
goto V_174;
}
V_130 = ! ! V_128 -> V_130 ;
if ( V_130 == F_21 ( V_6 , V_118 ) &&
( V_128 -> V_130 == 0x02 ) == F_21 ( V_6 , V_441 ) ) {
V_34 = F_66 ( V_19 , V_440 , V_6 ) ;
goto V_174;
}
V_125 = F_83 ( V_19 , V_440 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_174;
}
F_53 ( & V_139 , V_6 ) ;
F_75 ( & V_139 , V_442 , 1 , & V_130 ) ;
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
bool V_197 , V_443 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( V_128 -> V_130 != 0x00 && V_128 -> V_130 != 0x01 && V_128 -> V_130 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_444 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_130 )
V_197 = ! F_61 ( V_6 , V_119 ) ;
else
V_197 = F_52 ( V_6 ,
V_119 ) ;
if ( V_128 -> V_130 == 0x02 )
V_443 = ! F_61 ( V_6 ,
V_206 ) ;
else
V_443 = F_52 ( V_6 ,
V_206 ) ;
if ( F_43 ( V_6 ) && V_443 &&
F_21 ( V_6 , V_115 ) ) {
T_1 V_445 = ( V_128 -> V_130 == 0x02 ) ? 0x01 : 0x00 ;
F_110 ( V_6 , V_207 ,
sizeof( V_445 ) , & V_445 ) ;
}
V_34 = F_66 ( V_19 , V_444 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_236 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_446 ,
T_2 V_8 )
{
struct V_447 * V_128 = V_446 ;
bool V_197 ;
int V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_448 ,
V_185 ) ;
if ( V_128 -> V_449 != 0x00 && V_128 -> V_449 != 0x01 && V_128 -> V_449 != 0x02 )
return F_82 ( V_19 , V_6 -> V_59 , V_448 ,
V_172 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_448 ,
V_186 ) ;
F_35 ( V_6 ) ;
F_58 ( V_6 , V_450 ) ;
if ( V_128 -> V_449 ) {
V_197 = ! F_61 ( V_6 , V_120 ) ;
memcpy ( V_6 -> V_451 , V_128 -> V_451 , sizeof( V_6 -> V_451 ) ) ;
F_58 ( V_6 , V_141 ) ;
if ( V_128 -> V_449 == 0x02 )
F_58 ( V_6 , V_201 ) ;
else
F_63 ( V_6 , V_201 ) ;
} else {
V_197 = F_52 ( V_6 , V_120 ) ;
memset ( V_6 -> V_451 , 0 , sizeof( V_6 -> V_451 ) ) ;
F_63 ( V_6 , V_141 ) ;
F_63 ( V_6 , V_201 ) ;
}
V_34 = F_66 ( V_19 , V_448 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( V_197 )
V_34 = F_85 ( V_6 , V_19 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_237 ( struct V_452 * V_451 )
{
switch ( V_451 -> V_251 . type ) {
case V_16 :
return true ;
case V_283 :
if ( ( V_451 -> V_251 . V_122 . V_431 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_238 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_446 ,
T_2 V_8 )
{
struct V_453 * V_128 = V_446 ;
const T_2 V_454 = ( ( V_243 - sizeof( * V_128 ) ) /
sizeof( struct V_452 ) ) ;
T_2 V_455 , V_246 ;
int V_33 , V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_456 ,
V_185 ) ;
V_455 = F_101 ( V_128 -> V_455 ) ;
if ( V_455 > V_454 ) {
F_136 ( L_23 , V_455 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_456 ,
V_172 ) ;
}
V_246 = sizeof( * V_128 ) + V_455 * sizeof( struct V_452 ) ;
if ( V_246 != V_8 ) {
F_136 ( L_24 ,
V_246 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_456 ,
V_172 ) ;
}
F_10 ( L_25 , V_6 -> V_83 , V_455 ) ;
for ( V_33 = 0 ; V_33 < V_455 ; V_33 ++ ) {
struct V_452 * V_249 = & V_128 -> V_457 [ V_33 ] ;
if ( ! F_237 ( V_249 ) )
return F_82 ( V_19 , V_6 -> V_59 ,
V_456 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_239 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_455 ; V_33 ++ ) {
struct V_452 * V_451 = & V_128 -> V_457 [ V_33 ] ;
F_240 ( V_6 , & V_451 -> V_251 . V_122 ,
F_8 ( V_451 -> V_251 . type ) , V_451 -> V_130 ,
V_76 ) ;
}
F_58 ( V_6 , V_450 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_456 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_241 ( struct V_458 * V_249 )
{
if ( V_249 -> V_459 != 0x00 && V_249 -> V_459 != 0x01 )
return false ;
switch ( V_249 -> V_251 . type ) {
case V_16 :
return true ;
case V_283 :
if ( ( V_249 -> V_251 . V_122 . V_431 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_242 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_446 , T_2 V_8 )
{
struct V_460 * V_128 = V_446 ;
const T_2 V_242 = ( ( V_243 - sizeof( * V_128 ) ) /
sizeof( struct V_458 ) ) ;
T_2 V_245 , V_246 ;
int V_33 , V_34 ;
F_10 ( L_6 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_461 ,
V_185 ) ;
V_245 = F_101 ( V_128 -> V_245 ) ;
if ( V_245 > V_242 ) {
F_136 ( L_26 , V_245 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_461 ,
V_172 ) ;
}
V_246 = sizeof( * V_128 ) + V_245 *
sizeof( struct V_458 ) ;
if ( V_246 != V_8 ) {
F_136 ( L_27 ,
V_246 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_461 ,
V_172 ) ;
}
F_10 ( L_28 , V_6 -> V_83 , V_245 ) ;
for ( V_33 = 0 ; V_33 < V_245 ; V_33 ++ ) {
struct V_458 * V_249 = & V_128 -> V_250 [ V_33 ] ;
if ( ! F_241 ( V_249 ) )
return F_82 ( V_19 , V_6 -> V_59 ,
V_461 ,
V_172 ) ;
}
F_35 ( V_6 ) ;
F_243 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_245 ; V_33 ++ ) {
struct V_458 * V_249 = & V_128 -> V_250 [ V_33 ] ;
T_1 type , V_462 ;
switch ( V_249 -> type ) {
case V_463 :
V_462 = 0x00 ;
type = V_249 -> V_459 ? V_464 : V_465 ;
break;
case V_466 :
V_462 = 0x01 ;
type = V_249 -> V_459 ? V_464 : V_465 ;
break;
case V_467 :
V_462 = 0x00 ;
type = V_468 ;
break;
case V_469 :
V_462 = 0x01 ;
type = V_468 ;
break;
case V_470 :
V_462 = 0x00 ;
type = V_471 ;
default:
continue;
}
F_244 ( V_6 , & V_249 -> V_251 . V_122 ,
F_8 ( V_249 -> V_251 . type ) , type , V_462 ,
V_249 -> V_130 , V_249 -> V_472 , V_249 -> V_473 , V_249 -> rand ) ;
}
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_461 , 0 ,
NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_245 ( struct V_124 * V_125 , T_1 V_150 )
{
struct V_161 * V_162 = V_125 -> V_310 ;
struct V_474 V_22 ;
int V_34 ;
memcpy ( & V_22 . V_251 , V_125 -> V_129 , sizeof( V_22 . V_251 ) ) ;
if ( V_150 == V_187 ) {
V_22 . V_393 = V_162 -> V_393 ;
V_22 . V_475 = V_162 -> V_475 ;
V_22 . V_476 = V_162 -> V_476 ;
} else {
V_22 . V_393 = V_477 ;
V_22 . V_475 = V_478 ;
V_22 . V_476 = V_478 ;
}
V_34 = F_12 ( V_125 -> V_19 , V_125 -> V_58 , V_479 ,
V_150 , & V_22 , sizeof( V_22 ) ) ;
F_160 ( V_162 ) ;
F_162 ( V_162 ) ;
return V_34 ;
}
static void F_246 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_41 )
{
struct V_480 * V_128 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
T_2 V_481 ;
T_1 V_150 ;
F_10 ( L_7 , V_1 ) ;
F_35 ( V_6 ) ;
V_128 = F_247 ( V_6 , V_482 ) ;
if ( ! V_128 ) {
V_128 = F_247 ( V_6 , V_483 ) ;
V_150 = V_187 ;
} else {
V_150 = F_1 ( V_1 ) ;
}
if ( ! V_128 ) {
F_136 ( L_29 ) ;
goto V_188;
}
V_481 = F_101 ( V_128 -> V_481 ) ;
V_162 = F_248 ( V_6 , V_481 ) ;
if ( ! V_162 ) {
F_136 ( L_30 , V_481 ) ;
goto V_188;
}
V_125 = F_46 ( V_479 , V_6 , V_162 ) ;
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
struct V_484 * V_128 = V_7 ;
struct V_474 V_22 ;
struct V_161 * V_162 ;
unsigned long V_485 ;
int V_34 = 0 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_251 . V_122 , & V_128 -> V_251 . V_122 ) ;
V_22 . V_251 . type = V_128 -> V_251 . type ;
if ( ! F_141 ( V_128 -> V_251 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_479 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_479 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( V_128 -> V_251 . type == V_252 )
V_162 = F_142 ( V_6 , V_264 ,
& V_128 -> V_251 . V_122 ) ;
else
V_162 = F_142 ( V_6 , V_282 , & V_128 -> V_251 . V_122 ) ;
if ( ! V_162 || V_162 -> V_277 != V_329 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_479 ,
V_280 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( F_46 ( V_479 , V_6 , V_162 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_479 ,
V_173 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_485 = V_6 -> V_486 +
F_250 ( V_6 -> V_487 -
V_6 -> V_486 ) ;
if ( F_251 ( V_488 , V_162 -> V_489 +
F_99 ( V_485 ) ) ||
! V_162 -> V_489 ) {
struct V_138 V_139 ;
struct V_490 V_491 ;
struct V_480 V_492 ;
struct V_124 * V_125 ;
F_53 ( & V_139 , V_6 ) ;
V_492 . V_481 = F_11 ( V_162 -> V_481 ) ;
F_75 ( & V_139 , V_482 , sizeof( V_492 ) ,
& V_492 ) ;
if ( ! F_192 ( V_128 -> V_251 . type ) ||
V_162 -> V_475 == V_478 ) {
V_491 . V_481 = F_11 ( V_162 -> V_481 ) ;
V_491 . type = 0x00 ;
F_75 ( & V_139 , V_483 ,
sizeof( V_491 ) , & V_491 ) ;
}
if ( V_162 -> V_476 == V_478 ) {
V_491 . V_481 = F_11 ( V_162 -> V_481 ) ;
V_491 . type = 0x01 ;
F_75 ( & V_139 , V_483 ,
sizeof( V_491 ) , & V_491 ) ;
}
V_34 = F_56 ( & V_139 , F_246 ) ;
if ( V_34 < 0 )
goto V_188;
V_125 = F_83 ( V_19 , V_479 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_252 ( V_162 ) ;
V_125 -> V_310 = F_173 ( V_162 ) ;
V_125 -> V_182 = F_245 ;
V_162 -> V_489 = V_488 ;
} else {
V_22 . V_393 = V_162 -> V_393 ;
V_22 . V_475 = V_162 -> V_475 ;
V_22 . V_476 = V_162 -> V_476 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_479 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_253 ( struct V_124 * V_125 , T_1 V_150 )
{
struct V_161 * V_162 = V_125 -> V_310 ;
struct V_493 V_22 ;
struct V_5 * V_6 ;
int V_34 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
memcpy ( & V_22 . V_251 , & V_125 -> V_129 , sizeof( V_22 . V_251 ) ) ;
if ( V_150 )
goto V_315;
V_6 = F_254 ( V_125 -> V_58 ) ;
if ( V_6 ) {
V_22 . V_494 = F_31 ( V_6 -> clock ) ;
F_255 ( V_6 ) ;
}
if ( V_162 ) {
V_22 . V_495 = F_31 ( V_162 -> clock ) ;
V_22 . V_496 = F_11 ( V_162 -> V_497 ) ;
}
V_315:
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
struct V_498 * V_212 ;
struct V_124 * V_125 ;
struct V_161 * V_162 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
F_35 ( V_6 ) ;
V_212 = F_247 ( V_6 , V_499 ) ;
if ( ! V_212 )
goto V_188;
if ( V_212 -> V_500 ) {
T_2 V_481 = F_101 ( V_212 -> V_481 ) ;
V_162 = F_248 ( V_6 , V_481 ) ;
} else {
V_162 = NULL ;
}
V_125 = F_46 ( V_501 , V_6 , V_162 ) ;
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
struct V_502 * V_128 = V_7 ;
struct V_493 V_22 ;
struct V_498 V_212 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
struct V_161 * V_162 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_65 ( & V_22 . V_251 . V_122 , & V_128 -> V_251 . V_122 ) ;
V_22 . V_251 . type = V_128 -> V_251 . type ;
if ( V_128 -> V_251 . type != V_252 )
return F_12 ( V_19 , V_6 -> V_59 , V_501 ,
V_172 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_501 ,
V_196 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_188;
}
if ( F_29 ( & V_128 -> V_251 . V_122 , V_76 ) ) {
V_162 = F_142 ( V_6 , V_264 ,
& V_128 -> V_251 . V_122 ) ;
if ( ! V_162 || V_162 -> V_277 != V_329 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_501 ,
V_280 ,
& V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
} else {
V_162 = NULL ;
}
V_125 = F_83 ( V_19 , V_501 , V_6 , V_7 , V_8 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
V_125 -> V_182 = F_253 ;
F_53 ( & V_139 , V_6 ) ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
F_75 ( & V_139 , V_499 , sizeof( V_212 ) , & V_212 ) ;
if ( V_162 ) {
F_252 ( V_162 ) ;
V_125 -> V_310 = F_173 ( V_162 ) ;
V_212 . V_481 = F_11 ( V_162 -> V_481 ) ;
V_212 . V_500 = 0x01 ;
F_75 ( & V_139 , V_499 , sizeof( V_212 ) , & V_212 ) ;
}
V_34 = F_56 ( & V_139 , F_256 ) ;
if ( V_34 < 0 )
F_92 ( V_125 ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_258 ( struct V_5 * V_6 , T_7 * V_251 , T_1 type )
{
struct V_161 * V_162 ;
V_162 = F_142 ( V_6 , V_282 , V_251 ) ;
if ( ! V_162 )
return false ;
if ( V_162 -> V_289 != type )
return false ;
if ( V_162 -> V_277 != V_329 )
return false ;
return true ;
}
static int F_259 ( struct V_5 * V_6 , T_7 * V_251 ,
T_1 V_255 , T_1 V_269 )
{
struct V_260 * V_261 ;
V_261 = F_169 ( V_6 , V_251 , V_255 ) ;
if ( ! V_261 )
return - V_503 ;
if ( V_261 -> V_269 == V_269 )
return 0 ;
F_260 ( & V_261 -> V_504 ) ;
switch ( V_269 ) {
case V_271 :
case V_505 :
if ( V_261 -> V_268 )
F_261 ( & V_261 -> V_504 , & V_6 -> V_506 ) ;
break;
case V_507 :
if ( V_261 -> V_268 )
F_261 ( & V_261 -> V_504 , & V_6 -> V_506 ) ;
else
F_261 ( & V_261 -> V_504 , & V_6 -> V_508 ) ;
break;
case V_509 :
case V_510 :
if ( ! F_258 ( V_6 , V_251 , V_255 ) )
F_261 ( & V_261 -> V_504 , & V_6 -> V_506 ) ;
break;
}
V_261 -> V_269 = V_269 ;
F_10 ( L_31 , V_251 , V_255 ,
V_269 ) ;
return 0 ;
}
static void F_262 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_7 * V_122 , T_1 type , T_1 V_504 )
{
struct V_511 V_155 ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = type ;
V_155 . V_504 = V_504 ;
F_7 ( V_512 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
}
static int F_263 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_513 * V_128 = V_7 ;
T_1 V_514 , V_255 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_141 ( V_128 -> V_251 . type ) ||
! F_29 ( & V_128 -> V_251 . V_122 , V_76 ) )
return F_12 ( V_19 , V_6 -> V_59 , V_515 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
if ( V_128 -> V_504 != 0x00 && V_128 -> V_504 != 0x01 && V_128 -> V_504 != 0x02 )
return F_12 ( V_19 , V_6 -> V_59 , V_515 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_251 . type == V_252 ) {
if ( V_128 -> V_504 != 0x01 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_515 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
V_34 = F_212 ( & V_6 -> V_516 , & V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type ) ;
if ( V_34 )
goto V_188;
F_105 ( V_6 ) ;
goto V_517;
}
V_255 = F_8 ( V_128 -> V_251 . type ) ;
if ( V_128 -> V_504 == 0x02 )
V_514 = V_510 ;
else if ( V_128 -> V_504 == 0x01 )
V_514 = V_509 ;
else
V_514 = V_507 ;
if ( ! F_264 ( & V_128 -> V_251 . V_122 , V_255 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_515 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
if ( F_259 ( V_6 , & V_128 -> V_251 . V_122 , V_255 ,
V_514 ) < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_515 ,
V_3 , & V_128 -> V_251 ,
sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
F_106 ( V_6 ) ;
V_517:
F_262 ( V_19 , V_6 , & V_128 -> V_251 . V_122 , V_128 -> V_251 . type , V_128 -> V_504 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_515 ,
V_187 , & V_128 -> V_251 ,
sizeof( V_128 -> V_251 ) ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_265 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_7 * V_122 , T_1 type )
{
struct V_518 V_155 ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = type ;
F_7 ( V_519 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
}
static int F_266 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_520 * V_128 = V_7 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_29 ( & V_128 -> V_251 . V_122 , V_76 ) ) {
struct V_260 * V_261 ;
T_1 V_255 ;
if ( ! F_141 ( V_128 -> V_251 . type ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_521 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
if ( V_128 -> V_251 . type == V_252 ) {
V_34 = F_214 ( & V_6 -> V_516 ,
& V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type ) ;
if ( V_34 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_521 ,
V_172 ,
& V_128 -> V_251 ,
sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
F_105 ( V_6 ) ;
F_265 ( V_19 , V_6 , & V_128 -> V_251 . V_122 ,
V_128 -> V_251 . type ) ;
goto V_315;
}
V_255 = F_8 ( V_128 -> V_251 . type ) ;
if ( ! F_264 ( & V_128 -> V_251 . V_122 , V_255 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_521 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
V_261 = F_150 ( V_6 , & V_128 -> V_251 . V_122 ,
V_255 ) ;
if ( ! V_261 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_521 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
if ( V_261 -> V_269 == V_271 ||
V_261 -> V_269 == V_270 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_521 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
F_88 ( & V_261 -> V_504 ) ;
F_88 ( & V_261 -> V_181 ) ;
F_17 ( V_261 ) ;
F_106 ( V_6 ) ;
F_265 ( V_19 , V_6 , & V_128 -> V_251 . V_122 , V_128 -> V_251 . type ) ;
} else {
struct V_260 * V_323 , * V_232 ;
struct V_522 * V_431 , * V_523 ;
if ( V_128 -> V_251 . type ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_521 ,
V_172 ,
& V_128 -> V_251 , sizeof( V_128 -> V_251 ) ) ;
goto V_188;
}
F_131 (b, btmp, &hdev->whitelist, list) {
F_265 ( V_19 , V_6 , & V_431 -> V_122 , V_431 -> V_524 ) ;
F_88 ( & V_431 -> V_181 ) ;
F_17 ( V_431 ) ;
}
F_105 ( V_6 ) ;
F_131 (p, tmp, &hdev->le_conn_params, list) {
if ( V_323 -> V_269 == V_271 )
continue;
F_265 ( V_19 , V_6 , & V_323 -> V_251 , V_323 -> V_255 ) ;
if ( V_323 -> V_268 ) {
V_323 -> V_269 = V_270 ;
continue;
}
F_88 ( & V_323 -> V_504 ) ;
F_88 ( & V_323 -> V_181 ) ;
F_17 ( V_323 ) ;
}
F_10 ( L_32 ) ;
F_106 ( V_6 ) ;
}
V_315:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_521 ,
V_187 , & V_128 -> V_251 ,
sizeof( V_128 -> V_251 ) ) ;
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_267 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_525 * V_128 = V_7 ;
const T_2 V_526 = ( ( V_243 - sizeof( * V_128 ) ) /
sizeof( struct V_527 ) ) ;
T_2 V_528 , V_246 ;
int V_33 ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_529 ,
V_185 ) ;
V_528 = F_101 ( V_128 -> V_528 ) ;
if ( V_528 > V_526 ) {
F_136 ( L_33 ,
V_528 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_529 ,
V_172 ) ;
}
V_246 = sizeof( * V_128 ) + V_528 *
sizeof( struct V_527 ) ;
if ( V_246 != V_8 ) {
F_136 ( L_34 ,
V_246 , V_8 ) ;
return F_82 ( V_19 , V_6 -> V_59 , V_529 ,
V_172 ) ;
}
F_10 ( L_35 , V_6 -> V_83 , V_528 ) ;
F_35 ( V_6 ) ;
F_268 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_528 ; V_33 ++ ) {
struct V_527 * V_129 = & V_128 -> V_261 [ V_33 ] ;
struct V_260 * V_530 ;
T_2 V_531 , V_532 , V_533 , V_195 ;
T_1 V_255 ;
F_10 ( L_36 , & V_129 -> V_251 . V_122 ,
V_129 -> V_251 . type ) ;
if ( V_129 -> V_251 . type == V_16 ) {
V_255 = V_17 ;
} else if ( V_129 -> V_251 . type == V_283 ) {
V_255 = V_18 ;
} else {
F_136 ( L_37 ) ;
continue;
}
V_531 = F_269 ( V_129 -> V_534 ) ;
V_532 = F_269 ( V_129 -> V_535 ) ;
V_533 = F_269 ( V_129 -> V_533 ) ;
V_195 = F_269 ( V_129 -> V_195 ) ;
F_10 ( L_38 ,
V_531 , V_532 , V_533 , V_195 ) ;
if ( F_270 ( V_531 , V_532 , V_533 , V_195 ) < 0 ) {
F_136 ( L_37 ) ;
continue;
}
V_530 = F_169 ( V_6 , & V_129 -> V_251 . V_122 ,
V_255 ) ;
if ( ! V_530 ) {
F_136 ( L_39 ) ;
continue;
}
V_530 -> V_536 = V_531 ;
V_530 -> V_537 = V_532 ;
V_530 -> V_538 = V_533 ;
V_530 -> V_539 = V_195 ;
}
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_529 , 0 ,
NULL , 0 ) ;
}
static int F_271 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_540 * V_128 = V_7 ;
bool V_197 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_541 ,
V_186 ) ;
if ( V_128 -> V_542 != 0x00 && V_128 -> V_542 != 0x01 )
return F_82 ( V_19 , V_6 -> V_59 , V_541 ,
V_172 ) ;
if ( ! F_23 ( V_72 , & V_6 -> V_57 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_541 ,
V_185 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_542 )
V_197 = ! F_61 ( V_6 , V_73 ) ;
else
V_197 = F_52 ( V_6 , V_73 ) ;
V_34 = F_33 ( V_19 , V_541 , V_6 ) ;
if ( V_34 < 0 )
goto V_188;
if ( ! V_197 )
goto V_188;
V_34 = F_32 ( V_6 , V_19 ) ;
if ( F_21 ( V_6 , V_51 ) == F_28 ( V_6 ) ) {
F_272 ( V_6 ) ;
if ( F_273 ( V_6 , V_51 ) ) {
F_58 ( V_6 , V_54 ) ;
F_58 ( V_6 , V_543 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_175 ) ;
} else {
F_149 ( V_544 , & V_6 -> V_165 ) ;
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
struct V_545 * V_128 = V_7 ;
bool V_197 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_546 ,
V_186 ) ;
if ( ! F_29 ( & V_128 -> V_122 , V_76 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_546 ,
V_172 ) ;
if ( ! V_6 -> V_85 )
return F_82 ( V_19 , V_6 -> V_59 , V_546 ,
V_185 ) ;
F_35 ( V_6 ) ;
V_197 = ! ! F_29 ( & V_6 -> V_75 , & V_128 -> V_122 ) ;
F_65 ( & V_6 -> V_75 , & V_128 -> V_122 ) ;
V_34 = F_33 ( V_19 , V_546 , V_6 ) ;
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
F_58 ( V_6 , V_543 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_175 ) ;
}
V_188:
F_36 ( V_6 ) ;
return V_34 ;
}
static inline T_2 F_276 ( T_1 * V_547 , T_2 V_548 , T_1 type , T_1 * V_7 ,
T_1 V_20 )
{
V_547 [ V_548 ++ ] = sizeof( type ) + V_20 ;
V_547 [ V_548 ++ ] = type ;
memcpy ( & V_547 [ V_548 ] , V_7 , V_20 ) ;
V_548 += V_20 ;
return V_548 ;
}
static void F_277 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 , struct V_352 * V_353 )
{
const struct V_549 * V_396 ;
struct V_550 * V_355 ;
T_1 * V_551 , * V_552 , * V_553 , * V_554 ;
struct V_124 * V_125 ;
T_2 V_548 ;
int V_34 ;
F_10 ( L_15 , V_6 -> V_83 , V_150 ) ;
V_125 = F_44 ( V_555 , V_6 ) ;
if ( ! V_125 )
return;
V_396 = V_125 -> V_129 ;
if ( V_150 ) {
V_150 = F_1 ( V_150 ) ;
V_548 = 0 ;
V_551 = NULL ;
V_552 = NULL ;
V_553 = NULL ;
V_554 = NULL ;
} else if ( V_41 == V_357 ) {
struct V_358 * V_22 ;
if ( V_353 -> V_8 != sizeof( * V_22 ) ) {
V_150 = V_3 ;
V_548 = 0 ;
} else {
V_150 = V_187 ;
V_22 = ( void * ) V_353 -> V_7 ;
V_548 = 5 + 18 + 18 ;
V_551 = V_22 -> V_360 ;
V_552 = V_22 -> rand ;
V_553 = NULL ;
V_554 = NULL ;
}
} else {
struct V_364 * V_22 ;
if ( V_353 -> V_8 != sizeof( * V_22 ) ) {
V_150 = V_3 ;
V_548 = 0 ;
} else {
V_150 = V_187 ;
V_22 = ( void * ) V_353 -> V_7 ;
if ( F_21 ( V_6 , V_441 ) ) {
V_548 = 5 + 18 + 18 ;
V_551 = NULL ;
V_552 = NULL ;
} else {
V_548 = 5 + 18 + 18 + 18 + 18 ;
V_551 = V_22 -> V_359 ;
V_552 = V_22 -> V_361 ;
}
V_553 = V_22 -> V_362 ;
V_554 = V_22 -> V_363 ;
}
}
V_355 = F_15 ( sizeof( * V_355 ) + V_548 , V_39 ) ;
if ( ! V_355 )
goto V_266;
if ( V_150 )
goto V_556;
V_548 = F_276 ( V_355 -> V_547 , 0 , V_557 ,
V_6 -> V_146 , 3 ) ;
if ( V_551 && V_552 ) {
V_548 = F_276 ( V_355 -> V_547 , V_548 ,
V_558 , V_551 , 16 ) ;
V_548 = F_276 ( V_355 -> V_547 , V_548 ,
V_559 , V_552 , 16 ) ;
}
if ( V_553 && V_554 ) {
V_548 = F_276 ( V_355 -> V_547 , V_548 ,
V_560 , V_553 , 16 ) ;
V_548 = F_276 ( V_355 -> V_547 , V_548 ,
V_561 , V_554 , 16 ) ;
}
V_556:
V_355 -> type = V_396 -> type ;
V_355 -> V_548 = F_11 ( V_548 ) ;
V_34 = F_12 ( V_125 -> V_19 , V_6 -> V_59 ,
V_555 , V_150 ,
V_355 , sizeof( * V_355 ) + V_548 ) ;
if ( V_34 < 0 || V_150 )
goto V_266;
F_26 ( V_125 -> V_19 , V_562 ) ;
V_34 = F_5 ( V_563 , V_6 ,
V_355 , sizeof( * V_355 ) + V_548 ,
V_562 , V_125 -> V_19 ) ;
V_266:
F_17 ( V_355 ) ;
F_92 ( V_125 ) ;
}
static int F_278 ( struct V_5 * V_6 , struct V_11 * V_19 ,
struct V_549 * V_128 )
{
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
V_125 = F_83 ( V_19 , V_555 , V_6 ,
V_128 , sizeof( * V_128 ) ) ;
if ( ! V_125 )
return - V_40 ;
F_53 ( & V_139 , V_6 ) ;
if ( F_188 ( V_6 ) )
F_75 ( & V_139 , V_365 , 0 , NULL ) ;
else
F_75 ( & V_139 , V_357 , 0 , NULL ) ;
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
struct V_549 * V_128 = V_7 ;
struct V_550 * V_22 ;
T_3 V_46 ;
T_2 V_548 ;
T_1 V_150 , V_165 , V_564 , V_251 [ 7 ] , V_360 [ 16 ] , rand [ 16 ] ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) ) {
switch ( V_128 -> type ) {
case F_280 ( V_252 ) :
V_150 = F_96 ( V_6 ) ;
if ( V_150 )
V_548 = 0 ;
else
V_548 = 5 ;
break;
case ( F_280 ( V_16 ) | F_280 ( V_283 ) ) :
V_150 = F_97 ( V_6 ) ;
if ( V_150 )
V_548 = 0 ;
else
V_548 = 9 + 3 + 18 + 18 + 3 ;
break;
default:
V_150 = V_172 ;
V_548 = 0 ;
break;
}
} else {
V_150 = V_196 ;
V_548 = 0 ;
}
V_46 = sizeof( * V_22 ) + V_548 ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 )
return - V_40 ;
if ( V_150 )
goto V_315;
F_35 ( V_6 ) ;
V_548 = 0 ;
switch ( V_128 -> type ) {
case F_280 ( V_252 ) :
if ( F_21 ( V_6 , V_115 ) ) {
V_34 = F_278 ( V_6 , V_19 , V_128 ) ;
F_36 ( V_6 ) ;
if ( ! V_34 )
goto V_266;
V_150 = V_3 ;
goto V_315;
} else {
V_548 = F_276 ( V_22 -> V_547 , V_548 ,
V_557 ,
V_6 -> V_146 , 3 ) ;
}
break;
case ( F_280 ( V_16 ) | F_280 ( V_283 ) ) :
if ( F_21 ( V_6 , V_118 ) &&
F_281 ( V_6 , V_360 , rand ) < 0 ) {
F_36 ( V_6 ) ;
V_150 = V_3 ;
goto V_315;
}
if ( F_21 ( V_6 , V_120 ) ) {
F_36 ( V_6 ) ;
V_150 = V_186 ;
goto V_315;
}
if ( F_21 ( V_6 , V_121 ) ||
! F_29 ( & V_6 -> V_122 , V_76 ) ||
( ! F_21 ( V_6 , V_112 ) &&
F_29 ( & V_6 -> V_123 , V_76 ) ) ) {
memcpy ( V_251 , & V_6 -> V_123 , 6 ) ;
V_251 [ 6 ] = 0x01 ;
} else {
memcpy ( V_251 , & V_6 -> V_122 , 6 ) ;
V_251 [ 6 ] = 0x00 ;
}
V_548 = F_276 ( V_22 -> V_547 , V_548 , V_565 ,
V_251 , sizeof( V_251 ) ) ;
if ( F_21 ( V_6 , V_117 ) )
V_564 = 0x02 ;
else
V_564 = 0x01 ;
V_548 = F_276 ( V_22 -> V_547 , V_548 , V_566 ,
& V_564 , sizeof( V_564 ) ) ;
if ( F_21 ( V_6 , V_118 ) ) {
V_548 = F_276 ( V_22 -> V_547 , V_548 ,
V_567 ,
V_360 , sizeof( V_360 ) ) ;
V_548 = F_276 ( V_22 -> V_547 , V_548 ,
V_568 ,
rand , sizeof( rand ) ) ;
}
V_165 = F_48 ( V_6 ) ;
if ( ! F_21 ( V_6 , V_112 ) )
V_165 |= V_569 ;
V_548 = F_276 ( V_22 -> V_547 , V_548 , V_570 ,
& V_165 , sizeof( V_165 ) ) ;
break;
}
F_36 ( V_6 ) ;
F_26 ( V_19 , V_562 ) ;
V_150 = V_187 ;
V_315:
V_22 -> type = V_128 -> type ;
V_22 -> V_548 = F_11 ( V_548 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_555 ,
V_150 , V_22 , sizeof( * V_22 ) + V_548 ) ;
if ( V_34 < 0 || V_150 )
goto V_266;
V_34 = F_5 ( V_563 , V_6 ,
V_22 , sizeof( * V_22 ) + V_548 ,
V_562 , V_19 ) ;
V_266:
F_17 ( V_22 ) ;
return V_34 ;
}
static T_6 F_282 ( struct V_5 * V_6 )
{
T_6 V_165 = 0 ;
V_165 |= V_571 ;
V_165 |= V_572 ;
V_165 |= V_573 ;
V_165 |= V_574 ;
if ( V_6 -> V_575 != V_478 )
V_165 |= V_576 ;
return V_165 ;
}
static int F_283 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_577 * V_22 ;
T_3 V_46 ;
int V_34 ;
struct V_421 * V_422 ;
T_6 V_578 ;
T_1 * V_153 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_579 ,
V_186 ) ;
F_35 ( V_6 ) ;
V_46 = sizeof( * V_22 ) + V_6 -> V_580 ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 ) {
F_36 ( V_6 ) ;
return - V_40 ;
}
V_578 = F_282 ( V_6 ) ;
V_22 -> V_578 = F_31 ( V_578 ) ;
V_22 -> V_581 = V_582 ;
V_22 -> V_583 = V_582 ;
V_22 -> V_584 = V_585 ;
V_22 -> V_586 = V_6 -> V_580 ;
V_153 = V_22 -> V_153 ;
F_20 (adv_instance, &hdev->adv_instances, list) {
* V_153 = V_422 -> V_153 ;
V_153 ++ ;
}
F_36 ( V_6 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_579 ,
V_187 , V_22 , V_46 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static bool F_284 ( struct V_5 * V_6 , T_6 V_587 , T_1 * V_7 ,
T_1 V_8 , bool V_588 )
{
T_1 V_589 = V_582 ;
int V_33 , V_590 ;
bool V_591 = false ;
bool V_592 = false ;
if ( V_588 ) {
if ( V_587 & ( V_572 |
V_573 |
V_574 ) ) {
V_591 = true ;
V_589 -= 3 ;
}
if ( V_587 & V_576 ) {
V_592 = true ;
V_589 -= 3 ;
}
}
if ( V_8 > V_589 )
return false ;
for ( V_33 = 0 , V_590 = 0 ; V_33 < V_8 ; V_33 += ( V_590 + 1 ) ) {
V_590 = V_7 [ V_33 ] ;
if ( V_591 && V_7 [ V_33 + 1 ] == V_570 )
return false ;
if ( V_592 && V_7 [ V_33 + 1 ] == V_593 )
return false ;
if ( V_33 + V_590 >= V_8 )
return false ;
}
return true ;
}
static void F_285 ( struct V_5 * V_6 , T_1 V_150 ,
T_2 V_41 )
{
struct V_124 * V_125 ;
struct V_594 * V_128 ;
struct V_595 V_22 ;
struct V_421 * V_422 , * V_596 ;
T_1 V_153 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_597 , V_6 ) ;
F_131 (adv_instance, n, &hdev->adv_instances, list) {
if ( ! V_422 -> V_598 )
continue;
if ( ! V_150 ) {
V_422 -> V_598 = false ;
continue;
}
V_153 = V_422 -> V_153 ;
if ( V_6 -> V_351 == V_153 )
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
struct V_594 * V_128 = V_7 ;
struct V_595 V_22 ;
T_6 V_165 ;
T_6 V_578 ;
T_1 V_150 ;
T_2 V_195 , V_599 ;
unsigned int V_600 = V_6 -> V_580 ;
T_1 V_601 = 0 ;
struct V_421 * V_602 ;
int V_34 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
V_150 = F_97 ( V_6 ) ;
if ( V_150 )
return F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_150 ) ;
if ( V_128 -> V_153 < 1 || V_128 -> V_153 > V_585 )
return F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_172 ) ;
if ( V_20 != sizeof( * V_128 ) + V_128 -> V_603 + V_128 -> V_604 )
return F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_172 ) ;
V_165 = F_288 ( V_128 -> V_165 ) ;
V_195 = F_101 ( V_128 -> V_195 ) ;
V_599 = F_101 ( V_128 -> V_599 ) ;
V_578 = F_282 ( V_6 ) ;
if ( V_165 & ~ V_578 )
return F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_172 ) ;
F_35 ( V_6 ) ;
if ( V_195 && ! F_43 ( V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_186 ) ;
goto V_188;
}
if ( F_44 ( V_597 , V_6 ) ||
F_44 ( V_605 , V_6 ) ||
F_44 ( V_210 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_173 ) ;
goto V_188;
}
if ( ! F_284 ( V_6 , V_165 , V_128 -> V_7 , V_128 -> V_603 , true ) ||
! F_284 ( V_6 , V_165 , V_128 -> V_7 + V_128 -> V_603 ,
V_128 -> V_604 , false ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_172 ) ;
goto V_188;
}
V_34 = F_289 ( V_6 , V_128 -> V_153 , V_165 ,
V_128 -> V_603 , V_128 -> V_7 ,
V_128 -> V_604 ,
V_128 -> V_7 + V_128 -> V_603 ,
V_195 , V_599 ) ;
if ( V_34 < 0 ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_597 ,
V_3 ) ;
goto V_188;
}
if ( V_6 -> V_580 > V_600 )
F_71 ( V_19 , V_6 , V_128 -> V_153 ) ;
if ( V_6 -> V_351 == V_128 -> V_153 ) {
F_73 ( V_6 ) ;
V_602 = F_290 ( V_6 , V_128 -> V_153 ) ;
if ( V_602 )
V_601 = V_602 -> V_153 ;
} else if ( ! V_6 -> V_159 ) {
V_601 = V_128 -> V_153 ;
}
if ( ! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) ||
! V_601 ) {
V_22 . V_153 = V_128 -> V_153 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_597 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_597 , V_6 , V_7 ,
V_20 ) ;
if ( ! V_125 ) {
V_34 = - V_40 ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
V_34 = F_220 ( & V_139 , V_601 , true ) ;
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
struct V_606 * V_128 ;
struct V_607 V_22 ;
F_10 ( L_19 , V_150 ) ;
F_35 ( V_6 ) ;
V_125 = F_44 ( V_605 , V_6 ) ;
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
struct V_606 * V_128 = V_7 ;
struct V_607 V_22 ;
struct V_124 * V_125 ;
struct V_138 V_139 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( V_128 -> V_153 && ! F_293 ( V_6 , V_128 -> V_153 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 ,
V_605 ,
V_172 ) ;
goto V_188;
}
if ( F_44 ( V_597 , V_6 ) ||
F_44 ( V_605 , V_6 ) ||
F_44 ( V_210 , V_6 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_605 ,
V_173 ) ;
goto V_188;
}
if ( F_218 ( & V_6 -> V_423 ) ) {
V_34 = F_82 ( V_19 , V_6 -> V_59 , V_605 ,
V_172 ) ;
goto V_188;
}
F_53 ( & V_139 , V_6 ) ;
F_76 ( V_6 , & V_139 , V_128 -> V_153 , true ) ;
if ( F_218 ( & V_6 -> V_423 ) )
F_77 ( & V_139 ) ;
if ( F_294 ( & V_139 . V_608 ) ||
! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) ) {
V_22 . V_153 = V_128 -> V_153 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_605 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
goto V_188;
}
V_125 = F_83 ( V_19 , V_605 , V_6 , V_7 ,
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
static T_1 F_295 ( T_6 V_587 , bool V_588 )
{
T_1 V_589 = V_582 ;
if ( V_588 ) {
if ( V_587 & ( V_572 |
V_573 |
V_574 ) )
V_589 -= 3 ;
if ( V_587 & V_576 )
V_589 -= 3 ;
}
return V_589 ;
}
static int F_296 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_609 * V_128 = V_7 ;
struct V_610 V_22 ;
T_6 V_165 , V_578 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_82 ( V_19 , V_6 -> V_59 , V_611 ,
V_186 ) ;
if ( V_128 -> V_153 < 1 || V_128 -> V_153 > V_585 )
return F_82 ( V_19 , V_6 -> V_59 , V_611 ,
V_172 ) ;
V_165 = F_288 ( V_128 -> V_165 ) ;
V_578 = F_282 ( V_6 ) ;
if ( V_165 & ~ V_578 )
return F_82 ( V_19 , V_6 -> V_59 , V_611 ,
V_172 ) ;
V_22 . V_153 = V_128 -> V_153 ;
V_22 . V_165 = V_128 -> V_165 ;
V_22 . V_581 = F_295 ( V_165 , true ) ;
V_22 . V_583 = F_295 ( V_165 , false ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_611 ,
V_187 , & V_22 , sizeof( V_22 ) ) ;
return V_34 ;
}
void F_274 ( struct V_5 * V_6 )
{
struct V_612 V_155 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_613 , V_6 ,
NULL , 0 , V_70 ) ;
V_155 . type = 0x01 ;
} else {
F_3 ( V_614 , V_6 , NULL , 0 ,
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
F_3 ( V_615 , V_6 , & V_155 , sizeof( V_155 ) ,
V_68 ) ;
}
void F_272 ( struct V_5 * V_6 )
{
struct V_612 V_155 ;
T_1 V_150 = V_616 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
F_114 ( 0 , V_6 , F_93 , & V_150 ) ;
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_617 , V_6 ,
NULL , 0 , V_70 ) ;
V_155 . type = 0x01 ;
} else {
F_3 ( V_618 , V_6 , NULL , 0 ,
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
F_3 ( V_619 , V_6 , & V_155 , sizeof( V_155 ) ,
V_68 ) ;
}
static void F_297 ( struct V_5 * V_6 )
{
struct V_260 * V_323 ;
F_20 (p, &hdev->le_conn_params, list) {
F_260 ( & V_323 -> V_504 ) ;
switch ( V_323 -> V_269 ) {
case V_509 :
case V_510 :
F_261 ( & V_323 -> V_504 , & V_6 -> V_506 ) ;
break;
case V_507 :
F_261 ( & V_323 -> V_504 , & V_6 -> V_508 ) ;
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
T_1 V_150 , V_620 [] = { 0 , 0 , 0 } ;
F_114 ( V_171 , V_6 , F_87 , & V_180 ) ;
if ( F_21 ( V_6 , V_621 ) )
V_150 = V_616 ;
else
V_150 = V_196 ;
F_114 ( 0 , V_6 , F_93 , & V_150 ) ;
if ( memcmp ( V_6 -> V_146 , V_620 , sizeof( V_620 ) ) != 0 )
F_6 ( V_622 , V_6 ,
V_620 , sizeof( V_620 ) , NULL ) ;
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
if ( V_34 == - V_623 )
V_150 = V_624 ;
else
V_150 = V_3 ;
F_82 ( V_125 -> V_19 , V_6 -> V_59 , V_171 , V_150 ) ;
F_92 ( V_125 ) ;
}
void F_301 ( struct V_5 * V_6 , struct V_625 * V_249 ,
bool V_626 )
{
struct V_627 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_628 = V_626 ;
F_65 ( & V_155 . V_249 . V_251 . V_122 , & V_249 -> V_122 ) ;
V_155 . V_249 . V_251 . type = V_252 ;
V_155 . V_249 . type = V_249 -> type ;
memcpy ( V_155 . V_249 . V_130 , V_249 -> V_130 , V_629 ) ;
V_155 . V_249 . V_254 = V_249 -> V_254 ;
F_7 ( V_630 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
static T_1 F_302 ( struct V_631 * V_632 )
{
switch ( V_632 -> type ) {
case V_464 :
case V_465 :
if ( V_632 -> V_462 )
return V_466 ;
return V_463 ;
case V_468 :
if ( V_632 -> V_462 )
return V_469 ;
return V_467 ;
case V_471 :
return V_470 ;
}
return V_463 ;
}
void F_303 ( struct V_5 * V_6 , struct V_631 * V_249 , bool V_626 )
{
struct V_633 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_249 -> V_524 == V_18 &&
( V_249 -> V_122 . V_431 [ 5 ] & 0xc0 ) != 0xc0 )
V_155 . V_628 = 0x00 ;
else
V_155 . V_628 = V_626 ;
F_65 ( & V_155 . V_249 . V_251 . V_122 , & V_249 -> V_122 ) ;
V_155 . V_249 . V_251 . type = F_153 ( V_282 , V_249 -> V_524 ) ;
V_155 . V_249 . type = F_302 ( V_249 ) ;
V_155 . V_249 . V_472 = V_249 -> V_472 ;
V_155 . V_249 . V_473 = V_249 -> V_473 ;
V_155 . V_249 . rand = V_249 -> rand ;
if ( V_249 -> type == V_464 )
V_155 . V_249 . V_459 = 1 ;
memcpy ( V_155 . V_249 . V_130 , V_249 -> V_130 , V_249 -> V_472 ) ;
memset ( V_155 . V_249 . V_130 + V_249 -> V_472 , 0 ,
sizeof( V_155 . V_249 . V_130 ) - V_249 -> V_472 ) ;
F_7 ( V_634 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_304 ( struct V_5 * V_6 , struct V_635 * V_451 , bool V_626 )
{
struct V_636 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_628 = V_626 ;
F_65 ( & V_155 . V_637 , & V_451 -> V_637 ) ;
F_65 ( & V_155 . V_451 . V_251 . V_122 , & V_451 -> V_122 ) ;
V_155 . V_451 . V_251 . type = F_153 ( V_282 , V_451 -> V_255 ) ;
memcpy ( V_155 . V_451 . V_130 , V_451 -> V_130 , sizeof( V_451 -> V_130 ) ) ;
F_7 ( V_638 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_305 ( struct V_5 * V_6 , struct V_639 * V_640 ,
bool V_626 )
{
struct V_641 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_640 -> V_524 == V_18 &&
( V_640 -> V_122 . V_431 [ 5 ] & 0xc0 ) != 0xc0 )
V_155 . V_628 = 0x00 ;
else
V_155 . V_628 = V_626 ;
F_65 ( & V_155 . V_249 . V_251 . V_122 , & V_640 -> V_122 ) ;
V_155 . V_249 . V_251 . type = F_153 ( V_282 , V_640 -> V_524 ) ;
V_155 . V_249 . type = V_640 -> type ;
memcpy ( V_155 . V_249 . V_130 , V_640 -> V_130 , sizeof( V_640 -> V_130 ) ) ;
F_7 ( V_642 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_306 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_524 , T_1 V_628 , T_2 V_534 ,
T_2 V_535 , T_2 V_533 , T_2 V_195 )
{
struct V_643 V_155 ;
if ( ! F_264 ( V_122 , V_524 ) )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = F_153 ( V_282 , V_524 ) ;
V_155 . V_628 = V_628 ;
V_155 . V_534 = F_11 ( V_534 ) ;
V_155 . V_535 = F_11 ( V_535 ) ;
V_155 . V_533 = F_11 ( V_533 ) ;
V_155 . V_195 = F_11 ( V_195 ) ;
F_7 ( V_644 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_307 ( struct V_5 * V_6 , struct V_161 * V_162 ,
T_6 V_165 , T_1 * V_83 , T_1 V_645 )
{
char V_646 [ 512 ] ;
struct V_647 * V_155 = ( void * ) V_646 ;
T_2 V_548 = 0 ;
F_65 ( & V_155 -> V_251 . V_122 , & V_162 -> V_288 ) ;
V_155 -> V_251 . type = F_153 ( V_162 -> type , V_162 -> V_289 ) ;
V_155 -> V_165 = F_308 ( V_165 ) ;
if ( V_162 -> V_648 > 0 ) {
memcpy ( & V_155 -> V_547 [ V_548 ] ,
V_162 -> V_649 , V_162 -> V_648 ) ;
V_548 = V_162 -> V_648 ;
} else {
if ( V_645 > 0 )
V_548 = F_276 ( V_155 -> V_547 , 0 , V_650 ,
V_83 , V_645 ) ;
if ( memcmp ( V_162 -> V_146 , L_41 , 3 ) != 0 )
V_548 = F_276 ( V_155 -> V_547 , V_548 ,
V_557 ,
V_162 -> V_146 , 3 ) ;
}
V_155 -> V_548 = F_11 ( V_548 ) ;
F_7 ( V_651 , V_6 , V_646 ,
sizeof( * V_155 ) + V_548 , NULL ) ;
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
struct V_258 * V_128 = V_125 -> V_129 ;
F_139 ( V_6 , & V_128 -> V_251 . V_122 , V_128 -> V_251 . type , V_125 -> V_19 ) ;
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
T_1 V_281 , T_1 V_255 , T_1 V_652 ,
bool V_653 )
{
struct V_654 V_155 ;
struct V_11 * V_19 = NULL ;
if ( F_311 ( V_6 ) && F_68 ( V_6 ) == 1 ) {
F_69 ( & V_6 -> V_151 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_151 . V_136 ) ;
}
if ( ! V_653 )
return;
if ( V_281 != V_264 && V_281 != V_282 )
return;
F_114 ( V_275 , V_6 , F_309 , & V_19 ) ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = F_153 ( V_281 , V_255 ) ;
V_155 . V_652 = V_652 ;
F_7 ( V_655 , V_6 , & V_155 , sizeof( V_155 ) , V_19 ) ;
if ( V_19 )
F_115 ( V_19 ) ;
F_114 ( V_262 , V_6 , F_310 ,
V_6 ) ;
}
void F_313 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_1 V_150 )
{
T_1 V_524 = F_153 ( V_281 , V_255 ) ;
struct V_273 * V_128 ;
struct V_124 * V_125 ;
F_114 ( V_262 , V_6 , F_310 ,
V_6 ) ;
V_125 = F_44 ( V_275 , V_6 ) ;
if ( ! V_125 )
return;
V_128 = V_125 -> V_129 ;
if ( F_29 ( V_122 , & V_128 -> V_251 . V_122 ) )
return;
if ( V_128 -> V_251 . type != V_524 )
return;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
void F_314 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_281 ,
T_1 V_255 , T_1 V_150 )
{
struct V_656 V_155 ;
if ( F_311 ( V_6 ) && F_68 ( V_6 ) == 1 ) {
F_69 ( & V_6 -> V_151 ) ;
F_70 ( V_6 -> V_152 , & V_6 -> V_151 . V_136 ) ;
}
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = F_153 ( V_281 , V_255 ) ;
V_155 . V_150 = F_1 ( V_150 ) ;
F_7 ( V_657 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_315 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_658 )
{
struct V_659 V_155 ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = V_252 ;
V_155 . V_658 = V_658 ;
F_7 ( V_660 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_316 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_150 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_299 , V_6 ) ;
if ( ! V_125 )
return;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
void F_317 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_150 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_294 , V_6 ) ;
if ( ! V_125 )
return;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
}
int F_318 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_6 V_661 ,
T_1 V_662 )
{
struct V_663 V_155 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = F_153 ( V_281 , V_255 ) ;
V_155 . V_662 = V_662 ;
V_155 . V_661 = F_31 ( V_661 ) ;
return F_7 ( V_664 , V_6 , & V_155 , sizeof( V_155 ) ,
NULL ) ;
}
int F_319 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 )
{
struct V_665 V_155 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = F_153 ( V_281 , V_255 ) ;
return F_7 ( V_666 , V_6 , & V_155 , sizeof( V_155 ) ,
NULL ) ;
}
static int F_320 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_1 V_150 ,
T_1 V_41 )
{
struct V_124 * V_125 ;
V_125 = F_44 ( V_41 , V_6 ) ;
if ( ! V_125 )
return - V_667 ;
V_125 -> V_182 ( V_125 , F_1 ( V_150 ) ) ;
F_92 ( V_125 ) ;
return 0 ;
}
int F_321 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_281 , V_255 ,
V_150 , V_338 ) ;
}
int F_322 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_281 , V_255 ,
V_150 ,
V_341 ) ;
}
int F_323 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_281 , V_255 ,
V_150 , V_344 ) ;
}
int F_324 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_1 V_150 )
{
return F_320 ( V_6 , V_122 , V_281 , V_255 ,
V_150 ,
V_346 ) ;
}
int F_325 ( struct V_5 * V_6 , T_7 * V_122 ,
T_1 V_281 , T_1 V_255 , T_6 V_334 ,
T_1 V_668 )
{
struct V_669 V_155 ;
F_10 ( L_16 , V_6 -> V_83 ) ;
F_65 ( & V_155 . V_251 . V_122 , V_122 ) ;
V_155 . V_251 . type = F_153 ( V_281 , V_255 ) ;
V_155 . V_334 = F_308 ( V_334 ) ;
V_155 . V_668 = V_668 ;
return F_7 ( V_670 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
void F_326 ( struct V_161 * V_162 , T_1 V_1 )
{
struct V_671 V_155 ;
struct V_124 * V_125 ;
T_1 V_150 = F_1 ( V_1 ) ;
F_65 ( & V_155 . V_251 . V_122 , & V_162 -> V_288 ) ;
V_155 . V_251 . type = F_153 ( V_162 -> type , V_162 -> V_289 ) ;
V_155 . V_150 = V_150 ;
V_125 = F_158 ( V_162 ) ;
F_7 ( V_672 , V_162 -> V_6 , & V_155 , sizeof( V_155 ) ,
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
F_114 ( V_202 , V_6 ,
F_91 , & V_189 ) ;
return;
}
if ( F_23 ( V_203 , & V_6 -> V_165 ) )
V_197 = ! F_61 ( V_6 , V_114 ) ;
else
V_197 = F_52 ( V_6 , V_114 ) ;
F_114 ( V_202 , V_6 , F_87 ,
& V_180 ) ;
if ( V_197 )
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
}
static void F_328 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_673 V_128 ;
if ( ! F_329 ( V_6 ) )
return;
memset ( V_6 -> V_547 , 0 , sizeof( V_6 -> V_547 ) ) ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_75 ( V_139 , V_674 , sizeof( V_128 ) , & V_128 ) ;
}
void F_330 ( struct V_5 * V_6 , T_1 V_675 , T_1 V_150 )
{
struct V_179 V_180 = { NULL , V_6 } ;
struct V_138 V_139 ;
bool V_197 = false ;
if ( V_150 ) {
T_1 V_189 = F_1 ( V_150 ) ;
if ( V_675 && F_52 ( V_6 ,
V_115 ) ) {
F_63 ( V_6 , V_116 ) ;
F_85 ( V_6 , NULL ) ;
}
F_114 ( V_205 , V_6 , F_91 ,
& V_189 ) ;
return;
}
if ( V_675 ) {
V_197 = ! F_61 ( V_6 , V_115 ) ;
} else {
V_197 = F_52 ( V_6 , V_115 ) ;
if ( ! V_197 )
V_197 = F_52 ( V_6 ,
V_116 ) ;
else
F_63 ( V_6 , V_116 ) ;
}
F_114 ( V_205 , V_6 , F_87 , & V_180 ) ;
if ( V_197 )
F_85 ( V_6 , V_180 . V_19 ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
F_53 ( & V_139 , V_6 ) ;
if ( F_21 ( V_6 , V_115 ) ) {
if ( F_21 ( V_6 , V_206 ) )
F_75 ( & V_139 , V_207 ,
sizeof( V_675 ) , & V_675 ) ;
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
F_114 ( V_220 , V_6 , F_331 , & V_180 ) ;
F_114 ( V_218 , V_6 , F_331 , & V_180 ) ;
F_114 ( V_219 , V_6 , F_331 , & V_180 ) ;
if ( ! V_150 )
F_6 ( V_622 , V_6 ,
V_146 , 3 , NULL ) ;
if ( V_180 . V_19 )
F_115 ( V_180 . V_19 ) ;
}
void F_333 ( struct V_5 * V_6 , T_1 * V_83 , T_1 V_150 )
{
struct V_348 V_155 ;
struct V_124 * V_125 ;
if ( V_150 )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
memcpy ( V_155 . V_83 , V_83 , V_676 ) ;
memcpy ( V_155 . V_148 , V_6 -> V_148 , V_677 ) ;
V_125 = F_44 ( V_349 , V_6 ) ;
if ( ! V_125 ) {
memcpy ( V_6 -> V_147 , V_83 , sizeof( V_6 -> V_147 ) ) ;
if ( F_44 ( V_171 , V_6 ) )
return;
}
F_6 ( V_350 , V_6 , & V_155 , sizeof( V_155 ) ,
V_125 ? V_125 -> V_19 : NULL ) ;
}
static void F_334 ( struct V_5 * V_6 )
{
if ( ! F_21 ( V_6 , V_425 ) )
return;
if ( F_251 ( V_488 + V_678 ,
V_6 -> V_382 . V_679 +
V_6 -> V_382 . V_680 ) )
return;
F_84 ( V_6 -> V_152 , & V_6 -> V_681 ,
V_678 ) ;
}
static bool F_335 ( struct V_5 * V_6 , T_10 V_393 , T_1 * V_547 ,
T_2 V_548 , T_1 * V_682 , T_1 V_604 )
{
if ( V_6 -> V_382 . V_393 != V_477 &&
( V_393 == V_477 ||
( V_393 < V_6 -> V_382 . V_393 &&
! F_23 ( V_683 , & V_6 -> V_57 ) ) ) )
return false ;
if ( V_6 -> V_382 . V_391 != 0 ) {
if ( ! F_336 ( V_547 , V_548 , V_6 -> V_382 . V_391 ,
V_6 -> V_382 . V_228 ) &&
! F_336 ( V_682 , V_604 ,
V_6 -> V_382 . V_391 ,
V_6 -> V_382 . V_228 ) )
return false ;
}
if ( F_23 ( V_683 , & V_6 -> V_57 ) ) {
F_334 ( V_6 ) ;
if ( V_6 -> V_382 . V_393 != V_477 &&
V_393 < V_6 -> V_382 . V_393 )
return false ;
}
return true ;
}
void F_337 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_281 ,
T_1 V_255 , T_1 * V_146 , T_10 V_393 , T_6 V_165 ,
T_1 * V_547 , T_2 V_548 , T_1 * V_682 , T_1 V_604 )
{
char V_646 [ 512 ] ;
struct V_684 * V_155 = ( void * ) V_646 ;
T_3 V_685 ;
if ( ! F_207 ( V_6 ) ) {
if ( V_281 == V_264 )
return;
if ( V_281 == V_282 && F_218 ( & V_6 -> V_508 ) )
return;
}
if ( V_6 -> V_382 . V_392 ) {
if ( ! F_335 ( V_6 , V_393 , V_547 , V_548 , V_682 ,
V_604 ) )
return;
}
if ( V_6 -> V_382 . V_386 ) {
if ( V_146 ) {
if ( ! ( V_146 [ 1 ] & 0x20 ) )
return;
} else {
T_1 * V_165 = F_338 ( V_547 , V_548 , V_570 , NULL ) ;
if ( ! V_165 || ! ( V_165 [ 0 ] & V_132 ) )
return;
}
}
if ( sizeof( * V_155 ) + V_548 + V_604 + 5 > sizeof( V_646 ) )
return;
memset ( V_646 , 0 , sizeof( V_646 ) ) ;
if ( V_393 == V_477 && ! V_6 -> V_382 . V_385 &&
V_281 == V_264 )
V_393 = 0 ;
F_65 ( & V_155 -> V_251 . V_122 , V_122 ) ;
V_155 -> V_251 . type = F_153 ( V_281 , V_255 ) ;
V_155 -> V_393 = V_393 ;
V_155 -> V_165 = F_31 ( V_165 ) ;
if ( V_548 > 0 )
memcpy ( V_155 -> V_547 , V_547 , V_548 ) ;
if ( V_146 && ! F_338 ( V_155 -> V_547 , V_548 , V_557 ,
NULL ) )
V_548 = F_276 ( V_155 -> V_547 , V_548 , V_557 ,
V_146 , 3 ) ;
if ( V_604 > 0 )
memcpy ( V_155 -> V_547 + V_548 , V_682 , V_604 ) ;
V_155 -> V_548 = F_11 ( V_548 + V_604 ) ;
V_685 = sizeof( * V_155 ) + V_548 + V_604 ;
F_7 ( V_686 , V_6 , V_155 , V_685 , NULL ) ;
}
void F_339 ( struct V_5 * V_6 , T_7 * V_122 , T_1 V_281 ,
T_1 V_255 , T_10 V_393 , T_1 * V_83 , T_1 V_645 )
{
struct V_684 * V_155 ;
char V_646 [ sizeof( * V_155 ) + V_676 + 2 ] ;
T_2 V_548 ;
V_155 = (struct V_684 * ) V_646 ;
memset ( V_646 , 0 , sizeof( V_646 ) ) ;
F_65 ( & V_155 -> V_251 . V_122 , V_122 ) ;
V_155 -> V_251 . type = F_153 ( V_281 , V_255 ) ;
V_155 -> V_393 = V_393 ;
V_548 = F_276 ( V_155 -> V_547 , 0 , V_650 , V_83 ,
V_645 ) ;
V_155 -> V_548 = F_11 ( V_548 ) ;
F_7 ( V_686 , V_6 , V_155 , sizeof( * V_155 ) + V_548 , NULL ) ;
}
void F_340 ( struct V_5 * V_6 , T_1 V_687 )
{
struct V_688 V_155 ;
F_10 ( L_42 , V_6 -> V_83 , V_687 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . type = V_6 -> V_382 . type ;
V_155 . V_687 = V_687 ;
F_7 ( V_689 , V_6 , & V_155 , sizeof( V_155 ) , NULL ) ;
}
int F_341 ( void )
{
return F_342 ( & V_690 ) ;
}
void F_343 ( void )
{
F_344 ( & V_690 ) ;
}
