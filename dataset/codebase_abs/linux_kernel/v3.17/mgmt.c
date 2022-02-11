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
V_23 -> V_148 = F_16 ( V_21 , V_15 ) ;
if ( ! V_23 -> V_148 ) {
F_18 ( V_23 ) ;
return NULL ;
}
if ( V_7 )
memcpy ( V_23 -> V_148 , V_7 , V_21 ) ;
V_23 -> V_22 = V_22 ;
F_81 ( V_22 ) ;
F_82 ( & V_23 -> V_209 , & V_6 -> V_210 ) ;
return V_23 ;
}
static void F_83 ( T_2 V_17 , struct V_5 * V_6 ,
void (* F_84)( struct V_129 * V_23 ,
void * V_7 ) ,
void * V_7 )
{
struct V_129 * V_23 , * V_211 ;
F_85 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_17 > 0 && V_23 -> V_17 != V_17 )
continue;
F_84 ( V_23 , V_7 ) ;
}
}
static void F_86 ( struct V_129 * V_23 )
{
F_87 ( & V_23 -> V_209 ) ;
F_77 ( V_23 ) ;
}
static int F_88 ( struct V_9 * V_22 , T_2 V_17 , struct V_5 * V_6 )
{
T_5 V_83 = F_28 ( F_39 ( V_6 ) ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_17 , 0 , & V_83 ,
sizeof( V_83 ) ) ;
}
static void F_89 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_8 , V_6 -> V_77 , V_24 ) ;
if ( F_90 ( V_6 ) == 0 ) {
F_91 ( & V_6 -> V_212 ) ;
F_92 ( V_6 -> V_213 , & V_6 -> V_212 . V_199 ) ;
}
}
static bool F_93 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_214 V_141 ;
struct V_215 * V_216 ;
switch ( V_6 -> V_217 . V_218 ) {
case V_219 :
if ( F_22 ( V_220 , & V_6 -> V_153 ) ) {
F_49 ( V_139 , V_221 , 0 , NULL ) ;
} else {
F_91 ( & V_6 -> V_222 ) ;
F_94 ( V_139 ) ;
}
return true ;
case V_223 :
V_216 = F_95 ( V_6 , V_70 ,
V_224 ) ;
if ( ! V_216 )
break;
F_76 ( & V_141 . V_204 , & V_216 -> V_7 . V_204 ) ;
F_49 ( V_139 , V_225 , sizeof( V_141 ) ,
& V_141 ) ;
return true ;
default:
if ( F_22 ( V_226 , & V_6 -> V_55 ) ) {
F_94 ( V_139 ) ;
return true ;
}
break;
}
return false ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
struct V_227 * V_228 ;
bool V_229 ;
int V_27 ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_230 , & V_6 -> V_153 ) ||
F_22 ( V_231 , & V_6 -> V_153 ) ) {
T_1 V_232 = 0x00 ;
F_49 ( & V_139 , V_233 , 1 , & V_232 ) ;
}
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_62 ( & V_139 ) ;
V_229 = F_93 ( & V_139 ) ;
F_21 (conn, &hdev->conn_hash.list, list) {
struct V_234 V_235 ;
struct V_236 V_237 ;
switch ( V_228 -> V_218 ) {
case V_238 :
case V_239 :
V_235 . V_240 = F_6 ( V_228 -> V_240 ) ;
V_235 . V_241 = 0x15 ;
F_49 ( & V_139 , V_242 , sizeof( V_235 ) , & V_235 ) ;
break;
case V_243 :
if ( V_228 -> type == V_186 )
F_49 ( & V_139 , V_244 ,
0 , NULL ) ;
else if ( V_228 -> type == V_245 )
F_49 ( & V_139 , V_246 ,
6 , & V_228 -> V_247 ) ;
break;
case V_248 :
F_76 ( & V_237 . V_204 , & V_228 -> V_247 ) ;
V_237 . V_241 = 0x15 ;
if ( V_228 -> type == V_245 )
F_49 ( & V_139 , V_249 ,
sizeof( V_237 ) , & V_237 ) ;
else if ( V_228 -> type == V_250 )
F_49 ( & V_139 , V_251 ,
sizeof( V_237 ) , & V_237 ) ;
break;
}
}
V_27 = F_55 ( & V_139 , F_89 ) ;
if ( ! V_27 && V_229 )
F_97 ( V_6 , V_252 ) ;
return V_27 ;
}
static int F_98 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_253 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( F_45 ( V_253 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_253 ,
V_255 ) ;
goto V_256;
}
if ( F_69 ( V_257 , & V_6 -> V_55 ) ) {
F_91 ( & V_6 -> V_212 ) ;
if ( V_141 -> V_149 ) {
F_79 ( V_22 , V_253 , V_6 ,
V_7 , V_21 ) ;
V_27 = F_99 ( V_6 , 1 ) ;
goto V_256;
}
}
if ( ! ! V_141 -> V_149 == F_40 ( V_6 ) ) {
V_27 = F_88 ( V_22 , V_253 , V_6 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_253 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
if ( V_141 -> V_149 ) {
F_92 ( V_6 -> V_213 , & V_6 -> V_258 ) ;
V_27 = 0 ;
} else {
V_27 = F_96 ( V_6 ) ;
if ( ! V_27 )
F_100 ( V_6 -> V_213 , & V_6 -> V_212 ,
V_259 ) ;
if ( V_27 == - V_260 ) {
F_91 ( & V_6 -> V_212 ) ;
F_92 ( V_6 -> V_213 , & V_6 -> V_212 . V_199 ) ;
V_27 = 0 ;
}
}
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_101 ( struct V_5 * V_6 , struct V_9 * V_74 )
{
T_5 V_26 ;
V_26 = F_28 ( F_39 ( V_6 ) ) ;
return F_3 ( V_261 , V_6 , & V_26 , sizeof( V_26 ) , V_74 ) ;
}
int F_102 ( struct V_5 * V_6 )
{
return F_101 ( V_6 , NULL ) ;
}
static void F_103 ( struct V_129 * V_23 , void * V_7 )
{
struct V_262 * V_263 = V_7 ;
F_88 ( V_23 -> V_22 , V_23 -> V_17 , V_263 -> V_6 ) ;
F_87 ( & V_23 -> V_209 ) ;
if ( V_263 -> V_22 == NULL ) {
V_263 -> V_22 = V_23 -> V_22 ;
F_81 ( V_263 -> V_22 ) ;
}
F_77 ( V_23 ) ;
}
static void F_104 ( struct V_129 * V_23 , void * V_7 )
{
T_1 * V_24 = V_7 ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , * V_24 ) ;
F_86 ( V_23 ) ;
}
static T_1 F_105 ( struct V_5 * V_6 )
{
if ( ! F_35 ( V_6 ) )
return V_264 ;
else if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return V_265 ;
else
return V_266 ;
}
static T_1 F_106 ( struct V_5 * V_6 )
{
if ( ! F_38 ( V_6 ) )
return V_264 ;
else if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return V_265 ;
else
return V_266 ;
}
static void F_107 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
struct V_147 * V_141 ;
struct V_138 V_139 ;
bool V_267 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_146 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_269 ) ;
F_65 ( V_152 , & V_6 -> V_55 ) ;
goto V_270;
}
V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 ) {
V_267 = ! F_73 ( V_105 ,
& V_6 -> V_55 ) ;
if ( V_6 -> V_271 > 0 ) {
int V_272 = F_108 ( V_6 -> V_271 * 1000 ) ;
F_100 ( V_6 -> V_273 , & V_6 -> V_274 ,
V_272 ) ;
}
} else {
V_267 = F_69 ( V_105 ,
& V_6 -> V_55 ) ;
}
F_88 ( V_23 -> V_22 , V_146 , V_6 ) ;
if ( V_267 )
F_101 ( V_6 , V_23 -> V_22 ) ;
F_54 ( & V_139 , V_6 ) ;
F_60 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
V_270:
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_109 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_275 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_2 V_276 ;
T_1 V_232 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) &&
! F_22 ( V_107 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_265 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 && V_141 -> V_149 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_254 ) ;
V_276 = F_110 ( V_141 -> V_276 ) ;
if ( ( V_141 -> V_149 == 0x00 && V_276 > 0 ) ||
( V_141 -> V_149 == 0x02 && V_276 == 0 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) && V_276 > 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_277 ) ;
goto V_256;
}
if ( F_45 ( V_146 , V_6 ) ||
F_45 ( V_180 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_255 ) ;
goto V_256;
}
if ( ! F_22 ( V_103 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_146 ,
V_265 ) ;
goto V_256;
}
if ( ! F_40 ( V_6 ) ) {
bool V_267 = false ;
if ( ! ! V_141 -> V_149 != F_22 ( V_105 , & V_6 -> V_55 ) ) {
F_111 ( V_105 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_88 ( V_22 , V_146 , V_6 ) ;
if ( V_27 < 0 )
goto V_256;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_256;
}
if ( ! ! V_141 -> V_149 == F_22 ( V_105 , & V_6 -> V_55 ) &&
( V_141 -> V_149 == 0x02 ) == F_22 ( V_152 ,
& V_6 -> V_55 ) ) {
F_91 ( & V_6 -> V_274 ) ;
V_6 -> V_271 = V_276 ;
if ( V_141 -> V_149 && V_6 -> V_271 > 0 ) {
int V_272 = F_108 ( V_6 -> V_271 * 1000 ) ;
F_100 ( V_6 -> V_273 , & V_6 -> V_274 ,
V_272 ) ;
}
V_27 = F_88 ( V_22 , V_146 , V_6 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_146 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
F_91 ( & V_6 -> V_274 ) ;
V_6 -> V_271 = V_276 ;
if ( V_141 -> V_149 == 0x02 )
F_71 ( V_152 , & V_6 -> V_55 ) ;
else
F_65 ( V_152 , & V_6 -> V_55 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
goto V_278;
V_232 = V_279 ;
if ( V_141 -> V_149 ) {
struct V_280 V_281 ;
if ( V_141 -> V_149 == 0x02 ) {
V_281 . V_282 = F_112 ( T_1 , V_6 -> V_282 , 2 ) ;
V_281 . V_283 [ 0 ] = 0x00 ;
V_281 . V_283 [ 1 ] = 0x8b ;
V_281 . V_283 [ 2 ] = 0x9e ;
V_281 . V_283 [ 3 ] = 0x33 ;
V_281 . V_283 [ 4 ] = 0x8b ;
V_281 . V_283 [ 5 ] = 0x9e ;
} else {
V_281 . V_282 = 1 ;
V_281 . V_283 [ 0 ] = 0x33 ;
V_281 . V_283 [ 1 ] = 0x8b ;
V_281 . V_283 [ 2 ] = 0x9e ;
}
F_49 ( & V_139 , V_284 ,
( V_281 . V_282 * 3 ) + 1 , & V_281 ) ;
V_232 |= V_285 ;
} else {
F_65 ( V_152 , & V_6 -> V_55 ) ;
}
F_49 ( & V_139 , V_233 , sizeof( V_232 ) , & V_232 ) ;
V_278:
F_52 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_107 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_113 ( struct V_138 * V_139 , bool V_181 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_286 V_287 ;
T_1 type ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return;
if ( V_6 -> V_89 < V_90 )
return;
if ( V_181 ) {
type = V_288 ;
V_287 . V_289 = F_6 ( 0x0100 ) ;
} else {
type = V_290 ;
V_287 . V_289 = F_6 ( 0x0800 ) ;
}
V_287 . V_291 = F_6 ( 0x0012 ) ;
if ( F_114 ( V_6 -> V_292 ) != V_287 . V_289 ||
F_114 ( V_6 -> V_293 ) != V_287 . V_291 )
F_49 ( V_139 , V_294 ,
sizeof( V_287 ) , & V_287 ) ;
if ( V_6 -> V_295 != type )
F_49 ( V_139 , V_296 , 1 , & type ) ;
}
static void F_115 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
struct V_147 * V_141 ;
bool V_297 , V_298 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_180 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_269 ) ;
goto V_270;
}
V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 ) {
V_297 = ! F_73 ( V_103 ,
& V_6 -> V_55 ) ;
V_298 = false ;
} else {
V_297 = F_69 ( V_103 ,
& V_6 -> V_55 ) ;
V_298 = F_69 ( V_105 ,
& V_6 -> V_55 ) ;
}
F_88 ( V_23 -> V_22 , V_180 , V_6 ) ;
if ( V_297 || V_298 ) {
F_101 ( V_6 , V_23 -> V_22 ) ;
if ( V_298 )
F_53 ( V_6 ) ;
F_116 ( V_6 ) ;
}
V_270:
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_117 ( struct V_5 * V_6 ,
struct V_9 * V_22 , T_1 V_149 )
{
bool V_267 = false ;
int V_27 ;
if ( ! ! V_149 != F_22 ( V_103 , & V_6 -> V_55 ) )
V_267 = true ;
if ( V_149 ) {
F_71 ( V_103 , & V_6 -> V_55 ) ;
} else {
F_65 ( V_103 , & V_6 -> V_55 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
}
V_27 = F_88 ( V_22 , V_180 , V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_267 ) {
F_116 ( V_6 ) ;
return F_101 ( V_6 , V_22 ) ;
}
return 0 ;
}
static int F_118 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_1 V_232 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) &&
! F_22 ( V_107 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_180 ,
V_265 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_180 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_117 ( V_6 , V_22 , V_141 -> V_149 ) ;
goto V_256;
}
if ( F_45 ( V_146 , V_6 ) ||
F_45 ( V_180 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_180 ,
V_255 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_180 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
F_54 ( & V_139 , V_6 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) ) {
if ( ! V_141 -> V_149 ) {
F_65 ( V_152 , & V_6 -> V_55 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
}
F_52 ( & V_139 ) ;
} else if ( V_141 -> V_149 != F_22 ( V_231 , & V_6 -> V_153 ) ) {
if ( V_141 -> V_149 ) {
V_232 = V_279 ;
} else {
if ( F_119 ( & V_6 -> V_299 ) )
V_232 = V_300 ;
else if ( F_22 ( V_230 , & V_6 -> V_153 ) )
V_232 = V_279 ;
else
goto V_301;
if ( F_22 ( V_230 , & V_6 -> V_153 ) &&
V_6 -> V_271 > 0 )
F_91 ( & V_6 -> V_274 ) ;
}
F_49 ( & V_139 , V_233 , 1 , & V_232 ) ;
}
V_301:
if ( V_141 -> V_149 || F_22 ( V_104 , & V_6 -> V_55 ) )
F_113 ( & V_139 , false ) ;
if ( F_22 ( V_112 , & V_6 -> V_55 ) )
F_63 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_115 ) ;
if ( V_27 < 0 ) {
F_86 ( V_23 ) ;
if ( V_27 == - V_260 )
V_27 = F_117 ( V_6 , V_22 ,
V_141 -> V_149 ) ;
goto V_256;
}
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_120 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
bool V_267 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_302 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 )
V_267 = ! F_73 ( V_106 , & V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_106 , & V_6 -> V_55 ) ;
V_27 = F_88 ( V_22 , V_302 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_121 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
T_1 V_149 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_105 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_303 ,
V_24 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_303 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_267 = false ;
if ( ! ! V_141 -> V_149 != F_22 ( V_109 ,
& V_6 -> V_55 ) ) {
F_111 ( V_109 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_88 ( V_22 , V_303 , V_6 ) ;
if ( V_27 < 0 )
goto V_256;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_256;
}
if ( F_45 ( V_303 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_303 ,
V_255 ) ;
goto V_256;
}
V_149 = ! ! V_141 -> V_149 ;
if ( F_22 ( V_304 , & V_6 -> V_153 ) == V_149 ) {
V_27 = F_88 ( V_22 , V_303 , V_6 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_303 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
V_27 = F_122 ( V_6 , V_305 , sizeof( V_149 ) , & V_149 ) ;
if ( V_27 < 0 ) {
F_86 ( V_23 ) ;
goto V_256;
}
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_123 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_105 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_306 , V_24 ) ;
if ( ! F_36 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_306 ,
V_264 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_306 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_267 ;
if ( V_141 -> V_149 ) {
V_267 = ! F_73 ( V_110 ,
& V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_110 ,
& V_6 -> V_55 ) ;
if ( ! V_267 )
V_267 = F_69 ( V_111 ,
& V_6 -> V_55 ) ;
else
F_65 ( V_111 , & V_6 -> V_55 ) ;
}
V_27 = F_88 ( V_22 , V_306 , V_6 ) ;
if ( V_27 < 0 )
goto V_256;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_256;
}
if ( F_45 ( V_306 , V_6 ) ||
F_45 ( V_307 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_306 ,
V_255 ) ;
goto V_256;
}
if ( ! ! V_141 -> V_149 == F_22 ( V_110 , & V_6 -> V_55 ) ) {
V_27 = F_88 ( V_22 , V_306 , V_6 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_306 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
if ( ! V_141 -> V_149 && F_22 ( V_308 , & V_6 -> V_55 ) )
F_122 ( V_6 , V_309 ,
sizeof( V_141 -> V_149 ) , & V_141 -> V_149 ) ;
V_27 = F_122 ( V_6 , V_310 , 1 , & V_141 -> V_149 ) ;
if ( V_27 < 0 ) {
F_86 ( V_23 ) ;
goto V_256;
}
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_124 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
bool V_267 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_105 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_307 , V_24 ) ;
if ( ! F_36 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_264 ) ;
if ( ! F_22 ( V_110 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_265 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 ) {
V_267 = ! F_73 ( V_111 , & V_6 -> V_55 ) ;
} else {
if ( F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_265 ) ;
goto V_268;
}
V_267 = F_69 ( V_111 , & V_6 -> V_55 ) ;
}
V_27 = F_88 ( V_22 , V_307 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_125 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 } ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_83 ( V_311 , V_6 , F_104 ,
& V_269 ) ;
return;
}
F_83 ( V_311 , V_6 , F_103 , & V_263 ) ;
F_101 ( V_6 , V_263 . V_22 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
if ( F_22 ( V_108 , & V_6 -> V_55 ) ) {
struct V_138 V_139 ;
F_32 ( V_6 ) ;
F_54 ( & V_139 , V_6 ) ;
F_52 ( & V_139 ) ;
F_48 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
F_116 ( V_6 ) ;
F_33 ( V_6 ) ;
}
}
static int F_126 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_312 V_281 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
T_1 V_149 , V_313 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_264 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_254 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_265 ) ;
F_32 ( V_6 ) ;
V_149 = ! ! V_141 -> V_149 ;
V_313 = F_127 ( V_6 ) ;
if ( ! F_40 ( V_6 ) || V_149 == V_313 ) {
bool V_267 = false ;
if ( V_149 != F_22 ( V_108 , & V_6 -> V_55 ) ) {
F_111 ( V_108 , & V_6 -> V_55 ) ;
V_267 = true ;
}
if ( ! V_149 && F_22 ( V_112 , & V_6 -> V_55 ) ) {
F_65 ( V_112 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_88 ( V_22 , V_311 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_268;
}
if ( F_45 ( V_311 , V_6 ) ||
F_45 ( V_314 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_255 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_311 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_139 , V_6 ) ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
if ( V_149 ) {
V_281 . V_315 = V_149 ;
V_281 . V_316 = 0x00 ;
} else {
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_62 ( & V_139 ) ;
}
F_49 ( & V_139 , V_317 , sizeof( V_281 ) ,
& V_281 ) ;
V_27 = F_55 ( & V_139 , F_125 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_128 ( struct V_5 * V_6 )
{
struct V_129 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
switch ( V_23 -> V_17 ) {
case V_318 :
case V_319 :
case V_320 :
case V_253 :
return true ;
}
}
return false ;
}
static T_1 F_129 ( const T_1 * V_119 )
{
T_6 V_149 ;
if ( memcmp ( V_119 , V_321 , 12 ) )
return 128 ;
V_149 = F_130 ( & V_119 [ 12 ] ) ;
if ( V_149 > 0xffff )
return 32 ;
return 16 ;
}
static void F_131 ( struct V_5 * V_6 , T_2 V_322 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_322 , V_6 ) ;
if ( ! V_23 )
goto V_268;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , F_1 ( V_24 ) ,
V_6 -> V_178 , 3 ) ;
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static void F_132 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_10 , V_24 ) ;
F_131 ( V_6 , V_318 , V_24 ) ;
}
static int F_133 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_323 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
struct V_118 * V_119 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_128 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_318 ,
V_255 ) ;
goto V_256;
}
V_119 = F_16 ( sizeof( * V_119 ) , V_15 ) ;
if ( ! V_119 ) {
V_27 = - V_16 ;
goto V_256;
}
memcpy ( V_119 -> V_119 , V_141 -> V_119 , 16 ) ;
V_119 -> V_174 = V_141 -> V_174 ;
V_119 -> V_121 = F_129 ( V_141 -> V_119 ) ;
F_134 ( & V_119 -> V_209 , & V_6 -> V_324 ) ;
F_54 ( & V_139 , V_6 ) ;
F_60 ( & V_139 ) ;
F_57 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_132 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_260 )
goto V_256;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_318 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_318 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
V_27 = 0 ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_135 ( struct V_5 * V_6 )
{
if ( ! F_40 ( V_6 ) )
return false ;
if ( ! F_73 ( V_171 , & V_6 -> V_55 ) ) {
F_100 ( V_6 -> V_273 , & V_6 -> V_200 ,
V_325 ) ;
return true ;
}
return false ;
}
static void F_136 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_10 , V_24 ) ;
F_131 ( V_6 , V_319 , V_24 ) ;
}
static int F_137 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_326 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_118 * V_263 , * V_211 ;
T_1 V_327 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_138 V_139 ;
int V_27 , V_328 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_128 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_319 ,
V_255 ) ;
goto V_268;
}
if ( memcmp ( V_141 -> V_119 , V_327 , 16 ) == 0 ) {
F_138 ( V_6 ) ;
if ( F_135 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_319 ,
0 , V_6 -> V_178 , 3 ) ;
goto V_268;
}
goto F_60;
}
V_328 = 0 ;
F_85 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_263 -> V_119 , V_141 -> V_119 , 16 ) != 0 )
continue;
F_87 ( & V_263 -> V_209 ) ;
F_18 ( V_263 ) ;
V_328 ++ ;
}
if ( V_328 == 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_319 ,
V_254 ) ;
goto V_268;
}
F_60:
F_54 ( & V_139 , V_6 ) ;
F_60 ( & V_139 ) ;
F_57 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_136 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_260 )
goto V_268;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_319 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_319 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_27 = 0 ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_139 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_10 , V_24 ) ;
F_131 ( V_6 , V_320 , V_24 ) ;
}
static int F_140 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_329 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_264 ) ;
F_32 ( V_6 ) ;
if ( F_128 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_255 ) ;
goto V_268;
}
if ( ( V_141 -> V_330 & 0x03 ) != 0 || ( V_141 -> V_331 & 0xe0 ) != 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_254 ) ;
goto V_268;
}
V_6 -> V_177 = V_141 -> V_331 ;
V_6 -> V_176 = V_141 -> V_330 ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_320 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_268;
}
F_54 ( & V_139 , V_6 ) ;
if ( F_69 ( V_171 , & V_6 -> V_55 ) ) {
F_33 ( V_6 ) ;
F_141 ( & V_6 -> V_200 ) ;
F_32 ( V_6 ) ;
F_57 ( & V_139 ) ;
}
F_60 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_139 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_260 )
goto V_268;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_320 , 0 ,
V_6 -> V_178 , 3 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_320 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_27 = 0 ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_142 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_332 * V_141 = V_7 ;
const T_2 V_333 = ( ( V_334 - sizeof( * V_141 ) ) /
sizeof( struct V_335 ) ) ;
T_2 V_336 , V_337 ;
bool V_267 ;
int V_45 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_264 ) ;
V_336 = F_110 ( V_141 -> V_336 ) ;
if ( V_336 > V_333 ) {
F_143 ( L_11 ,
V_336 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_254 ) ;
}
V_337 = sizeof( * V_141 ) + V_336 *
sizeof( struct V_335 ) ;
if ( V_337 != V_21 ) {
F_143 ( L_12 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_254 ) ;
}
if ( V_141 -> V_339 != 0x00 && V_141 -> V_339 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_254 ) ;
F_11 ( L_13 , V_6 -> V_77 , V_141 -> V_339 ,
V_336 ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_335 * V_340 = & V_141 -> V_341 [ V_45 ] ;
if ( V_340 -> V_342 . type != V_343 || V_340 -> type > 0x08 )
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_254 ) ;
}
F_32 ( V_6 ) ;
F_144 ( V_6 ) ;
if ( V_141 -> V_339 )
V_267 = ! F_73 ( V_114 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_114 ,
& V_6 -> V_55 ) ;
if ( V_267 )
F_101 ( V_6 , NULL ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_335 * V_340 = & V_141 -> V_341 [ V_45 ] ;
if ( V_340 -> type == V_344 )
continue;
F_145 ( V_6 , NULL , & V_340 -> V_342 . V_204 , V_340 -> V_149 ,
V_340 -> type , V_340 -> V_345 , NULL ) ;
}
F_13 ( V_22 , V_6 -> V_19 , V_338 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return 0 ;
}
static int F_146 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_346 , struct V_9 * V_10 )
{
struct V_347 V_26 ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = V_346 ;
return F_3 ( V_348 , V_6 , & V_26 , sizeof( V_26 ) ,
V_10 ) ;
}
static int F_147 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_349 * V_141 = V_7 ;
struct V_350 V_29 ;
struct V_234 V_235 ;
struct V_129 * V_23 ;
struct V_227 * V_228 ;
int V_27 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
if ( ! F_148 ( V_141 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_141 -> V_352 != 0x00 && V_141 -> V_352 != 0x01 )
return F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_141 -> V_342 . type == V_343 ) {
V_27 = F_149 ( V_6 , & V_141 -> V_342 . V_204 ) ;
} else {
T_1 V_346 ;
if ( V_141 -> V_342 . type == V_353 )
V_346 = V_354 ;
else
V_346 = V_355 ;
F_150 ( V_6 , & V_141 -> V_342 . V_204 , V_346 ) ;
F_151 ( V_6 , & V_141 -> V_342 . V_204 , V_346 ) ;
V_27 = F_152 ( V_6 , & V_141 -> V_342 . V_204 , V_346 ) ;
}
if ( V_27 < 0 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_356 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_141 -> V_352 ) {
if ( V_141 -> V_342 . type == V_343 )
V_228 = F_153 ( V_6 , V_245 ,
& V_141 -> V_342 . V_204 ) ;
else
V_228 = F_153 ( V_6 , V_186 ,
& V_141 -> V_342 . V_204 ) ;
} else {
V_228 = NULL ;
}
if ( ! V_228 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_351 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
F_146 ( V_6 , & V_141 -> V_342 . V_204 , V_141 -> V_342 . type , V_22 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_351 , V_6 , V_141 ,
sizeof( * V_141 ) ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_235 . V_240 = F_6 ( V_228 -> V_240 ) ;
V_235 . V_241 = 0x13 ;
V_27 = F_122 ( V_6 , V_242 , sizeof( V_235 ) , & V_235 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int V_352 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_357 * V_141 = V_7 ;
struct V_358 V_29 ;
struct V_234 V_235 ;
struct V_129 * V_23 ;
struct V_227 * V_228 ;
int V_27 ;
F_11 ( L_7 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
if ( ! F_148 ( V_141 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_359 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_22 ( V_360 , & V_6 -> V_153 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_359 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_256;
}
if ( F_45 ( V_359 , V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_359 ,
V_255 , & V_29 , sizeof( V_29 ) ) ;
goto V_256;
}
if ( V_141 -> V_342 . type == V_343 )
V_228 = F_153 ( V_6 , V_245 ,
& V_141 -> V_342 . V_204 ) ;
else
V_228 = F_153 ( V_6 , V_186 , & V_141 -> V_342 . V_204 ) ;
if ( ! V_228 || V_228 -> V_218 == V_361 || V_228 -> V_218 == V_362 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_359 ,
V_363 , & V_29 , sizeof( V_29 ) ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_359 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
V_235 . V_240 = F_6 ( V_228 -> V_240 ) ;
V_235 . V_241 = V_364 ;
V_27 = F_122 ( V_6 , V_242 , sizeof( V_235 ) , & V_235 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static T_1 F_154 ( T_1 V_365 , T_1 V_346 )
{
switch ( V_365 ) {
case V_186 :
switch ( V_346 ) {
case V_354 :
return V_353 ;
default:
return V_366 ;
}
default:
return V_343 ;
}
}
static int F_155 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_367 * V_29 ;
struct V_227 * V_368 ;
T_3 V_30 ;
int V_27 ;
T_2 V_45 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_369 ,
V_277 ) ;
goto V_268;
}
V_45 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_370 , & V_368 -> V_153 ) )
V_45 ++ ;
}
V_30 = sizeof( * V_29 ) + ( V_45 * sizeof( struct V_371 ) ) ;
V_29 = F_16 ( V_30 , V_15 ) ;
if ( ! V_29 ) {
V_27 = - V_16 ;
goto V_268;
}
V_45 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_370 , & V_368 -> V_153 ) )
continue;
F_76 ( & V_29 -> V_342 [ V_45 ] . V_204 , & V_368 -> V_247 ) ;
V_29 -> V_342 [ V_45 ] . type = F_154 ( V_368 -> type , V_368 -> V_372 ) ;
if ( V_368 -> type == V_250 || V_368 -> type == V_373 )
continue;
V_45 ++ ;
}
V_29 -> V_374 = F_6 ( V_45 ) ;
V_30 = sizeof( * V_29 ) + ( V_45 * sizeof( struct V_371 ) ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_369 , 0 , V_29 ,
V_30 ) ;
F_18 ( V_29 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_156 ( struct V_9 * V_22 , struct V_5 * V_6 ,
struct V_375 * V_141 )
{
struct V_129 * V_23 ;
int V_27 ;
V_23 = F_79 ( V_22 , V_376 , V_6 , V_141 ,
sizeof( * V_141 ) ) ;
if ( ! V_23 )
return - V_16 ;
V_27 = F_122 ( V_6 , V_377 ,
sizeof( V_141 -> V_342 . V_204 ) , & V_141 -> V_342 . V_204 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
return V_27 ;
}
static int F_157 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_227 * V_228 ;
struct V_378 * V_141 = V_7 ;
struct V_379 V_380 ;
struct V_129 * V_23 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_381 ,
V_277 ) ;
goto V_256;
}
V_228 = F_153 ( V_6 , V_245 , & V_141 -> V_342 . V_204 ) ;
if ( ! V_228 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_381 ,
V_363 ) ;
goto V_256;
}
if ( V_228 -> V_382 == V_383 && V_141 -> V_345 != 16 ) {
struct V_375 V_384 ;
memcpy ( & V_384 . V_342 , & V_141 -> V_342 , sizeof( V_384 . V_342 ) ) ;
F_143 ( L_14 ) ;
V_27 = F_156 ( V_22 , V_6 , & V_384 ) ;
if ( V_27 >= 0 )
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_381 ,
V_254 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_381 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
F_76 ( & V_380 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_380 . V_345 = V_141 -> V_345 ;
memcpy ( V_380 . V_385 , V_141 -> V_385 , sizeof( V_380 . V_385 ) ) ;
V_27 = F_122 ( V_6 , V_386 , sizeof( V_380 ) , & V_380 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_158 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_387 * V_141 = V_7 ;
F_11 ( L_7 ) ;
if ( V_141 -> V_388 > V_389 )
return F_13 ( V_22 , V_6 -> V_19 , V_390 ,
V_254 , NULL , 0 ) ;
F_32 ( V_6 ) ;
V_6 -> V_388 = V_141 -> V_388 ;
F_11 ( L_15 , V_6 -> V_77 ,
V_6 -> V_388 ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_390 , 0 , NULL ,
0 ) ;
}
static struct V_129 * F_159 ( struct V_227 * V_228 )
{
struct V_5 * V_6 = V_228 -> V_6 ;
struct V_129 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_17 != V_391 )
continue;
if ( V_23 -> V_130 != V_228 )
continue;
return V_23 ;
}
return NULL ;
}
static void F_160 ( struct V_129 * V_23 , T_1 V_24 )
{
struct V_392 V_29 ;
struct V_227 * V_228 = V_23 -> V_130 ;
F_76 ( & V_29 . V_342 . V_204 , & V_228 -> V_247 ) ;
V_29 . V_342 . type = F_154 ( V_228 -> type , V_228 -> V_372 ) ;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_391 , V_24 ,
& V_29 , sizeof( V_29 ) ) ;
V_228 -> V_393 = NULL ;
V_228 -> V_394 = NULL ;
V_228 -> V_395 = NULL ;
F_161 ( V_228 ) ;
F_86 ( V_23 ) ;
}
void F_162 ( struct V_227 * V_228 , bool V_396 )
{
T_1 V_24 = V_396 ? V_266 : V_3 ;
struct V_129 * V_23 ;
V_23 = F_159 ( V_228 ) ;
if ( V_23 )
F_160 ( V_23 , V_24 ) ;
}
static void F_163 ( struct V_227 * V_228 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_16 , V_24 ) ;
V_23 = F_159 ( V_228 ) ;
if ( ! V_23 )
F_11 ( L_17 ) ;
else
F_160 ( V_23 , F_1 ( V_24 ) ) ;
}
static void F_164 ( struct V_227 * V_228 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_16 , V_24 ) ;
if ( ! V_24 )
return;
V_23 = F_159 ( V_228 ) ;
if ( ! V_23 )
F_11 ( L_17 ) ;
else
F_160 ( V_23 , F_1 ( V_24 ) ) ;
}
static int F_165 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_397 * V_141 = V_7 ;
struct V_392 V_29 ;
struct V_129 * V_23 ;
T_1 V_398 , V_399 ;
struct V_227 * V_228 ;
int V_27 ;
F_11 ( L_7 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
if ( ! F_148 ( V_141 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_141 -> V_400 > V_389 )
return F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
V_398 = V_401 ;
V_399 = V_402 ;
if ( V_141 -> V_342 . type == V_343 ) {
V_228 = F_166 ( V_6 , & V_141 -> V_342 . V_204 , V_398 ,
V_399 ) ;
} else {
T_1 V_346 ;
if ( V_141 -> V_342 . type == V_353 )
V_346 = V_354 ;
else
V_346 = V_355 ;
F_167 ( V_6 , & V_141 -> V_342 . V_204 , V_346 ) ;
V_228 = F_168 ( V_6 , & V_141 -> V_342 . V_204 , V_346 ,
V_398 , V_403 ,
V_404 ) ;
}
if ( F_169 ( V_228 ) ) {
int V_24 ;
if ( F_170 ( V_228 ) == - V_405 )
V_24 = V_255 ;
else
V_24 = V_406 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_24 , & V_29 ,
sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_228 -> V_393 ) {
F_161 ( V_228 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_255 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_391 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
F_161 ( V_228 ) ;
goto V_268;
}
if ( V_141 -> V_342 . type == V_343 ) {
V_228 -> V_393 = F_163 ;
V_228 -> V_394 = F_163 ;
V_228 -> V_395 = F_163 ;
} else {
V_228 -> V_393 = F_164 ;
V_228 -> V_394 = F_164 ;
V_228 -> V_395 = F_164 ;
}
V_228 -> V_388 = V_141 -> V_400 ;
V_23 -> V_130 = V_228 ;
if ( ( V_228 -> V_218 == V_238 || V_228 -> V_218 == V_239 ) &&
F_171 ( V_228 , V_398 , V_399 , true ) )
F_160 ( V_23 , 0 ) ;
V_27 = 0 ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_172 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_371 * V_342 = V_7 ;
struct V_129 * V_23 ;
struct V_227 * V_228 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_407 ,
V_277 ) ;
goto V_268;
}
V_23 = F_45 ( V_391 , V_6 ) ;
if ( ! V_23 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_407 ,
V_254 ) ;
goto V_268;
}
V_228 = V_23 -> V_130 ;
if ( F_26 ( & V_342 -> V_204 , & V_228 -> V_247 ) != 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_407 ,
V_254 ) ;
goto V_268;
}
F_160 ( V_23 , V_408 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_407 , 0 ,
V_342 , sizeof( * V_342 ) ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_173 ( struct V_9 * V_22 , struct V_5 * V_6 ,
struct V_371 * V_342 , T_2 V_322 ,
T_2 V_409 , T_5 V_410 )
{
struct V_129 * V_23 ;
struct V_227 * V_228 ;
int V_27 ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_277 , V_342 ,
sizeof( * V_342 ) ) ;
goto V_411;
}
if ( V_342 -> type == V_343 )
V_228 = F_153 ( V_6 , V_245 , & V_342 -> V_204 ) ;
else
V_228 = F_153 ( V_6 , V_186 , & V_342 -> V_204 ) ;
if ( ! V_228 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_363 , V_342 ,
sizeof( * V_342 ) ) ;
goto V_411;
}
if ( V_342 -> type == V_353 || V_342 -> type == V_366 ) {
V_27 = F_174 ( V_228 , V_322 , V_410 ) ;
if ( ! V_27 )
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_266 , V_342 ,
sizeof( * V_342 ) ) ;
else
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_3 , V_342 ,
sizeof( * V_342 ) ) ;
goto V_411;
}
V_23 = F_79 ( V_22 , V_322 , V_6 , V_342 , sizeof( * V_342 ) ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_411;
}
if ( V_409 == V_412 ) {
struct V_413 V_141 ;
F_76 ( & V_141 . V_204 , & V_342 -> V_204 ) ;
V_141 . V_410 = V_410 ;
V_27 = F_122 ( V_6 , V_409 , sizeof( V_141 ) , & V_141 ) ;
} else
V_27 = F_122 ( V_6 , V_409 , sizeof( V_342 -> V_204 ) ,
& V_342 -> V_204 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_411:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_175 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_375 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_173 ( V_22 , V_6 , & V_141 -> V_342 ,
V_376 ,
V_377 , 0 ) ;
}
static int F_176 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_414 * V_141 = V_7 ;
F_11 ( L_7 ) ;
if ( V_21 != sizeof( * V_141 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_415 ,
V_254 ) ;
return F_173 ( V_22 , V_6 , & V_141 -> V_342 ,
V_415 ,
V_416 , 0 ) ;
}
static int F_177 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_417 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_173 ( V_22 , V_6 , & V_141 -> V_342 ,
V_418 ,
V_419 , 0 ) ;
}
static int F_178 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_420 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_173 ( V_22 , V_6 , & V_141 -> V_342 ,
V_421 ,
V_412 , V_141 -> V_410 ) ;
}
static int F_179 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_422 * V_141 = V_7 ;
F_11 ( L_7 ) ;
return F_173 ( V_22 , V_6 , & V_141 -> V_342 ,
V_423 ,
V_424 , 0 ) ;
}
static void F_180 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_425 V_141 ;
memcpy ( V_141 . V_77 , V_6 -> V_133 , sizeof( V_141 . V_77 ) ) ;
F_49 ( V_139 , V_426 , sizeof( V_141 ) , & V_141 ) ;
}
static void F_181 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_427 * V_141 ;
struct V_129 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_428 , V_6 ) ;
if ( ! V_23 )
goto V_268;
V_141 = V_23 -> V_148 ;
if ( V_24 )
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_428 ,
F_1 ( V_24 ) ) ;
else
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_428 , 0 ,
V_141 , sizeof( * V_141 ) ) ;
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_182 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_427 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_133 , V_141 -> V_77 , sizeof( V_6 -> V_133 ) ) &&
! memcmp ( V_6 -> V_207 , V_141 -> V_207 ,
sizeof( V_6 -> V_207 ) ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_428 , 0 ,
V_7 , V_21 ) ;
goto V_256;
}
memcpy ( V_6 -> V_207 , V_141 -> V_207 , sizeof( V_6 -> V_207 ) ) ;
if ( ! F_40 ( V_6 ) ) {
memcpy ( V_6 -> V_133 , V_141 -> V_77 , sizeof( V_6 -> V_133 ) ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_428 , 0 ,
V_7 , V_21 ) ;
if ( V_27 < 0 )
goto V_256;
V_27 = F_3 ( V_429 , V_6 , V_7 , V_21 ,
V_22 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_428 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
memcpy ( V_6 -> V_133 , V_141 -> V_77 , sizeof( V_6 -> V_133 ) ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_35 ( V_6 ) ) {
F_180 ( & V_139 ) ;
F_57 ( & V_139 ) ;
}
if ( F_38 ( V_6 ) )
F_48 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_181 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_183 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_129 * V_23 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_430 ,
V_277 ) ;
goto V_268;
}
if ( ! F_36 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_430 ,
V_264 ) ;
goto V_268;
}
if ( F_45 ( V_430 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_430 ,
V_255 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_430 , V_6 , NULL , 0 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
if ( F_22 ( V_113 , & V_6 -> V_55 ) )
V_27 = F_122 ( V_6 , V_431 ,
0 , NULL ) ;
else
V_27 = F_122 ( V_6 , V_432 , 0 , NULL ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_184 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
int V_27 ;
F_11 ( L_18 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( V_21 == V_433 ) {
struct V_434 * V_141 = V_7 ;
T_1 V_24 ;
V_27 = F_185 ( V_6 , & V_141 -> V_342 . V_204 ,
V_141 -> V_435 , V_141 -> V_436 ) ;
if ( V_27 < 0 )
V_24 = V_3 ;
else
V_24 = V_266 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_437 ,
V_24 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
} else if ( V_21 == V_438 ) {
struct V_439 * V_141 = V_7 ;
T_1 V_24 ;
V_27 = F_186 ( V_6 , & V_141 -> V_342 . V_204 ,
V_141 -> V_440 ,
V_141 -> V_441 ,
V_141 -> V_442 ,
V_141 -> V_443 ) ;
if ( V_27 < 0 )
V_24 = V_3 ;
else
V_24 = V_266 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_437 ,
V_24 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
} else {
F_143 ( L_19 , V_21 ) ;
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_437 ,
V_254 ) ;
}
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_187 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_444 * V_141 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
V_27 = F_188 ( V_6 , & V_141 -> V_342 . V_204 ) ;
if ( V_27 < 0 )
V_24 = V_254 ;
else
V_24 = V_266 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_445 ,
V_24 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_189 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
T_1 type ;
int V_27 ;
F_97 ( V_6 , V_446 ) ;
V_23 = F_45 ( V_447 , V_6 ) ;
if ( ! V_23 )
return - V_448 ;
type = V_6 -> V_217 . type ;
V_27 = F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_23 -> V_17 , F_1 ( V_24 ) ,
& type , sizeof( type ) ) ;
F_86 ( V_23 ) ;
return V_27 ;
}
static void F_190 ( struct V_5 * V_6 , T_1 V_24 )
{
unsigned long V_276 = 0 ;
F_11 ( L_20 , V_24 ) ;
if ( V_24 ) {
F_32 ( V_6 ) ;
F_189 ( V_6 , V_24 ) ;
F_33 ( V_6 ) ;
return;
}
F_32 ( V_6 ) ;
F_97 ( V_6 , V_219 ) ;
F_33 ( V_6 ) ;
switch ( V_6 -> V_217 . type ) {
case V_449 :
V_276 = F_108 ( V_450 ) ;
break;
case V_451 :
V_276 = F_108 ( V_6 -> V_452 ) ;
break;
case V_453 :
break;
default:
F_143 ( L_21 , V_6 -> V_217 . type ) ;
}
if ( ! V_276 )
return;
F_100 ( V_6 -> V_273 , & V_6 -> V_222 , V_276 ) ;
}
static int F_191 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_454 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_455 V_456 ;
struct V_457 V_458 ;
struct V_459 V_460 ;
struct V_138 V_139 ;
T_1 V_461 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
T_1 V_24 , V_184 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_277 ) ;
goto V_256;
}
if ( F_22 ( V_462 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_255 ) ;
goto V_256;
}
if ( V_6 -> V_217 . V_218 != V_446 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_255 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_447 , V_6 , NULL , 0 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
V_6 -> V_217 . type = V_141 -> type ;
F_54 ( & V_139 , V_6 ) ;
switch ( V_6 -> V_217 . type ) {
case V_453 :
V_24 = F_105 ( V_6 ) ;
if ( V_24 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_24 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
if ( F_22 ( V_220 , & V_6 -> V_153 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_255 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
F_192 ( V_6 ) ;
memset ( & V_460 , 0 , sizeof( V_460 ) ) ;
memcpy ( & V_460 . V_461 , V_461 , sizeof( V_460 . V_461 ) ) ;
V_460 . V_144 = V_463 ;
F_49 ( & V_139 , V_464 , sizeof( V_460 ) , & V_460 ) ;
break;
case V_449 :
case V_451 :
V_24 = F_106 ( V_6 ) ;
if ( V_24 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_24 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
if ( V_6 -> V_217 . type == V_451 &&
! F_22 ( V_107 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_264 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
if ( F_22 ( V_187 , & V_6 -> V_55 ) ) {
if ( F_193 ( V_6 , V_186 ,
V_243 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 ,
V_447 ,
V_265 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
F_62 ( & V_139 ) ;
}
if ( F_22 ( V_226 , & V_6 -> V_55 ) )
F_94 ( & V_139 ) ;
memset ( & V_456 , 0 , sizeof( V_456 ) ) ;
V_27 = F_66 ( & V_139 , true , & V_184 ) ;
if ( V_27 < 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_3 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
V_456 . type = V_465 ;
V_456 . V_289 = F_6 ( V_466 ) ;
V_456 . V_291 = F_6 ( V_467 ) ;
V_456 . V_194 = V_184 ;
F_49 ( & V_139 , V_468 , sizeof( V_456 ) ,
& V_456 ) ;
memset ( & V_458 , 0 , sizeof( V_458 ) ) ;
V_458 . V_181 = V_469 ;
V_458 . V_470 = V_471 ;
F_49 ( & V_139 , V_472 , sizeof( V_458 ) ,
& V_458 ) ;
break;
default:
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_447 ,
V_254 ) ;
F_86 ( V_23 ) ;
goto V_256;
}
V_27 = F_55 ( & V_139 , F_190 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
else
F_97 ( V_6 , V_473 ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_194 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
int V_27 ;
V_23 = F_45 ( V_474 , V_6 ) ;
if ( ! V_23 )
return - V_448 ;
V_27 = F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_23 -> V_17 , F_1 ( V_24 ) ,
& V_6 -> V_217 . type , sizeof( V_6 -> V_217 . type ) ) ;
F_86 ( V_23 ) ;
return V_27 ;
}
static void F_195 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_20 , V_24 ) ;
F_32 ( V_6 ) ;
if ( V_24 ) {
F_194 ( V_6 , V_24 ) ;
goto V_268;
}
F_97 ( V_6 , V_446 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_196 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_475 * V_476 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_197 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_474 ,
V_265 , & V_476 -> type ,
sizeof( V_476 -> type ) ) ;
goto V_268;
}
if ( V_6 -> V_217 . type != V_476 -> type ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_474 ,
V_254 , & V_476 -> type ,
sizeof( V_476 -> type ) ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_474 , V_6 , NULL , 0 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_139 , V_6 ) ;
F_93 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_195 ) ;
if ( ! V_27 ) {
F_97 ( V_6 , V_252 ) ;
goto V_268;
}
F_86 ( V_23 ) ;
if ( V_27 == - V_260 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_474 , 0 ,
& V_476 -> type , sizeof( V_476 -> type ) ) ;
F_97 ( V_6 , V_446 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_198 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_477 * V_141 = V_7 ;
struct V_215 * V_216 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_197 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_478 ,
V_3 , & V_141 -> V_342 ,
sizeof( V_141 -> V_342 ) ) ;
goto V_256;
}
V_216 = F_199 ( V_6 , & V_141 -> V_342 . V_204 ) ;
if ( ! V_216 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_478 ,
V_254 , & V_141 -> V_342 ,
sizeof( V_141 -> V_342 ) ) ;
goto V_256;
}
if ( V_141 -> V_479 ) {
V_216 -> V_480 = V_481 ;
F_87 ( & V_216 -> V_209 ) ;
} else {
V_216 -> V_480 = V_482 ;
F_200 ( V_6 , V_216 ) ;
}
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_478 , 0 , & V_141 -> V_342 ,
sizeof( V_141 -> V_342 ) ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_201 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_483 * V_141 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_148 ( V_141 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_484 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
F_32 ( V_6 ) ;
V_27 = F_202 ( & V_6 -> V_485 , & V_141 -> V_342 . V_204 ,
V_141 -> V_342 . type ) ;
if ( V_27 < 0 ) {
V_24 = V_3 ;
goto V_411;
}
F_3 ( V_486 , V_6 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ,
V_22 ) ;
V_24 = V_266 ;
V_411:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 , V_24 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_203 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_487 * V_141 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_148 ( V_141 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_488 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
F_32 ( V_6 ) ;
V_27 = F_204 ( & V_6 -> V_485 , & V_141 -> V_342 . V_204 ,
V_141 -> V_342 . type ) ;
if ( V_27 < 0 ) {
V_24 = V_254 ;
goto V_411;
}
F_3 ( V_489 , V_6 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ,
V_22 ) ;
V_24 = V_266 ;
V_411:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_488 , V_24 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_205 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_490 * V_141 = V_7 ;
struct V_138 V_139 ;
int V_27 ;
T_9 V_491 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
V_491 = F_110 ( V_141 -> V_491 ) ;
if ( V_491 > 0x0002 )
return F_10 ( V_22 , V_6 -> V_19 , V_492 ,
V_254 ) ;
F_32 ( V_6 ) ;
V_6 -> V_164 = V_491 ;
V_6 -> V_166 = F_110 ( V_141 -> V_493 ) ;
V_6 -> V_167 = F_110 ( V_141 -> V_494 ) ;
V_6 -> V_168 = F_110 ( V_141 -> V_34 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_492 , 0 , NULL , 0 ) ;
F_54 ( & V_139 , V_6 ) ;
F_57 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_206 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 } ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_83 ( V_314 , V_6 ,
F_104 , & V_269 ) ;
return;
}
if ( F_22 ( V_187 , & V_6 -> V_55 ) )
F_71 ( V_112 , & V_6 -> V_55 ) ;
else
F_65 ( V_112 , & V_6 -> V_55 ) ;
F_83 ( V_314 , V_6 , F_103 ,
& V_263 ) ;
F_101 ( V_6 , V_263 . V_22 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
}
static int F_207 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
T_1 V_149 , V_313 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_106 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_314 ,
V_24 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_314 ,
V_254 ) ;
F_32 ( V_6 ) ;
V_149 = ! ! V_141 -> V_149 ;
V_313 = F_22 ( V_112 , & V_6 -> V_55 ) ;
if ( ! F_40 ( V_6 ) || V_149 == V_313 ||
F_64 ( V_6 , V_186 ) > 0 ||
( F_22 ( V_226 , & V_6 -> V_55 ) &&
V_6 -> V_495 == V_465 ) ) {
bool V_267 = false ;
if ( V_149 != F_22 ( V_112 , & V_6 -> V_55 ) ) {
F_111 ( V_112 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_88 ( V_22 , V_314 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_268;
}
if ( F_45 ( V_314 , V_6 ) ||
F_45 ( V_311 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_314 ,
V_255 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_314 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_139 , V_6 ) ;
if ( V_149 )
F_63 ( & V_139 ) ;
else
F_62 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_206 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_208 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_496 * V_141 = V_7 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_497 ,
V_264 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_497 ,
V_265 ) ;
if ( F_26 ( & V_141 -> V_204 , V_70 ) ) {
if ( ! F_26 ( & V_141 -> V_204 , V_498 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_497 ,
V_254 ) ;
if ( ( V_141 -> V_204 . V_499 [ 5 ] & 0xc0 ) != 0xc0 )
return F_10 ( V_22 , V_6 -> V_19 ,
V_497 ,
V_254 ) ;
}
F_32 ( V_6 ) ;
F_76 ( & V_6 -> V_500 , & V_141 -> V_204 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_497 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_209 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_501 * V_141 = V_7 ;
T_9 V_289 , V_291 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_502 ,
V_264 ) ;
V_289 = F_110 ( V_141 -> V_289 ) ;
if ( V_289 < 0x0004 || V_289 > 0x4000 )
return F_10 ( V_22 , V_6 -> V_19 , V_502 ,
V_254 ) ;
V_291 = F_110 ( V_141 -> V_291 ) ;
if ( V_291 < 0x0004 || V_291 > 0x4000 )
return F_10 ( V_22 , V_6 -> V_19 , V_502 ,
V_254 ) ;
if ( V_291 > V_289 )
return F_10 ( V_22 , V_6 -> V_19 , V_502 ,
V_254 ) ;
F_32 ( V_6 ) ;
V_6 -> V_503 = V_289 ;
V_6 -> V_504 = V_291 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_502 , 0 , NULL , 0 ) ;
if ( F_22 ( V_226 , & V_6 -> V_55 ) &&
V_6 -> V_217 . V_218 == V_446 ) {
struct V_138 V_139 ;
F_54 ( & V_139 , V_6 ) ;
F_94 ( & V_139 ) ;
F_210 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
}
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_211 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_505 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_505 ,
F_1 ( V_24 ) ) ;
} else {
struct V_147 * V_141 = V_23 -> V_148 ;
if ( V_141 -> V_149 )
F_71 ( V_104 , & V_6 -> V_55 ) ;
else
F_65 ( V_104 , & V_6 -> V_55 ) ;
F_88 ( V_23 -> V_22 , V_505 , V_6 ) ;
F_101 ( V_6 , V_23 -> V_22 ) ;
}
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_212 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) ||
V_6 -> V_89 < V_90 )
return F_10 ( V_22 , V_6 -> V_19 , V_505 ,
V_264 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_505 ,
V_254 ) ;
if ( ! F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_505 ,
V_277 ) ;
if ( ! F_22 ( V_103 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_505 ,
V_265 ) ;
F_32 ( V_6 ) ;
if ( F_45 ( V_505 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_505 ,
V_255 ) ;
goto V_268;
}
if ( ! ! V_141 -> V_149 == F_22 ( V_104 , & V_6 -> V_55 ) ) {
V_27 = F_88 ( V_22 , V_505 ,
V_6 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_505 , V_6 ,
V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_139 , V_6 ) ;
F_113 ( & V_139 , V_141 -> V_149 ) ;
V_27 = F_55 ( & V_139 , F_211 ) ;
if ( V_27 < 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_505 ,
V_3 ) ;
F_86 ( V_23 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_213 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
T_1 V_232 = 0 ;
F_113 ( V_139 , false ) ;
if ( F_22 ( V_103 , & V_6 -> V_55 ) ||
! F_119 ( & V_6 -> V_299 ) )
V_232 |= V_279 ;
if ( F_22 ( V_105 , & V_6 -> V_55 ) )
V_232 |= V_285 ;
if ( V_232 )
F_49 ( V_139 , V_233 , 1 , & V_232 ) ;
}
static void F_214 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_506 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_65 ( V_107 , & V_6 -> V_55 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_269 ) ;
} else {
F_88 ( V_23 -> V_22 , V_506 , V_6 ) ;
F_101 ( V_6 , V_23 -> V_22 ) ;
}
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_215 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) || ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_506 ,
V_264 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_506 ,
V_265 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_506 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 == F_22 ( V_107 , & V_6 -> V_55 ) ) {
V_27 = F_88 ( V_22 , V_506 , V_6 ) ;
goto V_268;
}
if ( ! F_40 ( V_6 ) ) {
if ( ! V_141 -> V_149 ) {
F_65 ( V_105 , & V_6 -> V_55 ) ;
F_65 ( V_110 , & V_6 -> V_55 ) ;
F_65 ( V_109 , & V_6 -> V_55 ) ;
F_65 ( V_104 , & V_6 -> V_55 ) ;
F_65 ( V_111 , & V_6 -> V_55 ) ;
}
F_111 ( V_107 , & V_6 -> V_55 ) ;
V_27 = F_88 ( V_22 , V_506 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_268;
}
if ( ! V_141 -> V_149 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_506 ,
V_265 ) ;
goto V_268;
}
if ( F_45 ( V_506 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_506 ,
V_255 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_506 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_71 ( V_107 , & V_6 -> V_55 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_103 , & V_6 -> V_55 ) ||
! F_119 ( & V_6 -> V_299 ) )
F_213 ( & V_139 ) ;
F_52 ( & V_139 ) ;
V_27 = F_55 ( & V_139 , F_214 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_216 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
struct V_129 * V_23 ;
T_1 V_149 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_105 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_507 ,
V_24 ) ;
if ( ! F_37 ( V_6 ) &&
! F_22 ( V_96 , & V_6 -> V_97 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_507 ,
V_264 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 && V_141 -> V_149 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_507 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_267 ;
if ( V_141 -> V_149 ) {
V_267 = ! F_73 ( V_113 ,
& V_6 -> V_55 ) ;
if ( V_141 -> V_149 == 0x02 )
F_71 ( V_508 , & V_6 -> V_55 ) ;
else
F_65 ( V_508 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_113 ,
& V_6 -> V_55 ) ;
F_65 ( V_508 , & V_6 -> V_55 ) ;
}
V_27 = F_88 ( V_22 , V_507 , V_6 ) ;
if ( V_27 < 0 )
goto V_256;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
goto V_256;
}
if ( F_45 ( V_507 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_507 ,
V_255 ) ;
goto V_256;
}
V_149 = ! ! V_141 -> V_149 ;
if ( V_149 == F_22 ( V_113 , & V_6 -> V_55 ) &&
( V_141 -> V_149 == 0x02 ) == F_22 ( V_508 , & V_6 -> V_55 ) ) {
V_27 = F_88 ( V_22 , V_507 , V_6 ) ;
goto V_256;
}
V_23 = F_79 ( V_22 , V_507 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_256;
}
V_27 = F_122 ( V_6 , V_509 , 1 , & V_149 ) ;
if ( V_27 < 0 ) {
F_86 ( V_23 ) ;
goto V_256;
}
if ( V_141 -> V_149 == 0x02 )
F_71 ( V_508 , & V_6 -> V_55 ) ;
else
F_65 ( V_508 , & V_6 -> V_55 ) ;
V_256:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_217 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_147 * V_141 = V_7 ;
bool V_267 , V_510 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_141 -> V_149 != 0x00 && V_141 -> V_149 != 0x01 && V_141 -> V_149 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_511 ,
V_254 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_149 )
V_267 = ! F_73 ( V_114 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_114 ,
& V_6 -> V_55 ) ;
if ( V_141 -> V_149 == 0x02 )
V_510 = ! F_73 ( V_308 ,
& V_6 -> V_55 ) ;
else
V_510 = F_69 ( V_308 ,
& V_6 -> V_55 ) ;
if ( F_40 ( V_6 ) && V_510 &&
F_22 ( V_110 , & V_6 -> V_55 ) ) {
T_1 V_512 = ( V_141 -> V_149 == 0x02 ) ? 0x01 : 0x00 ;
F_122 ( V_6 , V_309 ,
sizeof( V_512 ) , & V_512 ) ;
}
V_27 = F_88 ( V_22 , V_511 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_218 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_513 ,
T_2 V_21 )
{
struct V_514 * V_141 = V_513 ;
bool V_267 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_264 ) ;
if ( V_141 -> V_516 != 0x00 && V_141 -> V_516 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_254 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_265 ) ;
F_32 ( V_6 ) ;
F_71 ( V_517 , & V_6 -> V_55 ) ;
if ( V_141 -> V_516 ) {
V_267 = ! F_73 ( V_115 , & V_6 -> V_55 ) ;
memcpy ( V_6 -> V_518 , V_141 -> V_518 , sizeof( V_6 -> V_518 ) ) ;
F_71 ( V_201 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_115 , & V_6 -> V_55 ) ;
memset ( V_6 -> V_518 , 0 , sizeof( V_6 -> V_518 ) ) ;
F_65 ( V_201 , & V_6 -> V_55 ) ;
}
V_27 = F_88 ( V_22 , V_515 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_101 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_219 ( struct V_519 * V_518 )
{
switch ( V_518 -> V_342 . type ) {
case V_353 :
return true ;
case V_366 :
if ( ( V_518 -> V_342 . V_204 . V_499 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_220 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_513 ,
T_2 V_21 )
{
struct V_520 * V_141 = V_513 ;
const T_2 V_521 = ( ( V_334 - sizeof( * V_141 ) ) /
sizeof( struct V_519 ) ) ;
T_2 V_522 , V_337 ;
int V_45 , V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_523 ,
V_264 ) ;
V_522 = F_110 ( V_141 -> V_522 ) ;
if ( V_522 > V_521 ) {
F_143 ( L_22 , V_522 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_523 ,
V_254 ) ;
}
V_337 = sizeof( * V_141 ) + V_522 * sizeof( struct V_519 ) ;
if ( V_337 != V_21 ) {
F_143 ( L_23 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_523 ,
V_254 ) ;
}
F_11 ( L_24 , V_6 -> V_77 , V_522 ) ;
for ( V_45 = 0 ; V_45 < V_522 ; V_45 ++ ) {
struct V_519 * V_340 = & V_141 -> V_524 [ V_45 ] ;
if ( ! F_219 ( V_340 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_523 ,
V_254 ) ;
}
F_32 ( V_6 ) ;
F_221 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_522 ; V_45 ++ ) {
struct V_519 * V_518 = & V_141 -> V_524 [ V_45 ] ;
T_1 V_346 ;
if ( V_518 -> V_342 . type == V_353 )
V_346 = V_354 ;
else
V_346 = V_355 ;
F_222 ( V_6 , & V_518 -> V_342 . V_204 , V_346 , V_518 -> V_149 ,
V_70 ) ;
}
F_71 ( V_517 , & V_6 -> V_55 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_523 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_223 ( struct V_525 * V_340 )
{
if ( V_340 -> V_526 != 0x00 && V_340 -> V_526 != 0x01 )
return false ;
switch ( V_340 -> V_342 . type ) {
case V_353 :
return true ;
case V_366 :
if ( ( V_340 -> V_342 . V_204 . V_499 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_224 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_513 , T_2 V_21 )
{
struct V_527 * V_141 = V_513 ;
const T_2 V_333 = ( ( V_334 - sizeof( * V_141 ) ) /
sizeof( struct V_525 ) ) ;
T_2 V_336 , V_337 ;
int V_45 , V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_528 ,
V_264 ) ;
V_336 = F_110 ( V_141 -> V_336 ) ;
if ( V_336 > V_333 ) {
F_143 ( L_25 , V_336 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_528 ,
V_254 ) ;
}
V_337 = sizeof( * V_141 ) + V_336 *
sizeof( struct V_525 ) ;
if ( V_337 != V_21 ) {
F_143 ( L_26 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_528 ,
V_254 ) ;
}
F_11 ( L_27 , V_6 -> V_77 , V_336 ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_525 * V_340 = & V_141 -> V_341 [ V_45 ] ;
if ( ! F_223 ( V_340 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_528 ,
V_254 ) ;
}
F_32 ( V_6 ) ;
F_225 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_525 * V_340 = & V_141 -> V_341 [ V_45 ] ;
T_1 type , V_346 , V_529 ;
if ( V_340 -> V_342 . type == V_353 )
V_346 = V_354 ;
else
V_346 = V_355 ;
if ( V_340 -> V_526 )
type = V_530 ;
else
type = V_531 ;
switch ( V_340 -> type ) {
case V_532 :
V_529 = 0x00 ;
break;
case V_533 :
V_529 = 0x01 ;
break;
default:
continue;
}
F_226 ( V_6 , & V_340 -> V_342 . V_204 , V_346 , type ,
V_529 , V_340 -> V_149 , V_340 -> V_534 , V_340 -> V_535 ,
V_340 -> rand ) ;
}
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_528 , 0 ,
NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_227 ( struct V_129 * V_23 , void * V_7 )
{
struct V_536 * V_263 = V_7 ;
struct V_537 * V_141 ;
struct V_538 V_29 ;
struct V_227 * V_228 = V_23 -> V_130 ;
if ( V_228 != V_263 -> V_228 )
return;
V_141 = (struct V_537 * ) V_23 -> V_148 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
if ( ! V_263 -> F_1 ) {
V_29 . V_539 = V_228 -> V_539 ;
if ( V_263 -> V_540 ) {
V_29 . V_541 = V_228 -> V_541 ;
V_29 . V_542 = V_228 -> V_542 ;
} else {
V_29 . V_541 = V_157 ;
V_29 . V_542 = V_157 ;
}
}
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_543 ,
V_263 -> F_1 , & V_29 , sizeof( V_29 ) ) ;
F_161 ( V_228 ) ;
F_86 ( V_23 ) ;
}
static void F_228 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_544 * V_141 ;
struct V_227 * V_228 ;
struct V_536 V_263 ;
T_2 V_240 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_263 . V_540 = ! V_24 ;
V_141 = F_229 ( V_6 , V_545 ) ;
if ( ! V_141 ) {
V_141 = F_229 ( V_6 , V_546 ) ;
V_24 = 0 ;
}
if ( ! V_141 ) {
F_143 ( L_28 ) ;
goto V_268;
}
V_240 = F_110 ( V_141 -> V_240 ) ;
V_228 = F_230 ( V_6 , V_240 ) ;
if ( ! V_228 ) {
F_143 ( L_29 , V_240 ) ;
goto V_268;
}
V_263 . V_228 = V_228 ;
V_263 . F_1 = F_1 ( V_24 ) ;
F_83 ( V_543 , V_6 ,
F_227 , & V_263 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_231 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_537 * V_141 = V_7 ;
struct V_538 V_29 ;
struct V_227 * V_228 ;
unsigned long V_547 ;
int V_27 = 0 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
if ( ! F_148 ( V_141 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_543 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_543 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_141 -> V_342 . type == V_343 )
V_228 = F_153 ( V_6 , V_245 ,
& V_141 -> V_342 . V_204 ) ;
else
V_228 = F_153 ( V_6 , V_186 , & V_141 -> V_342 . V_204 ) ;
if ( ! V_228 || V_228 -> V_218 != V_238 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_543 ,
V_363 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
V_547 = V_6 -> V_548 +
F_232 ( V_6 -> V_549 -
V_6 -> V_548 ) ;
if ( F_233 ( V_550 , V_228 -> V_551 +
F_108 ( V_547 ) ) ||
! V_228 -> V_551 ) {
struct V_138 V_139 ;
struct V_552 V_553 ;
struct V_544 V_554 ;
struct V_129 * V_23 ;
F_54 ( & V_139 , V_6 ) ;
V_554 . V_240 = F_6 ( V_228 -> V_240 ) ;
F_49 ( & V_139 , V_545 , sizeof( V_554 ) ,
& V_554 ) ;
if ( ! F_234 ( V_141 -> V_342 . type ) ||
V_228 -> V_541 == V_157 ) {
V_553 . V_240 = F_6 ( V_228 -> V_240 ) ;
V_553 . type = 0x00 ;
F_49 ( & V_139 , V_546 ,
sizeof( V_553 ) , & V_553 ) ;
}
if ( V_228 -> V_542 == V_157 ) {
V_553 . V_240 = F_6 ( V_228 -> V_240 ) ;
V_553 . type = 0x01 ;
F_49 ( & V_139 , V_546 ,
sizeof( V_553 ) , & V_553 ) ;
}
V_27 = F_55 ( & V_139 , F_228 ) ;
if ( V_27 < 0 )
goto V_268;
V_23 = F_79 ( V_22 , V_543 , V_6 ,
V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_235 ( V_228 ) ;
V_23 -> V_130 = V_228 ;
V_228 -> V_551 = V_550 ;
} else {
V_29 . V_539 = V_228 -> V_539 ;
V_29 . V_541 = V_228 -> V_541 ;
V_29 . V_542 = V_228 -> V_542 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_543 ,
V_266 , & V_29 , sizeof( V_29 ) ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_236 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_555 * V_141 ;
struct V_556 V_29 ;
struct V_557 * V_281 ;
struct V_129 * V_23 ;
struct V_227 * V_228 ;
F_11 ( L_30 , V_6 -> V_77 , V_24 ) ;
F_32 ( V_6 ) ;
V_281 = F_229 ( V_6 , V_558 ) ;
if ( ! V_281 )
goto V_268;
if ( V_281 -> V_559 ) {
T_2 V_240 = F_110 ( V_281 -> V_240 ) ;
V_228 = F_230 ( V_6 , V_240 ) ;
} else {
V_228 = NULL ;
}
V_23 = F_46 ( V_560 , V_6 , V_228 ) ;
if ( ! V_23 )
goto V_268;
V_141 = V_23 -> V_148 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memcpy ( & V_29 . V_342 , & V_141 -> V_342 , sizeof( V_29 . V_342 ) ) ;
if ( V_24 )
goto V_561;
V_29 . V_562 = F_28 ( V_6 -> clock ) ;
if ( V_228 ) {
V_29 . V_563 = F_28 ( V_228 -> clock ) ;
V_29 . V_564 = F_6 ( V_228 -> V_565 ) ;
}
V_561:
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , F_1 ( V_24 ) ,
& V_29 , sizeof( V_29 ) ) ;
F_86 ( V_23 ) ;
if ( V_228 )
F_161 ( V_228 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_237 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_555 * V_141 = V_7 ;
struct V_556 V_29 ;
struct V_557 V_281 ;
struct V_129 * V_23 ;
struct V_138 V_139 ;
struct V_227 * V_228 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
if ( V_141 -> V_342 . type != V_343 )
return F_13 ( V_22 , V_6 -> V_19 , V_560 ,
V_254 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_560 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( F_26 ( & V_141 -> V_342 . V_204 , V_70 ) ) {
V_228 = F_153 ( V_6 , V_245 ,
& V_141 -> V_342 . V_204 ) ;
if ( ! V_228 || V_228 -> V_218 != V_238 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_560 ,
V_363 ,
& V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
} else {
V_228 = NULL ;
}
V_23 = F_79 ( V_22 , V_560 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_139 , V_6 ) ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
F_49 ( & V_139 , V_558 , sizeof( V_281 ) , & V_281 ) ;
if ( V_228 ) {
F_235 ( V_228 ) ;
V_23 -> V_130 = V_228 ;
V_281 . V_240 = F_6 ( V_228 -> V_240 ) ;
V_281 . V_559 = 0x01 ;
F_49 ( & V_139 , V_558 , sizeof( V_281 ) , & V_281 ) ;
}
V_27 = F_55 ( & V_139 , F_236 ) ;
if ( V_27 < 0 )
F_86 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_238 ( struct V_5 * V_6 , T_1 V_232 )
{
if ( ! F_22 ( V_107 , & V_6 -> V_55 ) )
return;
if ( ! F_40 ( V_6 ) )
return;
if ( F_22 ( V_103 , & V_6 -> V_55 ) )
return;
if ( F_22 ( V_105 , & V_6 -> V_55 ) )
V_232 |= V_285 ;
F_122 ( V_6 , V_233 , 1 , & V_232 ) ;
}
static void F_239 ( struct V_9 * V_22 , struct V_5 * V_6 ,
T_8 * V_204 , T_1 type , T_1 V_566 )
{
struct V_567 V_26 ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = type ;
V_26 . V_566 = V_566 ;
F_3 ( V_568 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
}
static int F_240 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_569 * V_141 = V_7 ;
T_1 V_570 , V_346 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_148 ( V_141 -> V_342 . type ) ||
! F_26 ( & V_141 -> V_342 . V_204 , V_70 ) )
return F_13 ( V_22 , V_6 -> V_19 , V_571 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
if ( V_141 -> V_566 != 0x00 && V_141 -> V_566 != 0x01 && V_141 -> V_566 != 0x02 )
return F_13 ( V_22 , V_6 -> V_19 , V_571 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_342 . type == V_343 ) {
bool V_572 ;
if ( V_141 -> V_566 != 0x01 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_571 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
V_572 = F_119 ( & V_6 -> V_299 ) ;
V_27 = F_202 ( & V_6 -> V_299 , & V_141 -> V_342 . V_204 ,
V_141 -> V_342 . type ) ;
if ( V_27 )
goto V_268;
if ( V_572 )
F_238 ( V_6 , V_279 ) ;
goto V_573;
}
if ( V_141 -> V_342 . type == V_353 )
V_346 = V_354 ;
else
V_346 = V_355 ;
if ( V_141 -> V_566 == 0x02 )
V_570 = V_574 ;
else if ( V_141 -> V_566 == 0x01 )
V_570 = V_575 ;
else
V_570 = V_576 ;
if ( F_241 ( V_6 , & V_141 -> V_342 . V_204 , V_346 ,
V_570 ) < 0 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_571 ,
V_3 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
V_573:
F_239 ( V_22 , V_6 , & V_141 -> V_342 . V_204 , V_141 -> V_342 . type , V_141 -> V_566 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_571 ,
V_266 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_242 ( struct V_9 * V_22 , struct V_5 * V_6 ,
T_8 * V_204 , T_1 type )
{
struct V_577 V_26 ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = type ;
F_3 ( V_578 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
}
static int F_243 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_579 * V_141 = V_7 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_26 ( & V_141 -> V_342 . V_204 , V_70 ) ) {
struct V_580 * V_581 ;
T_1 V_346 ;
if ( ! F_148 ( V_141 -> V_342 . type ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_582 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
if ( V_141 -> V_342 . type == V_343 ) {
V_27 = F_204 ( & V_6 -> V_299 ,
& V_141 -> V_342 . V_204 ,
V_141 -> V_342 . type ) ;
if ( V_27 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_582 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
if ( F_119 ( & V_6 -> V_299 ) )
F_238 ( V_6 , V_300 ) ;
F_242 ( V_22 , V_6 , & V_141 -> V_342 . V_204 ,
V_141 -> V_342 . type ) ;
goto V_396;
}
if ( V_141 -> V_342 . type == V_353 )
V_346 = V_354 ;
else
V_346 = V_355 ;
V_581 = F_244 ( V_6 , & V_141 -> V_342 . V_204 ,
V_346 ) ;
if ( ! V_581 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_582 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
if ( V_581 -> V_583 == V_584 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_582 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
F_87 ( & V_581 -> V_566 ) ;
F_87 ( & V_581 -> V_209 ) ;
F_18 ( V_581 ) ;
F_116 ( V_6 ) ;
F_242 ( V_22 , V_6 , & V_141 -> V_342 . V_204 , V_141 -> V_342 . type ) ;
} else {
struct V_580 * V_585 , * V_211 ;
struct V_586 * V_499 , * V_587 ;
if ( V_141 -> V_342 . type ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_582 ,
V_254 ,
& V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
goto V_268;
}
F_85 (b, btmp, &hdev->whitelist, list) {
F_242 ( V_22 , V_6 , & V_499 -> V_204 , V_499 -> V_588 ) ;
F_87 ( & V_499 -> V_209 ) ;
F_18 ( V_499 ) ;
}
F_238 ( V_6 , V_300 ) ;
F_85 (p, tmp, &hdev->le_conn_params, list) {
if ( V_585 -> V_583 == V_584 )
continue;
F_242 ( V_22 , V_6 , & V_585 -> V_342 , V_585 -> V_346 ) ;
F_87 ( & V_585 -> V_566 ) ;
F_87 ( & V_585 -> V_209 ) ;
F_18 ( V_585 ) ;
}
F_11 ( L_31 ) ;
F_116 ( V_6 ) ;
}
V_396:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_582 ,
V_266 , & V_141 -> V_342 , sizeof( V_141 -> V_342 ) ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_245 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_589 * V_141 = V_7 ;
const T_2 V_590 = ( ( V_334 - sizeof( * V_141 ) ) /
sizeof( struct V_591 ) ) ;
T_2 V_592 , V_337 ;
int V_45 ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_593 ,
V_264 ) ;
V_592 = F_110 ( V_141 -> V_592 ) ;
if ( V_592 > V_590 ) {
F_143 ( L_32 ,
V_592 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_593 ,
V_254 ) ;
}
V_337 = sizeof( * V_141 ) + V_592 *
sizeof( struct V_591 ) ;
if ( V_337 != V_21 ) {
F_143 ( L_33 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_593 ,
V_254 ) ;
}
F_11 ( L_34 , V_6 -> V_77 , V_592 ) ;
F_32 ( V_6 ) ;
F_246 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_592 ; V_45 ++ ) {
struct V_591 * V_148 = & V_141 -> V_581 [ V_45 ] ;
struct V_580 * V_594 ;
T_2 V_595 , V_596 , V_597 , V_276 ;
T_1 V_346 ;
F_11 ( L_35 , & V_148 -> V_342 . V_204 ,
V_148 -> V_342 . type ) ;
if ( V_148 -> V_342 . type == V_353 ) {
V_346 = V_354 ;
} else if ( V_148 -> V_342 . type == V_366 ) {
V_346 = V_355 ;
} else {
F_143 ( L_36 ) ;
continue;
}
V_595 = F_247 ( V_148 -> V_188 ) ;
V_596 = F_247 ( V_148 -> V_190 ) ;
V_597 = F_247 ( V_148 -> V_597 ) ;
V_276 = F_247 ( V_148 -> V_276 ) ;
F_11 ( L_37 ,
V_595 , V_596 , V_597 , V_276 ) ;
if ( F_248 ( V_595 , V_596 , V_597 , V_276 ) < 0 ) {
F_143 ( L_36 ) ;
continue;
}
V_594 = F_167 ( V_6 , & V_148 -> V_342 . V_204 ,
V_346 ) ;
if ( ! V_594 ) {
F_143 ( L_38 ) ;
continue;
}
V_594 -> V_598 = V_595 ;
V_594 -> V_599 = V_596 ;
V_594 -> V_600 = V_597 ;
V_594 -> V_601 = V_276 ;
}
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_593 , 0 , NULL , 0 ) ;
}
static int F_249 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_602 * V_141 = V_7 ;
bool V_267 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_603 ,
V_265 ) ;
if ( V_141 -> V_604 != 0x00 && V_141 -> V_604 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_603 ,
V_254 ) ;
if ( ! F_22 ( V_66 , & V_6 -> V_61 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_603 ,
V_264 ) ;
F_32 ( V_6 ) ;
if ( V_141 -> V_604 )
V_267 = ! F_73 ( V_67 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_67 ,
& V_6 -> V_55 ) ;
V_27 = F_30 ( V_22 , V_603 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( ! V_267 )
goto V_268;
V_27 = F_29 ( V_6 , V_22 ) ;
if ( F_22 ( V_54 , & V_6 -> V_55 ) == F_25 ( V_6 ) ) {
F_250 ( V_6 ) ;
if ( F_251 ( V_54 , & V_6 -> V_55 ) ) {
F_71 ( V_58 , & V_6 -> V_55 ) ;
F_71 ( V_257 , & V_6 -> V_55 ) ;
F_92 ( V_6 -> V_213 , & V_6 -> V_258 ) ;
} else {
F_71 ( V_605 , & V_6 -> V_153 ) ;
F_252 ( V_6 ) ;
}
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_253 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_606 * V_141 = V_7 ;
bool V_267 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_607 ,
V_265 ) ;
if ( ! F_26 ( & V_141 -> V_204 , V_70 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_607 ,
V_254 ) ;
if ( ! V_6 -> V_79 )
return F_10 ( V_22 , V_6 -> V_19 , V_607 ,
V_264 ) ;
F_32 ( V_6 ) ;
V_267 = ! ! F_26 ( & V_6 -> V_69 , & V_141 -> V_204 ) ;
F_76 ( & V_6 -> V_69 , & V_141 -> V_204 ) ;
V_27 = F_30 ( V_22 , V_607 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( ! V_267 )
goto V_268;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
V_27 = F_29 ( V_6 , V_22 ) ;
if ( F_25 ( V_6 ) ) {
F_250 ( V_6 ) ;
F_65 ( V_54 , & V_6 -> V_55 ) ;
F_71 ( V_58 , & V_6 -> V_55 ) ;
F_71 ( V_257 , & V_6 -> V_55 ) ;
F_92 ( V_6 -> V_213 , & V_6 -> V_258 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
int F_254 ( struct V_9 * V_22 , struct V_608 * V_609 , T_3 V_610 )
{
void * V_611 ;
T_1 * V_141 ;
struct V_13 * V_14 ;
T_2 V_17 , V_18 , V_21 ;
struct V_5 * V_6 = NULL ;
const struct V_612 * V_613 ;
int V_27 ;
F_11 ( L_39 , V_610 ) ;
if ( V_610 < sizeof( * V_14 ) )
return - V_614 ;
V_611 = F_16 ( V_610 , V_15 ) ;
if ( ! V_611 )
return - V_16 ;
if ( F_255 ( V_611 , V_609 -> V_615 , V_610 ) ) {
V_27 = - V_616 ;
goto V_411;
}
V_14 = V_611 ;
V_17 = F_110 ( V_14 -> V_17 ) ;
V_18 = F_110 ( V_14 -> V_18 ) ;
V_21 = F_110 ( V_14 -> V_21 ) ;
if ( V_21 != V_610 - sizeof( * V_14 ) ) {
V_27 = - V_614 ;
goto V_411;
}
if ( V_18 != V_20 ) {
V_6 = F_256 ( V_18 ) ;
if ( ! V_6 ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_617 ) ;
goto V_411;
}
if ( F_22 ( V_57 , & V_6 -> V_55 ) ||
F_22 ( V_58 , & V_6 -> V_55 ) ||
F_22 ( V_59 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_617 ) ;
goto V_411;
}
if ( F_22 ( V_54 , & V_6 -> V_55 ) &&
V_17 != V_82 &&
V_17 != V_603 &&
V_17 != V_607 ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_617 ) ;
goto V_411;
}
}
if ( V_17 >= F_2 ( V_618 ) ||
V_618 [ V_17 ] . V_619 == NULL ) {
F_11 ( L_40 , V_17 ) ;
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_620 ) ;
goto V_411;
}
if ( V_6 && ( V_17 <= V_63 ||
V_17 == V_65 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_617 ) ;
goto V_411;
}
if ( ! V_6 && ( V_17 > V_63 &&
V_17 != V_65 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_617 ) ;
goto V_411;
}
V_613 = & V_618 [ V_17 ] ;
if ( ( V_613 -> V_621 && V_21 < V_613 -> V_8 ) ||
( ! V_613 -> V_621 && V_21 != V_613 -> V_8 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_254 ) ;
goto V_411;
}
if ( V_6 )
F_72 ( V_22 , V_6 ) ;
V_141 = V_611 + sizeof( * V_14 ) ;
V_27 = V_613 -> V_619 ( V_22 , V_6 , V_141 , V_21 ) ;
if ( V_27 < 0 )
goto V_411;
V_27 = V_610 ;
V_411:
if ( V_6 )
F_257 ( V_6 ) ;
F_18 ( V_611 ) ;
return V_27 ;
}
void F_252 ( struct V_5 * V_6 )
{
if ( V_6 -> V_52 != V_53 )
return;
if ( F_22 ( V_60 , & V_6 -> V_61 ) )
return;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
F_3 ( V_622 , V_6 , NULL , 0 , NULL ) ;
else
F_3 ( V_623 , V_6 , NULL , 0 , NULL ) ;
}
void F_250 ( struct V_5 * V_6 )
{
T_1 V_24 = V_617 ;
if ( V_6 -> V_52 != V_53 )
return;
if ( F_22 ( V_60 , & V_6 -> V_61 ) )
return;
F_83 ( 0 , V_6 , F_104 , & V_24 ) ;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
F_3 ( V_624 , V_6 , NULL , 0 , NULL ) ;
else
F_3 ( V_625 , V_6 , NULL , 0 , NULL ) ;
}
static void F_258 ( struct V_5 * V_6 )
{
struct V_580 * V_585 ;
F_21 (p, &hdev->le_conn_params, list) {
F_259 ( & V_585 -> V_566 ) ;
switch ( V_585 -> V_583 ) {
case V_575 :
case V_574 :
F_82 ( & V_585 -> V_566 , & V_6 -> V_626 ) ;
break;
case V_576 :
F_82 ( & V_585 -> V_566 , & V_6 -> V_627 ) ;
break;
default:
break;
}
}
F_116 ( V_6 ) ;
}
static void F_260 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 } ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
F_258 ( V_6 ) ;
F_83 ( V_253 , V_6 , F_103 , & V_263 ) ;
F_101 ( V_6 , V_263 . V_22 ) ;
F_33 ( V_6 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
}
static int F_261 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
T_1 V_628 ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) &&
! F_262 ( V_6 ) ) {
T_1 V_629 = 1 ;
F_49 ( & V_139 , V_310 , 1 , & V_629 ) ;
}
if ( F_22 ( V_108 , & V_6 -> V_55 ) &&
F_35 ( V_6 ) ) {
struct V_312 V_141 ;
V_141 . V_315 = 0x01 ;
V_141 . V_316 = 0x00 ;
if ( V_141 . V_315 != F_127 ( V_6 ) ||
V_141 . V_316 != F_263 ( V_6 ) )
F_49 ( & V_139 , V_317 ,
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
V_628 = F_22 ( V_109 , & V_6 -> V_55 ) ;
if ( V_628 != F_22 ( V_304 , & V_6 -> V_153 ) )
F_49 ( & V_139 , V_305 ,
sizeof( V_628 ) , & V_628 ) ;
if ( F_35 ( V_6 ) ) {
if ( F_22 ( V_107 , & V_6 -> V_55 ) )
F_213 ( & V_139 ) ;
F_60 ( & V_139 ) ;
F_180 ( & V_139 ) ;
F_57 ( & V_139 ) ;
}
return F_55 ( & V_139 , F_260 ) ;
}
int F_99 ( struct V_5 * V_6 , T_1 V_630 )
{
struct V_262 V_263 = { NULL , V_6 } ;
T_1 V_631 = V_277 ;
T_1 V_632 [] = { 0 , 0 , 0 } ;
int V_27 ;
if ( ! F_22 ( V_202 , & V_6 -> V_55 ) )
return 0 ;
if ( V_630 ) {
if ( F_261 ( V_6 ) == 0 )
return 0 ;
F_83 ( V_253 , V_6 , F_103 ,
& V_263 ) ;
goto F_101;
}
F_83 ( V_253 , V_6 , F_103 , & V_263 ) ;
F_83 ( 0 , V_6 , F_104 , & V_631 ) ;
if ( memcmp ( V_6 -> V_178 , V_632 , sizeof( V_632 ) ) != 0 )
F_3 ( V_633 , V_6 ,
V_632 , sizeof( V_632 ) , NULL ) ;
F_101:
V_27 = F_101 ( V_6 , V_263 . V_22 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
return V_27 ;
}
void F_264 ( struct V_5 * V_6 , int V_27 )
{
struct V_129 * V_23 ;
T_1 V_24 ;
V_23 = F_45 ( V_253 , V_6 ) ;
if ( ! V_23 )
return;
if ( V_27 == - V_634 )
V_24 = V_635 ;
else
V_24 = V_3 ;
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_253 , V_24 ) ;
F_86 ( V_23 ) ;
}
void F_265 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
F_32 ( V_6 ) ;
F_65 ( V_152 , & V_6 -> V_55 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_107 , & V_6 -> V_55 ) ) {
T_1 V_232 = V_279 ;
F_49 ( & V_139 , V_233 ,
sizeof( V_232 ) , & V_232 ) ;
}
F_60 ( & V_139 ) ;
F_52 ( & V_139 ) ;
F_55 ( & V_139 , NULL ) ;
V_6 -> V_271 = 0 ;
F_101 ( V_6 , NULL ) ;
F_33 ( V_6 ) ;
}
void F_266 ( struct V_5 * V_6 , struct V_636 * V_340 ,
bool V_637 )
{
struct V_638 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_639 = V_637 ;
F_76 ( & V_26 . V_340 . V_342 . V_204 , & V_340 -> V_204 ) ;
V_26 . V_340 . V_342 . type = V_343 ;
V_26 . V_340 . type = V_340 -> type ;
memcpy ( V_26 . V_340 . V_149 , V_340 -> V_149 , V_640 ) ;
V_26 . V_340 . V_345 = V_340 -> V_345 ;
F_3 ( V_641 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static T_1 F_267 ( struct V_642 * V_643 )
{
if ( V_643 -> V_529 )
return V_533 ;
return V_532 ;
}
void F_268 ( struct V_5 * V_6 , struct V_642 * V_340 , bool V_637 )
{
struct V_644 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_340 -> V_588 == V_355 &&
( V_340 -> V_204 . V_499 [ 5 ] & 0xc0 ) != 0xc0 )
V_26 . V_639 = 0x00 ;
else
V_26 . V_639 = V_637 ;
F_76 ( & V_26 . V_340 . V_342 . V_204 , & V_340 -> V_204 ) ;
V_26 . V_340 . V_342 . type = F_154 ( V_186 , V_340 -> V_588 ) ;
V_26 . V_340 . type = F_267 ( V_340 ) ;
V_26 . V_340 . V_534 = V_340 -> V_534 ;
V_26 . V_340 . V_535 = V_340 -> V_535 ;
V_26 . V_340 . rand = V_340 -> rand ;
if ( V_340 -> type == V_530 )
V_26 . V_340 . V_526 = 1 ;
memcpy ( V_26 . V_340 . V_149 , V_340 -> V_149 , sizeof( V_340 -> V_149 ) ) ;
F_3 ( V_645 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_269 ( struct V_5 * V_6 , struct V_646 * V_518 )
{
struct V_647 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_26 ( & V_518 -> V_648 , V_70 ) )
V_26 . V_639 = 0x01 ;
else
V_26 . V_639 = 0x00 ;
F_76 ( & V_26 . V_648 , & V_518 -> V_648 ) ;
F_76 ( & V_26 . V_518 . V_342 . V_204 , & V_518 -> V_204 ) ;
V_26 . V_518 . V_342 . type = F_154 ( V_186 , V_518 -> V_346 ) ;
memcpy ( V_26 . V_518 . V_149 , V_518 -> V_149 , sizeof( V_518 -> V_149 ) ) ;
F_3 ( V_649 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_270 ( struct V_5 * V_6 , struct V_650 * V_651 ,
bool V_637 )
{
struct V_652 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_651 -> V_588 == V_355 &&
( V_651 -> V_204 . V_499 [ 5 ] & 0xc0 ) != 0xc0 )
V_26 . V_639 = 0x00 ;
else
V_26 . V_639 = V_637 ;
F_76 ( & V_26 . V_340 . V_342 . V_204 , & V_651 -> V_204 ) ;
V_26 . V_340 . V_342 . type = F_154 ( V_186 , V_651 -> V_588 ) ;
V_26 . V_340 . V_526 = V_651 -> V_526 ;
memcpy ( V_26 . V_340 . V_149 , V_651 -> V_149 , sizeof( V_651 -> V_149 ) ) ;
F_3 ( V_653 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_271 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_588 , T_1 V_639 , T_2 V_188 ,
T_2 V_190 , T_2 V_597 , T_2 V_276 )
{
struct V_654 V_26 ;
if ( ! F_272 ( V_204 , V_588 ) )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_186 , V_588 ) ;
V_26 . V_639 = V_639 ;
V_26 . V_188 = F_6 ( V_188 ) ;
V_26 . V_190 = F_6 ( V_190 ) ;
V_26 . V_597 = F_6 ( V_597 ) ;
V_26 . V_276 = F_6 ( V_276 ) ;
F_3 ( V_655 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static inline T_2 F_273 ( T_1 * V_172 , T_2 V_656 , T_1 type , T_1 * V_7 ,
T_1 V_8 )
{
V_172 [ V_656 ++ ] = sizeof( type ) + V_8 ;
V_172 [ V_656 ++ ] = type ;
memcpy ( & V_172 [ V_656 ] , V_7 , V_8 ) ;
V_656 += V_8 ;
return V_656 ;
}
void F_274 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_365 ,
T_1 V_346 , T_6 V_153 , T_1 * V_77 , T_1 V_132 ,
T_1 * V_178 )
{
char V_611 [ 512 ] ;
struct V_657 * V_26 = ( void * ) V_611 ;
T_2 V_656 = 0 ;
F_76 ( & V_26 -> V_342 . V_204 , V_204 ) ;
V_26 -> V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 -> V_153 = F_275 ( V_153 ) ;
if ( V_132 > 0 )
V_656 = F_273 ( V_26 -> V_172 , 0 , V_137 ,
V_77 , V_132 ) ;
if ( V_178 && memcmp ( V_178 , L_41 , 3 ) != 0 )
V_656 = F_273 ( V_26 -> V_172 , V_656 ,
V_658 , V_178 , 3 ) ;
V_26 -> V_656 = F_6 ( V_656 ) ;
F_3 ( V_659 , V_6 , V_611 ,
sizeof( * V_26 ) + V_656 , NULL ) ;
}
static void F_276 ( struct V_129 * V_23 , void * V_7 )
{
struct V_357 * V_141 = V_23 -> V_148 ;
struct V_9 * * V_22 = V_7 ;
struct V_358 V_29 ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_359 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
* V_22 = V_23 -> V_22 ;
F_81 ( * V_22 ) ;
F_86 ( V_23 ) ;
}
static void F_277 ( struct V_129 * V_23 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_349 * V_141 = V_23 -> V_148 ;
struct V_350 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_204 , & V_141 -> V_342 . V_204 ) ;
V_29 . V_342 . type = V_141 -> V_342 . type ;
F_146 ( V_6 , & V_141 -> V_342 . V_204 , V_141 -> V_342 . type , V_23 -> V_22 ) ;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , 0 , & V_29 , sizeof( V_29 ) ) ;
F_86 ( V_23 ) ;
}
void F_278 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_241 ,
bool V_660 )
{
struct V_661 V_26 ;
struct V_129 * V_212 ;
struct V_9 * V_22 = NULL ;
V_212 = F_45 ( V_253 , V_6 ) ;
if ( V_212 ) {
struct V_147 * V_141 = V_212 -> V_148 ;
if ( ! V_141 -> V_149 && F_90 ( V_6 ) == 1 ) {
F_91 ( & V_6 -> V_212 ) ;
F_92 ( V_6 -> V_213 , & V_6 -> V_212 . V_199 ) ;
}
}
if ( ! V_660 )
return;
if ( V_365 != V_245 && V_365 != V_186 )
return;
F_83 ( V_359 , V_6 , F_276 , & V_22 ) ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 . V_241 = V_241 ;
F_3 ( V_662 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
if ( V_22 )
F_78 ( V_22 ) ;
F_83 ( V_351 , V_6 , F_277 ,
V_6 ) ;
}
void F_279 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_24 )
{
T_1 V_588 = F_154 ( V_365 , V_346 ) ;
struct V_357 * V_141 ;
struct V_358 V_29 ;
struct V_129 * V_23 ;
F_83 ( V_351 , V_6 , F_277 ,
V_6 ) ;
V_23 = F_45 ( V_359 , V_6 ) ;
if ( ! V_23 )
return;
V_141 = V_23 -> V_148 ;
if ( F_26 ( V_204 , & V_141 -> V_342 . V_204 ) )
return;
if ( V_141 -> V_342 . type != V_588 )
return;
F_76 ( & V_29 . V_342 . V_204 , V_204 ) ;
V_29 . V_342 . type = V_588 ;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_359 ,
F_1 ( V_24 ) , & V_29 , sizeof( V_29 ) ) ;
F_86 ( V_23 ) ;
}
void F_280 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_365 ,
T_1 V_346 , T_1 V_24 )
{
struct V_663 V_26 ;
struct V_129 * V_212 ;
V_212 = F_45 ( V_253 , V_6 ) ;
if ( V_212 ) {
struct V_147 * V_141 = V_212 -> V_148 ;
if ( ! V_141 -> V_149 && F_90 ( V_6 ) == 1 ) {
F_91 ( & V_6 -> V_212 ) ;
F_92 ( V_6 -> V_213 , & V_6 -> V_212 . V_199 ) ;
}
}
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 . V_24 = F_1 ( V_24 ) ;
F_3 ( V_664 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_281 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_665 )
{
struct V_666 V_26 ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = V_343 ;
V_26 . V_665 = V_665 ;
F_3 ( V_667 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_282 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_24 )
{
struct V_129 * V_23 ;
struct V_668 V_29 ;
V_23 = F_45 ( V_381 , V_6 ) ;
if ( ! V_23 )
return;
F_76 ( & V_29 . V_342 . V_204 , V_204 ) ;
V_29 . V_342 . type = V_343 ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_381 ,
F_1 ( V_24 ) , & V_29 , sizeof( V_29 ) ) ;
F_86 ( V_23 ) ;
}
void F_283 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_24 )
{
struct V_129 * V_23 ;
struct V_668 V_29 ;
V_23 = F_45 ( V_376 , V_6 ) ;
if ( ! V_23 )
return;
F_76 ( & V_29 . V_342 . V_204 , V_204 ) ;
V_29 . V_342 . type = V_343 ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_376 ,
F_1 ( V_24 ) , & V_29 , sizeof( V_29 ) ) ;
F_86 ( V_23 ) ;
}
int F_284 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_6 V_669 ,
T_1 V_670 )
{
struct V_671 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 . V_670 = V_670 ;
V_26 . V_669 = F_28 ( V_669 ) ;
return F_3 ( V_672 , V_6 , & V_26 , sizeof( V_26 ) ,
NULL ) ;
}
int F_285 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 )
{
struct V_673 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_365 , V_346 ) ;
return F_3 ( V_674 , V_6 , & V_26 , sizeof( V_26 ) ,
NULL ) ;
}
static int F_286 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_24 ,
T_1 V_17 )
{
struct V_129 * V_23 ;
struct V_675 V_29 ;
int V_27 ;
V_23 = F_45 ( V_17 , V_6 ) ;
if ( ! V_23 )
return - V_448 ;
F_76 ( & V_29 . V_342 . V_204 , V_204 ) ;
V_29 . V_342 . type = F_154 ( V_365 , V_346 ) ;
V_27 = F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_17 , F_1 ( V_24 ) ,
& V_29 , sizeof( V_29 ) ) ;
F_86 ( V_23 ) ;
return V_27 ;
}
int F_287 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_24 )
{
return F_286 ( V_6 , V_204 , V_365 , V_346 ,
V_24 , V_415 ) ;
}
int F_288 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_24 )
{
return F_286 ( V_6 , V_204 , V_365 , V_346 ,
V_24 ,
V_418 ) ;
}
int F_289 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_24 )
{
return F_286 ( V_6 , V_204 , V_365 , V_346 ,
V_24 , V_421 ) ;
}
int F_290 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_1 V_24 )
{
return F_286 ( V_6 , V_204 , V_365 , V_346 ,
V_24 ,
V_423 ) ;
}
int F_291 ( struct V_5 * V_6 , T_8 * V_204 ,
T_1 V_365 , T_1 V_346 , T_6 V_410 ,
T_1 V_676 )
{
struct V_677 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 . V_410 = F_275 ( V_410 ) ;
V_26 . V_676 = V_676 ;
return F_3 ( V_678 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_292 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_365 ,
T_1 V_346 , T_1 V_24 )
{
struct V_679 V_26 ;
F_76 ( & V_26 . V_342 . V_204 , V_204 ) ;
V_26 . V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 . V_24 = F_1 ( V_24 ) ;
F_3 ( V_680 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_293 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 } ;
bool V_267 ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_83 ( V_303 , V_6 ,
F_104 , & V_269 ) ;
return;
}
if ( F_22 ( V_304 , & V_6 -> V_153 ) )
V_267 = ! F_73 ( V_109 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_109 ,
& V_6 -> V_55 ) ;
F_83 ( V_303 , V_6 , F_103 ,
& V_263 ) ;
if ( V_267 )
F_101 ( V_6 , V_263 . V_22 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
}
static void F_294 ( struct V_138 * V_139 )
{
struct V_5 * V_6 = V_139 -> V_6 ;
struct V_170 V_141 ;
if ( ! F_58 ( V_6 ) )
return;
memset ( V_6 -> V_172 , 0 , sizeof( V_6 -> V_172 ) ) ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
F_49 ( V_139 , V_173 , sizeof( V_141 ) , & V_141 ) ;
}
void F_295 ( struct V_5 * V_6 , T_1 V_181 , T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 } ;
struct V_138 V_139 ;
bool V_267 = false ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
if ( V_181 && F_69 ( V_110 ,
& V_6 -> V_55 ) ) {
F_65 ( V_111 , & V_6 -> V_55 ) ;
F_101 ( V_6 , NULL ) ;
}
F_83 ( V_306 , V_6 , F_104 ,
& V_269 ) ;
return;
}
if ( V_181 ) {
V_267 = ! F_73 ( V_110 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_110 , & V_6 -> V_55 ) ;
if ( ! V_267 )
V_267 = F_69 ( V_111 ,
& V_6 -> V_55 ) ;
else
F_65 ( V_111 , & V_6 -> V_55 ) ;
}
F_83 ( V_306 , V_6 , F_103 , & V_263 ) ;
if ( V_267 )
F_101 ( V_6 , V_263 . V_22 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
F_54 ( & V_139 , V_6 ) ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) ) {
if ( F_22 ( V_308 , & V_6 -> V_55 ) )
F_49 ( & V_139 , V_309 ,
sizeof( V_181 ) , & V_181 ) ;
F_57 ( & V_139 ) ;
} else {
F_294 ( & V_139 ) ;
}
F_55 ( & V_139 , NULL ) ;
}
void F_296 ( struct V_5 * V_6 , T_1 V_181 , T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 } ;
bool V_267 = false ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
if ( V_181 ) {
if ( F_69 ( V_113 ,
& V_6 -> V_55 ) )
F_101 ( V_6 , NULL ) ;
F_65 ( V_508 , & V_6 -> V_55 ) ;
}
F_83 ( V_507 , V_6 ,
F_104 , & V_269 ) ;
return;
}
if ( V_181 ) {
V_267 = ! F_73 ( V_113 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_113 , & V_6 -> V_55 ) ;
F_65 ( V_508 , & V_6 -> V_55 ) ;
}
F_83 ( V_507 , V_6 ,
F_103 , & V_263 ) ;
if ( V_267 )
F_101 ( V_6 , V_263 . V_22 ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
}
static void F_297 ( struct V_129 * V_23 , void * V_7 )
{
struct V_262 * V_263 = V_7 ;
if ( V_263 -> V_22 == NULL ) {
V_263 -> V_22 = V_23 -> V_22 ;
F_81 ( V_263 -> V_22 ) ;
}
}
void F_298 ( struct V_5 * V_6 , T_1 * V_178 ,
T_1 V_24 )
{
struct V_262 V_263 = { NULL , V_6 , F_1 (status) } ;
F_83 ( V_320 , V_6 , F_297 , & V_263 ) ;
F_83 ( V_318 , V_6 , F_297 , & V_263 ) ;
F_83 ( V_319 , V_6 , F_297 , & V_263 ) ;
if ( ! V_24 )
F_3 ( V_633 , V_6 , V_178 , 3 ,
NULL ) ;
if ( V_263 . V_22 )
F_78 ( V_263 . V_22 ) ;
}
void F_299 ( struct V_5 * V_6 , T_1 * V_77 , T_1 V_24 )
{
struct V_427 V_26 ;
struct V_129 * V_23 ;
if ( V_24 )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
memcpy ( V_26 . V_77 , V_77 , V_681 ) ;
memcpy ( V_26 . V_207 , V_6 -> V_207 , V_682 ) ;
V_23 = F_45 ( V_428 , V_6 ) ;
if ( ! V_23 ) {
memcpy ( V_6 -> V_133 , V_77 , sizeof( V_6 -> V_133 ) ) ;
if ( F_45 ( V_253 , V_6 ) )
return;
}
F_3 ( V_429 , V_6 , & V_26 , sizeof( V_26 ) ,
V_23 ? V_23 -> V_22 : NULL ) ;
}
void F_300 ( struct V_5 * V_6 , T_1 * V_440 ,
T_1 * V_441 , T_1 * V_442 ,
T_1 * V_443 , T_1 V_24 )
{
struct V_129 * V_23 ;
F_11 ( L_30 , V_6 -> V_77 , V_24 ) ;
V_23 = F_45 ( V_430 , V_6 ) ;
if ( ! V_23 )
return;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_430 ,
F_1 ( V_24 ) ) ;
} else {
if ( F_22 ( V_113 , & V_6 -> V_55 ) &&
V_442 && V_443 ) {
struct V_683 V_29 ;
memcpy ( V_29 . V_440 , V_440 , sizeof( V_29 . V_440 ) ) ;
memcpy ( V_29 . V_441 , V_441 ,
sizeof( V_29 . V_441 ) ) ;
memcpy ( V_29 . V_442 , V_442 , sizeof( V_29 . V_442 ) ) ;
memcpy ( V_29 . V_443 , V_443 ,
sizeof( V_29 . V_443 ) ) ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 ,
V_430 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
} else {
struct V_684 V_29 ;
memcpy ( V_29 . V_435 , V_440 , sizeof( V_29 . V_435 ) ) ;
memcpy ( V_29 . V_436 , V_441 ,
sizeof( V_29 . V_436 ) ) ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 ,
V_430 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
}
}
F_86 ( V_23 ) ;
}
void F_301 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_365 ,
T_1 V_346 , T_1 * V_178 , T_10 V_539 , T_6 V_153 ,
T_1 * V_172 , T_2 V_656 , T_1 * V_685 , T_1 V_686 )
{
char V_611 [ 512 ] ;
struct V_687 * V_26 = ( void * ) V_611 ;
T_3 V_688 ;
if ( ! F_197 ( V_6 ) ) {
if ( V_365 == V_245 )
return;
if ( V_365 == V_186 && F_119 ( & V_6 -> V_627 ) )
return;
}
if ( sizeof( * V_26 ) + V_656 + V_686 + 5 > sizeof( V_611 ) )
return;
memset ( V_611 , 0 , sizeof( V_611 ) ) ;
F_76 ( & V_26 -> V_342 . V_204 , V_204 ) ;
V_26 -> V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 -> V_539 = V_539 ;
V_26 -> V_153 = F_28 ( V_153 ) ;
if ( V_656 > 0 )
memcpy ( V_26 -> V_172 , V_172 , V_656 ) ;
if ( V_178 && ! F_302 ( V_26 -> V_172 , V_656 , V_658 ) )
V_656 = F_273 ( V_26 -> V_172 , V_656 , V_658 ,
V_178 , 3 ) ;
if ( V_686 > 0 )
memcpy ( V_26 -> V_172 + V_656 , V_685 , V_686 ) ;
V_26 -> V_656 = F_6 ( V_656 + V_686 ) ;
V_688 = sizeof( * V_26 ) + V_656 + V_686 ;
F_3 ( V_689 , V_6 , V_26 , V_688 , NULL ) ;
}
void F_303 ( struct V_5 * V_6 , T_8 * V_204 , T_1 V_365 ,
T_1 V_346 , T_10 V_539 , T_1 * V_77 , T_1 V_132 )
{
struct V_687 * V_26 ;
char V_611 [ sizeof( * V_26 ) + V_681 + 2 ] ;
T_2 V_656 ;
V_26 = (struct V_687 * ) V_611 ;
memset ( V_611 , 0 , sizeof( V_611 ) ) ;
F_76 ( & V_26 -> V_342 . V_204 , V_204 ) ;
V_26 -> V_342 . type = F_154 ( V_365 , V_346 ) ;
V_26 -> V_539 = V_539 ;
V_656 = F_273 ( V_26 -> V_172 , 0 , V_137 , V_77 ,
V_132 ) ;
V_26 -> V_656 = F_6 ( V_656 ) ;
F_3 ( V_689 , V_6 , V_26 , sizeof( * V_26 ) + V_656 , NULL ) ;
}
void F_304 ( struct V_5 * V_6 , T_1 V_690 )
{
struct V_691 V_26 ;
struct V_129 * V_23 ;
F_11 ( L_42 , V_6 -> V_77 , V_690 ) ;
if ( V_690 )
V_23 = F_45 ( V_447 , V_6 ) ;
else
V_23 = F_45 ( V_474 , V_6 ) ;
if ( V_23 != NULL ) {
T_1 type = V_6 -> V_217 . type ;
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_23 -> V_17 , 0 , & type ,
sizeof( type ) ) ;
F_86 ( V_23 ) ;
}
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . type = V_6 -> V_217 . type ;
V_26 . V_690 = V_690 ;
F_3 ( V_692 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static void F_305 ( struct V_5 * V_6 , T_1 V_24 )
{
F_11 ( L_30 , V_6 -> V_77 , V_24 ) ;
}
void F_306 ( struct V_5 * V_6 )
{
struct V_138 V_139 ;
if ( ! F_22 ( V_112 , & V_6 -> V_55 ) )
return;
F_54 ( & V_139 , V_6 ) ;
F_63 ( & V_139 ) ;
F_55 ( & V_139 , F_305 ) ;
}
