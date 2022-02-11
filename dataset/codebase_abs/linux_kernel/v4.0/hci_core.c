static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_10 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_6 ( struct V_4 * V_4 , const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_12 * V_13 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
int V_16 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_10 , & V_2 -> V_11 ) )
return - V_22 ;
F_10 ( V_2 ) ;
if ( V_15 )
V_13 = F_11 ( V_2 , V_23 , 0 , NULL ,
V_24 ) ;
else
V_13 = F_11 ( V_2 , V_25 , 0 , NULL ,
V_24 ) ;
F_12 ( V_2 ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_16 = - F_15 ( V_13 -> V_26 [ 0 ] ) ;
F_16 ( V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
F_17 ( V_10 , & V_2 -> V_11 ) ;
return V_6 ;
}
static void F_18 ( struct V_1 * V_2 , T_5 V_27 , T_6 V_28 )
{
F_19 ( L_1 , V_2 -> V_29 , V_27 ) ;
if ( V_2 -> V_30 == V_31 ) {
V_2 -> V_32 = V_27 ;
V_2 -> V_30 = V_33 ;
F_20 ( & V_2 -> V_34 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , int V_16 )
{
F_19 ( L_2 , V_2 -> V_29 , V_16 ) ;
if ( V_2 -> V_30 == V_31 ) {
V_2 -> V_32 = V_16 ;
V_2 -> V_30 = V_35 ;
F_20 ( & V_2 -> V_34 ) ;
}
}
static struct V_12 * F_22 ( struct V_1 * V_2 , T_6 V_28 ,
T_5 V_3 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_12 * V_13 ;
F_23 ( V_2 ) ;
V_13 = V_2 -> V_40 ;
V_2 -> V_40 = NULL ;
F_24 ( V_2 ) ;
if ( ! V_13 )
return F_25 ( - V_41 ) ;
if ( V_13 -> V_42 < sizeof( * V_39 ) ) {
F_26 ( L_3 ) ;
goto V_43;
}
V_39 = ( void * ) V_13 -> V_26 ;
F_27 ( V_13 , V_44 ) ;
if ( V_3 ) {
if ( V_39 -> V_45 != V_3 )
goto V_43;
return V_13 ;
}
if ( V_39 -> V_45 != V_46 ) {
F_19 ( L_4 , V_39 -> V_45 ) ;
goto V_43;
}
if ( V_13 -> V_42 < sizeof( * V_37 ) ) {
F_26 ( L_5 ) ;
goto V_43;
}
V_37 = ( void * ) V_13 -> V_26 ;
F_27 ( V_13 , sizeof( * V_37 ) ) ;
if ( V_28 == F_28 ( V_37 -> V_28 ) )
return V_13 ;
F_19 ( L_6 , V_28 ,
F_28 ( V_37 -> V_28 ) ) ;
V_43:
F_16 ( V_13 ) ;
return F_25 ( - V_41 ) ;
}
struct V_12 * F_29 ( struct V_1 * V_2 , T_6 V_28 , T_7 V_47 ,
const void * V_48 , T_5 V_3 , T_7 V_49 )
{
F_30 ( V_50 , V_51 ) ;
struct V_52 V_53 ;
int V_16 = 0 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
F_31 ( & V_53 , V_2 ) ;
F_32 ( & V_53 , V_28 , V_47 , V_48 , V_3 ) ;
V_2 -> V_30 = V_31 ;
F_33 ( & V_2 -> V_34 , & V_50 ) ;
F_34 ( V_54 ) ;
V_16 = F_35 ( & V_53 , F_18 ) ;
if ( V_16 < 0 ) {
F_36 ( & V_2 -> V_34 , & V_50 ) ;
F_34 ( V_55 ) ;
return F_25 ( V_16 ) ;
}
F_37 ( V_49 ) ;
F_36 ( & V_2 -> V_34 , & V_50 ) ;
if ( F_38 ( V_51 ) )
return F_25 ( - V_56 ) ;
switch ( V_2 -> V_30 ) {
case V_33 :
V_16 = - F_15 ( V_2 -> V_32 ) ;
break;
case V_35 :
V_16 = - V_2 -> V_32 ;
break;
default:
V_16 = - V_57 ;
break;
}
V_2 -> V_30 = V_2 -> V_32 = 0 ;
F_19 ( L_8 , V_2 -> V_29 , V_16 ) ;
if ( V_16 < 0 )
return F_25 ( V_16 ) ;
return F_22 ( V_2 , V_28 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_6 V_28 , T_7 V_47 ,
const void * V_48 , T_7 V_49 )
{
return F_29 ( V_2 , V_28 , V_47 , V_48 , 0 , V_49 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
void (* F_40)( struct V_52 * V_53 ,
unsigned long V_58 ) ,
unsigned long V_58 , T_8 V_49 )
{
struct V_52 V_53 ;
F_30 ( V_50 , V_51 ) ;
int V_16 = 0 ;
F_19 ( L_9 , V_2 -> V_29 ) ;
F_31 ( & V_53 , V_2 ) ;
V_2 -> V_30 = V_31 ;
F_40 ( & V_53 , V_58 ) ;
F_33 ( & V_2 -> V_34 , & V_50 ) ;
F_34 ( V_54 ) ;
V_16 = F_35 ( & V_53 , F_18 ) ;
if ( V_16 < 0 ) {
V_2 -> V_30 = 0 ;
F_36 ( & V_2 -> V_34 , & V_50 ) ;
F_34 ( V_55 ) ;
if ( V_16 == - V_41 )
return 0 ;
return V_16 ;
}
F_37 ( V_49 ) ;
F_36 ( & V_2 -> V_34 , & V_50 ) ;
if ( F_38 ( V_51 ) )
return - V_56 ;
switch ( V_2 -> V_30 ) {
case V_33 :
V_16 = - F_15 ( V_2 -> V_32 ) ;
break;
case V_35 :
V_16 = - V_2 -> V_32 ;
break;
default:
V_16 = - V_57 ;
break;
}
V_2 -> V_30 = V_2 -> V_32 = 0 ;
F_19 ( L_8 , V_2 -> V_29 , V_16 ) ;
return V_16 ;
}
static int F_41 ( struct V_1 * V_2 ,
void (* V_53)( struct V_52 * V_53 ,
unsigned long V_58 ) ,
unsigned long V_58 , T_8 V_49 )
{
int V_59 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_59 = F_39 ( V_2 , V_53 , V_58 , V_49 ) ;
F_12 ( V_2 ) ;
return V_59 ;
}
static void F_42 ( struct V_52 * V_53 , unsigned long V_58 )
{
F_19 ( L_10 , V_53 -> V_2 -> V_29 , V_58 ) ;
F_43 ( V_60 , & V_53 -> V_2 -> V_18 ) ;
F_44 ( V_53 , V_25 , 0 , NULL ) ;
}
static void F_45 ( struct V_52 * V_53 )
{
V_53 -> V_2 -> V_61 = V_62 ;
F_44 ( V_53 , V_63 , 0 , NULL ) ;
F_44 ( V_53 , V_64 , 0 , NULL ) ;
F_44 ( V_53 , V_65 , 0 , NULL ) ;
}
static void F_46 ( struct V_52 * V_53 )
{
V_53 -> V_2 -> V_61 = V_66 ;
F_44 ( V_53 , V_64 , 0 , NULL ) ;
F_44 ( V_53 , V_67 , 0 , NULL ) ;
F_44 ( V_53 , V_63 , 0 , NULL ) ;
F_44 ( V_53 , V_68 , 0 , NULL ) ;
F_44 ( V_53 , V_69 , 0 , NULL ) ;
F_44 ( V_53 , V_70 , 0 , NULL ) ;
F_44 ( V_53 , V_71 , 0 , NULL ) ;
}
static void F_47 ( struct V_52 * V_53 , unsigned long V_58 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
F_19 ( L_10 , V_2 -> V_29 , V_58 ) ;
if ( ! F_4 ( V_72 , & V_2 -> V_73 ) )
F_42 ( V_53 , 0 ) ;
switch ( V_2 -> V_74 ) {
case V_75 :
F_45 ( V_53 ) ;
break;
case V_76 :
F_46 ( V_53 ) ;
break;
default:
F_26 ( L_11 , V_2 -> V_74 ) ;
break;
}
}
static void F_48 ( struct V_52 * V_53 )
{
T_9 V_48 ;
T_10 V_77 ;
F_44 ( V_53 , V_78 , 0 , NULL ) ;
F_44 ( V_53 , V_79 , 0 , NULL ) ;
F_44 ( V_53 , V_80 , 0 , NULL ) ;
F_44 ( V_53 , V_81 , 0 , NULL ) ;
F_44 ( V_53 , V_82 , 0 , NULL ) ;
F_44 ( V_53 , V_83 , 0 , NULL ) ;
V_77 = V_84 ;
F_44 ( V_53 , V_85 , 1 , & V_77 ) ;
V_48 = F_49 ( 0x7d00 ) ;
F_44 ( V_53 , V_86 , 2 , & V_48 ) ;
}
static void F_50 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
F_44 ( V_53 , V_87 , 0 , NULL ) ;
F_44 ( V_53 , V_88 , 0 , NULL ) ;
F_44 ( V_53 , V_89 , 0 , NULL ) ;
F_44 ( V_53 , V_90 , 0 , NULL ) ;
F_44 ( V_53 , V_91 , 0 , NULL ) ;
if ( ! F_51 ( V_2 ) )
F_43 ( V_92 , & V_2 -> V_93 ) ;
}
static void F_52 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_5 V_94 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_95 < V_96 )
return;
if ( F_51 ( V_2 ) ) {
V_94 [ 4 ] |= 0x01 ;
V_94 [ 4 ] |= 0x02 ;
V_94 [ 4 ] |= 0x04 ;
V_94 [ 5 ] |= 0x08 ;
V_94 [ 5 ] |= 0x10 ;
} else {
memset ( V_94 , 0 , sizeof( V_94 ) ) ;
V_94 [ 0 ] |= 0x10 ;
V_94 [ 1 ] |= 0x08 ;
V_94 [ 1 ] |= 0x20 ;
V_94 [ 1 ] |= 0x40 ;
V_94 [ 1 ] |= 0x80 ;
V_94 [ 2 ] |= 0x04 ;
V_94 [ 3 ] |= 0x02 ;
if ( V_2 -> V_97 [ 0 ] & V_98 ) {
V_94 [ 0 ] |= 0x80 ;
V_94 [ 5 ] |= 0x80 ;
}
}
if ( F_53 ( V_2 ) )
V_94 [ 4 ] |= 0x02 ;
if ( F_54 ( V_2 ) )
V_94 [ 5 ] |= 0x20 ;
if ( F_55 ( V_2 ) )
V_94 [ 5 ] |= 0x80 ;
if ( F_56 ( V_2 ) )
V_94 [ 5 ] |= 0x40 ;
if ( F_57 ( V_2 ) )
V_94 [ 7 ] |= 0x01 ;
if ( F_58 ( V_2 ) )
V_94 [ 6 ] |= 0x80 ;
if ( F_59 ( V_2 ) ) {
V_94 [ 6 ] |= 0x01 ;
V_94 [ 6 ] |= 0x02 ;
V_94 [ 6 ] |= 0x04 ;
V_94 [ 6 ] |= 0x08 ;
V_94 [ 6 ] |= 0x10 ;
V_94 [ 6 ] |= 0x20 ;
V_94 [ 7 ] |= 0x04 ;
V_94 [ 7 ] |= 0x08 ;
V_94 [ 7 ] |= 0x10 ;
}
if ( F_60 ( V_2 ) )
V_94 [ 7 ] |= 0x20 ;
F_44 ( V_53 , V_99 , sizeof( V_94 ) , V_94 ) ;
}
static void F_61 ( struct V_52 * V_53 , unsigned long V_58 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
if ( F_51 ( V_2 ) )
F_48 ( V_53 ) ;
else
F_62 ( V_100 , & V_2 -> V_93 ) ;
if ( F_60 ( V_2 ) )
F_50 ( V_53 ) ;
if ( V_2 -> V_95 > V_101 &&
! F_4 ( V_102 , & V_2 -> V_73 ) )
F_44 ( V_53 , V_67 , 0 , NULL ) ;
if ( F_59 ( V_2 ) ) {
V_2 -> V_103 = 0x01 ;
if ( F_4 ( V_104 , & V_2 -> V_93 ) ) {
T_5 V_105 = 0x01 ;
F_44 ( V_53 , V_106 ,
sizeof( V_105 ) , & V_105 ) ;
} else {
struct V_107 V_108 ;
memset ( V_2 -> V_109 , 0 , sizeof( V_2 -> V_109 ) ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_44 ( V_53 , V_110 , sizeof( V_108 ) , & V_108 ) ;
}
}
if ( F_53 ( V_2 ) ||
F_4 ( V_111 , & V_2 -> V_73 ) ) {
T_5 V_105 ;
V_105 = F_56 ( V_2 ) ? 0x02 : 0x01 ;
F_44 ( V_53 , V_112 , 1 , & V_105 ) ;
}
if ( F_63 ( V_2 ) )
F_44 ( V_53 , V_113 , 0 , NULL ) ;
if ( F_64 ( V_2 ) ) {
struct V_114 V_108 ;
V_108 . V_115 = 0x01 ;
F_44 ( V_53 , V_116 ,
sizeof( V_108 ) , & V_108 ) ;
}
if ( F_4 ( V_117 , & V_2 -> V_93 ) ) {
T_5 V_15 = 1 ;
F_44 ( V_53 , V_118 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_65 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_119 V_108 ;
T_6 V_120 = 0 ;
if ( F_66 ( V_2 ) )
V_120 |= V_121 ;
if ( F_67 ( V_2 ) )
V_120 |= V_122 ;
if ( F_68 ( V_2 ) )
V_120 |= V_123 ;
if ( F_69 ( V_2 ) )
V_120 |= V_124 ;
V_108 . V_125 = F_49 ( V_120 ) ;
F_44 ( V_53 , V_126 , sizeof( V_108 ) , & V_108 ) ;
}
static void F_70 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_127 V_108 ;
if ( ! F_51 ( V_2 ) )
return;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
if ( F_4 ( V_92 , & V_2 -> V_93 ) ) {
V_108 . V_128 = 0x01 ;
V_108 . V_129 = 0x00 ;
}
if ( V_108 . V_128 != F_71 ( V_2 ) )
F_44 ( V_53 , V_130 , sizeof( V_108 ) ,
& V_108 ) ;
}
static void F_72 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_5 V_94 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_73 ( V_2 ) ) {
V_94 [ 1 ] |= 0x40 ;
V_94 [ 1 ] |= 0x80 ;
V_94 [ 2 ] |= 0x10 ;
V_94 [ 2 ] |= 0x20 ;
}
if ( F_74 ( V_2 ) ) {
V_94 [ 2 ] |= 0x01 ;
V_94 [ 2 ] |= 0x02 ;
V_94 [ 2 ] |= 0x04 ;
V_94 [ 2 ] |= 0x08 ;
}
if ( F_75 ( V_2 ) || V_2 -> V_97 [ 0 ] & V_131 )
V_94 [ 2 ] |= 0x80 ;
F_44 ( V_53 , V_132 , sizeof( V_94 ) , V_94 ) ;
}
static void F_76 ( struct V_52 * V_53 , unsigned long V_58 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_5 V_133 ;
F_52 ( V_53 ) ;
if ( V_2 -> V_134 [ 6 ] & 0x20 ) {
struct V_135 V_108 ;
F_77 ( & V_108 . V_136 , V_137 ) ;
V_108 . V_138 = 0x01 ;
F_44 ( V_53 , V_139 , sizeof( V_108 ) , & V_108 ) ;
}
if ( V_2 -> V_134 [ 5 ] & 0x10 )
F_65 ( V_53 ) ;
if ( V_2 -> V_134 [ 8 ] & 0x01 )
F_44 ( V_53 , V_140 , 0 , NULL ) ;
if ( V_2 -> V_134 [ 13 ] & 0x01 )
F_44 ( V_53 , V_141 , 0 , NULL ) ;
if ( F_60 ( V_2 ) ) {
T_5 V_94 [ 8 ] ;
memset ( V_94 , 0 , sizeof( V_94 ) ) ;
V_94 [ 0 ] = 0x0f ;
if ( V_2 -> V_97 [ 0 ] & V_98 )
V_94 [ 0 ] |= 0x10 ;
if ( V_2 -> V_97 [ 0 ] & V_142 )
V_94 [ 0 ] |= 0x20 ;
if ( V_2 -> V_97 [ 0 ] & V_143 )
V_94 [ 0 ] |= 0x40 ;
if ( V_2 -> V_97 [ 0 ] & V_144 )
V_94 [ 1 ] |= 0x04 ;
if ( V_2 -> V_134 [ 34 ] & 0x02 )
V_94 [ 0 ] |= 0x80 ;
if ( V_2 -> V_134 [ 34 ] & 0x04 )
V_94 [ 1 ] |= 0x01 ;
F_44 ( V_53 , V_145 , sizeof( V_94 ) ,
V_94 ) ;
if ( V_2 -> V_134 [ 25 ] & 0x40 ) {
F_44 ( V_53 , V_146 , 0 , NULL ) ;
}
if ( V_2 -> V_97 [ 0 ] & V_143 ) {
F_44 ( V_53 , V_147 , 0 , NULL ) ;
F_44 ( V_53 , V_148 , 0 , NULL ) ;
}
F_70 ( V_53 ) ;
}
for ( V_133 = 2 ; V_133 < V_149 && V_133 <= V_2 -> V_103 ; V_133 ++ ) {
struct V_114 V_108 ;
V_108 . V_115 = V_133 ;
F_44 ( V_53 , V_116 ,
sizeof( V_108 ) , & V_108 ) ;
}
}
static void F_78 ( struct V_52 * V_53 , unsigned long V_58 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
if ( V_2 -> V_134 [ 6 ] & 0x80 &&
! F_4 ( V_150 , & V_2 -> V_73 ) ) {
struct V_151 V_108 ;
F_77 ( & V_108 . V_136 , V_137 ) ;
V_108 . V_152 = 0x01 ;
F_44 ( V_53 , V_153 ,
sizeof( V_108 ) , & V_108 ) ;
}
if ( V_2 -> V_134 [ 22 ] & 0x04 )
F_72 ( V_53 ) ;
if ( V_2 -> V_134 [ 29 ] & 0x20 )
F_44 ( V_53 , V_154 , 0 , NULL ) ;
if ( V_2 -> V_134 [ 30 ] & 0x08 )
F_44 ( V_53 , V_155 , 0 , NULL ) ;
if ( F_79 ( V_2 ) )
F_44 ( V_53 , V_156 , 0 , NULL ) ;
if ( F_4 ( V_104 , & V_2 -> V_93 ) &&
F_80 ( V_2 ) ) {
T_5 V_157 = 0x01 ;
F_44 ( V_53 , V_158 ,
sizeof( V_157 ) , & V_157 ) ;
}
}
static int F_81 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_39 ( V_2 , F_47 , 0 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_160 , & V_2 -> V_93 ) ) {
F_82 ( L_12 , 0644 , V_2 -> V_161 , V_2 ,
& V_162 ) ;
}
if ( V_2 -> V_74 != V_75 )
return 0 ;
V_16 = F_39 ( V_2 , F_61 , 0 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_39 ( V_2 , F_76 , 0 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_39 ( V_2 , F_78 , 0 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_160 , & V_2 -> V_93 ) &&
! F_4 ( V_163 , & V_2 -> V_93 ) )
return 0 ;
F_83 ( V_2 ) ;
if ( F_51 ( V_2 ) )
F_84 ( V_2 ) ;
if ( F_60 ( V_2 ) )
F_85 ( V_2 ) ;
return 0 ;
}
static void F_86 ( struct V_52 * V_53 , unsigned long V_58 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
F_19 ( L_10 , V_2 -> V_29 , V_58 ) ;
if ( ! F_4 ( V_72 , & V_2 -> V_73 ) )
F_42 ( V_53 , 0 ) ;
F_44 ( V_53 , V_64 , 0 , NULL ) ;
if ( V_2 -> V_164 )
F_44 ( V_53 , V_65 , 0 , NULL ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_16 ;
if ( F_4 ( V_165 , & V_2 -> V_73 ) )
return 0 ;
V_16 = F_39 ( V_2 , F_86 , 0 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static void F_88 ( struct V_52 * V_53 , unsigned long V_58 )
{
T_10 V_166 = V_58 ;
F_19 ( L_13 , V_53 -> V_2 -> V_29 , V_166 ) ;
F_44 ( V_53 , V_167 , 1 , & V_166 ) ;
}
static void F_89 ( struct V_52 * V_53 , unsigned long V_58 )
{
T_10 V_168 = V_58 ;
F_19 ( L_13 , V_53 -> V_2 -> V_29 , V_168 ) ;
F_44 ( V_53 , V_118 , 1 , & V_168 ) ;
}
static void F_90 ( struct V_52 * V_53 , unsigned long V_58 )
{
T_10 V_169 = V_58 ;
F_19 ( L_13 , V_53 -> V_2 -> V_29 , V_169 ) ;
F_44 ( V_53 , V_170 , 1 , & V_169 ) ;
}
static void F_91 ( struct V_52 * V_53 , unsigned long V_58 )
{
T_9 V_125 = F_49 ( V_58 ) ;
F_19 ( L_13 , V_53 -> V_2 -> V_29 , V_125 ) ;
F_44 ( V_53 , V_126 , 2 , & V_125 ) ;
}
struct V_1 * F_92 ( int V_171 )
{
struct V_1 * V_2 = NULL , * V_172 ;
F_19 ( L_14 , V_171 ) ;
if ( V_171 < 0 )
return NULL ;
F_93 ( & V_173 ) ;
F_94 (d, &hci_dev_list, list) {
if ( V_172 -> V_174 == V_171 ) {
V_2 = F_95 ( V_172 ) ;
break;
}
}
F_96 ( & V_173 ) ;
return V_2 ;
}
bool F_97 ( struct V_1 * V_2 )
{
struct V_175 * V_176 = & V_2 -> V_177 ;
switch ( V_176 -> V_178 ) {
case V_179 :
case V_180 :
return true ;
default:
return false ;
}
}
void F_98 ( struct V_1 * V_2 , int V_178 )
{
int V_181 = V_2 -> V_177 . V_178 ;
F_19 ( L_15 , V_2 -> V_29 , V_2 -> V_177 . V_178 , V_178 ) ;
if ( V_181 == V_178 )
return;
V_2 -> V_177 . V_178 = V_178 ;
switch ( V_178 ) {
case V_182 :
F_99 ( V_2 ) ;
if ( V_181 != V_183 )
F_100 ( V_2 , 0 ) ;
break;
case V_183 :
break;
case V_179 :
F_100 ( V_2 , 1 ) ;
break;
case V_180 :
break;
case V_184 :
break;
}
}
void F_101 ( struct V_1 * V_2 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_186 * V_133 , * V_187 ;
F_102 (p, n, &cache->all, all) {
F_103 ( & V_133 -> V_188 ) ;
F_104 ( V_133 ) ;
}
F_105 ( & V_185 -> V_189 ) ;
F_105 ( & V_185 -> V_190 ) ;
}
struct V_186 * F_106 ( struct V_1 * V_2 ,
T_11 * V_136 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_186 * V_191 ;
F_19 ( L_16 , V_185 , V_136 ) ;
F_94 (e, &cache->all, all) {
if ( ! F_107 ( & V_191 -> V_26 . V_136 , V_136 ) )
return V_191 ;
}
return NULL ;
}
struct V_186 * F_108 ( struct V_1 * V_2 ,
T_11 * V_136 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_186 * V_191 ;
F_19 ( L_16 , V_185 , V_136 ) ;
F_94 (e, &cache->unknown, list) {
if ( ! F_107 ( & V_191 -> V_26 . V_136 , V_136 ) )
return V_191 ;
}
return NULL ;
}
struct V_186 * F_109 ( struct V_1 * V_2 ,
T_11 * V_136 ,
int V_178 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_186 * V_191 ;
F_19 ( L_17 , V_185 , V_136 , V_178 ) ;
F_94 (e, &cache->resolve, list) {
if ( ! F_107 ( V_136 , V_137 ) && V_191 -> V_192 == V_178 )
return V_191 ;
if ( ! F_107 ( & V_191 -> V_26 . V_136 , V_136 ) )
return V_191 ;
}
return NULL ;
}
void F_110 ( struct V_1 * V_2 ,
struct V_186 * V_193 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_194 * V_195 = & V_185 -> V_190 ;
struct V_186 * V_133 ;
F_103 ( & V_193 -> V_196 ) ;
F_94 (p, &cache->resolve, list) {
if ( V_133 -> V_192 != V_197 &&
abs ( V_133 -> V_26 . V_198 ) >= abs ( V_193 -> V_26 . V_198 ) )
break;
V_195 = & V_133 -> V_196 ;
}
F_111 ( & V_193 -> V_196 , V_195 ) ;
}
T_7 F_112 ( struct V_1 * V_2 , struct V_199 * V_26 ,
bool V_200 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_186 * V_193 ;
T_7 V_18 = 0 ;
F_19 ( L_16 , V_185 , & V_26 -> V_136 ) ;
F_113 ( V_2 , & V_26 -> V_136 , V_201 ) ;
if ( ! V_26 -> V_202 )
V_18 |= V_203 ;
V_193 = F_106 ( V_2 , & V_26 -> V_136 ) ;
if ( V_193 ) {
if ( ! V_193 -> V_26 . V_202 )
V_18 |= V_203 ;
if ( V_193 -> V_192 == V_204 &&
V_26 -> V_198 != V_193 -> V_26 . V_198 ) {
V_193 -> V_26 . V_198 = V_26 -> V_198 ;
F_110 ( V_2 , V_193 ) ;
}
goto V_205;
}
V_193 = F_114 ( sizeof( * V_193 ) , V_206 ) ;
if ( ! V_193 ) {
V_18 |= V_207 ;
goto V_208;
}
F_111 ( & V_193 -> V_188 , & V_185 -> V_188 ) ;
if ( V_200 ) {
V_193 -> V_192 = V_209 ;
} else {
V_193 -> V_192 = V_210 ;
F_111 ( & V_193 -> V_196 , & V_185 -> V_189 ) ;
}
V_205:
if ( V_200 && V_193 -> V_192 != V_209 &&
V_193 -> V_192 != V_197 ) {
V_193 -> V_192 = V_209 ;
F_103 ( & V_193 -> V_196 ) ;
}
memcpy ( & V_193 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_193 -> V_211 = V_212 ;
V_185 -> V_211 = V_212 ;
if ( V_193 -> V_192 == V_210 )
V_18 |= V_207 ;
V_208:
return V_18 ;
}
static int F_115 ( struct V_1 * V_2 , int V_213 , T_10 * V_9 )
{
struct V_175 * V_185 = & V_2 -> V_177 ;
struct V_214 * V_215 = (struct V_214 * ) V_9 ;
struct V_186 * V_191 ;
int V_216 = 0 ;
F_94 (e, &cache->all, all) {
struct V_199 * V_26 = & V_191 -> V_26 ;
if ( V_216 >= V_213 )
break;
F_77 ( & V_215 -> V_136 , & V_26 -> V_136 ) ;
V_215 -> V_217 = V_26 -> V_217 ;
V_215 -> V_218 = V_26 -> V_218 ;
V_215 -> V_219 = V_26 -> V_219 ;
memcpy ( V_215 -> V_220 , V_26 -> V_220 , 3 ) ;
V_215 -> V_221 = V_26 -> V_221 ;
V_215 ++ ;
V_216 ++ ;
}
F_19 ( L_18 , V_185 , V_216 ) ;
return V_216 ;
}
static void F_116 ( struct V_52 * V_53 , unsigned long V_58 )
{
struct V_222 * V_223 = (struct V_222 * ) V_58 ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_224 V_108 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( F_4 ( V_225 , & V_2 -> V_18 ) )
return;
memcpy ( & V_108 . V_226 , & V_223 -> V_226 , 3 ) ;
V_108 . V_227 = V_223 -> V_227 ;
V_108 . V_228 = V_223 -> V_228 ;
F_44 ( V_53 , V_229 , sizeof( V_108 ) , & V_108 ) ;
}
int F_117 ( void T_2 * V_230 )
{
T_10 T_2 * V_231 = V_230 ;
struct V_222 V_223 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_232 = 0 , V_233 ;
long V_234 ;
T_10 * V_9 ;
if ( F_8 ( & V_223 , V_231 , sizeof( V_223 ) ) )
return - V_20 ;
V_2 = F_92 ( V_223 . V_235 ) ;
if ( ! V_2 )
return - V_236 ;
if ( F_4 ( V_237 , & V_2 -> V_93 ) ) {
V_16 = - V_238 ;
goto V_208;
}
if ( F_4 ( V_239 , & V_2 -> V_93 ) ) {
V_16 = - V_240 ;
goto V_208;
}
if ( V_2 -> V_74 != V_75 ) {
V_16 = - V_240 ;
goto V_208;
}
if ( ! F_4 ( V_100 , & V_2 -> V_93 ) ) {
V_16 = - V_240 ;
goto V_208;
}
F_23 ( V_2 ) ;
if ( F_118 ( V_2 ) > V_241 ||
F_119 ( V_2 ) || V_223 . V_18 & V_242 ) {
F_101 ( V_2 ) ;
V_232 = 1 ;
}
F_24 ( V_2 ) ;
V_234 = V_223 . V_227 * F_120 ( 2000 ) ;
if ( V_232 ) {
V_16 = F_41 ( V_2 , F_116 , ( unsigned long ) & V_223 ,
V_234 ) ;
if ( V_16 < 0 )
goto V_208;
if ( F_121 ( & V_2 -> V_18 , V_225 ,
V_54 ) )
return - V_56 ;
}
V_233 = ( V_223 . V_228 == 0 ) ? 255 : V_223 . V_228 ;
V_9 = F_122 ( sizeof( struct V_214 ) * V_233 , V_206 ) ;
if ( ! V_9 ) {
V_16 = - V_243 ;
goto V_208;
}
F_23 ( V_2 ) ;
V_223 . V_228 = F_115 ( V_2 , V_233 , V_9 ) ;
F_24 ( V_2 ) ;
F_19 ( L_19 , V_223 . V_228 ) ;
if ( ! F_123 ( V_231 , & V_223 , sizeof( V_223 ) ) ) {
V_231 += sizeof( V_223 ) ;
if ( F_123 ( V_231 , V_9 , sizeof( struct V_214 ) *
V_223 . V_228 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_104 ( V_9 ) ;
V_208:
F_124 ( V_2 ) ;
return V_16 ;
}
static int F_125 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
F_19 ( L_20 , V_2 -> V_29 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_244 , & V_2 -> V_93 ) ) {
V_59 = - V_236 ;
goto V_208;
}
if ( ! F_4 ( V_160 , & V_2 -> V_93 ) &&
! F_4 ( V_163 , & V_2 -> V_93 ) ) {
if ( F_4 ( V_245 , & V_2 -> V_93 ) ) {
V_59 = - V_246 ;
goto V_208;
}
if ( ! F_4 ( V_237 , & V_2 -> V_93 ) &&
V_2 -> V_74 == V_75 &&
! F_107 ( & V_2 -> V_136 , V_137 ) &&
! F_107 ( & V_2 -> V_247 , V_137 ) ) {
V_59 = - V_248 ;
goto V_208;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_59 = - V_22 ;
goto V_208;
}
if ( V_2 -> V_249 ( V_2 ) ) {
V_59 = - V_250 ;
goto V_208;
}
F_126 ( & V_2 -> V_251 , 1 ) ;
F_43 ( V_252 , & V_2 -> V_18 ) ;
if ( F_4 ( V_160 , & V_2 -> V_93 ) ) {
if ( V_2 -> V_253 )
V_59 = V_2 -> V_253 ( V_2 ) ;
if ( F_4 ( V_254 , & V_2 -> V_73 ) ||
F_4 ( V_255 , & V_2 -> V_73 ) )
F_43 ( V_239 , & V_2 -> V_93 ) ;
if ( F_4 ( V_239 , & V_2 -> V_93 ) )
V_59 = F_87 ( V_2 ) ;
}
if ( F_4 ( V_163 , & V_2 -> V_93 ) ) {
if ( F_107 ( & V_2 -> V_256 , V_137 ) &&
V_2 -> V_164 )
V_59 = V_2 -> V_164 ( V_2 , & V_2 -> V_256 ) ;
else
V_59 = - V_248 ;
}
if ( ! V_59 ) {
if ( ! F_4 ( V_239 , & V_2 -> V_93 ) &&
! F_4 ( V_237 , & V_2 -> V_93 ) )
V_59 = F_81 ( V_2 ) ;
}
F_62 ( V_252 , & V_2 -> V_18 ) ;
if ( ! V_59 ) {
F_95 ( V_2 ) ;
F_43 ( V_257 , & V_2 -> V_93 ) ;
F_43 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_258 ) ;
if ( ! F_4 ( V_160 , & V_2 -> V_93 ) &&
! F_4 ( V_163 , & V_2 -> V_93 ) &&
! F_4 ( V_239 , & V_2 -> V_93 ) &&
! F_4 ( V_237 , & V_2 -> V_93 ) &&
V_2 -> V_74 == V_75 ) {
F_23 ( V_2 ) ;
F_127 ( V_2 , 1 ) ;
F_24 ( V_2 ) ;
}
} else {
F_128 ( & V_2 -> V_259 ) ;
F_128 ( & V_2 -> V_260 ) ;
F_128 ( & V_2 -> V_261 ) ;
F_129 ( & V_2 -> V_262 ) ;
F_129 ( & V_2 -> V_263 ) ;
if ( V_2 -> V_264 )
V_2 -> V_264 ( V_2 ) ;
if ( V_2 -> V_265 ) {
F_16 ( V_2 -> V_265 ) ;
V_2 -> V_265 = NULL ;
}
V_2 -> V_266 ( V_2 ) ;
V_2 -> V_18 &= F_130 ( V_267 ) ;
}
V_208:
F_12 ( V_2 ) ;
return V_59 ;
}
int F_131 ( T_12 V_268 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_92 ( V_268 ) ;
if ( ! V_2 )
return - V_236 ;
if ( F_4 ( V_239 , & V_2 -> V_93 ) &&
! F_4 ( V_237 , & V_2 -> V_93 ) ) {
V_16 = - V_240 ;
goto V_208;
}
if ( F_132 ( V_269 , & V_2 -> V_93 ) )
F_133 ( & V_2 -> V_270 ) ;
F_134 ( V_2 -> V_271 ) ;
if ( ! F_4 ( V_237 , & V_2 -> V_93 ) &&
! F_4 ( V_272 , & V_2 -> V_93 ) )
F_43 ( V_273 , & V_2 -> V_93 ) ;
V_16 = F_125 ( V_2 ) ;
V_208:
F_124 ( V_2 ) ;
return V_16 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_274 * V_133 ;
F_94 (p, &hdev->le_conn_params, list) {
if ( V_133 -> V_275 ) {
F_136 ( V_133 -> V_275 ) ;
F_137 ( V_133 -> V_275 ) ;
V_133 -> V_275 = NULL ;
}
F_138 ( & V_133 -> V_276 ) ;
}
F_19 ( L_21 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
F_19 ( L_20 , V_2 -> V_29 , V_2 ) ;
F_133 ( & V_2 -> V_270 ) ;
F_21 ( V_2 , V_236 ) ;
F_10 ( V_2 ) ;
if ( ! F_132 ( V_17 , & V_2 -> V_18 ) ) {
F_140 ( & V_2 -> V_277 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_128 ( & V_2 -> V_259 ) ;
F_128 ( & V_2 -> V_261 ) ;
if ( V_2 -> V_278 > 0 ) {
F_133 ( & V_2 -> V_279 ) ;
V_2 -> V_278 = 0 ;
F_62 ( V_280 , & V_2 -> V_93 ) ;
F_62 ( V_281 , & V_2 -> V_93 ) ;
}
if ( F_132 ( V_282 , & V_2 -> V_93 ) )
F_133 ( & V_2 -> V_283 ) ;
F_140 ( & V_2 -> V_284 ) ;
F_140 ( & V_2 -> V_285 ) ;
if ( F_4 ( V_272 , & V_2 -> V_93 ) )
F_140 ( & V_2 -> V_286 ) ;
F_141 ( V_2 -> V_287 ) ;
F_23 ( V_2 ) ;
F_98 ( V_2 , V_182 ) ;
if ( ! F_132 ( V_269 , & V_2 -> V_93 ) ) {
if ( V_2 -> V_74 == V_75 )
F_127 ( V_2 , 0 ) ;
}
F_101 ( V_2 ) ;
F_135 ( V_2 ) ;
F_142 ( V_2 ) ;
F_24 ( V_2 ) ;
F_143 ( V_2 ) ;
F_1 ( V_2 , V_288 ) ;
if ( V_2 -> V_264 )
V_2 -> V_264 ( V_2 ) ;
F_129 ( & V_2 -> V_262 ) ;
F_126 ( & V_2 -> V_251 , 1 ) ;
if ( ! F_4 ( V_269 , & V_2 -> V_93 ) &&
! F_4 ( V_239 , & V_2 -> V_93 ) &&
F_4 ( V_72 , & V_2 -> V_73 ) ) {
F_43 ( V_252 , & V_2 -> V_18 ) ;
F_39 ( V_2 , F_42 , 0 , V_24 ) ;
F_62 ( V_252 , & V_2 -> V_18 ) ;
}
F_128 ( & V_2 -> V_260 ) ;
F_129 ( & V_2 -> V_263 ) ;
F_129 ( & V_2 -> V_262 ) ;
F_129 ( & V_2 -> V_289 ) ;
if ( V_2 -> V_265 ) {
F_140 ( & V_2 -> V_277 ) ;
F_16 ( V_2 -> V_265 ) ;
V_2 -> V_265 = NULL ;
}
F_16 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
V_2 -> V_266 ( V_2 ) ;
V_2 -> V_18 &= F_130 ( V_267 ) ;
V_2 -> V_93 &= ~ V_290 ;
V_2 -> V_291 = V_292 ;
memset ( V_2 -> V_109 , 0 , sizeof( V_2 -> V_109 ) ) ;
memset ( V_2 -> V_220 , 0 , sizeof( V_2 -> V_220 ) ) ;
F_77 ( & V_2 -> V_293 , V_137 ) ;
F_12 ( V_2 ) ;
F_124 ( V_2 ) ;
return 0 ;
}
int F_144 ( T_12 V_268 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_92 ( V_268 ) ;
if ( ! V_2 )
return - V_236 ;
if ( F_4 ( V_237 , & V_2 -> V_93 ) ) {
V_16 = - V_238 ;
goto V_208;
}
if ( F_132 ( V_269 , & V_2 -> V_93 ) )
F_133 ( & V_2 -> V_270 ) ;
V_16 = F_139 ( V_2 ) ;
V_208:
F_124 ( V_2 ) ;
return V_16 ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_59 ;
F_19 ( L_20 , V_2 -> V_29 , V_2 ) ;
F_10 ( V_2 ) ;
F_129 ( & V_2 -> V_263 ) ;
F_129 ( & V_2 -> V_262 ) ;
F_141 ( V_2 -> V_287 ) ;
F_23 ( V_2 ) ;
F_101 ( V_2 ) ;
F_142 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( V_2 -> V_264 )
V_2 -> V_264 ( V_2 ) ;
F_126 ( & V_2 -> V_251 , 1 ) ;
V_2 -> V_294 = 0 ; V_2 -> V_295 = 0 ; V_2 -> V_296 = 0 ;
V_59 = F_39 ( V_2 , F_42 , 0 , V_159 ) ;
F_12 ( V_2 ) ;
return V_59 ;
}
int F_146 ( T_12 V_268 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_92 ( V_268 ) ;
if ( ! V_2 )
return - V_236 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_16 = - V_19 ;
goto V_208;
}
if ( F_4 ( V_237 , & V_2 -> V_93 ) ) {
V_16 = - V_238 ;
goto V_208;
}
if ( F_4 ( V_239 , & V_2 -> V_93 ) ) {
V_16 = - V_240 ;
goto V_208;
}
V_16 = F_145 ( V_2 ) ;
V_208:
F_124 ( V_2 ) ;
return V_16 ;
}
int F_147 ( T_12 V_268 )
{
struct V_1 * V_2 ;
int V_59 = 0 ;
V_2 = F_92 ( V_268 ) ;
if ( ! V_2 )
return - V_236 ;
if ( F_4 ( V_237 , & V_2 -> V_93 ) ) {
V_59 = - V_238 ;
goto V_208;
}
if ( F_4 ( V_239 , & V_2 -> V_93 ) ) {
V_59 = - V_240 ;
goto V_208;
}
memset ( & V_2 -> V_297 , 0 , sizeof( struct V_298 ) ) ;
V_208:
F_124 ( V_2 ) ;
return V_59 ;
}
static void F_148 ( struct V_1 * V_2 , T_5 V_166 )
{
bool V_299 , V_300 ;
F_19 ( L_22 , V_2 -> V_29 , V_166 ) ;
if ( ( V_166 & V_301 ) )
V_299 = ! F_149 ( V_302 ,
& V_2 -> V_93 ) ;
else
V_299 = F_132 ( V_302 ,
& V_2 -> V_93 ) ;
if ( ( V_166 & V_303 ) ) {
V_300 = ! F_149 ( V_280 ,
& V_2 -> V_93 ) ;
} else {
F_62 ( V_281 , & V_2 -> V_93 ) ;
V_300 = F_132 ( V_280 ,
& V_2 -> V_93 ) ;
}
if ( ! F_4 ( V_272 , & V_2 -> V_93 ) )
return;
if ( V_299 || V_300 ) {
F_43 ( V_100 , & V_2 -> V_93 ) ;
if ( F_4 ( V_92 , & V_2 -> V_93 ) )
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
}
}
int F_152 ( unsigned int V_304 , void T_2 * V_230 )
{
struct V_1 * V_2 ;
struct V_305 V_306 ;
int V_16 = 0 ;
if ( F_8 ( & V_306 , V_230 , sizeof( V_306 ) ) )
return - V_20 ;
V_2 = F_92 ( V_306 . V_235 ) ;
if ( ! V_2 )
return - V_236 ;
if ( F_4 ( V_237 , & V_2 -> V_93 ) ) {
V_16 = - V_238 ;
goto V_208;
}
if ( F_4 ( V_239 , & V_2 -> V_93 ) ) {
V_16 = - V_240 ;
goto V_208;
}
if ( V_2 -> V_74 != V_75 ) {
V_16 = - V_240 ;
goto V_208;
}
if ( ! F_4 ( V_100 , & V_2 -> V_93 ) ) {
V_16 = - V_240 ;
goto V_208;
}
switch ( V_304 ) {
case V_307 :
V_16 = F_41 ( V_2 , F_89 , V_306 . V_308 ,
V_159 ) ;
break;
case V_309 :
if ( ! F_153 ( V_2 ) ) {
V_16 = - V_240 ;
break;
}
if ( ! F_4 ( V_310 , & V_2 -> V_18 ) ) {
V_16 = F_41 ( V_2 , F_89 , V_306 . V_308 ,
V_159 ) ;
if ( V_16 )
break;
}
V_16 = F_41 ( V_2 , F_90 , V_306 . V_308 ,
V_159 ) ;
break;
case V_311 :
V_16 = F_41 ( V_2 , F_88 , V_306 . V_308 ,
V_159 ) ;
if ( ! V_16 )
F_148 ( V_2 , V_306 . V_308 ) ;
break;
case V_312 :
V_16 = F_41 ( V_2 , F_91 , V_306 . V_308 ,
V_159 ) ;
break;
case V_313 :
V_2 -> V_314 = ( ( T_12 ) V_306 . V_308 ) &
( V_315 | V_316 ) ;
break;
case V_317 :
V_2 -> V_318 = ( T_12 ) V_306 . V_308 ;
break;
case V_319 :
V_2 -> V_320 = * ( ( T_12 * ) & V_306 . V_308 + 1 ) ;
V_2 -> V_321 = * ( ( T_12 * ) & V_306 . V_308 + 0 ) ;
break;
case V_322 :
V_2 -> V_323 = * ( ( T_12 * ) & V_306 . V_308 + 1 ) ;
V_2 -> V_324 = * ( ( T_12 * ) & V_306 . V_308 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_208:
F_124 ( V_2 ) ;
return V_16 ;
}
int F_154 ( void T_2 * V_230 )
{
struct V_1 * V_2 ;
struct V_325 * V_326 ;
struct V_305 * V_306 ;
int V_187 = 0 , V_327 , V_16 ;
T_12 V_328 ;
if ( F_155 ( V_328 , ( T_12 T_2 * ) V_230 ) )
return - V_20 ;
if ( ! V_328 || V_328 > ( V_329 * 2 ) / sizeof( * V_306 ) )
return - V_21 ;
V_327 = sizeof( * V_326 ) + V_328 * sizeof( * V_306 ) ;
V_326 = F_114 ( V_327 , V_206 ) ;
if ( ! V_326 )
return - V_243 ;
V_306 = V_326 -> V_330 ;
F_93 ( & V_173 ) ;
F_94 (hdev, &hci_dev_list, list) {
unsigned long V_18 = V_2 -> V_18 ;
if ( F_4 ( V_269 , & V_2 -> V_93 ) )
V_18 &= ~ F_130 ( V_17 ) ;
( V_306 + V_187 ) -> V_235 = V_2 -> V_174 ;
( V_306 + V_187 ) -> V_308 = V_18 ;
if ( ++ V_187 >= V_328 )
break;
}
F_96 ( & V_173 ) ;
V_326 -> V_328 = V_187 ;
V_327 = sizeof( * V_326 ) + V_187 * sizeof( * V_306 ) ;
V_16 = F_123 ( V_230 , V_326 , V_327 ) ;
F_104 ( V_326 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_156 ( void T_2 * V_230 )
{
struct V_1 * V_2 ;
struct V_331 V_332 ;
unsigned long V_18 ;
int V_16 = 0 ;
if ( F_8 ( & V_332 , V_230 , sizeof( V_332 ) ) )
return - V_20 ;
V_2 = F_92 ( V_332 . V_235 ) ;
if ( ! V_2 )
return - V_236 ;
if ( F_4 ( V_269 , & V_2 -> V_93 ) )
V_18 = V_2 -> V_18 & ~ F_130 ( V_17 ) ;
else
V_18 = V_2 -> V_18 ;
strcpy ( V_332 . V_29 , V_2 -> V_29 ) ;
V_332 . V_136 = V_2 -> V_136 ;
V_332 . type = ( V_2 -> V_333 & 0x0f ) | ( ( V_2 -> V_74 & 0x03 ) << 4 ) ;
V_332 . V_18 = V_18 ;
V_332 . V_318 = V_2 -> V_318 ;
if ( F_51 ( V_2 ) ) {
V_332 . V_320 = V_2 -> V_320 ;
V_332 . V_321 = V_2 -> V_321 ;
V_332 . V_323 = V_2 -> V_323 ;
V_332 . V_324 = V_2 -> V_324 ;
} else {
V_332 . V_320 = V_2 -> V_334 ;
V_332 . V_321 = V_2 -> V_335 ;
V_332 . V_323 = 0 ;
V_332 . V_324 = 0 ;
}
V_332 . V_120 = V_2 -> V_120 ;
V_332 . V_314 = V_2 -> V_314 ;
memcpy ( & V_332 . V_297 , & V_2 -> V_297 , sizeof( V_332 . V_297 ) ) ;
memcpy ( & V_332 . V_336 , & V_2 -> V_336 , sizeof( V_332 . V_336 ) ) ;
if ( F_123 ( V_230 , & V_332 , sizeof( V_332 ) ) )
V_16 = - V_20 ;
F_124 ( V_2 ) ;
return V_16 ;
}
static int F_157 ( void * V_26 , bool V_337 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( L_23 , V_2 , V_2 -> V_29 , V_337 ) ;
if ( F_4 ( V_237 , & V_2 -> V_93 ) )
return - V_238 ;
if ( V_337 ) {
F_43 ( V_245 , & V_2 -> V_93 ) ;
if ( ! F_4 ( V_160 , & V_2 -> V_93 ) &&
! F_4 ( V_163 , & V_2 -> V_93 ) )
F_139 ( V_2 ) ;
} else {
F_62 ( V_245 , & V_2 -> V_93 ) ;
}
return 0 ;
}
static void F_158 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 , V_340 ) ;
int V_16 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
V_16 = F_125 ( V_2 ) ;
if ( V_16 < 0 ) {
F_23 ( V_2 ) ;
F_160 ( V_2 , V_16 ) ;
F_24 ( V_2 ) ;
return;
}
if ( F_4 ( V_245 , & V_2 -> V_93 ) ||
F_4 ( V_239 , & V_2 -> V_93 ) ||
( V_2 -> V_74 == V_75 &&
! F_107 ( & V_2 -> V_136 , V_137 ) &&
! F_107 ( & V_2 -> V_247 , V_137 ) ) ) {
F_62 ( V_269 , & V_2 -> V_93 ) ;
F_139 ( V_2 ) ;
} else if ( F_4 ( V_269 , & V_2 -> V_93 ) ) {
F_161 ( V_2 -> V_271 , & V_2 -> V_270 ,
V_341 ) ;
}
if ( F_132 ( V_160 , & V_2 -> V_93 ) ) {
if ( F_4 ( V_239 , & V_2 -> V_93 ) )
F_43 ( V_267 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
} else if ( F_132 ( V_163 , & V_2 -> V_93 ) ) {
if ( ! F_4 ( V_239 , & V_2 -> V_93 ) )
F_62 ( V_267 , & V_2 -> V_18 ) ;
F_162 ( V_2 ) ;
}
}
static void F_163 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 ,
V_270 . V_339 ) ;
F_19 ( L_7 , V_2 -> V_29 ) ;
F_139 ( V_2 ) ;
}
static void F_164 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 , V_342 ) ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( V_2 -> V_343 )
V_2 -> V_343 ( V_2 , V_2 -> V_344 ) ;
else
F_26 ( L_24 , V_2 -> V_29 ,
V_2 -> V_344 ) ;
if ( F_139 ( V_2 ) )
return;
F_125 ( V_2 ) ;
}
static void F_165 ( struct V_338 * V_339 )
{
struct V_1 * V_2 ;
V_2 = F_159 ( V_339 , struct V_1 , V_279 . V_339 ) ;
F_19 ( L_7 , V_2 -> V_29 ) ;
F_166 ( V_2 ) ;
}
void F_167 ( struct V_1 * V_2 )
{
struct V_345 * V_346 , * V_347 ;
F_102 (uuid, tmp, &hdev->uuids, list) {
F_103 ( & V_346 -> V_196 ) ;
F_104 ( V_346 ) ;
}
}
void F_168 ( struct V_1 * V_2 )
{
struct V_348 * V_349 ;
F_169 (key, &hdev->link_keys, list) {
F_170 ( & V_349 -> V_196 ) ;
F_171 ( V_349 , V_350 ) ;
}
}
void F_172 ( struct V_1 * V_2 )
{
struct V_351 * V_352 ;
F_169 (k, &hdev->long_term_keys, list) {
F_170 ( & V_352 -> V_196 ) ;
F_171 ( V_352 , V_350 ) ;
}
}
void F_173 ( struct V_1 * V_2 )
{
struct V_353 * V_352 ;
F_169 (k, &hdev->identity_resolving_keys, list) {
F_170 ( & V_352 -> V_196 ) ;
F_171 ( V_352 , V_350 ) ;
}
}
struct V_348 * F_174 ( struct V_1 * V_2 , T_11 * V_136 )
{
struct V_348 * V_352 ;
F_175 () ;
F_169 (k, &hdev->link_keys, list) {
if ( F_107 ( V_136 , & V_352 -> V_136 ) == 0 ) {
F_176 () ;
return V_352 ;
}
}
F_176 () ;
return NULL ;
}
static bool F_177 ( struct V_1 * V_2 , struct V_354 * V_275 ,
T_5 V_355 , T_5 V_356 )
{
if ( V_355 < 0x03 )
return true ;
if ( V_355 == V_357 )
return false ;
if ( V_355 == V_358 && V_356 == 0xff )
return false ;
if ( ! V_275 )
return true ;
if ( V_275 -> type == V_359 )
return true ;
if ( V_275 -> V_360 > 0x01 && V_275 -> V_361 > 0x01 )
return true ;
if ( V_275 -> V_360 == 0x02 || V_275 -> V_360 == 0x03 )
return true ;
if ( V_275 -> V_361 == 0x02 || V_275 -> V_361 == 0x03 )
return true ;
return false ;
}
static T_5 F_178 ( T_5 type )
{
if ( type == V_362 )
return V_363 ;
return V_364 ;
}
struct V_351 * F_179 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 V_365 , T_5 V_366 )
{
struct V_351 * V_352 ;
F_175 () ;
F_169 (k, &hdev->long_term_keys, list) {
if ( V_365 != V_352 -> V_367 || F_107 ( V_136 , & V_352 -> V_136 ) )
continue;
if ( F_180 ( V_352 ) || F_178 ( V_352 -> type ) == V_366 ) {
F_176 () ;
return V_352 ;
}
}
F_176 () ;
return NULL ;
}
struct V_353 * F_181 ( struct V_1 * V_2 , T_11 * V_368 )
{
struct V_353 * V_369 ;
F_175 () ;
F_169 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_107 ( & V_369 -> V_368 , V_368 ) ) {
F_176 () ;
return V_369 ;
}
}
F_169 (irk, &hdev->identity_resolving_keys, list) {
if ( F_182 ( V_2 , V_369 -> V_370 , V_368 ) ) {
F_77 ( & V_369 -> V_368 , V_368 ) ;
F_176 () ;
return V_369 ;
}
}
F_176 () ;
return NULL ;
}
struct V_353 * F_183 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 V_365 )
{
struct V_353 * V_369 ;
if ( V_365 == V_371 && ( V_136 -> V_372 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_175 () ;
F_169 (irk, &hdev->identity_resolving_keys, list) {
if ( V_365 == V_369 -> V_365 &&
F_107 ( V_136 , & V_369 -> V_136 ) == 0 ) {
F_176 () ;
return V_369 ;
}
}
F_176 () ;
return NULL ;
}
struct V_348 * F_184 ( struct V_1 * V_2 , struct V_354 * V_275 ,
T_11 * V_136 , T_5 * V_370 , T_5 type ,
T_5 V_373 , bool * V_374 )
{
struct V_348 * V_349 , * V_375 ;
T_5 V_356 ;
V_375 = F_174 ( V_2 , V_136 ) ;
if ( V_375 ) {
V_356 = V_375 -> type ;
V_349 = V_375 ;
} else {
V_356 = V_275 ? V_275 -> V_355 : 0xff ;
V_349 = F_114 ( sizeof( * V_349 ) , V_206 ) ;
if ( ! V_349 )
return NULL ;
F_185 ( & V_349 -> V_196 , & V_2 -> V_376 ) ;
}
F_19 ( L_25 , V_2 -> V_29 , V_136 , type ) ;
if ( type == V_358 &&
( ! V_275 || V_275 -> V_361 == 0xff ) && V_356 == 0xff ) {
type = V_377 ;
if ( V_275 )
V_275 -> V_355 = type ;
}
F_77 ( & V_349 -> V_136 , V_136 ) ;
memcpy ( V_349 -> V_370 , V_370 , V_378 ) ;
V_349 -> V_373 = V_373 ;
if ( type == V_358 )
V_349 -> type = V_356 ;
else
V_349 -> type = type ;
if ( V_374 )
* V_374 = F_177 ( V_2 , V_275 , type ,
V_356 ) ;
return V_349 ;
}
struct V_351 * F_186 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 V_365 , T_5 type , T_5 V_379 ,
T_5 V_380 [ 16 ] , T_5 V_381 , T_9 V_382 , T_13 rand )
{
struct V_351 * V_349 , * V_375 ;
T_5 V_366 = F_178 ( type ) ;
V_375 = F_179 ( V_2 , V_136 , V_365 , V_366 ) ;
if ( V_375 )
V_349 = V_375 ;
else {
V_349 = F_114 ( sizeof( * V_349 ) , V_206 ) ;
if ( ! V_349 )
return NULL ;
F_185 ( & V_349 -> V_196 , & V_2 -> V_383 ) ;
}
F_77 ( & V_349 -> V_136 , V_136 ) ;
V_349 -> V_367 = V_365 ;
memcpy ( V_349 -> V_370 , V_380 , sizeof( V_349 -> V_370 ) ) ;
V_349 -> V_379 = V_379 ;
V_349 -> V_382 = V_382 ;
V_349 -> rand = rand ;
V_349 -> V_381 = V_381 ;
V_349 -> type = type ;
return V_349 ;
}
struct V_353 * F_187 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 V_365 , T_5 V_370 [ 16 ] , T_11 * V_368 )
{
struct V_353 * V_369 ;
V_369 = F_183 ( V_2 , V_136 , V_365 ) ;
if ( ! V_369 ) {
V_369 = F_114 ( sizeof( * V_369 ) , V_206 ) ;
if ( ! V_369 )
return NULL ;
F_77 ( & V_369 -> V_136 , V_136 ) ;
V_369 -> V_365 = V_365 ;
F_185 ( & V_369 -> V_196 , & V_2 -> V_384 ) ;
}
memcpy ( V_369 -> V_370 , V_370 , 16 ) ;
F_77 ( & V_369 -> V_368 , V_368 ) ;
return V_369 ;
}
int F_188 ( struct V_1 * V_2 , T_11 * V_136 )
{
struct V_348 * V_349 ;
V_349 = F_174 ( V_2 , V_136 ) ;
if ( ! V_349 )
return - V_385 ;
F_19 ( L_26 , V_2 -> V_29 , V_136 ) ;
F_170 ( & V_349 -> V_196 ) ;
F_171 ( V_349 , V_350 ) ;
return 0 ;
}
int F_189 ( struct V_1 * V_2 , T_11 * V_136 , T_5 V_367 )
{
struct V_351 * V_352 ;
int V_386 = 0 ;
F_169 (k, &hdev->long_term_keys, list) {
if ( F_107 ( V_136 , & V_352 -> V_136 ) || V_352 -> V_367 != V_367 )
continue;
F_19 ( L_26 , V_2 -> V_29 , V_136 ) ;
F_170 ( & V_352 -> V_196 ) ;
F_171 ( V_352 , V_350 ) ;
V_386 ++ ;
}
return V_386 ? 0 : - V_385 ;
}
void F_190 ( struct V_1 * V_2 , T_11 * V_136 , T_5 V_365 )
{
struct V_353 * V_352 ;
F_169 (k, &hdev->identity_resolving_keys, list) {
if ( F_107 ( V_136 , & V_352 -> V_136 ) || V_352 -> V_365 != V_365 )
continue;
F_19 ( L_26 , V_2 -> V_29 , V_136 ) ;
F_170 ( & V_352 -> V_196 ) ;
F_171 ( V_352 , V_350 ) ;
}
}
static void F_191 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 ,
V_277 . V_339 ) ;
if ( V_2 -> V_265 ) {
struct V_387 * V_388 = ( void * ) V_2 -> V_265 -> V_26 ;
T_6 V_28 = F_28 ( V_388 -> V_28 ) ;
F_26 ( L_27 , V_2 -> V_29 , V_28 ) ;
} else {
F_26 ( L_28 , V_2 -> V_29 ) ;
}
F_126 ( & V_2 -> V_251 , 1 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_260 ) ;
}
struct V_389 * F_193 ( struct V_1 * V_2 ,
T_11 * V_136 , T_5 V_367 )
{
struct V_389 * V_26 ;
F_94 (data, &hdev->remote_oob_data, list) {
if ( F_107 ( V_136 , & V_26 -> V_136 ) != 0 )
continue;
if ( V_26 -> V_367 != V_367 )
continue;
return V_26 ;
}
return NULL ;
}
int F_113 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 V_367 )
{
struct V_389 * V_26 ;
V_26 = F_193 ( V_2 , V_136 , V_367 ) ;
if ( ! V_26 )
return - V_385 ;
F_19 ( L_29 , V_2 -> V_29 , V_136 , V_367 ) ;
F_103 ( & V_26 -> V_196 ) ;
F_104 ( V_26 ) ;
return 0 ;
}
void F_194 ( struct V_1 * V_2 )
{
struct V_389 * V_26 , * V_187 ;
F_102 (data, n, &hdev->remote_oob_data, list) {
F_103 ( & V_26 -> V_196 ) ;
F_104 ( V_26 ) ;
}
}
int F_195 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 V_367 , T_5 * V_390 , T_5 * V_391 ,
T_5 * V_392 , T_5 * V_393 )
{
struct V_389 * V_26 ;
V_26 = F_193 ( V_2 , V_136 , V_367 ) ;
if ( ! V_26 ) {
V_26 = F_122 ( sizeof( * V_26 ) , V_206 ) ;
if ( ! V_26 )
return - V_243 ;
F_77 ( & V_26 -> V_136 , V_136 ) ;
V_26 -> V_367 = V_367 ;
F_111 ( & V_26 -> V_196 , & V_2 -> V_394 ) ;
}
if ( V_390 && V_391 ) {
memcpy ( V_26 -> V_390 , V_390 , sizeof( V_26 -> V_390 ) ) ;
memcpy ( V_26 -> V_391 , V_391 , sizeof( V_26 -> V_391 ) ) ;
if ( V_392 && V_393 )
V_26 -> V_395 = 0x03 ;
} else {
memset ( V_26 -> V_390 , 0 , sizeof( V_26 -> V_390 ) ) ;
memset ( V_26 -> V_391 , 0 , sizeof( V_26 -> V_391 ) ) ;
if ( V_392 && V_393 )
V_26 -> V_395 = 0x02 ;
else
V_26 -> V_395 = 0x00 ;
}
if ( V_392 && V_393 ) {
memcpy ( V_26 -> V_392 , V_392 , sizeof( V_26 -> V_392 ) ) ;
memcpy ( V_26 -> V_393 , V_393 , sizeof( V_26 -> V_393 ) ) ;
} else {
memset ( V_26 -> V_392 , 0 , sizeof( V_26 -> V_392 ) ) ;
memset ( V_26 -> V_393 , 0 , sizeof( V_26 -> V_393 ) ) ;
if ( V_390 && V_391 )
V_26 -> V_395 = 0x01 ;
}
F_19 ( L_30 , V_2 -> V_29 , V_136 ) ;
return 0 ;
}
struct V_396 * F_196 ( struct V_194 * V_396 ,
T_11 * V_136 , T_5 type )
{
struct V_396 * V_372 ;
F_94 (b, bdaddr_list, list) {
if ( ! F_107 ( & V_372 -> V_136 , V_136 ) && V_372 -> V_367 == type )
return V_372 ;
}
return NULL ;
}
void F_197 ( struct V_194 * V_396 )
{
struct V_194 * V_133 , * V_187 ;
F_198 (p, n, bdaddr_list) {
struct V_396 * V_372 = F_199 ( V_133 , struct V_396 , V_196 ) ;
F_103 ( V_133 ) ;
F_104 ( V_372 ) ;
}
}
int F_200 ( struct V_194 * V_196 , T_11 * V_136 , T_5 type )
{
struct V_396 * V_397 ;
if ( ! F_107 ( V_136 , V_137 ) )
return - V_398 ;
if ( F_196 ( V_196 , V_136 , type ) )
return - V_399 ;
V_397 = F_114 ( sizeof( * V_397 ) , V_206 ) ;
if ( ! V_397 )
return - V_243 ;
F_77 ( & V_397 -> V_136 , V_136 ) ;
V_397 -> V_367 = type ;
F_111 ( & V_397 -> V_196 , V_196 ) ;
return 0 ;
}
int F_201 ( struct V_194 * V_196 , T_11 * V_136 , T_5 type )
{
struct V_396 * V_397 ;
if ( ! F_107 ( V_136 , V_137 ) ) {
F_197 ( V_196 ) ;
return 0 ;
}
V_397 = F_196 ( V_196 , V_136 , type ) ;
if ( ! V_397 )
return - V_385 ;
F_103 ( & V_397 -> V_196 ) ;
F_104 ( V_397 ) ;
return 0 ;
}
struct V_274 * F_202 ( struct V_1 * V_2 ,
T_11 * V_400 , T_5 V_365 )
{
struct V_274 * V_401 ;
if ( ! F_203 ( V_400 , V_365 ) )
return NULL ;
F_94 (params, &hdev->le_conn_params, list) {
if ( F_107 ( & V_401 -> V_400 , V_400 ) == 0 &&
V_401 -> V_365 == V_365 ) {
return V_401 ;
}
}
return NULL ;
}
struct V_274 * F_204 ( struct V_194 * V_196 ,
T_11 * V_400 , T_5 V_365 )
{
struct V_274 * V_48 ;
if ( ! F_203 ( V_400 , V_365 ) )
return NULL ;
F_94 (param, list, action) {
if ( F_107 ( & V_48 -> V_400 , V_400 ) == 0 &&
V_48 -> V_365 == V_365 )
return V_48 ;
}
return NULL ;
}
struct V_274 * F_205 ( struct V_1 * V_2 ,
T_11 * V_400 , T_5 V_365 )
{
struct V_274 * V_401 ;
if ( ! F_203 ( V_400 , V_365 ) )
return NULL ;
V_401 = F_202 ( V_2 , V_400 , V_365 ) ;
if ( V_401 )
return V_401 ;
V_401 = F_114 ( sizeof( * V_401 ) , V_206 ) ;
if ( ! V_401 ) {
F_26 ( L_31 ) ;
return NULL ;
}
F_77 ( & V_401 -> V_400 , V_400 ) ;
V_401 -> V_365 = V_365 ;
F_111 ( & V_401 -> V_196 , & V_2 -> V_402 ) ;
F_105 ( & V_401 -> V_276 ) ;
V_401 -> V_403 = V_2 -> V_404 ;
V_401 -> V_405 = V_2 -> V_406 ;
V_401 -> V_407 = V_2 -> V_408 ;
V_401 -> V_409 = V_2 -> V_410 ;
V_401 -> V_411 = V_412 ;
F_19 ( L_32 , V_400 , V_365 ) ;
return V_401 ;
}
static void F_206 ( struct V_274 * V_401 )
{
if ( V_401 -> V_275 ) {
F_136 ( V_401 -> V_275 ) ;
F_137 ( V_401 -> V_275 ) ;
}
F_103 ( & V_401 -> V_276 ) ;
F_103 ( & V_401 -> V_196 ) ;
F_104 ( V_401 ) ;
}
void F_207 ( struct V_1 * V_2 , T_11 * V_400 , T_5 V_365 )
{
struct V_274 * V_401 ;
V_401 = F_202 ( V_2 , V_400 , V_365 ) ;
if ( ! V_401 )
return;
F_206 ( V_401 ) ;
F_99 ( V_2 ) ;
F_19 ( L_32 , V_400 , V_365 ) ;
}
void F_208 ( struct V_1 * V_2 )
{
struct V_274 * V_401 , * V_347 ;
F_102 (params, tmp, &hdev->le_conn_params, list) {
if ( V_401 -> V_411 != V_412 )
continue;
F_103 ( & V_401 -> V_196 ) ;
F_104 ( V_401 ) ;
}
F_19 ( L_33 ) ;
}
void F_209 ( struct V_1 * V_2 )
{
struct V_274 * V_401 , * V_347 ;
F_102 (params, tmp, &hdev->le_conn_params, list)
F_206 ( V_401 ) ;
F_99 ( V_2 ) ;
F_19 ( L_34 ) ;
}
static void F_210 ( struct V_1 * V_2 , T_5 V_413 , T_6 V_28 )
{
if ( V_413 ) {
F_26 ( L_35 , V_413 ) ;
F_23 ( V_2 ) ;
F_98 ( V_2 , V_182 ) ;
F_24 ( V_2 ) ;
return;
}
}
static void F_211 ( struct V_1 * V_2 , T_5 V_413 ,
T_6 V_28 )
{
T_5 V_226 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_52 V_53 ;
struct V_224 V_108 ;
int V_16 ;
if ( V_413 ) {
F_26 ( L_36 , V_413 ) ;
return;
}
V_2 -> V_177 . V_414 = 0 ;
switch ( V_2 -> V_177 . type ) {
case V_415 :
F_23 ( V_2 ) ;
F_98 ( V_2 , V_182 ) ;
F_24 ( V_2 ) ;
break;
case V_416 :
F_31 ( & V_53 , V_2 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
memcpy ( & V_108 . V_226 , V_226 , sizeof( V_108 . V_226 ) ) ;
V_108 . V_227 = V_417 ;
F_44 ( & V_53 , V_229 , sizeof( V_108 ) , & V_108 ) ;
F_23 ( V_2 ) ;
F_101 ( V_2 ) ;
V_16 = F_35 ( & V_53 , F_210 ) ;
if ( V_16 ) {
F_26 ( L_37 , V_16 ) ;
F_98 ( V_2 , V_182 ) ;
}
F_24 ( V_2 ) ;
break;
}
}
static void F_212 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 ,
V_284 . V_339 ) ;
struct V_52 V_53 ;
int V_16 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
F_140 ( & V_2 -> V_285 ) ;
F_31 ( & V_53 , V_2 ) ;
F_213 ( & V_53 ) ;
V_16 = F_35 ( & V_53 , F_211 ) ;
if ( V_16 )
F_26 ( L_38 , V_16 ) ;
}
static void F_214 ( struct V_1 * V_2 , T_5 V_413 ,
T_6 V_28 )
{
unsigned long V_49 , V_418 , V_414 , V_419 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( V_413 ) {
F_26 ( L_39 , V_413 ) ;
return;
}
if ( ! F_4 ( V_420 , & V_2 -> V_73 ) ||
! V_2 -> V_177 . V_414 )
return;
V_418 = V_2 -> V_177 . V_421 ;
V_414 = V_2 -> V_177 . V_414 ;
V_419 = V_212 ;
if ( V_419 - V_414 <= V_418 ) {
int V_422 ;
if ( V_419 >= V_414 )
V_422 = V_419 - V_414 ;
else
V_422 = V_423 - V_414 + V_419 ;
V_49 = V_418 - V_422 ;
} else {
V_49 = 0 ;
}
F_161 ( V_2 -> V_287 ,
& V_2 -> V_284 , V_49 ) ;
}
static void F_215 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 ,
V_285 . V_339 ) ;
struct V_52 V_53 ;
struct V_424 V_108 ;
int V_16 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( ! F_4 ( V_425 , & V_2 -> V_93 ) )
return;
F_31 ( & V_53 , V_2 ) ;
F_213 ( & V_53 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_15 = V_426 ;
V_108 . V_427 = V_428 ;
F_44 ( & V_53 , V_429 , sizeof( V_108 ) , & V_108 ) ;
V_16 = F_35 ( & V_53 , F_214 ) ;
if ( V_16 )
F_26 ( L_40 , V_16 ) ;
}
void F_216 ( struct V_1 * V_2 , T_11 * V_136 ,
T_5 * V_367 )
{
if ( F_4 ( V_430 , & V_2 -> V_11 ) ||
! F_107 ( & V_2 -> V_136 , V_137 ) ||
( ! F_4 ( V_100 , & V_2 -> V_93 ) &&
F_107 ( & V_2 -> V_247 , V_137 ) ) ) {
F_77 ( V_136 , & V_2 -> V_247 ) ;
* V_367 = V_371 ;
} else {
F_77 ( V_136 , & V_2 -> V_136 ) ;
* V_367 = V_431 ;
}
}
struct V_1 * F_217 ( void )
{
struct V_1 * V_2 ;
V_2 = F_114 ( sizeof( * V_2 ) , V_206 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_318 = ( V_432 | V_433 | V_434 ) ;
V_2 -> V_435 = ( V_436 ) ;
V_2 -> V_314 = ( V_316 ) ;
V_2 -> V_437 = 0x01 ;
V_2 -> V_438 = 0x03 ;
V_2 -> V_439 = 0xffff ;
V_2 -> V_440 = V_441 ;
V_2 -> V_442 = V_441 ;
V_2 -> V_443 = 800 ;
V_2 -> V_444 = 80 ;
V_2 -> V_445 = 0x07 ;
V_2 -> V_446 = 0x0800 ;
V_2 -> V_447 = 0x0800 ;
V_2 -> V_448 = 0x0060 ;
V_2 -> V_449 = 0x0030 ;
V_2 -> V_404 = 0x0028 ;
V_2 -> V_406 = 0x0038 ;
V_2 -> V_408 = 0x0000 ;
V_2 -> V_410 = 0x002a ;
V_2 -> V_450 = 0x001b ;
V_2 -> V_451 = 0x0148 ;
V_2 -> V_452 = 0x001b ;
V_2 -> V_453 = 0x0148 ;
V_2 -> V_454 = 0x001b ;
V_2 -> V_455 = 0x0148 ;
V_2 -> V_456 = V_457 ;
V_2 -> V_458 = V_459 ;
V_2 -> V_460 = V_461 ;
V_2 -> V_462 = V_463 ;
F_218 ( & V_2 -> V_464 ) ;
F_218 ( & V_2 -> V_465 ) ;
F_105 ( & V_2 -> V_466 ) ;
F_105 ( & V_2 -> V_467 ) ;
F_105 ( & V_2 -> V_468 ) ;
F_105 ( & V_2 -> V_469 ) ;
F_105 ( & V_2 -> V_376 ) ;
F_105 ( & V_2 -> V_383 ) ;
F_105 ( & V_2 -> V_384 ) ;
F_105 ( & V_2 -> V_394 ) ;
F_105 ( & V_2 -> V_470 ) ;
F_105 ( & V_2 -> V_402 ) ;
F_105 ( & V_2 -> V_471 ) ;
F_105 ( & V_2 -> V_472 ) ;
F_105 ( & V_2 -> V_473 . V_196 ) ;
F_219 ( & V_2 -> V_261 , V_474 ) ;
F_219 ( & V_2 -> V_260 , V_475 ) ;
F_219 ( & V_2 -> V_259 , V_476 ) ;
F_219 ( & V_2 -> V_340 , F_158 ) ;
F_219 ( & V_2 -> V_342 , F_164 ) ;
F_220 ( & V_2 -> V_270 , F_163 ) ;
F_220 ( & V_2 -> V_279 , F_165 ) ;
F_220 ( & V_2 -> V_284 , F_212 ) ;
F_220 ( & V_2 -> V_285 , F_215 ) ;
F_221 ( & V_2 -> V_263 ) ;
F_221 ( & V_2 -> V_262 ) ;
F_221 ( & V_2 -> V_289 ) ;
F_222 ( & V_2 -> V_34 ) ;
F_220 ( & V_2 -> V_277 , F_191 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
return V_2 ;
}
void F_225 ( struct V_1 * V_2 )
{
F_226 ( & V_2 -> V_268 ) ;
}
int F_227 ( struct V_1 * V_2 )
{
int V_174 , error ;
if ( ! V_2 -> V_249 || ! V_2 -> V_266 || ! V_2 -> V_477 )
return - V_21 ;
switch ( V_2 -> V_74 ) {
case V_75 :
V_174 = F_228 ( & V_478 , 0 , 0 , V_206 ) ;
break;
case V_76 :
V_174 = F_228 ( & V_478 , 1 , 0 , V_206 ) ;
break;
default:
return - V_21 ;
}
if ( V_174 < 0 )
return V_174 ;
sprintf ( V_2 -> V_29 , L_41 , V_174 ) ;
V_2 -> V_174 = V_174 ;
F_19 ( L_42 , V_2 , V_2 -> V_29 , V_2 -> V_333 ) ;
V_2 -> V_287 = F_229 ( L_7 , V_479 | V_480 |
V_481 , 1 , V_2 -> V_29 ) ;
if ( ! V_2 -> V_287 ) {
error = - V_243 ;
goto V_16;
}
V_2 -> V_271 = F_229 ( L_7 , V_479 | V_480 |
V_481 , 1 , V_2 -> V_29 ) ;
if ( ! V_2 -> V_271 ) {
F_230 ( V_2 -> V_287 ) ;
error = - V_243 ;
goto V_16;
}
if ( ! F_231 ( V_482 ) )
V_2 -> V_161 = F_232 ( V_2 -> V_29 , V_482 ) ;
F_233 ( & V_2 -> V_268 , L_7 , V_2 -> V_29 ) ;
error = F_234 ( & V_2 -> V_268 ) ;
if ( error < 0 )
goto V_483;
V_2 -> V_484 = F_235 ( V_2 -> V_29 , & V_2 -> V_268 ,
V_485 , & V_486 ,
V_2 ) ;
if ( V_2 -> V_484 ) {
if ( F_236 ( V_2 -> V_484 ) < 0 ) {
F_237 ( V_2 -> V_484 ) ;
V_2 -> V_484 = NULL ;
}
}
if ( V_2 -> V_484 && F_238 ( V_2 -> V_484 ) )
F_43 ( V_245 , & V_2 -> V_93 ) ;
F_43 ( V_160 , & V_2 -> V_93 ) ;
F_43 ( V_269 , & V_2 -> V_93 ) ;
if ( V_2 -> V_74 == V_75 ) {
F_43 ( V_100 , & V_2 -> V_93 ) ;
}
F_239 ( & V_173 ) ;
F_111 ( & V_2 -> V_196 , & V_487 ) ;
F_240 ( & V_173 ) ;
if ( F_4 ( V_165 , & V_2 -> V_73 ) )
F_43 ( V_239 , & V_2 -> V_93 ) ;
F_1 ( V_2 , V_488 ) ;
F_95 ( V_2 ) ;
F_192 ( V_2 -> V_271 , & V_2 -> V_340 ) ;
return V_174 ;
V_483:
F_230 ( V_2 -> V_287 ) ;
F_230 ( V_2 -> V_271 ) ;
V_16:
F_241 ( & V_478 , V_2 -> V_174 ) ;
return error ;
}
void F_242 ( struct V_1 * V_2 )
{
int V_489 , V_174 ;
F_19 ( L_42 , V_2 , V_2 -> V_29 , V_2 -> V_333 ) ;
F_43 ( V_244 , & V_2 -> V_93 ) ;
V_174 = V_2 -> V_174 ;
F_239 ( & V_173 ) ;
F_103 ( & V_2 -> V_196 ) ;
F_240 ( & V_173 ) ;
F_139 ( V_2 ) ;
for ( V_489 = 0 ; V_489 < V_490 ; V_489 ++ )
F_16 ( V_2 -> V_491 [ V_489 ] ) ;
F_243 ( & V_2 -> V_340 ) ;
if ( ! F_4 ( V_252 , & V_2 -> V_18 ) &&
! F_4 ( V_160 , & V_2 -> V_93 ) &&
! F_4 ( V_163 , & V_2 -> V_93 ) ) {
F_23 ( V_2 ) ;
F_244 ( V_2 ) ;
F_24 ( V_2 ) ;
}
F_245 ( ! F_246 ( & V_2 -> V_466 ) ) ;
F_1 ( V_2 , V_492 ) ;
if ( V_2 -> V_484 ) {
F_247 ( V_2 -> V_484 ) ;
F_237 ( V_2 -> V_484 ) ;
}
F_248 ( & V_2 -> V_268 ) ;
F_249 ( V_2 -> V_161 ) ;
F_230 ( V_2 -> V_287 ) ;
F_230 ( V_2 -> V_271 ) ;
F_23 ( V_2 ) ;
F_197 ( & V_2 -> V_467 ) ;
F_197 ( & V_2 -> V_468 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_194 ( V_2 ) ;
F_197 ( & V_2 -> V_470 ) ;
F_209 ( V_2 ) ;
F_250 ( V_2 ) ;
F_24 ( V_2 ) ;
F_124 ( V_2 ) ;
F_241 ( & V_478 , V_174 ) ;
}
int F_251 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_493 ) ;
return 0 ;
}
int F_252 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_494 ) ;
return 0 ;
}
int F_253 ( struct V_1 * V_2 )
{
const T_5 V_495 [] = { V_496 , 0x01 , 0x00 } ;
struct V_12 * V_13 ;
V_13 = F_254 ( 3 , V_497 ) ;
if ( ! V_13 )
return - V_243 ;
F_255 ( V_13 ) -> V_318 = V_498 ;
memcpy ( F_256 ( V_13 , 3 ) , V_495 , 3 ) ;
return F_257 ( V_2 , V_13 ) ;
}
int F_257 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_252 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_499 ;
}
F_255 ( V_13 ) -> V_500 = 1 ;
F_258 ( V_13 ) ;
F_259 ( & V_2 -> V_263 , V_13 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_261 ) ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_10 V_171 )
{
int V_42 = 0 ;
int V_501 = 0 ;
int V_502 = V_6 ;
struct V_12 * V_13 ;
struct V_503 * V_504 ;
if ( ( type < V_505 || type > V_498 ) ||
V_171 >= V_490 )
return - V_506 ;
V_13 = V_2 -> V_491 [ V_171 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_505 :
V_42 = V_507 ;
V_501 = V_508 ;
break;
case V_498 :
V_42 = V_509 ;
V_501 = V_44 ;
break;
case V_510 :
V_42 = V_511 ;
V_501 = V_512 ;
break;
}
V_13 = F_254 ( V_42 , V_497 ) ;
if ( ! V_13 )
return - V_243 ;
V_504 = ( void * ) V_13 -> V_513 ;
V_504 -> V_514 = V_501 ;
V_504 -> V_318 = type ;
V_2 -> V_491 [ V_171 ] = V_13 ;
}
while ( V_6 ) {
V_504 = ( void * ) V_13 -> V_513 ;
V_42 = F_261 ( V_515 , V_504 -> V_514 , V_6 ) ;
memcpy ( F_256 ( V_13 , V_42 ) , V_26 , V_42 ) ;
V_6 -= V_42 ;
V_26 += V_42 ;
V_504 -> V_514 -= V_42 ;
V_502 = V_6 ;
switch ( type ) {
case V_498 :
if ( V_13 -> V_42 == V_44 ) {
struct V_38 * V_516 = V_38 ( V_13 ) ;
V_504 -> V_514 = V_516 -> V_47 ;
if ( F_262 ( V_13 ) < V_504 -> V_514 ) {
F_16 ( V_13 ) ;
V_2 -> V_491 [ V_171 ] = NULL ;
return - V_243 ;
}
}
break;
case V_505 :
if ( V_13 -> V_42 == V_508 ) {
struct V_517 * V_516 = V_517 ( V_13 ) ;
V_504 -> V_514 = F_28 ( V_516 -> V_518 ) ;
if ( F_262 ( V_13 ) < V_504 -> V_514 ) {
F_16 ( V_13 ) ;
V_2 -> V_491 [ V_171 ] = NULL ;
return - V_243 ;
}
}
break;
case V_510 :
if ( V_13 -> V_42 == V_512 ) {
struct V_519 * V_516 = V_519 ( V_13 ) ;
V_504 -> V_514 = V_516 -> V_518 ;
if ( F_262 ( V_13 ) < V_504 -> V_514 ) {
F_16 ( V_13 ) ;
V_2 -> V_491 [ V_171 ] = NULL ;
return - V_243 ;
}
}
break;
}
if ( V_504 -> V_514 == 0 ) {
F_255 ( V_13 ) -> V_318 = type ;
F_257 ( V_2 , V_13 ) ;
V_2 -> V_491 [ V_171 ] = NULL ;
return V_502 ;
}
}
return V_502 ;
}
int F_263 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_520 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_491 [ V_521 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_522 ;
V_522 = V_26 ;
type = V_522 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_255 ( V_13 ) -> V_318 ;
V_520 = F_260 ( V_2 , type , V_26 , V_6 ,
V_521 ) ;
if ( V_520 < 0 )
return V_520 ;
V_26 += ( V_6 - V_520 ) ;
V_6 = V_520 ;
}
return V_520 ;
}
int F_264 ( struct V_523 * V_513 )
{
F_19 ( L_43 , V_513 , V_513 -> V_29 ) ;
F_239 ( & V_524 ) ;
F_111 ( & V_513 -> V_196 , & V_525 ) ;
F_240 ( & V_524 ) ;
return 0 ;
}
int F_265 ( struct V_523 * V_513 )
{
F_19 ( L_43 , V_513 , V_513 -> V_29 ) ;
F_239 ( & V_524 ) ;
F_103 ( & V_513 -> V_196 ) ;
F_240 ( & V_524 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_16 ;
F_19 ( L_44 , V_2 -> V_29 , F_255 ( V_13 ) -> V_318 , V_13 -> V_42 ) ;
F_258 ( V_13 ) ;
F_267 ( V_2 , V_13 ) ;
if ( F_268 ( & V_2 -> V_526 ) ) {
F_269 ( V_2 , V_13 ) ;
}
F_270 ( V_13 ) ;
V_16 = V_2 -> V_477 ( V_2 , V_13 ) ;
if ( V_16 < 0 ) {
F_26 ( L_45 , V_2 -> V_29 , V_16 ) ;
F_16 ( V_13 ) ;
}
}
bool F_271 ( struct V_1 * V_2 )
{
return ( V_2 -> V_30 == V_31 ) ;
}
int F_272 ( struct V_1 * V_2 , T_12 V_28 , T_8 V_47 ,
const void * V_48 )
{
struct V_12 * V_13 ;
F_19 ( L_46 , V_2 -> V_29 , V_28 , V_47 ) ;
V_13 = F_273 ( V_2 , V_28 , V_47 , V_48 ) ;
if ( ! V_13 ) {
F_26 ( L_47 , V_2 -> V_29 ) ;
return - V_243 ;
}
F_255 ( V_13 ) -> V_53 . V_527 = true ;
F_259 ( & V_2 -> V_262 , V_13 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_260 ) ;
return 0 ;
}
void * F_274 ( struct V_1 * V_2 , T_12 V_28 )
{
struct V_387 * V_39 ;
if ( ! V_2 -> V_265 )
return NULL ;
V_39 = ( void * ) V_2 -> V_265 -> V_26 ;
if ( V_39 -> V_28 != F_49 ( V_28 ) )
return NULL ;
F_19 ( L_48 , V_2 -> V_29 , V_28 ) ;
return V_2 -> V_265 -> V_26 + V_528 ;
}
static void F_275 ( struct V_12 * V_13 , T_12 V_529 , T_12 V_18 )
{
struct V_517 * V_39 ;
int V_42 = V_13 -> V_42 ;
F_276 ( V_13 , V_508 ) ;
F_277 ( V_13 ) ;
V_39 = (struct V_517 * ) F_278 ( V_13 ) ;
V_39 -> V_529 = F_49 ( F_279 ( V_529 , V_18 ) ) ;
V_39 -> V_518 = F_49 ( V_42 ) ;
}
static void F_280 ( struct V_530 * V_531 , struct V_532 * V_533 ,
struct V_12 * V_13 , T_12 V_18 )
{
struct V_354 * V_275 = V_531 -> V_275 ;
struct V_1 * V_2 = V_275 -> V_2 ;
struct V_12 * V_196 ;
V_13 -> V_42 = F_281 ( V_13 ) ;
V_13 -> V_534 = 0 ;
F_255 ( V_13 ) -> V_318 = V_505 ;
switch ( V_2 -> V_74 ) {
case V_75 :
F_275 ( V_13 , V_275 -> V_529 , V_18 ) ;
break;
case V_76 :
F_275 ( V_13 , V_531 -> V_529 , V_18 ) ;
break;
default:
F_26 ( L_49 , V_2 -> V_29 , V_2 -> V_74 ) ;
return;
}
V_196 = F_282 ( V_13 ) -> V_535 ;
if ( ! V_196 ) {
F_19 ( L_50 , V_2 -> V_29 , V_13 , V_13 -> V_42 ) ;
F_259 ( V_533 , V_13 ) ;
} else {
F_19 ( L_51 , V_2 -> V_29 , V_13 , V_13 -> V_42 ) ;
F_282 ( V_13 ) -> V_535 = NULL ;
F_283 ( & V_533 -> V_464 ) ;
F_284 ( V_533 , V_13 ) ;
V_18 &= ~ V_536 ;
V_18 |= V_537 ;
do {
V_13 = V_196 ; V_196 = V_196 -> V_538 ;
F_255 ( V_13 ) -> V_318 = V_505 ;
F_275 ( V_13 , V_275 -> V_529 , V_18 ) ;
F_19 ( L_51 , V_2 -> V_29 , V_13 , V_13 -> V_42 ) ;
F_284 ( V_533 , V_13 ) ;
} while ( V_196 );
F_285 ( & V_533 -> V_464 ) ;
}
}
void F_286 ( struct V_530 * V_531 , struct V_12 * V_13 , T_12 V_18 )
{
struct V_1 * V_2 = V_531 -> V_275 -> V_2 ;
F_19 ( L_52 , V_2 -> V_29 , V_531 , V_18 ) ;
F_280 ( V_531 , & V_531 -> V_539 , V_13 , V_18 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_259 ) ;
}
void F_287 ( struct V_354 * V_275 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_275 -> V_2 ;
struct V_519 V_39 ;
F_19 ( L_53 , V_2 -> V_29 , V_13 -> V_42 ) ;
V_39 . V_529 = F_49 ( V_275 -> V_529 ) ;
V_39 . V_518 = V_13 -> V_42 ;
F_276 ( V_13 , V_512 ) ;
F_277 ( V_13 ) ;
memcpy ( F_278 ( V_13 ) , & V_39 , V_512 ) ;
F_255 ( V_13 ) -> V_318 = V_510 ;
F_259 ( & V_275 -> V_539 , V_13 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_259 ) ;
}
static struct V_354 * F_288 ( struct V_1 * V_2 , T_10 type ,
int * V_540 )
{
struct V_541 * V_516 = & V_2 -> V_473 ;
struct V_354 * V_275 = NULL , * V_542 ;
unsigned int V_213 = 0 , F_7 = ~ 0 ;
F_175 () ;
F_169 (c, &h->list, list) {
if ( V_542 -> type != type || F_289 ( & V_542 -> V_539 ) )
continue;
if ( V_542 -> V_178 != V_543 && V_542 -> V_178 != V_544 )
continue;
V_213 ++ ;
if ( V_542 -> V_388 < F_7 ) {
F_7 = V_542 -> V_388 ;
V_275 = V_542 ;
}
if ( F_290 ( V_2 , type ) == V_213 )
break;
}
F_176 () ;
if ( V_275 ) {
int V_545 , V_546 ;
switch ( V_275 -> type ) {
case V_547 :
V_545 = V_2 -> V_294 ;
break;
case V_548 :
case V_549 :
V_545 = V_2 -> V_295 ;
break;
case V_359 :
V_545 = V_2 -> V_334 ? V_2 -> V_296 : V_2 -> V_294 ;
break;
default:
V_545 = 0 ;
F_26 ( L_54 ) ;
}
V_546 = V_545 / V_213 ;
* V_540 = V_546 ? V_546 : 1 ;
} else
* V_540 = 0 ;
F_19 ( L_55 , V_275 , * V_540 ) ;
return V_275 ;
}
static void F_291 ( struct V_1 * V_2 , T_10 type )
{
struct V_541 * V_516 = & V_2 -> V_473 ;
struct V_354 * V_542 ;
F_26 ( L_56 , V_2 -> V_29 ) ;
F_175 () ;
F_169 (c, &h->list, list) {
if ( V_542 -> type == type && V_542 -> V_388 ) {
F_26 ( L_57 ,
V_2 -> V_29 , & V_542 -> V_550 ) ;
F_292 ( V_542 , V_551 ) ;
}
}
F_176 () ;
}
static struct V_530 * F_293 ( struct V_1 * V_2 , T_10 type ,
int * V_540 )
{
struct V_541 * V_516 = & V_2 -> V_473 ;
struct V_530 * V_531 = NULL ;
unsigned int V_213 = 0 , F_7 = ~ 0 , V_552 = 0 ;
struct V_354 * V_275 ;
int V_545 , V_546 , V_553 = 0 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
F_175 () ;
F_169 (conn, &h->list, list) {
struct V_530 * V_347 ;
if ( V_275 -> type != type )
continue;
if ( V_275 -> V_178 != V_543 && V_275 -> V_178 != V_544 )
continue;
V_553 ++ ;
F_169 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_289 ( & V_347 -> V_539 ) )
continue;
V_13 = F_294 ( & V_347 -> V_539 ) ;
if ( V_13 -> V_554 < V_552 )
continue;
if ( V_13 -> V_554 > V_552 ) {
V_213 = 0 ;
F_7 = ~ 0 ;
V_552 = V_13 -> V_554 ;
}
V_213 ++ ;
if ( V_275 -> V_388 < F_7 ) {
F_7 = V_275 -> V_388 ;
V_531 = V_347 ;
}
}
if ( F_290 ( V_2 , type ) == V_553 )
break;
}
F_176 () ;
if ( ! V_531 )
return NULL ;
switch ( V_531 -> V_275 -> type ) {
case V_547 :
V_545 = V_2 -> V_294 ;
break;
case V_555 :
V_545 = V_2 -> V_556 ;
break;
case V_548 :
case V_549 :
V_545 = V_2 -> V_295 ;
break;
case V_359 :
V_545 = V_2 -> V_334 ? V_2 -> V_296 : V_2 -> V_294 ;
break;
default:
V_545 = 0 ;
F_26 ( L_54 ) ;
}
V_546 = V_545 / V_213 ;
* V_540 = V_546 ? V_546 : 1 ;
F_19 ( L_58 , V_531 , * V_540 ) ;
return V_531 ;
}
static void F_295 ( struct V_1 * V_2 , T_10 type )
{
struct V_541 * V_516 = & V_2 -> V_473 ;
struct V_354 * V_275 ;
int V_213 = 0 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
F_175 () ;
F_169 (conn, &h->list, list) {
struct V_530 * V_531 ;
if ( V_275 -> type != type )
continue;
if ( V_275 -> V_178 != V_543 && V_275 -> V_178 != V_544 )
continue;
V_213 ++ ;
F_169 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_531 -> V_388 ) {
V_531 -> V_388 = 0 ;
continue;
}
if ( F_289 ( & V_531 -> V_539 ) )
continue;
V_13 = F_294 ( & V_531 -> V_539 ) ;
if ( V_13 -> V_554 >= V_557 - 1 )
continue;
V_13 -> V_554 = V_557 - 1 ;
F_19 ( L_59 , V_531 , V_13 ,
V_13 -> V_554 ) ;
}
if ( F_290 ( V_2 , type ) == V_213 )
break;
}
F_176 () ;
}
static inline int F_296 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_297 ( V_13 -> V_42 - V_508 , V_2 -> V_558 ) ;
}
static void F_298 ( struct V_1 * V_2 , unsigned int V_545 )
{
if ( ! F_4 ( V_239 , & V_2 -> V_93 ) ) {
if ( ! V_545 && F_299 ( V_212 , V_2 -> V_559 +
V_560 ) )
F_291 ( V_2 , V_547 ) ;
}
}
static void F_300 ( struct V_1 * V_2 )
{
unsigned int V_545 = V_2 -> V_294 ;
struct V_530 * V_531 ;
struct V_12 * V_13 ;
int V_540 ;
F_298 ( V_2 , V_545 ) ;
while ( V_2 -> V_294 &&
( V_531 = F_293 ( V_2 , V_547 , & V_540 ) ) ) {
T_7 V_554 = ( F_294 ( & V_531 -> V_539 ) ) -> V_554 ;
while ( V_540 -- && ( V_13 = F_294 ( & V_531 -> V_539 ) ) ) {
F_19 ( L_60 , V_531 , V_13 ,
V_13 -> V_42 , V_13 -> V_554 ) ;
if ( V_13 -> V_554 < V_554 )
break;
V_13 = F_301 ( & V_531 -> V_539 ) ;
F_302 ( V_531 -> V_275 ,
F_255 ( V_13 ) -> V_561 ) ;
F_266 ( V_2 , V_13 ) ;
V_2 -> V_559 = V_212 ;
V_2 -> V_294 -- ;
V_531 -> V_388 ++ ;
V_531 -> V_275 -> V_388 ++ ;
}
}
if ( V_545 != V_2 -> V_294 )
F_295 ( V_2 , V_547 ) ;
}
static void F_303 ( struct V_1 * V_2 )
{
unsigned int V_545 = V_2 -> V_556 ;
struct V_530 * V_531 ;
struct V_12 * V_13 ;
int V_540 ;
T_5 type ;
F_298 ( V_2 , V_545 ) ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( V_2 -> V_74 == V_76 )
type = V_555 ;
else
type = V_547 ;
while ( V_2 -> V_556 > 0 &&
( V_531 = F_293 ( V_2 , type , & V_540 ) ) ) {
T_7 V_554 = ( F_294 ( & V_531 -> V_539 ) ) -> V_554 ;
while ( V_540 > 0 && ( V_13 = F_294 ( & V_531 -> V_539 ) ) ) {
int V_562 ;
F_19 ( L_60 , V_531 , V_13 ,
V_13 -> V_42 , V_13 -> V_554 ) ;
if ( V_13 -> V_554 < V_554 )
break;
V_13 = F_301 ( & V_531 -> V_539 ) ;
V_562 = F_296 ( V_2 , V_13 ) ;
if ( V_562 > V_2 -> V_556 )
return;
F_302 ( V_531 -> V_275 ,
F_255 ( V_13 ) -> V_561 ) ;
F_266 ( V_2 , V_13 ) ;
V_2 -> V_559 = V_212 ;
V_2 -> V_556 -= V_562 ;
V_540 -= V_562 ;
V_531 -> V_388 += V_562 ;
V_531 -> V_275 -> V_388 += V_562 ;
}
}
if ( V_545 != V_2 -> V_556 )
F_295 ( V_2 , type ) ;
}
static void F_304 ( struct V_1 * V_2 )
{
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( ! F_290 ( V_2 , V_547 ) && V_2 -> V_74 == V_75 )
return;
if ( ! F_290 ( V_2 , V_555 ) && V_2 -> V_74 == V_76 )
return;
switch ( V_2 -> V_61 ) {
case V_62 :
F_300 ( V_2 ) ;
break;
case V_66 :
F_303 ( V_2 ) ;
break;
}
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_354 * V_275 ;
struct V_12 * V_13 ;
int V_540 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( ! F_290 ( V_2 , V_548 ) )
return;
while ( V_2 -> V_295 && ( V_275 = F_288 ( V_2 , V_548 , & V_540 ) ) ) {
while ( V_540 -- && ( V_13 = F_301 ( & V_275 -> V_539 ) ) ) {
F_19 ( L_61 , V_13 , V_13 -> V_42 ) ;
F_266 ( V_2 , V_13 ) ;
V_275 -> V_388 ++ ;
if ( V_275 -> V_388 == ~ 0 )
V_275 -> V_388 = 0 ;
}
}
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_354 * V_275 ;
struct V_12 * V_13 ;
int V_540 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( ! F_290 ( V_2 , V_549 ) )
return;
while ( V_2 -> V_295 && ( V_275 = F_288 ( V_2 , V_549 ,
& V_540 ) ) ) {
while ( V_540 -- && ( V_13 = F_301 ( & V_275 -> V_539 ) ) ) {
F_19 ( L_61 , V_13 , V_13 -> V_42 ) ;
F_266 ( V_2 , V_13 ) ;
V_275 -> V_388 ++ ;
if ( V_275 -> V_388 == ~ 0 )
V_275 -> V_388 = 0 ;
}
}
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_530 * V_531 ;
struct V_12 * V_13 ;
int V_540 , V_545 , V_347 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
if ( ! F_290 ( V_2 , V_359 ) )
return;
if ( ! F_4 ( V_239 , & V_2 -> V_93 ) ) {
if ( ! V_2 -> V_296 && V_2 -> V_335 &&
F_299 ( V_212 , V_2 -> V_563 + V_564 * 45 ) )
F_291 ( V_2 , V_359 ) ;
}
V_545 = V_2 -> V_335 ? V_2 -> V_296 : V_2 -> V_294 ;
V_347 = V_545 ;
while ( V_545 && ( V_531 = F_293 ( V_2 , V_359 , & V_540 ) ) ) {
T_7 V_554 = ( F_294 ( & V_531 -> V_539 ) ) -> V_554 ;
while ( V_540 -- && ( V_13 = F_294 ( & V_531 -> V_539 ) ) ) {
F_19 ( L_60 , V_531 , V_13 ,
V_13 -> V_42 , V_13 -> V_554 ) ;
if ( V_13 -> V_554 < V_554 )
break;
V_13 = F_301 ( & V_531 -> V_539 ) ;
F_266 ( V_2 , V_13 ) ;
V_2 -> V_563 = V_212 ;
V_545 -- ;
V_531 -> V_388 ++ ;
V_531 -> V_275 -> V_388 ++ ;
}
}
if ( V_2 -> V_335 )
V_2 -> V_296 = V_545 ;
else
V_2 -> V_294 = V_545 ;
if ( V_545 != V_347 )
F_295 ( V_2 , V_359 ) ;
}
static void V_476 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 , V_259 ) ;
struct V_12 * V_13 ;
F_19 ( L_62 , V_2 -> V_29 , V_2 -> V_294 ,
V_2 -> V_295 , V_2 -> V_296 ) ;
if ( ! F_4 ( V_237 , & V_2 -> V_93 ) ) {
F_304 ( V_2 ) ;
F_305 ( V_2 ) ;
F_306 ( V_2 ) ;
F_307 ( V_2 ) ;
}
while ( ( V_13 = F_301 ( & V_2 -> V_289 ) ) )
F_266 ( V_2 , V_13 ) ;
}
static void F_308 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_517 * V_39 = ( void * ) V_13 -> V_26 ;
struct V_354 * V_275 ;
T_12 V_529 , V_18 ;
F_27 ( V_13 , V_508 ) ;
V_529 = F_28 ( V_39 -> V_529 ) ;
V_18 = F_309 ( V_529 ) ;
V_529 = F_310 ( V_529 ) ;
F_19 ( L_63 , V_2 -> V_29 , V_13 -> V_42 ,
V_529 , V_18 ) ;
V_2 -> V_297 . V_565 ++ ;
F_23 ( V_2 ) ;
V_275 = F_311 ( V_2 , V_529 ) ;
F_24 ( V_2 ) ;
if ( V_275 ) {
F_302 ( V_275 , V_566 ) ;
F_312 ( V_275 , V_13 , V_18 ) ;
return;
} else {
F_26 ( L_64 ,
V_2 -> V_29 , V_529 ) ;
}
F_16 ( V_13 ) ;
}
static void F_313 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_519 * V_39 = ( void * ) V_13 -> V_26 ;
struct V_354 * V_275 ;
T_12 V_529 ;
F_27 ( V_13 , V_512 ) ;
V_529 = F_28 ( V_39 -> V_529 ) ;
F_19 ( L_65 , V_2 -> V_29 , V_13 -> V_42 , V_529 ) ;
V_2 -> V_297 . V_567 ++ ;
F_23 ( V_2 ) ;
V_275 = F_311 ( V_2 , V_529 ) ;
F_24 ( V_2 ) ;
if ( V_275 ) {
F_314 ( V_275 , V_13 ) ;
return;
} else {
F_26 ( L_66 ,
V_2 -> V_29 , V_529 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_315 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_294 ( & V_2 -> V_262 ) ;
if ( ! V_13 )
return true ;
return F_255 ( V_13 ) -> V_53 . V_527 ;
}
static void F_316 ( struct V_1 * V_2 )
{
struct V_387 * V_388 ;
struct V_12 * V_13 ;
T_6 V_28 ;
if ( ! V_2 -> V_265 )
return;
V_388 = ( void * ) V_2 -> V_265 -> V_26 ;
V_28 = F_28 ( V_388 -> V_28 ) ;
if ( V_28 == V_25 )
return;
V_13 = F_317 ( V_2 -> V_265 , V_206 ) ;
if ( ! V_13 )
return;
F_318 ( & V_2 -> V_262 , V_13 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_260 ) ;
}
void F_319 ( struct V_1 * V_2 , T_6 V_28 , T_5 V_413 )
{
T_14 V_568 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_19 ( L_67 , V_28 , V_413 ) ;
if ( ! F_274 ( V_2 , V_28 ) ) {
if ( F_4 ( V_252 , & V_2 -> V_18 ) && V_28 == V_25 )
F_316 ( V_2 ) ;
return;
}
if ( ! V_413 && ! F_315 ( V_2 ) )
return;
if ( V_2 -> V_265 ) {
V_568 = F_255 ( V_2 -> V_265 ) -> V_53 . V_569 ;
if ( V_568 ) {
F_255 ( V_2 -> V_265 ) -> V_53 . V_569 = NULL ;
goto V_570;
}
}
F_320 ( & V_2 -> V_262 . V_464 , V_18 ) ;
while ( ( V_13 = F_321 ( & V_2 -> V_262 ) ) ) {
if ( F_255 ( V_13 ) -> V_53 . V_527 ) {
F_322 ( & V_2 -> V_262 , V_13 ) ;
break;
}
V_568 = F_255 ( V_13 ) -> V_53 . V_569 ;
F_16 ( V_13 ) ;
}
F_323 ( & V_2 -> V_262 . V_464 , V_18 ) ;
V_570:
if ( V_568 )
V_568 ( V_2 , V_413 , V_413 ? V_28 : V_571 ) ;
}
static void V_474 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 , V_261 ) ;
struct V_12 * V_13 ;
F_19 ( L_7 , V_2 -> V_29 ) ;
while ( ( V_13 = F_301 ( & V_2 -> V_263 ) ) ) {
F_267 ( V_2 , V_13 ) ;
if ( F_268 ( & V_2 -> V_526 ) ) {
F_269 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_237 , & V_2 -> V_93 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_252 , & V_2 -> V_18 ) ) {
switch ( F_255 ( V_13 ) -> V_318 ) {
case V_505 :
case V_510 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_255 ( V_13 ) -> V_318 ) {
case V_498 :
F_19 ( L_68 , V_2 -> V_29 ) ;
F_324 ( V_2 , V_13 ) ;
break;
case V_505 :
F_19 ( L_69 , V_2 -> V_29 ) ;
F_308 ( V_2 , V_13 ) ;
break;
case V_510 :
F_19 ( L_70 , V_2 -> V_29 ) ;
F_313 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_475 ( struct V_338 * V_339 )
{
struct V_1 * V_2 = F_159 ( V_339 , struct V_1 , V_260 ) ;
struct V_12 * V_13 ;
F_19 ( L_71 , V_2 -> V_29 ,
F_268 ( & V_2 -> V_251 ) , F_325 ( & V_2 -> V_262 ) ) ;
if ( F_268 ( & V_2 -> V_251 ) ) {
V_13 = F_301 ( & V_2 -> V_262 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_265 ) ;
V_2 -> V_265 = F_317 ( V_13 , V_206 ) ;
if ( V_2 -> V_265 ) {
F_326 ( & V_2 -> V_251 ) ;
F_266 ( V_2 , V_13 ) ;
if ( F_4 ( V_60 , & V_2 -> V_18 ) )
F_133 ( & V_2 -> V_277 ) ;
else
F_327 ( & V_2 -> V_277 ,
V_24 ) ;
} else {
F_318 ( & V_2 -> V_262 , V_13 ) ;
F_192 ( V_2 -> V_287 , & V_2 -> V_260 ) ;
}
}
}
