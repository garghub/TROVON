static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
if ( V_4 -> V_6 -> V_7 . V_8 & V_9 )
F_3 ( L_1 ) ;
if ( V_4 -> V_6 -> V_7 . V_8 & V_10 )
F_3 ( L_2 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 , F_1 ) ;
F_6 ( & V_4 -> V_5 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_5 ) ;
}
int F_9 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
F_10 ( 1 , L_3 ,
V_6 -> V_16 , V_6 -> V_17 , V_6 -> V_18 ) ;
F_11 ( V_6 , & V_19 [ V_20 ] ,
V_4 -> V_21 , V_14 -> V_22 . V_23 ) ;
F_12 ( V_24 , V_4 -> V_21 ) ;
F_10 ( 1 , L_4 , V_6 -> V_25 ) ;
if ( ( V_6 -> V_25 == V_9 ) &&
( V_6 -> V_7 . V_8 & V_9 ) ) {
F_10 ( 1 , L_5 ) ;
F_12 ( V_26 , 0x0040 | V_4 -> V_27 ) ;
F_13 ( 100 ) ;
F_12 ( V_28 , 0x00 ) ;
F_12 ( V_29 , 0x47 << 16 | 188 << 4 | 0x01 ) ;
switch ( V_6 -> V_30 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
F_12 ( V_35 , 1 << 13 ) ;
break;
case V_36 :
F_12 ( V_35 , 0x00 ) ;
break;
case V_37 :
case V_38 :
F_12 ( V_28 , 0x88 ) ;
F_13 ( 100 ) ;
break;
case V_39 :
F_12 ( V_28 , 0x88 ) ;
F_12 ( V_35 , 0 ) ;
F_12 ( V_40 , 0 ) ;
break;
case V_41 :
F_12 ( V_28 , 0x88 ) ;
F_12 ( V_29 , ( 0x47 << 16 ) | ( 188 << 4 ) ) ;
V_4 -> V_27 = 5 ;
F_12 ( V_35 , 0 ) ;
F_12 ( V_40 , 0 ) ;
F_13 ( 100 ) ;
break;
default:
F_12 ( V_35 , 0x00 ) ;
break;
}
F_12 ( V_26 , V_4 -> V_27 ) ;
F_13 ( 100 ) ;
} else if ( ( V_6 -> V_25 == V_10 ) &&
( V_6 -> V_7 . V_8 & V_10 ) ) {
F_10 ( 1 , L_6 ) ;
F_12 ( V_28 , 0x88 ) ;
F_12 ( V_26 , 0x46 ) ;
F_13 ( 100 ) ;
F_12 ( V_29 , 0x408 ) ;
F_12 ( V_40 , 0x2000 ) ;
F_12 ( V_26 , 0x06 ) ;
F_13 ( 100 ) ;
} else {
F_14 ( L_7 ,
V_42 , V_6 -> V_7 . V_8 ) ;
return - V_43 ;
}
F_12 ( V_44 , V_45 ) ;
V_12 -> V_46 = 0 ;
F_10 ( 1 , L_8 ) ;
F_15 ( V_47 , V_6 -> V_48 | V_49 ) ;
F_15 ( V_50 , 0x1f0011 ) ;
F_15 ( V_51 , ( 1 << 5 ) ) ;
F_15 ( V_52 , 0x11 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
F_10 ( 1 , L_9 ) ;
F_17 ( V_52 , 0x11 ) ;
F_17 ( V_47 , V_49 ) ;
F_17 ( V_50 , 0x1f0011 ) ;
F_12 ( V_26 , 0xcd ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
F_10 ( 1 , L_9 ) ;
if ( F_19 ( & V_12 -> V_53 ) )
return 0 ;
V_14 = F_20 ( V_12 -> V_53 . V_54 , struct V_13 , V_55 ) ;
F_10 ( 2 , L_10 ,
V_14 , V_14 -> V_56 . V_57 . V_58 ) ;
F_9 ( V_4 , V_12 , V_14 ) ;
return 0 ;
}
int F_21 ( struct V_59 * V_12 , struct V_3 * V_4 ,
struct V_13 * V_14 )
{
int V_60 = V_4 -> V_21 * V_4 -> V_61 ;
struct V_62 * V_63 = F_22 ( & V_14 -> V_56 . V_57 , 0 ) ;
struct V_64 * V_22 = & V_14 -> V_22 ;
int V_65 ;
if ( F_23 ( & V_14 -> V_56 . V_57 , 0 ) < V_60 )
return - V_43 ;
F_24 ( & V_14 -> V_56 . V_57 , 0 , V_60 ) ;
V_65 = F_25 ( V_4 -> V_66 , V_22 , V_63 -> V_67 ,
V_4 -> V_21 , V_4 -> V_61 , 0 ) ;
if ( V_65 ) {
if ( V_22 -> V_68 )
F_26 ( V_4 -> V_66 , V_22 -> V_60 ,
V_22 -> V_68 , V_22 -> V_23 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
return V_65 ;
}
return 0 ;
}
void F_27 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
struct V_13 * V_69 ;
struct V_11 * V_70 = & V_4 -> V_71 ;
F_10 ( 1 , L_9 ) ;
V_14 -> V_22 . V_68 [ 1 ] = F_28 ( V_14 -> V_22 . V_23 + 8 ) ;
V_14 -> V_22 . V_72 [ 0 ] = F_28 ( V_73 | V_74 ) ;
V_14 -> V_22 . V_72 [ 1 ] = F_28 ( V_14 -> V_22 . V_23 + 8 ) ;
if ( F_19 ( & V_70 -> V_53 ) ) {
F_10 ( 1 , L_11 ) ;
F_29 ( & V_14 -> V_55 , & V_70 -> V_53 ) ;
F_10 ( 1 , L_12 ,
V_14 , V_14 -> V_56 . V_57 . V_58 , V_42 ) ;
} else {
V_14 -> V_22 . V_68 [ 0 ] |= F_28 ( V_75 ) ;
F_10 ( 1 , L_13 ) ;
V_69 = F_20 ( V_70 -> V_53 . V_69 , struct V_13 , V_55 ) ;
F_29 ( & V_14 -> V_55 , & V_70 -> V_53 ) ;
V_69 -> V_22 . V_72 [ 1 ] = F_28 ( V_14 -> V_22 . V_23 ) ;
F_10 ( 1 , L_14 ,
V_14 , V_14 -> V_56 . V_57 . V_58 , V_42 ) ;
}
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_71 ;
struct V_13 * V_14 ;
unsigned long V_76 ;
F_31 ( & V_4 -> V_77 , V_76 ) ;
while ( ! F_19 ( & V_12 -> V_53 ) ) {
V_14 = F_20 ( V_12 -> V_53 . V_54 , struct V_13 , V_55 ) ;
F_32 ( & V_14 -> V_55 ) ;
F_33 ( & V_14 -> V_56 . V_57 , V_78 ) ;
}
F_34 ( & V_4 -> V_77 , V_76 ) ;
}
void F_35 ( struct V_3 * V_4 )
{
F_10 ( 1 , L_9 ) ;
F_16 ( V_4 ) ;
F_30 ( V_4 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
T_1 V_79 , V_80 , V_46 ;
F_10 ( 1 , L_9 ) ;
V_79 = F_37 ( V_81 ) ;
V_80 = F_37 ( V_50 ) ;
if ( 0 == ( V_79 & V_80 ) )
return;
F_12 ( V_81 , V_79 ) ;
if ( V_82 || ( V_79 & V_80 & ~ 0xff ) )
F_38 ( L_15 ,
V_83 , F_39 ( V_83 ) ,
V_79 , V_80 ) ;
if ( V_79 & ( 1 << 16 ) ) {
F_40 ( L_16 ) ;
F_17 ( V_52 , 0x11 ) ;
F_41 ( V_4 -> V_6 ,
& V_19 [ V_20 ] ) ;
}
if ( V_79 & 0x01 ) {
F_10 ( 1 , L_17 ) ;
F_42 ( & V_4 -> V_77 ) ;
V_46 = F_37 ( V_84 ) ;
F_43 ( V_4 -> V_6 , & V_4 -> V_71 , V_46 ) ;
F_44 ( & V_4 -> V_77 ) ;
}
if ( V_79 & 0x1f0100 ) {
F_10 ( 0 , L_18 , V_79 & 0x1f0100 ) ;
F_42 ( & V_4 -> V_77 ) ;
F_16 ( V_4 ) ;
F_44 ( & V_4 -> V_77 ) ;
}
}
static T_2 F_45 ( int V_85 , void * V_86 )
{
struct V_3 * V_4 = V_86 ;
struct V_15 * V_6 = V_4 -> V_6 ;
T_1 V_79 ;
int V_87 , V_88 = 0 ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
V_79 = F_37 ( V_90 ) &
( V_6 -> V_48 | V_49 ) ;
if ( V_79 == 0 )
goto V_91;
F_10 ( 1 , L_19 ) ;
F_10 ( 1 , L_20 , V_87 , V_89 ) ;
F_10 ( 1 , L_21 , V_79 ) ;
V_88 = 1 ;
F_12 ( V_90 , V_79 ) ;
if ( V_79 & V_6 -> V_48 )
F_46 ( V_6 , V_79 ) ;
if ( V_79 & V_49 )
F_36 ( V_4 ) ;
}
if ( V_87 == V_89 ) {
F_10 ( 0 , L_22 ) ;
F_40 ( L_23 ) ;
F_12 ( V_47 , 0 ) ;
}
V_91:
return F_47 ( V_88 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
int V_92 ;
if ( F_49 ( V_4 -> V_66 ) )
return - V_93 ;
F_50 ( V_4 -> V_66 ) ;
V_92 = F_51 ( V_4 -> V_66 , F_52 ( 32 ) ) ;
if ( V_92 ) {
F_14 ( L_24 ) ;
return - V_93 ;
}
V_4 -> V_94 = V_4 -> V_66 -> V_95 ;
F_53 ( V_4 -> V_66 , V_96 , & V_4 -> V_97 ) ;
F_54 ( L_25 ,
F_55 ( V_4 -> V_66 ) , V_4 -> V_94 , V_4 -> V_66 -> V_85 ,
V_4 -> V_97 ,
( unsigned long long ) F_56 ( V_4 -> V_66 , 0 ) ) ;
F_57 ( & V_4 -> V_77 ) ;
F_58 ( & V_4 -> V_71 . V_53 ) ;
V_92 = F_59 ( V_4 -> V_66 -> V_85 , F_45 ,
V_98 , V_4 -> V_6 -> V_99 , V_4 ) ;
if ( V_92 < 0 ) {
F_14 ( L_26 , V_4 -> V_66 -> V_85 ) ;
return V_92 ;
}
F_15 ( V_47 , V_6 -> V_48 ) ;
F_60 ( V_4 -> V_66 , V_4 ) ;
return 0 ;
}
static void F_61 ( struct V_3 * V_4 )
{
F_10 ( 2 , L_9 ) ;
F_16 ( V_4 ) ;
F_62 ( V_4 -> V_66 ) ;
F_63 ( V_4 -> V_66 -> V_85 , V_4 ) ;
}
static int F_64 ( struct V_100 * V_100 , T_3 V_101 )
{
struct V_3 * V_4 = F_65 ( V_100 ) ;
unsigned long V_76 ;
F_31 ( & V_4 -> V_77 , V_76 ) ;
if ( ! F_19 ( & V_4 -> V_71 . V_53 ) ) {
F_10 ( 2 , L_27 ) ;
F_54 ( L_28 ) ;
F_16 ( V_4 ) ;
}
F_34 ( & V_4 -> V_77 , V_76 ) ;
F_66 ( V_4 -> V_6 ) ;
F_67 ( V_100 ) ;
if ( F_68 ( V_100 ,
F_69 ( V_100 , V_101 ) ) != 0 ) {
F_62 ( V_100 ) ;
V_4 -> V_101 . V_102 = 1 ;
}
return 0 ;
}
static int F_70 ( struct V_100 * V_100 )
{
struct V_3 * V_4 = F_65 ( V_100 ) ;
unsigned long V_76 ;
int V_92 ;
if ( V_4 -> V_101 . V_102 ) {
V_92 = F_49 ( V_100 ) ;
if ( V_92 ) {
F_14 ( L_29 ) ;
return V_92 ;
}
V_4 -> V_101 . V_102 = 0 ;
}
V_92 = F_68 ( V_100 , V_103 ) ;
if ( V_92 ) {
F_14 ( L_29 ) ;
F_62 ( V_100 ) ;
V_4 -> V_101 . V_102 = 1 ;
return V_92 ;
}
F_71 ( V_100 ) ;
F_72 ( V_4 -> V_6 ) ;
F_31 ( & V_4 -> V_77 , V_76 ) ;
if ( ! F_19 ( & V_4 -> V_71 . V_53 ) ) {
F_54 ( L_30 ) ;
F_18 ( V_4 , & V_4 -> V_71 ) ;
}
F_34 ( & V_4 -> V_77 , V_76 ) ;
return 0 ;
}
struct V_104 * F_73 ( struct V_3 * V_4 ,
enum V_105 V_106 )
{
struct V_104 * V_107 ;
F_74 (d, &dev->drvlist, drvlist)
if ( V_107 -> V_108 == V_106 )
return V_107 ;
return NULL ;
}
static int F_75 ( struct V_104 * V_109 )
{
struct V_15 * V_6 = V_109 -> V_6 ;
unsigned int V_110 ;
if ( V_6 -> V_25 != V_111 &&
V_6 -> V_25 != V_109 -> V_108 )
return - V_112 ;
if ( V_109 -> V_108 == V_9 ) {
V_6 -> V_113 = V_6 -> V_114 ;
V_6 -> V_114 = 0 ;
for ( V_110 = 0 ;
V_110 < ( sizeof( V_6 -> V_7 . V_114 ) /
sizeof( struct V_115 ) ) ;
V_110 ++ ) {
if ( V_6 -> V_7 . V_114 [ V_110 ] . type == V_116 ) {
V_6 -> V_114 = V_110 ;
break;
}
}
}
if ( V_109 -> V_117 ) {
V_6 -> V_118 ++ ;
if ( V_6 -> V_25 == V_111 ) {
V_6 -> V_25 = V_109 -> V_108 ;
V_109 -> V_117 ( V_109 ) ;
}
F_10 ( 1 , L_31 , F_37 ( V_119 ) ) ;
}
return 0 ;
}
static int F_76 ( struct V_104 * V_109 )
{
struct V_15 * V_6 = V_109 -> V_6 ;
if ( V_109 -> V_120 && -- V_6 -> V_118 == 0 ) {
if ( V_109 -> V_108 == V_9 ) {
V_6 -> V_114 = V_6 -> V_113 ;
}
V_109 -> V_120 ( V_109 ) ;
V_6 -> V_25 = V_111 ;
F_10 ( 1 , L_32 , F_37 ( V_119 ) ) ;
}
return 0 ;
}
static int F_77 ( struct V_104 * V_109 )
{
if ( ! V_109 )
return - V_121 ;
if ( ( V_109 -> V_108 != V_9 ) &&
( V_109 -> V_108 != V_10 ) )
return - V_43 ;
if ( ( V_109 -> V_122 != V_123 ) &&
( V_109 -> V_122 != V_124 ) )
return - V_43 ;
if ( ( ! V_109 -> V_125 ) ||
( ! V_109 -> remove ) ||
( ! V_109 -> V_117 ) ||
( ! V_109 -> V_120 ) )
return - V_43 ;
return 0 ;
}
int F_78 ( struct V_104 * V_109 )
{
struct V_3 * V_4 ;
struct V_104 * V_126 ;
int V_92 , V_110 = 0 ;
F_54 ( L_33 ,
V_109 -> V_108 == V_9 ? L_34 : L_35 ,
V_109 -> V_122 == V_123 ?
L_36 : L_37 ) ;
V_92 = F_77 ( V_109 ) ;
if ( V_92 ) {
F_14 ( L_38 ) ;
return V_92 ;
}
F_79 ( & V_127 ) ;
F_74 (dev, &cx8802_devlist, devlist) {
F_54 ( L_39 ,
V_4 -> V_66 -> V_128 ,
V_4 -> V_66 -> V_129 , V_4 -> V_6 -> V_7 . V_99 ,
V_4 -> V_6 -> V_30 ) ;
V_126 = F_80 ( sizeof( * V_109 ) , V_130 ) ;
if ( ! V_126 ) {
V_92 = - V_131 ;
goto V_91;
}
V_109 -> V_6 = V_4 -> V_6 ;
V_109 -> V_132 = F_64 ;
V_109 -> V_133 = F_70 ;
V_109 -> V_134 = F_75 ;
V_109 -> V_135 = F_76 ;
memcpy ( V_126 , V_109 , sizeof( * V_126 ) ) ;
F_79 ( & V_109 -> V_6 -> V_136 ) ;
V_92 = V_109 -> V_125 ( V_126 ) ;
if ( V_92 == 0 ) {
V_110 ++ ;
F_29 ( & V_126 -> V_137 , & V_4 -> V_137 ) ;
} else {
F_14 ( L_40 , V_92 ) ;
}
F_81 ( & V_109 -> V_6 -> V_136 ) ;
}
V_92 = V_110 ? 0 : - V_121 ;
V_91:
F_81 ( & V_127 ) ;
return V_92 ;
}
int F_82 ( struct V_104 * V_109 )
{
struct V_3 * V_4 ;
struct V_104 * V_107 , * V_138 ;
int V_92 = 0 ;
F_54 ( L_41 ,
V_109 -> V_108 == V_9 ? L_34 : L_35 ,
V_109 -> V_122 == V_123 ?
L_36 : L_37 ) ;
F_79 ( & V_127 ) ;
F_74 (dev, &cx8802_devlist, devlist) {
F_54 ( L_39 ,
V_4 -> V_66 -> V_128 ,
V_4 -> V_66 -> V_129 , V_4 -> V_6 -> V_7 . V_99 ,
V_4 -> V_6 -> V_30 ) ;
F_79 ( & V_4 -> V_6 -> V_136 ) ;
F_83 (d, dtmp, &dev->drvlist, drvlist) {
if ( V_107 -> V_108 != V_109 -> V_108 )
continue;
V_92 = V_107 -> remove ( V_107 ) ;
if ( V_92 == 0 ) {
F_32 ( & V_107 -> V_137 ) ;
F_84 ( V_107 ) ;
} else
F_14 ( L_42 ,
V_92 ) ;
}
F_81 ( & V_4 -> V_6 -> V_136 ) ;
}
F_81 ( & V_127 ) ;
return V_92 ;
}
static int F_85 ( struct V_100 * V_100 ,
const struct V_139 * V_140 )
{
struct V_3 * V_4 ;
struct V_15 * V_6 ;
int V_92 ;
V_6 = F_86 ( V_100 ) ;
if ( ! V_6 )
return - V_43 ;
F_54 ( L_43 ) ;
V_92 = - V_121 ;
if ( ! V_6 -> V_7 . V_8 )
goto V_141;
V_92 = - V_131 ;
V_4 = F_80 ( sizeof( * V_4 ) , V_130 ) ;
if ( ! V_4 )
goto V_141;
V_4 -> V_66 = V_100 ;
V_4 -> V_6 = V_6 ;
V_6 -> V_142 = V_4 ;
V_92 = F_48 ( V_4 ) ;
if ( V_92 != 0 )
goto V_143;
F_58 ( & V_4 -> V_137 ) ;
F_79 ( & V_127 ) ;
F_29 ( & V_4 -> V_144 , & V_145 ) ;
F_81 ( & V_127 ) ;
F_4 ( V_4 ) ;
return 0 ;
V_143:
F_84 ( V_4 ) ;
V_141:
V_6 -> V_142 = NULL ;
F_87 ( V_6 , V_100 ) ;
return V_92 ;
}
static void F_88 ( struct V_100 * V_100 )
{
struct V_3 * V_4 ;
V_4 = F_65 ( V_100 ) ;
F_10 ( 1 , L_44 , V_42 ) ;
F_7 ( V_4 ) ;
F_79 ( & V_4 -> V_6 -> V_136 ) ;
if ( ! F_19 ( & V_4 -> V_137 ) ) {
struct V_104 * V_109 , * V_146 ;
int V_92 ;
F_40 ( L_45 ) ;
F_83 (drv, tmp, &dev->drvlist, drvlist) {
V_92 = V_109 -> remove ( V_109 ) ;
if ( V_92 == 0 ) {
F_32 ( & V_109 -> V_137 ) ;
} else
F_14 ( L_42 ,
V_92 ) ;
F_84 ( V_109 ) ;
}
}
F_81 ( & V_4 -> V_6 -> V_136 ) ;
V_4 -> V_6 -> V_142 = NULL ;
F_61 ( V_4 ) ;
F_87 ( V_4 -> V_6 , V_4 -> V_66 ) ;
F_84 ( V_4 ) ;
}
