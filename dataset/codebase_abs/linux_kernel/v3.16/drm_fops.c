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
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 = 0 ;
V_11 = F_6 ( F_7 ( V_7 ) ) ;
if ( F_8 ( V_11 ) )
return F_9 ( V_11 ) ;
V_2 = V_11 -> V_2 ;
if ( ! V_2 -> V_14 ++ )
V_13 = 1 ;
V_9 -> V_15 = V_2 -> V_16 -> V_17 ;
V_12 = F_10 ( V_9 , V_11 ) ;
if ( V_12 )
goto V_18;
if ( V_13 ) {
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
goto V_18;
}
return 0 ;
V_18:
V_2 -> V_14 -- ;
F_11 ( V_11 ) ;
return V_12 ;
}
int F_12 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_19 = - V_20 ;
const struct V_21 * V_22 ;
F_4 ( L_1 ) ;
F_13 ( & V_23 ) ;
V_11 = F_6 ( F_7 ( V_7 ) ) ;
if ( F_8 ( V_11 ) )
goto V_24;
V_2 = V_11 -> V_2 ;
V_22 = F_14 ( V_2 -> V_4 -> V_25 ) ;
if ( ! V_22 )
goto V_26;
F_15 ( V_9 , V_22 ) ;
if ( V_9 -> V_27 -> V_28 )
V_19 = V_9 -> V_27 -> V_28 ( V_7 , V_9 ) ;
V_26:
F_11 ( V_11 ) ;
V_24:
F_16 ( & V_23 ) ;
return V_19 ;
}
static int F_17 ( void )
{
#if F_18 ( V_29 )
if ( V_30 . V_31 == 3 )
return 0 ;
#endif
#if F_18 ( V_32 ) && ! F_18 ( V_33 )
return 0 ;
#endif
return 1 ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_34 * V_35 ;
int V_3 ;
if ( V_9 -> V_36 & V_37 )
return - V_38 ;
if ( ! F_17 () )
return - V_39 ;
if ( V_2 -> V_40 != V_41 && V_2 -> V_40 != V_42 )
return - V_39 ;
F_4 ( L_2 , F_19 ( V_43 ) , V_11 -> V_44 ) ;
V_35 = F_20 ( sizeof( * V_35 ) , V_45 ) ;
if ( ! V_35 )
return - V_46 ;
V_9 -> V_47 = V_35 ;
V_35 -> V_9 = V_9 ;
V_35 -> V_48 = F_21 () ;
V_35 -> V_49 = F_22 ( F_23 ( V_43 ) ) ;
V_35 -> V_11 = V_11 ;
V_35 -> V_50 = F_24 ( V_51 ) ;
V_35 -> V_52 = V_35 -> V_50 ;
V_35 -> V_53 = 0 ;
F_25 ( & V_35 -> V_54 ) ;
F_25 ( & V_35 -> V_55 ) ;
F_26 ( & V_35 -> V_56 ) ;
F_25 ( & V_35 -> V_57 ) ;
F_27 ( & V_35 -> V_58 ) ;
V_35 -> V_59 = 4096 ;
if ( V_2 -> V_4 -> V_60 & V_61 )
F_28 ( V_2 , V_35 ) ;
if ( F_2 ( V_2 , V_62 ) )
F_29 ( & V_35 -> V_63 ) ;
if ( V_2 -> V_4 -> V_28 ) {
V_3 = V_2 -> V_4 -> V_28 ( V_2 , V_35 ) ;
if ( V_3 < 0 )
goto V_64;
}
F_13 ( & V_2 -> V_65 ) ;
if ( F_30 ( V_35 ) && ! V_35 -> V_11 -> V_66 ) {
V_35 -> V_11 -> V_66 = F_31 ( V_35 -> V_11 ) ;
if ( ! V_35 -> V_11 -> V_66 ) {
V_3 = - V_46 ;
goto V_67;
}
V_35 -> V_68 = 1 ;
V_35 -> V_66 = F_32 ( V_35 -> V_11 -> V_66 ) ;
V_35 -> V_52 = 1 ;
if ( V_2 -> V_4 -> V_69 ) {
V_3 = V_2 -> V_4 -> V_69 ( V_2 , V_35 -> V_66 ) ;
if ( V_3 ) {
F_33 ( & V_35 -> V_11 -> V_66 ) ;
F_33 ( & V_35 -> V_66 ) ;
goto V_67;
}
}
if ( V_2 -> V_4 -> V_70 ) {
V_3 = V_2 -> V_4 -> V_70 ( V_2 , V_35 , true ) ;
if ( V_3 ) {
F_33 ( & V_35 -> V_11 -> V_66 ) ;
F_33 ( & V_35 -> V_66 ) ;
goto V_67;
}
}
} else if ( F_30 ( V_35 ) ) {
V_35 -> V_66 = F_32 ( V_35 -> V_11 -> V_66 ) ;
}
F_16 ( & V_2 -> V_65 ) ;
F_13 ( & V_2 -> V_71 ) ;
F_34 ( & V_35 -> V_54 , & V_2 -> V_72 ) ;
F_16 ( & V_2 -> V_71 ) ;
#ifdef F_35
if ( ! V_2 -> V_73 ) {
struct V_74 * V_74 ;
V_74 = F_36 ( V_75 << 8 , NULL ) ;
if ( V_74 ) {
V_2 -> V_73 = V_74 -> V_76 ;
F_37 ( V_74 ) ;
}
if ( ! V_2 -> V_73 ) {
struct V_77 * V_78 = F_38 ( V_79 . V_80 ,
struct V_77 , V_81 ) ;
if ( V_78 )
V_2 -> V_73 = V_78 -> V_76 ;
}
}
#endif
return 0 ;
V_67:
F_16 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_4 -> V_82 )
V_2 -> V_4 -> V_82 ( V_2 , V_35 ) ;
V_64:
if ( F_2 ( V_2 , V_62 ) )
F_39 ( & V_35 -> V_63 ) ;
if ( V_2 -> V_4 -> V_60 & V_61 )
F_40 ( V_2 , V_35 ) ;
F_41 ( V_35 -> V_49 ) ;
F_42 ( V_35 ) ;
V_9 -> V_47 = NULL ;
return V_3 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_34 * V_83 = V_9 -> V_47 ;
if ( F_44 ( V_2 , V_83 ) ) {
F_4 ( L_3 ,
V_9 , F_45 ( V_83 -> V_66 -> V_84 . V_85 -> V_84 ) ) ;
F_46 ( & V_83 -> V_66 -> V_84 ,
F_45 ( V_83 -> V_66 -> V_84 . V_85 -> V_84 ) ) ;
}
}
static void F_47 ( struct V_34 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_11 -> V_2 ;
struct V_86 * V_87 , * V_88 ;
struct V_89 * V_90 , * V_91 ;
unsigned long V_92 ;
F_48 ( & V_2 -> V_93 , V_92 ) ;
F_49 (v, vt, &dev->vblank_event_list, base.link)
if ( V_90 -> V_94 . V_83 == V_83 ) {
F_50 ( & V_90 -> V_94 . V_95 ) ;
F_51 ( V_2 , V_90 -> V_96 ) ;
V_90 -> V_94 . V_97 ( & V_90 -> V_94 ) ;
}
F_49 (e, et, &file_priv->event_list, link) {
F_50 ( & V_87 -> V_95 ) ;
V_87 -> V_97 ( V_87 ) ;
}
F_52 ( & V_2 -> V_93 , V_92 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 ) )
return;
V_2 -> V_98 . V_84 = NULL ;
V_2 -> V_99 = 0 ;
V_2 -> V_100 = 0 ;
V_2 -> V_101 = 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_102 * V_103 , * V_104 ;
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_105 )
V_2 -> V_4 -> V_105 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( V_2 -> V_106 && ! F_2 ( V_2 , V_6 ) )
F_55 ( V_2 ) ;
F_13 ( & V_2 -> V_71 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_49 (vma, vma_temp, &dev->vmalist, head) {
F_50 ( & V_103 -> V_107 ) ;
F_42 ( V_103 ) ;
}
F_58 ( V_2 ) ;
F_16 ( & V_2 -> V_71 ) ;
F_53 ( V_2 ) ;
F_4 ( L_5 ) ;
return 0 ;
}
int F_59 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_34 * V_83 = V_9 -> V_47 ;
struct V_10 * V_11 = V_83 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_12 = 0 ;
F_13 ( & V_23 ) ;
F_4 ( L_6 , V_2 -> V_14 ) ;
if ( V_2 -> V_4 -> V_108 )
V_2 -> V_4 -> V_108 ( V_2 , V_83 ) ;
F_4 ( L_7 ,
F_19 ( V_43 ) ,
( long ) F_60 ( V_83 -> V_11 -> V_109 -> V_110 ) ,
V_2 -> V_14 ) ;
if ( V_83 -> V_111 )
( void ) F_61 ( V_83 -> V_66 , V_83 -> V_111 ) ;
if ( V_83 -> V_11 -> V_66 )
F_43 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_112 ) )
F_62 ( V_2 , V_83 ) ;
F_47 ( V_83 ) ;
if ( V_2 -> V_4 -> V_60 & V_6 )
F_63 ( V_83 ) ;
if ( V_2 -> V_4 -> V_60 & V_61 )
F_40 ( V_2 , V_83 ) ;
F_13 ( & V_2 -> V_113 ) ;
if ( ! F_64 ( & V_2 -> V_114 ) ) {
struct V_115 * V_116 , * V_117 ;
F_49 (pos, n, &dev->ctxlist, head) {
if ( V_116 -> V_118 == V_83 &&
V_116 -> V_119 != V_120 ) {
if ( V_2 -> V_4 -> V_121 )
V_2 -> V_4 -> V_121 ( V_2 ,
V_116 -> V_119 ) ;
F_65 ( V_2 , V_116 -> V_119 ) ;
F_50 ( & V_116 -> V_107 ) ;
F_42 ( V_116 ) ;
}
}
}
F_16 ( & V_2 -> V_113 ) ;
F_13 ( & V_2 -> V_65 ) ;
if ( V_83 -> V_68 ) {
struct V_122 * V_66 = V_83 -> V_66 ;
struct V_34 * V_123 ;
F_13 ( & V_2 -> V_71 ) ;
F_66 (temp, &dev->filelist, lhead) {
if ( ( V_123 -> V_66 == V_83 -> V_66 ) &&
( V_123 != V_83 ) )
V_123 -> V_52 = V_123 -> V_50 ;
}
if ( V_66 -> V_84 . V_85 ) {
if ( V_2 -> V_98 . V_84 == V_66 -> V_84 . V_85 )
V_2 -> V_98 . V_84 = NULL ;
V_66 -> V_84 . V_85 = NULL ;
V_66 -> V_84 . V_83 = NULL ;
F_67 ( & V_66 -> V_84 . V_124 ) ;
}
F_16 ( & V_2 -> V_71 ) ;
if ( V_83 -> V_11 -> V_66 == V_83 -> V_66 ) {
if ( V_2 -> V_4 -> V_125 )
V_2 -> V_4 -> V_125 ( V_2 , V_83 , true ) ;
F_33 ( & V_83 -> V_11 -> V_66 ) ;
}
}
if ( V_83 -> V_66 )
F_33 ( & V_83 -> V_66 ) ;
V_83 -> V_68 = 0 ;
F_16 ( & V_2 -> V_65 ) ;
F_13 ( & V_2 -> V_71 ) ;
F_50 ( & V_83 -> V_54 ) ;
F_16 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_4 -> V_82 )
V_2 -> V_4 -> V_82 ( V_2 , V_83 ) ;
if ( F_2 ( V_2 , V_62 ) )
F_39 ( & V_83 -> V_63 ) ;
F_41 ( V_83 -> V_49 ) ;
F_42 ( V_83 ) ;
if ( ! -- V_2 -> V_14 ) {
V_12 = F_54 ( V_2 ) ;
if ( F_68 ( V_2 ) )
F_69 ( V_2 ) ;
}
F_16 ( & V_23 ) ;
F_11 ( V_11 ) ;
return V_12 ;
}
static bool
F_70 ( struct V_34 * V_83 ,
T_1 V_126 , T_1 V_127 , struct V_86 * * V_128 )
{
struct V_1 * V_2 = V_83 -> V_11 -> V_2 ;
struct V_86 * V_87 ;
unsigned long V_92 ;
bool V_3 = false ;
F_48 ( & V_2 -> V_93 , V_92 ) ;
* V_128 = NULL ;
if ( F_64 ( & V_83 -> V_57 ) )
goto V_128;
V_87 = F_71 ( & V_83 -> V_57 ,
struct V_86 , V_95 ) ;
if ( V_87 -> V_129 -> V_130 + V_126 > V_127 )
goto V_128;
V_83 -> V_59 += V_87 -> V_129 -> V_130 ;
F_50 ( & V_87 -> V_95 ) ;
* V_128 = V_87 ;
V_3 = true ;
V_128:
F_52 ( & V_2 -> V_93 , V_92 ) ;
return V_3 ;
}
T_2 F_72 ( struct V_8 * V_9 , char T_3 * V_131 ,
T_1 V_132 , T_4 * V_133 )
{
struct V_34 * V_83 = V_9 -> V_47 ;
struct V_86 * V_87 ;
T_1 V_126 ;
T_2 V_3 ;
V_3 = F_73 ( V_83 -> V_58 ,
! F_64 ( & V_83 -> V_57 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_126 = 0 ;
while ( F_70 ( V_83 , V_126 , V_132 , & V_87 ) ) {
if ( F_74 ( V_131 + V_126 ,
V_87 -> V_129 , V_87 -> V_129 -> V_130 ) ) {
V_126 = - V_134 ;
break;
}
V_126 += V_87 -> V_129 -> V_130 ;
V_87 -> V_97 ( V_87 ) ;
}
return V_126 ;
}
unsigned int F_75 ( struct V_8 * V_9 , struct V_135 * V_136 )
{
struct V_34 * V_83 = V_9 -> V_47 ;
unsigned int V_137 = 0 ;
F_76 ( V_9 , & V_83 -> V_58 , V_136 ) ;
if ( ! F_64 ( & V_83 -> V_57 ) )
V_137 |= V_138 | V_139 ;
return V_137 ;
}
