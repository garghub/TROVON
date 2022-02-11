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
V_21 . V_32 = F_12 ( V_33 ) ;
return F_10 ( V_5 , V_34 , V_35 , 0 , & V_21 ,
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
V_21 -> V_37 = F_12 ( V_37 ) ;
V_21 -> V_39 = F_12 ( V_39 ) ;
for ( V_42 = 0 , V_18 = V_21 -> V_43 ; V_42 < V_37 ; V_42 ++ , V_18 ++ )
F_15 ( V_38 [ V_42 ] , V_18 ) ;
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ , V_18 ++ )
F_15 ( V_40 [ V_42 ] , V_18 ) ;
V_15 = F_10 ( V_5 , V_34 , V_44 , 0 , V_21 ,
V_41 ) ;
F_16 ( V_21 ) ;
return V_15 ;
}
static int F_17 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_45 * V_21 ;
struct V_46 * V_47 ;
struct V_26 * V_48 ;
T_3 V_22 ;
T_2 V_49 ;
int V_42 , V_15 ;
F_4 ( L_2 , V_5 ) ;
F_18 ( & V_50 ) ;
V_49 = 0 ;
F_19 (p, &hci_dev_list) {
V_49 ++ ;
}
V_22 = sizeof( * V_21 ) + ( 2 * V_49 ) ;
V_21 = F_14 ( V_22 , V_51 ) ;
if ( ! V_21 ) {
F_20 ( & V_50 ) ;
return - V_17 ;
}
V_21 -> V_52 = F_7 ( V_49 ) ;
V_42 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( F_22 ( V_53 , & V_48 -> V_54 ) )
continue;
V_21 -> V_6 [ V_42 ++ ] = F_7 ( V_48 -> V_55 ) ;
F_4 ( L_3 , V_48 -> V_55 ) ;
}
F_20 ( & V_50 ) ;
V_15 = F_10 ( V_5 , V_34 , V_56 , 0 , V_21 ,
V_22 ) ;
F_16 ( V_21 ) ;
return V_15 ;
}
static T_5 F_23 ( struct V_26 * V_27 )
{
T_5 V_57 = 0 ;
V_57 |= V_58 ;
V_57 |= V_59 ;
V_57 |= V_60 ;
V_57 |= V_61 ;
V_57 |= V_62 ;
if ( V_27 -> V_63 [ 6 ] & V_64 )
V_57 |= V_65 ;
if ( ! ( V_27 -> V_63 [ 4 ] & V_66 ) ) {
V_57 |= V_67 ;
V_57 |= V_68 ;
}
if ( V_69 )
V_57 |= V_70 ;
if ( V_27 -> V_63 [ 4 ] & V_71 )
V_57 |= V_72 ;
return V_57 ;
}
static T_5 F_24 ( struct V_26 * V_27 )
{
T_5 V_57 = 0 ;
if ( F_25 ( V_27 ) )
V_57 |= V_58 ;
if ( F_22 ( V_73 , & V_27 -> V_54 ) )
V_57 |= V_59 ;
if ( F_22 ( V_74 , & V_27 -> V_54 ) )
V_57 |= V_61 ;
if ( F_22 ( V_75 , & V_27 -> V_54 ) )
V_57 |= V_62 ;
if ( ! ( V_27 -> V_63 [ 4 ] & V_66 ) )
V_57 |= V_67 ;
if ( F_22 ( V_76 , & V_27 -> V_54 ) )
V_57 |= V_72 ;
if ( F_22 ( V_77 , & V_27 -> V_54 ) )
V_57 |= V_68 ;
if ( F_22 ( V_78 , & V_27 -> V_54 ) )
V_57 |= V_65 ;
if ( F_22 ( V_79 , & V_27 -> V_54 ) )
V_57 |= V_70 ;
return V_57 ;
}
static T_2 F_26 ( T_1 * V_80 )
{
T_5 V_81 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 12 ; V_42 ++ ) {
if ( V_82 [ V_42 ] != V_80 [ V_42 ] )
return 0 ;
}
V_81 = F_27 ( & V_80 [ 12 ] ) ;
if ( V_81 > 0xffff )
return 0 ;
return ( T_2 ) V_81 ;
}
static void F_28 ( struct V_26 * V_27 , T_1 * V_25 )
{
T_1 * V_83 = V_25 ;
T_2 V_84 = 0 ;
T_2 V_85 [ V_86 / sizeof( T_2 ) ] ;
int V_42 , V_87 = 0 ;
struct V_88 * V_89 ;
T_3 V_90 ;
V_90 = strlen ( V_27 -> V_91 ) ;
if ( V_90 > 0 ) {
if ( V_90 > 48 ) {
V_90 = 48 ;
V_83 [ 1 ] = V_92 ;
} else
V_83 [ 1 ] = V_93 ;
V_83 [ 0 ] = V_90 + 1 ;
memcpy ( V_83 + 2 , V_27 -> V_91 , V_90 ) ;
V_84 += ( V_90 + 2 ) ;
V_83 += ( V_90 + 2 ) ;
}
if ( V_27 -> V_94 ) {
V_83 [ 0 ] = 2 ;
V_83 [ 1 ] = V_95 ;
V_83 [ 2 ] = ( T_1 ) V_27 -> V_94 ;
V_84 += 3 ;
V_83 += 3 ;
}
if ( V_27 -> V_96 > 0 ) {
V_83 [ 0 ] = 9 ;
V_83 [ 1 ] = V_97 ;
F_15 ( V_27 -> V_96 , V_83 + 2 ) ;
F_15 ( V_27 -> V_98 , V_83 + 4 ) ;
F_15 ( V_27 -> V_99 , V_83 + 6 ) ;
F_15 ( V_27 -> V_100 , V_83 + 8 ) ;
V_84 += 10 ;
V_83 += 10 ;
}
memset ( V_85 , 0 , sizeof( V_85 ) ) ;
F_21 (uuid, &hdev->uuids, list) {
T_2 V_101 ;
V_101 = F_26 ( V_89 -> V_89 ) ;
if ( V_101 == 0 )
return;
if ( V_101 < 0x1100 )
continue;
if ( V_101 == V_102 )
continue;
if ( V_84 + 2 + sizeof( T_2 ) > V_86 ) {
V_87 = 1 ;
break;
}
for ( V_42 = 0 ; V_85 [ V_42 ] != 0 ; V_42 ++ )
if ( V_85 [ V_42 ] == V_101 )
break;
if ( V_85 [ V_42 ] == 0 ) {
V_85 [ V_42 ] = V_101 ;
V_84 += sizeof( T_2 ) ;
}
}
if ( V_85 [ 0 ] != 0 ) {
T_1 * V_103 = V_83 ;
V_83 [ 1 ] = V_87 ? V_104 : V_105 ;
V_83 += 2 ;
V_84 += 2 ;
for ( V_42 = 0 ; V_85 [ V_42 ] != 0 ; V_42 ++ ) {
* V_83 ++ = ( V_85 [ V_42 ] & 0x00ff ) ;
* V_83 ++ = ( V_85 [ V_42 ] & 0xff00 ) >> 8 ;
}
* V_103 = ( V_42 * sizeof( T_2 ) ) + 1 ;
}
}
static int F_29 ( struct V_26 * V_27 )
{
struct V_106 V_107 ;
if ( ! F_25 ( V_27 ) )
return 0 ;
if ( ! ( V_27 -> V_63 [ 6 ] & V_108 ) )
return 0 ;
if ( ! F_22 ( V_78 , & V_27 -> V_54 ) )
return 0 ;
if ( F_22 ( V_109 , & V_27 -> V_54 ) )
return 0 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
F_28 ( V_27 , V_107 . V_25 ) ;
if ( memcmp ( V_107 . V_25 , V_27 -> V_110 , sizeof( V_107 . V_25 ) ) == 0 )
return 0 ;
memcpy ( V_27 -> V_110 , V_107 . V_25 , sizeof( V_107 . V_25 ) ) ;
return F_30 ( V_27 , V_111 , sizeof( V_107 ) , & V_107 ) ;
}
static T_1 F_31 ( struct V_26 * V_27 )
{
struct V_88 * V_89 ;
T_1 V_81 = 0 ;
F_21 (uuid, &hdev->uuids, list)
V_81 |= V_89 -> V_112 ;
return V_81 ;
}
static int F_32 ( struct V_26 * V_27 )
{
T_1 V_113 [ 3 ] ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
if ( ! F_25 ( V_27 ) )
return 0 ;
if ( F_22 ( V_109 , & V_27 -> V_54 ) )
return 0 ;
V_113 [ 0 ] = V_27 -> V_115 ;
V_113 [ 1 ] = V_27 -> V_116 ;
V_113 [ 2 ] = F_31 ( V_27 ) ;
if ( memcmp ( V_113 , V_27 -> V_117 , 3 ) == 0 )
return 0 ;
V_15 = F_30 ( V_27 , V_118 , sizeof( V_113 ) , V_113 ) ;
if ( V_15 == 0 )
F_33 ( V_119 , & V_27 -> V_54 ) ;
return V_15 ;
}
static void F_34 ( struct V_120 * V_121 )
{
struct V_26 * V_27 = F_35 ( V_121 , struct V_26 ,
V_122 . V_121 ) ;
if ( ! F_36 ( V_109 , & V_27 -> V_54 ) )
return;
F_37 ( V_27 ) ;
F_29 ( V_27 ) ;
F_32 ( V_27 ) ;
F_38 ( V_27 ) ;
}
static void F_39 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
if ( F_40 ( V_123 , & V_27 -> V_54 ) )
return;
F_41 ( & V_27 -> V_122 , F_34 ) ;
F_42 ( V_75 , & V_27 -> V_54 ) ;
}
static int F_43 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_124 V_21 ;
F_4 ( L_5 , V_5 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_44 ( & V_21 . V_125 , & V_27 -> V_125 ) ;
V_21 . V_30 = V_27 -> V_126 ;
V_21 . V_127 = F_7 ( V_27 -> V_127 ) ;
V_21 . V_128 = F_45 ( F_23 ( V_27 ) ) ;
V_21 . V_129 = F_45 ( F_24 ( V_27 ) ) ;
memcpy ( V_21 . V_117 , V_27 -> V_117 , 3 ) ;
memcpy ( V_21 . V_114 , V_27 -> V_91 , sizeof( V_27 -> V_91 ) ) ;
memcpy ( V_21 . V_130 , V_27 -> V_130 , sizeof( V_27 -> V_130 ) ) ;
F_38 ( V_27 ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_131 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static void F_46 ( struct V_132 * V_7 )
{
F_47 ( V_7 -> V_5 ) ;
F_16 ( V_7 -> V_133 ) ;
F_16 ( V_7 ) ;
}
static struct V_132 * F_48 ( struct V_4 * V_5 , T_2 V_18 ,
struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_132 * V_7 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 = V_18 ;
V_7 -> V_6 = V_27 -> V_55 ;
V_7 -> V_133 = F_14 ( V_20 , V_16 ) ;
if ( ! V_7 -> V_133 ) {
F_16 ( V_7 ) ;
return NULL ;
}
if ( V_25 )
memcpy ( V_7 -> V_133 , V_25 , V_20 ) ;
V_7 -> V_5 = V_5 ;
F_49 ( V_5 ) ;
F_50 ( & V_7 -> V_134 , & V_27 -> V_135 ) ;
return V_7 ;
}
static void F_51 ( T_2 V_18 , struct V_26 * V_27 ,
void (* F_52)( struct V_132 * V_7 ,
void * V_25 ) ,
void * V_25 )
{
struct V_46 * V_47 , * V_136 ;
F_53 (p, n, &hdev->mgmt_pending) {
struct V_132 * V_7 ;
V_7 = F_54 ( V_47 , struct V_132 , V_134 ) ;
if ( V_18 > 0 && V_7 -> V_18 != V_18 )
continue;
F_52 ( V_7 , V_25 ) ;
}
}
static struct V_132 * F_55 ( T_2 V_18 , struct V_26 * V_27 )
{
struct V_132 * V_7 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 == V_18 )
return V_7 ;
}
return NULL ;
}
static void F_56 ( struct V_132 * V_7 )
{
F_57 ( & V_7 -> V_134 ) ;
F_46 ( V_7 ) ;
}
static int F_58 ( struct V_4 * V_5 , T_2 V_18 , struct V_26 * V_27 )
{
T_6 V_57 = F_45 ( F_24 ( V_27 ) ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_18 , 0 , & V_57 ,
sizeof( V_57 ) ) ;
}
static int F_59 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( F_36 ( V_138 , & V_27 -> V_54 ) ) {
F_60 ( & V_27 -> V_139 ) ;
if ( V_107 -> V_81 ) {
V_15 = F_58 ( V_5 , V_140 , V_27 ) ;
F_61 ( V_27 , 1 ) ;
goto V_141;
}
}
if ( ! ! V_107 -> V_81 == F_25 ( V_27 ) ) {
V_15 = F_58 ( V_5 , V_140 , V_27 ) ;
goto V_141;
}
if ( F_55 ( V_140 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_140 ,
V_142 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_140 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
if ( V_107 -> V_81 )
F_62 ( & V_27 -> V_143 ) ;
else
F_62 ( & V_27 -> V_139 . V_121 ) ;
V_15 = 0 ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_63 ( T_2 V_144 , struct V_26 * V_27 , void * V_25 , T_2 V_28 ,
struct V_4 * V_145 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_5 ( sizeof( * V_12 ) + V_28 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_144 ) ;
if ( V_27 )
V_12 -> V_6 = F_7 ( V_27 -> V_55 ) ;
else
V_12 -> V_6 = F_7 ( V_34 ) ;
V_12 -> V_20 = F_7 ( V_28 ) ;
if ( V_25 )
memcpy ( F_6 ( V_10 , V_28 ) , V_25 , V_28 ) ;
F_64 ( V_10 ) ;
F_65 ( V_10 , V_145 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_66 ( struct V_26 * V_27 , struct V_4 * V_146 )
{
T_6 V_14 ;
V_14 = F_45 ( F_24 ( V_27 ) ) ;
return F_63 ( V_147 , V_27 , & V_14 , sizeof( V_14 ) , V_146 ) ;
}
static int F_67 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_148 * V_107 = V_25 ;
struct V_132 * V_7 ;
T_2 V_149 ;
T_1 V_150 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
V_149 = F_68 ( V_107 -> V_149 ) ;
if ( ! V_107 -> V_81 && V_149 > 0 )
return F_3 ( V_5 , V_27 -> V_55 , V_151 ,
V_152 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) && V_149 > 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_151 ,
V_153 ) ;
goto V_141;
}
if ( F_55 ( V_151 , V_27 ) ||
F_55 ( V_154 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_151 ,
V_142 ) ;
goto V_141;
}
if ( ! F_22 ( V_73 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_151 ,
V_155 ) ;
goto V_141;
}
if ( ! F_25 ( V_27 ) ) {
bool V_156 = false ;
if ( ! ! V_107 -> V_81 != F_22 ( V_74 , & V_27 -> V_54 ) ) {
F_69 ( V_74 , & V_27 -> V_54 ) ;
V_156 = true ;
}
V_15 = F_58 ( V_5 , V_151 , V_27 ) ;
if ( V_15 < 0 )
goto V_141;
if ( V_156 )
V_15 = F_66 ( V_27 , V_5 ) ;
goto V_141;
}
if ( ! ! V_107 -> V_81 == F_22 ( V_74 , & V_27 -> V_54 ) ) {
if ( V_27 -> V_157 > 0 ) {
F_60 ( & V_27 -> V_158 ) ;
V_27 -> V_157 = 0 ;
}
if ( V_107 -> V_81 && V_149 > 0 ) {
V_27 -> V_157 = V_149 ;
F_70 ( V_27 -> V_159 , & V_27 -> V_158 ,
F_71 ( V_27 -> V_157 * 1000 ) ) ;
}
V_15 = F_58 ( V_5 , V_151 , V_27 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_151 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
V_150 = V_160 ;
if ( V_107 -> V_81 )
V_150 |= V_161 ;
else
F_60 ( & V_27 -> V_158 ) ;
V_15 = F_30 ( V_27 , V_162 , 1 , & V_150 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
if ( V_107 -> V_81 )
V_27 -> V_157 = V_149 ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_72 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
struct V_132 * V_7 ;
T_1 V_150 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
bool V_156 = false ;
if ( ! ! V_107 -> V_81 != F_22 ( V_73 , & V_27 -> V_54 ) )
V_156 = true ;
if ( V_107 -> V_81 ) {
F_33 ( V_73 , & V_27 -> V_54 ) ;
} else {
F_42 ( V_73 , & V_27 -> V_54 ) ;
F_42 ( V_74 , & V_27 -> V_54 ) ;
}
V_15 = F_58 ( V_5 , V_154 , V_27 ) ;
if ( V_15 < 0 )
goto V_141;
if ( V_156 )
V_15 = F_66 ( V_27 , V_5 ) ;
goto V_141;
}
if ( F_55 ( V_151 , V_27 ) ||
F_55 ( V_154 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_154 ,
V_142 ) ;
goto V_141;
}
if ( ! ! V_107 -> V_81 == F_22 ( V_163 , & V_27 -> V_164 ) ) {
V_15 = F_58 ( V_5 , V_154 , V_27 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_154 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
if ( V_107 -> V_81 ) {
V_150 = V_160 ;
} else {
V_150 = 0 ;
if ( F_22 ( V_165 , & V_27 -> V_164 ) &&
V_27 -> V_157 > 0 )
F_60 ( & V_27 -> V_158 ) ;
}
V_15 = F_30 ( V_27 , V_162 , 1 , & V_150 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_73 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( V_107 -> V_81 )
F_33 ( V_75 , & V_27 -> V_54 ) ;
else
F_42 ( V_75 , & V_27 -> V_54 ) ;
V_15 = F_58 ( V_5 , V_166 , V_27 ) ;
if ( V_15 < 0 )
goto V_141;
V_15 = F_66 ( V_27 , V_5 ) ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_74 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
struct V_132 * V_7 ;
T_1 V_81 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
bool V_156 = false ;
if ( ! ! V_107 -> V_81 != F_22 ( V_77 ,
& V_27 -> V_54 ) ) {
F_69 ( V_77 , & V_27 -> V_54 ) ;
V_156 = true ;
}
V_15 = F_58 ( V_5 , V_167 , V_27 ) ;
if ( V_15 < 0 )
goto V_141;
if ( V_156 )
V_15 = F_66 ( V_27 , V_5 ) ;
goto V_141;
}
if ( F_55 ( V_167 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_167 ,
V_142 ) ;
goto V_141;
}
V_81 = ! ! V_107 -> V_81 ;
if ( F_22 ( V_168 , & V_27 -> V_164 ) == V_81 ) {
V_15 = F_58 ( V_5 , V_167 , V_27 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_167 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
V_15 = F_30 ( V_27 , V_169 , sizeof( V_81 ) , & V_81 ) ;
if ( V_15 < 0 ) {
F_56 ( V_7 ) ;
goto V_141;
}
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_75 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
struct V_132 * V_7 ;
T_1 V_81 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! ( V_27 -> V_63 [ 6 ] & V_64 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_170 ,
V_171 ) ;
goto V_141;
}
V_81 = ! ! V_107 -> V_81 ;
if ( ! F_25 ( V_27 ) ) {
bool V_156 = false ;
if ( V_81 != F_22 ( V_78 , & V_27 -> V_54 ) ) {
F_69 ( V_78 , & V_27 -> V_54 ) ;
V_156 = true ;
}
V_15 = F_58 ( V_5 , V_170 , V_27 ) ;
if ( V_15 < 0 )
goto V_141;
if ( V_156 )
V_15 = F_66 ( V_27 , V_5 ) ;
goto V_141;
}
if ( F_55 ( V_170 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_170 ,
V_142 ) ;
goto V_141;
}
if ( F_22 ( V_78 , & V_27 -> V_54 ) == V_81 ) {
V_15 = F_58 ( V_5 , V_170 , V_27 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_170 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
V_15 = F_30 ( V_27 , V_172 , sizeof( V_81 ) , & V_81 ) ;
if ( V_15 < 0 ) {
F_56 ( V_7 ) ;
goto V_141;
}
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_76 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
if ( ! V_69 )
return F_3 ( V_5 , V_27 -> V_55 , V_173 ,
V_171 ) ;
if ( V_107 -> V_81 )
F_33 ( V_79 , & V_27 -> V_54 ) ;
else
F_42 ( V_79 , & V_27 -> V_54 ) ;
return F_58 ( V_5 , V_173 , V_27 ) ;
}
static int F_77 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
struct V_174 V_175 ;
struct V_132 * V_7 ;
int V_15 ;
T_1 V_81 , V_176 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! ( V_27 -> V_63 [ 4 ] & V_71 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_177 ,
V_171 ) ;
goto V_178;
}
V_81 = ! ! V_107 -> V_81 ;
V_176 = ! ! ( V_27 -> V_179 [ 0 ] & V_180 ) ;
if ( ! F_25 ( V_27 ) || V_81 == V_176 ) {
bool V_156 = false ;
if ( V_81 != F_22 ( V_76 , & V_27 -> V_54 ) ) {
F_69 ( V_76 , & V_27 -> V_54 ) ;
V_156 = true ;
}
V_15 = F_58 ( V_5 , V_177 , V_27 ) ;
if ( V_15 < 0 )
goto V_178;
if ( V_156 )
V_15 = F_66 ( V_27 , V_5 ) ;
goto V_178;
}
if ( F_55 ( V_177 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_177 ,
V_142 ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_177 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_178;
}
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
if ( V_81 ) {
V_175 . V_181 = V_81 ;
V_175 . V_182 = ! ! ( V_27 -> V_63 [ 6 ] & V_183 ) ;
}
V_15 = F_30 ( V_27 , V_184 , sizeof( V_175 ) ,
& V_175 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_78 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_185 * V_107 = V_25 ;
struct V_132 * V_7 ;
struct V_88 * V_89 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( F_22 ( V_119 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_186 ,
V_142 ) ;
goto V_141;
}
V_89 = F_14 ( sizeof( * V_89 ) , V_16 ) ;
if ( ! V_89 ) {
V_15 = - V_17 ;
goto V_141;
}
memcpy ( V_89 -> V_89 , V_107 -> V_89 , 16 ) ;
V_89 -> V_112 = V_107 -> V_112 ;
F_50 ( & V_89 -> V_134 , & V_27 -> V_187 ) ;
V_15 = F_32 ( V_27 ) ;
if ( V_15 < 0 )
goto V_141;
V_15 = F_29 ( V_27 ) ;
if ( V_15 < 0 )
goto V_141;
if ( ! F_22 ( V_119 , & V_27 -> V_54 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_186 , 0 ,
V_27 -> V_117 , 3 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_186 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 )
V_15 = - V_17 ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static bool F_79 ( struct V_26 * V_27 )
{
if ( ! F_25 ( V_27 ) )
return false ;
if ( ! F_40 ( V_109 , & V_27 -> V_54 ) ) {
F_80 ( & V_27 -> V_122 , V_188 ) ;
return true ;
}
return false ;
}
static int F_81 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_189 * V_107 = V_25 ;
struct V_132 * V_7 ;
struct V_46 * V_47 , * V_136 ;
T_1 V_190 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_15 , V_191 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( F_22 ( V_119 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_192 ,
V_142 ) ;
goto V_178;
}
if ( memcmp ( V_107 -> V_89 , V_190 , 16 ) == 0 ) {
V_15 = F_82 ( V_27 ) ;
if ( F_79 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_192 ,
0 , V_27 -> V_117 , 3 ) ;
goto V_178;
}
goto F_32;
}
V_191 = 0 ;
F_53 (p, n, &hdev->uuids) {
struct V_88 * V_193 = F_54 ( V_47 , struct V_88 , V_134 ) ;
if ( memcmp ( V_193 -> V_89 , V_107 -> V_89 , 16 ) != 0 )
continue;
F_57 ( & V_193 -> V_134 ) ;
V_191 ++ ;
}
if ( V_191 == 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_192 ,
V_152 ) ;
goto V_178;
}
F_32:
V_15 = F_32 ( V_27 ) ;
if ( V_15 < 0 )
goto V_178;
V_15 = F_29 ( V_27 ) ;
if ( V_15 < 0 )
goto V_178;
if ( ! F_22 ( V_119 , & V_27 -> V_54 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_192 , 0 ,
V_27 -> V_117 , 3 ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_192 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 )
V_15 = - V_17 ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_83 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_194 * V_107 = V_25 ;
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( F_22 ( V_119 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_195 ,
V_142 ) ;
goto V_178;
}
V_27 -> V_116 = V_107 -> V_196 ;
V_27 -> V_115 = V_107 -> V_197 ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_195 , 0 ,
V_27 -> V_117 , 3 ) ;
goto V_178;
}
if ( F_36 ( V_109 , & V_27 -> V_54 ) ) {
F_38 ( V_27 ) ;
F_84 ( & V_27 -> V_122 ) ;
F_37 ( V_27 ) ;
F_29 ( V_27 ) ;
}
V_15 = F_32 ( V_27 ) ;
if ( V_15 < 0 )
goto V_178;
if ( ! F_22 ( V_119 , & V_27 -> V_54 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_195 , 0 ,
V_27 -> V_117 , 3 ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_195 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 )
V_15 = - V_17 ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_85 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_198 * V_107 = V_25 ;
T_2 V_199 , V_200 ;
int V_42 ;
V_199 = F_68 ( V_107 -> V_199 ) ;
V_200 = sizeof( * V_107 ) + V_199 *
sizeof( struct V_201 ) ;
if ( V_200 != V_20 ) {
F_86 ( L_7 ,
V_20 , V_200 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_202 ,
V_152 ) ;
}
F_4 ( L_8 , V_27 -> V_114 , V_107 -> V_203 ,
V_199 ) ;
F_37 ( V_27 ) ;
F_87 ( V_27 ) ;
F_33 ( V_204 , & V_27 -> V_54 ) ;
if ( V_107 -> V_203 )
F_33 ( V_205 , & V_27 -> V_54 ) ;
else
F_42 ( V_205 , & V_27 -> V_54 ) ;
for ( V_42 = 0 ; V_42 < V_199 ; V_42 ++ ) {
struct V_201 * V_206 = & V_107 -> V_207 [ V_42 ] ;
F_88 ( V_27 , NULL , 0 , & V_206 -> V_208 . V_125 , V_206 -> V_81 ,
V_206 -> type , V_206 -> V_209 ) ;
}
F_10 ( V_5 , V_27 -> V_55 , V_202 , 0 , NULL , 0 ) ;
F_38 ( V_27 ) ;
return 0 ;
}
static int F_89 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_210 , struct V_4 * V_145 )
{
struct V_211 V_14 ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = V_210 ;
return F_63 ( V_212 , V_27 , & V_14 , sizeof( V_14 ) ,
V_145 ) ;
}
static int F_90 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_213 * V_107 = V_25 ;
struct V_214 V_21 ;
struct V_215 V_216 ;
struct V_132 * V_7 ;
struct V_217 * V_218 ;
int V_15 ;
F_37 ( V_27 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_44 ( & V_21 . V_208 . V_125 , & V_107 -> V_208 . V_125 ) ;
V_21 . V_208 . type = V_107 -> V_208 . type ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_219 ,
V_153 , & V_21 , sizeof( V_21 ) ) ;
goto V_178;
}
if ( V_107 -> V_208 . type == V_220 )
V_15 = F_91 ( V_27 , & V_107 -> V_208 . V_125 ) ;
else
V_15 = F_92 ( V_27 , & V_107 -> V_208 . V_125 ) ;
if ( V_15 < 0 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_219 ,
V_221 , & V_21 , sizeof( V_21 ) ) ;
goto V_178;
}
if ( V_107 -> V_222 ) {
if ( V_107 -> V_208 . type == V_220 )
V_218 = F_93 ( V_27 , V_223 ,
& V_107 -> V_208 . V_125 ) ;
else
V_218 = F_93 ( V_27 , V_224 ,
& V_107 -> V_208 . V_125 ) ;
} else {
V_218 = NULL ;
}
if ( ! V_218 ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_219 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
F_89 ( V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type , V_5 ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_219 , V_27 , V_107 ,
sizeof( * V_107 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_178;
}
V_216 . V_225 = F_7 ( V_218 -> V_225 ) ;
V_216 . V_226 = 0x13 ;
V_15 = F_30 ( V_27 , V_227 , sizeof( V_216 ) , & V_216 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int V_222 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_228 * V_107 = V_25 ;
struct V_215 V_216 ;
struct V_132 * V_7 ;
struct V_217 * V_218 ;
int V_15 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
if ( ! F_22 ( V_229 , & V_27 -> V_164 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_230 ,
V_153 ) ;
goto V_141;
}
if ( F_55 ( V_230 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_230 ,
V_142 ) ;
goto V_141;
}
if ( V_107 -> V_208 . type == V_220 )
V_218 = F_93 ( V_27 , V_223 ,
& V_107 -> V_208 . V_125 ) ;
else
V_218 = F_93 ( V_27 , V_224 , & V_107 -> V_208 . V_125 ) ;
if ( ! V_218 || V_218 -> V_231 == V_232 || V_218 -> V_231 == V_233 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_230 ,
V_234 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_230 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
V_216 . V_225 = F_7 ( V_218 -> V_225 ) ;
V_216 . V_226 = V_235 ;
V_15 = F_30 ( V_27 , V_227 , sizeof( V_216 ) , & V_216 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static T_1 F_94 ( T_1 V_236 , T_1 V_210 )
{
switch ( V_236 ) {
case V_224 :
switch ( V_210 ) {
case V_237 :
return V_238 ;
default:
return V_239 ;
}
default:
return V_220 ;
}
}
static int F_95 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_240 * V_21 ;
struct V_217 * V_241 ;
T_3 V_22 ;
int V_15 ;
T_2 V_42 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_242 ,
V_153 ) ;
goto V_178;
}
V_42 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_243 , & V_241 -> V_164 ) )
V_42 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_244 ) ) ;
V_21 = F_14 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
V_15 = - V_17 ;
goto V_178;
}
V_42 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_243 , & V_241 -> V_164 ) )
continue;
F_44 ( & V_21 -> V_208 [ V_42 ] . V_125 , & V_241 -> V_245 ) ;
V_21 -> V_208 [ V_42 ] . type = F_94 ( V_241 -> type , V_241 -> V_246 ) ;
if ( V_241 -> type == V_247 || V_241 -> type == V_248 )
continue;
V_42 ++ ;
}
V_21 -> V_249 = F_7 ( V_42 ) ;
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_244 ) ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_242 , 0 , V_21 ,
V_22 ) ;
F_16 ( V_21 ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_96 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_250 * V_107 )
{
struct V_132 * V_7 ;
int V_15 ;
V_7 = F_48 ( V_5 , V_251 , V_27 , V_107 ,
sizeof( * V_107 ) ) ;
if ( ! V_7 )
return - V_17 ;
V_15 = F_30 ( V_27 , V_252 ,
sizeof( V_107 -> V_208 . V_125 ) , & V_107 -> V_208 . V_125 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
return V_15 ;
}
static int F_97 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_217 * V_218 ;
struct V_253 * V_107 = V_25 ;
struct V_254 V_255 ;
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_256 ,
V_153 ) ;
goto V_141;
}
V_218 = F_93 ( V_27 , V_223 , & V_107 -> V_208 . V_125 ) ;
if ( ! V_218 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_256 ,
V_234 ) ;
goto V_141;
}
if ( V_218 -> V_257 == V_258 && V_107 -> V_209 != 16 ) {
struct V_250 V_259 ;
memcpy ( & V_259 . V_208 , & V_107 -> V_208 , sizeof( V_259 . V_208 ) ) ;
F_86 ( L_10 ) ;
V_15 = F_96 ( V_5 , V_27 , & V_259 ) ;
if ( V_15 >= 0 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_256 ,
V_152 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_256 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
F_44 ( & V_255 . V_125 , & V_107 -> V_208 . V_125 ) ;
V_255 . V_209 = V_107 -> V_209 ;
memcpy ( V_255 . V_260 , V_107 -> V_260 , sizeof( V_255 . V_260 ) ) ;
V_15 = F_30 ( V_27 , V_261 , sizeof( V_255 ) , & V_255 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_98 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_262 * V_107 = V_25 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
V_27 -> V_263 = V_107 -> V_263 ;
F_4 ( L_11 , V_27 -> V_114 ,
V_27 -> V_263 ) ;
F_38 ( V_27 ) ;
return F_10 ( V_5 , V_27 -> V_55 , V_264 , 0 , NULL ,
0 ) ;
}
static struct V_132 * F_99 ( struct V_217 * V_218 )
{
struct V_26 * V_27 = V_218 -> V_27 ;
struct V_132 * V_7 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 != V_265 )
continue;
if ( V_7 -> V_266 != V_218 )
continue;
return V_7 ;
}
return NULL ;
}
static void F_100 ( struct V_132 * V_7 , T_1 V_8 )
{
struct V_267 V_21 ;
struct V_217 * V_218 = V_7 -> V_266 ;
F_44 ( & V_21 . V_208 . V_125 , & V_218 -> V_245 ) ;
V_21 . V_208 . type = F_94 ( V_218 -> type , V_218 -> V_246 ) ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_265 , V_8 ,
& V_21 , sizeof( V_21 ) ) ;
V_218 -> V_268 = NULL ;
V_218 -> V_269 = NULL ;
V_218 -> V_270 = NULL ;
F_101 ( V_218 ) ;
F_56 ( V_7 ) ;
}
static void F_102 ( struct V_217 * V_218 , T_1 V_8 )
{
struct V_132 * V_7 ;
F_4 ( L_12 , V_8 ) ;
V_7 = F_99 ( V_218 ) ;
if ( ! V_7 )
F_4 ( L_13 ) ;
else
F_100 ( V_7 , F_1 ( V_8 ) ) ;
}
static void F_103 ( struct V_217 * V_218 , T_1 V_8 )
{
struct V_132 * V_7 ;
F_4 ( L_12 , V_8 ) ;
if ( ! V_8 )
return;
V_7 = F_99 ( V_218 ) ;
if ( ! V_7 )
F_4 ( L_13 ) ;
else
F_100 ( V_7 , F_1 ( V_8 ) ) ;
}
static int F_104 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_271 * V_107 = V_25 ;
struct V_267 V_21 ;
struct V_132 * V_7 ;
T_1 V_272 , V_273 ;
struct V_217 * V_218 ;
int V_15 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_265 ,
V_153 ) ;
goto V_178;
}
V_272 = V_274 ;
if ( V_107 -> V_275 == 0x03 )
V_273 = V_276 ;
else
V_273 = V_277 ;
if ( V_107 -> V_208 . type == V_220 )
V_218 = F_105 ( V_27 , V_223 , & V_107 -> V_208 . V_125 ,
V_107 -> V_208 . type , V_272 , V_273 ) ;
else
V_218 = F_105 ( V_27 , V_224 , & V_107 -> V_208 . V_125 ,
V_107 -> V_208 . type , V_272 , V_273 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_44 ( & V_21 . V_208 . V_125 , & V_107 -> V_208 . V_125 ) ;
V_21 . V_208 . type = V_107 -> V_208 . type ;
if ( F_106 ( V_218 ) ) {
int V_8 ;
if ( F_107 ( V_218 ) == - V_278 )
V_8 = V_142 ;
else
V_8 = V_279 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_265 ,
V_8 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_178;
}
if ( V_218 -> V_268 ) {
F_101 ( V_218 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_265 ,
V_142 , & V_21 , sizeof( V_21 ) ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_265 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
F_101 ( V_218 ) ;
goto V_178;
}
if ( V_107 -> V_208 . type == V_220 )
V_218 -> V_268 = F_102 ;
else
V_218 -> V_268 = F_103 ;
V_218 -> V_269 = F_102 ;
V_218 -> V_270 = F_102 ;
V_218 -> V_263 = V_107 -> V_275 ;
V_7 -> V_266 = V_218 ;
if ( V_218 -> V_231 == V_280 &&
F_108 ( V_218 , V_272 , V_273 ) )
F_100 ( V_7 , 0 ) ;
V_15 = 0 ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_109 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_244 * V_208 = V_25 ;
struct V_132 * V_7 ;
struct V_217 * V_218 ;
int V_15 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_281 ,
V_153 ) ;
goto V_178;
}
V_7 = F_55 ( V_265 , V_27 ) ;
if ( ! V_7 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_281 ,
V_152 ) ;
goto V_178;
}
V_218 = V_7 -> V_266 ;
if ( F_110 ( & V_208 -> V_125 , & V_218 -> V_245 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_281 ,
V_152 ) ;
goto V_178;
}
F_100 ( V_7 , V_282 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_281 , 0 ,
V_208 , sizeof( * V_208 ) ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_111 ( struct V_4 * V_5 , struct V_26 * V_27 ,
T_7 * V_125 , T_1 type , T_2 V_283 ,
T_2 V_284 , T_6 V_285 )
{
struct V_132 * V_7 ;
struct V_217 * V_218 ;
int V_15 ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_283 ,
V_153 ) ;
goto V_286;
}
if ( type == V_220 )
V_218 = F_93 ( V_27 , V_223 , V_125 ) ;
else
V_218 = F_93 ( V_27 , V_224 , V_125 ) ;
if ( ! V_218 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_283 ,
V_234 ) ;
goto V_286;
}
if ( type == V_238 || type == V_239 ) {
V_15 = F_112 ( V_218 , V_283 , V_285 ) ;
if ( ! V_15 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_283 ,
V_287 ) ;
else
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_283 ,
V_3 ) ;
goto V_286;
}
V_7 = F_48 ( V_5 , V_283 , V_27 , V_125 , sizeof( * V_125 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_286;
}
if ( V_284 == V_288 ) {
struct V_289 V_107 ;
F_44 ( & V_107 . V_125 , V_125 ) ;
V_107 . V_285 = V_285 ;
V_15 = F_30 ( V_27 , V_284 , sizeof( V_107 ) , & V_107 ) ;
} else
V_15 = F_30 ( V_27 , V_284 , sizeof( * V_125 ) , V_125 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_286:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_113 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_250 * V_107 = V_25 ;
F_4 ( L_9 ) ;
return F_111 ( V_5 , V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ,
V_251 ,
V_252 , 0 ) ;
}
static int F_114 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_290 * V_107 = V_25 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_107 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_291 ,
V_152 ) ;
return F_111 ( V_5 , V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ,
V_291 ,
V_292 , 0 ) ;
}
static int F_115 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_293 * V_107 = V_25 ;
F_4 ( L_9 ) ;
return F_111 ( V_5 , V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ,
V_294 ,
V_295 , 0 ) ;
}
static int F_116 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_296 * V_107 = V_25 ;
F_4 ( L_9 ) ;
return F_111 ( V_5 , V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ,
V_297 ,
V_288 , V_107 -> V_285 ) ;
}
static int F_117 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_298 * V_107 = V_25 ;
F_4 ( L_9 ) ;
return F_111 ( V_5 , V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ,
V_299 ,
V_300 , 0 ) ;
}
static int F_118 ( struct V_26 * V_27 , const char * V_114 )
{
struct V_301 V_107 ;
memcpy ( V_107 . V_114 , V_114 , sizeof( V_107 . V_114 ) ) ;
return F_30 ( V_27 , V_302 , sizeof( V_107 ) , & V_107 ) ;
}
static int F_119 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_303 * V_107 = V_25 ;
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_9 ) ;
F_37 ( V_27 ) ;
memcpy ( V_27 -> V_130 , V_107 -> V_130 , sizeof( V_27 -> V_130 ) ) ;
if ( ! F_25 ( V_27 ) ) {
memcpy ( V_27 -> V_91 , V_107 -> V_114 , sizeof( V_27 -> V_91 ) ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_304 , 0 ,
V_25 , V_20 ) ;
if ( V_15 < 0 )
goto V_141;
V_15 = F_63 ( V_305 , V_27 , V_25 , V_20 ,
V_5 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_304 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
V_15 = F_118 ( V_27 , V_107 -> V_114 ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_120 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_306 ,
V_153 ) ;
goto V_178;
}
if ( ! ( V_27 -> V_63 [ 6 ] & V_64 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_306 ,
V_171 ) ;
goto V_178;
}
if ( F_55 ( V_306 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_306 ,
V_142 ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_306 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_178;
}
V_15 = F_30 ( V_27 , V_307 , 0 , NULL ) ;
if ( V_15 < 0 )
F_56 ( V_7 ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_121 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_308 * V_107 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_14 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_309 ,
V_153 , & V_107 -> V_208 ,
sizeof( V_107 -> V_208 ) ) ;
goto V_178;
}
V_15 = F_122 ( V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_310 ,
V_107 -> V_311 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = 0 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_309 , V_8 ,
& V_107 -> V_208 , sizeof( V_107 -> V_208 ) ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_123 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_312 * V_107 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 ,
V_313 ,
V_153 , & V_107 -> V_208 ,
sizeof( V_107 -> V_208 ) ) ;
goto V_178;
}
V_15 = F_124 ( V_27 , & V_107 -> V_208 . V_125 ) ;
if ( V_15 < 0 )
V_8 = V_152 ;
else
V_8 = 0 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_313 ,
V_8 , & V_107 -> V_208 , sizeof( V_107 -> V_208 ) ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
int F_125 ( struct V_26 * V_27 )
{
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
V_15 = F_126 ( V_27 , V_314 ) ;
if ( V_15 < 0 )
F_127 ( V_27 , V_315 ) ;
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_128 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_316 * V_107 = V_25 ;
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_25 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_317 ,
V_153 ) ;
goto V_141;
}
if ( F_22 ( V_318 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_317 ,
V_142 ) ;
goto V_141;
}
if ( V_27 -> V_319 . V_231 != V_315 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_317 ,
V_142 ) ;
goto V_141;
}
V_7 = F_48 ( V_5 , V_317 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_141;
}
V_27 -> V_319 . type = V_107 -> type ;
switch ( V_27 -> V_319 . type ) {
case V_320 :
if ( F_129 ( V_27 ) )
V_15 = F_126 ( V_27 , V_321 ) ;
else
V_15 = - V_322 ;
break;
case V_323 :
if ( F_130 ( V_27 ) )
V_15 = F_131 ( V_27 , V_324 , V_325 ,
V_326 , V_327 ) ;
else
V_15 = - V_322 ;
break;
case V_328 :
if ( F_130 ( V_27 ) && F_129 ( V_27 ) )
V_15 = F_131 ( V_27 , V_324 , V_325 ,
V_326 ,
V_329 ) ;
else
V_15 = - V_322 ;
break;
default:
V_15 = - V_330 ;
}
if ( V_15 < 0 )
F_56 ( V_7 ) ;
else
F_127 ( V_27 , V_331 ) ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_132 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_332 * V_333 = V_25 ;
struct V_132 * V_7 ;
struct V_334 V_107 ;
struct V_335 * V_336 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_133 ( V_27 ) ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_337 ,
V_155 , & V_333 -> type ,
sizeof( V_333 -> type ) ) ;
goto V_178;
}
if ( V_27 -> V_319 . type != V_333 -> type ) {
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_337 ,
V_152 , & V_333 -> type ,
sizeof( V_333 -> type ) ) ;
goto V_178;
}
V_7 = F_48 ( V_5 , V_337 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_178;
}
switch ( V_27 -> V_319 . V_231 ) {
case V_338 :
if ( F_22 ( V_339 , & V_27 -> V_164 ) )
V_15 = F_134 ( V_27 ) ;
else
V_15 = F_135 ( V_27 ) ;
break;
case V_340 :
V_336 = F_136 ( V_27 , V_341 ,
V_342 ) ;
if ( ! V_336 ) {
F_56 ( V_7 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 ,
V_337 , 0 ,
& V_333 -> type ,
sizeof( V_333 -> type ) ) ;
F_127 ( V_27 , V_315 ) ;
goto V_178;
}
F_44 ( & V_107 . V_125 , & V_336 -> V_25 . V_125 ) ;
V_15 = F_30 ( V_27 , V_343 ,
sizeof( V_107 ) , & V_107 ) ;
break;
default:
F_4 ( L_15 , V_27 -> V_319 . V_231 ) ;
V_15 = - V_344 ;
}
if ( V_15 < 0 )
F_56 ( V_7 ) ;
else
F_127 ( V_27 , V_345 ) ;
V_178:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_137 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_346 * V_107 = V_25 ;
struct V_335 * V_336 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
if ( ! F_133 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_347 ,
V_3 ) ;
goto V_141;
}
V_336 = F_138 ( V_27 , & V_107 -> V_208 . V_125 ) ;
if ( ! V_336 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_347 ,
V_152 ) ;
goto V_141;
}
if ( V_107 -> V_348 ) {
V_336 -> V_349 = V_350 ;
F_57 ( & V_336 -> V_134 ) ;
} else {
V_336 -> V_349 = V_351 ;
F_139 ( V_27 , V_336 ) ;
}
V_15 = 0 ;
V_141:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_140 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_352 * V_107 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
V_15 = F_141 ( V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = 0 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_353 , V_8 ,
& V_107 -> V_208 , sizeof( V_107 -> V_208 ) ) ;
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_142 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_354 * V_107 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_37 ( V_27 ) ;
V_15 = F_143 ( V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type ) ;
if ( V_15 < 0 )
V_8 = V_152 ;
else
V_8 = 0 ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_355 , V_8 ,
& V_107 -> V_208 , sizeof( V_107 -> V_208 ) ) ;
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_144 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_356 * V_107 = V_25 ;
int V_15 ;
T_8 V_357 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
V_357 = F_68 ( V_107 -> V_357 ) ;
if ( V_357 > 0x0002 )
return F_3 ( V_5 , V_27 -> V_55 , V_358 ,
V_152 ) ;
F_37 ( V_27 ) ;
V_27 -> V_96 = V_357 ;
V_27 -> V_98 = F_68 ( V_107 -> V_359 ) ;
V_27 -> V_99 = F_68 ( V_107 -> V_360 ) ;
V_27 -> V_100 = F_68 ( V_107 -> V_30 ) ;
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_358 , 0 , NULL , 0 ) ;
F_29 ( V_27 ) ;
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_145 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_137 * V_107 = V_25 ;
struct V_361 V_362 ;
T_1 type ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
if ( ! F_25 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_363 ,
V_153 ) ;
if ( ! F_22 ( V_73 , & V_27 -> V_54 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_363 ,
V_155 ) ;
F_37 ( V_27 ) ;
if ( V_107 -> V_81 ) {
type = V_364 ;
V_362 . V_365 = F_12 ( 0x0100 ) ;
} else {
type = V_366 ;
V_362 . V_365 = F_12 ( 0x0800 ) ;
}
V_362 . V_367 = F_12 ( 0x0012 ) ;
V_15 = F_30 ( V_27 , V_368 , sizeof( V_362 ) ,
& V_362 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_363 ,
V_3 ) ;
goto V_286;
}
V_15 = F_30 ( V_27 , V_369 , 1 , & type ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_363 ,
V_3 ) ;
goto V_286;
}
V_15 = F_10 ( V_5 , V_27 -> V_55 , V_363 , 0 ,
NULL , 0 ) ;
V_286:
F_38 ( V_27 ) ;
return V_15 ;
}
static int F_146 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_370 , T_2 V_20 )
{
struct V_371 * V_107 = V_370 ;
T_2 V_199 , V_200 ;
int V_42 ;
V_199 = F_68 ( V_107 -> V_199 ) ;
V_200 = sizeof( * V_107 ) + V_199 *
sizeof( struct V_372 ) ;
if ( V_200 != V_20 ) {
F_86 ( L_16 ,
V_20 , V_200 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_373 ,
V_330 ) ;
}
F_4 ( L_17 , V_27 -> V_114 , V_199 ) ;
F_37 ( V_27 ) ;
F_147 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_199 ; V_42 ++ ) {
struct V_372 * V_206 = & V_107 -> V_207 [ V_42 ] ;
T_1 type ;
if ( V_206 -> V_374 )
type = V_375 ;
else
type = V_376 ;
F_148 ( V_27 , & V_206 -> V_208 . V_125 ,
F_149 ( V_206 -> V_208 . type ) ,
type , 0 , V_206 -> V_377 , V_206 -> V_81 ,
V_206 -> V_378 , V_206 -> V_379 , V_206 -> rand ) ;
}
F_38 ( V_27 ) ;
return 0 ;
}
int F_150 ( struct V_4 * V_5 , struct V_380 * V_381 , T_3 V_382 )
{
void * V_383 ;
T_1 * V_107 ;
struct V_11 * V_12 ;
T_2 V_18 , V_6 , V_20 ;
struct V_26 * V_27 = NULL ;
const struct V_384 * V_385 ;
int V_15 ;
F_4 ( L_18 , V_382 ) ;
if ( V_382 < sizeof( * V_12 ) )
return - V_330 ;
V_383 = F_14 ( V_382 , V_16 ) ;
if ( ! V_383 )
return - V_17 ;
if ( F_151 ( V_383 , V_381 -> V_386 , V_382 ) ) {
V_15 = - V_344 ;
goto V_286;
}
V_12 = V_383 ;
V_18 = F_68 ( V_12 -> V_18 ) ;
V_6 = F_68 ( V_12 -> V_6 ) ;
V_20 = F_68 ( V_12 -> V_20 ) ;
if ( V_20 != V_382 - sizeof( * V_12 ) ) {
V_15 = - V_330 ;
goto V_286;
}
if ( V_6 != V_34 ) {
V_27 = F_152 ( V_6 ) ;
if ( ! V_27 ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_387 ) ;
goto V_286;
}
}
if ( V_18 >= F_2 ( V_388 ) ||
V_388 [ V_18 ] . V_389 == NULL ) {
F_4 ( L_19 , V_18 ) ;
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_390 ) ;
goto V_286;
}
if ( ( V_27 && V_18 < V_131 ) ||
( ! V_27 && V_18 >= V_131 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_387 ) ;
goto V_286;
}
V_385 = & V_388 [ V_18 ] ;
if ( ( V_385 -> V_391 && V_20 < V_385 -> V_28 ) ||
( ! V_385 -> V_391 && V_20 != V_385 -> V_28 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_152 ) ;
goto V_286;
}
if ( V_27 )
F_39 ( V_5 , V_27 ) ;
V_107 = V_383 + sizeof( * V_12 ) ;
V_15 = V_385 -> V_389 ( V_5 , V_27 , V_107 , V_20 ) ;
if ( V_15 < 0 )
goto V_286;
V_15 = V_382 ;
V_286:
if ( V_27 )
F_153 ( V_27 ) ;
F_16 ( V_383 ) ;
return V_15 ;
}
static void F_154 ( struct V_132 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , * V_8 ) ;
F_56 ( V_7 ) ;
}
int F_155 ( struct V_26 * V_27 )
{
return F_63 ( V_392 , V_27 , NULL , 0 , NULL ) ;
}
int F_156 ( struct V_26 * V_27 )
{
T_1 V_8 = V_387 ;
F_51 ( 0 , V_27 , F_154 , & V_8 ) ;
return F_63 ( V_393 , V_27 , NULL , 0 , NULL ) ;
}
static void F_157 ( struct V_132 * V_7 , void * V_25 )
{
struct V_394 * V_193 = V_25 ;
F_58 ( V_7 -> V_5 , V_7 -> V_18 , V_193 -> V_27 ) ;
F_57 ( & V_7 -> V_134 ) ;
if ( V_193 -> V_5 == NULL ) {
V_193 -> V_5 = V_7 -> V_5 ;
F_49 ( V_193 -> V_5 ) ;
}
F_46 ( V_7 ) ;
}
int F_61 ( struct V_26 * V_27 , T_1 V_395 )
{
struct V_394 V_193 = { NULL , V_27 } ;
int V_15 ;
if ( ! F_22 ( V_123 , & V_27 -> V_54 ) )
return 0 ;
F_51 ( V_140 , V_27 , F_157 , & V_193 ) ;
if ( V_395 ) {
T_1 V_150 = 0 ;
if ( F_22 ( V_73 , & V_27 -> V_54 ) )
V_150 |= V_160 ;
if ( F_22 ( V_74 , & V_27 -> V_54 ) )
V_150 |= V_161 ;
if ( V_150 )
F_30 ( V_27 , V_162 , 1 , & V_150 ) ;
if ( F_22 ( V_78 , & V_27 -> V_54 ) ) {
T_1 V_396 = 1 ;
F_30 ( V_27 , V_172 , 1 , & V_396 ) ;
}
if ( F_22 ( V_76 , & V_27 -> V_54 ) ) {
struct V_174 V_107 ;
V_107 . V_181 = 1 ;
V_107 . V_182 = ! ! ( V_27 -> V_63 [ 6 ] & V_183 ) ;
F_30 ( V_27 , V_184 ,
sizeof( V_107 ) , & V_107 ) ;
}
F_32 ( V_27 ) ;
F_118 ( V_27 , V_27 -> V_91 ) ;
F_29 ( V_27 ) ;
} else {
T_1 V_8 = V_153 ;
F_51 ( 0 , V_27 , F_154 , & V_8 ) ;
}
V_15 = F_66 ( V_27 , V_193 . V_5 ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
return V_15 ;
}
int F_158 ( struct V_26 * V_27 , T_1 V_397 )
{
struct V_394 V_193 = { NULL , V_27 } ;
bool V_156 = false ;
int V_15 = 0 ;
if ( V_397 ) {
if ( ! F_40 ( V_74 , & V_27 -> V_54 ) )
V_156 = true ;
} else {
if ( F_36 ( V_74 , & V_27 -> V_54 ) )
V_156 = true ;
}
F_51 ( V_151 , V_27 , F_157 ,
& V_193 ) ;
if ( V_156 )
V_15 = F_66 ( V_27 , V_193 . V_5 ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
return V_15 ;
}
int F_159 ( struct V_26 * V_27 , T_1 V_398 )
{
struct V_394 V_193 = { NULL , V_27 } ;
bool V_156 = false ;
int V_15 = 0 ;
if ( V_398 ) {
if ( ! F_40 ( V_73 , & V_27 -> V_54 ) )
V_156 = true ;
} else {
if ( F_36 ( V_73 , & V_27 -> V_54 ) )
V_156 = true ;
}
F_51 ( V_154 , V_27 , F_157 ,
& V_193 ) ;
if ( V_156 )
V_15 = F_66 ( V_27 , V_193 . V_5 ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
return V_15 ;
}
int F_160 ( struct V_26 * V_27 , T_1 V_150 , T_1 V_8 )
{
T_1 V_399 = F_1 ( V_8 ) ;
if ( V_150 & V_160 )
F_51 ( V_154 , V_27 ,
F_154 , & V_399 ) ;
if ( V_150 & V_161 )
F_51 ( V_151 , V_27 ,
F_154 , & V_399 ) ;
return 0 ;
}
int F_161 ( struct V_26 * V_27 , struct V_400 * V_206 ,
bool V_401 )
{
struct V_402 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_403 = V_401 ;
F_44 ( & V_14 . V_206 . V_208 . V_125 , & V_206 -> V_125 ) ;
V_14 . V_206 . V_208 . type = V_220 ;
V_14 . V_206 . type = V_206 -> type ;
memcpy ( V_14 . V_206 . V_81 , V_206 -> V_81 , V_404 ) ;
V_14 . V_206 . V_209 = V_206 -> V_209 ;
return F_63 ( V_405 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_162 ( struct V_26 * V_27 , struct V_406 * V_206 , T_1 V_401 )
{
struct V_407 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_403 = V_401 ;
F_44 ( & V_14 . V_206 . V_208 . V_125 , & V_206 -> V_125 ) ;
V_14 . V_206 . V_208 . type = F_94 ( V_224 , V_206 -> V_408 ) ;
V_14 . V_206 . V_377 = V_206 -> V_377 ;
V_14 . V_206 . V_378 = V_206 -> V_378 ;
V_14 . V_206 . V_379 = V_206 -> V_379 ;
if ( V_206 -> type == V_375 )
V_14 . V_206 . V_374 = 1 ;
memcpy ( V_14 . V_206 . rand , V_206 -> rand , sizeof( V_206 -> rand ) ) ;
memcpy ( V_14 . V_206 . V_81 , V_206 -> V_81 , sizeof( V_206 -> V_81 ) ) ;
return F_63 ( V_409 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_163 ( struct V_26 * V_27 , T_7 * V_125 , T_1 V_236 ,
T_1 V_210 , T_5 V_164 , T_1 * V_114 , T_1 V_90 ,
T_1 * V_117 )
{
char V_383 [ 512 ] ;
struct V_410 * V_14 = ( void * ) V_383 ;
T_2 V_84 = 0 ;
F_44 ( & V_14 -> V_208 . V_125 , V_125 ) ;
V_14 -> V_208 . type = F_94 ( V_236 , V_210 ) ;
V_14 -> V_164 = F_164 ( V_164 ) ;
if ( V_90 > 0 )
V_84 = F_165 ( V_14 -> V_110 , 0 , V_93 ,
V_114 , V_90 ) ;
if ( V_117 && memcmp ( V_117 , L_20 , 3 ) != 0 )
V_84 = F_165 ( V_14 -> V_110 , V_84 ,
V_411 , V_117 , 3 ) ;
V_14 -> V_84 = F_7 ( V_84 ) ;
return F_63 ( V_412 , V_27 , V_383 ,
sizeof( * V_14 ) + V_84 , NULL ) ;
}
static void F_166 ( struct V_132 * V_7 , void * V_25 )
{
struct V_228 * V_107 = V_7 -> V_133 ;
struct V_4 * * V_5 = V_25 ;
struct V_413 V_21 ;
F_44 ( & V_21 . V_208 . V_125 , & V_107 -> V_208 . V_125 ) ;
V_21 . V_208 . type = V_107 -> V_208 . type ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_230 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
* V_5 = V_7 -> V_5 ;
F_49 ( * V_5 ) ;
F_56 ( V_7 ) ;
}
static void F_167 ( struct V_132 * V_7 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_213 * V_107 = V_7 -> V_133 ;
struct V_214 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_44 ( & V_21 . V_208 . V_125 , & V_107 -> V_208 . V_125 ) ;
V_21 . V_208 . type = V_107 -> V_208 . type ;
F_89 ( V_27 , & V_107 -> V_208 . V_125 , V_107 -> V_208 . type , V_7 -> V_5 ) ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , 0 , & V_21 , sizeof( V_21 ) ) ;
F_56 ( V_7 ) ;
}
int F_168 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 )
{
struct V_244 V_14 ;
struct V_4 * V_5 = NULL ;
int V_15 ;
F_51 ( V_230 , V_27 , F_166 , & V_5 ) ;
F_44 ( & V_14 . V_125 , V_125 ) ;
V_14 . type = F_94 ( V_236 , V_210 ) ;
V_15 = F_63 ( V_414 , V_27 , & V_14 , sizeof( V_14 ) ,
V_5 ) ;
if ( V_5 )
F_47 ( V_5 ) ;
F_51 ( V_219 , V_27 , F_167 ,
V_27 ) ;
return V_15 ;
}
int F_169 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_1 V_8 )
{
struct V_413 V_21 ;
struct V_132 * V_7 ;
int V_15 ;
V_7 = F_55 ( V_230 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
F_44 ( & V_21 . V_208 . V_125 , V_125 ) ;
V_21 . V_208 . type = F_94 ( V_236 , V_210 ) ;
V_15 = F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_230 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_56 ( V_7 ) ;
F_51 ( V_219 , V_27 , F_167 ,
V_27 ) ;
return V_15 ;
}
int F_170 ( struct V_26 * V_27 , T_7 * V_125 , T_1 V_236 ,
T_1 V_210 , T_1 V_8 )
{
struct V_416 V_14 ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = F_94 ( V_236 , V_210 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
return F_63 ( V_417 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_171 ( struct V_26 * V_27 , T_7 * V_125 , T_1 V_418 )
{
struct V_419 V_14 ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = V_220 ;
V_14 . V_418 = V_418 ;
return F_63 ( V_420 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_172 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_8 )
{
struct V_132 * V_7 ;
struct V_421 V_21 ;
int V_15 ;
V_7 = F_55 ( V_256 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
F_44 ( & V_21 . V_208 . V_125 , V_125 ) ;
V_21 . V_208 . type = V_220 ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_256 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_56 ( V_7 ) ;
return V_15 ;
}
int F_173 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_8 )
{
struct V_132 * V_7 ;
struct V_421 V_21 ;
int V_15 ;
V_7 = F_55 ( V_251 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
F_44 ( & V_21 . V_208 . V_125 , V_125 ) ;
V_21 . V_208 . type = V_220 ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_251 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_56 ( V_7 ) ;
return V_15 ;
}
int F_174 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_6 V_422 ,
T_1 V_423 )
{
struct V_424 V_14 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = F_94 ( V_236 , V_210 ) ;
V_14 . V_423 = V_423 ;
V_14 . V_422 = V_422 ;
return F_63 ( V_425 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_175 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 )
{
struct V_426 V_14 ;
F_4 ( L_4 , V_27 -> V_114 ) ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = F_94 ( V_236 , V_210 ) ;
return F_63 ( V_427 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
static int F_176 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_1 V_8 ,
T_1 V_18 )
{
struct V_132 * V_7 ;
struct V_428 V_21 ;
int V_15 ;
V_7 = F_55 ( V_18 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
F_44 ( & V_21 . V_208 . V_125 , V_125 ) ;
V_21 . V_208 . type = F_94 ( V_236 , V_210 ) ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_18 , F_1 ( V_8 ) ,
& V_21 , sizeof( V_21 ) ) ;
F_56 ( V_7 ) ;
return V_15 ;
}
int F_177 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_1 V_8 )
{
return F_176 ( V_27 , V_125 , V_236 , V_210 ,
V_8 , V_291 ) ;
}
int F_178 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_1 V_8 )
{
return F_176 ( V_27 , V_125 , V_236 , V_210 ,
V_8 ,
V_294 ) ;
}
int F_179 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_1 V_8 )
{
return F_176 ( V_27 , V_125 , V_236 , V_210 ,
V_8 , V_297 ) ;
}
int F_180 ( struct V_26 * V_27 , T_7 * V_125 ,
T_1 V_236 , T_1 V_210 , T_1 V_8 )
{
return F_176 ( V_27 , V_125 , V_236 , V_210 ,
V_8 ,
V_299 ) ;
}
int F_181 ( struct V_26 * V_27 , T_7 * V_125 , T_1 V_236 ,
T_1 V_210 , T_1 V_8 )
{
struct V_429 V_14 ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = F_94 ( V_236 , V_210 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
return F_63 ( V_430 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_182 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_394 V_193 = { NULL , V_27 } ;
bool V_156 = false ;
int V_15 = 0 ;
if ( V_8 ) {
T_1 V_399 = F_1 ( V_8 ) ;
F_51 ( V_167 , V_27 ,
F_154 , & V_399 ) ;
return 0 ;
}
if ( F_22 ( V_168 , & V_27 -> V_164 ) ) {
if ( ! F_40 ( V_77 , & V_27 -> V_54 ) )
V_156 = true ;
} else {
if ( F_36 ( V_77 , & V_27 -> V_54 ) )
V_156 = true ;
}
F_51 ( V_167 , V_27 , F_157 ,
& V_193 ) ;
if ( V_156 )
V_15 = F_66 ( V_27 , V_193 . V_5 ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
return V_15 ;
}
static int F_183 ( struct V_26 * V_27 )
{
struct V_106 V_107 ;
if ( ! ( V_27 -> V_63 [ 6 ] & V_108 ) )
return 0 ;
memset ( V_27 -> V_110 , 0 , sizeof( V_27 -> V_110 ) ) ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
return F_30 ( V_27 , V_111 , sizeof( V_107 ) , & V_107 ) ;
}
int F_184 ( struct V_26 * V_27 , T_1 V_431 , T_1 V_8 )
{
struct V_394 V_193 = { NULL , V_27 } ;
bool V_156 = false ;
int V_15 = 0 ;
if ( V_8 ) {
T_1 V_399 = F_1 ( V_8 ) ;
if ( V_431 && F_36 ( V_78 ,
& V_27 -> V_54 ) )
V_15 = F_66 ( V_27 , NULL ) ;
F_51 ( V_170 , V_27 , F_154 ,
& V_399 ) ;
return V_15 ;
}
if ( V_431 ) {
if ( ! F_40 ( V_78 , & V_27 -> V_54 ) )
V_156 = true ;
} else {
if ( F_36 ( V_78 , & V_27 -> V_54 ) )
V_156 = true ;
}
F_51 ( V_170 , V_27 , F_157 , & V_193 ) ;
if ( V_156 )
V_15 = F_66 ( V_27 , V_193 . V_5 ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
if ( F_22 ( V_78 , & V_27 -> V_54 ) )
F_29 ( V_27 ) ;
else
F_183 ( V_27 ) ;
return V_15 ;
}
static void F_185 ( struct V_132 * V_7 , void * V_25 )
{
struct V_394 * V_193 = V_25 ;
F_10 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_193 -> F_1 ,
V_193 -> V_27 -> V_117 , 3 ) ;
F_57 ( & V_7 -> V_134 ) ;
if ( V_193 -> V_5 == NULL ) {
V_193 -> V_5 = V_7 -> V_5 ;
F_49 ( V_193 -> V_5 ) ;
}
F_46 ( V_7 ) ;
}
int F_186 ( struct V_26 * V_27 , T_1 * V_117 ,
T_1 V_8 )
{
struct V_394 V_193 = { NULL , V_27 , F_1 (status) } ;
int V_15 = 0 ;
F_42 ( V_119 , & V_27 -> V_54 ) ;
F_51 ( V_195 , V_27 , F_185 , & V_193 ) ;
F_51 ( V_186 , V_27 , F_185 , & V_193 ) ;
F_51 ( V_192 , V_27 , F_185 , & V_193 ) ;
if ( ! V_8 )
V_15 = F_63 ( V_432 , V_27 , V_117 ,
3 , NULL ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
return V_15 ;
}
int F_187 ( struct V_26 * V_27 , T_1 * V_114 , T_1 V_8 )
{
struct V_132 * V_7 ;
struct V_303 V_14 ;
bool V_156 = false ;
int V_15 = 0 ;
if ( memcmp ( V_114 , V_27 -> V_91 , sizeof( V_27 -> V_91 ) ) != 0 ) {
memcpy ( V_27 -> V_91 , V_114 , sizeof( V_27 -> V_91 ) ) ;
V_156 = true ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_114 , V_114 , V_433 ) ;
memcpy ( V_14 . V_130 , V_27 -> V_130 , V_434 ) ;
V_7 = F_55 ( V_304 , V_27 ) ;
if ( ! V_7 )
goto V_435;
V_156 = true ;
if ( V_8 ) {
V_15 = F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_304 ,
F_1 ( V_8 ) ) ;
goto V_141;
}
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_304 , 0 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
goto V_141;
V_435:
if ( V_156 )
V_15 = F_63 ( V_305 , V_27 , & V_14 ,
sizeof( V_14 ) , V_7 ? V_7 -> V_5 : NULL ) ;
F_29 ( V_27 ) ;
V_141:
if ( V_7 )
F_56 ( V_7 ) ;
return V_15 ;
}
int F_188 ( struct V_26 * V_27 , T_1 * V_310 ,
T_1 * V_311 , T_1 V_8 )
{
struct V_132 * V_7 ;
int V_15 ;
F_4 ( L_21 , V_27 -> V_114 , V_8 ) ;
V_7 = F_55 ( V_306 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
if ( V_8 ) {
V_15 = F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_306 ,
F_1 ( V_8 ) ) ;
} else {
struct V_436 V_21 ;
memcpy ( V_21 . V_310 , V_310 , sizeof( V_21 . V_310 ) ) ;
memcpy ( V_21 . V_311 , V_311 , sizeof( V_21 . V_311 ) ) ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 ,
V_306 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
F_56 ( V_7 ) ;
return V_15 ;
}
int F_189 ( struct V_26 * V_27 , T_1 V_431 , T_1 V_8 )
{
struct V_394 V_193 = { NULL , V_27 } ;
bool V_156 = false ;
int V_15 = 0 ;
if ( V_8 ) {
T_1 V_399 = F_1 ( V_8 ) ;
if ( V_431 && F_36 ( V_76 ,
& V_27 -> V_54 ) )
V_15 = F_66 ( V_27 , NULL ) ;
F_51 ( V_177 , V_27 , F_154 ,
& V_399 ) ;
return V_15 ;
}
if ( V_431 ) {
if ( ! F_40 ( V_76 , & V_27 -> V_54 ) )
V_156 = true ;
} else {
if ( F_36 ( V_76 , & V_27 -> V_54 ) )
V_156 = true ;
}
F_51 ( V_177 , V_27 , F_157 , & V_193 ) ;
if ( V_156 )
V_15 = F_66 ( V_27 , V_193 . V_5 ) ;
if ( V_193 . V_5 )
F_47 ( V_193 . V_5 ) ;
return V_15 ;
}
int F_190 ( struct V_26 * V_27 , T_7 * V_125 , T_1 V_236 ,
T_1 V_210 , T_1 * V_117 , T_9 V_437 , T_1 V_438 , T_1
V_396 , T_1 * V_110 , T_2 V_84 )
{
char V_383 [ 512 ] ;
struct V_439 * V_14 = ( void * ) V_383 ;
T_3 V_440 ;
if ( sizeof( * V_14 ) + V_84 + 5 > sizeof( V_383 ) )
return - V_330 ;
memset ( V_383 , 0 , sizeof( V_383 ) ) ;
F_44 ( & V_14 -> V_208 . V_125 , V_125 ) ;
V_14 -> V_208 . type = F_94 ( V_236 , V_210 ) ;
V_14 -> V_437 = V_437 ;
if ( V_438 )
V_14 -> V_164 |= F_45 ( V_441 ) ;
if ( ! V_396 )
V_14 -> V_164 |= F_45 ( V_442 ) ;
if ( V_84 > 0 )
memcpy ( V_14 -> V_110 , V_110 , V_84 ) ;
if ( V_117 && ! F_191 ( V_14 -> V_110 , V_84 , V_411 ) )
V_84 = F_165 ( V_14 -> V_110 , V_84 , V_411 ,
V_117 , 3 ) ;
V_14 -> V_84 = F_7 ( V_84 ) ;
V_440 = sizeof( * V_14 ) + V_84 ;
return F_63 ( V_443 , V_27 , V_14 , V_440 , NULL ) ;
}
int F_192 ( struct V_26 * V_27 , T_7 * V_125 , T_1 V_236 ,
T_1 V_210 , T_9 V_437 , T_1 * V_114 , T_1 V_90 )
{
struct V_439 * V_14 ;
char V_383 [ sizeof( * V_14 ) + V_433 + 2 ] ;
T_2 V_84 ;
V_14 = (struct V_439 * ) V_383 ;
memset ( V_383 , 0 , sizeof( V_383 ) ) ;
F_44 ( & V_14 -> V_208 . V_125 , V_125 ) ;
V_14 -> V_208 . type = F_94 ( V_236 , V_210 ) ;
V_14 -> V_437 = V_437 ;
V_84 = F_165 ( V_14 -> V_110 , 0 , V_93 , V_114 ,
V_90 ) ;
V_14 -> V_84 = F_7 ( V_84 ) ;
return F_63 ( V_443 , V_27 , V_14 ,
sizeof( * V_14 ) + V_84 , NULL ) ;
}
int F_193 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_132 * V_7 ;
T_1 type ;
int V_15 ;
F_127 ( V_27 , V_315 ) ;
V_7 = F_55 ( V_317 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
type = V_27 -> V_319 . type ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& type , sizeof( type ) ) ;
F_56 ( V_7 ) ;
return V_15 ;
}
int F_194 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_132 * V_7 ;
int V_15 ;
V_7 = F_55 ( V_337 , V_27 ) ;
if ( ! V_7 )
return - V_415 ;
V_15 = F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& V_27 -> V_319 . type , sizeof( V_27 -> V_319 . type ) ) ;
F_56 ( V_7 ) ;
return V_15 ;
}
int F_195 ( struct V_26 * V_27 , T_1 V_444 )
{
struct V_445 V_14 ;
struct V_132 * V_7 ;
F_4 ( L_22 , V_27 -> V_114 , V_444 ) ;
if ( V_444 )
V_7 = F_55 ( V_317 , V_27 ) ;
else
V_7 = F_55 ( V_337 , V_27 ) ;
if ( V_7 != NULL ) {
T_1 type = V_27 -> V_319 . type ;
F_10 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , 0 , & type ,
sizeof( type ) ) ;
F_56 ( V_7 ) ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . type = V_27 -> V_319 . type ;
V_14 . V_444 = V_444 ;
return F_63 ( V_446 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_196 ( struct V_26 * V_27 , T_7 * V_125 , T_1 type )
{
struct V_132 * V_7 ;
struct V_447 V_14 ;
V_7 = F_55 ( V_353 , V_27 ) ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = type ;
return F_63 ( V_448 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
int F_197 ( struct V_26 * V_27 , T_7 * V_125 , T_1 type )
{
struct V_132 * V_7 ;
struct V_449 V_14 ;
V_7 = F_55 ( V_355 , V_27 ) ;
F_44 ( & V_14 . V_208 . V_125 , V_125 ) ;
V_14 . V_208 . type = type ;
return F_63 ( V_450 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
