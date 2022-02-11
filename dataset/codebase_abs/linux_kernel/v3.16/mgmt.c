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
static void F_80 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_185 V_113 ;
struct V_186 * V_187 ;
switch ( V_27 -> V_188 . V_189 ) {
case V_190 :
if ( F_20 ( V_191 , & V_27 -> V_125 ) ) {
F_35 ( V_111 , V_192 , 0 , NULL ) ;
} else {
F_78 ( & V_27 -> V_193 ) ;
F_81 ( V_111 ) ;
}
break;
case V_194 :
V_187 = F_82 ( V_27 , V_195 ,
V_196 ) ;
if ( ! V_187 )
return;
F_63 ( & V_113 . V_174 , & V_187 -> V_25 . V_174 ) ;
F_35 ( V_111 , V_197 , sizeof( V_113 ) ,
& V_113 ) ;
break;
default:
if ( F_20 ( V_198 , & V_27 -> V_53 ) )
F_81 ( V_111 ) ;
break;
}
}
static int F_83 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
struct V_199 * V_200 ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_201 , & V_27 -> V_125 ) ||
F_20 ( V_202 , & V_27 -> V_125 ) ) {
T_1 V_203 = 0x00 ;
F_35 ( & V_111 , V_204 , 1 , & V_203 ) ;
}
if ( F_20 ( V_85 , & V_27 -> V_53 ) )
F_48 ( & V_111 ) ;
F_80 ( & V_111 ) ;
F_18 (conn, &hdev->conn_hash.list, list) {
struct V_205 V_206 ;
struct V_207 V_208 ;
switch ( V_200 -> V_189 ) {
case V_209 :
case V_210 :
V_206 . V_211 = F_7 ( V_200 -> V_211 ) ;
V_206 . V_212 = 0x15 ;
F_35 ( & V_111 , V_213 , sizeof( V_206 ) , & V_206 ) ;
break;
case V_214 :
if ( V_200 -> type == V_171 )
F_35 ( & V_111 , V_215 ,
0 , NULL ) ;
else if ( V_200 -> type == V_216 )
F_35 ( & V_111 , V_217 ,
6 , & V_200 -> V_218 ) ;
break;
case V_219 :
F_63 ( & V_208 . V_174 , & V_200 -> V_218 ) ;
V_208 . V_212 = 0x15 ;
if ( V_200 -> type == V_216 )
F_35 ( & V_111 , V_220 ,
sizeof( V_208 ) , & V_208 ) ;
else if ( V_200 -> type == V_221 )
F_35 ( & V_111 , V_222 ,
sizeof( V_208 ) , & V_208 ) ;
break;
}
}
return F_55 ( & V_111 , F_76 ) ;
}
static int F_84 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_223 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( F_32 ( V_223 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_223 ,
V_225 ) ;
goto V_226;
}
if ( F_51 ( V_227 , & V_27 -> V_53 ) ) {
F_78 ( & V_27 -> V_183 ) ;
if ( V_113 -> V_121 ) {
F_67 ( V_5 , V_223 , V_27 ,
V_25 , V_20 ) ;
V_15 = F_85 ( V_27 , 1 ) ;
goto V_226;
}
}
if ( ! ! V_113 -> V_121 == F_27 ( V_27 ) ) {
V_15 = F_75 ( V_5 , V_223 , V_27 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_223 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
if ( V_113 -> V_121 ) {
F_79 ( V_27 -> V_184 , & V_27 -> V_228 ) ;
V_15 = 0 ;
} else {
V_15 = F_83 ( V_27 ) ;
if ( ! V_15 )
F_86 ( V_27 -> V_184 , & V_27 -> V_183 ,
V_229 ) ;
if ( V_15 == - V_230 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
V_15 = 0 ;
}
}
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_87 ( T_2 V_231 , struct V_26 * V_27 , void * V_25 , T_2 V_28 ,
struct V_4 * V_232 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_5 ( sizeof( * V_12 ) + V_28 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_231 ) ;
if ( V_27 )
V_12 -> V_6 = F_7 ( V_27 -> V_55 ) ;
else
V_12 -> V_6 = F_7 ( V_34 ) ;
V_12 -> V_20 = F_7 ( V_28 ) ;
if ( V_25 )
memcpy ( F_6 ( V_10 , V_28 ) , V_25 , V_28 ) ;
F_88 ( V_10 ) ;
F_89 ( V_10 , V_232 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_90 ( struct V_26 * V_27 , struct V_4 * V_233 )
{
T_7 V_14 ;
V_14 = F_64 ( F_26 ( V_27 ) ) ;
return F_87 ( V_234 , V_27 , & V_14 , sizeof( V_14 ) , V_233 ) ;
}
static void F_91 ( struct V_102 * V_7 , void * V_25 )
{
struct V_235 * V_236 = V_25 ;
F_75 ( V_7 -> V_5 , V_7 -> V_18 , V_236 -> V_27 ) ;
F_74 ( & V_7 -> V_180 ) ;
if ( V_236 -> V_5 == NULL ) {
V_236 -> V_5 = V_7 -> V_5 ;
F_68 ( V_236 -> V_5 ) ;
}
F_65 ( V_7 ) ;
}
static void F_92 ( struct V_102 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , * V_8 ) ;
F_73 ( V_7 ) ;
}
static T_1 F_93 ( struct V_26 * V_27 )
{
if ( ! F_22 ( V_27 ) )
return V_237 ;
else if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return V_238 ;
else
return V_239 ;
}
static T_1 F_94 ( struct V_26 * V_27 )
{
if ( ! F_25 ( V_27 ) )
return V_237 ;
else if ( ! F_20 ( V_81 , & V_27 -> V_53 ) )
return V_238 ;
else
return V_239 ;
}
static void F_95 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_119 * V_113 ;
struct V_110 V_111 ;
bool V_240 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_118 , V_27 ) ;
if ( ! V_7 )
goto V_241;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_242 ) ;
F_46 ( V_124 , & V_27 -> V_53 ) ;
goto V_243;
}
V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 ) {
V_240 = ! F_60 ( V_78 ,
& V_27 -> V_53 ) ;
if ( V_27 -> V_244 > 0 ) {
int V_245 = F_96 ( V_27 -> V_244 * 1000 ) ;
F_86 ( V_27 -> V_246 , & V_27 -> V_247 ,
V_245 ) ;
}
} else {
V_240 = F_51 ( V_78 ,
& V_27 -> V_53 ) ;
}
F_75 ( V_7 -> V_5 , V_118 , V_27 ) ;
if ( V_240 )
F_90 ( V_27 , V_7 -> V_5 ) ;
F_52 ( & V_111 , V_27 ) ;
F_43 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
V_243:
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_97 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_248 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
T_2 V_249 ;
T_1 V_203 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) &&
! F_20 ( V_80 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_238 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 && V_113 -> V_121 != 0x02 )
return F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_224 ) ;
V_249 = F_98 ( V_113 -> V_249 ) ;
if ( ( V_113 -> V_121 == 0x00 && V_249 > 0 ) ||
( V_113 -> V_121 == 0x02 && V_249 == 0 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) && V_249 > 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_250 ) ;
goto V_226;
}
if ( F_32 ( V_118 , V_27 ) ||
F_32 ( V_153 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_225 ) ;
goto V_226;
}
if ( ! F_20 ( V_76 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_118 ,
V_238 ) ;
goto V_226;
}
if ( ! F_27 ( V_27 ) ) {
bool V_240 = false ;
if ( ! ! V_113 -> V_121 != F_20 ( V_78 , & V_27 -> V_53 ) ) {
F_99 ( V_78 , & V_27 -> V_53 ) ;
V_240 = true ;
}
V_15 = F_75 ( V_5 , V_118 , V_27 ) ;
if ( V_15 < 0 )
goto V_226;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_226;
}
if ( ! ! V_113 -> V_121 == F_20 ( V_78 , & V_27 -> V_53 ) &&
( V_113 -> V_121 == 0x02 ) == F_20 ( V_124 ,
& V_27 -> V_53 ) ) {
F_78 ( & V_27 -> V_247 ) ;
V_27 -> V_244 = V_249 ;
if ( V_113 -> V_121 && V_27 -> V_244 > 0 ) {
int V_245 = F_96 ( V_27 -> V_244 * 1000 ) ;
F_86 ( V_27 -> V_246 , & V_27 -> V_247 ,
V_245 ) ;
}
V_15 = F_75 ( V_5 , V_118 , V_27 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_118 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
F_78 ( & V_27 -> V_247 ) ;
V_27 -> V_244 = V_249 ;
if ( V_113 -> V_121 == 0x02 )
F_57 ( V_124 , & V_27 -> V_53 ) ;
else
F_46 ( V_124 , & V_27 -> V_53 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
goto V_251;
V_203 = V_252 ;
if ( V_113 -> V_121 ) {
struct V_253 V_254 ;
if ( V_113 -> V_121 == 0x02 ) {
V_254 . V_255 = F_100 ( T_1 , V_27 -> V_255 , 2 ) ;
V_254 . V_256 [ 0 ] = 0x00 ;
V_254 . V_256 [ 1 ] = 0x8b ;
V_254 . V_256 [ 2 ] = 0x9e ;
V_254 . V_256 [ 3 ] = 0x33 ;
V_254 . V_256 [ 4 ] = 0x8b ;
V_254 . V_256 [ 5 ] = 0x9e ;
} else {
V_254 . V_255 = 1 ;
V_254 . V_256 [ 0 ] = 0x33 ;
V_254 . V_256 [ 1 ] = 0x8b ;
V_254 . V_256 [ 2 ] = 0x9e ;
}
F_35 ( & V_111 , V_257 ,
( V_254 . V_255 * 3 ) + 1 , & V_254 ) ;
V_203 |= V_258 ;
} else {
F_46 ( V_124 , & V_27 -> V_53 ) ;
}
F_35 ( & V_111 , V_204 , sizeof( V_203 ) , & V_203 ) ;
V_251:
F_38 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_95 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_101 ( struct V_110 * V_111 , bool V_156 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_259 V_260 ;
T_1 type ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return;
if ( V_27 -> V_63 < V_64 )
return;
if ( V_156 ) {
type = V_261 ;
V_260 . V_262 = F_7 ( 0x0100 ) ;
} else {
type = V_263 ;
V_260 . V_262 = F_7 ( 0x0800 ) ;
}
V_260 . V_264 = F_7 ( 0x0012 ) ;
if ( F_102 ( V_27 -> V_265 ) != V_260 . V_262 ||
F_102 ( V_27 -> V_266 ) != V_260 . V_264 )
F_35 ( V_111 , V_267 ,
sizeof( V_260 ) , & V_260 ) ;
if ( V_27 -> V_268 != type )
F_35 ( V_111 , V_269 , 1 , & type ) ;
}
static void F_103 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_119 * V_113 ;
bool V_240 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_153 , V_27 ) ;
if ( ! V_7 )
goto V_241;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_242 ) ;
goto V_243;
}
V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 )
V_240 = ! F_60 ( V_76 , & V_27 -> V_53 ) ;
else
V_240 = F_51 ( V_76 , & V_27 -> V_53 ) ;
F_75 ( V_7 -> V_5 , V_153 , V_27 ) ;
if ( V_240 )
F_90 ( V_27 , V_7 -> V_5 ) ;
V_243:
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_104 ( struct V_26 * V_27 ,
struct V_4 * V_5 , T_1 V_121 )
{
bool V_240 = false ;
int V_15 ;
if ( ! ! V_121 != F_20 ( V_76 , & V_27 -> V_53 ) )
V_240 = true ;
if ( V_121 ) {
F_57 ( V_76 , & V_27 -> V_53 ) ;
} else {
F_46 ( V_76 , & V_27 -> V_53 ) ;
F_46 ( V_78 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_153 , V_27 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_240 )
return F_90 ( V_27 , V_5 ) ;
return 0 ;
}
static int F_105 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
T_1 V_203 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) &&
! F_20 ( V_80 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_153 ,
V_238 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_153 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_104 ( V_27 , V_5 , V_113 -> V_121 ) ;
goto V_226;
}
if ( F_32 ( V_118 , V_27 ) ||
F_32 ( V_153 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_153 ,
V_225 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_153 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
F_52 ( & V_111 , V_27 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) ) {
if ( ! V_113 -> V_121 ) {
F_46 ( V_124 , & V_27 -> V_53 ) ;
F_46 ( V_78 , & V_27 -> V_53 ) ;
}
F_38 ( & V_111 ) ;
} else if ( V_113 -> V_121 != F_20 ( V_202 , & V_27 -> V_125 ) ) {
if ( V_113 -> V_121 ) {
V_203 = V_252 ;
} else {
V_203 = 0 ;
if ( F_20 ( V_201 , & V_27 -> V_125 ) &&
V_27 -> V_244 > 0 )
F_78 ( & V_27 -> V_247 ) ;
}
F_35 ( & V_111 , V_204 , 1 , & V_203 ) ;
}
if ( V_113 -> V_121 || F_20 ( V_77 , & V_27 -> V_53 ) )
F_101 ( & V_111 , false ) ;
if ( F_20 ( V_85 , & V_27 -> V_53 ) &&
F_58 ( V_27 , V_171 ) == 0 ) {
F_48 ( & V_111 ) ;
F_45 ( & V_111 ) ;
}
V_15 = F_55 ( & V_111 , F_103 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
if ( V_15 == - V_230 )
V_15 = F_104 ( V_27 , V_5 ,
V_113 -> V_121 ) ;
goto V_226;
}
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_106 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
bool V_240 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_270 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 )
V_240 = ! F_60 ( V_79 , & V_27 -> V_53 ) ;
else
V_240 = F_51 ( V_79 , & V_27 -> V_53 ) ;
V_15 = F_75 ( V_5 , V_270 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_107 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
T_1 V_121 , V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_93 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_271 ,
V_8 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_271 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_240 = false ;
if ( ! ! V_113 -> V_121 != F_20 ( V_82 ,
& V_27 -> V_53 ) ) {
F_99 ( V_82 , & V_27 -> V_53 ) ;
V_240 = true ;
}
V_15 = F_75 ( V_5 , V_271 , V_27 ) ;
if ( V_15 < 0 )
goto V_226;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_226;
}
if ( F_32 ( V_271 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_271 ,
V_225 ) ;
goto V_226;
}
V_121 = ! ! V_113 -> V_121 ;
if ( F_20 ( V_272 , & V_27 -> V_125 ) == V_121 ) {
V_15 = F_75 ( V_5 , V_271 , V_27 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_271 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
V_15 = F_108 ( V_27 , V_273 , sizeof( V_121 ) , & V_121 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
goto V_226;
}
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_109 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_93 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_274 , V_8 ) ;
if ( ! F_23 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_274 ,
V_237 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_274 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_240 ;
if ( V_113 -> V_121 ) {
V_240 = ! F_60 ( V_83 ,
& V_27 -> V_53 ) ;
} else {
V_240 = F_51 ( V_83 ,
& V_27 -> V_53 ) ;
if ( ! V_240 )
V_240 = F_51 ( V_84 ,
& V_27 -> V_53 ) ;
else
F_46 ( V_84 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_274 , V_27 ) ;
if ( V_15 < 0 )
goto V_226;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_226;
}
if ( F_32 ( V_274 , V_27 ) ||
F_32 ( V_275 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_274 ,
V_225 ) ;
goto V_226;
}
if ( ! ! V_113 -> V_121 == F_20 ( V_83 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_274 , V_27 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_274 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
V_15 = F_108 ( V_27 , V_276 , 1 , & V_113 -> V_121 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
goto V_226;
}
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_110 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
bool V_240 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_93 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_275 , V_8 ) ;
if ( ! F_23 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_275 ,
V_237 ) ;
if ( ! F_20 ( V_83 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_275 ,
V_238 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_275 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 ) {
V_240 = ! F_60 ( V_84 , & V_27 -> V_53 ) ;
} else {
if ( F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_275 ,
V_238 ) ;
goto V_241;
}
V_240 = F_51 ( V_84 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_275 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_111 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 } ;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
F_70 ( V_277 , V_27 , F_92 ,
& V_242 ) ;
return;
}
F_70 ( V_277 , V_27 , F_91 , & V_236 ) ;
F_90 ( V_27 , V_236 . V_5 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
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
static int F_112 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_278 V_254 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
T_1 V_121 , V_279 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_277 ,
V_237 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_277 ,
V_224 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_277 ,
V_238 ) ;
F_53 ( V_27 ) ;
V_121 = ! ! V_113 -> V_121 ;
V_279 = F_113 ( V_27 ) ;
if ( ! F_27 ( V_27 ) || V_121 == V_279 ) {
bool V_240 = false ;
if ( V_121 != F_20 ( V_81 , & V_27 -> V_53 ) ) {
F_99 ( V_81 , & V_27 -> V_53 ) ;
V_240 = true ;
}
if ( ! V_121 && F_20 ( V_85 , & V_27 -> V_53 ) ) {
F_46 ( V_85 , & V_27 -> V_53 ) ;
V_240 = true ;
}
V_15 = F_75 ( V_5 , V_277 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_241;
}
if ( F_32 ( V_277 , V_27 ) ||
F_32 ( V_280 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_277 ,
V_225 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_277 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
F_52 ( & V_111 , V_27 ) ;
memset ( & V_254 , 0 , sizeof( V_254 ) ) ;
if ( V_121 ) {
V_254 . V_281 = V_121 ;
V_254 . V_282 = F_114 ( V_27 ) ;
} else {
if ( F_20 ( V_85 , & V_27 -> V_53 ) )
F_48 ( & V_111 ) ;
}
F_35 ( & V_111 , V_283 , sizeof( V_254 ) ,
& V_254 ) ;
V_15 = F_55 ( & V_111 , F_111 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_115 ( struct V_26 * V_27 )
{
struct V_102 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
switch ( V_7 -> V_18 ) {
case V_284 :
case V_285 :
case V_286 :
case V_223 :
return true ;
}
}
return false ;
}
static T_1 F_116 ( const T_1 * V_92 )
{
T_5 V_121 ;
if ( memcmp ( V_92 , V_287 , 12 ) )
return 128 ;
V_121 = F_117 ( & V_92 [ 12 ] ) ;
if ( V_121 > 0xffff )
return 32 ;
return 16 ;
}
static void F_118 ( struct V_26 * V_27 , T_2 V_288 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_288 , V_27 ) ;
if ( ! V_7 )
goto V_241;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , F_1 ( V_8 ) ,
V_27 -> V_151 , 3 ) ;
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
}
static void F_119 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_10 , V_8 ) ;
F_118 ( V_27 , V_284 , V_8 ) ;
}
static int F_120 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_289 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
struct V_91 * V_92 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( F_115 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_284 ,
V_225 ) ;
goto V_226;
}
V_92 = F_13 ( sizeof( * V_92 ) , V_16 ) ;
if ( ! V_92 ) {
V_15 = - V_17 ;
goto V_226;
}
memcpy ( V_92 -> V_92 , V_113 -> V_92 , 16 ) ;
V_92 -> V_146 = V_113 -> V_146 ;
V_92 -> V_94 = F_116 ( V_113 -> V_92 ) ;
F_121 ( & V_92 -> V_180 , & V_27 -> V_290 ) ;
F_52 ( & V_111 , V_27 ) ;
F_43 ( & V_111 ) ;
F_40 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_119 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_230 )
goto V_226;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_284 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_284 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
V_15 = 0 ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_122 ( struct V_26 * V_27 )
{
if ( ! F_27 ( V_27 ) )
return false ;
if ( ! F_60 ( V_143 , & V_27 -> V_53 ) ) {
F_86 ( V_27 -> V_246 , & V_27 -> V_169 ,
V_291 ) ;
return true ;
}
return false ;
}
static void F_123 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_10 , V_8 ) ;
F_118 ( V_27 , V_285 , V_8 ) ;
}
static int F_124 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_292 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_91 * V_236 , * V_182 ;
T_1 V_293 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_110 V_111 ;
int V_15 , V_294 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( F_115 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_285 ,
V_225 ) ;
goto V_241;
}
if ( memcmp ( V_113 -> V_92 , V_293 , 16 ) == 0 ) {
F_125 ( V_27 ) ;
if ( F_122 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_285 ,
0 , V_27 -> V_151 , 3 ) ;
goto V_241;
}
goto F_43;
}
V_294 = 0 ;
F_72 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_236 -> V_92 , V_113 -> V_92 , 16 ) != 0 )
continue;
F_74 ( & V_236 -> V_180 ) ;
F_15 ( V_236 ) ;
V_294 ++ ;
}
if ( V_294 == 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_285 ,
V_224 ) ;
goto V_241;
}
F_43:
F_52 ( & V_111 , V_27 ) ;
F_43 ( & V_111 ) ;
F_40 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_123 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_230 )
goto V_241;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_285 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_285 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
V_15 = 0 ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_126 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_10 , V_8 ) ;
F_118 ( V_27 , V_286 , V_8 ) ;
}
static int F_127 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_295 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_22 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_286 ,
V_237 ) ;
F_53 ( V_27 ) ;
if ( F_115 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_286 ,
V_225 ) ;
goto V_241;
}
if ( ( V_113 -> V_296 & 0x03 ) != 0 || ( V_113 -> V_297 & 0xe0 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_286 ,
V_224 ) ;
goto V_241;
}
V_27 -> V_150 = V_113 -> V_297 ;
V_27 -> V_149 = V_113 -> V_296 ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_286 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_241;
}
F_52 ( & V_111 , V_27 ) ;
if ( F_51 ( V_143 , & V_27 -> V_53 ) ) {
F_54 ( V_27 ) ;
F_128 ( & V_27 -> V_169 ) ;
F_53 ( V_27 ) ;
F_40 ( & V_111 ) ;
}
F_43 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_126 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_230 )
goto V_241;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_286 , 0 ,
V_27 -> V_151 , 3 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_286 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
V_15 = 0 ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_129 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_298 * V_113 = V_25 ;
T_2 V_299 , V_300 ;
bool V_240 ;
int V_42 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_22 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_301 ,
V_237 ) ;
V_299 = F_98 ( V_113 -> V_299 ) ;
V_300 = sizeof( * V_113 ) + V_299 *
sizeof( struct V_302 ) ;
if ( V_300 != V_20 ) {
F_130 ( L_11 ,
V_300 , V_20 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_301 ,
V_224 ) ;
}
if ( V_113 -> V_303 != 0x00 && V_113 -> V_303 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_301 ,
V_224 ) ;
F_4 ( L_12 , V_27 -> V_148 , V_113 -> V_303 ,
V_299 ) ;
for ( V_42 = 0 ; V_42 < V_299 ; V_42 ++ ) {
struct V_302 * V_304 = & V_113 -> V_305 [ V_42 ] ;
if ( V_304 -> V_306 . type != V_307 || V_304 -> type > 0x08 )
return F_3 ( V_5 , V_27 -> V_55 , V_301 ,
V_224 ) ;
}
F_53 ( V_27 ) ;
F_131 ( V_27 ) ;
if ( V_113 -> V_303 )
V_240 = ! F_60 ( V_87 , & V_27 -> V_53 ) ;
else
V_240 = F_51 ( V_87 , & V_27 -> V_53 ) ;
if ( V_240 )
F_90 ( V_27 , NULL ) ;
for ( V_42 = 0 ; V_42 < V_299 ; V_42 ++ ) {
struct V_302 * V_304 = & V_113 -> V_305 [ V_42 ] ;
F_132 ( V_27 , NULL , 0 , & V_304 -> V_306 . V_174 , V_304 -> V_121 ,
V_304 -> type , V_304 -> V_308 ) ;
}
F_10 ( V_5 , V_27 -> V_55 , V_301 , 0 , NULL , 0 ) ;
F_54 ( V_27 ) ;
return 0 ;
}
static int F_133 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_309 , struct V_4 * V_232 )
{
struct V_310 V_14 ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = V_309 ;
return F_87 ( V_311 , V_27 , & V_14 , sizeof( V_14 ) ,
V_232 ) ;
}
static int F_134 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_312 * V_113 = V_25 ;
struct V_313 V_21 ;
struct V_205 V_206 ;
struct V_102 * V_7 ;
struct V_199 * V_200 ;
int V_15 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
if ( ! F_135 ( V_113 -> V_306 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_314 ,
V_224 ,
& V_21 , sizeof( V_21 ) ) ;
if ( V_113 -> V_315 != 0x00 && V_113 -> V_315 != 0x01 )
return F_10 ( V_5 , V_27 -> V_55 , V_314 ,
V_224 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_314 ,
V_250 , & V_21 , sizeof( V_21 ) ) ;
goto V_241;
}
if ( V_113 -> V_306 . type == V_307 ) {
V_15 = F_136 ( V_27 , & V_113 -> V_306 . V_174 ) ;
} else {
T_1 V_309 ;
if ( V_113 -> V_306 . type == V_316 )
V_309 = V_317 ;
else
V_309 = V_318 ;
F_137 ( V_27 , & V_113 -> V_306 . V_174 , V_309 ) ;
F_138 ( V_27 , & V_113 -> V_306 . V_174 , V_309 ) ;
V_15 = F_139 ( V_27 , & V_113 -> V_306 . V_174 , V_309 ) ;
}
if ( V_15 < 0 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_314 ,
V_319 , & V_21 , sizeof( V_21 ) ) ;
goto V_241;
}
if ( V_113 -> V_315 ) {
if ( V_113 -> V_306 . type == V_307 )
V_200 = F_140 ( V_27 , V_216 ,
& V_113 -> V_306 . V_174 ) ;
else
V_200 = F_140 ( V_27 , V_171 ,
& V_113 -> V_306 . V_174 ) ;
} else {
V_200 = NULL ;
}
if ( ! V_200 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_314 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
F_133 ( V_27 , & V_113 -> V_306 . V_174 , V_113 -> V_306 . type , V_5 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_314 , V_27 , V_113 ,
sizeof( * V_113 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
V_206 . V_211 = F_7 ( V_200 -> V_211 ) ;
V_206 . V_212 = 0x13 ;
V_15 = F_108 ( V_27 , V_213 , sizeof( V_206 ) , & V_206 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int V_315 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_320 * V_113 = V_25 ;
struct V_321 V_21 ;
struct V_205 V_206 ;
struct V_102 * V_7 ;
struct V_199 * V_200 ;
int V_15 ;
F_4 ( L_6 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
if ( ! F_135 ( V_113 -> V_306 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_322 ,
V_224 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_20 ( V_323 , & V_27 -> V_125 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_322 ,
V_250 , & V_21 , sizeof( V_21 ) ) ;
goto V_226;
}
if ( F_32 ( V_322 , V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_322 ,
V_225 , & V_21 , sizeof( V_21 ) ) ;
goto V_226;
}
if ( V_113 -> V_306 . type == V_307 )
V_200 = F_140 ( V_27 , V_216 ,
& V_113 -> V_306 . V_174 ) ;
else
V_200 = F_140 ( V_27 , V_171 , & V_113 -> V_306 . V_174 ) ;
if ( ! V_200 || V_200 -> V_189 == V_324 || V_200 -> V_189 == V_325 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_322 ,
V_326 , & V_21 , sizeof( V_21 ) ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_322 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
V_206 . V_211 = F_7 ( V_200 -> V_211 ) ;
V_206 . V_212 = V_327 ;
V_15 = F_108 ( V_27 , V_213 , sizeof( V_206 ) , & V_206 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static T_1 F_141 ( T_1 V_328 , T_1 V_309 )
{
switch ( V_328 ) {
case V_171 :
switch ( V_309 ) {
case V_317 :
return V_316 ;
default:
return V_329 ;
}
default:
return V_307 ;
}
}
static int F_142 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_330 * V_21 ;
struct V_199 * V_331 ;
T_3 V_22 ;
int V_15 ;
T_2 V_42 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_332 ,
V_250 ) ;
goto V_241;
}
V_42 = 0 ;
F_18 (c, &hdev->conn_hash.list, list) {
if ( F_20 ( V_333 , & V_331 -> V_125 ) )
V_42 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_334 ) ) ;
V_21 = F_13 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
V_15 = - V_17 ;
goto V_241;
}
V_42 = 0 ;
F_18 (c, &hdev->conn_hash.list, list) {
if ( ! F_20 ( V_333 , & V_331 -> V_125 ) )
continue;
F_63 ( & V_21 -> V_306 [ V_42 ] . V_174 , & V_331 -> V_218 ) ;
V_21 -> V_306 [ V_42 ] . type = F_141 ( V_331 -> type , V_331 -> V_335 ) ;
if ( V_331 -> type == V_221 || V_331 -> type == V_336 )
continue;
V_42 ++ ;
}
V_21 -> V_337 = F_7 ( V_42 ) ;
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_334 ) ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_332 , 0 , V_21 ,
V_22 ) ;
F_15 ( V_21 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_143 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_338 * V_113 )
{
struct V_102 * V_7 ;
int V_15 ;
V_7 = F_67 ( V_5 , V_339 , V_27 , V_113 ,
sizeof( * V_113 ) ) ;
if ( ! V_7 )
return - V_17 ;
V_15 = F_108 ( V_27 , V_340 ,
sizeof( V_113 -> V_306 . V_174 ) , & V_113 -> V_306 . V_174 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
return V_15 ;
}
static int F_144 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_199 * V_200 ;
struct V_341 * V_113 = V_25 ;
struct V_342 V_343 ;
struct V_102 * V_7 ;
int V_15 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_250 ) ;
goto V_226;
}
V_200 = F_140 ( V_27 , V_216 , & V_113 -> V_306 . V_174 ) ;
if ( ! V_200 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_326 ) ;
goto V_226;
}
if ( V_200 -> V_345 == V_346 && V_113 -> V_308 != 16 ) {
struct V_338 V_347 ;
memcpy ( & V_347 . V_306 , & V_113 -> V_306 , sizeof( V_347 . V_306 ) ) ;
F_130 ( L_13 ) ;
V_15 = F_143 ( V_5 , V_27 , & V_347 ) ;
if ( V_15 >= 0 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_224 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_344 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
F_63 ( & V_343 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_343 . V_308 = V_113 -> V_308 ;
memcpy ( V_343 . V_348 , V_113 -> V_348 , sizeof( V_343 . V_348 ) ) ;
V_15 = F_108 ( V_27 , V_349 , sizeof( V_343 ) , & V_343 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_145 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_350 * V_113 = V_25 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
V_27 -> V_351 = V_113 -> V_351 ;
F_4 ( L_14 , V_27 -> V_148 ,
V_27 -> V_351 ) ;
F_54 ( V_27 ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_352 , 0 , NULL ,
0 ) ;
}
static struct V_102 * F_146 ( struct V_199 * V_200 )
{
struct V_26 * V_27 = V_200 -> V_27 ;
struct V_102 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 != V_353 )
continue;
if ( V_7 -> V_354 != V_200 )
continue;
return V_7 ;
}
return NULL ;
}
static void F_147 ( struct V_102 * V_7 , T_1 V_8 )
{
struct V_355 V_21 ;
struct V_199 * V_200 = V_7 -> V_354 ;
F_63 ( & V_21 . V_306 . V_174 , & V_200 -> V_218 ) ;
V_21 . V_306 . type = F_141 ( V_200 -> type , V_200 -> V_335 ) ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_353 , V_8 ,
& V_21 , sizeof( V_21 ) ) ;
V_200 -> V_356 = NULL ;
V_200 -> V_357 = NULL ;
V_200 -> V_358 = NULL ;
F_148 ( V_200 ) ;
F_73 ( V_7 ) ;
}
void F_149 ( struct V_199 * V_200 , bool V_359 )
{
T_1 V_8 = V_359 ? V_239 : V_3 ;
struct V_102 * V_7 ;
V_7 = F_146 ( V_200 ) ;
if ( V_7 )
F_147 ( V_7 , V_8 ) ;
}
static void F_150 ( struct V_199 * V_200 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_15 , V_8 ) ;
V_7 = F_146 ( V_200 ) ;
if ( ! V_7 )
F_4 ( L_16 ) ;
else
F_147 ( V_7 , F_1 ( V_8 ) ) ;
}
static void F_151 ( struct V_199 * V_200 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_15 , V_8 ) ;
if ( ! V_8 )
return;
V_7 = F_146 ( V_200 ) ;
if ( ! V_7 )
F_4 ( L_16 ) ;
else
F_147 ( V_7 , F_1 ( V_8 ) ) ;
}
static int F_152 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_360 * V_113 = V_25 ;
struct V_355 V_21 ;
struct V_102 * V_7 ;
T_1 V_361 , V_362 ;
struct V_199 * V_200 ;
int V_15 ;
F_4 ( L_6 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
if ( ! F_135 ( V_113 -> V_306 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_353 ,
V_224 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_353 ,
V_250 , & V_21 , sizeof( V_21 ) ) ;
goto V_241;
}
V_361 = V_363 ;
V_362 = V_364 ;
if ( V_113 -> V_306 . type == V_307 ) {
V_200 = F_153 ( V_27 , & V_113 -> V_306 . V_174 , V_361 ,
V_362 ) ;
} else {
T_1 V_309 ;
if ( V_113 -> V_306 . type == V_316 )
V_309 = V_317 ;
else
V_309 = V_318 ;
V_200 = F_154 ( V_27 , & V_113 -> V_306 . V_174 , V_309 ,
V_361 , V_362 ) ;
}
if ( F_155 ( V_200 ) ) {
int V_8 ;
if ( F_156 ( V_200 ) == - V_365 )
V_8 = V_225 ;
else
V_8 = V_366 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_353 ,
V_8 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_241;
}
if ( V_200 -> V_356 ) {
F_148 ( V_200 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_353 ,
V_225 , & V_21 , sizeof( V_21 ) ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_353 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
F_148 ( V_200 ) ;
goto V_241;
}
if ( V_113 -> V_306 . type == V_307 ) {
V_200 -> V_356 = F_150 ;
V_200 -> V_357 = F_150 ;
V_200 -> V_358 = F_150 ;
} else {
V_200 -> V_356 = F_151 ;
V_200 -> V_357 = F_151 ;
V_200 -> V_358 = F_151 ;
}
V_200 -> V_351 = V_113 -> V_367 ;
V_7 -> V_354 = V_200 ;
if ( V_200 -> V_189 == V_209 &&
F_157 ( V_200 , V_361 , V_362 ) )
F_147 ( V_7 , 0 ) ;
V_15 = 0 ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_158 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_334 * V_306 = V_25 ;
struct V_102 * V_7 ;
struct V_199 * V_200 ;
int V_15 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_368 ,
V_250 ) ;
goto V_241;
}
V_7 = F_32 ( V_353 , V_27 ) ;
if ( ! V_7 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_368 ,
V_224 ) ;
goto V_241;
}
V_200 = V_7 -> V_354 ;
if ( F_159 ( & V_306 -> V_174 , & V_200 -> V_218 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_368 ,
V_224 ) ;
goto V_241;
}
F_147 ( V_7 , V_369 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_368 , 0 ,
V_306 , sizeof( * V_306 ) ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_160 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_334 * V_306 , T_2 V_288 ,
T_2 V_370 , T_7 V_371 )
{
struct V_102 * V_7 ;
struct V_199 * V_200 ;
int V_15 ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_288 ,
V_250 , V_306 ,
sizeof( * V_306 ) ) ;
goto V_372;
}
if ( V_306 -> type == V_307 )
V_200 = F_140 ( V_27 , V_216 , & V_306 -> V_174 ) ;
else
V_200 = F_140 ( V_27 , V_171 , & V_306 -> V_174 ) ;
if ( ! V_200 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_288 ,
V_326 , V_306 ,
sizeof( * V_306 ) ) ;
goto V_372;
}
if ( V_306 -> type == V_316 || V_306 -> type == V_329 ) {
F_54 ( V_27 ) ;
V_15 = F_161 ( V_200 , V_288 , V_371 ) ;
F_53 ( V_27 ) ;
if ( ! V_15 )
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_288 ,
V_239 , V_306 ,
sizeof( * V_306 ) ) ;
else
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_288 ,
V_3 , V_306 ,
sizeof( * V_306 ) ) ;
goto V_372;
}
V_7 = F_67 ( V_5 , V_288 , V_27 , V_306 , sizeof( * V_306 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_372;
}
if ( V_370 == V_373 ) {
struct V_374 V_113 ;
F_63 ( & V_113 . V_174 , & V_306 -> V_174 ) ;
V_113 . V_371 = V_371 ;
V_15 = F_108 ( V_27 , V_370 , sizeof( V_113 ) , & V_113 ) ;
} else
V_15 = F_108 ( V_27 , V_370 , sizeof( V_306 -> V_174 ) ,
& V_306 -> V_174 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_372:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_162 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_338 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_160 ( V_5 , V_27 , & V_113 -> V_306 ,
V_339 ,
V_340 , 0 ) ;
}
static int F_163 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_375 * V_113 = V_25 ;
F_4 ( L_6 ) ;
if ( V_20 != sizeof( * V_113 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_376 ,
V_224 ) ;
return F_160 ( V_5 , V_27 , & V_113 -> V_306 ,
V_376 ,
V_377 , 0 ) ;
}
static int F_164 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_378 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_160 ( V_5 , V_27 , & V_113 -> V_306 ,
V_379 ,
V_380 , 0 ) ;
}
static int F_165 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_381 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_160 ( V_5 , V_27 , & V_113 -> V_306 ,
V_382 ,
V_373 , V_113 -> V_371 ) ;
}
static int F_166 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_383 * V_113 = V_25 ;
F_4 ( L_6 ) ;
return F_160 ( V_5 , V_27 , & V_113 -> V_306 ,
V_384 ,
V_385 , 0 ) ;
}
static void F_167 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_386 V_113 ;
memcpy ( V_113 . V_148 , V_27 -> V_105 , sizeof( V_113 . V_148 ) ) ;
F_35 ( V_111 , V_387 , sizeof( V_113 ) , & V_113 ) ;
}
static void F_168 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_388 * V_113 ;
struct V_102 * V_7 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_389 , V_27 ) ;
if ( ! V_7 )
goto V_241;
V_113 = V_7 -> V_120 ;
if ( V_8 )
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_389 ,
F_1 ( V_8 ) ) ;
else
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_389 , 0 ,
V_113 , sizeof( * V_113 ) ) ;
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_169 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_388 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_6 ) ;
F_53 ( V_27 ) ;
if ( ! memcmp ( V_27 -> V_105 , V_113 -> V_148 , sizeof( V_27 -> V_105 ) ) &&
! memcmp ( V_27 -> V_178 , V_113 -> V_178 ,
sizeof( V_27 -> V_178 ) ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_389 , 0 ,
V_25 , V_20 ) ;
goto V_226;
}
memcpy ( V_27 -> V_178 , V_113 -> V_178 , sizeof( V_27 -> V_178 ) ) ;
if ( ! F_27 ( V_27 ) ) {
memcpy ( V_27 -> V_105 , V_113 -> V_148 , sizeof( V_27 -> V_105 ) ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_389 , 0 ,
V_25 , V_20 ) ;
if ( V_15 < 0 )
goto V_226;
V_15 = F_87 ( V_390 , V_27 , V_25 , V_20 ,
V_5 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_389 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
memcpy ( V_27 -> V_105 , V_113 -> V_148 , sizeof( V_27 -> V_105 ) ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_22 ( V_27 ) ) {
F_167 ( & V_111 ) ;
F_40 ( & V_111 ) ;
}
if ( F_25 ( V_27 ) )
F_34 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_168 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_170 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_102 * V_7 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_391 ,
V_250 ) ;
goto V_241;
}
if ( ! F_23 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_391 ,
V_237 ) ;
goto V_241;
}
if ( F_32 ( V_391 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_391 ,
V_225 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_391 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
if ( F_20 ( V_86 , & V_27 -> V_53 ) )
V_15 = F_108 ( V_27 , V_392 ,
0 , NULL ) ;
else
V_15 = F_108 ( V_27 , V_393 , 0 , NULL ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_171 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
int V_15 ;
F_4 ( L_17 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( V_20 == V_394 ) {
struct V_395 * V_113 = V_25 ;
T_1 V_8 ;
V_15 = F_172 ( V_27 , & V_113 -> V_306 . V_174 ,
V_113 -> V_396 , V_113 -> V_397 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_239 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_398 ,
V_8 , & V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
} else if ( V_20 == V_399 ) {
struct V_400 * V_113 = V_25 ;
T_1 V_8 ;
V_15 = F_173 ( V_27 , & V_113 -> V_306 . V_174 ,
V_113 -> V_401 ,
V_113 -> V_402 ,
V_113 -> V_403 ,
V_113 -> V_404 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_239 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_398 ,
V_8 , & V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
} else {
F_130 ( L_18 , V_20 ) ;
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_398 ,
V_224 ) ;
}
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_174 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_405 * V_113 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
V_15 = F_175 ( V_27 , & V_113 -> V_306 . V_174 ) ;
if ( V_15 < 0 )
V_8 = V_224 ;
else
V_8 = V_239 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_406 ,
V_8 , & V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_176 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
T_1 type ;
int V_15 ;
F_177 ( V_27 , V_407 ) ;
V_7 = F_32 ( V_408 , V_27 ) ;
if ( ! V_7 )
return - V_409 ;
type = V_27 -> V_188 . type ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& type , sizeof( type ) ) ;
F_73 ( V_7 ) ;
return V_15 ;
}
static void F_178 ( struct V_26 * V_27 , T_1 V_8 )
{
unsigned long V_249 = 0 ;
F_4 ( L_19 , V_8 ) ;
if ( V_8 ) {
F_53 ( V_27 ) ;
F_176 ( V_27 , V_8 ) ;
F_54 ( V_27 ) ;
return;
}
F_53 ( V_27 ) ;
F_177 ( V_27 , V_190 ) ;
F_54 ( V_27 ) ;
switch ( V_27 -> V_188 . type ) {
case V_410 :
V_249 = F_96 ( V_411 ) ;
break;
case V_412 :
V_249 = F_96 ( V_27 -> V_413 ) ;
break;
case V_414 :
break;
default:
F_130 ( L_20 , V_27 -> V_188 . type ) ;
}
if ( ! V_249 )
return;
F_86 ( V_27 -> V_246 , & V_27 -> V_193 , V_249 ) ;
}
static int F_179 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_415 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_416 V_417 ;
struct V_418 V_419 ;
struct V_420 V_421 ;
struct V_110 V_111 ;
T_1 V_422 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
T_1 V_8 , V_155 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_250 ) ;
goto V_226;
}
if ( F_20 ( V_423 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_225 ) ;
goto V_226;
}
if ( V_27 -> V_188 . V_189 != V_407 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_225 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_408 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
V_27 -> V_188 . type = V_113 -> type ;
F_52 ( & V_111 , V_27 ) ;
switch ( V_27 -> V_188 . type ) {
case V_414 :
V_8 = F_93 ( V_27 ) ;
if ( V_8 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_8 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
if ( F_20 ( V_191 , & V_27 -> V_125 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_225 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
F_180 ( V_27 ) ;
memset ( & V_421 , 0 , sizeof( V_421 ) ) ;
memcpy ( & V_421 . V_422 , V_422 , sizeof( V_421 . V_422 ) ) ;
V_421 . V_116 = V_424 ;
F_35 ( & V_111 , V_425 , sizeof( V_421 ) , & V_421 ) ;
break;
case V_410 :
case V_412 :
V_8 = F_94 ( V_27 ) ;
if ( V_8 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_8 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
if ( V_27 -> V_188 . type == V_412 &&
! F_20 ( V_80 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_237 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
if ( F_20 ( V_85 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_238 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
if ( F_20 ( V_198 , & V_27 -> V_53 ) )
F_81 ( & V_111 ) ;
memset ( & V_417 , 0 , sizeof( V_417 ) ) ;
V_15 = F_47 ( & V_111 , true , & V_155 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_3 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
V_417 . type = V_426 ;
V_417 . V_262 = F_7 ( V_427 ) ;
V_417 . V_264 = F_7 ( V_428 ) ;
V_417 . V_162 = V_155 ;
F_35 ( & V_111 , V_429 , sizeof( V_417 ) ,
& V_417 ) ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
V_419 . V_156 = V_430 ;
V_419 . V_431 = V_432 ;
F_35 ( & V_111 , V_433 , sizeof( V_419 ) ,
& V_419 ) ;
break;
default:
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_408 ,
V_224 ) ;
F_73 ( V_7 ) ;
goto V_226;
}
V_15 = F_55 ( & V_111 , F_178 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
else
F_177 ( V_27 , V_434 ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_181 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
int V_15 ;
V_7 = F_32 ( V_435 , V_27 ) ;
if ( ! V_7 )
return - V_409 ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& V_27 -> V_188 . type , sizeof( V_27 -> V_188 . type ) ) ;
F_73 ( V_7 ) ;
return V_15 ;
}
static void F_182 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_19 , V_8 ) ;
F_53 ( V_27 ) ;
if ( V_8 ) {
F_181 ( V_27 , V_8 ) ;
goto V_241;
}
F_177 ( V_27 , V_407 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_183 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_436 * V_437 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_184 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_435 ,
V_238 , & V_437 -> type ,
sizeof( V_437 -> type ) ) ;
goto V_241;
}
if ( V_27 -> V_188 . type != V_437 -> type ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_435 ,
V_224 , & V_437 -> type ,
sizeof( V_437 -> type ) ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_435 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
F_52 ( & V_111 , V_27 ) ;
F_80 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_182 ) ;
if ( ! V_15 ) {
F_177 ( V_27 , V_438 ) ;
goto V_241;
}
F_73 ( V_7 ) ;
if ( V_15 == - V_230 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_435 , 0 ,
& V_437 -> type , sizeof( V_437 -> type ) ) ;
F_177 ( V_27 , V_407 ) ;
}
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_185 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_439 * V_113 = V_25 ;
struct V_186 * V_187 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_53 ( V_27 ) ;
if ( ! F_184 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_440 ,
V_3 , & V_113 -> V_306 ,
sizeof( V_113 -> V_306 ) ) ;
goto V_226;
}
V_187 = F_186 ( V_27 , & V_113 -> V_306 . V_174 ) ;
if ( ! V_187 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_440 ,
V_224 , & V_113 -> V_306 ,
sizeof( V_113 -> V_306 ) ) ;
goto V_226;
}
if ( V_113 -> V_441 ) {
V_187 -> V_442 = V_443 ;
F_74 ( & V_187 -> V_180 ) ;
} else {
V_187 -> V_442 = V_444 ;
F_187 ( V_27 , V_187 ) ;
}
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_440 , 0 , & V_113 -> V_306 ,
sizeof( V_113 -> V_306 ) ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_188 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_445 * V_113 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_135 ( V_113 -> V_306 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_446 ,
V_224 ,
& V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
F_53 ( V_27 ) ;
V_15 = F_189 ( V_27 , & V_113 -> V_306 . V_174 , V_113 -> V_306 . type ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_239 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_446 , V_8 ,
& V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_190 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_447 * V_113 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_135 ( V_113 -> V_306 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_448 ,
V_224 ,
& V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
F_53 ( V_27 ) ;
V_15 = F_191 ( V_27 , & V_113 -> V_306 . V_174 , V_113 -> V_306 . type ) ;
if ( V_15 < 0 )
V_8 = V_224 ;
else
V_8 = V_239 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_448 , V_8 ,
& V_113 -> V_306 , sizeof( V_113 -> V_306 ) ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_192 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_449 * V_113 = V_25 ;
struct V_110 V_111 ;
int V_15 ;
T_9 V_450 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
V_450 = F_98 ( V_113 -> V_450 ) ;
if ( V_450 > 0x0002 )
return F_3 ( V_5 , V_27 -> V_55 , V_451 ,
V_224 ) ;
F_53 ( V_27 ) ;
V_27 -> V_136 = V_450 ;
V_27 -> V_138 = F_98 ( V_113 -> V_452 ) ;
V_27 -> V_139 = F_98 ( V_113 -> V_453 ) ;
V_27 -> V_140 = F_98 ( V_113 -> V_30 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_451 , 0 , NULL , 0 ) ;
F_52 ( & V_111 , V_27 ) ;
F_40 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_193 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 } ;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
F_70 ( V_280 , V_27 ,
F_92 , & V_242 ) ;
return;
}
F_70 ( V_280 , V_27 , F_91 ,
& V_236 ) ;
F_90 ( V_27 , V_236 . V_5 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
}
static int F_194 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
T_1 V_121 , V_279 , V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_94 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_280 ,
V_8 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_280 ,
V_224 ) ;
F_53 ( V_27 ) ;
V_121 = ! ! V_113 -> V_121 ;
V_279 = F_20 ( V_85 , & V_27 -> V_53 ) ;
if ( ! F_27 ( V_27 ) || V_121 == V_279 ||
F_58 ( V_27 , V_171 ) > 0 ) {
bool V_240 = false ;
if ( V_121 != F_20 ( V_85 , & V_27 -> V_53 ) ) {
F_99 ( V_85 , & V_27 -> V_53 ) ;
V_240 = true ;
}
V_15 = F_75 ( V_5 , V_280 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_241;
}
if ( F_32 ( V_280 , V_27 ) ||
F_32 ( V_277 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_280 ,
V_225 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_280 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
F_52 ( & V_111 , V_27 ) ;
if ( V_121 )
F_45 ( & V_111 ) ;
else
F_48 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_193 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_195 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_454 * V_113 = V_25 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_455 ,
V_237 ) ;
if ( F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_455 ,
V_238 ) ;
if ( F_159 ( & V_113 -> V_174 , V_195 ) ) {
if ( ! F_159 ( & V_113 -> V_174 , V_456 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_455 ,
V_224 ) ;
if ( ( V_113 -> V_174 . V_457 [ 5 ] & 0xc0 ) != 0xc0 )
return F_3 ( V_5 , V_27 -> V_55 ,
V_455 ,
V_224 ) ;
}
F_53 ( V_27 ) ;
F_63 ( & V_27 -> V_458 , & V_113 -> V_174 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_455 , 0 , NULL , 0 ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_196 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_459 * V_113 = V_25 ;
T_9 V_262 , V_264 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_460 ,
V_237 ) ;
V_262 = F_98 ( V_113 -> V_262 ) ;
if ( V_262 < 0x0004 || V_262 > 0x4000 )
return F_3 ( V_5 , V_27 -> V_55 , V_460 ,
V_224 ) ;
V_264 = F_98 ( V_113 -> V_264 ) ;
if ( V_264 < 0x0004 || V_264 > 0x4000 )
return F_3 ( V_5 , V_27 -> V_55 , V_460 ,
V_224 ) ;
if ( V_264 > V_262 )
return F_3 ( V_5 , V_27 -> V_55 , V_460 ,
V_224 ) ;
F_53 ( V_27 ) ;
V_27 -> V_461 = V_262 ;
V_27 -> V_462 = V_264 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_460 , 0 , NULL , 0 ) ;
if ( F_20 ( V_198 , & V_27 -> V_53 ) &&
V_27 -> V_188 . V_189 == V_407 ) {
struct V_110 V_111 ;
F_52 ( & V_111 , V_27 ) ;
F_81 ( & V_111 ) ;
F_197 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
}
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_198 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_463 , V_27 ) ;
if ( ! V_7 )
goto V_241;
if ( V_8 ) {
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_463 ,
F_1 ( V_8 ) ) ;
} else {
struct V_119 * V_113 = V_7 -> V_120 ;
if ( V_113 -> V_121 )
F_57 ( V_77 , & V_27 -> V_53 ) ;
else
F_46 ( V_77 , & V_27 -> V_53 ) ;
F_75 ( V_7 -> V_5 , V_463 , V_27 ) ;
F_90 ( V_27 , V_7 -> V_5 ) ;
}
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_199 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
if ( ! F_20 ( V_80 , & V_27 -> V_53 ) ||
V_27 -> V_63 < V_64 )
return F_3 ( V_5 , V_27 -> V_55 , V_463 ,
V_237 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_463 ,
V_224 ) ;
if ( ! F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_463 ,
V_250 ) ;
if ( ! F_20 ( V_76 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_463 ,
V_238 ) ;
F_53 ( V_27 ) ;
if ( F_32 ( V_463 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_463 ,
V_225 ) ;
goto V_241;
}
if ( ! ! V_113 -> V_121 == F_20 ( V_77 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_463 ,
V_27 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_463 , V_27 ,
V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
F_52 ( & V_111 , V_27 ) ;
F_101 ( & V_111 , V_113 -> V_121 ) ;
V_15 = F_55 ( & V_111 , F_198 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_463 ,
V_3 ) ;
F_73 ( V_7 ) ;
}
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_200 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
T_1 V_203 = 0 ;
F_101 ( V_111 , false ) ;
if ( F_20 ( V_76 , & V_27 -> V_53 ) )
V_203 |= V_252 ;
if ( F_20 ( V_78 , & V_27 -> V_53 ) )
V_203 |= V_258 ;
if ( V_203 )
F_35 ( V_111 , V_204 , 1 , & V_203 ) ;
}
static void F_201 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_7 = F_32 ( V_464 , V_27 ) ;
if ( ! V_7 )
goto V_241;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
F_46 ( V_80 , & V_27 -> V_53 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_242 ) ;
} else {
F_75 ( V_7 -> V_5 , V_464 , V_27 ) ;
F_90 ( V_27 , V_7 -> V_5 ) ;
}
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_202 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
struct V_110 V_111 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_22 ( V_27 ) || ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_237 ) ;
if ( ! F_20 ( V_81 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_238 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 == F_20 ( V_80 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_464 , V_27 ) ;
goto V_241;
}
if ( ! F_27 ( V_27 ) ) {
if ( ! V_113 -> V_121 ) {
F_46 ( V_78 , & V_27 -> V_53 ) ;
F_46 ( V_83 , & V_27 -> V_53 ) ;
F_46 ( V_82 , & V_27 -> V_53 ) ;
F_46 ( V_77 , & V_27 -> V_53 ) ;
F_46 ( V_84 , & V_27 -> V_53 ) ;
}
F_99 ( V_80 , & V_27 -> V_53 ) ;
V_15 = F_75 ( V_5 , V_464 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_241;
}
if ( ! V_113 -> V_121 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_238 ) ;
goto V_241;
}
if ( F_32 ( V_464 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_464 ,
V_225 ) ;
goto V_241;
}
V_7 = F_67 ( V_5 , V_464 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
F_57 ( V_80 , & V_27 -> V_53 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_76 , & V_27 -> V_53 ) )
F_200 ( & V_111 ) ;
F_38 ( & V_111 ) ;
V_15 = F_55 ( & V_111 , F_201 ) ;
if ( V_15 < 0 )
F_73 ( V_7 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_203 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
struct V_102 * V_7 ;
T_1 V_121 , V_8 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
V_8 = F_93 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_8 ) ;
if ( ! F_24 ( V_27 ) &&
! F_20 ( V_71 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_237 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 && V_113 -> V_121 != 0x02 )
return F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_240 ;
if ( V_113 -> V_121 ) {
V_240 = ! F_60 ( V_86 ,
& V_27 -> V_53 ) ;
if ( V_113 -> V_121 == 0x02 )
F_57 ( V_466 , & V_27 -> V_53 ) ;
else
F_46 ( V_466 , & V_27 -> V_53 ) ;
} else {
V_240 = F_51 ( V_86 ,
& V_27 -> V_53 ) ;
F_46 ( V_466 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_465 , V_27 ) ;
if ( V_15 < 0 )
goto V_226;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
goto V_226;
}
if ( F_32 ( V_465 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_465 ,
V_225 ) ;
goto V_226;
}
V_121 = ! ! V_113 -> V_121 ;
if ( V_121 == F_20 ( V_86 , & V_27 -> V_53 ) &&
( V_113 -> V_121 == 0x02 ) == F_20 ( V_466 , & V_27 -> V_53 ) ) {
V_15 = F_75 ( V_5 , V_465 , V_27 ) ;
goto V_226;
}
V_7 = F_67 ( V_5 , V_465 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_226;
}
V_15 = F_108 ( V_27 , V_467 , 1 , & V_121 ) ;
if ( V_15 < 0 ) {
F_73 ( V_7 ) ;
goto V_226;
}
if ( V_113 -> V_121 == 0x02 )
F_57 ( V_466 , & V_27 -> V_53 ) ;
else
F_46 ( V_466 , & V_27 -> V_53 ) ;
V_226:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_204 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_119 * V_113 = V_25 ;
bool V_240 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( V_113 -> V_121 != 0x00 && V_113 -> V_121 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_468 ,
V_224 ) ;
F_53 ( V_27 ) ;
if ( V_113 -> V_121 )
V_240 = ! F_60 ( V_87 , & V_27 -> V_53 ) ;
else
V_240 = F_51 ( V_87 , & V_27 -> V_53 ) ;
V_15 = F_75 ( V_5 , V_468 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static int F_205 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_469 ,
T_2 V_20 )
{
struct V_470 * V_113 = V_469 ;
bool V_240 ;
int V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_471 ,
V_237 ) ;
if ( V_113 -> V_472 != 0x00 && V_113 -> V_472 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_471 ,
V_224 ) ;
if ( F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_471 ,
V_238 ) ;
F_53 ( V_27 ) ;
F_57 ( V_473 , & V_27 -> V_53 ) ;
if ( V_113 -> V_472 ) {
V_240 = ! F_60 ( V_88 , & V_27 -> V_53 ) ;
memcpy ( V_27 -> V_474 , V_113 -> V_474 , sizeof( V_27 -> V_474 ) ) ;
F_57 ( V_170 , & V_27 -> V_53 ) ;
} else {
V_240 = F_51 ( V_88 , & V_27 -> V_53 ) ;
memset ( V_27 -> V_474 , 0 , sizeof( V_27 -> V_474 ) ) ;
F_46 ( V_170 , & V_27 -> V_53 ) ;
}
V_15 = F_75 ( V_5 , V_471 , V_27 ) ;
if ( V_15 < 0 )
goto V_241;
if ( V_240 )
V_15 = F_90 ( V_27 , V_5 ) ;
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_206 ( struct V_475 * V_474 )
{
switch ( V_474 -> V_306 . type ) {
case V_316 :
return true ;
case V_329 :
if ( ( V_474 -> V_306 . V_174 . V_457 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_207 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_469 ,
T_2 V_20 )
{
struct V_476 * V_113 = V_469 ;
T_2 V_477 , V_300 ;
int V_42 , V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_478 ,
V_237 ) ;
V_477 = F_98 ( V_113 -> V_477 ) ;
V_300 = sizeof( * V_113 ) + V_477 * sizeof( struct V_475 ) ;
if ( V_300 != V_20 ) {
F_130 ( L_21 ,
V_300 , V_20 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_478 ,
V_224 ) ;
}
F_4 ( L_22 , V_27 -> V_148 , V_477 ) ;
for ( V_42 = 0 ; V_42 < V_477 ; V_42 ++ ) {
struct V_475 * V_304 = & V_113 -> V_479 [ V_42 ] ;
if ( ! F_206 ( V_304 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_478 ,
V_224 ) ;
}
F_53 ( V_27 ) ;
F_208 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_477 ; V_42 ++ ) {
struct V_475 * V_474 = & V_113 -> V_479 [ V_42 ] ;
T_1 V_309 ;
if ( V_474 -> V_306 . type == V_316 )
V_309 = V_317 ;
else
V_309 = V_318 ;
F_209 ( V_27 , & V_474 -> V_306 . V_174 , V_309 , V_474 -> V_121 ,
V_195 ) ;
}
F_57 ( V_473 , & V_27 -> V_53 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_478 , 0 , NULL , 0 ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static bool F_210 ( struct V_480 * V_304 )
{
if ( V_304 -> V_481 != 0x00 && V_304 -> V_481 != 0x01 )
return false ;
switch ( V_304 -> V_306 . type ) {
case V_316 :
return true ;
case V_329 :
if ( ( V_304 -> V_306 . V_174 . V_457 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_211 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_469 , T_2 V_20 )
{
struct V_482 * V_113 = V_469 ;
T_2 V_299 , V_300 ;
int V_42 , V_15 ;
F_4 ( L_9 , V_27 -> V_148 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_483 ,
V_237 ) ;
V_299 = F_98 ( V_113 -> V_299 ) ;
V_300 = sizeof( * V_113 ) + V_299 *
sizeof( struct V_480 ) ;
if ( V_300 != V_20 ) {
F_130 ( L_23 ,
V_300 , V_20 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_483 ,
V_224 ) ;
}
F_4 ( L_24 , V_27 -> V_148 , V_299 ) ;
for ( V_42 = 0 ; V_42 < V_299 ; V_42 ++ ) {
struct V_480 * V_304 = & V_113 -> V_305 [ V_42 ] ;
if ( ! F_210 ( V_304 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_483 ,
V_224 ) ;
}
F_53 ( V_27 ) ;
F_212 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_299 ; V_42 ++ ) {
struct V_480 * V_304 = & V_113 -> V_305 [ V_42 ] ;
T_1 type , V_309 , V_484 ;
if ( V_304 -> V_306 . type == V_316 )
V_309 = V_317 ;
else
V_309 = V_318 ;
if ( V_304 -> V_481 )
type = V_485 ;
else
type = V_486 ;
switch ( V_304 -> type ) {
case V_487 :
V_484 = 0x00 ;
break;
case V_488 :
V_484 = 0x01 ;
break;
default:
continue;
}
F_213 ( V_27 , & V_304 -> V_306 . V_174 , V_309 , type ,
V_484 , V_304 -> V_121 , V_304 -> V_489 , V_304 -> V_490 ,
V_304 -> rand ) ;
}
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_483 , 0 ,
NULL , 0 ) ;
F_54 ( V_27 ) ;
return V_15 ;
}
static void F_214 ( struct V_102 * V_7 , void * V_25 )
{
struct V_491 * V_236 = V_25 ;
struct V_492 * V_113 ;
struct V_493 V_21 ;
struct V_199 * V_200 = V_7 -> V_354 ;
if ( V_200 != V_236 -> V_200 )
return;
V_113 = (struct V_492 * ) V_7 -> V_120 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
if ( ! V_236 -> F_1 ) {
V_21 . V_494 = V_200 -> V_494 ;
if ( V_236 -> V_495 ) {
V_21 . V_496 = V_200 -> V_496 ;
V_21 . V_497 = V_200 -> V_497 ;
} else {
V_21 . V_496 = V_129 ;
V_21 . V_497 = V_129 ;
}
}
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_498 ,
V_236 -> F_1 , & V_21 , sizeof( V_21 ) ) ;
F_148 ( V_200 ) ;
F_73 ( V_7 ) ;
}
static void F_215 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_499 * V_113 ;
struct V_199 * V_200 ;
struct V_491 V_236 ;
T_2 V_211 ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
V_236 . V_495 = ! V_8 ;
V_113 = F_216 ( V_27 , V_500 ) ;
if ( ! V_113 ) {
V_113 = F_216 ( V_27 , V_501 ) ;
V_8 = 0 ;
}
if ( ! V_113 ) {
F_130 ( L_25 ) ;
goto V_241;
}
V_211 = F_98 ( V_113 -> V_211 ) ;
V_200 = F_217 ( V_27 , V_211 ) ;
if ( ! V_200 ) {
F_130 ( L_26 , V_211 ) ;
goto V_241;
}
V_236 . V_200 = V_200 ;
V_236 . F_1 = F_1 ( V_8 ) ;
F_70 ( V_498 , V_27 ,
F_214 , & V_236 ) ;
V_241:
F_54 ( V_27 ) ;
}
static int F_218 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_492 * V_113 = V_25 ;
struct V_493 V_21 ;
struct V_199 * V_200 ;
unsigned long V_502 ;
int V_15 = 0 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
if ( ! F_135 ( V_113 -> V_306 . type ) )
return F_10 ( V_5 , V_27 -> V_55 , V_498 ,
V_224 ,
& V_21 , sizeof( V_21 ) ) ;
F_53 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_498 ,
V_250 , & V_21 , sizeof( V_21 ) ) ;
goto V_241;
}
if ( V_113 -> V_306 . type == V_307 )
V_200 = F_140 ( V_27 , V_216 ,
& V_113 -> V_306 . V_174 ) ;
else
V_200 = F_140 ( V_27 , V_171 , & V_113 -> V_306 . V_174 ) ;
if ( ! V_200 || V_200 -> V_189 != V_209 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_498 ,
V_326 , & V_21 , sizeof( V_21 ) ) ;
goto V_241;
}
V_502 = V_27 -> V_503 +
F_219 ( V_27 -> V_504 -
V_27 -> V_503 ) ;
if ( F_220 ( V_505 , V_200 -> V_506 +
F_96 ( V_502 ) ) ||
! V_200 -> V_506 ) {
struct V_110 V_111 ;
struct V_507 V_508 ;
struct V_499 V_509 ;
struct V_102 * V_7 ;
F_52 ( & V_111 , V_27 ) ;
V_509 . V_211 = F_7 ( V_200 -> V_211 ) ;
F_35 ( & V_111 , V_500 , sizeof( V_509 ) ,
& V_509 ) ;
if ( ! F_221 ( V_113 -> V_306 . type ) ||
V_200 -> V_496 == V_129 ) {
V_508 . V_211 = F_7 ( V_200 -> V_211 ) ;
V_508 . type = 0x00 ;
F_35 ( & V_111 , V_501 ,
sizeof( V_508 ) , & V_508 ) ;
}
if ( V_200 -> V_497 == V_129 ) {
V_508 . V_211 = F_7 ( V_200 -> V_211 ) ;
V_508 . type = 0x01 ;
F_35 ( & V_111 , V_501 ,
sizeof( V_508 ) , & V_508 ) ;
}
V_15 = F_55 ( & V_111 , F_215 ) ;
if ( V_15 < 0 )
goto V_241;
V_7 = F_67 ( V_5 , V_498 , V_27 ,
V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_241;
}
F_222 ( V_200 ) ;
V_7 -> V_354 = V_200 ;
V_200 -> V_506 = V_505 ;
} else {
V_21 . V_494 = V_200 -> V_494 ;
V_21 . V_496 = V_200 -> V_496 ;
V_21 . V_497 = V_200 -> V_497 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_498 ,
V_239 , & V_21 , sizeof( V_21 ) ) ;
}
V_241:
F_54 ( V_27 ) ;
return V_15 ;
}
int F_223 ( struct V_4 * V_5 , struct V_510 * V_511 , T_3 V_512 )
{
void * V_513 ;
T_1 * V_113 ;
struct V_11 * V_12 ;
T_2 V_18 , V_6 , V_20 ;
struct V_26 * V_27 = NULL ;
const struct V_514 * V_515 ;
int V_15 ;
F_4 ( L_27 , V_512 ) ;
if ( V_512 < sizeof( * V_12 ) )
return - V_516 ;
V_513 = F_13 ( V_512 , V_16 ) ;
if ( ! V_513 )
return - V_17 ;
if ( F_224 ( V_513 , V_511 -> V_517 , V_512 ) ) {
V_15 = - V_518 ;
goto V_372;
}
V_12 = V_513 ;
V_18 = F_98 ( V_12 -> V_18 ) ;
V_6 = F_98 ( V_12 -> V_6 ) ;
V_20 = F_98 ( V_12 -> V_20 ) ;
if ( V_20 != V_512 - sizeof( * V_12 ) ) {
V_15 = - V_516 ;
goto V_372;
}
if ( V_6 != V_34 ) {
V_27 = F_225 ( V_6 ) ;
if ( ! V_27 ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_519 ) ;
goto V_372;
}
if ( F_20 ( V_52 , & V_27 -> V_53 ) ||
F_20 ( V_54 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_519 ) ;
goto V_372;
}
}
if ( V_18 >= F_2 ( V_520 ) ||
V_520 [ V_18 ] . V_521 == NULL ) {
F_4 ( L_28 , V_18 ) ;
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_522 ) ;
goto V_372;
}
if ( ( V_27 && V_18 < V_179 ) ||
( ! V_27 && V_18 >= V_179 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_519 ) ;
goto V_372;
}
V_515 = & V_520 [ V_18 ] ;
if ( ( V_515 -> V_523 && V_20 < V_515 -> V_28 ) ||
( ! V_515 -> V_523 && V_20 != V_515 -> V_28 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_224 ) ;
goto V_372;
}
if ( V_27 )
F_59 ( V_5 , V_27 ) ;
V_113 = V_513 + sizeof( * V_12 ) ;
V_15 = V_515 -> V_521 ( V_5 , V_27 , V_113 , V_20 ) ;
if ( V_15 < 0 )
goto V_372;
V_15 = V_512 ;
V_372:
if ( V_27 )
F_226 ( V_27 ) ;
F_15 ( V_513 ) ;
return V_15 ;
}
void F_227 ( struct V_26 * V_27 )
{
if ( V_27 -> V_49 != V_50 )
return;
F_87 ( V_524 , V_27 , NULL , 0 , NULL ) ;
}
void F_228 ( struct V_26 * V_27 )
{
T_1 V_8 = V_519 ;
if ( V_27 -> V_49 != V_50 )
return;
F_70 ( 0 , V_27 , F_92 , & V_8 ) ;
F_87 ( V_525 , V_27 , NULL , 0 , NULL ) ;
}
static void F_229 ( struct V_26 * V_27 )
{
struct V_526 * V_527 ;
F_18 (p, &hdev->le_conn_params, list) {
if ( V_527 -> V_528 == V_529 )
F_230 ( V_27 , & V_527 -> V_306 , V_527 -> V_309 ) ;
}
}
static void F_231 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 } ;
F_4 ( L_10 , V_8 ) ;
F_53 ( V_27 ) ;
F_229 ( V_27 ) ;
F_70 ( V_223 , V_27 , F_91 , & V_236 ) ;
F_90 ( V_27 , V_236 . V_5 ) ;
F_54 ( V_27 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
}
static int F_232 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
T_1 V_530 ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_83 , & V_27 -> V_53 ) &&
! F_233 ( V_27 ) ) {
T_1 V_531 = 1 ;
F_35 ( & V_111 , V_276 , 1 , & V_531 ) ;
}
if ( F_20 ( V_81 , & V_27 -> V_53 ) &&
F_22 ( V_27 ) ) {
struct V_278 V_113 ;
V_113 . V_281 = 1 ;
V_113 . V_282 = F_114 ( V_27 ) ;
if ( V_113 . V_281 != F_113 ( V_27 ) ||
V_113 . V_282 != F_234 ( V_27 ) )
F_35 ( & V_111 , V_283 ,
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
V_530 = F_20 ( V_82 , & V_27 -> V_53 ) ;
if ( V_530 != F_20 ( V_272 , & V_27 -> V_125 ) )
F_35 ( & V_111 , V_273 ,
sizeof( V_530 ) , & V_530 ) ;
if ( F_22 ( V_27 ) ) {
if ( F_20 ( V_80 , & V_27 -> V_53 ) )
F_200 ( & V_111 ) ;
F_43 ( & V_111 ) ;
F_167 ( & V_111 ) ;
F_40 ( & V_111 ) ;
}
return F_55 ( & V_111 , F_231 ) ;
}
int F_85 ( struct V_26 * V_27 , T_1 V_532 )
{
struct V_235 V_236 = { NULL , V_27 } ;
T_1 V_533 = V_250 ;
T_1 V_534 [] = { 0 , 0 , 0 } ;
int V_15 ;
if ( ! F_20 ( V_172 , & V_27 -> V_53 ) )
return 0 ;
if ( V_532 ) {
if ( F_232 ( V_27 ) == 0 )
return 0 ;
F_70 ( V_223 , V_27 , F_91 ,
& V_236 ) ;
goto F_90;
}
F_70 ( V_223 , V_27 , F_91 , & V_236 ) ;
F_70 ( 0 , V_27 , F_92 , & V_533 ) ;
if ( memcmp ( V_27 -> V_151 , V_534 , sizeof( V_534 ) ) != 0 )
F_87 ( V_535 , V_27 ,
V_534 , sizeof( V_534 ) , NULL ) ;
F_90:
V_15 = F_90 ( V_27 , V_236 . V_5 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
return V_15 ;
}
void F_235 ( struct V_26 * V_27 , int V_15 )
{
struct V_102 * V_7 ;
T_1 V_8 ;
V_7 = F_32 ( V_223 , V_27 ) ;
if ( ! V_7 )
return;
if ( V_15 == - V_536 )
V_8 = V_537 ;
else
V_8 = V_3 ;
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_223 , V_8 ) ;
F_73 ( V_7 ) ;
}
void F_236 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
F_53 ( V_27 ) ;
F_46 ( V_124 , & V_27 -> V_53 ) ;
F_46 ( V_78 , & V_27 -> V_53 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_80 , & V_27 -> V_53 ) ) {
T_1 V_203 = V_252 ;
F_35 ( & V_111 , V_204 ,
sizeof( V_203 ) , & V_203 ) ;
}
F_43 ( & V_111 ) ;
F_38 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
V_27 -> V_244 = 0 ;
F_90 ( V_27 , NULL ) ;
F_54 ( V_27 ) ;
}
void F_237 ( struct V_26 * V_27 , T_1 V_538 )
{
bool V_240 ;
if ( F_32 ( V_118 , V_27 ) )
return;
if ( ! V_538 && F_32 ( V_223 , V_27 ) )
return;
if ( V_538 ) {
V_240 = ! F_60 ( V_78 , & V_27 -> V_53 ) ;
} else {
F_46 ( V_124 , & V_27 -> V_53 ) ;
V_240 = F_51 ( V_78 , & V_27 -> V_53 ) ;
}
if ( V_240 ) {
struct V_110 V_111 ;
F_52 ( & V_111 , V_27 ) ;
F_38 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
F_90 ( V_27 , NULL ) ;
}
}
void F_238 ( struct V_26 * V_27 , T_1 V_157 )
{
bool V_240 ;
if ( F_32 ( V_153 , V_27 ) )
return;
if ( ! V_157 && F_32 ( V_223 , V_27 ) )
return;
if ( V_157 )
V_240 = ! F_60 ( V_76 , & V_27 -> V_53 ) ;
else
V_240 = F_51 ( V_76 , & V_27 -> V_53 ) ;
if ( V_240 )
F_90 ( V_27 , NULL ) ;
}
void F_239 ( struct V_26 * V_27 , T_1 V_539 )
{
if ( ! V_539 && F_32 ( V_223 , V_27 ) )
return;
if ( V_539 )
F_57 ( V_85 , & V_27 -> V_53 ) ;
else
F_46 ( V_85 , & V_27 -> V_53 ) ;
}
void F_240 ( struct V_26 * V_27 , T_1 V_203 , T_1 V_8 )
{
T_1 V_242 = F_1 ( V_8 ) ;
if ( V_203 & V_252 )
F_70 ( V_153 , V_27 ,
F_92 , & V_242 ) ;
if ( V_203 & V_258 )
F_70 ( V_118 , V_27 ,
F_92 , & V_242 ) ;
}
void F_241 ( struct V_26 * V_27 , struct V_540 * V_304 ,
bool V_541 )
{
struct V_542 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_543 = V_541 ;
F_63 ( & V_14 . V_304 . V_306 . V_174 , & V_304 -> V_174 ) ;
V_14 . V_304 . V_306 . type = V_307 ;
V_14 . V_304 . type = V_304 -> type ;
memcpy ( V_14 . V_304 . V_121 , V_304 -> V_121 , V_544 ) ;
V_14 . V_304 . V_308 = V_304 -> V_308 ;
F_87 ( V_545 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static T_1 F_242 ( struct V_546 * V_547 )
{
if ( V_547 -> V_484 )
return V_488 ;
return V_487 ;
}
void F_243 ( struct V_26 * V_27 , struct V_546 * V_304 , bool V_541 )
{
struct V_548 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( V_304 -> V_549 == V_318 &&
( V_304 -> V_174 . V_457 [ 5 ] & 0xc0 ) != 0xc0 )
V_14 . V_543 = 0x00 ;
else
V_14 . V_543 = V_541 ;
F_63 ( & V_14 . V_304 . V_306 . V_174 , & V_304 -> V_174 ) ;
V_14 . V_304 . V_306 . type = F_141 ( V_171 , V_304 -> V_549 ) ;
V_14 . V_304 . type = F_242 ( V_304 ) ;
V_14 . V_304 . V_489 = V_304 -> V_489 ;
V_14 . V_304 . V_490 = V_304 -> V_490 ;
V_14 . V_304 . rand = V_304 -> rand ;
if ( V_304 -> type == V_485 )
V_14 . V_304 . V_481 = 1 ;
memcpy ( V_14 . V_304 . V_121 , V_304 -> V_121 , sizeof( V_304 -> V_121 ) ) ;
F_87 ( V_550 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_244 ( struct V_26 * V_27 , struct V_551 * V_474 )
{
struct V_552 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( F_159 ( & V_474 -> V_553 , V_195 ) )
V_14 . V_543 = 0x01 ;
else
V_14 . V_543 = 0x00 ;
F_63 ( & V_14 . V_553 , & V_474 -> V_553 ) ;
F_63 ( & V_14 . V_474 . V_306 . V_174 , & V_474 -> V_174 ) ;
V_14 . V_474 . V_306 . type = F_141 ( V_171 , V_474 -> V_309 ) ;
memcpy ( V_14 . V_474 . V_121 , V_474 -> V_121 , sizeof( V_474 -> V_121 ) ) ;
F_87 ( V_554 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_245 ( struct V_26 * V_27 , struct V_555 * V_556 ,
bool V_541 )
{
struct V_557 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( V_556 -> V_549 == V_318 &&
( V_556 -> V_174 . V_457 [ 5 ] & 0xc0 ) != 0xc0 )
V_14 . V_543 = 0x00 ;
else
V_14 . V_543 = V_541 ;
F_63 ( & V_14 . V_304 . V_306 . V_174 , & V_556 -> V_174 ) ;
V_14 . V_304 . V_306 . type = F_141 ( V_171 , V_556 -> V_549 ) ;
V_14 . V_304 . V_481 = V_556 -> V_481 ;
memcpy ( V_14 . V_304 . V_121 , V_556 -> V_121 , sizeof( V_556 -> V_121 ) ) ;
F_87 ( V_558 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static inline T_2 F_246 ( T_1 * V_144 , T_2 V_559 , T_1 type , T_1 * V_25 ,
T_1 V_28 )
{
V_144 [ V_559 ++ ] = sizeof( type ) + V_28 ;
V_144 [ V_559 ++ ] = type ;
memcpy ( & V_144 [ V_559 ] , V_25 , V_28 ) ;
V_559 += V_28 ;
return V_559 ;
}
void F_247 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_328 ,
T_1 V_309 , T_5 V_125 , T_1 * V_148 , T_1 V_104 ,
T_1 * V_151 )
{
char V_513 [ 512 ] ;
struct V_560 * V_14 = ( void * ) V_513 ;
T_2 V_559 = 0 ;
F_63 ( & V_14 -> V_306 . V_174 , V_174 ) ;
V_14 -> V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 -> V_125 = F_248 ( V_125 ) ;
if ( V_104 > 0 )
V_559 = F_246 ( V_14 -> V_144 , 0 , V_109 ,
V_148 , V_104 ) ;
if ( V_151 && memcmp ( V_151 , L_29 , 3 ) != 0 )
V_559 = F_246 ( V_14 -> V_144 , V_559 ,
V_561 , V_151 , 3 ) ;
V_14 -> V_559 = F_7 ( V_559 ) ;
F_87 ( V_562 , V_27 , V_513 ,
sizeof( * V_14 ) + V_559 , NULL ) ;
}
static void F_249 ( struct V_102 * V_7 , void * V_25 )
{
struct V_320 * V_113 = V_7 -> V_120 ;
struct V_4 * * V_5 = V_25 ;
struct V_321 V_21 ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_322 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
* V_5 = V_7 -> V_5 ;
F_68 ( * V_5 ) ;
F_73 ( V_7 ) ;
}
static void F_250 ( struct V_102 * V_7 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_312 * V_113 = V_7 -> V_120 ;
struct V_313 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_63 ( & V_21 . V_306 . V_174 , & V_113 -> V_306 . V_174 ) ;
V_21 . V_306 . type = V_113 -> V_306 . type ;
F_133 ( V_27 , & V_113 -> V_306 . V_174 , V_113 -> V_306 . type , V_7 -> V_5 ) ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , 0 , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
void F_251 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_212 ,
bool V_563 )
{
struct V_564 V_14 ;
struct V_102 * V_183 ;
struct V_4 * V_5 = NULL ;
V_183 = F_32 ( V_223 , V_27 ) ;
if ( V_183 ) {
struct V_119 * V_113 = V_183 -> V_120 ;
if ( ! V_113 -> V_121 && F_77 ( V_27 ) == 1 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
}
}
if ( ! V_563 )
return;
if ( V_328 != V_216 && V_328 != V_171 )
return;
F_70 ( V_322 , V_27 , F_249 , & V_5 ) ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 . V_212 = V_212 ;
F_87 ( V_565 , V_27 , & V_14 , sizeof( V_14 ) , V_5 ) ;
if ( V_5 )
F_66 ( V_5 ) ;
F_70 ( V_314 , V_27 , F_250 ,
V_27 ) ;
}
void F_252 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_8 )
{
T_1 V_549 = F_141 ( V_328 , V_309 ) ;
struct V_320 * V_113 ;
struct V_321 V_21 ;
struct V_102 * V_7 ;
F_70 ( V_314 , V_27 , F_250 ,
V_27 ) ;
V_7 = F_32 ( V_322 , V_27 ) ;
if ( ! V_7 )
return;
V_113 = V_7 -> V_120 ;
if ( F_159 ( V_174 , & V_113 -> V_306 . V_174 ) )
return;
if ( V_113 -> V_306 . type != V_549 )
return;
F_63 ( & V_21 . V_306 . V_174 , V_174 ) ;
V_21 . V_306 . type = V_549 ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_322 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
void F_253 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_328 ,
T_1 V_309 , T_1 V_8 )
{
struct V_566 V_14 ;
struct V_102 * V_183 ;
V_183 = F_32 ( V_223 , V_27 ) ;
if ( V_183 ) {
struct V_119 * V_113 = V_183 -> V_120 ;
if ( ! V_113 -> V_121 && F_77 ( V_27 ) == 1 ) {
F_78 ( & V_27 -> V_183 ) ;
F_79 ( V_27 -> V_184 , & V_27 -> V_183 . V_168 ) ;
}
}
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
F_87 ( V_567 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_254 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_568 )
{
struct V_569 V_14 ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = V_307 ;
V_14 . V_568 = V_568 ;
F_87 ( V_570 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_255 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_571 V_21 ;
V_7 = F_32 ( V_344 , V_27 ) ;
if ( ! V_7 )
return;
F_63 ( & V_21 . V_306 . V_174 , V_174 ) ;
V_21 . V_306 . type = V_307 ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_344 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
void F_256 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_8 )
{
struct V_102 * V_7 ;
struct V_571 V_21 ;
V_7 = F_32 ( V_339 , V_27 ) ;
if ( ! V_7 )
return;
F_63 ( & V_21 . V_306 . V_174 , V_174 ) ;
V_21 . V_306 . type = V_307 ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_339 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
}
int F_257 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_5 V_572 ,
T_1 V_573 )
{
struct V_574 V_14 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 . V_573 = V_573 ;
V_14 . V_572 = F_64 ( V_572 ) ;
return F_87 ( V_575 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_258 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 )
{
struct V_576 V_14 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = F_141 ( V_328 , V_309 ) ;
return F_87 ( V_577 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
static int F_259 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_8 ,
T_1 V_18 )
{
struct V_102 * V_7 ;
struct V_578 V_21 ;
int V_15 ;
V_7 = F_32 ( V_18 , V_27 ) ;
if ( ! V_7 )
return - V_409 ;
F_63 ( & V_21 . V_306 . V_174 , V_174 ) ;
V_21 . V_306 . type = F_141 ( V_328 , V_309 ) ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_18 , F_1 ( V_8 ) ,
& V_21 , sizeof( V_21 ) ) ;
F_73 ( V_7 ) ;
return V_15 ;
}
int F_260 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_8 )
{
return F_259 ( V_27 , V_174 , V_328 , V_309 ,
V_8 , V_376 ) ;
}
int F_261 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_8 )
{
return F_259 ( V_27 , V_174 , V_328 , V_309 ,
V_8 ,
V_379 ) ;
}
int F_262 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_8 )
{
return F_259 ( V_27 , V_174 , V_328 , V_309 ,
V_8 , V_382 ) ;
}
int F_263 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_1 V_8 )
{
return F_259 ( V_27 , V_174 , V_328 , V_309 ,
V_8 ,
V_384 ) ;
}
int F_264 ( struct V_26 * V_27 , T_8 * V_174 ,
T_1 V_328 , T_1 V_309 , T_5 V_371 ,
T_1 V_579 )
{
struct V_580 V_14 ;
F_4 ( L_5 , V_27 -> V_148 ) ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 . V_371 = F_248 ( V_371 ) ;
V_14 . V_579 = V_579 ;
return F_87 ( V_581 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_265 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_328 ,
T_1 V_309 , T_1 V_8 )
{
struct V_582 V_14 ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
F_87 ( V_583 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_266 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 } ;
bool V_240 ;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
F_70 ( V_271 , V_27 ,
F_92 , & V_242 ) ;
return;
}
if ( F_20 ( V_272 , & V_27 -> V_125 ) )
V_240 = ! F_60 ( V_82 ,
& V_27 -> V_53 ) ;
else
V_240 = F_51 ( V_82 ,
& V_27 -> V_53 ) ;
F_70 ( V_271 , V_27 , F_91 ,
& V_236 ) ;
if ( V_240 )
F_90 ( V_27 , V_236 . V_5 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
}
static void F_267 ( struct V_110 * V_111 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
struct V_142 V_113 ;
if ( ! F_41 ( V_27 ) )
return;
memset ( V_27 -> V_144 , 0 , sizeof( V_27 -> V_144 ) ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
F_35 ( V_111 , V_145 , sizeof( V_113 ) , & V_113 ) ;
}
void F_268 ( struct V_26 * V_27 , T_1 V_156 , T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 } ;
struct V_110 V_111 ;
bool V_240 = false ;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
if ( V_156 && F_51 ( V_83 ,
& V_27 -> V_53 ) ) {
F_46 ( V_84 , & V_27 -> V_53 ) ;
F_90 ( V_27 , NULL ) ;
}
F_70 ( V_274 , V_27 , F_92 ,
& V_242 ) ;
return;
}
if ( V_156 ) {
V_240 = ! F_60 ( V_83 , & V_27 -> V_53 ) ;
} else {
V_240 = F_51 ( V_83 , & V_27 -> V_53 ) ;
if ( ! V_240 )
V_240 = F_51 ( V_84 ,
& V_27 -> V_53 ) ;
else
F_46 ( V_84 , & V_27 -> V_53 ) ;
}
F_70 ( V_274 , V_27 , F_91 , & V_236 ) ;
if ( V_240 )
F_90 ( V_27 , V_236 . V_5 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
F_52 ( & V_111 , V_27 ) ;
if ( F_20 ( V_83 , & V_27 -> V_53 ) )
F_40 ( & V_111 ) ;
else
F_267 ( & V_111 ) ;
F_55 ( & V_111 , NULL ) ;
}
void F_269 ( struct V_26 * V_27 , T_1 V_156 , T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 } ;
bool V_240 = false ;
if ( V_8 ) {
T_1 V_242 = F_1 ( V_8 ) ;
if ( V_156 ) {
if ( F_51 ( V_86 ,
& V_27 -> V_53 ) )
F_90 ( V_27 , NULL ) ;
F_46 ( V_466 , & V_27 -> V_53 ) ;
}
F_70 ( V_465 , V_27 ,
F_92 , & V_242 ) ;
return;
}
if ( V_156 ) {
V_240 = ! F_60 ( V_86 , & V_27 -> V_53 ) ;
} else {
V_240 = F_51 ( V_86 , & V_27 -> V_53 ) ;
F_46 ( V_466 , & V_27 -> V_53 ) ;
}
F_70 ( V_465 , V_27 ,
F_91 , & V_236 ) ;
if ( V_240 )
F_90 ( V_27 , V_236 . V_5 ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
}
static void F_270 ( struct V_102 * V_7 , void * V_25 )
{
struct V_235 * V_236 = V_25 ;
if ( V_236 -> V_5 == NULL ) {
V_236 -> V_5 = V_7 -> V_5 ;
F_68 ( V_236 -> V_5 ) ;
}
}
void F_271 ( struct V_26 * V_27 , T_1 * V_151 ,
T_1 V_8 )
{
struct V_235 V_236 = { NULL , V_27 , F_1 (status) } ;
F_70 ( V_286 , V_27 , F_270 , & V_236 ) ;
F_70 ( V_284 , V_27 , F_270 , & V_236 ) ;
F_70 ( V_285 , V_27 , F_270 , & V_236 ) ;
if ( ! V_8 )
F_87 ( V_535 , V_27 , V_151 , 3 ,
NULL ) ;
if ( V_236 . V_5 )
F_66 ( V_236 . V_5 ) ;
}
void F_272 ( struct V_26 * V_27 , T_1 * V_148 , T_1 V_8 )
{
struct V_388 V_14 ;
struct V_102 * V_7 ;
if ( V_8 )
return;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_148 , V_148 , V_584 ) ;
memcpy ( V_14 . V_178 , V_27 -> V_178 , V_585 ) ;
V_7 = F_32 ( V_389 , V_27 ) ;
if ( ! V_7 ) {
memcpy ( V_27 -> V_105 , V_148 , sizeof( V_27 -> V_105 ) ) ;
if ( F_32 ( V_223 , V_27 ) )
return;
}
F_87 ( V_390 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
void F_273 ( struct V_26 * V_27 , T_1 * V_401 ,
T_1 * V_402 , T_1 * V_403 ,
T_1 * V_404 , T_1 V_8 )
{
struct V_102 * V_7 ;
F_4 ( L_30 , V_27 -> V_148 , V_8 ) ;
V_7 = F_32 ( V_391 , V_27 ) ;
if ( ! V_7 )
return;
if ( V_8 ) {
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_391 ,
F_1 ( V_8 ) ) ;
} else {
if ( F_20 ( V_86 , & V_27 -> V_53 ) &&
V_403 && V_404 ) {
struct V_586 V_21 ;
memcpy ( V_21 . V_401 , V_401 , sizeof( V_21 . V_401 ) ) ;
memcpy ( V_21 . V_402 , V_402 ,
sizeof( V_21 . V_402 ) ) ;
memcpy ( V_21 . V_403 , V_403 , sizeof( V_21 . V_403 ) ) ;
memcpy ( V_21 . V_404 , V_404 ,
sizeof( V_21 . V_404 ) ) ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 ,
V_391 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
} else {
struct V_587 V_21 ;
memcpy ( V_21 . V_396 , V_401 , sizeof( V_21 . V_396 ) ) ;
memcpy ( V_21 . V_397 , V_402 ,
sizeof( V_21 . V_397 ) ) ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 ,
V_391 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
}
}
F_73 ( V_7 ) ;
}
void F_274 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_328 ,
T_1 V_309 , T_1 * V_151 , T_10 V_494 , T_1 V_588 ,
T_1 V_531 , T_1 * V_144 , T_2 V_559 , T_1 * V_589 ,
T_1 V_590 )
{
char V_513 [ 512 ] ;
struct V_591 * V_14 = ( void * ) V_513 ;
struct V_551 * V_474 ;
T_3 V_592 ;
if ( ! F_184 ( V_27 ) )
return;
if ( sizeof( * V_14 ) + V_559 + V_590 + 5 > sizeof( V_513 ) )
return;
memset ( V_513 , 0 , sizeof( V_513 ) ) ;
V_474 = F_275 ( V_27 , V_174 , V_309 ) ;
if ( V_474 ) {
F_63 ( & V_14 -> V_306 . V_174 , & V_474 -> V_174 ) ;
V_14 -> V_306 . type = F_141 ( V_328 , V_474 -> V_309 ) ;
} else {
F_63 ( & V_14 -> V_306 . V_174 , V_174 ) ;
V_14 -> V_306 . type = F_141 ( V_328 , V_309 ) ;
}
V_14 -> V_494 = V_494 ;
if ( V_588 )
V_14 -> V_125 |= F_64 ( V_593 ) ;
if ( ! V_531 )
V_14 -> V_125 |= F_64 ( V_594 ) ;
if ( V_559 > 0 )
memcpy ( V_14 -> V_144 , V_144 , V_559 ) ;
if ( V_151 && ! F_276 ( V_14 -> V_144 , V_559 , V_561 ) )
V_559 = F_246 ( V_14 -> V_144 , V_559 , V_561 ,
V_151 , 3 ) ;
if ( V_590 > 0 )
memcpy ( V_14 -> V_144 + V_559 , V_589 , V_590 ) ;
V_14 -> V_559 = F_7 ( V_559 + V_590 ) ;
V_592 = sizeof( * V_14 ) + V_559 + V_590 ;
F_87 ( V_595 , V_27 , V_14 , V_592 , NULL ) ;
}
void F_277 ( struct V_26 * V_27 , T_8 * V_174 , T_1 V_328 ,
T_1 V_309 , T_10 V_494 , T_1 * V_148 , T_1 V_104 )
{
struct V_591 * V_14 ;
char V_513 [ sizeof( * V_14 ) + V_584 + 2 ] ;
T_2 V_559 ;
V_14 = (struct V_591 * ) V_513 ;
memset ( V_513 , 0 , sizeof( V_513 ) ) ;
F_63 ( & V_14 -> V_306 . V_174 , V_174 ) ;
V_14 -> V_306 . type = F_141 ( V_328 , V_309 ) ;
V_14 -> V_494 = V_494 ;
V_559 = F_246 ( V_14 -> V_144 , 0 , V_109 , V_148 ,
V_104 ) ;
V_14 -> V_559 = F_7 ( V_559 ) ;
F_87 ( V_595 , V_27 , V_14 , sizeof( * V_14 ) + V_559 , NULL ) ;
}
void F_278 ( struct V_26 * V_27 , T_1 V_596 )
{
struct V_597 V_14 ;
struct V_102 * V_7 ;
F_4 ( L_31 , V_27 -> V_148 , V_596 ) ;
if ( V_596 )
V_7 = F_32 ( V_408 , V_27 ) ;
else
V_7 = F_32 ( V_435 , V_27 ) ;
if ( V_7 != NULL ) {
T_1 type = V_27 -> V_188 . type ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , 0 , & type ,
sizeof( type ) ) ;
F_73 ( V_7 ) ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . type = V_27 -> V_188 . type ;
V_14 . V_596 = V_596 ;
F_87 ( V_598 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_279 ( struct V_26 * V_27 , T_8 * V_174 , T_1 type )
{
struct V_102 * V_7 ;
struct V_599 V_14 ;
V_7 = F_32 ( V_446 , V_27 ) ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = type ;
return F_87 ( V_600 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
int F_280 ( struct V_26 * V_27 , T_8 * V_174 , T_1 type )
{
struct V_102 * V_7 ;
struct V_601 V_14 ;
V_7 = F_32 ( V_448 , V_27 ) ;
F_63 ( & V_14 . V_306 . V_174 , V_174 ) ;
V_14 . V_306 . type = type ;
return F_87 ( V_602 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
static void F_281 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_30 , V_27 -> V_148 , V_8 ) ;
if ( V_8 ) {
F_46 ( V_85 , & V_27 -> V_53 ) ;
F_90 ( V_27 , NULL ) ;
}
}
void F_282 ( struct V_26 * V_27 )
{
struct V_110 V_111 ;
if ( F_58 ( V_27 , V_171 ) > 0 )
return;
if ( ! F_20 ( V_85 , & V_27 -> V_53 ) )
return;
F_52 ( & V_111 , V_27 ) ;
F_45 ( & V_111 ) ;
if ( F_55 ( & V_111 , F_281 ) < 0 ) {
F_46 ( V_85 , & V_27 -> V_53 ) ;
F_90 ( V_27 , NULL ) ;
}
}
