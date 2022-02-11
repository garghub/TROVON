static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 -> V_5 &&
! F_2 ( V_2 , V_6 ) ) {
V_3 = V_2 -> V_4 -> V_5 ( V_2 ) ;
if ( V_3 != 0 )
return V_3 ;
}
V_3 = F_3 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_4 ( L_1 ) ;
return 0 ;
}
int F_5 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
int V_10 = F_6 ( V_7 ) ;
struct V_11 * V_12 ;
int V_13 = 0 ;
int V_14 = 0 ;
struct V_15 * V_16 ;
struct V_15 * V_17 ;
V_12 = F_7 ( & V_18 , V_10 ) ;
if ( ! V_12 )
return - V_19 ;
if ( ! ( V_2 = V_12 -> V_2 ) )
return - V_19 ;
if ( F_8 ( V_2 ) )
return - V_19 ;
if ( ! V_2 -> V_20 ++ )
V_14 = 1 ;
F_9 ( & V_2 -> V_21 ) ;
V_17 = V_7 -> V_22 ;
V_16 = V_2 -> V_23 ;
if ( V_16 == NULL )
V_2 -> V_23 = & V_7 -> V_24 ;
F_10 ( F_11 ( V_2 -> V_23 , struct V_7 , V_24 ) ) ;
V_7 -> V_22 = V_2 -> V_23 ;
V_9 -> V_25 = V_2 -> V_23 ;
F_12 ( & V_2 -> V_21 ) ;
V_13 = F_13 ( V_7 , V_9 , V_2 ) ;
if ( V_13 )
goto V_26;
if ( V_14 ) {
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
goto V_26;
}
return 0 ;
V_26:
F_9 ( & V_2 -> V_21 ) ;
V_9 -> V_25 = V_17 ;
V_7 -> V_22 = V_17 ;
F_14 ( F_11 ( V_2 -> V_23 , struct V_7 , V_24 ) ) ;
V_2 -> V_23 = V_16 ;
F_12 ( & V_2 -> V_21 ) ;
V_2 -> V_20 -- ;
return V_13 ;
}
int F_15 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 ;
int V_10 = F_6 ( V_7 ) ;
int V_27 = - V_19 ;
const struct V_28 * V_29 ;
F_4 ( L_1 ) ;
F_9 ( & V_30 ) ;
V_12 = F_7 ( & V_18 , V_10 ) ;
if ( ! V_12 )
goto V_31;
if ( ! ( V_2 = V_12 -> V_2 ) )
goto V_31;
if ( F_8 ( V_2 ) )
goto V_31;
V_29 = F_16 ( V_2 -> V_4 -> V_32 ) ;
if ( ! V_29 )
goto V_31;
F_17 ( V_9 , V_29 ) ;
if ( V_9 -> V_33 -> V_34 )
V_27 = V_9 -> V_33 -> V_34 ( V_7 , V_9 ) ;
V_31:
F_12 ( & V_30 ) ;
return V_27 ;
}
static int F_18 ( void )
{
#if F_19 ( V_35 )
if ( V_36 . V_37 == 3 )
return 0 ;
#endif
#if F_19 ( V_38 ) && ! F_19 ( V_39 )
return 0 ;
#endif
return 1 ;
}
static int F_13 ( struct V_7 * V_7 , struct V_8 * V_9 ,
struct V_1 * V_2 )
{
int V_10 = F_6 ( V_7 ) ;
struct V_40 * V_41 ;
int V_3 ;
if ( V_9 -> V_42 & V_43 )
return - V_44 ;
if ( ! F_18 () )
return - V_45 ;
if ( V_2 -> V_46 != V_47 && V_2 -> V_46 != V_48 )
return - V_45 ;
F_4 ( L_2 , F_20 ( V_49 ) , V_10 ) ;
V_41 = F_21 ( sizeof( * V_41 ) , V_50 ) ;
if ( ! V_41 )
return - V_51 ;
V_9 -> V_52 = V_41 ;
V_41 -> V_9 = V_9 ;
V_41 -> V_53 = F_22 () ;
V_41 -> V_54 = F_23 ( F_24 ( V_49 ) ) ;
V_41 -> V_12 = F_7 ( & V_18 , V_10 ) ;
if ( ! V_41 -> V_12 ) {
V_3 = - V_19 ;
goto V_55;
}
V_41 -> V_56 = 0 ;
V_41 -> V_57 = F_25 ( V_58 ) ;
V_41 -> V_59 = V_41 -> V_57 ;
V_41 -> V_60 = 0 ;
F_26 ( & V_41 -> V_61 ) ;
F_26 ( & V_41 -> V_62 ) ;
F_27 ( & V_41 -> V_63 ) ;
F_26 ( & V_41 -> V_64 ) ;
F_28 ( & V_41 -> V_65 ) ;
V_41 -> V_66 = 4096 ;
if ( V_2 -> V_4 -> V_67 & V_68 )
F_29 ( V_2 , V_41 ) ;
if ( F_2 ( V_2 , V_69 ) )
F_30 ( & V_41 -> V_70 ) ;
if ( V_2 -> V_4 -> V_34 ) {
V_3 = V_2 -> V_4 -> V_34 ( V_2 , V_41 ) ;
if ( V_3 < 0 )
goto V_71;
}
F_9 ( & V_2 -> V_21 ) ;
if ( ! V_41 -> V_12 -> V_72 && ! F_31 ( V_41 ) ) {
V_41 -> V_12 -> V_72 = F_32 ( V_41 -> V_12 ) ;
if ( ! V_41 -> V_12 -> V_72 ) {
F_12 ( & V_2 -> V_21 ) ;
V_3 = - V_51 ;
goto V_73;
}
V_41 -> V_74 = 1 ;
V_41 -> V_72 = F_33 ( V_41 -> V_12 -> V_72 ) ;
V_41 -> V_59 = 1 ;
F_12 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_75 ) {
V_3 = V_2 -> V_4 -> V_75 ( V_2 , V_41 -> V_72 ) ;
if ( V_3 ) {
F_9 ( & V_2 -> V_21 ) ;
F_34 ( & V_41 -> V_12 -> V_72 ) ;
F_34 ( & V_41 -> V_72 ) ;
F_12 ( & V_2 -> V_21 ) ;
goto V_73;
}
}
F_9 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_76 ) {
V_3 = V_2 -> V_4 -> V_76 ( V_2 , V_41 , true ) ;
if ( V_3 ) {
F_34 ( & V_41 -> V_12 -> V_72 ) ;
F_34 ( & V_41 -> V_72 ) ;
F_12 ( & V_2 -> V_21 ) ;
goto V_73;
}
}
} else if ( ! F_31 ( V_41 ) ) {
V_41 -> V_72 = F_33 ( V_41 -> V_12 -> V_72 ) ;
}
F_12 ( & V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_21 ) ;
F_35 ( & V_41 -> V_61 , & V_2 -> V_77 ) ;
F_12 ( & V_2 -> V_21 ) ;
#ifdef F_36
if ( ! V_2 -> V_78 ) {
struct V_79 * V_79 ;
V_79 = F_37 ( V_80 << 8 , NULL ) ;
if ( V_79 ) {
V_2 -> V_78 = V_79 -> V_81 ;
F_38 ( V_79 ) ;
}
if ( ! V_2 -> V_78 ) {
struct V_82 * V_83 = F_39 ( V_84 . V_85 ) ;
if ( V_83 )
V_2 -> V_78 = V_83 -> V_81 ;
}
}
#endif
return 0 ;
V_73:
if ( V_2 -> V_4 -> V_86 )
V_2 -> V_4 -> V_86 ( V_2 , V_41 ) ;
V_71:
if ( F_2 ( V_2 , V_69 ) )
F_40 ( & V_41 -> V_70 ) ;
if ( V_2 -> V_4 -> V_67 & V_68 )
F_41 ( V_2 , V_41 ) ;
V_55:
F_42 ( V_41 -> V_54 ) ;
F_43 ( V_41 ) ;
V_9 -> V_52 = NULL ;
return V_3 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_40 * V_87 = V_9 -> V_52 ;
if ( F_45 ( V_2 , V_87 ) ) {
F_4 ( L_3 ,
V_9 , F_46 ( V_87 -> V_72 -> V_88 . V_89 -> V_88 ) ) ;
F_47 ( & V_87 -> V_72 -> V_88 ,
F_46 ( V_87 -> V_72 -> V_88 . V_89 -> V_88 ) ) ;
}
}
static void F_48 ( struct V_40 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_12 -> V_2 ;
struct V_90 * V_91 , * V_92 ;
struct V_93 * V_94 , * V_95 ;
unsigned long V_96 ;
F_49 ( & V_2 -> V_97 , V_96 ) ;
F_50 (v, vt, &dev->vblank_event_list, base.link)
if ( V_94 -> V_98 . V_87 == V_87 ) {
F_51 ( & V_94 -> V_98 . V_99 ) ;
F_52 ( V_2 , V_94 -> V_100 ) ;
V_94 -> V_98 . V_101 ( & V_94 -> V_98 ) ;
}
F_50 (e, et, &file_priv->event_list, link) {
F_51 ( & V_91 -> V_99 ) ;
V_91 -> V_101 ( V_91 ) ;
}
F_53 ( & V_2 -> V_97 , V_96 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 ) )
return;
F_55 ( & V_2 -> V_56 , 0 ) ;
F_55 ( & V_2 -> V_102 , 0 ) ;
V_2 -> V_103 . V_88 = NULL ;
V_2 -> V_104 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_107 * V_108 , * V_109 ;
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_110 )
V_2 -> V_4 -> V_110 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( V_2 -> V_111 && ! F_2 ( V_2 , V_6 ) )
F_57 ( V_2 ) ;
F_9 ( & V_2 -> V_21 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_50 (vma, vma_temp, &dev->vmalist, head) {
F_51 ( & V_108 -> V_112 ) ;
F_43 ( V_108 ) ;
}
F_60 ( V_2 ) ;
V_2 -> V_23 = NULL ;
F_12 ( & V_2 -> V_21 ) ;
F_54 ( V_2 ) ;
F_4 ( L_5 ) ;
return 0 ;
}
int F_61 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_40 * V_87 = V_9 -> V_52 ;
struct V_1 * V_2 = V_87 -> V_12 -> V_2 ;
int V_13 = 0 ;
F_9 ( & V_30 ) ;
F_4 ( L_6 , V_2 -> V_20 ) ;
if ( V_2 -> V_4 -> V_113 )
V_2 -> V_4 -> V_113 ( V_2 , V_87 ) ;
F_4 ( L_7 ,
F_20 ( V_49 ) ,
( long ) F_62 ( V_87 -> V_12 -> V_114 ) ,
V_2 -> V_20 ) ;
if ( V_87 -> V_115 )
( void ) F_63 ( V_87 -> V_72 , V_87 -> V_115 ) ;
if ( V_87 -> V_12 -> V_72 )
F_44 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_116 ) )
F_64 ( V_2 , V_87 ) ;
F_48 ( V_87 ) ;
if ( V_2 -> V_4 -> V_67 & V_6 )
F_65 ( V_87 ) ;
if ( V_2 -> V_4 -> V_67 & V_68 )
F_41 ( V_2 , V_87 ) ;
F_9 ( & V_2 -> V_117 ) ;
if ( ! F_66 ( & V_2 -> V_118 ) ) {
struct V_119 * V_120 , * V_121 ;
F_50 (pos, n, &dev->ctxlist, head) {
if ( V_120 -> V_122 == V_87 &&
V_120 -> V_123 != V_124 ) {
if ( V_2 -> V_4 -> V_125 )
V_2 -> V_4 -> V_125 ( V_2 ,
V_120 -> V_123 ) ;
F_67 ( V_2 , V_120 -> V_123 ) ;
F_51 ( & V_120 -> V_112 ) ;
F_43 ( V_120 ) ;
}
}
}
F_12 ( & V_2 -> V_117 ) ;
F_9 ( & V_2 -> V_21 ) ;
if ( V_87 -> V_74 ) {
struct V_126 * V_72 = V_87 -> V_72 ;
struct V_40 * V_127 ;
F_68 (temp, &dev->filelist, lhead) {
if ( ( V_127 -> V_72 == V_87 -> V_72 ) &&
( V_127 != V_87 ) )
V_127 -> V_59 = V_127 -> V_57 ;
}
if ( V_72 -> V_88 . V_89 ) {
if ( V_2 -> V_103 . V_88 == V_72 -> V_88 . V_89 )
V_2 -> V_103 . V_88 = NULL ;
V_72 -> V_88 . V_89 = NULL ;
V_72 -> V_88 . V_87 = NULL ;
F_69 ( & V_72 -> V_88 . V_128 ) ;
}
if ( V_87 -> V_12 -> V_72 == V_87 -> V_72 ) {
if ( V_2 -> V_4 -> V_129 )
V_2 -> V_4 -> V_129 ( V_2 , V_87 , true ) ;
F_34 ( & V_87 -> V_12 -> V_72 ) ;
}
}
F_70 ( V_2 -> V_23 == NULL ) ;
F_14 ( F_11 ( V_2 -> V_23 , struct V_7 , V_24 ) ) ;
if ( V_87 -> V_72 )
F_34 ( & V_87 -> V_72 ) ;
V_87 -> V_74 = 0 ;
F_51 ( & V_87 -> V_61 ) ;
F_12 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_86 )
V_2 -> V_4 -> V_86 ( V_2 , V_87 ) ;
if ( F_2 ( V_2 , V_69 ) )
F_40 ( & V_87 -> V_70 ) ;
F_42 ( V_87 -> V_54 ) ;
F_43 ( V_87 ) ;
if ( ! -- V_2 -> V_20 ) {
if ( F_71 ( & V_2 -> V_56 ) ) {
F_72 ( L_8 ,
F_71 ( & V_2 -> V_56 ) ) ;
V_13 = - V_44 ;
} else
V_13 = F_56 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_73 ( V_2 ) ;
}
F_12 ( & V_30 ) ;
return V_13 ;
}
static bool
F_74 ( struct V_40 * V_87 ,
T_1 V_130 , T_1 V_131 , struct V_90 * * V_31 )
{
struct V_1 * V_2 = V_87 -> V_12 -> V_2 ;
struct V_90 * V_91 ;
unsigned long V_96 ;
bool V_3 = false ;
F_49 ( & V_2 -> V_97 , V_96 ) ;
* V_31 = NULL ;
if ( F_66 ( & V_87 -> V_64 ) )
goto V_31;
V_91 = F_75 ( & V_87 -> V_64 ,
struct V_90 , V_99 ) ;
if ( V_91 -> V_132 -> V_133 + V_130 > V_131 )
goto V_31;
V_87 -> V_66 += V_91 -> V_132 -> V_133 ;
F_51 ( & V_91 -> V_99 ) ;
* V_31 = V_91 ;
V_3 = true ;
V_31:
F_53 ( & V_2 -> V_97 , V_96 ) ;
return V_3 ;
}
T_2 F_76 ( struct V_8 * V_9 , char T_3 * V_134 ,
T_1 V_135 , T_4 * V_136 )
{
struct V_40 * V_87 = V_9 -> V_52 ;
struct V_90 * V_91 ;
T_1 V_130 ;
T_2 V_3 ;
V_3 = F_77 ( V_87 -> V_65 ,
! F_66 ( & V_87 -> V_64 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_130 = 0 ;
while ( F_74 ( V_87 , V_130 , V_135 , & V_91 ) ) {
if ( F_78 ( V_134 + V_130 ,
V_91 -> V_132 , V_91 -> V_132 -> V_133 ) ) {
V_130 = - V_137 ;
break;
}
V_130 += V_91 -> V_132 -> V_133 ;
V_91 -> V_101 ( V_91 ) ;
}
return V_130 ;
}
unsigned int F_79 ( struct V_8 * V_9 , struct V_138 * V_139 )
{
struct V_40 * V_87 = V_9 -> V_52 ;
unsigned int V_140 = 0 ;
F_80 ( V_9 , & V_87 -> V_65 , V_139 ) ;
if ( ! F_66 ( & V_87 -> V_64 ) )
V_140 |= V_141 | V_142 ;
return V_140 ;
}
