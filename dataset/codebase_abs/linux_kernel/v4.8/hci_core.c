static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 3 ] ;
V_8 [ 0 ] = F_2 ( V_6 , V_9 ) ? 'Y' : 'N' ;
V_8 [ 1 ] = '\n' ;
V_8 [ 2 ] = '\0' ;
return F_3 ( V_2 , V_3 , V_4 , V_8 , 2 ) ;
}
static T_1 F_4 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_10 * V_11 ;
char V_8 [ 32 ] ;
T_3 V_12 = F_5 ( V_3 , ( sizeof( V_8 ) - 1 ) ) ;
bool V_13 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) )
return - V_16 ;
if ( F_7 ( V_8 , V_2 , V_12 ) )
return - V_17 ;
V_8 [ V_12 ] = '\0' ;
if ( F_8 ( V_8 , & V_13 ) )
return - V_18 ;
if ( V_13 == F_2 ( V_6 , V_9 ) )
return - V_19 ;
F_9 ( V_6 ) ;
if ( V_13 )
V_11 = F_10 ( V_6 , V_20 , 0 , NULL ,
V_21 ) ;
else
V_11 = F_10 ( V_6 , V_22 , 0 , NULL ,
V_21 ) ;
F_11 ( V_6 ) ;
if ( F_12 ( V_11 ) )
return F_13 ( V_11 ) ;
F_14 ( V_11 ) ;
F_15 ( V_6 , V_9 ) ;
return V_3 ;
}
static T_1 F_16 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 3 ] ;
V_8 [ 0 ] = F_2 ( V_6 , V_23 ) ? 'Y' : 'N' ;
V_8 [ 1 ] = '\n' ;
V_8 [ 2 ] = '\0' ;
return F_3 ( V_2 , V_3 , V_4 , V_8 , 2 ) ;
}
static T_1 F_17 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char V_8 [ 32 ] ;
T_3 V_12 = F_5 ( V_3 , ( sizeof( V_8 ) - 1 ) ) ;
bool V_13 ;
int V_24 ;
if ( F_7 ( V_8 , V_2 , V_12 ) )
return - V_17 ;
V_8 [ V_12 ] = '\0' ;
if ( F_8 ( V_8 , & V_13 ) )
return - V_18 ;
if ( F_6 ( V_25 , & V_6 -> V_26 ) &&
! F_6 ( V_27 , & V_6 -> V_15 ) )
goto V_28;
F_9 ( V_6 ) ;
V_24 = V_6 -> V_29 ( V_6 , V_13 ) ;
F_11 ( V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
V_28:
if ( V_13 )
F_18 ( V_6 , V_23 ) ;
else
F_19 ( V_6 , V_23 ) ;
return V_3 ;
}
static void F_20 ( struct V_5 * V_6 )
{
F_21 ( L_1 , 0644 , V_6 -> V_30 , V_6 ,
& V_31 ) ;
if ( V_6 -> V_29 )
F_21 ( L_2 , 0644 , V_6 -> V_30 , V_6 ,
& V_32 ) ;
}
static int F_22 ( struct V_33 * V_34 , unsigned long V_35 )
{
F_23 ( L_3 , V_34 -> V_6 -> V_36 , V_35 ) ;
F_24 ( V_37 , & V_34 -> V_6 -> V_15 ) ;
F_25 ( V_34 , V_22 , 0 , NULL ) ;
return 0 ;
}
static void F_26 ( struct V_33 * V_34 )
{
V_34 -> V_6 -> V_38 = V_39 ;
F_25 ( V_34 , V_40 , 0 , NULL ) ;
F_25 ( V_34 , V_41 , 0 , NULL ) ;
F_25 ( V_34 , V_42 , 0 , NULL ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
V_34 -> V_6 -> V_38 = V_43 ;
F_25 ( V_34 , V_41 , 0 , NULL ) ;
F_25 ( V_34 , V_44 , 0 , NULL ) ;
F_25 ( V_34 , V_45 , 0 , NULL ) ;
F_25 ( V_34 , V_46 , 0 , NULL ) ;
F_25 ( V_34 , V_47 , 0 , NULL ) ;
F_25 ( V_34 , V_48 , 0 , NULL ) ;
}
static int F_28 ( struct V_33 * V_34 )
{
if ( V_34 -> V_6 -> V_49 [ 14 ] & 0x20 )
F_25 ( V_34 , V_40 , 0 , NULL ) ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 , unsigned long V_35 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
F_23 ( L_3 , V_6 -> V_36 , V_35 ) ;
if ( ! F_6 ( V_50 , & V_6 -> V_26 ) )
F_22 ( V_34 , 0 ) ;
switch ( V_6 -> V_51 ) {
case V_52 :
F_26 ( V_34 ) ;
break;
case V_53 :
F_27 ( V_34 ) ;
break;
default:
F_30 ( L_4 , V_6 -> V_51 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_33 * V_34 )
{
T_5 V_54 ;
T_6 V_55 ;
F_25 ( V_34 , V_56 , 0 , NULL ) ;
F_25 ( V_34 , V_57 , 0 , NULL ) ;
F_25 ( V_34 , V_58 , 0 , NULL ) ;
F_25 ( V_34 , V_59 , 0 , NULL ) ;
F_25 ( V_34 , V_60 , 0 , NULL ) ;
F_25 ( V_34 , V_61 , 0 , NULL ) ;
V_55 = V_62 ;
F_25 ( V_34 , V_63 , 1 , & V_55 ) ;
V_54 = F_32 ( 0x7d00 ) ;
F_25 ( V_34 , V_64 , 2 , & V_54 ) ;
}
static void F_33 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
F_25 ( V_34 , V_65 , 0 , NULL ) ;
F_25 ( V_34 , V_66 , 0 , NULL ) ;
F_25 ( V_34 , V_67 , 0 , NULL ) ;
if ( ! F_34 ( V_6 ) )
F_18 ( V_6 , V_68 ) ;
}
static void F_35 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
T_7 V_69 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_6 -> V_70 < V_71 )
return;
if ( F_34 ( V_6 ) ) {
V_69 [ 4 ] |= 0x01 ;
} else {
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
V_69 [ 1 ] |= 0x20 ;
V_69 [ 1 ] |= 0x40 ;
V_69 [ 1 ] |= 0x80 ;
if ( V_6 -> V_49 [ 0 ] & 0x20 ) {
V_69 [ 0 ] |= 0x10 ;
V_69 [ 2 ] |= 0x04 ;
V_69 [ 3 ] |= 0x02 ;
}
if ( V_6 -> V_49 [ 2 ] & 0x80 )
V_69 [ 1 ] |= 0x08 ;
if ( V_6 -> V_72 [ 0 ] & V_73 ) {
V_69 [ 0 ] |= 0x80 ;
V_69 [ 5 ] |= 0x80 ;
}
}
if ( F_36 ( V_6 ) ||
F_6 ( V_74 , & V_6 -> V_26 ) )
V_69 [ 4 ] |= 0x02 ;
if ( F_37 ( V_6 ) )
V_69 [ 4 ] |= 0x04 ;
if ( F_38 ( V_6 ) ) {
V_69 [ 5 ] |= 0x08 ;
V_69 [ 5 ] |= 0x10 ;
}
if ( F_39 ( V_6 ) )
V_69 [ 5 ] |= 0x20 ;
if ( F_40 ( V_6 ) )
V_69 [ 5 ] |= 0x80 ;
if ( F_41 ( V_6 ) )
V_69 [ 5 ] |= 0x40 ;
if ( F_42 ( V_6 ) )
V_69 [ 7 ] |= 0x01 ;
if ( F_43 ( V_6 ) )
V_69 [ 6 ] |= 0x80 ;
if ( F_44 ( V_6 ) ) {
V_69 [ 6 ] |= 0x01 ;
V_69 [ 6 ] |= 0x02 ;
V_69 [ 6 ] |= 0x04 ;
V_69 [ 6 ] |= 0x08 ;
V_69 [ 6 ] |= 0x10 ;
V_69 [ 6 ] |= 0x20 ;
V_69 [ 7 ] |= 0x04 ;
V_69 [ 7 ] |= 0x08 ;
V_69 [ 7 ] |= 0x10 ;
}
if ( F_45 ( V_6 ) )
V_69 [ 7 ] |= 0x20 ;
F_25 ( V_34 , V_75 , sizeof( V_69 ) , V_69 ) ;
}
static int F_46 ( struct V_33 * V_34 , unsigned long V_35 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_6 -> V_51 == V_53 )
return F_28 ( V_34 ) ;
if ( F_34 ( V_6 ) )
F_31 ( V_34 ) ;
else
F_19 ( V_6 , V_76 ) ;
if ( F_45 ( V_6 ) )
F_33 ( V_34 ) ;
if ( V_6 -> V_70 > V_77 &&
! F_6 ( V_78 , & V_6 -> V_26 ) )
F_25 ( V_34 , V_44 , 0 , NULL ) ;
if ( F_44 ( V_6 ) ) {
V_6 -> V_79 = 0x01 ;
if ( F_2 ( V_6 , V_80 ) ) {
T_7 V_81 = 0x01 ;
F_25 ( V_34 , V_82 ,
sizeof( V_81 ) , & V_81 ) ;
} else {
struct V_83 V_84 ;
memset ( V_6 -> V_85 , 0 , sizeof( V_6 -> V_85 ) ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_25 ( V_34 , V_86 , sizeof( V_84 ) , & V_84 ) ;
}
}
if ( F_36 ( V_6 ) ||
F_6 ( V_74 , & V_6 -> V_26 ) ) {
T_7 V_81 ;
V_81 = F_41 ( V_6 ) ? 0x02 : 0x01 ;
F_25 ( V_34 , V_87 , 1 , & V_81 ) ;
}
if ( F_47 ( V_6 ) )
F_25 ( V_34 , V_88 , 0 , NULL ) ;
if ( F_37 ( V_6 ) ) {
struct V_89 V_84 ;
V_84 . V_90 = 0x01 ;
F_25 ( V_34 , V_91 ,
sizeof( V_84 ) , & V_84 ) ;
}
if ( F_2 ( V_6 , V_92 ) ) {
T_7 V_13 = 1 ;
F_25 ( V_34 , V_93 , sizeof( V_13 ) ,
& V_13 ) ;
}
return 0 ;
}
static void F_48 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_94 V_84 ;
T_8 V_95 = 0 ;
if ( F_49 ( V_6 ) )
V_95 |= V_96 ;
if ( F_50 ( V_6 ) )
V_95 |= V_97 ;
if ( F_51 ( V_6 ) )
V_95 |= V_98 ;
if ( F_52 ( V_6 ) )
V_95 |= V_99 ;
V_84 . V_100 = F_32 ( V_95 ) ;
F_25 ( V_34 , V_101 , sizeof( V_84 ) , & V_84 ) ;
}
static void F_53 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_102 V_84 ;
if ( ! F_34 ( V_6 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( F_2 ( V_6 , V_68 ) ) {
V_84 . V_103 = 0x01 ;
V_84 . V_104 = 0x00 ;
}
if ( V_84 . V_103 != F_54 ( V_6 ) )
F_25 ( V_34 , V_105 , sizeof( V_84 ) ,
& V_84 ) ;
}
static void F_55 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
T_7 V_69 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_56 ( V_6 ) ) {
V_69 [ 1 ] |= 0x40 ;
V_69 [ 1 ] |= 0x80 ;
V_69 [ 2 ] |= 0x10 ;
V_69 [ 2 ] |= 0x20 ;
}
if ( F_57 ( V_6 ) ) {
V_69 [ 2 ] |= 0x01 ;
V_69 [ 2 ] |= 0x02 ;
V_69 [ 2 ] |= 0x04 ;
V_69 [ 2 ] |= 0x08 ;
}
if ( F_58 ( V_6 ) || V_6 -> V_72 [ 0 ] & V_106 )
V_69 [ 2 ] |= 0x80 ;
F_25 ( V_34 , V_107 , sizeof( V_69 ) , V_69 ) ;
}
static int F_59 ( struct V_33 * V_34 , unsigned long V_35 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
T_7 V_108 ;
F_35 ( V_34 ) ;
if ( V_6 -> V_49 [ 6 ] & 0x20 &&
! F_6 ( V_109 , & V_6 -> V_26 ) ) {
struct V_110 V_84 ;
F_60 ( & V_84 . V_111 , V_112 ) ;
V_84 . V_113 = 0x01 ;
F_25 ( V_34 , V_114 , sizeof( V_84 ) , & V_84 ) ;
}
if ( V_6 -> V_49 [ 5 ] & 0x10 )
F_48 ( V_34 ) ;
if ( V_6 -> V_49 [ 8 ] & 0x01 )
F_25 ( V_34 , V_115 , 0 , NULL ) ;
if ( V_6 -> V_49 [ 13 ] & 0x01 )
F_25 ( V_34 , V_116 , 0 , NULL ) ;
if ( F_45 ( V_6 ) ) {
T_7 V_69 [ 8 ] ;
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_6 -> V_72 [ 0 ] & V_73 )
V_69 [ 0 ] |= 0x10 ;
if ( V_6 -> V_72 [ 0 ] & V_117 )
V_69 [ 0 ] |= 0x20 ;
if ( V_6 -> V_72 [ 0 ] & V_118 )
V_69 [ 0 ] |= 0x40 ;
if ( V_6 -> V_72 [ 0 ] & V_119 )
V_69 [ 1 ] |= 0x04 ;
if ( V_6 -> V_49 [ 26 ] & 0x08 )
V_69 [ 0 ] |= 0x02 ;
if ( V_6 -> V_49 [ 26 ] & 0x10 )
V_69 [ 0 ] |= 0x01 ;
if ( V_6 -> V_49 [ 27 ] & 0x04 )
V_69 [ 0 ] |= 0x04 ;
if ( V_6 -> V_49 [ 27 ] & 0x20 )
V_69 [ 0 ] |= 0x08 ;
if ( V_6 -> V_49 [ 34 ] & 0x02 )
V_69 [ 0 ] |= 0x80 ;
if ( V_6 -> V_49 [ 34 ] & 0x04 )
V_69 [ 1 ] |= 0x01 ;
F_25 ( V_34 , V_120 , sizeof( V_69 ) ,
V_69 ) ;
if ( V_6 -> V_49 [ 25 ] & 0x40 ) {
F_25 ( V_34 , V_121 , 0 , NULL ) ;
}
if ( V_6 -> V_49 [ 26 ] & 0x40 ) {
F_25 ( V_34 , V_122 ,
0 , NULL ) ;
}
if ( V_6 -> V_49 [ 26 ] & 0x80 ) {
F_25 ( V_34 , V_123 , 0 , NULL ) ;
}
if ( V_6 -> V_72 [ 0 ] & V_118 ) {
F_25 ( V_34 , V_124 , 0 , NULL ) ;
F_25 ( V_34 , V_125 , 0 , NULL ) ;
}
F_53 ( V_34 ) ;
}
for ( V_108 = 2 ; V_108 < V_126 && V_108 <= V_6 -> V_79 ; V_108 ++ ) {
struct V_89 V_84 ;
V_84 . V_90 = V_108 ;
F_25 ( V_34 , V_91 ,
sizeof( V_84 ) , & V_84 ) ;
}
return 0 ;
}
static int F_61 ( struct V_33 * V_34 , unsigned long V_35 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_6 -> V_49 [ 6 ] & 0x80 &&
! F_6 ( V_109 , & V_6 -> V_26 ) ) {
struct V_127 V_84 ;
F_60 ( & V_84 . V_111 , V_112 ) ;
V_84 . V_128 = 0x01 ;
F_25 ( V_34 , V_129 ,
sizeof( V_84 ) , & V_84 ) ;
}
if ( V_6 -> V_49 [ 22 ] & 0x04 )
F_55 ( V_34 ) ;
if ( V_6 -> V_49 [ 29 ] & 0x20 )
F_25 ( V_34 , V_130 , 0 , NULL ) ;
if ( V_6 -> V_49 [ 30 ] & 0x08 )
F_25 ( V_34 , V_131 , 0 , NULL ) ;
if ( F_62 ( V_6 ) )
F_25 ( V_34 , V_132 , 0 , NULL ) ;
if ( F_2 ( V_6 , V_80 ) &&
F_63 ( V_6 ) ) {
T_7 V_133 = 0x01 ;
F_25 ( V_34 , V_134 ,
sizeof( V_133 ) , & V_133 ) ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 )
{
int V_24 ;
V_24 = F_65 ( V_6 , F_29 , 0 , V_135 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_2 ( V_6 , V_136 ) )
F_20 ( V_6 ) ;
V_24 = F_65 ( V_6 , F_46 , 0 , V_135 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_6 -> V_51 != V_52 )
return 0 ;
V_24 = F_65 ( V_6 , F_59 , 0 , V_135 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_65 ( V_6 , F_61 , 0 , V_135 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! F_2 ( V_6 , V_136 ) &&
! F_2 ( V_6 , V_137 ) )
return 0 ;
F_66 ( V_6 ) ;
if ( F_34 ( V_6 ) )
F_67 ( V_6 ) ;
if ( F_45 ( V_6 ) )
F_68 ( V_6 ) ;
return 0 ;
}
static int F_69 ( struct V_33 * V_34 , unsigned long V_35 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
F_23 ( L_3 , V_6 -> V_36 , V_35 ) ;
if ( ! F_6 ( V_50 , & V_6 -> V_26 ) )
F_22 ( V_34 , 0 ) ;
F_25 ( V_34 , V_41 , 0 , NULL ) ;
if ( V_6 -> V_138 )
F_25 ( V_34 , V_42 , 0 , NULL ) ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 )
{
int V_24 ;
if ( F_6 ( V_139 , & V_6 -> V_26 ) )
return 0 ;
V_24 = F_65 ( V_6 , F_69 , 0 , V_135 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_2 ( V_6 , V_136 ) )
F_20 ( V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_33 * V_34 , unsigned long V_35 )
{
T_6 V_140 = V_35 ;
F_23 ( L_5 , V_34 -> V_6 -> V_36 , V_140 ) ;
F_25 ( V_34 , V_141 , 1 , & V_140 ) ;
return 0 ;
}
static int F_72 ( struct V_33 * V_34 , unsigned long V_35 )
{
T_6 V_142 = V_35 ;
F_23 ( L_5 , V_34 -> V_6 -> V_36 , V_142 ) ;
F_25 ( V_34 , V_93 , 1 , & V_142 ) ;
return 0 ;
}
static int F_73 ( struct V_33 * V_34 , unsigned long V_35 )
{
T_6 V_143 = V_35 ;
F_23 ( L_5 , V_34 -> V_6 -> V_36 , V_143 ) ;
F_25 ( V_34 , V_144 , 1 , & V_143 ) ;
return 0 ;
}
static int F_74 ( struct V_33 * V_34 , unsigned long V_35 )
{
T_5 V_100 = F_32 ( V_35 ) ;
F_23 ( L_5 , V_34 -> V_6 -> V_36 , V_100 ) ;
F_25 ( V_34 , V_101 , 2 , & V_100 ) ;
return 0 ;
}
struct V_5 * F_75 ( int V_145 )
{
struct V_5 * V_6 = NULL , * V_146 ;
F_23 ( L_6 , V_145 ) ;
if ( V_145 < 0 )
return NULL ;
F_76 ( & V_147 ) ;
F_77 (d, &hci_dev_list, list) {
if ( V_146 -> V_148 == V_145 ) {
V_6 = F_78 ( V_146 ) ;
break;
}
}
F_79 ( & V_147 ) ;
return V_6 ;
}
bool F_80 ( struct V_5 * V_6 )
{
struct V_149 * V_150 = & V_6 -> V_151 ;
switch ( V_150 -> V_152 ) {
case V_153 :
case V_154 :
return true ;
default:
return false ;
}
}
void F_81 ( struct V_5 * V_6 , int V_152 )
{
int V_155 = V_6 -> V_151 . V_152 ;
F_23 ( L_7 , V_6 -> V_36 , V_6 -> V_151 . V_152 , V_152 ) ;
if ( V_155 == V_152 )
return;
V_6 -> V_151 . V_152 = V_152 ;
switch ( V_152 ) {
case V_156 :
F_82 ( V_6 ) ;
if ( V_155 != V_157 )
F_83 ( V_6 , 0 ) ;
break;
case V_157 :
break;
case V_153 :
F_83 ( V_6 , 1 ) ;
break;
case V_154 :
break;
case V_158 :
break;
}
}
void F_84 ( struct V_5 * V_6 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_160 * V_108 , * V_161 ;
F_85 (p, n, &cache->all, all) {
F_86 ( & V_108 -> V_162 ) ;
F_87 ( V_108 ) ;
}
F_88 ( & V_159 -> V_163 ) ;
F_88 ( & V_159 -> V_164 ) ;
}
struct V_160 * F_89 ( struct V_5 * V_6 ,
T_9 * V_111 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_160 * V_165 ;
F_23 ( L_8 , V_159 , V_111 ) ;
F_77 (e, &cache->all, all) {
if ( ! F_90 ( & V_165 -> V_166 . V_111 , V_111 ) )
return V_165 ;
}
return NULL ;
}
struct V_160 * F_91 ( struct V_5 * V_6 ,
T_9 * V_111 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_160 * V_165 ;
F_23 ( L_8 , V_159 , V_111 ) ;
F_77 (e, &cache->unknown, list) {
if ( ! F_90 ( & V_165 -> V_166 . V_111 , V_111 ) )
return V_165 ;
}
return NULL ;
}
struct V_160 * F_92 ( struct V_5 * V_6 ,
T_9 * V_111 ,
int V_152 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_160 * V_165 ;
F_23 ( L_9 , V_159 , V_111 , V_152 ) ;
F_77 (e, &cache->resolve, list) {
if ( ! F_90 ( V_111 , V_112 ) && V_165 -> V_167 == V_152 )
return V_165 ;
if ( ! F_90 ( & V_165 -> V_166 . V_111 , V_111 ) )
return V_165 ;
}
return NULL ;
}
void F_93 ( struct V_5 * V_6 ,
struct V_160 * V_168 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_169 * V_170 = & V_159 -> V_164 ;
struct V_160 * V_108 ;
F_86 ( & V_168 -> V_171 ) ;
F_77 (p, &cache->resolve, list) {
if ( V_108 -> V_167 != V_172 &&
abs ( V_108 -> V_166 . V_173 ) >= abs ( V_168 -> V_166 . V_173 ) )
break;
V_170 = & V_108 -> V_171 ;
}
F_94 ( & V_168 -> V_171 , V_170 ) ;
}
T_10 F_95 ( struct V_5 * V_6 , struct V_174 * V_166 ,
bool V_175 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_160 * V_168 ;
T_10 V_15 = 0 ;
F_23 ( L_8 , V_159 , & V_166 -> V_111 ) ;
F_96 ( V_6 , & V_166 -> V_111 , V_176 ) ;
if ( ! V_166 -> V_177 )
V_15 |= V_178 ;
V_168 = F_89 ( V_6 , & V_166 -> V_111 ) ;
if ( V_168 ) {
if ( ! V_168 -> V_166 . V_177 )
V_15 |= V_178 ;
if ( V_168 -> V_167 == V_179 &&
V_166 -> V_173 != V_168 -> V_166 . V_173 ) {
V_168 -> V_166 . V_173 = V_166 -> V_173 ;
F_93 ( V_6 , V_168 ) ;
}
goto V_180;
}
V_168 = F_97 ( sizeof( * V_168 ) , V_181 ) ;
if ( ! V_168 ) {
V_15 |= V_182 ;
goto V_28;
}
F_94 ( & V_168 -> V_162 , & V_159 -> V_162 ) ;
if ( V_175 ) {
V_168 -> V_167 = V_183 ;
} else {
V_168 -> V_167 = V_184 ;
F_94 ( & V_168 -> V_171 , & V_159 -> V_163 ) ;
}
V_180:
if ( V_175 && V_168 -> V_167 != V_183 &&
V_168 -> V_167 != V_172 ) {
V_168 -> V_167 = V_183 ;
F_86 ( & V_168 -> V_171 ) ;
}
memcpy ( & V_168 -> V_166 , V_166 , sizeof( * V_166 ) ) ;
V_168 -> V_185 = V_186 ;
V_159 -> V_185 = V_186 ;
if ( V_168 -> V_167 == V_184 )
V_15 |= V_182 ;
V_28:
return V_15 ;
}
static int F_98 ( struct V_5 * V_6 , int V_187 , T_6 * V_8 )
{
struct V_149 * V_159 = & V_6 -> V_151 ;
struct V_188 * V_189 = (struct V_188 * ) V_8 ;
struct V_160 * V_165 ;
int V_190 = 0 ;
F_77 (e, &cache->all, all) {
struct V_174 * V_166 = & V_165 -> V_166 ;
if ( V_190 >= V_187 )
break;
F_60 ( & V_189 -> V_111 , & V_166 -> V_111 ) ;
V_189 -> V_191 = V_166 -> V_191 ;
V_189 -> V_192 = V_166 -> V_192 ;
V_189 -> V_193 = V_166 -> V_193 ;
memcpy ( V_189 -> V_194 , V_166 -> V_194 , 3 ) ;
V_189 -> V_195 = V_166 -> V_195 ;
V_189 ++ ;
V_190 ++ ;
}
F_23 ( L_10 , V_159 , V_190 ) ;
return V_190 ;
}
static int F_99 ( struct V_33 * V_34 , unsigned long V_35 )
{
struct V_196 * V_197 = (struct V_196 * ) V_35 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_198 V_84 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( F_6 ( V_199 , & V_6 -> V_15 ) )
return 0 ;
memcpy ( & V_84 . V_200 , & V_197 -> V_200 , 3 ) ;
V_84 . V_201 = V_197 -> V_201 ;
V_84 . V_202 = V_197 -> V_202 ;
F_25 ( V_34 , V_203 , sizeof( V_84 ) , & V_84 ) ;
return 0 ;
}
int F_100 ( void T_2 * V_204 )
{
T_6 T_2 * V_205 = V_204 ;
struct V_196 V_197 ;
struct V_5 * V_6 ;
int V_24 = 0 , V_206 = 0 , V_207 ;
long V_208 ;
T_6 * V_8 ;
if ( F_7 ( & V_197 , V_205 , sizeof( V_197 ) ) )
return - V_17 ;
V_6 = F_75 ( V_197 . V_209 ) ;
if ( ! V_6 )
return - V_210 ;
if ( F_2 ( V_6 , V_211 ) ) {
V_24 = - V_212 ;
goto V_28;
}
if ( F_2 ( V_6 , V_213 ) ) {
V_24 = - V_214 ;
goto V_28;
}
if ( V_6 -> V_51 != V_52 ) {
V_24 = - V_214 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_76 ) ) {
V_24 = - V_214 ;
goto V_28;
}
F_101 ( V_6 ) ;
if ( F_102 ( V_6 ) > V_215 ||
F_103 ( V_6 ) || V_197 . V_15 & V_216 ) {
F_84 ( V_6 ) ;
V_206 = 1 ;
}
F_104 ( V_6 ) ;
V_208 = V_197 . V_201 * F_105 ( 2000 ) ;
if ( V_206 ) {
V_24 = F_106 ( V_6 , F_99 , ( unsigned long ) & V_197 ,
V_208 , NULL ) ;
if ( V_24 < 0 )
goto V_28;
if ( F_107 ( & V_6 -> V_15 , V_199 ,
V_217 ) )
return - V_218 ;
}
V_207 = ( V_197 . V_202 == 0 ) ? 255 : V_197 . V_202 ;
V_8 = F_108 ( sizeof( struct V_188 ) * V_207 , V_181 ) ;
if ( ! V_8 ) {
V_24 = - V_219 ;
goto V_28;
}
F_101 ( V_6 ) ;
V_197 . V_202 = F_98 ( V_6 , V_207 , V_8 ) ;
F_104 ( V_6 ) ;
F_23 ( L_12 , V_197 . V_202 ) ;
if ( ! F_109 ( V_205 , & V_197 , sizeof( V_197 ) ) ) {
V_205 += sizeof( V_197 ) ;
if ( F_109 ( V_205 , V_8 , sizeof( struct V_188 ) *
V_197 . V_202 ) )
V_24 = - V_17 ;
} else
V_24 = - V_17 ;
F_87 ( V_8 ) ;
V_28:
F_110 ( V_6 ) ;
return V_24 ;
}
static int F_111 ( struct V_5 * V_6 )
{
int V_220 = 0 ;
F_23 ( L_13 , V_6 -> V_36 , V_6 ) ;
F_9 ( V_6 ) ;
if ( F_2 ( V_6 , V_221 ) ) {
V_220 = - V_210 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_136 ) &&
! F_2 ( V_6 , V_137 ) ) {
if ( F_2 ( V_6 , V_222 ) ) {
V_220 = - V_223 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_211 ) &&
V_6 -> V_51 == V_52 &&
! F_90 ( & V_6 -> V_111 , V_112 ) &&
! F_90 ( & V_6 -> V_224 , V_112 ) ) {
V_220 = - V_225 ;
goto V_28;
}
}
if ( F_6 ( V_14 , & V_6 -> V_15 ) ) {
V_220 = - V_19 ;
goto V_28;
}
if ( V_6 -> V_226 ( V_6 ) ) {
V_220 = - V_227 ;
goto V_28;
}
F_24 ( V_27 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_228 ) ;
F_113 ( & V_6 -> V_229 , 1 ) ;
F_24 ( V_230 , & V_6 -> V_15 ) ;
if ( F_2 ( V_6 , V_136 ) ) {
F_112 ( V_6 , V_231 ) ;
if ( V_6 -> V_232 )
V_220 = V_6 -> V_232 ( V_6 ) ;
if ( F_6 ( V_233 , & V_6 -> V_26 ) ||
F_6 ( V_234 , & V_6 -> V_26 ) )
F_18 ( V_6 , V_213 ) ;
if ( F_2 ( V_6 , V_213 ) )
V_220 = F_70 ( V_6 ) ;
}
if ( F_2 ( V_6 , V_137 ) ) {
if ( F_90 ( & V_6 -> V_235 , V_112 ) &&
V_6 -> V_138 )
V_220 = V_6 -> V_138 ( V_6 , & V_6 -> V_235 ) ;
else
V_220 = - V_225 ;
}
if ( ! V_220 ) {
if ( ! F_2 ( V_6 , V_213 ) &&
! F_2 ( V_6 , V_211 ) ) {
V_220 = F_64 ( V_6 ) ;
if ( ! V_220 && V_6 -> V_236 )
V_220 = V_6 -> V_236 ( V_6 ) ;
}
}
if ( F_6 ( V_25 , & V_6 -> V_26 ) &&
F_2 ( V_6 , V_23 ) && V_6 -> V_29 )
V_220 = V_6 -> V_29 ( V_6 , true ) ;
F_114 ( V_230 , & V_6 -> V_15 ) ;
if ( ! V_220 ) {
F_78 ( V_6 ) ;
F_18 ( V_6 , V_237 ) ;
F_24 ( V_14 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_238 ) ;
F_115 ( V_6 , true ) ;
if ( ! F_2 ( V_6 , V_136 ) &&
! F_2 ( V_6 , V_137 ) &&
! F_2 ( V_6 , V_213 ) &&
! F_2 ( V_6 , V_211 ) &&
F_2 ( V_6 , V_239 ) &&
V_6 -> V_51 == V_52 ) {
V_220 = F_116 ( V_6 ) ;
F_117 ( V_6 , V_220 ) ;
}
} else {
F_118 ( & V_6 -> V_240 ) ;
F_118 ( & V_6 -> V_241 ) ;
F_118 ( & V_6 -> V_242 ) ;
F_119 ( & V_6 -> V_243 ) ;
F_119 ( & V_6 -> V_244 ) ;
if ( V_6 -> V_245 )
V_6 -> V_245 ( V_6 ) ;
if ( V_6 -> V_246 ) {
F_14 ( V_6 -> V_246 ) ;
V_6 -> V_246 = NULL ;
}
F_114 ( V_27 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_247 ) ;
V_6 -> V_248 ( V_6 ) ;
V_6 -> V_15 &= F_120 ( V_249 ) ;
}
V_28:
F_11 ( V_6 ) ;
return V_220 ;
}
int F_121 ( T_11 V_250 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_75 ( V_250 ) ;
if ( ! V_6 )
return - V_210 ;
if ( F_2 ( V_6 , V_213 ) &&
! F_2 ( V_6 , V_211 ) ) {
V_24 = - V_214 ;
goto V_28;
}
if ( F_122 ( V_6 , V_251 ) )
F_123 ( & V_6 -> V_252 ) ;
F_124 ( V_6 -> V_253 ) ;
if ( ! F_2 ( V_6 , V_211 ) &&
! F_2 ( V_6 , V_239 ) )
F_18 ( V_6 , V_254 ) ;
V_24 = F_111 ( V_6 ) ;
V_28:
F_110 ( V_6 ) ;
return V_24 ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_255 * V_108 ;
F_77 (p, &hdev->le_conn_params, list) {
if ( V_108 -> V_256 ) {
F_126 ( V_108 -> V_256 ) ;
F_127 ( V_108 -> V_256 ) ;
V_108 -> V_256 = NULL ;
}
F_128 ( & V_108 -> V_257 ) ;
}
F_23 ( L_14 ) ;
}
int F_129 ( struct V_5 * V_6 )
{
bool V_258 ;
F_23 ( L_13 , V_6 -> V_36 , V_6 ) ;
if ( ! F_2 ( V_6 , V_221 ) &&
! F_2 ( V_6 , V_211 ) &&
F_6 ( V_14 , & V_6 -> V_15 ) ) {
if ( V_6 -> V_259 )
V_6 -> V_259 ( V_6 ) ;
}
F_123 ( & V_6 -> V_252 ) ;
F_130 ( V_6 ) ;
F_9 ( V_6 ) ;
if ( ! F_131 ( V_14 , & V_6 -> V_15 ) ) {
F_132 ( & V_6 -> V_260 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
F_115 ( V_6 , false ) ;
F_118 ( & V_6 -> V_240 ) ;
F_118 ( & V_6 -> V_242 ) ;
if ( V_6 -> V_261 > 0 ) {
V_6 -> V_261 = 0 ;
F_19 ( V_6 , V_262 ) ;
F_19 ( V_6 , V_263 ) ;
}
if ( F_122 ( V_6 , V_264 ) )
F_123 ( & V_6 -> V_265 ) ;
if ( F_2 ( V_6 , V_239 ) )
F_132 ( & V_6 -> V_266 ) ;
F_133 ( V_6 -> V_267 ) ;
F_101 ( V_6 ) ;
F_81 ( V_6 , V_156 ) ;
V_258 = F_122 ( V_6 , V_251 ) ;
if ( ! V_258 && V_6 -> V_51 == V_52 &&
F_2 ( V_6 , V_239 ) )
F_134 ( V_6 ) ;
F_84 ( V_6 ) ;
F_125 ( V_6 ) ;
F_135 ( V_6 ) ;
F_104 ( V_6 ) ;
F_136 ( V_6 ) ;
F_112 ( V_6 , V_268 ) ;
if ( V_6 -> V_245 )
V_6 -> V_245 ( V_6 ) ;
F_119 ( & V_6 -> V_243 ) ;
F_113 ( & V_6 -> V_229 , 1 ) ;
if ( F_6 ( V_50 , & V_6 -> V_26 ) &&
! V_258 && ! F_2 ( V_6 , V_213 ) ) {
F_24 ( V_230 , & V_6 -> V_15 ) ;
F_65 ( V_6 , F_22 , 0 , V_21 , NULL ) ;
F_114 ( V_230 , & V_6 -> V_15 ) ;
}
F_118 ( & V_6 -> V_241 ) ;
F_119 ( & V_6 -> V_244 ) ;
F_119 ( & V_6 -> V_243 ) ;
F_119 ( & V_6 -> V_269 ) ;
if ( V_6 -> V_246 ) {
F_132 ( & V_6 -> V_260 ) ;
F_14 ( V_6 -> V_246 ) ;
V_6 -> V_246 = NULL ;
}
F_114 ( V_27 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_247 ) ;
V_6 -> V_248 ( V_6 ) ;
V_6 -> V_15 &= F_120 ( V_249 ) ;
F_137 ( V_6 ) ;
V_6 -> V_270 = V_271 ;
memset ( V_6 -> V_85 , 0 , sizeof( V_6 -> V_85 ) ) ;
memset ( V_6 -> V_194 , 0 , sizeof( V_6 -> V_194 ) ) ;
F_60 ( & V_6 -> V_272 , V_112 ) ;
F_11 ( V_6 ) ;
F_110 ( V_6 ) ;
return 0 ;
}
int F_138 ( T_11 V_250 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_75 ( V_250 ) ;
if ( ! V_6 )
return - V_210 ;
if ( F_2 ( V_6 , V_211 ) ) {
V_24 = - V_212 ;
goto V_28;
}
if ( F_122 ( V_6 , V_251 ) )
F_123 ( & V_6 -> V_252 ) ;
V_24 = F_129 ( V_6 ) ;
V_28:
F_110 ( V_6 ) ;
return V_24 ;
}
static int F_139 ( struct V_5 * V_6 )
{
int V_220 ;
F_23 ( L_13 , V_6 -> V_36 , V_6 ) ;
F_9 ( V_6 ) ;
F_119 ( & V_6 -> V_244 ) ;
F_119 ( & V_6 -> V_243 ) ;
F_133 ( V_6 -> V_267 ) ;
F_101 ( V_6 ) ;
F_84 ( V_6 ) ;
F_135 ( V_6 ) ;
F_104 ( V_6 ) ;
if ( V_6 -> V_245 )
V_6 -> V_245 ( V_6 ) ;
F_113 ( & V_6 -> V_229 , 1 ) ;
V_6 -> V_273 = 0 ; V_6 -> V_274 = 0 ; V_6 -> V_275 = 0 ;
V_220 = F_65 ( V_6 , F_22 , 0 , V_135 , NULL ) ;
F_11 ( V_6 ) ;
return V_220 ;
}
int F_140 ( T_11 V_250 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_75 ( V_250 ) ;
if ( ! V_6 )
return - V_210 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) ) {
V_24 = - V_16 ;
goto V_28;
}
if ( F_2 ( V_6 , V_211 ) ) {
V_24 = - V_212 ;
goto V_28;
}
if ( F_2 ( V_6 , V_213 ) ) {
V_24 = - V_214 ;
goto V_28;
}
V_24 = F_139 ( V_6 ) ;
V_28:
F_110 ( V_6 ) ;
return V_24 ;
}
int F_141 ( T_11 V_250 )
{
struct V_5 * V_6 ;
int V_220 = 0 ;
V_6 = F_75 ( V_250 ) ;
if ( ! V_6 )
return - V_210 ;
if ( F_2 ( V_6 , V_211 ) ) {
V_220 = - V_212 ;
goto V_28;
}
if ( F_2 ( V_6 , V_213 ) ) {
V_220 = - V_214 ;
goto V_28;
}
memset ( & V_6 -> V_276 , 0 , sizeof( struct V_277 ) ) ;
V_28:
F_110 ( V_6 ) ;
return V_220 ;
}
static void F_142 ( struct V_5 * V_6 , T_7 V_140 )
{
bool V_278 , V_279 ;
F_23 ( L_15 , V_6 -> V_36 , V_140 ) ;
if ( ( V_140 & V_280 ) )
V_278 = ! F_143 ( V_6 ,
V_281 ) ;
else
V_278 = F_122 ( V_6 ,
V_281 ) ;
if ( ( V_140 & V_282 ) ) {
V_279 = ! F_143 ( V_6 ,
V_262 ) ;
} else {
F_19 ( V_6 , V_263 ) ;
V_279 = F_122 ( V_6 ,
V_262 ) ;
}
if ( ! F_2 ( V_6 , V_239 ) )
return;
if ( V_278 || V_279 ) {
F_18 ( V_6 , V_76 ) ;
if ( F_2 ( V_6 , V_68 ) )
F_144 ( V_6 , V_6 -> V_283 ) ;
F_145 ( V_6 ) ;
}
}
int F_146 ( unsigned int V_284 , void T_2 * V_204 )
{
struct V_5 * V_6 ;
struct V_285 V_286 ;
int V_24 = 0 ;
if ( F_7 ( & V_286 , V_204 , sizeof( V_286 ) ) )
return - V_17 ;
V_6 = F_75 ( V_286 . V_209 ) ;
if ( ! V_6 )
return - V_210 ;
if ( F_2 ( V_6 , V_211 ) ) {
V_24 = - V_212 ;
goto V_28;
}
if ( F_2 ( V_6 , V_213 ) ) {
V_24 = - V_214 ;
goto V_28;
}
if ( V_6 -> V_51 != V_52 ) {
V_24 = - V_214 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_76 ) ) {
V_24 = - V_214 ;
goto V_28;
}
switch ( V_284 ) {
case V_287 :
V_24 = F_106 ( V_6 , F_72 , V_286 . V_288 ,
V_135 , NULL ) ;
break;
case V_289 :
if ( ! F_147 ( V_6 ) ) {
V_24 = - V_214 ;
break;
}
if ( ! F_6 ( V_290 , & V_6 -> V_15 ) ) {
V_24 = F_106 ( V_6 , F_72 , V_286 . V_288 ,
V_135 , NULL ) ;
if ( V_24 )
break;
}
V_24 = F_106 ( V_6 , F_73 , V_286 . V_288 ,
V_135 , NULL ) ;
break;
case V_291 :
V_24 = F_106 ( V_6 , F_71 , V_286 . V_288 ,
V_135 , NULL ) ;
if ( ! V_24 )
F_142 ( V_6 , V_286 . V_288 ) ;
break;
case V_292 :
V_24 = F_106 ( V_6 , F_74 , V_286 . V_288 ,
V_135 , NULL ) ;
break;
case V_293 :
V_6 -> V_294 = ( ( T_11 ) V_286 . V_288 ) &
( V_295 | V_296 ) ;
break;
case V_297 :
V_6 -> V_298 = ( T_11 ) V_286 . V_288 ;
break;
case V_299 :
V_6 -> V_300 = * ( ( T_11 * ) & V_286 . V_288 + 1 ) ;
V_6 -> V_301 = * ( ( T_11 * ) & V_286 . V_288 + 0 ) ;
break;
case V_302 :
V_6 -> V_303 = * ( ( T_11 * ) & V_286 . V_288 + 1 ) ;
V_6 -> V_304 = * ( ( T_11 * ) & V_286 . V_288 + 0 ) ;
break;
default:
V_24 = - V_18 ;
break;
}
V_28:
F_110 ( V_6 ) ;
return V_24 ;
}
int F_148 ( void T_2 * V_204 )
{
struct V_5 * V_6 ;
struct V_305 * V_306 ;
struct V_285 * V_286 ;
int V_161 = 0 , V_307 , V_24 ;
T_11 V_308 ;
if ( F_149 ( V_308 , ( T_11 T_2 * ) V_204 ) )
return - V_17 ;
if ( ! V_308 || V_308 > ( V_309 * 2 ) / sizeof( * V_286 ) )
return - V_18 ;
V_307 = sizeof( * V_306 ) + V_308 * sizeof( * V_286 ) ;
V_306 = F_97 ( V_307 , V_181 ) ;
if ( ! V_306 )
return - V_219 ;
V_286 = V_306 -> V_310 ;
F_76 ( & V_147 ) ;
F_77 (hdev, &hci_dev_list, list) {
unsigned long V_15 = V_6 -> V_15 ;
if ( F_2 ( V_6 , V_251 ) )
V_15 &= ~ F_120 ( V_14 ) ;
( V_286 + V_161 ) -> V_209 = V_6 -> V_148 ;
( V_286 + V_161 ) -> V_288 = V_15 ;
if ( ++ V_161 >= V_308 )
break;
}
F_79 ( & V_147 ) ;
V_306 -> V_308 = V_161 ;
V_307 = sizeof( * V_306 ) + V_161 * sizeof( * V_286 ) ;
V_24 = F_109 ( V_204 , V_306 , V_307 ) ;
F_87 ( V_306 ) ;
return V_24 ? - V_17 : 0 ;
}
int F_150 ( void T_2 * V_204 )
{
struct V_5 * V_6 ;
struct V_311 V_312 ;
unsigned long V_15 ;
int V_24 = 0 ;
if ( F_7 ( & V_312 , V_204 , sizeof( V_312 ) ) )
return - V_17 ;
V_6 = F_75 ( V_312 . V_209 ) ;
if ( ! V_6 )
return - V_210 ;
if ( F_2 ( V_6 , V_251 ) )
V_15 = V_6 -> V_15 & ~ F_120 ( V_14 ) ;
else
V_15 = V_6 -> V_15 ;
strcpy ( V_312 . V_36 , V_6 -> V_36 ) ;
V_312 . V_111 = V_6 -> V_111 ;
V_312 . type = ( V_6 -> V_313 & 0x0f ) | ( ( V_6 -> V_51 & 0x03 ) << 4 ) ;
V_312 . V_15 = V_15 ;
V_312 . V_298 = V_6 -> V_298 ;
if ( F_34 ( V_6 ) ) {
V_312 . V_300 = V_6 -> V_300 ;
V_312 . V_301 = V_6 -> V_301 ;
V_312 . V_303 = V_6 -> V_303 ;
V_312 . V_304 = V_6 -> V_304 ;
} else {
V_312 . V_300 = V_6 -> V_314 ;
V_312 . V_301 = V_6 -> V_315 ;
V_312 . V_303 = 0 ;
V_312 . V_304 = 0 ;
}
V_312 . V_95 = V_6 -> V_95 ;
V_312 . V_294 = V_6 -> V_294 ;
memcpy ( & V_312 . V_276 , & V_6 -> V_276 , sizeof( V_312 . V_276 ) ) ;
memcpy ( & V_312 . V_316 , & V_6 -> V_316 , sizeof( V_312 . V_316 ) ) ;
if ( F_109 ( V_204 , & V_312 , sizeof( V_312 ) ) )
V_24 = - V_17 ;
F_110 ( V_6 ) ;
return V_24 ;
}
static int F_151 ( void * V_166 , bool V_317 )
{
struct V_5 * V_6 = V_166 ;
F_23 ( L_16 , V_6 , V_6 -> V_36 , V_317 ) ;
if ( F_2 ( V_6 , V_211 ) )
return - V_212 ;
if ( V_317 ) {
F_18 ( V_6 , V_222 ) ;
if ( ! F_2 ( V_6 , V_136 ) &&
! F_2 ( V_6 , V_137 ) )
F_129 ( V_6 ) ;
} else {
F_19 ( V_6 , V_222 ) ;
}
return 0 ;
}
static void F_152 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 , V_320 ) ;
int V_24 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( F_6 ( V_14 , & V_6 -> V_15 ) &&
F_2 ( V_6 , V_239 ) &&
F_122 ( V_6 , V_251 ) ) {
F_123 ( & V_6 -> V_252 ) ;
F_9 ( V_6 ) ;
V_24 = F_116 ( V_6 ) ;
F_11 ( V_6 ) ;
F_117 ( V_6 , V_24 ) ;
return;
}
V_24 = F_111 ( V_6 ) ;
if ( V_24 < 0 ) {
F_101 ( V_6 ) ;
F_154 ( V_6 , V_24 ) ;
F_104 ( V_6 ) ;
return;
}
if ( F_2 ( V_6 , V_222 ) ||
F_2 ( V_6 , V_213 ) ||
( V_6 -> V_51 == V_52 &&
! F_90 ( & V_6 -> V_111 , V_112 ) &&
! F_90 ( & V_6 -> V_224 , V_112 ) ) ) {
F_19 ( V_6 , V_251 ) ;
F_129 ( V_6 ) ;
} else if ( F_2 ( V_6 , V_251 ) ) {
F_155 ( V_6 -> V_253 , & V_6 -> V_252 ,
V_321 ) ;
}
if ( F_122 ( V_6 , V_136 ) ) {
if ( F_2 ( V_6 , V_213 ) )
F_24 ( V_249 , & V_6 -> V_15 ) ;
F_156 ( V_6 ) ;
} else if ( F_122 ( V_6 , V_137 ) ) {
if ( ! F_2 ( V_6 , V_213 ) )
F_114 ( V_249 , & V_6 -> V_15 ) ;
F_156 ( V_6 ) ;
}
}
static void F_157 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 ,
V_252 . V_319 ) ;
F_23 ( L_11 , V_6 -> V_36 ) ;
F_129 ( V_6 ) ;
}
static void F_158 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 , V_322 ) ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( V_6 -> V_323 )
V_6 -> V_323 ( V_6 , V_6 -> V_324 ) ;
else
F_30 ( L_17 , V_6 -> V_36 ,
V_6 -> V_324 ) ;
if ( F_129 ( V_6 ) )
return;
F_111 ( V_6 ) ;
}
void F_159 ( struct V_5 * V_6 )
{
struct V_325 * V_326 , * V_327 ;
F_85 (uuid, tmp, &hdev->uuids, list) {
F_86 ( & V_326 -> V_171 ) ;
F_87 ( V_326 ) ;
}
}
void F_160 ( struct V_5 * V_6 )
{
struct V_328 * V_329 ;
F_161 (key, &hdev->link_keys, list) {
F_162 ( & V_329 -> V_171 ) ;
F_163 ( V_329 , V_330 ) ;
}
}
void F_164 ( struct V_5 * V_6 )
{
struct V_331 * V_332 ;
F_161 (k, &hdev->long_term_keys, list) {
F_162 ( & V_332 -> V_171 ) ;
F_163 ( V_332 , V_330 ) ;
}
}
void F_165 ( struct V_5 * V_6 )
{
struct V_333 * V_332 ;
F_161 (k, &hdev->identity_resolving_keys, list) {
F_162 ( & V_332 -> V_171 ) ;
F_163 ( V_332 , V_330 ) ;
}
}
struct V_328 * F_166 ( struct V_5 * V_6 , T_9 * V_111 )
{
struct V_328 * V_332 ;
F_167 () ;
F_161 (k, &hdev->link_keys, list) {
if ( F_90 ( V_111 , & V_332 -> V_111 ) == 0 ) {
F_168 () ;
return V_332 ;
}
}
F_168 () ;
return NULL ;
}
static bool F_169 ( struct V_5 * V_6 , struct V_334 * V_256 ,
T_7 V_335 , T_7 V_336 )
{
if ( V_335 < 0x03 )
return true ;
if ( V_335 == V_337 )
return false ;
if ( V_335 == V_338 && V_336 == 0xff )
return false ;
if ( ! V_256 )
return true ;
if ( V_256 -> type == V_339 )
return true ;
if ( V_256 -> V_340 > 0x01 && V_256 -> V_341 > 0x01 )
return true ;
if ( V_256 -> V_340 == 0x02 || V_256 -> V_340 == 0x03 )
return true ;
if ( V_256 -> V_341 == 0x02 || V_256 -> V_341 == 0x03 )
return true ;
return false ;
}
static T_7 F_170 ( T_7 type )
{
if ( type == V_342 )
return V_343 ;
return V_344 ;
}
struct V_331 * F_171 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 V_345 , T_7 V_346 )
{
struct V_331 * V_332 ;
F_167 () ;
F_161 (k, &hdev->long_term_keys, list) {
if ( V_345 != V_332 -> V_347 || F_90 ( V_111 , & V_332 -> V_111 ) )
continue;
if ( F_172 ( V_332 ) || F_170 ( V_332 -> type ) == V_346 ) {
F_168 () ;
return V_332 ;
}
}
F_168 () ;
return NULL ;
}
struct V_333 * F_173 ( struct V_5 * V_6 , T_9 * V_348 )
{
struct V_333 * V_349 ;
F_167 () ;
F_161 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_90 ( & V_349 -> V_348 , V_348 ) ) {
F_168 () ;
return V_349 ;
}
}
F_161 (irk, &hdev->identity_resolving_keys, list) {
if ( F_174 ( V_6 , V_349 -> V_350 , V_348 ) ) {
F_60 ( & V_349 -> V_348 , V_348 ) ;
F_168 () ;
return V_349 ;
}
}
F_168 () ;
return NULL ;
}
struct V_333 * F_175 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 V_345 )
{
struct V_333 * V_349 ;
if ( V_345 == V_351 && ( V_111 -> V_352 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_167 () ;
F_161 (irk, &hdev->identity_resolving_keys, list) {
if ( V_345 == V_349 -> V_345 &&
F_90 ( V_111 , & V_349 -> V_111 ) == 0 ) {
F_168 () ;
return V_349 ;
}
}
F_168 () ;
return NULL ;
}
struct V_328 * F_176 ( struct V_5 * V_6 , struct V_334 * V_256 ,
T_9 * V_111 , T_7 * V_350 , T_7 type ,
T_7 V_353 , bool * V_354 )
{
struct V_328 * V_329 , * V_355 ;
T_7 V_336 ;
V_355 = F_166 ( V_6 , V_111 ) ;
if ( V_355 ) {
V_336 = V_355 -> type ;
V_329 = V_355 ;
} else {
V_336 = V_256 ? V_256 -> V_335 : 0xff ;
V_329 = F_97 ( sizeof( * V_329 ) , V_181 ) ;
if ( ! V_329 )
return NULL ;
F_177 ( & V_329 -> V_171 , & V_6 -> V_356 ) ;
}
F_23 ( L_18 , V_6 -> V_36 , V_111 , type ) ;
if ( type == V_338 &&
( ! V_256 || V_256 -> V_341 == 0xff ) && V_336 == 0xff ) {
type = V_357 ;
if ( V_256 )
V_256 -> V_335 = type ;
}
F_60 ( & V_329 -> V_111 , V_111 ) ;
memcpy ( V_329 -> V_350 , V_350 , V_358 ) ;
V_329 -> V_353 = V_353 ;
if ( type == V_338 )
V_329 -> type = V_336 ;
else
V_329 -> type = type ;
if ( V_354 )
* V_354 = F_169 ( V_6 , V_256 , type ,
V_336 ) ;
return V_329 ;
}
struct V_331 * F_178 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 V_345 , T_7 type , T_7 V_359 ,
T_7 V_360 [ 16 ] , T_7 V_361 , T_5 V_362 , T_12 rand )
{
struct V_331 * V_329 , * V_355 ;
T_7 V_346 = F_170 ( type ) ;
V_355 = F_171 ( V_6 , V_111 , V_345 , V_346 ) ;
if ( V_355 )
V_329 = V_355 ;
else {
V_329 = F_97 ( sizeof( * V_329 ) , V_181 ) ;
if ( ! V_329 )
return NULL ;
F_177 ( & V_329 -> V_171 , & V_6 -> V_363 ) ;
}
F_60 ( & V_329 -> V_111 , V_111 ) ;
V_329 -> V_347 = V_345 ;
memcpy ( V_329 -> V_350 , V_360 , sizeof( V_329 -> V_350 ) ) ;
V_329 -> V_359 = V_359 ;
V_329 -> V_362 = V_362 ;
V_329 -> rand = rand ;
V_329 -> V_361 = V_361 ;
V_329 -> type = type ;
return V_329 ;
}
struct V_333 * F_179 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 V_345 , T_7 V_350 [ 16 ] , T_9 * V_348 )
{
struct V_333 * V_349 ;
V_349 = F_175 ( V_6 , V_111 , V_345 ) ;
if ( ! V_349 ) {
V_349 = F_97 ( sizeof( * V_349 ) , V_181 ) ;
if ( ! V_349 )
return NULL ;
F_60 ( & V_349 -> V_111 , V_111 ) ;
V_349 -> V_345 = V_345 ;
F_177 ( & V_349 -> V_171 , & V_6 -> V_364 ) ;
}
memcpy ( V_349 -> V_350 , V_350 , 16 ) ;
F_60 ( & V_349 -> V_348 , V_348 ) ;
return V_349 ;
}
int F_180 ( struct V_5 * V_6 , T_9 * V_111 )
{
struct V_328 * V_329 ;
V_329 = F_166 ( V_6 , V_111 ) ;
if ( ! V_329 )
return - V_365 ;
F_23 ( L_19 , V_6 -> V_36 , V_111 ) ;
F_162 ( & V_329 -> V_171 ) ;
F_163 ( V_329 , V_330 ) ;
return 0 ;
}
int F_181 ( struct V_5 * V_6 , T_9 * V_111 , T_7 V_347 )
{
struct V_331 * V_332 ;
int V_366 = 0 ;
F_161 (k, &hdev->long_term_keys, list) {
if ( F_90 ( V_111 , & V_332 -> V_111 ) || V_332 -> V_347 != V_347 )
continue;
F_23 ( L_19 , V_6 -> V_36 , V_111 ) ;
F_162 ( & V_332 -> V_171 ) ;
F_163 ( V_332 , V_330 ) ;
V_366 ++ ;
}
return V_366 ? 0 : - V_365 ;
}
void F_182 ( struct V_5 * V_6 , T_9 * V_111 , T_7 V_345 )
{
struct V_333 * V_332 ;
F_161 (k, &hdev->identity_resolving_keys, list) {
if ( F_90 ( V_111 , & V_332 -> V_111 ) || V_332 -> V_345 != V_345 )
continue;
F_23 ( L_19 , V_6 -> V_36 , V_111 ) ;
F_162 ( & V_332 -> V_171 ) ;
F_163 ( V_332 , V_330 ) ;
}
}
bool F_183 ( struct V_5 * V_6 , T_9 * V_111 , T_7 type )
{
struct V_331 * V_332 ;
struct V_333 * V_349 ;
T_7 V_345 ;
if ( type == V_176 ) {
if ( F_166 ( V_6 , V_111 ) )
return true ;
return false ;
}
if ( type == V_367 )
V_345 = V_368 ;
else
V_345 = V_351 ;
V_349 = F_184 ( V_6 , V_111 , V_345 ) ;
if ( V_349 ) {
V_111 = & V_349 -> V_111 ;
V_345 = V_349 -> V_345 ;
}
F_167 () ;
F_161 (k, &hdev->long_term_keys, list) {
if ( V_332 -> V_347 == V_345 && ! F_90 ( V_111 , & V_332 -> V_111 ) ) {
F_168 () ;
return true ;
}
}
F_168 () ;
return false ;
}
static void F_185 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 ,
V_260 . V_319 ) ;
if ( V_6 -> V_246 ) {
struct V_369 * V_370 = ( void * ) V_6 -> V_246 -> V_166 ;
T_8 V_371 = F_186 ( V_370 -> V_371 ) ;
F_30 ( L_20 , V_6 -> V_36 , V_371 ) ;
} else {
F_30 ( L_21 , V_6 -> V_36 ) ;
}
F_113 ( & V_6 -> V_229 , 1 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_241 ) ;
}
struct V_372 * F_188 ( struct V_5 * V_6 ,
T_9 * V_111 , T_7 V_347 )
{
struct V_372 * V_166 ;
F_77 (data, &hdev->remote_oob_data, list) {
if ( F_90 ( V_111 , & V_166 -> V_111 ) != 0 )
continue;
if ( V_166 -> V_347 != V_347 )
continue;
return V_166 ;
}
return NULL ;
}
int F_96 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 V_347 )
{
struct V_372 * V_166 ;
V_166 = F_188 ( V_6 , V_111 , V_347 ) ;
if ( ! V_166 )
return - V_365 ;
F_23 ( L_22 , V_6 -> V_36 , V_111 , V_347 ) ;
F_86 ( & V_166 -> V_171 ) ;
F_87 ( V_166 ) ;
return 0 ;
}
void F_189 ( struct V_5 * V_6 )
{
struct V_372 * V_166 , * V_161 ;
F_85 (data, n, &hdev->remote_oob_data, list) {
F_86 ( & V_166 -> V_171 ) ;
F_87 ( V_166 ) ;
}
}
int F_190 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 V_347 , T_7 * V_373 , T_7 * V_374 ,
T_7 * V_375 , T_7 * V_376 )
{
struct V_372 * V_166 ;
V_166 = F_188 ( V_6 , V_111 , V_347 ) ;
if ( ! V_166 ) {
V_166 = F_108 ( sizeof( * V_166 ) , V_181 ) ;
if ( ! V_166 )
return - V_219 ;
F_60 ( & V_166 -> V_111 , V_111 ) ;
V_166 -> V_347 = V_347 ;
F_94 ( & V_166 -> V_171 , & V_6 -> V_377 ) ;
}
if ( V_373 && V_374 ) {
memcpy ( V_166 -> V_373 , V_373 , sizeof( V_166 -> V_373 ) ) ;
memcpy ( V_166 -> V_374 , V_374 , sizeof( V_166 -> V_374 ) ) ;
if ( V_375 && V_376 )
V_166 -> V_378 = 0x03 ;
} else {
memset ( V_166 -> V_373 , 0 , sizeof( V_166 -> V_373 ) ) ;
memset ( V_166 -> V_374 , 0 , sizeof( V_166 -> V_374 ) ) ;
if ( V_375 && V_376 )
V_166 -> V_378 = 0x02 ;
else
V_166 -> V_378 = 0x00 ;
}
if ( V_375 && V_376 ) {
memcpy ( V_166 -> V_375 , V_375 , sizeof( V_166 -> V_375 ) ) ;
memcpy ( V_166 -> V_376 , V_376 , sizeof( V_166 -> V_376 ) ) ;
} else {
memset ( V_166 -> V_375 , 0 , sizeof( V_166 -> V_375 ) ) ;
memset ( V_166 -> V_376 , 0 , sizeof( V_166 -> V_376 ) ) ;
if ( V_373 && V_374 )
V_166 -> V_378 = 0x01 ;
}
F_23 ( L_23 , V_6 -> V_36 , V_111 ) ;
return 0 ;
}
struct V_379 * F_191 ( struct V_5 * V_6 , T_7 V_380 )
{
struct V_379 * V_381 ;
F_77 (adv_instance, &hdev->adv_instances, list) {
if ( V_381 -> V_380 == V_380 )
return V_381 ;
}
return NULL ;
}
struct V_379 * F_192 ( struct V_5 * V_6 , T_7 V_380 )
{
struct V_379 * V_382 ;
V_382 = F_191 ( V_6 , V_380 ) ;
if ( ! V_382 )
return NULL ;
if ( V_382 == F_193 ( & V_6 -> V_383 ,
struct V_379 , V_171 ) )
return F_194 ( & V_6 -> V_383 ,
struct V_379 , V_171 ) ;
else
return F_195 ( V_382 , V_171 ) ;
}
int F_196 ( struct V_5 * V_6 , T_7 V_380 )
{
struct V_379 * V_381 ;
V_381 = F_191 ( V_6 , V_380 ) ;
if ( ! V_381 )
return - V_365 ;
F_23 ( L_24 , V_6 -> V_36 , V_380 ) ;
if ( V_6 -> V_283 == V_380 ) {
if ( V_6 -> V_384 ) {
F_123 ( & V_6 -> V_385 ) ;
V_6 -> V_384 = 0 ;
}
V_6 -> V_283 = 0x00 ;
}
F_86 ( & V_381 -> V_171 ) ;
F_87 ( V_381 ) ;
V_6 -> V_386 -- ;
return 0 ;
}
void F_197 ( struct V_5 * V_6 )
{
struct V_379 * V_381 , * V_161 ;
if ( V_6 -> V_384 ) {
F_123 ( & V_6 -> V_385 ) ;
V_6 -> V_384 = 0 ;
}
F_85 (adv_instance, n, &hdev->adv_instances, list) {
F_86 ( & V_381 -> V_171 ) ;
F_87 ( V_381 ) ;
}
V_6 -> V_386 = 0 ;
V_6 -> V_283 = 0x00 ;
}
int F_198 ( struct V_5 * V_6 , T_7 V_380 , T_10 V_15 ,
T_8 V_387 , T_7 * V_388 ,
T_8 V_389 , T_7 * V_390 ,
T_8 V_391 , T_8 V_392 )
{
struct V_379 * V_381 ;
V_381 = F_191 ( V_6 , V_380 ) ;
if ( V_381 ) {
memset ( V_381 -> V_388 , 0 ,
sizeof( V_381 -> V_388 ) ) ;
memset ( V_381 -> V_390 , 0 ,
sizeof( V_381 -> V_390 ) ) ;
} else {
if ( V_6 -> V_386 >= V_393 ||
V_380 < 1 || V_380 > V_393 )
return - V_394 ;
V_381 = F_97 ( sizeof( * V_381 ) , V_181 ) ;
if ( ! V_381 )
return - V_219 ;
V_381 -> V_395 = true ;
V_381 -> V_380 = V_380 ;
F_94 ( & V_381 -> V_171 , & V_6 -> V_383 ) ;
V_6 -> V_386 ++ ;
}
V_381 -> V_15 = V_15 ;
V_381 -> V_387 = V_387 ;
V_381 -> V_389 = V_389 ;
if ( V_387 )
memcpy ( V_381 -> V_388 , V_388 , V_387 ) ;
if ( V_389 )
memcpy ( V_381 -> V_390 ,
V_390 , V_389 ) ;
V_381 -> V_391 = V_391 ;
V_381 -> V_396 = V_391 ;
if ( V_392 == 0 )
V_381 -> V_392 = V_397 ;
else
V_381 -> V_392 = V_392 ;
F_23 ( L_25 , V_6 -> V_36 , V_380 ) ;
return 0 ;
}
struct V_398 * F_199 ( struct V_169 * V_398 ,
T_9 * V_111 , T_7 type )
{
struct V_398 * V_352 ;
F_77 (b, bdaddr_list, list) {
if ( ! F_90 ( & V_352 -> V_111 , V_111 ) && V_352 -> V_347 == type )
return V_352 ;
}
return NULL ;
}
void F_200 ( struct V_169 * V_398 )
{
struct V_398 * V_352 , * V_161 ;
F_85 (b, n, bdaddr_list, list) {
F_86 ( & V_352 -> V_171 ) ;
F_87 ( V_352 ) ;
}
}
int F_201 ( struct V_169 * V_171 , T_9 * V_111 , T_7 type )
{
struct V_398 * V_399 ;
if ( ! F_90 ( V_111 , V_112 ) )
return - V_400 ;
if ( F_199 ( V_171 , V_111 , type ) )
return - V_401 ;
V_399 = F_97 ( sizeof( * V_399 ) , V_181 ) ;
if ( ! V_399 )
return - V_219 ;
F_60 ( & V_399 -> V_111 , V_111 ) ;
V_399 -> V_347 = type ;
F_94 ( & V_399 -> V_171 , V_171 ) ;
return 0 ;
}
int F_202 ( struct V_169 * V_171 , T_9 * V_111 , T_7 type )
{
struct V_398 * V_399 ;
if ( ! F_90 ( V_111 , V_112 ) ) {
F_200 ( V_171 ) ;
return 0 ;
}
V_399 = F_199 ( V_171 , V_111 , type ) ;
if ( ! V_399 )
return - V_365 ;
F_86 ( & V_399 -> V_171 ) ;
F_87 ( V_399 ) ;
return 0 ;
}
struct V_255 * F_203 ( struct V_5 * V_6 ,
T_9 * V_402 , T_7 V_345 )
{
struct V_255 * V_403 ;
F_77 (params, &hdev->le_conn_params, list) {
if ( F_90 ( & V_403 -> V_402 , V_402 ) == 0 &&
V_403 -> V_345 == V_345 ) {
return V_403 ;
}
}
return NULL ;
}
struct V_255 * F_204 ( struct V_169 * V_171 ,
T_9 * V_402 , T_7 V_345 )
{
struct V_255 * V_54 ;
F_77 (param, list, action) {
if ( F_90 ( & V_54 -> V_402 , V_402 ) == 0 &&
V_54 -> V_345 == V_345 )
return V_54 ;
}
return NULL ;
}
struct V_255 * F_205 ( struct V_5 * V_6 ,
T_9 * V_402 , T_7 V_345 )
{
struct V_255 * V_403 ;
V_403 = F_203 ( V_6 , V_402 , V_345 ) ;
if ( V_403 )
return V_403 ;
V_403 = F_97 ( sizeof( * V_403 ) , V_181 ) ;
if ( ! V_403 ) {
F_30 ( L_26 ) ;
return NULL ;
}
F_60 ( & V_403 -> V_402 , V_402 ) ;
V_403 -> V_345 = V_345 ;
F_94 ( & V_403 -> V_171 , & V_6 -> V_404 ) ;
F_88 ( & V_403 -> V_257 ) ;
V_403 -> V_405 = V_6 -> V_406 ;
V_403 -> V_407 = V_6 -> V_408 ;
V_403 -> V_409 = V_6 -> V_410 ;
V_403 -> V_411 = V_6 -> V_412 ;
V_403 -> V_413 = V_414 ;
F_23 ( L_27 , V_402 , V_345 ) ;
return V_403 ;
}
static void F_206 ( struct V_255 * V_403 )
{
if ( V_403 -> V_256 ) {
F_126 ( V_403 -> V_256 ) ;
F_127 ( V_403 -> V_256 ) ;
}
F_86 ( & V_403 -> V_257 ) ;
F_86 ( & V_403 -> V_171 ) ;
F_87 ( V_403 ) ;
}
void F_207 ( struct V_5 * V_6 , T_9 * V_402 , T_7 V_345 )
{
struct V_255 * V_403 ;
V_403 = F_203 ( V_6 , V_402 , V_345 ) ;
if ( ! V_403 )
return;
F_206 ( V_403 ) ;
F_82 ( V_6 ) ;
F_23 ( L_27 , V_402 , V_345 ) ;
}
void F_208 ( struct V_5 * V_6 )
{
struct V_255 * V_403 , * V_327 ;
F_85 (params, tmp, &hdev->le_conn_params, list) {
if ( V_403 -> V_413 != V_414 )
continue;
if ( V_403 -> V_415 ) {
V_403 -> V_413 = V_416 ;
continue;
}
F_86 ( & V_403 -> V_171 ) ;
F_87 ( V_403 ) ;
}
F_23 ( L_28 ) ;
}
static void F_209 ( struct V_5 * V_6 )
{
struct V_255 * V_403 , * V_327 ;
F_85 (params, tmp, &hdev->le_conn_params, list)
F_206 ( V_403 ) ;
F_23 ( L_29 ) ;
}
void F_210 ( struct V_5 * V_6 , T_9 * V_111 ,
T_7 * V_347 )
{
if ( F_2 ( V_6 , V_417 ) ||
! F_90 ( & V_6 -> V_111 , V_112 ) ||
( ! F_2 ( V_6 , V_76 ) &&
F_90 ( & V_6 -> V_224 , V_112 ) ) ) {
F_60 ( V_111 , & V_6 -> V_224 ) ;
* V_347 = V_351 ;
} else {
F_60 ( V_111 , & V_6 -> V_111 ) ;
* V_347 = V_368 ;
}
}
struct V_5 * F_211 ( void )
{
struct V_5 * V_6 ;
V_6 = F_97 ( sizeof( * V_6 ) , V_181 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_298 = ( V_418 | V_419 | V_420 ) ;
V_6 -> V_421 = ( V_422 ) ;
V_6 -> V_294 = ( V_296 ) ;
V_6 -> V_423 = 0x01 ;
V_6 -> V_424 = 0x03 ;
V_6 -> V_425 = 0xffff ;
V_6 -> V_426 = V_427 ;
V_6 -> V_428 = V_427 ;
V_6 -> V_386 = 0 ;
V_6 -> V_283 = 0x00 ;
V_6 -> V_384 = 0 ;
V_6 -> V_429 = 800 ;
V_6 -> V_430 = 80 ;
V_6 -> V_431 = 0x07 ;
V_6 -> V_432 = 0x0800 ;
V_6 -> V_433 = 0x0800 ;
V_6 -> V_434 = 0x0060 ;
V_6 -> V_435 = 0x0030 ;
V_6 -> V_406 = 0x0028 ;
V_6 -> V_408 = 0x0038 ;
V_6 -> V_410 = 0x0000 ;
V_6 -> V_412 = 0x002a ;
V_6 -> V_436 = 0x001b ;
V_6 -> V_437 = 0x0148 ;
V_6 -> V_438 = 0x001b ;
V_6 -> V_439 = 0x0148 ;
V_6 -> V_440 = 0x001b ;
V_6 -> V_441 = 0x0148 ;
V_6 -> V_442 = V_443 ;
V_6 -> V_444 = V_445 ;
V_6 -> V_446 = V_447 ;
V_6 -> V_448 = V_449 ;
F_212 ( & V_6 -> V_450 ) ;
F_212 ( & V_6 -> V_451 ) ;
F_88 ( & V_6 -> V_452 ) ;
F_88 ( & V_6 -> V_453 ) ;
F_88 ( & V_6 -> V_454 ) ;
F_88 ( & V_6 -> V_455 ) ;
F_88 ( & V_6 -> V_356 ) ;
F_88 ( & V_6 -> V_363 ) ;
F_88 ( & V_6 -> V_364 ) ;
F_88 ( & V_6 -> V_377 ) ;
F_88 ( & V_6 -> V_456 ) ;
F_88 ( & V_6 -> V_404 ) ;
F_88 ( & V_6 -> V_457 ) ;
F_88 ( & V_6 -> V_458 ) ;
F_88 ( & V_6 -> V_459 . V_171 ) ;
F_88 ( & V_6 -> V_383 ) ;
F_213 ( & V_6 -> V_242 , V_460 ) ;
F_213 ( & V_6 -> V_241 , V_461 ) ;
F_213 ( & V_6 -> V_240 , V_462 ) ;
F_213 ( & V_6 -> V_320 , F_152 ) ;
F_213 ( & V_6 -> V_322 , F_158 ) ;
F_214 ( & V_6 -> V_252 , F_157 ) ;
F_215 ( & V_6 -> V_244 ) ;
F_215 ( & V_6 -> V_243 ) ;
F_215 ( & V_6 -> V_269 ) ;
F_216 ( & V_6 -> V_463 ) ;
F_214 ( & V_6 -> V_260 , F_185 ) ;
F_217 ( V_6 ) ;
F_218 ( V_6 ) ;
F_219 ( V_6 ) ;
return V_6 ;
}
void F_220 ( struct V_5 * V_6 )
{
F_221 ( & V_6 -> V_250 ) ;
}
int F_222 ( struct V_5 * V_6 )
{
int V_148 , error ;
if ( ! V_6 -> V_226 || ! V_6 -> V_248 || ! V_6 -> V_464 )
return - V_18 ;
switch ( V_6 -> V_51 ) {
case V_52 :
V_148 = F_223 ( & V_465 , 0 , 0 , V_181 ) ;
break;
case V_53 :
V_148 = F_223 ( & V_465 , 1 , 0 , V_181 ) ;
break;
default:
return - V_18 ;
}
if ( V_148 < 0 )
return V_148 ;
sprintf ( V_6 -> V_36 , L_30 , V_148 ) ;
V_6 -> V_148 = V_148 ;
F_23 ( L_31 , V_6 , V_6 -> V_36 , V_6 -> V_313 ) ;
V_6 -> V_267 = F_224 ( L_11 , V_466 | V_467 |
V_468 , 1 , V_6 -> V_36 ) ;
if ( ! V_6 -> V_267 ) {
error = - V_219 ;
goto V_24;
}
V_6 -> V_253 = F_224 ( L_11 , V_466 | V_467 |
V_468 , 1 , V_6 -> V_36 ) ;
if ( ! V_6 -> V_253 ) {
F_225 ( V_6 -> V_267 ) ;
error = - V_219 ;
goto V_24;
}
if ( ! F_226 ( V_469 ) )
V_6 -> V_30 = F_227 ( V_6 -> V_36 , V_469 ) ;
F_228 ( & V_6 -> V_250 , L_11 , V_6 -> V_36 ) ;
error = F_229 ( & V_6 -> V_250 ) ;
if ( error < 0 )
goto V_470;
F_230 ( V_6 ) ;
V_6 -> V_471 = F_231 ( V_6 -> V_36 , & V_6 -> V_250 ,
V_472 , & V_473 ,
V_6 ) ;
if ( V_6 -> V_471 ) {
if ( F_232 ( V_6 -> V_471 ) < 0 ) {
F_233 ( V_6 -> V_471 ) ;
V_6 -> V_471 = NULL ;
}
}
if ( V_6 -> V_471 && F_234 ( V_6 -> V_471 ) )
F_18 ( V_6 , V_222 ) ;
F_18 ( V_6 , V_136 ) ;
F_18 ( V_6 , V_251 ) ;
if ( V_6 -> V_51 == V_52 ) {
F_18 ( V_6 , V_76 ) ;
}
F_235 ( & V_147 ) ;
F_94 ( & V_6 -> V_171 , & V_474 ) ;
F_236 ( & V_147 ) ;
if ( F_6 ( V_139 , & V_6 -> V_26 ) )
F_18 ( V_6 , V_213 ) ;
F_112 ( V_6 , V_475 ) ;
F_78 ( V_6 ) ;
F_187 ( V_6 -> V_253 , & V_6 -> V_320 ) ;
return V_148 ;
V_470:
F_225 ( V_6 -> V_267 ) ;
F_225 ( V_6 -> V_253 ) ;
V_24:
F_237 ( & V_465 , V_6 -> V_148 ) ;
return error ;
}
void F_238 ( struct V_5 * V_6 )
{
int V_148 ;
F_23 ( L_31 , V_6 , V_6 -> V_36 , V_6 -> V_313 ) ;
F_18 ( V_6 , V_221 ) ;
V_148 = V_6 -> V_148 ;
F_235 ( & V_147 ) ;
F_86 ( & V_6 -> V_171 ) ;
F_236 ( & V_147 ) ;
F_239 ( & V_6 -> V_320 ) ;
F_129 ( V_6 ) ;
if ( ! F_6 ( V_230 , & V_6 -> V_15 ) &&
! F_2 ( V_6 , V_136 ) &&
! F_2 ( V_6 , V_137 ) ) {
F_101 ( V_6 ) ;
F_240 ( V_6 ) ;
F_104 ( V_6 ) ;
}
F_241 ( ! F_242 ( & V_6 -> V_452 ) ) ;
F_112 ( V_6 , V_476 ) ;
if ( V_6 -> V_471 ) {
F_243 ( V_6 -> V_471 ) ;
F_233 ( V_6 -> V_471 ) ;
}
F_244 ( & V_6 -> V_250 ) ;
F_245 ( V_6 -> V_30 ) ;
F_246 ( V_6 -> V_477 ) ;
F_246 ( V_6 -> V_478 ) ;
F_225 ( V_6 -> V_267 ) ;
F_225 ( V_6 -> V_253 ) ;
F_101 ( V_6 ) ;
F_200 ( & V_6 -> V_453 ) ;
F_200 ( & V_6 -> V_454 ) ;
F_159 ( V_6 ) ;
F_160 ( V_6 ) ;
F_164 ( V_6 ) ;
F_165 ( V_6 ) ;
F_189 ( V_6 ) ;
F_197 ( V_6 ) ;
F_200 ( & V_6 -> V_456 ) ;
F_209 ( V_6 ) ;
F_247 ( V_6 ) ;
F_104 ( V_6 ) ;
F_110 ( V_6 ) ;
F_237 ( & V_465 , V_148 ) ;
}
int F_248 ( struct V_5 * V_6 )
{
F_112 ( V_6 , V_479 ) ;
return 0 ;
}
int F_249 ( struct V_5 * V_6 )
{
F_112 ( V_6 , V_480 ) ;
return 0 ;
}
int F_250 ( struct V_5 * V_6 )
{
const T_7 V_481 [] = { V_482 , 0x01 , 0x00 } ;
struct V_10 * V_11 ;
V_11 = F_251 ( 3 , V_483 ) ;
if ( ! V_11 )
return - V_219 ;
F_252 ( V_11 ) = V_484 ;
memcpy ( F_253 ( V_11 , 3 ) , V_481 , 3 ) ;
return F_254 ( V_6 , V_11 ) ;
}
int F_254 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( ! V_6 || ( ! F_6 ( V_14 , & V_6 -> V_15 )
&& ! F_6 ( V_230 , & V_6 -> V_15 ) ) ) {
F_14 ( V_11 ) ;
return - V_485 ;
}
if ( F_252 ( V_11 ) != V_484 &&
F_252 ( V_11 ) != V_486 &&
F_252 ( V_11 ) != V_487 ) {
F_14 ( V_11 ) ;
return - V_18 ;
}
F_255 ( V_11 ) -> V_488 = 1 ;
F_256 ( V_11 ) ;
F_257 ( & V_6 -> V_244 , V_11 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_242 ) ;
return 0 ;
}
int F_258 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
F_252 ( V_11 ) = V_489 ;
F_256 ( V_11 ) ;
F_257 ( & V_6 -> V_244 , V_11 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_242 ) ;
return 0 ;
}
void F_259 ( struct V_5 * V_6 , const char * V_490 , ... )
{
T_13 V_491 ;
va_start ( V_491 , V_490 ) ;
F_246 ( V_6 -> V_477 ) ;
V_6 -> V_477 = F_260 ( V_181 , V_490 , V_491 ) ;
va_end ( V_491 ) ;
}
void F_261 ( struct V_5 * V_6 , const char * V_490 , ... )
{
T_13 V_491 ;
va_start ( V_491 , V_490 ) ;
F_246 ( V_6 -> V_478 ) ;
V_6 -> V_478 = F_260 ( V_181 , V_490 , V_491 ) ;
va_end ( V_491 ) ;
}
int F_262 ( struct V_492 * V_493 )
{
F_23 ( L_32 , V_493 , V_493 -> V_36 ) ;
F_263 ( & V_494 ) ;
F_264 ( & V_493 -> V_171 , & V_495 ) ;
F_265 ( & V_494 ) ;
return 0 ;
}
int F_266 ( struct V_492 * V_493 )
{
F_23 ( L_32 , V_493 , V_493 -> V_36 ) ;
F_263 ( & V_494 ) ;
F_86 ( & V_493 -> V_171 ) ;
F_265 ( & V_494 ) ;
return 0 ;
}
static void F_267 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
int V_24 ;
F_23 ( L_33 , V_6 -> V_36 , F_252 ( V_11 ) ,
V_11 -> V_496 ) ;
F_256 ( V_11 ) ;
F_268 ( V_6 , V_11 ) ;
if ( F_269 ( & V_6 -> V_497 ) ) {
F_270 ( V_6 , V_11 ) ;
}
F_271 ( V_11 ) ;
if ( ! F_6 ( V_27 , & V_6 -> V_15 ) ) {
F_14 ( V_11 ) ;
return;
}
V_24 = V_6 -> V_464 ( V_6 , V_11 ) ;
if ( V_24 < 0 ) {
F_30 ( L_34 , V_6 -> V_36 , V_24 ) ;
F_14 ( V_11 ) ;
}
}
int F_272 ( struct V_5 * V_6 , T_11 V_371 , T_14 V_498 ,
const void * V_54 )
{
struct V_10 * V_11 ;
F_23 ( L_35 , V_6 -> V_36 , V_371 , V_498 ) ;
V_11 = F_273 ( V_6 , V_371 , V_498 , V_54 ) ;
if ( ! V_11 ) {
F_30 ( L_36 , V_6 -> V_36 ) ;
return - V_219 ;
}
F_255 ( V_11 ) -> V_499 . V_500 |= V_501 ;
F_257 ( & V_6 -> V_243 , V_11 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_241 ) ;
return 0 ;
}
void * F_274 ( struct V_5 * V_6 , T_11 V_371 )
{
struct V_369 * V_502 ;
if ( ! V_6 -> V_246 )
return NULL ;
V_502 = ( void * ) V_6 -> V_246 -> V_166 ;
if ( V_502 -> V_371 != F_32 ( V_371 ) )
return NULL ;
F_23 ( L_37 , V_6 -> V_36 , V_371 ) ;
return V_6 -> V_246 -> V_166 + V_503 ;
}
struct V_10 * F_275 ( struct V_5 * V_6 , T_8 V_371 , T_10 V_498 ,
const void * V_54 , T_10 V_391 )
{
struct V_10 * V_11 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) )
return F_276 ( - V_16 ) ;
F_277 ( V_6 , L_38 , V_371 , V_498 ) ;
F_9 ( V_6 ) ;
V_11 = F_10 ( V_6 , V_371 , V_498 , V_54 , V_391 ) ;
F_11 ( V_6 ) ;
return V_11 ;
}
static void F_278 ( struct V_10 * V_11 , T_11 V_504 , T_11 V_15 )
{
struct V_505 * V_502 ;
int V_496 = V_11 -> V_496 ;
F_279 ( V_11 , V_506 ) ;
F_280 ( V_11 ) ;
V_502 = (struct V_505 * ) F_281 ( V_11 ) ;
V_502 -> V_504 = F_32 ( F_282 ( V_504 , V_15 ) ) ;
V_502 -> V_507 = F_32 ( V_496 ) ;
}
static void F_283 ( struct V_508 * V_509 , struct V_510 * V_511 ,
struct V_10 * V_11 , T_11 V_15 )
{
struct V_334 * V_256 = V_509 -> V_256 ;
struct V_5 * V_6 = V_256 -> V_6 ;
struct V_10 * V_171 ;
V_11 -> V_496 = F_284 ( V_11 ) ;
V_11 -> V_512 = 0 ;
F_252 ( V_11 ) = V_486 ;
switch ( V_6 -> V_51 ) {
case V_52 :
F_278 ( V_11 , V_256 -> V_504 , V_15 ) ;
break;
case V_53 :
F_278 ( V_11 , V_509 -> V_504 , V_15 ) ;
break;
default:
F_30 ( L_39 , V_6 -> V_36 , V_6 -> V_51 ) ;
return;
}
V_171 = F_285 ( V_11 ) -> V_513 ;
if ( ! V_171 ) {
F_23 ( L_40 , V_6 -> V_36 , V_11 , V_11 -> V_496 ) ;
F_257 ( V_511 , V_11 ) ;
} else {
F_23 ( L_41 , V_6 -> V_36 , V_11 , V_11 -> V_496 ) ;
F_285 ( V_11 ) -> V_513 = NULL ;
F_286 ( & V_511 -> V_450 ) ;
F_287 ( V_511 , V_11 ) ;
V_15 &= ~ V_514 ;
V_15 |= V_515 ;
do {
V_11 = V_171 ; V_171 = V_171 -> V_516 ;
F_252 ( V_11 ) = V_486 ;
F_278 ( V_11 , V_256 -> V_504 , V_15 ) ;
F_23 ( L_41 , V_6 -> V_36 , V_11 , V_11 -> V_496 ) ;
F_287 ( V_511 , V_11 ) ;
} while ( V_171 );
F_288 ( & V_511 -> V_450 ) ;
}
}
void F_289 ( struct V_508 * V_509 , struct V_10 * V_11 , T_11 V_15 )
{
struct V_5 * V_6 = V_509 -> V_256 -> V_6 ;
F_23 ( L_42 , V_6 -> V_36 , V_509 , V_15 ) ;
F_283 ( V_509 , & V_509 -> V_517 , V_11 , V_15 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_240 ) ;
}
void F_290 ( struct V_334 * V_256 , struct V_10 * V_11 )
{
struct V_5 * V_6 = V_256 -> V_6 ;
struct V_518 V_502 ;
F_23 ( L_43 , V_6 -> V_36 , V_11 -> V_496 ) ;
V_502 . V_504 = F_32 ( V_256 -> V_504 ) ;
V_502 . V_507 = V_11 -> V_496 ;
F_279 ( V_11 , V_519 ) ;
F_280 ( V_11 ) ;
memcpy ( F_281 ( V_11 ) , & V_502 , V_519 ) ;
F_252 ( V_11 ) = V_487 ;
F_257 ( & V_256 -> V_517 , V_11 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_240 ) ;
}
static struct V_334 * F_291 ( struct V_5 * V_6 , T_6 type ,
int * V_520 )
{
struct V_521 * V_522 = & V_6 -> V_459 ;
struct V_334 * V_256 = NULL , * V_523 ;
unsigned int V_187 = 0 , F_5 = ~ 0 ;
F_167 () ;
F_161 (c, &h->list, list) {
if ( V_523 -> type != type || F_292 ( & V_523 -> V_517 ) )
continue;
if ( V_523 -> V_152 != V_524 && V_523 -> V_152 != V_525 )
continue;
V_187 ++ ;
if ( V_523 -> V_370 < F_5 ) {
F_5 = V_523 -> V_370 ;
V_256 = V_523 ;
}
if ( F_293 ( V_6 , type ) == V_187 )
break;
}
F_168 () ;
if ( V_256 ) {
int V_526 , V_527 ;
switch ( V_256 -> type ) {
case V_528 :
V_526 = V_6 -> V_273 ;
break;
case V_529 :
case V_530 :
V_526 = V_6 -> V_274 ;
break;
case V_339 :
V_526 = V_6 -> V_314 ? V_6 -> V_275 : V_6 -> V_273 ;
break;
default:
V_526 = 0 ;
F_30 ( L_44 ) ;
}
V_527 = V_526 / V_187 ;
* V_520 = V_527 ? V_527 : 1 ;
} else
* V_520 = 0 ;
F_23 ( L_45 , V_256 , * V_520 ) ;
return V_256 ;
}
static void F_294 ( struct V_5 * V_6 , T_6 type )
{
struct V_521 * V_522 = & V_6 -> V_459 ;
struct V_334 * V_523 ;
F_30 ( L_46 , V_6 -> V_36 ) ;
F_167 () ;
F_161 (c, &h->list, list) {
if ( V_523 -> type == type && V_523 -> V_370 ) {
F_30 ( L_47 ,
V_6 -> V_36 , & V_523 -> V_531 ) ;
F_295 ( V_523 , V_532 ) ;
}
}
F_168 () ;
}
static struct V_508 * F_296 ( struct V_5 * V_6 , T_6 type ,
int * V_520 )
{
struct V_521 * V_522 = & V_6 -> V_459 ;
struct V_508 * V_509 = NULL ;
unsigned int V_187 = 0 , F_5 = ~ 0 , V_533 = 0 ;
struct V_334 * V_256 ;
int V_526 , V_527 , V_534 = 0 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
F_167 () ;
F_161 (conn, &h->list, list) {
struct V_508 * V_327 ;
if ( V_256 -> type != type )
continue;
if ( V_256 -> V_152 != V_524 && V_256 -> V_152 != V_525 )
continue;
V_534 ++ ;
F_161 (tmp, &conn->chan_list, list) {
struct V_10 * V_11 ;
if ( F_292 ( & V_327 -> V_517 ) )
continue;
V_11 = F_297 ( & V_327 -> V_517 ) ;
if ( V_11 -> V_535 < V_533 )
continue;
if ( V_11 -> V_535 > V_533 ) {
V_187 = 0 ;
F_5 = ~ 0 ;
V_533 = V_11 -> V_535 ;
}
V_187 ++ ;
if ( V_256 -> V_370 < F_5 ) {
F_5 = V_256 -> V_370 ;
V_509 = V_327 ;
}
}
if ( F_293 ( V_6 , type ) == V_534 )
break;
}
F_168 () ;
if ( ! V_509 )
return NULL ;
switch ( V_509 -> V_256 -> type ) {
case V_528 :
V_526 = V_6 -> V_273 ;
break;
case V_536 :
V_526 = V_6 -> V_537 ;
break;
case V_529 :
case V_530 :
V_526 = V_6 -> V_274 ;
break;
case V_339 :
V_526 = V_6 -> V_314 ? V_6 -> V_275 : V_6 -> V_273 ;
break;
default:
V_526 = 0 ;
F_30 ( L_44 ) ;
}
V_527 = V_526 / V_187 ;
* V_520 = V_527 ? V_527 : 1 ;
F_23 ( L_48 , V_509 , * V_520 ) ;
return V_509 ;
}
static void F_298 ( struct V_5 * V_6 , T_6 type )
{
struct V_521 * V_522 = & V_6 -> V_459 ;
struct V_334 * V_256 ;
int V_187 = 0 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
F_167 () ;
F_161 (conn, &h->list, list) {
struct V_508 * V_509 ;
if ( V_256 -> type != type )
continue;
if ( V_256 -> V_152 != V_524 && V_256 -> V_152 != V_525 )
continue;
V_187 ++ ;
F_161 (chan, &conn->chan_list, list) {
struct V_10 * V_11 ;
if ( V_509 -> V_370 ) {
V_509 -> V_370 = 0 ;
continue;
}
if ( F_292 ( & V_509 -> V_517 ) )
continue;
V_11 = F_297 ( & V_509 -> V_517 ) ;
if ( V_11 -> V_535 >= V_538 - 1 )
continue;
V_11 -> V_535 = V_538 - 1 ;
F_23 ( L_49 , V_509 , V_11 ,
V_11 -> V_535 ) ;
}
if ( F_293 ( V_6 , type ) == V_187 )
break;
}
F_168 () ;
}
static inline int F_299 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
return F_300 ( V_11 -> V_496 - V_506 , V_6 -> V_539 ) ;
}
static void F_301 ( struct V_5 * V_6 , unsigned int V_526 )
{
if ( ! F_2 ( V_6 , V_213 ) ) {
if ( ! V_526 && F_302 ( V_186 , V_6 -> V_540 +
V_541 ) )
F_294 ( V_6 , V_528 ) ;
}
}
static void F_303 ( struct V_5 * V_6 )
{
unsigned int V_526 = V_6 -> V_273 ;
struct V_508 * V_509 ;
struct V_10 * V_11 ;
int V_520 ;
F_301 ( V_6 , V_526 ) ;
while ( V_6 -> V_273 &&
( V_509 = F_296 ( V_6 , V_528 , & V_520 ) ) ) {
T_10 V_535 = ( F_297 ( & V_509 -> V_517 ) ) -> V_535 ;
while ( V_520 -- && ( V_11 = F_297 ( & V_509 -> V_517 ) ) ) {
F_23 ( L_50 , V_509 , V_11 ,
V_11 -> V_496 , V_11 -> V_535 ) ;
if ( V_11 -> V_535 < V_535 )
break;
V_11 = F_304 ( & V_509 -> V_517 ) ;
F_305 ( V_509 -> V_256 ,
F_255 ( V_11 ) -> V_542 ) ;
F_267 ( V_6 , V_11 ) ;
V_6 -> V_540 = V_186 ;
V_6 -> V_273 -- ;
V_509 -> V_370 ++ ;
V_509 -> V_256 -> V_370 ++ ;
}
}
if ( V_526 != V_6 -> V_273 )
F_298 ( V_6 , V_528 ) ;
}
static void F_306 ( struct V_5 * V_6 )
{
unsigned int V_526 = V_6 -> V_537 ;
struct V_508 * V_509 ;
struct V_10 * V_11 ;
int V_520 ;
T_7 type ;
F_301 ( V_6 , V_526 ) ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( V_6 -> V_51 == V_53 )
type = V_536 ;
else
type = V_528 ;
while ( V_6 -> V_537 > 0 &&
( V_509 = F_296 ( V_6 , type , & V_520 ) ) ) {
T_10 V_535 = ( F_297 ( & V_509 -> V_517 ) ) -> V_535 ;
while ( V_520 > 0 && ( V_11 = F_297 ( & V_509 -> V_517 ) ) ) {
int V_543 ;
F_23 ( L_50 , V_509 , V_11 ,
V_11 -> V_496 , V_11 -> V_535 ) ;
if ( V_11 -> V_535 < V_535 )
break;
V_11 = F_304 ( & V_509 -> V_517 ) ;
V_543 = F_299 ( V_6 , V_11 ) ;
if ( V_543 > V_6 -> V_537 )
return;
F_305 ( V_509 -> V_256 ,
F_255 ( V_11 ) -> V_542 ) ;
F_267 ( V_6 , V_11 ) ;
V_6 -> V_540 = V_186 ;
V_6 -> V_537 -= V_543 ;
V_520 -= V_543 ;
V_509 -> V_370 += V_543 ;
V_509 -> V_256 -> V_370 += V_543 ;
}
}
if ( V_526 != V_6 -> V_537 )
F_298 ( V_6 , type ) ;
}
static void F_307 ( struct V_5 * V_6 )
{
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( ! F_293 ( V_6 , V_528 ) && V_6 -> V_51 == V_52 )
return;
if ( ! F_293 ( V_6 , V_536 ) && V_6 -> V_51 == V_53 )
return;
switch ( V_6 -> V_38 ) {
case V_39 :
F_303 ( V_6 ) ;
break;
case V_43 :
F_306 ( V_6 ) ;
break;
}
}
static void F_308 ( struct V_5 * V_6 )
{
struct V_334 * V_256 ;
struct V_10 * V_11 ;
int V_520 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( ! F_293 ( V_6 , V_529 ) )
return;
while ( V_6 -> V_274 && ( V_256 = F_291 ( V_6 , V_529 , & V_520 ) ) ) {
while ( V_520 -- && ( V_11 = F_304 ( & V_256 -> V_517 ) ) ) {
F_23 ( L_51 , V_11 , V_11 -> V_496 ) ;
F_267 ( V_6 , V_11 ) ;
V_256 -> V_370 ++ ;
if ( V_256 -> V_370 == ~ 0 )
V_256 -> V_370 = 0 ;
}
}
}
static void F_309 ( struct V_5 * V_6 )
{
struct V_334 * V_256 ;
struct V_10 * V_11 ;
int V_520 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( ! F_293 ( V_6 , V_530 ) )
return;
while ( V_6 -> V_274 && ( V_256 = F_291 ( V_6 , V_530 ,
& V_520 ) ) ) {
while ( V_520 -- && ( V_11 = F_304 ( & V_256 -> V_517 ) ) ) {
F_23 ( L_51 , V_11 , V_11 -> V_496 ) ;
F_267 ( V_6 , V_11 ) ;
V_256 -> V_370 ++ ;
if ( V_256 -> V_370 == ~ 0 )
V_256 -> V_370 = 0 ;
}
}
}
static void F_310 ( struct V_5 * V_6 )
{
struct V_508 * V_509 ;
struct V_10 * V_11 ;
int V_520 , V_526 , V_327 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
if ( ! F_293 ( V_6 , V_339 ) )
return;
if ( ! F_2 ( V_6 , V_213 ) ) {
if ( ! V_6 -> V_275 && V_6 -> V_315 &&
F_302 ( V_186 , V_6 -> V_544 + V_545 * 45 ) )
F_294 ( V_6 , V_339 ) ;
}
V_526 = V_6 -> V_315 ? V_6 -> V_275 : V_6 -> V_273 ;
V_327 = V_526 ;
while ( V_526 && ( V_509 = F_296 ( V_6 , V_339 , & V_520 ) ) ) {
T_10 V_535 = ( F_297 ( & V_509 -> V_517 ) ) -> V_535 ;
while ( V_520 -- && ( V_11 = F_297 ( & V_509 -> V_517 ) ) ) {
F_23 ( L_50 , V_509 , V_11 ,
V_11 -> V_496 , V_11 -> V_535 ) ;
if ( V_11 -> V_535 < V_535 )
break;
V_11 = F_304 ( & V_509 -> V_517 ) ;
F_267 ( V_6 , V_11 ) ;
V_6 -> V_544 = V_186 ;
V_526 -- ;
V_509 -> V_370 ++ ;
V_509 -> V_256 -> V_370 ++ ;
}
}
if ( V_6 -> V_315 )
V_6 -> V_275 = V_526 ;
else
V_6 -> V_273 = V_526 ;
if ( V_526 != V_327 )
F_298 ( V_6 , V_339 ) ;
}
static void V_462 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 , V_240 ) ;
struct V_10 * V_11 ;
F_23 ( L_52 , V_6 -> V_36 , V_6 -> V_273 ,
V_6 -> V_274 , V_6 -> V_275 ) ;
if ( ! F_2 ( V_6 , V_211 ) ) {
F_307 ( V_6 ) ;
F_308 ( V_6 ) ;
F_309 ( V_6 ) ;
F_310 ( V_6 ) ;
}
while ( ( V_11 = F_304 ( & V_6 -> V_269 ) ) )
F_267 ( V_6 , V_11 ) ;
}
static void F_311 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_505 * V_502 = ( void * ) V_11 -> V_166 ;
struct V_334 * V_256 ;
T_11 V_504 , V_15 ;
F_312 ( V_11 , V_506 ) ;
V_504 = F_186 ( V_502 -> V_504 ) ;
V_15 = F_313 ( V_504 ) ;
V_504 = F_314 ( V_504 ) ;
F_23 ( L_53 , V_6 -> V_36 , V_11 -> V_496 ,
V_504 , V_15 ) ;
V_6 -> V_276 . V_546 ++ ;
F_101 ( V_6 ) ;
V_256 = F_315 ( V_6 , V_504 ) ;
F_104 ( V_6 ) ;
if ( V_256 ) {
F_305 ( V_256 , V_547 ) ;
F_316 ( V_256 , V_11 , V_15 ) ;
return;
} else {
F_30 ( L_54 ,
V_6 -> V_36 , V_504 ) ;
}
F_14 ( V_11 ) ;
}
static void F_317 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_518 * V_502 = ( void * ) V_11 -> V_166 ;
struct V_334 * V_256 ;
T_11 V_504 ;
F_312 ( V_11 , V_519 ) ;
V_504 = F_186 ( V_502 -> V_504 ) ;
F_23 ( L_55 , V_6 -> V_36 , V_11 -> V_496 , V_504 ) ;
V_6 -> V_276 . V_548 ++ ;
F_101 ( V_6 ) ;
V_256 = F_315 ( V_6 , V_504 ) ;
F_104 ( V_6 ) ;
if ( V_256 ) {
F_318 ( V_256 , V_11 ) ;
return;
} else {
F_30 ( L_56 ,
V_6 -> V_36 , V_504 ) ;
}
F_14 ( V_11 ) ;
}
static bool F_319 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
V_11 = F_297 ( & V_6 -> V_243 ) ;
if ( ! V_11 )
return true ;
return ( F_255 ( V_11 ) -> V_499 . V_500 & V_501 ) ;
}
static void F_320 ( struct V_5 * V_6 )
{
struct V_369 * V_370 ;
struct V_10 * V_11 ;
T_8 V_371 ;
if ( ! V_6 -> V_246 )
return;
V_370 = ( void * ) V_6 -> V_246 -> V_166 ;
V_371 = F_186 ( V_370 -> V_371 ) ;
if ( V_371 == V_22 )
return;
V_11 = F_321 ( V_6 -> V_246 , V_181 ) ;
if ( ! V_11 )
return;
F_322 ( & V_6 -> V_243 , V_11 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_241 ) ;
}
void F_323 ( struct V_5 * V_6 , T_8 V_371 , T_7 V_549 ,
T_15 * V_550 ,
T_16 * V_551 )
{
struct V_10 * V_11 ;
unsigned long V_15 ;
F_23 ( L_57 , V_371 , V_549 ) ;
if ( ! F_274 ( V_6 , V_371 ) ) {
if ( F_6 ( V_230 , & V_6 -> V_15 ) && V_371 == V_22 )
F_320 ( V_6 ) ;
return;
}
if ( ! V_549 && ! F_319 ( V_6 ) )
return;
if ( F_255 ( V_6 -> V_246 ) -> V_499 . V_500 & V_552 ) {
* V_551 = F_255 ( V_6 -> V_246 ) -> V_499 . V_551 ;
return;
}
if ( F_255 ( V_6 -> V_246 ) -> V_499 . V_550 ) {
* V_550 = F_255 ( V_6 -> V_246 ) -> V_499 . V_550 ;
return;
}
F_324 ( & V_6 -> V_243 . V_450 , V_15 ) ;
while ( ( V_11 = F_325 ( & V_6 -> V_243 ) ) ) {
if ( F_255 ( V_11 ) -> V_499 . V_500 & V_501 ) {
F_326 ( & V_6 -> V_243 , V_11 ) ;
break;
}
if ( F_255 ( V_11 ) -> V_499 . V_500 & V_552 )
* V_551 = F_255 ( V_11 ) -> V_499 . V_551 ;
else
* V_550 = F_255 ( V_11 ) -> V_499 . V_550 ;
F_14 ( V_11 ) ;
}
F_327 ( & V_6 -> V_243 . V_450 , V_15 ) ;
}
static void V_460 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 , V_242 ) ;
struct V_10 * V_11 ;
F_23 ( L_11 , V_6 -> V_36 ) ;
while ( ( V_11 = F_304 ( & V_6 -> V_244 ) ) ) {
F_268 ( V_6 , V_11 ) ;
if ( F_269 ( & V_6 -> V_497 ) ) {
F_270 ( V_6 , V_11 ) ;
}
if ( F_2 ( V_6 , V_211 ) ) {
F_14 ( V_11 ) ;
continue;
}
if ( F_6 ( V_230 , & V_6 -> V_15 ) ) {
switch ( F_252 ( V_11 ) ) {
case V_486 :
case V_487 :
F_14 ( V_11 ) ;
continue;
}
}
switch ( F_252 ( V_11 ) ) {
case V_484 :
F_23 ( L_58 , V_6 -> V_36 ) ;
F_328 ( V_6 , V_11 ) ;
break;
case V_486 :
F_23 ( L_59 , V_6 -> V_36 ) ;
F_311 ( V_6 , V_11 ) ;
break;
case V_487 :
F_23 ( L_60 , V_6 -> V_36 ) ;
F_317 ( V_6 , V_11 ) ;
break;
default:
F_14 ( V_11 ) ;
break;
}
}
}
static void V_461 ( struct V_318 * V_319 )
{
struct V_5 * V_6 = F_153 ( V_319 , struct V_5 , V_241 ) ;
struct V_10 * V_11 ;
F_23 ( L_61 , V_6 -> V_36 ,
F_269 ( & V_6 -> V_229 ) , F_329 ( & V_6 -> V_243 ) ) ;
if ( F_269 ( & V_6 -> V_229 ) ) {
V_11 = F_304 ( & V_6 -> V_243 ) ;
if ( ! V_11 )
return;
F_14 ( V_6 -> V_246 ) ;
V_6 -> V_246 = F_321 ( V_11 , V_181 ) ;
if ( V_6 -> V_246 ) {
F_330 ( & V_6 -> V_229 ) ;
F_267 ( V_6 , V_11 ) ;
if ( F_6 ( V_37 , & V_6 -> V_15 ) )
F_123 ( & V_6 -> V_260 ) ;
else
F_331 ( & V_6 -> V_260 ,
V_21 ) ;
} else {
F_322 ( & V_6 -> V_243 , V_11 ) ;
F_187 ( V_6 -> V_267 , & V_6 -> V_241 ) ;
}
}
}
