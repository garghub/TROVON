static unsigned short F_1 ( int V_1 )
{
if ( V_1 > 0xff ) {
switch ( V_1 - 0xff ) {
case V_2 : return V_3 ;
case V_4 : return V_3 ;
case V_5 : return V_6 ;
case V_7 : return V_8 ;
}
}
return V_9 ;
}
static unsigned short F_2 ( int V_10 )
{
switch ( V_10 ) {
case 0x82 : return V_11 ;
case 0x14 : return V_12 ;
case 0x12 : return V_13 ;
case 0x11 : return V_14 ;
case 0x24 : return V_15 ;
case 0x22 : return V_16 ;
case 0x21 : return V_17 ;
case 0x44 : return V_18 ;
case 0x42 : return V_19 ;
case 0x41 : return V_20 ;
case 0x81 : return V_21 ;
case 0x84 : return V_22 ;
case 0x88 : return V_23 ;
case 0x48 : return V_24 ;
case 0x28 : return V_25 ;
case 0x18 : return V_26 ;
default: return F_1 ( V_10 ) ;
}
}
static unsigned short F_3 ( int V_10 )
{
switch ( V_10 ) {
case 0x11 : return V_11 ;
case 0x21 : return V_12 ;
case 0x41 : return V_13 ;
case 0x81 : return V_14 ;
case 0x12 : return V_15 ;
case 0x22 : return V_16 ;
case 0x42 : return V_17 ;
case 0x82 : return V_18 ;
case 0x14 : return V_19 ;
case 0x24 : return V_20 ;
case 0x44 : return V_21 ;
case 0x84 : return V_22 ;
case 0x18 : return V_23 ;
case 0x28 : return V_24 ;
case 0x48 : return V_27 ;
case 0x88 : return V_28 ;
default: return F_1 ( V_10 ) ;
}
}
static unsigned short F_4 ( int V_10 )
{
switch ( V_10 ) {
case 0x11 : return V_11 ;
case 0x21 : return V_12 ;
case 0x41 : return V_13 ;
case 0x81 : return V_14 ;
case 0x12 : return V_15 ;
case 0x22 : return V_16 ;
case 0x42 : return V_17 ;
case 0x82 : return V_18 ;
case 0x14 : return V_19 ;
case 0x24 : return V_20 ;
case 0x44 : return V_21 ;
case 0x84 : return V_22 ;
case 0x18 : return V_23 ;
case 0x28 : return V_24 ;
case 0x48 : return V_25 ;
case 0x88 : return V_26 ;
default: return F_1 ( V_10 ) ;
}
}
static unsigned short F_5 ( int V_10 )
{
switch ( V_10 ) {
case 0x82 : return V_11 ;
case 0x11 : return V_12 ;
case 0x12 : return V_13 ;
case 0x14 : return V_14 ;
case 0x21 : return V_15 ;
case 0x22 : return V_16 ;
case 0x24 : return V_17 ;
case 0x41 : return V_18 ;
case 0x42 : return V_19 ;
case 0x44 : return V_20 ;
case 0x84 : return V_21 ;
case 0x81 : return V_22 ;
case 0x18 : return V_23 ;
case 0x28 : return V_24 ;
case 0x48 : return V_25 ;
case 0x88 : return V_26 ;
default: return F_1 ( V_10 ) ;
}
}
static void F_6 ( struct V_29 * V_30 , int V_31 )
{
struct V_32 * V_33 = V_30 -> V_33 ;
if ( V_30 -> V_34 >= 0 ) {
F_7 ( V_33 , V_30 -> V_34 , 0 ) ;
}
V_30 -> V_34 = V_31 ;
if ( V_31 >= 0 ) {
F_7 ( V_33 , V_31 , 1 ) ;
}
F_8 ( V_33 ) ;
}
static void F_9 ( struct V_29 * V_30 )
{
int error ;
if ( V_30 -> V_35 )
V_30 -> V_36 -> V_37 [ V_38 ] |= V_39 ;
else
V_30 -> V_36 -> V_37 [ V_38 ] &= ~ V_39 ;
error = F_10 ( V_30 -> V_40 , V_41 ) ;
if ( error )
F_11 ( & V_30 -> V_42 -> V_30 ,
L_1 ,
V_43 , error ) ;
}
static void F_12 ( struct V_44 * V_44 )
{
struct V_29 * V_30 = V_44 -> V_45 ;
const int V_46 = V_44 -> V_46 ;
int error ;
F_13 ( & V_30 -> V_42 -> V_30 , L_2 ,
V_30 -> V_47 -> V_37 [ 0 ] ,
V_30 -> V_47 -> V_37 [ 1 ] ,
V_30 -> V_47 -> V_37 [ 2 ] ,
V_30 -> V_47 -> V_37 [ 3 ] ,
V_30 -> V_48 ) ;
if ( V_46 ) {
if ( V_46 == - V_49 )
return;
F_14 ( & V_30 -> V_42 -> V_30 , L_3 ,
V_43 , V_46 ) ;
goto V_50;
}
if ( V_30 -> V_47 -> V_37 [ V_51 ] & 0x0f ) {
const int V_1 = ( V_30 -> V_47 -> V_37 [ V_51 ] & 0x0f ) ;
F_6 ( V_30 , V_30 -> V_52 [ 0xff + V_1 ] ) ;
}
if ( V_30 -> V_48 == 0xf ) {
if ( ( V_30 -> V_53 & 0xf0 ) == ( V_30 -> V_47 -> V_37 [ V_54 ] & 0xf0 ) )
goto V_50;
V_30 -> V_53 = V_30 -> V_47 -> V_37 [ V_54 ] & 0xf0 ;
V_30 -> V_48 = 0x1 ;
} else {
F_6 ( V_30 , V_30 -> V_52 [ V_30 -> V_47 -> V_37 [ V_54 ] ] ) ;
V_30 -> V_48 <<= 1 ;
if ( V_30 -> V_48 > 0x8 )
V_30 -> V_48 = 0xf ;
}
V_50:
F_15 ( & V_30 -> V_55 ) ;
V_30 -> V_56 = 0 ;
if ( F_16 ( ! V_30 -> V_57 ) ) {
if ( V_30 -> V_35 )
V_30 -> V_36 -> V_37 [ V_38 ] |= V_39 ;
else
V_30 -> V_36 -> V_37 [ V_38 ] &= ~ V_39 ;
V_30 -> V_36 -> V_37 [ V_58 ] = V_30 -> V_48 ;
V_30 -> V_36 -> V_37 [ V_59 ] = V_30 -> V_48 ;
V_30 -> V_60 = 0 ;
V_30 -> V_61 = 1 ;
error = F_10 ( V_30 -> V_40 , V_41 ) ;
if ( error )
F_11 ( & V_30 -> V_42 -> V_30 ,
L_1 ,
V_43 , error ) ;
}
F_17 ( & V_30 -> V_55 ) ;
}
static void F_18 ( struct V_44 * V_44 )
{
struct V_29 * V_30 = V_44 -> V_45 ;
const int V_46 = V_44 -> V_46 ;
int error ;
F_13 ( & V_30 -> V_42 -> V_30 , L_4 ,
V_30 -> V_36 -> V_37 [ 0 ] ,
V_30 -> V_36 -> V_37 [ 1 ] ,
V_30 -> V_36 -> V_37 [ 2 ] ,
V_30 -> V_36 -> V_37 [ 3 ] ) ;
if ( V_46 ) {
if ( V_46 == - V_49 )
return;
F_14 ( & V_30 -> V_42 -> V_30 , L_3 ,
V_43 , V_46 ) ;
}
F_15 ( & V_30 -> V_55 ) ;
V_30 -> V_61 = 0 ;
if ( F_16 ( ! V_30 -> V_57 ) ) {
if ( V_30 -> V_60 || V_46 ) {
V_30 -> V_60 = 0 ;
V_30 -> V_61 = 1 ;
F_9 ( V_30 ) ;
} else if ( F_16 ( ! V_30 -> V_56 ) ) {
V_30 -> V_56 = 1 ;
error = F_10 ( V_30 -> V_62 , V_41 ) ;
if ( error )
F_11 ( & V_30 -> V_42 -> V_30 ,
L_5 ,
V_43 , error ) ;
}
}
F_17 ( & V_30 -> V_55 ) ;
}
static void F_19 ( struct V_29 * V_30 )
{
unsigned long V_63 ;
F_20 ( & V_30 -> V_55 , V_63 ) ;
if ( V_30 -> V_61 ) {
V_30 -> V_60 = 1 ;
} else {
V_30 -> V_61 = 1 ;
F_9 ( V_30 ) ;
}
F_21 ( & V_30 -> V_55 , V_63 ) ;
}
static void F_22 ( struct V_29 * V_30 , int V_64 )
{
int error ;
if ( V_64 )
V_30 -> V_36 -> V_37 [ V_38 ] |= V_39 ;
else
V_30 -> V_36 -> V_37 [ V_38 ] &= ~ V_39 ;
error = F_23 ( V_30 -> V_65 ,
F_24 ( V_30 -> V_65 , 0 ) ,
V_30 -> V_66 -> V_67 ,
V_30 -> V_66 -> V_68 ,
F_25 ( V_30 -> V_66 -> V_69 ) ,
F_25 ( V_30 -> V_66 -> V_70 ) ,
V_30 -> V_36 ,
V_71 , V_72 ) ;
if ( error < 0 && error != - V_73 )
F_11 ( & V_30 -> V_42 -> V_30 , L_6 ,
V_43 , error ) ;
}
static void F_26 ( struct V_29 * V_30 )
{
V_30 -> V_57 = 1 ;
F_27 () ;
F_28 ( V_30 -> V_40 ) ;
F_28 ( V_30 -> V_62 ) ;
F_22 ( V_30 , 0 ) ;
V_30 -> V_57 = 0 ;
F_27 () ;
}
static void F_29 ( struct V_29 * V_30 )
{
if ( V_30 -> V_74 ) {
F_19 ( V_30 ) ;
}
}
static int F_30 ( struct V_32 * V_33 )
{
struct V_29 * V_30 = F_31 ( V_33 ) ;
int error ;
error = F_32 ( V_30 -> V_42 ) ;
if ( error < 0 ) {
F_11 ( & V_33 -> V_30 , L_7 ,
V_43 , error ) ;
return error ;
}
F_33 ( & V_30 -> V_75 ) ;
V_30 -> V_35 = 0 ;
V_30 -> V_34 = - 1 ;
V_30 -> V_48 = 0xf ;
V_30 -> V_36 -> V_37 [ V_38 ] = V_76 ;
V_30 -> V_36 -> V_37 [ V_58 ] = V_30 -> V_48 ;
V_30 -> V_36 -> V_37 [ V_59 ] = V_30 -> V_48 ;
V_30 -> V_36 -> V_37 [ V_77 ] = 0x00 ;
error = F_10 ( V_30 -> V_40 , V_78 ) ;
if ( error )
F_11 ( & V_30 -> V_42 -> V_30 , L_1 ,
V_43 , error ) ;
else
V_30 -> V_74 = 1 ;
F_34 ( & V_30 -> V_75 ) ;
if ( error )
F_35 ( V_30 -> V_42 ) ;
return error ;
}
static void F_36 ( struct V_32 * V_33 )
{
struct V_29 * V_30 = F_31 ( V_33 ) ;
F_33 ( & V_30 -> V_75 ) ;
F_26 ( V_30 ) ;
V_30 -> V_74 = 0 ;
F_34 ( & V_30 -> V_75 ) ;
F_35 ( V_30 -> V_42 ) ;
}
static int F_37 ( struct V_32 * V_33 , unsigned int type ,
unsigned int V_1 , int V_79 )
{
struct V_29 * V_30 = F_31 ( V_33 ) ;
F_13 ( & V_30 -> V_42 -> V_30 ,
L_8 , type , V_1 , V_79 ) ;
if ( type != V_80 )
return - V_81 ;
switch ( V_1 ) {
case V_82 :
case V_83 :
V_30 -> V_35 = ! ! V_79 ;
if ( ! V_30 -> V_84 )
F_19 ( V_30 ) ;
return 0 ;
default:
return - V_81 ;
}
}
static void F_38 ( struct V_29 * V_30 )
{
F_39 ( V_30 -> V_66 ) ;
if ( V_30 -> V_36 )
F_40 ( V_30 -> V_65 , V_71 ,
V_30 -> V_36 , V_30 -> V_85 ) ;
if ( V_30 -> V_47 )
F_40 ( V_30 -> V_65 , V_71 ,
V_30 -> V_47 , V_30 -> V_86 ) ;
F_41 ( V_30 -> V_62 ) ;
F_41 ( V_30 -> V_40 ) ;
F_39 ( V_30 ) ;
}
static void F_42 ( struct V_87 * V_88 )
{
struct V_29 * V_30 = F_43 ( V_88 ) ;
F_44 ( V_88 , NULL ) ;
F_45 ( V_30 -> V_33 ) ;
F_38 ( V_30 ) ;
}
static int F_46 ( struct V_87 * V_42 ,
const struct V_89 * V_90 )
{
struct V_91 * V_65 = F_47 ( V_42 ) ;
struct V_92 * V_93 = (struct V_92 * ) V_90 -> V_92 ;
struct V_94 * V_88 ;
struct V_95 * V_96 ;
struct V_29 * V_30 ;
struct V_32 * V_32 = NULL ;
int V_97 , V_98 , V_99 ;
int error = - V_100 ;
V_88 = V_42 -> V_101 ;
V_96 = & V_88 -> V_96 [ 0 ] . V_102 ;
if ( ! F_48 ( V_96 ) )
return - V_103 ;
V_30 = F_49 ( sizeof( * V_30 ) , V_78 ) ;
if ( ! V_30 )
return - V_100 ;
F_50 ( & V_30 -> V_55 ) ;
F_51 ( & V_30 -> V_75 ) ;
V_30 -> V_65 = V_65 ;
V_30 -> V_42 = V_42 ;
V_30 -> V_33 = V_32 = F_52 () ;
if ( ! V_32 )
goto V_104;
V_30 -> V_47 = F_53 ( V_65 , V_71 ,
V_78 , & V_30 -> V_86 ) ;
if ( ! V_30 -> V_47 )
goto V_104;
V_30 -> V_36 = F_53 ( V_65 , V_71 ,
V_78 , & V_30 -> V_85 ) ;
if ( ! V_30 -> V_36 )
goto V_104;
V_30 -> V_66 = F_54 ( sizeof( * ( V_30 -> V_66 ) ) , V_78 ) ;
if ( ! V_30 -> V_66 )
goto V_104;
V_30 -> V_62 = F_55 ( 0 , V_78 ) ;
if ( ! V_30 -> V_62 )
goto V_104;
V_30 -> V_40 = F_55 ( 0 , V_78 ) ;
if ( ! V_30 -> V_40 )
goto V_104;
V_98 = F_56 ( V_65 , V_96 -> V_105 ) ;
V_97 = F_57 ( V_65 , V_98 , F_58 ( V_98 ) ) ;
if ( V_97 != V_71 )
F_11 ( & V_42 -> V_30 , L_9 ,
V_97 , V_71 ) ;
F_59 ( V_30 -> V_62 , V_65 , V_98 , V_30 -> V_47 ,
V_71 ,
F_12 , V_30 , V_96 -> V_106 ) ;
V_30 -> V_62 -> V_107 = V_30 -> V_86 ;
V_30 -> V_62 -> V_108 |= V_109 ;
V_30 -> V_62 -> V_30 = V_65 ;
V_30 -> V_66 -> V_68 = V_110 | V_111 |
V_112 ;
V_30 -> V_66 -> V_67 = V_113 ;
V_30 -> V_66 -> V_69 = F_60 ( 0x200 ) ;
V_30 -> V_66 -> V_70 = F_60 ( V_88 -> V_102 . V_114 ) ;
V_30 -> V_66 -> V_115 = F_60 ( V_71 ) ;
F_61 ( V_30 -> V_40 , V_65 , F_24 ( V_65 , 0 ) ,
( void * ) V_30 -> V_66 , V_30 -> V_36 , V_71 ,
F_18 , V_30 ) ;
V_30 -> V_40 -> V_107 = V_30 -> V_85 ;
V_30 -> V_40 -> V_108 |= V_109 ;
V_30 -> V_40 -> V_30 = V_65 ;
F_62 ( V_65 , V_30 -> V_116 , sizeof( V_30 -> V_116 ) ) ;
F_63 ( V_30 -> V_116 , L_10 , sizeof( V_30 -> V_116 ) ) ;
V_32 -> V_117 = V_93 -> V_117 ;
V_32 -> V_116 = V_30 -> V_116 ;
F_64 ( V_65 , & V_32 -> V_90 ) ;
V_32 -> V_30 . V_118 = & V_42 -> V_30 ;
F_65 ( V_32 , V_30 ) ;
V_32 -> V_74 = F_30 ;
V_32 -> V_119 = F_36 ;
V_32 -> V_120 = F_37 ;
V_32 -> V_121 = V_30 -> V_52 ;
V_32 -> V_122 = sizeof( unsigned char ) ;
V_32 -> V_123 = F_66 ( V_30 -> V_52 ) ;
V_32 -> V_124 [ 0 ] = F_67 ( V_125 ) | F_67 ( V_80 ) ;
V_32 -> V_126 [ 0 ] = F_67 ( V_83 ) | F_67 ( V_82 ) ;
for ( V_99 = 0 ; V_99 < V_127 ; V_99 ++ ) {
unsigned short V_128 = V_52 ( V_99 ) ;
V_30 -> V_52 [ V_99 ] = V_128 ;
F_68 ( V_128 , V_32 -> V_48 ) ;
}
F_69 ( V_9 , V_32 -> V_48 ) ;
error = F_70 ( V_30 -> V_33 ) ;
if ( error )
goto V_104;
F_44 ( V_42 , V_30 ) ;
return 0 ;
V_104:
F_71 ( V_32 ) ;
F_38 ( V_30 ) ;
return error ;
}
static int F_72 ( struct V_87 * V_42 , T_1 V_129 )
{
struct V_29 * V_30 = F_43 ( V_42 ) ;
F_73 ( & V_42 -> V_30 , L_11 , V_129 . V_120 ) ;
F_33 ( & V_30 -> V_75 ) ;
F_26 ( V_30 ) ;
F_34 ( & V_30 -> V_75 ) ;
return 0 ;
}
static int F_74 ( struct V_87 * V_42 )
{
struct V_29 * V_30 = F_43 ( V_42 ) ;
F_73 ( & V_42 -> V_30 , L_12 ) ;
F_33 ( & V_30 -> V_75 ) ;
F_29 ( V_30 ) ;
F_34 ( & V_30 -> V_75 ) ;
return 0 ;
}
static int F_75 ( struct V_87 * V_42 )
{
struct V_29 * V_30 = F_43 ( V_42 ) ;
F_33 ( & V_30 -> V_75 ) ;
V_30 -> V_84 = 1 ;
F_27 () ;
F_26 ( V_30 ) ;
return 0 ;
}
static int F_76 ( struct V_87 * V_42 )
{
struct V_29 * V_30 = F_43 ( V_42 ) ;
V_30 -> V_84 = 0 ;
F_27 () ;
F_29 ( V_30 ) ;
F_34 ( & V_30 -> V_75 ) ;
return 0 ;
}
static int T_2 F_77 ( void )
{
if ( ! strcasecmp ( V_130 , L_13 ) ) {
V_52 = F_2 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_15 ) ;
} else if ( ! strcasecmp ( V_130 , L_16 ) ) {
V_52 = F_3 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_17 ) ;
} else if ( ! strcasecmp ( V_130 , L_18 ) ) {
V_52 = F_4 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_19 ) ;
} else if ( ! strcasecmp ( V_130 , L_20 ) ) {
V_52 = F_5 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_21 ) ;
} else {
F_78 (KERN_ERR KBUILD_MODNAME L_14
L_22 , phone) ;
return - V_81 ;
}
return 0 ;
}
static int T_2 F_79 ( void )
{
int V_131 ;
V_131 = F_77 () ;
if ( V_131 )
return V_131 ;
V_131 = F_80 ( & V_132 ) ;
if ( V_131 )
return V_131 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
DRIVER_DESC L_14 DRIVER_VERSION L_23 DRIVER_AUTHOR L_24 ) ;
return 0 ;
}
static void T_3 F_81 ( void )
{
F_82 ( & V_132 ) ;
}
