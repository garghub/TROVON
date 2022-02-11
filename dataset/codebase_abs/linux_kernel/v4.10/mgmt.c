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
static int F_6 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 , T_2 V_8 ,
struct V_11 * V_12 )
{
return F_4 ( V_4 , V_6 , V_10 , V_7 , V_8 ,
V_13 , V_12 ) ;
}
static T_1 F_7 ( T_1 V_14 )
{
if ( V_14 == V_15 )
return V_16 ;
else
return V_17 ;
}
void F_8 ( void * V_18 )
{
struct V_19 * V_20 = V_18 ;
V_20 -> V_21 = V_22 ;
V_20 -> V_23 = F_9 ( V_24 ) ;
}
static int F_10 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_26 )
{
struct V_19 V_20 ;
F_11 ( L_1 , V_25 ) ;
F_8 ( & V_20 ) ;
return F_12 ( V_25 , V_27 , V_28 , 0 ,
& V_20 , sizeof( V_20 ) ) ;
}
static int F_13 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_26 )
{
struct V_29 * V_20 ;
T_2 V_30 , V_31 ;
T_3 V_32 ;
int V_33 , V_34 ;
F_11 ( L_1 , V_25 ) ;
if ( F_14 ( V_25 , V_13 ) ) {
V_30 = F_2 ( V_35 ) ;
V_31 = F_2 ( V_36 ) ;
} else {
V_30 = F_2 ( V_37 ) ;
V_31 = F_2 ( V_38 ) ;
}
V_32 = sizeof( * V_20 ) + ( ( V_30 + V_31 ) * sizeof( T_2 ) ) ;
V_20 = F_15 ( V_32 , V_39 ) ;
if ( ! V_20 )
return - V_40 ;
V_20 -> V_30 = F_9 ( V_30 ) ;
V_20 -> V_31 = F_9 ( V_31 ) ;
if ( F_14 ( V_25 , V_13 ) ) {
T_4 * V_41 = V_20 -> V_42 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ , V_41 ++ )
F_16 ( V_35 [ V_33 ] , V_41 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_41 ++ )
F_16 ( V_36 [ V_33 ] , V_41 ) ;
} else {
T_4 * V_41 = V_20 -> V_42 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ , V_41 ++ )
F_16 ( V_37 [ V_33 ] , V_41 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_41 ++ )
F_16 ( V_38 [ V_33 ] , V_41 ) ;
}
V_34 = F_12 ( V_25 , V_27 , V_43 , 0 ,
V_20 , V_32 ) ;
F_17 ( V_20 ) ;
return V_34 ;
}
static int F_18 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_26 )
{
struct V_44 * V_20 ;
struct V_5 * V_45 ;
T_3 V_46 ;
T_2 V_47 ;
int V_34 ;
F_11 ( L_1 , V_25 ) ;
F_19 ( & V_48 ) ;
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( V_45 -> V_49 == V_50 &&
! F_21 ( V_45 , V_51 ) )
V_47 ++ ;
}
V_46 = sizeof( * V_20 ) + ( 2 * V_47 ) ;
V_20 = F_15 ( V_46 , V_52 ) ;
if ( ! V_20 ) {
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
V_20 -> V_58 [ V_47 ++ ] = F_9 ( V_45 -> V_59 ) ;
F_11 ( L_2 , V_45 -> V_59 ) ;
}
}
V_20 -> V_60 = F_9 ( V_47 ) ;
V_46 = sizeof( * V_20 ) + ( 2 * V_47 ) ;
F_22 ( & V_48 ) ;
V_34 = F_12 ( V_25 , V_27 , V_61 ,
0 , V_20 , V_46 ) ;
F_17 ( V_20 ) ;
return V_34 ;
}
static int F_24 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_62 * V_20 ;
struct V_5 * V_45 ;
T_3 V_46 ;
T_2 V_47 ;
int V_34 ;
F_11 ( L_1 , V_25 ) ;
F_19 ( & V_48 ) ;
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( V_45 -> V_49 == V_50 &&
F_21 ( V_45 , V_51 ) )
V_47 ++ ;
}
V_46 = sizeof( * V_20 ) + ( 2 * V_47 ) ;
V_20 = F_15 ( V_46 , V_52 ) ;
if ( ! V_20 ) {
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
V_20 -> V_58 [ V_47 ++ ] = F_9 ( V_45 -> V_59 ) ;
F_11 ( L_2 , V_45 -> V_59 ) ;
}
}
V_20 -> V_60 = F_9 ( V_47 ) ;
V_46 = sizeof( * V_20 ) + ( 2 * V_47 ) ;
F_22 ( & V_48 ) ;
V_34 = F_12 ( V_25 , V_27 ,
V_63 , 0 , V_20 , V_46 ) ;
F_17 ( V_20 ) ;
return V_34 ;
}
static int F_25 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_64 * V_20 ;
struct V_5 * V_45 ;
T_3 V_46 ;
T_2 V_47 ;
int V_34 ;
F_11 ( L_1 , V_25 ) ;
F_19 ( & V_48 ) ;
V_47 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( V_45 -> V_49 == V_50 || V_45 -> V_49 == V_65 )
V_47 ++ ;
}
V_46 = sizeof( * V_20 ) + ( sizeof( V_20 -> V_66 [ 0 ] ) * V_47 ) ;
V_20 = F_15 ( V_46 , V_52 ) ;
if ( ! V_20 ) {
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
V_20 -> V_66 [ V_47 ] . type = 0x01 ;
else
V_20 -> V_66 [ V_47 ] . type = 0x00 ;
} else if ( V_45 -> V_49 == V_65 ) {
V_20 -> V_66 [ V_47 ] . type = 0x02 ;
} else {
continue;
}
V_20 -> V_66 [ V_47 ] . V_67 = V_45 -> V_67 ;
V_20 -> V_66 [ V_47 ++ ] . V_58 = F_9 ( V_45 -> V_59 ) ;
F_11 ( L_2 , V_45 -> V_59 ) ;
}
V_20 -> V_60 = F_9 ( V_47 ) ;
V_46 = sizeof( * V_20 ) + ( sizeof( V_20 -> V_66 [ 0 ] ) * V_47 ) ;
F_22 ( & V_48 ) ;
F_26 ( V_25 , V_68 ) ;
F_27 ( V_25 , V_69 ) ;
F_27 ( V_25 , V_70 ) ;
V_34 = F_12 ( V_25 , V_27 ,
V_71 , 0 , V_20 , V_46 ) ;
F_17 ( V_20 ) ;
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
return F_5 ( V_81 , V_6 , & V_77 ,
sizeof( V_77 ) , V_82 , V_80 ) ;
}
static int F_33 ( struct V_11 * V_25 , T_2 V_41 , struct V_5 * V_6 )
{
T_5 V_77 = F_30 ( V_6 ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_41 , 0 , & V_77 ,
sizeof( V_77 ) ) ;
}
static int F_34 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_83 V_20 ;
T_6 V_77 = 0 ;
F_11 ( L_3 , V_25 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_85 = F_9 ( V_6 -> V_85 ) ;
if ( F_23 ( V_72 , & V_6 -> V_57 ) )
V_77 |= V_78 ;
if ( V_6 -> V_86 )
V_77 |= V_79 ;
V_20 . V_87 = F_31 ( V_77 ) ;
V_20 . V_88 = F_30 ( V_6 ) ;
F_36 ( V_6 ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_89 , 0 ,
& V_20 , sizeof( V_20 ) ) ;
}
static T_6 F_37 ( struct V_5 * V_6 )
{
T_6 V_90 = 0 ;
V_90 |= V_91 ;
V_90 |= V_92 ;
V_90 |= V_93 ;
V_90 |= V_94 ;
V_90 |= V_95 ;
if ( F_38 ( V_6 ) ) {
if ( V_6 -> V_96 >= V_97 )
V_90 |= V_98 ;
V_90 |= V_99 ;
V_90 |= V_100 ;
if ( F_39 ( V_6 ) ) {
V_90 |= V_101 ;
V_90 |= V_102 ;
}
if ( F_40 ( V_6 ) )
V_90 |= V_103 ;
}
if ( F_41 ( V_6 ) ) {
V_90 |= V_104 ;
V_90 |= V_105 ;
V_90 |= V_103 ;
V_90 |= V_106 ;
V_90 |= V_107 ;
}
if ( F_23 ( V_72 , & V_6 -> V_57 ) ||
V_6 -> V_86 )
V_90 |= V_108 ;
return V_90 ;
}
static T_6 F_42 ( struct V_5 * V_6 )
{
T_6 V_90 = 0 ;
if ( F_43 ( V_6 ) )
V_90 |= V_91 ;
if ( F_21 ( V_6 , V_109 ) )
V_90 |= V_94 ;
if ( F_21 ( V_6 , V_110 ) )
V_90 |= V_98 ;
if ( F_21 ( V_6 , V_111 ) )
V_90 |= V_95 ;
if ( F_21 ( V_6 , V_112 ) )
V_90 |= V_92 ;
if ( F_21 ( V_6 , V_113 ) )
V_90 |= V_99 ;
if ( F_21 ( V_6 , V_114 ) )
V_90 |= V_104 ;
if ( F_21 ( V_6 , V_115 ) )
V_90 |= V_100 ;
if ( F_21 ( V_6 , V_116 ) )
V_90 |= V_101 ;
if ( F_21 ( V_6 , V_117 ) )
V_90 |= V_102 ;
if ( F_21 ( V_6 , V_118 ) )
V_90 |= V_105 ;
if ( F_21 ( V_6 , V_119 ) )
V_90 |= V_103 ;
if ( F_21 ( V_6 , V_120 ) )
V_90 |= V_93 ;
if ( F_21 ( V_6 , V_121 ) )
V_90 |= V_106 ;
if ( F_21 ( V_6 , V_122 ) ||
! F_21 ( V_6 , V_113 ) ||
! F_29 ( & V_6 -> V_123 , V_76 ) ) {
if ( F_29 ( & V_6 -> V_124 , V_76 ) )
V_90 |= V_107 ;
}
return V_90 ;
}
static struct V_125 * F_44 ( T_2 V_41 , struct V_5 * V_6 )
{
return F_45 ( V_10 , V_41 , V_6 ) ;
}
static struct V_125 * F_46 ( T_2 V_41 ,
struct V_5 * V_6 ,
const void * V_7 )
{
return F_47 ( V_10 , V_41 , V_6 , V_7 ) ;
}
T_1 F_48 ( struct V_5 * V_6 )
{
struct V_125 * V_126 ;
V_126 = F_44 ( V_127 , V_6 ) ;
if ( V_126 ) {
struct V_128 * V_129 = V_126 -> V_130 ;
if ( V_129 -> V_131 == 0x01 )
return V_132 ;
else if ( V_129 -> V_131 == 0x02 )
return V_133 ;
} else {
if ( F_21 ( V_6 , V_134 ) )
return V_133 ;
else if ( F_21 ( V_6 , V_111 ) )
return V_132 ;
}
return 0 ;
}
bool F_49 ( struct V_5 * V_6 )
{
struct V_125 * V_126 ;
V_126 = F_44 ( V_135 , V_6 ) ;
if ( V_126 ) {
struct V_128 * V_129 = V_126 -> V_130 ;
return V_129 -> V_131 ;
}
return F_21 ( V_6 , V_109 ) ;
}
static void F_50 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = F_51 ( V_137 , struct V_5 ,
V_138 . V_137 ) ;
struct V_139 V_140 ;
if ( ! F_52 ( V_6 , V_141 ) )
return;
F_53 ( & V_140 , V_6 ) ;
F_35 ( V_6 ) ;
F_54 ( & V_140 ) ;
F_55 ( & V_140 ) ;
F_36 ( V_6 ) ;
F_56 ( & V_140 , NULL ) ;
}
static void F_57 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = F_51 ( V_137 , struct V_5 ,
F_57 . V_137 ) ;
struct V_139 V_140 ;
F_11 ( L_4 ) ;
F_58 ( V_6 , V_142 ) ;
if ( ! F_21 ( V_6 , V_118 ) )
return;
F_53 ( & V_140 , V_6 ) ;
F_59 ( & V_140 ) ;
F_56 ( & V_140 , NULL ) ;
}
static void F_60 ( struct V_11 * V_25 , struct V_5 * V_6 )
{
if ( F_61 ( V_6 , V_143 ) )
return;
F_62 ( & V_6 -> V_138 , F_50 ) ;
F_62 ( & V_6 -> F_57 , F_57 ) ;
F_63 ( V_6 , V_112 ) ;
}
static int F_64 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_144 V_20 ;
F_11 ( L_3 , V_25 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_65 ( & V_20 . V_123 , & V_6 -> V_123 ) ;
V_20 . V_21 = V_6 -> V_96 ;
V_20 . V_85 = F_9 ( V_6 -> V_85 ) ;
V_20 . V_145 = F_31 ( F_37 ( V_6 ) ) ;
V_20 . V_146 = F_31 ( F_42 ( V_6 ) ) ;
memcpy ( V_20 . V_147 , V_6 -> V_147 , 3 ) ;
memcpy ( V_20 . V_84 , V_6 -> V_148 , sizeof( V_6 -> V_148 ) ) ;
memcpy ( V_20 . V_149 , V_6 -> V_149 , sizeof( V_6 -> V_149 ) ) ;
F_36 ( V_6 ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_150 , 0 , & V_20 ,
sizeof( V_20 ) ) ;
}
static T_2 F_66 ( struct V_5 * V_6 , T_1 * V_151 )
{
T_2 V_152 = 0 ;
T_3 V_153 ;
if ( F_21 ( V_6 , V_113 ) )
V_152 = F_67 ( V_151 , V_152 , V_154 ,
V_6 -> V_147 , 3 ) ;
if ( F_21 ( V_6 , V_114 ) )
V_152 = F_68 ( V_151 , V_152 , V_155 ,
V_6 -> V_156 ) ;
V_153 = strlen ( V_6 -> V_148 ) ;
V_152 = F_67 ( V_151 , V_152 , V_157 ,
V_6 -> V_148 , V_153 ) ;
V_153 = strlen ( V_6 -> V_149 ) ;
V_152 = F_67 ( V_151 , V_152 , V_158 ,
V_6 -> V_149 , V_153 ) ;
return V_152 ;
}
static int F_69 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
char V_159 [ 512 ] ;
struct V_160 * V_20 = ( void * ) V_159 ;
T_2 V_152 ;
F_11 ( L_3 , V_25 , V_6 -> V_84 ) ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
F_35 ( V_6 ) ;
F_65 ( & V_20 -> V_123 , & V_6 -> V_123 ) ;
V_20 -> V_21 = V_6 -> V_96 ;
V_20 -> V_85 = F_9 ( V_6 -> V_85 ) ;
V_20 -> V_145 = F_31 ( F_37 ( V_6 ) ) ;
V_20 -> V_146 = F_31 ( F_42 ( V_6 ) ) ;
V_152 = F_66 ( V_6 , V_20 -> V_151 ) ;
V_20 -> V_152 = F_9 ( V_152 ) ;
F_36 ( V_6 ) ;
F_26 ( V_25 , V_161 ) ;
F_27 ( V_25 , V_162 ) ;
F_27 ( V_25 , V_163 ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_164 , 0 , V_20 ,
sizeof( * V_20 ) + V_152 ) ;
}
static int F_70 ( struct V_5 * V_6 , struct V_11 * V_80 )
{
char V_159 [ 512 ] ;
struct V_165 * V_166 = ( void * ) V_159 ;
T_2 V_152 ;
memset ( V_159 , 0 , sizeof( V_159 ) ) ;
V_152 = F_66 ( V_6 , V_166 -> V_151 ) ;
V_166 -> V_152 = F_9 ( V_152 ) ;
return F_5 ( V_167 , V_6 , V_166 ,
sizeof( * V_166 ) + V_152 ,
V_161 , V_80 ) ;
}
static int F_71 ( struct V_11 * V_25 , T_2 V_41 , struct V_5 * V_6 )
{
T_5 V_90 = F_31 ( F_42 ( V_6 ) ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_41 , 0 , & V_90 ,
sizeof( V_90 ) ) ;
}
static void F_72 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
F_11 ( L_5 , V_6 -> V_84 , V_168 ) ;
if ( F_73 ( V_6 ) == 0 ) {
F_74 ( & V_6 -> V_169 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_169 . V_137 ) ;
}
}
void F_76 ( struct V_11 * V_25 , struct V_5 * V_6 , T_1 V_171 )
{
struct V_172 V_166 ;
V_166 . V_171 = V_171 ;
F_6 ( V_173 , V_6 , & V_166 , sizeof( V_166 ) , V_25 ) ;
}
void F_77 ( struct V_11 * V_25 , struct V_5 * V_6 ,
T_1 V_171 )
{
struct V_174 V_166 ;
V_166 . V_171 = V_171 ;
F_6 ( V_175 , V_6 , & V_166 , sizeof( V_166 ) , V_25 ) ;
}
static void F_78 ( struct V_5 * V_6 )
{
if ( V_6 -> V_176 ) {
V_6 -> V_176 = 0 ;
F_74 ( & V_6 -> V_177 ) ;
}
}
static int F_79 ( struct V_5 * V_6 )
{
struct V_139 V_140 ;
struct V_178 * V_179 ;
bool V_180 ;
int V_34 ;
F_53 ( & V_140 , V_6 ) ;
if ( F_23 ( V_181 , & V_6 -> V_182 ) ||
F_23 ( V_183 , & V_6 -> V_182 ) ) {
T_1 V_184 = 0x00 ;
F_80 ( & V_140 , V_185 , 1 , & V_184 ) ;
}
F_81 ( V_6 , NULL , NULL , 0x00 , false ) ;
if ( F_21 ( V_6 , V_186 ) )
F_82 ( & V_140 ) ;
V_180 = F_83 ( & V_140 ) ;
F_20 (conn, &hdev->conn_hash.list, list) {
F_84 ( & V_140 , V_179 , 0x15 ) ;
}
V_34 = F_56 ( & V_140 , F_72 ) ;
if ( ! V_34 && V_180 )
F_85 ( V_6 , V_187 ) ;
return V_34 ;
}
static int F_86 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_188 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_188 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_188 ,
V_190 ) ;
goto V_191;
}
if ( ! ! V_129 -> V_131 == F_43 ( V_6 ) ) {
V_34 = F_71 ( V_25 , V_188 , V_6 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_188 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
if ( V_129 -> V_131 ) {
F_75 ( V_6 -> V_170 , & V_6 -> V_192 ) ;
V_34 = 0 ;
} else {
V_34 = F_79 ( V_6 ) ;
if ( ! V_34 )
F_89 ( V_6 -> V_170 , & V_6 -> V_169 ,
V_193 ) ;
if ( V_34 == - V_194 ) {
F_74 ( & V_6 -> V_169 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_169 . V_137 ) ;
V_34 = 0 ;
}
}
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_90 ( struct V_5 * V_6 , struct V_11 * V_80 )
{
T_5 V_166 = F_31 ( F_42 ( V_6 ) ) ;
return F_5 ( V_195 , V_6 , & V_166 ,
sizeof( V_166 ) , V_196 , V_80 ) ;
}
int F_91 ( struct V_5 * V_6 )
{
return F_90 ( V_6 , NULL ) ;
}
static void F_92 ( struct V_125 * V_126 , void * V_7 )
{
struct V_197 * V_198 = V_7 ;
F_71 ( V_126 -> V_25 , V_126 -> V_41 , V_198 -> V_6 ) ;
F_93 ( & V_126 -> V_199 ) ;
if ( V_198 -> V_25 == NULL ) {
V_198 -> V_25 = V_126 -> V_25 ;
F_94 ( V_198 -> V_25 ) ;
}
F_95 ( V_126 ) ;
}
static void F_96 ( struct V_125 * V_126 , void * V_7 )
{
T_1 * V_168 = V_7 ;
F_87 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , * V_168 ) ;
F_97 ( V_126 ) ;
}
static void F_98 ( struct V_125 * V_126 , void * V_7 )
{
if ( V_126 -> V_200 ) {
T_1 * V_168 = V_7 ;
V_126 -> V_200 ( V_126 , * V_168 ) ;
F_97 ( V_126 ) ;
return;
}
F_96 ( V_126 , V_7 ) ;
}
static int F_99 ( struct V_125 * V_126 , T_1 V_168 )
{
return F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_168 ,
V_126 -> V_130 , V_126 -> V_201 ) ;
}
static int F_100 ( struct V_125 * V_126 , T_1 V_168 )
{
return F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_168 ,
V_126 -> V_130 , sizeof( struct V_202 ) ) ;
}
static T_1 F_101 ( struct V_5 * V_6 )
{
if ( ! F_38 ( V_6 ) )
return V_203 ;
else if ( ! F_21 ( V_6 , V_113 ) )
return V_204 ;
else
return V_205 ;
}
static T_1 F_102 ( struct V_5 * V_6 )
{
if ( ! F_41 ( V_6 ) )
return V_203 ;
else if ( ! F_21 ( V_6 , V_114 ) )
return V_204 ;
else
return V_205 ;
}
void F_103 ( struct V_5 * V_6 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_11 ( L_7 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_127 , V_6 ) ;
if ( ! V_126 )
goto V_206;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
F_87 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_207 ) ;
F_63 ( V_6 , V_134 ) ;
goto V_208;
}
if ( F_21 ( V_6 , V_111 ) &&
V_6 -> V_209 > 0 ) {
int V_210 = F_104 ( V_6 -> V_209 * 1000 ) ;
F_89 ( V_6 -> V_170 , & V_6 -> V_211 , V_210 ) ;
}
F_71 ( V_126 -> V_25 , V_127 , V_6 ) ;
F_90 ( V_6 , V_126 -> V_25 ) ;
V_208:
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_105 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_212 * V_129 = V_7 ;
struct V_125 * V_126 ;
T_2 V_213 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_21 ( V_6 , V_114 ) &&
! F_21 ( V_6 , V_113 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_127 ,
V_204 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 && V_129 -> V_131 != 0x02 )
return F_87 ( V_25 , V_6 -> V_59 , V_127 ,
V_189 ) ;
V_213 = F_106 ( V_129 -> V_213 ) ;
if ( ( V_129 -> V_131 == 0x00 && V_213 > 0 ) ||
( V_129 -> V_131 == 0x02 && V_213 == 0 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_127 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) && V_213 > 0 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_127 ,
V_214 ) ;
goto V_191;
}
if ( F_44 ( V_127 , V_6 ) ||
F_44 ( V_135 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_127 ,
V_190 ) ;
goto V_191;
}
if ( ! F_21 ( V_6 , V_109 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_127 ,
V_204 ) ;
goto V_191;
}
if ( ! F_43 ( V_6 ) ) {
bool V_215 = false ;
if ( ! ! V_129 -> V_131 != F_21 ( V_6 , V_111 ) ) {
F_107 ( V_6 , V_111 ) ;
V_215 = true ;
}
V_34 = F_71 ( V_25 , V_127 , V_6 ) ;
if ( V_34 < 0 )
goto V_191;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_191;
}
if ( ! ! V_129 -> V_131 == F_21 ( V_6 , V_111 ) &&
( V_129 -> V_131 == 0x02 ) == F_21 ( V_6 ,
V_134 ) ) {
F_74 ( & V_6 -> V_211 ) ;
V_6 -> V_209 = V_213 ;
if ( V_129 -> V_131 && V_6 -> V_209 > 0 ) {
int V_210 = F_104 ( V_6 -> V_209 * 1000 ) ;
F_89 ( V_6 -> V_170 ,
& V_6 -> V_211 , V_210 ) ;
}
V_34 = F_71 ( V_25 , V_127 , V_6 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_127 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
F_74 ( & V_6 -> V_211 ) ;
V_6 -> V_209 = V_213 ;
if ( V_129 -> V_131 )
F_58 ( V_6 , V_111 ) ;
else
F_63 ( V_6 , V_111 ) ;
if ( V_129 -> V_131 == 0x02 )
F_58 ( V_6 , V_134 ) ;
else
F_63 ( V_6 , V_134 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_216 ) ;
V_34 = 0 ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
void F_108 ( struct V_5 * V_6 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_11 ( L_7 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_135 , V_6 ) ;
if ( ! V_126 )
goto V_206;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
F_87 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_207 ) ;
goto V_208;
}
F_71 ( V_126 -> V_25 , V_135 , V_6 ) ;
F_90 ( V_6 , V_126 -> V_25 ) ;
V_208:
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_109 ( struct V_5 * V_6 ,
struct V_11 * V_25 , T_1 V_131 )
{
bool V_215 = false ;
int V_34 ;
if ( ! ! V_131 != F_21 ( V_6 , V_109 ) )
V_215 = true ;
if ( V_131 ) {
F_58 ( V_6 , V_109 ) ;
} else {
F_63 ( V_6 , V_109 ) ;
F_63 ( V_6 , V_111 ) ;
}
V_34 = F_71 ( V_25 , V_135 , V_6 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_215 ) {
F_110 ( V_6 ) ;
F_111 ( V_6 ) ;
return F_90 ( V_6 , V_25 ) ;
}
return 0 ;
}
static int F_112 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_21 ( V_6 , V_114 ) &&
! F_21 ( V_6 , V_113 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_135 ,
V_204 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_135 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_109 ( V_6 , V_25 , V_129 -> V_131 ) ;
goto V_191;
}
if ( F_44 ( V_127 , V_6 ) ||
F_44 ( V_135 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_135 ,
V_190 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_135 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
if ( V_129 -> V_131 ) {
F_58 ( V_6 , V_109 ) ;
} else {
if ( V_6 -> V_209 > 0 )
F_74 ( & V_6 -> V_211 ) ;
F_63 ( V_6 , V_134 ) ;
F_63 ( V_6 , V_111 ) ;
F_63 ( V_6 , V_109 ) ;
}
F_75 ( V_6 -> V_170 , & V_6 -> V_217 ) ;
V_34 = 0 ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_113 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
bool V_215 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_218 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( V_129 -> V_131 )
V_215 = ! F_61 ( V_6 , V_112 ) ;
else
V_215 = F_52 ( V_6 , V_112 ) ;
V_34 = F_71 ( V_25 , V_218 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( V_215 ) {
if ( F_43 ( V_6 ) &&
F_21 ( V_6 , V_118 ) &&
F_21 ( V_6 , V_111 ) &&
F_21 ( V_6 , V_219 ) )
F_75 ( V_6 -> V_170 ,
& V_6 -> V_216 ) ;
V_34 = F_90 ( V_6 , V_25 ) ;
}
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_114 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
T_1 V_131 , V_168 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
V_168 = F_101 ( V_6 ) ;
if ( V_168 )
return F_87 ( V_25 , V_6 -> V_59 , V_220 ,
V_168 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_220 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_215 = false ;
if ( ! ! V_129 -> V_131 != F_21 ( V_6 , V_115 ) ) {
F_107 ( V_6 , V_115 ) ;
V_215 = true ;
}
V_34 = F_71 ( V_25 , V_220 , V_6 ) ;
if ( V_34 < 0 )
goto V_191;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_191;
}
if ( F_44 ( V_220 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_220 ,
V_190 ) ;
goto V_191;
}
V_131 = ! ! V_129 -> V_131 ;
if ( F_23 ( V_221 , & V_6 -> V_182 ) == V_131 ) {
V_34 = F_71 ( V_25 , V_220 , V_6 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_220 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
V_34 = F_115 ( V_6 , V_222 , sizeof( V_131 ) , & V_131 ) ;
if ( V_34 < 0 ) {
F_97 ( V_126 ) ;
goto V_191;
}
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_116 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
V_168 = F_101 ( V_6 ) ;
if ( V_168 )
return F_87 ( V_25 , V_6 -> V_59 , V_223 , V_168 ) ;
if ( ! F_39 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_223 ,
V_203 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_223 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_215 ;
if ( V_129 -> V_131 ) {
V_215 = ! F_61 ( V_6 ,
V_116 ) ;
} else {
V_215 = F_52 ( V_6 ,
V_116 ) ;
if ( ! V_215 )
V_215 = F_52 ( V_6 ,
V_117 ) ;
else
F_63 ( V_6 , V_117 ) ;
}
V_34 = F_71 ( V_25 , V_223 , V_6 ) ;
if ( V_34 < 0 )
goto V_191;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_191;
}
if ( F_44 ( V_223 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_223 ,
V_190 ) ;
goto V_191;
}
if ( ! ! V_129 -> V_131 == F_21 ( V_6 , V_116 ) ) {
V_34 = F_71 ( V_25 , V_223 , V_6 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_223 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
if ( ! V_129 -> V_131 && F_21 ( V_6 , V_224 ) )
F_115 ( V_6 , V_225 ,
sizeof( V_129 -> V_131 ) , & V_129 -> V_131 ) ;
V_34 = F_115 ( V_6 , V_226 , 1 , & V_129 -> V_131 ) ;
if ( V_34 < 0 ) {
F_97 ( V_126 ) ;
goto V_191;
}
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_117 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
bool V_215 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
V_168 = F_101 ( V_6 ) ;
if ( V_168 )
return F_87 ( V_25 , V_6 -> V_59 , V_227 , V_168 ) ;
if ( ! F_39 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_227 ,
V_203 ) ;
if ( ! F_21 ( V_6 , V_116 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_227 ,
V_204 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_227 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_223 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_227 ,
V_190 ) ;
goto V_206;
}
if ( V_129 -> V_131 ) {
V_215 = ! F_61 ( V_6 , V_117 ) ;
} else {
if ( F_43 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_227 ,
V_204 ) ;
goto V_206;
}
V_215 = F_52 ( V_6 , V_117 ) ;
}
V_34 = F_71 ( V_25 , V_227 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_118 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
struct V_197 V_198 = { NULL , V_6 } ;
F_35 ( V_6 ) ;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
F_119 ( V_228 , V_6 , F_96 ,
& V_207 ) ;
goto V_206;
}
F_119 ( V_228 , V_6 , F_92 , & V_198 ) ;
F_90 ( V_6 , V_198 . V_25 ) ;
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
if ( F_21 ( V_6 , V_114 ) ) {
struct V_139 V_140 ;
F_53 ( & V_140 , V_6 ) ;
F_121 ( & V_140 , 0x00 ) ;
F_122 ( & V_140 , 0x00 ) ;
F_56 ( & V_140 , NULL ) ;
F_111 ( V_6 ) ;
}
V_206:
F_36 ( V_6 ) ;
}
static int F_123 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_229 V_230 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
T_1 V_131 , V_231 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_228 ,
V_203 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_228 ,
V_189 ) ;
if ( ! F_21 ( V_6 , V_113 ) ) {
if ( V_129 -> V_131 == 0x01 )
return F_71 ( V_25 , V_228 , V_6 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_228 ,
V_204 ) ;
}
F_35 ( V_6 ) ;
V_131 = ! ! V_129 -> V_131 ;
V_231 = F_124 ( V_6 ) ;
if ( ! V_131 )
F_81 ( V_6 , NULL , NULL , 0x00 , true ) ;
if ( ! F_43 ( V_6 ) || V_131 == V_231 ) {
bool V_215 = false ;
if ( V_131 != F_21 ( V_6 , V_114 ) ) {
F_107 ( V_6 , V_114 ) ;
V_215 = true ;
}
if ( ! V_131 && F_21 ( V_6 , V_118 ) ) {
F_63 ( V_6 , V_118 ) ;
V_215 = true ;
}
V_34 = F_71 ( V_25 , V_228 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_206;
}
if ( F_44 ( V_228 , V_6 ) ||
F_44 ( V_232 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_228 ,
V_190 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_228 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
if ( V_131 ) {
V_230 . V_233 = V_131 ;
V_230 . V_234 = 0x00 ;
} else {
if ( F_21 ( V_6 , V_186 ) )
F_82 ( & V_140 ) ;
}
F_80 ( & V_140 , V_235 , sizeof( V_230 ) ,
& V_230 ) ;
V_34 = F_56 ( & V_140 , F_118 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_125 ( struct V_5 * V_6 )
{
struct V_125 * V_126 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
switch ( V_126 -> V_41 ) {
case V_236 :
case V_237 :
case V_238 :
case V_188 :
return true ;
}
}
return false ;
}
static T_1 F_126 ( const T_1 * V_239 )
{
T_6 V_131 ;
if ( memcmp ( V_239 , V_240 , 12 ) )
return 128 ;
V_131 = F_127 ( & V_239 [ 12 ] ) ;
if ( V_131 > 0xffff )
return 32 ;
return 16 ;
}
static void F_128 ( struct V_5 * V_6 , T_2 V_241 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_241 , V_6 ) ;
if ( ! V_126 )
goto V_206;
F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 ,
F_1 ( V_168 ) , V_6 -> V_147 , 3 ) ;
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static void F_129 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
F_11 ( L_7 , V_168 ) ;
F_128 ( V_6 , V_236 , V_168 ) ;
}
static int F_130 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_242 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
struct V_243 * V_239 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( F_125 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_236 ,
V_190 ) ;
goto V_191;
}
V_239 = F_15 ( sizeof( * V_239 ) , V_39 ) ;
if ( ! V_239 ) {
V_34 = - V_40 ;
goto V_191;
}
memcpy ( V_239 -> V_239 , V_129 -> V_239 , 16 ) ;
V_239 -> V_244 = V_129 -> V_244 ;
V_239 -> V_245 = F_126 ( V_129 -> V_239 ) ;
F_131 ( & V_239 -> V_199 , & V_6 -> V_246 ) ;
F_53 ( & V_140 , V_6 ) ;
F_55 ( & V_140 ) ;
F_54 ( & V_140 ) ;
V_34 = F_56 ( & V_140 , F_129 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_194 )
goto V_191;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_236 , 0 ,
V_6 -> V_147 , 3 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_236 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
V_34 = 0 ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_132 ( struct V_5 * V_6 )
{
if ( ! F_43 ( V_6 ) )
return false ;
if ( ! F_61 ( V_6 , V_141 ) ) {
F_89 ( V_6 -> V_247 , & V_6 -> V_138 ,
V_248 ) ;
return true ;
}
return false ;
}
static void F_133 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
F_11 ( L_7 , V_168 ) ;
F_128 ( V_6 , V_237 , V_168 ) ;
}
static int F_134 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_249 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_243 * V_198 , * V_250 ;
T_1 V_251 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_139 V_140 ;
int V_34 , V_252 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( F_125 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_237 ,
V_190 ) ;
goto V_206;
}
if ( memcmp ( V_129 -> V_239 , V_251 , 16 ) == 0 ) {
F_135 ( V_6 ) ;
if ( F_132 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_237 ,
0 , V_6 -> V_147 , 3 ) ;
goto V_206;
}
goto V_253;
}
V_252 = 0 ;
F_136 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_198 -> V_239 , V_129 -> V_239 , 16 ) != 0 )
continue;
F_93 ( & V_198 -> V_199 ) ;
F_17 ( V_198 ) ;
V_252 ++ ;
}
if ( V_252 == 0 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_237 ,
V_189 ) ;
goto V_206;
}
V_253:
F_53 ( & V_140 , V_6 ) ;
F_55 ( & V_140 ) ;
F_54 ( & V_140 ) ;
V_34 = F_56 ( & V_140 , F_133 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_194 )
goto V_206;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_237 , 0 ,
V_6 -> V_147 , 3 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_237 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
V_34 = 0 ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_137 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
F_11 ( L_7 , V_168 ) ;
F_128 ( V_6 , V_238 , V_168 ) ;
}
static int F_138 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_254 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_38 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_238 ,
V_203 ) ;
F_35 ( V_6 ) ;
if ( F_125 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_238 ,
V_190 ) ;
goto V_206;
}
if ( ( V_129 -> V_255 & 0x03 ) != 0 || ( V_129 -> V_256 & 0xe0 ) != 0 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_238 ,
V_189 ) ;
goto V_206;
}
V_6 -> V_257 = V_129 -> V_256 ;
V_6 -> V_258 = V_129 -> V_255 ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_238 , 0 ,
V_6 -> V_147 , 3 ) ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
if ( F_52 ( V_6 , V_141 ) ) {
F_36 ( V_6 ) ;
F_139 ( & V_6 -> V_138 ) ;
F_35 ( V_6 ) ;
F_54 ( & V_140 ) ;
}
F_55 ( & V_140 ) ;
V_34 = F_56 ( & V_140 , F_137 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_194 )
goto V_206;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_238 , 0 ,
V_6 -> V_147 , 3 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_238 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
V_34 = 0 ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_140 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_259 * V_129 = V_7 ;
const T_2 V_260 = ( ( V_261 - sizeof( * V_129 ) ) /
sizeof( struct V_262 ) ) ;
T_2 V_263 , V_264 ;
bool V_215 ;
int V_33 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_38 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_265 ,
V_203 ) ;
V_263 = F_106 ( V_129 -> V_263 ) ;
if ( V_263 > V_260 ) {
F_141 ( L_8 ,
V_263 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_265 ,
V_189 ) ;
}
V_264 = sizeof( * V_129 ) + V_263 *
sizeof( struct V_262 ) ;
if ( V_264 != V_8 ) {
F_141 ( L_9 ,
V_264 , V_8 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_265 ,
V_189 ) ;
}
if ( V_129 -> V_266 != 0x00 && V_129 -> V_266 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_265 ,
V_189 ) ;
F_11 ( L_10 , V_6 -> V_84 , V_129 -> V_266 ,
V_263 ) ;
for ( V_33 = 0 ; V_33 < V_263 ; V_33 ++ ) {
struct V_262 * V_267 = & V_129 -> V_268 [ V_33 ] ;
if ( V_267 -> V_269 . type != V_270 || V_267 -> type > 0x08 )
return F_87 ( V_25 , V_6 -> V_59 ,
V_265 ,
V_189 ) ;
}
F_35 ( V_6 ) ;
F_142 ( V_6 ) ;
if ( V_129 -> V_266 )
V_215 = ! F_61 ( V_6 , V_120 ) ;
else
V_215 = F_52 ( V_6 ,
V_120 ) ;
if ( V_215 )
F_90 ( V_6 , NULL ) ;
for ( V_33 = 0 ; V_33 < V_263 ; V_33 ++ ) {
struct V_262 * V_267 = & V_129 -> V_268 [ V_33 ] ;
if ( V_267 -> type == V_271 )
continue;
F_143 ( V_6 , NULL , & V_267 -> V_269 . V_123 , V_267 -> V_131 ,
V_267 -> type , V_267 -> V_272 , NULL ) ;
}
F_12 ( V_25 , V_6 -> V_59 , V_265 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int F_144 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_273 , struct V_11 * V_12 )
{
struct V_274 V_166 ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = V_273 ;
return F_6 ( V_275 , V_6 , & V_166 , sizeof( V_166 ) ,
V_12 ) ;
}
static int F_145 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_276 * V_129 = V_7 ;
struct V_277 V_20 ;
struct V_278 * V_279 ;
struct V_125 * V_126 ;
struct V_178 * V_179 ;
T_1 V_273 ;
int V_34 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_65 ( & V_20 . V_269 . V_123 , & V_129 -> V_269 . V_123 ) ;
V_20 . V_269 . type = V_129 -> V_269 . type ;
if ( ! F_146 ( V_129 -> V_269 . type ) )
return F_12 ( V_25 , V_6 -> V_59 , V_280 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
if ( V_129 -> V_281 != 0x00 && V_129 -> V_281 != 0x01 )
return F_12 ( V_25 , V_6 -> V_59 , V_280 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_280 ,
V_214 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
if ( V_129 -> V_269 . type == V_270 ) {
if ( V_129 -> V_281 )
V_179 = F_147 ( V_6 , V_282 ,
& V_129 -> V_269 . V_123 ) ;
else
V_179 = NULL ;
V_34 = F_148 ( V_6 , & V_129 -> V_269 . V_123 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_280 ,
V_283 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
goto V_284;
}
V_273 = F_7 ( V_129 -> V_269 . type ) ;
F_149 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ) ;
V_34 = F_150 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_280 ,
V_283 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
V_179 = F_151 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ) ;
if ( ! V_179 ) {
F_152 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ) ;
goto V_284;
}
F_153 ( V_179 ) ;
F_154 ( V_285 , & V_179 -> V_182 ) ;
V_279 = F_155 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ) ;
if ( V_279 ) {
if ( V_279 -> V_286 )
V_279 -> V_287 = V_288 ;
else
V_279 -> V_287 = V_289 ;
}
if ( ! V_129 -> V_281 )
V_179 = NULL ;
V_284:
if ( ! V_179 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_280 , 0 ,
& V_20 , sizeof( V_20 ) ) ;
F_144 ( V_6 , & V_129 -> V_269 . V_123 , V_129 -> V_269 . type , V_25 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_280 , V_6 , V_129 ,
sizeof( * V_129 ) ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
V_126 -> V_200 = F_100 ;
V_34 = F_156 ( V_179 , V_290 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int V_281 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_291 * V_129 = V_7 ;
struct V_292 V_20 ;
struct V_125 * V_126 ;
struct V_178 * V_179 ;
int V_34 ;
F_11 ( L_4 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_65 ( & V_20 . V_269 . V_123 , & V_129 -> V_269 . V_123 ) ;
V_20 . V_269 . type = V_129 -> V_269 . type ;
if ( ! F_146 ( V_129 -> V_269 . type ) )
return F_12 ( V_25 , V_6 -> V_59 , V_293 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_23 ( V_294 , & V_6 -> V_182 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_293 ,
V_214 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_191;
}
if ( F_44 ( V_293 , V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_293 ,
V_190 , & V_20 , sizeof( V_20 ) ) ;
goto V_191;
}
if ( V_129 -> V_269 . type == V_270 )
V_179 = F_147 ( V_6 , V_282 ,
& V_129 -> V_269 . V_123 ) ;
else
V_179 = F_151 ( V_6 , & V_129 -> V_269 . V_123 ,
F_7 ( V_129 -> V_269 . type ) ) ;
if ( ! V_179 || V_179 -> V_295 == V_296 || V_179 -> V_295 == V_297 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_293 ,
V_298 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_293 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
V_126 -> V_200 = F_99 ;
V_34 = F_157 ( V_179 , V_290 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static T_1 F_158 ( T_1 V_299 , T_1 V_273 )
{
switch ( V_299 ) {
case V_300 :
switch ( V_273 ) {
case V_16 :
return V_15 ;
default:
return V_301 ;
}
default:
return V_270 ;
}
}
static int F_159 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_26 )
{
struct V_302 * V_20 ;
struct V_178 * V_303 ;
T_3 V_46 ;
int V_34 ;
T_2 V_33 ;
F_11 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_304 ,
V_214 ) ;
goto V_206;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_23 ( V_305 , & V_303 -> V_182 ) )
V_33 ++ ;
}
V_46 = sizeof( * V_20 ) + ( V_33 * sizeof( struct V_202 ) ) ;
V_20 = F_15 ( V_46 , V_39 ) ;
if ( ! V_20 ) {
V_34 = - V_40 ;
goto V_206;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_23 ( V_305 , & V_303 -> V_182 ) )
continue;
F_65 ( & V_20 -> V_269 [ V_33 ] . V_123 , & V_303 -> V_306 ) ;
V_20 -> V_269 [ V_33 ] . type = F_158 ( V_303 -> type , V_303 -> V_307 ) ;
if ( V_303 -> type == V_308 || V_303 -> type == V_309 )
continue;
V_33 ++ ;
}
V_20 -> V_310 = F_9 ( V_33 ) ;
V_46 = sizeof( * V_20 ) + ( V_33 * sizeof( struct V_202 ) ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_304 , 0 , V_20 ,
V_46 ) ;
F_17 ( V_20 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_160 ( struct V_11 * V_25 , struct V_5 * V_6 ,
struct V_311 * V_129 )
{
struct V_125 * V_126 ;
int V_34 ;
V_126 = F_88 ( V_25 , V_312 , V_6 , V_129 ,
sizeof( * V_129 ) ) ;
if ( ! V_126 )
return - V_40 ;
V_126 -> V_200 = F_100 ;
V_34 = F_115 ( V_6 , V_313 ,
sizeof( V_129 -> V_269 . V_123 ) , & V_129 -> V_269 . V_123 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
return V_34 ;
}
static int F_161 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_178 * V_179 ;
struct V_314 * V_129 = V_7 ;
struct V_315 V_316 ;
struct V_125 * V_126 ;
int V_34 ;
F_11 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_317 ,
V_214 ) ;
goto V_191;
}
V_179 = F_147 ( V_6 , V_282 , & V_129 -> V_269 . V_123 ) ;
if ( ! V_179 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_317 ,
V_298 ) ;
goto V_191;
}
if ( V_179 -> V_318 == V_319 && V_129 -> V_272 != 16 ) {
struct V_311 V_320 ;
memcpy ( & V_320 . V_269 , & V_129 -> V_269 , sizeof( V_320 . V_269 ) ) ;
F_141 ( L_11 ) ;
V_34 = F_160 ( V_25 , V_6 , & V_320 ) ;
if ( V_34 >= 0 )
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_317 ,
V_189 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_317 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
V_126 -> V_200 = F_100 ;
F_65 ( & V_316 . V_123 , & V_129 -> V_269 . V_123 ) ;
V_316 . V_272 = V_129 -> V_272 ;
memcpy ( V_316 . V_321 , V_129 -> V_321 , sizeof( V_316 . V_321 ) ) ;
V_34 = F_115 ( V_6 , V_322 , sizeof( V_316 ) , & V_316 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_162 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_323 * V_129 = V_7 ;
F_11 ( L_4 ) ;
if ( V_129 -> V_324 > V_325 )
return F_87 ( V_25 , V_6 -> V_59 , V_326 ,
V_189 ) ;
F_35 ( V_6 ) ;
V_6 -> V_324 = V_129 -> V_324 ;
F_11 ( L_12 , V_6 -> V_84 ,
V_6 -> V_324 ) ;
F_36 ( V_6 ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_326 , 0 ,
NULL , 0 ) ;
}
static struct V_125 * F_163 ( struct V_178 * V_179 )
{
struct V_5 * V_6 = V_179 -> V_6 ;
struct V_125 * V_126 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_126 -> V_41 != V_327 )
continue;
if ( V_126 -> V_328 != V_179 )
continue;
return V_126 ;
}
return NULL ;
}
static int F_164 ( struct V_125 * V_126 , T_1 V_168 )
{
struct V_329 V_20 ;
struct V_178 * V_179 = V_126 -> V_328 ;
int V_34 ;
F_65 ( & V_20 . V_269 . V_123 , & V_179 -> V_306 ) ;
V_20 . V_269 . type = F_158 ( V_179 -> type , V_179 -> V_307 ) ;
V_34 = F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_327 ,
V_168 , & V_20 , sizeof( V_20 ) ) ;
V_179 -> V_330 = NULL ;
V_179 -> V_331 = NULL ;
V_179 -> V_332 = NULL ;
F_165 ( V_179 ) ;
F_166 ( V_285 , & V_179 -> V_182 ) ;
F_167 ( V_179 ) ;
return V_34 ;
}
void F_168 ( struct V_178 * V_179 , bool V_333 )
{
T_1 V_168 = V_333 ? V_205 : V_3 ;
struct V_125 * V_126 ;
V_126 = F_163 ( V_179 ) ;
if ( V_126 ) {
V_126 -> V_200 ( V_126 , V_168 ) ;
F_97 ( V_126 ) ;
}
}
static void F_169 ( struct V_178 * V_179 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_11 ( L_13 , V_168 ) ;
V_126 = F_163 ( V_179 ) ;
if ( ! V_126 ) {
F_11 ( L_14 ) ;
return;
}
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
static void F_170 ( struct V_178 * V_179 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_11 ( L_13 , V_168 ) ;
if ( ! V_168 )
return;
V_126 = F_163 ( V_179 ) ;
if ( ! V_126 ) {
F_11 ( L_14 ) ;
return;
}
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
static int F_171 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_334 * V_129 = V_7 ;
struct V_329 V_20 ;
struct V_125 * V_126 ;
T_1 V_335 , V_336 ;
struct V_178 * V_179 ;
int V_34 ;
F_11 ( L_4 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_65 ( & V_20 . V_269 . V_123 , & V_129 -> V_269 . V_123 ) ;
V_20 . V_269 . type = V_129 -> V_269 . type ;
if ( ! F_146 ( V_129 -> V_269 . type ) )
return F_12 ( V_25 , V_6 -> V_59 , V_327 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
if ( V_129 -> V_337 > V_325 )
return F_12 ( V_25 , V_6 -> V_59 , V_327 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_327 ,
V_214 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
if ( F_172 ( V_6 , & V_129 -> V_269 . V_123 , V_129 -> V_269 . type ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_327 ,
V_338 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
V_335 = V_339 ;
V_336 = V_340 ;
if ( V_129 -> V_269 . type == V_270 ) {
V_179 = F_173 ( V_6 , & V_129 -> V_269 . V_123 , V_335 ,
V_336 ) ;
} else {
T_1 V_273 = F_7 ( V_129 -> V_269 . type ) ;
struct V_278 * V_341 ;
V_341 = F_174 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ) ;
if ( V_341 -> V_287 == V_288 )
V_341 -> V_287 = V_289 ;
V_179 = F_175 ( V_6 , & V_129 -> V_269 . V_123 ,
V_273 , V_335 ,
V_342 ) ;
}
if ( F_176 ( V_179 ) ) {
int V_168 ;
if ( F_177 ( V_179 ) == - V_343 )
V_168 = V_190 ;
else if ( F_177 ( V_179 ) == - V_344 )
V_168 = V_203 ;
else if ( F_177 ( V_179 ) == - V_345 )
V_168 = V_204 ;
else
V_168 = V_346 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_327 ,
V_168 , & V_20 , sizeof( V_20 ) ) ;
goto V_206;
}
if ( V_179 -> V_330 ) {
F_165 ( V_179 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_327 ,
V_190 , & V_20 , sizeof( V_20 ) ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_327 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
F_165 ( V_179 ) ;
goto V_206;
}
V_126 -> V_200 = F_164 ;
if ( V_129 -> V_269 . type == V_270 ) {
V_179 -> V_330 = F_169 ;
V_179 -> V_331 = F_169 ;
V_179 -> V_332 = F_169 ;
} else {
V_179 -> V_330 = F_170 ;
V_179 -> V_331 = F_170 ;
V_179 -> V_332 = F_170 ;
}
V_179 -> V_324 = V_129 -> V_337 ;
V_126 -> V_328 = F_178 ( V_179 ) ;
if ( ( V_179 -> V_295 == V_347 || V_179 -> V_295 == V_348 ) &&
F_179 ( V_179 , V_335 , V_336 , true ) ) {
V_126 -> V_200 ( V_126 , 0 ) ;
F_97 ( V_126 ) ;
}
V_34 = 0 ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_180 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_202 * V_269 = V_7 ;
struct V_125 * V_126 ;
struct V_178 * V_179 ;
int V_34 ;
F_11 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_349 ,
V_214 ) ;
goto V_206;
}
V_126 = F_44 ( V_327 , V_6 ) ;
if ( ! V_126 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_349 ,
V_189 ) ;
goto V_206;
}
V_179 = V_126 -> V_328 ;
if ( F_29 ( & V_269 -> V_123 , & V_179 -> V_306 ) != 0 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_349 ,
V_189 ) ;
goto V_206;
}
V_126 -> V_200 ( V_126 , V_350 ) ;
F_97 ( V_126 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_349 , 0 ,
V_269 , sizeof( * V_269 ) ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_181 ( struct V_11 * V_25 , struct V_5 * V_6 ,
struct V_202 * V_269 , T_2 V_241 ,
T_2 V_351 , T_5 V_352 )
{
struct V_125 * V_126 ;
struct V_178 * V_179 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_241 ,
V_214 , V_269 ,
sizeof( * V_269 ) ) ;
goto V_284;
}
if ( V_269 -> type == V_270 )
V_179 = F_147 ( V_6 , V_282 , & V_269 -> V_123 ) ;
else
V_179 = F_151 ( V_6 , & V_269 -> V_123 ,
F_7 ( V_269 -> type ) ) ;
if ( ! V_179 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_241 ,
V_298 , V_269 ,
sizeof( * V_269 ) ) ;
goto V_284;
}
if ( V_269 -> type == V_15 || V_269 -> type == V_301 ) {
V_34 = F_182 ( V_179 , V_241 , V_352 ) ;
if ( ! V_34 )
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_241 ,
V_205 , V_269 ,
sizeof( * V_269 ) ) ;
else
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_241 ,
V_3 , V_269 ,
sizeof( * V_269 ) ) ;
goto V_284;
}
V_126 = F_88 ( V_25 , V_241 , V_6 , V_269 , sizeof( * V_269 ) ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_284;
}
V_126 -> V_200 = F_100 ;
if ( V_351 == V_353 ) {
struct V_354 V_129 ;
F_65 ( & V_129 . V_123 , & V_269 -> V_123 ) ;
V_129 . V_352 = V_352 ;
V_34 = F_115 ( V_6 , V_351 , sizeof( V_129 ) , & V_129 ) ;
} else
V_34 = F_115 ( V_6 , V_351 , sizeof( V_269 -> V_123 ) ,
& V_269 -> V_123 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_284:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_183 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_311 * V_129 = V_7 ;
F_11 ( L_4 ) ;
return F_181 ( V_25 , V_6 , & V_129 -> V_269 ,
V_312 ,
V_313 , 0 ) ;
}
static int F_184 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_355 * V_129 = V_7 ;
F_11 ( L_4 ) ;
if ( V_8 != sizeof( * V_129 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_356 ,
V_189 ) ;
return F_181 ( V_25 , V_6 , & V_129 -> V_269 ,
V_356 ,
V_357 , 0 ) ;
}
static int F_185 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_358 * V_129 = V_7 ;
F_11 ( L_4 ) ;
return F_181 ( V_25 , V_6 , & V_129 -> V_269 ,
V_359 ,
V_360 , 0 ) ;
}
static int F_186 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_361 * V_129 = V_7 ;
F_11 ( L_4 ) ;
return F_181 ( V_25 , V_6 , & V_129 -> V_269 ,
V_362 ,
V_353 , V_129 -> V_352 ) ;
}
static int F_187 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_363 * V_129 = V_7 ;
F_11 ( L_4 ) ;
return F_181 ( V_25 , V_6 , & V_129 -> V_269 ,
V_364 ,
V_365 , 0 ) ;
}
static void F_188 ( struct V_5 * V_6 , T_6 V_182 )
{
struct V_366 * V_367 ;
struct V_139 V_140 ;
int V_34 ;
V_367 = F_189 ( V_6 , V_6 -> V_368 ) ;
if ( ! V_367 )
return;
if ( ! ( V_367 -> V_182 & V_182 ) )
return;
F_78 ( V_6 ) ;
V_367 = F_190 ( V_6 , V_367 -> V_171 ) ;
if ( ! V_367 )
return;
F_53 ( & V_140 , V_6 ) ;
V_34 = F_191 ( & V_140 , V_367 -> V_171 ,
true ) ;
if ( V_34 )
return;
F_56 ( & V_140 , NULL ) ;
}
static void F_192 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
struct V_369 * V_129 ;
struct V_125 * V_126 ;
F_11 ( L_7 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_370 , V_6 ) ;
if ( ! V_126 )
goto V_206;
V_129 = V_126 -> V_130 ;
if ( V_168 ) {
F_87 ( V_126 -> V_25 , V_6 -> V_59 , V_370 ,
F_1 ( V_168 ) ) ;
} else {
F_12 ( V_126 -> V_25 , V_6 -> V_59 , V_370 , 0 ,
V_129 , sizeof( * V_129 ) ) ;
if ( F_21 ( V_6 , V_186 ) )
F_188 ( V_6 , V_371 ) ;
}
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_193 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_369 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
F_11 ( L_4 ) ;
F_35 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_148 , V_129 -> V_84 , sizeof( V_6 -> V_148 ) ) &&
! memcmp ( V_6 -> V_149 , V_129 -> V_149 ,
sizeof( V_6 -> V_149 ) ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_370 , 0 ,
V_7 , V_8 ) ;
goto V_191;
}
memcpy ( V_6 -> V_149 , V_129 -> V_149 , sizeof( V_6 -> V_149 ) ) ;
if ( ! F_43 ( V_6 ) ) {
memcpy ( V_6 -> V_148 , V_129 -> V_84 , sizeof( V_6 -> V_148 ) ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_370 , 0 ,
V_7 , V_8 ) ;
if ( V_34 < 0 )
goto V_191;
V_34 = F_5 ( V_372 , V_6 , V_7 ,
V_8 , V_163 , V_25 ) ;
F_70 ( V_6 , V_25 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_370 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
memcpy ( V_6 -> V_148 , V_129 -> V_84 , sizeof( V_6 -> V_148 ) ) ;
F_53 ( & V_140 , V_6 ) ;
if ( F_38 ( V_6 ) ) {
F_194 ( & V_140 ) ;
F_54 ( & V_140 ) ;
}
if ( F_41 ( V_6 ) && F_21 ( V_6 , V_118 ) )
F_122 ( & V_140 , V_6 -> V_368 ) ;
V_34 = F_56 ( & V_140 , F_192 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_195 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_373 * V_129 = V_7 ;
T_2 V_374 ;
int V_34 ;
F_11 ( L_4 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_375 ,
V_203 ) ;
V_374 = F_196 ( V_129 -> V_156 ) ;
F_35 ( V_6 ) ;
if ( V_6 -> V_156 != V_374 ) {
V_6 -> V_156 = V_374 ;
if ( F_21 ( V_6 , V_186 ) )
F_188 ( V_6 , V_376 ) ;
F_70 ( V_6 , V_25 ) ;
}
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_375 , 0 , NULL ,
0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_197 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 , struct V_377 * V_378 )
{
struct V_379 V_380 ;
T_3 V_32 = sizeof( V_380 ) ;
struct V_125 * V_126 ;
F_11 ( L_15 , V_6 -> V_84 , V_168 ) ;
V_126 = F_44 ( V_381 , V_6 ) ;
if ( ! V_126 )
return;
if ( V_168 || ! V_378 ) {
F_87 ( V_126 -> V_25 , V_6 -> V_59 , V_381 ,
V_168 ? F_1 ( V_168 ) : V_3 ) ;
goto remove;
}
memset ( & V_380 , 0 , sizeof( V_380 ) ) ;
if ( V_41 == V_382 ) {
struct V_383 * V_20 = ( void * ) V_378 -> V_7 ;
if ( V_378 -> V_8 < sizeof( * V_20 ) ) {
F_87 ( V_126 -> V_25 , V_6 -> V_59 ,
V_381 ,
V_3 ) ;
goto remove;
}
memcpy ( V_380 . V_384 , V_20 -> V_385 , sizeof( V_20 -> V_385 ) ) ;
memcpy ( V_380 . V_386 , V_20 -> rand , sizeof( V_20 -> rand ) ) ;
V_32 -= sizeof( V_380 . V_387 ) + sizeof( V_380 . V_388 ) ;
} else {
struct V_389 * V_20 = ( void * ) V_378 -> V_7 ;
if ( V_378 -> V_8 < sizeof( * V_20 ) ) {
F_87 ( V_126 -> V_25 , V_6 -> V_59 ,
V_381 ,
V_3 ) ;
goto remove;
}
memcpy ( V_380 . V_384 , V_20 -> V_384 , sizeof( V_20 -> V_384 ) ) ;
memcpy ( V_380 . V_386 , V_20 -> V_386 , sizeof( V_20 -> V_386 ) ) ;
memcpy ( V_380 . V_387 , V_20 -> V_387 , sizeof( V_20 -> V_387 ) ) ;
memcpy ( V_380 . V_388 , V_20 -> V_388 , sizeof( V_20 -> V_388 ) ) ;
}
F_12 ( V_126 -> V_25 , V_6 -> V_59 , V_381 ,
V_205 , & V_380 , V_32 ) ;
remove:
F_97 ( V_126 ) ;
}
static int F_198 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_381 ,
V_214 ) ;
goto V_206;
}
if ( ! F_39 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_381 ,
V_203 ) ;
goto V_206;
}
if ( F_44 ( V_381 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_381 ,
V_190 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_381 , V_6 , NULL , 0 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
if ( F_199 ( V_6 ) )
F_80 ( & V_140 , V_390 , 0 , NULL ) ;
else
F_80 ( & V_140 , V_382 , 0 , NULL ) ;
V_34 = F_200 ( & V_140 , F_197 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_201 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_202 * V_269 = V_7 ;
int V_34 ;
F_11 ( L_17 , V_6 -> V_84 ) ;
if ( ! F_146 ( V_269 -> type ) )
return F_12 ( V_25 , V_6 -> V_59 ,
V_391 ,
V_189 ,
V_269 , sizeof( * V_269 ) ) ;
F_35 ( V_6 ) ;
if ( V_8 == V_392 ) {
struct V_393 * V_129 = V_7 ;
T_1 V_168 ;
if ( V_129 -> V_269 . type != V_270 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_391 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
V_34 = F_202 ( V_6 , & V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type , V_129 -> V_385 ,
V_129 -> rand , NULL , NULL ) ;
if ( V_34 < 0 )
V_168 = V_3 ;
else
V_168 = V_205 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_391 , V_168 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
} else if ( V_8 == V_394 ) {
struct V_395 * V_129 = V_7 ;
T_1 * V_386 , * V_384 , * V_388 , * V_387 ;
T_1 V_168 ;
if ( F_203 ( V_129 -> V_269 . type ) ) {
if ( memcmp ( V_129 -> V_386 , V_396 , 16 ) ||
memcmp ( V_129 -> V_384 , V_396 , 16 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_391 ,
V_189 ,
V_269 , sizeof( * V_269 ) ) ;
goto V_206;
}
V_386 = NULL ;
V_384 = NULL ;
} else {
if ( ! memcmp ( V_129 -> V_386 , V_396 , 16 ) ||
! memcmp ( V_129 -> V_384 , V_396 , 16 ) ) {
V_386 = NULL ;
V_384 = NULL ;
} else {
V_386 = V_129 -> V_386 ;
V_384 = V_129 -> V_384 ;
}
}
if ( ! memcmp ( V_129 -> V_388 , V_396 , 16 ) ||
! memcmp ( V_129 -> V_387 , V_396 , 16 ) ) {
V_388 = NULL ;
V_387 = NULL ;
} else {
V_388 = V_129 -> V_388 ;
V_387 = V_129 -> V_387 ;
}
V_34 = F_202 ( V_6 , & V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type , V_384 , V_386 ,
V_387 , V_388 ) ;
if ( V_34 < 0 )
V_168 = V_3 ;
else
V_168 = V_205 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_391 ,
V_168 , & V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
} else {
F_141 ( L_18 , V_8 ) ;
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_391 ,
V_189 ) ;
}
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_204 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_397 * V_129 = V_7 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( V_129 -> V_269 . type != V_270 )
return F_12 ( V_25 , V_6 -> V_59 ,
V_398 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_29 ( & V_129 -> V_269 . V_123 , V_76 ) ) {
F_205 ( V_6 ) ;
V_168 = V_205 ;
goto V_284;
}
V_34 = F_206 ( V_6 , & V_129 -> V_269 . V_123 , V_129 -> V_269 . type ) ;
if ( V_34 < 0 )
V_168 = V_189 ;
else
V_168 = V_205 ;
V_284:
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_398 ,
V_168 , & V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
void F_207 ( struct V_5 * V_6 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_11 ( L_19 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_399 , V_6 ) ;
if ( ! V_126 )
V_126 = F_44 ( V_400 , V_6 ) ;
if ( ! V_126 )
V_126 = F_44 ( V_401 , V_6 ) ;
if ( V_126 ) {
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
F_36 ( V_6 ) ;
}
static bool F_208 ( struct V_5 * V_6 , T_8 type ,
T_8 * F_1 )
{
switch ( type ) {
case V_402 :
* F_1 = F_102 ( V_6 ) ;
if ( * F_1 )
return false ;
break;
case V_403 :
* F_1 = F_102 ( V_6 ) ;
if ( * F_1 )
return false ;
case V_404 :
* F_1 = F_101 ( V_6 ) ;
if ( * F_1 )
return false ;
break;
default:
* F_1 = V_189 ;
return false ;
}
return true ;
}
static int F_209 ( struct V_11 * V_25 , struct V_5 * V_6 ,
T_2 V_405 , void * V_7 , T_2 V_8 )
{
struct V_406 * V_129 = V_7 ;
struct V_125 * V_126 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_405 ,
V_214 ,
& V_129 -> type , sizeof( V_129 -> type ) ) ;
goto V_191;
}
if ( V_6 -> V_407 . V_295 != V_408 ||
F_21 ( V_6 , V_409 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_405 , V_190 ,
& V_129 -> type , sizeof( V_129 -> type ) ) ;
goto V_191;
}
if ( ! F_208 ( V_6 , V_129 -> type , & V_168 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_405 , V_168 ,
& V_129 -> type , sizeof( V_129 -> type ) ) ;
goto V_191;
}
F_210 ( V_6 ) ;
V_6 -> V_407 . type = V_129 -> type ;
V_6 -> V_407 . V_410 = false ;
if ( V_405 == V_401 )
V_6 -> V_407 . V_411 = true ;
else
V_6 -> V_407 . V_411 = false ;
V_126 = F_88 ( V_25 , V_405 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
V_126 -> V_200 = F_99 ;
F_85 ( V_6 , V_412 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_413 ) ;
V_34 = 0 ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_211 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
return F_209 ( V_25 , V_6 , V_399 ,
V_7 , V_8 ) ;
}
static int F_212 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
return F_209 ( V_25 , V_6 ,
V_401 ,
V_7 , V_8 ) ;
}
static int F_213 ( struct V_125 * V_126 ,
T_1 V_168 )
{
return F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_168 ,
V_126 -> V_130 , 1 ) ;
}
static int F_214 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_414 * V_129 = V_7 ;
struct V_125 * V_126 ;
const T_2 V_415 = ( ( V_261 - sizeof( * V_129 ) ) / 16 ) ;
T_2 V_416 , V_264 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_400 ,
V_214 ,
& V_129 -> type , sizeof( V_129 -> type ) ) ;
goto V_191;
}
if ( V_6 -> V_407 . V_295 != V_408 ||
F_21 ( V_6 , V_409 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_400 ,
V_190 , & V_129 -> type ,
sizeof( V_129 -> type ) ) ;
goto V_191;
}
V_416 = F_106 ( V_129 -> V_416 ) ;
if ( V_416 > V_415 ) {
F_141 ( L_20 ,
V_416 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_400 ,
V_189 , & V_129 -> type ,
sizeof( V_129 -> type ) ) ;
goto V_191;
}
V_264 = sizeof( * V_129 ) + V_416 * 16 ;
if ( V_264 != V_8 ) {
F_141 ( L_21 ,
V_264 , V_8 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_400 ,
V_189 , & V_129 -> type ,
sizeof( V_129 -> type ) ) ;
goto V_191;
}
if ( ! F_208 ( V_6 , V_129 -> type , & V_168 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_400 ,
V_168 , & V_129 -> type , sizeof( V_129 -> type ) ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_400 ,
V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
V_126 -> V_200 = F_213 ;
F_210 ( V_6 ) ;
V_6 -> V_407 . V_417 = true ;
V_6 -> V_407 . type = V_129 -> type ;
V_6 -> V_407 . V_418 = V_129 -> V_418 ;
V_6 -> V_407 . V_416 = V_416 ;
if ( V_416 > 0 ) {
V_6 -> V_407 . V_246 = F_215 ( V_129 -> V_246 , V_416 * 16 ,
V_39 ) ;
if ( ! V_6 -> V_407 . V_246 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_400 ,
V_3 ,
& V_129 -> type , sizeof( V_129 -> type ) ) ;
F_97 ( V_126 ) ;
goto V_191;
}
}
F_85 ( V_6 , V_412 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_413 ) ;
V_34 = 0 ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
void F_216 ( struct V_5 * V_6 , T_1 V_168 )
{
struct V_125 * V_126 ;
F_11 ( L_19 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_419 , V_6 ) ;
if ( V_126 ) {
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
F_36 ( V_6 ) ;
}
static int F_217 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_420 * V_421 = V_7 ;
struct V_125 * V_126 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( ! F_218 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_419 ,
V_204 , & V_421 -> type ,
sizeof( V_421 -> type ) ) ;
goto V_206;
}
if ( V_6 -> V_407 . type != V_421 -> type ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_419 ,
V_189 ,
& V_421 -> type , sizeof( V_421 -> type ) ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_419 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
V_126 -> V_200 = F_99 ;
F_85 ( V_6 , V_187 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_413 ) ;
V_34 = 0 ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_219 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_422 * V_129 = V_7 ;
struct V_423 * V_424 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( ! F_218 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_425 ,
V_3 , & V_129 -> V_269 ,
sizeof( V_129 -> V_269 ) ) ;
goto V_191;
}
V_424 = F_220 ( V_6 , & V_129 -> V_269 . V_123 ) ;
if ( ! V_424 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_425 ,
V_189 , & V_129 -> V_269 ,
sizeof( V_129 -> V_269 ) ) ;
goto V_191;
}
if ( V_129 -> V_426 ) {
V_424 -> V_427 = V_428 ;
F_93 ( & V_424 -> V_199 ) ;
} else {
V_424 -> V_427 = V_429 ;
F_221 ( V_6 , V_424 ) ;
}
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_425 , 0 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_222 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_430 * V_129 = V_7 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_146 ( V_129 -> V_269 . type ) )
return F_12 ( V_25 , V_6 -> V_59 , V_431 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_223 ( & V_6 -> V_432 , & V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type ) ;
if ( V_34 < 0 ) {
V_168 = V_3 ;
goto V_284;
}
F_6 ( V_433 , V_6 , & V_129 -> V_269 , sizeof( V_129 -> V_269 ) ,
V_25 ) ;
V_168 = V_205 ;
V_284:
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_431 , V_168 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_224 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_434 * V_129 = V_7 ;
T_1 V_168 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_146 ( V_129 -> V_269 . type ) )
return F_12 ( V_25 , V_6 -> V_59 , V_435 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_225 ( & V_6 -> V_432 , & V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type ) ;
if ( V_34 < 0 ) {
V_168 = V_189 ;
goto V_284;
}
F_6 ( V_436 , V_6 , & V_129 -> V_269 , sizeof( V_129 -> V_269 ) ,
V_25 ) ;
V_168 = V_205 ;
V_284:
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_435 , V_168 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_226 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_437 * V_129 = V_7 ;
struct V_139 V_140 ;
int V_34 ;
T_9 V_438 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
V_438 = F_106 ( V_129 -> V_438 ) ;
if ( V_438 > 0x0002 )
return F_87 ( V_25 , V_6 -> V_59 , V_439 ,
V_189 ) ;
F_35 ( V_6 ) ;
V_6 -> V_440 = V_438 ;
V_6 -> V_441 = F_106 ( V_129 -> V_442 ) ;
V_6 -> V_443 = F_106 ( V_129 -> V_444 ) ;
V_6 -> V_445 = F_106 ( V_129 -> V_21 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_439 , 0 ,
NULL , 0 ) ;
F_53 ( & V_140 , V_6 ) ;
F_54 ( & V_140 ) ;
F_56 ( & V_140 , NULL ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_227 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 )
{
F_11 ( L_19 , V_168 ) ;
}
static void F_228 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 )
{
struct V_197 V_198 = { NULL , V_6 } ;
struct V_139 V_140 ;
T_1 V_171 ;
struct V_366 * V_367 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
F_119 ( V_232 , V_6 ,
F_96 , & V_207 ) ;
goto V_206;
}
if ( F_21 ( V_6 , V_186 ) )
F_58 ( V_6 , V_118 ) ;
else
F_63 ( V_6 , V_118 ) ;
F_119 ( V_232 , V_6 , F_92 ,
& V_198 ) ;
F_90 ( V_6 , V_198 . V_25 ) ;
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
if ( F_21 ( V_6 , V_118 ) ||
F_229 ( & V_6 -> V_446 ) )
goto V_206;
V_171 = V_6 -> V_368 ;
if ( ! V_171 ) {
V_367 = F_230 ( & V_6 -> V_446 ,
struct V_366 , V_199 ) ;
if ( ! V_367 )
goto V_206;
V_171 = V_367 -> V_171 ;
}
F_53 ( & V_140 , V_6 ) ;
V_34 = F_191 ( & V_140 , V_171 , true ) ;
if ( ! V_34 )
V_34 = F_56 ( & V_140 , F_227 ) ;
if ( V_34 )
F_141 ( L_22 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_231 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
T_1 V_131 , V_168 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
V_168 = F_102 ( V_6 ) ;
if ( V_168 )
return F_87 ( V_25 , V_6 -> V_59 , V_232 ,
V_168 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 && V_129 -> V_131 != 0x02 )
return F_87 ( V_25 , V_6 -> V_59 , V_232 ,
V_189 ) ;
F_35 ( V_6 ) ;
V_131 = ! ! V_129 -> V_131 ;
if ( ! F_43 ( V_6 ) ||
( V_131 == F_21 ( V_6 , V_118 ) &&
( V_129 -> V_131 == 0x02 ) == F_21 ( V_6 , V_447 ) ) ||
F_232 ( V_6 , V_300 ) > 0 ||
( F_21 ( V_6 , V_448 ) &&
V_6 -> V_449 == V_450 ) ) {
bool V_215 ;
if ( V_129 -> V_131 ) {
V_6 -> V_368 = 0x00 ;
V_215 = ! F_61 ( V_6 , V_118 ) ;
if ( V_129 -> V_131 == 0x02 )
F_58 ( V_6 , V_447 ) ;
else
F_63 ( V_6 , V_447 ) ;
} else {
V_215 = F_52 ( V_6 , V_118 ) ;
F_63 ( V_6 , V_447 ) ;
}
V_34 = F_71 ( V_25 , V_232 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_206;
}
if ( F_44 ( V_232 , V_6 ) ||
F_44 ( V_228 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_232 ,
V_190 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_232 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
if ( V_129 -> V_131 == 0x02 )
F_58 ( V_6 , V_447 ) ;
else
F_63 ( V_6 , V_447 ) ;
F_78 ( V_6 ) ;
if ( V_131 ) {
V_6 -> V_368 = 0x00 ;
F_121 ( & V_140 , 0x00 ) ;
F_122 ( & V_140 , 0x00 ) ;
F_59 ( & V_140 ) ;
} else {
F_82 ( & V_140 ) ;
}
V_34 = F_56 ( & V_140 , F_228 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_233 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_451 * V_129 = V_7 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_452 ,
V_203 ) ;
if ( F_43 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_452 ,
V_204 ) ;
if ( F_29 ( & V_129 -> V_123 , V_76 ) ) {
if ( ! F_29 ( & V_129 -> V_123 , V_453 ) )
return F_87 ( V_25 , V_6 -> V_59 ,
V_452 ,
V_189 ) ;
if ( ( V_129 -> V_123 . V_454 [ 5 ] & 0xc0 ) != 0xc0 )
return F_87 ( V_25 , V_6 -> V_59 ,
V_452 ,
V_189 ) ;
}
F_35 ( V_6 ) ;
F_65 ( & V_6 -> V_124 , & V_129 -> V_123 ) ;
V_34 = F_71 ( V_25 , V_452 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
V_34 = F_90 ( V_6 , V_25 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_234 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_455 * V_129 = V_7 ;
T_9 V_456 , V_457 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_458 ,
V_203 ) ;
V_456 = F_106 ( V_129 -> V_456 ) ;
if ( V_456 < 0x0004 || V_456 > 0x4000 )
return F_87 ( V_25 , V_6 -> V_59 , V_458 ,
V_189 ) ;
V_457 = F_106 ( V_129 -> V_457 ) ;
if ( V_457 < 0x0004 || V_457 > 0x4000 )
return F_87 ( V_25 , V_6 -> V_59 , V_458 ,
V_189 ) ;
if ( V_457 > V_456 )
return F_87 ( V_25 , V_6 -> V_59 , V_458 ,
V_189 ) ;
F_35 ( V_6 ) ;
V_6 -> V_459 = V_456 ;
V_6 -> V_460 = V_457 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_458 , 0 ,
NULL , 0 ) ;
if ( F_21 ( V_6 , V_448 ) &&
V_6 -> V_407 . V_295 == V_408 ) {
struct V_139 V_140 ;
F_53 ( & V_140 , V_6 ) ;
F_235 ( & V_140 ) ;
F_236 ( & V_140 ) ;
F_56 ( & V_140 , NULL ) ;
}
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_237 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 )
{
struct V_125 * V_126 ;
F_11 ( L_7 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_461 , V_6 ) ;
if ( ! V_126 )
goto V_206;
if ( V_168 ) {
F_87 ( V_126 -> V_25 , V_6 -> V_59 , V_461 ,
F_1 ( V_168 ) ) ;
} else {
struct V_128 * V_129 = V_126 -> V_130 ;
if ( V_129 -> V_131 )
F_58 ( V_6 , V_110 ) ;
else
F_63 ( V_6 , V_110 ) ;
F_71 ( V_126 -> V_25 , V_461 , V_6 ) ;
F_90 ( V_6 , V_126 -> V_25 ) ;
}
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_238 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_21 ( V_6 , V_113 ) ||
V_6 -> V_96 < V_97 )
return F_87 ( V_25 , V_6 -> V_59 , V_461 ,
V_203 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_461 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( F_44 ( V_461 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_461 ,
V_190 ) ;
goto V_206;
}
if ( ! ! V_129 -> V_131 == F_21 ( V_6 , V_110 ) ) {
V_34 = F_71 ( V_25 , V_461 ,
V_6 ) ;
goto V_206;
}
if ( ! F_43 ( V_6 ) ) {
F_107 ( V_6 , V_110 ) ;
V_34 = F_71 ( V_25 , V_461 ,
V_6 ) ;
F_90 ( V_6 , V_25 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_461 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
F_239 ( & V_140 , V_129 -> V_131 ) ;
V_34 = F_56 ( & V_140 , F_237 ) ;
if ( V_34 < 0 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_461 ,
V_3 ) ;
F_97 ( V_126 ) ;
}
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_240 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
struct V_125 * V_126 ;
F_11 ( L_7 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_462 , V_6 ) ;
if ( ! V_126 )
goto V_206;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
F_63 ( V_6 , V_113 ) ;
F_87 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_207 ) ;
} else {
F_71 ( V_126 -> V_25 , V_462 , V_6 ) ;
F_90 ( V_6 , V_126 -> V_25 ) ;
}
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_241 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_38 ( V_6 ) || ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_462 ,
V_203 ) ;
if ( ! F_21 ( V_6 , V_114 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_462 ,
V_204 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_462 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( V_129 -> V_131 == F_21 ( V_6 , V_113 ) ) {
V_34 = F_71 ( V_25 , V_462 , V_6 ) ;
goto V_206;
}
if ( ! F_43 ( V_6 ) ) {
if ( ! V_129 -> V_131 ) {
F_63 ( V_6 , V_111 ) ;
F_63 ( V_6 , V_116 ) ;
F_63 ( V_6 , V_115 ) ;
F_63 ( V_6 , V_110 ) ;
F_63 ( V_6 , V_117 ) ;
}
F_107 ( V_6 , V_113 ) ;
V_34 = F_71 ( V_25 , V_462 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_206;
}
if ( ! V_129 -> V_131 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_462 ,
V_204 ) ;
goto V_206;
} else {
if ( ! F_21 ( V_6 , V_113 ) &&
( F_29 ( & V_6 -> V_124 , V_76 ) ||
F_21 ( V_6 , V_119 ) ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_462 ,
V_204 ) ;
goto V_206;
}
}
if ( F_44 ( V_462 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_462 ,
V_190 ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_462 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_58 ( V_6 , V_113 ) ;
F_53 ( & V_140 , V_6 ) ;
F_239 ( & V_140 , false ) ;
F_242 ( & V_140 ) ;
F_121 ( & V_140 , V_6 -> V_368 ) ;
V_34 = F_56 ( & V_140 , F_240 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_243 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
struct V_125 * V_126 ;
struct V_128 * V_129 ;
F_11 ( L_15 , V_6 -> V_84 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_463 , V_6 ) ;
if ( ! V_126 )
goto V_206;
if ( V_168 ) {
F_87 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 ,
F_1 ( V_168 ) ) ;
goto remove;
}
V_129 = V_126 -> V_130 ;
switch ( V_129 -> V_131 ) {
case 0x00 :
F_63 ( V_6 , V_119 ) ;
F_63 ( V_6 , V_464 ) ;
break;
case 0x01 :
F_58 ( V_6 , V_119 ) ;
F_63 ( V_6 , V_464 ) ;
break;
case 0x02 :
F_58 ( V_6 , V_119 ) ;
F_58 ( V_6 , V_464 ) ;
break;
}
F_71 ( V_126 -> V_25 , V_463 , V_6 ) ;
F_90 ( V_6 , V_126 -> V_25 ) ;
remove:
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_244 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
T_1 V_131 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_40 ( V_6 ) &&
! F_21 ( V_6 , V_114 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_463 ,
V_203 ) ;
if ( F_21 ( V_6 , V_113 ) &&
F_40 ( V_6 ) &&
! F_21 ( V_6 , V_116 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_463 ,
V_204 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 && V_129 -> V_131 != 0x02 )
return F_87 ( V_25 , V_6 -> V_59 , V_463 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) || ! F_40 ( V_6 ) ||
! F_21 ( V_6 , V_113 ) ) {
bool V_215 ;
if ( V_129 -> V_131 ) {
V_215 = ! F_61 ( V_6 ,
V_119 ) ;
if ( V_129 -> V_131 == 0x02 )
F_58 ( V_6 , V_464 ) ;
else
F_63 ( V_6 , V_464 ) ;
} else {
V_215 = F_52 ( V_6 ,
V_119 ) ;
F_63 ( V_6 , V_464 ) ;
}
V_34 = F_71 ( V_25 , V_463 , V_6 ) ;
if ( V_34 < 0 )
goto V_191;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
goto V_191;
}
if ( F_44 ( V_463 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_463 ,
V_190 ) ;
goto V_191;
}
V_131 = ! ! V_129 -> V_131 ;
if ( V_131 == F_21 ( V_6 , V_119 ) &&
( V_129 -> V_131 == 0x02 ) == F_21 ( V_6 , V_464 ) ) {
V_34 = F_71 ( V_25 , V_463 , V_6 ) ;
goto V_191;
}
V_126 = F_88 ( V_25 , V_463 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_191;
}
F_53 ( & V_140 , V_6 ) ;
F_80 ( & V_140 , V_465 , 1 , & V_131 ) ;
V_34 = F_56 ( & V_140 , F_243 ) ;
if ( V_34 < 0 ) {
F_97 ( V_126 ) ;
goto V_191;
}
V_191:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_245 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_128 * V_129 = V_7 ;
bool V_215 , V_466 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( V_129 -> V_131 != 0x00 && V_129 -> V_131 != 0x01 && V_129 -> V_131 != 0x02 )
return F_87 ( V_25 , V_6 -> V_59 , V_467 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( V_129 -> V_131 )
V_215 = ! F_61 ( V_6 , V_120 ) ;
else
V_215 = F_52 ( V_6 ,
V_120 ) ;
if ( V_129 -> V_131 == 0x02 )
V_466 = ! F_61 ( V_6 ,
V_224 ) ;
else
V_466 = F_52 ( V_6 ,
V_224 ) ;
if ( F_43 ( V_6 ) && V_466 &&
F_21 ( V_6 , V_116 ) ) {
T_1 V_468 = ( V_129 -> V_131 == 0x02 ) ? 0x01 : 0x00 ;
F_115 ( V_6 , V_225 ,
sizeof( V_468 ) , & V_468 ) ;
}
V_34 = F_71 ( V_25 , V_467 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_246 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_469 ,
T_2 V_8 )
{
struct V_470 * V_129 = V_469 ;
bool V_215 ;
int V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_471 ,
V_203 ) ;
if ( V_129 -> V_472 != 0x00 && V_129 -> V_472 != 0x01 && V_129 -> V_472 != 0x02 )
return F_87 ( V_25 , V_6 -> V_59 , V_471 ,
V_189 ) ;
if ( F_43 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_471 ,
V_204 ) ;
F_35 ( V_6 ) ;
F_58 ( V_6 , V_473 ) ;
if ( V_129 -> V_472 ) {
V_215 = ! F_61 ( V_6 , V_121 ) ;
memcpy ( V_6 -> V_474 , V_129 -> V_474 , sizeof( V_6 -> V_474 ) ) ;
F_58 ( V_6 , V_142 ) ;
if ( V_129 -> V_472 == 0x02 )
F_58 ( V_6 , V_219 ) ;
else
F_63 ( V_6 , V_219 ) ;
} else {
V_215 = F_52 ( V_6 , V_121 ) ;
memset ( V_6 -> V_474 , 0 , sizeof( V_6 -> V_474 ) ) ;
F_63 ( V_6 , V_142 ) ;
F_63 ( V_6 , V_219 ) ;
}
V_34 = F_71 ( V_25 , V_471 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( V_215 )
V_34 = F_90 ( V_6 , V_25 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_247 ( struct V_475 * V_474 )
{
switch ( V_474 -> V_269 . type ) {
case V_15 :
return true ;
case V_301 :
if ( ( V_474 -> V_269 . V_123 . V_454 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_248 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_469 ,
T_2 V_8 )
{
struct V_476 * V_129 = V_469 ;
const T_2 V_477 = ( ( V_261 - sizeof( * V_129 ) ) /
sizeof( struct V_475 ) ) ;
T_2 V_478 , V_264 ;
int V_33 , V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_479 ,
V_203 ) ;
V_478 = F_106 ( V_129 -> V_478 ) ;
if ( V_478 > V_477 ) {
F_141 ( L_23 , V_478 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_479 ,
V_189 ) ;
}
V_264 = sizeof( * V_129 ) + V_478 * sizeof( struct V_475 ) ;
if ( V_264 != V_8 ) {
F_141 ( L_24 ,
V_264 , V_8 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_479 ,
V_189 ) ;
}
F_11 ( L_25 , V_6 -> V_84 , V_478 ) ;
for ( V_33 = 0 ; V_33 < V_478 ; V_33 ++ ) {
struct V_475 * V_267 = & V_129 -> V_480 [ V_33 ] ;
if ( ! F_247 ( V_267 ) )
return F_87 ( V_25 , V_6 -> V_59 ,
V_479 ,
V_189 ) ;
}
F_35 ( V_6 ) ;
F_249 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_478 ; V_33 ++ ) {
struct V_475 * V_474 = & V_129 -> V_480 [ V_33 ] ;
F_250 ( V_6 , & V_474 -> V_269 . V_123 ,
F_7 ( V_474 -> V_269 . type ) , V_474 -> V_131 ,
V_76 ) ;
}
F_58 ( V_6 , V_473 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_479 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_251 ( struct V_481 * V_267 )
{
if ( V_267 -> V_482 != 0x00 && V_267 -> V_482 != 0x01 )
return false ;
switch ( V_267 -> V_269 . type ) {
case V_15 :
return true ;
case V_301 :
if ( ( V_267 -> V_269 . V_123 . V_454 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_252 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_469 , T_2 V_8 )
{
struct V_483 * V_129 = V_469 ;
const T_2 V_260 = ( ( V_261 - sizeof( * V_129 ) ) /
sizeof( struct V_481 ) ) ;
T_2 V_263 , V_264 ;
int V_33 , V_34 ;
F_11 ( L_6 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_484 ,
V_203 ) ;
V_263 = F_106 ( V_129 -> V_263 ) ;
if ( V_263 > V_260 ) {
F_141 ( L_26 , V_263 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_484 ,
V_189 ) ;
}
V_264 = sizeof( * V_129 ) + V_263 *
sizeof( struct V_481 ) ;
if ( V_264 != V_8 ) {
F_141 ( L_27 ,
V_264 , V_8 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_484 ,
V_189 ) ;
}
F_11 ( L_28 , V_6 -> V_84 , V_263 ) ;
for ( V_33 = 0 ; V_33 < V_263 ; V_33 ++ ) {
struct V_481 * V_267 = & V_129 -> V_268 [ V_33 ] ;
if ( ! F_251 ( V_267 ) )
return F_87 ( V_25 , V_6 -> V_59 ,
V_484 ,
V_189 ) ;
}
F_35 ( V_6 ) ;
F_253 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_263 ; V_33 ++ ) {
struct V_481 * V_267 = & V_129 -> V_268 [ V_33 ] ;
T_1 type , V_485 ;
switch ( V_267 -> type ) {
case V_486 :
V_485 = 0x00 ;
type = V_267 -> V_482 ? V_487 : V_488 ;
break;
case V_489 :
V_485 = 0x01 ;
type = V_267 -> V_482 ? V_487 : V_488 ;
break;
case V_490 :
V_485 = 0x00 ;
type = V_491 ;
break;
case V_492 :
V_485 = 0x01 ;
type = V_491 ;
break;
case V_493 :
V_485 = 0x00 ;
type = V_494 ;
default:
continue;
}
F_254 ( V_6 , & V_267 -> V_269 . V_123 ,
F_7 ( V_267 -> V_269 . type ) , type , V_485 ,
V_267 -> V_131 , V_267 -> V_495 , V_267 -> V_496 , V_267 -> rand ) ;
}
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_484 , 0 ,
NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_255 ( struct V_125 * V_126 , T_1 V_168 )
{
struct V_178 * V_179 = V_126 -> V_328 ;
struct V_497 V_20 ;
int V_34 ;
memcpy ( & V_20 . V_269 , V_126 -> V_130 , sizeof( V_20 . V_269 ) ) ;
if ( V_168 == V_205 ) {
V_20 . V_418 = V_179 -> V_418 ;
V_20 . V_498 = V_179 -> V_498 ;
V_20 . V_499 = V_179 -> V_499 ;
} else {
V_20 . V_418 = V_500 ;
V_20 . V_498 = V_501 ;
V_20 . V_499 = V_501 ;
}
V_34 = F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_502 ,
V_168 , & V_20 , sizeof( V_20 ) ) ;
F_165 ( V_179 ) ;
F_167 ( V_179 ) ;
return V_34 ;
}
static void F_256 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_41 )
{
struct V_503 * V_129 ;
struct V_125 * V_126 ;
struct V_178 * V_179 ;
T_2 V_504 ;
T_1 V_168 ;
F_11 ( L_7 , V_1 ) ;
F_35 ( V_6 ) ;
V_129 = F_257 ( V_6 , V_505 ) ;
if ( ! V_129 ) {
V_129 = F_257 ( V_6 , V_506 ) ;
V_168 = V_205 ;
} else {
V_168 = F_1 ( V_1 ) ;
}
if ( ! V_129 ) {
F_141 ( L_29 ) ;
goto V_206;
}
V_504 = F_106 ( V_129 -> V_504 ) ;
V_179 = F_258 ( V_6 , V_504 ) ;
if ( ! V_179 ) {
F_141 ( L_30 , V_504 ) ;
goto V_206;
}
V_126 = F_46 ( V_502 , V_6 , V_179 ) ;
if ( ! V_126 )
goto V_206;
V_126 -> V_200 ( V_126 , V_168 ) ;
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_259 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_507 * V_129 = V_7 ;
struct V_497 V_20 ;
struct V_178 * V_179 ;
unsigned long V_508 ;
int V_34 = 0 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_65 ( & V_20 . V_269 . V_123 , & V_129 -> V_269 . V_123 ) ;
V_20 . V_269 . type = V_129 -> V_269 . type ;
if ( ! F_146 ( V_129 -> V_269 . type ) )
return F_12 ( V_25 , V_6 -> V_59 , V_502 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_502 ,
V_214 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
if ( V_129 -> V_269 . type == V_270 )
V_179 = F_147 ( V_6 , V_282 ,
& V_129 -> V_269 . V_123 ) ;
else
V_179 = F_147 ( V_6 , V_300 , & V_129 -> V_269 . V_123 ) ;
if ( ! V_179 || V_179 -> V_295 != V_347 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_502 ,
V_298 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
if ( F_46 ( V_502 , V_6 , V_179 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_502 ,
V_190 , & V_20 , sizeof( V_20 ) ) ;
goto V_206;
}
V_508 = V_6 -> V_509 +
F_260 ( V_6 -> V_510 -
V_6 -> V_509 ) ;
if ( F_261 ( V_511 , V_179 -> V_512 +
F_104 ( V_508 ) ) ||
! V_179 -> V_512 ) {
struct V_139 V_140 ;
struct V_513 V_514 ;
struct V_503 V_515 ;
struct V_125 * V_126 ;
F_53 ( & V_140 , V_6 ) ;
V_515 . V_504 = F_9 ( V_179 -> V_504 ) ;
F_80 ( & V_140 , V_505 , sizeof( V_515 ) ,
& V_515 ) ;
if ( ! F_203 ( V_129 -> V_269 . type ) ||
V_179 -> V_498 == V_501 ) {
V_514 . V_504 = F_9 ( V_179 -> V_504 ) ;
V_514 . type = 0x00 ;
F_80 ( & V_140 , V_506 ,
sizeof( V_514 ) , & V_514 ) ;
}
if ( V_179 -> V_499 == V_501 ) {
V_514 . V_504 = F_9 ( V_179 -> V_504 ) ;
V_514 . type = 0x01 ;
F_80 ( & V_140 , V_506 ,
sizeof( V_514 ) , & V_514 ) ;
}
V_34 = F_56 ( & V_140 , F_256 ) ;
if ( V_34 < 0 )
goto V_206;
V_126 = F_88 ( V_25 , V_502 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_262 ( V_179 ) ;
V_126 -> V_328 = F_178 ( V_179 ) ;
V_126 -> V_200 = F_255 ;
V_179 -> V_512 = V_511 ;
} else {
V_20 . V_418 = V_179 -> V_418 ;
V_20 . V_498 = V_179 -> V_498 ;
V_20 . V_499 = V_179 -> V_499 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_502 ,
V_205 , & V_20 , sizeof( V_20 ) ) ;
}
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_263 ( struct V_125 * V_126 , T_1 V_168 )
{
struct V_178 * V_179 = V_126 -> V_328 ;
struct V_516 V_20 ;
struct V_5 * V_6 ;
int V_34 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memcpy ( & V_20 . V_269 , V_126 -> V_130 , sizeof( V_20 . V_269 ) ) ;
if ( V_168 )
goto V_333;
V_6 = F_264 ( V_126 -> V_58 ) ;
if ( V_6 ) {
V_20 . V_517 = F_31 ( V_6 -> clock ) ;
F_265 ( V_6 ) ;
}
if ( V_179 ) {
V_20 . V_518 = F_31 ( V_179 -> clock ) ;
V_20 . V_519 = F_9 ( V_179 -> V_520 ) ;
}
V_333:
V_34 = F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_168 , & V_20 ,
sizeof( V_20 ) ) ;
if ( V_179 ) {
F_165 ( V_179 ) ;
F_167 ( V_179 ) ;
}
return V_34 ;
}
static void F_266 ( struct V_5 * V_6 , T_1 V_168 , T_2 V_41 )
{
struct V_521 * V_230 ;
struct V_125 * V_126 ;
struct V_178 * V_179 ;
F_11 ( L_15 , V_6 -> V_84 , V_168 ) ;
F_35 ( V_6 ) ;
V_230 = F_257 ( V_6 , V_522 ) ;
if ( ! V_230 )
goto V_206;
if ( V_230 -> V_523 ) {
T_2 V_504 = F_106 ( V_230 -> V_504 ) ;
V_179 = F_258 ( V_6 , V_504 ) ;
} else {
V_179 = NULL ;
}
V_126 = F_46 ( V_524 , V_6 , V_179 ) ;
if ( ! V_126 )
goto V_206;
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_267 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_525 * V_129 = V_7 ;
struct V_516 V_20 ;
struct V_521 V_230 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
struct V_178 * V_179 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_65 ( & V_20 . V_269 . V_123 , & V_129 -> V_269 . V_123 ) ;
V_20 . V_269 . type = V_129 -> V_269 . type ;
if ( V_129 -> V_269 . type != V_270 )
return F_12 ( V_25 , V_6 -> V_59 , V_524 ,
V_189 ,
& V_20 , sizeof( V_20 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_524 ,
V_214 , & V_20 ,
sizeof( V_20 ) ) ;
goto V_206;
}
if ( F_29 ( & V_129 -> V_269 . V_123 , V_76 ) ) {
V_179 = F_147 ( V_6 , V_282 ,
& V_129 -> V_269 . V_123 ) ;
if ( ! V_179 || V_179 -> V_295 != V_347 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_524 ,
V_298 ,
& V_20 , sizeof( V_20 ) ) ;
goto V_206;
}
} else {
V_179 = NULL ;
}
V_126 = F_88 ( V_25 , V_524 , V_6 , V_7 , V_8 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
V_126 -> V_200 = F_263 ;
F_53 ( & V_140 , V_6 ) ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
F_80 ( & V_140 , V_522 , sizeof( V_230 ) , & V_230 ) ;
if ( V_179 ) {
F_262 ( V_179 ) ;
V_126 -> V_328 = F_178 ( V_179 ) ;
V_230 . V_504 = F_9 ( V_179 -> V_504 ) ;
V_230 . V_523 = 0x01 ;
F_80 ( & V_140 , V_522 , sizeof( V_230 ) , & V_230 ) ;
}
V_34 = F_56 ( & V_140 , F_266 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_268 ( struct V_5 * V_6 , T_7 * V_269 , T_1 type )
{
struct V_178 * V_179 ;
V_179 = F_147 ( V_6 , V_300 , V_269 ) ;
if ( ! V_179 )
return false ;
if ( V_179 -> V_307 != type )
return false ;
if ( V_179 -> V_295 != V_347 )
return false ;
return true ;
}
static int F_269 ( struct V_5 * V_6 , T_7 * V_269 ,
T_1 V_273 , T_1 V_287 )
{
struct V_278 * V_279 ;
V_279 = F_174 ( V_6 , V_269 , V_273 ) ;
if ( ! V_279 )
return - V_526 ;
if ( V_279 -> V_287 == V_287 )
return 0 ;
F_270 ( & V_279 -> V_527 ) ;
switch ( V_287 ) {
case V_289 :
case V_528 :
if ( V_279 -> V_286 )
F_271 ( & V_279 -> V_527 , & V_6 -> V_529 ) ;
break;
case V_530 :
if ( V_279 -> V_286 )
F_271 ( & V_279 -> V_527 , & V_6 -> V_529 ) ;
else
F_271 ( & V_279 -> V_527 , & V_6 -> V_531 ) ;
break;
case V_532 :
case V_533 :
if ( ! F_268 ( V_6 , V_269 , V_273 ) )
F_271 ( & V_279 -> V_527 , & V_6 -> V_529 ) ;
break;
}
V_279 -> V_287 = V_287 ;
F_11 ( L_31 , V_269 , V_273 ,
V_287 ) ;
return 0 ;
}
static void F_272 ( struct V_11 * V_25 , struct V_5 * V_6 ,
T_7 * V_123 , T_1 type , T_1 V_527 )
{
struct V_534 V_166 ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = type ;
V_166 . V_527 = V_527 ;
F_6 ( V_535 , V_6 , & V_166 , sizeof( V_166 ) , V_25 ) ;
}
static int F_273 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_536 * V_129 = V_7 ;
T_1 V_537 , V_273 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_146 ( V_129 -> V_269 . type ) ||
! F_29 ( & V_129 -> V_269 . V_123 , V_76 ) )
return F_12 ( V_25 , V_6 -> V_59 , V_538 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
if ( V_129 -> V_527 != 0x00 && V_129 -> V_527 != 0x01 && V_129 -> V_527 != 0x02 )
return F_12 ( V_25 , V_6 -> V_59 , V_538 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
F_35 ( V_6 ) ;
if ( V_129 -> V_269 . type == V_270 ) {
if ( V_129 -> V_527 != 0x01 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_538 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
V_34 = F_223 ( & V_6 -> V_539 , & V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type ) ;
if ( V_34 )
goto V_206;
F_110 ( V_6 ) ;
goto V_540;
}
V_273 = F_7 ( V_129 -> V_269 . type ) ;
if ( V_129 -> V_527 == 0x02 )
V_537 = V_533 ;
else if ( V_129 -> V_527 == 0x01 )
V_537 = V_532 ;
else
V_537 = V_530 ;
if ( ! F_274 ( & V_129 -> V_269 . V_123 , V_273 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_538 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
if ( F_269 ( V_6 , & V_129 -> V_269 . V_123 , V_273 ,
V_537 ) < 0 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_538 ,
V_3 , & V_129 -> V_269 ,
sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
F_111 ( V_6 ) ;
V_540:
F_272 ( V_25 , V_6 , & V_129 -> V_269 . V_123 , V_129 -> V_269 . type , V_129 -> V_527 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_538 ,
V_205 , & V_129 -> V_269 ,
sizeof( V_129 -> V_269 ) ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_275 ( struct V_11 * V_25 , struct V_5 * V_6 ,
T_7 * V_123 , T_1 type )
{
struct V_541 V_166 ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = type ;
F_6 ( V_542 , V_6 , & V_166 , sizeof( V_166 ) , V_25 ) ;
}
static int F_276 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_543 * V_129 = V_7 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( F_29 ( & V_129 -> V_269 . V_123 , V_76 ) ) {
struct V_278 * V_279 ;
T_1 V_273 ;
if ( ! F_146 ( V_129 -> V_269 . type ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_544 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
if ( V_129 -> V_269 . type == V_270 ) {
V_34 = F_225 ( & V_6 -> V_539 ,
& V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type ) ;
if ( V_34 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_544 ,
V_189 ,
& V_129 -> V_269 ,
sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
F_110 ( V_6 ) ;
F_275 ( V_25 , V_6 , & V_129 -> V_269 . V_123 ,
V_129 -> V_269 . type ) ;
goto V_333;
}
V_273 = F_7 ( V_129 -> V_269 . type ) ;
if ( ! F_274 ( & V_129 -> V_269 . V_123 , V_273 ) ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_544 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
V_279 = F_155 ( V_6 , & V_129 -> V_269 . V_123 ,
V_273 ) ;
if ( ! V_279 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_544 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
if ( V_279 -> V_287 == V_289 ||
V_279 -> V_287 == V_288 ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_544 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
F_93 ( & V_279 -> V_527 ) ;
F_93 ( & V_279 -> V_199 ) ;
F_17 ( V_279 ) ;
F_111 ( V_6 ) ;
F_275 ( V_25 , V_6 , & V_129 -> V_269 . V_123 , V_129 -> V_269 . type ) ;
} else {
struct V_278 * V_341 , * V_250 ;
struct V_545 * V_454 , * V_546 ;
if ( V_129 -> V_269 . type ) {
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_544 ,
V_189 ,
& V_129 -> V_269 , sizeof( V_129 -> V_269 ) ) ;
goto V_206;
}
F_136 (b, btmp, &hdev->whitelist, list) {
F_275 ( V_25 , V_6 , & V_454 -> V_123 , V_454 -> V_547 ) ;
F_93 ( & V_454 -> V_199 ) ;
F_17 ( V_454 ) ;
}
F_110 ( V_6 ) ;
F_136 (p, tmp, &hdev->le_conn_params, list) {
if ( V_341 -> V_287 == V_289 )
continue;
F_275 ( V_25 , V_6 , & V_341 -> V_269 , V_341 -> V_273 ) ;
if ( V_341 -> V_286 ) {
V_341 -> V_287 = V_288 ;
continue;
}
F_93 ( & V_341 -> V_527 ) ;
F_93 ( & V_341 -> V_199 ) ;
F_17 ( V_341 ) ;
}
F_11 ( L_32 ) ;
F_111 ( V_6 ) ;
}
V_333:
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_544 ,
V_205 , & V_129 -> V_269 ,
sizeof( V_129 -> V_269 ) ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_277 ( struct V_11 * V_25 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_548 * V_129 = V_7 ;
const T_2 V_549 = ( ( V_261 - sizeof( * V_129 ) ) /
sizeof( struct V_550 ) ) ;
T_2 V_551 , V_264 ;
int V_33 ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_552 ,
V_203 ) ;
V_551 = F_106 ( V_129 -> V_551 ) ;
if ( V_551 > V_549 ) {
F_141 ( L_33 ,
V_551 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_552 ,
V_189 ) ;
}
V_264 = sizeof( * V_129 ) + V_551 *
sizeof( struct V_550 ) ;
if ( V_264 != V_8 ) {
F_141 ( L_34 ,
V_264 , V_8 ) ;
return F_87 ( V_25 , V_6 -> V_59 , V_552 ,
V_189 ) ;
}
F_11 ( L_35 , V_6 -> V_84 , V_551 ) ;
F_35 ( V_6 ) ;
F_278 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_551 ; V_33 ++ ) {
struct V_550 * V_130 = & V_129 -> V_279 [ V_33 ] ;
struct V_278 * V_553 ;
T_2 V_554 , V_555 , V_556 , V_213 ;
T_1 V_273 ;
F_11 ( L_36 , & V_130 -> V_269 . V_123 ,
V_130 -> V_269 . type ) ;
if ( V_130 -> V_269 . type == V_15 ) {
V_273 = V_16 ;
} else if ( V_130 -> V_269 . type == V_301 ) {
V_273 = V_17 ;
} else {
F_141 ( L_37 ) ;
continue;
}
V_554 = F_196 ( V_130 -> V_557 ) ;
V_555 = F_196 ( V_130 -> V_558 ) ;
V_556 = F_196 ( V_130 -> V_556 ) ;
V_213 = F_196 ( V_130 -> V_213 ) ;
F_11 ( L_38 ,
V_554 , V_555 , V_556 , V_213 ) ;
if ( F_279 ( V_554 , V_555 , V_556 , V_213 ) < 0 ) {
F_141 ( L_37 ) ;
continue;
}
V_553 = F_174 ( V_6 , & V_130 -> V_269 . V_123 ,
V_273 ) ;
if ( ! V_553 ) {
F_141 ( L_39 ) ;
continue;
}
V_553 -> V_559 = V_554 ;
V_553 -> V_560 = V_555 ;
V_553 -> V_561 = V_556 ;
V_553 -> V_562 = V_213 ;
}
F_36 ( V_6 ) ;
return F_12 ( V_25 , V_6 -> V_59 , V_552 , 0 ,
NULL , 0 ) ;
}
static int F_280 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_563 * V_129 = V_7 ;
bool V_215 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( F_43 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_564 ,
V_204 ) ;
if ( V_129 -> V_565 != 0x00 && V_129 -> V_565 != 0x01 )
return F_87 ( V_25 , V_6 -> V_59 , V_564 ,
V_189 ) ;
if ( ! F_23 ( V_72 , & V_6 -> V_57 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_564 ,
V_203 ) ;
F_35 ( V_6 ) ;
if ( V_129 -> V_565 )
V_215 = ! F_61 ( V_6 , V_73 ) ;
else
V_215 = F_52 ( V_6 , V_73 ) ;
V_34 = F_33 ( V_25 , V_564 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( ! V_215 )
goto V_206;
V_34 = F_32 ( V_6 , V_25 ) ;
if ( F_21 ( V_6 , V_51 ) == F_28 ( V_6 ) ) {
F_281 ( V_6 ) ;
if ( F_282 ( V_6 , V_51 ) ) {
F_58 ( V_6 , V_54 ) ;
F_58 ( V_6 , V_566 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_192 ) ;
} else {
F_154 ( V_567 , & V_6 -> V_182 ) ;
F_283 ( V_6 ) ;
}
}
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_284 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_568 * V_129 = V_7 ;
bool V_215 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( F_43 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_569 ,
V_204 ) ;
if ( ! F_29 ( & V_129 -> V_123 , V_76 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_569 ,
V_189 ) ;
if ( ! V_6 -> V_86 )
return F_87 ( V_25 , V_6 -> V_59 , V_569 ,
V_203 ) ;
F_35 ( V_6 ) ;
V_215 = ! ! F_29 ( & V_6 -> V_75 , & V_129 -> V_123 ) ;
F_65 ( & V_6 -> V_75 , & V_129 -> V_123 ) ;
V_34 = F_33 ( V_25 , V_569 , V_6 ) ;
if ( V_34 < 0 )
goto V_206;
if ( ! V_215 )
goto V_206;
if ( F_21 ( V_6 , V_51 ) )
V_34 = F_32 ( V_6 , V_25 ) ;
if ( F_28 ( V_6 ) ) {
F_281 ( V_6 ) ;
F_63 ( V_6 , V_51 ) ;
F_58 ( V_6 , V_54 ) ;
F_58 ( V_6 , V_566 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_192 ) ;
}
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_285 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 , struct V_377 * V_378 )
{
const struct V_570 * V_421 ;
struct V_571 * V_380 ;
T_1 * V_572 , * V_573 , * V_574 , * V_575 ;
struct V_125 * V_126 ;
T_2 V_152 ;
int V_34 ;
F_11 ( L_15 , V_6 -> V_84 , V_168 ) ;
V_126 = F_44 ( V_576 , V_6 ) ;
if ( ! V_126 )
return;
V_421 = V_126 -> V_130 ;
if ( V_168 ) {
V_168 = F_1 ( V_168 ) ;
V_152 = 0 ;
V_572 = NULL ;
V_573 = NULL ;
V_574 = NULL ;
V_575 = NULL ;
} else if ( V_41 == V_382 ) {
struct V_383 * V_20 ;
if ( V_378 -> V_8 != sizeof( * V_20 ) ) {
V_168 = V_3 ;
V_152 = 0 ;
} else {
V_168 = V_205 ;
V_20 = ( void * ) V_378 -> V_7 ;
V_152 = 5 + 18 + 18 ;
V_572 = V_20 -> V_385 ;
V_573 = V_20 -> rand ;
V_574 = NULL ;
V_575 = NULL ;
}
} else {
struct V_389 * V_20 ;
if ( V_378 -> V_8 != sizeof( * V_20 ) ) {
V_168 = V_3 ;
V_152 = 0 ;
} else {
V_168 = V_205 ;
V_20 = ( void * ) V_378 -> V_7 ;
if ( F_21 ( V_6 , V_464 ) ) {
V_152 = 5 + 18 + 18 ;
V_572 = NULL ;
V_573 = NULL ;
} else {
V_152 = 5 + 18 + 18 + 18 + 18 ;
V_572 = V_20 -> V_384 ;
V_573 = V_20 -> V_386 ;
}
V_574 = V_20 -> V_387 ;
V_575 = V_20 -> V_388 ;
}
}
V_380 = F_15 ( sizeof( * V_380 ) + V_152 , V_39 ) ;
if ( ! V_380 )
goto V_284;
if ( V_168 )
goto V_577;
V_152 = F_67 ( V_380 -> V_151 , 0 , V_154 ,
V_6 -> V_147 , 3 ) ;
if ( V_572 && V_573 ) {
V_152 = F_67 ( V_380 -> V_151 , V_152 ,
V_578 , V_572 , 16 ) ;
V_152 = F_67 ( V_380 -> V_151 , V_152 ,
V_579 , V_573 , 16 ) ;
}
if ( V_574 && V_575 ) {
V_152 = F_67 ( V_380 -> V_151 , V_152 ,
V_580 , V_574 , 16 ) ;
V_152 = F_67 ( V_380 -> V_151 , V_152 ,
V_581 , V_575 , 16 ) ;
}
V_577:
V_380 -> type = V_421 -> type ;
V_380 -> V_152 = F_9 ( V_152 ) ;
V_34 = F_12 ( V_126 -> V_25 , V_6 -> V_59 ,
V_576 , V_168 ,
V_380 , sizeof( * V_380 ) + V_152 ) ;
if ( V_34 < 0 || V_168 )
goto V_284;
F_26 ( V_126 -> V_25 , V_582 ) ;
V_34 = F_5 ( V_583 , V_6 ,
V_380 , sizeof( * V_380 ) + V_152 ,
V_582 , V_126 -> V_25 ) ;
V_284:
F_17 ( V_380 ) ;
F_97 ( V_126 ) ;
}
static int F_286 ( struct V_5 * V_6 , struct V_11 * V_25 ,
struct V_570 * V_129 )
{
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
V_126 = F_88 ( V_25 , V_576 , V_6 ,
V_129 , sizeof( * V_129 ) ) ;
if ( ! V_126 )
return - V_40 ;
F_53 ( & V_140 , V_6 ) ;
if ( F_199 ( V_6 ) )
F_80 ( & V_140 , V_390 , 0 , NULL ) ;
else
F_80 ( & V_140 , V_382 , 0 , NULL ) ;
V_34 = F_200 ( & V_140 , F_285 ) ;
if ( V_34 < 0 ) {
F_97 ( V_126 ) ;
return V_34 ;
}
return 0 ;
}
static int F_287 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_570 * V_129 = V_7 ;
struct V_571 * V_20 ;
T_3 V_46 ;
T_2 V_152 ;
T_1 V_168 , V_182 , V_584 , V_269 [ 7 ] , V_385 [ 16 ] , rand [ 16 ] ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( F_43 ( V_6 ) ) {
switch ( V_129 -> type ) {
case F_288 ( V_270 ) :
V_168 = F_101 ( V_6 ) ;
if ( V_168 )
V_152 = 0 ;
else
V_152 = 5 ;
break;
case ( F_288 ( V_15 ) | F_288 ( V_301 ) ) :
V_168 = F_102 ( V_6 ) ;
if ( V_168 )
V_152 = 0 ;
else
V_152 = 9 + 3 + 18 + 18 + 3 ;
break;
default:
V_168 = V_189 ;
V_152 = 0 ;
break;
}
} else {
V_168 = V_214 ;
V_152 = 0 ;
}
V_46 = sizeof( * V_20 ) + V_152 ;
V_20 = F_15 ( V_46 , V_52 ) ;
if ( ! V_20 )
return - V_40 ;
if ( V_168 )
goto V_333;
F_35 ( V_6 ) ;
V_152 = 0 ;
switch ( V_129 -> type ) {
case F_288 ( V_270 ) :
if ( F_21 ( V_6 , V_116 ) ) {
V_34 = F_286 ( V_6 , V_25 , V_129 ) ;
F_36 ( V_6 ) ;
if ( ! V_34 )
goto V_284;
V_168 = V_3 ;
goto V_333;
} else {
V_152 = F_67 ( V_20 -> V_151 , V_152 ,
V_154 ,
V_6 -> V_147 , 3 ) ;
}
break;
case ( F_288 ( V_15 ) | F_288 ( V_301 ) ) :
if ( F_21 ( V_6 , V_119 ) &&
F_289 ( V_6 , V_385 , rand ) < 0 ) {
F_36 ( V_6 ) ;
V_168 = V_3 ;
goto V_333;
}
if ( F_21 ( V_6 , V_121 ) ) {
F_36 ( V_6 ) ;
V_168 = V_204 ;
goto V_333;
}
if ( F_21 ( V_6 , V_122 ) ||
! F_29 ( & V_6 -> V_123 , V_76 ) ||
( ! F_21 ( V_6 , V_113 ) &&
F_29 ( & V_6 -> V_124 , V_76 ) ) ) {
memcpy ( V_269 , & V_6 -> V_124 , 6 ) ;
V_269 [ 6 ] = 0x01 ;
} else {
memcpy ( V_269 , & V_6 -> V_123 , 6 ) ;
V_269 [ 6 ] = 0x00 ;
}
V_152 = F_67 ( V_20 -> V_151 , V_152 , V_585 ,
V_269 , sizeof( V_269 ) ) ;
if ( F_21 ( V_6 , V_118 ) )
V_584 = 0x02 ;
else
V_584 = 0x01 ;
V_152 = F_67 ( V_20 -> V_151 , V_152 , V_586 ,
& V_584 , sizeof( V_584 ) ) ;
if ( F_21 ( V_6 , V_119 ) ) {
V_152 = F_67 ( V_20 -> V_151 , V_152 ,
V_587 ,
V_385 , sizeof( V_385 ) ) ;
V_152 = F_67 ( V_20 -> V_151 , V_152 ,
V_588 ,
rand , sizeof( rand ) ) ;
}
V_182 = F_48 ( V_6 ) ;
if ( ! F_21 ( V_6 , V_113 ) )
V_182 |= V_589 ;
V_152 = F_67 ( V_20 -> V_151 , V_152 , V_590 ,
& V_182 , sizeof( V_182 ) ) ;
break;
}
F_36 ( V_6 ) ;
F_26 ( V_25 , V_582 ) ;
V_168 = V_205 ;
V_333:
V_20 -> type = V_129 -> type ;
V_20 -> V_152 = F_9 ( V_152 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_576 ,
V_168 , V_20 , sizeof( * V_20 ) + V_152 ) ;
if ( V_34 < 0 || V_168 )
goto V_284;
V_34 = F_5 ( V_583 , V_6 ,
V_20 , sizeof( * V_20 ) + V_152 ,
V_582 , V_25 ) ;
V_284:
F_17 ( V_20 ) ;
return V_34 ;
}
static T_6 F_290 ( struct V_5 * V_6 )
{
T_6 V_182 = 0 ;
V_182 |= V_591 ;
V_182 |= V_592 ;
V_182 |= V_593 ;
V_182 |= V_594 ;
V_182 |= V_376 ;
V_182 |= V_371 ;
if ( V_6 -> V_595 != V_501 )
V_182 |= V_596 ;
return V_182 ;
}
static int F_291 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_597 * V_20 ;
T_3 V_46 ;
int V_34 ;
struct V_366 * V_367 ;
T_6 V_598 ;
T_1 * V_171 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_599 ,
V_204 ) ;
F_35 ( V_6 ) ;
V_46 = sizeof( * V_20 ) + V_6 -> V_600 ;
V_20 = F_15 ( V_46 , V_52 ) ;
if ( ! V_20 ) {
F_36 ( V_6 ) ;
return - V_40 ;
}
V_598 = F_290 ( V_6 ) ;
V_20 -> V_598 = F_31 ( V_598 ) ;
V_20 -> V_601 = V_602 ;
V_20 -> V_603 = V_602 ;
V_20 -> V_604 = V_605 ;
V_20 -> V_606 = V_6 -> V_600 ;
V_171 = V_20 -> V_171 ;
F_20 (adv_instance, &hdev->adv_instances, list) {
* V_171 = V_367 -> V_171 ;
V_171 ++ ;
}
F_36 ( V_6 ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_599 ,
V_205 , V_20 , V_46 ) ;
F_17 ( V_20 ) ;
return V_34 ;
}
static T_1 F_292 ( struct V_5 * V_6 )
{
T_1 V_159 [ V_607 + 3 ] ;
return F_293 ( V_6 , V_159 , 0 ) ;
}
static T_1 F_294 ( struct V_5 * V_6 , T_6 V_608 ,
bool V_609 )
{
T_1 V_610 = V_602 ;
if ( V_609 ) {
if ( V_608 & ( V_592 |
V_593 |
V_594 ) )
V_610 -= 3 ;
if ( V_608 & V_596 )
V_610 -= 3 ;
} else {
if ( V_608 & V_371 )
V_610 -= F_292 ( V_6 ) ;
if ( V_608 & ( V_376 ) )
V_610 -= 4 ;
}
return V_610 ;
}
static bool F_295 ( T_6 V_608 )
{
return V_608 & ( V_592 |
V_593 |
V_594 ) ;
}
static bool F_296 ( T_6 V_608 )
{
return V_608 & V_596 ;
}
static bool F_297 ( T_6 V_608 )
{
return V_608 & V_371 ;
}
static bool F_298 ( T_6 V_608 )
{
return V_608 & V_376 ;
}
static bool F_299 ( struct V_5 * V_6 , T_6 V_608 , T_1 * V_7 ,
T_1 V_8 , bool V_609 )
{
int V_33 , V_611 ;
T_1 V_610 ;
V_610 = F_294 ( V_6 , V_608 , V_609 ) ;
if ( V_8 > V_610 )
return false ;
for ( V_33 = 0 , V_611 = 0 ; V_33 < V_8 ; V_33 += ( V_611 + 1 ) ) {
V_611 = V_7 [ V_33 ] ;
if ( V_7 [ V_33 + 1 ] == V_590 &&
( ! V_609 || F_295 ( V_608 ) ) )
return false ;
if ( V_7 [ V_33 + 1 ] == V_612 && F_296 ( V_608 ) )
return false ;
if ( V_7 [ V_33 + 1 ] == V_157 && F_297 ( V_608 ) )
return false ;
if ( V_7 [ V_33 + 1 ] == V_158 && F_297 ( V_608 ) )
return false ;
if ( V_7 [ V_33 + 1 ] == V_155 &&
F_298 ( V_608 ) )
return false ;
if ( V_33 + V_611 >= V_8 )
return false ;
}
return true ;
}
static void F_300 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 )
{
struct V_125 * V_126 ;
struct V_613 * V_129 ;
struct V_614 V_20 ;
struct V_366 * V_367 , * V_615 ;
T_1 V_171 ;
F_11 ( L_19 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_616 , V_6 ) ;
F_136 (adv_instance, n, &hdev->adv_instances, list) {
if ( ! V_367 -> V_617 )
continue;
if ( ! V_168 ) {
V_367 -> V_617 = false ;
continue;
}
V_171 = V_367 -> V_171 ;
if ( V_6 -> V_368 == V_171 )
F_78 ( V_6 ) ;
F_301 ( V_6 , V_171 ) ;
F_77 ( V_126 ? V_126 -> V_25 : NULL , V_6 , V_171 ) ;
}
if ( ! V_126 )
goto V_206;
V_129 = V_126 -> V_130 ;
V_20 . V_171 = V_129 -> V_171 ;
if ( V_168 )
F_87 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 ,
F_1 ( V_168 ) ) ;
else
F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 ,
F_1 ( V_168 ) , & V_20 , sizeof( V_20 ) ) ;
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_302 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_613 * V_129 = V_7 ;
struct V_614 V_20 ;
T_6 V_182 ;
T_6 V_598 ;
T_1 V_168 ;
T_2 V_213 , V_618 ;
unsigned int V_619 = V_6 -> V_600 ;
T_1 V_620 = 0 ;
struct V_366 * V_621 ;
int V_34 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
V_168 = F_102 ( V_6 ) ;
if ( V_168 )
return F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_168 ) ;
if ( V_129 -> V_171 < 1 || V_129 -> V_171 > V_605 )
return F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_189 ) ;
if ( V_26 != sizeof( * V_129 ) + V_129 -> V_622 + V_129 -> V_623 )
return F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_189 ) ;
V_182 = F_303 ( V_129 -> V_182 ) ;
V_213 = F_106 ( V_129 -> V_213 ) ;
V_618 = F_106 ( V_129 -> V_618 ) ;
V_598 = F_290 ( V_6 ) ;
if ( V_182 & ~ V_598 )
return F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_189 ) ;
F_35 ( V_6 ) ;
if ( V_213 && ! F_43 ( V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_204 ) ;
goto V_206;
}
if ( F_44 ( V_616 , V_6 ) ||
F_44 ( V_624 , V_6 ) ||
F_44 ( V_228 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_190 ) ;
goto V_206;
}
if ( ! F_299 ( V_6 , V_182 , V_129 -> V_7 , V_129 -> V_622 , true ) ||
! F_299 ( V_6 , V_182 , V_129 -> V_7 + V_129 -> V_622 ,
V_129 -> V_623 , false ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_189 ) ;
goto V_206;
}
V_34 = F_304 ( V_6 , V_129 -> V_171 , V_182 ,
V_129 -> V_622 , V_129 -> V_7 ,
V_129 -> V_623 ,
V_129 -> V_7 + V_129 -> V_622 ,
V_213 , V_618 ) ;
if ( V_34 < 0 ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_616 ,
V_3 ) ;
goto V_206;
}
if ( V_6 -> V_600 > V_619 )
F_76 ( V_25 , V_6 , V_129 -> V_171 ) ;
if ( V_6 -> V_368 == V_129 -> V_171 ) {
F_78 ( V_6 ) ;
V_621 = F_190 ( V_6 , V_129 -> V_171 ) ;
if ( V_621 )
V_620 = V_621 -> V_171 ;
} else if ( ! V_6 -> V_176 ) {
V_620 = V_129 -> V_171 ;
}
if ( ! F_43 ( V_6 ) ||
F_21 ( V_6 , V_118 ) ||
! V_620 ) {
V_20 . V_171 = V_129 -> V_171 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_616 ,
V_205 , & V_20 , sizeof( V_20 ) ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_616 , V_6 , V_7 ,
V_26 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
V_34 = F_191 ( & V_140 , V_620 , true ) ;
if ( ! V_34 )
V_34 = F_56 ( & V_140 , F_300 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_305 ( struct V_5 * V_6 , T_1 V_168 ,
T_2 V_41 )
{
struct V_125 * V_126 ;
struct V_625 * V_129 ;
struct V_626 V_20 ;
F_11 ( L_19 , V_168 ) ;
F_35 ( V_6 ) ;
V_126 = F_44 ( V_624 , V_6 ) ;
if ( ! V_126 )
goto V_206;
V_129 = V_126 -> V_130 ;
V_20 . V_171 = V_129 -> V_171 ;
F_12 ( V_126 -> V_25 , V_126 -> V_58 , V_126 -> V_41 , V_205 ,
& V_20 , sizeof( V_20 ) ) ;
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
}
static int F_306 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_625 * V_129 = V_7 ;
struct V_626 V_20 ;
struct V_125 * V_126 ;
struct V_139 V_140 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_35 ( V_6 ) ;
if ( V_129 -> V_171 && ! F_189 ( V_6 , V_129 -> V_171 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 ,
V_624 ,
V_189 ) ;
goto V_206;
}
if ( F_44 ( V_616 , V_6 ) ||
F_44 ( V_624 , V_6 ) ||
F_44 ( V_228 , V_6 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_624 ,
V_190 ) ;
goto V_206;
}
if ( F_229 ( & V_6 -> V_446 ) ) {
V_34 = F_87 ( V_25 , V_6 -> V_59 , V_624 ,
V_189 ) ;
goto V_206;
}
F_53 ( & V_140 , V_6 ) ;
F_81 ( V_6 , V_25 , & V_140 , V_129 -> V_171 , true ) ;
if ( F_229 ( & V_6 -> V_446 ) )
F_82 ( & V_140 ) ;
if ( F_307 ( & V_140 . V_627 ) ||
! F_43 ( V_6 ) ||
F_21 ( V_6 , V_118 ) ) {
V_20 . V_171 = V_129 -> V_171 ;
V_34 = F_12 ( V_25 , V_6 -> V_59 ,
V_624 ,
V_205 , & V_20 , sizeof( V_20 ) ) ;
goto V_206;
}
V_126 = F_88 ( V_25 , V_624 , V_6 , V_7 ,
V_26 ) ;
if ( ! V_126 ) {
V_34 = - V_40 ;
goto V_206;
}
V_34 = F_56 ( & V_140 , F_305 ) ;
if ( V_34 < 0 )
F_97 ( V_126 ) ;
V_206:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_308 ( struct V_11 * V_25 , struct V_5 * V_6 ,
void * V_7 , T_2 V_26 )
{
struct V_628 * V_129 = V_7 ;
struct V_629 V_20 ;
T_6 V_182 , V_598 ;
int V_34 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
if ( ! F_41 ( V_6 ) )
return F_87 ( V_25 , V_6 -> V_59 , V_630 ,
V_204 ) ;
if ( V_129 -> V_171 < 1 || V_129 -> V_171 > V_605 )
return F_87 ( V_25 , V_6 -> V_59 , V_630 ,
V_189 ) ;
V_182 = F_303 ( V_129 -> V_182 ) ;
V_598 = F_290 ( V_6 ) ;
if ( V_182 & ~ V_598 )
return F_87 ( V_25 , V_6 -> V_59 , V_630 ,
V_189 ) ;
V_20 . V_171 = V_129 -> V_171 ;
V_20 . V_182 = V_129 -> V_182 ;
V_20 . V_601 = F_294 ( V_6 , V_182 , true ) ;
V_20 . V_603 = F_294 ( V_6 , V_182 , false ) ;
V_34 = F_12 ( V_25 , V_6 -> V_59 , V_630 ,
V_205 , & V_20 , sizeof( V_20 ) ) ;
return V_34 ;
}
void F_283 ( struct V_5 * V_6 )
{
struct V_631 V_166 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_632 , V_6 ,
NULL , 0 , V_70 ) ;
V_166 . type = 0x01 ;
} else {
F_3 ( V_633 , V_6 , NULL , 0 ,
V_69 ) ;
V_166 . type = 0x00 ;
}
break;
case V_65 :
V_166 . type = 0x02 ;
break;
default:
return;
}
V_166 . V_67 = V_6 -> V_67 ;
F_3 ( V_634 , V_6 , & V_166 , sizeof( V_166 ) ,
V_68 ) ;
}
void F_281 ( struct V_5 * V_6 )
{
struct V_631 V_166 ;
T_1 V_168 = V_635 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
F_119 ( 0 , V_6 , F_98 , & V_168 ) ;
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_636 , V_6 ,
NULL , 0 , V_70 ) ;
V_166 . type = 0x01 ;
} else {
F_3 ( V_637 , V_6 , NULL , 0 ,
V_69 ) ;
V_166 . type = 0x00 ;
}
break;
case V_65 :
V_166 . type = 0x02 ;
break;
default:
return;
}
V_166 . V_67 = V_6 -> V_67 ;
F_3 ( V_638 , V_6 , & V_166 , sizeof( V_166 ) ,
V_68 ) ;
}
static void F_309 ( struct V_5 * V_6 )
{
struct V_278 * V_341 ;
F_20 (p, &hdev->le_conn_params, list) {
F_270 ( & V_341 -> V_527 ) ;
switch ( V_341 -> V_287 ) {
case V_532 :
case V_533 :
F_271 ( & V_341 -> V_527 , & V_6 -> V_529 ) ;
break;
case V_530 :
F_271 ( & V_341 -> V_527 , & V_6 -> V_531 ) ;
break;
default:
break;
}
}
}
void F_310 ( struct V_5 * V_6 , int V_34 )
{
struct V_197 V_198 = { NULL , V_6 } ;
F_11 ( L_40 , V_34 ) ;
F_35 ( V_6 ) ;
if ( ! V_34 ) {
F_309 ( V_6 ) ;
F_111 ( V_6 ) ;
}
F_119 ( V_188 , V_6 , F_92 , & V_198 ) ;
F_90 ( V_6 , V_198 . V_25 ) ;
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
F_36 ( V_6 ) ;
}
void F_311 ( struct V_5 * V_6 )
{
struct V_197 V_198 = { NULL , V_6 } ;
T_1 V_168 , V_639 [] = { 0 , 0 , 0 } ;
F_119 ( V_188 , V_6 , F_92 , & V_198 ) ;
if ( F_21 ( V_6 , V_640 ) )
V_168 = V_635 ;
else
V_168 = V_214 ;
F_119 ( 0 , V_6 , F_98 , & V_168 ) ;
if ( memcmp ( V_6 -> V_147 , V_639 , sizeof( V_639 ) ) != 0 ) {
F_5 ( V_641 , V_6 ,
V_639 , sizeof( V_639 ) ,
V_162 , NULL ) ;
F_70 ( V_6 , NULL ) ;
}
F_90 ( V_6 , V_198 . V_25 ) ;
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
}
void F_312 ( struct V_5 * V_6 , int V_34 )
{
struct V_125 * V_126 ;
T_1 V_168 ;
V_126 = F_44 ( V_188 , V_6 ) ;
if ( ! V_126 )
return;
if ( V_34 == - V_642 )
V_168 = V_643 ;
else
V_168 = V_3 ;
F_87 ( V_126 -> V_25 , V_6 -> V_59 , V_188 , V_168 ) ;
F_97 ( V_126 ) ;
}
void F_313 ( struct V_5 * V_6 , struct V_644 * V_267 ,
bool V_645 )
{
struct V_646 V_166 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_647 = V_645 ;
F_65 ( & V_166 . V_267 . V_269 . V_123 , & V_267 -> V_123 ) ;
V_166 . V_267 . V_269 . type = V_270 ;
V_166 . V_267 . type = V_267 -> type ;
memcpy ( V_166 . V_267 . V_131 , V_267 -> V_131 , V_648 ) ;
V_166 . V_267 . V_272 = V_267 -> V_272 ;
F_6 ( V_649 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
static T_1 F_314 ( struct V_650 * V_651 )
{
switch ( V_651 -> type ) {
case V_487 :
case V_488 :
if ( V_651 -> V_485 )
return V_489 ;
return V_486 ;
case V_491 :
if ( V_651 -> V_485 )
return V_492 ;
return V_490 ;
case V_494 :
return V_493 ;
}
return V_486 ;
}
void F_315 ( struct V_5 * V_6 , struct V_650 * V_267 , bool V_645 )
{
struct V_652 V_166 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( V_267 -> V_547 == V_17 &&
( V_267 -> V_123 . V_454 [ 5 ] & 0xc0 ) != 0xc0 )
V_166 . V_647 = 0x00 ;
else
V_166 . V_647 = V_645 ;
F_65 ( & V_166 . V_267 . V_269 . V_123 , & V_267 -> V_123 ) ;
V_166 . V_267 . V_269 . type = F_158 ( V_300 , V_267 -> V_547 ) ;
V_166 . V_267 . type = F_314 ( V_267 ) ;
V_166 . V_267 . V_495 = V_267 -> V_495 ;
V_166 . V_267 . V_496 = V_267 -> V_496 ;
V_166 . V_267 . rand = V_267 -> rand ;
if ( V_267 -> type == V_487 )
V_166 . V_267 . V_482 = 1 ;
memcpy ( V_166 . V_267 . V_131 , V_267 -> V_131 , V_267 -> V_495 ) ;
memset ( V_166 . V_267 . V_131 + V_267 -> V_495 , 0 ,
sizeof( V_166 . V_267 . V_131 ) - V_267 -> V_495 ) ;
F_6 ( V_653 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_316 ( struct V_5 * V_6 , struct V_654 * V_474 , bool V_645 )
{
struct V_655 V_166 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_647 = V_645 ;
F_65 ( & V_166 . V_656 , & V_474 -> V_656 ) ;
F_65 ( & V_166 . V_474 . V_269 . V_123 , & V_474 -> V_123 ) ;
V_166 . V_474 . V_269 . type = F_158 ( V_300 , V_474 -> V_273 ) ;
memcpy ( V_166 . V_474 . V_131 , V_474 -> V_131 , sizeof( V_474 -> V_131 ) ) ;
F_6 ( V_657 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_317 ( struct V_5 * V_6 , struct V_658 * V_659 ,
bool V_645 )
{
struct V_660 V_166 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( V_659 -> V_547 == V_17 &&
( V_659 -> V_123 . V_454 [ 5 ] & 0xc0 ) != 0xc0 )
V_166 . V_647 = 0x00 ;
else
V_166 . V_647 = V_645 ;
F_65 ( & V_166 . V_267 . V_269 . V_123 , & V_659 -> V_123 ) ;
V_166 . V_267 . V_269 . type = F_158 ( V_300 , V_659 -> V_547 ) ;
V_166 . V_267 . type = V_659 -> type ;
memcpy ( V_166 . V_267 . V_131 , V_659 -> V_131 , sizeof( V_659 -> V_131 ) ) ;
F_6 ( V_661 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_318 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_547 , T_1 V_647 , T_2 V_557 ,
T_2 V_558 , T_2 V_556 , T_2 V_213 )
{
struct V_662 V_166 ;
if ( ! F_274 ( V_123 , V_547 ) )
return;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = F_158 ( V_300 , V_547 ) ;
V_166 . V_647 = V_647 ;
V_166 . V_557 = F_9 ( V_557 ) ;
V_166 . V_558 = F_9 ( V_558 ) ;
V_166 . V_556 = F_9 ( V_556 ) ;
V_166 . V_213 = F_9 ( V_213 ) ;
F_6 ( V_663 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_319 ( struct V_5 * V_6 , struct V_178 * V_179 ,
T_6 V_182 , T_1 * V_84 , T_1 V_153 )
{
char V_159 [ 512 ] ;
struct V_664 * V_166 = ( void * ) V_159 ;
T_2 V_152 = 0 ;
F_65 ( & V_166 -> V_269 . V_123 , & V_179 -> V_306 ) ;
V_166 -> V_269 . type = F_158 ( V_179 -> type , V_179 -> V_307 ) ;
V_166 -> V_182 = F_320 ( V_182 ) ;
if ( V_179 -> V_665 > 0 ) {
memcpy ( & V_166 -> V_151 [ V_152 ] ,
V_179 -> V_666 , V_179 -> V_665 ) ;
V_152 = V_179 -> V_665 ;
} else {
if ( V_153 > 0 )
V_152 = F_67 ( V_166 -> V_151 , 0 , V_157 ,
V_84 , V_153 ) ;
if ( memcmp ( V_179 -> V_147 , L_41 , 3 ) != 0 )
V_152 = F_67 ( V_166 -> V_151 , V_152 ,
V_154 ,
V_179 -> V_147 , 3 ) ;
}
V_166 -> V_152 = F_9 ( V_152 ) ;
F_6 ( V_667 , V_6 , V_159 ,
sizeof( * V_166 ) + V_152 , NULL ) ;
}
static void F_321 ( struct V_125 * V_126 , void * V_7 )
{
struct V_11 * * V_25 = V_7 ;
V_126 -> V_200 ( V_126 , 0 ) ;
* V_25 = V_126 -> V_25 ;
F_94 ( * V_25 ) ;
F_97 ( V_126 ) ;
}
static void F_322 ( struct V_125 * V_126 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_276 * V_129 = V_126 -> V_130 ;
F_144 ( V_6 , & V_129 -> V_269 . V_123 , V_129 -> V_269 . type , V_126 -> V_25 ) ;
V_126 -> V_200 ( V_126 , 0 ) ;
F_97 ( V_126 ) ;
}
bool F_323 ( struct V_5 * V_6 )
{
struct V_125 * V_126 ;
struct V_128 * V_129 ;
V_126 = F_44 ( V_188 , V_6 ) ;
if ( ! V_126 )
return false ;
V_129 = V_126 -> V_130 ;
if ( ! V_129 -> V_131 )
return true ;
return false ;
}
void F_324 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_668 ,
bool V_669 )
{
struct V_670 V_166 ;
struct V_11 * V_25 = NULL ;
if ( F_323 ( V_6 ) && F_73 ( V_6 ) == 1 ) {
F_74 ( & V_6 -> V_169 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_169 . V_137 ) ;
}
if ( ! V_669 )
return;
if ( V_299 != V_282 && V_299 != V_300 )
return;
F_119 ( V_293 , V_6 , F_321 , & V_25 ) ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = F_158 ( V_299 , V_273 ) ;
V_166 . V_668 = V_668 ;
F_6 ( V_671 , V_6 , & V_166 , sizeof( V_166 ) , V_25 ) ;
if ( V_25 )
F_120 ( V_25 ) ;
F_119 ( V_280 , V_6 , F_322 ,
V_6 ) ;
}
void F_325 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_168 )
{
T_1 V_547 = F_158 ( V_299 , V_273 ) ;
struct V_291 * V_129 ;
struct V_125 * V_126 ;
F_119 ( V_280 , V_6 , F_322 ,
V_6 ) ;
V_126 = F_44 ( V_293 , V_6 ) ;
if ( ! V_126 )
return;
V_129 = V_126 -> V_130 ;
if ( F_29 ( V_123 , & V_129 -> V_269 . V_123 ) )
return;
if ( V_129 -> V_269 . type != V_547 )
return;
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
void F_326 ( struct V_5 * V_6 , T_7 * V_123 , T_1 V_299 ,
T_1 V_273 , T_1 V_168 )
{
struct V_672 V_166 ;
if ( F_323 ( V_6 ) && F_73 ( V_6 ) == 1 ) {
F_74 ( & V_6 -> V_169 ) ;
F_75 ( V_6 -> V_170 , & V_6 -> V_169 . V_137 ) ;
}
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = F_158 ( V_299 , V_273 ) ;
V_166 . V_168 = F_1 ( V_168 ) ;
F_6 ( V_673 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_327 ( struct V_5 * V_6 , T_7 * V_123 , T_1 V_674 )
{
struct V_675 V_166 ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = V_270 ;
V_166 . V_674 = V_674 ;
F_6 ( V_676 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_328 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_168 )
{
struct V_125 * V_126 ;
V_126 = F_44 ( V_317 , V_6 ) ;
if ( ! V_126 )
return;
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
void F_329 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_168 )
{
struct V_125 * V_126 ;
V_126 = F_44 ( V_312 , V_6 ) ;
if ( ! V_126 )
return;
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
}
int F_330 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_6 V_677 ,
T_1 V_678 )
{
struct V_679 V_166 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = F_158 ( V_299 , V_273 ) ;
V_166 . V_678 = V_678 ;
V_166 . V_677 = F_31 ( V_677 ) ;
return F_6 ( V_680 , V_6 , & V_166 , sizeof( V_166 ) ,
NULL ) ;
}
int F_331 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 )
{
struct V_681 V_166 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = F_158 ( V_299 , V_273 ) ;
return F_6 ( V_682 , V_6 , & V_166 , sizeof( V_166 ) ,
NULL ) ;
}
static int F_332 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_168 ,
T_1 V_41 )
{
struct V_125 * V_126 ;
V_126 = F_44 ( V_41 , V_6 ) ;
if ( ! V_126 )
return - V_683 ;
V_126 -> V_200 ( V_126 , F_1 ( V_168 ) ) ;
F_97 ( V_126 ) ;
return 0 ;
}
int F_333 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_168 )
{
return F_332 ( V_6 , V_123 , V_299 , V_273 ,
V_168 , V_356 ) ;
}
int F_334 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_168 )
{
return F_332 ( V_6 , V_123 , V_299 , V_273 ,
V_168 ,
V_359 ) ;
}
int F_335 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_168 )
{
return F_332 ( V_6 , V_123 , V_299 , V_273 ,
V_168 , V_362 ) ;
}
int F_336 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_1 V_168 )
{
return F_332 ( V_6 , V_123 , V_299 , V_273 ,
V_168 ,
V_364 ) ;
}
int F_337 ( struct V_5 * V_6 , T_7 * V_123 ,
T_1 V_299 , T_1 V_273 , T_6 V_352 ,
T_1 V_684 )
{
struct V_685 V_166 ;
F_11 ( L_16 , V_6 -> V_84 ) ;
F_65 ( & V_166 . V_269 . V_123 , V_123 ) ;
V_166 . V_269 . type = F_158 ( V_299 , V_273 ) ;
V_166 . V_352 = F_320 ( V_352 ) ;
V_166 . V_684 = V_684 ;
return F_6 ( V_686 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
void F_338 ( struct V_178 * V_179 , T_1 V_1 )
{
struct V_687 V_166 ;
struct V_125 * V_126 ;
T_1 V_168 = F_1 ( V_1 ) ;
F_65 ( & V_166 . V_269 . V_123 , & V_179 -> V_306 ) ;
V_166 . V_269 . type = F_158 ( V_179 -> type , V_179 -> V_307 ) ;
V_166 . V_168 = V_168 ;
V_126 = F_163 ( V_179 ) ;
F_6 ( V_688 , V_179 -> V_6 , & V_166 , sizeof( V_166 ) ,
V_126 ? V_126 -> V_25 : NULL ) ;
if ( V_126 ) {
V_126 -> V_200 ( V_126 , V_168 ) ;
F_97 ( V_126 ) ;
}
}
void F_339 ( struct V_5 * V_6 , T_1 V_168 )
{
struct V_197 V_198 = { NULL , V_6 } ;
bool V_215 ;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
F_119 ( V_220 , V_6 ,
F_96 , & V_207 ) ;
return;
}
if ( F_23 ( V_221 , & V_6 -> V_182 ) )
V_215 = ! F_61 ( V_6 , V_115 ) ;
else
V_215 = F_52 ( V_6 , V_115 ) ;
F_119 ( V_220 , V_6 , F_92 ,
& V_198 ) ;
if ( V_215 )
F_90 ( V_6 , V_198 . V_25 ) ;
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
}
static void F_340 ( struct V_139 * V_140 )
{
struct V_5 * V_6 = V_140 -> V_6 ;
struct V_689 V_129 ;
if ( ! F_341 ( V_6 ) )
return;
memset ( V_6 -> V_151 , 0 , sizeof( V_6 -> V_151 ) ) ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_80 ( V_140 , V_690 , sizeof( V_129 ) , & V_129 ) ;
}
void F_342 ( struct V_5 * V_6 , T_1 V_691 , T_1 V_168 )
{
struct V_197 V_198 = { NULL , V_6 } ;
struct V_139 V_140 ;
bool V_215 = false ;
if ( V_168 ) {
T_1 V_207 = F_1 ( V_168 ) ;
if ( V_691 && F_52 ( V_6 ,
V_116 ) ) {
F_63 ( V_6 , V_117 ) ;
F_90 ( V_6 , NULL ) ;
}
F_119 ( V_223 , V_6 , F_96 ,
& V_207 ) ;
return;
}
if ( V_691 ) {
V_215 = ! F_61 ( V_6 , V_116 ) ;
} else {
V_215 = F_52 ( V_6 , V_116 ) ;
if ( ! V_215 )
V_215 = F_52 ( V_6 ,
V_117 ) ;
else
F_63 ( V_6 , V_117 ) ;
}
F_119 ( V_223 , V_6 , F_92 , & V_198 ) ;
if ( V_215 )
F_90 ( V_6 , V_198 . V_25 ) ;
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
F_53 ( & V_140 , V_6 ) ;
if ( F_21 ( V_6 , V_116 ) ) {
if ( F_21 ( V_6 , V_224 ) )
F_80 ( & V_140 , V_225 ,
sizeof( V_691 ) , & V_691 ) ;
F_54 ( & V_140 ) ;
} else {
F_340 ( & V_140 ) ;
}
F_56 ( & V_140 , NULL ) ;
}
static void F_343 ( struct V_125 * V_126 , void * V_7 )
{
struct V_197 * V_198 = V_7 ;
if ( V_198 -> V_25 == NULL ) {
V_198 -> V_25 = V_126 -> V_25 ;
F_94 ( V_198 -> V_25 ) ;
}
}
void F_344 ( struct V_5 * V_6 , T_1 * V_147 ,
T_1 V_168 )
{
struct V_197 V_198 = { NULL , V_6 , F_1 (status) } ;
F_119 ( V_238 , V_6 , F_343 , & V_198 ) ;
F_119 ( V_236 , V_6 , F_343 , & V_198 ) ;
F_119 ( V_237 , V_6 , F_343 , & V_198 ) ;
if ( ! V_168 ) {
F_5 ( V_641 , V_6 , V_147 ,
3 , V_162 , NULL ) ;
F_70 ( V_6 , NULL ) ;
}
if ( V_198 . V_25 )
F_120 ( V_198 . V_25 ) ;
}
void F_345 ( struct V_5 * V_6 , T_1 * V_84 , T_1 V_168 )
{
struct V_369 V_166 ;
struct V_125 * V_126 ;
if ( V_168 )
return;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
memcpy ( V_166 . V_84 , V_84 , V_692 ) ;
memcpy ( V_166 . V_149 , V_6 -> V_149 , V_607 ) ;
V_126 = F_44 ( V_370 , V_6 ) ;
if ( ! V_126 ) {
memcpy ( V_6 -> V_148 , V_84 , sizeof( V_6 -> V_148 ) ) ;
if ( F_44 ( V_188 , V_6 ) )
return;
}
F_5 ( V_372 , V_6 , & V_166 , sizeof( V_166 ) ,
V_163 , V_126 ? V_126 -> V_25 : NULL ) ;
F_70 ( V_6 , V_126 ? V_126 -> V_25 : NULL ) ;
}
static void F_346 ( struct V_5 * V_6 )
{
if ( ! F_21 ( V_6 , V_448 ) )
return;
if ( F_261 ( V_511 + V_693 ,
V_6 -> V_407 . V_694 +
V_6 -> V_407 . V_695 ) )
return;
F_89 ( V_6 -> V_170 , & V_6 -> V_696 ,
V_693 ) ;
}
static bool F_347 ( struct V_5 * V_6 , T_10 V_418 , T_1 * V_151 ,
T_2 V_152 , T_1 * V_697 , T_1 V_623 )
{
if ( V_6 -> V_407 . V_418 != V_500 &&
( V_418 == V_500 ||
( V_418 < V_6 -> V_407 . V_418 &&
! F_23 ( V_698 , & V_6 -> V_57 ) ) ) )
return false ;
if ( V_6 -> V_407 . V_416 != 0 ) {
if ( ! F_348 ( V_151 , V_152 , V_6 -> V_407 . V_416 ,
V_6 -> V_407 . V_246 ) &&
! F_348 ( V_697 , V_623 ,
V_6 -> V_407 . V_416 ,
V_6 -> V_407 . V_246 ) )
return false ;
}
if ( F_23 ( V_698 , & V_6 -> V_57 ) ) {
F_346 ( V_6 ) ;
if ( V_6 -> V_407 . V_418 != V_500 &&
V_418 < V_6 -> V_407 . V_418 )
return false ;
}
return true ;
}
void F_349 ( struct V_5 * V_6 , T_7 * V_123 , T_1 V_299 ,
T_1 V_273 , T_1 * V_147 , T_10 V_418 , T_6 V_182 ,
T_1 * V_151 , T_2 V_152 , T_1 * V_697 , T_1 V_623 )
{
char V_159 [ 512 ] ;
struct V_699 * V_166 = ( void * ) V_159 ;
T_3 V_700 ;
if ( ! F_218 ( V_6 ) ) {
if ( V_299 == V_282 )
return;
if ( V_299 == V_300 && F_229 ( & V_6 -> V_531 ) )
return;
}
if ( V_6 -> V_407 . V_417 ) {
if ( ! F_347 ( V_6 , V_418 , V_151 , V_152 , V_697 ,
V_623 ) )
return;
}
if ( V_6 -> V_407 . V_411 ) {
if ( V_147 ) {
if ( ! ( V_147 [ 1 ] & 0x20 ) )
return;
} else {
T_1 * V_182 = F_350 ( V_151 , V_152 , V_590 , NULL ) ;
if ( ! V_182 || ! ( V_182 [ 0 ] & V_133 ) )
return;
}
}
if ( sizeof( * V_166 ) + V_152 + V_623 + 5 > sizeof( V_159 ) )
return;
memset ( V_159 , 0 , sizeof( V_159 ) ) ;
if ( V_418 == V_500 && ! V_6 -> V_407 . V_410 &&
V_299 == V_282 )
V_418 = 0 ;
F_65 ( & V_166 -> V_269 . V_123 , V_123 ) ;
V_166 -> V_269 . type = F_158 ( V_299 , V_273 ) ;
V_166 -> V_418 = V_418 ;
V_166 -> V_182 = F_31 ( V_182 ) ;
if ( V_152 > 0 )
memcpy ( V_166 -> V_151 , V_151 , V_152 ) ;
if ( V_147 && ! F_350 ( V_166 -> V_151 , V_152 , V_154 ,
NULL ) )
V_152 = F_67 ( V_166 -> V_151 , V_152 , V_154 ,
V_147 , 3 ) ;
if ( V_623 > 0 )
memcpy ( V_166 -> V_151 + V_152 , V_697 , V_623 ) ;
V_166 -> V_152 = F_9 ( V_152 + V_623 ) ;
V_700 = sizeof( * V_166 ) + V_152 + V_623 ;
F_6 ( V_701 , V_6 , V_166 , V_700 , NULL ) ;
}
void F_351 ( struct V_5 * V_6 , T_7 * V_123 , T_1 V_299 ,
T_1 V_273 , T_10 V_418 , T_1 * V_84 , T_1 V_153 )
{
struct V_699 * V_166 ;
char V_159 [ sizeof( * V_166 ) + V_692 + 2 ] ;
T_2 V_152 ;
V_166 = (struct V_699 * ) V_159 ;
memset ( V_159 , 0 , sizeof( V_159 ) ) ;
F_65 ( & V_166 -> V_269 . V_123 , V_123 ) ;
V_166 -> V_269 . type = F_158 ( V_299 , V_273 ) ;
V_166 -> V_418 = V_418 ;
V_152 = F_67 ( V_166 -> V_151 , 0 , V_157 , V_84 ,
V_153 ) ;
V_166 -> V_152 = F_9 ( V_152 ) ;
F_6 ( V_701 , V_6 , V_166 , sizeof( * V_166 ) + V_152 , NULL ) ;
}
void F_352 ( struct V_5 * V_6 , T_1 V_702 )
{
struct V_703 V_166 ;
F_11 ( L_42 , V_6 -> V_84 , V_702 ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . type = V_6 -> V_407 . type ;
V_166 . V_702 = V_702 ;
F_6 ( V_704 , V_6 , & V_166 , sizeof( V_166 ) , NULL ) ;
}
int F_353 ( void )
{
return F_354 ( & V_705 ) ;
}
void F_355 ( void )
{
F_356 ( & V_705 ) ;
}
