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
V_16 -> V_10 = F_8 ( V_10 ) ;
V_16 -> V_24 = F_8 ( sizeof( * V_18 ) ) ;
V_18 = ( void * ) F_7 ( V_14 , sizeof( * V_18 ) ) ;
V_18 -> V_12 = V_12 ;
V_18 -> V_22 = F_8 ( V_11 ) ;
V_19 = F_9 ( V_9 , V_14 ) ;
if ( V_19 < 0 )
F_10 ( V_14 ) ;
return V_19 ;
}
static int F_11 ( struct V_8 * V_9 , T_2 V_10 , T_2 V_11 , T_1 V_12 ,
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
V_16 -> V_10 = F_8 ( V_10 ) ;
V_16 -> V_24 = F_8 ( sizeof( * V_18 ) + V_26 ) ;
V_18 = ( void * ) F_7 ( V_14 , sizeof( * V_18 ) + V_26 ) ;
V_18 -> V_22 = F_8 ( V_11 ) ;
V_18 -> V_12 = V_12 ;
if ( V_25 )
memcpy ( V_18 -> V_29 , V_25 , V_26 ) ;
V_19 = F_9 ( V_9 , V_14 ) ;
if ( V_19 < 0 )
F_10 ( V_14 ) ;
return V_19 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_31 V_25 ;
F_5 ( L_2 , V_9 ) ;
V_25 . V_32 = V_33 ;
V_25 . V_34 = F_13 ( V_35 ) ;
return F_11 ( V_9 , V_36 , V_37 , 0 , & V_25 ,
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
V_25 -> V_39 = F_13 ( V_39 ) ;
V_25 -> V_41 = F_13 ( V_41 ) ;
for ( V_44 = 0 , V_22 = V_25 -> V_45 ; V_44 < V_39 ; V_44 ++ , V_22 ++ )
F_16 ( V_40 [ V_44 ] , V_22 ) ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ , V_22 ++ )
F_16 ( V_42 [ V_44 ] , V_22 ) ;
V_19 = F_11 ( V_9 , V_36 , V_46 , 0 , V_25 ,
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
V_25 -> V_10 [ V_49 ++ ] = F_8 ( V_48 -> V_54 ) ;
F_5 ( L_3 , V_48 -> V_54 ) ;
}
V_25 -> V_55 = F_8 ( V_49 ) ;
V_26 = sizeof( * V_25 ) + ( 2 * V_49 ) ;
F_21 ( & V_50 ) ;
V_19 = F_11 ( V_9 , V_36 , V_56 , 0 , V_25 ,
V_26 ) ;
F_17 ( V_25 ) ;
return V_19 ;
}
static T_5 F_23 ( struct V_1 * V_2 )
{
T_5 V_57 = 0 ;
V_57 |= V_58 ;
V_57 |= V_59 ;
V_57 |= V_60 ;
V_57 |= V_61 ;
V_57 |= V_62 ;
if ( F_24 ( V_2 ) )
V_57 |= V_63 ;
if ( F_25 ( V_2 ) ) {
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
V_57 |= V_59 ;
if ( F_22 ( V_70 , & V_2 -> V_53 ) )
V_57 |= V_61 ;
if ( F_22 ( V_71 , & V_2 -> V_53 ) )
V_57 |= V_62 ;
if ( F_25 ( V_2 ) )
V_57 |= V_64 ;
if ( F_22 ( V_72 , & V_2 -> V_53 ) )
V_57 |= V_68 ;
if ( F_22 ( V_73 , & V_2 -> V_53 ) )
V_57 |= V_65 ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) )
V_57 |= V_63 ;
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
if ( V_2 -> V_90 ) {
V_79 [ 0 ] = 2 ;
V_79 [ 1 ] = V_91 ;
V_79 [ 2 ] = ( T_1 ) V_2 -> V_90 ;
V_80 += 3 ;
V_79 += 3 ;
}
if ( V_2 -> V_92 > 0 ) {
V_79 [ 0 ] = 9 ;
V_79 [ 1 ] = V_93 ;
F_16 ( V_2 -> V_92 , V_79 + 2 ) ;
F_16 ( V_2 -> V_94 , V_79 + 4 ) ;
F_16 ( V_2 -> V_95 , V_79 + 6 ) ;
F_16 ( V_2 -> V_96 , V_79 + 8 ) ;
V_80 += 10 ;
V_79 += 10 ;
}
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
F_20 (uuid, &hdev->uuids, list) {
T_2 V_97 ;
V_97 = F_29 ( V_85 -> V_85 ) ;
if ( V_97 == 0 )
return;
if ( V_97 < 0x1100 )
continue;
if ( V_97 == V_98 )
continue;
if ( V_80 + 2 + sizeof( T_2 ) > V_82 ) {
V_83 = 1 ;
break;
}
for ( V_44 = 0 ; V_81 [ V_44 ] != 0 ; V_44 ++ )
if ( V_81 [ V_44 ] == V_97 )
break;
if ( V_81 [ V_44 ] == 0 ) {
V_81 [ V_44 ] = V_97 ;
V_80 += sizeof( T_2 ) ;
}
}
if ( V_81 [ 0 ] != 0 ) {
T_1 * V_99 = V_79 ;
V_79 [ 1 ] = V_83 ? V_100 : V_101 ;
V_79 += 2 ;
V_80 += 2 ;
for ( V_44 = 0 ; V_81 [ V_44 ] != 0 ; V_44 ++ ) {
* V_79 ++ = ( V_81 [ V_44 ] & 0x00ff ) ;
* V_79 ++ = ( V_81 [ V_44 ] & 0xff00 ) >> 8 ;
}
* V_99 = ( V_44 * sizeof( T_2 ) ) + 1 ;
}
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_102 V_103 ;
if ( ! F_28 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_104 [ 6 ] & V_105 ) )
return 0 ;
if ( ! F_22 ( V_74 , & V_2 -> V_53 ) )
return 0 ;
if ( F_22 ( V_106 , & V_2 -> V_53 ) )
return 0 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
F_31 ( V_2 , V_103 . V_29 ) ;
if ( memcmp ( V_103 . V_29 , V_2 -> V_107 , sizeof( V_103 . V_29 ) ) == 0 )
return 0 ;
memcpy ( V_2 -> V_107 , V_103 . V_29 , sizeof( V_103 . V_29 ) ) ;
return F_33 ( V_2 , V_108 , sizeof( V_103 ) , & V_103 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
T_1 V_77 = 0 ;
F_20 (uuid, &hdev->uuids, list)
V_77 |= V_85 -> V_109 ;
return V_77 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_1 V_110 [ 3 ] ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
if ( ! F_28 ( V_2 ) )
return 0 ;
if ( F_22 ( V_106 , & V_2 -> V_53 ) )
return 0 ;
V_110 [ 0 ] = V_2 -> V_112 ;
V_110 [ 1 ] = V_2 -> V_113 ;
V_110 [ 2 ] = F_34 ( V_2 ) ;
if ( memcmp ( V_110 , V_2 -> V_114 , 3 ) == 0 )
return 0 ;
V_19 = F_33 ( V_2 , V_115 , sizeof( V_110 ) , V_110 ) ;
if ( V_19 == 0 )
F_36 ( V_116 , & V_2 -> V_53 ) ;
return V_19 ;
}
static void F_37 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_38 ( V_118 , struct V_1 ,
V_119 . V_118 ) ;
if ( ! F_39 ( V_106 , & V_2 -> V_53 ) )
return;
F_40 ( V_2 ) ;
F_32 ( V_2 ) ;
F_35 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static void F_42 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_43 ( V_120 , & V_2 -> V_53 ) )
return;
F_44 ( & V_2 -> V_119 , F_37 ) ;
F_45 ( V_71 , & V_2 -> V_53 ) ;
}
static int F_46 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_121 V_25 ;
F_5 ( L_5 , V_9 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_47 ( & V_25 . V_122 , & V_2 -> V_122 ) ;
V_25 . V_32 = V_2 -> V_123 ;
V_25 . V_124 = F_8 ( V_2 -> V_124 ) ;
V_25 . V_125 = F_48 ( F_23 ( V_2 ) ) ;
V_25 . V_126 = F_48 ( F_27 ( V_2 ) ) ;
memcpy ( V_25 . V_114 , V_2 -> V_114 , 3 ) ;
memcpy ( V_25 . V_111 , V_2 -> V_87 , sizeof( V_2 -> V_87 ) ) ;
memcpy ( V_25 . V_127 , V_2 -> V_127 , sizeof( V_2 -> V_127 ) ) ;
F_41 ( V_2 ) ;
return F_11 ( V_9 , V_2 -> V_54 , V_128 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
static void F_49 ( struct V_129 * V_11 )
{
F_50 ( V_11 -> V_9 ) ;
F_17 ( V_11 -> V_130 ) ;
F_17 ( V_11 ) ;
}
static struct V_129 * F_51 ( struct V_8 * V_9 , T_2 V_22 ,
struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_129 * V_11 ;
V_11 = F_15 ( sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_22 = V_22 ;
V_11 -> V_10 = V_2 -> V_54 ;
V_11 -> V_130 = F_15 ( V_24 , V_20 ) ;
if ( ! V_11 -> V_130 ) {
F_17 ( V_11 ) ;
return NULL ;
}
if ( V_29 )
memcpy ( V_11 -> V_130 , V_29 , V_24 ) ;
V_11 -> V_9 = V_9 ;
F_52 ( V_9 ) ;
F_53 ( & V_11 -> V_131 , & V_2 -> V_132 ) ;
return V_11 ;
}
static void F_54 ( T_2 V_22 , struct V_1 * V_2 ,
void (* F_55)( struct V_129 * V_11 ,
void * V_29 ) ,
void * V_29 )
{
struct V_133 * V_134 , * V_135 ;
F_56 (p, n, &hdev->mgmt_pending) {
struct V_129 * V_11 ;
V_11 = F_57 ( V_134 , struct V_129 , V_131 ) ;
if ( V_22 > 0 && V_11 -> V_22 != V_22 )
continue;
F_55 ( V_11 , V_29 ) ;
}
}
static struct V_129 * F_58 ( T_2 V_22 , struct V_1 * V_2 )
{
struct V_129 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 == V_22 )
return V_11 ;
}
return NULL ;
}
static void F_59 ( struct V_129 * V_11 )
{
F_60 ( & V_11 -> V_131 ) ;
F_49 ( V_11 ) ;
}
static int F_61 ( struct V_8 * V_9 , T_2 V_22 , struct V_1 * V_2 )
{
T_6 V_57 = F_48 ( F_27 ( V_2 ) ) ;
return F_11 ( V_9 , V_2 -> V_54 , V_22 , 0 , & V_57 ,
sizeof( V_57 ) ) ;
}
static int F_62 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( F_39 ( V_137 , & V_2 -> V_53 ) ) {
F_63 ( & V_2 -> V_138 ) ;
if ( V_103 -> V_77 ) {
V_19 = F_61 ( V_9 , V_139 , V_2 ) ;
F_64 ( V_2 , 1 ) ;
goto V_140;
}
}
if ( ! ! V_103 -> V_77 == F_28 ( V_2 ) ) {
V_19 = F_61 ( V_9 , V_139 , V_2 ) ;
goto V_140;
}
if ( F_58 ( V_139 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_139 ,
V_141 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_139 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
if ( V_103 -> V_77 )
F_65 ( & V_2 -> V_142 ) ;
else
F_65 ( & V_2 -> V_138 . V_118 ) ;
V_19 = 0 ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_66 ( T_2 V_143 , struct V_1 * V_2 , void * V_29 , T_2 V_30 ,
struct V_8 * V_144 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_14 = F_6 ( sizeof( * V_16 ) + V_30 , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_16 = ( void * ) F_7 ( V_14 , sizeof( * V_16 ) ) ;
V_16 -> V_22 = F_8 ( V_143 ) ;
if ( V_2 )
V_16 -> V_10 = F_8 ( V_2 -> V_54 ) ;
else
V_16 -> V_10 = F_8 ( V_36 ) ;
V_16 -> V_24 = F_8 ( V_30 ) ;
if ( V_29 )
memcpy ( F_7 ( V_14 , V_30 ) , V_29 , V_30 ) ;
F_67 ( V_14 ) ;
F_68 ( V_14 , V_144 ) ;
F_10 ( V_14 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_8 * V_145 )
{
T_6 V_18 ;
V_18 = F_48 ( F_27 ( V_2 ) ) ;
return F_66 ( V_146 , V_2 , & V_18 , sizeof( V_18 ) , V_145 ) ;
}
static int F_70 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_147 * V_103 = V_29 ;
struct V_129 * V_11 ;
T_2 V_148 ;
T_1 V_149 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
V_148 = F_71 ( V_103 -> V_148 ) ;
if ( ! V_103 -> V_77 && V_148 > 0 )
return F_4 ( V_9 , V_2 -> V_54 , V_150 ,
V_151 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) && V_148 > 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_150 ,
V_152 ) ;
goto V_140;
}
if ( F_58 ( V_150 , V_2 ) ||
F_58 ( V_153 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_150 ,
V_141 ) ;
goto V_140;
}
if ( ! F_22 ( V_69 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_150 ,
V_154 ) ;
goto V_140;
}
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( ! ! V_103 -> V_77 != F_22 ( V_70 , & V_2 -> V_53 ) ) {
F_72 ( V_70 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_61 ( V_9 , V_150 , V_2 ) ;
if ( V_19 < 0 )
goto V_140;
if ( V_155 )
V_19 = F_69 ( V_2 , V_9 ) ;
goto V_140;
}
if ( ! ! V_103 -> V_77 == F_22 ( V_70 , & V_2 -> V_53 ) ) {
if ( V_2 -> V_156 > 0 ) {
F_63 ( & V_2 -> V_157 ) ;
V_2 -> V_156 = 0 ;
}
if ( V_103 -> V_77 && V_148 > 0 ) {
V_2 -> V_156 = V_148 ;
F_73 ( V_2 -> V_158 , & V_2 -> V_157 ,
F_74 ( V_2 -> V_156 * 1000 ) ) ;
}
V_19 = F_61 ( V_9 , V_150 , V_2 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_150 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
V_149 = V_159 ;
if ( V_103 -> V_77 )
V_149 |= V_160 ;
else
F_63 ( & V_2 -> V_157 ) ;
V_19 = F_33 ( V_2 , V_161 , 1 , & V_149 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
if ( V_103 -> V_77 )
V_2 -> V_156 = V_148 ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_75 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
struct V_129 * V_11 ;
T_1 V_149 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( ! ! V_103 -> V_77 != F_22 ( V_69 , & V_2 -> V_53 ) )
V_155 = true ;
if ( V_103 -> V_77 ) {
F_36 ( V_69 , & V_2 -> V_53 ) ;
} else {
F_45 ( V_69 , & V_2 -> V_53 ) ;
F_45 ( V_70 , & V_2 -> V_53 ) ;
}
V_19 = F_61 ( V_9 , V_153 , V_2 ) ;
if ( V_19 < 0 )
goto V_140;
if ( V_155 )
V_19 = F_69 ( V_2 , V_9 ) ;
goto V_140;
}
if ( F_58 ( V_150 , V_2 ) ||
F_58 ( V_153 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_153 ,
V_141 ) ;
goto V_140;
}
if ( ! ! V_103 -> V_77 == F_22 ( V_162 , & V_2 -> V_163 ) ) {
V_19 = F_61 ( V_9 , V_153 , V_2 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_153 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
if ( V_103 -> V_77 ) {
V_149 = V_159 ;
} else {
V_149 = 0 ;
if ( F_22 ( V_164 , & V_2 -> V_163 ) &&
V_2 -> V_156 > 0 )
F_63 ( & V_2 -> V_157 ) ;
}
V_19 = F_33 ( V_2 , V_161 , 1 , & V_149 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_76 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( V_103 -> V_77 )
F_36 ( V_71 , & V_2 -> V_53 ) ;
else
F_45 ( V_71 , & V_2 -> V_53 ) ;
V_19 = F_61 ( V_9 , V_165 , V_2 ) ;
if ( V_19 < 0 )
goto V_140;
V_19 = F_69 ( V_2 , V_9 ) ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_77 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
struct V_129 * V_11 ;
T_1 V_77 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( ! ! V_103 -> V_77 != F_22 ( V_73 ,
& V_2 -> V_53 ) ) {
F_72 ( V_73 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_61 ( V_9 , V_166 , V_2 ) ;
if ( V_19 < 0 )
goto V_140;
if ( V_155 )
V_19 = F_69 ( V_2 , V_9 ) ;
goto V_140;
}
if ( F_58 ( V_166 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_166 ,
V_141 ) ;
goto V_140;
}
V_77 = ! ! V_103 -> V_77 ;
if ( F_22 ( V_167 , & V_2 -> V_163 ) == V_77 ) {
V_19 = F_61 ( V_9 , V_166 , V_2 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_166 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
V_19 = F_33 ( V_2 , V_168 , sizeof( V_77 ) , & V_77 ) ;
if ( V_19 < 0 ) {
F_59 ( V_11 ) ;
goto V_140;
}
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_78 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
struct V_129 * V_11 ;
T_1 V_77 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_24 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_169 ,
V_170 ) ;
goto V_140;
}
V_77 = ! ! V_103 -> V_77 ;
if ( ! F_28 ( V_2 ) ) {
bool V_155 = false ;
if ( V_77 != F_22 ( V_74 , & V_2 -> V_53 ) ) {
F_72 ( V_74 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_61 ( V_9 , V_169 , V_2 ) ;
if ( V_19 < 0 )
goto V_140;
if ( V_155 )
V_19 = F_69 ( V_2 , V_9 ) ;
goto V_140;
}
if ( F_58 ( V_169 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_169 ,
V_141 ) ;
goto V_140;
}
if ( F_22 ( V_74 , & V_2 -> V_53 ) == V_77 ) {
V_19 = F_61 ( V_9 , V_169 , V_2 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_169 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
V_19 = F_33 ( V_2 , V_171 , sizeof( V_77 ) , & V_77 ) ;
if ( V_19 < 0 ) {
F_59 ( V_11 ) ;
goto V_140;
}
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_79 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
if ( ! V_66 )
return F_4 ( V_9 , V_2 -> V_54 , V_172 ,
V_170 ) ;
if ( V_103 -> V_77 )
F_36 ( V_75 , & V_2 -> V_53 ) ;
else
F_45 ( V_75 , & V_2 -> V_53 ) ;
return F_61 ( V_9 , V_172 , V_2 ) ;
}
static int F_80 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
struct V_173 V_174 ;
struct V_129 * V_11 ;
int V_19 ;
T_1 V_77 , V_175 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_26 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_176 ,
V_170 ) ;
goto V_177;
}
V_77 = ! ! V_103 -> V_77 ;
V_175 = ! ! ( V_2 -> V_178 [ 0 ] & V_179 ) ;
if ( ! F_28 ( V_2 ) || V_77 == V_175 ) {
bool V_155 = false ;
if ( V_77 != F_22 ( V_72 , & V_2 -> V_53 ) ) {
F_72 ( V_72 , & V_2 -> V_53 ) ;
V_155 = true ;
}
V_19 = F_61 ( V_9 , V_176 , V_2 ) ;
if ( V_19 < 0 )
goto V_177;
if ( V_155 )
V_19 = F_69 ( V_2 , V_9 ) ;
goto V_177;
}
if ( F_58 ( V_176 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_176 ,
V_141 ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_176 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_177;
}
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
if ( V_77 ) {
V_174 . V_180 = V_77 ;
V_174 . V_181 = ! ! ( V_2 -> V_104 [ 6 ] & V_182 ) ;
}
V_19 = F_33 ( V_2 , V_183 , sizeof( V_174 ) ,
& V_174 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_81 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_184 * V_103 = V_29 ;
struct V_129 * V_11 ;
struct V_84 * V_85 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( F_22 ( V_116 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_185 ,
V_141 ) ;
goto V_140;
}
V_85 = F_15 ( sizeof( * V_85 ) , V_20 ) ;
if ( ! V_85 ) {
V_19 = - V_21 ;
goto V_140;
}
memcpy ( V_85 -> V_85 , V_103 -> V_85 , 16 ) ;
V_85 -> V_109 = V_103 -> V_109 ;
F_53 ( & V_85 -> V_131 , & V_2 -> V_186 ) ;
V_19 = F_35 ( V_2 ) ;
if ( V_19 < 0 )
goto V_140;
V_19 = F_32 ( V_2 ) ;
if ( V_19 < 0 )
goto V_140;
if ( ! F_22 ( V_116 , & V_2 -> V_53 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_185 , 0 ,
V_2 -> V_114 , 3 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_185 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static bool F_82 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 ) )
return false ;
if ( ! F_43 ( V_106 , & V_2 -> V_53 ) ) {
F_83 ( & V_2 -> V_119 , V_187 ) ;
return true ;
}
return false ;
}
static int F_84 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_188 * V_103 = V_29 ;
struct V_129 * V_11 ;
struct V_133 * V_134 , * V_135 ;
T_1 V_189 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_19 , V_190 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( F_22 ( V_116 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_191 ,
V_141 ) ;
goto V_177;
}
if ( memcmp ( V_103 -> V_85 , V_189 , 16 ) == 0 ) {
V_19 = F_85 ( V_2 ) ;
if ( F_82 ( V_2 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_191 ,
0 , V_2 -> V_114 , 3 ) ;
goto V_177;
}
goto F_35;
}
V_190 = 0 ;
F_56 (p, n, &hdev->uuids) {
struct V_84 * V_192 = F_57 ( V_134 , struct V_84 , V_131 ) ;
if ( memcmp ( V_192 -> V_85 , V_103 -> V_85 , 16 ) != 0 )
continue;
F_60 ( & V_192 -> V_131 ) ;
F_17 ( V_192 ) ;
V_190 ++ ;
}
if ( V_190 == 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_191 ,
V_151 ) ;
goto V_177;
}
F_35:
V_19 = F_35 ( V_2 ) ;
if ( V_19 < 0 )
goto V_177;
V_19 = F_32 ( V_2 ) ;
if ( V_19 < 0 )
goto V_177;
if ( ! F_22 ( V_116 , & V_2 -> V_53 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_191 , 0 ,
V_2 -> V_114 , 3 ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_191 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_86 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_193 * V_103 = V_29 ;
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( F_22 ( V_116 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_194 ,
V_141 ) ;
goto V_177;
}
V_2 -> V_113 = V_103 -> V_195 ;
V_2 -> V_112 = V_103 -> V_196 ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_194 , 0 ,
V_2 -> V_114 , 3 ) ;
goto V_177;
}
if ( F_39 ( V_106 , & V_2 -> V_53 ) ) {
F_41 ( V_2 ) ;
F_87 ( & V_2 -> V_119 ) ;
F_40 ( V_2 ) ;
F_32 ( V_2 ) ;
}
V_19 = F_35 ( V_2 ) ;
if ( V_19 < 0 )
goto V_177;
if ( ! F_22 ( V_116 , & V_2 -> V_53 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_194 , 0 ,
V_2 -> V_114 , 3 ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_194 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_88 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_197 * V_103 = V_29 ;
T_2 V_198 , V_199 ;
int V_44 ;
V_198 = F_71 ( V_103 -> V_198 ) ;
V_199 = sizeof( * V_103 ) + V_198 *
sizeof( struct V_200 ) ;
if ( V_199 != V_24 ) {
F_89 ( L_7 ,
V_24 , V_199 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_201 ,
V_151 ) ;
}
F_5 ( L_8 , V_2 -> V_111 , V_103 -> V_202 ,
V_198 ) ;
F_40 ( V_2 ) ;
F_90 ( V_2 ) ;
F_36 ( V_203 , & V_2 -> V_53 ) ;
if ( V_103 -> V_202 )
F_36 ( V_204 , & V_2 -> V_53 ) ;
else
F_45 ( V_204 , & V_2 -> V_53 ) ;
for ( V_44 = 0 ; V_44 < V_198 ; V_44 ++ ) {
struct V_200 * V_205 = & V_103 -> V_206 [ V_44 ] ;
F_91 ( V_2 , NULL , 0 , & V_205 -> V_207 . V_122 , V_205 -> V_77 ,
V_205 -> type , V_205 -> V_208 ) ;
}
F_11 ( V_9 , V_2 -> V_54 , V_201 , 0 , NULL , 0 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_209 , struct V_8 * V_144 )
{
struct V_210 V_18 ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = V_209 ;
return F_66 ( V_211 , V_2 , & V_18 , sizeof( V_18 ) ,
V_144 ) ;
}
static int F_93 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_212 * V_103 = V_29 ;
struct V_213 V_25 ;
struct V_214 V_215 ;
struct V_129 * V_11 ;
struct V_216 * V_217 ;
int V_19 ;
F_40 ( V_2 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_47 ( & V_25 . V_207 . V_122 , & V_103 -> V_207 . V_122 ) ;
V_25 . V_207 . type = V_103 -> V_207 . type ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_218 ,
V_152 , & V_25 , sizeof( V_25 ) ) ;
goto V_177;
}
if ( V_103 -> V_207 . type == V_219 )
V_19 = F_94 ( V_2 , & V_103 -> V_207 . V_122 ) ;
else
V_19 = F_95 ( V_2 , & V_103 -> V_207 . V_122 ) ;
if ( V_19 < 0 ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_218 ,
V_220 , & V_25 , sizeof( V_25 ) ) ;
goto V_177;
}
if ( V_103 -> V_221 ) {
if ( V_103 -> V_207 . type == V_219 )
V_217 = F_96 ( V_2 , V_222 ,
& V_103 -> V_207 . V_122 ) ;
else
V_217 = F_96 ( V_2 , V_223 ,
& V_103 -> V_207 . V_122 ) ;
} else {
V_217 = NULL ;
}
if ( ! V_217 ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_218 , 0 ,
& V_25 , sizeof( V_25 ) ) ;
F_92 ( V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type , V_9 ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_218 , V_2 , V_103 ,
sizeof( * V_103 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_177;
}
V_215 . V_224 = F_8 ( V_217 -> V_224 ) ;
V_215 . V_225 = 0x13 ;
V_19 = F_33 ( V_2 , V_226 , sizeof( V_215 ) , & V_215 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int V_221 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_227 * V_103 = V_29 ;
struct V_214 V_215 ;
struct V_129 * V_11 ;
struct V_216 * V_217 ;
int V_19 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
if ( ! F_22 ( V_228 , & V_2 -> V_163 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_229 ,
V_152 ) ;
goto V_140;
}
if ( F_58 ( V_229 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_229 ,
V_141 ) ;
goto V_140;
}
if ( V_103 -> V_207 . type == V_219 )
V_217 = F_96 ( V_2 , V_222 ,
& V_103 -> V_207 . V_122 ) ;
else
V_217 = F_96 ( V_2 , V_223 , & V_103 -> V_207 . V_122 ) ;
if ( ! V_217 || V_217 -> V_230 == V_231 || V_217 -> V_230 == V_232 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_229 ,
V_233 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_229 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
V_215 . V_224 = F_8 ( V_217 -> V_224 ) ;
V_215 . V_225 = V_234 ;
V_19 = F_33 ( V_2 , V_226 , sizeof( V_215 ) , & V_215 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static T_1 F_97 ( T_1 V_235 , T_1 V_209 )
{
switch ( V_235 ) {
case V_223 :
switch ( V_209 ) {
case V_236 :
return V_237 ;
default:
return V_238 ;
}
default:
return V_219 ;
}
}
static int F_98 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_239 * V_25 ;
struct V_216 * V_240 ;
T_3 V_26 ;
int V_19 ;
T_2 V_44 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_241 ,
V_152 ) ;
goto V_177;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_242 , & V_240 -> V_163 ) )
V_44 ++ ;
}
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_243 ) ) ;
V_25 = F_15 ( V_26 , V_20 ) ;
if ( ! V_25 ) {
V_19 = - V_21 ;
goto V_177;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_242 , & V_240 -> V_163 ) )
continue;
F_47 ( & V_25 -> V_207 [ V_44 ] . V_122 , & V_240 -> V_244 ) ;
V_25 -> V_207 [ V_44 ] . type = F_97 ( V_240 -> type , V_240 -> V_245 ) ;
if ( V_240 -> type == V_246 || V_240 -> type == V_247 )
continue;
V_44 ++ ;
}
V_25 -> V_248 = F_8 ( V_44 ) ;
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_243 ) ) ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_241 , 0 , V_25 ,
V_26 ) ;
F_17 ( V_25 ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_99 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_249 * V_103 )
{
struct V_129 * V_11 ;
int V_19 ;
V_11 = F_51 ( V_9 , V_250 , V_2 , V_103 ,
sizeof( * V_103 ) ) ;
if ( ! V_11 )
return - V_21 ;
V_19 = F_33 ( V_2 , V_251 ,
sizeof( V_103 -> V_207 . V_122 ) , & V_103 -> V_207 . V_122 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
return V_19 ;
}
static int F_100 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_216 * V_217 ;
struct V_252 * V_103 = V_29 ;
struct V_253 V_254 ;
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_255 ,
V_152 ) ;
goto V_140;
}
V_217 = F_96 ( V_2 , V_222 , & V_103 -> V_207 . V_122 ) ;
if ( ! V_217 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_255 ,
V_233 ) ;
goto V_140;
}
if ( V_217 -> V_256 == V_257 && V_103 -> V_208 != 16 ) {
struct V_249 V_258 ;
memcpy ( & V_258 . V_207 , & V_103 -> V_207 , sizeof( V_258 . V_207 ) ) ;
F_89 ( L_10 ) ;
V_19 = F_99 ( V_9 , V_2 , & V_258 ) ;
if ( V_19 >= 0 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_255 ,
V_151 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_255 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
F_47 ( & V_254 . V_122 , & V_103 -> V_207 . V_122 ) ;
V_254 . V_208 = V_103 -> V_208 ;
memcpy ( V_254 . V_259 , V_103 -> V_259 , sizeof( V_254 . V_259 ) ) ;
V_19 = F_33 ( V_2 , V_260 , sizeof( V_254 ) , & V_254 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_101 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_261 * V_103 = V_29 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
V_2 -> V_262 = V_103 -> V_262 ;
F_5 ( L_11 , V_2 -> V_111 ,
V_2 -> V_262 ) ;
F_41 ( V_2 ) ;
return F_11 ( V_9 , V_2 -> V_54 , V_263 , 0 , NULL ,
0 ) ;
}
static struct V_129 * F_102 ( struct V_216 * V_217 )
{
struct V_1 * V_2 = V_217 -> V_2 ;
struct V_129 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 != V_264 )
continue;
if ( V_11 -> V_265 != V_217 )
continue;
return V_11 ;
}
return NULL ;
}
static void F_103 ( struct V_129 * V_11 , T_1 V_12 )
{
struct V_266 V_25 ;
struct V_216 * V_217 = V_11 -> V_265 ;
F_47 ( & V_25 . V_207 . V_122 , & V_217 -> V_244 ) ;
V_25 . V_207 . type = F_97 ( V_217 -> type , V_217 -> V_245 ) ;
F_11 ( V_11 -> V_9 , V_11 -> V_10 , V_264 , V_12 ,
& V_25 , sizeof( V_25 ) ) ;
V_217 -> V_267 = NULL ;
V_217 -> V_268 = NULL ;
V_217 -> V_269 = NULL ;
F_104 ( V_217 ) ;
F_59 ( V_11 ) ;
}
static void F_105 ( struct V_216 * V_217 , T_1 V_12 )
{
struct V_129 * V_11 ;
F_5 ( L_12 , V_12 ) ;
V_11 = F_102 ( V_217 ) ;
if ( ! V_11 )
F_5 ( L_13 ) ;
else
F_103 ( V_11 , F_2 ( V_12 ) ) ;
}
static void F_106 ( struct V_216 * V_217 , T_1 V_12 )
{
struct V_129 * V_11 ;
F_5 ( L_12 , V_12 ) ;
if ( ! V_12 )
return;
V_11 = F_102 ( V_217 ) ;
if ( ! V_11 )
F_5 ( L_13 ) ;
else
F_103 ( V_11 , F_2 ( V_12 ) ) ;
}
static int F_107 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_270 * V_103 = V_29 ;
struct V_266 V_25 ;
struct V_129 * V_11 ;
T_1 V_271 , V_272 ;
struct V_216 * V_217 ;
int V_19 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_264 ,
V_152 ) ;
goto V_177;
}
V_271 = V_273 ;
if ( V_103 -> V_274 == 0x03 )
V_272 = V_275 ;
else
V_272 = V_276 ;
if ( V_103 -> V_207 . type == V_219 )
V_217 = F_108 ( V_2 , V_222 , & V_103 -> V_207 . V_122 ,
V_103 -> V_207 . type , V_271 , V_272 ) ;
else
V_217 = F_108 ( V_2 , V_223 , & V_103 -> V_207 . V_122 ,
V_103 -> V_207 . type , V_271 , V_272 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_47 ( & V_25 . V_207 . V_122 , & V_103 -> V_207 . V_122 ) ;
V_25 . V_207 . type = V_103 -> V_207 . type ;
if ( F_109 ( V_217 ) ) {
int V_12 ;
if ( F_110 ( V_217 ) == - V_277 )
V_12 = V_141 ;
else
V_12 = V_278 ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_264 ,
V_12 , & V_25 ,
sizeof( V_25 ) ) ;
goto V_177;
}
if ( V_217 -> V_267 ) {
F_104 ( V_217 ) ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_264 ,
V_141 , & V_25 , sizeof( V_25 ) ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_264 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
F_104 ( V_217 ) ;
goto V_177;
}
if ( V_103 -> V_207 . type == V_219 )
V_217 -> V_267 = F_105 ;
else
V_217 -> V_267 = F_106 ;
V_217 -> V_268 = F_105 ;
V_217 -> V_269 = F_105 ;
V_217 -> V_262 = V_103 -> V_274 ;
V_11 -> V_265 = V_217 ;
if ( V_217 -> V_230 == V_279 &&
F_111 ( V_217 , V_271 , V_272 ) )
F_103 ( V_11 , 0 ) ;
V_19 = 0 ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_112 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_243 * V_207 = V_29 ;
struct V_129 * V_11 ;
struct V_216 * V_217 ;
int V_19 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_280 ,
V_152 ) ;
goto V_177;
}
V_11 = F_58 ( V_264 , V_2 ) ;
if ( ! V_11 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_280 ,
V_151 ) ;
goto V_177;
}
V_217 = V_11 -> V_265 ;
if ( F_113 ( & V_207 -> V_122 , & V_217 -> V_244 ) != 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_280 ,
V_151 ) ;
goto V_177;
}
F_103 ( V_11 , V_281 ) ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_280 , 0 ,
V_207 , sizeof( * V_207 ) ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_114 ( struct V_8 * V_9 , struct V_1 * V_2 ,
T_7 * V_122 , T_1 type , T_2 V_282 ,
T_2 V_283 , T_6 V_284 )
{
struct V_129 * V_11 ;
struct V_216 * V_217 ;
int V_19 ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_282 ,
V_152 ) ;
goto V_285;
}
if ( type == V_219 )
V_217 = F_96 ( V_2 , V_222 , V_122 ) ;
else
V_217 = F_96 ( V_2 , V_223 , V_122 ) ;
if ( ! V_217 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_282 ,
V_233 ) ;
goto V_285;
}
if ( type == V_237 || type == V_238 ) {
V_19 = F_115 ( V_217 , V_282 , V_284 ) ;
if ( ! V_19 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_282 ,
V_286 ) ;
else
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_282 ,
V_7 ) ;
goto V_285;
}
V_11 = F_51 ( V_9 , V_282 , V_2 , V_122 , sizeof( * V_122 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_285;
}
if ( V_283 == V_287 ) {
struct V_288 V_103 ;
F_47 ( & V_103 . V_122 , V_122 ) ;
V_103 . V_284 = V_284 ;
V_19 = F_33 ( V_2 , V_283 , sizeof( V_103 ) , & V_103 ) ;
} else
V_19 = F_33 ( V_2 , V_283 , sizeof( * V_122 ) , V_122 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_285:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_116 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_249 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_114 ( V_9 , V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ,
V_250 ,
V_251 , 0 ) ;
}
static int F_117 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_289 * V_103 = V_29 ;
F_5 ( L_9 ) ;
if ( V_24 != sizeof( * V_103 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_290 ,
V_151 ) ;
return F_114 ( V_9 , V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ,
V_290 ,
V_291 , 0 ) ;
}
static int F_118 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_292 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_114 ( V_9 , V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ,
V_293 ,
V_294 , 0 ) ;
}
static int F_119 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_295 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_114 ( V_9 , V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ,
V_296 ,
V_287 , V_103 -> V_284 ) ;
}
static int F_120 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_297 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_114 ( V_9 , V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ,
V_298 ,
V_299 , 0 ) ;
}
static int F_121 ( struct V_1 * V_2 , const char * V_111 )
{
struct V_300 V_103 ;
memcpy ( V_103 . V_111 , V_111 , sizeof( V_103 . V_111 ) ) ;
return F_33 ( V_2 , V_301 , sizeof( V_103 ) , & V_103 ) ;
}
static int F_122 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_302 * V_103 = V_29 ;
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_9 ) ;
F_40 ( V_2 ) ;
memcpy ( V_2 -> V_127 , V_103 -> V_127 , sizeof( V_2 -> V_127 ) ) ;
if ( ! F_28 ( V_2 ) ) {
memcpy ( V_2 -> V_87 , V_103 -> V_111 , sizeof( V_2 -> V_87 ) ) ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_303 , 0 ,
V_29 , V_24 ) ;
if ( V_19 < 0 )
goto V_140;
V_19 = F_66 ( V_304 , V_2 , V_29 , V_24 ,
V_9 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_303 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
V_19 = F_121 ( V_2 , V_103 -> V_111 ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_123 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_305 ,
V_152 ) ;
goto V_177;
}
if ( ! F_24 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_305 ,
V_170 ) ;
goto V_177;
}
if ( F_58 ( V_305 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_305 ,
V_141 ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_305 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_177;
}
V_19 = F_33 ( V_2 , V_306 , 0 , NULL ) ;
if ( V_19 < 0 )
F_59 ( V_11 ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_124 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_307 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_14 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_308 ,
V_152 , & V_103 -> V_207 ,
sizeof( V_103 -> V_207 ) ) ;
goto V_177;
}
V_19 = F_125 ( V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_309 ,
V_103 -> V_310 ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = 0 ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_308 , V_12 ,
& V_103 -> V_207 , sizeof( V_103 -> V_207 ) ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_126 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_311 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 ,
V_312 ,
V_152 , & V_103 -> V_207 ,
sizeof( V_103 -> V_207 ) ) ;
goto V_177;
}
V_19 = F_127 ( V_2 , & V_103 -> V_207 . V_122 ) ;
if ( V_19 < 0 )
V_12 = V_151 ;
else
V_12 = 0 ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_312 ,
V_12 , & V_103 -> V_207 , sizeof( V_103 -> V_207 ) ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
int F_128 ( struct V_1 * V_2 )
{
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
V_19 = F_129 ( V_2 , V_313 ) ;
if ( V_19 < 0 )
F_130 ( V_2 , V_314 ) ;
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_131 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_315 * V_103 = V_29 ;
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_316 ,
V_152 ) ;
goto V_140;
}
if ( F_22 ( V_317 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_316 ,
V_141 ) ;
goto V_140;
}
if ( V_2 -> V_318 . V_230 != V_314 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_316 ,
V_141 ) ;
goto V_140;
}
V_11 = F_51 ( V_9 , V_316 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_140;
}
V_2 -> V_318 . type = V_103 -> type ;
switch ( V_2 -> V_318 . type ) {
case V_319 :
if ( F_25 ( V_2 ) )
V_19 = F_129 ( V_2 , V_320 ) ;
else
V_19 = - V_321 ;
break;
case V_322 :
if ( F_132 ( V_2 ) )
V_19 = F_133 ( V_2 , V_323 , V_324 ,
V_325 , V_326 ) ;
else
V_19 = - V_321 ;
break;
case V_327 :
if ( F_132 ( V_2 ) && F_25 ( V_2 ) )
V_19 = F_133 ( V_2 , V_323 , V_324 ,
V_325 ,
V_328 ) ;
else
V_19 = - V_321 ;
break;
default:
V_19 = - V_329 ;
}
if ( V_19 < 0 )
F_59 ( V_11 ) ;
else
F_130 ( V_2 , V_330 ) ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_134 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_331 * V_332 = V_29 ;
struct V_129 * V_11 ;
struct V_333 V_103 ;
struct V_334 * V_335 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_135 ( V_2 ) ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_336 ,
V_154 , & V_332 -> type ,
sizeof( V_332 -> type ) ) ;
goto V_177;
}
if ( V_2 -> V_318 . type != V_332 -> type ) {
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_336 ,
V_151 , & V_332 -> type ,
sizeof( V_332 -> type ) ) ;
goto V_177;
}
V_11 = F_51 ( V_9 , V_336 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_177;
}
switch ( V_2 -> V_318 . V_230 ) {
case V_337 :
if ( F_22 ( V_338 , & V_2 -> V_163 ) )
V_19 = F_136 ( V_2 ) ;
else
V_19 = F_137 ( V_2 ) ;
break;
case V_339 :
V_335 = F_138 ( V_2 , V_340 ,
V_341 ) ;
if ( ! V_335 ) {
F_59 ( V_11 ) ;
V_19 = F_11 ( V_9 , V_2 -> V_54 ,
V_336 , 0 ,
& V_332 -> type ,
sizeof( V_332 -> type ) ) ;
F_130 ( V_2 , V_314 ) ;
goto V_177;
}
F_47 ( & V_103 . V_122 , & V_335 -> V_29 . V_122 ) ;
V_19 = F_33 ( V_2 , V_342 ,
sizeof( V_103 ) , & V_103 ) ;
break;
default:
F_5 ( L_15 , V_2 -> V_318 . V_230 ) ;
V_19 = - V_343 ;
}
if ( V_19 < 0 )
F_59 ( V_11 ) ;
else
F_130 ( V_2 , V_344 ) ;
V_177:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_139 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_345 * V_103 = V_29 ;
struct V_334 * V_335 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
if ( ! F_135 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_346 ,
V_7 ) ;
goto V_140;
}
V_335 = F_140 ( V_2 , & V_103 -> V_207 . V_122 ) ;
if ( ! V_335 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_346 ,
V_151 ) ;
goto V_140;
}
if ( V_103 -> V_347 ) {
V_335 -> V_348 = V_349 ;
F_60 ( & V_335 -> V_131 ) ;
} else {
V_335 -> V_348 = V_350 ;
F_141 ( V_2 , V_335 ) ;
}
V_19 = 0 ;
V_140:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_142 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_351 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
V_19 = F_143 ( V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = 0 ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_352 , V_12 ,
& V_103 -> V_207 , sizeof( V_103 -> V_207 ) ) ;
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_144 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_353 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_40 ( V_2 ) ;
V_19 = F_145 ( V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type ) ;
if ( V_19 < 0 )
V_12 = V_151 ;
else
V_12 = 0 ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_354 , V_12 ,
& V_103 -> V_207 , sizeof( V_103 -> V_207 ) ) ;
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_146 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_355 * V_103 = V_29 ;
int V_19 ;
T_8 V_356 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
V_356 = F_71 ( V_103 -> V_356 ) ;
if ( V_356 > 0x0002 )
return F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_151 ) ;
F_40 ( V_2 ) ;
V_2 -> V_92 = V_356 ;
V_2 -> V_94 = F_71 ( V_103 -> V_358 ) ;
V_2 -> V_95 = F_71 ( V_103 -> V_359 ) ;
V_2 -> V_96 = F_71 ( V_103 -> V_32 ) ;
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_357 , 0 , NULL , 0 ) ;
F_32 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_147 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_136 * V_103 = V_29 ;
struct V_360 V_361 ;
T_1 type ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
if ( ! F_28 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_362 ,
V_152 ) ;
if ( ! F_22 ( V_69 , & V_2 -> V_53 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_362 ,
V_154 ) ;
F_40 ( V_2 ) ;
if ( V_103 -> V_77 ) {
type = V_363 ;
V_361 . V_364 = F_13 ( 0x0100 ) ;
} else {
type = V_365 ;
V_361 . V_364 = F_13 ( 0x0800 ) ;
}
V_361 . V_366 = F_13 ( 0x0012 ) ;
V_19 = F_33 ( V_2 , V_367 , sizeof( V_361 ) ,
& V_361 ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_362 ,
V_7 ) ;
goto V_285;
}
V_19 = F_33 ( V_2 , V_368 , 1 , & type ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_362 ,
V_7 ) ;
goto V_285;
}
V_19 = F_11 ( V_9 , V_2 -> V_54 , V_362 , 0 ,
NULL , 0 ) ;
V_285:
F_41 ( V_2 ) ;
return V_19 ;
}
static int F_148 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_369 , T_2 V_24 )
{
struct V_370 * V_103 = V_369 ;
T_2 V_198 , V_199 ;
int V_44 ;
V_198 = F_71 ( V_103 -> V_198 ) ;
V_199 = sizeof( * V_103 ) + V_198 *
sizeof( struct V_371 ) ;
if ( V_199 != V_24 ) {
F_89 ( L_16 ,
V_24 , V_199 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_372 ,
V_329 ) ;
}
F_5 ( L_17 , V_2 -> V_111 , V_198 ) ;
F_40 ( V_2 ) ;
F_149 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_198 ; V_44 ++ ) {
struct V_371 * V_205 = & V_103 -> V_206 [ V_44 ] ;
T_1 type ;
if ( V_205 -> V_373 )
type = V_374 ;
else
type = V_375 ;
F_150 ( V_2 , & V_205 -> V_207 . V_122 ,
F_151 ( V_205 -> V_207 . type ) ,
type , 0 , V_205 -> V_376 , V_205 -> V_77 ,
V_205 -> V_377 , V_205 -> V_378 , V_205 -> rand ) ;
}
F_41 ( V_2 ) ;
return 0 ;
}
int F_152 ( struct V_8 * V_9 , struct V_379 * V_380 , T_3 V_381 )
{
void * V_382 ;
T_1 * V_103 ;
struct V_15 * V_16 ;
T_2 V_22 , V_10 , V_24 ;
struct V_1 * V_2 = NULL ;
const struct V_383 * V_384 ;
int V_19 ;
F_5 ( L_18 , V_381 ) ;
if ( V_381 < sizeof( * V_16 ) )
return - V_329 ;
V_382 = F_15 ( V_381 , V_20 ) ;
if ( ! V_382 )
return - V_21 ;
if ( F_153 ( V_382 , V_380 -> V_385 , V_381 ) ) {
V_19 = - V_343 ;
goto V_285;
}
V_16 = V_382 ;
V_22 = F_71 ( V_16 -> V_22 ) ;
V_10 = F_71 ( V_16 -> V_10 ) ;
V_24 = F_71 ( V_16 -> V_24 ) ;
if ( V_24 != V_381 - sizeof( * V_16 ) ) {
V_19 = - V_329 ;
goto V_285;
}
if ( V_10 != V_36 ) {
V_2 = F_154 ( V_10 ) ;
if ( ! V_2 ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_386 ) ;
goto V_285;
}
}
if ( V_22 >= F_3 ( V_387 ) ||
V_387 [ V_22 ] . V_388 == NULL ) {
F_5 ( L_19 , V_22 ) ;
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_389 ) ;
goto V_285;
}
if ( ( V_2 && V_22 < V_128 ) ||
( ! V_2 && V_22 >= V_128 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_386 ) ;
goto V_285;
}
V_384 = & V_387 [ V_22 ] ;
if ( ( V_384 -> V_390 && V_24 < V_384 -> V_30 ) ||
( ! V_384 -> V_390 && V_24 != V_384 -> V_30 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_151 ) ;
goto V_285;
}
if ( V_2 )
F_42 ( V_9 , V_2 ) ;
V_103 = V_382 + sizeof( * V_16 ) ;
V_19 = V_384 -> V_388 ( V_9 , V_2 , V_103 , V_24 ) ;
if ( V_19 < 0 )
goto V_285;
V_19 = V_381 ;
V_285:
if ( V_2 )
F_155 ( V_2 ) ;
F_17 ( V_382 ) ;
return V_19 ;
}
static void F_156 ( struct V_129 * V_11 , void * V_29 )
{
T_1 * V_12 = V_29 ;
F_4 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , * V_12 ) ;
F_59 ( V_11 ) ;
}
int F_157 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return - V_321 ;
return F_66 ( V_391 , V_2 , NULL , 0 , NULL ) ;
}
int F_158 ( struct V_1 * V_2 )
{
T_1 V_12 = V_386 ;
if ( ! F_1 ( V_2 ) )
return - V_321 ;
F_54 ( 0 , V_2 , F_156 , & V_12 ) ;
return F_66 ( V_392 , V_2 , NULL , 0 , NULL ) ;
}
static void F_159 ( struct V_129 * V_11 , void * V_29 )
{
struct V_393 * V_192 = V_29 ;
F_61 ( V_11 -> V_9 , V_11 -> V_22 , V_192 -> V_2 ) ;
F_60 ( & V_11 -> V_131 ) ;
if ( V_192 -> V_9 == NULL ) {
V_192 -> V_9 = V_11 -> V_9 ;
F_52 ( V_192 -> V_9 ) ;
}
F_49 ( V_11 ) ;
}
int F_64 ( struct V_1 * V_2 , T_1 V_394 )
{
struct V_393 V_192 = { NULL , V_2 } ;
int V_19 ;
if ( ! F_22 ( V_120 , & V_2 -> V_53 ) )
return 0 ;
F_54 ( V_139 , V_2 , F_159 , & V_192 ) ;
if ( V_394 ) {
T_1 V_149 = 0 ;
if ( F_22 ( V_69 , & V_2 -> V_53 ) )
V_149 |= V_159 ;
if ( F_22 ( V_70 , & V_2 -> V_53 ) )
V_149 |= V_160 ;
if ( V_149 )
F_33 ( V_2 , V_161 , 1 , & V_149 ) ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) ) {
T_1 V_395 = 1 ;
F_33 ( V_2 , V_171 , 1 , & V_395 ) ;
}
if ( F_22 ( V_72 , & V_2 -> V_53 ) ) {
struct V_173 V_103 ;
V_103 . V_180 = 1 ;
V_103 . V_181 = ! ! ( V_2 -> V_104 [ 6 ] & V_182 ) ;
F_33 ( V_2 , V_183 ,
sizeof( V_103 ) , & V_103 ) ;
}
F_35 ( V_2 ) ;
F_121 ( V_2 , V_2 -> V_87 ) ;
F_32 ( V_2 ) ;
} else {
T_1 V_12 = V_152 ;
F_54 ( 0 , V_2 , F_156 , & V_12 ) ;
}
V_19 = F_69 ( V_2 , V_192 . V_9 ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
return V_19 ;
}
int F_160 ( struct V_1 * V_2 , T_1 V_396 )
{
struct V_393 V_192 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_396 ) {
if ( ! F_43 ( V_70 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_39 ( V_70 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_54 ( V_150 , V_2 , F_159 ,
& V_192 ) ;
if ( V_155 )
V_19 = F_69 ( V_2 , V_192 . V_9 ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
return V_19 ;
}
int F_161 ( struct V_1 * V_2 , T_1 V_397 )
{
struct V_393 V_192 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_397 ) {
if ( ! F_43 ( V_69 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_39 ( V_69 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_54 ( V_153 , V_2 , F_159 ,
& V_192 ) ;
if ( V_155 )
V_19 = F_69 ( V_2 , V_192 . V_9 ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
return V_19 ;
}
int F_162 ( struct V_1 * V_2 , T_1 V_149 , T_1 V_12 )
{
T_1 V_398 = F_2 ( V_12 ) ;
if ( V_149 & V_159 )
F_54 ( V_153 , V_2 ,
F_156 , & V_398 ) ;
if ( V_149 & V_160 )
F_54 ( V_150 , V_2 ,
F_156 , & V_398 ) ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , struct V_399 * V_205 ,
bool V_400 )
{
struct V_401 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_402 = V_400 ;
F_47 ( & V_18 . V_205 . V_207 . V_122 , & V_205 -> V_122 ) ;
V_18 . V_205 . V_207 . type = V_219 ;
V_18 . V_205 . type = V_205 -> type ;
memcpy ( V_18 . V_205 . V_77 , V_205 -> V_77 , V_403 ) ;
V_18 . V_205 . V_208 = V_205 -> V_208 ;
return F_66 ( V_404 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_164 ( struct V_1 * V_2 , struct V_405 * V_205 , T_1 V_400 )
{
struct V_406 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_402 = V_400 ;
F_47 ( & V_18 . V_205 . V_207 . V_122 , & V_205 -> V_122 ) ;
V_18 . V_205 . V_207 . type = F_97 ( V_223 , V_205 -> V_407 ) ;
V_18 . V_205 . V_376 = V_205 -> V_376 ;
V_18 . V_205 . V_377 = V_205 -> V_377 ;
V_18 . V_205 . V_378 = V_205 -> V_378 ;
if ( V_205 -> type == V_374 )
V_18 . V_205 . V_373 = 1 ;
memcpy ( V_18 . V_205 . rand , V_205 -> rand , sizeof( V_205 -> rand ) ) ;
memcpy ( V_18 . V_205 . V_77 , V_205 -> V_77 , sizeof( V_205 -> V_77 ) ) ;
return F_66 ( V_408 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_165 ( struct V_1 * V_2 , T_7 * V_122 , T_1 V_235 ,
T_1 V_209 , T_5 V_163 , T_1 * V_111 , T_1 V_86 ,
T_1 * V_114 )
{
char V_382 [ 512 ] ;
struct V_409 * V_18 = ( void * ) V_382 ;
T_2 V_80 = 0 ;
F_47 ( & V_18 -> V_207 . V_122 , V_122 ) ;
V_18 -> V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 -> V_163 = F_166 ( V_163 ) ;
if ( V_86 > 0 )
V_80 = F_167 ( V_18 -> V_107 , 0 , V_89 ,
V_111 , V_86 ) ;
if ( V_114 && memcmp ( V_114 , L_20 , 3 ) != 0 )
V_80 = F_167 ( V_18 -> V_107 , V_80 ,
V_410 , V_114 , 3 ) ;
V_18 -> V_80 = F_8 ( V_80 ) ;
return F_66 ( V_411 , V_2 , V_382 ,
sizeof( * V_18 ) + V_80 , NULL ) ;
}
static void F_168 ( struct V_129 * V_11 , void * V_29 )
{
struct V_227 * V_103 = V_11 -> V_130 ;
struct V_8 * * V_9 = V_29 ;
struct V_412 V_25 ;
F_47 ( & V_25 . V_207 . V_122 , & V_103 -> V_207 . V_122 ) ;
V_25 . V_207 . type = V_103 -> V_207 . type ;
F_11 ( V_11 -> V_9 , V_11 -> V_10 , V_229 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
* V_9 = V_11 -> V_9 ;
F_52 ( * V_9 ) ;
F_59 ( V_11 ) ;
}
static void F_169 ( struct V_129 * V_11 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_212 * V_103 = V_11 -> V_130 ;
struct V_213 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_47 ( & V_25 . V_207 . V_122 , & V_103 -> V_207 . V_122 ) ;
V_25 . V_207 . type = V_103 -> V_207 . type ;
F_92 ( V_2 , & V_103 -> V_207 . V_122 , V_103 -> V_207 . type , V_11 -> V_9 ) ;
F_11 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , 0 , & V_25 , sizeof( V_25 ) ) ;
F_59 ( V_11 ) ;
}
int F_170 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_225 )
{
struct V_413 V_18 ;
struct V_8 * V_9 = NULL ;
int V_19 ;
F_54 ( V_229 , V_2 , F_168 , & V_9 ) ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 . V_225 = V_225 ;
V_19 = F_66 ( V_414 , V_2 , & V_18 , sizeof( V_18 ) ,
V_9 ) ;
if ( V_9 )
F_50 ( V_9 ) ;
F_54 ( V_218 , V_2 , F_169 ,
V_2 ) ;
return V_19 ;
}
int F_171 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_12 )
{
struct V_412 V_25 ;
struct V_129 * V_11 ;
int V_19 ;
V_11 = F_58 ( V_229 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_47 ( & V_25 . V_207 . V_122 , V_122 ) ;
V_25 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_19 = F_11 ( V_11 -> V_9 , V_11 -> V_10 , V_229 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_59 ( V_11 ) ;
F_54 ( V_218 , V_2 , F_169 ,
V_2 ) ;
return V_19 ;
}
int F_172 ( struct V_1 * V_2 , T_7 * V_122 , T_1 V_235 ,
T_1 V_209 , T_1 V_12 )
{
struct V_416 V_18 ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_66 ( V_417 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_173 ( struct V_1 * V_2 , T_7 * V_122 , T_1 V_418 )
{
struct V_419 V_18 ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = V_219 ;
V_18 . V_418 = V_418 ;
return F_66 ( V_420 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_174 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_12 )
{
struct V_129 * V_11 ;
struct V_421 V_25 ;
int V_19 ;
V_11 = F_58 ( V_255 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_47 ( & V_25 . V_207 . V_122 , V_122 ) ;
V_25 . V_207 . type = V_219 ;
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_255 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_59 ( V_11 ) ;
return V_19 ;
}
int F_175 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_12 )
{
struct V_129 * V_11 ;
struct V_421 V_25 ;
int V_19 ;
V_11 = F_58 ( V_250 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_47 ( & V_25 . V_207 . V_122 , V_122 ) ;
V_25 . V_207 . type = V_219 ;
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_250 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_59 ( V_11 ) ;
return V_19 ;
}
int F_176 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_6 V_422 ,
T_1 V_423 )
{
struct V_424 V_18 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 . V_423 = V_423 ;
V_18 . V_422 = V_422 ;
return F_66 ( V_425 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_177 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 )
{
struct V_426 V_18 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = F_97 ( V_235 , V_209 ) ;
return F_66 ( V_427 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
static int F_178 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_12 ,
T_1 V_22 )
{
struct V_129 * V_11 ;
struct V_428 V_25 ;
int V_19 ;
V_11 = F_58 ( V_22 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_47 ( & V_25 . V_207 . V_122 , V_122 ) ;
V_25 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_22 , F_2 ( V_12 ) ,
& V_25 , sizeof( V_25 ) ) ;
F_59 ( V_11 ) ;
return V_19 ;
}
int F_179 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_12 )
{
return F_178 ( V_2 , V_122 , V_235 , V_209 ,
V_12 , V_290 ) ;
}
int F_180 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_12 )
{
return F_178 ( V_2 , V_122 , V_235 , V_209 ,
V_12 ,
V_293 ) ;
}
int F_181 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_12 )
{
return F_178 ( V_2 , V_122 , V_235 , V_209 ,
V_12 , V_296 ) ;
}
int F_182 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_1 V_12 )
{
return F_178 ( V_2 , V_122 , V_235 , V_209 ,
V_12 ,
V_298 ) ;
}
int F_183 ( struct V_1 * V_2 , T_7 * V_122 ,
T_1 V_235 , T_1 V_209 , T_5 V_284 ,
T_1 V_429 )
{
struct V_430 V_18 ;
F_5 ( L_4 , V_2 -> V_111 ) ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 . V_284 = F_166 ( V_284 ) ;
V_18 . V_429 = V_429 ;
return F_66 ( V_431 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_184 ( struct V_1 * V_2 , T_7 * V_122 , T_1 V_235 ,
T_1 V_209 , T_1 V_12 )
{
struct V_432 V_18 ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_66 ( V_433 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_185 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_393 V_192 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_398 = F_2 ( V_12 ) ;
F_54 ( V_166 , V_2 ,
F_156 , & V_398 ) ;
return 0 ;
}
if ( F_22 ( V_167 , & V_2 -> V_163 ) ) {
if ( ! F_43 ( V_73 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_39 ( V_73 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_54 ( V_166 , V_2 , F_159 ,
& V_192 ) ;
if ( V_155 )
V_19 = F_69 ( V_2 , V_192 . V_9 ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
return V_19 ;
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_102 V_103 ;
if ( ! ( V_2 -> V_104 [ 6 ] & V_105 ) )
return 0 ;
memset ( V_2 -> V_107 , 0 , sizeof( V_2 -> V_107 ) ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
return F_33 ( V_2 , V_108 , sizeof( V_103 ) , & V_103 ) ;
}
int F_187 ( struct V_1 * V_2 , T_1 V_434 , T_1 V_12 )
{
struct V_393 V_192 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_398 = F_2 ( V_12 ) ;
if ( V_434 && F_39 ( V_74 ,
& V_2 -> V_53 ) )
V_19 = F_69 ( V_2 , NULL ) ;
F_54 ( V_169 , V_2 , F_156 ,
& V_398 ) ;
return V_19 ;
}
if ( V_434 ) {
if ( ! F_43 ( V_74 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_39 ( V_74 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_54 ( V_169 , V_2 , F_159 , & V_192 ) ;
if ( V_155 )
V_19 = F_69 ( V_2 , V_192 . V_9 ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) )
F_32 ( V_2 ) ;
else
F_186 ( V_2 ) ;
return V_19 ;
}
static void F_188 ( struct V_129 * V_11 , void * V_29 )
{
struct V_393 * V_192 = V_29 ;
F_11 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , V_192 -> F_2 ,
V_192 -> V_2 -> V_114 , 3 ) ;
F_60 ( & V_11 -> V_131 ) ;
if ( V_192 -> V_9 == NULL ) {
V_192 -> V_9 = V_11 -> V_9 ;
F_52 ( V_192 -> V_9 ) ;
}
F_49 ( V_11 ) ;
}
int F_189 ( struct V_1 * V_2 , T_1 * V_114 ,
T_1 V_12 )
{
struct V_393 V_192 = { NULL , V_2 , F_2 (status) } ;
int V_19 = 0 ;
F_45 ( V_116 , & V_2 -> V_53 ) ;
F_54 ( V_194 , V_2 , F_188 , & V_192 ) ;
F_54 ( V_185 , V_2 , F_188 , & V_192 ) ;
F_54 ( V_191 , V_2 , F_188 , & V_192 ) ;
if ( ! V_12 )
V_19 = F_66 ( V_435 , V_2 , V_114 ,
3 , NULL ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
return V_19 ;
}
int F_190 ( struct V_1 * V_2 , T_1 * V_111 , T_1 V_12 )
{
struct V_129 * V_11 ;
struct V_302 V_18 ;
bool V_155 = false ;
int V_19 = 0 ;
if ( memcmp ( V_111 , V_2 -> V_87 , sizeof( V_2 -> V_87 ) ) != 0 ) {
memcpy ( V_2 -> V_87 , V_111 , sizeof( V_2 -> V_87 ) ) ;
V_155 = true ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memcpy ( V_18 . V_111 , V_111 , V_436 ) ;
memcpy ( V_18 . V_127 , V_2 -> V_127 , V_437 ) ;
V_11 = F_58 ( V_303 , V_2 ) ;
if ( ! V_11 )
goto V_438;
V_155 = true ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_303 ,
F_2 ( V_12 ) ) ;
goto V_140;
}
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_303 , 0 , & V_18 ,
sizeof( V_18 ) ) ;
if ( V_19 < 0 )
goto V_140;
V_438:
if ( V_155 )
V_19 = F_66 ( V_304 , V_2 , & V_18 ,
sizeof( V_18 ) , V_11 ? V_11 -> V_9 : NULL ) ;
F_32 ( V_2 ) ;
V_140:
if ( V_11 )
F_59 ( V_11 ) ;
return V_19 ;
}
int F_191 ( struct V_1 * V_2 , T_1 * V_309 ,
T_1 * V_310 , T_1 V_12 )
{
struct V_129 * V_11 ;
int V_19 ;
F_5 ( L_21 , V_2 -> V_111 , V_12 ) ;
V_11 = F_58 ( V_305 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_305 ,
F_2 ( V_12 ) ) ;
} else {
struct V_439 V_25 ;
memcpy ( V_25 . V_309 , V_309 , sizeof( V_25 . V_309 ) ) ;
memcpy ( V_25 . V_310 , V_310 , sizeof( V_25 . V_310 ) ) ;
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 ,
V_305 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
F_59 ( V_11 ) ;
return V_19 ;
}
int F_192 ( struct V_1 * V_2 , T_1 V_434 , T_1 V_12 )
{
struct V_393 V_192 = { NULL , V_2 } ;
bool V_155 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_398 = F_2 ( V_12 ) ;
if ( V_434 && F_39 ( V_72 ,
& V_2 -> V_53 ) )
V_19 = F_69 ( V_2 , NULL ) ;
F_54 ( V_176 , V_2 , F_156 ,
& V_398 ) ;
return V_19 ;
}
if ( V_434 ) {
if ( ! F_43 ( V_72 , & V_2 -> V_53 ) )
V_155 = true ;
} else {
if ( F_39 ( V_72 , & V_2 -> V_53 ) )
V_155 = true ;
}
F_54 ( V_176 , V_2 , F_159 , & V_192 ) ;
if ( V_155 )
V_19 = F_69 ( V_2 , V_192 . V_9 ) ;
if ( V_192 . V_9 )
F_50 ( V_192 . V_9 ) ;
return V_19 ;
}
int F_193 ( struct V_1 * V_2 , T_7 * V_122 , T_1 V_235 ,
T_1 V_209 , T_1 * V_114 , T_9 V_440 , T_1 V_441 , T_1
V_395 , T_1 * V_107 , T_2 V_80 )
{
char V_382 [ 512 ] ;
struct V_442 * V_18 = ( void * ) V_382 ;
T_3 V_443 ;
if ( sizeof( * V_18 ) + V_80 + 5 > sizeof( V_382 ) )
return - V_329 ;
memset ( V_382 , 0 , sizeof( V_382 ) ) ;
F_47 ( & V_18 -> V_207 . V_122 , V_122 ) ;
V_18 -> V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 -> V_440 = V_440 ;
if ( V_441 )
V_18 -> V_163 |= F_48 ( V_444 ) ;
if ( ! V_395 )
V_18 -> V_163 |= F_48 ( V_445 ) ;
if ( V_80 > 0 )
memcpy ( V_18 -> V_107 , V_107 , V_80 ) ;
if ( V_114 && ! F_194 ( V_18 -> V_107 , V_80 , V_410 ) )
V_80 = F_167 ( V_18 -> V_107 , V_80 , V_410 ,
V_114 , 3 ) ;
V_18 -> V_80 = F_8 ( V_80 ) ;
V_443 = sizeof( * V_18 ) + V_80 ;
return F_66 ( V_446 , V_2 , V_18 , V_443 , NULL ) ;
}
int F_195 ( struct V_1 * V_2 , T_7 * V_122 , T_1 V_235 ,
T_1 V_209 , T_9 V_440 , T_1 * V_111 , T_1 V_86 )
{
struct V_442 * V_18 ;
char V_382 [ sizeof( * V_18 ) + V_436 + 2 ] ;
T_2 V_80 ;
V_18 = (struct V_442 * ) V_382 ;
memset ( V_382 , 0 , sizeof( V_382 ) ) ;
F_47 ( & V_18 -> V_207 . V_122 , V_122 ) ;
V_18 -> V_207 . type = F_97 ( V_235 , V_209 ) ;
V_18 -> V_440 = V_440 ;
V_80 = F_167 ( V_18 -> V_107 , 0 , V_89 , V_111 ,
V_86 ) ;
V_18 -> V_80 = F_8 ( V_80 ) ;
return F_66 ( V_446 , V_2 , V_18 ,
sizeof( * V_18 ) + V_80 , NULL ) ;
}
int F_196 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_129 * V_11 ;
T_1 type ;
int V_19 ;
F_130 ( V_2 , V_314 ) ;
V_11 = F_58 ( V_316 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
type = V_2 -> V_318 . type ;
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& type , sizeof( type ) ) ;
F_59 ( V_11 ) ;
return V_19 ;
}
int F_197 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_129 * V_11 ;
int V_19 ;
V_11 = F_58 ( V_336 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
V_19 = F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& V_2 -> V_318 . type , sizeof( V_2 -> V_318 . type ) ) ;
F_59 ( V_11 ) ;
return V_19 ;
}
int F_198 ( struct V_1 * V_2 , T_1 V_447 )
{
struct V_448 V_18 ;
struct V_129 * V_11 ;
F_5 ( L_22 , V_2 -> V_111 , V_447 ) ;
if ( V_447 )
V_11 = F_58 ( V_316 , V_2 ) ;
else
V_11 = F_58 ( V_336 , V_2 ) ;
if ( V_11 != NULL ) {
T_1 type = V_2 -> V_318 . type ;
F_11 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , 0 , & type ,
sizeof( type ) ) ;
F_59 ( V_11 ) ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . type = V_2 -> V_318 . type ;
V_18 . V_447 = V_447 ;
return F_66 ( V_449 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_199 ( struct V_1 * V_2 , T_7 * V_122 , T_1 type )
{
struct V_129 * V_11 ;
struct V_450 V_18 ;
V_11 = F_58 ( V_352 , V_2 ) ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = type ;
return F_66 ( V_451 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
int F_200 ( struct V_1 * V_2 , T_7 * V_122 , T_1 type )
{
struct V_129 * V_11 ;
struct V_452 V_18 ;
V_11 = F_58 ( V_354 , V_2 ) ;
F_47 ( & V_18 . V_207 . V_122 , V_122 ) ;
V_18 . V_207 . type = type ;
return F_66 ( V_453 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
