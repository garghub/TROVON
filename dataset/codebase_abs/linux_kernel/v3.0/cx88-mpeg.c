static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
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
static int F_9 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
F_10 ( 1 , L_3 ,
V_14 -> V_16 . V_17 , V_14 -> V_16 . V_18 , V_14 -> V_16 . V_19 ) ;
F_11 ( V_6 , & V_20 [ V_21 ] ,
V_4 -> V_22 , V_14 -> V_23 . V_24 ) ;
F_12 ( V_25 , V_14 -> V_16 . V_17 ) ;
F_10 ( 1 , L_4 , V_6 -> V_26 ) ;
if ( ( V_6 -> V_26 == V_9 ) &&
( V_6 -> V_7 . V_8 & V_9 ) ) {
F_10 ( 1 , L_5 ) ;
F_12 ( V_27 , 0x0040 | V_4 -> V_28 ) ;
F_13 ( 100 ) ;
F_12 ( V_29 , 0x00 ) ;
F_12 ( V_30 , 0x47 << 16 | 188 << 4 | 0x01 ) ;
switch ( V_6 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
F_12 ( V_36 , 1 << 13 ) ;
break;
case V_37 :
F_12 ( V_36 , 0x00 ) ;
break;
case V_38 :
case V_39 :
F_12 ( V_29 , 0x88 ) ;
F_13 ( 100 ) ;
break;
case V_40 :
F_12 ( V_29 , 0x88 ) ;
F_12 ( V_36 , 0 ) ;
F_12 ( V_41 , 0 ) ;
break;
case V_42 :
F_12 ( V_29 , 0x88 ) ;
F_12 ( V_30 , ( 0x47 << 16 ) | ( 188 << 4 ) ) ;
V_4 -> V_28 = 5 ;
F_12 ( V_36 , 0 ) ;
F_12 ( V_41 , 0 ) ;
F_13 ( 100 ) ;
break;
default:
F_12 ( V_36 , 0x00 ) ;
break;
}
F_12 ( V_27 , V_4 -> V_28 ) ;
F_13 ( 100 ) ;
} else if ( ( V_6 -> V_26 == V_10 ) &&
( V_6 -> V_7 . V_8 & V_10 ) ) {
F_10 ( 1 , L_6 ) ;
F_12 ( V_29 , 0x88 ) ;
F_12 ( V_27 , 0x46 ) ;
F_13 ( 100 ) ;
F_12 ( V_30 , 0x408 ) ;
F_12 ( V_41 , 0x2000 ) ;
F_12 ( V_27 , 0x06 ) ;
F_13 ( 100 ) ;
} else {
F_14 ( L_7 , V_43 ,
V_6 -> V_7 . V_8 ) ;
return - V_44 ;
}
F_12 ( V_45 , V_46 ) ;
V_12 -> V_47 = 1 ;
F_10 ( 1 , L_8 ) ;
F_15 ( V_48 , V_6 -> V_49 | V_50 ) ;
F_15 ( V_51 , 0x1f0011 ) ;
F_15 ( V_52 , ( 1 << 5 ) ) ;
F_15 ( V_53 , 0x11 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
F_10 ( 1 , L_9 ) ;
F_17 ( V_53 , 0x11 ) ;
F_17 ( V_48 , V_50 ) ;
F_17 ( V_51 , 0x1f0011 ) ;
F_12 ( V_27 , 0xcd ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
F_10 ( 1 , L_10 ) ;
if ( F_19 ( & V_12 -> V_54 ) )
{
struct V_13 * V_55 ;
V_55 = NULL ;
F_10 ( 1 , L_11 ) ;
for (; ; ) {
if ( F_19 ( & V_12 -> V_56 ) )
return 0 ;
V_14 = F_20 ( V_12 -> V_56 . V_57 , struct V_13 , V_16 . V_58 ) ;
if ( NULL == V_55 ) {
F_21 ( & V_14 -> V_16 . V_58 ) ;
F_22 ( & V_14 -> V_16 . V_58 , & V_12 -> V_54 ) ;
F_9 ( V_4 , V_12 , V_14 ) ;
V_14 -> V_16 . V_59 = V_60 ;
V_14 -> V_47 = V_12 -> V_47 ++ ;
F_23 ( & V_12 -> V_61 , V_62 + V_63 ) ;
F_10 ( 1 , L_12 ,
V_14 , V_14 -> V_16 . V_64 ) ;
} else if ( V_55 -> V_16 . V_17 == V_14 -> V_16 . V_17 &&
V_55 -> V_16 . V_18 == V_14 -> V_16 . V_18 &&
V_55 -> V_65 == V_14 -> V_65 ) {
F_21 ( & V_14 -> V_16 . V_58 ) ;
F_22 ( & V_14 -> V_16 . V_58 , & V_12 -> V_54 ) ;
V_14 -> V_16 . V_59 = V_60 ;
V_14 -> V_47 = V_12 -> V_47 ++ ;
V_55 -> V_23 . V_66 [ 1 ] = F_24 ( V_14 -> V_23 . V_24 ) ;
F_10 ( 1 , L_13 ,
V_14 , V_14 -> V_16 . V_64 ) ;
} else {
return 0 ;
}
V_55 = V_14 ;
}
return 0 ;
}
V_14 = F_20 ( V_12 -> V_54 . V_57 , struct V_13 , V_16 . V_58 ) ;
F_10 ( 2 , L_14 ,
V_14 , V_14 -> V_16 . V_64 ) ;
F_9 ( V_4 , V_12 , V_14 ) ;
F_25 (buf, &q->active, vb.queue)
V_14 -> V_47 = V_12 -> V_47 ++ ;
F_23 ( & V_12 -> V_61 , V_62 + V_63 ) ;
return 0 ;
}
int F_26 ( struct V_67 * V_12 , struct V_3 * V_4 ,
struct V_13 * V_14 , enum V_68 V_19 )
{
int V_69 = V_4 -> V_22 * V_4 -> V_70 ;
struct V_71 * V_24 = F_27 ( & V_14 -> V_16 ) ;
int V_72 ;
F_10 ( 1 , L_15 , V_43 , V_14 ) ;
if ( 0 != V_14 -> V_16 . V_73 && V_14 -> V_16 . V_74 < V_69 )
return - V_44 ;
if ( V_75 == V_14 -> V_16 . V_59 ) {
V_14 -> V_16 . V_17 = V_4 -> V_22 ;
V_14 -> V_16 . V_18 = V_4 -> V_70 ;
V_14 -> V_16 . V_69 = V_69 ;
V_14 -> V_16 . V_19 = V_19 ;
if ( 0 != ( V_72 = F_28 ( V_12 , & V_14 -> V_16 , NULL ) ) )
goto V_76;
F_29 ( V_4 -> V_77 , & V_14 -> V_23 ,
V_24 -> V_78 ,
V_14 -> V_16 . V_17 , V_14 -> V_16 . V_18 , 0 ) ;
}
V_14 -> V_16 . V_59 = V_79 ;
return 0 ;
V_76:
F_30 ( V_12 , V_14 ) ;
return V_72 ;
}
void F_31 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
struct V_13 * V_55 ;
struct V_11 * V_80 = & V_4 -> V_81 ;
F_10 ( 1 , L_16 ) ;
V_14 -> V_23 . V_66 [ 0 ] = F_24 ( V_82 | V_83 | V_84 ) ;
V_14 -> V_23 . V_66 [ 1 ] = F_24 ( V_80 -> V_85 . V_24 ) ;
if ( F_19 ( & V_80 -> V_54 ) ) {
F_10 ( 1 , L_17 ) ;
F_22 ( & V_14 -> V_16 . V_58 , & V_80 -> V_54 ) ;
F_9 ( V_4 , V_80 , V_14 ) ;
V_14 -> V_16 . V_59 = V_60 ;
V_14 -> V_47 = V_80 -> V_47 ++ ;
F_23 ( & V_80 -> V_61 , V_62 + V_63 ) ;
F_10 ( 1 , L_18 ,
V_14 , V_14 -> V_16 . V_64 , V_43 ) ;
} else {
F_10 ( 1 , L_19 ) ;
V_55 = F_20 ( V_80 -> V_54 . V_55 , struct V_13 , V_16 . V_58 ) ;
F_22 ( & V_14 -> V_16 . V_58 , & V_80 -> V_54 ) ;
V_14 -> V_16 . V_59 = V_60 ;
V_14 -> V_47 = V_80 -> V_47 ++ ;
V_55 -> V_23 . V_66 [ 1 ] = F_24 ( V_14 -> V_23 . V_24 ) ;
F_10 ( 1 , L_20 ,
V_14 , V_14 -> V_16 . V_64 , V_43 ) ;
}
}
static void F_32 ( struct V_3 * V_4 , const char * V_86 , int V_87 )
{
struct V_11 * V_12 = & V_4 -> V_81 ;
struct V_13 * V_14 ;
unsigned long V_88 ;
F_33 ( & V_4 -> V_89 , V_88 ) ;
while ( ! F_19 ( & V_12 -> V_54 ) ) {
V_14 = F_20 ( V_12 -> V_54 . V_57 , struct V_13 , V_16 . V_58 ) ;
F_21 ( & V_14 -> V_16 . V_58 ) ;
V_14 -> V_16 . V_59 = V_90 ;
F_34 ( & V_14 -> V_16 . V_91 ) ;
F_10 ( 1 , L_21 ,
V_14 , V_14 -> V_16 . V_64 , V_86 , ( unsigned long ) V_14 -> V_23 . V_24 ) ;
}
if ( V_87 )
{
F_10 ( 1 , L_22 ) ;
F_18 ( V_4 , V_12 ) ;
}
F_35 ( & V_4 -> V_89 , V_88 ) ;
}
void F_36 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_81 ;
F_10 ( 1 , L_23 ) ;
F_37 ( & V_12 -> V_61 ) ;
F_16 ( V_4 ) ;
F_32 ( V_4 , L_24 , 0 ) ;
}
static void F_38 ( unsigned long V_92 )
{
struct V_3 * V_4 = (struct V_3 * ) V_92 ;
F_10 ( 1 , L_25 , V_43 ) ;
if ( V_93 )
F_39 ( V_4 -> V_6 , & V_20 [ V_21 ] ) ;
F_16 ( V_4 ) ;
F_32 ( V_4 , L_26 , 1 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
T_1 V_94 , V_95 , V_47 ;
F_10 ( 1 , L_27 ) ;
V_94 = F_41 ( V_96 ) ;
V_95 = F_41 ( V_51 ) ;
if ( 0 == ( V_94 & V_95 ) )
return;
F_12 ( V_96 , V_94 ) ;
if ( V_93 || ( V_94 & V_95 & ~ 0xff ) )
F_42 ( V_6 -> V_97 , L_28 ,
V_98 , F_43 ( V_98 ) ,
V_94 , V_95 ) ;
if ( V_94 & ( 1 << 16 ) ) {
F_14 ( V_99 L_29 , V_6 -> V_97 ) ;
F_17 ( V_53 , 0x11 ) ;
F_39 ( V_4 -> V_6 , & V_20 [ V_21 ] ) ;
}
if ( V_94 & 0x01 ) {
F_10 ( 1 , L_30 ) ;
F_44 ( & V_4 -> V_89 ) ;
V_47 = F_41 ( V_100 ) ;
F_45 ( V_4 -> V_6 , & V_4 -> V_81 , V_47 ) ;
F_46 ( & V_4 -> V_89 ) ;
}
if ( V_94 & 0x10 ) {
F_44 ( & V_4 -> V_89 ) ;
F_18 ( V_4 , & V_4 -> V_81 ) ;
F_46 ( & V_4 -> V_89 ) ;
}
if ( V_94 & 0x1f0100 ) {
F_10 ( 0 , L_31 , V_94 & 0x1f0100 ) ;
F_44 ( & V_4 -> V_89 ) ;
F_16 ( V_4 ) ;
F_18 ( V_4 , & V_4 -> V_81 ) ;
F_46 ( & V_4 -> V_89 ) ;
}
}
static T_2 F_47 ( int V_101 , void * V_102 )
{
struct V_3 * V_4 = V_102 ;
struct V_15 * V_6 = V_4 -> V_6 ;
T_1 V_94 ;
int V_103 , V_104 = 0 ;
for ( V_103 = 0 ; V_103 < V_105 ; V_103 ++ ) {
V_94 = F_41 ( V_106 ) &
( V_6 -> V_49 | V_50 ) ;
if ( 0 == V_94 )
goto V_107;
F_10 ( 1 , L_32 ) ;
F_10 ( 1 , L_33 , V_103 , V_105 ) ;
F_10 ( 1 , L_34 , V_94 ) ;
V_104 = 1 ;
F_12 ( V_106 , V_94 ) ;
if ( V_94 & V_6 -> V_49 )
F_48 ( V_6 , V_94 ) ;
if ( V_94 & V_50 )
F_40 ( V_4 ) ;
} ;
if ( V_105 == V_103 ) {
F_10 ( 0 , L_35 ) ;
F_14 ( V_99 L_36 ,
V_6 -> V_97 ) ;
F_12 ( V_48 , 0 ) ;
}
V_107:
return F_49 ( V_104 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_15 * V_6 = V_4 -> V_6 ;
int V_108 ;
if ( F_51 ( V_4 -> V_77 ) )
return - V_109 ;
F_52 ( V_4 -> V_77 ) ;
if ( ! F_53 ( V_4 -> V_77 , F_54 ( 32 ) ) ) {
F_14 ( L_37 , V_4 -> V_6 -> V_97 ) ;
return - V_109 ;
}
V_4 -> V_110 = V_4 -> V_77 -> V_111 ;
F_55 ( V_4 -> V_77 , V_112 , & V_4 -> V_113 ) ;
F_14 ( V_114 L_38
L_39 , V_4 -> V_6 -> V_97 ,
F_56 ( V_4 -> V_77 ) , V_4 -> V_110 , V_4 -> V_77 -> V_101 ,
V_4 -> V_113 , ( unsigned long long ) F_57 ( V_4 -> V_77 , 0 ) ) ;
F_58 ( & V_4 -> V_89 ) ;
F_59 ( & V_4 -> V_81 . V_54 ) ;
F_59 ( & V_4 -> V_81 . V_56 ) ;
V_4 -> V_81 . V_61 . V_115 = F_38 ;
V_4 -> V_81 . V_61 . V_92 = ( unsigned long ) V_4 ;
F_60 ( & V_4 -> V_81 . V_61 ) ;
F_61 ( V_4 -> V_77 , & V_4 -> V_81 . V_85 ,
V_53 , 0x11 , 0x00 ) ;
V_108 = F_62 ( V_4 -> V_77 -> V_101 , F_47 ,
V_116 | V_117 , V_4 -> V_6 -> V_97 , V_4 ) ;
if ( V_108 < 0 ) {
F_14 ( V_118 L_40 ,
V_4 -> V_6 -> V_97 , V_4 -> V_77 -> V_101 ) ;
return V_108 ;
}
F_15 ( V_48 , V_6 -> V_49 ) ;
F_63 ( V_4 -> V_77 , V_4 ) ;
return 0 ;
}
static void F_64 ( struct V_3 * V_4 )
{
F_10 ( 2 , L_41 ) ;
F_16 ( V_4 ) ;
F_65 ( V_4 -> V_77 ) ;
F_66 ( V_4 -> V_77 -> V_101 , V_4 ) ;
F_63 ( V_4 -> V_77 , NULL ) ;
F_67 ( V_4 -> V_77 , & V_4 -> V_81 . V_85 ) ;
}
static int F_68 ( struct V_119 * V_119 , T_3 V_59 )
{
struct V_3 * V_4 = F_69 ( V_119 ) ;
struct V_15 * V_6 = V_4 -> V_6 ;
F_44 ( & V_4 -> V_89 ) ;
if ( ! F_19 ( & V_4 -> V_81 . V_54 ) ) {
F_10 ( 2 , L_42 ) ;
F_14 ( L_43 , V_6 -> V_97 ) ;
F_16 ( V_4 ) ;
F_70 ( & V_4 -> V_81 . V_61 ) ;
}
F_46 ( & V_4 -> V_89 ) ;
F_71 ( V_4 -> V_6 ) ;
F_72 ( V_119 ) ;
if ( 0 != F_73 ( V_119 , F_74 ( V_119 , V_59 ) ) ) {
F_65 ( V_119 ) ;
V_4 -> V_59 . V_120 = 1 ;
}
return 0 ;
}
static int F_75 ( struct V_119 * V_119 )
{
struct V_3 * V_4 = F_69 ( V_119 ) ;
struct V_15 * V_6 = V_4 -> V_6 ;
int V_108 ;
if ( V_4 -> V_59 . V_120 ) {
V_108 = F_51 ( V_119 ) ;
if ( V_108 ) {
F_14 ( V_118 L_44 ,
V_4 -> V_6 -> V_97 ) ;
return V_108 ;
}
V_4 -> V_59 . V_120 = 0 ;
}
V_108 = F_73 ( V_119 , V_121 ) ;
if ( V_108 ) {
F_14 ( V_118 L_44 ,
V_4 -> V_6 -> V_97 ) ;
F_65 ( V_119 ) ;
V_4 -> V_59 . V_120 = 1 ;
return V_108 ;
}
F_76 ( V_119 ) ;
F_77 ( V_4 -> V_6 ) ;
F_44 ( & V_4 -> V_89 ) ;
if ( ! F_19 ( & V_4 -> V_81 . V_54 ) ) {
F_14 ( L_45 , V_6 -> V_97 ) ;
F_18 ( V_4 , & V_4 -> V_81 ) ;
}
F_46 ( & V_4 -> V_89 ) ;
return 0 ;
}
struct V_122 * F_78 ( struct V_3 * V_4 , enum V_123 V_124 )
{
struct V_122 * V_125 ;
F_25 (d, &dev->drvlist, drvlist)
if ( V_125 -> V_126 == V_124 )
return V_125 ;
return NULL ;
}
static int F_79 ( struct V_122 * V_127 )
{
struct V_15 * V_6 = V_127 -> V_6 ;
unsigned int V_64 ;
if ( V_6 -> V_26 != V_128 &&
V_6 -> V_26 != V_127 -> V_126 )
return - V_129 ;
V_6 -> V_130 = 0 ;
for ( V_64 = 0 ;
V_64 < ( sizeof( V_6 -> V_7 . V_130 ) / sizeof( struct V_131 ) ) ;
V_64 ++ ) {
if ( V_6 -> V_7 . V_130 [ V_64 ] . type == V_132 ) {
V_6 -> V_130 = V_64 ;
break;
}
}
if ( V_127 -> V_133 )
{
V_6 -> V_134 ++ ;
if ( V_6 -> V_26 == V_128 ) {
V_6 -> V_26 = V_127 -> V_126 ;
V_127 -> V_133 ( V_127 ) ;
}
F_80 ( 1 , L_46 , V_43 , F_41 ( V_135 ) ) ;
}
return 0 ;
}
static int F_81 ( struct V_122 * V_127 )
{
struct V_15 * V_6 = V_127 -> V_6 ;
if ( V_127 -> V_136 && -- V_6 -> V_134 == 0 )
{
V_127 -> V_136 ( V_127 ) ;
V_6 -> V_26 = V_128 ;
F_80 ( 1 , L_47 , V_43 , F_41 ( V_135 ) ) ;
}
return 0 ;
}
static int F_82 ( struct V_122 * V_127 )
{
if ( V_127 == NULL )
return - V_137 ;
if ( ( V_127 -> V_126 != V_9 ) &&
( V_127 -> V_126 != V_10 ) )
return - V_44 ;
if ( ( V_127 -> V_138 != V_139 ) &&
( V_127 -> V_138 != V_140 ) )
return - V_44 ;
if ( ( V_127 -> V_141 == NULL ) ||
( V_127 -> remove == NULL ) ||
( V_127 -> V_133 == NULL ) ||
( V_127 -> V_136 == NULL ) )
return - V_44 ;
return 0 ;
}
int F_83 ( struct V_122 * V_127 )
{
struct V_3 * V_4 ;
struct V_122 * V_142 ;
int V_108 , V_64 = 0 ;
F_14 ( V_114
L_48 ,
V_127 -> V_126 == V_9 ? L_49 : L_50 ,
V_127 -> V_138 == V_139 ? L_51 : L_52 ) ;
if ( ( V_108 = F_82 ( V_127 ) ) != 0 ) {
F_14 ( V_118 L_53 ) ;
return V_108 ;
}
F_84 ( & V_143 ) ;
F_25 (dev, &cx8802_devlist, devlist) {
F_14 ( V_114
L_54 ,
V_4 -> V_6 -> V_97 , V_4 -> V_77 -> V_144 ,
V_4 -> V_77 -> V_145 , V_4 -> V_6 -> V_7 . V_97 ,
V_4 -> V_6 -> V_31 ) ;
V_142 = F_85 ( sizeof( * V_127 ) , V_146 ) ;
if ( V_142 == NULL ) {
V_108 = - V_147 ;
goto V_107;
}
V_127 -> V_6 = V_4 -> V_6 ;
V_127 -> V_148 = F_68 ;
V_127 -> V_149 = F_75 ;
V_127 -> V_150 = F_79 ;
V_127 -> V_151 = F_81 ;
memcpy ( V_142 , V_127 , sizeof( * V_142 ) ) ;
F_84 ( & V_127 -> V_6 -> V_152 ) ;
V_108 = V_127 -> V_141 ( V_142 ) ;
if ( V_108 == 0 ) {
V_64 ++ ;
F_22 ( & V_142 -> V_153 , & V_4 -> V_153 ) ;
} else {
F_14 ( V_118
L_55 ,
V_4 -> V_6 -> V_97 , V_108 ) ;
}
F_86 ( & V_127 -> V_6 -> V_152 ) ;
}
V_108 = V_64 ? 0 : - V_137 ;
V_107:
F_86 ( & V_143 ) ;
return V_108 ;
}
int F_87 ( struct V_122 * V_127 )
{
struct V_3 * V_4 ;
struct V_122 * V_125 , * V_154 ;
int V_108 = 0 ;
F_14 ( V_114
L_56 ,
V_127 -> V_126 == V_9 ? L_49 : L_50 ,
V_127 -> V_138 == V_139 ? L_51 : L_52 ) ;
F_84 ( & V_143 ) ;
F_25 (dev, &cx8802_devlist, devlist) {
F_14 ( V_114
L_54 ,
V_4 -> V_6 -> V_97 , V_4 -> V_77 -> V_144 ,
V_4 -> V_77 -> V_145 , V_4 -> V_6 -> V_7 . V_97 ,
V_4 -> V_6 -> V_31 ) ;
F_84 ( & V_4 -> V_6 -> V_152 ) ;
F_88 (d, dtmp, &dev->drvlist, drvlist) {
if ( V_125 -> V_126 != V_127 -> V_126 )
continue;
V_108 = V_125 -> remove ( V_125 ) ;
if ( V_108 == 0 ) {
F_21 ( & V_125 -> V_153 ) ;
F_89 ( V_125 ) ;
} else
F_14 ( V_118 L_57
L_58 , V_4 -> V_6 -> V_97 , V_108 ) ;
}
F_86 ( & V_4 -> V_6 -> V_152 ) ;
}
F_86 ( & V_143 ) ;
return V_108 ;
}
static int T_4 F_90 ( struct V_119 * V_119 ,
const struct V_155 * V_156 )
{
struct V_3 * V_4 ;
struct V_15 * V_6 ;
int V_108 ;
V_6 = F_91 ( V_119 ) ;
if ( NULL == V_6 )
return - V_44 ;
F_14 ( L_59 , V_6 -> V_97 ) ;
V_108 = - V_137 ;
if ( ! V_6 -> V_7 . V_8 )
goto V_157;
V_108 = - V_147 ;
V_4 = F_85 ( sizeof( * V_4 ) , V_146 ) ;
if ( NULL == V_4 )
goto V_157;
V_4 -> V_77 = V_119 ;
V_4 -> V_6 = V_6 ;
V_6 -> V_158 = V_4 ;
V_108 = F_50 ( V_4 ) ;
if ( V_108 != 0 )
goto V_159;
F_59 ( & V_4 -> V_153 ) ;
F_84 ( & V_143 ) ;
F_22 ( & V_4 -> V_160 , & V_161 ) ;
F_86 ( & V_143 ) ;
F_4 ( V_4 ) ;
return 0 ;
V_159:
F_89 ( V_4 ) ;
V_157:
V_6 -> V_158 = NULL ;
F_92 ( V_6 , V_119 ) ;
return V_108 ;
}
static void T_5 F_93 ( struct V_119 * V_119 )
{
struct V_3 * V_4 ;
V_4 = F_69 ( V_119 ) ;
F_10 ( 1 , L_25 , V_43 ) ;
F_7 ( V_4 ) ;
F_84 ( & V_4 -> V_6 -> V_152 ) ;
if ( ! F_19 ( & V_4 -> V_153 ) ) {
struct V_122 * V_127 , * V_162 ;
int V_108 ;
F_14 ( V_99 L_60
L_61 ,
V_4 -> V_6 -> V_97 ) ;
F_88 (drv, tmp, &dev->drvlist, drvlist) {
V_108 = V_127 -> remove ( V_127 ) ;
if ( V_108 == 0 ) {
F_21 ( & V_127 -> V_153 ) ;
} else
F_14 ( V_118 L_57
L_58 , V_4 -> V_6 -> V_97 , V_108 ) ;
F_89 ( V_127 ) ;
}
}
F_86 ( & V_4 -> V_6 -> V_152 ) ;
V_4 -> V_6 -> V_158 = NULL ;
F_64 ( V_4 ) ;
F_92 ( V_4 -> V_6 , V_4 -> V_77 ) ;
F_89 ( V_4 ) ;
}
static int T_6 F_94 ( void )
{
F_14 ( V_114 L_62 ,
( V_163 >> 16 ) & 0xff ,
( V_163 >> 8 ) & 0xff ,
V_163 & 0xff ) ;
#ifdef F_95
F_14 ( V_114 L_63 ,
F_95 / 10000 , ( F_95 / 100 ) % 100 , F_95 % 100 ) ;
#endif
return F_96 ( & V_164 ) ;
}
static void T_7 F_97 ( void )
{
F_98 ( & V_164 ) ;
}
