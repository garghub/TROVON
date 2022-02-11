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
static T_1 * F_29 ( struct V_1 * V_2 , T_1 * V_29 , T_6 V_24 )
{
T_1 * V_76 = V_29 , * V_77 = NULL ;
struct V_78 * V_79 ;
if ( V_24 < 4 )
return V_76 ;
F_20 (uuid, &hdev->uuids, list) {
T_2 V_80 ;
if ( V_79 -> V_81 != 16 )
continue;
V_80 = F_30 ( & V_79 -> V_79 [ 12 ] ) ;
if ( V_80 < 0x1100 )
continue;
if ( V_80 == V_82 )
continue;
if ( ! V_77 ) {
V_77 = V_76 ;
V_77 [ 0 ] = 1 ;
V_77 [ 1 ] = V_83 ;
V_76 += 2 ;
}
if ( ( V_76 - V_29 ) + sizeof( T_2 ) > V_24 ) {
V_77 [ 1 ] = V_84 ;
break;
}
* V_76 ++ = ( V_80 & 0x00ff ) ;
* V_76 ++ = ( V_80 & 0xff00 ) >> 8 ;
V_77 [ 0 ] += sizeof( V_80 ) ;
}
return V_76 ;
}
static T_1 * F_31 ( struct V_1 * V_2 , T_1 * V_29 , T_6 V_24 )
{
T_1 * V_76 = V_29 , * V_77 = NULL ;
struct V_78 * V_79 ;
if ( V_24 < 6 )
return V_76 ;
F_20 (uuid, &hdev->uuids, list) {
if ( V_79 -> V_81 != 32 )
continue;
if ( ! V_77 ) {
V_77 = V_76 ;
V_77 [ 0 ] = 1 ;
V_77 [ 1 ] = V_85 ;
V_76 += 2 ;
}
if ( ( V_76 - V_29 ) + sizeof( T_5 ) > V_24 ) {
V_77 [ 1 ] = V_86 ;
break;
}
memcpy ( V_76 , & V_79 -> V_79 [ 12 ] , sizeof( T_5 ) ) ;
V_76 += sizeof( T_5 ) ;
V_77 [ 0 ] += sizeof( T_5 ) ;
}
return V_76 ;
}
static T_1 * F_32 ( struct V_1 * V_2 , T_1 * V_29 , T_6 V_24 )
{
T_1 * V_76 = V_29 , * V_77 = NULL ;
struct V_78 * V_79 ;
if ( V_24 < 18 )
return V_76 ;
F_20 (uuid, &hdev->uuids, list) {
if ( V_79 -> V_81 != 128 )
continue;
if ( ! V_77 ) {
V_77 = V_76 ;
V_77 [ 0 ] = 1 ;
V_77 [ 1 ] = V_87 ;
V_76 += 2 ;
}
if ( ( V_76 - V_29 ) + 16 > V_24 ) {
V_77 [ 1 ] = V_88 ;
break;
}
memcpy ( V_76 , V_79 -> V_79 , 16 ) ;
V_76 += 16 ;
V_77 [ 0 ] += 16 ;
}
return V_76 ;
}
static void F_33 ( struct V_1 * V_2 , T_1 * V_29 )
{
T_1 * V_76 = V_29 ;
T_3 V_89 ;
V_89 = strlen ( V_2 -> V_90 ) ;
if ( V_89 > 0 ) {
if ( V_89 > 48 ) {
V_89 = 48 ;
V_76 [ 1 ] = V_91 ;
} else
V_76 [ 1 ] = V_92 ;
V_76 [ 0 ] = V_89 + 1 ;
memcpy ( V_76 + 2 , V_2 -> V_90 , V_89 ) ;
V_76 += ( V_89 + 2 ) ;
}
if ( V_2 -> V_93 != V_94 ) {
V_76 [ 0 ] = 2 ;
V_76 [ 1 ] = V_95 ;
V_76 [ 2 ] = ( T_1 ) V_2 -> V_93 ;
V_76 += 3 ;
}
if ( V_2 -> V_96 > 0 ) {
V_76 [ 0 ] = 9 ;
V_76 [ 1 ] = V_97 ;
F_16 ( V_2 -> V_96 , V_76 + 2 ) ;
F_16 ( V_2 -> V_98 , V_76 + 4 ) ;
F_16 ( V_2 -> V_99 , V_76 + 6 ) ;
F_16 ( V_2 -> V_100 , V_76 + 8 ) ;
V_76 += 10 ;
}
V_76 = F_29 ( V_2 , V_76 , V_101 - ( V_76 - V_29 ) ) ;
V_76 = F_31 ( V_2 , V_76 , V_101 - ( V_76 - V_29 ) ) ;
V_76 = F_32 ( V_2 , V_76 , V_101 - ( V_76 - V_29 ) ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_102 V_103 ;
if ( ! F_28 ( V_2 ) )
return 0 ;
if ( ! F_35 ( V_2 ) )
return 0 ;
if ( ! F_22 ( V_74 , & V_2 -> V_53 ) )
return 0 ;
if ( F_22 ( V_104 , & V_2 -> V_53 ) )
return 0 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
F_33 ( V_2 , V_103 . V_29 ) ;
if ( memcmp ( V_103 . V_29 , V_2 -> V_105 , sizeof( V_103 . V_29 ) ) == 0 )
return 0 ;
memcpy ( V_2 -> V_105 , V_103 . V_29 , sizeof( V_103 . V_29 ) ) ;
return F_36 ( V_2 , V_106 , sizeof( V_103 ) , & V_103 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
T_1 V_107 = 0 ;
F_20 (uuid, &hdev->uuids, list)
V_107 |= V_79 -> V_108 ;
return V_107 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_109 [ 3 ] ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
if ( ! F_28 ( V_2 ) )
return 0 ;
if ( F_22 ( V_104 , & V_2 -> V_53 ) )
return 0 ;
V_109 [ 0 ] = V_2 -> V_111 ;
V_109 [ 1 ] = V_2 -> V_112 ;
V_109 [ 2 ] = F_37 ( V_2 ) ;
if ( memcmp ( V_109 , V_2 -> V_113 , 3 ) == 0 )
return 0 ;
V_19 = F_36 ( V_2 , V_114 , sizeof( V_109 ) , V_109 ) ;
if ( V_19 == 0 )
F_39 ( V_115 , & V_2 -> V_53 ) ;
return V_19 ;
}
static void F_40 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_41 ( V_117 , struct V_1 ,
V_118 . V_117 ) ;
if ( ! F_42 ( V_104 , & V_2 -> V_53 ) )
return;
F_43 ( V_2 ) ;
F_34 ( V_2 ) ;
F_38 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_46 ( V_119 , & V_2 -> V_53 ) )
return;
F_47 ( & V_2 -> V_118 , F_40 ) ;
F_48 ( V_71 , & V_2 -> V_53 ) ;
}
static int F_49 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_120 V_25 ;
F_5 ( L_5 , V_9 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_50 ( & V_25 . V_121 , & V_2 -> V_121 ) ;
V_25 . V_32 = V_2 -> V_122 ;
V_25 . V_123 = F_9 ( V_2 -> V_123 ) ;
V_25 . V_124 = F_51 ( F_23 ( V_2 ) ) ;
V_25 . V_125 = F_51 ( F_27 ( V_2 ) ) ;
memcpy ( V_25 . V_113 , V_2 -> V_113 , 3 ) ;
memcpy ( V_25 . V_110 , V_2 -> V_90 , sizeof( V_2 -> V_90 ) ) ;
memcpy ( V_25 . V_126 , V_2 -> V_126 , sizeof( V_2 -> V_126 ) ) ;
F_44 ( V_2 ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_127 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
static void F_52 ( struct V_128 * V_11 )
{
F_53 ( V_11 -> V_9 ) ;
F_17 ( V_11 -> V_129 ) ;
F_17 ( V_11 ) ;
}
static struct V_128 * F_54 ( struct V_8 * V_9 , T_2 V_22 ,
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
F_55 ( V_9 ) ;
F_56 ( & V_11 -> V_130 , & V_2 -> V_131 ) ;
return V_11 ;
}
static void F_57 ( T_2 V_22 , struct V_1 * V_2 ,
void (* F_58)( struct V_128 * V_11 ,
void * V_29 ) ,
void * V_29 )
{
struct V_128 * V_11 , * V_132 ;
F_59 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_22 > 0 && V_11 -> V_22 != V_22 )
continue;
F_58 ( V_11 , V_29 ) ;
}
}
static struct V_128 * F_60 ( T_2 V_22 , struct V_1 * V_2 )
{
struct V_128 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 == V_22 )
return V_11 ;
}
return NULL ;
}
static void F_61 ( struct V_128 * V_11 )
{
F_62 ( & V_11 -> V_130 ) ;
F_52 ( V_11 ) ;
}
static int F_63 ( struct V_8 * V_9 , T_2 V_22 , struct V_1 * V_2 )
{
T_7 V_57 = F_51 ( F_27 ( V_2 ) ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_22 , 0 , & V_57 ,
sizeof( V_57 ) ) ;
}
static int F_64 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_134 ,
V_135 ) ;
F_43 ( V_2 ) ;
if ( F_42 ( V_136 , & V_2 -> V_53 ) ) {
F_65 ( & V_2 -> V_137 ) ;
if ( V_103 -> V_107 ) {
F_54 ( V_9 , V_134 , V_2 ,
V_29 , V_24 ) ;
V_19 = F_66 ( V_2 , 1 ) ;
goto V_138;
}
}
if ( ! ! V_103 -> V_107 == F_28 ( V_2 ) ) {
V_19 = F_63 ( V_9 , V_134 , V_2 ) ;
goto V_138;
}
if ( F_60 ( V_134 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_134 ,
V_139 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_134 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
if ( V_103 -> V_107 )
F_67 ( V_2 -> V_140 , & V_2 -> V_141 ) ;
else
F_67 ( V_2 -> V_140 , & V_2 -> V_137 . V_117 ) ;
V_19 = 0 ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_68 ( T_2 V_142 , struct V_1 * V_2 , void * V_29 , T_2 V_30 ,
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
F_69 ( V_14 ) ;
F_70 ( V_14 , V_143 ) ;
F_11 ( V_14 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_8 * V_144 )
{
T_7 V_18 ;
V_18 = F_51 ( F_27 ( V_2 ) ) ;
return F_68 ( V_145 , V_2 , & V_18 , sizeof( V_18 ) , V_144 ) ;
}
static int F_72 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_146 * V_103 = V_29 ;
struct V_128 * V_11 ;
T_2 V_147 ;
T_1 V_148 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_135 ) ;
V_147 = F_73 ( V_103 -> V_147 ) ;
if ( ! V_103 -> V_107 && V_147 > 0 )
return F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_135 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) && V_147 > 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_151 ) ;
goto V_138;
}
if ( F_60 ( V_149 , V_2 ) ||
F_60 ( V_152 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_139 ) ;
goto V_138;
}
if ( ! F_22 ( V_69 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_149 ,
V_153 ) ;
goto V_138;
}
if ( ! F_28 ( V_2 ) ) {
bool V_154 = false ;
if ( ! ! V_103 -> V_107 != F_22 ( V_70 , & V_2 -> V_53 ) ) {
F_74 ( V_70 , & V_2 -> V_53 ) ;
V_154 = true ;
}
V_19 = F_63 ( V_9 , V_149 , V_2 ) ;
if ( V_19 < 0 )
goto V_138;
if ( V_154 )
V_19 = F_71 ( V_2 , V_9 ) ;
goto V_138;
}
if ( ! ! V_103 -> V_107 == F_22 ( V_70 , & V_2 -> V_53 ) ) {
if ( V_2 -> V_155 > 0 ) {
F_65 ( & V_2 -> V_156 ) ;
V_2 -> V_155 = 0 ;
}
if ( V_103 -> V_107 && V_147 > 0 ) {
V_2 -> V_155 = V_147 ;
F_75 ( V_2 -> V_157 , & V_2 -> V_156 ,
F_76 ( V_2 -> V_155 * 1000 ) ) ;
}
V_19 = F_63 ( V_9 , V_149 , V_2 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_149 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
V_148 = V_158 ;
if ( V_103 -> V_107 )
V_148 |= V_159 ;
else
F_65 ( & V_2 -> V_156 ) ;
V_19 = F_36 ( V_2 , V_160 , 1 , & V_148 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
if ( V_103 -> V_107 )
V_2 -> V_155 = V_147 ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_77 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
struct V_128 * V_11 ;
T_1 V_148 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_135 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_154 = false ;
if ( ! ! V_103 -> V_107 != F_22 ( V_69 , & V_2 -> V_53 ) )
V_154 = true ;
if ( V_103 -> V_107 ) {
F_39 ( V_69 , & V_2 -> V_53 ) ;
} else {
F_48 ( V_69 , & V_2 -> V_53 ) ;
F_48 ( V_70 , & V_2 -> V_53 ) ;
}
V_19 = F_63 ( V_9 , V_152 , V_2 ) ;
if ( V_19 < 0 )
goto V_138;
if ( V_154 )
V_19 = F_71 ( V_2 , V_9 ) ;
goto V_138;
}
if ( F_60 ( V_149 , V_2 ) ||
F_60 ( V_152 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_152 ,
V_139 ) ;
goto V_138;
}
if ( ! ! V_103 -> V_107 == F_22 ( V_161 , & V_2 -> V_162 ) ) {
V_19 = F_63 ( V_9 , V_152 , V_2 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_152 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
if ( V_103 -> V_107 ) {
V_148 = V_158 ;
} else {
V_148 = 0 ;
if ( F_22 ( V_163 , & V_2 -> V_162 ) &&
V_2 -> V_155 > 0 )
F_65 ( & V_2 -> V_156 ) ;
}
V_19 = F_36 ( V_2 , V_160 , 1 , & V_148 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_78 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_164 ,
V_135 ) ;
F_43 ( V_2 ) ;
if ( V_103 -> V_107 )
F_39 ( V_71 , & V_2 -> V_53 ) ;
else
F_48 ( V_71 , & V_2 -> V_53 ) ;
V_19 = F_63 ( V_9 , V_164 , V_2 ) ;
if ( V_19 < 0 )
goto V_138;
V_19 = F_71 ( V_2 , V_9 ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_79 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
struct V_128 * V_11 ;
T_1 V_107 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_165 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_165 ,
V_135 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
bool V_154 = false ;
if ( ! ! V_103 -> V_107 != F_22 ( V_73 ,
& V_2 -> V_53 ) ) {
F_74 ( V_73 , & V_2 -> V_53 ) ;
V_154 = true ;
}
V_19 = F_63 ( V_9 , V_165 , V_2 ) ;
if ( V_19 < 0 )
goto V_138;
if ( V_154 )
V_19 = F_71 ( V_2 , V_9 ) ;
goto V_138;
}
if ( F_60 ( V_165 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_165 ,
V_139 ) ;
goto V_138;
}
V_107 = ! ! V_103 -> V_107 ;
if ( F_22 ( V_166 , & V_2 -> V_162 ) == V_107 ) {
V_19 = F_63 ( V_9 , V_165 , V_2 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_165 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
V_19 = F_36 ( V_2 , V_167 , sizeof( V_107 ) , & V_107 ) ;
if ( V_19 < 0 ) {
F_61 ( V_11 ) ;
goto V_138;
}
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_80 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
struct V_128 * V_11 ;
T_1 V_107 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_24 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_168 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_168 ,
V_135 ) ;
F_43 ( V_2 ) ;
V_107 = ! ! V_103 -> V_107 ;
if ( ! F_28 ( V_2 ) ) {
bool V_154 = false ;
if ( V_107 != F_22 ( V_74 , & V_2 -> V_53 ) ) {
F_74 ( V_74 , & V_2 -> V_53 ) ;
V_154 = true ;
}
V_19 = F_63 ( V_9 , V_168 , V_2 ) ;
if ( V_19 < 0 )
goto V_138;
if ( V_154 )
V_19 = F_71 ( V_2 , V_9 ) ;
goto V_138;
}
if ( F_60 ( V_168 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_168 ,
V_139 ) ;
goto V_138;
}
if ( F_22 ( V_74 , & V_2 -> V_53 ) == V_107 ) {
V_19 = F_63 ( V_9 , V_168 , V_2 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_168 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
V_19 = F_36 ( V_2 , V_169 , sizeof( V_107 ) , & V_107 ) ;
if ( V_19 < 0 ) {
F_61 ( V_11 ) ;
goto V_138;
}
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_81 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! V_66 )
return F_4 ( V_9 , V_2 -> V_54 , V_170 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_170 ,
V_135 ) ;
if ( V_103 -> V_107 )
F_39 ( V_75 , & V_2 -> V_53 ) ;
else
F_48 ( V_75 , & V_2 -> V_53 ) ;
return F_63 ( V_9 , V_170 , V_2 ) ;
}
static int F_82 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
struct V_171 V_172 ;
struct V_128 * V_11 ;
int V_19 ;
T_1 V_107 , V_173 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_26 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_174 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_174 ,
V_135 ) ;
F_43 ( V_2 ) ;
V_107 = ! ! V_103 -> V_107 ;
V_173 = F_83 ( V_2 ) ;
if ( ! F_28 ( V_2 ) || V_107 == V_173 ) {
bool V_154 = false ;
if ( V_107 != F_22 ( V_72 , & V_2 -> V_53 ) ) {
F_74 ( V_72 , & V_2 -> V_53 ) ;
V_154 = true ;
}
V_19 = F_63 ( V_9 , V_174 , V_2 ) ;
if ( V_19 < 0 )
goto V_175;
if ( V_154 )
V_19 = F_71 ( V_2 , V_9 ) ;
goto V_175;
}
if ( F_60 ( V_174 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_174 ,
V_139 ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_174 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_175;
}
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
if ( V_107 ) {
V_172 . V_176 = V_107 ;
V_172 . V_177 = F_84 ( V_2 ) ;
}
V_19 = F_36 ( V_2 , V_178 , sizeof( V_172 ) ,
& V_172 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static T_1 F_85 ( const T_1 * V_79 )
{
T_5 V_107 ;
if ( memcmp ( V_79 , V_179 , 12 ) )
return 128 ;
V_107 = F_86 ( & V_79 [ 12 ] ) ;
if ( V_107 > 0xffff )
return 32 ;
return 16 ;
}
static int F_87 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 , T_2 V_24 )
{
struct V_180 * V_103 = V_29 ;
struct V_128 * V_11 ;
struct V_78 * V_79 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
if ( F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_181 ,
V_139 ) ;
goto V_138;
}
V_79 = F_15 ( sizeof( * V_79 ) , V_20 ) ;
if ( ! V_79 ) {
V_19 = - V_21 ;
goto V_138;
}
memcpy ( V_79 -> V_79 , V_103 -> V_79 , 16 ) ;
V_79 -> V_108 = V_103 -> V_108 ;
V_79 -> V_81 = F_85 ( V_103 -> V_79 ) ;
F_88 ( & V_79 -> V_130 , & V_2 -> V_182 ) ;
V_19 = F_38 ( V_2 ) ;
if ( V_19 < 0 )
goto V_138;
V_19 = F_34 ( V_2 ) ;
if ( V_19 < 0 )
goto V_138;
if ( ! F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_181 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_181 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static bool F_89 ( struct V_1 * V_2 )
{
if ( ! F_28 ( V_2 ) )
return false ;
if ( ! F_46 ( V_104 , & V_2 -> V_53 ) ) {
F_75 ( V_2 -> V_157 , & V_2 -> V_118 ,
V_183 ) ;
return true ;
}
return false ;
}
static int F_90 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_184 * V_103 = V_29 ;
struct V_128 * V_11 ;
struct V_78 * V_185 , * V_132 ;
T_1 V_186 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_19 , V_187 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
if ( F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_188 ,
V_139 ) ;
goto V_175;
}
if ( memcmp ( V_103 -> V_79 , V_186 , 16 ) == 0 ) {
V_19 = F_91 ( V_2 ) ;
if ( F_89 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_188 ,
0 , V_2 -> V_113 , 3 ) ;
goto V_175;
}
goto F_38;
}
V_187 = 0 ;
F_59 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_185 -> V_79 , V_103 -> V_79 , 16 ) != 0 )
continue;
F_62 ( & V_185 -> V_130 ) ;
F_17 ( V_185 ) ;
V_187 ++ ;
}
if ( V_187 == 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_188 ,
V_135 ) ;
goto V_175;
}
F_38:
V_19 = F_38 ( V_2 ) ;
if ( V_19 < 0 )
goto V_175;
V_19 = F_34 ( V_2 ) ;
if ( V_19 < 0 )
goto V_175;
if ( ! F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_188 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_188 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_92 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_189 * V_103 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_6 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_150 ) ;
if ( F_22 ( V_115 , & V_2 -> V_53 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_139 ) ;
if ( ( V_103 -> V_191 & 0x03 ) != 0 || ( V_103 -> V_192 & 0xe0 ) != 0 )
return F_4 ( V_9 , V_2 -> V_54 , V_190 ,
V_135 ) ;
F_43 ( V_2 ) ;
V_2 -> V_112 = V_103 -> V_192 ;
V_2 -> V_111 = V_103 -> V_191 ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_190 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_175;
}
if ( F_42 ( V_104 , & V_2 -> V_53 ) ) {
F_44 ( V_2 ) ;
F_93 ( & V_2 -> V_118 ) ;
F_43 ( V_2 ) ;
F_34 ( V_2 ) ;
}
V_19 = F_38 ( V_2 ) ;
if ( V_19 < 0 )
goto V_175;
if ( ! F_22 ( V_115 , & V_2 -> V_53 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_190 , 0 ,
V_2 -> V_113 , 3 ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_190 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 )
V_19 = - V_21 ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_94 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_193 * V_103 = V_29 ;
T_2 V_194 , V_195 ;
int V_44 ;
V_194 = F_73 ( V_103 -> V_194 ) ;
V_195 = sizeof( * V_103 ) + V_194 *
sizeof( struct V_196 ) ;
if ( V_195 != V_24 ) {
F_95 ( L_7 ,
V_24 , V_195 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_197 ,
V_135 ) ;
}
if ( V_103 -> V_198 != 0x00 && V_103 -> V_198 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_197 ,
V_135 ) ;
F_5 ( L_8 , V_2 -> V_110 , V_103 -> V_198 ,
V_194 ) ;
for ( V_44 = 0 ; V_44 < V_194 ; V_44 ++ ) {
struct V_196 * V_199 = & V_103 -> V_200 [ V_44 ] ;
if ( V_199 -> V_201 . type != V_202 )
return F_4 ( V_9 , V_2 -> V_54 , V_197 ,
V_135 ) ;
}
F_43 ( V_2 ) ;
F_96 ( V_2 ) ;
F_39 ( V_203 , & V_2 -> V_53 ) ;
if ( V_103 -> V_198 )
F_39 ( V_204 , & V_2 -> V_53 ) ;
else
F_48 ( V_204 , & V_2 -> V_53 ) ;
for ( V_44 = 0 ; V_44 < V_194 ; V_44 ++ ) {
struct V_196 * V_199 = & V_103 -> V_200 [ V_44 ] ;
F_97 ( V_2 , NULL , 0 , & V_199 -> V_201 . V_121 , V_199 -> V_107 ,
V_199 -> type , V_199 -> V_205 ) ;
}
F_12 ( V_9 , V_2 -> V_54 , V_197 , 0 , NULL , 0 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_206 , struct V_8 * V_143 )
{
struct V_207 V_18 ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = V_206 ;
return F_68 ( V_208 , V_2 , & V_18 , sizeof( V_18 ) ,
V_143 ) ;
}
static int F_99 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_209 * V_103 = V_29 ;
struct V_210 V_25 ;
struct V_211 V_212 ;
struct V_128 * V_11 ;
struct V_213 * V_214 ;
int V_19 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_50 ( & V_25 . V_201 . V_121 , & V_103 -> V_201 . V_121 ) ;
V_25 . V_201 . type = V_103 -> V_201 . type ;
if ( ! F_100 ( V_103 -> V_201 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_215 ,
V_135 ,
& V_25 , sizeof( V_25 ) ) ;
if ( V_103 -> V_216 != 0x00 && V_103 -> V_216 != 0x01 )
return F_12 ( V_9 , V_2 -> V_54 , V_215 ,
V_135 ,
& V_25 , sizeof( V_25 ) ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_215 ,
V_151 , & V_25 , sizeof( V_25 ) ) ;
goto V_175;
}
if ( V_103 -> V_201 . type == V_202 )
V_19 = F_101 ( V_2 , & V_103 -> V_201 . V_121 ) ;
else
V_19 = F_102 ( V_2 , & V_103 -> V_201 . V_121 ) ;
if ( V_19 < 0 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_215 ,
V_217 , & V_25 , sizeof( V_25 ) ) ;
goto V_175;
}
if ( V_103 -> V_216 ) {
if ( V_103 -> V_201 . type == V_202 )
V_214 = F_103 ( V_2 , V_218 ,
& V_103 -> V_201 . V_121 ) ;
else
V_214 = F_103 ( V_2 , V_219 ,
& V_103 -> V_201 . V_121 ) ;
} else {
V_214 = NULL ;
}
if ( ! V_214 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_215 , 0 ,
& V_25 , sizeof( V_25 ) ) ;
F_98 ( V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type , V_9 ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_215 , V_2 , V_103 ,
sizeof( * V_103 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_175;
}
V_212 . V_220 = F_9 ( V_214 -> V_220 ) ;
V_212 . V_221 = 0x13 ;
V_19 = F_36 ( V_2 , V_222 , sizeof( V_212 ) , & V_212 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int V_216 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_223 * V_103 = V_29 ;
struct V_224 V_25 ;
struct V_211 V_212 ;
struct V_128 * V_11 ;
struct V_213 * V_214 ;
int V_19 ;
F_5 ( L_9 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_50 ( & V_25 . V_201 . V_121 , & V_103 -> V_201 . V_121 ) ;
V_25 . V_201 . type = V_103 -> V_201 . type ;
if ( ! F_100 ( V_103 -> V_201 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_225 ,
V_135 ,
& V_25 , sizeof( V_25 ) ) ;
F_43 ( V_2 ) ;
if ( ! F_22 ( V_226 , & V_2 -> V_162 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_225 ,
V_151 , & V_25 , sizeof( V_25 ) ) ;
goto V_138;
}
if ( F_60 ( V_225 , V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_225 ,
V_139 , & V_25 , sizeof( V_25 ) ) ;
goto V_138;
}
if ( V_103 -> V_201 . type == V_202 )
V_214 = F_103 ( V_2 , V_218 ,
& V_103 -> V_201 . V_121 ) ;
else
V_214 = F_103 ( V_2 , V_219 , & V_103 -> V_201 . V_121 ) ;
if ( ! V_214 || V_214 -> V_227 == V_228 || V_214 -> V_227 == V_229 ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_225 ,
V_230 , & V_25 , sizeof( V_25 ) ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_225 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
V_212 . V_220 = F_9 ( V_214 -> V_220 ) ;
V_212 . V_221 = V_231 ;
V_19 = F_36 ( V_2 , V_222 , sizeof( V_212 ) , & V_212 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static T_1 F_104 ( T_1 V_232 , T_1 V_206 )
{
switch ( V_232 ) {
case V_219 :
switch ( V_206 ) {
case V_233 :
return V_234 ;
default:
return V_235 ;
}
default:
return V_202 ;
}
}
static int F_105 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_30 )
{
struct V_236 * V_25 ;
struct V_213 * V_237 ;
T_3 V_26 ;
int V_19 ;
T_2 V_44 ;
F_5 ( L_9 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_238 ,
V_151 ) ;
goto V_175;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_239 , & V_237 -> V_162 ) )
V_44 ++ ;
}
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_240 ) ) ;
V_25 = F_15 ( V_26 , V_20 ) ;
if ( ! V_25 ) {
V_19 = - V_21 ;
goto V_175;
}
V_44 = 0 ;
F_20 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_239 , & V_237 -> V_162 ) )
continue;
F_50 ( & V_25 -> V_201 [ V_44 ] . V_121 , & V_237 -> V_241 ) ;
V_25 -> V_201 [ V_44 ] . type = F_104 ( V_237 -> type , V_237 -> V_242 ) ;
if ( V_237 -> type == V_243 || V_237 -> type == V_244 )
continue;
V_44 ++ ;
}
V_25 -> V_245 = F_9 ( V_44 ) ;
V_26 = sizeof( * V_25 ) + ( V_44 * sizeof( struct V_240 ) ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_238 , 0 , V_25 ,
V_26 ) ;
F_17 ( V_25 ) ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_106 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_246 * V_103 )
{
struct V_128 * V_11 ;
int V_19 ;
V_11 = F_54 ( V_9 , V_247 , V_2 , V_103 ,
sizeof( * V_103 ) ) ;
if ( ! V_11 )
return - V_21 ;
V_19 = F_36 ( V_2 , V_248 ,
sizeof( V_103 -> V_201 . V_121 ) , & V_103 -> V_201 . V_121 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
return V_19 ;
}
static int F_107 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_213 * V_214 ;
struct V_249 * V_103 = V_29 ;
struct V_250 V_251 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_9 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_252 ,
V_151 ) ;
goto V_138;
}
V_214 = F_103 ( V_2 , V_218 , & V_103 -> V_201 . V_121 ) ;
if ( ! V_214 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_252 ,
V_230 ) ;
goto V_138;
}
if ( V_214 -> V_253 == V_254 && V_103 -> V_205 != 16 ) {
struct V_246 V_255 ;
memcpy ( & V_255 . V_201 , & V_103 -> V_201 , sizeof( V_255 . V_201 ) ) ;
F_95 ( L_10 ) ;
V_19 = F_106 ( V_9 , V_2 , & V_255 ) ;
if ( V_19 >= 0 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_252 ,
V_135 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_252 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
F_50 ( & V_251 . V_121 , & V_103 -> V_201 . V_121 ) ;
V_251 . V_205 = V_103 -> V_205 ;
memcpy ( V_251 . V_256 , V_103 -> V_256 , sizeof( V_251 . V_256 ) ) ;
V_19 = F_36 ( V_2 , V_257 , sizeof( V_251 ) , & V_251 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_108 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_258 * V_103 = V_29 ;
F_5 ( L_9 ) ;
F_43 ( V_2 ) ;
V_2 -> V_259 = V_103 -> V_259 ;
F_5 ( L_11 , V_2 -> V_110 ,
V_2 -> V_259 ) ;
F_44 ( V_2 ) ;
return F_12 ( V_9 , V_2 -> V_54 , V_260 , 0 , NULL ,
0 ) ;
}
static struct V_128 * F_109 ( struct V_213 * V_214 )
{
struct V_1 * V_2 = V_214 -> V_2 ;
struct V_128 * V_11 ;
F_20 (cmd, &hdev->mgmt_pending, list) {
if ( V_11 -> V_22 != V_261 )
continue;
if ( V_11 -> V_262 != V_214 )
continue;
return V_11 ;
}
return NULL ;
}
static void F_110 ( struct V_128 * V_11 , T_1 V_12 )
{
struct V_263 V_25 ;
struct V_213 * V_214 = V_11 -> V_262 ;
F_50 ( & V_25 . V_201 . V_121 , & V_214 -> V_241 ) ;
V_25 . V_201 . type = F_104 ( V_214 -> type , V_214 -> V_242 ) ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_261 , V_12 ,
& V_25 , sizeof( V_25 ) ) ;
V_214 -> V_264 = NULL ;
V_214 -> V_265 = NULL ;
V_214 -> V_266 = NULL ;
F_111 ( V_214 ) ;
F_61 ( V_11 ) ;
}
static void F_112 ( struct V_213 * V_214 , T_1 V_12 )
{
struct V_128 * V_11 ;
F_5 ( L_12 , V_12 ) ;
V_11 = F_109 ( V_214 ) ;
if ( ! V_11 )
F_5 ( L_13 ) ;
else
F_110 ( V_11 , F_2 ( V_12 ) ) ;
}
static void F_113 ( struct V_213 * V_214 , T_1 V_12 )
{
struct V_128 * V_11 ;
F_5 ( L_12 , V_12 ) ;
if ( ! V_12 )
return;
V_11 = F_109 ( V_214 ) ;
if ( ! V_11 )
F_5 ( L_13 ) ;
else
F_110 ( V_11 , F_2 ( V_12 ) ) ;
}
static int F_114 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_267 * V_103 = V_29 ;
struct V_263 V_25 ;
struct V_128 * V_11 ;
T_1 V_268 , V_269 ;
struct V_213 * V_214 ;
int V_19 ;
F_5 ( L_9 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_50 ( & V_25 . V_201 . V_121 , & V_103 -> V_201 . V_121 ) ;
V_25 . V_201 . type = V_103 -> V_201 . type ;
if ( ! F_100 ( V_103 -> V_201 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_261 ,
V_135 ,
& V_25 , sizeof( V_25 ) ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_261 ,
V_151 , & V_25 , sizeof( V_25 ) ) ;
goto V_175;
}
V_268 = V_270 ;
if ( V_103 -> V_271 == 0x03 )
V_269 = V_272 ;
else
V_269 = V_273 ;
if ( V_103 -> V_201 . type == V_202 )
V_214 = F_115 ( V_2 , V_218 , & V_103 -> V_201 . V_121 ,
V_103 -> V_201 . type , V_268 , V_269 ) ;
else
V_214 = F_115 ( V_2 , V_219 , & V_103 -> V_201 . V_121 ,
V_103 -> V_201 . type , V_268 , V_269 ) ;
if ( F_116 ( V_214 ) ) {
int V_12 ;
if ( F_117 ( V_214 ) == - V_274 )
V_12 = V_139 ;
else
V_12 = V_275 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_261 ,
V_12 , & V_25 ,
sizeof( V_25 ) ) ;
goto V_175;
}
if ( V_214 -> V_264 ) {
F_111 ( V_214 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_261 ,
V_139 , & V_25 , sizeof( V_25 ) ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_261 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
F_111 ( V_214 ) ;
goto V_175;
}
if ( V_103 -> V_201 . type == V_202 )
V_214 -> V_264 = F_112 ;
else
V_214 -> V_264 = F_113 ;
V_214 -> V_265 = F_112 ;
V_214 -> V_266 = F_112 ;
V_214 -> V_259 = V_103 -> V_271 ;
V_11 -> V_262 = V_214 ;
if ( V_214 -> V_227 == V_276 &&
F_118 ( V_214 , V_268 , V_269 ) )
F_110 ( V_11 , 0 ) ;
V_19 = 0 ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_119 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_240 * V_201 = V_29 ;
struct V_128 * V_11 ;
struct V_213 * V_214 ;
int V_19 ;
F_5 ( L_9 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_277 ,
V_151 ) ;
goto V_175;
}
V_11 = F_60 ( V_261 , V_2 ) ;
if ( ! V_11 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_277 ,
V_135 ) ;
goto V_175;
}
V_214 = V_11 -> V_262 ;
if ( F_120 ( & V_201 -> V_121 , & V_214 -> V_241 ) != 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_277 ,
V_135 ) ;
goto V_175;
}
F_110 ( V_11 , V_278 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_277 , 0 ,
V_201 , sizeof( * V_201 ) ) ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_121 ( struct V_8 * V_9 , struct V_1 * V_2 ,
T_8 * V_121 , T_1 type , T_2 V_279 ,
T_2 V_280 , T_7 V_281 )
{
struct V_128 * V_11 ;
struct V_213 * V_214 ;
int V_19 ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_279 ,
V_151 ) ;
goto V_282;
}
if ( type == V_202 )
V_214 = F_103 ( V_2 , V_218 , V_121 ) ;
else
V_214 = F_103 ( V_2 , V_219 , V_121 ) ;
if ( ! V_214 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_279 ,
V_230 ) ;
goto V_282;
}
if ( type == V_234 || type == V_235 ) {
V_19 = F_122 ( V_214 , V_279 , V_281 ) ;
if ( ! V_19 )
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_279 ,
V_283 ) ;
else
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_279 ,
V_7 ) ;
goto V_282;
}
V_11 = F_54 ( V_9 , V_279 , V_2 , V_121 , sizeof( * V_121 ) ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_282;
}
if ( V_280 == V_284 ) {
struct V_285 V_103 ;
F_50 ( & V_103 . V_121 , V_121 ) ;
V_103 . V_281 = V_281 ;
V_19 = F_36 ( V_2 , V_280 , sizeof( V_103 ) , & V_103 ) ;
} else
V_19 = F_36 ( V_2 , V_280 , sizeof( * V_121 ) , V_121 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_282:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_123 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_246 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_121 ( V_9 , V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ,
V_247 ,
V_248 , 0 ) ;
}
static int F_124 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_286 * V_103 = V_29 ;
F_5 ( L_9 ) ;
if ( V_24 != sizeof( * V_103 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_287 ,
V_135 ) ;
return F_121 ( V_9 , V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ,
V_287 ,
V_288 , 0 ) ;
}
static int F_125 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_289 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_121 ( V_9 , V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ,
V_290 ,
V_291 , 0 ) ;
}
static int F_126 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_292 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_121 ( V_9 , V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ,
V_293 ,
V_284 , V_103 -> V_281 ) ;
}
static int F_127 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_294 * V_103 = V_29 ;
F_5 ( L_9 ) ;
return F_121 ( V_9 , V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ,
V_295 ,
V_296 , 0 ) ;
}
static int F_128 ( struct V_1 * V_2 , const char * V_110 )
{
struct V_297 V_103 ;
memcpy ( V_103 . V_110 , V_110 , sizeof( V_103 . V_110 ) ) ;
return F_36 ( V_2 , V_298 , sizeof( V_103 ) , & V_103 ) ;
}
static int F_129 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_299 * V_103 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_9 ) ;
F_43 ( V_2 ) ;
memcpy ( V_2 -> V_126 , V_103 -> V_126 , sizeof( V_2 -> V_126 ) ) ;
if ( ! F_28 ( V_2 ) ) {
memcpy ( V_2 -> V_90 , V_103 -> V_110 , sizeof( V_2 -> V_90 ) ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_300 , 0 ,
V_29 , V_24 ) ;
if ( V_19 < 0 )
goto V_138;
V_19 = F_68 ( V_301 , V_2 , V_29 , V_24 ,
V_9 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_300 , V_2 , V_29 , V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
V_19 = F_128 ( V_2 , V_103 -> V_110 ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_130 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_30 )
{
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_302 ,
V_151 ) ;
goto V_175;
}
if ( ! F_24 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_302 ,
V_150 ) ;
goto V_175;
}
if ( F_60 ( V_302 , V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_302 ,
V_139 ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_302 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_175;
}
V_19 = F_36 ( V_2 , V_303 , 0 , NULL ) ;
if ( V_19 < 0 )
F_61 ( V_11 ) ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_131 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_304 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_14 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
V_19 = F_132 ( V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_305 ,
V_103 -> V_306 ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = V_283 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_307 , V_12 ,
& V_103 -> V_201 , sizeof( V_103 -> V_201 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_133 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_308 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
V_19 = F_134 ( V_2 , & V_103 -> V_201 . V_121 ) ;
if ( V_19 < 0 )
V_12 = V_135 ;
else
V_12 = V_283 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_309 ,
V_12 , & V_103 -> V_201 , sizeof( V_103 -> V_201 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
int F_135 ( struct V_1 * V_2 )
{
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
V_19 = F_136 ( V_2 , V_310 ) ;
if ( V_19 < 0 )
F_137 ( V_2 , V_311 ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_138 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_312 * V_103 = V_29 ;
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
if ( ! F_28 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_151 ) ;
goto V_138;
}
if ( F_22 ( V_314 , & V_2 -> V_53 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_139 ) ;
goto V_138;
}
if ( V_2 -> V_315 . V_227 != V_311 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_139 ) ;
goto V_138;
}
V_11 = F_54 ( V_9 , V_313 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_138;
}
V_2 -> V_315 . type = V_103 -> type ;
switch ( V_2 -> V_315 . type ) {
case V_316 :
if ( ! F_25 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_150 ) ;
F_61 ( V_11 ) ;
goto V_138;
}
V_19 = F_136 ( V_2 , V_317 ) ;
break;
case V_318 :
if ( ! F_83 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_150 ) ;
F_61 ( V_11 ) ;
goto V_138;
}
V_19 = F_139 ( V_2 , V_319 , V_320 ,
V_321 , V_322 ) ;
break;
case V_323 :
if ( ! F_83 ( V_2 ) || ! F_25 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_150 ) ;
F_61 ( V_11 ) ;
goto V_138;
}
V_19 = F_139 ( V_2 , V_319 , V_320 , V_321 ,
V_324 ) ;
break;
default:
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_313 ,
V_135 ) ;
F_61 ( V_11 ) ;
goto V_138;
}
if ( V_19 < 0 )
F_61 ( V_11 ) ;
else
F_137 ( V_2 , V_325 ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_140 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_326 * V_327 = V_29 ;
struct V_128 * V_11 ;
struct V_328 V_103 ;
struct V_329 * V_330 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
if ( ! F_141 ( V_2 ) ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_331 ,
V_153 , & V_327 -> type ,
sizeof( V_327 -> type ) ) ;
goto V_175;
}
if ( V_2 -> V_315 . type != V_327 -> type ) {
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_331 ,
V_135 , & V_327 -> type ,
sizeof( V_327 -> type ) ) ;
goto V_175;
}
V_11 = F_54 ( V_9 , V_331 , V_2 , NULL , 0 ) ;
if ( ! V_11 ) {
V_19 = - V_21 ;
goto V_175;
}
switch ( V_2 -> V_315 . V_227 ) {
case V_332 :
if ( F_22 ( V_333 , & V_2 -> V_162 ) )
V_19 = F_142 ( V_2 ) ;
else
V_19 = F_143 ( V_2 ) ;
break;
case V_334 :
V_330 = F_144 ( V_2 , V_335 ,
V_336 ) ;
if ( ! V_330 ) {
F_61 ( V_11 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 ,
V_331 , 0 ,
& V_327 -> type ,
sizeof( V_327 -> type ) ) ;
F_137 ( V_2 , V_311 ) ;
goto V_175;
}
F_50 ( & V_103 . V_121 , & V_330 -> V_29 . V_121 ) ;
V_19 = F_36 ( V_2 , V_337 ,
sizeof( V_103 ) , & V_103 ) ;
break;
default:
F_5 ( L_15 , V_2 -> V_315 . V_227 ) ;
V_19 = - V_338 ;
}
if ( V_19 < 0 )
F_61 ( V_11 ) ;
else
F_137 ( V_2 , V_339 ) ;
V_175:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_145 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_340 * V_103 = V_29 ;
struct V_329 * V_330 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_43 ( V_2 ) ;
if ( ! F_141 ( V_2 ) ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_341 ,
V_7 ) ;
goto V_138;
}
V_330 = F_146 ( V_2 , & V_103 -> V_201 . V_121 ) ;
if ( ! V_330 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_341 ,
V_135 ) ;
goto V_138;
}
if ( V_103 -> V_342 ) {
V_330 -> V_343 = V_344 ;
F_62 ( & V_330 -> V_130 ) ;
} else {
V_330 -> V_343 = V_345 ;
F_147 ( V_2 , V_330 ) ;
}
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_341 , 0 , & V_103 -> V_201 ,
sizeof( V_103 -> V_201 ) ) ;
V_138:
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_148 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_346 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
if ( ! F_100 ( V_103 -> V_201 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_347 ,
V_135 ,
& V_103 -> V_201 , sizeof( V_103 -> V_201 ) ) ;
F_43 ( V_2 ) ;
V_19 = F_149 ( V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ) ;
if ( V_19 < 0 )
V_12 = V_7 ;
else
V_12 = V_283 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_347 , V_12 ,
& V_103 -> V_201 , sizeof( V_103 -> V_201 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_150 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_348 * V_103 = V_29 ;
T_1 V_12 ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
if ( ! F_100 ( V_103 -> V_201 . type ) )
return F_12 ( V_9 , V_2 -> V_54 , V_349 ,
V_135 ,
& V_103 -> V_201 , sizeof( V_103 -> V_201 ) ) ;
F_43 ( V_2 ) ;
V_19 = F_151 ( V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type ) ;
if ( V_19 < 0 )
V_12 = V_135 ;
else
V_12 = V_283 ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_349 , V_12 ,
& V_103 -> V_201 , sizeof( V_103 -> V_201 ) ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_152 ( struct V_8 * V_9 , struct V_1 * V_2 , void * V_29 ,
T_2 V_24 )
{
struct V_350 * V_103 = V_29 ;
int V_19 ;
T_9 V_351 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
V_351 = F_73 ( V_103 -> V_351 ) ;
if ( V_351 > 0x0002 )
return F_4 ( V_9 , V_2 -> V_54 , V_352 ,
V_135 ) ;
F_43 ( V_2 ) ;
V_2 -> V_96 = V_351 ;
V_2 -> V_98 = F_73 ( V_103 -> V_353 ) ;
V_2 -> V_99 = F_73 ( V_103 -> V_354 ) ;
V_2 -> V_100 = F_73 ( V_103 -> V_32 ) ;
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_352 , 0 , NULL , 0 ) ;
F_34 ( V_2 ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
static int F_153 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_29 , T_2 V_24 )
{
struct V_133 * V_103 = V_29 ;
struct V_355 V_356 ;
T_1 type ;
int V_19 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
if ( ! F_25 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_150 ) ;
if ( V_103 -> V_107 != 0x00 && V_103 -> V_107 != 0x01 )
return F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_135 ) ;
if ( ! F_28 ( V_2 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_151 ) ;
if ( ! F_22 ( V_69 , & V_2 -> V_53 ) )
return F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_153 ) ;
F_43 ( V_2 ) ;
if ( V_103 -> V_107 ) {
type = V_358 ;
V_356 . V_359 = F_8 ( 0x0100 ) ;
} else {
type = V_360 ;
V_356 . V_359 = F_8 ( 0x0800 ) ;
}
V_356 . V_361 = F_8 ( 0x0012 ) ;
V_19 = F_36 ( V_2 , V_362 , sizeof( V_356 ) ,
& V_356 ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_7 ) ;
goto V_282;
}
V_19 = F_36 ( V_2 , V_363 , 1 , & type ) ;
if ( V_19 < 0 ) {
V_19 = F_4 ( V_9 , V_2 -> V_54 , V_357 ,
V_7 ) ;
goto V_282;
}
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_357 , 0 ,
NULL , 0 ) ;
V_282:
F_44 ( V_2 ) ;
return V_19 ;
}
static bool F_154 ( struct V_364 * V_199 )
{
if ( V_199 -> V_365 != 0x00 && V_199 -> V_365 != 0x01 )
return false ;
if ( V_199 -> V_366 != 0x00 && V_199 -> V_366 != 0x01 )
return false ;
if ( ! F_155 ( V_199 -> V_201 . type ) )
return false ;
return true ;
}
static int F_156 ( struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_367 , T_2 V_24 )
{
struct V_368 * V_103 = V_367 ;
T_2 V_194 , V_195 ;
int V_44 , V_19 ;
V_194 = F_73 ( V_103 -> V_194 ) ;
V_195 = sizeof( * V_103 ) + V_194 *
sizeof( struct V_364 ) ;
if ( V_195 != V_24 ) {
F_95 ( L_16 ,
V_24 , V_195 ) ;
return F_4 ( V_9 , V_2 -> V_54 , V_369 ,
V_135 ) ;
}
F_5 ( L_17 , V_2 -> V_110 , V_194 ) ;
for ( V_44 = 0 ; V_44 < V_194 ; V_44 ++ ) {
struct V_364 * V_199 = & V_103 -> V_200 [ V_44 ] ;
if ( ! F_154 ( V_199 ) )
return F_4 ( V_9 , V_2 -> V_54 ,
V_369 ,
V_135 ) ;
}
F_43 ( V_2 ) ;
F_157 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_194 ; V_44 ++ ) {
struct V_364 * V_199 = & V_103 -> V_200 [ V_44 ] ;
T_1 type ;
if ( V_199 -> V_366 )
type = V_370 ;
else
type = V_371 ;
F_158 ( V_2 , & V_199 -> V_201 . V_121 ,
F_159 ( V_199 -> V_201 . type ) ,
type , 0 , V_199 -> V_365 , V_199 -> V_107 ,
V_199 -> V_372 , V_199 -> V_373 , V_199 -> rand ) ;
}
V_19 = F_12 ( V_9 , V_2 -> V_54 , V_369 , 0 ,
NULL , 0 ) ;
F_44 ( V_2 ) ;
return V_19 ;
}
int F_160 ( struct V_8 * V_9 , struct V_374 * V_375 , T_3 V_376 )
{
void * V_377 ;
T_1 * V_103 ;
struct V_15 * V_16 ;
T_2 V_22 , V_10 , V_24 ;
struct V_1 * V_2 = NULL ;
const struct V_378 * V_379 ;
int V_19 ;
F_5 ( L_18 , V_376 ) ;
if ( V_376 < sizeof( * V_16 ) )
return - V_380 ;
V_377 = F_15 ( V_376 , V_20 ) ;
if ( ! V_377 )
return - V_21 ;
if ( F_161 ( V_377 , V_375 -> V_381 , V_376 ) ) {
V_19 = - V_338 ;
goto V_282;
}
V_16 = V_377 ;
V_22 = F_73 ( V_16 -> V_22 ) ;
V_10 = F_73 ( V_16 -> V_10 ) ;
V_24 = F_73 ( V_16 -> V_24 ) ;
if ( V_24 != V_376 - sizeof( * V_16 ) ) {
V_19 = - V_380 ;
goto V_282;
}
if ( V_10 != V_36 ) {
V_2 = F_162 ( V_10 ) ;
if ( ! V_2 ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_382 ) ;
goto V_282;
}
}
if ( V_22 >= F_3 ( V_383 ) ||
V_383 [ V_22 ] . V_384 == NULL ) {
F_5 ( L_19 , V_22 ) ;
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_385 ) ;
goto V_282;
}
if ( ( V_2 && V_22 < V_127 ) ||
( ! V_2 && V_22 >= V_127 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_382 ) ;
goto V_282;
}
V_379 = & V_383 [ V_22 ] ;
if ( ( V_379 -> V_386 && V_24 < V_379 -> V_30 ) ||
( ! V_379 -> V_386 && V_24 != V_379 -> V_30 ) ) {
V_19 = F_4 ( V_9 , V_10 , V_22 ,
V_135 ) ;
goto V_282;
}
if ( V_2 )
F_45 ( V_9 , V_2 ) ;
V_103 = V_377 + sizeof( * V_16 ) ;
V_19 = V_379 -> V_384 ( V_9 , V_2 , V_103 , V_24 ) ;
if ( V_19 < 0 )
goto V_282;
V_19 = V_376 ;
V_282:
if ( V_2 )
F_163 ( V_2 ) ;
F_17 ( V_377 ) ;
return V_19 ;
}
static void F_164 ( struct V_128 * V_11 , void * V_29 )
{
T_1 * V_12 = V_29 ;
F_4 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , * V_12 ) ;
F_61 ( V_11 ) ;
}
int F_165 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
return - V_387 ;
return F_68 ( V_388 , V_2 , NULL , 0 , NULL ) ;
}
int F_166 ( struct V_1 * V_2 )
{
T_1 V_12 = V_382 ;
if ( ! F_1 ( V_2 ) )
return - V_387 ;
F_57 ( 0 , V_2 , F_164 , & V_12 ) ;
return F_68 ( V_389 , V_2 , NULL , 0 , NULL ) ;
}
static void F_167 ( struct V_128 * V_11 , void * V_29 )
{
struct V_390 * V_185 = V_29 ;
F_63 ( V_11 -> V_9 , V_11 -> V_22 , V_185 -> V_2 ) ;
F_62 ( & V_11 -> V_130 ) ;
if ( V_185 -> V_9 == NULL ) {
V_185 -> V_9 = V_11 -> V_9 ;
F_55 ( V_185 -> V_9 ) ;
}
F_52 ( V_11 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
T_1 V_148 = 0 ;
if ( F_22 ( V_69 , & V_2 -> V_53 ) )
V_148 |= V_158 ;
if ( F_22 ( V_70 , & V_2 -> V_53 ) )
V_148 |= V_159 ;
if ( ! V_148 )
return 0 ;
return F_36 ( V_2 , V_160 , 1 , & V_148 ) ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_391 )
{
struct V_390 V_185 = { NULL , V_2 } ;
int V_19 ;
if ( ! F_22 ( V_119 , & V_2 -> V_53 ) )
return 0 ;
F_57 ( V_134 , V_2 , F_167 , & V_185 ) ;
if ( V_391 ) {
T_1 V_392 ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) &&
! F_169 ( V_2 ) ) {
T_1 V_393 = 1 ;
F_36 ( V_2 , V_169 , 1 , & V_393 ) ;
}
if ( F_22 ( V_72 , & V_2 -> V_53 ) ) {
struct V_171 V_103 ;
V_103 . V_176 = 1 ;
V_103 . V_177 = F_84 ( V_2 ) ;
if ( V_103 . V_176 != F_83 ( V_2 ) ||
V_103 . V_177 != F_170 ( V_2 ) )
F_36 ( V_2 ,
V_178 ,
sizeof( V_103 ) , & V_103 ) ;
}
V_392 = F_22 ( V_73 , & V_2 -> V_53 ) ;
if ( V_392 != F_22 ( V_166 , & V_2 -> V_162 ) )
F_36 ( V_2 , V_167 ,
sizeof( V_392 ) , & V_392 ) ;
if ( F_25 ( V_2 ) ) {
F_168 ( V_2 ) ;
F_38 ( V_2 ) ;
F_128 ( V_2 , V_2 -> V_90 ) ;
F_34 ( V_2 ) ;
}
} else {
T_1 V_12 = V_151 ;
T_1 V_394 [] = { 0 , 0 , 0 } ;
F_57 ( 0 , V_2 , F_164 , & V_12 ) ;
if ( memcmp ( V_2 -> V_113 , V_394 , sizeof( V_394 ) ) != 0 )
F_68 ( V_395 , V_2 ,
V_394 , sizeof( V_394 ) , NULL ) ;
}
V_19 = F_71 ( V_2 , V_185 . V_9 ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
return V_19 ;
}
int F_171 ( struct V_1 * V_2 , T_1 V_396 )
{
struct V_390 V_185 = { NULL , V_2 } ;
bool V_154 = false ;
int V_19 = 0 ;
if ( V_396 ) {
if ( ! F_46 ( V_70 , & V_2 -> V_53 ) )
V_154 = true ;
} else {
if ( F_42 ( V_70 , & V_2 -> V_53 ) )
V_154 = true ;
}
F_57 ( V_149 , V_2 , F_167 ,
& V_185 ) ;
if ( V_154 )
V_19 = F_71 ( V_2 , V_185 . V_9 ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
return V_19 ;
}
int F_172 ( struct V_1 * V_2 , T_1 V_397 )
{
struct V_390 V_185 = { NULL , V_2 } ;
bool V_154 = false ;
int V_19 = 0 ;
if ( V_397 ) {
if ( ! F_46 ( V_69 , & V_2 -> V_53 ) )
V_154 = true ;
} else {
if ( F_42 ( V_69 , & V_2 -> V_53 ) )
V_154 = true ;
}
F_57 ( V_152 , V_2 , F_167 ,
& V_185 ) ;
if ( V_154 )
V_19 = F_71 ( V_2 , V_185 . V_9 ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
return V_19 ;
}
int F_173 ( struct V_1 * V_2 , T_1 V_148 , T_1 V_12 )
{
T_1 V_398 = F_2 ( V_12 ) ;
if ( V_148 & V_158 )
F_57 ( V_152 , V_2 ,
F_164 , & V_398 ) ;
if ( V_148 & V_159 )
F_57 ( V_149 , V_2 ,
F_164 , & V_398 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_2 , struct V_399 * V_199 ,
bool V_400 )
{
struct V_401 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_402 = V_400 ;
F_50 ( & V_18 . V_199 . V_201 . V_121 , & V_199 -> V_121 ) ;
V_18 . V_199 . V_201 . type = V_202 ;
V_18 . V_199 . type = V_199 -> type ;
memcpy ( V_18 . V_199 . V_107 , V_199 -> V_107 , V_403 ) ;
V_18 . V_199 . V_205 = V_199 -> V_205 ;
return F_68 ( V_404 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_175 ( struct V_1 * V_2 , struct V_405 * V_199 , T_1 V_400 )
{
struct V_406 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_402 = V_400 ;
F_50 ( & V_18 . V_199 . V_201 . V_121 , & V_199 -> V_121 ) ;
V_18 . V_199 . V_201 . type = F_104 ( V_219 , V_199 -> V_407 ) ;
V_18 . V_199 . V_365 = V_199 -> V_365 ;
V_18 . V_199 . V_372 = V_199 -> V_372 ;
V_18 . V_199 . V_373 = V_199 -> V_373 ;
if ( V_199 -> type == V_370 )
V_18 . V_199 . V_366 = 1 ;
memcpy ( V_18 . V_199 . rand , V_199 -> rand , sizeof( V_199 -> rand ) ) ;
memcpy ( V_18 . V_199 . V_107 , V_199 -> V_107 , sizeof( V_199 -> V_107 ) ) ;
return F_68 ( V_408 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_176 ( struct V_1 * V_2 , T_8 * V_121 , T_1 V_232 ,
T_1 V_206 , T_5 V_162 , T_1 * V_110 , T_1 V_89 ,
T_1 * V_113 )
{
char V_377 [ 512 ] ;
struct V_409 * V_18 = ( void * ) V_377 ;
T_2 V_410 = 0 ;
F_50 ( & V_18 -> V_201 . V_121 , V_121 ) ;
V_18 -> V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 -> V_162 = F_177 ( V_162 ) ;
if ( V_89 > 0 )
V_410 = F_178 ( V_18 -> V_105 , 0 , V_92 ,
V_110 , V_89 ) ;
if ( V_113 && memcmp ( V_113 , L_20 , 3 ) != 0 )
V_410 = F_178 ( V_18 -> V_105 , V_410 ,
V_411 , V_113 , 3 ) ;
V_18 -> V_410 = F_9 ( V_410 ) ;
return F_68 ( V_412 , V_2 , V_377 ,
sizeof( * V_18 ) + V_410 , NULL ) ;
}
static void F_179 ( struct V_128 * V_11 , void * V_29 )
{
struct V_223 * V_103 = V_11 -> V_129 ;
struct V_8 * * V_9 = V_29 ;
struct V_224 V_25 ;
F_50 ( & V_25 . V_201 . V_121 , & V_103 -> V_201 . V_121 ) ;
V_25 . V_201 . type = V_103 -> V_201 . type ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_225 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
* V_9 = V_11 -> V_9 ;
F_55 ( * V_9 ) ;
F_61 ( V_11 ) ;
}
static void F_180 ( struct V_128 * V_11 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_209 * V_103 = V_11 -> V_129 ;
struct V_210 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_50 ( & V_25 . V_201 . V_121 , & V_103 -> V_201 . V_121 ) ;
V_25 . V_201 . type = V_103 -> V_201 . type ;
F_98 ( V_2 , & V_103 -> V_201 . V_121 , V_103 -> V_201 . type , V_11 -> V_9 ) ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , 0 , & V_25 , sizeof( V_25 ) ) ;
F_61 ( V_11 ) ;
}
int F_181 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_221 )
{
struct V_413 V_18 ;
struct V_8 * V_9 = NULL ;
int V_19 ;
F_57 ( V_225 , V_2 , F_179 , & V_9 ) ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 . V_221 = V_221 ;
V_19 = F_68 ( V_414 , V_2 , & V_18 , sizeof( V_18 ) ,
V_9 ) ;
if ( V_9 )
F_53 ( V_9 ) ;
F_57 ( V_215 , V_2 , F_180 ,
V_2 ) ;
return V_19 ;
}
int F_182 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_12 )
{
struct V_224 V_25 ;
struct V_128 * V_11 ;
int V_19 ;
F_57 ( V_215 , V_2 , F_180 ,
V_2 ) ;
V_11 = F_60 ( V_225 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_50 ( & V_25 . V_201 . V_121 , V_121 ) ;
V_25 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_19 = F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_225 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_61 ( V_11 ) ;
return V_19 ;
}
int F_183 ( struct V_1 * V_2 , T_8 * V_121 , T_1 V_232 ,
T_1 V_206 , T_1 V_12 )
{
struct V_416 V_18 ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_68 ( V_417 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_184 ( struct V_1 * V_2 , T_8 * V_121 , T_1 V_418 )
{
struct V_419 V_18 ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = V_202 ;
V_18 . V_418 = V_418 ;
return F_68 ( V_420 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_185 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_12 )
{
struct V_128 * V_11 ;
struct V_421 V_25 ;
int V_19 ;
V_11 = F_60 ( V_252 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_50 ( & V_25 . V_201 . V_121 , V_121 ) ;
V_25 . V_201 . type = V_202 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_252 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_61 ( V_11 ) ;
return V_19 ;
}
int F_186 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_12 )
{
struct V_128 * V_11 ;
struct V_421 V_25 ;
int V_19 ;
V_11 = F_60 ( V_247 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_50 ( & V_25 . V_201 . V_121 , V_121 ) ;
V_25 . V_201 . type = V_202 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_247 ,
F_2 ( V_12 ) , & V_25 , sizeof( V_25 ) ) ;
F_61 ( V_11 ) ;
return V_19 ;
}
int F_187 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_7 V_422 ,
T_1 V_423 )
{
struct V_424 V_18 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 . V_423 = V_423 ;
V_18 . V_422 = V_422 ;
return F_68 ( V_425 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
int F_188 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 )
{
struct V_426 V_18 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = F_104 ( V_232 , V_206 ) ;
return F_68 ( V_427 , V_2 , & V_18 , sizeof( V_18 ) ,
NULL ) ;
}
static int F_189 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_12 ,
T_1 V_22 )
{
struct V_128 * V_11 ;
struct V_428 V_25 ;
int V_19 ;
V_11 = F_60 ( V_22 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
F_50 ( & V_25 . V_201 . V_121 , V_121 ) ;
V_25 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_22 , F_2 ( V_12 ) ,
& V_25 , sizeof( V_25 ) ) ;
F_61 ( V_11 ) ;
return V_19 ;
}
int F_190 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_12 )
{
return F_189 ( V_2 , V_121 , V_232 , V_206 ,
V_12 , V_287 ) ;
}
int F_191 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_12 )
{
return F_189 ( V_2 , V_121 , V_232 , V_206 ,
V_12 ,
V_290 ) ;
}
int F_192 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_12 )
{
return F_189 ( V_2 , V_121 , V_232 , V_206 ,
V_12 , V_293 ) ;
}
int F_193 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_1 V_12 )
{
return F_189 ( V_2 , V_121 , V_232 , V_206 ,
V_12 ,
V_295 ) ;
}
int F_194 ( struct V_1 * V_2 , T_8 * V_121 ,
T_1 V_232 , T_1 V_206 , T_5 V_281 ,
T_1 V_429 )
{
struct V_430 V_18 ;
F_5 ( L_4 , V_2 -> V_110 ) ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 . V_281 = F_177 ( V_281 ) ;
V_18 . V_429 = V_429 ;
return F_68 ( V_431 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_195 ( struct V_1 * V_2 , T_8 * V_121 , T_1 V_232 ,
T_1 V_206 , T_1 V_12 )
{
struct V_432 V_18 ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 . V_12 = F_2 ( V_12 ) ;
return F_68 ( V_433 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_196 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_390 V_185 = { NULL , V_2 } ;
bool V_154 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_398 = F_2 ( V_12 ) ;
F_57 ( V_165 , V_2 ,
F_164 , & V_398 ) ;
return 0 ;
}
if ( F_22 ( V_166 , & V_2 -> V_162 ) ) {
if ( ! F_46 ( V_73 , & V_2 -> V_53 ) )
V_154 = true ;
} else {
if ( F_42 ( V_73 , & V_2 -> V_53 ) )
V_154 = true ;
}
F_57 ( V_165 , V_2 , F_167 ,
& V_185 ) ;
if ( V_154 )
V_19 = F_71 ( V_2 , V_185 . V_9 ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
return V_19 ;
}
static int F_197 ( struct V_1 * V_2 )
{
struct V_102 V_103 ;
if ( ! F_35 ( V_2 ) )
return 0 ;
memset ( V_2 -> V_105 , 0 , sizeof( V_2 -> V_105 ) ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
return F_36 ( V_2 , V_106 , sizeof( V_103 ) , & V_103 ) ;
}
int F_198 ( struct V_1 * V_2 , T_1 V_434 , T_1 V_12 )
{
struct V_390 V_185 = { NULL , V_2 } ;
bool V_154 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_398 = F_2 ( V_12 ) ;
if ( V_434 && F_42 ( V_74 ,
& V_2 -> V_53 ) )
V_19 = F_71 ( V_2 , NULL ) ;
F_57 ( V_168 , V_2 , F_164 ,
& V_398 ) ;
return V_19 ;
}
if ( V_434 ) {
if ( ! F_46 ( V_74 , & V_2 -> V_53 ) )
V_154 = true ;
} else {
if ( F_42 ( V_74 , & V_2 -> V_53 ) )
V_154 = true ;
}
F_57 ( V_168 , V_2 , F_167 , & V_185 ) ;
if ( V_154 )
V_19 = F_71 ( V_2 , V_185 . V_9 ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
if ( F_22 ( V_74 , & V_2 -> V_53 ) )
F_34 ( V_2 ) ;
else
F_197 ( V_2 ) ;
return V_19 ;
}
static void F_199 ( struct V_128 * V_11 , void * V_29 )
{
struct V_390 * V_185 = V_29 ;
F_12 ( V_11 -> V_9 , V_11 -> V_10 , V_11 -> V_22 , V_185 -> F_2 ,
V_185 -> V_2 -> V_113 , 3 ) ;
F_62 ( & V_11 -> V_130 ) ;
if ( V_185 -> V_9 == NULL ) {
V_185 -> V_9 = V_11 -> V_9 ;
F_55 ( V_185 -> V_9 ) ;
}
F_52 ( V_11 ) ;
}
int F_200 ( struct V_1 * V_2 , T_1 * V_113 ,
T_1 V_12 )
{
struct V_390 V_185 = { NULL , V_2 , F_2 (status) } ;
int V_19 = 0 ;
F_48 ( V_115 , & V_2 -> V_53 ) ;
F_57 ( V_190 , V_2 , F_199 , & V_185 ) ;
F_57 ( V_181 , V_2 , F_199 , & V_185 ) ;
F_57 ( V_188 , V_2 , F_199 , & V_185 ) ;
if ( ! V_12 )
V_19 = F_68 ( V_395 , V_2 , V_113 ,
3 , NULL ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
return V_19 ;
}
int F_201 ( struct V_1 * V_2 , T_1 * V_110 , T_1 V_12 )
{
struct V_128 * V_11 ;
struct V_299 V_18 ;
bool V_154 = false ;
int V_19 = 0 ;
if ( memcmp ( V_110 , V_2 -> V_90 , sizeof( V_2 -> V_90 ) ) != 0 ) {
memcpy ( V_2 -> V_90 , V_110 , sizeof( V_2 -> V_90 ) ) ;
V_154 = true ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memcpy ( V_18 . V_110 , V_110 , V_435 ) ;
memcpy ( V_18 . V_126 , V_2 -> V_126 , V_436 ) ;
V_11 = F_60 ( V_300 , V_2 ) ;
if ( ! V_11 )
goto V_437;
V_154 = true ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_300 ,
F_2 ( V_12 ) ) ;
goto V_138;
}
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_300 , 0 , & V_18 ,
sizeof( V_18 ) ) ;
if ( V_19 < 0 )
goto V_138;
V_437:
if ( V_154 )
V_19 = F_68 ( V_301 , V_2 , & V_18 ,
sizeof( V_18 ) , V_11 ? V_11 -> V_9 : NULL ) ;
if ( ! F_22 ( V_438 , & V_2 -> V_162 ) )
F_34 ( V_2 ) ;
V_138:
if ( V_11 )
F_61 ( V_11 ) ;
return V_19 ;
}
int F_202 ( struct V_1 * V_2 , T_1 * V_305 ,
T_1 * V_306 , T_1 V_12 )
{
struct V_128 * V_11 ;
int V_19 ;
F_5 ( L_21 , V_2 -> V_110 , V_12 ) ;
V_11 = F_60 ( V_302 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
if ( V_12 ) {
V_19 = F_4 ( V_11 -> V_9 , V_2 -> V_54 , V_302 ,
F_2 ( V_12 ) ) ;
} else {
struct V_439 V_25 ;
memcpy ( V_25 . V_305 , V_305 , sizeof( V_25 . V_305 ) ) ;
memcpy ( V_25 . V_306 , V_306 , sizeof( V_25 . V_306 ) ) ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 ,
V_302 , 0 , & V_25 ,
sizeof( V_25 ) ) ;
}
F_61 ( V_11 ) ;
return V_19 ;
}
int F_203 ( struct V_1 * V_2 , T_1 V_434 , T_1 V_12 )
{
struct V_390 V_185 = { NULL , V_2 } ;
bool V_154 = false ;
int V_19 = 0 ;
if ( V_12 ) {
T_1 V_398 = F_2 ( V_12 ) ;
if ( V_434 && F_42 ( V_72 ,
& V_2 -> V_53 ) )
V_19 = F_71 ( V_2 , NULL ) ;
F_57 ( V_174 , V_2 , F_164 ,
& V_398 ) ;
return V_19 ;
}
if ( V_434 ) {
if ( ! F_46 ( V_72 , & V_2 -> V_53 ) )
V_154 = true ;
} else {
if ( F_42 ( V_72 , & V_2 -> V_53 ) )
V_154 = true ;
}
F_57 ( V_174 , V_2 , F_167 , & V_185 ) ;
if ( V_154 )
V_19 = F_71 ( V_2 , V_185 . V_9 ) ;
if ( V_185 . V_9 )
F_53 ( V_185 . V_9 ) ;
return V_19 ;
}
int F_204 ( struct V_1 * V_2 , T_8 * V_121 , T_1 V_232 ,
T_1 V_206 , T_1 * V_113 , T_10 V_440 , T_1 V_441 , T_1
V_393 , T_1 * V_105 , T_2 V_410 )
{
char V_377 [ 512 ] ;
struct V_442 * V_18 = ( void * ) V_377 ;
T_3 V_443 ;
if ( sizeof( * V_18 ) + V_410 + 5 > sizeof( V_377 ) )
return - V_380 ;
memset ( V_377 , 0 , sizeof( V_377 ) ) ;
F_50 ( & V_18 -> V_201 . V_121 , V_121 ) ;
V_18 -> V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 -> V_440 = V_440 ;
if ( V_441 )
V_18 -> V_162 |= F_205 ( V_444 ) ;
if ( ! V_393 )
V_18 -> V_162 |= F_205 ( V_445 ) ;
if ( V_410 > 0 )
memcpy ( V_18 -> V_105 , V_105 , V_410 ) ;
if ( V_113 && ! F_206 ( V_18 -> V_105 , V_410 , V_411 ) )
V_410 = F_178 ( V_18 -> V_105 , V_410 , V_411 ,
V_113 , 3 ) ;
V_18 -> V_410 = F_9 ( V_410 ) ;
V_443 = sizeof( * V_18 ) + V_410 ;
return F_68 ( V_446 , V_2 , V_18 , V_443 , NULL ) ;
}
int F_207 ( struct V_1 * V_2 , T_8 * V_121 , T_1 V_232 ,
T_1 V_206 , T_10 V_440 , T_1 * V_110 , T_1 V_89 )
{
struct V_442 * V_18 ;
char V_377 [ sizeof( * V_18 ) + V_435 + 2 ] ;
T_2 V_410 ;
V_18 = (struct V_442 * ) V_377 ;
memset ( V_377 , 0 , sizeof( V_377 ) ) ;
F_50 ( & V_18 -> V_201 . V_121 , V_121 ) ;
V_18 -> V_201 . type = F_104 ( V_232 , V_206 ) ;
V_18 -> V_440 = V_440 ;
V_410 = F_178 ( V_18 -> V_105 , 0 , V_92 , V_110 ,
V_89 ) ;
V_18 -> V_410 = F_9 ( V_410 ) ;
return F_68 ( V_446 , V_2 , V_18 ,
sizeof( * V_18 ) + V_410 , NULL ) ;
}
int F_208 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_128 * V_11 ;
T_1 type ;
int V_19 ;
F_137 ( V_2 , V_311 ) ;
V_11 = F_60 ( V_313 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
type = V_2 -> V_315 . type ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& type , sizeof( type ) ) ;
F_61 ( V_11 ) ;
return V_19 ;
}
int F_209 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_128 * V_11 ;
int V_19 ;
V_11 = F_60 ( V_331 , V_2 ) ;
if ( ! V_11 )
return - V_415 ;
V_19 = F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , F_2 ( V_12 ) ,
& V_2 -> V_315 . type , sizeof( V_2 -> V_315 . type ) ) ;
F_61 ( V_11 ) ;
return V_19 ;
}
int F_210 ( struct V_1 * V_2 , T_1 V_447 )
{
struct V_448 V_18 ;
struct V_128 * V_11 ;
F_5 ( L_22 , V_2 -> V_110 , V_447 ) ;
if ( V_447 )
V_11 = F_60 ( V_313 , V_2 ) ;
else
V_11 = F_60 ( V_331 , V_2 ) ;
if ( V_11 != NULL ) {
T_1 type = V_2 -> V_315 . type ;
F_12 ( V_11 -> V_9 , V_2 -> V_54 , V_11 -> V_22 , 0 , & type ,
sizeof( type ) ) ;
F_61 ( V_11 ) ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . type = V_2 -> V_315 . type ;
V_18 . V_447 = V_447 ;
return F_68 ( V_449 , V_2 , & V_18 , sizeof( V_18 ) , NULL ) ;
}
int F_211 ( struct V_1 * V_2 , T_8 * V_121 , T_1 type )
{
struct V_128 * V_11 ;
struct V_450 V_18 ;
V_11 = F_60 ( V_347 , V_2 ) ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = type ;
return F_68 ( V_451 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
int F_212 ( struct V_1 * V_2 , T_8 * V_121 , T_1 type )
{
struct V_128 * V_11 ;
struct V_452 V_18 ;
V_11 = F_60 ( V_349 , V_2 ) ;
F_50 ( & V_18 . V_201 . V_121 , V_121 ) ;
V_18 . V_201 . type = type ;
return F_68 ( V_453 , V_2 , & V_18 , sizeof( V_18 ) ,
V_11 ? V_11 -> V_9 : NULL ) ;
}
