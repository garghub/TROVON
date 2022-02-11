static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_10 * V_11 ;
int V_12 ;
for ( V_12 = 0 ; ; V_12 ++ ) {
if ( F_4 ( & V_8 -> V_13 ) ) {
F_5 ( 1 , L_1 , V_12 ) ;
break;
}
V_11 = F_6 ( V_8 -> V_13 . V_14 , struct V_10 ,
V_15 . V_16 ) ;
if ( ( V_17 ) ( V_9 - V_11 -> V_9 ) < 0 )
break;
F_7 ( & V_11 -> V_15 . V_18 ) ;
V_11 -> V_15 . V_19 = V_20 ;
F_8 ( & V_11 -> V_15 . V_16 ) ;
F_9 ( & V_11 -> V_15 . V_21 ) ;
}
if ( F_4 ( & V_8 -> V_13 ) )
F_10 ( & V_8 -> V_22 ) ;
else
F_11 ( & V_8 -> V_22 , V_23 + V_24 ) ;
if ( V_12 != 1 )
F_12 ( L_2 , V_25 , V_12 ) ;
}
int F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_10 * V_11 ,
const struct V_26 * V_27 )
{
int V_28 = 0 ;
F_14 ( V_6 , V_27 , V_11 -> V_29 , V_11 -> V_30 . V_31 ) ;
F_15 ( V_27 -> V_32 , 3 ) ;
V_8 -> V_9 = 1 ;
F_16 ( V_33 , F_17 ( V_33 ) | ( 1 << V_27 -> V_3 ) ) ;
F_16 ( V_27 -> V_34 , 0x11 ) ;
F_15 ( V_27 -> V_35 , 0x11 ) ;
V_28 = F_17 ( V_36 ) ;
F_15 ( V_36 , V_28 & 0xFFFFFE00 ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_26 * V_27 )
{
struct V_10 * V_11 , * V_37 ;
struct V_38 * V_39 ;
if ( ! F_4 ( & V_8 -> V_13 ) ) {
V_11 = F_6 ( V_8 -> V_13 . V_14 , struct V_10 ,
V_15 . V_16 ) ;
F_13 ( V_6 , V_8 , V_11 , V_27 ) ;
F_19 (item, &q->active) {
V_11 = F_6 ( V_39 , struct V_10 , V_15 . V_16 ) ;
V_11 -> V_9 = V_8 -> V_9 ++ ;
}
F_11 ( & V_8 -> V_22 , V_23 + V_24 ) ;
return 0 ;
}
V_37 = NULL ;
for (; ; ) {
if ( F_4 ( & V_8 -> V_40 ) )
return 0 ;
V_11 = F_6 ( V_8 -> V_40 . V_14 , struct V_10 ,
V_15 . V_16 ) ;
if ( NULL == V_37 ) {
F_20 ( & V_11 -> V_15 . V_16 , & V_8 -> V_13 ) ;
F_13 ( V_6 , V_8 , V_11 , V_27 ) ;
V_11 -> V_15 . V_19 = V_41 ;
V_11 -> V_9 = V_8 -> V_9 ++ ;
F_11 ( & V_8 -> V_22 , V_23 + V_24 ) ;
} else if ( V_37 -> V_15 . V_42 == V_11 -> V_15 . V_42 &&
V_37 -> V_15 . V_43 == V_11 -> V_15 . V_43 &&
V_37 -> V_44 == V_11 -> V_44 ) {
F_20 ( & V_11 -> V_15 . V_16 , & V_8 -> V_13 ) ;
V_11 -> V_15 . V_19 = V_41 ;
V_11 -> V_9 = V_8 -> V_9 ++ ;
V_37 -> V_30 . V_45 [ 1 ] = F_21 ( V_11 -> V_30 . V_31 ) ;
V_37 -> V_30 . V_45 [ 2 ] = F_21 ( 0 ) ;
} else {
return 0 ;
}
V_37 = V_11 ;
}
}
static void F_22 ( unsigned long V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
struct V_5 * V_6 = V_48 -> V_6 ;
const struct V_26 * V_27 = V_48 -> V_27 ;
struct V_7 * V_8 = & V_6 -> V_49 [ V_27 -> V_3 ] . V_50 ;
struct V_10 * V_11 ;
unsigned long V_51 ;
F_23 ( V_27 -> V_35 , 0x11 ) ;
F_24 ( & V_6 -> V_52 , V_51 ) ;
while ( ! F_4 ( & V_8 -> V_13 ) ) {
V_11 = F_6 ( V_8 -> V_13 . V_14 , struct V_10 ,
V_15 . V_16 ) ;
F_8 ( & V_11 -> V_15 . V_16 ) ;
V_11 -> V_15 . V_19 = V_53 ;
F_9 ( & V_11 -> V_15 . V_21 ) ;
}
F_18 ( V_6 , V_8 , V_27 ) ;
F_25 ( & V_6 -> V_52 , V_51 ) ;
}
int F_26 ( struct V_5 * V_6 , int V_54 , T_1 V_55 )
{
T_1 V_9 = 0 ;
int V_56 = 0 ;
T_1 V_57 ;
const struct V_26 * V_27 = V_6 -> V_49 [ V_54 ] . V_58 ;
V_57 = F_17 ( V_27 -> V_34 ) ;
if ( 0 == ( V_55 & V_57 ) )
return V_56 ;
F_15 ( V_27 -> V_59 , V_55 ) ;
if ( V_55 & ( 1 << 16 ) ) {
F_27 ( L_3 ,
V_6 -> V_60 , V_27 -> V_60 ) ;
F_23 ( V_27 -> V_35 , 0x11 ) ;
F_28 ( V_6 , V_27 ) ;
}
if ( V_55 & V_61 ) {
F_29 ( & V_6 -> V_52 ) ;
V_9 = F_17 ( V_27 -> V_62 ) ;
F_3 ( V_6 , & V_6 -> V_49 [ V_27 -> V_3 ] . V_50 ,
V_9 ) ;
F_30 ( & V_6 -> V_52 ) ;
V_56 ++ ;
}
if ( V_55 & 0x10 ) {
F_5 ( 2 , L_4 ) ;
F_29 ( & V_6 -> V_52 ) ;
F_18 ( V_6 ,
& V_6 -> V_49 [ V_27 -> V_3 ] . V_50 , V_27 ) ;
F_30 ( & V_6 -> V_52 ) ;
V_56 ++ ;
}
return V_56 ;
}
static int F_31 ( struct V_63 * V_8 , unsigned int * V_9 ,
unsigned int * V_64 )
{
struct V_65 * V_66 = V_8 -> V_67 ;
* V_64 = V_66 -> V_44 -> V_68 * V_66 -> V_42 * V_66 -> V_43 >> 3 ;
if ( 0 == * V_9 )
* V_9 = 32 ;
if ( * V_64 * * V_9 > V_69 * 1024 * 1024 )
* V_9 = ( V_69 * 1024 * 1024 ) / * V_64 ;
return 0 ;
}
static int F_32 ( struct V_63 * V_8 , struct V_70 * V_15 ,
enum V_71 V_72 )
{
struct V_65 * V_66 = V_8 -> V_67 ;
struct V_5 * V_6 = V_66 -> V_6 ;
struct V_10 * V_11 =
F_33 ( V_15 , struct V_10 , V_15 ) ;
int V_73 , V_74 = 0 ;
T_1 V_75 ;
struct V_76 * V_31 = F_34 ( & V_11 -> V_15 ) ;
int V_77 = V_78 ;
F_35 ( NULL == V_66 -> V_44 ) ;
if ( V_66 -> V_42 < 48 || V_66 -> V_42 > 720 ||
V_66 -> V_43 < 32 || V_66 -> V_43 > 576 )
return - V_79 ;
V_11 -> V_15 . V_64 = ( V_66 -> V_42 * V_66 -> V_43 * V_66 -> V_44 -> V_68 ) >> 3 ;
if ( 0 != V_11 -> V_15 . V_80 && V_11 -> V_15 . V_81 < V_11 -> V_15 . V_64 )
return - V_79 ;
if ( V_11 -> V_44 != V_66 -> V_44 ||
V_11 -> V_15 . V_42 != V_66 -> V_42 ||
V_11 -> V_15 . V_43 != V_66 -> V_43 || V_11 -> V_15 . V_72 != V_72 ) {
V_11 -> V_44 = V_66 -> V_44 ;
V_11 -> V_15 . V_42 = V_66 -> V_42 ;
V_11 -> V_15 . V_43 = V_66 -> V_43 ;
V_11 -> V_15 . V_72 = V_72 ;
V_74 = 1 ;
}
if ( V_82 == V_11 -> V_15 . V_19 ) {
V_74 = 1 ;
V_73 = F_36 ( V_8 , & V_11 -> V_15 , NULL ) ;
if ( 0 != V_73 ) {
F_37 (KERN_DEBUG pr_fmt(L_5)) ;
goto V_83;
}
}
F_5 ( 1 , L_6 , V_74 ) ;
if ( V_74 ) {
if ( V_66 -> V_84 == V_85 )
V_11 -> V_29 = ( V_11 -> V_44 -> V_68 * V_11 -> V_15 . V_42 ) >> 3 ;
else
V_11 -> V_29 = ( V_11 -> V_44 -> V_68 >> 3 ) * ( V_11 -> V_15 . V_42 ) ;
if ( V_66 -> V_84 == V_85 ) {
V_77 = V_11 -> V_29 ;
} else {
V_77 = V_11 -> V_29 ;
if ( V_66 -> V_86 ) {
if ( V_6 -> V_87 & V_88 )
V_77 = 352 << 1 ;
else
V_77 = V_66 -> V_89 << 1 ;
}
}
switch ( V_11 -> V_15 . V_72 ) {
case V_90 :
F_38 ( V_6 -> V_91 , & V_11 -> V_30 ,
V_31 -> V_92 , 0 , V_93 ,
V_11 -> V_29 , 0 , V_11 -> V_15 . V_43 ) ;
break;
case V_94 :
F_38 ( V_6 -> V_91 , & V_11 -> V_30 ,
V_31 -> V_92 , V_93 , 0 ,
V_11 -> V_29 , 0 , V_11 -> V_15 . V_43 ) ;
break;
case V_95 :
V_75 = 0 ;
F_5 ( 1 , L_7 ) ;
F_38 ( V_6 -> V_91 , & V_11 -> V_30 ,
V_31 -> V_92 , V_75 ,
V_77 , V_77 , V_77 ,
V_11 -> V_15 . V_43 >> 1 ) ;
break;
case V_96 :
F_38 ( V_6 -> V_91 , & V_11 -> V_30 ,
V_31 -> V_92 ,
0 , V_11 -> V_29 * ( V_11 -> V_15 . V_43 >> 1 ) ,
V_11 -> V_29 , 0 , V_11 -> V_15 . V_43 >> 1 ) ;
break;
case V_97 :
F_38 ( V_6 -> V_91 , & V_11 -> V_30 ,
V_31 -> V_92 ,
V_11 -> V_29 * ( V_11 -> V_15 . V_43 >> 1 ) , 0 ,
V_11 -> V_29 , 0 , V_11 -> V_15 . V_43 >> 1 ) ;
break;
default:
F_39 () ;
}
}
F_5 ( 2 , L_8 ,
V_11 , V_11 -> V_15 . V_3 , V_66 -> V_42 , V_66 -> V_43 , V_66 -> V_44 -> V_68 ,
V_66 -> V_44 -> V_60 , ( unsigned long ) V_11 -> V_30 . V_31 ) ;
V_11 -> V_15 . V_19 = V_98 ;
return 0 ;
V_83:
F_40 ( V_8 , V_11 ) ;
return V_73 ;
}
static void F_41 ( struct V_63 * V_8 ,
struct V_70 * V_15 )
{
struct V_10 * V_11 =
F_33 ( V_15 , struct V_10 , V_15 ) ;
F_40 ( V_8 , V_11 ) ;
}
static int F_42 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
return F_44 ( & V_66 -> V_102 , V_101 ) ;
}
static void F_45 ( struct V_63 * V_103 , struct V_70 * V_15 )
{
struct V_10 * V_11 =
F_33 ( V_15 , struct V_10 , V_15 ) ;
struct V_10 * V_37 ;
struct V_65 * V_66 = V_103 -> V_67 ;
struct V_5 * V_6 = V_66 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_49 [ V_66 -> V_104 ] . V_50 ;
V_11 -> V_30 . V_45 [ 0 ] = F_21 ( V_105 | V_106 | V_107 ) ;
V_11 -> V_30 . V_45 [ 1 ] = F_21 ( V_8 -> V_108 . V_31 ) ;
V_11 -> V_30 . V_45 [ 2 ] = F_21 ( 0 ) ;
F_5 ( 2 , L_9 , V_11 -> V_30 . V_45 [ 1 ] ) ;
if ( ! F_4 ( & V_8 -> V_40 ) ) {
F_46 ( & V_11 -> V_15 . V_16 , & V_8 -> V_40 ) ;
V_11 -> V_15 . V_19 = V_109 ;
F_5 ( 2 , L_10 , V_11 ,
V_11 -> V_15 . V_3 ) ;
} else if ( F_4 ( & V_8 -> V_13 ) ) {
F_46 ( & V_11 -> V_15 . V_16 , & V_8 -> V_13 ) ;
F_13 ( V_6 , V_8 , V_11 , V_66 -> V_58 ) ;
V_11 -> V_15 . V_19 = V_41 ;
V_11 -> V_9 = V_8 -> V_9 ++ ;
F_11 ( & V_8 -> V_22 , V_23 + V_24 ) ;
F_5 ( 2 , L_11 ,
V_11 , V_11 -> V_15 . V_3 , V_11 -> V_9 , V_8 -> V_9 ) ;
} else {
V_37 = F_6 ( V_8 -> V_13 . V_37 , struct V_10 ,
V_15 . V_16 ) ;
if ( V_37 -> V_15 . V_42 == V_11 -> V_15 . V_42
&& V_37 -> V_15 . V_43 == V_11 -> V_15 . V_43
&& V_37 -> V_44 == V_11 -> V_44 ) {
F_46 ( & V_11 -> V_15 . V_16 , & V_8 -> V_13 ) ;
V_11 -> V_15 . V_19 = V_41 ;
V_11 -> V_9 = V_8 -> V_9 ++ ;
V_37 -> V_30 . V_45 [ 1 ] = F_21 ( V_11 -> V_30 . V_31 ) ;
V_37 -> V_30 . V_45 [ 2 ] = F_21 ( 0 ) ;
F_5 ( 2 , L_12 ,
V_11 , V_11 -> V_15 . V_3 , V_11 -> V_9 ) ;
} else {
F_46 ( & V_11 -> V_15 . V_16 , & V_8 -> V_40 ) ;
V_11 -> V_15 . V_19 = V_109 ;
F_5 ( 2 , L_13 , V_11 ,
V_11 -> V_15 . V_3 ) ;
}
}
if ( F_4 ( & V_8 -> V_13 ) )
F_5 ( 2 , L_14 ) ;
}
static T_2 F_47 ( struct V_99 * V_99 , char T_3 * V_46 , T_4 V_9 ,
T_5 * V_110 )
{
struct V_111 * V_112 = V_99 -> V_113 ;
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
int V_114 = 0 ;
if ( F_48 ( & V_6 -> V_115 ) )
return - V_116 ;
if ( V_66 -> V_117 && V_66 -> V_117 != V_112 ) {
V_114 = - V_118 ;
goto V_119;
}
V_66 -> V_117 = V_112 ;
V_114 = F_49 ( & V_66 -> V_102 , V_46 , V_9 , V_110 ,
V_99 -> V_120 & V_121 ) ;
V_119:
F_50 ( & V_6 -> V_115 ) ;
return V_114 ;
}
static unsigned int F_51 ( struct V_99 * V_99 ,
struct V_122 * V_123 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
unsigned long V_124 = F_52 ( V_123 ) ;
unsigned int V_125 = F_53 ( V_99 , V_123 ) ;
if ( V_124 & ( V_126 | V_127 ) )
V_125 |= F_54 ( V_99 , & V_66 -> V_102 , V_123 ) ;
return V_125 ;
}
static int F_55 ( struct V_99 * V_99 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_111 * V_112 = V_99 -> V_113 ;
struct V_5 * V_6 = V_66 -> V_6 ;
const struct V_26 * V_128 =
V_6 -> V_49 [ 0 ] . V_58 ;
F_56 ( & V_6 -> V_115 ) ;
F_15 ( V_128 -> V_35 , 0 ) ;
if ( V_66 -> V_117 == V_112 ) {
F_57 ( & V_66 -> V_102 ) ;
V_66 -> V_117 = NULL ;
}
if ( V_66 -> V_102 . V_129 ) {
F_41 ( & V_66 -> V_102 , V_66 -> V_102 . V_129 ) ;
F_58 ( V_66 -> V_102 . V_129 ) ;
}
F_59 ( & V_66 -> V_102 ) ;
F_50 ( & V_6 -> V_115 ) ;
return F_60 ( V_99 ) ;
}
static int F_61 ( struct V_99 * V_99 , void * V_130 ,
struct V_131 * V_132 )
{
if ( F_62 ( V_132 -> V_133 >= F_2 ( V_4 ) ) )
return - V_79 ;
F_63 ( V_132 -> V_134 , V_4 [ V_132 -> V_133 ] . V_60 , sizeof( V_132 -> V_134 ) ) ;
V_132 -> V_135 = V_4 [ V_132 -> V_133 ] . V_2 ;
return 0 ;
}
static int F_64 ( struct V_99 * V_99 , void * V_130 ,
struct V_136 * V_132 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
V_132 -> V_44 . V_137 . V_42 = V_66 -> V_42 ;
V_132 -> V_44 . V_137 . V_43 = V_66 -> V_43 ;
V_132 -> V_44 . V_137 . V_72 = V_66 -> V_102 . V_72 ;
V_132 -> V_44 . V_137 . V_135 = V_66 -> V_44 -> V_2 ;
V_132 -> V_44 . V_137 . V_138 = ( V_66 -> V_42 * V_66 -> V_44 -> V_68 ) >> 3 ;
V_132 -> V_44 . V_137 . V_139 = V_66 -> V_43 * V_132 -> V_44 . V_137 . V_138 ;
V_132 -> V_44 . V_137 . V_140 = V_141 ;
V_132 -> V_44 . V_137 . V_130 = 0 ;
return 0 ;
}
static int F_65 ( struct V_99 * V_99 , void * V_130 ,
struct V_136 * V_132 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
const struct V_1 * V_44 ;
enum V_71 V_72 = V_132 -> V_44 . V_137 . V_72 ;
unsigned int V_142 ;
unsigned V_143 ;
V_44 = F_1 ( V_132 -> V_44 . V_137 . V_135 ) ;
if ( NULL == V_44 )
return - V_79 ;
V_142 = ( V_6 -> V_87 & V_88 ) ? 576 : 480 ;
V_143 = V_132 -> V_44 . V_137 . V_42 ;
if ( V_72 != V_94 )
V_72 = V_90 ;
if ( V_143 < 352 ) {
V_143 = 176 ;
V_132 -> V_44 . V_137 . V_43 = V_142 / 4 ;
} else if ( V_143 < 720 ) {
V_143 = 352 ;
V_132 -> V_44 . V_137 . V_43 = V_142 / 2 ;
} else {
V_143 = 720 ;
V_132 -> V_44 . V_137 . V_43 = V_142 ;
V_72 = V_95 ;
}
V_132 -> V_44 . V_137 . V_72 = V_72 ;
V_132 -> V_44 . V_137 . V_42 = V_143 ;
V_132 -> V_44 . V_137 . V_138 = ( V_132 -> V_44 . V_137 . V_42 * V_44 -> V_68 ) >> 3 ;
V_132 -> V_44 . V_137 . V_139 = V_132 -> V_44 . V_137 . V_43 * V_132 -> V_44 . V_137 . V_138 ;
V_132 -> V_44 . V_137 . V_140 = V_141 ;
V_132 -> V_44 . V_137 . V_130 = 0 ;
return 0 ;
}
static int F_66 ( struct V_99 * V_99 , void * V_130 ,
struct V_136 * V_132 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
int V_144 = V_145 ;
int V_114 ;
V_114 = F_65 ( V_99 , V_130 , V_132 ) ;
if ( 0 != V_114 )
return V_114 ;
V_66 -> V_44 = F_1 ( V_132 -> V_44 . V_137 . V_135 ) ;
V_66 -> V_102 . V_72 = V_132 -> V_44 . V_137 . V_72 ;
V_66 -> V_42 = V_132 -> V_44 . V_137 . V_42 ;
V_66 -> V_43 = V_132 -> V_44 . V_137 . V_43 ;
if ( V_132 -> V_44 . V_137 . V_135 == V_146 )
V_144 = V_85 ;
else
V_144 = V_145 ;
F_67 ( V_6 , V_147 , V_144 ) ;
if ( V_66 -> V_42 == 320 || V_66 -> V_42 == 352 )
V_66 -> V_86 = 1 ;
else
V_66 -> V_86 = 0 ;
V_66 -> V_89 = V_66 -> V_42 ;
F_68 ( V_6 , V_66 -> V_42 , V_147 ) ;
return 0 ;
}
static int F_69 ( struct V_99 * V_99 , void * V_130 , enum V_148 V_3 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
if ( V_3 != V_149 )
return - V_79 ;
if ( V_66 -> V_117 && V_66 -> V_117 != V_130 )
return - V_118 ;
V_66 -> V_117 = V_130 ;
return F_70 ( & V_66 -> V_102 ) ;
}
static int F_71 ( struct V_99 * V_99 , void * V_130 , enum V_148 V_3 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
if ( V_3 != V_149 )
return - V_79 ;
if ( V_66 -> V_117 && V_66 -> V_117 != V_130 )
return - V_118 ;
if ( V_66 -> V_117 == NULL )
return 0 ;
V_66 -> V_117 = NULL ;
return F_72 ( & V_66 -> V_102 ) ;
}
static int F_73 ( struct V_99 * V_99 , void * V_130 , struct V_150 * V_151 )
{
int V_152 = 0 ;
struct V_65 * V_66 = F_43 ( V_99 ) ;
V_152 = F_74 ( & V_66 -> V_102 , V_151 , V_99 -> V_120 & V_121 ) ;
V_151 -> V_153 = V_66 -> V_50 . V_9 ;
return V_152 ;
}
static int F_75 ( struct V_99 * V_99 , void * V_130 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
const struct V_26 * V_128 = V_66 -> V_58 ;
T_1 V_28 = 0 ;
V_28 = F_17 ( V_128 -> V_35 ) ;
F_76 ( L_15 ,
( V_28 & 0x11 ) ? L_16 : L_17 ) ;
return 0 ;
}
static int F_77 ( struct V_99 * V_99 , void * V_130 ,
struct V_154 * V_155 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
const T_1 V_156 = V_157 |
V_158 | V_159 ;
const T_1 V_160 = V_161 | V_158 ;
strcpy ( V_155 -> V_162 , L_18 ) ;
F_63 ( V_155 -> V_163 , V_164 [ V_6 -> V_165 ] . V_60 , sizeof( V_155 -> V_163 ) ) ;
sprintf ( V_155 -> V_166 , L_19 , F_78 ( V_6 -> V_91 ) ) ;
if ( V_66 -> V_104 >= V_167 )
V_155 -> V_168 = V_160 ;
else
V_155 -> V_168 = V_156 ;
V_155 -> V_169 = V_156 | V_160 | V_170 ;
return 0 ;
}
static int F_79 ( struct V_99 * V_99 , void * V_130 ,
struct V_171 * V_151 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
return F_80 ( & V_66 -> V_102 , V_151 ) ;
}
static int F_81 ( struct V_99 * V_99 , void * V_130 ,
struct V_150 * V_151 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
return F_82 ( & V_66 -> V_102 , V_151 ) ;
}
static int F_83 ( struct V_99 * V_99 , void * V_130 , struct V_150 * V_151 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
return F_84 ( & V_66 -> V_102 , V_151 ) ;
}
static int F_85 ( struct V_99 * V_99 , void * V_130 , T_6 * V_172 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
* V_172 = V_66 -> V_6 -> V_87 ;
return 0 ;
}
static int F_86 ( struct V_99 * V_99 , void * V_130 ,
T_6 V_172 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
if ( V_6 -> V_87 == V_172 )
return 0 ;
V_6 -> V_87 = V_172 ;
V_66 -> V_42 = 720 ;
V_66 -> V_43 = ( V_6 -> V_87 & V_88 ) ? 576 : 480 ;
F_87 ( V_6 ) ;
return 0 ;
}
static int F_88 ( struct V_99 * V_99 , void * V_130 ,
struct V_173 * V_3 )
{
if ( V_3 -> V_133 )
return - V_79 ;
V_3 -> type = V_174 ;
V_3 -> V_175 = V_176 ;
strcpy ( V_3 -> V_60 , L_20 ) ;
return 0 ;
}
static int F_89 ( struct V_99 * V_99 , void * V_130 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_90 ( struct V_99 * V_99 , void * V_130 , unsigned int V_3 )
{
return V_3 ? - V_79 : 0 ;
}
static int F_91 ( struct V_177 * V_178 )
{
struct V_65 * V_66 =
F_33 ( V_178 -> V_179 , struct V_65 , V_180 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
switch ( V_178 -> V_104 ) {
case V_181 :
F_92 ( V_6 , V_178 -> V_182 , V_66 -> V_104 ) ;
break;
case V_183 :
F_93 ( V_6 , V_178 -> V_182 , V_66 -> V_104 ) ;
break;
case V_184 :
F_94 ( V_6 , V_178 -> V_182 , V_66 -> V_104 ) ;
break;
case V_185 :
F_95 ( V_6 , V_178 -> V_182 , V_66 -> V_104 ) ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_96 ( struct V_99 * V_99 , void * V_130 ,
struct V_186 * V_187 )
{
if ( V_187 -> V_133 )
return - V_79 ;
V_187 -> type = V_174 ;
V_187 -> V_175 = V_176 ;
strcpy ( V_187 -> V_60 , L_20 ) ;
return 0 ;
}
static int F_97 ( struct V_99 * V_99 , void * V_130 , unsigned int * V_187 )
{
* V_187 = 0 ;
return 0 ;
}
static int F_98 ( struct V_99 * V_99 , void * V_130 , unsigned int V_187 )
{
return V_187 ? - V_79 : 0 ;
}
static int F_99 ( struct V_99 * V_99 , void * V_130 ,
struct V_136 * V_132 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
const struct V_1 * V_44 ;
V_44 = F_1 ( V_132 -> V_44 . V_137 . V_135 ) ;
if ( NULL == V_44 )
return - V_79 ;
V_132 -> V_44 . V_137 . V_42 = 720 ;
V_132 -> V_44 . V_137 . V_43 = ( V_6 -> V_87 & V_88 ) ? 576 : 480 ;
V_132 -> V_44 . V_137 . V_72 = V_95 ;
V_132 -> V_44 . V_137 . V_138 = ( V_132 -> V_44 . V_137 . V_42 * V_44 -> V_68 ) >> 3 ;
V_132 -> V_44 . V_137 . V_139 = V_132 -> V_44 . V_137 . V_43 * V_132 -> V_44 . V_137 . V_138 ;
V_132 -> V_44 . V_137 . V_140 = V_141 ;
V_132 -> V_44 . V_137 . V_130 = 0 ;
return 0 ;
}
static int F_100 ( struct V_99 * V_99 , void * V_130 ,
struct V_136 * V_132 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
int V_114 ;
V_114 = F_99 ( V_99 , V_130 , V_132 ) ;
if ( 0 != V_114 )
return V_114 ;
V_66 -> V_44 = F_1 ( V_132 -> V_44 . V_137 . V_135 ) ;
V_66 -> V_102 . V_72 = V_132 -> V_44 . V_137 . V_72 ;
V_66 -> V_42 = V_132 -> V_44 . V_137 . V_42 ;
V_66 -> V_43 = V_132 -> V_44 . V_137 . V_43 ;
if ( V_132 -> V_44 . V_137 . V_135 == V_146 )
V_66 -> V_84 = V_85 ;
else
V_66 -> V_84 = V_145 ;
return 0 ;
}
static T_2 F_101 ( struct V_99 * V_99 , const char T_3 * V_46 , T_4 V_9 ,
T_5 * V_110 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
struct V_111 * V_112 = V_99 -> V_113 ;
int V_114 = 0 ;
if ( F_48 ( & V_6 -> V_115 ) )
return - V_116 ;
if ( V_66 -> V_117 && V_66 -> V_117 != V_112 ) {
V_114 = - V_118 ;
goto V_119;
}
if ( ! V_66 -> V_117 ) {
V_114 = F_102 ( V_66 , V_66 -> V_84 ) ;
if ( V_114 )
goto V_119;
V_66 -> V_117 = V_112 ;
}
V_114 = F_103 ( V_66 , V_46 , V_9 ) ;
V_9 -= V_114 ;
* V_110 += V_114 ;
V_119:
F_50 ( & V_6 -> V_115 ) ;
return V_114 ;
}
static int F_104 ( struct V_99 * V_99 )
{
struct V_65 * V_66 = F_43 ( V_99 ) ;
struct V_5 * V_6 = V_66 -> V_6 ;
struct V_111 * V_112 = V_99 -> V_113 ;
F_56 ( & V_6 -> V_115 ) ;
if ( V_66 -> V_117 == V_112 ) {
F_105 ( V_66 ) ;
V_66 -> V_117 = NULL ;
}
F_50 ( & V_6 -> V_115 ) ;
return F_60 ( V_99 ) ;
}
void F_106 ( struct V_5 * V_6 , int V_54 )
{
F_23 ( V_33 , 1 ) ;
if ( F_107 ( & V_6 -> V_49 [ V_54 ] . V_188 ) ) {
F_108 ( & V_6 -> V_49 [ V_54 ] . V_188 ) ;
F_109 ( & V_6 -> V_49 [ V_54 ] . V_180 ) ;
F_110 ( V_6 -> V_91 ,
& V_6 -> V_49 [ V_54 ] . V_50 . V_108 ) ;
}
}
int F_111 ( struct V_5 * V_6 )
{
int V_114 ;
int V_3 ;
V_6 -> V_87 = V_189 ;
F_112 ( & V_6 -> V_52 ) ;
for ( V_3 = 0 ; V_3 < V_190 - 1 ; ++ V_3 ) {
struct V_65 * V_66 = & V_6 -> V_49 [ V_3 ] ;
struct V_191 * V_188 = & V_66 -> V_188 ;
struct V_192 * V_180 = & V_66 -> V_180 ;
bool V_193 = V_3 > V_194 ;
if ( V_3 == V_194 )
continue;
if ( ! V_193 ) {
F_113 ( V_180 , 4 ) ;
F_114 ( V_180 , & V_195 ,
V_181 , 0 , 10000 , 1 , 6200 ) ;
F_114 ( V_180 , & V_195 ,
V_184 , 0 , 10000 , 1 , 5000 ) ;
F_114 ( V_180 , & V_195 ,
V_185 , 0 , 10000 , 1 , 5000 ) ;
F_114 ( V_180 , & V_195 ,
V_183 , 0 , 10000 , 1 , 5000 ) ;
if ( V_180 -> error ) {
V_114 = V_180 -> error ;
goto V_196;
}
V_114 = F_115 ( V_180 ) ;
if ( V_114 )
goto V_196;
} else {
V_66 -> V_197 = & V_6 -> V_198 [ V_3 - V_199 ] ;
V_66 -> V_197 -> V_66 = V_66 ;
}
F_116 ( V_6 -> V_91 , & V_66 -> V_50 . V_108 ,
V_66 -> V_58 -> V_35 , 0x11 , 0 ) ;
V_66 -> V_58 = & V_200 [ V_3 ] ;
V_66 -> V_42 = 720 ;
if ( V_6 -> V_87 & V_88 )
V_66 -> V_43 = 576 ;
else
V_66 -> V_43 = 480 ;
if ( V_66 -> V_84 == V_85 )
V_66 -> V_44 = F_1 ( V_146 ) ;
else
V_66 -> V_44 = F_1 ( V_201 ) ;
F_15 ( V_66 -> V_58 -> V_59 , 0xffffffff ) ;
F_117 ( & V_66 -> V_50 . V_13 ) ;
F_117 ( & V_66 -> V_50 . V_40 ) ;
V_66 -> V_48 . V_6 = V_6 ;
V_66 -> V_48 . V_27 = & V_200 [ V_3 ] ;
V_66 -> V_50 . V_22 . V_202 = F_22 ;
V_66 -> V_50 . V_22 . V_46 = ( unsigned long ) & V_66 -> V_48 ;
F_118 ( & V_66 -> V_50 . V_22 ) ;
if ( ! V_193 )
F_119 ( & V_66 -> V_102 , & V_203 , & V_6 -> V_91 -> V_6 ,
& V_6 -> V_52 , V_149 ,
V_95 , sizeof( struct V_10 ) ,
V_66 , & V_6 -> V_115 ) ;
* V_188 = V_193 ? V_204 : V_205 ;
V_188 -> V_206 = & V_6 -> V_206 ;
if ( ! V_193 )
V_188 -> V_207 = V_180 ;
else
V_188 -> V_208 = V_209 ;
V_188 -> V_115 = & V_6 -> V_115 ;
F_120 ( V_210 , & V_188 -> V_51 ) ;
snprintf ( V_188 -> V_60 , sizeof( V_188 -> V_60 ) , L_21 , V_6 -> V_60 , V_3 ) ;
F_121 ( V_188 , V_66 ) ;
V_114 = F_122 ( V_188 , V_211 ,
V_212 [ V_6 -> V_213 ] ) ;
if ( V_114 < 0 )
goto V_196;
}
F_16 ( V_33 , 0xff ) ;
return 0 ;
V_196:
while ( V_3 >= 0 )
F_106 ( V_6 , V_3 -- ) ;
return V_114 ;
}
