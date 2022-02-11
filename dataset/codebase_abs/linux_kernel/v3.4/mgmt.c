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
F_8 ( V_7 , & V_14 -> V_18 ) ;
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
V_12 -> V_6 = F_7 ( V_6 ) ;
V_12 -> V_20 = F_7 ( sizeof( * V_14 ) + V_22 ) ;
V_14 = ( void * ) F_6 ( V_10 , sizeof( * V_14 ) + V_22 ) ;
F_8 ( V_7 , & V_14 -> V_18 ) ;
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
F_8 ( V_32 , & V_21 . V_33 ) ;
return F_11 ( V_5 , V_34 , V_35 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static int F_13 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_36 * V_21 ;
T_2 V_37 = F_2 ( V_38 ) ;
T_2 V_39 = F_2 ( V_40 ) ;
T_2 * V_18 ;
T_3 V_41 ;
int V_42 , V_15 ;
F_4 ( L_2 , V_5 ) ;
V_41 = sizeof( * V_21 ) + ( ( V_37 + V_39 ) * sizeof( T_2 ) ) ;
V_21 = F_14 ( V_41 , V_43 ) ;
if ( ! V_21 )
return - V_17 ;
F_8 ( V_37 , & V_21 -> V_37 ) ;
F_8 ( V_39 , & V_21 -> V_39 ) ;
for ( V_42 = 0 , V_18 = V_21 -> V_44 ; V_42 < V_37 ; V_42 ++ , V_18 ++ )
F_8 ( V_38 [ V_42 ] , V_18 ) ;
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ , V_18 ++ )
F_8 ( V_40 [ V_42 ] , V_18 ) ;
V_15 = F_11 ( V_5 , V_34 , V_45 , 0 , V_21 ,
V_41 ) ;
F_15 ( V_21 ) ;
return V_15 ;
}
static int F_16 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_46 * V_21 ;
struct V_47 * V_48 ;
struct V_26 * V_49 ;
T_3 V_22 ;
T_2 V_50 ;
int V_42 , V_15 ;
F_4 ( L_2 , V_5 ) ;
F_17 ( & V_51 ) ;
V_50 = 0 ;
F_18 (p, &hci_dev_list) {
V_50 ++ ;
}
V_22 = sizeof( * V_21 ) + ( 2 * V_50 ) ;
V_21 = F_14 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
F_19 ( & V_51 ) ;
return - V_17 ;
}
F_8 ( V_50 , & V_21 -> V_52 ) ;
V_42 = 0 ;
F_20 (d, &hci_dev_list, list) {
if ( F_21 ( V_53 , & V_49 -> V_54 ) )
continue;
F_8 ( V_49 -> V_55 , & V_21 -> V_6 [ V_42 ++ ] ) ;
F_4 ( L_3 , V_49 -> V_55 ) ;
}
F_19 ( & V_51 ) ;
V_15 = F_11 ( V_5 , V_34 , V_56 , 0 , V_21 ,
V_22 ) ;
F_15 ( V_21 ) ;
return V_15 ;
}
static T_4 F_22 ( struct V_26 * V_27 )
{
T_4 V_57 = 0 ;
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
if ( V_71 ) {
if ( V_27 -> V_63 [ 4 ] & V_72 )
V_57 |= V_73 ;
}
return V_57 ;
}
static T_4 F_23 ( struct V_26 * V_27 )
{
T_4 V_57 = 0 ;
if ( F_24 ( V_27 ) )
V_57 |= V_58 ;
if ( F_21 ( V_74 , & V_27 -> V_54 ) )
V_57 |= V_59 ;
if ( F_21 ( V_75 , & V_27 -> V_54 ) )
V_57 |= V_61 ;
if ( F_21 ( V_76 , & V_27 -> V_54 ) )
V_57 |= V_62 ;
if ( ! ( V_27 -> V_63 [ 4 ] & V_66 ) )
V_57 |= V_67 ;
if ( F_21 ( V_77 , & V_27 -> V_54 ) )
V_57 |= V_73 ;
if ( F_21 ( V_78 , & V_27 -> V_54 ) )
V_57 |= V_68 ;
if ( F_21 ( V_79 , & V_27 -> V_54 ) )
V_57 |= V_65 ;
if ( F_21 ( V_80 , & V_27 -> V_54 ) )
V_57 |= V_70 ;
return V_57 ;
}
static T_2 F_25 ( T_1 * V_81 )
{
T_4 V_82 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 12 ; V_42 ++ ) {
if ( V_83 [ V_42 ] != V_81 [ V_42 ] )
return 0 ;
}
memcpy ( & V_82 , & V_81 [ 12 ] , 4 ) ;
V_82 = F_26 ( V_82 ) ;
if ( V_82 > 0xffff )
return 0 ;
return ( T_2 ) V_82 ;
}
static void F_27 ( struct V_26 * V_27 , T_1 * V_25 )
{
T_1 * V_84 = V_25 ;
T_2 V_85 = 0 ;
T_2 V_86 [ V_87 / sizeof( T_2 ) ] ;
int V_42 , V_88 = 0 ;
struct V_89 * V_90 ;
T_3 V_91 ;
V_91 = strlen ( V_27 -> V_92 ) ;
if ( V_91 > 0 ) {
if ( V_91 > 48 ) {
V_91 = 48 ;
V_84 [ 1 ] = V_93 ;
} else
V_84 [ 1 ] = V_94 ;
V_84 [ 0 ] = V_91 + 1 ;
memcpy ( V_84 + 2 , V_27 -> V_92 , V_91 ) ;
V_85 += ( V_91 + 2 ) ;
V_84 += ( V_91 + 2 ) ;
}
memset ( V_86 , 0 , sizeof( V_86 ) ) ;
F_20 (uuid, &hdev->uuids, list) {
T_2 V_95 ;
V_95 = F_25 ( V_90 -> V_90 ) ;
if ( V_95 == 0 )
return;
if ( V_95 < 0x1100 )
continue;
if ( V_95 == V_96 )
continue;
if ( V_85 + 2 + sizeof( T_2 ) > V_87 ) {
V_88 = 1 ;
break;
}
for ( V_42 = 0 ; V_86 [ V_42 ] != 0 ; V_42 ++ )
if ( V_86 [ V_42 ] == V_95 )
break;
if ( V_86 [ V_42 ] == 0 ) {
V_86 [ V_42 ] = V_95 ;
V_85 += sizeof( T_2 ) ;
}
}
if ( V_86 [ 0 ] != 0 ) {
T_1 * V_97 = V_84 ;
V_84 [ 1 ] = V_88 ? V_98 : V_99 ;
V_84 += 2 ;
V_85 += 2 ;
for ( V_42 = 0 ; V_86 [ V_42 ] != 0 ; V_42 ++ ) {
* V_84 ++ = ( V_86 [ V_42 ] & 0x00ff ) ;
* V_84 ++ = ( V_86 [ V_42 ] & 0xff00 ) >> 8 ;
}
* V_97 = ( V_42 * sizeof( T_2 ) ) + 1 ;
}
}
static int F_28 ( struct V_26 * V_27 )
{
struct V_100 V_101 ;
if ( ! F_24 ( V_27 ) )
return 0 ;
if ( ! ( V_27 -> V_63 [ 6 ] & V_102 ) )
return 0 ;
if ( ! F_21 ( V_79 , & V_27 -> V_54 ) )
return 0 ;
if ( F_21 ( V_103 , & V_27 -> V_54 ) )
return 0 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_27 ( V_27 , V_101 . V_25 ) ;
if ( memcmp ( V_101 . V_25 , V_27 -> V_104 , sizeof( V_101 . V_25 ) ) == 0 )
return 0 ;
memcpy ( V_27 -> V_104 , V_101 . V_25 , sizeof( V_101 . V_25 ) ) ;
return F_29 ( V_27 , V_105 , sizeof( V_101 ) , & V_101 ) ;
}
static T_1 F_30 ( struct V_26 * V_27 )
{
struct V_89 * V_90 ;
T_1 V_82 = 0 ;
F_20 (uuid, &hdev->uuids, list)
V_82 |= V_90 -> V_106 ;
return V_82 ;
}
static int F_31 ( struct V_26 * V_27 )
{
T_1 V_107 [ 3 ] ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
if ( ! F_24 ( V_27 ) )
return 0 ;
if ( F_21 ( V_103 , & V_27 -> V_54 ) )
return 0 ;
V_107 [ 0 ] = V_27 -> V_109 ;
V_107 [ 1 ] = V_27 -> V_110 ;
V_107 [ 2 ] = F_30 ( V_27 ) ;
if ( memcmp ( V_107 , V_27 -> V_111 , 3 ) == 0 )
return 0 ;
V_15 = F_29 ( V_27 , V_112 , sizeof( V_107 ) , V_107 ) ;
if ( V_15 == 0 )
F_32 ( V_113 , & V_27 -> V_54 ) ;
return V_15 ;
}
static void F_33 ( struct V_114 * V_115 )
{
struct V_26 * V_27 = F_34 ( V_115 , struct V_26 ,
V_116 . V_115 ) ;
if ( ! F_35 ( V_103 , & V_27 -> V_54 ) )
return;
F_36 ( V_27 ) ;
F_28 ( V_27 ) ;
F_31 ( V_27 ) ;
F_37 ( V_27 ) ;
}
static void F_38 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
if ( F_39 ( V_117 , & V_27 -> V_54 ) )
return;
F_40 ( & V_27 -> V_116 , F_33 ) ;
F_41 ( V_76 , & V_27 -> V_54 ) ;
}
static int F_42 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_118 V_21 ;
F_4 ( L_5 , V_5 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_43 ( & V_21 . V_119 , & V_27 -> V_119 ) ;
V_21 . V_30 = V_27 -> V_120 ;
F_8 ( V_27 -> V_121 , & V_21 . V_121 ) ;
V_21 . V_122 = F_44 ( F_22 ( V_27 ) ) ;
V_21 . V_123 = F_44 ( F_23 ( V_27 ) ) ;
memcpy ( V_21 . V_111 , V_27 -> V_111 , 3 ) ;
memcpy ( V_21 . V_108 , V_27 -> V_92 , sizeof( V_27 -> V_92 ) ) ;
memcpy ( V_21 . V_124 , V_27 -> V_124 , sizeof( V_27 -> V_124 ) ) ;
F_37 ( V_27 ) ;
return F_11 ( V_5 , V_27 -> V_55 , V_125 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
static void F_45 ( struct V_126 * V_7 )
{
F_46 ( V_7 -> V_5 ) ;
F_15 ( V_7 -> V_127 ) ;
F_15 ( V_7 ) ;
}
static struct V_126 * F_47 ( struct V_4 * V_5 , T_2 V_18 ,
struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_126 * V_7 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 = V_18 ;
V_7 -> V_6 = V_27 -> V_55 ;
V_7 -> V_127 = F_14 ( V_20 , V_16 ) ;
if ( ! V_7 -> V_127 ) {
F_15 ( V_7 ) ;
return NULL ;
}
if ( V_25 )
memcpy ( V_7 -> V_127 , V_25 , V_20 ) ;
V_7 -> V_5 = V_5 ;
F_48 ( V_5 ) ;
F_49 ( & V_7 -> V_128 , & V_27 -> V_129 ) ;
return V_7 ;
}
static void F_50 ( T_2 V_18 , struct V_26 * V_27 ,
void (* F_51)( struct V_126 * V_7 , void * V_25 ) ,
void * V_25 )
{
struct V_47 * V_48 , * V_130 ;
F_52 (p, n, &hdev->mgmt_pending) {
struct V_126 * V_7 ;
V_7 = F_53 ( V_48 , struct V_126 , V_128 ) ;
if ( V_18 > 0 && V_7 -> V_18 != V_18 )
continue;
F_51 ( V_7 , V_25 ) ;
}
}
static struct V_126 * F_54 ( T_2 V_18 , struct V_26 * V_27 )
{
struct V_126 * V_7 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 == V_18 )
return V_7 ;
}
return NULL ;
}
static void F_55 ( struct V_126 * V_7 )
{
F_56 ( & V_7 -> V_128 ) ;
F_45 ( V_7 ) ;
}
static int F_57 ( struct V_4 * V_5 , T_2 V_18 , struct V_26 * V_27 )
{
T_5 V_57 = F_44 ( F_23 ( V_27 ) ) ;
return F_11 ( V_5 , V_27 -> V_55 , V_18 , 0 , & V_57 ,
sizeof( V_57 ) ) ;
}
static int F_58 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( F_35 ( V_132 , & V_27 -> V_54 ) ) {
F_59 ( & V_27 -> V_133 ) ;
if ( V_101 -> V_82 ) {
V_15 = F_57 ( V_5 , V_134 , V_27 ) ;
F_60 ( V_27 , 1 ) ;
goto V_135;
}
}
if ( ! ! V_101 -> V_82 == F_24 ( V_27 ) ) {
V_15 = F_57 ( V_5 , V_134 , V_27 ) ;
goto V_135;
}
if ( F_54 ( V_134 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_134 ,
V_136 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_134 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
if ( V_101 -> V_82 )
F_61 ( & V_27 -> V_137 ) ;
else
F_61 ( & V_27 -> V_133 . V_115 ) ;
V_15 = 0 ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_62 ( T_2 V_138 , struct V_26 * V_27 , void * V_25 , T_2 V_28 ,
struct V_4 * V_139 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_5 ( sizeof( * V_12 ) + V_28 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_138 ) ;
if ( V_27 )
V_12 -> V_6 = F_7 ( V_27 -> V_55 ) ;
else
V_12 -> V_6 = F_7 ( V_34 ) ;
V_12 -> V_20 = F_7 ( V_28 ) ;
if ( V_25 )
memcpy ( F_6 ( V_10 , V_28 ) , V_25 , V_28 ) ;
F_63 ( V_10 ) ;
F_64 ( V_10 , V_139 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
static int F_65 ( struct V_26 * V_27 , struct V_4 * V_140 )
{
T_5 V_14 ;
V_14 = F_44 ( F_23 ( V_27 ) ) ;
return F_62 ( V_141 , V_27 , & V_14 , sizeof( V_14 ) , V_140 ) ;
}
static int F_66 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_142 * V_101 = V_25 ;
struct V_126 * V_7 ;
T_2 V_143 ;
T_1 V_144 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
V_143 = F_67 ( & V_101 -> V_143 ) ;
if ( ! V_101 -> V_82 && V_143 > 0 )
return F_3 ( V_5 , V_27 -> V_55 , V_145 ,
V_146 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) && V_143 > 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_145 ,
V_147 ) ;
goto V_135;
}
if ( F_54 ( V_145 , V_27 ) ||
F_54 ( V_148 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_145 ,
V_136 ) ;
goto V_135;
}
if ( ! F_21 ( V_74 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_145 ,
V_149 ) ;
goto V_135;
}
if ( ! F_24 ( V_27 ) ) {
bool V_150 = false ;
if ( ! ! V_101 -> V_82 != F_21 ( V_75 , & V_27 -> V_54 ) ) {
F_68 ( V_75 , & V_27 -> V_54 ) ;
V_150 = true ;
}
V_15 = F_57 ( V_5 , V_145 , V_27 ) ;
if ( V_15 < 0 )
goto V_135;
if ( V_150 )
V_15 = F_65 ( V_27 , V_5 ) ;
goto V_135;
}
if ( ! ! V_101 -> V_82 == F_21 ( V_75 , & V_27 -> V_54 ) ) {
if ( V_27 -> V_151 > 0 ) {
F_59 ( & V_27 -> V_152 ) ;
V_27 -> V_151 = 0 ;
}
if ( V_101 -> V_82 && V_143 > 0 ) {
V_27 -> V_151 = V_143 ;
F_69 ( V_27 -> V_153 , & V_27 -> V_152 ,
F_70 ( V_27 -> V_151 * 1000 ) ) ;
}
V_15 = F_57 ( V_5 , V_145 , V_27 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_145 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
V_144 = V_154 ;
if ( V_101 -> V_82 )
V_144 |= V_155 ;
else
F_59 ( & V_27 -> V_152 ) ;
V_15 = F_29 ( V_27 , V_156 , 1 , & V_144 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
if ( V_101 -> V_82 )
V_27 -> V_151 = V_143 ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_71 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
struct V_126 * V_7 ;
T_1 V_144 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
bool V_150 = false ;
if ( ! ! V_101 -> V_82 != F_21 ( V_74 , & V_27 -> V_54 ) )
V_150 = true ;
if ( V_101 -> V_82 ) {
F_32 ( V_74 , & V_27 -> V_54 ) ;
} else {
F_41 ( V_74 , & V_27 -> V_54 ) ;
F_41 ( V_75 , & V_27 -> V_54 ) ;
}
V_15 = F_57 ( V_5 , V_148 , V_27 ) ;
if ( V_15 < 0 )
goto V_135;
if ( V_150 )
V_15 = F_65 ( V_27 , V_5 ) ;
goto V_135;
}
if ( F_54 ( V_145 , V_27 ) ||
F_54 ( V_148 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_148 ,
V_136 ) ;
goto V_135;
}
if ( ! ! V_101 -> V_82 == F_21 ( V_157 , & V_27 -> V_158 ) ) {
V_15 = F_57 ( V_5 , V_148 , V_27 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_148 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
if ( V_101 -> V_82 ) {
V_144 = V_154 ;
} else {
V_144 = 0 ;
if ( F_21 ( V_159 , & V_27 -> V_158 ) &&
V_27 -> V_151 > 0 )
F_59 ( & V_27 -> V_152 ) ;
}
V_15 = F_29 ( V_27 , V_156 , 1 , & V_144 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_72 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( V_101 -> V_82 )
F_32 ( V_76 , & V_27 -> V_54 ) ;
else
F_41 ( V_76 , & V_27 -> V_54 ) ;
V_15 = F_57 ( V_5 , V_160 , V_27 ) ;
if ( V_15 < 0 )
goto V_135;
V_15 = F_65 ( V_27 , V_5 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_73 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
struct V_126 * V_7 ;
T_1 V_82 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
bool V_150 = false ;
if ( ! ! V_101 -> V_82 != F_21 ( V_78 ,
& V_27 -> V_54 ) ) {
F_68 ( V_78 , & V_27 -> V_54 ) ;
V_150 = true ;
}
V_15 = F_57 ( V_5 , V_161 , V_27 ) ;
if ( V_15 < 0 )
goto V_135;
if ( V_150 )
V_15 = F_65 ( V_27 , V_5 ) ;
goto V_135;
}
if ( F_54 ( V_161 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_161 ,
V_136 ) ;
goto V_135;
}
V_82 = ! ! V_101 -> V_82 ;
if ( F_21 ( V_162 , & V_27 -> V_158 ) == V_82 ) {
V_15 = F_57 ( V_5 , V_161 , V_27 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_161 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
V_15 = F_29 ( V_27 , V_163 , sizeof( V_82 ) , & V_82 ) ;
if ( V_15 < 0 ) {
F_55 ( V_7 ) ;
goto V_135;
}
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_74 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
struct V_126 * V_7 ;
T_1 V_82 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! ( V_27 -> V_63 [ 6 ] & V_64 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_164 ,
V_165 ) ;
goto V_135;
}
V_82 = ! ! V_101 -> V_82 ;
if ( ! F_24 ( V_27 ) ) {
bool V_150 = false ;
if ( V_82 != F_21 ( V_79 , & V_27 -> V_54 ) ) {
F_68 ( V_79 , & V_27 -> V_54 ) ;
V_150 = true ;
}
V_15 = F_57 ( V_5 , V_164 , V_27 ) ;
if ( V_15 < 0 )
goto V_135;
if ( V_150 )
V_15 = F_65 ( V_27 , V_5 ) ;
goto V_135;
}
if ( F_54 ( V_164 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_164 ,
V_136 ) ;
goto V_135;
}
if ( F_21 ( V_79 , & V_27 -> V_54 ) == V_82 ) {
V_15 = F_57 ( V_5 , V_164 , V_27 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_164 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
V_15 = F_29 ( V_27 , V_166 , sizeof( V_82 ) , & V_82 ) ;
if ( V_15 < 0 ) {
F_55 ( V_7 ) ;
goto V_135;
}
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_75 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
if ( ! V_69 )
return F_3 ( V_5 , V_27 -> V_55 , V_167 ,
V_165 ) ;
if ( V_101 -> V_82 )
F_32 ( V_80 , & V_27 -> V_54 ) ;
else
F_41 ( V_80 , & V_27 -> V_54 ) ;
return F_57 ( V_5 , V_167 , V_27 ) ;
}
static int F_76 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
struct V_168 V_169 ;
struct V_126 * V_7 ;
int V_15 ;
T_1 V_82 , V_170 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! V_71 || ! ( V_27 -> V_63 [ 4 ] & V_72 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_171 ,
V_165 ) ;
goto V_172;
}
V_82 = ! ! V_101 -> V_82 ;
V_170 = ! ! ( V_27 -> V_173 [ 0 ] & V_174 ) ;
if ( ! F_24 ( V_27 ) || V_82 == V_170 ) {
bool V_150 = false ;
if ( V_82 != F_21 ( V_77 , & V_27 -> V_54 ) ) {
F_68 ( V_77 , & V_27 -> V_54 ) ;
V_150 = true ;
}
V_15 = F_57 ( V_5 , V_171 , V_27 ) ;
if ( V_15 < 0 )
goto V_172;
if ( V_150 )
V_15 = F_65 ( V_27 , V_5 ) ;
goto V_172;
}
if ( F_54 ( V_171 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_171 ,
V_136 ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_171 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_172;
}
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
if ( V_82 ) {
V_169 . V_175 = V_82 ;
V_169 . V_176 = ! ! ( V_27 -> V_63 [ 6 ] & V_177 ) ;
}
V_15 = F_29 ( V_27 , V_178 , sizeof( V_169 ) ,
& V_169 ) ;
if ( V_15 < 0 ) {
F_55 ( V_7 ) ;
goto V_172;
}
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_77 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 , T_2 V_20 )
{
struct V_179 * V_101 = V_25 ;
struct V_126 * V_7 ;
struct V_89 * V_90 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( F_21 ( V_113 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_180 ,
V_136 ) ;
goto V_135;
}
V_90 = F_14 ( sizeof( * V_90 ) , V_16 ) ;
if ( ! V_90 ) {
V_15 = - V_17 ;
goto V_135;
}
memcpy ( V_90 -> V_90 , V_101 -> V_90 , 16 ) ;
V_90 -> V_106 = V_101 -> V_106 ;
F_49 ( & V_90 -> V_128 , & V_27 -> V_181 ) ;
V_15 = F_31 ( V_27 ) ;
if ( V_15 < 0 )
goto V_135;
V_15 = F_28 ( V_27 ) ;
if ( V_15 < 0 )
goto V_135;
if ( ! F_21 ( V_113 , & V_27 -> V_54 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_180 , 0 ,
V_27 -> V_111 , 3 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_180 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static bool F_78 ( struct V_26 * V_27 )
{
if ( ! F_24 ( V_27 ) )
return false ;
if ( ! F_39 ( V_103 , & V_27 -> V_54 ) ) {
F_79 ( & V_27 -> V_116 , V_182 ) ;
return true ;
}
return false ;
}
static int F_80 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_183 * V_101 = V_25 ;
struct V_126 * V_7 ;
struct V_47 * V_48 , * V_130 ;
T_1 V_184 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_15 , V_185 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( F_21 ( V_113 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_186 ,
V_136 ) ;
goto V_172;
}
if ( memcmp ( V_101 -> V_90 , V_184 , 16 ) == 0 ) {
V_15 = F_81 ( V_27 ) ;
if ( F_78 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_186 ,
0 , V_27 -> V_111 , 3 ) ;
goto V_172;
}
goto F_31;
}
V_185 = 0 ;
F_52 (p, n, &hdev->uuids) {
struct V_89 * V_187 = F_53 ( V_48 , struct V_89 , V_128 ) ;
if ( memcmp ( V_187 -> V_90 , V_101 -> V_90 , 16 ) != 0 )
continue;
F_56 ( & V_187 -> V_128 ) ;
V_185 ++ ;
}
if ( V_185 == 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_186 ,
V_146 ) ;
goto V_172;
}
F_31:
V_15 = F_31 ( V_27 ) ;
if ( V_15 < 0 )
goto V_172;
V_15 = F_28 ( V_27 ) ;
if ( V_15 < 0 )
goto V_172;
if ( ! F_21 ( V_113 , & V_27 -> V_54 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_186 , 0 ,
V_27 -> V_111 , 3 ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_186 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_172;
}
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_82 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_188 * V_101 = V_25 ;
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_6 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( F_21 ( V_113 , & V_27 -> V_54 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_189 ,
V_136 ) ;
goto V_172;
}
V_27 -> V_110 = V_101 -> V_190 ;
V_27 -> V_109 = V_101 -> V_191 ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_189 , 0 ,
V_27 -> V_111 , 3 ) ;
goto V_172;
}
if ( F_35 ( V_103 , & V_27 -> V_54 ) ) {
F_37 ( V_27 ) ;
F_83 ( & V_27 -> V_116 ) ;
F_36 ( V_27 ) ;
F_28 ( V_27 ) ;
}
V_15 = F_31 ( V_27 ) ;
if ( V_15 < 0 )
goto V_172;
if ( ! F_21 ( V_113 , & V_27 -> V_54 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_189 , 0 ,
V_27 -> V_111 , 3 ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_189 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_172;
}
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_84 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_192 * V_101 = V_25 ;
T_2 V_193 , V_194 ;
int V_42 ;
V_193 = F_67 ( & V_101 -> V_193 ) ;
V_194 = sizeof( * V_101 ) + V_193 *
sizeof( struct V_195 ) ;
if ( V_194 != V_20 ) {
F_85 ( L_7 ,
V_20 , V_194 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_196 ,
V_146 ) ;
}
F_4 ( L_8 , V_27 -> V_108 , V_101 -> V_197 ,
V_193 ) ;
F_36 ( V_27 ) ;
F_86 ( V_27 ) ;
F_32 ( V_198 , & V_27 -> V_54 ) ;
if ( V_101 -> V_197 )
F_32 ( V_199 , & V_27 -> V_54 ) ;
else
F_41 ( V_199 , & V_27 -> V_54 ) ;
for ( V_42 = 0 ; V_42 < V_193 ; V_42 ++ ) {
struct V_195 * V_200 = & V_101 -> V_201 [ V_42 ] ;
F_87 ( V_27 , NULL , 0 , & V_200 -> V_202 . V_119 , V_200 -> V_82 ,
V_200 -> type , V_200 -> V_203 ) ;
}
F_11 ( V_5 , V_27 -> V_55 , V_196 , 0 , NULL , 0 ) ;
F_37 ( V_27 ) ;
return 0 ;
}
static int F_88 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_204 , struct V_4 * V_139 )
{
struct V_205 V_14 ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = V_204 ;
return F_62 ( V_206 , V_27 , & V_14 , sizeof( V_14 ) ,
V_139 ) ;
}
static int F_89 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_207 * V_101 = V_25 ;
struct V_208 V_21 ;
struct V_209 V_210 ;
struct V_126 * V_7 ;
struct V_211 * V_212 ;
int V_15 ;
F_36 ( V_27 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_43 ( & V_21 . V_202 . V_119 , & V_101 -> V_202 . V_119 ) ;
V_21 . V_202 . type = V_101 -> V_202 . type ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_213 ,
V_147 , & V_21 , sizeof( V_21 ) ) ;
goto V_172;
}
if ( V_101 -> V_202 . type == V_214 )
V_15 = F_90 ( V_27 , & V_101 -> V_202 . V_119 ) ;
else
V_15 = F_91 ( V_27 , & V_101 -> V_202 . V_119 ) ;
if ( V_15 < 0 ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_213 ,
V_215 , & V_21 , sizeof( V_21 ) ) ;
goto V_172;
}
if ( V_101 -> V_216 ) {
if ( V_101 -> V_202 . type == V_214 )
V_212 = F_92 ( V_27 , V_217 ,
& V_101 -> V_202 . V_119 ) ;
else
V_212 = F_92 ( V_27 , V_218 ,
& V_101 -> V_202 . V_119 ) ;
} else {
V_212 = NULL ;
}
if ( ! V_212 ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_213 , 0 ,
& V_21 , sizeof( V_21 ) ) ;
F_88 ( V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type , V_5 ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_213 , V_27 , V_101 ,
sizeof( * V_101 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_172;
}
F_8 ( V_212 -> V_219 , & V_210 . V_219 ) ;
V_210 . V_220 = 0x13 ;
V_15 = F_29 ( V_27 , V_221 , sizeof( V_210 ) , & V_210 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int V_216 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_222 * V_101 = V_25 ;
struct V_209 V_210 ;
struct V_126 * V_7 ;
struct V_211 * V_212 ;
int V_15 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
if ( ! F_21 ( V_223 , & V_27 -> V_158 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_224 ,
V_147 ) ;
goto V_135;
}
if ( F_54 ( V_224 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_224 ,
V_136 ) ;
goto V_135;
}
if ( V_101 -> V_202 . type == V_214 )
V_212 = F_92 ( V_27 , V_217 , & V_101 -> V_202 . V_119 ) ;
else
V_212 = F_92 ( V_27 , V_218 , & V_101 -> V_202 . V_119 ) ;
if ( ! V_212 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_224 ,
V_225 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_224 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
F_8 ( V_212 -> V_219 , & V_210 . V_219 ) ;
V_210 . V_220 = 0x13 ;
V_15 = F_29 ( V_27 , V_221 , sizeof( V_210 ) , & V_210 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static T_1 F_93 ( T_1 V_226 , T_1 V_204 )
{
switch ( V_226 ) {
case V_218 :
switch ( V_204 ) {
case V_227 :
return V_228 ;
case V_229 :
return V_230 ;
default:
return V_231 ;
}
case V_217 :
return V_214 ;
default:
return V_231 ;
}
}
static int F_94 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_28 )
{
struct V_232 * V_21 ;
struct V_211 * V_233 ;
T_3 V_22 ;
int V_15 ;
T_2 V_42 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_234 ,
V_147 ) ;
goto V_172;
}
V_42 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_21 ( V_235 , & V_233 -> V_158 ) )
V_42 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_236 ) ) ;
V_21 = F_14 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
V_15 = - V_17 ;
goto V_172;
}
V_42 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_21 ( V_235 , & V_233 -> V_158 ) )
continue;
F_43 ( & V_21 -> V_202 [ V_42 ] . V_119 , & V_233 -> V_237 ) ;
V_21 -> V_202 [ V_42 ] . type = F_93 ( V_233 -> type , V_233 -> V_238 ) ;
if ( V_21 -> V_202 [ V_42 ] . type == V_231 )
continue;
V_42 ++ ;
}
F_8 ( V_42 , & V_21 -> V_239 ) ;
V_22 = sizeof( * V_21 ) + ( V_42 * sizeof( struct V_236 ) ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_234 , 0 , V_21 ,
V_22 ) ;
F_15 ( V_21 ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_95 ( struct V_4 * V_5 , struct V_26 * V_27 ,
struct V_240 * V_101 )
{
struct V_126 * V_7 ;
int V_15 ;
V_7 = F_47 ( V_5 , V_241 , V_27 , V_101 ,
sizeof( * V_101 ) ) ;
if ( ! V_7 )
return - V_17 ;
V_15 = F_29 ( V_27 , V_242 ,
sizeof( V_101 -> V_202 . V_119 ) , & V_101 -> V_202 . V_119 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
return V_15 ;
}
static int F_96 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_211 * V_212 ;
struct V_243 * V_101 = V_25 ;
struct V_244 V_245 ;
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_246 ,
V_147 ) ;
goto V_135;
}
V_212 = F_92 ( V_27 , V_217 , & V_101 -> V_202 . V_119 ) ;
if ( ! V_212 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_246 ,
V_225 ) ;
goto V_135;
}
if ( V_212 -> V_247 == V_248 && V_101 -> V_203 != 16 ) {
struct V_240 V_249 ;
memcpy ( & V_249 . V_202 , & V_101 -> V_202 , sizeof( V_249 . V_202 ) ) ;
F_85 ( L_10 ) ;
V_15 = F_95 ( V_5 , V_27 , & V_249 ) ;
if ( V_15 >= 0 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_246 ,
V_146 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_246 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
F_43 ( & V_245 . V_119 , & V_101 -> V_202 . V_119 ) ;
V_245 . V_203 = V_101 -> V_203 ;
memcpy ( V_245 . V_250 , V_101 -> V_250 , sizeof( V_245 . V_250 ) ) ;
V_15 = F_29 ( V_27 , V_251 , sizeof( V_245 ) , & V_245 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_97 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_240 * V_101 = V_25 ;
int V_15 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_241 ,
V_147 ) ;
goto V_135;
}
V_15 = F_95 ( V_5 , V_27 , V_101 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_98 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_252 * V_101 = V_25 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
V_27 -> V_253 = V_101 -> V_253 ;
F_4 ( L_11 , V_27 -> V_108 ,
V_27 -> V_253 ) ;
F_37 ( V_27 ) ;
return F_11 ( V_5 , V_27 -> V_55 , V_254 , 0 , NULL ,
0 ) ;
}
static inline struct V_126 * F_99 ( struct V_211 * V_212 )
{
struct V_26 * V_27 = V_212 -> V_27 ;
struct V_126 * V_7 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 != V_255 )
continue;
if ( V_7 -> V_256 != V_212 )
continue;
return V_7 ;
}
return NULL ;
}
static void F_100 ( struct V_126 * V_7 , T_1 V_8 )
{
struct V_257 V_21 ;
struct V_211 * V_212 = V_7 -> V_256 ;
F_43 ( & V_21 . V_202 . V_119 , & V_212 -> V_237 ) ;
V_21 . V_202 . type = F_93 ( V_212 -> type , V_212 -> V_238 ) ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_255 , V_8 ,
& V_21 , sizeof( V_21 ) ) ;
V_212 -> V_258 = NULL ;
V_212 -> V_259 = NULL ;
V_212 -> V_260 = NULL ;
F_101 ( V_212 ) ;
F_55 ( V_7 ) ;
}
static void F_102 ( struct V_211 * V_212 , T_1 V_8 )
{
struct V_126 * V_7 ;
F_4 ( L_12 , V_8 ) ;
V_7 = F_99 ( V_212 ) ;
if ( ! V_7 )
F_4 ( L_13 ) ;
else
F_100 ( V_7 , F_1 ( V_8 ) ) ;
}
static int F_103 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_261 * V_101 = V_25 ;
struct V_257 V_21 ;
struct V_126 * V_7 ;
T_1 V_262 , V_263 ;
struct V_211 * V_212 ;
int V_15 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_255 ,
V_147 ) ;
goto V_172;
}
V_262 = V_264 ;
if ( V_101 -> V_265 == 0x03 )
V_263 = V_266 ;
else
V_263 = V_267 ;
if ( V_101 -> V_202 . type == V_214 )
V_212 = F_104 ( V_27 , V_217 , & V_101 -> V_202 . V_119 , V_262 ,
V_263 ) ;
else
V_212 = F_104 ( V_27 , V_218 , & V_101 -> V_202 . V_119 , V_262 ,
V_263 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_43 ( & V_21 . V_202 . V_119 , & V_101 -> V_202 . V_119 ) ;
V_21 . V_202 . type = V_101 -> V_202 . type ;
if ( F_105 ( V_212 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_255 ,
V_268 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_172;
}
if ( V_212 -> V_258 ) {
F_101 ( V_212 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_255 ,
V_136 , & V_21 , sizeof( V_21 ) ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_255 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
F_101 ( V_212 ) ;
goto V_172;
}
if ( V_101 -> V_202 . type == V_214 )
V_212 -> V_258 = F_102 ;
V_212 -> V_259 = F_102 ;
V_212 -> V_260 = F_102 ;
V_212 -> V_253 = V_101 -> V_265 ;
V_7 -> V_256 = V_212 ;
if ( V_212 -> V_269 == V_270 &&
F_106 ( V_212 , V_262 , V_263 ) )
F_100 ( V_7 , 0 ) ;
V_15 = 0 ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_107 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_236 * V_202 = V_25 ;
struct V_126 * V_7 ;
struct V_211 * V_212 ;
int V_15 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_271 ,
V_147 ) ;
goto V_172;
}
V_7 = F_54 ( V_255 , V_27 ) ;
if ( ! V_7 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_271 ,
V_146 ) ;
goto V_172;
}
V_212 = V_7 -> V_256 ;
if ( F_108 ( & V_202 -> V_119 , & V_212 -> V_237 ) != 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_271 ,
V_146 ) ;
goto V_172;
}
F_100 ( V_7 , V_272 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_271 , 0 ,
V_202 , sizeof( * V_202 ) ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_109 ( struct V_4 * V_5 , struct V_26 * V_27 ,
T_6 * V_119 , T_1 type , T_2 V_273 ,
T_2 V_274 , T_5 V_275 )
{
struct V_126 * V_7 ;
struct V_211 * V_212 ;
int V_15 ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_273 ,
V_147 ) ;
goto V_276;
}
if ( type == V_214 )
V_212 = F_92 ( V_27 , V_217 , V_119 ) ;
else
V_212 = F_92 ( V_27 , V_218 , V_119 ) ;
if ( ! V_212 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_273 ,
V_225 ) ;
goto V_276;
}
if ( type == V_228 || type == V_230 ) {
V_15 = F_110 ( V_212 , V_273 , V_275 ) ;
if ( ! V_15 )
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_273 ,
V_277 ) ;
else
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_273 ,
V_3 ) ;
goto V_276;
}
V_7 = F_47 ( V_5 , V_273 , V_27 , V_119 , sizeof( * V_119 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_276;
}
if ( V_274 == V_278 ) {
struct V_279 V_101 ;
F_43 ( & V_101 . V_119 , V_119 ) ;
V_101 . V_275 = V_275 ;
V_15 = F_29 ( V_27 , V_274 , sizeof( V_101 ) , & V_101 ) ;
} else
V_15 = F_29 ( V_27 , V_274 , sizeof( * V_119 ) , V_119 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_276:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_111 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_280 * V_101 = V_25 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_101 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_281 ,
V_146 ) ;
return F_109 ( V_5 , V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type ,
V_281 ,
V_282 , 0 ) ;
}
static int F_112 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_283 * V_101 = V_25 ;
F_4 ( L_9 ) ;
return F_109 ( V_5 , V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type ,
V_284 ,
V_285 , 0 ) ;
}
static int F_113 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_286 * V_101 = V_25 ;
F_4 ( L_9 ) ;
return F_109 ( V_5 , V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type ,
V_287 ,
V_278 , V_101 -> V_275 ) ;
}
static int F_114 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_288 * V_101 = V_25 ;
F_4 ( L_9 ) ;
return F_109 ( V_5 , V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type ,
V_289 ,
V_290 , 0 ) ;
}
static int F_115 ( struct V_26 * V_27 , const char * V_108 )
{
struct V_291 V_101 ;
memcpy ( V_101 . V_108 , V_108 , sizeof( V_101 . V_108 ) ) ;
return F_29 ( V_27 , V_292 , sizeof( V_101 ) , & V_101 ) ;
}
static int F_116 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_293 * V_101 = V_25 ;
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_9 ) ;
F_36 ( V_27 ) ;
memcpy ( V_27 -> V_124 , V_101 -> V_124 , sizeof( V_27 -> V_124 ) ) ;
if ( ! F_24 ( V_27 ) ) {
memcpy ( V_27 -> V_92 , V_101 -> V_108 , sizeof( V_27 -> V_92 ) ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_294 , 0 ,
V_25 , V_20 ) ;
if ( V_15 < 0 )
goto V_135;
V_15 = F_62 ( V_295 , V_27 , V_25 , V_20 ,
V_5 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_294 , V_27 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
V_15 = F_115 ( V_27 , V_101 -> V_108 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_117 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_28 )
{
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_296 ,
V_147 ) ;
goto V_172;
}
if ( ! ( V_27 -> V_63 [ 6 ] & V_64 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_296 ,
V_165 ) ;
goto V_172;
}
if ( F_54 ( V_296 , V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_296 ,
V_136 ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_296 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_172;
}
V_15 = F_29 ( V_27 , V_297 , 0 , NULL ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_118 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_298 * V_101 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_14 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_299 ,
V_147 , & V_101 -> V_202 ,
sizeof( V_101 -> V_202 ) ) ;
goto V_172;
}
V_15 = F_119 ( V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_300 ,
V_101 -> V_301 ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = 0 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_299 , V_8 ,
& V_101 -> V_202 , sizeof( V_101 -> V_202 ) ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_120 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_302 * V_101 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 ,
V_303 ,
V_147 , & V_101 -> V_202 ,
sizeof( V_101 -> V_202 ) ) ;
goto V_172;
}
V_15 = F_121 ( V_27 , & V_101 -> V_202 . V_119 ) ;
if ( V_15 < 0 )
V_8 = V_146 ;
else
V_8 = 0 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_303 ,
V_8 , & V_101 -> V_202 , sizeof( V_101 -> V_202 ) ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
int F_122 ( struct V_26 * V_27 )
{
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
V_15 = F_123 ( V_27 , V_304 ) ;
if ( V_15 < 0 )
F_124 ( V_27 , V_305 ) ;
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_125 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_306 * V_101 = V_25 ;
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_24 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_307 ,
V_147 ) ;
goto V_135;
}
if ( V_27 -> V_308 . V_269 != V_305 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_307 ,
V_136 ) ;
goto V_135;
}
V_7 = F_47 ( V_5 , V_307 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_135;
}
V_27 -> V_308 . type = V_101 -> type ;
switch ( V_27 -> V_308 . type ) {
case V_309 :
if ( F_126 ( V_27 ) )
V_15 = F_123 ( V_27 , V_310 ) ;
else
V_15 = - V_311 ;
break;
case V_312 :
if ( F_127 ( V_27 ) )
V_15 = F_128 ( V_27 , V_313 , V_314 ,
V_315 , V_316 ) ;
else
V_15 = - V_311 ;
break;
case V_317 :
if ( F_127 ( V_27 ) && F_126 ( V_27 ) )
V_15 = F_128 ( V_27 , V_313 , V_314 ,
V_315 ,
V_318 ) ;
else
V_15 = - V_311 ;
break;
default:
V_15 = - V_319 ;
}
if ( V_15 < 0 )
F_55 ( V_7 ) ;
else
F_124 ( V_27 , V_320 ) ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_129 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_321 * V_322 = V_25 ;
struct V_126 * V_7 ;
struct V_323 V_101 ;
struct V_324 * V_325 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_130 ( V_27 ) ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_326 ,
V_149 , & V_322 -> type ,
sizeof( V_322 -> type ) ) ;
goto V_172;
}
if ( V_27 -> V_308 . type != V_322 -> type ) {
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_326 ,
V_146 , & V_322 -> type ,
sizeof( V_322 -> type ) ) ;
goto V_172;
}
V_7 = F_47 ( V_5 , V_326 , V_27 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_172;
}
if ( V_27 -> V_308 . V_269 == V_327 ) {
V_15 = F_131 ( V_27 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
else
F_124 ( V_27 , V_328 ) ;
goto V_172;
}
V_325 = F_132 ( V_27 , V_329 , V_330 ) ;
if ( ! V_325 ) {
F_55 ( V_7 ) ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_326 , 0 ,
& V_322 -> type , sizeof( V_322 -> type ) ) ;
F_124 ( V_27 , V_305 ) ;
goto V_172;
}
F_43 ( & V_101 . V_119 , & V_325 -> V_25 . V_119 ) ;
V_15 = F_29 ( V_27 , V_331 , sizeof( V_101 ) ,
& V_101 ) ;
if ( V_15 < 0 )
F_55 ( V_7 ) ;
else
F_124 ( V_27 , V_328 ) ;
V_172:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_133 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_332 * V_101 = V_25 ;
struct V_324 * V_325 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
if ( ! F_130 ( V_27 ) ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_333 ,
V_3 ) ;
goto V_135;
}
V_325 = F_134 ( V_27 , & V_101 -> V_202 . V_119 ) ;
if ( ! V_325 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_333 ,
V_146 ) ;
goto V_135;
}
if ( V_101 -> V_334 ) {
V_325 -> V_335 = V_336 ;
F_56 ( & V_325 -> V_128 ) ;
} else {
V_325 -> V_335 = V_337 ;
F_135 ( V_27 , V_325 ) ;
}
V_15 = 0 ;
V_135:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_136 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_338 * V_101 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
V_15 = F_137 ( V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type ) ;
if ( V_15 < 0 )
V_8 = V_3 ;
else
V_8 = 0 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_339 , V_8 ,
& V_101 -> V_202 , sizeof( V_101 -> V_202 ) ) ;
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_138 ( struct V_4 * V_5 , struct V_26 * V_27 , void * V_25 ,
T_2 V_20 )
{
struct V_340 * V_101 = V_25 ;
T_1 V_8 ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_36 ( V_27 ) ;
V_15 = F_139 ( V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type ) ;
if ( V_15 < 0 )
V_8 = V_146 ;
else
V_8 = 0 ;
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_341 , V_8 ,
& V_101 -> V_202 , sizeof( V_101 -> V_202 ) ) ;
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_140 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_25 , T_2 V_20 )
{
struct V_131 * V_101 = V_25 ;
struct V_342 V_343 ;
T_1 type ;
int V_15 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
if ( ! F_24 ( V_27 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_147 ) ;
if ( ! F_21 ( V_74 , & V_27 -> V_54 ) )
return F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_149 ) ;
F_36 ( V_27 ) ;
if ( V_101 -> V_82 ) {
type = V_345 ;
V_343 . V_346 = F_141 ( 0x0024 ) ;
} else {
type = V_347 ;
V_343 . V_346 = F_141 ( 0x0800 ) ;
}
V_343 . V_348 = F_141 ( 0x0012 ) ;
V_15 = F_29 ( V_27 , V_349 , sizeof( V_343 ) ,
& V_343 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_3 ) ;
goto V_276;
}
V_15 = F_29 ( V_27 , V_350 , 1 , & type ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_27 -> V_55 , V_344 ,
V_3 ) ;
goto V_276;
}
V_15 = F_11 ( V_5 , V_27 -> V_55 , V_344 , 0 ,
NULL , 0 ) ;
V_276:
F_37 ( V_27 ) ;
return V_15 ;
}
static int F_142 ( struct V_4 * V_5 , struct V_26 * V_27 ,
void * V_351 , T_2 V_20 )
{
struct V_352 * V_101 = V_351 ;
T_2 V_193 , V_194 ;
int V_42 ;
V_193 = F_67 ( & V_101 -> V_193 ) ;
V_194 = sizeof( * V_101 ) + V_193 *
sizeof( struct V_353 ) ;
if ( V_194 != V_20 ) {
F_85 ( L_15 ,
V_20 , V_194 ) ;
return F_3 ( V_5 , V_27 -> V_55 , V_354 ,
V_319 ) ;
}
F_4 ( L_16 , V_27 -> V_108 , V_193 ) ;
F_36 ( V_27 ) ;
F_143 ( V_27 ) ;
for ( V_42 = 0 ; V_42 < V_193 ; V_42 ++ ) {
struct V_353 * V_200 = & V_101 -> V_201 [ V_42 ] ;
T_1 type ;
if ( V_200 -> V_355 )
type = V_356 ;
else
type = V_357 ;
F_144 ( V_27 , & V_200 -> V_202 . V_119 , V_200 -> V_202 . type ,
type , 0 , V_200 -> V_358 , V_200 -> V_82 ,
V_200 -> V_359 , V_200 -> V_360 , V_200 -> rand ) ;
}
F_37 ( V_27 ) ;
return 0 ;
}
int F_145 ( struct V_4 * V_5 , struct V_361 * V_362 , T_3 V_363 )
{
void * V_364 ;
T_1 * V_101 ;
struct V_11 * V_12 ;
T_2 V_18 , V_6 , V_20 ;
struct V_26 * V_27 = NULL ;
struct V_365 * V_366 ;
int V_15 ;
F_4 ( L_17 , V_363 ) ;
if ( V_363 < sizeof( * V_12 ) )
return - V_319 ;
V_364 = F_14 ( V_363 , V_43 ) ;
if ( ! V_364 )
return - V_17 ;
if ( F_146 ( V_364 , V_362 -> V_367 , V_363 ) ) {
V_15 = - V_368 ;
goto V_276;
}
V_12 = V_364 ;
V_18 = F_67 ( & V_12 -> V_18 ) ;
V_6 = F_67 ( & V_12 -> V_6 ) ;
V_20 = F_67 ( & V_12 -> V_20 ) ;
if ( V_20 != V_363 - sizeof( * V_12 ) ) {
V_15 = - V_319 ;
goto V_276;
}
if ( V_6 != V_34 ) {
V_27 = F_147 ( V_6 ) ;
if ( ! V_27 ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_369 ) ;
goto V_276;
}
}
if ( V_18 >= F_2 ( V_370 ) ||
V_370 [ V_18 ] . V_371 == NULL ) {
F_4 ( L_18 , V_18 ) ;
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_372 ) ;
goto V_276;
}
if ( ( V_27 && V_18 < V_125 ) ||
( ! V_27 && V_18 >= V_125 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_369 ) ;
goto V_276;
}
V_366 = & V_370 [ V_18 ] ;
if ( ( V_366 -> V_373 && V_20 < V_366 -> V_28 ) ||
( ! V_366 -> V_373 && V_20 != V_366 -> V_28 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_146 ) ;
goto V_276;
}
if ( V_27 )
F_38 ( V_5 , V_27 ) ;
V_101 = V_364 + sizeof( * V_12 ) ;
V_15 = V_366 -> V_371 ( V_5 , V_27 , V_101 , V_20 ) ;
if ( V_15 < 0 )
goto V_276;
V_15 = V_363 ;
V_276:
if ( V_27 )
F_148 ( V_27 ) ;
F_15 ( V_364 ) ;
return V_15 ;
}
static void F_149 ( struct V_126 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , * V_8 ) ;
F_55 ( V_7 ) ;
}
int F_150 ( struct V_26 * V_27 )
{
return F_62 ( V_374 , V_27 , NULL , 0 , NULL ) ;
}
int F_151 ( struct V_26 * V_27 )
{
T_1 V_8 = V_369 ;
F_50 ( 0 , V_27 , F_149 , & V_8 ) ;
return F_62 ( V_375 , V_27 , NULL , 0 , NULL ) ;
}
static void F_152 ( struct V_126 * V_7 , void * V_25 )
{
struct V_376 * V_187 = V_25 ;
F_57 ( V_7 -> V_5 , V_7 -> V_18 , V_187 -> V_27 ) ;
F_56 ( & V_7 -> V_128 ) ;
if ( V_187 -> V_5 == NULL ) {
V_187 -> V_5 = V_7 -> V_5 ;
F_48 ( V_187 -> V_5 ) ;
}
F_45 ( V_7 ) ;
}
int F_60 ( struct V_26 * V_27 , T_1 V_377 )
{
struct V_376 V_187 = { NULL , V_27 } ;
int V_15 ;
if ( ! F_21 ( V_117 , & V_27 -> V_54 ) )
return 0 ;
F_50 ( V_134 , V_27 , F_152 , & V_187 ) ;
if ( V_377 ) {
T_1 V_144 = 0 ;
if ( F_21 ( V_74 , & V_27 -> V_54 ) )
V_144 |= V_154 ;
if ( F_21 ( V_75 , & V_27 -> V_54 ) )
V_144 |= V_155 ;
if ( V_144 )
F_29 ( V_27 , V_156 , 1 , & V_144 ) ;
F_31 ( V_27 ) ;
F_115 ( V_27 , V_27 -> V_92 ) ;
F_28 ( V_27 ) ;
} else {
T_1 V_8 = V_147 ;
F_50 ( 0 , V_27 , F_149 , & V_8 ) ;
}
V_15 = F_65 ( V_27 , V_187 . V_5 ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
return V_15 ;
}
int F_153 ( struct V_26 * V_27 , T_1 V_378 )
{
struct V_376 V_187 = { NULL , V_27 } ;
bool V_150 = false ;
int V_15 = 0 ;
if ( V_378 ) {
if ( ! F_39 ( V_75 , & V_27 -> V_54 ) )
V_150 = true ;
} else {
if ( F_35 ( V_75 , & V_27 -> V_54 ) )
V_150 = true ;
}
F_50 ( V_145 , V_27 , F_152 ,
& V_187 ) ;
if ( V_150 )
V_15 = F_65 ( V_27 , V_187 . V_5 ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
return V_15 ;
}
int F_154 ( struct V_26 * V_27 , T_1 V_379 )
{
struct V_376 V_187 = { NULL , V_27 } ;
bool V_150 = false ;
int V_15 = 0 ;
if ( V_379 ) {
if ( ! F_39 ( V_74 , & V_27 -> V_54 ) )
V_150 = true ;
} else {
if ( F_35 ( V_74 , & V_27 -> V_54 ) )
V_150 = true ;
}
F_50 ( V_148 , V_27 , F_152 ,
& V_187 ) ;
if ( V_150 )
V_15 = F_65 ( V_27 , V_187 . V_5 ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
return V_15 ;
}
int F_155 ( struct V_26 * V_27 , T_1 V_144 , T_1 V_8 )
{
T_1 V_380 = F_1 ( V_8 ) ;
if ( V_144 & V_154 )
F_50 ( V_148 , V_27 ,
F_149 , & V_380 ) ;
if ( V_144 & V_155 )
F_50 ( V_145 , V_27 ,
F_149 , & V_380 ) ;
return 0 ;
}
int F_156 ( struct V_26 * V_27 , struct V_381 * V_200 , bool V_382 )
{
struct V_383 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_384 = V_382 ;
F_43 ( & V_14 . V_200 . V_202 . V_119 , & V_200 -> V_119 ) ;
V_14 . V_200 . V_202 . type = V_214 ;
V_14 . V_200 . type = V_200 -> type ;
memcpy ( V_14 . V_200 . V_82 , V_200 -> V_82 , 16 ) ;
V_14 . V_200 . V_203 = V_200 -> V_203 ;
return F_62 ( V_385 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_157 ( struct V_26 * V_27 , struct V_386 * V_200 , T_1 V_382 )
{
struct V_387 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_384 = V_382 ;
F_43 ( & V_14 . V_200 . V_202 . V_119 , & V_200 -> V_119 ) ;
V_14 . V_200 . V_202 . type = V_200 -> V_388 ;
V_14 . V_200 . V_358 = V_200 -> V_358 ;
V_14 . V_200 . V_359 = V_200 -> V_359 ;
V_14 . V_200 . V_360 = V_200 -> V_360 ;
if ( V_200 -> type == V_356 )
V_14 . V_200 . V_355 = 1 ;
memcpy ( V_14 . V_200 . rand , V_200 -> rand , sizeof( V_200 -> rand ) ) ;
memcpy ( V_14 . V_200 . V_82 , V_200 -> V_82 , sizeof( V_200 -> V_82 ) ) ;
return F_62 ( V_389 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_158 ( struct V_26 * V_27 , T_6 * V_119 , T_1 V_226 ,
T_1 V_204 , T_4 V_158 , T_1 * V_108 , T_1 V_91 ,
T_1 * V_111 )
{
char V_364 [ 512 ] ;
struct V_390 * V_14 = ( void * ) V_364 ;
T_2 V_85 = 0 ;
F_43 ( & V_14 -> V_202 . V_119 , V_119 ) ;
V_14 -> V_202 . type = F_93 ( V_226 , V_204 ) ;
V_14 -> V_158 = F_159 ( V_158 ) ;
if ( V_91 > 0 )
V_85 = F_160 ( V_14 -> V_104 , 0 , V_94 ,
V_108 , V_91 ) ;
if ( V_111 && memcmp ( V_111 , L_19 , 3 ) != 0 )
V_85 = F_160 ( V_14 -> V_104 , V_85 ,
V_391 , V_111 , 3 ) ;
F_8 ( V_85 , & V_14 -> V_85 ) ;
return F_62 ( V_392 , V_27 , V_364 ,
sizeof( * V_14 ) + V_85 , NULL ) ;
}
static void F_161 ( struct V_126 * V_7 , void * V_25 )
{
struct V_222 * V_101 = V_7 -> V_127 ;
struct V_4 * * V_5 = V_25 ;
struct V_393 V_21 ;
F_43 ( & V_21 . V_202 . V_119 , & V_101 -> V_202 . V_119 ) ;
V_21 . V_202 . type = V_101 -> V_202 . type ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_224 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
* V_5 = V_7 -> V_5 ;
F_48 ( * V_5 ) ;
F_55 ( V_7 ) ;
}
static void F_162 ( struct V_126 * V_7 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_207 * V_101 = V_7 -> V_127 ;
struct V_208 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_43 ( & V_21 . V_202 . V_119 , & V_101 -> V_202 . V_119 ) ;
V_21 . V_202 . type = V_101 -> V_202 . type ;
F_88 ( V_27 , & V_101 -> V_202 . V_119 , V_101 -> V_202 . type , V_7 -> V_5 ) ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , 0 , & V_21 , sizeof( V_21 ) ) ;
F_55 ( V_7 ) ;
}
int F_163 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 )
{
struct V_236 V_14 ;
struct V_4 * V_5 = NULL ;
int V_15 ;
F_50 ( V_224 , V_27 , F_161 , & V_5 ) ;
F_43 ( & V_14 . V_119 , V_119 ) ;
V_14 . type = F_93 ( V_226 , V_204 ) ;
V_15 = F_62 ( V_394 , V_27 , & V_14 , sizeof( V_14 ) ,
V_5 ) ;
if ( V_5 )
F_46 ( V_5 ) ;
F_50 ( V_213 , V_27 , F_162 ,
V_27 ) ;
return V_15 ;
}
int F_164 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_1 V_8 )
{
struct V_393 V_21 ;
struct V_126 * V_7 ;
int V_15 ;
V_7 = F_54 ( V_224 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
F_43 ( & V_21 . V_202 . V_119 , V_119 ) ;
V_21 . V_202 . type = F_93 ( V_226 , V_204 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_224 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_55 ( V_7 ) ;
F_50 ( V_213 , V_27 , F_162 ,
V_27 ) ;
return V_15 ;
}
int F_165 ( struct V_26 * V_27 , T_6 * V_119 , T_1 V_226 ,
T_1 V_204 , T_1 V_8 )
{
struct V_396 V_14 ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = F_93 ( V_226 , V_204 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
return F_62 ( V_397 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_166 ( struct V_26 * V_27 , T_6 * V_119 , T_1 V_398 )
{
struct V_399 V_14 ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = V_214 ;
V_14 . V_398 = V_398 ;
return F_62 ( V_400 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_167 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_8 )
{
struct V_126 * V_7 ;
struct V_401 V_21 ;
int V_15 ;
V_7 = F_54 ( V_246 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
F_43 ( & V_21 . V_202 . V_119 , V_119 ) ;
V_21 . V_202 . type = V_214 ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_246 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_55 ( V_7 ) ;
return V_15 ;
}
int F_168 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_8 )
{
struct V_126 * V_7 ;
struct V_401 V_21 ;
int V_15 ;
V_7 = F_54 ( V_241 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
F_43 ( & V_21 . V_202 . V_119 , V_119 ) ;
V_21 . V_202 . type = V_214 ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_241 ,
F_1 ( V_8 ) , & V_21 , sizeof( V_21 ) ) ;
F_55 ( V_7 ) ;
return V_15 ;
}
int F_169 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_5 V_402 ,
T_1 V_403 )
{
struct V_404 V_14 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = F_93 ( V_226 , V_204 ) ;
V_14 . V_403 = V_403 ;
F_170 ( V_402 , & V_14 . V_402 ) ;
return F_62 ( V_405 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_171 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 )
{
struct V_406 V_14 ;
F_4 ( L_4 , V_27 -> V_108 ) ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = F_93 ( V_226 , V_204 ) ;
return F_62 ( V_407 , V_27 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
static int F_172 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_1 V_8 ,
T_1 V_18 )
{
struct V_126 * V_7 ;
struct V_408 V_21 ;
int V_15 ;
V_7 = F_54 ( V_18 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
F_43 ( & V_21 . V_202 . V_119 , V_119 ) ;
V_21 . V_202 . type = F_93 ( V_226 , V_204 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_18 , F_1 ( V_8 ) ,
& V_21 , sizeof( V_21 ) ) ;
F_55 ( V_7 ) ;
return V_15 ;
}
int F_173 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_1 V_8 )
{
return F_172 ( V_27 , V_119 , V_226 , V_204 ,
V_8 , V_281 ) ;
}
int F_174 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_1 V_8 )
{
return F_172 ( V_27 , V_119 , V_226 , V_204 ,
V_8 , V_284 ) ;
}
int F_175 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_1 V_8 )
{
return F_172 ( V_27 , V_119 , V_226 , V_204 ,
V_8 , V_287 ) ;
}
int F_176 ( struct V_26 * V_27 , T_6 * V_119 ,
T_1 V_226 , T_1 V_204 , T_1 V_8 )
{
return F_172 ( V_27 , V_119 , V_226 , V_204 ,
V_8 , V_289 ) ;
}
int F_177 ( struct V_26 * V_27 , T_6 * V_119 , T_1 V_226 ,
T_1 V_204 , T_1 V_8 )
{
struct V_409 V_14 ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = F_93 ( V_226 , V_204 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
return F_62 ( V_410 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_178 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_376 V_187 = { NULL , V_27 } ;
bool V_150 = false ;
int V_15 = 0 ;
if ( V_8 ) {
T_1 V_380 = F_1 ( V_8 ) ;
F_50 ( V_161 , V_27 ,
F_149 , & V_380 ) ;
return 0 ;
}
if ( F_21 ( V_162 , & V_27 -> V_158 ) ) {
if ( ! F_39 ( V_78 , & V_27 -> V_54 ) )
V_150 = true ;
} else {
if ( F_35 ( V_78 , & V_27 -> V_54 ) )
V_150 = true ;
}
F_50 ( V_161 , V_27 , F_152 ,
& V_187 ) ;
if ( V_150 )
V_15 = F_65 ( V_27 , V_187 . V_5 ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
return V_15 ;
}
static int F_179 ( struct V_26 * V_27 )
{
struct V_100 V_101 ;
if ( ! ( V_27 -> V_63 [ 6 ] & V_102 ) )
return 0 ;
memset ( V_27 -> V_104 , 0 , sizeof( V_27 -> V_104 ) ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
return F_29 ( V_27 , V_105 , sizeof( V_101 ) , & V_101 ) ;
}
int F_180 ( struct V_26 * V_27 , T_1 V_411 , T_1 V_8 )
{
struct V_376 V_187 = { NULL , V_27 } ;
bool V_150 = false ;
int V_15 = 0 ;
if ( V_8 ) {
T_1 V_380 = F_1 ( V_8 ) ;
if ( V_411 && F_35 ( V_79 ,
& V_27 -> V_54 ) )
V_15 = F_65 ( V_27 , NULL ) ;
F_50 ( V_164 , V_27 , F_149 ,
& V_380 ) ;
return V_15 ;
}
if ( V_411 ) {
if ( ! F_39 ( V_79 , & V_27 -> V_54 ) )
V_150 = true ;
} else {
if ( F_35 ( V_79 , & V_27 -> V_54 ) )
V_150 = true ;
}
F_50 ( V_164 , V_27 , F_152 , & V_187 ) ;
if ( V_150 )
V_15 = F_65 ( V_27 , V_187 . V_5 ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
if ( F_21 ( V_79 , & V_27 -> V_54 ) )
F_28 ( V_27 ) ;
else
F_179 ( V_27 ) ;
return V_15 ;
}
static void F_181 ( struct V_126 * V_7 , void * V_25 )
{
struct V_376 * V_187 = V_25 ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , V_187 -> F_1 ,
V_187 -> V_27 -> V_111 , 3 ) ;
F_56 ( & V_7 -> V_128 ) ;
if ( V_187 -> V_5 == NULL ) {
V_187 -> V_5 = V_7 -> V_5 ;
F_48 ( V_187 -> V_5 ) ;
}
F_45 ( V_7 ) ;
}
int F_182 ( struct V_26 * V_27 , T_1 * V_111 ,
T_1 V_8 )
{
struct V_376 V_187 = { NULL , V_27 , F_1 (status) } ;
int V_15 = 0 ;
F_41 ( V_113 , & V_27 -> V_54 ) ;
F_50 ( V_189 , V_27 , F_181 , & V_187 ) ;
F_50 ( V_180 , V_27 , F_181 , & V_187 ) ;
F_50 ( V_186 , V_27 , F_181 , & V_187 ) ;
if ( ! V_8 )
V_15 = F_62 ( V_412 , V_27 , V_111 ,
3 , NULL ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
return V_15 ;
}
int F_183 ( struct V_26 * V_27 , T_1 * V_108 , T_1 V_8 )
{
struct V_126 * V_7 ;
struct V_293 V_14 ;
bool V_150 = false ;
int V_15 = 0 ;
if ( memcmp ( V_108 , V_27 -> V_92 , sizeof( V_27 -> V_92 ) ) != 0 ) {
memcpy ( V_27 -> V_92 , V_108 , sizeof( V_27 -> V_92 ) ) ;
V_150 = true ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_108 , V_108 , V_413 ) ;
memcpy ( V_14 . V_124 , V_27 -> V_124 , V_414 ) ;
V_7 = F_54 ( V_294 , V_27 ) ;
if ( ! V_7 )
goto V_415;
V_150 = true ;
if ( V_8 ) {
V_15 = F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_294 ,
F_1 ( V_8 ) ) ;
goto V_135;
}
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_294 , 0 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
goto V_135;
V_415:
if ( V_150 )
V_15 = F_62 ( V_295 , V_27 , & V_14 ,
sizeof( V_14 ) , V_7 ? V_7 -> V_5 : NULL ) ;
F_28 ( V_27 ) ;
V_135:
if ( V_7 )
F_55 ( V_7 ) ;
return V_15 ;
}
int F_184 ( struct V_26 * V_27 , T_1 * V_300 ,
T_1 * V_301 , T_1 V_8 )
{
struct V_126 * V_7 ;
int V_15 ;
F_4 ( L_20 , V_27 -> V_108 , V_8 ) ;
V_7 = F_54 ( V_296 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
if ( V_8 ) {
V_15 = F_3 ( V_7 -> V_5 , V_27 -> V_55 , V_296 ,
F_1 ( V_8 ) ) ;
} else {
struct V_416 V_21 ;
memcpy ( V_21 . V_300 , V_300 , sizeof( V_21 . V_300 ) ) ;
memcpy ( V_21 . V_301 , V_301 , sizeof( V_21 . V_301 ) ) ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 ,
V_296 , 0 , & V_21 ,
sizeof( V_21 ) ) ;
}
F_55 ( V_7 ) ;
return V_15 ;
}
int F_185 ( struct V_26 * V_27 , T_1 V_411 , T_1 V_8 )
{
struct V_376 V_187 = { NULL , V_27 } ;
bool V_150 = false ;
int V_15 = 0 ;
if ( V_8 ) {
T_1 V_380 = F_1 ( V_8 ) ;
if ( V_411 && F_35 ( V_77 ,
& V_27 -> V_54 ) )
V_15 = F_65 ( V_27 , NULL ) ;
F_50 ( V_171 , V_27 ,
F_149 , & V_380 ) ;
return V_15 ;
}
if ( V_411 ) {
if ( ! F_39 ( V_77 , & V_27 -> V_54 ) )
V_150 = true ;
} else {
if ( F_35 ( V_77 , & V_27 -> V_54 ) )
V_150 = true ;
}
F_50 ( V_171 , V_27 , F_152 , & V_187 ) ;
if ( V_150 )
V_15 = F_65 ( V_27 , V_187 . V_5 ) ;
if ( V_187 . V_5 )
F_46 ( V_187 . V_5 ) ;
return V_15 ;
}
int F_186 ( struct V_26 * V_27 , T_6 * V_119 , T_1 V_226 ,
T_1 V_204 , T_1 * V_111 , T_7 V_417 , T_1 V_418 , T_1
V_419 , T_1 * V_104 , T_2 V_85 )
{
char V_364 [ 512 ] ;
struct V_420 * V_14 = ( void * ) V_364 ;
T_3 V_421 ;
if ( sizeof( * V_14 ) + V_85 + 5 > sizeof( V_364 ) )
return - V_319 ;
memset ( V_364 , 0 , sizeof( V_364 ) ) ;
F_43 ( & V_14 -> V_202 . V_119 , V_119 ) ;
V_14 -> V_202 . type = F_93 ( V_226 , V_204 ) ;
V_14 -> V_417 = V_417 ;
if ( V_418 )
V_14 -> V_158 [ 0 ] |= V_422 ;
if ( ! V_419 )
V_14 -> V_158 [ 0 ] |= V_423 ;
if ( V_85 > 0 )
memcpy ( V_14 -> V_104 , V_104 , V_85 ) ;
if ( V_111 && ! F_187 ( V_14 -> V_104 , V_85 , V_391 ) )
V_85 = F_160 ( V_14 -> V_104 , V_85 , V_391 ,
V_111 , 3 ) ;
F_8 ( V_85 , & V_14 -> V_85 ) ;
V_421 = sizeof( * V_14 ) + V_85 ;
return F_62 ( V_424 , V_27 , V_14 , V_421 , NULL ) ;
}
int F_188 ( struct V_26 * V_27 , T_6 * V_119 , T_1 V_226 ,
T_1 V_204 , T_7 V_417 , T_1 * V_108 , T_1 V_91 )
{
struct V_420 * V_14 ;
char V_364 [ sizeof( * V_14 ) + V_413 + 2 ] ;
T_2 V_85 ;
V_14 = (struct V_420 * ) V_364 ;
memset ( V_364 , 0 , sizeof( V_364 ) ) ;
F_43 ( & V_14 -> V_202 . V_119 , V_119 ) ;
V_14 -> V_202 . type = F_93 ( V_226 , V_204 ) ;
V_14 -> V_417 = V_417 ;
V_85 = F_160 ( V_14 -> V_104 , 0 , V_94 , V_108 ,
V_91 ) ;
F_8 ( V_85 , & V_14 -> V_85 ) ;
return F_62 ( V_424 , V_27 , V_14 ,
sizeof( * V_14 ) + V_85 , NULL ) ;
}
int F_189 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_126 * V_7 ;
T_1 type ;
int V_15 ;
F_124 ( V_27 , V_305 ) ;
V_7 = F_54 ( V_307 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
type = V_27 -> V_308 . type ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& type , sizeof( type ) ) ;
F_55 ( V_7 ) ;
return V_15 ;
}
int F_190 ( struct V_26 * V_27 , T_1 V_8 )
{
struct V_126 * V_7 ;
int V_15 ;
V_7 = F_54 ( V_326 , V_27 ) ;
if ( ! V_7 )
return - V_395 ;
V_15 = F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , F_1 ( V_8 ) ,
& V_27 -> V_308 . type , sizeof( V_27 -> V_308 . type ) ) ;
F_55 ( V_7 ) ;
return V_15 ;
}
int F_191 ( struct V_26 * V_27 , T_1 V_425 )
{
struct V_426 V_14 ;
struct V_126 * V_7 ;
F_4 ( L_21 , V_27 -> V_108 , V_425 ) ;
if ( V_425 )
V_7 = F_54 ( V_307 , V_27 ) ;
else
V_7 = F_54 ( V_326 , V_27 ) ;
if ( V_7 != NULL ) {
T_1 type = V_27 -> V_308 . type ;
F_11 ( V_7 -> V_5 , V_27 -> V_55 , V_7 -> V_18 , 0 , & type ,
sizeof( type ) ) ;
F_55 ( V_7 ) ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . type = V_27 -> V_308 . type ;
V_14 . V_425 = V_425 ;
return F_62 ( V_427 , V_27 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_192 ( struct V_26 * V_27 , T_6 * V_119 , T_1 type )
{
struct V_126 * V_7 ;
struct V_428 V_14 ;
V_7 = F_54 ( V_339 , V_27 ) ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = type ;
return F_62 ( V_429 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
int F_193 ( struct V_26 * V_27 , T_6 * V_119 , T_1 type )
{
struct V_126 * V_7 ;
struct V_430 V_14 ;
V_7 = F_54 ( V_341 , V_27 ) ;
F_43 ( & V_14 . V_202 . V_119 , V_119 ) ;
V_14 . V_202 . type = type ;
return F_62 ( V_431 , V_27 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
