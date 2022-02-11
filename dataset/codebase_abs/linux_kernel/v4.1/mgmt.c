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
static int F_8 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_16 )
{
struct V_17 V_18 ;
F_9 ( L_1 , V_15 ) ;
V_18 . V_19 = V_20 ;
V_18 . V_21 = F_10 ( V_22 ) ;
return F_11 ( V_15 , V_23 , V_24 , 0 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_12 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_16 )
{
struct V_25 * V_18 ;
T_2 V_26 , V_27 ;
T_3 V_28 ;
int V_29 , V_30 ;
F_9 ( L_1 , V_15 ) ;
if ( F_13 ( V_15 , V_14 ) ) {
V_26 = F_2 ( V_31 ) ;
V_27 = F_2 ( V_32 ) ;
} else {
V_26 = F_2 ( V_33 ) ;
V_27 = F_2 ( V_34 ) ;
}
V_28 = sizeof( * V_18 ) + ( ( V_26 + V_27 ) * sizeof( T_2 ) ) ;
V_18 = F_14 ( V_28 , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_18 -> V_26 = F_10 ( V_26 ) ;
V_18 -> V_27 = F_10 ( V_27 ) ;
if ( F_13 ( V_15 , V_14 ) ) {
T_4 * V_37 = V_18 -> V_38 ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ , V_37 ++ )
F_15 ( V_31 [ V_29 ] , V_37 ) ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ , V_37 ++ )
F_15 ( V_32 [ V_29 ] , V_37 ) ;
} else {
T_4 * V_37 = V_18 -> V_38 ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ , V_37 ++ )
F_15 ( V_33 [ V_29 ] , V_37 ) ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ , V_37 ++ )
F_15 ( V_34 [ V_29 ] , V_37 ) ;
}
V_30 = F_11 ( V_15 , V_23 , V_39 , 0 ,
V_18 , V_28 ) ;
F_16 ( V_18 ) ;
return V_30 ;
}
static int F_17 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_16 )
{
struct V_40 * V_18 ;
struct V_5 * V_41 ;
T_3 V_42 ;
T_2 V_43 ;
int V_30 ;
F_9 ( L_1 , V_15 ) ;
F_18 ( & V_44 ) ;
V_43 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( V_41 -> V_45 == V_46 &&
! F_20 ( V_41 , V_47 ) )
V_43 ++ ;
}
V_42 = sizeof( * V_18 ) + ( 2 * V_43 ) ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 ) {
F_21 ( & V_44 ) ;
return - V_36 ;
}
V_43 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( F_20 ( V_41 , V_49 ) ||
F_20 ( V_41 , V_50 ) ||
F_20 ( V_41 , V_51 ) )
continue;
if ( F_22 ( V_52 , & V_41 -> V_53 ) )
continue;
if ( V_41 -> V_45 == V_46 &&
! F_20 ( V_41 , V_47 ) ) {
V_18 -> V_54 [ V_43 ++ ] = F_10 ( V_41 -> V_55 ) ;
F_9 ( L_2 , V_41 -> V_55 ) ;
}
}
V_18 -> V_56 = F_10 ( V_43 ) ;
V_42 = sizeof( * V_18 ) + ( 2 * V_43 ) ;
F_21 ( & V_44 ) ;
V_30 = F_11 ( V_15 , V_23 , V_57 ,
0 , V_18 , V_42 ) ;
F_16 ( V_18 ) ;
return V_30 ;
}
static int F_23 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_58 * V_18 ;
struct V_5 * V_41 ;
T_3 V_42 ;
T_2 V_43 ;
int V_30 ;
F_9 ( L_1 , V_15 ) ;
F_18 ( & V_44 ) ;
V_43 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( V_41 -> V_45 == V_46 &&
F_20 ( V_41 , V_47 ) )
V_43 ++ ;
}
V_42 = sizeof( * V_18 ) + ( 2 * V_43 ) ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 ) {
F_21 ( & V_44 ) ;
return - V_36 ;
}
V_43 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( F_20 ( V_41 , V_49 ) ||
F_20 ( V_41 , V_50 ) ||
F_20 ( V_41 , V_51 ) )
continue;
if ( F_22 ( V_52 , & V_41 -> V_53 ) )
continue;
if ( V_41 -> V_45 == V_46 &&
F_20 ( V_41 , V_47 ) ) {
V_18 -> V_54 [ V_43 ++ ] = F_10 ( V_41 -> V_55 ) ;
F_9 ( L_2 , V_41 -> V_55 ) ;
}
}
V_18 -> V_56 = F_10 ( V_43 ) ;
V_42 = sizeof( * V_18 ) + ( 2 * V_43 ) ;
F_21 ( & V_44 ) ;
V_30 = F_11 ( V_15 , V_23 ,
V_59 , 0 , V_18 , V_42 ) ;
F_16 ( V_18 ) ;
return V_30 ;
}
static int F_24 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_60 * V_18 ;
struct V_5 * V_41 ;
T_3 V_42 ;
T_2 V_43 ;
int V_30 ;
F_9 ( L_1 , V_15 ) ;
F_18 ( & V_44 ) ;
V_43 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( V_41 -> V_45 == V_46 || V_41 -> V_45 == V_61 )
V_43 ++ ;
}
V_42 = sizeof( * V_18 ) + ( sizeof( V_18 -> V_62 [ 0 ] ) * V_43 ) ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 ) {
F_21 ( & V_44 ) ;
return - V_36 ;
}
V_43 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( F_20 ( V_41 , V_49 ) ||
F_20 ( V_41 , V_50 ) ||
F_20 ( V_41 , V_51 ) )
continue;
if ( F_22 ( V_52 , & V_41 -> V_53 ) )
continue;
if ( V_41 -> V_45 == V_46 ) {
if ( F_20 ( V_41 , V_47 ) )
V_18 -> V_62 [ V_43 ] . type = 0x01 ;
else
V_18 -> V_62 [ V_43 ] . type = 0x00 ;
} else if ( V_41 -> V_45 == V_61 ) {
V_18 -> V_62 [ V_43 ] . type = 0x02 ;
} else {
continue;
}
V_18 -> V_62 [ V_43 ] . V_63 = V_41 -> V_63 ;
V_18 -> V_62 [ V_43 ++ ] . V_54 = F_10 ( V_41 -> V_55 ) ;
F_9 ( L_2 , V_41 -> V_55 ) ;
}
V_18 -> V_56 = F_10 ( V_43 ) ;
V_42 = sizeof( * V_18 ) + ( sizeof( V_18 -> V_62 [ 0 ] ) * V_43 ) ;
F_21 ( & V_44 ) ;
F_25 ( V_15 , V_64 ) ;
F_26 ( V_15 , V_65 ) ;
F_26 ( V_15 , V_66 ) ;
V_30 = F_11 ( V_15 , V_23 ,
V_67 , 0 , V_18 , V_42 ) ;
F_16 ( V_18 ) ;
return V_30 ;
}
static bool F_27 ( struct V_5 * V_6 )
{
if ( F_22 ( V_68 , & V_6 -> V_53 ) &&
! F_20 ( V_6 , V_69 ) )
return false ;
if ( F_22 ( V_70 , & V_6 -> V_53 ) &&
! F_28 ( & V_6 -> V_71 , V_72 ) )
return false ;
return true ;
}
static T_5 F_29 ( struct V_5 * V_6 )
{
T_6 V_73 = 0 ;
if ( F_22 ( V_68 , & V_6 -> V_53 ) &&
! F_20 ( V_6 , V_69 ) )
V_73 |= V_74 ;
if ( F_22 ( V_70 , & V_6 -> V_53 ) &&
! F_28 ( & V_6 -> V_71 , V_72 ) )
V_73 |= V_75 ;
return F_30 ( V_73 ) ;
}
static int F_31 ( struct V_5 * V_6 , struct V_11 * V_76 )
{
T_5 V_73 = F_29 ( V_6 ) ;
return F_6 ( V_77 , V_6 , & V_73 ,
sizeof( V_73 ) , V_76 ) ;
}
static int F_32 ( struct V_11 * V_15 , T_2 V_37 , struct V_5 * V_6 )
{
T_5 V_73 = F_29 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_37 , 0 , & V_73 ,
sizeof( V_73 ) ) ;
}
static int F_33 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_78 V_18 ;
T_6 V_73 = 0 ;
F_9 ( L_3 , V_15 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_80 = F_10 ( V_6 -> V_80 ) ;
if ( F_22 ( V_68 , & V_6 -> V_53 ) )
V_73 |= V_74 ;
if ( V_6 -> V_81 )
V_73 |= V_75 ;
V_18 . V_82 = F_30 ( V_73 ) ;
V_18 . V_83 = F_29 ( V_6 ) ;
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_84 , 0 ,
& V_18 , sizeof( V_18 ) ) ;
}
static T_6 F_36 ( struct V_5 * V_6 )
{
T_6 V_85 = 0 ;
V_85 |= V_86 ;
V_85 |= V_87 ;
V_85 |= V_88 ;
V_85 |= V_89 ;
V_85 |= V_90 ;
if ( F_37 ( V_6 ) ) {
if ( V_6 -> V_91 >= V_92 )
V_85 |= V_93 ;
V_85 |= V_94 ;
V_85 |= V_95 ;
if ( F_38 ( V_6 ) ) {
V_85 |= V_96 ;
V_85 |= V_97 ;
}
if ( F_39 ( V_6 ) )
V_85 |= V_98 ;
}
if ( F_40 ( V_6 ) ) {
V_85 |= V_99 ;
V_85 |= V_100 ;
V_85 |= V_98 ;
V_85 |= V_101 ;
V_85 |= V_102 ;
}
if ( F_22 ( V_68 , & V_6 -> V_53 ) ||
V_6 -> V_81 )
V_85 |= V_103 ;
return V_85 ;
}
static T_6 F_41 ( struct V_5 * V_6 )
{
T_6 V_85 = 0 ;
if ( F_42 ( V_6 ) )
V_85 |= V_86 ;
if ( F_20 ( V_6 , V_104 ) )
V_85 |= V_89 ;
if ( F_20 ( V_6 , V_105 ) )
V_85 |= V_93 ;
if ( F_20 ( V_6 , V_106 ) )
V_85 |= V_90 ;
if ( F_20 ( V_6 , V_107 ) )
V_85 |= V_87 ;
if ( F_20 ( V_6 , V_108 ) )
V_85 |= V_94 ;
if ( F_20 ( V_6 , V_109 ) )
V_85 |= V_99 ;
if ( F_20 ( V_6 , V_110 ) )
V_85 |= V_95 ;
if ( F_20 ( V_6 , V_111 ) )
V_85 |= V_96 ;
if ( F_20 ( V_6 , V_112 ) )
V_85 |= V_97 ;
if ( F_20 ( V_6 , V_113 ) )
V_85 |= V_100 ;
if ( F_20 ( V_6 , V_114 ) )
V_85 |= V_98 ;
if ( F_20 ( V_6 , V_115 ) )
V_85 |= V_88 ;
if ( F_20 ( V_6 , V_116 ) )
V_85 |= V_101 ;
if ( F_20 ( V_6 , V_117 ) ||
! F_20 ( V_6 , V_108 ) ||
! F_28 ( & V_6 -> V_118 , V_72 ) ) {
if ( F_28 ( & V_6 -> V_119 , V_72 ) )
V_85 |= V_102 ;
}
return V_85 ;
}
static T_1 * F_43 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_8 )
{
T_1 * V_120 = V_7 , * V_121 = NULL ;
struct V_122 * V_123 ;
if ( V_8 < 4 )
return V_120 ;
F_19 (uuid, &hdev->uuids, list) {
T_2 V_124 ;
if ( V_123 -> V_125 != 16 )
continue;
V_124 = F_44 ( & V_123 -> V_123 [ 12 ] ) ;
if ( V_124 < 0x1100 )
continue;
if ( V_124 == V_126 )
continue;
if ( ! V_121 ) {
V_121 = V_120 ;
V_121 [ 0 ] = 1 ;
V_121 [ 1 ] = V_127 ;
V_120 += 2 ;
}
if ( ( V_120 - V_7 ) + sizeof( T_2 ) > V_8 ) {
V_121 [ 1 ] = V_128 ;
break;
}
* V_120 ++ = ( V_124 & 0x00ff ) ;
* V_120 ++ = ( V_124 & 0xff00 ) >> 8 ;
V_121 [ 0 ] += sizeof( V_124 ) ;
}
return V_120 ;
}
static T_1 * F_45 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_8 )
{
T_1 * V_120 = V_7 , * V_121 = NULL ;
struct V_122 * V_123 ;
if ( V_8 < 6 )
return V_120 ;
F_19 (uuid, &hdev->uuids, list) {
if ( V_123 -> V_125 != 32 )
continue;
if ( ! V_121 ) {
V_121 = V_120 ;
V_121 [ 0 ] = 1 ;
V_121 [ 1 ] = V_129 ;
V_120 += 2 ;
}
if ( ( V_120 - V_7 ) + sizeof( T_6 ) > V_8 ) {
V_121 [ 1 ] = V_130 ;
break;
}
memcpy ( V_120 , & V_123 -> V_123 [ 12 ] , sizeof( T_6 ) ) ;
V_120 += sizeof( T_6 ) ;
V_121 [ 0 ] += sizeof( T_6 ) ;
}
return V_120 ;
}
static T_1 * F_46 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_8 )
{
T_1 * V_120 = V_7 , * V_121 = NULL ;
struct V_122 * V_123 ;
if ( V_8 < 18 )
return V_120 ;
F_19 (uuid, &hdev->uuids, list) {
if ( V_123 -> V_125 != 128 )
continue;
if ( ! V_121 ) {
V_121 = V_120 ;
V_121 [ 0 ] = 1 ;
V_121 [ 1 ] = V_131 ;
V_120 += 2 ;
}
if ( ( V_120 - V_7 ) + 16 > V_8 ) {
V_121 [ 1 ] = V_132 ;
break;
}
memcpy ( V_120 , V_123 -> V_123 , 16 ) ;
V_120 += 16 ;
V_121 [ 0 ] += 16 ;
}
return V_120 ;
}
static struct V_133 * F_47 ( T_2 V_37 , struct V_5 * V_6 )
{
return F_48 ( V_10 , V_37 , V_6 ) ;
}
static struct V_133 * F_49 ( T_2 V_37 ,
struct V_5 * V_6 ,
const void * V_7 )
{
return F_50 ( V_10 , V_37 , V_6 , V_7 ) ;
}
static T_1 F_51 ( struct V_5 * V_6 , T_1 * V_120 )
{
T_1 V_134 = 0 ;
T_3 V_135 ;
V_135 = strlen ( V_6 -> V_136 ) ;
if ( V_135 > 0 ) {
T_3 V_137 = V_138 - V_134 - 2 ;
if ( V_135 > V_137 ) {
V_135 = V_137 ;
V_120 [ 1 ] = V_139 ;
} else
V_120 [ 1 ] = V_140 ;
V_120 [ 0 ] = V_135 + 1 ;
memcpy ( V_120 + 2 , V_6 -> V_136 , V_135 ) ;
V_134 += ( V_135 + 2 ) ;
V_120 += ( V_135 + 2 ) ;
}
return V_134 ;
}
static T_1 F_52 ( struct V_5 * V_6 , T_1 * V_120 )
{
memcpy ( V_120 , V_6 -> V_141 . V_142 ,
V_6 -> V_141 . V_143 ) ;
return V_6 -> V_141 . V_143 ;
}
static void F_53 ( struct V_144 * V_145 ,
T_1 V_146 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_147 V_148 ;
T_1 V_8 ;
if ( ! F_20 ( V_6 , V_109 ) )
return;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_146 )
V_8 = F_52 ( V_6 , V_148 . V_7 ) ;
else
V_8 = F_51 ( V_6 , V_148 . V_7 ) ;
if ( V_6 -> V_149 == V_8 &&
! memcmp ( V_148 . V_7 , V_6 -> V_142 , V_8 ) )
return;
memcpy ( V_6 -> V_142 , V_148 . V_7 , sizeof( V_148 . V_7 ) ) ;
V_6 -> V_149 = V_8 ;
V_148 . V_150 = V_8 ;
F_54 ( V_145 , V_151 , sizeof( V_148 ) , & V_148 ) ;
}
static void F_55 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
T_1 V_146 ;
if ( F_20 ( V_6 , V_152 ) &&
! F_20 ( V_6 , V_113 ) )
V_146 = 0x01 ;
else
V_146 = 0x00 ;
F_53 ( V_145 , V_146 ) ;
}
static T_1 F_56 ( struct V_5 * V_6 )
{
struct V_133 * V_153 ;
V_153 = F_47 ( V_154 , V_6 ) ;
if ( V_153 ) {
struct V_155 * V_148 = V_153 -> V_156 ;
if ( V_148 -> V_157 == 0x01 )
return V_158 ;
else if ( V_148 -> V_157 == 0x02 )
return V_159 ;
} else {
if ( F_20 ( V_6 , V_160 ) )
return V_159 ;
else if ( F_20 ( V_6 , V_106 ) )
return V_158 ;
}
return 0 ;
}
static T_1 F_57 ( struct V_5 * V_6 )
{
if ( F_20 ( V_6 , V_152 ) &&
! F_20 ( V_6 , V_113 ) )
return 0x01 ;
return 0x00 ;
}
static bool F_58 ( struct V_5 * V_6 )
{
struct V_133 * V_153 ;
V_153 = F_47 ( V_161 , V_6 ) ;
if ( V_153 ) {
struct V_155 * V_148 = V_153 -> V_156 ;
return V_148 -> V_157 ;
}
return F_20 ( V_6 , V_104 ) ;
}
static T_6 F_59 ( struct V_5 * V_6 , T_1 V_146 )
{
T_6 V_162 ;
if ( V_146 > 0x01 )
return 0 ;
if ( V_146 == 0x01 )
return V_6 -> V_141 . V_162 ;
V_162 = V_163 | V_164 ;
if ( F_20 ( V_6 , V_165 ) )
V_162 |= V_166 ;
return V_162 ;
}
static T_1 F_60 ( struct V_5 * V_6 , T_1 V_146 )
{
if ( V_146 != 0x01 )
return 0 ;
return V_6 -> V_141 . V_143 ;
}
static T_1 F_61 ( struct V_5 * V_6 , T_1 V_146 , T_1 * V_120 )
{
T_1 V_134 = 0 , V_162 = 0 ;
T_6 V_167 = F_59 ( V_6 , V_146 ) ;
if ( V_167 & V_168 )
V_162 |= V_158 ;
if ( V_167 & V_169 )
V_162 |= V_159 ;
if ( V_162 || ( V_167 & V_164 ) ) {
if ( ! V_162 )
V_162 |= F_56 ( V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) )
V_162 |= V_170 ;
if ( V_162 ) {
V_120 [ 0 ] = 0x02 ;
V_120 [ 1 ] = V_171 ;
V_120 [ 2 ] = V_162 ;
V_134 += 3 ;
V_120 += 3 ;
}
}
if ( V_146 ) {
memcpy ( V_120 , V_6 -> V_141 . V_172 ,
V_6 -> V_141 . V_173 ) ;
V_134 += V_6 -> V_141 . V_173 ;
V_120 += V_6 -> V_141 . V_173 ;
}
if ( V_6 -> V_174 != V_175 &&
( V_167 & V_163 ) ) {
V_120 [ 0 ] = 0x02 ;
V_120 [ 1 ] = V_176 ;
V_120 [ 2 ] = ( T_1 ) V_6 -> V_174 ;
V_134 += 3 ;
V_120 += 3 ;
}
return V_134 ;
}
static void F_62 ( struct V_144 * V_145 , T_1 V_146 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_177 V_148 ;
T_1 V_8 ;
if ( ! F_20 ( V_6 , V_109 ) )
return;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_8 = F_61 ( V_6 , V_146 , V_148 . V_7 ) ;
if ( V_6 -> V_173 == V_8 &&
memcmp ( V_148 . V_7 , V_6 -> V_172 , V_8 ) == 0 )
return;
memcpy ( V_6 -> V_172 , V_148 . V_7 , sizeof( V_148 . V_7 ) ) ;
V_6 -> V_173 = V_8 ;
V_148 . V_150 = V_8 ;
F_54 ( V_145 , V_178 , sizeof( V_148 ) , & V_148 ) ;
}
static void F_63 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
T_1 V_146 = F_57 ( V_6 ) ;
F_62 ( V_145 , V_146 ) ;
}
int F_64 ( struct V_5 * V_6 )
{
struct V_144 V_145 ;
F_65 ( & V_145 , V_6 ) ;
F_63 ( & V_145 ) ;
return F_66 ( & V_145 , NULL ) ;
}
static void F_67 ( struct V_5 * V_6 , T_1 * V_7 )
{
T_1 * V_120 = V_7 ;
T_3 V_135 ;
V_135 = strlen ( V_6 -> V_136 ) ;
if ( V_135 > 0 ) {
if ( V_135 > 48 ) {
V_135 = 48 ;
V_120 [ 1 ] = V_139 ;
} else
V_120 [ 1 ] = V_140 ;
V_120 [ 0 ] = V_135 + 1 ;
memcpy ( V_120 + 2 , V_6 -> V_136 , V_135 ) ;
V_120 += ( V_135 + 2 ) ;
}
if ( V_6 -> V_179 != V_175 ) {
V_120 [ 0 ] = 2 ;
V_120 [ 1 ] = V_176 ;
V_120 [ 2 ] = ( T_1 ) V_6 -> V_179 ;
V_120 += 3 ;
}
if ( V_6 -> V_180 > 0 ) {
V_120 [ 0 ] = 9 ;
V_120 [ 1 ] = V_181 ;
F_15 ( V_6 -> V_180 , V_120 + 2 ) ;
F_15 ( V_6 -> V_182 , V_120 + 4 ) ;
F_15 ( V_6 -> V_183 , V_120 + 6 ) ;
F_15 ( V_6 -> V_184 , V_120 + 8 ) ;
V_120 += 10 ;
}
V_120 = F_43 ( V_6 , V_120 , V_185 - ( V_120 - V_7 ) ) ;
V_120 = F_45 ( V_6 , V_120 , V_185 - ( V_120 - V_7 ) ) ;
V_120 = F_46 ( V_6 , V_120 , V_185 - ( V_120 - V_7 ) ) ;
}
static void F_68 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_186 V_148 ;
if ( ! F_42 ( V_6 ) )
return;
if ( ! F_69 ( V_6 ) )
return;
if ( ! F_20 ( V_6 , V_111 ) )
return;
if ( F_20 ( V_6 , V_187 ) )
return;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_67 ( V_6 , V_148 . V_7 ) ;
if ( memcmp ( V_148 . V_7 , V_6 -> V_188 , sizeof( V_148 . V_7 ) ) == 0 )
return;
memcpy ( V_6 -> V_188 , V_148 . V_7 , sizeof( V_148 . V_7 ) ) ;
F_54 ( V_145 , V_189 , sizeof( V_148 ) , & V_148 ) ;
}
static T_1 F_70 ( struct V_5 * V_6 )
{
struct V_122 * V_123 ;
T_1 V_157 = 0 ;
F_19 (uuid, &hdev->uuids, list)
V_157 |= V_123 -> V_190 ;
return V_157 ;
}
static void F_71 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
T_1 V_191 [ 3 ] ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_42 ( V_6 ) )
return;
if ( ! F_20 ( V_6 , V_108 ) )
return;
if ( F_20 ( V_6 , V_187 ) )
return;
V_191 [ 0 ] = V_6 -> V_192 ;
V_191 [ 1 ] = V_6 -> V_193 ;
V_191 [ 2 ] = F_70 ( V_6 ) ;
if ( F_20 ( V_6 , V_160 ) )
V_191 [ 1 ] |= 0x20 ;
if ( memcmp ( V_191 , V_6 -> V_194 , 3 ) == 0 )
return;
F_54 ( V_145 , V_195 , sizeof( V_191 ) , V_191 ) ;
}
static void F_72 ( struct V_144 * V_145 )
{
T_1 V_196 = 0x00 ;
F_54 ( V_145 , V_197 , sizeof( V_196 ) , & V_196 ) ;
}
static void F_73 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_198 V_148 ;
T_1 V_199 , V_196 = 0x01 ;
bool V_200 ;
T_1 V_146 ;
T_6 V_162 ;
if ( F_74 ( V_6 , V_201 ) > 0 )
return;
if ( F_20 ( V_6 , V_202 ) )
F_72 ( V_145 ) ;
F_75 ( V_6 , V_202 ) ;
V_146 = F_57 ( V_6 ) ;
V_162 = F_59 ( V_6 , V_146 ) ;
V_200 = ( V_162 & V_166 ) ||
F_58 ( V_6 ) ;
if ( F_76 ( V_145 , ! V_200 , & V_199 ) < 0 )
return;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_203 = F_10 ( V_6 -> V_204 ) ;
V_148 . V_205 = F_10 ( V_6 -> V_206 ) ;
if ( V_200 )
V_148 . type = V_207 ;
else if ( F_60 ( V_6 , V_146 ) )
V_148 . type = V_208 ;
else
V_148 . type = V_209 ;
V_148 . V_210 = V_199 ;
V_148 . V_211 = V_6 -> V_212 ;
F_54 ( V_145 , V_213 , sizeof( V_148 ) , & V_148 ) ;
F_54 ( V_145 , V_197 , sizeof( V_196 ) , & V_196 ) ;
}
static void F_77 ( struct V_214 * V_215 )
{
struct V_5 * V_6 = F_78 ( V_215 , struct V_5 ,
V_216 . V_215 ) ;
struct V_144 V_145 ;
if ( ! F_79 ( V_6 , V_187 ) )
return;
F_65 ( & V_145 , V_6 ) ;
F_34 ( V_6 ) ;
F_68 ( & V_145 ) ;
F_71 ( & V_145 ) ;
F_35 ( V_6 ) ;
F_66 ( & V_145 , NULL ) ;
}
static void F_80 ( struct V_214 * V_215 )
{
struct V_5 * V_6 = F_78 ( V_215 , struct V_5 ,
F_80 . V_215 ) ;
struct V_144 V_145 ;
F_9 ( L_5 ) ;
F_81 ( V_6 , V_217 ) ;
if ( ! F_20 ( V_6 , V_113 ) )
return;
F_65 ( & V_145 , V_6 ) ;
F_73 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
}
static void F_82 ( struct V_11 * V_15 , struct V_5 * V_6 )
{
if ( F_83 ( V_6 , V_218 ) )
return;
F_84 ( & V_6 -> V_216 , F_77 ) ;
F_84 ( & V_6 -> F_80 , F_80 ) ;
F_75 ( V_6 , V_107 ) ;
}
static int F_85 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_219 V_18 ;
F_9 ( L_3 , V_15 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_86 ( & V_18 . V_118 , & V_6 -> V_118 ) ;
V_18 . V_19 = V_6 -> V_91 ;
V_18 . V_80 = F_10 ( V_6 -> V_80 ) ;
V_18 . V_220 = F_30 ( F_36 ( V_6 ) ) ;
V_18 . V_221 = F_30 ( F_41 ( V_6 ) ) ;
memcpy ( V_18 . V_194 , V_6 -> V_194 , 3 ) ;
memcpy ( V_18 . V_79 , V_6 -> V_136 , sizeof( V_6 -> V_136 ) ) ;
memcpy ( V_18 . V_222 , V_6 -> V_222 , sizeof( V_6 -> V_222 ) ) ;
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_223 , 0 , & V_18 ,
sizeof( V_18 ) ) ;
}
static int F_87 ( struct V_11 * V_15 , T_2 V_37 , struct V_5 * V_6 )
{
T_5 V_85 = F_30 ( F_41 ( V_6 ) ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_37 , 0 , & V_85 ,
sizeof( V_85 ) ) ;
}
static void F_88 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
F_9 ( L_6 , V_6 -> V_79 , V_224 ) ;
if ( F_89 ( V_6 ) == 0 ) {
F_90 ( & V_6 -> V_225 ) ;
F_91 ( V_6 -> V_226 , & V_6 -> V_225 . V_215 ) ;
}
}
static bool F_92 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_227 V_148 ;
struct V_228 * V_229 ;
switch ( V_6 -> V_230 . V_231 ) {
case V_232 :
if ( F_22 ( V_233 , & V_6 -> V_162 ) )
F_54 ( V_145 , V_234 , 0 , NULL ) ;
if ( F_20 ( V_6 , V_235 ) ) {
F_90 ( & V_6 -> V_236 ) ;
F_93 ( V_145 ) ;
}
return true ;
case V_237 :
V_229 = F_94 ( V_6 , V_72 ,
V_238 ) ;
if ( ! V_229 )
break;
F_86 ( & V_148 . V_118 , & V_229 -> V_7 . V_118 ) ;
F_54 ( V_145 , V_239 , sizeof( V_148 ) ,
& V_148 ) ;
return true ;
default:
if ( F_20 ( V_6 , V_235 ) ) {
F_93 ( V_145 ) ;
return true ;
}
break;
}
return false ;
}
static void F_95 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_1 V_146 )
{
struct V_240 V_241 ;
V_241 . V_146 = V_146 ;
F_7 ( V_242 , V_6 , & V_241 , sizeof( V_241 ) , V_15 ) ;
}
static void F_96 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_1 V_146 )
{
struct V_243 V_241 ;
V_241 . V_146 = V_146 ;
F_7 ( V_244 , V_6 , & V_241 , sizeof( V_241 ) , V_15 ) ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_144 V_145 ;
if ( ! F_20 ( V_6 , V_152 ) )
return;
if ( V_6 -> V_141 . V_245 )
F_90 ( & V_6 -> V_141 . V_246 ) ;
memset ( & V_6 -> V_141 , 0 , sizeof( V_6 -> V_141 ) ) ;
F_96 ( NULL , V_6 , 1 ) ;
F_75 ( V_6 , V_152 ) ;
if ( ! F_42 ( V_6 ) ||
F_20 ( V_6 , V_113 ) )
return;
F_65 ( & V_145 , V_6 ) ;
F_72 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
}
static int F_98 ( struct V_5 * V_6 )
{
struct V_144 V_145 ;
struct V_247 * V_248 ;
bool V_249 ;
int V_30 ;
F_65 ( & V_145 , V_6 ) ;
if ( F_22 ( V_250 , & V_6 -> V_162 ) ||
F_22 ( V_251 , & V_6 -> V_162 ) ) {
T_1 V_252 = 0x00 ;
F_54 ( & V_145 , V_253 , 1 , & V_252 ) ;
}
if ( V_6 -> V_141 . V_245 )
F_97 ( V_6 ) ;
if ( F_20 ( V_6 , V_202 ) )
F_72 ( & V_145 ) ;
V_249 = F_92 ( & V_145 ) ;
F_19 (conn, &hdev->conn_hash.list, list) {
struct V_254 V_255 ;
struct V_256 V_257 ;
switch ( V_248 -> V_231 ) {
case V_258 :
case V_259 :
V_255 . V_260 = F_10 ( V_248 -> V_260 ) ;
V_255 . V_261 = 0x15 ;
F_54 ( & V_145 , V_262 , sizeof( V_255 ) , & V_255 ) ;
break;
case V_263 :
if ( V_248 -> type == V_201 )
F_54 ( & V_145 , V_264 ,
0 , NULL ) ;
else if ( V_248 -> type == V_265 )
F_54 ( & V_145 , V_266 ,
6 , & V_248 -> V_267 ) ;
break;
case V_268 :
F_86 ( & V_257 . V_118 , & V_248 -> V_267 ) ;
V_257 . V_261 = 0x15 ;
if ( V_248 -> type == V_265 )
F_54 ( & V_145 , V_269 ,
sizeof( V_257 ) , & V_257 ) ;
else if ( V_248 -> type == V_270 )
F_54 ( & V_145 , V_271 ,
sizeof( V_257 ) , & V_257 ) ;
break;
}
}
V_30 = F_66 ( & V_145 , F_88 ) ;
if ( ! V_30 && V_249 )
F_99 ( V_6 , V_272 ) ;
return V_30 ;
}
static int F_100 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_273 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_273 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_273 ,
V_275 ) ;
goto V_276;
}
if ( F_79 ( V_6 , V_277 ) ) {
F_90 ( & V_6 -> V_225 ) ;
if ( V_148 -> V_157 ) {
F_102 ( V_15 , V_273 , V_6 ,
V_7 , V_8 ) ;
V_30 = F_103 ( V_6 , 1 ) ;
goto V_276;
}
}
if ( ! ! V_148 -> V_157 == F_42 ( V_6 ) ) {
V_30 = F_87 ( V_15 , V_273 , V_6 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_273 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
if ( V_148 -> V_157 ) {
F_91 ( V_6 -> V_226 , & V_6 -> V_278 ) ;
V_30 = 0 ;
} else {
V_30 = F_98 ( V_6 ) ;
if ( ! V_30 )
F_104 ( V_6 -> V_226 , & V_6 -> V_225 ,
V_279 ) ;
if ( V_30 == - V_280 ) {
F_90 ( & V_6 -> V_225 ) ;
F_91 ( V_6 -> V_226 , & V_6 -> V_225 . V_215 ) ;
V_30 = 0 ;
}
}
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_105 ( struct V_5 * V_6 , struct V_11 * V_76 )
{
T_5 V_241 = F_30 ( F_41 ( V_6 ) ) ;
return F_6 ( V_281 , V_6 , & V_241 ,
sizeof( V_241 ) , V_76 ) ;
}
int F_106 ( struct V_5 * V_6 )
{
return F_105 ( V_6 , NULL ) ;
}
static void F_107 ( struct V_133 * V_153 , void * V_7 )
{
struct V_282 * V_283 = V_7 ;
F_87 ( V_153 -> V_15 , V_153 -> V_37 , V_283 -> V_6 ) ;
F_108 ( & V_153 -> V_284 ) ;
if ( V_283 -> V_15 == NULL ) {
V_283 -> V_15 = V_153 -> V_15 ;
F_109 ( V_283 -> V_15 ) ;
}
F_110 ( V_153 ) ;
}
static void F_111 ( struct V_133 * V_153 , void * V_7 )
{
T_1 * V_224 = V_7 ;
F_101 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , * V_224 ) ;
F_112 ( V_153 ) ;
}
static void F_113 ( struct V_133 * V_153 , void * V_7 )
{
if ( V_153 -> V_285 ) {
T_1 * V_224 = V_7 ;
V_153 -> V_285 ( V_153 , * V_224 ) ;
F_112 ( V_153 ) ;
return;
}
F_111 ( V_153 , V_7 ) ;
}
static int F_114 ( struct V_133 * V_153 , T_1 V_224 )
{
return F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_224 ,
V_153 -> V_156 , V_153 -> V_286 ) ;
}
static int F_115 ( struct V_133 * V_153 , T_1 V_224 )
{
return F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_224 ,
V_153 -> V_156 , sizeof( struct V_287 ) ) ;
}
static T_1 F_116 ( struct V_5 * V_6 )
{
if ( ! F_37 ( V_6 ) )
return V_288 ;
else if ( ! F_20 ( V_6 , V_108 ) )
return V_289 ;
else
return V_290 ;
}
static T_1 F_117 ( struct V_5 * V_6 )
{
if ( ! F_40 ( V_6 ) )
return V_288 ;
else if ( ! F_20 ( V_6 , V_109 ) )
return V_289 ;
else
return V_290 ;
}
static void F_118 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_133 * V_153 ;
struct V_155 * V_148 ;
struct V_144 V_145 ;
bool V_291 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_154 , V_6 ) ;
if ( ! V_153 )
goto V_292;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
F_101 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_293 ) ;
F_75 ( V_6 , V_160 ) ;
goto V_294;
}
V_148 = V_153 -> V_156 ;
if ( V_148 -> V_157 ) {
V_291 = ! F_83 ( V_6 , V_106 ) ;
if ( V_6 -> V_295 > 0 ) {
int V_296 = F_119 ( V_6 -> V_295 * 1000 ) ;
F_104 ( V_6 -> V_297 , & V_6 -> V_298 ,
V_296 ) ;
}
} else {
V_291 = F_79 ( V_6 , V_106 ) ;
}
F_87 ( V_153 -> V_15 , V_154 , V_6 ) ;
if ( V_291 )
F_105 ( V_6 , V_153 -> V_15 ) ;
F_65 ( & V_145 , V_6 ) ;
F_120 ( & V_145 ) ;
F_71 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
V_294:
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_121 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_299 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
T_2 V_245 ;
T_1 V_252 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_20 ( V_6 , V_109 ) &&
! F_20 ( V_6 , V_108 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_154 ,
V_289 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 && V_148 -> V_157 != 0x02 )
return F_101 ( V_15 , V_6 -> V_55 , V_154 ,
V_274 ) ;
V_245 = F_122 ( V_148 -> V_245 ) ;
if ( ( V_148 -> V_157 == 0x00 && V_245 > 0 ) ||
( V_148 -> V_157 == 0x02 && V_245 == 0 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_154 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) && V_245 > 0 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_154 ,
V_300 ) ;
goto V_276;
}
if ( F_47 ( V_154 , V_6 ) ||
F_47 ( V_161 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_154 ,
V_275 ) ;
goto V_276;
}
if ( ! F_20 ( V_6 , V_104 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_154 ,
V_289 ) ;
goto V_276;
}
if ( ! F_42 ( V_6 ) ) {
bool V_291 = false ;
if ( ! ! V_148 -> V_157 != F_20 ( V_6 , V_106 ) ) {
F_123 ( V_6 , V_106 ) ;
V_291 = true ;
}
V_30 = F_87 ( V_15 , V_154 , V_6 ) ;
if ( V_30 < 0 )
goto V_276;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_276;
}
if ( ! ! V_148 -> V_157 == F_20 ( V_6 , V_106 ) &&
( V_148 -> V_157 == 0x02 ) == F_20 ( V_6 ,
V_160 ) ) {
F_90 ( & V_6 -> V_298 ) ;
V_6 -> V_295 = V_245 ;
if ( V_148 -> V_157 && V_6 -> V_295 > 0 ) {
int V_296 = F_119 ( V_6 -> V_295 * 1000 ) ;
F_104 ( V_6 -> V_297 , & V_6 -> V_298 ,
V_296 ) ;
}
V_30 = F_87 ( V_15 , V_154 , V_6 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_154 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
F_90 ( & V_6 -> V_298 ) ;
V_6 -> V_295 = V_245 ;
if ( V_148 -> V_157 == 0x02 )
F_81 ( V_6 , V_160 ) ;
else
F_75 ( V_6 , V_160 ) ;
F_65 ( & V_145 , V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) )
goto V_301;
V_252 = V_302 ;
if ( V_148 -> V_157 ) {
struct V_303 V_304 ;
if ( V_148 -> V_157 == 0x02 ) {
V_304 . V_305 = F_124 ( T_1 , V_6 -> V_305 , 2 ) ;
V_304 . V_306 [ 0 ] = 0x00 ;
V_304 . V_306 [ 1 ] = 0x8b ;
V_304 . V_306 [ 2 ] = 0x9e ;
V_304 . V_306 [ 3 ] = 0x33 ;
V_304 . V_306 [ 4 ] = 0x8b ;
V_304 . V_306 [ 5 ] = 0x9e ;
} else {
V_304 . V_305 = 1 ;
V_304 . V_306 [ 0 ] = 0x33 ;
V_304 . V_306 [ 1 ] = 0x8b ;
V_304 . V_306 [ 2 ] = 0x9e ;
}
F_54 ( & V_145 , V_307 ,
( V_304 . V_305 * 3 ) + 1 , & V_304 ) ;
V_252 |= V_308 ;
} else {
F_75 ( V_6 , V_160 ) ;
}
F_54 ( & V_145 , V_253 , sizeof( V_252 ) , & V_252 ) ;
V_301:
F_63 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_118 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_125 ( struct V_144 * V_145 , bool V_196 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_309 V_310 ;
T_1 type ;
if ( ! F_20 ( V_6 , V_108 ) )
return;
if ( V_6 -> V_91 < V_92 )
return;
if ( V_196 ) {
type = V_311 ;
V_310 . V_312 = F_10 ( 0x0100 ) ;
} else {
type = V_313 ;
V_310 . V_312 = F_10 ( 0x0800 ) ;
}
V_310 . V_314 = F_10 ( 0x0012 ) ;
if ( F_126 ( V_6 -> V_315 ) != V_310 . V_312 ||
F_126 ( V_6 -> V_316 ) != V_310 . V_314 )
F_54 ( V_145 , V_317 ,
sizeof( V_310 ) , & V_310 ) ;
if ( V_6 -> V_318 != type )
F_54 ( V_145 , V_319 , 1 , & type ) ;
}
static void F_127 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_133 * V_153 ;
struct V_155 * V_148 ;
bool V_320 , V_321 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_161 , V_6 ) ;
if ( ! V_153 )
goto V_292;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
F_101 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_293 ) ;
goto V_294;
}
V_148 = V_153 -> V_156 ;
if ( V_148 -> V_157 ) {
V_320 = ! F_83 ( V_6 ,
V_104 ) ;
V_321 = false ;
} else {
V_320 = F_79 ( V_6 ,
V_104 ) ;
V_321 = F_79 ( V_6 ,
V_106 ) ;
}
F_87 ( V_153 -> V_15 , V_161 , V_6 ) ;
if ( V_320 || V_321 ) {
F_105 ( V_6 , V_153 -> V_15 ) ;
F_128 ( V_6 ) ;
if ( V_321 )
F_64 ( V_6 ) ;
F_129 ( V_6 ) ;
}
V_294:
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_130 ( struct V_5 * V_6 ,
struct V_11 * V_15 , T_1 V_157 )
{
bool V_291 = false ;
int V_30 ;
if ( ! ! V_157 != F_20 ( V_6 , V_104 ) )
V_291 = true ;
if ( V_157 ) {
F_81 ( V_6 , V_104 ) ;
} else {
F_75 ( V_6 , V_104 ) ;
F_75 ( V_6 , V_106 ) ;
}
V_30 = F_87 ( V_15 , V_161 , V_6 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_291 ) {
F_128 ( V_6 ) ;
F_129 ( V_6 ) ;
return F_105 ( V_6 , V_15 ) ;
}
return 0 ;
}
static int F_131 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
T_1 V_252 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_20 ( V_6 , V_109 ) &&
! F_20 ( V_6 , V_108 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_161 ,
V_289 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_161 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_130 ( V_6 , V_15 , V_148 -> V_157 ) ;
goto V_276;
}
if ( F_47 ( V_154 , V_6 ) ||
F_47 ( V_161 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_161 ,
V_275 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_161 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
F_65 ( & V_145 , V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) ) {
if ( ! V_148 -> V_157 ) {
F_75 ( V_6 , V_160 ) ;
F_75 ( V_6 , V_106 ) ;
}
F_63 ( & V_145 ) ;
} else if ( V_148 -> V_157 != F_22 ( V_251 , & V_6 -> V_162 ) ) {
if ( V_148 -> V_157 ) {
V_252 = V_302 ;
} else {
if ( F_132 ( & V_6 -> V_322 ) )
V_252 = V_323 ;
else if ( F_22 ( V_250 , & V_6 -> V_162 ) )
V_252 = V_302 ;
else
goto V_324;
if ( F_22 ( V_250 , & V_6 -> V_162 ) &&
V_6 -> V_295 > 0 )
F_90 ( & V_6 -> V_298 ) ;
}
F_54 ( & V_145 , V_253 , 1 , & V_252 ) ;
}
V_324:
if ( F_20 ( V_6 , V_113 ) ||
F_20 ( V_6 , V_152 ) )
F_73 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_127 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
if ( V_30 == - V_280 )
V_30 = F_130 ( V_6 , V_15 ,
V_148 -> V_157 ) ;
goto V_276;
}
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_133 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
bool V_291 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_325 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( V_148 -> V_157 )
V_291 = ! F_83 ( V_6 , V_107 ) ;
else
V_291 = F_79 ( V_6 , V_107 ) ;
V_30 = F_87 ( V_15 , V_325 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_134 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
T_1 V_157 , V_224 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_224 = F_116 ( V_6 ) ;
if ( V_224 )
return F_101 ( V_15 , V_6 -> V_55 , V_326 ,
V_224 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_326 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
bool V_291 = false ;
if ( ! ! V_148 -> V_157 != F_20 ( V_6 , V_110 ) ) {
F_123 ( V_6 , V_110 ) ;
V_291 = true ;
}
V_30 = F_87 ( V_15 , V_326 , V_6 ) ;
if ( V_30 < 0 )
goto V_276;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_276;
}
if ( F_47 ( V_326 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_326 ,
V_275 ) ;
goto V_276;
}
V_157 = ! ! V_148 -> V_157 ;
if ( F_22 ( V_327 , & V_6 -> V_162 ) == V_157 ) {
V_30 = F_87 ( V_15 , V_326 , V_6 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_326 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
V_30 = F_135 ( V_6 , V_328 , sizeof( V_157 ) , & V_157 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
goto V_276;
}
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_136 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_224 = F_116 ( V_6 ) ;
if ( V_224 )
return F_101 ( V_15 , V_6 -> V_55 , V_329 , V_224 ) ;
if ( ! F_38 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_329 ,
V_288 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_329 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
bool V_291 ;
if ( V_148 -> V_157 ) {
V_291 = ! F_83 ( V_6 ,
V_111 ) ;
} else {
V_291 = F_79 ( V_6 ,
V_111 ) ;
if ( ! V_291 )
V_291 = F_79 ( V_6 ,
V_112 ) ;
else
F_75 ( V_6 , V_112 ) ;
}
V_30 = F_87 ( V_15 , V_329 , V_6 ) ;
if ( V_30 < 0 )
goto V_276;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_276;
}
if ( F_47 ( V_329 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_329 ,
V_275 ) ;
goto V_276;
}
if ( ! ! V_148 -> V_157 == F_20 ( V_6 , V_111 ) ) {
V_30 = F_87 ( V_15 , V_329 , V_6 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_329 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
if ( ! V_148 -> V_157 && F_20 ( V_6 , V_330 ) )
F_135 ( V_6 , V_331 ,
sizeof( V_148 -> V_157 ) , & V_148 -> V_157 ) ;
V_30 = F_135 ( V_6 , V_332 , 1 , & V_148 -> V_157 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
goto V_276;
}
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_137 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
bool V_291 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_224 = F_116 ( V_6 ) ;
if ( V_224 )
return F_101 ( V_15 , V_6 -> V_55 , V_333 , V_224 ) ;
if ( ! F_38 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_333 ,
V_288 ) ;
if ( ! F_20 ( V_6 , V_111 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_333 ,
V_289 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_333 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_329 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_333 ,
V_275 ) ;
goto V_292;
}
if ( V_148 -> V_157 ) {
V_291 = ! F_83 ( V_6 , V_112 ) ;
} else {
if ( F_42 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_333 ,
V_289 ) ;
goto V_292;
}
V_291 = F_79 ( V_6 , V_112 ) ;
}
V_30 = F_87 ( V_15 , V_333 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_138 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_282 V_283 = { NULL , V_6 } ;
F_34 ( V_6 ) ;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
F_139 ( V_334 , V_6 , F_111 ,
& V_293 ) ;
goto V_292;
}
F_139 ( V_334 , V_6 , F_107 , & V_283 ) ;
F_105 ( V_6 , V_283 . V_15 ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
if ( F_20 ( V_6 , V_109 ) ) {
struct V_144 V_145 ;
F_65 ( & V_145 , V_6 ) ;
F_63 ( & V_145 ) ;
F_55 ( & V_145 ) ;
F_141 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
}
V_292:
F_35 ( V_6 ) ;
}
static int F_142 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_335 V_304 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
T_1 V_157 , V_336 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_334 ,
V_288 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_334 ,
V_274 ) ;
if ( ! F_20 ( V_6 , V_108 ) ) {
if ( V_148 -> V_157 == 0x01 )
return F_87 ( V_15 , V_334 , V_6 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_334 ,
V_289 ) ;
}
F_34 ( V_6 ) ;
V_157 = ! ! V_148 -> V_157 ;
V_336 = F_143 ( V_6 ) ;
if ( ! F_42 ( V_6 ) || V_157 == V_336 ) {
bool V_291 = false ;
if ( V_157 != F_20 ( V_6 , V_109 ) ) {
F_123 ( V_6 , V_109 ) ;
V_291 = true ;
}
if ( ! V_157 && F_20 ( V_6 , V_113 ) ) {
F_75 ( V_6 , V_113 ) ;
V_291 = true ;
}
V_30 = F_87 ( V_15 , V_334 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_292;
}
if ( F_47 ( V_334 , V_6 ) ||
F_47 ( V_337 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_334 ,
V_275 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_334 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
memset ( & V_304 , 0 , sizeof( V_304 ) ) ;
if ( V_157 ) {
V_304 . V_338 = V_157 ;
V_304 . V_339 = 0x00 ;
} else {
if ( F_20 ( V_6 , V_202 ) )
F_72 ( & V_145 ) ;
}
F_54 ( & V_145 , V_340 , sizeof( V_304 ) ,
& V_304 ) ;
V_30 = F_66 ( & V_145 , F_138 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_144 ( struct V_5 * V_6 )
{
struct V_133 * V_153 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
switch ( V_153 -> V_37 ) {
case V_341 :
case V_342 :
case V_343 :
case V_273 :
return true ;
}
}
return false ;
}
static T_1 F_145 ( const T_1 * V_123 )
{
T_6 V_157 ;
if ( memcmp ( V_123 , V_344 , 12 ) )
return 128 ;
V_157 = F_146 ( & V_123 [ 12 ] ) ;
if ( V_157 > 0xffff )
return 32 ;
return 16 ;
}
static void F_147 ( struct V_5 * V_6 , T_2 V_345 , T_1 V_224 )
{
struct V_133 * V_153 ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_345 , V_6 ) ;
if ( ! V_153 )
goto V_292;
F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 ,
F_1 ( V_224 ) , V_6 -> V_194 , 3 ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static void F_148 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
F_9 ( L_8 , V_224 ) ;
F_147 ( V_6 , V_341 , V_224 ) ;
}
static int F_149 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_346 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
struct V_122 * V_123 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( F_144 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_341 ,
V_275 ) ;
goto V_276;
}
V_123 = F_14 ( sizeof( * V_123 ) , V_35 ) ;
if ( ! V_123 ) {
V_30 = - V_36 ;
goto V_276;
}
memcpy ( V_123 -> V_123 , V_148 -> V_123 , 16 ) ;
V_123 -> V_190 = V_148 -> V_190 ;
V_123 -> V_125 = F_145 ( V_148 -> V_123 ) ;
F_150 ( & V_123 -> V_284 , & V_6 -> V_347 ) ;
F_65 ( & V_145 , V_6 ) ;
F_71 ( & V_145 ) ;
F_68 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_148 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_280 )
goto V_276;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_341 , 0 ,
V_6 -> V_194 , 3 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_341 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
V_30 = 0 ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_151 ( struct V_5 * V_6 )
{
if ( ! F_42 ( V_6 ) )
return false ;
if ( ! F_83 ( V_6 , V_187 ) ) {
F_104 ( V_6 -> V_297 , & V_6 -> V_216 ,
V_348 ) ;
return true ;
}
return false ;
}
static void F_152 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
F_9 ( L_8 , V_224 ) ;
F_147 ( V_6 , V_342 , V_224 ) ;
}
static int F_153 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_349 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_122 * V_283 , * V_350 ;
T_1 V_351 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_144 V_145 ;
int V_30 , V_352 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( F_144 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_342 ,
V_275 ) ;
goto V_292;
}
if ( memcmp ( V_148 -> V_123 , V_351 , 16 ) == 0 ) {
F_154 ( V_6 ) ;
if ( F_151 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_342 ,
0 , V_6 -> V_194 , 3 ) ;
goto V_292;
}
goto F_71;
}
V_352 = 0 ;
F_155 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_283 -> V_123 , V_148 -> V_123 , 16 ) != 0 )
continue;
F_108 ( & V_283 -> V_284 ) ;
F_16 ( V_283 ) ;
V_352 ++ ;
}
if ( V_352 == 0 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_342 ,
V_274 ) ;
goto V_292;
}
F_71:
F_65 ( & V_145 , V_6 ) ;
F_71 ( & V_145 ) ;
F_68 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_152 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_280 )
goto V_292;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_342 , 0 ,
V_6 -> V_194 , 3 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_342 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_30 = 0 ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_156 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
F_9 ( L_8 , V_224 ) ;
F_147 ( V_6 , V_343 , V_224 ) ;
}
static int F_157 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_353 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_37 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_343 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( F_144 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_343 ,
V_275 ) ;
goto V_292;
}
if ( ( V_148 -> V_354 & 0x03 ) != 0 || ( V_148 -> V_355 & 0xe0 ) != 0 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_343 ,
V_274 ) ;
goto V_292;
}
V_6 -> V_193 = V_148 -> V_355 ;
V_6 -> V_192 = V_148 -> V_354 ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_343 , 0 ,
V_6 -> V_194 , 3 ) ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
if ( F_79 ( V_6 , V_187 ) ) {
F_35 ( V_6 ) ;
F_158 ( & V_6 -> V_216 ) ;
F_34 ( V_6 ) ;
F_68 ( & V_145 ) ;
}
F_71 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_156 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_280 )
goto V_292;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_343 , 0 ,
V_6 -> V_194 , 3 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_343 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_30 = 0 ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_159 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_356 * V_148 = V_7 ;
const T_2 V_357 = ( ( V_358 - sizeof( * V_148 ) ) /
sizeof( struct V_359 ) ) ;
T_2 V_360 , V_361 ;
bool V_291 ;
int V_29 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_37 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_362 ,
V_288 ) ;
V_360 = F_122 ( V_148 -> V_360 ) ;
if ( V_360 > V_357 ) {
F_160 ( L_9 ,
V_360 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_362 ,
V_274 ) ;
}
V_361 = sizeof( * V_148 ) + V_360 *
sizeof( struct V_359 ) ;
if ( V_361 != V_8 ) {
F_160 ( L_10 ,
V_361 , V_8 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_362 ,
V_274 ) ;
}
if ( V_148 -> V_363 != 0x00 && V_148 -> V_363 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_362 ,
V_274 ) ;
F_9 ( L_11 , V_6 -> V_79 , V_148 -> V_363 ,
V_360 ) ;
for ( V_29 = 0 ; V_29 < V_360 ; V_29 ++ ) {
struct V_359 * V_364 = & V_148 -> V_365 [ V_29 ] ;
if ( V_364 -> V_366 . type != V_367 || V_364 -> type > 0x08 )
return F_101 ( V_15 , V_6 -> V_55 ,
V_362 ,
V_274 ) ;
}
F_34 ( V_6 ) ;
F_161 ( V_6 ) ;
if ( V_148 -> V_363 )
V_291 = ! F_83 ( V_6 , V_115 ) ;
else
V_291 = F_79 ( V_6 ,
V_115 ) ;
if ( V_291 )
F_105 ( V_6 , NULL ) ;
for ( V_29 = 0 ; V_29 < V_360 ; V_29 ++ ) {
struct V_359 * V_364 = & V_148 -> V_365 [ V_29 ] ;
if ( V_364 -> type == V_368 )
continue;
F_162 ( V_6 , NULL , & V_364 -> V_366 . V_118 , V_364 -> V_157 ,
V_364 -> type , V_364 -> V_369 , NULL ) ;
}
F_11 ( V_15 , V_6 -> V_55 , V_362 , 0 , NULL , 0 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
static int F_163 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_370 , struct V_11 * V_12 )
{
struct V_371 V_241 ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = V_370 ;
return F_7 ( V_372 , V_6 , & V_241 , sizeof( V_241 ) ,
V_12 ) ;
}
static int F_164 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_373 * V_148 = V_7 ;
struct V_374 V_18 ;
struct V_254 V_255 ;
struct V_133 * V_153 ;
struct V_247 * V_248 ;
int V_30 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_86 ( & V_18 . V_366 . V_118 , & V_148 -> V_366 . V_118 ) ;
V_18 . V_366 . type = V_148 -> V_366 . type ;
if ( ! F_165 ( V_148 -> V_366 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_375 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_148 -> V_376 != 0x00 && V_148 -> V_376 != 0x01 )
return F_11 ( V_15 , V_6 -> V_55 , V_375 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_375 ,
V_300 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
if ( V_148 -> V_366 . type == V_367 ) {
if ( V_148 -> V_376 )
V_248 = F_166 ( V_6 , V_265 ,
& V_148 -> V_366 . V_118 ) ;
else
V_248 = NULL ;
V_30 = F_167 ( V_6 , & V_148 -> V_366 . V_118 ) ;
} else {
T_1 V_370 ;
V_248 = F_166 ( V_6 , V_201 ,
& V_148 -> V_366 . V_118 ) ;
if ( V_248 ) {
F_168 ( V_377 , & V_248 -> V_162 ) ;
if ( ! V_148 -> V_376 )
V_248 = NULL ;
}
if ( V_148 -> V_366 . type == V_378 )
V_370 = V_379 ;
else
V_370 = V_380 ;
F_169 ( V_6 , & V_148 -> V_366 . V_118 , V_370 ) ;
V_30 = F_170 ( V_6 , & V_148 -> V_366 . V_118 , V_370 ) ;
}
if ( V_30 < 0 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_375 ,
V_381 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
if ( ! V_248 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_375 , 0 ,
& V_18 , sizeof( V_18 ) ) ;
F_163 ( V_6 , & V_148 -> V_366 . V_118 , V_148 -> V_366 . type , V_15 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_375 , V_6 , V_148 ,
sizeof( * V_148 ) ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_153 -> V_285 = F_115 ;
V_255 . V_260 = F_10 ( V_248 -> V_260 ) ;
V_255 . V_261 = 0x13 ;
V_30 = F_135 ( V_6 , V_262 , sizeof( V_255 ) , & V_255 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int V_376 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_382 * V_148 = V_7 ;
struct V_383 V_18 ;
struct V_133 * V_153 ;
struct V_247 * V_248 ;
int V_30 ;
F_9 ( L_5 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_86 ( & V_18 . V_366 . V_118 , & V_148 -> V_366 . V_118 ) ;
V_18 . V_366 . type = V_148 -> V_366 . type ;
if ( ! F_165 ( V_148 -> V_366 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_384 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_22 ( V_385 , & V_6 -> V_162 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_384 ,
V_300 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_276;
}
if ( F_47 ( V_384 , V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_384 ,
V_275 , & V_18 , sizeof( V_18 ) ) ;
goto V_276;
}
if ( V_148 -> V_366 . type == V_367 )
V_248 = F_166 ( V_6 , V_265 ,
& V_148 -> V_366 . V_118 ) ;
else
V_248 = F_166 ( V_6 , V_201 , & V_148 -> V_366 . V_118 ) ;
if ( ! V_248 || V_248 -> V_231 == V_386 || V_248 -> V_231 == V_387 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_384 ,
V_388 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_384 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
V_153 -> V_285 = F_114 ;
V_30 = F_171 ( V_248 , V_389 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static T_1 F_172 ( T_1 V_390 , T_1 V_370 )
{
switch ( V_390 ) {
case V_201 :
switch ( V_370 ) {
case V_379 :
return V_378 ;
default:
return V_391 ;
}
default:
return V_367 ;
}
}
static int F_173 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_16 )
{
struct V_392 * V_18 ;
struct V_247 * V_393 ;
T_3 V_42 ;
int V_30 ;
T_2 V_29 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_394 ,
V_300 ) ;
goto V_292;
}
V_29 = 0 ;
F_19 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_395 , & V_393 -> V_162 ) )
V_29 ++ ;
}
V_42 = sizeof( * V_18 ) + ( V_29 * sizeof( struct V_287 ) ) ;
V_18 = F_14 ( V_42 , V_35 ) ;
if ( ! V_18 ) {
V_30 = - V_36 ;
goto V_292;
}
V_29 = 0 ;
F_19 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_395 , & V_393 -> V_162 ) )
continue;
F_86 ( & V_18 -> V_366 [ V_29 ] . V_118 , & V_393 -> V_267 ) ;
V_18 -> V_366 [ V_29 ] . type = F_172 ( V_393 -> type , V_393 -> V_396 ) ;
if ( V_393 -> type == V_270 || V_393 -> type == V_397 )
continue;
V_29 ++ ;
}
V_18 -> V_398 = F_10 ( V_29 ) ;
V_42 = sizeof( * V_18 ) + ( V_29 * sizeof( struct V_287 ) ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_394 , 0 , V_18 ,
V_42 ) ;
F_16 ( V_18 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_174 ( struct V_11 * V_15 , struct V_5 * V_6 ,
struct V_399 * V_148 )
{
struct V_133 * V_153 ;
int V_30 ;
V_153 = F_102 ( V_15 , V_400 , V_6 , V_148 ,
sizeof( * V_148 ) ) ;
if ( ! V_153 )
return - V_36 ;
V_30 = F_135 ( V_6 , V_401 ,
sizeof( V_148 -> V_366 . V_118 ) , & V_148 -> V_366 . V_118 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
return V_30 ;
}
static int F_175 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_247 * V_248 ;
struct V_402 * V_148 = V_7 ;
struct V_403 V_404 ;
struct V_133 * V_153 ;
int V_30 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_405 ,
V_300 ) ;
goto V_276;
}
V_248 = F_166 ( V_6 , V_265 , & V_148 -> V_366 . V_118 ) ;
if ( ! V_248 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_405 ,
V_388 ) ;
goto V_276;
}
if ( V_248 -> V_406 == V_407 && V_148 -> V_369 != 16 ) {
struct V_399 V_408 ;
memcpy ( & V_408 . V_366 , & V_148 -> V_366 , sizeof( V_408 . V_366 ) ) ;
F_160 ( L_12 ) ;
V_30 = F_174 ( V_15 , V_6 , & V_408 ) ;
if ( V_30 >= 0 )
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_405 ,
V_274 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_405 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
V_153 -> V_285 = F_115 ;
F_86 ( & V_404 . V_118 , & V_148 -> V_366 . V_118 ) ;
V_404 . V_369 = V_148 -> V_369 ;
memcpy ( V_404 . V_409 , V_148 -> V_409 , sizeof( V_404 . V_409 ) ) ;
V_30 = F_135 ( V_6 , V_410 , sizeof( V_404 ) , & V_404 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_176 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_411 * V_148 = V_7 ;
F_9 ( L_5 ) ;
if ( V_148 -> V_412 > V_413 )
return F_11 ( V_15 , V_6 -> V_55 , V_414 ,
V_274 , NULL , 0 ) ;
F_34 ( V_6 ) ;
V_6 -> V_412 = V_148 -> V_412 ;
F_9 ( L_13 , V_6 -> V_79 ,
V_6 -> V_412 ) ;
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_414 , 0 ,
NULL , 0 ) ;
}
static struct V_133 * F_177 ( struct V_247 * V_248 )
{
struct V_5 * V_6 = V_248 -> V_6 ;
struct V_133 * V_153 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
if ( V_153 -> V_37 != V_415 )
continue;
if ( V_153 -> V_416 != V_248 )
continue;
return V_153 ;
}
return NULL ;
}
static int F_178 ( struct V_133 * V_153 , T_1 V_224 )
{
struct V_417 V_18 ;
struct V_247 * V_248 = V_153 -> V_416 ;
int V_30 ;
F_86 ( & V_18 . V_366 . V_118 , & V_248 -> V_267 ) ;
V_18 . V_366 . type = F_172 ( V_248 -> type , V_248 -> V_396 ) ;
V_30 = F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_415 ,
V_224 , & V_18 , sizeof( V_18 ) ) ;
V_248 -> V_418 = NULL ;
V_248 -> V_419 = NULL ;
V_248 -> V_420 = NULL ;
F_179 ( V_248 ) ;
F_180 ( V_377 , & V_248 -> V_162 ) ;
F_181 ( V_248 ) ;
return V_30 ;
}
void F_182 ( struct V_247 * V_248 , bool V_421 )
{
T_1 V_224 = V_421 ? V_290 : V_3 ;
struct V_133 * V_153 ;
V_153 = F_177 ( V_248 ) ;
if ( V_153 ) {
V_153 -> V_285 ( V_153 , V_224 ) ;
F_112 ( V_153 ) ;
}
}
static void F_183 ( struct V_247 * V_248 , T_1 V_224 )
{
struct V_133 * V_153 ;
F_9 ( L_14 , V_224 ) ;
V_153 = F_177 ( V_248 ) ;
if ( ! V_153 ) {
F_9 ( L_15 ) ;
return;
}
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
static void F_184 ( struct V_247 * V_248 , T_1 V_224 )
{
struct V_133 * V_153 ;
F_9 ( L_14 , V_224 ) ;
if ( ! V_224 )
return;
V_153 = F_177 ( V_248 ) ;
if ( ! V_153 ) {
F_9 ( L_15 ) ;
return;
}
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
static int F_185 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_422 * V_148 = V_7 ;
struct V_417 V_18 ;
struct V_133 * V_153 ;
T_1 V_423 , V_424 ;
struct V_247 * V_248 ;
int V_30 ;
F_9 ( L_5 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_86 ( & V_18 . V_366 . V_118 , & V_148 -> V_366 . V_118 ) ;
V_18 . V_366 . type = V_148 -> V_366 . type ;
if ( ! F_165 ( V_148 -> V_366 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_415 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_148 -> V_425 > V_413 )
return F_11 ( V_15 , V_6 -> V_55 , V_415 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_415 ,
V_300 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
if ( F_186 ( V_6 , & V_148 -> V_366 . V_118 , V_148 -> V_366 . type ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_415 ,
V_426 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
V_423 = V_427 ;
V_424 = V_428 ;
if ( V_148 -> V_366 . type == V_367 ) {
V_248 = F_187 ( V_6 , & V_148 -> V_366 . V_118 , V_423 ,
V_424 ) ;
} else {
T_1 V_370 ;
if ( V_148 -> V_366 . type == V_378 )
V_370 = V_379 ;
else
V_370 = V_380 ;
F_188 ( V_6 , & V_148 -> V_366 . V_118 , V_370 ) ;
V_248 = F_189 ( V_6 , & V_148 -> V_366 . V_118 , V_370 ,
V_423 , V_429 ,
V_430 ) ;
}
if ( F_190 ( V_248 ) ) {
int V_224 ;
if ( F_191 ( V_248 ) == - V_431 )
V_224 = V_275 ;
else if ( F_191 ( V_248 ) == - V_432 )
V_224 = V_288 ;
else if ( F_191 ( V_248 ) == - V_433 )
V_224 = V_289 ;
else
V_224 = V_434 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_415 ,
V_224 , & V_18 , sizeof( V_18 ) ) ;
goto V_292;
}
if ( V_248 -> V_418 ) {
F_179 ( V_248 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_415 ,
V_275 , & V_18 , sizeof( V_18 ) ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_415 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
F_179 ( V_248 ) ;
goto V_292;
}
V_153 -> V_285 = F_178 ;
if ( V_148 -> V_366 . type == V_367 ) {
V_248 -> V_418 = F_183 ;
V_248 -> V_419 = F_183 ;
V_248 -> V_420 = F_183 ;
} else {
V_248 -> V_418 = F_184 ;
V_248 -> V_419 = F_184 ;
V_248 -> V_420 = F_184 ;
}
V_248 -> V_412 = V_148 -> V_425 ;
V_153 -> V_416 = F_192 ( V_248 ) ;
if ( ( V_248 -> V_231 == V_258 || V_248 -> V_231 == V_259 ) &&
F_193 ( V_248 , V_423 , V_424 , true ) ) {
V_153 -> V_285 ( V_153 , 0 ) ;
F_112 ( V_153 ) ;
}
V_30 = 0 ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_194 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_287 * V_366 = V_7 ;
struct V_133 * V_153 ;
struct V_247 * V_248 ;
int V_30 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_435 ,
V_300 ) ;
goto V_292;
}
V_153 = F_47 ( V_415 , V_6 ) ;
if ( ! V_153 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_435 ,
V_274 ) ;
goto V_292;
}
V_248 = V_153 -> V_416 ;
if ( F_28 ( & V_366 -> V_118 , & V_248 -> V_267 ) != 0 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_435 ,
V_274 ) ;
goto V_292;
}
V_153 -> V_285 ( V_153 , V_436 ) ;
F_112 ( V_153 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_435 , 0 ,
V_366 , sizeof( * V_366 ) ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_195 ( struct V_11 * V_15 , struct V_5 * V_6 ,
struct V_287 * V_366 , T_2 V_345 ,
T_2 V_437 , T_5 V_438 )
{
struct V_133 * V_153 ;
struct V_247 * V_248 ;
int V_30 ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_345 ,
V_300 , V_366 ,
sizeof( * V_366 ) ) ;
goto V_439;
}
if ( V_366 -> type == V_367 )
V_248 = F_166 ( V_6 , V_265 , & V_366 -> V_118 ) ;
else
V_248 = F_166 ( V_6 , V_201 , & V_366 -> V_118 ) ;
if ( ! V_248 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_345 ,
V_388 , V_366 ,
sizeof( * V_366 ) ) ;
goto V_439;
}
if ( V_366 -> type == V_378 || V_366 -> type == V_391 ) {
V_30 = F_196 ( V_248 , V_345 , V_438 ) ;
if ( ! V_30 )
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_345 ,
V_290 , V_366 ,
sizeof( * V_366 ) ) ;
else
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_345 ,
V_3 , V_366 ,
sizeof( * V_366 ) ) ;
goto V_439;
}
V_153 = F_102 ( V_15 , V_345 , V_6 , V_366 , sizeof( * V_366 ) ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_439;
}
V_153 -> V_285 = F_115 ;
if ( V_437 == V_440 ) {
struct V_441 V_148 ;
F_86 ( & V_148 . V_118 , & V_366 -> V_118 ) ;
V_148 . V_438 = V_438 ;
V_30 = F_135 ( V_6 , V_437 , sizeof( V_148 ) , & V_148 ) ;
} else
V_30 = F_135 ( V_6 , V_437 , sizeof( V_366 -> V_118 ) ,
& V_366 -> V_118 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_439:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_197 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_399 * V_148 = V_7 ;
F_9 ( L_5 ) ;
return F_195 ( V_15 , V_6 , & V_148 -> V_366 ,
V_400 ,
V_401 , 0 ) ;
}
static int F_198 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_442 * V_148 = V_7 ;
F_9 ( L_5 ) ;
if ( V_8 != sizeof( * V_148 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_443 ,
V_274 ) ;
return F_195 ( V_15 , V_6 , & V_148 -> V_366 ,
V_443 ,
V_444 , 0 ) ;
}
static int F_199 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_445 * V_148 = V_7 ;
F_9 ( L_5 ) ;
return F_195 ( V_15 , V_6 , & V_148 -> V_366 ,
V_446 ,
V_447 , 0 ) ;
}
static int F_200 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_448 * V_148 = V_7 ;
F_9 ( L_5 ) ;
return F_195 ( V_15 , V_6 , & V_148 -> V_366 ,
V_449 ,
V_440 , V_148 -> V_438 ) ;
}
static int F_201 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_450 * V_148 = V_7 ;
F_9 ( L_5 ) ;
return F_195 ( V_15 , V_6 , & V_148 -> V_366 ,
V_451 ,
V_452 , 0 ) ;
}
static void F_202 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_453 V_148 ;
memcpy ( V_148 . V_79 , V_6 -> V_136 , sizeof( V_148 . V_79 ) ) ;
F_54 ( V_145 , V_454 , sizeof( V_148 ) , & V_148 ) ;
}
static void F_203 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_455 * V_148 ;
struct V_133 * V_153 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_456 , V_6 ) ;
if ( ! V_153 )
goto V_292;
V_148 = V_153 -> V_156 ;
if ( V_224 )
F_101 ( V_153 -> V_15 , V_6 -> V_55 , V_456 ,
F_1 ( V_224 ) ) ;
else
F_11 ( V_153 -> V_15 , V_6 -> V_55 , V_456 , 0 ,
V_148 , sizeof( * V_148 ) ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_204 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_455 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_136 , V_148 -> V_79 , sizeof( V_6 -> V_136 ) ) &&
! memcmp ( V_6 -> V_222 , V_148 -> V_222 ,
sizeof( V_6 -> V_222 ) ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_456 , 0 ,
V_7 , V_8 ) ;
goto V_276;
}
memcpy ( V_6 -> V_222 , V_148 -> V_222 , sizeof( V_6 -> V_222 ) ) ;
if ( ! F_42 ( V_6 ) ) {
memcpy ( V_6 -> V_136 , V_148 -> V_79 , sizeof( V_6 -> V_136 ) ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_456 , 0 ,
V_7 , V_8 ) ;
if ( V_30 < 0 )
goto V_276;
V_30 = F_6 ( V_457 , V_6 ,
V_7 , V_8 , V_15 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_456 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
memcpy ( V_6 -> V_136 , V_148 -> V_79 , sizeof( V_6 -> V_136 ) ) ;
F_65 ( & V_145 , V_6 ) ;
if ( F_37 ( V_6 ) ) {
F_202 ( & V_145 ) ;
F_68 ( & V_145 ) ;
}
if ( F_40 ( V_6 ) )
F_55 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_203 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_205 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 , struct V_458 * V_459 )
{
struct V_460 V_461 ;
T_3 V_28 = sizeof( V_461 ) ;
struct V_133 * V_153 ;
F_9 ( L_16 , V_6 -> V_79 , V_224 ) ;
V_153 = F_47 ( V_462 , V_6 ) ;
if ( ! V_153 )
return;
if ( V_224 || ! V_459 ) {
F_101 ( V_153 -> V_15 , V_6 -> V_55 , V_462 ,
V_224 ? F_1 ( V_224 ) : V_3 ) ;
goto remove;
}
memset ( & V_461 , 0 , sizeof( V_461 ) ) ;
if ( V_37 == V_463 ) {
struct V_464 * V_18 = ( void * ) V_459 -> V_7 ;
if ( V_459 -> V_8 < sizeof( * V_18 ) ) {
F_101 ( V_153 -> V_15 , V_6 -> V_55 ,
V_462 ,
V_3 ) ;
goto remove;
}
memcpy ( V_461 . V_465 , V_18 -> V_466 , sizeof( V_18 -> V_466 ) ) ;
memcpy ( V_461 . V_467 , V_18 -> rand , sizeof( V_18 -> rand ) ) ;
V_28 -= sizeof( V_461 . V_468 ) + sizeof( V_461 . V_469 ) ;
} else {
struct V_470 * V_18 = ( void * ) V_459 -> V_7 ;
if ( V_459 -> V_8 < sizeof( * V_18 ) ) {
F_101 ( V_153 -> V_15 , V_6 -> V_55 ,
V_462 ,
V_3 ) ;
goto remove;
}
memcpy ( V_461 . V_465 , V_18 -> V_465 , sizeof( V_18 -> V_465 ) ) ;
memcpy ( V_461 . V_467 , V_18 -> V_467 , sizeof( V_18 -> V_467 ) ) ;
memcpy ( V_461 . V_468 , V_18 -> V_468 , sizeof( V_18 -> V_468 ) ) ;
memcpy ( V_461 . V_469 , V_18 -> V_469 , sizeof( V_18 -> V_469 ) ) ;
}
F_11 ( V_153 -> V_15 , V_6 -> V_55 , V_462 ,
V_290 , & V_461 , V_28 ) ;
remove:
F_112 ( V_153 ) ;
}
static int F_206 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_462 ,
V_300 ) ;
goto V_292;
}
if ( ! F_38 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_462 ,
V_288 ) ;
goto V_292;
}
if ( F_47 ( V_462 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_462 ,
V_275 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_462 , V_6 , NULL , 0 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
if ( F_207 ( V_6 ) )
F_54 ( & V_145 , V_471 , 0 , NULL ) ;
else
F_54 ( & V_145 , V_463 , 0 , NULL ) ;
V_30 = F_208 ( & V_145 , F_205 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_209 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_287 * V_366 = V_7 ;
int V_30 ;
F_9 ( L_17 , V_6 -> V_79 ) ;
if ( ! F_165 ( V_366 -> type ) )
return F_11 ( V_15 , V_6 -> V_55 ,
V_472 ,
V_274 ,
V_366 , sizeof( * V_366 ) ) ;
F_34 ( V_6 ) ;
if ( V_8 == V_473 ) {
struct V_474 * V_148 = V_7 ;
T_1 V_224 ;
if ( V_148 -> V_366 . type != V_367 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_472 ,
V_274 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
goto V_292;
}
V_30 = F_210 ( V_6 , & V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type , V_148 -> V_466 ,
V_148 -> rand , NULL , NULL ) ;
if ( V_30 < 0 )
V_224 = V_3 ;
else
V_224 = V_290 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_472 , V_224 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
} else if ( V_8 == V_475 ) {
struct V_476 * V_148 = V_7 ;
T_1 * V_467 , * V_465 , * V_469 , * V_468 ;
T_1 V_224 ;
if ( F_211 ( V_148 -> V_366 . type ) ) {
if ( memcmp ( V_148 -> V_467 , V_477 , 16 ) ||
memcmp ( V_148 -> V_465 , V_477 , 16 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_472 ,
V_274 ,
V_366 , sizeof( * V_366 ) ) ;
goto V_292;
}
V_467 = NULL ;
V_465 = NULL ;
} else {
if ( ! memcmp ( V_148 -> V_467 , V_477 , 16 ) ||
! memcmp ( V_148 -> V_465 , V_477 , 16 ) ) {
V_467 = NULL ;
V_465 = NULL ;
} else {
V_467 = V_148 -> V_467 ;
V_465 = V_148 -> V_465 ;
}
}
if ( ! memcmp ( V_148 -> V_469 , V_477 , 16 ) ||
! memcmp ( V_148 -> V_468 , V_477 , 16 ) ) {
V_469 = NULL ;
V_468 = NULL ;
} else {
V_469 = V_148 -> V_469 ;
V_468 = V_148 -> V_468 ;
}
V_30 = F_210 ( V_6 , & V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type , V_465 , V_467 ,
V_468 , V_469 ) ;
if ( V_30 < 0 )
V_224 = V_3 ;
else
V_224 = V_290 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_472 ,
V_224 , & V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
} else {
F_160 ( L_18 , V_8 ) ;
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_472 ,
V_274 ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_212 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_478 * V_148 = V_7 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( V_148 -> V_366 . type != V_367 )
return F_11 ( V_15 , V_6 -> V_55 ,
V_479 ,
V_274 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_28 ( & V_148 -> V_366 . V_118 , V_72 ) ) {
F_213 ( V_6 ) ;
V_224 = V_290 ;
goto V_439;
}
V_30 = F_214 ( V_6 , & V_148 -> V_366 . V_118 , V_148 -> V_366 . type ) ;
if ( V_30 < 0 )
V_224 = V_274 ;
else
V_224 = V_290 ;
V_439:
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_479 ,
V_224 , & V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_215 ( struct V_144 * V_145 , T_1 * V_224 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_480 V_148 ;
T_1 V_481 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
* V_224 = F_116 ( V_6 ) ;
if ( * V_224 )
return false ;
if ( F_20 ( V_6 , V_233 ) ) {
* V_224 = V_275 ;
return false ;
}
F_216 ( V_6 ) ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
memcpy ( & V_148 . V_481 , V_481 , sizeof( V_148 . V_481 ) ) ;
V_148 . V_150 = V_482 ;
F_54 ( V_145 , V_483 , sizeof( V_148 ) , & V_148 ) ;
return true ;
}
static bool F_217 ( struct V_144 * V_145 , T_2 V_312 , T_1 * V_224 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_484 V_485 ;
struct V_486 V_487 ;
T_1 V_199 ;
int V_30 ;
* V_224 = F_117 ( V_6 ) ;
if ( * V_224 )
return false ;
if ( F_20 ( V_6 , V_202 ) ) {
if ( F_218 ( V_6 , V_201 , V_263 ) ) {
* V_224 = V_289 ;
return false ;
}
F_72 ( V_145 ) ;
}
if ( F_20 ( V_6 , V_235 ) )
F_93 ( V_145 ) ;
V_30 = F_76 ( V_145 , true , & V_199 ) ;
if ( V_30 < 0 ) {
* V_224 = V_3 ;
return false ;
}
memset ( & V_485 , 0 , sizeof( V_485 ) ) ;
V_485 . type = V_488 ;
V_485 . V_312 = F_10 ( V_312 ) ;
V_485 . V_314 = F_10 ( V_489 ) ;
V_485 . V_210 = V_199 ;
F_54 ( V_145 , V_490 , sizeof( V_485 ) ,
& V_485 ) ;
memset ( & V_487 , 0 , sizeof( V_487 ) ) ;
V_487 . V_196 = V_491 ;
V_487 . V_492 = V_493 ;
F_54 ( V_145 , V_494 , sizeof( V_487 ) ,
& V_487 ) ;
return true ;
}
static bool F_219 ( struct V_144 * V_145 , T_1 * V_224 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
switch ( V_6 -> V_230 . type ) {
case V_495 :
if ( ! F_215 ( V_145 , V_224 ) )
return false ;
break;
case V_496 :
if ( F_22 ( V_497 ,
& V_6 -> V_53 ) ) {
if ( ! F_217 ( V_145 , V_498 * 2 ,
V_224 ) )
return false ;
if ( ! F_215 ( V_145 , V_224 ) )
return false ;
return true ;
}
if ( ! F_20 ( V_6 , V_108 ) ) {
* V_224 = V_288 ;
return false ;
}
case V_499 :
if ( ! F_217 ( V_145 , V_498 , V_224 ) )
return false ;
break;
default:
* V_224 = V_274 ;
return false ;
}
return true ;
}
static void F_220 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_133 * V_153 ;
unsigned long V_245 ;
F_9 ( L_19 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_500 , V_6 ) ;
if ( ! V_153 )
V_153 = F_47 ( V_501 , V_6 ) ;
if ( V_153 ) {
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
if ( V_224 ) {
F_99 ( V_6 , V_502 ) ;
goto V_292;
}
F_99 ( V_6 , V_232 ) ;
switch ( V_6 -> V_230 . type ) {
case V_499 :
V_245 = F_119 ( V_503 ) ;
break;
case V_496 :
if ( F_22 ( V_497 , & V_6 -> V_53 ) )
V_245 = F_119 ( V_503 ) ;
else
V_245 = F_119 ( V_6 -> V_504 ) ;
break;
case V_495 :
V_245 = 0 ;
break;
default:
F_160 ( L_20 , V_6 -> V_230 . type ) ;
V_245 = 0 ;
break;
}
if ( V_245 ) {
if ( F_22 ( V_505 ,
& V_6 -> V_53 ) &&
V_6 -> V_230 . V_506 ) {
V_6 -> V_230 . V_507 = V_508 ;
V_6 -> V_230 . V_509 = V_245 ;
}
F_104 ( V_6 -> V_297 ,
& V_6 -> V_236 , V_245 ) ;
}
V_292:
F_35 ( V_6 ) ;
}
static int F_221 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_510 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_500 ,
V_300 ,
& V_148 -> type , sizeof( V_148 -> type ) ) ;
goto V_276;
}
if ( V_6 -> V_230 . V_231 != V_502 ||
F_20 ( V_6 , V_511 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_500 ,
V_275 , & V_148 -> type ,
sizeof( V_148 -> type ) ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_500 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
V_153 -> V_285 = F_114 ;
F_222 ( V_6 ) ;
V_6 -> V_230 . type = V_148 -> type ;
V_6 -> V_230 . V_512 = false ;
F_65 ( & V_145 , V_6 ) ;
if ( ! F_219 ( & V_145 , & V_224 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_500 ,
V_224 , & V_148 -> type , sizeof( V_148 -> type ) ) ;
F_112 ( V_153 ) ;
goto V_276;
}
V_30 = F_66 ( & V_145 , F_220 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
goto V_276;
}
F_99 ( V_6 , V_513 ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_223 ( struct V_133 * V_153 ,
T_1 V_224 )
{
return F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_224 ,
V_153 -> V_156 , 1 ) ;
}
static int F_224 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_514 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
const T_2 V_515 = ( ( V_358 - sizeof( * V_148 ) ) / 16 ) ;
T_2 V_516 , V_361 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_501 ,
V_300 ,
& V_148 -> type , sizeof( V_148 -> type ) ) ;
goto V_276;
}
if ( V_6 -> V_230 . V_231 != V_502 ||
F_20 ( V_6 , V_511 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_501 ,
V_275 , & V_148 -> type ,
sizeof( V_148 -> type ) ) ;
goto V_276;
}
V_516 = F_122 ( V_148 -> V_516 ) ;
if ( V_516 > V_515 ) {
F_160 ( L_21 ,
V_516 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_501 ,
V_274 , & V_148 -> type ,
sizeof( V_148 -> type ) ) ;
goto V_276;
}
V_361 = sizeof( * V_148 ) + V_516 * 16 ;
if ( V_361 != V_8 ) {
F_160 ( L_22 ,
V_361 , V_8 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_501 ,
V_274 , & V_148 -> type ,
sizeof( V_148 -> type ) ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_501 ,
V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
V_153 -> V_285 = F_223 ;
F_222 ( V_6 ) ;
V_6 -> V_230 . V_506 = true ;
V_6 -> V_230 . type = V_148 -> type ;
V_6 -> V_230 . V_517 = V_148 -> V_517 ;
V_6 -> V_230 . V_516 = V_516 ;
if ( V_516 > 0 ) {
V_6 -> V_230 . V_347 = F_225 ( V_148 -> V_347 , V_516 * 16 ,
V_35 ) ;
if ( ! V_6 -> V_230 . V_347 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_501 ,
V_3 ,
& V_148 -> type , sizeof( V_148 -> type ) ) ;
F_112 ( V_153 ) ;
goto V_276;
}
}
F_65 ( & V_145 , V_6 ) ;
if ( ! F_219 ( & V_145 , & V_224 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_501 ,
V_224 , & V_148 -> type , sizeof( V_148 -> type ) ) ;
F_112 ( V_153 ) ;
goto V_276;
}
V_30 = F_66 ( & V_145 , F_220 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
goto V_276;
}
F_99 ( V_6 , V_513 ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_226 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_133 * V_153 ;
F_9 ( L_19 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_518 , V_6 ) ;
if ( V_153 ) {
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
if ( ! V_224 )
F_99 ( V_6 , V_502 ) ;
F_35 ( V_6 ) ;
}
static int F_227 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_519 * V_520 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_228 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_518 ,
V_289 , & V_520 -> type ,
sizeof( V_520 -> type ) ) ;
goto V_292;
}
if ( V_6 -> V_230 . type != V_520 -> type ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_518 ,
V_274 ,
& V_520 -> type , sizeof( V_520 -> type ) ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_518 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_153 -> V_285 = F_114 ;
F_65 ( & V_145 , V_6 ) ;
F_92 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_226 ) ;
if ( ! V_30 ) {
F_99 ( V_6 , V_272 ) ;
goto V_292;
}
F_112 ( V_153 ) ;
if ( V_30 == - V_280 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_518 , 0 ,
& V_520 -> type , sizeof( V_520 -> type ) ) ;
F_99 ( V_6 , V_502 ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_229 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_521 * V_148 = V_7 ;
struct V_228 * V_229 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_228 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_522 ,
V_3 , & V_148 -> V_366 ,
sizeof( V_148 -> V_366 ) ) ;
goto V_276;
}
V_229 = F_230 ( V_6 , & V_148 -> V_366 . V_118 ) ;
if ( ! V_229 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_522 ,
V_274 , & V_148 -> V_366 ,
sizeof( V_148 -> V_366 ) ) ;
goto V_276;
}
if ( V_148 -> V_523 ) {
V_229 -> V_524 = V_525 ;
F_108 ( & V_229 -> V_284 ) ;
} else {
V_229 -> V_524 = V_526 ;
F_231 ( V_6 , V_229 ) ;
}
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_522 , 0 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_232 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_527 * V_148 = V_7 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_165 ( V_148 -> V_366 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_528 ,
V_274 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_34 ( V_6 ) ;
V_30 = F_233 ( & V_6 -> V_529 , & V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type ) ;
if ( V_30 < 0 ) {
V_224 = V_3 ;
goto V_439;
}
F_7 ( V_530 , V_6 , & V_148 -> V_366 , sizeof( V_148 -> V_366 ) ,
V_15 ) ;
V_224 = V_290 ;
V_439:
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_528 , V_224 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_234 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_531 * V_148 = V_7 ;
T_1 V_224 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_165 ( V_148 -> V_366 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_532 ,
V_274 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_34 ( V_6 ) ;
V_30 = F_235 ( & V_6 -> V_529 , & V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type ) ;
if ( V_30 < 0 ) {
V_224 = V_274 ;
goto V_439;
}
F_7 ( V_533 , V_6 , & V_148 -> V_366 , sizeof( V_148 -> V_366 ) ,
V_15 ) ;
V_224 = V_290 ;
V_439:
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_532 , V_224 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_236 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_534 * V_148 = V_7 ;
struct V_144 V_145 ;
int V_30 ;
T_9 V_535 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
V_535 = F_122 ( V_148 -> V_535 ) ;
if ( V_535 > 0x0002 )
return F_101 ( V_15 , V_6 -> V_55 , V_536 ,
V_274 ) ;
F_34 ( V_6 ) ;
V_6 -> V_180 = V_535 ;
V_6 -> V_182 = F_122 ( V_148 -> V_537 ) ;
V_6 -> V_183 = F_122 ( V_148 -> V_538 ) ;
V_6 -> V_184 = F_122 ( V_148 -> V_19 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_536 , 0 ,
NULL , 0 ) ;
F_65 ( & V_145 , V_6 ) ;
F_68 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_237 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
F_9 ( L_19 , V_224 ) ;
}
static void F_238 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_282 V_283 = { NULL , V_6 } ;
struct V_144 V_145 ;
F_34 ( V_6 ) ;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
F_139 ( V_337 , V_6 ,
F_111 , & V_293 ) ;
goto V_292;
}
if ( F_20 ( V_6 , V_202 ) )
F_81 ( V_6 , V_113 ) ;
else
F_75 ( V_6 , V_113 ) ;
F_139 ( V_337 , V_6 , F_107 ,
& V_283 ) ;
F_105 ( V_6 , V_283 . V_15 ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
if ( F_20 ( V_6 , V_113 ) ||
! F_20 ( V_6 , V_152 ) )
goto V_292;
F_65 ( & V_145 , V_6 ) ;
F_63 ( & V_145 ) ;
F_73 ( & V_145 ) ;
if ( F_66 ( & V_145 , F_237 ) < 0 )
F_160 ( L_23 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_239 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
T_1 V_157 , V_224 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_224 = F_117 ( V_6 ) ;
if ( V_224 )
return F_101 ( V_15 , V_6 -> V_55 , V_337 ,
V_224 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 && V_148 -> V_157 != 0x02 )
return F_101 ( V_15 , V_6 -> V_55 , V_337 ,
V_274 ) ;
F_34 ( V_6 ) ;
V_157 = ! ! V_148 -> V_157 ;
if ( ! F_42 ( V_6 ) ||
( V_157 == F_20 ( V_6 , V_113 ) &&
( V_148 -> V_157 == 0x02 ) == F_20 ( V_6 , V_165 ) ) ||
F_74 ( V_6 , V_201 ) > 0 ||
( F_20 ( V_6 , V_235 ) &&
V_6 -> V_539 == V_488 ) ) {
bool V_291 ;
if ( V_148 -> V_157 ) {
V_291 = ! F_83 ( V_6 , V_113 ) ;
if ( V_148 -> V_157 == 0x02 )
F_81 ( V_6 , V_165 ) ;
else
F_75 ( V_6 , V_165 ) ;
} else {
V_291 = F_79 ( V_6 , V_113 ) ;
F_75 ( V_6 , V_165 ) ;
}
V_30 = F_87 ( V_15 , V_337 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_292;
}
if ( F_47 ( V_337 , V_6 ) ||
F_47 ( V_334 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_337 ,
V_275 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_337 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
if ( V_148 -> V_157 == 0x02 )
F_81 ( V_6 , V_165 ) ;
else
F_75 ( V_6 , V_165 ) ;
if ( V_157 ) {
F_62 ( & V_145 , 0 ) ;
F_53 ( & V_145 , 0 ) ;
F_73 ( & V_145 ) ;
} else {
F_72 ( & V_145 ) ;
}
V_30 = F_66 ( & V_145 , F_238 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_240 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_540 * V_148 = V_7 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_541 ,
V_288 ) ;
if ( F_42 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_541 ,
V_289 ) ;
if ( F_28 ( & V_148 -> V_118 , V_72 ) ) {
if ( ! F_28 ( & V_148 -> V_118 , V_542 ) )
return F_101 ( V_15 , V_6 -> V_55 ,
V_541 ,
V_274 ) ;
if ( ( V_148 -> V_118 . V_543 [ 5 ] & 0xc0 ) != 0xc0 )
return F_101 ( V_15 , V_6 -> V_55 ,
V_541 ,
V_274 ) ;
}
F_34 ( V_6 ) ;
F_86 ( & V_6 -> V_119 , & V_148 -> V_118 ) ;
V_30 = F_87 ( V_15 , V_541 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
V_30 = F_105 ( V_6 , V_15 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_241 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_544 * V_148 = V_7 ;
T_9 V_312 , V_314 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_545 ,
V_288 ) ;
V_312 = F_122 ( V_148 -> V_312 ) ;
if ( V_312 < 0x0004 || V_312 > 0x4000 )
return F_101 ( V_15 , V_6 -> V_55 , V_545 ,
V_274 ) ;
V_314 = F_122 ( V_148 -> V_314 ) ;
if ( V_314 < 0x0004 || V_314 > 0x4000 )
return F_101 ( V_15 , V_6 -> V_55 , V_545 ,
V_274 ) ;
if ( V_314 > V_312 )
return F_101 ( V_15 , V_6 -> V_55 , V_545 ,
V_274 ) ;
F_34 ( V_6 ) ;
V_6 -> V_546 = V_312 ;
V_6 -> V_547 = V_314 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_545 , 0 ,
NULL , 0 ) ;
if ( F_20 ( V_6 , V_235 ) &&
V_6 -> V_230 . V_231 == V_502 ) {
struct V_144 V_145 ;
F_65 ( & V_145 , V_6 ) ;
F_93 ( & V_145 ) ;
F_242 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
}
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_243 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_133 * V_153 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_548 , V_6 ) ;
if ( ! V_153 )
goto V_292;
if ( V_224 ) {
F_101 ( V_153 -> V_15 , V_6 -> V_55 , V_548 ,
F_1 ( V_224 ) ) ;
} else {
struct V_155 * V_148 = V_153 -> V_156 ;
if ( V_148 -> V_157 )
F_81 ( V_6 , V_105 ) ;
else
F_75 ( V_6 , V_105 ) ;
F_87 ( V_153 -> V_15 , V_548 , V_6 ) ;
F_105 ( V_6 , V_153 -> V_15 ) ;
}
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_244 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_20 ( V_6 , V_108 ) ||
V_6 -> V_91 < V_92 )
return F_101 ( V_15 , V_6 -> V_55 , V_548 ,
V_288 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_548 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_548 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_548 ,
V_275 ) ;
goto V_292;
}
if ( ! ! V_148 -> V_157 == F_20 ( V_6 , V_105 ) ) {
V_30 = F_87 ( V_15 , V_548 ,
V_6 ) ;
goto V_292;
}
if ( ! F_42 ( V_6 ) ) {
F_123 ( V_6 , V_105 ) ;
V_30 = F_87 ( V_15 , V_548 ,
V_6 ) ;
F_105 ( V_6 , V_15 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_548 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
F_125 ( & V_145 , V_148 -> V_157 ) ;
V_30 = F_66 ( & V_145 , F_243 ) ;
if ( V_30 < 0 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_548 ,
V_3 ) ;
F_112 ( V_153 ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_245 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_133 * V_153 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_549 , V_6 ) ;
if ( ! V_153 )
goto V_292;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
F_75 ( V_6 , V_108 ) ;
F_101 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_293 ) ;
} else {
F_87 ( V_153 -> V_15 , V_549 , V_6 ) ;
F_105 ( V_6 , V_153 -> V_15 ) ;
}
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_246 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_37 ( V_6 ) || ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_549 ,
V_288 ) ;
if ( ! F_20 ( V_6 , V_109 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_549 ,
V_289 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_549 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( V_148 -> V_157 == F_20 ( V_6 , V_108 ) ) {
V_30 = F_87 ( V_15 , V_549 , V_6 ) ;
goto V_292;
}
if ( ! F_42 ( V_6 ) ) {
if ( ! V_148 -> V_157 ) {
F_75 ( V_6 , V_106 ) ;
F_75 ( V_6 , V_111 ) ;
F_75 ( V_6 , V_110 ) ;
F_75 ( V_6 , V_105 ) ;
F_75 ( V_6 , V_112 ) ;
}
F_123 ( V_6 , V_108 ) ;
V_30 = F_87 ( V_15 , V_549 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_292;
}
if ( ! V_148 -> V_157 ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_549 ,
V_289 ) ;
goto V_292;
} else {
if ( ! F_20 ( V_6 , V_108 ) &&
( F_28 ( & V_6 -> V_119 , V_72 ) ||
F_20 ( V_6 , V_114 ) ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_549 ,
V_289 ) ;
goto V_292;
}
}
if ( F_47 ( V_549 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_549 ,
V_275 ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_549 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_81 ( V_6 , V_108 ) ;
F_65 ( & V_145 , V_6 ) ;
F_125 ( & V_145 , false ) ;
F_120 ( & V_145 ) ;
F_63 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_245 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_247 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_133 * V_153 ;
struct V_155 * V_148 ;
F_9 ( L_16 , V_6 -> V_79 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_550 , V_6 ) ;
if ( ! V_153 )
goto V_292;
if ( V_224 ) {
F_101 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 ,
F_1 ( V_224 ) ) ;
goto remove;
}
V_148 = V_153 -> V_156 ;
switch ( V_148 -> V_157 ) {
case 0x00 :
F_75 ( V_6 , V_114 ) ;
F_75 ( V_6 , V_551 ) ;
break;
case 0x01 :
F_81 ( V_6 , V_114 ) ;
F_75 ( V_6 , V_551 ) ;
break;
case 0x02 :
F_81 ( V_6 , V_114 ) ;
F_81 ( V_6 , V_551 ) ;
break;
}
F_87 ( V_153 -> V_15 , V_550 , V_6 ) ;
F_105 ( V_6 , V_153 -> V_15 ) ;
remove:
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_248 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
T_1 V_157 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_39 ( V_6 ) &&
! F_20 ( V_6 , V_109 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_550 ,
V_288 ) ;
if ( F_20 ( V_6 , V_108 ) &&
F_39 ( V_6 ) &&
! F_20 ( V_6 , V_111 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_550 ,
V_289 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 && V_148 -> V_157 != 0x02 )
return F_101 ( V_15 , V_6 -> V_55 , V_550 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) || ! F_39 ( V_6 ) ||
! F_20 ( V_6 , V_108 ) ) {
bool V_291 ;
if ( V_148 -> V_157 ) {
V_291 = ! F_83 ( V_6 ,
V_114 ) ;
if ( V_148 -> V_157 == 0x02 )
F_81 ( V_6 , V_551 ) ;
else
F_75 ( V_6 , V_551 ) ;
} else {
V_291 = F_79 ( V_6 ,
V_114 ) ;
F_75 ( V_6 , V_551 ) ;
}
V_30 = F_87 ( V_15 , V_550 , V_6 ) ;
if ( V_30 < 0 )
goto V_276;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
goto V_276;
}
if ( F_47 ( V_550 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_550 ,
V_275 ) ;
goto V_276;
}
V_157 = ! ! V_148 -> V_157 ;
if ( V_157 == F_20 ( V_6 , V_114 ) &&
( V_148 -> V_157 == 0x02 ) == F_20 ( V_6 , V_551 ) ) {
V_30 = F_87 ( V_15 , V_550 , V_6 ) ;
goto V_276;
}
V_153 = F_102 ( V_15 , V_550 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_276;
}
F_65 ( & V_145 , V_6 ) ;
F_54 ( & V_145 , V_552 , 1 , & V_157 ) ;
V_30 = F_66 ( & V_145 , F_247 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
goto V_276;
}
V_276:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_249 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_155 * V_148 = V_7 ;
bool V_291 , V_553 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( V_148 -> V_157 != 0x00 && V_148 -> V_157 != 0x01 && V_148 -> V_157 != 0x02 )
return F_101 ( V_15 , V_6 -> V_55 , V_554 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( V_148 -> V_157 )
V_291 = ! F_83 ( V_6 , V_115 ) ;
else
V_291 = F_79 ( V_6 ,
V_115 ) ;
if ( V_148 -> V_157 == 0x02 )
V_553 = ! F_83 ( V_6 ,
V_330 ) ;
else
V_553 = F_79 ( V_6 ,
V_330 ) ;
if ( F_42 ( V_6 ) && V_553 &&
F_20 ( V_6 , V_111 ) ) {
T_1 V_555 = ( V_148 -> V_157 == 0x02 ) ? 0x01 : 0x00 ;
F_135 ( V_6 , V_331 ,
sizeof( V_555 ) , & V_555 ) ;
}
V_30 = F_87 ( V_15 , V_554 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_250 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_556 ,
T_2 V_8 )
{
struct V_557 * V_148 = V_556 ;
bool V_291 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_558 ,
V_288 ) ;
if ( V_148 -> V_559 != 0x00 && V_148 -> V_559 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_558 ,
V_274 ) ;
if ( F_42 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_558 ,
V_289 ) ;
F_34 ( V_6 ) ;
F_81 ( V_6 , V_560 ) ;
if ( V_148 -> V_559 ) {
V_291 = ! F_83 ( V_6 , V_116 ) ;
memcpy ( V_6 -> V_561 , V_148 -> V_561 , sizeof( V_6 -> V_561 ) ) ;
F_81 ( V_6 , V_217 ) ;
} else {
V_291 = F_79 ( V_6 , V_116 ) ;
memset ( V_6 -> V_561 , 0 , sizeof( V_6 -> V_561 ) ) ;
F_75 ( V_6 , V_217 ) ;
}
V_30 = F_87 ( V_15 , V_558 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( V_291 )
V_30 = F_105 ( V_6 , V_15 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_251 ( struct V_562 * V_561 )
{
switch ( V_561 -> V_366 . type ) {
case V_378 :
return true ;
case V_391 :
if ( ( V_561 -> V_366 . V_118 . V_543 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_252 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_556 ,
T_2 V_8 )
{
struct V_563 * V_148 = V_556 ;
const T_2 V_564 = ( ( V_358 - sizeof( * V_148 ) ) /
sizeof( struct V_562 ) ) ;
T_2 V_565 , V_361 ;
int V_29 , V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_566 ,
V_288 ) ;
V_565 = F_122 ( V_148 -> V_565 ) ;
if ( V_565 > V_564 ) {
F_160 ( L_24 , V_565 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_566 ,
V_274 ) ;
}
V_361 = sizeof( * V_148 ) + V_565 * sizeof( struct V_562 ) ;
if ( V_361 != V_8 ) {
F_160 ( L_25 ,
V_361 , V_8 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_566 ,
V_274 ) ;
}
F_9 ( L_26 , V_6 -> V_79 , V_565 ) ;
for ( V_29 = 0 ; V_29 < V_565 ; V_29 ++ ) {
struct V_562 * V_364 = & V_148 -> V_567 [ V_29 ] ;
if ( ! F_251 ( V_364 ) )
return F_101 ( V_15 , V_6 -> V_55 ,
V_566 ,
V_274 ) ;
}
F_34 ( V_6 ) ;
F_253 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_565 ; V_29 ++ ) {
struct V_562 * V_561 = & V_148 -> V_567 [ V_29 ] ;
T_1 V_370 ;
if ( V_561 -> V_366 . type == V_378 )
V_370 = V_379 ;
else
V_370 = V_380 ;
F_254 ( V_6 , & V_561 -> V_366 . V_118 , V_370 , V_561 -> V_157 ,
V_72 ) ;
}
F_81 ( V_6 , V_560 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_566 , 0 , NULL , 0 ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_255 ( struct V_568 * V_364 )
{
if ( V_364 -> V_569 != 0x00 && V_364 -> V_569 != 0x01 )
return false ;
switch ( V_364 -> V_366 . type ) {
case V_378 :
return true ;
case V_391 :
if ( ( V_364 -> V_366 . V_118 . V_543 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_256 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_556 , T_2 V_8 )
{
struct V_570 * V_148 = V_556 ;
const T_2 V_357 = ( ( V_358 - sizeof( * V_148 ) ) /
sizeof( struct V_568 ) ) ;
T_2 V_360 , V_361 ;
int V_29 , V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_571 ,
V_288 ) ;
V_360 = F_122 ( V_148 -> V_360 ) ;
if ( V_360 > V_357 ) {
F_160 ( L_27 , V_360 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_571 ,
V_274 ) ;
}
V_361 = sizeof( * V_148 ) + V_360 *
sizeof( struct V_568 ) ;
if ( V_361 != V_8 ) {
F_160 ( L_28 ,
V_361 , V_8 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_571 ,
V_274 ) ;
}
F_9 ( L_29 , V_6 -> V_79 , V_360 ) ;
for ( V_29 = 0 ; V_29 < V_360 ; V_29 ++ ) {
struct V_568 * V_364 = & V_148 -> V_365 [ V_29 ] ;
if ( ! F_255 ( V_364 ) )
return F_101 ( V_15 , V_6 -> V_55 ,
V_571 ,
V_274 ) ;
}
F_34 ( V_6 ) ;
F_257 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_360 ; V_29 ++ ) {
struct V_568 * V_364 = & V_148 -> V_365 [ V_29 ] ;
T_1 type , V_370 , V_572 ;
if ( V_364 -> V_366 . type == V_378 )
V_370 = V_379 ;
else
V_370 = V_380 ;
switch ( V_364 -> type ) {
case V_573 :
V_572 = 0x00 ;
type = V_364 -> V_569 ? V_574 : V_575 ;
break;
case V_576 :
V_572 = 0x01 ;
type = V_364 -> V_569 ? V_574 : V_575 ;
break;
case V_577 :
V_572 = 0x00 ;
type = V_578 ;
break;
case V_579 :
V_572 = 0x01 ;
type = V_578 ;
break;
case V_580 :
V_572 = 0x00 ;
type = V_581 ;
default:
continue;
}
F_258 ( V_6 , & V_364 -> V_366 . V_118 , V_370 , type ,
V_572 , V_364 -> V_157 , V_364 -> V_582 , V_364 -> V_583 ,
V_364 -> rand ) ;
}
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_571 , 0 ,
NULL , 0 ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_259 ( struct V_133 * V_153 , T_1 V_224 )
{
struct V_247 * V_248 = V_153 -> V_416 ;
struct V_584 V_18 ;
int V_30 ;
memcpy ( & V_18 . V_366 , V_153 -> V_156 , sizeof( V_18 . V_366 ) ) ;
if ( V_224 == V_290 ) {
V_18 . V_517 = V_248 -> V_517 ;
V_18 . V_585 = V_248 -> V_585 ;
V_18 . V_586 = V_248 -> V_586 ;
} else {
V_18 . V_517 = V_587 ;
V_18 . V_585 = V_175 ;
V_18 . V_586 = V_175 ;
}
V_30 = F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_588 ,
V_224 , & V_18 , sizeof( V_18 ) ) ;
F_179 ( V_248 ) ;
F_181 ( V_248 ) ;
return V_30 ;
}
static void F_260 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_37 )
{
struct V_589 * V_148 ;
struct V_133 * V_153 ;
struct V_247 * V_248 ;
T_2 V_260 ;
T_1 V_224 ;
F_9 ( L_8 , V_1 ) ;
F_34 ( V_6 ) ;
V_148 = F_261 ( V_6 , V_590 ) ;
if ( ! V_148 ) {
V_148 = F_261 ( V_6 , V_591 ) ;
V_224 = V_290 ;
} else {
V_224 = F_1 ( V_1 ) ;
}
if ( ! V_148 ) {
F_160 ( L_30 ) ;
goto V_292;
}
V_260 = F_122 ( V_148 -> V_260 ) ;
V_248 = F_262 ( V_6 , V_260 ) ;
if ( ! V_248 ) {
F_160 ( L_31 , V_260 ) ;
goto V_292;
}
V_153 = F_49 ( V_588 , V_6 , V_248 ) ;
if ( ! V_153 )
goto V_292;
V_153 -> V_285 ( V_153 , V_224 ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_263 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_592 * V_148 = V_7 ;
struct V_584 V_18 ;
struct V_247 * V_248 ;
unsigned long V_593 ;
int V_30 = 0 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_86 ( & V_18 . V_366 . V_118 , & V_148 -> V_366 . V_118 ) ;
V_18 . V_366 . type = V_148 -> V_366 . type ;
if ( ! F_165 ( V_148 -> V_366 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_588 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_588 ,
V_300 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
if ( V_148 -> V_366 . type == V_367 )
V_248 = F_166 ( V_6 , V_265 ,
& V_148 -> V_366 . V_118 ) ;
else
V_248 = F_166 ( V_6 , V_201 , & V_148 -> V_366 . V_118 ) ;
if ( ! V_248 || V_248 -> V_231 != V_258 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_588 ,
V_388 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
if ( F_49 ( V_588 , V_6 , V_248 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_588 ,
V_275 , & V_18 , sizeof( V_18 ) ) ;
goto V_292;
}
V_593 = V_6 -> V_594 +
F_264 ( V_6 -> V_595 -
V_6 -> V_594 ) ;
if ( F_265 ( V_508 , V_248 -> V_596 +
F_119 ( V_593 ) ) ||
! V_248 -> V_596 ) {
struct V_144 V_145 ;
struct V_597 V_598 ;
struct V_589 V_599 ;
struct V_133 * V_153 ;
F_65 ( & V_145 , V_6 ) ;
V_599 . V_260 = F_10 ( V_248 -> V_260 ) ;
F_54 ( & V_145 , V_590 , sizeof( V_599 ) ,
& V_599 ) ;
if ( ! F_211 ( V_148 -> V_366 . type ) ||
V_248 -> V_585 == V_175 ) {
V_598 . V_260 = F_10 ( V_248 -> V_260 ) ;
V_598 . type = 0x00 ;
F_54 ( & V_145 , V_591 ,
sizeof( V_598 ) , & V_598 ) ;
}
if ( V_248 -> V_586 == V_175 ) {
V_598 . V_260 = F_10 ( V_248 -> V_260 ) ;
V_598 . type = 0x01 ;
F_54 ( & V_145 , V_591 ,
sizeof( V_598 ) , & V_598 ) ;
}
V_30 = F_66 ( & V_145 , F_260 ) ;
if ( V_30 < 0 )
goto V_292;
V_153 = F_102 ( V_15 , V_588 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_266 ( V_248 ) ;
V_153 -> V_416 = F_192 ( V_248 ) ;
V_153 -> V_285 = F_259 ;
V_248 -> V_596 = V_508 ;
} else {
V_18 . V_517 = V_248 -> V_517 ;
V_18 . V_585 = V_248 -> V_585 ;
V_18 . V_586 = V_248 -> V_586 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_588 ,
V_290 , & V_18 , sizeof( V_18 ) ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_267 ( struct V_133 * V_153 , T_1 V_224 )
{
struct V_247 * V_248 = V_153 -> V_416 ;
struct V_600 V_18 ;
struct V_5 * V_6 ;
int V_30 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memcpy ( & V_18 . V_366 , & V_153 -> V_156 , sizeof( V_18 . V_366 ) ) ;
if ( V_224 )
goto V_421;
V_6 = F_268 ( V_153 -> V_54 ) ;
if ( V_6 ) {
V_18 . V_601 = F_30 ( V_6 -> clock ) ;
F_269 ( V_6 ) ;
}
if ( V_248 ) {
V_18 . V_602 = F_30 ( V_248 -> clock ) ;
V_18 . V_603 = F_10 ( V_248 -> V_604 ) ;
}
V_421:
V_30 = F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_224 , & V_18 ,
sizeof( V_18 ) ) ;
if ( V_248 ) {
F_179 ( V_248 ) ;
F_181 ( V_248 ) ;
}
return V_30 ;
}
static void F_270 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_605 * V_304 ;
struct V_133 * V_153 ;
struct V_247 * V_248 ;
F_9 ( L_16 , V_6 -> V_79 , V_224 ) ;
F_34 ( V_6 ) ;
V_304 = F_261 ( V_6 , V_606 ) ;
if ( ! V_304 )
goto V_292;
if ( V_304 -> V_607 ) {
T_2 V_260 = F_122 ( V_304 -> V_260 ) ;
V_248 = F_262 ( V_6 , V_260 ) ;
} else {
V_248 = NULL ;
}
V_153 = F_49 ( V_608 , V_6 , V_248 ) ;
if ( ! V_153 )
goto V_292;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_271 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_609 * V_148 = V_7 ;
struct V_600 V_18 ;
struct V_605 V_304 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
struct V_247 * V_248 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_86 ( & V_18 . V_366 . V_118 , & V_148 -> V_366 . V_118 ) ;
V_18 . V_366 . type = V_148 -> V_366 . type ;
if ( V_148 -> V_366 . type != V_367 )
return F_11 ( V_15 , V_6 -> V_55 , V_608 ,
V_274 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_608 ,
V_300 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_292;
}
if ( F_28 ( & V_148 -> V_366 . V_118 , V_72 ) ) {
V_248 = F_166 ( V_6 , V_265 ,
& V_148 -> V_366 . V_118 ) ;
if ( ! V_248 || V_248 -> V_231 != V_258 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_608 ,
V_388 ,
& V_18 , sizeof( V_18 ) ) ;
goto V_292;
}
} else {
V_248 = NULL ;
}
V_153 = F_102 ( V_15 , V_608 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_153 -> V_285 = F_267 ;
F_65 ( & V_145 , V_6 ) ;
memset ( & V_304 , 0 , sizeof( V_304 ) ) ;
F_54 ( & V_145 , V_606 , sizeof( V_304 ) , & V_304 ) ;
if ( V_248 ) {
F_266 ( V_248 ) ;
V_153 -> V_416 = F_192 ( V_248 ) ;
V_304 . V_260 = F_10 ( V_248 -> V_260 ) ;
V_304 . V_607 = 0x01 ;
F_54 ( & V_145 , V_606 , sizeof( V_304 ) , & V_304 ) ;
}
V_30 = F_66 ( & V_145 , F_270 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_272 ( struct V_5 * V_6 , T_8 * V_366 , T_1 type )
{
struct V_247 * V_248 ;
V_248 = F_166 ( V_6 , V_201 , V_366 ) ;
if ( ! V_248 )
return false ;
if ( V_248 -> V_396 != type )
return false ;
if ( V_248 -> V_231 != V_258 )
return false ;
return true ;
}
static int F_273 ( struct V_144 * V_145 , T_8 * V_366 ,
T_1 V_370 , T_1 V_610 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_611 * V_612 ;
V_612 = F_188 ( V_6 , V_366 , V_370 ) ;
if ( ! V_612 )
return - V_613 ;
if ( V_612 -> V_610 == V_610 )
return 0 ;
F_274 ( & V_612 -> V_614 ) ;
switch ( V_610 ) {
case V_615 :
case V_616 :
F_141 ( V_145 ) ;
break;
case V_617 :
F_275 ( & V_612 -> V_614 , & V_6 -> V_618 ) ;
F_141 ( V_145 ) ;
break;
case V_619 :
case V_620 :
if ( ! F_272 ( V_6 , V_366 , V_370 ) ) {
F_275 ( & V_612 -> V_614 , & V_6 -> V_621 ) ;
F_141 ( V_145 ) ;
}
break;
}
V_612 -> V_610 = V_610 ;
F_9 ( L_32 , V_366 , V_370 ,
V_610 ) ;
return 0 ;
}
static void F_276 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_8 * V_118 , T_1 type , T_1 V_614 )
{
struct V_622 V_241 ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = type ;
V_241 . V_614 = V_614 ;
F_7 ( V_623 , V_6 , & V_241 , sizeof( V_241 ) , V_15 ) ;
}
static void F_277 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_133 * V_153 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_624 , V_6 ) ;
if ( ! V_153 )
goto V_292;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_278 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_625 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
T_1 V_626 , V_370 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_165 ( V_148 -> V_366 . type ) ||
! F_28 ( & V_148 -> V_366 . V_118 , V_72 ) )
return F_11 ( V_15 , V_6 -> V_55 , V_624 ,
V_274 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
if ( V_148 -> V_614 != 0x00 && V_148 -> V_614 != 0x01 && V_148 -> V_614 != 0x02 )
return F_11 ( V_15 , V_6 -> V_55 , V_624 ,
V_274 ,
& V_148 -> V_366 , sizeof( V_148 -> V_366 ) ) ;
F_65 ( & V_145 , V_6 ) ;
F_34 ( V_6 ) ;
V_153 = F_102 ( V_15 , V_624 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_153 -> V_285 = F_115 ;
if ( V_148 -> V_366 . type == V_367 ) {
if ( V_148 -> V_614 != 0x01 ) {
V_30 = V_153 -> V_285 ( V_153 ,
V_274 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
V_30 = F_233 ( & V_6 -> V_322 , & V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type ) ;
if ( V_30 )
goto V_292;
F_120 ( & V_145 ) ;
goto V_627;
}
if ( V_148 -> V_366 . type == V_378 )
V_370 = V_379 ;
else
V_370 = V_380 ;
if ( V_148 -> V_614 == 0x02 )
V_626 = V_620 ;
else if ( V_148 -> V_614 == 0x01 )
V_626 = V_619 ;
else
V_626 = V_617 ;
if ( F_273 ( & V_145 , & V_148 -> V_366 . V_118 , V_370 ,
V_626 ) < 0 ) {
V_30 = V_153 -> V_285 ( V_153 , V_3 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
V_627:
F_276 ( V_15 , V_6 , & V_148 -> V_366 . V_118 , V_148 -> V_366 . type , V_148 -> V_614 ) ;
V_30 = F_66 ( & V_145 , F_277 ) ;
if ( V_30 < 0 ) {
if ( V_30 == - V_280 )
V_30 = V_153 -> V_285 ( V_153 , V_290 ) ;
F_112 ( V_153 ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_279 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_8 * V_118 , T_1 type )
{
struct V_628 V_241 ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = type ;
F_7 ( V_629 , V_6 , & V_241 , sizeof( V_241 ) , V_15 ) ;
}
static void F_280 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_133 * V_153 ;
F_9 ( L_8 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_630 , V_6 ) ;
if ( ! V_153 )
goto V_292;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_281 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_631 * V_148 = V_7 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_65 ( & V_145 , V_6 ) ;
F_34 ( V_6 ) ;
V_153 = F_102 ( V_15 , V_630 , V_6 , V_7 , V_8 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
V_153 -> V_285 = F_115 ;
if ( F_28 ( & V_148 -> V_366 . V_118 , V_72 ) ) {
struct V_611 * V_612 ;
T_1 V_370 ;
if ( ! F_165 ( V_148 -> V_366 . type ) ) {
V_30 = V_153 -> V_285 ( V_153 ,
V_274 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
if ( V_148 -> V_366 . type == V_367 ) {
V_30 = F_235 ( & V_6 -> V_322 ,
& V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type ) ;
if ( V_30 ) {
V_30 = V_153 -> V_285 ( V_153 ,
V_274 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
F_120 ( & V_145 ) ;
F_279 ( V_15 , V_6 , & V_148 -> V_366 . V_118 ,
V_148 -> V_366 . type ) ;
goto V_421;
}
if ( V_148 -> V_366 . type == V_378 )
V_370 = V_379 ;
else
V_370 = V_380 ;
V_612 = F_282 ( V_6 , & V_148 -> V_366 . V_118 ,
V_370 ) ;
if ( ! V_612 ) {
V_30 = V_153 -> V_285 ( V_153 ,
V_274 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
if ( V_612 -> V_610 == V_615 ) {
V_30 = V_153 -> V_285 ( V_153 ,
V_274 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
F_108 ( & V_612 -> V_614 ) ;
F_108 ( & V_612 -> V_284 ) ;
F_16 ( V_612 ) ;
F_141 ( & V_145 ) ;
F_279 ( V_15 , V_6 , & V_148 -> V_366 . V_118 , V_148 -> V_366 . type ) ;
} else {
struct V_611 * V_632 , * V_350 ;
struct V_633 * V_543 , * V_634 ;
if ( V_148 -> V_366 . type ) {
V_30 = V_153 -> V_285 ( V_153 ,
V_274 ) ;
F_112 ( V_153 ) ;
goto V_292;
}
F_155 (b, btmp, &hdev->whitelist, list) {
F_279 ( V_15 , V_6 , & V_543 -> V_118 , V_543 -> V_635 ) ;
F_108 ( & V_543 -> V_284 ) ;
F_16 ( V_543 ) ;
}
F_120 ( & V_145 ) ;
F_155 (p, tmp, &hdev->le_conn_params, list) {
if ( V_632 -> V_610 == V_615 )
continue;
F_279 ( V_15 , V_6 , & V_632 -> V_366 , V_632 -> V_370 ) ;
F_108 ( & V_632 -> V_614 ) ;
F_108 ( & V_632 -> V_284 ) ;
F_16 ( V_632 ) ;
}
F_9 ( L_33 ) ;
F_141 ( & V_145 ) ;
}
V_421:
V_30 = F_66 ( & V_145 , F_280 ) ;
if ( V_30 < 0 ) {
if ( V_30 == - V_280 )
V_30 = V_153 -> V_285 ( V_153 , V_290 ) ;
F_112 ( V_153 ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_283 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_636 * V_148 = V_7 ;
const T_2 V_637 = ( ( V_358 - sizeof( * V_148 ) ) /
sizeof( struct V_638 ) ) ;
T_2 V_639 , V_361 ;
int V_29 ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_640 ,
V_288 ) ;
V_639 = F_122 ( V_148 -> V_639 ) ;
if ( V_639 > V_637 ) {
F_160 ( L_34 ,
V_639 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_640 ,
V_274 ) ;
}
V_361 = sizeof( * V_148 ) + V_639 *
sizeof( struct V_638 ) ;
if ( V_361 != V_8 ) {
F_160 ( L_35 ,
V_361 , V_8 ) ;
return F_101 ( V_15 , V_6 -> V_55 , V_640 ,
V_274 ) ;
}
F_9 ( L_36 , V_6 -> V_79 , V_639 ) ;
F_34 ( V_6 ) ;
F_284 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_639 ; V_29 ++ ) {
struct V_638 * V_156 = & V_148 -> V_612 [ V_29 ] ;
struct V_611 * V_641 ;
T_2 V_642 , V_643 , V_644 , V_245 ;
T_1 V_370 ;
F_9 ( L_37 , & V_156 -> V_366 . V_118 ,
V_156 -> V_366 . type ) ;
if ( V_156 -> V_366 . type == V_378 ) {
V_370 = V_379 ;
} else if ( V_156 -> V_366 . type == V_391 ) {
V_370 = V_380 ;
} else {
F_160 ( L_38 ) ;
continue;
}
V_642 = F_285 ( V_156 -> V_203 ) ;
V_643 = F_285 ( V_156 -> V_205 ) ;
V_644 = F_285 ( V_156 -> V_644 ) ;
V_245 = F_285 ( V_156 -> V_245 ) ;
F_9 ( L_39 ,
V_642 , V_643 , V_644 , V_245 ) ;
if ( F_286 ( V_642 , V_643 , V_644 , V_245 ) < 0 ) {
F_160 ( L_38 ) ;
continue;
}
V_641 = F_188 ( V_6 , & V_156 -> V_366 . V_118 ,
V_370 ) ;
if ( ! V_641 ) {
F_160 ( L_40 ) ;
continue;
}
V_641 -> V_645 = V_642 ;
V_641 -> V_646 = V_643 ;
V_641 -> V_647 = V_644 ;
V_641 -> V_648 = V_245 ;
}
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_640 , 0 ,
NULL , 0 ) ;
}
static int F_287 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_649 * V_148 = V_7 ;
bool V_291 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( F_42 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_650 ,
V_289 ) ;
if ( V_148 -> V_651 != 0x00 && V_148 -> V_651 != 0x01 )
return F_101 ( V_15 , V_6 -> V_55 , V_650 ,
V_274 ) ;
if ( ! F_22 ( V_68 , & V_6 -> V_53 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_650 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( V_148 -> V_651 )
V_291 = ! F_83 ( V_6 , V_69 ) ;
else
V_291 = F_79 ( V_6 , V_69 ) ;
V_30 = F_32 ( V_15 , V_650 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( ! V_291 )
goto V_292;
V_30 = F_31 ( V_6 , V_15 ) ;
if ( F_20 ( V_6 , V_47 ) == F_27 ( V_6 ) ) {
F_288 ( V_6 ) ;
if ( F_289 ( V_6 , V_47 ) ) {
F_81 ( V_6 , V_50 ) ;
F_81 ( V_6 , V_277 ) ;
F_91 ( V_6 -> V_226 , & V_6 -> V_278 ) ;
} else {
F_168 ( V_652 , & V_6 -> V_162 ) ;
F_290 ( V_6 ) ;
}
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_291 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_653 * V_148 = V_7 ;
bool V_291 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( F_42 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_654 ,
V_289 ) ;
if ( ! F_28 ( & V_148 -> V_118 , V_72 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_654 ,
V_274 ) ;
if ( ! V_6 -> V_81 )
return F_101 ( V_15 , V_6 -> V_55 , V_654 ,
V_288 ) ;
F_34 ( V_6 ) ;
V_291 = ! ! F_28 ( & V_6 -> V_71 , & V_148 -> V_118 ) ;
F_86 ( & V_6 -> V_71 , & V_148 -> V_118 ) ;
V_30 = F_32 ( V_15 , V_654 , V_6 ) ;
if ( V_30 < 0 )
goto V_292;
if ( ! V_291 )
goto V_292;
if ( F_20 ( V_6 , V_47 ) )
V_30 = F_31 ( V_6 , V_15 ) ;
if ( F_27 ( V_6 ) ) {
F_288 ( V_6 ) ;
F_75 ( V_6 , V_47 ) ;
F_81 ( V_6 , V_50 ) ;
F_81 ( V_6 , V_277 ) ;
F_91 ( V_6 -> V_226 , & V_6 -> V_278 ) ;
}
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static inline T_2 F_292 ( T_1 * V_188 , T_2 V_655 , T_1 type , T_1 * V_7 ,
T_1 V_16 )
{
V_188 [ V_655 ++ ] = sizeof( type ) + V_16 ;
V_188 [ V_655 ++ ] = type ;
memcpy ( & V_188 [ V_655 ] , V_7 , V_16 ) ;
V_655 += V_16 ;
return V_655 ;
}
static void F_293 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 , struct V_458 * V_459 )
{
const struct V_656 * V_520 ;
struct V_657 * V_461 ;
T_1 * V_658 , * V_659 , * V_660 , * V_661 ;
struct V_133 * V_153 ;
T_2 V_655 ;
int V_30 ;
F_9 ( L_16 , V_6 -> V_79 , V_224 ) ;
V_153 = F_47 ( V_662 , V_6 ) ;
if ( ! V_153 )
return;
V_520 = V_153 -> V_156 ;
if ( V_224 ) {
V_224 = F_1 ( V_224 ) ;
V_655 = 0 ;
V_658 = NULL ;
V_659 = NULL ;
V_660 = NULL ;
V_661 = NULL ;
} else if ( V_37 == V_463 ) {
struct V_464 * V_18 ;
if ( V_459 -> V_8 != sizeof( * V_18 ) ) {
V_224 = V_3 ;
V_655 = 0 ;
} else {
V_224 = V_290 ;
V_18 = ( void * ) V_459 -> V_7 ;
V_655 = 5 + 18 + 18 ;
V_658 = V_18 -> V_466 ;
V_659 = V_18 -> rand ;
V_660 = NULL ;
V_661 = NULL ;
}
} else {
struct V_470 * V_18 ;
if ( V_459 -> V_8 != sizeof( * V_18 ) ) {
V_224 = V_3 ;
V_655 = 0 ;
} else {
V_224 = V_290 ;
V_18 = ( void * ) V_459 -> V_7 ;
if ( F_20 ( V_6 , V_551 ) ) {
V_655 = 5 + 18 + 18 ;
V_658 = NULL ;
V_659 = NULL ;
} else {
V_655 = 5 + 18 + 18 + 18 + 18 ;
V_658 = V_18 -> V_465 ;
V_659 = V_18 -> V_467 ;
}
V_660 = V_18 -> V_468 ;
V_661 = V_18 -> V_469 ;
}
}
V_461 = F_14 ( sizeof( * V_461 ) + V_655 , V_35 ) ;
if ( ! V_461 )
goto V_439;
if ( V_224 )
goto V_663;
V_655 = F_292 ( V_461 -> V_188 , 0 , V_664 ,
V_6 -> V_194 , 3 ) ;
if ( V_658 && V_659 ) {
V_655 = F_292 ( V_461 -> V_188 , V_655 ,
V_665 , V_658 , 16 ) ;
V_655 = F_292 ( V_461 -> V_188 , V_655 ,
V_666 , V_659 , 16 ) ;
}
if ( V_660 && V_661 ) {
V_655 = F_292 ( V_461 -> V_188 , V_655 ,
V_667 , V_660 , 16 ) ;
V_655 = F_292 ( V_461 -> V_188 , V_655 ,
V_668 , V_661 , 16 ) ;
}
V_663:
V_461 -> type = V_520 -> type ;
V_461 -> V_655 = F_10 ( V_655 ) ;
V_30 = F_11 ( V_153 -> V_15 , V_6 -> V_55 ,
V_662 , V_224 ,
V_461 , sizeof( * V_461 ) + V_655 ) ;
if ( V_30 < 0 || V_224 )
goto V_439;
F_25 ( V_153 -> V_15 , V_669 ) ;
V_30 = F_5 ( V_670 , V_6 ,
V_461 , sizeof( * V_461 ) + V_655 ,
V_669 , V_153 -> V_15 ) ;
V_439:
F_16 ( V_461 ) ;
F_112 ( V_153 ) ;
}
static int F_294 ( struct V_5 * V_6 , struct V_11 * V_15 ,
struct V_656 * V_148 )
{
struct V_133 * V_153 ;
struct V_144 V_145 ;
int V_30 ;
V_153 = F_102 ( V_15 , V_662 , V_6 ,
V_148 , sizeof( * V_148 ) ) ;
if ( ! V_153 )
return - V_36 ;
F_65 ( & V_145 , V_6 ) ;
if ( F_207 ( V_6 ) )
F_54 ( & V_145 , V_471 , 0 , NULL ) ;
else
F_54 ( & V_145 , V_463 , 0 , NULL ) ;
V_30 = F_208 ( & V_145 , F_293 ) ;
if ( V_30 < 0 ) {
F_112 ( V_153 ) ;
return V_30 ;
}
return 0 ;
}
static int F_295 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_656 * V_148 = V_7 ;
struct V_657 * V_18 ;
T_3 V_42 ;
T_2 V_655 ;
T_1 V_224 , V_162 , V_671 , V_366 [ 7 ] , V_466 [ 16 ] , rand [ 16 ] ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( F_42 ( V_6 ) ) {
switch ( V_148 -> type ) {
case F_296 ( V_367 ) :
V_224 = F_116 ( V_6 ) ;
if ( V_224 )
V_655 = 0 ;
else
V_655 = 5 ;
break;
case ( F_296 ( V_378 ) | F_296 ( V_391 ) ) :
V_224 = F_117 ( V_6 ) ;
if ( V_224 )
V_655 = 0 ;
else
V_655 = 9 + 3 + 18 + 18 + 3 ;
break;
default:
V_224 = V_274 ;
V_655 = 0 ;
break;
}
} else {
V_224 = V_300 ;
V_655 = 0 ;
}
V_42 = sizeof( * V_18 ) + V_655 ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 )
return - V_36 ;
if ( V_224 )
goto V_421;
F_34 ( V_6 ) ;
V_655 = 0 ;
switch ( V_148 -> type ) {
case F_296 ( V_367 ) :
if ( F_20 ( V_6 , V_111 ) ) {
V_30 = F_294 ( V_6 , V_15 , V_148 ) ;
F_35 ( V_6 ) ;
if ( ! V_30 )
goto V_439;
V_224 = V_3 ;
goto V_421;
} else {
V_655 = F_292 ( V_18 -> V_188 , V_655 ,
V_664 ,
V_6 -> V_194 , 3 ) ;
}
break;
case ( F_296 ( V_378 ) | F_296 ( V_391 ) ) :
if ( F_20 ( V_6 , V_114 ) &&
F_297 ( V_6 , V_466 , rand ) < 0 ) {
F_35 ( V_6 ) ;
V_224 = V_3 ;
goto V_421;
}
if ( F_20 ( V_6 , V_116 ) ) {
F_35 ( V_6 ) ;
V_224 = V_289 ;
goto V_421;
}
if ( F_20 ( V_6 , V_117 ) ||
! F_28 ( & V_6 -> V_118 , V_72 ) ||
( ! F_20 ( V_6 , V_108 ) &&
F_28 ( & V_6 -> V_119 , V_72 ) ) ) {
memcpy ( V_366 , & V_6 -> V_119 , 6 ) ;
V_366 [ 6 ] = 0x01 ;
} else {
memcpy ( V_366 , & V_6 -> V_118 , 6 ) ;
V_366 [ 6 ] = 0x00 ;
}
V_655 = F_292 ( V_18 -> V_188 , V_655 , V_672 ,
V_366 , sizeof( V_366 ) ) ;
if ( F_20 ( V_6 , V_113 ) )
V_671 = 0x02 ;
else
V_671 = 0x01 ;
V_655 = F_292 ( V_18 -> V_188 , V_655 , V_673 ,
& V_671 , sizeof( V_671 ) ) ;
if ( F_20 ( V_6 , V_114 ) ) {
V_655 = F_292 ( V_18 -> V_188 , V_655 ,
V_674 ,
V_466 , sizeof( V_466 ) ) ;
V_655 = F_292 ( V_18 -> V_188 , V_655 ,
V_675 ,
rand , sizeof( rand ) ) ;
}
V_162 = F_56 ( V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) )
V_162 |= V_170 ;
V_655 = F_292 ( V_18 -> V_188 , V_655 , V_171 ,
& V_162 , sizeof( V_162 ) ) ;
break;
}
F_35 ( V_6 ) ;
F_25 ( V_15 , V_669 ) ;
V_224 = V_290 ;
V_421:
V_18 -> type = V_148 -> type ;
V_18 -> V_655 = F_10 ( V_655 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_662 ,
V_224 , V_18 , sizeof( * V_18 ) + V_655 ) ;
if ( V_30 < 0 || V_224 )
goto V_439;
V_30 = F_5 ( V_670 , V_6 ,
V_18 , sizeof( * V_18 ) + V_655 ,
V_669 , V_15 ) ;
V_439:
F_16 ( V_18 ) ;
return V_30 ;
}
static T_6 F_298 ( struct V_5 * V_6 )
{
T_6 V_162 = 0 ;
V_162 |= V_166 ;
V_162 |= V_168 ;
V_162 |= V_169 ;
V_162 |= V_164 ;
if ( V_6 -> V_174 != V_175 )
V_162 |= V_163 ;
return V_162 ;
}
static int F_299 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_676 * V_18 ;
T_3 V_42 ;
int V_30 ;
bool V_146 ;
T_6 V_677 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_678 ,
V_289 ) ;
F_34 ( V_6 ) ;
V_42 = sizeof( * V_18 ) ;
V_146 = F_20 ( V_6 , V_152 ) ;
if ( V_146 )
V_42 ++ ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 ) {
F_35 ( V_6 ) ;
return - V_36 ;
}
V_677 = F_298 ( V_6 ) ;
V_18 -> V_677 = F_30 ( V_677 ) ;
V_18 -> V_679 = V_138 ;
V_18 -> V_680 = V_138 ;
V_18 -> V_681 = 1 ;
if ( V_146 ) {
V_18 -> V_682 = 1 ;
V_18 -> V_146 [ 0 ] = 1 ;
} else {
V_18 -> V_682 = 0 ;
}
F_35 ( V_6 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_678 ,
V_290 , V_18 , V_42 ) ;
F_16 ( V_18 ) ;
return V_30 ;
}
static bool F_300 ( struct V_5 * V_6 , T_6 V_683 , T_1 * V_7 ,
T_1 V_8 , bool V_684 )
{
T_1 V_137 = V_138 ;
int V_29 , V_685 ;
bool V_686 = false ;
bool V_687 = false ;
T_6 V_688 = V_168 | V_169 |
V_164 ;
if ( V_684 && ( V_683 & V_688 ) ) {
V_686 = true ;
V_137 -= 3 ;
}
if ( V_684 && ( V_683 & V_163 ) ) {
V_687 = true ;
V_137 -= 3 ;
}
if ( V_8 > V_137 )
return false ;
for ( V_29 = 0 , V_685 = 0 ; V_29 < V_8 ; V_29 += ( V_685 + 1 ) ) {
V_685 = V_7 [ V_29 ] ;
if ( V_686 && V_7 [ V_29 + 1 ] == V_171 )
return false ;
if ( V_687 && V_7 [ V_29 + 1 ] == V_176 )
return false ;
if ( V_29 + V_685 >= V_8 )
return false ;
}
return true ;
}
static void F_301 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_133 * V_153 ;
struct V_689 V_18 ;
F_9 ( L_19 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_690 , V_6 ) ;
if ( V_224 ) {
F_75 ( V_6 , V_152 ) ;
memset ( & V_6 -> V_141 , 0 , sizeof( V_6 -> V_141 ) ) ;
F_96 ( V_153 ? V_153 -> V_15 : NULL , V_6 , 1 ) ;
}
if ( ! V_153 )
goto V_292;
V_18 . V_146 = 0x01 ;
if ( V_224 )
F_101 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 ,
F_1 ( V_224 ) ) ;
else
F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 ,
F_1 ( V_224 ) , & V_18 , sizeof( V_18 ) ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static void F_302 ( struct V_214 * V_215 )
{
struct V_5 * V_6 = F_78 ( V_215 , struct V_5 ,
V_141 . V_246 . V_215 ) ;
V_6 -> V_141 . V_245 = 0 ;
F_34 ( V_6 ) ;
F_97 ( V_6 ) ;
F_35 ( V_6 ) ;
}
static int F_303 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_691 * V_148 = V_7 ;
struct V_689 V_18 ;
T_6 V_162 ;
T_6 V_677 ;
T_1 V_224 ;
T_2 V_245 ;
int V_30 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
V_224 = F_117 ( V_6 ) ;
if ( V_224 )
return F_101 ( V_15 , V_6 -> V_55 , V_690 ,
V_224 ) ;
V_162 = F_304 ( V_148 -> V_162 ) ;
V_245 = F_122 ( V_148 -> V_245 ) ;
V_677 = F_298 ( V_6 ) ;
if ( V_148 -> V_146 != 0x01 || ( V_162 & ~ V_677 ) )
return F_101 ( V_15 , V_6 -> V_55 , V_690 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( V_245 && ! F_42 ( V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_690 ,
V_289 ) ;
goto V_292;
}
if ( F_47 ( V_690 , V_6 ) ||
F_47 ( V_692 , V_6 ) ||
F_47 ( V_334 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_690 ,
V_275 ) ;
goto V_292;
}
if ( ! F_300 ( V_6 , V_162 , V_148 -> V_7 , V_148 -> V_173 , true ) ||
! F_300 ( V_6 , V_162 , V_148 -> V_7 + V_148 -> V_173 ,
V_148 -> V_143 , false ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_690 ,
V_274 ) ;
goto V_292;
}
F_84 ( & V_6 -> V_141 . V_246 , F_302 ) ;
V_6 -> V_141 . V_162 = V_162 ;
V_6 -> V_141 . V_173 = V_148 -> V_173 ;
V_6 -> V_141 . V_143 = V_148 -> V_143 ;
if ( V_148 -> V_173 )
memcpy ( V_6 -> V_141 . V_172 , V_148 -> V_7 , V_148 -> V_173 ) ;
if ( V_148 -> V_143 )
memcpy ( V_6 -> V_141 . V_142 ,
V_148 -> V_7 + V_148 -> V_173 , V_148 -> V_143 ) ;
if ( V_6 -> V_141 . V_245 )
F_90 ( & V_6 -> V_141 . V_246 ) ;
V_6 -> V_141 . V_245 = V_245 ;
if ( V_245 )
F_104 ( V_6 -> V_297 ,
& V_6 -> V_141 . V_246 ,
F_119 ( V_245 * 1000 ) ) ;
if ( ! F_83 ( V_6 , V_152 ) )
F_95 ( V_15 , V_6 , 1 ) ;
if ( ! F_42 ( V_6 ) ||
F_20 ( V_6 , V_113 ) ) {
V_18 . V_146 = 0x01 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_690 ,
V_290 , & V_18 , sizeof( V_18 ) ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_690 , V_6 , V_7 ,
V_16 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
F_63 ( & V_145 ) ;
F_55 ( & V_145 ) ;
F_73 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_301 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_305 ( struct V_5 * V_6 , T_1 V_224 ,
T_2 V_37 )
{
struct V_133 * V_153 ;
struct V_693 V_18 ;
F_9 ( L_19 , V_224 ) ;
F_34 ( V_6 ) ;
V_153 = F_47 ( V_692 , V_6 ) ;
if ( ! V_153 )
goto V_292;
V_18 . V_146 = 1 ;
F_11 ( V_153 -> V_15 , V_153 -> V_54 , V_153 -> V_37 , V_290 ,
& V_18 , sizeof( V_18 ) ) ;
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
}
static int F_306 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_694 * V_148 = V_7 ;
struct V_693 V_18 ;
int V_30 ;
struct V_133 * V_153 ;
struct V_144 V_145 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( V_148 -> V_146 > 1 )
return F_101 ( V_15 , V_6 -> V_55 , V_692 ,
V_274 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_690 , V_6 ) ||
F_47 ( V_692 , V_6 ) ||
F_47 ( V_334 , V_6 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_692 ,
V_275 ) ;
goto V_292;
}
if ( ! F_20 ( V_6 , V_152 ) ) {
V_30 = F_101 ( V_15 , V_6 -> V_55 , V_692 ,
V_274 ) ;
goto V_292;
}
if ( V_6 -> V_141 . V_245 )
F_90 ( & V_6 -> V_141 . V_246 ) ;
memset ( & V_6 -> V_141 , 0 , sizeof( V_6 -> V_141 ) ) ;
F_96 ( V_15 , V_6 , 1 ) ;
F_75 ( V_6 , V_152 ) ;
if ( ! F_42 ( V_6 ) ||
F_20 ( V_6 , V_113 ) ) {
V_18 . V_146 = 1 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_692 ,
V_290 , & V_18 , sizeof( V_18 ) ) ;
goto V_292;
}
V_153 = F_102 ( V_15 , V_692 , V_6 , V_7 ,
V_16 ) ;
if ( ! V_153 ) {
V_30 = - V_36 ;
goto V_292;
}
F_65 ( & V_145 , V_6 ) ;
F_72 ( & V_145 ) ;
V_30 = F_66 ( & V_145 , F_305 ) ;
if ( V_30 < 0 )
F_112 ( V_153 ) ;
V_292:
F_35 ( V_6 ) ;
return V_30 ;
}
void F_290 ( struct V_5 * V_6 )
{
struct V_695 V_241 ;
if ( F_22 ( V_52 , & V_6 -> V_53 ) )
return;
switch ( V_6 -> V_45 ) {
case V_46 :
if ( F_20 ( V_6 , V_47 ) ) {
F_3 ( V_696 , V_6 ,
NULL , 0 , V_66 ) ;
V_241 . type = 0x01 ;
} else {
F_3 ( V_697 , V_6 , NULL , 0 ,
V_65 ) ;
V_241 . type = 0x00 ;
}
break;
case V_61 :
V_241 . type = 0x02 ;
break;
default:
return;
}
V_241 . V_63 = V_6 -> V_63 ;
F_3 ( V_698 , V_6 , & V_241 , sizeof( V_241 ) ,
V_64 ) ;
}
void F_288 ( struct V_5 * V_6 )
{
struct V_695 V_241 ;
T_1 V_224 = V_699 ;
if ( F_22 ( V_52 , & V_6 -> V_53 ) )
return;
switch ( V_6 -> V_45 ) {
case V_46 :
F_139 ( 0 , V_6 , F_113 , & V_224 ) ;
if ( F_20 ( V_6 , V_47 ) ) {
F_3 ( V_700 , V_6 ,
NULL , 0 , V_66 ) ;
V_241 . type = 0x01 ;
} else {
F_3 ( V_701 , V_6 , NULL , 0 ,
V_65 ) ;
V_241 . type = 0x00 ;
}
break;
case V_61 :
V_241 . type = 0x02 ;
break;
default:
return;
}
V_241 . V_63 = V_6 -> V_63 ;
F_3 ( V_702 , V_6 , & V_241 , sizeof( V_241 ) ,
V_64 ) ;
}
static void F_307 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_611 * V_632 ;
F_19 (p, &hdev->le_conn_params, list) {
F_274 ( & V_632 -> V_614 ) ;
switch ( V_632 -> V_610 ) {
case V_619 :
case V_620 :
F_275 ( & V_632 -> V_614 , & V_6 -> V_621 ) ;
break;
case V_617 :
F_275 ( & V_632 -> V_614 , & V_6 -> V_618 ) ;
break;
default:
break;
}
}
F_141 ( V_145 ) ;
}
static void F_308 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
struct V_282 V_283 = { NULL , V_6 } ;
F_9 ( L_8 , V_224 ) ;
if ( ! V_224 ) {
F_309 ( V_6 ) ;
}
F_34 ( V_6 ) ;
F_139 ( V_273 , V_6 , F_107 , & V_283 ) ;
F_105 ( V_6 , V_283 . V_15 ) ;
F_35 ( V_6 ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
}
static int F_310 ( struct V_5 * V_6 )
{
struct V_144 V_145 ;
T_1 V_703 ;
F_65 ( & V_145 , V_6 ) ;
if ( F_20 ( V_6 , V_111 ) &&
! F_311 ( V_6 ) ) {
T_1 V_555 = 0x01 ;
F_54 ( & V_145 , V_332 , sizeof( V_555 ) , & V_555 ) ;
if ( F_207 ( V_6 ) && ! F_312 ( V_6 ) ) {
T_1 V_704 = 0x01 ;
F_54 ( & V_145 , V_552 ,
sizeof( V_704 ) , & V_704 ) ;
}
}
if ( F_20 ( V_6 , V_109 ) &&
F_37 ( V_6 ) ) {
struct V_335 V_148 ;
V_148 . V_338 = 0x01 ;
V_148 . V_339 = 0x00 ;
if ( V_148 . V_338 != F_143 ( V_6 ) ||
V_148 . V_339 != F_313 ( V_6 ) )
F_54 ( & V_145 , V_340 ,
sizeof( V_148 ) , & V_148 ) ;
}
if ( F_40 ( V_6 ) ) {
if ( F_20 ( V_6 , V_109 ) ) {
F_63 ( & V_145 ) ;
F_55 ( & V_145 ) ;
}
if ( F_20 ( V_6 , V_113 ) ||
F_20 ( V_6 , V_152 ) )
F_73 ( & V_145 ) ;
F_307 ( & V_145 ) ;
}
V_703 = F_20 ( V_6 , V_110 ) ;
if ( V_703 != F_22 ( V_327 , & V_6 -> V_162 ) )
F_54 ( & V_145 , V_328 ,
sizeof( V_703 ) , & V_703 ) ;
if ( F_37 ( V_6 ) ) {
if ( F_20 ( V_6 , V_105 ) )
F_125 ( & V_145 , true ) ;
else
F_125 ( & V_145 , false ) ;
F_120 ( & V_145 ) ;
F_71 ( & V_145 ) ;
F_202 ( & V_145 ) ;
F_68 ( & V_145 ) ;
}
return F_66 ( & V_145 , F_308 ) ;
}
int F_103 ( struct V_5 * V_6 , T_1 V_705 )
{
struct V_282 V_283 = { NULL , V_6 } ;
T_1 V_224 , V_706 [] = { 0 , 0 , 0 } ;
int V_30 ;
if ( ! F_20 ( V_6 , V_218 ) )
return 0 ;
if ( V_705 ) {
if ( F_310 ( V_6 ) == 0 )
return 0 ;
F_139 ( V_273 , V_6 , F_107 ,
& V_283 ) ;
goto F_105;
}
F_139 ( V_273 , V_6 , F_107 , & V_283 ) ;
if ( F_20 ( V_6 , V_707 ) )
V_224 = V_699 ;
else
V_224 = V_300 ;
F_139 ( 0 , V_6 , F_113 , & V_224 ) ;
if ( memcmp ( V_6 -> V_194 , V_706 , sizeof( V_706 ) ) != 0 )
F_6 ( V_708 , V_6 ,
V_706 , sizeof( V_706 ) , NULL ) ;
F_105:
V_30 = F_105 ( V_6 , V_283 . V_15 ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
return V_30 ;
}
void F_314 ( struct V_5 * V_6 , int V_30 )
{
struct V_133 * V_153 ;
T_1 V_224 ;
V_153 = F_47 ( V_273 , V_6 ) ;
if ( ! V_153 )
return;
if ( V_30 == - V_709 )
V_224 = V_710 ;
else
V_224 = V_3 ;
F_101 ( V_153 -> V_15 , V_6 -> V_55 , V_273 , V_224 ) ;
F_112 ( V_153 ) ;
}
void F_315 ( struct V_5 * V_6 )
{
struct V_144 V_145 ;
F_34 ( V_6 ) ;
F_75 ( V_6 , V_160 ) ;
F_75 ( V_6 , V_106 ) ;
F_65 ( & V_145 , V_6 ) ;
if ( F_20 ( V_6 , V_108 ) ) {
T_1 V_252 = V_302 ;
F_54 ( & V_145 , V_253 ,
sizeof( V_252 ) , & V_252 ) ;
}
F_71 ( & V_145 ) ;
if ( F_20 ( V_6 , V_113 ) )
F_63 ( & V_145 ) ;
F_66 ( & V_145 , NULL ) ;
V_6 -> V_295 = 0 ;
F_105 ( V_6 , NULL ) ;
F_35 ( V_6 ) ;
}
void F_316 ( struct V_5 * V_6 , struct V_711 * V_364 ,
bool V_712 )
{
struct V_713 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_714 = V_712 ;
F_86 ( & V_241 . V_364 . V_366 . V_118 , & V_364 -> V_118 ) ;
V_241 . V_364 . V_366 . type = V_367 ;
V_241 . V_364 . type = V_364 -> type ;
memcpy ( V_241 . V_364 . V_157 , V_364 -> V_157 , V_715 ) ;
V_241 . V_364 . V_369 = V_364 -> V_369 ;
F_7 ( V_716 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
static T_1 F_317 ( struct V_717 * V_718 )
{
switch ( V_718 -> type ) {
case V_574 :
case V_575 :
if ( V_718 -> V_572 )
return V_576 ;
return V_573 ;
case V_578 :
if ( V_718 -> V_572 )
return V_579 ;
return V_577 ;
case V_581 :
return V_580 ;
}
return V_573 ;
}
void F_318 ( struct V_5 * V_6 , struct V_717 * V_364 , bool V_712 )
{
struct V_719 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
if ( V_364 -> V_635 == V_380 &&
( V_364 -> V_118 . V_543 [ 5 ] & 0xc0 ) != 0xc0 )
V_241 . V_714 = 0x00 ;
else
V_241 . V_714 = V_712 ;
F_86 ( & V_241 . V_364 . V_366 . V_118 , & V_364 -> V_118 ) ;
V_241 . V_364 . V_366 . type = F_172 ( V_201 , V_364 -> V_635 ) ;
V_241 . V_364 . type = F_317 ( V_364 ) ;
V_241 . V_364 . V_582 = V_364 -> V_582 ;
V_241 . V_364 . V_583 = V_364 -> V_583 ;
V_241 . V_364 . rand = V_364 -> rand ;
if ( V_364 -> type == V_574 )
V_241 . V_364 . V_569 = 1 ;
memcpy ( V_241 . V_364 . V_157 , V_364 -> V_157 , sizeof( V_364 -> V_157 ) ) ;
F_7 ( V_720 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_319 ( struct V_5 * V_6 , struct V_721 * V_561 )
{
struct V_722 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
if ( F_28 ( & V_561 -> V_723 , V_72 ) )
V_241 . V_714 = 0x01 ;
else
V_241 . V_714 = 0x00 ;
F_86 ( & V_241 . V_723 , & V_561 -> V_723 ) ;
F_86 ( & V_241 . V_561 . V_366 . V_118 , & V_561 -> V_118 ) ;
V_241 . V_561 . V_366 . type = F_172 ( V_201 , V_561 -> V_370 ) ;
memcpy ( V_241 . V_561 . V_157 , V_561 -> V_157 , sizeof( V_561 -> V_157 ) ) ;
F_7 ( V_724 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_320 ( struct V_5 * V_6 , struct V_725 * V_726 ,
bool V_712 )
{
struct V_727 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
if ( V_726 -> V_635 == V_380 &&
( V_726 -> V_118 . V_543 [ 5 ] & 0xc0 ) != 0xc0 )
V_241 . V_714 = 0x00 ;
else
V_241 . V_714 = V_712 ;
F_86 ( & V_241 . V_364 . V_366 . V_118 , & V_726 -> V_118 ) ;
V_241 . V_364 . V_366 . type = F_172 ( V_201 , V_726 -> V_635 ) ;
V_241 . V_364 . type = V_726 -> type ;
memcpy ( V_241 . V_364 . V_157 , V_726 -> V_157 , sizeof( V_726 -> V_157 ) ) ;
F_7 ( V_728 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_321 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_635 , T_1 V_714 , T_2 V_203 ,
T_2 V_205 , T_2 V_644 , T_2 V_245 )
{
struct V_729 V_241 ;
if ( ! F_322 ( V_118 , V_635 ) )
return;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = F_172 ( V_201 , V_635 ) ;
V_241 . V_714 = V_714 ;
V_241 . V_203 = F_10 ( V_203 ) ;
V_241 . V_205 = F_10 ( V_205 ) ;
V_241 . V_644 = F_10 ( V_644 ) ;
V_241 . V_245 = F_10 ( V_245 ) ;
F_7 ( V_730 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_323 ( struct V_5 * V_6 , struct V_247 * V_248 ,
T_6 V_162 , T_1 * V_79 , T_1 V_135 )
{
char V_731 [ 512 ] ;
struct V_732 * V_241 = ( void * ) V_731 ;
T_2 V_655 = 0 ;
F_86 ( & V_241 -> V_366 . V_118 , & V_248 -> V_267 ) ;
V_241 -> V_366 . type = F_172 ( V_248 -> type , V_248 -> V_396 ) ;
V_241 -> V_162 = F_324 ( V_162 ) ;
if ( V_248 -> V_733 > 0 ) {
memcpy ( & V_241 -> V_188 [ V_655 ] ,
V_248 -> V_734 , V_248 -> V_733 ) ;
V_655 = V_248 -> V_733 ;
} else {
if ( V_135 > 0 )
V_655 = F_292 ( V_241 -> V_188 , 0 , V_140 ,
V_79 , V_135 ) ;
if ( memcmp ( V_248 -> V_194 , L_41 , 3 ) != 0 )
V_655 = F_292 ( V_241 -> V_188 , V_655 ,
V_664 ,
V_248 -> V_194 , 3 ) ;
}
V_241 -> V_655 = F_10 ( V_655 ) ;
F_7 ( V_735 , V_6 , V_731 ,
sizeof( * V_241 ) + V_655 , NULL ) ;
}
static void F_325 ( struct V_133 * V_153 , void * V_7 )
{
struct V_11 * * V_15 = V_7 ;
V_153 -> V_285 ( V_153 , 0 ) ;
* V_15 = V_153 -> V_15 ;
F_109 ( * V_15 ) ;
F_112 ( V_153 ) ;
}
static void F_326 ( struct V_133 * V_153 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_373 * V_148 = V_153 -> V_156 ;
F_163 ( V_6 , & V_148 -> V_366 . V_118 , V_148 -> V_366 . type , V_153 -> V_15 ) ;
V_153 -> V_285 ( V_153 , 0 ) ;
F_112 ( V_153 ) ;
}
bool F_327 ( struct V_5 * V_6 )
{
struct V_133 * V_153 ;
struct V_155 * V_148 ;
V_153 = F_47 ( V_273 , V_6 ) ;
if ( ! V_153 )
return false ;
V_148 = V_153 -> V_156 ;
if ( ! V_148 -> V_157 )
return true ;
return false ;
}
void F_328 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_261 ,
bool V_736 )
{
struct V_737 V_241 ;
struct V_11 * V_15 = NULL ;
if ( F_327 ( V_6 ) && F_89 ( V_6 ) == 1 ) {
F_90 ( & V_6 -> V_225 ) ;
F_91 ( V_6 -> V_226 , & V_6 -> V_225 . V_215 ) ;
}
if ( ! V_736 )
return;
if ( V_390 != V_265 && V_390 != V_201 )
return;
F_139 ( V_384 , V_6 , F_325 , & V_15 ) ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = F_172 ( V_390 , V_370 ) ;
V_241 . V_261 = V_261 ;
F_7 ( V_738 , V_6 , & V_241 , sizeof( V_241 ) , V_15 ) ;
if ( V_15 )
F_140 ( V_15 ) ;
F_139 ( V_375 , V_6 , F_326 ,
V_6 ) ;
}
void F_329 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_224 )
{
T_1 V_635 = F_172 ( V_390 , V_370 ) ;
struct V_382 * V_148 ;
struct V_133 * V_153 ;
F_139 ( V_375 , V_6 , F_326 ,
V_6 ) ;
V_153 = F_47 ( V_384 , V_6 ) ;
if ( ! V_153 )
return;
V_148 = V_153 -> V_156 ;
if ( F_28 ( V_118 , & V_148 -> V_366 . V_118 ) )
return;
if ( V_148 -> V_366 . type != V_635 )
return;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
void F_330 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_390 ,
T_1 V_370 , T_1 V_224 )
{
struct V_739 V_241 ;
if ( F_327 ( V_6 ) && F_89 ( V_6 ) == 1 ) {
F_90 ( & V_6 -> V_225 ) ;
F_91 ( V_6 -> V_226 , & V_6 -> V_225 . V_215 ) ;
}
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = F_172 ( V_390 , V_370 ) ;
V_241 . V_224 = F_1 ( V_224 ) ;
F_7 ( V_740 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_331 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_741 )
{
struct V_742 V_241 ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = V_367 ;
V_241 . V_741 = V_741 ;
F_7 ( V_743 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_332 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_224 )
{
struct V_133 * V_153 ;
V_153 = F_47 ( V_405 , V_6 ) ;
if ( ! V_153 )
return;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
void F_333 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_224 )
{
struct V_133 * V_153 ;
V_153 = F_47 ( V_400 , V_6 ) ;
if ( ! V_153 )
return;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
}
int F_334 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_6 V_744 ,
T_1 V_745 )
{
struct V_746 V_241 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = F_172 ( V_390 , V_370 ) ;
V_241 . V_745 = V_745 ;
V_241 . V_744 = F_30 ( V_744 ) ;
return F_7 ( V_747 , V_6 , & V_241 , sizeof( V_241 ) ,
NULL ) ;
}
int F_335 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 )
{
struct V_748 V_241 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = F_172 ( V_390 , V_370 ) ;
return F_7 ( V_749 , V_6 , & V_241 , sizeof( V_241 ) ,
NULL ) ;
}
static int F_336 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_224 ,
T_1 V_37 )
{
struct V_133 * V_153 ;
V_153 = F_47 ( V_37 , V_6 ) ;
if ( ! V_153 )
return - V_750 ;
V_153 -> V_285 ( V_153 , F_1 ( V_224 ) ) ;
F_112 ( V_153 ) ;
return 0 ;
}
int F_337 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_224 )
{
return F_336 ( V_6 , V_118 , V_390 , V_370 ,
V_224 , V_443 ) ;
}
int F_338 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_224 )
{
return F_336 ( V_6 , V_118 , V_390 , V_370 ,
V_224 ,
V_446 ) ;
}
int F_339 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_224 )
{
return F_336 ( V_6 , V_118 , V_390 , V_370 ,
V_224 , V_449 ) ;
}
int F_340 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_1 V_224 )
{
return F_336 ( V_6 , V_118 , V_390 , V_370 ,
V_224 ,
V_451 ) ;
}
int F_341 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_390 , T_1 V_370 , T_6 V_438 ,
T_1 V_751 )
{
struct V_752 V_241 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_86 ( & V_241 . V_366 . V_118 , V_118 ) ;
V_241 . V_366 . type = F_172 ( V_390 , V_370 ) ;
V_241 . V_438 = F_324 ( V_438 ) ;
V_241 . V_751 = V_751 ;
return F_7 ( V_753 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
void F_342 ( struct V_247 * V_248 , T_1 V_1 )
{
struct V_754 V_241 ;
struct V_133 * V_153 ;
T_1 V_224 = F_1 ( V_1 ) ;
F_86 ( & V_241 . V_366 . V_118 , & V_248 -> V_267 ) ;
V_241 . V_366 . type = F_172 ( V_248 -> type , V_248 -> V_396 ) ;
V_241 . V_224 = V_224 ;
V_153 = F_177 ( V_248 ) ;
F_7 ( V_755 , V_248 -> V_6 , & V_241 , sizeof( V_241 ) ,
V_153 ? V_153 -> V_15 : NULL ) ;
if ( V_153 ) {
V_153 -> V_285 ( V_153 , V_224 ) ;
F_112 ( V_153 ) ;
}
}
void F_343 ( struct V_5 * V_6 , T_1 V_224 )
{
struct V_282 V_283 = { NULL , V_6 } ;
bool V_291 ;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
F_139 ( V_326 , V_6 ,
F_111 , & V_293 ) ;
return;
}
if ( F_22 ( V_327 , & V_6 -> V_162 ) )
V_291 = ! F_83 ( V_6 , V_110 ) ;
else
V_291 = F_79 ( V_6 , V_110 ) ;
F_139 ( V_326 , V_6 , F_107 ,
& V_283 ) ;
if ( V_291 )
F_105 ( V_6 , V_283 . V_15 ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
}
static void F_344 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = V_145 -> V_6 ;
struct V_186 V_148 ;
if ( ! F_69 ( V_6 ) )
return;
memset ( V_6 -> V_188 , 0 , sizeof( V_6 -> V_188 ) ) ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_54 ( V_145 , V_189 , sizeof( V_148 ) , & V_148 ) ;
}
void F_345 ( struct V_5 * V_6 , T_1 V_196 , T_1 V_224 )
{
struct V_282 V_283 = { NULL , V_6 } ;
struct V_144 V_145 ;
bool V_291 = false ;
if ( V_224 ) {
T_1 V_293 = F_1 ( V_224 ) ;
if ( V_196 && F_79 ( V_6 ,
V_111 ) ) {
F_75 ( V_6 , V_112 ) ;
F_105 ( V_6 , NULL ) ;
}
F_139 ( V_329 , V_6 , F_111 ,
& V_293 ) ;
return;
}
if ( V_196 ) {
V_291 = ! F_83 ( V_6 , V_111 ) ;
} else {
V_291 = F_79 ( V_6 , V_111 ) ;
if ( ! V_291 )
V_291 = F_79 ( V_6 ,
V_112 ) ;
else
F_75 ( V_6 , V_112 ) ;
}
F_139 ( V_329 , V_6 , F_107 , & V_283 ) ;
if ( V_291 )
F_105 ( V_6 , V_283 . V_15 ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
F_65 ( & V_145 , V_6 ) ;
if ( F_20 ( V_6 , V_111 ) ) {
if ( F_20 ( V_6 , V_330 ) )
F_54 ( & V_145 , V_331 ,
sizeof( V_196 ) , & V_196 ) ;
F_68 ( & V_145 ) ;
} else {
F_344 ( & V_145 ) ;
}
F_66 ( & V_145 , NULL ) ;
}
static void F_346 ( struct V_133 * V_153 , void * V_7 )
{
struct V_282 * V_283 = V_7 ;
if ( V_283 -> V_15 == NULL ) {
V_283 -> V_15 = V_153 -> V_15 ;
F_109 ( V_283 -> V_15 ) ;
}
}
void F_347 ( struct V_5 * V_6 , T_1 * V_194 ,
T_1 V_224 )
{
struct V_282 V_283 = { NULL , V_6 , F_1 (status) } ;
F_139 ( V_343 , V_6 , F_346 , & V_283 ) ;
F_139 ( V_341 , V_6 , F_346 , & V_283 ) ;
F_139 ( V_342 , V_6 , F_346 , & V_283 ) ;
if ( ! V_224 )
F_6 ( V_708 , V_6 ,
V_194 , 3 , NULL ) ;
if ( V_283 . V_15 )
F_140 ( V_283 . V_15 ) ;
}
void F_348 ( struct V_5 * V_6 , T_1 * V_79 , T_1 V_224 )
{
struct V_455 V_241 ;
struct V_133 * V_153 ;
if ( V_224 )
return;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
memcpy ( V_241 . V_79 , V_79 , V_756 ) ;
memcpy ( V_241 . V_222 , V_6 -> V_222 , V_757 ) ;
V_153 = F_47 ( V_456 , V_6 ) ;
if ( ! V_153 ) {
memcpy ( V_6 -> V_136 , V_79 , sizeof( V_6 -> V_136 ) ) ;
if ( F_47 ( V_273 , V_6 ) )
return;
}
F_6 ( V_457 , V_6 , & V_241 , sizeof( V_241 ) ,
V_153 ? V_153 -> V_15 : NULL ) ;
}
static void F_349 ( struct V_5 * V_6 )
{
if ( ! F_20 ( V_6 , V_235 ) )
return;
if ( F_265 ( V_508 + V_758 ,
V_6 -> V_230 . V_507 +
V_6 -> V_230 . V_509 ) )
return;
F_104 ( V_6 -> V_297 , & V_6 -> V_759 ,
V_758 ) ;
}
static bool F_350 ( struct V_5 * V_6 , T_10 V_517 , T_1 * V_188 ,
T_2 V_655 , T_1 * V_760 , T_1 V_143 )
{
if ( V_6 -> V_230 . V_517 != V_587 &&
( V_517 == V_587 ||
( V_517 < V_6 -> V_230 . V_517 &&
! F_22 ( V_505 , & V_6 -> V_53 ) ) ) )
return false ;
if ( V_6 -> V_230 . V_516 != 0 ) {
if ( ! F_351 ( V_188 , V_655 , V_6 -> V_230 . V_516 ,
V_6 -> V_230 . V_347 ) &&
! F_351 ( V_760 , V_143 ,
V_6 -> V_230 . V_516 ,
V_6 -> V_230 . V_347 ) )
return false ;
}
if ( F_22 ( V_505 , & V_6 -> V_53 ) ) {
F_349 ( V_6 ) ;
if ( V_6 -> V_230 . V_517 != V_587 &&
V_517 < V_6 -> V_230 . V_517 )
return false ;
}
return true ;
}
void F_352 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_390 ,
T_1 V_370 , T_1 * V_194 , T_10 V_517 , T_6 V_162 ,
T_1 * V_188 , T_2 V_655 , T_1 * V_760 , T_1 V_143 )
{
char V_731 [ 512 ] ;
struct V_761 * V_241 = ( void * ) V_731 ;
T_3 V_762 ;
if ( ! F_228 ( V_6 ) ) {
if ( V_390 == V_265 )
return;
if ( V_390 == V_201 && F_132 ( & V_6 -> V_618 ) )
return;
}
if ( V_6 -> V_230 . V_506 ) {
if ( ! F_350 ( V_6 , V_517 , V_188 , V_655 , V_760 ,
V_143 ) )
return;
}
if ( sizeof( * V_241 ) + V_655 + V_143 + 5 > sizeof( V_731 ) )
return;
memset ( V_731 , 0 , sizeof( V_731 ) ) ;
if ( V_517 == V_587 && ! V_6 -> V_230 . V_512 &&
V_390 == V_265 )
V_517 = 0 ;
F_86 ( & V_241 -> V_366 . V_118 , V_118 ) ;
V_241 -> V_366 . type = F_172 ( V_390 , V_370 ) ;
V_241 -> V_517 = V_517 ;
V_241 -> V_162 = F_30 ( V_162 ) ;
if ( V_655 > 0 )
memcpy ( V_241 -> V_188 , V_188 , V_655 ) ;
if ( V_194 && ! F_353 ( V_241 -> V_188 , V_655 , V_664 ) )
V_655 = F_292 ( V_241 -> V_188 , V_655 , V_664 ,
V_194 , 3 ) ;
if ( V_143 > 0 )
memcpy ( V_241 -> V_188 + V_655 , V_760 , V_143 ) ;
V_241 -> V_655 = F_10 ( V_655 + V_143 ) ;
V_762 = sizeof( * V_241 ) + V_655 + V_143 ;
F_7 ( V_763 , V_6 , V_241 , V_762 , NULL ) ;
}
void F_354 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_390 ,
T_1 V_370 , T_10 V_517 , T_1 * V_79 , T_1 V_135 )
{
struct V_761 * V_241 ;
char V_731 [ sizeof( * V_241 ) + V_756 + 2 ] ;
T_2 V_655 ;
V_241 = (struct V_761 * ) V_731 ;
memset ( V_731 , 0 , sizeof( V_731 ) ) ;
F_86 ( & V_241 -> V_366 . V_118 , V_118 ) ;
V_241 -> V_366 . type = F_172 ( V_390 , V_370 ) ;
V_241 -> V_517 = V_517 ;
V_655 = F_292 ( V_241 -> V_188 , 0 , V_140 , V_79 ,
V_135 ) ;
V_241 -> V_655 = F_10 ( V_655 ) ;
F_7 ( V_763 , V_6 , V_241 , sizeof( * V_241 ) + V_655 , NULL ) ;
}
void F_355 ( struct V_5 * V_6 , T_1 V_764 )
{
struct V_765 V_241 ;
F_9 ( L_42 , V_6 -> V_79 , V_764 ) ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . type = V_6 -> V_230 . type ;
V_241 . V_764 = V_764 ;
F_7 ( V_766 , V_6 , & V_241 , sizeof( V_241 ) , NULL ) ;
}
static void F_356 ( struct V_5 * V_6 , T_1 V_224 , T_2 V_37 )
{
F_9 ( L_16 , V_6 -> V_79 , V_224 ) ;
}
void F_357 ( struct V_5 * V_6 )
{
struct V_144 V_145 ;
if ( ! F_20 ( V_6 , V_113 ) &&
! F_20 ( V_6 , V_152 ) )
return;
F_65 ( & V_145 , V_6 ) ;
F_73 ( & V_145 ) ;
F_66 ( & V_145 , F_356 ) ;
}
int F_358 ( void )
{
return F_359 ( & V_767 ) ;
}
void F_360 ( void )
{
F_361 ( & V_767 ) ;
}
