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
int V_25 = - V_26 ;
if ( ! V_9 ) {
F_6 ( L_5 ) ;
return F_8 ( V_25 ) ;
}
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_9 -> V_27 = F_9 ( V_28 , 0 ) ;
if ( ! V_9 -> V_27 ) {
F_6 ( L_6 ) ;
return F_8 ( - V_29 ) ;
}
F_2 ( L_7 ) ;
F_2 ( L_8 ,
V_9 -> V_30 ) ;
V_19 = F_10 ( V_9 -> V_30 ,
V_31 | V_32 | V_33 , V_9 ) ;
if ( F_11 ( V_19 ) ) {
V_25 = F_12 ( V_19 ) ;
goto V_34;
}
V_21 = F_13 ( V_19 ) ;
V_23 = & V_17 . V_23 ;
V_23 -> V_35 = F_14 ( V_19 ) ;
V_23 -> V_36 = V_37 ;
V_23 -> V_38 = V_37 ;
V_17 . V_39 = V_21 -> V_40 ;
V_17 . V_41 = V_21 -> V_40 ;
V_9 -> V_42 = V_19 ;
V_15 = F_15 ( V_2 ,
& V_43 , V_13 , V_24 , V_9 ,
& V_17 , L_9 , V_5 ) ;
if ( ! V_15 )
goto V_34;
if ( F_16 ( V_21 ) ) {
V_15 -> V_44 -> V_45 . V_46 =
V_21 -> V_23 . V_47 ;
V_15 -> V_44 -> V_45 . V_48 = 1 ;
V_15 -> V_44 -> V_45 . V_49 =
V_21 -> V_23 . V_50 >> 9 ;
V_15 -> V_44 -> V_45 . V_51 =
V_21 -> V_23 . V_52 ;
F_2 ( L_10
L_11 ) ;
}
if ( F_17 ( V_21 ) )
V_15 -> V_44 -> V_45 . V_53 = 1 ;
return V_15 ;
V_34:
if ( V_9 -> V_27 ) {
F_18 ( V_9 -> V_27 ) ;
V_9 -> V_27 = NULL ;
}
V_9 -> V_42 = NULL ;
return F_8 ( V_25 ) ;
}
static void F_19 ( void * V_14 )
{
struct V_8 * V_9 = V_14 ;
if ( V_9 -> V_42 != NULL )
F_20 ( V_9 -> V_42 , V_31 | V_32 | V_33 ) ;
if ( V_9 -> V_27 != NULL )
F_18 ( V_9 -> V_27 ) ;
F_21 ( V_9 ) ;
}
static inline struct V_54 * F_22 ( struct V_55 * V_56 )
{
return F_23 ( V_56 , struct V_54 , V_57 ) ;
}
static struct V_55 *
F_24 ( unsigned char * V_58 )
{
struct V_54 * V_59 ;
V_59 = F_5 ( sizeof( struct V_54 ) , V_10 ) ;
if ( ! V_59 ) {
F_6 ( L_12 ) ;
return NULL ;
}
F_25 ( & V_59 -> V_60 , 1 ) ;
return & V_59 -> V_57 ;
}
static unsigned long long F_26 (
struct V_11 * V_15 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned long long V_61 = ( F_27 ( F_28 ( V_19 -> V_62 ) ,
F_14 ( V_19 ) ) - 1 ) ;
T_1 V_63 = F_14 ( V_19 ) ;
if ( V_63 == V_15 -> V_44 -> V_45 . V_63 )
return V_61 ;
switch ( V_63 ) {
case 4096 :
switch ( V_15 -> V_44 -> V_45 . V_63 ) {
case 2048 :
V_61 <<= 1 ;
break;
case 1024 :
V_61 <<= 2 ;
break;
case 512 :
V_61 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_15 -> V_44 -> V_45 . V_63 ) {
case 4096 :
V_61 >>= 1 ;
break;
case 1024 :
V_61 <<= 1 ;
break;
case 512 :
V_61 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_15 -> V_44 -> V_45 . V_63 ) {
case 4096 :
V_61 >>= 2 ;
break;
case 2048 :
V_61 >>= 1 ;
break;
case 512 :
V_61 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_15 -> V_44 -> V_45 . V_63 ) {
case 4096 :
V_61 >>= 3 ;
break;
case 2048 :
V_61 >>= 2 ;
break;
case 1024 :
V_61 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_61 ;
}
static void F_29 ( struct V_64 * V_64 , int V_65 )
{
struct V_66 * V_67 = V_64 -> V_68 ;
if ( V_65 )
F_6 ( L_13 , V_65 ) ;
if ( V_67 )
F_30 ( V_67 , V_65 == 0 ) ;
F_31 ( V_64 ) ;
}
static void F_32 ( struct V_55 * V_56 )
{
struct V_66 * V_67 = V_56 -> V_69 ;
struct V_8 * V_9 = V_67 -> V_13 -> V_70 ;
int V_71 = ( V_67 -> V_72 [ 1 ] & 0x2 ) ;
struct V_64 * V_64 ;
if ( V_71 )
F_30 ( V_67 , 1 ) ;
V_64 = F_33 ( V_10 , 0 ) ;
V_64 -> V_73 = F_29 ;
V_64 -> V_74 = V_9 -> V_42 ;
if ( ! V_71 )
V_64 -> V_68 = V_67 ;
F_34 ( V_75 , V_64 ) ;
}
static int F_35 ( struct V_11 * V_15 , T_2 V_76 , T_1 V_77 )
{
struct V_8 * V_78 = V_15 -> V_70 ;
struct V_18 * V_19 = V_78 -> V_42 ;
int V_79 = 0 ;
return F_36 ( V_19 , V_76 , V_77 , V_10 , V_79 ) ;
}
static void F_37 ( struct V_55 * V_56 )
{
F_21 ( F_22 ( V_56 ) ) ;
}
static T_3 F_38 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
const char * V_80 , T_3 V_81 )
{
struct V_8 * V_9 = V_13 -> V_82 ;
char * V_83 , * V_84 , * V_85 , * V_86 ;
T_4 args [ V_87 ] ;
int V_25 = 0 , V_88 ;
V_86 = F_39 ( V_80 , V_10 ) ;
if ( ! V_86 )
return - V_29 ;
V_83 = V_86 ;
while ( ( V_84 = F_40 ( & V_86 , L_14 ) ) != NULL ) {
if ( ! * V_84 )
continue;
V_88 = F_41 ( V_84 , V_89 , args ) ;
switch ( V_88 ) {
case V_90 :
if ( V_9 -> V_42 ) {
F_6 ( L_15
L_16 ) ;
V_25 = - V_91 ;
goto V_92;
}
V_85 = F_42 ( & args [ 0 ] ) ;
if ( ! V_85 ) {
V_25 = - V_29 ;
break;
}
snprintf ( V_9 -> V_30 , V_93 ,
L_17 , V_85 ) ;
F_21 ( V_85 ) ;
F_2 ( L_18 ,
V_9 -> V_30 ) ;
V_9 -> V_94 |= V_95 ;
break;
case V_96 :
break;
default:
break;
}
}
V_92:
F_21 ( V_83 ) ;
return ( ! V_25 ) ? V_81 : V_25 ;
}
static T_3 F_43 (
struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_8 * V_78 = V_13 -> V_82 ;
if ( ! ( V_78 -> V_94 & V_95 ) ) {
F_6 ( L_19 ) ;
return - V_26 ;
}
return 0 ;
}
static T_3 F_44 (
struct V_1 * V_2 ,
struct V_12 * V_13 ,
char * V_97 )
{
struct V_8 * V_78 = V_13 -> V_82 ;
struct V_18 * V_19 = V_78 -> V_42 ;
char V_98 [ V_99 ] ;
T_3 V_100 = 0 ;
if ( V_19 )
V_100 += sprintf ( V_97 + V_100 , L_20 ,
F_45 ( V_19 , V_98 ) ) ;
if ( V_78 -> V_94 & V_95 ) {
V_100 += sprintf ( V_97 + V_100 , L_21 ,
V_78 -> V_30 ) ;
} else
V_100 += sprintf ( V_97 + V_100 , L_22 ) ;
V_100 += sprintf ( V_97 + V_100 , L_23 ) ;
if ( V_19 ) {
V_100 += sprintf ( V_97 + V_100 , L_24 ,
F_46 ( V_19 -> V_101 ) , F_47 ( V_19 -> V_101 ) , ( ! V_19 -> V_102 ) ?
L_25 : ( V_19 -> V_103 == V_78 ) ?
L_26 : L_27 ) ;
} else {
V_100 += sprintf ( V_97 + V_100 , L_28 ) ;
}
return V_100 ;
}
static void F_48 ( struct V_64 * V_64 )
{
struct V_55 * V_56 = V_64 -> V_68 ;
struct V_8 * V_9 = V_56 -> V_69 -> V_13 -> V_70 ;
F_49 ( V_64 , V_9 -> V_27 ) ;
}
static struct V_64 *
F_50 ( struct V_55 * V_56 , T_2 V_76 , T_1 V_104 )
{
struct V_8 * V_9 = V_56 -> V_69 -> V_13 -> V_70 ;
struct V_54 * V_59 = F_22 ( V_56 ) ;
struct V_64 * V_64 ;
if ( V_104 > V_105 )
V_104 = V_105 ;
V_64 = F_51 ( V_106 , V_104 , V_9 -> V_27 ) ;
if ( ! V_64 ) {
F_6 ( L_29 ) ;
return NULL ;
}
F_2 ( L_30
L_31 , V_64 , V_56 -> V_107 , V_9 -> V_27 ) ;
F_2 ( L_32 , V_64 , V_56 -> V_108 ) ;
V_64 -> V_74 = V_9 -> V_42 ;
V_64 -> V_68 = V_56 ;
V_64 -> V_109 = F_48 ;
V_64 -> V_73 = & V_110 ;
V_64 -> V_111 = V_76 ;
F_52 ( & V_59 -> V_60 ) ;
F_2 ( L_33 , ( unsigned long long ) V_64 -> V_111 ) ;
F_2 ( L_34 , F_53 ( & V_59 -> V_60 ) ) ;
return V_64 ;
}
static void F_54 ( struct V_112 * V_113 , int V_114 )
{
struct V_115 V_116 ;
struct V_64 * V_64 ;
F_55 ( & V_116 ) ;
while ( ( V_64 = F_56 ( V_113 ) ) )
F_34 ( V_114 , V_64 ) ;
F_57 ( & V_116 ) ;
}
static int F_58 ( struct V_55 * V_56 )
{
struct V_66 * V_67 = V_56 -> V_69 ;
struct V_11 * V_15 = V_67 -> V_13 ;
struct V_54 * V_117 = F_22 ( V_56 ) ;
struct V_64 * V_64 ;
struct V_112 V_113 ;
struct V_118 * V_119 ;
T_1 V_120 , V_104 = V_56 -> V_107 ;
T_2 V_121 ;
unsigned V_122 ;
int V_114 ;
if ( V_56 -> V_123 == V_124 ) {
if ( V_15 -> V_44 -> V_45 . V_125 == 0 ||
( V_15 -> V_44 -> V_45 . V_126 > 0 &&
( V_67 -> V_127 & V_128 ) ) )
V_114 = V_129 ;
else
V_114 = V_130 ;
} else {
V_114 = V_131 ;
}
if ( V_15 -> V_44 -> V_45 . V_63 == 4096 )
V_121 = ( V_56 -> V_132 << 3 ) ;
else if ( V_15 -> V_44 -> V_45 . V_63 == 2048 )
V_121 = ( V_56 -> V_132 << 2 ) ;
else if ( V_15 -> V_44 -> V_45 . V_63 == 1024 )
V_121 = ( V_56 -> V_132 << 1 ) ;
else if ( V_15 -> V_44 -> V_45 . V_63 == 512 )
V_121 = V_56 -> V_132 ;
else {
F_6 ( L_35
L_36 , V_15 -> V_44 -> V_45 . V_63 ) ;
V_67 -> V_133 = V_134 ;
return - V_135 ;
}
V_64 = F_50 ( V_56 , V_121 , V_104 ) ;
if ( ! V_64 ) {
V_67 -> V_133 = V_134 ;
return - V_29 ;
}
F_59 ( & V_113 ) ;
F_60 ( & V_113 , V_64 ) ;
V_122 = 1 ;
F_61 (task->task_sg, sg, task->task_sg_nents, i) {
while ( F_62 ( V_64 , F_63 ( V_119 ) , V_119 -> V_136 , V_119 -> V_137 )
!= V_119 -> V_136 ) {
if ( V_122 >= V_138 ) {
F_54 ( & V_113 , V_114 ) ;
V_122 = 0 ;
}
V_64 = F_50 ( V_56 , V_121 , V_104 ) ;
if ( ! V_64 )
goto V_139;
F_60 ( & V_113 , V_64 ) ;
V_122 ++ ;
}
V_121 += V_119 -> V_136 >> V_140 ;
V_104 -- ;
}
F_54 ( & V_113 , V_114 ) ;
if ( F_64 ( & V_117 -> V_60 ) ) {
F_65 ( V_56 ,
! F_53 ( & V_117 -> V_141 ) ) ;
}
return 0 ;
V_139:
while ( ( V_64 = F_56 ( & V_113 ) ) )
F_31 ( V_64 ) ;
V_67 -> V_133 = V_134 ;
return - V_29 ;
}
static T_1 F_66 ( struct V_11 * V_15 )
{
return V_142 ;
}
static T_1 F_67 ( struct V_11 * V_15 )
{
return V_143 ;
}
static T_2 F_68 ( struct V_11 * V_15 )
{
struct V_8 * V_78 = V_15 -> V_70 ;
struct V_18 * V_19 = V_78 -> V_42 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_26 ( V_15 , V_19 , V_21 ) ;
}
static void V_110 ( struct V_64 * V_64 , int V_65 )
{
struct V_55 * V_56 = V_64 -> V_68 ;
struct V_54 * V_117 = F_22 ( V_56 ) ;
if ( ! F_69 ( V_144 , & V_64 -> V_145 ) && ! V_65 )
V_65 = - V_146 ;
if ( V_65 != 0 ) {
F_6 ( L_37
L_38 , V_64 , V_65 ) ;
F_52 ( & V_117 -> V_141 ) ;
F_70 () ;
}
F_31 ( V_64 ) ;
if ( ! F_64 ( & V_117 -> V_60 ) )
return;
F_2 ( L_39 ,
V_56 , V_64 , V_56 -> V_132 ,
( unsigned long long ) V_64 -> V_111 , V_65 ) ;
F_65 ( V_56 , ! F_53 ( & V_117 -> V_141 ) ) ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_43 ) ;
}
static void F_73 ( void )
{
F_74 ( & V_43 ) ;
}
