static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 ;
V_4 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
V_4 -> V_7 = V_3 ;
V_2 -> V_8 = V_4 ;
F_4 ( L_2
L_3 , V_2 -> V_9 , V_10 ,
V_11 ) ;
F_4 ( L_4
L_5 ,
V_2 -> V_9 , V_4 -> V_7 , V_12 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_8 ;
F_4 ( L_6
L_7 , V_2 -> V_9 , V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
V_2 -> V_8 = NULL ;
}
static void * F_7 ( struct V_1 * V_2 , const char * V_13 )
{
struct V_14 * V_14 ;
struct V_4 * V_4 = V_2 -> V_8 ;
V_14 = F_2 ( sizeof( struct V_14 ) , V_5 ) ;
if ( ! V_14 ) {
F_3 ( L_8 ) ;
return NULL ;
}
V_14 -> V_4 = V_4 ;
F_4 ( L_9 , V_13 ) ;
return V_14 ;
}
static struct V_15 * F_8 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
void * V_18 )
{
char * V_19 = NULL ;
struct V_15 * V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_14 = V_18 ;
struct V_4 * V_4 = V_2 -> V_8 ;
T_2 V_25 ;
struct V_26 * V_26 ;
struct V_27 * V_27 = NULL ;
int V_28 = 0 , V_29 , V_30 = - V_31 ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_19 = F_12 ( V_14 -> V_32 ) ;
F_10 ( V_25 ) ;
if ( F_13 ( V_19 ) ) {
F_3 ( L_10 ,
V_14 -> V_32 , F_13 ( V_19 ) ) ;
V_30 = F_14 ( V_19 ) ;
goto V_33;
}
#if 0
if (di->no_create_file)
flags = O_RDWR | O_LARGEFILE;
else
flags = O_RDWR | O_CREAT | O_LARGEFILE;
#else
V_29 = V_34 | V_35 | V_36 ;
#endif
if ( ! ( V_14 -> V_37 & V_38 ) )
V_29 |= V_39 ;
V_26 = F_15 ( V_19 , V_29 , 0600 ) ;
if ( F_13 ( V_26 ) ) {
F_3 ( L_11 , V_19 ) ;
V_30 = F_14 ( V_26 ) ;
goto V_33;
}
if ( ! V_26 || ! V_26 -> V_40 ) {
F_3 ( L_11 , V_19 ) ;
goto V_33;
}
V_14 -> V_41 = V_26 ;
V_27 = V_26 -> V_42 -> V_43 ;
if ( F_16 ( V_27 -> V_44 ) ) {
struct V_45 * V_46 ;
unsigned long long V_47 ;
V_46 = F_17 ( V_27 -> V_48 ) ;
V_24 = & V_22 . V_24 ;
V_24 -> V_49 = F_18 ( V_27 -> V_48 ) ;
V_24 -> V_50 = F_19 ( V_46 ) ;
V_24 -> V_51 = F_20 ( V_46 ) ;
V_14 -> V_52 = F_18 ( V_27 -> V_48 ) ;
V_47 = ( F_21 ( V_26 -> V_42 -> V_43 ) -
V_14 -> V_52 ) ;
F_4 ( L_12
L_13 ,
V_47 , F_22 ( V_47 , V_14 -> V_52 ) ,
V_14 -> V_52 ) ;
} else {
if ( ! ( V_14 -> V_37 & V_53 ) ) {
F_3 ( L_14
L_15
L_16 ) ;
goto V_33;
}
V_24 = & V_22 . V_24 ;
V_24 -> V_49 = V_54 ;
V_24 -> V_50 = V_12 ;
V_24 -> V_51 = V_12 ;
V_14 -> V_52 = V_54 ;
}
V_22 . V_55 = V_56 ;
V_22 . V_57 = V_58 ;
V_20 = F_23 ( V_2 , & V_59 ,
V_17 , V_28 , V_14 ,
& V_22 , L_17 , V_10 ) ;
if ( ! V_20 )
goto V_33;
V_14 -> V_60 = V_4 -> V_61 ++ ;
V_14 -> V_62 = V_20 -> V_57 ;
F_4 ( L_18
L_19 , V_4 -> V_7 , V_14 -> V_60 ,
V_14 -> V_32 , V_14 -> V_63 ) ;
F_24 ( V_19 ) ;
return V_20 ;
V_33:
if ( V_14 -> V_41 ) {
F_25 ( V_14 -> V_41 , NULL ) ;
V_14 -> V_41 = NULL ;
}
F_24 ( V_19 ) ;
return F_26 ( V_30 ) ;
}
static void F_27 ( void * V_18 )
{
struct V_14 * V_14 = V_18 ;
if ( V_14 -> V_41 ) {
F_25 ( V_14 -> V_41 , NULL ) ;
V_14 -> V_41 = NULL ;
}
F_6 ( V_14 ) ;
}
static inline struct V_64 * F_28 ( struct V_65 * V_66 )
{
return F_29 ( V_66 , struct V_64 , V_67 ) ;
}
static struct V_65 *
F_30 ( unsigned char * V_68 )
{
struct V_64 * V_69 ;
V_69 = F_2 ( sizeof( struct V_64 ) , V_5 ) ;
if ( ! V_69 ) {
F_3 ( L_20 ) ;
return NULL ;
}
return & V_69 -> V_67 ;
}
static int F_31 ( struct V_65 * V_66 )
{
struct V_64 * V_70 = F_28 ( V_66 ) ;
struct V_15 * V_17 = V_70 -> V_67 . V_71 -> V_17 ;
struct V_14 * V_20 = V_17 -> V_72 ;
struct V_26 * V_73 = V_20 -> V_41 ;
struct V_74 * V_75 = V_66 -> V_76 ;
struct V_77 * V_78 ;
T_2 V_25 ;
T_3 V_79 = ( V_66 -> V_80 *
V_17 -> V_81 -> V_82 . V_83 ) ;
int V_30 = 0 , V_84 ;
V_78 = F_2 ( sizeof( struct V_77 ) * V_66 -> V_85 , V_5 ) ;
if ( ! V_78 ) {
F_3 ( L_21 ) ;
return - V_6 ;
}
F_32 (task->task_sg, sg, task->task_sg_nents, i) {
V_78 [ V_84 ] . V_86 = V_75 -> V_87 ;
V_78 [ V_84 ] . V_88 = F_33 ( V_75 ) ;
}
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_30 = F_34 ( V_73 , & V_78 [ 0 ] , V_66 -> V_85 , & V_79 ) ;
F_10 ( V_25 ) ;
F_6 ( V_78 ) ;
if ( F_16 ( V_73 -> V_40 -> V_89 -> V_44 ) ) {
if ( V_30 < 0 || V_30 != V_66 -> V_90 ) {
F_3 ( L_22
L_23 , V_30 ,
( int ) V_66 -> V_90 ) ;
return ( V_30 < 0 ? V_30 : - V_31 ) ;
}
} else {
if ( V_30 < 0 ) {
F_3 ( L_24
L_25 , V_30 ) ;
return V_30 ;
}
}
return 1 ;
}
static int F_35 ( struct V_65 * V_66 )
{
struct V_64 * V_70 = F_28 ( V_66 ) ;
struct V_15 * V_17 = V_70 -> V_67 . V_71 -> V_17 ;
struct V_14 * V_20 = V_17 -> V_72 ;
struct V_26 * V_73 = V_20 -> V_41 ;
struct V_74 * V_75 = V_66 -> V_76 ;
struct V_77 * V_78 ;
T_2 V_25 ;
T_3 V_79 = ( V_66 -> V_80 *
V_17 -> V_81 -> V_82 . V_83 ) ;
int V_30 , V_84 = 0 ;
V_78 = F_2 ( sizeof( struct V_77 ) * V_66 -> V_85 , V_5 ) ;
if ( ! V_78 ) {
F_3 ( L_26 ) ;
return - V_6 ;
}
F_32 (task->task_sg, sg, task->task_sg_nents, i) {
V_78 [ V_84 ] . V_86 = V_75 -> V_87 ;
V_78 [ V_84 ] . V_88 = F_33 ( V_75 ) ;
}
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_30 = F_36 ( V_73 , & V_78 [ 0 ] , V_66 -> V_85 , & V_79 ) ;
F_10 ( V_25 ) ;
F_6 ( V_78 ) ;
if ( V_30 < 0 || V_30 != V_66 -> V_90 ) {
F_3 ( L_27 , V_30 ) ;
return ( V_30 < 0 ? V_30 : - V_31 ) ;
}
return 1 ;
}
static void F_37 ( struct V_65 * V_66 )
{
struct V_91 * V_92 = V_66 -> V_71 ;
struct V_15 * V_20 = V_92 -> V_17 ;
struct V_14 * V_14 = V_20 -> V_72 ;
int V_93 = ( V_92 -> V_94 [ 1 ] & 0x2 ) ;
T_3 V_95 , V_96 ;
int V_30 ;
if ( V_93 )
F_38 ( V_92 , 1 ) ;
if ( V_92 -> V_97 == 0 && V_92 -> V_98 == 0 ) {
V_95 = 0 ;
V_96 = V_99 ;
} else {
V_95 = V_92 -> V_97 * V_20 -> V_81 -> V_82 . V_83 ;
if ( V_92 -> V_98 )
V_96 = V_95 + V_92 -> V_98 ;
else
V_96 = V_99 ;
}
V_30 = F_39 ( V_14 -> V_41 , V_95 , V_96 , 1 ) ;
if ( V_30 != 0 )
F_3 ( L_28 , V_30 ) ;
if ( ! V_93 )
F_38 ( V_92 , V_30 == 0 ) ;
}
static void F_40 ( struct V_91 * V_92 , struct V_65 * V_66 )
{
struct V_15 * V_20 = V_92 -> V_17 ;
struct V_14 * V_14 = V_20 -> V_72 ;
T_3 V_95 = V_66 -> V_80 * V_20 -> V_81 -> V_82 . V_83 ;
T_3 V_96 = V_95 + V_66 -> V_90 ;
int V_30 ;
F_4 ( L_29 ,
V_66 -> V_80 , V_66 -> V_90 ) ;
V_30 = F_39 ( V_14 -> V_41 , V_95 , V_96 , 1 ) ;
if ( V_30 != 0 )
F_3 ( L_28 , V_30 ) ;
}
static int F_41 ( struct V_65 * V_66 )
{
struct V_91 * V_92 = V_66 -> V_71 ;
struct V_15 * V_20 = V_92 -> V_17 ;
int V_30 = 0 ;
if ( V_66 -> V_100 == V_101 ) {
V_30 = F_31 ( V_66 ) ;
} else {
V_30 = F_35 ( V_66 ) ;
if ( V_30 > 0 &&
V_20 -> V_81 -> V_82 . V_102 > 0 &&
V_20 -> V_81 -> V_82 . V_103 > 0 &&
( V_92 -> V_104 & V_105 ) ) {
F_40 ( V_92 , V_66 ) ;
}
}
if ( V_30 < 0 ) {
V_92 -> V_106 = V_107 ;
return V_30 ;
}
if ( V_30 ) {
V_66 -> V_108 = V_109 ;
F_42 ( V_66 , 1 ) ;
}
return 0 ;
}
static void F_43 ( struct V_65 * V_66 )
{
struct V_64 * V_70 = F_28 ( V_66 ) ;
F_6 ( V_70 ) ;
}
static T_4 F_44 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_110 , T_4 V_111 )
{
struct V_14 * V_14 = V_17 -> V_112 ;
char * V_113 , * V_114 , * V_115 , * V_116 ;
T_5 args [ V_117 ] ;
int V_30 = 0 , V_118 , V_119 ;
V_116 = F_45 ( V_110 , V_5 ) ;
if ( ! V_116 )
return - V_6 ;
V_113 = V_116 ;
while ( ( V_114 = F_46 ( & V_116 , L_30 ) ) != NULL ) {
if ( ! * V_114 )
continue;
V_119 = F_47 ( V_114 , V_120 , args ) ;
switch ( V_119 ) {
case V_121 :
V_115 = F_48 ( & args [ 0 ] ) ;
if ( ! V_115 ) {
V_30 = - V_6 ;
break;
}
snprintf ( V_14 -> V_32 , V_122 ,
L_31 , V_115 ) ;
F_6 ( V_115 ) ;
F_4 ( L_32 ,
V_14 -> V_32 ) ;
V_14 -> V_37 |= V_123 ;
break;
case V_124 :
V_115 = F_48 ( & args [ 0 ] ) ;
if ( ! V_115 ) {
V_30 = - V_6 ;
break;
}
V_30 = F_49 ( V_115 , 0 , & V_14 -> V_63 ) ;
F_6 ( V_115 ) ;
if ( V_30 < 0 ) {
F_3 ( L_33
L_34 ) ;
goto V_125;
}
F_4 ( L_35
L_36 , V_14 -> V_63 ) ;
V_14 -> V_37 |= V_53 ;
break;
case V_126 :
F_50 ( args , & V_118 ) ;
if ( V_118 != 1 ) {
F_3 ( L_37 , V_118 ) ;
V_30 = - V_31 ;
goto V_125;
}
F_4 ( L_38
L_39 ) ;
V_14 -> V_37 |= V_38 ;
break;
default:
break;
}
}
V_125:
F_6 ( V_113 ) ;
return ( ! V_30 ) ? V_111 : V_30 ;
}
static T_4 F_51 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_14 * V_14 = V_17 -> V_112 ;
if ( ! ( V_14 -> V_37 & V_123 ) ) {
F_3 ( L_40 ) ;
return - V_31 ;
}
return 0 ;
}
static T_4 F_52 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_127 )
{
struct V_14 * V_14 = V_17 -> V_112 ;
T_4 V_128 = 0 ;
V_128 = sprintf ( V_127 + V_128 , L_41 , V_14 -> V_60 ) ;
V_128 += sprintf ( V_127 + V_128 , L_42 ,
V_14 -> V_32 , V_14 -> V_63 ,
( V_14 -> V_37 & V_38 ) ?
L_43 : L_44 ) ;
return V_128 ;
}
static T_1 F_53 ( struct V_15 * V_20 )
{
return V_129 ;
}
static T_1 F_54 ( struct V_15 * V_20 )
{
return V_130 ;
}
static T_6 F_55 ( struct V_15 * V_20 )
{
struct V_14 * V_14 = V_20 -> V_72 ;
struct V_26 * V_131 = V_14 -> V_41 ;
struct V_27 * V_84 = V_131 -> V_42 -> V_43 ;
unsigned long long V_47 ;
if ( F_16 ( V_84 -> V_44 ) )
V_47 = ( F_21 ( V_84 ) - V_14 -> V_52 ) ;
else
V_47 = V_14 -> V_63 ;
return F_22 ( V_47 , V_20 -> V_81 -> V_82 . V_83 ) ;
}
static int T_7 F_56 ( void )
{
return F_57 ( & V_59 ) ;
}
static void F_58 ( void )
{
F_59 ( & V_59 ) ;
}
