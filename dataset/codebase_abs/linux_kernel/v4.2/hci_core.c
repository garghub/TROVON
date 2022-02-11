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
if ( ! F_8 ( V_15 , & V_2 -> V_16 ) )
return - V_17 ;
if ( F_9 ( V_9 , V_5 , V_13 ) )
return - V_18 ;
V_9 [ V_13 ] = '\0' ;
if ( F_10 ( V_9 , & V_14 ) )
return - V_19 ;
if ( V_14 == F_4 ( V_2 , V_10 ) )
return - V_20 ;
F_11 ( V_2 ) ;
if ( V_14 )
V_12 = F_12 ( V_2 , V_21 , 0 , NULL ,
V_22 ) ;
else
V_12 = F_12 ( V_2 , V_23 , 0 , NULL ,
V_22 ) ;
F_13 ( V_2 ) ;
if ( F_14 ( V_12 ) )
return F_15 ( V_12 ) ;
F_16 ( V_12 ) ;
F_17 ( V_2 , V_10 ) ;
return V_6 ;
}
static void F_18 ( struct V_1 * V_2 , T_5 V_24 , T_6 V_25 ,
struct V_11 * V_12 )
{
F_19 ( L_1 , V_2 -> V_26 , V_24 ) ;
if ( V_2 -> V_27 == V_28 ) {
V_2 -> V_29 = V_24 ;
V_2 -> V_27 = V_30 ;
if ( V_12 )
V_2 -> V_31 = F_20 ( V_12 ) ;
F_21 ( & V_2 -> V_32 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_33 )
{
F_19 ( L_2 , V_2 -> V_26 , V_33 ) ;
if ( V_2 -> V_27 == V_28 ) {
V_2 -> V_29 = V_33 ;
V_2 -> V_27 = V_34 ;
F_21 ( & V_2 -> V_32 ) ;
}
}
struct V_11 * F_23 ( struct V_1 * V_2 , T_6 V_25 , T_7 V_35 ,
const void * V_36 , T_5 V_3 , T_7 V_37 )
{
F_24 ( V_38 , V_39 ) ;
struct V_40 V_41 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_25 ( & V_41 , V_2 ) ;
F_26 ( & V_41 , V_25 , V_35 , V_36 , V_3 ) ;
V_2 -> V_27 = V_28 ;
F_27 ( & V_2 -> V_32 , & V_38 ) ;
F_28 ( V_42 ) ;
V_33 = F_29 ( & V_41 , F_18 ) ;
if ( V_33 < 0 ) {
F_30 ( & V_2 -> V_32 , & V_38 ) ;
F_28 ( V_43 ) ;
return F_31 ( V_33 ) ;
}
F_32 ( V_37 ) ;
F_30 ( & V_2 -> V_32 , & V_38 ) ;
if ( F_33 ( V_39 ) )
return F_31 ( - V_44 ) ;
switch ( V_2 -> V_27 ) {
case V_30 :
V_33 = - F_34 ( V_2 -> V_29 ) ;
break;
case V_34 :
V_33 = - V_2 -> V_29 ;
break;
default:
V_33 = - V_45 ;
break;
}
V_2 -> V_27 = V_2 -> V_29 = 0 ;
V_12 = V_2 -> V_31 ;
V_2 -> V_31 = NULL ;
F_19 ( L_4 , V_2 -> V_26 , V_33 ) ;
if ( V_33 < 0 ) {
F_16 ( V_12 ) ;
return F_31 ( V_33 ) ;
}
if ( ! V_12 )
return F_31 ( - V_46 ) ;
return V_12 ;
}
struct V_11 * F_12 ( struct V_1 * V_2 , T_6 V_25 , T_7 V_35 ,
const void * V_36 , T_7 V_37 )
{
return F_23 ( V_2 , V_25 , V_35 , V_36 , 0 , V_37 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
void (* F_36)( struct V_40 * V_41 ,
unsigned long V_47 ) ,
unsigned long V_47 , T_8 V_37 )
{
struct V_40 V_41 ;
F_24 ( V_38 , V_39 ) ;
int V_33 = 0 ;
F_19 ( L_5 , V_2 -> V_26 ) ;
F_25 ( & V_41 , V_2 ) ;
V_2 -> V_27 = V_28 ;
F_36 ( & V_41 , V_47 ) ;
F_27 ( & V_2 -> V_32 , & V_38 ) ;
F_28 ( V_42 ) ;
V_33 = F_29 ( & V_41 , F_18 ) ;
if ( V_33 < 0 ) {
V_2 -> V_27 = 0 ;
F_30 ( & V_2 -> V_32 , & V_38 ) ;
F_28 ( V_43 ) ;
if ( V_33 == - V_46 )
return 0 ;
return V_33 ;
}
F_32 ( V_37 ) ;
F_30 ( & V_2 -> V_32 , & V_38 ) ;
if ( F_33 ( V_39 ) )
return - V_44 ;
switch ( V_2 -> V_27 ) {
case V_30 :
V_33 = - F_34 ( V_2 -> V_29 ) ;
break;
case V_34 :
V_33 = - V_2 -> V_29 ;
break;
default:
V_33 = - V_45 ;
break;
}
V_2 -> V_27 = V_2 -> V_29 = 0 ;
F_19 ( L_4 , V_2 -> V_26 , V_33 ) ;
return V_33 ;
}
static int F_37 ( struct V_1 * V_2 ,
void (* V_41)( struct V_40 * V_41 ,
unsigned long V_47 ) ,
unsigned long V_47 , T_8 V_37 )
{
int V_48 ;
if ( ! F_8 ( V_15 , & V_2 -> V_16 ) )
return - V_17 ;
F_11 ( V_2 ) ;
V_48 = F_35 ( V_2 , V_41 , V_47 , V_37 ) ;
F_13 ( V_2 ) ;
return V_48 ;
}
static void F_38 ( struct V_40 * V_41 , unsigned long V_47 )
{
F_19 ( L_6 , V_41 -> V_2 -> V_26 , V_47 ) ;
F_39 ( V_49 , & V_41 -> V_2 -> V_16 ) ;
F_40 ( V_41 , V_23 , 0 , NULL ) ;
}
static void F_41 ( struct V_40 * V_41 )
{
V_41 -> V_2 -> V_50 = V_51 ;
F_40 ( V_41 , V_52 , 0 , NULL ) ;
F_40 ( V_41 , V_53 , 0 , NULL ) ;
F_40 ( V_41 , V_54 , 0 , NULL ) ;
}
static void F_42 ( struct V_40 * V_41 )
{
V_41 -> V_2 -> V_50 = V_55 ;
F_40 ( V_41 , V_53 , 0 , NULL ) ;
F_40 ( V_41 , V_56 , 0 , NULL ) ;
F_40 ( V_41 , V_57 , 0 , NULL ) ;
F_40 ( V_41 , V_58 , 0 , NULL ) ;
F_40 ( V_41 , V_59 , 0 , NULL ) ;
F_40 ( V_41 , V_60 , 0 , NULL ) ;
}
static void F_43 ( struct V_40 * V_41 )
{
if ( V_41 -> V_2 -> V_61 [ 14 ] & 0x20 )
F_40 ( V_41 , V_52 , 0 , NULL ) ;
}
static void F_44 ( struct V_40 * V_41 , unsigned long V_47 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
F_19 ( L_6 , V_2 -> V_26 , V_47 ) ;
if ( ! F_8 ( V_62 , & V_2 -> V_63 ) )
F_38 ( V_41 , 0 ) ;
switch ( V_2 -> V_64 ) {
case V_65 :
F_41 ( V_41 ) ;
break;
case V_66 :
F_42 ( V_41 ) ;
break;
default:
F_45 ( L_7 , V_2 -> V_64 ) ;
break;
}
}
static void F_46 ( struct V_40 * V_41 )
{
T_9 V_36 ;
T_10 V_67 ;
F_40 ( V_41 , V_68 , 0 , NULL ) ;
F_40 ( V_41 , V_69 , 0 , NULL ) ;
F_40 ( V_41 , V_70 , 0 , NULL ) ;
F_40 ( V_41 , V_71 , 0 , NULL ) ;
F_40 ( V_41 , V_72 , 0 , NULL ) ;
F_40 ( V_41 , V_73 , 0 , NULL ) ;
V_67 = V_74 ;
F_40 ( V_41 , V_75 , 1 , & V_67 ) ;
V_36 = F_47 ( 0x7d00 ) ;
F_40 ( V_41 , V_76 , 2 , & V_36 ) ;
}
static void F_48 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
F_40 ( V_41 , V_77 , 0 , NULL ) ;
F_40 ( V_41 , V_78 , 0 , NULL ) ;
F_40 ( V_41 , V_79 , 0 , NULL ) ;
F_40 ( V_41 , V_80 , 0 , NULL ) ;
F_40 ( V_41 , V_81 , 0 , NULL ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( V_2 , V_82 ) ;
}
static void F_51 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
T_5 V_83 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_84 < V_85 )
return;
if ( F_49 ( V_2 ) ) {
V_83 [ 4 ] |= 0x01 ;
V_83 [ 4 ] |= 0x02 ;
V_83 [ 4 ] |= 0x04 ;
V_83 [ 5 ] |= 0x08 ;
V_83 [ 5 ] |= 0x10 ;
} else {
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
V_83 [ 0 ] |= 0x10 ;
V_83 [ 1 ] |= 0x08 ;
V_83 [ 1 ] |= 0x20 ;
V_83 [ 1 ] |= 0x40 ;
V_83 [ 1 ] |= 0x80 ;
V_83 [ 2 ] |= 0x04 ;
V_83 [ 3 ] |= 0x02 ;
if ( V_2 -> V_86 [ 0 ] & V_87 ) {
V_83 [ 0 ] |= 0x80 ;
V_83 [ 5 ] |= 0x80 ;
}
}
if ( F_52 ( V_2 ) )
V_83 [ 4 ] |= 0x02 ;
if ( F_53 ( V_2 ) )
V_83 [ 5 ] |= 0x20 ;
if ( F_54 ( V_2 ) )
V_83 [ 5 ] |= 0x80 ;
if ( F_55 ( V_2 ) )
V_83 [ 5 ] |= 0x40 ;
if ( F_56 ( V_2 ) )
V_83 [ 7 ] |= 0x01 ;
if ( F_57 ( V_2 ) )
V_83 [ 6 ] |= 0x80 ;
if ( F_58 ( V_2 ) ) {
V_83 [ 6 ] |= 0x01 ;
V_83 [ 6 ] |= 0x02 ;
V_83 [ 6 ] |= 0x04 ;
V_83 [ 6 ] |= 0x08 ;
V_83 [ 6 ] |= 0x10 ;
V_83 [ 6 ] |= 0x20 ;
V_83 [ 7 ] |= 0x04 ;
V_83 [ 7 ] |= 0x08 ;
V_83 [ 7 ] |= 0x10 ;
}
if ( F_59 ( V_2 ) )
V_83 [ 7 ] |= 0x20 ;
F_40 ( V_41 , V_88 , sizeof( V_83 ) , V_83 ) ;
}
static void F_60 ( struct V_40 * V_41 , unsigned long V_47 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
if ( V_2 -> V_64 == V_66 )
return F_43 ( V_41 ) ;
if ( F_49 ( V_2 ) )
F_46 ( V_41 ) ;
else
F_61 ( V_2 , V_89 ) ;
if ( F_59 ( V_2 ) )
F_48 ( V_41 ) ;
if ( V_2 -> V_84 > V_90 &&
! F_8 ( V_91 , & V_2 -> V_63 ) )
F_40 ( V_41 , V_56 , 0 , NULL ) ;
if ( F_58 ( V_2 ) ) {
V_2 -> V_92 = 0x01 ;
if ( F_4 ( V_2 , V_93 ) ) {
T_5 V_94 = 0x01 ;
F_40 ( V_41 , V_95 ,
sizeof( V_94 ) , & V_94 ) ;
} else {
struct V_96 V_97 ;
memset ( V_2 -> V_98 , 0 , sizeof( V_2 -> V_98 ) ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
F_40 ( V_41 , V_99 , sizeof( V_97 ) , & V_97 ) ;
}
}
if ( F_52 ( V_2 ) ||
F_8 ( V_100 , & V_2 -> V_63 ) ) {
T_5 V_94 ;
V_94 = F_55 ( V_2 ) ? 0x02 : 0x01 ;
F_40 ( V_41 , V_101 , 1 , & V_94 ) ;
}
if ( F_62 ( V_2 ) )
F_40 ( V_41 , V_102 , 0 , NULL ) ;
if ( F_63 ( V_2 ) ) {
struct V_103 V_97 ;
V_97 . V_104 = 0x01 ;
F_40 ( V_41 , V_105 ,
sizeof( V_97 ) , & V_97 ) ;
}
if ( F_4 ( V_2 , V_106 ) ) {
T_5 V_14 = 1 ;
F_40 ( V_41 , V_107 , sizeof( V_14 ) ,
& V_14 ) ;
}
}
static void F_64 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_108 V_97 ;
T_6 V_109 = 0 ;
if ( F_65 ( V_2 ) )
V_109 |= V_110 ;
if ( F_66 ( V_2 ) )
V_109 |= V_111 ;
if ( F_67 ( V_2 ) )
V_109 |= V_112 ;
if ( F_68 ( V_2 ) )
V_109 |= V_113 ;
V_97 . V_114 = F_47 ( V_109 ) ;
F_40 ( V_41 , V_115 , sizeof( V_97 ) , & V_97 ) ;
}
static void F_69 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_116 V_97 ;
if ( ! F_49 ( V_2 ) )
return;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
if ( F_4 ( V_2 , V_82 ) ) {
V_97 . V_117 = 0x01 ;
V_97 . V_118 = 0x00 ;
}
if ( V_97 . V_117 != F_70 ( V_2 ) )
F_40 ( V_41 , V_119 , sizeof( V_97 ) ,
& V_97 ) ;
}
static void F_71 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
T_5 V_83 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_72 ( V_2 ) ) {
V_83 [ 1 ] |= 0x40 ;
V_83 [ 1 ] |= 0x80 ;
V_83 [ 2 ] |= 0x10 ;
V_83 [ 2 ] |= 0x20 ;
}
if ( F_73 ( V_2 ) ) {
V_83 [ 2 ] |= 0x01 ;
V_83 [ 2 ] |= 0x02 ;
V_83 [ 2 ] |= 0x04 ;
V_83 [ 2 ] |= 0x08 ;
}
if ( F_74 ( V_2 ) || V_2 -> V_86 [ 0 ] & V_120 )
V_83 [ 2 ] |= 0x80 ;
F_40 ( V_41 , V_121 , sizeof( V_83 ) , V_83 ) ;
}
static void F_75 ( struct V_40 * V_41 , unsigned long V_47 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
T_5 V_122 ;
F_51 ( V_41 ) ;
if ( V_2 -> V_61 [ 6 ] & 0x20 ) {
struct V_123 V_97 ;
F_76 ( & V_97 . V_124 , V_125 ) ;
V_97 . V_126 = 0x01 ;
F_40 ( V_41 , V_127 , sizeof( V_97 ) , & V_97 ) ;
}
if ( V_2 -> V_61 [ 5 ] & 0x10 )
F_64 ( V_41 ) ;
if ( V_2 -> V_61 [ 8 ] & 0x01 )
F_40 ( V_41 , V_128 , 0 , NULL ) ;
if ( V_2 -> V_61 [ 13 ] & 0x01 )
F_40 ( V_41 , V_129 , 0 , NULL ) ;
if ( F_59 ( V_2 ) ) {
T_5 V_83 [ 8 ] ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
V_83 [ 0 ] = 0x0f ;
if ( V_2 -> V_86 [ 0 ] & V_87 )
V_83 [ 0 ] |= 0x10 ;
if ( V_2 -> V_86 [ 0 ] & V_130 )
V_83 [ 0 ] |= 0x20 ;
if ( V_2 -> V_86 [ 0 ] & V_131 )
V_83 [ 0 ] |= 0x40 ;
if ( V_2 -> V_86 [ 0 ] & V_132 )
V_83 [ 1 ] |= 0x04 ;
if ( V_2 -> V_61 [ 34 ] & 0x02 )
V_83 [ 0 ] |= 0x80 ;
if ( V_2 -> V_61 [ 34 ] & 0x04 )
V_83 [ 1 ] |= 0x01 ;
F_40 ( V_41 , V_133 , sizeof( V_83 ) ,
V_83 ) ;
if ( V_2 -> V_61 [ 25 ] & 0x40 ) {
F_40 ( V_41 , V_134 , 0 , NULL ) ;
}
if ( V_2 -> V_86 [ 0 ] & V_131 ) {
F_40 ( V_41 , V_135 , 0 , NULL ) ;
F_40 ( V_41 , V_136 , 0 , NULL ) ;
}
F_69 ( V_41 ) ;
}
for ( V_122 = 2 ; V_122 < V_137 && V_122 <= V_2 -> V_92 ; V_122 ++ ) {
struct V_103 V_97 ;
V_97 . V_104 = V_122 ;
F_40 ( V_41 , V_105 ,
sizeof( V_97 ) , & V_97 ) ;
}
}
static void F_77 ( struct V_40 * V_41 , unsigned long V_47 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
if ( V_2 -> V_61 [ 6 ] & 0x80 &&
! F_8 ( V_138 , & V_2 -> V_63 ) ) {
struct V_139 V_97 ;
F_76 ( & V_97 . V_124 , V_125 ) ;
V_97 . V_140 = 0x01 ;
F_40 ( V_41 , V_141 ,
sizeof( V_97 ) , & V_97 ) ;
}
if ( V_2 -> V_61 [ 22 ] & 0x04 )
F_71 ( V_41 ) ;
if ( V_2 -> V_61 [ 29 ] & 0x20 )
F_40 ( V_41 , V_142 , 0 , NULL ) ;
if ( V_2 -> V_61 [ 30 ] & 0x08 )
F_40 ( V_41 , V_143 , 0 , NULL ) ;
if ( F_78 ( V_2 ) )
F_40 ( V_41 , V_144 , 0 , NULL ) ;
if ( F_4 ( V_2 , V_93 ) &&
F_79 ( V_2 ) ) {
T_5 V_145 = 0x01 ;
F_40 ( V_41 , V_146 ,
sizeof( V_145 ) , & V_145 ) ;
}
}
static int F_80 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_35 ( V_2 , F_44 , 0 , V_147 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( F_4 ( V_2 , V_148 ) ) {
F_81 ( L_8 , 0644 , V_2 -> V_149 , V_2 ,
& V_150 ) ;
}
V_33 = F_35 ( V_2 , F_60 , 0 , V_147 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_2 -> V_64 != V_65 )
return 0 ;
V_33 = F_35 ( V_2 , F_75 , 0 , V_147 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_35 ( V_2 , F_77 , 0 , V_147 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( ! F_4 ( V_2 , V_148 ) &&
! F_4 ( V_2 , V_151 ) )
return 0 ;
F_82 ( V_2 ) ;
if ( F_49 ( V_2 ) )
F_83 ( V_2 ) ;
if ( F_59 ( V_2 ) )
F_84 ( V_2 ) ;
return 0 ;
}
static void F_85 ( struct V_40 * V_41 , unsigned long V_47 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
F_19 ( L_6 , V_2 -> V_26 , V_47 ) ;
if ( ! F_8 ( V_62 , & V_2 -> V_63 ) )
F_38 ( V_41 , 0 ) ;
F_40 ( V_41 , V_53 , 0 , NULL ) ;
if ( V_2 -> V_152 )
F_40 ( V_41 , V_54 , 0 , NULL ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_33 ;
if ( F_8 ( V_153 , & V_2 -> V_63 ) )
return 0 ;
V_33 = F_35 ( V_2 , F_85 , 0 , V_147 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
static void F_87 ( struct V_40 * V_41 , unsigned long V_47 )
{
T_10 V_154 = V_47 ;
F_19 ( L_9 , V_41 -> V_2 -> V_26 , V_154 ) ;
F_40 ( V_41 , V_155 , 1 , & V_154 ) ;
}
static void F_88 ( struct V_40 * V_41 , unsigned long V_47 )
{
T_10 V_156 = V_47 ;
F_19 ( L_9 , V_41 -> V_2 -> V_26 , V_156 ) ;
F_40 ( V_41 , V_107 , 1 , & V_156 ) ;
}
static void F_89 ( struct V_40 * V_41 , unsigned long V_47 )
{
T_10 V_157 = V_47 ;
F_19 ( L_9 , V_41 -> V_2 -> V_26 , V_157 ) ;
F_40 ( V_41 , V_158 , 1 , & V_157 ) ;
}
static void F_90 ( struct V_40 * V_41 , unsigned long V_47 )
{
T_9 V_114 = F_47 ( V_47 ) ;
F_19 ( L_9 , V_41 -> V_2 -> V_26 , V_114 ) ;
F_40 ( V_41 , V_115 , 2 , & V_114 ) ;
}
struct V_1 * F_91 ( int V_159 )
{
struct V_1 * V_2 = NULL , * V_160 ;
F_19 ( L_10 , V_159 ) ;
if ( V_159 < 0 )
return NULL ;
F_92 ( & V_161 ) ;
F_93 (d, &hci_dev_list, list) {
if ( V_160 -> V_162 == V_159 ) {
V_2 = F_94 ( V_160 ) ;
break;
}
}
F_95 ( & V_161 ) ;
return V_2 ;
}
bool F_96 ( struct V_1 * V_2 )
{
struct V_163 * V_164 = & V_2 -> V_165 ;
switch ( V_164 -> V_166 ) {
case V_167 :
case V_168 :
return true ;
default:
return false ;
}
}
void F_97 ( struct V_1 * V_2 , int V_166 )
{
int V_169 = V_2 -> V_165 . V_166 ;
F_19 ( L_11 , V_2 -> V_26 , V_2 -> V_165 . V_166 , V_166 ) ;
if ( V_169 == V_166 )
return;
V_2 -> V_165 . V_166 = V_166 ;
switch ( V_166 ) {
case V_170 :
F_98 ( V_2 ) ;
if ( V_169 != V_171 )
F_99 ( V_2 , 0 ) ;
break;
case V_171 :
break;
case V_167 :
F_99 ( V_2 , 1 ) ;
break;
case V_168 :
break;
case V_172 :
break;
}
}
void F_100 ( struct V_1 * V_2 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_174 * V_122 , * V_175 ;
F_101 (p, n, &cache->all, all) {
F_102 ( & V_122 -> V_176 ) ;
F_103 ( V_122 ) ;
}
F_104 ( & V_173 -> V_177 ) ;
F_104 ( & V_173 -> V_178 ) ;
}
struct V_174 * F_105 ( struct V_1 * V_2 ,
T_11 * V_124 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_174 * V_179 ;
F_19 ( L_12 , V_173 , V_124 ) ;
F_93 (e, &cache->all, all) {
if ( ! F_106 ( & V_179 -> V_180 . V_124 , V_124 ) )
return V_179 ;
}
return NULL ;
}
struct V_174 * F_107 ( struct V_1 * V_2 ,
T_11 * V_124 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_174 * V_179 ;
F_19 ( L_12 , V_173 , V_124 ) ;
F_93 (e, &cache->unknown, list) {
if ( ! F_106 ( & V_179 -> V_180 . V_124 , V_124 ) )
return V_179 ;
}
return NULL ;
}
struct V_174 * F_108 ( struct V_1 * V_2 ,
T_11 * V_124 ,
int V_166 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_174 * V_179 ;
F_19 ( L_13 , V_173 , V_124 , V_166 ) ;
F_93 (e, &cache->resolve, list) {
if ( ! F_106 ( V_124 , V_125 ) && V_179 -> V_181 == V_166 )
return V_179 ;
if ( ! F_106 ( & V_179 -> V_180 . V_124 , V_124 ) )
return V_179 ;
}
return NULL ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_174 * V_182 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_183 * V_184 = & V_173 -> V_178 ;
struct V_174 * V_122 ;
F_102 ( & V_182 -> V_185 ) ;
F_93 (p, &cache->resolve, list) {
if ( V_122 -> V_181 != V_186 &&
abs ( V_122 -> V_180 . V_187 ) >= abs ( V_182 -> V_180 . V_187 ) )
break;
V_184 = & V_122 -> V_185 ;
}
F_110 ( & V_182 -> V_185 , V_184 ) ;
}
T_7 F_111 ( struct V_1 * V_2 , struct V_188 * V_180 ,
bool V_189 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_174 * V_182 ;
T_7 V_16 = 0 ;
F_19 ( L_12 , V_173 , & V_180 -> V_124 ) ;
F_112 ( V_2 , & V_180 -> V_124 , V_190 ) ;
if ( ! V_180 -> V_191 )
V_16 |= V_192 ;
V_182 = F_105 ( V_2 , & V_180 -> V_124 ) ;
if ( V_182 ) {
if ( ! V_182 -> V_180 . V_191 )
V_16 |= V_192 ;
if ( V_182 -> V_181 == V_193 &&
V_180 -> V_187 != V_182 -> V_180 . V_187 ) {
V_182 -> V_180 . V_187 = V_180 -> V_187 ;
F_109 ( V_2 , V_182 ) ;
}
goto V_194;
}
V_182 = F_113 ( sizeof( * V_182 ) , V_195 ) ;
if ( ! V_182 ) {
V_16 |= V_196 ;
goto V_197;
}
F_110 ( & V_182 -> V_176 , & V_173 -> V_176 ) ;
if ( V_189 ) {
V_182 -> V_181 = V_198 ;
} else {
V_182 -> V_181 = V_199 ;
F_110 ( & V_182 -> V_185 , & V_173 -> V_177 ) ;
}
V_194:
if ( V_189 && V_182 -> V_181 != V_198 &&
V_182 -> V_181 != V_186 ) {
V_182 -> V_181 = V_198 ;
F_102 ( & V_182 -> V_185 ) ;
}
memcpy ( & V_182 -> V_180 , V_180 , sizeof( * V_180 ) ) ;
V_182 -> V_200 = V_201 ;
V_173 -> V_200 = V_201 ;
if ( V_182 -> V_181 == V_199 )
V_16 |= V_196 ;
V_197:
return V_16 ;
}
static int F_114 ( struct V_1 * V_2 , int V_202 , T_10 * V_9 )
{
struct V_163 * V_173 = & V_2 -> V_165 ;
struct V_203 * V_204 = (struct V_203 * ) V_9 ;
struct V_174 * V_179 ;
int V_205 = 0 ;
F_93 (e, &cache->all, all) {
struct V_188 * V_180 = & V_179 -> V_180 ;
if ( V_205 >= V_202 )
break;
F_76 ( & V_204 -> V_124 , & V_180 -> V_124 ) ;
V_204 -> V_206 = V_180 -> V_206 ;
V_204 -> V_207 = V_180 -> V_207 ;
V_204 -> V_208 = V_180 -> V_208 ;
memcpy ( V_204 -> V_209 , V_180 -> V_209 , 3 ) ;
V_204 -> V_210 = V_180 -> V_210 ;
V_204 ++ ;
V_205 ++ ;
}
F_19 ( L_14 , V_173 , V_205 ) ;
return V_205 ;
}
static void F_115 ( struct V_40 * V_41 , unsigned long V_47 )
{
struct V_211 * V_212 = (struct V_211 * ) V_47 ;
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_213 V_97 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( F_8 ( V_214 , & V_2 -> V_16 ) )
return;
memcpy ( & V_97 . V_215 , & V_212 -> V_215 , 3 ) ;
V_97 . V_216 = V_212 -> V_216 ;
V_97 . V_217 = V_212 -> V_217 ;
F_40 ( V_41 , V_218 , sizeof( V_97 ) , & V_97 ) ;
}
int F_116 ( void T_2 * V_219 )
{
T_10 T_2 * V_220 = V_219 ;
struct V_211 V_212 ;
struct V_1 * V_2 ;
int V_33 = 0 , V_221 = 0 , V_222 ;
long V_223 ;
T_10 * V_9 ;
if ( F_9 ( & V_212 , V_220 , sizeof( V_212 ) ) )
return - V_18 ;
V_2 = F_91 ( V_212 . V_224 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_33 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_33 = - V_229 ;
goto V_197;
}
if ( V_2 -> V_64 != V_65 ) {
V_33 = - V_229 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_89 ) ) {
V_33 = - V_229 ;
goto V_197;
}
F_117 ( V_2 ) ;
if ( F_118 ( V_2 ) > V_230 ||
F_119 ( V_2 ) || V_212 . V_16 & V_231 ) {
F_100 ( V_2 ) ;
V_221 = 1 ;
}
F_120 ( V_2 ) ;
V_223 = V_212 . V_216 * F_121 ( 2000 ) ;
if ( V_221 ) {
V_33 = F_37 ( V_2 , F_115 , ( unsigned long ) & V_212 ,
V_223 ) ;
if ( V_33 < 0 )
goto V_197;
if ( F_122 ( & V_2 -> V_16 , V_214 ,
V_42 ) )
return - V_44 ;
}
V_222 = ( V_212 . V_217 == 0 ) ? 255 : V_212 . V_217 ;
V_9 = F_123 ( sizeof( struct V_203 ) * V_222 , V_195 ) ;
if ( ! V_9 ) {
V_33 = - V_232 ;
goto V_197;
}
F_117 ( V_2 ) ;
V_212 . V_217 = F_114 ( V_2 , V_222 , V_9 ) ;
F_120 ( V_2 ) ;
F_19 ( L_15 , V_212 . V_217 ) ;
if ( ! F_124 ( V_220 , & V_212 , sizeof( V_212 ) ) ) {
V_220 += sizeof( V_212 ) ;
if ( F_124 ( V_220 , V_9 , sizeof( struct V_203 ) *
V_212 . V_217 ) )
V_33 = - V_18 ;
} else
V_33 = - V_18 ;
F_103 ( V_9 ) ;
V_197:
F_125 ( V_2 ) ;
return V_33 ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_48 = 0 ;
F_19 ( L_16 , V_2 -> V_26 , V_2 ) ;
F_11 ( V_2 ) ;
if ( F_4 ( V_2 , V_233 ) ) {
V_48 = - V_225 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_148 ) &&
! F_4 ( V_2 , V_151 ) ) {
if ( F_4 ( V_2 , V_234 ) ) {
V_48 = - V_235 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_226 ) &&
V_2 -> V_64 == V_65 &&
! F_106 ( & V_2 -> V_124 , V_125 ) &&
! F_106 ( & V_2 -> V_236 , V_125 ) ) {
V_48 = - V_237 ;
goto V_197;
}
}
if ( F_8 ( V_15 , & V_2 -> V_16 ) ) {
V_48 = - V_20 ;
goto V_197;
}
if ( V_2 -> V_238 ( V_2 ) ) {
V_48 = - V_239 ;
goto V_197;
}
F_127 ( & V_2 -> V_240 , 1 ) ;
F_39 ( V_241 , & V_2 -> V_16 ) ;
if ( F_4 ( V_2 , V_148 ) ) {
if ( V_2 -> V_242 )
V_48 = V_2 -> V_242 ( V_2 ) ;
if ( F_8 ( V_243 , & V_2 -> V_63 ) ||
F_8 ( V_244 , & V_2 -> V_63 ) )
F_50 ( V_2 , V_228 ) ;
if ( F_4 ( V_2 , V_228 ) )
V_48 = F_86 ( V_2 ) ;
}
if ( F_4 ( V_2 , V_151 ) ) {
if ( F_106 ( & V_2 -> V_245 , V_125 ) &&
V_2 -> V_152 )
V_48 = V_2 -> V_152 ( V_2 , & V_2 -> V_245 ) ;
else
V_48 = - V_237 ;
}
if ( ! V_48 ) {
if ( ! F_4 ( V_2 , V_228 ) &&
! F_4 ( V_2 , V_226 ) )
V_48 = F_80 ( V_2 ) ;
}
F_128 ( V_241 , & V_2 -> V_16 ) ;
if ( ! V_48 ) {
F_94 ( V_2 ) ;
F_50 ( V_2 , V_246 ) ;
F_39 ( V_15 , & V_2 -> V_16 ) ;
F_1 ( V_2 , V_247 ) ;
if ( ! F_4 ( V_2 , V_148 ) &&
! F_4 ( V_2 , V_151 ) &&
! F_4 ( V_2 , V_228 ) &&
! F_4 ( V_2 , V_226 ) &&
V_2 -> V_64 == V_65 ) {
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
F_16 ( V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
}
V_2 -> V_255 ( V_2 ) ;
V_2 -> V_16 &= F_132 ( V_256 ) ;
}
V_197:
F_13 ( V_2 ) ;
return V_48 ;
}
int F_133 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_228 ) &&
! F_4 ( V_2 , V_226 ) ) {
V_33 = - V_229 ;
goto V_197;
}
if ( F_134 ( V_2 , V_258 ) )
F_135 ( & V_2 -> V_259 ) ;
F_136 ( V_2 -> V_260 ) ;
if ( ! F_4 ( V_2 , V_226 ) &&
! F_4 ( V_2 , V_261 ) )
F_50 ( V_2 , V_262 ) ;
V_33 = F_126 ( V_2 ) ;
V_197:
F_125 ( V_2 ) ;
return V_33 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_263 * V_122 ;
F_93 (p, &hdev->le_conn_params, list) {
if ( V_122 -> V_264 ) {
F_138 ( V_122 -> V_264 ) ;
F_139 ( V_122 -> V_264 ) ;
V_122 -> V_264 = NULL ;
}
F_140 ( & V_122 -> V_265 ) ;
}
F_19 ( L_17 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
F_19 ( L_16 , V_2 -> V_26 , V_2 ) ;
if ( ! F_4 ( V_2 , V_233 ) &&
! F_4 ( V_2 , V_226 ) &&
F_8 ( V_15 , & V_2 -> V_16 ) ) {
if ( V_2 -> V_266 )
V_2 -> V_266 ( V_2 ) ;
}
F_135 ( & V_2 -> V_259 ) ;
F_22 ( V_2 , V_225 ) ;
F_11 ( V_2 ) ;
if ( ! F_142 ( V_15 , & V_2 -> V_16 ) ) {
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
if ( V_2 -> V_277 ) {
F_143 ( & V_2 -> V_278 ) ;
V_2 -> V_277 = 0 ;
}
F_144 ( V_2 -> V_279 ) ;
F_117 ( V_2 ) ;
F_97 ( V_2 , V_170 ) ;
if ( ! F_134 ( V_2 , V_258 ) ) {
if ( V_2 -> V_64 == V_65 )
F_129 ( V_2 , 0 ) ;
}
F_100 ( V_2 ) ;
F_137 ( V_2 ) ;
F_145 ( V_2 ) ;
F_120 ( V_2 ) ;
F_146 ( V_2 ) ;
F_1 ( V_2 , V_280 ) ;
if ( V_2 -> V_253 )
V_2 -> V_253 ( V_2 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_127 ( & V_2 -> V_240 , 1 ) ;
if ( ! F_4 ( V_2 , V_258 ) &&
! F_4 ( V_2 , V_228 ) &&
F_8 ( V_62 , & V_2 -> V_63 ) ) {
F_39 ( V_241 , & V_2 -> V_16 ) ;
F_35 ( V_2 , F_38 , 0 , V_22 ) ;
F_128 ( V_241 , & V_2 -> V_16 ) ;
}
F_130 ( & V_2 -> V_249 ) ;
F_131 ( & V_2 -> V_252 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_131 ( & V_2 -> V_281 ) ;
if ( V_2 -> V_254 ) {
F_143 ( & V_2 -> V_267 ) ;
F_16 ( V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
}
V_2 -> V_255 ( V_2 ) ;
V_2 -> V_16 &= F_132 ( V_256 ) ;
F_147 ( V_2 ) ;
V_2 -> V_282 = V_283 ;
memset ( V_2 -> V_98 , 0 , sizeof( V_2 -> V_98 ) ) ;
memset ( V_2 -> V_209 , 0 , sizeof( V_2 -> V_209 ) ) ;
F_76 ( & V_2 -> V_284 , V_125 ) ;
F_13 ( V_2 ) ;
F_125 ( V_2 ) ;
return 0 ;
}
int F_148 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_33 = - V_227 ;
goto V_197;
}
if ( F_134 ( V_2 , V_258 ) )
F_135 ( & V_2 -> V_259 ) ;
V_33 = F_141 ( V_2 ) ;
V_197:
F_125 ( V_2 ) ;
return V_33 ;
}
static int F_149 ( struct V_1 * V_2 )
{
int V_48 ;
F_19 ( L_16 , V_2 -> V_26 , V_2 ) ;
F_11 ( V_2 ) ;
F_131 ( & V_2 -> V_252 ) ;
F_131 ( & V_2 -> V_251 ) ;
F_144 ( V_2 -> V_279 ) ;
F_117 ( V_2 ) ;
F_100 ( V_2 ) ;
F_145 ( V_2 ) ;
F_120 ( V_2 ) ;
if ( V_2 -> V_253 )
V_2 -> V_253 ( V_2 ) ;
F_127 ( & V_2 -> V_240 , 1 ) ;
V_2 -> V_285 = 0 ; V_2 -> V_286 = 0 ; V_2 -> V_287 = 0 ;
V_48 = F_35 ( V_2 , F_38 , 0 , V_147 ) ;
F_13 ( V_2 ) ;
return V_48 ;
}
int F_150 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( ! F_8 ( V_15 , & V_2 -> V_16 ) ) {
V_33 = - V_17 ;
goto V_197;
}
if ( F_4 ( V_2 , V_226 ) ) {
V_33 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_33 = - V_229 ;
goto V_197;
}
V_33 = F_149 ( V_2 ) ;
V_197:
F_125 ( V_2 ) ;
return V_33 ;
}
int F_151 ( T_12 V_257 )
{
struct V_1 * V_2 ;
int V_48 = 0 ;
V_2 = F_91 ( V_257 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_48 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_48 = - V_229 ;
goto V_197;
}
memset ( & V_2 -> V_288 , 0 , sizeof( struct V_289 ) ) ;
V_197:
F_125 ( V_2 ) ;
return V_48 ;
}
static void F_152 ( struct V_1 * V_2 , T_5 V_154 )
{
bool V_290 , V_291 ;
F_19 ( L_18 , V_2 -> V_26 , V_154 ) ;
if ( ( V_154 & V_292 ) )
V_290 = ! F_153 ( V_2 ,
V_293 ) ;
else
V_290 = F_134 ( V_2 ,
V_293 ) ;
if ( ( V_154 & V_294 ) ) {
V_291 = ! F_153 ( V_2 ,
V_270 ) ;
} else {
F_61 ( V_2 , V_271 ) ;
V_291 = F_134 ( V_2 ,
V_270 ) ;
}
if ( ! F_4 ( V_2 , V_261 ) )
return;
if ( V_290 || V_291 ) {
F_50 ( V_2 , V_89 ) ;
if ( F_4 ( V_2 , V_82 ) )
F_154 ( V_2 ) ;
F_155 ( V_2 ) ;
}
}
int F_156 ( unsigned int V_295 , void T_2 * V_219 )
{
struct V_1 * V_2 ;
struct V_296 V_297 ;
int V_33 = 0 ;
if ( F_9 ( & V_297 , V_219 , sizeof( V_297 ) ) )
return - V_18 ;
V_2 = F_91 ( V_297 . V_224 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_226 ) ) {
V_33 = - V_227 ;
goto V_197;
}
if ( F_4 ( V_2 , V_228 ) ) {
V_33 = - V_229 ;
goto V_197;
}
if ( V_2 -> V_64 != V_65 ) {
V_33 = - V_229 ;
goto V_197;
}
if ( ! F_4 ( V_2 , V_89 ) ) {
V_33 = - V_229 ;
goto V_197;
}
switch ( V_295 ) {
case V_298 :
V_33 = F_37 ( V_2 , F_88 , V_297 . V_299 ,
V_147 ) ;
break;
case V_300 :
if ( ! F_157 ( V_2 ) ) {
V_33 = - V_229 ;
break;
}
if ( ! F_8 ( V_301 , & V_2 -> V_16 ) ) {
V_33 = F_37 ( V_2 , F_88 , V_297 . V_299 ,
V_147 ) ;
if ( V_33 )
break;
}
V_33 = F_37 ( V_2 , F_89 , V_297 . V_299 ,
V_147 ) ;
break;
case V_302 :
V_33 = F_37 ( V_2 , F_87 , V_297 . V_299 ,
V_147 ) ;
if ( ! V_33 )
F_152 ( V_2 , V_297 . V_299 ) ;
break;
case V_303 :
V_33 = F_37 ( V_2 , F_90 , V_297 . V_299 ,
V_147 ) ;
break;
case V_304 :
V_2 -> V_305 = ( ( T_12 ) V_297 . V_299 ) &
( V_306 | V_307 ) ;
break;
case V_308 :
V_2 -> V_309 = ( T_12 ) V_297 . V_299 ;
break;
case V_310 :
V_2 -> V_311 = * ( ( T_12 * ) & V_297 . V_299 + 1 ) ;
V_2 -> V_312 = * ( ( T_12 * ) & V_297 . V_299 + 0 ) ;
break;
case V_313 :
V_2 -> V_314 = * ( ( T_12 * ) & V_297 . V_299 + 1 ) ;
V_2 -> V_315 = * ( ( T_12 * ) & V_297 . V_299 + 0 ) ;
break;
default:
V_33 = - V_19 ;
break;
}
V_197:
F_125 ( V_2 ) ;
return V_33 ;
}
int F_158 ( void T_2 * V_219 )
{
struct V_1 * V_2 ;
struct V_316 * V_317 ;
struct V_296 * V_297 ;
int V_175 = 0 , V_318 , V_33 ;
T_12 V_319 ;
if ( F_159 ( V_319 , ( T_12 T_2 * ) V_219 ) )
return - V_18 ;
if ( ! V_319 || V_319 > ( V_320 * 2 ) / sizeof( * V_297 ) )
return - V_19 ;
V_318 = sizeof( * V_317 ) + V_319 * sizeof( * V_297 ) ;
V_317 = F_113 ( V_318 , V_195 ) ;
if ( ! V_317 )
return - V_232 ;
V_297 = V_317 -> V_321 ;
F_92 ( & V_161 ) ;
F_93 (hdev, &hci_dev_list, list) {
unsigned long V_16 = V_2 -> V_16 ;
if ( F_4 ( V_2 , V_258 ) )
V_16 &= ~ F_132 ( V_15 ) ;
( V_297 + V_175 ) -> V_224 = V_2 -> V_162 ;
( V_297 + V_175 ) -> V_299 = V_16 ;
if ( ++ V_175 >= V_319 )
break;
}
F_95 ( & V_161 ) ;
V_317 -> V_319 = V_175 ;
V_318 = sizeof( * V_317 ) + V_175 * sizeof( * V_297 ) ;
V_33 = F_124 ( V_219 , V_317 , V_318 ) ;
F_103 ( V_317 ) ;
return V_33 ? - V_18 : 0 ;
}
int F_160 ( void T_2 * V_219 )
{
struct V_1 * V_2 ;
struct V_322 V_323 ;
unsigned long V_16 ;
int V_33 = 0 ;
if ( F_9 ( & V_323 , V_219 , sizeof( V_323 ) ) )
return - V_18 ;
V_2 = F_91 ( V_323 . V_224 ) ;
if ( ! V_2 )
return - V_225 ;
if ( F_4 ( V_2 , V_258 ) )
V_16 = V_2 -> V_16 & ~ F_132 ( V_15 ) ;
else
V_16 = V_2 -> V_16 ;
strcpy ( V_323 . V_26 , V_2 -> V_26 ) ;
V_323 . V_124 = V_2 -> V_124 ;
V_323 . type = ( V_2 -> V_324 & 0x0f ) | ( ( V_2 -> V_64 & 0x03 ) << 4 ) ;
V_323 . V_16 = V_16 ;
V_323 . V_309 = V_2 -> V_309 ;
if ( F_49 ( V_2 ) ) {
V_323 . V_311 = V_2 -> V_311 ;
V_323 . V_312 = V_2 -> V_312 ;
V_323 . V_314 = V_2 -> V_314 ;
V_323 . V_315 = V_2 -> V_315 ;
} else {
V_323 . V_311 = V_2 -> V_325 ;
V_323 . V_312 = V_2 -> V_326 ;
V_323 . V_314 = 0 ;
V_323 . V_315 = 0 ;
}
V_323 . V_109 = V_2 -> V_109 ;
V_323 . V_305 = V_2 -> V_305 ;
memcpy ( & V_323 . V_288 , & V_2 -> V_288 , sizeof( V_323 . V_288 ) ) ;
memcpy ( & V_323 . V_327 , & V_2 -> V_327 , sizeof( V_323 . V_327 ) ) ;
if ( F_124 ( V_219 , & V_323 , sizeof( V_323 ) ) )
V_33 = - V_18 ;
F_125 ( V_2 ) ;
return V_33 ;
}
static int F_161 ( void * V_180 , bool V_328 )
{
struct V_1 * V_2 = V_180 ;
F_19 ( L_19 , V_2 , V_2 -> V_26 , V_328 ) ;
if ( F_4 ( V_2 , V_226 ) )
return - V_227 ;
if ( V_328 ) {
F_50 ( V_2 , V_234 ) ;
if ( ! F_4 ( V_2 , V_148 ) &&
! F_4 ( V_2 , V_151 ) )
F_141 ( V_2 ) ;
} else {
F_61 ( V_2 , V_234 ) ;
}
return 0 ;
}
static void F_162 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 , V_331 ) ;
int V_33 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
V_33 = F_126 ( V_2 ) ;
if ( V_33 < 0 ) {
F_117 ( V_2 ) ;
F_164 ( V_2 , V_33 ) ;
F_120 ( V_2 ) ;
return;
}
if ( F_4 ( V_2 , V_234 ) ||
F_4 ( V_2 , V_228 ) ||
( V_2 -> V_64 == V_65 &&
! F_106 ( & V_2 -> V_124 , V_125 ) &&
! F_106 ( & V_2 -> V_236 , V_125 ) ) ) {
F_61 ( V_2 , V_258 ) ;
F_141 ( V_2 ) ;
} else if ( F_4 ( V_2 , V_258 ) ) {
F_165 ( V_2 -> V_260 , & V_2 -> V_259 ,
V_332 ) ;
}
if ( F_134 ( V_2 , V_148 ) ) {
if ( F_4 ( V_2 , V_228 ) )
F_39 ( V_256 , & V_2 -> V_16 ) ;
F_166 ( V_2 ) ;
} else if ( F_134 ( V_2 , V_151 ) ) {
if ( ! F_4 ( V_2 , V_228 ) )
F_128 ( V_256 , & V_2 -> V_16 ) ;
F_166 ( V_2 ) ;
}
}
static void F_167 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 ,
V_259 . V_330 ) ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_141 ( V_2 ) ;
}
static void F_168 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 , V_333 ) ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( V_2 -> V_334 )
V_2 -> V_334 ( V_2 , V_2 -> V_335 ) ;
else
F_45 ( L_20 , V_2 -> V_26 ,
V_2 -> V_335 ) ;
if ( F_141 ( V_2 ) )
return;
F_126 ( V_2 ) ;
}
static void F_169 ( struct V_329 * V_330 )
{
struct V_1 * V_2 ;
V_2 = F_163 ( V_330 , struct V_1 , V_269 . V_330 ) ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_170 ( V_2 ) ;
}
static void F_171 ( struct V_329 * V_330 )
{
struct V_1 * V_2 ;
V_2 = F_163 ( V_330 , struct V_1 , V_278 . V_330 ) ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_172 ( V_2 ) ;
}
void F_173 ( struct V_1 * V_2 )
{
struct V_336 * V_337 , * V_338 ;
F_101 (uuid, tmp, &hdev->uuids, list) {
F_102 ( & V_337 -> V_185 ) ;
F_103 ( V_337 ) ;
}
}
void F_174 ( struct V_1 * V_2 )
{
struct V_339 * V_340 ;
F_175 (key, &hdev->link_keys, list) {
F_176 ( & V_340 -> V_185 ) ;
F_177 ( V_340 , V_341 ) ;
}
}
void F_178 ( struct V_1 * V_2 )
{
struct V_342 * V_343 ;
F_175 (k, &hdev->long_term_keys, list) {
F_176 ( & V_343 -> V_185 ) ;
F_177 ( V_343 , V_341 ) ;
}
}
void F_179 ( struct V_1 * V_2 )
{
struct V_344 * V_343 ;
F_175 (k, &hdev->identity_resolving_keys, list) {
F_176 ( & V_343 -> V_185 ) ;
F_177 ( V_343 , V_341 ) ;
}
}
struct V_339 * F_180 ( struct V_1 * V_2 , T_11 * V_124 )
{
struct V_339 * V_343 ;
F_181 () ;
F_175 (k, &hdev->link_keys, list) {
if ( F_106 ( V_124 , & V_343 -> V_124 ) == 0 ) {
F_182 () ;
return V_343 ;
}
}
F_182 () ;
return NULL ;
}
static bool F_183 ( struct V_1 * V_2 , struct V_345 * V_264 ,
T_5 V_346 , T_5 V_347 )
{
if ( V_346 < 0x03 )
return true ;
if ( V_346 == V_348 )
return false ;
if ( V_346 == V_349 && V_347 == 0xff )
return false ;
if ( ! V_264 )
return true ;
if ( V_264 -> type == V_350 )
return true ;
if ( V_264 -> V_351 > 0x01 && V_264 -> V_352 > 0x01 )
return true ;
if ( V_264 -> V_351 == 0x02 || V_264 -> V_351 == 0x03 )
return true ;
if ( V_264 -> V_352 == 0x02 || V_264 -> V_352 == 0x03 )
return true ;
return false ;
}
static T_5 F_184 ( T_5 type )
{
if ( type == V_353 )
return V_354 ;
return V_355 ;
}
struct V_342 * F_185 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 V_356 , T_5 V_357 )
{
struct V_342 * V_343 ;
F_181 () ;
F_175 (k, &hdev->long_term_keys, list) {
if ( V_356 != V_343 -> V_358 || F_106 ( V_124 , & V_343 -> V_124 ) )
continue;
if ( F_186 ( V_343 ) || F_184 ( V_343 -> type ) == V_357 ) {
F_182 () ;
return V_343 ;
}
}
F_182 () ;
return NULL ;
}
struct V_344 * F_187 ( struct V_1 * V_2 , T_11 * V_359 )
{
struct V_344 * V_360 ;
F_181 () ;
F_175 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_106 ( & V_360 -> V_359 , V_359 ) ) {
F_182 () ;
return V_360 ;
}
}
F_175 (irk, &hdev->identity_resolving_keys, list) {
if ( F_188 ( V_2 , V_360 -> V_361 , V_359 ) ) {
F_76 ( & V_360 -> V_359 , V_359 ) ;
F_182 () ;
return V_360 ;
}
}
F_182 () ;
return NULL ;
}
struct V_344 * F_189 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 V_356 )
{
struct V_344 * V_360 ;
if ( V_356 == V_362 && ( V_124 -> V_363 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_181 () ;
F_175 (irk, &hdev->identity_resolving_keys, list) {
if ( V_356 == V_360 -> V_356 &&
F_106 ( V_124 , & V_360 -> V_124 ) == 0 ) {
F_182 () ;
return V_360 ;
}
}
F_182 () ;
return NULL ;
}
struct V_339 * F_190 ( struct V_1 * V_2 , struct V_345 * V_264 ,
T_11 * V_124 , T_5 * V_361 , T_5 type ,
T_5 V_364 , bool * V_365 )
{
struct V_339 * V_340 , * V_366 ;
T_5 V_347 ;
V_366 = F_180 ( V_2 , V_124 ) ;
if ( V_366 ) {
V_347 = V_366 -> type ;
V_340 = V_366 ;
} else {
V_347 = V_264 ? V_264 -> V_346 : 0xff ;
V_340 = F_113 ( sizeof( * V_340 ) , V_195 ) ;
if ( ! V_340 )
return NULL ;
F_191 ( & V_340 -> V_185 , & V_2 -> V_367 ) ;
}
F_19 ( L_21 , V_2 -> V_26 , V_124 , type ) ;
if ( type == V_349 &&
( ! V_264 || V_264 -> V_352 == 0xff ) && V_347 == 0xff ) {
type = V_368 ;
if ( V_264 )
V_264 -> V_346 = type ;
}
F_76 ( & V_340 -> V_124 , V_124 ) ;
memcpy ( V_340 -> V_361 , V_361 , V_369 ) ;
V_340 -> V_364 = V_364 ;
if ( type == V_349 )
V_340 -> type = V_347 ;
else
V_340 -> type = type ;
if ( V_365 )
* V_365 = F_183 ( V_2 , V_264 , type ,
V_347 ) ;
return V_340 ;
}
struct V_342 * F_192 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 V_356 , T_5 type , T_5 V_370 ,
T_5 V_371 [ 16 ] , T_5 V_372 , T_9 V_373 , T_13 rand )
{
struct V_342 * V_340 , * V_366 ;
T_5 V_357 = F_184 ( type ) ;
V_366 = F_185 ( V_2 , V_124 , V_356 , V_357 ) ;
if ( V_366 )
V_340 = V_366 ;
else {
V_340 = F_113 ( sizeof( * V_340 ) , V_195 ) ;
if ( ! V_340 )
return NULL ;
F_191 ( & V_340 -> V_185 , & V_2 -> V_374 ) ;
}
F_76 ( & V_340 -> V_124 , V_124 ) ;
V_340 -> V_358 = V_356 ;
memcpy ( V_340 -> V_361 , V_371 , sizeof( V_340 -> V_361 ) ) ;
V_340 -> V_370 = V_370 ;
V_340 -> V_373 = V_373 ;
V_340 -> rand = rand ;
V_340 -> V_372 = V_372 ;
V_340 -> type = type ;
return V_340 ;
}
struct V_344 * F_193 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 V_356 , T_5 V_361 [ 16 ] , T_11 * V_359 )
{
struct V_344 * V_360 ;
V_360 = F_189 ( V_2 , V_124 , V_356 ) ;
if ( ! V_360 ) {
V_360 = F_113 ( sizeof( * V_360 ) , V_195 ) ;
if ( ! V_360 )
return NULL ;
F_76 ( & V_360 -> V_124 , V_124 ) ;
V_360 -> V_356 = V_356 ;
F_191 ( & V_360 -> V_185 , & V_2 -> V_375 ) ;
}
memcpy ( V_360 -> V_361 , V_361 , 16 ) ;
F_76 ( & V_360 -> V_359 , V_359 ) ;
return V_360 ;
}
int F_194 ( struct V_1 * V_2 , T_11 * V_124 )
{
struct V_339 * V_340 ;
V_340 = F_180 ( V_2 , V_124 ) ;
if ( ! V_340 )
return - V_376 ;
F_19 ( L_22 , V_2 -> V_26 , V_124 ) ;
F_176 ( & V_340 -> V_185 ) ;
F_177 ( V_340 , V_341 ) ;
return 0 ;
}
int F_195 ( struct V_1 * V_2 , T_11 * V_124 , T_5 V_358 )
{
struct V_342 * V_343 ;
int V_377 = 0 ;
F_175 (k, &hdev->long_term_keys, list) {
if ( F_106 ( V_124 , & V_343 -> V_124 ) || V_343 -> V_358 != V_358 )
continue;
F_19 ( L_22 , V_2 -> V_26 , V_124 ) ;
F_176 ( & V_343 -> V_185 ) ;
F_177 ( V_343 , V_341 ) ;
V_377 ++ ;
}
return V_377 ? 0 : - V_376 ;
}
void F_196 ( struct V_1 * V_2 , T_11 * V_124 , T_5 V_356 )
{
struct V_344 * V_343 ;
F_175 (k, &hdev->identity_resolving_keys, list) {
if ( F_106 ( V_124 , & V_343 -> V_124 ) || V_343 -> V_356 != V_356 )
continue;
F_19 ( L_22 , V_2 -> V_26 , V_124 ) ;
F_176 ( & V_343 -> V_185 ) ;
F_177 ( V_343 , V_341 ) ;
}
}
bool F_197 ( struct V_1 * V_2 , T_11 * V_124 , T_5 type )
{
struct V_342 * V_343 ;
struct V_344 * V_360 ;
T_5 V_356 ;
if ( type == V_190 ) {
if ( F_180 ( V_2 , V_124 ) )
return true ;
return false ;
}
if ( type == V_378 )
V_356 = V_379 ;
else
V_356 = V_362 ;
V_360 = F_198 ( V_2 , V_124 , V_356 ) ;
if ( V_360 ) {
V_124 = & V_360 -> V_124 ;
V_356 = V_360 -> V_356 ;
}
F_181 () ;
F_175 (k, &hdev->long_term_keys, list) {
if ( V_343 -> V_358 == V_356 && ! F_106 ( V_124 , & V_343 -> V_124 ) ) {
F_182 () ;
return true ;
}
}
F_182 () ;
return false ;
}
static void F_199 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 ,
V_267 . V_330 ) ;
if ( V_2 -> V_254 ) {
struct V_380 * V_381 = ( void * ) V_2 -> V_254 -> V_180 ;
T_6 V_25 = F_200 ( V_381 -> V_25 ) ;
F_45 ( L_23 , V_2 -> V_26 , V_25 ) ;
} else {
F_45 ( L_24 , V_2 -> V_26 ) ;
}
F_127 ( & V_2 -> V_240 , 1 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_249 ) ;
}
struct V_382 * F_202 ( struct V_1 * V_2 ,
T_11 * V_124 , T_5 V_358 )
{
struct V_382 * V_180 ;
F_93 (data, &hdev->remote_oob_data, list) {
if ( F_106 ( V_124 , & V_180 -> V_124 ) != 0 )
continue;
if ( V_180 -> V_358 != V_358 )
continue;
return V_180 ;
}
return NULL ;
}
int F_112 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 V_358 )
{
struct V_382 * V_180 ;
V_180 = F_202 ( V_2 , V_124 , V_358 ) ;
if ( ! V_180 )
return - V_376 ;
F_19 ( L_25 , V_2 -> V_26 , V_124 , V_358 ) ;
F_102 ( & V_180 -> V_185 ) ;
F_103 ( V_180 ) ;
return 0 ;
}
void F_203 ( struct V_1 * V_2 )
{
struct V_382 * V_180 , * V_175 ;
F_101 (data, n, &hdev->remote_oob_data, list) {
F_102 ( & V_180 -> V_185 ) ;
F_103 ( V_180 ) ;
}
}
int F_204 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 V_358 , T_5 * V_383 , T_5 * V_384 ,
T_5 * V_385 , T_5 * V_386 )
{
struct V_382 * V_180 ;
V_180 = F_202 ( V_2 , V_124 , V_358 ) ;
if ( ! V_180 ) {
V_180 = F_123 ( sizeof( * V_180 ) , V_195 ) ;
if ( ! V_180 )
return - V_232 ;
F_76 ( & V_180 -> V_124 , V_124 ) ;
V_180 -> V_358 = V_358 ;
F_110 ( & V_180 -> V_185 , & V_2 -> V_387 ) ;
}
if ( V_383 && V_384 ) {
memcpy ( V_180 -> V_383 , V_383 , sizeof( V_180 -> V_383 ) ) ;
memcpy ( V_180 -> V_384 , V_384 , sizeof( V_180 -> V_384 ) ) ;
if ( V_385 && V_386 )
V_180 -> V_388 = 0x03 ;
} else {
memset ( V_180 -> V_383 , 0 , sizeof( V_180 -> V_383 ) ) ;
memset ( V_180 -> V_384 , 0 , sizeof( V_180 -> V_384 ) ) ;
if ( V_385 && V_386 )
V_180 -> V_388 = 0x02 ;
else
V_180 -> V_388 = 0x00 ;
}
if ( V_385 && V_386 ) {
memcpy ( V_180 -> V_385 , V_385 , sizeof( V_180 -> V_385 ) ) ;
memcpy ( V_180 -> V_386 , V_386 , sizeof( V_180 -> V_386 ) ) ;
} else {
memset ( V_180 -> V_385 , 0 , sizeof( V_180 -> V_385 ) ) ;
memset ( V_180 -> V_386 , 0 , sizeof( V_180 -> V_386 ) ) ;
if ( V_383 && V_384 )
V_180 -> V_388 = 0x01 ;
}
F_19 ( L_26 , V_2 -> V_26 , V_124 ) ;
return 0 ;
}
struct V_389 * F_205 ( struct V_1 * V_2 , T_5 V_390 )
{
struct V_389 * V_391 ;
F_93 (adv_instance, &hdev->adv_instances, list) {
if ( V_391 -> V_390 == V_390 )
return V_391 ;
}
return NULL ;
}
struct V_389 * F_206 ( struct V_1 * V_2 , T_5 V_390 ) {
struct V_389 * V_392 ;
V_392 = F_205 ( V_2 , V_390 ) ;
if ( ! V_392 )
return NULL ;
if ( V_392 == F_207 ( & V_2 -> V_393 ,
struct V_389 , V_185 ) )
return F_208 ( & V_2 -> V_393 ,
struct V_389 , V_185 ) ;
else
return F_209 ( V_392 , V_185 ) ;
}
int F_210 ( struct V_1 * V_2 , T_5 V_390 )
{
struct V_389 * V_391 ;
V_391 = F_205 ( V_2 , V_390 ) ;
if ( ! V_391 )
return - V_376 ;
F_19 ( L_27 , V_2 -> V_26 , V_390 ) ;
if ( V_2 -> V_394 == V_390 && V_2 -> V_277 ) {
F_135 ( & V_2 -> V_278 ) ;
V_2 -> V_277 = 0 ;
}
F_102 ( & V_391 -> V_185 ) ;
F_103 ( V_391 ) ;
V_2 -> V_395 -- ;
return 0 ;
}
void F_211 ( struct V_1 * V_2 )
{
struct V_389 * V_391 , * V_175 ;
if ( V_2 -> V_277 ) {
F_135 ( & V_2 -> V_278 ) ;
V_2 -> V_277 = 0 ;
}
F_101 (adv_instance, n, &hdev->adv_instances, list) {
F_102 ( & V_391 -> V_185 ) ;
F_103 ( V_391 ) ;
}
V_2 -> V_395 = 0 ;
}
int F_212 ( struct V_1 * V_2 , T_5 V_390 , T_7 V_16 ,
T_6 V_396 , T_5 * V_397 ,
T_6 V_398 , T_5 * V_399 ,
T_6 V_37 , T_6 V_400 )
{
struct V_389 * V_391 ;
V_391 = F_205 ( V_2 , V_390 ) ;
if ( V_391 ) {
memset ( V_391 -> V_397 , 0 ,
sizeof( V_391 -> V_397 ) ) ;
memset ( V_391 -> V_399 , 0 ,
sizeof( V_391 -> V_399 ) ) ;
} else {
if ( V_2 -> V_395 >= V_401 ||
V_390 < 1 || V_390 > V_401 )
return - V_402 ;
V_391 = F_113 ( sizeof( * V_391 ) , V_195 ) ;
if ( ! V_391 )
return - V_232 ;
V_391 -> V_403 = true ;
V_391 -> V_390 = V_390 ;
F_110 ( & V_391 -> V_185 , & V_2 -> V_393 ) ;
V_2 -> V_395 ++ ;
}
V_391 -> V_16 = V_16 ;
V_391 -> V_396 = V_396 ;
V_391 -> V_398 = V_398 ;
if ( V_396 )
memcpy ( V_391 -> V_397 , V_397 , V_396 ) ;
if ( V_398 )
memcpy ( V_391 -> V_399 ,
V_399 , V_398 ) ;
V_391 -> V_37 = V_37 ;
V_391 -> V_404 = V_37 ;
if ( V_400 == 0 )
V_391 -> V_400 = V_405 ;
else
V_391 -> V_400 = V_400 ;
F_19 ( L_28 , V_2 -> V_26 , V_390 ) ;
return 0 ;
}
struct V_406 * F_213 ( struct V_183 * V_406 ,
T_11 * V_124 , T_5 type )
{
struct V_406 * V_363 ;
F_93 (b, bdaddr_list, list) {
if ( ! F_106 ( & V_363 -> V_124 , V_124 ) && V_363 -> V_358 == type )
return V_363 ;
}
return NULL ;
}
void F_214 ( struct V_183 * V_406 )
{
struct V_183 * V_122 , * V_175 ;
F_215 (p, n, bdaddr_list) {
struct V_406 * V_363 = F_216 ( V_122 , struct V_406 , V_185 ) ;
F_102 ( V_122 ) ;
F_103 ( V_363 ) ;
}
}
int F_217 ( struct V_183 * V_185 , T_11 * V_124 , T_5 type )
{
struct V_406 * V_407 ;
if ( ! F_106 ( V_124 , V_125 ) )
return - V_408 ;
if ( F_213 ( V_185 , V_124 , type ) )
return - V_409 ;
V_407 = F_113 ( sizeof( * V_407 ) , V_195 ) ;
if ( ! V_407 )
return - V_232 ;
F_76 ( & V_407 -> V_124 , V_124 ) ;
V_407 -> V_358 = type ;
F_110 ( & V_407 -> V_185 , V_185 ) ;
return 0 ;
}
int F_218 ( struct V_183 * V_185 , T_11 * V_124 , T_5 type )
{
struct V_406 * V_407 ;
if ( ! F_106 ( V_124 , V_125 ) ) {
F_214 ( V_185 ) ;
return 0 ;
}
V_407 = F_213 ( V_185 , V_124 , type ) ;
if ( ! V_407 )
return - V_376 ;
F_102 ( & V_407 -> V_185 ) ;
F_103 ( V_407 ) ;
return 0 ;
}
struct V_263 * F_219 ( struct V_1 * V_2 ,
T_11 * V_410 , T_5 V_356 )
{
struct V_263 * V_411 ;
if ( ! F_220 ( V_410 , V_356 ) )
return NULL ;
F_93 (params, &hdev->le_conn_params, list) {
if ( F_106 ( & V_411 -> V_410 , V_410 ) == 0 &&
V_411 -> V_356 == V_356 ) {
return V_411 ;
}
}
return NULL ;
}
struct V_263 * F_221 ( struct V_183 * V_185 ,
T_11 * V_410 , T_5 V_356 )
{
struct V_263 * V_36 ;
if ( ! F_220 ( V_410 , V_356 ) )
return NULL ;
F_93 (param, list, action) {
if ( F_106 ( & V_36 -> V_410 , V_410 ) == 0 &&
V_36 -> V_356 == V_356 )
return V_36 ;
}
return NULL ;
}
struct V_263 * F_222 ( struct V_1 * V_2 ,
T_11 * V_410 , T_5 V_356 )
{
struct V_263 * V_411 ;
if ( ! F_220 ( V_410 , V_356 ) )
return NULL ;
V_411 = F_219 ( V_2 , V_410 , V_356 ) ;
if ( V_411 )
return V_411 ;
V_411 = F_113 ( sizeof( * V_411 ) , V_195 ) ;
if ( ! V_411 ) {
F_45 ( L_29 ) ;
return NULL ;
}
F_76 ( & V_411 -> V_410 , V_410 ) ;
V_411 -> V_356 = V_356 ;
F_110 ( & V_411 -> V_185 , & V_2 -> V_412 ) ;
F_104 ( & V_411 -> V_265 ) ;
V_411 -> V_413 = V_2 -> V_414 ;
V_411 -> V_415 = V_2 -> V_416 ;
V_411 -> V_417 = V_2 -> V_418 ;
V_411 -> V_419 = V_2 -> V_420 ;
V_411 -> V_421 = V_422 ;
F_19 ( L_30 , V_410 , V_356 ) ;
return V_411 ;
}
static void F_223 ( struct V_263 * V_411 )
{
if ( V_411 -> V_264 ) {
F_138 ( V_411 -> V_264 ) ;
F_139 ( V_411 -> V_264 ) ;
}
F_102 ( & V_411 -> V_265 ) ;
F_102 ( & V_411 -> V_185 ) ;
F_103 ( V_411 ) ;
}
void F_224 ( struct V_1 * V_2 , T_11 * V_410 , T_5 V_356 )
{
struct V_263 * V_411 ;
V_411 = F_219 ( V_2 , V_410 , V_356 ) ;
if ( ! V_411 )
return;
F_223 ( V_411 ) ;
F_98 ( V_2 ) ;
F_19 ( L_30 , V_410 , V_356 ) ;
}
void F_225 ( struct V_1 * V_2 )
{
struct V_263 * V_411 , * V_338 ;
F_101 (params, tmp, &hdev->le_conn_params, list) {
if ( V_411 -> V_421 != V_422 )
continue;
F_102 ( & V_411 -> V_185 ) ;
F_103 ( V_411 ) ;
}
F_19 ( L_31 ) ;
}
void F_226 ( struct V_1 * V_2 )
{
struct V_263 * V_411 , * V_338 ;
F_101 (params, tmp, &hdev->le_conn_params, list)
F_223 ( V_411 ) ;
F_98 ( V_2 ) ;
F_19 ( L_32 ) ;
}
static void F_227 ( struct V_1 * V_2 , T_5 V_423 , T_6 V_25 )
{
if ( V_423 ) {
F_45 ( L_33 , V_423 ) ;
F_117 ( V_2 ) ;
F_97 ( V_2 , V_170 ) ;
F_120 ( V_2 ) ;
return;
}
}
static void F_228 ( struct V_1 * V_2 , T_5 V_423 ,
T_6 V_25 )
{
T_5 V_215 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_213 V_97 ;
int V_33 ;
if ( V_423 ) {
F_45 ( L_34 , V_423 ) ;
return;
}
V_2 -> V_165 . V_424 = 0 ;
switch ( V_2 -> V_165 . type ) {
case V_425 :
F_117 ( V_2 ) ;
F_97 ( V_2 , V_170 ) ;
F_120 ( V_2 ) ;
break;
case V_426 :
F_117 ( V_2 ) ;
if ( F_8 ( V_427 ,
& V_2 -> V_63 ) ) {
if ( ! F_8 ( V_214 , & V_2 -> V_16 ) &&
V_2 -> V_165 . V_166 != V_168 )
F_97 ( V_2 ,
V_170 ) ;
} else {
struct V_40 V_41 ;
F_100 ( V_2 ) ;
F_25 ( & V_41 , V_2 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
memcpy ( & V_97 . V_215 , V_215 , sizeof( V_97 . V_215 ) ) ;
V_97 . V_216 = V_428 ;
F_40 ( & V_41 , V_218 , sizeof( V_97 ) , & V_97 ) ;
V_33 = F_229 ( & V_41 , F_227 ) ;
if ( V_33 ) {
F_45 ( L_35 , V_33 ) ;
F_97 ( V_2 ,
V_170 ) ;
}
}
F_120 ( V_2 ) ;
break;
}
}
static void F_230 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 ,
V_274 . V_330 ) ;
struct V_40 V_41 ;
int V_33 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_143 ( & V_2 -> V_275 ) ;
F_25 ( & V_41 , V_2 ) ;
F_231 ( & V_41 ) ;
V_33 = F_229 ( & V_41 , F_228 ) ;
if ( V_33 )
F_45 ( L_36 , V_33 ) ;
}
static void F_232 ( struct V_1 * V_2 , T_5 V_423 ,
T_6 V_25 )
{
unsigned long V_37 , V_400 , V_424 , V_429 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( V_423 ) {
F_45 ( L_37 , V_423 ) ;
return;
}
if ( ! F_8 ( V_430 , & V_2 -> V_63 ) ||
! V_2 -> V_165 . V_424 )
return;
V_400 = V_2 -> V_165 . V_431 ;
V_424 = V_2 -> V_165 . V_424 ;
V_429 = V_201 ;
if ( V_429 - V_424 <= V_400 ) {
int V_432 ;
if ( V_429 >= V_424 )
V_432 = V_429 - V_424 ;
else
V_432 = V_433 - V_424 + V_429 ;
V_37 = V_400 - V_432 ;
} else {
V_37 = 0 ;
}
F_165 ( V_2 -> V_279 ,
& V_2 -> V_274 , V_37 ) ;
}
static void F_233 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 ,
V_275 . V_330 ) ;
struct V_40 V_41 ;
struct V_434 V_97 ;
int V_33 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( ! F_4 ( V_2 , V_435 ) )
return;
F_25 ( & V_41 , V_2 ) ;
F_231 ( & V_41 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_14 = V_436 ;
V_97 . V_437 = V_438 ;
F_40 ( & V_41 , V_439 , sizeof( V_97 ) , & V_97 ) ;
V_33 = F_229 ( & V_41 , F_232 ) ;
if ( V_33 )
F_45 ( L_38 , V_33 ) ;
}
void F_234 ( struct V_1 * V_2 , T_11 * V_124 ,
T_5 * V_358 )
{
if ( F_4 ( V_2 , V_440 ) ||
! F_106 ( & V_2 -> V_124 , V_125 ) ||
( ! F_4 ( V_2 , V_89 ) &&
F_106 ( & V_2 -> V_236 , V_125 ) ) ) {
F_76 ( V_124 , & V_2 -> V_236 ) ;
* V_358 = V_362 ;
} else {
F_76 ( V_124 , & V_2 -> V_124 ) ;
* V_358 = V_379 ;
}
}
struct V_1 * F_235 ( void )
{
struct V_1 * V_2 ;
V_2 = F_113 ( sizeof( * V_2 ) , V_195 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_309 = ( V_441 | V_442 | V_443 ) ;
V_2 -> V_444 = ( V_445 ) ;
V_2 -> V_305 = ( V_307 ) ;
V_2 -> V_446 = 0x01 ;
V_2 -> V_447 = 0x03 ;
V_2 -> V_448 = 0xffff ;
V_2 -> V_449 = V_450 ;
V_2 -> V_451 = V_450 ;
V_2 -> V_395 = 0 ;
V_2 -> V_394 = 0x00 ;
V_2 -> V_277 = 0 ;
V_2 -> V_452 = 800 ;
V_2 -> V_453 = 80 ;
V_2 -> V_454 = 0x07 ;
V_2 -> V_455 = 0x0800 ;
V_2 -> V_456 = 0x0800 ;
V_2 -> V_457 = 0x0060 ;
V_2 -> V_458 = 0x0030 ;
V_2 -> V_414 = 0x0028 ;
V_2 -> V_416 = 0x0038 ;
V_2 -> V_418 = 0x0000 ;
V_2 -> V_420 = 0x002a ;
V_2 -> V_459 = 0x001b ;
V_2 -> V_460 = 0x0148 ;
V_2 -> V_461 = 0x001b ;
V_2 -> V_462 = 0x0148 ;
V_2 -> V_463 = 0x001b ;
V_2 -> V_464 = 0x0148 ;
V_2 -> V_465 = V_466 ;
V_2 -> V_467 = V_468 ;
V_2 -> V_469 = V_470 ;
V_2 -> V_471 = V_472 ;
F_236 ( & V_2 -> V_473 ) ;
F_236 ( & V_2 -> V_474 ) ;
F_104 ( & V_2 -> V_475 ) ;
F_104 ( & V_2 -> V_476 ) ;
F_104 ( & V_2 -> V_477 ) ;
F_104 ( & V_2 -> V_478 ) ;
F_104 ( & V_2 -> V_367 ) ;
F_104 ( & V_2 -> V_374 ) ;
F_104 ( & V_2 -> V_375 ) ;
F_104 ( & V_2 -> V_387 ) ;
F_104 ( & V_2 -> V_479 ) ;
F_104 ( & V_2 -> V_412 ) ;
F_104 ( & V_2 -> V_480 ) ;
F_104 ( & V_2 -> V_481 ) ;
F_104 ( & V_2 -> V_482 . V_185 ) ;
F_104 ( & V_2 -> V_393 ) ;
F_237 ( & V_2 -> V_250 , V_483 ) ;
F_237 ( & V_2 -> V_249 , V_484 ) ;
F_237 ( & V_2 -> V_248 , V_485 ) ;
F_237 ( & V_2 -> V_331 , F_162 ) ;
F_237 ( & V_2 -> V_333 , F_168 ) ;
F_238 ( & V_2 -> V_259 , F_167 ) ;
F_238 ( & V_2 -> V_269 , F_169 ) ;
F_238 ( & V_2 -> V_274 , F_230 ) ;
F_238 ( & V_2 -> V_275 , F_233 ) ;
F_238 ( & V_2 -> V_278 , F_171 ) ;
F_239 ( & V_2 -> V_252 ) ;
F_239 ( & V_2 -> V_251 ) ;
F_239 ( & V_2 -> V_281 ) ;
F_240 ( & V_2 -> V_32 ) ;
F_238 ( & V_2 -> V_267 , F_199 ) ;
F_241 ( V_2 ) ;
F_242 ( V_2 ) ;
return V_2 ;
}
void F_243 ( struct V_1 * V_2 )
{
F_244 ( & V_2 -> V_257 ) ;
}
int F_245 ( struct V_1 * V_2 )
{
int V_162 , error ;
if ( ! V_2 -> V_238 || ! V_2 -> V_255 || ! V_2 -> V_486 )
return - V_19 ;
switch ( V_2 -> V_64 ) {
case V_65 :
V_162 = F_246 ( & V_487 , 0 , 0 , V_195 ) ;
break;
case V_66 :
V_162 = F_246 ( & V_487 , 1 , 0 , V_195 ) ;
break;
default:
return - V_19 ;
}
if ( V_162 < 0 )
return V_162 ;
sprintf ( V_2 -> V_26 , L_39 , V_162 ) ;
V_2 -> V_162 = V_162 ;
F_19 ( L_40 , V_2 , V_2 -> V_26 , V_2 -> V_324 ) ;
V_2 -> V_279 = F_247 ( L_3 , V_488 | V_489 |
V_490 , 1 , V_2 -> V_26 ) ;
if ( ! V_2 -> V_279 ) {
error = - V_232 ;
goto V_33;
}
V_2 -> V_260 = F_247 ( L_3 , V_488 | V_489 |
V_490 , 1 , V_2 -> V_26 ) ;
if ( ! V_2 -> V_260 ) {
F_248 ( V_2 -> V_279 ) ;
error = - V_232 ;
goto V_33;
}
if ( ! F_249 ( V_491 ) )
V_2 -> V_149 = F_250 ( V_2 -> V_26 , V_491 ) ;
F_251 ( & V_2 -> V_257 , L_3 , V_2 -> V_26 ) ;
error = F_252 ( & V_2 -> V_257 ) ;
if ( error < 0 )
goto V_492;
V_2 -> V_493 = F_253 ( V_2 -> V_26 , & V_2 -> V_257 ,
V_494 , & V_495 ,
V_2 ) ;
if ( V_2 -> V_493 ) {
if ( F_254 ( V_2 -> V_493 ) < 0 ) {
F_255 ( V_2 -> V_493 ) ;
V_2 -> V_493 = NULL ;
}
}
if ( V_2 -> V_493 && F_256 ( V_2 -> V_493 ) )
F_50 ( V_2 , V_234 ) ;
F_50 ( V_2 , V_148 ) ;
F_50 ( V_2 , V_258 ) ;
if ( V_2 -> V_64 == V_65 ) {
F_50 ( V_2 , V_89 ) ;
}
F_257 ( & V_161 ) ;
F_110 ( & V_2 -> V_185 , & V_496 ) ;
F_258 ( & V_161 ) ;
if ( F_8 ( V_153 , & V_2 -> V_63 ) )
F_50 ( V_2 , V_228 ) ;
F_1 ( V_2 , V_497 ) ;
F_94 ( V_2 ) ;
F_201 ( V_2 -> V_260 , & V_2 -> V_331 ) ;
return V_162 ;
V_492:
F_248 ( V_2 -> V_279 ) ;
F_248 ( V_2 -> V_260 ) ;
V_33:
F_259 ( & V_487 , V_2 -> V_162 ) ;
return error ;
}
void F_260 ( struct V_1 * V_2 )
{
int V_162 ;
F_19 ( L_40 , V_2 , V_2 -> V_26 , V_2 -> V_324 ) ;
F_50 ( V_2 , V_233 ) ;
V_162 = V_2 -> V_162 ;
F_257 ( & V_161 ) ;
F_102 ( & V_2 -> V_185 ) ;
F_258 ( & V_161 ) ;
F_141 ( V_2 ) ;
F_261 ( & V_2 -> V_331 ) ;
if ( ! F_8 ( V_241 , & V_2 -> V_16 ) &&
! F_4 ( V_2 , V_148 ) &&
! F_4 ( V_2 , V_151 ) ) {
F_117 ( V_2 ) ;
F_262 ( V_2 ) ;
F_120 ( V_2 ) ;
}
F_263 ( ! F_264 ( & V_2 -> V_475 ) ) ;
F_1 ( V_2 , V_498 ) ;
if ( V_2 -> V_493 ) {
F_265 ( V_2 -> V_493 ) ;
F_255 ( V_2 -> V_493 ) ;
}
F_266 ( & V_2 -> V_257 ) ;
F_267 ( V_2 -> V_149 ) ;
F_248 ( V_2 -> V_279 ) ;
F_248 ( V_2 -> V_260 ) ;
F_117 ( V_2 ) ;
F_214 ( & V_2 -> V_476 ) ;
F_214 ( & V_2 -> V_477 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
F_203 ( V_2 ) ;
F_211 ( V_2 ) ;
F_214 ( & V_2 -> V_479 ) ;
F_226 ( V_2 ) ;
F_268 ( V_2 ) ;
F_120 ( V_2 ) ;
F_125 ( V_2 ) ;
F_259 ( & V_487 , V_162 ) ;
}
int F_269 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_499 ) ;
return 0 ;
}
int F_270 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_500 ) ;
return 0 ;
}
int F_271 ( struct V_1 * V_2 )
{
const T_5 V_501 [] = { V_502 , 0x01 , 0x00 } ;
struct V_11 * V_12 ;
V_12 = F_272 ( 3 , V_503 ) ;
if ( ! V_12 )
return - V_232 ;
F_273 ( V_12 ) -> V_309 = V_504 ;
memcpy ( F_274 ( V_12 , 3 ) , V_501 , 3 ) ;
return F_275 ( V_2 , V_12 ) ;
}
int F_275 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! V_2 || ( ! F_8 ( V_15 , & V_2 -> V_16 )
&& ! F_8 ( V_241 , & V_2 -> V_16 ) ) ) {
F_16 ( V_12 ) ;
return - V_505 ;
}
F_273 ( V_12 ) -> V_506 = 1 ;
F_276 ( V_12 ) ;
F_277 ( & V_2 -> V_252 , V_12 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_250 ) ;
return 0 ;
}
int F_278 ( struct V_507 * V_508 )
{
F_19 ( L_41 , V_508 , V_508 -> V_26 ) ;
F_279 ( & V_509 ) ;
F_280 ( & V_508 -> V_185 , & V_510 ) ;
F_281 ( & V_509 ) ;
return 0 ;
}
int F_282 ( struct V_507 * V_508 )
{
F_19 ( L_41 , V_508 , V_508 -> V_26 ) ;
F_279 ( & V_509 ) ;
F_102 ( & V_508 -> V_185 ) ;
F_281 ( & V_509 ) ;
return 0 ;
}
static void F_283 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_33 ;
F_19 ( L_42 , V_2 -> V_26 , F_273 ( V_12 ) -> V_309 , V_12 -> V_511 ) ;
F_276 ( V_12 ) ;
F_284 ( V_2 , V_12 ) ;
if ( F_285 ( & V_2 -> V_512 ) ) {
F_286 ( V_2 , V_12 ) ;
}
F_287 ( V_12 ) ;
V_33 = V_2 -> V_486 ( V_2 , V_12 ) ;
if ( V_33 < 0 ) {
F_45 ( L_43 , V_2 -> V_26 , V_33 ) ;
F_16 ( V_12 ) ;
}
}
int F_288 ( struct V_1 * V_2 , T_12 V_25 , T_8 V_35 ,
const void * V_36 )
{
struct V_11 * V_12 ;
F_19 ( L_44 , V_2 -> V_26 , V_25 , V_35 ) ;
V_12 = F_289 ( V_2 , V_25 , V_35 , V_36 ) ;
if ( ! V_12 ) {
F_45 ( L_45 , V_2 -> V_26 ) ;
return - V_232 ;
}
F_273 ( V_12 ) -> V_41 . V_513 = true ;
F_277 ( & V_2 -> V_251 , V_12 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_249 ) ;
return 0 ;
}
void * F_290 ( struct V_1 * V_2 , T_12 V_25 )
{
struct V_380 * V_514 ;
if ( ! V_2 -> V_254 )
return NULL ;
V_514 = ( void * ) V_2 -> V_254 -> V_180 ;
if ( V_514 -> V_25 != F_47 ( V_25 ) )
return NULL ;
F_19 ( L_46 , V_2 -> V_26 , V_25 ) ;
return V_2 -> V_254 -> V_180 + V_515 ;
}
static void F_291 ( struct V_11 * V_12 , T_12 V_516 , T_12 V_16 )
{
struct V_517 * V_514 ;
int V_511 = V_12 -> V_511 ;
F_292 ( V_12 , V_518 ) ;
F_293 ( V_12 ) ;
V_514 = (struct V_517 * ) F_294 ( V_12 ) ;
V_514 -> V_516 = F_47 ( F_295 ( V_516 , V_16 ) ) ;
V_514 -> V_519 = F_47 ( V_511 ) ;
}
static void F_296 ( struct V_520 * V_521 , struct V_522 * V_523 ,
struct V_11 * V_12 , T_12 V_16 )
{
struct V_345 * V_264 = V_521 -> V_264 ;
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_11 * V_185 ;
V_12 -> V_511 = F_297 ( V_12 ) ;
V_12 -> V_524 = 0 ;
F_273 ( V_12 ) -> V_309 = V_525 ;
switch ( V_2 -> V_64 ) {
case V_65 :
F_291 ( V_12 , V_264 -> V_516 , V_16 ) ;
break;
case V_66 :
F_291 ( V_12 , V_521 -> V_516 , V_16 ) ;
break;
default:
F_45 ( L_47 , V_2 -> V_26 , V_2 -> V_64 ) ;
return;
}
V_185 = F_298 ( V_12 ) -> V_526 ;
if ( ! V_185 ) {
F_19 ( L_48 , V_2 -> V_26 , V_12 , V_12 -> V_511 ) ;
F_277 ( V_523 , V_12 ) ;
} else {
F_19 ( L_49 , V_2 -> V_26 , V_12 , V_12 -> V_511 ) ;
F_298 ( V_12 ) -> V_526 = NULL ;
F_299 ( & V_523 -> V_473 ) ;
F_300 ( V_523 , V_12 ) ;
V_16 &= ~ V_527 ;
V_16 |= V_528 ;
do {
V_12 = V_185 ; V_185 = V_185 -> V_529 ;
F_273 ( V_12 ) -> V_309 = V_525 ;
F_291 ( V_12 , V_264 -> V_516 , V_16 ) ;
F_19 ( L_49 , V_2 -> V_26 , V_12 , V_12 -> V_511 ) ;
F_300 ( V_523 , V_12 ) ;
} while ( V_185 );
F_301 ( & V_523 -> V_473 ) ;
}
}
void F_302 ( struct V_520 * V_521 , struct V_11 * V_12 , T_12 V_16 )
{
struct V_1 * V_2 = V_521 -> V_264 -> V_2 ;
F_19 ( L_50 , V_2 -> V_26 , V_521 , V_16 ) ;
F_296 ( V_521 , & V_521 -> V_530 , V_12 , V_16 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_248 ) ;
}
void F_303 ( struct V_345 * V_264 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_531 V_514 ;
F_19 ( L_51 , V_2 -> V_26 , V_12 -> V_511 ) ;
V_514 . V_516 = F_47 ( V_264 -> V_516 ) ;
V_514 . V_519 = V_12 -> V_511 ;
F_292 ( V_12 , V_532 ) ;
F_293 ( V_12 ) ;
memcpy ( F_294 ( V_12 ) , & V_514 , V_532 ) ;
F_273 ( V_12 ) -> V_309 = V_533 ;
F_277 ( & V_264 -> V_530 , V_12 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_248 ) ;
}
static struct V_345 * F_304 ( struct V_1 * V_2 , T_10 type ,
int * V_534 )
{
struct V_535 * V_536 = & V_2 -> V_482 ;
struct V_345 * V_264 = NULL , * V_537 ;
unsigned int V_202 = 0 , F_7 = ~ 0 ;
F_181 () ;
F_175 (c, &h->list, list) {
if ( V_537 -> type != type || F_305 ( & V_537 -> V_530 ) )
continue;
if ( V_537 -> V_166 != V_538 && V_537 -> V_166 != V_539 )
continue;
V_202 ++ ;
if ( V_537 -> V_381 < F_7 ) {
F_7 = V_537 -> V_381 ;
V_264 = V_537 ;
}
if ( F_306 ( V_2 , type ) == V_202 )
break;
}
F_182 () ;
if ( V_264 ) {
int V_540 , V_541 ;
switch ( V_264 -> type ) {
case V_542 :
V_540 = V_2 -> V_285 ;
break;
case V_543 :
case V_544 :
V_540 = V_2 -> V_286 ;
break;
case V_350 :
V_540 = V_2 -> V_325 ? V_2 -> V_287 : V_2 -> V_285 ;
break;
default:
V_540 = 0 ;
F_45 ( L_52 ) ;
}
V_541 = V_540 / V_202 ;
* V_534 = V_541 ? V_541 : 1 ;
} else
* V_534 = 0 ;
F_19 ( L_53 , V_264 , * V_534 ) ;
return V_264 ;
}
static void F_307 ( struct V_1 * V_2 , T_10 type )
{
struct V_535 * V_536 = & V_2 -> V_482 ;
struct V_345 * V_537 ;
F_45 ( L_54 , V_2 -> V_26 ) ;
F_181 () ;
F_175 (c, &h->list, list) {
if ( V_537 -> type == type && V_537 -> V_381 ) {
F_45 ( L_55 ,
V_2 -> V_26 , & V_537 -> V_545 ) ;
F_308 ( V_537 , V_546 ) ;
}
}
F_182 () ;
}
static struct V_520 * F_309 ( struct V_1 * V_2 , T_10 type ,
int * V_534 )
{
struct V_535 * V_536 = & V_2 -> V_482 ;
struct V_520 * V_521 = NULL ;
unsigned int V_202 = 0 , F_7 = ~ 0 , V_547 = 0 ;
struct V_345 * V_264 ;
int V_540 , V_541 , V_548 = 0 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_181 () ;
F_175 (conn, &h->list, list) {
struct V_520 * V_338 ;
if ( V_264 -> type != type )
continue;
if ( V_264 -> V_166 != V_538 && V_264 -> V_166 != V_539 )
continue;
V_548 ++ ;
F_175 (tmp, &conn->chan_list, list) {
struct V_11 * V_12 ;
if ( F_305 ( & V_338 -> V_530 ) )
continue;
V_12 = F_310 ( & V_338 -> V_530 ) ;
if ( V_12 -> V_549 < V_547 )
continue;
if ( V_12 -> V_549 > V_547 ) {
V_202 = 0 ;
F_7 = ~ 0 ;
V_547 = V_12 -> V_549 ;
}
V_202 ++ ;
if ( V_264 -> V_381 < F_7 ) {
F_7 = V_264 -> V_381 ;
V_521 = V_338 ;
}
}
if ( F_306 ( V_2 , type ) == V_548 )
break;
}
F_182 () ;
if ( ! V_521 )
return NULL ;
switch ( V_521 -> V_264 -> type ) {
case V_542 :
V_540 = V_2 -> V_285 ;
break;
case V_550 :
V_540 = V_2 -> V_551 ;
break;
case V_543 :
case V_544 :
V_540 = V_2 -> V_286 ;
break;
case V_350 :
V_540 = V_2 -> V_325 ? V_2 -> V_287 : V_2 -> V_285 ;
break;
default:
V_540 = 0 ;
F_45 ( L_52 ) ;
}
V_541 = V_540 / V_202 ;
* V_534 = V_541 ? V_541 : 1 ;
F_19 ( L_56 , V_521 , * V_534 ) ;
return V_521 ;
}
static void F_311 ( struct V_1 * V_2 , T_10 type )
{
struct V_535 * V_536 = & V_2 -> V_482 ;
struct V_345 * V_264 ;
int V_202 = 0 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
F_181 () ;
F_175 (conn, &h->list, list) {
struct V_520 * V_521 ;
if ( V_264 -> type != type )
continue;
if ( V_264 -> V_166 != V_538 && V_264 -> V_166 != V_539 )
continue;
V_202 ++ ;
F_175 (chan, &conn->chan_list, list) {
struct V_11 * V_12 ;
if ( V_521 -> V_381 ) {
V_521 -> V_381 = 0 ;
continue;
}
if ( F_305 ( & V_521 -> V_530 ) )
continue;
V_12 = F_310 ( & V_521 -> V_530 ) ;
if ( V_12 -> V_549 >= V_552 - 1 )
continue;
V_12 -> V_549 = V_552 - 1 ;
F_19 ( L_57 , V_521 , V_12 ,
V_12 -> V_549 ) ;
}
if ( F_306 ( V_2 , type ) == V_202 )
break;
}
F_182 () ;
}
static inline int F_312 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return F_313 ( V_12 -> V_511 - V_518 , V_2 -> V_553 ) ;
}
static void F_314 ( struct V_1 * V_2 , unsigned int V_540 )
{
if ( ! F_4 ( V_2 , V_228 ) ) {
if ( ! V_540 && F_315 ( V_201 , V_2 -> V_554 +
V_555 ) )
F_307 ( V_2 , V_542 ) ;
}
}
static void F_316 ( struct V_1 * V_2 )
{
unsigned int V_540 = V_2 -> V_285 ;
struct V_520 * V_521 ;
struct V_11 * V_12 ;
int V_534 ;
F_314 ( V_2 , V_540 ) ;
while ( V_2 -> V_285 &&
( V_521 = F_309 ( V_2 , V_542 , & V_534 ) ) ) {
T_7 V_549 = ( F_310 ( & V_521 -> V_530 ) ) -> V_549 ;
while ( V_534 -- && ( V_12 = F_310 ( & V_521 -> V_530 ) ) ) {
F_19 ( L_58 , V_521 , V_12 ,
V_12 -> V_511 , V_12 -> V_549 ) ;
if ( V_12 -> V_549 < V_549 )
break;
V_12 = F_317 ( & V_521 -> V_530 ) ;
F_318 ( V_521 -> V_264 ,
F_273 ( V_12 ) -> V_556 ) ;
F_283 ( V_2 , V_12 ) ;
V_2 -> V_554 = V_201 ;
V_2 -> V_285 -- ;
V_521 -> V_381 ++ ;
V_521 -> V_264 -> V_381 ++ ;
}
}
if ( V_540 != V_2 -> V_285 )
F_311 ( V_2 , V_542 ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
unsigned int V_540 = V_2 -> V_551 ;
struct V_520 * V_521 ;
struct V_11 * V_12 ;
int V_534 ;
T_5 type ;
F_314 ( V_2 , V_540 ) ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( V_2 -> V_64 == V_66 )
type = V_550 ;
else
type = V_542 ;
while ( V_2 -> V_551 > 0 &&
( V_521 = F_309 ( V_2 , type , & V_534 ) ) ) {
T_7 V_549 = ( F_310 ( & V_521 -> V_530 ) ) -> V_549 ;
while ( V_534 > 0 && ( V_12 = F_310 ( & V_521 -> V_530 ) ) ) {
int V_557 ;
F_19 ( L_58 , V_521 , V_12 ,
V_12 -> V_511 , V_12 -> V_549 ) ;
if ( V_12 -> V_549 < V_549 )
break;
V_12 = F_317 ( & V_521 -> V_530 ) ;
V_557 = F_312 ( V_2 , V_12 ) ;
if ( V_557 > V_2 -> V_551 )
return;
F_318 ( V_521 -> V_264 ,
F_273 ( V_12 ) -> V_556 ) ;
F_283 ( V_2 , V_12 ) ;
V_2 -> V_554 = V_201 ;
V_2 -> V_551 -= V_557 ;
V_534 -= V_557 ;
V_521 -> V_381 += V_557 ;
V_521 -> V_264 -> V_381 += V_557 ;
}
}
if ( V_540 != V_2 -> V_551 )
F_311 ( V_2 , type ) ;
}
static void F_320 ( struct V_1 * V_2 )
{
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( ! F_306 ( V_2 , V_542 ) && V_2 -> V_64 == V_65 )
return;
if ( ! F_306 ( V_2 , V_550 ) && V_2 -> V_64 == V_66 )
return;
switch ( V_2 -> V_50 ) {
case V_51 :
F_316 ( V_2 ) ;
break;
case V_55 :
F_319 ( V_2 ) ;
break;
}
}
static void F_321 ( struct V_1 * V_2 )
{
struct V_345 * V_264 ;
struct V_11 * V_12 ;
int V_534 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( ! F_306 ( V_2 , V_543 ) )
return;
while ( V_2 -> V_286 && ( V_264 = F_304 ( V_2 , V_543 , & V_534 ) ) ) {
while ( V_534 -- && ( V_12 = F_317 ( & V_264 -> V_530 ) ) ) {
F_19 ( L_59 , V_12 , V_12 -> V_511 ) ;
F_283 ( V_2 , V_12 ) ;
V_264 -> V_381 ++ ;
if ( V_264 -> V_381 == ~ 0 )
V_264 -> V_381 = 0 ;
}
}
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_345 * V_264 ;
struct V_11 * V_12 ;
int V_534 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( ! F_306 ( V_2 , V_544 ) )
return;
while ( V_2 -> V_286 && ( V_264 = F_304 ( V_2 , V_544 ,
& V_534 ) ) ) {
while ( V_534 -- && ( V_12 = F_317 ( & V_264 -> V_530 ) ) ) {
F_19 ( L_59 , V_12 , V_12 -> V_511 ) ;
F_283 ( V_2 , V_12 ) ;
V_264 -> V_381 ++ ;
if ( V_264 -> V_381 == ~ 0 )
V_264 -> V_381 = 0 ;
}
}
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_520 * V_521 ;
struct V_11 * V_12 ;
int V_534 , V_540 , V_338 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
if ( ! F_306 ( V_2 , V_350 ) )
return;
if ( ! F_4 ( V_2 , V_228 ) ) {
if ( ! V_2 -> V_287 && V_2 -> V_326 &&
F_315 ( V_201 , V_2 -> V_558 + V_559 * 45 ) )
F_307 ( V_2 , V_350 ) ;
}
V_540 = V_2 -> V_326 ? V_2 -> V_287 : V_2 -> V_285 ;
V_338 = V_540 ;
while ( V_540 && ( V_521 = F_309 ( V_2 , V_350 , & V_534 ) ) ) {
T_7 V_549 = ( F_310 ( & V_521 -> V_530 ) ) -> V_549 ;
while ( V_534 -- && ( V_12 = F_310 ( & V_521 -> V_530 ) ) ) {
F_19 ( L_58 , V_521 , V_12 ,
V_12 -> V_511 , V_12 -> V_549 ) ;
if ( V_12 -> V_549 < V_549 )
break;
V_12 = F_317 ( & V_521 -> V_530 ) ;
F_283 ( V_2 , V_12 ) ;
V_2 -> V_558 = V_201 ;
V_540 -- ;
V_521 -> V_381 ++ ;
V_521 -> V_264 -> V_381 ++ ;
}
}
if ( V_2 -> V_326 )
V_2 -> V_287 = V_540 ;
else
V_2 -> V_285 = V_540 ;
if ( V_540 != V_338 )
F_311 ( V_2 , V_350 ) ;
}
static void V_485 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 , V_248 ) ;
struct V_11 * V_12 ;
F_19 ( L_60 , V_2 -> V_26 , V_2 -> V_285 ,
V_2 -> V_286 , V_2 -> V_287 ) ;
if ( ! F_4 ( V_2 , V_226 ) ) {
F_320 ( V_2 ) ;
F_321 ( V_2 ) ;
F_322 ( V_2 ) ;
F_323 ( V_2 ) ;
}
while ( ( V_12 = F_317 ( & V_2 -> V_281 ) ) )
F_283 ( V_2 , V_12 ) ;
}
static void F_324 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_517 * V_514 = ( void * ) V_12 -> V_180 ;
struct V_345 * V_264 ;
T_12 V_516 , V_16 ;
F_325 ( V_12 , V_518 ) ;
V_516 = F_200 ( V_514 -> V_516 ) ;
V_16 = F_326 ( V_516 ) ;
V_516 = F_327 ( V_516 ) ;
F_19 ( L_61 , V_2 -> V_26 , V_12 -> V_511 ,
V_516 , V_16 ) ;
V_2 -> V_288 . V_560 ++ ;
F_117 ( V_2 ) ;
V_264 = F_328 ( V_2 , V_516 ) ;
F_120 ( V_2 ) ;
if ( V_264 ) {
F_318 ( V_264 , V_561 ) ;
F_329 ( V_264 , V_12 , V_16 ) ;
return;
} else {
F_45 ( L_62 ,
V_2 -> V_26 , V_516 ) ;
}
F_16 ( V_12 ) ;
}
static void F_330 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_531 * V_514 = ( void * ) V_12 -> V_180 ;
struct V_345 * V_264 ;
T_12 V_516 ;
F_325 ( V_12 , V_532 ) ;
V_516 = F_200 ( V_514 -> V_516 ) ;
F_19 ( L_63 , V_2 -> V_26 , V_12 -> V_511 , V_516 ) ;
V_2 -> V_288 . V_562 ++ ;
F_117 ( V_2 ) ;
V_264 = F_328 ( V_2 , V_516 ) ;
F_120 ( V_2 ) ;
if ( V_264 ) {
F_331 ( V_264 , V_12 ) ;
return;
} else {
F_45 ( L_64 ,
V_2 -> V_26 , V_516 ) ;
}
F_16 ( V_12 ) ;
}
static bool F_332 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_310 ( & V_2 -> V_251 ) ;
if ( ! V_12 )
return true ;
return F_273 ( V_12 ) -> V_41 . V_513 ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_380 * V_381 ;
struct V_11 * V_12 ;
T_6 V_25 ;
if ( ! V_2 -> V_254 )
return;
V_381 = ( void * ) V_2 -> V_254 -> V_180 ;
V_25 = F_200 ( V_381 -> V_25 ) ;
if ( V_25 == V_23 )
return;
V_12 = F_334 ( V_2 -> V_254 , V_195 ) ;
if ( ! V_12 )
return;
F_335 ( & V_2 -> V_251 , V_12 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_249 ) ;
}
void F_336 ( struct V_1 * V_2 , T_6 V_25 , T_5 V_423 ,
T_14 * V_563 ,
T_15 * V_564 )
{
struct V_11 * V_12 ;
unsigned long V_16 ;
F_19 ( L_65 , V_25 , V_423 ) ;
if ( ! F_290 ( V_2 , V_25 ) ) {
if ( F_8 ( V_241 , & V_2 -> V_16 ) && V_25 == V_23 )
F_333 ( V_2 ) ;
return;
}
if ( ! V_423 && ! F_332 ( V_2 ) )
return;
if ( F_273 ( V_2 -> V_254 ) -> V_41 . V_565 ) {
* V_563 = F_273 ( V_2 -> V_254 ) -> V_41 . V_565 ;
return;
}
if ( F_273 ( V_2 -> V_254 ) -> V_41 . V_566 ) {
* V_564 = F_273 ( V_2 -> V_254 ) -> V_41 . V_566 ;
return;
}
F_337 ( & V_2 -> V_251 . V_473 , V_16 ) ;
while ( ( V_12 = F_338 ( & V_2 -> V_251 ) ) ) {
if ( F_273 ( V_12 ) -> V_41 . V_513 ) {
F_339 ( & V_2 -> V_251 , V_12 ) ;
break;
}
* V_563 = F_273 ( V_12 ) -> V_41 . V_565 ;
* V_564 = F_273 ( V_12 ) -> V_41 . V_566 ;
F_16 ( V_12 ) ;
}
F_340 ( & V_2 -> V_251 . V_473 , V_16 ) ;
}
static void V_483 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 , V_250 ) ;
struct V_11 * V_12 ;
F_19 ( L_3 , V_2 -> V_26 ) ;
while ( ( V_12 = F_317 ( & V_2 -> V_252 ) ) ) {
F_284 ( V_2 , V_12 ) ;
if ( F_285 ( & V_2 -> V_512 ) ) {
F_286 ( V_2 , V_12 ) ;
}
if ( F_4 ( V_2 , V_226 ) ) {
F_16 ( V_12 ) ;
continue;
}
if ( F_8 ( V_241 , & V_2 -> V_16 ) ) {
switch ( F_273 ( V_12 ) -> V_309 ) {
case V_525 :
case V_533 :
F_16 ( V_12 ) ;
continue;
}
}
switch ( F_273 ( V_12 ) -> V_309 ) {
case V_504 :
F_19 ( L_66 , V_2 -> V_26 ) ;
F_341 ( V_2 , V_12 ) ;
break;
case V_525 :
F_19 ( L_67 , V_2 -> V_26 ) ;
F_324 ( V_2 , V_12 ) ;
break;
case V_533 :
F_19 ( L_68 , V_2 -> V_26 ) ;
F_330 ( V_2 , V_12 ) ;
break;
default:
F_16 ( V_12 ) ;
break;
}
}
}
static void V_484 ( struct V_329 * V_330 )
{
struct V_1 * V_2 = F_163 ( V_330 , struct V_1 , V_249 ) ;
struct V_11 * V_12 ;
F_19 ( L_69 , V_2 -> V_26 ,
F_285 ( & V_2 -> V_240 ) , F_342 ( & V_2 -> V_251 ) ) ;
if ( F_285 ( & V_2 -> V_240 ) ) {
V_12 = F_317 ( & V_2 -> V_251 ) ;
if ( ! V_12 )
return;
F_16 ( V_2 -> V_254 ) ;
V_2 -> V_254 = F_334 ( V_12 , V_195 ) ;
if ( V_2 -> V_254 ) {
F_343 ( & V_2 -> V_240 ) ;
F_283 ( V_2 , V_12 ) ;
if ( F_8 ( V_49 , & V_2 -> V_16 ) )
F_135 ( & V_2 -> V_267 ) ;
else
F_344 ( & V_2 -> V_267 ,
V_22 ) ;
} else {
F_335 ( & V_2 -> V_251 , V_12 ) ;
F_201 ( V_2 -> V_279 , & V_2 -> V_249 ) ;
}
}
}
