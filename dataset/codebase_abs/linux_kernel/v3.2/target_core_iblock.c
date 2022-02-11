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
static void F_31 ( struct V_67 * V_67 , int V_68 )
{
struct V_69 * V_70 = V_67 -> V_71 ;
if ( V_68 )
F_3 ( L_18 , V_68 ) ;
if ( V_70 )
F_32 ( V_70 , V_68 == 0 ) ;
F_33 ( V_67 ) ;
}
static void F_34 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = V_59 -> V_72 ;
struct V_14 * V_15 = V_70 -> V_19 -> V_73 ;
int V_74 = ( V_70 -> V_75 [ 1 ] & 0x2 ) ;
struct V_67 * V_67 ;
if ( V_74 )
F_32 ( V_70 , 1 ) ;
V_67 = F_35 ( V_6 , 0 ) ;
V_67 -> V_76 = F_31 ;
V_67 -> V_77 = V_15 -> V_45 ;
if ( ! V_74 )
V_67 -> V_71 = V_70 ;
F_36 ( V_78 , V_67 ) ;
}
static int F_37 ( struct V_17 * V_21 , T_2 V_79 , T_1 V_80 )
{
struct V_14 * V_81 = V_21 -> V_73 ;
struct V_24 * V_25 = V_81 -> V_45 ;
int V_82 = 0 ;
return F_38 ( V_25 , V_79 , V_80 , V_6 , V_82 ) ;
}
static void F_39 ( struct V_58 * V_59 )
{
F_6 ( F_24 ( V_59 ) ) ;
}
static T_3 F_40 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const char * V_83 , T_3 V_84 )
{
struct V_14 * V_15 = V_19 -> V_85 ;
char * V_86 , * V_87 , * V_88 , * V_89 ;
T_4 args [ V_90 ] ;
int V_31 = 0 , V_91 ;
V_89 = F_41 ( V_83 , V_6 ) ;
if ( ! V_89 )
return - V_7 ;
V_86 = V_89 ;
while ( ( V_87 = F_42 ( & V_89 , L_19 ) ) != NULL ) {
if ( ! * V_87 )
continue;
V_91 = F_43 ( V_87 , V_92 , args ) ;
switch ( V_91 ) {
case V_93 :
if ( V_15 -> V_45 ) {
F_3 ( L_20
L_21 ) ;
V_31 = - V_94 ;
goto V_95;
}
V_88 = F_44 ( & args [ 0 ] ) ;
if ( ! V_88 ) {
V_31 = - V_7 ;
break;
}
snprintf ( V_15 -> V_34 , V_96 ,
L_22 , V_88 ) ;
F_6 ( V_88 ) ;
F_4 ( L_23 ,
V_15 -> V_34 ) ;
V_15 -> V_97 |= V_98 ;
break;
case V_99 :
break;
default:
break;
}
}
V_95:
F_6 ( V_86 ) ;
return ( ! V_31 ) ? V_84 : V_31 ;
}
static T_3 F_45 (
struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_14 * V_81 = V_19 -> V_85 ;
if ( ! ( V_81 -> V_97 & V_98 ) ) {
F_3 ( L_24 ) ;
return - V_32 ;
}
return 0 ;
}
static T_3 F_46 (
struct V_1 * V_2 ,
struct V_18 * V_19 ,
char * V_100 )
{
struct V_14 * V_81 = V_19 -> V_85 ;
struct V_24 * V_25 = V_81 -> V_45 ;
char V_101 [ V_102 ] ;
T_3 V_103 = 0 ;
if ( V_25 )
V_103 += sprintf ( V_100 + V_103 , L_25 ,
F_47 ( V_25 , V_101 ) ) ;
if ( V_81 -> V_97 & V_98 ) {
V_103 += sprintf ( V_100 + V_103 , L_26 ,
V_81 -> V_34 ) ;
} else
V_103 += sprintf ( V_100 + V_103 , L_27 ) ;
V_103 += sprintf ( V_100 + V_103 , L_28 ) ;
if ( V_25 ) {
V_103 += sprintf ( V_100 + V_103 , L_29 ,
F_48 ( V_25 -> V_104 ) , F_49 ( V_25 -> V_104 ) , ( ! V_25 -> V_105 ) ?
L_30 : ( V_25 -> V_106 == (struct V_14 * ) V_81 ) ?
L_31 : L_32 ) ;
} else {
V_103 += sprintf ( V_100 + V_103 , L_33 ) ;
}
return V_103 ;
}
static void F_50 ( struct V_67 * V_67 )
{
struct V_58 * V_59 = V_67 -> V_71 ;
struct V_14 * V_15 = V_59 -> V_72 -> V_19 -> V_73 ;
F_51 ( V_67 , V_15 -> V_33 ) ;
}
static struct V_67 *
F_52 ( struct V_58 * V_59 , T_2 V_79 , T_1 V_107 )
{
struct V_14 * V_15 = V_59 -> V_72 -> V_19 -> V_73 ;
struct V_57 * V_62 = F_24 ( V_59 ) ;
struct V_67 * V_67 ;
V_67 = F_53 ( V_108 , V_107 , V_15 -> V_33 ) ;
if ( ! V_67 ) {
F_3 ( L_34 ) ;
return NULL ;
}
F_4 ( L_35
L_36 , V_67 , V_59 -> V_109 , V_15 -> V_33 ) ;
F_4 ( L_37 , V_67 , V_59 -> V_110 ) ;
V_67 -> V_77 = V_15 -> V_45 ;
V_67 -> V_71 = V_59 ;
V_67 -> V_111 = F_50 ;
V_67 -> V_76 = & V_112 ;
V_67 -> V_113 = V_79 ;
F_54 ( & V_62 -> V_63 ) ;
F_4 ( L_38 , ( unsigned long long ) V_67 -> V_113 ) ;
F_4 ( L_39 ,
F_55 ( & V_62 -> V_63 ) ) ;
return V_67 ;
}
static int F_56 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = V_59 -> V_72 ;
struct V_17 * V_21 = V_70 -> V_19 ;
struct V_67 * V_67 ;
struct V_114 V_115 ;
struct V_116 * V_117 ;
T_1 V_118 , V_107 = V_59 -> V_109 ;
T_2 V_119 ;
struct V_120 V_121 ;
int V_122 ;
if ( V_59 -> V_123 == V_124 ) {
if ( V_21 -> V_47 -> V_48 . V_125 == 0 ||
( V_21 -> V_47 -> V_48 . V_126 > 0 &&
( V_70 -> V_127 & V_128 ) ) )
V_122 = V_129 ;
else
V_122 = V_130 ;
} else {
V_122 = V_131 ;
}
if ( V_21 -> V_47 -> V_48 . V_66 == 4096 )
V_119 = ( V_59 -> V_132 << 3 ) ;
else if ( V_21 -> V_47 -> V_48 . V_66 == 2048 )
V_119 = ( V_59 -> V_132 << 2 ) ;
else if ( V_21 -> V_47 -> V_48 . V_66 == 1024 )
V_119 = ( V_59 -> V_132 << 1 ) ;
else if ( V_21 -> V_47 -> V_48 . V_66 == 512 )
V_119 = V_59 -> V_132 ;
else {
F_3 ( L_40
L_41 , V_21 -> V_47 -> V_48 . V_66 ) ;
V_70 -> V_133 = V_134 ;
return - V_135 ;
}
V_67 = F_52 ( V_59 , V_119 , V_107 ) ;
if ( ! V_67 ) {
V_70 -> V_133 = V_134 ;
return - V_7 ;
}
F_57 ( & V_115 ) ;
F_58 ( & V_115 , V_67 ) ;
F_59 (task->task_sg, sg, task->task_sg_nents, i) {
while ( F_60 ( V_67 , F_61 ( V_117 ) , V_117 -> V_136 , V_117 -> V_137 )
!= V_117 -> V_136 ) {
V_67 = F_52 ( V_59 , V_119 , V_107 ) ;
if ( ! V_67 )
goto V_138;
F_58 ( & V_115 , V_67 ) ;
}
V_119 += V_117 -> V_136 >> V_139 ;
V_107 -- ;
}
F_62 ( & V_121 ) ;
while ( ( V_67 = F_63 ( & V_115 ) ) )
F_36 ( V_122 , V_67 ) ;
F_64 ( & V_121 ) ;
return 0 ;
V_138:
while ( ( V_67 = F_63 ( & V_115 ) ) )
F_33 ( V_67 ) ;
V_70 -> V_133 = V_134 ;
return - V_7 ;
}
static T_1 F_65 ( struct V_17 * V_21 )
{
return V_140 ;
}
static T_1 F_66 ( struct V_17 * V_21 )
{
return V_141 ;
}
static T_2 F_67 ( struct V_17 * V_21 )
{
struct V_14 * V_81 = V_21 -> V_73 ;
struct V_24 * V_25 = V_81 -> V_45 ;
struct V_26 * V_27 = F_14 ( V_25 ) ;
return F_28 ( V_21 , V_25 , V_27 ) ;
}
static void V_112 ( struct V_67 * V_67 , int V_68 )
{
struct V_58 * V_59 = V_67 -> V_71 ;
struct V_57 * V_142 = F_24 ( V_59 ) ;
if ( ! F_68 ( V_143 , & V_67 -> V_144 ) && ! V_68 )
V_68 = - V_145 ;
if ( V_68 != 0 ) {
F_3 ( L_42
L_43 , V_67 , V_68 ) ;
F_54 ( & V_142 -> V_146 ) ;
F_69 () ;
}
F_33 ( V_67 ) ;
if ( ! F_70 ( & V_142 -> V_63 ) )
return;
F_4 ( L_44 ,
V_59 , V_67 , V_59 -> V_132 ,
( unsigned long long ) V_67 -> V_113 , V_68 ) ;
F_71 ( V_59 , ! F_55 ( & V_142 -> V_146 ) ) ;
}
static int T_5 F_72 ( void )
{
return F_73 ( & V_46 ) ;
}
static void F_74 ( void )
{
F_75 ( & V_46 ) ;
}
