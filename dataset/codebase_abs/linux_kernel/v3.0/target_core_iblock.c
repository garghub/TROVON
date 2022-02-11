static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! ( V_5 ) ) {
F_3 ( V_7 L_1
L_2 ) ;
return - V_8 ;
}
V_5 -> V_9 = V_3 ;
F_4 ( & V_2 -> V_10 , V_11 ) ;
F_4 ( & V_2 -> V_12 , V_11 ) ;
V_2 -> V_13 = ( void * ) V_5 ;
F_3 ( V_14 L_3
L_4 , V_2 -> V_15 ,
V_16 , V_17 ) ;
F_3 ( V_14 L_5
L_6 , V_2 -> V_15 ,
V_5 -> V_9 , F_5 ( & V_2 -> V_12 ) ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_13 ;
F_3 ( V_14 L_7
L_8 , V_2 -> V_15 , V_5 -> V_9 ) ;
F_7 ( V_5 ) ;
V_2 -> V_13 = NULL ;
}
static void * F_8 ( struct V_1 * V_2 , const char * V_18 )
{
struct V_19 * V_20 = NULL ;
struct V_4 * V_5 = V_2 -> V_13 ;
V_20 = F_2 ( sizeof( struct V_19 ) , V_6 ) ;
if ( ! ( V_20 ) ) {
F_3 ( V_7 L_9 ) ;
return NULL ;
}
V_20 -> V_21 = V_5 ;
F_3 ( V_14 L_10 , V_18 ) ;
return V_20 ;
}
static struct V_22 * F_9 (
struct V_1 * V_2 ,
struct V_23 * V_24 ,
void * V_25 )
{
struct V_19 * V_20 = V_25 ;
struct V_22 * V_26 ;
struct V_27 V_28 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_1 V_35 = 0 ;
int V_36 = - V_37 ;
if ( ! ( V_20 ) ) {
F_3 ( V_7 L_11 ) ;
return F_10 ( V_36 ) ;
}
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_20 -> V_38 = F_11 ( 32 , 64 ) ;
if ( ! ( V_20 -> V_38 ) ) {
F_3 ( V_7 L_12 ) ;
return F_10 ( - V_8 ) ;
}
F_3 ( V_14 L_13 ) ;
F_3 ( V_14 L_14 ,
V_20 -> V_39 ) ;
V_30 = F_12 ( V_20 -> V_39 ,
V_40 | V_41 | V_42 , V_20 ) ;
if ( F_13 ( V_30 ) ) {
V_36 = F_14 ( V_30 ) ;
goto V_43;
}
V_32 = F_15 ( V_30 ) ;
V_34 = & V_28 . V_34 ;
V_34 -> V_44 = F_16 ( V_30 ) ;
V_34 -> V_45 = F_17 ( V_32 ) ;
V_34 -> V_46 = F_18 ( V_32 ) ;
V_28 . V_47 = V_48 ;
V_28 . V_49 = V_50 ;
V_20 -> V_51 = F_19 ( V_30 -> V_52 ) ;
V_20 -> V_53 = F_20 ( V_30 -> V_52 ) ;
V_20 -> V_54 = V_30 ;
V_26 = F_21 ( V_2 ,
& V_55 , V_24 , V_35 , ( void * ) V_20 ,
& V_28 , L_15 , V_16 ) ;
if ( ! ( V_26 ) )
goto V_43;
V_20 -> V_56 = V_26 -> V_49 ;
if ( F_22 ( V_32 ) ) {
F_23 ( V_26 ) -> V_57 =
V_32 -> V_34 . V_58 ;
F_23 ( V_26 ) -> V_59 = 1 ;
F_23 ( V_26 ) -> V_60 =
V_32 -> V_34 . V_61 ;
F_23 ( V_26 ) -> V_62 =
V_32 -> V_34 . V_63 ;
F_3 ( V_14 L_16
L_17 ) ;
}
return V_26 ;
V_43:
if ( V_20 -> V_38 ) {
F_24 ( V_20 -> V_38 ) ;
V_20 -> V_38 = NULL ;
}
V_20 -> V_54 = NULL ;
V_20 -> V_51 = 0 ;
V_20 -> V_53 = 0 ;
return F_10 ( V_36 ) ;
}
static void F_25 ( void * V_25 )
{
struct V_19 * V_20 = V_25 ;
if ( V_20 -> V_54 != NULL )
F_26 ( V_20 -> V_54 , V_40 | V_41 | V_42 ) ;
if ( V_20 -> V_38 != NULL )
F_24 ( V_20 -> V_38 ) ;
F_7 ( V_20 ) ;
}
static inline struct V_64 * F_27 ( struct V_65 * V_66 )
{
return F_28 ( V_66 , struct V_64 , V_67 ) ;
}
static struct V_65 *
F_29 ( struct V_68 * V_69 )
{
struct V_64 * V_70 ;
V_70 = F_2 ( sizeof( struct V_64 ) , V_6 ) ;
if ( ! ( V_70 ) ) {
F_3 ( V_7 L_18 ) ;
return NULL ;
}
V_70 -> V_20 = F_30 ( V_69 ) -> V_71 ;
F_4 ( & V_70 -> V_72 , 0 ) ;
return & V_70 -> V_67 ;
}
static unsigned long long F_31 (
struct V_22 * V_26 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
unsigned long long V_73 = ( F_32 ( F_33 ( V_30 -> V_74 ) ,
F_16 ( V_30 ) ) - 1 ) ;
T_1 V_75 = F_16 ( V_30 ) ;
if ( V_75 == F_23 ( V_26 ) -> V_75 )
return V_73 ;
switch ( V_75 ) {
case 4096 :
switch ( F_23 ( V_26 ) -> V_75 ) {
case 2048 :
V_73 <<= 1 ;
break;
case 1024 :
V_73 <<= 2 ;
break;
case 512 :
V_73 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( F_23 ( V_26 ) -> V_75 ) {
case 4096 :
V_73 >>= 1 ;
break;
case 1024 :
V_73 <<= 1 ;
break;
case 512 :
V_73 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( F_23 ( V_26 ) -> V_75 ) {
case 4096 :
V_73 >>= 2 ;
break;
case 2048 :
V_73 >>= 1 ;
break;
case 512 :
V_73 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( F_23 ( V_26 ) -> V_75 ) {
case 4096 :
V_73 >>= 3 ;
break;
case 2048 :
V_73 >>= 2 ;
break;
case 1024 :
V_73 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_73 ;
}
static void F_34 ( struct V_65 * V_66 )
{
struct V_68 * V_69 = F_35 ( V_66 ) ;
struct V_19 * V_20 = V_69 -> V_24 -> V_71 ;
int V_76 = ( F_36 ( V_69 ) -> V_77 [ 1 ] & 0x2 ) ;
T_2 V_78 ;
int V_36 ;
if ( V_76 )
F_37 ( V_69 , 1 ) ;
V_36 = F_38 ( V_20 -> V_54 , V_6 , & V_78 ) ;
if ( V_36 != 0 ) {
F_3 ( V_7 L_19
L_20 , V_36 ,
( unsigned long long ) V_78 ) ;
}
if ( ! V_76 )
F_37 ( V_69 , V_36 == 0 ) ;
}
static int F_39 ( struct V_22 * V_26 )
{
return 1 ;
}
static int F_40 ( struct V_22 * V_26 )
{
return 0 ;
}
static int F_41 ( struct V_22 * V_26 )
{
return 1 ;
}
static int F_42 ( struct V_22 * V_26 )
{
return 0 ;
}
static int F_43 ( struct V_65 * V_66 )
{
struct V_22 * V_26 = V_66 -> V_79 -> V_24 ;
struct V_64 * V_80 = F_27 ( V_66 ) ;
struct V_81 * V_81 = V_80 -> V_82 , * V_83 = NULL ;
struct V_84 V_85 ;
int V_86 ;
if ( V_66 -> V_87 == V_88 ) {
if ( F_23 ( V_26 ) -> V_89 == 0 ||
( F_23 ( V_26 ) -> V_90 > 0 &&
F_36 ( V_66 -> V_79 ) -> V_91 ) )
V_86 = V_92 ;
else
V_86 = V_93 ;
} else {
V_86 = V_94 ;
}
F_44 ( & V_85 ) ;
while ( V_81 ) {
V_83 = V_81 -> V_95 ;
V_81 -> V_95 = NULL ;
F_45 ( L_21
L_22 , V_66 , V_81 , V_81 -> V_96 ) ;
F_46 ( V_86 , V_81 ) ;
V_81 = V_83 ;
}
F_47 ( & V_85 ) ;
return V_97 ;
}
static int F_48 ( struct V_22 * V_26 , T_2 V_98 , T_1 V_99 )
{
struct V_19 * V_100 = V_26 -> V_71 ;
struct V_29 * V_30 = V_100 -> V_54 ;
int V_101 = 0 ;
return F_49 ( V_30 , V_98 , V_99 , V_6 , V_101 ) ;
}
static void F_50 ( struct V_65 * V_66 )
{
struct V_64 * V_80 = F_27 ( V_66 ) ;
struct V_81 * V_81 , * V_102 = V_80 -> V_82 ;
while ( V_102 != NULL ) {
V_81 = V_102 ;
V_102 = V_102 -> V_95 ;
V_81 -> V_95 = NULL ;
F_51 ( V_81 ) ;
}
F_7 ( V_80 ) ;
}
static T_3 F_52 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
const char * V_103 , T_3 V_104 )
{
struct V_19 * V_20 = V_24 -> V_105 ;
char * V_106 , * V_107 , * V_108 , * V_109 ;
T_4 args [ V_110 ] ;
int V_36 = 0 , V_111 , V_112 ;
V_109 = F_53 ( V_103 , V_6 ) ;
if ( ! V_109 )
return - V_8 ;
V_106 = V_109 ;
while ( ( V_107 = F_54 ( & V_109 , L_23 ) ) != NULL ) {
if ( ! * V_107 )
continue;
V_112 = F_55 ( V_107 , V_113 , args ) ;
switch ( V_112 ) {
case V_114 :
if ( V_20 -> V_54 ) {
F_3 ( V_7 L_24
L_25 ) ;
V_36 = - V_115 ;
goto V_116;
}
V_108 = F_56 ( & args [ 0 ] ) ;
if ( ! V_108 ) {
V_36 = - V_8 ;
break;
}
snprintf ( V_20 -> V_39 , V_117 ,
L_26 , V_108 ) ;
F_7 ( V_108 ) ;
F_3 ( V_14 L_27 ,
V_20 -> V_39 ) ;
V_20 -> V_118 |= V_119 ;
break;
case V_120 :
F_57 ( args , & V_111 ) ;
V_20 -> V_121 = V_111 ;
F_3 ( V_14 L_28 ,
V_20 -> V_121 ) ;
break;
default:
break;
}
}
V_116:
F_7 ( V_106 ) ;
return ( ! V_36 ) ? V_104 : V_36 ;
}
static T_3 F_58 (
struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_19 * V_100 = V_24 -> V_105 ;
if ( ! ( V_100 -> V_118 & V_119 ) ) {
F_3 ( V_7 L_29 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_59 (
struct V_1 * V_2 ,
struct V_23 * V_24 ,
char * V_122 )
{
struct V_19 * V_100 = V_24 -> V_105 ;
struct V_29 * V_30 = V_100 -> V_54 ;
char V_123 [ V_124 ] ;
T_3 V_125 = 0 ;
if ( V_30 )
V_125 += sprintf ( V_122 + V_125 , L_30 ,
F_60 ( V_30 , V_123 ) ) ;
if ( V_100 -> V_118 & V_119 ) {
V_125 += sprintf ( V_122 + V_125 , L_31 ,
V_100 -> V_39 ) ;
} else
V_125 += sprintf ( V_122 + V_125 , L_32 ) ;
V_125 += sprintf ( V_122 + V_125 , L_33 ) ;
if ( V_30 ) {
V_125 += sprintf ( V_122 + V_125 , L_34 ,
V_100 -> V_51 , V_100 -> V_53 , ( ! V_30 -> V_126 ) ?
L_35 : ( V_30 -> V_127 == (struct V_19 * ) V_100 ) ?
L_36 : L_37 ) ;
} else {
V_125 += sprintf ( V_122 + V_125 , L_38 ,
V_100 -> V_51 , V_100 -> V_53 ) ;
}
return V_125 ;
}
static void F_61 ( struct V_81 * V_81 )
{
struct V_65 * V_66 = V_81 -> V_128 ;
struct V_19 * V_20 = V_66 -> V_24 -> V_71 ;
F_62 ( V_81 , V_20 -> V_38 ) ;
}
static struct V_81 * F_63 (
struct V_65 * V_66 ,
struct V_64 * V_70 ,
struct V_19 * V_20 ,
int * V_36 ,
T_2 V_98 ,
T_1 V_129 )
{
struct V_81 * V_81 ;
V_81 = F_64 ( V_130 , V_129 , V_20 -> V_38 ) ;
if ( ! ( V_81 ) ) {
F_3 ( V_7 L_39 ) ;
* V_36 = V_131 ;
return NULL ;
}
F_45 ( L_40
L_41 , V_81 , V_66 -> V_132 , V_20 -> V_38 ) ;
F_45 ( L_42 , V_81 , V_66 -> V_133 ) ;
V_81 -> V_134 = V_20 -> V_54 ;
V_81 -> V_128 = ( void * ) V_66 ;
V_81 -> V_135 = F_61 ;
V_81 -> V_136 = & V_137 ;
V_81 -> V_96 = V_98 ;
F_65 ( & V_70 -> V_72 ) ;
F_45 ( L_43 , V_81 -> V_96 ) ;
F_45 ( L_44 ,
F_5 ( & V_70 -> V_72 ) ) ;
return V_81 ;
}
static int F_66 ( struct V_65 * V_66 )
{
struct V_68 * V_69 = V_66 -> V_79 ;
struct V_22 * V_26 = F_30 ( V_69 ) ;
struct V_19 * V_20 = V_66 -> V_24 -> V_71 ;
struct V_64 * V_70 = F_27 ( V_66 ) ;
struct V_81 * V_81 = NULL , * V_102 = NULL , * V_138 = NULL ;
struct V_139 * V_140 ;
int V_36 = 0 ;
T_1 V_141 , V_129 = V_66 -> V_132 ;
T_2 V_142 ;
if ( F_23 ( V_26 ) -> V_75 == 4096 )
V_142 = ( V_66 -> V_143 << 3 ) ;
else if ( F_23 ( V_26 ) -> V_75 == 2048 )
V_142 = ( V_66 -> V_143 << 2 ) ;
else if ( F_23 ( V_26 ) -> V_75 == 1024 )
V_142 = ( V_66 -> V_143 << 1 ) ;
else if ( F_23 ( V_26 ) -> V_75 == 512 )
V_142 = V_66 -> V_143 ;
else {
F_3 ( V_7 L_45
L_46 , F_23 ( V_26 ) -> V_75 ) ;
return V_144 ;
}
V_81 = F_63 ( V_66 , V_70 , V_20 , & V_36 , V_142 , V_129 ) ;
if ( ! ( V_81 ) )
return V_36 ;
V_70 -> V_82 = V_81 ;
V_102 = V_138 = V_81 ;
F_67 (task->task_sg, sg, task->task_sg_num, i) {
F_45 ( L_47
L_48 , V_66 , V_81 , F_68 ( V_140 ) ,
V_140 -> V_145 , V_140 -> V_146 ) ;
V_147:
V_36 = F_69 ( V_81 , F_68 ( V_140 ) , V_140 -> V_145 , V_140 -> V_146 ) ;
if ( V_36 != V_140 -> V_145 ) {
F_45 ( L_49 ,
V_81 -> V_96 ) ;
F_45 ( L_50 ,
V_66 -> V_133 ) ;
F_45 ( L_51 ,
V_81 -> V_148 ) ;
F_45 ( L_52 ,
V_81 -> V_149 ) ;
V_81 = F_63 ( V_66 , V_70 , V_20 , & V_36 ,
V_142 , V_129 ) ;
if ( ! ( V_81 ) )
goto V_150;
V_138 = V_138 -> V_95 = V_81 ;
F_45 ( L_53
L_54 , V_81 ) ;
goto V_147;
}
V_142 += V_140 -> V_145 >> V_151 ;
V_129 -- ;
F_45 ( L_55
L_56 , V_66 , V_129 ) ;
F_45 ( L_57
L_58 , V_66 , V_142 ) ;
F_45 ( L_59
L_46 , V_66 , V_81 -> V_149 ) ;
}
return 0 ;
V_150:
while ( V_102 ) {
V_81 = V_102 ;
V_102 = V_102 -> V_95 ;
V_81 -> V_95 = NULL ;
F_51 ( V_81 ) ;
}
return V_36 ;
}
static unsigned char * F_70 ( struct V_65 * V_66 )
{
return F_27 ( V_66 ) -> V_152 ;
}
static T_1 F_71 ( struct V_22 * V_26 )
{
return V_153 ;
}
static T_1 F_72 ( struct V_22 * V_26 )
{
return V_154 ;
}
static T_2 F_73 ( struct V_22 * V_26 )
{
struct V_19 * V_100 = V_26 -> V_71 ;
struct V_29 * V_30 = V_100 -> V_54 ;
struct V_31 * V_32 = F_15 ( V_30 ) ;
return F_31 ( V_26 , V_30 , V_32 ) ;
}
static void V_137 ( struct V_81 * V_81 , int V_155 )
{
struct V_65 * V_66 = V_81 -> V_128 ;
struct V_64 * V_156 = F_27 ( V_66 ) ;
if ( ! ( F_74 ( V_157 , & V_81 -> V_158 ) ) && ! ( V_155 ) )
V_155 = - V_159 ;
if ( V_155 != 0 ) {
F_3 ( V_7 L_60
L_61 , V_81 , V_155 ) ;
F_65 ( & V_156 -> V_160 ) ;
F_75 () ;
F_51 ( V_81 ) ;
if ( ! ( F_76 ( & V_156 -> V_72 ) ) )
return;
V_156 -> V_82 = NULL ;
F_77 ( V_66 , 0 ) ;
return;
}
F_45 ( L_62 ,
V_66 , V_81 , V_66 -> V_143 , V_81 -> V_96 , V_155 ) ;
F_51 ( V_81 ) ;
if ( ! ( F_76 ( & V_156 -> V_72 ) ) )
return;
V_156 -> V_82 = NULL ;
F_77 ( V_66 , ( ! F_5 ( & V_156 -> V_160 ) ) ) ;
}
static int T_5 F_78 ( void )
{
return F_79 ( & V_55 ) ;
}
static void F_80 ( void )
{
F_81 ( & V_55 ) ;
}
