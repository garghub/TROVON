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
static T_1 * F_44 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_8 )
{
T_1 * V_124 = V_7 , * V_125 = NULL ;
struct V_126 * V_127 ;
if ( V_8 < 4 )
return V_124 ;
F_20 (uuid, &hdev->uuids, list) {
T_2 V_128 ;
if ( V_127 -> V_129 != 16 )
continue;
V_128 = F_45 ( & V_127 -> V_127 [ 12 ] ) ;
if ( V_128 < 0x1100 )
continue;
if ( V_128 == V_130 )
continue;
if ( ! V_125 ) {
V_125 = V_124 ;
V_125 [ 0 ] = 1 ;
V_125 [ 1 ] = V_131 ;
V_124 += 2 ;
}
if ( ( V_124 - V_7 ) + sizeof( T_2 ) > V_8 ) {
V_125 [ 1 ] = V_132 ;
break;
}
* V_124 ++ = ( V_128 & 0x00ff ) ;
* V_124 ++ = ( V_128 & 0xff00 ) >> 8 ;
V_125 [ 0 ] += sizeof( V_128 ) ;
}
return V_124 ;
}
static T_1 * F_46 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_8 )
{
T_1 * V_124 = V_7 , * V_125 = NULL ;
struct V_126 * V_127 ;
if ( V_8 < 6 )
return V_124 ;
F_20 (uuid, &hdev->uuids, list) {
if ( V_127 -> V_129 != 32 )
continue;
if ( ! V_125 ) {
V_125 = V_124 ;
V_125 [ 0 ] = 1 ;
V_125 [ 1 ] = V_133 ;
V_124 += 2 ;
}
if ( ( V_124 - V_7 ) + sizeof( T_6 ) > V_8 ) {
V_125 [ 1 ] = V_134 ;
break;
}
memcpy ( V_124 , & V_127 -> V_127 [ 12 ] , sizeof( T_6 ) ) ;
V_124 += sizeof( T_6 ) ;
V_125 [ 0 ] += sizeof( T_6 ) ;
}
return V_124 ;
}
static T_1 * F_47 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_8 )
{
T_1 * V_124 = V_7 , * V_125 = NULL ;
struct V_126 * V_127 ;
if ( V_8 < 18 )
return V_124 ;
F_20 (uuid, &hdev->uuids, list) {
if ( V_127 -> V_129 != 128 )
continue;
if ( ! V_125 ) {
V_125 = V_124 ;
V_125 [ 0 ] = 1 ;
V_125 [ 1 ] = V_135 ;
V_124 += 2 ;
}
if ( ( V_124 - V_7 ) + 16 > V_8 ) {
V_125 [ 1 ] = V_136 ;
break;
}
memcpy ( V_124 , V_127 -> V_127 , 16 ) ;
V_124 += 16 ;
V_125 [ 0 ] += 16 ;
}
return V_124 ;
}
static struct V_137 * F_48 ( T_2 V_41 , struct V_5 * V_6 )
{
return F_49 ( V_10 , V_41 , V_6 ) ;
}
static struct V_137 * F_50 ( T_2 V_41 ,
struct V_5 * V_6 ,
const void * V_7 )
{
return F_51 ( V_10 , V_41 , V_6 , V_7 ) ;
}
static T_1 F_52 ( struct V_5 * V_6 )
{
if ( F_21 ( V_6 , V_138 ) &&
! F_21 ( V_6 , V_117 ) )
return V_6 -> V_139 ;
return 0x00 ;
}
static T_1 F_53 ( struct V_5 * V_6 , T_1 * V_124 )
{
T_1 V_140 = 0 ;
T_3 V_141 ;
V_141 = strlen ( V_6 -> V_142 ) ;
if ( V_141 > 0 ) {
T_3 V_143 = V_144 - V_140 - 2 ;
if ( V_141 > V_143 ) {
V_141 = V_143 ;
V_124 [ 1 ] = V_145 ;
} else
V_124 [ 1 ] = V_146 ;
V_124 [ 0 ] = V_141 + 1 ;
memcpy ( V_124 + 2 , V_6 -> V_142 , V_141 ) ;
V_140 += ( V_141 + 2 ) ;
V_124 += ( V_141 + 2 ) ;
}
return V_140 ;
}
static T_1 F_54 ( struct V_5 * V_6 , T_1 V_147 ,
T_1 * V_124 )
{
struct V_148 * V_149 ;
V_149 = F_55 ( V_6 , V_147 ) ;
if ( ! V_149 )
return 0 ;
memcpy ( V_124 , V_149 -> V_150 ,
V_149 -> V_151 ) ;
return V_149 -> V_151 ;
}
static void F_56 ( struct V_152 * V_153 , T_1 V_147 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_154 V_155 ;
T_1 V_8 ;
if ( ! F_21 ( V_6 , V_113 ) )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_147 )
V_8 = F_54 ( V_6 , V_147 , V_155 . V_7 ) ;
else
V_8 = F_53 ( V_6 , V_155 . V_7 ) ;
if ( V_6 -> V_156 == V_8 &&
! memcmp ( V_155 . V_7 , V_6 -> V_150 , V_8 ) )
return;
memcpy ( V_6 -> V_150 , V_155 . V_7 , sizeof( V_155 . V_7 ) ) ;
V_6 -> V_156 = V_8 ;
V_155 . V_157 = V_8 ;
F_57 ( V_153 , V_158 , sizeof( V_155 ) , & V_155 ) ;
}
static void F_58 ( struct V_152 * V_153 )
{
F_56 ( V_153 , F_52 ( V_153 -> V_6 ) ) ;
}
static T_1 F_59 ( struct V_5 * V_6 )
{
struct V_137 * V_159 ;
V_159 = F_48 ( V_160 , V_6 ) ;
if ( V_159 ) {
struct V_161 * V_155 = V_159 -> V_162 ;
if ( V_155 -> V_163 == 0x01 )
return V_164 ;
else if ( V_155 -> V_163 == 0x02 )
return V_165 ;
} else {
if ( F_21 ( V_6 , V_166 ) )
return V_165 ;
else if ( F_21 ( V_6 , V_110 ) )
return V_164 ;
}
return 0 ;
}
static bool F_60 ( struct V_5 * V_6 )
{
struct V_137 * V_159 ;
V_159 = F_48 ( V_167 , V_6 ) ;
if ( V_159 ) {
struct V_161 * V_155 = V_159 -> V_162 ;
return V_155 -> V_163 ;
}
return F_21 ( V_6 , V_108 ) ;
}
static T_6 F_61 ( struct V_5 * V_6 , T_1 V_147 )
{
T_6 V_168 ;
struct V_148 * V_149 ;
if ( V_147 == 0x00 ) {
V_168 = V_169 | V_170 ;
if ( F_21 ( V_6 , V_171 ) )
V_168 |= V_172 ;
return V_168 ;
}
V_149 = F_55 ( V_6 , V_147 ) ;
if ( ! V_149 )
return 0 ;
return V_149 -> V_168 ;
}
static T_1 F_62 ( struct V_5 * V_6 )
{
T_1 V_147 = F_52 ( V_6 ) ;
struct V_148 * V_149 ;
if ( V_147 == 0x00 )
return 0 ;
V_149 = F_55 ( V_6 , V_147 ) ;
if ( ! V_149 )
return 0 ;
return V_149 -> V_151 ;
}
static T_1 F_63 ( struct V_5 * V_6 , T_1 V_147 , T_1 * V_124 )
{
struct V_148 * V_149 = NULL ;
T_1 V_140 = 0 , V_168 = 0 ;
T_6 V_173 ;
if ( V_147 ) {
V_149 = F_55 ( V_6 , V_147 ) ;
if ( ! V_149 )
return 0 ;
}
V_173 = F_61 ( V_6 , V_147 ) ;
if ( V_173 & V_174 )
V_168 |= V_164 ;
if ( V_173 & V_175 )
V_168 |= V_165 ;
if ( V_168 || ( V_173 & V_170 ) ) {
if ( ! V_168 )
V_168 |= F_59 ( V_6 ) ;
if ( ! F_21 ( V_6 , V_112 ) )
V_168 |= V_176 ;
if ( V_168 ) {
V_124 [ 0 ] = 0x02 ;
V_124 [ 1 ] = V_177 ;
V_124 [ 2 ] = V_168 ;
V_140 += 3 ;
V_124 += 3 ;
}
}
if ( V_149 ) {
memcpy ( V_124 , V_149 -> V_178 ,
V_149 -> V_179 ) ;
V_140 += V_149 -> V_179 ;
V_124 += V_149 -> V_179 ;
}
if ( V_6 -> V_180 != V_181 &&
( V_173 & V_169 ) ) {
V_124 [ 0 ] = 0x02 ;
V_124 [ 1 ] = V_182 ;
V_124 [ 2 ] = ( T_1 ) V_6 -> V_180 ;
V_140 += 3 ;
V_124 += 3 ;
}
return V_140 ;
}
static void F_64 ( struct V_152 * V_153 , T_1 V_147 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_183 V_155 ;
T_1 V_8 ;
if ( ! F_21 ( V_6 , V_113 ) )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_8 = F_63 ( V_6 , V_147 , V_155 . V_7 ) ;
if ( V_6 -> V_179 == V_8 &&
memcmp ( V_155 . V_7 , V_6 -> V_178 , V_8 ) == 0 )
return;
memcpy ( V_6 -> V_178 , V_155 . V_7 , sizeof( V_155 . V_7 ) ) ;
V_6 -> V_179 = V_8 ;
V_155 . V_157 = V_8 ;
F_57 ( V_153 , V_184 , sizeof( V_155 ) , & V_155 ) ;
}
static void F_65 ( struct V_152 * V_153 )
{
F_64 ( V_153 , F_52 ( V_153 -> V_6 ) ) ;
}
int F_66 ( struct V_5 * V_6 )
{
struct V_152 V_153 ;
F_67 ( & V_153 , V_6 ) ;
F_65 ( & V_153 ) ;
return F_68 ( & V_153 , NULL ) ;
}
static void F_69 ( struct V_5 * V_6 , T_1 * V_7 )
{
T_1 * V_124 = V_7 ;
T_3 V_141 ;
V_141 = strlen ( V_6 -> V_142 ) ;
if ( V_141 > 0 ) {
if ( V_141 > 48 ) {
V_141 = 48 ;
V_124 [ 1 ] = V_145 ;
} else
V_124 [ 1 ] = V_146 ;
V_124 [ 0 ] = V_141 + 1 ;
memcpy ( V_124 + 2 , V_6 -> V_142 , V_141 ) ;
V_124 += ( V_141 + 2 ) ;
}
if ( V_6 -> V_185 != V_181 ) {
V_124 [ 0 ] = 2 ;
V_124 [ 1 ] = V_182 ;
V_124 [ 2 ] = ( T_1 ) V_6 -> V_185 ;
V_124 += 3 ;
}
if ( V_6 -> V_186 > 0 ) {
V_124 [ 0 ] = 9 ;
V_124 [ 1 ] = V_187 ;
F_16 ( V_6 -> V_186 , V_124 + 2 ) ;
F_16 ( V_6 -> V_188 , V_124 + 4 ) ;
F_16 ( V_6 -> V_189 , V_124 + 6 ) ;
F_16 ( V_6 -> V_190 , V_124 + 8 ) ;
V_124 += 10 ;
}
V_124 = F_44 ( V_6 , V_124 , V_191 - ( V_124 - V_7 ) ) ;
V_124 = F_46 ( V_6 , V_124 , V_191 - ( V_124 - V_7 ) ) ;
V_124 = F_47 ( V_6 , V_124 , V_191 - ( V_124 - V_7 ) ) ;
}
static void F_70 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_192 V_155 ;
if ( ! F_43 ( V_6 ) )
return;
if ( ! F_71 ( V_6 ) )
return;
if ( ! F_21 ( V_6 , V_115 ) )
return;
if ( F_21 ( V_6 , V_193 ) )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
F_69 ( V_6 , V_155 . V_7 ) ;
if ( memcmp ( V_155 . V_7 , V_6 -> V_194 , sizeof( V_155 . V_7 ) ) == 0 )
return;
memcpy ( V_6 -> V_194 , V_155 . V_7 , sizeof( V_155 . V_7 ) ) ;
F_57 ( V_153 , V_195 , sizeof( V_155 ) , & V_155 ) ;
}
static T_1 F_72 ( struct V_5 * V_6 )
{
struct V_126 * V_127 ;
T_1 V_163 = 0 ;
F_20 (uuid, &hdev->uuids, list)
V_163 |= V_127 -> V_196 ;
return V_163 ;
}
static void F_73 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
T_1 V_197 [ 3 ] ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_43 ( V_6 ) )
return;
if ( ! F_21 ( V_6 , V_112 ) )
return;
if ( F_21 ( V_6 , V_193 ) )
return;
V_197 [ 0 ] = V_6 -> V_198 ;
V_197 [ 1 ] = V_6 -> V_199 ;
V_197 [ 2 ] = F_72 ( V_6 ) ;
if ( F_21 ( V_6 , V_166 ) )
V_197 [ 1 ] |= 0x20 ;
if ( memcmp ( V_197 , V_6 -> V_200 , 3 ) == 0 )
return;
F_57 ( V_153 , V_201 , sizeof( V_197 ) , V_197 ) ;
}
static void F_74 ( struct V_152 * V_153 )
{
T_1 V_202 = 0x00 ;
F_57 ( V_153 , V_203 , sizeof( V_202 ) , & V_202 ) ;
}
static void F_75 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_204 V_155 ;
T_1 V_205 , V_202 = 0x01 ;
bool V_206 ;
T_1 V_147 ;
T_6 V_168 ;
if ( F_76 ( V_6 , V_207 ) > 0 )
return;
if ( F_21 ( V_6 , V_208 ) )
F_74 ( V_153 ) ;
F_77 ( V_6 , V_208 ) ;
V_147 = F_52 ( V_6 ) ;
V_168 = F_61 ( V_6 , V_147 ) ;
V_206 = ( V_168 & V_172 ) ||
F_60 ( V_6 ) ;
if ( F_78 ( V_153 , ! V_206 , & V_205 ) < 0 )
return;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_209 = F_11 ( V_6 -> V_210 ) ;
V_155 . V_211 = F_11 ( V_6 -> V_212 ) ;
if ( V_206 )
V_155 . type = V_213 ;
else if ( F_62 ( V_6 ) )
V_155 . type = V_214 ;
else
V_155 . type = V_215 ;
V_155 . V_216 = V_205 ;
V_155 . V_217 = V_6 -> V_218 ;
F_57 ( V_153 , V_219 , sizeof( V_155 ) , & V_155 ) ;
F_57 ( V_153 , V_203 , sizeof( V_202 ) , & V_202 ) ;
}
static void F_79 ( struct V_220 * V_221 )
{
struct V_5 * V_6 = F_80 ( V_221 , struct V_5 ,
V_222 . V_221 ) ;
struct V_152 V_153 ;
if ( ! F_81 ( V_6 , V_193 ) )
return;
F_67 ( & V_153 , V_6 ) ;
F_35 ( V_6 ) ;
F_70 ( & V_153 ) ;
F_73 ( & V_153 ) ;
F_36 ( V_6 ) ;
F_68 ( & V_153 , NULL ) ;
}
static void F_82 ( struct V_220 * V_221 )
{
struct V_5 * V_6 = F_80 ( V_221 , struct V_5 ,
F_82 . V_221 ) ;
struct V_152 V_153 ;
F_10 ( L_5 ) ;
F_83 ( V_6 , V_223 ) ;
if ( ! F_21 ( V_6 , V_117 ) )
return;
F_67 ( & V_153 , V_6 ) ;
F_75 ( & V_153 ) ;
F_68 ( & V_153 , NULL ) ;
}
static void F_84 ( struct V_11 * V_19 , struct V_5 * V_6 )
{
if ( F_85 ( V_6 , V_224 ) )
return;
F_86 ( & V_6 -> V_222 , F_79 ) ;
F_86 ( & V_6 -> F_82 , F_82 ) ;
F_77 ( V_6 , V_111 ) ;
}
static int F_87 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_225 V_22 ;
F_10 ( L_3 , V_19 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_88 ( & V_22 . V_122 , & V_6 -> V_122 ) ;
V_22 . V_23 = V_6 -> V_95 ;
V_22 . V_84 = F_11 ( V_6 -> V_84 ) ;
V_22 . V_226 = F_31 ( F_37 ( V_6 ) ) ;
V_22 . V_227 = F_31 ( F_42 ( V_6 ) ) ;
memcpy ( V_22 . V_200 , V_6 -> V_200 , 3 ) ;
memcpy ( V_22 . V_83 , V_6 -> V_142 , sizeof( V_6 -> V_142 ) ) ;
memcpy ( V_22 . V_228 , V_6 -> V_228 , sizeof( V_6 -> V_228 ) ) ;
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_229 , 0 , & V_22 ,
sizeof( V_22 ) ) ;
}
static int F_89 ( struct V_11 * V_19 , T_2 V_41 , struct V_5 * V_6 )
{
T_5 V_89 = F_31 ( F_42 ( V_6 ) ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_41 , 0 , & V_89 ,
sizeof( V_89 ) ) ;
}
static void F_90 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
F_10 ( L_6 , V_6 -> V_83 , V_230 ) ;
if ( F_91 ( V_6 ) == 0 ) {
F_92 ( & V_6 -> V_231 ) ;
F_93 ( V_6 -> V_232 , & V_6 -> V_231 . V_221 ) ;
}
}
static bool F_94 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_233 V_155 ;
struct V_234 * V_235 ;
switch ( V_6 -> V_236 . V_237 ) {
case V_238 :
if ( F_23 ( V_239 , & V_6 -> V_168 ) )
F_57 ( V_153 , V_240 , 0 , NULL ) ;
if ( F_21 ( V_6 , V_241 ) ) {
F_92 ( & V_6 -> V_242 ) ;
F_95 ( V_153 ) ;
}
return true ;
case V_243 :
V_235 = F_96 ( V_6 , V_76 ,
V_244 ) ;
if ( ! V_235 )
break;
F_88 ( & V_155 . V_122 , & V_235 -> V_7 . V_122 ) ;
F_57 ( V_153 , V_245 , sizeof( V_155 ) ,
& V_155 ) ;
return true ;
default:
if ( F_21 ( V_6 , V_241 ) ) {
F_95 ( V_153 ) ;
return true ;
}
break;
}
return false ;
}
static void F_97 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_1 V_147 )
{
struct V_246 V_247 ;
V_247 . V_147 = V_147 ;
F_7 ( V_248 , V_6 , & V_247 , sizeof( V_247 ) , V_19 ) ;
}
static void F_98 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_1 V_147 )
{
struct V_249 V_247 ;
V_247 . V_147 = V_147 ;
F_7 ( V_250 , V_6 , & V_247 , sizeof( V_247 ) , V_19 ) ;
}
static int F_99 ( struct V_152 * V_153 , T_1 V_147 ,
bool V_251 ) {
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_148 * V_149 = NULL ;
T_2 V_252 ;
if ( F_21 ( V_6 , V_117 ) ||
! F_21 ( V_6 , V_138 ) )
return - V_253 ;
if ( V_6 -> V_254 )
return - V_255 ;
V_149 = F_55 ( V_6 , V_147 ) ;
if ( ! V_149 )
return - V_256 ;
if ( V_149 -> V_252 == 0 ||
V_149 -> V_257 <= V_149 -> V_258 )
V_252 = V_149 -> V_257 ;
else
V_252 = V_149 -> V_258 ;
if ( V_149 -> V_252 )
V_149 -> V_258 =
V_149 -> V_258 - V_252 ;
V_6 -> V_254 = V_252 ;
F_100 ( V_6 -> V_259 ,
& V_6 -> V_260 ,
F_101 ( V_252 * 1000 ) ) ;
if ( ! V_251 && V_6 -> V_139 == V_147 &&
F_21 ( V_6 , V_208 ) )
return 0 ;
V_6 -> V_139 = V_147 ;
F_65 ( V_153 ) ;
F_58 ( V_153 ) ;
F_75 ( V_153 ) ;
return 0 ;
}
static void F_102 ( struct V_5 * V_6 )
{
if ( V_6 -> V_254 ) {
V_6 -> V_254 = 0 ;
F_92 ( & V_6 -> V_260 ) ;
}
}
static void F_103 ( struct V_5 * V_6 , struct V_152 * V_153 ,
T_1 V_147 , bool V_251 )
{
struct V_148 * V_149 , * V_261 , * V_262 = NULL ;
int V_34 ;
T_1 V_263 ;
if ( ! V_147 || V_6 -> V_139 == V_147 )
F_102 ( V_6 ) ;
if ( V_147 && V_6 -> V_139 == V_147 )
V_262 = F_104 ( V_6 , V_147 ) ;
if ( V_147 == 0x00 ) {
F_105 (adv_instance, n, &hdev->adv_instances,
list) {
if ( ! ( V_251 || V_149 -> V_252 ) )
continue;
V_263 = V_149 -> V_147 ;
V_34 = F_106 ( V_6 , V_263 ) ;
if ( ! V_34 )
F_98 ( NULL , V_6 , V_263 ) ;
}
V_6 -> V_139 = 0x00 ;
} else {
V_149 = F_55 ( V_6 , V_147 ) ;
if ( V_251 || ( V_149 && V_149 -> V_252 &&
! V_149 -> V_258 ) ) {
if ( V_262 &&
V_262 -> V_147 == V_147 )
V_262 = NULL ;
V_34 = F_106 ( V_6 , V_147 ) ;
if ( ! V_34 )
F_98 ( NULL , V_6 , V_147 ) ;
}
}
if ( F_107 ( & V_6 -> V_264 ) ) {
V_6 -> V_139 = 0x00 ;
F_77 ( V_6 , V_138 ) ;
}
if ( ! V_153 || ! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) )
return;
if ( V_262 )
F_99 ( V_153 , V_262 -> V_147 , false ) ;
}
static int F_108 ( struct V_5 * V_6 )
{
struct V_152 V_153 ;
struct V_265 * V_266 ;
bool V_267 ;
int V_34 ;
F_67 ( & V_153 , V_6 ) ;
if ( F_23 ( V_268 , & V_6 -> V_168 ) ||
F_23 ( V_269 , & V_6 -> V_168 ) ) {
T_1 V_270 = 0x00 ;
F_57 ( & V_153 , V_271 , 1 , & V_270 ) ;
}
F_103 ( V_6 , NULL , 0x00 , false ) ;
if ( F_21 ( V_6 , V_208 ) )
F_74 ( & V_153 ) ;
V_267 = F_94 ( & V_153 ) ;
F_20 (conn, &hdev->conn_hash.list, list) {
F_109 ( & V_153 , V_266 , 0x15 ) ;
}
V_34 = F_68 ( & V_153 , F_90 ) ;
if ( ! V_34 && V_267 )
F_110 ( V_6 , V_272 ) ;
return V_34 ;
}
static int F_111 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_273 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( F_48 ( V_273 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_273 ,
V_275 ) ;
goto V_276;
}
if ( F_81 ( V_6 , V_277 ) ) {
F_92 ( & V_6 -> V_231 ) ;
if ( V_155 -> V_163 ) {
F_113 ( V_19 , V_273 , V_6 ,
V_7 , V_8 ) ;
V_34 = F_114 ( V_6 , 1 ) ;
goto V_276;
}
}
if ( ! ! V_155 -> V_163 == F_43 ( V_6 ) ) {
V_34 = F_89 ( V_19 , V_273 , V_6 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_273 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
if ( V_155 -> V_163 ) {
F_93 ( V_6 -> V_232 , & V_6 -> V_278 ) ;
V_34 = 0 ;
} else {
V_34 = F_108 ( V_6 ) ;
if ( ! V_34 )
F_100 ( V_6 -> V_232 , & V_6 -> V_231 ,
V_279 ) ;
if ( V_34 == - V_280 ) {
F_92 ( & V_6 -> V_231 ) ;
F_93 ( V_6 -> V_232 , & V_6 -> V_231 . V_221 ) ;
V_34 = 0 ;
}
}
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_115 ( struct V_5 * V_6 , struct V_11 * V_80 )
{
T_5 V_247 = F_31 ( F_42 ( V_6 ) ) ;
return F_6 ( V_281 , V_6 , & V_247 ,
sizeof( V_247 ) , V_80 ) ;
}
int F_116 ( struct V_5 * V_6 )
{
return F_115 ( V_6 , NULL ) ;
}
static void F_117 ( struct V_137 * V_159 , void * V_7 )
{
struct V_282 * V_283 = V_7 ;
F_89 ( V_159 -> V_19 , V_159 -> V_41 , V_283 -> V_6 ) ;
F_118 ( & V_159 -> V_284 ) ;
if ( V_283 -> V_19 == NULL ) {
V_283 -> V_19 = V_159 -> V_19 ;
F_119 ( V_283 -> V_19 ) ;
}
F_120 ( V_159 ) ;
}
static void F_121 ( struct V_137 * V_159 , void * V_7 )
{
T_1 * V_230 = V_7 ;
F_112 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , * V_230 ) ;
F_122 ( V_159 ) ;
}
static void F_123 ( struct V_137 * V_159 , void * V_7 )
{
if ( V_159 -> V_285 ) {
T_1 * V_230 = V_7 ;
V_159 -> V_285 ( V_159 , * V_230 ) ;
F_122 ( V_159 ) ;
return;
}
F_121 ( V_159 , V_7 ) ;
}
static int F_124 ( struct V_137 * V_159 , T_1 V_230 )
{
return F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_230 ,
V_159 -> V_162 , V_159 -> V_286 ) ;
}
static int F_125 ( struct V_137 * V_159 , T_1 V_230 )
{
return F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_230 ,
V_159 -> V_162 , sizeof( struct V_287 ) ) ;
}
static T_1 F_126 ( struct V_5 * V_6 )
{
if ( ! F_38 ( V_6 ) )
return V_288 ;
else if ( ! F_21 ( V_6 , V_112 ) )
return V_289 ;
else
return V_290 ;
}
static T_1 F_127 ( struct V_5 * V_6 )
{
if ( ! F_41 ( V_6 ) )
return V_288 ;
else if ( ! F_21 ( V_6 , V_113 ) )
return V_289 ;
else
return V_290 ;
}
static void F_128 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_137 * V_159 ;
struct V_161 * V_155 ;
struct V_152 V_153 ;
bool V_291 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_160 , V_6 ) ;
if ( ! V_159 )
goto V_292;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
F_112 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_293 ) ;
F_77 ( V_6 , V_166 ) ;
goto V_294;
}
V_155 = V_159 -> V_162 ;
if ( V_155 -> V_163 ) {
V_291 = ! F_85 ( V_6 , V_110 ) ;
if ( V_6 -> V_295 > 0 ) {
int V_296 = F_101 ( V_6 -> V_295 * 1000 ) ;
F_100 ( V_6 -> V_259 , & V_6 -> V_297 ,
V_296 ) ;
}
} else {
V_291 = F_81 ( V_6 , V_110 ) ;
}
F_89 ( V_159 -> V_19 , V_160 , V_6 ) ;
if ( V_291 )
F_115 ( V_6 , V_159 -> V_19 ) ;
F_67 ( & V_153 , V_6 ) ;
F_129 ( & V_153 ) ;
F_73 ( & V_153 ) ;
F_68 ( & V_153 , NULL ) ;
V_294:
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_130 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_298 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
T_2 V_252 ;
T_1 V_270 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_21 ( V_6 , V_113 ) &&
! F_21 ( V_6 , V_112 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_160 ,
V_289 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 && V_155 -> V_163 != 0x02 )
return F_112 ( V_19 , V_6 -> V_59 , V_160 ,
V_274 ) ;
V_252 = F_131 ( V_155 -> V_252 ) ;
if ( ( V_155 -> V_163 == 0x00 && V_252 > 0 ) ||
( V_155 -> V_163 == 0x02 && V_252 == 0 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_160 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) && V_252 > 0 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_160 ,
V_299 ) ;
goto V_276;
}
if ( F_48 ( V_160 , V_6 ) ||
F_48 ( V_167 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_160 ,
V_275 ) ;
goto V_276;
}
if ( ! F_21 ( V_6 , V_108 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_160 ,
V_289 ) ;
goto V_276;
}
if ( ! F_43 ( V_6 ) ) {
bool V_291 = false ;
if ( ! ! V_155 -> V_163 != F_21 ( V_6 , V_110 ) ) {
F_132 ( V_6 , V_110 ) ;
V_291 = true ;
}
V_34 = F_89 ( V_19 , V_160 , V_6 ) ;
if ( V_34 < 0 )
goto V_276;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_276;
}
if ( ! ! V_155 -> V_163 == F_21 ( V_6 , V_110 ) &&
( V_155 -> V_163 == 0x02 ) == F_21 ( V_6 ,
V_166 ) ) {
F_92 ( & V_6 -> V_297 ) ;
V_6 -> V_295 = V_252 ;
if ( V_155 -> V_163 && V_6 -> V_295 > 0 ) {
int V_296 = F_101 ( V_6 -> V_295 * 1000 ) ;
F_100 ( V_6 -> V_259 , & V_6 -> V_297 ,
V_296 ) ;
}
V_34 = F_89 ( V_19 , V_160 , V_6 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_160 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
F_92 ( & V_6 -> V_297 ) ;
V_6 -> V_295 = V_252 ;
if ( V_155 -> V_163 == 0x02 )
F_83 ( V_6 , V_166 ) ;
else
F_77 ( V_6 , V_166 ) ;
F_67 ( & V_153 , V_6 ) ;
if ( ! F_21 ( V_6 , V_112 ) )
goto V_300;
V_270 = V_301 ;
if ( V_155 -> V_163 ) {
struct V_302 V_303 ;
if ( V_155 -> V_163 == 0x02 ) {
V_303 . V_304 = F_133 ( T_1 , V_6 -> V_304 , 2 ) ;
V_303 . V_305 [ 0 ] = 0x00 ;
V_303 . V_305 [ 1 ] = 0x8b ;
V_303 . V_305 [ 2 ] = 0x9e ;
V_303 . V_305 [ 3 ] = 0x33 ;
V_303 . V_305 [ 4 ] = 0x8b ;
V_303 . V_305 [ 5 ] = 0x9e ;
} else {
V_303 . V_304 = 1 ;
V_303 . V_305 [ 0 ] = 0x33 ;
V_303 . V_305 [ 1 ] = 0x8b ;
V_303 . V_305 [ 2 ] = 0x9e ;
}
F_57 ( & V_153 , V_306 ,
( V_303 . V_304 * 3 ) + 1 , & V_303 ) ;
V_270 |= V_307 ;
} else {
F_77 ( V_6 , V_166 ) ;
}
F_57 ( & V_153 , V_271 , sizeof( V_270 ) , & V_270 ) ;
V_300:
F_65 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_128 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_134 ( struct V_152 * V_153 , bool V_202 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_308 V_309 ;
T_1 type ;
if ( ! F_21 ( V_6 , V_112 ) )
return;
if ( V_6 -> V_95 < V_96 )
return;
if ( V_202 ) {
type = V_310 ;
V_309 . V_311 = F_11 ( 0x0100 ) ;
} else {
type = V_312 ;
V_309 . V_311 = F_11 ( 0x0800 ) ;
}
V_309 . V_313 = F_11 ( 0x0012 ) ;
if ( F_135 ( V_6 -> V_314 ) != V_309 . V_311 ||
F_135 ( V_6 -> V_315 ) != V_309 . V_313 )
F_57 ( V_153 , V_316 ,
sizeof( V_309 ) , & V_309 ) ;
if ( V_6 -> V_317 != type )
F_57 ( V_153 , V_318 , 1 , & type ) ;
}
static void F_136 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_137 * V_159 ;
struct V_161 * V_155 ;
bool V_319 , V_320 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_167 , V_6 ) ;
if ( ! V_159 )
goto V_292;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
F_112 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_293 ) ;
goto V_294;
}
V_155 = V_159 -> V_162 ;
if ( V_155 -> V_163 ) {
V_319 = ! F_85 ( V_6 ,
V_108 ) ;
V_320 = false ;
} else {
V_319 = F_81 ( V_6 ,
V_108 ) ;
V_320 = F_81 ( V_6 ,
V_110 ) ;
}
F_89 ( V_159 -> V_19 , V_167 , V_6 ) ;
if ( V_319 || V_320 ) {
F_115 ( V_6 , V_159 -> V_19 ) ;
F_137 ( V_6 ) ;
if ( V_320 )
F_66 ( V_6 ) ;
F_138 ( V_6 ) ;
}
V_294:
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_139 ( struct V_5 * V_6 ,
struct V_11 * V_19 , T_1 V_163 )
{
bool V_291 = false ;
int V_34 ;
if ( ! ! V_163 != F_21 ( V_6 , V_108 ) )
V_291 = true ;
if ( V_163 ) {
F_83 ( V_6 , V_108 ) ;
} else {
F_77 ( V_6 , V_108 ) ;
F_77 ( V_6 , V_110 ) ;
}
V_34 = F_89 ( V_19 , V_167 , V_6 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_291 ) {
F_137 ( V_6 ) ;
F_138 ( V_6 ) ;
return F_115 ( V_6 , V_19 ) ;
}
return 0 ;
}
static int F_140 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
T_1 V_270 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_21 ( V_6 , V_113 ) &&
! F_21 ( V_6 , V_112 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_167 ,
V_289 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_167 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_139 ( V_6 , V_19 , V_155 -> V_163 ) ;
goto V_276;
}
if ( F_48 ( V_160 , V_6 ) ||
F_48 ( V_167 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_167 ,
V_275 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_167 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
F_67 ( & V_153 , V_6 ) ;
if ( ! F_21 ( V_6 , V_112 ) ) {
if ( ! V_155 -> V_163 ) {
F_77 ( V_6 , V_166 ) ;
F_77 ( V_6 , V_110 ) ;
}
F_65 ( & V_153 ) ;
} else if ( V_155 -> V_163 != F_23 ( V_269 , & V_6 -> V_168 ) ) {
if ( V_155 -> V_163 ) {
V_270 = V_301 ;
} else {
if ( F_107 ( & V_6 -> V_321 ) )
V_270 = V_322 ;
else if ( F_23 ( V_268 , & V_6 -> V_168 ) )
V_270 = V_301 ;
else
goto V_323;
if ( F_23 ( V_268 , & V_6 -> V_168 ) &&
V_6 -> V_295 > 0 )
F_92 ( & V_6 -> V_297 ) ;
}
F_57 ( & V_153 , V_271 , 1 , & V_270 ) ;
}
V_323:
if ( F_21 ( V_6 , V_117 ) ||
F_21 ( V_6 , V_138 ) )
F_75 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_136 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
if ( V_34 == - V_280 )
V_34 = F_139 ( V_6 , V_19 ,
V_155 -> V_163 ) ;
goto V_276;
}
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_141 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
bool V_291 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_324 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( V_155 -> V_163 )
V_291 = ! F_85 ( V_6 , V_111 ) ;
else
V_291 = F_81 ( V_6 , V_111 ) ;
V_34 = F_89 ( V_19 , V_324 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_142 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
T_1 V_163 , V_230 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
V_230 = F_126 ( V_6 ) ;
if ( V_230 )
return F_112 ( V_19 , V_6 -> V_59 , V_325 ,
V_230 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_325 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_291 = false ;
if ( ! ! V_155 -> V_163 != F_21 ( V_6 , V_114 ) ) {
F_132 ( V_6 , V_114 ) ;
V_291 = true ;
}
V_34 = F_89 ( V_19 , V_325 , V_6 ) ;
if ( V_34 < 0 )
goto V_276;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_276;
}
if ( F_48 ( V_325 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_325 ,
V_275 ) ;
goto V_276;
}
V_163 = ! ! V_155 -> V_163 ;
if ( F_23 ( V_326 , & V_6 -> V_168 ) == V_163 ) {
V_34 = F_89 ( V_19 , V_325 , V_6 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_325 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
V_34 = F_143 ( V_6 , V_327 , sizeof( V_163 ) , & V_163 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
goto V_276;
}
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_144 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
V_230 = F_126 ( V_6 ) ;
if ( V_230 )
return F_112 ( V_19 , V_6 -> V_59 , V_328 , V_230 ) ;
if ( ! F_39 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_328 ,
V_288 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_328 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
bool V_291 ;
if ( V_155 -> V_163 ) {
V_291 = ! F_85 ( V_6 ,
V_115 ) ;
} else {
V_291 = F_81 ( V_6 ,
V_115 ) ;
if ( ! V_291 )
V_291 = F_81 ( V_6 ,
V_116 ) ;
else
F_77 ( V_6 , V_116 ) ;
}
V_34 = F_89 ( V_19 , V_328 , V_6 ) ;
if ( V_34 < 0 )
goto V_276;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_276;
}
if ( F_48 ( V_328 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_328 ,
V_275 ) ;
goto V_276;
}
if ( ! ! V_155 -> V_163 == F_21 ( V_6 , V_115 ) ) {
V_34 = F_89 ( V_19 , V_328 , V_6 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_328 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
if ( ! V_155 -> V_163 && F_21 ( V_6 , V_329 ) )
F_143 ( V_6 , V_330 ,
sizeof( V_155 -> V_163 ) , & V_155 -> V_163 ) ;
V_34 = F_143 ( V_6 , V_331 , 1 , & V_155 -> V_163 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
goto V_276;
}
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_145 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
bool V_291 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
V_230 = F_126 ( V_6 ) ;
if ( V_230 )
return F_112 ( V_19 , V_6 -> V_59 , V_332 , V_230 ) ;
if ( ! F_39 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_332 ,
V_288 ) ;
if ( ! F_21 ( V_6 , V_115 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_332 ,
V_289 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_332 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( F_48 ( V_328 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_332 ,
V_275 ) ;
goto V_292;
}
if ( V_155 -> V_163 ) {
V_291 = ! F_85 ( V_6 , V_116 ) ;
} else {
if ( F_43 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_332 ,
V_289 ) ;
goto V_292;
}
V_291 = F_81 ( V_6 , V_116 ) ;
}
V_34 = F_89 ( V_19 , V_332 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_146 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_282 V_283 = { NULL , V_6 } ;
F_35 ( V_6 ) ;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
F_147 ( V_333 , V_6 , F_121 ,
& V_293 ) ;
goto V_292;
}
F_147 ( V_333 , V_6 , F_117 , & V_283 ) ;
F_115 ( V_6 , V_283 . V_19 ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
if ( F_21 ( V_6 , V_113 ) ) {
struct V_152 V_153 ;
F_67 ( & V_153 , V_6 ) ;
F_65 ( & V_153 ) ;
F_58 ( & V_153 ) ;
F_149 ( & V_153 ) ;
F_68 ( & V_153 , NULL ) ;
}
V_292:
F_36 ( V_6 ) ;
}
static int F_150 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_334 V_303 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
T_1 V_163 , V_335 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_333 ,
V_288 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_333 ,
V_274 ) ;
if ( ! F_21 ( V_6 , V_112 ) ) {
if ( V_155 -> V_163 == 0x01 )
return F_89 ( V_19 , V_333 , V_6 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_333 ,
V_289 ) ;
}
F_35 ( V_6 ) ;
V_163 = ! ! V_155 -> V_163 ;
V_335 = F_151 ( V_6 ) ;
if ( ! V_163 )
F_103 ( V_6 , NULL , 0x00 , true ) ;
if ( ! F_43 ( V_6 ) || V_163 == V_335 ) {
bool V_291 = false ;
if ( V_163 != F_21 ( V_6 , V_113 ) ) {
F_132 ( V_6 , V_113 ) ;
V_291 = true ;
}
if ( ! V_163 && F_21 ( V_6 , V_117 ) ) {
F_77 ( V_6 , V_117 ) ;
V_291 = true ;
}
V_34 = F_89 ( V_19 , V_333 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_292;
}
if ( F_48 ( V_333 , V_6 ) ||
F_48 ( V_336 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_333 ,
V_275 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_333 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
memset ( & V_303 , 0 , sizeof( V_303 ) ) ;
if ( V_163 ) {
V_303 . V_337 = V_163 ;
V_303 . V_338 = 0x00 ;
} else {
if ( F_21 ( V_6 , V_208 ) )
F_74 ( & V_153 ) ;
}
F_57 ( & V_153 , V_339 , sizeof( V_303 ) ,
& V_303 ) ;
V_34 = F_68 ( & V_153 , F_146 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_152 ( struct V_5 * V_6 )
{
struct V_137 * V_159 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
switch ( V_159 -> V_41 ) {
case V_340 :
case V_341 :
case V_342 :
case V_273 :
return true ;
}
}
return false ;
}
static T_1 F_153 ( const T_1 * V_127 )
{
T_6 V_163 ;
if ( memcmp ( V_127 , V_343 , 12 ) )
return 128 ;
V_163 = F_154 ( & V_127 [ 12 ] ) ;
if ( V_163 > 0xffff )
return 32 ;
return 16 ;
}
static void F_155 ( struct V_5 * V_6 , T_2 V_344 , T_1 V_230 )
{
struct V_137 * V_159 ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_344 , V_6 ) ;
if ( ! V_159 )
goto V_292;
F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 ,
F_1 ( V_230 ) , V_6 -> V_200 , 3 ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static void F_156 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
F_10 ( L_8 , V_230 ) ;
F_155 ( V_6 , V_340 , V_230 ) ;
}
static int F_157 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_345 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
struct V_126 * V_127 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_152 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_340 ,
V_275 ) ;
goto V_276;
}
V_127 = F_15 ( sizeof( * V_127 ) , V_39 ) ;
if ( ! V_127 ) {
V_34 = - V_40 ;
goto V_276;
}
memcpy ( V_127 -> V_127 , V_155 -> V_127 , 16 ) ;
V_127 -> V_196 = V_155 -> V_196 ;
V_127 -> V_129 = F_153 ( V_155 -> V_127 ) ;
F_158 ( & V_127 -> V_284 , & V_6 -> V_346 ) ;
F_67 ( & V_153 , V_6 ) ;
F_73 ( & V_153 ) ;
F_70 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_156 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_280 )
goto V_276;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_340 , 0 ,
V_6 -> V_200 , 3 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_340 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
V_34 = 0 ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_159 ( struct V_5 * V_6 )
{
if ( ! F_43 ( V_6 ) )
return false ;
if ( ! F_85 ( V_6 , V_193 ) ) {
F_100 ( V_6 -> V_259 , & V_6 -> V_222 ,
V_347 ) ;
return true ;
}
return false ;
}
static void F_160 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
F_10 ( L_8 , V_230 ) ;
F_155 ( V_6 , V_341 , V_230 ) ;
}
static int F_161 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_348 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_126 * V_283 , * V_349 ;
T_1 V_350 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_152 V_153 ;
int V_34 , V_351 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( F_152 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_341 ,
V_275 ) ;
goto V_292;
}
if ( memcmp ( V_155 -> V_127 , V_350 , 16 ) == 0 ) {
F_162 ( V_6 ) ;
if ( F_159 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_341 ,
0 , V_6 -> V_200 , 3 ) ;
goto V_292;
}
goto F_73;
}
V_351 = 0 ;
F_105 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_283 -> V_127 , V_155 -> V_127 , 16 ) != 0 )
continue;
F_118 ( & V_283 -> V_284 ) ;
F_17 ( V_283 ) ;
V_351 ++ ;
}
if ( V_351 == 0 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_341 ,
V_274 ) ;
goto V_292;
}
F_73:
F_67 ( & V_153 , V_6 ) ;
F_73 ( & V_153 ) ;
F_70 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_160 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_280 )
goto V_292;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_341 , 0 ,
V_6 -> V_200 , 3 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_341 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_34 = 0 ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_163 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
F_10 ( L_8 , V_230 ) ;
F_155 ( V_6 , V_342 , V_230 ) ;
}
static int F_164 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_352 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_342 ,
V_288 ) ;
F_35 ( V_6 ) ;
if ( F_152 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_342 ,
V_275 ) ;
goto V_292;
}
if ( ( V_155 -> V_353 & 0x03 ) != 0 || ( V_155 -> V_354 & 0xe0 ) != 0 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_342 ,
V_274 ) ;
goto V_292;
}
V_6 -> V_199 = V_155 -> V_354 ;
V_6 -> V_198 = V_155 -> V_353 ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_342 , 0 ,
V_6 -> V_200 , 3 ) ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
if ( F_81 ( V_6 , V_193 ) ) {
F_36 ( V_6 ) ;
F_165 ( & V_6 -> V_222 ) ;
F_35 ( V_6 ) ;
F_70 ( & V_153 ) ;
}
F_73 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_163 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_280 )
goto V_292;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_342 , 0 ,
V_6 -> V_200 , 3 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_342 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_34 = 0 ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_166 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_355 * V_155 = V_7 ;
const T_2 V_356 = ( ( V_357 - sizeof( * V_155 ) ) /
sizeof( struct V_358 ) ) ;
T_2 V_359 , V_360 ;
bool V_291 ;
int V_33 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_361 ,
V_288 ) ;
V_359 = F_131 ( V_155 -> V_359 ) ;
if ( V_359 > V_356 ) {
F_167 ( L_9 ,
V_359 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_361 ,
V_274 ) ;
}
V_360 = sizeof( * V_155 ) + V_359 *
sizeof( struct V_358 ) ;
if ( V_360 != V_8 ) {
F_167 ( L_10 ,
V_360 , V_8 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_361 ,
V_274 ) ;
}
if ( V_155 -> V_362 != 0x00 && V_155 -> V_362 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_361 ,
V_274 ) ;
F_10 ( L_11 , V_6 -> V_83 , V_155 -> V_362 ,
V_359 ) ;
for ( V_33 = 0 ; V_33 < V_359 ; V_33 ++ ) {
struct V_358 * V_363 = & V_155 -> V_364 [ V_33 ] ;
if ( V_363 -> V_365 . type != V_366 || V_363 -> type > 0x08 )
return F_112 ( V_19 , V_6 -> V_59 ,
V_361 ,
V_274 ) ;
}
F_35 ( V_6 ) ;
F_168 ( V_6 ) ;
if ( V_155 -> V_362 )
V_291 = ! F_85 ( V_6 , V_119 ) ;
else
V_291 = F_81 ( V_6 ,
V_119 ) ;
if ( V_291 )
F_115 ( V_6 , NULL ) ;
for ( V_33 = 0 ; V_33 < V_359 ; V_33 ++ ) {
struct V_358 * V_363 = & V_155 -> V_364 [ V_33 ] ;
if ( V_363 -> type == V_367 )
continue;
F_169 ( V_6 , NULL , & V_363 -> V_365 . V_122 , V_363 -> V_163 ,
V_363 -> type , V_363 -> V_368 , NULL ) ;
}
F_12 ( V_19 , V_6 -> V_59 , V_361 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return 0 ;
}
static int F_170 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_369 , struct V_11 * V_12 )
{
struct V_370 V_247 ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = V_369 ;
return F_7 ( V_371 , V_6 , & V_247 , sizeof( V_247 ) ,
V_12 ) ;
}
static int F_171 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_372 * V_155 = V_7 ;
struct V_373 V_22 ;
struct V_374 * V_375 ;
struct V_137 * V_159 ;
struct V_265 * V_266 ;
T_1 V_369 ;
int V_34 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_88 ( & V_22 . V_365 . V_122 , & V_155 -> V_365 . V_122 ) ;
V_22 . V_365 . type = V_155 -> V_365 . type ;
if ( ! F_172 ( V_155 -> V_365 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_376 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_155 -> V_377 != 0x00 && V_155 -> V_377 != 0x01 )
return F_12 ( V_19 , V_6 -> V_59 , V_376 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_376 ,
V_299 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
if ( V_155 -> V_365 . type == V_366 ) {
if ( V_155 -> V_377 )
V_266 = F_173 ( V_6 , V_378 ,
& V_155 -> V_365 . V_122 ) ;
else
V_266 = NULL ;
V_34 = F_174 ( V_6 , & V_155 -> V_365 . V_122 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_376 ,
V_379 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
goto V_380;
}
V_369 = F_8 ( V_155 -> V_365 . type ) ;
F_175 ( V_6 , & V_155 -> V_365 . V_122 , V_369 ) ;
V_34 = F_176 ( V_6 , & V_155 -> V_365 . V_122 , V_369 ) ;
if ( V_34 < 0 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_376 ,
V_379 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
V_266 = F_177 ( V_6 , & V_155 -> V_365 . V_122 , V_369 ) ;
if ( ! V_266 ) {
F_178 ( V_6 , & V_155 -> V_365 . V_122 , V_369 ) ;
goto V_380;
}
F_179 ( V_266 ) ;
F_180 ( V_381 , & V_266 -> V_168 ) ;
V_375 = F_181 ( V_6 , & V_155 -> V_365 . V_122 , V_369 ) ;
if ( V_375 ) {
if ( V_375 -> V_382 )
V_375 -> V_383 = V_384 ;
else
V_375 -> V_383 = V_385 ;
}
if ( ! V_155 -> V_377 )
V_266 = NULL ;
V_380:
if ( ! V_266 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_376 , 0 ,
& V_22 , sizeof( V_22 ) ) ;
F_170 ( V_6 , & V_155 -> V_365 . V_122 , V_155 -> V_365 . type , V_19 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_376 , V_6 , V_155 ,
sizeof( * V_155 ) ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_159 -> V_285 = F_125 ;
V_34 = F_182 ( V_266 , V_386 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int V_377 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_387 * V_155 = V_7 ;
struct V_388 V_22 ;
struct V_137 * V_159 ;
struct V_265 * V_266 ;
int V_34 ;
F_10 ( L_5 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_88 ( & V_22 . V_365 . V_122 , & V_155 -> V_365 . V_122 ) ;
V_22 . V_365 . type = V_155 -> V_365 . type ;
if ( ! F_172 ( V_155 -> V_365 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_389 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_23 ( V_390 , & V_6 -> V_168 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_389 ,
V_299 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_276;
}
if ( F_48 ( V_389 , V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_389 ,
V_275 , & V_22 , sizeof( V_22 ) ) ;
goto V_276;
}
if ( V_155 -> V_365 . type == V_366 )
V_266 = F_173 ( V_6 , V_378 ,
& V_155 -> V_365 . V_122 ) ;
else
V_266 = F_177 ( V_6 , & V_155 -> V_365 . V_122 ,
F_8 ( V_155 -> V_365 . type ) ) ;
if ( ! V_266 || V_266 -> V_237 == V_391 || V_266 -> V_237 == V_392 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_389 ,
V_393 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_389 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
V_159 -> V_285 = F_124 ;
V_34 = F_183 ( V_266 , V_386 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static T_1 F_184 ( T_1 V_394 , T_1 V_369 )
{
switch ( V_394 ) {
case V_207 :
switch ( V_369 ) {
case V_17 :
return V_16 ;
default:
return V_395 ;
}
default:
return V_366 ;
}
}
static int F_185 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_20 )
{
struct V_396 * V_22 ;
struct V_265 * V_397 ;
T_3 V_46 ;
int V_34 ;
T_2 V_33 ;
F_10 ( L_5 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_398 ,
V_299 ) ;
goto V_292;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_23 ( V_399 , & V_397 -> V_168 ) )
V_33 ++ ;
}
V_46 = sizeof( * V_22 ) + ( V_33 * sizeof( struct V_287 ) ) ;
V_22 = F_15 ( V_46 , V_39 ) ;
if ( ! V_22 ) {
V_34 = - V_40 ;
goto V_292;
}
V_33 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_23 ( V_399 , & V_397 -> V_168 ) )
continue;
F_88 ( & V_22 -> V_365 [ V_33 ] . V_122 , & V_397 -> V_400 ) ;
V_22 -> V_365 [ V_33 ] . type = F_184 ( V_397 -> type , V_397 -> V_401 ) ;
if ( V_397 -> type == V_402 || V_397 -> type == V_403 )
continue;
V_33 ++ ;
}
V_22 -> V_404 = F_11 ( V_33 ) ;
V_46 = sizeof( * V_22 ) + ( V_33 * sizeof( struct V_287 ) ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_398 , 0 , V_22 ,
V_46 ) ;
F_17 ( V_22 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_186 ( struct V_11 * V_19 , struct V_5 * V_6 ,
struct V_405 * V_155 )
{
struct V_137 * V_159 ;
int V_34 ;
V_159 = F_113 ( V_19 , V_406 , V_6 , V_155 ,
sizeof( * V_155 ) ) ;
if ( ! V_159 )
return - V_40 ;
V_34 = F_143 ( V_6 , V_407 ,
sizeof( V_155 -> V_365 . V_122 ) , & V_155 -> V_365 . V_122 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
return V_34 ;
}
static int F_187 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_265 * V_266 ;
struct V_408 * V_155 = V_7 ;
struct V_409 V_410 ;
struct V_137 * V_159 ;
int V_34 ;
F_10 ( L_5 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_411 ,
V_299 ) ;
goto V_276;
}
V_266 = F_173 ( V_6 , V_378 , & V_155 -> V_365 . V_122 ) ;
if ( ! V_266 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_411 ,
V_393 ) ;
goto V_276;
}
if ( V_266 -> V_412 == V_413 && V_155 -> V_368 != 16 ) {
struct V_405 V_414 ;
memcpy ( & V_414 . V_365 , & V_155 -> V_365 , sizeof( V_414 . V_365 ) ) ;
F_167 ( L_12 ) ;
V_34 = F_186 ( V_19 , V_6 , & V_414 ) ;
if ( V_34 >= 0 )
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_411 ,
V_274 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_411 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
V_159 -> V_285 = F_125 ;
F_88 ( & V_410 . V_122 , & V_155 -> V_365 . V_122 ) ;
V_410 . V_368 = V_155 -> V_368 ;
memcpy ( V_410 . V_415 , V_155 -> V_415 , sizeof( V_410 . V_415 ) ) ;
V_34 = F_143 ( V_6 , V_416 , sizeof( V_410 ) , & V_410 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_188 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_417 * V_155 = V_7 ;
F_10 ( L_5 ) ;
if ( V_155 -> V_418 > V_419 )
return F_12 ( V_19 , V_6 -> V_59 , V_420 ,
V_274 , NULL , 0 ) ;
F_35 ( V_6 ) ;
V_6 -> V_418 = V_155 -> V_418 ;
F_10 ( L_13 , V_6 -> V_83 ,
V_6 -> V_418 ) ;
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_420 , 0 ,
NULL , 0 ) ;
}
static struct V_137 * F_189 ( struct V_265 * V_266 )
{
struct V_5 * V_6 = V_266 -> V_6 ;
struct V_137 * V_159 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_159 -> V_41 != V_421 )
continue;
if ( V_159 -> V_422 != V_266 )
continue;
return V_159 ;
}
return NULL ;
}
static int F_190 ( struct V_137 * V_159 , T_1 V_230 )
{
struct V_423 V_22 ;
struct V_265 * V_266 = V_159 -> V_422 ;
int V_34 ;
F_88 ( & V_22 . V_365 . V_122 , & V_266 -> V_400 ) ;
V_22 . V_365 . type = F_184 ( V_266 -> type , V_266 -> V_401 ) ;
V_34 = F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_421 ,
V_230 , & V_22 , sizeof( V_22 ) ) ;
V_266 -> V_424 = NULL ;
V_266 -> V_425 = NULL ;
V_266 -> V_426 = NULL ;
F_191 ( V_266 ) ;
F_192 ( V_381 , & V_266 -> V_168 ) ;
F_193 ( V_266 ) ;
return V_34 ;
}
void F_194 ( struct V_265 * V_266 , bool V_427 )
{
T_1 V_230 = V_427 ? V_290 : V_3 ;
struct V_137 * V_159 ;
V_159 = F_189 ( V_266 ) ;
if ( V_159 ) {
V_159 -> V_285 ( V_159 , V_230 ) ;
F_122 ( V_159 ) ;
}
}
static void F_195 ( struct V_265 * V_266 , T_1 V_230 )
{
struct V_137 * V_159 ;
F_10 ( L_14 , V_230 ) ;
V_159 = F_189 ( V_266 ) ;
if ( ! V_159 ) {
F_10 ( L_15 ) ;
return;
}
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
static void F_196 ( struct V_265 * V_266 , T_1 V_230 )
{
struct V_137 * V_159 ;
F_10 ( L_14 , V_230 ) ;
if ( ! V_230 )
return;
V_159 = F_189 ( V_266 ) ;
if ( ! V_159 ) {
F_10 ( L_15 ) ;
return;
}
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
static int F_197 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_428 * V_155 = V_7 ;
struct V_423 V_22 ;
struct V_137 * V_159 ;
T_1 V_429 , V_430 ;
struct V_265 * V_266 ;
int V_34 ;
F_10 ( L_5 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_88 ( & V_22 . V_365 . V_122 , & V_155 -> V_365 . V_122 ) ;
V_22 . V_365 . type = V_155 -> V_365 . type ;
if ( ! F_172 ( V_155 -> V_365 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_421 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_155 -> V_431 > V_419 )
return F_12 ( V_19 , V_6 -> V_59 , V_421 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_421 ,
V_299 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
if ( F_198 ( V_6 , & V_155 -> V_365 . V_122 , V_155 -> V_365 . type ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_421 ,
V_432 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
V_429 = V_433 ;
V_430 = V_434 ;
if ( V_155 -> V_365 . type == V_366 ) {
V_266 = F_199 ( V_6 , & V_155 -> V_365 . V_122 , V_429 ,
V_430 ) ;
} else {
T_1 V_369 = F_8 ( V_155 -> V_365 . type ) ;
struct V_374 * V_435 ;
V_435 = F_200 ( V_6 , & V_155 -> V_365 . V_122 , V_369 ) ;
if ( V_435 -> V_383 == V_384 )
V_435 -> V_383 = V_385 ;
V_266 = F_201 ( V_6 , & V_155 -> V_365 . V_122 ,
V_369 , V_429 ,
V_436 ,
V_437 ) ;
}
if ( F_202 ( V_266 ) ) {
int V_230 ;
if ( F_203 ( V_266 ) == - V_255 )
V_230 = V_275 ;
else if ( F_203 ( V_266 ) == - V_438 )
V_230 = V_288 ;
else if ( F_203 ( V_266 ) == - V_439 )
V_230 = V_289 ;
else
V_230 = V_440 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_421 ,
V_230 , & V_22 , sizeof( V_22 ) ) ;
goto V_292;
}
if ( V_266 -> V_424 ) {
F_191 ( V_266 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_421 ,
V_275 , & V_22 , sizeof( V_22 ) ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_421 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
F_191 ( V_266 ) ;
goto V_292;
}
V_159 -> V_285 = F_190 ;
if ( V_155 -> V_365 . type == V_366 ) {
V_266 -> V_424 = F_195 ;
V_266 -> V_425 = F_195 ;
V_266 -> V_426 = F_195 ;
} else {
V_266 -> V_424 = F_196 ;
V_266 -> V_425 = F_196 ;
V_266 -> V_426 = F_196 ;
}
V_266 -> V_418 = V_155 -> V_431 ;
V_159 -> V_422 = F_204 ( V_266 ) ;
if ( ( V_266 -> V_237 == V_441 || V_266 -> V_237 == V_442 ) &&
F_205 ( V_266 , V_429 , V_430 , true ) ) {
V_159 -> V_285 ( V_159 , 0 ) ;
F_122 ( V_159 ) ;
}
V_34 = 0 ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_206 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_287 * V_365 = V_7 ;
struct V_137 * V_159 ;
struct V_265 * V_266 ;
int V_34 ;
F_10 ( L_5 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_443 ,
V_299 ) ;
goto V_292;
}
V_159 = F_48 ( V_421 , V_6 ) ;
if ( ! V_159 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_443 ,
V_274 ) ;
goto V_292;
}
V_266 = V_159 -> V_422 ;
if ( F_29 ( & V_365 -> V_122 , & V_266 -> V_400 ) != 0 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_443 ,
V_274 ) ;
goto V_292;
}
V_159 -> V_285 ( V_159 , V_444 ) ;
F_122 ( V_159 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_443 , 0 ,
V_365 , sizeof( * V_365 ) ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_207 ( struct V_11 * V_19 , struct V_5 * V_6 ,
struct V_287 * V_365 , T_2 V_344 ,
T_2 V_445 , T_5 V_446 )
{
struct V_137 * V_159 ;
struct V_265 * V_266 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_344 ,
V_299 , V_365 ,
sizeof( * V_365 ) ) ;
goto V_380;
}
if ( V_365 -> type == V_366 )
V_266 = F_173 ( V_6 , V_378 , & V_365 -> V_122 ) ;
else
V_266 = F_177 ( V_6 , & V_365 -> V_122 ,
F_8 ( V_365 -> type ) ) ;
if ( ! V_266 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_344 ,
V_393 , V_365 ,
sizeof( * V_365 ) ) ;
goto V_380;
}
if ( V_365 -> type == V_16 || V_365 -> type == V_395 ) {
V_34 = F_208 ( V_266 , V_344 , V_446 ) ;
if ( ! V_34 )
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_344 ,
V_290 , V_365 ,
sizeof( * V_365 ) ) ;
else
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_344 ,
V_3 , V_365 ,
sizeof( * V_365 ) ) ;
goto V_380;
}
V_159 = F_113 ( V_19 , V_344 , V_6 , V_365 , sizeof( * V_365 ) ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_380;
}
V_159 -> V_285 = F_125 ;
if ( V_445 == V_447 ) {
struct V_448 V_155 ;
F_88 ( & V_155 . V_122 , & V_365 -> V_122 ) ;
V_155 . V_446 = V_446 ;
V_34 = F_143 ( V_6 , V_445 , sizeof( V_155 ) , & V_155 ) ;
} else
V_34 = F_143 ( V_6 , V_445 , sizeof( V_365 -> V_122 ) ,
& V_365 -> V_122 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_380:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_209 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_405 * V_155 = V_7 ;
F_10 ( L_5 ) ;
return F_207 ( V_19 , V_6 , & V_155 -> V_365 ,
V_406 ,
V_407 , 0 ) ;
}
static int F_210 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_449 * V_155 = V_7 ;
F_10 ( L_5 ) ;
if ( V_8 != sizeof( * V_155 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_450 ,
V_274 ) ;
return F_207 ( V_19 , V_6 , & V_155 -> V_365 ,
V_450 ,
V_451 , 0 ) ;
}
static int F_211 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_452 * V_155 = V_7 ;
F_10 ( L_5 ) ;
return F_207 ( V_19 , V_6 , & V_155 -> V_365 ,
V_453 ,
V_454 , 0 ) ;
}
static int F_212 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_455 * V_155 = V_7 ;
F_10 ( L_5 ) ;
return F_207 ( V_19 , V_6 , & V_155 -> V_365 ,
V_456 ,
V_447 , V_155 -> V_446 ) ;
}
static int F_213 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_457 * V_155 = V_7 ;
F_10 ( L_5 ) ;
return F_207 ( V_19 , V_6 , & V_155 -> V_365 ,
V_458 ,
V_459 , 0 ) ;
}
static void F_214 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_460 V_155 ;
memcpy ( V_155 . V_83 , V_6 -> V_142 , sizeof( V_155 . V_83 ) ) ;
F_57 ( V_153 , V_461 , sizeof( V_155 ) , & V_155 ) ;
}
static void F_215 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_462 * V_155 ;
struct V_137 * V_159 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_463 , V_6 ) ;
if ( ! V_159 )
goto V_292;
V_155 = V_159 -> V_162 ;
if ( V_230 )
F_112 ( V_159 -> V_19 , V_6 -> V_59 , V_463 ,
F_1 ( V_230 ) ) ;
else
F_12 ( V_159 -> V_19 , V_6 -> V_59 , V_463 , 0 ,
V_155 , sizeof( * V_155 ) ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_216 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_462 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_5 ) ;
F_35 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_142 , V_155 -> V_83 , sizeof( V_6 -> V_142 ) ) &&
! memcmp ( V_6 -> V_228 , V_155 -> V_228 ,
sizeof( V_6 -> V_228 ) ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_463 , 0 ,
V_7 , V_8 ) ;
goto V_276;
}
memcpy ( V_6 -> V_228 , V_155 -> V_228 , sizeof( V_6 -> V_228 ) ) ;
if ( ! F_43 ( V_6 ) ) {
memcpy ( V_6 -> V_142 , V_155 -> V_83 , sizeof( V_6 -> V_142 ) ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_463 , 0 ,
V_7 , V_8 ) ;
if ( V_34 < 0 )
goto V_276;
V_34 = F_6 ( V_464 , V_6 ,
V_7 , V_8 , V_19 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_463 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
memcpy ( V_6 -> V_142 , V_155 -> V_83 , sizeof( V_6 -> V_142 ) ) ;
F_67 ( & V_153 , V_6 ) ;
if ( F_38 ( V_6 ) ) {
F_214 ( & V_153 ) ;
F_70 ( & V_153 ) ;
}
if ( F_41 ( V_6 ) )
F_58 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_215 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_217 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 , struct V_465 * V_466 )
{
struct V_467 V_468 ;
T_3 V_32 = sizeof( V_468 ) ;
struct V_137 * V_159 ;
F_10 ( L_16 , V_6 -> V_83 , V_230 ) ;
V_159 = F_48 ( V_469 , V_6 ) ;
if ( ! V_159 )
return;
if ( V_230 || ! V_466 ) {
F_112 ( V_159 -> V_19 , V_6 -> V_59 , V_469 ,
V_230 ? F_1 ( V_230 ) : V_3 ) ;
goto remove;
}
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
if ( V_41 == V_470 ) {
struct V_471 * V_22 = ( void * ) V_466 -> V_7 ;
if ( V_466 -> V_8 < sizeof( * V_22 ) ) {
F_112 ( V_159 -> V_19 , V_6 -> V_59 ,
V_469 ,
V_3 ) ;
goto remove;
}
memcpy ( V_468 . V_472 , V_22 -> V_473 , sizeof( V_22 -> V_473 ) ) ;
memcpy ( V_468 . V_474 , V_22 -> rand , sizeof( V_22 -> rand ) ) ;
V_32 -= sizeof( V_468 . V_475 ) + sizeof( V_468 . V_476 ) ;
} else {
struct V_477 * V_22 = ( void * ) V_466 -> V_7 ;
if ( V_466 -> V_8 < sizeof( * V_22 ) ) {
F_112 ( V_159 -> V_19 , V_6 -> V_59 ,
V_469 ,
V_3 ) ;
goto remove;
}
memcpy ( V_468 . V_472 , V_22 -> V_472 , sizeof( V_22 -> V_472 ) ) ;
memcpy ( V_468 . V_474 , V_22 -> V_474 , sizeof( V_22 -> V_474 ) ) ;
memcpy ( V_468 . V_475 , V_22 -> V_475 , sizeof( V_22 -> V_475 ) ) ;
memcpy ( V_468 . V_476 , V_22 -> V_476 , sizeof( V_22 -> V_476 ) ) ;
}
F_12 ( V_159 -> V_19 , V_6 -> V_59 , V_469 ,
V_290 , & V_468 , V_32 ) ;
remove:
F_122 ( V_159 ) ;
}
static int F_218 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_469 ,
V_299 ) ;
goto V_292;
}
if ( ! F_39 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_469 ,
V_288 ) ;
goto V_292;
}
if ( F_48 ( V_469 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_469 ,
V_275 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_469 , V_6 , NULL , 0 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
if ( F_219 ( V_6 ) )
F_57 ( & V_153 , V_478 , 0 , NULL ) ;
else
F_57 ( & V_153 , V_470 , 0 , NULL ) ;
V_34 = F_220 ( & V_153 , F_217 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_221 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_287 * V_365 = V_7 ;
int V_34 ;
F_10 ( L_17 , V_6 -> V_83 ) ;
if ( ! F_172 ( V_365 -> type ) )
return F_12 ( V_19 , V_6 -> V_59 ,
V_479 ,
V_274 ,
V_365 , sizeof( * V_365 ) ) ;
F_35 ( V_6 ) ;
if ( V_8 == V_480 ) {
struct V_481 * V_155 = V_7 ;
T_1 V_230 ;
if ( V_155 -> V_365 . type != V_366 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_479 ,
V_274 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
goto V_292;
}
V_34 = F_222 ( V_6 , & V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type , V_155 -> V_473 ,
V_155 -> rand , NULL , NULL ) ;
if ( V_34 < 0 )
V_230 = V_3 ;
else
V_230 = V_290 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_479 , V_230 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
} else if ( V_8 == V_482 ) {
struct V_483 * V_155 = V_7 ;
T_1 * V_474 , * V_472 , * V_476 , * V_475 ;
T_1 V_230 ;
if ( F_223 ( V_155 -> V_365 . type ) ) {
if ( memcmp ( V_155 -> V_474 , V_484 , 16 ) ||
memcmp ( V_155 -> V_472 , V_484 , 16 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_479 ,
V_274 ,
V_365 , sizeof( * V_365 ) ) ;
goto V_292;
}
V_474 = NULL ;
V_472 = NULL ;
} else {
if ( ! memcmp ( V_155 -> V_474 , V_484 , 16 ) ||
! memcmp ( V_155 -> V_472 , V_484 , 16 ) ) {
V_474 = NULL ;
V_472 = NULL ;
} else {
V_474 = V_155 -> V_474 ;
V_472 = V_155 -> V_472 ;
}
}
if ( ! memcmp ( V_155 -> V_476 , V_484 , 16 ) ||
! memcmp ( V_155 -> V_475 , V_484 , 16 ) ) {
V_476 = NULL ;
V_475 = NULL ;
} else {
V_476 = V_155 -> V_476 ;
V_475 = V_155 -> V_475 ;
}
V_34 = F_222 ( V_6 , & V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type , V_472 , V_474 ,
V_475 , V_476 ) ;
if ( V_34 < 0 )
V_230 = V_3 ;
else
V_230 = V_290 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_479 ,
V_230 , & V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
} else {
F_167 ( L_18 , V_8 ) ;
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_479 ,
V_274 ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_224 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_485 * V_155 = V_7 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( V_155 -> V_365 . type != V_366 )
return F_12 ( V_19 , V_6 -> V_59 ,
V_486 ,
V_274 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_29 ( & V_155 -> V_365 . V_122 , V_76 ) ) {
F_225 ( V_6 ) ;
V_230 = V_290 ;
goto V_380;
}
V_34 = F_226 ( V_6 , & V_155 -> V_365 . V_122 , V_155 -> V_365 . type ) ;
if ( V_34 < 0 )
V_230 = V_274 ;
else
V_230 = V_290 ;
V_380:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_486 ,
V_230 , & V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_227 ( struct V_152 * V_153 , T_1 * V_230 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_487 V_155 ;
T_1 V_488 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
* V_230 = F_126 ( V_6 ) ;
if ( * V_230 )
return false ;
if ( F_21 ( V_6 , V_239 ) ) {
* V_230 = V_275 ;
return false ;
}
F_228 ( V_6 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
memcpy ( & V_155 . V_488 , V_488 , sizeof( V_155 . V_488 ) ) ;
V_155 . V_157 = V_489 ;
F_57 ( V_153 , V_490 , sizeof( V_155 ) , & V_155 ) ;
return true ;
}
static bool F_229 ( struct V_152 * V_153 , T_2 V_311 , T_1 * V_230 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_491 V_492 ;
struct V_493 V_494 ;
T_1 V_205 ;
int V_34 ;
* V_230 = F_127 ( V_6 ) ;
if ( * V_230 )
return false ;
if ( F_21 ( V_6 , V_208 ) ) {
if ( F_230 ( V_6 ) ) {
* V_230 = V_289 ;
return false ;
}
F_102 ( V_6 ) ;
F_74 ( V_153 ) ;
}
if ( F_21 ( V_6 , V_241 ) )
F_95 ( V_153 ) ;
V_34 = F_78 ( V_153 , true , & V_205 ) ;
if ( V_34 < 0 ) {
* V_230 = V_3 ;
return false ;
}
memset ( & V_492 , 0 , sizeof( V_492 ) ) ;
V_492 . type = V_495 ;
V_492 . V_311 = F_11 ( V_311 ) ;
V_492 . V_313 = F_11 ( V_496 ) ;
V_492 . V_216 = V_205 ;
F_57 ( V_153 , V_497 , sizeof( V_492 ) ,
& V_492 ) ;
memset ( & V_494 , 0 , sizeof( V_494 ) ) ;
V_494 . V_202 = V_498 ;
V_494 . V_499 = V_500 ;
F_57 ( V_153 , V_501 , sizeof( V_494 ) ,
& V_494 ) ;
return true ;
}
static bool F_231 ( struct V_152 * V_153 , T_1 * V_230 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
switch ( V_6 -> V_236 . type ) {
case V_502 :
if ( ! F_227 ( V_153 , V_230 ) )
return false ;
break;
case V_503 :
if ( F_23 ( V_504 ,
& V_6 -> V_57 ) ) {
if ( ! F_229 ( V_153 , V_505 * 2 ,
V_230 ) )
return false ;
if ( ! F_227 ( V_153 , V_230 ) )
return false ;
return true ;
}
if ( ! F_21 ( V_6 , V_112 ) ) {
* V_230 = V_288 ;
return false ;
}
case V_506 :
if ( ! F_229 ( V_153 , V_505 , V_230 ) )
return false ;
break;
default:
* V_230 = V_274 ;
return false ;
}
return true ;
}
static void F_232 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_137 * V_159 ;
unsigned long V_252 ;
F_10 ( L_19 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_507 , V_6 ) ;
if ( ! V_159 )
V_159 = F_48 ( V_508 , V_6 ) ;
if ( V_159 ) {
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
if ( V_230 ) {
F_110 ( V_6 , V_509 ) ;
goto V_292;
}
F_110 ( V_6 , V_238 ) ;
switch ( V_6 -> V_236 . type ) {
case V_506 :
V_252 = F_101 ( V_510 ) ;
break;
case V_503 :
if ( F_23 ( V_504 , & V_6 -> V_57 ) )
V_252 = F_101 ( V_510 ) ;
else
V_252 = F_101 ( V_6 -> V_511 ) ;
break;
case V_502 :
V_252 = 0 ;
break;
default:
F_167 ( L_20 , V_6 -> V_236 . type ) ;
V_252 = 0 ;
break;
}
if ( V_252 ) {
if ( F_23 ( V_512 ,
& V_6 -> V_57 ) &&
V_6 -> V_236 . V_513 ) {
V_6 -> V_236 . V_514 = V_515 ;
V_6 -> V_236 . V_516 = V_252 ;
}
F_100 ( V_6 -> V_259 ,
& V_6 -> V_242 , V_252 ) ;
}
V_292:
F_36 ( V_6 ) ;
}
static int F_233 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_517 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_507 ,
V_299 ,
& V_155 -> type , sizeof( V_155 -> type ) ) ;
goto V_276;
}
if ( V_6 -> V_236 . V_237 != V_509 ||
F_21 ( V_6 , V_518 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_507 ,
V_275 , & V_155 -> type ,
sizeof( V_155 -> type ) ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_507 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
V_159 -> V_285 = F_124 ;
F_234 ( V_6 ) ;
V_6 -> V_236 . type = V_155 -> type ;
V_6 -> V_236 . V_519 = false ;
F_67 ( & V_153 , V_6 ) ;
if ( ! F_231 ( & V_153 , & V_230 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_507 ,
V_230 , & V_155 -> type , sizeof( V_155 -> type ) ) ;
F_122 ( V_159 ) ;
goto V_276;
}
V_34 = F_68 ( & V_153 , F_232 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
goto V_276;
}
F_110 ( V_6 , V_520 ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_235 ( struct V_137 * V_159 ,
T_1 V_230 )
{
return F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_230 ,
V_159 -> V_162 , 1 ) ;
}
static int F_236 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_521 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
const T_2 V_522 = ( ( V_357 - sizeof( * V_155 ) ) / 16 ) ;
T_2 V_523 , V_360 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_508 ,
V_299 ,
& V_155 -> type , sizeof( V_155 -> type ) ) ;
goto V_276;
}
if ( V_6 -> V_236 . V_237 != V_509 ||
F_21 ( V_6 , V_518 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_508 ,
V_275 , & V_155 -> type ,
sizeof( V_155 -> type ) ) ;
goto V_276;
}
V_523 = F_131 ( V_155 -> V_523 ) ;
if ( V_523 > V_522 ) {
F_167 ( L_21 ,
V_523 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_508 ,
V_274 , & V_155 -> type ,
sizeof( V_155 -> type ) ) ;
goto V_276;
}
V_360 = sizeof( * V_155 ) + V_523 * 16 ;
if ( V_360 != V_8 ) {
F_167 ( L_22 ,
V_360 , V_8 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_508 ,
V_274 , & V_155 -> type ,
sizeof( V_155 -> type ) ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_508 ,
V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
V_159 -> V_285 = F_235 ;
F_234 ( V_6 ) ;
V_6 -> V_236 . V_513 = true ;
V_6 -> V_236 . type = V_155 -> type ;
V_6 -> V_236 . V_524 = V_155 -> V_524 ;
V_6 -> V_236 . V_523 = V_523 ;
if ( V_523 > 0 ) {
V_6 -> V_236 . V_346 = F_237 ( V_155 -> V_346 , V_523 * 16 ,
V_39 ) ;
if ( ! V_6 -> V_236 . V_346 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_508 ,
V_3 ,
& V_155 -> type , sizeof( V_155 -> type ) ) ;
F_122 ( V_159 ) ;
goto V_276;
}
}
F_67 ( & V_153 , V_6 ) ;
if ( ! F_231 ( & V_153 , & V_230 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_508 ,
V_230 , & V_155 -> type , sizeof( V_155 -> type ) ) ;
F_122 ( V_159 ) ;
goto V_276;
}
V_34 = F_68 ( & V_153 , F_232 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
goto V_276;
}
F_110 ( V_6 , V_520 ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_238 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_137 * V_159 ;
F_10 ( L_19 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_525 , V_6 ) ;
if ( V_159 ) {
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
if ( ! V_230 )
F_110 ( V_6 , V_509 ) ;
F_36 ( V_6 ) ;
}
static int F_239 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_526 * V_527 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_240 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_525 ,
V_289 , & V_527 -> type ,
sizeof( V_527 -> type ) ) ;
goto V_292;
}
if ( V_6 -> V_236 . type != V_527 -> type ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_525 ,
V_274 ,
& V_527 -> type , sizeof( V_527 -> type ) ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_525 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_159 -> V_285 = F_124 ;
F_67 ( & V_153 , V_6 ) ;
F_94 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_238 ) ;
if ( ! V_34 ) {
F_110 ( V_6 , V_272 ) ;
goto V_292;
}
F_122 ( V_159 ) ;
if ( V_34 == - V_280 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_525 , 0 ,
& V_527 -> type , sizeof( V_527 -> type ) ) ;
F_110 ( V_6 , V_509 ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_241 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_528 * V_155 = V_7 ;
struct V_234 * V_235 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( ! F_240 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_529 ,
V_3 , & V_155 -> V_365 ,
sizeof( V_155 -> V_365 ) ) ;
goto V_276;
}
V_235 = F_242 ( V_6 , & V_155 -> V_365 . V_122 ) ;
if ( ! V_235 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_529 ,
V_274 , & V_155 -> V_365 ,
sizeof( V_155 -> V_365 ) ) ;
goto V_276;
}
if ( V_155 -> V_530 ) {
V_235 -> V_531 = V_532 ;
F_118 ( & V_235 -> V_284 ) ;
} else {
V_235 -> V_531 = V_533 ;
F_243 ( V_6 , V_235 ) ;
}
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_529 , 0 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_244 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_534 * V_155 = V_7 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_172 ( V_155 -> V_365 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_535 ,
V_274 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_245 ( & V_6 -> V_536 , & V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type ) ;
if ( V_34 < 0 ) {
V_230 = V_3 ;
goto V_380;
}
F_7 ( V_537 , V_6 , & V_155 -> V_365 , sizeof( V_155 -> V_365 ) ,
V_19 ) ;
V_230 = V_290 ;
V_380:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_535 , V_230 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_246 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_538 * V_155 = V_7 ;
T_1 V_230 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_172 ( V_155 -> V_365 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_539 ,
V_274 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_35 ( V_6 ) ;
V_34 = F_247 ( & V_6 -> V_536 , & V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type ) ;
if ( V_34 < 0 ) {
V_230 = V_274 ;
goto V_380;
}
F_7 ( V_540 , V_6 , & V_155 -> V_365 , sizeof( V_155 -> V_365 ) ,
V_19 ) ;
V_230 = V_290 ;
V_380:
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_539 , V_230 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_248 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_541 * V_155 = V_7 ;
struct V_152 V_153 ;
int V_34 ;
T_9 V_542 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
V_542 = F_131 ( V_155 -> V_542 ) ;
if ( V_542 > 0x0002 )
return F_112 ( V_19 , V_6 -> V_59 , V_543 ,
V_274 ) ;
F_35 ( V_6 ) ;
V_6 -> V_186 = V_542 ;
V_6 -> V_188 = F_131 ( V_155 -> V_544 ) ;
V_6 -> V_189 = F_131 ( V_155 -> V_545 ) ;
V_6 -> V_190 = F_131 ( V_155 -> V_23 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_543 , 0 ,
NULL , 0 ) ;
F_67 ( & V_153 , V_6 ) ;
F_70 ( & V_153 ) ;
F_68 ( & V_153 , NULL ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_249 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
F_10 ( L_19 , V_230 ) ;
}
static void F_250 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_282 V_283 = { NULL , V_6 } ;
struct V_152 V_153 ;
T_1 V_147 ;
struct V_148 * V_149 ;
int V_34 ;
F_35 ( V_6 ) ;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
F_147 ( V_336 , V_6 ,
F_121 , & V_293 ) ;
goto V_292;
}
if ( F_21 ( V_6 , V_208 ) )
F_83 ( V_6 , V_117 ) ;
else
F_77 ( V_6 , V_117 ) ;
F_147 ( V_336 , V_6 , F_117 ,
& V_283 ) ;
F_115 ( V_6 , V_283 . V_19 ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
if ( F_21 ( V_6 , V_117 ) ||
! F_21 ( V_6 , V_138 ) ||
F_107 ( & V_6 -> V_264 ) )
goto V_292;
V_147 = V_6 -> V_139 ;
if ( ! V_147 ) {
V_149 = F_251 ( & V_6 -> V_264 ,
struct V_148 , V_284 ) ;
if ( ! V_149 )
goto V_292;
V_147 = V_149 -> V_147 ;
}
F_67 ( & V_153 , V_6 ) ;
V_34 = F_99 ( & V_153 , V_147 , true ) ;
if ( ! V_34 )
V_34 = F_68 ( & V_153 , F_249 ) ;
if ( V_34 )
F_167 ( L_23 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_252 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
T_1 V_163 , V_230 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
V_230 = F_127 ( V_6 ) ;
if ( V_230 )
return F_112 ( V_19 , V_6 -> V_59 , V_336 ,
V_230 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 && V_155 -> V_163 != 0x02 )
return F_112 ( V_19 , V_6 -> V_59 , V_336 ,
V_274 ) ;
F_35 ( V_6 ) ;
V_163 = ! ! V_155 -> V_163 ;
if ( ! F_43 ( V_6 ) ||
( V_163 == F_21 ( V_6 , V_117 ) &&
( V_155 -> V_163 == 0x02 ) == F_21 ( V_6 , V_171 ) ) ||
F_76 ( V_6 , V_207 ) > 0 ||
( F_21 ( V_6 , V_241 ) &&
V_6 -> V_546 == V_495 ) ) {
bool V_291 ;
if ( V_155 -> V_163 ) {
V_291 = ! F_85 ( V_6 , V_117 ) ;
if ( V_155 -> V_163 == 0x02 )
F_83 ( V_6 , V_171 ) ;
else
F_77 ( V_6 , V_171 ) ;
} else {
V_291 = F_81 ( V_6 , V_117 ) ;
F_77 ( V_6 , V_171 ) ;
}
V_34 = F_89 ( V_19 , V_336 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_292;
}
if ( F_48 ( V_336 , V_6 ) ||
F_48 ( V_333 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_336 ,
V_275 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_336 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
if ( V_155 -> V_163 == 0x02 )
F_83 ( V_6 , V_171 ) ;
else
F_77 ( V_6 , V_171 ) ;
F_102 ( V_6 ) ;
if ( V_163 ) {
F_64 ( & V_153 , 0x00 ) ;
F_56 ( & V_153 , 0x00 ) ;
F_75 ( & V_153 ) ;
} else {
F_74 ( & V_153 ) ;
}
V_34 = F_68 ( & V_153 , F_250 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_253 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_547 * V_155 = V_7 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_548 ,
V_288 ) ;
if ( F_43 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_548 ,
V_289 ) ;
if ( F_29 ( & V_155 -> V_122 , V_76 ) ) {
if ( ! F_29 ( & V_155 -> V_122 , V_549 ) )
return F_112 ( V_19 , V_6 -> V_59 ,
V_548 ,
V_274 ) ;
if ( ( V_155 -> V_122 . V_550 [ 5 ] & 0xc0 ) != 0xc0 )
return F_112 ( V_19 , V_6 -> V_59 ,
V_548 ,
V_274 ) ;
}
F_35 ( V_6 ) ;
F_88 ( & V_6 -> V_123 , & V_155 -> V_122 ) ;
V_34 = F_89 ( V_19 , V_548 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
V_34 = F_115 ( V_6 , V_19 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_254 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_551 * V_155 = V_7 ;
T_9 V_311 , V_313 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_552 ,
V_288 ) ;
V_311 = F_131 ( V_155 -> V_311 ) ;
if ( V_311 < 0x0004 || V_311 > 0x4000 )
return F_112 ( V_19 , V_6 -> V_59 , V_552 ,
V_274 ) ;
V_313 = F_131 ( V_155 -> V_313 ) ;
if ( V_313 < 0x0004 || V_313 > 0x4000 )
return F_112 ( V_19 , V_6 -> V_59 , V_552 ,
V_274 ) ;
if ( V_313 > V_311 )
return F_112 ( V_19 , V_6 -> V_59 , V_552 ,
V_274 ) ;
F_35 ( V_6 ) ;
V_6 -> V_553 = V_311 ;
V_6 -> V_554 = V_313 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_552 , 0 ,
NULL , 0 ) ;
if ( F_21 ( V_6 , V_241 ) &&
V_6 -> V_236 . V_237 == V_509 ) {
struct V_152 V_153 ;
F_67 ( & V_153 , V_6 ) ;
F_95 ( & V_153 ) ;
F_255 ( & V_153 ) ;
F_68 ( & V_153 , NULL ) ;
}
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_256 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_137 * V_159 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_555 , V_6 ) ;
if ( ! V_159 )
goto V_292;
if ( V_230 ) {
F_112 ( V_159 -> V_19 , V_6 -> V_59 , V_555 ,
F_1 ( V_230 ) ) ;
} else {
struct V_161 * V_155 = V_159 -> V_162 ;
if ( V_155 -> V_163 )
F_83 ( V_6 , V_109 ) ;
else
F_77 ( V_6 , V_109 ) ;
F_89 ( V_159 -> V_19 , V_555 , V_6 ) ;
F_115 ( V_6 , V_159 -> V_19 ) ;
}
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_257 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_21 ( V_6 , V_112 ) ||
V_6 -> V_95 < V_96 )
return F_112 ( V_19 , V_6 -> V_59 , V_555 ,
V_288 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_555 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( F_48 ( V_555 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_555 ,
V_275 ) ;
goto V_292;
}
if ( ! ! V_155 -> V_163 == F_21 ( V_6 , V_109 ) ) {
V_34 = F_89 ( V_19 , V_555 ,
V_6 ) ;
goto V_292;
}
if ( ! F_43 ( V_6 ) ) {
F_132 ( V_6 , V_109 ) ;
V_34 = F_89 ( V_19 , V_555 ,
V_6 ) ;
F_115 ( V_6 , V_19 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_555 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
F_134 ( & V_153 , V_155 -> V_163 ) ;
V_34 = F_68 ( & V_153 , F_256 ) ;
if ( V_34 < 0 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_555 ,
V_3 ) ;
F_122 ( V_159 ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_258 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_137 * V_159 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_556 , V_6 ) ;
if ( ! V_159 )
goto V_292;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
F_77 ( V_6 , V_112 ) ;
F_112 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_293 ) ;
} else {
F_89 ( V_159 -> V_19 , V_556 , V_6 ) ;
F_115 ( V_6 , V_159 -> V_19 ) ;
}
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_259 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_38 ( V_6 ) || ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_556 ,
V_288 ) ;
if ( ! F_21 ( V_6 , V_113 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_556 ,
V_289 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_556 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( V_155 -> V_163 == F_21 ( V_6 , V_112 ) ) {
V_34 = F_89 ( V_19 , V_556 , V_6 ) ;
goto V_292;
}
if ( ! F_43 ( V_6 ) ) {
if ( ! V_155 -> V_163 ) {
F_77 ( V_6 , V_110 ) ;
F_77 ( V_6 , V_115 ) ;
F_77 ( V_6 , V_114 ) ;
F_77 ( V_6 , V_109 ) ;
F_77 ( V_6 , V_116 ) ;
}
F_132 ( V_6 , V_112 ) ;
V_34 = F_89 ( V_19 , V_556 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_292;
}
if ( ! V_155 -> V_163 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_556 ,
V_289 ) ;
goto V_292;
} else {
if ( ! F_21 ( V_6 , V_112 ) &&
( F_29 ( & V_6 -> V_123 , V_76 ) ||
F_21 ( V_6 , V_118 ) ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_556 ,
V_289 ) ;
goto V_292;
}
}
if ( F_48 ( V_556 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_556 ,
V_275 ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_556 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_83 ( V_6 , V_112 ) ;
F_67 ( & V_153 , V_6 ) ;
F_134 ( & V_153 , false ) ;
F_129 ( & V_153 ) ;
F_65 ( & V_153 ) ;
V_34 = F_68 ( & V_153 , F_258 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_260 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_137 * V_159 ;
struct V_161 * V_155 ;
F_10 ( L_16 , V_6 -> V_83 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_557 , V_6 ) ;
if ( ! V_159 )
goto V_292;
if ( V_230 ) {
F_112 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 ,
F_1 ( V_230 ) ) ;
goto remove;
}
V_155 = V_159 -> V_162 ;
switch ( V_155 -> V_163 ) {
case 0x00 :
F_77 ( V_6 , V_118 ) ;
F_77 ( V_6 , V_558 ) ;
break;
case 0x01 :
F_83 ( V_6 , V_118 ) ;
F_77 ( V_6 , V_558 ) ;
break;
case 0x02 :
F_83 ( V_6 , V_118 ) ;
F_83 ( V_6 , V_558 ) ;
break;
}
F_89 ( V_159 -> V_19 , V_557 , V_6 ) ;
F_115 ( V_6 , V_159 -> V_19 ) ;
remove:
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_261 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
T_1 V_163 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_40 ( V_6 ) &&
! F_21 ( V_6 , V_113 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_557 ,
V_288 ) ;
if ( F_21 ( V_6 , V_112 ) &&
F_40 ( V_6 ) &&
! F_21 ( V_6 , V_115 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_557 ,
V_289 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 && V_155 -> V_163 != 0x02 )
return F_112 ( V_19 , V_6 -> V_59 , V_557 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) || ! F_40 ( V_6 ) ||
! F_21 ( V_6 , V_112 ) ) {
bool V_291 ;
if ( V_155 -> V_163 ) {
V_291 = ! F_85 ( V_6 ,
V_118 ) ;
if ( V_155 -> V_163 == 0x02 )
F_83 ( V_6 , V_558 ) ;
else
F_77 ( V_6 , V_558 ) ;
} else {
V_291 = F_81 ( V_6 ,
V_118 ) ;
F_77 ( V_6 , V_558 ) ;
}
V_34 = F_89 ( V_19 , V_557 , V_6 ) ;
if ( V_34 < 0 )
goto V_276;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
goto V_276;
}
if ( F_48 ( V_557 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_557 ,
V_275 ) ;
goto V_276;
}
V_163 = ! ! V_155 -> V_163 ;
if ( V_163 == F_21 ( V_6 , V_118 ) &&
( V_155 -> V_163 == 0x02 ) == F_21 ( V_6 , V_558 ) ) {
V_34 = F_89 ( V_19 , V_557 , V_6 ) ;
goto V_276;
}
V_159 = F_113 ( V_19 , V_557 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_276;
}
F_67 ( & V_153 , V_6 ) ;
F_57 ( & V_153 , V_559 , 1 , & V_163 ) ;
V_34 = F_68 ( & V_153 , F_260 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
goto V_276;
}
V_276:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_262 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_161 * V_155 = V_7 ;
bool V_291 , V_560 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( V_155 -> V_163 != 0x00 && V_155 -> V_163 != 0x01 && V_155 -> V_163 != 0x02 )
return F_112 ( V_19 , V_6 -> V_59 , V_561 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( V_155 -> V_163 )
V_291 = ! F_85 ( V_6 , V_119 ) ;
else
V_291 = F_81 ( V_6 ,
V_119 ) ;
if ( V_155 -> V_163 == 0x02 )
V_560 = ! F_85 ( V_6 ,
V_329 ) ;
else
V_560 = F_81 ( V_6 ,
V_329 ) ;
if ( F_43 ( V_6 ) && V_560 &&
F_21 ( V_6 , V_115 ) ) {
T_1 V_562 = ( V_155 -> V_163 == 0x02 ) ? 0x01 : 0x00 ;
F_143 ( V_6 , V_330 ,
sizeof( V_562 ) , & V_562 ) ;
}
V_34 = F_89 ( V_19 , V_561 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_263 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_563 ,
T_2 V_8 )
{
struct V_564 * V_155 = V_563 ;
bool V_291 ;
int V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_565 ,
V_288 ) ;
if ( V_155 -> V_566 != 0x00 && V_155 -> V_566 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_565 ,
V_274 ) ;
if ( F_43 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_565 ,
V_289 ) ;
F_35 ( V_6 ) ;
F_83 ( V_6 , V_567 ) ;
if ( V_155 -> V_566 ) {
V_291 = ! F_85 ( V_6 , V_120 ) ;
memcpy ( V_6 -> V_568 , V_155 -> V_568 , sizeof( V_6 -> V_568 ) ) ;
F_83 ( V_6 , V_223 ) ;
} else {
V_291 = F_81 ( V_6 , V_120 ) ;
memset ( V_6 -> V_568 , 0 , sizeof( V_6 -> V_568 ) ) ;
F_77 ( V_6 , V_223 ) ;
}
V_34 = F_89 ( V_19 , V_565 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( V_291 )
V_34 = F_115 ( V_6 , V_19 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_264 ( struct V_569 * V_568 )
{
switch ( V_568 -> V_365 . type ) {
case V_16 :
return true ;
case V_395 :
if ( ( V_568 -> V_365 . V_122 . V_550 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_265 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_563 ,
T_2 V_8 )
{
struct V_570 * V_155 = V_563 ;
const T_2 V_571 = ( ( V_357 - sizeof( * V_155 ) ) /
sizeof( struct V_569 ) ) ;
T_2 V_572 , V_360 ;
int V_33 , V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_573 ,
V_288 ) ;
V_572 = F_131 ( V_155 -> V_572 ) ;
if ( V_572 > V_571 ) {
F_167 ( L_24 , V_572 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_573 ,
V_274 ) ;
}
V_360 = sizeof( * V_155 ) + V_572 * sizeof( struct V_569 ) ;
if ( V_360 != V_8 ) {
F_167 ( L_25 ,
V_360 , V_8 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_573 ,
V_274 ) ;
}
F_10 ( L_26 , V_6 -> V_83 , V_572 ) ;
for ( V_33 = 0 ; V_33 < V_572 ; V_33 ++ ) {
struct V_569 * V_363 = & V_155 -> V_574 [ V_33 ] ;
if ( ! F_264 ( V_363 ) )
return F_112 ( V_19 , V_6 -> V_59 ,
V_573 ,
V_274 ) ;
}
F_35 ( V_6 ) ;
F_266 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_572 ; V_33 ++ ) {
struct V_569 * V_568 = & V_155 -> V_574 [ V_33 ] ;
F_267 ( V_6 , & V_568 -> V_365 . V_122 ,
F_8 ( V_568 -> V_365 . type ) , V_568 -> V_163 ,
V_76 ) ;
}
F_83 ( V_6 , V_567 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_573 , 0 , NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_268 ( struct V_575 * V_363 )
{
if ( V_363 -> V_576 != 0x00 && V_363 -> V_576 != 0x01 )
return false ;
switch ( V_363 -> V_365 . type ) {
case V_16 :
return true ;
case V_395 :
if ( ( V_363 -> V_365 . V_122 . V_550 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_269 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_563 , T_2 V_8 )
{
struct V_577 * V_155 = V_563 ;
const T_2 V_356 = ( ( V_357 - sizeof( * V_155 ) ) /
sizeof( struct V_575 ) ) ;
T_2 V_359 , V_360 ;
int V_33 , V_34 ;
F_10 ( L_7 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_578 ,
V_288 ) ;
V_359 = F_131 ( V_155 -> V_359 ) ;
if ( V_359 > V_356 ) {
F_167 ( L_27 , V_359 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_578 ,
V_274 ) ;
}
V_360 = sizeof( * V_155 ) + V_359 *
sizeof( struct V_575 ) ;
if ( V_360 != V_8 ) {
F_167 ( L_28 ,
V_360 , V_8 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_578 ,
V_274 ) ;
}
F_10 ( L_29 , V_6 -> V_83 , V_359 ) ;
for ( V_33 = 0 ; V_33 < V_359 ; V_33 ++ ) {
struct V_575 * V_363 = & V_155 -> V_364 [ V_33 ] ;
if ( ! F_268 ( V_363 ) )
return F_112 ( V_19 , V_6 -> V_59 ,
V_578 ,
V_274 ) ;
}
F_35 ( V_6 ) ;
F_270 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_359 ; V_33 ++ ) {
struct V_575 * V_363 = & V_155 -> V_364 [ V_33 ] ;
T_1 type , V_579 ;
switch ( V_363 -> type ) {
case V_580 :
V_579 = 0x00 ;
type = V_363 -> V_576 ? V_581 : V_582 ;
break;
case V_583 :
V_579 = 0x01 ;
type = V_363 -> V_576 ? V_581 : V_582 ;
break;
case V_584 :
V_579 = 0x00 ;
type = V_585 ;
break;
case V_586 :
V_579 = 0x01 ;
type = V_585 ;
break;
case V_587 :
V_579 = 0x00 ;
type = V_588 ;
default:
continue;
}
F_271 ( V_6 , & V_363 -> V_365 . V_122 ,
F_8 ( V_363 -> V_365 . type ) , type , V_579 ,
V_363 -> V_163 , V_363 -> V_589 , V_363 -> V_590 , V_363 -> rand ) ;
}
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_578 , 0 ,
NULL , 0 ) ;
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_272 ( struct V_137 * V_159 , T_1 V_230 )
{
struct V_265 * V_266 = V_159 -> V_422 ;
struct V_591 V_22 ;
int V_34 ;
memcpy ( & V_22 . V_365 , V_159 -> V_162 , sizeof( V_22 . V_365 ) ) ;
if ( V_230 == V_290 ) {
V_22 . V_524 = V_266 -> V_524 ;
V_22 . V_592 = V_266 -> V_592 ;
V_22 . V_593 = V_266 -> V_593 ;
} else {
V_22 . V_524 = V_594 ;
V_22 . V_592 = V_181 ;
V_22 . V_593 = V_181 ;
}
V_34 = F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_595 ,
V_230 , & V_22 , sizeof( V_22 ) ) ;
F_191 ( V_266 ) ;
F_193 ( V_266 ) ;
return V_34 ;
}
static void F_273 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_41 )
{
struct V_596 * V_155 ;
struct V_137 * V_159 ;
struct V_265 * V_266 ;
T_2 V_597 ;
T_1 V_230 ;
F_10 ( L_8 , V_1 ) ;
F_35 ( V_6 ) ;
V_155 = F_274 ( V_6 , V_598 ) ;
if ( ! V_155 ) {
V_155 = F_274 ( V_6 , V_599 ) ;
V_230 = V_290 ;
} else {
V_230 = F_1 ( V_1 ) ;
}
if ( ! V_155 ) {
F_167 ( L_30 ) ;
goto V_292;
}
V_597 = F_131 ( V_155 -> V_597 ) ;
V_266 = F_275 ( V_6 , V_597 ) ;
if ( ! V_266 ) {
F_167 ( L_31 , V_597 ) ;
goto V_292;
}
V_159 = F_50 ( V_595 , V_6 , V_266 ) ;
if ( ! V_159 )
goto V_292;
V_159 -> V_285 ( V_159 , V_230 ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_276 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_600 * V_155 = V_7 ;
struct V_591 V_22 ;
struct V_265 * V_266 ;
unsigned long V_601 ;
int V_34 = 0 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_88 ( & V_22 . V_365 . V_122 , & V_155 -> V_365 . V_122 ) ;
V_22 . V_365 . type = V_155 -> V_365 . type ;
if ( ! F_172 ( V_155 -> V_365 . type ) )
return F_12 ( V_19 , V_6 -> V_59 , V_595 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_595 ,
V_299 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
if ( V_155 -> V_365 . type == V_366 )
V_266 = F_173 ( V_6 , V_378 ,
& V_155 -> V_365 . V_122 ) ;
else
V_266 = F_173 ( V_6 , V_207 , & V_155 -> V_365 . V_122 ) ;
if ( ! V_266 || V_266 -> V_237 != V_441 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_595 ,
V_393 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
if ( F_50 ( V_595 , V_6 , V_266 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_595 ,
V_275 , & V_22 , sizeof( V_22 ) ) ;
goto V_292;
}
V_601 = V_6 -> V_602 +
F_277 ( V_6 -> V_603 -
V_6 -> V_602 ) ;
if ( F_278 ( V_515 , V_266 -> V_604 +
F_101 ( V_601 ) ) ||
! V_266 -> V_604 ) {
struct V_152 V_153 ;
struct V_605 V_606 ;
struct V_596 V_607 ;
struct V_137 * V_159 ;
F_67 ( & V_153 , V_6 ) ;
V_607 . V_597 = F_11 ( V_266 -> V_597 ) ;
F_57 ( & V_153 , V_598 , sizeof( V_607 ) ,
& V_607 ) ;
if ( ! F_223 ( V_155 -> V_365 . type ) ||
V_266 -> V_592 == V_181 ) {
V_606 . V_597 = F_11 ( V_266 -> V_597 ) ;
V_606 . type = 0x00 ;
F_57 ( & V_153 , V_599 ,
sizeof( V_606 ) , & V_606 ) ;
}
if ( V_266 -> V_593 == V_181 ) {
V_606 . V_597 = F_11 ( V_266 -> V_597 ) ;
V_606 . type = 0x01 ;
F_57 ( & V_153 , V_599 ,
sizeof( V_606 ) , & V_606 ) ;
}
V_34 = F_68 ( & V_153 , F_273 ) ;
if ( V_34 < 0 )
goto V_292;
V_159 = F_113 ( V_19 , V_595 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_279 ( V_266 ) ;
V_159 -> V_422 = F_204 ( V_266 ) ;
V_159 -> V_285 = F_272 ;
V_266 -> V_604 = V_515 ;
} else {
V_22 . V_524 = V_266 -> V_524 ;
V_22 . V_592 = V_266 -> V_592 ;
V_22 . V_593 = V_266 -> V_593 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_595 ,
V_290 , & V_22 , sizeof( V_22 ) ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_280 ( struct V_137 * V_159 , T_1 V_230 )
{
struct V_265 * V_266 = V_159 -> V_422 ;
struct V_608 V_22 ;
struct V_5 * V_6 ;
int V_34 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
memcpy ( & V_22 . V_365 , & V_159 -> V_162 , sizeof( V_22 . V_365 ) ) ;
if ( V_230 )
goto V_427;
V_6 = F_281 ( V_159 -> V_58 ) ;
if ( V_6 ) {
V_22 . V_609 = F_31 ( V_6 -> clock ) ;
F_282 ( V_6 ) ;
}
if ( V_266 ) {
V_22 . V_610 = F_31 ( V_266 -> clock ) ;
V_22 . V_611 = F_11 ( V_266 -> V_612 ) ;
}
V_427:
V_34 = F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_230 , & V_22 ,
sizeof( V_22 ) ) ;
if ( V_266 ) {
F_191 ( V_266 ) ;
F_193 ( V_266 ) ;
}
return V_34 ;
}
static void F_283 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_613 * V_303 ;
struct V_137 * V_159 ;
struct V_265 * V_266 ;
F_10 ( L_16 , V_6 -> V_83 , V_230 ) ;
F_35 ( V_6 ) ;
V_303 = F_274 ( V_6 , V_614 ) ;
if ( ! V_303 )
goto V_292;
if ( V_303 -> V_615 ) {
T_2 V_597 = F_131 ( V_303 -> V_597 ) ;
V_266 = F_275 ( V_6 , V_597 ) ;
} else {
V_266 = NULL ;
}
V_159 = F_50 ( V_616 , V_6 , V_266 ) ;
if ( ! V_159 )
goto V_292;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_284 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_617 * V_155 = V_7 ;
struct V_608 V_22 ;
struct V_613 V_303 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
struct V_265 * V_266 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_88 ( & V_22 . V_365 . V_122 , & V_155 -> V_365 . V_122 ) ;
V_22 . V_365 . type = V_155 -> V_365 . type ;
if ( V_155 -> V_365 . type != V_366 )
return F_12 ( V_19 , V_6 -> V_59 , V_616 ,
V_274 ,
& V_22 , sizeof( V_22 ) ) ;
F_35 ( V_6 ) ;
if ( ! F_43 ( V_6 ) ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_616 ,
V_299 , & V_22 ,
sizeof( V_22 ) ) ;
goto V_292;
}
if ( F_29 ( & V_155 -> V_365 . V_122 , V_76 ) ) {
V_266 = F_173 ( V_6 , V_378 ,
& V_155 -> V_365 . V_122 ) ;
if ( ! V_266 || V_266 -> V_237 != V_441 ) {
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_616 ,
V_393 ,
& V_22 , sizeof( V_22 ) ) ;
goto V_292;
}
} else {
V_266 = NULL ;
}
V_159 = F_113 ( V_19 , V_616 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_159 -> V_285 = F_280 ;
F_67 ( & V_153 , V_6 ) ;
memset ( & V_303 , 0 , sizeof( V_303 ) ) ;
F_57 ( & V_153 , V_614 , sizeof( V_303 ) , & V_303 ) ;
if ( V_266 ) {
F_279 ( V_266 ) ;
V_159 -> V_422 = F_204 ( V_266 ) ;
V_303 . V_597 = F_11 ( V_266 -> V_597 ) ;
V_303 . V_615 = 0x01 ;
F_57 ( & V_153 , V_614 , sizeof( V_303 ) , & V_303 ) ;
}
V_34 = F_68 ( & V_153 , F_283 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static bool F_285 ( struct V_5 * V_6 , T_8 * V_365 , T_1 type )
{
struct V_265 * V_266 ;
V_266 = F_173 ( V_6 , V_207 , V_365 ) ;
if ( ! V_266 )
return false ;
if ( V_266 -> V_401 != type )
return false ;
if ( V_266 -> V_237 != V_441 )
return false ;
return true ;
}
static int F_286 ( struct V_152 * V_153 , T_8 * V_365 ,
T_1 V_369 , T_1 V_383 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_374 * V_375 ;
V_375 = F_200 ( V_6 , V_365 , V_369 ) ;
if ( ! V_375 )
return - V_618 ;
if ( V_375 -> V_383 == V_383 )
return 0 ;
F_287 ( & V_375 -> V_619 ) ;
switch ( V_383 ) {
case V_385 :
case V_620 :
if ( V_375 -> V_382 )
F_288 ( & V_375 -> V_619 , & V_6 -> V_621 ) ;
F_149 ( V_153 ) ;
break;
case V_622 :
if ( V_375 -> V_382 )
F_288 ( & V_375 -> V_619 , & V_6 -> V_621 ) ;
else
F_288 ( & V_375 -> V_619 , & V_6 -> V_623 ) ;
F_149 ( V_153 ) ;
break;
case V_624 :
case V_625 :
if ( ! F_285 ( V_6 , V_365 , V_369 ) ) {
F_288 ( & V_375 -> V_619 , & V_6 -> V_621 ) ;
if ( V_375 -> V_383 != V_384 )
F_149 ( V_153 ) ;
}
break;
}
V_375 -> V_383 = V_383 ;
F_10 ( L_32 , V_365 , V_369 ,
V_383 ) ;
return 0 ;
}
static void F_289 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_8 * V_122 , T_1 type , T_1 V_619 )
{
struct V_626 V_247 ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = type ;
V_247 . V_619 = V_619 ;
F_7 ( V_627 , V_6 , & V_247 , sizeof( V_247 ) , V_19 ) ;
}
static void F_290 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_137 * V_159 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_628 , V_6 ) ;
if ( ! V_159 )
goto V_292;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_291 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_629 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
T_1 V_630 , V_369 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_172 ( V_155 -> V_365 . type ) ||
! F_29 ( & V_155 -> V_365 . V_122 , V_76 ) )
return F_12 ( V_19 , V_6 -> V_59 , V_628 ,
V_274 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
if ( V_155 -> V_619 != 0x00 && V_155 -> V_619 != 0x01 && V_155 -> V_619 != 0x02 )
return F_12 ( V_19 , V_6 -> V_59 , V_628 ,
V_274 ,
& V_155 -> V_365 , sizeof( V_155 -> V_365 ) ) ;
F_67 ( & V_153 , V_6 ) ;
F_35 ( V_6 ) ;
V_159 = F_113 ( V_19 , V_628 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_159 -> V_285 = F_125 ;
if ( V_155 -> V_365 . type == V_366 ) {
if ( V_155 -> V_619 != 0x01 ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
V_34 = F_245 ( & V_6 -> V_321 , & V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type ) ;
if ( V_34 )
goto V_292;
F_129 ( & V_153 ) ;
goto V_631;
}
V_369 = F_8 ( V_155 -> V_365 . type ) ;
if ( V_155 -> V_619 == 0x02 )
V_630 = V_625 ;
else if ( V_155 -> V_619 == 0x01 )
V_630 = V_624 ;
else
V_630 = V_622 ;
if ( ! F_292 ( & V_155 -> V_365 . V_122 , V_369 ) ) {
V_34 = V_159 -> V_285 ( V_159 , V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
if ( F_286 ( & V_153 , & V_155 -> V_365 . V_122 , V_369 ,
V_630 ) < 0 ) {
V_34 = V_159 -> V_285 ( V_159 , V_3 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
V_631:
F_289 ( V_19 , V_6 , & V_155 -> V_365 . V_122 , V_155 -> V_365 . type , V_155 -> V_619 ) ;
V_34 = F_68 ( & V_153 , F_290 ) ;
if ( V_34 < 0 ) {
if ( V_34 == - V_280 )
V_34 = V_159 -> V_285 ( V_159 , V_290 ) ;
F_122 ( V_159 ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_293 ( struct V_11 * V_19 , struct V_5 * V_6 ,
T_8 * V_122 , T_1 type )
{
struct V_632 V_247 ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = type ;
F_7 ( V_633 , V_6 , & V_247 , sizeof( V_247 ) , V_19 ) ;
}
static void F_294 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_137 * V_159 ;
F_10 ( L_8 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_634 , V_6 ) ;
if ( ! V_159 )
goto V_292;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_295 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_635 * V_155 = V_7 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_67 ( & V_153 , V_6 ) ;
F_35 ( V_6 ) ;
V_159 = F_113 ( V_19 , V_634 , V_6 , V_7 , V_8 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_159 -> V_285 = F_125 ;
if ( F_29 ( & V_155 -> V_365 . V_122 , V_76 ) ) {
struct V_374 * V_375 ;
T_1 V_369 ;
if ( ! F_172 ( V_155 -> V_365 . type ) ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
if ( V_155 -> V_365 . type == V_366 ) {
V_34 = F_247 ( & V_6 -> V_321 ,
& V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type ) ;
if ( V_34 ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
F_129 ( & V_153 ) ;
F_293 ( V_19 , V_6 , & V_155 -> V_365 . V_122 ,
V_155 -> V_365 . type ) ;
goto V_427;
}
V_369 = F_8 ( V_155 -> V_365 . type ) ;
if ( ! F_292 ( & V_155 -> V_365 . V_122 , V_369 ) ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
V_375 = F_181 ( V_6 , & V_155 -> V_365 . V_122 ,
V_369 ) ;
if ( ! V_375 ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
if ( V_375 -> V_383 == V_385 ||
V_375 -> V_383 == V_384 ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
F_118 ( & V_375 -> V_619 ) ;
F_118 ( & V_375 -> V_284 ) ;
F_17 ( V_375 ) ;
F_149 ( & V_153 ) ;
F_293 ( V_19 , V_6 , & V_155 -> V_365 . V_122 , V_155 -> V_365 . type ) ;
} else {
struct V_374 * V_435 , * V_349 ;
struct V_636 * V_550 , * V_637 ;
if ( V_155 -> V_365 . type ) {
V_34 = V_159 -> V_285 ( V_159 ,
V_274 ) ;
F_122 ( V_159 ) ;
goto V_292;
}
F_105 (b, btmp, &hdev->whitelist, list) {
F_293 ( V_19 , V_6 , & V_550 -> V_122 , V_550 -> V_638 ) ;
F_118 ( & V_550 -> V_284 ) ;
F_17 ( V_550 ) ;
}
F_129 ( & V_153 ) ;
F_105 (p, tmp, &hdev->le_conn_params, list) {
if ( V_435 -> V_383 == V_385 )
continue;
F_293 ( V_19 , V_6 , & V_435 -> V_365 , V_435 -> V_369 ) ;
if ( V_435 -> V_382 ) {
V_435 -> V_383 = V_384 ;
continue;
}
F_118 ( & V_435 -> V_619 ) ;
F_118 ( & V_435 -> V_284 ) ;
F_17 ( V_435 ) ;
}
F_10 ( L_33 ) ;
F_149 ( & V_153 ) ;
}
V_427:
V_34 = F_68 ( & V_153 , F_294 ) ;
if ( V_34 < 0 ) {
if ( V_34 == - V_280 )
V_34 = V_159 -> V_285 ( V_159 , V_290 ) ;
F_122 ( V_159 ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_296 ( struct V_11 * V_19 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_639 * V_155 = V_7 ;
const T_2 V_640 = ( ( V_357 - sizeof( * V_155 ) ) /
sizeof( struct V_641 ) ) ;
T_2 V_642 , V_360 ;
int V_33 ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_643 ,
V_288 ) ;
V_642 = F_131 ( V_155 -> V_642 ) ;
if ( V_642 > V_640 ) {
F_167 ( L_34 ,
V_642 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_643 ,
V_274 ) ;
}
V_360 = sizeof( * V_155 ) + V_642 *
sizeof( struct V_641 ) ;
if ( V_360 != V_8 ) {
F_167 ( L_35 ,
V_360 , V_8 ) ;
return F_112 ( V_19 , V_6 -> V_59 , V_643 ,
V_274 ) ;
}
F_10 ( L_36 , V_6 -> V_83 , V_642 ) ;
F_35 ( V_6 ) ;
F_297 ( V_6 ) ;
for ( V_33 = 0 ; V_33 < V_642 ; V_33 ++ ) {
struct V_641 * V_162 = & V_155 -> V_375 [ V_33 ] ;
struct V_374 * V_644 ;
T_2 V_645 , V_646 , V_647 , V_252 ;
T_1 V_369 ;
F_10 ( L_37 , & V_162 -> V_365 . V_122 ,
V_162 -> V_365 . type ) ;
if ( V_162 -> V_365 . type == V_16 ) {
V_369 = V_17 ;
} else if ( V_162 -> V_365 . type == V_395 ) {
V_369 = V_18 ;
} else {
F_167 ( L_38 ) ;
continue;
}
V_645 = F_298 ( V_162 -> V_209 ) ;
V_646 = F_298 ( V_162 -> V_211 ) ;
V_647 = F_298 ( V_162 -> V_647 ) ;
V_252 = F_298 ( V_162 -> V_252 ) ;
F_10 ( L_39 ,
V_645 , V_646 , V_647 , V_252 ) ;
if ( F_299 ( V_645 , V_646 , V_647 , V_252 ) < 0 ) {
F_167 ( L_38 ) ;
continue;
}
V_644 = F_200 ( V_6 , & V_162 -> V_365 . V_122 ,
V_369 ) ;
if ( ! V_644 ) {
F_167 ( L_40 ) ;
continue;
}
V_644 -> V_648 = V_645 ;
V_644 -> V_649 = V_646 ;
V_644 -> V_650 = V_647 ;
V_644 -> V_651 = V_252 ;
}
F_36 ( V_6 ) ;
return F_12 ( V_19 , V_6 -> V_59 , V_643 , 0 ,
NULL , 0 ) ;
}
static int F_300 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_652 * V_155 = V_7 ;
bool V_291 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_653 ,
V_289 ) ;
if ( V_155 -> V_654 != 0x00 && V_155 -> V_654 != 0x01 )
return F_112 ( V_19 , V_6 -> V_59 , V_653 ,
V_274 ) ;
if ( ! F_23 ( V_72 , & V_6 -> V_57 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_653 ,
V_288 ) ;
F_35 ( V_6 ) ;
if ( V_155 -> V_654 )
V_291 = ! F_85 ( V_6 , V_73 ) ;
else
V_291 = F_81 ( V_6 , V_73 ) ;
V_34 = F_33 ( V_19 , V_653 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( ! V_291 )
goto V_292;
V_34 = F_32 ( V_6 , V_19 ) ;
if ( F_21 ( V_6 , V_51 ) == F_28 ( V_6 ) ) {
F_301 ( V_6 ) ;
if ( F_302 ( V_6 , V_51 ) ) {
F_83 ( V_6 , V_54 ) ;
F_83 ( V_6 , V_277 ) ;
F_93 ( V_6 -> V_232 , & V_6 -> V_278 ) ;
} else {
F_180 ( V_655 , & V_6 -> V_168 ) ;
F_303 ( V_6 ) ;
}
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static int F_304 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_656 * V_155 = V_7 ;
bool V_291 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_657 ,
V_289 ) ;
if ( ! F_29 ( & V_155 -> V_122 , V_76 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_657 ,
V_274 ) ;
if ( ! V_6 -> V_85 )
return F_112 ( V_19 , V_6 -> V_59 , V_657 ,
V_288 ) ;
F_35 ( V_6 ) ;
V_291 = ! ! F_29 ( & V_6 -> V_75 , & V_155 -> V_122 ) ;
F_88 ( & V_6 -> V_75 , & V_155 -> V_122 ) ;
V_34 = F_33 ( V_19 , V_657 , V_6 ) ;
if ( V_34 < 0 )
goto V_292;
if ( ! V_291 )
goto V_292;
if ( F_21 ( V_6 , V_51 ) )
V_34 = F_32 ( V_6 , V_19 ) ;
if ( F_28 ( V_6 ) ) {
F_301 ( V_6 ) ;
F_77 ( V_6 , V_51 ) ;
F_83 ( V_6 , V_54 ) ;
F_83 ( V_6 , V_277 ) ;
F_93 ( V_6 -> V_232 , & V_6 -> V_278 ) ;
}
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static inline T_2 F_305 ( T_1 * V_194 , T_2 V_658 , T_1 type , T_1 * V_7 ,
T_1 V_20 )
{
V_194 [ V_658 ++ ] = sizeof( type ) + V_20 ;
V_194 [ V_658 ++ ] = type ;
memcpy ( & V_194 [ V_658 ] , V_7 , V_20 ) ;
V_658 += V_20 ;
return V_658 ;
}
static void F_306 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 , struct V_465 * V_466 )
{
const struct V_659 * V_527 ;
struct V_660 * V_468 ;
T_1 * V_661 , * V_662 , * V_663 , * V_664 ;
struct V_137 * V_159 ;
T_2 V_658 ;
int V_34 ;
F_10 ( L_16 , V_6 -> V_83 , V_230 ) ;
V_159 = F_48 ( V_665 , V_6 ) ;
if ( ! V_159 )
return;
V_527 = V_159 -> V_162 ;
if ( V_230 ) {
V_230 = F_1 ( V_230 ) ;
V_658 = 0 ;
V_661 = NULL ;
V_662 = NULL ;
V_663 = NULL ;
V_664 = NULL ;
} else if ( V_41 == V_470 ) {
struct V_471 * V_22 ;
if ( V_466 -> V_8 != sizeof( * V_22 ) ) {
V_230 = V_3 ;
V_658 = 0 ;
} else {
V_230 = V_290 ;
V_22 = ( void * ) V_466 -> V_7 ;
V_658 = 5 + 18 + 18 ;
V_661 = V_22 -> V_473 ;
V_662 = V_22 -> rand ;
V_663 = NULL ;
V_664 = NULL ;
}
} else {
struct V_477 * V_22 ;
if ( V_466 -> V_8 != sizeof( * V_22 ) ) {
V_230 = V_3 ;
V_658 = 0 ;
} else {
V_230 = V_290 ;
V_22 = ( void * ) V_466 -> V_7 ;
if ( F_21 ( V_6 , V_558 ) ) {
V_658 = 5 + 18 + 18 ;
V_661 = NULL ;
V_662 = NULL ;
} else {
V_658 = 5 + 18 + 18 + 18 + 18 ;
V_661 = V_22 -> V_472 ;
V_662 = V_22 -> V_474 ;
}
V_663 = V_22 -> V_475 ;
V_664 = V_22 -> V_476 ;
}
}
V_468 = F_15 ( sizeof( * V_468 ) + V_658 , V_39 ) ;
if ( ! V_468 )
goto V_380;
if ( V_230 )
goto V_666;
V_658 = F_305 ( V_468 -> V_194 , 0 , V_667 ,
V_6 -> V_200 , 3 ) ;
if ( V_661 && V_662 ) {
V_658 = F_305 ( V_468 -> V_194 , V_658 ,
V_668 , V_661 , 16 ) ;
V_658 = F_305 ( V_468 -> V_194 , V_658 ,
V_669 , V_662 , 16 ) ;
}
if ( V_663 && V_664 ) {
V_658 = F_305 ( V_468 -> V_194 , V_658 ,
V_670 , V_663 , 16 ) ;
V_658 = F_305 ( V_468 -> V_194 , V_658 ,
V_671 , V_664 , 16 ) ;
}
V_666:
V_468 -> type = V_527 -> type ;
V_468 -> V_658 = F_11 ( V_658 ) ;
V_34 = F_12 ( V_159 -> V_19 , V_6 -> V_59 ,
V_665 , V_230 ,
V_468 , sizeof( * V_468 ) + V_658 ) ;
if ( V_34 < 0 || V_230 )
goto V_380;
F_26 ( V_159 -> V_19 , V_672 ) ;
V_34 = F_5 ( V_673 , V_6 ,
V_468 , sizeof( * V_468 ) + V_658 ,
V_672 , V_159 -> V_19 ) ;
V_380:
F_17 ( V_468 ) ;
F_122 ( V_159 ) ;
}
static int F_307 ( struct V_5 * V_6 , struct V_11 * V_19 ,
struct V_659 * V_155 )
{
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
V_159 = F_113 ( V_19 , V_665 , V_6 ,
V_155 , sizeof( * V_155 ) ) ;
if ( ! V_159 )
return - V_40 ;
F_67 ( & V_153 , V_6 ) ;
if ( F_219 ( V_6 ) )
F_57 ( & V_153 , V_478 , 0 , NULL ) ;
else
F_57 ( & V_153 , V_470 , 0 , NULL ) ;
V_34 = F_220 ( & V_153 , F_306 ) ;
if ( V_34 < 0 ) {
F_122 ( V_159 ) ;
return V_34 ;
}
return 0 ;
}
static int F_308 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_659 * V_155 = V_7 ;
struct V_660 * V_22 ;
T_3 V_46 ;
T_2 V_658 ;
T_1 V_230 , V_168 , V_674 , V_365 [ 7 ] , V_473 [ 16 ] , rand [ 16 ] ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( F_43 ( V_6 ) ) {
switch ( V_155 -> type ) {
case F_309 ( V_366 ) :
V_230 = F_126 ( V_6 ) ;
if ( V_230 )
V_658 = 0 ;
else
V_658 = 5 ;
break;
case ( F_309 ( V_16 ) | F_309 ( V_395 ) ) :
V_230 = F_127 ( V_6 ) ;
if ( V_230 )
V_658 = 0 ;
else
V_658 = 9 + 3 + 18 + 18 + 3 ;
break;
default:
V_230 = V_274 ;
V_658 = 0 ;
break;
}
} else {
V_230 = V_299 ;
V_658 = 0 ;
}
V_46 = sizeof( * V_22 ) + V_658 ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 )
return - V_40 ;
if ( V_230 )
goto V_427;
F_35 ( V_6 ) ;
V_658 = 0 ;
switch ( V_155 -> type ) {
case F_309 ( V_366 ) :
if ( F_21 ( V_6 , V_115 ) ) {
V_34 = F_307 ( V_6 , V_19 , V_155 ) ;
F_36 ( V_6 ) ;
if ( ! V_34 )
goto V_380;
V_230 = V_3 ;
goto V_427;
} else {
V_658 = F_305 ( V_22 -> V_194 , V_658 ,
V_667 ,
V_6 -> V_200 , 3 ) ;
}
break;
case ( F_309 ( V_16 ) | F_309 ( V_395 ) ) :
if ( F_21 ( V_6 , V_118 ) &&
F_310 ( V_6 , V_473 , rand ) < 0 ) {
F_36 ( V_6 ) ;
V_230 = V_3 ;
goto V_427;
}
if ( F_21 ( V_6 , V_120 ) ) {
F_36 ( V_6 ) ;
V_230 = V_289 ;
goto V_427;
}
if ( F_21 ( V_6 , V_121 ) ||
! F_29 ( & V_6 -> V_122 , V_76 ) ||
( ! F_21 ( V_6 , V_112 ) &&
F_29 ( & V_6 -> V_123 , V_76 ) ) ) {
memcpy ( V_365 , & V_6 -> V_123 , 6 ) ;
V_365 [ 6 ] = 0x01 ;
} else {
memcpy ( V_365 , & V_6 -> V_122 , 6 ) ;
V_365 [ 6 ] = 0x00 ;
}
V_658 = F_305 ( V_22 -> V_194 , V_658 , V_675 ,
V_365 , sizeof( V_365 ) ) ;
if ( F_21 ( V_6 , V_117 ) )
V_674 = 0x02 ;
else
V_674 = 0x01 ;
V_658 = F_305 ( V_22 -> V_194 , V_658 , V_676 ,
& V_674 , sizeof( V_674 ) ) ;
if ( F_21 ( V_6 , V_118 ) ) {
V_658 = F_305 ( V_22 -> V_194 , V_658 ,
V_677 ,
V_473 , sizeof( V_473 ) ) ;
V_658 = F_305 ( V_22 -> V_194 , V_658 ,
V_678 ,
rand , sizeof( rand ) ) ;
}
V_168 = F_59 ( V_6 ) ;
if ( ! F_21 ( V_6 , V_112 ) )
V_168 |= V_176 ;
V_658 = F_305 ( V_22 -> V_194 , V_658 , V_177 ,
& V_168 , sizeof( V_168 ) ) ;
break;
}
F_36 ( V_6 ) ;
F_26 ( V_19 , V_672 ) ;
V_230 = V_290 ;
V_427:
V_22 -> type = V_155 -> type ;
V_22 -> V_658 = F_11 ( V_658 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_665 ,
V_230 , V_22 , sizeof( * V_22 ) + V_658 ) ;
if ( V_34 < 0 || V_230 )
goto V_380;
V_34 = F_5 ( V_673 , V_6 ,
V_22 , sizeof( * V_22 ) + V_658 ,
V_672 , V_19 ) ;
V_380:
F_17 ( V_22 ) ;
return V_34 ;
}
static T_6 F_311 ( struct V_5 * V_6 )
{
T_6 V_168 = 0 ;
V_168 |= V_172 ;
V_168 |= V_174 ;
V_168 |= V_175 ;
V_168 |= V_170 ;
if ( V_6 -> V_180 != V_181 )
V_168 |= V_169 ;
return V_168 ;
}
static int F_312 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_679 * V_22 ;
T_3 V_46 ;
int V_34 , V_33 ;
bool V_147 ;
struct V_148 * V_149 ;
T_6 V_680 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
if ( ! F_41 ( V_6 ) )
return F_112 ( V_19 , V_6 -> V_59 , V_681 ,
V_289 ) ;
F_35 ( V_6 ) ;
V_46 = sizeof( * V_22 ) ;
V_147 = F_21 ( V_6 , V_138 ) ;
if ( V_147 )
V_46 += V_6 -> V_682 ;
V_22 = F_15 ( V_46 , V_52 ) ;
if ( ! V_22 ) {
F_36 ( V_6 ) ;
return - V_40 ;
}
V_680 = F_311 ( V_6 ) ;
V_22 -> V_680 = F_31 ( V_680 ) ;
V_22 -> V_683 = V_144 ;
V_22 -> V_684 = V_144 ;
V_22 -> V_685 = V_686 ;
if ( V_147 ) {
V_33 = 0 ;
F_20 (adv_instance, &hdev->adv_instances, list) {
if ( V_33 >= V_6 -> V_682 )
break;
V_22 -> V_147 [ V_33 ] = V_149 -> V_147 ;
V_33 ++ ;
}
V_22 -> V_687 = V_6 -> V_682 ;
} else {
V_22 -> V_687 = 0 ;
}
F_36 ( V_6 ) ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_681 ,
V_290 , V_22 , V_46 ) ;
F_17 ( V_22 ) ;
return V_34 ;
}
static bool F_313 ( struct V_5 * V_6 , T_6 V_688 , T_1 * V_7 ,
T_1 V_8 , bool V_689 )
{
T_1 V_143 = V_144 ;
int V_33 , V_690 ;
bool V_691 = false ;
bool V_692 = false ;
T_6 V_693 = V_174 | V_175 |
V_170 ;
if ( V_689 && ( V_688 & V_693 ) ) {
V_691 = true ;
V_143 -= 3 ;
}
if ( V_689 && ( V_688 & V_169 ) ) {
V_692 = true ;
V_143 -= 3 ;
}
if ( V_8 > V_143 )
return false ;
for ( V_33 = 0 , V_690 = 0 ; V_33 < V_8 ; V_33 += ( V_690 + 1 ) ) {
V_690 = V_7 [ V_33 ] ;
if ( V_691 && V_7 [ V_33 + 1 ] == V_177 )
return false ;
if ( V_692 && V_7 [ V_33 + 1 ] == V_182 )
return false ;
if ( V_33 + V_690 >= V_8 )
return false ;
}
return true ;
}
static void F_314 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_137 * V_159 ;
struct V_694 * V_155 ;
struct V_695 V_22 ;
struct V_148 * V_149 , * V_261 ;
T_1 V_147 ;
F_10 ( L_19 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_696 , V_6 ) ;
if ( V_230 )
F_77 ( V_6 , V_138 ) ;
F_105 (adv_instance, n, &hdev->adv_instances, list) {
if ( ! V_149 -> V_697 )
continue;
if ( ! V_230 ) {
V_149 -> V_697 = false ;
continue;
}
V_147 = V_149 -> V_147 ;
if ( V_6 -> V_139 == V_147 )
F_102 ( V_6 ) ;
F_106 ( V_6 , V_147 ) ;
F_98 ( V_159 ? V_159 -> V_19 : NULL , V_6 , V_147 ) ;
}
if ( ! V_159 )
goto V_292;
V_155 = V_159 -> V_162 ;
V_22 . V_147 = V_155 -> V_147 ;
if ( V_230 )
F_112 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 ,
F_1 ( V_230 ) ) ;
else
F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 ,
F_1 ( V_230 ) , & V_22 , sizeof( V_22 ) ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
void F_315 ( struct V_5 * V_6 )
{
T_1 V_147 ;
struct V_152 V_153 ;
V_6 -> V_254 = 0 ;
V_147 = F_52 ( V_6 ) ;
if ( V_147 == 0x00 )
return;
F_35 ( V_6 ) ;
F_67 ( & V_153 , V_6 ) ;
F_103 ( V_6 , & V_153 , V_147 , false ) ;
if ( F_107 ( & V_6 -> V_264 ) )
F_74 ( & V_153 ) ;
if ( ! F_316 ( & V_153 . V_698 ) )
F_68 ( & V_153 , NULL ) ;
F_36 ( V_6 ) ;
}
static int F_317 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_694 * V_155 = V_7 ;
struct V_695 V_22 ;
T_6 V_168 ;
T_6 V_680 ;
T_1 V_230 ;
T_2 V_252 , V_257 ;
unsigned int V_699 = V_6 -> V_682 ;
T_1 V_700 = 0 ;
struct V_148 * V_262 ;
int V_34 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
V_230 = F_127 ( V_6 ) ;
if ( V_230 )
return F_112 ( V_19 , V_6 -> V_59 , V_696 ,
V_230 ) ;
V_168 = F_318 ( V_155 -> V_168 ) ;
V_252 = F_131 ( V_155 -> V_252 ) ;
V_257 = F_131 ( V_155 -> V_257 ) ;
V_680 = F_311 ( V_6 ) ;
if ( V_168 & ~ V_680 )
return F_112 ( V_19 , V_6 -> V_59 , V_696 ,
V_274 ) ;
F_35 ( V_6 ) ;
if ( V_252 && ! F_43 ( V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_696 ,
V_289 ) ;
goto V_292;
}
if ( F_48 ( V_696 , V_6 ) ||
F_48 ( V_701 , V_6 ) ||
F_48 ( V_333 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_696 ,
V_275 ) ;
goto V_292;
}
if ( ! F_313 ( V_6 , V_168 , V_155 -> V_7 , V_155 -> V_179 , true ) ||
! F_313 ( V_6 , V_168 , V_155 -> V_7 + V_155 -> V_179 ,
V_155 -> V_151 , false ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_696 ,
V_274 ) ;
goto V_292;
}
V_34 = F_319 ( V_6 , V_155 -> V_147 , V_168 ,
V_155 -> V_179 , V_155 -> V_7 ,
V_155 -> V_151 ,
V_155 -> V_7 + V_155 -> V_179 ,
V_252 , V_257 ) ;
if ( V_34 < 0 ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_696 ,
V_3 ) ;
goto V_292;
}
if ( V_6 -> V_682 > V_699 )
F_97 ( V_19 , V_6 , V_155 -> V_147 ) ;
F_83 ( V_6 , V_138 ) ;
if ( V_6 -> V_139 == V_155 -> V_147 ) {
F_102 ( V_6 ) ;
V_262 = F_104 ( V_6 , V_155 -> V_147 ) ;
if ( V_262 )
V_700 = V_262 -> V_147 ;
} else if ( ! V_6 -> V_254 ) {
V_700 = V_155 -> V_147 ;
}
if ( ! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) ||
! V_700 ) {
V_22 . V_147 = V_155 -> V_147 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 , V_696 ,
V_290 , & V_22 , sizeof( V_22 ) ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_696 , V_6 , V_7 ,
V_20 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
V_34 = F_99 ( & V_153 , V_700 , true ) ;
if ( ! V_34 )
V_34 = F_68 ( & V_153 , F_314 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
static void F_320 ( struct V_5 * V_6 , T_1 V_230 ,
T_2 V_41 )
{
struct V_137 * V_159 ;
struct V_702 * V_155 ;
struct V_703 V_22 ;
F_10 ( L_19 , V_230 ) ;
F_35 ( V_6 ) ;
V_159 = F_48 ( V_701 , V_6 ) ;
if ( ! V_159 )
goto V_292;
V_155 = V_159 -> V_162 ;
V_22 . V_147 = V_155 -> V_147 ;
F_12 ( V_159 -> V_19 , V_159 -> V_58 , V_159 -> V_41 , V_290 ,
& V_22 , sizeof( V_22 ) ) ;
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
}
static int F_321 ( struct V_11 * V_19 , struct V_5 * V_6 ,
void * V_7 , T_2 V_20 )
{
struct V_702 * V_155 = V_7 ;
struct V_703 V_22 ;
struct V_137 * V_159 ;
struct V_152 V_153 ;
int V_34 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_35 ( V_6 ) ;
if ( V_155 -> V_147 && ! F_55 ( V_6 , V_155 -> V_147 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 ,
V_701 ,
V_274 ) ;
goto V_292;
}
if ( F_48 ( V_696 , V_6 ) ||
F_48 ( V_701 , V_6 ) ||
F_48 ( V_333 , V_6 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_701 ,
V_275 ) ;
goto V_292;
}
if ( ! F_21 ( V_6 , V_138 ) ) {
V_34 = F_112 ( V_19 , V_6 -> V_59 , V_701 ,
V_274 ) ;
goto V_292;
}
F_67 ( & V_153 , V_6 ) ;
F_103 ( V_6 , & V_153 , V_155 -> V_147 , true ) ;
if ( F_107 ( & V_6 -> V_264 ) )
F_74 ( & V_153 ) ;
if ( F_316 ( & V_153 . V_698 ) ||
! F_43 ( V_6 ) ||
F_21 ( V_6 , V_117 ) ) {
V_22 . V_147 = V_155 -> V_147 ;
V_34 = F_12 ( V_19 , V_6 -> V_59 ,
V_701 ,
V_290 , & V_22 , sizeof( V_22 ) ) ;
goto V_292;
}
V_159 = F_113 ( V_19 , V_701 , V_6 , V_7 ,
V_20 ) ;
if ( ! V_159 ) {
V_34 = - V_40 ;
goto V_292;
}
V_34 = F_68 ( & V_153 , F_320 ) ;
if ( V_34 < 0 )
F_122 ( V_159 ) ;
V_292:
F_36 ( V_6 ) ;
return V_34 ;
}
void F_303 ( struct V_5 * V_6 )
{
struct V_704 V_247 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_705 , V_6 ,
NULL , 0 , V_70 ) ;
V_247 . type = 0x01 ;
} else {
F_3 ( V_706 , V_6 , NULL , 0 ,
V_69 ) ;
V_247 . type = 0x00 ;
}
break;
case V_65 :
V_247 . type = 0x02 ;
break;
default:
return;
}
V_247 . V_67 = V_6 -> V_67 ;
F_3 ( V_707 , V_6 , & V_247 , sizeof( V_247 ) ,
V_68 ) ;
}
void F_301 ( struct V_5 * V_6 )
{
struct V_704 V_247 ;
T_1 V_230 = V_708 ;
if ( F_23 ( V_56 , & V_6 -> V_57 ) )
return;
switch ( V_6 -> V_49 ) {
case V_50 :
F_147 ( 0 , V_6 , F_123 , & V_230 ) ;
if ( F_21 ( V_6 , V_51 ) ) {
F_3 ( V_709 , V_6 ,
NULL , 0 , V_70 ) ;
V_247 . type = 0x01 ;
} else {
F_3 ( V_710 , V_6 , NULL , 0 ,
V_69 ) ;
V_247 . type = 0x00 ;
}
break;
case V_65 :
V_247 . type = 0x02 ;
break;
default:
return;
}
V_247 . V_67 = V_6 -> V_67 ;
F_3 ( V_711 , V_6 , & V_247 , sizeof( V_247 ) ,
V_68 ) ;
}
static void F_322 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_374 * V_435 ;
F_20 (p, &hdev->le_conn_params, list) {
F_287 ( & V_435 -> V_619 ) ;
switch ( V_435 -> V_383 ) {
case V_624 :
case V_625 :
F_288 ( & V_435 -> V_619 , & V_6 -> V_621 ) ;
break;
case V_622 :
F_288 ( & V_435 -> V_619 , & V_6 -> V_623 ) ;
break;
default:
break;
}
}
F_149 ( V_153 ) ;
}
static void F_323 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
struct V_282 V_283 = { NULL , V_6 } ;
F_10 ( L_8 , V_230 ) ;
if ( ! V_230 ) {
F_324 ( V_6 ) ;
}
F_35 ( V_6 ) ;
F_147 ( V_273 , V_6 , F_117 , & V_283 ) ;
F_115 ( V_6 , V_283 . V_19 ) ;
F_36 ( V_6 ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
}
static int F_325 ( struct V_5 * V_6 )
{
struct V_152 V_153 ;
struct V_148 * V_149 ;
T_1 V_712 ;
F_67 ( & V_153 , V_6 ) ;
if ( F_21 ( V_6 , V_115 ) &&
! F_326 ( V_6 ) ) {
T_1 V_562 = 0x01 ;
F_57 ( & V_153 , V_331 , sizeof( V_562 ) , & V_562 ) ;
if ( F_219 ( V_6 ) && ! F_327 ( V_6 ) ) {
T_1 V_713 = 0x01 ;
F_57 ( & V_153 , V_559 ,
sizeof( V_713 ) , & V_713 ) ;
}
}
if ( F_21 ( V_6 , V_113 ) &&
F_38 ( V_6 ) ) {
struct V_334 V_155 ;
V_155 . V_337 = 0x01 ;
V_155 . V_338 = 0x00 ;
if ( V_155 . V_337 != F_151 ( V_6 ) ||
V_155 . V_338 != F_328 ( V_6 ) )
F_57 ( & V_153 , V_339 ,
sizeof( V_155 ) , & V_155 ) ;
}
if ( F_41 ( V_6 ) ) {
if ( F_21 ( V_6 , V_113 ) &&
( F_21 ( V_6 , V_117 ) ||
! F_21 ( V_6 , V_138 ) ) ) {
F_65 ( & V_153 ) ;
F_58 ( & V_153 ) ;
}
if ( F_21 ( V_6 , V_138 ) &&
V_6 -> V_139 == 0x00 &&
! F_107 ( & V_6 -> V_264 ) ) {
V_149 = F_329 ( & V_6 -> V_264 ,
struct V_148 , V_284 ) ;
V_6 -> V_139 = V_149 -> V_147 ;
}
if ( F_21 ( V_6 , V_117 ) )
F_75 ( & V_153 ) ;
else if ( F_21 ( V_6 , V_138 ) &&
V_6 -> V_139 )
F_99 ( & V_153 , V_6 -> V_139 ,
true ) ;
F_322 ( & V_153 ) ;
}
V_712 = F_21 ( V_6 , V_114 ) ;
if ( V_712 != F_23 ( V_326 , & V_6 -> V_168 ) )
F_57 ( & V_153 , V_327 ,
sizeof( V_712 ) , & V_712 ) ;
if ( F_38 ( V_6 ) ) {
if ( F_21 ( V_6 , V_109 ) )
F_134 ( & V_153 , true ) ;
else
F_134 ( & V_153 , false ) ;
F_129 ( & V_153 ) ;
F_73 ( & V_153 ) ;
F_214 ( & V_153 ) ;
F_70 ( & V_153 ) ;
}
return F_68 ( & V_153 , F_323 ) ;
}
int F_114 ( struct V_5 * V_6 , T_1 V_714 )
{
struct V_282 V_283 = { NULL , V_6 } ;
T_1 V_230 , V_715 [] = { 0 , 0 , 0 } ;
int V_34 ;
if ( ! F_21 ( V_6 , V_224 ) )
return 0 ;
if ( V_714 ) {
if ( F_325 ( V_6 ) == 0 )
return 0 ;
F_147 ( V_273 , V_6 , F_117 ,
& V_283 ) ;
goto F_115;
}
F_147 ( V_273 , V_6 , F_117 , & V_283 ) ;
if ( F_21 ( V_6 , V_716 ) )
V_230 = V_708 ;
else
V_230 = V_299 ;
F_147 ( 0 , V_6 , F_123 , & V_230 ) ;
if ( memcmp ( V_6 -> V_200 , V_715 , sizeof( V_715 ) ) != 0 )
F_6 ( V_717 , V_6 ,
V_715 , sizeof( V_715 ) , NULL ) ;
F_115:
V_34 = F_115 ( V_6 , V_283 . V_19 ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
return V_34 ;
}
void F_330 ( struct V_5 * V_6 , int V_34 )
{
struct V_137 * V_159 ;
T_1 V_230 ;
V_159 = F_48 ( V_273 , V_6 ) ;
if ( ! V_159 )
return;
if ( V_34 == - V_718 )
V_230 = V_719 ;
else
V_230 = V_3 ;
F_112 ( V_159 -> V_19 , V_6 -> V_59 , V_273 , V_230 ) ;
F_122 ( V_159 ) ;
}
void F_331 ( struct V_5 * V_6 )
{
struct V_152 V_153 ;
F_35 ( V_6 ) ;
F_77 ( V_6 , V_166 ) ;
F_77 ( V_6 , V_110 ) ;
F_67 ( & V_153 , V_6 ) ;
if ( F_21 ( V_6 , V_112 ) ) {
T_1 V_270 = V_301 ;
F_57 ( & V_153 , V_271 ,
sizeof( V_270 ) , & V_270 ) ;
}
F_73 ( & V_153 ) ;
if ( F_21 ( V_6 , V_117 ) )
F_65 ( & V_153 ) ;
F_68 ( & V_153 , NULL ) ;
V_6 -> V_295 = 0 ;
F_115 ( V_6 , NULL ) ;
F_36 ( V_6 ) ;
}
void F_332 ( struct V_5 * V_6 , struct V_720 * V_363 ,
bool V_721 )
{
struct V_722 V_247 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_723 = V_721 ;
F_88 ( & V_247 . V_363 . V_365 . V_122 , & V_363 -> V_122 ) ;
V_247 . V_363 . V_365 . type = V_366 ;
V_247 . V_363 . type = V_363 -> type ;
memcpy ( V_247 . V_363 . V_163 , V_363 -> V_163 , V_724 ) ;
V_247 . V_363 . V_368 = V_363 -> V_368 ;
F_7 ( V_725 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
static T_1 F_333 ( struct V_726 * V_727 )
{
switch ( V_727 -> type ) {
case V_581 :
case V_582 :
if ( V_727 -> V_579 )
return V_583 ;
return V_580 ;
case V_585 :
if ( V_727 -> V_579 )
return V_586 ;
return V_584 ;
case V_588 :
return V_587 ;
}
return V_580 ;
}
void F_334 ( struct V_5 * V_6 , struct V_726 * V_363 , bool V_721 )
{
struct V_728 V_247 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
if ( V_363 -> V_638 == V_18 &&
( V_363 -> V_122 . V_550 [ 5 ] & 0xc0 ) != 0xc0 )
V_247 . V_723 = 0x00 ;
else
V_247 . V_723 = V_721 ;
F_88 ( & V_247 . V_363 . V_365 . V_122 , & V_363 -> V_122 ) ;
V_247 . V_363 . V_365 . type = F_184 ( V_207 , V_363 -> V_638 ) ;
V_247 . V_363 . type = F_333 ( V_363 ) ;
V_247 . V_363 . V_589 = V_363 -> V_589 ;
V_247 . V_363 . V_590 = V_363 -> V_590 ;
V_247 . V_363 . rand = V_363 -> rand ;
if ( V_363 -> type == V_581 )
V_247 . V_363 . V_576 = 1 ;
memcpy ( V_247 . V_363 . V_163 , V_363 -> V_163 , V_363 -> V_589 ) ;
memset ( V_247 . V_363 . V_163 + V_363 -> V_589 , 0 ,
sizeof( V_247 . V_363 . V_163 ) - V_363 -> V_589 ) ;
F_7 ( V_729 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_335 ( struct V_5 * V_6 , struct V_730 * V_568 , bool V_721 )
{
struct V_731 V_247 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_723 = V_721 ;
F_88 ( & V_247 . V_732 , & V_568 -> V_732 ) ;
F_88 ( & V_247 . V_568 . V_365 . V_122 , & V_568 -> V_122 ) ;
V_247 . V_568 . V_365 . type = F_184 ( V_207 , V_568 -> V_369 ) ;
memcpy ( V_247 . V_568 . V_163 , V_568 -> V_163 , sizeof( V_568 -> V_163 ) ) ;
F_7 ( V_733 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_336 ( struct V_5 * V_6 , struct V_734 * V_735 ,
bool V_721 )
{
struct V_736 V_247 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
if ( V_735 -> V_638 == V_18 &&
( V_735 -> V_122 . V_550 [ 5 ] & 0xc0 ) != 0xc0 )
V_247 . V_723 = 0x00 ;
else
V_247 . V_723 = V_721 ;
F_88 ( & V_247 . V_363 . V_365 . V_122 , & V_735 -> V_122 ) ;
V_247 . V_363 . V_365 . type = F_184 ( V_207 , V_735 -> V_638 ) ;
V_247 . V_363 . type = V_735 -> type ;
memcpy ( V_247 . V_363 . V_163 , V_735 -> V_163 , sizeof( V_735 -> V_163 ) ) ;
F_7 ( V_737 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_337 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_638 , T_1 V_723 , T_2 V_209 ,
T_2 V_211 , T_2 V_647 , T_2 V_252 )
{
struct V_738 V_247 ;
if ( ! F_292 ( V_122 , V_638 ) )
return;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = F_184 ( V_207 , V_638 ) ;
V_247 . V_723 = V_723 ;
V_247 . V_209 = F_11 ( V_209 ) ;
V_247 . V_211 = F_11 ( V_211 ) ;
V_247 . V_647 = F_11 ( V_647 ) ;
V_247 . V_252 = F_11 ( V_252 ) ;
F_7 ( V_739 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_338 ( struct V_5 * V_6 , struct V_265 * V_266 ,
T_6 V_168 , T_1 * V_83 , T_1 V_141 )
{
char V_740 [ 512 ] ;
struct V_741 * V_247 = ( void * ) V_740 ;
T_2 V_658 = 0 ;
F_88 ( & V_247 -> V_365 . V_122 , & V_266 -> V_400 ) ;
V_247 -> V_365 . type = F_184 ( V_266 -> type , V_266 -> V_401 ) ;
V_247 -> V_168 = F_339 ( V_168 ) ;
if ( V_266 -> V_742 > 0 ) {
memcpy ( & V_247 -> V_194 [ V_658 ] ,
V_266 -> V_743 , V_266 -> V_742 ) ;
V_658 = V_266 -> V_742 ;
} else {
if ( V_141 > 0 )
V_658 = F_305 ( V_247 -> V_194 , 0 , V_146 ,
V_83 , V_141 ) ;
if ( memcmp ( V_266 -> V_200 , L_41 , 3 ) != 0 )
V_658 = F_305 ( V_247 -> V_194 , V_658 ,
V_667 ,
V_266 -> V_200 , 3 ) ;
}
V_247 -> V_658 = F_11 ( V_658 ) ;
F_7 ( V_744 , V_6 , V_740 ,
sizeof( * V_247 ) + V_658 , NULL ) ;
}
static void F_340 ( struct V_137 * V_159 , void * V_7 )
{
struct V_11 * * V_19 = V_7 ;
V_159 -> V_285 ( V_159 , 0 ) ;
* V_19 = V_159 -> V_19 ;
F_119 ( * V_19 ) ;
F_122 ( V_159 ) ;
}
static void F_341 ( struct V_137 * V_159 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_372 * V_155 = V_159 -> V_162 ;
F_170 ( V_6 , & V_155 -> V_365 . V_122 , V_155 -> V_365 . type , V_159 -> V_19 ) ;
V_159 -> V_285 ( V_159 , 0 ) ;
F_122 ( V_159 ) ;
}
bool F_342 ( struct V_5 * V_6 )
{
struct V_137 * V_159 ;
struct V_161 * V_155 ;
V_159 = F_48 ( V_273 , V_6 ) ;
if ( ! V_159 )
return false ;
V_155 = V_159 -> V_162 ;
if ( ! V_155 -> V_163 )
return true ;
return false ;
}
void F_343 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_745 ,
bool V_746 )
{
struct V_747 V_247 ;
struct V_11 * V_19 = NULL ;
if ( F_342 ( V_6 ) && F_91 ( V_6 ) == 1 ) {
F_92 ( & V_6 -> V_231 ) ;
F_93 ( V_6 -> V_232 , & V_6 -> V_231 . V_221 ) ;
}
if ( ! V_746 )
return;
if ( V_394 != V_378 && V_394 != V_207 )
return;
F_147 ( V_389 , V_6 , F_340 , & V_19 ) ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = F_184 ( V_394 , V_369 ) ;
V_247 . V_745 = V_745 ;
F_7 ( V_748 , V_6 , & V_247 , sizeof( V_247 ) , V_19 ) ;
if ( V_19 )
F_148 ( V_19 ) ;
F_147 ( V_376 , V_6 , F_341 ,
V_6 ) ;
}
void F_344 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_230 )
{
T_1 V_638 = F_184 ( V_394 , V_369 ) ;
struct V_387 * V_155 ;
struct V_137 * V_159 ;
F_147 ( V_376 , V_6 , F_341 ,
V_6 ) ;
V_159 = F_48 ( V_389 , V_6 ) ;
if ( ! V_159 )
return;
V_155 = V_159 -> V_162 ;
if ( F_29 ( V_122 , & V_155 -> V_365 . V_122 ) )
return;
if ( V_155 -> V_365 . type != V_638 )
return;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
void F_345 ( struct V_5 * V_6 , T_8 * V_122 , T_1 V_394 ,
T_1 V_369 , T_1 V_230 )
{
struct V_749 V_247 ;
if ( F_342 ( V_6 ) && F_91 ( V_6 ) == 1 ) {
F_92 ( & V_6 -> V_231 ) ;
F_93 ( V_6 -> V_232 , & V_6 -> V_231 . V_221 ) ;
}
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = F_184 ( V_394 , V_369 ) ;
V_247 . V_230 = F_1 ( V_230 ) ;
F_7 ( V_750 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_346 ( struct V_5 * V_6 , T_8 * V_122 , T_1 V_751 )
{
struct V_752 V_247 ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = V_366 ;
V_247 . V_751 = V_751 ;
F_7 ( V_753 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_347 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_230 )
{
struct V_137 * V_159 ;
V_159 = F_48 ( V_411 , V_6 ) ;
if ( ! V_159 )
return;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
void F_348 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_230 )
{
struct V_137 * V_159 ;
V_159 = F_48 ( V_406 , V_6 ) ;
if ( ! V_159 )
return;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
}
int F_349 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_6 V_754 ,
T_1 V_755 )
{
struct V_756 V_247 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = F_184 ( V_394 , V_369 ) ;
V_247 . V_755 = V_755 ;
V_247 . V_754 = F_31 ( V_754 ) ;
return F_7 ( V_757 , V_6 , & V_247 , sizeof( V_247 ) ,
NULL ) ;
}
int F_350 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 )
{
struct V_758 V_247 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = F_184 ( V_394 , V_369 ) ;
return F_7 ( V_759 , V_6 , & V_247 , sizeof( V_247 ) ,
NULL ) ;
}
static int F_351 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_230 ,
T_1 V_41 )
{
struct V_137 * V_159 ;
V_159 = F_48 ( V_41 , V_6 ) ;
if ( ! V_159 )
return - V_256 ;
V_159 -> V_285 ( V_159 , F_1 ( V_230 ) ) ;
F_122 ( V_159 ) ;
return 0 ;
}
int F_352 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_230 )
{
return F_351 ( V_6 , V_122 , V_394 , V_369 ,
V_230 , V_450 ) ;
}
int F_353 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_230 )
{
return F_351 ( V_6 , V_122 , V_394 , V_369 ,
V_230 ,
V_453 ) ;
}
int F_354 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_230 )
{
return F_351 ( V_6 , V_122 , V_394 , V_369 ,
V_230 , V_456 ) ;
}
int F_355 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_1 V_230 )
{
return F_351 ( V_6 , V_122 , V_394 , V_369 ,
V_230 ,
V_458 ) ;
}
int F_356 ( struct V_5 * V_6 , T_8 * V_122 ,
T_1 V_394 , T_1 V_369 , T_6 V_446 ,
T_1 V_760 )
{
struct V_761 V_247 ;
F_10 ( L_4 , V_6 -> V_83 ) ;
F_88 ( & V_247 . V_365 . V_122 , V_122 ) ;
V_247 . V_365 . type = F_184 ( V_394 , V_369 ) ;
V_247 . V_446 = F_339 ( V_446 ) ;
V_247 . V_760 = V_760 ;
return F_7 ( V_762 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
void F_357 ( struct V_265 * V_266 , T_1 V_1 )
{
struct V_763 V_247 ;
struct V_137 * V_159 ;
T_1 V_230 = F_1 ( V_1 ) ;
F_88 ( & V_247 . V_365 . V_122 , & V_266 -> V_400 ) ;
V_247 . V_365 . type = F_184 ( V_266 -> type , V_266 -> V_401 ) ;
V_247 . V_230 = V_230 ;
V_159 = F_189 ( V_266 ) ;
F_7 ( V_764 , V_266 -> V_6 , & V_247 , sizeof( V_247 ) ,
V_159 ? V_159 -> V_19 : NULL ) ;
if ( V_159 ) {
V_159 -> V_285 ( V_159 , V_230 ) ;
F_122 ( V_159 ) ;
}
}
void F_358 ( struct V_5 * V_6 , T_1 V_230 )
{
struct V_282 V_283 = { NULL , V_6 } ;
bool V_291 ;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
F_147 ( V_325 , V_6 ,
F_121 , & V_293 ) ;
return;
}
if ( F_23 ( V_326 , & V_6 -> V_168 ) )
V_291 = ! F_85 ( V_6 , V_114 ) ;
else
V_291 = F_81 ( V_6 , V_114 ) ;
F_147 ( V_325 , V_6 , F_117 ,
& V_283 ) ;
if ( V_291 )
F_115 ( V_6 , V_283 . V_19 ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
}
static void F_359 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_192 V_155 ;
if ( ! F_71 ( V_6 ) )
return;
memset ( V_6 -> V_194 , 0 , sizeof( V_6 -> V_194 ) ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
F_57 ( V_153 , V_195 , sizeof( V_155 ) , & V_155 ) ;
}
void F_360 ( struct V_5 * V_6 , T_1 V_202 , T_1 V_230 )
{
struct V_282 V_283 = { NULL , V_6 } ;
struct V_152 V_153 ;
bool V_291 = false ;
if ( V_230 ) {
T_1 V_293 = F_1 ( V_230 ) ;
if ( V_202 && F_81 ( V_6 ,
V_115 ) ) {
F_77 ( V_6 , V_116 ) ;
F_115 ( V_6 , NULL ) ;
}
F_147 ( V_328 , V_6 , F_121 ,
& V_293 ) ;
return;
}
if ( V_202 ) {
V_291 = ! F_85 ( V_6 , V_115 ) ;
} else {
V_291 = F_81 ( V_6 , V_115 ) ;
if ( ! V_291 )
V_291 = F_81 ( V_6 ,
V_116 ) ;
else
F_77 ( V_6 , V_116 ) ;
}
F_147 ( V_328 , V_6 , F_117 , & V_283 ) ;
if ( V_291 )
F_115 ( V_6 , V_283 . V_19 ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
F_67 ( & V_153 , V_6 ) ;
if ( F_21 ( V_6 , V_115 ) ) {
if ( F_21 ( V_6 , V_329 ) )
F_57 ( & V_153 , V_330 ,
sizeof( V_202 ) , & V_202 ) ;
F_70 ( & V_153 ) ;
} else {
F_359 ( & V_153 ) ;
}
F_68 ( & V_153 , NULL ) ;
}
static void F_361 ( struct V_137 * V_159 , void * V_7 )
{
struct V_282 * V_283 = V_7 ;
if ( V_283 -> V_19 == NULL ) {
V_283 -> V_19 = V_159 -> V_19 ;
F_119 ( V_283 -> V_19 ) ;
}
}
void F_362 ( struct V_5 * V_6 , T_1 * V_200 ,
T_1 V_230 )
{
struct V_282 V_283 = { NULL , V_6 , F_1 (status) } ;
F_147 ( V_342 , V_6 , F_361 , & V_283 ) ;
F_147 ( V_340 , V_6 , F_361 , & V_283 ) ;
F_147 ( V_341 , V_6 , F_361 , & V_283 ) ;
if ( ! V_230 )
F_6 ( V_717 , V_6 ,
V_200 , 3 , NULL ) ;
if ( V_283 . V_19 )
F_148 ( V_283 . V_19 ) ;
}
void F_363 ( struct V_5 * V_6 , T_1 * V_83 , T_1 V_230 )
{
struct V_462 V_247 ;
struct V_137 * V_159 ;
if ( V_230 )
return;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
memcpy ( V_247 . V_83 , V_83 , V_765 ) ;
memcpy ( V_247 . V_228 , V_6 -> V_228 , V_766 ) ;
V_159 = F_48 ( V_463 , V_6 ) ;
if ( ! V_159 ) {
memcpy ( V_6 -> V_142 , V_83 , sizeof( V_6 -> V_142 ) ) ;
if ( F_48 ( V_273 , V_6 ) )
return;
}
F_6 ( V_464 , V_6 , & V_247 , sizeof( V_247 ) ,
V_159 ? V_159 -> V_19 : NULL ) ;
}
static void F_364 ( struct V_5 * V_6 )
{
if ( ! F_21 ( V_6 , V_241 ) )
return;
if ( F_278 ( V_515 + V_767 ,
V_6 -> V_236 . V_514 +
V_6 -> V_236 . V_516 ) )
return;
F_100 ( V_6 -> V_259 , & V_6 -> V_768 ,
V_767 ) ;
}
static bool F_365 ( struct V_5 * V_6 , T_10 V_524 , T_1 * V_194 ,
T_2 V_658 , T_1 * V_769 , T_1 V_151 )
{
if ( V_6 -> V_236 . V_524 != V_594 &&
( V_524 == V_594 ||
( V_524 < V_6 -> V_236 . V_524 &&
! F_23 ( V_512 , & V_6 -> V_57 ) ) ) )
return false ;
if ( V_6 -> V_236 . V_523 != 0 ) {
if ( ! F_366 ( V_194 , V_658 , V_6 -> V_236 . V_523 ,
V_6 -> V_236 . V_346 ) &&
! F_366 ( V_769 , V_151 ,
V_6 -> V_236 . V_523 ,
V_6 -> V_236 . V_346 ) )
return false ;
}
if ( F_23 ( V_512 , & V_6 -> V_57 ) ) {
F_364 ( V_6 ) ;
if ( V_6 -> V_236 . V_524 != V_594 &&
V_524 < V_6 -> V_236 . V_524 )
return false ;
}
return true ;
}
void F_367 ( struct V_5 * V_6 , T_8 * V_122 , T_1 V_394 ,
T_1 V_369 , T_1 * V_200 , T_10 V_524 , T_6 V_168 ,
T_1 * V_194 , T_2 V_658 , T_1 * V_769 , T_1 V_151 )
{
char V_740 [ 512 ] ;
struct V_770 * V_247 = ( void * ) V_740 ;
T_3 V_771 ;
if ( ! F_240 ( V_6 ) ) {
if ( V_394 == V_378 )
return;
if ( V_394 == V_207 && F_107 ( & V_6 -> V_623 ) )
return;
}
if ( V_6 -> V_236 . V_513 ) {
if ( ! F_365 ( V_6 , V_524 , V_194 , V_658 , V_769 ,
V_151 ) )
return;
}
if ( sizeof( * V_247 ) + V_658 + V_151 + 5 > sizeof( V_740 ) )
return;
memset ( V_740 , 0 , sizeof( V_740 ) ) ;
if ( V_524 == V_594 && ! V_6 -> V_236 . V_519 &&
V_394 == V_378 )
V_524 = 0 ;
F_88 ( & V_247 -> V_365 . V_122 , V_122 ) ;
V_247 -> V_365 . type = F_184 ( V_394 , V_369 ) ;
V_247 -> V_524 = V_524 ;
V_247 -> V_168 = F_31 ( V_168 ) ;
if ( V_658 > 0 )
memcpy ( V_247 -> V_194 , V_194 , V_658 ) ;
if ( V_200 && ! F_368 ( V_247 -> V_194 , V_658 , V_667 ) )
V_658 = F_305 ( V_247 -> V_194 , V_658 , V_667 ,
V_200 , 3 ) ;
if ( V_151 > 0 )
memcpy ( V_247 -> V_194 + V_658 , V_769 , V_151 ) ;
V_247 -> V_658 = F_11 ( V_658 + V_151 ) ;
V_771 = sizeof( * V_247 ) + V_658 + V_151 ;
F_7 ( V_772 , V_6 , V_247 , V_771 , NULL ) ;
}
void F_369 ( struct V_5 * V_6 , T_8 * V_122 , T_1 V_394 ,
T_1 V_369 , T_10 V_524 , T_1 * V_83 , T_1 V_141 )
{
struct V_770 * V_247 ;
char V_740 [ sizeof( * V_247 ) + V_765 + 2 ] ;
T_2 V_658 ;
V_247 = (struct V_770 * ) V_740 ;
memset ( V_740 , 0 , sizeof( V_740 ) ) ;
F_88 ( & V_247 -> V_365 . V_122 , V_122 ) ;
V_247 -> V_365 . type = F_184 ( V_394 , V_369 ) ;
V_247 -> V_524 = V_524 ;
V_658 = F_305 ( V_247 -> V_194 , 0 , V_146 , V_83 ,
V_141 ) ;
V_247 -> V_658 = F_11 ( V_658 ) ;
F_7 ( V_772 , V_6 , V_247 , sizeof( * V_247 ) + V_658 , NULL ) ;
}
void F_370 ( struct V_5 * V_6 , T_1 V_773 )
{
struct V_774 V_247 ;
F_10 ( L_42 , V_6 -> V_83 , V_773 ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . type = V_6 -> V_236 . type ;
V_247 . V_773 = V_773 ;
F_7 ( V_775 , V_6 , & V_247 , sizeof( V_247 ) , NULL ) ;
}
static void F_371 ( struct V_5 * V_6 , T_1 V_230 , T_2 V_41 )
{
F_10 ( L_16 , V_6 -> V_83 , V_230 ) ;
}
void F_372 ( struct V_5 * V_6 )
{
struct V_152 V_153 ;
T_1 V_147 ;
if ( ! F_21 ( V_6 , V_117 ) &&
! F_21 ( V_6 , V_138 ) )
return;
V_147 = F_52 ( V_6 ) ;
F_67 ( & V_153 , V_6 ) ;
if ( V_147 ) {
F_99 ( & V_153 , V_147 , true ) ;
} else {
F_65 ( & V_153 ) ;
F_58 ( & V_153 ) ;
F_75 ( & V_153 ) ;
}
F_68 ( & V_153 , F_371 ) ;
}
int F_373 ( void )
{
return F_374 ( & V_776 ) ;
}
void F_375 ( void )
{
F_376 ( & V_776 ) ;
}
