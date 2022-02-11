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
static void F_22 ( struct V_5 * V_6 , T_5 V_33 , T_6 V_34 ,
struct V_10 * V_11 )
{
F_23 ( L_3 , V_6 -> V_35 , V_33 ) ;
if ( V_6 -> V_36 == V_37 ) {
V_6 -> V_38 = V_33 ;
V_6 -> V_36 = V_39 ;
if ( V_11 )
V_6 -> V_40 = F_24 ( V_11 ) ;
F_25 ( & V_6 -> V_41 ) ;
}
}
static void F_26 ( struct V_5 * V_6 , int V_24 )
{
F_23 ( L_4 , V_6 -> V_35 , V_24 ) ;
if ( V_6 -> V_36 == V_37 ) {
V_6 -> V_38 = V_24 ;
V_6 -> V_36 = V_42 ;
F_25 ( & V_6 -> V_41 ) ;
}
}
struct V_10 * F_27 ( struct V_5 * V_6 , T_6 V_34 , T_7 V_43 ,
const void * V_44 , T_5 V_45 , T_7 V_46 )
{
F_28 ( V_47 , V_48 ) ;
struct V_49 V_50 ;
struct V_10 * V_11 ;
int V_24 = 0 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_29 ( & V_50 , V_6 ) ;
F_30 ( & V_50 , V_34 , V_43 , V_44 , V_45 ) ;
V_6 -> V_36 = V_37 ;
F_31 ( & V_6 -> V_41 , & V_47 ) ;
F_32 ( V_51 ) ;
V_24 = F_33 ( & V_50 , F_22 ) ;
if ( V_24 < 0 ) {
F_34 ( & V_6 -> V_41 , & V_47 ) ;
F_32 ( V_52 ) ;
return F_35 ( V_24 ) ;
}
F_36 ( V_46 ) ;
F_34 ( & V_6 -> V_41 , & V_47 ) ;
if ( F_37 ( V_48 ) )
return F_35 ( - V_53 ) ;
switch ( V_6 -> V_36 ) {
case V_39 :
V_24 = - F_38 ( V_6 -> V_38 ) ;
break;
case V_42 :
V_24 = - V_6 -> V_38 ;
break;
default:
V_24 = - V_54 ;
break;
}
V_6 -> V_36 = V_6 -> V_38 = 0 ;
V_11 = V_6 -> V_40 ;
V_6 -> V_40 = NULL ;
F_23 ( L_6 , V_6 -> V_35 , V_24 ) ;
if ( V_24 < 0 ) {
F_14 ( V_11 ) ;
return F_35 ( V_24 ) ;
}
if ( ! V_11 )
return F_35 ( - V_55 ) ;
return V_11 ;
}
struct V_10 * F_10 ( struct V_5 * V_6 , T_6 V_34 , T_7 V_43 ,
const void * V_44 , T_7 V_46 )
{
return F_27 ( V_6 , V_34 , V_43 , V_44 , 0 , V_46 ) ;
}
static int F_39 ( struct V_5 * V_6 ,
void (* F_40)( struct V_49 * V_50 ,
unsigned long V_56 ) ,
unsigned long V_56 , T_8 V_46 )
{
struct V_49 V_50 ;
F_28 ( V_47 , V_48 ) ;
int V_24 = 0 ;
F_23 ( L_7 , V_6 -> V_35 ) ;
F_29 ( & V_50 , V_6 ) ;
V_6 -> V_36 = V_37 ;
F_40 ( & V_50 , V_56 ) ;
F_31 ( & V_6 -> V_41 , & V_47 ) ;
F_32 ( V_51 ) ;
V_24 = F_33 ( & V_50 , F_22 ) ;
if ( V_24 < 0 ) {
V_6 -> V_36 = 0 ;
F_34 ( & V_6 -> V_41 , & V_47 ) ;
F_32 ( V_52 ) ;
if ( V_24 == - V_55 )
return 0 ;
return V_24 ;
}
F_36 ( V_46 ) ;
F_34 ( & V_6 -> V_41 , & V_47 ) ;
if ( F_37 ( V_48 ) )
return - V_53 ;
switch ( V_6 -> V_36 ) {
case V_39 :
V_24 = - F_38 ( V_6 -> V_38 ) ;
break;
case V_42 :
V_24 = - V_6 -> V_38 ;
break;
default:
V_24 = - V_54 ;
break;
}
V_6 -> V_36 = V_6 -> V_38 = 0 ;
F_23 ( L_6 , V_6 -> V_35 , V_24 ) ;
return V_24 ;
}
static int F_41 ( struct V_5 * V_6 ,
void (* V_50)( struct V_49 * V_50 ,
unsigned long V_56 ) ,
unsigned long V_56 , T_8 V_46 )
{
int V_57 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) )
return - V_16 ;
F_9 ( V_6 ) ;
V_57 = F_39 ( V_6 , V_50 , V_56 , V_46 ) ;
F_11 ( V_6 ) ;
return V_57 ;
}
static void F_42 ( struct V_49 * V_50 , unsigned long V_56 )
{
F_23 ( L_8 , V_50 -> V_6 -> V_35 , V_56 ) ;
F_43 ( V_58 , & V_50 -> V_6 -> V_15 ) ;
F_44 ( V_50 , V_22 , 0 , NULL ) ;
}
static void F_45 ( struct V_49 * V_50 )
{
V_50 -> V_6 -> V_59 = V_60 ;
F_44 ( V_50 , V_61 , 0 , NULL ) ;
F_44 ( V_50 , V_62 , 0 , NULL ) ;
F_44 ( V_50 , V_63 , 0 , NULL ) ;
}
static void F_46 ( struct V_49 * V_50 )
{
V_50 -> V_6 -> V_59 = V_64 ;
F_44 ( V_50 , V_62 , 0 , NULL ) ;
F_44 ( V_50 , V_65 , 0 , NULL ) ;
F_44 ( V_50 , V_66 , 0 , NULL ) ;
F_44 ( V_50 , V_67 , 0 , NULL ) ;
F_44 ( V_50 , V_68 , 0 , NULL ) ;
F_44 ( V_50 , V_69 , 0 , NULL ) ;
}
static void F_47 ( struct V_49 * V_50 )
{
if ( V_50 -> V_6 -> V_70 [ 14 ] & 0x20 )
F_44 ( V_50 , V_61 , 0 , NULL ) ;
}
static void F_48 ( struct V_49 * V_50 , unsigned long V_56 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
F_23 ( L_8 , V_6 -> V_35 , V_56 ) ;
if ( ! F_6 ( V_71 , & V_6 -> V_26 ) )
F_42 ( V_50 , 0 ) ;
switch ( V_6 -> V_72 ) {
case V_73 :
F_45 ( V_50 ) ;
break;
case V_74 :
F_46 ( V_50 ) ;
break;
default:
F_49 ( L_9 , V_6 -> V_72 ) ;
break;
}
}
static void F_50 ( struct V_49 * V_50 )
{
T_9 V_44 ;
T_10 V_75 ;
F_44 ( V_50 , V_76 , 0 , NULL ) ;
F_44 ( V_50 , V_77 , 0 , NULL ) ;
F_44 ( V_50 , V_78 , 0 , NULL ) ;
F_44 ( V_50 , V_79 , 0 , NULL ) ;
F_44 ( V_50 , V_80 , 0 , NULL ) ;
F_44 ( V_50 , V_81 , 0 , NULL ) ;
V_75 = V_82 ;
F_44 ( V_50 , V_83 , 1 , & V_75 ) ;
V_44 = F_51 ( 0x7d00 ) ;
F_44 ( V_50 , V_84 , 2 , & V_44 ) ;
}
static void F_52 ( struct V_49 * V_50 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
F_44 ( V_50 , V_85 , 0 , NULL ) ;
F_44 ( V_50 , V_86 , 0 , NULL ) ;
F_44 ( V_50 , V_87 , 0 , NULL ) ;
if ( ! F_53 ( V_6 ) )
F_18 ( V_6 , V_88 ) ;
}
static void F_54 ( struct V_49 * V_50 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
T_5 V_89 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_6 -> V_90 < V_91 )
return;
if ( F_53 ( V_6 ) ) {
V_89 [ 4 ] |= 0x01 ;
V_89 [ 4 ] |= 0x02 ;
V_89 [ 4 ] |= 0x04 ;
V_89 [ 5 ] |= 0x08 ;
V_89 [ 5 ] |= 0x10 ;
} else {
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
V_89 [ 0 ] |= 0x10 ;
V_89 [ 1 ] |= 0x08 ;
V_89 [ 1 ] |= 0x20 ;
V_89 [ 1 ] |= 0x40 ;
V_89 [ 1 ] |= 0x80 ;
V_89 [ 2 ] |= 0x04 ;
V_89 [ 3 ] |= 0x02 ;
if ( V_6 -> V_92 [ 0 ] & V_93 ) {
V_89 [ 0 ] |= 0x80 ;
V_89 [ 5 ] |= 0x80 ;
}
}
if ( F_55 ( V_6 ) )
V_89 [ 4 ] |= 0x02 ;
if ( F_56 ( V_6 ) )
V_89 [ 5 ] |= 0x20 ;
if ( F_57 ( V_6 ) )
V_89 [ 5 ] |= 0x80 ;
if ( F_58 ( V_6 ) )
V_89 [ 5 ] |= 0x40 ;
if ( F_59 ( V_6 ) )
V_89 [ 7 ] |= 0x01 ;
if ( F_60 ( V_6 ) )
V_89 [ 6 ] |= 0x80 ;
if ( F_61 ( V_6 ) ) {
V_89 [ 6 ] |= 0x01 ;
V_89 [ 6 ] |= 0x02 ;
V_89 [ 6 ] |= 0x04 ;
V_89 [ 6 ] |= 0x08 ;
V_89 [ 6 ] |= 0x10 ;
V_89 [ 6 ] |= 0x20 ;
V_89 [ 7 ] |= 0x04 ;
V_89 [ 7 ] |= 0x08 ;
V_89 [ 7 ] |= 0x10 ;
}
if ( F_62 ( V_6 ) )
V_89 [ 7 ] |= 0x20 ;
F_44 ( V_50 , V_94 , sizeof( V_89 ) , V_89 ) ;
}
static void F_63 ( struct V_49 * V_50 , unsigned long V_56 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
if ( V_6 -> V_72 == V_74 )
return F_47 ( V_50 ) ;
if ( F_53 ( V_6 ) )
F_50 ( V_50 ) ;
else
F_19 ( V_6 , V_95 ) ;
if ( F_62 ( V_6 ) )
F_52 ( V_50 ) ;
if ( V_6 -> V_90 > V_96 &&
! F_6 ( V_97 , & V_6 -> V_26 ) )
F_44 ( V_50 , V_65 , 0 , NULL ) ;
if ( F_61 ( V_6 ) ) {
V_6 -> V_98 = 0x01 ;
if ( F_2 ( V_6 , V_99 ) ) {
T_5 V_100 = 0x01 ;
F_44 ( V_50 , V_101 ,
sizeof( V_100 ) , & V_100 ) ;
} else {
struct V_102 V_103 ;
memset ( V_6 -> V_104 , 0 , sizeof( V_6 -> V_104 ) ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
F_44 ( V_50 , V_105 , sizeof( V_103 ) , & V_103 ) ;
}
}
if ( F_55 ( V_6 ) ||
F_6 ( V_106 , & V_6 -> V_26 ) ) {
T_5 V_100 ;
V_100 = F_58 ( V_6 ) ? 0x02 : 0x01 ;
F_44 ( V_50 , V_107 , 1 , & V_100 ) ;
}
if ( F_64 ( V_6 ) )
F_44 ( V_50 , V_108 , 0 , NULL ) ;
if ( F_65 ( V_6 ) ) {
struct V_109 V_103 ;
V_103 . V_110 = 0x01 ;
F_44 ( V_50 , V_111 ,
sizeof( V_103 ) , & V_103 ) ;
}
if ( F_2 ( V_6 , V_112 ) ) {
T_5 V_13 = 1 ;
F_44 ( V_50 , V_113 , sizeof( V_13 ) ,
& V_13 ) ;
}
}
static void F_66 ( struct V_49 * V_50 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
struct V_114 V_103 ;
T_6 V_115 = 0 ;
if ( F_67 ( V_6 ) )
V_115 |= V_116 ;
if ( F_68 ( V_6 ) )
V_115 |= V_117 ;
if ( F_69 ( V_6 ) )
V_115 |= V_118 ;
if ( F_70 ( V_6 ) )
V_115 |= V_119 ;
V_103 . V_120 = F_51 ( V_115 ) ;
F_44 ( V_50 , V_121 , sizeof( V_103 ) , & V_103 ) ;
}
static void F_71 ( struct V_49 * V_50 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
struct V_122 V_103 ;
if ( ! F_53 ( V_6 ) )
return;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
if ( F_2 ( V_6 , V_88 ) ) {
V_103 . V_123 = 0x01 ;
V_103 . V_124 = 0x00 ;
}
if ( V_103 . V_123 != F_72 ( V_6 ) )
F_44 ( V_50 , V_125 , sizeof( V_103 ) ,
& V_103 ) ;
}
static void F_73 ( struct V_49 * V_50 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
T_5 V_89 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_74 ( V_6 ) ) {
V_89 [ 1 ] |= 0x40 ;
V_89 [ 1 ] |= 0x80 ;
V_89 [ 2 ] |= 0x10 ;
V_89 [ 2 ] |= 0x20 ;
}
if ( F_75 ( V_6 ) ) {
V_89 [ 2 ] |= 0x01 ;
V_89 [ 2 ] |= 0x02 ;
V_89 [ 2 ] |= 0x04 ;
V_89 [ 2 ] |= 0x08 ;
}
if ( F_76 ( V_6 ) || V_6 -> V_92 [ 0 ] & V_126 )
V_89 [ 2 ] |= 0x80 ;
F_44 ( V_50 , V_127 , sizeof( V_89 ) , V_89 ) ;
}
static void F_77 ( struct V_49 * V_50 , unsigned long V_56 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
T_5 V_128 ;
F_54 ( V_50 ) ;
if ( V_6 -> V_70 [ 6 ] & 0x20 &&
! F_6 ( V_129 , & V_6 -> V_26 ) ) {
struct V_130 V_103 ;
F_78 ( & V_103 . V_131 , V_132 ) ;
V_103 . V_133 = 0x01 ;
F_44 ( V_50 , V_134 , sizeof( V_103 ) , & V_103 ) ;
}
if ( V_6 -> V_70 [ 5 ] & 0x10 )
F_66 ( V_50 ) ;
if ( V_6 -> V_70 [ 8 ] & 0x01 )
F_44 ( V_50 , V_135 , 0 , NULL ) ;
if ( V_6 -> V_70 [ 13 ] & 0x01 )
F_44 ( V_50 , V_136 , 0 , NULL ) ;
if ( F_62 ( V_6 ) ) {
T_5 V_89 [ 8 ] ;
memset ( V_89 , 0 , sizeof( V_89 ) ) ;
V_89 [ 0 ] = 0x0f ;
if ( V_6 -> V_92 [ 0 ] & V_93 )
V_89 [ 0 ] |= 0x10 ;
if ( V_6 -> V_92 [ 0 ] & V_137 )
V_89 [ 0 ] |= 0x20 ;
if ( V_6 -> V_92 [ 0 ] & V_138 )
V_89 [ 0 ] |= 0x40 ;
if ( V_6 -> V_92 [ 0 ] & V_139 )
V_89 [ 1 ] |= 0x04 ;
if ( V_6 -> V_70 [ 34 ] & 0x02 )
V_89 [ 0 ] |= 0x80 ;
if ( V_6 -> V_70 [ 34 ] & 0x04 )
V_89 [ 1 ] |= 0x01 ;
F_44 ( V_50 , V_140 , sizeof( V_89 ) ,
V_89 ) ;
if ( V_6 -> V_70 [ 25 ] & 0x40 ) {
F_44 ( V_50 , V_141 , 0 , NULL ) ;
}
if ( V_6 -> V_70 [ 26 ] & 0x40 ) {
F_44 ( V_50 , V_142 ,
0 , NULL ) ;
}
if ( V_6 -> V_70 [ 26 ] & 0x80 ) {
F_44 ( V_50 , V_143 , 0 , NULL ) ;
}
if ( V_6 -> V_92 [ 0 ] & V_138 ) {
F_44 ( V_50 , V_144 , 0 , NULL ) ;
F_44 ( V_50 , V_145 , 0 , NULL ) ;
}
F_71 ( V_50 ) ;
}
for ( V_128 = 2 ; V_128 < V_146 && V_128 <= V_6 -> V_98 ; V_128 ++ ) {
struct V_109 V_103 ;
V_103 . V_110 = V_128 ;
F_44 ( V_50 , V_111 ,
sizeof( V_103 ) , & V_103 ) ;
}
}
static void F_79 ( struct V_49 * V_50 , unsigned long V_56 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
if ( V_6 -> V_70 [ 6 ] & 0x80 &&
! F_6 ( V_129 , & V_6 -> V_26 ) ) {
struct V_147 V_103 ;
F_78 ( & V_103 . V_131 , V_132 ) ;
V_103 . V_148 = 0x01 ;
F_44 ( V_50 , V_149 ,
sizeof( V_103 ) , & V_103 ) ;
}
if ( V_6 -> V_70 [ 22 ] & 0x04 )
F_73 ( V_50 ) ;
if ( V_6 -> V_70 [ 29 ] & 0x20 )
F_44 ( V_50 , V_150 , 0 , NULL ) ;
if ( V_6 -> V_70 [ 30 ] & 0x08 )
F_44 ( V_50 , V_151 , 0 , NULL ) ;
if ( F_80 ( V_6 ) )
F_44 ( V_50 , V_152 , 0 , NULL ) ;
if ( F_2 ( V_6 , V_99 ) &&
F_81 ( V_6 ) ) {
T_5 V_153 = 0x01 ;
F_44 ( V_50 , V_154 ,
sizeof( V_153 ) , & V_153 ) ;
}
}
static int F_82 ( struct V_5 * V_6 )
{
int V_24 ;
V_24 = F_39 ( V_6 , F_48 , 0 , V_155 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_2 ( V_6 , V_156 ) )
F_20 ( V_6 ) ;
V_24 = F_39 ( V_6 , F_63 , 0 , V_155 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_6 -> V_72 != V_73 )
return 0 ;
V_24 = F_39 ( V_6 , F_77 , 0 , V_155 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_39 ( V_6 , F_79 , 0 , V_155 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! F_2 ( V_6 , V_156 ) &&
! F_2 ( V_6 , V_157 ) )
return 0 ;
F_83 ( V_6 ) ;
if ( F_53 ( V_6 ) )
F_84 ( V_6 ) ;
if ( F_62 ( V_6 ) )
F_85 ( V_6 ) ;
return 0 ;
}
static void F_86 ( struct V_49 * V_50 , unsigned long V_56 )
{
struct V_5 * V_6 = V_50 -> V_6 ;
F_23 ( L_8 , V_6 -> V_35 , V_56 ) ;
if ( ! F_6 ( V_71 , & V_6 -> V_26 ) )
F_42 ( V_50 , 0 ) ;
F_44 ( V_50 , V_62 , 0 , NULL ) ;
if ( V_6 -> V_158 )
F_44 ( V_50 , V_63 , 0 , NULL ) ;
}
static int F_87 ( struct V_5 * V_6 )
{
int V_24 ;
if ( F_6 ( V_159 , & V_6 -> V_26 ) )
return 0 ;
V_24 = F_39 ( V_6 , F_86 , 0 , V_155 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( F_2 ( V_6 , V_156 ) )
F_20 ( V_6 ) ;
return 0 ;
}
static void F_88 ( struct V_49 * V_50 , unsigned long V_56 )
{
T_10 V_160 = V_56 ;
F_23 ( L_10 , V_50 -> V_6 -> V_35 , V_160 ) ;
F_44 ( V_50 , V_161 , 1 , & V_160 ) ;
}
static void F_89 ( struct V_49 * V_50 , unsigned long V_56 )
{
T_10 V_162 = V_56 ;
F_23 ( L_10 , V_50 -> V_6 -> V_35 , V_162 ) ;
F_44 ( V_50 , V_113 , 1 , & V_162 ) ;
}
static void F_90 ( struct V_49 * V_50 , unsigned long V_56 )
{
T_10 V_163 = V_56 ;
F_23 ( L_10 , V_50 -> V_6 -> V_35 , V_163 ) ;
F_44 ( V_50 , V_164 , 1 , & V_163 ) ;
}
static void F_91 ( struct V_49 * V_50 , unsigned long V_56 )
{
T_9 V_120 = F_51 ( V_56 ) ;
F_23 ( L_10 , V_50 -> V_6 -> V_35 , V_120 ) ;
F_44 ( V_50 , V_121 , 2 , & V_120 ) ;
}
struct V_5 * F_92 ( int V_165 )
{
struct V_5 * V_6 = NULL , * V_166 ;
F_23 ( L_11 , V_165 ) ;
if ( V_165 < 0 )
return NULL ;
F_93 ( & V_167 ) ;
F_94 (d, &hci_dev_list, list) {
if ( V_166 -> V_168 == V_165 ) {
V_6 = F_95 ( V_166 ) ;
break;
}
}
F_96 ( & V_167 ) ;
return V_6 ;
}
bool F_97 ( struct V_5 * V_6 )
{
struct V_169 * V_170 = & V_6 -> V_171 ;
switch ( V_170 -> V_172 ) {
case V_173 :
case V_174 :
return true ;
default:
return false ;
}
}
void F_98 ( struct V_5 * V_6 , int V_172 )
{
int V_175 = V_6 -> V_171 . V_172 ;
F_23 ( L_12 , V_6 -> V_35 , V_6 -> V_171 . V_172 , V_172 ) ;
if ( V_175 == V_172 )
return;
V_6 -> V_171 . V_172 = V_172 ;
switch ( V_172 ) {
case V_176 :
F_99 ( V_6 ) ;
if ( V_175 != V_177 )
F_100 ( V_6 , 0 ) ;
break;
case V_177 :
break;
case V_173 :
F_100 ( V_6 , 1 ) ;
break;
case V_174 :
break;
case V_178 :
break;
}
}
void F_101 ( struct V_5 * V_6 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_180 * V_128 , * V_181 ;
F_102 (p, n, &cache->all, all) {
F_103 ( & V_128 -> V_182 ) ;
F_104 ( V_128 ) ;
}
F_105 ( & V_179 -> V_183 ) ;
F_105 ( & V_179 -> V_184 ) ;
}
struct V_180 * F_106 ( struct V_5 * V_6 ,
T_11 * V_131 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_180 * V_185 ;
F_23 ( L_13 , V_179 , V_131 ) ;
F_94 (e, &cache->all, all) {
if ( ! F_107 ( & V_185 -> V_186 . V_131 , V_131 ) )
return V_185 ;
}
return NULL ;
}
struct V_180 * F_108 ( struct V_5 * V_6 ,
T_11 * V_131 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_180 * V_185 ;
F_23 ( L_13 , V_179 , V_131 ) ;
F_94 (e, &cache->unknown, list) {
if ( ! F_107 ( & V_185 -> V_186 . V_131 , V_131 ) )
return V_185 ;
}
return NULL ;
}
struct V_180 * F_109 ( struct V_5 * V_6 ,
T_11 * V_131 ,
int V_172 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_180 * V_185 ;
F_23 ( L_14 , V_179 , V_131 , V_172 ) ;
F_94 (e, &cache->resolve, list) {
if ( ! F_107 ( V_131 , V_132 ) && V_185 -> V_187 == V_172 )
return V_185 ;
if ( ! F_107 ( & V_185 -> V_186 . V_131 , V_131 ) )
return V_185 ;
}
return NULL ;
}
void F_110 ( struct V_5 * V_6 ,
struct V_180 * V_188 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_189 * V_190 = & V_179 -> V_184 ;
struct V_180 * V_128 ;
F_103 ( & V_188 -> V_191 ) ;
F_94 (p, &cache->resolve, list) {
if ( V_128 -> V_187 != V_192 &&
abs ( V_128 -> V_186 . V_193 ) >= abs ( V_188 -> V_186 . V_193 ) )
break;
V_190 = & V_128 -> V_191 ;
}
F_111 ( & V_188 -> V_191 , V_190 ) ;
}
T_7 F_112 ( struct V_5 * V_6 , struct V_194 * V_186 ,
bool V_195 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_180 * V_188 ;
T_7 V_15 = 0 ;
F_23 ( L_13 , V_179 , & V_186 -> V_131 ) ;
F_113 ( V_6 , & V_186 -> V_131 , V_196 ) ;
if ( ! V_186 -> V_197 )
V_15 |= V_198 ;
V_188 = F_106 ( V_6 , & V_186 -> V_131 ) ;
if ( V_188 ) {
if ( ! V_188 -> V_186 . V_197 )
V_15 |= V_198 ;
if ( V_188 -> V_187 == V_199 &&
V_186 -> V_193 != V_188 -> V_186 . V_193 ) {
V_188 -> V_186 . V_193 = V_186 -> V_193 ;
F_110 ( V_6 , V_188 ) ;
}
goto V_200;
}
V_188 = F_114 ( sizeof( * V_188 ) , V_201 ) ;
if ( ! V_188 ) {
V_15 |= V_202 ;
goto V_28;
}
F_111 ( & V_188 -> V_182 , & V_179 -> V_182 ) ;
if ( V_195 ) {
V_188 -> V_187 = V_203 ;
} else {
V_188 -> V_187 = V_204 ;
F_111 ( & V_188 -> V_191 , & V_179 -> V_183 ) ;
}
V_200:
if ( V_195 && V_188 -> V_187 != V_203 &&
V_188 -> V_187 != V_192 ) {
V_188 -> V_187 = V_203 ;
F_103 ( & V_188 -> V_191 ) ;
}
memcpy ( & V_188 -> V_186 , V_186 , sizeof( * V_186 ) ) ;
V_188 -> V_205 = V_206 ;
V_179 -> V_205 = V_206 ;
if ( V_188 -> V_187 == V_204 )
V_15 |= V_202 ;
V_28:
return V_15 ;
}
static int F_115 ( struct V_5 * V_6 , int V_207 , T_10 * V_8 )
{
struct V_169 * V_179 = & V_6 -> V_171 ;
struct V_208 * V_209 = (struct V_208 * ) V_8 ;
struct V_180 * V_185 ;
int V_210 = 0 ;
F_94 (e, &cache->all, all) {
struct V_194 * V_186 = & V_185 -> V_186 ;
if ( V_210 >= V_207 )
break;
F_78 ( & V_209 -> V_131 , & V_186 -> V_131 ) ;
V_209 -> V_211 = V_186 -> V_211 ;
V_209 -> V_212 = V_186 -> V_212 ;
V_209 -> V_213 = V_186 -> V_213 ;
memcpy ( V_209 -> V_214 , V_186 -> V_214 , 3 ) ;
V_209 -> V_215 = V_186 -> V_215 ;
V_209 ++ ;
V_210 ++ ;
}
F_23 ( L_15 , V_179 , V_210 ) ;
return V_210 ;
}
static void F_116 ( struct V_49 * V_50 , unsigned long V_56 )
{
struct V_216 * V_217 = (struct V_216 * ) V_56 ;
struct V_5 * V_6 = V_50 -> V_6 ;
struct V_218 V_103 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( F_6 ( V_219 , & V_6 -> V_15 ) )
return;
memcpy ( & V_103 . V_220 , & V_217 -> V_220 , 3 ) ;
V_103 . V_221 = V_217 -> V_221 ;
V_103 . V_222 = V_217 -> V_222 ;
F_44 ( V_50 , V_223 , sizeof( V_103 ) , & V_103 ) ;
}
int F_117 ( void T_2 * V_224 )
{
T_10 T_2 * V_225 = V_224 ;
struct V_216 V_217 ;
struct V_5 * V_6 ;
int V_24 = 0 , V_226 = 0 , V_227 ;
long V_228 ;
T_10 * V_8 ;
if ( F_7 ( & V_217 , V_225 , sizeof( V_217 ) ) )
return - V_17 ;
V_6 = F_92 ( V_217 . V_229 ) ;
if ( ! V_6 )
return - V_230 ;
if ( F_2 ( V_6 , V_231 ) ) {
V_24 = - V_232 ;
goto V_28;
}
if ( F_2 ( V_6 , V_233 ) ) {
V_24 = - V_234 ;
goto V_28;
}
if ( V_6 -> V_72 != V_73 ) {
V_24 = - V_234 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_95 ) ) {
V_24 = - V_234 ;
goto V_28;
}
F_118 ( V_6 ) ;
if ( F_119 ( V_6 ) > V_235 ||
F_120 ( V_6 ) || V_217 . V_15 & V_236 ) {
F_101 ( V_6 ) ;
V_226 = 1 ;
}
F_121 ( V_6 ) ;
V_228 = V_217 . V_221 * F_122 ( 2000 ) ;
if ( V_226 ) {
V_24 = F_41 ( V_6 , F_116 , ( unsigned long ) & V_217 ,
V_228 ) ;
if ( V_24 < 0 )
goto V_28;
if ( F_123 ( & V_6 -> V_15 , V_219 ,
V_51 ) )
return - V_53 ;
}
V_227 = ( V_217 . V_222 == 0 ) ? 255 : V_217 . V_222 ;
V_8 = F_124 ( sizeof( struct V_208 ) * V_227 , V_201 ) ;
if ( ! V_8 ) {
V_24 = - V_237 ;
goto V_28;
}
F_118 ( V_6 ) ;
V_217 . V_222 = F_115 ( V_6 , V_227 , V_8 ) ;
F_121 ( V_6 ) ;
F_23 ( L_16 , V_217 . V_222 ) ;
if ( ! F_125 ( V_225 , & V_217 , sizeof( V_217 ) ) ) {
V_225 += sizeof( V_217 ) ;
if ( F_125 ( V_225 , V_8 , sizeof( struct V_208 ) *
V_217 . V_222 ) )
V_24 = - V_17 ;
} else
V_24 = - V_17 ;
F_104 ( V_8 ) ;
V_28:
F_126 ( V_6 ) ;
return V_24 ;
}
static int F_127 ( struct V_5 * V_6 )
{
int V_57 = 0 ;
F_23 ( L_17 , V_6 -> V_35 , V_6 ) ;
F_9 ( V_6 ) ;
if ( F_2 ( V_6 , V_238 ) ) {
V_57 = - V_230 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_156 ) &&
! F_2 ( V_6 , V_157 ) ) {
if ( F_2 ( V_6 , V_239 ) ) {
V_57 = - V_240 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_231 ) &&
V_6 -> V_72 == V_73 &&
! F_107 ( & V_6 -> V_131 , V_132 ) &&
! F_107 ( & V_6 -> V_241 , V_132 ) ) {
V_57 = - V_242 ;
goto V_28;
}
}
if ( F_6 ( V_14 , & V_6 -> V_15 ) ) {
V_57 = - V_19 ;
goto V_28;
}
if ( V_6 -> V_243 ( V_6 ) ) {
V_57 = - V_244 ;
goto V_28;
}
F_43 ( V_27 , & V_6 -> V_15 ) ;
F_128 ( V_6 , V_245 ) ;
F_129 ( & V_6 -> V_246 , 1 ) ;
F_43 ( V_247 , & V_6 -> V_15 ) ;
if ( F_2 ( V_6 , V_156 ) ) {
F_128 ( V_6 , V_248 ) ;
if ( V_6 -> V_249 )
V_57 = V_6 -> V_249 ( V_6 ) ;
if ( F_6 ( V_250 , & V_6 -> V_26 ) ||
F_6 ( V_251 , & V_6 -> V_26 ) )
F_18 ( V_6 , V_233 ) ;
if ( F_2 ( V_6 , V_233 ) )
V_57 = F_87 ( V_6 ) ;
}
if ( F_2 ( V_6 , V_157 ) ) {
if ( F_107 ( & V_6 -> V_252 , V_132 ) &&
V_6 -> V_158 )
V_57 = V_6 -> V_158 ( V_6 , & V_6 -> V_252 ) ;
else
V_57 = - V_242 ;
}
if ( ! V_57 ) {
if ( ! F_2 ( V_6 , V_233 ) &&
! F_2 ( V_6 , V_231 ) ) {
V_57 = F_82 ( V_6 ) ;
if ( ! V_57 && V_6 -> V_253 )
V_57 = V_6 -> V_253 ( V_6 ) ;
}
}
if ( F_6 ( V_25 , & V_6 -> V_26 ) &&
F_2 ( V_6 , V_23 ) && V_6 -> V_29 )
V_57 = V_6 -> V_29 ( V_6 , true ) ;
F_130 ( V_247 , & V_6 -> V_15 ) ;
if ( ! V_57 ) {
F_95 ( V_6 ) ;
F_18 ( V_6 , V_254 ) ;
F_43 ( V_14 , & V_6 -> V_15 ) ;
F_128 ( V_6 , V_255 ) ;
if ( ! F_2 ( V_6 , V_156 ) &&
! F_2 ( V_6 , V_157 ) &&
! F_2 ( V_6 , V_233 ) &&
! F_2 ( V_6 , V_231 ) &&
V_6 -> V_72 == V_73 ) {
F_118 ( V_6 ) ;
F_131 ( V_6 , 1 ) ;
F_121 ( V_6 ) ;
}
} else {
F_132 ( & V_6 -> V_256 ) ;
F_132 ( & V_6 -> V_257 ) ;
F_132 ( & V_6 -> V_258 ) ;
F_133 ( & V_6 -> V_259 ) ;
F_133 ( & V_6 -> V_260 ) ;
if ( V_6 -> V_261 )
V_6 -> V_261 ( V_6 ) ;
if ( V_6 -> V_262 ) {
F_14 ( V_6 -> V_262 ) ;
V_6 -> V_262 = NULL ;
}
F_130 ( V_27 , & V_6 -> V_15 ) ;
F_128 ( V_6 , V_263 ) ;
V_6 -> V_264 ( V_6 ) ;
V_6 -> V_15 &= F_134 ( V_265 ) ;
}
V_28:
F_11 ( V_6 ) ;
return V_57 ;
}
int F_135 ( T_12 V_266 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_92 ( V_266 ) ;
if ( ! V_6 )
return - V_230 ;
if ( F_2 ( V_6 , V_233 ) &&
! F_2 ( V_6 , V_231 ) ) {
V_24 = - V_234 ;
goto V_28;
}
if ( F_136 ( V_6 , V_267 ) )
F_137 ( & V_6 -> V_268 ) ;
F_138 ( V_6 -> V_269 ) ;
if ( ! F_2 ( V_6 , V_231 ) &&
! F_2 ( V_6 , V_270 ) )
F_18 ( V_6 , V_271 ) ;
V_24 = F_127 ( V_6 ) ;
V_28:
F_126 ( V_6 ) ;
return V_24 ;
}
static void F_139 ( struct V_5 * V_6 )
{
struct V_272 * V_128 ;
F_94 (p, &hdev->le_conn_params, list) {
if ( V_128 -> V_273 ) {
F_140 ( V_128 -> V_273 ) ;
F_141 ( V_128 -> V_273 ) ;
V_128 -> V_273 = NULL ;
}
F_142 ( & V_128 -> V_274 ) ;
}
F_23 ( L_18 ) ;
}
int F_143 ( struct V_5 * V_6 )
{
bool V_275 ;
F_23 ( L_17 , V_6 -> V_35 , V_6 ) ;
if ( ! F_2 ( V_6 , V_238 ) &&
! F_2 ( V_6 , V_231 ) &&
F_6 ( V_14 , & V_6 -> V_15 ) ) {
if ( V_6 -> V_276 )
V_6 -> V_276 ( V_6 ) ;
}
F_137 ( & V_6 -> V_268 ) ;
F_26 ( V_6 , V_230 ) ;
F_9 ( V_6 ) ;
if ( ! F_144 ( V_14 , & V_6 -> V_15 ) ) {
F_145 ( & V_6 -> V_277 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
F_132 ( & V_6 -> V_256 ) ;
F_132 ( & V_6 -> V_258 ) ;
if ( V_6 -> V_278 > 0 ) {
F_137 ( & V_6 -> V_279 ) ;
V_6 -> V_278 = 0 ;
F_19 ( V_6 , V_280 ) ;
F_19 ( V_6 , V_281 ) ;
}
if ( F_136 ( V_6 , V_282 ) )
F_137 ( & V_6 -> V_283 ) ;
F_145 ( & V_6 -> V_284 ) ;
F_145 ( & V_6 -> V_285 ) ;
if ( F_2 ( V_6 , V_270 ) )
F_145 ( & V_6 -> V_286 ) ;
if ( V_6 -> V_287 ) {
F_145 ( & V_6 -> V_288 ) ;
V_6 -> V_287 = 0 ;
}
F_146 ( V_6 -> V_289 ) ;
F_118 ( V_6 ) ;
F_98 ( V_6 , V_176 ) ;
V_275 = F_136 ( V_6 , V_267 ) ;
if ( ! V_275 && V_6 -> V_72 == V_73 )
F_131 ( V_6 , 0 ) ;
F_101 ( V_6 ) ;
F_139 ( V_6 ) ;
F_147 ( V_6 ) ;
F_121 ( V_6 ) ;
F_148 ( V_6 ) ;
F_128 ( V_6 , V_290 ) ;
if ( V_6 -> V_261 )
V_6 -> V_261 ( V_6 ) ;
F_133 ( & V_6 -> V_259 ) ;
F_129 ( & V_6 -> V_246 , 1 ) ;
if ( F_6 ( V_71 , & V_6 -> V_26 ) &&
! V_275 && ! F_2 ( V_6 , V_233 ) ) {
F_43 ( V_247 , & V_6 -> V_15 ) ;
F_39 ( V_6 , F_42 , 0 , V_21 ) ;
F_130 ( V_247 , & V_6 -> V_15 ) ;
}
F_132 ( & V_6 -> V_257 ) ;
F_133 ( & V_6 -> V_260 ) ;
F_133 ( & V_6 -> V_259 ) ;
F_133 ( & V_6 -> V_291 ) ;
if ( V_6 -> V_262 ) {
F_145 ( & V_6 -> V_277 ) ;
F_14 ( V_6 -> V_262 ) ;
V_6 -> V_262 = NULL ;
}
F_130 ( V_27 , & V_6 -> V_15 ) ;
F_128 ( V_6 , V_263 ) ;
V_6 -> V_264 ( V_6 ) ;
V_6 -> V_15 &= F_134 ( V_265 ) ;
F_149 ( V_6 ) ;
V_6 -> V_292 = V_293 ;
memset ( V_6 -> V_104 , 0 , sizeof( V_6 -> V_104 ) ) ;
memset ( V_6 -> V_214 , 0 , sizeof( V_6 -> V_214 ) ) ;
F_78 ( & V_6 -> V_294 , V_132 ) ;
F_11 ( V_6 ) ;
F_126 ( V_6 ) ;
return 0 ;
}
int F_150 ( T_12 V_266 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_92 ( V_266 ) ;
if ( ! V_6 )
return - V_230 ;
if ( F_2 ( V_6 , V_231 ) ) {
V_24 = - V_232 ;
goto V_28;
}
if ( F_136 ( V_6 , V_267 ) )
F_137 ( & V_6 -> V_268 ) ;
V_24 = F_143 ( V_6 ) ;
V_28:
F_126 ( V_6 ) ;
return V_24 ;
}
static int F_151 ( struct V_5 * V_6 )
{
int V_57 ;
F_23 ( L_17 , V_6 -> V_35 , V_6 ) ;
F_9 ( V_6 ) ;
F_133 ( & V_6 -> V_260 ) ;
F_133 ( & V_6 -> V_259 ) ;
F_146 ( V_6 -> V_289 ) ;
F_118 ( V_6 ) ;
F_101 ( V_6 ) ;
F_147 ( V_6 ) ;
F_121 ( V_6 ) ;
if ( V_6 -> V_261 )
V_6 -> V_261 ( V_6 ) ;
F_129 ( & V_6 -> V_246 , 1 ) ;
V_6 -> V_295 = 0 ; V_6 -> V_296 = 0 ; V_6 -> V_297 = 0 ;
V_57 = F_39 ( V_6 , F_42 , 0 , V_155 ) ;
F_11 ( V_6 ) ;
return V_57 ;
}
int F_152 ( T_12 V_266 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_92 ( V_266 ) ;
if ( ! V_6 )
return - V_230 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) ) {
V_24 = - V_16 ;
goto V_28;
}
if ( F_2 ( V_6 , V_231 ) ) {
V_24 = - V_232 ;
goto V_28;
}
if ( F_2 ( V_6 , V_233 ) ) {
V_24 = - V_234 ;
goto V_28;
}
V_24 = F_151 ( V_6 ) ;
V_28:
F_126 ( V_6 ) ;
return V_24 ;
}
int F_153 ( T_12 V_266 )
{
struct V_5 * V_6 ;
int V_57 = 0 ;
V_6 = F_92 ( V_266 ) ;
if ( ! V_6 )
return - V_230 ;
if ( F_2 ( V_6 , V_231 ) ) {
V_57 = - V_232 ;
goto V_28;
}
if ( F_2 ( V_6 , V_233 ) ) {
V_57 = - V_234 ;
goto V_28;
}
memset ( & V_6 -> V_298 , 0 , sizeof( struct V_299 ) ) ;
V_28:
F_126 ( V_6 ) ;
return V_57 ;
}
static void F_154 ( struct V_5 * V_6 , T_5 V_160 )
{
bool V_300 , V_301 ;
F_23 ( L_19 , V_6 -> V_35 , V_160 ) ;
if ( ( V_160 & V_302 ) )
V_300 = ! F_155 ( V_6 ,
V_303 ) ;
else
V_300 = F_136 ( V_6 ,
V_303 ) ;
if ( ( V_160 & V_304 ) ) {
V_301 = ! F_155 ( V_6 ,
V_280 ) ;
} else {
F_19 ( V_6 , V_281 ) ;
V_301 = F_136 ( V_6 ,
V_280 ) ;
}
if ( ! F_2 ( V_6 , V_270 ) )
return;
if ( V_300 || V_301 ) {
F_18 ( V_6 , V_95 ) ;
if ( F_2 ( V_6 , V_88 ) )
F_156 ( V_6 ) ;
F_157 ( V_6 ) ;
}
}
int F_158 ( unsigned int V_305 , void T_2 * V_224 )
{
struct V_5 * V_6 ;
struct V_306 V_307 ;
int V_24 = 0 ;
if ( F_7 ( & V_307 , V_224 , sizeof( V_307 ) ) )
return - V_17 ;
V_6 = F_92 ( V_307 . V_229 ) ;
if ( ! V_6 )
return - V_230 ;
if ( F_2 ( V_6 , V_231 ) ) {
V_24 = - V_232 ;
goto V_28;
}
if ( F_2 ( V_6 , V_233 ) ) {
V_24 = - V_234 ;
goto V_28;
}
if ( V_6 -> V_72 != V_73 ) {
V_24 = - V_234 ;
goto V_28;
}
if ( ! F_2 ( V_6 , V_95 ) ) {
V_24 = - V_234 ;
goto V_28;
}
switch ( V_305 ) {
case V_308 :
V_24 = F_41 ( V_6 , F_89 , V_307 . V_309 ,
V_155 ) ;
break;
case V_310 :
if ( ! F_159 ( V_6 ) ) {
V_24 = - V_234 ;
break;
}
if ( ! F_6 ( V_311 , & V_6 -> V_15 ) ) {
V_24 = F_41 ( V_6 , F_89 , V_307 . V_309 ,
V_155 ) ;
if ( V_24 )
break;
}
V_24 = F_41 ( V_6 , F_90 , V_307 . V_309 ,
V_155 ) ;
break;
case V_312 :
V_24 = F_41 ( V_6 , F_88 , V_307 . V_309 ,
V_155 ) ;
if ( ! V_24 )
F_154 ( V_6 , V_307 . V_309 ) ;
break;
case V_313 :
V_24 = F_41 ( V_6 , F_91 , V_307 . V_309 ,
V_155 ) ;
break;
case V_314 :
V_6 -> V_315 = ( ( T_12 ) V_307 . V_309 ) &
( V_316 | V_317 ) ;
break;
case V_318 :
V_6 -> V_319 = ( T_12 ) V_307 . V_309 ;
break;
case V_320 :
V_6 -> V_321 = * ( ( T_12 * ) & V_307 . V_309 + 1 ) ;
V_6 -> V_322 = * ( ( T_12 * ) & V_307 . V_309 + 0 ) ;
break;
case V_323 :
V_6 -> V_324 = * ( ( T_12 * ) & V_307 . V_309 + 1 ) ;
V_6 -> V_325 = * ( ( T_12 * ) & V_307 . V_309 + 0 ) ;
break;
default:
V_24 = - V_18 ;
break;
}
V_28:
F_126 ( V_6 ) ;
return V_24 ;
}
int F_160 ( void T_2 * V_224 )
{
struct V_5 * V_6 ;
struct V_326 * V_327 ;
struct V_306 * V_307 ;
int V_181 = 0 , V_328 , V_24 ;
T_12 V_329 ;
if ( F_161 ( V_329 , ( T_12 T_2 * ) V_224 ) )
return - V_17 ;
if ( ! V_329 || V_329 > ( V_330 * 2 ) / sizeof( * V_307 ) )
return - V_18 ;
V_328 = sizeof( * V_327 ) + V_329 * sizeof( * V_307 ) ;
V_327 = F_114 ( V_328 , V_201 ) ;
if ( ! V_327 )
return - V_237 ;
V_307 = V_327 -> V_331 ;
F_93 ( & V_167 ) ;
F_94 (hdev, &hci_dev_list, list) {
unsigned long V_15 = V_6 -> V_15 ;
if ( F_2 ( V_6 , V_267 ) )
V_15 &= ~ F_134 ( V_14 ) ;
( V_307 + V_181 ) -> V_229 = V_6 -> V_168 ;
( V_307 + V_181 ) -> V_309 = V_15 ;
if ( ++ V_181 >= V_329 )
break;
}
F_96 ( & V_167 ) ;
V_327 -> V_329 = V_181 ;
V_328 = sizeof( * V_327 ) + V_181 * sizeof( * V_307 ) ;
V_24 = F_125 ( V_224 , V_327 , V_328 ) ;
F_104 ( V_327 ) ;
return V_24 ? - V_17 : 0 ;
}
int F_162 ( void T_2 * V_224 )
{
struct V_5 * V_6 ;
struct V_332 V_333 ;
unsigned long V_15 ;
int V_24 = 0 ;
if ( F_7 ( & V_333 , V_224 , sizeof( V_333 ) ) )
return - V_17 ;
V_6 = F_92 ( V_333 . V_229 ) ;
if ( ! V_6 )
return - V_230 ;
if ( F_2 ( V_6 , V_267 ) )
V_15 = V_6 -> V_15 & ~ F_134 ( V_14 ) ;
else
V_15 = V_6 -> V_15 ;
strcpy ( V_333 . V_35 , V_6 -> V_35 ) ;
V_333 . V_131 = V_6 -> V_131 ;
V_333 . type = ( V_6 -> V_334 & 0x0f ) | ( ( V_6 -> V_72 & 0x03 ) << 4 ) ;
V_333 . V_15 = V_15 ;
V_333 . V_319 = V_6 -> V_319 ;
if ( F_53 ( V_6 ) ) {
V_333 . V_321 = V_6 -> V_321 ;
V_333 . V_322 = V_6 -> V_322 ;
V_333 . V_324 = V_6 -> V_324 ;
V_333 . V_325 = V_6 -> V_325 ;
} else {
V_333 . V_321 = V_6 -> V_335 ;
V_333 . V_322 = V_6 -> V_336 ;
V_333 . V_324 = 0 ;
V_333 . V_325 = 0 ;
}
V_333 . V_115 = V_6 -> V_115 ;
V_333 . V_315 = V_6 -> V_315 ;
memcpy ( & V_333 . V_298 , & V_6 -> V_298 , sizeof( V_333 . V_298 ) ) ;
memcpy ( & V_333 . V_337 , & V_6 -> V_337 , sizeof( V_333 . V_337 ) ) ;
if ( F_125 ( V_224 , & V_333 , sizeof( V_333 ) ) )
V_24 = - V_17 ;
F_126 ( V_6 ) ;
return V_24 ;
}
static int F_163 ( void * V_186 , bool V_338 )
{
struct V_5 * V_6 = V_186 ;
F_23 ( L_20 , V_6 , V_6 -> V_35 , V_338 ) ;
if ( F_2 ( V_6 , V_231 ) )
return - V_232 ;
if ( V_338 ) {
F_18 ( V_6 , V_239 ) ;
if ( ! F_2 ( V_6 , V_156 ) &&
! F_2 ( V_6 , V_157 ) )
F_143 ( V_6 ) ;
} else {
F_19 ( V_6 , V_239 ) ;
}
return 0 ;
}
static void F_164 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 , V_341 ) ;
int V_24 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
V_24 = F_127 ( V_6 ) ;
if ( V_24 < 0 ) {
F_118 ( V_6 ) ;
F_166 ( V_6 , V_24 ) ;
F_121 ( V_6 ) ;
return;
}
if ( F_2 ( V_6 , V_239 ) ||
F_2 ( V_6 , V_233 ) ||
( V_6 -> V_72 == V_73 &&
! F_107 ( & V_6 -> V_131 , V_132 ) &&
! F_107 ( & V_6 -> V_241 , V_132 ) ) ) {
F_19 ( V_6 , V_267 ) ;
F_143 ( V_6 ) ;
} else if ( F_2 ( V_6 , V_267 ) ) {
F_167 ( V_6 -> V_269 , & V_6 -> V_268 ,
V_342 ) ;
}
if ( F_136 ( V_6 , V_156 ) ) {
if ( F_2 ( V_6 , V_233 ) )
F_43 ( V_265 , & V_6 -> V_15 ) ;
F_168 ( V_6 ) ;
} else if ( F_136 ( V_6 , V_157 ) ) {
if ( ! F_2 ( V_6 , V_233 ) )
F_130 ( V_265 , & V_6 -> V_15 ) ;
F_168 ( V_6 ) ;
}
}
static void F_169 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 ,
V_268 . V_340 ) ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_143 ( V_6 ) ;
}
static void F_170 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 , V_343 ) ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( V_6 -> V_344 )
V_6 -> V_344 ( V_6 , V_6 -> V_345 ) ;
else
F_49 ( L_21 , V_6 -> V_35 ,
V_6 -> V_345 ) ;
if ( F_143 ( V_6 ) )
return;
F_127 ( V_6 ) ;
}
static void F_171 ( struct V_339 * V_340 )
{
struct V_5 * V_6 ;
V_6 = F_165 ( V_340 , struct V_5 , V_279 . V_340 ) ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_172 ( V_6 ) ;
}
static void F_173 ( struct V_339 * V_340 )
{
struct V_5 * V_6 ;
V_6 = F_165 ( V_340 , struct V_5 , V_288 . V_340 ) ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_174 ( V_6 ) ;
}
void F_175 ( struct V_5 * V_6 )
{
struct V_346 * V_347 , * V_348 ;
F_102 (uuid, tmp, &hdev->uuids, list) {
F_103 ( & V_347 -> V_191 ) ;
F_104 ( V_347 ) ;
}
}
void F_176 ( struct V_5 * V_6 )
{
struct V_349 * V_350 ;
F_177 (key, &hdev->link_keys, list) {
F_178 ( & V_350 -> V_191 ) ;
F_179 ( V_350 , V_351 ) ;
}
}
void F_180 ( struct V_5 * V_6 )
{
struct V_352 * V_353 ;
F_177 (k, &hdev->long_term_keys, list) {
F_178 ( & V_353 -> V_191 ) ;
F_179 ( V_353 , V_351 ) ;
}
}
void F_181 ( struct V_5 * V_6 )
{
struct V_354 * V_353 ;
F_177 (k, &hdev->identity_resolving_keys, list) {
F_178 ( & V_353 -> V_191 ) ;
F_179 ( V_353 , V_351 ) ;
}
}
struct V_349 * F_182 ( struct V_5 * V_6 , T_11 * V_131 )
{
struct V_349 * V_353 ;
F_183 () ;
F_177 (k, &hdev->link_keys, list) {
if ( F_107 ( V_131 , & V_353 -> V_131 ) == 0 ) {
F_184 () ;
return V_353 ;
}
}
F_184 () ;
return NULL ;
}
static bool F_185 ( struct V_5 * V_6 , struct V_355 * V_273 ,
T_5 V_356 , T_5 V_357 )
{
if ( V_356 < 0x03 )
return true ;
if ( V_356 == V_358 )
return false ;
if ( V_356 == V_359 && V_357 == 0xff )
return false ;
if ( ! V_273 )
return true ;
if ( V_273 -> type == V_360 )
return true ;
if ( V_273 -> V_361 > 0x01 && V_273 -> V_362 > 0x01 )
return true ;
if ( V_273 -> V_361 == 0x02 || V_273 -> V_361 == 0x03 )
return true ;
if ( V_273 -> V_362 == 0x02 || V_273 -> V_362 == 0x03 )
return true ;
return false ;
}
static T_5 F_186 ( T_5 type )
{
if ( type == V_363 )
return V_364 ;
return V_365 ;
}
struct V_352 * F_187 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 V_366 , T_5 V_367 )
{
struct V_352 * V_353 ;
F_183 () ;
F_177 (k, &hdev->long_term_keys, list) {
if ( V_366 != V_353 -> V_368 || F_107 ( V_131 , & V_353 -> V_131 ) )
continue;
if ( F_188 ( V_353 ) || F_186 ( V_353 -> type ) == V_367 ) {
F_184 () ;
return V_353 ;
}
}
F_184 () ;
return NULL ;
}
struct V_354 * F_189 ( struct V_5 * V_6 , T_11 * V_369 )
{
struct V_354 * V_370 ;
F_183 () ;
F_177 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_107 ( & V_370 -> V_369 , V_369 ) ) {
F_184 () ;
return V_370 ;
}
}
F_177 (irk, &hdev->identity_resolving_keys, list) {
if ( F_190 ( V_6 , V_370 -> V_371 , V_369 ) ) {
F_78 ( & V_370 -> V_369 , V_369 ) ;
F_184 () ;
return V_370 ;
}
}
F_184 () ;
return NULL ;
}
struct V_354 * F_191 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 V_366 )
{
struct V_354 * V_370 ;
if ( V_366 == V_372 && ( V_131 -> V_373 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_183 () ;
F_177 (irk, &hdev->identity_resolving_keys, list) {
if ( V_366 == V_370 -> V_366 &&
F_107 ( V_131 , & V_370 -> V_131 ) == 0 ) {
F_184 () ;
return V_370 ;
}
}
F_184 () ;
return NULL ;
}
struct V_349 * F_192 ( struct V_5 * V_6 , struct V_355 * V_273 ,
T_11 * V_131 , T_5 * V_371 , T_5 type ,
T_5 V_374 , bool * V_375 )
{
struct V_349 * V_350 , * V_376 ;
T_5 V_357 ;
V_376 = F_182 ( V_6 , V_131 ) ;
if ( V_376 ) {
V_357 = V_376 -> type ;
V_350 = V_376 ;
} else {
V_357 = V_273 ? V_273 -> V_356 : 0xff ;
V_350 = F_114 ( sizeof( * V_350 ) , V_201 ) ;
if ( ! V_350 )
return NULL ;
F_193 ( & V_350 -> V_191 , & V_6 -> V_377 ) ;
}
F_23 ( L_22 , V_6 -> V_35 , V_131 , type ) ;
if ( type == V_359 &&
( ! V_273 || V_273 -> V_362 == 0xff ) && V_357 == 0xff ) {
type = V_378 ;
if ( V_273 )
V_273 -> V_356 = type ;
}
F_78 ( & V_350 -> V_131 , V_131 ) ;
memcpy ( V_350 -> V_371 , V_371 , V_379 ) ;
V_350 -> V_374 = V_374 ;
if ( type == V_359 )
V_350 -> type = V_357 ;
else
V_350 -> type = type ;
if ( V_375 )
* V_375 = F_185 ( V_6 , V_273 , type ,
V_357 ) ;
return V_350 ;
}
struct V_352 * F_194 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 V_366 , T_5 type , T_5 V_380 ,
T_5 V_381 [ 16 ] , T_5 V_382 , T_9 V_383 , T_13 rand )
{
struct V_352 * V_350 , * V_376 ;
T_5 V_367 = F_186 ( type ) ;
V_376 = F_187 ( V_6 , V_131 , V_366 , V_367 ) ;
if ( V_376 )
V_350 = V_376 ;
else {
V_350 = F_114 ( sizeof( * V_350 ) , V_201 ) ;
if ( ! V_350 )
return NULL ;
F_193 ( & V_350 -> V_191 , & V_6 -> V_384 ) ;
}
F_78 ( & V_350 -> V_131 , V_131 ) ;
V_350 -> V_368 = V_366 ;
memcpy ( V_350 -> V_371 , V_381 , sizeof( V_350 -> V_371 ) ) ;
V_350 -> V_380 = V_380 ;
V_350 -> V_383 = V_383 ;
V_350 -> rand = rand ;
V_350 -> V_382 = V_382 ;
V_350 -> type = type ;
return V_350 ;
}
struct V_354 * F_195 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 V_366 , T_5 V_371 [ 16 ] , T_11 * V_369 )
{
struct V_354 * V_370 ;
V_370 = F_191 ( V_6 , V_131 , V_366 ) ;
if ( ! V_370 ) {
V_370 = F_114 ( sizeof( * V_370 ) , V_201 ) ;
if ( ! V_370 )
return NULL ;
F_78 ( & V_370 -> V_131 , V_131 ) ;
V_370 -> V_366 = V_366 ;
F_193 ( & V_370 -> V_191 , & V_6 -> V_385 ) ;
}
memcpy ( V_370 -> V_371 , V_371 , 16 ) ;
F_78 ( & V_370 -> V_369 , V_369 ) ;
return V_370 ;
}
int F_196 ( struct V_5 * V_6 , T_11 * V_131 )
{
struct V_349 * V_350 ;
V_350 = F_182 ( V_6 , V_131 ) ;
if ( ! V_350 )
return - V_386 ;
F_23 ( L_23 , V_6 -> V_35 , V_131 ) ;
F_178 ( & V_350 -> V_191 ) ;
F_179 ( V_350 , V_351 ) ;
return 0 ;
}
int F_197 ( struct V_5 * V_6 , T_11 * V_131 , T_5 V_368 )
{
struct V_352 * V_353 ;
int V_387 = 0 ;
F_177 (k, &hdev->long_term_keys, list) {
if ( F_107 ( V_131 , & V_353 -> V_131 ) || V_353 -> V_368 != V_368 )
continue;
F_23 ( L_23 , V_6 -> V_35 , V_131 ) ;
F_178 ( & V_353 -> V_191 ) ;
F_179 ( V_353 , V_351 ) ;
V_387 ++ ;
}
return V_387 ? 0 : - V_386 ;
}
void F_198 ( struct V_5 * V_6 , T_11 * V_131 , T_5 V_366 )
{
struct V_354 * V_353 ;
F_177 (k, &hdev->identity_resolving_keys, list) {
if ( F_107 ( V_131 , & V_353 -> V_131 ) || V_353 -> V_366 != V_366 )
continue;
F_23 ( L_23 , V_6 -> V_35 , V_131 ) ;
F_178 ( & V_353 -> V_191 ) ;
F_179 ( V_353 , V_351 ) ;
}
}
bool F_199 ( struct V_5 * V_6 , T_11 * V_131 , T_5 type )
{
struct V_352 * V_353 ;
struct V_354 * V_370 ;
T_5 V_366 ;
if ( type == V_196 ) {
if ( F_182 ( V_6 , V_131 ) )
return true ;
return false ;
}
if ( type == V_388 )
V_366 = V_389 ;
else
V_366 = V_372 ;
V_370 = F_200 ( V_6 , V_131 , V_366 ) ;
if ( V_370 ) {
V_131 = & V_370 -> V_131 ;
V_366 = V_370 -> V_366 ;
}
F_183 () ;
F_177 (k, &hdev->long_term_keys, list) {
if ( V_353 -> V_368 == V_366 && ! F_107 ( V_131 , & V_353 -> V_131 ) ) {
F_184 () ;
return true ;
}
}
F_184 () ;
return false ;
}
static void F_201 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 ,
V_277 . V_340 ) ;
if ( V_6 -> V_262 ) {
struct V_390 * V_391 = ( void * ) V_6 -> V_262 -> V_186 ;
T_6 V_34 = F_202 ( V_391 -> V_34 ) ;
F_49 ( L_24 , V_6 -> V_35 , V_34 ) ;
} else {
F_49 ( L_25 , V_6 -> V_35 ) ;
}
F_129 ( & V_6 -> V_246 , 1 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_257 ) ;
}
struct V_392 * F_204 ( struct V_5 * V_6 ,
T_11 * V_131 , T_5 V_368 )
{
struct V_392 * V_186 ;
F_94 (data, &hdev->remote_oob_data, list) {
if ( F_107 ( V_131 , & V_186 -> V_131 ) != 0 )
continue;
if ( V_186 -> V_368 != V_368 )
continue;
return V_186 ;
}
return NULL ;
}
int F_113 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 V_368 )
{
struct V_392 * V_186 ;
V_186 = F_204 ( V_6 , V_131 , V_368 ) ;
if ( ! V_186 )
return - V_386 ;
F_23 ( L_26 , V_6 -> V_35 , V_131 , V_368 ) ;
F_103 ( & V_186 -> V_191 ) ;
F_104 ( V_186 ) ;
return 0 ;
}
void F_205 ( struct V_5 * V_6 )
{
struct V_392 * V_186 , * V_181 ;
F_102 (data, n, &hdev->remote_oob_data, list) {
F_103 ( & V_186 -> V_191 ) ;
F_104 ( V_186 ) ;
}
}
int F_206 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 V_368 , T_5 * V_393 , T_5 * V_394 ,
T_5 * V_395 , T_5 * V_396 )
{
struct V_392 * V_186 ;
V_186 = F_204 ( V_6 , V_131 , V_368 ) ;
if ( ! V_186 ) {
V_186 = F_124 ( sizeof( * V_186 ) , V_201 ) ;
if ( ! V_186 )
return - V_237 ;
F_78 ( & V_186 -> V_131 , V_131 ) ;
V_186 -> V_368 = V_368 ;
F_111 ( & V_186 -> V_191 , & V_6 -> V_397 ) ;
}
if ( V_393 && V_394 ) {
memcpy ( V_186 -> V_393 , V_393 , sizeof( V_186 -> V_393 ) ) ;
memcpy ( V_186 -> V_394 , V_394 , sizeof( V_186 -> V_394 ) ) ;
if ( V_395 && V_396 )
V_186 -> V_398 = 0x03 ;
} else {
memset ( V_186 -> V_393 , 0 , sizeof( V_186 -> V_393 ) ) ;
memset ( V_186 -> V_394 , 0 , sizeof( V_186 -> V_394 ) ) ;
if ( V_395 && V_396 )
V_186 -> V_398 = 0x02 ;
else
V_186 -> V_398 = 0x00 ;
}
if ( V_395 && V_396 ) {
memcpy ( V_186 -> V_395 , V_395 , sizeof( V_186 -> V_395 ) ) ;
memcpy ( V_186 -> V_396 , V_396 , sizeof( V_186 -> V_396 ) ) ;
} else {
memset ( V_186 -> V_395 , 0 , sizeof( V_186 -> V_395 ) ) ;
memset ( V_186 -> V_396 , 0 , sizeof( V_186 -> V_396 ) ) ;
if ( V_393 && V_394 )
V_186 -> V_398 = 0x01 ;
}
F_23 ( L_27 , V_6 -> V_35 , V_131 ) ;
return 0 ;
}
struct V_399 * F_207 ( struct V_5 * V_6 , T_5 V_400 )
{
struct V_399 * V_401 ;
F_94 (adv_instance, &hdev->adv_instances, list) {
if ( V_401 -> V_400 == V_400 )
return V_401 ;
}
return NULL ;
}
struct V_399 * F_208 ( struct V_5 * V_6 , T_5 V_400 ) {
struct V_399 * V_402 ;
V_402 = F_207 ( V_6 , V_400 ) ;
if ( ! V_402 )
return NULL ;
if ( V_402 == F_209 ( & V_6 -> V_403 ,
struct V_399 , V_191 ) )
return F_210 ( & V_6 -> V_403 ,
struct V_399 , V_191 ) ;
else
return F_211 ( V_402 , V_191 ) ;
}
int F_212 ( struct V_5 * V_6 , T_5 V_400 )
{
struct V_399 * V_401 ;
V_401 = F_207 ( V_6 , V_400 ) ;
if ( ! V_401 )
return - V_386 ;
F_23 ( L_28 , V_6 -> V_35 , V_400 ) ;
if ( V_6 -> V_404 == V_400 && V_6 -> V_287 ) {
F_137 ( & V_6 -> V_288 ) ;
V_6 -> V_287 = 0 ;
}
F_103 ( & V_401 -> V_191 ) ;
F_104 ( V_401 ) ;
V_6 -> V_405 -- ;
return 0 ;
}
void F_213 ( struct V_5 * V_6 )
{
struct V_399 * V_401 , * V_181 ;
if ( V_6 -> V_287 ) {
F_137 ( & V_6 -> V_288 ) ;
V_6 -> V_287 = 0 ;
}
F_102 (adv_instance, n, &hdev->adv_instances, list) {
F_103 ( & V_401 -> V_191 ) ;
F_104 ( V_401 ) ;
}
V_6 -> V_405 = 0 ;
}
int F_214 ( struct V_5 * V_6 , T_5 V_400 , T_7 V_15 ,
T_6 V_406 , T_5 * V_407 ,
T_6 V_408 , T_5 * V_409 ,
T_6 V_46 , T_6 V_410 )
{
struct V_399 * V_401 ;
V_401 = F_207 ( V_6 , V_400 ) ;
if ( V_401 ) {
memset ( V_401 -> V_407 , 0 ,
sizeof( V_401 -> V_407 ) ) ;
memset ( V_401 -> V_409 , 0 ,
sizeof( V_401 -> V_409 ) ) ;
} else {
if ( V_6 -> V_405 >= V_411 ||
V_400 < 1 || V_400 > V_411 )
return - V_412 ;
V_401 = F_114 ( sizeof( * V_401 ) , V_201 ) ;
if ( ! V_401 )
return - V_237 ;
V_401 -> V_413 = true ;
V_401 -> V_400 = V_400 ;
F_111 ( & V_401 -> V_191 , & V_6 -> V_403 ) ;
V_6 -> V_405 ++ ;
}
V_401 -> V_15 = V_15 ;
V_401 -> V_406 = V_406 ;
V_401 -> V_408 = V_408 ;
if ( V_406 )
memcpy ( V_401 -> V_407 , V_407 , V_406 ) ;
if ( V_408 )
memcpy ( V_401 -> V_409 ,
V_409 , V_408 ) ;
V_401 -> V_46 = V_46 ;
V_401 -> V_414 = V_46 ;
if ( V_410 == 0 )
V_401 -> V_410 = V_415 ;
else
V_401 -> V_410 = V_410 ;
F_23 ( L_29 , V_6 -> V_35 , V_400 ) ;
return 0 ;
}
struct V_416 * F_215 ( struct V_189 * V_416 ,
T_11 * V_131 , T_5 type )
{
struct V_416 * V_373 ;
F_94 (b, bdaddr_list, list) {
if ( ! F_107 ( & V_373 -> V_131 , V_131 ) && V_373 -> V_368 == type )
return V_373 ;
}
return NULL ;
}
void F_216 ( struct V_189 * V_416 )
{
struct V_189 * V_128 , * V_181 ;
F_217 (p, n, bdaddr_list) {
struct V_416 * V_373 = F_218 ( V_128 , struct V_416 , V_191 ) ;
F_103 ( V_128 ) ;
F_104 ( V_373 ) ;
}
}
int F_219 ( struct V_189 * V_191 , T_11 * V_131 , T_5 type )
{
struct V_416 * V_417 ;
if ( ! F_107 ( V_131 , V_132 ) )
return - V_418 ;
if ( F_215 ( V_191 , V_131 , type ) )
return - V_419 ;
V_417 = F_114 ( sizeof( * V_417 ) , V_201 ) ;
if ( ! V_417 )
return - V_237 ;
F_78 ( & V_417 -> V_131 , V_131 ) ;
V_417 -> V_368 = type ;
F_111 ( & V_417 -> V_191 , V_191 ) ;
return 0 ;
}
int F_220 ( struct V_189 * V_191 , T_11 * V_131 , T_5 type )
{
struct V_416 * V_417 ;
if ( ! F_107 ( V_131 , V_132 ) ) {
F_216 ( V_191 ) ;
return 0 ;
}
V_417 = F_215 ( V_191 , V_131 , type ) ;
if ( ! V_417 )
return - V_386 ;
F_103 ( & V_417 -> V_191 ) ;
F_104 ( V_417 ) ;
return 0 ;
}
struct V_272 * F_221 ( struct V_5 * V_6 ,
T_11 * V_420 , T_5 V_366 )
{
struct V_272 * V_421 ;
F_94 (params, &hdev->le_conn_params, list) {
if ( F_107 ( & V_421 -> V_420 , V_420 ) == 0 &&
V_421 -> V_366 == V_366 ) {
return V_421 ;
}
}
return NULL ;
}
struct V_272 * F_222 ( struct V_189 * V_191 ,
T_11 * V_420 , T_5 V_366 )
{
struct V_272 * V_44 ;
F_94 (param, list, action) {
if ( F_107 ( & V_44 -> V_420 , V_420 ) == 0 &&
V_44 -> V_366 == V_366 )
return V_44 ;
}
return NULL ;
}
struct V_272 * F_223 ( struct V_5 * V_6 ,
T_11 * V_420 , T_5 V_366 )
{
struct V_272 * V_421 ;
V_421 = F_221 ( V_6 , V_420 , V_366 ) ;
if ( V_421 )
return V_421 ;
V_421 = F_114 ( sizeof( * V_421 ) , V_201 ) ;
if ( ! V_421 ) {
F_49 ( L_30 ) ;
return NULL ;
}
F_78 ( & V_421 -> V_420 , V_420 ) ;
V_421 -> V_366 = V_366 ;
F_111 ( & V_421 -> V_191 , & V_6 -> V_422 ) ;
F_105 ( & V_421 -> V_274 ) ;
V_421 -> V_423 = V_6 -> V_424 ;
V_421 -> V_425 = V_6 -> V_426 ;
V_421 -> V_427 = V_6 -> V_428 ;
V_421 -> V_429 = V_6 -> V_430 ;
V_421 -> V_431 = V_432 ;
F_23 ( L_31 , V_420 , V_366 ) ;
return V_421 ;
}
static void F_224 ( struct V_272 * V_421 )
{
if ( V_421 -> V_273 ) {
F_140 ( V_421 -> V_273 ) ;
F_141 ( V_421 -> V_273 ) ;
}
F_103 ( & V_421 -> V_274 ) ;
F_103 ( & V_421 -> V_191 ) ;
F_104 ( V_421 ) ;
}
void F_225 ( struct V_5 * V_6 , T_11 * V_420 , T_5 V_366 )
{
struct V_272 * V_421 ;
V_421 = F_221 ( V_6 , V_420 , V_366 ) ;
if ( ! V_421 )
return;
F_224 ( V_421 ) ;
F_99 ( V_6 ) ;
F_23 ( L_31 , V_420 , V_366 ) ;
}
void F_226 ( struct V_5 * V_6 )
{
struct V_272 * V_421 , * V_348 ;
F_102 (params, tmp, &hdev->le_conn_params, list) {
if ( V_421 -> V_431 != V_432 )
continue;
if ( V_421 -> V_433 ) {
V_421 -> V_431 = V_434 ;
continue;
}
F_103 ( & V_421 -> V_191 ) ;
F_104 ( V_421 ) ;
}
F_23 ( L_32 ) ;
}
void F_227 ( struct V_5 * V_6 )
{
struct V_272 * V_421 , * V_348 ;
F_102 (params, tmp, &hdev->le_conn_params, list)
F_224 ( V_421 ) ;
F_99 ( V_6 ) ;
F_23 ( L_33 ) ;
}
static void F_228 ( struct V_5 * V_6 , T_5 V_435 , T_6 V_34 )
{
if ( V_435 ) {
F_49 ( L_34 , V_435 ) ;
F_118 ( V_6 ) ;
F_98 ( V_6 , V_176 ) ;
F_121 ( V_6 ) ;
return;
}
}
static void F_229 ( struct V_5 * V_6 , T_5 V_435 ,
T_6 V_34 )
{
T_5 V_220 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_218 V_103 ;
int V_24 ;
if ( V_435 ) {
F_49 ( L_35 , V_435 ) ;
return;
}
V_6 -> V_171 . V_436 = 0 ;
switch ( V_6 -> V_171 . type ) {
case V_437 :
F_118 ( V_6 ) ;
F_98 ( V_6 , V_176 ) ;
F_121 ( V_6 ) ;
break;
case V_438 :
F_118 ( V_6 ) ;
if ( F_6 ( V_439 ,
& V_6 -> V_26 ) ) {
if ( ! F_6 ( V_219 , & V_6 -> V_15 ) &&
V_6 -> V_171 . V_172 != V_174 )
F_98 ( V_6 ,
V_176 ) ;
} else {
struct V_49 V_50 ;
F_101 ( V_6 ) ;
F_29 ( & V_50 , V_6 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
memcpy ( & V_103 . V_220 , V_220 , sizeof( V_103 . V_220 ) ) ;
V_103 . V_221 = V_440 ;
F_44 ( & V_50 , V_223 , sizeof( V_103 ) , & V_103 ) ;
V_24 = F_230 ( & V_50 , F_228 ) ;
if ( V_24 ) {
F_49 ( L_36 , V_24 ) ;
F_98 ( V_6 ,
V_176 ) ;
}
}
F_121 ( V_6 ) ;
break;
}
}
static void F_231 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 ,
V_284 . V_340 ) ;
struct V_49 V_50 ;
int V_24 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_145 ( & V_6 -> V_285 ) ;
F_29 ( & V_50 , V_6 ) ;
F_232 ( & V_50 ) ;
V_24 = F_230 ( & V_50 , F_229 ) ;
if ( V_24 )
F_49 ( L_37 , V_24 ) ;
}
static void F_233 ( struct V_5 * V_6 , T_5 V_435 ,
T_6 V_34 )
{
unsigned long V_46 , V_410 , V_436 , V_441 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( V_435 ) {
F_49 ( L_38 , V_435 ) ;
return;
}
if ( ! F_6 ( V_442 , & V_6 -> V_26 ) ||
! V_6 -> V_171 . V_436 )
return;
V_410 = V_6 -> V_171 . V_443 ;
V_436 = V_6 -> V_171 . V_436 ;
V_441 = V_206 ;
if ( V_441 - V_436 <= V_410 ) {
int V_444 ;
if ( V_441 >= V_436 )
V_444 = V_441 - V_436 ;
else
V_444 = V_445 - V_436 + V_441 ;
V_46 = V_410 - V_444 ;
} else {
V_46 = 0 ;
}
F_167 ( V_6 -> V_289 ,
& V_6 -> V_284 , V_46 ) ;
}
static void F_234 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 ,
V_285 . V_340 ) ;
struct V_49 V_50 ;
struct V_446 V_103 ;
int V_24 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( ! F_2 ( V_6 , V_447 ) )
return;
F_29 ( & V_50 , V_6 ) ;
F_232 ( & V_50 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_13 = V_448 ;
V_103 . V_449 = V_450 ;
F_44 ( & V_50 , V_451 , sizeof( V_103 ) , & V_103 ) ;
V_24 = F_230 ( & V_50 , F_233 ) ;
if ( V_24 )
F_49 ( L_39 , V_24 ) ;
}
void F_235 ( struct V_5 * V_6 , T_11 * V_131 ,
T_5 * V_368 )
{
if ( F_2 ( V_6 , V_452 ) ||
! F_107 ( & V_6 -> V_131 , V_132 ) ||
( ! F_2 ( V_6 , V_95 ) &&
F_107 ( & V_6 -> V_241 , V_132 ) ) ) {
F_78 ( V_131 , & V_6 -> V_241 ) ;
* V_368 = V_372 ;
} else {
F_78 ( V_131 , & V_6 -> V_131 ) ;
* V_368 = V_389 ;
}
}
struct V_5 * F_236 ( void )
{
struct V_5 * V_6 ;
V_6 = F_114 ( sizeof( * V_6 ) , V_201 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_319 = ( V_453 | V_454 | V_455 ) ;
V_6 -> V_456 = ( V_457 ) ;
V_6 -> V_315 = ( V_317 ) ;
V_6 -> V_458 = 0x01 ;
V_6 -> V_459 = 0x03 ;
V_6 -> V_460 = 0xffff ;
V_6 -> V_461 = V_462 ;
V_6 -> V_463 = V_462 ;
V_6 -> V_405 = 0 ;
V_6 -> V_404 = 0x00 ;
V_6 -> V_287 = 0 ;
V_6 -> V_464 = 800 ;
V_6 -> V_465 = 80 ;
V_6 -> V_466 = 0x07 ;
V_6 -> V_467 = 0x0800 ;
V_6 -> V_468 = 0x0800 ;
V_6 -> V_469 = 0x0060 ;
V_6 -> V_470 = 0x0030 ;
V_6 -> V_424 = 0x0028 ;
V_6 -> V_426 = 0x0038 ;
V_6 -> V_428 = 0x0000 ;
V_6 -> V_430 = 0x002a ;
V_6 -> V_471 = 0x001b ;
V_6 -> V_472 = 0x0148 ;
V_6 -> V_473 = 0x001b ;
V_6 -> V_474 = 0x0148 ;
V_6 -> V_475 = 0x001b ;
V_6 -> V_476 = 0x0148 ;
V_6 -> V_477 = V_478 ;
V_6 -> V_479 = V_480 ;
V_6 -> V_481 = V_482 ;
V_6 -> V_483 = V_484 ;
F_237 ( & V_6 -> V_485 ) ;
F_237 ( & V_6 -> V_486 ) ;
F_105 ( & V_6 -> V_487 ) ;
F_105 ( & V_6 -> V_488 ) ;
F_105 ( & V_6 -> V_489 ) ;
F_105 ( & V_6 -> V_490 ) ;
F_105 ( & V_6 -> V_377 ) ;
F_105 ( & V_6 -> V_384 ) ;
F_105 ( & V_6 -> V_385 ) ;
F_105 ( & V_6 -> V_397 ) ;
F_105 ( & V_6 -> V_491 ) ;
F_105 ( & V_6 -> V_422 ) ;
F_105 ( & V_6 -> V_492 ) ;
F_105 ( & V_6 -> V_493 ) ;
F_105 ( & V_6 -> V_494 . V_191 ) ;
F_105 ( & V_6 -> V_403 ) ;
F_238 ( & V_6 -> V_258 , V_495 ) ;
F_238 ( & V_6 -> V_257 , V_496 ) ;
F_238 ( & V_6 -> V_256 , V_497 ) ;
F_238 ( & V_6 -> V_341 , F_164 ) ;
F_238 ( & V_6 -> V_343 , F_170 ) ;
F_239 ( & V_6 -> V_268 , F_169 ) ;
F_239 ( & V_6 -> V_279 , F_171 ) ;
F_239 ( & V_6 -> V_284 , F_231 ) ;
F_239 ( & V_6 -> V_285 , F_234 ) ;
F_239 ( & V_6 -> V_288 , F_173 ) ;
F_240 ( & V_6 -> V_260 ) ;
F_240 ( & V_6 -> V_259 ) ;
F_240 ( & V_6 -> V_291 ) ;
F_241 ( & V_6 -> V_41 ) ;
F_239 ( & V_6 -> V_277 , F_201 ) ;
F_242 ( V_6 ) ;
F_243 ( V_6 ) ;
return V_6 ;
}
void F_244 ( struct V_5 * V_6 )
{
F_245 ( & V_6 -> V_266 ) ;
}
int F_246 ( struct V_5 * V_6 )
{
int V_168 , error ;
if ( ! V_6 -> V_243 || ! V_6 -> V_264 || ! V_6 -> V_498 )
return - V_18 ;
switch ( V_6 -> V_72 ) {
case V_73 :
V_168 = F_247 ( & V_499 , 0 , 0 , V_201 ) ;
break;
case V_74 :
V_168 = F_247 ( & V_499 , 1 , 0 , V_201 ) ;
break;
default:
return - V_18 ;
}
if ( V_168 < 0 )
return V_168 ;
sprintf ( V_6 -> V_35 , L_40 , V_168 ) ;
V_6 -> V_168 = V_168 ;
F_23 ( L_41 , V_6 , V_6 -> V_35 , V_6 -> V_334 ) ;
V_6 -> V_289 = F_248 ( L_5 , V_500 | V_501 |
V_502 , 1 , V_6 -> V_35 ) ;
if ( ! V_6 -> V_289 ) {
error = - V_237 ;
goto V_24;
}
V_6 -> V_269 = F_248 ( L_5 , V_500 | V_501 |
V_502 , 1 , V_6 -> V_35 ) ;
if ( ! V_6 -> V_269 ) {
F_249 ( V_6 -> V_289 ) ;
error = - V_237 ;
goto V_24;
}
if ( ! F_250 ( V_503 ) )
V_6 -> V_30 = F_251 ( V_6 -> V_35 , V_503 ) ;
F_252 ( & V_6 -> V_266 , L_5 , V_6 -> V_35 ) ;
error = F_253 ( & V_6 -> V_266 ) ;
if ( error < 0 )
goto V_504;
V_6 -> V_505 = F_254 ( V_6 -> V_35 , & V_6 -> V_266 ,
V_506 , & V_507 ,
V_6 ) ;
if ( V_6 -> V_505 ) {
if ( F_255 ( V_6 -> V_505 ) < 0 ) {
F_256 ( V_6 -> V_505 ) ;
V_6 -> V_505 = NULL ;
}
}
if ( V_6 -> V_505 && F_257 ( V_6 -> V_505 ) )
F_18 ( V_6 , V_239 ) ;
F_18 ( V_6 , V_156 ) ;
F_18 ( V_6 , V_267 ) ;
if ( V_6 -> V_72 == V_73 ) {
F_18 ( V_6 , V_95 ) ;
}
F_258 ( & V_167 ) ;
F_111 ( & V_6 -> V_191 , & V_508 ) ;
F_259 ( & V_167 ) ;
if ( F_6 ( V_159 , & V_6 -> V_26 ) )
F_18 ( V_6 , V_233 ) ;
F_128 ( V_6 , V_509 ) ;
F_95 ( V_6 ) ;
F_203 ( V_6 -> V_269 , & V_6 -> V_341 ) ;
return V_168 ;
V_504:
F_249 ( V_6 -> V_289 ) ;
F_249 ( V_6 -> V_269 ) ;
V_24:
F_260 ( & V_499 , V_6 -> V_168 ) ;
return error ;
}
void F_261 ( struct V_5 * V_6 )
{
int V_168 ;
F_23 ( L_41 , V_6 , V_6 -> V_35 , V_6 -> V_334 ) ;
F_18 ( V_6 , V_238 ) ;
V_168 = V_6 -> V_168 ;
F_258 ( & V_167 ) ;
F_103 ( & V_6 -> V_191 ) ;
F_259 ( & V_167 ) ;
F_143 ( V_6 ) ;
F_262 ( & V_6 -> V_341 ) ;
if ( ! F_6 ( V_247 , & V_6 -> V_15 ) &&
! F_2 ( V_6 , V_156 ) &&
! F_2 ( V_6 , V_157 ) ) {
F_118 ( V_6 ) ;
F_263 ( V_6 ) ;
F_121 ( V_6 ) ;
}
F_264 ( ! F_265 ( & V_6 -> V_487 ) ) ;
F_128 ( V_6 , V_510 ) ;
if ( V_6 -> V_505 ) {
F_266 ( V_6 -> V_505 ) ;
F_256 ( V_6 -> V_505 ) ;
}
F_267 ( & V_6 -> V_266 ) ;
F_268 ( V_6 -> V_30 ) ;
F_249 ( V_6 -> V_289 ) ;
F_249 ( V_6 -> V_269 ) ;
F_118 ( V_6 ) ;
F_216 ( & V_6 -> V_488 ) ;
F_216 ( & V_6 -> V_489 ) ;
F_175 ( V_6 ) ;
F_176 ( V_6 ) ;
F_180 ( V_6 ) ;
F_181 ( V_6 ) ;
F_205 ( V_6 ) ;
F_213 ( V_6 ) ;
F_216 ( & V_6 -> V_491 ) ;
F_227 ( V_6 ) ;
F_269 ( V_6 ) ;
F_121 ( V_6 ) ;
F_126 ( V_6 ) ;
F_260 ( & V_499 , V_168 ) ;
}
int F_270 ( struct V_5 * V_6 )
{
F_128 ( V_6 , V_511 ) ;
return 0 ;
}
int F_271 ( struct V_5 * V_6 )
{
F_128 ( V_6 , V_512 ) ;
return 0 ;
}
int F_272 ( struct V_5 * V_6 )
{
const T_5 V_513 [] = { V_514 , 0x01 , 0x00 } ;
struct V_10 * V_11 ;
V_11 = F_273 ( 3 , V_515 ) ;
if ( ! V_11 )
return - V_237 ;
F_274 ( V_11 ) -> V_319 = V_516 ;
memcpy ( F_275 ( V_11 , 3 ) , V_513 , 3 ) ;
return F_276 ( V_6 , V_11 ) ;
}
int F_276 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( ! V_6 || ( ! F_6 ( V_14 , & V_6 -> V_15 )
&& ! F_6 ( V_247 , & V_6 -> V_15 ) ) ) {
F_14 ( V_11 ) ;
return - V_517 ;
}
if ( F_274 ( V_11 ) -> V_319 != V_516 &&
F_274 ( V_11 ) -> V_319 != V_518 &&
F_274 ( V_11 ) -> V_319 != V_519 ) {
F_14 ( V_11 ) ;
return - V_18 ;
}
F_274 ( V_11 ) -> V_520 = 1 ;
F_277 ( V_11 ) ;
F_278 ( & V_6 -> V_260 , V_11 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_258 ) ;
return 0 ;
}
int F_279 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
F_274 ( V_11 ) -> V_319 = V_521 ;
F_277 ( V_11 ) ;
F_278 ( & V_6 -> V_260 , V_11 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_258 ) ;
return 0 ;
}
int F_280 ( struct V_522 * V_523 )
{
F_23 ( L_42 , V_523 , V_523 -> V_35 ) ;
F_281 ( & V_524 ) ;
F_282 ( & V_523 -> V_191 , & V_525 ) ;
F_283 ( & V_524 ) ;
return 0 ;
}
int F_284 ( struct V_522 * V_523 )
{
F_23 ( L_42 , V_523 , V_523 -> V_35 ) ;
F_281 ( & V_524 ) ;
F_103 ( & V_523 -> V_191 ) ;
F_283 ( & V_524 ) ;
return 0 ;
}
static void F_285 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
int V_24 ;
F_23 ( L_43 , V_6 -> V_35 , F_274 ( V_11 ) -> V_319 , V_11 -> V_526 ) ;
F_277 ( V_11 ) ;
F_286 ( V_6 , V_11 ) ;
if ( F_287 ( & V_6 -> V_527 ) ) {
F_288 ( V_6 , V_11 ) ;
}
F_289 ( V_11 ) ;
if ( ! F_6 ( V_27 , & V_6 -> V_15 ) ) {
F_14 ( V_11 ) ;
return;
}
V_24 = V_6 -> V_498 ( V_6 , V_11 ) ;
if ( V_24 < 0 ) {
F_49 ( L_44 , V_6 -> V_35 , V_24 ) ;
F_14 ( V_11 ) ;
}
}
int F_290 ( struct V_5 * V_6 , T_12 V_34 , T_8 V_43 ,
const void * V_44 )
{
struct V_10 * V_11 ;
F_23 ( L_45 , V_6 -> V_35 , V_34 , V_43 ) ;
V_11 = F_291 ( V_6 , V_34 , V_43 , V_44 ) ;
if ( ! V_11 ) {
F_49 ( L_46 , V_6 -> V_35 ) ;
return - V_237 ;
}
F_274 ( V_11 ) -> V_528 . V_529 = true ;
F_278 ( & V_6 -> V_259 , V_11 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_257 ) ;
return 0 ;
}
void * F_292 ( struct V_5 * V_6 , T_12 V_34 )
{
struct V_390 * V_530 ;
if ( ! V_6 -> V_262 )
return NULL ;
V_530 = ( void * ) V_6 -> V_262 -> V_186 ;
if ( V_530 -> V_34 != F_51 ( V_34 ) )
return NULL ;
F_23 ( L_47 , V_6 -> V_35 , V_34 ) ;
return V_6 -> V_262 -> V_186 + V_531 ;
}
struct V_10 * F_293 ( struct V_5 * V_6 , T_6 V_34 , T_7 V_43 ,
const void * V_44 , T_7 V_46 )
{
struct V_10 * V_11 ;
if ( ! F_6 ( V_14 , & V_6 -> V_15 ) )
return F_35 ( - V_16 ) ;
F_294 ( V_6 , L_48 , V_34 , V_43 ) ;
F_9 ( V_6 ) ;
V_11 = F_10 ( V_6 , V_34 , V_43 , V_44 , V_46 ) ;
F_11 ( V_6 ) ;
return V_11 ;
}
static void F_295 ( struct V_10 * V_11 , T_12 V_532 , T_12 V_15 )
{
struct V_533 * V_530 ;
int V_526 = V_11 -> V_526 ;
F_296 ( V_11 , V_534 ) ;
F_297 ( V_11 ) ;
V_530 = (struct V_533 * ) F_298 ( V_11 ) ;
V_530 -> V_532 = F_51 ( F_299 ( V_532 , V_15 ) ) ;
V_530 -> V_535 = F_51 ( V_526 ) ;
}
static void F_300 ( struct V_536 * V_537 , struct V_538 * V_539 ,
struct V_10 * V_11 , T_12 V_15 )
{
struct V_355 * V_273 = V_537 -> V_273 ;
struct V_5 * V_6 = V_273 -> V_6 ;
struct V_10 * V_191 ;
V_11 -> V_526 = F_301 ( V_11 ) ;
V_11 -> V_540 = 0 ;
F_274 ( V_11 ) -> V_319 = V_518 ;
switch ( V_6 -> V_72 ) {
case V_73 :
F_295 ( V_11 , V_273 -> V_532 , V_15 ) ;
break;
case V_74 :
F_295 ( V_11 , V_537 -> V_532 , V_15 ) ;
break;
default:
F_49 ( L_49 , V_6 -> V_35 , V_6 -> V_72 ) ;
return;
}
V_191 = F_302 ( V_11 ) -> V_541 ;
if ( ! V_191 ) {
F_23 ( L_50 , V_6 -> V_35 , V_11 , V_11 -> V_526 ) ;
F_278 ( V_539 , V_11 ) ;
} else {
F_23 ( L_51 , V_6 -> V_35 , V_11 , V_11 -> V_526 ) ;
F_302 ( V_11 ) -> V_541 = NULL ;
F_303 ( & V_539 -> V_485 ) ;
F_304 ( V_539 , V_11 ) ;
V_15 &= ~ V_542 ;
V_15 |= V_543 ;
do {
V_11 = V_191 ; V_191 = V_191 -> V_544 ;
F_274 ( V_11 ) -> V_319 = V_518 ;
F_295 ( V_11 , V_273 -> V_532 , V_15 ) ;
F_23 ( L_51 , V_6 -> V_35 , V_11 , V_11 -> V_526 ) ;
F_304 ( V_539 , V_11 ) ;
} while ( V_191 );
F_305 ( & V_539 -> V_485 ) ;
}
}
void F_306 ( struct V_536 * V_537 , struct V_10 * V_11 , T_12 V_15 )
{
struct V_5 * V_6 = V_537 -> V_273 -> V_6 ;
F_23 ( L_52 , V_6 -> V_35 , V_537 , V_15 ) ;
F_300 ( V_537 , & V_537 -> V_545 , V_11 , V_15 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_256 ) ;
}
void F_307 ( struct V_355 * V_273 , struct V_10 * V_11 )
{
struct V_5 * V_6 = V_273 -> V_6 ;
struct V_546 V_530 ;
F_23 ( L_53 , V_6 -> V_35 , V_11 -> V_526 ) ;
V_530 . V_532 = F_51 ( V_273 -> V_532 ) ;
V_530 . V_535 = V_11 -> V_526 ;
F_296 ( V_11 , V_547 ) ;
F_297 ( V_11 ) ;
memcpy ( F_298 ( V_11 ) , & V_530 , V_547 ) ;
F_274 ( V_11 ) -> V_319 = V_519 ;
F_278 ( & V_273 -> V_545 , V_11 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_256 ) ;
}
static struct V_355 * F_308 ( struct V_5 * V_6 , T_10 type ,
int * V_548 )
{
struct V_549 * V_550 = & V_6 -> V_494 ;
struct V_355 * V_273 = NULL , * V_551 ;
unsigned int V_207 = 0 , F_5 = ~ 0 ;
F_183 () ;
F_177 (c, &h->list, list) {
if ( V_551 -> type != type || F_309 ( & V_551 -> V_545 ) )
continue;
if ( V_551 -> V_172 != V_552 && V_551 -> V_172 != V_553 )
continue;
V_207 ++ ;
if ( V_551 -> V_391 < F_5 ) {
F_5 = V_551 -> V_391 ;
V_273 = V_551 ;
}
if ( F_310 ( V_6 , type ) == V_207 )
break;
}
F_184 () ;
if ( V_273 ) {
int V_554 , V_555 ;
switch ( V_273 -> type ) {
case V_556 :
V_554 = V_6 -> V_295 ;
break;
case V_557 :
case V_558 :
V_554 = V_6 -> V_296 ;
break;
case V_360 :
V_554 = V_6 -> V_335 ? V_6 -> V_297 : V_6 -> V_295 ;
break;
default:
V_554 = 0 ;
F_49 ( L_54 ) ;
}
V_555 = V_554 / V_207 ;
* V_548 = V_555 ? V_555 : 1 ;
} else
* V_548 = 0 ;
F_23 ( L_55 , V_273 , * V_548 ) ;
return V_273 ;
}
static void F_311 ( struct V_5 * V_6 , T_10 type )
{
struct V_549 * V_550 = & V_6 -> V_494 ;
struct V_355 * V_551 ;
F_49 ( L_56 , V_6 -> V_35 ) ;
F_183 () ;
F_177 (c, &h->list, list) {
if ( V_551 -> type == type && V_551 -> V_391 ) {
F_49 ( L_57 ,
V_6 -> V_35 , & V_551 -> V_559 ) ;
F_312 ( V_551 , V_560 ) ;
}
}
F_184 () ;
}
static struct V_536 * F_313 ( struct V_5 * V_6 , T_10 type ,
int * V_548 )
{
struct V_549 * V_550 = & V_6 -> V_494 ;
struct V_536 * V_537 = NULL ;
unsigned int V_207 = 0 , F_5 = ~ 0 , V_561 = 0 ;
struct V_355 * V_273 ;
int V_554 , V_555 , V_562 = 0 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_183 () ;
F_177 (conn, &h->list, list) {
struct V_536 * V_348 ;
if ( V_273 -> type != type )
continue;
if ( V_273 -> V_172 != V_552 && V_273 -> V_172 != V_553 )
continue;
V_562 ++ ;
F_177 (tmp, &conn->chan_list, list) {
struct V_10 * V_11 ;
if ( F_309 ( & V_348 -> V_545 ) )
continue;
V_11 = F_314 ( & V_348 -> V_545 ) ;
if ( V_11 -> V_563 < V_561 )
continue;
if ( V_11 -> V_563 > V_561 ) {
V_207 = 0 ;
F_5 = ~ 0 ;
V_561 = V_11 -> V_563 ;
}
V_207 ++ ;
if ( V_273 -> V_391 < F_5 ) {
F_5 = V_273 -> V_391 ;
V_537 = V_348 ;
}
}
if ( F_310 ( V_6 , type ) == V_562 )
break;
}
F_184 () ;
if ( ! V_537 )
return NULL ;
switch ( V_537 -> V_273 -> type ) {
case V_556 :
V_554 = V_6 -> V_295 ;
break;
case V_564 :
V_554 = V_6 -> V_565 ;
break;
case V_557 :
case V_558 :
V_554 = V_6 -> V_296 ;
break;
case V_360 :
V_554 = V_6 -> V_335 ? V_6 -> V_297 : V_6 -> V_295 ;
break;
default:
V_554 = 0 ;
F_49 ( L_54 ) ;
}
V_555 = V_554 / V_207 ;
* V_548 = V_555 ? V_555 : 1 ;
F_23 ( L_58 , V_537 , * V_548 ) ;
return V_537 ;
}
static void F_315 ( struct V_5 * V_6 , T_10 type )
{
struct V_549 * V_550 = & V_6 -> V_494 ;
struct V_355 * V_273 ;
int V_207 = 0 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
F_183 () ;
F_177 (conn, &h->list, list) {
struct V_536 * V_537 ;
if ( V_273 -> type != type )
continue;
if ( V_273 -> V_172 != V_552 && V_273 -> V_172 != V_553 )
continue;
V_207 ++ ;
F_177 (chan, &conn->chan_list, list) {
struct V_10 * V_11 ;
if ( V_537 -> V_391 ) {
V_537 -> V_391 = 0 ;
continue;
}
if ( F_309 ( & V_537 -> V_545 ) )
continue;
V_11 = F_314 ( & V_537 -> V_545 ) ;
if ( V_11 -> V_563 >= V_566 - 1 )
continue;
V_11 -> V_563 = V_566 - 1 ;
F_23 ( L_59 , V_537 , V_11 ,
V_11 -> V_563 ) ;
}
if ( F_310 ( V_6 , type ) == V_207 )
break;
}
F_184 () ;
}
static inline int F_316 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
return F_317 ( V_11 -> V_526 - V_534 , V_6 -> V_567 ) ;
}
static void F_318 ( struct V_5 * V_6 , unsigned int V_554 )
{
if ( ! F_2 ( V_6 , V_233 ) ) {
if ( ! V_554 && F_319 ( V_206 , V_6 -> V_568 +
V_569 ) )
F_311 ( V_6 , V_556 ) ;
}
}
static void F_320 ( struct V_5 * V_6 )
{
unsigned int V_554 = V_6 -> V_295 ;
struct V_536 * V_537 ;
struct V_10 * V_11 ;
int V_548 ;
F_318 ( V_6 , V_554 ) ;
while ( V_6 -> V_295 &&
( V_537 = F_313 ( V_6 , V_556 , & V_548 ) ) ) {
T_7 V_563 = ( F_314 ( & V_537 -> V_545 ) ) -> V_563 ;
while ( V_548 -- && ( V_11 = F_314 ( & V_537 -> V_545 ) ) ) {
F_23 ( L_60 , V_537 , V_11 ,
V_11 -> V_526 , V_11 -> V_563 ) ;
if ( V_11 -> V_563 < V_563 )
break;
V_11 = F_321 ( & V_537 -> V_545 ) ;
F_322 ( V_537 -> V_273 ,
F_274 ( V_11 ) -> V_570 ) ;
F_285 ( V_6 , V_11 ) ;
V_6 -> V_568 = V_206 ;
V_6 -> V_295 -- ;
V_537 -> V_391 ++ ;
V_537 -> V_273 -> V_391 ++ ;
}
}
if ( V_554 != V_6 -> V_295 )
F_315 ( V_6 , V_556 ) ;
}
static void F_323 ( struct V_5 * V_6 )
{
unsigned int V_554 = V_6 -> V_565 ;
struct V_536 * V_537 ;
struct V_10 * V_11 ;
int V_548 ;
T_5 type ;
F_318 ( V_6 , V_554 ) ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( V_6 -> V_72 == V_74 )
type = V_564 ;
else
type = V_556 ;
while ( V_6 -> V_565 > 0 &&
( V_537 = F_313 ( V_6 , type , & V_548 ) ) ) {
T_7 V_563 = ( F_314 ( & V_537 -> V_545 ) ) -> V_563 ;
while ( V_548 > 0 && ( V_11 = F_314 ( & V_537 -> V_545 ) ) ) {
int V_571 ;
F_23 ( L_60 , V_537 , V_11 ,
V_11 -> V_526 , V_11 -> V_563 ) ;
if ( V_11 -> V_563 < V_563 )
break;
V_11 = F_321 ( & V_537 -> V_545 ) ;
V_571 = F_316 ( V_6 , V_11 ) ;
if ( V_571 > V_6 -> V_565 )
return;
F_322 ( V_537 -> V_273 ,
F_274 ( V_11 ) -> V_570 ) ;
F_285 ( V_6 , V_11 ) ;
V_6 -> V_568 = V_206 ;
V_6 -> V_565 -= V_571 ;
V_548 -= V_571 ;
V_537 -> V_391 += V_571 ;
V_537 -> V_273 -> V_391 += V_571 ;
}
}
if ( V_554 != V_6 -> V_565 )
F_315 ( V_6 , type ) ;
}
static void F_324 ( struct V_5 * V_6 )
{
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( ! F_310 ( V_6 , V_556 ) && V_6 -> V_72 == V_73 )
return;
if ( ! F_310 ( V_6 , V_564 ) && V_6 -> V_72 == V_74 )
return;
switch ( V_6 -> V_59 ) {
case V_60 :
F_320 ( V_6 ) ;
break;
case V_64 :
F_323 ( V_6 ) ;
break;
}
}
static void F_325 ( struct V_5 * V_6 )
{
struct V_355 * V_273 ;
struct V_10 * V_11 ;
int V_548 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( ! F_310 ( V_6 , V_557 ) )
return;
while ( V_6 -> V_296 && ( V_273 = F_308 ( V_6 , V_557 , & V_548 ) ) ) {
while ( V_548 -- && ( V_11 = F_321 ( & V_273 -> V_545 ) ) ) {
F_23 ( L_61 , V_11 , V_11 -> V_526 ) ;
F_285 ( V_6 , V_11 ) ;
V_273 -> V_391 ++ ;
if ( V_273 -> V_391 == ~ 0 )
V_273 -> V_391 = 0 ;
}
}
}
static void F_326 ( struct V_5 * V_6 )
{
struct V_355 * V_273 ;
struct V_10 * V_11 ;
int V_548 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( ! F_310 ( V_6 , V_558 ) )
return;
while ( V_6 -> V_296 && ( V_273 = F_308 ( V_6 , V_558 ,
& V_548 ) ) ) {
while ( V_548 -- && ( V_11 = F_321 ( & V_273 -> V_545 ) ) ) {
F_23 ( L_61 , V_11 , V_11 -> V_526 ) ;
F_285 ( V_6 , V_11 ) ;
V_273 -> V_391 ++ ;
if ( V_273 -> V_391 == ~ 0 )
V_273 -> V_391 = 0 ;
}
}
}
static void F_327 ( struct V_5 * V_6 )
{
struct V_536 * V_537 ;
struct V_10 * V_11 ;
int V_548 , V_554 , V_348 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
if ( ! F_310 ( V_6 , V_360 ) )
return;
if ( ! F_2 ( V_6 , V_233 ) ) {
if ( ! V_6 -> V_297 && V_6 -> V_336 &&
F_319 ( V_206 , V_6 -> V_572 + V_573 * 45 ) )
F_311 ( V_6 , V_360 ) ;
}
V_554 = V_6 -> V_336 ? V_6 -> V_297 : V_6 -> V_295 ;
V_348 = V_554 ;
while ( V_554 && ( V_537 = F_313 ( V_6 , V_360 , & V_548 ) ) ) {
T_7 V_563 = ( F_314 ( & V_537 -> V_545 ) ) -> V_563 ;
while ( V_548 -- && ( V_11 = F_314 ( & V_537 -> V_545 ) ) ) {
F_23 ( L_60 , V_537 , V_11 ,
V_11 -> V_526 , V_11 -> V_563 ) ;
if ( V_11 -> V_563 < V_563 )
break;
V_11 = F_321 ( & V_537 -> V_545 ) ;
F_285 ( V_6 , V_11 ) ;
V_6 -> V_572 = V_206 ;
V_554 -- ;
V_537 -> V_391 ++ ;
V_537 -> V_273 -> V_391 ++ ;
}
}
if ( V_6 -> V_336 )
V_6 -> V_297 = V_554 ;
else
V_6 -> V_295 = V_554 ;
if ( V_554 != V_348 )
F_315 ( V_6 , V_360 ) ;
}
static void V_497 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 , V_256 ) ;
struct V_10 * V_11 ;
F_23 ( L_62 , V_6 -> V_35 , V_6 -> V_295 ,
V_6 -> V_296 , V_6 -> V_297 ) ;
if ( ! F_2 ( V_6 , V_231 ) ) {
F_324 ( V_6 ) ;
F_325 ( V_6 ) ;
F_326 ( V_6 ) ;
F_327 ( V_6 ) ;
}
while ( ( V_11 = F_321 ( & V_6 -> V_291 ) ) )
F_285 ( V_6 , V_11 ) ;
}
static void F_328 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_533 * V_530 = ( void * ) V_11 -> V_186 ;
struct V_355 * V_273 ;
T_12 V_532 , V_15 ;
F_329 ( V_11 , V_534 ) ;
V_532 = F_202 ( V_530 -> V_532 ) ;
V_15 = F_330 ( V_532 ) ;
V_532 = F_331 ( V_532 ) ;
F_23 ( L_63 , V_6 -> V_35 , V_11 -> V_526 ,
V_532 , V_15 ) ;
V_6 -> V_298 . V_574 ++ ;
F_118 ( V_6 ) ;
V_273 = F_332 ( V_6 , V_532 ) ;
F_121 ( V_6 ) ;
if ( V_273 ) {
F_322 ( V_273 , V_575 ) ;
F_333 ( V_273 , V_11 , V_15 ) ;
return;
} else {
F_49 ( L_64 ,
V_6 -> V_35 , V_532 ) ;
}
F_14 ( V_11 ) ;
}
static void F_334 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_546 * V_530 = ( void * ) V_11 -> V_186 ;
struct V_355 * V_273 ;
T_12 V_532 ;
F_329 ( V_11 , V_547 ) ;
V_532 = F_202 ( V_530 -> V_532 ) ;
F_23 ( L_65 , V_6 -> V_35 , V_11 -> V_526 , V_532 ) ;
V_6 -> V_298 . V_576 ++ ;
F_118 ( V_6 ) ;
V_273 = F_332 ( V_6 , V_532 ) ;
F_121 ( V_6 ) ;
if ( V_273 ) {
F_335 ( V_273 , V_11 ) ;
return;
} else {
F_49 ( L_66 ,
V_6 -> V_35 , V_532 ) ;
}
F_14 ( V_11 ) ;
}
static bool F_336 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
V_11 = F_314 ( & V_6 -> V_259 ) ;
if ( ! V_11 )
return true ;
return F_274 ( V_11 ) -> V_528 . V_529 ;
}
static void F_337 ( struct V_5 * V_6 )
{
struct V_390 * V_391 ;
struct V_10 * V_11 ;
T_6 V_34 ;
if ( ! V_6 -> V_262 )
return;
V_391 = ( void * ) V_6 -> V_262 -> V_186 ;
V_34 = F_202 ( V_391 -> V_34 ) ;
if ( V_34 == V_22 )
return;
V_11 = F_338 ( V_6 -> V_262 , V_201 ) ;
if ( ! V_11 )
return;
F_339 ( & V_6 -> V_259 , V_11 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_257 ) ;
}
void F_340 ( struct V_5 * V_6 , T_6 V_34 , T_5 V_435 ,
T_14 * V_577 ,
T_15 * V_578 )
{
struct V_10 * V_11 ;
unsigned long V_15 ;
F_23 ( L_67 , V_34 , V_435 ) ;
if ( ! F_292 ( V_6 , V_34 ) ) {
if ( F_6 ( V_247 , & V_6 -> V_15 ) && V_34 == V_22 )
F_337 ( V_6 ) ;
return;
}
if ( ! V_435 && ! F_336 ( V_6 ) )
return;
if ( F_274 ( V_6 -> V_262 ) -> V_528 . V_577 ) {
* V_577 = F_274 ( V_6 -> V_262 ) -> V_528 . V_577 ;
return;
}
if ( F_274 ( V_6 -> V_262 ) -> V_528 . V_578 ) {
* V_578 = F_274 ( V_6 -> V_262 ) -> V_528 . V_578 ;
return;
}
F_341 ( & V_6 -> V_259 . V_485 , V_15 ) ;
while ( ( V_11 = F_342 ( & V_6 -> V_259 ) ) ) {
if ( F_274 ( V_11 ) -> V_528 . V_529 ) {
F_343 ( & V_6 -> V_259 , V_11 ) ;
break;
}
* V_577 = F_274 ( V_11 ) -> V_528 . V_577 ;
* V_578 = F_274 ( V_11 ) -> V_528 . V_578 ;
F_14 ( V_11 ) ;
}
F_344 ( & V_6 -> V_259 . V_485 , V_15 ) ;
}
static void V_495 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 , V_258 ) ;
struct V_10 * V_11 ;
F_23 ( L_5 , V_6 -> V_35 ) ;
while ( ( V_11 = F_321 ( & V_6 -> V_260 ) ) ) {
F_286 ( V_6 , V_11 ) ;
if ( F_287 ( & V_6 -> V_527 ) ) {
F_288 ( V_6 , V_11 ) ;
}
if ( F_2 ( V_6 , V_231 ) ) {
F_14 ( V_11 ) ;
continue;
}
if ( F_6 ( V_247 , & V_6 -> V_15 ) ) {
switch ( F_274 ( V_11 ) -> V_319 ) {
case V_518 :
case V_519 :
F_14 ( V_11 ) ;
continue;
}
}
switch ( F_274 ( V_11 ) -> V_319 ) {
case V_516 :
F_23 ( L_68 , V_6 -> V_35 ) ;
F_345 ( V_6 , V_11 ) ;
break;
case V_518 :
F_23 ( L_69 , V_6 -> V_35 ) ;
F_328 ( V_6 , V_11 ) ;
break;
case V_519 :
F_23 ( L_70 , V_6 -> V_35 ) ;
F_334 ( V_6 , V_11 ) ;
break;
default:
F_14 ( V_11 ) ;
break;
}
}
}
static void V_496 ( struct V_339 * V_340 )
{
struct V_5 * V_6 = F_165 ( V_340 , struct V_5 , V_257 ) ;
struct V_10 * V_11 ;
F_23 ( L_71 , V_6 -> V_35 ,
F_287 ( & V_6 -> V_246 ) , F_346 ( & V_6 -> V_259 ) ) ;
if ( F_287 ( & V_6 -> V_246 ) ) {
V_11 = F_321 ( & V_6 -> V_259 ) ;
if ( ! V_11 )
return;
F_14 ( V_6 -> V_262 ) ;
V_6 -> V_262 = F_338 ( V_11 , V_201 ) ;
if ( V_6 -> V_262 ) {
F_347 ( & V_6 -> V_246 ) ;
F_285 ( V_6 , V_11 ) ;
if ( F_6 ( V_58 , & V_6 -> V_15 ) )
F_137 ( & V_6 -> V_277 ) ;
else
F_348 ( & V_6 -> V_277 ,
V_21 ) ;
} else {
F_339 ( & V_6 -> V_259 , V_11 ) ;
F_203 ( V_6 -> V_289 , & V_6 -> V_257 ) ;
}
}
}
