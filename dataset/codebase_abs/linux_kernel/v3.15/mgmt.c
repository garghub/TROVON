static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 < F_2 ( V_2 ) )
return V_2 [ V_1 ] ;
return V_3 ;
}
static int F_3 ( struct V_4 * V_5 , T_2 V_6 , T_2 V_7 , T_1 V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
F_4 ( L_1 , V_5 , V_6 , V_7 , V_8 ) ;
V_10 = F_5 ( sizeof( * V_12 ) + sizeof( * V_14 ) , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_19 ) ;
V_12 -> V_6 = F_7 ( V_6 ) ;
V_12 -> V_20 = F_7 ( sizeof( * V_14 ) ) ;
V_14 = ( void * ) F_6 ( V_10 , sizeof( * V_14 ) ) ;
V_14 -> V_8 = V_8 ;
V_14 -> V_18 = F_7 ( V_7 ) ;
V_15 = F_8 ( V_5 , V_10 ) ;
if ( V_15 < 0 )
F_9 ( V_10 ) ;
return V_15 ;
}
static int F_10 ( struct V_4 * V_5 , T_2 V_6 , T_2 V_7 , T_1 V_8 ,
void * V_21 , T_3 V_22 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_23 * V_14 ;
int V_15 ;
F_4 ( L_2 , V_5 ) ;
V_10 = F_5 ( sizeof( * V_12 ) + sizeof( * V_14 ) + V_22 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_24 ) ;
V_12 -> V_6 = F_7 ( V_6 ) ;
V_12 -> V_20 = F_7 ( sizeof( * V_14 ) + V_22 ) ;
V_14 = ( void * ) F_6 ( V_10 , sizeof( * V_14 ) + V_22 ) ;
V_14 -> V_18 = F_7 ( V_7 ) ;
V_14 -> V_8 = V_8 ;
if ( V_21 )
memcpy ( V_14 -> V_25 , V_21 , V_22 ) ;
V_15 = F_8 ( V_5 , V_10 ) ;
if ( V_15 < 0 )
F_9 ( V_10 ) ;
return V_15 ;
}
static int F_11 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_29 V_21 ;
F_4 ( L_2 , V_5 ) ;
V_21 . V_30 = V_31 ;
V_21 . V_32 = F_7 ( V_33 ) ;
return F_10 ( V_5 , V_34 , V_35 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static int F_12 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_36 * V_21 ;
const T_2 V_37 = F_2 ( V_38 ) ;
const T_2 V_39 = F_2 ( V_40 ) ;
T_4 * V_18 ;
T_3 V_41 ;
int V_42 , V_15 ;
F_4 ( L_2 , V_5 ) ;
V_41 = sizeof( * V_21 ) + ( ( V_37 + V_39 ) * sizeof( T_2 ) ) ;
V_21 = F_13 ( V_41 , V_16 ) ;
if ( ! V_21 )
return - V_17 ;
V_21 -> V_37 = F_7 ( V_37 ) ;
V_21 -> V_39 = F_7 ( V_39 ) ;
for ( V_42 = 0 , V_18 = V_21 -> V_43 ; V_42 < V_37 ; V_42 ++ , V_18 ++ )
F_14 ( V_38 [ V_42 ] , V_18 ) ;
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ , V_18 ++ )
F_14 ( V_40 [ V_42 ] , V_18 ) ;
V_15 = F_10 ( V_5 , V_34 , V_44 , 0 , V_21 ,
V_41 ) ;
F_15 ( V_21 ) ;
return V_15 ;
}
static int F_16 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_45 * V_21 ;
struct V_26 * V_46 ;
T_3 V_22 ;
T_2 V_47 ;
int V_15 ;
F_4 ( L_2 , V_5 ) ;
F_17 ( & V_48 ) ;
V_47 = 0 ;
F_18 (d, &hci_dev_list, list) {
if ( V_46 -> V_49 == V_50 )
V_47 ++ ;
}
V_22 = sizeof( * V_21 ) + ( 2 * V_47 ) ;
V_21 = F_13 ( V_22 , V_51 ) ;
if ( ! V_21 ) {
F_19 ( & V_48 ) ;
return - V_17 ;
}
V_47 = 0 ;
F_18 (d, &hci_dev_list, list) {
if ( F_20 ( V_52 , & V_46 -> V_53 ) )
continue;
if ( F_20 ( V_54 , & V_46 -> V_53 ) )
continue;
if ( V_46 -> V_49 == V_50 ) {
V_21 -> V_6 [ V_47 ++ ] = F_7 ( V_46 -> V_55 ) ;
F_4 ( L_3 , V_46 -> V_55 ) ;
}
}
V_21 -> V_56 = F_7 ( V_47 ) ;
V_22 = sizeof( * V_21 ) + ( 2 * V_47 ) ;
F_19 ( & V_48 ) ;
V_15 = F_10 ( V_5 , V_34 , V_57 , 0 , V_21 ,
V_22 ) ;
F_15 ( V_21 ) ;
return V_15 ;
}
static T_5 F_21 ( struct V_26 * V_27 )
{
T_5 V_58 = 0 ;
V_58 |= V_59 ;
V_58 |= V_60 ;
V_58 |= V_61 ;
if ( F_22 ( V_27 ) ) {
V_58 |= V_62 ;
if ( V_27 -> V_63 >= V_64 )
V_58 |= V_65 ;
V_58 |= V_66 ;
V_58 |= V_67 ;
V_58 |= V_68 ;
if ( F_23 ( V_27 ) ) {
V_58 |= V_69 ;
V_58 |= V_70 ;
}
if ( F_24 ( V_27 ) ||
F_20 ( V_71 , & V_27 -> V_53 ) )
V_58 |= V_72 ;
}
if ( F_25 ( V_27 ) ) {
V_58 |= V_73 ;
V_58 |= V_74 ;
V_58 |= V_75 ;
}
return V_58 ;
}
static T_5 F_26 ( struct V_26 * V_27 )
{
T_5 V_58 = 0 ;
if ( F_27 ( V_27 ) )
V_58 |= V_59 ;
if ( F_20 ( V_76 , & V_27 -> V_53 ) )
V_58 |= V_62 ;
if ( F_20 ( V_77 , & V_27 -> V_53 ) )
V_58 |= V_65 ;
if ( F_20 ( V_78 , & V_27 -> V_53 ) )
V_58 |= V_66 ;
if ( F_20 ( V_79 , & V_27 -> V_53 ) )
V_58 |= V_60 ;
if ( F_20 ( V_80 , & V_27 -> V_53 ) )
V_58 |= V_67 ;
if ( F_20 ( V_81 , & V_27 -> V_53 ) )
V_58 |= V_73 ;
if ( F_20 ( V_82 , & V_27 -> V_53 ) )
V_58 |= V_68 ;
if ( F_20 ( V_83 , & V_27 -> V_53 ) )
V_58 |= V_69 ;
if ( F_20 ( V_84 , & V_27 -> V_53 ) )
V_58 |= V_70 ;
if ( F_20 ( V_85 , & V_27 -> V_53 ) )
V_58 |= V_74 ;
if ( F_20 ( V_86 , & V_27 -> V_53 ) )
V_58 |= V_72 ;
if ( F_20 ( V_87 , & V_27 -> V_53 ) )
V_58 |= V_61 ;
if ( F_20 ( V_88 , & V_27 -> V_53 ) )
V_58 |= V_75 ;
return V_58 ;
}
static T_1 * F_28 ( struct V_26 * V_27 , T_1 * V_25 , T_6 V_20 )
{
T_1 * V_89 = V_25 , * V_90 = NULL ;
struct V_91 * V_92 ;
if ( V_20 < 4 )
return V_89 ;
F_18 (uuid, &hdev->uuids, list) {
T_2 V_93 ;
if ( V_92 -> V_94 != 16 )
continue;
V_93 = F_29 ( & V_92 -> V_92 [ 12 ] ) ;
if ( V_93 < 0x1100 )
continue;
if ( V_93 == V_95 )
continue;
if ( ! V_90 ) {
V_90 = V_89 ;
V_90 [ 0 ] = 1 ;
V_90 [ 1 ] = V_96 ;
V_89 += 2 ;
}
if ( ( V_89 - V_25 ) + sizeof( T_2 ) > V_20 ) {
V_90 [ 1 ] = V_97 ;
break;
}
* V_89 ++ = ( V_93 & 0x00ff ) ;
* V_89 ++ = ( V_93 & 0xff00 ) >> 8 ;
V_90 [ 0 ] += sizeof( V_93 ) ;
}
return V_89 ;
}
static T_1 * F_30 ( struct V_26 * V_27 , T_1 * V_25 , T_6 V_20 )
{
T_1 * V_89 = V_25 , * V_90 = NULL ;
struct V_91 * V_92 ;
if ( V_20 < 6 )
return V_89 ;
F_18 (uuid, &hdev->uuids, list) {
if ( V_92 -> V_94 != 32 )
continue;
if ( ! V_90 ) {
V_90 = V_89 ;
V_90 [ 0 ] = 1 ;
V_90 [ 1 ] = V_98 ;
V_89 += 2 ;
}
if ( ( V_89 - V_25 ) + sizeof( T_5 ) > V_20 ) {
V_90 [ 1 ] = V_99 ;
break;
}
memcpy ( V_89 , & V_92 -> V_92 [ 12 ] , sizeof( T_5 ) ) ;
V_89 += sizeof( T_5 ) ;
V_90 [ 0 ] += sizeof( T_5 ) ;
}
return V_89 ;
}
static T_1 * F_31 ( struct V_26 * V_27 , T_1 * V_25 , T_6 V_20 )
{
T_1 * V_89 = V_25 , * V_90 = NULL ;
struct V_91 * V_92 ;
if ( V_20 < 18 )
return V_89 ;
F_18 (uuid, &hdev->uuids, list) {
if ( V_92 -> V_94 != 128 )
continue;
if ( ! V_90 ) {
V_90 = V_89 ;
V_90 [ 0 ] = 1 ;
V_90 [ 1 ] = V_100 ;
V_89 += 2 ;
}
if ( ( V_89 - V_25 ) + 16 > V_20 ) {
V_90 [ 1 ] = V_101 ;
break;
}
memcpy ( V_89 , V_92 -> V_92 , 16 ) ;
V_89 += 16 ;
V_90 [ 0 ] += 16 ;
}
return V_89 ;
}
static struct V_102 * F_32 ( T_2 V_18 , struct V_26 * V_27 )
{
struct V_102 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 == V_18 )
return V_7 ;
}
return NULL ;
}
static T_1 F_33 ( struct V_26 * V_27 , T_1 * V_89 )
{
T_1 V_103 = 0 ;
T_3 V_104 ;
V_104 = strlen ( V_27 -> V_105 ) ;
if ( V_104 > 0 ) {
T_3 V_106 = V_107 - V_103 - 2 ;
if ( V_104 > V_106 ) {
V_104 = V_106 ;
V_89 [ 1 ] = V_108 ;
} else
V_89 [ 1 ] = V_109 ;
V_89 [ 0 ] = V_104 + 1 ;
memcpy ( V_89 + 2 , V_27 -> V_105 , V_104 ) ;
V_103 += ( V_104 + 2 ) ;
V_89 += ( V_104 + 2 ) ;
}
return V_103 ;
}
static void F_34 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_112 V_113 ;
T_1 V_20 ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) )
return;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_20 = F_33 ( V_27 , V_113 . V_25 ) ;
if ( V_27 -> V_114 == V_20 &&
memcmp ( V_113 . V_25 , V_27 -> V_115 , V_20 ) == 0 )
return;
memcpy ( V_27 -> V_115 , V_113 . V_25 , sizeof( V_113 . V_25 ) ) ;
V_27 -> V_114 = V_20 ;
V_113 . V_116 = V_20 ;
F_35 ( V_111 , V_117 , sizeof( V_113 ) , & V_113 ) ;
}
static T_1 F_36 ( struct V_26 * V_27 )
{
struct V_102 * V_7 ;
V_7 = F_32 ( V_118 , V_27 ) ;
if ( V_7 ) {
struct V_119 * V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 == 0x01 )
return V_122 ;
else if ( V_113 -> V_121 == 0x02 )
return V_123 ;
} else {
if ( F_20 ( V_124 , & V_27 -> V_53 ) )
return V_123 ;
else if ( F_20 ( V_78 , & V_27 -> V_53 ) )
return V_122 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_26 * V_27 , T_1 * V_89 )
{
T_1 V_103 = 0 , V_125 = 0 ;
V_125 |= F_36 ( V_27 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
V_125 |= V_126 ;
if ( V_125 ) {
F_4 ( L_4 , V_125 ) ;
V_89 [ 0 ] = 2 ;
V_89 [ 1 ] = V_127 ;
V_89 [ 2 ] = V_125 ;
V_103 += 3 ;
V_89 += 3 ;
}
if ( V_27 -> V_128 != V_129 ) {
V_89 [ 0 ] = 2 ;
V_89 [ 1 ] = V_130 ;
V_89 [ 2 ] = ( T_1 ) V_27 -> V_128 ;
V_103 += 3 ;
V_89 += 3 ;
}
return V_103 ;
}
static void F_38 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_131 V_113 ;
T_1 V_20 ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) )
return;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_20 = F_37 ( V_27 , V_113 . V_25 ) ;
if ( V_27 -> V_132 == V_20 &&
memcmp ( V_113 . V_25 , V_27 -> V_133 , V_20 ) == 0 )
return;
memcpy ( V_27 -> V_133 , V_113 . V_25 , sizeof( V_113 . V_25 ) ) ;
V_27 -> V_132 = V_20 ;
V_113 . V_116 = V_20 ;
F_35 ( V_111 , V_134 , sizeof( V_113 ) , & V_113 ) ;
}
static void F_39 ( struct V_26 * V_27 , T_1 * V_25 )
{
T_1 * V_89 = V_25 ;
T_3 V_104 ;
V_104 = strlen ( V_27 -> V_105 ) ;
if ( V_104 > 0 ) {
if ( V_104 > 48 ) {
V_104 = 48 ;
V_89 [ 1 ] = V_108 ;
} else
V_89 [ 1 ] = V_109 ;
V_89 [ 0 ] = V_104 + 1 ;
memcpy ( V_89 + 2 , V_27 -> V_105 , V_104 ) ;
V_89 += ( V_104 + 2 ) ;
}
if ( V_27 -> V_135 != V_129 ) {
V_89 [ 0 ] = 2 ;
V_89 [ 1 ] = V_130 ;
V_89 [ 2 ] = ( T_1 ) V_27 -> V_135 ;
V_89 += 3 ;
}
if ( V_27 -> V_136 > 0 ) {
V_89 [ 0 ] = 9 ;
V_89 [ 1 ] = V_137 ;
F_14 ( V_27 -> V_136 , V_89 + 2 ) ;
F_14 ( V_27 -> V_138 , V_89 + 4 ) ;
F_14 ( V_27 -> V_139 , V_89 + 6 ) ;
F_14 ( V_27 -> V_140 , V_89 + 8 ) ;
V_89 += 10 ;
}
V_89 = F_28 ( V_27 , V_89 , V_141 - ( V_89 - V_25 ) ) ;
V_89 = F_30 ( V_27 , V_89 , V_141 - ( V_89 - V_25 ) ) ;
V_89 = F_31 ( V_27 , V_89 , V_141 - ( V_89 - V_25 ) ) ;
}
static void F_40 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_142 V_113 ;
if ( ! F_27 ( V_27 ) )
return;
if ( ! F_41 ( V_27 ) )
return;
if ( ! F_20 ( V_83 , & V_27 -> V_53 ) )
return;
if ( F_20 ( V_143 , & V_27 -> V_53 ) )
return;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
F_39 ( V_27 , V_113 . V_25 ) ;
if ( memcmp ( V_113 . V_25 , V_27 -> V_144 , sizeof( V_113 . V_25 ) ) == 0 )
return;
memcpy ( V_27 -> V_144 , V_113 . V_25 , sizeof( V_113 . V_25 ) ) ;
F_35 ( V_111 , V_145 , sizeof( V_113 ) , & V_113 ) ;
}
static T_1 F_42 ( struct V_26 * V_27 )
{
struct V_91 * V_92 ;
T_1 V_121 = 0 ;
F_18 (uuid, &hdev->uuids, list)
V_121 |= V_92 -> V_146 ;
return V_121 ;
}
static void F_43 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
T_1 V_147 [ 3 ] ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_27 ( V_27 ) )
return;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return;
if ( F_20 ( V_143 , & V_27 -> V_53 ) )
return;
V_147 [ 0 ] = V_27 -> V_149 ;
V_147 [ 1 ] = V_27 -> V_150 ;
V_147 [ 2 ] = F_42 ( V_27 ) ;
if ( F_20 ( V_124 , & V_27 -> V_53 ) )
V_147 [ 1 ] |= 0x20 ;
if ( memcmp ( V_147 , V_27 -> V_151 , 3 ) == 0 )
return;
F_35 ( V_111 , V_152 , sizeof( V_147 ) , V_147 ) ;
}
static bool F_44 ( struct V_26 * V_27 )
{
struct V_102 * V_7 ;
V_7 = F_32 ( V_153 , V_27 ) ;
if ( V_7 ) {
struct V_119 * V_113 = V_7 -> V_120 ;
return V_113 -> V_121 ;
}
return F_20 ( V_76 , & V_27 -> V_53 ) ;
}
static void F_45 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_154 V_113 ;
T_1 V_155 , V_156 = 0x01 ;
bool V_157 ;
F_46 ( V_85 , & V_27 -> V_53 ) ;
V_157 = F_44 ( V_27 ) ;
if ( F_47 ( V_111 , ! V_157 , & V_155 ) < 0 )
return;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_158 = F_7 ( 0x0800 ) ;
V_113 . V_159 = F_7 ( 0x0800 ) ;
V_113 . type = V_157 ? V_160 : V_161 ;
V_113 . V_162 = V_155 ;
V_113 . V_163 = V_27 -> V_164 ;
F_35 ( V_111 , V_165 , sizeof( V_113 ) , & V_113 ) ;
F_35 ( V_111 , V_166 , sizeof( V_156 ) , & V_156 ) ;
}
static void F_48 ( struct V_110 * V_111 )
{
T_1 V_156 = 0x00 ;
F_35 ( V_111 , V_166 , sizeof( V_156 ) , & V_156 ) ;
}
static void F_49 ( struct V_167 * V_168 )
{
struct V_26 * V_27 = F_50 ( V_168 , struct V_26 ,
V_169 . V_168 ) ;
struct V_110 V_111 ;
if ( ! F_51 ( V_143 , & V_27 -> V_53 ) )
return;
F_52 ( & V_111 , V_27 ) ;
F_53 ( V_27 ) ;
F_40 ( & V_111 ) ;
F_43 ( & V_111 ) ;
F_54 ( V_27 ) ;
F_55 ( & V_111 , NULL ) ;
}
static void F_56 ( struct V_167 * V_168 )
{
struct V_26 * V_27 = F_50 ( V_168 , struct V_26 ,
F_56 . V_168 ) ;
struct V_110 V_111 ;
F_4 ( L_6 ) ;
F_57 ( V_170 , & V_27 -> V_53 ) ;
if ( ! F_20 ( V_85 , & V_27 -> V_53 ) ||
F_58 ( V_27 , V_171 ) > 0 )
return;
F_52 ( & V_111 , V_27 ) ;
F_48 ( & V_111 ) ;
F_45 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
}
static void F_59 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
if ( F_60 ( V_172 , & V_27 -> V_53 ) )
return;
F_61 ( & V_27 -> V_169 , F_49 ) ;
F_61 ( & V_27 -> F_56 , F_56 ) ;
F_46 ( V_79 , & V_27 -> V_53 ) ;
}
static int F_62 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_173 V_21 ;
F_4 ( L_7 , V_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_174 , & V_27 -> V_174 ) ;
V_21 . V_30 = V_27 -> V_63 ;
V_21 . V_175 = F_7 ( V_27 -> V_175 ) ;
V_21 . V_176 = F_64 ( F_21 ( V_27 ) ) ;
V_21 . V_177 = F_64 ( F_26 ( V_27 ) ) ;
memcpy ( V_21 . V_151 , V_27 -> V_151 , 3 ) ;
memcpy ( V_21 . V_148 , V_27 -> V_105 , sizeof( V_27 -> V_105 ) ) ;
memcpy ( V_21 . V_178 , V_27 -> V_178 , sizeof( V_27 -> V_178 ) ) ;
F_54 ( V_27 ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_179 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static void F_65 ( struct V_102 * V_7 )
{
F_66 ( V_7 -> V_5 ) ;
F_15 ( V_7 -> V_120 ) ;
F_15 ( V_7 ) ;
}
static struct V_102 * F_67 ( struct V_4 * V_5 , T_2 V_18 ,
struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_102 * V_7 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 = V_18 ;
V_7 -> V_6 = V_27 -> V_55 ;
V_7 -> V_120 = F_13 ( V_20 , V_16 ) ;
if ( ! V_7 -> V_120 ) {
F_15 ( V_7 ) ;
return NULL ;
}
if ( V_25 )
memcpy ( V_7 -> V_120 , V_25 , V_20 ) ;
V_7 -> V_5 = V_5 ;
F_68 ( V_5 ) ;
F_69 ( & V_7 -> V_180 , & V_27 -> V_181 ) ;
return V_7 ;
}
static void F_70 ( T_2 V_18 , struct V_26 * V_27 ,
void (* F_71)( struct V_102 * V_7 ,
void * V_25 ) ,
void * V_25 )
{
struct V_102 * V_7 , * V_182 ;
F_72 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_18 > 0 && V_7 -> V_18 != V_18 )
continue;
F_71 ( V_7 , V_25 ) ;
}
}
static void F_73 ( struct V_102 * V_7 )
{
F_74 ( & V_7 -> V_180 ) ;
F_65 ( V_7 ) ;
}
static int F_75 ( struct V_4 * V_5 , T_2 V_18 , struct V_26 * V_27 )
{
T_7 V_58 = F_64 ( F_26 ( V_27 ) ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_18 , 0 , & V_58 ,
sizeof( V_58 ) ) ;
}
static void F_76 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_8 , V_27 -> V_148 , V_8 ) ;
if ( F_77 ( V_27 ) == 0 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
}
}
static int F_80 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
struct V_185 * V_186 ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_187 , & V_27 -> V_125 ) ||
F_20 ( V_188 , & V_27 -> V_125 ) ) {
T_1 V_189 = 0x00 ;
F_35 ( & V_111 , V_190 , 1 , & V_189 ) ;
}
if ( F_20 ( V_85 , & V_27 -> V_53 ) )
F_48 ( & V_111 ) ;
if ( F_20 ( V_191 , & V_27 -> V_53 ) ) {
F_81 ( & V_111 ) ;
}
F_18 (conn, &hdev->conn_hash.list, list) {
struct V_192 V_193 ;
struct V_194 V_195 ;
switch ( V_186 -> V_196 ) {
case V_197 :
case V_198 :
V_193 . V_199 = F_7 ( V_186 -> V_199 ) ;
V_193 . V_200 = 0x15 ;
F_35 ( & V_111 , V_201 , sizeof( V_193 ) , & V_193 ) ;
break;
case V_202 :
if ( V_186 -> type == V_171 )
F_35 ( & V_111 , V_203 ,
0 , NULL ) ;
else if ( V_186 -> type == V_204 )
F_35 ( & V_111 , V_205 ,
6 , & V_186 -> V_206 ) ;
break;
case V_207 :
F_63 ( & V_195 . V_174 , & V_186 -> V_206 ) ;
V_195 . V_200 = 0x15 ;
if ( V_186 -> type == V_204 )
F_35 ( & V_111 , V_208 ,
sizeof( V_195 ) , & V_195 ) ;
else if ( V_186 -> type == V_209 )
F_35 ( & V_111 , V_210 ,
sizeof( V_195 ) , & V_195 ) ;
break;
}
}
return F_55 ( & V_111 , F_76 ) ;
}
static int F_82 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_211 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( F_32 ( V_211 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_211 ,
V_213 ) ;
goto V_214;
}
if ( F_51 ( V_215 , & V_27 -> V_53 ) ) {
F_78 ( & V_27 -> V_183 ) ;
if ( V_113 -> V_121 ) {
F_67 ( V_5 , V_211 , V_27 ,
V_25 , V_20 ) ;
V_15 = F_83 ( V_27 , 1 ) ;
goto V_214;
}
}
if ( ! ! V_113 -> V_121 == F_27 ( V_27 ) ) {
V_15 = F_75 ( V_5 , V_211 , V_27 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_211 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
if ( V_113 -> V_121 ) {
F_79 ( V_27 -> V_184 , & V_27 -> V_216 ) ;
V_15 = 0 ;
} else {
V_15 = F_80 ( V_27 ) ;
if ( ! V_15 )
F_84 ( V_27 -> V_184 , & V_27 -> V_183 ,
V_217 ) ;
if ( V_15 == - V_218 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
V_15 = 0 ;
}
}
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_85 ( T_2 V_219 , struct V_26 * V_27 , void * V_25 , T_2 V_28 ,
struct V_4 * V_220 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_5 ( sizeof( * V_12 ) + V_28 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_219 ) ;
if ( V_27 )
V_12 -> V_6 = F_7 ( V_27 -> V_55 ) ;
else
V_12 -> V_6 = F_7 ( V_34 ) ;
V_12 -> V_20 = F_7 ( V_28 ) ;
if ( V_25 )
memcpy ( F_6 ( V_10 , V_28 ) , V_25 , V_28 ) ;
F_86 ( V_10 ) ;
F_87 ( V_10 , V_220 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_88 ( struct V_26 * V_27 , struct V_4 * V_221 )
{
T_7 V_14 ;
V_14 = F_64 ( F_26 ( V_27 ) ) ;
return F_85 ( V_222 , V_27 , & V_14 , sizeof( V_14 ) , V_221 ) ;
}
static void F_89 ( struct V_102 * V_7 , void * V_25 )
{
struct V_223 * V_224 = V_25 ;
F_75 ( V_7 -> V_5 , V_7 -> V_18 , V_224 -> V_27 ) ;
F_74 ( & V_7 -> V_180 ) ;
if ( V_224 -> V_5 == NULL ) {
V_224 -> V_5 = V_7 -> V_5 ;
F_68 ( V_224 -> V_5 ) ;
}
F_65 ( V_7 ) ;
}
static void F_90 ( struct V_102 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , * V_8 ) ;
F_73 ( V_7 ) ;
}
static T_1 F_91 ( struct V_26 * V_27 )
{
if ( ! F_22 ( V_27 ) )
return V_225 ;
else if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return V_226 ;
else
return V_227 ;
}
static T_1 F_92 ( struct V_26 * V_27 )
{
if ( ! F_25 ( V_27 ) )
return V_225 ;
else if ( ! F_20 ( V_81 , & V_27 -> V_53 ) )
return V_226 ;
else
return V_227 ;
}
static void F_93 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_119 * V_113 ;
struct V_110 V_111 ;
bool V_228 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_118 , V_27 ) ;
if ( ! V_7 )
goto V_229;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_230 ) ;
F_46 ( V_124 , & V_27 -> V_53 ) ;
goto V_231;
}
V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 ) {
V_228 = ! F_60 ( V_78 ,
& V_27 -> V_53 ) ;
if ( V_27 -> V_232 > 0 ) {
int V_233 = F_94 ( V_27 -> V_232 * 1000 ) ;
F_84 ( V_27 -> V_234 , & V_27 -> V_235 ,
V_233 ) ;
}
} else {
V_228 = F_51 ( V_78 ,
& V_27 -> V_53 ) ;
}
F_75 ( V_7 -> V_5 , V_118 , V_27 ) ;
if ( V_228 )
F_88 ( V_27 , V_7 -> V_5 ) ;
F_52 ( & V_111 , V_27 ) ;
F_43 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
V_231:
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
}
static int F_95 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_236 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
T_2 V_237 ;
T_1 V_189 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) &&
! F_20 ( V_80 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_226 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 && V_113 -> V_121 != 0x02 )
return F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_212 ) ;
V_237 = F_96 ( V_113 -> V_237 ) ;
if ( ( V_113 -> V_121 == 0x00 && V_237 > 0 ) ||
( V_113 -> V_121 == 0x02 && V_237 == 0 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) && V_237 > 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_238 ) ;
goto V_214;
}
if ( F_32 ( V_118 , V_27 ) ||
F_32 ( V_153 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_213 ) ;
goto V_214;
}
if ( ! F_20 ( V_76 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_226 ) ;
goto V_214;
}
if ( ! F_27 ( V_27 ) ) {
bool V_228 = false ;
if ( ! ! V_113 -> V_121 != F_20 ( V_78 , & V_27 -> V_53 ) ) {
F_97 ( V_78 , & V_27 -> V_53 ) ;
V_228 = true ;
}
V_15 = F_75 ( V_5 , V_118 , V_27 ) ;
if ( V_15 < 0 )
goto V_214;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_214;
}
if ( ! ! V_113 -> V_121 == F_20 ( V_78 , & V_27 -> V_53 ) &&
( V_113 -> V_121 == 0x02 ) == F_20 ( V_124 ,
& V_27 -> V_53 ) ) {
F_78 ( & V_27 -> V_235 ) ;
V_27 -> V_232 = V_237 ;
if ( V_113 -> V_121 && V_27 -> V_232 > 0 ) {
int V_233 = F_94 ( V_27 -> V_232 * 1000 ) ;
F_84 ( V_27 -> V_234 , & V_27 -> V_235 ,
V_233 ) ;
}
V_15 = F_75 ( V_5 , V_118 , V_27 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_118 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
F_78 ( & V_27 -> V_235 ) ;
V_27 -> V_232 = V_237 ;
if ( V_113 -> V_121 == 0x02 )
F_57 ( V_124 , & V_27 -> V_53 ) ;
else
F_46 ( V_124 , & V_27 -> V_53 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
goto V_239;
V_189 = V_240 ;
if ( V_113 -> V_121 ) {
struct V_241 V_242 ;
if ( V_113 -> V_121 == 0x02 ) {
V_242 . V_243 = F_98 ( T_1 , V_27 -> V_243 , 2 ) ;
V_242 . V_244 [ 0 ] = 0x00 ;
V_242 . V_244 [ 1 ] = 0x8b ;
V_242 . V_244 [ 2 ] = 0x9e ;
V_242 . V_244 [ 3 ] = 0x33 ;
V_242 . V_244 [ 4 ] = 0x8b ;
V_242 . V_244 [ 5 ] = 0x9e ;
} else {
V_242 . V_243 = 1 ;
V_242 . V_244 [ 0 ] = 0x33 ;
V_242 . V_244 [ 1 ] = 0x8b ;
V_242 . V_244 [ 2 ] = 0x9e ;
}
F_35 ( & V_111 , V_245 ,
( V_242 . V_243 * 3 ) + 1 , & V_242 ) ;
V_189 |= V_246 ;
} else {
F_46 ( V_124 , & V_27 -> V_53 ) ;
}
F_35 ( & V_111 , V_190 , sizeof( V_189 ) , & V_189 ) ;
V_239:
F_38 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_93 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_99 ( struct V_110 * V_111 , bool V_156 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_247 V_248 ;
T_1 type ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return;
if ( V_27 -> V_63 < V_64 )
return;
if ( V_156 ) {
type = V_249 ;
V_248 . V_250 = F_7 ( 0x0100 ) ;
} else {
type = V_251 ;
V_248 . V_250 = F_7 ( 0x0800 ) ;
}
V_248 . V_252 = F_7 ( 0x0012 ) ;
if ( F_100 ( V_27 -> V_253 ) != V_248 . V_250 ||
F_100 ( V_27 -> V_254 ) != V_248 . V_252 )
F_35 ( V_111 , V_255 ,
sizeof( V_248 ) , & V_248 ) ;
if ( V_27 -> V_256 != type )
F_35 ( V_111 , V_257 , 1 , & type ) ;
}
static void F_101 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_119 * V_113 ;
bool V_228 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_153 , V_27 ) ;
if ( ! V_7 )
goto V_229;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_230 ) ;
goto V_231;
}
V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 )
V_228 = ! F_60 ( V_76 , & V_27 -> V_53 ) ;
else
V_228 = F_51 ( V_76 , & V_27 -> V_53 ) ;
F_75 ( V_7 -> V_5 , V_153 , V_27 ) ;
if ( V_228 )
F_88 ( V_27 , V_7 -> V_5 ) ;
V_231:
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
}
static int F_102 ( struct V_26 * V_27 ,
struct V_4 * V_5 , T_1 V_121 )
{
bool V_228 = false ;
int V_15 ;
if ( ! ! V_121 != F_20 ( V_76 , & V_27 -> V_53 ) )
V_228 = true ;
if ( V_121 ) {
F_57 ( V_76 , & V_27 -> V_53 ) ;
} else {
F_46 ( V_76 , & V_27 -> V_53 ) ;
F_46 ( V_78 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_153 , V_27 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_228 )
return F_88 ( V_27 , V_5 ) ;
return 0 ;
}
static int F_103 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
T_1 V_189 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) &&
! F_20 ( V_80 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_153 ,
V_226 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_153 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_102 ( V_27 , V_5 , V_113 -> V_121 ) ;
goto V_214;
}
if ( F_32 ( V_118 , V_27 ) ||
F_32 ( V_153 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_153 ,
V_213 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_153 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
F_52 ( & V_111 , V_27 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) ) {
if ( ! V_113 -> V_121 ) {
F_46 ( V_124 , & V_27 -> V_53 ) ;
F_46 ( V_78 , & V_27 -> V_53 ) ;
}
F_38 ( & V_111 ) ;
} else if ( V_113 -> V_121 != F_20 ( V_188 , & V_27 -> V_125 ) ) {
if ( V_113 -> V_121 ) {
V_189 = V_240 ;
} else {
V_189 = 0 ;
if ( F_20 ( V_187 , & V_27 -> V_125 ) &&
V_27 -> V_232 > 0 )
F_78 ( & V_27 -> V_235 ) ;
}
F_35 ( & V_111 , V_190 , 1 , & V_189 ) ;
}
if ( V_113 -> V_121 || F_20 ( V_77 , & V_27 -> V_53 ) )
F_99 ( & V_111 , false ) ;
if ( F_20 ( V_85 , & V_27 -> V_53 ) &&
F_58 ( V_27 , V_171 ) == 0 ) {
F_48 ( & V_111 ) ;
F_45 ( & V_111 ) ;
}
V_15 = F_55 ( & V_111 , F_101 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
if ( V_15 == - V_218 )
V_15 = F_102 ( V_27 , V_5 ,
V_113 -> V_121 ) ;
goto V_214;
}
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_104 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
bool V_228 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_258 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 )
V_228 = ! F_60 ( V_79 , & V_27 -> V_53 ) ;
else
V_228 = F_51 ( V_79 , & V_27 -> V_53 ) ;
V_15 = F_75 ( V_5 , V_258 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_105 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
T_1 V_121 , V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_91 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_8 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_228 = false ;
if ( ! ! V_113 -> V_121 != F_20 ( V_82 ,
& V_27 -> V_53 ) ) {
F_97 ( V_82 , & V_27 -> V_53 ) ;
V_228 = true ;
}
V_15 = F_75 ( V_5 , V_259 , V_27 ) ;
if ( V_15 < 0 )
goto V_214;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_214;
}
if ( F_32 ( V_259 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_213 ) ;
goto V_214;
}
V_121 = ! ! V_113 -> V_121 ;
if ( F_20 ( V_260 , & V_27 -> V_125 ) == V_121 ) {
V_15 = F_75 ( V_5 , V_259 , V_27 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_259 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
V_15 = F_106 ( V_27 , V_261 , sizeof( V_121 ) , & V_121 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
goto V_214;
}
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_107 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_91 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_262 , V_8 ) ;
if ( ! F_23 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_262 ,
V_225 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_262 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_228 ;
if ( V_113 -> V_121 ) {
V_228 = ! F_60 ( V_83 ,
& V_27 -> V_53 ) ;
} else {
V_228 = F_51 ( V_83 ,
& V_27 -> V_53 ) ;
if ( ! V_228 )
V_228 = F_51 ( V_84 ,
& V_27 -> V_53 ) ;
else
F_46 ( V_84 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_262 , V_27 ) ;
if ( V_15 < 0 )
goto V_214;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_214;
}
if ( F_32 ( V_262 , V_27 ) ||
F_32 ( V_263 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_262 ,
V_213 ) ;
goto V_214;
}
if ( ! ! V_113 -> V_121 == F_20 ( V_83 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_262 , V_27 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_262 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
V_15 = F_106 ( V_27 , V_264 , 1 , & V_113 -> V_121 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
goto V_214;
}
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_108 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
bool V_228 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_91 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_263 , V_8 ) ;
if ( ! F_23 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_263 ,
V_225 ) ;
if ( ! F_20 ( V_83 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_263 ,
V_226 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_263 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 ) {
V_228 = ! F_60 ( V_84 , & V_27 -> V_53 ) ;
} else {
if ( F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_263 ,
V_226 ) ;
goto V_229;
}
V_228 = F_51 ( V_84 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_263 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_109 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 } ;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
F_70 ( V_265 , V_27 , F_90 ,
& V_230 ) ;
return;
}
F_70 ( V_265 , V_27 , F_89 , & V_224 ) ;
F_88 ( V_27 , V_224 . V_5 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
if ( F_20 ( V_81 , & V_27 -> V_53 ) ) {
struct V_110 V_111 ;
F_53 ( V_27 ) ;
F_52 ( & V_111 , V_27 ) ;
F_38 ( & V_111 ) ;
F_34 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
F_54 ( V_27 ) ;
}
}
static int F_110 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_266 V_242 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
T_1 V_121 , V_267 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_265 ,
V_225 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_265 ,
V_212 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_265 ,
V_226 ) ;
F_53 ( V_27 ) ;
V_121 = ! ! V_113 -> V_121 ;
V_267 = F_111 ( V_27 ) ;
if ( ! F_27 ( V_27 ) || V_121 == V_267 ) {
bool V_228 = false ;
if ( V_121 != F_20 ( V_81 , & V_27 -> V_53 ) ) {
F_97 ( V_81 , & V_27 -> V_53 ) ;
V_228 = true ;
}
if ( ! V_121 && F_20 ( V_85 , & V_27 -> V_53 ) ) {
F_46 ( V_85 , & V_27 -> V_53 ) ;
V_228 = true ;
}
V_15 = F_75 ( V_5 , V_265 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_229;
}
if ( F_32 ( V_265 , V_27 ) ||
F_32 ( V_268 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_265 ,
V_213 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_265 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
F_52 ( & V_111 , V_27 ) ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
if ( V_121 ) {
V_242 . V_269 = V_121 ;
V_242 . V_270 = F_112 ( V_27 ) ;
} else {
if ( F_20 ( V_85 , & V_27 -> V_53 ) )
F_48 ( & V_111 ) ;
}
F_35 ( & V_111 , V_271 , sizeof( V_242 ) ,
& V_242 ) ;
V_15 = F_55 ( & V_111 , F_109 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_113 ( struct V_26 * V_27 )
{
struct V_102 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
switch ( V_7 -> V_18 ) {
case V_272 :
case V_273 :
case V_274 :
case V_211 :
return true ;
}
}
return false ;
}
static T_1 F_114 ( const T_1 * V_92 )
{
T_5 V_121 ;
if ( memcmp ( V_92 , V_275 , 12 ) )
return 128 ;
V_121 = F_115 ( & V_92 [ 12 ] ) ;
if ( V_121 > 0xffff )
return 32 ;
return 16 ;
}
static void F_116 ( struct V_26 * V_27 , T_2 V_276 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_276 , V_27 ) ;
if ( ! V_7 )
goto V_229;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , F_1 ( V_8 ) ,
V_27 -> V_151 , 3 ) ;
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
}
static void F_117 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_10 , V_8 ) ;
F_116 ( V_27 , V_272 , V_8 ) ;
}
static int F_118 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_277 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
struct V_91 * V_92 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( F_113 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_272 ,
V_213 ) ;
goto V_214;
}
V_92 = F_13 ( sizeof( * V_92 ) , V_16 ) ;
if ( ! V_92 ) {
V_15 = - V_17 ;
goto V_214;
}
memcpy ( V_92 -> V_92 , V_113 -> V_92 , 16 ) ;
V_92 -> V_146 = V_113 -> V_146 ;
V_92 -> V_94 = F_114 ( V_113 -> V_92 ) ;
F_119 ( & V_92 -> V_180 , & V_27 -> V_278 ) ;
F_52 ( & V_111 , V_27 ) ;
F_43 ( & V_111 ) ;
F_40 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_117 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_218 )
goto V_214;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_272 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_272 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
V_15 = 0 ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_120 ( struct V_26 * V_27 )
{
if ( ! F_27 ( V_27 ) )
return false ;
if ( ! F_60 ( V_143 , & V_27 -> V_53 ) ) {
F_84 ( V_27 -> V_234 , & V_27 -> V_169 ,
V_279 ) ;
return true ;
}
return false ;
}
static void F_121 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_10 , V_8 ) ;
F_116 ( V_27 , V_273 , V_8 ) ;
}
static int F_122 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_280 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_91 * V_224 , * V_182 ;
T_1 V_281 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_110 V_111 ;
int V_15 , V_282 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( F_113 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_273 ,
V_213 ) ;
goto V_229;
}
if ( memcmp ( V_113 -> V_92 , V_281 , 16 ) == 0 ) {
F_123 ( V_27 ) ;
if ( F_120 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_273 ,
0 , V_27 -> V_151 , 3 ) ;
goto V_229;
}
goto F_43;
}
V_282 = 0 ;
F_72 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_224 -> V_92 , V_113 -> V_92 , 16 ) != 0 )
continue;
F_74 ( & V_224 -> V_180 ) ;
F_15 ( V_224 ) ;
V_282 ++ ;
}
if ( V_282 == 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_273 ,
V_212 ) ;
goto V_229;
}
F_43:
F_52 ( & V_111 , V_27 ) ;
F_43 ( & V_111 ) ;
F_40 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_121 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_218 )
goto V_229;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_273 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_273 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
V_15 = 0 ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_124 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_10 , V_8 ) ;
F_116 ( V_27 , V_274 , V_8 ) ;
}
static int F_125 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_283 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_22 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_274 ,
V_225 ) ;
F_53 ( V_27 ) ;
if ( F_113 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_274 ,
V_213 ) ;
goto V_229;
}
if ( ( V_113 -> V_284 & 0x03 ) != 0 || ( V_113 -> V_285 & 0xe0 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_274 ,
V_212 ) ;
goto V_229;
}
V_27 -> V_150 = V_113 -> V_285 ;
V_27 -> V_149 = V_113 -> V_284 ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_274 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_229;
}
F_52 ( & V_111 , V_27 ) ;
if ( F_51 ( V_143 , & V_27 -> V_53 ) ) {
F_54 ( V_27 ) ;
F_126 ( & V_27 -> V_169 ) ;
F_53 ( V_27 ) ;
F_40 ( & V_111 ) ;
}
F_43 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_124 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_218 )
goto V_229;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_274 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_274 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
V_15 = 0 ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_127 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_286 * V_113 = V_25 ;
T_2 V_287 , V_288 ;
bool V_228 ;
int V_42 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_22 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_289 ,
V_225 ) ;
V_287 = F_96 ( V_113 -> V_287 ) ;
V_288 = sizeof( * V_113 ) + V_287 *
sizeof( struct V_290 ) ;
if ( V_288 != V_20 ) {
F_128 ( L_11 ,
V_288 , V_20 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_289 ,
V_212 ) ;
}
if ( V_113 -> V_291 != 0x00 && V_113 -> V_291 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_289 ,
V_212 ) ;
F_4 ( L_12 , V_27 -> V_148 , V_113 -> V_291 ,
V_287 ) ;
for ( V_42 = 0 ; V_42 < V_287 ; V_42 ++ ) {
struct V_290 * V_292 = & V_113 -> V_293 [ V_42 ] ;
if ( V_292 -> V_294 . type != V_295 || V_292 -> type > 0x08 )
return F_3 ( V_5 , V_27 -> V_55 , V_289 ,
V_212 ) ;
}
F_53 ( V_27 ) ;
F_129 ( V_27 ) ;
if ( V_113 -> V_291 )
V_228 = ! F_60 ( V_87 , & V_27 -> V_53 ) ;
else
V_228 = F_51 ( V_87 , & V_27 -> V_53 ) ;
if ( V_228 )
F_88 ( V_27 , NULL ) ;
for ( V_42 = 0 ; V_42 < V_287 ; V_42 ++ ) {
struct V_290 * V_292 = & V_113 -> V_293 [ V_42 ] ;
F_130 ( V_27 , NULL , 0 , & V_292 -> V_294 . V_174 , V_292 -> V_121 ,
V_292 -> type , V_292 -> V_296 ) ;
}
F_10 ( V_5 , V_27 -> V_55 , V_289 , 0 , NULL , 0 ) ;
F_54 ( V_27 ) ;
return 0 ;
}
static int F_131 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_297 , struct V_4 * V_220 )
{
struct V_298 V_14 ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = V_297 ;
return F_85 ( V_299 , V_27 , & V_14 , sizeof( V_14 ) ,
V_220 ) ;
}
static int F_132 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_300 * V_113 = V_25 ;
struct V_301 V_21 ;
struct V_192 V_193 ;
struct V_102 * V_7 ;
struct V_185 * V_186 ;
int V_15 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_294 . V_174 , & V_113 -> V_294 . V_174 ) ;
V_21 . V_294 . type = V_113 -> V_294 . type ;
if ( ! F_133 ( V_113 -> V_294 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_302 ,
V_212 ,
& V_21 , sizeof( V_21 ) ) ;
if ( V_113 -> V_303 != 0x00 && V_113 -> V_303 != 0x01 )
return F_10 ( V_5 , V_27 -> V_55 , V_302 ,
V_212 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_302 ,
V_238 , & V_21 , sizeof( V_21 ) ) ;
goto V_229;
}
if ( V_113 -> V_294 . type == V_295 ) {
V_15 = F_134 ( V_27 , & V_113 -> V_294 . V_174 ) ;
} else {
T_1 V_297 ;
if ( V_113 -> V_294 . type == V_304 )
V_297 = V_305 ;
else
V_297 = V_306 ;
F_135 ( V_27 , & V_113 -> V_294 . V_174 , V_297 ) ;
F_136 ( V_27 , & V_113 -> V_294 . V_174 , V_297 ) ;
V_15 = F_137 ( V_27 , & V_113 -> V_294 . V_174 , V_297 ) ;
}
if ( V_15 < 0 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_302 ,
V_307 , & V_21 , sizeof( V_21 ) ) ;
goto V_229;
}
if ( V_113 -> V_303 ) {
if ( V_113 -> V_294 . type == V_295 )
V_186 = F_138 ( V_27 , V_204 ,
& V_113 -> V_294 . V_174 ) ;
else
V_186 = F_138 ( V_27 , V_171 ,
& V_113 -> V_294 . V_174 ) ;
} else {
V_186 = NULL ;
}
if ( ! V_186 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_302 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
F_131 ( V_27 , & V_113 -> V_294 . V_174 , V_113 -> V_294 . type , V_5 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_302 , V_27 , V_113 ,
sizeof( * V_113 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
V_193 . V_199 = F_7 ( V_186 -> V_199 ) ;
V_193 . V_200 = 0x13 ;
V_15 = F_106 ( V_27 , V_201 , sizeof( V_193 ) , & V_193 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int V_303 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_308 * V_113 = V_25 ;
struct V_309 V_21 ;
struct V_192 V_193 ;
struct V_102 * V_7 ;
struct V_185 * V_186 ;
int V_15 ;
F_4 ( L_6 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_294 . V_174 , & V_113 -> V_294 . V_174 ) ;
V_21 . V_294 . type = V_113 -> V_294 . type ;
if ( ! F_133 ( V_113 -> V_294 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_310 ,
V_212 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_20 ( V_311 , & V_27 -> V_125 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_310 ,
V_238 , & V_21 , sizeof( V_21 ) ) ;
goto V_214;
}
if ( F_32 ( V_310 , V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_310 ,
V_213 , & V_21 , sizeof( V_21 ) ) ;
goto V_214;
}
if ( V_113 -> V_294 . type == V_295 )
V_186 = F_138 ( V_27 , V_204 ,
& V_113 -> V_294 . V_174 ) ;
else
V_186 = F_138 ( V_27 , V_171 , & V_113 -> V_294 . V_174 ) ;
if ( ! V_186 || V_186 -> V_196 == V_312 || V_186 -> V_196 == V_313 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_310 ,
V_314 , & V_21 , sizeof( V_21 ) ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_310 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
V_193 . V_199 = F_7 ( V_186 -> V_199 ) ;
V_193 . V_200 = V_315 ;
V_15 = F_106 ( V_27 , V_201 , sizeof( V_193 ) , & V_193 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static T_1 F_139 ( T_1 V_316 , T_1 V_297 )
{
switch ( V_316 ) {
case V_171 :
switch ( V_297 ) {
case V_305 :
return V_304 ;
default:
return V_317 ;
}
default:
return V_295 ;
}
}
static int F_140 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_318 * V_21 ;
struct V_185 * V_319 ;
T_3 V_22 ;
int V_15 ;
T_2 V_42 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_320 ,
V_238 ) ;
goto V_229;
}
V_42 = 0 ;
F_18 (c, &hdev->conn_hash.list, list) {
if ( F_20 ( V_321 , & V_319 -> V_125 ) )
V_42 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_322 ) ) ;
V_21 = F_13 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
V_15 = - V_17 ;
goto V_229;
}
V_42 = 0 ;
F_18 (c, &hdev->conn_hash.list, list) {
if ( ! F_20 ( V_321 , & V_319 -> V_125 ) )
continue;
F_63 ( & V_21 -> V_294 [ V_42 ] . V_174 , & V_319 -> V_206 ) ;
V_21 -> V_294 [ V_42 ] . type = F_139 ( V_319 -> type , V_319 -> V_323 ) ;
if ( V_319 -> type == V_209 || V_319 -> type == V_324 )
continue;
V_42 ++ ;
}
V_21 -> V_325 = F_7 ( V_42 ) ;
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_322 ) ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_320 , 0 , V_21 ,
V_22 ) ;
F_15 ( V_21 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_141 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_326 * V_113 )
{
struct V_102 * V_7 ;
int V_15 ;
V_7 = F_67 ( V_5 , V_327 , V_27 , V_113 ,
sizeof( * V_113 ) ) ;
if ( ! V_7 )
return - V_17 ;
V_15 = F_106 ( V_27 , V_328 ,
sizeof( V_113 -> V_294 . V_174 ) , & V_113 -> V_294 . V_174 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
return V_15 ;
}
static int F_142 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_185 * V_186 ;
struct V_329 * V_113 = V_25 ;
struct V_330 V_331 ;
struct V_102 * V_7 ;
int V_15 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_332 ,
V_238 ) ;
goto V_214;
}
V_186 = F_138 ( V_27 , V_204 , & V_113 -> V_294 . V_174 ) ;
if ( ! V_186 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_332 ,
V_314 ) ;
goto V_214;
}
if ( V_186 -> V_333 == V_334 && V_113 -> V_296 != 16 ) {
struct V_326 V_335 ;
memcpy ( & V_335 . V_294 , & V_113 -> V_294 , sizeof( V_335 . V_294 ) ) ;
F_128 ( L_13 ) ;
V_15 = F_141 ( V_5 , V_27 , & V_335 ) ;
if ( V_15 >= 0 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_332 ,
V_212 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_332 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
F_63 ( & V_331 . V_174 , & V_113 -> V_294 . V_174 ) ;
V_331 . V_296 = V_113 -> V_296 ;
memcpy ( V_331 . V_336 , V_113 -> V_336 , sizeof( V_331 . V_336 ) ) ;
V_15 = F_106 ( V_27 , V_337 , sizeof( V_331 ) , & V_331 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_143 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_338 * V_113 = V_25 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
V_27 -> V_339 = V_113 -> V_339 ;
F_4 ( L_14 , V_27 -> V_148 ,
V_27 -> V_339 ) ;
F_54 ( V_27 ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_340 , 0 , NULL ,
0 ) ;
}
static struct V_102 * F_144 ( struct V_185 * V_186 )
{
struct V_26 * V_27 = V_186 -> V_27 ;
struct V_102 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 != V_341 )
continue;
if ( V_7 -> V_342 != V_186 )
continue;
return V_7 ;
}
return NULL ;
}
static void F_145 ( struct V_102 * V_7 , T_1 V_8 )
{
struct V_343 V_21 ;
struct V_185 * V_186 = V_7 -> V_342 ;
F_63 ( & V_21 . V_294 . V_174 , & V_186 -> V_206 ) ;
V_21 . V_294 . type = F_139 ( V_186 -> type , V_186 -> V_323 ) ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_341 , V_8 ,
& V_21 , sizeof( V_21 ) ) ;
V_186 -> V_344 = NULL ;
V_186 -> V_345 = NULL ;
V_186 -> V_346 = NULL ;
F_146 ( V_186 ) ;
F_73 ( V_7 ) ;
}
void F_147 ( struct V_185 * V_186 , bool V_347 )
{
T_1 V_8 = V_347 ? V_227 : V_3 ;
struct V_102 * V_7 ;
V_7 = F_144 ( V_186 ) ;
if ( V_7 )
F_145 ( V_7 , V_8 ) ;
}
static void F_148 ( struct V_185 * V_186 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_15 , V_8 ) ;
V_7 = F_144 ( V_186 ) ;
if ( ! V_7 )
F_4 ( L_16 ) ;
else
F_145 ( V_7 , F_1 ( V_8 ) ) ;
}
static void F_149 ( struct V_185 * V_186 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_15 , V_8 ) ;
if ( ! V_8 )
return;
V_7 = F_144 ( V_186 ) ;
if ( ! V_7 )
F_4 ( L_16 ) ;
else
F_145 ( V_7 , F_1 ( V_8 ) ) ;
}
static int F_150 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_348 * V_113 = V_25 ;
struct V_343 V_21 ;
struct V_102 * V_7 ;
T_1 V_349 , V_350 ;
struct V_185 * V_186 ;
int V_15 ;
F_4 ( L_6 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_294 . V_174 , & V_113 -> V_294 . V_174 ) ;
V_21 . V_294 . type = V_113 -> V_294 . type ;
if ( ! F_133 ( V_113 -> V_294 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_341 ,
V_212 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_341 ,
V_238 , & V_21 , sizeof( V_21 ) ) ;
goto V_229;
}
V_349 = V_351 ;
if ( V_113 -> V_352 == 0x03 )
V_350 = V_353 ;
else
V_350 = V_354 ;
if ( V_113 -> V_294 . type == V_295 ) {
V_186 = F_151 ( V_27 , & V_113 -> V_294 . V_174 , V_349 ,
V_350 ) ;
} else {
T_1 V_297 ;
if ( V_113 -> V_294 . type == V_304 )
V_297 = V_305 ;
else
V_297 = V_306 ;
V_186 = F_152 ( V_27 , & V_113 -> V_294 . V_174 , V_297 ,
V_349 , V_350 ) ;
}
if ( F_153 ( V_186 ) ) {
int V_8 ;
if ( F_154 ( V_186 ) == - V_355 )
V_8 = V_213 ;
else
V_8 = V_356 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_341 ,
V_8 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_229;
}
if ( V_186 -> V_344 ) {
F_146 ( V_186 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_341 ,
V_213 , & V_21 , sizeof( V_21 ) ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_341 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
F_146 ( V_186 ) ;
goto V_229;
}
if ( V_113 -> V_294 . type == V_295 ) {
V_186 -> V_344 = F_148 ;
V_186 -> V_345 = F_148 ;
V_186 -> V_346 = F_148 ;
} else {
V_186 -> V_344 = F_149 ;
V_186 -> V_345 = F_149 ;
V_186 -> V_346 = F_149 ;
}
V_186 -> V_339 = V_113 -> V_352 ;
V_7 -> V_342 = V_186 ;
if ( V_186 -> V_196 == V_197 &&
F_155 ( V_186 , V_349 , V_350 ) )
F_145 ( V_7 , 0 ) ;
V_15 = 0 ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_156 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_322 * V_294 = V_25 ;
struct V_102 * V_7 ;
struct V_185 * V_186 ;
int V_15 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_357 ,
V_238 ) ;
goto V_229;
}
V_7 = F_32 ( V_341 , V_27 ) ;
if ( ! V_7 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_357 ,
V_212 ) ;
goto V_229;
}
V_186 = V_7 -> V_342 ;
if ( F_157 ( & V_294 -> V_174 , & V_186 -> V_206 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_357 ,
V_212 ) ;
goto V_229;
}
F_145 ( V_7 , V_358 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_357 , 0 ,
V_294 , sizeof( * V_294 ) ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_158 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_322 * V_294 , T_2 V_276 ,
T_2 V_359 , T_7 V_360 )
{
struct V_102 * V_7 ;
struct V_185 * V_186 ;
int V_15 ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_276 ,
V_238 , V_294 ,
sizeof( * V_294 ) ) ;
goto V_361;
}
if ( V_294 -> type == V_295 )
V_186 = F_138 ( V_27 , V_204 , & V_294 -> V_174 ) ;
else
V_186 = F_138 ( V_27 , V_171 , & V_294 -> V_174 ) ;
if ( ! V_186 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_276 ,
V_314 , V_294 ,
sizeof( * V_294 ) ) ;
goto V_361;
}
if ( V_294 -> type == V_304 || V_294 -> type == V_317 ) {
V_15 = F_159 ( V_186 , V_276 , V_360 ) ;
if ( ! V_15 )
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_276 ,
V_227 , V_294 ,
sizeof( * V_294 ) ) ;
else
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_276 ,
V_3 , V_294 ,
sizeof( * V_294 ) ) ;
goto V_361;
}
V_7 = F_67 ( V_5 , V_276 , V_27 , V_294 , sizeof( * V_294 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_361;
}
if ( V_359 == V_362 ) {
struct V_363 V_113 ;
F_63 ( & V_113 . V_174 , & V_294 -> V_174 ) ;
V_113 . V_360 = V_360 ;
V_15 = F_106 ( V_27 , V_359 , sizeof( V_113 ) , & V_113 ) ;
} else
V_15 = F_106 ( V_27 , V_359 , sizeof( V_294 -> V_174 ) ,
& V_294 -> V_174 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_361:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_160 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_326 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_158 ( V_5 , V_27 , & V_113 -> V_294 ,
V_327 ,
V_328 , 0 ) ;
}
static int F_161 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_364 * V_113 = V_25 ;
F_4 ( L_6 ) ;
if ( V_20 != sizeof( * V_113 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_365 ,
V_212 ) ;
return F_158 ( V_5 , V_27 , & V_113 -> V_294 ,
V_365 ,
V_366 , 0 ) ;
}
static int F_162 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_367 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_158 ( V_5 , V_27 , & V_113 -> V_294 ,
V_368 ,
V_369 , 0 ) ;
}
static int F_163 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_370 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_158 ( V_5 , V_27 , & V_113 -> V_294 ,
V_371 ,
V_362 , V_113 -> V_360 ) ;
}
static int F_164 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_372 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_158 ( V_5 , V_27 , & V_113 -> V_294 ,
V_373 ,
V_374 , 0 ) ;
}
static void F_165 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_375 V_113 ;
memcpy ( V_113 . V_148 , V_27 -> V_105 , sizeof( V_113 . V_148 ) ) ;
F_35 ( V_111 , V_376 , sizeof( V_113 ) , & V_113 ) ;
}
static void F_166 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_377 * V_113 ;
struct V_102 * V_7 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_378 , V_27 ) ;
if ( ! V_7 )
goto V_229;
V_113 = V_7 -> V_120 ;
if ( V_8 )
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_378 ,
F_1 ( V_8 ) ) ;
else
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_378 , 0 ,
V_113 , sizeof( * V_113 ) ) ;
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
}
static int F_167 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_377 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! memcmp ( V_27 -> V_105 , V_113 -> V_148 , sizeof( V_27 -> V_105 ) ) &&
! memcmp ( V_27 -> V_178 , V_113 -> V_178 ,
sizeof( V_27 -> V_178 ) ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_378 , 0 ,
V_25 , V_20 ) ;
goto V_214;
}
memcpy ( V_27 -> V_178 , V_113 -> V_178 , sizeof( V_27 -> V_178 ) ) ;
if ( ! F_27 ( V_27 ) ) {
memcpy ( V_27 -> V_105 , V_113 -> V_148 , sizeof( V_27 -> V_105 ) ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_378 , 0 ,
V_25 , V_20 ) ;
if ( V_15 < 0 )
goto V_214;
V_15 = F_85 ( V_379 , V_27 , V_25 , V_20 ,
V_5 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_378 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
memcpy ( V_27 -> V_105 , V_113 -> V_148 , sizeof( V_27 -> V_105 ) ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_22 ( V_27 ) ) {
F_165 ( & V_111 ) ;
F_40 ( & V_111 ) ;
}
if ( F_25 ( V_27 ) )
F_34 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_166 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_168 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_102 * V_7 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_380 ,
V_238 ) ;
goto V_229;
}
if ( ! F_23 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_380 ,
V_225 ) ;
goto V_229;
}
if ( F_32 ( V_380 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_380 ,
V_213 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_380 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
if ( F_20 ( V_86 , & V_27 -> V_53 ) )
V_15 = F_106 ( V_27 , V_381 ,
0 , NULL ) ;
else
V_15 = F_106 ( V_27 , V_382 , 0 , NULL ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_169 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
int V_15 ;
F_4 ( L_17 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( V_20 == V_383 ) {
struct V_384 * V_113 = V_25 ;
T_1 V_8 ;
V_15 = F_170 ( V_27 , & V_113 -> V_294 . V_174 ,
V_113 -> V_385 , V_113 -> V_386 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_227 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_387 ,
V_8 , & V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
} else if ( V_20 == V_388 ) {
struct V_389 * V_113 = V_25 ;
T_1 V_8 ;
V_15 = F_171 ( V_27 , & V_113 -> V_294 . V_174 ,
V_113 -> V_390 ,
V_113 -> V_391 ,
V_113 -> V_392 ,
V_113 -> V_393 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_227 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_387 ,
V_8 , & V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
} else {
F_128 ( L_18 , V_20 ) ;
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_387 ,
V_212 ) ;
}
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_172 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_394 * V_113 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
V_15 = F_173 ( V_27 , & V_113 -> V_294 . V_174 ) ;
if ( V_15 < 0 )
V_8 = V_212 ;
else
V_8 = V_227 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_395 ,
V_8 , & V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_174 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
T_1 type ;
int V_15 ;
F_175 ( V_27 , V_396 ) ;
V_7 = F_32 ( V_397 , V_27 ) ;
if ( ! V_7 )
return - V_398 ;
type = V_27 -> V_399 . type ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& type , sizeof( type ) ) ;
F_73 ( V_7 ) ;
return V_15 ;
}
static void F_176 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_19 , V_8 ) ;
if ( V_8 ) {
F_53 ( V_27 ) ;
F_174 ( V_27 , V_8 ) ;
F_54 ( V_27 ) ;
return;
}
F_53 ( V_27 ) ;
F_175 ( V_27 , V_400 ) ;
F_54 ( V_27 ) ;
switch ( V_27 -> V_399 . type ) {
case V_401 :
F_84 ( V_27 -> V_234 , & V_27 -> V_402 ,
V_403 ) ;
break;
case V_404 :
F_84 ( V_27 -> V_234 , & V_27 -> V_402 ,
V_405 ) ;
break;
case V_406 :
break;
default:
F_128 ( L_20 , V_27 -> V_399 . type ) ;
}
}
static int F_177 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_407 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_408 V_409 ;
struct V_410 V_411 ;
struct V_412 V_413 ;
struct V_110 V_111 ;
T_1 V_414 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
T_1 V_8 , V_155 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_238 ) ;
goto V_214;
}
if ( F_20 ( V_415 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_213 ) ;
goto V_214;
}
if ( V_27 -> V_399 . V_196 != V_396 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_213 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_397 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
V_27 -> V_399 . type = V_113 -> type ;
F_52 ( & V_111 , V_27 ) ;
switch ( V_27 -> V_399 . type ) {
case V_406 :
V_8 = F_91 ( V_27 ) ;
if ( V_8 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_8 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
if ( F_20 ( V_416 , & V_27 -> V_125 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_213 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
F_178 ( V_27 ) ;
memset ( & V_413 , 0 , sizeof( V_413 ) ) ;
memcpy ( & V_413 . V_414 , V_414 , sizeof( V_413 . V_414 ) ) ;
V_413 . V_116 = V_417 ;
F_35 ( & V_111 , V_418 , sizeof( V_413 ) , & V_413 ) ;
break;
case V_401 :
case V_404 :
V_8 = F_92 ( V_27 ) ;
if ( V_8 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_8 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
if ( V_27 -> V_399 . type == V_404 &&
! F_20 ( V_80 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_225 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
if ( F_20 ( V_85 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_226 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
if ( F_20 ( V_191 , & V_27 -> V_53 ) )
F_81 ( & V_111 ) ;
memset ( & V_409 , 0 , sizeof( V_409 ) ) ;
V_15 = F_47 ( & V_111 , true , & V_155 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_3 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
V_409 . type = V_419 ;
V_409 . V_250 = F_7 ( V_420 ) ;
V_409 . V_252 = F_7 ( V_421 ) ;
V_409 . V_162 = V_155 ;
F_35 ( & V_111 , V_422 , sizeof( V_409 ) ,
& V_409 ) ;
memset ( & V_411 , 0 , sizeof( V_411 ) ) ;
V_411 . V_156 = V_423 ;
V_411 . V_424 = V_425 ;
F_35 ( & V_111 , V_426 , sizeof( V_411 ) ,
& V_411 ) ;
break;
default:
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_397 ,
V_212 ) ;
F_73 ( V_7 ) ;
goto V_214;
}
V_15 = F_55 ( & V_111 , F_176 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
else
F_175 ( V_27 , V_427 ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_179 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
int V_15 ;
V_7 = F_32 ( V_428 , V_27 ) ;
if ( ! V_7 )
return - V_398 ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& V_27 -> V_399 . type , sizeof( V_27 -> V_399 . type ) ) ;
F_73 ( V_7 ) ;
return V_15 ;
}
static void F_180 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_19 , V_8 ) ;
F_53 ( V_27 ) ;
if ( V_8 ) {
F_179 ( V_27 , V_8 ) ;
goto V_229;
}
F_175 ( V_27 , V_396 ) ;
V_229:
F_54 ( V_27 ) ;
}
static int F_181 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_429 * V_430 = V_25 ;
struct V_102 * V_7 ;
struct V_431 V_113 ;
struct V_432 * V_433 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_182 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_428 ,
V_226 , & V_430 -> type ,
sizeof( V_430 -> type ) ) ;
goto V_229;
}
if ( V_27 -> V_399 . type != V_430 -> type ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_428 ,
V_212 , & V_430 -> type ,
sizeof( V_430 -> type ) ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_428 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
F_52 ( & V_111 , V_27 ) ;
switch ( V_27 -> V_399 . V_196 ) {
case V_400 :
if ( F_20 ( V_416 , & V_27 -> V_125 ) ) {
F_35 ( & V_111 , V_434 , 0 , NULL ) ;
} else {
F_78 ( & V_27 -> V_402 ) ;
F_81 ( & V_111 ) ;
}
break;
case V_435 :
V_433 = F_183 ( V_27 , V_436 ,
V_437 ) ;
if ( ! V_433 ) {
F_73 ( V_7 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 ,
V_428 , 0 ,
& V_430 -> type ,
sizeof( V_430 -> type ) ) ;
F_175 ( V_27 , V_396 ) ;
goto V_229;
}
F_63 ( & V_113 . V_174 , & V_433 -> V_25 . V_174 ) ;
F_35 ( & V_111 , V_438 , sizeof( V_113 ) ,
& V_113 ) ;
break;
default:
F_4 ( L_21 , V_27 -> V_399 . V_196 ) ;
F_73 ( V_7 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_428 ,
V_3 , & V_430 -> type ,
sizeof( V_430 -> type ) ) ;
goto V_229;
}
V_15 = F_55 ( & V_111 , F_180 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
else
F_175 ( V_27 , V_439 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_184 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_440 * V_113 = V_25 ;
struct V_432 * V_433 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_182 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_441 ,
V_3 , & V_113 -> V_294 ,
sizeof( V_113 -> V_294 ) ) ;
goto V_214;
}
V_433 = F_185 ( V_27 , & V_113 -> V_294 . V_174 ) ;
if ( ! V_433 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_441 ,
V_212 , & V_113 -> V_294 ,
sizeof( V_113 -> V_294 ) ) ;
goto V_214;
}
if ( V_113 -> V_442 ) {
V_433 -> V_443 = V_444 ;
F_74 ( & V_433 -> V_180 ) ;
} else {
V_433 -> V_443 = V_445 ;
F_186 ( V_27 , V_433 ) ;
}
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_441 , 0 , & V_113 -> V_294 ,
sizeof( V_113 -> V_294 ) ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_187 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_446 * V_113 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_133 ( V_113 -> V_294 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_447 ,
V_212 ,
& V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
F_53 ( V_27 ) ;
V_15 = F_188 ( V_27 , & V_113 -> V_294 . V_174 , V_113 -> V_294 . type ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_227 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_447 , V_8 ,
& V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_189 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_448 * V_113 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_133 ( V_113 -> V_294 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_449 ,
V_212 ,
& V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
F_53 ( V_27 ) ;
V_15 = F_190 ( V_27 , & V_113 -> V_294 . V_174 , V_113 -> V_294 . type ) ;
if ( V_15 < 0 )
V_8 = V_212 ;
else
V_8 = V_227 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_449 , V_8 ,
& V_113 -> V_294 , sizeof( V_113 -> V_294 ) ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_191 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_450 * V_113 = V_25 ;
struct V_110 V_111 ;
int V_15 ;
T_9 V_451 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
V_451 = F_96 ( V_113 -> V_451 ) ;
if ( V_451 > 0x0002 )
return F_3 ( V_5 , V_27 -> V_55 , V_452 ,
V_212 ) ;
F_53 ( V_27 ) ;
V_27 -> V_136 = V_451 ;
V_27 -> V_138 = F_96 ( V_113 -> V_453 ) ;
V_27 -> V_139 = F_96 ( V_113 -> V_454 ) ;
V_27 -> V_140 = F_96 ( V_113 -> V_30 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_452 , 0 , NULL , 0 ) ;
F_52 ( & V_111 , V_27 ) ;
F_40 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_192 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 } ;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
F_70 ( V_268 , V_27 ,
F_90 , & V_230 ) ;
return;
}
F_70 ( V_268 , V_27 , F_89 ,
& V_224 ) ;
F_88 ( V_27 , V_224 . V_5 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
}
static int F_193 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
T_1 V_121 , V_267 , V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_92 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_268 ,
V_8 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_268 ,
V_212 ) ;
F_53 ( V_27 ) ;
V_121 = ! ! V_113 -> V_121 ;
V_267 = F_20 ( V_85 , & V_27 -> V_53 ) ;
if ( ! F_27 ( V_27 ) || V_121 == V_267 ||
F_58 ( V_27 , V_171 ) > 0 ) {
bool V_228 = false ;
if ( V_121 != F_20 ( V_85 , & V_27 -> V_53 ) ) {
F_97 ( V_85 , & V_27 -> V_53 ) ;
V_228 = true ;
}
V_15 = F_75 ( V_5 , V_268 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_229;
}
if ( F_32 ( V_268 , V_27 ) ||
F_32 ( V_265 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_268 ,
V_213 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_268 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
F_52 ( & V_111 , V_27 ) ;
if ( V_121 )
F_45 ( & V_111 ) ;
else
F_48 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_192 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_194 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_455 * V_113 = V_25 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_456 ,
V_225 ) ;
if ( F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_456 ,
V_226 ) ;
if ( F_157 ( & V_113 -> V_174 , V_436 ) ) {
if ( ! F_157 ( & V_113 -> V_174 , V_457 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_456 ,
V_212 ) ;
if ( ( V_113 -> V_174 . V_458 [ 5 ] & 0xc0 ) != 0xc0 )
return F_3 ( V_5 , V_27 -> V_55 ,
V_456 ,
V_212 ) ;
}
F_53 ( V_27 ) ;
F_63 ( & V_27 -> V_459 , & V_113 -> V_174 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_456 , 0 , NULL , 0 ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_195 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_460 * V_113 = V_25 ;
T_9 V_250 , V_252 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_461 ,
V_225 ) ;
V_250 = F_96 ( V_113 -> V_250 ) ;
if ( V_250 < 0x0004 || V_250 > 0x4000 )
return F_3 ( V_5 , V_27 -> V_55 , V_461 ,
V_212 ) ;
V_252 = F_96 ( V_113 -> V_252 ) ;
if ( V_252 < 0x0004 || V_252 > 0x4000 )
return F_3 ( V_5 , V_27 -> V_55 , V_461 ,
V_212 ) ;
if ( V_252 > V_250 )
return F_3 ( V_5 , V_27 -> V_55 , V_461 ,
V_212 ) ;
F_53 ( V_27 ) ;
V_27 -> V_462 = V_250 ;
V_27 -> V_463 = V_252 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_461 , 0 , NULL , 0 ) ;
if ( F_20 ( V_191 , & V_27 -> V_53 ) &&
V_27 -> V_399 . V_196 == V_396 ) {
struct V_110 V_111 ;
F_52 ( & V_111 , V_27 ) ;
F_81 ( & V_111 ) ;
F_196 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
}
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_197 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_464 , V_27 ) ;
if ( ! V_7 )
goto V_229;
if ( V_8 ) {
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_464 ,
F_1 ( V_8 ) ) ;
} else {
struct V_119 * V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 )
F_57 ( V_77 , & V_27 -> V_53 ) ;
else
F_46 ( V_77 , & V_27 -> V_53 ) ;
F_75 ( V_7 -> V_5 , V_464 , V_27 ) ;
F_88 ( V_27 , V_7 -> V_5 ) ;
}
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
}
static int F_198 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) ||
V_27 -> V_63 < V_64 )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_225 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_212 ) ;
if ( ! F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_238 ) ;
if ( ! F_20 ( V_76 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_226 ) ;
F_53 ( V_27 ) ;
if ( F_32 ( V_464 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_213 ) ;
goto V_229;
}
if ( ! ! V_113 -> V_121 == F_20 ( V_77 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_464 ,
V_27 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_464 , V_27 ,
V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
F_52 ( & V_111 , V_27 ) ;
F_99 ( & V_111 , V_113 -> V_121 ) ;
V_15 = F_55 ( & V_111 , F_197 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_3 ) ;
F_73 ( V_7 ) ;
}
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_199 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
T_1 V_189 = 0 ;
F_99 ( V_111 , false ) ;
if ( F_20 ( V_76 , & V_27 -> V_53 ) )
V_189 |= V_240 ;
if ( F_20 ( V_78 , & V_27 -> V_53 ) )
V_189 |= V_246 ;
if ( V_189 )
F_35 ( V_111 , V_190 , 1 , & V_189 ) ;
}
static void F_200 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_465 , V_27 ) ;
if ( ! V_7 )
goto V_229;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
F_46 ( V_80 , & V_27 -> V_53 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_230 ) ;
} else {
F_75 ( V_7 -> V_5 , V_465 , V_27 ) ;
F_88 ( V_27 , V_7 -> V_5 ) ;
}
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
}
static int F_201 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_22 ( V_27 ) || ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_225 ) ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_226 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 == F_20 ( V_80 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_465 , V_27 ) ;
goto V_229;
}
if ( ! F_27 ( V_27 ) ) {
if ( ! V_113 -> V_121 ) {
F_46 ( V_78 , & V_27 -> V_53 ) ;
F_46 ( V_83 , & V_27 -> V_53 ) ;
F_46 ( V_82 , & V_27 -> V_53 ) ;
F_46 ( V_77 , & V_27 -> V_53 ) ;
F_46 ( V_84 , & V_27 -> V_53 ) ;
}
F_97 ( V_80 , & V_27 -> V_53 ) ;
V_15 = F_75 ( V_5 , V_465 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_229;
}
if ( ! V_113 -> V_121 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_226 ) ;
goto V_229;
}
if ( F_32 ( V_465 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_213 ) ;
goto V_229;
}
V_7 = F_67 ( V_5 , V_465 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_229;
}
F_57 ( V_80 , & V_27 -> V_53 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_76 , & V_27 -> V_53 ) )
F_199 ( & V_111 ) ;
F_38 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_200 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_202 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
T_1 V_121 , V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_91 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_466 ,
V_8 ) ;
if ( ! F_24 ( V_27 ) &&
! F_20 ( V_71 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_466 ,
V_225 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 && V_113 -> V_121 != 0x02 )
return F_3 ( V_5 , V_27 -> V_55 , V_466 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_228 ;
if ( V_113 -> V_121 ) {
V_228 = ! F_60 ( V_86 ,
& V_27 -> V_53 ) ;
if ( V_113 -> V_121 == 0x02 )
F_57 ( V_467 , & V_27 -> V_53 ) ;
else
F_46 ( V_467 , & V_27 -> V_53 ) ;
} else {
V_228 = F_51 ( V_86 ,
& V_27 -> V_53 ) ;
F_46 ( V_467 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_466 , V_27 ) ;
if ( V_15 < 0 )
goto V_214;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
goto V_214;
}
if ( F_32 ( V_466 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_466 ,
V_213 ) ;
goto V_214;
}
V_121 = ! ! V_113 -> V_121 ;
if ( V_121 == F_20 ( V_86 , & V_27 -> V_53 ) &&
( V_113 -> V_121 == 0x02 ) == F_20 ( V_467 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_466 , V_27 ) ;
goto V_214;
}
V_7 = F_67 ( V_5 , V_466 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_214;
}
V_15 = F_106 ( V_27 , V_468 , 1 , & V_121 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
goto V_214;
}
if ( V_113 -> V_121 == 0x02 )
F_57 ( V_467 , & V_27 -> V_53 ) ;
else
F_46 ( V_467 , & V_27 -> V_53 ) ;
V_214:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_203 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
bool V_228 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_469 ,
V_212 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 )
V_228 = ! F_60 ( V_87 , & V_27 -> V_53 ) ;
else
V_228 = F_51 ( V_87 , & V_27 -> V_53 ) ;
V_15 = F_75 ( V_5 , V_469 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_204 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_470 ,
T_2 V_20 )
{
struct V_471 * V_113 = V_470 ;
bool V_228 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_472 ,
V_225 ) ;
if ( V_113 -> V_473 != 0x00 && V_113 -> V_473 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_472 ,
V_212 ) ;
if ( F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_472 ,
V_226 ) ;
F_53 ( V_27 ) ;
F_57 ( V_474 , & V_27 -> V_53 ) ;
if ( V_113 -> V_473 ) {
V_228 = ! F_60 ( V_88 , & V_27 -> V_53 ) ;
memcpy ( V_27 -> V_475 , V_113 -> V_475 , sizeof( V_27 -> V_475 ) ) ;
F_57 ( V_170 , & V_27 -> V_53 ) ;
} else {
V_228 = F_51 ( V_88 , & V_27 -> V_53 ) ;
memset ( V_27 -> V_475 , 0 , sizeof( V_27 -> V_475 ) ) ;
F_46 ( V_170 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_472 , V_27 ) ;
if ( V_15 < 0 )
goto V_229;
if ( V_228 )
V_15 = F_88 ( V_27 , V_5 ) ;
V_229:
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_205 ( struct V_476 * V_475 )
{
switch ( V_475 -> V_294 . type ) {
case V_304 :
return true ;
case V_317 :
if ( ( V_475 -> V_294 . V_174 . V_458 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_206 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_470 ,
T_2 V_20 )
{
struct V_477 * V_113 = V_470 ;
T_2 V_478 , V_288 ;
int V_42 , V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_479 ,
V_225 ) ;
V_478 = F_96 ( V_113 -> V_478 ) ;
V_288 = sizeof( * V_113 ) + V_478 * sizeof( struct V_476 ) ;
if ( V_288 != V_20 ) {
F_128 ( L_22 ,
V_288 , V_20 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_479 ,
V_212 ) ;
}
F_4 ( L_23 , V_27 -> V_148 , V_478 ) ;
for ( V_42 = 0 ; V_42 < V_478 ; V_42 ++ ) {
struct V_476 * V_292 = & V_113 -> V_480 [ V_42 ] ;
if ( ! F_205 ( V_292 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_479 ,
V_212 ) ;
}
F_53 ( V_27 ) ;
F_207 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_478 ; V_42 ++ ) {
struct V_476 * V_475 = & V_113 -> V_480 [ V_42 ] ;
T_1 V_297 ;
if ( V_475 -> V_294 . type == V_304 )
V_297 = V_305 ;
else
V_297 = V_306 ;
F_208 ( V_27 , & V_475 -> V_294 . V_174 , V_297 , V_475 -> V_121 ,
V_436 ) ;
}
F_57 ( V_474 , & V_27 -> V_53 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_479 , 0 , NULL , 0 ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_209 ( struct V_481 * V_292 )
{
if ( V_292 -> V_482 != 0x00 && V_292 -> V_482 != 0x01 )
return false ;
switch ( V_292 -> V_294 . type ) {
case V_304 :
return true ;
case V_317 :
if ( ( V_292 -> V_294 . V_174 . V_458 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_210 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_470 , T_2 V_20 )
{
struct V_483 * V_113 = V_470 ;
T_2 V_287 , V_288 ;
int V_42 , V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_484 ,
V_225 ) ;
V_287 = F_96 ( V_113 -> V_287 ) ;
V_288 = sizeof( * V_113 ) + V_287 *
sizeof( struct V_481 ) ;
if ( V_288 != V_20 ) {
F_128 ( L_24 ,
V_288 , V_20 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_484 ,
V_212 ) ;
}
F_4 ( L_25 , V_27 -> V_148 , V_287 ) ;
for ( V_42 = 0 ; V_42 < V_287 ; V_42 ++ ) {
struct V_481 * V_292 = & V_113 -> V_293 [ V_42 ] ;
if ( ! F_209 ( V_292 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_484 ,
V_212 ) ;
}
F_53 ( V_27 ) ;
F_211 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_287 ; V_42 ++ ) {
struct V_481 * V_292 = & V_113 -> V_293 [ V_42 ] ;
T_1 type , V_297 ;
if ( V_292 -> V_294 . type == V_304 )
V_297 = V_305 ;
else
V_297 = V_306 ;
if ( V_292 -> V_482 )
type = V_485 ;
else
type = V_486 ;
F_212 ( V_27 , & V_292 -> V_294 . V_174 , V_297 , type ,
V_292 -> type , V_292 -> V_121 , V_292 -> V_487 , V_292 -> V_488 ,
V_292 -> rand ) ;
}
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_484 , 0 ,
NULL , 0 ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
int F_213 ( struct V_4 * V_5 , struct V_489 * V_490 , T_3 V_491 )
{
void * V_492 ;
T_1 * V_113 ;
struct V_11 * V_12 ;
T_2 V_18 , V_6 , V_20 ;
struct V_26 * V_27 = NULL ;
const struct V_493 * V_494 ;
int V_15 ;
F_4 ( L_26 , V_491 ) ;
if ( V_491 < sizeof( * V_12 ) )
return - V_495 ;
V_492 = F_13 ( V_491 , V_16 ) ;
if ( ! V_492 )
return - V_17 ;
if ( F_214 ( V_492 , V_490 -> V_496 , V_491 ) ) {
V_15 = - V_497 ;
goto V_361;
}
V_12 = V_492 ;
V_18 = F_96 ( V_12 -> V_18 ) ;
V_6 = F_96 ( V_12 -> V_6 ) ;
V_20 = F_96 ( V_12 -> V_20 ) ;
if ( V_20 != V_491 - sizeof( * V_12 ) ) {
V_15 = - V_495 ;
goto V_361;
}
if ( V_6 != V_34 ) {
V_27 = F_215 ( V_6 ) ;
if ( ! V_27 ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_498 ) ;
goto V_361;
}
if ( F_20 ( V_52 , & V_27 -> V_53 ) ||
F_20 ( V_54 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_498 ) ;
goto V_361;
}
}
if ( V_18 >= F_2 ( V_499 ) ||
V_499 [ V_18 ] . V_500 == NULL ) {
F_4 ( L_27 , V_18 ) ;
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_501 ) ;
goto V_361;
}
if ( ( V_27 && V_18 < V_179 ) ||
( ! V_27 && V_18 >= V_179 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_498 ) ;
goto V_361;
}
V_494 = & V_499 [ V_18 ] ;
if ( ( V_494 -> V_502 && V_20 < V_494 -> V_28 ) ||
( ! V_494 -> V_502 && V_20 != V_494 -> V_28 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_212 ) ;
goto V_361;
}
if ( V_27 )
F_59 ( V_5 , V_27 ) ;
V_113 = V_492 + sizeof( * V_12 ) ;
V_15 = V_494 -> V_500 ( V_5 , V_27 , V_113 , V_20 ) ;
if ( V_15 < 0 )
goto V_361;
V_15 = V_491 ;
V_361:
if ( V_27 )
F_216 ( V_27 ) ;
F_15 ( V_492 ) ;
return V_15 ;
}
void F_217 ( struct V_26 * V_27 )
{
if ( V_27 -> V_49 != V_50 )
return;
F_85 ( V_503 , V_27 , NULL , 0 , NULL ) ;
}
void F_218 ( struct V_26 * V_27 )
{
T_1 V_8 = V_498 ;
if ( V_27 -> V_49 != V_50 )
return;
F_70 ( 0 , V_27 , F_90 , & V_8 ) ;
F_85 ( V_504 , V_27 , NULL , 0 , NULL ) ;
}
static void F_219 ( struct V_26 * V_27 )
{
struct V_505 * V_506 ;
F_18 (p, &hdev->le_conn_params, list) {
if ( V_506 -> V_507 == V_508 )
F_220 ( V_27 , & V_506 -> V_294 , V_506 -> V_297 ) ;
}
}
static void F_221 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 } ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
F_219 ( V_27 ) ;
F_70 ( V_211 , V_27 , F_89 , & V_224 ) ;
F_88 ( V_27 , V_224 . V_5 ) ;
F_54 ( V_27 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
}
static int F_222 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
T_1 V_509 ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_83 , & V_27 -> V_53 ) &&
! F_223 ( V_27 ) ) {
T_1 V_510 = 1 ;
F_35 ( & V_111 , V_264 , 1 , & V_510 ) ;
}
if ( F_20 ( V_81 , & V_27 -> V_53 ) &&
F_22 ( V_27 ) ) {
struct V_266 V_113 ;
V_113 . V_269 = 1 ;
V_113 . V_270 = F_112 ( V_27 ) ;
if ( V_113 . V_269 != F_111 ( V_27 ) ||
V_113 . V_270 != F_224 ( V_27 ) )
F_35 ( & V_111 , V_271 ,
sizeof( V_113 ) , & V_113 ) ;
}
if ( F_25 ( V_27 ) ) {
if ( F_20 ( V_81 , & V_27 -> V_53 ) ) {
F_38 ( & V_111 ) ;
F_34 ( & V_111 ) ;
}
if ( F_20 ( V_85 , & V_27 -> V_53 ) )
F_45 ( & V_111 ) ;
}
V_509 = F_20 ( V_82 , & V_27 -> V_53 ) ;
if ( V_509 != F_20 ( V_260 , & V_27 -> V_125 ) )
F_35 ( & V_111 , V_261 ,
sizeof( V_509 ) , & V_509 ) ;
if ( F_22 ( V_27 ) ) {
if ( F_20 ( V_80 , & V_27 -> V_53 ) )
F_199 ( & V_111 ) ;
F_43 ( & V_111 ) ;
F_165 ( & V_111 ) ;
F_40 ( & V_111 ) ;
}
return F_55 ( & V_111 , F_221 ) ;
}
int F_83 ( struct V_26 * V_27 , T_1 V_511 )
{
struct V_223 V_224 = { NULL , V_27 } ;
T_1 V_512 = V_238 ;
T_1 V_513 [] = { 0 , 0 , 0 } ;
int V_15 ;
if ( ! F_20 ( V_172 , & V_27 -> V_53 ) )
return 0 ;
if ( V_511 ) {
if ( F_222 ( V_27 ) == 0 )
return 0 ;
F_70 ( V_211 , V_27 , F_89 ,
& V_224 ) ;
goto F_88;
}
F_70 ( V_211 , V_27 , F_89 , & V_224 ) ;
F_70 ( 0 , V_27 , F_90 , & V_512 ) ;
if ( memcmp ( V_27 -> V_151 , V_513 , sizeof( V_513 ) ) != 0 )
F_85 ( V_514 , V_27 ,
V_513 , sizeof( V_513 ) , NULL ) ;
F_88:
V_15 = F_88 ( V_27 , V_224 . V_5 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
return V_15 ;
}
void F_225 ( struct V_26 * V_27 , int V_15 )
{
struct V_102 * V_7 ;
T_1 V_8 ;
V_7 = F_32 ( V_211 , V_27 ) ;
if ( ! V_7 )
return;
if ( V_15 == - V_515 )
V_8 = V_516 ;
else
V_8 = V_3 ;
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_211 , V_8 ) ;
F_73 ( V_7 ) ;
}
void F_226 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
F_53 ( V_27 ) ;
F_46 ( V_124 , & V_27 -> V_53 ) ;
F_46 ( V_78 , & V_27 -> V_53 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_80 , & V_27 -> V_53 ) ) {
T_1 V_189 = V_240 ;
F_35 ( & V_111 , V_190 ,
sizeof( V_189 ) , & V_189 ) ;
}
F_43 ( & V_111 ) ;
F_38 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
V_27 -> V_232 = 0 ;
F_88 ( V_27 , NULL ) ;
F_54 ( V_27 ) ;
}
void F_227 ( struct V_26 * V_27 , T_1 V_517 )
{
bool V_228 ;
if ( F_32 ( V_118 , V_27 ) )
return;
if ( ! V_517 && F_32 ( V_211 , V_27 ) )
return;
if ( V_517 ) {
V_228 = ! F_60 ( V_78 , & V_27 -> V_53 ) ;
} else {
F_46 ( V_124 , & V_27 -> V_53 ) ;
V_228 = F_51 ( V_78 , & V_27 -> V_53 ) ;
}
if ( V_228 ) {
struct V_110 V_111 ;
F_52 ( & V_111 , V_27 ) ;
F_38 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
F_88 ( V_27 , NULL ) ;
}
}
void F_228 ( struct V_26 * V_27 , T_1 V_157 )
{
bool V_228 ;
if ( F_32 ( V_153 , V_27 ) )
return;
if ( ! V_157 && F_32 ( V_211 , V_27 ) )
return;
if ( V_157 )
V_228 = ! F_60 ( V_76 , & V_27 -> V_53 ) ;
else
V_228 = F_51 ( V_76 , & V_27 -> V_53 ) ;
if ( V_228 )
F_88 ( V_27 , NULL ) ;
}
void F_229 ( struct V_26 * V_27 , T_1 V_518 )
{
if ( ! V_518 && F_32 ( V_211 , V_27 ) )
return;
if ( V_518 )
F_57 ( V_85 , & V_27 -> V_53 ) ;
else
F_46 ( V_85 , & V_27 -> V_53 ) ;
}
void F_230 ( struct V_26 * V_27 , T_1 V_189 , T_1 V_8 )
{
T_1 V_230 = F_1 ( V_8 ) ;
if ( V_189 & V_240 )
F_70 ( V_153 , V_27 ,
F_90 , & V_230 ) ;
if ( V_189 & V_246 )
F_70 ( V_118 , V_27 ,
F_90 , & V_230 ) ;
}
void F_231 ( struct V_26 * V_27 , struct V_519 * V_292 ,
bool V_520 )
{
struct V_521 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_522 = V_520 ;
F_63 ( & V_14 . V_292 . V_294 . V_174 , & V_292 -> V_174 ) ;
V_14 . V_292 . V_294 . type = V_295 ;
V_14 . V_292 . type = V_292 -> type ;
memcpy ( V_14 . V_292 . V_121 , V_292 -> V_121 , V_523 ) ;
V_14 . V_292 . V_296 = V_292 -> V_296 ;
F_85 ( V_524 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_232 ( struct V_26 * V_27 , struct V_525 * V_292 , bool V_520 )
{
struct V_526 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( V_292 -> V_527 == V_306 &&
( V_292 -> V_174 . V_458 [ 5 ] & 0xc0 ) != 0xc0 )
V_14 . V_522 = 0x00 ;
else
V_14 . V_522 = V_520 ;
F_63 ( & V_14 . V_292 . V_294 . V_174 , & V_292 -> V_174 ) ;
V_14 . V_292 . V_294 . type = F_139 ( V_171 , V_292 -> V_527 ) ;
V_14 . V_292 . type = V_292 -> V_528 ;
V_14 . V_292 . V_487 = V_292 -> V_487 ;
V_14 . V_292 . V_488 = V_292 -> V_488 ;
V_14 . V_292 . rand = V_292 -> rand ;
if ( V_292 -> type == V_485 )
V_14 . V_292 . V_482 = 1 ;
memcpy ( V_14 . V_292 . V_121 , V_292 -> V_121 , sizeof( V_292 -> V_121 ) ) ;
F_85 ( V_529 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_233 ( struct V_26 * V_27 , struct V_530 * V_475 )
{
struct V_531 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( F_157 ( & V_475 -> V_532 , V_436 ) )
V_14 . V_522 = 0x01 ;
else
V_14 . V_522 = 0x00 ;
F_63 ( & V_14 . V_532 , & V_475 -> V_532 ) ;
F_63 ( & V_14 . V_475 . V_294 . V_174 , & V_475 -> V_174 ) ;
V_14 . V_475 . V_294 . type = F_139 ( V_171 , V_475 -> V_297 ) ;
memcpy ( V_14 . V_475 . V_121 , V_475 -> V_121 , sizeof( V_475 -> V_121 ) ) ;
F_85 ( V_533 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_234 ( struct V_26 * V_27 , struct V_534 * V_535 ,
bool V_520 )
{
struct V_536 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( V_535 -> V_527 == V_306 &&
( V_535 -> V_174 . V_458 [ 5 ] & 0xc0 ) != 0xc0 )
V_14 . V_522 = 0x00 ;
else
V_14 . V_522 = V_520 ;
F_63 ( & V_14 . V_292 . V_294 . V_174 , & V_535 -> V_174 ) ;
V_14 . V_292 . V_294 . type = F_139 ( V_171 , V_535 -> V_527 ) ;
V_14 . V_292 . V_482 = V_535 -> V_482 ;
memcpy ( V_14 . V_292 . V_121 , V_535 -> V_121 , sizeof( V_535 -> V_121 ) ) ;
F_85 ( V_537 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static inline T_2 F_235 ( T_1 * V_144 , T_2 V_538 , T_1 type , T_1 * V_25 ,
T_1 V_28 )
{
V_144 [ V_538 ++ ] = sizeof( type ) + V_28 ;
V_144 [ V_538 ++ ] = type ;
memcpy ( & V_144 [ V_538 ] , V_25 , V_28 ) ;
V_538 += V_28 ;
return V_538 ;
}
void F_236 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_316 ,
T_1 V_297 , T_5 V_125 , T_1 * V_148 , T_1 V_104 ,
T_1 * V_151 )
{
char V_492 [ 512 ] ;
struct V_539 * V_14 = ( void * ) V_492 ;
T_2 V_538 = 0 ;
F_63 ( & V_14 -> V_294 . V_174 , V_174 ) ;
V_14 -> V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 -> V_125 = F_237 ( V_125 ) ;
if ( V_104 > 0 )
V_538 = F_235 ( V_14 -> V_144 , 0 , V_109 ,
V_148 , V_104 ) ;
if ( V_151 && memcmp ( V_151 , L_28 , 3 ) != 0 )
V_538 = F_235 ( V_14 -> V_144 , V_538 ,
V_540 , V_151 , 3 ) ;
V_14 -> V_538 = F_7 ( V_538 ) ;
F_85 ( V_541 , V_27 , V_492 ,
sizeof( * V_14 ) + V_538 , NULL ) ;
}
static void F_238 ( struct V_102 * V_7 , void * V_25 )
{
struct V_308 * V_113 = V_7 -> V_120 ;
struct V_4 * * V_5 = V_25 ;
struct V_309 V_21 ;
F_63 ( & V_21 . V_294 . V_174 , & V_113 -> V_294 . V_174 ) ;
V_21 . V_294 . type = V_113 -> V_294 . type ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_310 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
* V_5 = V_7 -> V_5 ;
F_68 ( * V_5 ) ;
F_73 ( V_7 ) ;
}
static void F_239 ( struct V_102 * V_7 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_300 * V_113 = V_7 -> V_120 ;
struct V_301 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_294 . V_174 , & V_113 -> V_294 . V_174 ) ;
V_21 . V_294 . type = V_113 -> V_294 . type ;
F_131 ( V_27 , & V_113 -> V_294 . V_174 , V_113 -> V_294 . type , V_7 -> V_5 ) ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , 0 , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
void F_240 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_200 ,
bool V_542 )
{
struct V_543 V_14 ;
struct V_102 * V_183 ;
struct V_4 * V_5 = NULL ;
V_183 = F_32 ( V_211 , V_27 ) ;
if ( V_183 ) {
struct V_119 * V_113 = V_183 -> V_120 ;
if ( ! V_113 -> V_121 && F_77 ( V_27 ) == 1 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
}
}
if ( ! V_542 )
return;
if ( V_316 != V_204 && V_316 != V_171 )
return;
F_70 ( V_310 , V_27 , F_238 , & V_5 ) ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 . V_200 = V_200 ;
F_85 ( V_544 , V_27 , & V_14 , sizeof( V_14 ) , V_5 ) ;
if ( V_5 )
F_66 ( V_5 ) ;
F_70 ( V_302 , V_27 , F_239 ,
V_27 ) ;
}
void F_241 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_8 )
{
T_1 V_527 = F_139 ( V_316 , V_297 ) ;
struct V_308 * V_113 ;
struct V_309 V_21 ;
struct V_102 * V_7 ;
F_70 ( V_302 , V_27 , F_239 ,
V_27 ) ;
V_7 = F_32 ( V_310 , V_27 ) ;
if ( ! V_7 )
return;
V_113 = V_7 -> V_120 ;
if ( F_157 ( V_174 , & V_113 -> V_294 . V_174 ) )
return;
if ( V_113 -> V_294 . type != V_527 )
return;
F_63 ( & V_21 . V_294 . V_174 , V_174 ) ;
V_21 . V_294 . type = V_527 ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_310 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
void F_242 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_316 ,
T_1 V_297 , T_1 V_8 )
{
struct V_545 V_14 ;
struct V_102 * V_183 ;
V_183 = F_32 ( V_211 , V_27 ) ;
if ( V_183 ) {
struct V_119 * V_113 = V_183 -> V_120 ;
if ( ! V_113 -> V_121 && F_77 ( V_27 ) == 1 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
}
}
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
F_85 ( V_546 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_243 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_547 )
{
struct V_548 V_14 ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = V_295 ;
V_14 . V_547 = V_547 ;
F_85 ( V_549 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_244 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_550 V_21 ;
V_7 = F_32 ( V_332 , V_27 ) ;
if ( ! V_7 )
return;
F_63 ( & V_21 . V_294 . V_174 , V_174 ) ;
V_21 . V_294 . type = V_295 ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_332 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
void F_245 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_550 V_21 ;
V_7 = F_32 ( V_327 , V_27 ) ;
if ( ! V_7 )
return;
F_63 ( & V_21 . V_294 . V_174 , V_174 ) ;
V_21 . V_294 . type = V_295 ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_327 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
int F_246 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_5 V_551 ,
T_1 V_552 )
{
struct V_553 V_14 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 . V_552 = V_552 ;
V_14 . V_551 = F_64 ( V_551 ) ;
return F_85 ( V_554 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_247 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 )
{
struct V_555 V_14 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = F_139 ( V_316 , V_297 ) ;
return F_85 ( V_556 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
static int F_248 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_8 ,
T_1 V_18 )
{
struct V_102 * V_7 ;
struct V_557 V_21 ;
int V_15 ;
V_7 = F_32 ( V_18 , V_27 ) ;
if ( ! V_7 )
return - V_398 ;
F_63 ( & V_21 . V_294 . V_174 , V_174 ) ;
V_21 . V_294 . type = F_139 ( V_316 , V_297 ) ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_18 , F_1 ( V_8 ) ,
& V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
return V_15 ;
}
int F_249 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_8 )
{
return F_248 ( V_27 , V_174 , V_316 , V_297 ,
V_8 , V_365 ) ;
}
int F_250 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_8 )
{
return F_248 ( V_27 , V_174 , V_316 , V_297 ,
V_8 ,
V_368 ) ;
}
int F_251 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_8 )
{
return F_248 ( V_27 , V_174 , V_316 , V_297 ,
V_8 , V_371 ) ;
}
int F_252 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_1 V_8 )
{
return F_248 ( V_27 , V_174 , V_316 , V_297 ,
V_8 ,
V_373 ) ;
}
int F_253 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_316 , T_1 V_297 , T_5 V_360 ,
T_1 V_558 )
{
struct V_559 V_14 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 . V_360 = F_237 ( V_360 ) ;
V_14 . V_558 = V_558 ;
return F_85 ( V_560 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_254 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_316 ,
T_1 V_297 , T_1 V_8 )
{
struct V_561 V_14 ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
F_85 ( V_562 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_255 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 } ;
bool V_228 ;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
F_70 ( V_259 , V_27 ,
F_90 , & V_230 ) ;
return;
}
if ( F_20 ( V_260 , & V_27 -> V_125 ) )
V_228 = ! F_60 ( V_82 ,
& V_27 -> V_53 ) ;
else
V_228 = F_51 ( V_82 ,
& V_27 -> V_53 ) ;
F_70 ( V_259 , V_27 , F_89 ,
& V_224 ) ;
if ( V_228 )
F_88 ( V_27 , V_224 . V_5 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
}
static void F_256 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_142 V_113 ;
if ( ! F_41 ( V_27 ) )
return;
memset ( V_27 -> V_144 , 0 , sizeof( V_27 -> V_144 ) ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
F_35 ( V_111 , V_145 , sizeof( V_113 ) , & V_113 ) ;
}
void F_257 ( struct V_26 * V_27 , T_1 V_156 , T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 } ;
struct V_110 V_111 ;
bool V_228 = false ;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
if ( V_156 && F_51 ( V_83 ,
& V_27 -> V_53 ) ) {
F_46 ( V_84 , & V_27 -> V_53 ) ;
F_88 ( V_27 , NULL ) ;
}
F_70 ( V_262 , V_27 , F_90 ,
& V_230 ) ;
return;
}
if ( V_156 ) {
V_228 = ! F_60 ( V_83 , & V_27 -> V_53 ) ;
} else {
V_228 = F_51 ( V_83 , & V_27 -> V_53 ) ;
if ( ! V_228 )
V_228 = F_51 ( V_84 ,
& V_27 -> V_53 ) ;
else
F_46 ( V_84 , & V_27 -> V_53 ) ;
}
F_70 ( V_262 , V_27 , F_89 , & V_224 ) ;
if ( V_228 )
F_88 ( V_27 , V_224 . V_5 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_83 , & V_27 -> V_53 ) )
F_40 ( & V_111 ) ;
else
F_256 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
}
void F_258 ( struct V_26 * V_27 , T_1 V_156 , T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 } ;
bool V_228 = false ;
if ( V_8 ) {
T_1 V_230 = F_1 ( V_8 ) ;
if ( V_156 ) {
if ( F_51 ( V_86 ,
& V_27 -> V_53 ) )
F_88 ( V_27 , NULL ) ;
F_46 ( V_467 , & V_27 -> V_53 ) ;
}
F_70 ( V_466 , V_27 ,
F_90 , & V_230 ) ;
return;
}
if ( V_156 ) {
V_228 = ! F_60 ( V_86 , & V_27 -> V_53 ) ;
} else {
V_228 = F_51 ( V_86 , & V_27 -> V_53 ) ;
F_46 ( V_467 , & V_27 -> V_53 ) ;
}
F_70 ( V_466 , V_27 ,
F_89 , & V_224 ) ;
if ( V_228 )
F_88 ( V_27 , V_224 . V_5 ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
}
static void F_259 ( struct V_102 * V_7 , void * V_25 )
{
struct V_223 * V_224 = V_25 ;
if ( V_224 -> V_5 == NULL ) {
V_224 -> V_5 = V_7 -> V_5 ;
F_68 ( V_224 -> V_5 ) ;
}
}
void F_260 ( struct V_26 * V_27 , T_1 * V_151 ,
T_1 V_8 )
{
struct V_223 V_224 = { NULL , V_27 , F_1 (status) } ;
F_70 ( V_274 , V_27 , F_259 , & V_224 ) ;
F_70 ( V_272 , V_27 , F_259 , & V_224 ) ;
F_70 ( V_273 , V_27 , F_259 , & V_224 ) ;
if ( ! V_8 )
F_85 ( V_514 , V_27 , V_151 , 3 ,
NULL ) ;
if ( V_224 . V_5 )
F_66 ( V_224 . V_5 ) ;
}
void F_261 ( struct V_26 * V_27 , T_1 * V_148 , T_1 V_8 )
{
struct V_377 V_14 ;
struct V_102 * V_7 ;
if ( V_8 )
return;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_148 , V_148 , V_563 ) ;
memcpy ( V_14 . V_178 , V_27 -> V_178 , V_564 ) ;
V_7 = F_32 ( V_378 , V_27 ) ;
if ( ! V_7 ) {
memcpy ( V_27 -> V_105 , V_148 , sizeof( V_27 -> V_105 ) ) ;
if ( F_32 ( V_211 , V_27 ) )
return;
}
F_85 ( V_379 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
void F_262 ( struct V_26 * V_27 , T_1 * V_390 ,
T_1 * V_391 , T_1 * V_392 ,
T_1 * V_393 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_29 , V_27 -> V_148 , V_8 ) ;
V_7 = F_32 ( V_380 , V_27 ) ;
if ( ! V_7 )
return;
if ( V_8 ) {
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_380 ,
F_1 ( V_8 ) ) ;
} else {
if ( F_20 ( V_86 , & V_27 -> V_53 ) &&
V_392 && V_393 ) {
struct V_565 V_21 ;
memcpy ( V_21 . V_390 , V_390 , sizeof( V_21 . V_390 ) ) ;
memcpy ( V_21 . V_391 , V_391 ,
sizeof( V_21 . V_391 ) ) ;
memcpy ( V_21 . V_392 , V_392 , sizeof( V_21 . V_392 ) ) ;
memcpy ( V_21 . V_393 , V_393 ,
sizeof( V_21 . V_393 ) ) ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 ,
V_380 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
} else {
struct V_566 V_21 ;
memcpy ( V_21 . V_385 , V_390 , sizeof( V_21 . V_385 ) ) ;
memcpy ( V_21 . V_386 , V_391 ,
sizeof( V_21 . V_386 ) ) ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 ,
V_380 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
}
}
F_73 ( V_7 ) ;
}
void F_263 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_316 ,
T_1 V_297 , T_1 * V_151 , T_10 V_567 , T_1 V_568 , T_1
V_510 , T_1 * V_144 , T_2 V_538 )
{
char V_492 [ 512 ] ;
struct V_569 * V_14 = ( void * ) V_492 ;
struct V_530 * V_475 ;
T_3 V_570 ;
if ( ! F_182 ( V_27 ) )
return;
if ( sizeof( * V_14 ) + V_538 + 5 > sizeof( V_492 ) )
return;
memset ( V_492 , 0 , sizeof( V_492 ) ) ;
V_475 = F_264 ( V_27 , V_174 , V_297 ) ;
if ( V_475 ) {
F_63 ( & V_14 -> V_294 . V_174 , & V_475 -> V_174 ) ;
V_14 -> V_294 . type = F_139 ( V_316 , V_475 -> V_297 ) ;
} else {
F_63 ( & V_14 -> V_294 . V_174 , V_174 ) ;
V_14 -> V_294 . type = F_139 ( V_316 , V_297 ) ;
}
V_14 -> V_567 = V_567 ;
if ( V_568 )
V_14 -> V_125 |= F_64 ( V_571 ) ;
if ( ! V_510 )
V_14 -> V_125 |= F_64 ( V_572 ) ;
if ( V_538 > 0 )
memcpy ( V_14 -> V_144 , V_144 , V_538 ) ;
if ( V_151 && ! F_265 ( V_14 -> V_144 , V_538 , V_540 ) )
V_538 = F_235 ( V_14 -> V_144 , V_538 , V_540 ,
V_151 , 3 ) ;
V_14 -> V_538 = F_7 ( V_538 ) ;
V_570 = sizeof( * V_14 ) + V_538 ;
F_85 ( V_573 , V_27 , V_14 , V_570 , NULL ) ;
}
void F_266 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_316 ,
T_1 V_297 , T_10 V_567 , T_1 * V_148 , T_1 V_104 )
{
struct V_569 * V_14 ;
char V_492 [ sizeof( * V_14 ) + V_563 + 2 ] ;
T_2 V_538 ;
V_14 = (struct V_569 * ) V_492 ;
memset ( V_492 , 0 , sizeof( V_492 ) ) ;
F_63 ( & V_14 -> V_294 . V_174 , V_174 ) ;
V_14 -> V_294 . type = F_139 ( V_316 , V_297 ) ;
V_14 -> V_567 = V_567 ;
V_538 = F_235 ( V_14 -> V_144 , 0 , V_109 , V_148 ,
V_104 ) ;
V_14 -> V_538 = F_7 ( V_538 ) ;
F_85 ( V_573 , V_27 , V_14 , sizeof( * V_14 ) + V_538 , NULL ) ;
}
void F_267 ( struct V_26 * V_27 , T_1 V_574 )
{
struct V_575 V_14 ;
struct V_102 * V_7 ;
F_4 ( L_30 , V_27 -> V_148 , V_574 ) ;
if ( V_574 )
V_7 = F_32 ( V_397 , V_27 ) ;
else
V_7 = F_32 ( V_428 , V_27 ) ;
if ( V_7 != NULL ) {
T_1 type = V_27 -> V_399 . type ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , 0 , & type ,
sizeof( type ) ) ;
F_73 ( V_7 ) ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . type = V_27 -> V_399 . type ;
V_14 . V_574 = V_574 ;
F_85 ( V_576 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_268 ( struct V_26 * V_27 , T_8 * V_174 , T_1 type )
{
struct V_102 * V_7 ;
struct V_577 V_14 ;
V_7 = F_32 ( V_447 , V_27 ) ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = type ;
return F_85 ( V_578 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
int F_269 ( struct V_26 * V_27 , T_8 * V_174 , T_1 type )
{
struct V_102 * V_7 ;
struct V_579 V_14 ;
V_7 = F_32 ( V_449 , V_27 ) ;
F_63 ( & V_14 . V_294 . V_174 , V_174 ) ;
V_14 . V_294 . type = type ;
return F_85 ( V_580 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
static void F_270 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_29 , V_27 -> V_148 , V_8 ) ;
if ( V_8 ) {
F_46 ( V_85 , & V_27 -> V_53 ) ;
F_88 ( V_27 , NULL ) ;
}
}
void F_271 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
if ( F_58 ( V_27 , V_171 ) > 0 )
return;
if ( ! F_20 ( V_85 , & V_27 -> V_53 ) )
return;
F_52 ( & V_111 , V_27 ) ;
F_45 ( & V_111 ) ;
if ( F_55 ( & V_111 , F_270 ) < 0 ) {
F_46 ( V_85 , & V_27 -> V_53 ) ;
F_88 ( V_27 , NULL ) ;
}
}
