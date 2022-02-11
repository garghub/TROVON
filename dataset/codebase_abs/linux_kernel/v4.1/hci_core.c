static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_2 , V_10 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_6 ( struct V_4 * V_4 , const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_11 * V_12 ;
char V_9 [ 32 ] ;
T_3 V_13 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_14 ;
int V_15 ;
if ( ! F_8 ( V_16 , & V_2 -> V_17 ) )
return - V_18 ;
if ( F_9 ( V_9 , V_5 , V_13 ) )
return - V_19 ;
V_9 [ V_13 ] = '\0' ;
if ( F_10 ( V_9 , & V_14 ) )
return - V_20 ;
if ( V_14 == F_4 ( V_2 , V_10 ) )
return - V_21 ;
F_11 ( V_2 ) ;
if ( V_14 )
V_12 = F_12 ( V_2 , V_22 , 0 , NULL ,
V_23 ) ;
else
V_12 = F_12 ( V_2 , V_24 , 0 , NULL ,
V_23 ) ;
F_13 ( V_2 ) ;
if ( F_14 ( V_12 ) )
return F_15 ( V_12 ) ;
V_15 = - F_16 ( V_12 -> V_25 [ 0 ] ) ;
F_17 ( V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
F_18 ( V_2 , V_10 ) ;
return V_6 ;
}
static void F_19 ( struct V_1 * V_2 , T_5 V_26 , T_6 V_27 ,
struct V_11 * V_12 )
{
F_20 ( L_1 , V_2 -> V_28 , V_26 ) ;
if ( V_2 -> V_29 == V_30 ) {
V_2 -> V_31 = V_26 ;
V_2 -> V_29 = V_32 ;
if ( V_12 )
V_2 -> V_33 = F_21 ( V_12 ) ;
F_22 ( & V_2 -> V_34 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , int V_15 )
{
F_20 ( L_2 , V_2 -> V_28 , V_15 ) ;
if ( V_2 -> V_29 == V_30 ) {
V_2 -> V_31 = V_15 ;
V_2 -> V_29 = V_35 ;
F_22 ( & V_2 -> V_34 ) ;
}
}
struct V_11 * F_24 ( struct V_1 * V_2 , T_6 V_27 , T_7 V_36 ,
const void * V_37 , T_5 V_3 , T_7 V_38 )
{
F_25 ( V_39 , V_40 ) ;
struct V_41 V_42 ;
struct V_11 * V_12 ;
int V_15 = 0 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
F_26 ( & V_42 , V_2 ) ;
F_27 ( & V_42 , V_27 , V_36 , V_37 , V_3 ) ;
V_2 -> V_29 = V_30 ;
F_28 ( & V_2 -> V_34 , & V_39 ) ;
F_29 ( V_43 ) ;
V_15 = F_30 ( & V_42 , F_19 ) ;
if ( V_15 < 0 ) {
F_31 ( & V_2 -> V_34 , & V_39 ) ;
F_29 ( V_44 ) ;
return F_32 ( V_15 ) ;
}
F_33 ( V_38 ) ;
F_31 ( & V_2 -> V_34 , & V_39 ) ;
if ( F_34 ( V_40 ) )
return F_32 ( - V_45 ) ;
switch ( V_2 -> V_29 ) {
case V_32 :
V_15 = - F_16 ( V_2 -> V_31 ) ;
break;
case V_35 :
V_15 = - V_2 -> V_31 ;
break;
default:
V_15 = - V_46 ;
break;
}
V_2 -> V_29 = V_2 -> V_31 = 0 ;
V_12 = V_2 -> V_33 ;
V_2 -> V_33 = NULL ;
F_20 ( L_4 , V_2 -> V_28 , V_15 ) ;
if ( V_15 < 0 ) {
F_17 ( V_12 ) ;
return F_32 ( V_15 ) ;
}
if ( ! V_12 )
return F_32 ( - V_47 ) ;
return V_12 ;
}
struct V_11 * F_12 ( struct V_1 * V_2 , T_6 V_27 , T_7 V_36 ,
const void * V_37 , T_7 V_38 )
{
return F_24 ( V_2 , V_27 , V_36 , V_37 , 0 , V_38 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
void (* F_36)( struct V_41 * V_42 ,
unsigned long V_48 ) ,
unsigned long V_48 , T_8 V_38 )
{
struct V_41 V_42 ;
F_25 ( V_39 , V_40 ) ;
int V_15 = 0 ;
F_20 ( L_5 , V_2 -> V_28 ) ;
F_26 ( & V_42 , V_2 ) ;
V_2 -> V_29 = V_30 ;
F_36 ( & V_42 , V_48 ) ;
F_28 ( & V_2 -> V_34 , & V_39 ) ;
F_29 ( V_43 ) ;
V_15 = F_30 ( & V_42 , F_19 ) ;
if ( V_15 < 0 ) {
V_2 -> V_29 = 0 ;
F_31 ( & V_2 -> V_34 , & V_39 ) ;
F_29 ( V_44 ) ;
if ( V_15 == - V_47 )
return 0 ;
return V_15 ;
}
F_33 ( V_38 ) ;
F_31 ( & V_2 -> V_34 , & V_39 ) ;
if ( F_34 ( V_40 ) )
return - V_45 ;
switch ( V_2 -> V_29 ) {
case V_32 :
V_15 = - F_16 ( V_2 -> V_31 ) ;
break;
case V_35 :
V_15 = - V_2 -> V_31 ;
break;
default:
V_15 = - V_46 ;
break;
}
V_2 -> V_29 = V_2 -> V_31 = 0 ;
F_20 ( L_4 , V_2 -> V_28 , V_15 ) ;
return V_15 ;
}
static int F_37 ( struct V_1 * V_2 ,
void (* V_42)( struct V_41 * V_42 ,
unsigned long V_48 ) ,
unsigned long V_48 , T_8 V_38 )
{
int V_49 ;
if ( ! F_8 ( V_16 , & V_2 -> V_17 ) )
return - V_18 ;
F_11 ( V_2 ) ;
V_49 = F_35 ( V_2 , V_42 , V_48 , V_38 ) ;
F_13 ( V_2 ) ;
return V_49 ;
}
static void F_38 ( struct V_41 * V_42 , unsigned long V_48 )
{
F_20 ( L_6 , V_42 -> V_2 -> V_28 , V_48 ) ;
F_39 ( V_50 , & V_42 -> V_2 -> V_17 ) ;
F_40 ( V_42 , V_24 , 0 , NULL ) ;
}
static void F_41 ( struct V_41 * V_42 )
{
V_42 -> V_2 -> V_51 = V_52 ;
F_40 ( V_42 , V_53 , 0 , NULL ) ;
F_40 ( V_42 , V_54 , 0 , NULL ) ;
F_40 ( V_42 , V_55 , 0 , NULL ) ;
}
static void F_42 ( struct V_41 * V_42 )
{
V_42 -> V_2 -> V_51 = V_56 ;
F_40 ( V_42 , V_54 , 0 , NULL ) ;
F_40 ( V_42 , V_57 , 0 , NULL ) ;
F_40 ( V_42 , V_58 , 0 , NULL ) ;
F_40 ( V_42 , V_59 , 0 , NULL ) ;
F_40 ( V_42 , V_60 , 0 , NULL ) ;
F_40 ( V_42 , V_61 , 0 , NULL ) ;
}
static void F_43 ( struct V_41 * V_42 )
{
if ( V_42 -> V_2 -> V_62 [ 14 ] & 0x20 )
F_40 ( V_42 , V_53 , 0 , NULL ) ;
}
static void F_44 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
F_20 ( L_6 , V_2 -> V_28 , V_48 ) ;
if ( ! F_8 ( V_63 , & V_2 -> V_64 ) )
F_38 ( V_42 , 0 ) ;
switch ( V_2 -> V_65 ) {
case V_66 :
F_41 ( V_42 ) ;
break;
case V_67 :
F_42 ( V_42 ) ;
break;
default:
F_45 ( L_7 , V_2 -> V_65 ) ;
break;
}
}
static void F_46 ( struct V_41 * V_42 )
{
T_9 V_37 ;
T_10 V_68 ;
F_40 ( V_42 , V_69 , 0 , NULL ) ;
F_40 ( V_42 , V_70 , 0 , NULL ) ;
F_40 ( V_42 , V_71 , 0 , NULL ) ;
F_40 ( V_42 , V_72 , 0 , NULL ) ;
F_40 ( V_42 , V_73 , 0 , NULL ) ;
F_40 ( V_42 , V_74 , 0 , NULL ) ;
V_68 = V_75 ;
F_40 ( V_42 , V_76 , 1 , & V_68 ) ;
V_37 = F_47 ( 0x7d00 ) ;
F_40 ( V_42 , V_77 , 2 , & V_37 ) ;
}
static void F_48 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
F_40 ( V_42 , V_78 , 0 , NULL ) ;
F_40 ( V_42 , V_79 , 0 , NULL ) ;
F_40 ( V_42 , V_80 , 0 , NULL ) ;
F_40 ( V_42 , V_81 , 0 , NULL ) ;
F_40 ( V_42 , V_82 , 0 , NULL ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( V_2 , V_83 ) ;
}
static void F_51 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
T_5 V_84 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_85 < V_86 )
return;
if ( F_49 ( V_2 ) ) {
V_84 [ 4 ] |= 0x01 ;
V_84 [ 4 ] |= 0x02 ;
V_84 [ 4 ] |= 0x04 ;
V_84 [ 5 ] |= 0x08 ;
V_84 [ 5 ] |= 0x10 ;
} else {
memset ( V_84 , 0 , sizeof( V_84 ) ) ;
V_84 [ 0 ] |= 0x10 ;
V_84 [ 1 ] |= 0x08 ;
V_84 [ 1 ] |= 0x20 ;
V_84 [ 1 ] |= 0x40 ;
V_84 [ 1 ] |= 0x80 ;
V_84 [ 2 ] |= 0x04 ;
V_84 [ 3 ] |= 0x02 ;
if ( V_2 -> V_87 [ 0 ] & V_88 ) {
V_84 [ 0 ] |= 0x80 ;
V_84 [ 5 ] |= 0x80 ;
}
}
if ( F_52 ( V_2 ) )
V_84 [ 4 ] |= 0x02 ;
if ( F_53 ( V_2 ) )
V_84 [ 5 ] |= 0x20 ;
if ( F_54 ( V_2 ) )
V_84 [ 5 ] |= 0x80 ;
if ( F_55 ( V_2 ) )
V_84 [ 5 ] |= 0x40 ;
if ( F_56 ( V_2 ) )
V_84 [ 7 ] |= 0x01 ;
if ( F_57 ( V_2 ) )
V_84 [ 6 ] |= 0x80 ;
if ( F_58 ( V_2 ) ) {
V_84 [ 6 ] |= 0x01 ;
V_84 [ 6 ] |= 0x02 ;
V_84 [ 6 ] |= 0x04 ;
V_84 [ 6 ] |= 0x08 ;
V_84 [ 6 ] |= 0x10 ;
V_84 [ 6 ] |= 0x20 ;
V_84 [ 7 ] |= 0x04 ;
V_84 [ 7 ] |= 0x08 ;
V_84 [ 7 ] |= 0x10 ;
}
if ( F_59 ( V_2 ) )
V_84 [ 7 ] |= 0x20 ;
F_40 ( V_42 , V_89 , sizeof( V_84 ) , V_84 ) ;
}
static void F_60 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
if ( V_2 -> V_65 == V_67 )
return F_43 ( V_42 ) ;
if ( F_49 ( V_2 ) )
F_46 ( V_42 ) ;
else
F_61 ( V_2 , V_90 ) ;
if ( F_59 ( V_2 ) )
F_48 ( V_42 ) ;
if ( V_2 -> V_85 > V_91 &&
! F_8 ( V_92 , & V_2 -> V_64 ) )
F_40 ( V_42 , V_57 , 0 , NULL ) ;
if ( F_58 ( V_2 ) ) {
V_2 -> V_93 = 0x01 ;
if ( F_4 ( V_2 , V_94 ) ) {
T_5 V_95 = 0x01 ;
F_40 ( V_42 , V_96 ,
sizeof( V_95 ) , & V_95 ) ;
} else {
struct V_97 V_98 ;
memset ( V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
F_40 ( V_42 , V_100 , sizeof( V_98 ) , & V_98 ) ;
}
}
if ( F_52 ( V_2 ) ||
F_8 ( V_101 , & V_2 -> V_64 ) ) {
T_5 V_95 ;
V_95 = F_55 ( V_2 ) ? 0x02 : 0x01 ;
F_40 ( V_42 , V_102 , 1 , & V_95 ) ;
}
if ( F_62 ( V_2 ) )
F_40 ( V_42 , V_103 , 0 , NULL ) ;
if ( F_63 ( V_2 ) ) {
struct V_104 V_98 ;
V_98 . V_105 = 0x01 ;
F_40 ( V_42 , V_106 ,
sizeof( V_98 ) , & V_98 ) ;
}
if ( F_4 ( V_2 , V_107 ) ) {
T_5 V_14 = 1 ;
F_40 ( V_42 , V_108 , sizeof( V_14 ) ,
& V_14 ) ;
}
}
static void F_64 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_109 V_98 ;
T_6 V_110 = 0 ;
if ( F_65 ( V_2 ) )
V_110 |= V_111 ;
if ( F_66 ( V_2 ) )
V_110 |= V_112 ;
if ( F_67 ( V_2 ) )
V_110 |= V_113 ;
if ( F_68 ( V_2 ) )
V_110 |= V_114 ;
V_98 . V_115 = F_47 ( V_110 ) ;
F_40 ( V_42 , V_116 , sizeof( V_98 ) , & V_98 ) ;
}
static void F_69 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_117 V_98 ;
if ( ! F_49 ( V_2 ) )
return;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
if ( F_4 ( V_2 , V_83 ) ) {
V_98 . V_118 = 0x01 ;
V_98 . V_119 = 0x00 ;
}
if ( V_98 . V_118 != F_70 ( V_2 ) )
F_40 ( V_42 , V_120 , sizeof( V_98 ) ,
& V_98 ) ;
}
static void F_71 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
T_5 V_84 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_72 ( V_2 ) ) {
V_84 [ 1 ] |= 0x40 ;
V_84 [ 1 ] |= 0x80 ;
V_84 [ 2 ] |= 0x10 ;
V_84 [ 2 ] |= 0x20 ;
}
if ( F_73 ( V_2 ) ) {
V_84 [ 2 ] |= 0x01 ;
V_84 [ 2 ] |= 0x02 ;
V_84 [ 2 ] |= 0x04 ;
V_84 [ 2 ] |= 0x08 ;
}
if ( F_74 ( V_2 ) || V_2 -> V_87 [ 0 ] & V_121 )
V_84 [ 2 ] |= 0x80 ;
F_40 ( V_42 , V_122 , sizeof( V_84 ) , V_84 ) ;
}
static void F_75 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
T_5 V_123 ;
F_51 ( V_42 ) ;
if ( V_2 -> V_62 [ 6 ] & 0x20 ) {
struct V_124 V_98 ;
F_76 ( & V_98 . V_125 , V_126 ) ;
V_98 . V_127 = 0x01 ;
F_40 ( V_42 , V_128 , sizeof( V_98 ) , & V_98 ) ;
}
if ( V_2 -> V_62 [ 5 ] & 0x10 )
F_64 ( V_42 ) ;
if ( V_2 -> V_62 [ 8 ] & 0x01 )
F_40 ( V_42 , V_129 , 0 , NULL ) ;
if ( V_2 -> V_62 [ 13 ] & 0x01 )
F_40 ( V_42 , V_130 , 0 , NULL ) ;
if ( F_59 ( V_2 ) ) {
T_5 V_84 [ 8 ] ;
memset ( V_84 , 0 , sizeof( V_84 ) ) ;
V_84 [ 0 ] = 0x0f ;
if ( V_2 -> V_87 [ 0 ] & V_88 )
V_84 [ 0 ] |= 0x10 ;
if ( V_2 -> V_87 [ 0 ] & V_131 )
V_84 [ 0 ] |= 0x20 ;
if ( V_2 -> V_87 [ 0 ] & V_132 )
V_84 [ 0 ] |= 0x40 ;
if ( V_2 -> V_87 [ 0 ] & V_133 )
V_84 [ 1 ] |= 0x04 ;
if ( V_2 -> V_62 [ 34 ] & 0x02 )
V_84 [ 0 ] |= 0x80 ;
if ( V_2 -> V_62 [ 34 ] & 0x04 )
V_84 [ 1 ] |= 0x01 ;
F_40 ( V_42 , V_134 , sizeof( V_84 ) ,
V_84 ) ;
if ( V_2 -> V_62 [ 25 ] & 0x40 ) {
F_40 ( V_42 , V_135 , 0 , NULL ) ;
}
if ( V_2 -> V_87 [ 0 ] & V_132 ) {
F_40 ( V_42 , V_136 , 0 , NULL ) ;
F_40 ( V_42 , V_137 , 0 , NULL ) ;
}
F_69 ( V_42 ) ;
}
for ( V_123 = 2 ; V_123 < V_138 && V_123 <= V_2 -> V_93 ; V_123 ++ ) {
struct V_104 V_98 ;
V_98 . V_105 = V_123 ;
F_40 ( V_42 , V_106 ,
sizeof( V_98 ) , & V_98 ) ;
}
}
static void F_77 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
if ( V_2 -> V_62 [ 6 ] & 0x80 &&
! F_8 ( V_139 , & V_2 -> V_64 ) ) {
struct V_140 V_98 ;
F_76 ( & V_98 . V_125 , V_126 ) ;
V_98 . V_141 = 0x01 ;
F_40 ( V_42 , V_142 ,
sizeof( V_98 ) , & V_98 ) ;
}
if ( V_2 -> V_62 [ 22 ] & 0x04 )
F_71 ( V_42 ) ;
if ( V_2 -> V_62 [ 29 ] & 0x20 )
F_40 ( V_42 , V_143 , 0 , NULL ) ;
if ( V_2 -> V_62 [ 30 ] & 0x08 )
F_40 ( V_42 , V_144 , 0 , NULL ) ;
if ( F_78 ( V_2 ) )
F_40 ( V_42 , V_145 , 0 , NULL ) ;
if ( F_4 ( V_2 , V_94 ) &&
F_79 ( V_2 ) ) {
T_5 V_146 = 0x01 ;
F_40 ( V_42 , V_147 ,
sizeof( V_146 ) , & V_146 ) ;
}
}
static int F_80 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_35 ( V_2 , F_44 , 0 , V_148 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_4 ( V_2 , V_149 ) ) {
F_81 ( L_8 , 0644 , V_2 -> V_150 , V_2 ,
& V_151 ) ;
}
V_15 = F_35 ( V_2 , F_60 , 0 , V_148 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_2 -> V_65 != V_66 )
return 0 ;
V_15 = F_35 ( V_2 , F_75 , 0 , V_148 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_35 ( V_2 , F_77 , 0 , V_148 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! F_4 ( V_2 , V_149 ) &&
! F_4 ( V_2 , V_152 ) )
return 0 ;
F_82 ( V_2 ) ;
if ( F_49 ( V_2 ) )
F_83 ( V_2 ) ;
if ( F_59 ( V_2 ) )
F_84 ( V_2 ) ;
return 0 ;
}
static void F_85 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
F_20 ( L_6 , V_2 -> V_28 , V_48 ) ;
if ( ! F_8 ( V_63 , & V_2 -> V_64 ) )
F_38 ( V_42 , 0 ) ;
F_40 ( V_42 , V_54 , 0 , NULL ) ;
if ( V_2 -> V_153 )
F_40 ( V_42 , V_55 , 0 , NULL ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_15 ;
if ( F_8 ( V_154 , & V_2 -> V_64 ) )
return 0 ;
V_15 = F_35 ( V_2 , F_85 , 0 , V_148 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static void F_87 ( struct V_41 * V_42 , unsigned long V_48 )
{
T_10 V_155 = V_48 ;
F_20 ( L_9 , V_42 -> V_2 -> V_28 , V_155 ) ;
F_40 ( V_42 , V_156 , 1 , & V_155 ) ;
}
static void F_88 ( struct V_41 * V_42 , unsigned long V_48 )
{
T_10 V_157 = V_48 ;
F_20 ( L_9 , V_42 -> V_2 -> V_28 , V_157 ) ;
F_40 ( V_42 , V_108 , 1 , & V_157 ) ;
}
static void F_89 ( struct V_41 * V_42 , unsigned long V_48 )
{
T_10 V_158 = V_48 ;
F_20 ( L_9 , V_42 -> V_2 -> V_28 , V_158 ) ;
F_40 ( V_42 , V_159 , 1 , & V_158 ) ;
}
static void F_90 ( struct V_41 * V_42 , unsigned long V_48 )
{
T_9 V_115 = F_47 ( V_48 ) ;
F_20 ( L_9 , V_42 -> V_2 -> V_28 , V_115 ) ;
F_40 ( V_42 , V_116 , 2 , & V_115 ) ;
}
struct V_1 * F_91 ( int V_160 )
{
struct V_1 * V_2 = NULL , * V_161 ;
F_20 ( L_10 , V_160 ) ;
if ( V_160 < 0 )
return NULL ;
F_92 ( & V_162 ) ;
F_93 (d, &hci_dev_list, list) {
if ( V_161 -> V_163 == V_160 ) {
V_2 = F_94 ( V_161 ) ;
break;
}
}
F_95 ( & V_162 ) ;
return V_2 ;
}
bool F_96 ( struct V_1 * V_2 )
{
struct V_164 * V_165 = & V_2 -> V_166 ;
switch ( V_165 -> V_167 ) {
case V_168 :
case V_169 :
return true ;
default:
return false ;
}
}
void F_97 ( struct V_1 * V_2 , int V_167 )
{
int V_170 = V_2 -> V_166 . V_167 ;
F_20 ( L_11 , V_2 -> V_28 , V_2 -> V_166 . V_167 , V_167 ) ;
if ( V_170 == V_167 )
return;
V_2 -> V_166 . V_167 = V_167 ;
switch ( V_167 ) {
case V_171 :
F_98 ( V_2 ) ;
if ( V_170 != V_172 )
F_99 ( V_2 , 0 ) ;
break;
case V_172 :
break;
case V_168 :
F_99 ( V_2 , 1 ) ;
break;
case V_169 :
break;
case V_173 :
break;
}
}
void F_100 ( struct V_1 * V_2 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_175 * V_123 , * V_176 ;
F_101 (p, n, &cache->all, all) {
F_102 ( & V_123 -> V_177 ) ;
F_103 ( V_123 ) ;
}
F_104 ( & V_174 -> V_178 ) ;
F_104 ( & V_174 -> V_179 ) ;
}
struct V_175 * F_105 ( struct V_1 * V_2 ,
T_11 * V_125 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_175 * V_180 ;
F_20 ( L_12 , V_174 , V_125 ) ;
F_93 (e, &cache->all, all) {
if ( ! F_106 ( & V_180 -> V_25 . V_125 , V_125 ) )
return V_180 ;
}
return NULL ;
}
struct V_175 * F_107 ( struct V_1 * V_2 ,
T_11 * V_125 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_175 * V_180 ;
F_20 ( L_12 , V_174 , V_125 ) ;
F_93 (e, &cache->unknown, list) {
if ( ! F_106 ( & V_180 -> V_25 . V_125 , V_125 ) )
return V_180 ;
}
return NULL ;
}
struct V_175 * F_108 ( struct V_1 * V_2 ,
T_11 * V_125 ,
int V_167 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_175 * V_180 ;
F_20 ( L_13 , V_174 , V_125 , V_167 ) ;
F_93 (e, &cache->resolve, list) {
if ( ! F_106 ( V_125 , V_126 ) && V_180 -> V_181 == V_167 )
return V_180 ;
if ( ! F_106 ( & V_180 -> V_25 . V_125 , V_125 ) )
return V_180 ;
}
return NULL ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_175 * V_182 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_183 * V_184 = & V_174 -> V_179 ;
struct V_175 * V_123 ;
F_102 ( & V_182 -> V_185 ) ;
F_93 (p, &cache->resolve, list) {
if ( V_123 -> V_181 != V_186 &&
abs ( V_123 -> V_25 . V_187 ) >= abs ( V_182 -> V_25 . V_187 ) )
break;
V_184 = & V_123 -> V_185 ;
}
F_110 ( & V_182 -> V_185 , V_184 ) ;
}
T_7 F_111 ( struct V_1 * V_2 , struct V_188 * V_25 ,
bool V_189 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_175 * V_182 ;
T_7 V_17 = 0 ;
F_20 ( L_12 , V_174 , & V_25 -> V_125 ) ;
F_112 ( V_2 , & V_25 -> V_125 , V_190 ) ;
if ( ! V_25 -> V_191 )
V_17 |= V_192 ;
V_182 = F_105 ( V_2 , & V_25 -> V_125 ) ;
if ( V_182 ) {
if ( ! V_182 -> V_25 . V_191 )
V_17 |= V_192 ;
if ( V_182 -> V_181 == V_193 &&
V_25 -> V_187 != V_182 -> V_25 . V_187 ) {
V_182 -> V_25 . V_187 = V_25 -> V_187 ;
F_109 ( V_2 , V_182 ) ;
}
goto V_194;
}
V_182 = F_113 ( sizeof( * V_182 ) , V_195 ) ;
if ( ! V_182 ) {
V_17 |= V_196 ;
goto V_197;
}
F_110 ( & V_182 -> V_177 , & V_174 -> V_177 ) ;
if ( V_189 ) {
V_182 -> V_181 = V_198 ;
} else {
V_182 -> V_181 = V_199 ;
F_110 ( & V_182 -> V_185 , & V_174 -> V_178 ) ;
}
V_194:
if ( V_189 && V_182 -> V_181 != V_198 &&
V_182 -> V_181 != V_186 ) {
V_182 -> V_181 = V_198 ;
F_102 ( & V_182 -> V_185 ) ;
}
memcpy ( & V_182 -> V_25 , V_25 , sizeof( * V_25 ) ) ;
V_182 -> V_200 = V_201 ;
V_174 -> V_200 = V_201 ;
if ( V_182 -> V_181 == V_199 )
V_17 |= V_196 ;
V_197:
return V_17 ;
}
static int F_114 ( struct V_1 * V_2 , int V_202 , T_10 * V_9 )
{
struct V_164 * V_174 = & V_2 -> V_166 ;
struct V_203 * V_204 = (struct V_203 * ) V_9 ;
struct V_175 * V_180 ;
int V_205 = 0 ;
F_93 (e, &cache->all, all) {
struct V_188 * V_25 = & V_180 -> V_25 ;
if ( V_205 >= V_202 )
break;
F_76 ( & V_204 -> V_125 , & V_25 -> V_125 ) ;
V_204 -> V_206 = V_25 -> V_206 ;
V_204 -> V_207 = V_25 -> V_207 ;
V_204 -> V_208 = V_25 -> V_208 ;
memcpy ( V_204 -> V_209 , V_25 -> V_209 , 3 ) ;
V_204 -> V_210 = V_25 -> V_210 ;
V_204 ++ ;
V_205 ++ ;
}
F_20 ( L_14 , V_174 , V_205 ) ;
return V_205 ;
}
static void F_115 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_211 * V_212 = (struct V_211 * ) V_48 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_213 V_98 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( F_8 ( V_214 , & V_2 -> V_17 ) )
return;
memcpy ( & V_98 . V_215 , & V_212 -> V_215 , 3 ) ;
V_98 . V_216 = V_212 -> V_216 ;
V_98 . V_217 = V_212 -> V_217 ;
F_40 ( V_42 , V_218 , sizeof( V_98 ) , & V_98 ) ;
}
int F_116 ( void T_2 * V_219 )
{
T_10 T_2 * V_220 = V_219 ;
struct V_211 V_212 ;
struct V_1 * V_2 ;
int V_15 = 0 , V_221 = 0 , V_222 ;
long V_223 ;
T_10 * V_9 ;
if ( F_9 ( & V_212 , V_220 , sizeof( V_212 ) ) )
return - V_19 ;
V_2 = F_91 ( V_212 . V_224 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_15 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_15 = - V_229 ;
goto V_197;
}
if ( V_2 -> V_65 != V_66 ) {
V_15 = - V_229 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_90 ) ) {
V_15 = - V_229 ;
goto V_197;
}
F_117 ( V_2 ) ;
if ( F_118 ( V_2 ) > V_230 ||
F_119 ( V_2 ) || V_212 . V_17 & V_231 ) {
F_100 ( V_2 ) ;
V_221 = 1 ;
}
F_120 ( V_2 ) ;
V_223 = V_212 . V_216 * F_121 ( 2000 ) ;
if ( V_221 ) {
V_15 = F_37 ( V_2 , F_115 , ( unsigned long ) & V_212 ,
V_223 ) ;
if ( V_15 < 0 )
goto V_197;
if ( F_122 ( & V_2 -> V_17 , V_214 ,
V_43 ) )
return - V_45 ;
}
V_222 = ( V_212 . V_217 == 0 ) ? 255 : V_212 . V_217 ;
V_9 = F_123 ( sizeof( struct V_203 ) * V_222 , V_195 ) ;
if ( ! V_9 ) {
V_15 = - V_232 ;
goto V_197;
}
F_117 ( V_2 ) ;
V_212 . V_217 = F_114 ( V_2 , V_222 , V_9 ) ;
F_120 ( V_2 ) ;
F_20 ( L_15 , V_212 . V_217 ) ;
if ( ! F_124 ( V_220 , & V_212 , sizeof( V_212 ) ) ) {
V_220 += sizeof( V_212 ) ;
if ( F_124 ( V_220 , V_9 , sizeof( struct V_203 ) *
V_212 . V_217 ) )
V_15 = - V_19 ;
} else
V_15 = - V_19 ;
F_103 ( V_9 ) ;
V_197:
F_125 ( V_2 ) ;
return V_15 ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_49 = 0 ;
F_20 ( L_16 , V_2 -> V_28 , V_2 ) ;
F_11 ( V_2 ) ;
if ( F_4 ( V_2 , V_233 ) ) {
V_49 = - V_225 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_149 ) &&
! F_4 ( V_2 , V_152 ) ) {
if ( F_4 ( V_2 , V_234 ) ) {
V_49 = - V_235 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_226 ) &&
V_2 -> V_65 == V_66 &&
! F_106 ( & V_2 -> V_125 , V_126 ) &&
! F_106 ( & V_2 -> V_236 , V_126 ) ) {
V_49 = - V_237 ;
goto V_197;
}
}
if ( F_8 ( V_16 , & V_2 -> V_17 ) ) {
V_49 = - V_21 ;
goto V_197;
}
if ( V_2 -> V_238 ( V_2 ) ) {
V_49 = - V_239 ;
goto V_197;
}
F_127 ( & V_2 -> V_240 , 1 ) ;
F_39 ( V_241 , & V_2 -> V_17 ) ;
if ( F_4 ( V_2 , V_149 ) ) {
if ( V_2 -> V_242 )
V_49 = V_2 -> V_242 ( V_2 ) ;
if ( F_8 ( V_243 , & V_2 -> V_64 ) ||
F_8 ( V_244 , & V_2 -> V_64 ) )
F_50 ( V_2 , V_228 ) ;
if ( F_4 ( V_2 , V_228 ) )
V_49 = F_86 ( V_2 ) ;
}
if ( F_4 ( V_2 , V_152 ) ) {
if ( F_106 ( & V_2 -> V_245 , V_126 ) &&
V_2 -> V_153 )
V_49 = V_2 -> V_153 ( V_2 , & V_2 -> V_245 ) ;
else
V_49 = - V_237 ;
}
if ( ! V_49 ) {
if ( ! F_4 ( V_2 , V_228 ) &&
! F_4 ( V_2 , V_226 ) )
V_49 = F_80 ( V_2 ) ;
}
F_128 ( V_241 , & V_2 -> V_17 ) ;
if ( ! V_49 ) {
F_94 ( V_2 ) ;
F_50 ( V_2 , V_246 ) ;
F_39 ( V_16 , & V_2 -> V_17 ) ;
F_1 ( V_2 , V_247 ) ;
if ( ! F_4 ( V_2 , V_149 ) &&
! F_4 ( V_2 , V_152 ) &&
! F_4 ( V_2 , V_228 ) &&
! F_4 ( V_2 , V_226 ) &&
V_2 -> V_65 == V_66 ) {
F_117 ( V_2 ) ;
F_129 ( V_2 , 1 ) ;
F_120 ( V_2 ) ;
}
} else {
F_130 ( & V_2 -> V_248 ) ;
F_130 ( & V_2 -> V_249 ) ;
F_130 ( & V_2 -> V_250 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_131 ( & V_2 -> V_252 ) ;
if ( V_2 -> V_253 )
V_2 -> V_253 ( V_2 ) ;
if ( V_2 -> V_254 ) {
F_17 ( V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
}
V_2 -> V_255 ( V_2 ) ;
V_2 -> V_17 &= F_132 ( V_256 ) ;
}
V_197:
F_13 ( V_2 ) ;
return V_49 ;
}
int F_133 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_228 ) &&
! F_4 ( V_2 , V_226 ) ) {
V_15 = - V_229 ;
goto V_197;
}
if ( F_134 ( V_2 , V_258 ) )
F_135 ( & V_2 -> V_259 ) ;
F_136 ( V_2 -> V_260 ) ;
if ( ! F_4 ( V_2 , V_226 ) &&
! F_4 ( V_2 , V_261 ) )
F_50 ( V_2 , V_262 ) ;
V_15 = F_126 ( V_2 ) ;
V_197:
F_125 ( V_2 ) ;
return V_15 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_263 * V_123 ;
F_93 (p, &hdev->le_conn_params, list) {
if ( V_123 -> V_264 ) {
F_138 ( V_123 -> V_264 ) ;
F_139 ( V_123 -> V_264 ) ;
V_123 -> V_264 = NULL ;
}
F_140 ( & V_123 -> V_265 ) ;
}
F_20 ( L_17 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
F_20 ( L_16 , V_2 -> V_28 , V_2 ) ;
if ( ! F_4 ( V_2 , V_233 ) &&
F_8 ( V_16 , & V_2 -> V_17 ) ) {
if ( V_2 -> V_266 )
V_2 -> V_266 ( V_2 ) ;
}
F_135 ( & V_2 -> V_259 ) ;
F_23 ( V_2 , V_225 ) ;
F_11 ( V_2 ) ;
if ( ! F_142 ( V_16 , & V_2 -> V_17 ) ) {
F_143 ( & V_2 -> V_267 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
F_130 ( & V_2 -> V_248 ) ;
F_130 ( & V_2 -> V_250 ) ;
if ( V_2 -> V_268 > 0 ) {
F_135 ( & V_2 -> V_269 ) ;
V_2 -> V_268 = 0 ;
F_61 ( V_2 , V_270 ) ;
F_61 ( V_2 , V_271 ) ;
}
if ( F_134 ( V_2 , V_272 ) )
F_135 ( & V_2 -> V_273 ) ;
F_143 ( & V_2 -> V_274 ) ;
F_143 ( & V_2 -> V_275 ) ;
if ( F_4 ( V_2 , V_261 ) )
F_143 ( & V_2 -> V_276 ) ;
F_144 ( V_2 -> V_277 ) ;
F_117 ( V_2 ) ;
F_97 ( V_2 , V_171 ) ;
if ( ! F_134 ( V_2 , V_258 ) ) {
if ( V_2 -> V_65 == V_66 )
F_129 ( V_2 , 0 ) ;
}
F_100 ( V_2 ) ;
F_137 ( V_2 ) ;
F_145 ( V_2 ) ;
F_120 ( V_2 ) ;
F_146 ( V_2 ) ;
F_1 ( V_2 , V_278 ) ;
if ( V_2 -> V_253 )
V_2 -> V_253 ( V_2 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_127 ( & V_2 -> V_240 , 1 ) ;
if ( ! F_4 ( V_2 , V_258 ) &&
! F_4 ( V_2 , V_228 ) &&
F_8 ( V_63 , & V_2 -> V_64 ) ) {
F_39 ( V_241 , & V_2 -> V_17 ) ;
F_35 ( V_2 , F_38 , 0 , V_23 ) ;
F_128 ( V_241 , & V_2 -> V_17 ) ;
}
F_130 ( & V_2 -> V_249 ) ;
F_131 ( & V_2 -> V_252 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_131 ( & V_2 -> V_279 ) ;
if ( V_2 -> V_254 ) {
F_143 ( & V_2 -> V_267 ) ;
F_17 ( V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
}
V_2 -> V_255 ( V_2 ) ;
V_2 -> V_17 &= F_132 ( V_256 ) ;
F_147 ( V_2 ) ;
V_2 -> V_280 = V_281 ;
memset ( V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
memset ( V_2 -> V_209 , 0 , sizeof( V_2 -> V_209 ) ) ;
F_76 ( & V_2 -> V_282 , V_126 ) ;
F_13 ( V_2 ) ;
F_125 ( V_2 ) ;
return 0 ;
}
int F_148 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_15 = - V_227 ;
goto V_197;
}
if ( F_134 ( V_2 , V_258 ) )
F_135 ( & V_2 -> V_259 ) ;
V_15 = F_141 ( V_2 ) ;
V_197:
F_125 ( V_2 ) ;
return V_15 ;
}
static int F_149 ( struct V_1 * V_2 )
{
int V_49 ;
F_20 ( L_16 , V_2 -> V_28 , V_2 ) ;
F_11 ( V_2 ) ;
F_131 ( & V_2 -> V_252 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_144 ( V_2 -> V_277 ) ;
F_117 ( V_2 ) ;
F_100 ( V_2 ) ;
F_145 ( V_2 ) ;
F_120 ( V_2 ) ;
if ( V_2 -> V_253 )
V_2 -> V_253 ( V_2 ) ;
F_127 ( & V_2 -> V_240 , 1 ) ;
V_2 -> V_283 = 0 ; V_2 -> V_284 = 0 ; V_2 -> V_285 = 0 ;
V_49 = F_35 ( V_2 , F_38 , 0 , V_148 ) ;
F_13 ( V_2 ) ;
return V_49 ;
}
int F_150 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( ! F_8 ( V_16 , & V_2 -> V_17 ) ) {
V_15 = - V_18 ;
goto V_197;
}
if ( F_4 ( V_2 , V_226 ) ) {
V_15 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_15 = - V_229 ;
goto V_197;
}
V_15 = F_149 ( V_2 ) ;
V_197:
F_125 ( V_2 ) ;
return V_15 ;
}
int F_151 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_49 = 0 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_49 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_49 = - V_229 ;
goto V_197;
}
memset ( & V_2 -> V_286 , 0 , sizeof( struct V_287 ) ) ;
V_197:
F_125 ( V_2 ) ;
return V_49 ;
}
static void F_152 ( struct V_1 * V_2 , T_5 V_155 )
{
bool V_288 , V_289 ;
F_20 ( L_18 , V_2 -> V_28 , V_155 ) ;
if ( ( V_155 & V_290 ) )
V_288 = ! F_153 ( V_2 ,
V_291 ) ;
else
V_288 = F_134 ( V_2 ,
V_291 ) ;
if ( ( V_155 & V_292 ) ) {
V_289 = ! F_153 ( V_2 ,
V_270 ) ;
} else {
F_61 ( V_2 , V_271 ) ;
V_289 = F_134 ( V_2 ,
V_270 ) ;
}
if ( ! F_4 ( V_2 , V_261 ) )
return;
if ( V_288 || V_289 ) {
F_50 ( V_2 , V_90 ) ;
if ( F_4 ( V_2 , V_83 ) )
F_154 ( V_2 ) ;
F_155 ( V_2 ) ;
}
}
int F_156 ( unsigned int V_293 , void T_2 * V_219 )
{
struct V_1 * V_2 ;
struct V_294 V_295 ;
int V_15 = 0 ;
if ( F_9 ( & V_295 , V_219 , sizeof( V_295 ) ) )
return - V_19 ;
V_2 = F_91 ( V_295 . V_224 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_15 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_15 = - V_229 ;
goto V_197;
}
if ( V_2 -> V_65 != V_66 ) {
V_15 = - V_229 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_90 ) ) {
V_15 = - V_229 ;
goto V_197;
}
switch ( V_293 ) {
case V_296 :
V_15 = F_37 ( V_2 , F_88 , V_295 . V_297 ,
V_148 ) ;
break;
case V_298 :
if ( ! F_157 ( V_2 ) ) {
V_15 = - V_229 ;
break;
}
if ( ! F_8 ( V_299 , & V_2 -> V_17 ) ) {
V_15 = F_37 ( V_2 , F_88 , V_295 . V_297 ,
V_148 ) ;
if ( V_15 )
break;
}
V_15 = F_37 ( V_2 , F_89 , V_295 . V_297 ,
V_148 ) ;
break;
case V_300 :
V_15 = F_37 ( V_2 , F_87 , V_295 . V_297 ,
V_148 ) ;
if ( ! V_15 )
F_152 ( V_2 , V_295 . V_297 ) ;
break;
case V_301 :
V_15 = F_37 ( V_2 , F_90 , V_295 . V_297 ,
V_148 ) ;
break;
case V_302 :
V_2 -> V_303 = ( ( T_12 ) V_295 . V_297 ) &
( V_304 | V_305 ) ;
break;
case V_306 :
V_2 -> V_307 = ( T_12 ) V_295 . V_297 ;
break;
case V_308 :
V_2 -> V_309 = * ( ( T_12 * ) & V_295 . V_297 + 1 ) ;
V_2 -> V_310 = * ( ( T_12 * ) & V_295 . V_297 + 0 ) ;
break;
case V_311 :
V_2 -> V_312 = * ( ( T_12 * ) & V_295 . V_297 + 1 ) ;
V_2 -> V_313 = * ( ( T_12 * ) & V_295 . V_297 + 0 ) ;
break;
default:
V_15 = - V_20 ;
break;
}
V_197:
F_125 ( V_2 ) ;
return V_15 ;
}
int F_158 ( void T_2 * V_219 )
{
struct V_1 * V_2 ;
struct V_314 * V_315 ;
struct V_294 * V_295 ;
int V_176 = 0 , V_316 , V_15 ;
T_12 V_317 ;
if ( F_159 ( V_317 , ( T_12 T_2 * ) V_219 ) )
return - V_19 ;
if ( ! V_317 || V_317 > ( V_318 * 2 ) / sizeof( * V_295 ) )
return - V_20 ;
V_316 = sizeof( * V_315 ) + V_317 * sizeof( * V_295 ) ;
V_315 = F_113 ( V_316 , V_195 ) ;
if ( ! V_315 )
return - V_232 ;
V_295 = V_315 -> V_319 ;
F_92 ( & V_162 ) ;
F_93 (hdev, &hci_dev_list, list) {
unsigned long V_17 = V_2 -> V_17 ;
if ( F_4 ( V_2 , V_258 ) )
V_17 &= ~ F_132 ( V_16 ) ;
( V_295 + V_176 ) -> V_224 = V_2 -> V_163 ;
( V_295 + V_176 ) -> V_297 = V_17 ;
if ( ++ V_176 >= V_317 )
break;
}
F_95 ( & V_162 ) ;
V_315 -> V_317 = V_176 ;
V_316 = sizeof( * V_315 ) + V_176 * sizeof( * V_295 ) ;
V_15 = F_124 ( V_219 , V_315 , V_316 ) ;
F_103 ( V_315 ) ;
return V_15 ? - V_19 : 0 ;
}
int F_160 ( void T_2 * V_219 )
{
struct V_1 * V_2 ;
struct V_320 V_321 ;
unsigned long V_17 ;
int V_15 = 0 ;
if ( F_9 ( & V_321 , V_219 , sizeof( V_321 ) ) )
return - V_19 ;
V_2 = F_91 ( V_321 . V_224 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_258 ) )
V_17 = V_2 -> V_17 & ~ F_132 ( V_16 ) ;
else
V_17 = V_2 -> V_17 ;
strcpy ( V_321 . V_28 , V_2 -> V_28 ) ;
V_321 . V_125 = V_2 -> V_125 ;
V_321 . type = ( V_2 -> V_322 & 0x0f ) | ( ( V_2 -> V_65 & 0x03 ) << 4 ) ;
V_321 . V_17 = V_17 ;
V_321 . V_307 = V_2 -> V_307 ;
if ( F_49 ( V_2 ) ) {
V_321 . V_309 = V_2 -> V_309 ;
V_321 . V_310 = V_2 -> V_310 ;
V_321 . V_312 = V_2 -> V_312 ;
V_321 . V_313 = V_2 -> V_313 ;
} else {
V_321 . V_309 = V_2 -> V_323 ;
V_321 . V_310 = V_2 -> V_324 ;
V_321 . V_312 = 0 ;
V_321 . V_313 = 0 ;
}
V_321 . V_110 = V_2 -> V_110 ;
V_321 . V_303 = V_2 -> V_303 ;
memcpy ( & V_321 . V_286 , & V_2 -> V_286 , sizeof( V_321 . V_286 ) ) ;
memcpy ( & V_321 . V_325 , & V_2 -> V_325 , sizeof( V_321 . V_325 ) ) ;
if ( F_124 ( V_219 , & V_321 , sizeof( V_321 ) ) )
V_15 = - V_19 ;
F_125 ( V_2 ) ;
return V_15 ;
}
static int F_161 ( void * V_25 , bool V_326 )
{
struct V_1 * V_2 = V_25 ;
F_20 ( L_19 , V_2 , V_2 -> V_28 , V_326 ) ;
if ( F_4 ( V_2 , V_226 ) )
return - V_227 ;
if ( V_326 ) {
F_50 ( V_2 , V_234 ) ;
if ( ! F_4 ( V_2 , V_149 ) &&
! F_4 ( V_2 , V_152 ) )
F_141 ( V_2 ) ;
} else {
F_61 ( V_2 , V_234 ) ;
}
return 0 ;
}
static void F_162 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 , V_329 ) ;
int V_15 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
V_15 = F_126 ( V_2 ) ;
if ( V_15 < 0 ) {
F_117 ( V_2 ) ;
F_164 ( V_2 , V_15 ) ;
F_120 ( V_2 ) ;
return;
}
if ( F_4 ( V_2 , V_234 ) ||
F_4 ( V_2 , V_228 ) ||
( V_2 -> V_65 == V_66 &&
! F_106 ( & V_2 -> V_125 , V_126 ) &&
! F_106 ( & V_2 -> V_236 , V_126 ) ) ) {
F_61 ( V_2 , V_258 ) ;
F_141 ( V_2 ) ;
} else if ( F_4 ( V_2 , V_258 ) ) {
F_165 ( V_2 -> V_260 , & V_2 -> V_259 ,
V_330 ) ;
}
if ( F_134 ( V_2 , V_149 ) ) {
if ( F_4 ( V_2 , V_228 ) )
F_39 ( V_256 , & V_2 -> V_17 ) ;
F_166 ( V_2 ) ;
} else if ( F_134 ( V_2 , V_152 ) ) {
if ( ! F_4 ( V_2 , V_228 ) )
F_128 ( V_256 , & V_2 -> V_17 ) ;
F_166 ( V_2 ) ;
}
}
static void F_167 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 ,
V_259 . V_328 ) ;
F_20 ( L_3 , V_2 -> V_28 ) ;
F_141 ( V_2 ) ;
}
static void F_168 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 , V_331 ) ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( V_2 -> V_332 )
V_2 -> V_332 ( V_2 , V_2 -> V_333 ) ;
else
F_45 ( L_20 , V_2 -> V_28 ,
V_2 -> V_333 ) ;
if ( F_141 ( V_2 ) )
return;
F_126 ( V_2 ) ;
}
static void F_169 ( struct V_327 * V_328 )
{
struct V_1 * V_2 ;
V_2 = F_163 ( V_328 , struct V_1 , V_269 . V_328 ) ;
F_20 ( L_3 , V_2 -> V_28 ) ;
F_170 ( V_2 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_334 * V_335 , * V_336 ;
F_101 (uuid, tmp, &hdev->uuids, list) {
F_102 ( & V_335 -> V_185 ) ;
F_103 ( V_335 ) ;
}
}
void F_172 ( struct V_1 * V_2 )
{
struct V_337 * V_338 ;
F_173 (key, &hdev->link_keys, list) {
F_174 ( & V_338 -> V_185 ) ;
F_175 ( V_338 , V_339 ) ;
}
}
void F_176 ( struct V_1 * V_2 )
{
struct V_340 * V_341 ;
F_173 (k, &hdev->long_term_keys, list) {
F_174 ( & V_341 -> V_185 ) ;
F_175 ( V_341 , V_339 ) ;
}
}
void F_177 ( struct V_1 * V_2 )
{
struct V_342 * V_341 ;
F_173 (k, &hdev->identity_resolving_keys, list) {
F_174 ( & V_341 -> V_185 ) ;
F_175 ( V_341 , V_339 ) ;
}
}
struct V_337 * F_178 ( struct V_1 * V_2 , T_11 * V_125 )
{
struct V_337 * V_341 ;
F_179 () ;
F_173 (k, &hdev->link_keys, list) {
if ( F_106 ( V_125 , & V_341 -> V_125 ) == 0 ) {
F_180 () ;
return V_341 ;
}
}
F_180 () ;
return NULL ;
}
static bool F_181 ( struct V_1 * V_2 , struct V_343 * V_264 ,
T_5 V_344 , T_5 V_345 )
{
if ( V_344 < 0x03 )
return true ;
if ( V_344 == V_346 )
return false ;
if ( V_344 == V_347 && V_345 == 0xff )
return false ;
if ( ! V_264 )
return true ;
if ( V_264 -> type == V_348 )
return true ;
if ( V_264 -> V_349 > 0x01 && V_264 -> V_350 > 0x01 )
return true ;
if ( V_264 -> V_349 == 0x02 || V_264 -> V_349 == 0x03 )
return true ;
if ( V_264 -> V_350 == 0x02 || V_264 -> V_350 == 0x03 )
return true ;
return false ;
}
static T_5 F_182 ( T_5 type )
{
if ( type == V_351 )
return V_352 ;
return V_353 ;
}
struct V_340 * F_183 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 V_354 , T_5 V_355 )
{
struct V_340 * V_341 ;
F_179 () ;
F_173 (k, &hdev->long_term_keys, list) {
if ( V_354 != V_341 -> V_356 || F_106 ( V_125 , & V_341 -> V_125 ) )
continue;
if ( F_184 ( V_341 ) || F_182 ( V_341 -> type ) == V_355 ) {
F_180 () ;
return V_341 ;
}
}
F_180 () ;
return NULL ;
}
struct V_342 * F_185 ( struct V_1 * V_2 , T_11 * V_357 )
{
struct V_342 * V_358 ;
F_179 () ;
F_173 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_106 ( & V_358 -> V_357 , V_357 ) ) {
F_180 () ;
return V_358 ;
}
}
F_173 (irk, &hdev->identity_resolving_keys, list) {
if ( F_186 ( V_2 , V_358 -> V_359 , V_357 ) ) {
F_76 ( & V_358 -> V_357 , V_357 ) ;
F_180 () ;
return V_358 ;
}
}
F_180 () ;
return NULL ;
}
struct V_342 * F_187 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 V_354 )
{
struct V_342 * V_358 ;
if ( V_354 == V_360 && ( V_125 -> V_361 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_179 () ;
F_173 (irk, &hdev->identity_resolving_keys, list) {
if ( V_354 == V_358 -> V_354 &&
F_106 ( V_125 , & V_358 -> V_125 ) == 0 ) {
F_180 () ;
return V_358 ;
}
}
F_180 () ;
return NULL ;
}
struct V_337 * F_188 ( struct V_1 * V_2 , struct V_343 * V_264 ,
T_11 * V_125 , T_5 * V_359 , T_5 type ,
T_5 V_362 , bool * V_363 )
{
struct V_337 * V_338 , * V_364 ;
T_5 V_345 ;
V_364 = F_178 ( V_2 , V_125 ) ;
if ( V_364 ) {
V_345 = V_364 -> type ;
V_338 = V_364 ;
} else {
V_345 = V_264 ? V_264 -> V_344 : 0xff ;
V_338 = F_113 ( sizeof( * V_338 ) , V_195 ) ;
if ( ! V_338 )
return NULL ;
F_189 ( & V_338 -> V_185 , & V_2 -> V_365 ) ;
}
F_20 ( L_21 , V_2 -> V_28 , V_125 , type ) ;
if ( type == V_347 &&
( ! V_264 || V_264 -> V_350 == 0xff ) && V_345 == 0xff ) {
type = V_366 ;
if ( V_264 )
V_264 -> V_344 = type ;
}
F_76 ( & V_338 -> V_125 , V_125 ) ;
memcpy ( V_338 -> V_359 , V_359 , V_367 ) ;
V_338 -> V_362 = V_362 ;
if ( type == V_347 )
V_338 -> type = V_345 ;
else
V_338 -> type = type ;
if ( V_363 )
* V_363 = F_181 ( V_2 , V_264 , type ,
V_345 ) ;
return V_338 ;
}
struct V_340 * F_190 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 V_354 , T_5 type , T_5 V_368 ,
T_5 V_369 [ 16 ] , T_5 V_370 , T_9 V_371 , T_13 rand )
{
struct V_340 * V_338 , * V_364 ;
T_5 V_355 = F_182 ( type ) ;
V_364 = F_183 ( V_2 , V_125 , V_354 , V_355 ) ;
if ( V_364 )
V_338 = V_364 ;
else {
V_338 = F_113 ( sizeof( * V_338 ) , V_195 ) ;
if ( ! V_338 )
return NULL ;
F_189 ( & V_338 -> V_185 , & V_2 -> V_372 ) ;
}
F_76 ( & V_338 -> V_125 , V_125 ) ;
V_338 -> V_356 = V_354 ;
memcpy ( V_338 -> V_359 , V_369 , sizeof( V_338 -> V_359 ) ) ;
V_338 -> V_368 = V_368 ;
V_338 -> V_371 = V_371 ;
V_338 -> rand = rand ;
V_338 -> V_370 = V_370 ;
V_338 -> type = type ;
return V_338 ;
}
struct V_342 * F_191 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 V_354 , T_5 V_359 [ 16 ] , T_11 * V_357 )
{
struct V_342 * V_358 ;
V_358 = F_187 ( V_2 , V_125 , V_354 ) ;
if ( ! V_358 ) {
V_358 = F_113 ( sizeof( * V_358 ) , V_195 ) ;
if ( ! V_358 )
return NULL ;
F_76 ( & V_358 -> V_125 , V_125 ) ;
V_358 -> V_354 = V_354 ;
F_189 ( & V_358 -> V_185 , & V_2 -> V_373 ) ;
}
memcpy ( V_358 -> V_359 , V_359 , 16 ) ;
F_76 ( & V_358 -> V_357 , V_357 ) ;
return V_358 ;
}
int F_192 ( struct V_1 * V_2 , T_11 * V_125 )
{
struct V_337 * V_338 ;
V_338 = F_178 ( V_2 , V_125 ) ;
if ( ! V_338 )
return - V_374 ;
F_20 ( L_22 , V_2 -> V_28 , V_125 ) ;
F_174 ( & V_338 -> V_185 ) ;
F_175 ( V_338 , V_339 ) ;
return 0 ;
}
int F_193 ( struct V_1 * V_2 , T_11 * V_125 , T_5 V_356 )
{
struct V_340 * V_341 ;
int V_375 = 0 ;
F_173 (k, &hdev->long_term_keys, list) {
if ( F_106 ( V_125 , & V_341 -> V_125 ) || V_341 -> V_356 != V_356 )
continue;
F_20 ( L_22 , V_2 -> V_28 , V_125 ) ;
F_174 ( & V_341 -> V_185 ) ;
F_175 ( V_341 , V_339 ) ;
V_375 ++ ;
}
return V_375 ? 0 : - V_374 ;
}
void F_194 ( struct V_1 * V_2 , T_11 * V_125 , T_5 V_354 )
{
struct V_342 * V_341 ;
F_173 (k, &hdev->identity_resolving_keys, list) {
if ( F_106 ( V_125 , & V_341 -> V_125 ) || V_341 -> V_354 != V_354 )
continue;
F_20 ( L_22 , V_2 -> V_28 , V_125 ) ;
F_174 ( & V_341 -> V_185 ) ;
F_175 ( V_341 , V_339 ) ;
}
}
bool F_195 ( struct V_1 * V_2 , T_11 * V_125 , T_5 type )
{
struct V_340 * V_341 ;
struct V_342 * V_358 ;
T_5 V_354 ;
if ( type == V_190 ) {
if ( F_178 ( V_2 , V_125 ) )
return true ;
return false ;
}
if ( type == V_376 )
V_354 = V_377 ;
else
V_354 = V_360 ;
V_358 = F_196 ( V_2 , V_125 , V_354 ) ;
if ( V_358 ) {
V_125 = & V_358 -> V_125 ;
V_354 = V_358 -> V_354 ;
}
F_179 () ;
F_173 (k, &hdev->long_term_keys, list) {
if ( V_341 -> V_356 == V_354 && ! F_106 ( V_125 , & V_341 -> V_125 ) ) {
F_180 () ;
return true ;
}
}
F_180 () ;
return false ;
}
static void F_197 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 ,
V_267 . V_328 ) ;
if ( V_2 -> V_254 ) {
struct V_378 * V_379 = ( void * ) V_2 -> V_254 -> V_25 ;
T_6 V_27 = F_198 ( V_379 -> V_27 ) ;
F_45 ( L_23 , V_2 -> V_28 , V_27 ) ;
} else {
F_45 ( L_24 , V_2 -> V_28 ) ;
}
F_127 ( & V_2 -> V_240 , 1 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_249 ) ;
}
struct V_380 * F_200 ( struct V_1 * V_2 ,
T_11 * V_125 , T_5 V_356 )
{
struct V_380 * V_25 ;
F_93 (data, &hdev->remote_oob_data, list) {
if ( F_106 ( V_125 , & V_25 -> V_125 ) != 0 )
continue;
if ( V_25 -> V_356 != V_356 )
continue;
return V_25 ;
}
return NULL ;
}
int F_112 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 V_356 )
{
struct V_380 * V_25 ;
V_25 = F_200 ( V_2 , V_125 , V_356 ) ;
if ( ! V_25 )
return - V_374 ;
F_20 ( L_25 , V_2 -> V_28 , V_125 , V_356 ) ;
F_102 ( & V_25 -> V_185 ) ;
F_103 ( V_25 ) ;
return 0 ;
}
void F_201 ( struct V_1 * V_2 )
{
struct V_380 * V_25 , * V_176 ;
F_101 (data, n, &hdev->remote_oob_data, list) {
F_102 ( & V_25 -> V_185 ) ;
F_103 ( V_25 ) ;
}
}
int F_202 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 V_356 , T_5 * V_381 , T_5 * V_382 ,
T_5 * V_383 , T_5 * V_384 )
{
struct V_380 * V_25 ;
V_25 = F_200 ( V_2 , V_125 , V_356 ) ;
if ( ! V_25 ) {
V_25 = F_123 ( sizeof( * V_25 ) , V_195 ) ;
if ( ! V_25 )
return - V_232 ;
F_76 ( & V_25 -> V_125 , V_125 ) ;
V_25 -> V_356 = V_356 ;
F_110 ( & V_25 -> V_185 , & V_2 -> V_385 ) ;
}
if ( V_381 && V_382 ) {
memcpy ( V_25 -> V_381 , V_381 , sizeof( V_25 -> V_381 ) ) ;
memcpy ( V_25 -> V_382 , V_382 , sizeof( V_25 -> V_382 ) ) ;
if ( V_383 && V_384 )
V_25 -> V_386 = 0x03 ;
} else {
memset ( V_25 -> V_381 , 0 , sizeof( V_25 -> V_381 ) ) ;
memset ( V_25 -> V_382 , 0 , sizeof( V_25 -> V_382 ) ) ;
if ( V_383 && V_384 )
V_25 -> V_386 = 0x02 ;
else
V_25 -> V_386 = 0x00 ;
}
if ( V_383 && V_384 ) {
memcpy ( V_25 -> V_383 , V_383 , sizeof( V_25 -> V_383 ) ) ;
memcpy ( V_25 -> V_384 , V_384 , sizeof( V_25 -> V_384 ) ) ;
} else {
memset ( V_25 -> V_383 , 0 , sizeof( V_25 -> V_383 ) ) ;
memset ( V_25 -> V_384 , 0 , sizeof( V_25 -> V_384 ) ) ;
if ( V_381 && V_382 )
V_25 -> V_386 = 0x01 ;
}
F_20 ( L_26 , V_2 -> V_28 , V_125 ) ;
return 0 ;
}
struct V_387 * F_203 ( struct V_183 * V_387 ,
T_11 * V_125 , T_5 type )
{
struct V_387 * V_361 ;
F_93 (b, bdaddr_list, list) {
if ( ! F_106 ( & V_361 -> V_125 , V_125 ) && V_361 -> V_356 == type )
return V_361 ;
}
return NULL ;
}
void F_204 ( struct V_183 * V_387 )
{
struct V_183 * V_123 , * V_176 ;
F_205 (p, n, bdaddr_list) {
struct V_387 * V_361 = F_206 ( V_123 , struct V_387 , V_185 ) ;
F_102 ( V_123 ) ;
F_103 ( V_361 ) ;
}
}
int F_207 ( struct V_183 * V_185 , T_11 * V_125 , T_5 type )
{
struct V_387 * V_388 ;
if ( ! F_106 ( V_125 , V_126 ) )
return - V_389 ;
if ( F_203 ( V_185 , V_125 , type ) )
return - V_390 ;
V_388 = F_113 ( sizeof( * V_388 ) , V_195 ) ;
if ( ! V_388 )
return - V_232 ;
F_76 ( & V_388 -> V_125 , V_125 ) ;
V_388 -> V_356 = type ;
F_110 ( & V_388 -> V_185 , V_185 ) ;
return 0 ;
}
int F_208 ( struct V_183 * V_185 , T_11 * V_125 , T_5 type )
{
struct V_387 * V_388 ;
if ( ! F_106 ( V_125 , V_126 ) ) {
F_204 ( V_185 ) ;
return 0 ;
}
V_388 = F_203 ( V_185 , V_125 , type ) ;
if ( ! V_388 )
return - V_374 ;
F_102 ( & V_388 -> V_185 ) ;
F_103 ( V_388 ) ;
return 0 ;
}
struct V_263 * F_209 ( struct V_1 * V_2 ,
T_11 * V_391 , T_5 V_354 )
{
struct V_263 * V_392 ;
if ( ! F_210 ( V_391 , V_354 ) )
return NULL ;
F_93 (params, &hdev->le_conn_params, list) {
if ( F_106 ( & V_392 -> V_391 , V_391 ) == 0 &&
V_392 -> V_354 == V_354 ) {
return V_392 ;
}
}
return NULL ;
}
struct V_263 * F_211 ( struct V_183 * V_185 ,
T_11 * V_391 , T_5 V_354 )
{
struct V_263 * V_37 ;
if ( ! F_210 ( V_391 , V_354 ) )
return NULL ;
F_93 (param, list, action) {
if ( F_106 ( & V_37 -> V_391 , V_391 ) == 0 &&
V_37 -> V_354 == V_354 )
return V_37 ;
}
return NULL ;
}
struct V_263 * F_212 ( struct V_1 * V_2 ,
T_11 * V_391 , T_5 V_354 )
{
struct V_263 * V_392 ;
if ( ! F_210 ( V_391 , V_354 ) )
return NULL ;
V_392 = F_209 ( V_2 , V_391 , V_354 ) ;
if ( V_392 )
return V_392 ;
V_392 = F_113 ( sizeof( * V_392 ) , V_195 ) ;
if ( ! V_392 ) {
F_45 ( L_27 ) ;
return NULL ;
}
F_76 ( & V_392 -> V_391 , V_391 ) ;
V_392 -> V_354 = V_354 ;
F_110 ( & V_392 -> V_185 , & V_2 -> V_393 ) ;
F_104 ( & V_392 -> V_265 ) ;
V_392 -> V_394 = V_2 -> V_395 ;
V_392 -> V_396 = V_2 -> V_397 ;
V_392 -> V_398 = V_2 -> V_399 ;
V_392 -> V_400 = V_2 -> V_401 ;
V_392 -> V_402 = V_403 ;
F_20 ( L_28 , V_391 , V_354 ) ;
return V_392 ;
}
static void F_213 ( struct V_263 * V_392 )
{
if ( V_392 -> V_264 ) {
F_138 ( V_392 -> V_264 ) ;
F_139 ( V_392 -> V_264 ) ;
}
F_102 ( & V_392 -> V_265 ) ;
F_102 ( & V_392 -> V_185 ) ;
F_103 ( V_392 ) ;
}
void F_214 ( struct V_1 * V_2 , T_11 * V_391 , T_5 V_354 )
{
struct V_263 * V_392 ;
V_392 = F_209 ( V_2 , V_391 , V_354 ) ;
if ( ! V_392 )
return;
F_213 ( V_392 ) ;
F_98 ( V_2 ) ;
F_20 ( L_28 , V_391 , V_354 ) ;
}
void F_215 ( struct V_1 * V_2 )
{
struct V_263 * V_392 , * V_336 ;
F_101 (params, tmp, &hdev->le_conn_params, list) {
if ( V_392 -> V_402 != V_403 )
continue;
F_102 ( & V_392 -> V_185 ) ;
F_103 ( V_392 ) ;
}
F_20 ( L_29 ) ;
}
void F_216 ( struct V_1 * V_2 )
{
struct V_263 * V_392 , * V_336 ;
F_101 (params, tmp, &hdev->le_conn_params, list)
F_213 ( V_392 ) ;
F_98 ( V_2 ) ;
F_20 ( L_30 ) ;
}
static void F_217 ( struct V_1 * V_2 , T_5 V_404 , T_6 V_27 )
{
if ( V_404 ) {
F_45 ( L_31 , V_404 ) ;
F_117 ( V_2 ) ;
F_97 ( V_2 , V_171 ) ;
F_120 ( V_2 ) ;
return;
}
}
static void F_218 ( struct V_1 * V_2 , T_5 V_404 ,
T_6 V_27 )
{
T_5 V_215 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_213 V_98 ;
int V_15 ;
if ( V_404 ) {
F_45 ( L_32 , V_404 ) ;
return;
}
V_2 -> V_166 . V_405 = 0 ;
switch ( V_2 -> V_166 . type ) {
case V_406 :
F_117 ( V_2 ) ;
F_97 ( V_2 , V_171 ) ;
F_120 ( V_2 ) ;
break;
case V_407 :
F_117 ( V_2 ) ;
if ( F_8 ( V_408 ,
& V_2 -> V_64 ) ) {
if ( ! F_8 ( V_214 , & V_2 -> V_17 ) &&
V_2 -> V_166 . V_167 != V_169 )
F_97 ( V_2 ,
V_171 ) ;
} else {
struct V_41 V_42 ;
F_100 ( V_2 ) ;
F_26 ( & V_42 , V_2 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
memcpy ( & V_98 . V_215 , V_215 , sizeof( V_98 . V_215 ) ) ;
V_98 . V_216 = V_409 ;
F_40 ( & V_42 , V_218 , sizeof( V_98 ) , & V_98 ) ;
V_15 = F_219 ( & V_42 , F_217 ) ;
if ( V_15 ) {
F_45 ( L_33 , V_15 ) ;
F_97 ( V_2 ,
V_171 ) ;
}
}
F_120 ( V_2 ) ;
break;
}
}
static void F_220 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 ,
V_274 . V_328 ) ;
struct V_41 V_42 ;
int V_15 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
F_143 ( & V_2 -> V_275 ) ;
F_26 ( & V_42 , V_2 ) ;
F_221 ( & V_42 ) ;
V_15 = F_219 ( & V_42 , F_218 ) ;
if ( V_15 )
F_45 ( L_34 , V_15 ) ;
}
static void F_222 ( struct V_1 * V_2 , T_5 V_404 ,
T_6 V_27 )
{
unsigned long V_38 , V_410 , V_405 , V_411 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( V_404 ) {
F_45 ( L_35 , V_404 ) ;
return;
}
if ( ! F_8 ( V_412 , & V_2 -> V_64 ) ||
! V_2 -> V_166 . V_405 )
return;
V_410 = V_2 -> V_166 . V_413 ;
V_405 = V_2 -> V_166 . V_405 ;
V_411 = V_201 ;
if ( V_411 - V_405 <= V_410 ) {
int V_414 ;
if ( V_411 >= V_405 )
V_414 = V_411 - V_405 ;
else
V_414 = V_415 - V_405 + V_411 ;
V_38 = V_410 - V_414 ;
} else {
V_38 = 0 ;
}
F_165 ( V_2 -> V_277 ,
& V_2 -> V_274 , V_38 ) ;
}
static void F_223 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 ,
V_275 . V_328 ) ;
struct V_41 V_42 ;
struct V_416 V_98 ;
int V_15 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( ! F_4 ( V_2 , V_417 ) )
return;
F_26 ( & V_42 , V_2 ) ;
F_221 ( & V_42 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_14 = V_418 ;
V_98 . V_419 = V_420 ;
F_40 ( & V_42 , V_421 , sizeof( V_98 ) , & V_98 ) ;
V_15 = F_219 ( & V_42 , F_222 ) ;
if ( V_15 )
F_45 ( L_36 , V_15 ) ;
}
void F_224 ( struct V_1 * V_2 , T_11 * V_125 ,
T_5 * V_356 )
{
if ( F_4 ( V_2 , V_422 ) ||
! F_106 ( & V_2 -> V_125 , V_126 ) ||
( ! F_4 ( V_2 , V_90 ) &&
F_106 ( & V_2 -> V_236 , V_126 ) ) ) {
F_76 ( V_125 , & V_2 -> V_236 ) ;
* V_356 = V_360 ;
} else {
F_76 ( V_125 , & V_2 -> V_125 ) ;
* V_356 = V_377 ;
}
}
struct V_1 * F_225 ( void )
{
struct V_1 * V_2 ;
V_2 = F_113 ( sizeof( * V_2 ) , V_195 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_307 = ( V_423 | V_424 | V_425 ) ;
V_2 -> V_426 = ( V_427 ) ;
V_2 -> V_303 = ( V_305 ) ;
V_2 -> V_428 = 0x01 ;
V_2 -> V_429 = 0x03 ;
V_2 -> V_430 = 0xffff ;
V_2 -> V_431 = V_432 ;
V_2 -> V_433 = V_432 ;
V_2 -> V_434 = 800 ;
V_2 -> V_435 = 80 ;
V_2 -> V_436 = 0x07 ;
V_2 -> V_437 = 0x0800 ;
V_2 -> V_438 = 0x0800 ;
V_2 -> V_439 = 0x0060 ;
V_2 -> V_440 = 0x0030 ;
V_2 -> V_395 = 0x0028 ;
V_2 -> V_397 = 0x0038 ;
V_2 -> V_399 = 0x0000 ;
V_2 -> V_401 = 0x002a ;
V_2 -> V_441 = 0x001b ;
V_2 -> V_442 = 0x0148 ;
V_2 -> V_443 = 0x001b ;
V_2 -> V_444 = 0x0148 ;
V_2 -> V_445 = 0x001b ;
V_2 -> V_446 = 0x0148 ;
V_2 -> V_447 = V_448 ;
V_2 -> V_449 = V_450 ;
V_2 -> V_451 = V_452 ;
V_2 -> V_453 = V_454 ;
F_226 ( & V_2 -> V_455 ) ;
F_226 ( & V_2 -> V_456 ) ;
F_104 ( & V_2 -> V_457 ) ;
F_104 ( & V_2 -> V_458 ) ;
F_104 ( & V_2 -> V_459 ) ;
F_104 ( & V_2 -> V_460 ) ;
F_104 ( & V_2 -> V_365 ) ;
F_104 ( & V_2 -> V_372 ) ;
F_104 ( & V_2 -> V_373 ) ;
F_104 ( & V_2 -> V_385 ) ;
F_104 ( & V_2 -> V_461 ) ;
F_104 ( & V_2 -> V_393 ) ;
F_104 ( & V_2 -> V_462 ) ;
F_104 ( & V_2 -> V_463 ) ;
F_104 ( & V_2 -> V_464 . V_185 ) ;
F_227 ( & V_2 -> V_250 , V_465 ) ;
F_227 ( & V_2 -> V_249 , V_466 ) ;
F_227 ( & V_2 -> V_248 , V_467 ) ;
F_227 ( & V_2 -> V_329 , F_162 ) ;
F_227 ( & V_2 -> V_331 , F_168 ) ;
F_228 ( & V_2 -> V_259 , F_167 ) ;
F_228 ( & V_2 -> V_269 , F_169 ) ;
F_228 ( & V_2 -> V_274 , F_220 ) ;
F_228 ( & V_2 -> V_275 , F_223 ) ;
F_229 ( & V_2 -> V_252 ) ;
F_229 ( & V_2 -> V_251 ) ;
F_229 ( & V_2 -> V_279 ) ;
F_230 ( & V_2 -> V_34 ) ;
F_228 ( & V_2 -> V_267 , F_197 ) ;
F_231 ( V_2 ) ;
F_232 ( V_2 ) ;
F_233 ( V_2 ) ;
return V_2 ;
}
void F_234 ( struct V_1 * V_2 )
{
F_235 ( & V_2 -> V_257 ) ;
}
int F_236 ( struct V_1 * V_2 )
{
int V_163 , error ;
if ( ! V_2 -> V_238 || ! V_2 -> V_255 || ! V_2 -> V_468 )
return - V_20 ;
switch ( V_2 -> V_65 ) {
case V_66 :
V_163 = F_237 ( & V_469 , 0 , 0 , V_195 ) ;
break;
case V_67 :
V_163 = F_237 ( & V_469 , 1 , 0 , V_195 ) ;
break;
default:
return - V_20 ;
}
if ( V_163 < 0 )
return V_163 ;
sprintf ( V_2 -> V_28 , L_37 , V_163 ) ;
V_2 -> V_163 = V_163 ;
F_20 ( L_38 , V_2 , V_2 -> V_28 , V_2 -> V_322 ) ;
V_2 -> V_277 = F_238 ( L_3 , V_470 | V_471 |
V_472 , 1 , V_2 -> V_28 ) ;
if ( ! V_2 -> V_277 ) {
error = - V_232 ;
goto V_15;
}
V_2 -> V_260 = F_238 ( L_3 , V_470 | V_471 |
V_472 , 1 , V_2 -> V_28 ) ;
if ( ! V_2 -> V_260 ) {
F_239 ( V_2 -> V_277 ) ;
error = - V_232 ;
goto V_15;
}
if ( ! F_240 ( V_473 ) )
V_2 -> V_150 = F_241 ( V_2 -> V_28 , V_473 ) ;
F_242 ( & V_2 -> V_257 , L_3 , V_2 -> V_28 ) ;
error = F_243 ( & V_2 -> V_257 ) ;
if ( error < 0 )
goto V_474;
V_2 -> V_475 = F_244 ( V_2 -> V_28 , & V_2 -> V_257 ,
V_476 , & V_477 ,
V_2 ) ;
if ( V_2 -> V_475 ) {
if ( F_245 ( V_2 -> V_475 ) < 0 ) {
F_246 ( V_2 -> V_475 ) ;
V_2 -> V_475 = NULL ;
}
}
if ( V_2 -> V_475 && F_247 ( V_2 -> V_475 ) )
F_50 ( V_2 , V_234 ) ;
F_50 ( V_2 , V_149 ) ;
F_50 ( V_2 , V_258 ) ;
if ( V_2 -> V_65 == V_66 ) {
F_50 ( V_2 , V_90 ) ;
}
F_248 ( & V_162 ) ;
F_110 ( & V_2 -> V_185 , & V_478 ) ;
F_249 ( & V_162 ) ;
if ( F_8 ( V_154 , & V_2 -> V_64 ) )
F_50 ( V_2 , V_228 ) ;
F_1 ( V_2 , V_479 ) ;
F_94 ( V_2 ) ;
F_199 ( V_2 -> V_260 , & V_2 -> V_329 ) ;
return V_163 ;
V_474:
F_239 ( V_2 -> V_277 ) ;
F_239 ( V_2 -> V_260 ) ;
V_15:
F_250 ( & V_469 , V_2 -> V_163 ) ;
return error ;
}
void F_251 ( struct V_1 * V_2 )
{
int V_163 ;
F_20 ( L_38 , V_2 , V_2 -> V_28 , V_2 -> V_322 ) ;
F_50 ( V_2 , V_233 ) ;
V_163 = V_2 -> V_163 ;
F_248 ( & V_162 ) ;
F_102 ( & V_2 -> V_185 ) ;
F_249 ( & V_162 ) ;
F_141 ( V_2 ) ;
F_252 ( & V_2 -> V_329 ) ;
if ( ! F_8 ( V_241 , & V_2 -> V_17 ) &&
! F_4 ( V_2 , V_149 ) &&
! F_4 ( V_2 , V_152 ) ) {
F_117 ( V_2 ) ;
F_253 ( V_2 ) ;
F_120 ( V_2 ) ;
}
F_254 ( ! F_255 ( & V_2 -> V_457 ) ) ;
F_1 ( V_2 , V_480 ) ;
if ( V_2 -> V_475 ) {
F_256 ( V_2 -> V_475 ) ;
F_246 ( V_2 -> V_475 ) ;
}
F_257 ( & V_2 -> V_257 ) ;
F_258 ( V_2 -> V_150 ) ;
F_239 ( V_2 -> V_277 ) ;
F_239 ( V_2 -> V_260 ) ;
F_117 ( V_2 ) ;
F_204 ( & V_2 -> V_458 ) ;
F_204 ( & V_2 -> V_459 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
F_201 ( V_2 ) ;
F_204 ( & V_2 -> V_461 ) ;
F_216 ( V_2 ) ;
F_259 ( V_2 ) ;
F_120 ( V_2 ) ;
F_125 ( V_2 ) ;
F_250 ( & V_469 , V_163 ) ;
}
int F_260 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_481 ) ;
return 0 ;
}
int F_261 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_482 ) ;
return 0 ;
}
int F_262 ( struct V_1 * V_2 )
{
const T_5 V_483 [] = { V_484 , 0x01 , 0x00 } ;
struct V_11 * V_12 ;
V_12 = F_263 ( 3 , V_485 ) ;
if ( ! V_12 )
return - V_232 ;
F_264 ( V_12 ) -> V_307 = V_486 ;
memcpy ( F_265 ( V_12 , 3 ) , V_483 , 3 ) ;
return F_266 ( V_2 , V_12 ) ;
}
int F_266 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! V_2 || ( ! F_8 ( V_16 , & V_2 -> V_17 )
&& ! F_8 ( V_241 , & V_2 -> V_17 ) ) ) {
F_17 ( V_12 ) ;
return - V_487 ;
}
F_264 ( V_12 ) -> V_488 = 1 ;
F_267 ( V_12 ) ;
F_268 ( & V_2 -> V_252 , V_12 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_250 ) ;
return 0 ;
}
int F_269 ( struct V_489 * V_490 )
{
F_20 ( L_39 , V_490 , V_490 -> V_28 ) ;
F_270 ( & V_491 ) ;
F_271 ( & V_490 -> V_185 , & V_492 ) ;
F_272 ( & V_491 ) ;
return 0 ;
}
int F_273 ( struct V_489 * V_490 )
{
F_20 ( L_39 , V_490 , V_490 -> V_28 ) ;
F_270 ( & V_491 ) ;
F_102 ( & V_490 -> V_185 ) ;
F_272 ( & V_491 ) ;
return 0 ;
}
static void F_274 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_15 ;
F_20 ( L_40 , V_2 -> V_28 , F_264 ( V_12 ) -> V_307 , V_12 -> V_493 ) ;
F_267 ( V_12 ) ;
F_275 ( V_2 , V_12 ) ;
if ( F_276 ( & V_2 -> V_494 ) ) {
F_277 ( V_2 , V_12 ) ;
}
F_278 ( V_12 ) ;
V_15 = V_2 -> V_468 ( V_2 , V_12 ) ;
if ( V_15 < 0 ) {
F_45 ( L_41 , V_2 -> V_28 , V_15 ) ;
F_17 ( V_12 ) ;
}
}
int F_279 ( struct V_1 * V_2 , T_12 V_27 , T_8 V_36 ,
const void * V_37 )
{
struct V_11 * V_12 ;
F_20 ( L_42 , V_2 -> V_28 , V_27 , V_36 ) ;
V_12 = F_280 ( V_2 , V_27 , V_36 , V_37 ) ;
if ( ! V_12 ) {
F_45 ( L_43 , V_2 -> V_28 ) ;
return - V_232 ;
}
F_264 ( V_12 ) -> V_42 . V_495 = true ;
F_268 ( & V_2 -> V_251 , V_12 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_249 ) ;
return 0 ;
}
void * F_281 ( struct V_1 * V_2 , T_12 V_27 )
{
struct V_378 * V_496 ;
if ( ! V_2 -> V_254 )
return NULL ;
V_496 = ( void * ) V_2 -> V_254 -> V_25 ;
if ( V_496 -> V_27 != F_47 ( V_27 ) )
return NULL ;
F_20 ( L_44 , V_2 -> V_28 , V_27 ) ;
return V_2 -> V_254 -> V_25 + V_497 ;
}
static void F_282 ( struct V_11 * V_12 , T_12 V_498 , T_12 V_17 )
{
struct V_499 * V_496 ;
int V_493 = V_12 -> V_493 ;
F_283 ( V_12 , V_500 ) ;
F_284 ( V_12 ) ;
V_496 = (struct V_499 * ) F_285 ( V_12 ) ;
V_496 -> V_498 = F_47 ( F_286 ( V_498 , V_17 ) ) ;
V_496 -> V_501 = F_47 ( V_493 ) ;
}
static void F_287 ( struct V_502 * V_503 , struct V_504 * V_505 ,
struct V_11 * V_12 , T_12 V_17 )
{
struct V_343 * V_264 = V_503 -> V_264 ;
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_11 * V_185 ;
V_12 -> V_493 = F_288 ( V_12 ) ;
V_12 -> V_506 = 0 ;
F_264 ( V_12 ) -> V_307 = V_507 ;
switch ( V_2 -> V_65 ) {
case V_66 :
F_282 ( V_12 , V_264 -> V_498 , V_17 ) ;
break;
case V_67 :
F_282 ( V_12 , V_503 -> V_498 , V_17 ) ;
break;
default:
F_45 ( L_45 , V_2 -> V_28 , V_2 -> V_65 ) ;
return;
}
V_185 = F_289 ( V_12 ) -> V_508 ;
if ( ! V_185 ) {
F_20 ( L_46 , V_2 -> V_28 , V_12 , V_12 -> V_493 ) ;
F_268 ( V_505 , V_12 ) ;
} else {
F_20 ( L_47 , V_2 -> V_28 , V_12 , V_12 -> V_493 ) ;
F_289 ( V_12 ) -> V_508 = NULL ;
F_290 ( & V_505 -> V_455 ) ;
F_291 ( V_505 , V_12 ) ;
V_17 &= ~ V_509 ;
V_17 |= V_510 ;
do {
V_12 = V_185 ; V_185 = V_185 -> V_511 ;
F_264 ( V_12 ) -> V_307 = V_507 ;
F_282 ( V_12 , V_264 -> V_498 , V_17 ) ;
F_20 ( L_47 , V_2 -> V_28 , V_12 , V_12 -> V_493 ) ;
F_291 ( V_505 , V_12 ) ;
} while ( V_185 );
F_292 ( & V_505 -> V_455 ) ;
}
}
void F_293 ( struct V_502 * V_503 , struct V_11 * V_12 , T_12 V_17 )
{
struct V_1 * V_2 = V_503 -> V_264 -> V_2 ;
F_20 ( L_48 , V_2 -> V_28 , V_503 , V_17 ) ;
F_287 ( V_503 , & V_503 -> V_512 , V_12 , V_17 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_248 ) ;
}
void F_294 ( struct V_343 * V_264 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_513 V_496 ;
F_20 ( L_49 , V_2 -> V_28 , V_12 -> V_493 ) ;
V_496 . V_498 = F_47 ( V_264 -> V_498 ) ;
V_496 . V_501 = V_12 -> V_493 ;
F_283 ( V_12 , V_514 ) ;
F_284 ( V_12 ) ;
memcpy ( F_285 ( V_12 ) , & V_496 , V_514 ) ;
F_264 ( V_12 ) -> V_307 = V_515 ;
F_268 ( & V_264 -> V_512 , V_12 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_248 ) ;
}
static struct V_343 * F_295 ( struct V_1 * V_2 , T_10 type ,
int * V_516 )
{
struct V_517 * V_518 = & V_2 -> V_464 ;
struct V_343 * V_264 = NULL , * V_519 ;
unsigned int V_202 = 0 , F_7 = ~ 0 ;
F_179 () ;
F_173 (c, &h->list, list) {
if ( V_519 -> type != type || F_296 ( & V_519 -> V_512 ) )
continue;
if ( V_519 -> V_167 != V_520 && V_519 -> V_167 != V_521 )
continue;
V_202 ++ ;
if ( V_519 -> V_379 < F_7 ) {
F_7 = V_519 -> V_379 ;
V_264 = V_519 ;
}
if ( F_297 ( V_2 , type ) == V_202 )
break;
}
F_180 () ;
if ( V_264 ) {
int V_522 , V_523 ;
switch ( V_264 -> type ) {
case V_524 :
V_522 = V_2 -> V_283 ;
break;
case V_525 :
case V_526 :
V_522 = V_2 -> V_284 ;
break;
case V_348 :
V_522 = V_2 -> V_323 ? V_2 -> V_285 : V_2 -> V_283 ;
break;
default:
V_522 = 0 ;
F_45 ( L_50 ) ;
}
V_523 = V_522 / V_202 ;
* V_516 = V_523 ? V_523 : 1 ;
} else
* V_516 = 0 ;
F_20 ( L_51 , V_264 , * V_516 ) ;
return V_264 ;
}
static void F_298 ( struct V_1 * V_2 , T_10 type )
{
struct V_517 * V_518 = & V_2 -> V_464 ;
struct V_343 * V_519 ;
F_45 ( L_52 , V_2 -> V_28 ) ;
F_179 () ;
F_173 (c, &h->list, list) {
if ( V_519 -> type == type && V_519 -> V_379 ) {
F_45 ( L_53 ,
V_2 -> V_28 , & V_519 -> V_527 ) ;
F_299 ( V_519 , V_528 ) ;
}
}
F_180 () ;
}
static struct V_502 * F_300 ( struct V_1 * V_2 , T_10 type ,
int * V_516 )
{
struct V_517 * V_518 = & V_2 -> V_464 ;
struct V_502 * V_503 = NULL ;
unsigned int V_202 = 0 , F_7 = ~ 0 , V_529 = 0 ;
struct V_343 * V_264 ;
int V_522 , V_523 , V_530 = 0 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
F_179 () ;
F_173 (conn, &h->list, list) {
struct V_502 * V_336 ;
if ( V_264 -> type != type )
continue;
if ( V_264 -> V_167 != V_520 && V_264 -> V_167 != V_521 )
continue;
V_530 ++ ;
F_173 (tmp, &conn->chan_list, list) {
struct V_11 * V_12 ;
if ( F_296 ( & V_336 -> V_512 ) )
continue;
V_12 = F_301 ( & V_336 -> V_512 ) ;
if ( V_12 -> V_531 < V_529 )
continue;
if ( V_12 -> V_531 > V_529 ) {
V_202 = 0 ;
F_7 = ~ 0 ;
V_529 = V_12 -> V_531 ;
}
V_202 ++ ;
if ( V_264 -> V_379 < F_7 ) {
F_7 = V_264 -> V_379 ;
V_503 = V_336 ;
}
}
if ( F_297 ( V_2 , type ) == V_530 )
break;
}
F_180 () ;
if ( ! V_503 )
return NULL ;
switch ( V_503 -> V_264 -> type ) {
case V_524 :
V_522 = V_2 -> V_283 ;
break;
case V_532 :
V_522 = V_2 -> V_533 ;
break;
case V_525 :
case V_526 :
V_522 = V_2 -> V_284 ;
break;
case V_348 :
V_522 = V_2 -> V_323 ? V_2 -> V_285 : V_2 -> V_283 ;
break;
default:
V_522 = 0 ;
F_45 ( L_50 ) ;
}
V_523 = V_522 / V_202 ;
* V_516 = V_523 ? V_523 : 1 ;
F_20 ( L_54 , V_503 , * V_516 ) ;
return V_503 ;
}
static void F_302 ( struct V_1 * V_2 , T_10 type )
{
struct V_517 * V_518 = & V_2 -> V_464 ;
struct V_343 * V_264 ;
int V_202 = 0 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
F_179 () ;
F_173 (conn, &h->list, list) {
struct V_502 * V_503 ;
if ( V_264 -> type != type )
continue;
if ( V_264 -> V_167 != V_520 && V_264 -> V_167 != V_521 )
continue;
V_202 ++ ;
F_173 (chan, &conn->chan_list, list) {
struct V_11 * V_12 ;
if ( V_503 -> V_379 ) {
V_503 -> V_379 = 0 ;
continue;
}
if ( F_296 ( & V_503 -> V_512 ) )
continue;
V_12 = F_301 ( & V_503 -> V_512 ) ;
if ( V_12 -> V_531 >= V_534 - 1 )
continue;
V_12 -> V_531 = V_534 - 1 ;
F_20 ( L_55 , V_503 , V_12 ,
V_12 -> V_531 ) ;
}
if ( F_297 ( V_2 , type ) == V_202 )
break;
}
F_180 () ;
}
static inline int F_303 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return F_304 ( V_12 -> V_493 - V_500 , V_2 -> V_535 ) ;
}
static void F_305 ( struct V_1 * V_2 , unsigned int V_522 )
{
if ( ! F_4 ( V_2 , V_228 ) ) {
if ( ! V_522 && F_306 ( V_201 , V_2 -> V_536 +
V_537 ) )
F_298 ( V_2 , V_524 ) ;
}
}
static void F_307 ( struct V_1 * V_2 )
{
unsigned int V_522 = V_2 -> V_283 ;
struct V_502 * V_503 ;
struct V_11 * V_12 ;
int V_516 ;
F_305 ( V_2 , V_522 ) ;
while ( V_2 -> V_283 &&
( V_503 = F_300 ( V_2 , V_524 , & V_516 ) ) ) {
T_7 V_531 = ( F_301 ( & V_503 -> V_512 ) ) -> V_531 ;
while ( V_516 -- && ( V_12 = F_301 ( & V_503 -> V_512 ) ) ) {
F_20 ( L_56 , V_503 , V_12 ,
V_12 -> V_493 , V_12 -> V_531 ) ;
if ( V_12 -> V_531 < V_531 )
break;
V_12 = F_308 ( & V_503 -> V_512 ) ;
F_309 ( V_503 -> V_264 ,
F_264 ( V_12 ) -> V_538 ) ;
F_274 ( V_2 , V_12 ) ;
V_2 -> V_536 = V_201 ;
V_2 -> V_283 -- ;
V_503 -> V_379 ++ ;
V_503 -> V_264 -> V_379 ++ ;
}
}
if ( V_522 != V_2 -> V_283 )
F_302 ( V_2 , V_524 ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
unsigned int V_522 = V_2 -> V_533 ;
struct V_502 * V_503 ;
struct V_11 * V_12 ;
int V_516 ;
T_5 type ;
F_305 ( V_2 , V_522 ) ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( V_2 -> V_65 == V_67 )
type = V_532 ;
else
type = V_524 ;
while ( V_2 -> V_533 > 0 &&
( V_503 = F_300 ( V_2 , type , & V_516 ) ) ) {
T_7 V_531 = ( F_301 ( & V_503 -> V_512 ) ) -> V_531 ;
while ( V_516 > 0 && ( V_12 = F_301 ( & V_503 -> V_512 ) ) ) {
int V_539 ;
F_20 ( L_56 , V_503 , V_12 ,
V_12 -> V_493 , V_12 -> V_531 ) ;
if ( V_12 -> V_531 < V_531 )
break;
V_12 = F_308 ( & V_503 -> V_512 ) ;
V_539 = F_303 ( V_2 , V_12 ) ;
if ( V_539 > V_2 -> V_533 )
return;
F_309 ( V_503 -> V_264 ,
F_264 ( V_12 ) -> V_538 ) ;
F_274 ( V_2 , V_12 ) ;
V_2 -> V_536 = V_201 ;
V_2 -> V_533 -= V_539 ;
V_516 -= V_539 ;
V_503 -> V_379 += V_539 ;
V_503 -> V_264 -> V_379 += V_539 ;
}
}
if ( V_522 != V_2 -> V_533 )
F_302 ( V_2 , type ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( ! F_297 ( V_2 , V_524 ) && V_2 -> V_65 == V_66 )
return;
if ( ! F_297 ( V_2 , V_532 ) && V_2 -> V_65 == V_67 )
return;
switch ( V_2 -> V_51 ) {
case V_52 :
F_307 ( V_2 ) ;
break;
case V_56 :
F_310 ( V_2 ) ;
break;
}
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_343 * V_264 ;
struct V_11 * V_12 ;
int V_516 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( ! F_297 ( V_2 , V_525 ) )
return;
while ( V_2 -> V_284 && ( V_264 = F_295 ( V_2 , V_525 , & V_516 ) ) ) {
while ( V_516 -- && ( V_12 = F_308 ( & V_264 -> V_512 ) ) ) {
F_20 ( L_57 , V_12 , V_12 -> V_493 ) ;
F_274 ( V_2 , V_12 ) ;
V_264 -> V_379 ++ ;
if ( V_264 -> V_379 == ~ 0 )
V_264 -> V_379 = 0 ;
}
}
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_343 * V_264 ;
struct V_11 * V_12 ;
int V_516 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( ! F_297 ( V_2 , V_526 ) )
return;
while ( V_2 -> V_284 && ( V_264 = F_295 ( V_2 , V_526 ,
& V_516 ) ) ) {
while ( V_516 -- && ( V_12 = F_308 ( & V_264 -> V_512 ) ) ) {
F_20 ( L_57 , V_12 , V_12 -> V_493 ) ;
F_274 ( V_2 , V_12 ) ;
V_264 -> V_379 ++ ;
if ( V_264 -> V_379 == ~ 0 )
V_264 -> V_379 = 0 ;
}
}
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_502 * V_503 ;
struct V_11 * V_12 ;
int V_516 , V_522 , V_336 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
if ( ! F_297 ( V_2 , V_348 ) )
return;
if ( ! F_4 ( V_2 , V_228 ) ) {
if ( ! V_2 -> V_285 && V_2 -> V_324 &&
F_306 ( V_201 , V_2 -> V_540 + V_541 * 45 ) )
F_298 ( V_2 , V_348 ) ;
}
V_522 = V_2 -> V_324 ? V_2 -> V_285 : V_2 -> V_283 ;
V_336 = V_522 ;
while ( V_522 && ( V_503 = F_300 ( V_2 , V_348 , & V_516 ) ) ) {
T_7 V_531 = ( F_301 ( & V_503 -> V_512 ) ) -> V_531 ;
while ( V_516 -- && ( V_12 = F_301 ( & V_503 -> V_512 ) ) ) {
F_20 ( L_56 , V_503 , V_12 ,
V_12 -> V_493 , V_12 -> V_531 ) ;
if ( V_12 -> V_531 < V_531 )
break;
V_12 = F_308 ( & V_503 -> V_512 ) ;
F_274 ( V_2 , V_12 ) ;
V_2 -> V_540 = V_201 ;
V_522 -- ;
V_503 -> V_379 ++ ;
V_503 -> V_264 -> V_379 ++ ;
}
}
if ( V_2 -> V_324 )
V_2 -> V_285 = V_522 ;
else
V_2 -> V_283 = V_522 ;
if ( V_522 != V_336 )
F_302 ( V_2 , V_348 ) ;
}
static void V_467 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 , V_248 ) ;
struct V_11 * V_12 ;
F_20 ( L_58 , V_2 -> V_28 , V_2 -> V_283 ,
V_2 -> V_284 , V_2 -> V_285 ) ;
if ( ! F_4 ( V_2 , V_226 ) ) {
F_311 ( V_2 ) ;
F_312 ( V_2 ) ;
F_313 ( V_2 ) ;
F_314 ( V_2 ) ;
}
while ( ( V_12 = F_308 ( & V_2 -> V_279 ) ) )
F_274 ( V_2 , V_12 ) ;
}
static void F_315 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_499 * V_496 = ( void * ) V_12 -> V_25 ;
struct V_343 * V_264 ;
T_12 V_498 , V_17 ;
F_316 ( V_12 , V_500 ) ;
V_498 = F_198 ( V_496 -> V_498 ) ;
V_17 = F_317 ( V_498 ) ;
V_498 = F_318 ( V_498 ) ;
F_20 ( L_59 , V_2 -> V_28 , V_12 -> V_493 ,
V_498 , V_17 ) ;
V_2 -> V_286 . V_542 ++ ;
F_117 ( V_2 ) ;
V_264 = F_319 ( V_2 , V_498 ) ;
F_120 ( V_2 ) ;
if ( V_264 ) {
F_309 ( V_264 , V_543 ) ;
F_320 ( V_264 , V_12 , V_17 ) ;
return;
} else {
F_45 ( L_60 ,
V_2 -> V_28 , V_498 ) ;
}
F_17 ( V_12 ) ;
}
static void F_321 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_513 * V_496 = ( void * ) V_12 -> V_25 ;
struct V_343 * V_264 ;
T_12 V_498 ;
F_316 ( V_12 , V_514 ) ;
V_498 = F_198 ( V_496 -> V_498 ) ;
F_20 ( L_61 , V_2 -> V_28 , V_12 -> V_493 , V_498 ) ;
V_2 -> V_286 . V_544 ++ ;
F_117 ( V_2 ) ;
V_264 = F_319 ( V_2 , V_498 ) ;
F_120 ( V_2 ) ;
if ( V_264 ) {
F_322 ( V_264 , V_12 ) ;
return;
} else {
F_45 ( L_62 ,
V_2 -> V_28 , V_498 ) ;
}
F_17 ( V_12 ) ;
}
static bool F_323 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_301 ( & V_2 -> V_251 ) ;
if ( ! V_12 )
return true ;
return F_264 ( V_12 ) -> V_42 . V_495 ;
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_378 * V_379 ;
struct V_11 * V_12 ;
T_6 V_27 ;
if ( ! V_2 -> V_254 )
return;
V_379 = ( void * ) V_2 -> V_254 -> V_25 ;
V_27 = F_198 ( V_379 -> V_27 ) ;
if ( V_27 == V_24 )
return;
V_12 = F_325 ( V_2 -> V_254 , V_195 ) ;
if ( ! V_12 )
return;
F_326 ( & V_2 -> V_251 , V_12 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_249 ) ;
}
void F_327 ( struct V_1 * V_2 , T_6 V_27 , T_5 V_404 ,
T_14 * V_545 ,
T_15 * V_546 )
{
struct V_11 * V_12 ;
unsigned long V_17 ;
F_20 ( L_63 , V_27 , V_404 ) ;
if ( ! F_281 ( V_2 , V_27 ) ) {
if ( F_8 ( V_241 , & V_2 -> V_17 ) && V_27 == V_24 )
F_324 ( V_2 ) ;
return;
}
if ( ! V_404 && ! F_323 ( V_2 ) )
return;
if ( F_264 ( V_2 -> V_254 ) -> V_42 . V_547 ) {
* V_545 = F_264 ( V_2 -> V_254 ) -> V_42 . V_547 ;
return;
}
if ( F_264 ( V_2 -> V_254 ) -> V_42 . V_548 ) {
* V_546 = F_264 ( V_2 -> V_254 ) -> V_42 . V_548 ;
return;
}
F_328 ( & V_2 -> V_251 . V_455 , V_17 ) ;
while ( ( V_12 = F_329 ( & V_2 -> V_251 ) ) ) {
if ( F_264 ( V_12 ) -> V_42 . V_495 ) {
F_330 ( & V_2 -> V_251 , V_12 ) ;
break;
}
* V_545 = F_264 ( V_12 ) -> V_42 . V_547 ;
* V_546 = F_264 ( V_12 ) -> V_42 . V_548 ;
F_17 ( V_12 ) ;
}
F_331 ( & V_2 -> V_251 . V_455 , V_17 ) ;
}
static void V_465 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 , V_250 ) ;
struct V_11 * V_12 ;
F_20 ( L_3 , V_2 -> V_28 ) ;
while ( ( V_12 = F_308 ( & V_2 -> V_252 ) ) ) {
F_275 ( V_2 , V_12 ) ;
if ( F_276 ( & V_2 -> V_494 ) ) {
F_277 ( V_2 , V_12 ) ;
}
if ( F_4 ( V_2 , V_226 ) ) {
F_17 ( V_12 ) ;
continue;
}
if ( F_8 ( V_241 , & V_2 -> V_17 ) ) {
switch ( F_264 ( V_12 ) -> V_307 ) {
case V_507 :
case V_515 :
F_17 ( V_12 ) ;
continue;
}
}
switch ( F_264 ( V_12 ) -> V_307 ) {
case V_486 :
F_20 ( L_64 , V_2 -> V_28 ) ;
F_332 ( V_2 , V_12 ) ;
break;
case V_507 :
F_20 ( L_65 , V_2 -> V_28 ) ;
F_315 ( V_2 , V_12 ) ;
break;
case V_515 :
F_20 ( L_66 , V_2 -> V_28 ) ;
F_321 ( V_2 , V_12 ) ;
break;
default:
F_17 ( V_12 ) ;
break;
}
}
}
static void V_466 ( struct V_327 * V_328 )
{
struct V_1 * V_2 = F_163 ( V_328 , struct V_1 , V_249 ) ;
struct V_11 * V_12 ;
F_20 ( L_67 , V_2 -> V_28 ,
F_276 ( & V_2 -> V_240 ) , F_333 ( & V_2 -> V_251 ) ) ;
if ( F_276 ( & V_2 -> V_240 ) ) {
V_12 = F_308 ( & V_2 -> V_251 ) ;
if ( ! V_12 )
return;
F_17 ( V_2 -> V_254 ) ;
V_2 -> V_254 = F_325 ( V_12 , V_195 ) ;
if ( V_2 -> V_254 ) {
F_334 ( & V_2 -> V_240 ) ;
F_274 ( V_2 , V_12 ) ;
if ( F_8 ( V_50 , & V_2 -> V_17 ) )
F_135 ( & V_2 -> V_267 ) ;
else
F_335 ( & V_2 -> V_267 ,
V_23 ) ;
} else {
F_326 ( & V_2 -> V_251 , V_12 ) ;
F_199 ( V_2 -> V_277 , & V_2 -> V_249 ) ;
}
}
}
