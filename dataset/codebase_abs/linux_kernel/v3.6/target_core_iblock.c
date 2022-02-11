static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( L_1
L_2 , V_2 -> V_4 ,
V_5 , V_6 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static void * F_4 ( struct V_1 * V_2 , const char * V_7 )
{
struct V_8 * V_9 = NULL ;
V_9 = F_5 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 ) {
F_6 ( L_3 ) ;
return NULL ;
}
F_2 ( L_4 , V_7 ) ;
return V_9 ;
}
static struct V_11 * F_7 (
struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * V_14 )
{
struct V_8 * V_9 = V_14 ;
struct V_11 * V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
T_1 V_24 = 0 ;
T_2 V_25 ;
int V_26 = - V_27 ;
if ( ! V_9 ) {
F_6 ( L_5 ) ;
return F_8 ( V_26 ) ;
}
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_9 -> V_28 = F_9 ( V_29 , 0 ) ;
if ( ! V_9 -> V_28 ) {
F_6 ( L_6 ) ;
return F_8 ( - V_30 ) ;
}
F_2 ( L_7 ) ;
F_2 ( L_8 ,
V_9 -> V_31 ) ;
V_25 = V_32 | V_33 ;
if ( ! V_9 -> V_34 )
V_25 |= V_35 ;
V_19 = F_10 ( V_9 -> V_31 , V_25 , V_9 ) ;
if ( F_11 ( V_19 ) ) {
V_26 = F_12 ( V_19 ) ;
goto V_36;
}
V_21 = F_13 ( V_19 ) ;
V_23 = & V_17 . V_23 ;
V_23 -> V_37 = F_14 ( V_19 ) ;
V_23 -> V_38 = V_39 ;
V_23 -> V_40 = V_39 ;
V_17 . V_41 = V_21 -> V_42 ;
V_17 . V_43 = V_21 -> V_42 ;
V_9 -> V_44 = V_19 ;
V_15 = F_15 ( V_2 ,
& V_45 , V_13 , V_24 , V_9 ,
& V_17 , L_9 , V_5 ) ;
if ( ! V_15 )
goto V_36;
if ( F_16 ( V_21 ) ) {
V_15 -> V_46 -> V_47 . V_48 =
V_21 -> V_23 . V_49 ;
V_15 -> V_46 -> V_47 . V_50 = 1 ;
V_15 -> V_46 -> V_47 . V_51 =
V_21 -> V_23 . V_52 >> 9 ;
V_15 -> V_46 -> V_47 . V_53 =
V_21 -> V_23 . V_54 ;
F_2 ( L_10
L_11 ) ;
}
if ( F_17 ( V_21 ) )
V_15 -> V_46 -> V_47 . V_55 = 1 ;
return V_15 ;
V_36:
if ( V_9 -> V_28 ) {
F_18 ( V_9 -> V_28 ) ;
V_9 -> V_28 = NULL ;
}
V_9 -> V_44 = NULL ;
return F_8 ( V_26 ) ;
}
static void F_19 ( void * V_14 )
{
struct V_8 * V_9 = V_14 ;
if ( V_9 -> V_44 != NULL )
F_20 ( V_9 -> V_44 , V_35 | V_32 | V_33 ) ;
if ( V_9 -> V_28 != NULL )
F_18 ( V_9 -> V_28 ) ;
F_21 ( V_9 ) ;
}
static unsigned long long F_22 (
struct V_11 * V_15 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned long long V_56 = ( F_23 ( F_24 ( V_19 -> V_57 ) ,
F_14 ( V_19 ) ) - 1 ) ;
T_1 V_58 = F_14 ( V_19 ) ;
if ( V_58 == V_15 -> V_46 -> V_47 . V_58 )
return V_56 ;
switch ( V_58 ) {
case 4096 :
switch ( V_15 -> V_46 -> V_47 . V_58 ) {
case 2048 :
V_56 <<= 1 ;
break;
case 1024 :
V_56 <<= 2 ;
break;
case 512 :
V_56 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_15 -> V_46 -> V_47 . V_58 ) {
case 4096 :
V_56 >>= 1 ;
break;
case 1024 :
V_56 <<= 1 ;
break;
case 512 :
V_56 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_15 -> V_46 -> V_47 . V_58 ) {
case 4096 :
V_56 >>= 2 ;
break;
case 2048 :
V_56 >>= 1 ;
break;
case 512 :
V_56 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_15 -> V_46 -> V_47 . V_58 ) {
case 4096 :
V_56 >>= 3 ;
break;
case 2048 :
V_56 >>= 2 ;
break;
case 1024 :
V_56 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_56 ;
}
static void F_25 ( struct V_59 * V_59 , int V_60 )
{
struct V_61 * V_62 = V_59 -> V_63 ;
if ( V_60 )
F_6 ( L_12 , V_60 ) ;
if ( V_62 ) {
if ( V_60 ) {
V_62 -> V_64 =
V_65 ;
F_26 ( V_62 , V_66 ) ;
} else {
F_26 ( V_62 , V_67 ) ;
}
}
F_27 ( V_59 ) ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_8 * V_9 = V_62 -> V_13 -> V_68 ;
int V_69 = ( V_62 -> V_70 [ 1 ] & 0x2 ) ;
struct V_59 * V_59 ;
if ( V_69 )
F_26 ( V_62 , V_67 ) ;
V_59 = F_29 ( V_10 , 0 ) ;
V_59 -> V_71 = F_25 ;
V_59 -> V_72 = V_9 -> V_44 ;
if ( ! V_69 )
V_59 -> V_63 = V_62 ;
F_30 ( V_73 , V_59 ) ;
return 0 ;
}
static int F_31 ( struct V_61 * V_62 )
{
struct V_11 * V_15 = V_62 -> V_13 ;
struct V_8 * V_74 = V_15 -> V_68 ;
unsigned char * V_75 , * V_76 = NULL ;
T_3 V_77 ;
int V_78 ;
T_1 V_79 ;
int V_26 = 0 ;
int V_80 , V_81 ;
if ( V_62 -> V_82 < 8 ) {
F_32 ( L_13 ,
V_62 -> V_82 ) ;
V_62 -> V_64 = V_83 ;
return - V_27 ;
}
V_75 = F_33 ( V_62 ) ;
V_80 = F_34 ( & V_75 [ 0 ] ) ;
V_81 = F_34 ( & V_75 [ 2 ] ) ;
V_78 = V_62 -> V_82 - 8 ;
if ( V_81 > V_78 )
F_32 ( L_14 ,
V_62 -> V_82 , V_81 ) ;
else
V_78 = V_81 ;
if ( V_78 / 16 > V_15 -> V_46 -> V_47 . V_50 ) {
V_62 -> V_64 = V_83 ;
V_26 = - V_27 ;
goto V_60;
}
V_76 = & V_75 [ 8 ] ;
F_2 ( L_15
L_16 , V_15 -> V_84 -> V_7 , V_80 , V_81 , V_78 , V_76 ) ;
while ( V_78 >= 16 ) {
V_77 = F_35 ( & V_76 [ 0 ] ) ;
V_79 = F_36 ( & V_76 [ 8 ] ) ;
F_2 ( L_17 ,
( unsigned long long ) V_77 , V_79 ) ;
if ( V_79 > V_15 -> V_46 -> V_47 . V_48 ) {
V_62 -> V_64 = V_83 ;
V_26 = - V_27 ;
goto V_60;
}
if ( V_77 + V_79 > V_15 -> V_84 -> V_85 ( V_15 ) + 1 ) {
V_62 -> V_64 = V_86 ;
V_26 = - V_27 ;
goto V_60;
}
V_26 = F_37 ( V_74 -> V_44 , V_77 , V_79 ,
V_10 , 0 ) ;
if ( V_26 < 0 ) {
F_6 ( L_18 ,
V_26 ) ;
goto V_60;
}
V_76 += 16 ;
V_78 -= 16 ;
}
V_60:
F_38 ( V_62 ) ;
if ( ! V_26 )
F_26 ( V_62 , V_87 ) ;
return V_26 ;
}
static int F_39 ( struct V_61 * V_62 )
{
struct V_8 * V_74 = V_62 -> V_13 -> V_68 ;
int V_26 ;
V_26 = F_37 ( V_74 -> V_44 , V_62 -> V_88 ,
F_40 ( V_62 ) , V_10 ,
0 ) ;
if ( V_26 < 0 ) {
F_2 ( L_19 ) ;
return V_26 ;
}
F_26 ( V_62 , V_87 ) ;
return 0 ;
}
static T_4 F_41 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
const char * V_89 , T_4 V_90 )
{
struct V_8 * V_9 = V_13 -> V_91 ;
char * V_92 , * V_76 , * V_93 , * V_94 ;
T_5 args [ V_95 ] ;
int V_26 = 0 , V_96 ;
unsigned long V_97 ;
V_94 = F_42 ( V_89 , V_10 ) ;
if ( ! V_94 )
return - V_30 ;
V_92 = V_94 ;
while ( ( V_76 = F_43 ( & V_94 , L_20 ) ) != NULL ) {
if ( ! * V_76 )
continue;
V_96 = F_44 ( V_76 , V_98 , args ) ;
switch ( V_96 ) {
case V_99 :
if ( V_9 -> V_44 ) {
F_6 ( L_21
L_22 ) ;
V_26 = - V_100 ;
goto V_101;
}
V_93 = F_45 ( & args [ 0 ] ) ;
if ( ! V_93 ) {
V_26 = - V_30 ;
break;
}
snprintf ( V_9 -> V_31 , V_102 ,
L_23 , V_93 ) ;
F_21 ( V_93 ) ;
F_2 ( L_24 ,
V_9 -> V_31 ) ;
V_9 -> V_103 |= V_104 ;
break;
case V_105 :
V_93 = F_45 ( & args [ 0 ] ) ;
if ( ! V_93 ) {
V_26 = - V_30 ;
break;
}
V_26 = F_46 ( V_93 , 0 , & V_97 ) ;
F_21 ( V_93 ) ;
if ( V_26 < 0 ) {
F_6 ( L_25
L_26 ) ;
goto V_101;
}
V_9 -> V_34 = V_97 ;
F_2 ( L_27 , V_9 -> V_34 ) ;
break;
case V_106 :
break;
default:
break;
}
}
V_101:
F_21 ( V_92 ) ;
return ( ! V_26 ) ? V_90 : V_26 ;
}
static T_4 F_47 (
struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_8 * V_74 = V_13 -> V_91 ;
if ( ! ( V_74 -> V_103 & V_104 ) ) {
F_6 ( L_28 ) ;
return - V_27 ;
}
return 0 ;
}
static T_4 F_48 (
struct V_1 * V_2 ,
struct V_12 * V_13 ,
char * V_107 )
{
struct V_8 * V_74 = V_13 -> V_91 ;
struct V_18 * V_19 = V_74 -> V_44 ;
char V_75 [ V_108 ] ;
T_4 V_109 = 0 ;
if ( V_19 )
V_109 += sprintf ( V_107 + V_109 , L_29 ,
F_49 ( V_19 , V_75 ) ) ;
if ( V_74 -> V_103 & V_104 )
V_109 += sprintf ( V_107 + V_109 , L_30 ,
V_74 -> V_31 ) ;
V_109 += sprintf ( V_107 + V_109 , L_31 , V_74 -> V_34 ) ;
V_109 += sprintf ( V_107 + V_109 , L_32 ) ;
if ( V_19 ) {
V_109 += sprintf ( V_107 + V_109 , L_33 ,
F_50 ( V_19 -> V_110 ) , F_51 ( V_19 -> V_110 ) , ( ! V_19 -> V_111 ) ?
L_34 : ( V_19 -> V_112 == V_74 ) ?
L_35 : L_36 ) ;
} else {
V_109 += sprintf ( V_107 + V_109 , L_37 ) ;
}
return V_109 ;
}
static void F_52 ( struct V_61 * V_62 )
{
struct V_113 * V_114 = V_62 -> V_115 ;
T_6 V_116 ;
if ( ! F_53 ( & V_114 -> V_117 ) )
return;
if ( F_54 ( & V_114 -> V_118 ) )
V_116 = V_66 ;
else
V_116 = V_67 ;
F_26 ( V_62 , V_116 ) ;
F_21 ( V_114 ) ;
}
static void F_55 ( struct V_59 * V_59 )
{
struct V_61 * V_62 = V_59 -> V_63 ;
struct V_8 * V_9 = V_62 -> V_13 -> V_68 ;
F_56 ( V_59 , V_9 -> V_28 ) ;
}
static struct V_59 *
F_57 ( struct V_61 * V_62 , T_3 V_77 , T_1 V_119 )
{
struct V_8 * V_9 = V_62 -> V_13 -> V_68 ;
struct V_59 * V_59 ;
if ( V_119 > V_120 )
V_119 = V_120 ;
V_59 = F_58 ( V_121 , V_119 , V_9 -> V_28 ) ;
if ( ! V_59 ) {
F_6 ( L_38 ) ;
return NULL ;
}
V_59 -> V_72 = V_9 -> V_44 ;
V_59 -> V_63 = V_62 ;
V_59 -> V_122 = F_55 ;
V_59 -> V_71 = & V_123 ;
V_59 -> V_124 = V_77 ;
return V_59 ;
}
static void F_59 ( struct V_125 * V_126 , int V_127 )
{
struct V_128 V_129 ;
struct V_59 * V_59 ;
F_60 ( & V_129 ) ;
while ( ( V_59 = F_61 ( V_126 ) ) )
F_30 ( V_127 , V_59 ) ;
F_62 ( & V_129 ) ;
}
static int F_63 ( struct V_61 * V_62 )
{
struct V_130 * V_131 = V_62 -> V_132 ;
T_1 V_133 = V_62 -> V_134 ;
enum V_135 V_136 = V_62 -> V_136 ;
struct V_11 * V_15 = V_62 -> V_13 ;
struct V_113 * V_114 ;
struct V_59 * V_59 ;
struct V_125 V_126 ;
struct V_130 * V_137 ;
T_1 V_119 = V_133 ;
T_3 V_138 ;
unsigned V_139 ;
int V_127 ;
int V_140 ;
if ( V_136 == V_141 ) {
if ( V_15 -> V_46 -> V_47 . V_142 == 0 ||
( V_15 -> V_46 -> V_47 . V_143 > 0 &&
( V_62 -> V_144 & V_145 ) ) )
V_127 = V_146 ;
else
V_127 = V_147 ;
} else {
V_127 = V_148 ;
}
if ( V_15 -> V_46 -> V_47 . V_58 == 4096 )
V_138 = ( V_62 -> V_88 << 3 ) ;
else if ( V_15 -> V_46 -> V_47 . V_58 == 2048 )
V_138 = ( V_62 -> V_88 << 2 ) ;
else if ( V_15 -> V_46 -> V_47 . V_58 == 1024 )
V_138 = ( V_62 -> V_88 << 1 ) ;
else if ( V_15 -> V_46 -> V_47 . V_58 == 512 )
V_138 = V_62 -> V_88 ;
else {
F_6 ( L_39
L_40 , V_15 -> V_46 -> V_47 . V_58 ) ;
V_62 -> V_64 = V_65 ;
return - V_149 ;
}
V_114 = F_5 ( sizeof( struct V_113 ) , V_10 ) ;
if ( ! V_114 )
goto V_150;
V_62 -> V_115 = V_114 ;
V_59 = F_57 ( V_62 , V_138 , V_133 ) ;
if ( ! V_59 )
goto V_151;
F_64 ( & V_126 ) ;
F_65 ( & V_126 , V_59 ) ;
F_66 ( & V_114 -> V_117 , 2 ) ;
V_139 = 1 ;
F_67 (sgl, sg, sgl_nents, i) {
while ( F_68 ( V_59 , F_69 ( V_137 ) , V_137 -> V_152 , V_137 -> V_153 )
!= V_137 -> V_152 ) {
if ( V_139 >= V_154 ) {
F_59 ( & V_126 , V_127 ) ;
V_139 = 0 ;
}
V_59 = F_57 ( V_62 , V_138 , V_119 ) ;
if ( ! V_59 )
goto V_155;
F_70 ( & V_114 -> V_117 ) ;
F_65 ( & V_126 , V_59 ) ;
V_139 ++ ;
}
V_138 += V_137 -> V_152 >> V_156 ;
V_119 -- ;
}
F_59 ( & V_126 , V_127 ) ;
F_52 ( V_62 ) ;
return 0 ;
V_155:
while ( ( V_59 = F_61 ( & V_126 ) ) )
F_27 ( V_59 ) ;
V_151:
F_21 ( V_114 ) ;
V_62 -> V_64 = V_65 ;
V_150:
return - V_30 ;
}
static T_1 F_71 ( struct V_11 * V_15 )
{
return V_157 ;
}
static T_1 F_72 ( struct V_11 * V_15 )
{
return V_158 ;
}
static T_3 F_73 ( struct V_11 * V_15 )
{
struct V_8 * V_74 = V_15 -> V_68 ;
struct V_18 * V_19 = V_74 -> V_44 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_22 ( V_15 , V_19 , V_21 ) ;
}
static void V_123 ( struct V_59 * V_59 , int V_60 )
{
struct V_61 * V_62 = V_59 -> V_63 ;
struct V_113 * V_114 = V_62 -> V_115 ;
if ( ! F_74 ( V_159 , & V_59 -> V_160 ) && ! V_60 )
V_60 = - V_161 ;
if ( V_60 != 0 ) {
F_6 ( L_41
L_42 , V_59 , V_60 ) ;
F_70 ( & V_114 -> V_118 ) ;
F_75 () ;
}
F_27 ( V_59 ) ;
F_52 ( V_62 ) ;
}
static int F_76 ( struct V_61 * V_62 )
{
return F_77 ( V_62 , & V_162 ) ;
}
static int T_7 F_78 ( void )
{
return F_79 ( & V_45 ) ;
}
static void F_80 ( void )
{
F_81 ( & V_45 ) ;
}
