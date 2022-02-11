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
( ! F_6 ( V_27 , & V_6 -> V_15 ) ||
F_2 ( V_6 , V_28 ) ) )
goto V_29;
F_9 ( V_6 ) ;
V_24 = V_6 -> V_30 ( V_6 , V_13 ) ;
F_11 ( V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
V_29:
if ( V_13 )
F_18 ( V_6 , V_23 ) ;
else
F_19 ( V_6 , V_23 ) ;
return V_3 ;
}
static void F_20 ( struct V_5 * V_6 )
{
F_21 ( L_1 , 0644 , V_6 -> V_31 , V_6 ,
& V_32 ) ;
if ( V_6 -> V_30 )
F_21 ( L_2 , 0644 , V_6 -> V_31 , V_6 ,
& V_33 ) ;
}
static int F_22 ( struct V_34 * V_35 , unsigned long V_36 )
{
F_23 ( L_3 , V_35 -> V_6 -> V_37 , V_36 ) ;
F_24 ( V_38 , & V_35 -> V_6 -> V_15 ) ;
F_25 ( V_35 , V_22 , 0 , NULL ) ;
return 0 ;
}
static void F_26 ( struct V_34 * V_35 )
{
V_35 -> V_6 -> V_39 = V_40 ;
F_25 ( V_35 , V_41 , 0 , NULL ) ;
F_25 ( V_35 , V_42 , 0 , NULL ) ;
F_25 ( V_35 , V_43 , 0 , NULL ) ;
}
static void F_27 ( struct V_34 * V_35 )
{
V_35 -> V_6 -> V_39 = V_44 ;
F_25 ( V_35 , V_42 , 0 , NULL ) ;
F_25 ( V_35 , V_45 , 0 , NULL ) ;
F_25 ( V_35 , V_46 , 0 , NULL ) ;
F_25 ( V_35 , V_47 , 0 , NULL ) ;
F_25 ( V_35 , V_48 , 0 , NULL ) ;
F_25 ( V_35 , V_49 , 0 , NULL ) ;
}
static int F_28 ( struct V_34 * V_35 )
{
if ( V_35 -> V_6 -> V_50 [ 14 ] & 0x20 )
F_25 ( V_35 , V_41 , 0 , NULL ) ;
return 0 ;
}
static int F_29 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
F_23 ( L_3 , V_6 -> V_37 , V_36 ) ;
if ( ! F_6 ( V_51 , & V_6 -> V_26 ) )
F_22 ( V_35 , 0 ) ;
switch ( V_6 -> V_52 ) {
case V_53 :
F_26 ( V_35 ) ;
break;
case V_54 :
F_27 ( V_35 ) ;
break;
default:
F_30 ( L_4 , V_6 -> V_52 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_34 * V_35 )
{
T_5 V_55 ;
T_6 V_56 ;
F_25 ( V_35 , V_57 , 0 , NULL ) ;
F_25 ( V_35 , V_58 , 0 , NULL ) ;
F_25 ( V_35 , V_59 , 0 , NULL ) ;
F_25 ( V_35 , V_60 , 0 , NULL ) ;
F_25 ( V_35 , V_61 , 0 , NULL ) ;
F_25 ( V_35 , V_62 , 0 , NULL ) ;
V_56 = V_63 ;
F_25 ( V_35 , V_64 , 1 , & V_56 ) ;
V_55 = F_32 ( 0x7d00 ) ;
F_25 ( V_35 , V_65 , 2 , & V_55 ) ;
}
static void F_33 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
F_25 ( V_35 , V_66 , 0 , NULL ) ;
F_25 ( V_35 , V_67 , 0 , NULL ) ;
F_25 ( V_35 , V_68 , 0 , NULL ) ;
if ( ! F_34 ( V_6 ) )
F_18 ( V_6 , V_69 ) ;
}
static void F_35 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
T_7 V_70 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_6 -> V_71 < V_72 )
return;
if ( F_34 ( V_6 ) ) {
V_70 [ 4 ] |= 0x01 ;
} else {
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
V_70 [ 1 ] |= 0x20 ;
V_70 [ 1 ] |= 0x40 ;
V_70 [ 1 ] |= 0x80 ;
if ( V_6 -> V_50 [ 0 ] & 0x20 ) {
V_70 [ 0 ] |= 0x10 ;
V_70 [ 2 ] |= 0x04 ;
V_70 [ 3 ] |= 0x02 ;
}
if ( V_6 -> V_50 [ 2 ] & 0x80 )
V_70 [ 1 ] |= 0x08 ;
if ( V_6 -> V_73 [ 0 ] & V_74 ) {
V_70 [ 0 ] |= 0x80 ;
V_70 [ 5 ] |= 0x80 ;
}
}
if ( F_36 ( V_6 ) ||
F_6 ( V_75 , & V_6 -> V_26 ) )
V_70 [ 4 ] |= 0x02 ;
if ( F_37 ( V_6 ) )
V_70 [ 4 ] |= 0x04 ;
if ( F_38 ( V_6 ) ) {
V_70 [ 5 ] |= 0x08 ;
V_70 [ 5 ] |= 0x10 ;
}
if ( F_39 ( V_6 ) )
V_70 [ 5 ] |= 0x20 ;
if ( F_40 ( V_6 ) )
V_70 [ 5 ] |= 0x80 ;
if ( F_41 ( V_6 ) )
V_70 [ 5 ] |= 0x40 ;
if ( F_42 ( V_6 ) )
V_70 [ 7 ] |= 0x01 ;
if ( F_43 ( V_6 ) )
V_70 [ 6 ] |= 0x80 ;
if ( F_44 ( V_6 ) ) {
V_70 [ 6 ] |= 0x01 ;
V_70 [ 6 ] |= 0x02 ;
V_70 [ 6 ] |= 0x04 ;
V_70 [ 6 ] |= 0x08 ;
V_70 [ 6 ] |= 0x10 ;
V_70 [ 6 ] |= 0x20 ;
V_70 [ 7 ] |= 0x04 ;
V_70 [ 7 ] |= 0x08 ;
V_70 [ 7 ] |= 0x10 ;
}
if ( F_45 ( V_6 ) )
V_70 [ 7 ] |= 0x20 ;
F_25 ( V_35 , V_76 , sizeof( V_70 ) , V_70 ) ;
}
static int F_46 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
if ( V_6 -> V_52 == V_54 )
return F_28 ( V_35 ) ;
if ( F_34 ( V_6 ) )
F_31 ( V_35 ) ;
else
F_19 ( V_6 , V_77 ) ;
if ( F_45 ( V_6 ) )
F_33 ( V_35 ) ;
if ( V_6 -> V_71 > V_78 &&
! F_6 ( V_79 , & V_6 -> V_26 ) )
F_25 ( V_35 , V_45 , 0 , NULL ) ;
if ( F_44 ( V_6 ) ) {
V_6 -> V_80 = 0x01 ;
if ( F_2 ( V_6 , V_81 ) ) {
T_7 V_82 = 0x01 ;
F_25 ( V_35 , V_83 ,
sizeof( V_82 ) , & V_82 ) ;
} else {
struct V_84 V_85 ;
memset ( V_6 -> V_86 , 0 , sizeof( V_6 -> V_86 ) ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
F_25 ( V_35 , V_87 , sizeof( V_85 ) , & V_85 ) ;
}
}
if ( F_36 ( V_6 ) ||
F_6 ( V_75 , & V_6 -> V_26 ) ) {
T_7 V_82 ;
V_82 = F_41 ( V_6 ) ? 0x02 : 0x01 ;
F_25 ( V_35 , V_88 , 1 , & V_82 ) ;
}
if ( F_47 ( V_6 ) )
F_25 ( V_35 , V_89 , 0 , NULL ) ;
if ( F_37 ( V_6 ) ) {
struct V_90 V_85 ;
V_85 . V_91 = 0x01 ;
F_25 ( V_35 , V_92 ,
sizeof( V_85 ) , & V_85 ) ;
}
if ( F_2 ( V_6 , V_93 ) ) {
T_7 V_13 = 1 ;
F_25 ( V_35 , V_94 , sizeof( V_13 ) ,
& V_13 ) ;
}
return 0 ;
}
static void F_48 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_95 V_85 ;
T_8 V_96 = 0 ;
if ( F_49 ( V_6 ) )
V_96 |= V_97 ;
if ( F_50 ( V_6 ) )
V_96 |= V_98 ;
if ( F_51 ( V_6 ) )
V_96 |= V_99 ;
if ( F_52 ( V_6 ) )
V_96 |= V_100 ;
V_85 . V_101 = F_32 ( V_96 ) ;
F_25 ( V_35 , V_102 , sizeof( V_85 ) , & V_85 ) ;
}
static void F_53 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_103 V_85 ;
if ( ! F_34 ( V_6 ) )
return;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
if ( F_2 ( V_6 , V_69 ) ) {
V_85 . V_104 = 0x01 ;
V_85 . V_105 = 0x00 ;
}
if ( V_85 . V_104 != F_54 ( V_6 ) )
F_25 ( V_35 , V_106 , sizeof( V_85 ) ,
& V_85 ) ;
}
static void F_55 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
T_7 V_70 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
bool V_107 = false ;
if ( F_56 ( V_6 ) ) {
V_70 [ 1 ] |= 0x40 ;
V_70 [ 1 ] |= 0x80 ;
V_70 [ 2 ] |= 0x10 ;
V_70 [ 2 ] |= 0x20 ;
V_107 = true ;
}
if ( F_57 ( V_6 ) ) {
V_70 [ 2 ] |= 0x01 ;
V_70 [ 2 ] |= 0x02 ;
V_70 [ 2 ] |= 0x04 ;
V_70 [ 2 ] |= 0x08 ;
V_107 = true ;
}
if ( F_58 ( V_6 ) || V_6 -> V_73 [ 0 ] & V_108 ) {
V_70 [ 2 ] |= 0x80 ;
V_107 = true ;
}
if ( V_107 )
F_25 ( V_35 , V_109 ,
sizeof( V_70 ) , V_70 ) ;
}
static int F_59 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
T_7 V_110 ;
F_35 ( V_35 ) ;
if ( V_6 -> V_50 [ 6 ] & 0x20 &&
! F_6 ( V_111 , & V_6 -> V_26 ) ) {
struct V_112 V_85 ;
F_60 ( & V_85 . V_113 , V_114 ) ;
V_85 . V_115 = 0x01 ;
F_25 ( V_35 , V_116 , sizeof( V_85 ) , & V_85 ) ;
}
if ( V_6 -> V_50 [ 5 ] & 0x10 )
F_48 ( V_35 ) ;
if ( V_6 -> V_50 [ 8 ] & 0x01 )
F_25 ( V_35 , V_117 , 0 , NULL ) ;
if ( V_6 -> V_50 [ 13 ] & 0x01 )
F_25 ( V_35 , V_118 , 0 , NULL ) ;
if ( F_45 ( V_6 ) ) {
T_7 V_70 [ 8 ] ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_6 -> V_73 [ 0 ] & V_74 )
V_70 [ 0 ] |= 0x10 ;
if ( V_6 -> V_73 [ 0 ] & V_119 )
V_70 [ 0 ] |= 0x20 ;
if ( V_6 -> V_73 [ 0 ] & V_120 )
V_70 [ 0 ] |= 0x40 ;
if ( V_6 -> V_73 [ 0 ] & V_121 )
V_70 [ 1 ] |= 0x04 ;
if ( V_6 -> V_73 [ 1 ] & V_122 )
V_70 [ 2 ] |= 0x08 ;
if ( V_6 -> V_50 [ 26 ] & 0x08 )
V_70 [ 0 ] |= 0x02 ;
if ( V_6 -> V_50 [ 26 ] & 0x10 )
V_70 [ 0 ] |= 0x01 ;
if ( V_6 -> V_50 [ 27 ] & 0x04 )
V_70 [ 0 ] |= 0x04 ;
if ( V_6 -> V_50 [ 27 ] & 0x20 )
V_70 [ 0 ] |= 0x08 ;
if ( V_6 -> V_50 [ 34 ] & 0x02 )
V_70 [ 0 ] |= 0x80 ;
if ( V_6 -> V_50 [ 34 ] & 0x04 )
V_70 [ 1 ] |= 0x01 ;
if ( V_6 -> V_50 [ 35 ] & ( 0x20 | 0x40 ) )
V_70 [ 1 ] |= 0x08 ;
F_25 ( V_35 , V_123 , sizeof( V_70 ) ,
V_70 ) ;
if ( V_6 -> V_50 [ 25 ] & 0x40 ) {
F_25 ( V_35 , V_124 , 0 , NULL ) ;
}
if ( V_6 -> V_50 [ 26 ] & 0x40 ) {
F_25 ( V_35 , V_125 ,
0 , NULL ) ;
}
if ( V_6 -> V_50 [ 26 ] & 0x80 ) {
F_25 ( V_35 , V_126 , 0 , NULL ) ;
}
if ( V_6 -> V_73 [ 0 ] & V_120 ) {
F_25 ( V_35 , V_127 , 0 , NULL ) ;
F_25 ( V_35 , V_128 , 0 , NULL ) ;
}
F_53 ( V_35 ) ;
}
for ( V_110 = 2 ; V_110 < V_129 && V_110 <= V_6 -> V_80 ; V_110 ++ ) {
struct V_90 V_85 ;
V_85 . V_91 = V_110 ;
F_25 ( V_35 , V_92 ,
sizeof( V_85 ) , & V_85 ) ;
}
return 0 ;
}
static int F_61 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
if ( V_6 -> V_50 [ 6 ] & 0x80 &&
! F_6 ( V_111 , & V_6 -> V_26 ) ) {
struct V_130 V_85 ;
F_60 ( & V_85 . V_113 , V_114 ) ;
V_85 . V_131 = 0x01 ;
F_25 ( V_35 , V_132 ,
sizeof( V_85 ) , & V_85 ) ;
}
if ( V_6 -> V_50 [ 22 ] & 0x04 )
F_55 ( V_35 ) ;
if ( V_6 -> V_50 [ 29 ] & 0x20 )
F_25 ( V_35 , V_133 , 0 , NULL ) ;
if ( V_6 -> V_50 [ 30 ] & 0x08 )
F_25 ( V_35 , V_134 , 0 , NULL ) ;
if ( F_62 ( V_6 ) )
F_25 ( V_35 , V_135 , 0 , NULL ) ;
if ( F_2 ( V_6 , V_81 ) &&
F_63 ( V_6 ) ) {
T_7 V_136 = 0x01 ;
F_25 ( V_35 , V_137 ,
sizeof( V_136 ) , & V_136 ) ;
}
if ( V_6 -> V_73 [ 0 ] & V_120 ) {
struct V_138 V_85 ;
V_85 . V_139 = V_6 -> V_140 ;
V_85 . V_141 = V_6 -> V_142 ;
F_25 ( V_35 , V_143 , sizeof( V_85 ) , & V_85 ) ;
}
if ( V_6 -> V_50 [ 35 ] & 0x20 ) {
struct V_144 V_85 ;
V_85 . V_145 = 0x03 ;
V_85 . V_146 = 0 ;
V_85 . V_147 = 0 ;
F_25 ( V_35 , V_148 , sizeof( V_85 ) , & V_85 ) ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 )
{
int V_24 ;
V_24 = F_65 ( V_6 , F_29 , 0 , V_149 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_2 ( V_6 , V_150 ) )
F_20 ( V_6 ) ;
V_24 = F_65 ( V_6 , F_46 , 0 , V_149 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_6 -> V_52 != V_53 )
return 0 ;
V_24 = F_65 ( V_6 , F_59 , 0 , V_149 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_65 ( V_6 , F_61 , 0 , V_149 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! F_2 ( V_6 , V_150 ) &&
! F_2 ( V_6 , V_151 ) )
return 0 ;
F_66 ( V_6 ) ;
if ( F_34 ( V_6 ) )
F_67 ( V_6 ) ;
if ( F_45 ( V_6 ) )
F_68 ( V_6 ) ;
return 0 ;
}
static int F_69 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
F_23 ( L_3 , V_6 -> V_37 , V_36 ) ;
if ( ! F_6 ( V_51 , & V_6 -> V_26 ) )
F_22 ( V_35 , 0 ) ;
F_25 ( V_35 , V_42 , 0 , NULL ) ;
if ( V_6 -> V_152 )
F_25 ( V_35 , V_43 , 0 , NULL ) ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 )
{
int V_24 ;
if ( F_6 ( V_153 , & V_6 -> V_26 ) )
return 0 ;
V_24 = F_65 ( V_6 , F_69 , 0 , V_149 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_2 ( V_6 , V_150 ) )
F_20 ( V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_34 * V_35 , unsigned long V_36 )
{
T_6 V_154 = V_36 ;
F_23 ( L_5 , V_35 -> V_6 -> V_37 , V_154 ) ;
F_25 ( V_35 , V_155 , 1 , & V_154 ) ;
return 0 ;
}
static int F_72 ( struct V_34 * V_35 , unsigned long V_36 )
{
T_6 V_156 = V_36 ;
F_23 ( L_5 , V_35 -> V_6 -> V_37 , V_156 ) ;
F_25 ( V_35 , V_94 , 1 , & V_156 ) ;
return 0 ;
}
static int F_73 ( struct V_34 * V_35 , unsigned long V_36 )
{
T_6 V_157 = V_36 ;
F_23 ( L_5 , V_35 -> V_6 -> V_37 , V_157 ) ;
F_25 ( V_35 , V_158 , 1 , & V_157 ) ;
return 0 ;
}
static int F_74 ( struct V_34 * V_35 , unsigned long V_36 )
{
T_5 V_101 = F_32 ( V_36 ) ;
F_23 ( L_5 , V_35 -> V_6 -> V_37 , V_101 ) ;
F_25 ( V_35 , V_102 , 2 , & V_101 ) ;
return 0 ;
}
struct V_5 * F_75 ( int V_159 )
{
struct V_5 * V_6 = NULL , * V_160 ;
F_23 ( L_6 , V_159 ) ;
if ( V_159 < 0 )
return NULL ;
F_76 ( & V_161 ) ;
F_77 (d, &hci_dev_list, list) {
if ( V_160 -> V_162 == V_159 ) {
V_6 = F_78 ( V_160 ) ;
break;
}
}
F_79 ( & V_161 ) ;
return V_6 ;
}
bool F_80 ( struct V_5 * V_6 )
{
struct V_163 * V_164 = & V_6 -> V_165 ;
switch ( V_164 -> V_166 ) {
case V_167 :
case V_168 :
return true ;
default:
return false ;
}
}
void F_81 ( struct V_5 * V_6 , int V_166 )
{
int V_169 = V_6 -> V_165 . V_166 ;
F_23 ( L_7 , V_6 -> V_37 , V_6 -> V_165 . V_166 , V_166 ) ;
if ( V_169 == V_166 )
return;
V_6 -> V_165 . V_166 = V_166 ;
switch ( V_166 ) {
case V_170 :
F_82 ( V_6 ) ;
if ( V_169 != V_171 )
F_83 ( V_6 , 0 ) ;
break;
case V_171 :
break;
case V_167 :
F_83 ( V_6 , 1 ) ;
break;
case V_168 :
break;
case V_172 :
break;
}
}
void F_84 ( struct V_5 * V_6 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_174 * V_110 , * V_175 ;
F_85 (p, n, &cache->all, all) {
F_86 ( & V_110 -> V_176 ) ;
F_87 ( V_110 ) ;
}
F_88 ( & V_173 -> V_177 ) ;
F_88 ( & V_173 -> V_178 ) ;
}
struct V_174 * F_89 ( struct V_5 * V_6 ,
T_9 * V_113 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_174 * V_179 ;
F_23 ( L_8 , V_173 , V_113 ) ;
F_77 (e, &cache->all, all) {
if ( ! F_90 ( & V_179 -> V_180 . V_113 , V_113 ) )
return V_179 ;
}
return NULL ;
}
struct V_174 * F_91 ( struct V_5 * V_6 ,
T_9 * V_113 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_174 * V_179 ;
F_23 ( L_8 , V_173 , V_113 ) ;
F_77 (e, &cache->unknown, list) {
if ( ! F_90 ( & V_179 -> V_180 . V_113 , V_113 ) )
return V_179 ;
}
return NULL ;
}
struct V_174 * F_92 ( struct V_5 * V_6 ,
T_9 * V_113 ,
int V_166 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_174 * V_179 ;
F_23 ( L_9 , V_173 , V_113 , V_166 ) ;
F_77 (e, &cache->resolve, list) {
if ( ! F_90 ( V_113 , V_114 ) && V_179 -> V_181 == V_166 )
return V_179 ;
if ( ! F_90 ( & V_179 -> V_180 . V_113 , V_113 ) )
return V_179 ;
}
return NULL ;
}
void F_93 ( struct V_5 * V_6 ,
struct V_174 * V_182 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_183 * V_184 = & V_173 -> V_178 ;
struct V_174 * V_110 ;
F_86 ( & V_182 -> V_185 ) ;
F_77 (p, &cache->resolve, list) {
if ( V_110 -> V_181 != V_186 &&
abs ( V_110 -> V_180 . V_187 ) >= abs ( V_182 -> V_180 . V_187 ) )
break;
V_184 = & V_110 -> V_185 ;
}
F_94 ( & V_182 -> V_185 , V_184 ) ;
}
T_10 F_95 ( struct V_5 * V_6 , struct V_188 * V_180 ,
bool V_189 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_174 * V_182 ;
T_10 V_15 = 0 ;
F_23 ( L_8 , V_173 , & V_180 -> V_113 ) ;
F_96 ( V_6 , & V_180 -> V_113 , V_190 ) ;
if ( ! V_180 -> V_191 )
V_15 |= V_192 ;
V_182 = F_89 ( V_6 , & V_180 -> V_113 ) ;
if ( V_182 ) {
if ( ! V_182 -> V_180 . V_191 )
V_15 |= V_192 ;
if ( V_182 -> V_181 == V_193 &&
V_180 -> V_187 != V_182 -> V_180 . V_187 ) {
V_182 -> V_180 . V_187 = V_180 -> V_187 ;
F_93 ( V_6 , V_182 ) ;
}
goto V_194;
}
V_182 = F_97 ( sizeof( * V_182 ) , V_195 ) ;
if ( ! V_182 ) {
V_15 |= V_196 ;
goto V_29;
}
F_94 ( & V_182 -> V_176 , & V_173 -> V_176 ) ;
if ( V_189 ) {
V_182 -> V_181 = V_197 ;
} else {
V_182 -> V_181 = V_198 ;
F_94 ( & V_182 -> V_185 , & V_173 -> V_177 ) ;
}
V_194:
if ( V_189 && V_182 -> V_181 != V_197 &&
V_182 -> V_181 != V_186 ) {
V_182 -> V_181 = V_197 ;
F_86 ( & V_182 -> V_185 ) ;
}
memcpy ( & V_182 -> V_180 , V_180 , sizeof( * V_180 ) ) ;
V_182 -> V_199 = V_200 ;
V_173 -> V_199 = V_200 ;
if ( V_182 -> V_181 == V_198 )
V_15 |= V_196 ;
V_29:
return V_15 ;
}
static int F_98 ( struct V_5 * V_6 , int V_201 , T_6 * V_8 )
{
struct V_163 * V_173 = & V_6 -> V_165 ;
struct V_202 * V_203 = (struct V_202 * ) V_8 ;
struct V_174 * V_179 ;
int V_204 = 0 ;
F_77 (e, &cache->all, all) {
struct V_188 * V_180 = & V_179 -> V_180 ;
if ( V_204 >= V_201 )
break;
F_60 ( & V_203 -> V_113 , & V_180 -> V_113 ) ;
V_203 -> V_205 = V_180 -> V_205 ;
V_203 -> V_206 = V_180 -> V_206 ;
V_203 -> V_207 = V_180 -> V_207 ;
memcpy ( V_203 -> V_208 , V_180 -> V_208 , 3 ) ;
V_203 -> V_209 = V_180 -> V_209 ;
V_203 ++ ;
V_204 ++ ;
}
F_23 ( L_10 , V_173 , V_204 ) ;
return V_204 ;
}
static int F_99 ( struct V_34 * V_35 , unsigned long V_36 )
{
struct V_210 * V_211 = (struct V_210 * ) V_36 ;
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_212 V_85 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( F_6 ( V_213 , & V_6 -> V_15 ) )
return 0 ;
memcpy ( & V_85 . V_214 , & V_211 -> V_214 , 3 ) ;
V_85 . V_215 = V_211 -> V_215 ;
V_85 . V_216 = V_211 -> V_216 ;
F_25 ( V_35 , V_217 , sizeof( V_85 ) , & V_85 ) ;
return 0 ;
}
int F_100 ( void T_2 * V_218 )
{
T_6 T_2 * V_219 = V_218 ;
struct V_210 V_211 ;
struct V_5 * V_6 ;
int V_24 = 0 , V_220 = 0 , V_221 ;
long V_222 ;
T_6 * V_8 ;
if ( F_7 ( & V_211 , V_219 , sizeof( V_211 ) ) )
return - V_17 ;
V_6 = F_75 ( V_211 . V_223 ) ;
if ( ! V_6 )
return - V_224 ;
if ( F_2 ( V_6 , V_28 ) ) {
V_24 = - V_225 ;
goto V_29;
}
if ( F_2 ( V_6 , V_226 ) ) {
V_24 = - V_227 ;
goto V_29;
}
if ( V_6 -> V_52 != V_53 ) {
V_24 = - V_227 ;
goto V_29;
}
if ( ! F_2 ( V_6 , V_77 ) ) {
V_24 = - V_227 ;
goto V_29;
}
F_101 ( V_6 ) ;
if ( F_102 ( V_6 ) > V_228 ||
F_103 ( V_6 ) || V_211 . V_15 & V_229 ) {
F_84 ( V_6 ) ;
V_220 = 1 ;
}
F_104 ( V_6 ) ;
V_222 = V_211 . V_215 * F_105 ( 2000 ) ;
if ( V_220 ) {
V_24 = F_106 ( V_6 , F_99 , ( unsigned long ) & V_211 ,
V_222 , NULL ) ;
if ( V_24 < 0 )
goto V_29;
if ( F_107 ( & V_6 -> V_15 , V_213 ,
V_230 ) )
return - V_231 ;
}
V_221 = ( V_211 . V_216 == 0 ) ? 255 : V_211 . V_216 ;
V_8 = F_108 ( sizeof( struct V_202 ) * V_221 , V_195 ) ;
if ( ! V_8 ) {
V_24 = - V_232 ;
goto V_29;
}
F_101 ( V_6 ) ;
V_211 . V_216 = F_98 ( V_6 , V_221 , V_8 ) ;
F_104 ( V_6 ) ;
F_23 ( L_12 , V_211 . V_216 ) ;
if ( ! F_109 ( V_219 , & V_211 , sizeof( V_211 ) ) ) {
V_219 += sizeof( V_211 ) ;
if ( F_109 ( V_219 , V_8 , sizeof( struct V_202 ) *
V_211 . V_216 ) )
V_24 = - V_17 ;
} else
V_24 = - V_17 ;
F_87 ( V_8 ) ;
V_29:
F_110 ( V_6 ) ;
return V_24 ;
}
static int F_111 ( struct V_5 * V_6 )
{
int V_233 = 0 ;
F_23 ( L_13 , V_6 -> V_37 , V_6 ) ;
F_9 ( V_6 ) ;
if ( F_2 ( V_6 , V_234 ) ) {
V_233 = - V_224 ;
goto V_29;
}
if ( ! F_2 ( V_6 , V_150 ) &&
! F_2 ( V_6 , V_151 ) ) {
if ( F_2 ( V_6 , V_235 ) ) {
V_233 = - V_236 ;
goto V_29;
}
if ( ! F_2 ( V_6 , V_28 ) &&
V_6 -> V_52 == V_53 &&
! F_90 ( & V_6 -> V_113 , V_114 ) &&
! F_90 ( & V_6 -> V_237 , V_114 ) ) {
V_233 = - V_238 ;
goto V_29;
}
}
if ( F_6 ( V_14 , & V_6 -> V_15 ) ) {
V_233 = - V_19 ;
goto V_29;
}
if ( V_6 -> V_239 ( V_6 ) ) {
V_233 = - V_240 ;
goto V_29;
}
F_24 ( V_27 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_241 ) ;
F_113 ( & V_6 -> V_242 , 1 ) ;
F_24 ( V_243 , & V_6 -> V_15 ) ;
if ( F_2 ( V_6 , V_150 ) ) {
F_112 ( V_6 , V_244 ) ;
if ( V_6 -> V_245 )
V_233 = V_6 -> V_245 ( V_6 ) ;
if ( F_6 ( V_246 , & V_6 -> V_26 ) ||
F_6 ( V_247 , & V_6 -> V_26 ) )
F_18 ( V_6 , V_226 ) ;
if ( F_2 ( V_6 , V_226 ) )
V_233 = F_70 ( V_6 ) ;
}
if ( F_2 ( V_6 , V_151 ) ) {
if ( F_90 ( & V_6 -> V_248 , V_114 ) &&
V_6 -> V_152 )
V_233 = V_6 -> V_152 ( V_6 , & V_6 -> V_248 ) ;
else
V_233 = - V_238 ;
}
if ( ! V_233 ) {
if ( ! F_2 ( V_6 , V_226 ) &&
! F_2 ( V_6 , V_28 ) ) {
V_233 = F_64 ( V_6 ) ;
if ( ! V_233 && V_6 -> V_249 )
V_233 = V_6 -> V_249 ( V_6 ) ;
}
}
if ( F_6 ( V_25 , & V_6 -> V_26 ) &&
! F_2 ( V_6 , V_28 ) &&
F_2 ( V_6 , V_23 ) && V_6 -> V_30 )
V_233 = V_6 -> V_30 ( V_6 , true ) ;
F_114 ( V_243 , & V_6 -> V_15 ) ;
if ( ! V_233 ) {
F_78 ( V_6 ) ;
F_18 ( V_6 , V_250 ) ;
F_24 ( V_14 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_251 ) ;
F_115 ( V_6 , true ) ;
if ( ! F_2 ( V_6 , V_150 ) &&
! F_2 ( V_6 , V_151 ) &&
! F_2 ( V_6 , V_226 ) &&
! F_2 ( V_6 , V_28 ) &&
F_2 ( V_6 , V_252 ) &&
V_6 -> V_52 == V_53 ) {
V_233 = F_116 ( V_6 ) ;
F_117 ( V_6 , V_233 ) ;
}
} else {
F_118 ( & V_6 -> V_253 ) ;
F_118 ( & V_6 -> V_254 ) ;
F_118 ( & V_6 -> V_255 ) ;
F_119 ( & V_6 -> V_256 ) ;
F_119 ( & V_6 -> V_257 ) ;
if ( V_6 -> V_258 )
V_6 -> V_258 ( V_6 ) ;
if ( V_6 -> V_259 ) {
F_14 ( V_6 -> V_259 ) ;
V_6 -> V_259 = NULL ;
}
F_114 ( V_27 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_260 ) ;
V_6 -> V_261 ( V_6 ) ;
V_6 -> V_15 &= F_120 ( V_262 ) ;
}
V_29:
F_11 ( V_6 ) ;
return V_233 ;
}
int F_121 ( T_11 V_263 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_75 ( V_263 ) ;
if ( ! V_6 )
return - V_224 ;
if ( F_2 ( V_6 , V_226 ) &&
! F_2 ( V_6 , V_28 ) ) {
V_24 = - V_227 ;
goto V_29;
}
if ( F_122 ( V_6 , V_264 ) )
F_123 ( & V_6 -> V_265 ) ;
F_124 ( V_6 -> V_266 ) ;
if ( ! F_2 ( V_6 , V_28 ) &&
! F_2 ( V_6 , V_252 ) )
F_18 ( V_6 , V_267 ) ;
V_24 = F_111 ( V_6 ) ;
V_29:
F_110 ( V_6 ) ;
return V_24 ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_268 * V_110 ;
F_77 (p, &hdev->le_conn_params, list) {
if ( V_110 -> V_269 ) {
F_126 ( V_110 -> V_269 ) ;
F_127 ( V_110 -> V_269 ) ;
V_110 -> V_269 = NULL ;
}
F_128 ( & V_110 -> V_270 ) ;
}
F_23 ( L_14 ) ;
}
int F_129 ( struct V_5 * V_6 )
{
bool V_271 ;
F_23 ( L_13 , V_6 -> V_37 , V_6 ) ;
if ( ! F_2 ( V_6 , V_234 ) &&
! F_2 ( V_6 , V_28 ) &&
F_6 ( V_14 , & V_6 -> V_15 ) ) {
if ( V_6 -> V_272 )
V_6 -> V_272 ( V_6 ) ;
}
F_123 ( & V_6 -> V_265 ) ;
F_130 ( V_6 ) ;
F_9 ( V_6 ) ;
if ( ! F_131 ( V_14 , & V_6 -> V_15 ) ) {
F_132 ( & V_6 -> V_273 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
F_115 ( V_6 , false ) ;
F_118 ( & V_6 -> V_253 ) ;
F_118 ( & V_6 -> V_255 ) ;
if ( V_6 -> V_274 > 0 ) {
V_6 -> V_274 = 0 ;
F_19 ( V_6 , V_275 ) ;
F_19 ( V_6 , V_276 ) ;
}
if ( F_122 ( V_6 , V_277 ) )
F_123 ( & V_6 -> V_278 ) ;
if ( F_2 ( V_6 , V_252 ) )
F_132 ( & V_6 -> V_279 ) ;
F_133 ( V_6 -> V_280 ) ;
F_101 ( V_6 ) ;
F_81 ( V_6 , V_170 ) ;
V_271 = F_122 ( V_6 , V_264 ) ;
if ( ! V_271 && V_6 -> V_52 == V_53 &&
! F_2 ( V_6 , V_28 ) &&
F_2 ( V_6 , V_252 ) )
F_134 ( V_6 ) ;
F_84 ( V_6 ) ;
F_125 ( V_6 ) ;
F_135 ( V_6 ) ;
F_104 ( V_6 ) ;
F_136 ( V_6 ) ;
F_112 ( V_6 , V_281 ) ;
if ( V_6 -> V_258 )
V_6 -> V_258 ( V_6 ) ;
F_119 ( & V_6 -> V_256 ) ;
F_113 ( & V_6 -> V_242 , 1 ) ;
if ( F_6 ( V_51 , & V_6 -> V_26 ) &&
! V_271 && ! F_2 ( V_6 , V_226 ) ) {
F_24 ( V_243 , & V_6 -> V_15 ) ;
F_65 ( V_6 , F_22 , 0 , V_21 , NULL ) ;
F_114 ( V_243 , & V_6 -> V_15 ) ;
}
F_118 ( & V_6 -> V_254 ) ;
F_119 ( & V_6 -> V_257 ) ;
F_119 ( & V_6 -> V_256 ) ;
F_119 ( & V_6 -> V_282 ) ;
if ( V_6 -> V_259 ) {
F_132 ( & V_6 -> V_273 ) ;
F_14 ( V_6 -> V_259 ) ;
V_6 -> V_259 = NULL ;
}
F_114 ( V_27 , & V_6 -> V_15 ) ;
F_112 ( V_6 , V_260 ) ;
V_6 -> V_261 ( V_6 ) ;
V_6 -> V_15 &= F_120 ( V_262 ) ;
F_137 ( V_6 ) ;
V_6 -> V_283 = V_284 ;
memset ( V_6 -> V_86 , 0 , sizeof( V_6 -> V_86 ) ) ;
memset ( V_6 -> V_208 , 0 , sizeof( V_6 -> V_208 ) ) ;
F_60 ( & V_6 -> V_285 , V_114 ) ;
F_11 ( V_6 ) ;
F_110 ( V_6 ) ;
return 0 ;
}
int F_138 ( T_11 V_263 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_75 ( V_263 ) ;
if ( ! V_6 )
return - V_224 ;
if ( F_2 ( V_6 , V_28 ) ) {
V_24 = - V_225 ;
goto V_29;
}
if ( F_122 ( V_6 , V_264 ) )
F_123 ( & V_6 -> V_265 ) ;
V_24 = F_129 ( V_6 ) ;
V_29:
F_110 ( V_6 ) ;
return V_24 ;
}
static int F_139 ( struct V_5 * V_6 )
{
int V_233 ;
F_23 ( L_13 , V_6 -> V_37 , V_6 ) ;
F_9 ( V_6 ) ;
F_119 ( & V_6 -> V_257 ) ;
F_119 ( & V_6 -> V_256 ) ;
F_133 ( V_6 -> V_280 ) ;
F_101 ( V_6 ) ;
F_84 ( V_6 ) ;
F_135 ( V_6 ) ;
F_104 ( V_6 ) ;
if ( V_6 -> V_258 )
V_6 -> V_258 ( V_6 ) ;
F_113 ( & V_6 -> V_242 , 1 ) ;
V_6 -> V_286 = 0 ; V_6 -> V_287 = 0 ; V_6 -> V_288 = 0 ;
V_233 = F_65 ( V_6 , F_22 , 0 , V_149 , NULL ) ;
F_11 ( V_6 ) ;
return V_233 ;
}
int F_140 ( T_11 V_263 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_75 ( V_263 ) ;
if ( ! V_6 )
return - V_224 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) ) {
V_24 = - V_16 ;
goto V_29;
}
if ( F_2 ( V_6 , V_28 ) ) {
V_24 = - V_225 ;
goto V_29;
}
if ( F_2 ( V_6 , V_226 ) ) {
V_24 = - V_227 ;
goto V_29;
}
V_24 = F_139 ( V_6 ) ;
V_29:
F_110 ( V_6 ) ;
return V_24 ;
}
int F_141 ( T_11 V_263 )
{
struct V_5 * V_6 ;
int V_233 = 0 ;
V_6 = F_75 ( V_263 ) ;
if ( ! V_6 )
return - V_224 ;
if ( F_2 ( V_6 , V_28 ) ) {
V_233 = - V_225 ;
goto V_29;
}
if ( F_2 ( V_6 , V_226 ) ) {
V_233 = - V_227 ;
goto V_29;
}
memset ( & V_6 -> V_289 , 0 , sizeof( struct V_290 ) ) ;
V_29:
F_110 ( V_6 ) ;
return V_233 ;
}
static void F_142 ( struct V_5 * V_6 , T_7 V_154 )
{
bool V_291 , V_292 ;
F_23 ( L_15 , V_6 -> V_37 , V_154 ) ;
if ( ( V_154 & V_293 ) )
V_291 = ! F_143 ( V_6 ,
V_294 ) ;
else
V_291 = F_122 ( V_6 ,
V_294 ) ;
if ( ( V_154 & V_295 ) ) {
V_292 = ! F_143 ( V_6 ,
V_275 ) ;
} else {
F_19 ( V_6 , V_276 ) ;
V_292 = F_122 ( V_6 ,
V_275 ) ;
}
if ( ! F_2 ( V_6 , V_252 ) )
return;
if ( V_291 || V_292 ) {
F_18 ( V_6 , V_77 ) ;
if ( F_2 ( V_6 , V_69 ) )
F_144 ( V_6 , V_6 -> V_296 ) ;
F_145 ( V_6 ) ;
}
}
int F_146 ( unsigned int V_297 , void T_2 * V_218 )
{
struct V_5 * V_6 ;
struct V_298 V_299 ;
int V_24 = 0 ;
if ( F_7 ( & V_299 , V_218 , sizeof( V_299 ) ) )
return - V_17 ;
V_6 = F_75 ( V_299 . V_223 ) ;
if ( ! V_6 )
return - V_224 ;
if ( F_2 ( V_6 , V_28 ) ) {
V_24 = - V_225 ;
goto V_29;
}
if ( F_2 ( V_6 , V_226 ) ) {
V_24 = - V_227 ;
goto V_29;
}
if ( V_6 -> V_52 != V_53 ) {
V_24 = - V_227 ;
goto V_29;
}
if ( ! F_2 ( V_6 , V_77 ) ) {
V_24 = - V_227 ;
goto V_29;
}
switch ( V_297 ) {
case V_300 :
V_24 = F_106 ( V_6 , F_72 , V_299 . V_301 ,
V_149 , NULL ) ;
break;
case V_302 :
if ( ! F_147 ( V_6 ) ) {
V_24 = - V_227 ;
break;
}
if ( ! F_6 ( V_303 , & V_6 -> V_15 ) ) {
V_24 = F_106 ( V_6 , F_72 , V_299 . V_301 ,
V_149 , NULL ) ;
if ( V_24 )
break;
}
V_24 = F_106 ( V_6 , F_73 , V_299 . V_301 ,
V_149 , NULL ) ;
break;
case V_304 :
V_24 = F_106 ( V_6 , F_71 , V_299 . V_301 ,
V_149 , NULL ) ;
if ( ! V_24 )
F_142 ( V_6 , V_299 . V_301 ) ;
break;
case V_305 :
V_24 = F_106 ( V_6 , F_74 , V_299 . V_301 ,
V_149 , NULL ) ;
break;
case V_306 :
V_6 -> V_307 = ( ( T_11 ) V_299 . V_301 ) &
( V_308 | V_309 ) ;
break;
case V_310 :
V_6 -> V_311 = ( T_11 ) V_299 . V_301 ;
break;
case V_312 :
V_6 -> V_313 = * ( ( T_11 * ) & V_299 . V_301 + 1 ) ;
V_6 -> V_314 = * ( ( T_11 * ) & V_299 . V_301 + 0 ) ;
break;
case V_315 :
V_6 -> V_316 = * ( ( T_11 * ) & V_299 . V_301 + 1 ) ;
V_6 -> V_317 = * ( ( T_11 * ) & V_299 . V_301 + 0 ) ;
break;
default:
V_24 = - V_18 ;
break;
}
V_29:
F_110 ( V_6 ) ;
return V_24 ;
}
int F_148 ( void T_2 * V_218 )
{
struct V_5 * V_6 ;
struct V_318 * V_319 ;
struct V_298 * V_299 ;
int V_175 = 0 , V_320 , V_24 ;
T_11 V_321 ;
if ( F_149 ( V_321 , ( T_11 T_2 * ) V_218 ) )
return - V_17 ;
if ( ! V_321 || V_321 > ( V_322 * 2 ) / sizeof( * V_299 ) )
return - V_18 ;
V_320 = sizeof( * V_319 ) + V_321 * sizeof( * V_299 ) ;
V_319 = F_97 ( V_320 , V_195 ) ;
if ( ! V_319 )
return - V_232 ;
V_299 = V_319 -> V_323 ;
F_76 ( & V_161 ) ;
F_77 (hdev, &hci_dev_list, list) {
unsigned long V_15 = V_6 -> V_15 ;
if ( F_2 ( V_6 , V_264 ) )
V_15 &= ~ F_120 ( V_14 ) ;
( V_299 + V_175 ) -> V_223 = V_6 -> V_162 ;
( V_299 + V_175 ) -> V_301 = V_15 ;
if ( ++ V_175 >= V_321 )
break;
}
F_79 ( & V_161 ) ;
V_319 -> V_321 = V_175 ;
V_320 = sizeof( * V_319 ) + V_175 * sizeof( * V_299 ) ;
V_24 = F_109 ( V_218 , V_319 , V_320 ) ;
F_87 ( V_319 ) ;
return V_24 ? - V_17 : 0 ;
}
int F_150 ( void T_2 * V_218 )
{
struct V_5 * V_6 ;
struct V_324 V_325 ;
unsigned long V_15 ;
int V_24 = 0 ;
if ( F_7 ( & V_325 , V_218 , sizeof( V_325 ) ) )
return - V_17 ;
V_6 = F_75 ( V_325 . V_223 ) ;
if ( ! V_6 )
return - V_224 ;
if ( F_2 ( V_6 , V_264 ) )
V_15 = V_6 -> V_15 & ~ F_120 ( V_14 ) ;
else
V_15 = V_6 -> V_15 ;
strcpy ( V_325 . V_37 , V_6 -> V_37 ) ;
V_325 . V_113 = V_6 -> V_113 ;
V_325 . type = ( V_6 -> V_326 & 0x0f ) | ( ( V_6 -> V_52 & 0x03 ) << 4 ) ;
V_325 . V_15 = V_15 ;
V_325 . V_311 = V_6 -> V_311 ;
if ( F_34 ( V_6 ) ) {
V_325 . V_313 = V_6 -> V_313 ;
V_325 . V_314 = V_6 -> V_314 ;
V_325 . V_316 = V_6 -> V_316 ;
V_325 . V_317 = V_6 -> V_317 ;
} else {
V_325 . V_313 = V_6 -> V_327 ;
V_325 . V_314 = V_6 -> V_328 ;
V_325 . V_316 = 0 ;
V_325 . V_317 = 0 ;
}
V_325 . V_96 = V_6 -> V_96 ;
V_325 . V_307 = V_6 -> V_307 ;
memcpy ( & V_325 . V_289 , & V_6 -> V_289 , sizeof( V_325 . V_289 ) ) ;
memcpy ( & V_325 . V_329 , & V_6 -> V_329 , sizeof( V_325 . V_329 ) ) ;
if ( F_109 ( V_218 , & V_325 , sizeof( V_325 ) ) )
V_24 = - V_17 ;
F_110 ( V_6 ) ;
return V_24 ;
}
static int F_151 ( void * V_180 , bool V_330 )
{
struct V_5 * V_6 = V_180 ;
F_23 ( L_16 , V_6 , V_6 -> V_37 , V_330 ) ;
if ( F_2 ( V_6 , V_28 ) )
return - V_225 ;
if ( V_330 ) {
F_18 ( V_6 , V_235 ) ;
if ( ! F_2 ( V_6 , V_150 ) &&
! F_2 ( V_6 , V_151 ) )
F_129 ( V_6 ) ;
} else {
F_19 ( V_6 , V_235 ) ;
}
return 0 ;
}
static void F_152 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 , V_333 ) ;
int V_24 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( F_6 ( V_14 , & V_6 -> V_15 ) &&
F_2 ( V_6 , V_252 ) &&
F_122 ( V_6 , V_264 ) ) {
F_123 ( & V_6 -> V_265 ) ;
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
if ( F_2 ( V_6 , V_235 ) ||
F_2 ( V_6 , V_226 ) ||
( V_6 -> V_52 == V_53 &&
! F_90 ( & V_6 -> V_113 , V_114 ) &&
! F_90 ( & V_6 -> V_237 , V_114 ) ) ) {
F_19 ( V_6 , V_264 ) ;
F_129 ( V_6 ) ;
} else if ( F_2 ( V_6 , V_264 ) ) {
F_155 ( V_6 -> V_266 , & V_6 -> V_265 ,
V_334 ) ;
}
if ( F_122 ( V_6 , V_150 ) ) {
if ( F_2 ( V_6 , V_226 ) )
F_24 ( V_262 , & V_6 -> V_15 ) ;
F_156 ( V_6 ) ;
} else if ( F_122 ( V_6 , V_151 ) ) {
if ( ! F_2 ( V_6 , V_226 ) )
F_114 ( V_262 , & V_6 -> V_15 ) ;
F_156 ( V_6 ) ;
}
}
static void F_157 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 ,
V_265 . V_332 ) ;
F_23 ( L_11 , V_6 -> V_37 ) ;
F_129 ( V_6 ) ;
}
static void F_158 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 , V_335 ) ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( V_6 -> V_336 )
V_6 -> V_336 ( V_6 , V_6 -> V_337 ) ;
else
F_30 ( L_17 , V_6 -> V_37 ,
V_6 -> V_337 ) ;
if ( F_129 ( V_6 ) )
return;
F_111 ( V_6 ) ;
}
void F_159 ( struct V_5 * V_6 )
{
struct V_338 * V_339 , * V_340 ;
F_85 (uuid, tmp, &hdev->uuids, list) {
F_86 ( & V_339 -> V_185 ) ;
F_87 ( V_339 ) ;
}
}
void F_160 ( struct V_5 * V_6 )
{
struct V_341 * V_342 ;
F_161 (key, &hdev->link_keys, list) {
F_162 ( & V_342 -> V_185 ) ;
F_163 ( V_342 , V_343 ) ;
}
}
void F_164 ( struct V_5 * V_6 )
{
struct V_344 * V_345 ;
F_161 (k, &hdev->long_term_keys, list) {
F_162 ( & V_345 -> V_185 ) ;
F_163 ( V_345 , V_343 ) ;
}
}
void F_165 ( struct V_5 * V_6 )
{
struct V_346 * V_345 ;
F_161 (k, &hdev->identity_resolving_keys, list) {
F_162 ( & V_345 -> V_185 ) ;
F_163 ( V_345 , V_343 ) ;
}
}
struct V_341 * F_166 ( struct V_5 * V_6 , T_9 * V_113 )
{
struct V_341 * V_345 ;
F_167 () ;
F_161 (k, &hdev->link_keys, list) {
if ( F_90 ( V_113 , & V_345 -> V_113 ) == 0 ) {
F_168 () ;
return V_345 ;
}
}
F_168 () ;
return NULL ;
}
static bool F_169 ( struct V_5 * V_6 , struct V_347 * V_269 ,
T_7 V_348 , T_7 V_349 )
{
if ( V_348 < 0x03 )
return true ;
if ( V_348 == V_350 )
return false ;
if ( V_348 == V_351 && V_349 == 0xff )
return false ;
if ( ! V_269 )
return true ;
if ( V_269 -> type == V_352 )
return true ;
if ( V_269 -> V_353 > 0x01 && V_269 -> V_354 > 0x01 )
return true ;
if ( V_269 -> V_353 == 0x02 || V_269 -> V_353 == 0x03 )
return true ;
if ( V_269 -> V_354 == 0x02 || V_269 -> V_354 == 0x03 )
return true ;
return false ;
}
static T_7 F_170 ( T_7 type )
{
if ( type == V_355 )
return V_356 ;
return V_357 ;
}
struct V_344 * F_171 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 V_358 , T_7 V_359 )
{
struct V_344 * V_345 ;
F_167 () ;
F_161 (k, &hdev->long_term_keys, list) {
if ( V_358 != V_345 -> V_360 || F_90 ( V_113 , & V_345 -> V_113 ) )
continue;
if ( F_172 ( V_345 ) || F_170 ( V_345 -> type ) == V_359 ) {
F_168 () ;
return V_345 ;
}
}
F_168 () ;
return NULL ;
}
struct V_346 * F_173 ( struct V_5 * V_6 , T_9 * V_361 )
{
struct V_346 * V_362 ;
F_167 () ;
F_161 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_90 ( & V_362 -> V_361 , V_361 ) ) {
F_168 () ;
return V_362 ;
}
}
F_161 (irk, &hdev->identity_resolving_keys, list) {
if ( F_174 ( V_6 , V_362 -> V_363 , V_361 ) ) {
F_60 ( & V_362 -> V_361 , V_361 ) ;
F_168 () ;
return V_362 ;
}
}
F_168 () ;
return NULL ;
}
struct V_346 * F_175 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 V_358 )
{
struct V_346 * V_362 ;
if ( V_358 == V_364 && ( V_113 -> V_365 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_167 () ;
F_161 (irk, &hdev->identity_resolving_keys, list) {
if ( V_358 == V_362 -> V_358 &&
F_90 ( V_113 , & V_362 -> V_113 ) == 0 ) {
F_168 () ;
return V_362 ;
}
}
F_168 () ;
return NULL ;
}
struct V_341 * F_176 ( struct V_5 * V_6 , struct V_347 * V_269 ,
T_9 * V_113 , T_7 * V_363 , T_7 type ,
T_7 V_366 , bool * V_367 )
{
struct V_341 * V_342 , * V_368 ;
T_7 V_349 ;
V_368 = F_166 ( V_6 , V_113 ) ;
if ( V_368 ) {
V_349 = V_368 -> type ;
V_342 = V_368 ;
} else {
V_349 = V_269 ? V_269 -> V_348 : 0xff ;
V_342 = F_97 ( sizeof( * V_342 ) , V_195 ) ;
if ( ! V_342 )
return NULL ;
F_177 ( & V_342 -> V_185 , & V_6 -> V_369 ) ;
}
F_23 ( L_18 , V_6 -> V_37 , V_113 , type ) ;
if ( type == V_351 &&
( ! V_269 || V_269 -> V_354 == 0xff ) && V_349 == 0xff ) {
type = V_370 ;
if ( V_269 )
V_269 -> V_348 = type ;
}
F_60 ( & V_342 -> V_113 , V_113 ) ;
memcpy ( V_342 -> V_363 , V_363 , V_371 ) ;
V_342 -> V_366 = V_366 ;
if ( type == V_351 )
V_342 -> type = V_349 ;
else
V_342 -> type = type ;
if ( V_367 )
* V_367 = F_169 ( V_6 , V_269 , type ,
V_349 ) ;
return V_342 ;
}
struct V_344 * F_178 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 V_358 , T_7 type , T_7 V_372 ,
T_7 V_373 [ 16 ] , T_7 V_374 , T_5 V_375 , T_12 rand )
{
struct V_344 * V_342 , * V_368 ;
T_7 V_359 = F_170 ( type ) ;
V_368 = F_171 ( V_6 , V_113 , V_358 , V_359 ) ;
if ( V_368 )
V_342 = V_368 ;
else {
V_342 = F_97 ( sizeof( * V_342 ) , V_195 ) ;
if ( ! V_342 )
return NULL ;
F_177 ( & V_342 -> V_185 , & V_6 -> V_376 ) ;
}
F_60 ( & V_342 -> V_113 , V_113 ) ;
V_342 -> V_360 = V_358 ;
memcpy ( V_342 -> V_363 , V_373 , sizeof( V_342 -> V_363 ) ) ;
V_342 -> V_372 = V_372 ;
V_342 -> V_375 = V_375 ;
V_342 -> rand = rand ;
V_342 -> V_374 = V_374 ;
V_342 -> type = type ;
return V_342 ;
}
struct V_346 * F_179 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 V_358 , T_7 V_363 [ 16 ] , T_9 * V_361 )
{
struct V_346 * V_362 ;
V_362 = F_175 ( V_6 , V_113 , V_358 ) ;
if ( ! V_362 ) {
V_362 = F_97 ( sizeof( * V_362 ) , V_195 ) ;
if ( ! V_362 )
return NULL ;
F_60 ( & V_362 -> V_113 , V_113 ) ;
V_362 -> V_358 = V_358 ;
F_177 ( & V_362 -> V_185 , & V_6 -> V_377 ) ;
}
memcpy ( V_362 -> V_363 , V_363 , 16 ) ;
F_60 ( & V_362 -> V_361 , V_361 ) ;
return V_362 ;
}
int F_180 ( struct V_5 * V_6 , T_9 * V_113 )
{
struct V_341 * V_342 ;
V_342 = F_166 ( V_6 , V_113 ) ;
if ( ! V_342 )
return - V_378 ;
F_23 ( L_19 , V_6 -> V_37 , V_113 ) ;
F_162 ( & V_342 -> V_185 ) ;
F_163 ( V_342 , V_343 ) ;
return 0 ;
}
int F_181 ( struct V_5 * V_6 , T_9 * V_113 , T_7 V_360 )
{
struct V_344 * V_345 ;
int V_379 = 0 ;
F_161 (k, &hdev->long_term_keys, list) {
if ( F_90 ( V_113 , & V_345 -> V_113 ) || V_345 -> V_360 != V_360 )
continue;
F_23 ( L_19 , V_6 -> V_37 , V_113 ) ;
F_162 ( & V_345 -> V_185 ) ;
F_163 ( V_345 , V_343 ) ;
V_379 ++ ;
}
return V_379 ? 0 : - V_378 ;
}
void F_182 ( struct V_5 * V_6 , T_9 * V_113 , T_7 V_358 )
{
struct V_346 * V_345 ;
F_161 (k, &hdev->identity_resolving_keys, list) {
if ( F_90 ( V_113 , & V_345 -> V_113 ) || V_345 -> V_358 != V_358 )
continue;
F_23 ( L_19 , V_6 -> V_37 , V_113 ) ;
F_162 ( & V_345 -> V_185 ) ;
F_163 ( V_345 , V_343 ) ;
}
}
bool F_183 ( struct V_5 * V_6 , T_9 * V_113 , T_7 type )
{
struct V_344 * V_345 ;
struct V_346 * V_362 ;
T_7 V_358 ;
if ( type == V_190 ) {
if ( F_166 ( V_6 , V_113 ) )
return true ;
return false ;
}
if ( type == V_380 )
V_358 = V_381 ;
else
V_358 = V_364 ;
V_362 = F_184 ( V_6 , V_113 , V_358 ) ;
if ( V_362 ) {
V_113 = & V_362 -> V_113 ;
V_358 = V_362 -> V_358 ;
}
F_167 () ;
F_161 (k, &hdev->long_term_keys, list) {
if ( V_345 -> V_360 == V_358 && ! F_90 ( V_113 , & V_345 -> V_113 ) ) {
F_168 () ;
return true ;
}
}
F_168 () ;
return false ;
}
static void F_185 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 ,
V_273 . V_332 ) ;
if ( V_6 -> V_259 ) {
struct V_382 * V_383 = ( void * ) V_6 -> V_259 -> V_180 ;
T_8 V_384 = F_186 ( V_383 -> V_384 ) ;
F_30 ( L_20 , V_6 -> V_37 , V_384 ) ;
} else {
F_30 ( L_21 , V_6 -> V_37 ) ;
}
F_113 ( & V_6 -> V_242 , 1 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_254 ) ;
}
struct V_385 * F_188 ( struct V_5 * V_6 ,
T_9 * V_113 , T_7 V_360 )
{
struct V_385 * V_180 ;
F_77 (data, &hdev->remote_oob_data, list) {
if ( F_90 ( V_113 , & V_180 -> V_113 ) != 0 )
continue;
if ( V_180 -> V_360 != V_360 )
continue;
return V_180 ;
}
return NULL ;
}
int F_96 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 V_360 )
{
struct V_385 * V_180 ;
V_180 = F_188 ( V_6 , V_113 , V_360 ) ;
if ( ! V_180 )
return - V_378 ;
F_23 ( L_22 , V_6 -> V_37 , V_113 , V_360 ) ;
F_86 ( & V_180 -> V_185 ) ;
F_87 ( V_180 ) ;
return 0 ;
}
void F_189 ( struct V_5 * V_6 )
{
struct V_385 * V_180 , * V_175 ;
F_85 (data, n, &hdev->remote_oob_data, list) {
F_86 ( & V_180 -> V_185 ) ;
F_87 ( V_180 ) ;
}
}
int F_190 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 V_360 , T_7 * V_386 , T_7 * V_387 ,
T_7 * V_388 , T_7 * V_389 )
{
struct V_385 * V_180 ;
V_180 = F_188 ( V_6 , V_113 , V_360 ) ;
if ( ! V_180 ) {
V_180 = F_108 ( sizeof( * V_180 ) , V_195 ) ;
if ( ! V_180 )
return - V_232 ;
F_60 ( & V_180 -> V_113 , V_113 ) ;
V_180 -> V_360 = V_360 ;
F_94 ( & V_180 -> V_185 , & V_6 -> V_390 ) ;
}
if ( V_386 && V_387 ) {
memcpy ( V_180 -> V_386 , V_386 , sizeof( V_180 -> V_386 ) ) ;
memcpy ( V_180 -> V_387 , V_387 , sizeof( V_180 -> V_387 ) ) ;
if ( V_388 && V_389 )
V_180 -> V_391 = 0x03 ;
} else {
memset ( V_180 -> V_386 , 0 , sizeof( V_180 -> V_386 ) ) ;
memset ( V_180 -> V_387 , 0 , sizeof( V_180 -> V_387 ) ) ;
if ( V_388 && V_389 )
V_180 -> V_391 = 0x02 ;
else
V_180 -> V_391 = 0x00 ;
}
if ( V_388 && V_389 ) {
memcpy ( V_180 -> V_388 , V_388 , sizeof( V_180 -> V_388 ) ) ;
memcpy ( V_180 -> V_389 , V_389 , sizeof( V_180 -> V_389 ) ) ;
} else {
memset ( V_180 -> V_388 , 0 , sizeof( V_180 -> V_388 ) ) ;
memset ( V_180 -> V_389 , 0 , sizeof( V_180 -> V_389 ) ) ;
if ( V_386 && V_387 )
V_180 -> V_391 = 0x01 ;
}
F_23 ( L_23 , V_6 -> V_37 , V_113 ) ;
return 0 ;
}
struct V_392 * F_191 ( struct V_5 * V_6 , T_7 V_393 )
{
struct V_392 * V_394 ;
F_77 (adv_instance, &hdev->adv_instances, list) {
if ( V_394 -> V_393 == V_393 )
return V_394 ;
}
return NULL ;
}
struct V_392 * F_192 ( struct V_5 * V_6 , T_7 V_393 )
{
struct V_392 * V_395 ;
V_395 = F_191 ( V_6 , V_393 ) ;
if ( ! V_395 )
return NULL ;
if ( V_395 == F_193 ( & V_6 -> V_396 ,
struct V_392 , V_185 ) )
return F_194 ( & V_6 -> V_396 ,
struct V_392 , V_185 ) ;
else
return F_195 ( V_395 , V_185 ) ;
}
int F_196 ( struct V_5 * V_6 , T_7 V_393 )
{
struct V_392 * V_394 ;
V_394 = F_191 ( V_6 , V_393 ) ;
if ( ! V_394 )
return - V_378 ;
F_23 ( L_24 , V_6 -> V_37 , V_393 ) ;
if ( V_6 -> V_296 == V_393 ) {
if ( V_6 -> V_397 ) {
F_123 ( & V_6 -> V_398 ) ;
V_6 -> V_397 = 0 ;
}
V_6 -> V_296 = 0x00 ;
}
F_86 ( & V_394 -> V_185 ) ;
F_87 ( V_394 ) ;
V_6 -> V_399 -- ;
return 0 ;
}
void F_197 ( struct V_5 * V_6 )
{
struct V_392 * V_394 , * V_175 ;
if ( V_6 -> V_397 ) {
F_123 ( & V_6 -> V_398 ) ;
V_6 -> V_397 = 0 ;
}
F_85 (adv_instance, n, &hdev->adv_instances, list) {
F_86 ( & V_394 -> V_185 ) ;
F_87 ( V_394 ) ;
}
V_6 -> V_399 = 0 ;
V_6 -> V_296 = 0x00 ;
}
int F_198 ( struct V_5 * V_6 , T_7 V_393 , T_10 V_15 ,
T_8 V_400 , T_7 * V_401 ,
T_8 V_402 , T_7 * V_403 ,
T_8 V_404 , T_8 V_405 )
{
struct V_392 * V_394 ;
V_394 = F_191 ( V_6 , V_393 ) ;
if ( V_394 ) {
memset ( V_394 -> V_401 , 0 ,
sizeof( V_394 -> V_401 ) ) ;
memset ( V_394 -> V_403 , 0 ,
sizeof( V_394 -> V_403 ) ) ;
} else {
if ( V_6 -> V_399 >= V_406 ||
V_393 < 1 || V_393 > V_406 )
return - V_407 ;
V_394 = F_97 ( sizeof( * V_394 ) , V_195 ) ;
if ( ! V_394 )
return - V_232 ;
V_394 -> V_408 = true ;
V_394 -> V_393 = V_393 ;
F_94 ( & V_394 -> V_185 , & V_6 -> V_396 ) ;
V_6 -> V_399 ++ ;
}
V_394 -> V_15 = V_15 ;
V_394 -> V_400 = V_400 ;
V_394 -> V_402 = V_402 ;
if ( V_400 )
memcpy ( V_394 -> V_401 , V_401 , V_400 ) ;
if ( V_402 )
memcpy ( V_394 -> V_403 ,
V_403 , V_402 ) ;
V_394 -> V_404 = V_404 ;
V_394 -> V_409 = V_404 ;
if ( V_405 == 0 )
V_394 -> V_405 = V_410 ;
else
V_394 -> V_405 = V_405 ;
F_23 ( L_25 , V_6 -> V_37 , V_393 ) ;
return 0 ;
}
struct V_411 * F_199 ( struct V_183 * V_411 ,
T_9 * V_113 , T_7 type )
{
struct V_411 * V_365 ;
F_77 (b, bdaddr_list, list) {
if ( ! F_90 ( & V_365 -> V_113 , V_113 ) && V_365 -> V_360 == type )
return V_365 ;
}
return NULL ;
}
void F_200 ( struct V_183 * V_411 )
{
struct V_411 * V_365 , * V_175 ;
F_85 (b, n, bdaddr_list, list) {
F_86 ( & V_365 -> V_185 ) ;
F_87 ( V_365 ) ;
}
}
int F_201 ( struct V_183 * V_185 , T_9 * V_113 , T_7 type )
{
struct V_411 * V_412 ;
if ( ! F_90 ( V_113 , V_114 ) )
return - V_413 ;
if ( F_199 ( V_185 , V_113 , type ) )
return - V_414 ;
V_412 = F_97 ( sizeof( * V_412 ) , V_195 ) ;
if ( ! V_412 )
return - V_232 ;
F_60 ( & V_412 -> V_113 , V_113 ) ;
V_412 -> V_360 = type ;
F_94 ( & V_412 -> V_185 , V_185 ) ;
return 0 ;
}
int F_202 ( struct V_183 * V_185 , T_9 * V_113 , T_7 type )
{
struct V_411 * V_412 ;
if ( ! F_90 ( V_113 , V_114 ) ) {
F_200 ( V_185 ) ;
return 0 ;
}
V_412 = F_199 ( V_185 , V_113 , type ) ;
if ( ! V_412 )
return - V_378 ;
F_86 ( & V_412 -> V_185 ) ;
F_87 ( V_412 ) ;
return 0 ;
}
struct V_268 * F_203 ( struct V_5 * V_6 ,
T_9 * V_415 , T_7 V_358 )
{
struct V_268 * V_416 ;
F_77 (params, &hdev->le_conn_params, list) {
if ( F_90 ( & V_416 -> V_415 , V_415 ) == 0 &&
V_416 -> V_358 == V_358 ) {
return V_416 ;
}
}
return NULL ;
}
struct V_268 * F_204 ( struct V_183 * V_185 ,
T_9 * V_415 , T_7 V_358 )
{
struct V_268 * V_55 ;
F_77 (param, list, action) {
if ( F_90 ( & V_55 -> V_415 , V_415 ) == 0 &&
V_55 -> V_358 == V_358 )
return V_55 ;
}
return NULL ;
}
struct V_268 * F_205 ( struct V_5 * V_6 ,
T_9 * V_415 , T_7 V_358 )
{
struct V_268 * V_416 ;
V_416 = F_203 ( V_6 , V_415 , V_358 ) ;
if ( V_416 )
return V_416 ;
V_416 = F_97 ( sizeof( * V_416 ) , V_195 ) ;
if ( ! V_416 ) {
F_30 ( L_26 ) ;
return NULL ;
}
F_60 ( & V_416 -> V_415 , V_415 ) ;
V_416 -> V_358 = V_358 ;
F_94 ( & V_416 -> V_185 , & V_6 -> V_417 ) ;
F_88 ( & V_416 -> V_270 ) ;
V_416 -> V_418 = V_6 -> V_419 ;
V_416 -> V_420 = V_6 -> V_421 ;
V_416 -> V_422 = V_6 -> V_423 ;
V_416 -> V_424 = V_6 -> V_425 ;
V_416 -> V_426 = V_427 ;
F_23 ( L_27 , V_415 , V_358 ) ;
return V_416 ;
}
static void F_206 ( struct V_268 * V_416 )
{
if ( V_416 -> V_269 ) {
F_126 ( V_416 -> V_269 ) ;
F_127 ( V_416 -> V_269 ) ;
}
F_86 ( & V_416 -> V_270 ) ;
F_86 ( & V_416 -> V_185 ) ;
F_87 ( V_416 ) ;
}
void F_207 ( struct V_5 * V_6 , T_9 * V_415 , T_7 V_358 )
{
struct V_268 * V_416 ;
V_416 = F_203 ( V_6 , V_415 , V_358 ) ;
if ( ! V_416 )
return;
F_206 ( V_416 ) ;
F_82 ( V_6 ) ;
F_23 ( L_27 , V_415 , V_358 ) ;
}
void F_208 ( struct V_5 * V_6 )
{
struct V_268 * V_416 , * V_340 ;
F_85 (params, tmp, &hdev->le_conn_params, list) {
if ( V_416 -> V_426 != V_427 )
continue;
if ( V_416 -> V_428 ) {
V_416 -> V_426 = V_429 ;
continue;
}
F_86 ( & V_416 -> V_185 ) ;
F_87 ( V_416 ) ;
}
F_23 ( L_28 ) ;
}
static void F_209 ( struct V_5 * V_6 )
{
struct V_268 * V_416 , * V_340 ;
F_85 (params, tmp, &hdev->le_conn_params, list)
F_206 ( V_416 ) ;
F_23 ( L_29 ) ;
}
void F_210 ( struct V_5 * V_6 , T_9 * V_113 ,
T_7 * V_360 )
{
if ( F_2 ( V_6 , V_430 ) ||
! F_90 ( & V_6 -> V_113 , V_114 ) ||
( ! F_2 ( V_6 , V_77 ) &&
F_90 ( & V_6 -> V_237 , V_114 ) ) ) {
F_60 ( V_113 , & V_6 -> V_237 ) ;
* V_360 = V_364 ;
} else {
F_60 ( V_113 , & V_6 -> V_113 ) ;
* V_360 = V_381 ;
}
}
struct V_5 * F_211 ( void )
{
struct V_5 * V_6 ;
V_6 = F_97 ( sizeof( * V_6 ) , V_195 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_311 = ( V_431 | V_432 | V_433 ) ;
V_6 -> V_434 = ( V_435 ) ;
V_6 -> V_307 = ( V_309 ) ;
V_6 -> V_436 = 0x01 ;
V_6 -> V_437 = 0x03 ;
V_6 -> V_438 = 0xffff ;
V_6 -> V_439 = V_440 ;
V_6 -> V_441 = V_440 ;
V_6 -> V_399 = 0 ;
V_6 -> V_296 = 0x00 ;
V_6 -> V_397 = 0 ;
V_6 -> V_442 = 800 ;
V_6 -> V_443 = 80 ;
V_6 -> V_444 = 0x07 ;
V_6 -> V_445 = 0x0800 ;
V_6 -> V_446 = 0x0800 ;
V_6 -> V_447 = 0x0060 ;
V_6 -> V_448 = 0x0030 ;
V_6 -> V_419 = 0x0018 ;
V_6 -> V_421 = 0x0028 ;
V_6 -> V_423 = 0x0000 ;
V_6 -> V_425 = 0x002a ;
V_6 -> V_449 = 0x001b ;
V_6 -> V_450 = 0x0148 ;
V_6 -> V_140 = 0x001b ;
V_6 -> V_142 = 0x0148 ;
V_6 -> V_451 = 0x001b ;
V_6 -> V_452 = 0x0148 ;
V_6 -> V_453 = V_454 ;
V_6 -> V_455 = V_456 ;
V_6 -> V_457 = V_458 ;
V_6 -> V_459 = V_460 ;
F_212 ( & V_6 -> V_461 ) ;
F_212 ( & V_6 -> V_462 ) ;
F_88 ( & V_6 -> V_463 ) ;
F_88 ( & V_6 -> V_464 ) ;
F_88 ( & V_6 -> V_465 ) ;
F_88 ( & V_6 -> V_466 ) ;
F_88 ( & V_6 -> V_369 ) ;
F_88 ( & V_6 -> V_376 ) ;
F_88 ( & V_6 -> V_377 ) ;
F_88 ( & V_6 -> V_390 ) ;
F_88 ( & V_6 -> V_467 ) ;
F_88 ( & V_6 -> V_417 ) ;
F_88 ( & V_6 -> V_468 ) ;
F_88 ( & V_6 -> V_469 ) ;
F_88 ( & V_6 -> V_470 . V_185 ) ;
F_88 ( & V_6 -> V_396 ) ;
F_213 ( & V_6 -> V_255 , V_471 ) ;
F_213 ( & V_6 -> V_254 , V_472 ) ;
F_213 ( & V_6 -> V_253 , V_473 ) ;
F_213 ( & V_6 -> V_333 , F_152 ) ;
F_213 ( & V_6 -> V_335 , F_158 ) ;
F_214 ( & V_6 -> V_265 , F_157 ) ;
F_215 ( & V_6 -> V_257 ) ;
F_215 ( & V_6 -> V_256 ) ;
F_215 ( & V_6 -> V_282 ) ;
F_216 ( & V_6 -> V_474 ) ;
F_214 ( & V_6 -> V_273 , F_185 ) ;
F_217 ( V_6 ) ;
F_218 ( V_6 ) ;
F_219 ( V_6 ) ;
return V_6 ;
}
void F_220 ( struct V_5 * V_6 )
{
F_221 ( & V_6 -> V_263 ) ;
}
int F_222 ( struct V_5 * V_6 )
{
int V_162 , error ;
if ( ! V_6 -> V_239 || ! V_6 -> V_261 || ! V_6 -> V_475 )
return - V_18 ;
switch ( V_6 -> V_52 ) {
case V_53 :
V_162 = F_223 ( & V_476 , 0 , 0 , V_195 ) ;
break;
case V_54 :
V_162 = F_223 ( & V_476 , 1 , 0 , V_195 ) ;
break;
default:
return - V_18 ;
}
if ( V_162 < 0 )
return V_162 ;
sprintf ( V_6 -> V_37 , L_30 , V_162 ) ;
V_6 -> V_162 = V_162 ;
F_23 ( L_31 , V_6 , V_6 -> V_37 , V_6 -> V_326 ) ;
V_6 -> V_280 = F_224 ( L_11 , V_477 , V_6 -> V_37 ) ;
if ( ! V_6 -> V_280 ) {
error = - V_232 ;
goto V_24;
}
V_6 -> V_266 = F_224 ( L_11 , V_477 ,
V_6 -> V_37 ) ;
if ( ! V_6 -> V_266 ) {
F_225 ( V_6 -> V_280 ) ;
error = - V_232 ;
goto V_24;
}
if ( ! F_226 ( V_478 ) )
V_6 -> V_31 = F_227 ( V_6 -> V_37 , V_478 ) ;
F_228 ( & V_6 -> V_263 , L_11 , V_6 -> V_37 ) ;
error = F_229 ( & V_6 -> V_263 ) ;
if ( error < 0 )
goto V_479;
F_230 ( V_6 ) ;
V_6 -> V_480 = F_231 ( V_6 -> V_37 , & V_6 -> V_263 ,
V_481 , & V_482 ,
V_6 ) ;
if ( V_6 -> V_480 ) {
if ( F_232 ( V_6 -> V_480 ) < 0 ) {
F_233 ( V_6 -> V_480 ) ;
V_6 -> V_480 = NULL ;
}
}
if ( V_6 -> V_480 && F_234 ( V_6 -> V_480 ) )
F_18 ( V_6 , V_235 ) ;
F_18 ( V_6 , V_150 ) ;
F_18 ( V_6 , V_264 ) ;
if ( V_6 -> V_52 == V_53 ) {
F_18 ( V_6 , V_77 ) ;
}
F_235 ( & V_161 ) ;
F_94 ( & V_6 -> V_185 , & V_483 ) ;
F_236 ( & V_161 ) ;
if ( F_6 ( V_153 , & V_6 -> V_26 ) )
F_18 ( V_6 , V_226 ) ;
F_112 ( V_6 , V_484 ) ;
F_78 ( V_6 ) ;
F_187 ( V_6 -> V_266 , & V_6 -> V_333 ) ;
return V_162 ;
V_479:
F_225 ( V_6 -> V_280 ) ;
F_225 ( V_6 -> V_266 ) ;
V_24:
F_237 ( & V_476 , V_6 -> V_162 ) ;
return error ;
}
void F_238 ( struct V_5 * V_6 )
{
int V_162 ;
F_23 ( L_31 , V_6 , V_6 -> V_37 , V_6 -> V_326 ) ;
F_18 ( V_6 , V_234 ) ;
V_162 = V_6 -> V_162 ;
F_235 ( & V_161 ) ;
F_86 ( & V_6 -> V_185 ) ;
F_236 ( & V_161 ) ;
F_239 ( & V_6 -> V_333 ) ;
F_129 ( V_6 ) ;
if ( ! F_6 ( V_243 , & V_6 -> V_15 ) &&
! F_2 ( V_6 , V_150 ) &&
! F_2 ( V_6 , V_151 ) ) {
F_101 ( V_6 ) ;
F_240 ( V_6 ) ;
F_104 ( V_6 ) ;
}
F_241 ( ! F_242 ( & V_6 -> V_463 ) ) ;
F_112 ( V_6 , V_485 ) ;
if ( V_6 -> V_480 ) {
F_243 ( V_6 -> V_480 ) ;
F_233 ( V_6 -> V_480 ) ;
}
F_244 ( & V_6 -> V_263 ) ;
F_245 ( V_6 -> V_31 ) ;
F_246 ( V_6 -> V_486 ) ;
F_246 ( V_6 -> V_487 ) ;
F_225 ( V_6 -> V_280 ) ;
F_225 ( V_6 -> V_266 ) ;
F_101 ( V_6 ) ;
F_200 ( & V_6 -> V_464 ) ;
F_200 ( & V_6 -> V_465 ) ;
F_159 ( V_6 ) ;
F_160 ( V_6 ) ;
F_164 ( V_6 ) ;
F_165 ( V_6 ) ;
F_189 ( V_6 ) ;
F_197 ( V_6 ) ;
F_200 ( & V_6 -> V_467 ) ;
F_209 ( V_6 ) ;
F_247 ( V_6 ) ;
F_104 ( V_6 ) ;
F_110 ( V_6 ) ;
F_237 ( & V_476 , V_162 ) ;
}
int F_248 ( struct V_5 * V_6 )
{
F_112 ( V_6 , V_488 ) ;
return 0 ;
}
int F_249 ( struct V_5 * V_6 )
{
F_112 ( V_6 , V_489 ) ;
return 0 ;
}
int F_250 ( struct V_5 * V_6 )
{
const T_7 V_490 [] = { V_491 , 0x01 , 0x00 } ;
struct V_10 * V_11 ;
V_11 = F_251 ( 3 , V_492 ) ;
if ( ! V_11 )
return - V_232 ;
F_252 ( V_11 ) = V_493 ;
F_253 ( V_11 , V_490 , 3 ) ;
return F_254 ( V_6 , V_11 ) ;
}
int F_254 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( ! V_6 || ( ! F_6 ( V_14 , & V_6 -> V_15 )
&& ! F_6 ( V_243 , & V_6 -> V_15 ) ) ) {
F_14 ( V_11 ) ;
return - V_494 ;
}
if ( F_252 ( V_11 ) != V_493 &&
F_252 ( V_11 ) != V_495 &&
F_252 ( V_11 ) != V_496 ) {
F_14 ( V_11 ) ;
return - V_18 ;
}
F_255 ( V_11 ) -> V_497 = 1 ;
F_256 ( V_11 ) ;
F_257 ( & V_6 -> V_257 , V_11 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_255 ) ;
return 0 ;
}
int F_258 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
F_252 ( V_11 ) = V_498 ;
F_256 ( V_11 ) ;
F_257 ( & V_6 -> V_257 , V_11 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_255 ) ;
return 0 ;
}
void F_259 ( struct V_5 * V_6 , const char * V_499 , ... )
{
T_13 V_500 ;
va_start ( V_500 , V_499 ) ;
F_246 ( V_6 -> V_486 ) ;
V_6 -> V_486 = F_260 ( V_195 , V_499 , V_500 ) ;
va_end ( V_500 ) ;
}
void F_261 ( struct V_5 * V_6 , const char * V_499 , ... )
{
T_13 V_500 ;
va_start ( V_500 , V_499 ) ;
F_246 ( V_6 -> V_487 ) ;
V_6 -> V_487 = F_260 ( V_195 , V_499 , V_500 ) ;
va_end ( V_500 ) ;
}
int F_262 ( struct V_501 * V_502 )
{
F_23 ( L_32 , V_502 , V_502 -> V_37 ) ;
F_263 ( & V_503 ) ;
F_264 ( & V_502 -> V_185 , & V_504 ) ;
F_265 ( & V_503 ) ;
return 0 ;
}
int F_266 ( struct V_501 * V_502 )
{
F_23 ( L_32 , V_502 , V_502 -> V_37 ) ;
F_263 ( & V_503 ) ;
F_86 ( & V_502 -> V_185 ) ;
F_265 ( & V_503 ) ;
return 0 ;
}
static void F_267 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
int V_24 ;
F_23 ( L_33 , V_6 -> V_37 , F_252 ( V_11 ) ,
V_11 -> V_505 ) ;
F_256 ( V_11 ) ;
F_268 ( V_6 , V_11 ) ;
if ( F_269 ( & V_6 -> V_506 ) ) {
F_270 ( V_6 , V_11 ) ;
}
F_271 ( V_11 ) ;
if ( ! F_6 ( V_27 , & V_6 -> V_15 ) ) {
F_14 ( V_11 ) ;
return;
}
V_24 = V_6 -> V_475 ( V_6 , V_11 ) ;
if ( V_24 < 0 ) {
F_30 ( L_34 , V_6 -> V_37 , V_24 ) ;
F_14 ( V_11 ) ;
}
}
int F_272 ( struct V_5 * V_6 , T_11 V_384 , T_14 V_507 ,
const void * V_55 )
{
struct V_10 * V_11 ;
F_23 ( L_35 , V_6 -> V_37 , V_384 , V_507 ) ;
V_11 = F_273 ( V_6 , V_384 , V_507 , V_55 ) ;
if ( ! V_11 ) {
F_30 ( L_36 , V_6 -> V_37 ) ;
return - V_232 ;
}
F_255 ( V_11 ) -> V_508 . V_509 |= V_510 ;
F_257 ( & V_6 -> V_256 , V_11 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_254 ) ;
return 0 ;
}
void * F_274 ( struct V_5 * V_6 , T_11 V_384 )
{
struct V_382 * V_511 ;
if ( ! V_6 -> V_259 )
return NULL ;
V_511 = ( void * ) V_6 -> V_259 -> V_180 ;
if ( V_511 -> V_384 != F_32 ( V_384 ) )
return NULL ;
F_23 ( L_37 , V_6 -> V_37 , V_384 ) ;
return V_6 -> V_259 -> V_180 + V_512 ;
}
struct V_10 * F_275 ( struct V_5 * V_6 , T_8 V_384 , T_10 V_507 ,
const void * V_55 , T_10 V_404 )
{
struct V_10 * V_11 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) )
return F_276 ( - V_16 ) ;
F_277 ( V_6 , L_38 , V_384 , V_507 ) ;
F_9 ( V_6 ) ;
V_11 = F_10 ( V_6 , V_384 , V_507 , V_55 , V_404 ) ;
F_11 ( V_6 ) ;
return V_11 ;
}
static void F_278 ( struct V_10 * V_11 , T_11 V_513 , T_11 V_15 )
{
struct V_514 * V_511 ;
int V_505 = V_11 -> V_505 ;
F_279 ( V_11 , V_515 ) ;
F_280 ( V_11 ) ;
V_511 = (struct V_514 * ) F_281 ( V_11 ) ;
V_511 -> V_513 = F_32 ( F_282 ( V_513 , V_15 ) ) ;
V_511 -> V_516 = F_32 ( V_505 ) ;
}
static void F_283 ( struct V_517 * V_518 , struct V_519 * V_520 ,
struct V_10 * V_11 , T_11 V_15 )
{
struct V_347 * V_269 = V_518 -> V_269 ;
struct V_5 * V_6 = V_269 -> V_6 ;
struct V_10 * V_185 ;
V_11 -> V_505 = F_284 ( V_11 ) ;
V_11 -> V_521 = 0 ;
F_252 ( V_11 ) = V_495 ;
switch ( V_6 -> V_52 ) {
case V_53 :
F_278 ( V_11 , V_269 -> V_513 , V_15 ) ;
break;
case V_54 :
F_278 ( V_11 , V_518 -> V_513 , V_15 ) ;
break;
default:
F_30 ( L_39 , V_6 -> V_37 , V_6 -> V_52 ) ;
return;
}
V_185 = F_285 ( V_11 ) -> V_522 ;
if ( ! V_185 ) {
F_23 ( L_40 , V_6 -> V_37 , V_11 , V_11 -> V_505 ) ;
F_257 ( V_520 , V_11 ) ;
} else {
F_23 ( L_41 , V_6 -> V_37 , V_11 , V_11 -> V_505 ) ;
F_285 ( V_11 ) -> V_522 = NULL ;
F_286 ( & V_520 -> V_461 ) ;
F_287 ( V_520 , V_11 ) ;
V_15 &= ~ V_523 ;
V_15 |= V_524 ;
do {
V_11 = V_185 ; V_185 = V_185 -> V_525 ;
F_252 ( V_11 ) = V_495 ;
F_278 ( V_11 , V_269 -> V_513 , V_15 ) ;
F_23 ( L_41 , V_6 -> V_37 , V_11 , V_11 -> V_505 ) ;
F_287 ( V_520 , V_11 ) ;
} while ( V_185 );
F_288 ( & V_520 -> V_461 ) ;
}
}
void F_289 ( struct V_517 * V_518 , struct V_10 * V_11 , T_11 V_15 )
{
struct V_5 * V_6 = V_518 -> V_269 -> V_6 ;
F_23 ( L_42 , V_6 -> V_37 , V_518 , V_15 ) ;
F_283 ( V_518 , & V_518 -> V_526 , V_11 , V_15 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_253 ) ;
}
void F_290 ( struct V_347 * V_269 , struct V_10 * V_11 )
{
struct V_5 * V_6 = V_269 -> V_6 ;
struct V_527 V_511 ;
F_23 ( L_43 , V_6 -> V_37 , V_11 -> V_505 ) ;
V_511 . V_513 = F_32 ( V_269 -> V_513 ) ;
V_511 . V_516 = V_11 -> V_505 ;
F_279 ( V_11 , V_528 ) ;
F_280 ( V_11 ) ;
memcpy ( F_281 ( V_11 ) , & V_511 , V_528 ) ;
F_252 ( V_11 ) = V_496 ;
F_257 ( & V_269 -> V_526 , V_11 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_253 ) ;
}
static struct V_347 * F_291 ( struct V_5 * V_6 , T_6 type ,
int * V_529 )
{
struct V_530 * V_531 = & V_6 -> V_470 ;
struct V_347 * V_269 = NULL , * V_532 ;
unsigned int V_201 = 0 , F_5 = ~ 0 ;
F_167 () ;
F_161 (c, &h->list, list) {
if ( V_532 -> type != type || F_292 ( & V_532 -> V_526 ) )
continue;
if ( V_532 -> V_166 != V_533 && V_532 -> V_166 != V_534 )
continue;
V_201 ++ ;
if ( V_532 -> V_383 < F_5 ) {
F_5 = V_532 -> V_383 ;
V_269 = V_532 ;
}
if ( F_293 ( V_6 , type ) == V_201 )
break;
}
F_168 () ;
if ( V_269 ) {
int V_535 , V_536 ;
switch ( V_269 -> type ) {
case V_537 :
V_535 = V_6 -> V_286 ;
break;
case V_538 :
case V_539 :
V_535 = V_6 -> V_287 ;
break;
case V_352 :
V_535 = V_6 -> V_327 ? V_6 -> V_288 : V_6 -> V_286 ;
break;
default:
V_535 = 0 ;
F_30 ( L_44 ) ;
}
V_536 = V_535 / V_201 ;
* V_529 = V_536 ? V_536 : 1 ;
} else
* V_529 = 0 ;
F_23 ( L_45 , V_269 , * V_529 ) ;
return V_269 ;
}
static void F_294 ( struct V_5 * V_6 , T_6 type )
{
struct V_530 * V_531 = & V_6 -> V_470 ;
struct V_347 * V_532 ;
F_30 ( L_46 , V_6 -> V_37 ) ;
F_167 () ;
F_161 (c, &h->list, list) {
if ( V_532 -> type == type && V_532 -> V_383 ) {
F_30 ( L_47 ,
V_6 -> V_37 , & V_532 -> V_540 ) ;
F_295 ( V_532 , V_541 ) ;
}
}
F_168 () ;
}
static struct V_517 * F_296 ( struct V_5 * V_6 , T_6 type ,
int * V_529 )
{
struct V_530 * V_531 = & V_6 -> V_470 ;
struct V_517 * V_518 = NULL ;
unsigned int V_201 = 0 , F_5 = ~ 0 , V_542 = 0 ;
struct V_347 * V_269 ;
int V_535 , V_536 , V_543 = 0 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
F_167 () ;
F_161 (conn, &h->list, list) {
struct V_517 * V_340 ;
if ( V_269 -> type != type )
continue;
if ( V_269 -> V_166 != V_533 && V_269 -> V_166 != V_534 )
continue;
V_543 ++ ;
F_161 (tmp, &conn->chan_list, list) {
struct V_10 * V_11 ;
if ( F_292 ( & V_340 -> V_526 ) )
continue;
V_11 = F_297 ( & V_340 -> V_526 ) ;
if ( V_11 -> V_544 < V_542 )
continue;
if ( V_11 -> V_544 > V_542 ) {
V_201 = 0 ;
F_5 = ~ 0 ;
V_542 = V_11 -> V_544 ;
}
V_201 ++ ;
if ( V_269 -> V_383 < F_5 ) {
F_5 = V_269 -> V_383 ;
V_518 = V_340 ;
}
}
if ( F_293 ( V_6 , type ) == V_543 )
break;
}
F_168 () ;
if ( ! V_518 )
return NULL ;
switch ( V_518 -> V_269 -> type ) {
case V_537 :
V_535 = V_6 -> V_286 ;
break;
case V_545 :
V_535 = V_6 -> V_546 ;
break;
case V_538 :
case V_539 :
V_535 = V_6 -> V_287 ;
break;
case V_352 :
V_535 = V_6 -> V_327 ? V_6 -> V_288 : V_6 -> V_286 ;
break;
default:
V_535 = 0 ;
F_30 ( L_44 ) ;
}
V_536 = V_535 / V_201 ;
* V_529 = V_536 ? V_536 : 1 ;
F_23 ( L_48 , V_518 , * V_529 ) ;
return V_518 ;
}
static void F_298 ( struct V_5 * V_6 , T_6 type )
{
struct V_530 * V_531 = & V_6 -> V_470 ;
struct V_347 * V_269 ;
int V_201 = 0 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
F_167 () ;
F_161 (conn, &h->list, list) {
struct V_517 * V_518 ;
if ( V_269 -> type != type )
continue;
if ( V_269 -> V_166 != V_533 && V_269 -> V_166 != V_534 )
continue;
V_201 ++ ;
F_161 (chan, &conn->chan_list, list) {
struct V_10 * V_11 ;
if ( V_518 -> V_383 ) {
V_518 -> V_383 = 0 ;
continue;
}
if ( F_292 ( & V_518 -> V_526 ) )
continue;
V_11 = F_297 ( & V_518 -> V_526 ) ;
if ( V_11 -> V_544 >= V_547 - 1 )
continue;
V_11 -> V_544 = V_547 - 1 ;
F_23 ( L_49 , V_518 , V_11 ,
V_11 -> V_544 ) ;
}
if ( F_293 ( V_6 , type ) == V_201 )
break;
}
F_168 () ;
}
static inline int F_299 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
return F_300 ( V_11 -> V_505 - V_515 , V_6 -> V_548 ) ;
}
static void F_301 ( struct V_5 * V_6 , unsigned int V_535 )
{
if ( ! F_2 ( V_6 , V_226 ) ) {
if ( ! V_535 && F_302 ( V_200 , V_6 -> V_549 +
V_550 ) )
F_294 ( V_6 , V_537 ) ;
}
}
static void F_303 ( struct V_5 * V_6 )
{
unsigned int V_535 = V_6 -> V_286 ;
struct V_517 * V_518 ;
struct V_10 * V_11 ;
int V_529 ;
F_301 ( V_6 , V_535 ) ;
while ( V_6 -> V_286 &&
( V_518 = F_296 ( V_6 , V_537 , & V_529 ) ) ) {
T_10 V_544 = ( F_297 ( & V_518 -> V_526 ) ) -> V_544 ;
while ( V_529 -- && ( V_11 = F_297 ( & V_518 -> V_526 ) ) ) {
F_23 ( L_50 , V_518 , V_11 ,
V_11 -> V_505 , V_11 -> V_544 ) ;
if ( V_11 -> V_544 < V_544 )
break;
V_11 = F_304 ( & V_518 -> V_526 ) ;
F_305 ( V_518 -> V_269 ,
F_255 ( V_11 ) -> V_551 ) ;
F_267 ( V_6 , V_11 ) ;
V_6 -> V_549 = V_200 ;
V_6 -> V_286 -- ;
V_518 -> V_383 ++ ;
V_518 -> V_269 -> V_383 ++ ;
}
}
if ( V_535 != V_6 -> V_286 )
F_298 ( V_6 , V_537 ) ;
}
static void F_306 ( struct V_5 * V_6 )
{
unsigned int V_535 = V_6 -> V_546 ;
struct V_517 * V_518 ;
struct V_10 * V_11 ;
int V_529 ;
T_7 type ;
F_301 ( V_6 , V_535 ) ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( V_6 -> V_52 == V_54 )
type = V_545 ;
else
type = V_537 ;
while ( V_6 -> V_546 > 0 &&
( V_518 = F_296 ( V_6 , type , & V_529 ) ) ) {
T_10 V_544 = ( F_297 ( & V_518 -> V_526 ) ) -> V_544 ;
while ( V_529 > 0 && ( V_11 = F_297 ( & V_518 -> V_526 ) ) ) {
int V_552 ;
F_23 ( L_50 , V_518 , V_11 ,
V_11 -> V_505 , V_11 -> V_544 ) ;
if ( V_11 -> V_544 < V_544 )
break;
V_11 = F_304 ( & V_518 -> V_526 ) ;
V_552 = F_299 ( V_6 , V_11 ) ;
if ( V_552 > V_6 -> V_546 )
return;
F_305 ( V_518 -> V_269 ,
F_255 ( V_11 ) -> V_551 ) ;
F_267 ( V_6 , V_11 ) ;
V_6 -> V_549 = V_200 ;
V_6 -> V_546 -= V_552 ;
V_529 -= V_552 ;
V_518 -> V_383 += V_552 ;
V_518 -> V_269 -> V_383 += V_552 ;
}
}
if ( V_535 != V_6 -> V_546 )
F_298 ( V_6 , type ) ;
}
static void F_307 ( struct V_5 * V_6 )
{
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( ! F_293 ( V_6 , V_537 ) && V_6 -> V_52 == V_53 )
return;
if ( ! F_293 ( V_6 , V_545 ) && V_6 -> V_52 == V_54 )
return;
switch ( V_6 -> V_39 ) {
case V_40 :
F_303 ( V_6 ) ;
break;
case V_44 :
F_306 ( V_6 ) ;
break;
}
}
static void F_308 ( struct V_5 * V_6 )
{
struct V_347 * V_269 ;
struct V_10 * V_11 ;
int V_529 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( ! F_293 ( V_6 , V_538 ) )
return;
while ( V_6 -> V_287 && ( V_269 = F_291 ( V_6 , V_538 , & V_529 ) ) ) {
while ( V_529 -- && ( V_11 = F_304 ( & V_269 -> V_526 ) ) ) {
F_23 ( L_51 , V_11 , V_11 -> V_505 ) ;
F_267 ( V_6 , V_11 ) ;
V_269 -> V_383 ++ ;
if ( V_269 -> V_383 == ~ 0 )
V_269 -> V_383 = 0 ;
}
}
}
static void F_309 ( struct V_5 * V_6 )
{
struct V_347 * V_269 ;
struct V_10 * V_11 ;
int V_529 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( ! F_293 ( V_6 , V_539 ) )
return;
while ( V_6 -> V_287 && ( V_269 = F_291 ( V_6 , V_539 ,
& V_529 ) ) ) {
while ( V_529 -- && ( V_11 = F_304 ( & V_269 -> V_526 ) ) ) {
F_23 ( L_51 , V_11 , V_11 -> V_505 ) ;
F_267 ( V_6 , V_11 ) ;
V_269 -> V_383 ++ ;
if ( V_269 -> V_383 == ~ 0 )
V_269 -> V_383 = 0 ;
}
}
}
static void F_310 ( struct V_5 * V_6 )
{
struct V_517 * V_518 ;
struct V_10 * V_11 ;
int V_529 , V_535 , V_340 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
if ( ! F_293 ( V_6 , V_352 ) )
return;
if ( ! F_2 ( V_6 , V_226 ) ) {
if ( ! V_6 -> V_288 && V_6 -> V_328 &&
F_302 ( V_200 , V_6 -> V_553 + V_554 * 45 ) )
F_294 ( V_6 , V_352 ) ;
}
V_535 = V_6 -> V_328 ? V_6 -> V_288 : V_6 -> V_286 ;
V_340 = V_535 ;
while ( V_535 && ( V_518 = F_296 ( V_6 , V_352 , & V_529 ) ) ) {
T_10 V_544 = ( F_297 ( & V_518 -> V_526 ) ) -> V_544 ;
while ( V_529 -- && ( V_11 = F_297 ( & V_518 -> V_526 ) ) ) {
F_23 ( L_50 , V_518 , V_11 ,
V_11 -> V_505 , V_11 -> V_544 ) ;
if ( V_11 -> V_544 < V_544 )
break;
V_11 = F_304 ( & V_518 -> V_526 ) ;
F_267 ( V_6 , V_11 ) ;
V_6 -> V_553 = V_200 ;
V_535 -- ;
V_518 -> V_383 ++ ;
V_518 -> V_269 -> V_383 ++ ;
}
}
if ( V_6 -> V_328 )
V_6 -> V_288 = V_535 ;
else
V_6 -> V_286 = V_535 ;
if ( V_535 != V_340 )
F_298 ( V_6 , V_352 ) ;
}
static void V_473 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 , V_253 ) ;
struct V_10 * V_11 ;
F_23 ( L_52 , V_6 -> V_37 , V_6 -> V_286 ,
V_6 -> V_287 , V_6 -> V_288 ) ;
if ( ! F_2 ( V_6 , V_28 ) ) {
F_307 ( V_6 ) ;
F_308 ( V_6 ) ;
F_309 ( V_6 ) ;
F_310 ( V_6 ) ;
}
while ( ( V_11 = F_304 ( & V_6 -> V_282 ) ) )
F_267 ( V_6 , V_11 ) ;
}
static void F_311 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_514 * V_511 = ( void * ) V_11 -> V_180 ;
struct V_347 * V_269 ;
T_11 V_513 , V_15 ;
F_312 ( V_11 , V_515 ) ;
V_513 = F_186 ( V_511 -> V_513 ) ;
V_15 = F_313 ( V_513 ) ;
V_513 = F_314 ( V_513 ) ;
F_23 ( L_53 , V_6 -> V_37 , V_11 -> V_505 ,
V_513 , V_15 ) ;
V_6 -> V_289 . V_555 ++ ;
F_101 ( V_6 ) ;
V_269 = F_315 ( V_6 , V_513 ) ;
F_104 ( V_6 ) ;
if ( V_269 ) {
F_305 ( V_269 , V_556 ) ;
F_316 ( V_269 , V_11 , V_15 ) ;
return;
} else {
F_30 ( L_54 ,
V_6 -> V_37 , V_513 ) ;
}
F_14 ( V_11 ) ;
}
static void F_317 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_527 * V_511 = ( void * ) V_11 -> V_180 ;
struct V_347 * V_269 ;
T_11 V_513 ;
F_312 ( V_11 , V_528 ) ;
V_513 = F_186 ( V_511 -> V_513 ) ;
F_23 ( L_55 , V_6 -> V_37 , V_11 -> V_505 , V_513 ) ;
V_6 -> V_289 . V_557 ++ ;
F_101 ( V_6 ) ;
V_269 = F_315 ( V_6 , V_513 ) ;
F_104 ( V_6 ) ;
if ( V_269 ) {
F_318 ( V_269 , V_11 ) ;
return;
} else {
F_30 ( L_56 ,
V_6 -> V_37 , V_513 ) ;
}
F_14 ( V_11 ) ;
}
static bool F_319 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
V_11 = F_297 ( & V_6 -> V_256 ) ;
if ( ! V_11 )
return true ;
return ( F_255 ( V_11 ) -> V_508 . V_509 & V_510 ) ;
}
static void F_320 ( struct V_5 * V_6 )
{
struct V_382 * V_383 ;
struct V_10 * V_11 ;
T_8 V_384 ;
if ( ! V_6 -> V_259 )
return;
V_383 = ( void * ) V_6 -> V_259 -> V_180 ;
V_384 = F_186 ( V_383 -> V_384 ) ;
if ( V_384 == V_22 )
return;
V_11 = F_321 ( V_6 -> V_259 , V_195 ) ;
if ( ! V_11 )
return;
F_322 ( & V_6 -> V_256 , V_11 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_254 ) ;
}
void F_323 ( struct V_5 * V_6 , T_8 V_384 , T_7 V_558 ,
T_15 * V_559 ,
T_16 * V_560 )
{
struct V_10 * V_11 ;
unsigned long V_15 ;
F_23 ( L_57 , V_384 , V_558 ) ;
if ( ! F_274 ( V_6 , V_384 ) ) {
if ( F_6 ( V_243 , & V_6 -> V_15 ) && V_384 == V_22 )
F_320 ( V_6 ) ;
return;
}
if ( ! V_558 && ! F_319 ( V_6 ) )
return;
if ( F_255 ( V_6 -> V_259 ) -> V_508 . V_509 & V_561 ) {
* V_560 = F_255 ( V_6 -> V_259 ) -> V_508 . V_560 ;
return;
}
if ( F_255 ( V_6 -> V_259 ) -> V_508 . V_559 ) {
* V_559 = F_255 ( V_6 -> V_259 ) -> V_508 . V_559 ;
return;
}
F_324 ( & V_6 -> V_256 . V_461 , V_15 ) ;
while ( ( V_11 = F_325 ( & V_6 -> V_256 ) ) ) {
if ( F_255 ( V_11 ) -> V_508 . V_509 & V_510 ) {
F_326 ( & V_6 -> V_256 , V_11 ) ;
break;
}
if ( F_255 ( V_11 ) -> V_508 . V_509 & V_561 )
* V_560 = F_255 ( V_11 ) -> V_508 . V_560 ;
else
* V_559 = F_255 ( V_11 ) -> V_508 . V_559 ;
F_14 ( V_11 ) ;
}
F_327 ( & V_6 -> V_256 . V_461 , V_15 ) ;
}
static void V_471 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 , V_255 ) ;
struct V_10 * V_11 ;
F_23 ( L_11 , V_6 -> V_37 ) ;
while ( ( V_11 = F_304 ( & V_6 -> V_257 ) ) ) {
F_268 ( V_6 , V_11 ) ;
if ( F_269 ( & V_6 -> V_506 ) ) {
F_270 ( V_6 , V_11 ) ;
}
if ( F_2 ( V_6 , V_28 ) ) {
F_14 ( V_11 ) ;
continue;
}
if ( F_6 ( V_243 , & V_6 -> V_15 ) ) {
switch ( F_252 ( V_11 ) ) {
case V_495 :
case V_496 :
F_14 ( V_11 ) ;
continue;
}
}
switch ( F_252 ( V_11 ) ) {
case V_493 :
F_23 ( L_58 , V_6 -> V_37 ) ;
F_328 ( V_6 , V_11 ) ;
break;
case V_495 :
F_23 ( L_59 , V_6 -> V_37 ) ;
F_311 ( V_6 , V_11 ) ;
break;
case V_496 :
F_23 ( L_60 , V_6 -> V_37 ) ;
F_317 ( V_6 , V_11 ) ;
break;
default:
F_14 ( V_11 ) ;
break;
}
}
}
static void V_472 ( struct V_331 * V_332 )
{
struct V_5 * V_6 = F_153 ( V_332 , struct V_5 , V_254 ) ;
struct V_10 * V_11 ;
F_23 ( L_61 , V_6 -> V_37 ,
F_269 ( & V_6 -> V_242 ) , F_329 ( & V_6 -> V_256 ) ) ;
if ( F_269 ( & V_6 -> V_242 ) ) {
V_11 = F_304 ( & V_6 -> V_256 ) ;
if ( ! V_11 )
return;
F_14 ( V_6 -> V_259 ) ;
V_6 -> V_259 = F_321 ( V_11 , V_195 ) ;
if ( V_6 -> V_259 ) {
F_330 ( & V_6 -> V_242 ) ;
F_267 ( V_6 , V_11 ) ;
if ( F_6 ( V_38 , & V_6 -> V_15 ) )
F_123 ( & V_6 -> V_273 ) ;
else
F_331 ( & V_6 -> V_273 ,
V_21 ) ;
} else {
F_322 ( & V_6 -> V_256 , V_11 ) ;
F_187 ( V_6 -> V_280 , & V_6 -> V_254 ) ;
}
}
}
