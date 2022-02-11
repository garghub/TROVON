static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 ) {
F_3 ( L_1
L_2 ) ;
return - V_7 ;
}
V_5 -> V_8 = V_3 ;
V_2 -> V_9 = V_5 ;
F_4 ( L_3
L_4 , V_2 -> V_10 ,
V_11 , V_12 ) ;
F_4 ( L_5 ,
V_2 -> V_10 , V_5 -> V_8 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 ;
F_4 ( L_6
L_7 , V_2 -> V_10 , V_5 -> V_8 ) ;
F_6 ( V_5 ) ;
V_2 -> V_9 = NULL ;
}
static void * F_7 ( struct V_1 * V_2 , const char * V_13 )
{
struct V_14 * V_15 = NULL ;
struct V_4 * V_5 = V_2 -> V_9 ;
V_15 = F_2 ( sizeof( struct V_14 ) , V_6 ) ;
if ( ! V_15 ) {
F_3 ( L_8 ) ;
return NULL ;
}
V_15 -> V_16 = V_5 ;
F_4 ( L_9 , V_13 ) ;
return V_15 ;
}
static struct V_17 * F_8 (
struct V_1 * V_2 ,
struct V_18 * V_19 ,
void * V_20 )
{
struct V_14 * V_15 = V_20 ;
struct V_17 * V_21 ;
struct V_22 V_23 ;
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
T_1 V_30 = 0 ;
int V_31 = - V_32 ;
if ( ! V_15 ) {
F_3 ( L_10 ) ;
return F_9 ( V_31 ) ;
}
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_15 -> V_33 = F_10 ( 32 , 64 ) ;
if ( ! V_15 -> V_33 ) {
F_3 ( L_11 ) ;
return F_9 ( - V_7 ) ;
}
F_4 ( L_12 ) ;
F_4 ( L_13 ,
V_15 -> V_34 ) ;
V_25 = F_11 ( V_15 -> V_34 ,
V_35 | V_36 | V_37 , V_15 ) ;
if ( F_12 ( V_25 ) ) {
V_31 = F_13 ( V_25 ) ;
goto V_38;
}
V_27 = F_14 ( V_25 ) ;
V_29 = & V_23 . V_29 ;
V_29 -> V_39 = F_15 ( V_25 ) ;
V_29 -> V_40 = F_16 ( V_27 ) ;
V_29 -> V_41 = F_17 ( V_27 ) ;
V_23 . V_42 = V_27 -> V_43 ;
V_23 . V_44 = V_27 -> V_43 ;
V_15 -> V_45 = V_25 ;
V_21 = F_18 ( V_2 ,
& V_46 , V_19 , V_30 , V_15 ,
& V_23 , L_14 , V_11 ) ;
if ( ! V_21 )
goto V_38;
if ( F_19 ( V_27 ) ) {
V_21 -> V_47 -> V_48 . V_49 =
V_27 -> V_29 . V_50 ;
V_21 -> V_47 -> V_48 . V_51 = 1 ;
V_21 -> V_47 -> V_48 . V_52 =
V_27 -> V_29 . V_53 ;
V_21 -> V_47 -> V_48 . V_54 =
V_27 -> V_29 . V_55 ;
F_4 ( L_15
L_16 ) ;
}
if ( F_20 ( V_27 ) )
V_21 -> V_47 -> V_48 . V_56 = 1 ;
return V_21 ;
V_38:
if ( V_15 -> V_33 ) {
F_21 ( V_15 -> V_33 ) ;
V_15 -> V_33 = NULL ;
}
V_15 -> V_45 = NULL ;
return F_9 ( V_31 ) ;
}
static void F_22 ( void * V_20 )
{
struct V_14 * V_15 = V_20 ;
if ( V_15 -> V_45 != NULL )
F_23 ( V_15 -> V_45 , V_35 | V_36 | V_37 ) ;
if ( V_15 -> V_33 != NULL )
F_21 ( V_15 -> V_33 ) ;
F_6 ( V_15 ) ;
}
static inline struct V_57 * F_24 ( struct V_58 * V_59 )
{
return F_25 ( V_59 , struct V_57 , V_60 ) ;
}
static struct V_58 *
F_26 ( unsigned char * V_61 )
{
struct V_57 * V_62 ;
V_62 = F_2 ( sizeof( struct V_57 ) , V_6 ) ;
if ( ! V_62 ) {
F_3 ( L_17 ) ;
return NULL ;
}
F_27 ( & V_62 -> V_63 , 0 ) ;
return & V_62 -> V_60 ;
}
static unsigned long long F_28 (
struct V_17 * V_21 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
unsigned long long V_64 = ( F_29 ( F_30 ( V_25 -> V_65 ) ,
F_15 ( V_25 ) ) - 1 ) ;
T_1 V_66 = F_15 ( V_25 ) ;
if ( V_66 == V_21 -> V_47 -> V_48 . V_66 )
return V_64 ;
switch ( V_66 ) {
case 4096 :
switch ( V_21 -> V_47 -> V_48 . V_66 ) {
case 2048 :
V_64 <<= 1 ;
break;
case 1024 :
V_64 <<= 2 ;
break;
case 512 :
V_64 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_21 -> V_47 -> V_48 . V_66 ) {
case 4096 :
V_64 >>= 1 ;
break;
case 1024 :
V_64 <<= 1 ;
break;
case 512 :
V_64 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_21 -> V_47 -> V_48 . V_66 ) {
case 4096 :
V_64 >>= 2 ;
break;
case 2048 :
V_64 >>= 1 ;
break;
case 512 :
V_64 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_21 -> V_47 -> V_48 . V_66 ) {
case 4096 :
V_64 >>= 3 ;
break;
case 2048 :
V_64 >>= 2 ;
break;
case 1024 :
V_64 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_64 ;
}
static void F_31 ( struct V_58 * V_59 )
{
struct V_67 * V_68 = V_59 -> V_69 ;
struct V_14 * V_15 = V_68 -> V_19 -> V_70 ;
int V_71 = ( V_68 -> V_72 [ 1 ] & 0x2 ) ;
T_2 V_73 ;
int V_31 ;
if ( V_71 )
F_32 ( V_68 , 1 ) ;
V_31 = F_33 ( V_15 -> V_45 , V_6 , & V_73 ) ;
if ( V_31 != 0 ) {
F_3 ( L_18
L_19 , V_31 ,
( unsigned long long ) V_73 ) ;
}
if ( ! V_71 )
F_32 ( V_68 , V_31 == 0 ) ;
}
static int F_34 ( struct V_17 * V_21 )
{
return 1 ;
}
static int F_35 ( struct V_17 * V_21 )
{
return 0 ;
}
static int F_36 ( struct V_17 * V_21 )
{
return 1 ;
}
static int F_37 ( struct V_17 * V_21 )
{
return 0 ;
}
static int F_38 ( struct V_58 * V_59 )
{
struct V_17 * V_21 = V_59 -> V_69 -> V_19 ;
struct V_57 * V_74 = F_24 ( V_59 ) ;
struct V_75 * V_75 = V_74 -> V_76 , * V_77 = NULL ;
struct V_78 V_79 ;
int V_80 ;
if ( V_59 -> V_81 == V_82 ) {
if ( V_21 -> V_47 -> V_48 . V_83 == 0 ||
( V_21 -> V_47 -> V_48 . V_84 > 0 &&
V_59 -> V_69 -> V_85 ) )
V_80 = V_86 ;
else
V_80 = V_87 ;
} else {
V_80 = V_88 ;
}
F_39 ( & V_79 ) ;
while ( V_75 ) {
V_77 = V_75 -> V_89 ;
V_75 -> V_89 = NULL ;
F_4 ( L_20
L_21 , V_59 , V_75 ,
( unsigned long long ) V_75 -> V_90 ) ;
F_40 ( V_80 , V_75 ) ;
V_75 = V_77 ;
}
F_41 ( & V_79 ) ;
return V_91 ;
}
static int F_42 ( struct V_17 * V_21 , T_2 V_92 , T_1 V_93 )
{
struct V_14 * V_94 = V_21 -> V_70 ;
struct V_24 * V_25 = V_94 -> V_45 ;
int V_95 = 0 ;
return F_43 ( V_25 , V_92 , V_93 , V_6 , V_95 ) ;
}
static void F_44 ( struct V_58 * V_59 )
{
struct V_57 * V_74 = F_24 ( V_59 ) ;
struct V_75 * V_75 , * V_96 = V_74 -> V_76 ;
while ( V_96 != NULL ) {
V_75 = V_96 ;
V_96 = V_96 -> V_89 ;
V_75 -> V_89 = NULL ;
F_45 ( V_75 ) ;
}
F_6 ( V_74 ) ;
}
static T_3 F_46 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const char * V_97 , T_3 V_98 )
{
struct V_14 * V_15 = V_19 -> V_99 ;
char * V_100 , * V_101 , * V_102 , * V_103 ;
T_4 args [ V_104 ] ;
int V_31 = 0 , V_105 ;
V_103 = F_47 ( V_97 , V_6 ) ;
if ( ! V_103 )
return - V_7 ;
V_100 = V_103 ;
while ( ( V_101 = F_48 ( & V_103 , L_22 ) ) != NULL ) {
if ( ! * V_101 )
continue;
V_105 = F_49 ( V_101 , V_106 , args ) ;
switch ( V_105 ) {
case V_107 :
if ( V_15 -> V_45 ) {
F_3 ( L_23
L_24 ) ;
V_31 = - V_108 ;
goto V_109;
}
V_102 = F_50 ( & args [ 0 ] ) ;
if ( ! V_102 ) {
V_31 = - V_7 ;
break;
}
snprintf ( V_15 -> V_34 , V_110 ,
L_25 , V_102 ) ;
F_6 ( V_102 ) ;
F_4 ( L_26 ,
V_15 -> V_34 ) ;
V_15 -> V_111 |= V_112 ;
break;
case V_113 :
break;
default:
break;
}
}
V_109:
F_6 ( V_100 ) ;
return ( ! V_31 ) ? V_98 : V_31 ;
}
static T_3 F_51 (
struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_14 * V_94 = V_19 -> V_99 ;
if ( ! ( V_94 -> V_111 & V_112 ) ) {
F_3 ( L_27 ) ;
return - V_32 ;
}
return 0 ;
}
static T_3 F_52 (
struct V_1 * V_2 ,
struct V_18 * V_19 ,
char * V_114 )
{
struct V_14 * V_94 = V_19 -> V_99 ;
struct V_24 * V_25 = V_94 -> V_45 ;
char V_115 [ V_116 ] ;
T_3 V_117 = 0 ;
if ( V_25 )
V_117 += sprintf ( V_114 + V_117 , L_28 ,
F_53 ( V_25 , V_115 ) ) ;
if ( V_94 -> V_111 & V_112 ) {
V_117 += sprintf ( V_114 + V_117 , L_29 ,
V_94 -> V_34 ) ;
} else
V_117 += sprintf ( V_114 + V_117 , L_30 ) ;
V_117 += sprintf ( V_114 + V_117 , L_31 ) ;
if ( V_25 ) {
V_117 += sprintf ( V_114 + V_117 , L_32 ,
F_54 ( V_25 -> V_118 ) , F_55 ( V_25 -> V_118 ) , ( ! V_25 -> V_119 ) ?
L_33 : ( V_25 -> V_120 == (struct V_14 * ) V_94 ) ?
L_34 : L_35 ) ;
} else {
V_117 += sprintf ( V_114 + V_117 , L_36 ) ;
}
return V_117 ;
}
static void F_56 ( struct V_75 * V_75 )
{
struct V_58 * V_59 = V_75 -> V_121 ;
struct V_14 * V_15 = V_59 -> V_19 -> V_70 ;
F_57 ( V_75 , V_15 -> V_33 ) ;
}
static struct V_75 * F_58 (
struct V_58 * V_59 ,
struct V_57 * V_62 ,
struct V_14 * V_15 ,
int * V_31 ,
T_2 V_92 ,
T_1 V_122 )
{
struct V_75 * V_75 ;
V_75 = F_59 ( V_123 , V_122 , V_15 -> V_33 ) ;
if ( ! V_75 ) {
F_3 ( L_37 ) ;
* V_31 = V_124 ;
return NULL ;
}
F_4 ( L_38
L_39 , V_75 , V_59 -> V_125 , V_15 -> V_33 ) ;
F_4 ( L_40 , V_75 , V_59 -> V_126 ) ;
V_75 -> V_127 = V_15 -> V_45 ;
V_75 -> V_121 = V_59 ;
V_75 -> V_128 = F_56 ;
V_75 -> V_129 = & V_130 ;
V_75 -> V_90 = V_92 ;
F_60 ( & V_62 -> V_63 ) ;
F_4 ( L_41 , ( unsigned long long ) V_75 -> V_90 ) ;
F_4 ( L_42 ,
F_61 ( & V_62 -> V_63 ) ) ;
return V_75 ;
}
static int F_62 ( struct V_58 * V_59 )
{
struct V_67 * V_68 = V_59 -> V_69 ;
struct V_17 * V_21 = V_68 -> V_19 ;
struct V_14 * V_15 = V_59 -> V_19 -> V_70 ;
struct V_57 * V_62 = F_24 ( V_59 ) ;
struct V_75 * V_75 = NULL , * V_96 = NULL , * V_131 = NULL ;
struct V_132 * V_133 ;
int V_31 = 0 ;
T_1 V_134 , V_122 = V_59 -> V_125 ;
T_2 V_135 ;
if ( V_21 -> V_47 -> V_48 . V_66 == 4096 )
V_135 = ( V_59 -> V_136 << 3 ) ;
else if ( V_21 -> V_47 -> V_48 . V_66 == 2048 )
V_135 = ( V_59 -> V_136 << 2 ) ;
else if ( V_21 -> V_47 -> V_48 . V_66 == 1024 )
V_135 = ( V_59 -> V_136 << 1 ) ;
else if ( V_21 -> V_47 -> V_48 . V_66 == 512 )
V_135 = V_59 -> V_136 ;
else {
F_3 ( L_43
L_44 , V_21 -> V_47 -> V_48 . V_66 ) ;
return V_137 ;
}
V_75 = F_58 ( V_59 , V_62 , V_15 , & V_31 , V_135 , V_122 ) ;
if ( ! V_75 )
return V_31 ;
V_62 -> V_76 = V_75 ;
V_96 = V_131 = V_75 ;
F_63 (task->task_sg, sg, task->task_sg_nents, i) {
F_4 ( L_45
L_46 , V_59 , V_75 , F_64 ( V_133 ) ,
V_133 -> V_138 , V_133 -> V_139 ) ;
V_140:
V_31 = F_65 ( V_75 , F_64 ( V_133 ) , V_133 -> V_138 , V_133 -> V_139 ) ;
if ( V_31 != V_133 -> V_138 ) {
F_4 ( L_47 ,
( unsigned long long ) V_75 -> V_90 ) ;
F_4 ( L_48 ,
V_59 -> V_126 ) ;
F_4 ( L_49 ,
V_75 -> V_141 ) ;
F_4 ( L_50 ,
V_75 -> V_142 ) ;
V_75 = F_58 ( V_59 , V_62 , V_15 , & V_31 ,
V_135 , V_122 ) ;
if ( ! V_75 )
goto V_143;
V_131 = V_131 -> V_89 = V_75 ;
F_4 ( L_51
L_52 , V_75 ) ;
goto V_140;
}
V_135 += V_133 -> V_138 >> V_144 ;
V_122 -- ;
F_4 ( L_53
L_54 , V_59 , V_122 ) ;
F_4 ( L_55
L_56 , V_59 , ( unsigned long long ) V_135 ) ;
F_4 ( L_57
L_44 , V_59 , V_75 -> V_142 ) ;
}
return 0 ;
V_143:
while ( V_96 ) {
V_75 = V_96 ;
V_96 = V_96 -> V_89 ;
V_75 -> V_89 = NULL ;
F_45 ( V_75 ) ;
}
return V_31 ;
}
static unsigned char * F_66 ( struct V_58 * V_59 )
{
return F_24 ( V_59 ) -> V_145 ;
}
static T_1 F_67 ( struct V_17 * V_21 )
{
return V_146 ;
}
static T_1 F_68 ( struct V_17 * V_21 )
{
return V_147 ;
}
static T_2 F_69 ( struct V_17 * V_21 )
{
struct V_14 * V_94 = V_21 -> V_70 ;
struct V_24 * V_25 = V_94 -> V_45 ;
struct V_26 * V_27 = F_14 ( V_25 ) ;
return F_28 ( V_21 , V_25 , V_27 ) ;
}
static void V_130 ( struct V_75 * V_75 , int V_148 )
{
struct V_58 * V_59 = V_75 -> V_121 ;
struct V_57 * V_149 = F_24 ( V_59 ) ;
if ( ! F_70 ( V_150 , & V_75 -> V_151 ) && ! V_148 )
V_148 = - V_152 ;
if ( V_148 != 0 ) {
F_3 ( L_58
L_59 , V_75 , V_148 ) ;
F_60 ( & V_149 -> V_153 ) ;
F_71 () ;
F_45 ( V_75 ) ;
if ( ! F_72 ( & V_149 -> V_63 ) )
return;
V_149 -> V_76 = NULL ;
F_73 ( V_59 , 0 ) ;
return;
}
F_4 ( L_60 ,
V_59 , V_75 , V_59 -> V_136 , ( unsigned long long ) V_75 -> V_90 , V_148 ) ;
F_45 ( V_75 ) ;
if ( ! F_72 ( & V_149 -> V_63 ) )
return;
V_149 -> V_76 = NULL ;
F_73 ( V_59 , ( ! F_61 ( & V_149 -> V_153 ) ) ) ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_46 ) ;
}
static void F_76 ( void )
{
F_77 ( & V_46 ) ;
}
