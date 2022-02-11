static unsigned short F_1 ( int V_1 )
{
if ( V_1 > 0xff ) {
switch ( V_1 - 0xff ) {
case V_2 : return V_3 ;
case V_4 : return V_5 ;
case V_6 : return V_7 ;
case V_8 : return V_9 ;
}
}
return V_10 ;
}
static unsigned short F_2 ( int V_11 )
{
switch ( V_11 ) {
case 0x82 : return V_12 ;
case 0x14 : return V_13 ;
case 0x12 : return V_14 ;
case 0x11 : return V_15 ;
case 0x24 : return V_16 ;
case 0x22 : return V_17 ;
case 0x21 : return V_18 ;
case 0x44 : return V_19 ;
case 0x42 : return V_20 ;
case 0x41 : return V_21 ;
case 0x81 : return V_22 ;
case 0x84 : return V_23 ;
case 0x88 : return V_24 ;
case 0x48 : return V_25 ;
case 0x28 : return V_26 ;
case 0x18 : return V_27 ;
default: return F_1 ( V_11 ) ;
}
}
static unsigned short F_3 ( int V_11 )
{
switch ( V_11 ) {
case 0x11 : return V_12 ;
case 0x21 : return V_13 ;
case 0x41 : return V_14 ;
case 0x81 : return V_15 ;
case 0x12 : return V_16 ;
case 0x22 : return V_17 ;
case 0x42 : return V_18 ;
case 0x82 : return V_19 ;
case 0x14 : return V_20 ;
case 0x24 : return V_21 ;
case 0x44 : return V_22 ;
case 0x84 : return V_23 ;
case 0x18 : return V_24 ;
case 0x28 : return V_25 ;
case 0x48 : return V_28 ;
case 0x88 : return V_29 ;
default: return F_1 ( V_11 ) ;
}
}
static unsigned short F_4 ( int V_11 )
{
switch ( V_11 ) {
case 0x11 : return V_12 ;
case 0x21 : return V_13 ;
case 0x41 : return V_14 ;
case 0x81 : return V_15 ;
case 0x12 : return V_16 ;
case 0x22 : return V_17 ;
case 0x42 : return V_18 ;
case 0x82 : return V_19 ;
case 0x14 : return V_20 ;
case 0x24 : return V_21 ;
case 0x44 : return V_22 ;
case 0x84 : return V_23 ;
case 0x18 : return V_24 ;
case 0x28 : return V_25 ;
case 0x48 : return V_26 ;
case 0x88 : return V_27 ;
default: return F_1 ( V_11 ) ;
}
}
static unsigned short F_5 ( int V_11 )
{
switch ( V_11 ) {
case 0x82 : return V_12 ;
case 0x11 : return V_13 ;
case 0x12 : return V_14 ;
case 0x14 : return V_15 ;
case 0x21 : return V_16 ;
case 0x22 : return V_17 ;
case 0x24 : return V_18 ;
case 0x41 : return V_19 ;
case 0x42 : return V_20 ;
case 0x44 : return V_21 ;
case 0x84 : return V_22 ;
case 0x81 : return V_23 ;
case 0x18 : return V_24 ;
case 0x28 : return V_25 ;
case 0x48 : return V_26 ;
case 0x88 : return V_27 ;
default: return F_1 ( V_11 ) ;
}
}
static void F_6 ( struct V_30 * V_31 , int V_32 )
{
struct V_33 * V_34 = V_31 -> V_34 ;
if ( V_31 -> V_35 >= 0 ) {
F_7 ( V_34 , V_31 -> V_35 , 0 ) ;
}
V_31 -> V_35 = V_32 ;
if ( V_32 >= 0 ) {
F_7 ( V_34 , V_32 , 1 ) ;
}
F_8 ( V_34 ) ;
}
static void F_9 ( struct V_30 * V_31 )
{
static const T_1 V_36 = V_2 | V_4 ;
struct V_33 * V_34 = V_31 -> V_34 ;
T_1 V_37 = V_31 -> V_38 -> V_39 [ V_40 ] ;
unsigned short V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_41 = V_31 -> V_43 [ 0xff + F_10 ( V_42 ) ] ;
if ( V_41 == V_10 )
continue;
F_7 ( V_34 , V_41 , V_37 & F_10 ( V_42 ) ) ;
if ( V_37 & V_36 & F_10 ( V_42 ) ) {
F_8 ( V_34 ) ;
F_7 ( V_34 , V_41 , 0 ) ;
}
}
F_8 ( V_34 ) ;
}
static void F_11 ( struct V_30 * V_31 )
{
int error ;
if ( V_31 -> V_44 )
V_31 -> V_45 -> V_39 [ V_46 ] |= V_47 ;
else
V_31 -> V_45 -> V_39 [ V_46 ] &= ~ V_47 ;
error = F_12 ( V_31 -> V_48 , V_49 ) ;
if ( error )
F_13 ( & V_31 -> V_50 -> V_31 ,
L_1 ,
V_51 , error ) ;
}
static void F_14 ( struct V_52 * V_52 )
{
struct V_30 * V_31 = V_52 -> V_53 ;
const int V_54 = V_52 -> V_54 ;
int error ;
unsigned long V_55 ;
F_15 ( & V_31 -> V_50 -> V_31 , L_2 ,
V_31 -> V_38 -> V_39 [ 0 ] ,
V_31 -> V_38 -> V_39 [ 1 ] ,
V_31 -> V_38 -> V_39 [ 2 ] ,
V_31 -> V_38 -> V_39 [ 3 ] ,
V_31 -> V_56 ) ;
if ( V_54 ) {
if ( V_54 == - V_57 )
return;
F_16 ( & V_31 -> V_50 -> V_31 , L_3 ,
V_51 , V_54 ) ;
goto V_58;
}
F_9 ( V_31 ) ;
if ( V_31 -> V_56 == 0xf ) {
if ( ( V_31 -> V_59 & 0xf0 ) == ( V_31 -> V_38 -> V_39 [ V_60 ] & 0xf0 ) )
goto V_58;
V_31 -> V_59 = V_31 -> V_38 -> V_39 [ V_60 ] & 0xf0 ;
V_31 -> V_56 = 0x1 ;
} else {
F_6 ( V_31 , V_31 -> V_43 [ V_31 -> V_38 -> V_39 [ V_60 ] ] ) ;
V_31 -> V_56 <<= 1 ;
if ( V_31 -> V_56 > 0x8 )
V_31 -> V_56 = 0xf ;
}
V_58:
F_17 ( & V_31 -> V_61 , V_55 ) ;
V_31 -> V_62 = 0 ;
if ( F_18 ( ! V_31 -> V_63 ) ) {
if ( V_31 -> V_44 )
V_31 -> V_45 -> V_39 [ V_46 ] |= V_47 ;
else
V_31 -> V_45 -> V_39 [ V_46 ] &= ~ V_47 ;
V_31 -> V_45 -> V_39 [ V_64 ] = V_31 -> V_56 ;
V_31 -> V_45 -> V_39 [ V_65 ] = V_31 -> V_56 ;
V_31 -> V_66 = 0 ;
V_31 -> V_67 = 1 ;
error = F_12 ( V_31 -> V_48 , V_49 ) ;
if ( error )
F_13 ( & V_31 -> V_50 -> V_31 ,
L_1 ,
V_51 , error ) ;
}
F_19 ( & V_31 -> V_61 , V_55 ) ;
}
static void F_20 ( struct V_52 * V_52 )
{
struct V_30 * V_31 = V_52 -> V_53 ;
const int V_54 = V_52 -> V_54 ;
int error ;
unsigned long V_55 ;
F_15 ( & V_31 -> V_50 -> V_31 , L_4 ,
V_31 -> V_45 -> V_39 [ 0 ] ,
V_31 -> V_45 -> V_39 [ 1 ] ,
V_31 -> V_45 -> V_39 [ 2 ] ,
V_31 -> V_45 -> V_39 [ 3 ] ) ;
if ( V_54 ) {
if ( V_54 == - V_57 )
return;
F_16 ( & V_31 -> V_50 -> V_31 , L_3 ,
V_51 , V_54 ) ;
}
F_17 ( & V_31 -> V_61 , V_55 ) ;
V_31 -> V_67 = 0 ;
if ( F_18 ( ! V_31 -> V_63 ) ) {
if ( V_31 -> V_66 || V_54 ) {
V_31 -> V_66 = 0 ;
V_31 -> V_67 = 1 ;
F_11 ( V_31 ) ;
} else if ( F_18 ( ! V_31 -> V_62 ) ) {
V_31 -> V_62 = 1 ;
error = F_12 ( V_31 -> V_68 , V_49 ) ;
if ( error )
F_13 ( & V_31 -> V_50 -> V_31 ,
L_5 ,
V_51 , error ) ;
}
}
F_19 ( & V_31 -> V_61 , V_55 ) ;
}
static void F_21 ( struct V_30 * V_31 )
{
unsigned long V_55 ;
F_17 ( & V_31 -> V_61 , V_55 ) ;
if ( V_31 -> V_67 ) {
V_31 -> V_66 = 1 ;
} else {
V_31 -> V_67 = 1 ;
F_11 ( V_31 ) ;
}
F_19 ( & V_31 -> V_61 , V_55 ) ;
}
static void F_22 ( struct V_30 * V_31 , int V_69 )
{
int error ;
if ( V_69 )
V_31 -> V_45 -> V_39 [ V_46 ] |= V_47 ;
else
V_31 -> V_45 -> V_39 [ V_46 ] &= ~ V_47 ;
error = F_23 ( V_31 -> V_70 ,
F_24 ( V_31 -> V_70 , 0 ) ,
V_31 -> V_71 -> V_72 ,
V_31 -> V_71 -> V_73 ,
F_25 ( V_31 -> V_71 -> V_74 ) ,
F_25 ( V_31 -> V_71 -> V_75 ) ,
V_31 -> V_45 ,
V_76 , V_77 ) ;
if ( error < 0 && error != - V_78 )
F_13 ( & V_31 -> V_50 -> V_31 , L_6 ,
V_51 , error ) ;
}
static void F_26 ( struct V_30 * V_31 )
{
V_31 -> V_63 = 1 ;
F_27 () ;
F_28 ( V_31 -> V_48 ) ;
F_28 ( V_31 -> V_68 ) ;
F_22 ( V_31 , 0 ) ;
V_31 -> V_63 = 0 ;
F_27 () ;
}
static void F_29 ( struct V_30 * V_31 )
{
if ( V_31 -> V_79 ) {
F_21 ( V_31 ) ;
}
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_30 * V_31 = F_31 ( V_34 ) ;
int error ;
error = F_32 ( V_31 -> V_50 ) ;
if ( error < 0 ) {
F_13 ( & V_34 -> V_31 , L_7 ,
V_51 , error ) ;
return error ;
}
F_33 ( & V_31 -> V_80 ) ;
V_31 -> V_44 = 0 ;
V_31 -> V_35 = - 1 ;
V_31 -> V_56 = 0xf ;
V_31 -> V_45 -> V_39 [ V_46 ] = V_81 ;
V_31 -> V_45 -> V_39 [ V_64 ] = V_31 -> V_56 ;
V_31 -> V_45 -> V_39 [ V_65 ] = V_31 -> V_56 ;
V_31 -> V_45 -> V_39 [ V_82 ] = 0x00 ;
error = F_12 ( V_31 -> V_48 , V_83 ) ;
if ( error )
F_13 ( & V_31 -> V_50 -> V_31 , L_1 ,
V_51 , error ) ;
else
V_31 -> V_79 = 1 ;
F_34 ( & V_31 -> V_80 ) ;
if ( error )
F_35 ( V_31 -> V_50 ) ;
return error ;
}
static void F_36 ( struct V_33 * V_34 )
{
struct V_30 * V_31 = F_31 ( V_34 ) ;
F_33 ( & V_31 -> V_80 ) ;
F_26 ( V_31 ) ;
V_31 -> V_79 = 0 ;
F_34 ( & V_31 -> V_80 ) ;
F_35 ( V_31 -> V_50 ) ;
}
static int F_37 ( struct V_33 * V_34 , unsigned int type ,
unsigned int V_1 , int V_84 )
{
struct V_30 * V_31 = F_31 ( V_34 ) ;
F_15 ( & V_31 -> V_50 -> V_31 ,
L_8 , type , V_1 , V_84 ) ;
if ( type != V_85 )
return - V_86 ;
switch ( V_1 ) {
case V_87 :
case V_88 :
V_31 -> V_44 = ! ! V_84 ;
if ( ! V_31 -> V_89 )
F_21 ( V_31 ) ;
return 0 ;
default:
return - V_86 ;
}
}
static void F_38 ( struct V_30 * V_31 )
{
F_39 ( V_31 -> V_71 ) ;
if ( V_31 -> V_45 )
F_40 ( V_31 -> V_70 , V_76 ,
V_31 -> V_45 , V_31 -> V_90 ) ;
if ( V_31 -> V_38 )
F_40 ( V_31 -> V_70 , V_76 ,
V_31 -> V_38 , V_31 -> V_91 ) ;
F_41 ( V_31 -> V_68 ) ;
F_41 ( V_31 -> V_48 ) ;
F_39 ( V_31 ) ;
}
static void F_42 ( struct V_92 * V_93 )
{
struct V_30 * V_31 = F_43 ( V_93 ) ;
F_44 ( V_93 , NULL ) ;
F_45 ( V_31 -> V_34 ) ;
F_38 ( V_31 ) ;
}
static int F_46 ( struct V_92 * V_50 ,
const struct V_94 * V_95 )
{
struct V_96 * V_70 = F_47 ( V_50 ) ;
struct V_97 * V_98 = (struct V_97 * ) V_95 -> V_97 ;
struct V_99 * V_93 ;
struct V_100 * V_101 ;
struct V_30 * V_31 ;
struct V_33 * V_33 = NULL ;
int V_102 , V_103 , V_42 ;
int error = - V_104 ;
V_93 = V_50 -> V_105 ;
V_101 = & V_93 -> V_101 [ 0 ] . V_106 ;
if ( ! F_48 ( V_101 ) )
return - V_107 ;
V_31 = F_49 ( sizeof( * V_31 ) , V_83 ) ;
if ( ! V_31 )
return - V_104 ;
F_50 ( & V_31 -> V_61 ) ;
F_51 ( & V_31 -> V_80 ) ;
V_31 -> V_70 = V_70 ;
V_31 -> V_50 = V_50 ;
V_31 -> V_34 = V_33 = F_52 () ;
if ( ! V_33 )
goto V_108;
V_31 -> V_38 = F_53 ( V_70 , V_76 ,
V_83 , & V_31 -> V_91 ) ;
if ( ! V_31 -> V_38 )
goto V_108;
V_31 -> V_45 = F_53 ( V_70 , V_76 ,
V_83 , & V_31 -> V_90 ) ;
if ( ! V_31 -> V_45 )
goto V_108;
V_31 -> V_71 = F_54 ( sizeof( * ( V_31 -> V_71 ) ) , V_83 ) ;
if ( ! V_31 -> V_71 )
goto V_108;
V_31 -> V_68 = F_55 ( 0 , V_83 ) ;
if ( ! V_31 -> V_68 )
goto V_108;
V_31 -> V_48 = F_55 ( 0 , V_83 ) ;
if ( ! V_31 -> V_48 )
goto V_108;
V_103 = F_56 ( V_70 , V_101 -> V_109 ) ;
V_102 = F_57 ( V_70 , V_103 , F_58 ( V_103 ) ) ;
if ( V_102 != V_76 )
F_13 ( & V_50 -> V_31 , L_9 ,
V_102 , V_76 ) ;
F_59 ( V_31 -> V_68 , V_70 , V_103 , V_31 -> V_38 ,
V_76 ,
F_14 , V_31 , V_101 -> V_110 ) ;
V_31 -> V_68 -> V_111 = V_31 -> V_91 ;
V_31 -> V_68 -> V_112 |= V_113 ;
V_31 -> V_68 -> V_31 = V_70 ;
V_31 -> V_71 -> V_73 = V_114 | V_115 |
V_116 ;
V_31 -> V_71 -> V_72 = V_117 ;
V_31 -> V_71 -> V_74 = F_60 ( 0x200 ) ;
V_31 -> V_71 -> V_75 = F_60 ( V_93 -> V_106 . V_118 ) ;
V_31 -> V_71 -> V_119 = F_60 ( V_76 ) ;
F_61 ( V_31 -> V_48 , V_70 , F_24 ( V_70 , 0 ) ,
( void * ) V_31 -> V_71 , V_31 -> V_45 , V_76 ,
F_20 , V_31 ) ;
V_31 -> V_48 -> V_111 = V_31 -> V_90 ;
V_31 -> V_48 -> V_112 |= V_113 ;
V_31 -> V_48 -> V_31 = V_70 ;
F_62 ( V_70 , V_31 -> V_120 , sizeof( V_31 -> V_120 ) ) ;
F_63 ( V_31 -> V_120 , L_10 , sizeof( V_31 -> V_120 ) ) ;
V_33 -> V_121 = V_98 -> V_121 ;
V_33 -> V_120 = V_31 -> V_120 ;
F_64 ( V_70 , & V_33 -> V_95 ) ;
V_33 -> V_31 . V_122 = & V_50 -> V_31 ;
F_65 ( V_33 , V_31 ) ;
V_33 -> V_79 = F_30 ;
V_33 -> V_123 = F_36 ;
V_33 -> V_124 = F_37 ;
V_33 -> V_41 = V_31 -> V_43 ;
V_33 -> V_125 = sizeof( unsigned char ) ;
V_33 -> V_126 = F_66 ( V_31 -> V_43 ) ;
V_33 -> V_127 [ 0 ] = F_67 ( V_128 ) | F_67 ( V_85 ) ;
V_33 -> V_129 [ 0 ] = F_67 ( V_88 ) | F_67 ( V_87 ) ;
for ( V_42 = 0 ; V_42 < V_130 ; V_42 ++ ) {
unsigned short V_131 = V_43 ( V_42 ) ;
V_31 -> V_43 [ V_42 ] = V_131 ;
F_68 ( V_131 , V_33 -> V_56 ) ;
}
F_69 ( V_10 , V_33 -> V_56 ) ;
error = F_70 ( V_31 -> V_34 ) ;
if ( error )
goto V_108;
F_44 ( V_50 , V_31 ) ;
return 0 ;
V_108:
F_71 ( V_33 ) ;
F_38 ( V_31 ) ;
return error ;
}
static int F_72 ( struct V_92 * V_50 , T_2 V_132 )
{
struct V_30 * V_31 = F_43 ( V_50 ) ;
F_73 ( & V_50 -> V_31 , L_11 , V_132 . V_124 ) ;
F_33 ( & V_31 -> V_80 ) ;
F_26 ( V_31 ) ;
F_34 ( & V_31 -> V_80 ) ;
return 0 ;
}
static int F_74 ( struct V_92 * V_50 )
{
struct V_30 * V_31 = F_43 ( V_50 ) ;
F_73 ( & V_50 -> V_31 , L_12 ) ;
F_33 ( & V_31 -> V_80 ) ;
F_29 ( V_31 ) ;
F_34 ( & V_31 -> V_80 ) ;
return 0 ;
}
static int F_75 ( struct V_92 * V_50 )
{
struct V_30 * V_31 = F_43 ( V_50 ) ;
F_33 ( & V_31 -> V_80 ) ;
V_31 -> V_89 = 1 ;
F_27 () ;
F_26 ( V_31 ) ;
return 0 ;
}
static int F_76 ( struct V_92 * V_50 )
{
struct V_30 * V_31 = F_43 ( V_50 ) ;
V_31 -> V_89 = 0 ;
F_27 () ;
F_29 ( V_31 ) ;
F_34 ( & V_31 -> V_80 ) ;
return 0 ;
}
static int T_3 F_77 ( void )
{
if ( ! strcasecmp ( V_133 , L_13 ) ) {
V_43 = F_2 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_15 ) ;
} else if ( ! strcasecmp ( V_133 , L_16 ) ) {
V_43 = F_3 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_17 ) ;
} else if ( ! strcasecmp ( V_133 , L_18 ) ) {
V_43 = F_4 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_19 ) ;
} else if ( ! strcasecmp ( V_133 , L_20 ) ) {
V_43 = F_5 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
L_21 ) ;
} else {
F_78 (KERN_ERR KBUILD_MODNAME L_14
L_22 , phone) ;
return - V_86 ;
}
return 0 ;
}
static int T_3 F_79 ( void )
{
int V_134 ;
V_134 = F_77 () ;
if ( V_134 )
return V_134 ;
V_134 = F_80 ( & V_135 ) ;
if ( V_134 )
return V_134 ;
F_78 (KERN_INFO KBUILD_MODNAME L_14
DRIVER_DESC L_14 DRIVER_VERSION L_23 DRIVER_AUTHOR L_24 ) ;
return 0 ;
}
static void T_4 F_81 ( void )
{
F_82 ( & V_135 ) ;
}
