static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_2 ( L_1 , V_2 , V_3 , V_4 , V_5 ) ;
V_7 = F_3 ( sizeof( * V_9 ) + sizeof( * V_11 ) , V_12 ) ;
if ( ! V_7 )
return - V_13 ;
V_9 = ( void * ) F_4 ( V_7 , sizeof( * V_9 ) ) ;
V_9 -> V_14 = F_5 ( V_15 ) ;
V_9 -> V_3 = F_5 ( V_3 ) ;
V_9 -> V_16 = F_5 ( sizeof( * V_11 ) ) ;
V_11 = ( void * ) F_4 ( V_7 , sizeof( * V_11 ) ) ;
V_11 -> V_5 = V_5 ;
F_6 ( V_4 , & V_11 -> V_14 ) ;
if ( F_7 ( V_2 , V_7 ) < 0 )
F_8 ( V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_17 ,
T_3 V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_19 * V_11 ;
F_2 ( L_2 , V_2 ) ;
V_7 = F_3 ( sizeof( * V_9 ) + sizeof( * V_11 ) + V_18 , V_12 ) ;
if ( ! V_7 )
return - V_13 ;
V_9 = ( void * ) F_4 ( V_7 , sizeof( * V_9 ) ) ;
V_9 -> V_14 = F_5 ( V_20 ) ;
V_9 -> V_3 = F_5 ( V_3 ) ;
V_9 -> V_16 = F_5 ( sizeof( * V_11 ) + V_18 ) ;
V_11 = ( void * ) F_4 ( V_7 , sizeof( * V_11 ) + V_18 ) ;
F_6 ( V_4 , & V_11 -> V_14 ) ;
if ( V_17 )
memcpy ( V_11 -> V_21 , V_17 , V_18 ) ;
if ( F_7 ( V_2 , V_7 ) < 0 )
F_8 ( V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_22 V_17 ;
F_2 ( L_2 , V_2 ) ;
V_17 . V_23 = V_24 ;
F_6 ( V_25 , & V_17 . V_26 ) ;
return F_9 ( V_2 , V_27 , V_28 , & V_17 ,
sizeof( V_17 ) ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_17 ;
struct V_30 * V_31 ;
T_3 V_18 ;
T_1 V_32 ;
int V_33 , V_34 ;
F_2 ( L_2 , V_2 ) ;
F_12 ( & V_35 ) ;
V_32 = 0 ;
F_13 (p, &hci_dev_list) {
V_32 ++ ;
}
V_18 = sizeof( * V_17 ) + ( 2 * V_32 ) ;
V_17 = F_14 ( V_18 , V_12 ) ;
if ( ! V_17 ) {
F_15 ( & V_35 ) ;
return - V_13 ;
}
F_6 ( V_32 , & V_17 -> V_36 ) ;
V_33 = 0 ;
F_13 (p, &hci_dev_list) {
struct V_37 * V_38 = F_16 ( V_31 , struct V_37 , V_39 ) ;
F_17 ( V_38 ) ;
F_18 ( V_40 , & V_38 -> V_41 ) ;
if ( F_19 ( V_42 , & V_38 -> V_41 ) )
continue;
F_6 ( V_38 -> V_43 , & V_17 -> V_3 [ V_33 ++ ] ) ;
F_2 ( L_3 , V_38 -> V_43 ) ;
}
F_15 ( & V_35 ) ;
V_34 = F_9 ( V_2 , V_27 , V_44 , V_17 ,
V_18 ) ;
F_20 ( V_17 ) ;
return V_34 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_45 V_17 ;
struct V_37 * V_46 ;
F_2 ( L_4 , V_2 , V_3 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_47 , V_48 ) ;
F_17 ( V_46 ) ;
F_23 ( V_46 ) ;
F_18 ( V_40 , & V_46 -> V_41 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . type = V_46 -> V_49 ;
V_17 . V_50 = F_19 ( V_51 , & V_46 -> V_41 ) ;
V_17 . V_52 = F_19 ( V_53 , & V_46 -> V_41 ) ;
V_17 . V_54 = F_19 ( V_55 , & V_46 -> V_41 ) ;
V_17 . V_56 = F_19 ( V_53 , & V_46 -> V_41 ) ;
if ( F_19 ( V_57 , & V_46 -> V_41 ) )
V_17 . V_58 = 3 ;
else if ( V_46 -> V_59 > 0 )
V_17 . V_58 = 4 ;
else
V_17 . V_58 = 2 ;
F_24 ( & V_17 . V_60 , & V_46 -> V_60 ) ;
memcpy ( V_17 . V_61 , V_46 -> V_61 , 8 ) ;
memcpy ( V_17 . V_62 , V_46 -> V_62 , 3 ) ;
F_6 ( V_46 -> V_63 , & V_17 . V_63 ) ;
V_17 . V_64 = V_46 -> V_64 ;
F_6 ( V_46 -> V_65 , & V_17 . V_65 ) ;
memcpy ( V_17 . V_66 , V_46 -> V_67 , sizeof( V_46 -> V_67 ) ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return F_9 ( V_2 , V_3 , V_47 , & V_17 , sizeof( V_17 ) ) ;
}
static void F_27 ( struct V_68 * V_4 )
{
F_28 ( V_4 -> V_2 ) ;
F_20 ( V_4 -> V_69 ) ;
F_20 ( V_4 ) ;
}
static struct V_68 * F_29 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_3 , void * V_21 , T_1 V_16 )
{
struct V_68 * V_4 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_14 = V_14 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_69 = F_14 ( V_16 , V_12 ) ;
if ( ! V_4 -> V_69 ) {
F_20 ( V_4 ) ;
return NULL ;
}
if ( V_21 )
memcpy ( V_4 -> V_69 , V_21 , V_16 ) ;
V_4 -> V_2 = V_2 ;
F_30 ( V_2 ) ;
F_31 ( & V_4 -> V_39 , & V_70 ) ;
return V_4 ;
}
static void F_32 ( T_1 V_14 , int V_3 ,
void (* F_33)( struct V_68 * V_4 , void * V_21 ) ,
void * V_21 )
{
struct V_30 * V_31 , * V_71 ;
F_34 (p, n, &cmd_list) {
struct V_68 * V_4 ;
V_4 = F_16 ( V_31 , struct V_68 , V_39 ) ;
if ( V_4 -> V_14 != V_14 )
continue;
if ( V_3 >= 0 && V_4 -> V_3 != V_3 )
continue;
F_33 ( V_4 , V_21 ) ;
}
}
static struct V_68 * F_35 ( T_1 V_14 , int V_3 )
{
struct V_30 * V_31 ;
F_13 (p, &cmd_list) {
struct V_68 * V_4 ;
V_4 = F_16 ( V_31 , struct V_68 , V_39 ) ;
if ( V_4 -> V_14 != V_14 )
continue;
if ( V_3 >= 0 && V_4 -> V_3 != V_3 )
continue;
return V_4 ;
}
return NULL ;
}
static void F_36 ( struct V_68 * V_4 )
{
F_37 ( & V_4 -> V_39 ) ;
F_27 ( V_4 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_72 * V_73 ;
struct V_37 * V_46 ;
struct V_68 * V_4 ;
int V_34 , V_74 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_75 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_75 , V_48 ) ;
F_23 ( V_46 ) ;
V_74 = F_19 ( V_51 , & V_46 -> V_41 ) ;
if ( ( V_73 -> V_77 && V_74 ) || ( ! V_73 -> V_77 && ! V_74 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_75 , V_78 ) ;
goto V_79;
}
if ( F_35 ( V_75 , V_3 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_75 , V_80 ) ;
goto V_79;
}
V_4 = F_29 ( V_2 , V_75 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
if ( V_73 -> V_77 )
F_39 ( V_46 -> V_81 , & V_46 -> V_82 ) ;
else
F_39 ( V_46 -> V_81 , & V_46 -> V_83 ) ;
V_34 = 0 ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_72 * V_73 ;
struct V_37 * V_46 ;
struct V_68 * V_4 ;
T_2 V_84 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_85 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_85 , V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_85 , V_86 ) ;
goto V_79;
}
if ( F_35 ( V_85 , V_3 ) ||
F_35 ( V_87 , V_3 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_85 , V_80 ) ;
goto V_79;
}
if ( V_73 -> V_77 == F_19 ( V_55 , & V_46 -> V_41 ) &&
F_19 ( V_53 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_85 , V_78 ) ;
goto V_79;
}
V_4 = F_29 ( V_2 , V_85 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
V_84 = V_88 ;
if ( V_73 -> V_77 )
V_84 |= V_89 ;
V_34 = F_41 ( V_46 , V_90 , 1 , & V_84 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_72 * V_73 ;
struct V_37 * V_46 ;
struct V_68 * V_4 ;
T_2 V_84 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_87 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_87 , V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_87 , V_86 ) ;
goto V_79;
}
if ( F_35 ( V_85 , V_3 ) ||
F_35 ( V_87 , V_3 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_87 , V_80 ) ;
goto V_79;
}
if ( V_73 -> V_77 == F_19 ( V_53 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_87 , V_78 ) ;
goto V_79;
}
V_4 = F_29 ( V_2 , V_87 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
if ( V_73 -> V_77 )
V_84 = V_88 ;
else
V_84 = 0 ;
V_34 = F_41 ( V_46 , V_90 , 1 , & V_84 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_43 ( T_1 V_91 , T_1 V_3 , void * V_21 , T_1 V_92 ,
struct V_1 * V_93 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( sizeof( * V_9 ) + V_92 , V_12 ) ;
if ( ! V_7 )
return - V_13 ;
F_44 ( V_7 ) -> V_94 = V_95 ;
V_9 = ( void * ) F_4 ( V_7 , sizeof( * V_9 ) ) ;
V_9 -> V_14 = F_5 ( V_91 ) ;
V_9 -> V_3 = F_5 ( V_3 ) ;
V_9 -> V_16 = F_5 ( V_92 ) ;
if ( V_21 )
memcpy ( F_4 ( V_7 , V_92 ) , V_21 , V_92 ) ;
F_45 ( NULL , V_7 , V_93 ) ;
F_8 ( V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_3 , T_2 V_77 )
{
struct V_72 V_17 ;
V_17 . V_77 = V_77 ;
return F_9 ( V_2 , V_3 , V_14 , & V_17 , sizeof( V_17 ) ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_72 * V_73 , V_11 ;
struct V_37 * V_46 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_96 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_96 , V_48 ) ;
F_23 ( V_46 ) ;
if ( V_73 -> V_77 )
F_18 ( V_97 , & V_46 -> V_41 ) ;
else
F_48 ( V_97 , & V_46 -> V_41 ) ;
V_34 = F_46 ( V_2 , V_96 , V_3 , V_73 -> V_77 ) ;
if ( V_34 < 0 )
goto V_79;
V_11 . V_77 = V_73 -> V_77 ;
V_34 = F_43 ( V_98 , V_3 , & V_11 , sizeof( V_11 ) , V_2 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static T_1 F_49 ( T_2 * V_99 )
{
T_4 V_77 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 12 ; V_33 ++ ) {
if ( V_100 [ V_33 ] != V_99 [ V_33 ] )
return 0 ;
}
memcpy ( & V_77 , & V_99 [ 12 ] , 4 ) ;
V_77 = F_50 ( V_77 ) ;
if ( V_77 > 0xffff )
return 0 ;
return ( T_1 ) V_77 ;
}
static void F_51 ( struct V_37 * V_46 , T_2 * V_21 )
{
T_2 * V_101 = V_21 ;
T_1 V_102 = 0 ;
T_1 V_103 [ V_104 / sizeof( T_1 ) ] ;
int V_33 , V_105 = 0 ;
struct V_30 * V_31 ;
T_3 V_106 ;
V_106 = strlen ( V_46 -> V_67 ) ;
if ( V_106 > 0 ) {
if ( V_106 > 48 ) {
V_106 = 48 ;
V_101 [ 1 ] = V_107 ;
} else
V_101 [ 1 ] = V_108 ;
V_101 [ 0 ] = V_106 + 1 ;
memcpy ( V_101 + 2 , V_46 -> V_67 , V_106 ) ;
V_102 += ( V_106 + 2 ) ;
V_101 += ( V_106 + 2 ) ;
}
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
F_13 (p, &hdev->uuids) {
struct V_109 * V_110 = F_16 ( V_31 , struct V_109 , V_39 ) ;
T_1 V_111 ;
V_111 = F_49 ( V_110 -> V_110 ) ;
if ( V_111 == 0 )
return;
if ( V_111 < 0x1100 )
continue;
if ( V_111 == V_112 )
continue;
if ( V_102 + 2 + sizeof( T_1 ) > V_104 ) {
V_105 = 1 ;
break;
}
for ( V_33 = 0 ; V_103 [ V_33 ] != 0 ; V_33 ++ )
if ( V_103 [ V_33 ] == V_111 )
break;
if ( V_103 [ V_33 ] == 0 ) {
V_103 [ V_33 ] = V_111 ;
V_102 += sizeof( T_1 ) ;
}
}
if ( V_103 [ 0 ] != 0 ) {
T_2 * V_113 = V_101 ;
V_101 [ 1 ] = V_105 ? V_114 : V_115 ;
V_101 += 2 ;
V_102 += 2 ;
for ( V_33 = 0 ; V_103 [ V_33 ] != 0 ; V_33 ++ ) {
* V_101 ++ = ( V_103 [ V_33 ] & 0x00ff ) ;
* V_101 ++ = ( V_103 [ V_33 ] & 0xff00 ) >> 8 ;
}
* V_113 = ( V_33 * sizeof( T_1 ) ) + 1 ;
}
}
static int F_52 ( struct V_37 * V_46 )
{
struct V_116 V_73 ;
if ( ! ( V_46 -> V_61 [ 6 ] & V_117 ) )
return 0 ;
if ( V_46 -> V_59 == 0 )
return 0 ;
if ( F_19 ( V_118 , & V_46 -> V_41 ) )
return 0 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_51 ( V_46 , V_73 . V_21 ) ;
if ( memcmp ( V_73 . V_21 , V_46 -> V_119 , sizeof( V_73 . V_21 ) ) == 0 )
return 0 ;
memcpy ( V_46 -> V_119 , V_73 . V_21 , sizeof( V_73 . V_21 ) ) ;
return F_41 ( V_46 , V_120 , sizeof( V_73 ) , & V_73 ) ;
}
static T_2 F_53 ( struct V_37 * V_46 )
{
struct V_30 * V_31 ;
T_2 V_77 = 0 ;
F_13 (p, &hdev->uuids) {
struct V_109 * V_110 = F_16 ( V_31 , struct V_109 , V_39 ) ;
V_77 |= V_110 -> V_121 ;
}
return V_77 ;
}
static int F_54 ( struct V_37 * V_46 )
{
T_2 V_122 [ 3 ] ;
F_2 ( L_6 , V_46 -> V_66 ) ;
if ( F_19 ( V_118 , & V_46 -> V_41 ) )
return 0 ;
V_122 [ 0 ] = V_46 -> V_123 ;
V_122 [ 1 ] = V_46 -> V_124 ;
V_122 [ 2 ] = F_53 ( V_46 ) ;
if ( memcmp ( V_122 , V_46 -> V_62 , 3 ) == 0 )
return 0 ;
return F_41 ( V_46 , V_125 , sizeof( V_122 ) , V_122 ) ;
}
static int F_55 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_126 * V_73 ;
struct V_37 * V_46 ;
struct V_109 * V_110 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_127 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_127 , V_48 ) ;
F_23 ( V_46 ) ;
V_110 = F_14 ( sizeof( * V_110 ) , V_12 ) ;
if ( ! V_110 ) {
V_34 = - V_13 ;
goto V_79;
}
memcpy ( V_110 -> V_110 , V_73 -> V_110 , 16 ) ;
V_110 -> V_121 = V_73 -> V_121 ;
F_31 ( & V_110 -> V_39 , & V_46 -> V_128 ) ;
V_34 = F_54 ( V_46 ) ;
if ( V_34 < 0 )
goto V_79;
V_34 = F_52 ( V_46 ) ;
if ( V_34 < 0 )
goto V_79;
V_34 = F_9 ( V_2 , V_3 , V_127 , NULL , 0 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_56 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_30 * V_31 , * V_71 ;
struct V_129 * V_73 ;
struct V_37 * V_46 ;
T_2 V_130 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_34 , V_131 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_132 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_132 , V_48 ) ;
F_23 ( V_46 ) ;
if ( memcmp ( V_73 -> V_110 , V_130 , 16 ) == 0 ) {
V_34 = F_57 ( V_46 ) ;
goto V_133;
}
V_131 = 0 ;
F_34 (p, n, &hdev->uuids) {
struct V_109 * V_134 = F_16 ( V_31 , struct V_109 , V_39 ) ;
if ( memcmp ( V_134 -> V_110 , V_73 -> V_110 , 16 ) != 0 )
continue;
F_37 ( & V_134 -> V_39 ) ;
V_131 ++ ;
}
if ( V_131 == 0 ) {
V_34 = F_1 ( V_2 , V_3 , V_132 , V_135 ) ;
goto V_133;
}
V_34 = F_54 ( V_46 ) ;
if ( V_34 < 0 )
goto V_133;
V_34 = F_52 ( V_46 ) ;
if ( V_34 < 0 )
goto V_133;
V_34 = F_9 ( V_2 , V_3 , V_132 , NULL , 0 ) ;
V_133:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_136 * V_73 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
F_2 ( L_5 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_137 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_137 , V_48 ) ;
F_23 ( V_46 ) ;
V_46 -> V_124 = V_73 -> V_138 ;
V_46 -> V_123 = V_73 -> V_139 ;
V_34 = F_54 ( V_46 ) ;
if ( V_34 == 0 )
V_34 = F_9 ( V_2 , V_3 , V_137 , NULL , 0 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_140 * V_73 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_141 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_141 , V_48 ) ;
F_23 ( V_46 ) ;
F_2 ( L_7 , V_3 , V_73 -> V_142 ) ;
if ( V_73 -> V_142 ) {
F_18 ( V_118 , & V_46 -> V_41 ) ;
V_34 = 0 ;
} else {
F_48 ( V_118 , & V_46 -> V_41 ) ;
V_34 = F_54 ( V_46 ) ;
if ( V_34 == 0 )
V_34 = F_52 ( V_46 ) ;
}
if ( V_34 == 0 )
V_34 = F_9 ( V_2 , V_3 , V_141 , NULL ,
0 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_143 * V_73 ;
T_1 V_144 , V_145 ;
int V_33 , V_34 ;
V_73 = ( void * ) V_21 ;
if ( V_16 < sizeof( * V_73 ) )
return - V_76 ;
V_144 = F_61 ( & V_73 -> V_144 ) ;
V_145 = sizeof( * V_73 ) + V_144 * sizeof( struct V_146 ) ;
if ( V_145 > V_16 ) {
F_62 ( L_8 ,
V_145 , V_16 ) ;
return - V_76 ;
}
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_147 , V_48 ) ;
F_2 ( L_9 , V_3 , V_73 -> V_148 ,
V_144 ) ;
F_23 ( V_46 ) ;
F_63 ( V_46 ) ;
F_18 ( V_149 , & V_46 -> V_41 ) ;
if ( V_73 -> V_148 )
F_18 ( V_150 , & V_46 -> V_41 ) ;
else
F_48 ( V_150 , & V_46 -> V_41 ) ;
V_16 -= sizeof( * V_73 ) ;
V_33 = 0 ;
while ( V_33 < V_16 ) {
struct V_146 * V_151 = ( void * ) V_73 -> V_152 + V_33 ;
V_33 += sizeof( * V_151 ) + V_151 -> V_153 ;
if ( V_151 -> type == V_154 ) {
struct V_155 * V_43 = ( void * ) V_151 -> V_21 ;
if ( V_151 -> V_153 != sizeof( struct V_155 ) )
continue;
F_64 ( V_46 , 0 , & V_151 -> V_60 , V_151 -> V_156 ,
V_43 -> V_157 , V_43 -> rand , V_151 -> V_77 ) ;
continue;
}
F_65 ( V_46 , NULL , 0 , & V_151 -> V_60 , V_151 -> V_77 , V_151 -> type ,
V_151 -> V_156 ) ;
}
V_34 = F_9 ( V_2 , V_3 , V_147 , NULL , 0 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_158 * V_73 ;
struct V_159 * V_160 ;
int V_34 ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_161 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_161 , V_48 ) ;
F_23 ( V_46 ) ;
V_34 = F_67 ( V_46 , & V_73 -> V_60 ) ;
if ( V_34 < 0 ) {
V_34 = F_1 ( V_2 , V_3 , V_161 , - V_34 ) ;
goto V_133;
}
V_34 = 0 ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) || ! V_73 -> V_162 )
goto V_133;
V_160 = F_68 ( V_46 , V_163 , & V_73 -> V_60 ) ;
if ( V_160 ) {
struct V_164 V_165 ;
F_6 ( V_160 -> V_166 , & V_165 . V_166 ) ;
V_165 . V_167 = 0x13 ;
V_34 = F_41 ( V_46 , V_168 , sizeof( V_165 ) , & V_165 ) ;
}
V_133:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int V_162 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_169 * V_73 ;
struct V_164 V_165 ;
struct V_68 * V_4 ;
struct V_159 * V_160 ;
int V_34 ;
F_2 ( L_10 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_170 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_170 , V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_170 , V_86 ) ;
goto V_79;
}
if ( F_35 ( V_170 , V_3 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_170 , V_80 ) ;
goto V_79;
}
V_160 = F_68 ( V_46 , V_163 , & V_73 -> V_60 ) ;
if ( ! V_160 )
V_160 = F_68 ( V_46 , V_171 , & V_73 -> V_60 ) ;
if ( ! V_160 ) {
V_34 = F_1 ( V_2 , V_3 , V_170 , V_172 ) ;
goto V_79;
}
V_4 = F_29 ( V_2 , V_170 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
F_6 ( V_160 -> V_166 , & V_165 . V_166 ) ;
V_165 . V_167 = 0x13 ;
V_34 = F_41 ( V_46 , V_168 , sizeof( V_165 ) , & V_165 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_173 * V_17 ;
struct V_37 * V_46 ;
struct V_30 * V_31 ;
T_3 V_18 ;
T_1 V_32 ;
int V_33 , V_34 ;
F_2 ( L_10 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_174 , V_48 ) ;
F_23 ( V_46 ) ;
V_32 = 0 ;
F_13 (p, &hdev->conn_hash.list) {
V_32 ++ ;
}
V_18 = sizeof( * V_17 ) + ( V_32 * sizeof( V_175 ) ) ;
V_17 = F_14 ( V_18 , V_12 ) ;
if ( ! V_17 ) {
V_34 = - V_13 ;
goto V_133;
}
F_6 ( V_32 , & V_17 -> V_176 ) ;
V_33 = 0 ;
F_13 (p, &hdev->conn_hash.list) {
struct V_159 * V_177 = F_16 ( V_31 , struct V_159 , V_39 ) ;
F_24 ( & V_17 -> V_160 [ V_33 ++ ] , & V_177 -> V_178 ) ;
}
V_34 = F_9 ( V_2 , V_3 , V_174 , V_17 , V_18 ) ;
V_133:
F_20 ( V_17 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_70 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_37 * V_46 , struct V_179 * V_73 )
{
struct V_68 * V_4 ;
int V_34 ;
V_4 = F_29 ( V_2 , V_180 , V_3 , V_73 ,
sizeof( * V_73 ) ) ;
if ( ! V_4 )
return - V_13 ;
V_34 = F_41 ( V_46 , V_181 , sizeof( V_73 -> V_60 ) ,
& V_73 -> V_60 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
return V_34 ;
}
static int F_71 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_159 * V_160 ;
struct V_182 * V_73 ;
struct V_179 V_183 ;
struct V_184 V_185 ;
struct V_68 * V_4 ;
int V_34 ;
F_2 ( L_10 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_186 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_186 , V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_186 , V_86 ) ;
goto V_79;
}
V_160 = F_68 ( V_46 , V_163 , & V_73 -> V_60 ) ;
if ( ! V_160 ) {
V_34 = F_1 ( V_2 , V_3 , V_186 , V_172 ) ;
goto V_79;
}
if ( V_160 -> V_187 == V_188 && V_73 -> V_156 != 16 ) {
F_24 ( & V_183 . V_60 , & V_73 -> V_60 ) ;
F_62 ( L_11 ) ;
V_34 = F_70 ( V_2 , V_3 , V_46 , & V_183 ) ;
if ( V_34 >= 0 )
V_34 = F_1 ( V_2 , V_3 , V_186 ,
V_76 ) ;
goto V_79;
}
V_4 = F_29 ( V_2 , V_186 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
F_24 ( & V_185 . V_60 , & V_73 -> V_60 ) ;
V_185 . V_156 = V_73 -> V_156 ;
memcpy ( V_185 . V_189 , V_73 -> V_189 , sizeof( V_185 . V_189 ) ) ;
V_34 = F_41 ( V_46 , V_190 , sizeof( V_185 ) , & V_185 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_179 * V_73 ;
int V_34 ;
F_2 ( L_10 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_180 ,
V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_180 ,
V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_180 ,
V_86 ) ;
goto V_79;
}
V_34 = F_70 ( V_2 , V_3 , V_46 , V_73 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_73 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_191 * V_73 ;
F_2 ( L_10 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_192 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_192 , V_48 ) ;
F_23 ( V_46 ) ;
V_46 -> V_193 = V_73 -> V_193 ;
F_2 ( L_12 , V_46 -> V_66 ,
V_46 -> V_193 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return F_9 ( V_2 , V_3 , V_192 , NULL , 0 ) ;
}
static inline struct V_68 * F_74 ( struct V_159 * V_160 )
{
struct V_37 * V_46 = V_160 -> V_46 ;
struct V_30 * V_31 ;
F_13 (p, &cmd_list) {
struct V_68 * V_4 ;
V_4 = F_16 ( V_31 , struct V_68 , V_39 ) ;
if ( V_4 -> V_14 != V_194 )
continue;
if ( V_4 -> V_3 != V_46 -> V_43 )
continue;
if ( V_4 -> V_195 != V_160 )
continue;
return V_4 ;
}
return NULL ;
}
static void F_75 ( struct V_68 * V_4 , T_2 V_5 )
{
struct V_196 V_17 ;
struct V_159 * V_160 = V_4 -> V_195 ;
F_24 ( & V_17 . V_60 , & V_160 -> V_178 ) ;
V_17 . V_5 = V_5 ;
F_9 ( V_4 -> V_2 , V_4 -> V_3 , V_194 , & V_17 , sizeof( V_17 ) ) ;
V_160 -> V_197 = NULL ;
V_160 -> V_198 = NULL ;
V_160 -> V_199 = NULL ;
F_76 ( V_160 ) ;
F_36 ( V_4 ) ;
}
static void F_77 ( struct V_159 * V_160 , T_2 V_5 )
{
struct V_68 * V_4 ;
F_2 ( L_13 , V_5 ) ;
V_4 = F_74 ( V_160 ) ;
if ( ! V_4 ) {
F_2 ( L_14 ) ;
return;
}
F_75 ( V_4 , V_5 ) ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 , T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_200 * V_73 ;
struct V_68 * V_4 ;
T_2 V_201 , V_202 ;
struct V_159 * V_160 ;
int V_34 ;
F_2 ( L_10 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_194 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_194 , V_48 ) ;
F_23 ( V_46 ) ;
if ( V_73 -> V_203 == 0x03 ) {
V_201 = V_204 ;
V_202 = V_205 ;
} else {
V_201 = V_188 ;
V_202 = V_206 ;
}
V_160 = F_79 ( V_46 , V_163 , & V_73 -> V_60 , V_201 , V_202 ) ;
if ( F_80 ( V_160 ) ) {
V_34 = F_81 ( V_160 ) ;
goto V_133;
}
if ( V_160 -> V_197 ) {
F_76 ( V_160 ) ;
V_34 = F_1 ( V_2 , V_3 , V_194 , V_80 ) ;
goto V_133;
}
V_4 = F_29 ( V_2 , V_194 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
F_76 ( V_160 ) ;
goto V_133;
}
V_160 -> V_197 = F_77 ;
V_160 -> V_198 = F_77 ;
V_160 -> V_199 = F_77 ;
V_160 -> V_193 = V_73 -> V_203 ;
V_4 -> V_195 = V_160 ;
if ( V_160 -> V_207 == V_208 &&
F_82 ( V_160 , V_201 , V_202 ) )
F_75 ( V_4 , 0 ) ;
V_34 = 0 ;
V_133:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 , int V_209 )
{
struct V_210 * V_73 = ( void * ) V_21 ;
T_1 V_211 , V_212 ;
struct V_68 * V_4 ;
struct V_37 * V_46 ;
int V_34 ;
F_2 ( L_10 ) ;
if ( V_209 ) {
V_211 = V_213 ;
V_212 = V_214 ;
} else {
V_211 = V_215 ;
V_212 = V_216 ;
}
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_211 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_211 , V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_211 , V_86 ) ;
goto V_79;
}
V_4 = F_29 ( V_2 , V_211 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
V_34 = F_41 ( V_46 , V_212 , sizeof( V_73 -> V_60 ) , & V_73 -> V_60 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_217 * V_218 = ( void * ) V_21 ;
struct V_219 V_220 ;
struct V_37 * V_46 ;
struct V_68 * V_4 ;
int V_34 ;
F_2 ( L_10 ) ;
if ( V_16 != sizeof( * V_218 ) )
return F_1 ( V_2 , V_3 , V_221 , V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_221 , V_48 ) ;
F_23 ( V_46 ) ;
V_4 = F_29 ( V_2 , V_221 , V_3 , V_21 , V_16 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
memcpy ( V_220 . V_66 , V_218 -> V_66 , sizeof( V_220 . V_66 ) ) ;
V_34 = F_41 ( V_46 , V_222 , sizeof( V_220 ) ,
& V_220 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_85 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_37 * V_46 ;
struct V_68 * V_4 ;
int V_34 ;
F_2 ( L_15 , V_3 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_223 ,
V_48 ) ;
F_23 ( V_46 ) ;
if ( ! F_19 ( V_51 , & V_46 -> V_41 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_223 ,
V_86 ) ;
goto V_133;
}
if ( ! ( V_46 -> V_61 [ 6 ] & V_224 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_223 ,
V_225 ) ;
goto V_133;
}
if ( F_35 ( V_223 , V_3 ) ) {
V_34 = F_1 ( V_2 , V_3 , V_223 , V_80 ) ;
goto V_133;
}
V_4 = F_29 ( V_2 , V_223 , V_3 , NULL , 0 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_133;
}
V_34 = F_41 ( V_46 , V_226 , 0 , NULL ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_133:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_227 * V_73 = ( void * ) V_21 ;
int V_34 ;
F_2 ( L_16 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_228 ,
V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_228 ,
V_48 ) ;
F_23 ( V_46 ) ;
V_34 = F_87 ( V_46 , & V_73 -> V_60 , V_73 -> V_229 ,
V_73 -> V_230 ) ;
if ( V_34 < 0 )
V_34 = F_1 ( V_2 , V_3 , V_228 , - V_34 ) ;
else
V_34 = F_9 ( V_2 , V_3 , V_228 , NULL ,
0 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_88 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char * V_21 , T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_231 * V_73 = ( void * ) V_21 ;
int V_34 ;
F_2 ( L_16 , V_3 ) ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_232 ,
V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_232 ,
V_48 ) ;
F_23 ( V_46 ) ;
V_34 = F_89 ( V_46 , & V_73 -> V_60 ) ;
if ( V_34 < 0 )
V_34 = F_1 ( V_2 , V_3 , V_232 ,
- V_34 ) ;
else
V_34 = F_9 ( V_2 , V_3 , V_232 ,
NULL , 0 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_233 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_234 V_73 ;
struct V_68 * V_4 ;
struct V_37 * V_46 ;
int V_34 ;
F_2 ( L_15 , V_3 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_235 , V_48 ) ;
F_23 ( V_46 ) ;
V_4 = F_29 ( V_2 , V_235 , V_3 , NULL , 0 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
memcpy ( & V_73 . V_233 , V_233 , 3 ) ;
V_73 . V_113 = 0x08 ;
V_73 . V_236 = 0x00 ;
V_34 = F_41 ( V_46 , V_237 , sizeof( V_73 ) , & V_73 ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_37 * V_46 ;
struct V_68 * V_4 ;
int V_34 ;
F_2 ( L_15 , V_3 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_238 , V_48 ) ;
F_23 ( V_46 ) ;
V_4 = F_29 ( V_2 , V_238 , V_3 , NULL , 0 ) ;
if ( ! V_4 ) {
V_34 = - V_13 ;
goto V_79;
}
V_34 = F_41 ( V_46 , V_239 , 0 , NULL ) ;
if ( V_34 < 0 )
F_36 ( V_4 ) ;
V_79:
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_92 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_240 * V_73 ;
int V_34 ;
F_2 ( L_15 , V_3 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_241 ,
V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_241 ,
V_48 ) ;
V_34 = F_93 ( V_46 , & V_73 -> V_60 ) ;
if ( V_34 < 0 )
V_34 = F_1 ( V_2 , V_3 , V_241 , - V_34 ) ;
else
V_34 = F_9 ( V_2 , V_3 , V_241 ,
NULL , 0 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
static int F_94 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_21 ,
T_1 V_16 )
{
struct V_37 * V_46 ;
struct V_242 * V_73 ;
int V_34 ;
F_2 ( L_15 , V_3 ) ;
V_73 = ( void * ) V_21 ;
if ( V_16 != sizeof( * V_73 ) )
return F_1 ( V_2 , V_3 , V_243 ,
V_76 ) ;
V_46 = F_22 ( V_3 ) ;
if ( ! V_46 )
return F_1 ( V_2 , V_3 , V_243 ,
V_48 ) ;
V_34 = F_95 ( V_46 , & V_73 -> V_60 ) ;
if ( V_34 < 0 )
V_34 = F_1 ( V_2 , V_3 , V_243 , - V_34 ) ;
else
V_34 = F_9 ( V_2 , V_3 , V_243 ,
NULL , 0 ) ;
F_26 ( V_46 ) ;
return V_34 ;
}
int F_96 ( struct V_1 * V_2 , struct V_244 * V_245 , T_3 V_246 )
{
unsigned char * V_247 ;
struct V_8 * V_9 ;
T_1 V_14 , V_3 , V_16 ;
int V_34 ;
F_2 ( L_17 , V_246 ) ;
if ( V_246 < sizeof( * V_9 ) )
return - V_76 ;
V_247 = F_14 ( V_246 , V_248 ) ;
if ( ! V_247 )
return - V_13 ;
if ( F_97 ( V_247 , V_245 -> V_249 , V_246 ) ) {
V_34 = - V_250 ;
goto V_251;
}
V_9 = (struct V_8 * ) V_247 ;
V_14 = F_61 ( & V_9 -> V_14 ) ;
V_3 = F_61 ( & V_9 -> V_3 ) ;
V_16 = F_61 ( & V_9 -> V_16 ) ;
if ( V_16 != V_246 - sizeof( * V_9 ) ) {
V_34 = - V_76 ;
goto V_251;
}
switch ( V_14 ) {
case V_28 :
V_34 = F_10 ( V_2 ) ;
break;
case V_44 :
V_34 = F_11 ( V_2 ) ;
break;
case V_47 :
V_34 = F_21 ( V_2 , V_3 ) ;
break;
case V_75 :
V_34 = F_38 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_85 :
V_34 = F_40 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_87 :
V_34 = F_42 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_96 :
V_34 = F_47 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_127 :
V_34 = F_55 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_132 :
V_34 = F_56 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_137 :
V_34 = F_58 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_141 :
V_34 = F_59 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_147 :
V_34 = F_60 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_161 :
V_34 = F_66 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_170 :
V_34 = V_162 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_174 :
V_34 = F_69 ( V_2 , V_3 ) ;
break;
case V_186 :
V_34 = F_71 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_180 :
V_34 = F_72 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_192 :
V_34 = F_73 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_194 :
V_34 = F_78 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_213 :
V_34 = F_83 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 , 1 ) ;
break;
case V_215 :
V_34 = F_83 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 , 0 ) ;
break;
case V_221 :
V_34 = F_84 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_223 :
V_34 = F_85 ( V_2 , V_3 ) ;
break;
case V_228 :
V_34 = F_86 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_232 :
V_34 = F_88 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) ,
V_16 ) ;
break;
case V_235 :
V_34 = F_90 ( V_2 , V_3 ) ;
break;
case V_238 :
V_34 = F_91 ( V_2 , V_3 ) ;
break;
case V_241 :
V_34 = F_92 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
case V_243 :
V_34 = F_94 ( V_2 , V_3 , V_247 + sizeof( * V_9 ) , V_16 ) ;
break;
default:
F_2 ( L_18 , V_14 ) ;
V_34 = F_1 ( V_2 , V_3 , V_14 , 0x01 ) ;
break;
}
if ( V_34 < 0 )
goto V_251;
V_34 = V_246 ;
V_251:
F_20 ( V_247 ) ;
return V_34 ;
}
int F_98 ( T_1 V_3 )
{
return F_43 ( V_252 , V_3 , NULL , 0 , NULL ) ;
}
int F_99 ( T_1 V_3 )
{
return F_43 ( V_253 , V_3 , NULL , 0 , NULL ) ;
}
static void F_100 ( struct V_68 * V_4 , void * V_21 )
{
struct V_72 * V_73 = V_4 -> V_69 ;
struct V_254 * V_134 = V_21 ;
if ( V_73 -> V_77 != V_134 -> V_77 )
return;
F_46 ( V_4 -> V_2 , V_4 -> V_14 , V_4 -> V_3 , V_73 -> V_77 ) ;
F_37 ( & V_4 -> V_39 ) ;
if ( V_134 -> V_2 == NULL ) {
V_134 -> V_2 = V_4 -> V_2 ;
F_30 ( V_134 -> V_2 ) ;
}
F_27 ( V_4 ) ;
}
int F_101 ( T_1 V_3 , T_2 V_50 )
{
struct V_72 V_11 ;
struct V_254 V_134 = { V_50 , NULL } ;
int V_255 ;
F_32 ( V_75 , V_3 , F_100 , & V_134 ) ;
V_11 . V_77 = V_50 ;
V_255 = F_43 ( V_256 , V_3 , & V_11 , sizeof( V_11 ) , V_134 . V_2 ) ;
if ( V_134 . V_2 )
F_28 ( V_134 . V_2 ) ;
return V_255 ;
}
int F_102 ( T_1 V_3 , T_2 V_54 )
{
struct V_72 V_11 ;
struct V_254 V_134 = { V_54 , NULL } ;
int V_255 ;
F_32 ( V_85 , V_3 , F_100 , & V_134 ) ;
V_11 . V_77 = V_54 ;
V_255 = F_43 ( V_257 , V_3 , & V_11 , sizeof( V_11 ) ,
V_134 . V_2 ) ;
if ( V_134 . V_2 )
F_28 ( V_134 . V_2 ) ;
return V_255 ;
}
int F_103 ( T_1 V_3 , T_2 V_52 )
{
struct V_72 V_11 ;
struct V_254 V_134 = { V_52 , NULL } ;
int V_255 ;
F_32 ( V_87 , V_3 , F_100 , & V_134 ) ;
V_11 . V_77 = V_52 ;
V_255 = F_43 ( V_258 , V_3 , & V_11 , sizeof( V_11 ) , V_134 . V_2 ) ;
if ( V_134 . V_2 )
F_28 ( V_134 . V_2 ) ;
return V_255 ;
}
int F_104 ( T_1 V_3 , struct V_259 * V_151 , T_2 V_260 )
{
struct V_261 * V_11 ;
int V_34 , V_262 ;
V_262 = sizeof( struct V_261 ) + V_151 -> V_153 ;
V_11 = F_105 ( V_262 , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
F_24 ( & V_11 -> V_151 . V_60 , & V_151 -> V_60 ) ;
V_11 -> V_151 . type = V_151 -> type ;
memcpy ( V_11 -> V_151 . V_77 , V_151 -> V_77 , 16 ) ;
V_11 -> V_151 . V_156 = V_151 -> V_156 ;
V_11 -> V_151 . V_153 = V_151 -> V_153 ;
V_11 -> V_263 = V_260 ;
memcpy ( V_11 -> V_151 . V_21 , V_151 -> V_21 , V_151 -> V_153 ) ;
V_34 = F_43 ( V_264 , V_3 , V_11 , V_262 , NULL ) ;
F_20 ( V_11 ) ;
return V_34 ;
}
int F_106 ( T_1 V_3 , V_175 * V_60 )
{
struct V_265 V_11 ;
F_24 ( & V_11 . V_60 , V_60 ) ;
return F_43 ( V_266 , V_3 , & V_11 , sizeof( V_11 ) , NULL ) ;
}
static void F_107 ( struct V_68 * V_4 , void * V_21 )
{
struct V_169 * V_73 = V_4 -> V_69 ;
struct V_1 * * V_2 = V_21 ;
struct V_267 V_17 ;
F_24 ( & V_17 . V_60 , & V_73 -> V_60 ) ;
F_9 ( V_4 -> V_2 , V_4 -> V_3 , V_170 , & V_17 , sizeof( V_17 ) ) ;
* V_2 = V_4 -> V_2 ;
F_30 ( * V_2 ) ;
F_36 ( V_4 ) ;
}
int F_108 ( T_1 V_3 , V_175 * V_60 )
{
struct V_268 V_11 ;
struct V_1 * V_2 = NULL ;
int V_34 ;
F_32 ( V_170 , V_3 , F_107 , & V_2 ) ;
F_24 ( & V_11 . V_60 , V_60 ) ;
V_34 = F_43 ( V_269 , V_3 , & V_11 , sizeof( V_11 ) , V_2 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
return V_34 ;
}
int F_109 ( T_1 V_3 )
{
struct V_68 * V_4 ;
int V_34 ;
V_4 = F_35 ( V_170 , V_3 ) ;
if ( ! V_4 )
return - V_135 ;
V_34 = F_1 ( V_4 -> V_2 , V_3 , V_170 , V_270 ) ;
F_36 ( V_4 ) ;
return V_34 ;
}
int F_110 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 )
{
struct V_271 V_11 ;
F_24 ( & V_11 . V_60 , V_60 ) ;
V_11 . V_5 = V_5 ;
return F_43 ( V_272 , V_3 , & V_11 , sizeof( V_11 ) , NULL ) ;
}
int F_111 ( T_1 V_3 , V_175 * V_60 , T_2 V_273 )
{
struct V_274 V_11 ;
F_24 ( & V_11 . V_60 , V_60 ) ;
V_11 . V_273 = V_273 ;
return F_43 ( V_275 , V_3 , & V_11 , sizeof( V_11 ) ,
NULL ) ;
}
int F_112 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 )
{
struct V_68 * V_4 ;
struct V_276 V_17 ;
int V_34 ;
V_4 = F_35 ( V_186 , V_3 ) ;
if ( ! V_4 )
return - V_135 ;
F_24 ( & V_17 . V_60 , V_60 ) ;
V_17 . V_5 = V_5 ;
V_34 = F_9 ( V_4 -> V_2 , V_3 , V_186 , & V_17 ,
sizeof( V_17 ) ) ;
F_36 ( V_4 ) ;
return V_34 ;
}
int F_113 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 )
{
struct V_68 * V_4 ;
struct V_276 V_17 ;
int V_34 ;
V_4 = F_35 ( V_180 , V_3 ) ;
if ( ! V_4 )
return - V_135 ;
F_24 ( & V_17 . V_60 , V_60 ) ;
V_17 . V_5 = V_5 ;
V_34 = F_9 ( V_4 -> V_2 , V_3 , V_180 , & V_17 ,
sizeof( V_17 ) ) ;
F_36 ( V_4 ) ;
return V_34 ;
}
int F_114 ( T_1 V_3 , V_175 * V_60 , T_5 V_277 ,
T_2 V_278 )
{
struct V_279 V_11 ;
F_2 ( L_15 , V_3 ) ;
F_24 ( & V_11 . V_60 , V_60 ) ;
V_11 . V_278 = V_278 ;
F_115 ( V_277 , & V_11 . V_277 ) ;
return F_43 ( V_280 , V_3 , & V_11 , sizeof( V_11 ) ,
NULL ) ;
}
static int F_116 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 ,
T_2 V_14 )
{
struct V_68 * V_4 ;
struct V_281 V_17 ;
int V_34 ;
V_4 = F_35 ( V_14 , V_3 ) ;
if ( ! V_4 )
return - V_135 ;
F_24 ( & V_17 . V_60 , V_60 ) ;
V_17 . V_5 = V_5 ;
V_34 = F_9 ( V_4 -> V_2 , V_3 , V_14 , & V_17 , sizeof( V_17 ) ) ;
F_36 ( V_4 ) ;
return V_34 ;
}
int F_117 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 )
{
return F_116 ( V_3 , V_60 , V_5 ,
V_213 ) ;
}
int F_118 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 )
{
return F_116 ( V_3 , V_60 , V_5 ,
V_215 ) ;
}
int F_119 ( T_1 V_3 , V_175 * V_60 , T_2 V_5 )
{
struct V_282 V_11 ;
F_24 ( & V_11 . V_60 , V_60 ) ;
V_11 . V_5 = V_5 ;
return F_43 ( V_283 , V_3 , & V_11 , sizeof( V_11 ) , NULL ) ;
}
int F_120 ( T_1 V_3 , T_2 * V_66 , T_2 V_5 )
{
struct V_68 * V_4 ;
struct V_37 * V_46 ;
struct V_217 V_11 ;
int V_34 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
memcpy ( V_11 . V_66 , V_66 , V_284 ) ;
V_4 = F_35 ( V_221 , V_3 ) ;
if ( ! V_4 )
goto V_285;
if ( V_5 ) {
V_34 = F_1 ( V_4 -> V_2 , V_3 , V_221 , V_270 ) ;
goto V_79;
}
V_46 = F_22 ( V_3 ) ;
if ( V_46 ) {
F_23 ( V_46 ) ;
F_52 ( V_46 ) ;
F_25 ( V_46 ) ;
F_26 ( V_46 ) ;
}
V_34 = F_9 ( V_4 -> V_2 , V_3 , V_221 , & V_11 ,
sizeof( V_11 ) ) ;
if ( V_34 < 0 )
goto V_79;
V_285:
V_34 = F_43 ( V_286 , V_3 , & V_11 , sizeof( V_11 ) ,
V_4 ? V_4 -> V_2 : NULL ) ;
V_79:
if ( V_4 )
F_36 ( V_4 ) ;
return V_34 ;
}
int F_121 ( T_1 V_3 , T_2 * V_229 , T_2 * V_230 ,
T_2 V_5 )
{
struct V_68 * V_4 ;
int V_34 ;
F_2 ( L_19 , V_3 , V_5 ) ;
V_4 = F_35 ( V_223 , V_3 ) ;
if ( ! V_4 )
return - V_135 ;
if ( V_5 ) {
V_34 = F_1 ( V_4 -> V_2 , V_3 , V_223 ,
V_270 ) ;
} else {
struct V_287 V_17 ;
memcpy ( V_17 . V_229 , V_229 , sizeof( V_17 . V_229 ) ) ;
memcpy ( V_17 . V_230 , V_230 , sizeof( V_17 . V_230 ) ) ;
V_34 = F_9 ( V_4 -> V_2 , V_3 , V_223 ,
& V_17 , sizeof( V_17 ) ) ;
}
F_36 ( V_4 ) ;
return V_34 ;
}
int F_122 ( T_1 V_3 , V_175 * V_60 , T_2 * V_62 , T_6 V_288 ,
T_2 * V_119 )
{
struct V_289 V_11 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
F_24 ( & V_11 . V_60 , V_60 ) ;
memcpy ( V_11 . V_62 , V_62 , sizeof( V_11 . V_62 ) ) ;
V_11 . V_288 = V_288 ;
if ( V_119 )
memcpy ( V_11 . V_119 , V_119 , sizeof( V_11 . V_119 ) ) ;
return F_43 ( V_290 , V_3 , & V_11 , sizeof( V_11 ) , NULL ) ;
}
int F_123 ( T_1 V_3 , V_175 * V_60 , T_2 * V_66 )
{
struct V_291 V_11 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
F_24 ( & V_11 . V_60 , V_60 ) ;
memcpy ( V_11 . V_66 , V_66 , V_284 ) ;
return F_43 ( V_292 , V_3 , & V_11 , sizeof( V_11 ) , NULL ) ;
}
int F_124 ( T_1 V_3 , T_2 V_293 )
{
return F_43 ( V_294 , V_3 , & V_293 ,
sizeof( V_293 ) , NULL ) ;
}
