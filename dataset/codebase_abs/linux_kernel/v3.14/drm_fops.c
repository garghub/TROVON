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
V_41 -> V_56 = F_25 ( V_57 ) ;
V_41 -> V_58 = V_41 -> V_56 ;
V_41 -> V_59 = 0 ;
F_26 ( & V_41 -> V_60 ) ;
F_26 ( & V_41 -> V_61 ) ;
F_27 ( & V_41 -> V_62 ) ;
F_26 ( & V_41 -> V_63 ) ;
F_28 ( & V_41 -> V_64 ) ;
V_41 -> V_65 = 4096 ;
if ( V_2 -> V_4 -> V_66 & V_67 )
F_29 ( V_2 , V_41 ) ;
if ( F_2 ( V_2 , V_68 ) )
F_30 ( & V_41 -> V_69 ) ;
if ( V_2 -> V_4 -> V_34 ) {
V_3 = V_2 -> V_4 -> V_34 ( V_2 , V_41 ) ;
if ( V_3 < 0 )
goto V_70;
}
F_9 ( & V_2 -> V_21 ) ;
if ( ! V_41 -> V_12 -> V_71 && ! F_31 ( V_41 ) ) {
V_41 -> V_12 -> V_71 = F_32 ( V_41 -> V_12 ) ;
if ( ! V_41 -> V_12 -> V_71 ) {
F_12 ( & V_2 -> V_21 ) ;
V_3 = - V_51 ;
goto V_72;
}
V_41 -> V_73 = 1 ;
V_41 -> V_71 = F_33 ( V_41 -> V_12 -> V_71 ) ;
V_41 -> V_58 = 1 ;
F_12 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_74 ) {
V_3 = V_2 -> V_4 -> V_74 ( V_2 , V_41 -> V_71 ) ;
if ( V_3 ) {
F_9 ( & V_2 -> V_21 ) ;
F_34 ( & V_41 -> V_12 -> V_71 ) ;
F_34 ( & V_41 -> V_71 ) ;
F_12 ( & V_2 -> V_21 ) ;
goto V_72;
}
}
F_9 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_75 ) {
V_3 = V_2 -> V_4 -> V_75 ( V_2 , V_41 , true ) ;
if ( V_3 ) {
F_34 ( & V_41 -> V_12 -> V_71 ) ;
F_34 ( & V_41 -> V_71 ) ;
F_12 ( & V_2 -> V_21 ) ;
goto V_72;
}
}
} else if ( ! F_31 ( V_41 ) ) {
V_41 -> V_71 = F_33 ( V_41 -> V_12 -> V_71 ) ;
}
F_12 ( & V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_21 ) ;
F_35 ( & V_41 -> V_60 , & V_2 -> V_76 ) ;
F_12 ( & V_2 -> V_21 ) ;
#ifdef F_36
if ( ! V_2 -> V_77 ) {
struct V_78 * V_78 ;
V_78 = F_37 ( V_79 << 8 , NULL ) ;
if ( V_78 ) {
V_2 -> V_77 = V_78 -> V_80 ;
F_38 ( V_78 ) ;
}
if ( ! V_2 -> V_77 ) {
struct V_81 * V_82 = F_39 ( V_83 . V_84 ) ;
if ( V_82 )
V_2 -> V_77 = V_82 -> V_80 ;
}
}
#endif
return 0 ;
V_72:
if ( V_2 -> V_4 -> V_85 )
V_2 -> V_4 -> V_85 ( V_2 , V_41 ) ;
V_70:
if ( F_2 ( V_2 , V_68 ) )
F_40 ( & V_41 -> V_69 ) ;
if ( V_2 -> V_4 -> V_66 & V_67 )
F_41 ( V_2 , V_41 ) ;
V_55:
F_42 ( V_41 -> V_54 ) ;
F_43 ( V_41 ) ;
V_9 -> V_52 = NULL ;
return V_3 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_40 * V_86 = V_9 -> V_52 ;
if ( F_45 ( V_2 , V_86 ) ) {
F_4 ( L_3 ,
V_9 , F_46 ( V_86 -> V_71 -> V_87 . V_88 -> V_87 ) ) ;
F_47 ( & V_86 -> V_71 -> V_87 ,
F_46 ( V_86 -> V_71 -> V_87 . V_88 -> V_87 ) ) ;
}
}
static void F_48 ( struct V_40 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_12 -> V_2 ;
struct V_89 * V_90 , * V_91 ;
struct V_92 * V_93 , * V_94 ;
unsigned long V_95 ;
F_49 ( & V_2 -> V_96 , V_95 ) ;
F_50 (v, vt, &dev->vblank_event_list, base.link)
if ( V_93 -> V_97 . V_86 == V_86 ) {
F_51 ( & V_93 -> V_97 . V_98 ) ;
F_52 ( V_2 , V_93 -> V_99 ) ;
V_93 -> V_97 . V_100 ( & V_93 -> V_97 ) ;
}
F_50 (e, et, &file_priv->event_list, link) {
F_51 ( & V_90 -> V_98 ) ;
V_90 -> V_100 ( V_90 ) ;
}
F_53 ( & V_2 -> V_96 , V_95 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 ) )
return;
V_2 -> V_101 . V_87 = NULL ;
V_2 -> V_102 = 0 ;
V_2 -> V_103 = 0 ;
V_2 -> V_104 = 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_105 * V_106 , * V_107 ;
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_108 )
V_2 -> V_4 -> V_108 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( V_2 -> V_109 && ! F_2 ( V_2 , V_6 ) )
F_56 ( V_2 ) ;
F_9 ( & V_2 -> V_21 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_50 (vma, vma_temp, &dev->vmalist, head) {
F_51 ( & V_106 -> V_110 ) ;
F_43 ( V_106 ) ;
}
F_59 ( V_2 ) ;
V_2 -> V_23 = NULL ;
F_12 ( & V_2 -> V_21 ) ;
F_54 ( V_2 ) ;
F_4 ( L_5 ) ;
return 0 ;
}
int F_60 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_40 * V_86 = V_9 -> V_52 ;
struct V_1 * V_2 = V_86 -> V_12 -> V_2 ;
int V_13 = 0 ;
F_9 ( & V_30 ) ;
F_4 ( L_6 , V_2 -> V_20 ) ;
if ( V_2 -> V_4 -> V_111 )
V_2 -> V_4 -> V_111 ( V_2 , V_86 ) ;
F_4 ( L_7 ,
F_20 ( V_49 ) ,
( long ) F_61 ( V_86 -> V_12 -> V_112 ) ,
V_2 -> V_20 ) ;
if ( V_86 -> V_113 )
( void ) F_62 ( V_86 -> V_71 , V_86 -> V_113 ) ;
if ( V_86 -> V_12 -> V_71 )
F_44 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_114 ) )
F_63 ( V_2 , V_86 ) ;
F_48 ( V_86 ) ;
if ( V_2 -> V_4 -> V_66 & V_6 )
F_64 ( V_86 ) ;
if ( V_2 -> V_4 -> V_66 & V_67 )
F_41 ( V_2 , V_86 ) ;
F_9 ( & V_2 -> V_115 ) ;
if ( ! F_65 ( & V_2 -> V_116 ) ) {
struct V_117 * V_118 , * V_119 ;
F_50 (pos, n, &dev->ctxlist, head) {
if ( V_118 -> V_120 == V_86 &&
V_118 -> V_121 != V_122 ) {
if ( V_2 -> V_4 -> V_123 )
V_2 -> V_4 -> V_123 ( V_2 ,
V_118 -> V_121 ) ;
F_66 ( V_2 , V_118 -> V_121 ) ;
F_51 ( & V_118 -> V_110 ) ;
F_43 ( V_118 ) ;
}
}
}
F_12 ( & V_2 -> V_115 ) ;
F_9 ( & V_2 -> V_21 ) ;
if ( V_86 -> V_73 ) {
struct V_124 * V_71 = V_86 -> V_71 ;
struct V_40 * V_125 ;
F_67 (temp, &dev->filelist, lhead) {
if ( ( V_125 -> V_71 == V_86 -> V_71 ) &&
( V_125 != V_86 ) )
V_125 -> V_58 = V_125 -> V_56 ;
}
if ( V_71 -> V_87 . V_88 ) {
if ( V_2 -> V_101 . V_87 == V_71 -> V_87 . V_88 )
V_2 -> V_101 . V_87 = NULL ;
V_71 -> V_87 . V_88 = NULL ;
V_71 -> V_87 . V_86 = NULL ;
F_68 ( & V_71 -> V_87 . V_126 ) ;
}
if ( V_86 -> V_12 -> V_71 == V_86 -> V_71 ) {
if ( V_2 -> V_4 -> V_127 )
V_2 -> V_4 -> V_127 ( V_2 , V_86 , true ) ;
F_34 ( & V_86 -> V_12 -> V_71 ) ;
}
}
F_69 ( V_2 -> V_23 == NULL ) ;
F_14 ( F_11 ( V_2 -> V_23 , struct V_7 , V_24 ) ) ;
if ( V_86 -> V_71 )
F_34 ( & V_86 -> V_71 ) ;
V_86 -> V_73 = 0 ;
F_51 ( & V_86 -> V_60 ) ;
F_12 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_85 )
V_2 -> V_4 -> V_85 ( V_2 , V_86 ) ;
if ( F_2 ( V_2 , V_68 ) )
F_40 ( & V_86 -> V_69 ) ;
F_42 ( V_86 -> V_54 ) ;
F_43 ( V_86 ) ;
if ( ! -- V_2 -> V_20 ) {
V_13 = F_55 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_70 ( V_2 ) ;
}
F_12 ( & V_30 ) ;
return V_13 ;
}
static bool
F_71 ( struct V_40 * V_86 ,
T_1 V_128 , T_1 V_129 , struct V_89 * * V_31 )
{
struct V_1 * V_2 = V_86 -> V_12 -> V_2 ;
struct V_89 * V_90 ;
unsigned long V_95 ;
bool V_3 = false ;
F_49 ( & V_2 -> V_96 , V_95 ) ;
* V_31 = NULL ;
if ( F_65 ( & V_86 -> V_63 ) )
goto V_31;
V_90 = F_72 ( & V_86 -> V_63 ,
struct V_89 , V_98 ) ;
if ( V_90 -> V_130 -> V_131 + V_128 > V_129 )
goto V_31;
V_86 -> V_65 += V_90 -> V_130 -> V_131 ;
F_51 ( & V_90 -> V_98 ) ;
* V_31 = V_90 ;
V_3 = true ;
V_31:
F_53 ( & V_2 -> V_96 , V_95 ) ;
return V_3 ;
}
T_2 F_73 ( struct V_8 * V_9 , char T_3 * V_132 ,
T_1 V_133 , T_4 * V_134 )
{
struct V_40 * V_86 = V_9 -> V_52 ;
struct V_89 * V_90 ;
T_1 V_128 ;
T_2 V_3 ;
V_3 = F_74 ( V_86 -> V_64 ,
! F_65 ( & V_86 -> V_63 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_128 = 0 ;
while ( F_71 ( V_86 , V_128 , V_133 , & V_90 ) ) {
if ( F_75 ( V_132 + V_128 ,
V_90 -> V_130 , V_90 -> V_130 -> V_131 ) ) {
V_128 = - V_135 ;
break;
}
V_128 += V_90 -> V_130 -> V_131 ;
V_90 -> V_100 ( V_90 ) ;
}
return V_128 ;
}
unsigned int F_76 ( struct V_8 * V_9 , struct V_136 * V_137 )
{
struct V_40 * V_86 = V_9 -> V_52 ;
unsigned int V_138 = 0 ;
F_77 ( V_9 , & V_86 -> V_64 , V_137 ) ;
if ( ! F_65 ( & V_86 -> V_63 ) )
V_138 |= V_139 | V_140 ;
return V_138 ;
}
