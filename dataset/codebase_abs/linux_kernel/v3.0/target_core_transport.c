int F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! ( V_2 ) ) {
F_3 ( V_4 L_1 ) ;
return - 1 ;
}
F_4 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_5 ( & V_2 -> V_12 ) ;
F_5 ( & V_2 -> V_13 ) ;
V_14 = F_6 ( L_2 ,
sizeof( struct V_15 ) , F_7 ( struct V_15 ) , 0 , NULL ) ;
if ( ! ( V_14 ) ) {
F_3 ( V_4 L_3 ) ;
goto V_16;
}
V_17 = F_6 ( L_4 ,
sizeof( struct V_18 ) , F_7 ( struct V_18 ) ,
0 , NULL ) ;
if ( ! ( V_17 ) ) {
F_3 ( V_4 L_5
L_6 ) ;
goto V_16;
}
V_19 = F_6 ( L_7 ,
sizeof( struct V_20 ) , F_7 ( struct V_20 ) ,
0 , NULL ) ;
if ( ! ( V_19 ) ) {
F_3 ( V_4 L_8
L_6 ) ;
goto V_16;
}
V_21 = F_6 ( L_9 ,
sizeof( struct V_22 ) , F_7 ( struct V_22 ) ,
0 , NULL ) ;
if ( ! ( V_21 ) ) {
F_3 ( V_4 L_10 ) ;
goto V_16;
}
V_23 = F_6 ( L_11 ,
sizeof( struct V_24 ) , F_7 ( struct V_24 ) , 0 , NULL ) ;
if ( ! ( V_23 ) ) {
F_3 ( V_4 L_12 ) ;
goto V_16;
}
V_25 = F_6 ( L_13 ,
sizeof( struct V_26 ) ,
F_7 ( struct V_26 ) , 0 , NULL ) ;
if ( ! ( V_25 ) ) {
F_3 ( V_4 L_14
L_6 ) ;
goto V_16;
}
V_27 = F_6 ( L_15 ,
sizeof( struct V_28 ) , F_7 ( struct V_28 ) ,
0 , NULL ) ;
if ( ! ( V_27 ) ) {
F_3 ( V_4 L_16
L_6 ) ;
goto V_16;
}
V_29 = F_6 ( L_17 ,
sizeof( struct V_30 ) ,
F_7 ( struct V_30 ) , 0 , NULL ) ;
if ( ! ( V_29 ) ) {
F_3 ( V_4 L_18
L_19 ) ;
goto V_16;
}
V_31 = F_6 ( L_20 ,
sizeof( struct V_32 ) ,
F_7 ( struct V_32 ) , 0 , NULL ) ;
if ( ! ( V_31 ) ) {
F_3 ( V_4 L_21
L_19 ) ;
goto V_16;
}
V_33 = F_6 (
L_22 ,
sizeof( struct V_34 ) ,
F_7 ( struct V_34 ) ,
0 , NULL ) ;
if ( ! ( V_33 ) ) {
F_3 ( V_4 L_21
L_23 ) ;
goto V_16;
}
V_1 = V_2 ;
return 0 ;
V_16:
if ( V_14 )
F_8 ( V_14 ) ;
if ( V_17 )
F_8 ( V_17 ) ;
if ( V_19 )
F_8 ( V_19 ) ;
if ( V_21 )
F_8 ( V_21 ) ;
if ( V_23 )
F_8 ( V_23 ) ;
if ( V_25 )
F_8 ( V_25 ) ;
if ( V_27 )
F_8 ( V_27 ) ;
if ( V_29 )
F_8 ( V_29 ) ;
if ( V_31 )
F_8 ( V_31 ) ;
if ( V_33 )
F_8 ( V_33 ) ;
F_9 ( V_2 ) ;
return - 1 ;
}
void F_10 ( void )
{
struct V_1 * V_2 ;
V_2 = V_1 ;
if ( ! ( V_2 ) )
return;
F_8 ( V_14 ) ;
F_8 ( V_17 ) ;
F_8 ( V_19 ) ;
F_8 ( V_21 ) ;
F_8 ( V_23 ) ;
F_8 ( V_25 ) ;
F_8 ( V_27 ) ;
F_8 ( V_29 ) ;
F_8 ( V_31 ) ;
F_8 ( V_33 ) ;
F_9 ( V_2 ) ;
V_1 = NULL ;
}
void F_11 ( void )
{
memset ( & V_35 , 0 , sizeof( struct V_35 ) ) ;
F_5 ( & V_35 . V_36 ) ;
}
T_1 F_12 ( T_2 type )
{
T_1 V_37 ;
if ( ( type < 0 ) || ( type >= V_38 ) ) {
F_3 ( V_4 L_24 , type ) ;
return - V_39 ;
}
F_13 ( & V_35 . V_36 ) ;
V_37 = ++ V_35 . V_40 [ type ] ;
if ( V_37 == 0 )
V_37 = ++ V_35 . V_40 [ type ] ;
F_14 ( & V_35 . V_36 ) ;
return V_37 ;
}
void F_15 ( struct V_41 * V_42 )
{
F_16 ( & V_42 -> V_43 , 0 ) ;
F_4 ( & V_42 -> V_44 ) ;
F_17 ( & V_42 -> V_45 ) ;
F_5 ( & V_42 -> V_46 ) ;
}
static int F_18 ( void )
{
int V_47 ;
V_47 = F_19 ( L_25 ) ;
if ( V_47 != 0 )
F_3 ( V_4 L_26 ) ;
V_47 = F_19 ( L_27 ) ;
if ( V_47 != 0 )
F_3 ( V_4 L_28 ) ;
V_47 = F_19 ( L_29 ) ;
if ( V_47 != 0 )
F_3 ( V_4 L_30 ) ;
V_47 = F_19 ( L_31 ) ;
if ( V_47 != 0 )
F_3 ( V_4 L_32 ) ;
return 0 ;
}
int F_20 ( void )
{
if ( V_1 -> V_48 )
return 0 ;
if ( F_18 () < 0 )
return - 1 ;
V_1 -> V_48 = 1 ;
return 0 ;
}
struct V_20 * F_21 ( void )
{
struct V_20 * V_49 ;
V_49 = F_22 ( V_19 , V_3 ) ;
if ( ! ( V_49 ) ) {
F_3 ( V_4 L_33
L_34 ) ;
return F_23 ( - V_50 ) ;
}
F_4 ( & V_49 -> V_51 ) ;
F_4 ( & V_49 -> V_52 ) ;
return V_49 ;
}
void F_24 (
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_20 * V_49 ,
void * V_57 )
{
unsigned char V_58 [ V_59 ] ;
V_49 -> V_54 = V_54 ;
V_49 -> V_57 = V_57 ;
if ( V_56 ) {
if ( F_25 ( V_54 ) -> V_60 != NULL ) {
memset ( & V_58 [ 0 ] , 0 , V_59 ) ;
F_25 ( V_54 ) -> V_60 ( V_49 ,
& V_58 [ 0 ] , V_59 ) ;
V_49 -> V_61 = F_26 ( & V_58 [ 0 ] ) ;
}
F_27 ( & V_56 -> V_62 ) ;
V_56 -> V_63 = V_49 ;
F_28 ( & V_49 -> V_52 ,
& V_56 -> V_64 ) ;
F_29 ( & V_56 -> V_62 ) ;
}
F_28 ( & V_49 -> V_51 , & V_54 -> V_65 ) ;
F_3 ( V_66 L_35 ,
F_25 ( V_54 ) -> F_30 () , V_49 -> V_57 ) ;
}
void F_31 (
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_20 * V_49 ,
void * V_57 )
{
F_32 ( & V_54 -> V_67 ) ;
F_24 ( V_54 , V_56 , V_49 , V_57 ) ;
F_33 ( & V_54 -> V_67 ) ;
}
void F_34 ( struct V_20 * V_49 )
{
struct V_55 * V_56 ;
unsigned long V_68 ;
V_56 = V_49 -> V_55 ;
if ( ( V_56 ) ) {
F_35 ( & V_56 -> V_62 , V_68 ) ;
F_36 ( & V_49 -> V_52 ) ;
if ( F_37 ( & V_56 -> V_64 ) )
V_56 -> V_63 = NULL ;
else {
V_56 -> V_63 = F_38 (
V_56 -> V_64 . V_69 ,
struct V_20 , V_52 ) ;
}
F_39 ( & V_56 -> V_62 , V_68 ) ;
}
}
void F_40 ( struct V_20 * V_49 )
{
F_41 ( V_19 , V_49 ) ;
}
void F_42 ( struct V_20 * V_49 )
{
struct V_53 * V_54 = V_49 -> V_54 ;
struct V_55 * V_56 ;
if ( ! ( V_54 ) ) {
F_40 ( V_49 ) ;
return;
}
F_32 ( & V_54 -> V_67 ) ;
F_36 ( & V_49 -> V_51 ) ;
V_49 -> V_54 = NULL ;
V_49 -> V_57 = NULL ;
F_33 ( & V_54 -> V_67 ) ;
V_56 = V_49 -> V_55 ;
if ( ( V_56 ) ) {
F_32 ( & V_54 -> V_70 ) ;
if ( V_56 -> V_71 ) {
if ( ! ( F_25 ( V_54 ) -> F_43 (
V_54 ) ) ) {
F_36 ( & V_56 -> V_72 ) ;
V_54 -> V_73 -- ;
F_33 ( & V_54 -> V_70 ) ;
F_44 ( V_56 ) ;
F_45 ( V_56 , V_54 ) ;
F_25 ( V_54 ) -> F_46 ( V_54 ,
V_56 ) ;
F_32 ( & V_54 -> V_70 ) ;
}
}
F_33 ( & V_54 -> V_70 ) ;
}
F_40 ( V_49 ) ;
F_3 ( V_66 L_36 ,
F_25 ( V_54 ) -> F_30 () ) ;
}
static void F_47 ( struct V_15 * V_74 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
unsigned long V_68 ;
if ( ! F_48 ( V_74 ) )
return;
F_49 (task, &T_TASK(cmd)->t_task_list, t_list) {
V_76 = V_78 -> V_79 ;
if ( ! ( V_76 ) )
continue;
if ( F_50 ( & V_78 -> V_80 ) )
continue;
if ( ! ( F_50 ( & V_78 -> V_81 ) ) )
continue;
F_35 ( & V_76 -> V_82 , V_68 ) ;
F_36 ( & V_78 -> V_83 ) ;
F_51 ( L_37 ,
F_52 ( V_74 ) -> F_53 ( V_74 ) , V_76 , V_78 ) ;
F_39 ( & V_76 -> V_82 , V_68 ) ;
F_16 ( & V_78 -> V_81 , 0 ) ;
F_54 ( & F_48 ( V_74 ) -> V_84 ) ;
}
}
static int F_55 (
struct V_15 * V_74 ,
int V_85 ,
T_3 V_86 )
{
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_88 ) ) {
F_56 ( L_38
L_39 , V_89 , __LINE__ ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
V_74 -> V_90 = V_74 -> V_86 ;
V_74 -> V_86 = V_91 ;
F_16 ( & F_48 ( V_74 ) -> V_92 , 0 ) ;
if ( V_85 == 2 )
F_47 ( V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_58 ( & F_48 ( V_74 ) -> V_93 ) ;
return 1 ;
}
if ( F_50 ( & F_48 ( V_74 ) -> V_94 ) ) {
F_56 ( L_40
L_41 , V_89 , __LINE__ ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
V_74 -> V_90 = V_74 -> V_86 ;
V_74 -> V_86 = V_91 ;
if ( V_85 == 2 )
F_47 ( V_74 ) ;
if ( V_85 == 2 )
V_74 -> V_95 = NULL ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_58 ( & F_48 ( V_74 ) -> V_96 ) ;
return 1 ;
}
if ( V_85 ) {
F_16 ( & F_48 ( V_74 ) -> V_92 , 0 ) ;
if ( V_85 == 2 ) {
F_47 ( V_74 ) ;
V_74 -> V_95 = NULL ;
if ( F_52 ( V_74 ) -> V_97 != NULL ) {
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_52 ( V_74 ) -> V_97 ( V_74 ) ;
return 1 ;
}
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return 0 ;
} else if ( V_86 )
V_74 -> V_86 = V_86 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return 0 ;
}
static int F_59 ( struct V_15 * V_74 )
{
return F_55 ( V_74 , 2 , 0 ) ;
}
static void F_60 ( struct V_15 * V_74 )
{
struct V_95 * V_98 = F_61 ( V_74 ) ;
unsigned long V_68 ;
if ( ! V_98 )
return;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( ! ( F_50 ( & F_48 ( V_74 ) -> V_99 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
goto V_100;
}
F_16 ( & F_48 ( V_74 ) -> V_99 , 0 ) ;
F_47 ( V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
V_100:
F_35 ( & V_98 -> V_101 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_102 ) ) {
F_36 ( & V_74 -> V_103 ) ;
F_16 ( & F_48 ( V_74 ) -> V_102 , 0 ) ;
#if 0
printk(KERN_INFO "Removed ITT: 0x%08x from LUN LIST[%d]\n"
CMD_TFO(cmd)->get_task_tag(cmd), lun->unpacked_lun);
#endif
}
F_39 ( & V_98 -> V_101 , V_68 ) ;
}
void F_62 ( struct V_15 * V_74 , int remove )
{
F_63 ( V_74 , F_64 ( V_74 ) -> V_104 ) ;
F_60 ( V_74 ) ;
if ( F_59 ( V_74 ) )
return;
if ( remove )
F_65 ( V_74 , 0 , 0 ) ;
}
void F_66 ( struct V_15 * V_74 )
{
F_63 ( V_74 , F_64 ( V_74 ) -> V_104 ) ;
if ( F_59 ( V_74 ) )
return;
F_65 ( V_74 , 0 , 0 ) ;
}
static int F_67 (
struct V_15 * V_74 ,
int V_86 )
{
struct V_75 * V_76 = V_74 -> V_79 ;
struct V_41 * V_42 = V_76 -> V_104 ;
struct V_105 * V_106 ;
unsigned long V_68 ;
V_106 = F_2 ( sizeof( struct V_105 ) , V_107 ) ;
if ( ! ( V_106 ) ) {
F_3 ( V_4 L_42
L_43 ) ;
return - 1 ;
}
F_4 ( & V_106 -> V_108 ) ;
V_106 -> V_74 = ( void * ) V_74 ;
V_106 -> V_109 = V_86 ;
if ( V_86 ) {
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
V_74 -> V_86 = V_86 ;
F_16 ( & F_48 ( V_74 ) -> V_92 , 1 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
}
F_35 ( & V_42 -> V_46 , V_68 ) ;
F_28 ( & V_106 -> V_108 , & V_42 -> V_44 ) ;
F_68 ( & F_48 ( V_74 ) -> V_110 ) ;
F_39 ( & V_42 -> V_46 , V_68 ) ;
F_68 ( & V_42 -> V_43 ) ;
F_69 ( & V_42 -> V_45 ) ;
return 0 ;
}
static struct V_105 *
F_70 ( struct V_41 * V_42 )
{
struct V_15 * V_74 ;
struct V_105 * V_106 = NULL ;
if ( F_37 ( & V_42 -> V_44 ) )
return NULL ;
F_49 (qr, &qobj->qobj_list, qr_list)
break;
if ( V_106 -> V_74 ) {
V_74 = (struct V_15 * ) V_106 -> V_74 ;
F_54 ( & F_48 ( V_74 ) -> V_110 ) ;
}
F_36 ( & V_106 -> V_108 ) ;
F_54 ( & V_42 -> V_43 ) ;
return V_106 ;
}
static struct V_105 *
F_71 ( struct V_41 * V_42 )
{
struct V_15 * V_74 ;
struct V_105 * V_106 ;
unsigned long V_68 ;
F_35 ( & V_42 -> V_46 , V_68 ) ;
if ( F_37 ( & V_42 -> V_44 ) ) {
F_39 ( & V_42 -> V_46 , V_68 ) ;
return NULL ;
}
F_49 (qr, &qobj->qobj_list, qr_list)
break;
if ( V_106 -> V_74 ) {
V_74 = (struct V_15 * ) V_106 -> V_74 ;
F_54 ( & F_48 ( V_74 ) -> V_110 ) ;
}
F_36 ( & V_106 -> V_108 ) ;
F_54 ( & V_42 -> V_43 ) ;
F_39 ( & V_42 -> V_46 , V_68 ) ;
return V_106 ;
}
static void F_63 ( struct V_15 * V_74 ,
struct V_41 * V_42 )
{
struct V_15 * V_111 ;
struct V_105 * V_106 = NULL , * V_112 = NULL ;
unsigned long V_68 ;
F_35 ( & V_42 -> V_46 , V_68 ) ;
if ( ! ( F_50 ( & F_48 ( V_74 ) -> V_110 ) ) ) {
F_39 ( & V_42 -> V_46 , V_68 ) ;
return;
}
F_72 (qr, qr_p, &qobj->qobj_list, qr_list) {
V_111 = (struct V_15 * ) V_106 -> V_74 ;
if ( V_111 != V_74 )
continue;
F_54 ( & F_48 ( V_111 ) -> V_110 ) ;
F_54 ( & V_42 -> V_43 ) ;
F_36 ( & V_106 -> V_108 ) ;
F_9 ( V_106 ) ;
}
F_39 ( & V_42 -> V_46 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_110 ) ) {
F_3 ( V_4 L_44 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_50 ( & F_48 ( V_74 ) -> V_110 ) ) ;
}
}
void F_73 ( struct V_15 * V_74 , int V_113 )
{
struct V_77 * V_78 = F_74 ( F_48 ( V_74 ) -> V_114 . V_115 ,
struct V_77 , V_116 ) ;
if ( V_113 ) {
V_74 -> V_117 = V_118 ;
V_78 -> V_119 = V_120 ;
} else {
V_78 -> V_119 = V_121 ;
V_78 -> V_122 = V_123 ;
F_75 ( V_78 ) -> V_124 =
V_123 ;
}
F_76 ( V_78 , V_113 ) ;
}
void F_76 ( struct V_77 * V_78 , int V_125 )
{
struct V_15 * V_74 = F_75 ( V_78 ) ;
struct V_75 * V_76 = V_78 -> V_79 ;
int V_86 ;
unsigned long V_68 ;
#if 0
printk(KERN_INFO "task: %p CDB: 0x%02x obj_ptr: %p\n", task,
T_TASK(cmd)->t_task_cdb[0], dev);
#endif
if ( V_76 ) {
F_35 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
F_68 ( & V_76 -> V_127 ) ;
F_68 ( & F_77 ( V_76 ) -> V_128 ) ;
F_39 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
}
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_16 ( & V_78 -> V_80 , 0 ) ;
if ( V_76 && V_76 -> V_129 -> V_130 ) {
if ( V_76 -> V_129 -> V_130 ( V_78 ) != 0 ) {
V_74 -> V_131 |= V_132 ;
V_78 -> V_133 = 1 ;
V_125 = 1 ;
}
}
if ( F_50 ( & V_78 -> V_134 ) ) {
if ( F_50 ( & V_78 -> V_135 ) ) {
F_54 ( & F_48 ( V_74 ) -> V_136 ) ;
F_16 ( & V_78 -> V_135 , 0 ) ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_58 ( & V_78 -> V_137 ) ;
return;
}
if ( F_50 ( & V_78 -> V_135 ) ) {
if ( ! ( F_78 (
& F_48 ( V_74 ) -> V_138 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_68 ) ;
return;
}
V_86 = V_139 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_67 ( V_74 , V_86 ) ;
return;
}
F_54 ( & F_48 ( V_74 ) -> V_138 ) ;
if ( ! ( F_78 ( & F_48 ( V_74 ) -> V_140 ) ) ) {
if ( ! V_125 )
F_48 ( V_74 ) -> V_141 = 1 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return;
}
if ( ! V_125 || F_48 ( V_74 ) -> V_141 ) {
V_86 = V_142 ;
if ( ! V_78 -> V_122 ) {
V_78 -> V_122 =
V_143 ;
V_74 -> V_124 =
V_143 ;
}
} else {
F_16 ( & F_48 ( V_74 ) -> V_144 , 1 ) ;
V_86 = V_145 ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_67 ( V_74 , V_86 ) ;
}
static inline int F_79 (
struct V_77 * V_78 ,
struct V_77 * V_146 ,
struct V_75 * V_76 )
{
if ( V_76 -> V_147 != V_148 ) {
F_28 ( & V_78 -> V_149 , & V_76 -> V_150 ) ;
return 0 ;
}
if ( V_78 -> V_151 -> V_152 == V_153 ) {
F_80 ( & V_78 -> V_149 ,
( V_146 != NULL ) ?
& V_146 -> V_149 :
& V_76 -> V_150 ) ;
F_81 ( L_45
L_46 ,
F_48 ( V_78 -> V_151 ) -> V_154 [ 0 ] ) ;
return 1 ;
}
F_28 ( & V_78 -> V_149 , & V_76 -> V_150 ) ;
return 0 ;
}
static void F_82 (
struct V_77 * V_78 ,
struct V_77 * V_146 ,
struct V_75 * V_76 )
{
int V_155 ;
V_155 = F_79 ( V_78 , V_146 , V_76 ) ;
F_68 ( & V_76 -> V_156 ) ;
if ( F_50 ( & V_78 -> V_81 ) )
return;
if ( V_155 )
F_80 ( & V_78 -> V_83 , ( V_146 ) ?
& V_146 -> V_83 :
& V_76 -> V_157 ) ;
else
F_28 ( & V_78 -> V_83 , & V_76 -> V_157 ) ;
F_16 ( & V_78 -> V_81 , 1 ) ;
F_51 ( L_47 ,
F_52 ( V_78 -> V_151 ) -> F_57 ( V_78 -> V_151 ) ,
V_78 , V_76 ) ;
}
static void F_83 ( struct V_15 * V_74 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_49 (task, &T_TASK(cmd)->t_task_list, t_list) {
V_76 = V_78 -> V_79 ;
if ( F_50 ( & V_78 -> V_81 ) )
continue;
F_13 ( & V_76 -> V_82 ) ;
F_28 ( & V_78 -> V_83 , & V_76 -> V_157 ) ;
F_16 ( & V_78 -> V_81 , 1 ) ;
F_51 ( L_47 ,
F_52 ( V_78 -> V_151 ) -> F_57 (
V_78 -> V_151 ) , V_78 , V_76 ) ;
F_14 ( & V_76 -> V_82 ) ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
}
static void F_84 ( struct V_15 * V_74 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
struct V_77 * V_78 , * V_146 = NULL ;
unsigned long V_68 ;
F_35 ( & V_76 -> V_82 , V_68 ) ;
F_49 (task, &T_TASK(cmd)->t_task_list, t_list) {
if ( F_50 ( & V_78 -> V_158 ) )
continue;
F_82 ( V_78 , V_146 , V_76 ) ;
F_16 ( & V_78 -> V_158 , 1 ) ;
V_146 = V_78 ;
}
F_39 ( & V_76 -> V_82 , V_68 ) ;
return;
}
static struct V_77 *
F_85 ( struct V_75 * V_76 )
{
struct V_77 * V_78 ;
if ( F_37 ( & V_76 -> V_150 ) )
return NULL ;
F_49 (task, &dev->execute_task_list, t_execute_list)
break;
F_36 ( & V_78 -> V_149 ) ;
F_16 ( & V_78 -> V_158 , 0 ) ;
F_54 ( & V_76 -> V_156 ) ;
return V_78 ;
}
void F_86 (
struct V_77 * V_78 ,
struct V_75 * V_76 )
{
unsigned long V_68 ;
if ( F_50 ( & V_78 -> V_158 ) == 0 ) {
F_87 () ;
return;
}
F_35 ( & V_76 -> V_82 , V_68 ) ;
F_36 ( & V_78 -> V_149 ) ;
F_16 ( & V_78 -> V_158 , 0 ) ;
F_54 ( & V_76 -> V_156 ) ;
F_39 ( & V_76 -> V_82 , V_68 ) ;
}
unsigned char * F_88 ( struct V_15 * V_74 )
{
switch ( V_74 -> V_159 ) {
case V_160 :
return L_48 ;
case V_161 :
return L_49 ;
case V_162 :
return L_50 ;
case V_163 :
return L_51 ;
default:
break;
}
return L_52 ;
}
void F_89 (
struct V_75 * V_76 ,
char * V_164 ,
int * V_165 )
{
* V_165 += sprintf ( V_164 + * V_165 , L_53 ) ;
switch ( V_76 -> V_166 ) {
case V_167 :
* V_165 += sprintf ( V_164 + * V_165 , L_54 ) ;
break;
case V_168 :
* V_165 += sprintf ( V_164 + * V_165 , L_55 ) ;
break;
case V_169 :
* V_165 += sprintf ( V_164 + * V_165 , L_56 ) ;
break;
case V_170 :
case V_171 :
* V_165 += sprintf ( V_164 + * V_165 , L_57 ) ;
break;
default:
* V_165 += sprintf ( V_164 + * V_165 , L_58 , V_76 -> V_166 ) ;
break;
}
* V_165 += sprintf ( V_164 + * V_165 , L_59 ,
F_50 ( & V_76 -> V_156 ) , F_50 ( & V_76 -> V_127 ) ,
V_76 -> V_172 ) ;
* V_165 += sprintf ( V_164 + * V_165 , L_60 ,
F_90 ( V_76 ) -> V_173 , F_90 ( V_76 ) -> V_174 ) ;
* V_165 += sprintf ( V_164 + * V_165 , L_61 ) ;
}
static void F_91 ( struct V_75 * V_76 )
{
struct V_15 * V_74 = NULL ;
struct V_105 * V_106 = NULL , * V_112 = NULL ;
int V_175 = 0 , V_86 ;
unsigned long V_68 ;
F_35 ( & V_76 -> V_104 -> V_46 , V_68 ) ;
F_72 (qr, qr_p, &dev->dev_queue_obj->qobj_list,
qr_list) {
V_74 = (struct V_15 * ) V_106 -> V_74 ;
V_86 = V_106 -> V_109 ;
F_36 ( & V_106 -> V_108 ) ;
F_9 ( V_106 ) ;
F_39 ( & V_76 -> V_104 -> V_46 ,
V_68 ) ;
F_3 ( V_4 L_62
L_63 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_52 ( V_74 ) -> F_92 ( V_74 ) , V_86 ) ;
F_93 ( V_74 ) ;
V_175 = 1 ;
F_35 ( & V_76 -> V_104 -> V_46 , V_68 ) ;
}
F_39 ( & V_76 -> V_104 -> V_46 , V_68 ) ;
#if 0
if (bug_out)
BUG();
#endif
}
void F_94 (
struct V_176 * V_177 ,
unsigned char * V_178 ,
int V_179 )
{
unsigned char V_58 [ V_180 ] ;
int V_181 ;
memset ( V_58 , 0 , V_180 ) ;
V_181 = sprintf ( V_58 , L_64 ) ;
switch ( V_177 -> V_182 ) {
case 0x00 :
sprintf ( V_58 + V_181 , L_65 ) ;
break;
case 0x10 :
sprintf ( V_58 + V_181 , L_66 ) ;
break;
case 0x20 :
sprintf ( V_58 + V_181 , L_67 ) ;
break;
case 0x30 :
sprintf ( V_58 + V_181 , L_68 ) ;
break;
case 0x40 :
sprintf ( V_58 + V_181 , L_69
L_70 ) ;
break;
case 0x50 :
sprintf ( V_58 + V_181 , L_71 ) ;
break;
case 0x60 :
sprintf ( V_58 + V_181 , L_72 ) ;
break;
case 0x70 :
sprintf ( V_58 + V_181 , L_73
L_70 ) ;
break;
case 0x80 :
sprintf ( V_58 + V_181 , L_74 ) ;
break;
default:
sprintf ( V_58 + V_181 , L_75 ,
V_177 -> V_182 ) ;
break;
}
if ( V_178 )
strncpy ( V_178 , V_58 , V_179 ) ;
else
F_3 ( V_66 L_76 , V_58 ) ;
}
void
F_95 ( struct V_176 * V_177 , unsigned char * V_183 )
{
if ( V_183 [ 1 ] & 0x80 ) {
V_177 -> V_182 = ( V_183 [ 0 ] & 0xf0 ) ;
V_177 -> V_184 = 1 ;
F_94 ( V_177 , NULL , 0 ) ;
}
}
int F_96 (
struct V_176 * V_177 ,
unsigned char * V_178 ,
int V_179 )
{
unsigned char V_58 [ V_180 ] ;
int V_47 = 0 , V_181 ;
memset ( V_58 , 0 , V_180 ) ;
V_181 = sprintf ( V_58 , L_77 ) ;
switch ( V_177 -> V_185 ) {
case 0x00 :
sprintf ( V_58 + V_181 , L_78 ) ;
break;
case 0x10 :
sprintf ( V_58 + V_181 , L_79 ) ;
break;
case 0x20 :
sprintf ( V_58 + V_181 , L_80 ) ;
break;
default:
sprintf ( V_58 + V_181 , L_75 , V_177 -> V_185 ) ;
V_47 = - 1 ;
break;
}
if ( V_178 )
strncpy ( V_178 , V_58 , V_179 ) ;
else
F_3 ( L_76 , V_58 ) ;
return V_47 ;
}
int F_97 ( struct V_176 * V_177 , unsigned char * V_183 )
{
V_177 -> V_185 = ( V_183 [ 1 ] & 0x30 ) ;
return F_96 ( V_177 , NULL , 0 ) ;
}
int F_98 (
struct V_176 * V_177 ,
unsigned char * V_178 ,
int V_179 )
{
unsigned char V_58 [ V_180 ] ;
int V_47 = 0 , V_181 ;
memset ( V_58 , 0 , V_180 ) ;
V_181 = sprintf ( V_58 , L_81 ) ;
switch ( V_177 -> V_186 ) {
case 0x00 :
sprintf ( V_58 + V_181 , L_82 ) ;
break;
case 0x01 :
sprintf ( V_58 + V_181 , L_83 ) ;
break;
case 0x02 :
sprintf ( V_58 + V_181 , L_84 ) ;
break;
case 0x03 :
sprintf ( V_58 + V_181 , L_85 ) ;
break;
case 0x04 :
sprintf ( V_58 + V_181 , L_86 ) ;
break;
case 0x08 :
sprintf ( V_58 + V_181 , L_87 ) ;
break;
default:
sprintf ( V_58 + V_181 , L_88 ,
V_177 -> V_186 ) ;
V_47 = - 1 ;
break;
}
if ( V_178 )
strncpy ( V_178 , V_58 , V_179 ) ;
else
F_3 ( L_76 , V_58 ) ;
return V_47 ;
}
int F_99 ( struct V_176 * V_177 , unsigned char * V_183 )
{
V_177 -> V_186 = ( V_183 [ 1 ] & 0x0f ) ;
return F_98 ( V_177 , NULL , 0 ) ;
}
int F_100 (
struct V_176 * V_177 ,
unsigned char * V_178 ,
int V_179 )
{
unsigned char V_58 [ V_180 ] ;
int V_47 = 0 ;
memset ( V_58 , 0 , V_180 ) ;
switch ( V_177 -> V_187 ) {
case 0x01 :
sprintf ( V_58 , L_89 ,
& V_177 -> V_188 [ 0 ] ) ;
break;
case 0x02 :
sprintf ( V_58 , L_90 ,
& V_177 -> V_188 [ 0 ] ) ;
break;
case 0x03 :
sprintf ( V_58 , L_91 ,
& V_177 -> V_188 [ 0 ] ) ;
break;
default:
sprintf ( V_58 , L_92
L_93 , V_177 -> V_187 ) ;
V_47 = - 1 ;
break;
}
if ( V_178 )
strncpy ( V_178 , V_58 , V_179 ) ;
else
F_3 ( L_76 , V_58 ) ;
return V_47 ;
}
int
F_101 ( struct V_176 * V_177 , unsigned char * V_183 )
{
static const char V_189 [] = L_94 ;
int V_190 = 0 , V_191 = 4 ;
V_177 -> V_187 = ( V_183 [ 0 ] & 0x0f ) ;
switch ( V_177 -> V_187 ) {
case 0x01 :
V_177 -> V_188 [ V_190 ++ ] =
V_189 [ V_177 -> V_186 ] ;
while ( V_191 < ( 4 + V_183 [ 3 ] ) ) {
V_177 -> V_188 [ V_190 ++ ] =
V_189 [ ( V_183 [ V_191 ] & 0xf0 ) >> 4 ] ;
V_177 -> V_188 [ V_190 ++ ] =
V_189 [ V_183 [ V_191 ] & 0x0f ] ;
V_191 ++ ;
}
break;
case 0x02 :
case 0x03 :
while ( V_191 < ( 4 + V_183 [ 3 ] ) )
V_177 -> V_188 [ V_190 ++ ] = V_183 [ V_191 ++ ] ;
break;
default:
break;
}
return F_100 ( V_177 , NULL , 0 ) ;
}
static void F_102 ( struct V_75 * V_76 )
{
if ( F_103 ( V_76 ) -> V_192 == V_193 ) {
V_76 -> V_147 = V_194 ;
return;
}
V_76 -> V_147 = V_148 ;
F_81 ( L_95
L_96 , F_103 ( V_76 ) -> V_195 ,
F_103 ( V_76 ) -> F_104 ( V_76 ) ) ;
}
static void F_105 ( struct V_75 * V_76 )
{
struct V_196 * V_197 = F_106 ( V_76 ) ;
int V_191 , V_198 ;
F_3 ( L_97 ) ;
for ( V_191 = 0 ; V_191 < 8 ; V_191 ++ )
if ( V_197 -> V_199 [ V_191 ] >= 0x20 )
F_3 ( L_98 , V_197 -> V_199 [ V_191 ] ) ;
else
F_3 ( L_99 ) ;
F_3 ( L_100 ) ;
for ( V_191 = 0 ; V_191 < 16 ; V_191 ++ )
if ( V_197 -> V_200 [ V_191 ] >= 0x20 )
F_3 ( L_98 , V_197 -> V_200 [ V_191 ] ) ;
else
F_3 ( L_99 ) ;
F_3 ( L_101 ) ;
for ( V_191 = 0 ; V_191 < 4 ; V_191 ++ )
if ( V_197 -> V_201 [ V_191 ] >= 0x20 )
F_3 ( L_98 , V_197 -> V_201 [ V_191 ] ) ;
else
F_3 ( L_99 ) ;
F_3 ( L_102 ) ;
V_198 = F_103 ( V_76 ) -> F_107 ( V_76 ) ;
F_3 ( L_103 , F_108 ( V_198 ) ) ;
F_3 ( L_104 ,
F_103 ( V_76 ) -> F_104 ( V_76 ) ) ;
}
struct V_75 * F_109 (
struct V_202 * V_203 ,
struct V_204 * V_129 ,
struct V_205 * V_79 ,
T_1 V_206 ,
void * V_207 ,
struct V_208 * V_209 ,
const char * V_210 ,
const char * V_211 )
{
int V_212 ;
struct V_75 * V_76 ;
V_76 = F_2 ( sizeof( struct V_75 ) , V_3 ) ;
if ( ! ( V_76 ) ) {
F_3 ( V_4 L_105 ) ;
return NULL ;
}
V_76 -> V_104 = F_2 ( sizeof( struct V_41 ) , V_3 ) ;
if ( ! ( V_76 -> V_104 ) ) {
F_3 ( V_4 L_42
L_106 ) ;
F_9 ( V_76 ) ;
return NULL ;
}
F_15 ( V_76 -> V_104 ) ;
V_76 -> V_213 = F_2 ( sizeof( struct V_41 ) ,
V_3 ) ;
if ( ! ( V_76 -> V_213 ) ) {
F_3 ( V_4 L_42
L_107 ) ;
F_9 ( V_76 -> V_104 ) ;
F_9 ( V_76 ) ;
return NULL ;
}
F_15 ( V_76 -> V_213 ) ;
V_76 -> V_214 = V_206 ;
V_76 -> V_166 |= V_168 ;
V_76 -> V_215 = ( void * ) V_207 ;
V_76 -> V_202 = V_203 ;
V_76 -> V_216 = V_79 ;
V_76 -> V_129 = V_129 ;
F_16 ( & V_76 -> V_217 , 0 ) ;
F_4 ( & V_76 -> V_218 ) ;
F_4 ( & V_76 -> V_219 ) ;
F_4 ( & V_76 -> V_220 ) ;
F_4 ( & V_76 -> V_150 ) ;
F_4 ( & V_76 -> V_221 ) ;
F_4 ( & V_76 -> V_222 ) ;
F_4 ( & V_76 -> V_157 ) ;
F_5 ( & V_76 -> V_82 ) ;
F_5 ( & V_76 -> V_223 ) ;
F_5 ( & V_76 -> V_224 ) ;
F_5 ( & V_76 -> V_225 ) ;
F_5 ( & V_76 -> V_226 ) ;
F_5 ( & V_76 -> V_227 ) ;
F_5 ( & V_76 -> V_228 ) ;
F_5 ( & V_76 -> V_229 ) ;
F_5 ( & V_76 -> V_230 ) ;
F_5 ( & V_76 -> V_231 ) ;
V_76 -> V_172 = V_209 -> V_172 ;
F_16 ( & V_76 -> V_127 , V_76 -> V_172 ) ;
F_16 ( & V_76 -> V_232 , 0 ) ;
F_110 ( V_76 , V_209 ) ;
V_76 -> V_233 = F_12 ( V_234 ) ;
V_76 -> V_235 = F_111 () ;
F_5 ( & V_76 -> V_236 ) ;
F_13 ( & V_203 -> V_237 ) ;
F_28 ( & V_76 -> V_218 , & V_203 -> V_238 ) ;
V_203 -> V_239 ++ ;
F_14 ( & V_203 -> V_237 ) ;
F_102 ( V_76 ) ;
V_212 = ( V_203 -> V_240 & V_241 ) ;
F_112 ( V_76 , V_212 ) ;
if ( F_113 ( V_76 , V_212 ) < 0 )
goto V_16;
V_76 -> V_242 = F_114 ( V_243 , V_76 ,
L_108 , F_103 ( V_76 ) -> V_195 ) ;
if ( F_115 ( V_76 -> V_242 ) ) {
F_3 ( V_4 L_109 ,
F_103 ( V_76 ) -> V_195 ) ;
goto V_16;
}
if ( F_103 ( V_76 ) -> V_192 != V_193 ) {
if ( ! ( V_210 ) || ! ( V_210 ) ) {
F_3 ( V_4 L_110
L_111 ) ;
goto V_16;
}
strncpy ( & F_106 ( V_76 ) -> V_199 [ 0 ] , L_112 , 8 ) ;
strncpy ( & F_106 ( V_76 ) -> V_200 [ 0 ] , V_210 , 16 ) ;
strncpy ( & F_106 ( V_76 ) -> V_201 [ 0 ] , V_211 , 4 ) ;
}
F_105 ( V_76 ) ;
return V_76 ;
V_16:
F_116 ( V_76 -> V_242 ) ;
F_13 ( & V_203 -> V_237 ) ;
F_36 ( & V_76 -> V_218 ) ;
V_203 -> V_239 -- ;
F_14 ( & V_203 -> V_237 ) ;
F_117 ( V_76 ) ;
F_9 ( V_76 -> V_213 ) ;
F_9 ( V_76 -> V_104 ) ;
F_9 ( V_76 ) ;
return NULL ;
}
static inline void F_118 (
unsigned char * V_244 )
{
switch ( V_244 [ 0 ] ) {
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
break;
default:
V_244 [ 1 ] &= 0x1f ;
break;
}
}
static struct V_77 *
F_119 ( struct V_15 * V_74 ,
enum V_253 V_159 )
{
struct V_77 * V_78 ;
struct V_75 * V_76 = F_64 ( V_74 ) ;
unsigned long V_68 ;
V_78 = V_76 -> V_129 -> V_254 ( V_74 ) ;
if ( ! V_78 ) {
F_3 ( V_4 L_113 ) ;
return NULL ;
}
F_4 ( & V_78 -> V_116 ) ;
F_4 ( & V_78 -> V_149 ) ;
F_4 ( & V_78 -> V_83 ) ;
F_120 ( & V_78 -> V_137 ) ;
V_78 -> V_255 = F_48 ( V_74 ) -> V_256 ++ ;
V_78 -> V_151 = V_74 ;
V_78 -> V_79 = V_76 ;
V_78 -> V_257 = V_159 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_28 ( & V_78 -> V_116 , & F_48 ( V_74 ) -> V_114 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return V_78 ;
}
void F_121 ( struct V_15 * V_74 )
{
V_74 -> V_79 = F_61 ( V_74 ) -> V_258 ;
}
void F_122 (
struct V_15 * V_74 ,
struct V_259 * V_260 ,
struct V_20 * V_49 ,
T_1 V_261 ,
int V_159 ,
int V_262 ,
unsigned char * V_263 )
{
F_4 ( & V_74 -> V_103 ) ;
F_4 ( & V_74 -> V_264 ) ;
F_4 ( & V_74 -> V_265 ) ;
V_74 -> V_266 = & V_74 -> V_267 ;
F_4 ( & F_48 ( V_74 ) -> V_114 ) ;
F_120 ( & F_48 ( V_74 ) -> V_268 ) ;
F_120 ( & F_48 ( V_74 ) -> V_93 ) ;
F_120 ( & F_48 ( V_74 ) -> V_96 ) ;
F_5 ( & F_48 ( V_74 ) -> V_87 ) ;
F_16 ( & F_48 ( V_74 ) -> V_99 , 1 ) ;
V_74 -> V_269 = V_260 ;
V_74 -> V_49 = V_49 ;
V_74 -> V_261 = V_261 ;
V_74 -> V_159 = V_159 ;
V_74 -> V_152 = V_262 ;
V_74 -> V_263 = V_263 ;
}
static int F_123 ( struct V_15 * V_74 )
{
if ( F_64 ( V_74 ) -> V_147 != V_148 )
return 0 ;
if ( V_74 -> V_152 == V_270 ) {
F_81 ( L_114
L_115 ) ;
return - 1 ;
}
V_74 -> V_271 = F_124 ( & F_64 ( V_74 ) -> V_232 ) ;
F_125 () ;
F_81 ( L_116 ,
V_74 -> V_271 , V_74 -> V_152 ,
F_103 ( V_74 -> V_79 ) -> V_195 ) ;
return 0 ;
}
void F_126 (
struct V_15 * V_15 )
{
if ( V_15 -> V_18 )
F_127 ( V_15 -> V_18 ) ;
if ( F_48 ( V_15 ) -> V_154 != F_48 ( V_15 ) -> V_272 )
F_9 ( F_48 ( V_15 ) -> V_154 ) ;
}
int F_128 (
struct V_15 * V_74 ,
unsigned char * V_244 )
{
int V_47 ;
F_118 ( V_244 ) ;
V_74 -> V_273 = & V_274 ;
F_121 ( V_74 ) ;
if ( F_129 ( V_244 ) > V_275 ) {
F_3 ( V_4 L_117
L_118 ,
F_129 ( V_244 ) , V_275 ) ;
return - 1 ;
}
if ( F_129 ( V_244 ) > sizeof( F_48 ( V_74 ) -> V_272 ) ) {
F_48 ( V_74 ) -> V_154 = F_2 ( F_129 ( V_244 ) ,
V_3 ) ;
if ( ! ( F_48 ( V_74 ) -> V_154 ) ) {
F_3 ( V_4 L_119
L_120 ,
F_129 ( V_244 ) ,
( unsigned long ) sizeof( F_48 ( V_74 ) -> V_272 ) ) ;
return - 1 ;
}
} else
F_48 ( V_74 ) -> V_154 = & F_48 ( V_74 ) -> V_272 [ 0 ] ;
memcpy ( F_48 ( V_74 ) -> V_154 , V_244 , F_129 ( V_244 ) ) ;
V_47 = F_130 ( V_74 , V_244 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( F_123 ( V_74 ) < 0 ) {
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 = V_278 ;
return - 2 ;
}
F_13 ( & V_74 -> V_95 -> V_279 ) ;
if ( V_74 -> V_95 -> V_280 )
V_74 -> V_95 -> V_280 -> V_281 . V_282 ++ ;
F_14 ( & V_74 -> V_95 -> V_279 ) ;
return 0 ;
}
int F_131 (
struct V_15 * V_74 )
{
if ( ! F_61 ( V_74 ) ) {
F_87 () ;
F_3 ( V_4 L_121 ) ;
return - 1 ;
}
F_67 ( V_74 , V_283 ) ;
return 0 ;
}
int F_132 (
struct V_15 * V_74 )
{
if ( ! F_61 ( V_74 ) ) {
F_87 () ;
F_3 ( V_4 L_121 ) ;
return - 1 ;
}
F_67 ( V_74 , V_284 ) ;
return 0 ;
}
int F_133 (
struct V_15 * V_74 )
{
if ( ! F_134 () && F_135 ( V_285 ) )
return - 1 ;
if ( F_136 ( V_74 , 1 ) != 0 )
return 0 ;
F_67 ( V_74 , V_286 ) ;
return 0 ;
}
int F_137 (
struct V_15 * V_74 )
{
V_74 -> V_273 = & V_274 ;
F_121 ( V_74 ) ;
F_67 ( V_74 , V_287 ) ;
return 0 ;
}
void F_138 (
struct V_15 * V_74 )
{
F_67 ( V_74 , V_288 ) ;
}
static int F_139 ( struct V_15 * V_74 )
{
struct V_77 * V_78 , * V_289 ;
unsigned long V_68 ;
int V_47 = 0 ;
F_140 ( L_122 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_72 (task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list) {
F_140 ( L_123 ,
V_78 -> V_255 , V_78 ) ;
if ( ! F_50 ( & V_78 -> V_290 ) &&
! F_50 ( & V_78 -> V_80 ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_68 ) ;
F_86 ( V_78 ,
V_78 -> V_79 ) ;
F_140 ( L_124 ,
V_78 -> V_255 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
continue;
}
if ( F_50 ( & V_78 -> V_80 ) ) {
F_16 ( & V_78 -> V_134 , 1 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_68 ) ;
F_140 ( L_125 ,
V_78 -> V_255 ) ;
F_141 ( & V_78 -> V_137 ) ;
F_140 ( L_126 ,
V_78 -> V_255 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_54 ( & F_48 ( V_74 ) -> V_140 ) ;
F_16 ( & V_78 -> V_80 , 0 ) ;
F_16 ( & V_78 -> V_134 , 0 ) ;
} else {
F_140 ( L_127 , V_78 -> V_255 ) ;
V_47 ++ ;
}
F_142 ( V_78 , & V_68 ) ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return V_47 ;
}
static void F_143 ( struct V_75 * V_76 )
{
unsigned long V_68 ;
F_35 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
F_68 ( & V_76 -> V_127 ) ;
F_68 ( & F_77 ( V_76 ) -> V_128 ) ;
F_39 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
}
static void F_144 (
struct V_15 * V_74 ,
struct V_75 * V_76 ,
int F_58 ,
int V_291 )
{
F_145 ( L_128
L_129 , V_74 , F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_48 ( V_74 ) -> V_154 [ 0 ] ) ;
F_145 ( L_130
L_131 ,
F_52 ( V_74 ) -> F_92 ( V_74 ) ,
V_74 -> V_86 , V_74 -> V_90 ,
V_74 -> V_124 ) ;
F_145 ( L_132
L_133
L_134
L_135 , F_48 ( V_74 ) -> V_292 ,
F_50 ( & F_48 ( V_74 ) -> V_140 ) ,
F_50 ( & F_48 ( V_74 ) -> V_293 ) ,
F_50 ( & F_48 ( V_74 ) -> V_84 ) ,
F_50 ( & F_48 ( V_74 ) -> V_92 ) ,
F_50 ( & F_48 ( V_74 ) -> V_94 ) ,
F_50 ( & F_48 ( V_74 ) -> V_294 ) ) ;
F_146 ( V_74 ) ;
if ( V_76 )
F_143 ( V_76 ) ;
if ( V_74 -> V_79 -> V_147 == V_148 )
F_147 ( V_74 ) ;
if ( F_58 ) {
F_148 ( V_74 ) ;
V_74 -> V_124 = V_295 ;
}
switch ( V_74 -> V_124 ) {
case V_143 :
V_74 -> V_277 = V_296 ;
break;
case V_297 :
V_74 -> V_277 = V_298 ;
break;
case V_299 :
V_74 -> V_277 = V_278 ;
break;
case V_300 :
V_74 -> V_277 = V_301 ;
break;
case V_302 :
if ( ! V_291 )
F_149 ( V_74 ) ;
F_52 ( V_74 ) -> F_150 ( V_74 -> V_49 ) ;
F_52 ( V_74 ) -> F_151 ( V_74 -> V_49 , 0 , 0 ) ;
goto V_303;
case V_295 :
case V_123 :
V_74 -> V_277 = V_304 ;
break;
case V_305 :
V_74 -> V_277 = V_306 ;
break;
case V_307 :
V_74 -> V_277 = V_308 ;
break;
case V_309 :
V_74 -> V_117 = V_310 ;
if ( F_152 ( V_74 ) &&
F_90 ( V_74 -> V_79 ) -> V_311 == 2 )
F_153 ( F_152 ( V_74 ) -> V_55 ,
V_74 -> V_312 , 0x2C ,
V_313 ) ;
F_52 ( V_74 ) -> F_154 ( V_74 ) ;
goto V_303;
case V_314 :
break;
default:
F_3 ( V_4 L_136 ,
F_48 ( V_74 ) -> V_154 [ 0 ] ,
V_74 -> V_124 ) ;
V_74 -> V_277 = V_296 ;
break;
}
if ( ! V_291 )
F_149 ( V_74 ) ;
else
F_155 ( V_74 ,
V_74 -> V_277 , 0 ) ;
V_303:
F_60 ( V_74 ) ;
if ( ! ( F_59 ( V_74 ) ) )
;
}
static void F_148 ( struct V_15 * V_74 )
{
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( ! ( F_50 ( & F_48 ( V_74 ) -> V_315 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return;
}
if ( F_50 ( & F_48 ( V_74 ) -> V_138 ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return;
}
F_156 ( F_50 ( & F_48 ( V_74 ) -> V_315 ) ,
& F_48 ( V_74 ) -> V_136 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
}
static void F_157 ( struct V_15 * V_74 )
{
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_315 ) > 1 ) {
int V_316 = ( F_50 ( & F_48 ( V_74 ) -> V_315 ) - 1 ) ;
F_156 ( V_316 , & F_48 ( V_74 ) -> V_136 ) ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_65 ( V_74 , 0 , 0 ) ;
}
static int
F_158 ( struct V_15 * V_74 , T_1 V_261 )
{
unsigned char * V_58 ;
V_58 = F_2 ( V_261 , V_3 ) ;
if ( ! ( V_58 ) ) {
F_3 ( V_4 L_137 ) ;
return - 1 ;
}
F_48 ( V_74 ) -> V_317 = 0 ;
F_48 ( V_74 ) -> V_318 = V_58 ;
return 0 ;
}
static inline T_1 F_159 ( unsigned char * V_244 )
{
return ( ( V_244 [ 1 ] & 0x1f ) << 16 ) | ( V_244 [ 2 ] << 8 ) | V_244 [ 3 ] ;
}
static inline T_1 F_160 ( unsigned char * V_244 )
{
return ( V_244 [ 2 ] << 24 ) | ( V_244 [ 3 ] << 16 ) | ( V_244 [ 4 ] << 8 ) | V_244 [ 5 ] ;
}
static inline unsigned long long F_161 ( unsigned char * V_244 )
{
unsigned int V_319 , V_320 ;
V_319 = ( V_244 [ 2 ] << 24 ) | ( V_244 [ 3 ] << 16 ) | ( V_244 [ 4 ] << 8 ) | V_244 [ 5 ] ;
V_320 = ( V_244 [ 6 ] << 24 ) | ( V_244 [ 7 ] << 16 ) | ( V_244 [ 8 ] << 8 ) | V_244 [ 9 ] ;
return ( ( unsigned long long ) V_320 ) | ( unsigned long long ) V_319 << 32 ;
}
static inline unsigned long long F_162 ( unsigned char * V_244 )
{
unsigned int V_319 , V_320 ;
V_319 = ( V_244 [ 12 ] << 24 ) | ( V_244 [ 13 ] << 16 ) | ( V_244 [ 14 ] << 8 ) | V_244 [ 15 ] ;
V_320 = ( V_244 [ 16 ] << 24 ) | ( V_244 [ 17 ] << 16 ) | ( V_244 [ 18 ] << 8 ) | V_244 [ 19 ] ;
return ( ( unsigned long long ) V_320 ) | ( unsigned long long ) V_319 << 32 ;
}
static void F_163 ( struct V_15 * V_15 )
{
unsigned long V_68 ;
F_35 ( & F_48 ( V_15 ) -> V_87 , V_68 ) ;
V_15 -> V_131 |= V_321 ;
F_39 ( & F_48 ( V_15 ) -> V_87 , V_68 ) ;
}
static void F_164 ( unsigned long V_322 )
{
struct V_77 * V_78 = (struct V_77 * ) V_322 ;
struct V_15 * V_74 = F_75 ( V_78 ) ;
unsigned long V_68 ;
F_165 ( L_138 , V_78 , V_74 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( V_78 -> V_323 & V_324 ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return;
}
V_78 -> V_323 &= ~ V_325 ;
if ( ! ( F_50 ( & V_78 -> V_80 ) ) ) {
F_165 ( L_139
L_140 , V_78 , V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return;
}
F_68 ( & F_48 ( V_74 ) -> V_136 ) ;
F_68 ( & F_48 ( V_74 ) -> V_315 ) ;
F_48 ( V_74 ) -> V_141 = 1 ;
F_16 ( & V_78 -> V_135 , 1 ) ;
V_78 -> V_122 = V_326 ;
V_78 -> V_119 = 1 ;
if ( F_50 ( & V_78 -> V_134 ) ) {
F_165 ( L_141
L_142 , V_78 , V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_58 ( & V_78 -> V_137 ) ;
return;
}
if ( ! ( F_78 ( & F_48 ( V_74 ) -> V_140 ) ) ) {
F_165 ( L_143
L_144 , V_78 , V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return;
}
F_165 ( L_145 ,
V_78 , V_74 ) ;
V_74 -> V_86 = V_142 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_67 ( V_74 , V_142 ) ;
}
static void F_166 ( struct V_77 * V_78 )
{
struct V_75 * V_76 = V_78 -> V_79 ;
int V_327 ;
if ( V_78 -> V_323 & V_325 )
return;
V_327 = F_90 ( V_76 ) -> V_135 ;
if ( ! ( V_327 ) )
return;
F_167 ( & V_78 -> V_328 ) ;
V_78 -> V_328 . V_329 = ( F_111 () + V_327 * V_330 ) ;
V_78 -> V_328 . V_322 = ( unsigned long ) V_78 ;
V_78 -> V_328 . V_331 = F_164 ;
V_78 -> V_323 |= V_325 ;
F_168 ( & V_78 -> V_328 ) ;
#if 0
printk(KERN_INFO "Starting task timer for cmd: %p task: %p seconds:"
" %d\n", task->task_se_cmd, task, timeout);
#endif
}
void F_142 ( struct V_77 * V_78 , unsigned long * V_68 )
{
struct V_15 * V_74 = F_75 ( V_78 ) ;
if ( ! ( V_78 -> V_323 & V_325 ) )
return;
V_78 -> V_323 |= V_324 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , * V_68 ) ;
F_169 ( & V_78 -> V_328 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , * V_68 ) ;
V_78 -> V_323 &= ~ V_325 ;
V_78 -> V_323 &= ~ V_324 ;
}
static void F_146 ( struct V_15 * V_74 )
{
struct V_77 * V_78 = NULL , * V_289 ;
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_72 (task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list)
F_142 ( V_78 , & V_68 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
}
static inline int F_170 ( struct V_75 * V_76 )
{
if ( V_76 -> V_332 ++ <
V_333 ) {
F_171 ( V_334 ) ;
} else
F_171 ( V_335 ) ;
F_69 ( & V_76 -> V_104 -> V_45 ) ;
return 0 ;
}
static inline int F_172 ( struct V_15 * V_74 )
{
if ( F_64 ( V_74 ) -> V_147 != V_148 )
return 1 ;
if ( V_74 -> V_152 == V_153 ) {
F_68 ( & F_64 ( V_74 ) -> V_336 ) ;
F_125 () ;
F_81 ( L_146
L_147 ,
F_48 ( V_74 ) -> V_154 [ 0 ] ,
V_74 -> V_271 ) ;
return 1 ;
} else if ( V_74 -> V_152 == V_337 ) {
F_13 ( & F_64 ( V_74 ) -> V_224 ) ;
F_28 ( & V_74 -> V_265 ,
& F_64 ( V_74 ) -> V_222 ) ;
F_14 ( & F_64 ( V_74 ) -> V_224 ) ;
F_68 ( & F_64 ( V_74 ) -> V_338 ) ;
F_125 () ;
F_81 ( L_148
L_149 ,
F_48 ( V_74 ) -> V_154 [ 0 ] ,
V_74 -> V_271 ) ;
if ( ! ( F_50 ( & F_64 ( V_74 ) -> V_339 ) ) )
return 1 ;
} else {
F_68 ( & F_64 ( V_74 ) -> V_339 ) ;
F_125 () ;
}
if ( F_50 ( & F_64 ( V_74 ) -> V_338 ) != 0 ) {
F_13 ( & F_64 ( V_74 ) -> V_223 ) ;
V_74 -> V_131 |= V_340 ;
F_28 ( & V_74 -> V_264 ,
& F_64 ( V_74 ) -> V_221 ) ;
F_14 ( & F_64 ( V_74 ) -> V_223 ) ;
F_81 ( L_150
L_151 ,
F_48 ( V_74 ) -> V_154 [ 0 ] , V_74 -> V_152 ,
V_74 -> V_271 ) ;
return 0 ;
}
return 1 ;
}
static int F_173 ( struct V_15 * V_74 )
{
int V_341 ;
if ( ! ( V_74 -> V_131 & V_342 ) ) {
if ( F_174 ( V_74 -> V_343 ) != 0 ) {
V_74 -> V_124 =
V_295 ;
F_144 ( V_74 , NULL , 0 , 1 ) ;
return 0 ;
}
}
if ( ! ( F_55 ( V_74 , 0 , V_344 ) ) ) {
V_341 = F_172 ( V_74 ) ;
if ( V_341 == 0 )
goto V_156;
F_84 ( V_74 ) ;
}
V_156:
F_175 ( F_64 ( V_74 ) ) ;
return 0 ;
}
static int F_175 ( struct V_75 * V_76 )
{
int error ;
struct V_15 * V_74 = NULL ;
struct V_77 * V_78 ;
unsigned long V_68 ;
V_345:
F_35 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
if ( ! ( F_50 ( & V_76 -> V_127 ) ) ||
! ( F_50 ( & F_77 ( V_76 ) -> V_128 ) ) ) {
F_39 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
return F_170 ( V_76 ) ;
}
V_76 -> V_332 = 0 ;
F_13 ( & V_76 -> V_82 ) ;
V_78 = F_85 ( V_76 ) ;
F_14 ( & V_76 -> V_82 ) ;
if ( ! V_78 ) {
F_39 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
return 0 ;
}
F_54 ( & V_76 -> V_127 ) ;
F_54 ( & F_77 ( V_76 ) -> V_128 ) ;
F_39 ( & F_77 ( V_76 ) -> V_126 , V_68 ) ;
V_74 = F_75 ( V_78 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_16 ( & V_78 -> V_80 , 1 ) ;
F_16 ( & V_78 -> V_290 , 1 ) ;
F_68 ( & F_48 ( V_74 ) -> V_293 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_293 ) ==
F_48 ( V_74 ) -> V_292 )
F_16 ( & V_74 -> V_346 , 1 ) ;
F_166 ( V_78 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( V_74 -> V_347 ) {
error = V_74 -> V_347 ( V_74 ) ;
if ( error != 0 ) {
V_74 -> V_124 = error ;
F_16 ( & V_78 -> V_80 , 0 ) ;
F_16 ( & V_74 -> V_346 , 0 ) ;
F_139 ( V_74 ) ;
F_144 ( V_74 , V_76 , 0 , 1 ) ;
goto V_345;
}
if ( ! ( V_74 -> V_131 & V_348 ) ) {
V_74 -> V_117 = V_118 ;
V_78 -> V_119 = V_120 ;
F_76 ( V_78 , 1 ) ;
}
} else {
if ( ( F_103 ( V_76 ) -> V_192 != V_193 ) &&
( ! ( F_75 ( V_78 ) -> V_131 & V_349 ) ) )
error = F_176 ( V_78 ) ;
else
error = F_103 ( V_76 ) -> F_177 ( V_78 ) ;
if ( error != 0 ) {
V_74 -> V_124 = error ;
F_16 ( & V_78 -> V_80 , 0 ) ;
F_16 ( & V_74 -> V_346 , 0 ) ;
F_139 ( V_74 ) ;
F_144 ( V_74 , V_76 , 0 , 1 ) ;
}
}
goto V_345;
return 0 ;
}
void F_149 ( struct V_15 * V_15 )
{
unsigned long V_68 ;
F_35 ( & F_48 ( V_15 ) -> V_87 , V_68 ) ;
V_15 -> V_131 |= V_350 ;
V_15 -> V_131 |= V_276 ;
F_39 ( & F_48 ( V_15 ) -> V_87 , V_68 ) ;
F_52 ( V_15 ) -> F_178 ( V_15 ) ;
}
static inline T_1 F_179 (
unsigned char * V_244 ,
struct V_15 * V_74 ,
int * V_47 )
{
struct V_75 * V_76 = F_61 ( V_74 ) -> V_258 ;
if ( ! V_76 )
goto V_351;
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) == V_352 )
return ( T_1 ) ( V_244 [ 2 ] << 16 ) + ( V_244 [ 3 ] << 8 ) + V_244 [ 4 ] ;
V_351:
return ( T_1 ) V_244 [ 4 ] ;
}
static inline T_1 F_180 (
unsigned char * V_244 ,
struct V_15 * V_74 ,
int * V_47 )
{
struct V_75 * V_76 = F_61 ( V_74 ) -> V_258 ;
if ( ! V_76 )
goto V_351;
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) == V_352 ) {
* V_47 = - 1 ;
return 0 ;
}
V_351:
return ( T_1 ) ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
}
static inline T_1 F_181 (
unsigned char * V_244 ,
struct V_15 * V_74 ,
int * V_47 )
{
struct V_75 * V_76 = F_61 ( V_74 ) -> V_258 ;
if ( ! V_76 )
goto V_351;
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) == V_352 ) {
* V_47 = - 1 ;
return 0 ;
}
V_351:
return ( T_1 ) ( V_244 [ 6 ] << 24 ) + ( V_244 [ 7 ] << 16 ) + ( V_244 [ 8 ] << 8 ) + V_244 [ 9 ] ;
}
static inline T_1 F_182 (
unsigned char * V_244 ,
struct V_15 * V_74 ,
int * V_47 )
{
struct V_75 * V_76 = F_61 ( V_74 ) -> V_258 ;
if ( ! V_76 )
goto V_351;
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) == V_352 )
return ( T_1 ) ( V_244 [ 12 ] << 16 ) + ( V_244 [ 13 ] << 8 ) + V_244 [ 14 ] ;
V_351:
return ( T_1 ) ( V_244 [ 10 ] << 24 ) + ( V_244 [ 11 ] << 16 ) +
( V_244 [ 12 ] << 8 ) + V_244 [ 13 ] ;
}
static inline T_1 F_183 (
unsigned char * V_244 ,
struct V_15 * V_74 ,
int * V_47 )
{
return ( T_1 ) ( V_244 [ 28 ] << 24 ) + ( V_244 [ 29 ] << 16 ) +
( V_244 [ 30 ] << 8 ) + V_244 [ 31 ] ;
}
static inline T_1 F_184 (
T_1 V_353 ,
unsigned char * V_244 ,
struct V_15 * V_74 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) == V_352 ) {
if ( V_244 [ 1 ] & 1 ) {
return F_90 ( V_76 ) -> V_173 * V_353 ;
} else
return V_353 ;
}
#if 0
printk(KERN_INFO "Returning block_size: %u, sectors: %u == %u for"
" %s object\n", DEV_ATTRIB(dev)->block_size, sectors,
DEV_ATTRIB(dev)->block_size * sectors,
TRANSPORT(dev)->name);
#endif
return F_90 ( V_76 ) -> V_173 * V_353 ;
}
unsigned char F_185 ( unsigned char V_354 [ 2 ] )
{
unsigned char V_355 = 0 ;
if ( ( V_354 [ 0 ] >= 'a' ) && ( V_354 [ 0 ] <= 'f' ) )
V_355 = ( ( V_354 [ 0 ] - 'a' + 10 ) & 0xf ) << 4 ;
else
if ( ( V_354 [ 0 ] >= 'A' ) && ( V_354 [ 0 ] <= 'F' ) )
V_355 = ( ( V_354 [ 0 ] - 'A' + 10 ) & 0xf ) << 4 ;
else
V_355 = ( ( V_354 [ 0 ] - '0' ) & 0xf ) << 4 ;
if ( ( V_354 [ 1 ] >= 'a' ) && ( V_354 [ 1 ] <= 'f' ) )
V_355 |= ( ( V_354 [ 1 ] - 'a' + 10 ) & 0xf ) ;
else
if ( ( V_354 [ 1 ] >= 'A' ) && ( V_354 [ 1 ] <= 'F' ) )
V_355 |= ( ( V_354 [ 1 ] - 'A' + 10 ) & 0xf ) ;
else
V_355 |= ( ( V_354 [ 1 ] - '0' ) & 0xf ) ;
return V_355 ;
}
static void F_186 ( struct V_15 * V_74 )
{
unsigned char * V_58 , * V_356 ;
struct V_24 * V_24 ;
unsigned int V_357 ;
int V_191 ;
V_58 = F_187 ( V_74 -> V_261 , V_3 ) ;
if ( ! ( V_58 ) ) {
F_3 ( V_4 L_152 ) ;
return;
}
F_188 ( V_74 , V_58 , F_48 ( V_74 ) -> V_358 ) ;
V_357 = 0 ;
F_49 (se_mem, T_TASK(cmd)->t_mem_bidi_list, se_list) {
V_356 = ( unsigned char * ) F_189 ( V_24 -> V_359 , V_360 ) ;
if ( ! ( V_356 ) )
goto V_16;
for ( V_191 = 0 ; V_191 < V_24 -> V_361 ; V_191 ++ )
* ( V_356 + V_24 -> V_362 + V_191 ) ^= * ( V_58 + V_357 + V_191 ) ;
V_357 += V_24 -> V_361 ;
F_190 ( V_356 , V_360 ) ;
}
V_16:
F_9 ( V_58 ) ;
}
static int F_191 ( struct V_15 * V_74 )
{
unsigned char * V_363 = V_74 -> V_263 , * V_263 = NULL ;
struct V_75 * V_76 ;
struct V_77 * V_78 = NULL , * V_289 ;
unsigned long V_68 ;
T_1 V_357 = 0 ;
if ( ! F_61 ( V_74 ) ) {
F_3 ( V_4 L_121 ) ;
return - 1 ;
}
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( V_74 -> V_131 & V_364 ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return 0 ;
}
F_72 (task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list) {
if ( ! V_78 -> V_133 )
continue;
V_76 = V_78 -> V_79 ;
if ( ! ( V_76 ) )
continue;
if ( ! F_103 ( V_76 ) -> V_365 ) {
F_3 ( V_4 L_153
L_154 ) ;
continue;
}
V_263 = F_103 ( V_76 ) -> V_365 ( V_78 ) ;
if ( ! ( V_263 ) ) {
F_3 ( V_4 L_155
L_156 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) , V_78 -> V_255 ) ;
continue;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
V_357 = F_52 ( V_74 ) -> F_192 ( V_74 ,
V_366 ) ;
memcpy ( ( void * ) & V_363 [ V_357 ] , ( void * ) V_263 ,
V_366 ) ;
V_74 -> V_117 = V_78 -> V_119 ;
V_74 -> V_367 =
( V_366 + V_357 ) ;
F_3 ( V_66 L_157
L_158 ,
V_76 -> V_202 -> V_368 , F_103 ( V_76 ) -> V_195 ,
V_74 -> V_117 ) ;
return 0 ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return - 1 ;
}
static int F_193 ( struct V_15 * V_74 )
{
T_1 V_369 = V_74 -> V_261 ;
if ( ( V_74 -> V_131 & V_349 ) ||
( V_74 -> V_131 & V_370 ) )
return F_194 ( V_74 , V_369 , V_371 ) ;
else if ( V_74 -> V_131 & V_372 )
return F_158 ( V_74 , V_369 ) ;
else
return 0 ;
}
static int
F_195 ( struct V_15 * V_74 )
{
V_74 -> V_273 = & V_373 ;
V_74 -> V_131 |= V_276 ;
V_74 -> V_131 |= V_374 ;
V_74 -> V_117 = V_310 ;
if ( F_152 ( V_74 ) &&
F_90 ( V_74 -> V_79 ) -> V_311 == 2 )
F_153 ( F_152 ( V_74 ) -> V_55 ,
V_74 -> V_312 , 0x2C ,
V_313 ) ;
return - 2 ;
}
static int F_130 (
struct V_15 * V_74 ,
unsigned char * V_244 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
struct V_205 * V_375 = V_76 -> V_216 ;
int V_47 = 0 , V_376 = 0 , V_377 ;
T_1 V_353 = 0 , V_378 = 0 , V_379 = 0 ;
T_4 V_380 ;
T_3 V_381 = 0 ;
if ( F_196 ( V_74 , V_244 ) < 0 ) {
V_74 -> V_273 =
& V_373 ;
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 = V_382 ;
return - 2 ;
}
V_47 = F_197 ( V_375 ) -> F_198 ( V_74 , V_244 , & V_381 ) ;
if ( V_47 != 0 ) {
V_74 -> V_273 = & V_373 ;
if ( V_47 > 0 ) {
#if 0
printk(KERN_INFO "[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
CMD_TFO(cmd)->get_fabric_name(), alua_ascq);
#endif
F_199 ( V_74 , 0x04 , V_381 ) ;
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 = V_383 ;
return - 2 ;
}
goto V_384;
}
if ( F_200 ( V_375 ) -> F_201 ( V_74 , & V_379 ) != 0 ) {
if ( F_200 ( V_375 ) -> F_202 (
V_74 , V_244 , V_379 ) != 0 )
return F_195 ( V_74 ) ;
}
switch ( V_244 [ 0 ] ) {
case V_385 :
V_353 = F_179 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_388 ;
F_48 ( V_74 ) -> V_389 = F_159 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_245 :
V_353 = F_180 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_390 ;
F_48 ( V_74 ) -> V_389 = F_160 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_246 :
V_353 = F_181 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_391 ;
F_48 ( V_74 ) -> V_389 = F_160 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_247 :
V_353 = F_182 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_392 ;
F_48 ( V_74 ) -> V_389 = F_161 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_393 :
V_353 = F_179 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_388 ;
F_48 ( V_74 ) -> V_389 = F_159 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_394 :
V_353 = F_180 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_390 ;
F_48 ( V_74 ) -> V_389 = F_160 ( V_244 ) ;
F_48 ( V_74 ) -> V_395 = ( V_244 [ 1 ] & 0x8 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_396 :
V_353 = F_181 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_391 ;
F_48 ( V_74 ) -> V_389 = F_160 ( V_244 ) ;
F_48 ( V_74 ) -> V_395 = ( V_244 [ 1 ] & 0x8 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_397 :
V_353 = F_182 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_392 ;
F_48 ( V_74 ) -> V_389 = F_161 ( V_244 ) ;
F_48 ( V_74 ) -> V_395 = ( V_244 [ 1 ] & 0x8 ) ;
V_74 -> V_131 |= V_349 ;
break;
case V_398 :
if ( ( V_74 -> V_159 != V_162 ) ||
! ( F_48 ( V_74 ) -> V_399 ) )
goto V_384;
V_353 = F_180 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_390 ;
F_48 ( V_74 ) -> V_389 = F_160 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
V_377 = ( F_103 ( V_76 ) -> V_192 ==
V_193 ) ;
if ( V_377 )
break;
V_74 -> V_400 = & F_186 ;
F_48 ( V_74 ) -> V_395 = ( V_244 [ 1 ] & 0x8 ) ;
break;
case V_401 :
V_380 = F_203 ( & V_244 [ 8 ] ) ;
V_377 = ( F_103 ( V_76 ) -> V_192 ==
V_193 ) ;
switch ( V_380 ) {
case V_402 :
V_353 = F_183 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_387 = & V_403 ;
F_48 ( V_74 ) -> V_389 = F_162 ( V_244 ) ;
V_74 -> V_131 |= V_349 ;
if ( V_377 )
break;
V_74 -> V_400 = & F_186 ;
F_48 ( V_74 ) -> V_395 = ( V_244 [ 10 ] & 0x8 ) ;
break;
case V_404 :
V_353 = F_183 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
F_48 ( V_74 ) -> V_389 = F_26 ( & V_244 [ 12 ] ) ;
V_74 -> V_131 |= V_370 ;
if ( V_377 )
break;
if ( ( V_244 [ 10 ] & 0x04 ) || ( V_244 [ 10 ] & 0x02 ) ) {
F_3 ( V_4 L_159
L_160
L_161 ) ;
goto V_384;
}
if ( ! ( V_244 [ 10 ] & 0x08 ) ) {
F_3 ( V_4 L_162
L_163 ) ;
goto V_384;
}
break;
default:
F_3 ( V_4 L_164
L_165 , V_380 ) ;
goto V_386;
}
break;
case 0xa3 :
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) != V_405 ) {
if ( V_244 [ 1 ] == V_406 ) {
V_74 -> V_347 =
( F_197 ( V_375 ) -> V_407 ==
V_408 ) ?
& V_409 :
NULL ;
}
V_378 = ( V_244 [ 6 ] << 24 ) | ( V_244 [ 7 ] << 16 ) |
( V_244 [ 8 ] << 8 ) | V_244 [ 9 ] ;
} else {
V_378 = ( V_244 [ 8 ] << 8 ) + V_244 [ 9 ] ;
}
V_74 -> V_131 |= V_372 ;
break;
case V_410 :
V_378 = V_244 [ 4 ] ;
V_74 -> V_131 |= V_370 ;
break;
case V_411 :
V_378 = ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
V_74 -> V_131 |= V_370 ;
break;
case V_412 :
V_378 = V_244 [ 4 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
V_378 = ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_418 :
V_378 = V_419 ;
V_74 -> V_131 |= V_372 ;
break;
case V_420 :
case V_421 :
case V_422 :
case V_423 :
V_378 = ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
V_74 -> V_131 |= V_370 ;
break;
case V_424 :
case V_425 :
V_74 -> V_347 =
( F_204 ( V_375 ) -> V_426 ==
V_427 ) ?
& V_428 : NULL ;
V_378 = ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_429 :
case V_430 :
V_378 = ( V_244 [ 8 ] << 8 ) + V_244 [ 9 ] ;
V_74 -> V_131 |= V_370 ;
break;
case V_431 :
V_378 = V_432 ;
V_74 -> V_131 |= V_372 ;
break;
case 0xa4 :
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) != V_405 ) {
if ( V_244 [ 1 ] == V_433 ) {
V_74 -> V_347 =
( F_197 ( V_375 ) -> V_407 ==
V_408 ) ?
& V_434 :
NULL ;
}
V_378 = ( V_244 [ 6 ] << 24 ) | ( V_244 [ 7 ] << 16 ) |
( V_244 [ 8 ] << 8 ) | V_244 [ 9 ] ;
} else {
V_378 = ( V_244 [ 8 ] << 8 ) + V_244 [ 9 ] ;
}
V_74 -> V_131 |= V_372 ;
break;
case V_435 :
V_378 = ( V_244 [ 3 ] << 8 ) + V_244 [ 4 ] ;
if ( F_64 ( V_74 ) -> V_147 == V_148 )
V_74 -> V_152 = V_153 ;
V_74 -> V_131 |= V_372 ;
break;
case V_436 :
V_378 = ( V_244 [ 6 ] << 16 ) + ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_437 :
V_378 = V_438 ;
V_74 -> V_131 |= V_372 ;
break;
case V_439 :
case V_440 :
case V_441 :
V_378 = ( V_244 [ 6 ] << 24 ) | ( V_244 [ 7 ] << 16 ) | ( V_244 [ 8 ] << 8 ) | V_244 [ 9 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
V_378 = ( V_244 [ 10 ] << 24 ) | ( V_244 [ 11 ] << 16 ) |
( V_244 [ 12 ] << 8 ) | V_244 [ 13 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_449 :
case V_248 :
V_378 = ( V_244 [ 3 ] << 8 ) | V_244 [ 4 ] ;
V_74 -> V_131 |= V_372 ;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
#endif
case V_450 :
V_378 = V_244 [ 8 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_451 :
V_378 = V_244 [ 4 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_452 :
V_378 = 65536 * V_244 [ 7 ] + 256 * V_244 [ 8 ] + V_244 [ 9 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_453 :
V_378 = ( V_244 [ 6 ] << 16 ) + ( V_244 [ 7 ] << 8 ) + V_244 [ 8 ] ;
V_74 -> V_131 |= V_372 ;
break;
case V_454 :
case V_455 :
if ( V_244 [ 0 ] == V_455 )
V_378 = ( V_244 [ 7 ] << 8 ) | V_244 [ 8 ] ;
else
V_378 = V_74 -> V_261 ;
V_74 -> V_347 =
( F_204 ( V_375 ) -> V_426 !=
V_456 ) ?
& V_457 : NULL ;
V_74 -> V_131 |= V_458 ;
break;
case V_459 :
case V_460 :
if ( V_244 [ 0 ] == V_460 )
V_378 = ( V_244 [ 7 ] << 8 ) | V_244 [ 8 ] ;
else
V_378 = V_74 -> V_261 ;
V_74 -> V_347 =
( F_204 ( V_375 ) -> V_426 !=
V_456 ) ?
& V_457 : NULL ;
V_74 -> V_131 |= V_458 ;
break;
case V_461 :
case 0x91 :
if ( V_244 [ 0 ] == V_461 ) {
V_353 = F_180 ( V_244 , V_74 , & V_376 ) ;
F_48 ( V_74 ) -> V_389 = F_160 ( V_244 ) ;
} else {
V_353 = F_182 ( V_244 , V_74 , & V_376 ) ;
F_48 ( V_74 ) -> V_389 = F_161 ( V_244 ) ;
}
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
V_74 -> V_131 |= V_458 ;
if ( F_103 ( V_76 ) -> V_192 == V_193 )
break;
V_74 -> V_131 |= V_348 ;
if ( F_205 ( V_74 ) < 0 )
goto V_384;
break;
case V_462 :
V_378 = F_203 ( & V_244 [ 7 ] ) ;
V_377 = ( F_103 ( V_76 ) -> V_192 ==
V_193 ) ;
if ( ! ( V_377 ) )
V_74 -> V_131 |= V_463 ;
V_74 -> V_131 |= V_372 ;
break;
case V_464 :
V_353 = F_182 ( V_244 , V_74 , & V_376 ) ;
if ( V_376 )
goto V_386;
V_378 = F_184 ( V_353 , V_244 , V_74 ) ;
F_48 ( V_74 ) -> V_389 = F_203 ( & V_244 [ 2 ] ) ;
V_377 = ( F_103 ( V_76 ) -> V_192 ==
V_193 ) ;
if ( ! ( V_377 ) ) {
if ( ( V_244 [ 1 ] & 0x04 ) || ( V_244 [ 1 ] & 0x02 ) ) {
F_3 ( V_4 L_159
L_160
L_161 ) ;
goto V_384;
}
if ( ! ( V_244 [ 1 ] & 0x08 ) ) {
F_3 ( V_4 L_166
L_163 ) ;
goto V_384;
}
}
V_74 -> V_131 |= V_370 ;
break;
case V_465 :
case V_466 :
case V_467 :
case V_468 :
case V_469 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_249 :
case V_476 :
case V_477 :
V_74 -> V_131 |= V_458 ;
break;
case V_478 :
V_74 -> V_347 =
& V_479 ;
V_378 = ( V_244 [ 6 ] << 24 ) | ( V_244 [ 7 ] << 16 ) | ( V_244 [ 8 ] << 8 ) | V_244 [ 9 ] ;
if ( F_64 ( V_74 ) -> V_147 == V_148 )
V_74 -> V_152 = V_153 ;
V_74 -> V_131 |= V_372 ;
break;
default:
F_3 ( V_480 L_167
L_168 ,
F_52 ( V_74 ) -> F_30 () , V_244 [ 0 ] ) ;
V_74 -> V_273 = & V_373 ;
goto V_386;
}
if ( V_378 != V_74 -> V_261 ) {
F_3 ( V_480 L_169
L_170
L_171 , F_52 ( V_74 ) -> F_30 () ,
V_74 -> V_261 , V_378 , V_244 [ 0 ] ) ;
V_74 -> V_481 = V_378 ;
if ( V_74 -> V_159 == V_162 ) {
F_3 ( V_4 L_172
L_173 ) ;
goto V_384;
}
if ( ! ( V_47 ) && ( F_90 ( V_76 ) -> V_173 != 512 ) ) {
F_3 ( V_4 L_174
L_175
L_176 , F_103 ( V_76 ) -> V_195 ) ;
goto V_384;
}
if ( V_378 > V_74 -> V_261 ) {
V_74 -> V_131 |= V_482 ;
V_74 -> V_483 = ( V_378 - V_74 -> V_261 ) ;
} else {
V_74 -> V_131 |= V_484 ;
V_74 -> V_483 = ( V_74 -> V_261 - V_378 ) ;
}
V_74 -> V_261 = V_378 ;
}
F_163 ( V_74 ) ;
return V_47 ;
V_386:
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 = V_296 ;
return - 2 ;
V_384:
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 = V_278 ;
return - 2 ;
}
static void F_206 (
struct V_15 * V_74 ,
struct V_485 * V_486 ,
unsigned char * V_487 )
{
T_1 V_191 = 0 , V_369 = 0 , V_488 = V_74 -> V_261 ;
void * V_489 ;
while ( V_488 ) {
V_369 = V_486 [ V_191 ] . V_369 ;
if ( V_369 > V_488 )
V_369 = V_488 ;
V_489 = F_207 ( & V_486 [ V_191 ] ) ;
memcpy ( V_489 , V_487 , V_369 ) ;
if ( ! ( V_488 -= V_369 ) )
return;
V_487 += V_369 ;
V_191 ++ ;
}
}
static void F_208 (
struct V_15 * V_74 ,
unsigned char * V_489 ,
struct V_485 * V_490 )
{
T_1 V_191 = 0 , V_369 = 0 , V_488 = V_74 -> V_261 ;
void * V_487 ;
while ( V_488 ) {
V_369 = V_490 [ V_191 ] . V_369 ;
if ( V_369 > V_488 )
V_369 = V_488 ;
V_487 = F_207 ( & V_490 [ V_191 ] ) ;
memcpy ( V_489 , V_487 , V_369 ) ;
if ( ! ( V_488 -= V_369 ) )
return;
V_489 += V_369 ;
V_191 ++ ;
}
}
static void F_188 (
struct V_15 * V_74 ,
unsigned char * V_489 ,
struct V_491 * V_492 )
{
struct V_24 * V_24 ;
void * V_487 ;
T_1 V_369 = 0 , V_488 = V_74 -> V_261 ;
F_49 (se_mem, se_mem_list, se_list) {
V_369 = V_24 -> V_361 ;
if ( V_369 > V_488 )
V_369 = V_488 ;
V_487 = F_209 ( V_24 -> V_359 ) + V_24 -> V_362 ;
memcpy ( V_489 , V_487 , V_369 ) ;
if ( ! ( V_488 -= V_369 ) )
return;
V_489 += V_369 ;
}
}
static void F_147 ( struct V_15 * V_74 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
struct V_15 * V_493 , * V_494 ;
int V_495 = 0 ;
if ( V_74 -> V_152 == V_496 ) {
F_54 ( & V_76 -> V_339 ) ;
F_210 () ;
V_76 -> V_497 ++ ;
F_81 ( L_177
L_178 , V_76 -> V_497 ,
V_74 -> V_271 ) ;
} else if ( V_74 -> V_152 == V_153 ) {
F_54 ( & V_76 -> V_336 ) ;
F_210 () ;
V_76 -> V_497 ++ ;
F_81 ( L_179
L_180 , V_76 -> V_497 ,
V_74 -> V_271 ) ;
} else if ( V_74 -> V_152 == V_337 ) {
F_13 ( & V_76 -> V_224 ) ;
F_36 ( & V_74 -> V_265 ) ;
F_54 ( & V_76 -> V_338 ) ;
F_210 () ;
F_14 ( & V_76 -> V_224 ) ;
V_76 -> V_497 ++ ;
F_81 ( L_181
L_182 , V_76 -> V_497 , V_74 -> V_271 ) ;
}
F_13 ( & V_76 -> V_223 ) ;
F_72 (cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_list) {
F_36 ( & V_493 -> V_264 ) ;
F_14 ( & V_76 -> V_223 ) ;
F_81 ( L_183
L_184
L_185 ,
F_48 ( V_493 ) -> V_154 [ 0 ] ,
V_493 -> V_152 , V_493 -> V_271 ) ;
F_84 ( V_493 ) ;
V_495 ++ ;
F_13 ( & V_76 -> V_223 ) ;
if ( V_493 -> V_152 == V_337 )
break;
}
F_14 ( & V_76 -> V_223 ) ;
if ( V_495 != 0 )
F_69 ( & V_76 -> V_104 -> V_45 ) ;
}
static void F_211 ( struct V_15 * V_74 )
{
int V_498 = 0 ;
if ( F_64 ( V_74 ) -> V_147 == V_148 )
F_147 ( V_74 ) ;
if ( V_74 -> V_131 & V_132 ) {
if ( F_191 ( V_74 ) < 0 )
V_498 = V_499 ;
if ( V_74 -> V_117 ) {
F_155 (
V_74 , V_498 , 1 ) ;
F_60 ( V_74 ) ;
F_59 ( V_74 ) ;
return;
}
}
if ( V_74 -> V_400 )
V_74 -> V_400 ( V_74 ) ;
switch ( V_74 -> V_159 ) {
case V_161 :
F_13 ( & V_74 -> V_95 -> V_279 ) ;
if ( F_61 ( V_74 ) -> V_280 ) {
F_61 ( V_74 ) -> V_280 -> V_281 . V_500 +=
V_74 -> V_261 ;
}
F_14 ( & V_74 -> V_95 -> V_279 ) ;
if ( V_74 -> V_131 & V_501 )
F_206 ( V_74 ,
F_48 ( V_74 ) -> V_502 ,
F_48 ( V_74 ) -> V_318 ) ;
F_52 ( V_74 ) -> F_212 ( V_74 ) ;
break;
case V_162 :
F_13 ( & V_74 -> V_95 -> V_279 ) ;
if ( F_61 ( V_74 ) -> V_280 ) {
F_61 ( V_74 ) -> V_280 -> V_281 . V_503 +=
V_74 -> V_261 ;
}
F_14 ( & V_74 -> V_95 -> V_279 ) ;
if ( F_48 ( V_74 ) -> V_504 != NULL ) {
F_13 ( & V_74 -> V_95 -> V_279 ) ;
if ( F_61 ( V_74 ) -> V_280 ) {
F_61 ( V_74 ) -> V_280 -> V_281 . V_500 +=
V_74 -> V_261 ;
}
F_14 ( & V_74 -> V_95 -> V_279 ) ;
F_52 ( V_74 ) -> F_212 ( V_74 ) ;
break;
}
case V_160 :
F_52 ( V_74 ) -> F_154 ( V_74 ) ;
break;
default:
break;
}
F_60 ( V_74 ) ;
F_59 ( V_74 ) ;
}
static void F_213 ( struct V_15 * V_74 )
{
struct V_77 * V_78 , * V_289 ;
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_72 (task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list) {
if ( F_50 ( & V_78 -> V_80 ) )
continue;
F_9 ( V_78 -> V_505 ) ;
F_9 ( V_78 -> V_506 ) ;
F_36 ( & V_78 -> V_116 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( V_78 -> V_79 )
F_103 ( V_78 -> V_79 ) -> F_214 ( V_78 ) ;
else
F_3 ( V_4 L_186 ,
V_78 -> V_255 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
}
static inline void F_215 ( struct V_15 * V_74 )
{
struct V_24 * V_24 , * V_507 ;
int V_508 = 1 ;
if ( V_74 -> V_131 & V_509 )
V_508 = 0 ;
if ( V_74 -> V_79 -> V_129 -> V_510 )
V_508 = 0 ;
if ( F_48 ( V_74 ) -> V_318 ) {
F_9 ( F_48 ( V_74 ) -> V_318 ) ;
F_48 ( V_74 ) -> V_318 = NULL ;
return;
}
if ( V_74 -> V_131 & V_511 )
return;
if ( ! ( F_48 ( V_74 ) -> V_317 ) )
return;
F_72 (se_mem, se_mem_tmp,
T_TASK(cmd)->t_mem_list, se_list) {
if ( V_508 )
F_216 ( V_24 -> V_359 ) ;
F_36 ( & V_24 -> V_512 ) ;
F_41 ( V_23 , V_24 ) ;
}
if ( F_48 ( V_74 ) -> V_504 && F_48 ( V_74 ) -> V_513 ) {
F_72 (se_mem, se_mem_tmp,
T_TASK(cmd)->t_mem_bidi_list, se_list) {
if ( V_508 )
F_216 ( V_24 -> V_359 ) ;
F_36 ( & V_24 -> V_512 ) ;
F_41 ( V_23 , V_24 ) ;
}
}
F_9 ( F_48 ( V_74 ) -> V_504 ) ;
F_48 ( V_74 ) -> V_504 = NULL ;
F_9 ( F_48 ( V_74 ) -> V_358 ) ;
F_48 ( V_74 ) -> V_358 = NULL ;
F_48 ( V_74 ) -> V_317 = 0 ;
}
static inline void F_217 ( struct V_15 * V_74 )
{
F_213 ( V_74 ) ;
}
static inline int F_218 ( struct V_15 * V_74 )
{
unsigned long V_68 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_514 ) ) {
if ( ! ( F_78 ( & F_48 ( V_74 ) -> V_514 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_68 ) ;
return 1 ;
}
}
if ( F_50 ( & F_48 ( V_74 ) -> V_136 ) ) {
if ( ! ( F_78 ( & F_48 ( V_74 ) -> V_136 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_68 ) ;
return 1 ;
}
}
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return 0 ;
}
static void F_93 ( struct V_15 * V_74 )
{
unsigned long V_68 ;
if ( F_218 ( V_74 ) )
return;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( ! ( F_50 ( & F_48 ( V_74 ) -> V_99 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
goto V_515;
}
F_16 ( & F_48 ( V_74 ) -> V_99 , 0 ) ;
F_47 ( V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_217 ( V_74 ) ;
V_515:
F_215 ( V_74 ) ;
F_126 ( V_74 ) ;
F_52 ( V_74 ) -> F_219 ( V_74 ) ;
}
static int F_65 (
struct V_15 * V_74 ,
int V_516 ,
int V_517 )
{
unsigned long V_68 ;
if ( ! ( F_48 ( V_74 ) ) )
goto V_518;
if ( F_218 ( V_74 ) ) {
if ( V_517 ) {
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_47 ( V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_68 ) ;
}
return 1 ;
}
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( ! ( F_50 ( & F_48 ( V_74 ) -> V_99 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
goto V_515;
}
F_16 ( & F_48 ( V_74 ) -> V_99 , 0 ) ;
F_47 ( V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_217 ( V_74 ) ;
V_515:
F_215 ( V_74 ) ;
V_518:
if ( V_516 ) {
F_220 ( V_74 ) ;
} else {
F_126 ( V_74 ) ;
F_52 ( V_74 ) -> F_219 ( V_74 ) ;
}
return 0 ;
}
int F_221 (
struct V_15 * V_74 ,
struct V_485 * V_519 ,
T_1 V_520 ,
struct V_485 * V_521 ,
T_1 V_522 )
{
T_1 V_523 = 0 ;
int V_47 ;
if ( ! ( V_519 ) || ! ( V_520 ) )
return 0 ;
if ( ! ( V_74 -> V_131 & V_524 ) ) {
if ( ( V_521 ) || ( V_522 ) ) {
F_3 ( V_4 L_187
L_188 ) ;
return - V_525 ;
}
F_48 ( V_74 ) -> V_358 = (struct V_491 * ) V_519 ;
F_48 ( V_74 ) -> V_317 = V_520 ;
V_74 -> V_131 |= V_511 ;
return 0 ;
}
if ( ( V_74 -> V_131 & V_349 ) ||
( V_74 -> V_131 & V_370 ) ) {
F_48 ( V_74 ) -> V_358 = F_222 () ;
if ( ! ( F_48 ( V_74 ) -> V_358 ) )
return - V_50 ;
V_47 = F_223 ( V_74 ,
F_48 ( V_74 ) -> V_358 , V_519 , & V_523 ) ;
if ( V_47 < 0 )
return - V_50 ;
F_48 ( V_74 ) -> V_317 = V_523 ;
if ( ( V_521 ) && ( V_522 ) ) {
F_48 ( V_74 ) -> V_504 = F_222 () ;
if ( ! ( F_48 ( V_74 ) -> V_504 ) ) {
F_9 ( F_48 ( V_74 ) -> V_358 ) ;
return - V_50 ;
}
V_523 = 0 ;
V_47 = F_223 ( V_74 ,
F_48 ( V_74 ) -> V_504 , V_521 ,
& V_523 ) ;
if ( V_47 < 0 ) {
F_9 ( F_48 ( V_74 ) -> V_358 ) ;
return - V_50 ;
}
F_48 ( V_74 ) -> V_513 = V_523 ;
}
V_74 -> V_131 |= V_509 ;
} else if ( V_74 -> V_131 & V_372 ) {
if ( V_521 || V_522 ) {
F_3 ( V_4 L_189
L_190 ) ;
return - V_525 ;
}
V_74 -> V_131 |= V_501 ;
F_48 ( V_74 ) -> V_502 = V_519 ;
}
return 0 ;
}
static inline long long F_224 ( struct V_75 * V_76 )
{
return V_76 -> V_129 -> V_526 ( V_76 ) + 1 ;
}
static int F_205 ( struct V_15 * V_74 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
F_48 ( V_74 ) -> V_527 =
( V_74 -> V_261 / F_90 ( V_76 ) -> V_173 ) ;
if ( ! ( F_48 ( V_74 ) -> V_527 ) )
F_48 ( V_74 ) -> V_527 = 1 ;
if ( F_103 ( V_76 ) -> F_107 ( V_76 ) != V_528 )
return 0 ;
if ( ( F_48 ( V_74 ) -> V_389 + F_48 ( V_74 ) -> V_527 ) >
F_224 ( V_76 ) ) {
F_3 ( V_4 L_191
L_192 ,
F_48 ( V_74 ) -> V_389 , F_48 ( V_74 ) -> V_527 ,
F_224 ( V_76 ) ) ;
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 = V_298 ;
return V_297 ;
}
return 0 ;
}
static int F_225 ( struct V_15 * V_74 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
T_1 V_529 = 0 , V_530 ;
if ( ! ( V_74 -> V_131 & V_349 ) ) {
V_529 ++ ;
F_48 ( V_74 ) -> V_292 ++ ;
} else {
int V_531 = 1 ;
if ( ( F_48 ( V_74 ) -> V_504 != NULL ) &&
( F_103 ( V_76 ) -> V_192 != V_193 ) ) {
V_530 = F_226 ( V_74 ,
F_48 ( V_74 ) -> V_389 ,
F_48 ( V_74 ) -> V_527 ,
V_161 , F_48 ( V_74 ) -> V_504 ,
V_531 ) ;
if ( ! ( V_530 ) ) {
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 =
V_304 ;
return V_295 ;
}
V_531 = 0 ;
}
V_529 = F_226 ( V_74 ,
F_48 ( V_74 ) -> V_389 ,
F_48 ( V_74 ) -> V_527 ,
V_74 -> V_159 , F_48 ( V_74 ) -> V_358 ,
V_531 ) ;
if ( ! ( V_529 ) ) {
V_74 -> V_131 |= V_276 ;
V_74 -> V_277 =
V_304 ;
return V_295 ;
}
F_48 ( V_74 ) -> V_292 += V_529 ;
#if 0
printk(KERN_INFO "data_length: %u, LBA: %llu t_tasks_sectors:"
" %u, t_task_cdbs: %u\n", obj_ptr, cmd->data_length,
T_TASK(cmd)->t_task_lba, T_TASK(cmd)->t_tasks_sectors,
T_TASK(cmd)->t_task_cdbs);
#endif
}
F_16 ( & F_48 ( V_74 ) -> V_140 , V_529 ) ;
F_16 ( & F_48 ( V_74 ) -> V_84 , V_529 ) ;
F_16 ( & F_48 ( V_74 ) -> V_138 , V_529 ) ;
return 0 ;
}
static struct V_491 * F_222 ( void )
{
struct V_491 * V_492 ;
V_492 = F_2 ( sizeof( struct V_491 ) , V_3 ) ;
if ( ! ( V_492 ) ) {
F_3 ( V_4 L_193 ) ;
return NULL ;
}
F_4 ( V_492 ) ;
return V_492 ;
}
static int
F_194 ( struct V_15 * V_74 , T_1 V_369 , T_1 V_532 )
{
unsigned char * V_58 ;
struct V_24 * V_24 ;
F_48 ( V_74 ) -> V_358 = F_222 () ;
if ( ! ( F_48 ( V_74 ) -> V_358 ) )
return - V_50 ;
if ( V_74 -> V_79 -> V_129 -> V_510 )
return 0 ;
if ( F_48 ( V_74 ) -> V_399 ) {
F_48 ( V_74 ) -> V_504 = F_222 () ;
if ( ! ( F_48 ( V_74 ) -> V_504 ) ) {
F_9 ( F_48 ( V_74 ) -> V_358 ) ;
return - V_50 ;
}
}
while ( V_369 ) {
V_24 = F_22 ( V_23 , V_3 ) ;
if ( ! ( V_24 ) ) {
F_3 ( V_4 L_194 ) ;
goto V_16;
}
V_24 -> V_359 = F_227 ( V_3 , 0 ) ;
if ( ! ( V_24 -> V_359 ) ) {
F_3 ( V_4 L_195 ) ;
goto V_16;
}
V_58 = F_189 ( V_24 -> V_359 , V_533 ) ;
if ( ! ( V_58 ) ) {
F_3 ( V_4 L_196 ) ;
goto V_16;
}
F_4 ( & V_24 -> V_512 ) ;
V_24 -> V_361 = ( V_369 > V_532 ) ? V_532 : V_369 ;
memset ( V_58 , 0 , V_24 -> V_361 ) ;
F_190 ( V_58 , V_533 ) ;
F_28 ( & V_24 -> V_512 , F_48 ( V_74 ) -> V_358 ) ;
F_48 ( V_74 ) -> V_317 ++ ;
F_228 ( L_197
L_198 , V_24 -> V_359 , V_24 -> V_361 ,
V_24 -> V_362 ) ;
V_369 -= V_24 -> V_361 ;
}
F_228 ( L_199 ,
F_48 ( V_74 ) -> V_317 ) ;
return 0 ;
V_16:
if ( V_24 )
F_229 ( V_24 -> V_359 , 0 ) ;
F_41 ( V_23 , V_24 ) ;
return - 1 ;
}
T_1 F_230 (
struct V_77 * V_78 ,
struct V_24 * V_534 ,
T_1 V_535 )
{
struct V_15 * V_15 = V_78 -> V_151 ;
struct V_75 * V_79 = F_64 ( V_15 ) ;
struct V_24 * V_24 = V_534 ;
struct V_259 * V_260 = F_52 ( V_15 ) ;
T_1 V_536 , V_537 = V_78 -> V_537 , V_538 ;
while ( V_537 != 0 ) {
F_231 ( L_200
L_201 ,
V_24 -> V_359 , V_24 -> V_361 ,
V_24 -> V_362 , V_535 ) ;
if ( V_535 == 0 ) {
if ( V_537 >= V_24 -> V_361 ) {
V_536 = V_24 -> V_361 ;
if ( ! ( F_232 ( & V_24 -> V_512 ,
F_48 ( V_15 ) -> V_358 ) ) )
V_24 = F_74 ( V_24 -> V_512 . V_115 ,
struct V_24 , V_512 ) ;
} else {
V_536 = V_537 ;
V_537 -= V_536 ;
goto V_115;
}
F_231 ( L_202 ,
V_536 , V_537 ) ;
} else {
if ( ( V_24 -> V_361 - V_535 ) > V_537 ) {
V_536 = V_537 ;
V_537 -= V_536 ;
goto V_115;
} else {
V_536 = ( V_24 -> V_361 - V_535 ) ;
if ( ! ( F_232 ( & V_24 -> V_512 ,
F_48 ( V_15 ) -> V_358 ) ) )
V_24 = F_74 ( V_24 -> V_512 . V_115 ,
struct V_24 , V_512 ) ;
}
F_231 ( L_202 ,
V_536 , V_537 ) ;
V_535 = 0 ;
}
V_537 -= V_536 ;
V_115:
F_231 ( L_203 ,
V_78 -> V_255 , V_537 ) ;
V_78 -> V_539 ++ ;
}
if ( V_260 -> V_540 ) {
V_538 = ( V_78 -> V_539 + 1 ) ;
V_78 -> V_541 = 1 ;
} else
V_538 = V_78 -> V_539 ;
V_78 -> V_506 = F_2 ( V_538 *
sizeof( struct V_485 ) , V_3 ) ;
if ( ! ( V_78 -> V_506 ) ) {
F_3 ( V_4 L_42
L_204 ) ;
return 0 ;
}
F_233 ( & V_78 -> V_506 [ 0 ] , V_538 ) ;
if ( ( F_48 ( V_15 ) -> V_504 != NULL ) &&
( F_103 ( V_79 ) -> V_192 == V_193 ) ) {
V_78 -> V_505 = F_2 ( V_538 *
sizeof( struct V_485 ) , V_3 ) ;
if ( ! ( V_78 -> V_505 ) ) {
F_3 ( V_4 L_42
L_205 ) ;
return 0 ;
}
F_233 ( & V_78 -> V_505 [ 0 ] , V_538 ) ;
}
if ( V_78 -> V_541 ) {
F_234 ( & V_78 -> V_506 [ V_78 -> V_539 - 1 ] ) ;
if ( V_78 -> V_505 )
F_234 ( & V_78 -> V_505 [ V_78 -> V_539 - 1 ] ) ;
}
F_231 ( L_206
L_207 , V_78 -> V_539 ,
V_538 ) ;
return V_78 -> V_539 ;
}
static inline int F_235 (
struct V_77 * V_78 ,
struct V_75 * V_76 ,
unsigned long long V_542 ,
T_1 V_353 ,
int * V_543 )
{
if ( ( V_542 + V_353 ) > F_224 ( V_76 ) ) {
V_78 -> V_544 = ( ( F_224 ( V_76 ) - V_542 ) + 1 ) ;
if ( V_78 -> V_544 > F_90 ( V_76 ) -> V_174 ) {
V_78 -> V_544 = F_90 ( V_76 ) -> V_174 ;
* V_543 = 1 ;
}
} else {
if ( V_353 > F_90 ( V_76 ) -> V_174 ) {
V_78 -> V_544 = F_90 ( V_76 ) -> V_174 ;
* V_543 = 1 ;
} else
V_78 -> V_544 = V_353 ;
}
return 0 ;
}
static inline int F_236 (
struct V_77 * V_78 ,
struct V_75 * V_76 ,
unsigned long long V_542 ,
T_1 V_353 ,
int * V_543 )
{
if ( V_353 > F_90 ( V_76 ) -> V_174 ) {
V_78 -> V_544 = F_90 ( V_76 ) -> V_174 ;
* V_543 = 1 ;
} else
V_78 -> V_544 = V_353 ;
return 0 ;
}
static inline int F_237 (
struct V_77 * V_78 ,
struct V_75 * V_76 ,
unsigned long long V_542 ,
T_1 V_353 ,
int * V_543 )
{
return ( F_103 ( V_76 ) -> F_107 ( V_76 ) == V_528 ) ?
F_235 ( V_78 , V_76 , V_542 , V_353 ,
V_543 ) :
F_236 ( V_78 , V_76 , V_542 , V_353 ,
V_543 ) ;
}
static int F_223 (
struct V_15 * V_74 ,
struct V_491 * V_492 ,
void * V_545 ,
T_1 * V_546 )
{
struct V_24 * V_24 ;
struct V_485 * V_547 ;
T_1 V_548 = 1 , V_549 = V_74 -> V_261 ;
if ( ! V_545 ) {
F_3 ( V_4 L_208 ) ;
return - 1 ;
}
V_547 = (struct V_485 * ) V_545 ;
while ( V_549 ) {
V_24 = F_22 ( V_23 , V_3 ) ;
if ( ! ( V_24 ) ) {
F_3 ( V_4 L_194 ) ;
return - 1 ;
}
F_4 ( & V_24 -> V_512 ) ;
F_228 ( L_209
L_210 , V_549 ,
F_238 ( V_547 ) , V_547 -> V_357 , V_547 -> V_369 ) ;
V_24 -> V_359 = F_238 ( V_547 ) ;
V_24 -> V_362 = V_547 -> V_357 ;
if ( V_549 > V_547 -> V_369 ) {
V_24 -> V_361 = V_547 -> V_369 ;
V_547 = F_239 ( V_547 ) ;
V_548 ++ ;
} else
V_24 -> V_361 = V_549 ;
V_549 -= V_24 -> V_361 ;
F_228 ( L_211 ,
* V_546 , V_549 ) ;
F_228 ( L_212 ,
V_24 -> V_359 , V_24 -> V_362 , V_24 -> V_361 ) ;
F_28 ( & V_24 -> V_512 , V_492 ) ;
( * V_546 ) ++ ;
}
F_228 ( L_213
L_214 , V_548 , * V_546 ) ;
if ( V_548 != * V_546 )
F_240 () ;
return 0 ;
}
int F_241 (
struct V_77 * V_78 ,
struct V_491 * V_492 ,
void * V_545 ,
struct V_24 * V_534 ,
struct V_24 * * V_550 ,
T_1 * V_546 ,
T_1 * V_535 )
{
struct V_15 * V_15 = V_78 -> V_151 ;
struct V_24 * V_24 = V_534 ;
struct V_485 * V_547 = (struct V_485 * ) V_545 ;
T_1 V_537 = V_78 -> V_537 , V_551 = 0 ;
if ( ! V_547 ) {
F_3 ( V_4 L_215
L_216 ) ;
return - 1 ;
}
while ( V_537 != 0 ) {
F_242 ( V_547 , V_24 -> V_359 ) ;
if ( * V_535 == 0 ) {
V_547 -> V_357 = V_24 -> V_362 ;
if ( V_537 >= V_24 -> V_361 ) {
V_547 -> V_369 = V_24 -> V_361 ;
if ( ! ( F_232 ( & V_24 -> V_512 ,
F_48 ( V_15 ) -> V_358 ) ) ) {
V_24 = F_74 ( V_24 -> V_512 . V_115 ,
struct V_24 , V_512 ) ;
( * V_546 ) ++ ;
}
} else {
V_547 -> V_369 = V_537 ;
V_537 -= V_547 -> V_369 ;
if ( ! ( V_537 ) )
* V_535 = V_547 -> V_369 ;
goto V_115;
}
} else {
V_547 -> V_357 = ( * V_535 + V_24 -> V_362 ) ;
if ( ( V_24 -> V_361 - * V_535 ) > V_537 ) {
V_547 -> V_369 = V_537 ;
V_537 -= V_547 -> V_369 ;
if ( ! ( V_537 ) )
* V_535 += V_547 -> V_369 ;
goto V_115;
} else {
V_547 -> V_369 = ( V_24 -> V_361 - * V_535 ) ;
if ( ! ( F_232 ( & V_24 -> V_512 ,
F_48 ( V_15 ) -> V_358 ) ) ) {
V_24 = F_74 ( V_24 -> V_512 . V_115 ,
struct V_24 , V_512 ) ;
( * V_546 ) ++ ;
}
}
* V_535 = 0 ;
}
V_537 -= V_547 -> V_369 ;
V_115:
F_228 ( L_217
L_218 , V_78 -> V_255 , V_551 ,
F_238 ( V_547 ) , V_547 -> V_369 , V_547 -> V_357 , V_537 , * V_535 ) ;
V_551 ++ ;
if ( ! ( V_537 ) )
break;
V_547 = F_239 ( V_547 ) ;
if ( V_537 > V_15 -> V_261 )
F_240 () ;
}
* V_550 = V_24 ;
F_228 ( L_219
L_220 , V_78 -> V_255 , * V_546 , V_551 ) ;
return 0 ;
}
void F_243 ( struct V_15 * V_74 )
{
struct V_485 * V_552 = NULL , * V_553 = NULL , * V_554 = NULL ;
struct V_485 * V_555 = NULL , * V_556 = NULL ;
struct V_485 * V_547 , * V_557 = NULL , * V_558 = NULL ;
struct V_77 * V_78 ;
struct V_259 * V_260 = F_52 ( V_74 ) ;
T_1 V_539 = 0 , V_548 = 0 ;
int V_191 ;
if ( V_260 -> V_540 == 0 ) {
F_3 ( V_4 L_221
L_222 , V_260 -> F_30 () ) ;
F_87 () ;
return;
}
F_49 (task, &T_TASK(cmd)->t_task_list, t_list) {
if ( ! ( V_78 -> V_506 ) || ! ( V_78 -> V_541 ) )
continue;
if ( V_552 && V_553 ) {
V_555 = & V_78 -> V_506 [ 0 ] ;
V_556 = & V_78 -> V_506 [ V_78 -> V_539 ] ;
if ( ! ( F_232 ( & V_78 -> V_116 ,
& F_48 ( V_74 ) -> V_114 ) ) ) {
V_558 = & V_78 -> V_506 [ V_78 -> V_539 - 1 ] ;
V_558 -> V_559 &= ~ 0x02 ;
F_244 ( V_552 , V_539 , V_555 ) ;
V_548 += V_78 -> V_539 ;
V_539 = ( V_78 -> V_539 + 1 ) ;
} else {
F_244 ( V_552 , V_539 , V_555 ) ;
V_548 += V_78 -> V_539 ;
V_539 = V_78 -> V_539 ;
}
V_552 = V_555 ;
V_553 = V_556 ;
continue;
}
V_552 = V_554 = & V_78 -> V_506 [ 0 ] ;
V_553 = & V_78 -> V_506 [ V_78 -> V_539 ] ;
if ( ! ( F_232 ( & V_78 -> V_116 , & F_48 ( V_74 ) -> V_114 ) ) ) {
V_557 = & V_78 -> V_506 [ V_78 -> V_539 - 1 ] ;
V_557 -> V_559 &= ~ 0x02 ;
V_548 += V_78 -> V_539 ;
V_539 = ( V_78 -> V_539 + 1 ) ;
} else {
V_548 += V_78 -> V_539 ;
V_539 = V_78 -> V_539 ;
}
}
F_48 ( V_74 ) -> V_560 = V_554 ;
F_48 ( V_74 ) -> V_561 = V_548 ;
F_245 ( L_223
L_224 , V_74 , F_48 ( V_74 ) -> V_560 ,
F_48 ( V_74 ) -> V_561 ) ;
F_246 (T_TASK(cmd)->t_tasks_sg_chained, sg,
T_TASK(cmd)->t_tasks_sg_chained_no, i) {
F_245 ( L_225 ,
V_191 , V_547 , F_238 ( V_547 ) , V_547 -> V_369 , V_547 -> V_357 , V_547 -> V_562 ) ;
if ( F_247 ( V_547 ) )
F_245 ( L_226 , V_547 ) ;
if ( F_248 ( V_547 ) )
F_245 ( L_227 , V_547 ) ;
}
}
static int F_249 (
struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_491 * V_492 ,
void * V_545 ,
struct V_24 * V_534 ,
struct V_24 * * V_550 ,
T_1 * V_546 ,
T_1 * V_563 )
{
T_1 V_535 = * V_563 ;
int V_47 = 0 ;
if ( F_103 ( V_76 ) -> V_510 ) {
V_47 = F_103 ( V_76 ) -> V_510 ( V_78 , V_492 ,
V_545 , V_534 , V_550 , V_546 ,
V_563 ) ;
if ( V_47 == 0 )
F_48 ( V_78 -> V_151 ) -> V_317 += * V_546 ;
return V_47 ;
}
F_250 ( F_37 ( V_492 ) ) ;
if ( ! ( V_78 -> V_505 ) ) {
if ( ! ( F_230 ( V_78 , V_534 , V_535 ) ) )
return - 1 ;
return F_241 ( V_78 , V_492 , V_78 -> V_506 ,
V_534 , V_550 , V_546 ,
V_563 ) ;
}
return F_241 ( V_78 , V_492 , V_78 -> V_505 ,
V_534 , V_550 , V_546 ,
V_563 ) ;
}
static T_1 F_226 (
struct V_15 * V_74 ,
unsigned long long V_542 ,
T_1 V_353 ,
enum V_253 V_159 ,
struct V_491 * V_564 ,
int V_531 )
{
unsigned char * V_244 = NULL ;
struct V_77 * V_78 ;
struct V_24 * V_24 = NULL , * V_565 = NULL ;
struct V_24 * V_566 = NULL , * V_567 = NULL ;
struct V_75 * V_76 = F_64 ( V_74 ) ;
int V_543 = 0 , V_47 ;
T_1 V_563 = 0 , V_546 = 0 , V_568 = 0 , V_529 = 0 ;
if ( ! V_564 ) {
F_3 ( V_4 L_228
L_229 ) ;
return 0 ;
}
if ( ! ( F_37 ( V_564 ) ) )
V_24 = F_74 ( V_564 -> V_115 , struct V_24 , V_512 ) ;
if ( ( F_48 ( V_74 ) -> V_504 != NULL ) &&
! ( F_37 ( F_48 ( V_74 ) -> V_504 ) ) &&
( F_103 ( V_76 ) -> V_192 == V_193 ) )
V_566 = F_74 ( F_48 ( V_74 ) -> V_504 -> V_115 ,
struct V_24 , V_512 ) ;
while ( V_353 ) {
F_251 ( L_230 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) , V_542 , V_353 ,
F_224 ( V_76 ) ) ;
V_78 = F_119 ( V_74 , V_159 ) ;
if ( ! ( V_78 ) )
goto V_16;
F_237 ( V_78 , V_76 , V_542 , V_353 ,
& V_543 ) ;
V_78 -> V_569 = V_542 ;
V_542 += V_78 -> V_544 ;
V_353 -= V_78 -> V_544 ;
V_78 -> V_537 = ( V_78 -> V_544 *
F_90 ( V_76 ) -> V_173 ) ;
V_244 = F_103 ( V_76 ) -> F_252 ( V_78 ) ;
if ( ( V_244 ) ) {
memcpy ( V_244 , F_48 ( V_74 ) -> V_154 ,
F_129 ( F_48 ( V_74 ) -> V_154 ) ) ;
V_74 -> V_387 ( V_78 -> V_569 ,
& V_78 -> V_544 , V_244 ) ;
}
V_47 = F_249 ( V_76 , V_78 , V_564 ,
NULL , V_24 , & V_565 , & V_546 ,
& V_563 ) ;
if ( V_47 < 0 )
goto V_16;
V_24 = V_565 ;
if ( V_78 -> V_505 != NULL ) {
V_47 = F_249 ( V_76 , V_78 ,
F_48 ( V_74 ) -> V_504 , NULL ,
V_566 , & V_567 , & V_568 ,
& V_563 ) ;
if ( V_47 < 0 )
goto V_16;
V_566 = V_567 ;
}
V_529 ++ ;
F_251 ( L_231 ,
V_529 , V_78 -> V_539 ) ;
if ( V_543 ) {
V_543 = 0 ;
continue;
}
if ( ! V_353 )
break;
}
if ( V_531 ) {
F_68 ( & F_48 ( V_74 ) -> V_514 ) ;
F_68 ( & F_48 ( V_74 ) -> V_136 ) ;
}
F_251 ( L_232 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) , ( V_159 == V_162 )
? L_233 : L_234 , V_529 ) ;
return V_529 ;
V_16:
return 0 ;
}
static int
F_253 ( struct V_15 * V_74 )
{
struct V_75 * V_76 = F_64 ( V_74 ) ;
unsigned char * V_244 ;
struct V_77 * V_78 ;
int V_47 ;
V_78 = F_119 ( V_74 , V_74 -> V_159 ) ;
if ( ! V_78 )
return V_302 ;
V_244 = F_103 ( V_76 ) -> F_252 ( V_78 ) ;
if ( V_244 )
memcpy ( V_244 , V_74 -> V_266 -> V_154 ,
F_129 ( V_74 -> V_266 -> V_154 ) ) ;
V_78 -> V_537 = V_74 -> V_261 ;
V_78 -> V_539 =
( V_74 -> V_131 & V_370 ) ? 1 : 0 ;
F_68 ( & V_74 -> V_266 -> V_514 ) ;
F_68 ( & V_74 -> V_266 -> V_136 ) ;
if ( V_74 -> V_131 & V_370 ) {
struct V_24 * V_24 = NULL , * V_565 = NULL ;
T_1 V_546 = 0 , V_535 = 0 ;
if ( ! F_37 ( F_48 ( V_74 ) -> V_358 ) )
V_24 = F_74 ( F_48 ( V_74 ) -> V_358 -> V_115 ,
struct V_24 , V_512 ) ;
V_47 = F_249 ( V_76 , V_78 ,
V_74 -> V_266 -> V_358 , NULL , V_24 ,
& V_565 , & V_546 , & V_535 ) ;
if ( V_47 < 0 )
return V_302 ;
if ( V_76 -> V_129 -> V_570 )
return V_76 -> V_129 -> V_570 ( V_78 ) ;
return 0 ;
} else if ( V_74 -> V_131 & V_372 ) {
if ( V_76 -> V_129 -> V_571 )
return V_76 -> V_129 -> V_571 ( V_78 ) ;
return 0 ;
} else if ( V_74 -> V_131 & V_458 ) {
if ( V_76 -> V_129 -> V_572 )
return V_76 -> V_129 -> V_572 ( V_78 ) ;
return 0 ;
} else {
F_240 () ;
return V_302 ;
}
}
static int F_254 ( struct V_15 * V_74 )
{
struct V_53 * V_54 ;
struct V_77 * V_78 ;
struct V_75 * V_76 = F_64 ( V_74 ) ;
int V_47 = 0 ;
if ( ! ( V_74 -> V_131 & V_509 ) ) {
V_47 = F_193 ( V_74 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_47 = F_205 ( V_74 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_225 ( V_74 ) ;
if ( V_47 < 0 )
return V_47 ;
V_54 = F_61 ( V_74 ) -> V_280 -> V_573 ;
if ( F_25 ( V_54 ) -> V_574 != NULL ) {
V_47 = F_25 ( V_54 ) -> V_574 ( V_74 ) ;
if ( V_47 < 0 )
return V_302 ;
}
if ( V_74 -> V_131 & V_349 ) {
F_49 (task, &T_TASK(cmd)->t_task_list, t_list) {
if ( F_50 ( & V_78 -> V_290 ) )
continue;
if ( ! V_76 -> V_129 -> V_570 )
continue;
V_47 = V_76 -> V_129 -> V_570 ( V_78 ) ;
if ( V_47 < 0 )
return V_47 ;
}
} else {
V_47 = F_253 ( V_74 ) ;
if ( V_47 < 0 )
return V_47 ;
}
if ( V_74 -> V_159 == V_162 ) {
F_83 ( V_74 ) ;
return F_255 ( V_74 ) ;
}
F_173 ( V_74 ) ;
return 0 ;
}
void F_256 ( struct V_15 * V_74 )
{
#if 0
if (cmd->se_cmd_flags & SCF_UNDERFLOW_BIT) {
if (!T_TASK(cmd)->t_tasks_se_num) {
unsigned char *dst, *buf =
(unsigned char *)T_TASK(cmd)->t_task_buf;
dst = kzalloc(cmd->cmd_spdtl), GFP_KERNEL);
if (!(dst)) {
printk(KERN_ERR "Unable to allocate memory for"
" WRITE underflow\n");
transport_generic_request_failure(cmd, NULL,
PYX_TRANSPORT_REQ_TOO_MANY_SECTORS, 1);
return;
}
memcpy(dst, buf, cmd->cmd_spdtl);
kfree(T_TASK(cmd)->t_task_buf);
T_TASK(cmd)->t_task_buf = dst;
} else {
struct scatterlist *sg =
(struct scatterlist *sg)T_TASK(cmd)->t_task_buf;
struct scatterlist *orig_sg;
orig_sg = kzalloc(sizeof(struct scatterlist) *
T_TASK(cmd)->t_tasks_se_num,
GFP_KERNEL))) {
if (!(orig_sg)) {
printk(KERN_ERR "Unable to allocate memory"
" for WRITE underflow\n");
transport_generic_request_failure(cmd, NULL,
PYX_TRANSPORT_REQ_TOO_MANY_SECTORS, 1);
return;
}
memcpy(orig_sg, T_TASK(cmd)->t_task_buf,
sizeof(struct scatterlist) *
T_TASK(cmd)->t_tasks_se_num);
cmd->data_length = cmd->cmd_spdtl;
if (transport_generic_new_cmd(cmd) < 0) {
transport_generic_request_failure(cmd, NULL,
PYX_TRANSPORT_REQ_TOO_MANY_SECTORS, 1);
kfree(orig_sg);
return;
}
transport_memcpy_write_sg(cmd, orig_sg);
}
}
#endif
F_173 ( V_74 ) ;
}
static int F_255 ( struct V_15 * V_74 )
{
unsigned long V_68 ;
int V_47 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
V_74 -> V_86 = V_575 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( V_74 -> V_131 & V_501 )
F_208 ( V_74 ,
F_48 ( V_74 ) -> V_318 ,
F_48 ( V_74 ) -> V_502 ) ;
F_55 ( V_74 , 1 , 0 ) ;
V_47 = F_52 ( V_74 ) -> F_257 ( V_74 ) ;
if ( V_47 < 0 )
return V_47 ;
return V_576 ;
}
void F_220 ( struct V_15 * V_74 )
{
F_250 ( ! F_48 ( V_74 ) ) ;
F_250 ( ! F_52 ( V_74 ) ) ;
F_126 ( V_74 ) ;
F_52 ( V_74 ) -> F_258 ( V_74 ) ;
}
void F_259 (
struct V_15 * V_74 ,
int V_577 ,
int V_516 ,
int V_517 )
{
if ( ! ( V_74 -> V_131 & V_578 ) || ! F_48 ( V_74 ) )
F_220 ( V_74 ) ;
else {
F_260 ( V_74 -> V_49 -> V_55 , V_74 ) ;
if ( F_61 ( V_74 ) ) {
#if 0
printk(KERN_INFO "cmd: %p ITT: 0x%08x contains"
" SE_LUN(cmd)\n", cmd,
CMD_TFO(cmd)->get_task_tag(cmd));
#endif
F_60 ( V_74 ) ;
}
if ( V_577 && V_74 -> V_273 )
V_74 -> V_273 ( V_74 , 0 , 0 ) ;
F_213 ( V_74 ) ;
F_65 ( V_74 , V_516 ,
V_517 ) ;
}
}
static void V_373 (
struct V_15 * V_74 ,
int V_579 ,
int V_517 )
{
return;
}
static int F_261 ( struct V_15 * V_74 , struct V_95 * V_98 )
{
unsigned long V_68 ;
int V_47 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_94 ) ) {
F_16 ( & F_48 ( V_74 ) -> V_88 , 0 ) ;
F_262 ( L_235
L_236 , F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_55 ( V_74 , 1 , 0 ) ;
return - 1 ;
}
F_16 ( & F_48 ( V_74 ) -> V_580 , 1 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_69 ( & F_64 ( V_74 ) -> V_104 -> V_45 ) ;
V_47 = F_139 ( V_74 ) ;
F_262 ( L_237
L_238 , V_74 , F_48 ( V_74 ) -> V_292 , V_47 ) ;
if ( ! V_47 ) {
F_262 ( L_239 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_141 ( & F_48 ( V_74 ) -> V_93 ) ;
F_262 ( L_240 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
}
F_63 ( V_74 , F_64 ( V_74 ) -> V_104 ) ;
return 0 ;
}
static void F_263 ( struct V_95 * V_98 )
{
struct V_15 * V_74 = NULL ;
unsigned long V_581 , V_582 ;
F_35 ( & V_98 -> V_101 , V_581 ) ;
while ( ! F_264 ( & V_98 -> V_583 ) ) {
V_74 = F_74 ( V_98 -> V_583 . V_115 ,
struct V_15 , V_103 ) ;
F_36 ( & V_74 -> V_103 ) ;
if ( ! ( F_48 ( V_74 ) ) ) {
F_3 ( V_4 L_241
L_242 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_52 ( V_74 ) -> F_92 ( V_74 ) , V_74 -> V_86 ) ;
F_240 () ;
}
F_16 ( & F_48 ( V_74 ) -> V_102 , 0 ) ;
F_13 ( & F_48 ( V_74 ) -> V_87 ) ;
F_265 ( L_243
L_244 ,
F_61 ( V_74 ) -> V_584 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_16 ( & F_48 ( V_74 ) -> V_88 , 1 ) ;
F_14 ( & F_48 ( V_74 ) -> V_87 ) ;
F_39 ( & V_98 -> V_101 , V_581 ) ;
if ( ! ( F_61 ( V_74 ) ) ) {
F_3 ( V_4 L_245 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_52 ( V_74 ) -> F_92 ( V_74 ) , V_74 -> V_86 ) ;
F_240 () ;
}
F_265 ( L_246
L_247 , F_61 ( V_74 ) -> V_584 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
if ( F_261 ( V_74 , F_61 ( V_74 ) ) < 0 ) {
F_35 ( & V_98 -> V_101 , V_581 ) ;
continue;
}
F_265 ( L_248
L_249 ,
F_61 ( V_74 ) -> V_584 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_582 ) ;
if ( ! ( F_50 ( & F_48 ( V_74 ) -> V_99 ) ) ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_582 ) ;
goto V_585;
}
F_16 ( & F_48 ( V_74 ) -> V_99 , 0 ) ;
F_47 ( V_74 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_582 ) ;
F_213 ( V_74 ) ;
V_585:
F_155 ( V_74 ,
V_499 , 0 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_582 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_580 ) ) {
F_265 ( L_250
L_251 ,
V_98 -> V_584 ,
V_74 , F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 ,
V_582 ) ;
F_55 ( V_74 , 1 , 0 ) ;
F_58 ( & F_48 ( V_74 ) -> V_268 ) ;
F_35 ( & V_98 -> V_101 , V_581 ) ;
continue;
}
F_265 ( L_252 ,
V_98 -> V_584 , F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_582 ) ;
F_35 ( & V_98 -> V_101 , V_581 ) ;
}
F_39 ( & V_98 -> V_101 , V_581 ) ;
}
static int F_266 ( void * V_586 )
{
struct V_95 * V_98 = (struct V_95 * ) V_586 ;
F_263 ( V_98 ) ;
F_58 ( & V_98 -> V_587 ) ;
return 0 ;
}
int F_267 ( struct V_95 * V_98 )
{
struct V_588 * V_589 ;
V_589 = F_114 ( F_266 , ( void * ) V_98 ,
L_253 , V_98 -> V_584 ) ;
if ( F_115 ( V_589 ) ) {
F_3 ( V_4 L_254 ) ;
return - 1 ;
}
F_141 ( & V_98 -> V_587 ) ;
return 0 ;
}
static void V_274 (
struct V_15 * V_74 ,
int V_579 ,
int V_517 )
{
unsigned long V_68 ;
if ( ! ( V_74 -> V_131 & V_578 ) && ! ( V_74 -> V_18 ) )
return;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_88 ) ) {
F_262 ( L_255
L_256
L_257 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_58 ( & F_48 ( V_74 ) -> V_93 ) ;
F_141 ( & F_48 ( V_74 ) -> V_268 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_47 ( V_74 ) ;
F_262 ( L_258
L_259
L_260 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
F_16 ( & F_48 ( V_74 ) -> V_88 , 0 ) ;
}
if ( ! F_50 ( & F_48 ( V_74 ) -> V_92 ) ||
F_50 ( & F_48 ( V_74 ) -> V_590 ) )
goto remove;
F_16 ( & F_48 ( V_74 ) -> V_94 , 1 ) ;
F_262 ( L_261
L_262
L_263 , V_74 , F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_52 ( V_74 ) -> F_92 ( V_74 ) , V_74 -> V_86 ,
V_74 -> V_90 ) ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_69 ( & F_64 ( V_74 ) -> V_104 -> V_45 ) ;
F_141 ( & F_48 ( V_74 ) -> V_96 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_16 ( & F_48 ( V_74 ) -> V_92 , 0 ) ;
F_16 ( & F_48 ( V_74 ) -> V_94 , 0 ) ;
F_262 ( L_264
L_265 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
remove:
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( ! V_579 )
return;
F_259 ( V_74 , 0 , 0 , V_517 ) ;
}
static int F_268 (
struct V_15 * V_74 ,
T_3 * V_591 ,
T_3 * V_592 )
{
* V_591 = V_74 -> V_593 ;
* V_592 = V_74 -> V_594 ;
return 0 ;
}
static int F_199 (
struct V_15 * V_74 ,
T_3 V_591 ,
T_3 V_592 )
{
V_74 -> V_593 = V_591 ;
V_74 -> V_594 = V_592 ;
return 0 ;
}
int F_155 (
struct V_15 * V_74 ,
T_3 V_498 ,
int V_595 )
{
unsigned char * V_363 = V_74 -> V_263 ;
unsigned long V_68 ;
int V_357 ;
T_3 V_591 = 0 , V_592 = 0 ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( V_74 -> V_131 & V_364 ) {
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
return 0 ;
}
V_74 -> V_131 |= V_364 ;
F_39 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
if ( ! V_498 && V_595 )
goto V_596;
if ( ! V_595 )
V_74 -> V_131 |= V_597 ;
V_357 = F_52 ( V_74 ) -> F_192 ( V_74 ,
V_366 ) ;
switch ( V_498 ) {
case V_499 :
case V_296 :
case V_298 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_599 ;
V_363 [ V_357 + V_600 ] = 0x20 ;
break;
case V_306 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_599 ;
V_363 [ V_357 + V_600 ] = 0x24 ;
break;
case V_601 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x29 ;
V_363 [ V_357 + V_603 ] = 0x03 ;
break;
case V_604 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x0c ;
V_363 [ V_357 + V_603 ] = 0x0d ;
break;
case V_278 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x24 ;
break;
case V_301 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x26 ;
break;
case V_605 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x0c ;
V_363 [ V_357 + V_603 ] = 0x0c ;
break;
case V_606 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x47 ;
V_363 [ V_357 + V_603 ] = 0x05 ;
break;
case V_607 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_602 ;
V_363 [ V_357 + V_600 ] = 0x11 ;
V_363 [ V_357 + V_603 ] = 0x13 ;
break;
case V_308 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_608 ;
V_363 [ V_357 + V_600 ] = 0x27 ;
break;
case V_382 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_609 ;
F_269 ( V_74 , & V_591 , & V_592 ) ;
V_363 [ V_357 + V_600 ] = V_591 ;
V_363 [ V_357 + V_603 ] = V_592 ;
break;
case V_383 :
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_610 ;
F_268 ( V_74 , & V_591 , & V_592 ) ;
V_363 [ V_357 + V_600 ] = V_591 ;
V_363 [ V_357 + V_603 ] = V_592 ;
break;
case V_304 :
default:
V_363 [ V_357 ] = 0x70 ;
V_363 [ V_357 + V_598 ] = V_599 ;
V_363 [ V_357 + V_600 ] = 0x80 ;
break;
}
V_74 -> V_117 = V_121 ;
V_74 -> V_367 = V_366 + V_357 ;
V_596:
F_52 ( V_74 ) -> F_154 ( V_74 ) ;
return 0 ;
}
int F_136 ( struct V_15 * V_74 , int V_611 )
{
int V_47 = 0 ;
if ( F_50 ( & F_48 ( V_74 ) -> V_590 ) != 0 ) {
if ( ! ( V_611 ) ||
( V_74 -> V_131 & V_612 ) )
return 1 ;
#if 0
printk(KERN_INFO "Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
T_TASK(cmd)->t_task_cdb[0],
CMD_TFO(cmd)->get_task_tag(cmd));
#endif
V_74 -> V_131 |= V_612 ;
F_52 ( V_74 ) -> F_154 ( V_74 ) ;
V_47 = 1 ;
}
return V_47 ;
}
void F_270 ( struct V_15 * V_74 )
{
if ( V_74 -> V_159 == V_162 ) {
if ( F_52 ( V_74 ) -> F_271 ( V_74 ) != 0 ) {
F_68 ( & F_48 ( V_74 ) -> V_590 ) ;
F_125 () ;
V_74 -> V_117 = V_613 ;
F_149 ( V_74 ) ;
return;
}
}
V_74 -> V_117 = V_613 ;
#if 0
printk(KERN_INFO "Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", T_TASK(cmd)->t_task_cdb[0],
CMD_TFO(cmd)->get_task_tag(cmd));
#endif
F_52 ( V_74 ) -> F_154 ( V_74 ) ;
}
int F_272 ( struct V_15 * V_74 )
{
struct V_15 * V_614 ;
struct V_75 * V_76 = F_64 ( V_74 ) ;
struct V_18 * V_615 = V_74 -> V_18 ;
int V_47 ;
switch ( V_615 -> V_331 ) {
case V_616 :
V_614 = V_615 -> V_614 ;
V_615 -> V_617 = V_618 ;
break;
case V_619 :
case V_620 :
case V_621 :
V_615 -> V_617 = V_622 ;
break;
case V_623 :
V_47 = F_273 ( V_76 , V_615 , NULL , NULL ) ;
V_615 -> V_617 = ( ! V_47 ) ? V_624 :
V_618 ;
break;
case V_625 :
V_615 -> V_617 = V_618 ;
break;
case V_626 :
V_615 -> V_617 = V_618 ;
break;
default:
F_3 ( V_4 L_266 ,
V_615 -> V_331 ) ;
V_615 -> V_617 = V_618 ;
break;
}
V_74 -> V_86 = V_627 ;
F_52 ( V_74 ) -> F_274 ( V_74 ) ;
F_55 ( V_74 , 2 , 0 ) ;
return 0 ;
}
static struct V_77 *
F_275 ( struct V_75 * V_76 )
{
struct V_77 * V_78 ;
if ( F_37 ( & V_76 -> V_157 ) )
return NULL ;
F_49 (task, &dev->state_task_list, t_state_list)
break;
F_36 ( & V_78 -> V_83 ) ;
F_16 ( & V_78 -> V_81 , 0 ) ;
return V_78 ;
}
static void F_276 ( struct V_75 * V_76 )
{
struct V_15 * V_74 ;
struct V_105 * V_106 ;
struct V_77 * V_78 ;
T_3 V_109 ;
unsigned long V_68 ;
F_35 ( & V_76 -> V_82 , V_68 ) ;
while ( ( V_78 = F_275 ( V_76 ) ) ) {
if ( ! ( F_75 ( V_78 ) ) ) {
F_3 ( V_4 L_267 ) ;
continue;
}
V_74 = F_75 ( V_78 ) ;
if ( ! F_48 ( V_74 ) ) {
F_3 ( V_4 L_268
L_269 , V_78 , V_74 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ) ;
continue;
}
F_39 ( & V_76 -> V_82 , V_68 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_277 ( L_270
L_271
L_272 , V_74 , V_78 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) , V_74 -> V_628 ,
F_52 ( V_74 ) -> F_92 ( V_74 ) , V_74 -> V_629 ,
V_74 -> V_86 , V_74 -> V_90 ,
F_48 ( V_74 ) -> V_154 [ 0 ] ) ;
F_277 ( L_273
L_274
L_275 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_48 ( V_74 ) -> V_292 ,
F_50 ( & F_48 ( V_74 ) -> V_140 ) ,
F_50 ( & F_48 ( V_74 ) -> V_293 ) ,
F_50 ( & F_48 ( V_74 ) -> V_92 ) ,
F_50 ( & F_48 ( V_74 ) -> V_94 ) ,
F_50 ( & F_48 ( V_74 ) -> V_294 ) ) ;
if ( F_50 ( & V_78 -> V_80 ) ) {
F_16 ( & V_78 -> V_134 , 1 ) ;
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_277 ( L_276
L_277 , V_78 , V_76 ) ;
F_141 ( & V_78 -> V_137 ) ;
F_277 ( L_278 ,
V_78 , V_76 ) ;
F_35 ( & F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_54 ( & F_48 ( V_74 ) -> V_140 ) ;
F_16 ( & V_78 -> V_80 , 0 ) ;
F_16 ( & V_78 -> V_134 , 0 ) ;
} else {
if ( F_50 ( & V_78 -> V_158 ) != 0 )
F_86 ( V_78 , V_76 ) ;
}
F_142 ( V_78 , & V_68 ) ;
if ( ! ( F_78 ( & F_48 ( V_74 ) -> V_84 ) ) ) {
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_277 ( L_279
L_280 , V_78 , V_76 ,
F_50 ( & F_48 ( V_74 ) -> V_84 ) ) ;
F_35 ( & V_76 -> V_82 , V_68 ) ;
continue;
}
if ( F_50 ( & F_48 ( V_74 ) -> V_92 ) ) {
F_277 ( L_281
L_277 , V_78 , V_76 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_514 ) ) {
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_155 (
V_74 , V_304 ,
0 ) ;
F_63 ( V_74 ,
F_64 ( V_74 ) -> V_104 ) ;
F_60 ( V_74 ) ;
F_55 ( V_74 , 1 , 0 ) ;
} else {
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_63 ( V_74 ,
F_64 ( V_74 ) -> V_104 ) ;
F_60 ( V_74 ) ;
if ( F_55 ( V_74 , 1 , 0 ) )
F_65 ( V_74 , 0 , 0 ) ;
}
F_35 ( & V_76 -> V_82 , V_68 ) ;
continue;
}
F_277 ( L_282 ,
V_78 , V_76 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_514 ) ) {
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_155 ( V_74 ,
V_304 , 0 ) ;
F_63 ( V_74 ,
F_64 ( V_74 ) -> V_104 ) ;
F_60 ( V_74 ) ;
F_55 ( V_74 , 1 , 0 ) ;
} else {
F_39 (
& F_48 ( V_74 ) -> V_87 , V_68 ) ;
F_63 ( V_74 ,
F_64 ( V_74 ) -> V_104 ) ;
F_60 ( V_74 ) ;
if ( F_55 ( V_74 , 1 , 0 ) )
F_65 ( V_74 , 0 , 0 ) ;
}
F_35 ( & V_76 -> V_82 , V_68 ) ;
}
F_39 ( & V_76 -> V_82 , V_68 ) ;
F_35 ( & V_76 -> V_104 -> V_46 , V_68 ) ;
while ( ( V_106 = F_70 ( V_76 -> V_104 ) ) ) {
F_39 (
& V_76 -> V_104 -> V_46 , V_68 ) ;
V_74 = (struct V_15 * ) V_106 -> V_74 ;
V_109 = V_106 -> V_109 ;
F_9 ( V_106 ) ;
F_277 ( L_283 ,
V_74 , V_109 ) ;
if ( F_50 ( & F_48 ( V_74 ) -> V_514 ) ) {
F_155 ( V_74 ,
V_304 , 0 ) ;
F_60 ( V_74 ) ;
F_55 ( V_74 , 1 , 0 ) ;
} else {
F_60 ( V_74 ) ;
if ( F_55 ( V_74 , 1 , 0 ) )
F_65 ( V_74 , 0 , 0 ) ;
}
F_35 ( & V_76 -> V_104 -> V_46 , V_68 ) ;
}
F_39 ( & V_76 -> V_104 -> V_46 , V_68 ) ;
}
static int V_243 ( void * V_630 )
{
int V_47 , V_86 ;
struct V_15 * V_74 ;
struct V_75 * V_76 = (struct V_75 * ) V_630 ;
struct V_105 * V_106 ;
F_278 ( V_285 , - 20 ) ;
while ( ! F_279 () ) {
V_47 = F_280 ( V_76 -> V_104 -> V_45 ,
F_50 ( & V_76 -> V_104 -> V_43 ) ||
F_279 () ) ;
if ( V_47 < 0 )
goto V_16;
F_27 ( & V_76 -> V_228 ) ;
if ( V_76 -> V_166 & V_169 ) {
F_29 ( & V_76 -> V_228 ) ;
F_276 ( V_76 ) ;
continue;
}
F_29 ( & V_76 -> V_228 ) ;
V_631:
F_175 ( V_76 ) ;
V_106 = F_71 ( V_76 -> V_104 ) ;
if ( ! ( V_106 ) )
continue;
V_74 = (struct V_15 * ) V_106 -> V_74 ;
V_86 = V_106 -> V_109 ;
F_9 ( V_106 ) ;
switch ( V_86 ) {
case V_284 :
if ( ! ( F_52 ( V_74 ) -> V_632 ) ) {
F_3 ( V_4 L_284
L_285 ) ;
F_240 () ;
}
V_47 = F_52 ( V_74 ) -> V_632 ( V_74 ) ;
if ( V_47 < 0 ) {
V_74 -> V_124 = V_47 ;
F_144 ( V_74 , NULL ,
0 , ( V_74 -> V_159 !=
V_162 ) ) ;
break;
}
case V_283 :
V_47 = F_254 ( V_74 ) ;
if ( V_47 < 0 ) {
V_74 -> V_124 = V_47 ;
F_144 ( V_74 , NULL ,
0 , ( V_74 -> V_159 !=
V_162 ) ) ;
}
break;
case V_286 :
F_256 ( V_74 ) ;
break;
case V_145 :
F_146 ( V_74 ) ;
F_211 ( V_74 ) ;
break;
case V_633 :
F_65 ( V_74 , 1 , 0 ) ;
break;
case V_288 :
F_259 ( V_74 , 0 , 1 , 0 ) ;
break;
case V_287 :
F_272 ( V_74 ) ;
break;
case V_142 :
F_144 ( V_74 , NULL , 1 , 1 ) ;
break;
case V_139 :
F_146 ( V_74 ) ;
F_157 ( V_74 ) ;
break;
default:
F_3 ( V_4 L_286
L_287
L_182 , V_86 , V_74 -> V_90 ,
F_52 ( V_74 ) -> F_57 ( V_74 ) ,
F_52 ( V_74 ) -> F_92 ( V_74 ) ,
F_61 ( V_74 ) -> V_584 ) ;
F_240 () ;
}
goto V_631;
}
V_16:
F_91 ( V_76 ) ;
V_76 -> V_242 = NULL ;
return 0 ;
}
