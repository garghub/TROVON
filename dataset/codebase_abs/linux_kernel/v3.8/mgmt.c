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
V_57 |= V_62 ;
V_57 |= V_63 ;
V_57 |= V_64 ;
V_57 |= V_65 ;
}
if ( V_66 )
V_57 |= V_67 ;
if ( F_26 ( V_2 ) )
V_57 |= V_68 ;
return V_57 ;
}
static T_5 F_27 ( struct V_1 * V_2 )
{
T_5 V_57 = 0 ;
if ( F_28 ( V_2 ) )
V_57 |= V_58 ;
if ( F_22 ( V_69 , & V_2 -> V_53 ) )
V_57 |= V_61 ;
if ( F_22 ( V_70 , & V_2 -> V_53 ) )
V_57 |= V_63 ;
if ( F_22 ( V_71 , & V_2 -> V_53 ) )
V_57 |= V_59 ;
if ( F_25 ( V_2 ) )
V_57 |= V_64 ;
if ( F_22 ( V_72 , & V_2 -> V_53 ) )
V_57 |= V_68 ;
if ( F_22 ( V_73 , & V_2 -> V_53 ) )
V_57 |= V_65 ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) )
V_57 |= V_60 ;
if ( F_22 ( V_75 , & V_2 -> V_53 ) )
V_57 |= V_67 ;
return V_57 ;
}
static T_2 F_29 ( T_1 * V_76 )
{
T_5 V_77 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 12 ; V_44 ++ ) {
if ( V_78 [ V_44 ] != V_76 [ V_44 ] )
return 0 ;
}
V_77 = F_30 ( & V_76 [ 12 ] ) ;
if ( V_77 > 0xffff )
return 0 ;
return ( T_2 ) V_77 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 * V_29 )
{
T_1 * V_79 = V_29 ;
T_2 V_80 = 0 ;
T_2 V_81 [ V_82 / sizeof( T_2 ) ] ;
int V_44 , V_83 = 0 ;
struct V_84 * V_85 ;
T_3 V_86 ;
V_86 = strlen ( V_2 -> V_87 ) ;
if ( V_86 > 0 ) {
if ( V_86 > 48 ) {
V_86 = 48 ;
V_79 [ 1 ] = V_88 ;
} else
V_79 [ 1 ] = V_89 ;
V_79 [ 0 ] = V_86 + 1 ;
memcpy ( V_79 + 2 , V_2 -> V_87 , V_86 ) ;
V_80 += ( V_86 + 2 ) ;
V_79 += ( V_86 + 2 ) ;
}
if ( V_2 -> V_90 != V_91 ) {
V_79 [ 0 ] = 2 ;
V_79 [ 1 ] = V_92 ;
V_79 [ 2 ] = ( T_1 ) V_2 -> V_90 ;
V_80 += 3 ;
V_79 += 3 ;
}
if ( V_2 -> V_93 > 0 ) {
V_79 [ 0 ] = 9 ;
V_79 [ 1 ] = V_94 ;
F_16 ( V_2 -> V_93 , V_79 + 2 ) ;
F_16 ( V_2 -> V_95 , V_79 + 4 ) ;
F_16 ( V_2 -> V_96 , V_79 + 6 ) ;
F_16 ( V_2 -> V_97 , V_79 + 8 ) ;
V_80 += 10 ;
V_79 += 10 ;
}
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
F_20 (uuid, &hdev->uuids, list) {
T_2 V_98 ;
V_98 = F_29 ( V_85 -> V_85 ) ;
if ( V_98 == 0 )
return;
if ( V_98 < 0x1100 )
continue;
if ( V_98 == V_99 )
continue;
if ( V_80 + 2 + sizeof( T_2 ) > V_82 ) {
V_83 = 1 ;
break;
}
for ( V_44 = 0 ; V_81 [ V_44 ] != 0 ; V_44 ++ )
if ( V_81 [ V_44 ] == V_98 )
break;
if ( V_81 [ V_44 ] == 0 ) {
V_81 [ V_44 ] = V_98 ;
V_80 += sizeof( T_2 ) ;
}
}
if ( V_81 [ 0 ] != 0 ) {
T_1 * V_100 = V_79 ;
V_79 [ 1 ] = V_83 ? V_101 : V_102 ;
V_79 += 2 ;
V_80 += 2 ;
for ( V_44 = 0 ; V_81 [ V_44 ] != 0 ; V_44 ++ ) {
* V_79 ++ = ( V_81 [ V_44 ] & 0x00ff ) ;
* V_79 ++ = ( V_81 [ V_44 ] & 0xff00 ) >> 8 ;
}
* V_100 = ( V_44 * sizeof( T_2 ) ) + 1 ;
}
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_103 V_104 ;
if ( ! F_28 ( V_2 ) )
return 0 ;
if ( ! F_33 ( V_2 ) )
return 0 ;
if ( ! F_22 ( V_74 , & V_2 -> V_53 ) )
return 0 ;
if ( F_22 ( V_105 , & V_2 -> V_53 ) )
return 0 ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
F_31 ( V_2 , V_104 . V_29 ) ;
if ( memcmp ( V_104 . V_29 , V_2 -> V_106 , sizeof( V_104 . V_29 ) ) == 0 )
return 0 ;
memcpy ( V_2 -> V_106 , V_104 . V_29 , sizeof( V_104 . V_29 ) ) ;
return F_34 ( V_2 , V_107 , sizeof( V_104 ) , & V_104 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
T_1 V_77 = 0 ;
F_20 (uuid, &hdev->uuids, list)
V_77 |= V_85 -> V_108 ;
return V_77 ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_109 [ 3 ] ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
if ( ! F_28 ( V_2 ) )
return 0 ;
if ( F_22 ( V_105 , & V_2 -> V_53 ) )
return 0 ;
V_109 [ 0 ] = V_2 -> V_111 ;
V_109 [ 1 ] = V_2 -> V_112 ;
V_109 [ 2 ] = F_35 ( V_2 ) ;
if ( memcmp ( V_109 , V_2 -> V_113 , 3 ) == 0 )
return 0 ;
V_19 = F_34 ( V_2 , V_114 , sizeof( V_109 ) , V_109 ) ;
if ( V_19 == 0 )
F_37 ( V_115 , & V_2 -> V_53 ) ;
return V_19 ;
}
static void F_38 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_39 ( V_117 , struct V_1 ,
V_118 . V_117 ) ;
if ( ! F_40 ( V_105 , & V_2 -> V_53 ) )
return;
F_41 ( V_2 ) ;
F_32 ( V_2 ) ;
F_36 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_44 ( V_119 , & V_2 -> V_53 ) )
return;
F_45 ( & V_2 -> V_118 , F_38 ) ;
F_46 ( V_71 , & V_2 -> V_53 ) ;
}
static int F_47 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_120 V_25 ;
F_5 ( L_5 , V_9 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_48 ( & V_25 . V_121 , & V_2 -> V_121 ) ;
V_25 . V_32 = V_2 -> V_122 ;
V_25 . V_123 = F_9 ( V_2 -> V_123 ) ;
V_25 . V_124 = F_49 ( F_23 ( V_2 ) ) ;
V_25 . V_125 = F_49 ( F_27 ( V_2 ) ) ;
memcpy ( V_25 . V_113 , V_2 -> V_113 , 3 ) ;
memcpy ( V_25 . V_110 , V_2 -> V_87 , sizeof( V_2 -> V_87 ) ) ;
memcpy ( V_25 . V_126 , V_2 -> V_126 , sizeof( V_2 -> V_126 ) ) ;
F_42 ( V_2 ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_127 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
static void F_50 ( struct V_128 * V_11 )
{
F_51 ( V_11 -> V_9 ) ;
F_17 ( V_11 -> V_129 ) ;
F_17 ( V_11 ) ;
}
static struct V_128 * F_52 ( struct V_8 * V_9 , T_2 V_22 ,
struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_128 * V_11 ;
V_11 = F_15 ( sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_22 = V_22 ;
V_11 -> V_10 = V_2 -> V_54 ;
V_11 -> V_129 = F_15 ( V_24 , V_20 ) ;
if ( ! V_11 -> V_129 ) {
F_17 ( V_11 ) ;
return NULL ;
}
if ( V_29 )
memcpy ( V_11 -> V_129 , V_29 , V_24 ) ;
V_11 -> V_9 = V_9 ;
F_53 ( V_9 ) ;
F_54 ( & V_11 -> V_130 , & V_2 -> V_131 ) ;
return V_11 ;
}
static void F_55 ( T_2 V_22 , struct V_1 * V_2 ,
void (* F_56)( struct V_128 * V_11 ,
void * V_29 ) ,
void * V_29 )
{
struct V_132 * V_133 , * V_134 ;
F_57 (p, n, &hdev->mgmt_pending) {
struct V_128 * V_11 ;
V_11 = F_58 ( V_133 , struct V_128 , V_130 ) ;
if ( V_22 > 0 && V_11 -> V_22 != V_22 )
continue;
F_56 ( V_11 , V_29 ) ;
}
}
static struct V_128 * F_59 ( T_2 V_22 , struct V_1 * V_2 )
{
struct V_128 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 == V_22 )
return V_11 ;
}
return NULL ;
}
static void F_60 ( struct V_128 * V_11 )
{
F_61 ( & V_11 -> V_130 ) ;
F_50 ( V_11 ) ;
}
static int F_62 ( struct V_8 * V_9 , T_2 V_22 , struct V_1 * V_2 )
{
T_6 V_57 = F_49 ( F_27 ( V_2 ) ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_22 , 0 , & V_57 ,
sizeof( V_57 ) ) ;
}
static int F_63 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( F_40 ( V_136 , & V_2 -> V_53 ) ) {
F_64 ( & V_2 -> V_137 ) ;
if ( V_104 -> V_77 ) {
V_19 = F_62 ( V_9 , V_138 , V_2 ) ;
F_65 ( V_2 , 1 ) ;
goto V_139;
}
}
if ( ! ! V_104 -> V_77 == F_28 ( V_2 ) ) {
V_19 = F_62 ( V_9 , V_138 , V_2 ) ;
goto V_139;
}
if ( F_59 ( V_138 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_138 ,
V_140 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_138 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
if ( V_104 -> V_77 )
F_66 ( & V_2 -> V_141 ) ;
else
F_66 ( & V_2 -> V_137 . V_117 ) ;
V_19 = 0 ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_67 ( T_2 V_142 , struct V_1 * V_2 , void * V_29 , T_2 V_30 ,
struct V_8 * V_143 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_14 = F_6 ( sizeof( * V_16 ) + V_30 , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_16 = ( void * ) F_7 ( V_14 , sizeof( * V_16 ) ) ;
V_16 -> V_22 = F_9 ( V_142 ) ;
if ( V_2 )
V_16 -> V_10 = F_9 ( V_2 -> V_54 ) ;
else
V_16 -> V_10 = F_8 ( V_36 ) ;
V_16 -> V_24 = F_9 ( V_30 ) ;
if ( V_29 )
memcpy ( F_7 ( V_14 , V_30 ) , V_29 , V_30 ) ;
F_68 ( V_14 ) ;
F_69 ( V_14 , V_143 ) ;
F_11 ( V_14 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_8 * V_144 )
{
T_6 V_18 ;
V_18 = F_49 ( F_27 ( V_2 ) ) ;
return F_67 ( V_145 , V_2 , & V_18 , sizeof( V_18 ) , V_144 ) ;
}
static int F_71 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_146 * V_104 = V_29 ;
struct V_128 * V_11 ;
T_2 V_147 ;
T_1 V_148 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_150 ) ;
V_147 = F_72 ( V_104 -> V_147 ) ;
if ( ! V_104 -> V_77 && V_147 > 0 )
return F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_151 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) && V_147 > 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_152 ) ;
goto V_139;
}
if ( F_59 ( V_149 , V_2 ) ||
F_59 ( V_153 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_140 ) ;
goto V_139;
}
if ( ! F_22 ( V_69 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_154 ) ;
goto V_139;
}
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( ! ! V_104 -> V_77 != F_22 ( V_70 , & V_2 -> V_53 ) ) {
F_73 ( V_70 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_62 ( V_9 , V_149 , V_2 ) ;
if ( V_19 < 0 )
goto V_139;
if ( V_155 )
V_19 = F_70 ( V_2 , V_9 ) ;
goto V_139;
}
if ( ! ! V_104 -> V_77 == F_22 ( V_70 , & V_2 -> V_53 ) ) {
if ( V_2 -> V_156 > 0 ) {
F_64 ( & V_2 -> V_157 ) ;
V_2 -> V_156 = 0 ;
}
if ( V_104 -> V_77 && V_147 > 0 ) {
V_2 -> V_156 = V_147 ;
F_74 ( V_2 -> V_158 , & V_2 -> V_157 ,
F_75 ( V_2 -> V_156 * 1000 ) ) ;
}
V_19 = F_62 ( V_9 , V_149 , V_2 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_149 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
V_148 = V_159 ;
if ( V_104 -> V_77 )
V_148 |= V_160 ;
else
F_64 ( & V_2 -> V_157 ) ;
V_19 = F_34 ( V_2 , V_161 , 1 , & V_148 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
if ( V_104 -> V_77 )
V_2 -> V_156 = V_147 ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_76 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
struct V_128 * V_11 ;
T_1 V_148 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_153 ,
V_150 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( ! ! V_104 -> V_77 != F_22 ( V_69 , & V_2 -> V_53 ) )
V_155 = true ;
if ( V_104 -> V_77 ) {
F_37 ( V_69 , & V_2 -> V_53 ) ;
} else {
F_46 ( V_69 , & V_2 -> V_53 ) ;
F_46 ( V_70 , & V_2 -> V_53 ) ;
}
V_19 = F_62 ( V_9 , V_153 , V_2 ) ;
if ( V_19 < 0 )
goto V_139;
if ( V_155 )
V_19 = F_70 ( V_2 , V_9 ) ;
goto V_139;
}
if ( F_59 ( V_149 , V_2 ) ||
F_59 ( V_153 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_153 ,
V_140 ) ;
goto V_139;
}
if ( ! ! V_104 -> V_77 == F_22 ( V_162 , & V_2 -> V_163 ) ) {
V_19 = F_62 ( V_9 , V_153 , V_2 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_153 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
if ( V_104 -> V_77 ) {
V_148 = V_159 ;
} else {
V_148 = 0 ;
if ( F_22 ( V_164 , & V_2 -> V_163 ) &&
V_2 -> V_156 > 0 )
F_64 ( & V_2 -> V_157 ) ;
}
V_19 = F_34 ( V_2 , V_161 , 1 , & V_148 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_77 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( V_104 -> V_77 )
F_37 ( V_71 , & V_2 -> V_53 ) ;
else
F_46 ( V_71 , & V_2 -> V_53 ) ;
V_19 = F_62 ( V_9 , V_165 , V_2 ) ;
if ( V_19 < 0 )
goto V_139;
V_19 = F_70 ( V_2 , V_9 ) ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_78 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
struct V_128 * V_11 ;
T_1 V_77 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_166 ,
V_150 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( ! ! V_104 -> V_77 != F_22 ( V_73 ,
& V_2 -> V_53 ) ) {
F_73 ( V_73 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_62 ( V_9 , V_166 , V_2 ) ;
if ( V_19 < 0 )
goto V_139;
if ( V_155 )
V_19 = F_70 ( V_2 , V_9 ) ;
goto V_139;
}
if ( F_59 ( V_166 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_166 ,
V_140 ) ;
goto V_139;
}
V_77 = ! ! V_104 -> V_77 ;
if ( F_22 ( V_167 , & V_2 -> V_163 ) == V_77 ) {
V_19 = F_62 ( V_9 , V_166 , V_2 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_166 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
V_19 = F_34 ( V_2 , V_168 , sizeof( V_77 ) , & V_77 ) ;
if ( V_19 < 0 ) {
F_60 ( V_11 ) ;
goto V_139;
}
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_79 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
struct V_128 * V_11 ;
T_1 V_77 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_24 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_169 ,
V_150 ) ;
goto V_139;
}
V_77 = ! ! V_104 -> V_77 ;
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( V_77 != F_22 ( V_74 , & V_2 -> V_53 ) ) {
F_73 ( V_74 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_62 ( V_9 , V_169 , V_2 ) ;
if ( V_19 < 0 )
goto V_139;
if ( V_155 )
V_19 = F_70 ( V_2 , V_9 ) ;
goto V_139;
}
if ( F_59 ( V_169 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_169 ,
V_140 ) ;
goto V_139;
}
if ( F_22 ( V_74 , & V_2 -> V_53 ) == V_77 ) {
V_19 = F_62 ( V_9 , V_169 , V_2 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_169 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
V_19 = F_34 ( V_2 , V_170 , sizeof( V_77 ) , & V_77 ) ;
if ( V_19 < 0 ) {
F_60 ( V_11 ) ;
goto V_139;
}
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_80 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! V_66 )
return F_4 ( V_9 , V_2 -> V_54 , V_171 ,
V_150 ) ;
if ( V_104 -> V_77 )
F_37 ( V_75 , & V_2 -> V_53 ) ;
else
F_46 ( V_75 , & V_2 -> V_53 ) ;
return F_62 ( V_9 , V_171 , V_2 ) ;
}
static int F_81 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
struct V_172 V_173 ;
struct V_128 * V_11 ;
int V_19 ;
T_1 V_77 , V_174 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_26 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_175 ,
V_150 ) ;
goto V_176;
}
V_77 = ! ! V_104 -> V_77 ;
V_174 = F_82 ( V_2 ) ;
if ( ! F_28 ( V_2 ) || V_77 == V_174 ) {
bool V_155 = false ;
if ( V_77 != F_22 ( V_72 , & V_2 -> V_53 ) ) {
F_73 ( V_72 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_62 ( V_9 , V_175 , V_2 ) ;
if ( V_19 < 0 )
goto V_176;
if ( V_155 )
V_19 = F_70 ( V_2 , V_9 ) ;
goto V_176;
}
if ( F_59 ( V_175 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_175 ,
V_140 ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_175 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
if ( V_77 ) {
V_173 . V_177 = V_77 ;
V_173 . V_178 = F_83 ( V_2 ) ;
}
V_19 = F_34 ( V_2 , V_179 , sizeof( V_173 ) ,
& V_173 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_84 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_180 * V_104 = V_29 ;
struct V_128 * V_11 ;
struct V_84 * V_85 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_181 ,
V_140 ) ;
goto V_139;
}
V_85 = F_15 ( sizeof( * V_85 ) , V_20 ) ;
if ( ! V_85 ) {
V_19 = - V_21 ;
goto V_139;
}
memcpy ( V_85 -> V_85 , V_104 -> V_85 , 16 ) ;
V_85 -> V_108 = V_104 -> V_108 ;
F_54 ( & V_85 -> V_130 , & V_2 -> V_182 ) ;
V_19 = F_36 ( V_2 ) ;
if ( V_19 < 0 )
goto V_139;
V_19 = F_32 ( V_2 ) ;
if ( V_19 < 0 )
goto V_139;
if ( ! F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_181 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_181 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static bool F_85 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 ) )
return false ;
if ( ! F_44 ( V_105 , & V_2 -> V_53 ) ) {
F_86 ( & V_2 -> V_118 , V_183 ) ;
return true ;
}
return false ;
}
static int F_87 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_184 * V_104 = V_29 ;
struct V_128 * V_11 ;
struct V_132 * V_133 , * V_134 ;
T_1 V_185 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_19 , V_186 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_187 ,
V_140 ) ;
goto V_176;
}
if ( memcmp ( V_104 -> V_85 , V_185 , 16 ) == 0 ) {
V_19 = F_88 ( V_2 ) ;
if ( F_85 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_187 ,
0 , V_2 -> V_113 , 3 ) ;
goto V_176;
}
goto F_36;
}
V_186 = 0 ;
F_57 (p, n, &hdev->uuids) {
struct V_84 * V_188 = F_58 ( V_133 , struct V_84 , V_130 ) ;
if ( memcmp ( V_188 -> V_85 , V_104 -> V_85 , 16 ) != 0 )
continue;
F_61 ( & V_188 -> V_130 ) ;
F_17 ( V_188 ) ;
V_186 ++ ;
}
if ( V_186 == 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_187 ,
V_151 ) ;
goto V_176;
}
F_36:
V_19 = F_36 ( V_2 ) ;
if ( V_19 < 0 )
goto V_176;
V_19 = F_32 ( V_2 ) ;
if ( V_19 < 0 )
goto V_176;
if ( ! F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_187 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_187 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_89 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_189 * V_104 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_140 ) ;
goto V_176;
}
V_2 -> V_112 = V_104 -> V_191 ;
V_2 -> V_111 = V_104 -> V_192 ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_190 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_176;
}
if ( F_40 ( V_105 , & V_2 -> V_53 ) ) {
F_42 ( V_2 ) ;
F_90 ( & V_2 -> V_118 ) ;
F_41 ( V_2 ) ;
F_32 ( V_2 ) ;
}
V_19 = F_36 ( V_2 ) ;
if ( V_19 < 0 )
goto V_176;
if ( ! F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_190 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_190 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_91 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_193 * V_104 = V_29 ;
T_2 V_194 , V_195 ;
int V_44 ;
V_194 = F_72 ( V_104 -> V_194 ) ;
V_195 = sizeof( * V_104 ) + V_194 *
sizeof( struct V_196 ) ;
if ( V_195 != V_24 ) {
F_92 ( L_7 ,
V_24 , V_195 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_197 ,
V_151 ) ;
}
F_5 ( L_8 , V_2 -> V_110 , V_104 -> V_198 ,
V_194 ) ;
F_41 ( V_2 ) ;
F_93 ( V_2 ) ;
F_37 ( V_199 , & V_2 -> V_53 ) ;
if ( V_104 -> V_198 )
F_37 ( V_200 , & V_2 -> V_53 ) ;
else
F_46 ( V_200 , & V_2 -> V_53 ) ;
for ( V_44 = 0 ; V_44 < V_194 ; V_44 ++ ) {
struct V_196 * V_201 = & V_104 -> V_202 [ V_44 ] ;
F_94 ( V_2 , NULL , 0 , & V_201 -> V_203 . V_121 , V_201 -> V_77 ,
V_201 -> type , V_201 -> V_204 ) ;
}
F_12 ( V_9 , V_2 -> V_54 , V_197 , 0 , NULL , 0 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_205 , struct V_8 * V_143 )
{
struct V_206 V_18 ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = V_205 ;
return F_67 ( V_207 , V_2 , & V_18 , sizeof( V_18 ) ,
V_143 ) ;
}
static int F_96 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_208 * V_104 = V_29 ;
struct V_209 V_25 ;
struct V_210 V_211 ;
struct V_128 * V_11 ;
struct V_212 * V_213 ;
int V_19 ;
F_41 ( V_2 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_48 ( & V_25 . V_203 . V_121 , & V_104 -> V_203 . V_121 ) ;
V_25 . V_203 . type = V_104 -> V_203 . type ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_214 ,
V_152 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
if ( V_104 -> V_203 . type == V_215 )
V_19 = F_97 ( V_2 , & V_104 -> V_203 . V_121 ) ;
else
V_19 = F_98 ( V_2 , & V_104 -> V_203 . V_121 ) ;
if ( V_19 < 0 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_214 ,
V_216 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
if ( V_104 -> V_217 ) {
if ( V_104 -> V_203 . type == V_215 )
V_213 = F_99 ( V_2 , V_218 ,
& V_104 -> V_203 . V_121 ) ;
else
V_213 = F_99 ( V_2 , V_219 ,
& V_104 -> V_203 . V_121 ) ;
} else {
V_213 = NULL ;
}
if ( ! V_213 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_214 , 0 ,
& V_25 , sizeof( V_25 ) ) ;
F_95 ( V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type , V_9 ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_214 , V_2 , V_104 ,
sizeof( * V_104 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
V_211 . V_220 = F_9 ( V_213 -> V_220 ) ;
V_211 . V_221 = 0x13 ;
V_19 = F_34 ( V_2 , V_222 , sizeof( V_211 ) , & V_211 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int V_217 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_223 * V_104 = V_29 ;
struct V_210 V_211 ;
struct V_128 * V_11 ;
struct V_212 * V_213 ;
int V_19 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
if ( ! F_22 ( V_224 , & V_2 -> V_163 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_225 ,
V_152 ) ;
goto V_139;
}
if ( F_59 ( V_225 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_225 ,
V_140 ) ;
goto V_139;
}
if ( V_104 -> V_203 . type == V_215 )
V_213 = F_99 ( V_2 , V_218 ,
& V_104 -> V_203 . V_121 ) ;
else
V_213 = F_99 ( V_2 , V_219 , & V_104 -> V_203 . V_121 ) ;
if ( ! V_213 || V_213 -> V_226 == V_227 || V_213 -> V_226 == V_228 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_225 ,
V_229 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_225 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
V_211 . V_220 = F_9 ( V_213 -> V_220 ) ;
V_211 . V_221 = V_230 ;
V_19 = F_34 ( V_2 , V_222 , sizeof( V_211 ) , & V_211 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static T_1 F_100 ( T_1 V_231 , T_1 V_205 )
{
switch ( V_231 ) {
case V_219 :
switch ( V_205 ) {
case V_232 :
return V_233 ;
default:
return V_234 ;
}
default:
return V_215 ;
}
}
static int F_101 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_235 * V_25 ;
struct V_212 * V_236 ;
T_3 V_26 ;
int V_19 ;
T_2 V_44 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_237 ,
V_152 ) ;
goto V_176;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_238 , & V_236 -> V_163 ) )
V_44 ++ ;
}
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_239 ) ) ;
V_25 = F_15 ( V_26 , V_20 ) ;
if ( ! V_25 ) {
V_19 = - V_21 ;
goto V_176;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_238 , & V_236 -> V_163 ) )
continue;
F_48 ( & V_25 -> V_203 [ V_44 ] . V_121 , & V_236 -> V_240 ) ;
V_25 -> V_203 [ V_44 ] . type = F_100 ( V_236 -> type , V_236 -> V_241 ) ;
if ( V_236 -> type == V_242 || V_236 -> type == V_243 )
continue;
V_44 ++ ;
}
V_25 -> V_244 = F_9 ( V_44 ) ;
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_239 ) ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_237 , 0 , V_25 ,
V_26 ) ;
F_17 ( V_25 ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_102 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_245 * V_104 )
{
struct V_128 * V_11 ;
int V_19 ;
V_11 = F_52 ( V_9 , V_246 , V_2 , V_104 ,
sizeof( * V_104 ) ) ;
if ( ! V_11 )
return - V_21 ;
V_19 = F_34 ( V_2 , V_247 ,
sizeof( V_104 -> V_203 . V_121 ) , & V_104 -> V_203 . V_121 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
return V_19 ;
}
static int F_103 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_212 * V_213 ;
struct V_248 * V_104 = V_29 ;
struct V_249 V_250 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_251 ,
V_152 ) ;
goto V_139;
}
V_213 = F_99 ( V_2 , V_218 , & V_104 -> V_203 . V_121 ) ;
if ( ! V_213 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_251 ,
V_229 ) ;
goto V_139;
}
if ( V_213 -> V_252 == V_253 && V_104 -> V_204 != 16 ) {
struct V_245 V_254 ;
memcpy ( & V_254 . V_203 , & V_104 -> V_203 , sizeof( V_254 . V_203 ) ) ;
F_92 ( L_10 ) ;
V_19 = F_102 ( V_9 , V_2 , & V_254 ) ;
if ( V_19 >= 0 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_251 ,
V_151 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_251 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
F_48 ( & V_250 . V_121 , & V_104 -> V_203 . V_121 ) ;
V_250 . V_204 = V_104 -> V_204 ;
memcpy ( V_250 . V_255 , V_104 -> V_255 , sizeof( V_250 . V_255 ) ) ;
V_19 = F_34 ( V_2 , V_256 , sizeof( V_250 ) , & V_250 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_104 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_257 * V_104 = V_29 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
V_2 -> V_258 = V_104 -> V_258 ;
F_5 ( L_11 , V_2 -> V_110 ,
V_2 -> V_258 ) ;
F_42 ( V_2 ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_259 , 0 , NULL ,
0 ) ;
}
static struct V_128 * F_105 ( struct V_212 * V_213 )
{
struct V_1 * V_2 = V_213 -> V_2 ;
struct V_128 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 != V_260 )
continue;
if ( V_11 -> V_261 != V_213 )
continue;
return V_11 ;
}
return NULL ;
}
static void F_106 ( struct V_128 * V_11 , T_1 V_12 )
{
struct V_262 V_25 ;
struct V_212 * V_213 = V_11 -> V_261 ;
F_48 ( & V_25 . V_203 . V_121 , & V_213 -> V_240 ) ;
V_25 . V_203 . type = F_100 ( V_213 -> type , V_213 -> V_241 ) ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_260 , V_12 ,
& V_25 , sizeof( V_25 ) ) ;
V_213 -> V_263 = NULL ;
V_213 -> V_264 = NULL ;
V_213 -> V_265 = NULL ;
F_107 ( V_213 ) ;
F_60 ( V_11 ) ;
}
static void F_108 ( struct V_212 * V_213 , T_1 V_12 )
{
struct V_128 * V_11 ;
F_5 ( L_12 , V_12 ) ;
V_11 = F_105 ( V_213 ) ;
if ( ! V_11 )
F_5 ( L_13 ) ;
else
F_106 ( V_11 , F_2 ( V_12 ) ) ;
}
static void F_109 ( struct V_212 * V_213 , T_1 V_12 )
{
struct V_128 * V_11 ;
F_5 ( L_12 , V_12 ) ;
if ( ! V_12 )
return;
V_11 = F_105 ( V_213 ) ;
if ( ! V_11 )
F_5 ( L_13 ) ;
else
F_106 ( V_11 , F_2 ( V_12 ) ) ;
}
static int F_110 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_266 * V_104 = V_29 ;
struct V_262 V_25 ;
struct V_128 * V_11 ;
T_1 V_267 , V_268 ;
struct V_212 * V_213 ;
int V_19 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_260 ,
V_152 ) ;
goto V_176;
}
V_267 = V_269 ;
if ( V_104 -> V_270 == 0x03 )
V_268 = V_271 ;
else
V_268 = V_272 ;
if ( V_104 -> V_203 . type == V_215 )
V_213 = F_111 ( V_2 , V_218 , & V_104 -> V_203 . V_121 ,
V_104 -> V_203 . type , V_267 , V_268 ) ;
else
V_213 = F_111 ( V_2 , V_219 , & V_104 -> V_203 . V_121 ,
V_104 -> V_203 . type , V_267 , V_268 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_48 ( & V_25 . V_203 . V_121 , & V_104 -> V_203 . V_121 ) ;
V_25 . V_203 . type = V_104 -> V_203 . type ;
if ( F_112 ( V_213 ) ) {
int V_12 ;
if ( F_113 ( V_213 ) == - V_273 )
V_12 = V_140 ;
else
V_12 = V_274 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_260 ,
V_12 , & V_25 ,
sizeof( V_25 ) ) ;
goto V_176;
}
if ( V_213 -> V_263 ) {
F_107 ( V_213 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_260 ,
V_140 , & V_25 , sizeof( V_25 ) ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_260 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
F_107 ( V_213 ) ;
goto V_176;
}
if ( V_104 -> V_203 . type == V_215 )
V_213 -> V_263 = F_108 ;
else
V_213 -> V_263 = F_109 ;
V_213 -> V_264 = F_108 ;
V_213 -> V_265 = F_108 ;
V_213 -> V_258 = V_104 -> V_270 ;
V_11 -> V_261 = V_213 ;
if ( V_213 -> V_226 == V_275 &&
F_114 ( V_213 , V_267 , V_268 ) )
F_106 ( V_11 , 0 ) ;
V_19 = 0 ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_115 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_239 * V_203 = V_29 ;
struct V_128 * V_11 ;
struct V_212 * V_213 ;
int V_19 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_276 ,
V_152 ) ;
goto V_176;
}
V_11 = F_59 ( V_260 , V_2 ) ;
if ( ! V_11 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_276 ,
V_151 ) ;
goto V_176;
}
V_213 = V_11 -> V_261 ;
if ( F_116 ( & V_203 -> V_121 , & V_213 -> V_240 ) != 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_276 ,
V_151 ) ;
goto V_176;
}
F_106 ( V_11 , V_277 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_276 , 0 ,
V_203 , sizeof( * V_203 ) ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_117 ( struct V_8 * V_9 , struct V_1 * V_2 ,
T_7 * V_121 , T_1 type , T_2 V_278 ,
T_2 V_279 , T_6 V_280 )
{
struct V_128 * V_11 ;
struct V_212 * V_213 ;
int V_19 ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_278 ,
V_152 ) ;
goto V_281;
}
if ( type == V_215 )
V_213 = F_99 ( V_2 , V_218 , V_121 ) ;
else
V_213 = F_99 ( V_2 , V_219 , V_121 ) ;
if ( ! V_213 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_278 ,
V_229 ) ;
goto V_281;
}
if ( type == V_233 || type == V_234 ) {
V_19 = F_118 ( V_213 , V_278 , V_280 ) ;
if ( ! V_19 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_278 ,
V_282 ) ;
else
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_278 ,
V_7 ) ;
goto V_281;
}
V_11 = F_52 ( V_9 , V_278 , V_2 , V_121 , sizeof( * V_121 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_281;
}
if ( V_279 == V_283 ) {
struct V_284 V_104 ;
F_48 ( & V_104 . V_121 , V_121 ) ;
V_104 . V_280 = V_280 ;
V_19 = F_34 ( V_2 , V_279 , sizeof( V_104 ) , & V_104 ) ;
} else
V_19 = F_34 ( V_2 , V_279 , sizeof( * V_121 ) , V_121 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_281:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_119 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_245 * V_104 = V_29 ;
F_5 ( L_9 ) ;
return F_117 ( V_9 , V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ,
V_246 ,
V_247 , 0 ) ;
}
static int F_120 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_285 * V_104 = V_29 ;
F_5 ( L_9 ) ;
if ( V_24 != sizeof( * V_104 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_286 ,
V_151 ) ;
return F_117 ( V_9 , V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ,
V_286 ,
V_287 , 0 ) ;
}
static int F_121 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_288 * V_104 = V_29 ;
F_5 ( L_9 ) ;
return F_117 ( V_9 , V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ,
V_289 ,
V_290 , 0 ) ;
}
static int F_122 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_291 * V_104 = V_29 ;
F_5 ( L_9 ) ;
return F_117 ( V_9 , V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ,
V_292 ,
V_283 , V_104 -> V_280 ) ;
}
static int F_123 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_293 * V_104 = V_29 ;
F_5 ( L_9 ) ;
return F_117 ( V_9 , V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ,
V_294 ,
V_295 , 0 ) ;
}
static int F_124 ( struct V_1 * V_2 , const char * V_110 )
{
struct V_296 V_104 ;
memcpy ( V_104 . V_110 , V_110 , sizeof( V_104 . V_110 ) ) ;
return F_34 ( V_2 , V_297 , sizeof( V_104 ) , & V_104 ) ;
}
static int F_125 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_298 * V_104 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_9 ) ;
F_41 ( V_2 ) ;
memcpy ( V_2 -> V_126 , V_104 -> V_126 , sizeof( V_2 -> V_126 ) ) ;
if ( ! F_28 ( V_2 ) ) {
memcpy ( V_2 -> V_87 , V_104 -> V_110 , sizeof( V_2 -> V_87 ) ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_299 , 0 ,
V_29 , V_24 ) ;
if ( V_19 < 0 )
goto V_139;
V_19 = F_67 ( V_300 , V_2 , V_29 , V_24 ,
V_9 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_299 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
V_19 = F_124 ( V_2 , V_104 -> V_110 ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_126 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_301 ,
V_152 ) ;
goto V_176;
}
if ( ! F_24 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_301 ,
V_150 ) ;
goto V_176;
}
if ( F_59 ( V_301 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_301 ,
V_140 ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_301 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
V_19 = F_34 ( V_2 , V_302 , 0 , NULL ) ;
if ( V_19 < 0 )
F_60 ( V_11 ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_127 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_303 * V_104 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_14 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_304 ,
V_152 , & V_104 -> V_203 ,
sizeof( V_104 -> V_203 ) ) ;
goto V_176;
}
V_19 = F_128 ( V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_305 ,
V_104 -> V_306 ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = 0 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_304 , V_12 ,
& V_104 -> V_203 , sizeof( V_104 -> V_203 ) ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_129 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_307 * V_104 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 ,
V_308 ,
V_152 , & V_104 -> V_203 ,
sizeof( V_104 -> V_203 ) ) ;
goto V_176;
}
V_19 = F_130 ( V_2 , & V_104 -> V_203 . V_121 ) ;
if ( V_19 < 0 )
V_12 = V_151 ;
else
V_12 = 0 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_308 ,
V_12 , & V_104 -> V_203 , sizeof( V_104 -> V_203 ) ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
V_19 = F_132 ( V_2 , V_309 ) ;
if ( V_19 < 0 )
F_133 ( V_2 , V_310 ) ;
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_134 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_311 * V_104 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_312 ,
V_152 ) ;
goto V_139;
}
if ( F_22 ( V_313 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_312 ,
V_140 ) ;
goto V_139;
}
if ( V_2 -> V_314 . V_226 != V_310 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_312 ,
V_140 ) ;
goto V_139;
}
V_11 = F_52 ( V_9 , V_312 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_139;
}
V_2 -> V_314 . type = V_104 -> type ;
switch ( V_2 -> V_314 . type ) {
case V_315 :
if ( F_25 ( V_2 ) )
V_19 = F_132 ( V_2 , V_316 ) ;
else
V_19 = - V_317 ;
break;
case V_318 :
if ( F_82 ( V_2 ) )
V_19 = F_135 ( V_2 , V_319 , V_320 ,
V_321 , V_322 ) ;
else
V_19 = - V_317 ;
break;
case V_323 :
if ( F_82 ( V_2 ) && F_25 ( V_2 ) )
V_19 = F_135 ( V_2 , V_319 , V_320 ,
V_321 ,
V_324 ) ;
else
V_19 = - V_317 ;
break;
default:
V_19 = - V_325 ;
}
if ( V_19 < 0 )
F_60 ( V_11 ) ;
else
F_133 ( V_2 , V_326 ) ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_136 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_327 * V_328 = V_29 ;
struct V_128 * V_11 ;
struct V_329 V_104 ;
struct V_330 * V_331 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_137 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_332 ,
V_154 , & V_328 -> type ,
sizeof( V_328 -> type ) ) ;
goto V_176;
}
if ( V_2 -> V_314 . type != V_328 -> type ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_332 ,
V_151 , & V_328 -> type ,
sizeof( V_328 -> type ) ) ;
goto V_176;
}
V_11 = F_52 ( V_9 , V_332 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_176;
}
switch ( V_2 -> V_314 . V_226 ) {
case V_333 :
if ( F_22 ( V_334 , & V_2 -> V_163 ) )
V_19 = F_138 ( V_2 ) ;
else
V_19 = F_139 ( V_2 ) ;
break;
case V_335 :
V_331 = F_140 ( V_2 , V_336 ,
V_337 ) ;
if ( ! V_331 ) {
F_60 ( V_11 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 ,
V_332 , 0 ,
& V_328 -> type ,
sizeof( V_328 -> type ) ) ;
F_133 ( V_2 , V_310 ) ;
goto V_176;
}
F_48 ( & V_104 . V_121 , & V_331 -> V_29 . V_121 ) ;
V_19 = F_34 ( V_2 , V_338 ,
sizeof( V_104 ) , & V_104 ) ;
break;
default:
F_5 ( L_15 , V_2 -> V_314 . V_226 ) ;
V_19 = - V_339 ;
}
if ( V_19 < 0 )
F_60 ( V_11 ) ;
else
F_133 ( V_2 , V_340 ) ;
V_176:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_141 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_341 * V_104 = V_29 ;
struct V_330 * V_331 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
if ( ! F_137 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_342 ,
V_7 ) ;
goto V_139;
}
V_331 = F_142 ( V_2 , & V_104 -> V_203 . V_121 ) ;
if ( ! V_331 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_342 ,
V_151 ) ;
goto V_139;
}
if ( V_104 -> V_343 ) {
V_331 -> V_344 = V_345 ;
F_61 ( & V_331 -> V_130 ) ;
} else {
V_331 -> V_344 = V_346 ;
F_143 ( V_2 , V_331 ) ;
}
V_19 = 0 ;
V_139:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_144 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_347 * V_104 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
V_19 = F_145 ( V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = 0 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_348 , V_12 ,
& V_104 -> V_203 , sizeof( V_104 -> V_203 ) ) ;
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_146 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_349 * V_104 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_41 ( V_2 ) ;
V_19 = F_147 ( V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type ) ;
if ( V_19 < 0 )
V_12 = V_151 ;
else
V_12 = 0 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_350 , V_12 ,
& V_104 -> V_203 , sizeof( V_104 -> V_203 ) ) ;
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_148 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_351 * V_104 = V_29 ;
int V_19 ;
T_8 V_352 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
V_352 = F_72 ( V_104 -> V_352 ) ;
if ( V_352 > 0x0002 )
return F_4 ( V_9 , V_2 -> V_54 , V_353 ,
V_151 ) ;
F_41 ( V_2 ) ;
V_2 -> V_93 = V_352 ;
V_2 -> V_95 = F_72 ( V_104 -> V_354 ) ;
V_2 -> V_96 = F_72 ( V_104 -> V_355 ) ;
V_2 -> V_97 = F_72 ( V_104 -> V_32 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_353 , 0 , NULL , 0 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_149 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_135 * V_104 = V_29 ;
struct V_356 V_357 ;
T_1 type ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_358 ,
V_150 ) ;
if ( ! F_28 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_358 ,
V_152 ) ;
if ( ! F_22 ( V_69 , & V_2 -> V_53 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_358 ,
V_154 ) ;
F_41 ( V_2 ) ;
if ( V_104 -> V_77 ) {
type = V_359 ;
V_357 . V_360 = F_8 ( 0x0100 ) ;
} else {
type = V_361 ;
V_357 . V_360 = F_8 ( 0x0800 ) ;
}
V_357 . V_362 = F_8 ( 0x0012 ) ;
V_19 = F_34 ( V_2 , V_363 , sizeof( V_357 ) ,
& V_357 ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_358 ,
V_7 ) ;
goto V_281;
}
V_19 = F_34 ( V_2 , V_364 , 1 , & type ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_358 ,
V_7 ) ;
goto V_281;
}
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_358 , 0 ,
NULL , 0 ) ;
V_281:
F_42 ( V_2 ) ;
return V_19 ;
}
static int F_150 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_365 , T_2 V_24 )
{
struct V_366 * V_104 = V_365 ;
T_2 V_194 , V_195 ;
int V_44 ;
V_194 = F_72 ( V_104 -> V_194 ) ;
V_195 = sizeof( * V_104 ) + V_194 *
sizeof( struct V_367 ) ;
if ( V_195 != V_24 ) {
F_92 ( L_16 ,
V_24 , V_195 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_368 ,
V_325 ) ;
}
F_5 ( L_17 , V_2 -> V_110 , V_194 ) ;
F_41 ( V_2 ) ;
F_151 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_194 ; V_44 ++ ) {
struct V_367 * V_201 = & V_104 -> V_202 [ V_44 ] ;
T_1 type ;
if ( V_201 -> V_369 )
type = V_370 ;
else
type = V_371 ;
F_152 ( V_2 , & V_201 -> V_203 . V_121 ,
F_153 ( V_201 -> V_203 . type ) ,
type , 0 , V_201 -> V_372 , V_201 -> V_77 ,
V_201 -> V_373 , V_201 -> V_374 , V_201 -> rand ) ;
}
F_42 ( V_2 ) ;
return 0 ;
}
int F_154 ( struct V_8 * V_9 , struct V_375 * V_376 , T_3 V_377 )
{
void * V_378 ;
T_1 * V_104 ;
struct V_15 * V_16 ;
T_2 V_22 , V_10 , V_24 ;
struct V_1 * V_2 = NULL ;
const struct V_379 * V_380 ;
int V_19 ;
F_5 ( L_18 , V_377 ) ;
if ( V_377 < sizeof( * V_16 ) )
return - V_325 ;
V_378 = F_15 ( V_377 , V_20 ) ;
if ( ! V_378 )
return - V_21 ;
if ( F_155 ( V_378 , V_376 -> V_381 , V_377 ) ) {
V_19 = - V_339 ;
goto V_281;
}
V_16 = V_378 ;
V_22 = F_72 ( V_16 -> V_22 ) ;
V_10 = F_72 ( V_16 -> V_10 ) ;
V_24 = F_72 ( V_16 -> V_24 ) ;
if ( V_24 != V_377 - sizeof( * V_16 ) ) {
V_19 = - V_325 ;
goto V_281;
}
if ( V_10 != V_36 ) {
V_2 = F_156 ( V_10 ) ;
if ( ! V_2 ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_382 ) ;
goto V_281;
}
}
if ( V_22 >= F_3 ( V_383 ) ||
V_383 [ V_22 ] . V_384 == NULL ) {
F_5 ( L_19 , V_22 ) ;
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_385 ) ;
goto V_281;
}
if ( ( V_2 && V_22 < V_127 ) ||
( ! V_2 && V_22 >= V_127 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_382 ) ;
goto V_281;
}
V_380 = & V_383 [ V_22 ] ;
if ( ( V_380 -> V_386 && V_24 < V_380 -> V_30 ) ||
( ! V_380 -> V_386 && V_24 != V_380 -> V_30 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_151 ) ;
goto V_281;
}
if ( V_2 )
F_43 ( V_9 , V_2 ) ;
V_104 = V_378 + sizeof( * V_16 ) ;
V_19 = V_380 -> V_384 ( V_9 , V_2 , V_104 , V_24 ) ;
if ( V_19 < 0 )
goto V_281;
V_19 = V_377 ;
V_281:
if ( V_2 )
F_157 ( V_2 ) ;
F_17 ( V_378 ) ;
return V_19 ;
}
static void F_158 ( struct V_128 * V_11 , void * V_29 )
{
T_1 * V_12 = V_29 ;
F_4 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , * V_12 ) ;
F_60 ( V_11 ) ;
}
int F_159 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return - V_317 ;
return F_67 ( V_387 , V_2 , NULL , 0 , NULL ) ;
}
int F_160 ( struct V_1 * V_2 )
{
T_1 V_12 = V_382 ;
if ( ! F_1 ( V_2 ) )
return - V_317 ;
F_55 ( 0 , V_2 , F_158 , & V_12 ) ;
return F_67 ( V_388 , V_2 , NULL , 0 , NULL ) ;
}
static void F_161 ( struct V_128 * V_11 , void * V_29 )
{
struct V_389 * V_188 = V_29 ;
F_62 ( V_11 -> V_9 , V_11 -> V_22 , V_188 -> V_2 ) ;
F_61 ( & V_11 -> V_130 ) ;
if ( V_188 -> V_9 == NULL ) {
V_188 -> V_9 = V_11 -> V_9 ;
F_53 ( V_188 -> V_9 ) ;
}
F_50 ( V_11 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
T_1 V_148 = 0 ;
if ( F_22 ( V_69 , & V_2 -> V_53 ) )
V_148 |= V_159 ;
if ( F_22 ( V_70 , & V_2 -> V_53 ) )
V_148 |= V_160 ;
if ( ! V_148 )
return 0 ;
return F_34 ( V_2 , V_161 , 1 , & V_148 ) ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_390 )
{
struct V_389 V_188 = { NULL , V_2 } ;
int V_19 ;
if ( ! F_22 ( V_119 , & V_2 -> V_53 ) )
return 0 ;
F_55 ( V_138 , V_2 , F_161 , & V_188 ) ;
if ( V_390 ) {
if ( F_22 ( V_74 , & V_2 -> V_53 ) &&
! F_163 ( V_2 ) ) {
T_1 V_391 = 1 ;
F_34 ( V_2 , V_170 , 1 , & V_391 ) ;
}
if ( F_22 ( V_72 , & V_2 -> V_53 ) ) {
struct V_172 V_104 ;
V_104 . V_177 = 1 ;
V_104 . V_178 = F_83 ( V_2 ) ;
if ( V_104 . V_177 != F_82 ( V_2 ) ||
V_104 . V_178 != F_164 ( V_2 ) )
F_34 ( V_2 ,
V_179 ,
sizeof( V_104 ) , & V_104 ) ;
}
if ( F_25 ( V_2 ) ) {
F_162 ( V_2 ) ;
F_36 ( V_2 ) ;
F_124 ( V_2 , V_2 -> V_87 ) ;
F_32 ( V_2 ) ;
}
} else {
T_1 V_12 = V_152 ;
F_55 ( 0 , V_2 , F_158 , & V_12 ) ;
}
V_19 = F_70 ( V_2 , V_188 . V_9 ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
return V_19 ;
}
int F_165 ( struct V_1 * V_2 , T_1 V_392 )
{
struct V_389 V_188 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_392 ) {
if ( ! F_44 ( V_70 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_40 ( V_70 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_55 ( V_149 , V_2 , F_161 ,
& V_188 ) ;
if ( V_155 )
V_19 = F_70 ( V_2 , V_188 . V_9 ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
return V_19 ;
}
int F_166 ( struct V_1 * V_2 , T_1 V_393 )
{
struct V_389 V_188 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_393 ) {
if ( ! F_44 ( V_69 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_40 ( V_69 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_55 ( V_153 , V_2 , F_161 ,
& V_188 ) ;
if ( V_155 )
V_19 = F_70 ( V_2 , V_188 . V_9 ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
return V_19 ;
}
int F_167 ( struct V_1 * V_2 , T_1 V_148 , T_1 V_12 )
{
T_1 V_394 = F_2 ( V_12 ) ;
if ( V_148 & V_159 )
F_55 ( V_153 , V_2 ,
F_158 , & V_394 ) ;
if ( V_148 & V_160 )
F_55 ( V_149 , V_2 ,
F_158 , & V_394 ) ;
return 0 ;
}
int F_168 ( struct V_1 * V_2 , struct V_395 * V_201 ,
bool V_396 )
{
struct V_397 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_398 = V_396 ;
F_48 ( & V_18 . V_201 . V_203 . V_121 , & V_201 -> V_121 ) ;
V_18 . V_201 . V_203 . type = V_215 ;
V_18 . V_201 . type = V_201 -> type ;
memcpy ( V_18 . V_201 . V_77 , V_201 -> V_77 , V_399 ) ;
V_18 . V_201 . V_204 = V_201 -> V_204 ;
return F_67 ( V_400 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_169 ( struct V_1 * V_2 , struct V_401 * V_201 , T_1 V_396 )
{
struct V_402 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_398 = V_396 ;
F_48 ( & V_18 . V_201 . V_203 . V_121 , & V_201 -> V_121 ) ;
V_18 . V_201 . V_203 . type = F_100 ( V_219 , V_201 -> V_403 ) ;
V_18 . V_201 . V_372 = V_201 -> V_372 ;
V_18 . V_201 . V_373 = V_201 -> V_373 ;
V_18 . V_201 . V_374 = V_201 -> V_374 ;
if ( V_201 -> type == V_370 )
V_18 . V_201 . V_369 = 1 ;
memcpy ( V_18 . V_201 . rand , V_201 -> rand , sizeof( V_201 -> rand ) ) ;
memcpy ( V_18 . V_201 . V_77 , V_201 -> V_77 , sizeof( V_201 -> V_77 ) ) ;
return F_67 ( V_404 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_170 ( struct V_1 * V_2 , T_7 * V_121 , T_1 V_231 ,
T_1 V_205 , T_5 V_163 , T_1 * V_110 , T_1 V_86 ,
T_1 * V_113 )
{
char V_378 [ 512 ] ;
struct V_405 * V_18 = ( void * ) V_378 ;
T_2 V_80 = 0 ;
F_48 ( & V_18 -> V_203 . V_121 , V_121 ) ;
V_18 -> V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 -> V_163 = F_171 ( V_163 ) ;
if ( V_86 > 0 )
V_80 = F_172 ( V_18 -> V_106 , 0 , V_89 ,
V_110 , V_86 ) ;
if ( V_113 && memcmp ( V_113 , L_20 , 3 ) != 0 )
V_80 = F_172 ( V_18 -> V_106 , V_80 ,
V_406 , V_113 , 3 ) ;
V_18 -> V_80 = F_9 ( V_80 ) ;
return F_67 ( V_407 , V_2 , V_378 ,
sizeof( * V_18 ) + V_80 , NULL ) ;
}
static void F_173 ( struct V_128 * V_11 , void * V_29 )
{
struct V_223 * V_104 = V_11 -> V_129 ;
struct V_8 * * V_9 = V_29 ;
struct V_408 V_25 ;
F_48 ( & V_25 . V_203 . V_121 , & V_104 -> V_203 . V_121 ) ;
V_25 . V_203 . type = V_104 -> V_203 . type ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_225 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
* V_9 = V_11 -> V_9 ;
F_53 ( * V_9 ) ;
F_60 ( V_11 ) ;
}
static void F_174 ( struct V_128 * V_11 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_208 * V_104 = V_11 -> V_129 ;
struct V_209 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_48 ( & V_25 . V_203 . V_121 , & V_104 -> V_203 . V_121 ) ;
V_25 . V_203 . type = V_104 -> V_203 . type ;
F_95 ( V_2 , & V_104 -> V_203 . V_121 , V_104 -> V_203 . type , V_11 -> V_9 ) ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , 0 , & V_25 , sizeof( V_25 ) ) ;
F_60 ( V_11 ) ;
}
int F_175 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_221 )
{
struct V_409 V_18 ;
struct V_8 * V_9 = NULL ;
int V_19 ;
F_55 ( V_225 , V_2 , F_173 , & V_9 ) ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 . V_221 = V_221 ;
V_19 = F_67 ( V_410 , V_2 , & V_18 , sizeof( V_18 ) ,
V_9 ) ;
if ( V_9 )
F_51 ( V_9 ) ;
F_55 ( V_214 , V_2 , F_174 ,
V_2 ) ;
return V_19 ;
}
int F_176 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_12 )
{
struct V_408 V_25 ;
struct V_128 * V_11 ;
int V_19 ;
F_55 ( V_214 , V_2 , F_174 ,
V_2 ) ;
V_11 = F_59 ( V_225 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
F_48 ( & V_25 . V_203 . V_121 , V_121 ) ;
V_25 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_19 = F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_225 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_60 ( V_11 ) ;
return V_19 ;
}
int F_177 ( struct V_1 * V_2 , T_7 * V_121 , T_1 V_231 ,
T_1 V_205 , T_1 V_12 )
{
struct V_412 V_18 ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_67 ( V_413 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_178 ( struct V_1 * V_2 , T_7 * V_121 , T_1 V_414 )
{
struct V_415 V_18 ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = V_215 ;
V_18 . V_414 = V_414 ;
return F_67 ( V_416 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_179 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_12 )
{
struct V_128 * V_11 ;
struct V_417 V_25 ;
int V_19 ;
V_11 = F_59 ( V_251 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
F_48 ( & V_25 . V_203 . V_121 , V_121 ) ;
V_25 . V_203 . type = V_215 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_251 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_60 ( V_11 ) ;
return V_19 ;
}
int F_180 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_12 )
{
struct V_128 * V_11 ;
struct V_417 V_25 ;
int V_19 ;
V_11 = F_59 ( V_246 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
F_48 ( & V_25 . V_203 . V_121 , V_121 ) ;
V_25 . V_203 . type = V_215 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_246 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_60 ( V_11 ) ;
return V_19 ;
}
int F_181 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_6 V_418 ,
T_1 V_419 )
{
struct V_420 V_18 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 . V_419 = V_419 ;
V_18 . V_418 = V_418 ;
return F_67 ( V_421 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_182 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 )
{
struct V_422 V_18 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = F_100 ( V_231 , V_205 ) ;
return F_67 ( V_423 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
static int F_183 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_12 ,
T_1 V_22 )
{
struct V_128 * V_11 ;
struct V_424 V_25 ;
int V_19 ;
V_11 = F_59 ( V_22 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
F_48 ( & V_25 . V_203 . V_121 , V_121 ) ;
V_25 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_22 , F_2 ( V_12 ) ,
& V_25 , sizeof( V_25 ) ) ;
F_60 ( V_11 ) ;
return V_19 ;
}
int F_184 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_12 )
{
return F_183 ( V_2 , V_121 , V_231 , V_205 ,
V_12 , V_286 ) ;
}
int F_185 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_12 )
{
return F_183 ( V_2 , V_121 , V_231 , V_205 ,
V_12 ,
V_289 ) ;
}
int F_186 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_12 )
{
return F_183 ( V_2 , V_121 , V_231 , V_205 ,
V_12 , V_292 ) ;
}
int F_187 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_1 V_12 )
{
return F_183 ( V_2 , V_121 , V_231 , V_205 ,
V_12 ,
V_294 ) ;
}
int F_188 ( struct V_1 * V_2 , T_7 * V_121 ,
T_1 V_231 , T_1 V_205 , T_5 V_280 ,
T_1 V_425 )
{
struct V_426 V_18 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 . V_280 = F_171 ( V_280 ) ;
V_18 . V_425 = V_425 ;
return F_67 ( V_427 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_189 ( struct V_1 * V_2 , T_7 * V_121 , T_1 V_231 ,
T_1 V_205 , T_1 V_12 )
{
struct V_428 V_18 ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_67 ( V_429 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_190 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_389 V_188 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_394 = F_2 ( V_12 ) ;
F_55 ( V_166 , V_2 ,
F_158 , & V_394 ) ;
return 0 ;
}
if ( F_22 ( V_167 , & V_2 -> V_163 ) ) {
if ( ! F_44 ( V_73 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_40 ( V_73 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_55 ( V_166 , V_2 , F_161 ,
& V_188 ) ;
if ( V_155 )
V_19 = F_70 ( V_2 , V_188 . V_9 ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
return V_19 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_103 V_104 ;
if ( ! F_33 ( V_2 ) )
return 0 ;
memset ( V_2 -> V_106 , 0 , sizeof( V_2 -> V_106 ) ) ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
return F_34 ( V_2 , V_107 , sizeof( V_104 ) , & V_104 ) ;
}
int F_192 ( struct V_1 * V_2 , T_1 V_430 , T_1 V_12 )
{
struct V_389 V_188 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_394 = F_2 ( V_12 ) ;
if ( V_430 && F_40 ( V_74 ,
& V_2 -> V_53 ) )
V_19 = F_70 ( V_2 , NULL ) ;
F_55 ( V_169 , V_2 , F_158 ,
& V_394 ) ;
return V_19 ;
}
if ( V_430 ) {
if ( ! F_44 ( V_74 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_40 ( V_74 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_55 ( V_169 , V_2 , F_161 , & V_188 ) ;
if ( V_155 )
V_19 = F_70 ( V_2 , V_188 . V_9 ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) )
F_32 ( V_2 ) ;
else
F_191 ( V_2 ) ;
return V_19 ;
}
static void F_193 ( struct V_128 * V_11 , void * V_29 )
{
struct V_389 * V_188 = V_29 ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , V_188 -> F_2 ,
V_188 -> V_2 -> V_113 , 3 ) ;
F_61 ( & V_11 -> V_130 ) ;
if ( V_188 -> V_9 == NULL ) {
V_188 -> V_9 = V_11 -> V_9 ;
F_53 ( V_188 -> V_9 ) ;
}
F_50 ( V_11 ) ;
}
int F_194 ( struct V_1 * V_2 , T_1 * V_113 ,
T_1 V_12 )
{
struct V_389 V_188 = { NULL , V_2 , F_2 (status) } ;
int V_19 = 0 ;
F_46 ( V_115 , & V_2 -> V_53 ) ;
F_55 ( V_190 , V_2 , F_193 , & V_188 ) ;
F_55 ( V_181 , V_2 , F_193 , & V_188 ) ;
F_55 ( V_187 , V_2 , F_193 , & V_188 ) ;
if ( ! V_12 )
V_19 = F_67 ( V_431 , V_2 , V_113 ,
3 , NULL ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
return V_19 ;
}
int F_195 ( struct V_1 * V_2 , T_1 * V_110 , T_1 V_12 )
{
struct V_128 * V_11 ;
struct V_298 V_18 ;
bool V_155 = false ;
int V_19 = 0 ;
if ( memcmp ( V_110 , V_2 -> V_87 , sizeof( V_2 -> V_87 ) ) != 0 ) {
memcpy ( V_2 -> V_87 , V_110 , sizeof( V_2 -> V_87 ) ) ;
V_155 = true ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memcpy ( V_18 . V_110 , V_110 , V_432 ) ;
memcpy ( V_18 . V_126 , V_2 -> V_126 , V_433 ) ;
V_11 = F_59 ( V_299 , V_2 ) ;
if ( ! V_11 )
goto V_434;
V_155 = true ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_299 ,
F_2 ( V_12 ) ) ;
goto V_139;
}
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_299 , 0 , & V_18 ,
sizeof( V_18 ) ) ;
if ( V_19 < 0 )
goto V_139;
V_434:
if ( V_155 )
V_19 = F_67 ( V_300 , V_2 , & V_18 ,
sizeof( V_18 ) , V_11 ? V_11 -> V_9 : NULL ) ;
if ( ! F_22 ( V_435 , & V_2 -> V_163 ) )
F_32 ( V_2 ) ;
V_139:
if ( V_11 )
F_60 ( V_11 ) ;
return V_19 ;
}
int F_196 ( struct V_1 * V_2 , T_1 * V_305 ,
T_1 * V_306 , T_1 V_12 )
{
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_21 , V_2 -> V_110 , V_12 ) ;
V_11 = F_59 ( V_301 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_301 ,
F_2 ( V_12 ) ) ;
} else {
struct V_436 V_25 ;
memcpy ( V_25 . V_305 , V_305 , sizeof( V_25 . V_305 ) ) ;
memcpy ( V_25 . V_306 , V_306 , sizeof( V_25 . V_306 ) ) ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 ,
V_301 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
F_60 ( V_11 ) ;
return V_19 ;
}
int F_197 ( struct V_1 * V_2 , T_1 V_430 , T_1 V_12 )
{
struct V_389 V_188 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_394 = F_2 ( V_12 ) ;
if ( V_430 && F_40 ( V_72 ,
& V_2 -> V_53 ) )
V_19 = F_70 ( V_2 , NULL ) ;
F_55 ( V_175 , V_2 , F_158 ,
& V_394 ) ;
return V_19 ;
}
if ( V_430 ) {
if ( ! F_44 ( V_72 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_40 ( V_72 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_55 ( V_175 , V_2 , F_161 , & V_188 ) ;
if ( V_155 )
V_19 = F_70 ( V_2 , V_188 . V_9 ) ;
if ( V_188 . V_9 )
F_51 ( V_188 . V_9 ) ;
return V_19 ;
}
int F_198 ( struct V_1 * V_2 , T_7 * V_121 , T_1 V_231 ,
T_1 V_205 , T_1 * V_113 , T_9 V_437 , T_1 V_438 , T_1
V_391 , T_1 * V_106 , T_2 V_80 )
{
char V_378 [ 512 ] ;
struct V_439 * V_18 = ( void * ) V_378 ;
T_3 V_440 ;
if ( sizeof( * V_18 ) + V_80 + 5 > sizeof( V_378 ) )
return - V_325 ;
memset ( V_378 , 0 , sizeof( V_378 ) ) ;
F_48 ( & V_18 -> V_203 . V_121 , V_121 ) ;
V_18 -> V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 -> V_437 = V_437 ;
if ( V_438 )
V_18 -> V_163 |= F_199 ( V_441 ) ;
if ( ! V_391 )
V_18 -> V_163 |= F_199 ( V_442 ) ;
if ( V_80 > 0 )
memcpy ( V_18 -> V_106 , V_106 , V_80 ) ;
if ( V_113 && ! F_200 ( V_18 -> V_106 , V_80 , V_406 ) )
V_80 = F_172 ( V_18 -> V_106 , V_80 , V_406 ,
V_113 , 3 ) ;
V_18 -> V_80 = F_9 ( V_80 ) ;
V_440 = sizeof( * V_18 ) + V_80 ;
return F_67 ( V_443 , V_2 , V_18 , V_440 , NULL ) ;
}
int F_201 ( struct V_1 * V_2 , T_7 * V_121 , T_1 V_231 ,
T_1 V_205 , T_9 V_437 , T_1 * V_110 , T_1 V_86 )
{
struct V_439 * V_18 ;
char V_378 [ sizeof( * V_18 ) + V_432 + 2 ] ;
T_2 V_80 ;
V_18 = (struct V_439 * ) V_378 ;
memset ( V_378 , 0 , sizeof( V_378 ) ) ;
F_48 ( & V_18 -> V_203 . V_121 , V_121 ) ;
V_18 -> V_203 . type = F_100 ( V_231 , V_205 ) ;
V_18 -> V_437 = V_437 ;
V_80 = F_172 ( V_18 -> V_106 , 0 , V_89 , V_110 ,
V_86 ) ;
V_18 -> V_80 = F_9 ( V_80 ) ;
return F_67 ( V_443 , V_2 , V_18 ,
sizeof( * V_18 ) + V_80 , NULL ) ;
}
int F_202 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_128 * V_11 ;
T_1 type ;
int V_19 ;
F_133 ( V_2 , V_310 ) ;
V_11 = F_59 ( V_312 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
type = V_2 -> V_314 . type ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& type , sizeof( type ) ) ;
F_60 ( V_11 ) ;
return V_19 ;
}
int F_203 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_128 * V_11 ;
int V_19 ;
V_11 = F_59 ( V_332 , V_2 ) ;
if ( ! V_11 )
return - V_411 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& V_2 -> V_314 . type , sizeof( V_2 -> V_314 . type ) ) ;
F_60 ( V_11 ) ;
return V_19 ;
}
int F_204 ( struct V_1 * V_2 , T_1 V_444 )
{
struct V_445 V_18 ;
struct V_128 * V_11 ;
F_5 ( L_22 , V_2 -> V_110 , V_444 ) ;
if ( V_444 )
V_11 = F_59 ( V_312 , V_2 ) ;
else
V_11 = F_59 ( V_332 , V_2 ) ;
if ( V_11 != NULL ) {
T_1 type = V_2 -> V_314 . type ;
F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , 0 , & type ,
sizeof( type ) ) ;
F_60 ( V_11 ) ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . type = V_2 -> V_314 . type ;
V_18 . V_444 = V_444 ;
return F_67 ( V_446 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_205 ( struct V_1 * V_2 , T_7 * V_121 , T_1 type )
{
struct V_128 * V_11 ;
struct V_447 V_18 ;
V_11 = F_59 ( V_348 , V_2 ) ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = type ;
return F_67 ( V_448 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
int F_206 ( struct V_1 * V_2 , T_7 * V_121 , T_1 type )
{
struct V_128 * V_11 ;
struct V_449 V_18 ;
V_11 = F_59 ( V_350 , V_2 ) ;
F_48 ( & V_18 . V_203 . V_121 , V_121 ) ;
V_18 . V_203 . type = type ;
return F_67 ( V_450 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
