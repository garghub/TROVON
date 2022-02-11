bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static T_1 F_2 ( T_1 V_5 )
{
if ( V_5 < F_3 ( V_6 ) )
return V_6 [ V_5 ] ;
return V_7 ;
}
static int F_4 ( struct V_8 * V_9 , T_2 V_10 , T_2 V_11 , T_1 V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
F_5 ( L_1 , V_9 , V_10 , V_11 , V_12 ) ;
V_14 = F_6 ( sizeof( * V_16 ) + sizeof( * V_18 ) , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_16 = ( void * ) F_7 ( V_14 , sizeof( * V_16 ) ) ;
V_16 -> V_22 = F_8 ( V_23 ) ;
V_16 -> V_10 = F_9 ( V_10 ) ;
V_16 -> V_24 = F_9 ( sizeof( * V_18 ) ) ;
V_18 = ( void * ) F_7 ( V_14 , sizeof( * V_18 ) ) ;
V_18 -> V_12 = V_12 ;
V_18 -> V_22 = F_9 ( V_11 ) ;
V_19 = F_10 ( V_9 , V_14 ) ;
if ( V_19 < 0 )
F_11 ( V_14 ) ;
return V_19 ;
}
static int F_12 ( struct V_8 * V_9 , T_2 V_10 , T_2 V_11 , T_1 V_12 ,
void * V_25 , T_3 V_26 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_27 * V_18 ;
int V_19 ;
F_5 ( L_2 , V_9 ) ;
V_14 = F_6 ( sizeof( * V_16 ) + sizeof( * V_18 ) + V_26 , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_16 = ( void * ) F_7 ( V_14 , sizeof( * V_16 ) ) ;
V_16 -> V_22 = F_8 ( V_28 ) ;
V_16 -> V_10 = F_9 ( V_10 ) ;
V_16 -> V_24 = F_9 ( sizeof( * V_18 ) + V_26 ) ;
V_18 = ( void * ) F_7 ( V_14 , sizeof( * V_18 ) + V_26 ) ;
V_18 -> V_22 = F_9 ( V_11 ) ;
V_18 -> V_12 = V_12 ;
if ( V_25 )
memcpy ( V_18 -> V_29 , V_25 , V_26 ) ;
V_19 = F_10 ( V_9 , V_14 ) ;
if ( V_19 < 0 )
F_11 ( V_14 ) ;
return V_19 ;
}
static int F_13 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_31 V_25 ;
F_5 ( L_2 , V_9 ) ;
V_25 . V_32 = V_33 ;
V_25 . V_34 = F_8 ( V_35 ) ;
return F_12 ( V_9 , V_36 , V_37 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
static int F_14 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_38 * V_25 ;
const T_2 V_39 = F_3 ( V_40 ) ;
const T_2 V_41 = F_3 ( V_42 ) ;
T_4 * V_22 ;
T_3 V_43 ;
int V_44 , V_19 ;
F_5 ( L_2 , V_9 ) ;
V_43 = sizeof( * V_25 ) + ( ( V_39 + V_41 ) * sizeof( T_2 ) ) ;
V_25 = F_15 ( V_43 , V_20 ) ;
if ( ! V_25 )
return - V_21 ;
V_25 -> V_39 = F_8 ( V_39 ) ;
V_25 -> V_41 = F_8 ( V_41 ) ;
for ( V_44 = 0 , V_22 = V_25 -> V_45 ; V_44 < V_39 ; V_44 ++ , V_22 ++ )
F_16 ( V_40 [ V_44 ] , V_22 ) ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ , V_22 ++ )
F_16 ( V_42 [ V_44 ] , V_22 ) ;
V_19 = F_12 ( V_9 , V_36 , V_46 , 0 , V_25 ,
V_43 ) ;
F_17 ( V_25 ) ;
return V_19 ;
}
static int F_18 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_47 * V_25 ;
struct V_1 * V_48 ;
T_3 V_26 ;
T_2 V_49 ;
int V_19 ;
F_5 ( L_2 , V_9 ) ;
F_19 ( & V_50 ) ;
V_49 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( ! F_1 ( V_48 ) )
continue;
V_49 ++ ;
}
V_26 = sizeof( * V_25 ) + ( 2 * V_49 ) ;
V_25 = F_15 ( V_26 , V_51 ) ;
if ( ! V_25 ) {
F_21 ( & V_50 ) ;
return - V_21 ;
}
V_49 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( F_22 ( V_52 , & V_48 -> V_53 ) )
continue;
if ( ! F_1 ( V_48 ) )
continue;
V_25 -> V_10 [ V_49 ++ ] = F_9 ( V_48 -> V_54 ) ;
F_5 ( L_3 , V_48 -> V_54 ) ;
}
V_25 -> V_55 = F_9 ( V_49 ) ;
V_26 = sizeof( * V_25 ) + ( 2 * V_49 ) ;
F_21 ( & V_50 ) ;
V_19 = F_12 ( V_9 , V_36 , V_56 , 0 , V_25 ,
V_26 ) ;
F_17 ( V_25 ) ;
return V_19 ;
}
static T_5 F_23 ( struct V_1 * V_2 )
{
T_5 V_57 = 0 ;
V_57 |= V_58 ;
V_57 |= V_59 ;
if ( F_24 ( V_2 ) )
V_57 |= V_60 ;
if ( F_25 ( V_2 ) ) {
V_57 |= V_61 ;
if ( V_2 -> V_62 >= V_63 )
V_57 |= V_64 ;
V_57 |= V_65 ;
V_57 |= V_66 ;
V_57 |= V_67 ;
}
if ( V_68 )
V_57 |= V_69 ;
if ( F_26 ( V_2 ) )
V_57 |= V_70 ;
return V_57 ;
}
static T_5 F_27 ( struct V_1 * V_2 )
{
T_5 V_57 = 0 ;
if ( F_28 ( V_2 ) )
V_57 |= V_58 ;
if ( F_22 ( V_71 , & V_2 -> V_53 ) )
V_57 |= V_61 ;
if ( F_22 ( V_72 , & V_2 -> V_53 ) )
V_57 |= V_64 ;
if ( F_22 ( V_73 , & V_2 -> V_53 ) )
V_57 |= V_65 ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) )
V_57 |= V_59 ;
if ( F_25 ( V_2 ) )
V_57 |= V_66 ;
if ( F_22 ( V_75 , & V_2 -> V_53 ) )
V_57 |= V_70 ;
if ( F_22 ( V_76 , & V_2 -> V_53 ) )
V_57 |= V_67 ;
if ( F_22 ( V_77 , & V_2 -> V_53 ) )
V_57 |= V_60 ;
if ( F_22 ( V_78 , & V_2 -> V_53 ) )
V_57 |= V_69 ;
return V_57 ;
}
static T_1 * F_29 ( struct V_1 * V_2 , T_1 * V_29 , T_6 V_24 )
{
T_1 * V_79 = V_29 , * V_80 = NULL ;
struct V_81 * V_82 ;
if ( V_24 < 4 )
return V_79 ;
F_20 (uuid, &hdev->uuids, list) {
T_2 V_83 ;
if ( V_82 -> V_84 != 16 )
continue;
V_83 = F_30 ( & V_82 -> V_82 [ 12 ] ) ;
if ( V_83 < 0x1100 )
continue;
if ( V_83 == V_85 )
continue;
if ( ! V_80 ) {
V_80 = V_79 ;
V_80 [ 0 ] = 1 ;
V_80 [ 1 ] = V_86 ;
V_79 += 2 ;
}
if ( ( V_79 - V_29 ) + sizeof( T_2 ) > V_24 ) {
V_80 [ 1 ] = V_87 ;
break;
}
* V_79 ++ = ( V_83 & 0x00ff ) ;
* V_79 ++ = ( V_83 & 0xff00 ) >> 8 ;
V_80 [ 0 ] += sizeof( V_83 ) ;
}
return V_79 ;
}
static T_1 * F_31 ( struct V_1 * V_2 , T_1 * V_29 , T_6 V_24 )
{
T_1 * V_79 = V_29 , * V_80 = NULL ;
struct V_81 * V_82 ;
if ( V_24 < 6 )
return V_79 ;
F_20 (uuid, &hdev->uuids, list) {
if ( V_82 -> V_84 != 32 )
continue;
if ( ! V_80 ) {
V_80 = V_79 ;
V_80 [ 0 ] = 1 ;
V_80 [ 1 ] = V_88 ;
V_79 += 2 ;
}
if ( ( V_79 - V_29 ) + sizeof( T_5 ) > V_24 ) {
V_80 [ 1 ] = V_89 ;
break;
}
memcpy ( V_79 , & V_82 -> V_82 [ 12 ] , sizeof( T_5 ) ) ;
V_79 += sizeof( T_5 ) ;
V_80 [ 0 ] += sizeof( T_5 ) ;
}
return V_79 ;
}
static T_1 * F_32 ( struct V_1 * V_2 , T_1 * V_29 , T_6 V_24 )
{
T_1 * V_79 = V_29 , * V_80 = NULL ;
struct V_81 * V_82 ;
if ( V_24 < 18 )
return V_79 ;
F_20 (uuid, &hdev->uuids, list) {
if ( V_82 -> V_84 != 128 )
continue;
if ( ! V_80 ) {
V_80 = V_79 ;
V_80 [ 0 ] = 1 ;
V_80 [ 1 ] = V_90 ;
V_79 += 2 ;
}
if ( ( V_79 - V_29 ) + 16 > V_24 ) {
V_80 [ 1 ] = V_91 ;
break;
}
memcpy ( V_79 , V_82 -> V_82 , 16 ) ;
V_79 += 16 ;
V_80 [ 0 ] += 16 ;
}
return V_79 ;
}
static void F_33 ( struct V_1 * V_2 , T_1 * V_29 )
{
T_1 * V_79 = V_29 ;
T_3 V_92 ;
V_92 = strlen ( V_2 -> V_93 ) ;
if ( V_92 > 0 ) {
if ( V_92 > 48 ) {
V_92 = 48 ;
V_79 [ 1 ] = V_94 ;
} else
V_79 [ 1 ] = V_95 ;
V_79 [ 0 ] = V_92 + 1 ;
memcpy ( V_79 + 2 , V_2 -> V_93 , V_92 ) ;
V_79 += ( V_92 + 2 ) ;
}
if ( V_2 -> V_96 != V_97 ) {
V_79 [ 0 ] = 2 ;
V_79 [ 1 ] = V_98 ;
V_79 [ 2 ] = ( T_1 ) V_2 -> V_96 ;
V_79 += 3 ;
}
if ( V_2 -> V_99 > 0 ) {
V_79 [ 0 ] = 9 ;
V_79 [ 1 ] = V_100 ;
F_16 ( V_2 -> V_99 , V_79 + 2 ) ;
F_16 ( V_2 -> V_101 , V_79 + 4 ) ;
F_16 ( V_2 -> V_102 , V_79 + 6 ) ;
F_16 ( V_2 -> V_103 , V_79 + 8 ) ;
V_79 += 10 ;
}
V_79 = F_29 ( V_2 , V_79 , V_104 - ( V_79 - V_29 ) ) ;
V_79 = F_31 ( V_2 , V_79 , V_104 - ( V_79 - V_29 ) ) ;
V_79 = F_32 ( V_2 , V_79 , V_104 - ( V_79 - V_29 ) ) ;
}
static void F_34 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_107 V_108 ;
if ( ! F_28 ( V_2 ) )
return;
if ( ! F_35 ( V_2 ) )
return;
if ( ! F_22 ( V_77 , & V_2 -> V_53 ) )
return;
if ( F_22 ( V_109 , & V_2 -> V_53 ) )
return;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_33 ( V_2 , V_108 . V_29 ) ;
if ( memcmp ( V_108 . V_29 , V_2 -> V_110 , sizeof( V_108 . V_29 ) ) == 0 )
return;
memcpy ( V_2 -> V_110 , V_108 . V_29 , sizeof( V_108 . V_29 ) ) ;
F_36 ( V_106 , V_111 , sizeof( V_108 ) , & V_108 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
T_1 V_112 = 0 ;
F_20 (uuid, &hdev->uuids, list)
V_112 |= V_82 -> V_113 ;
return V_112 ;
}
static void F_38 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
T_1 V_114 [ 3 ] ;
F_5 ( L_4 , V_2 -> V_115 ) ;
if ( ! F_28 ( V_2 ) )
return;
if ( F_22 ( V_109 , & V_2 -> V_53 ) )
return;
V_114 [ 0 ] = V_2 -> V_116 ;
V_114 [ 1 ] = V_2 -> V_117 ;
V_114 [ 2 ] = F_37 ( V_2 ) ;
if ( memcmp ( V_114 , V_2 -> V_118 , 3 ) == 0 )
return;
F_36 ( V_106 , V_119 , sizeof( V_114 ) , V_114 ) ;
}
static void F_39 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_40 ( V_121 , struct V_1 ,
V_122 . V_121 ) ;
struct V_105 V_106 ;
if ( ! F_41 ( V_109 , & V_2 -> V_53 ) )
return;
F_42 ( & V_106 , V_2 ) ;
F_43 ( V_2 ) ;
F_34 ( & V_106 ) ;
F_38 ( & V_106 ) ;
F_44 ( V_2 ) ;
F_45 ( & V_106 , NULL ) ;
}
static void F_46 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_47 ( V_123 , & V_2 -> V_53 ) )
return;
F_48 ( & V_2 -> V_122 , F_39 ) ;
F_49 ( V_74 , & V_2 -> V_53 ) ;
}
static int F_50 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_124 V_25 ;
F_5 ( L_5 , V_9 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_51 ( & V_25 . V_125 , & V_2 -> V_125 ) ;
V_25 . V_32 = V_2 -> V_62 ;
V_25 . V_126 = F_9 ( V_2 -> V_126 ) ;
V_25 . V_127 = F_52 ( F_23 ( V_2 ) ) ;
V_25 . V_128 = F_52 ( F_27 ( V_2 ) ) ;
memcpy ( V_25 . V_118 , V_2 -> V_118 , 3 ) ;
memcpy ( V_25 . V_115 , V_2 -> V_93 , sizeof( V_2 -> V_93 ) ) ;
memcpy ( V_25 . V_129 , V_2 -> V_129 , sizeof( V_2 -> V_129 ) ) ;
F_44 ( V_2 ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_130 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
static void F_53 ( struct V_131 * V_11 )
{
F_54 ( V_11 -> V_9 ) ;
F_17 ( V_11 -> V_132 ) ;
F_17 ( V_11 ) ;
}
static struct V_131 * F_55 ( struct V_8 * V_9 , T_2 V_22 ,
struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_131 * V_11 ;
V_11 = F_15 ( sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_22 = V_22 ;
V_11 -> V_10 = V_2 -> V_54 ;
V_11 -> V_132 = F_15 ( V_24 , V_20 ) ;
if ( ! V_11 -> V_132 ) {
F_17 ( V_11 ) ;
return NULL ;
}
if ( V_29 )
memcpy ( V_11 -> V_132 , V_29 , V_24 ) ;
V_11 -> V_9 = V_9 ;
F_56 ( V_9 ) ;
F_57 ( & V_11 -> V_133 , & V_2 -> V_134 ) ;
return V_11 ;
}
static void F_58 ( T_2 V_22 , struct V_1 * V_2 ,
void (* F_59)( struct V_131 * V_11 ,
void * V_29 ) ,
void * V_29 )
{
struct V_131 * V_11 , * V_135 ;
F_60 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_22 > 0 && V_11 -> V_22 != V_22 )
continue;
F_59 ( V_11 , V_29 ) ;
}
}
static struct V_131 * F_61 ( T_2 V_22 , struct V_1 * V_2 )
{
struct V_131 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 == V_22 )
return V_11 ;
}
return NULL ;
}
static void F_62 ( struct V_131 * V_11 )
{
F_63 ( & V_11 -> V_133 ) ;
F_53 ( V_11 ) ;
}
static int F_64 ( struct V_8 * V_9 , T_2 V_22 , struct V_1 * V_2 )
{
T_7 V_57 = F_52 ( F_27 ( V_2 ) ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_22 , 0 , & V_57 ,
sizeof( V_57 ) ) ;
}
static int F_65 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
struct V_131 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_137 ,
V_138 ) ;
F_43 ( V_2 ) ;
if ( F_41 ( V_139 , & V_2 -> V_53 ) ) {
F_66 ( & V_2 -> V_140 ) ;
if ( V_108 -> V_112 ) {
F_55 ( V_9 , V_137 , V_2 ,
V_29 , V_24 ) ;
V_19 = F_67 ( V_2 , 1 ) ;
goto V_141;
}
}
if ( ! ! V_108 -> V_112 == F_28 ( V_2 ) ) {
V_19 = F_64 ( V_9 , V_137 , V_2 ) ;
goto V_141;
}
if ( F_61 ( V_137 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_137 ,
V_142 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_137 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
if ( V_108 -> V_112 )
F_68 ( V_2 -> V_143 , & V_2 -> V_144 ) ;
else
F_68 ( V_2 -> V_143 , & V_2 -> V_140 . V_121 ) ;
V_19 = 0 ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_69 ( T_2 V_145 , struct V_1 * V_2 , void * V_29 , T_2 V_30 ,
struct V_8 * V_146 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_14 = F_6 ( sizeof( * V_16 ) + V_30 , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_16 = ( void * ) F_7 ( V_14 , sizeof( * V_16 ) ) ;
V_16 -> V_22 = F_9 ( V_145 ) ;
if ( V_2 )
V_16 -> V_10 = F_9 ( V_2 -> V_54 ) ;
else
V_16 -> V_10 = F_8 ( V_36 ) ;
V_16 -> V_24 = F_9 ( V_30 ) ;
if ( V_29 )
memcpy ( F_7 ( V_14 , V_30 ) , V_29 , V_30 ) ;
F_70 ( V_14 ) ;
F_71 ( V_14 , V_146 ) ;
F_11 ( V_14 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_8 * V_147 )
{
T_7 V_18 ;
V_18 = F_52 ( F_27 ( V_2 ) ) ;
return F_69 ( V_148 , V_2 , & V_18 , sizeof( V_18 ) , V_147 ) ;
}
static int F_73 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_149 * V_108 = V_29 ;
struct V_131 * V_11 ;
T_2 V_150 ;
T_1 V_151 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_138 ) ;
V_150 = F_74 ( V_108 -> V_150 ) ;
if ( ! V_108 -> V_112 && V_150 > 0 )
return F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_138 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) && V_150 > 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_154 ) ;
goto V_141;
}
if ( F_61 ( V_152 , V_2 ) ||
F_61 ( V_155 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_142 ) ;
goto V_141;
}
if ( ! F_22 ( V_71 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_156 ) ;
goto V_141;
}
if ( ! F_28 ( V_2 ) ) {
bool V_157 = false ;
if ( ! ! V_108 -> V_112 != F_22 ( V_73 , & V_2 -> V_53 ) ) {
F_75 ( V_73 , & V_2 -> V_53 ) ;
V_157 = true ;
}
V_19 = F_64 ( V_9 , V_152 , V_2 ) ;
if ( V_19 < 0 )
goto V_141;
if ( V_157 )
V_19 = F_72 ( V_2 , V_9 ) ;
goto V_141;
}
if ( ! ! V_108 -> V_112 == F_22 ( V_73 , & V_2 -> V_53 ) ) {
if ( V_2 -> V_158 > 0 ) {
F_66 ( & V_2 -> V_159 ) ;
V_2 -> V_158 = 0 ;
}
if ( V_108 -> V_112 && V_150 > 0 ) {
V_2 -> V_158 = V_150 ;
F_76 ( V_2 -> V_160 , & V_2 -> V_159 ,
F_77 ( V_2 -> V_158 * 1000 ) ) ;
}
V_19 = F_64 ( V_9 , V_152 , V_2 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_152 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
V_151 = V_161 ;
if ( V_108 -> V_112 )
V_151 |= V_162 ;
else
F_66 ( & V_2 -> V_159 ) ;
V_19 = F_78 ( V_2 , V_163 , 1 , & V_151 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
if ( V_108 -> V_112 )
V_2 -> V_158 = V_150 ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static void F_79 ( struct V_105 * V_106 , bool V_164 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_165 V_166 ;
T_1 type ;
if ( V_2 -> V_62 < V_63 )
return;
if ( V_164 ) {
type = V_167 ;
V_166 . V_168 = F_8 ( 0x0100 ) ;
} else {
type = V_169 ;
V_166 . V_168 = F_8 ( 0x0800 ) ;
}
V_166 . V_170 = F_8 ( 0x0012 ) ;
if ( F_80 ( V_2 -> V_171 ) != V_166 . V_168 ||
F_80 ( V_2 -> V_172 ) != V_166 . V_170 )
F_36 ( V_106 , V_173 ,
sizeof( V_166 ) , & V_166 ) ;
if ( V_2 -> V_174 != type )
F_36 ( V_106 , V_175 , 1 , & type ) ;
}
static void F_81 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_131 * V_11 ;
F_5 ( L_7 , V_12 ) ;
F_43 ( V_2 ) ;
V_11 = F_61 ( V_155 , V_2 ) ;
if ( ! V_11 )
goto V_176;
F_64 ( V_11 -> V_9 , V_155 , V_2 ) ;
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
}
static int F_82 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_105 V_106 ;
T_1 V_151 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_155 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_155 ,
V_138 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_157 = false ;
if ( ! ! V_108 -> V_112 != F_22 ( V_71 , & V_2 -> V_53 ) )
V_157 = true ;
if ( V_108 -> V_112 ) {
F_83 ( V_71 , & V_2 -> V_53 ) ;
} else {
F_49 ( V_71 , & V_2 -> V_53 ) ;
F_49 ( V_73 , & V_2 -> V_53 ) ;
}
V_19 = F_64 ( V_9 , V_155 , V_2 ) ;
if ( V_19 < 0 )
goto V_141;
if ( V_157 )
V_19 = F_72 ( V_2 , V_9 ) ;
goto V_141;
}
if ( F_61 ( V_152 , V_2 ) ||
F_61 ( V_155 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_155 ,
V_142 ) ;
goto V_141;
}
if ( ! ! V_108 -> V_112 == F_22 ( V_177 , & V_2 -> V_178 ) ) {
V_19 = F_64 ( V_9 , V_155 , V_2 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_155 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
if ( V_108 -> V_112 ) {
V_151 = V_161 ;
} else {
V_151 = 0 ;
if ( F_22 ( V_179 , & V_2 -> V_178 ) &&
V_2 -> V_158 > 0 )
F_66 ( & V_2 -> V_159 ) ;
}
F_42 ( & V_106 , V_2 ) ;
F_36 ( & V_106 , V_163 , 1 , & V_151 ) ;
if ( V_108 -> V_112 || F_22 ( V_72 , & V_2 -> V_53 ) )
F_79 ( & V_106 , false ) ;
V_19 = F_45 ( & V_106 , F_81 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_84 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_180 ,
V_138 ) ;
F_43 ( V_2 ) ;
if ( V_108 -> V_112 )
F_83 ( V_74 , & V_2 -> V_53 ) ;
else
F_49 ( V_74 , & V_2 -> V_53 ) ;
V_19 = F_64 ( V_9 , V_180 , V_2 ) ;
if ( V_19 < 0 )
goto V_141;
V_19 = F_72 ( V_2 , V_9 ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_85 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
struct V_131 * V_11 ;
T_1 V_112 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_181 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_181 ,
V_138 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_157 = false ;
if ( ! ! V_108 -> V_112 != F_22 ( V_76 ,
& V_2 -> V_53 ) ) {
F_75 ( V_76 , & V_2 -> V_53 ) ;
V_157 = true ;
}
V_19 = F_64 ( V_9 , V_181 , V_2 ) ;
if ( V_19 < 0 )
goto V_141;
if ( V_157 )
V_19 = F_72 ( V_2 , V_9 ) ;
goto V_141;
}
if ( F_61 ( V_181 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_181 ,
V_142 ) ;
goto V_141;
}
V_112 = ! ! V_108 -> V_112 ;
if ( F_22 ( V_182 , & V_2 -> V_178 ) == V_112 ) {
V_19 = F_64 ( V_9 , V_181 , V_2 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_181 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
V_19 = F_78 ( V_2 , V_183 , sizeof( V_112 ) , & V_112 ) ;
if ( V_19 < 0 ) {
F_62 ( V_11 ) ;
goto V_141;
}
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_86 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
struct V_131 * V_11 ;
T_1 V_112 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! F_24 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_184 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_184 ,
V_138 ) ;
F_43 ( V_2 ) ;
V_112 = ! ! V_108 -> V_112 ;
if ( ! F_28 ( V_2 ) ) {
bool V_157 = false ;
if ( V_112 != F_22 ( V_77 , & V_2 -> V_53 ) ) {
F_75 ( V_77 , & V_2 -> V_53 ) ;
V_157 = true ;
}
V_19 = F_64 ( V_9 , V_184 , V_2 ) ;
if ( V_19 < 0 )
goto V_141;
if ( V_157 )
V_19 = F_72 ( V_2 , V_9 ) ;
goto V_141;
}
if ( F_61 ( V_184 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_184 ,
V_142 ) ;
goto V_141;
}
if ( F_22 ( V_77 , & V_2 -> V_53 ) == V_112 ) {
V_19 = F_64 ( V_9 , V_184 , V_2 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_184 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
V_19 = F_78 ( V_2 , V_185 , sizeof( V_112 ) , & V_112 ) ;
if ( V_19 < 0 ) {
F_62 ( V_11 ) ;
goto V_141;
}
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_87 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! V_68 )
return F_4 ( V_9 , V_2 -> V_54 , V_186 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_186 ,
V_138 ) ;
if ( V_108 -> V_112 )
F_83 ( V_78 , & V_2 -> V_53 ) ;
else
F_49 ( V_78 , & V_2 -> V_53 ) ;
return F_64 ( V_9 , V_186 , V_2 ) ;
}
static int F_88 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
struct V_187 V_188 ;
struct V_131 * V_11 ;
int V_19 ;
T_1 V_112 , V_189 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! F_26 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_138 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_156 ) ;
F_43 ( V_2 ) ;
V_112 = ! ! V_108 -> V_112 ;
V_189 = F_89 ( V_2 ) ;
if ( ! F_28 ( V_2 ) || V_112 == V_189 ) {
bool V_157 = false ;
if ( V_112 != F_22 ( V_75 , & V_2 -> V_53 ) ) {
F_75 ( V_75 , & V_2 -> V_53 ) ;
V_157 = true ;
}
V_19 = F_64 ( V_9 , V_190 , V_2 ) ;
if ( V_19 < 0 )
goto V_176;
if ( V_157 )
V_19 = F_72 ( V_2 , V_9 ) ;
goto V_176;
}
if ( F_61 ( V_190 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_142 ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_190 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
if ( V_112 ) {
V_188 . V_191 = V_112 ;
V_188 . V_192 = F_90 ( V_2 ) ;
}
V_19 = F_78 ( V_2 , V_193 , sizeof( V_188 ) ,
& V_188 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static bool F_91 ( struct V_1 * V_2 )
{
struct V_131 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
switch ( V_11 -> V_22 ) {
case V_194 :
case V_195 :
case V_196 :
case V_137 :
return true ;
}
}
return false ;
}
static T_1 F_92 ( const T_1 * V_82 )
{
T_5 V_112 ;
if ( memcmp ( V_82 , V_197 , 12 ) )
return 128 ;
V_112 = F_93 ( & V_82 [ 12 ] ) ;
if ( V_112 > 0xffff )
return 32 ;
return 16 ;
}
static void F_94 ( struct V_1 * V_2 , T_2 V_198 , T_1 V_12 )
{
struct V_131 * V_11 ;
F_43 ( V_2 ) ;
V_11 = F_61 ( V_198 , V_2 ) ;
if ( ! V_11 )
goto V_176;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , F_2 ( V_12 ) ,
V_2 -> V_118 , 3 ) ;
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_2 , T_1 V_12 )
{
F_5 ( L_7 , V_12 ) ;
F_94 ( V_2 , V_194 , V_12 ) ;
}
static int F_96 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_199 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_105 V_106 ;
struct V_81 * V_82 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
if ( F_91 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_194 ,
V_142 ) ;
goto V_141;
}
V_82 = F_15 ( sizeof( * V_82 ) , V_20 ) ;
if ( ! V_82 ) {
V_19 = - V_21 ;
goto V_141;
}
memcpy ( V_82 -> V_82 , V_108 -> V_82 , 16 ) ;
V_82 -> V_113 = V_108 -> V_113 ;
V_82 -> V_84 = F_92 ( V_108 -> V_82 ) ;
F_97 ( & V_82 -> V_133 , & V_2 -> V_200 ) ;
F_42 ( & V_106 , V_2 ) ;
F_38 ( & V_106 ) ;
F_34 ( & V_106 ) ;
V_19 = F_45 ( & V_106 , F_95 ) ;
if ( V_19 < 0 ) {
if ( V_19 != - V_201 )
goto V_141;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_194 , 0 ,
V_2 -> V_118 , 3 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_194 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
V_19 = 0 ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static bool F_98 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 ) )
return false ;
if ( ! F_47 ( V_109 , & V_2 -> V_53 ) ) {
F_76 ( V_2 -> V_160 , & V_2 -> V_122 ,
V_202 ) ;
return true ;
}
return false ;
}
static void F_99 ( struct V_1 * V_2 , T_1 V_12 )
{
F_5 ( L_7 , V_12 ) ;
F_94 ( V_2 , V_195 , V_12 ) ;
}
static int F_100 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_203 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_81 * V_204 , * V_135 ;
T_1 V_205 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_105 V_106 ;
int V_19 , V_206 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
if ( F_91 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_195 ,
V_142 ) ;
goto V_176;
}
if ( memcmp ( V_108 -> V_82 , V_205 , 16 ) == 0 ) {
V_19 = F_101 ( V_2 ) ;
if ( F_98 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_195 ,
0 , V_2 -> V_118 , 3 ) ;
goto V_176;
}
goto F_38;
}
V_206 = 0 ;
F_60 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_204 -> V_82 , V_108 -> V_82 , 16 ) != 0 )
continue;
F_63 ( & V_204 -> V_133 ) ;
F_17 ( V_204 ) ;
V_206 ++ ;
}
if ( V_206 == 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_195 ,
V_138 ) ;
goto V_176;
}
F_38:
F_42 ( & V_106 , V_2 ) ;
F_38 ( & V_106 ) ;
F_34 ( & V_106 ) ;
V_19 = F_45 ( & V_106 , F_99 ) ;
if ( V_19 < 0 ) {
if ( V_19 != - V_201 )
goto V_176;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_195 , 0 ,
V_2 -> V_118 , 3 ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_195 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
V_19 = 0 ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static void F_102 ( struct V_1 * V_2 , T_1 V_12 )
{
F_5 ( L_7 , V_12 ) ;
F_94 ( V_2 , V_196 , V_12 ) ;
}
static int F_103 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_207 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_105 V_106 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_115 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_196 ,
V_153 ) ;
F_43 ( V_2 ) ;
if ( F_91 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_196 ,
V_142 ) ;
goto V_176;
}
if ( ( V_108 -> V_208 & 0x03 ) != 0 || ( V_108 -> V_209 & 0xe0 ) != 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_196 ,
V_138 ) ;
goto V_176;
}
V_2 -> V_117 = V_108 -> V_209 ;
V_2 -> V_116 = V_108 -> V_208 ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_196 , 0 ,
V_2 -> V_118 , 3 ) ;
goto V_176;
}
F_42 ( & V_106 , V_2 ) ;
if ( F_41 ( V_109 , & V_2 -> V_53 ) ) {
F_44 ( V_2 ) ;
F_104 ( & V_2 -> V_122 ) ;
F_43 ( V_2 ) ;
F_34 ( & V_106 ) ;
}
F_38 ( & V_106 ) ;
V_19 = F_45 ( & V_106 , F_102 ) ;
if ( V_19 < 0 ) {
if ( V_19 != - V_201 )
goto V_176;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_196 , 0 ,
V_2 -> V_118 , 3 ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_196 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
V_19 = 0 ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_105 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_210 * V_108 = V_29 ;
T_2 V_211 , V_212 ;
int V_44 ;
V_211 = F_74 ( V_108 -> V_211 ) ;
V_212 = sizeof( * V_108 ) + V_211 *
sizeof( struct V_213 ) ;
if ( V_212 != V_24 ) {
F_106 ( L_8 ,
V_24 , V_212 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_214 ,
V_138 ) ;
}
if ( V_108 -> V_215 != 0x00 && V_108 -> V_215 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_214 ,
V_138 ) ;
F_5 ( L_9 , V_2 -> V_115 , V_108 -> V_215 ,
V_211 ) ;
for ( V_44 = 0 ; V_44 < V_211 ; V_44 ++ ) {
struct V_213 * V_216 = & V_108 -> V_217 [ V_44 ] ;
if ( V_216 -> V_218 . type != V_219 )
return F_4 ( V_9 , V_2 -> V_54 , V_214 ,
V_138 ) ;
}
F_43 ( V_2 ) ;
F_107 ( V_2 ) ;
if ( V_108 -> V_215 )
F_83 ( V_220 , & V_2 -> V_53 ) ;
else
F_49 ( V_220 , & V_2 -> V_53 ) ;
for ( V_44 = 0 ; V_44 < V_211 ; V_44 ++ ) {
struct V_213 * V_216 = & V_108 -> V_217 [ V_44 ] ;
F_108 ( V_2 , NULL , 0 , & V_216 -> V_218 . V_125 , V_216 -> V_112 ,
V_216 -> type , V_216 -> V_221 ) ;
}
F_12 ( V_9 , V_2 -> V_54 , V_214 , 0 , NULL , 0 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_222 , struct V_8 * V_146 )
{
struct V_223 V_18 ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = V_222 ;
return F_69 ( V_224 , V_2 , & V_18 , sizeof( V_18 ) ,
V_146 ) ;
}
static int F_110 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_225 * V_108 = V_29 ;
struct V_226 V_25 ;
struct V_227 V_228 ;
struct V_131 * V_11 ;
struct V_229 * V_230 ;
int V_19 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_51 ( & V_25 . V_218 . V_125 , & V_108 -> V_218 . V_125 ) ;
V_25 . V_218 . type = V_108 -> V_218 . type ;
if ( ! F_111 ( V_108 -> V_218 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_231 ,
V_138 ,
& V_25 , sizeof( V_25 ) ) ;
if ( V_108 -> V_232 != 0x00 && V_108 -> V_232 != 0x01 )
return F_12 ( V_9 , V_2 -> V_54 , V_231 ,
V_138 ,
& V_25 , sizeof( V_25 ) ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_231 ,
V_154 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
if ( V_108 -> V_218 . type == V_219 )
V_19 = F_112 ( V_2 , & V_108 -> V_218 . V_125 ) ;
else
V_19 = F_113 ( V_2 , & V_108 -> V_218 . V_125 ) ;
if ( V_19 < 0 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_231 ,
V_233 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
if ( V_108 -> V_232 ) {
if ( V_108 -> V_218 . type == V_219 )
V_230 = F_114 ( V_2 , V_234 ,
& V_108 -> V_218 . V_125 ) ;
else
V_230 = F_114 ( V_2 , V_235 ,
& V_108 -> V_218 . V_125 ) ;
} else {
V_230 = NULL ;
}
if ( ! V_230 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_231 , 0 ,
& V_25 , sizeof( V_25 ) ) ;
F_109 ( V_2 , & V_108 -> V_218 . V_125 , V_108 -> V_218 . type , V_9 ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_231 , V_2 , V_108 ,
sizeof( * V_108 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
V_228 . V_236 = F_9 ( V_230 -> V_236 ) ;
V_228 . V_237 = 0x13 ;
V_19 = F_78 ( V_2 , V_238 , sizeof( V_228 ) , & V_228 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int V_232 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_239 * V_108 = V_29 ;
struct V_240 V_25 ;
struct V_227 V_228 ;
struct V_131 * V_11 ;
struct V_229 * V_230 ;
int V_19 ;
F_5 ( L_10 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_51 ( & V_25 . V_218 . V_125 , & V_108 -> V_218 . V_125 ) ;
V_25 . V_218 . type = V_108 -> V_218 . type ;
if ( ! F_111 ( V_108 -> V_218 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_241 ,
V_138 ,
& V_25 , sizeof( V_25 ) ) ;
F_43 ( V_2 ) ;
if ( ! F_22 ( V_242 , & V_2 -> V_178 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_241 ,
V_154 , & V_25 , sizeof( V_25 ) ) ;
goto V_141;
}
if ( F_61 ( V_241 , V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_241 ,
V_142 , & V_25 , sizeof( V_25 ) ) ;
goto V_141;
}
if ( V_108 -> V_218 . type == V_219 )
V_230 = F_114 ( V_2 , V_234 ,
& V_108 -> V_218 . V_125 ) ;
else
V_230 = F_114 ( V_2 , V_235 , & V_108 -> V_218 . V_125 ) ;
if ( ! V_230 || V_230 -> V_243 == V_244 || V_230 -> V_243 == V_245 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_241 ,
V_246 , & V_25 , sizeof( V_25 ) ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_241 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
V_228 . V_236 = F_9 ( V_230 -> V_236 ) ;
V_228 . V_237 = V_247 ;
V_19 = F_78 ( V_2 , V_238 , sizeof( V_228 ) , & V_228 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static T_1 F_115 ( T_1 V_248 , T_1 V_222 )
{
switch ( V_248 ) {
case V_235 :
switch ( V_222 ) {
case V_249 :
return V_250 ;
default:
return V_251 ;
}
default:
return V_219 ;
}
}
static int F_116 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_252 * V_25 ;
struct V_229 * V_253 ;
T_3 V_26 ;
int V_19 ;
T_2 V_44 ;
F_5 ( L_10 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_254 ,
V_154 ) ;
goto V_176;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_255 , & V_253 -> V_178 ) )
V_44 ++ ;
}
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_256 ) ) ;
V_25 = F_15 ( V_26 , V_20 ) ;
if ( ! V_25 ) {
V_19 = - V_21 ;
goto V_176;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_255 , & V_253 -> V_178 ) )
continue;
F_51 ( & V_25 -> V_218 [ V_44 ] . V_125 , & V_253 -> V_257 ) ;
V_25 -> V_218 [ V_44 ] . type = F_115 ( V_253 -> type , V_253 -> V_258 ) ;
if ( V_253 -> type == V_259 || V_253 -> type == V_260 )
continue;
V_44 ++ ;
}
V_25 -> V_261 = F_9 ( V_44 ) ;
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_256 ) ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_254 , 0 , V_25 ,
V_26 ) ;
F_17 ( V_25 ) ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_117 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_262 * V_108 )
{
struct V_131 * V_11 ;
int V_19 ;
V_11 = F_55 ( V_9 , V_263 , V_2 , V_108 ,
sizeof( * V_108 ) ) ;
if ( ! V_11 )
return - V_21 ;
V_19 = F_78 ( V_2 , V_264 ,
sizeof( V_108 -> V_218 . V_125 ) , & V_108 -> V_218 . V_125 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
return V_19 ;
}
static int F_118 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_229 * V_230 ;
struct V_265 * V_108 = V_29 ;
struct V_266 V_267 ;
struct V_131 * V_11 ;
int V_19 ;
F_5 ( L_10 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_268 ,
V_154 ) ;
goto V_141;
}
V_230 = F_114 ( V_2 , V_234 , & V_108 -> V_218 . V_125 ) ;
if ( ! V_230 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_268 ,
V_246 ) ;
goto V_141;
}
if ( V_230 -> V_269 == V_270 && V_108 -> V_221 != 16 ) {
struct V_262 V_271 ;
memcpy ( & V_271 . V_218 , & V_108 -> V_218 , sizeof( V_271 . V_218 ) ) ;
F_106 ( L_11 ) ;
V_19 = F_117 ( V_9 , V_2 , & V_271 ) ;
if ( V_19 >= 0 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_268 ,
V_138 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_268 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
F_51 ( & V_267 . V_125 , & V_108 -> V_218 . V_125 ) ;
V_267 . V_221 = V_108 -> V_221 ;
memcpy ( V_267 . V_272 , V_108 -> V_272 , sizeof( V_267 . V_272 ) ) ;
V_19 = F_78 ( V_2 , V_273 , sizeof( V_267 ) , & V_267 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_119 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_274 * V_108 = V_29 ;
F_5 ( L_10 ) ;
F_43 ( V_2 ) ;
V_2 -> V_275 = V_108 -> V_275 ;
F_5 ( L_12 , V_2 -> V_115 ,
V_2 -> V_275 ) ;
F_44 ( V_2 ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_276 , 0 , NULL ,
0 ) ;
}
static struct V_131 * F_120 ( struct V_229 * V_230 )
{
struct V_1 * V_2 = V_230 -> V_2 ;
struct V_131 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 != V_277 )
continue;
if ( V_11 -> V_278 != V_230 )
continue;
return V_11 ;
}
return NULL ;
}
static void F_121 ( struct V_131 * V_11 , T_1 V_12 )
{
struct V_279 V_25 ;
struct V_229 * V_230 = V_11 -> V_278 ;
F_51 ( & V_25 . V_218 . V_125 , & V_230 -> V_257 ) ;
V_25 . V_218 . type = F_115 ( V_230 -> type , V_230 -> V_258 ) ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_277 , V_12 ,
& V_25 , sizeof( V_25 ) ) ;
V_230 -> V_280 = NULL ;
V_230 -> V_281 = NULL ;
V_230 -> V_282 = NULL ;
F_122 ( V_230 ) ;
F_62 ( V_11 ) ;
}
static void F_123 ( struct V_229 * V_230 , T_1 V_12 )
{
struct V_131 * V_11 ;
F_5 ( L_13 , V_12 ) ;
V_11 = F_120 ( V_230 ) ;
if ( ! V_11 )
F_5 ( L_14 ) ;
else
F_121 ( V_11 , F_2 ( V_12 ) ) ;
}
static void F_124 ( struct V_229 * V_230 , T_1 V_12 )
{
struct V_131 * V_11 ;
F_5 ( L_13 , V_12 ) ;
if ( ! V_12 )
return;
V_11 = F_120 ( V_230 ) ;
if ( ! V_11 )
F_5 ( L_14 ) ;
else
F_121 ( V_11 , F_2 ( V_12 ) ) ;
}
static int F_125 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_283 * V_108 = V_29 ;
struct V_279 V_25 ;
struct V_131 * V_11 ;
T_1 V_284 , V_285 ;
struct V_229 * V_230 ;
int V_19 ;
F_5 ( L_10 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_51 ( & V_25 . V_218 . V_125 , & V_108 -> V_218 . V_125 ) ;
V_25 . V_218 . type = V_108 -> V_218 . type ;
if ( ! F_111 ( V_108 -> V_218 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_277 ,
V_138 ,
& V_25 , sizeof( V_25 ) ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_277 ,
V_154 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
V_284 = V_286 ;
if ( V_108 -> V_287 == 0x03 )
V_285 = V_288 ;
else
V_285 = V_289 ;
if ( V_108 -> V_218 . type == V_219 )
V_230 = F_126 ( V_2 , V_234 , & V_108 -> V_218 . V_125 ,
V_108 -> V_218 . type , V_284 , V_285 ) ;
else
V_230 = F_126 ( V_2 , V_235 , & V_108 -> V_218 . V_125 ,
V_108 -> V_218 . type , V_284 , V_285 ) ;
if ( F_127 ( V_230 ) ) {
int V_12 ;
if ( F_128 ( V_230 ) == - V_290 )
V_12 = V_142 ;
else
V_12 = V_291 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_277 ,
V_12 , & V_25 ,
sizeof( V_25 ) ) ;
goto V_176;
}
if ( V_230 -> V_280 ) {
F_122 ( V_230 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_277 ,
V_142 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_277 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
F_122 ( V_230 ) ;
goto V_176;
}
if ( V_108 -> V_218 . type == V_219 )
V_230 -> V_280 = F_123 ;
else
V_230 -> V_280 = F_124 ;
V_230 -> V_281 = F_123 ;
V_230 -> V_282 = F_123 ;
V_230 -> V_275 = V_108 -> V_287 ;
V_11 -> V_278 = V_230 ;
if ( V_230 -> V_243 == V_292 &&
F_129 ( V_230 , V_284 , V_285 ) )
F_121 ( V_11 , 0 ) ;
V_19 = 0 ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_130 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_256 * V_218 = V_29 ;
struct V_131 * V_11 ;
struct V_229 * V_230 ;
int V_19 ;
F_5 ( L_10 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_293 ,
V_154 ) ;
goto V_176;
}
V_11 = F_61 ( V_277 , V_2 ) ;
if ( ! V_11 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_293 ,
V_138 ) ;
goto V_176;
}
V_230 = V_11 -> V_278 ;
if ( F_131 ( & V_218 -> V_125 , & V_230 -> V_257 ) != 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_293 ,
V_138 ) ;
goto V_176;
}
F_121 ( V_11 , V_294 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_293 , 0 ,
V_218 , sizeof( * V_218 ) ) ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_132 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_256 * V_218 , T_2 V_198 ,
T_2 V_295 , T_7 V_296 )
{
struct V_131 * V_11 ;
struct V_229 * V_230 ;
int V_19 ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_198 ,
V_154 , V_218 ,
sizeof( * V_218 ) ) ;
goto V_297;
}
if ( V_218 -> type == V_219 )
V_230 = F_114 ( V_2 , V_234 , & V_218 -> V_125 ) ;
else
V_230 = F_114 ( V_2 , V_235 , & V_218 -> V_125 ) ;
if ( ! V_230 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_198 ,
V_246 , V_218 ,
sizeof( * V_218 ) ) ;
goto V_297;
}
if ( V_218 -> type == V_250 || V_218 -> type == V_251 ) {
V_19 = F_133 ( V_230 , V_198 , V_296 ) ;
if ( ! V_19 )
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_198 ,
V_298 , V_218 ,
sizeof( * V_218 ) ) ;
else
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_198 ,
V_7 , V_218 ,
sizeof( * V_218 ) ) ;
goto V_297;
}
V_11 = F_55 ( V_9 , V_198 , V_2 , V_218 , sizeof( * V_218 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_297;
}
if ( V_295 == V_299 ) {
struct V_300 V_108 ;
F_51 ( & V_108 . V_125 , & V_218 -> V_125 ) ;
V_108 . V_296 = V_296 ;
V_19 = F_78 ( V_2 , V_295 , sizeof( V_108 ) , & V_108 ) ;
} else
V_19 = F_78 ( V_2 , V_295 , sizeof( V_218 -> V_125 ) ,
& V_218 -> V_125 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_297:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_134 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_262 * V_108 = V_29 ;
F_5 ( L_10 ) ;
return F_132 ( V_9 , V_2 , & V_108 -> V_218 ,
V_263 ,
V_264 , 0 ) ;
}
static int F_135 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_301 * V_108 = V_29 ;
F_5 ( L_10 ) ;
if ( V_24 != sizeof( * V_108 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_302 ,
V_138 ) ;
return F_132 ( V_9 , V_2 , & V_108 -> V_218 ,
V_302 ,
V_303 , 0 ) ;
}
static int F_136 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_304 * V_108 = V_29 ;
F_5 ( L_10 ) ;
return F_132 ( V_9 , V_2 , & V_108 -> V_218 ,
V_305 ,
V_306 , 0 ) ;
}
static int F_137 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_307 * V_108 = V_29 ;
F_5 ( L_10 ) ;
return F_132 ( V_9 , V_2 , & V_108 -> V_218 ,
V_308 ,
V_299 , V_108 -> V_296 ) ;
}
static int F_138 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_309 * V_108 = V_29 ;
F_5 ( L_10 ) ;
return F_132 ( V_9 , V_2 , & V_108 -> V_218 ,
V_310 ,
V_311 , 0 ) ;
}
static void F_139 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_312 V_108 ;
memcpy ( V_108 . V_115 , V_2 -> V_93 , sizeof( V_108 . V_115 ) ) ;
F_36 ( V_106 , V_313 , sizeof( V_108 ) , & V_108 ) ;
}
static void F_140 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_314 * V_108 ;
struct V_131 * V_11 ;
F_5 ( L_7 , V_12 ) ;
F_43 ( V_2 ) ;
V_11 = F_61 ( V_315 , V_2 ) ;
if ( ! V_11 )
goto V_176;
V_108 = V_11 -> V_132 ;
if ( V_12 )
F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_315 ,
F_2 ( V_12 ) ) ;
else
F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_315 , 0 ,
V_108 , sizeof( * V_108 ) ) ;
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
}
static int F_141 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_314 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_105 V_106 ;
int V_19 ;
F_5 ( L_10 ) ;
F_43 ( V_2 ) ;
if ( ! memcmp ( V_2 -> V_93 , V_108 -> V_115 , sizeof( V_2 -> V_93 ) ) &&
! memcmp ( V_2 -> V_129 , V_108 -> V_129 ,
sizeof( V_2 -> V_129 ) ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_315 , 0 ,
V_29 , V_24 ) ;
goto V_141;
}
memcpy ( V_2 -> V_129 , V_108 -> V_129 , sizeof( V_2 -> V_129 ) ) ;
if ( ! F_28 ( V_2 ) ) {
memcpy ( V_2 -> V_93 , V_108 -> V_115 , sizeof( V_2 -> V_93 ) ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_315 , 0 ,
V_29 , V_24 ) ;
if ( V_19 < 0 )
goto V_141;
V_19 = F_69 ( V_316 , V_2 , V_29 , V_24 ,
V_9 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_315 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
memcpy ( V_2 -> V_93 , V_108 -> V_115 , sizeof( V_2 -> V_93 ) ) ;
F_42 ( & V_106 , V_2 ) ;
if ( F_25 ( V_2 ) ) {
F_139 ( & V_106 ) ;
F_34 ( & V_106 ) ;
}
if ( F_26 ( V_2 ) )
F_142 ( & V_106 ) ;
V_19 = F_45 ( & V_106 , F_140 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_143 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_131 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_317 ,
V_154 ) ;
goto V_176;
}
if ( ! F_24 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_317 ,
V_153 ) ;
goto V_176;
}
if ( F_61 ( V_317 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_317 ,
V_142 ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_317 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
V_19 = F_78 ( V_2 , V_318 , 0 , NULL ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_144 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_319 * V_108 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_15 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
V_19 = F_145 ( V_2 , & V_108 -> V_218 . V_125 , V_108 -> V_320 ,
V_108 -> V_321 ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = V_298 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_322 , V_12 ,
& V_108 -> V_218 , sizeof( V_108 -> V_218 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_146 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_323 * V_108 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
V_19 = F_147 ( V_2 , & V_108 -> V_218 . V_125 ) ;
if ( V_19 < 0 )
V_12 = V_138 ;
else
V_12 = V_298 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_324 ,
V_12 , & V_108 -> V_218 , sizeof( V_108 -> V_218 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_148 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_131 * V_11 ;
T_1 type ;
int V_19 ;
F_149 ( V_2 , V_325 ) ;
V_11 = F_61 ( V_326 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
type = V_2 -> V_328 . type ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& type , sizeof( type ) ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
static void F_150 ( struct V_1 * V_2 , T_1 V_12 )
{
F_5 ( L_16 , V_12 ) ;
if ( V_12 ) {
F_43 ( V_2 ) ;
F_148 ( V_2 , V_12 ) ;
F_44 ( V_2 ) ;
return;
}
F_43 ( V_2 ) ;
F_149 ( V_2 , V_329 ) ;
F_44 ( V_2 ) ;
switch ( V_2 -> V_328 . type ) {
case V_330 :
F_76 ( V_2 -> V_160 , & V_2 -> V_331 ,
V_332 ) ;
break;
case V_333 :
F_76 ( V_2 -> V_160 , & V_2 -> V_331 ,
V_334 ) ;
break;
case V_335 :
break;
default:
F_106 ( L_17 , V_2 -> V_328 . type ) ;
}
}
static int F_151 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_336 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_337 V_338 ;
struct V_339 V_340 ;
struct V_341 V_342 ;
struct V_105 V_106 ;
T_1 V_343 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_154 ) ;
goto V_141;
}
if ( F_22 ( V_344 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_142 ) ;
goto V_141;
}
if ( V_2 -> V_328 . V_243 != V_325 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_142 ) ;
goto V_141;
}
V_11 = F_55 ( V_9 , V_326 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_141;
}
V_2 -> V_328 . type = V_108 -> type ;
F_42 ( & V_106 , V_2 ) ;
switch ( V_2 -> V_328 . type ) {
case V_335 :
if ( ! F_25 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_153 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
if ( F_22 ( V_345 , & V_2 -> V_178 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_142 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
F_152 ( V_2 ) ;
memset ( & V_342 , 0 , sizeof( V_342 ) ) ;
memcpy ( & V_342 . V_343 , V_343 , sizeof( V_342 . V_343 ) ) ;
V_342 . V_346 = V_347 ;
F_36 ( & V_106 , V_348 , sizeof( V_342 ) , & V_342 ) ;
break;
case V_330 :
case V_333 :
if ( ! F_22 ( V_75 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_153 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
if ( V_2 -> V_328 . type == V_333 &&
! F_25 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_153 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
if ( F_22 ( V_349 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_156 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
if ( F_22 ( V_350 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_142 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
memset ( & V_338 , 0 , sizeof( V_338 ) ) ;
V_338 . type = V_351 ;
V_338 . V_168 = F_9 ( V_352 ) ;
V_338 . V_170 = F_9 ( V_353 ) ;
F_36 ( & V_106 , V_354 , sizeof( V_338 ) ,
& V_338 ) ;
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_340 . V_164 = V_355 ;
V_340 . V_356 = V_357 ;
F_36 ( & V_106 , V_358 , sizeof( V_340 ) ,
& V_340 ) ;
break;
default:
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_326 ,
V_138 ) ;
F_62 ( V_11 ) ;
goto V_141;
}
V_19 = F_45 ( & V_106 , F_150 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
else
F_149 ( V_2 , V_359 ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_153 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_131 * V_11 ;
int V_19 ;
V_11 = F_61 ( V_360 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& V_2 -> V_328 . type , sizeof( V_2 -> V_328 . type ) ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
static void F_154 ( struct V_1 * V_2 , T_1 V_12 )
{
F_5 ( L_16 , V_12 ) ;
F_43 ( V_2 ) ;
if ( V_12 ) {
F_153 ( V_2 , V_12 ) ;
goto V_176;
}
F_149 ( V_2 , V_325 ) ;
V_176:
F_44 ( V_2 ) ;
}
static int F_155 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_361 * V_362 = V_29 ;
struct V_131 * V_11 ;
struct V_363 V_108 ;
struct V_364 * V_365 ;
struct V_105 V_106 ;
struct V_339 V_340 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
if ( ! F_156 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_360 ,
V_156 , & V_362 -> type ,
sizeof( V_362 -> type ) ) ;
goto V_176;
}
if ( V_2 -> V_328 . type != V_362 -> type ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_360 ,
V_138 , & V_362 -> type ,
sizeof( V_362 -> type ) ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_360 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
F_42 ( & V_106 , V_2 ) ;
switch ( V_2 -> V_328 . V_243 ) {
case V_329 :
if ( F_22 ( V_345 , & V_2 -> V_178 ) ) {
F_36 ( & V_106 , V_366 , 0 , NULL ) ;
} else {
F_66 ( & V_2 -> V_331 ) ;
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_340 . V_164 = V_367 ;
F_36 ( & V_106 , V_358 ,
sizeof( V_340 ) , & V_340 ) ;
}
break;
case V_368 :
V_365 = F_157 ( V_2 , V_369 ,
V_370 ) ;
if ( ! V_365 ) {
F_62 ( V_11 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 ,
V_360 , 0 ,
& V_362 -> type ,
sizeof( V_362 -> type ) ) ;
F_149 ( V_2 , V_325 ) ;
goto V_176;
}
F_51 ( & V_108 . V_125 , & V_365 -> V_29 . V_125 ) ;
F_36 ( & V_106 , V_371 , sizeof( V_108 ) ,
& V_108 ) ;
break;
default:
F_5 ( L_18 , V_2 -> V_328 . V_243 ) ;
F_62 ( V_11 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_360 ,
V_7 , & V_362 -> type ,
sizeof( V_362 -> type ) ) ;
goto V_176;
}
V_19 = F_45 ( & V_106 , F_154 ) ;
if ( V_19 < 0 )
F_62 ( V_11 ) ;
else
F_149 ( V_2 , V_372 ) ;
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_158 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_373 * V_108 = V_29 ;
struct V_364 * V_365 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_43 ( V_2 ) ;
if ( ! F_156 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_374 ,
V_7 ) ;
goto V_141;
}
V_365 = F_159 ( V_2 , & V_108 -> V_218 . V_125 ) ;
if ( ! V_365 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_374 ,
V_138 ) ;
goto V_141;
}
if ( V_108 -> V_375 ) {
V_365 -> V_376 = V_377 ;
F_63 ( & V_365 -> V_133 ) ;
} else {
V_365 -> V_376 = V_378 ;
F_160 ( V_2 , V_365 ) ;
}
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_374 , 0 , & V_108 -> V_218 ,
sizeof( V_108 -> V_218 ) ) ;
V_141:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_161 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_379 * V_108 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
if ( ! F_111 ( V_108 -> V_218 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_380 ,
V_138 ,
& V_108 -> V_218 , sizeof( V_108 -> V_218 ) ) ;
F_43 ( V_2 ) ;
V_19 = F_162 ( V_2 , & V_108 -> V_218 . V_125 , V_108 -> V_218 . type ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = V_298 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_380 , V_12 ,
& V_108 -> V_218 , sizeof( V_108 -> V_218 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_163 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_381 * V_108 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
if ( ! F_111 ( V_108 -> V_218 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_382 ,
V_138 ,
& V_108 -> V_218 , sizeof( V_108 -> V_218 ) ) ;
F_43 ( V_2 ) ;
V_19 = F_164 ( V_2 , & V_108 -> V_218 . V_125 , V_108 -> V_218 . type ) ;
if ( V_19 < 0 )
V_12 = V_138 ;
else
V_12 = V_298 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_382 , V_12 ,
& V_108 -> V_218 , sizeof( V_108 -> V_218 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_165 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_383 * V_108 = V_29 ;
struct V_105 V_106 ;
int V_19 ;
T_9 V_384 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
V_384 = F_74 ( V_108 -> V_384 ) ;
if ( V_384 > 0x0002 )
return F_4 ( V_9 , V_2 -> V_54 , V_385 ,
V_138 ) ;
F_43 ( V_2 ) ;
V_2 -> V_99 = V_384 ;
V_2 -> V_101 = F_74 ( V_108 -> V_386 ) ;
V_2 -> V_102 = F_74 ( V_108 -> V_387 ) ;
V_2 -> V_103 = F_74 ( V_108 -> V_32 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_385 , 0 , NULL , 0 ) ;
F_42 ( & V_106 , V_2 ) ;
F_34 ( & V_106 ) ;
F_45 ( & V_106 , NULL ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static void F_166 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_131 * V_11 ;
F_5 ( L_7 , V_12 ) ;
F_43 ( V_2 ) ;
V_11 = F_61 ( V_388 , V_2 ) ;
if ( ! V_11 )
goto V_176;
if ( V_12 ) {
F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_388 ,
F_2 ( V_12 ) ) ;
} else {
struct V_136 * V_108 = V_11 -> V_132 ;
if ( V_108 -> V_112 )
F_83 ( V_72 , & V_2 -> V_53 ) ;
else
F_49 ( V_72 , & V_2 -> V_53 ) ;
F_64 ( V_11 -> V_9 , V_388 , V_2 ) ;
F_72 ( V_2 , V_11 -> V_9 ) ;
}
F_62 ( V_11 ) ;
V_176:
F_44 ( V_2 ) ;
}
static int F_167 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_136 * V_108 = V_29 ;
struct V_131 * V_11 ;
struct V_105 V_106 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
if ( ! F_25 ( V_2 ) || V_2 -> V_62 < V_63 )
return F_4 ( V_9 , V_2 -> V_54 , V_388 ,
V_153 ) ;
if ( V_108 -> V_112 != 0x00 && V_108 -> V_112 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_388 ,
V_138 ) ;
if ( ! F_28 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_388 ,
V_154 ) ;
if ( ! F_22 ( V_71 , & V_2 -> V_53 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_388 ,
V_156 ) ;
F_43 ( V_2 ) ;
if ( F_61 ( V_388 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_388 ,
V_142 ) ;
goto V_176;
}
if ( ! ! V_108 -> V_112 == F_22 ( V_72 , & V_2 -> V_53 ) ) {
V_19 = F_64 ( V_9 , V_388 ,
V_2 ) ;
goto V_176;
}
V_11 = F_55 ( V_9 , V_388 , V_2 ,
V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
F_42 ( & V_106 , V_2 ) ;
F_79 ( & V_106 , V_108 -> V_112 ) ;
V_19 = F_45 ( & V_106 , F_166 ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_388 ,
V_7 ) ;
F_62 ( V_11 ) ;
}
V_176:
F_44 ( V_2 ) ;
return V_19 ;
}
static bool F_168 ( struct V_389 * V_216 )
{
if ( V_216 -> V_390 != 0x00 && V_216 -> V_390 != 0x01 )
return false ;
if ( V_216 -> V_391 != 0x00 && V_216 -> V_391 != 0x01 )
return false ;
if ( ! F_169 ( V_216 -> V_218 . type ) )
return false ;
return true ;
}
static int F_170 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_392 , T_2 V_24 )
{
struct V_393 * V_108 = V_392 ;
T_2 V_211 , V_212 ;
int V_44 , V_19 ;
V_211 = F_74 ( V_108 -> V_211 ) ;
V_212 = sizeof( * V_108 ) + V_211 *
sizeof( struct V_389 ) ;
if ( V_212 != V_24 ) {
F_106 ( L_19 ,
V_24 , V_212 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_394 ,
V_138 ) ;
}
F_5 ( L_20 , V_2 -> V_115 , V_211 ) ;
for ( V_44 = 0 ; V_44 < V_211 ; V_44 ++ ) {
struct V_389 * V_216 = & V_108 -> V_217 [ V_44 ] ;
if ( ! F_168 ( V_216 ) )
return F_4 ( V_9 , V_2 -> V_54 ,
V_394 ,
V_138 ) ;
}
F_43 ( V_2 ) ;
F_171 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_211 ; V_44 ++ ) {
struct V_389 * V_216 = & V_108 -> V_217 [ V_44 ] ;
T_1 type ;
if ( V_216 -> V_391 )
type = V_395 ;
else
type = V_396 ;
F_172 ( V_2 , & V_216 -> V_218 . V_125 ,
F_173 ( V_216 -> V_218 . type ) ,
type , 0 , V_216 -> V_390 , V_216 -> V_112 ,
V_216 -> V_397 , V_216 -> V_398 , V_216 -> rand ) ;
}
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_394 , 0 ,
NULL , 0 ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
int F_174 ( struct V_8 * V_9 , struct V_399 * V_400 , T_3 V_401 )
{
void * V_402 ;
T_1 * V_108 ;
struct V_15 * V_16 ;
T_2 V_22 , V_10 , V_24 ;
struct V_1 * V_2 = NULL ;
const struct V_403 * V_404 ;
int V_19 ;
F_5 ( L_21 , V_401 ) ;
if ( V_401 < sizeof( * V_16 ) )
return - V_405 ;
V_402 = F_15 ( V_401 , V_20 ) ;
if ( ! V_402 )
return - V_21 ;
if ( F_175 ( V_402 , V_400 -> V_406 , V_401 ) ) {
V_19 = - V_407 ;
goto V_297;
}
V_16 = V_402 ;
V_22 = F_74 ( V_16 -> V_22 ) ;
V_10 = F_74 ( V_16 -> V_10 ) ;
V_24 = F_74 ( V_16 -> V_24 ) ;
if ( V_24 != V_401 - sizeof( * V_16 ) ) {
V_19 = - V_405 ;
goto V_297;
}
if ( V_10 != V_36 ) {
V_2 = F_176 ( V_10 ) ;
if ( ! V_2 ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_408 ) ;
goto V_297;
}
}
if ( V_22 >= F_3 ( V_409 ) ||
V_409 [ V_22 ] . V_410 == NULL ) {
F_5 ( L_22 , V_22 ) ;
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_411 ) ;
goto V_297;
}
if ( ( V_2 && V_22 < V_130 ) ||
( ! V_2 && V_22 >= V_130 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_408 ) ;
goto V_297;
}
V_404 = & V_409 [ V_22 ] ;
if ( ( V_404 -> V_412 && V_24 < V_404 -> V_30 ) ||
( ! V_404 -> V_412 && V_24 != V_404 -> V_30 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_138 ) ;
goto V_297;
}
if ( V_2 )
F_46 ( V_9 , V_2 ) ;
V_108 = V_402 + sizeof( * V_16 ) ;
V_19 = V_404 -> V_410 ( V_9 , V_2 , V_108 , V_24 ) ;
if ( V_19 < 0 )
goto V_297;
V_19 = V_401 ;
V_297:
if ( V_2 )
F_177 ( V_2 ) ;
F_17 ( V_402 ) ;
return V_19 ;
}
static void F_178 ( struct V_131 * V_11 , void * V_29 )
{
T_1 * V_12 = V_29 ;
F_4 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , * V_12 ) ;
F_62 ( V_11 ) ;
}
int F_179 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return - V_413 ;
return F_69 ( V_414 , V_2 , NULL , 0 , NULL ) ;
}
int F_180 ( struct V_1 * V_2 )
{
T_1 V_12 = V_408 ;
if ( ! F_1 ( V_2 ) )
return - V_413 ;
F_58 ( 0 , V_2 , F_178 , & V_12 ) ;
return F_69 ( V_415 , V_2 , NULL , 0 , NULL ) ;
}
static void F_181 ( struct V_131 * V_11 , void * V_29 )
{
struct V_416 * V_204 = V_29 ;
F_64 ( V_11 -> V_9 , V_11 -> V_22 , V_204 -> V_2 ) ;
F_63 ( & V_11 -> V_133 ) ;
if ( V_204 -> V_9 == NULL ) {
V_204 -> V_9 = V_11 -> V_9 ;
F_56 ( V_204 -> V_9 ) ;
}
F_53 ( V_11 ) ;
}
static void F_182 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
T_1 V_151 = 0 ;
F_79 ( V_106 , false ) ;
if ( F_22 ( V_71 , & V_2 -> V_53 ) )
V_151 |= V_161 ;
if ( F_22 ( V_73 , & V_2 -> V_53 ) )
V_151 |= V_162 ;
if ( V_151 )
F_36 ( V_106 , V_163 , 1 , & V_151 ) ;
}
static void F_183 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_416 V_204 = { NULL , V_2 } ;
F_5 ( L_7 , V_12 ) ;
F_43 ( V_2 ) ;
F_58 ( V_137 , V_2 , F_181 , & V_204 ) ;
F_72 ( V_2 , V_204 . V_9 ) ;
F_44 ( V_2 ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_105 V_106 ;
T_1 V_417 ;
F_42 ( & V_106 , V_2 ) ;
if ( F_22 ( V_77 , & V_2 -> V_53 ) &&
! F_185 ( V_2 ) ) {
T_1 V_418 = 1 ;
F_36 ( & V_106 , V_185 , 1 , & V_418 ) ;
}
if ( F_22 ( V_75 , & V_2 -> V_53 ) &&
F_25 ( V_2 ) ) {
struct V_187 V_108 ;
V_108 . V_191 = 1 ;
V_108 . V_192 = F_90 ( V_2 ) ;
if ( V_108 . V_191 != F_89 ( V_2 ) ||
V_108 . V_192 != F_186 ( V_2 ) )
F_36 ( & V_106 , V_193 ,
sizeof( V_108 ) , & V_108 ) ;
}
V_417 = F_22 ( V_76 , & V_2 -> V_53 ) ;
if ( V_417 != F_22 ( V_182 , & V_2 -> V_178 ) )
F_36 ( & V_106 , V_183 ,
sizeof( V_417 ) , & V_417 ) ;
if ( F_25 ( V_2 ) ) {
F_182 ( & V_106 ) ;
F_38 ( & V_106 ) ;
F_139 ( & V_106 ) ;
F_34 ( & V_106 ) ;
}
return F_45 ( & V_106 , F_183 ) ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_419 )
{
struct V_416 V_204 = { NULL , V_2 } ;
T_1 V_420 = V_154 ;
T_1 V_421 [] = { 0 , 0 , 0 } ;
int V_19 ;
if ( ! F_22 ( V_123 , & V_2 -> V_53 ) )
return 0 ;
if ( V_419 ) {
if ( F_184 ( V_2 ) == 0 )
return 0 ;
F_58 ( V_137 , V_2 , F_181 ,
& V_204 ) ;
goto F_72;
}
F_58 ( V_137 , V_2 , F_181 , & V_204 ) ;
F_58 ( 0 , V_2 , F_178 , & V_420 ) ;
if ( memcmp ( V_2 -> V_118 , V_421 , sizeof( V_421 ) ) != 0 )
F_69 ( V_422 , V_2 ,
V_421 , sizeof( V_421 ) , NULL ) ;
F_72:
V_19 = F_72 ( V_2 , V_204 . V_9 ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
return V_19 ;
}
int F_187 ( struct V_1 * V_2 , int V_19 )
{
struct V_131 * V_11 ;
T_1 V_12 ;
V_11 = F_61 ( V_137 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
if ( V_19 == - V_423 )
V_12 = V_424 ;
else
V_12 = V_7 ;
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_137 , V_12 ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
int F_188 ( struct V_1 * V_2 , T_1 V_425 )
{
struct V_416 V_204 = { NULL , V_2 } ;
bool V_157 = false ;
int V_19 = 0 ;
if ( V_425 ) {
if ( ! F_47 ( V_73 , & V_2 -> V_53 ) )
V_157 = true ;
} else {
if ( F_41 ( V_73 , & V_2 -> V_53 ) )
V_157 = true ;
}
F_58 ( V_152 , V_2 , F_181 ,
& V_204 ) ;
if ( V_157 )
V_19 = F_72 ( V_2 , V_204 . V_9 ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
return V_19 ;
}
int F_189 ( struct V_1 * V_2 , T_1 V_426 )
{
struct V_131 * V_11 ;
bool V_157 = false ;
int V_19 = 0 ;
if ( V_426 ) {
if ( ! F_47 ( V_71 , & V_2 -> V_53 ) )
V_157 = true ;
} else {
if ( F_41 ( V_71 , & V_2 -> V_53 ) )
V_157 = true ;
}
V_11 = F_61 ( V_155 , V_2 ) ;
if ( V_157 )
V_19 = F_72 ( V_2 , V_11 ? V_11 -> V_9 : NULL ) ;
return V_19 ;
}
int F_190 ( struct V_1 * V_2 , T_1 V_151 , T_1 V_12 )
{
T_1 V_427 = F_2 ( V_12 ) ;
if ( V_151 & V_161 )
F_58 ( V_155 , V_2 ,
F_178 , & V_427 ) ;
if ( V_151 & V_162 )
F_58 ( V_152 , V_2 ,
F_178 , & V_427 ) ;
return 0 ;
}
int F_191 ( struct V_1 * V_2 , struct V_428 * V_216 ,
bool V_429 )
{
struct V_430 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_431 = V_429 ;
F_51 ( & V_18 . V_216 . V_218 . V_125 , & V_216 -> V_125 ) ;
V_18 . V_216 . V_218 . type = V_219 ;
V_18 . V_216 . type = V_216 -> type ;
memcpy ( V_18 . V_216 . V_112 , V_216 -> V_112 , V_432 ) ;
V_18 . V_216 . V_221 = V_216 -> V_221 ;
return F_69 ( V_433 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_192 ( struct V_1 * V_2 , struct V_434 * V_216 , T_1 V_429 )
{
struct V_435 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_431 = V_429 ;
F_51 ( & V_18 . V_216 . V_218 . V_125 , & V_216 -> V_125 ) ;
V_18 . V_216 . V_218 . type = F_115 ( V_235 , V_216 -> V_436 ) ;
V_18 . V_216 . V_390 = V_216 -> V_390 ;
V_18 . V_216 . V_397 = V_216 -> V_397 ;
V_18 . V_216 . V_398 = V_216 -> V_398 ;
if ( V_216 -> type == V_395 )
V_18 . V_216 . V_391 = 1 ;
memcpy ( V_18 . V_216 . rand , V_216 -> rand , sizeof( V_216 -> rand ) ) ;
memcpy ( V_18 . V_216 . V_112 , V_216 -> V_112 , sizeof( V_216 -> V_112 ) ) ;
return F_69 ( V_437 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_193 ( struct V_1 * V_2 , T_8 * V_125 , T_1 V_248 ,
T_1 V_222 , T_5 V_178 , T_1 * V_115 , T_1 V_92 ,
T_1 * V_118 )
{
char V_402 [ 512 ] ;
struct V_438 * V_18 = ( void * ) V_402 ;
T_2 V_439 = 0 ;
F_51 ( & V_18 -> V_218 . V_125 , V_125 ) ;
V_18 -> V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 -> V_178 = F_194 ( V_178 ) ;
if ( V_92 > 0 )
V_439 = F_195 ( V_18 -> V_110 , 0 , V_95 ,
V_115 , V_92 ) ;
if ( V_118 && memcmp ( V_118 , L_23 , 3 ) != 0 )
V_439 = F_195 ( V_18 -> V_110 , V_439 ,
V_440 , V_118 , 3 ) ;
V_18 -> V_439 = F_9 ( V_439 ) ;
return F_69 ( V_441 , V_2 , V_402 ,
sizeof( * V_18 ) + V_439 , NULL ) ;
}
static void F_196 ( struct V_131 * V_11 , void * V_29 )
{
struct V_239 * V_108 = V_11 -> V_132 ;
struct V_8 * * V_9 = V_29 ;
struct V_240 V_25 ;
F_51 ( & V_25 . V_218 . V_125 , & V_108 -> V_218 . V_125 ) ;
V_25 . V_218 . type = V_108 -> V_218 . type ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_241 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
* V_9 = V_11 -> V_9 ;
F_56 ( * V_9 ) ;
F_62 ( V_11 ) ;
}
static void F_197 ( struct V_131 * V_11 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_225 * V_108 = V_11 -> V_132 ;
struct V_226 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_51 ( & V_25 . V_218 . V_125 , & V_108 -> V_218 . V_125 ) ;
V_25 . V_218 . type = V_108 -> V_218 . type ;
F_109 ( V_2 , & V_108 -> V_218 . V_125 , V_108 -> V_218 . type , V_11 -> V_9 ) ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , 0 , & V_25 , sizeof( V_25 ) ) ;
F_62 ( V_11 ) ;
}
int F_198 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_237 )
{
struct V_442 V_18 ;
struct V_8 * V_9 = NULL ;
int V_19 ;
F_58 ( V_241 , V_2 , F_196 , & V_9 ) ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 . V_237 = V_237 ;
V_19 = F_69 ( V_443 , V_2 , & V_18 , sizeof( V_18 ) ,
V_9 ) ;
if ( V_9 )
F_54 ( V_9 ) ;
F_58 ( V_231 , V_2 , F_197 ,
V_2 ) ;
return V_19 ;
}
int F_199 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_12 )
{
struct V_240 V_25 ;
struct V_131 * V_11 ;
int V_19 ;
F_58 ( V_231 , V_2 , F_197 ,
V_2 ) ;
V_11 = F_61 ( V_241 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
F_51 ( & V_25 . V_218 . V_125 , V_125 ) ;
V_25 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_19 = F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_241 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
int F_200 ( struct V_1 * V_2 , T_8 * V_125 , T_1 V_248 ,
T_1 V_222 , T_1 V_12 )
{
struct V_444 V_18 ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_69 ( V_445 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_201 ( struct V_1 * V_2 , T_8 * V_125 , T_1 V_446 )
{
struct V_447 V_18 ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = V_219 ;
V_18 . V_446 = V_446 ;
return F_69 ( V_448 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_202 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_12 )
{
struct V_131 * V_11 ;
struct V_449 V_25 ;
int V_19 ;
V_11 = F_61 ( V_268 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
F_51 ( & V_25 . V_218 . V_125 , V_125 ) ;
V_25 . V_218 . type = V_219 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_268 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
int F_203 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_12 )
{
struct V_131 * V_11 ;
struct V_449 V_25 ;
int V_19 ;
V_11 = F_61 ( V_263 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
F_51 ( & V_25 . V_218 . V_125 , V_125 ) ;
V_25 . V_218 . type = V_219 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_263 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
int F_204 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_7 V_450 ,
T_1 V_451 )
{
struct V_452 V_18 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 . V_451 = V_451 ;
V_18 . V_450 = V_450 ;
return F_69 ( V_453 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_205 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 )
{
struct V_454 V_18 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = F_115 ( V_248 , V_222 ) ;
return F_69 ( V_455 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
static int F_206 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_12 ,
T_1 V_22 )
{
struct V_131 * V_11 ;
struct V_456 V_25 ;
int V_19 ;
V_11 = F_61 ( V_22 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
F_51 ( & V_25 . V_218 . V_125 , V_125 ) ;
V_25 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_22 , F_2 ( V_12 ) ,
& V_25 , sizeof( V_25 ) ) ;
F_62 ( V_11 ) ;
return V_19 ;
}
int F_207 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_12 )
{
return F_206 ( V_2 , V_125 , V_248 , V_222 ,
V_12 , V_302 ) ;
}
int F_208 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_12 )
{
return F_206 ( V_2 , V_125 , V_248 , V_222 ,
V_12 ,
V_305 ) ;
}
int F_209 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_12 )
{
return F_206 ( V_2 , V_125 , V_248 , V_222 ,
V_12 , V_308 ) ;
}
int F_210 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_1 V_12 )
{
return F_206 ( V_2 , V_125 , V_248 , V_222 ,
V_12 ,
V_310 ) ;
}
int F_211 ( struct V_1 * V_2 , T_8 * V_125 ,
T_1 V_248 , T_1 V_222 , T_5 V_296 ,
T_1 V_457 )
{
struct V_458 V_18 ;
F_5 ( L_4 , V_2 -> V_115 ) ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 . V_296 = F_194 ( V_296 ) ;
V_18 . V_457 = V_457 ;
return F_69 ( V_459 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_212 ( struct V_1 * V_2 , T_8 * V_125 , T_1 V_248 ,
T_1 V_222 , T_1 V_12 )
{
struct V_460 V_18 ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_69 ( V_461 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_213 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_416 V_204 = { NULL , V_2 } ;
bool V_157 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_427 = F_2 ( V_12 ) ;
F_58 ( V_181 , V_2 ,
F_178 , & V_427 ) ;
return 0 ;
}
if ( F_22 ( V_182 , & V_2 -> V_178 ) ) {
if ( ! F_47 ( V_76 , & V_2 -> V_53 ) )
V_157 = true ;
} else {
if ( F_41 ( V_76 , & V_2 -> V_53 ) )
V_157 = true ;
}
F_58 ( V_181 , V_2 , F_181 ,
& V_204 ) ;
if ( V_157 )
V_19 = F_72 ( V_2 , V_204 . V_9 ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
return V_19 ;
}
static void F_214 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_107 V_108 ;
if ( ! F_35 ( V_2 ) )
return;
memset ( V_2 -> V_110 , 0 , sizeof( V_2 -> V_110 ) ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_36 ( V_106 , V_111 , sizeof( V_108 ) , & V_108 ) ;
}
int F_215 ( struct V_1 * V_2 , T_1 V_164 , T_1 V_12 )
{
struct V_416 V_204 = { NULL , V_2 } ;
struct V_105 V_106 ;
bool V_157 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_427 = F_2 ( V_12 ) ;
if ( V_164 && F_41 ( V_77 ,
& V_2 -> V_53 ) )
V_19 = F_72 ( V_2 , NULL ) ;
F_58 ( V_184 , V_2 , F_178 ,
& V_427 ) ;
return V_19 ;
}
if ( V_164 ) {
if ( ! F_47 ( V_77 , & V_2 -> V_53 ) )
V_157 = true ;
} else {
if ( F_41 ( V_77 , & V_2 -> V_53 ) )
V_157 = true ;
}
F_58 ( V_184 , V_2 , F_181 , & V_204 ) ;
if ( V_157 )
V_19 = F_72 ( V_2 , V_204 . V_9 ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
F_42 ( & V_106 , V_2 ) ;
if ( F_22 ( V_77 , & V_2 -> V_53 ) )
F_34 ( & V_106 ) ;
else
F_214 ( & V_106 ) ;
F_45 ( & V_106 , NULL ) ;
return V_19 ;
}
static void F_216 ( struct V_131 * V_11 , void * V_29 )
{
struct V_416 * V_204 = V_29 ;
if ( V_204 -> V_9 == NULL ) {
V_204 -> V_9 = V_11 -> V_9 ;
F_56 ( V_204 -> V_9 ) ;
}
}
int F_217 ( struct V_1 * V_2 , T_1 * V_118 ,
T_1 V_12 )
{
struct V_416 V_204 = { NULL , V_2 , F_2 (status) } ;
int V_19 = 0 ;
F_58 ( V_196 , V_2 , F_216 , & V_204 ) ;
F_58 ( V_194 , V_2 , F_216 , & V_204 ) ;
F_58 ( V_195 , V_2 , F_216 , & V_204 ) ;
if ( ! V_12 )
V_19 = F_69 ( V_422 , V_2 , V_118 ,
3 , NULL ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
return V_19 ;
}
int F_218 ( struct V_1 * V_2 , T_1 * V_115 , T_1 V_12 )
{
struct V_314 V_18 ;
struct V_131 * V_11 ;
if ( V_12 )
return 0 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memcpy ( V_18 . V_115 , V_115 , V_462 ) ;
memcpy ( V_18 . V_129 , V_2 -> V_129 , V_463 ) ;
V_11 = F_61 ( V_315 , V_2 ) ;
if ( ! V_11 ) {
memcpy ( V_2 -> V_93 , V_115 , sizeof( V_2 -> V_93 ) ) ;
if ( F_61 ( V_137 , V_2 ) )
return 0 ;
}
return F_69 ( V_316 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
int F_219 ( struct V_1 * V_2 , T_1 * V_320 ,
T_1 * V_321 , T_1 V_12 )
{
struct V_131 * V_11 ;
int V_19 ;
F_5 ( L_24 , V_2 -> V_115 , V_12 ) ;
V_11 = F_61 ( V_317 , V_2 ) ;
if ( ! V_11 )
return - V_327 ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_317 ,
F_2 ( V_12 ) ) ;
} else {
struct V_464 V_25 ;
memcpy ( V_25 . V_320 , V_320 , sizeof( V_25 . V_320 ) ) ;
memcpy ( V_25 . V_321 , V_321 , sizeof( V_25 . V_321 ) ) ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 ,
V_317 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
F_62 ( V_11 ) ;
return V_19 ;
}
int F_220 ( struct V_1 * V_2 , T_1 V_164 , T_1 V_12 )
{
struct V_416 V_204 = { NULL , V_2 } ;
bool V_157 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_427 = F_2 ( V_12 ) ;
if ( V_164 && F_41 ( V_75 ,
& V_2 -> V_53 ) )
V_19 = F_72 ( V_2 , NULL ) ;
F_58 ( V_190 , V_2 , F_178 ,
& V_427 ) ;
return V_19 ;
}
if ( V_164 ) {
if ( ! F_47 ( V_75 , & V_2 -> V_53 ) )
V_157 = true ;
} else {
if ( F_41 ( V_75 , & V_2 -> V_53 ) )
V_157 = true ;
}
F_58 ( V_190 , V_2 , F_181 , & V_204 ) ;
if ( V_157 )
V_19 = F_72 ( V_2 , V_204 . V_9 ) ;
if ( V_204 . V_9 )
F_54 ( V_204 . V_9 ) ;
return V_19 ;
}
int F_221 ( struct V_1 * V_2 , T_8 * V_125 , T_1 V_248 ,
T_1 V_222 , T_1 * V_118 , T_10 V_465 , T_1 V_466 , T_1
V_418 , T_1 * V_110 , T_2 V_439 )
{
char V_402 [ 512 ] ;
struct V_467 * V_18 = ( void * ) V_402 ;
T_3 V_468 ;
if ( ! F_156 ( V_2 ) )
return - V_469 ;
if ( sizeof( * V_18 ) + V_439 + 5 > sizeof( V_402 ) )
return - V_405 ;
memset ( V_402 , 0 , sizeof( V_402 ) ) ;
F_51 ( & V_18 -> V_218 . V_125 , V_125 ) ;
V_18 -> V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 -> V_465 = V_465 ;
if ( V_466 )
V_18 -> V_178 |= F_222 ( V_470 ) ;
if ( ! V_418 )
V_18 -> V_178 |= F_222 ( V_471 ) ;
if ( V_439 > 0 )
memcpy ( V_18 -> V_110 , V_110 , V_439 ) ;
if ( V_118 && ! F_223 ( V_18 -> V_110 , V_439 , V_440 ) )
V_439 = F_195 ( V_18 -> V_110 , V_439 , V_440 ,
V_118 , 3 ) ;
V_18 -> V_439 = F_9 ( V_439 ) ;
V_468 = sizeof( * V_18 ) + V_439 ;
return F_69 ( V_472 , V_2 , V_18 , V_468 , NULL ) ;
}
int F_224 ( struct V_1 * V_2 , T_8 * V_125 , T_1 V_248 ,
T_1 V_222 , T_10 V_465 , T_1 * V_115 , T_1 V_92 )
{
struct V_467 * V_18 ;
char V_402 [ sizeof( * V_18 ) + V_462 + 2 ] ;
T_2 V_439 ;
V_18 = (struct V_467 * ) V_402 ;
memset ( V_402 , 0 , sizeof( V_402 ) ) ;
F_51 ( & V_18 -> V_218 . V_125 , V_125 ) ;
V_18 -> V_218 . type = F_115 ( V_248 , V_222 ) ;
V_18 -> V_465 = V_465 ;
V_439 = F_195 ( V_18 -> V_110 , 0 , V_95 , V_115 ,
V_92 ) ;
V_18 -> V_439 = F_9 ( V_439 ) ;
return F_69 ( V_472 , V_2 , V_18 ,
sizeof( * V_18 ) + V_439 , NULL ) ;
}
int F_225 ( struct V_1 * V_2 , T_1 V_473 )
{
struct V_474 V_18 ;
struct V_131 * V_11 ;
F_5 ( L_25 , V_2 -> V_115 , V_473 ) ;
if ( V_473 )
V_11 = F_61 ( V_326 , V_2 ) ;
else
V_11 = F_61 ( V_360 , V_2 ) ;
if ( V_11 != NULL ) {
T_1 type = V_2 -> V_328 . type ;
F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , 0 , & type ,
sizeof( type ) ) ;
F_62 ( V_11 ) ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . type = V_2 -> V_328 . type ;
V_18 . V_473 = V_473 ;
return F_69 ( V_475 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_226 ( struct V_1 * V_2 , T_8 * V_125 , T_1 type )
{
struct V_131 * V_11 ;
struct V_476 V_18 ;
V_11 = F_61 ( V_380 , V_2 ) ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = type ;
return F_69 ( V_477 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
int F_227 ( struct V_1 * V_2 , T_8 * V_125 , T_1 type )
{
struct V_131 * V_11 ;
struct V_478 V_18 ;
V_11 = F_61 ( V_382 , V_2 ) ;
F_51 ( & V_18 . V_218 . V_125 , V_125 ) ;
V_18 . V_218 . type = type ;
return F_69 ( V_479 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
