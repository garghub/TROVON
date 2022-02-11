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
V_12 -> V_6 = F_8 ( V_6 ) ;
V_12 -> V_20 = F_8 ( sizeof( * V_14 ) ) ;
V_14 = ( void * ) F_6 ( V_10 , sizeof( * V_14 ) ) ;
V_14 -> V_8 = V_8 ;
V_14 -> V_18 = F_8 ( V_7 ) ;
V_15 = F_9 ( V_5 , V_10 ) ;
if ( V_15 < 0 )
F_10 ( V_10 ) ;
return V_15 ;
}
static int F_11 ( struct V_4 * V_5 , T_2 V_6 , T_2 V_7 , T_1 V_8 ,
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
V_12 -> V_6 = F_8 ( V_6 ) ;
V_12 -> V_20 = F_8 ( sizeof( * V_14 ) + V_22 ) ;
V_14 = ( void * ) F_6 ( V_10 , sizeof( * V_14 ) + V_22 ) ;
V_14 -> V_18 = F_8 ( V_7 ) ;
V_14 -> V_8 = V_8 ;
if ( V_21 )
memcpy ( V_14 -> V_25 , V_21 , V_22 ) ;
V_15 = F_9 ( V_5 , V_10 ) ;
if ( V_15 < 0 )
F_10 ( V_10 ) ;
return V_15 ;
}
static int F_12 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_29 V_21 ;
F_4 ( L_2 , V_5 ) ;
V_21 . V_30 = V_31 ;
V_21 . V_32 = F_7 ( V_33 ) ;
return F_11 ( V_5 , V_34 , V_35 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static int F_13 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
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
V_21 = F_14 ( V_41 , V_16 ) ;
if ( ! V_21 )
return - V_17 ;
V_21 -> V_37 = F_7 ( V_37 ) ;
V_21 -> V_39 = F_7 ( V_39 ) ;
for ( V_42 = 0 , V_18 = V_21 -> V_43 ; V_42 < V_37 ; V_42 ++ , V_18 ++ )
F_15 ( V_38 [ V_42 ] , V_18 ) ;
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ , V_18 ++ )
F_15 ( V_40 [ V_42 ] , V_18 ) ;
V_15 = F_11 ( V_5 , V_34 , V_44 , 0 , V_21 ,
V_41 ) ;
F_16 ( V_21 ) ;
return V_15 ;
}
static int F_17 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_45 * V_21 ;
struct V_26 * V_46 ;
T_3 V_22 ;
T_2 V_47 ;
int V_15 ;
F_4 ( L_2 , V_5 ) ;
F_18 ( & V_48 ) ;
V_47 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( V_46 -> V_49 == V_50 )
V_47 ++ ;
}
V_22 = sizeof( * V_21 ) + ( 2 * V_47 ) ;
V_21 = F_14 ( V_22 , V_51 ) ;
if ( ! V_21 ) {
F_20 ( & V_48 ) ;
return - V_17 ;
}
V_47 = 0 ;
F_19 (d, &hci_dev_list, list) {
if ( F_21 ( V_52 , & V_46 -> V_53 ) )
continue;
if ( F_21 ( V_54 , & V_46 -> V_53 ) )
continue;
if ( V_46 -> V_49 == V_50 ) {
V_21 -> V_6 [ V_47 ++ ] = F_8 ( V_46 -> V_55 ) ;
F_4 ( L_3 , V_46 -> V_55 ) ;
}
}
V_21 -> V_56 = F_8 ( V_47 ) ;
V_22 = sizeof( * V_21 ) + ( 2 * V_47 ) ;
F_20 ( & V_48 ) ;
V_15 = F_11 ( V_5 , V_34 , V_57 , 0 , V_21 ,
V_22 ) ;
F_16 ( V_21 ) ;
return V_15 ;
}
static T_5 F_22 ( struct V_26 * V_27 )
{
T_5 V_58 = 0 ;
V_58 |= V_59 ;
V_58 |= V_60 ;
if ( F_23 ( V_27 ) ) {
V_58 |= V_61 ;
if ( V_27 -> V_62 >= V_63 )
V_58 |= V_64 ;
V_58 |= V_65 ;
V_58 |= V_66 ;
V_58 |= V_67 ;
if ( F_24 ( V_27 ) ) {
V_58 |= V_68 ;
V_58 |= V_69 ;
}
}
if ( F_25 ( V_27 ) ) {
V_58 |= V_70 ;
V_58 |= V_71 ;
}
return V_58 ;
}
static T_5 F_26 ( struct V_26 * V_27 )
{
T_5 V_58 = 0 ;
if ( F_27 ( V_27 ) )
V_58 |= V_59 ;
if ( F_21 ( V_72 , & V_27 -> V_53 ) )
V_58 |= V_61 ;
if ( F_21 ( V_73 , & V_27 -> V_53 ) )
V_58 |= V_64 ;
if ( F_21 ( V_74 , & V_27 -> V_53 ) )
V_58 |= V_65 ;
if ( F_21 ( V_75 , & V_27 -> V_53 ) )
V_58 |= V_60 ;
if ( F_21 ( V_76 , & V_27 -> V_53 ) )
V_58 |= V_66 ;
if ( F_21 ( V_77 , & V_27 -> V_53 ) )
V_58 |= V_70 ;
if ( F_21 ( V_78 , & V_27 -> V_53 ) )
V_58 |= V_67 ;
if ( F_21 ( V_79 , & V_27 -> V_53 ) )
V_58 |= V_68 ;
if ( F_21 ( V_80 , & V_27 -> V_53 ) )
V_58 |= V_69 ;
if ( F_21 ( V_81 , & V_27 -> V_53 ) )
V_58 |= V_71 ;
return V_58 ;
}
static T_1 * F_28 ( struct V_26 * V_27 , T_1 * V_25 , T_6 V_20 )
{
T_1 * V_82 = V_25 , * V_83 = NULL ;
struct V_84 * V_85 ;
if ( V_20 < 4 )
return V_82 ;
F_19 (uuid, &hdev->uuids, list) {
T_2 V_86 ;
if ( V_85 -> V_87 != 16 )
continue;
V_86 = F_29 ( & V_85 -> V_85 [ 12 ] ) ;
if ( V_86 < 0x1100 )
continue;
if ( V_86 == V_88 )
continue;
if ( ! V_83 ) {
V_83 = V_82 ;
V_83 [ 0 ] = 1 ;
V_83 [ 1 ] = V_89 ;
V_82 += 2 ;
}
if ( ( V_82 - V_25 ) + sizeof( T_2 ) > V_20 ) {
V_83 [ 1 ] = V_90 ;
break;
}
* V_82 ++ = ( V_86 & 0x00ff ) ;
* V_82 ++ = ( V_86 & 0xff00 ) >> 8 ;
V_83 [ 0 ] += sizeof( V_86 ) ;
}
return V_82 ;
}
static T_1 * F_30 ( struct V_26 * V_27 , T_1 * V_25 , T_6 V_20 )
{
T_1 * V_82 = V_25 , * V_83 = NULL ;
struct V_84 * V_85 ;
if ( V_20 < 6 )
return V_82 ;
F_19 (uuid, &hdev->uuids, list) {
if ( V_85 -> V_87 != 32 )
continue;
if ( ! V_83 ) {
V_83 = V_82 ;
V_83 [ 0 ] = 1 ;
V_83 [ 1 ] = V_91 ;
V_82 += 2 ;
}
if ( ( V_82 - V_25 ) + sizeof( T_5 ) > V_20 ) {
V_83 [ 1 ] = V_92 ;
break;
}
memcpy ( V_82 , & V_85 -> V_85 [ 12 ] , sizeof( T_5 ) ) ;
V_82 += sizeof( T_5 ) ;
V_83 [ 0 ] += sizeof( T_5 ) ;
}
return V_82 ;
}
static T_1 * F_31 ( struct V_26 * V_27 , T_1 * V_25 , T_6 V_20 )
{
T_1 * V_82 = V_25 , * V_83 = NULL ;
struct V_84 * V_85 ;
if ( V_20 < 18 )
return V_82 ;
F_19 (uuid, &hdev->uuids, list) {
if ( V_85 -> V_87 != 128 )
continue;
if ( ! V_83 ) {
V_83 = V_82 ;
V_83 [ 0 ] = 1 ;
V_83 [ 1 ] = V_93 ;
V_82 += 2 ;
}
if ( ( V_82 - V_25 ) + 16 > V_20 ) {
V_83 [ 1 ] = V_94 ;
break;
}
memcpy ( V_82 , V_85 -> V_85 , 16 ) ;
V_82 += 16 ;
V_83 [ 0 ] += 16 ;
}
return V_82 ;
}
static struct V_95 * F_32 ( T_2 V_18 , struct V_26 * V_27 )
{
struct V_95 * V_7 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 == V_18 )
return V_7 ;
}
return NULL ;
}
static T_1 F_33 ( struct V_26 * V_27 , T_1 * V_82 )
{
T_1 V_96 = 0 ;
T_3 V_97 ;
V_97 = strlen ( V_27 -> V_98 ) ;
if ( V_97 > 0 ) {
T_3 V_99 = V_100 - V_96 - 2 ;
if ( V_97 > V_99 ) {
V_97 = V_99 ;
V_82 [ 1 ] = V_101 ;
} else
V_82 [ 1 ] = V_102 ;
V_82 [ 0 ] = V_97 + 1 ;
memcpy ( V_82 + 2 , V_27 -> V_98 , V_97 ) ;
V_96 += ( V_97 + 2 ) ;
V_82 += ( V_97 + 2 ) ;
}
return V_96 ;
}
static void F_34 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_105 V_106 ;
T_1 V_20 ;
if ( ! F_21 ( V_77 , & V_27 -> V_53 ) )
return;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_20 = F_33 ( V_27 , V_106 . V_25 ) ;
if ( V_27 -> V_107 == V_20 &&
memcmp ( V_106 . V_25 , V_27 -> V_108 , V_20 ) == 0 )
return;
memcpy ( V_27 -> V_108 , V_106 . V_25 , sizeof( V_106 . V_25 ) ) ;
V_27 -> V_107 = V_20 ;
V_106 . V_109 = V_20 ;
F_35 ( V_104 , V_110 , sizeof( V_106 ) , & V_106 ) ;
}
static T_1 F_36 ( struct V_26 * V_27 )
{
struct V_95 * V_7 ;
V_7 = F_32 ( V_111 , V_27 ) ;
if ( V_7 ) {
struct V_112 * V_106 = V_7 -> V_113 ;
if ( V_106 -> V_114 == 0x01 )
return V_115 ;
else if ( V_106 -> V_114 == 0x02 )
return V_116 ;
} else {
if ( F_21 ( V_117 , & V_27 -> V_53 ) )
return V_116 ;
else if ( F_21 ( V_74 , & V_27 -> V_53 ) )
return V_115 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_26 * V_27 , T_1 * V_82 )
{
T_1 V_96 = 0 , V_118 = 0 ;
V_118 |= F_36 ( V_27 ) ;
if ( F_21 ( V_76 , & V_27 -> V_53 ) ) {
if ( F_38 ( V_27 ) )
V_118 |= V_119 ;
if ( F_39 ( V_27 ) )
V_118 |= V_120 ;
} else {
V_118 |= V_121 ;
}
if ( V_118 ) {
F_4 ( L_4 , V_118 ) ;
V_82 [ 0 ] = 2 ;
V_82 [ 1 ] = V_122 ;
V_82 [ 2 ] = V_118 ;
V_96 += 3 ;
V_82 += 3 ;
}
if ( V_27 -> V_123 != V_124 ) {
V_82 [ 0 ] = 2 ;
V_82 [ 1 ] = V_125 ;
V_82 [ 2 ] = ( T_1 ) V_27 -> V_123 ;
V_96 += 3 ;
V_82 += 3 ;
}
return V_96 ;
}
static void F_40 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_126 V_106 ;
T_1 V_20 ;
if ( ! F_21 ( V_77 , & V_27 -> V_53 ) )
return;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_20 = F_37 ( V_27 , V_106 . V_25 ) ;
if ( V_27 -> V_127 == V_20 &&
memcmp ( V_106 . V_25 , V_27 -> V_128 , V_20 ) == 0 )
return;
memcpy ( V_27 -> V_128 , V_106 . V_25 , sizeof( V_106 . V_25 ) ) ;
V_27 -> V_127 = V_20 ;
V_106 . V_109 = V_20 ;
F_35 ( V_104 , V_129 , sizeof( V_106 ) , & V_106 ) ;
}
static void F_41 ( struct V_26 * V_27 , T_1 * V_25 )
{
T_1 * V_82 = V_25 ;
T_3 V_97 ;
V_97 = strlen ( V_27 -> V_98 ) ;
if ( V_97 > 0 ) {
if ( V_97 > 48 ) {
V_97 = 48 ;
V_82 [ 1 ] = V_101 ;
} else
V_82 [ 1 ] = V_102 ;
V_82 [ 0 ] = V_97 + 1 ;
memcpy ( V_82 + 2 , V_27 -> V_98 , V_97 ) ;
V_82 += ( V_97 + 2 ) ;
}
if ( V_27 -> V_130 != V_124 ) {
V_82 [ 0 ] = 2 ;
V_82 [ 1 ] = V_125 ;
V_82 [ 2 ] = ( T_1 ) V_27 -> V_130 ;
V_82 += 3 ;
}
if ( V_27 -> V_131 > 0 ) {
V_82 [ 0 ] = 9 ;
V_82 [ 1 ] = V_132 ;
F_15 ( V_27 -> V_131 , V_82 + 2 ) ;
F_15 ( V_27 -> V_133 , V_82 + 4 ) ;
F_15 ( V_27 -> V_134 , V_82 + 6 ) ;
F_15 ( V_27 -> V_135 , V_82 + 8 ) ;
V_82 += 10 ;
}
V_82 = F_28 ( V_27 , V_82 , V_136 - ( V_82 - V_25 ) ) ;
V_82 = F_30 ( V_27 , V_82 , V_136 - ( V_82 - V_25 ) ) ;
V_82 = F_31 ( V_27 , V_82 , V_136 - ( V_82 - V_25 ) ) ;
}
static void F_42 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_137 V_106 ;
if ( ! F_27 ( V_27 ) )
return;
if ( ! F_43 ( V_27 ) )
return;
if ( ! F_21 ( V_79 , & V_27 -> V_53 ) )
return;
if ( F_21 ( V_138 , & V_27 -> V_53 ) )
return;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
F_41 ( V_27 , V_106 . V_25 ) ;
if ( memcmp ( V_106 . V_25 , V_27 -> V_139 , sizeof( V_106 . V_25 ) ) == 0 )
return;
memcpy ( V_27 -> V_139 , V_106 . V_25 , sizeof( V_106 . V_25 ) ) ;
F_35 ( V_104 , V_140 , sizeof( V_106 ) , & V_106 ) ;
}
static T_1 F_44 ( struct V_26 * V_27 )
{
struct V_84 * V_85 ;
T_1 V_114 = 0 ;
F_19 (uuid, &hdev->uuids, list)
V_114 |= V_85 -> V_141 ;
return V_114 ;
}
static void F_45 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
T_1 V_142 [ 3 ] ;
F_4 ( L_5 , V_27 -> V_143 ) ;
if ( ! F_27 ( V_27 ) )
return;
if ( ! F_21 ( V_76 , & V_27 -> V_53 ) )
return;
if ( F_21 ( V_138 , & V_27 -> V_53 ) )
return;
V_142 [ 0 ] = V_27 -> V_144 ;
V_142 [ 1 ] = V_27 -> V_145 ;
V_142 [ 2 ] = F_44 ( V_27 ) ;
if ( F_21 ( V_117 , & V_27 -> V_53 ) )
V_142 [ 1 ] |= 0x20 ;
if ( memcmp ( V_142 , V_27 -> V_146 , 3 ) == 0 )
return;
F_35 ( V_104 , V_147 , sizeof( V_142 ) , V_142 ) ;
}
static void F_46 ( struct V_148 * V_149 )
{
struct V_26 * V_27 = F_47 ( V_149 , struct V_26 ,
V_150 . V_149 ) ;
struct V_103 V_104 ;
if ( ! F_48 ( V_138 , & V_27 -> V_53 ) )
return;
F_49 ( & V_104 , V_27 ) ;
F_50 ( V_27 ) ;
F_42 ( & V_104 ) ;
F_45 ( & V_104 ) ;
F_51 ( V_27 ) ;
F_52 ( & V_104 , NULL ) ;
}
static void F_53 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
if ( F_54 ( V_151 , & V_27 -> V_53 ) )
return;
F_55 ( & V_27 -> V_150 , F_46 ) ;
F_56 ( V_75 , & V_27 -> V_53 ) ;
}
static int F_57 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_152 V_21 ;
F_4 ( L_6 , V_5 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_58 ( & V_21 . V_153 , & V_27 -> V_153 ) ;
V_21 . V_30 = V_27 -> V_62 ;
V_21 . V_154 = F_8 ( V_27 -> V_154 ) ;
V_21 . V_155 = F_59 ( F_22 ( V_27 ) ) ;
V_21 . V_156 = F_59 ( F_26 ( V_27 ) ) ;
memcpy ( V_21 . V_146 , V_27 -> V_146 , 3 ) ;
memcpy ( V_21 . V_143 , V_27 -> V_98 , sizeof( V_27 -> V_98 ) ) ;
memcpy ( V_21 . V_157 , V_27 -> V_157 , sizeof( V_27 -> V_157 ) ) ;
F_51 ( V_27 ) ;
return F_11 ( V_5 , V_27 -> V_55 , V_158 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static void F_60 ( struct V_95 * V_7 )
{
F_61 ( V_7 -> V_5 ) ;
F_16 ( V_7 -> V_113 ) ;
F_16 ( V_7 ) ;
}
static struct V_95 * F_62 ( struct V_4 * V_5 , T_2 V_18 ,
struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_95 * V_7 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 = V_18 ;
V_7 -> V_6 = V_27 -> V_55 ;
V_7 -> V_113 = F_14 ( V_20 , V_16 ) ;
if ( ! V_7 -> V_113 ) {
F_16 ( V_7 ) ;
return NULL ;
}
if ( V_25 )
memcpy ( V_7 -> V_113 , V_25 , V_20 ) ;
V_7 -> V_5 = V_5 ;
F_63 ( V_5 ) ;
F_64 ( & V_7 -> V_159 , & V_27 -> V_160 ) ;
return V_7 ;
}
static void F_65 ( T_2 V_18 , struct V_26 * V_27 ,
void (* F_66)( struct V_95 * V_7 ,
void * V_25 ) ,
void * V_25 )
{
struct V_95 * V_7 , * V_161 ;
F_67 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_18 > 0 && V_7 -> V_18 != V_18 )
continue;
F_66 ( V_7 , V_25 ) ;
}
}
static void F_68 ( struct V_95 * V_7 )
{
F_69 ( & V_7 -> V_159 ) ;
F_60 ( V_7 ) ;
}
static int F_70 ( struct V_4 * V_5 , T_2 V_18 , struct V_26 * V_27 )
{
T_7 V_58 = F_59 ( F_26 ( V_27 ) ) ;
return F_11 ( V_5 , V_27 -> V_55 , V_18 , 0 , & V_58 ,
sizeof( V_58 ) ) ;
}
static int F_71 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_162 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( F_32 ( V_162 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_162 ,
V_164 ) ;
goto V_165;
}
if ( F_48 ( V_166 , & V_27 -> V_53 ) ) {
F_72 ( & V_27 -> V_167 ) ;
if ( V_106 -> V_114 ) {
F_62 ( V_5 , V_162 , V_27 ,
V_25 , V_20 ) ;
V_15 = F_73 ( V_27 , 1 ) ;
goto V_165;
}
}
if ( ! ! V_106 -> V_114 == F_27 ( V_27 ) ) {
V_15 = F_70 ( V_5 , V_162 , V_27 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_162 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
if ( V_106 -> V_114 )
F_74 ( V_27 -> V_168 , & V_27 -> V_169 ) ;
else
F_74 ( V_27 -> V_168 , & V_27 -> V_167 . V_149 ) ;
V_15 = 0 ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_75 ( T_2 V_170 , struct V_26 * V_27 , void * V_25 , T_2 V_28 ,
struct V_4 * V_171 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_5 ( sizeof( * V_12 ) + V_28 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_8 ( V_170 ) ;
if ( V_27 )
V_12 -> V_6 = F_8 ( V_27 -> V_55 ) ;
else
V_12 -> V_6 = F_7 ( V_34 ) ;
V_12 -> V_20 = F_8 ( V_28 ) ;
if ( V_25 )
memcpy ( F_6 ( V_10 , V_28 ) , V_25 , V_28 ) ;
F_76 ( V_10 ) ;
F_77 ( V_10 , V_171 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
static int F_78 ( struct V_26 * V_27 , struct V_4 * V_172 )
{
T_7 V_14 ;
V_14 = F_59 ( F_26 ( V_27 ) ) ;
return F_75 ( V_173 , V_27 , & V_14 , sizeof( V_14 ) , V_172 ) ;
}
static void F_79 ( struct V_95 * V_7 , void * V_25 )
{
struct V_174 * V_175 = V_25 ;
F_70 ( V_7 -> V_5 , V_7 -> V_18 , V_175 -> V_27 ) ;
F_69 ( & V_7 -> V_159 ) ;
if ( V_175 -> V_5 == NULL ) {
V_175 -> V_5 = V_7 -> V_5 ;
F_63 ( V_175 -> V_5 ) ;
}
F_60 ( V_7 ) ;
}
static void F_80 ( struct V_95 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , * V_8 ) ;
F_68 ( V_7 ) ;
}
static T_1 F_81 ( struct V_26 * V_27 )
{
if ( ! F_23 ( V_27 ) )
return V_176 ;
else if ( ! F_21 ( V_76 , & V_27 -> V_53 ) )
return V_177 ;
else
return V_178 ;
}
static T_1 F_82 ( struct V_26 * V_27 )
{
if ( ! F_25 ( V_27 ) )
return V_176 ;
else if ( ! F_21 ( V_77 , & V_27 -> V_53 ) )
return V_177 ;
else
return V_178 ;
}
static void F_83 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_95 * V_7 ;
struct V_112 * V_106 ;
struct V_103 V_104 ;
bool V_179 ;
F_4 ( L_8 , V_8 ) ;
F_50 ( V_27 ) ;
V_7 = F_32 ( V_111 , V_27 ) ;
if ( ! V_7 )
goto V_180;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_181 ) ;
F_56 ( V_117 , & V_27 -> V_53 ) ;
goto V_182;
}
V_106 = V_7 -> V_113 ;
if ( V_106 -> V_114 ) {
V_179 = ! F_54 ( V_74 ,
& V_27 -> V_53 ) ;
if ( V_27 -> V_183 > 0 ) {
int V_184 = F_84 ( V_27 -> V_183 * 1000 ) ;
F_85 ( V_27 -> V_185 , & V_27 -> V_186 ,
V_184 ) ;
}
} else {
V_179 = F_48 ( V_74 ,
& V_27 -> V_53 ) ;
}
F_70 ( V_7 -> V_5 , V_111 , V_27 ) ;
if ( V_179 )
F_78 ( V_27 , V_7 -> V_5 ) ;
F_49 ( & V_104 , V_27 ) ;
F_45 ( & V_104 ) ;
F_52 ( & V_104 , NULL ) ;
V_182:
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
}
static int F_86 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_187 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
T_2 V_188 ;
T_1 V_189 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_21 ( V_77 , & V_27 -> V_53 ) &&
! F_21 ( V_76 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_111 ,
V_177 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 && V_106 -> V_114 != 0x02 )
return F_3 ( V_5 , V_27 -> V_55 , V_111 ,
V_163 ) ;
V_188 = F_87 ( V_106 -> V_188 ) ;
if ( ( V_106 -> V_114 == 0x00 && V_188 > 0 ) ||
( V_106 -> V_114 == 0x02 && V_188 == 0 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_111 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) && V_188 > 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_111 ,
V_190 ) ;
goto V_165;
}
if ( F_32 ( V_111 , V_27 ) ||
F_32 ( V_191 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_111 ,
V_164 ) ;
goto V_165;
}
if ( ! F_21 ( V_72 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_111 ,
V_177 ) ;
goto V_165;
}
if ( ! F_27 ( V_27 ) ) {
bool V_179 = false ;
if ( ! ! V_106 -> V_114 != F_21 ( V_74 , & V_27 -> V_53 ) ) {
F_88 ( V_74 , & V_27 -> V_53 ) ;
V_179 = true ;
}
V_15 = F_70 ( V_5 , V_111 , V_27 ) ;
if ( V_15 < 0 )
goto V_165;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
goto V_165;
}
if ( ! ! V_106 -> V_114 == F_21 ( V_74 , & V_27 -> V_53 ) &&
( V_106 -> V_114 == 0x02 ) == F_21 ( V_117 ,
& V_27 -> V_53 ) ) {
F_72 ( & V_27 -> V_186 ) ;
V_27 -> V_183 = V_188 ;
if ( V_106 -> V_114 && V_27 -> V_183 > 0 ) {
int V_184 = F_84 ( V_27 -> V_183 * 1000 ) ;
F_85 ( V_27 -> V_185 , & V_27 -> V_186 ,
V_184 ) ;
}
V_15 = F_70 ( V_5 , V_111 , V_27 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_111 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
F_72 ( & V_27 -> V_186 ) ;
V_27 -> V_183 = V_188 ;
if ( V_106 -> V_114 == 0x02 )
F_89 ( V_117 , & V_27 -> V_53 ) ;
else
F_56 ( V_117 , & V_27 -> V_53 ) ;
F_49 ( & V_104 , V_27 ) ;
if ( ! F_21 ( V_76 , & V_27 -> V_53 ) )
goto V_192;
V_189 = V_193 ;
if ( V_106 -> V_114 ) {
struct V_194 V_195 ;
if ( V_106 -> V_114 == 0x02 ) {
V_195 . V_196 = F_90 ( T_1 , V_27 -> V_196 , 2 ) ;
V_195 . V_197 [ 0 ] = 0x00 ;
V_195 . V_197 [ 1 ] = 0x8b ;
V_195 . V_197 [ 2 ] = 0x9e ;
V_195 . V_197 [ 3 ] = 0x33 ;
V_195 . V_197 [ 4 ] = 0x8b ;
V_195 . V_197 [ 5 ] = 0x9e ;
} else {
V_195 . V_196 = 1 ;
V_195 . V_197 [ 0 ] = 0x33 ;
V_195 . V_197 [ 1 ] = 0x8b ;
V_195 . V_197 [ 2 ] = 0x9e ;
}
F_35 ( & V_104 , V_198 ,
( V_195 . V_196 * 3 ) + 1 , & V_195 ) ;
V_189 |= V_199 ;
} else {
F_56 ( V_117 , & V_27 -> V_53 ) ;
}
F_35 ( & V_104 , V_200 , sizeof( V_189 ) , & V_189 ) ;
V_192:
F_40 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_83 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static void F_91 ( struct V_103 * V_104 , bool V_201 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_202 V_203 ;
T_1 type ;
if ( ! F_21 ( V_76 , & V_27 -> V_53 ) )
return;
if ( V_27 -> V_62 < V_63 )
return;
if ( V_201 ) {
type = V_204 ;
V_203 . V_205 = F_7 ( 0x0100 ) ;
} else {
type = V_206 ;
V_203 . V_205 = F_7 ( 0x0800 ) ;
}
V_203 . V_207 = F_7 ( 0x0012 ) ;
if ( F_92 ( V_27 -> V_208 ) != V_203 . V_205 ||
F_92 ( V_27 -> V_209 ) != V_203 . V_207 )
F_35 ( V_104 , V_210 ,
sizeof( V_203 ) , & V_203 ) ;
if ( V_27 -> V_211 != type )
F_35 ( V_104 , V_212 , 1 , & type ) ;
}
static T_1 F_93 ( struct V_26 * V_27 )
{
struct V_95 * V_7 ;
bool V_213 ;
V_7 = F_32 ( V_191 , V_27 ) ;
if ( V_7 ) {
struct V_112 * V_106 = V_7 -> V_113 ;
V_213 = ! ! V_106 -> V_114 ;
} else {
V_213 = F_21 ( V_72 , & V_27 -> V_53 ) ;
}
return V_213 ? V_214 : V_215 ;
}
static void F_94 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_216 V_106 ;
T_1 V_201 = 0x01 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_217 = F_7 ( 0x0800 ) ;
V_106 . V_218 = F_7 ( 0x0800 ) ;
V_106 . type = F_93 ( V_27 ) ;
V_106 . V_219 = V_27 -> V_220 ;
V_106 . V_221 = 0x07 ;
F_35 ( V_104 , V_222 , sizeof( V_106 ) , & V_106 ) ;
F_35 ( V_104 , V_223 , sizeof( V_201 ) , & V_201 ) ;
}
static void F_95 ( struct V_103 * V_104 )
{
T_1 V_201 = 0x00 ;
F_35 ( V_104 , V_223 , sizeof( V_201 ) , & V_201 ) ;
}
static void F_96 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_95 * V_7 ;
struct V_112 * V_106 ;
bool V_179 ;
F_4 ( L_8 , V_8 ) ;
F_50 ( V_27 ) ;
V_7 = F_32 ( V_191 , V_27 ) ;
if ( ! V_7 )
goto V_180;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_181 ) ;
goto V_182;
}
V_106 = V_7 -> V_113 ;
if ( V_106 -> V_114 )
V_179 = ! F_54 ( V_72 , & V_27 -> V_53 ) ;
else
V_179 = F_48 ( V_72 , & V_27 -> V_53 ) ;
F_70 ( V_7 -> V_5 , V_191 , V_27 ) ;
if ( V_179 )
F_78 ( V_27 , V_7 -> V_5 ) ;
V_182:
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
}
static int F_97 ( struct V_26 * V_27 ,
struct V_4 * V_5 , T_1 V_114 )
{
bool V_179 = false ;
int V_15 ;
if ( ! ! V_114 != F_21 ( V_72 , & V_27 -> V_53 ) )
V_179 = true ;
if ( V_114 ) {
F_89 ( V_72 , & V_27 -> V_53 ) ;
} else {
F_56 ( V_72 , & V_27 -> V_53 ) ;
F_56 ( V_74 , & V_27 -> V_53 ) ;
}
V_15 = F_70 ( V_5 , V_191 , V_27 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_179 )
return F_78 ( V_27 , V_5 ) ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
T_1 V_189 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_21 ( V_77 , & V_27 -> V_53 ) &&
! F_21 ( V_76 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_191 ,
V_177 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_191 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_97 ( V_27 , V_5 , V_106 -> V_114 ) ;
goto V_165;
}
if ( F_32 ( V_111 , V_27 ) ||
F_32 ( V_191 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_191 ,
V_164 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_191 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
F_49 ( & V_104 , V_27 ) ;
if ( ! F_21 ( V_76 , & V_27 -> V_53 ) ) {
if ( ! V_106 -> V_114 ) {
F_56 ( V_117 , & V_27 -> V_53 ) ;
F_56 ( V_74 , & V_27 -> V_53 ) ;
}
F_40 ( & V_104 ) ;
} else if ( V_106 -> V_114 != F_21 ( V_224 , & V_27 -> V_118 ) ) {
if ( V_106 -> V_114 ) {
V_189 = V_193 ;
} else {
V_189 = 0 ;
if ( F_21 ( V_225 , & V_27 -> V_118 ) &&
V_27 -> V_183 > 0 )
F_72 ( & V_27 -> V_186 ) ;
}
F_35 ( & V_104 , V_200 , 1 , & V_189 ) ;
}
if ( V_106 -> V_114 || F_21 ( V_73 , & V_27 -> V_53 ) )
F_91 ( & V_104 , false ) ;
if ( F_21 ( V_81 , & V_27 -> V_53 ) &&
F_99 ( V_27 , V_226 ) == 0 ) {
F_95 ( & V_104 ) ;
F_94 ( & V_104 ) ;
}
V_15 = F_52 ( & V_104 , F_96 ) ;
if ( V_15 < 0 ) {
F_68 ( V_7 ) ;
if ( V_15 == - V_227 )
V_15 = F_97 ( V_27 , V_5 ,
V_106 -> V_114 ) ;
goto V_165;
}
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_100 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
bool V_179 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_228 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( V_106 -> V_114 )
V_179 = ! F_54 ( V_75 , & V_27 -> V_53 ) ;
else
V_179 = F_48 ( V_75 , & V_27 -> V_53 ) ;
V_15 = F_70 ( V_5 , V_228 , V_27 ) ;
if ( V_15 < 0 )
goto V_180;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_101 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
T_1 V_114 , V_8 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
V_8 = F_81 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_229 ,
V_8 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_229 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_179 = false ;
if ( ! ! V_106 -> V_114 != F_21 ( V_78 ,
& V_27 -> V_53 ) ) {
F_88 ( V_78 , & V_27 -> V_53 ) ;
V_179 = true ;
}
V_15 = F_70 ( V_5 , V_229 , V_27 ) ;
if ( V_15 < 0 )
goto V_165;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
goto V_165;
}
if ( F_32 ( V_229 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_229 ,
V_164 ) ;
goto V_165;
}
V_114 = ! ! V_106 -> V_114 ;
if ( F_21 ( V_230 , & V_27 -> V_118 ) == V_114 ) {
V_15 = F_70 ( V_5 , V_229 , V_27 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_229 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
V_15 = F_102 ( V_27 , V_231 , sizeof( V_114 ) , & V_114 ) ;
if ( V_15 < 0 ) {
F_68 ( V_7 ) ;
goto V_165;
}
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_103 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
V_8 = F_81 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_232 , V_8 ) ;
if ( ! F_24 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_232 ,
V_176 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_232 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
bool V_179 ;
if ( V_106 -> V_114 ) {
V_179 = ! F_54 ( V_79 ,
& V_27 -> V_53 ) ;
} else {
V_179 = F_48 ( V_79 ,
& V_27 -> V_53 ) ;
if ( ! V_179 )
V_179 = F_48 ( V_80 ,
& V_27 -> V_53 ) ;
else
F_56 ( V_80 , & V_27 -> V_53 ) ;
}
V_15 = F_70 ( V_5 , V_232 , V_27 ) ;
if ( V_15 < 0 )
goto V_165;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
goto V_165;
}
if ( F_32 ( V_232 , V_27 ) ||
F_32 ( V_233 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_232 ,
V_164 ) ;
goto V_165;
}
if ( ! ! V_106 -> V_114 == F_21 ( V_79 , & V_27 -> V_53 ) ) {
V_15 = F_70 ( V_5 , V_232 , V_27 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_232 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
V_15 = F_102 ( V_27 , V_234 , 1 , & V_106 -> V_114 ) ;
if ( V_15 < 0 ) {
F_68 ( V_7 ) ;
goto V_165;
}
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_104 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
bool V_179 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
V_8 = F_81 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_233 , V_8 ) ;
if ( ! F_24 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_233 ,
V_176 ) ;
if ( ! F_21 ( V_79 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_233 ,
V_177 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_233 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( V_106 -> V_114 ) {
V_179 = ! F_54 ( V_80 , & V_27 -> V_53 ) ;
} else {
if ( F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_233 ,
V_177 ) ;
goto V_180;
}
V_179 = F_48 ( V_80 , & V_27 -> V_53 ) ;
}
V_15 = F_70 ( V_5 , V_233 , V_27 ) ;
if ( V_15 < 0 )
goto V_180;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static void F_105 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_174 V_175 = { NULL , V_27 } ;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
F_65 ( V_235 , V_27 , F_80 ,
& V_181 ) ;
return;
}
F_65 ( V_235 , V_27 , F_79 , & V_175 ) ;
F_78 ( V_27 , V_175 . V_5 ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
if ( F_21 ( V_77 , & V_27 -> V_53 ) ) {
struct V_103 V_104 ;
F_50 ( V_27 ) ;
F_49 ( & V_104 , V_27 ) ;
F_40 ( & V_104 ) ;
F_34 ( & V_104 ) ;
F_52 ( & V_104 , NULL ) ;
F_51 ( V_27 ) ;
}
}
static int F_106 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_236 V_195 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
int V_15 ;
T_1 V_114 , V_237 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_235 ,
V_176 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_235 ,
V_163 ) ;
if ( ! F_21 ( V_76 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_235 ,
V_177 ) ;
F_50 ( V_27 ) ;
V_114 = ! ! V_106 -> V_114 ;
V_237 = F_107 ( V_27 ) ;
if ( ! F_27 ( V_27 ) || V_114 == V_237 ) {
bool V_179 = false ;
if ( V_114 != F_21 ( V_77 , & V_27 -> V_53 ) ) {
F_88 ( V_77 , & V_27 -> V_53 ) ;
V_179 = true ;
}
if ( ! V_114 && F_21 ( V_81 , & V_27 -> V_53 ) ) {
F_56 ( V_81 , & V_27 -> V_53 ) ;
V_179 = true ;
}
V_15 = F_70 ( V_5 , V_235 , V_27 ) ;
if ( V_15 < 0 )
goto V_180;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
goto V_180;
}
if ( F_32 ( V_235 , V_27 ) ||
F_32 ( V_238 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_235 ,
V_164 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_235 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
F_49 ( & V_104 , V_27 ) ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
if ( V_114 ) {
V_195 . V_239 = V_114 ;
V_195 . V_240 = F_38 ( V_27 ) ;
} else {
if ( F_21 ( V_81 , & V_27 -> V_53 ) )
F_95 ( & V_104 ) ;
}
F_35 ( & V_104 , V_241 , sizeof( V_195 ) ,
& V_195 ) ;
V_15 = F_52 ( & V_104 , F_105 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static bool F_108 ( struct V_26 * V_27 )
{
struct V_95 * V_7 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
switch ( V_7 -> V_18 ) {
case V_242 :
case V_243 :
case V_244 :
case V_162 :
return true ;
}
}
return false ;
}
static T_1 F_109 ( const T_1 * V_85 )
{
T_5 V_114 ;
if ( memcmp ( V_85 , V_245 , 12 ) )
return 128 ;
V_114 = F_110 ( & V_85 [ 12 ] ) ;
if ( V_114 > 0xffff )
return 32 ;
return 16 ;
}
static void F_111 ( struct V_26 * V_27 , T_2 V_246 , T_1 V_8 )
{
struct V_95 * V_7 ;
F_50 ( V_27 ) ;
V_7 = F_32 ( V_246 , V_27 ) ;
if ( ! V_7 )
goto V_180;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , F_1 ( V_8 ) ,
V_27 -> V_146 , 3 ) ;
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
}
static void F_112 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_8 , V_8 ) ;
F_111 ( V_27 , V_242 , V_8 ) ;
}
static int F_113 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_247 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
struct V_84 * V_85 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
if ( F_108 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_242 ,
V_164 ) ;
goto V_165;
}
V_85 = F_14 ( sizeof( * V_85 ) , V_16 ) ;
if ( ! V_85 ) {
V_15 = - V_17 ;
goto V_165;
}
memcpy ( V_85 -> V_85 , V_106 -> V_85 , 16 ) ;
V_85 -> V_141 = V_106 -> V_141 ;
V_85 -> V_87 = F_109 ( V_106 -> V_85 ) ;
F_114 ( & V_85 -> V_159 , & V_27 -> V_248 ) ;
F_49 ( & V_104 , V_27 ) ;
F_45 ( & V_104 ) ;
F_42 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_112 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_227 )
goto V_165;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_242 , 0 ,
V_27 -> V_146 , 3 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_242 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
V_15 = 0 ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static bool F_115 ( struct V_26 * V_27 )
{
if ( ! F_27 ( V_27 ) )
return false ;
if ( ! F_54 ( V_138 , & V_27 -> V_53 ) ) {
F_85 ( V_27 -> V_185 , & V_27 -> V_150 ,
V_249 ) ;
return true ;
}
return false ;
}
static void F_116 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_8 , V_8 ) ;
F_111 ( V_27 , V_243 , V_8 ) ;
}
static int F_117 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_250 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_84 * V_175 , * V_161 ;
T_1 V_251 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_103 V_104 ;
int V_15 , V_252 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
if ( F_108 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_243 ,
V_164 ) ;
goto V_180;
}
if ( memcmp ( V_106 -> V_85 , V_251 , 16 ) == 0 ) {
V_15 = F_118 ( V_27 ) ;
if ( F_115 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_243 ,
0 , V_27 -> V_146 , 3 ) ;
goto V_180;
}
goto F_45;
}
V_252 = 0 ;
F_67 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_175 -> V_85 , V_106 -> V_85 , 16 ) != 0 )
continue;
F_69 ( & V_175 -> V_159 ) ;
F_16 ( V_175 ) ;
V_252 ++ ;
}
if ( V_252 == 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_243 ,
V_163 ) ;
goto V_180;
}
F_45:
F_49 ( & V_104 , V_27 ) ;
F_45 ( & V_104 ) ;
F_42 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_116 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_227 )
goto V_180;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_243 , 0 ,
V_27 -> V_146 , 3 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_243 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
V_15 = 0 ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static void F_119 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_8 , V_8 ) ;
F_111 ( V_27 , V_244 , V_8 ) ;
}
static int F_120 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_253 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_23 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_244 ,
V_176 ) ;
F_50 ( V_27 ) ;
if ( F_108 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_244 ,
V_164 ) ;
goto V_180;
}
if ( ( V_106 -> V_254 & 0x03 ) != 0 || ( V_106 -> V_255 & 0xe0 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_244 ,
V_163 ) ;
goto V_180;
}
V_27 -> V_145 = V_106 -> V_255 ;
V_27 -> V_144 = V_106 -> V_254 ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_244 , 0 ,
V_27 -> V_146 , 3 ) ;
goto V_180;
}
F_49 ( & V_104 , V_27 ) ;
if ( F_48 ( V_138 , & V_27 -> V_53 ) ) {
F_51 ( V_27 ) ;
F_121 ( & V_27 -> V_150 ) ;
F_50 ( V_27 ) ;
F_42 ( & V_104 ) ;
}
F_45 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_119 ) ;
if ( V_15 < 0 ) {
if ( V_15 != - V_227 )
goto V_180;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_244 , 0 ,
V_27 -> V_146 , 3 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_244 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
V_15 = 0 ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_122 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_256 * V_106 = V_25 ;
T_2 V_257 , V_258 ;
int V_42 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_23 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_176 ) ;
V_257 = F_87 ( V_106 -> V_257 ) ;
V_258 = sizeof( * V_106 ) + V_257 *
sizeof( struct V_260 ) ;
if ( V_258 != V_20 ) {
F_123 ( L_9 ,
V_20 , V_258 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_163 ) ;
}
if ( V_106 -> V_261 != 0x00 && V_106 -> V_261 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_163 ) ;
F_4 ( L_10 , V_27 -> V_143 , V_106 -> V_261 ,
V_257 ) ;
for ( V_42 = 0 ; V_42 < V_257 ; V_42 ++ ) {
struct V_260 * V_262 = & V_106 -> V_263 [ V_42 ] ;
if ( V_262 -> V_264 . type != V_265 )
return F_3 ( V_5 , V_27 -> V_55 , V_259 ,
V_163 ) ;
}
F_50 ( V_27 ) ;
F_124 ( V_27 ) ;
if ( V_106 -> V_261 )
F_89 ( V_266 , & V_27 -> V_53 ) ;
else
F_56 ( V_266 , & V_27 -> V_53 ) ;
for ( V_42 = 0 ; V_42 < V_257 ; V_42 ++ ) {
struct V_260 * V_262 = & V_106 -> V_263 [ V_42 ] ;
F_125 ( V_27 , NULL , 0 , & V_262 -> V_264 . V_153 , V_262 -> V_114 ,
V_262 -> type , V_262 -> V_267 ) ;
}
F_11 ( V_5 , V_27 -> V_55 , V_259 , 0 , NULL , 0 ) ;
F_51 ( V_27 ) ;
return 0 ;
}
static int F_126 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_268 , struct V_4 * V_171 )
{
struct V_269 V_14 ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = V_268 ;
return F_75 ( V_270 , V_27 , & V_14 , sizeof( V_14 ) ,
V_171 ) ;
}
static int F_127 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_271 * V_106 = V_25 ;
struct V_272 V_21 ;
struct V_273 V_274 ;
struct V_95 * V_7 ;
struct V_275 * V_276 ;
int V_15 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_58 ( & V_21 . V_264 . V_153 , & V_106 -> V_264 . V_153 ) ;
V_21 . V_264 . type = V_106 -> V_264 . type ;
if ( ! F_128 ( V_106 -> V_264 . type ) )
return F_11 ( V_5 , V_27 -> V_55 , V_277 ,
V_163 ,
& V_21 , sizeof( V_21 ) ) ;
if ( V_106 -> V_278 != 0x00 && V_106 -> V_278 != 0x01 )
return F_11 ( V_5 , V_27 -> V_55 , V_277 ,
V_163 ,
& V_21 , sizeof( V_21 ) ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_277 ,
V_190 , & V_21 , sizeof( V_21 ) ) ;
goto V_180;
}
if ( V_106 -> V_264 . type == V_265 )
V_15 = F_129 ( V_27 , & V_106 -> V_264 . V_153 ) ;
else
V_15 = F_130 ( V_27 , & V_106 -> V_264 . V_153 ) ;
if ( V_15 < 0 ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_277 ,
V_279 , & V_21 , sizeof( V_21 ) ) ;
goto V_180;
}
if ( V_106 -> V_278 ) {
if ( V_106 -> V_264 . type == V_265 )
V_276 = F_131 ( V_27 , V_280 ,
& V_106 -> V_264 . V_153 ) ;
else
V_276 = F_131 ( V_27 , V_226 ,
& V_106 -> V_264 . V_153 ) ;
} else {
V_276 = NULL ;
}
if ( ! V_276 ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_277 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
F_126 ( V_27 , & V_106 -> V_264 . V_153 , V_106 -> V_264 . type , V_5 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_277 , V_27 , V_106 ,
sizeof( * V_106 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
V_274 . V_281 = F_8 ( V_276 -> V_281 ) ;
V_274 . V_282 = 0x13 ;
V_15 = F_102 ( V_27 , V_283 , sizeof( V_274 ) , & V_274 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int V_278 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_284 * V_106 = V_25 ;
struct V_285 V_21 ;
struct V_273 V_274 ;
struct V_95 * V_7 ;
struct V_275 * V_276 ;
int V_15 ;
F_4 ( L_11 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_58 ( & V_21 . V_264 . V_153 , & V_106 -> V_264 . V_153 ) ;
V_21 . V_264 . type = V_106 -> V_264 . type ;
if ( ! F_128 ( V_106 -> V_264 . type ) )
return F_11 ( V_5 , V_27 -> V_55 , V_286 ,
V_163 ,
& V_21 , sizeof( V_21 ) ) ;
F_50 ( V_27 ) ;
if ( ! F_21 ( V_287 , & V_27 -> V_118 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_286 ,
V_190 , & V_21 , sizeof( V_21 ) ) ;
goto V_165;
}
if ( F_32 ( V_286 , V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_286 ,
V_164 , & V_21 , sizeof( V_21 ) ) ;
goto V_165;
}
if ( V_106 -> V_264 . type == V_265 )
V_276 = F_131 ( V_27 , V_280 ,
& V_106 -> V_264 . V_153 ) ;
else
V_276 = F_131 ( V_27 , V_226 , & V_106 -> V_264 . V_153 ) ;
if ( ! V_276 || V_276 -> V_288 == V_289 || V_276 -> V_288 == V_290 ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_286 ,
V_291 , & V_21 , sizeof( V_21 ) ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_286 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
V_274 . V_281 = F_8 ( V_276 -> V_281 ) ;
V_274 . V_282 = V_292 ;
V_15 = F_102 ( V_27 , V_283 , sizeof( V_274 ) , & V_274 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static T_1 F_132 ( T_1 V_293 , T_1 V_268 )
{
switch ( V_293 ) {
case V_226 :
switch ( V_268 ) {
case V_294 :
return V_295 ;
default:
return V_296 ;
}
default:
return V_265 ;
}
}
static int F_133 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_297 * V_21 ;
struct V_275 * V_298 ;
T_3 V_22 ;
int V_15 ;
T_2 V_42 ;
F_4 ( L_11 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_299 ,
V_190 ) ;
goto V_180;
}
V_42 = 0 ;
F_19 (c, &hdev->conn_hash.list, list) {
if ( F_21 ( V_300 , & V_298 -> V_118 ) )
V_42 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_301 ) ) ;
V_21 = F_14 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
V_15 = - V_17 ;
goto V_180;
}
V_42 = 0 ;
F_19 (c, &hdev->conn_hash.list, list) {
if ( ! F_21 ( V_300 , & V_298 -> V_118 ) )
continue;
F_58 ( & V_21 -> V_264 [ V_42 ] . V_153 , & V_298 -> V_302 ) ;
V_21 -> V_264 [ V_42 ] . type = F_132 ( V_298 -> type , V_298 -> V_303 ) ;
if ( V_298 -> type == V_304 || V_298 -> type == V_305 )
continue;
V_42 ++ ;
}
V_21 -> V_306 = F_8 ( V_42 ) ;
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_301 ) ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_299 , 0 , V_21 ,
V_22 ) ;
F_16 ( V_21 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_134 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_307 * V_106 )
{
struct V_95 * V_7 ;
int V_15 ;
V_7 = F_62 ( V_5 , V_308 , V_27 , V_106 ,
sizeof( * V_106 ) ) ;
if ( ! V_7 )
return - V_17 ;
V_15 = F_102 ( V_27 , V_309 ,
sizeof( V_106 -> V_264 . V_153 ) , & V_106 -> V_264 . V_153 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
return V_15 ;
}
static int F_135 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_275 * V_276 ;
struct V_310 * V_106 = V_25 ;
struct V_311 V_312 ;
struct V_95 * V_7 ;
int V_15 ;
F_4 ( L_11 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_313 ,
V_190 ) ;
goto V_165;
}
V_276 = F_131 ( V_27 , V_280 , & V_106 -> V_264 . V_153 ) ;
if ( ! V_276 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_313 ,
V_291 ) ;
goto V_165;
}
if ( V_276 -> V_314 == V_315 && V_106 -> V_267 != 16 ) {
struct V_307 V_316 ;
memcpy ( & V_316 . V_264 , & V_106 -> V_264 , sizeof( V_316 . V_264 ) ) ;
F_123 ( L_12 ) ;
V_15 = F_134 ( V_5 , V_27 , & V_316 ) ;
if ( V_15 >= 0 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_313 ,
V_163 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_313 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
F_58 ( & V_312 . V_153 , & V_106 -> V_264 . V_153 ) ;
V_312 . V_267 = V_106 -> V_267 ;
memcpy ( V_312 . V_317 , V_106 -> V_317 , sizeof( V_312 . V_317 ) ) ;
V_15 = F_102 ( V_27 , V_318 , sizeof( V_312 ) , & V_312 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_136 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_319 * V_106 = V_25 ;
F_4 ( L_11 ) ;
F_50 ( V_27 ) ;
V_27 -> V_320 = V_106 -> V_320 ;
F_4 ( L_13 , V_27 -> V_143 ,
V_27 -> V_320 ) ;
F_51 ( V_27 ) ;
return F_11 ( V_5 , V_27 -> V_55 , V_321 , 0 , NULL ,
0 ) ;
}
static struct V_95 * F_137 ( struct V_275 * V_276 )
{
struct V_26 * V_27 = V_276 -> V_27 ;
struct V_95 * V_7 ;
F_19 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 != V_322 )
continue;
if ( V_7 -> V_323 != V_276 )
continue;
return V_7 ;
}
return NULL ;
}
static void F_138 ( struct V_95 * V_7 , T_1 V_8 )
{
struct V_324 V_21 ;
struct V_275 * V_276 = V_7 -> V_323 ;
F_58 ( & V_21 . V_264 . V_153 , & V_276 -> V_302 ) ;
V_21 . V_264 . type = F_132 ( V_276 -> type , V_276 -> V_303 ) ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_322 , V_8 ,
& V_21 , sizeof( V_21 ) ) ;
V_276 -> V_325 = NULL ;
V_276 -> V_326 = NULL ;
V_276 -> V_327 = NULL ;
F_139 ( V_276 ) ;
F_68 ( V_7 ) ;
}
static void F_140 ( struct V_275 * V_276 , T_1 V_8 )
{
struct V_95 * V_7 ;
F_4 ( L_14 , V_8 ) ;
V_7 = F_137 ( V_276 ) ;
if ( ! V_7 )
F_4 ( L_15 ) ;
else
F_138 ( V_7 , F_1 ( V_8 ) ) ;
}
static void F_141 ( struct V_275 * V_276 , T_1 V_8 )
{
struct V_95 * V_7 ;
F_4 ( L_14 , V_8 ) ;
if ( ! V_8 )
return;
V_7 = F_137 ( V_276 ) ;
if ( ! V_7 )
F_4 ( L_15 ) ;
else
F_138 ( V_7 , F_1 ( V_8 ) ) ;
}
static int F_142 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_328 * V_106 = V_25 ;
struct V_324 V_21 ;
struct V_95 * V_7 ;
T_1 V_329 , V_330 ;
struct V_275 * V_276 ;
int V_15 ;
F_4 ( L_11 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_58 ( & V_21 . V_264 . V_153 , & V_106 -> V_264 . V_153 ) ;
V_21 . V_264 . type = V_106 -> V_264 . type ;
if ( ! F_128 ( V_106 -> V_264 . type ) )
return F_11 ( V_5 , V_27 -> V_55 , V_322 ,
V_163 ,
& V_21 , sizeof( V_21 ) ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_322 ,
V_190 , & V_21 , sizeof( V_21 ) ) ;
goto V_180;
}
V_329 = V_331 ;
if ( V_106 -> V_332 == 0x03 )
V_330 = V_333 ;
else
V_330 = V_334 ;
if ( V_106 -> V_264 . type == V_265 )
V_276 = F_143 ( V_27 , V_280 , & V_106 -> V_264 . V_153 ,
V_106 -> V_264 . type , V_329 , V_330 ) ;
else
V_276 = F_143 ( V_27 , V_226 , & V_106 -> V_264 . V_153 ,
V_106 -> V_264 . type , V_329 , V_330 ) ;
if ( F_144 ( V_276 ) ) {
int V_8 ;
if ( F_145 ( V_276 ) == - V_335 )
V_8 = V_164 ;
else
V_8 = V_336 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_322 ,
V_8 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_180;
}
if ( V_276 -> V_325 ) {
F_139 ( V_276 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_322 ,
V_164 , & V_21 , sizeof( V_21 ) ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_322 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
F_139 ( V_276 ) ;
goto V_180;
}
if ( V_106 -> V_264 . type == V_265 )
V_276 -> V_325 = F_140 ;
else
V_276 -> V_325 = F_141 ;
V_276 -> V_326 = F_140 ;
V_276 -> V_327 = F_140 ;
V_276 -> V_320 = V_106 -> V_332 ;
V_7 -> V_323 = V_276 ;
if ( V_276 -> V_288 == V_337 &&
F_146 ( V_276 , V_329 , V_330 ) )
F_138 ( V_7 , 0 ) ;
V_15 = 0 ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_147 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_301 * V_264 = V_25 ;
struct V_95 * V_7 ;
struct V_275 * V_276 ;
int V_15 ;
F_4 ( L_11 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_338 ,
V_190 ) ;
goto V_180;
}
V_7 = F_32 ( V_322 , V_27 ) ;
if ( ! V_7 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_338 ,
V_163 ) ;
goto V_180;
}
V_276 = V_7 -> V_323 ;
if ( F_148 ( & V_264 -> V_153 , & V_276 -> V_302 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_338 ,
V_163 ) ;
goto V_180;
}
F_138 ( V_7 , V_339 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_338 , 0 ,
V_264 , sizeof( * V_264 ) ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_149 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_301 * V_264 , T_2 V_246 ,
T_2 V_340 , T_7 V_341 )
{
struct V_95 * V_7 ;
struct V_275 * V_276 ;
int V_15 ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_246 ,
V_190 , V_264 ,
sizeof( * V_264 ) ) ;
goto V_342;
}
if ( V_264 -> type == V_265 )
V_276 = F_131 ( V_27 , V_280 , & V_264 -> V_153 ) ;
else
V_276 = F_131 ( V_27 , V_226 , & V_264 -> V_153 ) ;
if ( ! V_276 ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_246 ,
V_291 , V_264 ,
sizeof( * V_264 ) ) ;
goto V_342;
}
if ( V_264 -> type == V_295 || V_264 -> type == V_296 ) {
V_15 = F_150 ( V_276 , V_246 , V_341 ) ;
if ( ! V_15 )
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_246 ,
V_178 , V_264 ,
sizeof( * V_264 ) ) ;
else
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_246 ,
V_3 , V_264 ,
sizeof( * V_264 ) ) ;
goto V_342;
}
V_7 = F_62 ( V_5 , V_246 , V_27 , V_264 , sizeof( * V_264 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_342;
}
if ( V_340 == V_343 ) {
struct V_344 V_106 ;
F_58 ( & V_106 . V_153 , & V_264 -> V_153 ) ;
V_106 . V_341 = V_341 ;
V_15 = F_102 ( V_27 , V_340 , sizeof( V_106 ) , & V_106 ) ;
} else
V_15 = F_102 ( V_27 , V_340 , sizeof( V_264 -> V_153 ) ,
& V_264 -> V_153 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_342:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_151 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_307 * V_106 = V_25 ;
F_4 ( L_11 ) ;
return F_149 ( V_5 , V_27 , & V_106 -> V_264 ,
V_308 ,
V_309 , 0 ) ;
}
static int F_152 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_345 * V_106 = V_25 ;
F_4 ( L_11 ) ;
if ( V_20 != sizeof( * V_106 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_346 ,
V_163 ) ;
return F_149 ( V_5 , V_27 , & V_106 -> V_264 ,
V_346 ,
V_347 , 0 ) ;
}
static int F_153 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_348 * V_106 = V_25 ;
F_4 ( L_11 ) ;
return F_149 ( V_5 , V_27 , & V_106 -> V_264 ,
V_349 ,
V_350 , 0 ) ;
}
static int F_154 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_351 * V_106 = V_25 ;
F_4 ( L_11 ) ;
return F_149 ( V_5 , V_27 , & V_106 -> V_264 ,
V_352 ,
V_343 , V_106 -> V_341 ) ;
}
static int F_155 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_353 * V_106 = V_25 ;
F_4 ( L_11 ) ;
return F_149 ( V_5 , V_27 , & V_106 -> V_264 ,
V_354 ,
V_355 , 0 ) ;
}
static void F_156 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_356 V_106 ;
memcpy ( V_106 . V_143 , V_27 -> V_98 , sizeof( V_106 . V_143 ) ) ;
F_35 ( V_104 , V_357 , sizeof( V_106 ) , & V_106 ) ;
}
static void F_157 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_358 * V_106 ;
struct V_95 * V_7 ;
F_4 ( L_8 , V_8 ) ;
F_50 ( V_27 ) ;
V_7 = F_32 ( V_359 , V_27 ) ;
if ( ! V_7 )
goto V_180;
V_106 = V_7 -> V_113 ;
if ( V_8 )
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_359 ,
F_1 ( V_8 ) ) ;
else
F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_359 , 0 ,
V_106 , sizeof( * V_106 ) ) ;
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
}
static int F_158 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_358 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
int V_15 ;
F_4 ( L_11 ) ;
F_50 ( V_27 ) ;
if ( ! memcmp ( V_27 -> V_98 , V_106 -> V_143 , sizeof( V_27 -> V_98 ) ) &&
! memcmp ( V_27 -> V_157 , V_106 -> V_157 ,
sizeof( V_27 -> V_157 ) ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_359 , 0 ,
V_25 , V_20 ) ;
goto V_165;
}
memcpy ( V_27 -> V_157 , V_106 -> V_157 , sizeof( V_27 -> V_157 ) ) ;
if ( ! F_27 ( V_27 ) ) {
memcpy ( V_27 -> V_98 , V_106 -> V_143 , sizeof( V_27 -> V_98 ) ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_359 , 0 ,
V_25 , V_20 ) ;
if ( V_15 < 0 )
goto V_165;
V_15 = F_75 ( V_360 , V_27 , V_25 , V_20 ,
V_5 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_359 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
memcpy ( V_27 -> V_98 , V_106 -> V_143 , sizeof( V_27 -> V_98 ) ) ;
F_49 ( & V_104 , V_27 ) ;
if ( F_23 ( V_27 ) ) {
F_156 ( & V_104 ) ;
F_42 ( & V_104 ) ;
}
if ( F_25 ( V_27 ) )
F_34 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_157 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_159 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_95 * V_7 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_361 ,
V_190 ) ;
goto V_180;
}
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_361 ,
V_176 ) ;
goto V_180;
}
if ( F_32 ( V_361 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_361 ,
V_164 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_361 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
V_15 = F_102 ( V_27 , V_362 , 0 , NULL ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_160 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_363 * V_106 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_16 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
V_15 = F_161 ( V_27 , & V_106 -> V_264 . V_153 , V_106 -> V_364 ,
V_106 -> V_365 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_178 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_366 , V_8 ,
& V_106 -> V_264 , sizeof( V_106 -> V_264 ) ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_162 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_367 * V_106 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
V_15 = F_163 ( V_27 , & V_106 -> V_264 . V_153 ) ;
if ( V_15 < 0 )
V_8 = V_163 ;
else
V_8 = V_178 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_368 ,
V_8 , & V_106 -> V_264 , sizeof( V_106 -> V_264 ) ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_164 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_95 * V_7 ;
T_1 type ;
int V_15 ;
F_165 ( V_27 , V_369 ) ;
V_7 = F_32 ( V_370 , V_27 ) ;
if ( ! V_7 )
return - V_371 ;
type = V_27 -> V_372 . type ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& type , sizeof( type ) ) ;
F_68 ( V_7 ) ;
return V_15 ;
}
static void F_166 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_17 , V_8 ) ;
if ( V_8 ) {
F_50 ( V_27 ) ;
F_164 ( V_27 , V_8 ) ;
F_51 ( V_27 ) ;
return;
}
F_50 ( V_27 ) ;
F_165 ( V_27 , V_373 ) ;
F_51 ( V_27 ) ;
switch ( V_27 -> V_372 . type ) {
case V_374 :
F_85 ( V_27 -> V_185 , & V_27 -> V_375 ,
V_376 ) ;
break;
case V_377 :
F_85 ( V_27 -> V_185 , & V_27 -> V_375 ,
V_378 ) ;
break;
case V_379 :
break;
default:
F_123 ( L_18 , V_27 -> V_372 . type ) ;
}
}
static int F_167 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_380 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
struct V_385 V_386 ;
struct V_103 V_104 ;
T_1 V_387 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
if ( ! F_27 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_190 ) ;
goto V_165;
}
if ( F_21 ( V_388 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_164 ) ;
goto V_165;
}
if ( V_27 -> V_372 . V_288 != V_369 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_164 ) ;
goto V_165;
}
V_7 = F_62 ( V_5 , V_370 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_165;
}
V_27 -> V_372 . type = V_106 -> type ;
F_49 ( & V_104 , V_27 ) ;
switch ( V_27 -> V_372 . type ) {
case V_379 :
V_8 = F_81 ( V_27 ) ;
if ( V_8 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_8 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
if ( F_21 ( V_389 , & V_27 -> V_118 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_164 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
F_168 ( V_27 ) ;
memset ( & V_386 , 0 , sizeof( V_386 ) ) ;
memcpy ( & V_386 . V_387 , V_387 , sizeof( V_386 . V_387 ) ) ;
V_386 . V_109 = V_390 ;
F_35 ( & V_104 , V_391 , sizeof( V_386 ) , & V_386 ) ;
break;
case V_374 :
case V_377 :
V_8 = F_82 ( V_27 ) ;
if ( V_8 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_8 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
if ( V_27 -> V_372 . type == V_377 &&
! F_21 ( V_76 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_176 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
if ( F_21 ( V_81 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_177 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
if ( F_21 ( V_392 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_164 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
memset ( & V_382 , 0 , sizeof( V_382 ) ) ;
V_382 . type = V_393 ;
V_382 . V_205 = F_8 ( V_394 ) ;
V_382 . V_207 = F_8 ( V_395 ) ;
V_382 . V_219 = V_27 -> V_220 ;
F_35 ( & V_104 , V_396 , sizeof( V_382 ) ,
& V_382 ) ;
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
V_384 . V_201 = V_397 ;
V_384 . V_398 = V_399 ;
F_35 ( & V_104 , V_400 , sizeof( V_384 ) ,
& V_384 ) ;
break;
default:
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_370 ,
V_163 ) ;
F_68 ( V_7 ) ;
goto V_165;
}
V_15 = F_52 ( & V_104 , F_166 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
else
F_165 ( V_27 , V_401 ) ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_169 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_95 * V_7 ;
int V_15 ;
V_7 = F_32 ( V_402 , V_27 ) ;
if ( ! V_7 )
return - V_371 ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& V_27 -> V_372 . type , sizeof( V_27 -> V_372 . type ) ) ;
F_68 ( V_7 ) ;
return V_15 ;
}
static void F_170 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_17 , V_8 ) ;
F_50 ( V_27 ) ;
if ( V_8 ) {
F_169 ( V_27 , V_8 ) ;
goto V_180;
}
F_165 ( V_27 , V_369 ) ;
V_180:
F_51 ( V_27 ) ;
}
static int F_171 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_403 * V_404 = V_25 ;
struct V_95 * V_7 ;
struct V_405 V_106 ;
struct V_406 * V_407 ;
struct V_103 V_104 ;
struct V_383 V_384 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
if ( ! F_172 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_402 ,
V_177 , & V_404 -> type ,
sizeof( V_404 -> type ) ) ;
goto V_180;
}
if ( V_27 -> V_372 . type != V_404 -> type ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_402 ,
V_163 , & V_404 -> type ,
sizeof( V_404 -> type ) ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_402 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
F_49 ( & V_104 , V_27 ) ;
switch ( V_27 -> V_372 . V_288 ) {
case V_373 :
if ( F_21 ( V_389 , & V_27 -> V_118 ) ) {
F_35 ( & V_104 , V_408 , 0 , NULL ) ;
} else {
F_72 ( & V_27 -> V_375 ) ;
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
V_384 . V_201 = V_409 ;
F_35 ( & V_104 , V_400 ,
sizeof( V_384 ) , & V_384 ) ;
}
break;
case V_410 :
V_407 = F_173 ( V_27 , V_411 ,
V_412 ) ;
if ( ! V_407 ) {
F_68 ( V_7 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 ,
V_402 , 0 ,
& V_404 -> type ,
sizeof( V_404 -> type ) ) ;
F_165 ( V_27 , V_369 ) ;
goto V_180;
}
F_58 ( & V_106 . V_153 , & V_407 -> V_25 . V_153 ) ;
F_35 ( & V_104 , V_413 , sizeof( V_106 ) ,
& V_106 ) ;
break;
default:
F_4 ( L_19 , V_27 -> V_372 . V_288 ) ;
F_68 ( V_7 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_402 ,
V_3 , & V_404 -> type ,
sizeof( V_404 -> type ) ) ;
goto V_180;
}
V_15 = F_52 ( & V_104 , F_170 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
else
F_165 ( V_27 , V_414 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_174 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_415 * V_106 = V_25 ;
struct V_406 * V_407 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_50 ( V_27 ) ;
if ( ! F_172 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_416 ,
V_3 ) ;
goto V_165;
}
V_407 = F_175 ( V_27 , & V_106 -> V_264 . V_153 ) ;
if ( ! V_407 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_416 ,
V_163 ) ;
goto V_165;
}
if ( V_106 -> V_417 ) {
V_407 -> V_418 = V_419 ;
F_69 ( & V_407 -> V_159 ) ;
} else {
V_407 -> V_418 = V_420 ;
F_176 ( V_27 , V_407 ) ;
}
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_416 , 0 , & V_106 -> V_264 ,
sizeof( V_106 -> V_264 ) ) ;
V_165:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_177 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_421 * V_106 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
if ( ! F_128 ( V_106 -> V_264 . type ) )
return F_11 ( V_5 , V_27 -> V_55 , V_422 ,
V_163 ,
& V_106 -> V_264 , sizeof( V_106 -> V_264 ) ) ;
F_50 ( V_27 ) ;
V_15 = F_178 ( V_27 , & V_106 -> V_264 . V_153 , V_106 -> V_264 . type ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = V_178 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_422 , V_8 ,
& V_106 -> V_264 , sizeof( V_106 -> V_264 ) ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_179 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_423 * V_106 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
if ( ! F_128 ( V_106 -> V_264 . type ) )
return F_11 ( V_5 , V_27 -> V_55 , V_424 ,
V_163 ,
& V_106 -> V_264 , sizeof( V_106 -> V_264 ) ) ;
F_50 ( V_27 ) ;
V_15 = F_180 ( V_27 , & V_106 -> V_264 . V_153 , V_106 -> V_264 . type ) ;
if ( V_15 < 0 )
V_8 = V_163 ;
else
V_8 = V_178 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_424 , V_8 ,
& V_106 -> V_264 , sizeof( V_106 -> V_264 ) ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_181 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_425 * V_106 = V_25 ;
struct V_103 V_104 ;
int V_15 ;
T_9 V_426 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
V_426 = F_87 ( V_106 -> V_426 ) ;
if ( V_426 > 0x0002 )
return F_3 ( V_5 , V_27 -> V_55 , V_427 ,
V_163 ) ;
F_50 ( V_27 ) ;
V_27 -> V_131 = V_426 ;
V_27 -> V_133 = F_87 ( V_106 -> V_428 ) ;
V_27 -> V_134 = F_87 ( V_106 -> V_429 ) ;
V_27 -> V_135 = F_87 ( V_106 -> V_30 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_427 , 0 , NULL , 0 ) ;
F_49 ( & V_104 , V_27 ) ;
F_42 ( & V_104 ) ;
F_52 ( & V_104 , NULL ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static void F_182 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_174 V_175 = { NULL , V_27 } ;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
F_65 ( V_238 , V_27 ,
F_80 , & V_181 ) ;
return;
}
F_65 ( V_238 , V_27 , F_79 ,
& V_175 ) ;
F_78 ( V_27 , V_175 . V_5 ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
}
static int F_183 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
T_1 V_114 , V_237 , V_8 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
V_8 = F_82 ( V_27 ) ;
if ( V_8 )
return F_3 ( V_5 , V_27 -> V_55 , V_238 ,
V_8 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_238 ,
V_163 ) ;
F_50 ( V_27 ) ;
V_114 = ! ! V_106 -> V_114 ;
V_237 = F_21 ( V_81 , & V_27 -> V_53 ) ;
if ( ! F_27 ( V_27 ) || V_114 == V_237 ||
F_99 ( V_27 , V_226 ) > 0 ) {
bool V_179 = false ;
if ( V_114 != F_21 ( V_81 , & V_27 -> V_53 ) ) {
F_88 ( V_81 , & V_27 -> V_53 ) ;
V_179 = true ;
}
V_15 = F_70 ( V_5 , V_238 , V_27 ) ;
if ( V_15 < 0 )
goto V_180;
if ( V_179 )
V_15 = F_78 ( V_27 , V_5 ) ;
goto V_180;
}
if ( F_32 ( V_238 , V_27 ) ||
F_32 ( V_235 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_238 ,
V_164 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_238 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
F_49 ( & V_104 , V_27 ) ;
if ( V_114 )
F_94 ( & V_104 ) ;
else
F_95 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_182 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_184 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_430 * V_106 = V_25 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_431 ,
V_176 ) ;
if ( F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_431 ,
V_177 ) ;
if ( F_148 ( & V_106 -> V_153 , V_411 ) ) {
if ( ! F_148 ( & V_106 -> V_153 , V_432 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_431 ,
V_163 ) ;
if ( ( V_106 -> V_153 . V_433 [ 5 ] & 0xc0 ) != 0xc0 )
return F_3 ( V_5 , V_27 -> V_55 ,
V_431 ,
V_163 ) ;
}
F_50 ( V_27 ) ;
F_58 ( & V_27 -> V_434 , & V_106 -> V_153 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_431 , 0 , NULL , 0 ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static int F_185 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_435 * V_106 = V_25 ;
T_9 V_205 , V_207 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_436 ,
V_176 ) ;
V_205 = F_87 ( V_106 -> V_205 ) ;
if ( V_205 < 0x0004 || V_205 > 0x4000 )
return F_3 ( V_5 , V_27 -> V_55 , V_436 ,
V_163 ) ;
V_207 = F_87 ( V_106 -> V_207 ) ;
if ( V_207 < 0x0004 || V_207 > 0x4000 )
return F_3 ( V_5 , V_27 -> V_55 , V_436 ,
V_163 ) ;
if ( V_207 > V_205 )
return F_3 ( V_5 , V_27 -> V_55 , V_436 ,
V_163 ) ;
F_50 ( V_27 ) ;
V_27 -> V_437 = V_205 ;
V_27 -> V_438 = V_207 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_436 , 0 , NULL , 0 ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
static void F_186 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_95 * V_7 ;
F_4 ( L_8 , V_8 ) ;
F_50 ( V_27 ) ;
V_7 = F_32 ( V_439 , V_27 ) ;
if ( ! V_7 )
goto V_180;
if ( V_8 ) {
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_439 ,
F_1 ( V_8 ) ) ;
} else {
struct V_112 * V_106 = V_7 -> V_113 ;
if ( V_106 -> V_114 )
F_89 ( V_73 , & V_27 -> V_53 ) ;
else
F_56 ( V_73 , & V_27 -> V_53 ) ;
F_70 ( V_7 -> V_5 , V_439 , V_27 ) ;
F_78 ( V_27 , V_7 -> V_5 ) ;
}
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
}
static int F_187 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
int V_15 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
if ( ! F_21 ( V_76 , & V_27 -> V_53 ) ||
V_27 -> V_62 < V_63 )
return F_3 ( V_5 , V_27 -> V_55 , V_439 ,
V_176 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_439 ,
V_163 ) ;
if ( ! F_27 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_439 ,
V_190 ) ;
if ( ! F_21 ( V_72 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_439 ,
V_177 ) ;
F_50 ( V_27 ) ;
if ( F_32 ( V_439 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_439 ,
V_164 ) ;
goto V_180;
}
if ( ! ! V_106 -> V_114 == F_21 ( V_73 , & V_27 -> V_53 ) ) {
V_15 = F_70 ( V_5 , V_439 ,
V_27 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_439 , V_27 ,
V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
F_49 ( & V_104 , V_27 ) ;
F_91 ( & V_104 , V_106 -> V_114 ) ;
V_15 = F_52 ( & V_104 , F_186 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_439 ,
V_3 ) ;
F_68 ( V_7 ) ;
}
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static void F_188 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
T_1 V_189 = 0 ;
F_91 ( V_104 , false ) ;
if ( F_21 ( V_72 , & V_27 -> V_53 ) )
V_189 |= V_193 ;
if ( F_21 ( V_74 , & V_27 -> V_53 ) )
V_189 |= V_199 ;
if ( V_189 )
F_35 ( V_104 , V_200 , 1 , & V_189 ) ;
}
static void F_189 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_95 * V_7 ;
F_4 ( L_8 , V_8 ) ;
F_50 ( V_27 ) ;
V_7 = F_32 ( V_440 , V_27 ) ;
if ( ! V_7 )
goto V_180;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
F_56 ( V_76 , & V_27 -> V_53 ) ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_181 ) ;
} else {
F_70 ( V_7 -> V_5 , V_440 , V_27 ) ;
F_78 ( V_27 , V_7 -> V_5 ) ;
}
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
}
static int F_190 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_112 * V_106 = V_25 ;
struct V_95 * V_7 ;
struct V_103 V_104 ;
int V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_23 ( V_27 ) || ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_440 ,
V_176 ) ;
if ( ! F_21 ( V_77 , & V_27 -> V_53 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_440 ,
V_177 ) ;
if ( V_106 -> V_114 != 0x00 && V_106 -> V_114 != 0x01 )
return F_3 ( V_5 , V_27 -> V_55 , V_440 ,
V_163 ) ;
F_50 ( V_27 ) ;
if ( V_106 -> V_114 == F_21 ( V_76 , & V_27 -> V_53 ) ) {
V_15 = F_70 ( V_5 , V_440 , V_27 ) ;
goto V_180;
}
if ( ! F_27 ( V_27 ) ) {
if ( ! V_106 -> V_114 ) {
F_56 ( V_74 , & V_27 -> V_53 ) ;
F_56 ( V_79 , & V_27 -> V_53 ) ;
F_56 ( V_78 , & V_27 -> V_53 ) ;
F_56 ( V_73 , & V_27 -> V_53 ) ;
F_56 ( V_80 , & V_27 -> V_53 ) ;
}
F_88 ( V_76 , & V_27 -> V_53 ) ;
V_15 = F_70 ( V_5 , V_440 , V_27 ) ;
if ( V_15 < 0 )
goto V_180;
V_15 = F_78 ( V_27 , V_5 ) ;
goto V_180;
}
if ( ! V_106 -> V_114 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_440 ,
V_177 ) ;
goto V_180;
}
if ( F_32 ( V_440 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_440 ,
V_164 ) ;
goto V_180;
}
V_7 = F_62 ( V_5 , V_440 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_180;
}
F_89 ( V_76 , & V_27 -> V_53 ) ;
F_49 ( & V_104 , V_27 ) ;
if ( F_21 ( V_72 , & V_27 -> V_53 ) )
F_188 ( & V_104 ) ;
F_40 ( & V_104 ) ;
V_15 = F_52 ( & V_104 , F_189 ) ;
if ( V_15 < 0 )
F_68 ( V_7 ) ;
V_180:
F_51 ( V_27 ) ;
return V_15 ;
}
static bool F_191 ( struct V_441 * V_262 )
{
if ( V_262 -> V_442 != 0x00 && V_262 -> V_442 != 0x01 )
return false ;
if ( V_262 -> V_443 != 0x00 && V_262 -> V_443 != 0x01 )
return false ;
if ( ! F_192 ( V_262 -> V_264 . type ) )
return false ;
return true ;
}
static int F_193 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_444 , T_2 V_20 )
{
struct V_445 * V_106 = V_444 ;
T_2 V_257 , V_258 ;
int V_42 , V_15 ;
F_4 ( L_7 , V_27 -> V_143 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_446 ,
V_176 ) ;
V_257 = F_87 ( V_106 -> V_257 ) ;
V_258 = sizeof( * V_106 ) + V_257 *
sizeof( struct V_441 ) ;
if ( V_258 != V_20 ) {
F_123 ( L_20 ,
V_20 , V_258 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_446 ,
V_163 ) ;
}
F_4 ( L_21 , V_27 -> V_143 , V_257 ) ;
for ( V_42 = 0 ; V_42 < V_257 ; V_42 ++ ) {
struct V_441 * V_262 = & V_106 -> V_263 [ V_42 ] ;
if ( ! F_191 ( V_262 ) )
return F_3 ( V_5 , V_27 -> V_55 ,
V_446 ,
V_163 ) ;
}
F_50 ( V_27 ) ;
F_194 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_257 ; V_42 ++ ) {
struct V_441 * V_262 = & V_106 -> V_263 [ V_42 ] ;
T_1 type , V_268 ;
if ( V_262 -> V_264 . type == V_295 )
V_268 = V_294 ;
else
V_268 = V_447 ;
if ( V_262 -> V_443 )
type = V_448 ;
else
type = V_449 ;
F_195 ( V_27 , & V_262 -> V_264 . V_153 , V_268 ,
type , 0 , V_262 -> V_442 , V_262 -> V_114 ,
V_262 -> V_450 , V_262 -> V_451 , V_262 -> rand ) ;
}
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_446 , 0 ,
NULL , 0 ) ;
F_51 ( V_27 ) ;
return V_15 ;
}
int F_196 ( struct V_4 * V_5 , struct V_452 * V_453 , T_3 V_454 )
{
void * V_455 ;
T_1 * V_106 ;
struct V_11 * V_12 ;
T_2 V_18 , V_6 , V_20 ;
struct V_26 * V_27 = NULL ;
const struct V_456 * V_457 ;
int V_15 ;
F_4 ( L_22 , V_454 ) ;
if ( V_454 < sizeof( * V_12 ) )
return - V_458 ;
V_455 = F_14 ( V_454 , V_16 ) ;
if ( ! V_455 )
return - V_17 ;
if ( F_197 ( V_455 , V_453 -> V_459 , V_454 ) ) {
V_15 = - V_460 ;
goto V_342;
}
V_12 = V_455 ;
V_18 = F_87 ( V_12 -> V_18 ) ;
V_6 = F_87 ( V_12 -> V_6 ) ;
V_20 = F_87 ( V_12 -> V_20 ) ;
if ( V_20 != V_454 - sizeof( * V_12 ) ) {
V_15 = - V_458 ;
goto V_342;
}
if ( V_6 != V_34 ) {
V_27 = F_198 ( V_6 ) ;
if ( ! V_27 ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_461 ) ;
goto V_342;
}
if ( F_21 ( V_52 , & V_27 -> V_53 ) ||
F_21 ( V_54 , & V_27 -> V_53 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_461 ) ;
goto V_342;
}
}
if ( V_18 >= F_2 ( V_462 ) ||
V_462 [ V_18 ] . V_463 == NULL ) {
F_4 ( L_23 , V_18 ) ;
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_464 ) ;
goto V_342;
}
if ( ( V_27 && V_18 < V_158 ) ||
( ! V_27 && V_18 >= V_158 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_461 ) ;
goto V_342;
}
V_457 = & V_462 [ V_18 ] ;
if ( ( V_457 -> V_465 && V_20 < V_457 -> V_28 ) ||
( ! V_457 -> V_465 && V_20 != V_457 -> V_28 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_163 ) ;
goto V_342;
}
if ( V_27 )
F_53 ( V_5 , V_27 ) ;
V_106 = V_455 + sizeof( * V_12 ) ;
V_15 = V_457 -> V_463 ( V_5 , V_27 , V_106 , V_20 ) ;
if ( V_15 < 0 )
goto V_342;
V_15 = V_454 ;
V_342:
if ( V_27 )
F_199 ( V_27 ) ;
F_16 ( V_455 ) ;
return V_15 ;
}
void F_200 ( struct V_26 * V_27 )
{
if ( V_27 -> V_49 != V_50 )
return;
F_75 ( V_466 , V_27 , NULL , 0 , NULL ) ;
}
void F_201 ( struct V_26 * V_27 )
{
T_1 V_8 = V_461 ;
if ( V_27 -> V_49 != V_50 )
return;
F_65 ( 0 , V_27 , F_80 , & V_8 ) ;
F_75 ( V_467 , V_27 , NULL , 0 , NULL ) ;
}
static void F_202 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_174 V_175 = { NULL , V_27 } ;
F_4 ( L_8 , V_8 ) ;
F_50 ( V_27 ) ;
F_65 ( V_162 , V_27 , F_79 , & V_175 ) ;
F_78 ( V_27 , V_175 . V_5 ) ;
F_51 ( V_27 ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
}
static int F_203 ( struct V_26 * V_27 )
{
struct V_103 V_104 ;
T_1 V_468 ;
F_49 ( & V_104 , V_27 ) ;
if ( F_21 ( V_79 , & V_27 -> V_53 ) &&
! F_204 ( V_27 ) ) {
T_1 V_469 = 1 ;
F_35 ( & V_104 , V_234 , 1 , & V_469 ) ;
}
if ( F_21 ( V_77 , & V_27 -> V_53 ) &&
F_23 ( V_27 ) ) {
struct V_236 V_106 ;
V_106 . V_239 = 1 ;
V_106 . V_240 = F_38 ( V_27 ) ;
if ( V_106 . V_239 != F_107 ( V_27 ) ||
V_106 . V_240 != F_39 ( V_27 ) )
F_35 ( & V_104 , V_241 ,
sizeof( V_106 ) , & V_106 ) ;
}
if ( F_25 ( V_27 ) ) {
if ( F_148 ( & V_27 -> V_434 , V_411 ) )
F_35 ( & V_104 , V_470 , 6 ,
& V_27 -> V_434 ) ;
if ( F_21 ( V_77 , & V_27 -> V_53 ) ) {
F_40 ( & V_104 ) ;
F_34 ( & V_104 ) ;
}
if ( F_21 ( V_81 , & V_27 -> V_53 ) )
F_94 ( & V_104 ) ;
}
V_468 = F_21 ( V_78 , & V_27 -> V_53 ) ;
if ( V_468 != F_21 ( V_230 , & V_27 -> V_118 ) )
F_35 ( & V_104 , V_231 ,
sizeof( V_468 ) , & V_468 ) ;
if ( F_23 ( V_27 ) ) {
if ( F_21 ( V_76 , & V_27 -> V_53 ) )
F_188 ( & V_104 ) ;
F_45 ( & V_104 ) ;
F_156 ( & V_104 ) ;
F_42 ( & V_104 ) ;
}
return F_52 ( & V_104 , F_202 ) ;
}
int F_73 ( struct V_26 * V_27 , T_1 V_471 )
{
struct V_174 V_175 = { NULL , V_27 } ;
T_1 V_472 = V_190 ;
T_1 V_473 [] = { 0 , 0 , 0 } ;
int V_15 ;
if ( ! F_21 ( V_151 , & V_27 -> V_53 ) )
return 0 ;
if ( V_471 ) {
if ( F_203 ( V_27 ) == 0 )
return 0 ;
F_65 ( V_162 , V_27 , F_79 ,
& V_175 ) ;
goto F_78;
}
F_65 ( V_162 , V_27 , F_79 , & V_175 ) ;
F_65 ( 0 , V_27 , F_80 , & V_472 ) ;
if ( memcmp ( V_27 -> V_146 , V_473 , sizeof( V_473 ) ) != 0 )
F_75 ( V_474 , V_27 ,
V_473 , sizeof( V_473 ) , NULL ) ;
F_78:
V_15 = F_78 ( V_27 , V_175 . V_5 ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
return V_15 ;
}
void F_205 ( struct V_26 * V_27 , int V_15 )
{
struct V_95 * V_7 ;
T_1 V_8 ;
V_7 = F_32 ( V_162 , V_27 ) ;
if ( ! V_7 )
return;
if ( V_15 == - V_475 )
V_8 = V_476 ;
else
V_8 = V_3 ;
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_162 , V_8 ) ;
F_68 ( V_7 ) ;
}
void F_206 ( struct V_26 * V_27 )
{
struct V_103 V_104 ;
F_50 ( V_27 ) ;
F_56 ( V_117 , & V_27 -> V_53 ) ;
F_56 ( V_74 , & V_27 -> V_53 ) ;
F_49 ( & V_104 , V_27 ) ;
if ( F_21 ( V_76 , & V_27 -> V_53 ) ) {
T_1 V_189 = V_193 ;
F_35 ( & V_104 , V_200 ,
sizeof( V_189 ) , & V_189 ) ;
}
F_45 ( & V_104 ) ;
F_40 ( & V_104 ) ;
F_52 ( & V_104 , NULL ) ;
V_27 -> V_183 = 0 ;
F_78 ( V_27 , NULL ) ;
F_51 ( V_27 ) ;
}
void F_207 ( struct V_26 * V_27 , T_1 V_477 )
{
bool V_179 ;
if ( F_32 ( V_111 , V_27 ) )
return;
if ( V_477 ) {
V_179 = ! F_54 ( V_74 , & V_27 -> V_53 ) ;
} else {
F_56 ( V_117 , & V_27 -> V_53 ) ;
V_179 = F_48 ( V_74 , & V_27 -> V_53 ) ;
}
if ( V_179 ) {
struct V_103 V_104 ;
F_49 ( & V_104 , V_27 ) ;
F_40 ( & V_104 ) ;
F_52 ( & V_104 , NULL ) ;
F_78 ( V_27 , NULL ) ;
}
}
void F_208 ( struct V_26 * V_27 , T_1 V_213 )
{
bool V_179 ;
if ( F_32 ( V_191 , V_27 ) )
return;
if ( V_213 )
V_179 = ! F_54 ( V_72 , & V_27 -> V_53 ) ;
else
V_179 = F_48 ( V_72 , & V_27 -> V_53 ) ;
if ( V_179 )
F_78 ( V_27 , NULL ) ;
}
void F_209 ( struct V_26 * V_27 , T_1 V_189 , T_1 V_8 )
{
T_1 V_181 = F_1 ( V_8 ) ;
if ( V_189 & V_193 )
F_65 ( V_191 , V_27 ,
F_80 , & V_181 ) ;
if ( V_189 & V_199 )
F_65 ( V_111 , V_27 ,
F_80 , & V_181 ) ;
}
void F_210 ( struct V_26 * V_27 , struct V_478 * V_262 ,
bool V_479 )
{
struct V_480 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_481 = V_479 ;
F_58 ( & V_14 . V_262 . V_264 . V_153 , & V_262 -> V_153 ) ;
V_14 . V_262 . V_264 . type = V_265 ;
V_14 . V_262 . type = V_262 -> type ;
memcpy ( V_14 . V_262 . V_114 , V_262 -> V_114 , V_482 ) ;
V_14 . V_262 . V_267 = V_262 -> V_267 ;
F_75 ( V_483 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_211 ( struct V_26 * V_27 , struct V_484 * V_262 , T_1 V_479 )
{
struct V_485 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_481 = V_479 ;
F_58 ( & V_14 . V_262 . V_264 . V_153 , & V_262 -> V_153 ) ;
V_14 . V_262 . V_264 . type = F_132 ( V_226 , V_262 -> V_486 ) ;
V_14 . V_262 . V_442 = V_262 -> V_442 ;
V_14 . V_262 . V_450 = V_262 -> V_450 ;
V_14 . V_262 . V_451 = V_262 -> V_451 ;
if ( V_262 -> type == V_448 )
V_14 . V_262 . V_443 = 1 ;
memcpy ( V_14 . V_262 . rand , V_262 -> rand , sizeof( V_262 -> rand ) ) ;
memcpy ( V_14 . V_262 . V_114 , V_262 -> V_114 , sizeof( V_262 -> V_114 ) ) ;
F_75 ( V_487 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static inline T_2 F_212 ( T_1 * V_139 , T_2 V_488 , T_1 type , T_1 * V_25 ,
T_1 V_28 )
{
V_139 [ V_488 ++ ] = sizeof( type ) + V_28 ;
V_139 [ V_488 ++ ] = type ;
memcpy ( & V_139 [ V_488 ] , V_25 , V_28 ) ;
V_488 += V_28 ;
return V_488 ;
}
void F_213 ( struct V_26 * V_27 , T_8 * V_153 , T_1 V_293 ,
T_1 V_268 , T_5 V_118 , T_1 * V_143 , T_1 V_97 ,
T_1 * V_146 )
{
char V_455 [ 512 ] ;
struct V_489 * V_14 = ( void * ) V_455 ;
T_2 V_488 = 0 ;
F_58 ( & V_14 -> V_264 . V_153 , V_153 ) ;
V_14 -> V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 -> V_118 = F_214 ( V_118 ) ;
if ( V_97 > 0 )
V_488 = F_212 ( V_14 -> V_139 , 0 , V_102 ,
V_143 , V_97 ) ;
if ( V_146 && memcmp ( V_146 , L_24 , 3 ) != 0 )
V_488 = F_212 ( V_14 -> V_139 , V_488 ,
V_490 , V_146 , 3 ) ;
V_14 -> V_488 = F_8 ( V_488 ) ;
F_75 ( V_491 , V_27 , V_455 ,
sizeof( * V_14 ) + V_488 , NULL ) ;
}
static void F_215 ( struct V_95 * V_7 , void * V_25 )
{
struct V_284 * V_106 = V_7 -> V_113 ;
struct V_4 * * V_5 = V_25 ;
struct V_285 V_21 ;
F_58 ( & V_21 . V_264 . V_153 , & V_106 -> V_264 . V_153 ) ;
V_21 . V_264 . type = V_106 -> V_264 . type ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_286 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
* V_5 = V_7 -> V_5 ;
F_63 ( * V_5 ) ;
F_68 ( V_7 ) ;
}
static void F_216 ( struct V_95 * V_7 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_271 * V_106 = V_7 -> V_113 ;
struct V_272 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_58 ( & V_21 . V_264 . V_153 , & V_106 -> V_264 . V_153 ) ;
V_21 . V_264 . type = V_106 -> V_264 . type ;
F_126 ( V_27 , & V_106 -> V_264 . V_153 , V_106 -> V_264 . type , V_7 -> V_5 ) ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , 0 , & V_21 , sizeof( V_21 ) ) ;
F_68 ( V_7 ) ;
}
void F_217 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_282 )
{
struct V_492 V_14 ;
struct V_4 * V_5 = NULL ;
if ( V_293 != V_280 && V_293 != V_226 )
return;
F_65 ( V_286 , V_27 , F_215 , & V_5 ) ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 . V_282 = V_282 ;
F_75 ( V_493 , V_27 , & V_14 , sizeof( V_14 ) , V_5 ) ;
if ( V_5 )
F_61 ( V_5 ) ;
F_65 ( V_277 , V_27 , F_216 ,
V_27 ) ;
}
void F_218 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_8 )
{
T_1 V_486 = F_132 ( V_293 , V_268 ) ;
struct V_284 * V_106 ;
struct V_285 V_21 ;
struct V_95 * V_7 ;
F_65 ( V_277 , V_27 , F_216 ,
V_27 ) ;
V_7 = F_32 ( V_286 , V_27 ) ;
if ( ! V_7 )
return;
V_106 = V_7 -> V_113 ;
if ( F_148 ( V_153 , & V_106 -> V_264 . V_153 ) )
return;
if ( V_106 -> V_264 . type != V_486 )
return;
F_58 ( & V_21 . V_264 . V_153 , V_153 ) ;
V_21 . V_264 . type = V_486 ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_286 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_68 ( V_7 ) ;
}
void F_219 ( struct V_26 * V_27 , T_8 * V_153 , T_1 V_293 ,
T_1 V_268 , T_1 V_8 )
{
struct V_494 V_14 ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
F_75 ( V_495 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_220 ( struct V_26 * V_27 , T_8 * V_153 , T_1 V_496 )
{
struct V_497 V_14 ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = V_265 ;
V_14 . V_496 = V_496 ;
F_75 ( V_498 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_221 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_8 )
{
struct V_95 * V_7 ;
struct V_499 V_21 ;
V_7 = F_32 ( V_313 , V_27 ) ;
if ( ! V_7 )
return;
F_58 ( & V_21 . V_264 . V_153 , V_153 ) ;
V_21 . V_264 . type = V_265 ;
F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_313 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_68 ( V_7 ) ;
}
void F_222 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_8 )
{
struct V_95 * V_7 ;
struct V_499 V_21 ;
V_7 = F_32 ( V_308 , V_27 ) ;
if ( ! V_7 )
return;
F_58 ( & V_21 . V_264 . V_153 , V_153 ) ;
V_21 . V_264 . type = V_265 ;
F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_308 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_68 ( V_7 ) ;
}
int F_223 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_7 V_500 ,
T_1 V_501 )
{
struct V_502 V_14 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 . V_501 = V_501 ;
V_14 . V_500 = V_500 ;
return F_75 ( V_503 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_224 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 )
{
struct V_504 V_14 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = F_132 ( V_293 , V_268 ) ;
return F_75 ( V_505 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
static int F_225 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_8 ,
T_1 V_18 )
{
struct V_95 * V_7 ;
struct V_506 V_21 ;
int V_15 ;
V_7 = F_32 ( V_18 , V_27 ) ;
if ( ! V_7 )
return - V_371 ;
F_58 ( & V_21 . V_264 . V_153 , V_153 ) ;
V_21 . V_264 . type = F_132 ( V_293 , V_268 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_18 , F_1 ( V_8 ) ,
& V_21 , sizeof( V_21 ) ) ;
F_68 ( V_7 ) ;
return V_15 ;
}
int F_226 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_8 )
{
return F_225 ( V_27 , V_153 , V_293 , V_268 ,
V_8 , V_346 ) ;
}
int F_227 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_8 )
{
return F_225 ( V_27 , V_153 , V_293 , V_268 ,
V_8 ,
V_349 ) ;
}
int F_228 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_8 )
{
return F_225 ( V_27 , V_153 , V_293 , V_268 ,
V_8 , V_352 ) ;
}
int F_229 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_1 V_8 )
{
return F_225 ( V_27 , V_153 , V_293 , V_268 ,
V_8 ,
V_354 ) ;
}
int F_230 ( struct V_26 * V_27 , T_8 * V_153 ,
T_1 V_293 , T_1 V_268 , T_5 V_341 ,
T_1 V_507 )
{
struct V_508 V_14 ;
F_4 ( L_5 , V_27 -> V_143 ) ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 . V_341 = F_214 ( V_341 ) ;
V_14 . V_507 = V_507 ;
return F_75 ( V_509 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_231 ( struct V_26 * V_27 , T_8 * V_153 , T_1 V_293 ,
T_1 V_268 , T_1 V_8 )
{
struct V_510 V_14 ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
F_75 ( V_511 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
void F_232 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_174 V_175 = { NULL , V_27 } ;
bool V_179 ;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
F_65 ( V_229 , V_27 ,
F_80 , & V_181 ) ;
return;
}
if ( F_21 ( V_230 , & V_27 -> V_118 ) )
V_179 = ! F_54 ( V_78 ,
& V_27 -> V_53 ) ;
else
V_179 = F_48 ( V_78 ,
& V_27 -> V_53 ) ;
F_65 ( V_229 , V_27 , F_79 ,
& V_175 ) ;
if ( V_179 )
F_78 ( V_27 , V_175 . V_5 ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
}
static void F_233 ( struct V_103 * V_104 )
{
struct V_26 * V_27 = V_104 -> V_27 ;
struct V_137 V_106 ;
if ( ! F_43 ( V_27 ) )
return;
memset ( V_27 -> V_139 , 0 , sizeof( V_27 -> V_139 ) ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
F_35 ( V_104 , V_140 , sizeof( V_106 ) , & V_106 ) ;
}
void F_234 ( struct V_26 * V_27 , T_1 V_201 , T_1 V_8 )
{
struct V_174 V_175 = { NULL , V_27 } ;
struct V_103 V_104 ;
bool V_179 = false ;
if ( V_8 ) {
T_1 V_181 = F_1 ( V_8 ) ;
if ( V_201 && F_48 ( V_79 ,
& V_27 -> V_53 ) ) {
F_56 ( V_80 , & V_27 -> V_53 ) ;
F_78 ( V_27 , NULL ) ;
}
F_65 ( V_232 , V_27 , F_80 ,
& V_181 ) ;
return;
}
if ( V_201 ) {
V_179 = ! F_54 ( V_79 , & V_27 -> V_53 ) ;
} else {
V_179 = F_48 ( V_79 , & V_27 -> V_53 ) ;
if ( ! V_179 )
V_179 = F_48 ( V_80 ,
& V_27 -> V_53 ) ;
else
F_56 ( V_80 , & V_27 -> V_53 ) ;
}
F_65 ( V_232 , V_27 , F_79 , & V_175 ) ;
if ( V_179 )
F_78 ( V_27 , V_175 . V_5 ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
F_49 ( & V_104 , V_27 ) ;
if ( F_21 ( V_79 , & V_27 -> V_53 ) )
F_42 ( & V_104 ) ;
else
F_233 ( & V_104 ) ;
F_52 ( & V_104 , NULL ) ;
}
static void F_235 ( struct V_95 * V_7 , void * V_25 )
{
struct V_174 * V_175 = V_25 ;
if ( V_175 -> V_5 == NULL ) {
V_175 -> V_5 = V_7 -> V_5 ;
F_63 ( V_175 -> V_5 ) ;
}
}
void F_236 ( struct V_26 * V_27 , T_1 * V_146 ,
T_1 V_8 )
{
struct V_174 V_175 = { NULL , V_27 , F_1 (status) } ;
F_65 ( V_244 , V_27 , F_235 , & V_175 ) ;
F_65 ( V_242 , V_27 , F_235 , & V_175 ) ;
F_65 ( V_243 , V_27 , F_235 , & V_175 ) ;
if ( ! V_8 )
F_75 ( V_474 , V_27 , V_146 , 3 ,
NULL ) ;
if ( V_175 . V_5 )
F_61 ( V_175 . V_5 ) ;
}
void F_237 ( struct V_26 * V_27 , T_1 * V_143 , T_1 V_8 )
{
struct V_358 V_14 ;
struct V_95 * V_7 ;
if ( V_8 )
return;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_143 , V_143 , V_512 ) ;
memcpy ( V_14 . V_157 , V_27 -> V_157 , V_513 ) ;
V_7 = F_32 ( V_359 , V_27 ) ;
if ( ! V_7 ) {
memcpy ( V_27 -> V_98 , V_143 , sizeof( V_27 -> V_98 ) ) ;
if ( F_32 ( V_162 , V_27 ) )
return;
}
F_75 ( V_360 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
void F_238 ( struct V_26 * V_27 , T_1 * V_364 ,
T_1 * V_365 , T_1 V_8 )
{
struct V_95 * V_7 ;
F_4 ( L_25 , V_27 -> V_143 , V_8 ) ;
V_7 = F_32 ( V_361 , V_27 ) ;
if ( ! V_7 )
return;
if ( V_8 ) {
F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_361 ,
F_1 ( V_8 ) ) ;
} else {
struct V_514 V_21 ;
memcpy ( V_21 . V_364 , V_364 , sizeof( V_21 . V_364 ) ) ;
memcpy ( V_21 . V_365 , V_365 , sizeof( V_21 . V_365 ) ) ;
F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_361 ,
0 , & V_21 , sizeof( V_21 ) ) ;
}
F_68 ( V_7 ) ;
}
void F_239 ( struct V_26 * V_27 , T_8 * V_153 , T_1 V_293 ,
T_1 V_268 , T_1 * V_146 , T_10 V_515 , T_1 V_516 , T_1
V_469 , T_1 * V_139 , T_2 V_488 )
{
char V_455 [ 512 ] ;
struct V_517 * V_14 = ( void * ) V_455 ;
T_3 V_518 ;
if ( ! F_172 ( V_27 ) )
return;
if ( sizeof( * V_14 ) + V_488 + 5 > sizeof( V_455 ) )
return;
memset ( V_455 , 0 , sizeof( V_455 ) ) ;
F_58 ( & V_14 -> V_264 . V_153 , V_153 ) ;
V_14 -> V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 -> V_515 = V_515 ;
if ( V_516 )
V_14 -> V_118 |= F_240 ( V_519 ) ;
if ( ! V_469 )
V_14 -> V_118 |= F_240 ( V_520 ) ;
if ( V_488 > 0 )
memcpy ( V_14 -> V_139 , V_139 , V_488 ) ;
if ( V_146 && ! F_241 ( V_14 -> V_139 , V_488 , V_490 ) )
V_488 = F_212 ( V_14 -> V_139 , V_488 , V_490 ,
V_146 , 3 ) ;
V_14 -> V_488 = F_8 ( V_488 ) ;
V_518 = sizeof( * V_14 ) + V_488 ;
F_75 ( V_521 , V_27 , V_14 , V_518 , NULL ) ;
}
void F_242 ( struct V_26 * V_27 , T_8 * V_153 , T_1 V_293 ,
T_1 V_268 , T_10 V_515 , T_1 * V_143 , T_1 V_97 )
{
struct V_517 * V_14 ;
char V_455 [ sizeof( * V_14 ) + V_512 + 2 ] ;
T_2 V_488 ;
V_14 = (struct V_517 * ) V_455 ;
memset ( V_455 , 0 , sizeof( V_455 ) ) ;
F_58 ( & V_14 -> V_264 . V_153 , V_153 ) ;
V_14 -> V_264 . type = F_132 ( V_293 , V_268 ) ;
V_14 -> V_515 = V_515 ;
V_488 = F_212 ( V_14 -> V_139 , 0 , V_102 , V_143 ,
V_97 ) ;
V_14 -> V_488 = F_8 ( V_488 ) ;
F_75 ( V_521 , V_27 , V_14 , sizeof( * V_14 ) + V_488 , NULL ) ;
}
void F_243 ( struct V_26 * V_27 , T_1 V_522 )
{
struct V_523 V_14 ;
struct V_95 * V_7 ;
F_4 ( L_26 , V_27 -> V_143 , V_522 ) ;
if ( V_522 )
V_7 = F_32 ( V_370 , V_27 ) ;
else
V_7 = F_32 ( V_402 , V_27 ) ;
if ( V_7 != NULL ) {
T_1 type = V_27 -> V_372 . type ;
F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , 0 , & type ,
sizeof( type ) ) ;
F_68 ( V_7 ) ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . type = V_27 -> V_372 . type ;
V_14 . V_522 = V_522 ;
F_75 ( V_524 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_244 ( struct V_26 * V_27 , T_8 * V_153 , T_1 type )
{
struct V_95 * V_7 ;
struct V_525 V_14 ;
V_7 = F_32 ( V_422 , V_27 ) ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = type ;
return F_75 ( V_526 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
int F_245 ( struct V_26 * V_27 , T_8 * V_153 , T_1 type )
{
struct V_95 * V_7 ;
struct V_527 V_14 ;
V_7 = F_32 ( V_424 , V_27 ) ;
F_58 ( & V_14 . V_264 . V_153 , V_153 ) ;
V_14 . V_264 . type = type ;
return F_75 ( V_528 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
static void F_246 ( struct V_26 * V_27 , T_1 V_8 )
{
F_4 ( L_25 , V_27 -> V_143 , V_8 ) ;
if ( V_8 ) {
F_56 ( V_81 , & V_27 -> V_53 ) ;
F_78 ( V_27 , NULL ) ;
}
}
void F_247 ( struct V_26 * V_27 )
{
struct V_103 V_104 ;
if ( F_99 ( V_27 , V_226 ) > 0 )
return;
if ( ! F_21 ( V_81 , & V_27 -> V_53 ) )
return;
F_49 ( & V_104 , V_27 ) ;
F_94 ( & V_104 ) ;
if ( F_52 ( & V_104 , F_246 ) < 0 ) {
F_56 ( V_81 , & V_27 -> V_53 ) ;
F_78 ( V_27 , NULL ) ;
}
}
