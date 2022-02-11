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
static int F_11 ( struct V_4 * V_5 , T_2 V_6 , T_2 V_7 , void * V_21 ,
T_3 V_22 )
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
if ( V_21 )
memcpy ( V_14 -> V_25 , V_21 , V_22 ) ;
V_15 = F_9 ( V_5 , V_10 ) ;
if ( V_15 < 0 )
F_10 ( V_10 ) ;
return V_15 ; ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_26 V_21 ;
F_4 ( L_2 , V_5 ) ;
V_21 . V_27 = V_28 ;
F_8 ( V_29 , & V_21 . V_30 ) ;
return F_11 ( V_5 , V_31 , V_32 , & V_21 ,
sizeof( V_21 ) ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_33 * V_21 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
T_3 V_22 ;
T_2 V_38 ;
int V_39 , V_15 ;
F_4 ( L_2 , V_5 ) ;
F_14 ( & V_40 ) ;
V_38 = 0 ;
F_15 (p, &hci_dev_list) {
V_38 ++ ;
}
V_22 = sizeof( * V_21 ) + ( 2 * V_38 ) ;
V_21 = F_16 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
F_17 ( & V_40 ) ;
return - V_17 ;
}
F_8 ( V_38 , & V_21 -> V_41 ) ;
V_39 = 0 ;
F_18 (d, &hci_dev_list, list) {
if ( F_19 ( V_42 , & V_37 -> V_43 ) )
F_20 ( & V_37 -> V_44 ) ;
if ( F_21 ( V_45 , & V_37 -> V_43 ) )
continue;
F_8 ( V_37 -> V_46 , & V_21 -> V_6 [ V_39 ++ ] ) ;
F_4 ( L_3 , V_37 -> V_46 ) ;
}
F_17 ( & V_40 ) ;
V_15 = F_11 ( V_5 , V_31 , V_47 , V_21 ,
V_22 ) ;
F_22 ( V_21 ) ;
return V_15 ;
}
static T_4 F_23 ( struct V_36 * V_48 )
{
T_4 V_49 = 0 ;
V_49 |= V_50 ;
V_49 |= V_51 ;
V_49 |= V_52 ;
V_49 |= V_53 ;
V_49 |= V_54 ;
if ( V_48 -> V_55 [ 6 ] & V_56 )
V_49 |= V_57 ;
if ( ! ( V_48 -> V_55 [ 4 ] & V_58 ) ) {
V_49 |= V_59 ;
V_49 |= V_60 ;
}
if ( V_48 -> V_55 [ 4 ] & V_61 )
V_49 |= V_62 ;
return V_49 ;
}
static T_4 F_24 ( struct V_36 * V_48 )
{
T_4 V_49 = 0 ;
if ( F_21 ( V_63 , & V_48 -> V_43 ) )
V_49 |= V_50 ;
else
return V_49 ;
if ( F_21 ( V_64 , & V_48 -> V_43 ) )
V_49 |= V_51 ;
if ( F_21 ( V_65 , & V_48 -> V_43 ) )
V_49 |= V_53 ;
if ( F_21 ( V_66 , & V_48 -> V_43 ) )
V_49 |= V_54 ;
if ( ! ( V_48 -> V_55 [ 4 ] & V_58 ) )
V_49 |= V_59 ;
if ( V_48 -> V_67 [ 0 ] & V_68 )
V_49 |= V_62 ;
if ( F_21 ( V_69 , & V_48 -> V_43 ) )
V_49 |= V_60 ;
if ( V_48 -> V_70 > 0 )
V_49 |= V_57 ;
return V_49 ;
}
static T_2 F_25 ( T_1 * V_71 )
{
T_4 V_72 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 12 ; V_39 ++ ) {
if ( V_73 [ V_39 ] != V_71 [ V_39 ] )
return 0 ;
}
memcpy ( & V_72 , & V_71 [ 12 ] , 4 ) ;
V_72 = F_26 ( V_72 ) ;
if ( V_72 > 0xffff )
return 0 ;
return ( T_2 ) V_72 ;
}
static void F_27 ( struct V_36 * V_48 , T_1 * V_25 )
{
T_1 * V_74 = V_25 ;
T_2 V_75 = 0 ;
T_2 V_76 [ V_77 / sizeof( T_2 ) ] ;
int V_39 , V_78 = 0 ;
struct V_79 * V_80 ;
T_3 V_81 ;
V_81 = strlen ( V_48 -> V_82 ) ;
if ( V_81 > 0 ) {
if ( V_81 > 48 ) {
V_81 = 48 ;
V_74 [ 1 ] = V_83 ;
} else
V_74 [ 1 ] = V_84 ;
V_74 [ 0 ] = V_81 + 1 ;
memcpy ( V_74 + 2 , V_48 -> V_82 , V_81 ) ;
V_75 += ( V_81 + 2 ) ;
V_74 += ( V_81 + 2 ) ;
}
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
F_18 (uuid, &hdev->uuids, list) {
T_2 V_85 ;
V_85 = F_25 ( V_80 -> V_80 ) ;
if ( V_85 == 0 )
return;
if ( V_85 < 0x1100 )
continue;
if ( V_85 == V_86 )
continue;
if ( V_75 + 2 + sizeof( T_2 ) > V_77 ) {
V_78 = 1 ;
break;
}
for ( V_39 = 0 ; V_76 [ V_39 ] != 0 ; V_39 ++ )
if ( V_76 [ V_39 ] == V_85 )
break;
if ( V_76 [ V_39 ] == 0 ) {
V_76 [ V_39 ] = V_85 ;
V_75 += sizeof( T_2 ) ;
}
}
if ( V_76 [ 0 ] != 0 ) {
T_1 * V_87 = V_74 ;
V_74 [ 1 ] = V_78 ? V_88 : V_89 ;
V_74 += 2 ;
V_75 += 2 ;
for ( V_39 = 0 ; V_76 [ V_39 ] != 0 ; V_39 ++ ) {
* V_74 ++ = ( V_76 [ V_39 ] & 0x00ff ) ;
* V_74 ++ = ( V_76 [ V_39 ] & 0xff00 ) >> 8 ;
}
* V_87 = ( V_39 * sizeof( T_2 ) ) + 1 ;
}
}
static int F_28 ( struct V_36 * V_48 )
{
struct V_90 V_91 ;
if ( ! ( V_48 -> V_55 [ 6 ] & V_92 ) )
return 0 ;
if ( V_48 -> V_70 == 0 )
return 0 ;
if ( F_21 ( V_93 , & V_48 -> V_43 ) )
return 0 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
F_27 ( V_48 , V_91 . V_25 ) ;
if ( memcmp ( V_91 . V_25 , V_48 -> V_94 , sizeof( V_91 . V_25 ) ) == 0 )
return 0 ;
memcpy ( V_48 -> V_94 , V_91 . V_25 , sizeof( V_91 . V_25 ) ) ;
return F_29 ( V_48 , V_95 , sizeof( V_91 ) , & V_91 ) ;
}
static T_1 F_30 ( struct V_36 * V_48 )
{
struct V_79 * V_80 ;
T_1 V_72 = 0 ;
F_18 (uuid, &hdev->uuids, list)
V_72 |= V_80 -> V_96 ;
return V_72 ;
}
static int F_31 ( struct V_36 * V_48 )
{
T_1 V_97 [ 3 ] ;
F_4 ( L_4 , V_48 -> V_98 ) ;
if ( F_21 ( V_93 , & V_48 -> V_43 ) )
return 0 ;
V_97 [ 0 ] = V_48 -> V_99 ;
V_97 [ 1 ] = V_48 -> V_100 ;
V_97 [ 2 ] = F_30 ( V_48 ) ;
if ( memcmp ( V_97 , V_48 -> V_101 , 3 ) == 0 )
return 0 ;
return F_29 ( V_48 , V_102 , sizeof( V_97 ) , V_97 ) ;
}
static void F_32 ( struct V_103 * V_104 )
{
struct V_36 * V_48 = F_33 ( V_104 , struct V_36 ,
V_105 . V_104 ) ;
if ( ! F_19 ( V_93 , & V_48 -> V_43 ) )
return;
F_34 ( V_48 ) ;
F_28 ( V_48 ) ;
F_31 ( V_48 ) ;
F_35 ( V_48 ) ;
}
static void F_36 ( struct V_36 * V_48 )
{
if ( ! F_37 ( V_106 , & V_48 -> V_43 ) )
F_38 ( & V_48 -> V_105 , F_32 ) ;
if ( ! F_37 ( V_93 , & V_48 -> V_43 ) )
F_39 ( & V_48 -> V_105 ,
F_40 ( V_107 ) ) ;
}
static int F_41 ( struct V_4 * V_5 , T_2 V_6 )
{
struct V_108 V_21 ;
struct V_36 * V_48 ;
F_4 ( L_5 , V_5 , V_6 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_109 ,
V_110 ) ;
if ( F_19 ( V_42 , & V_48 -> V_43 ) )
F_43 ( & V_48 -> V_44 ) ;
F_34 ( V_48 ) ;
if ( F_19 ( V_111 , & F_44 ( V_5 ) -> V_43 ) )
F_36 ( V_48 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_45 ( & V_21 . V_112 , & V_48 -> V_112 ) ;
V_21 . V_27 = V_48 -> V_113 ;
F_8 ( V_48 -> V_114 , & V_21 . V_114 ) ;
V_21 . V_115 = F_46 ( F_23 ( V_48 ) ) ;
V_21 . V_116 = F_46 ( F_24 ( V_48 ) ) ;
memcpy ( V_21 . V_101 , V_48 -> V_101 , 3 ) ;
memcpy ( V_21 . V_98 , V_48 -> V_82 , sizeof( V_48 -> V_82 ) ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return F_11 ( V_5 , V_6 , V_109 , & V_21 , sizeof( V_21 ) ) ;
}
static void F_48 ( struct V_117 * V_7 )
{
F_49 ( V_7 -> V_5 ) ;
F_22 ( V_7 -> V_118 ) ;
F_22 ( V_7 ) ;
}
static struct V_117 * F_50 ( struct V_4 * V_5 , T_2 V_18 ,
struct V_36 * V_48 ,
void * V_25 , T_2 V_20 )
{
struct V_117 * V_7 ;
V_7 = F_16 ( sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 = V_18 ;
V_7 -> V_6 = V_48 -> V_46 ;
V_7 -> V_118 = F_16 ( V_20 , V_16 ) ;
if ( ! V_7 -> V_118 ) {
F_22 ( V_7 ) ;
return NULL ;
}
if ( V_25 )
memcpy ( V_7 -> V_118 , V_25 , V_20 ) ;
V_7 -> V_5 = V_5 ;
F_51 ( V_5 ) ;
F_52 ( & V_7 -> V_119 , & V_48 -> V_120 ) ;
return V_7 ;
}
static void F_53 ( T_2 V_18 , struct V_36 * V_48 ,
void (* F_54)( struct V_117 * V_7 , void * V_25 ) ,
void * V_25 )
{
struct V_34 * V_35 , * V_121 ;
F_55 (p, n, &hdev->mgmt_pending) {
struct V_117 * V_7 ;
V_7 = F_56 ( V_35 , struct V_117 , V_119 ) ;
if ( V_18 > 0 && V_7 -> V_18 != V_18 )
continue;
F_54 ( V_7 , V_25 ) ;
}
}
static struct V_117 * F_57 ( T_2 V_18 , struct V_36 * V_48 )
{
struct V_117 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 == V_18 )
return V_7 ;
}
return NULL ;
}
static void F_58 ( struct V_117 * V_7 )
{
F_59 ( & V_7 -> V_119 ) ;
F_48 ( V_7 ) ;
}
static int F_60 ( struct V_4 * V_5 , T_2 V_18 , struct V_36 * V_48 )
{
T_5 V_49 = F_46 ( F_24 ( V_48 ) ) ;
return F_11 ( V_5 , V_48 -> V_46 , V_18 , & V_49 , sizeof( V_49 ) ) ;
}
static int F_61 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 , T_2 V_20 )
{
struct V_122 * V_91 ;
struct V_36 * V_48 ;
struct V_117 * V_7 ;
int V_15 , V_123 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_124 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_124 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_123 = F_21 ( V_63 , & V_48 -> V_43 ) ;
if ( ( V_91 -> V_72 && V_123 ) || ( ! V_91 -> V_72 && ! V_123 ) ) {
V_15 = F_60 ( V_5 , V_124 , V_48 ) ;
goto V_125;
}
if ( F_57 ( V_124 , V_48 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_124 ,
V_126 ) ;
goto V_125;
}
V_7 = F_50 ( V_5 , V_124 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
if ( V_91 -> V_72 )
F_62 ( & V_48 -> V_127 ) ;
else
F_62 ( & V_48 -> V_44 . V_104 ) ;
V_15 = 0 ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_63 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_128 * V_91 ;
struct V_36 * V_48 ;
struct V_117 * V_7 ;
T_1 V_129 ;
int V_15 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_130 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_130 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_130 ,
V_131 ) ;
goto V_125;
}
if ( F_57 ( V_130 , V_48 ) ||
F_57 ( V_132 , V_48 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_130 ,
V_126 ) ;
goto V_125;
}
if ( V_91 -> V_72 == F_21 ( V_65 , & V_48 -> V_43 ) &&
F_21 ( V_64 , & V_48 -> V_43 ) ) {
V_15 = F_60 ( V_5 , V_130 , V_48 ) ;
goto V_125;
}
V_7 = F_50 ( V_5 , V_130 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
V_129 = V_133 ;
if ( V_91 -> V_72 )
V_129 |= V_134 ;
else
F_20 ( & V_48 -> V_135 ) ;
V_15 = F_29 ( V_48 , V_136 , 1 , & V_129 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
if ( V_91 -> V_72 )
V_48 -> V_137 = F_64 ( & V_91 -> V_138 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_65 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_122 * V_91 ;
struct V_36 * V_48 ;
struct V_117 * V_7 ;
T_1 V_129 ;
int V_15 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_132 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_132 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_132 ,
V_131 ) ;
goto V_125;
}
if ( F_57 ( V_130 , V_48 ) ||
F_57 ( V_132 , V_48 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_132 ,
V_126 ) ;
goto V_125;
}
if ( V_91 -> V_72 == F_21 ( V_64 , & V_48 -> V_43 ) ) {
V_15 = F_60 ( V_5 , V_132 , V_48 ) ;
goto V_125;
}
V_7 = F_50 ( V_5 , V_132 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
if ( V_91 -> V_72 )
V_129 = V_133 ;
else
V_129 = 0 ;
V_15 = F_29 ( V_48 , V_136 , 1 , & V_129 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_66 ( T_2 V_139 , struct V_36 * V_48 , void * V_25 ,
T_2 V_140 , struct V_4 * V_141 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_5 ( sizeof( * V_12 ) + V_140 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
F_67 ( V_10 ) -> V_142 = V_143 ;
V_12 = ( void * ) F_6 ( V_10 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = F_7 ( V_139 ) ;
if ( V_48 )
V_12 -> V_6 = F_7 ( V_48 -> V_46 ) ;
else
V_12 -> V_6 = F_7 ( V_31 ) ;
V_12 -> V_20 = F_7 ( V_140 ) ;
if ( V_25 )
memcpy ( F_6 ( V_10 , V_140 ) , V_25 , V_140 ) ;
F_68 ( NULL , V_10 , V_141 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_122 * V_91 ;
struct V_36 * V_48 ;
T_5 V_14 ;
int V_15 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_144 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_144 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( V_91 -> V_72 )
F_70 ( V_66 , & V_48 -> V_43 ) ;
else
F_71 ( V_66 , & V_48 -> V_43 ) ;
V_15 = F_60 ( V_5 , V_144 , V_48 ) ;
if ( V_15 < 0 )
goto V_125;
V_14 = F_46 ( F_24 ( V_48 ) ) ;
V_15 = F_66 ( V_145 , V_48 , & V_14 , sizeof( V_14 ) , V_5 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_72 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 , T_2 V_20 )
{
struct V_146 * V_91 ;
struct V_36 * V_48 ;
struct V_79 * V_80 ;
int V_15 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_147 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_147 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_80 = F_16 ( sizeof( * V_80 ) , V_16 ) ;
if ( ! V_80 ) {
V_15 = - V_17 ;
goto V_125;
}
memcpy ( V_80 -> V_80 , V_91 -> V_80 , 16 ) ;
V_80 -> V_96 = V_91 -> V_96 ;
F_52 ( & V_80 -> V_119 , & V_48 -> V_148 ) ;
V_15 = F_31 ( V_48 ) ;
if ( V_15 < 0 )
goto V_125;
V_15 = F_28 ( V_48 ) ;
if ( V_15 < 0 )
goto V_125;
V_15 = F_11 ( V_5 , V_6 , V_147 , NULL , 0 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_73 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 , T_2 V_20 )
{
struct V_34 * V_35 , * V_121 ;
struct V_149 * V_91 ;
struct V_36 * V_48 ;
T_1 V_150 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_15 , V_151 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_152 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_152 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( memcmp ( V_91 -> V_80 , V_150 , 16 ) == 0 ) {
V_15 = F_74 ( V_48 ) ;
goto V_153;
}
V_151 = 0 ;
F_55 (p, n, &hdev->uuids) {
struct V_79 * V_154 = F_56 ( V_35 , struct V_79 , V_119 ) ;
if ( memcmp ( V_154 -> V_80 , V_91 -> V_80 , 16 ) != 0 )
continue;
F_59 ( & V_154 -> V_119 ) ;
V_151 ++ ;
}
if ( V_151 == 0 ) {
V_15 = F_3 ( V_5 , V_6 , V_152 ,
V_110 ) ;
goto V_153;
}
V_15 = F_31 ( V_48 ) ;
if ( V_15 < 0 )
goto V_153;
V_15 = F_28 ( V_48 ) ;
if ( V_15 < 0 )
goto V_153;
V_15 = F_11 ( V_5 , V_6 , V_152 , NULL , 0 ) ;
V_153:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_75 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_155 * V_91 ;
int V_15 ;
V_91 = ( void * ) V_25 ;
F_4 ( L_6 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_156 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_156 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_48 -> V_100 = V_91 -> V_157 ;
V_48 -> V_99 = V_91 -> V_158 ;
if ( F_19 ( V_93 , & V_48 -> V_43 ) ) {
F_35 ( V_48 ) ;
F_43 ( & V_48 -> V_105 ) ;
F_34 ( V_48 ) ;
F_28 ( V_48 ) ;
}
V_15 = F_31 ( V_48 ) ;
if ( V_15 == 0 )
V_15 = F_11 ( V_5 , V_6 , V_156 , NULL , 0 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_76 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_159 * V_91 ;
T_2 V_160 , V_161 ;
int V_39 ;
V_91 = ( void * ) V_25 ;
if ( V_20 < sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_162 ,
V_110 ) ;
V_160 = F_64 ( & V_91 -> V_160 ) ;
V_161 = sizeof( * V_91 ) + V_160 *
sizeof( struct V_163 ) ;
if ( V_161 != V_20 ) {
F_77 ( L_7 ,
V_20 , V_161 ) ;
return F_3 ( V_5 , V_6 , V_162 ,
V_110 ) ;
}
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_162 ,
V_110 ) ;
F_4 ( L_8 , V_6 , V_91 -> V_164 ,
V_160 ) ;
F_34 ( V_48 ) ;
F_78 ( V_48 ) ;
F_70 ( V_165 , & V_48 -> V_43 ) ;
if ( V_91 -> V_164 )
F_70 ( V_166 , & V_48 -> V_43 ) ;
else
F_71 ( V_166 , & V_48 -> V_43 ) ;
for ( V_39 = 0 ; V_39 < V_160 ; V_39 ++ ) {
struct V_163 * V_167 = & V_91 -> V_168 [ V_39 ] ;
F_79 ( V_48 , NULL , 0 , & V_167 -> V_112 , V_167 -> V_72 , V_167 -> type ,
V_167 -> V_169 ) ;
}
F_11 ( V_5 , V_6 , V_162 , NULL , 0 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_170 * V_91 ;
struct V_171 V_21 ;
struct V_172 V_173 ;
struct V_117 * V_7 ;
struct V_174 * V_175 ;
int V_15 ;
V_91 = ( void * ) V_25 ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_176 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_176 ,
V_110 ) ;
F_34 ( V_48 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_45 ( & V_21 . V_112 , & V_91 -> V_112 ) ;
V_21 . V_8 = V_3 ;
V_15 = F_81 ( V_48 , & V_91 -> V_112 ) ;
if ( V_15 < 0 ) {
V_21 . V_8 = V_177 ;
goto V_153;
}
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) || ! V_91 -> V_178 ) {
V_15 = F_11 ( V_5 , V_6 , V_176 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_153;
}
V_175 = F_82 ( V_48 , V_179 , & V_91 -> V_112 ) ;
if ( ! V_175 ) {
V_15 = F_11 ( V_5 , V_6 , V_176 , & V_21 ,
sizeof( V_21 ) ) ;
goto V_153;
}
V_7 = F_50 ( V_5 , V_176 , V_48 , V_91 , sizeof( * V_91 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_153;
}
F_8 ( V_175 -> V_180 , & V_173 . V_180 ) ;
V_173 . V_181 = 0x13 ;
V_15 = F_29 ( V_48 , V_182 , sizeof( V_173 ) , & V_173 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_153:
if ( V_15 < 0 )
V_15 = F_11 ( V_5 , V_6 , V_176 , & V_21 ,
sizeof( V_21 ) ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int V_178 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 , T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_183 * V_91 ;
struct V_172 V_173 ;
struct V_117 * V_7 ;
struct V_174 * V_175 ;
int V_15 ;
F_4 ( L_9 ) ;
V_91 = ( void * ) V_25 ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_184 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_184 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_184 ,
V_131 ) ;
goto V_125;
}
if ( F_57 ( V_184 , V_48 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_184 ,
V_126 ) ;
goto V_125;
}
V_175 = F_82 ( V_48 , V_179 , & V_91 -> V_112 ) ;
if ( ! V_175 )
V_175 = F_82 ( V_48 , V_185 , & V_91 -> V_112 ) ;
if ( ! V_175 ) {
V_15 = F_3 ( V_5 , V_6 , V_184 ,
V_186 ) ;
goto V_125;
}
V_7 = F_50 ( V_5 , V_184 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
F_8 ( V_175 -> V_180 , & V_173 . V_180 ) ;
V_173 . V_181 = 0x13 ;
V_15 = F_29 ( V_48 , V_182 , sizeof( V_173 ) , & V_173 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static T_1 F_83 ( T_1 V_187 , T_1 V_188 )
{
switch ( V_187 ) {
case V_185 :
switch ( V_188 ) {
case V_189 :
return V_190 ;
case V_191 :
return V_192 ;
default:
return V_193 ;
}
case V_179 :
return V_194 ;
default:
return V_193 ;
}
}
static int F_84 ( struct V_4 * V_5 , T_2 V_6 )
{
struct V_195 * V_21 ;
struct V_36 * V_48 ;
struct V_174 * V_196 ;
struct V_34 * V_35 ;
T_3 V_22 ;
T_2 V_38 ;
int V_39 , V_15 ;
F_4 ( L_9 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_197 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_38 = 0 ;
F_15 (p, &hdev->conn_hash.list) {
V_38 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_38 * sizeof( struct V_198 ) ) ;
V_21 = F_16 ( V_22 , V_16 ) ;
if ( ! V_21 ) {
V_15 = - V_17 ;
goto V_153;
}
F_8 ( V_38 , & V_21 -> V_199 ) ;
V_39 = 0 ;
F_18 (c, &hdev->conn_hash.list, list) {
F_45 ( & V_21 -> V_200 [ V_39 ] . V_112 , & V_196 -> V_201 ) ;
V_21 -> V_200 [ V_39 ] . type = F_83 ( V_196 -> type , V_196 -> V_202 ) ;
if ( V_21 -> V_200 [ V_39 ] . type == V_193 )
continue;
V_39 ++ ;
}
V_22 = sizeof( * V_21 ) + ( V_39 * sizeof( struct V_198 ) ) ;
V_15 = F_11 ( V_5 , V_6 , V_197 , V_21 , V_22 ) ;
V_153:
F_22 ( V_21 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_85 ( struct V_4 * V_5 , T_2 V_6 ,
struct V_36 * V_48 , struct V_203 * V_91 )
{
struct V_117 * V_7 ;
int V_15 ;
V_7 = F_50 ( V_5 , V_204 , V_48 , V_91 ,
sizeof( * V_91 ) ) ;
if ( ! V_7 )
return - V_17 ;
V_15 = F_29 ( V_48 , V_205 , sizeof( V_91 -> V_112 ) ,
& V_91 -> V_112 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
return V_15 ;
}
static int F_86 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_174 * V_175 ;
struct V_206 * V_91 ;
struct V_203 V_207 ;
struct V_208 V_209 ;
struct V_117 * V_7 ;
int V_15 ;
F_4 ( L_9 ) ;
V_91 = ( void * ) V_25 ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_210 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_210 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_210 ,
V_131 ) ;
goto V_125;
}
V_175 = F_82 ( V_48 , V_179 , & V_91 -> V_112 ) ;
if ( ! V_175 ) {
V_15 = F_3 ( V_5 , V_6 , V_210 ,
V_186 ) ;
goto V_125;
}
if ( V_175 -> V_211 == V_212 && V_91 -> V_169 != 16 ) {
F_45 ( & V_207 . V_112 , & V_91 -> V_112 ) ;
F_77 ( L_10 ) ;
V_15 = F_85 ( V_5 , V_6 , V_48 , & V_207 ) ;
if ( V_15 >= 0 )
V_15 = F_3 ( V_5 , V_6 , V_210 ,
V_110 ) ;
goto V_125;
}
V_7 = F_50 ( V_5 , V_210 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
F_45 ( & V_209 . V_112 , & V_91 -> V_112 ) ;
V_209 . V_169 = V_91 -> V_169 ;
memcpy ( V_209 . V_213 , V_91 -> V_213 , sizeof( V_209 . V_213 ) ) ;
V_15 = F_29 ( V_48 , V_214 , sizeof( V_209 ) , & V_209 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_87 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_203 * V_91 ;
int V_15 ;
F_4 ( L_9 ) ;
V_91 = ( void * ) V_25 ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_204 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_204 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_204 ,
V_131 ) ;
goto V_125;
}
V_15 = F_85 ( V_5 , V_6 , V_48 , V_91 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_88 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_215 * V_91 ;
F_4 ( L_9 ) ;
V_91 = ( void * ) V_25 ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_216 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_216 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_48 -> V_217 = V_91 -> V_217 ;
F_4 ( L_11 , V_48 -> V_98 ,
V_48 -> V_217 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return F_11 ( V_5 , V_6 , V_216 , NULL , 0 ) ;
}
static inline struct V_117 * F_89 ( struct V_174 * V_175 )
{
struct V_36 * V_48 = V_175 -> V_48 ;
struct V_117 * V_7 ;
F_18 (cmd, &hdev->mgmt_pending, list) {
if ( V_7 -> V_18 != V_218 )
continue;
if ( V_7 -> V_219 != V_175 )
continue;
return V_7 ;
}
return NULL ;
}
static void F_90 ( struct V_117 * V_7 , T_1 V_8 )
{
struct V_220 V_21 ;
struct V_174 * V_175 = V_7 -> V_219 ;
F_45 ( & V_21 . V_200 . V_112 , & V_175 -> V_201 ) ;
V_21 . V_200 . type = F_83 ( V_175 -> type , V_175 -> V_202 ) ;
V_21 . V_8 = V_8 ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_218 , & V_21 , sizeof( V_21 ) ) ;
V_175 -> V_221 = NULL ;
V_175 -> V_222 = NULL ;
V_175 -> V_223 = NULL ;
F_91 ( V_175 ) ;
F_58 ( V_7 ) ;
}
static void F_92 ( struct V_174 * V_175 , T_1 V_8 )
{
struct V_117 * V_7 ;
F_4 ( L_12 , V_8 ) ;
V_7 = F_89 ( V_175 ) ;
if ( ! V_7 )
F_4 ( L_13 ) ;
else
F_90 ( V_7 , V_8 ) ;
}
static int F_93 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 , T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_224 * V_91 ;
struct V_220 V_21 ;
struct V_117 * V_7 ;
T_1 V_225 , V_226 ;
struct V_174 * V_175 ;
int V_15 ;
F_4 ( L_9 ) ;
V_91 = ( void * ) V_25 ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_218 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_218 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_225 = V_227 ;
if ( V_91 -> V_228 == 0x03 )
V_226 = V_229 ;
else
V_226 = V_230 ;
if ( V_91 -> V_200 . type == V_194 )
V_175 = F_94 ( V_48 , V_179 , & V_91 -> V_200 . V_112 , V_225 ,
V_226 ) ;
else
V_175 = F_94 ( V_48 , V_185 , & V_91 -> V_200 . V_112 , V_225 ,
V_226 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_45 ( & V_21 . V_200 . V_112 , & V_91 -> V_200 . V_112 ) ;
V_21 . V_200 . type = V_91 -> V_200 . type ;
if ( F_95 ( V_175 ) ) {
V_21 . V_8 = - F_96 ( V_175 ) ;
V_15 = F_11 ( V_5 , V_6 , V_218 ,
& V_21 , sizeof( V_21 ) ) ;
goto V_153;
}
if ( V_175 -> V_221 ) {
F_91 ( V_175 ) ;
V_21 . V_8 = V_231 ;
V_15 = F_11 ( V_5 , V_6 , V_218 ,
& V_21 , sizeof( V_21 ) ) ;
goto V_153;
}
V_7 = F_50 ( V_5 , V_218 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
F_91 ( V_175 ) ;
goto V_153;
}
if ( V_91 -> V_200 . type == V_194 )
V_175 -> V_221 = F_92 ;
V_175 -> V_222 = F_92 ;
V_175 -> V_223 = F_92 ;
V_175 -> V_217 = V_91 -> V_228 ;
V_7 -> V_219 = V_175 ;
if ( V_175 -> V_232 == V_233 &&
F_97 ( V_175 , V_225 , V_226 ) )
F_90 ( V_7 , 0 ) ;
V_15 = 0 ;
V_153:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_98 ( struct V_4 * V_5 , T_2 V_6 , T_6 * V_112 ,
T_2 V_234 , T_2 V_235 , T_5 V_236 )
{
struct V_117 * V_7 ;
struct V_36 * V_48 ;
struct V_174 * V_175 ;
int V_15 ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_234 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_234 , V_131 ) ;
goto V_237;
}
V_175 = F_82 ( V_48 , V_179 , V_112 ) ;
if ( ! V_175 ) {
V_175 = F_82 ( V_48 , V_185 , V_112 ) ;
if ( ! V_175 ) {
V_15 = F_3 ( V_5 , V_6 , V_234 ,
V_186 ) ;
goto V_237;
}
V_15 = F_99 ( V_175 , V_234 , V_236 ) ;
if ( ! V_15 )
V_15 = F_3 ( V_5 , V_6 , V_234 ,
V_238 ) ;
else
V_15 = F_3 ( V_5 , V_6 , V_234 ,
V_3 ) ;
goto V_237;
}
V_7 = F_50 ( V_5 , V_234 , V_48 , V_112 , sizeof( * V_112 ) ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_237;
}
if ( V_235 == V_239 ) {
struct V_240 V_91 ;
F_45 ( & V_91 . V_112 , V_112 ) ;
V_91 . V_236 = V_236 ;
V_15 = F_29 ( V_48 , V_235 , sizeof( V_91 ) , & V_91 ) ;
} else
V_15 = F_29 ( V_48 , V_235 , sizeof( * V_112 ) , V_112 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_237:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_100 ( struct V_4 * V_5 , T_2 V_6 , void * V_25 , T_2 V_20 )
{
struct V_241 * V_91 = ( void * ) V_25 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_242 ,
V_110 ) ;
return F_98 ( V_5 , V_6 , & V_91 -> V_112 ,
V_242 ,
V_243 , 0 ) ;
}
static int F_101 ( struct V_4 * V_5 , T_2 V_6 , void * V_25 ,
T_2 V_20 )
{
struct V_244 * V_91 = V_25 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_245 ,
V_110 ) ;
return F_98 ( V_5 , V_6 , & V_91 -> V_112 ,
V_245 ,
V_246 , 0 ) ;
}
static int F_102 ( struct V_4 * V_5 , T_2 V_6 , void * V_25 , T_2 V_20 )
{
struct V_247 * V_91 = ( void * ) V_25 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_248 ,
V_249 ) ;
return F_98 ( V_5 , V_6 , & V_91 -> V_112 ,
V_248 ,
V_239 , V_91 -> V_236 ) ;
}
static int F_103 ( struct V_4 * V_5 , T_2 V_6 , void * V_25 ,
T_2 V_20 )
{
struct V_250 * V_91 = ( void * ) V_25 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_251 ,
V_249 ) ;
return F_98 ( V_5 , V_6 , & V_91 -> V_112 ,
V_251 ,
V_252 , 0 ) ;
}
static int F_104 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_253 * V_254 = ( void * ) V_25 ;
struct V_255 V_256 ;
struct V_36 * V_48 ;
struct V_117 * V_7 ;
int V_15 ;
F_4 ( L_9 ) ;
if ( V_20 != sizeof( * V_254 ) )
return F_3 ( V_5 , V_6 , V_257 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_257 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_7 = F_50 ( V_5 , V_257 , V_48 , V_25 , V_20 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
memcpy ( V_256 . V_98 , V_254 -> V_98 , sizeof( V_256 . V_98 ) ) ;
V_15 = F_29 ( V_48 , V_258 , sizeof( V_256 ) ,
& V_256 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_105 ( struct V_4 * V_5 , T_2 V_6 )
{
struct V_36 * V_48 ;
struct V_117 * V_7 ;
int V_15 ;
F_4 ( L_14 , V_6 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_259 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_259 ,
V_131 ) ;
goto V_153;
}
if ( ! ( V_48 -> V_55 [ 6 ] & V_56 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_259 ,
V_260 ) ;
goto V_153;
}
if ( F_57 ( V_259 , V_48 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_259 ,
V_126 ) ;
goto V_153;
}
V_7 = F_50 ( V_5 , V_259 , V_48 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_153;
}
V_15 = F_29 ( V_48 , V_261 , 0 , NULL ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_153:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_106 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_262 * V_91 = ( void * ) V_25 ;
int V_15 ;
F_4 ( L_15 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_263 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_263 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_15 = F_107 ( V_48 , & V_91 -> V_112 , V_91 -> V_264 ,
V_91 -> V_265 ) ;
if ( V_15 < 0 )
V_15 = F_3 ( V_5 , V_6 , V_263 ,
V_3 ) ;
else
V_15 = F_11 ( V_5 , V_6 , V_263 , NULL ,
0 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_108 ( struct V_4 * V_5 , T_2 V_6 ,
unsigned char * V_25 , T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_266 * V_91 = ( void * ) V_25 ;
int V_15 ;
F_4 ( L_15 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_267 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_267 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_15 = F_109 ( V_48 , & V_91 -> V_112 ) ;
if ( V_15 < 0 )
V_15 = F_3 ( V_5 , V_6 , V_267 ,
V_110 ) ;
else
V_15 = F_11 ( V_5 , V_6 , V_267 ,
NULL , 0 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_110 ( struct V_4 * V_5 , T_2 V_6 ,
unsigned char * V_25 , T_2 V_20 )
{
struct V_268 * V_91 = ( void * ) V_25 ;
struct V_117 * V_7 ;
struct V_36 * V_48 ;
int V_15 ;
F_4 ( L_14 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_269 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_269 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( ! F_21 ( V_63 , & V_48 -> V_43 ) ) {
V_15 = F_3 ( V_5 , V_6 , V_269 ,
V_131 ) ;
goto V_125;
}
V_7 = F_50 ( V_5 , V_269 , V_48 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
V_15 = F_111 ( V_48 , V_270 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_112 ( struct V_4 * V_5 , T_2 V_6 )
{
struct V_36 * V_48 ;
struct V_117 * V_7 ;
int V_15 ;
F_4 ( L_14 , V_6 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_271 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_7 = F_50 ( V_5 , V_271 , V_48 , NULL , 0 ) ;
if ( ! V_7 ) {
V_15 = - V_17 ;
goto V_125;
}
V_15 = F_113 ( V_48 ) ;
if ( V_15 < 0 )
F_58 ( V_7 ) ;
V_125:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_114 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_272 * V_91 = ( void * ) V_25 ;
int V_15 ;
F_4 ( L_14 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_273 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_273 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_15 = F_115 ( V_48 , & V_91 -> V_112 ) ;
if ( V_15 < 0 )
V_15 = F_3 ( V_5 , V_6 , V_273 ,
V_3 ) ;
else
V_15 = F_11 ( V_5 , V_6 , V_273 ,
NULL , 0 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_116 ( struct V_4 * V_5 , T_2 V_6 , unsigned char * V_25 ,
T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_274 * V_91 = ( void * ) V_25 ;
int V_15 ;
F_4 ( L_14 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_275 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_275 ,
V_110 ) ;
F_34 ( V_48 ) ;
V_15 = F_117 ( V_48 , & V_91 -> V_112 ) ;
if ( V_15 < 0 )
V_15 = F_3 ( V_5 , V_6 , V_275 ,
V_110 ) ;
else
V_15 = F_11 ( V_5 , V_6 , V_275 ,
NULL , 0 ) ;
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
static int F_118 ( struct V_4 * V_5 , T_2 V_6 ,
unsigned char * V_25 , T_2 V_20 )
{
struct V_36 * V_48 ;
struct V_122 * V_91 = ( void * ) V_25 ;
struct V_276 V_277 ;
T_1 type ;
int V_15 ;
F_4 ( L_14 , V_6 ) ;
if ( V_20 != sizeof( * V_91 ) )
return F_3 ( V_5 , V_6 , V_278 ,
V_110 ) ;
V_48 = F_42 ( V_6 ) ;
if ( ! V_48 )
return F_3 ( V_5 , V_6 , V_278 ,
V_110 ) ;
F_34 ( V_48 ) ;
if ( V_91 -> V_72 ) {
type = V_279 ;
V_277 . V_280 = 0x0024 ;
} else {
type = V_281 ;
V_277 . V_280 = 0x0800 ;
}
V_277 . V_282 = 0x0012 ;
V_15 = F_29 ( V_48 , V_283 ,
sizeof( V_277 ) , & V_277 ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_6 , V_278 ,
V_3 ) ;
goto V_237;
}
V_15 = F_29 ( V_48 , V_284 , 1 , & type ) ;
if ( V_15 < 0 ) {
V_15 = F_3 ( V_5 , V_6 , V_278 ,
V_3 ) ;
goto V_237;
}
V_15 = F_11 ( V_5 , V_6 , V_278 ,
NULL , 0 ) ;
V_237:
F_35 ( V_48 ) ;
F_47 ( V_48 ) ;
return V_15 ;
}
int F_119 ( struct V_4 * V_5 , struct V_285 * V_286 , T_3 V_287 )
{
unsigned char * V_288 ;
struct V_11 * V_12 ;
T_2 V_18 , V_6 , V_20 ;
int V_15 ;
F_4 ( L_16 , V_287 ) ;
if ( V_287 < sizeof( * V_12 ) )
return - V_249 ;
V_288 = F_16 ( V_287 , V_289 ) ;
if ( ! V_288 )
return - V_17 ;
if ( F_120 ( V_288 , V_286 -> V_290 , V_287 ) ) {
V_15 = - V_291 ;
goto V_237;
}
V_12 = (struct V_11 * ) V_288 ;
V_18 = F_64 ( & V_12 -> V_18 ) ;
V_6 = F_64 ( & V_12 -> V_6 ) ;
V_20 = F_64 ( & V_12 -> V_20 ) ;
if ( V_20 != V_287 - sizeof( * V_12 ) ) {
V_15 = - V_249 ;
goto V_237;
}
switch ( V_18 ) {
case V_32 :
V_15 = F_12 ( V_5 ) ;
break;
case V_47 :
V_15 = F_13 ( V_5 ) ;
break;
case V_109 :
V_15 = F_41 ( V_5 , V_6 ) ;
break;
case V_124 :
V_15 = F_61 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_130 :
V_15 = F_63 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_132 :
V_15 = F_65 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_278 :
V_15 = F_118 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) ,
V_20 ) ;
break;
case V_144 :
V_15 = F_69 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_147 :
V_15 = F_72 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_152 :
V_15 = F_73 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_156 :
V_15 = F_75 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_162 :
V_15 = F_76 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_176 :
V_15 = F_80 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_184 :
V_15 = V_178 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_197 :
V_15 = F_84 ( V_5 , V_6 ) ;
break;
case V_210 :
V_15 = F_86 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_204 :
V_15 = F_87 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_216 :
V_15 = F_88 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_218 :
V_15 = F_93 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_242 :
V_15 = F_100 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_245 :
V_15 = F_101 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) ,
V_20 ) ;
break;
case V_248 :
V_15 = F_102 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_251 :
V_15 = F_103 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) ,
V_20 ) ;
break;
case V_257 :
V_15 = F_104 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_259 :
V_15 = F_105 ( V_5 , V_6 ) ;
break;
case V_263 :
V_15 = F_106 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_267 :
V_15 = F_108 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) ,
V_20 ) ;
break;
case V_269 :
V_15 = F_110 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_271 :
V_15 = F_112 ( V_5 , V_6 ) ;
break;
case V_273 :
V_15 = F_114 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
case V_275 :
V_15 = F_116 ( V_5 , V_6 , V_288 + sizeof( * V_12 ) , V_20 ) ;
break;
default:
F_4 ( L_17 , V_18 ) ;
V_15 = F_3 ( V_5 , V_6 , V_18 ,
V_292 ) ;
break;
}
if ( V_15 < 0 )
goto V_237;
V_15 = V_287 ;
V_237:
F_22 ( V_288 ) ;
return V_15 ;
}
static void F_121 ( struct V_117 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
F_3 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_18 , * V_8 ) ;
F_58 ( V_7 ) ;
}
int F_122 ( struct V_36 * V_48 )
{
return F_66 ( V_293 , V_48 , NULL , 0 , NULL ) ;
}
int F_123 ( struct V_36 * V_48 )
{
T_1 V_8 = V_294 ;
F_53 ( 0 , V_48 , F_121 , & V_8 ) ;
return F_66 ( V_295 , V_48 , NULL , 0 , NULL ) ;
}
static void F_124 ( struct V_117 * V_7 , void * V_25 )
{
struct V_296 * V_154 = V_25 ;
F_60 ( V_7 -> V_5 , V_7 -> V_18 , V_154 -> V_48 ) ;
F_59 ( & V_7 -> V_119 ) ;
if ( V_154 -> V_5 == NULL ) {
V_154 -> V_5 = V_7 -> V_5 ;
F_51 ( V_154 -> V_5 ) ;
}
F_48 ( V_7 ) ;
}
int F_125 ( struct V_36 * V_48 , T_1 V_297 )
{
struct V_296 V_154 = { V_297 , NULL , V_48 } ;
T_5 V_14 ;
int V_298 ;
F_53 ( V_124 , V_48 , F_124 , & V_154 ) ;
if ( ! V_297 ) {
T_1 V_8 = V_299 ;
F_53 ( 0 , V_48 , F_121 , & V_8 ) ;
}
V_14 = F_46 ( F_24 ( V_48 ) ) ;
V_298 = F_66 ( V_145 , V_48 , & V_14 , sizeof( V_14 ) ,
V_154 . V_5 ) ;
if ( V_154 . V_5 )
F_49 ( V_154 . V_5 ) ;
return V_298 ;
}
int F_126 ( struct V_36 * V_48 , T_1 V_300 )
{
struct V_296 V_154 = { V_300 , NULL , V_48 } ;
T_5 V_14 ;
int V_298 ;
F_53 ( V_130 , V_48 , F_124 , & V_154 ) ;
V_14 = F_46 ( F_24 ( V_48 ) ) ;
V_298 = F_66 ( V_145 , V_48 , & V_14 , sizeof( V_14 ) ,
V_154 . V_5 ) ;
if ( V_154 . V_5 )
F_49 ( V_154 . V_5 ) ;
return V_298 ;
}
int F_127 ( struct V_36 * V_48 , T_1 V_301 )
{
T_5 V_14 ;
struct V_296 V_154 = { V_301 , NULL , V_48 } ;
int V_298 ;
F_53 ( V_132 , V_48 , F_124 ,
& V_154 ) ;
V_14 = F_46 ( F_24 ( V_48 ) ) ;
V_298 = F_66 ( V_145 , V_48 , & V_14 , sizeof( V_14 ) , V_154 . V_5 ) ;
if ( V_154 . V_5 )
F_49 ( V_154 . V_5 ) ;
return V_298 ;
}
int F_128 ( struct V_36 * V_48 , T_1 V_129 , T_1 V_8 )
{
T_1 V_302 = F_1 ( V_8 ) ;
if ( V_129 & V_133 )
F_53 ( V_132 , V_48 ,
F_121 , & V_302 ) ;
if ( V_129 & V_134 )
F_53 ( V_130 , V_48 ,
F_121 , & V_302 ) ;
return 0 ;
}
int F_129 ( struct V_36 * V_48 , struct V_303 * V_167 ,
T_1 V_304 )
{
struct V_305 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_306 = V_304 ;
F_45 ( & V_14 . V_167 . V_112 , & V_167 -> V_112 ) ;
V_14 . V_167 . type = V_167 -> type ;
memcpy ( V_14 . V_167 . V_72 , V_167 -> V_72 , 16 ) ;
V_14 . V_167 . V_169 = V_167 -> V_169 ;
return F_66 ( V_307 , V_48 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_130 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_187 ,
T_1 V_188 )
{
struct V_198 V_14 ;
F_45 ( & V_14 . V_112 , V_112 ) ;
V_14 . type = F_83 ( V_187 , V_188 ) ;
return F_66 ( V_308 , V_48 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static void F_131 ( struct V_117 * V_7 , void * V_25 )
{
struct V_183 * V_91 = V_7 -> V_118 ;
struct V_4 * * V_5 = V_25 ;
struct V_309 V_21 ;
F_45 ( & V_21 . V_112 , & V_91 -> V_112 ) ;
V_21 . V_8 = 0 ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_184 , & V_21 , sizeof( V_21 ) ) ;
* V_5 = V_7 -> V_5 ;
F_51 ( * V_5 ) ;
F_58 ( V_7 ) ;
}
static void F_132 ( struct V_117 * V_7 , void * V_25 )
{
T_1 * V_8 = V_25 ;
struct V_170 * V_91 = V_7 -> V_118 ;
struct V_171 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_45 ( & V_21 . V_112 , & V_91 -> V_112 ) ;
if ( V_8 != NULL )
V_21 . V_8 = * V_8 ;
F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_176 , & V_21 ,
sizeof( V_21 ) ) ;
F_58 ( V_7 ) ;
}
int F_133 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_187 ,
T_1 V_188 )
{
struct V_198 V_14 ;
struct V_4 * V_5 = NULL ;
int V_15 ;
F_53 ( V_184 , V_48 , F_131 , & V_5 ) ;
F_45 ( & V_14 . V_112 , V_112 ) ;
V_14 . type = F_83 ( V_187 , V_188 ) ;
V_15 = F_66 ( V_310 , V_48 , & V_14 , sizeof( V_14 ) , V_5 ) ;
if ( V_5 )
F_49 ( V_5 ) ;
F_53 ( V_176 , V_48 , F_132 , NULL ) ;
return V_15 ;
}
int F_134 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_8 )
{
struct V_117 * V_7 ;
T_1 V_302 = F_1 ( V_8 ) ;
int V_15 ;
V_7 = F_57 ( V_184 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
if ( V_112 ) {
struct V_309 V_21 ;
F_45 ( & V_21 . V_112 , V_112 ) ;
V_21 . V_8 = V_8 ;
V_15 = F_11 ( V_7 -> V_5 , V_7 -> V_6 , V_184 ,
& V_21 , sizeof( V_21 ) ) ;
} else
V_15 = F_3 ( V_7 -> V_5 , V_48 -> V_46 , V_184 ,
V_302 ) ;
F_58 ( V_7 ) ;
return V_15 ;
}
int F_135 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_187 ,
T_1 V_188 , T_1 V_8 )
{
struct V_312 V_14 ;
F_45 ( & V_14 . V_200 . V_112 , V_112 ) ;
V_14 . V_200 . type = F_83 ( V_187 , V_188 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
return F_66 ( V_313 , V_48 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_136 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_314 )
{
struct V_315 V_14 ;
F_45 ( & V_14 . V_112 , V_112 ) ;
V_14 . V_314 = V_314 ;
return F_66 ( V_316 , V_48 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_137 ( struct V_36 * V_48 , T_6 * V_112 ,
T_1 V_8 )
{
struct V_117 * V_7 ;
struct V_317 V_21 ;
int V_15 ;
V_7 = F_57 ( V_210 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
F_45 ( & V_21 . V_112 , V_112 ) ;
V_21 . V_8 = F_1 ( V_8 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_48 -> V_46 , V_210 , & V_21 ,
sizeof( V_21 ) ) ;
F_58 ( V_7 ) ;
return V_15 ;
}
int F_138 ( struct V_36 * V_48 , T_6 * V_112 ,
T_1 V_8 )
{
struct V_117 * V_7 ;
struct V_317 V_21 ;
int V_15 ;
V_7 = F_57 ( V_204 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
F_45 ( & V_21 . V_112 , V_112 ) ;
V_21 . V_8 = F_1 ( V_8 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_48 -> V_46 , V_204 , & V_21 ,
sizeof( V_21 ) ) ;
F_58 ( V_7 ) ;
return V_15 ;
}
int F_139 ( struct V_36 * V_48 , T_6 * V_112 ,
T_5 V_318 , T_1 V_319 )
{
struct V_320 V_14 ;
F_4 ( L_4 , V_48 -> V_98 ) ;
F_45 ( & V_14 . V_112 , V_112 ) ;
V_14 . V_319 = V_319 ;
F_140 ( V_318 , & V_14 . V_318 ) ;
return F_66 ( V_321 , V_48 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
int F_141 ( struct V_36 * V_48 , T_6 * V_112 )
{
struct V_322 V_14 ;
F_4 ( L_4 , V_48 -> V_98 ) ;
F_45 ( & V_14 . V_112 , V_112 ) ;
return F_66 ( V_323 , V_48 , & V_14 , sizeof( V_14 ) ,
NULL ) ;
}
static int F_142 ( struct V_36 * V_48 , T_6 * V_112 ,
T_1 V_8 , T_1 V_18 )
{
struct V_117 * V_7 ;
struct V_324 V_21 ;
int V_15 ;
V_7 = F_57 ( V_18 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
F_45 ( & V_21 . V_112 , V_112 ) ;
V_21 . V_8 = F_1 ( V_8 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_48 -> V_46 , V_18 , & V_21 , sizeof( V_21 ) ) ;
F_58 ( V_7 ) ;
return V_15 ;
}
int F_143 ( struct V_36 * V_48 , T_6 * V_112 ,
T_1 V_8 )
{
return F_142 ( V_48 , V_112 , V_8 ,
V_242 ) ;
}
int F_144 ( struct V_36 * V_48 ,
T_6 * V_112 , T_1 V_8 )
{
return F_142 ( V_48 , V_112 , V_8 ,
V_245 ) ;
}
int F_145 ( struct V_36 * V_48 , T_6 * V_112 ,
T_1 V_8 )
{
return F_142 ( V_48 , V_112 , V_8 ,
V_248 ) ;
}
int F_146 ( struct V_36 * V_48 ,
T_6 * V_112 , T_1 V_8 )
{
return F_142 ( V_48 , V_112 , V_8 ,
V_251 ) ;
}
int F_147 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_8 )
{
struct V_325 V_14 ;
F_45 ( & V_14 . V_112 , V_112 ) ;
V_14 . V_8 = F_1 ( V_8 ) ;
return F_66 ( V_326 , V_48 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_148 ( struct V_36 * V_48 , T_1 * V_98 , T_1 V_8 )
{
struct V_117 * V_7 ;
struct V_253 V_14 ;
int V_15 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memcpy ( V_14 . V_98 , V_98 , V_327 ) ;
V_7 = F_57 ( V_257 , V_48 ) ;
if ( ! V_7 )
goto V_328;
if ( V_8 ) {
V_15 = F_3 ( V_7 -> V_5 , V_48 -> V_46 , V_257 ,
F_1 ( V_8 ) ) ;
goto V_125;
}
F_28 ( V_48 ) ;
V_15 = F_11 ( V_7 -> V_5 , V_48 -> V_46 , V_257 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
goto V_125;
V_328:
V_15 = F_66 ( V_329 , V_48 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
V_125:
if ( V_7 )
F_58 ( V_7 ) ;
return V_15 ;
}
int F_149 ( struct V_36 * V_48 , T_1 * V_264 ,
T_1 * V_265 , T_1 V_8 )
{
struct V_117 * V_7 ;
int V_15 ;
F_4 ( L_18 , V_48 -> V_98 , V_8 ) ;
V_7 = F_57 ( V_259 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
if ( V_8 ) {
V_15 = F_3 ( V_7 -> V_5 , V_48 -> V_46 ,
V_259 ,
F_1 ( V_8 ) ) ;
} else {
struct V_330 V_21 ;
memcpy ( V_21 . V_264 , V_264 , sizeof( V_21 . V_264 ) ) ;
memcpy ( V_21 . V_265 , V_265 , sizeof( V_21 . V_265 ) ) ;
V_15 = F_11 ( V_7 -> V_5 , V_48 -> V_46 ,
V_259 ,
& V_21 , sizeof( V_21 ) ) ;
}
F_58 ( V_7 ) ;
return V_15 ;
}
int F_150 ( struct V_36 * V_48 , T_6 * V_112 , T_1 V_187 ,
T_1 V_188 , T_1 * V_101 , T_7 V_331 , T_1 * V_94 )
{
struct V_332 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
F_45 ( & V_14 . V_200 . V_112 , V_112 ) ;
V_14 . V_200 . type = F_83 ( V_187 , V_188 ) ;
V_14 . V_331 = V_331 ;
if ( V_94 )
memcpy ( V_14 . V_94 , V_94 , sizeof( V_14 . V_94 ) ) ;
if ( V_101 )
memcpy ( V_14 . V_101 , V_101 , sizeof( V_14 . V_101 ) ) ;
return F_66 ( V_333 , V_48 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_151 ( struct V_36 * V_48 , T_6 * V_112 , T_1 * V_98 )
{
struct V_334 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
F_45 ( & V_14 . V_112 , V_112 ) ;
memcpy ( V_14 . V_98 , V_98 , V_327 ) ;
return F_66 ( V_335 , V_48 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_152 ( struct V_36 * V_48 , T_1 V_8 )
{
struct V_117 * V_7 ;
int V_15 ;
V_7 = F_57 ( V_269 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
V_15 = F_3 ( V_7 -> V_5 , V_48 -> V_46 , V_7 -> V_18 , F_1 ( V_8 ) ) ;
F_58 ( V_7 ) ;
return V_15 ;
}
int F_153 ( struct V_36 * V_48 , T_1 V_8 )
{
struct V_117 * V_7 ;
int V_15 ;
V_7 = F_57 ( V_271 , V_48 ) ;
if ( ! V_7 )
return - V_311 ;
V_15 = F_3 ( V_7 -> V_5 , V_48 -> V_46 , V_7 -> V_18 , F_1 ( V_8 ) ) ;
F_58 ( V_7 ) ;
return V_15 ;
}
int F_154 ( struct V_36 * V_48 , T_1 V_336 )
{
struct V_117 * V_7 ;
if ( V_336 )
V_7 = F_57 ( V_269 , V_48 ) ;
else
V_7 = F_57 ( V_271 , V_48 ) ;
if ( V_7 != NULL ) {
F_11 ( V_7 -> V_5 , V_48 -> V_46 , V_7 -> V_18 , NULL , 0 ) ;
F_58 ( V_7 ) ;
}
return F_66 ( V_337 , V_48 , & V_336 ,
sizeof( V_336 ) , NULL ) ;
}
int F_155 ( struct V_36 * V_48 , T_6 * V_112 )
{
struct V_117 * V_7 ;
struct V_338 V_14 ;
V_7 = F_57 ( V_273 , V_48 ) ;
F_45 ( & V_14 . V_112 , V_112 ) ;
return F_66 ( V_339 , V_48 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
int F_156 ( struct V_36 * V_48 , T_6 * V_112 )
{
struct V_117 * V_7 ;
struct V_340 V_14 ;
V_7 = F_57 ( V_275 , V_48 ) ;
F_45 ( & V_14 . V_112 , V_112 ) ;
return F_66 ( V_341 , V_48 , & V_14 , sizeof( V_14 ) ,
V_7 ? V_7 -> V_5 : NULL ) ;
}
