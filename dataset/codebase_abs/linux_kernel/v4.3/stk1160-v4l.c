static unsigned int
F_1 ( unsigned int V_1 , unsigned int V_2 )
{
for (; ; V_2 ++ ) {
if ( V_1 % V_2 == 0 )
return V_1 / V_2 ;
}
}
static void F_2 ( struct V_3 * V_4 )
{
int V_5 ;
static struct V_6 V_7 [] = {
{ V_8 , 0x0000 } ,
{ V_9 , 0x0000 } ,
{ V_10 , 0x0003 } ,
{ V_11 , 0x0000 } ,
{ V_12 , 0x05a0 } ,
{ V_13 , 0x0005 } ,
{ V_14 , 0x00f3 } ,
{ V_15 , 0x0000 } ,
{ 0xffff , 0xffff }
} ;
static struct V_6 V_16 [] = {
{ V_17 , 0x0000 } ,
{ V_17 + 1 , 0x0000 } ,
{ V_17 + 2 , 0x0001 } ,
{ V_17 + 3 , 0x0000 } ,
{ V_18 , 0x05a0 } ,
{ V_18 + 1 , 0x0005 } ,
{ V_18 + 2 , 0x0121 } ,
{ V_18 + 3 , 0x0001 } ,
{ 0xffff , 0xffff }
} ;
if ( V_4 -> V_19 & V_20 ) {
F_3 ( L_1 ) ;
for ( V_5 = 0 ; V_7 [ V_5 ] . V_21 != 0xffff ; V_5 ++ )
F_4 ( V_4 , V_7 [ V_5 ] . V_21 , V_7 [ V_5 ] . V_22 ) ;
} else {
F_3 ( L_2 ) ;
for ( V_5 = 0 ; V_16 [ V_5 ] . V_21 != 0xffff ; V_5 ++ )
F_4 ( V_4 , V_16 [ V_5 ] . V_21 , V_16 [ V_5 ] . V_22 ) ;
}
}
static void F_5 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
T_1 V_22 = 0 ;
if ( V_24 ) {
V_22 |= V_25 ;
V_22 |= V_24 -> V_26 ? V_27 : 0 ;
V_22 |= V_24 -> V_28 ? V_29 : 0 ;
V_22 |= V_24 -> V_30 ==
V_31 ?
V_32 : 0 ;
V_22 |= V_24 -> V_33 ==
V_31 ?
V_34 : 0 ;
F_4 ( V_4 , V_35 , V_24 -> V_36 ) ;
F_4 ( V_4 , V_37 , V_24 -> V_38 ) ;
F_3 ( L_3 ,
V_22 , V_24 -> V_36 , V_24 -> V_38 ) ;
}
F_4 ( V_4 , V_39 , V_22 ) ;
}
static bool F_6 ( struct V_3 * V_4 )
{
int V_5 , V_40 = V_4 -> V_41 ;
unsigned int V_42 ;
bool V_43 ;
V_42 = V_44 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_45 ; V_5 ++ ) {
if ( V_4 -> V_46 [ V_5 ] >= V_42 ) {
V_4 -> V_41 = V_5 ;
break;
} else if ( V_4 -> V_46 [ V_5 ] >
V_4 -> V_46 [ V_4 -> V_41 ] )
V_4 -> V_41 = V_5 ;
}
F_3 ( L_4 , V_4 -> V_41 ) ;
if ( V_4 -> V_41 != V_40 ) {
F_3 ( L_5 ,
V_42 , V_4 -> V_41 ) ;
F_3 ( L_6 ,
V_4 -> V_41 , V_4 -> V_46 [ V_4 -> V_41 ] ) ;
F_7 ( V_4 -> V_47 , 0 , V_4 -> V_41 ) ;
}
V_43 = V_4 -> V_48 != V_4 -> V_46 [ V_4 -> V_41 ] ;
V_4 -> V_48 = V_4 -> V_46 [ V_4 -> V_41 ] ;
return V_43 ;
}
static int F_8 ( struct V_3 * V_4 )
{
bool V_43 ;
int V_49 = 0 ;
int V_5 ;
if ( ! V_4 -> V_47 )
return - V_50 ;
if ( F_9 ( & V_4 -> V_51 ) )
return - V_52 ;
V_43 = F_6 ( V_4 ) ;
if ( ! V_4 -> V_53 . V_54 || V_43 ) {
V_49 = F_10 ( V_4 ) ;
if ( V_49 < 0 )
goto V_55;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_53 . V_54 ; V_5 ++ ) {
V_49 = F_11 ( V_4 -> V_53 . V_56 [ V_5 ] , V_57 ) ;
if ( V_49 ) {
F_12 ( L_7 , V_5 , V_49 ) ;
goto V_58;
}
}
F_13 ( & V_4 -> V_59 , 0 , V_60 , V_61 , 1 ) ;
V_4 -> V_62 = 0 ;
F_4 ( V_4 , V_63 , 0xb3 ) ;
F_4 ( V_4 , V_63 + 3 , 0x00 ) ;
F_3 ( L_8 ) ;
F_14 ( & V_4 -> V_51 ) ;
return 0 ;
V_58:
F_15 ( V_4 ) ;
V_55:
F_7 ( V_4 -> V_47 , 0 , 0 ) ;
F_16 ( V_4 ) ;
F_14 ( & V_4 -> V_51 ) ;
return V_49 ;
}
static void F_17 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_47 )
return;
V_4 -> V_41 = 0 ;
F_3 ( L_4 , V_4 -> V_41 ) ;
F_7 ( V_4 -> V_47 , 0 , 0 ) ;
F_4 ( V_4 , V_63 , 0x00 ) ;
F_4 ( V_4 , V_63 + 3 , 0x00 ) ;
F_13 ( & V_4 -> V_59 , 0 , V_60 , V_61 , 0 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
if ( F_9 ( & V_4 -> V_51 ) )
return - V_52 ;
F_19 ( V_4 ) ;
if ( ! V_64 )
F_20 ( V_4 ) ;
F_17 ( V_4 ) ;
F_16 ( V_4 ) ;
F_3 ( L_9 ) ;
F_14 ( & V_4 -> V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_65 * V_65 ,
void * V_66 , struct V_67 * V_68 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
strcpy ( V_68 -> V_69 , L_10 ) ;
strcpy ( V_68 -> V_70 , L_10 ) ;
F_23 ( V_4 -> V_47 , V_68 -> V_71 , sizeof( V_68 -> V_71 ) ) ;
V_68 -> V_72 =
V_73 |
V_74 |
V_75 ;
V_68 -> V_76 = V_68 -> V_72 | V_77 ;
return 0 ;
}
static int F_24 ( struct V_65 * V_65 , void * V_66 ,
struct V_78 * V_79 )
{
if ( V_79 -> V_80 != 0 )
return - V_81 ;
F_25 ( V_79 -> V_82 , V_83 [ V_79 -> V_80 ] . V_84 , sizeof( V_79 -> V_82 ) ) ;
V_79 -> V_85 = V_83 [ V_79 -> V_80 ] . V_86 ;
return 0 ;
}
static int F_26 ( struct V_65 * V_65 , void * V_66 ,
struct V_87 * V_79 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
V_79 -> V_88 . V_89 . V_90 = V_4 -> V_90 ;
V_79 -> V_88 . V_89 . V_91 = V_4 -> V_91 ;
V_79 -> V_88 . V_89 . V_92 = V_93 ;
V_79 -> V_88 . V_89 . V_85 = V_4 -> V_88 -> V_86 ;
V_79 -> V_88 . V_89 . V_94 = V_4 -> V_90 * 2 ;
V_79 -> V_88 . V_89 . V_95 = V_4 -> V_91 * V_79 -> V_88 . V_89 . V_94 ;
V_79 -> V_88 . V_89 . V_96 = V_97 ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 , struct V_87 * V_79 ,
struct V_23 * V_24 )
{
unsigned int V_90 , V_91 ;
unsigned int V_98 , V_99 ;
unsigned int V_36 , V_38 ;
enum V_100 V_30 , V_33 ;
bool V_26 , V_28 ;
V_98 = 720 ;
V_99 = ( V_4 -> V_19 & V_20 ) ? 480 : 576 ;
V_90 = F_28 (unsigned int, f->fmt.pix.width,
base_width / 20 , base_width) ;
V_91 = F_28 (unsigned int, f->fmt.pix.height,
base_height / 20 , base_height) ;
V_36 = 0 ;
V_38 = 0 ;
V_26 = false ;
V_28 = false ;
V_79 -> V_88 . V_89 . V_90 = V_98 ;
V_79 -> V_88 . V_89 . V_91 = V_99 ;
V_33 = V_101 ;
V_30 = V_101 ;
if ( V_90 < V_98 && V_90 > V_98 / 2 ) {
V_36 = F_1 ( V_90 , V_98 - V_90 ) ;
if ( V_36 > 0 && V_36 <= 255 ) {
V_26 = true ;
V_30 = V_101 ;
V_79 -> V_88 . V_89 . V_90 = ( V_98 * V_36 ) / ( V_36 + 1 ) ;
}
} else if ( V_90 <= V_98 / 2 ) {
V_36 = F_1 ( V_98 , V_90 ) - 1 ;
if ( V_36 > 0 && V_36 <= 255 ) {
V_26 = true ;
V_30 = V_31 ;
V_79 -> V_88 . V_89 . V_90 = V_98 / ( V_36 + 1 ) ;
}
}
if ( V_91 < V_99 && V_91 > V_99 / 2 ) {
V_38 = F_1 ( V_91 , V_99 - V_91 ) ;
if ( V_38 > 0 && V_38 <= 255 ) {
V_28 = true ;
V_33 = V_101 ;
V_79 -> V_88 . V_89 . V_91 = ( V_99 * V_38 ) / ( V_38 + 1 ) ;
}
} else if ( V_91 <= V_99 / 2 ) {
V_38 = F_1 ( V_99 , V_91 ) - 1 ;
if ( V_38 > 0 && V_38 <= 255 ) {
V_28 = true ;
V_33 = V_31 ;
V_79 -> V_88 . V_89 . V_91 = V_99 / ( V_38 + 1 ) ;
}
}
V_79 -> V_88 . V_89 . V_85 = V_4 -> V_88 -> V_86 ;
V_79 -> V_88 . V_89 . V_92 = V_93 ;
V_79 -> V_88 . V_89 . V_94 = V_79 -> V_88 . V_89 . V_90 * 2 ;
V_79 -> V_88 . V_89 . V_95 = V_79 -> V_88 . V_89 . V_91 * V_79 -> V_88 . V_89 . V_94 ;
V_79 -> V_88 . V_89 . V_96 = V_97 ;
if ( V_24 ) {
V_24 -> V_26 = V_26 ;
V_24 -> V_36 = V_36 ;
V_24 -> V_30 = V_30 ;
V_24 -> V_28 = V_28 ;
V_24 -> V_38 = V_38 ;
V_24 -> V_33 = V_33 ;
}
F_3 ( L_11 ,
V_79 -> V_88 . V_89 . V_90 , V_79 -> V_88 . V_89 . V_91 ) ;
return 0 ;
}
static int F_29 ( struct V_65 * V_65 , void * V_66 ,
struct V_87 * V_79 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
return F_27 ( V_4 , V_79 , NULL ) ;
}
static int F_30 ( struct V_65 * V_65 , void * V_66 ,
struct V_87 * V_79 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
struct V_102 * V_103 = & V_4 -> V_104 ;
struct V_23 V_24 ;
int V_49 ;
if ( F_31 ( V_103 ) )
return - V_105 ;
V_49 = F_27 ( V_4 , V_79 , & V_24 ) ;
if ( V_49 < 0 )
return V_49 ;
V_4 -> V_90 = V_79 -> V_88 . V_89 . V_90 ;
V_4 -> V_91 = V_79 -> V_88 . V_89 . V_91 ;
F_5 ( V_4 , & V_24 ) ;
return 0 ;
}
static int F_32 ( struct V_65 * V_65 , void * V_66 , T_2 * V_19 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
F_13 ( & V_4 -> V_59 , 0 , V_60 , V_106 , V_19 ) ;
return 0 ;
}
static int F_33 ( struct V_65 * V_65 , void * V_66 , T_2 * V_19 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
* V_19 = V_4 -> V_19 ;
return 0 ;
}
static int F_34 ( struct V_65 * V_65 , void * V_66 , T_2 V_19 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
struct V_102 * V_103 = & V_4 -> V_104 ;
if ( V_4 -> V_19 == V_19 )
return 0 ;
if ( F_31 ( V_103 ) )
return - V_105 ;
if ( ! V_4 -> V_47 )
return - V_50 ;
V_4 -> V_90 = 720 ;
V_4 -> V_91 = ( V_19 & V_20 ) ? 480 : 576 ;
V_4 -> V_19 = V_19 ;
F_2 ( V_4 ) ;
F_5 ( V_4 , NULL ) ;
F_13 ( & V_4 -> V_59 , 0 , V_60 , V_107 ,
V_4 -> V_19 ) ;
return 0 ;
}
static int F_35 ( struct V_65 * V_65 , void * V_66 ,
struct V_108 * V_5 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
if ( V_5 -> V_80 > V_109 )
return - V_81 ;
if ( V_5 -> V_80 == V_110 )
sprintf ( V_5 -> V_84 , L_12 ) ;
else
sprintf ( V_5 -> V_84 , L_13 , V_5 -> V_80 ) ;
V_5 -> type = V_111 ;
V_5 -> V_112 = V_4 -> V_113 . V_114 ;
return 0 ;
}
static int F_36 ( struct V_65 * V_65 , void * V_66 , unsigned int * V_5 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
* V_5 = V_4 -> V_115 ;
return 0 ;
}
static int F_37 ( struct V_65 * V_65 , void * V_66 , unsigned int V_5 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
if ( V_5 > V_109 )
return - V_81 ;
V_4 -> V_115 = V_5 ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_39 ( struct V_65 * V_65 , void * V_66 ,
struct V_116 * V_21 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
int V_49 ;
T_3 V_22 ;
V_49 = F_40 ( V_4 , V_21 -> V_21 , & V_22 ) ;
V_21 -> V_22 = V_22 ;
V_21 -> V_117 = 1 ;
return V_49 ;
}
static int F_41 ( struct V_65 * V_65 , void * V_66 ,
const struct V_116 * V_21 )
{
struct V_3 * V_4 = F_22 ( V_65 ) ;
return F_4 ( V_4 , V_21 -> V_21 , V_21 -> V_22 ) ;
}
static int F_42 ( struct V_102 * V_118 , const struct V_87 * V_119 ,
unsigned int * V_120 , unsigned int * V_121 ,
unsigned int V_122 [] , void * V_123 [] )
{
struct V_3 * V_4 = F_43 ( V_118 ) ;
unsigned long V_117 ;
V_117 = V_4 -> V_90 * V_4 -> V_91 * 2 ;
* V_120 = F_28 (unsigned int, *nbuffers,
STK1160_MIN_VIDEO_BUFFERS, STK1160_MAX_VIDEO_BUFFERS) ;
* V_121 = 1 ;
V_122 [ 0 ] = V_117 ;
F_3 ( L_14 ,
V_124 , * V_120 , V_117 ) ;
return 0 ;
}
static void F_44 ( struct V_125 * V_126 )
{
unsigned long V_127 ;
struct V_3 * V_4 = F_43 ( V_126 -> V_102 ) ;
struct V_128 * V_129 =
F_45 ( V_126 , struct V_128 , V_126 ) ;
F_46 ( & V_4 -> V_130 , V_127 ) ;
if ( ! V_4 -> V_47 ) {
F_47 ( & V_129 -> V_126 , V_131 ) ;
} else {
V_129 -> V_132 = F_48 ( V_126 , 0 ) ;
V_129 -> V_133 = F_49 ( V_126 , 0 ) ;
V_129 -> V_134 = 0 ;
V_129 -> V_135 = 0 ;
if ( V_129 -> V_133 < V_4 -> V_90 * V_4 -> V_91 * 2 )
F_47 ( & V_129 -> V_126 , V_131 ) ;
else
F_50 ( & V_129 -> V_136 , & V_4 -> V_137 ) ;
}
F_51 ( & V_4 -> V_130 , V_127 ) ;
}
static int F_52 ( struct V_102 * V_118 , unsigned int V_138 )
{
struct V_3 * V_4 = F_43 ( V_118 ) ;
return F_8 ( V_4 ) ;
}
static void F_53 ( struct V_102 * V_118 )
{
struct V_3 * V_4 = F_43 ( V_118 ) ;
F_18 ( V_4 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
struct V_128 * V_129 ;
unsigned long V_127 ;
F_46 ( & V_4 -> V_130 , V_127 ) ;
while ( ! F_54 ( & V_4 -> V_137 ) ) {
V_129 = F_55 ( & V_4 -> V_137 ,
struct V_128 , V_136 ) ;
F_56 ( & V_129 -> V_136 ) ;
F_47 ( & V_129 -> V_126 , V_131 ) ;
F_3 ( L_15 ,
V_129 , V_129 -> V_126 . V_139 . V_80 ) ;
}
if ( V_4 -> V_53 . V_129 ) {
V_129 = V_4 -> V_53 . V_129 ;
V_4 -> V_53 . V_129 = NULL ;
F_47 ( & V_129 -> V_126 , V_131 ) ;
F_3 ( L_15 ,
V_129 , V_129 -> V_126 . V_139 . V_80 ) ;
}
F_51 ( & V_4 -> V_130 , V_127 ) ;
}
int F_57 ( struct V_3 * V_4 )
{
int V_49 ;
struct V_102 * V_103 ;
V_103 = & V_4 -> V_104 ;
V_103 -> type = V_140 ;
V_103 -> V_141 = V_142 | V_143 | V_144 | V_145 ;
V_103 -> V_146 = V_4 ;
V_103 -> V_147 = sizeof( struct V_128 ) ;
V_103 -> V_148 = & V_149 ;
V_103 -> V_150 = & V_151 ;
V_103 -> V_152 = V_153 ;
V_49 = F_58 ( V_103 ) ;
if ( V_49 < 0 )
return V_49 ;
F_59 ( & V_4 -> V_137 ) ;
return 0 ;
}
int F_60 ( struct V_3 * V_4 )
{
int V_49 ;
V_4 -> V_113 = V_154 ;
V_4 -> V_113 . V_155 = & V_4 -> V_104 ;
V_4 -> V_113 . V_156 = & V_4 -> V_51 ;
V_4 -> V_113 . V_155 -> V_156 = & V_4 -> V_157 ;
V_4 -> V_113 . V_59 = & V_4 -> V_59 ;
V_4 -> V_19 = V_158 ;
V_4 -> V_90 = 720 ;
V_4 -> V_91 = 480 ;
V_4 -> V_88 = & V_83 [ 0 ] ;
F_2 ( V_4 ) ;
F_13 ( & V_4 -> V_59 , 0 , V_60 , V_107 ,
V_4 -> V_19 ) ;
F_61 ( & V_4 -> V_113 , V_4 ) ;
V_49 = F_62 ( & V_4 -> V_113 , V_159 , - 1 ) ;
if ( V_49 < 0 ) {
F_12 ( L_16 , V_49 ) ;
return V_49 ;
}
F_63 ( & V_4 -> V_59 , L_17 ,
F_64 ( & V_4 -> V_113 ) ) ;
return 0 ;
}
