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
static T_1 F_51 ( struct V_5 * V_6 )
{
if ( F_20 ( V_6 , V_134 ) &&
! F_20 ( V_6 , V_113 ) )
return V_6 -> V_135 ;
return 0x00 ;
}
static T_1 F_52 ( struct V_5 * V_6 , T_1 * V_120 )
{
T_1 V_136 = 0 ;
T_3 V_137 ;
V_137 = strlen ( V_6 -> V_138 ) ;
if ( V_137 > 0 ) {
T_3 V_139 = V_140 - V_136 - 2 ;
if ( V_137 > V_139 ) {
V_137 = V_139 ;
V_120 [ 1 ] = V_141 ;
} else
V_120 [ 1 ] = V_142 ;
V_120 [ 0 ] = V_137 + 1 ;
memcpy ( V_120 + 2 , V_6 -> V_138 , V_137 ) ;
V_136 += ( V_137 + 2 ) ;
V_120 += ( V_137 + 2 ) ;
}
return V_136 ;
}
static T_1 F_53 ( struct V_5 * V_6 , T_1 V_143 ,
T_1 * V_120 )
{
struct V_144 * V_145 ;
V_145 = F_54 ( V_6 , V_143 ) ;
if ( ! V_145 )
return 0 ;
memcpy ( V_120 , V_145 -> V_146 ,
V_145 -> V_147 ) ;
return V_145 -> V_147 ;
}
static void F_55 ( struct V_148 * V_149 , T_1 V_143 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_150 V_151 ;
T_1 V_8 ;
if ( ! F_20 ( V_6 , V_109 ) )
return;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
if ( V_143 )
V_8 = F_53 ( V_6 , V_143 , V_151 . V_7 ) ;
else
V_8 = F_52 ( V_6 , V_151 . V_7 ) ;
if ( V_6 -> V_152 == V_8 &&
! memcmp ( V_151 . V_7 , V_6 -> V_146 , V_8 ) )
return;
memcpy ( V_6 -> V_146 , V_151 . V_7 , sizeof( V_151 . V_7 ) ) ;
V_6 -> V_152 = V_8 ;
V_151 . V_153 = V_8 ;
F_56 ( V_149 , V_154 , sizeof( V_151 ) , & V_151 ) ;
}
static void F_57 ( struct V_148 * V_149 )
{
F_55 ( V_149 , F_51 ( V_149 -> V_6 ) ) ;
}
static T_1 F_58 ( struct V_5 * V_6 )
{
struct V_133 * V_155 ;
V_155 = F_47 ( V_156 , V_6 ) ;
if ( V_155 ) {
struct V_157 * V_151 = V_155 -> V_158 ;
if ( V_151 -> V_159 == 0x01 )
return V_160 ;
else if ( V_151 -> V_159 == 0x02 )
return V_161 ;
} else {
if ( F_20 ( V_6 , V_162 ) )
return V_161 ;
else if ( F_20 ( V_6 , V_106 ) )
return V_160 ;
}
return 0 ;
}
static bool F_59 ( struct V_5 * V_6 )
{
struct V_133 * V_155 ;
V_155 = F_47 ( V_163 , V_6 ) ;
if ( V_155 ) {
struct V_157 * V_151 = V_155 -> V_158 ;
return V_151 -> V_159 ;
}
return F_20 ( V_6 , V_104 ) ;
}
static T_6 F_60 ( struct V_5 * V_6 , T_1 V_143 )
{
T_6 V_164 ;
struct V_144 * V_145 ;
if ( V_143 == 0x00 ) {
V_164 = V_165 | V_166 ;
if ( F_20 ( V_6 , V_167 ) )
V_164 |= V_168 ;
return V_164 ;
}
V_145 = F_54 ( V_6 , V_143 ) ;
if ( ! V_145 )
return 0 ;
return V_145 -> V_164 ;
}
static T_1 F_61 ( struct V_5 * V_6 )
{
T_1 V_143 = F_51 ( V_6 ) ;
struct V_144 * V_145 ;
if ( V_143 == 0x00 )
return 0 ;
V_145 = F_54 ( V_6 , V_143 ) ;
if ( ! V_145 )
return 0 ;
return V_145 -> V_147 ;
}
static T_1 F_62 ( struct V_5 * V_6 , T_1 V_143 , T_1 * V_120 )
{
struct V_144 * V_145 = NULL ;
T_1 V_136 = 0 , V_164 = 0 ;
T_6 V_169 ;
if ( V_143 ) {
V_145 = F_54 ( V_6 , V_143 ) ;
if ( ! V_145 )
return 0 ;
}
V_169 = F_60 ( V_6 , V_143 ) ;
if ( V_169 & V_170 )
V_164 |= V_160 ;
if ( V_169 & V_171 )
V_164 |= V_161 ;
if ( V_164 || ( V_169 & V_166 ) ) {
if ( ! V_164 )
V_164 |= F_58 ( V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) )
V_164 |= V_172 ;
if ( V_164 ) {
V_120 [ 0 ] = 0x02 ;
V_120 [ 1 ] = V_173 ;
V_120 [ 2 ] = V_164 ;
V_136 += 3 ;
V_120 += 3 ;
}
}
if ( V_145 ) {
memcpy ( V_120 , V_145 -> V_174 ,
V_145 -> V_175 ) ;
V_136 += V_145 -> V_175 ;
V_120 += V_145 -> V_175 ;
}
if ( V_6 -> V_176 != V_177 &&
( V_169 & V_165 ) ) {
V_120 [ 0 ] = 0x02 ;
V_120 [ 1 ] = V_178 ;
V_120 [ 2 ] = ( T_1 ) V_6 -> V_176 ;
V_136 += 3 ;
V_120 += 3 ;
}
return V_136 ;
}
static void F_63 ( struct V_148 * V_149 , T_1 V_143 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_179 V_151 ;
T_1 V_8 ;
if ( ! F_20 ( V_6 , V_109 ) )
return;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_8 = F_62 ( V_6 , V_143 , V_151 . V_7 ) ;
if ( V_6 -> V_175 == V_8 &&
memcmp ( V_151 . V_7 , V_6 -> V_174 , V_8 ) == 0 )
return;
memcpy ( V_6 -> V_174 , V_151 . V_7 , sizeof( V_151 . V_7 ) ) ;
V_6 -> V_175 = V_8 ;
V_151 . V_153 = V_8 ;
F_56 ( V_149 , V_180 , sizeof( V_151 ) , & V_151 ) ;
}
static void F_64 ( struct V_148 * V_149 )
{
F_63 ( V_149 , F_51 ( V_149 -> V_6 ) ) ;
}
int F_65 ( struct V_5 * V_6 )
{
struct V_148 V_149 ;
F_66 ( & V_149 , V_6 ) ;
F_64 ( & V_149 ) ;
return F_67 ( & V_149 , NULL ) ;
}
static void F_68 ( struct V_5 * V_6 , T_1 * V_7 )
{
T_1 * V_120 = V_7 ;
T_3 V_137 ;
V_137 = strlen ( V_6 -> V_138 ) ;
if ( V_137 > 0 ) {
if ( V_137 > 48 ) {
V_137 = 48 ;
V_120 [ 1 ] = V_141 ;
} else
V_120 [ 1 ] = V_142 ;
V_120 [ 0 ] = V_137 + 1 ;
memcpy ( V_120 + 2 , V_6 -> V_138 , V_137 ) ;
V_120 += ( V_137 + 2 ) ;
}
if ( V_6 -> V_181 != V_177 ) {
V_120 [ 0 ] = 2 ;
V_120 [ 1 ] = V_178 ;
V_120 [ 2 ] = ( T_1 ) V_6 -> V_181 ;
V_120 += 3 ;
}
if ( V_6 -> V_182 > 0 ) {
V_120 [ 0 ] = 9 ;
V_120 [ 1 ] = V_183 ;
F_15 ( V_6 -> V_182 , V_120 + 2 ) ;
F_15 ( V_6 -> V_184 , V_120 + 4 ) ;
F_15 ( V_6 -> V_185 , V_120 + 6 ) ;
F_15 ( V_6 -> V_186 , V_120 + 8 ) ;
V_120 += 10 ;
}
V_120 = F_43 ( V_6 , V_120 , V_187 - ( V_120 - V_7 ) ) ;
V_120 = F_45 ( V_6 , V_120 , V_187 - ( V_120 - V_7 ) ) ;
V_120 = F_46 ( V_6 , V_120 , V_187 - ( V_120 - V_7 ) ) ;
}
static void F_69 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_188 V_151 ;
if ( ! F_42 ( V_6 ) )
return;
if ( ! F_70 ( V_6 ) )
return;
if ( ! F_20 ( V_6 , V_111 ) )
return;
if ( F_20 ( V_6 , V_189 ) )
return;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
F_68 ( V_6 , V_151 . V_7 ) ;
if ( memcmp ( V_151 . V_7 , V_6 -> V_190 , sizeof( V_151 . V_7 ) ) == 0 )
return;
memcpy ( V_6 -> V_190 , V_151 . V_7 , sizeof( V_151 . V_7 ) ) ;
F_56 ( V_149 , V_191 , sizeof( V_151 ) , & V_151 ) ;
}
static T_1 F_71 ( struct V_5 * V_6 )
{
struct V_122 * V_123 ;
T_1 V_159 = 0 ;
F_19 (uuid, &hdev->uuids, list)
V_159 |= V_123 -> V_192 ;
return V_159 ;
}
static void F_72 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
T_1 V_193 [ 3 ] ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_42 ( V_6 ) )
return;
if ( ! F_20 ( V_6 , V_108 ) )
return;
if ( F_20 ( V_6 , V_189 ) )
return;
V_193 [ 0 ] = V_6 -> V_194 ;
V_193 [ 1 ] = V_6 -> V_195 ;
V_193 [ 2 ] = F_71 ( V_6 ) ;
if ( F_20 ( V_6 , V_162 ) )
V_193 [ 1 ] |= 0x20 ;
if ( memcmp ( V_193 , V_6 -> V_196 , 3 ) == 0 )
return;
F_56 ( V_149 , V_197 , sizeof( V_193 ) , V_193 ) ;
}
static void F_73 ( struct V_148 * V_149 )
{
T_1 V_198 = 0x00 ;
F_56 ( V_149 , V_199 , sizeof( V_198 ) , & V_198 ) ;
}
static void F_74 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_200 V_151 ;
T_1 V_201 , V_198 = 0x01 ;
bool V_202 ;
T_1 V_143 ;
T_6 V_164 ;
if ( F_75 ( V_6 , V_203 ) > 0 )
return;
if ( F_20 ( V_6 , V_204 ) )
F_73 ( V_149 ) ;
F_76 ( V_6 , V_204 ) ;
V_143 = F_51 ( V_6 ) ;
V_164 = F_60 ( V_6 , V_143 ) ;
V_202 = ( V_164 & V_168 ) ||
F_59 ( V_6 ) ;
if ( F_77 ( V_149 , ! V_202 , & V_201 ) < 0 )
return;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_205 = F_10 ( V_6 -> V_206 ) ;
V_151 . V_207 = F_10 ( V_6 -> V_208 ) ;
if ( V_202 )
V_151 . type = V_209 ;
else if ( F_61 ( V_6 ) )
V_151 . type = V_210 ;
else
V_151 . type = V_211 ;
V_151 . V_212 = V_201 ;
V_151 . V_213 = V_6 -> V_214 ;
F_56 ( V_149 , V_215 , sizeof( V_151 ) , & V_151 ) ;
F_56 ( V_149 , V_199 , sizeof( V_198 ) , & V_198 ) ;
}
static void F_78 ( struct V_216 * V_217 )
{
struct V_5 * V_6 = F_79 ( V_217 , struct V_5 ,
V_218 . V_217 ) ;
struct V_148 V_149 ;
if ( ! F_80 ( V_6 , V_189 ) )
return;
F_66 ( & V_149 , V_6 ) ;
F_34 ( V_6 ) ;
F_69 ( & V_149 ) ;
F_72 ( & V_149 ) ;
F_35 ( V_6 ) ;
F_67 ( & V_149 , NULL ) ;
}
static void F_81 ( struct V_216 * V_217 )
{
struct V_5 * V_6 = F_79 ( V_217 , struct V_5 ,
F_81 . V_217 ) ;
struct V_148 V_149 ;
F_9 ( L_5 ) ;
F_82 ( V_6 , V_219 ) ;
if ( ! F_20 ( V_6 , V_113 ) )
return;
F_66 ( & V_149 , V_6 ) ;
F_74 ( & V_149 ) ;
F_67 ( & V_149 , NULL ) ;
}
static void F_83 ( struct V_11 * V_15 , struct V_5 * V_6 )
{
if ( F_84 ( V_6 , V_220 ) )
return;
F_85 ( & V_6 -> V_218 , F_78 ) ;
F_85 ( & V_6 -> F_81 , F_81 ) ;
F_76 ( V_6 , V_107 ) ;
}
static int F_86 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_221 V_18 ;
F_9 ( L_3 , V_15 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_87 ( & V_18 . V_118 , & V_6 -> V_118 ) ;
V_18 . V_19 = V_6 -> V_91 ;
V_18 . V_80 = F_10 ( V_6 -> V_80 ) ;
V_18 . V_222 = F_30 ( F_36 ( V_6 ) ) ;
V_18 . V_223 = F_30 ( F_41 ( V_6 ) ) ;
memcpy ( V_18 . V_196 , V_6 -> V_196 , 3 ) ;
memcpy ( V_18 . V_79 , V_6 -> V_138 , sizeof( V_6 -> V_138 ) ) ;
memcpy ( V_18 . V_224 , V_6 -> V_224 , sizeof( V_6 -> V_224 ) ) ;
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_225 , 0 , & V_18 ,
sizeof( V_18 ) ) ;
}
static int F_88 ( struct V_11 * V_15 , T_2 V_37 , struct V_5 * V_6 )
{
T_5 V_85 = F_30 ( F_41 ( V_6 ) ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_37 , 0 , & V_85 ,
sizeof( V_85 ) ) ;
}
static void F_89 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
F_9 ( L_6 , V_6 -> V_79 , V_226 ) ;
if ( F_90 ( V_6 ) == 0 ) {
F_91 ( & V_6 -> V_227 ) ;
F_92 ( V_6 -> V_228 , & V_6 -> V_227 . V_217 ) ;
}
}
static bool F_93 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_229 V_151 ;
struct V_230 * V_231 ;
switch ( V_6 -> V_232 . V_233 ) {
case V_234 :
if ( F_22 ( V_235 , & V_6 -> V_164 ) )
F_56 ( V_149 , V_236 , 0 , NULL ) ;
if ( F_20 ( V_6 , V_237 ) ) {
F_91 ( & V_6 -> V_238 ) ;
F_94 ( V_149 ) ;
}
return true ;
case V_239 :
V_231 = F_95 ( V_6 , V_72 ,
V_240 ) ;
if ( ! V_231 )
break;
F_87 ( & V_151 . V_118 , & V_231 -> V_7 . V_118 ) ;
F_56 ( V_149 , V_241 , sizeof( V_151 ) ,
& V_151 ) ;
return true ;
default:
if ( F_20 ( V_6 , V_237 ) ) {
F_94 ( V_149 ) ;
return true ;
}
break;
}
return false ;
}
static void F_96 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_1 V_143 )
{
struct V_242 V_243 ;
V_243 . V_143 = V_143 ;
F_7 ( V_244 , V_6 , & V_243 , sizeof( V_243 ) , V_15 ) ;
}
static void F_97 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_1 V_143 )
{
struct V_245 V_243 ;
V_243 . V_143 = V_143 ;
F_7 ( V_246 , V_6 , & V_243 , sizeof( V_243 ) , V_15 ) ;
}
static int F_98 ( struct V_148 * V_149 , T_1 V_143 ,
bool V_247 ) {
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_144 * V_145 = NULL ;
T_2 V_248 ;
if ( F_20 ( V_6 , V_113 ) ||
! F_20 ( V_6 , V_134 ) )
return - V_249 ;
if ( V_6 -> V_250 )
return - V_251 ;
V_145 = F_54 ( V_6 , V_143 ) ;
if ( ! V_145 )
return - V_252 ;
if ( V_145 -> V_248 == 0 ||
V_145 -> V_253 <= V_145 -> V_254 )
V_248 = V_145 -> V_253 ;
else
V_248 = V_145 -> V_254 ;
if ( V_145 -> V_248 )
V_145 -> V_254 =
V_145 -> V_254 - V_248 ;
V_6 -> V_250 = V_248 ;
F_99 ( V_6 -> V_255 ,
& V_6 -> V_256 ,
F_100 ( V_248 * 1000 ) ) ;
if ( ! V_247 && V_6 -> V_135 == V_143 &&
F_20 ( V_6 , V_204 ) )
return 0 ;
V_6 -> V_135 = V_143 ;
F_64 ( V_149 ) ;
F_57 ( V_149 ) ;
F_74 ( V_149 ) ;
return 0 ;
}
static void F_101 ( struct V_5 * V_6 )
{
if ( V_6 -> V_250 ) {
V_6 -> V_250 = 0 ;
F_91 ( & V_6 -> V_256 ) ;
}
}
static void F_102 ( struct V_5 * V_6 , struct V_148 * V_149 ,
T_1 V_143 , bool V_247 )
{
struct V_144 * V_145 , * V_257 , * V_258 = NULL ;
int V_30 ;
T_1 V_259 ;
if ( ! V_143 || V_6 -> V_135 == V_143 )
F_101 ( V_6 ) ;
if ( V_143 && V_6 -> V_135 == V_143 )
V_258 = F_103 ( V_6 , V_143 ) ;
if ( V_143 == 0x00 ) {
F_104 (adv_instance, n, &hdev->adv_instances,
list) {
if ( ! ( V_247 || V_145 -> V_248 ) )
continue;
V_259 = V_145 -> V_143 ;
V_30 = F_105 ( V_6 , V_259 ) ;
if ( ! V_30 )
F_97 ( NULL , V_6 , V_259 ) ;
}
V_6 -> V_135 = 0x00 ;
} else {
V_145 = F_54 ( V_6 , V_143 ) ;
if ( V_247 || ( V_145 && V_145 -> V_248 &&
! V_145 -> V_254 ) ) {
if ( V_258 &&
V_258 -> V_143 == V_143 )
V_258 = NULL ;
V_30 = F_105 ( V_6 , V_143 ) ;
if ( ! V_30 )
F_97 ( NULL , V_6 , V_143 ) ;
}
}
if ( F_106 ( & V_6 -> V_260 ) ) {
V_6 -> V_135 = 0x00 ;
F_76 ( V_6 , V_134 ) ;
}
if ( ! V_149 || ! F_42 ( V_6 ) ||
F_20 ( V_6 , V_113 ) )
return;
if ( V_258 )
F_98 ( V_149 , V_258 -> V_143 , false ) ;
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_148 V_149 ;
struct V_261 * V_262 ;
bool V_263 ;
int V_30 ;
F_66 ( & V_149 , V_6 ) ;
if ( F_22 ( V_264 , & V_6 -> V_164 ) ||
F_22 ( V_265 , & V_6 -> V_164 ) ) {
T_1 V_266 = 0x00 ;
F_56 ( & V_149 , V_267 , 1 , & V_266 ) ;
}
F_102 ( V_6 , NULL , 0x00 , false ) ;
if ( F_20 ( V_6 , V_204 ) )
F_73 ( & V_149 ) ;
V_263 = F_93 ( & V_149 ) ;
F_19 (conn, &hdev->conn_hash.list, list) {
struct V_268 V_269 ;
struct V_270 V_271 ;
switch ( V_262 -> V_233 ) {
case V_272 :
case V_273 :
V_269 . V_274 = F_10 ( V_262 -> V_274 ) ;
V_269 . V_275 = 0x15 ;
F_56 ( & V_149 , V_276 , sizeof( V_269 ) , & V_269 ) ;
break;
case V_277 :
if ( V_262 -> type == V_203 )
F_56 ( & V_149 , V_278 ,
0 , NULL ) ;
else if ( V_262 -> type == V_279 )
F_56 ( & V_149 , V_280 ,
6 , & V_262 -> V_281 ) ;
break;
case V_282 :
F_87 ( & V_271 . V_118 , & V_262 -> V_281 ) ;
V_271 . V_275 = 0x15 ;
if ( V_262 -> type == V_279 )
F_56 ( & V_149 , V_283 ,
sizeof( V_271 ) , & V_271 ) ;
else if ( V_262 -> type == V_284 )
F_56 ( & V_149 , V_285 ,
sizeof( V_271 ) , & V_271 ) ;
break;
}
}
V_30 = F_67 ( & V_149 , F_89 ) ;
if ( ! V_30 && V_263 )
F_108 ( V_6 , V_286 ) ;
return V_30 ;
}
static int F_109 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_287 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_287 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_287 ,
V_289 ) ;
goto V_290;
}
if ( F_80 ( V_6 , V_291 ) ) {
F_91 ( & V_6 -> V_227 ) ;
if ( V_151 -> V_159 ) {
F_111 ( V_15 , V_287 , V_6 ,
V_7 , V_8 ) ;
V_30 = F_112 ( V_6 , 1 ) ;
goto V_290;
}
}
if ( ! ! V_151 -> V_159 == F_42 ( V_6 ) ) {
V_30 = F_88 ( V_15 , V_287 , V_6 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_287 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
if ( V_151 -> V_159 ) {
F_92 ( V_6 -> V_228 , & V_6 -> V_292 ) ;
V_30 = 0 ;
} else {
V_30 = F_107 ( V_6 ) ;
if ( ! V_30 )
F_99 ( V_6 -> V_228 , & V_6 -> V_227 ,
V_293 ) ;
if ( V_30 == - V_294 ) {
F_91 ( & V_6 -> V_227 ) ;
F_92 ( V_6 -> V_228 , & V_6 -> V_227 . V_217 ) ;
V_30 = 0 ;
}
}
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_113 ( struct V_5 * V_6 , struct V_11 * V_76 )
{
T_5 V_243 = F_30 ( F_41 ( V_6 ) ) ;
return F_6 ( V_295 , V_6 , & V_243 ,
sizeof( V_243 ) , V_76 ) ;
}
int F_114 ( struct V_5 * V_6 )
{
return F_113 ( V_6 , NULL ) ;
}
static void F_115 ( struct V_133 * V_155 , void * V_7 )
{
struct V_296 * V_297 = V_7 ;
F_88 ( V_155 -> V_15 , V_155 -> V_37 , V_297 -> V_6 ) ;
F_116 ( & V_155 -> V_298 ) ;
if ( V_297 -> V_15 == NULL ) {
V_297 -> V_15 = V_155 -> V_15 ;
F_117 ( V_297 -> V_15 ) ;
}
F_118 ( V_155 ) ;
}
static void F_119 ( struct V_133 * V_155 , void * V_7 )
{
T_1 * V_226 = V_7 ;
F_110 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , * V_226 ) ;
F_120 ( V_155 ) ;
}
static void F_121 ( struct V_133 * V_155 , void * V_7 )
{
if ( V_155 -> V_299 ) {
T_1 * V_226 = V_7 ;
V_155 -> V_299 ( V_155 , * V_226 ) ;
F_120 ( V_155 ) ;
return;
}
F_119 ( V_155 , V_7 ) ;
}
static int F_122 ( struct V_133 * V_155 , T_1 V_226 )
{
return F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_226 ,
V_155 -> V_158 , V_155 -> V_300 ) ;
}
static int F_123 ( struct V_133 * V_155 , T_1 V_226 )
{
return F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_226 ,
V_155 -> V_158 , sizeof( struct V_301 ) ) ;
}
static T_1 F_124 ( struct V_5 * V_6 )
{
if ( ! F_37 ( V_6 ) )
return V_302 ;
else if ( ! F_20 ( V_6 , V_108 ) )
return V_303 ;
else
return V_304 ;
}
static T_1 F_125 ( struct V_5 * V_6 )
{
if ( ! F_40 ( V_6 ) )
return V_302 ;
else if ( ! F_20 ( V_6 , V_109 ) )
return V_303 ;
else
return V_304 ;
}
static void F_126 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_133 * V_155 ;
struct V_157 * V_151 ;
struct V_148 V_149 ;
bool V_305 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_156 , V_6 ) ;
if ( ! V_155 )
goto V_306;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
F_110 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_307 ) ;
F_76 ( V_6 , V_162 ) ;
goto V_308;
}
V_151 = V_155 -> V_158 ;
if ( V_151 -> V_159 ) {
V_305 = ! F_84 ( V_6 , V_106 ) ;
if ( V_6 -> V_309 > 0 ) {
int V_310 = F_100 ( V_6 -> V_309 * 1000 ) ;
F_99 ( V_6 -> V_255 , & V_6 -> V_311 ,
V_310 ) ;
}
} else {
V_305 = F_80 ( V_6 , V_106 ) ;
}
F_88 ( V_155 -> V_15 , V_156 , V_6 ) ;
if ( V_305 )
F_113 ( V_6 , V_155 -> V_15 ) ;
F_66 ( & V_149 , V_6 ) ;
F_127 ( & V_149 ) ;
F_72 ( & V_149 ) ;
F_67 ( & V_149 , NULL ) ;
V_308:
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_128 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_312 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
T_2 V_248 ;
T_1 V_266 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_20 ( V_6 , V_109 ) &&
! F_20 ( V_6 , V_108 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_156 ,
V_303 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 && V_151 -> V_159 != 0x02 )
return F_110 ( V_15 , V_6 -> V_55 , V_156 ,
V_288 ) ;
V_248 = F_129 ( V_151 -> V_248 ) ;
if ( ( V_151 -> V_159 == 0x00 && V_248 > 0 ) ||
( V_151 -> V_159 == 0x02 && V_248 == 0 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_156 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) && V_248 > 0 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_156 ,
V_313 ) ;
goto V_290;
}
if ( F_47 ( V_156 , V_6 ) ||
F_47 ( V_163 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_156 ,
V_289 ) ;
goto V_290;
}
if ( ! F_20 ( V_6 , V_104 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_156 ,
V_303 ) ;
goto V_290;
}
if ( ! F_42 ( V_6 ) ) {
bool V_305 = false ;
if ( ! ! V_151 -> V_159 != F_20 ( V_6 , V_106 ) ) {
F_130 ( V_6 , V_106 ) ;
V_305 = true ;
}
V_30 = F_88 ( V_15 , V_156 , V_6 ) ;
if ( V_30 < 0 )
goto V_290;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_290;
}
if ( ! ! V_151 -> V_159 == F_20 ( V_6 , V_106 ) &&
( V_151 -> V_159 == 0x02 ) == F_20 ( V_6 ,
V_162 ) ) {
F_91 ( & V_6 -> V_311 ) ;
V_6 -> V_309 = V_248 ;
if ( V_151 -> V_159 && V_6 -> V_309 > 0 ) {
int V_310 = F_100 ( V_6 -> V_309 * 1000 ) ;
F_99 ( V_6 -> V_255 , & V_6 -> V_311 ,
V_310 ) ;
}
V_30 = F_88 ( V_15 , V_156 , V_6 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_156 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
F_91 ( & V_6 -> V_311 ) ;
V_6 -> V_309 = V_248 ;
if ( V_151 -> V_159 == 0x02 )
F_82 ( V_6 , V_162 ) ;
else
F_76 ( V_6 , V_162 ) ;
F_66 ( & V_149 , V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) )
goto V_314;
V_266 = V_315 ;
if ( V_151 -> V_159 ) {
struct V_316 V_317 ;
if ( V_151 -> V_159 == 0x02 ) {
V_317 . V_318 = F_131 ( T_1 , V_6 -> V_318 , 2 ) ;
V_317 . V_319 [ 0 ] = 0x00 ;
V_317 . V_319 [ 1 ] = 0x8b ;
V_317 . V_319 [ 2 ] = 0x9e ;
V_317 . V_319 [ 3 ] = 0x33 ;
V_317 . V_319 [ 4 ] = 0x8b ;
V_317 . V_319 [ 5 ] = 0x9e ;
} else {
V_317 . V_318 = 1 ;
V_317 . V_319 [ 0 ] = 0x33 ;
V_317 . V_319 [ 1 ] = 0x8b ;
V_317 . V_319 [ 2 ] = 0x9e ;
}
F_56 ( & V_149 , V_320 ,
( V_317 . V_318 * 3 ) + 1 , & V_317 ) ;
V_266 |= V_321 ;
} else {
F_76 ( V_6 , V_162 ) ;
}
F_56 ( & V_149 , V_267 , sizeof( V_266 ) , & V_266 ) ;
V_314:
F_64 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_126 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_132 ( struct V_148 * V_149 , bool V_198 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_322 V_323 ;
T_1 type ;
if ( ! F_20 ( V_6 , V_108 ) )
return;
if ( V_6 -> V_91 < V_92 )
return;
if ( V_198 ) {
type = V_324 ;
V_323 . V_325 = F_10 ( 0x0100 ) ;
} else {
type = V_326 ;
V_323 . V_325 = F_10 ( 0x0800 ) ;
}
V_323 . V_327 = F_10 ( 0x0012 ) ;
if ( F_133 ( V_6 -> V_328 ) != V_323 . V_325 ||
F_133 ( V_6 -> V_329 ) != V_323 . V_327 )
F_56 ( V_149 , V_330 ,
sizeof( V_323 ) , & V_323 ) ;
if ( V_6 -> V_331 != type )
F_56 ( V_149 , V_332 , 1 , & type ) ;
}
static void F_134 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_133 * V_155 ;
struct V_157 * V_151 ;
bool V_333 , V_334 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_163 , V_6 ) ;
if ( ! V_155 )
goto V_306;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
F_110 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_307 ) ;
goto V_308;
}
V_151 = V_155 -> V_158 ;
if ( V_151 -> V_159 ) {
V_333 = ! F_84 ( V_6 ,
V_104 ) ;
V_334 = false ;
} else {
V_333 = F_80 ( V_6 ,
V_104 ) ;
V_334 = F_80 ( V_6 ,
V_106 ) ;
}
F_88 ( V_155 -> V_15 , V_163 , V_6 ) ;
if ( V_333 || V_334 ) {
F_113 ( V_6 , V_155 -> V_15 ) ;
F_135 ( V_6 ) ;
if ( V_334 )
F_65 ( V_6 ) ;
F_136 ( V_6 ) ;
}
V_308:
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_137 ( struct V_5 * V_6 ,
struct V_11 * V_15 , T_1 V_159 )
{
bool V_305 = false ;
int V_30 ;
if ( ! ! V_159 != F_20 ( V_6 , V_104 ) )
V_305 = true ;
if ( V_159 ) {
F_82 ( V_6 , V_104 ) ;
} else {
F_76 ( V_6 , V_104 ) ;
F_76 ( V_6 , V_106 ) ;
}
V_30 = F_88 ( V_15 , V_163 , V_6 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_305 ) {
F_135 ( V_6 ) ;
F_136 ( V_6 ) ;
return F_113 ( V_6 , V_15 ) ;
}
return 0 ;
}
static int F_138 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
T_1 V_266 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_20 ( V_6 , V_109 ) &&
! F_20 ( V_6 , V_108 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_163 ,
V_303 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_163 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_137 ( V_6 , V_15 , V_151 -> V_159 ) ;
goto V_290;
}
if ( F_47 ( V_156 , V_6 ) ||
F_47 ( V_163 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_163 ,
V_289 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_163 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
F_66 ( & V_149 , V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) ) {
if ( ! V_151 -> V_159 ) {
F_76 ( V_6 , V_162 ) ;
F_76 ( V_6 , V_106 ) ;
}
F_64 ( & V_149 ) ;
} else if ( V_151 -> V_159 != F_22 ( V_265 , & V_6 -> V_164 ) ) {
if ( V_151 -> V_159 ) {
V_266 = V_315 ;
} else {
if ( F_106 ( & V_6 -> V_335 ) )
V_266 = V_336 ;
else if ( F_22 ( V_264 , & V_6 -> V_164 ) )
V_266 = V_315 ;
else
goto V_337;
if ( F_22 ( V_264 , & V_6 -> V_164 ) &&
V_6 -> V_309 > 0 )
F_91 ( & V_6 -> V_311 ) ;
}
F_56 ( & V_149 , V_267 , 1 , & V_266 ) ;
}
V_337:
if ( F_20 ( V_6 , V_113 ) ||
F_20 ( V_6 , V_134 ) )
F_74 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_134 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
if ( V_30 == - V_294 )
V_30 = F_137 ( V_6 , V_15 ,
V_151 -> V_159 ) ;
goto V_290;
}
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_139 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
bool V_305 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_338 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( V_151 -> V_159 )
V_305 = ! F_84 ( V_6 , V_107 ) ;
else
V_305 = F_80 ( V_6 , V_107 ) ;
V_30 = F_88 ( V_15 , V_338 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_140 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
T_1 V_159 , V_226 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_226 = F_124 ( V_6 ) ;
if ( V_226 )
return F_110 ( V_15 , V_6 -> V_55 , V_339 ,
V_226 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_339 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
bool V_305 = false ;
if ( ! ! V_151 -> V_159 != F_20 ( V_6 , V_110 ) ) {
F_130 ( V_6 , V_110 ) ;
V_305 = true ;
}
V_30 = F_88 ( V_15 , V_339 , V_6 ) ;
if ( V_30 < 0 )
goto V_290;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_290;
}
if ( F_47 ( V_339 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_339 ,
V_289 ) ;
goto V_290;
}
V_159 = ! ! V_151 -> V_159 ;
if ( F_22 ( V_340 , & V_6 -> V_164 ) == V_159 ) {
V_30 = F_88 ( V_15 , V_339 , V_6 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_339 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
V_30 = F_141 ( V_6 , V_341 , sizeof( V_159 ) , & V_159 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
goto V_290;
}
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_142 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_226 = F_124 ( V_6 ) ;
if ( V_226 )
return F_110 ( V_15 , V_6 -> V_55 , V_342 , V_226 ) ;
if ( ! F_38 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_342 ,
V_302 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_342 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
bool V_305 ;
if ( V_151 -> V_159 ) {
V_305 = ! F_84 ( V_6 ,
V_111 ) ;
} else {
V_305 = F_80 ( V_6 ,
V_111 ) ;
if ( ! V_305 )
V_305 = F_80 ( V_6 ,
V_112 ) ;
else
F_76 ( V_6 , V_112 ) ;
}
V_30 = F_88 ( V_15 , V_342 , V_6 ) ;
if ( V_30 < 0 )
goto V_290;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_290;
}
if ( F_47 ( V_342 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_342 ,
V_289 ) ;
goto V_290;
}
if ( ! ! V_151 -> V_159 == F_20 ( V_6 , V_111 ) ) {
V_30 = F_88 ( V_15 , V_342 , V_6 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_342 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
if ( ! V_151 -> V_159 && F_20 ( V_6 , V_343 ) )
F_141 ( V_6 , V_344 ,
sizeof( V_151 -> V_159 ) , & V_151 -> V_159 ) ;
V_30 = F_141 ( V_6 , V_345 , 1 , & V_151 -> V_159 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
goto V_290;
}
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_143 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
bool V_305 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_226 = F_124 ( V_6 ) ;
if ( V_226 )
return F_110 ( V_15 , V_6 -> V_55 , V_346 , V_226 ) ;
if ( ! F_38 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_346 ,
V_302 ) ;
if ( ! F_20 ( V_6 , V_111 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_346 ,
V_303 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_346 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_342 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_346 ,
V_289 ) ;
goto V_306;
}
if ( V_151 -> V_159 ) {
V_305 = ! F_84 ( V_6 , V_112 ) ;
} else {
if ( F_42 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_346 ,
V_303 ) ;
goto V_306;
}
V_305 = F_80 ( V_6 , V_112 ) ;
}
V_30 = F_88 ( V_15 , V_346 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_144 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_296 V_297 = { NULL , V_6 } ;
F_34 ( V_6 ) ;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
F_145 ( V_347 , V_6 , F_119 ,
& V_307 ) ;
goto V_306;
}
F_145 ( V_347 , V_6 , F_115 , & V_297 ) ;
F_113 ( V_6 , V_297 . V_15 ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
if ( F_20 ( V_6 , V_109 ) ) {
struct V_148 V_149 ;
F_66 ( & V_149 , V_6 ) ;
F_64 ( & V_149 ) ;
F_57 ( & V_149 ) ;
F_147 ( & V_149 ) ;
F_67 ( & V_149 , NULL ) ;
}
V_306:
F_35 ( V_6 ) ;
}
static int F_148 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_348 V_317 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
T_1 V_159 , V_349 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_347 ,
V_302 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_347 ,
V_288 ) ;
if ( ! F_20 ( V_6 , V_108 ) ) {
if ( V_151 -> V_159 == 0x01 )
return F_88 ( V_15 , V_347 , V_6 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_347 ,
V_303 ) ;
}
F_34 ( V_6 ) ;
V_159 = ! ! V_151 -> V_159 ;
V_349 = F_149 ( V_6 ) ;
if ( ! V_159 )
F_102 ( V_6 , NULL , 0x00 , true ) ;
if ( ! F_42 ( V_6 ) || V_159 == V_349 ) {
bool V_305 = false ;
if ( V_159 != F_20 ( V_6 , V_109 ) ) {
F_130 ( V_6 , V_109 ) ;
V_305 = true ;
}
if ( ! V_159 && F_20 ( V_6 , V_113 ) ) {
F_76 ( V_6 , V_113 ) ;
V_305 = true ;
}
V_30 = F_88 ( V_15 , V_347 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_306;
}
if ( F_47 ( V_347 , V_6 ) ||
F_47 ( V_350 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_347 ,
V_289 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_347 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
if ( V_159 ) {
V_317 . V_351 = V_159 ;
V_317 . V_352 = 0x00 ;
} else {
if ( F_20 ( V_6 , V_204 ) )
F_73 ( & V_149 ) ;
}
F_56 ( & V_149 , V_353 , sizeof( V_317 ) ,
& V_317 ) ;
V_30 = F_67 ( & V_149 , F_144 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_150 ( struct V_5 * V_6 )
{
struct V_133 * V_155 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
switch ( V_155 -> V_37 ) {
case V_354 :
case V_355 :
case V_356 :
case V_287 :
return true ;
}
}
return false ;
}
static T_1 F_151 ( const T_1 * V_123 )
{
T_6 V_159 ;
if ( memcmp ( V_123 , V_357 , 12 ) )
return 128 ;
V_159 = F_152 ( & V_123 [ 12 ] ) ;
if ( V_159 > 0xffff )
return 32 ;
return 16 ;
}
static void F_153 ( struct V_5 * V_6 , T_2 V_358 , T_1 V_226 )
{
struct V_133 * V_155 ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_358 , V_6 ) ;
if ( ! V_155 )
goto V_306;
F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 ,
F_1 ( V_226 ) , V_6 -> V_196 , 3 ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static void F_154 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
F_9 ( L_8 , V_226 ) ;
F_153 ( V_6 , V_354 , V_226 ) ;
}
static int F_155 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_359 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
struct V_122 * V_123 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( F_150 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_354 ,
V_289 ) ;
goto V_290;
}
V_123 = F_14 ( sizeof( * V_123 ) , V_35 ) ;
if ( ! V_123 ) {
V_30 = - V_36 ;
goto V_290;
}
memcpy ( V_123 -> V_123 , V_151 -> V_123 , 16 ) ;
V_123 -> V_192 = V_151 -> V_192 ;
V_123 -> V_125 = F_151 ( V_151 -> V_123 ) ;
F_156 ( & V_123 -> V_298 , & V_6 -> V_360 ) ;
F_66 ( & V_149 , V_6 ) ;
F_72 ( & V_149 ) ;
F_69 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_154 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_294 )
goto V_290;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_354 , 0 ,
V_6 -> V_196 , 3 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_354 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
V_30 = 0 ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_157 ( struct V_5 * V_6 )
{
if ( ! F_42 ( V_6 ) )
return false ;
if ( ! F_84 ( V_6 , V_189 ) ) {
F_99 ( V_6 -> V_255 , & V_6 -> V_218 ,
V_361 ) ;
return true ;
}
return false ;
}
static void F_158 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
F_9 ( L_8 , V_226 ) ;
F_153 ( V_6 , V_355 , V_226 ) ;
}
static int F_159 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_362 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_122 * V_297 , * V_363 ;
T_1 V_364 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_148 V_149 ;
int V_30 , V_365 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( F_150 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_355 ,
V_289 ) ;
goto V_306;
}
if ( memcmp ( V_151 -> V_123 , V_364 , 16 ) == 0 ) {
F_160 ( V_6 ) ;
if ( F_157 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_355 ,
0 , V_6 -> V_196 , 3 ) ;
goto V_306;
}
goto F_72;
}
V_365 = 0 ;
F_104 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_297 -> V_123 , V_151 -> V_123 , 16 ) != 0 )
continue;
F_116 ( & V_297 -> V_298 ) ;
F_16 ( V_297 ) ;
V_365 ++ ;
}
if ( V_365 == 0 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_355 ,
V_288 ) ;
goto V_306;
}
F_72:
F_66 ( & V_149 , V_6 ) ;
F_72 ( & V_149 ) ;
F_69 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_158 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_294 )
goto V_306;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_355 , 0 ,
V_6 -> V_196 , 3 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_355 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_30 = 0 ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_161 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
F_9 ( L_8 , V_226 ) ;
F_153 ( V_6 , V_356 , V_226 ) ;
}
static int F_162 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_366 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_37 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_356 ,
V_302 ) ;
F_34 ( V_6 ) ;
if ( F_150 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_356 ,
V_289 ) ;
goto V_306;
}
if ( ( V_151 -> V_367 & 0x03 ) != 0 || ( V_151 -> V_368 & 0xe0 ) != 0 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_356 ,
V_288 ) ;
goto V_306;
}
V_6 -> V_195 = V_151 -> V_368 ;
V_6 -> V_194 = V_151 -> V_367 ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_356 , 0 ,
V_6 -> V_196 , 3 ) ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
if ( F_80 ( V_6 , V_189 ) ) {
F_35 ( V_6 ) ;
F_163 ( & V_6 -> V_218 ) ;
F_34 ( V_6 ) ;
F_69 ( & V_149 ) ;
}
F_72 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_161 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_294 )
goto V_306;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_356 , 0 ,
V_6 -> V_196 , 3 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_356 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_30 = 0 ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_164 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_369 * V_151 = V_7 ;
const T_2 V_370 = ( ( V_371 - sizeof( * V_151 ) ) /
sizeof( struct V_372 ) ) ;
T_2 V_373 , V_374 ;
bool V_305 ;
int V_29 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_37 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_375 ,
V_302 ) ;
V_373 = F_129 ( V_151 -> V_373 ) ;
if ( V_373 > V_370 ) {
F_165 ( L_9 ,
V_373 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_375 ,
V_288 ) ;
}
V_374 = sizeof( * V_151 ) + V_373 *
sizeof( struct V_372 ) ;
if ( V_374 != V_8 ) {
F_165 ( L_10 ,
V_374 , V_8 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_375 ,
V_288 ) ;
}
if ( V_151 -> V_376 != 0x00 && V_151 -> V_376 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_375 ,
V_288 ) ;
F_9 ( L_11 , V_6 -> V_79 , V_151 -> V_376 ,
V_373 ) ;
for ( V_29 = 0 ; V_29 < V_373 ; V_29 ++ ) {
struct V_372 * V_377 = & V_151 -> V_378 [ V_29 ] ;
if ( V_377 -> V_379 . type != V_380 || V_377 -> type > 0x08 )
return F_110 ( V_15 , V_6 -> V_55 ,
V_375 ,
V_288 ) ;
}
F_34 ( V_6 ) ;
F_166 ( V_6 ) ;
if ( V_151 -> V_376 )
V_305 = ! F_84 ( V_6 , V_115 ) ;
else
V_305 = F_80 ( V_6 ,
V_115 ) ;
if ( V_305 )
F_113 ( V_6 , NULL ) ;
for ( V_29 = 0 ; V_29 < V_373 ; V_29 ++ ) {
struct V_372 * V_377 = & V_151 -> V_378 [ V_29 ] ;
if ( V_377 -> type == V_381 )
continue;
F_167 ( V_6 , NULL , & V_377 -> V_379 . V_118 , V_377 -> V_159 ,
V_377 -> type , V_377 -> V_382 , NULL ) ;
}
F_11 ( V_15 , V_6 -> V_55 , V_375 , 0 , NULL , 0 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
static int F_168 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_383 , struct V_11 * V_12 )
{
struct V_384 V_243 ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = V_383 ;
return F_7 ( V_385 , V_6 , & V_243 , sizeof( V_243 ) ,
V_12 ) ;
}
static int F_169 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_386 * V_151 = V_7 ;
struct V_387 V_18 ;
struct V_268 V_269 ;
struct V_133 * V_155 ;
struct V_261 * V_262 ;
int V_30 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_87 ( & V_18 . V_379 . V_118 , & V_151 -> V_379 . V_118 ) ;
V_18 . V_379 . type = V_151 -> V_379 . type ;
if ( ! F_170 ( V_151 -> V_379 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_388 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_151 -> V_389 != 0x00 && V_151 -> V_389 != 0x01 )
return F_11 ( V_15 , V_6 -> V_55 , V_388 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_388 ,
V_313 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
if ( V_151 -> V_379 . type == V_380 ) {
if ( V_151 -> V_389 )
V_262 = F_171 ( V_6 , V_279 ,
& V_151 -> V_379 . V_118 ) ;
else
V_262 = NULL ;
V_30 = F_172 ( V_6 , & V_151 -> V_379 . V_118 ) ;
} else {
T_1 V_383 ;
V_262 = F_171 ( V_6 , V_203 ,
& V_151 -> V_379 . V_118 ) ;
if ( V_262 ) {
F_173 ( V_390 , & V_262 -> V_164 ) ;
if ( ! V_151 -> V_389 )
V_262 = NULL ;
}
if ( V_151 -> V_379 . type == V_391 )
V_383 = V_392 ;
else
V_383 = V_393 ;
F_174 ( V_6 , & V_151 -> V_379 . V_118 , V_383 ) ;
V_30 = F_175 ( V_6 , & V_151 -> V_379 . V_118 , V_383 ) ;
}
if ( V_30 < 0 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_388 ,
V_394 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
if ( ! V_262 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_388 , 0 ,
& V_18 , sizeof( V_18 ) ) ;
F_168 ( V_6 , & V_151 -> V_379 . V_118 , V_151 -> V_379 . type , V_15 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_388 , V_6 , V_151 ,
sizeof( * V_151 ) ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_155 -> V_299 = F_123 ;
V_269 . V_274 = F_10 ( V_262 -> V_274 ) ;
V_269 . V_275 = 0x13 ;
V_30 = F_141 ( V_6 , V_276 , sizeof( V_269 ) , & V_269 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int V_389 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_395 * V_151 = V_7 ;
struct V_396 V_18 ;
struct V_133 * V_155 ;
struct V_261 * V_262 ;
int V_30 ;
F_9 ( L_5 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_87 ( & V_18 . V_379 . V_118 , & V_151 -> V_379 . V_118 ) ;
V_18 . V_379 . type = V_151 -> V_379 . type ;
if ( ! F_170 ( V_151 -> V_379 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_397 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_22 ( V_398 , & V_6 -> V_164 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_397 ,
V_313 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_290;
}
if ( F_47 ( V_397 , V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_397 ,
V_289 , & V_18 , sizeof( V_18 ) ) ;
goto V_290;
}
if ( V_151 -> V_379 . type == V_380 )
V_262 = F_171 ( V_6 , V_279 ,
& V_151 -> V_379 . V_118 ) ;
else
V_262 = F_171 ( V_6 , V_203 , & V_151 -> V_379 . V_118 ) ;
if ( ! V_262 || V_262 -> V_233 == V_399 || V_262 -> V_233 == V_400 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_397 ,
V_401 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_397 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
V_155 -> V_299 = F_122 ;
V_30 = F_176 ( V_262 , V_402 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static T_1 F_177 ( T_1 V_403 , T_1 V_383 )
{
switch ( V_403 ) {
case V_203 :
switch ( V_383 ) {
case V_392 :
return V_391 ;
default:
return V_404 ;
}
default:
return V_380 ;
}
}
static int F_178 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_16 )
{
struct V_405 * V_18 ;
struct V_261 * V_406 ;
T_3 V_42 ;
int V_30 ;
T_2 V_29 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_407 ,
V_313 ) ;
goto V_306;
}
V_29 = 0 ;
F_19 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_408 , & V_406 -> V_164 ) )
V_29 ++ ;
}
V_42 = sizeof( * V_18 ) + ( V_29 * sizeof( struct V_301 ) ) ;
V_18 = F_14 ( V_42 , V_35 ) ;
if ( ! V_18 ) {
V_30 = - V_36 ;
goto V_306;
}
V_29 = 0 ;
F_19 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_408 , & V_406 -> V_164 ) )
continue;
F_87 ( & V_18 -> V_379 [ V_29 ] . V_118 , & V_406 -> V_281 ) ;
V_18 -> V_379 [ V_29 ] . type = F_177 ( V_406 -> type , V_406 -> V_409 ) ;
if ( V_406 -> type == V_284 || V_406 -> type == V_410 )
continue;
V_29 ++ ;
}
V_18 -> V_411 = F_10 ( V_29 ) ;
V_42 = sizeof( * V_18 ) + ( V_29 * sizeof( struct V_301 ) ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_407 , 0 , V_18 ,
V_42 ) ;
F_16 ( V_18 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_179 ( struct V_11 * V_15 , struct V_5 * V_6 ,
struct V_412 * V_151 )
{
struct V_133 * V_155 ;
int V_30 ;
V_155 = F_111 ( V_15 , V_413 , V_6 , V_151 ,
sizeof( * V_151 ) ) ;
if ( ! V_155 )
return - V_36 ;
V_30 = F_141 ( V_6 , V_414 ,
sizeof( V_151 -> V_379 . V_118 ) , & V_151 -> V_379 . V_118 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
return V_30 ;
}
static int F_180 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_261 * V_262 ;
struct V_415 * V_151 = V_7 ;
struct V_416 V_417 ;
struct V_133 * V_155 ;
int V_30 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_418 ,
V_313 ) ;
goto V_290;
}
V_262 = F_171 ( V_6 , V_279 , & V_151 -> V_379 . V_118 ) ;
if ( ! V_262 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_418 ,
V_401 ) ;
goto V_290;
}
if ( V_262 -> V_419 == V_420 && V_151 -> V_382 != 16 ) {
struct V_412 V_421 ;
memcpy ( & V_421 . V_379 , & V_151 -> V_379 , sizeof( V_421 . V_379 ) ) ;
F_165 ( L_12 ) ;
V_30 = F_179 ( V_15 , V_6 , & V_421 ) ;
if ( V_30 >= 0 )
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_418 ,
V_288 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_418 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
V_155 -> V_299 = F_123 ;
F_87 ( & V_417 . V_118 , & V_151 -> V_379 . V_118 ) ;
V_417 . V_382 = V_151 -> V_382 ;
memcpy ( V_417 . V_422 , V_151 -> V_422 , sizeof( V_417 . V_422 ) ) ;
V_30 = F_141 ( V_6 , V_423 , sizeof( V_417 ) , & V_417 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_181 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_424 * V_151 = V_7 ;
F_9 ( L_5 ) ;
if ( V_151 -> V_425 > V_426 )
return F_11 ( V_15 , V_6 -> V_55 , V_427 ,
V_288 , NULL , 0 ) ;
F_34 ( V_6 ) ;
V_6 -> V_425 = V_151 -> V_425 ;
F_9 ( L_13 , V_6 -> V_79 ,
V_6 -> V_425 ) ;
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_427 , 0 ,
NULL , 0 ) ;
}
static struct V_133 * F_182 ( struct V_261 * V_262 )
{
struct V_5 * V_6 = V_262 -> V_6 ;
struct V_133 * V_155 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
if ( V_155 -> V_37 != V_428 )
continue;
if ( V_155 -> V_429 != V_262 )
continue;
return V_155 ;
}
return NULL ;
}
static int F_183 ( struct V_133 * V_155 , T_1 V_226 )
{
struct V_430 V_18 ;
struct V_261 * V_262 = V_155 -> V_429 ;
int V_30 ;
F_87 ( & V_18 . V_379 . V_118 , & V_262 -> V_281 ) ;
V_18 . V_379 . type = F_177 ( V_262 -> type , V_262 -> V_409 ) ;
V_30 = F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_428 ,
V_226 , & V_18 , sizeof( V_18 ) ) ;
V_262 -> V_431 = NULL ;
V_262 -> V_432 = NULL ;
V_262 -> V_433 = NULL ;
F_184 ( V_262 ) ;
F_185 ( V_390 , & V_262 -> V_164 ) ;
F_186 ( V_262 ) ;
return V_30 ;
}
void F_187 ( struct V_261 * V_262 , bool V_434 )
{
T_1 V_226 = V_434 ? V_304 : V_3 ;
struct V_133 * V_155 ;
V_155 = F_182 ( V_262 ) ;
if ( V_155 ) {
V_155 -> V_299 ( V_155 , V_226 ) ;
F_120 ( V_155 ) ;
}
}
static void F_188 ( struct V_261 * V_262 , T_1 V_226 )
{
struct V_133 * V_155 ;
F_9 ( L_14 , V_226 ) ;
V_155 = F_182 ( V_262 ) ;
if ( ! V_155 ) {
F_9 ( L_15 ) ;
return;
}
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
static void F_189 ( struct V_261 * V_262 , T_1 V_226 )
{
struct V_133 * V_155 ;
F_9 ( L_14 , V_226 ) ;
if ( ! V_226 )
return;
V_155 = F_182 ( V_262 ) ;
if ( ! V_155 ) {
F_9 ( L_15 ) ;
return;
}
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
static int F_190 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_435 * V_151 = V_7 ;
struct V_430 V_18 ;
struct V_133 * V_155 ;
T_1 V_436 , V_437 ;
struct V_261 * V_262 ;
int V_30 ;
F_9 ( L_5 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_87 ( & V_18 . V_379 . V_118 , & V_151 -> V_379 . V_118 ) ;
V_18 . V_379 . type = V_151 -> V_379 . type ;
if ( ! F_170 ( V_151 -> V_379 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_428 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_151 -> V_438 > V_426 )
return F_11 ( V_15 , V_6 -> V_55 , V_428 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_428 ,
V_313 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
if ( F_191 ( V_6 , & V_151 -> V_379 . V_118 , V_151 -> V_379 . type ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_428 ,
V_439 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
V_436 = V_440 ;
V_437 = V_441 ;
if ( V_151 -> V_379 . type == V_380 ) {
V_262 = F_192 ( V_6 , & V_151 -> V_379 . V_118 , V_436 ,
V_437 ) ;
} else {
T_1 V_383 ;
if ( V_151 -> V_379 . type == V_391 )
V_383 = V_392 ;
else
V_383 = V_393 ;
F_193 ( V_6 , & V_151 -> V_379 . V_118 , V_383 ) ;
V_262 = F_194 ( V_6 , & V_151 -> V_379 . V_118 , V_383 ,
V_436 , V_442 ,
V_443 ) ;
}
if ( F_195 ( V_262 ) ) {
int V_226 ;
if ( F_196 ( V_262 ) == - V_251 )
V_226 = V_289 ;
else if ( F_196 ( V_262 ) == - V_444 )
V_226 = V_302 ;
else if ( F_196 ( V_262 ) == - V_445 )
V_226 = V_303 ;
else
V_226 = V_446 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_428 ,
V_226 , & V_18 , sizeof( V_18 ) ) ;
goto V_306;
}
if ( V_262 -> V_431 ) {
F_184 ( V_262 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_428 ,
V_289 , & V_18 , sizeof( V_18 ) ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_428 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
F_184 ( V_262 ) ;
goto V_306;
}
V_155 -> V_299 = F_183 ;
if ( V_151 -> V_379 . type == V_380 ) {
V_262 -> V_431 = F_188 ;
V_262 -> V_432 = F_188 ;
V_262 -> V_433 = F_188 ;
} else {
V_262 -> V_431 = F_189 ;
V_262 -> V_432 = F_189 ;
V_262 -> V_433 = F_189 ;
}
V_262 -> V_425 = V_151 -> V_438 ;
V_155 -> V_429 = F_197 ( V_262 ) ;
if ( ( V_262 -> V_233 == V_272 || V_262 -> V_233 == V_273 ) &&
F_198 ( V_262 , V_436 , V_437 , true ) ) {
V_155 -> V_299 ( V_155 , 0 ) ;
F_120 ( V_155 ) ;
}
V_30 = 0 ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_199 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_301 * V_379 = V_7 ;
struct V_133 * V_155 ;
struct V_261 * V_262 ;
int V_30 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_447 ,
V_313 ) ;
goto V_306;
}
V_155 = F_47 ( V_428 , V_6 ) ;
if ( ! V_155 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_447 ,
V_288 ) ;
goto V_306;
}
V_262 = V_155 -> V_429 ;
if ( F_28 ( & V_379 -> V_118 , & V_262 -> V_281 ) != 0 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_447 ,
V_288 ) ;
goto V_306;
}
V_155 -> V_299 ( V_155 , V_448 ) ;
F_120 ( V_155 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_447 , 0 ,
V_379 , sizeof( * V_379 ) ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_200 ( struct V_11 * V_15 , struct V_5 * V_6 ,
struct V_301 * V_379 , T_2 V_358 ,
T_2 V_449 , T_5 V_450 )
{
struct V_133 * V_155 ;
struct V_261 * V_262 ;
int V_30 ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_358 ,
V_313 , V_379 ,
sizeof( * V_379 ) ) ;
goto V_451;
}
if ( V_379 -> type == V_380 )
V_262 = F_171 ( V_6 , V_279 , & V_379 -> V_118 ) ;
else
V_262 = F_171 ( V_6 , V_203 , & V_379 -> V_118 ) ;
if ( ! V_262 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_358 ,
V_401 , V_379 ,
sizeof( * V_379 ) ) ;
goto V_451;
}
if ( V_379 -> type == V_391 || V_379 -> type == V_404 ) {
V_30 = F_201 ( V_262 , V_358 , V_450 ) ;
if ( ! V_30 )
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_358 ,
V_304 , V_379 ,
sizeof( * V_379 ) ) ;
else
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_358 ,
V_3 , V_379 ,
sizeof( * V_379 ) ) ;
goto V_451;
}
V_155 = F_111 ( V_15 , V_358 , V_6 , V_379 , sizeof( * V_379 ) ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_451;
}
V_155 -> V_299 = F_123 ;
if ( V_449 == V_452 ) {
struct V_453 V_151 ;
F_87 ( & V_151 . V_118 , & V_379 -> V_118 ) ;
V_151 . V_450 = V_450 ;
V_30 = F_141 ( V_6 , V_449 , sizeof( V_151 ) , & V_151 ) ;
} else
V_30 = F_141 ( V_6 , V_449 , sizeof( V_379 -> V_118 ) ,
& V_379 -> V_118 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_451:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_202 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_412 * V_151 = V_7 ;
F_9 ( L_5 ) ;
return F_200 ( V_15 , V_6 , & V_151 -> V_379 ,
V_413 ,
V_414 , 0 ) ;
}
static int F_203 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_454 * V_151 = V_7 ;
F_9 ( L_5 ) ;
if ( V_8 != sizeof( * V_151 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_455 ,
V_288 ) ;
return F_200 ( V_15 , V_6 , & V_151 -> V_379 ,
V_455 ,
V_456 , 0 ) ;
}
static int F_204 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_457 * V_151 = V_7 ;
F_9 ( L_5 ) ;
return F_200 ( V_15 , V_6 , & V_151 -> V_379 ,
V_458 ,
V_459 , 0 ) ;
}
static int F_205 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_460 * V_151 = V_7 ;
F_9 ( L_5 ) ;
return F_200 ( V_15 , V_6 , & V_151 -> V_379 ,
V_461 ,
V_452 , V_151 -> V_450 ) ;
}
static int F_206 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_462 * V_151 = V_7 ;
F_9 ( L_5 ) ;
return F_200 ( V_15 , V_6 , & V_151 -> V_379 ,
V_463 ,
V_464 , 0 ) ;
}
static void F_207 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_465 V_151 ;
memcpy ( V_151 . V_79 , V_6 -> V_138 , sizeof( V_151 . V_79 ) ) ;
F_56 ( V_149 , V_466 , sizeof( V_151 ) , & V_151 ) ;
}
static void F_208 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_467 * V_151 ;
struct V_133 * V_155 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_468 , V_6 ) ;
if ( ! V_155 )
goto V_306;
V_151 = V_155 -> V_158 ;
if ( V_226 )
F_110 ( V_155 -> V_15 , V_6 -> V_55 , V_468 ,
F_1 ( V_226 ) ) ;
else
F_11 ( V_155 -> V_15 , V_6 -> V_55 , V_468 , 0 ,
V_151 , sizeof( * V_151 ) ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_209 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_467 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_5 ) ;
F_34 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_138 , V_151 -> V_79 , sizeof( V_6 -> V_138 ) ) &&
! memcmp ( V_6 -> V_224 , V_151 -> V_224 ,
sizeof( V_6 -> V_224 ) ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_468 , 0 ,
V_7 , V_8 ) ;
goto V_290;
}
memcpy ( V_6 -> V_224 , V_151 -> V_224 , sizeof( V_6 -> V_224 ) ) ;
if ( ! F_42 ( V_6 ) ) {
memcpy ( V_6 -> V_138 , V_151 -> V_79 , sizeof( V_6 -> V_138 ) ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_468 , 0 ,
V_7 , V_8 ) ;
if ( V_30 < 0 )
goto V_290;
V_30 = F_6 ( V_469 , V_6 ,
V_7 , V_8 , V_15 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_468 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
memcpy ( V_6 -> V_138 , V_151 -> V_79 , sizeof( V_6 -> V_138 ) ) ;
F_66 ( & V_149 , V_6 ) ;
if ( F_37 ( V_6 ) ) {
F_207 ( & V_149 ) ;
F_69 ( & V_149 ) ;
}
if ( F_40 ( V_6 ) )
F_57 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_208 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_210 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 , struct V_470 * V_471 )
{
struct V_472 V_473 ;
T_3 V_28 = sizeof( V_473 ) ;
struct V_133 * V_155 ;
F_9 ( L_16 , V_6 -> V_79 , V_226 ) ;
V_155 = F_47 ( V_474 , V_6 ) ;
if ( ! V_155 )
return;
if ( V_226 || ! V_471 ) {
F_110 ( V_155 -> V_15 , V_6 -> V_55 , V_474 ,
V_226 ? F_1 ( V_226 ) : V_3 ) ;
goto remove;
}
memset ( & V_473 , 0 , sizeof( V_473 ) ) ;
if ( V_37 == V_475 ) {
struct V_476 * V_18 = ( void * ) V_471 -> V_7 ;
if ( V_471 -> V_8 < sizeof( * V_18 ) ) {
F_110 ( V_155 -> V_15 , V_6 -> V_55 ,
V_474 ,
V_3 ) ;
goto remove;
}
memcpy ( V_473 . V_477 , V_18 -> V_478 , sizeof( V_18 -> V_478 ) ) ;
memcpy ( V_473 . V_479 , V_18 -> rand , sizeof( V_18 -> rand ) ) ;
V_28 -= sizeof( V_473 . V_480 ) + sizeof( V_473 . V_481 ) ;
} else {
struct V_482 * V_18 = ( void * ) V_471 -> V_7 ;
if ( V_471 -> V_8 < sizeof( * V_18 ) ) {
F_110 ( V_155 -> V_15 , V_6 -> V_55 ,
V_474 ,
V_3 ) ;
goto remove;
}
memcpy ( V_473 . V_477 , V_18 -> V_477 , sizeof( V_18 -> V_477 ) ) ;
memcpy ( V_473 . V_479 , V_18 -> V_479 , sizeof( V_18 -> V_479 ) ) ;
memcpy ( V_473 . V_480 , V_18 -> V_480 , sizeof( V_18 -> V_480 ) ) ;
memcpy ( V_473 . V_481 , V_18 -> V_481 , sizeof( V_18 -> V_481 ) ) ;
}
F_11 ( V_155 -> V_15 , V_6 -> V_55 , V_474 ,
V_304 , & V_473 , V_28 ) ;
remove:
F_120 ( V_155 ) ;
}
static int F_211 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_474 ,
V_313 ) ;
goto V_306;
}
if ( ! F_38 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_474 ,
V_302 ) ;
goto V_306;
}
if ( F_47 ( V_474 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_474 ,
V_289 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_474 , V_6 , NULL , 0 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
if ( F_212 ( V_6 ) )
F_56 ( & V_149 , V_483 , 0 , NULL ) ;
else
F_56 ( & V_149 , V_475 , 0 , NULL ) ;
V_30 = F_213 ( & V_149 , F_210 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_214 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_301 * V_379 = V_7 ;
int V_30 ;
F_9 ( L_17 , V_6 -> V_79 ) ;
if ( ! F_170 ( V_379 -> type ) )
return F_11 ( V_15 , V_6 -> V_55 ,
V_484 ,
V_288 ,
V_379 , sizeof( * V_379 ) ) ;
F_34 ( V_6 ) ;
if ( V_8 == V_485 ) {
struct V_486 * V_151 = V_7 ;
T_1 V_226 ;
if ( V_151 -> V_379 . type != V_380 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_484 ,
V_288 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
goto V_306;
}
V_30 = F_215 ( V_6 , & V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type , V_151 -> V_478 ,
V_151 -> rand , NULL , NULL ) ;
if ( V_30 < 0 )
V_226 = V_3 ;
else
V_226 = V_304 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_484 , V_226 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
} else if ( V_8 == V_487 ) {
struct V_488 * V_151 = V_7 ;
T_1 * V_479 , * V_477 , * V_481 , * V_480 ;
T_1 V_226 ;
if ( F_216 ( V_151 -> V_379 . type ) ) {
if ( memcmp ( V_151 -> V_479 , V_489 , 16 ) ||
memcmp ( V_151 -> V_477 , V_489 , 16 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_484 ,
V_288 ,
V_379 , sizeof( * V_379 ) ) ;
goto V_306;
}
V_479 = NULL ;
V_477 = NULL ;
} else {
if ( ! memcmp ( V_151 -> V_479 , V_489 , 16 ) ||
! memcmp ( V_151 -> V_477 , V_489 , 16 ) ) {
V_479 = NULL ;
V_477 = NULL ;
} else {
V_479 = V_151 -> V_479 ;
V_477 = V_151 -> V_477 ;
}
}
if ( ! memcmp ( V_151 -> V_481 , V_489 , 16 ) ||
! memcmp ( V_151 -> V_480 , V_489 , 16 ) ) {
V_481 = NULL ;
V_480 = NULL ;
} else {
V_481 = V_151 -> V_481 ;
V_480 = V_151 -> V_480 ;
}
V_30 = F_215 ( V_6 , & V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type , V_477 , V_479 ,
V_480 , V_481 ) ;
if ( V_30 < 0 )
V_226 = V_3 ;
else
V_226 = V_304 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_484 ,
V_226 , & V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
} else {
F_165 ( L_18 , V_8 ) ;
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_484 ,
V_288 ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_217 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_490 * V_151 = V_7 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( V_151 -> V_379 . type != V_380 )
return F_11 ( V_15 , V_6 -> V_55 ,
V_491 ,
V_288 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_28 ( & V_151 -> V_379 . V_118 , V_72 ) ) {
F_218 ( V_6 ) ;
V_226 = V_304 ;
goto V_451;
}
V_30 = F_219 ( V_6 , & V_151 -> V_379 . V_118 , V_151 -> V_379 . type ) ;
if ( V_30 < 0 )
V_226 = V_288 ;
else
V_226 = V_304 ;
V_451:
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_491 ,
V_226 , & V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_220 ( struct V_148 * V_149 , T_1 * V_226 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_492 V_151 ;
T_1 V_493 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
* V_226 = F_124 ( V_6 ) ;
if ( * V_226 )
return false ;
if ( F_20 ( V_6 , V_235 ) ) {
* V_226 = V_289 ;
return false ;
}
F_221 ( V_6 ) ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
memcpy ( & V_151 . V_493 , V_493 , sizeof( V_151 . V_493 ) ) ;
V_151 . V_153 = V_494 ;
F_56 ( V_149 , V_495 , sizeof( V_151 ) , & V_151 ) ;
return true ;
}
static bool F_222 ( struct V_148 * V_149 , T_2 V_325 , T_1 * V_226 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_496 V_497 ;
struct V_498 V_499 ;
T_1 V_201 ;
int V_30 ;
* V_226 = F_125 ( V_6 ) ;
if ( * V_226 )
return false ;
if ( F_20 ( V_6 , V_204 ) ) {
if ( F_223 ( V_6 , V_203 , V_277 ) ) {
* V_226 = V_303 ;
return false ;
}
F_101 ( V_6 ) ;
F_73 ( V_149 ) ;
}
if ( F_20 ( V_6 , V_237 ) )
F_94 ( V_149 ) ;
V_30 = F_77 ( V_149 , true , & V_201 ) ;
if ( V_30 < 0 ) {
* V_226 = V_3 ;
return false ;
}
memset ( & V_497 , 0 , sizeof( V_497 ) ) ;
V_497 . type = V_500 ;
V_497 . V_325 = F_10 ( V_325 ) ;
V_497 . V_327 = F_10 ( V_501 ) ;
V_497 . V_212 = V_201 ;
F_56 ( V_149 , V_502 , sizeof( V_497 ) ,
& V_497 ) ;
memset ( & V_499 , 0 , sizeof( V_499 ) ) ;
V_499 . V_198 = V_503 ;
V_499 . V_504 = V_505 ;
F_56 ( V_149 , V_506 , sizeof( V_499 ) ,
& V_499 ) ;
return true ;
}
static bool F_224 ( struct V_148 * V_149 , T_1 * V_226 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
switch ( V_6 -> V_232 . type ) {
case V_507 :
if ( ! F_220 ( V_149 , V_226 ) )
return false ;
break;
case V_508 :
if ( F_22 ( V_509 ,
& V_6 -> V_53 ) ) {
if ( ! F_222 ( V_149 , V_510 * 2 ,
V_226 ) )
return false ;
if ( ! F_220 ( V_149 , V_226 ) )
return false ;
return true ;
}
if ( ! F_20 ( V_6 , V_108 ) ) {
* V_226 = V_302 ;
return false ;
}
case V_511 :
if ( ! F_222 ( V_149 , V_510 , V_226 ) )
return false ;
break;
default:
* V_226 = V_288 ;
return false ;
}
return true ;
}
static void F_225 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_133 * V_155 ;
unsigned long V_248 ;
F_9 ( L_19 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_512 , V_6 ) ;
if ( ! V_155 )
V_155 = F_47 ( V_513 , V_6 ) ;
if ( V_155 ) {
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
if ( V_226 ) {
F_108 ( V_6 , V_514 ) ;
goto V_306;
}
F_108 ( V_6 , V_234 ) ;
switch ( V_6 -> V_232 . type ) {
case V_511 :
V_248 = F_100 ( V_515 ) ;
break;
case V_508 :
if ( F_22 ( V_509 , & V_6 -> V_53 ) )
V_248 = F_100 ( V_515 ) ;
else
V_248 = F_100 ( V_6 -> V_516 ) ;
break;
case V_507 :
V_248 = 0 ;
break;
default:
F_165 ( L_20 , V_6 -> V_232 . type ) ;
V_248 = 0 ;
break;
}
if ( V_248 ) {
if ( F_22 ( V_517 ,
& V_6 -> V_53 ) &&
V_6 -> V_232 . V_518 ) {
V_6 -> V_232 . V_519 = V_520 ;
V_6 -> V_232 . V_521 = V_248 ;
}
F_99 ( V_6 -> V_255 ,
& V_6 -> V_238 , V_248 ) ;
}
V_306:
F_35 ( V_6 ) ;
}
static int F_226 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_522 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_512 ,
V_313 ,
& V_151 -> type , sizeof( V_151 -> type ) ) ;
goto V_290;
}
if ( V_6 -> V_232 . V_233 != V_514 ||
F_20 ( V_6 , V_523 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_512 ,
V_289 , & V_151 -> type ,
sizeof( V_151 -> type ) ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_512 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
V_155 -> V_299 = F_122 ;
F_227 ( V_6 ) ;
V_6 -> V_232 . type = V_151 -> type ;
V_6 -> V_232 . V_524 = false ;
F_66 ( & V_149 , V_6 ) ;
if ( ! F_224 ( & V_149 , & V_226 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_512 ,
V_226 , & V_151 -> type , sizeof( V_151 -> type ) ) ;
F_120 ( V_155 ) ;
goto V_290;
}
V_30 = F_67 ( & V_149 , F_225 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
goto V_290;
}
F_108 ( V_6 , V_525 ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_228 ( struct V_133 * V_155 ,
T_1 V_226 )
{
return F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_226 ,
V_155 -> V_158 , 1 ) ;
}
static int F_229 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_526 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
const T_2 V_527 = ( ( V_371 - sizeof( * V_151 ) ) / 16 ) ;
T_2 V_528 , V_374 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_513 ,
V_313 ,
& V_151 -> type , sizeof( V_151 -> type ) ) ;
goto V_290;
}
if ( V_6 -> V_232 . V_233 != V_514 ||
F_20 ( V_6 , V_523 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_513 ,
V_289 , & V_151 -> type ,
sizeof( V_151 -> type ) ) ;
goto V_290;
}
V_528 = F_129 ( V_151 -> V_528 ) ;
if ( V_528 > V_527 ) {
F_165 ( L_21 ,
V_528 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_513 ,
V_288 , & V_151 -> type ,
sizeof( V_151 -> type ) ) ;
goto V_290;
}
V_374 = sizeof( * V_151 ) + V_528 * 16 ;
if ( V_374 != V_8 ) {
F_165 ( L_22 ,
V_374 , V_8 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_513 ,
V_288 , & V_151 -> type ,
sizeof( V_151 -> type ) ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_513 ,
V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
V_155 -> V_299 = F_228 ;
F_227 ( V_6 ) ;
V_6 -> V_232 . V_518 = true ;
V_6 -> V_232 . type = V_151 -> type ;
V_6 -> V_232 . V_529 = V_151 -> V_529 ;
V_6 -> V_232 . V_528 = V_528 ;
if ( V_528 > 0 ) {
V_6 -> V_232 . V_360 = F_230 ( V_151 -> V_360 , V_528 * 16 ,
V_35 ) ;
if ( ! V_6 -> V_232 . V_360 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_513 ,
V_3 ,
& V_151 -> type , sizeof( V_151 -> type ) ) ;
F_120 ( V_155 ) ;
goto V_290;
}
}
F_66 ( & V_149 , V_6 ) ;
if ( ! F_224 ( & V_149 , & V_226 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_513 ,
V_226 , & V_151 -> type , sizeof( V_151 -> type ) ) ;
F_120 ( V_155 ) ;
goto V_290;
}
V_30 = F_67 ( & V_149 , F_225 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
goto V_290;
}
F_108 ( V_6 , V_525 ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_231 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_133 * V_155 ;
F_9 ( L_19 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_530 , V_6 ) ;
if ( V_155 ) {
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
if ( ! V_226 )
F_108 ( V_6 , V_514 ) ;
F_35 ( V_6 ) ;
}
static int F_232 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_531 * V_532 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_233 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_530 ,
V_303 , & V_532 -> type ,
sizeof( V_532 -> type ) ) ;
goto V_306;
}
if ( V_6 -> V_232 . type != V_532 -> type ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_530 ,
V_288 ,
& V_532 -> type , sizeof( V_532 -> type ) ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_530 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_155 -> V_299 = F_122 ;
F_66 ( & V_149 , V_6 ) ;
F_93 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_231 ) ;
if ( ! V_30 ) {
F_108 ( V_6 , V_286 ) ;
goto V_306;
}
F_120 ( V_155 ) ;
if ( V_30 == - V_294 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_530 , 0 ,
& V_532 -> type , sizeof( V_532 -> type ) ) ;
F_108 ( V_6 , V_514 ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_234 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_533 * V_151 = V_7 ;
struct V_230 * V_231 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( ! F_233 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_534 ,
V_3 , & V_151 -> V_379 ,
sizeof( V_151 -> V_379 ) ) ;
goto V_290;
}
V_231 = F_235 ( V_6 , & V_151 -> V_379 . V_118 ) ;
if ( ! V_231 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_534 ,
V_288 , & V_151 -> V_379 ,
sizeof( V_151 -> V_379 ) ) ;
goto V_290;
}
if ( V_151 -> V_535 ) {
V_231 -> V_536 = V_537 ;
F_116 ( & V_231 -> V_298 ) ;
} else {
V_231 -> V_536 = V_538 ;
F_236 ( V_6 , V_231 ) ;
}
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_534 , 0 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_237 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_539 * V_151 = V_7 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_170 ( V_151 -> V_379 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_540 ,
V_288 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_34 ( V_6 ) ;
V_30 = F_238 ( & V_6 -> V_541 , & V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type ) ;
if ( V_30 < 0 ) {
V_226 = V_3 ;
goto V_451;
}
F_7 ( V_542 , V_6 , & V_151 -> V_379 , sizeof( V_151 -> V_379 ) ,
V_15 ) ;
V_226 = V_304 ;
V_451:
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_540 , V_226 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_239 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_543 * V_151 = V_7 ;
T_1 V_226 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_170 ( V_151 -> V_379 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_544 ,
V_288 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_34 ( V_6 ) ;
V_30 = F_240 ( & V_6 -> V_541 , & V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type ) ;
if ( V_30 < 0 ) {
V_226 = V_288 ;
goto V_451;
}
F_7 ( V_545 , V_6 , & V_151 -> V_379 , sizeof( V_151 -> V_379 ) ,
V_15 ) ;
V_226 = V_304 ;
V_451:
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_544 , V_226 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_241 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_546 * V_151 = V_7 ;
struct V_148 V_149 ;
int V_30 ;
T_9 V_547 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
V_547 = F_129 ( V_151 -> V_547 ) ;
if ( V_547 > 0x0002 )
return F_110 ( V_15 , V_6 -> V_55 , V_548 ,
V_288 ) ;
F_34 ( V_6 ) ;
V_6 -> V_182 = V_547 ;
V_6 -> V_184 = F_129 ( V_151 -> V_549 ) ;
V_6 -> V_185 = F_129 ( V_151 -> V_550 ) ;
V_6 -> V_186 = F_129 ( V_151 -> V_19 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_548 , 0 ,
NULL , 0 ) ;
F_66 ( & V_149 , V_6 ) ;
F_69 ( & V_149 ) ;
F_67 ( & V_149 , NULL ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_242 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
F_9 ( L_19 , V_226 ) ;
}
static void F_243 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_296 V_297 = { NULL , V_6 } ;
struct V_148 V_149 ;
T_1 V_143 ;
struct V_144 * V_145 ;
int V_30 ;
F_34 ( V_6 ) ;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
F_145 ( V_350 , V_6 ,
F_119 , & V_307 ) ;
goto V_306;
}
if ( F_20 ( V_6 , V_204 ) )
F_82 ( V_6 , V_113 ) ;
else
F_76 ( V_6 , V_113 ) ;
F_145 ( V_350 , V_6 , F_115 ,
& V_297 ) ;
F_113 ( V_6 , V_297 . V_15 ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
if ( F_20 ( V_6 , V_113 ) ||
! F_20 ( V_6 , V_134 ) ||
F_106 ( & V_6 -> V_260 ) )
goto V_306;
V_143 = V_6 -> V_135 ;
if ( ! V_143 ) {
V_145 = F_244 ( & V_6 -> V_260 ,
struct V_144 , V_298 ) ;
if ( ! V_145 )
goto V_306;
V_143 = V_145 -> V_143 ;
}
F_66 ( & V_149 , V_6 ) ;
V_30 = F_98 ( & V_149 , V_143 , true ) ;
if ( ! V_30 )
V_30 = F_67 ( & V_149 , F_242 ) ;
if ( V_30 )
F_165 ( L_23 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_245 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
T_1 V_159 , V_226 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
V_226 = F_125 ( V_6 ) ;
if ( V_226 )
return F_110 ( V_15 , V_6 -> V_55 , V_350 ,
V_226 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 && V_151 -> V_159 != 0x02 )
return F_110 ( V_15 , V_6 -> V_55 , V_350 ,
V_288 ) ;
F_34 ( V_6 ) ;
V_159 = ! ! V_151 -> V_159 ;
if ( ! F_42 ( V_6 ) ||
( V_159 == F_20 ( V_6 , V_113 ) &&
( V_151 -> V_159 == 0x02 ) == F_20 ( V_6 , V_167 ) ) ||
F_75 ( V_6 , V_203 ) > 0 ||
( F_20 ( V_6 , V_237 ) &&
V_6 -> V_551 == V_500 ) ) {
bool V_305 ;
if ( V_151 -> V_159 ) {
V_305 = ! F_84 ( V_6 , V_113 ) ;
if ( V_151 -> V_159 == 0x02 )
F_82 ( V_6 , V_167 ) ;
else
F_76 ( V_6 , V_167 ) ;
} else {
V_305 = F_80 ( V_6 , V_113 ) ;
F_76 ( V_6 , V_167 ) ;
}
V_30 = F_88 ( V_15 , V_350 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_306;
}
if ( F_47 ( V_350 , V_6 ) ||
F_47 ( V_347 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_350 ,
V_289 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_350 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
if ( V_151 -> V_159 == 0x02 )
F_82 ( V_6 , V_167 ) ;
else
F_76 ( V_6 , V_167 ) ;
F_101 ( V_6 ) ;
if ( V_159 ) {
F_63 ( & V_149 , 0x00 ) ;
F_55 ( & V_149 , 0x00 ) ;
F_74 ( & V_149 ) ;
} else {
F_73 ( & V_149 ) ;
}
V_30 = F_67 ( & V_149 , F_243 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_246 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_552 * V_151 = V_7 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_553 ,
V_302 ) ;
if ( F_42 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_553 ,
V_303 ) ;
if ( F_28 ( & V_151 -> V_118 , V_72 ) ) {
if ( ! F_28 ( & V_151 -> V_118 , V_554 ) )
return F_110 ( V_15 , V_6 -> V_55 ,
V_553 ,
V_288 ) ;
if ( ( V_151 -> V_118 . V_555 [ 5 ] & 0xc0 ) != 0xc0 )
return F_110 ( V_15 , V_6 -> V_55 ,
V_553 ,
V_288 ) ;
}
F_34 ( V_6 ) ;
F_87 ( & V_6 -> V_119 , & V_151 -> V_118 ) ;
V_30 = F_88 ( V_15 , V_553 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
V_30 = F_113 ( V_6 , V_15 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_247 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_556 * V_151 = V_7 ;
T_9 V_325 , V_327 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_557 ,
V_302 ) ;
V_325 = F_129 ( V_151 -> V_325 ) ;
if ( V_325 < 0x0004 || V_325 > 0x4000 )
return F_110 ( V_15 , V_6 -> V_55 , V_557 ,
V_288 ) ;
V_327 = F_129 ( V_151 -> V_327 ) ;
if ( V_327 < 0x0004 || V_327 > 0x4000 )
return F_110 ( V_15 , V_6 -> V_55 , V_557 ,
V_288 ) ;
if ( V_327 > V_325 )
return F_110 ( V_15 , V_6 -> V_55 , V_557 ,
V_288 ) ;
F_34 ( V_6 ) ;
V_6 -> V_558 = V_325 ;
V_6 -> V_559 = V_327 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_557 , 0 ,
NULL , 0 ) ;
if ( F_20 ( V_6 , V_237 ) &&
V_6 -> V_232 . V_233 == V_514 ) {
struct V_148 V_149 ;
F_66 ( & V_149 , V_6 ) ;
F_94 ( & V_149 ) ;
F_248 ( & V_149 ) ;
F_67 ( & V_149 , NULL ) ;
}
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_249 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_133 * V_155 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_560 , V_6 ) ;
if ( ! V_155 )
goto V_306;
if ( V_226 ) {
F_110 ( V_155 -> V_15 , V_6 -> V_55 , V_560 ,
F_1 ( V_226 ) ) ;
} else {
struct V_157 * V_151 = V_155 -> V_158 ;
if ( V_151 -> V_159 )
F_82 ( V_6 , V_105 ) ;
else
F_76 ( V_6 , V_105 ) ;
F_88 ( V_155 -> V_15 , V_560 , V_6 ) ;
F_113 ( V_6 , V_155 -> V_15 ) ;
}
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_250 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_20 ( V_6 , V_108 ) ||
V_6 -> V_91 < V_92 )
return F_110 ( V_15 , V_6 -> V_55 , V_560 ,
V_302 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_560 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( F_47 ( V_560 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_560 ,
V_289 ) ;
goto V_306;
}
if ( ! ! V_151 -> V_159 == F_20 ( V_6 , V_105 ) ) {
V_30 = F_88 ( V_15 , V_560 ,
V_6 ) ;
goto V_306;
}
if ( ! F_42 ( V_6 ) ) {
F_130 ( V_6 , V_105 ) ;
V_30 = F_88 ( V_15 , V_560 ,
V_6 ) ;
F_113 ( V_6 , V_15 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_560 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
F_132 ( & V_149 , V_151 -> V_159 ) ;
V_30 = F_67 ( & V_149 , F_249 ) ;
if ( V_30 < 0 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_560 ,
V_3 ) ;
F_120 ( V_155 ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_251 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_133 * V_155 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_561 , V_6 ) ;
if ( ! V_155 )
goto V_306;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
F_76 ( V_6 , V_108 ) ;
F_110 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_307 ) ;
} else {
F_88 ( V_155 -> V_15 , V_561 , V_6 ) ;
F_113 ( V_6 , V_155 -> V_15 ) ;
}
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_252 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_37 ( V_6 ) || ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_561 ,
V_302 ) ;
if ( ! F_20 ( V_6 , V_109 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_561 ,
V_303 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_561 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( V_151 -> V_159 == F_20 ( V_6 , V_108 ) ) {
V_30 = F_88 ( V_15 , V_561 , V_6 ) ;
goto V_306;
}
if ( ! F_42 ( V_6 ) ) {
if ( ! V_151 -> V_159 ) {
F_76 ( V_6 , V_106 ) ;
F_76 ( V_6 , V_111 ) ;
F_76 ( V_6 , V_110 ) ;
F_76 ( V_6 , V_105 ) ;
F_76 ( V_6 , V_112 ) ;
}
F_130 ( V_6 , V_108 ) ;
V_30 = F_88 ( V_15 , V_561 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_306;
}
if ( ! V_151 -> V_159 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_561 ,
V_303 ) ;
goto V_306;
} else {
if ( ! F_20 ( V_6 , V_108 ) &&
( F_28 ( & V_6 -> V_119 , V_72 ) ||
F_20 ( V_6 , V_114 ) ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_561 ,
V_303 ) ;
goto V_306;
}
}
if ( F_47 ( V_561 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_561 ,
V_289 ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_561 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_82 ( V_6 , V_108 ) ;
F_66 ( & V_149 , V_6 ) ;
F_132 ( & V_149 , false ) ;
F_127 ( & V_149 ) ;
F_64 ( & V_149 ) ;
V_30 = F_67 ( & V_149 , F_251 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_253 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_133 * V_155 ;
struct V_157 * V_151 ;
F_9 ( L_16 , V_6 -> V_79 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_562 , V_6 ) ;
if ( ! V_155 )
goto V_306;
if ( V_226 ) {
F_110 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 ,
F_1 ( V_226 ) ) ;
goto remove;
}
V_151 = V_155 -> V_158 ;
switch ( V_151 -> V_159 ) {
case 0x00 :
F_76 ( V_6 , V_114 ) ;
F_76 ( V_6 , V_563 ) ;
break;
case 0x01 :
F_82 ( V_6 , V_114 ) ;
F_76 ( V_6 , V_563 ) ;
break;
case 0x02 :
F_82 ( V_6 , V_114 ) ;
F_82 ( V_6 , V_563 ) ;
break;
}
F_88 ( V_155 -> V_15 , V_562 , V_6 ) ;
F_113 ( V_6 , V_155 -> V_15 ) ;
remove:
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_254 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
T_1 V_159 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_39 ( V_6 ) &&
! F_20 ( V_6 , V_109 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_562 ,
V_302 ) ;
if ( F_20 ( V_6 , V_108 ) &&
F_39 ( V_6 ) &&
! F_20 ( V_6 , V_111 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_562 ,
V_303 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 && V_151 -> V_159 != 0x02 )
return F_110 ( V_15 , V_6 -> V_55 , V_562 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) || ! F_39 ( V_6 ) ||
! F_20 ( V_6 , V_108 ) ) {
bool V_305 ;
if ( V_151 -> V_159 ) {
V_305 = ! F_84 ( V_6 ,
V_114 ) ;
if ( V_151 -> V_159 == 0x02 )
F_82 ( V_6 , V_563 ) ;
else
F_76 ( V_6 , V_563 ) ;
} else {
V_305 = F_80 ( V_6 ,
V_114 ) ;
F_76 ( V_6 , V_563 ) ;
}
V_30 = F_88 ( V_15 , V_562 , V_6 ) ;
if ( V_30 < 0 )
goto V_290;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
goto V_290;
}
if ( F_47 ( V_562 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_562 ,
V_289 ) ;
goto V_290;
}
V_159 = ! ! V_151 -> V_159 ;
if ( V_159 == F_20 ( V_6 , V_114 ) &&
( V_151 -> V_159 == 0x02 ) == F_20 ( V_6 , V_563 ) ) {
V_30 = F_88 ( V_15 , V_562 , V_6 ) ;
goto V_290;
}
V_155 = F_111 ( V_15 , V_562 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_290;
}
F_66 ( & V_149 , V_6 ) ;
F_56 ( & V_149 , V_564 , 1 , & V_159 ) ;
V_30 = F_67 ( & V_149 , F_253 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
goto V_290;
}
V_290:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_255 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_157 * V_151 = V_7 ;
bool V_305 , V_565 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( V_151 -> V_159 != 0x00 && V_151 -> V_159 != 0x01 && V_151 -> V_159 != 0x02 )
return F_110 ( V_15 , V_6 -> V_55 , V_566 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( V_151 -> V_159 )
V_305 = ! F_84 ( V_6 , V_115 ) ;
else
V_305 = F_80 ( V_6 ,
V_115 ) ;
if ( V_151 -> V_159 == 0x02 )
V_565 = ! F_84 ( V_6 ,
V_343 ) ;
else
V_565 = F_80 ( V_6 ,
V_343 ) ;
if ( F_42 ( V_6 ) && V_565 &&
F_20 ( V_6 , V_111 ) ) {
T_1 V_567 = ( V_151 -> V_159 == 0x02 ) ? 0x01 : 0x00 ;
F_141 ( V_6 , V_344 ,
sizeof( V_567 ) , & V_567 ) ;
}
V_30 = F_88 ( V_15 , V_566 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_256 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_568 ,
T_2 V_8 )
{
struct V_569 * V_151 = V_568 ;
bool V_305 ;
int V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_570 ,
V_302 ) ;
if ( V_151 -> V_571 != 0x00 && V_151 -> V_571 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_570 ,
V_288 ) ;
if ( F_42 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_570 ,
V_303 ) ;
F_34 ( V_6 ) ;
F_82 ( V_6 , V_572 ) ;
if ( V_151 -> V_571 ) {
V_305 = ! F_84 ( V_6 , V_116 ) ;
memcpy ( V_6 -> V_573 , V_151 -> V_573 , sizeof( V_6 -> V_573 ) ) ;
F_82 ( V_6 , V_219 ) ;
} else {
V_305 = F_80 ( V_6 , V_116 ) ;
memset ( V_6 -> V_573 , 0 , sizeof( V_6 -> V_573 ) ) ;
F_76 ( V_6 , V_219 ) ;
}
V_30 = F_88 ( V_15 , V_570 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( V_305 )
V_30 = F_113 ( V_6 , V_15 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_257 ( struct V_574 * V_573 )
{
switch ( V_573 -> V_379 . type ) {
case V_391 :
return true ;
case V_404 :
if ( ( V_573 -> V_379 . V_118 . V_555 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_258 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_568 ,
T_2 V_8 )
{
struct V_575 * V_151 = V_568 ;
const T_2 V_576 = ( ( V_371 - sizeof( * V_151 ) ) /
sizeof( struct V_574 ) ) ;
T_2 V_577 , V_374 ;
int V_29 , V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_578 ,
V_302 ) ;
V_577 = F_129 ( V_151 -> V_577 ) ;
if ( V_577 > V_576 ) {
F_165 ( L_24 , V_577 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_578 ,
V_288 ) ;
}
V_374 = sizeof( * V_151 ) + V_577 * sizeof( struct V_574 ) ;
if ( V_374 != V_8 ) {
F_165 ( L_25 ,
V_374 , V_8 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_578 ,
V_288 ) ;
}
F_9 ( L_26 , V_6 -> V_79 , V_577 ) ;
for ( V_29 = 0 ; V_29 < V_577 ; V_29 ++ ) {
struct V_574 * V_377 = & V_151 -> V_579 [ V_29 ] ;
if ( ! F_257 ( V_377 ) )
return F_110 ( V_15 , V_6 -> V_55 ,
V_578 ,
V_288 ) ;
}
F_34 ( V_6 ) ;
F_259 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_577 ; V_29 ++ ) {
struct V_574 * V_573 = & V_151 -> V_579 [ V_29 ] ;
T_1 V_383 ;
if ( V_573 -> V_379 . type == V_391 )
V_383 = V_392 ;
else
V_383 = V_393 ;
F_260 ( V_6 , & V_573 -> V_379 . V_118 , V_383 , V_573 -> V_159 ,
V_72 ) ;
}
F_82 ( V_6 , V_572 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_578 , 0 , NULL , 0 ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_261 ( struct V_580 * V_377 )
{
if ( V_377 -> V_581 != 0x00 && V_377 -> V_581 != 0x01 )
return false ;
switch ( V_377 -> V_379 . type ) {
case V_391 :
return true ;
case V_404 :
if ( ( V_377 -> V_379 . V_118 . V_555 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_262 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_568 , T_2 V_8 )
{
struct V_582 * V_151 = V_568 ;
const T_2 V_370 = ( ( V_371 - sizeof( * V_151 ) ) /
sizeof( struct V_580 ) ) ;
T_2 V_373 , V_374 ;
int V_29 , V_30 ;
F_9 ( L_7 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_583 ,
V_302 ) ;
V_373 = F_129 ( V_151 -> V_373 ) ;
if ( V_373 > V_370 ) {
F_165 ( L_27 , V_373 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_583 ,
V_288 ) ;
}
V_374 = sizeof( * V_151 ) + V_373 *
sizeof( struct V_580 ) ;
if ( V_374 != V_8 ) {
F_165 ( L_28 ,
V_374 , V_8 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_583 ,
V_288 ) ;
}
F_9 ( L_29 , V_6 -> V_79 , V_373 ) ;
for ( V_29 = 0 ; V_29 < V_373 ; V_29 ++ ) {
struct V_580 * V_377 = & V_151 -> V_378 [ V_29 ] ;
if ( ! F_261 ( V_377 ) )
return F_110 ( V_15 , V_6 -> V_55 ,
V_583 ,
V_288 ) ;
}
F_34 ( V_6 ) ;
F_263 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_373 ; V_29 ++ ) {
struct V_580 * V_377 = & V_151 -> V_378 [ V_29 ] ;
T_1 type , V_383 , V_584 ;
if ( V_377 -> V_379 . type == V_391 )
V_383 = V_392 ;
else
V_383 = V_393 ;
switch ( V_377 -> type ) {
case V_585 :
V_584 = 0x00 ;
type = V_377 -> V_581 ? V_586 : V_587 ;
break;
case V_588 :
V_584 = 0x01 ;
type = V_377 -> V_581 ? V_586 : V_587 ;
break;
case V_589 :
V_584 = 0x00 ;
type = V_590 ;
break;
case V_591 :
V_584 = 0x01 ;
type = V_590 ;
break;
case V_592 :
V_584 = 0x00 ;
type = V_593 ;
default:
continue;
}
F_264 ( V_6 , & V_377 -> V_379 . V_118 , V_383 , type ,
V_584 , V_377 -> V_159 , V_377 -> V_594 , V_377 -> V_595 ,
V_377 -> rand ) ;
}
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_583 , 0 ,
NULL , 0 ) ;
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_265 ( struct V_133 * V_155 , T_1 V_226 )
{
struct V_261 * V_262 = V_155 -> V_429 ;
struct V_596 V_18 ;
int V_30 ;
memcpy ( & V_18 . V_379 , V_155 -> V_158 , sizeof( V_18 . V_379 ) ) ;
if ( V_226 == V_304 ) {
V_18 . V_529 = V_262 -> V_529 ;
V_18 . V_597 = V_262 -> V_597 ;
V_18 . V_598 = V_262 -> V_598 ;
} else {
V_18 . V_529 = V_599 ;
V_18 . V_597 = V_177 ;
V_18 . V_598 = V_177 ;
}
V_30 = F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_600 ,
V_226 , & V_18 , sizeof( V_18 ) ) ;
F_184 ( V_262 ) ;
F_186 ( V_262 ) ;
return V_30 ;
}
static void F_266 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_37 )
{
struct V_601 * V_151 ;
struct V_133 * V_155 ;
struct V_261 * V_262 ;
T_2 V_274 ;
T_1 V_226 ;
F_9 ( L_8 , V_1 ) ;
F_34 ( V_6 ) ;
V_151 = F_267 ( V_6 , V_602 ) ;
if ( ! V_151 ) {
V_151 = F_267 ( V_6 , V_603 ) ;
V_226 = V_304 ;
} else {
V_226 = F_1 ( V_1 ) ;
}
if ( ! V_151 ) {
F_165 ( L_30 ) ;
goto V_306;
}
V_274 = F_129 ( V_151 -> V_274 ) ;
V_262 = F_268 ( V_6 , V_274 ) ;
if ( ! V_262 ) {
F_165 ( L_31 , V_274 ) ;
goto V_306;
}
V_155 = F_49 ( V_600 , V_6 , V_262 ) ;
if ( ! V_155 )
goto V_306;
V_155 -> V_299 ( V_155 , V_226 ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_269 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_604 * V_151 = V_7 ;
struct V_596 V_18 ;
struct V_261 * V_262 ;
unsigned long V_605 ;
int V_30 = 0 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_87 ( & V_18 . V_379 . V_118 , & V_151 -> V_379 . V_118 ) ;
V_18 . V_379 . type = V_151 -> V_379 . type ;
if ( ! F_170 ( V_151 -> V_379 . type ) )
return F_11 ( V_15 , V_6 -> V_55 , V_600 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_600 ,
V_313 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
if ( V_151 -> V_379 . type == V_380 )
V_262 = F_171 ( V_6 , V_279 ,
& V_151 -> V_379 . V_118 ) ;
else
V_262 = F_171 ( V_6 , V_203 , & V_151 -> V_379 . V_118 ) ;
if ( ! V_262 || V_262 -> V_233 != V_272 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_600 ,
V_401 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
if ( F_49 ( V_600 , V_6 , V_262 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_600 ,
V_289 , & V_18 , sizeof( V_18 ) ) ;
goto V_306;
}
V_605 = V_6 -> V_606 +
F_270 ( V_6 -> V_607 -
V_6 -> V_606 ) ;
if ( F_271 ( V_520 , V_262 -> V_608 +
F_100 ( V_605 ) ) ||
! V_262 -> V_608 ) {
struct V_148 V_149 ;
struct V_609 V_610 ;
struct V_601 V_611 ;
struct V_133 * V_155 ;
F_66 ( & V_149 , V_6 ) ;
V_611 . V_274 = F_10 ( V_262 -> V_274 ) ;
F_56 ( & V_149 , V_602 , sizeof( V_611 ) ,
& V_611 ) ;
if ( ! F_216 ( V_151 -> V_379 . type ) ||
V_262 -> V_597 == V_177 ) {
V_610 . V_274 = F_10 ( V_262 -> V_274 ) ;
V_610 . type = 0x00 ;
F_56 ( & V_149 , V_603 ,
sizeof( V_610 ) , & V_610 ) ;
}
if ( V_262 -> V_598 == V_177 ) {
V_610 . V_274 = F_10 ( V_262 -> V_274 ) ;
V_610 . type = 0x01 ;
F_56 ( & V_149 , V_603 ,
sizeof( V_610 ) , & V_610 ) ;
}
V_30 = F_67 ( & V_149 , F_266 ) ;
if ( V_30 < 0 )
goto V_306;
V_155 = F_111 ( V_15 , V_600 , V_6 ,
V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_272 ( V_262 ) ;
V_155 -> V_429 = F_197 ( V_262 ) ;
V_155 -> V_299 = F_265 ;
V_262 -> V_608 = V_520 ;
} else {
V_18 . V_529 = V_262 -> V_529 ;
V_18 . V_597 = V_262 -> V_597 ;
V_18 . V_598 = V_262 -> V_598 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_600 ,
V_304 , & V_18 , sizeof( V_18 ) ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_273 ( struct V_133 * V_155 , T_1 V_226 )
{
struct V_261 * V_262 = V_155 -> V_429 ;
struct V_612 V_18 ;
struct V_5 * V_6 ;
int V_30 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memcpy ( & V_18 . V_379 , & V_155 -> V_158 , sizeof( V_18 . V_379 ) ) ;
if ( V_226 )
goto V_434;
V_6 = F_274 ( V_155 -> V_54 ) ;
if ( V_6 ) {
V_18 . V_613 = F_30 ( V_6 -> clock ) ;
F_275 ( V_6 ) ;
}
if ( V_262 ) {
V_18 . V_614 = F_30 ( V_262 -> clock ) ;
V_18 . V_615 = F_10 ( V_262 -> V_616 ) ;
}
V_434:
V_30 = F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_226 , & V_18 ,
sizeof( V_18 ) ) ;
if ( V_262 ) {
F_184 ( V_262 ) ;
F_186 ( V_262 ) ;
}
return V_30 ;
}
static void F_276 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_617 * V_317 ;
struct V_133 * V_155 ;
struct V_261 * V_262 ;
F_9 ( L_16 , V_6 -> V_79 , V_226 ) ;
F_34 ( V_6 ) ;
V_317 = F_267 ( V_6 , V_618 ) ;
if ( ! V_317 )
goto V_306;
if ( V_317 -> V_619 ) {
T_2 V_274 = F_129 ( V_317 -> V_274 ) ;
V_262 = F_268 ( V_6 , V_274 ) ;
} else {
V_262 = NULL ;
}
V_155 = F_49 ( V_620 , V_6 , V_262 ) ;
if ( ! V_155 )
goto V_306;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_277 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_621 * V_151 = V_7 ;
struct V_612 V_18 ;
struct V_617 V_317 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
struct V_261 * V_262 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_87 ( & V_18 . V_379 . V_118 , & V_151 -> V_379 . V_118 ) ;
V_18 . V_379 . type = V_151 -> V_379 . type ;
if ( V_151 -> V_379 . type != V_380 )
return F_11 ( V_15 , V_6 -> V_55 , V_620 ,
V_288 ,
& V_18 , sizeof( V_18 ) ) ;
F_34 ( V_6 ) ;
if ( ! F_42 ( V_6 ) ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_620 ,
V_313 , & V_18 ,
sizeof( V_18 ) ) ;
goto V_306;
}
if ( F_28 ( & V_151 -> V_379 . V_118 , V_72 ) ) {
V_262 = F_171 ( V_6 , V_279 ,
& V_151 -> V_379 . V_118 ) ;
if ( ! V_262 || V_262 -> V_233 != V_272 ) {
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_620 ,
V_401 ,
& V_18 , sizeof( V_18 ) ) ;
goto V_306;
}
} else {
V_262 = NULL ;
}
V_155 = F_111 ( V_15 , V_620 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_155 -> V_299 = F_273 ;
F_66 ( & V_149 , V_6 ) ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
F_56 ( & V_149 , V_618 , sizeof( V_317 ) , & V_317 ) ;
if ( V_262 ) {
F_272 ( V_262 ) ;
V_155 -> V_429 = F_197 ( V_262 ) ;
V_317 . V_274 = F_10 ( V_262 -> V_274 ) ;
V_317 . V_619 = 0x01 ;
F_56 ( & V_149 , V_618 , sizeof( V_317 ) , & V_317 ) ;
}
V_30 = F_67 ( & V_149 , F_276 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static bool F_278 ( struct V_5 * V_6 , T_8 * V_379 , T_1 type )
{
struct V_261 * V_262 ;
V_262 = F_171 ( V_6 , V_203 , V_379 ) ;
if ( ! V_262 )
return false ;
if ( V_262 -> V_409 != type )
return false ;
if ( V_262 -> V_233 != V_272 )
return false ;
return true ;
}
static int F_279 ( struct V_148 * V_149 , T_8 * V_379 ,
T_1 V_383 , T_1 V_622 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_623 * V_624 ;
V_624 = F_193 ( V_6 , V_379 , V_383 ) ;
if ( ! V_624 )
return - V_625 ;
if ( V_624 -> V_622 == V_622 )
return 0 ;
F_280 ( & V_624 -> V_626 ) ;
switch ( V_622 ) {
case V_627 :
case V_628 :
F_147 ( V_149 ) ;
break;
case V_629 :
F_281 ( & V_624 -> V_626 , & V_6 -> V_630 ) ;
F_147 ( V_149 ) ;
break;
case V_631 :
case V_632 :
if ( ! F_278 ( V_6 , V_379 , V_383 ) ) {
F_281 ( & V_624 -> V_626 , & V_6 -> V_633 ) ;
F_147 ( V_149 ) ;
}
break;
}
V_624 -> V_622 = V_622 ;
F_9 ( L_32 , V_379 , V_383 ,
V_622 ) ;
return 0 ;
}
static void F_282 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_8 * V_118 , T_1 type , T_1 V_626 )
{
struct V_634 V_243 ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = type ;
V_243 . V_626 = V_626 ;
F_7 ( V_635 , V_6 , & V_243 , sizeof( V_243 ) , V_15 ) ;
}
static void F_283 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_133 * V_155 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_636 , V_6 ) ;
if ( ! V_155 )
goto V_306;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_284 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_637 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
T_1 V_638 , V_383 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_170 ( V_151 -> V_379 . type ) ||
! F_28 ( & V_151 -> V_379 . V_118 , V_72 ) )
return F_11 ( V_15 , V_6 -> V_55 , V_636 ,
V_288 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
if ( V_151 -> V_626 != 0x00 && V_151 -> V_626 != 0x01 && V_151 -> V_626 != 0x02 )
return F_11 ( V_15 , V_6 -> V_55 , V_636 ,
V_288 ,
& V_151 -> V_379 , sizeof( V_151 -> V_379 ) ) ;
F_66 ( & V_149 , V_6 ) ;
F_34 ( V_6 ) ;
V_155 = F_111 ( V_15 , V_636 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_155 -> V_299 = F_123 ;
if ( V_151 -> V_379 . type == V_380 ) {
if ( V_151 -> V_626 != 0x01 ) {
V_30 = V_155 -> V_299 ( V_155 ,
V_288 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
V_30 = F_238 ( & V_6 -> V_335 , & V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type ) ;
if ( V_30 )
goto V_306;
F_127 ( & V_149 ) ;
goto V_639;
}
if ( V_151 -> V_379 . type == V_391 )
V_383 = V_392 ;
else
V_383 = V_393 ;
if ( V_151 -> V_626 == 0x02 )
V_638 = V_632 ;
else if ( V_151 -> V_626 == 0x01 )
V_638 = V_631 ;
else
V_638 = V_629 ;
if ( F_279 ( & V_149 , & V_151 -> V_379 . V_118 , V_383 ,
V_638 ) < 0 ) {
V_30 = V_155 -> V_299 ( V_155 , V_3 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
V_639:
F_282 ( V_15 , V_6 , & V_151 -> V_379 . V_118 , V_151 -> V_379 . type , V_151 -> V_626 ) ;
V_30 = F_67 ( & V_149 , F_283 ) ;
if ( V_30 < 0 ) {
if ( V_30 == - V_294 )
V_30 = V_155 -> V_299 ( V_155 , V_304 ) ;
F_120 ( V_155 ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_285 ( struct V_11 * V_15 , struct V_5 * V_6 ,
T_8 * V_118 , T_1 type )
{
struct V_640 V_243 ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = type ;
F_7 ( V_641 , V_6 , & V_243 , sizeof( V_243 ) , V_15 ) ;
}
static void F_286 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_133 * V_155 ;
F_9 ( L_8 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_642 , V_6 ) ;
if ( ! V_155 )
goto V_306;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_287 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_643 * V_151 = V_7 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_66 ( & V_149 , V_6 ) ;
F_34 ( V_6 ) ;
V_155 = F_111 ( V_15 , V_642 , V_6 , V_7 , V_8 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_155 -> V_299 = F_123 ;
if ( F_28 ( & V_151 -> V_379 . V_118 , V_72 ) ) {
struct V_623 * V_624 ;
T_1 V_383 ;
if ( ! F_170 ( V_151 -> V_379 . type ) ) {
V_30 = V_155 -> V_299 ( V_155 ,
V_288 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
if ( V_151 -> V_379 . type == V_380 ) {
V_30 = F_240 ( & V_6 -> V_335 ,
& V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type ) ;
if ( V_30 ) {
V_30 = V_155 -> V_299 ( V_155 ,
V_288 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
F_127 ( & V_149 ) ;
F_285 ( V_15 , V_6 , & V_151 -> V_379 . V_118 ,
V_151 -> V_379 . type ) ;
goto V_434;
}
if ( V_151 -> V_379 . type == V_391 )
V_383 = V_392 ;
else
V_383 = V_393 ;
V_624 = F_288 ( V_6 , & V_151 -> V_379 . V_118 ,
V_383 ) ;
if ( ! V_624 ) {
V_30 = V_155 -> V_299 ( V_155 ,
V_288 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
if ( V_624 -> V_622 == V_627 ) {
V_30 = V_155 -> V_299 ( V_155 ,
V_288 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
F_116 ( & V_624 -> V_626 ) ;
F_116 ( & V_624 -> V_298 ) ;
F_16 ( V_624 ) ;
F_147 ( & V_149 ) ;
F_285 ( V_15 , V_6 , & V_151 -> V_379 . V_118 , V_151 -> V_379 . type ) ;
} else {
struct V_623 * V_644 , * V_363 ;
struct V_645 * V_555 , * V_646 ;
if ( V_151 -> V_379 . type ) {
V_30 = V_155 -> V_299 ( V_155 ,
V_288 ) ;
F_120 ( V_155 ) ;
goto V_306;
}
F_104 (b, btmp, &hdev->whitelist, list) {
F_285 ( V_15 , V_6 , & V_555 -> V_118 , V_555 -> V_647 ) ;
F_116 ( & V_555 -> V_298 ) ;
F_16 ( V_555 ) ;
}
F_127 ( & V_149 ) ;
F_104 (p, tmp, &hdev->le_conn_params, list) {
if ( V_644 -> V_622 == V_627 )
continue;
F_285 ( V_15 , V_6 , & V_644 -> V_379 , V_644 -> V_383 ) ;
F_116 ( & V_644 -> V_626 ) ;
F_116 ( & V_644 -> V_298 ) ;
F_16 ( V_644 ) ;
}
F_9 ( L_33 ) ;
F_147 ( & V_149 ) ;
}
V_434:
V_30 = F_67 ( & V_149 , F_286 ) ;
if ( V_30 < 0 ) {
if ( V_30 == - V_294 )
V_30 = V_155 -> V_299 ( V_155 , V_304 ) ;
F_120 ( V_155 ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_289 ( struct V_11 * V_15 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_648 * V_151 = V_7 ;
const T_2 V_649 = ( ( V_371 - sizeof( * V_151 ) ) /
sizeof( struct V_650 ) ) ;
T_2 V_651 , V_374 ;
int V_29 ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_652 ,
V_302 ) ;
V_651 = F_129 ( V_151 -> V_651 ) ;
if ( V_651 > V_649 ) {
F_165 ( L_34 ,
V_651 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_652 ,
V_288 ) ;
}
V_374 = sizeof( * V_151 ) + V_651 *
sizeof( struct V_650 ) ;
if ( V_374 != V_8 ) {
F_165 ( L_35 ,
V_374 , V_8 ) ;
return F_110 ( V_15 , V_6 -> V_55 , V_652 ,
V_288 ) ;
}
F_9 ( L_36 , V_6 -> V_79 , V_651 ) ;
F_34 ( V_6 ) ;
F_290 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_651 ; V_29 ++ ) {
struct V_650 * V_158 = & V_151 -> V_624 [ V_29 ] ;
struct V_623 * V_653 ;
T_2 V_654 , V_655 , V_656 , V_248 ;
T_1 V_383 ;
F_9 ( L_37 , & V_158 -> V_379 . V_118 ,
V_158 -> V_379 . type ) ;
if ( V_158 -> V_379 . type == V_391 ) {
V_383 = V_392 ;
} else if ( V_158 -> V_379 . type == V_404 ) {
V_383 = V_393 ;
} else {
F_165 ( L_38 ) ;
continue;
}
V_654 = F_291 ( V_158 -> V_205 ) ;
V_655 = F_291 ( V_158 -> V_207 ) ;
V_656 = F_291 ( V_158 -> V_656 ) ;
V_248 = F_291 ( V_158 -> V_248 ) ;
F_9 ( L_39 ,
V_654 , V_655 , V_656 , V_248 ) ;
if ( F_292 ( V_654 , V_655 , V_656 , V_248 ) < 0 ) {
F_165 ( L_38 ) ;
continue;
}
V_653 = F_193 ( V_6 , & V_158 -> V_379 . V_118 ,
V_383 ) ;
if ( ! V_653 ) {
F_165 ( L_40 ) ;
continue;
}
V_653 -> V_657 = V_654 ;
V_653 -> V_658 = V_655 ;
V_653 -> V_659 = V_656 ;
V_653 -> V_660 = V_248 ;
}
F_35 ( V_6 ) ;
return F_11 ( V_15 , V_6 -> V_55 , V_652 , 0 ,
NULL , 0 ) ;
}
static int F_293 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_661 * V_151 = V_7 ;
bool V_305 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( F_42 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_662 ,
V_303 ) ;
if ( V_151 -> V_663 != 0x00 && V_151 -> V_663 != 0x01 )
return F_110 ( V_15 , V_6 -> V_55 , V_662 ,
V_288 ) ;
if ( ! F_22 ( V_68 , & V_6 -> V_53 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_662 ,
V_302 ) ;
F_34 ( V_6 ) ;
if ( V_151 -> V_663 )
V_305 = ! F_84 ( V_6 , V_69 ) ;
else
V_305 = F_80 ( V_6 , V_69 ) ;
V_30 = F_32 ( V_15 , V_662 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( ! V_305 )
goto V_306;
V_30 = F_31 ( V_6 , V_15 ) ;
if ( F_20 ( V_6 , V_47 ) == F_27 ( V_6 ) ) {
F_294 ( V_6 ) ;
if ( F_295 ( V_6 , V_47 ) ) {
F_82 ( V_6 , V_50 ) ;
F_82 ( V_6 , V_291 ) ;
F_92 ( V_6 -> V_228 , & V_6 -> V_292 ) ;
} else {
F_173 ( V_664 , & V_6 -> V_164 ) ;
F_296 ( V_6 ) ;
}
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static int F_297 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_665 * V_151 = V_7 ;
bool V_305 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( F_42 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_666 ,
V_303 ) ;
if ( ! F_28 ( & V_151 -> V_118 , V_72 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_666 ,
V_288 ) ;
if ( ! V_6 -> V_81 )
return F_110 ( V_15 , V_6 -> V_55 , V_666 ,
V_302 ) ;
F_34 ( V_6 ) ;
V_305 = ! ! F_28 ( & V_6 -> V_71 , & V_151 -> V_118 ) ;
F_87 ( & V_6 -> V_71 , & V_151 -> V_118 ) ;
V_30 = F_32 ( V_15 , V_666 , V_6 ) ;
if ( V_30 < 0 )
goto V_306;
if ( ! V_305 )
goto V_306;
if ( F_20 ( V_6 , V_47 ) )
V_30 = F_31 ( V_6 , V_15 ) ;
if ( F_27 ( V_6 ) ) {
F_294 ( V_6 ) ;
F_76 ( V_6 , V_47 ) ;
F_82 ( V_6 , V_50 ) ;
F_82 ( V_6 , V_291 ) ;
F_92 ( V_6 -> V_228 , & V_6 -> V_292 ) ;
}
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static inline T_2 F_298 ( T_1 * V_190 , T_2 V_667 , T_1 type , T_1 * V_7 ,
T_1 V_16 )
{
V_190 [ V_667 ++ ] = sizeof( type ) + V_16 ;
V_190 [ V_667 ++ ] = type ;
memcpy ( & V_190 [ V_667 ] , V_7 , V_16 ) ;
V_667 += V_16 ;
return V_667 ;
}
static void F_299 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 , struct V_470 * V_471 )
{
const struct V_668 * V_532 ;
struct V_669 * V_473 ;
T_1 * V_670 , * V_671 , * V_672 , * V_673 ;
struct V_133 * V_155 ;
T_2 V_667 ;
int V_30 ;
F_9 ( L_16 , V_6 -> V_79 , V_226 ) ;
V_155 = F_47 ( V_674 , V_6 ) ;
if ( ! V_155 )
return;
V_532 = V_155 -> V_158 ;
if ( V_226 ) {
V_226 = F_1 ( V_226 ) ;
V_667 = 0 ;
V_670 = NULL ;
V_671 = NULL ;
V_672 = NULL ;
V_673 = NULL ;
} else if ( V_37 == V_475 ) {
struct V_476 * V_18 ;
if ( V_471 -> V_8 != sizeof( * V_18 ) ) {
V_226 = V_3 ;
V_667 = 0 ;
} else {
V_226 = V_304 ;
V_18 = ( void * ) V_471 -> V_7 ;
V_667 = 5 + 18 + 18 ;
V_670 = V_18 -> V_478 ;
V_671 = V_18 -> rand ;
V_672 = NULL ;
V_673 = NULL ;
}
} else {
struct V_482 * V_18 ;
if ( V_471 -> V_8 != sizeof( * V_18 ) ) {
V_226 = V_3 ;
V_667 = 0 ;
} else {
V_226 = V_304 ;
V_18 = ( void * ) V_471 -> V_7 ;
if ( F_20 ( V_6 , V_563 ) ) {
V_667 = 5 + 18 + 18 ;
V_670 = NULL ;
V_671 = NULL ;
} else {
V_667 = 5 + 18 + 18 + 18 + 18 ;
V_670 = V_18 -> V_477 ;
V_671 = V_18 -> V_479 ;
}
V_672 = V_18 -> V_480 ;
V_673 = V_18 -> V_481 ;
}
}
V_473 = F_14 ( sizeof( * V_473 ) + V_667 , V_35 ) ;
if ( ! V_473 )
goto V_451;
if ( V_226 )
goto V_675;
V_667 = F_298 ( V_473 -> V_190 , 0 , V_676 ,
V_6 -> V_196 , 3 ) ;
if ( V_670 && V_671 ) {
V_667 = F_298 ( V_473 -> V_190 , V_667 ,
V_677 , V_670 , 16 ) ;
V_667 = F_298 ( V_473 -> V_190 , V_667 ,
V_678 , V_671 , 16 ) ;
}
if ( V_672 && V_673 ) {
V_667 = F_298 ( V_473 -> V_190 , V_667 ,
V_679 , V_672 , 16 ) ;
V_667 = F_298 ( V_473 -> V_190 , V_667 ,
V_680 , V_673 , 16 ) ;
}
V_675:
V_473 -> type = V_532 -> type ;
V_473 -> V_667 = F_10 ( V_667 ) ;
V_30 = F_11 ( V_155 -> V_15 , V_6 -> V_55 ,
V_674 , V_226 ,
V_473 , sizeof( * V_473 ) + V_667 ) ;
if ( V_30 < 0 || V_226 )
goto V_451;
F_25 ( V_155 -> V_15 , V_681 ) ;
V_30 = F_5 ( V_682 , V_6 ,
V_473 , sizeof( * V_473 ) + V_667 ,
V_681 , V_155 -> V_15 ) ;
V_451:
F_16 ( V_473 ) ;
F_120 ( V_155 ) ;
}
static int F_300 ( struct V_5 * V_6 , struct V_11 * V_15 ,
struct V_668 * V_151 )
{
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
V_155 = F_111 ( V_15 , V_674 , V_6 ,
V_151 , sizeof( * V_151 ) ) ;
if ( ! V_155 )
return - V_36 ;
F_66 ( & V_149 , V_6 ) ;
if ( F_212 ( V_6 ) )
F_56 ( & V_149 , V_483 , 0 , NULL ) ;
else
F_56 ( & V_149 , V_475 , 0 , NULL ) ;
V_30 = F_213 ( & V_149 , F_299 ) ;
if ( V_30 < 0 ) {
F_120 ( V_155 ) ;
return V_30 ;
}
return 0 ;
}
static int F_301 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_668 * V_151 = V_7 ;
struct V_669 * V_18 ;
T_3 V_42 ;
T_2 V_667 ;
T_1 V_226 , V_164 , V_683 , V_379 [ 7 ] , V_478 [ 16 ] , rand [ 16 ] ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( F_42 ( V_6 ) ) {
switch ( V_151 -> type ) {
case F_302 ( V_380 ) :
V_226 = F_124 ( V_6 ) ;
if ( V_226 )
V_667 = 0 ;
else
V_667 = 5 ;
break;
case ( F_302 ( V_391 ) | F_302 ( V_404 ) ) :
V_226 = F_125 ( V_6 ) ;
if ( V_226 )
V_667 = 0 ;
else
V_667 = 9 + 3 + 18 + 18 + 3 ;
break;
default:
V_226 = V_288 ;
V_667 = 0 ;
break;
}
} else {
V_226 = V_313 ;
V_667 = 0 ;
}
V_42 = sizeof( * V_18 ) + V_667 ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 )
return - V_36 ;
if ( V_226 )
goto V_434;
F_34 ( V_6 ) ;
V_667 = 0 ;
switch ( V_151 -> type ) {
case F_302 ( V_380 ) :
if ( F_20 ( V_6 , V_111 ) ) {
V_30 = F_300 ( V_6 , V_15 , V_151 ) ;
F_35 ( V_6 ) ;
if ( ! V_30 )
goto V_451;
V_226 = V_3 ;
goto V_434;
} else {
V_667 = F_298 ( V_18 -> V_190 , V_667 ,
V_676 ,
V_6 -> V_196 , 3 ) ;
}
break;
case ( F_302 ( V_391 ) | F_302 ( V_404 ) ) :
if ( F_20 ( V_6 , V_114 ) &&
F_303 ( V_6 , V_478 , rand ) < 0 ) {
F_35 ( V_6 ) ;
V_226 = V_3 ;
goto V_434;
}
if ( F_20 ( V_6 , V_116 ) ) {
F_35 ( V_6 ) ;
V_226 = V_303 ;
goto V_434;
}
if ( F_20 ( V_6 , V_117 ) ||
! F_28 ( & V_6 -> V_118 , V_72 ) ||
( ! F_20 ( V_6 , V_108 ) &&
F_28 ( & V_6 -> V_119 , V_72 ) ) ) {
memcpy ( V_379 , & V_6 -> V_119 , 6 ) ;
V_379 [ 6 ] = 0x01 ;
} else {
memcpy ( V_379 , & V_6 -> V_118 , 6 ) ;
V_379 [ 6 ] = 0x00 ;
}
V_667 = F_298 ( V_18 -> V_190 , V_667 , V_684 ,
V_379 , sizeof( V_379 ) ) ;
if ( F_20 ( V_6 , V_113 ) )
V_683 = 0x02 ;
else
V_683 = 0x01 ;
V_667 = F_298 ( V_18 -> V_190 , V_667 , V_685 ,
& V_683 , sizeof( V_683 ) ) ;
if ( F_20 ( V_6 , V_114 ) ) {
V_667 = F_298 ( V_18 -> V_190 , V_667 ,
V_686 ,
V_478 , sizeof( V_478 ) ) ;
V_667 = F_298 ( V_18 -> V_190 , V_667 ,
V_687 ,
rand , sizeof( rand ) ) ;
}
V_164 = F_58 ( V_6 ) ;
if ( ! F_20 ( V_6 , V_108 ) )
V_164 |= V_172 ;
V_667 = F_298 ( V_18 -> V_190 , V_667 , V_173 ,
& V_164 , sizeof( V_164 ) ) ;
break;
}
F_35 ( V_6 ) ;
F_25 ( V_15 , V_681 ) ;
V_226 = V_304 ;
V_434:
V_18 -> type = V_151 -> type ;
V_18 -> V_667 = F_10 ( V_667 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_674 ,
V_226 , V_18 , sizeof( * V_18 ) + V_667 ) ;
if ( V_30 < 0 || V_226 )
goto V_451;
V_30 = F_5 ( V_682 , V_6 ,
V_18 , sizeof( * V_18 ) + V_667 ,
V_681 , V_15 ) ;
V_451:
F_16 ( V_18 ) ;
return V_30 ;
}
static T_6 F_304 ( struct V_5 * V_6 )
{
T_6 V_164 = 0 ;
V_164 |= V_168 ;
V_164 |= V_170 ;
V_164 |= V_171 ;
V_164 |= V_166 ;
if ( V_6 -> V_176 != V_177 )
V_164 |= V_165 ;
return V_164 ;
}
static int F_305 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_688 * V_18 ;
T_3 V_42 ;
int V_30 , V_29 ;
bool V_143 ;
struct V_144 * V_145 ;
T_6 V_689 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
if ( ! F_40 ( V_6 ) )
return F_110 ( V_15 , V_6 -> V_55 , V_690 ,
V_303 ) ;
F_34 ( V_6 ) ;
V_42 = sizeof( * V_18 ) ;
V_143 = F_20 ( V_6 , V_134 ) ;
if ( V_143 )
V_42 += V_6 -> V_691 ;
V_18 = F_14 ( V_42 , V_48 ) ;
if ( ! V_18 ) {
F_35 ( V_6 ) ;
return - V_36 ;
}
V_689 = F_304 ( V_6 ) ;
V_18 -> V_689 = F_30 ( V_689 ) ;
V_18 -> V_692 = V_140 ;
V_18 -> V_693 = V_140 ;
V_18 -> V_694 = V_695 ;
if ( V_143 ) {
V_29 = 0 ;
F_19 (adv_instance, &hdev->adv_instances, list) {
if ( V_29 >= V_6 -> V_691 )
break;
V_18 -> V_143 [ V_29 ] = V_145 -> V_143 ;
V_29 ++ ;
}
V_18 -> V_696 = V_6 -> V_691 ;
} else {
V_18 -> V_696 = 0 ;
}
F_35 ( V_6 ) ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_690 ,
V_304 , V_18 , V_42 ) ;
F_16 ( V_18 ) ;
return V_30 ;
}
static bool F_306 ( struct V_5 * V_6 , T_6 V_697 , T_1 * V_7 ,
T_1 V_8 , bool V_698 )
{
T_1 V_139 = V_140 ;
int V_29 , V_699 ;
bool V_700 = false ;
bool V_701 = false ;
T_6 V_702 = V_170 | V_171 |
V_166 ;
if ( V_698 && ( V_697 & V_702 ) ) {
V_700 = true ;
V_139 -= 3 ;
}
if ( V_698 && ( V_697 & V_165 ) ) {
V_701 = true ;
V_139 -= 3 ;
}
if ( V_8 > V_139 )
return false ;
for ( V_29 = 0 , V_699 = 0 ; V_29 < V_8 ; V_29 += ( V_699 + 1 ) ) {
V_699 = V_7 [ V_29 ] ;
if ( V_700 && V_7 [ V_29 + 1 ] == V_173 )
return false ;
if ( V_701 && V_7 [ V_29 + 1 ] == V_178 )
return false ;
if ( V_29 + V_699 >= V_8 )
return false ;
}
return true ;
}
static void F_307 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_133 * V_155 ;
struct V_703 * V_151 ;
struct V_704 V_18 ;
struct V_144 * V_145 , * V_257 ;
T_1 V_143 ;
F_9 ( L_19 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_705 , V_6 ) ;
if ( V_226 )
F_76 ( V_6 , V_134 ) ;
F_104 (adv_instance, n, &hdev->adv_instances, list) {
if ( ! V_145 -> V_706 )
continue;
if ( ! V_226 ) {
V_145 -> V_706 = false ;
continue;
}
V_143 = V_145 -> V_143 ;
if ( V_6 -> V_135 == V_143 )
F_101 ( V_6 ) ;
F_105 ( V_6 , V_143 ) ;
F_97 ( V_155 ? V_155 -> V_15 : NULL , V_6 , V_143 ) ;
}
if ( ! V_155 )
goto V_306;
V_151 = V_155 -> V_158 ;
V_18 . V_143 = V_151 -> V_143 ;
if ( V_226 )
F_110 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 ,
F_1 ( V_226 ) ) ;
else
F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 ,
F_1 ( V_226 ) , & V_18 , sizeof( V_18 ) ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
void F_308 ( struct V_5 * V_6 )
{
T_1 V_143 ;
struct V_148 V_149 ;
V_6 -> V_250 = 0 ;
V_143 = F_51 ( V_6 ) ;
if ( V_143 == 0x00 )
return;
F_34 ( V_6 ) ;
F_66 ( & V_149 , V_6 ) ;
F_102 ( V_6 , & V_149 , V_143 , false ) ;
if ( F_106 ( & V_6 -> V_260 ) )
F_73 ( & V_149 ) ;
if ( ! F_309 ( & V_149 . V_707 ) )
F_67 ( & V_149 , NULL ) ;
F_35 ( V_6 ) ;
}
static int F_310 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_703 * V_151 = V_7 ;
struct V_704 V_18 ;
T_6 V_164 ;
T_6 V_689 ;
T_1 V_226 ;
T_2 V_248 , V_253 ;
unsigned int V_708 = V_6 -> V_691 ;
T_1 V_709 = 0 ;
struct V_144 * V_258 ;
int V_30 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
V_226 = F_125 ( V_6 ) ;
if ( V_226 )
return F_110 ( V_15 , V_6 -> V_55 , V_705 ,
V_226 ) ;
V_164 = F_311 ( V_151 -> V_164 ) ;
V_248 = F_129 ( V_151 -> V_248 ) ;
V_253 = F_129 ( V_151 -> V_253 ) ;
V_689 = F_304 ( V_6 ) ;
if ( V_164 & ~ V_689 )
return F_110 ( V_15 , V_6 -> V_55 , V_705 ,
V_288 ) ;
F_34 ( V_6 ) ;
if ( V_248 && ! F_42 ( V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_705 ,
V_303 ) ;
goto V_306;
}
if ( F_47 ( V_705 , V_6 ) ||
F_47 ( V_710 , V_6 ) ||
F_47 ( V_347 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_705 ,
V_289 ) ;
goto V_306;
}
if ( ! F_306 ( V_6 , V_164 , V_151 -> V_7 , V_151 -> V_175 , true ) ||
! F_306 ( V_6 , V_164 , V_151 -> V_7 + V_151 -> V_175 ,
V_151 -> V_147 , false ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_705 ,
V_288 ) ;
goto V_306;
}
V_30 = F_312 ( V_6 , V_151 -> V_143 , V_164 ,
V_151 -> V_175 , V_151 -> V_7 ,
V_151 -> V_147 ,
V_151 -> V_7 + V_151 -> V_175 ,
V_248 , V_253 ) ;
if ( V_30 < 0 ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_705 ,
V_3 ) ;
goto V_306;
}
if ( V_6 -> V_691 > V_708 )
F_96 ( V_15 , V_6 , V_151 -> V_143 ) ;
F_82 ( V_6 , V_134 ) ;
if ( V_6 -> V_135 == V_151 -> V_143 ) {
F_101 ( V_6 ) ;
V_258 = F_103 ( V_6 , V_151 -> V_143 ) ;
if ( V_258 )
V_709 = V_258 -> V_143 ;
} else if ( ! V_6 -> V_250 ) {
V_709 = V_151 -> V_143 ;
}
if ( ! F_42 ( V_6 ) ||
F_20 ( V_6 , V_113 ) ||
! V_709 ) {
V_18 . V_143 = V_151 -> V_143 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 , V_705 ,
V_304 , & V_18 , sizeof( V_18 ) ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_705 , V_6 , V_7 ,
V_16 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
V_30 = F_98 ( & V_149 , V_709 , true ) ;
if ( ! V_30 )
V_30 = F_67 ( & V_149 , F_307 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
static void F_313 ( struct V_5 * V_6 , T_1 V_226 ,
T_2 V_37 )
{
struct V_133 * V_155 ;
struct V_711 * V_151 ;
struct V_712 V_18 ;
F_9 ( L_19 , V_226 ) ;
F_34 ( V_6 ) ;
V_155 = F_47 ( V_710 , V_6 ) ;
if ( ! V_155 )
goto V_306;
V_151 = V_155 -> V_158 ;
V_18 . V_143 = V_151 -> V_143 ;
F_11 ( V_155 -> V_15 , V_155 -> V_54 , V_155 -> V_37 , V_304 ,
& V_18 , sizeof( V_18 ) ) ;
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
}
static int F_314 ( struct V_11 * V_15 , struct V_5 * V_6 ,
void * V_7 , T_2 V_16 )
{
struct V_711 * V_151 = V_7 ;
struct V_712 V_18 ;
struct V_133 * V_155 ;
struct V_148 V_149 ;
int V_30 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_34 ( V_6 ) ;
if ( V_151 -> V_143 && ! F_54 ( V_6 , V_151 -> V_143 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 ,
V_710 ,
V_288 ) ;
goto V_306;
}
if ( F_47 ( V_705 , V_6 ) ||
F_47 ( V_710 , V_6 ) ||
F_47 ( V_347 , V_6 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_710 ,
V_289 ) ;
goto V_306;
}
if ( ! F_20 ( V_6 , V_134 ) ) {
V_30 = F_110 ( V_15 , V_6 -> V_55 , V_710 ,
V_288 ) ;
goto V_306;
}
F_66 ( & V_149 , V_6 ) ;
F_102 ( V_6 , & V_149 , V_151 -> V_143 , true ) ;
if ( F_106 ( & V_6 -> V_260 ) )
F_73 ( & V_149 ) ;
if ( F_309 ( & V_149 . V_707 ) ||
! F_42 ( V_6 ) ||
F_20 ( V_6 , V_113 ) ) {
V_18 . V_143 = V_151 -> V_143 ;
V_30 = F_11 ( V_15 , V_6 -> V_55 ,
V_710 ,
V_304 , & V_18 , sizeof( V_18 ) ) ;
goto V_306;
}
V_155 = F_111 ( V_15 , V_710 , V_6 , V_7 ,
V_16 ) ;
if ( ! V_155 ) {
V_30 = - V_36 ;
goto V_306;
}
V_30 = F_67 ( & V_149 , F_313 ) ;
if ( V_30 < 0 )
F_120 ( V_155 ) ;
V_306:
F_35 ( V_6 ) ;
return V_30 ;
}
void F_296 ( struct V_5 * V_6 )
{
struct V_713 V_243 ;
if ( F_22 ( V_52 , & V_6 -> V_53 ) )
return;
switch ( V_6 -> V_45 ) {
case V_46 :
if ( F_20 ( V_6 , V_47 ) ) {
F_3 ( V_714 , V_6 ,
NULL , 0 , V_66 ) ;
V_243 . type = 0x01 ;
} else {
F_3 ( V_715 , V_6 , NULL , 0 ,
V_65 ) ;
V_243 . type = 0x00 ;
}
break;
case V_61 :
V_243 . type = 0x02 ;
break;
default:
return;
}
V_243 . V_63 = V_6 -> V_63 ;
F_3 ( V_716 , V_6 , & V_243 , sizeof( V_243 ) ,
V_64 ) ;
}
void F_294 ( struct V_5 * V_6 )
{
struct V_713 V_243 ;
T_1 V_226 = V_717 ;
if ( F_22 ( V_52 , & V_6 -> V_53 ) )
return;
switch ( V_6 -> V_45 ) {
case V_46 :
F_145 ( 0 , V_6 , F_121 , & V_226 ) ;
if ( F_20 ( V_6 , V_47 ) ) {
F_3 ( V_718 , V_6 ,
NULL , 0 , V_66 ) ;
V_243 . type = 0x01 ;
} else {
F_3 ( V_719 , V_6 , NULL , 0 ,
V_65 ) ;
V_243 . type = 0x00 ;
}
break;
case V_61 :
V_243 . type = 0x02 ;
break;
default:
return;
}
V_243 . V_63 = V_6 -> V_63 ;
F_3 ( V_720 , V_6 , & V_243 , sizeof( V_243 ) ,
V_64 ) ;
}
static void F_315 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_623 * V_644 ;
F_19 (p, &hdev->le_conn_params, list) {
F_280 ( & V_644 -> V_626 ) ;
switch ( V_644 -> V_622 ) {
case V_631 :
case V_632 :
F_281 ( & V_644 -> V_626 , & V_6 -> V_633 ) ;
break;
case V_629 :
F_281 ( & V_644 -> V_626 , & V_6 -> V_630 ) ;
break;
default:
break;
}
}
F_147 ( V_149 ) ;
}
static void F_316 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
struct V_296 V_297 = { NULL , V_6 } ;
F_9 ( L_8 , V_226 ) ;
if ( ! V_226 ) {
F_317 ( V_6 ) ;
}
F_34 ( V_6 ) ;
F_145 ( V_287 , V_6 , F_115 , & V_297 ) ;
F_113 ( V_6 , V_297 . V_15 ) ;
F_35 ( V_6 ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
}
static int F_318 ( struct V_5 * V_6 )
{
struct V_148 V_149 ;
struct V_144 * V_145 ;
T_1 V_721 ;
F_66 ( & V_149 , V_6 ) ;
if ( F_20 ( V_6 , V_111 ) &&
! F_319 ( V_6 ) ) {
T_1 V_567 = 0x01 ;
F_56 ( & V_149 , V_345 , sizeof( V_567 ) , & V_567 ) ;
if ( F_212 ( V_6 ) && ! F_320 ( V_6 ) ) {
T_1 V_722 = 0x01 ;
F_56 ( & V_149 , V_564 ,
sizeof( V_722 ) , & V_722 ) ;
}
}
if ( F_20 ( V_6 , V_109 ) &&
F_37 ( V_6 ) ) {
struct V_348 V_151 ;
V_151 . V_351 = 0x01 ;
V_151 . V_352 = 0x00 ;
if ( V_151 . V_351 != F_149 ( V_6 ) ||
V_151 . V_352 != F_321 ( V_6 ) )
F_56 ( & V_149 , V_353 ,
sizeof( V_151 ) , & V_151 ) ;
}
if ( F_40 ( V_6 ) ) {
if ( F_20 ( V_6 , V_109 ) &&
( F_20 ( V_6 , V_113 ) ||
! F_20 ( V_6 , V_134 ) ) ) {
F_64 ( & V_149 ) ;
F_57 ( & V_149 ) ;
}
if ( F_20 ( V_6 , V_134 ) &&
V_6 -> V_135 == 0x00 &&
! F_106 ( & V_6 -> V_260 ) ) {
V_145 = F_322 ( & V_6 -> V_260 ,
struct V_144 , V_298 ) ;
V_6 -> V_135 = V_145 -> V_143 ;
}
if ( F_20 ( V_6 , V_113 ) )
F_74 ( & V_149 ) ;
else if ( F_20 ( V_6 , V_134 ) &&
V_6 -> V_135 )
F_98 ( & V_149 , V_6 -> V_135 ,
true ) ;
F_315 ( & V_149 ) ;
}
V_721 = F_20 ( V_6 , V_110 ) ;
if ( V_721 != F_22 ( V_340 , & V_6 -> V_164 ) )
F_56 ( & V_149 , V_341 ,
sizeof( V_721 ) , & V_721 ) ;
if ( F_37 ( V_6 ) ) {
if ( F_20 ( V_6 , V_105 ) )
F_132 ( & V_149 , true ) ;
else
F_132 ( & V_149 , false ) ;
F_127 ( & V_149 ) ;
F_72 ( & V_149 ) ;
F_207 ( & V_149 ) ;
F_69 ( & V_149 ) ;
}
return F_67 ( & V_149 , F_316 ) ;
}
int F_112 ( struct V_5 * V_6 , T_1 V_723 )
{
struct V_296 V_297 = { NULL , V_6 } ;
T_1 V_226 , V_724 [] = { 0 , 0 , 0 } ;
int V_30 ;
if ( ! F_20 ( V_6 , V_220 ) )
return 0 ;
if ( V_723 ) {
if ( F_318 ( V_6 ) == 0 )
return 0 ;
F_145 ( V_287 , V_6 , F_115 ,
& V_297 ) ;
goto F_113;
}
F_145 ( V_287 , V_6 , F_115 , & V_297 ) ;
if ( F_20 ( V_6 , V_725 ) )
V_226 = V_717 ;
else
V_226 = V_313 ;
F_145 ( 0 , V_6 , F_121 , & V_226 ) ;
if ( memcmp ( V_6 -> V_196 , V_724 , sizeof( V_724 ) ) != 0 )
F_6 ( V_726 , V_6 ,
V_724 , sizeof( V_724 ) , NULL ) ;
F_113:
V_30 = F_113 ( V_6 , V_297 . V_15 ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
return V_30 ;
}
void F_323 ( struct V_5 * V_6 , int V_30 )
{
struct V_133 * V_155 ;
T_1 V_226 ;
V_155 = F_47 ( V_287 , V_6 ) ;
if ( ! V_155 )
return;
if ( V_30 == - V_727 )
V_226 = V_728 ;
else
V_226 = V_3 ;
F_110 ( V_155 -> V_15 , V_6 -> V_55 , V_287 , V_226 ) ;
F_120 ( V_155 ) ;
}
void F_324 ( struct V_5 * V_6 )
{
struct V_148 V_149 ;
F_34 ( V_6 ) ;
F_76 ( V_6 , V_162 ) ;
F_76 ( V_6 , V_106 ) ;
F_66 ( & V_149 , V_6 ) ;
if ( F_20 ( V_6 , V_108 ) ) {
T_1 V_266 = V_315 ;
F_56 ( & V_149 , V_267 ,
sizeof( V_266 ) , & V_266 ) ;
}
F_72 ( & V_149 ) ;
if ( F_20 ( V_6 , V_113 ) )
F_64 ( & V_149 ) ;
F_67 ( & V_149 , NULL ) ;
V_6 -> V_309 = 0 ;
F_113 ( V_6 , NULL ) ;
F_35 ( V_6 ) ;
}
void F_325 ( struct V_5 * V_6 , struct V_729 * V_377 ,
bool V_730 )
{
struct V_731 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_732 = V_730 ;
F_87 ( & V_243 . V_377 . V_379 . V_118 , & V_377 -> V_118 ) ;
V_243 . V_377 . V_379 . type = V_380 ;
V_243 . V_377 . type = V_377 -> type ;
memcpy ( V_243 . V_377 . V_159 , V_377 -> V_159 , V_733 ) ;
V_243 . V_377 . V_382 = V_377 -> V_382 ;
F_7 ( V_734 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
static T_1 F_326 ( struct V_735 * V_736 )
{
switch ( V_736 -> type ) {
case V_586 :
case V_587 :
if ( V_736 -> V_584 )
return V_588 ;
return V_585 ;
case V_590 :
if ( V_736 -> V_584 )
return V_591 ;
return V_589 ;
case V_593 :
return V_592 ;
}
return V_585 ;
}
void F_327 ( struct V_5 * V_6 , struct V_735 * V_377 , bool V_730 )
{
struct V_737 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
if ( V_377 -> V_647 == V_393 &&
( V_377 -> V_118 . V_555 [ 5 ] & 0xc0 ) != 0xc0 )
V_243 . V_732 = 0x00 ;
else
V_243 . V_732 = V_730 ;
F_87 ( & V_243 . V_377 . V_379 . V_118 , & V_377 -> V_118 ) ;
V_243 . V_377 . V_379 . type = F_177 ( V_203 , V_377 -> V_647 ) ;
V_243 . V_377 . type = F_326 ( V_377 ) ;
V_243 . V_377 . V_594 = V_377 -> V_594 ;
V_243 . V_377 . V_595 = V_377 -> V_595 ;
V_243 . V_377 . rand = V_377 -> rand ;
if ( V_377 -> type == V_586 )
V_243 . V_377 . V_581 = 1 ;
memcpy ( V_243 . V_377 . V_159 , V_377 -> V_159 , V_377 -> V_594 ) ;
memset ( V_243 . V_377 . V_159 + V_377 -> V_594 , 0 ,
sizeof( V_243 . V_377 . V_159 ) - V_377 -> V_594 ) ;
F_7 ( V_738 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_328 ( struct V_5 * V_6 , struct V_739 * V_573 )
{
struct V_740 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
if ( F_28 ( & V_573 -> V_741 , V_72 ) )
V_243 . V_732 = 0x01 ;
else
V_243 . V_732 = 0x00 ;
F_87 ( & V_243 . V_741 , & V_573 -> V_741 ) ;
F_87 ( & V_243 . V_573 . V_379 . V_118 , & V_573 -> V_118 ) ;
V_243 . V_573 . V_379 . type = F_177 ( V_203 , V_573 -> V_383 ) ;
memcpy ( V_243 . V_573 . V_159 , V_573 -> V_159 , sizeof( V_573 -> V_159 ) ) ;
F_7 ( V_742 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_329 ( struct V_5 * V_6 , struct V_743 * V_744 ,
bool V_730 )
{
struct V_745 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
if ( V_744 -> V_647 == V_393 &&
( V_744 -> V_118 . V_555 [ 5 ] & 0xc0 ) != 0xc0 )
V_243 . V_732 = 0x00 ;
else
V_243 . V_732 = V_730 ;
F_87 ( & V_243 . V_377 . V_379 . V_118 , & V_744 -> V_118 ) ;
V_243 . V_377 . V_379 . type = F_177 ( V_203 , V_744 -> V_647 ) ;
V_243 . V_377 . type = V_744 -> type ;
memcpy ( V_243 . V_377 . V_159 , V_744 -> V_159 , sizeof( V_744 -> V_159 ) ) ;
F_7 ( V_746 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_330 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_647 , T_1 V_732 , T_2 V_205 ,
T_2 V_207 , T_2 V_656 , T_2 V_248 )
{
struct V_747 V_243 ;
if ( ! F_331 ( V_118 , V_647 ) )
return;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = F_177 ( V_203 , V_647 ) ;
V_243 . V_732 = V_732 ;
V_243 . V_205 = F_10 ( V_205 ) ;
V_243 . V_207 = F_10 ( V_207 ) ;
V_243 . V_656 = F_10 ( V_656 ) ;
V_243 . V_248 = F_10 ( V_248 ) ;
F_7 ( V_748 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_332 ( struct V_5 * V_6 , struct V_261 * V_262 ,
T_6 V_164 , T_1 * V_79 , T_1 V_137 )
{
char V_749 [ 512 ] ;
struct V_750 * V_243 = ( void * ) V_749 ;
T_2 V_667 = 0 ;
F_87 ( & V_243 -> V_379 . V_118 , & V_262 -> V_281 ) ;
V_243 -> V_379 . type = F_177 ( V_262 -> type , V_262 -> V_409 ) ;
V_243 -> V_164 = F_333 ( V_164 ) ;
if ( V_262 -> V_751 > 0 ) {
memcpy ( & V_243 -> V_190 [ V_667 ] ,
V_262 -> V_752 , V_262 -> V_751 ) ;
V_667 = V_262 -> V_751 ;
} else {
if ( V_137 > 0 )
V_667 = F_298 ( V_243 -> V_190 , 0 , V_142 ,
V_79 , V_137 ) ;
if ( memcmp ( V_262 -> V_196 , L_41 , 3 ) != 0 )
V_667 = F_298 ( V_243 -> V_190 , V_667 ,
V_676 ,
V_262 -> V_196 , 3 ) ;
}
V_243 -> V_667 = F_10 ( V_667 ) ;
F_7 ( V_753 , V_6 , V_749 ,
sizeof( * V_243 ) + V_667 , NULL ) ;
}
static void F_334 ( struct V_133 * V_155 , void * V_7 )
{
struct V_11 * * V_15 = V_7 ;
V_155 -> V_299 ( V_155 , 0 ) ;
* V_15 = V_155 -> V_15 ;
F_117 ( * V_15 ) ;
F_120 ( V_155 ) ;
}
static void F_335 ( struct V_133 * V_155 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_386 * V_151 = V_155 -> V_158 ;
F_168 ( V_6 , & V_151 -> V_379 . V_118 , V_151 -> V_379 . type , V_155 -> V_15 ) ;
V_155 -> V_299 ( V_155 , 0 ) ;
F_120 ( V_155 ) ;
}
bool F_336 ( struct V_5 * V_6 )
{
struct V_133 * V_155 ;
struct V_157 * V_151 ;
V_155 = F_47 ( V_287 , V_6 ) ;
if ( ! V_155 )
return false ;
V_151 = V_155 -> V_158 ;
if ( ! V_151 -> V_159 )
return true ;
return false ;
}
void F_337 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_275 ,
bool V_754 )
{
struct V_755 V_243 ;
struct V_11 * V_15 = NULL ;
if ( F_336 ( V_6 ) && F_90 ( V_6 ) == 1 ) {
F_91 ( & V_6 -> V_227 ) ;
F_92 ( V_6 -> V_228 , & V_6 -> V_227 . V_217 ) ;
}
if ( ! V_754 )
return;
if ( V_403 != V_279 && V_403 != V_203 )
return;
F_145 ( V_397 , V_6 , F_334 , & V_15 ) ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = F_177 ( V_403 , V_383 ) ;
V_243 . V_275 = V_275 ;
F_7 ( V_756 , V_6 , & V_243 , sizeof( V_243 ) , V_15 ) ;
if ( V_15 )
F_146 ( V_15 ) ;
F_145 ( V_388 , V_6 , F_335 ,
V_6 ) ;
}
void F_338 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_226 )
{
T_1 V_647 = F_177 ( V_403 , V_383 ) ;
struct V_395 * V_151 ;
struct V_133 * V_155 ;
F_145 ( V_388 , V_6 , F_335 ,
V_6 ) ;
V_155 = F_47 ( V_397 , V_6 ) ;
if ( ! V_155 )
return;
V_151 = V_155 -> V_158 ;
if ( F_28 ( V_118 , & V_151 -> V_379 . V_118 ) )
return;
if ( V_151 -> V_379 . type != V_647 )
return;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
void F_339 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_403 ,
T_1 V_383 , T_1 V_226 )
{
struct V_757 V_243 ;
if ( F_336 ( V_6 ) && F_90 ( V_6 ) == 1 ) {
F_91 ( & V_6 -> V_227 ) ;
F_92 ( V_6 -> V_228 , & V_6 -> V_227 . V_217 ) ;
}
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = F_177 ( V_403 , V_383 ) ;
V_243 . V_226 = F_1 ( V_226 ) ;
F_7 ( V_758 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_340 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_759 )
{
struct V_760 V_243 ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = V_380 ;
V_243 . V_759 = V_759 ;
F_7 ( V_761 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_341 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_226 )
{
struct V_133 * V_155 ;
V_155 = F_47 ( V_418 , V_6 ) ;
if ( ! V_155 )
return;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
void F_342 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_226 )
{
struct V_133 * V_155 ;
V_155 = F_47 ( V_413 , V_6 ) ;
if ( ! V_155 )
return;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
}
int F_343 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_6 V_762 ,
T_1 V_763 )
{
struct V_764 V_243 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = F_177 ( V_403 , V_383 ) ;
V_243 . V_763 = V_763 ;
V_243 . V_762 = F_30 ( V_762 ) ;
return F_7 ( V_765 , V_6 , & V_243 , sizeof( V_243 ) ,
NULL ) ;
}
int F_344 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 )
{
struct V_766 V_243 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = F_177 ( V_403 , V_383 ) ;
return F_7 ( V_767 , V_6 , & V_243 , sizeof( V_243 ) ,
NULL ) ;
}
static int F_345 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_226 ,
T_1 V_37 )
{
struct V_133 * V_155 ;
V_155 = F_47 ( V_37 , V_6 ) ;
if ( ! V_155 )
return - V_252 ;
V_155 -> V_299 ( V_155 , F_1 ( V_226 ) ) ;
F_120 ( V_155 ) ;
return 0 ;
}
int F_346 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_226 )
{
return F_345 ( V_6 , V_118 , V_403 , V_383 ,
V_226 , V_455 ) ;
}
int F_347 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_226 )
{
return F_345 ( V_6 , V_118 , V_403 , V_383 ,
V_226 ,
V_458 ) ;
}
int F_348 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_226 )
{
return F_345 ( V_6 , V_118 , V_403 , V_383 ,
V_226 , V_461 ) ;
}
int F_349 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_1 V_226 )
{
return F_345 ( V_6 , V_118 , V_403 , V_383 ,
V_226 ,
V_463 ) ;
}
int F_350 ( struct V_5 * V_6 , T_8 * V_118 ,
T_1 V_403 , T_1 V_383 , T_6 V_450 ,
T_1 V_768 )
{
struct V_769 V_243 ;
F_9 ( L_4 , V_6 -> V_79 ) ;
F_87 ( & V_243 . V_379 . V_118 , V_118 ) ;
V_243 . V_379 . type = F_177 ( V_403 , V_383 ) ;
V_243 . V_450 = F_333 ( V_450 ) ;
V_243 . V_768 = V_768 ;
return F_7 ( V_770 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
void F_351 ( struct V_261 * V_262 , T_1 V_1 )
{
struct V_771 V_243 ;
struct V_133 * V_155 ;
T_1 V_226 = F_1 ( V_1 ) ;
F_87 ( & V_243 . V_379 . V_118 , & V_262 -> V_281 ) ;
V_243 . V_379 . type = F_177 ( V_262 -> type , V_262 -> V_409 ) ;
V_243 . V_226 = V_226 ;
V_155 = F_182 ( V_262 ) ;
F_7 ( V_772 , V_262 -> V_6 , & V_243 , sizeof( V_243 ) ,
V_155 ? V_155 -> V_15 : NULL ) ;
if ( V_155 ) {
V_155 -> V_299 ( V_155 , V_226 ) ;
F_120 ( V_155 ) ;
}
}
void F_352 ( struct V_5 * V_6 , T_1 V_226 )
{
struct V_296 V_297 = { NULL , V_6 } ;
bool V_305 ;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
F_145 ( V_339 , V_6 ,
F_119 , & V_307 ) ;
return;
}
if ( F_22 ( V_340 , & V_6 -> V_164 ) )
V_305 = ! F_84 ( V_6 , V_110 ) ;
else
V_305 = F_80 ( V_6 , V_110 ) ;
F_145 ( V_339 , V_6 , F_115 ,
& V_297 ) ;
if ( V_305 )
F_113 ( V_6 , V_297 . V_15 ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
}
static void F_353 ( struct V_148 * V_149 )
{
struct V_5 * V_6 = V_149 -> V_6 ;
struct V_188 V_151 ;
if ( ! F_70 ( V_6 ) )
return;
memset ( V_6 -> V_190 , 0 , sizeof( V_6 -> V_190 ) ) ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
F_56 ( V_149 , V_191 , sizeof( V_151 ) , & V_151 ) ;
}
void F_354 ( struct V_5 * V_6 , T_1 V_198 , T_1 V_226 )
{
struct V_296 V_297 = { NULL , V_6 } ;
struct V_148 V_149 ;
bool V_305 = false ;
if ( V_226 ) {
T_1 V_307 = F_1 ( V_226 ) ;
if ( V_198 && F_80 ( V_6 ,
V_111 ) ) {
F_76 ( V_6 , V_112 ) ;
F_113 ( V_6 , NULL ) ;
}
F_145 ( V_342 , V_6 , F_119 ,
& V_307 ) ;
return;
}
if ( V_198 ) {
V_305 = ! F_84 ( V_6 , V_111 ) ;
} else {
V_305 = F_80 ( V_6 , V_111 ) ;
if ( ! V_305 )
V_305 = F_80 ( V_6 ,
V_112 ) ;
else
F_76 ( V_6 , V_112 ) ;
}
F_145 ( V_342 , V_6 , F_115 , & V_297 ) ;
if ( V_305 )
F_113 ( V_6 , V_297 . V_15 ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
F_66 ( & V_149 , V_6 ) ;
if ( F_20 ( V_6 , V_111 ) ) {
if ( F_20 ( V_6 , V_343 ) )
F_56 ( & V_149 , V_344 ,
sizeof( V_198 ) , & V_198 ) ;
F_69 ( & V_149 ) ;
} else {
F_353 ( & V_149 ) ;
}
F_67 ( & V_149 , NULL ) ;
}
static void F_355 ( struct V_133 * V_155 , void * V_7 )
{
struct V_296 * V_297 = V_7 ;
if ( V_297 -> V_15 == NULL ) {
V_297 -> V_15 = V_155 -> V_15 ;
F_117 ( V_297 -> V_15 ) ;
}
}
void F_356 ( struct V_5 * V_6 , T_1 * V_196 ,
T_1 V_226 )
{
struct V_296 V_297 = { NULL , V_6 , F_1 (status) } ;
F_145 ( V_356 , V_6 , F_355 , & V_297 ) ;
F_145 ( V_354 , V_6 , F_355 , & V_297 ) ;
F_145 ( V_355 , V_6 , F_355 , & V_297 ) ;
if ( ! V_226 )
F_6 ( V_726 , V_6 ,
V_196 , 3 , NULL ) ;
if ( V_297 . V_15 )
F_146 ( V_297 . V_15 ) ;
}
void F_357 ( struct V_5 * V_6 , T_1 * V_79 , T_1 V_226 )
{
struct V_467 V_243 ;
struct V_133 * V_155 ;
if ( V_226 )
return;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
memcpy ( V_243 . V_79 , V_79 , V_773 ) ;
memcpy ( V_243 . V_224 , V_6 -> V_224 , V_774 ) ;
V_155 = F_47 ( V_468 , V_6 ) ;
if ( ! V_155 ) {
memcpy ( V_6 -> V_138 , V_79 , sizeof( V_6 -> V_138 ) ) ;
if ( F_47 ( V_287 , V_6 ) )
return;
}
F_6 ( V_469 , V_6 , & V_243 , sizeof( V_243 ) ,
V_155 ? V_155 -> V_15 : NULL ) ;
}
static void F_358 ( struct V_5 * V_6 )
{
if ( ! F_20 ( V_6 , V_237 ) )
return;
if ( F_271 ( V_520 + V_775 ,
V_6 -> V_232 . V_519 +
V_6 -> V_232 . V_521 ) )
return;
F_99 ( V_6 -> V_255 , & V_6 -> V_776 ,
V_775 ) ;
}
static bool F_359 ( struct V_5 * V_6 , T_10 V_529 , T_1 * V_190 ,
T_2 V_667 , T_1 * V_777 , T_1 V_147 )
{
if ( V_6 -> V_232 . V_529 != V_599 &&
( V_529 == V_599 ||
( V_529 < V_6 -> V_232 . V_529 &&
! F_22 ( V_517 , & V_6 -> V_53 ) ) ) )
return false ;
if ( V_6 -> V_232 . V_528 != 0 ) {
if ( ! F_360 ( V_190 , V_667 , V_6 -> V_232 . V_528 ,
V_6 -> V_232 . V_360 ) &&
! F_360 ( V_777 , V_147 ,
V_6 -> V_232 . V_528 ,
V_6 -> V_232 . V_360 ) )
return false ;
}
if ( F_22 ( V_517 , & V_6 -> V_53 ) ) {
F_358 ( V_6 ) ;
if ( V_6 -> V_232 . V_529 != V_599 &&
V_529 < V_6 -> V_232 . V_529 )
return false ;
}
return true ;
}
void F_361 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_403 ,
T_1 V_383 , T_1 * V_196 , T_10 V_529 , T_6 V_164 ,
T_1 * V_190 , T_2 V_667 , T_1 * V_777 , T_1 V_147 )
{
char V_749 [ 512 ] ;
struct V_778 * V_243 = ( void * ) V_749 ;
T_3 V_779 ;
if ( ! F_233 ( V_6 ) ) {
if ( V_403 == V_279 )
return;
if ( V_403 == V_203 && F_106 ( & V_6 -> V_630 ) )
return;
}
if ( V_6 -> V_232 . V_518 ) {
if ( ! F_359 ( V_6 , V_529 , V_190 , V_667 , V_777 ,
V_147 ) )
return;
}
if ( sizeof( * V_243 ) + V_667 + V_147 + 5 > sizeof( V_749 ) )
return;
memset ( V_749 , 0 , sizeof( V_749 ) ) ;
if ( V_529 == V_599 && ! V_6 -> V_232 . V_524 &&
V_403 == V_279 )
V_529 = 0 ;
F_87 ( & V_243 -> V_379 . V_118 , V_118 ) ;
V_243 -> V_379 . type = F_177 ( V_403 , V_383 ) ;
V_243 -> V_529 = V_529 ;
V_243 -> V_164 = F_30 ( V_164 ) ;
if ( V_667 > 0 )
memcpy ( V_243 -> V_190 , V_190 , V_667 ) ;
if ( V_196 && ! F_362 ( V_243 -> V_190 , V_667 , V_676 ) )
V_667 = F_298 ( V_243 -> V_190 , V_667 , V_676 ,
V_196 , 3 ) ;
if ( V_147 > 0 )
memcpy ( V_243 -> V_190 + V_667 , V_777 , V_147 ) ;
V_243 -> V_667 = F_10 ( V_667 + V_147 ) ;
V_779 = sizeof( * V_243 ) + V_667 + V_147 ;
F_7 ( V_780 , V_6 , V_243 , V_779 , NULL ) ;
}
void F_363 ( struct V_5 * V_6 , T_8 * V_118 , T_1 V_403 ,
T_1 V_383 , T_10 V_529 , T_1 * V_79 , T_1 V_137 )
{
struct V_778 * V_243 ;
char V_749 [ sizeof( * V_243 ) + V_773 + 2 ] ;
T_2 V_667 ;
V_243 = (struct V_778 * ) V_749 ;
memset ( V_749 , 0 , sizeof( V_749 ) ) ;
F_87 ( & V_243 -> V_379 . V_118 , V_118 ) ;
V_243 -> V_379 . type = F_177 ( V_403 , V_383 ) ;
V_243 -> V_529 = V_529 ;
V_667 = F_298 ( V_243 -> V_190 , 0 , V_142 , V_79 ,
V_137 ) ;
V_243 -> V_667 = F_10 ( V_667 ) ;
F_7 ( V_780 , V_6 , V_243 , sizeof( * V_243 ) + V_667 , NULL ) ;
}
void F_364 ( struct V_5 * V_6 , T_1 V_781 )
{
struct V_782 V_243 ;
F_9 ( L_42 , V_6 -> V_79 , V_781 ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . type = V_6 -> V_232 . type ;
V_243 . V_781 = V_781 ;
F_7 ( V_783 , V_6 , & V_243 , sizeof( V_243 ) , NULL ) ;
}
static void F_365 ( struct V_5 * V_6 , T_1 V_226 , T_2 V_37 )
{
F_9 ( L_16 , V_6 -> V_79 , V_226 ) ;
}
void F_366 ( struct V_5 * V_6 )
{
struct V_148 V_149 ;
T_1 V_143 ;
if ( ! F_20 ( V_6 , V_113 ) &&
! F_20 ( V_6 , V_134 ) )
return;
V_143 = F_51 ( V_6 ) ;
F_66 ( & V_149 , V_6 ) ;
if ( V_143 ) {
F_98 ( & V_149 , V_143 , true ) ;
} else {
F_64 ( & V_149 ) ;
F_57 ( & V_149 ) ;
F_74 ( & V_149 ) ;
}
F_67 ( & V_149 , F_365 ) ;
}
int F_367 ( void )
{
return F_368 ( & V_784 ) ;
}
void F_369 ( void )
{
F_370 ( & V_784 ) ;
}
