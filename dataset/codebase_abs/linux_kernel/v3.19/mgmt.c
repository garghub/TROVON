static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 < F_2 ( V_2 ) )
return V_2 [ V_1 ] ;
return V_3 ;
}
static int F_3 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_4 ( sizeof( * V_14 ) + V_8 , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = ( void * ) F_5 ( V_12 , sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_6 ( V_4 ) ;
if ( V_6 )
V_14 -> V_18 = F_6 ( V_6 -> V_19 ) ;
else
V_14 -> V_18 = F_6 ( V_20 ) ;
V_14 -> V_21 = F_6 ( V_8 ) ;
if ( V_7 )
memcpy ( F_5 ( V_12 , V_8 ) , V_7 , V_8 ) ;
F_7 ( V_12 ) ;
F_8 ( V_12 , V_10 ) ;
F_9 ( V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_22 , T_2 V_18 , T_2 V_23 , T_1 V_24 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_25 * V_26 ;
int V_27 ;
F_11 ( L_1 , V_22 , V_18 , V_23 , V_24 ) ;
V_12 = F_4 ( sizeof( * V_14 ) + sizeof( * V_26 ) , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = ( void * ) F_5 ( V_12 , sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_6 ( V_28 ) ;
V_14 -> V_18 = F_6 ( V_18 ) ;
V_14 -> V_21 = F_6 ( sizeof( * V_26 ) ) ;
V_26 = ( void * ) F_5 ( V_12 , sizeof( * V_26 ) ) ;
V_26 -> V_24 = V_24 ;
V_26 -> V_17 = F_6 ( V_23 ) ;
V_27 = F_12 ( V_22 , V_12 ) ;
if ( V_27 < 0 )
F_9 ( V_12 ) ;
return V_27 ;
}
static int F_13 ( struct V_9 * V_22 , T_2 V_18 , T_2 V_23 , T_1 V_24 ,
void * V_29 , T_3 V_30 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_31 * V_26 ;
int V_27 ;
F_11 ( L_2 , V_22 ) ;
V_12 = F_4 ( sizeof( * V_14 ) + sizeof( * V_26 ) + V_30 , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = ( void * ) F_5 ( V_12 , sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_6 ( V_32 ) ;
V_14 -> V_18 = F_6 ( V_18 ) ;
V_14 -> V_21 = F_6 ( sizeof( * V_26 ) + V_30 ) ;
V_26 = ( void * ) F_5 ( V_12 , sizeof( * V_26 ) + V_30 ) ;
V_26 -> V_17 = F_6 ( V_23 ) ;
V_26 -> V_24 = V_24 ;
if ( V_29 )
memcpy ( V_26 -> V_7 , V_29 , V_30 ) ;
V_27 = F_12 ( V_22 , V_12 ) ;
if ( V_27 < 0 )
F_9 ( V_12 ) ;
return V_27 ;
}
static int F_14 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_33 V_29 ;
F_11 ( L_2 , V_22 ) ;
V_29 . V_34 = V_35 ;
V_29 . V_36 = F_6 ( V_37 ) ;
return F_13 ( V_22 , V_20 , V_38 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
}
static int F_15 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_39 * V_29 ;
const T_2 V_40 = F_2 ( V_41 ) ;
const T_2 V_42 = F_2 ( V_43 ) ;
T_4 * V_17 ;
T_3 V_44 ;
int V_45 , V_27 ;
F_11 ( L_2 , V_22 ) ;
V_44 = sizeof( * V_29 ) + ( ( V_40 + V_42 ) * sizeof( T_2 ) ) ;
V_29 = F_16 ( V_44 , V_15 ) ;
if ( ! V_29 )
return - V_16 ;
V_29 -> V_40 = F_6 ( V_40 ) ;
V_29 -> V_42 = F_6 ( V_42 ) ;
for ( V_45 = 0 , V_17 = V_29 -> V_46 ; V_45 < V_40 ; V_45 ++ , V_17 ++ )
F_17 ( V_41 [ V_45 ] , V_17 ) ;
for ( V_45 = 0 ; V_45 < V_42 ; V_45 ++ , V_17 ++ )
F_17 ( V_43 [ V_45 ] , V_17 ) ;
V_27 = F_13 ( V_22 , V_20 , V_47 , 0 , V_29 ,
V_44 ) ;
F_18 ( V_29 ) ;
return V_27 ;
}
static int F_19 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_48 * V_29 ;
struct V_5 * V_49 ;
T_3 V_30 ;
T_2 V_50 ;
int V_27 ;
F_11 ( L_2 , V_22 ) ;
F_20 ( & V_51 ) ;
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( V_49 -> V_52 == V_53 &&
! F_22 ( V_54 , & V_49 -> V_55 ) )
V_50 ++ ;
}
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
V_29 = F_16 ( V_30 , V_56 ) ;
if ( ! V_29 ) {
F_23 ( & V_51 ) ;
return - V_16 ;
}
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( F_22 ( V_57 , & V_49 -> V_55 ) ||
F_22 ( V_58 , & V_49 -> V_55 ) ||
F_22 ( V_59 , & V_49 -> V_55 ) )
continue;
if ( F_22 ( V_60 , & V_49 -> V_61 ) )
continue;
if ( V_49 -> V_52 == V_53 &&
! F_22 ( V_54 , & V_49 -> V_55 ) ) {
V_29 -> V_18 [ V_50 ++ ] = F_6 ( V_49 -> V_19 ) ;
F_11 ( L_3 , V_49 -> V_19 ) ;
}
}
V_29 -> V_62 = F_6 ( V_50 ) ;
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
F_23 ( & V_51 ) ;
V_27 = F_13 ( V_22 , V_20 , V_63 , 0 , V_29 ,
V_30 ) ;
F_18 ( V_29 ) ;
return V_27 ;
}
static int F_24 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_64 * V_29 ;
struct V_5 * V_49 ;
T_3 V_30 ;
T_2 V_50 ;
int V_27 ;
F_11 ( L_2 , V_22 ) ;
F_20 ( & V_51 ) ;
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( V_49 -> V_52 == V_53 &&
F_22 ( V_54 , & V_49 -> V_55 ) )
V_50 ++ ;
}
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
V_29 = F_16 ( V_30 , V_56 ) ;
if ( ! V_29 ) {
F_23 ( & V_51 ) ;
return - V_16 ;
}
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( F_22 ( V_57 , & V_49 -> V_55 ) ||
F_22 ( V_58 , & V_49 -> V_55 ) ||
F_22 ( V_59 , & V_49 -> V_55 ) )
continue;
if ( F_22 ( V_60 , & V_49 -> V_61 ) )
continue;
if ( V_49 -> V_52 == V_53 &&
F_22 ( V_54 , & V_49 -> V_55 ) ) {
V_29 -> V_18 [ V_50 ++ ] = F_6 ( V_49 -> V_19 ) ;
F_11 ( L_3 , V_49 -> V_19 ) ;
}
}
V_29 -> V_62 = F_6 ( V_50 ) ;
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
F_23 ( & V_51 ) ;
V_27 = F_13 ( V_22 , V_20 , V_65 ,
0 , V_29 , V_30 ) ;
F_18 ( V_29 ) ;
return V_27 ;
}
static bool F_25 ( struct V_5 * V_6 )
{
if ( F_22 ( V_66 , & V_6 -> V_61 ) &&
! F_22 ( V_67 , & V_6 -> V_55 ) )
return false ;
if ( F_22 ( V_68 , & V_6 -> V_61 ) &&
! F_26 ( & V_6 -> V_69 , V_70 ) )
return false ;
return true ;
}
static T_5 F_27 ( struct V_5 * V_6 )
{
T_6 V_71 = 0 ;
if ( F_22 ( V_66 , & V_6 -> V_61 ) &&
! F_22 ( V_67 , & V_6 -> V_55 ) )
V_71 |= V_72 ;
if ( F_22 ( V_68 , & V_6 -> V_61 ) &&
! F_26 ( & V_6 -> V_69 , V_70 ) )
V_71 |= V_73 ;
return F_28 ( V_71 ) ;
}
static int F_29 ( struct V_5 * V_6 , struct V_9 * V_74 )
{
T_5 V_71 = F_27 ( V_6 ) ;
return F_3 ( V_75 , V_6 , & V_71 ,
sizeof( V_71 ) , V_74 ) ;
}
static int F_30 ( struct V_9 * V_22 , T_2 V_17 , struct V_5 * V_6 )
{
T_5 V_71 = F_27 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_17 , 0 , & V_71 ,
sizeof( V_71 ) ) ;
}
static int F_31 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_76 V_29 ;
T_6 V_71 = 0 ;
F_11 ( L_4 , V_22 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_78 = F_6 ( V_6 -> V_78 ) ;
if ( F_22 ( V_66 , & V_6 -> V_61 ) )
V_71 |= V_72 ;
if ( V_6 -> V_79 )
V_71 |= V_73 ;
V_29 . V_80 = F_28 ( V_71 ) ;
V_29 . V_81 = F_27 ( V_6 ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_82 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
}
static T_6 F_34 ( struct V_5 * V_6 )
{
T_6 V_83 = 0 ;
V_83 |= V_84 ;
V_83 |= V_85 ;
V_83 |= V_86 ;
V_83 |= V_87 ;
V_83 |= V_88 ;
if ( F_35 ( V_6 ) ) {
if ( V_6 -> V_89 >= V_90 )
V_83 |= V_91 ;
V_83 |= V_92 ;
V_83 |= V_93 ;
if ( F_36 ( V_6 ) ) {
V_83 |= V_94 ;
V_83 |= V_95 ;
}
if ( F_37 ( V_6 ) ||
F_22 ( V_96 , & V_6 -> V_97 ) )
V_83 |= V_98 ;
}
if ( F_38 ( V_6 ) ) {
V_83 |= V_99 ;
V_83 |= V_100 ;
V_83 |= V_98 ;
V_83 |= V_101 ;
}
if ( F_22 ( V_66 , & V_6 -> V_61 ) ||
V_6 -> V_79 )
V_83 |= V_102 ;
return V_83 ;
}
static T_6 F_39 ( struct V_5 * V_6 )
{
T_6 V_83 = 0 ;
if ( F_40 ( V_6 ) )
V_83 |= V_84 ;
if ( F_22 ( V_103 , & V_6 -> V_55 ) )
V_83 |= V_87 ;
if ( F_22 ( V_104 , & V_6 -> V_55 ) )
V_83 |= V_91 ;
if ( F_22 ( V_105 , & V_6 -> V_55 ) )
V_83 |= V_88 ;
if ( F_22 ( V_106 , & V_6 -> V_55 ) )
V_83 |= V_85 ;
if ( F_22 ( V_107 , & V_6 -> V_55 ) )
V_83 |= V_92 ;
if ( F_22 ( V_108 , & V_6 -> V_55 ) )
V_83 |= V_99 ;
if ( F_22 ( V_109 , & V_6 -> V_55 ) )
V_83 |= V_93 ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) )
V_83 |= V_94 ;
if ( F_22 ( V_111 , & V_6 -> V_55 ) )
V_83 |= V_95 ;
if ( F_22 ( V_112 , & V_6 -> V_55 ) )
V_83 |= V_100 ;
if ( F_22 ( V_113 , & V_6 -> V_55 ) )
V_83 |= V_98 ;
if ( F_22 ( V_114 , & V_6 -> V_55 ) )
V_83 |= V_86 ;
if ( F_22 ( V_115 , & V_6 -> V_55 ) )
V_83 |= V_101 ;
return V_83 ;
}
static T_1 * F_41 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_21 )
{
T_1 * V_116 = V_7 , * V_117 = NULL ;
struct V_118 * V_119 ;
if ( V_21 < 4 )
return V_116 ;
F_21 (uuid, &hdev->uuids, list) {
T_2 V_120 ;
if ( V_119 -> V_121 != 16 )
continue;
V_120 = F_42 ( & V_119 -> V_119 [ 12 ] ) ;
if ( V_120 < 0x1100 )
continue;
if ( V_120 == V_122 )
continue;
if ( ! V_117 ) {
V_117 = V_116 ;
V_117 [ 0 ] = 1 ;
V_117 [ 1 ] = V_123 ;
V_116 += 2 ;
}
if ( ( V_116 - V_7 ) + sizeof( T_2 ) > V_21 ) {
V_117 [ 1 ] = V_124 ;
break;
}
* V_116 ++ = ( V_120 & 0x00ff ) ;
* V_116 ++ = ( V_120 & 0xff00 ) >> 8 ;
V_117 [ 0 ] += sizeof( V_120 ) ;
}
return V_116 ;
}
static T_1 * F_43 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_21 )
{
T_1 * V_116 = V_7 , * V_117 = NULL ;
struct V_118 * V_119 ;
if ( V_21 < 6 )
return V_116 ;
F_21 (uuid, &hdev->uuids, list) {
if ( V_119 -> V_121 != 32 )
continue;
if ( ! V_117 ) {
V_117 = V_116 ;
V_117 [ 0 ] = 1 ;
V_117 [ 1 ] = V_125 ;
V_116 += 2 ;
}
if ( ( V_116 - V_7 ) + sizeof( T_6 ) > V_21 ) {
V_117 [ 1 ] = V_126 ;
break;
}
memcpy ( V_116 , & V_119 -> V_119 [ 12 ] , sizeof( T_6 ) ) ;
V_116 += sizeof( T_6 ) ;
V_117 [ 0 ] += sizeof( T_6 ) ;
}
return V_116 ;
}
static T_1 * F_44 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_21 )
{
T_1 * V_116 = V_7 , * V_117 = NULL ;
struct V_118 * V_119 ;
if ( V_21 < 18 )
return V_116 ;
F_21 (uuid, &hdev->uuids, list) {
if ( V_119 -> V_121 != 128 )
continue;
if ( ! V_117 ) {
V_117 = V_116 ;
V_117 [ 0 ] = 1 ;
V_117 [ 1 ] = V_127 ;
V_116 += 2 ;
}
if ( ( V_116 - V_7 ) + 16 > V_21 ) {
V_117 [ 1 ] = V_128 ;
break;
}
memcpy ( V_116 , V_119 -> V_119 , 16 ) ;
V_116 += 16 ;
V_117 [ 0 ] += 16 ;
}
return V_116 ;
}
static struct V_129 * F_45 ( T_2 V_17 , struct V_5 * V_6 )
{
struct V_129 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_17 == V_17 )
return V_23 ;
}
return NULL ;
}
static struct V_129 * F_46 ( T_2 V_17 ,
struct V_5 * V_6 ,
const void * V_7 )
{
struct V_129 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_130 != V_7 )
continue;
if ( V_23 -> V_17 == V_17 )
return V_23 ;
}
return NULL ;
}
static T_1 F_47 ( struct V_5 * V_6 , T_1 * V_116 )
{
T_1 V_131 = 0 ;
T_3 V_132 ;
V_132 = strlen ( V_6 -> V_133 ) ;
if ( V_132 > 0 ) {
T_3 V_134 = V_135 - V_131 - 2 ;
if ( V_132 > V_134 ) {
V_132 = V_134 ;
V_116 [ 1 ] = V_136 ;
} else
V_116 [ 1 ] = V_137 ;
V_116 [ 0 ] = V_132 + 1 ;
memcpy ( V_116 + 2 , V_6 -> V_133 , V_132 ) ;
V_131 += ( V_132 + 2 ) ;
V_116 += ( V_132 + 2 ) ;
}
return V_131 ;
}
static void F_48 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_140 V_141 ;
T_1 V_21 ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_21 = F_47 ( V_6 , V_141 . V_7 ) ;
if ( V_6 -> V_142 == V_21 &&
memcmp ( V_141 . V_7 , V_6 -> V_143 , V_21 ) == 0 )
return;
memcpy ( V_6 -> V_143 , V_141 . V_7 , sizeof( V_141 . V_7 ) ) ;
V_6 -> V_142 = V_21 ;
V_141 . V_144 = V_21 ;
F_49 ( V_139 , V_145 , sizeof( V_141 ) , & V_141 ) ;
}
static T_1 F_50 ( struct V_5 * V_6 )
{
struct V_129 * V_23 ;
V_23 = F_45 ( V_146 , V_6 ) ;
if ( V_23 ) {
struct V_147 * V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 == 0x01 )
return V_150 ;
else if ( V_141 -> V_149 == 0x02 )
return V_151 ;
} else {
if ( F_22 ( V_152 , & V_6 -> V_55 ) )
return V_151 ;
else if ( F_22 ( V_105 , & V_6 -> V_55 ) )
return V_150 ;
}
return 0 ;
}
static T_1 F_51 ( struct V_5 * V_6 , T_1 * V_116 )
{
T_1 V_131 = 0 , V_153 = 0 ;
V_153 |= F_50 ( V_6 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
V_153 |= V_154 ;
if ( V_153 ) {
F_11 ( L_5 , V_153 ) ;
V_116 [ 0 ] = 2 ;
V_116 [ 1 ] = V_155 ;
V_116 [ 2 ] = V_153 ;
V_131 += 3 ;
V_116 += 3 ;
}
if ( V_6 -> V_156 != V_157 ) {
V_116 [ 0 ] = 2 ;
V_116 [ 1 ] = V_158 ;
V_116 [ 2 ] = ( T_1 ) V_6 -> V_156 ;
V_131 += 3 ;
V_116 += 3 ;
}
return V_131 ;
}
static void F_52 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_159 V_141 ;
T_1 V_21 ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_21 = F_51 ( V_6 , V_141 . V_7 ) ;
if ( V_6 -> V_160 == V_21 &&
memcmp ( V_141 . V_7 , V_6 -> V_161 , V_21 ) == 0 )
return;
memcpy ( V_6 -> V_161 , V_141 . V_7 , sizeof( V_141 . V_7 ) ) ;
V_6 -> V_160 = V_21 ;
V_141 . V_144 = V_21 ;
F_49 ( V_139 , V_162 , sizeof( V_141 ) , & V_141 ) ;
}
int F_53 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
F_54 ( & V_139 , V_6 ) ;
F_52 ( & V_139 ) ;
return F_55 ( & V_139 , NULL ) ;
}
static void F_56 ( struct V_5 * V_6 , T_1 * V_7 )
{
T_1 * V_116 = V_7 ;
T_3 V_132 ;
V_132 = strlen ( V_6 -> V_133 ) ;
if ( V_132 > 0 ) {
if ( V_132 > 48 ) {
V_132 = 48 ;
V_116 [ 1 ] = V_136 ;
} else
V_116 [ 1 ] = V_137 ;
V_116 [ 0 ] = V_132 + 1 ;
memcpy ( V_116 + 2 , V_6 -> V_133 , V_132 ) ;
V_116 += ( V_132 + 2 ) ;
}
if ( V_6 -> V_163 != V_157 ) {
V_116 [ 0 ] = 2 ;
V_116 [ 1 ] = V_158 ;
V_116 [ 2 ] = ( T_1 ) V_6 -> V_163 ;
V_116 += 3 ;
}
if ( V_6 -> V_164 > 0 ) {
V_116 [ 0 ] = 9 ;
V_116 [ 1 ] = V_165 ;
F_17 ( V_6 -> V_164 , V_116 + 2 ) ;
F_17 ( V_6 -> V_166 , V_116 + 4 ) ;
F_17 ( V_6 -> V_167 , V_116 + 6 ) ;
F_17 ( V_6 -> V_168 , V_116 + 8 ) ;
V_116 += 10 ;
}
V_116 = F_41 ( V_6 , V_116 , V_169 - ( V_116 - V_7 ) ) ;
V_116 = F_43 ( V_6 , V_116 , V_169 - ( V_116 - V_7 ) ) ;
V_116 = F_44 ( V_6 , V_116 , V_169 - ( V_116 - V_7 ) ) ;
}
static void F_57 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_170 V_141 ;
if ( ! F_40 ( V_6 ) )
return;
if ( ! F_58 ( V_6 ) )
return;
if ( ! F_22 ( V_110 , & V_6 -> V_55 ) )
return;
if ( F_22 ( V_171 , & V_6 -> V_55 ) )
return;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
F_56 ( V_6 , V_141 . V_7 ) ;
if ( memcmp ( V_141 . V_7 , V_6 -> V_172 , sizeof( V_141 . V_7 ) ) == 0 )
return;
memcpy ( V_6 -> V_172 , V_141 . V_7 , sizeof( V_141 . V_7 ) ) ;
F_49 ( V_139 , V_173 , sizeof( V_141 ) , & V_141 ) ;
}
static T_1 F_59 ( struct V_5 * V_6 )
{
struct V_118 * V_119 ;
T_1 V_149 = 0 ;
F_21 (uuid, &hdev->uuids, list)
V_149 |= V_119 -> V_174 ;
return V_149 ;
}
static void F_60 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
T_1 V_175 [ 3 ] ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_40 ( V_6 ) )
return;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return;
if ( F_22 ( V_171 , & V_6 -> V_55 ) )
return;
V_175 [ 0 ] = V_6 -> V_176 ;
V_175 [ 1 ] = V_6 -> V_177 ;
V_175 [ 2 ] = F_59 ( V_6 ) ;
if ( F_22 ( V_152 , & V_6 -> V_55 ) )
V_175 [ 1 ] |= 0x20 ;
if ( memcmp ( V_175 , V_6 -> V_178 , 3 ) == 0 )
return;
F_49 ( V_139 , V_179 , sizeof( V_175 ) , V_175 ) ;
}
static bool F_61 ( struct V_5 * V_6 )
{
struct V_129 * V_23 ;
V_23 = F_45 ( V_180 , V_6 ) ;
if ( V_23 ) {
struct V_147 * V_141 = V_23 -> V_148 ;
return V_141 -> V_149 ;
}
return F_22 ( V_103 , & V_6 -> V_55 ) ;
}
static void F_62 ( struct V_138 * V_139 )
{
T_1 V_181 = 0x00 ;
F_49 ( V_139 , V_182 , sizeof( V_181 ) , & V_181 ) ;
}
static void F_63 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_183 V_141 ;
T_1 V_184 , V_181 = 0x01 ;
bool V_185 ;
if ( F_64 ( V_6 , V_186 ) > 0 )
return;
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_62 ( V_139 ) ;
F_65 ( V_187 , & V_6 -> V_55 ) ;
V_185 = F_61 ( V_6 ) ;
if ( F_66 ( V_139 , ! V_185 , & V_184 ) < 0 )
return;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_188 = F_6 ( V_6 -> V_189 ) ;
V_141 . V_190 = F_6 ( V_6 -> V_191 ) ;
V_141 . type = V_185 ? V_192 : V_193 ;
V_141 . V_194 = V_184 ;
V_141 . V_195 = V_6 -> V_196 ;
F_49 ( V_139 , V_197 , sizeof( V_141 ) , & V_141 ) ;
F_49 ( V_139 , V_182 , sizeof( V_181 ) , & V_181 ) ;
}
static void F_67 ( struct V_198 * V_199 )
{
struct V_5 * V_6 = F_68 ( V_199 , struct V_5 ,
V_200 . V_199 ) ;
struct V_138 V_139 ;
if ( ! F_69 ( V_171 , & V_6 -> V_55 ) )
return;
F_54 ( & V_139 , V_6 ) ;
F_32 ( V_6 ) ;
F_57 ( & V_139 ) ;
F_60 ( & V_139 ) ;
F_33 ( V_6 ) ;
F_55 ( & V_139 , NULL ) ;
}
static void F_70 ( struct V_198 * V_199 )
{
struct V_5 * V_6 = F_68 ( V_199 , struct V_5 ,
F_70 . V_199 ) ;
struct V_138 V_139 ;
F_11 ( L_7 ) ;
F_71 ( V_201 , & V_6 -> V_55 ) ;
if ( ! F_22 ( V_112 , & V_6 -> V_55 ) )
return;
F_54 ( & V_139 , V_6 ) ;
F_63 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
}
static void F_72 ( struct V_9 * V_22 , struct V_5 * V_6 )
{
if ( F_73 ( V_202 , & V_6 -> V_55 ) )
return;
F_74 ( & V_6 -> V_200 , F_67 ) ;
F_74 ( & V_6 -> F_70 , F_70 ) ;
F_65 ( V_106 , & V_6 -> V_55 ) ;
}
static int F_75 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_203 V_29 ;
F_11 ( L_4 , V_22 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_204 , & V_6 -> V_204 ) ;
V_29 . V_34 = V_6 -> V_89 ;
V_29 . V_78 = F_6 ( V_6 -> V_78 ) ;
V_29 . V_205 = F_28 ( F_34 ( V_6 ) ) ;
V_29 . V_206 = F_28 ( F_39 ( V_6 ) ) ;
memcpy ( V_29 . V_178 , V_6 -> V_178 , 3 ) ;
memcpy ( V_29 . V_77 , V_6 -> V_133 , sizeof( V_6 -> V_133 ) ) ;
memcpy ( V_29 . V_207 , V_6 -> V_207 , sizeof( V_6 -> V_207 ) ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_208 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
}
static void F_77 ( struct V_129 * V_23 )
{
F_78 ( V_23 -> V_22 ) ;
F_18 ( V_23 -> V_148 ) ;
F_18 ( V_23 ) ;
}
static struct V_129 * F_79 ( struct V_9 * V_22 , T_2 V_17 ,
struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_129 * V_23 ;
V_23 = F_80 ( sizeof( * V_23 ) , V_15 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_17 = V_17 ;
V_23 -> V_18 = V_6 -> V_19 ;
V_23 -> V_148 = F_81 ( V_7 , V_21 , V_15 ) ;
if ( ! V_23 -> V_148 ) {
F_18 ( V_23 ) ;
return NULL ;
}
V_23 -> V_209 = V_21 ;
V_23 -> V_22 = V_22 ;
F_82 ( V_22 ) ;
F_83 ( & V_23 -> V_210 , & V_6 -> V_211 ) ;
return V_23 ;
}
static void F_84 ( T_2 V_17 , struct V_5 * V_6 ,
void (* F_85)( struct V_129 * V_23 ,
void * V_7 ) ,
void * V_7 )
{
struct V_129 * V_23 , * V_212 ;
F_86 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_17 > 0 && V_23 -> V_17 != V_17 )
continue;
F_85 ( V_23 , V_7 ) ;
}
}
static void F_87 ( struct V_129 * V_23 )
{
F_88 ( & V_23 -> V_210 ) ;
F_77 ( V_23 ) ;
}
static int F_89 ( struct V_9 * V_22 , T_2 V_17 , struct V_5 * V_6 )
{
T_5 V_83 = F_28 ( F_39 ( V_6 ) ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_17 , 0 , & V_83 ,
sizeof( V_83 ) ) ;
}
static void F_90 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_8 , V_6 -> V_77 , V_24 ) ;
if ( F_91 ( V_6 ) == 0 ) {
F_92 ( & V_6 -> V_213 ) ;
F_93 ( V_6 -> V_214 , & V_6 -> V_213 . V_199 ) ;
}
}
static bool F_94 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_215 V_141 ;
struct V_216 * V_217 ;
switch ( V_6 -> V_218 . V_219 ) {
case V_220 :
if ( F_22 ( V_221 , & V_6 -> V_153 ) ) {
F_49 ( V_139 , V_222 , 0 , NULL ) ;
} else {
F_92 ( & V_6 -> V_223 ) ;
F_95 ( V_139 ) ;
}
return true ;
case V_224 :
V_217 = F_96 ( V_6 , V_70 ,
V_225 ) ;
if ( ! V_217 )
break;
F_76 ( & V_141 . V_204 , & V_217 -> V_7 . V_204 ) ;
F_49 ( V_139 , V_226 , sizeof( V_141 ) ,
& V_141 ) ;
return true ;
default:
if ( F_22 ( V_227 , & V_6 -> V_55 ) ) {
F_95 ( V_139 ) ;
return true ;
}
break;
}
return false ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
struct V_228 * V_229 ;
bool V_230 ;
int V_27 ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_231 , & V_6 -> V_153 ) ||
F_22 ( V_232 , & V_6 -> V_153 ) ) {
T_1 V_233 = 0x00 ;
F_49 ( & V_139 , V_234 , 1 , & V_233 ) ;
}
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_62 ( & V_139 ) ;
V_230 = F_94 ( & V_139 ) ;
F_21 (conn, &hdev->conn_hash.list, list) {
struct V_235 V_236 ;
struct V_237 V_238 ;
switch ( V_229 -> V_219 ) {
case V_239 :
case V_240 :
V_236 . V_241 = F_6 ( V_229 -> V_241 ) ;
V_236 . V_242 = 0x15 ;
F_49 ( & V_139 , V_243 , sizeof( V_236 ) , & V_236 ) ;
break;
case V_244 :
if ( V_229 -> type == V_186 )
F_49 ( & V_139 , V_245 ,
0 , NULL ) ;
else if ( V_229 -> type == V_246 )
F_49 ( & V_139 , V_247 ,
6 , & V_229 -> V_248 ) ;
break;
case V_249 :
F_76 ( & V_238 . V_204 , & V_229 -> V_248 ) ;
V_238 . V_242 = 0x15 ;
if ( V_229 -> type == V_246 )
F_49 ( & V_139 , V_250 ,
sizeof( V_238 ) , & V_238 ) ;
else if ( V_229 -> type == V_251 )
F_49 ( & V_139 , V_252 ,
sizeof( V_238 ) , & V_238 ) ;
break;
}
}
V_27 = F_55 ( & V_139 , F_90 ) ;
if ( ! V_27 && V_230 )
F_98 ( V_6 , V_253 ) ;
return V_27 ;
}
static int F_99 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_254 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( F_45 ( V_254 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_254 ,
V_256 ) ;
goto V_257;
}
if ( F_69 ( V_258 , & V_6 -> V_55 ) ) {
F_92 ( & V_6 -> V_213 ) ;
if ( V_141 -> V_149 ) {
F_79 ( V_22 , V_254 , V_6 ,
V_7 , V_21 ) ;
V_27 = F_100 ( V_6 , 1 ) ;
goto V_257;
}
}
if ( ! ! V_141 -> V_149 == F_40 ( V_6 ) ) {
V_27 = F_89 ( V_22 , V_254 , V_6 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_254 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
if ( V_141 -> V_149 ) {
F_93 ( V_6 -> V_214 , & V_6 -> V_259 ) ;
V_27 = 0 ;
} else {
V_27 = F_97 ( V_6 ) ;
if ( ! V_27 )
F_101 ( V_6 -> V_214 , & V_6 -> V_213 ,
V_260 ) ;
if ( V_27 == - V_261 ) {
F_92 ( & V_6 -> V_213 ) ;
F_93 ( V_6 -> V_214 , & V_6 -> V_213 . V_199 ) ;
V_27 = 0 ;
}
}
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_102 ( struct V_5 * V_6 , struct V_9 * V_74 )
{
T_5 V_26 ;
V_26 = F_28 ( F_39 ( V_6 ) ) ;
return F_3 ( V_262 , V_6 , & V_26 , sizeof( V_26 ) , V_74 ) ;
}
int F_103 ( struct V_5 * V_6 )
{
return F_102 ( V_6 , NULL ) ;
}
static void F_104 ( struct V_129 * V_23 , void * V_7 )
{
struct V_263 * V_264 = V_7 ;
F_89 ( V_23 -> V_22 , V_23 -> V_17 , V_264 -> V_6 ) ;
F_88 ( & V_23 -> V_210 ) ;
if ( V_264 -> V_22 == NULL ) {
V_264 -> V_22 = V_23 -> V_22 ;
F_82 ( V_264 -> V_22 ) ;
}
F_77 ( V_23 ) ;
}
static void F_105 ( struct V_129 * V_23 , void * V_7 )
{
T_1 * V_24 = V_7 ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , * V_24 ) ;
F_87 ( V_23 ) ;
}
static void F_106 ( struct V_129 * V_23 , void * V_7 )
{
if ( V_23 -> F_13 ) {
T_1 * V_24 = V_7 ;
V_23 -> F_13 ( V_23 , * V_24 ) ;
F_87 ( V_23 ) ;
return;
}
F_105 ( V_23 , V_7 ) ;
}
static void F_107 ( struct V_129 * V_23 , T_1 V_24 )
{
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 , V_23 -> V_148 ,
V_23 -> V_209 ) ;
}
static void F_108 ( struct V_129 * V_23 , T_1 V_24 )
{
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 , V_23 -> V_148 ,
sizeof( struct V_265 ) ) ;
}
static T_1 F_109 ( struct V_5 * V_6 )
{
if ( ! F_35 ( V_6 ) )
return V_266 ;
else if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return V_267 ;
else
return V_268 ;
}
static T_1 F_110 ( struct V_5 * V_6 )
{
if ( ! F_38 ( V_6 ) )
return V_266 ;
else if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return V_267 ;
else
return V_268 ;
}
static void F_111 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
struct V_147 * V_141 ;
struct V_138 V_139 ;
bool V_269 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_146 , V_6 ) ;
if ( ! V_23 )
goto V_270;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_271 ) ;
F_65 ( V_152 , & V_6 -> V_55 ) ;
goto V_272;
}
V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 ) {
V_269 = ! F_73 ( V_105 ,
& V_6 -> V_55 ) ;
if ( V_6 -> V_273 > 0 ) {
int V_274 = F_112 ( V_6 -> V_273 * 1000 ) ;
F_101 ( V_6 -> V_275 , & V_6 -> V_276 ,
V_274 ) ;
}
} else {
V_269 = F_69 ( V_105 ,
& V_6 -> V_55 ) ;
}
F_89 ( V_23 -> V_22 , V_146 , V_6 ) ;
if ( V_269 )
F_102 ( V_6 , V_23 -> V_22 ) ;
F_54 ( & V_139 , V_6 ) ;
F_113 ( V_6 , & V_139 ) ;
F_60 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
V_272:
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_114 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_277 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_2 V_278 ;
T_1 V_233 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) &&
! F_22 ( V_107 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_267 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 && V_141 -> V_149 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_255 ) ;
V_278 = F_115 ( V_141 -> V_278 ) ;
if ( ( V_141 -> V_149 == 0x00 && V_278 > 0 ) ||
( V_141 -> V_149 == 0x02 && V_278 == 0 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) && V_278 > 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_279 ) ;
goto V_257;
}
if ( F_45 ( V_146 , V_6 ) ||
F_45 ( V_180 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_256 ) ;
goto V_257;
}
if ( ! F_22 ( V_103 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_267 ) ;
goto V_257;
}
if ( ! F_40 ( V_6 ) ) {
bool V_269 = false ;
if ( ! ! V_141 -> V_149 != F_22 ( V_105 , & V_6 -> V_55 ) ) {
F_116 ( V_105 , & V_6 -> V_55 ) ;
V_269 = true ;
}
V_27 = F_89 ( V_22 , V_146 , V_6 ) ;
if ( V_27 < 0 )
goto V_257;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_257;
}
if ( ! ! V_141 -> V_149 == F_22 ( V_105 , & V_6 -> V_55 ) &&
( V_141 -> V_149 == 0x02 ) == F_22 ( V_152 ,
& V_6 -> V_55 ) ) {
F_92 ( & V_6 -> V_276 ) ;
V_6 -> V_273 = V_278 ;
if ( V_141 -> V_149 && V_6 -> V_273 > 0 ) {
int V_274 = F_112 ( V_6 -> V_273 * 1000 ) ;
F_101 ( V_6 -> V_275 , & V_6 -> V_276 ,
V_274 ) ;
}
V_27 = F_89 ( V_22 , V_146 , V_6 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_146 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
F_92 ( & V_6 -> V_276 ) ;
V_6 -> V_273 = V_278 ;
if ( V_141 -> V_149 == 0x02 )
F_71 ( V_152 , & V_6 -> V_55 ) ;
else
F_65 ( V_152 , & V_6 -> V_55 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
goto V_280;
V_233 = V_281 ;
if ( V_141 -> V_149 ) {
struct V_282 V_283 ;
if ( V_141 -> V_149 == 0x02 ) {
V_283 . V_284 = F_117 ( T_1 , V_6 -> V_284 , 2 ) ;
V_283 . V_285 [ 0 ] = 0x00 ;
V_283 . V_285 [ 1 ] = 0x8b ;
V_283 . V_285 [ 2 ] = 0x9e ;
V_283 . V_285 [ 3 ] = 0x33 ;
V_283 . V_285 [ 4 ] = 0x8b ;
V_283 . V_285 [ 5 ] = 0x9e ;
} else {
V_283 . V_284 = 1 ;
V_283 . V_285 [ 0 ] = 0x33 ;
V_283 . V_285 [ 1 ] = 0x8b ;
V_283 . V_285 [ 2 ] = 0x9e ;
}
F_49 ( & V_139 , V_286 ,
( V_283 . V_284 * 3 ) + 1 , & V_283 ) ;
V_233 |= V_287 ;
} else {
F_65 ( V_152 , & V_6 -> V_55 ) ;
}
F_49 ( & V_139 , V_234 , sizeof( V_233 ) , & V_233 ) ;
V_280:
F_52 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_111 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_118 ( struct V_138 * V_139 , bool V_181 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_288 V_289 ;
T_1 type ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return;
if ( V_6 -> V_89 < V_90 )
return;
if ( V_181 ) {
type = V_290 ;
V_289 . V_291 = F_6 ( 0x0100 ) ;
} else {
type = V_292 ;
V_289 . V_291 = F_6 ( 0x0800 ) ;
}
V_289 . V_293 = F_6 ( 0x0012 ) ;
if ( F_119 ( V_6 -> V_294 ) != V_289 . V_291 ||
F_119 ( V_6 -> V_295 ) != V_289 . V_293 )
F_49 ( V_139 , V_296 ,
sizeof( V_289 ) , & V_289 ) ;
if ( V_6 -> V_297 != type )
F_49 ( V_139 , V_298 , 1 , & type ) ;
}
static void F_120 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
struct V_147 * V_141 ;
bool V_299 , V_300 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_180 , V_6 ) ;
if ( ! V_23 )
goto V_270;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_271 ) ;
goto V_272;
}
V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 ) {
V_299 = ! F_73 ( V_103 ,
& V_6 -> V_55 ) ;
V_300 = false ;
} else {
V_299 = F_69 ( V_103 ,
& V_6 -> V_55 ) ;
V_300 = F_69 ( V_105 ,
& V_6 -> V_55 ) ;
}
F_89 ( V_23 -> V_22 , V_180 , V_6 ) ;
if ( V_299 || V_300 ) {
F_102 ( V_6 , V_23 -> V_22 ) ;
F_113 ( V_6 , NULL ) ;
if ( V_300 )
F_53 ( V_6 ) ;
F_121 ( V_6 ) ;
}
V_272:
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_122 ( struct V_5 * V_6 ,
struct V_9 * V_22 , T_1 V_149 )
{
bool V_269 = false ;
int V_27 ;
if ( ! ! V_149 != F_22 ( V_103 , & V_6 -> V_55 ) )
V_269 = true ;
if ( V_149 ) {
F_71 ( V_103 , & V_6 -> V_55 ) ;
} else {
F_65 ( V_103 , & V_6 -> V_55 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_180 , V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_269 ) {
F_113 ( V_6 , NULL ) ;
F_121 ( V_6 ) ;
return F_102 ( V_6 , V_22 ) ;
}
return 0 ;
}
static int F_123 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_1 V_233 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) &&
! F_22 ( V_107 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_180 ,
V_267 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_180 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_122 ( V_6 , V_22 , V_141 -> V_149 ) ;
goto V_257;
}
if ( F_45 ( V_146 , V_6 ) ||
F_45 ( V_180 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_180 ,
V_256 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_180 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
F_54 ( & V_139 , V_6 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) ) {
if ( ! V_141 -> V_149 ) {
F_65 ( V_152 , & V_6 -> V_55 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
}
F_52 ( & V_139 ) ;
} else if ( V_141 -> V_149 != F_22 ( V_232 , & V_6 -> V_153 ) ) {
if ( V_141 -> V_149 ) {
V_233 = V_281 ;
} else {
if ( F_124 ( & V_6 -> V_301 ) )
V_233 = V_302 ;
else if ( F_22 ( V_231 , & V_6 -> V_153 ) )
V_233 = V_281 ;
else
goto V_303;
if ( F_22 ( V_231 , & V_6 -> V_153 ) &&
V_6 -> V_273 > 0 )
F_92 ( & V_6 -> V_276 ) ;
}
F_49 ( & V_139 , V_234 , 1 , & V_233 ) ;
}
V_303:
if ( V_141 -> V_149 || F_22 ( V_104 , & V_6 -> V_55 ) )
F_118 ( & V_139 , false ) ;
if ( F_22 ( V_112 , & V_6 -> V_55 ) )
F_63 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_120 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
if ( V_27 == - V_261 )
V_27 = F_122 ( V_6 , V_22 ,
V_141 -> V_149 ) ;
goto V_257;
}
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_125 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
bool V_269 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_304 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 )
V_269 = ! F_73 ( V_106 , & V_6 -> V_55 ) ;
else
V_269 = F_69 ( V_106 , & V_6 -> V_55 ) ;
V_27 = F_89 ( V_22 , V_304 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_126 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
T_1 V_149 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_109 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_305 ,
V_24 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_305 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_269 = false ;
if ( ! ! V_141 -> V_149 != F_22 ( V_109 ,
& V_6 -> V_55 ) ) {
F_116 ( V_109 , & V_6 -> V_55 ) ;
V_269 = true ;
}
V_27 = F_89 ( V_22 , V_305 , V_6 ) ;
if ( V_27 < 0 )
goto V_257;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_257;
}
if ( F_45 ( V_305 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_305 ,
V_256 ) ;
goto V_257;
}
V_149 = ! ! V_141 -> V_149 ;
if ( F_22 ( V_306 , & V_6 -> V_153 ) == V_149 ) {
V_27 = F_89 ( V_22 , V_305 , V_6 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_305 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_27 = F_127 ( V_6 , V_307 , sizeof( V_149 ) , & V_149 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_257;
}
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_128 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_109 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_308 , V_24 ) ;
if ( ! F_36 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_308 ,
V_266 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_308 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_269 ;
if ( V_141 -> V_149 ) {
V_269 = ! F_73 ( V_110 ,
& V_6 -> V_55 ) ;
} else {
V_269 = F_69 ( V_110 ,
& V_6 -> V_55 ) ;
if ( ! V_269 )
V_269 = F_69 ( V_111 ,
& V_6 -> V_55 ) ;
else
F_65 ( V_111 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_308 , V_6 ) ;
if ( V_27 < 0 )
goto V_257;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_257;
}
if ( F_45 ( V_308 , V_6 ) ||
F_45 ( V_309 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_308 ,
V_256 ) ;
goto V_257;
}
if ( ! ! V_141 -> V_149 == F_22 ( V_110 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_308 , V_6 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_308 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
if ( ! V_141 -> V_149 && F_22 ( V_310 , & V_6 -> V_55 ) )
F_127 ( V_6 , V_311 ,
sizeof( V_141 -> V_149 ) , & V_141 -> V_149 ) ;
V_27 = F_127 ( V_6 , V_312 , 1 , & V_141 -> V_149 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_257;
}
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_129 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
bool V_269 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_109 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_309 , V_24 ) ;
if ( ! F_36 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_309 ,
V_266 ) ;
if ( ! F_22 ( V_110 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_309 ,
V_267 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_309 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 ) {
V_269 = ! F_73 ( V_111 , & V_6 -> V_55 ) ;
} else {
if ( F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_309 ,
V_267 ) ;
goto V_270;
}
V_269 = F_69 ( V_111 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_309 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_130 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 } ;
F_32 ( V_6 ) ;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
F_84 ( V_313 , V_6 , F_105 ,
& V_271 ) ;
goto V_270;
}
F_84 ( V_313 , V_6 , F_104 , & V_264 ) ;
F_102 ( V_6 , V_264 . V_22 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
if ( F_22 ( V_108 , & V_6 -> V_55 ) ) {
struct V_138 V_139 ;
F_54 ( & V_139 , V_6 ) ;
F_52 ( & V_139 ) ;
F_48 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
F_121 ( V_6 ) ;
}
V_270:
F_33 ( V_6 ) ;
}
static int F_131 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_314 V_283 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
T_1 V_149 , V_315 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_313 ,
V_266 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_313 ,
V_255 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_313 ,
V_267 ) ;
F_32 ( V_6 ) ;
V_149 = ! ! V_141 -> V_149 ;
V_315 = F_132 ( V_6 ) ;
if ( ! F_40 ( V_6 ) || V_149 == V_315 ) {
bool V_269 = false ;
if ( V_149 != F_22 ( V_108 , & V_6 -> V_55 ) ) {
F_116 ( V_108 , & V_6 -> V_55 ) ;
V_269 = true ;
}
if ( ! V_149 && F_22 ( V_112 , & V_6 -> V_55 ) ) {
F_65 ( V_112 , & V_6 -> V_55 ) ;
V_269 = true ;
}
V_27 = F_89 ( V_22 , V_313 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_270;
}
if ( F_45 ( V_313 , V_6 ) ||
F_45 ( V_316 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_313 ,
V_256 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_313 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
F_54 ( & V_139 , V_6 ) ;
memset ( & V_283 , 0 , sizeof( V_283 ) ) ;
if ( V_149 ) {
V_283 . V_317 = V_149 ;
V_283 . V_318 = 0x00 ;
} else {
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_62 ( & V_139 ) ;
}
F_49 ( & V_139 , V_319 , sizeof( V_283 ) ,
& V_283 ) ;
V_27 = F_55 ( & V_139 , F_130 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_133 ( struct V_5 * V_6 )
{
struct V_129 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
switch ( V_23 -> V_17 ) {
case V_320 :
case V_321 :
case V_322 :
case V_254 :
return true ;
}
}
return false ;
}
static T_1 F_134 ( const T_1 * V_119 )
{
T_6 V_149 ;
if ( memcmp ( V_119 , V_323 , 12 ) )
return 128 ;
V_149 = F_135 ( & V_119 [ 12 ] ) ;
if ( V_149 > 0xffff )
return 32 ;
return 16 ;
}
static void F_136 ( struct V_5 * V_6 , T_2 V_324 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_324 , V_6 ) ;
if ( ! V_23 )
goto V_270;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , F_1 ( V_24 ) ,
V_6 -> V_178 , 3 ) ;
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static void F_137 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_10 , V_24 ) ;
F_136 ( V_6 , V_320 , V_24 ) ;
}
static int F_138 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_325 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
struct V_118 * V_119 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_133 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_256 ) ;
goto V_257;
}
V_119 = F_16 ( sizeof( * V_119 ) , V_15 ) ;
if ( ! V_119 ) {
V_27 = - V_16 ;
goto V_257;
}
memcpy ( V_119 -> V_119 , V_141 -> V_119 , 16 ) ;
V_119 -> V_174 = V_141 -> V_174 ;
V_119 -> V_121 = F_134 ( V_141 -> V_119 ) ;
F_139 ( & V_119 -> V_210 , & V_6 -> V_326 ) ;
F_54 ( & V_139 , V_6 ) ;
F_60 ( & V_139 ) ;
F_57 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_137 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_261 )
goto V_257;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_320 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_320 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_27 = 0 ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_140 ( struct V_5 * V_6 )
{
if ( ! F_40 ( V_6 ) )
return false ;
if ( ! F_73 ( V_171 , & V_6 -> V_55 ) ) {
F_101 ( V_6 -> V_275 , & V_6 -> V_200 ,
V_327 ) ;
return true ;
}
return false ;
}
static void F_141 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_10 , V_24 ) ;
F_136 ( V_6 , V_321 , V_24 ) ;
}
static int F_142 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_328 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_118 * V_264 , * V_212 ;
T_1 V_329 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_138 V_139 ;
int V_27 , V_330 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_133 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_321 ,
V_256 ) ;
goto V_270;
}
if ( memcmp ( V_141 -> V_119 , V_329 , 16 ) == 0 ) {
F_143 ( V_6 ) ;
if ( F_140 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_321 ,
0 , V_6 -> V_178 , 3 ) ;
goto V_270;
}
goto F_60;
}
V_330 = 0 ;
F_86 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_264 -> V_119 , V_141 -> V_119 , 16 ) != 0 )
continue;
F_88 ( & V_264 -> V_210 ) ;
F_18 ( V_264 ) ;
V_330 ++ ;
}
if ( V_330 == 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_321 ,
V_255 ) ;
goto V_270;
}
F_60:
F_54 ( & V_139 , V_6 ) ;
F_60 ( & V_139 ) ;
F_57 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_141 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_261 )
goto V_270;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_321 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_321 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
V_27 = 0 ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_144 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_10 , V_24 ) ;
F_136 ( V_6 , V_322 , V_24 ) ;
}
static int F_145 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_331 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_322 ,
V_266 ) ;
F_32 ( V_6 ) ;
if ( F_133 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_322 ,
V_256 ) ;
goto V_270;
}
if ( ( V_141 -> V_332 & 0x03 ) != 0 || ( V_141 -> V_333 & 0xe0 ) != 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_322 ,
V_255 ) ;
goto V_270;
}
V_6 -> V_177 = V_141 -> V_333 ;
V_6 -> V_176 = V_141 -> V_332 ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_270;
}
F_54 ( & V_139 , V_6 ) ;
if ( F_69 ( V_171 , & V_6 -> V_55 ) ) {
F_33 ( V_6 ) ;
F_146 ( & V_6 -> V_200 ) ;
F_32 ( V_6 ) ;
F_57 ( & V_139 ) ;
}
F_60 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_144 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_261 )
goto V_270;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_322 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
V_27 = 0 ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_147 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_334 * V_141 = V_7 ;
const T_2 V_335 = ( ( V_336 - sizeof( * V_141 ) ) /
sizeof( struct V_337 ) ) ;
T_2 V_338 , V_339 ;
bool V_269 ;
int V_45 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_340 ,
V_266 ) ;
V_338 = F_115 ( V_141 -> V_338 ) ;
if ( V_338 > V_335 ) {
F_148 ( L_11 ,
V_338 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_340 ,
V_255 ) ;
}
V_339 = sizeof( * V_141 ) + V_338 *
sizeof( struct V_337 ) ;
if ( V_339 != V_21 ) {
F_148 ( L_12 ,
V_339 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_340 ,
V_255 ) ;
}
if ( V_141 -> V_341 != 0x00 && V_141 -> V_341 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_340 ,
V_255 ) ;
F_11 ( L_13 , V_6 -> V_77 , V_141 -> V_341 ,
V_338 ) ;
for ( V_45 = 0 ; V_45 < V_338 ; V_45 ++ ) {
struct V_337 * V_342 = & V_141 -> V_343 [ V_45 ] ;
if ( V_342 -> V_344 . type != V_345 || V_342 -> type > 0x08 )
return F_10 ( V_22 , V_6 -> V_19 , V_340 ,
V_255 ) ;
}
F_32 ( V_6 ) ;
F_149 ( V_6 ) ;
if ( V_141 -> V_341 )
V_269 = ! F_73 ( V_114 ,
& V_6 -> V_55 ) ;
else
V_269 = F_69 ( V_114 ,
& V_6 -> V_55 ) ;
if ( V_269 )
F_102 ( V_6 , NULL ) ;
for ( V_45 = 0 ; V_45 < V_338 ; V_45 ++ ) {
struct V_337 * V_342 = & V_141 -> V_343 [ V_45 ] ;
if ( V_342 -> type == V_346 )
continue;
F_150 ( V_6 , NULL , & V_342 -> V_344 . V_204 , V_342 -> V_149 ,
V_342 -> type , V_342 -> V_347 , NULL ) ;
}
F_13 ( V_22 , V_6 -> V_19 , V_340 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return 0 ;
}
static int F_151 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_348 , struct V_9 * V_10 )
{
struct V_349 V_26 ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = V_348 ;
return F_3 ( V_350 , V_6 , & V_26 , sizeof( V_26 ) ,
V_10 ) ;
}
static int F_152 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_351 * V_141 = V_7 ;
struct V_352 V_29 ;
struct V_235 V_236 ;
struct V_129 * V_23 ;
struct V_228 * V_229 ;
int V_27 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_344 . V_204 , & V_141 -> V_344 . V_204 ) ;
V_29 . V_344 . type = V_141 -> V_344 . type ;
if ( ! F_153 ( V_141 -> V_344 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_353 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_141 -> V_354 != 0x00 && V_141 -> V_354 != 0x01 )
return F_13 ( V_22 , V_6 -> V_19 , V_353 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_353 ,
V_279 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
if ( V_141 -> V_344 . type == V_345 ) {
if ( V_141 -> V_354 )
V_229 = F_154 ( V_6 , V_246 ,
& V_141 -> V_344 . V_204 ) ;
else
V_229 = NULL ;
V_27 = F_155 ( V_6 , & V_141 -> V_344 . V_204 ) ;
} else {
T_1 V_348 ;
V_229 = F_154 ( V_6 , V_186 ,
& V_141 -> V_344 . V_204 ) ;
if ( V_229 ) {
F_71 ( V_355 , & V_229 -> V_153 ) ;
if ( ! V_141 -> V_354 )
V_229 = NULL ;
}
if ( V_141 -> V_344 . type == V_356 )
V_348 = V_357 ;
else
V_348 = V_358 ;
F_156 ( V_6 , & V_141 -> V_344 . V_204 , V_348 ) ;
V_27 = F_157 ( V_6 , & V_141 -> V_344 . V_204 , V_348 ) ;
}
if ( V_27 < 0 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_353 ,
V_359 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
if ( ! V_229 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_353 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
F_151 ( V_6 , & V_141 -> V_344 . V_204 , V_141 -> V_344 . type , V_22 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_353 , V_6 , V_141 ,
sizeof( * V_141 ) ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
V_23 -> F_13 = F_108 ;
V_236 . V_241 = F_6 ( V_229 -> V_241 ) ;
V_236 . V_242 = 0x13 ;
V_27 = F_127 ( V_6 , V_243 , sizeof( V_236 ) , & V_236 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int V_354 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_360 * V_141 = V_7 ;
struct V_361 V_29 ;
struct V_129 * V_23 ;
struct V_228 * V_229 ;
int V_27 ;
F_11 ( L_7 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_344 . V_204 , & V_141 -> V_344 . V_204 ) ;
V_29 . V_344 . type = V_141 -> V_344 . type ;
if ( ! F_153 ( V_141 -> V_344 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_362 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_22 ( V_363 , & V_6 -> V_153 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_362 ,
V_279 , & V_29 , sizeof( V_29 ) ) ;
goto V_257;
}
if ( F_45 ( V_362 , V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_362 ,
V_256 , & V_29 , sizeof( V_29 ) ) ;
goto V_257;
}
if ( V_141 -> V_344 . type == V_345 )
V_229 = F_154 ( V_6 , V_246 ,
& V_141 -> V_344 . V_204 ) ;
else
V_229 = F_154 ( V_6 , V_186 , & V_141 -> V_344 . V_204 ) ;
if ( ! V_229 || V_229 -> V_219 == V_364 || V_229 -> V_219 == V_365 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_362 ,
V_366 , & V_29 , sizeof( V_29 ) ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_362 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_23 -> F_13 = F_107 ;
V_27 = F_158 ( V_229 , V_367 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static T_1 F_159 ( T_1 V_368 , T_1 V_348 )
{
switch ( V_368 ) {
case V_186 :
switch ( V_348 ) {
case V_357 :
return V_356 ;
default:
return V_369 ;
}
default:
return V_345 ;
}
}
static int F_160 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_370 * V_29 ;
struct V_228 * V_371 ;
T_3 V_30 ;
int V_27 ;
T_2 V_45 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_372 ,
V_279 ) ;
goto V_270;
}
V_45 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_373 , & V_371 -> V_153 ) )
V_45 ++ ;
}
V_30 = sizeof( * V_29 ) + ( V_45 * sizeof( struct V_265 ) ) ;
V_29 = F_16 ( V_30 , V_15 ) ;
if ( ! V_29 ) {
V_27 = - V_16 ;
goto V_270;
}
V_45 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_373 , & V_371 -> V_153 ) )
continue;
F_76 ( & V_29 -> V_344 [ V_45 ] . V_204 , & V_371 -> V_248 ) ;
V_29 -> V_344 [ V_45 ] . type = F_159 ( V_371 -> type , V_371 -> V_374 ) ;
if ( V_371 -> type == V_251 || V_371 -> type == V_375 )
continue;
V_45 ++ ;
}
V_29 -> V_376 = F_6 ( V_45 ) ;
V_30 = sizeof( * V_29 ) + ( V_45 * sizeof( struct V_265 ) ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_372 , 0 , V_29 ,
V_30 ) ;
F_18 ( V_29 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_161 ( struct V_9 * V_22 , struct V_5 * V_6 ,
struct V_377 * V_141 )
{
struct V_129 * V_23 ;
int V_27 ;
V_23 = F_79 ( V_22 , V_378 , V_6 , V_141 ,
sizeof( * V_141 ) ) ;
if ( ! V_23 )
return - V_16 ;
V_27 = F_127 ( V_6 , V_379 ,
sizeof( V_141 -> V_344 . V_204 ) , & V_141 -> V_344 . V_204 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
return V_27 ;
}
static int F_162 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_228 * V_229 ;
struct V_380 * V_141 = V_7 ;
struct V_381 V_382 ;
struct V_129 * V_23 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_383 ,
V_279 ) ;
goto V_257;
}
V_229 = F_154 ( V_6 , V_246 , & V_141 -> V_344 . V_204 ) ;
if ( ! V_229 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_383 ,
V_366 ) ;
goto V_257;
}
if ( V_229 -> V_384 == V_385 && V_141 -> V_347 != 16 ) {
struct V_377 V_386 ;
memcpy ( & V_386 . V_344 , & V_141 -> V_344 , sizeof( V_386 . V_344 ) ) ;
F_148 ( L_14 ) ;
V_27 = F_161 ( V_22 , V_6 , & V_386 ) ;
if ( V_27 >= 0 )
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_383 ,
V_255 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_383 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_23 -> F_13 = F_108 ;
F_76 ( & V_382 . V_204 , & V_141 -> V_344 . V_204 ) ;
V_382 . V_347 = V_141 -> V_347 ;
memcpy ( V_382 . V_387 , V_141 -> V_387 , sizeof( V_382 . V_387 ) ) ;
V_27 = F_127 ( V_6 , V_388 , sizeof( V_382 ) , & V_382 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_163 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_389 * V_141 = V_7 ;
F_11 ( L_7 ) ;
if ( V_141 -> V_390 > V_391 )
return F_13 ( V_22 , V_6 -> V_19 , V_392 ,
V_255 , NULL , 0 ) ;
F_32 ( V_6 ) ;
V_6 -> V_390 = V_141 -> V_390 ;
F_11 ( L_15 , V_6 -> V_77 ,
V_6 -> V_390 ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_392 , 0 , NULL ,
0 ) ;
}
static struct V_129 * F_164 ( struct V_228 * V_229 )
{
struct V_5 * V_6 = V_229 -> V_6 ;
struct V_129 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_17 != V_393 )
continue;
if ( V_23 -> V_130 != V_229 )
continue;
return V_23 ;
}
return NULL ;
}
static void F_165 ( struct V_129 * V_23 , T_1 V_24 )
{
struct V_394 V_29 ;
struct V_228 * V_229 = V_23 -> V_130 ;
F_76 ( & V_29 . V_344 . V_204 , & V_229 -> V_248 ) ;
V_29 . V_344 . type = F_159 ( V_229 -> type , V_229 -> V_374 ) ;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_393 , V_24 ,
& V_29 , sizeof( V_29 ) ) ;
V_229 -> V_395 = NULL ;
V_229 -> V_396 = NULL ;
V_229 -> V_397 = NULL ;
F_166 ( V_229 ) ;
F_65 ( V_355 , & V_229 -> V_153 ) ;
F_167 ( V_229 ) ;
}
void F_168 ( struct V_228 * V_229 , bool V_398 )
{
T_1 V_24 = V_398 ? V_268 : V_3 ;
struct V_129 * V_23 ;
V_23 = F_164 ( V_229 ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , V_24 ) ;
F_87 ( V_23 ) ;
}
}
static void F_169 ( struct V_228 * V_229 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_16 , V_24 ) ;
V_23 = F_164 ( V_229 ) ;
if ( ! V_23 ) {
F_11 ( L_17 ) ;
return;
}
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
static void F_170 ( struct V_228 * V_229 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_16 , V_24 ) ;
if ( ! V_24 )
return;
V_23 = F_164 ( V_229 ) ;
if ( ! V_23 ) {
F_11 ( L_17 ) ;
return;
}
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
static int F_171 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_399 * V_141 = V_7 ;
struct V_394 V_29 ;
struct V_129 * V_23 ;
T_1 V_400 , V_401 ;
struct V_228 * V_229 ;
int V_27 ;
F_11 ( L_7 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_344 . V_204 , & V_141 -> V_344 . V_204 ) ;
V_29 . V_344 . type = V_141 -> V_344 . type ;
if ( ! F_153 ( V_141 -> V_344 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_393 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_141 -> V_402 > V_391 )
return F_13 ( V_22 , V_6 -> V_19 , V_393 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_393 ,
V_279 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
V_400 = V_403 ;
V_401 = V_404 ;
if ( V_141 -> V_344 . type == V_345 ) {
V_229 = F_172 ( V_6 , & V_141 -> V_344 . V_204 , V_400 ,
V_401 ) ;
} else {
T_1 V_348 ;
if ( V_141 -> V_344 . type == V_356 )
V_348 = V_357 ;
else
V_348 = V_358 ;
F_173 ( V_6 , & V_141 -> V_344 . V_204 , V_348 ) ;
V_229 = F_174 ( V_6 , & V_141 -> V_344 . V_204 , V_348 ,
V_400 , V_405 ,
V_406 ) ;
}
if ( F_175 ( V_229 ) ) {
int V_24 ;
if ( F_176 ( V_229 ) == - V_407 )
V_24 = V_256 ;
else
V_24 = V_408 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_393 ,
V_24 , & V_29 ,
sizeof( V_29 ) ) ;
goto V_270;
}
if ( V_229 -> V_395 ) {
F_166 ( V_229 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_393 ,
V_256 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_393 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
F_166 ( V_229 ) ;
goto V_270;
}
V_23 -> F_13 = F_165 ;
if ( V_141 -> V_344 . type == V_345 ) {
V_229 -> V_395 = F_169 ;
V_229 -> V_396 = F_169 ;
V_229 -> V_397 = F_169 ;
} else {
V_229 -> V_395 = F_170 ;
V_229 -> V_396 = F_170 ;
V_229 -> V_397 = F_170 ;
}
V_229 -> V_390 = V_141 -> V_402 ;
V_23 -> V_130 = F_177 ( V_229 ) ;
if ( ( V_229 -> V_219 == V_239 || V_229 -> V_219 == V_240 ) &&
F_178 ( V_229 , V_400 , V_401 , true ) ) {
V_23 -> F_13 ( V_23 , 0 ) ;
F_87 ( V_23 ) ;
}
V_27 = 0 ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_179 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_265 * V_344 = V_7 ;
struct V_129 * V_23 ;
struct V_228 * V_229 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_409 ,
V_279 ) ;
goto V_270;
}
V_23 = F_45 ( V_393 , V_6 ) ;
if ( ! V_23 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_409 ,
V_255 ) ;
goto V_270;
}
V_229 = V_23 -> V_130 ;
if ( F_26 ( & V_344 -> V_204 , & V_229 -> V_248 ) != 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_409 ,
V_255 ) ;
goto V_270;
}
V_23 -> F_13 ( V_23 , V_410 ) ;
F_87 ( V_23 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_409 , 0 ,
V_344 , sizeof( * V_344 ) ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_180 ( struct V_9 * V_22 , struct V_5 * V_6 ,
struct V_265 * V_344 , T_2 V_324 ,
T_2 V_411 , T_5 V_412 )
{
struct V_129 * V_23 ;
struct V_228 * V_229 ;
int V_27 ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_324 ,
V_279 , V_344 ,
sizeof( * V_344 ) ) ;
goto V_413;
}
if ( V_344 -> type == V_345 )
V_229 = F_154 ( V_6 , V_246 , & V_344 -> V_204 ) ;
else
V_229 = F_154 ( V_6 , V_186 , & V_344 -> V_204 ) ;
if ( ! V_229 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_324 ,
V_366 , V_344 ,
sizeof( * V_344 ) ) ;
goto V_413;
}
if ( V_344 -> type == V_356 || V_344 -> type == V_369 ) {
V_27 = F_181 ( V_229 , V_324 , V_412 ) ;
if ( ! V_27 )
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_324 ,
V_268 , V_344 ,
sizeof( * V_344 ) ) ;
else
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_324 ,
V_3 , V_344 ,
sizeof( * V_344 ) ) ;
goto V_413;
}
V_23 = F_79 ( V_22 , V_324 , V_6 , V_344 , sizeof( * V_344 ) ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_413;
}
V_23 -> F_13 = F_108 ;
if ( V_411 == V_414 ) {
struct V_415 V_141 ;
F_76 ( & V_141 . V_204 , & V_344 -> V_204 ) ;
V_141 . V_412 = V_412 ;
V_27 = F_127 ( V_6 , V_411 , sizeof( V_141 ) , & V_141 ) ;
} else
V_27 = F_127 ( V_6 , V_411 , sizeof( V_344 -> V_204 ) ,
& V_344 -> V_204 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_413:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_182 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_377 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_180 ( V_22 , V_6 , & V_141 -> V_344 ,
V_378 ,
V_379 , 0 ) ;
}
static int F_183 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_416 * V_141 = V_7 ;
F_11 ( L_7 ) ;
if ( V_21 != sizeof( * V_141 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_417 ,
V_255 ) ;
return F_180 ( V_22 , V_6 , & V_141 -> V_344 ,
V_417 ,
V_418 , 0 ) ;
}
static int F_184 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_419 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_180 ( V_22 , V_6 , & V_141 -> V_344 ,
V_420 ,
V_421 , 0 ) ;
}
static int F_185 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_422 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_180 ( V_22 , V_6 , & V_141 -> V_344 ,
V_423 ,
V_414 , V_141 -> V_412 ) ;
}
static int F_186 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_424 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_180 ( V_22 , V_6 , & V_141 -> V_344 ,
V_425 ,
V_426 , 0 ) ;
}
static void F_187 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_427 V_141 ;
memcpy ( V_141 . V_77 , V_6 -> V_133 , sizeof( V_141 . V_77 ) ) ;
F_49 ( V_139 , V_428 , sizeof( V_141 ) , & V_141 ) ;
}
static void F_188 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_429 * V_141 ;
struct V_129 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_430 , V_6 ) ;
if ( ! V_23 )
goto V_270;
V_141 = V_23 -> V_148 ;
if ( V_24 )
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_430 ,
F_1 ( V_24 ) ) ;
else
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_430 , 0 ,
V_141 , sizeof( * V_141 ) ) ;
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_189 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_429 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_133 , V_141 -> V_77 , sizeof( V_6 -> V_133 ) ) &&
! memcmp ( V_6 -> V_207 , V_141 -> V_207 ,
sizeof( V_6 -> V_207 ) ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_430 , 0 ,
V_7 , V_21 ) ;
goto V_257;
}
memcpy ( V_6 -> V_207 , V_141 -> V_207 , sizeof( V_6 -> V_207 ) ) ;
if ( ! F_40 ( V_6 ) ) {
memcpy ( V_6 -> V_133 , V_141 -> V_77 , sizeof( V_6 -> V_133 ) ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_430 , 0 ,
V_7 , V_21 ) ;
if ( V_27 < 0 )
goto V_257;
V_27 = F_3 ( V_431 , V_6 , V_7 , V_21 ,
V_22 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_430 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
memcpy ( V_6 -> V_133 , V_141 -> V_77 , sizeof( V_6 -> V_133 ) ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_35 ( V_6 ) ) {
F_187 ( & V_139 ) ;
F_57 ( & V_139 ) ;
}
if ( F_38 ( V_6 ) )
F_48 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_188 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_190 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_129 * V_23 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_432 ,
V_279 ) ;
goto V_270;
}
if ( ! F_36 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_432 ,
V_266 ) ;
goto V_270;
}
if ( F_45 ( V_432 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_432 ,
V_256 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_432 , V_6 , NULL , 0 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
if ( F_191 ( V_6 ) )
V_27 = F_127 ( V_6 , V_433 ,
0 , NULL ) ;
else
V_27 = F_127 ( V_6 , V_434 , 0 , NULL ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_192 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
int V_27 ;
F_11 ( L_18 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( V_21 == V_435 ) {
struct V_436 * V_141 = V_7 ;
T_1 V_24 ;
if ( V_141 -> V_344 . type != V_345 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_437 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
V_27 = F_193 ( V_6 , & V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type , V_141 -> V_438 ,
V_141 -> rand , NULL , NULL ) ;
if ( V_27 < 0 )
V_24 = V_3 ;
else
V_24 = V_268 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_437 ,
V_24 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
} else if ( V_21 == V_439 ) {
struct V_440 * V_141 = V_7 ;
T_1 * V_441 , * V_442 ;
T_1 V_24 ;
if ( V_141 -> V_344 . type != V_345 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_437 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
if ( F_194 ( V_141 -> V_344 . type ) ) {
V_441 = NULL ;
V_442 = NULL ;
} else {
V_441 = V_141 -> V_441 ;
V_442 = V_141 -> V_442 ;
}
V_27 = F_193 ( V_6 , & V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type , V_442 , V_441 ,
V_141 -> V_443 , V_141 -> V_444 ) ;
if ( V_27 < 0 )
V_24 = V_3 ;
else
V_24 = V_268 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_437 ,
V_24 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
} else {
F_148 ( L_19 , V_21 ) ;
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_437 ,
V_255 ) ;
}
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_195 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_445 * V_141 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( V_141 -> V_344 . type != V_345 )
return F_13 ( V_22 , V_6 -> V_19 , V_446 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_26 ( & V_141 -> V_344 . V_204 , V_70 ) ) {
F_196 ( V_6 ) ;
V_24 = V_268 ;
goto V_413;
}
V_27 = F_197 ( V_6 , & V_141 -> V_344 . V_204 , V_141 -> V_344 . type ) ;
if ( V_27 < 0 )
V_24 = V_255 ;
else
V_24 = V_268 ;
V_413:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_446 ,
V_24 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_198 ( struct V_138 * V_139 , T_1 * V_24 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_447 V_448 ;
struct V_449 V_450 ;
struct V_451 V_452 ;
T_1 V_453 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
T_1 V_184 ;
int V_27 ;
switch ( V_6 -> V_218 . type ) {
case V_454 :
* V_24 = F_109 ( V_6 ) ;
if ( * V_24 )
return false ;
if ( F_22 ( V_221 , & V_6 -> V_153 ) ) {
* V_24 = V_256 ;
return false ;
}
F_199 ( V_6 ) ;
memset ( & V_452 , 0 , sizeof( V_452 ) ) ;
memcpy ( & V_452 . V_453 , V_453 , sizeof( V_452 . V_453 ) ) ;
V_452 . V_144 = V_455 ;
F_49 ( V_139 , V_456 , sizeof( V_452 ) , & V_452 ) ;
break;
case V_457 :
case V_458 :
* V_24 = F_110 ( V_6 ) ;
if ( * V_24 )
return false ;
if ( V_6 -> V_218 . type == V_458 &&
! F_22 ( V_107 , & V_6 -> V_55 ) ) {
* V_24 = V_266 ;
return false ;
}
if ( F_22 ( V_187 , & V_6 -> V_55 ) ) {
if ( F_200 ( V_6 , V_186 ,
V_244 ) ) {
* V_24 = V_267 ;
return false ;
}
F_62 ( V_139 ) ;
}
if ( F_22 ( V_227 , & V_6 -> V_55 ) )
F_95 ( V_139 ) ;
memset ( & V_448 , 0 , sizeof( V_448 ) ) ;
V_27 = F_66 ( V_139 , true , & V_184 ) ;
if ( V_27 < 0 ) {
* V_24 = V_3 ;
return false ;
}
V_448 . type = V_459 ;
V_448 . V_291 = F_6 ( V_460 ) ;
V_448 . V_293 = F_6 ( V_461 ) ;
V_448 . V_194 = V_184 ;
F_49 ( V_139 , V_462 , sizeof( V_448 ) ,
& V_448 ) ;
memset ( & V_450 , 0 , sizeof( V_450 ) ) ;
V_450 . V_181 = V_463 ;
V_450 . V_464 = V_465 ;
F_49 ( V_139 , V_466 , sizeof( V_450 ) ,
& V_450 ) ;
break;
default:
* V_24 = V_255 ;
return false ;
}
return true ;
}
static void F_201 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
unsigned long V_278 ;
F_11 ( L_20 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_467 , V_6 ) ;
if ( ! V_23 )
V_23 = F_45 ( V_468 , V_6 ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
if ( V_24 ) {
F_98 ( V_6 , V_469 ) ;
goto V_270;
}
F_98 ( V_6 , V_220 ) ;
switch ( V_6 -> V_218 . type ) {
case V_457 :
V_278 = F_112 ( V_470 ) ;
break;
case V_458 :
V_278 = F_112 ( V_6 -> V_471 ) ;
break;
case V_454 :
V_278 = 0 ;
break;
default:
F_148 ( L_21 , V_6 -> V_218 . type ) ;
V_278 = 0 ;
break;
}
if ( V_278 )
F_101 ( V_6 -> V_275 ,
& V_6 -> V_223 , V_278 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_202 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_472 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_467 ,
V_279 ,
& V_141 -> type , sizeof( V_141 -> type ) ) ;
goto V_257;
}
if ( V_6 -> V_218 . V_219 != V_469 ||
F_22 ( V_473 , & V_6 -> V_55 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_467 ,
V_256 , & V_141 -> type ,
sizeof( V_141 -> type ) ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_467 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_23 -> F_13 = F_107 ;
F_203 ( V_6 ) ;
V_6 -> V_218 . type = V_141 -> type ;
V_6 -> V_218 . V_474 = false ;
F_54 ( & V_139 , V_6 ) ;
if ( ! F_198 ( & V_139 , & V_24 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_467 ,
V_24 , & V_141 -> type , sizeof( V_141 -> type ) ) ;
F_87 ( V_23 ) ;
goto V_257;
}
V_27 = F_55 ( & V_139 , F_201 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_257;
}
F_98 ( V_6 , V_475 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_204 ( struct V_129 * V_23 , T_1 V_24 )
{
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 , V_23 -> V_148 , 1 ) ;
}
static int F_205 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_476 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
const T_2 V_477 = ( ( V_336 - sizeof( * V_141 ) ) / 16 ) ;
T_2 V_478 , V_339 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_468 ,
V_279 ,
& V_141 -> type , sizeof( V_141 -> type ) ) ;
goto V_257;
}
if ( V_6 -> V_218 . V_219 != V_469 ||
F_22 ( V_473 , & V_6 -> V_55 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_468 ,
V_256 , & V_141 -> type ,
sizeof( V_141 -> type ) ) ;
goto V_257;
}
V_478 = F_115 ( V_141 -> V_478 ) ;
if ( V_478 > V_477 ) {
F_148 ( L_22 ,
V_478 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_468 ,
V_255 , & V_141 -> type ,
sizeof( V_141 -> type ) ) ;
goto V_257;
}
V_339 = sizeof( * V_141 ) + V_478 * 16 ;
if ( V_339 != V_21 ) {
F_148 ( L_23 ,
V_339 , V_21 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_468 ,
V_255 , & V_141 -> type ,
sizeof( V_141 -> type ) ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_468 ,
V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_23 -> F_13 = F_204 ;
F_203 ( V_6 ) ;
V_6 -> V_218 . type = V_141 -> type ;
V_6 -> V_218 . V_479 = V_141 -> V_479 ;
V_6 -> V_218 . V_478 = V_478 ;
if ( V_478 > 0 ) {
V_6 -> V_218 . V_326 = F_81 ( V_141 -> V_326 , V_478 * 16 ,
V_15 ) ;
if ( ! V_6 -> V_218 . V_326 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_468 ,
V_3 ,
& V_141 -> type , sizeof( V_141 -> type ) ) ;
F_87 ( V_23 ) ;
goto V_257;
}
}
F_54 ( & V_139 , V_6 ) ;
if ( ! F_198 ( & V_139 , & V_24 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_468 ,
V_24 , & V_141 -> type , sizeof( V_141 -> type ) ) ;
F_87 ( V_23 ) ;
goto V_257;
}
V_27 = F_55 ( & V_139 , F_201 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_257;
}
F_98 ( V_6 , V_475 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_206 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_20 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_480 , V_6 ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
if ( ! V_24 )
F_98 ( V_6 , V_469 ) ;
F_33 ( V_6 ) ;
}
static int F_207 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_481 * V_482 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_208 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_480 ,
V_267 , & V_482 -> type ,
sizeof( V_482 -> type ) ) ;
goto V_270;
}
if ( V_6 -> V_218 . type != V_482 -> type ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_480 ,
V_255 , & V_482 -> type ,
sizeof( V_482 -> type ) ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_480 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
V_23 -> F_13 = F_107 ;
F_54 ( & V_139 , V_6 ) ;
F_94 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_206 ) ;
if ( ! V_27 ) {
F_98 ( V_6 , V_253 ) ;
goto V_270;
}
F_87 ( V_23 ) ;
if ( V_27 == - V_261 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_480 , 0 ,
& V_482 -> type , sizeof( V_482 -> type ) ) ;
F_98 ( V_6 , V_469 ) ;
}
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_209 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_483 * V_141 = V_7 ;
struct V_216 * V_217 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_208 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 ,
V_3 , & V_141 -> V_344 ,
sizeof( V_141 -> V_344 ) ) ;
goto V_257;
}
V_217 = F_210 ( V_6 , & V_141 -> V_344 . V_204 ) ;
if ( ! V_217 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 ,
V_255 , & V_141 -> V_344 ,
sizeof( V_141 -> V_344 ) ) ;
goto V_257;
}
if ( V_141 -> V_485 ) {
V_217 -> V_486 = V_487 ;
F_88 ( & V_217 -> V_210 ) ;
} else {
V_217 -> V_486 = V_488 ;
F_211 ( V_6 , V_217 ) ;
}
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 , 0 , & V_141 -> V_344 ,
sizeof( V_141 -> V_344 ) ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_212 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_489 * V_141 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_153 ( V_141 -> V_344 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_490 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_32 ( V_6 ) ;
V_27 = F_213 ( & V_6 -> V_491 , & V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type ) ;
if ( V_27 < 0 ) {
V_24 = V_3 ;
goto V_413;
}
F_3 ( V_492 , V_6 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ,
V_22 ) ;
V_24 = V_268 ;
V_413:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_490 , V_24 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_214 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_493 * V_141 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_153 ( V_141 -> V_344 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_494 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_32 ( V_6 ) ;
V_27 = F_215 ( & V_6 -> V_491 , & V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type ) ;
if ( V_27 < 0 ) {
V_24 = V_255 ;
goto V_413;
}
F_3 ( V_495 , V_6 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ,
V_22 ) ;
V_24 = V_268 ;
V_413:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_494 , V_24 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_216 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_496 * V_141 = V_7 ;
struct V_138 V_139 ;
int V_27 ;
T_9 V_497 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
V_497 = F_115 ( V_141 -> V_497 ) ;
if ( V_497 > 0x0002 )
return F_10 ( V_22 , V_6 -> V_19 , V_498 ,
V_255 ) ;
F_32 ( V_6 ) ;
V_6 -> V_164 = V_497 ;
V_6 -> V_166 = F_115 ( V_141 -> V_499 ) ;
V_6 -> V_167 = F_115 ( V_141 -> V_500 ) ;
V_6 -> V_168 = F_115 ( V_141 -> V_34 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_498 , 0 , NULL , 0 ) ;
F_54 ( & V_139 , V_6 ) ;
F_57 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_217 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 } ;
F_32 ( V_6 ) ;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
F_84 ( V_316 , V_6 ,
F_105 , & V_271 ) ;
goto V_270;
}
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_71 ( V_112 , & V_6 -> V_55 ) ;
else
F_65 ( V_112 , & V_6 -> V_55 ) ;
F_84 ( V_316 , V_6 , F_104 ,
& V_264 ) ;
F_102 ( V_6 , V_264 . V_22 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_218 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_1 V_149 , V_315 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_110 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_316 ,
V_24 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_316 ,
V_255 ) ;
F_32 ( V_6 ) ;
V_149 = ! ! V_141 -> V_149 ;
V_315 = F_22 ( V_112 , & V_6 -> V_55 ) ;
if ( ! F_40 ( V_6 ) || V_149 == V_315 ||
F_64 ( V_6 , V_186 ) > 0 ||
( F_22 ( V_227 , & V_6 -> V_55 ) &&
V_6 -> V_501 == V_459 ) ) {
bool V_269 = false ;
if ( V_149 != F_22 ( V_112 , & V_6 -> V_55 ) ) {
F_116 ( V_112 , & V_6 -> V_55 ) ;
V_269 = true ;
}
V_27 = F_89 ( V_22 , V_316 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_270;
}
if ( F_45 ( V_316 , V_6 ) ||
F_45 ( V_313 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_316 ,
V_256 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_316 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
F_54 ( & V_139 , V_6 ) ;
if ( V_149 )
F_63 ( & V_139 ) ;
else
F_62 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_217 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_219 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_502 * V_141 = V_7 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_503 ,
V_266 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_503 ,
V_267 ) ;
if ( F_26 ( & V_141 -> V_204 , V_70 ) ) {
if ( ! F_26 ( & V_141 -> V_204 , V_504 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_503 ,
V_255 ) ;
if ( ( V_141 -> V_204 . V_505 [ 5 ] & 0xc0 ) != 0xc0 )
return F_10 ( V_22 , V_6 -> V_19 ,
V_503 ,
V_255 ) ;
}
F_32 ( V_6 ) ;
F_76 ( & V_6 -> V_506 , & V_141 -> V_204 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_503 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_220 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_507 * V_141 = V_7 ;
T_9 V_291 , V_293 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_508 ,
V_266 ) ;
V_291 = F_115 ( V_141 -> V_291 ) ;
if ( V_291 < 0x0004 || V_291 > 0x4000 )
return F_10 ( V_22 , V_6 -> V_19 , V_508 ,
V_255 ) ;
V_293 = F_115 ( V_141 -> V_293 ) ;
if ( V_293 < 0x0004 || V_293 > 0x4000 )
return F_10 ( V_22 , V_6 -> V_19 , V_508 ,
V_255 ) ;
if ( V_293 > V_291 )
return F_10 ( V_22 , V_6 -> V_19 , V_508 ,
V_255 ) ;
F_32 ( V_6 ) ;
V_6 -> V_509 = V_291 ;
V_6 -> V_510 = V_293 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_508 , 0 , NULL , 0 ) ;
if ( F_22 ( V_227 , & V_6 -> V_55 ) &&
V_6 -> V_218 . V_219 == V_469 ) {
struct V_138 V_139 ;
F_54 ( & V_139 , V_6 ) ;
F_95 ( & V_139 ) ;
F_221 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
}
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_222 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_511 , V_6 ) ;
if ( ! V_23 )
goto V_270;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_511 ,
F_1 ( V_24 ) ) ;
} else {
struct V_147 * V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 )
F_71 ( V_104 , & V_6 -> V_55 ) ;
else
F_65 ( V_104 , & V_6 -> V_55 ) ;
F_89 ( V_23 -> V_22 , V_511 , V_6 ) ;
F_102 ( V_6 , V_23 -> V_22 ) ;
}
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_223 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) ||
V_6 -> V_89 < V_90 )
return F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_266 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_255 ) ;
if ( ! F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_279 ) ;
if ( ! F_22 ( V_103 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_267 ) ;
F_32 ( V_6 ) ;
if ( F_45 ( V_511 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_256 ) ;
goto V_270;
}
if ( ! ! V_141 -> V_149 == F_22 ( V_104 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_511 ,
V_6 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_511 , V_6 ,
V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
F_54 ( & V_139 , V_6 ) ;
F_118 ( & V_139 , V_141 -> V_149 ) ;
V_27 = F_55 ( & V_139 , F_222 ) ;
if ( V_27 < 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_3 ) ;
F_87 ( V_23 ) ;
}
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_224 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_512 , V_6 ) ;
if ( ! V_23 )
goto V_270;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
F_65 ( V_107 , & V_6 -> V_55 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_271 ) ;
} else {
F_89 ( V_23 -> V_22 , V_512 , V_6 ) ;
F_102 ( V_6 , V_23 -> V_22 ) ;
}
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_225 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) || ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_266 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_267 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 == F_22 ( V_107 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_512 , V_6 ) ;
goto V_270;
}
if ( ! F_40 ( V_6 ) ) {
if ( ! V_141 -> V_149 ) {
F_65 ( V_105 , & V_6 -> V_55 ) ;
F_65 ( V_110 , & V_6 -> V_55 ) ;
F_65 ( V_109 , & V_6 -> V_55 ) ;
F_65 ( V_104 , & V_6 -> V_55 ) ;
F_65 ( V_111 , & V_6 -> V_55 ) ;
}
F_116 ( V_107 , & V_6 -> V_55 ) ;
V_27 = F_89 ( V_22 , V_512 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_270;
}
if ( ! V_141 -> V_149 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_267 ) ;
goto V_270;
}
if ( F_45 ( V_512 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_256 ) ;
goto V_270;
}
V_23 = F_79 ( V_22 , V_512 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
F_71 ( V_107 , & V_6 -> V_55 ) ;
F_54 ( & V_139 , V_6 ) ;
F_118 ( & V_139 , false ) ;
F_113 ( V_6 , & V_139 ) ;
F_52 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_224 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_226 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
T_1 V_149 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) &&
! F_37 ( V_6 ) && ! F_22 ( V_96 , & V_6 -> V_97 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_513 ,
V_266 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 && V_141 -> V_149 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_513 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ||
( ! F_37 ( V_6 ) &&
! F_22 ( V_96 , & V_6 -> V_97 ) ) ||
! F_22 ( V_107 , & V_6 -> V_55 ) ) {
bool V_269 ;
if ( V_141 -> V_149 ) {
V_269 = ! F_73 ( V_113 ,
& V_6 -> V_55 ) ;
if ( V_141 -> V_149 == 0x02 )
F_71 ( V_514 , & V_6 -> V_55 ) ;
else
F_65 ( V_514 , & V_6 -> V_55 ) ;
} else {
V_269 = F_69 ( V_113 ,
& V_6 -> V_55 ) ;
F_65 ( V_514 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_513 , V_6 ) ;
if ( V_27 < 0 )
goto V_257;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_257;
}
if ( F_45 ( V_513 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_513 ,
V_256 ) ;
goto V_257;
}
V_149 = ! ! V_141 -> V_149 ;
if ( V_149 == F_22 ( V_113 , & V_6 -> V_55 ) &&
( V_141 -> V_149 == 0x02 ) == F_22 ( V_514 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_513 , V_6 ) ;
goto V_257;
}
V_23 = F_79 ( V_22 , V_513 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_257;
}
V_27 = F_127 ( V_6 , V_515 , 1 , & V_149 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_257;
}
if ( V_141 -> V_149 == 0x02 )
F_71 ( V_514 , & V_6 -> V_55 ) ;
else
F_65 ( V_514 , & V_6 -> V_55 ) ;
V_257:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_227 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
bool V_269 , V_516 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 && V_141 -> V_149 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_517 ,
V_255 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 )
V_269 = ! F_73 ( V_114 ,
& V_6 -> V_55 ) ;
else
V_269 = F_69 ( V_114 ,
& V_6 -> V_55 ) ;
if ( V_141 -> V_149 == 0x02 )
V_516 = ! F_73 ( V_310 ,
& V_6 -> V_55 ) ;
else
V_516 = F_69 ( V_310 ,
& V_6 -> V_55 ) ;
if ( F_40 ( V_6 ) && V_516 &&
F_22 ( V_110 , & V_6 -> V_55 ) ) {
T_1 V_518 = ( V_141 -> V_149 == 0x02 ) ? 0x01 : 0x00 ;
F_127 ( V_6 , V_311 ,
sizeof( V_518 ) , & V_518 ) ;
}
V_27 = F_89 ( V_22 , V_517 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_228 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_519 ,
T_2 V_21 )
{
struct V_520 * V_141 = V_519 ;
bool V_269 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_521 ,
V_266 ) ;
if ( V_141 -> V_522 != 0x00 && V_141 -> V_522 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_521 ,
V_255 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_521 ,
V_267 ) ;
F_32 ( V_6 ) ;
F_71 ( V_523 , & V_6 -> V_55 ) ;
if ( V_141 -> V_522 ) {
V_269 = ! F_73 ( V_115 , & V_6 -> V_55 ) ;
memcpy ( V_6 -> V_524 , V_141 -> V_524 , sizeof( V_6 -> V_524 ) ) ;
F_71 ( V_201 , & V_6 -> V_55 ) ;
} else {
V_269 = F_69 ( V_115 , & V_6 -> V_55 ) ;
memset ( V_6 -> V_524 , 0 , sizeof( V_6 -> V_524 ) ) ;
F_65 ( V_201 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_521 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( V_269 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_229 ( struct V_525 * V_524 )
{
switch ( V_524 -> V_344 . type ) {
case V_356 :
return true ;
case V_369 :
if ( ( V_524 -> V_344 . V_204 . V_505 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_230 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_519 ,
T_2 V_21 )
{
struct V_526 * V_141 = V_519 ;
const T_2 V_527 = ( ( V_336 - sizeof( * V_141 ) ) /
sizeof( struct V_525 ) ) ;
T_2 V_528 , V_339 ;
int V_45 , V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_529 ,
V_266 ) ;
V_528 = F_115 ( V_141 -> V_528 ) ;
if ( V_528 > V_527 ) {
F_148 ( L_24 , V_528 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_529 ,
V_255 ) ;
}
V_339 = sizeof( * V_141 ) + V_528 * sizeof( struct V_525 ) ;
if ( V_339 != V_21 ) {
F_148 ( L_25 ,
V_339 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_529 ,
V_255 ) ;
}
F_11 ( L_26 , V_6 -> V_77 , V_528 ) ;
for ( V_45 = 0 ; V_45 < V_528 ; V_45 ++ ) {
struct V_525 * V_342 = & V_141 -> V_530 [ V_45 ] ;
if ( ! F_229 ( V_342 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_529 ,
V_255 ) ;
}
F_32 ( V_6 ) ;
F_231 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_528 ; V_45 ++ ) {
struct V_525 * V_524 = & V_141 -> V_530 [ V_45 ] ;
T_1 V_348 ;
if ( V_524 -> V_344 . type == V_356 )
V_348 = V_357 ;
else
V_348 = V_358 ;
F_232 ( V_6 , & V_524 -> V_344 . V_204 , V_348 , V_524 -> V_149 ,
V_70 ) ;
}
F_71 ( V_523 , & V_6 -> V_55 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_529 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_233 ( struct V_531 * V_342 )
{
if ( V_342 -> V_532 != 0x00 && V_342 -> V_532 != 0x01 )
return false ;
switch ( V_342 -> V_344 . type ) {
case V_356 :
return true ;
case V_369 :
if ( ( V_342 -> V_344 . V_204 . V_505 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_234 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_519 , T_2 V_21 )
{
struct V_533 * V_141 = V_519 ;
const T_2 V_335 = ( ( V_336 - sizeof( * V_141 ) ) /
sizeof( struct V_531 ) ) ;
T_2 V_338 , V_339 ;
int V_45 , V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_534 ,
V_266 ) ;
V_338 = F_115 ( V_141 -> V_338 ) ;
if ( V_338 > V_335 ) {
F_148 ( L_27 , V_338 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_534 ,
V_255 ) ;
}
V_339 = sizeof( * V_141 ) + V_338 *
sizeof( struct V_531 ) ;
if ( V_339 != V_21 ) {
F_148 ( L_28 ,
V_339 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_534 ,
V_255 ) ;
}
F_11 ( L_29 , V_6 -> V_77 , V_338 ) ;
for ( V_45 = 0 ; V_45 < V_338 ; V_45 ++ ) {
struct V_531 * V_342 = & V_141 -> V_343 [ V_45 ] ;
if ( ! F_233 ( V_342 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_534 ,
V_255 ) ;
}
F_32 ( V_6 ) ;
F_235 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_338 ; V_45 ++ ) {
struct V_531 * V_342 = & V_141 -> V_343 [ V_45 ] ;
T_1 type , V_348 , V_535 ;
if ( V_342 -> V_344 . type == V_356 )
V_348 = V_357 ;
else
V_348 = V_358 ;
switch ( V_342 -> type ) {
case V_536 :
V_535 = 0x00 ;
type = V_342 -> V_532 ? V_537 : V_538 ;
break;
case V_539 :
V_535 = 0x01 ;
type = V_342 -> V_532 ? V_537 : V_538 ;
break;
case V_540 :
V_535 = 0x00 ;
type = V_541 ;
break;
case V_542 :
V_535 = 0x01 ;
type = V_541 ;
break;
case V_543 :
V_535 = 0x00 ;
type = V_544 ;
default:
continue;
}
F_236 ( V_6 , & V_342 -> V_344 . V_204 , V_348 , type ,
V_535 , V_342 -> V_149 , V_342 -> V_545 , V_342 -> V_546 ,
V_342 -> rand ) ;
}
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_534 , 0 ,
NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_237 ( struct V_129 * V_23 , T_1 V_24 )
{
struct V_228 * V_229 = V_23 -> V_130 ;
struct V_547 V_29 ;
memcpy ( & V_29 . V_344 , V_23 -> V_148 , sizeof( V_29 . V_344 ) ) ;
if ( V_24 == V_268 ) {
V_29 . V_479 = V_229 -> V_479 ;
V_29 . V_548 = V_229 -> V_548 ;
V_29 . V_549 = V_229 -> V_549 ;
} else {
V_29 . V_479 = V_550 ;
V_29 . V_548 = V_157 ;
V_29 . V_549 = V_157 ;
}
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_551 , V_24 ,
& V_29 , sizeof( V_29 ) ) ;
F_166 ( V_229 ) ;
F_167 ( V_229 ) ;
}
static void F_238 ( struct V_5 * V_6 , T_1 V_1 )
{
struct V_552 * V_141 ;
struct V_129 * V_23 ;
struct V_228 * V_229 ;
T_2 V_241 ;
T_1 V_24 ;
F_11 ( L_10 , V_1 ) ;
F_32 ( V_6 ) ;
V_141 = F_239 ( V_6 , V_553 ) ;
if ( ! V_141 ) {
V_141 = F_239 ( V_6 , V_554 ) ;
V_24 = V_268 ;
} else {
V_24 = F_1 ( V_1 ) ;
}
if ( ! V_141 ) {
F_148 ( L_30 ) ;
goto V_270;
}
V_241 = F_115 ( V_141 -> V_241 ) ;
V_229 = F_240 ( V_6 , V_241 ) ;
if ( ! V_229 ) {
F_148 ( L_31 , V_241 ) ;
goto V_270;
}
V_23 = F_46 ( V_551 , V_6 , V_229 ) ;
if ( ! V_23 )
goto V_270;
V_23 -> F_13 ( V_23 , V_24 ) ;
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_241 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_555 * V_141 = V_7 ;
struct V_547 V_29 ;
struct V_228 * V_229 ;
unsigned long V_556 ;
int V_27 = 0 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_344 . V_204 , & V_141 -> V_344 . V_204 ) ;
V_29 . V_344 . type = V_141 -> V_344 . type ;
if ( ! F_153 ( V_141 -> V_344 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_551 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_551 ,
V_279 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
if ( V_141 -> V_344 . type == V_345 )
V_229 = F_154 ( V_6 , V_246 ,
& V_141 -> V_344 . V_204 ) ;
else
V_229 = F_154 ( V_6 , V_186 , & V_141 -> V_344 . V_204 ) ;
if ( ! V_229 || V_229 -> V_219 != V_239 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_551 ,
V_366 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
if ( F_46 ( V_551 , V_6 , V_229 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_551 ,
V_256 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
V_556 = V_6 -> V_557 +
F_242 ( V_6 -> V_558 -
V_6 -> V_557 ) ;
if ( F_243 ( V_559 , V_229 -> V_560 +
F_112 ( V_556 ) ) ||
! V_229 -> V_560 ) {
struct V_138 V_139 ;
struct V_561 V_562 ;
struct V_552 V_563 ;
struct V_129 * V_23 ;
F_54 ( & V_139 , V_6 ) ;
V_563 . V_241 = F_6 ( V_229 -> V_241 ) ;
F_49 ( & V_139 , V_553 , sizeof( V_563 ) ,
& V_563 ) ;
if ( ! F_194 ( V_141 -> V_344 . type ) ||
V_229 -> V_548 == V_157 ) {
V_562 . V_241 = F_6 ( V_229 -> V_241 ) ;
V_562 . type = 0x00 ;
F_49 ( & V_139 , V_554 ,
sizeof( V_562 ) , & V_562 ) ;
}
if ( V_229 -> V_549 == V_157 ) {
V_562 . V_241 = F_6 ( V_229 -> V_241 ) ;
V_562 . type = 0x01 ;
F_49 ( & V_139 , V_554 ,
sizeof( V_562 ) , & V_562 ) ;
}
V_27 = F_55 ( & V_139 , F_238 ) ;
if ( V_27 < 0 )
goto V_270;
V_23 = F_79 ( V_22 , V_551 , V_6 ,
V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
F_244 ( V_229 ) ;
V_23 -> V_130 = F_177 ( V_229 ) ;
V_23 -> F_13 = F_237 ;
V_229 -> V_560 = V_559 ;
} else {
V_29 . V_479 = V_229 -> V_479 ;
V_29 . V_548 = V_229 -> V_548 ;
V_29 . V_549 = V_229 -> V_549 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_551 ,
V_268 , & V_29 , sizeof( V_29 ) ) ;
}
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_245 ( struct V_129 * V_23 , T_1 V_24 )
{
struct V_228 * V_229 = V_23 -> V_130 ;
struct V_564 V_29 ;
struct V_5 * V_6 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memcpy ( & V_29 . V_344 , & V_23 -> V_148 , sizeof( V_29 . V_344 ) ) ;
if ( V_24 )
goto V_398;
V_6 = F_246 ( V_23 -> V_18 ) ;
if ( V_6 ) {
V_29 . V_565 = F_28 ( V_6 -> clock ) ;
F_247 ( V_6 ) ;
}
if ( V_229 ) {
V_29 . V_566 = F_28 ( V_229 -> clock ) ;
V_29 . V_567 = F_6 ( V_229 -> V_568 ) ;
}
V_398:
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 , & V_29 , sizeof( V_29 ) ) ;
if ( V_229 ) {
F_166 ( V_229 ) ;
F_167 ( V_229 ) ;
}
}
static void F_248 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_569 * V_283 ;
struct V_129 * V_23 ;
struct V_228 * V_229 ;
F_11 ( L_32 , V_6 -> V_77 , V_24 ) ;
F_32 ( V_6 ) ;
V_283 = F_239 ( V_6 , V_570 ) ;
if ( ! V_283 )
goto V_270;
if ( V_283 -> V_571 ) {
T_2 V_241 = F_115 ( V_283 -> V_241 ) ;
V_229 = F_240 ( V_6 , V_241 ) ;
} else {
V_229 = NULL ;
}
V_23 = F_46 ( V_572 , V_6 , V_229 ) ;
if ( ! V_23 )
goto V_270;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
}
static int F_249 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_573 * V_141 = V_7 ;
struct V_564 V_29 ;
struct V_569 V_283 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
struct V_228 * V_229 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_344 . V_204 , & V_141 -> V_344 . V_204 ) ;
V_29 . V_344 . type = V_141 -> V_344 . type ;
if ( V_141 -> V_344 . type != V_345 )
return F_13 ( V_22 , V_6 -> V_19 , V_572 ,
V_255 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_572 ,
V_279 , & V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
if ( F_26 ( & V_141 -> V_344 . V_204 , V_70 ) ) {
V_229 = F_154 ( V_6 , V_246 ,
& V_141 -> V_344 . V_204 ) ;
if ( ! V_229 || V_229 -> V_219 != V_239 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_572 ,
V_366 ,
& V_29 , sizeof( V_29 ) ) ;
goto V_270;
}
} else {
V_229 = NULL ;
}
V_23 = F_79 ( V_22 , V_572 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_270;
}
V_23 -> F_13 = F_245 ;
F_54 ( & V_139 , V_6 ) ;
memset ( & V_283 , 0 , sizeof( V_283 ) ) ;
F_49 ( & V_139 , V_570 , sizeof( V_283 ) , & V_283 ) ;
if ( V_229 ) {
F_244 ( V_229 ) ;
V_23 -> V_130 = F_177 ( V_229 ) ;
V_283 . V_241 = F_6 ( V_229 -> V_241 ) ;
V_283 . V_571 = 0x01 ;
F_49 ( & V_139 , V_570 , sizeof( V_283 ) , & V_283 ) ;
}
V_27 = F_55 ( & V_139 , F_248 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_250 ( struct V_9 * V_22 , struct V_5 * V_6 ,
T_8 * V_204 , T_1 type , T_1 V_574 )
{
struct V_575 V_26 ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = type ;
V_26 . V_574 = V_574 ;
F_3 ( V_576 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
}
static int F_251 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_577 * V_141 = V_7 ;
T_1 V_578 , V_348 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_153 ( V_141 -> V_344 . type ) ||
! F_26 ( & V_141 -> V_344 . V_204 , V_70 ) )
return F_13 ( V_22 , V_6 -> V_19 , V_579 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
if ( V_141 -> V_574 != 0x00 && V_141 -> V_574 != 0x01 && V_141 -> V_574 != 0x02 )
return F_13 ( V_22 , V_6 -> V_19 , V_579 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_344 . type == V_345 ) {
if ( V_141 -> V_574 != 0x01 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_579 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
V_27 = F_213 ( & V_6 -> V_301 , & V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type ) ;
if ( V_27 )
goto V_270;
F_113 ( V_6 , NULL ) ;
goto V_580;
}
if ( V_141 -> V_344 . type == V_356 )
V_348 = V_357 ;
else
V_348 = V_358 ;
if ( V_141 -> V_574 == 0x02 )
V_578 = V_581 ;
else if ( V_141 -> V_574 == 0x01 )
V_578 = V_582 ;
else
V_578 = V_583 ;
if ( F_252 ( V_6 , & V_141 -> V_344 . V_204 , V_348 ,
V_578 ) < 0 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_579 ,
V_3 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
V_580:
F_250 ( V_22 , V_6 , & V_141 -> V_344 . V_204 , V_141 -> V_344 . type , V_141 -> V_574 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_579 ,
V_268 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_253 ( struct V_9 * V_22 , struct V_5 * V_6 ,
T_8 * V_204 , T_1 type )
{
struct V_584 V_26 ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = type ;
F_3 ( V_585 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
}
static int F_254 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_586 * V_141 = V_7 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_26 ( & V_141 -> V_344 . V_204 , V_70 ) ) {
struct V_587 * V_588 ;
T_1 V_348 ;
if ( ! F_153 ( V_141 -> V_344 . type ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_589 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
if ( V_141 -> V_344 . type == V_345 ) {
V_27 = F_215 ( & V_6 -> V_301 ,
& V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type ) ;
if ( V_27 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_589 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
F_113 ( V_6 , NULL ) ;
F_253 ( V_22 , V_6 , & V_141 -> V_344 . V_204 ,
V_141 -> V_344 . type ) ;
goto V_398;
}
if ( V_141 -> V_344 . type == V_356 )
V_348 = V_357 ;
else
V_348 = V_358 ;
V_588 = F_255 ( V_6 , & V_141 -> V_344 . V_204 ,
V_348 ) ;
if ( ! V_588 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_589 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
if ( V_588 -> V_590 == V_591 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_589 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
F_88 ( & V_588 -> V_574 ) ;
F_88 ( & V_588 -> V_210 ) ;
F_18 ( V_588 ) ;
F_121 ( V_6 ) ;
F_253 ( V_22 , V_6 , & V_141 -> V_344 . V_204 , V_141 -> V_344 . type ) ;
} else {
struct V_587 * V_592 , * V_212 ;
struct V_593 * V_505 , * V_594 ;
if ( V_141 -> V_344 . type ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_589 ,
V_255 ,
& V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
goto V_270;
}
F_86 (b, btmp, &hdev->whitelist, list) {
F_253 ( V_22 , V_6 , & V_505 -> V_204 , V_505 -> V_595 ) ;
F_88 ( & V_505 -> V_210 ) ;
F_18 ( V_505 ) ;
}
F_113 ( V_6 , NULL ) ;
F_86 (p, tmp, &hdev->le_conn_params, list) {
if ( V_592 -> V_590 == V_591 )
continue;
F_253 ( V_22 , V_6 , & V_592 -> V_344 , V_592 -> V_348 ) ;
F_88 ( & V_592 -> V_574 ) ;
F_88 ( & V_592 -> V_210 ) ;
F_18 ( V_592 ) ;
}
F_11 ( L_33 ) ;
F_121 ( V_6 ) ;
}
V_398:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_589 ,
V_268 , & V_141 -> V_344 , sizeof( V_141 -> V_344 ) ) ;
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_256 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_596 * V_141 = V_7 ;
const T_2 V_597 = ( ( V_336 - sizeof( * V_141 ) ) /
sizeof( struct V_598 ) ) ;
T_2 V_599 , V_339 ;
int V_45 ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_600 ,
V_266 ) ;
V_599 = F_115 ( V_141 -> V_599 ) ;
if ( V_599 > V_597 ) {
F_148 ( L_34 ,
V_599 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_600 ,
V_255 ) ;
}
V_339 = sizeof( * V_141 ) + V_599 *
sizeof( struct V_598 ) ;
if ( V_339 != V_21 ) {
F_148 ( L_35 ,
V_339 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_600 ,
V_255 ) ;
}
F_11 ( L_36 , V_6 -> V_77 , V_599 ) ;
F_32 ( V_6 ) ;
F_257 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_599 ; V_45 ++ ) {
struct V_598 * V_148 = & V_141 -> V_588 [ V_45 ] ;
struct V_587 * V_601 ;
T_2 V_602 , V_603 , V_604 , V_278 ;
T_1 V_348 ;
F_11 ( L_37 , & V_148 -> V_344 . V_204 ,
V_148 -> V_344 . type ) ;
if ( V_148 -> V_344 . type == V_356 ) {
V_348 = V_357 ;
} else if ( V_148 -> V_344 . type == V_369 ) {
V_348 = V_358 ;
} else {
F_148 ( L_38 ) ;
continue;
}
V_602 = F_258 ( V_148 -> V_188 ) ;
V_603 = F_258 ( V_148 -> V_190 ) ;
V_604 = F_258 ( V_148 -> V_604 ) ;
V_278 = F_258 ( V_148 -> V_278 ) ;
F_11 ( L_39 ,
V_602 , V_603 , V_604 , V_278 ) ;
if ( F_259 ( V_602 , V_603 , V_604 , V_278 ) < 0 ) {
F_148 ( L_38 ) ;
continue;
}
V_601 = F_173 ( V_6 , & V_148 -> V_344 . V_204 ,
V_348 ) ;
if ( ! V_601 ) {
F_148 ( L_40 ) ;
continue;
}
V_601 -> V_605 = V_602 ;
V_601 -> V_606 = V_603 ;
V_601 -> V_607 = V_604 ;
V_601 -> V_608 = V_278 ;
}
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_600 , 0 , NULL , 0 ) ;
}
static int F_260 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_609 * V_141 = V_7 ;
bool V_269 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_610 ,
V_267 ) ;
if ( V_141 -> V_611 != 0x00 && V_141 -> V_611 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_610 ,
V_255 ) ;
if ( ! F_22 ( V_66 , & V_6 -> V_61 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_610 ,
V_266 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_611 )
V_269 = ! F_73 ( V_67 ,
& V_6 -> V_55 ) ;
else
V_269 = F_69 ( V_67 ,
& V_6 -> V_55 ) ;
V_27 = F_30 ( V_22 , V_610 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( ! V_269 )
goto V_270;
V_27 = F_29 ( V_6 , V_22 ) ;
if ( F_22 ( V_54 , & V_6 -> V_55 ) == F_25 ( V_6 ) ) {
F_261 ( V_6 ) ;
if ( F_262 ( V_54 , & V_6 -> V_55 ) ) {
F_71 ( V_58 , & V_6 -> V_55 ) ;
F_71 ( V_258 , & V_6 -> V_55 ) ;
F_93 ( V_6 -> V_214 , & V_6 -> V_259 ) ;
} else {
F_71 ( V_612 , & V_6 -> V_153 ) ;
F_263 ( V_6 ) ;
}
}
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_264 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_613 * V_141 = V_7 ;
bool V_269 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_614 ,
V_267 ) ;
if ( ! F_26 ( & V_141 -> V_204 , V_70 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_614 ,
V_255 ) ;
if ( ! V_6 -> V_79 )
return F_10 ( V_22 , V_6 -> V_19 , V_614 ,
V_266 ) ;
F_32 ( V_6 ) ;
V_269 = ! ! F_26 ( & V_6 -> V_69 , & V_141 -> V_204 ) ;
F_76 ( & V_6 -> V_69 , & V_141 -> V_204 ) ;
V_27 = F_30 ( V_22 , V_614 , V_6 ) ;
if ( V_27 < 0 )
goto V_270;
if ( ! V_269 )
goto V_270;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
V_27 = F_29 ( V_6 , V_22 ) ;
if ( F_25 ( V_6 ) ) {
F_261 ( V_6 ) ;
F_65 ( V_54 , & V_6 -> V_55 ) ;
F_71 ( V_58 , & V_6 -> V_55 ) ;
F_71 ( V_258 , & V_6 -> V_55 ) ;
F_93 ( V_6 -> V_214 , & V_6 -> V_259 ) ;
}
V_270:
F_33 ( V_6 ) ;
return V_27 ;
}
int F_265 ( struct V_9 * V_22 , struct V_615 * V_616 , T_3 V_617 )
{
void * V_618 ;
T_1 * V_141 ;
struct V_13 * V_14 ;
T_2 V_17 , V_18 , V_21 ;
struct V_5 * V_6 = NULL ;
const struct V_619 * V_620 ;
int V_27 ;
F_11 ( L_41 , V_617 ) ;
if ( V_617 < sizeof( * V_14 ) )
return - V_621 ;
V_618 = F_16 ( V_617 , V_15 ) ;
if ( ! V_618 )
return - V_16 ;
if ( F_266 ( V_618 , V_616 , V_617 ) ) {
V_27 = - V_622 ;
goto V_413;
}
V_14 = V_618 ;
V_17 = F_115 ( V_14 -> V_17 ) ;
V_18 = F_115 ( V_14 -> V_18 ) ;
V_21 = F_115 ( V_14 -> V_21 ) ;
if ( V_21 != V_617 - sizeof( * V_14 ) ) {
V_27 = - V_621 ;
goto V_413;
}
if ( V_18 != V_20 ) {
V_6 = F_246 ( V_18 ) ;
if ( ! V_6 ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_623 ) ;
goto V_413;
}
if ( F_22 ( V_57 , & V_6 -> V_55 ) ||
F_22 ( V_58 , & V_6 -> V_55 ) ||
F_22 ( V_59 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_623 ) ;
goto V_413;
}
if ( F_22 ( V_54 , & V_6 -> V_55 ) &&
V_17 != V_82 &&
V_17 != V_610 &&
V_17 != V_614 ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_623 ) ;
goto V_413;
}
}
if ( V_17 >= F_2 ( V_624 ) ||
V_624 [ V_17 ] . V_625 == NULL ) {
F_11 ( L_42 , V_17 ) ;
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_626 ) ;
goto V_413;
}
if ( V_6 && ( V_17 <= V_63 ||
V_17 == V_65 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_623 ) ;
goto V_413;
}
if ( ! V_6 && ( V_17 > V_63 &&
V_17 != V_65 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_623 ) ;
goto V_413;
}
V_620 = & V_624 [ V_17 ] ;
if ( ( V_620 -> V_627 && V_21 < V_620 -> V_8 ) ||
( ! V_620 -> V_627 && V_21 != V_620 -> V_8 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_255 ) ;
goto V_413;
}
if ( V_6 )
F_72 ( V_22 , V_6 ) ;
V_141 = V_618 + sizeof( * V_14 ) ;
V_27 = V_620 -> V_625 ( V_22 , V_6 , V_141 , V_21 ) ;
if ( V_27 < 0 )
goto V_413;
V_27 = V_617 ;
V_413:
if ( V_6 )
F_247 ( V_6 ) ;
F_18 ( V_618 ) ;
return V_27 ;
}
void F_263 ( struct V_5 * V_6 )
{
if ( V_6 -> V_52 != V_53 )
return;
if ( F_22 ( V_60 , & V_6 -> V_61 ) )
return;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
F_3 ( V_628 , V_6 , NULL , 0 , NULL ) ;
else
F_3 ( V_629 , V_6 , NULL , 0 , NULL ) ;
}
void F_261 ( struct V_5 * V_6 )
{
T_1 V_24 = V_623 ;
if ( V_6 -> V_52 != V_53 )
return;
if ( F_22 ( V_60 , & V_6 -> V_61 ) )
return;
F_84 ( 0 , V_6 , F_106 , & V_24 ) ;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
F_3 ( V_630 , V_6 , NULL , 0 , NULL ) ;
else
F_3 ( V_631 , V_6 , NULL , 0 , NULL ) ;
}
static void F_267 ( struct V_5 * V_6 )
{
struct V_587 * V_592 ;
F_21 (p, &hdev->le_conn_params, list) {
F_268 ( & V_592 -> V_574 ) ;
switch ( V_592 -> V_590 ) {
case V_582 :
case V_581 :
F_83 ( & V_592 -> V_574 , & V_6 -> V_632 ) ;
break;
case V_583 :
F_83 ( & V_592 -> V_574 , & V_6 -> V_633 ) ;
break;
default:
break;
}
}
F_121 ( V_6 ) ;
}
static void F_269 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 } ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
F_267 ( V_6 ) ;
F_84 ( V_254 , V_6 , F_104 , & V_264 ) ;
F_102 ( V_6 , V_264 . V_22 ) ;
F_33 ( V_6 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
}
static int F_270 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
T_1 V_634 ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) &&
! F_271 ( V_6 ) ) {
T_1 V_635 = 1 ;
F_49 ( & V_139 , V_312 , 1 , & V_635 ) ;
}
if ( F_191 ( V_6 ) && ! F_272 ( V_6 ) ) {
T_1 V_636 = 0x01 ;
F_49 ( & V_139 , V_515 , sizeof( V_636 ) , & V_636 ) ;
}
if ( F_22 ( V_108 , & V_6 -> V_55 ) &&
F_35 ( V_6 ) ) {
struct V_314 V_141 ;
V_141 . V_317 = 0x01 ;
V_141 . V_318 = 0x00 ;
if ( V_141 . V_317 != F_132 ( V_6 ) ||
V_141 . V_318 != F_273 ( V_6 ) )
F_49 ( & V_139 , V_319 ,
sizeof( V_141 ) , & V_141 ) ;
}
if ( F_38 ( V_6 ) ) {
if ( F_22 ( V_108 , & V_6 -> V_55 ) ) {
F_52 ( & V_139 ) ;
F_48 ( & V_139 ) ;
}
if ( F_22 ( V_112 , & V_6 -> V_55 ) )
F_63 ( & V_139 ) ;
}
V_634 = F_22 ( V_109 , & V_6 -> V_55 ) ;
if ( V_634 != F_22 ( V_306 , & V_6 -> V_153 ) )
F_49 ( & V_139 , V_307 ,
sizeof( V_634 ) , & V_634 ) ;
if ( F_35 ( V_6 ) ) {
F_118 ( & V_139 , false ) ;
F_113 ( V_6 , & V_139 ) ;
F_60 ( & V_139 ) ;
F_187 ( & V_139 ) ;
F_57 ( & V_139 ) ;
}
return F_55 ( & V_139 , F_269 ) ;
}
int F_100 ( struct V_5 * V_6 , T_1 V_637 )
{
struct V_263 V_264 = { NULL , V_6 } ;
T_1 V_24 , V_638 [] = { 0 , 0 , 0 } ;
int V_27 ;
if ( ! F_22 ( V_202 , & V_6 -> V_55 ) )
return 0 ;
if ( V_637 ) {
if ( F_270 ( V_6 ) == 0 )
return 0 ;
F_84 ( V_254 , V_6 , F_104 ,
& V_264 ) ;
goto F_102;
}
F_84 ( V_254 , V_6 , F_104 , & V_264 ) ;
if ( F_22 ( V_639 , & V_6 -> V_55 ) )
V_24 = V_623 ;
else
V_24 = V_279 ;
F_84 ( 0 , V_6 , F_106 , & V_24 ) ;
if ( memcmp ( V_6 -> V_178 , V_638 , sizeof( V_638 ) ) != 0 )
F_3 ( V_640 , V_6 ,
V_638 , sizeof( V_638 ) , NULL ) ;
F_102:
V_27 = F_102 ( V_6 , V_264 . V_22 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
return V_27 ;
}
void F_274 ( struct V_5 * V_6 , int V_27 )
{
struct V_129 * V_23 ;
T_1 V_24 ;
V_23 = F_45 ( V_254 , V_6 ) ;
if ( ! V_23 )
return;
if ( V_27 == - V_641 )
V_24 = V_642 ;
else
V_24 = V_3 ;
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_254 , V_24 ) ;
F_87 ( V_23 ) ;
}
void F_275 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
F_32 ( V_6 ) ;
F_65 ( V_152 , & V_6 -> V_55 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_107 , & V_6 -> V_55 ) ) {
T_1 V_233 = V_281 ;
F_49 ( & V_139 , V_234 ,
sizeof( V_233 ) , & V_233 ) ;
}
F_60 ( & V_139 ) ;
F_52 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
V_6 -> V_273 = 0 ;
F_102 ( V_6 , NULL ) ;
F_33 ( V_6 ) ;
}
void F_276 ( struct V_5 * V_6 , struct V_643 * V_342 ,
bool V_644 )
{
struct V_645 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_646 = V_644 ;
F_76 ( & V_26 . V_342 . V_344 . V_204 , & V_342 -> V_204 ) ;
V_26 . V_342 . V_344 . type = V_345 ;
V_26 . V_342 . type = V_342 -> type ;
memcpy ( V_26 . V_342 . V_149 , V_342 -> V_149 , V_647 ) ;
V_26 . V_342 . V_347 = V_342 -> V_347 ;
F_3 ( V_648 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static T_1 F_277 ( struct V_649 * V_650 )
{
switch ( V_650 -> type ) {
case V_537 :
case V_538 :
if ( V_650 -> V_535 )
return V_539 ;
return V_536 ;
case V_541 :
if ( V_650 -> V_535 )
return V_542 ;
return V_540 ;
case V_544 :
return V_543 ;
}
return V_536 ;
}
void F_278 ( struct V_5 * V_6 , struct V_649 * V_342 , bool V_644 )
{
struct V_651 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_342 -> V_595 == V_358 &&
( V_342 -> V_204 . V_505 [ 5 ] & 0xc0 ) != 0xc0 )
V_26 . V_646 = 0x00 ;
else
V_26 . V_646 = V_644 ;
F_76 ( & V_26 . V_342 . V_344 . V_204 , & V_342 -> V_204 ) ;
V_26 . V_342 . V_344 . type = F_159 ( V_186 , V_342 -> V_595 ) ;
V_26 . V_342 . type = F_277 ( V_342 ) ;
V_26 . V_342 . V_545 = V_342 -> V_545 ;
V_26 . V_342 . V_546 = V_342 -> V_546 ;
V_26 . V_342 . rand = V_342 -> rand ;
if ( V_342 -> type == V_537 )
V_26 . V_342 . V_532 = 1 ;
memcpy ( V_26 . V_342 . V_149 , V_342 -> V_149 , sizeof( V_342 -> V_149 ) ) ;
F_3 ( V_652 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_279 ( struct V_5 * V_6 , struct V_653 * V_524 )
{
struct V_654 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_26 ( & V_524 -> V_655 , V_70 ) )
V_26 . V_646 = 0x01 ;
else
V_26 . V_646 = 0x00 ;
F_76 ( & V_26 . V_655 , & V_524 -> V_655 ) ;
F_76 ( & V_26 . V_524 . V_344 . V_204 , & V_524 -> V_204 ) ;
V_26 . V_524 . V_344 . type = F_159 ( V_186 , V_524 -> V_348 ) ;
memcpy ( V_26 . V_524 . V_149 , V_524 -> V_149 , sizeof( V_524 -> V_149 ) ) ;
F_3 ( V_656 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_280 ( struct V_5 * V_6 , struct V_657 * V_658 ,
bool V_644 )
{
struct V_659 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_658 -> V_595 == V_358 &&
( V_658 -> V_204 . V_505 [ 5 ] & 0xc0 ) != 0xc0 )
V_26 . V_646 = 0x00 ;
else
V_26 . V_646 = V_644 ;
F_76 ( & V_26 . V_342 . V_344 . V_204 , & V_658 -> V_204 ) ;
V_26 . V_342 . V_344 . type = F_159 ( V_186 , V_658 -> V_595 ) ;
V_26 . V_342 . V_532 = V_658 -> V_532 ;
memcpy ( V_26 . V_342 . V_149 , V_658 -> V_149 , sizeof( V_658 -> V_149 ) ) ;
F_3 ( V_660 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_281 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_595 , T_1 V_646 , T_2 V_188 ,
T_2 V_190 , T_2 V_604 , T_2 V_278 )
{
struct V_661 V_26 ;
if ( ! F_282 ( V_204 , V_595 ) )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = F_159 ( V_186 , V_595 ) ;
V_26 . V_646 = V_646 ;
V_26 . V_188 = F_6 ( V_188 ) ;
V_26 . V_190 = F_6 ( V_190 ) ;
V_26 . V_604 = F_6 ( V_604 ) ;
V_26 . V_278 = F_6 ( V_278 ) ;
F_3 ( V_662 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static inline T_2 F_283 ( T_1 * V_172 , T_2 V_663 , T_1 type , T_1 * V_7 ,
T_1 V_8 )
{
V_172 [ V_663 ++ ] = sizeof( type ) + V_8 ;
V_172 [ V_663 ++ ] = type ;
memcpy ( & V_172 [ V_663 ] , V_7 , V_8 ) ;
V_663 += V_8 ;
return V_663 ;
}
void F_284 ( struct V_5 * V_6 , struct V_228 * V_229 ,
T_6 V_153 , T_1 * V_77 , T_1 V_132 )
{
char V_618 [ 512 ] ;
struct V_664 * V_26 = ( void * ) V_618 ;
T_2 V_663 = 0 ;
F_76 ( & V_26 -> V_344 . V_204 , & V_229 -> V_248 ) ;
V_26 -> V_344 . type = F_159 ( V_229 -> type , V_229 -> V_374 ) ;
V_26 -> V_153 = F_285 ( V_153 ) ;
if ( V_229 -> V_665 > 0 ) {
memcpy ( & V_26 -> V_172 [ V_663 ] ,
V_229 -> V_666 , V_229 -> V_665 ) ;
V_663 = V_229 -> V_665 ;
} else {
if ( V_132 > 0 )
V_663 = F_283 ( V_26 -> V_172 , 0 , V_137 ,
V_77 , V_132 ) ;
if ( memcmp ( V_229 -> V_178 , L_43 , 3 ) != 0 )
V_663 = F_283 ( V_26 -> V_172 , V_663 ,
V_667 ,
V_229 -> V_178 , 3 ) ;
}
V_26 -> V_663 = F_6 ( V_663 ) ;
F_3 ( V_668 , V_6 , V_618 ,
sizeof( * V_26 ) + V_663 , NULL ) ;
}
static void F_286 ( struct V_129 * V_23 , void * V_7 )
{
struct V_9 * * V_22 = V_7 ;
V_23 -> F_13 ( V_23 , 0 ) ;
* V_22 = V_23 -> V_22 ;
F_82 ( * V_22 ) ;
F_87 ( V_23 ) ;
}
static void F_287 ( struct V_129 * V_23 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_351 * V_141 = V_23 -> V_148 ;
F_151 ( V_6 , & V_141 -> V_344 . V_204 , V_141 -> V_344 . type , V_23 -> V_22 ) ;
V_23 -> F_13 ( V_23 , 0 ) ;
F_87 ( V_23 ) ;
}
bool F_288 ( struct V_5 * V_6 )
{
struct V_129 * V_23 ;
struct V_147 * V_141 ;
V_23 = F_45 ( V_254 , V_6 ) ;
if ( ! V_23 )
return false ;
V_141 = V_23 -> V_148 ;
if ( ! V_141 -> V_149 )
return true ;
return false ;
}
void F_289 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_242 ,
bool V_669 )
{
struct V_670 V_26 ;
struct V_9 * V_22 = NULL ;
if ( F_288 ( V_6 ) && F_91 ( V_6 ) == 1 ) {
F_92 ( & V_6 -> V_213 ) ;
F_93 ( V_6 -> V_214 , & V_6 -> V_213 . V_199 ) ;
}
if ( ! V_669 )
return;
if ( V_368 != V_246 && V_368 != V_186 )
return;
F_84 ( V_362 , V_6 , F_286 , & V_22 ) ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = F_159 ( V_368 , V_348 ) ;
V_26 . V_242 = V_242 ;
F_3 ( V_671 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
if ( V_22 )
F_78 ( V_22 ) ;
F_84 ( V_353 , V_6 , F_287 ,
V_6 ) ;
}
void F_290 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_24 )
{
T_1 V_595 = F_159 ( V_368 , V_348 ) ;
struct V_360 * V_141 ;
struct V_129 * V_23 ;
F_84 ( V_353 , V_6 , F_287 ,
V_6 ) ;
V_23 = F_45 ( V_362 , V_6 ) ;
if ( ! V_23 )
return;
V_141 = V_23 -> V_148 ;
if ( F_26 ( V_204 , & V_141 -> V_344 . V_204 ) )
return;
if ( V_141 -> V_344 . type != V_595 )
return;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
void F_291 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_368 ,
T_1 V_348 , T_1 V_24 )
{
struct V_672 V_26 ;
if ( F_288 ( V_6 ) && F_91 ( V_6 ) == 1 ) {
F_92 ( & V_6 -> V_213 ) ;
F_93 ( V_6 -> V_214 , & V_6 -> V_213 . V_199 ) ;
}
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = F_159 ( V_368 , V_348 ) ;
V_26 . V_24 = F_1 ( V_24 ) ;
F_3 ( V_673 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_292 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_674 )
{
struct V_675 V_26 ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = V_345 ;
V_26 . V_674 = V_674 ;
F_3 ( V_676 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_293 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_24 )
{
struct V_129 * V_23 ;
V_23 = F_45 ( V_383 , V_6 ) ;
if ( ! V_23 )
return;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
void F_294 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_24 )
{
struct V_129 * V_23 ;
V_23 = F_45 ( V_378 , V_6 ) ;
if ( ! V_23 )
return;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
int F_295 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_6 V_677 ,
T_1 V_678 )
{
struct V_679 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = F_159 ( V_368 , V_348 ) ;
V_26 . V_678 = V_678 ;
V_26 . V_677 = F_28 ( V_677 ) ;
return F_3 ( V_680 , V_6 , & V_26 , sizeof( V_26 ) ,
NULL ) ;
}
int F_296 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 )
{
struct V_681 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = F_159 ( V_368 , V_348 ) ;
return F_3 ( V_682 , V_6 , & V_26 , sizeof( V_26 ) ,
NULL ) ;
}
static int F_297 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_24 ,
T_1 V_17 )
{
struct V_129 * V_23 ;
V_23 = F_45 ( V_17 , V_6 ) ;
if ( ! V_23 )
return - V_683 ;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
return 0 ;
}
int F_298 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_24 )
{
return F_297 ( V_6 , V_204 , V_368 , V_348 ,
V_24 , V_417 ) ;
}
int F_299 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_24 )
{
return F_297 ( V_6 , V_204 , V_368 , V_348 ,
V_24 ,
V_420 ) ;
}
int F_300 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_24 )
{
return F_297 ( V_6 , V_204 , V_368 , V_348 ,
V_24 , V_423 ) ;
}
int F_301 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_1 V_24 )
{
return F_297 ( V_6 , V_204 , V_368 , V_348 ,
V_24 ,
V_425 ) ;
}
int F_302 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_368 , T_1 V_348 , T_6 V_412 ,
T_1 V_684 )
{
struct V_685 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_344 . V_204 , V_204 ) ;
V_26 . V_344 . type = F_159 ( V_368 , V_348 ) ;
V_26 . V_412 = F_285 ( V_412 ) ;
V_26 . V_684 = V_684 ;
return F_3 ( V_686 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_303 ( struct V_228 * V_229 , T_1 V_1 )
{
struct V_687 V_26 ;
struct V_129 * V_23 ;
T_1 V_24 = F_1 ( V_1 ) ;
F_76 ( & V_26 . V_344 . V_204 , & V_229 -> V_248 ) ;
V_26 . V_344 . type = F_159 ( V_229 -> type , V_229 -> V_374 ) ;
V_26 . V_24 = V_24 ;
V_23 = F_164 ( V_229 ) ;
F_3 ( V_688 , V_229 -> V_6 , & V_26 , sizeof( V_26 ) ,
V_23 ? V_23 -> V_22 : NULL ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , V_24 ) ;
F_87 ( V_23 ) ;
}
}
void F_304 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 } ;
bool V_269 ;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
F_84 ( V_305 , V_6 ,
F_105 , & V_271 ) ;
return;
}
if ( F_22 ( V_306 , & V_6 -> V_153 ) )
V_269 = ! F_73 ( V_109 ,
& V_6 -> V_55 ) ;
else
V_269 = F_69 ( V_109 ,
& V_6 -> V_55 ) ;
F_84 ( V_305 , V_6 , F_104 ,
& V_264 ) ;
if ( V_269 )
F_102 ( V_6 , V_264 . V_22 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
}
static void F_305 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_170 V_141 ;
if ( ! F_58 ( V_6 ) )
return;
memset ( V_6 -> V_172 , 0 , sizeof( V_6 -> V_172 ) ) ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
F_49 ( V_139 , V_173 , sizeof( V_141 ) , & V_141 ) ;
}
void F_306 ( struct V_5 * V_6 , T_1 V_181 , T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 } ;
struct V_138 V_139 ;
bool V_269 = false ;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
if ( V_181 && F_69 ( V_110 ,
& V_6 -> V_55 ) ) {
F_65 ( V_111 , & V_6 -> V_55 ) ;
F_102 ( V_6 , NULL ) ;
}
F_84 ( V_308 , V_6 , F_105 ,
& V_271 ) ;
return;
}
if ( V_181 ) {
V_269 = ! F_73 ( V_110 , & V_6 -> V_55 ) ;
} else {
V_269 = F_69 ( V_110 , & V_6 -> V_55 ) ;
if ( ! V_269 )
V_269 = F_69 ( V_111 ,
& V_6 -> V_55 ) ;
else
F_65 ( V_111 , & V_6 -> V_55 ) ;
}
F_84 ( V_308 , V_6 , F_104 , & V_264 ) ;
if ( V_269 )
F_102 ( V_6 , V_264 . V_22 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) ) {
if ( F_22 ( V_310 , & V_6 -> V_55 ) )
F_49 ( & V_139 , V_311 ,
sizeof( V_181 ) , & V_181 ) ;
F_57 ( & V_139 ) ;
} else {
F_305 ( & V_139 ) ;
}
F_55 ( & V_139 , NULL ) ;
}
void F_307 ( struct V_5 * V_6 , T_1 V_181 , T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 } ;
bool V_269 = false ;
if ( V_24 ) {
T_1 V_271 = F_1 ( V_24 ) ;
if ( V_181 ) {
if ( F_69 ( V_113 ,
& V_6 -> V_55 ) )
F_102 ( V_6 , NULL ) ;
F_65 ( V_514 , & V_6 -> V_55 ) ;
}
F_84 ( V_513 , V_6 ,
F_105 , & V_271 ) ;
return;
}
if ( V_181 ) {
V_269 = ! F_73 ( V_113 , & V_6 -> V_55 ) ;
} else {
V_269 = F_69 ( V_113 , & V_6 -> V_55 ) ;
F_65 ( V_514 , & V_6 -> V_55 ) ;
}
F_84 ( V_513 , V_6 ,
F_104 , & V_264 ) ;
if ( V_269 )
F_102 ( V_6 , V_264 . V_22 ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
}
static void F_308 ( struct V_129 * V_23 , void * V_7 )
{
struct V_263 * V_264 = V_7 ;
if ( V_264 -> V_22 == NULL ) {
V_264 -> V_22 = V_23 -> V_22 ;
F_82 ( V_264 -> V_22 ) ;
}
}
void F_309 ( struct V_5 * V_6 , T_1 * V_178 ,
T_1 V_24 )
{
struct V_263 V_264 = { NULL , V_6 , F_1 (status) } ;
F_84 ( V_322 , V_6 , F_308 , & V_264 ) ;
F_84 ( V_320 , V_6 , F_308 , & V_264 ) ;
F_84 ( V_321 , V_6 , F_308 , & V_264 ) ;
if ( ! V_24 )
F_3 ( V_640 , V_6 , V_178 , 3 ,
NULL ) ;
if ( V_264 . V_22 )
F_78 ( V_264 . V_22 ) ;
}
void F_310 ( struct V_5 * V_6 , T_1 * V_77 , T_1 V_24 )
{
struct V_429 V_26 ;
struct V_129 * V_23 ;
if ( V_24 )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
memcpy ( V_26 . V_77 , V_77 , V_689 ) ;
memcpy ( V_26 . V_207 , V_6 -> V_207 , V_690 ) ;
V_23 = F_45 ( V_430 , V_6 ) ;
if ( ! V_23 ) {
memcpy ( V_6 -> V_133 , V_77 , sizeof( V_6 -> V_133 ) ) ;
if ( F_45 ( V_254 , V_6 ) )
return;
}
F_3 ( V_431 , V_6 , & V_26 , sizeof( V_26 ) ,
V_23 ? V_23 -> V_22 : NULL ) ;
}
void F_311 ( struct V_5 * V_6 , T_1 * V_442 ,
T_1 * V_441 , T_1 * V_443 , T_1 * V_444 ,
T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_32 , V_6 -> V_77 , V_24 ) ;
V_23 = F_45 ( V_432 , V_6 ) ;
if ( ! V_23 )
return;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_432 ,
F_1 ( V_24 ) ) ;
} else {
if ( F_191 ( V_6 ) && V_443 && V_444 ) {
struct V_691 V_29 ;
memcpy ( V_29 . V_442 , V_442 , sizeof( V_29 . V_442 ) ) ;
memcpy ( V_29 . V_441 , V_441 , sizeof( V_29 . V_441 ) ) ;
memcpy ( V_29 . V_443 , V_443 , sizeof( V_29 . V_443 ) ) ;
memcpy ( V_29 . V_444 , V_444 , sizeof( V_29 . V_444 ) ) ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 ,
V_432 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
} else {
struct V_692 V_29 ;
memcpy ( V_29 . V_438 , V_442 , sizeof( V_29 . V_438 ) ) ;
memcpy ( V_29 . rand , V_441 , sizeof( V_29 . rand ) ) ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 ,
V_432 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
}
}
F_87 ( V_23 ) ;
}
void F_312 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_368 ,
T_1 V_348 , T_1 * V_178 , T_10 V_479 , T_6 V_153 ,
T_1 * V_172 , T_2 V_663 , T_1 * V_693 , T_1 V_694 )
{
char V_618 [ 512 ] ;
struct V_695 * V_26 = ( void * ) V_618 ;
T_3 V_696 ;
bool V_264 ;
if ( ! F_208 ( V_6 ) ) {
if ( V_368 == V_246 )
return;
if ( V_368 == V_186 && F_124 ( & V_6 -> V_633 ) )
return;
}
if ( V_6 -> V_218 . V_479 != V_550 &&
( V_479 < V_6 -> V_218 . V_479 || V_479 == V_550 ) )
return;
if ( sizeof( * V_26 ) + V_663 + V_694 + 5 > sizeof( V_618 ) )
return;
memset ( V_618 , 0 , sizeof( V_618 ) ) ;
if ( V_479 == V_550 && ! V_6 -> V_218 . V_474 )
V_479 = 0 ;
F_76 ( & V_26 -> V_344 . V_204 , V_204 ) ;
V_26 -> V_344 . type = F_159 ( V_368 , V_348 ) ;
V_26 -> V_479 = V_479 ;
V_26 -> V_153 = F_28 ( V_153 ) ;
if ( V_663 > 0 ) {
if ( V_6 -> V_218 . V_478 > 0 )
V_264 = F_313 ( V_172 , V_663 ,
V_6 -> V_218 . V_478 ,
V_6 -> V_218 . V_326 ) ;
else
V_264 = true ;
if ( ! V_264 && ! V_694 )
return;
memcpy ( V_26 -> V_172 , V_172 , V_663 ) ;
} else {
if ( V_6 -> V_218 . V_478 > 0 && ! V_694 )
return;
V_264 = false ;
}
if ( V_178 && ! F_314 ( V_26 -> V_172 , V_663 , V_667 ) )
V_663 = F_283 ( V_26 -> V_172 , V_663 , V_667 ,
V_178 , 3 ) ;
if ( V_694 > 0 ) {
if ( V_6 -> V_218 . V_478 > 0 ) {
if ( ! V_264 && ! F_313 ( V_693 , V_694 ,
V_6 -> V_218 . V_478 ,
V_6 -> V_218 . V_326 ) )
return;
}
memcpy ( V_26 -> V_172 + V_663 , V_693 , V_694 ) ;
} else {
if ( V_6 -> V_218 . V_478 > 0 && ! V_264 )
return;
}
V_26 -> V_663 = F_6 ( V_663 + V_694 ) ;
V_696 = sizeof( * V_26 ) + V_663 + V_694 ;
F_3 ( V_697 , V_6 , V_26 , V_696 , NULL ) ;
}
void F_315 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_368 ,
T_1 V_348 , T_10 V_479 , T_1 * V_77 , T_1 V_132 )
{
struct V_695 * V_26 ;
char V_618 [ sizeof( * V_26 ) + V_689 + 2 ] ;
T_2 V_663 ;
V_26 = (struct V_695 * ) V_618 ;
memset ( V_618 , 0 , sizeof( V_618 ) ) ;
F_76 ( & V_26 -> V_344 . V_204 , V_204 ) ;
V_26 -> V_344 . type = F_159 ( V_368 , V_348 ) ;
V_26 -> V_479 = V_479 ;
V_663 = F_283 ( V_26 -> V_172 , 0 , V_137 , V_77 ,
V_132 ) ;
V_26 -> V_663 = F_6 ( V_663 ) ;
F_3 ( V_697 , V_6 , V_26 , sizeof( * V_26 ) + V_663 , NULL ) ;
}
void F_316 ( struct V_5 * V_6 , T_1 V_698 )
{
struct V_699 V_26 ;
F_11 ( L_44 , V_6 -> V_77 , V_698 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . type = V_6 -> V_218 . type ;
V_26 . V_698 = V_698 ;
F_3 ( V_700 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static void F_317 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_32 , V_6 -> V_77 , V_24 ) ;
}
void F_318 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
if ( ! F_22 ( V_112 , & V_6 -> V_55 ) )
return;
F_54 ( & V_139 , V_6 ) ;
F_63 ( & V_139 ) ;
F_55 ( & V_139 , F_317 ) ;
}
