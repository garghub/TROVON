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
F_14 ( & V_2 -> V_27 [ V_28 ] ) ;
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
F_15 ( F_11 ( V_2 -> V_23 , struct V_7 , V_24 ) ) ;
V_2 -> V_23 = V_16 ;
F_12 ( & V_2 -> V_21 ) ;
V_2 -> V_20 -- ;
return V_13 ;
}
int F_16 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 ;
int V_10 = F_6 ( V_7 ) ;
int V_29 = - V_19 ;
const struct V_30 * V_31 ;
F_4 ( L_1 ) ;
F_9 ( & V_32 ) ;
V_12 = F_7 ( & V_18 , V_10 ) ;
if ( ! V_12 )
goto V_33;
if ( ! ( V_2 = V_12 -> V_2 ) )
goto V_33;
if ( F_8 ( V_2 ) )
goto V_33;
V_31 = V_9 -> V_34 ;
V_9 -> V_34 = F_17 ( V_2 -> V_4 -> V_35 ) ;
if ( V_9 -> V_34 == NULL ) {
V_9 -> V_34 = V_31 ;
goto V_33;
}
if ( V_9 -> V_34 -> V_36 && ( V_29 = V_9 -> V_34 -> V_36 ( V_7 , V_9 ) ) ) {
F_18 ( V_9 -> V_34 ) ;
V_9 -> V_34 = F_17 ( V_31 ) ;
}
F_18 ( V_31 ) ;
V_33:
F_12 ( & V_32 ) ;
return V_29 ;
}
static int F_19 ( void )
{
#if F_20 ( V_37 )
if ( V_38 . V_39 == 3 )
return 0 ;
#endif
#if F_20 ( V_40 ) && ! F_20 ( V_41 )
return 0 ;
#endif
return 1 ;
}
static int F_13 ( struct V_7 * V_7 , struct V_8 * V_9 ,
struct V_1 * V_2 )
{
int V_10 = F_6 ( V_7 ) ;
struct V_42 * V_43 ;
int V_3 ;
if ( V_9 -> V_44 & V_45 )
return - V_46 ;
if ( ! F_19 () )
return - V_47 ;
if ( V_2 -> V_48 != V_49 && V_2 -> V_48 != V_50 )
return - V_47 ;
F_4 ( L_2 , F_21 ( V_51 ) , V_10 ) ;
V_43 = F_22 ( sizeof( * V_43 ) , V_52 ) ;
if ( ! V_43 )
return - V_53 ;
V_9 -> V_54 = V_43 ;
V_43 -> V_9 = V_9 ;
V_43 -> V_55 = F_23 () ;
V_43 -> V_56 = F_24 ( F_25 ( V_51 ) ) ;
V_43 -> V_12 = F_7 ( & V_18 , V_10 ) ;
if ( ! V_43 -> V_12 ) {
V_3 = - V_19 ;
goto V_57;
}
V_43 -> V_58 = 0 ;
V_43 -> V_59 = F_26 ( V_60 ) ;
V_43 -> V_61 = 0 ;
F_27 ( & V_43 -> V_62 ) ;
F_27 ( & V_43 -> V_63 ) ;
F_28 ( & V_43 -> V_64 ) ;
F_27 ( & V_43 -> V_65 ) ;
F_29 ( & V_43 -> V_66 ) ;
V_43 -> V_67 = 4096 ;
if ( V_2 -> V_4 -> V_68 & V_69 )
F_30 ( V_2 , V_43 ) ;
if ( F_2 ( V_2 , V_70 ) )
F_31 ( & V_43 -> V_71 ) ;
if ( V_2 -> V_4 -> V_36 ) {
V_3 = V_2 -> V_4 -> V_36 ( V_2 , V_43 ) ;
if ( V_3 < 0 )
goto V_72;
}
F_9 ( & V_2 -> V_21 ) ;
if ( ! V_43 -> V_12 -> V_73 && ! F_32 ( V_43 ) ) {
V_43 -> V_12 -> V_73 = F_33 ( V_43 -> V_12 ) ;
if ( ! V_43 -> V_12 -> V_73 ) {
F_12 ( & V_2 -> V_21 ) ;
V_3 = - V_53 ;
goto V_74;
}
V_43 -> V_75 = 1 ;
V_43 -> V_73 = F_34 ( V_43 -> V_12 -> V_73 ) ;
V_43 -> V_59 = 1 ;
F_12 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_76 ) {
V_3 = V_2 -> V_4 -> V_76 ( V_2 , V_43 -> V_73 ) ;
if ( V_3 ) {
F_9 ( & V_2 -> V_21 ) ;
F_35 ( & V_43 -> V_12 -> V_73 ) ;
F_35 ( & V_43 -> V_73 ) ;
F_12 ( & V_2 -> V_21 ) ;
goto V_74;
}
}
F_9 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_77 ) {
V_3 = V_2 -> V_4 -> V_77 ( V_2 , V_43 , true ) ;
if ( V_3 ) {
F_35 ( & V_43 -> V_12 -> V_73 ) ;
F_35 ( & V_43 -> V_73 ) ;
F_12 ( & V_2 -> V_21 ) ;
goto V_74;
}
}
} else if ( ! F_32 ( V_43 ) ) {
V_43 -> V_73 = F_34 ( V_43 -> V_12 -> V_73 ) ;
}
F_12 ( & V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_21 ) ;
F_36 ( & V_43 -> V_62 , & V_2 -> V_78 ) ;
F_12 ( & V_2 -> V_21 ) ;
#ifdef F_37
if ( ! V_2 -> V_79 ) {
struct V_80 * V_80 ;
V_80 = F_38 ( V_81 << 8 , NULL ) ;
if ( V_80 ) {
V_2 -> V_79 = V_80 -> V_82 ;
F_39 ( V_80 ) ;
}
if ( ! V_2 -> V_79 ) {
struct V_83 * V_84 = F_40 ( V_85 . V_86 ) ;
if ( V_84 )
V_2 -> V_79 = V_84 -> V_82 ;
}
}
#endif
return 0 ;
V_74:
if ( V_2 -> V_4 -> V_87 )
V_2 -> V_4 -> V_87 ( V_2 , V_43 ) ;
V_72:
if ( F_2 ( V_2 , V_70 ) )
F_41 ( & V_43 -> V_71 ) ;
if ( V_2 -> V_4 -> V_68 & V_69 )
F_42 ( V_2 , V_43 ) ;
V_57:
F_43 ( V_43 -> V_56 ) ;
F_44 ( V_43 ) ;
V_9 -> V_54 = NULL ;
return V_3 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_42 * V_88 = V_9 -> V_54 ;
if ( F_46 ( V_2 , V_88 ) ) {
F_4 ( L_3 ,
V_9 , F_47 ( V_88 -> V_73 -> V_89 . V_90 -> V_89 ) ) ;
F_48 ( & V_88 -> V_73 -> V_89 ,
F_47 ( V_88 -> V_73 -> V_89 . V_90 -> V_89 ) ) ;
}
}
static void F_49 ( struct V_42 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_12 -> V_2 ;
struct V_91 * V_92 , * V_93 ;
struct V_94 * V_95 , * V_96 ;
unsigned long V_97 ;
F_50 ( & V_2 -> V_98 , V_97 ) ;
F_51 (v, vt, &dev->vblank_event_list, base.link)
if ( V_95 -> V_99 . V_88 == V_88 ) {
F_52 ( & V_95 -> V_99 . V_100 ) ;
F_53 ( V_2 , V_95 -> V_101 ) ;
V_95 -> V_99 . V_102 ( & V_95 -> V_99 ) ;
}
F_51 (e, et, &file_priv->event_list, link)
V_92 -> V_102 ( V_92 ) ;
F_54 ( & V_2 -> V_98 , V_97 ) ;
}
int F_55 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_42 * V_88 = V_9 -> V_54 ;
struct V_1 * V_2 = V_88 -> V_12 -> V_2 ;
int V_13 = 0 ;
F_9 ( & V_32 ) ;
F_4 ( L_4 , V_2 -> V_20 ) ;
if ( V_2 -> V_4 -> V_103 )
V_2 -> V_4 -> V_103 ( V_2 , V_88 ) ;
F_4 ( L_5 ,
F_21 ( V_51 ) ,
( long ) F_56 ( V_88 -> V_12 -> V_104 ) ,
V_2 -> V_20 ) ;
if ( V_88 -> V_105 )
( void ) F_57 ( V_88 -> V_73 , V_88 -> V_105 ) ;
if ( V_88 -> V_12 -> V_73 )
F_45 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_106 ) )
F_58 ( V_2 , V_88 ) ;
F_49 ( V_88 ) ;
if ( V_2 -> V_4 -> V_68 & V_6 )
F_59 ( V_88 ) ;
if ( V_2 -> V_4 -> V_68 & V_69 )
F_42 ( V_2 , V_88 ) ;
F_9 ( & V_2 -> V_107 ) ;
if ( ! F_60 ( & V_2 -> V_108 ) ) {
struct V_109 * V_110 , * V_111 ;
F_51 (pos, n, &dev->ctxlist, head) {
if ( V_110 -> V_112 == V_88 &&
V_110 -> V_113 != V_114 ) {
if ( V_2 -> V_4 -> V_115 )
V_2 -> V_4 -> V_115 ( V_2 ,
V_110 -> V_113 ) ;
F_61 ( V_2 , V_110 -> V_113 ) ;
F_52 ( & V_110 -> V_116 ) ;
F_44 ( V_110 ) ;
-- V_2 -> V_117 ;
}
}
}
F_12 ( & V_2 -> V_107 ) ;
F_9 ( & V_2 -> V_21 ) ;
if ( V_88 -> V_75 ) {
struct V_118 * V_73 = V_88 -> V_73 ;
struct V_42 * V_119 ;
F_62 (temp, &dev->filelist, lhead) {
if ( ( V_119 -> V_73 == V_88 -> V_73 ) &&
( V_119 != V_88 ) )
V_119 -> V_59 = 0 ;
}
if ( V_73 -> V_89 . V_90 ) {
if ( V_2 -> V_120 . V_89 == V_73 -> V_89 . V_90 )
V_2 -> V_120 . V_89 = NULL ;
V_73 -> V_89 . V_90 = NULL ;
V_73 -> V_89 . V_88 = NULL ;
F_63 ( & V_73 -> V_89 . V_121 ) ;
}
if ( V_88 -> V_12 -> V_73 == V_88 -> V_73 ) {
if ( V_2 -> V_4 -> V_122 )
V_2 -> V_4 -> V_122 ( V_2 , V_88 , true ) ;
F_35 ( & V_88 -> V_12 -> V_73 ) ;
}
}
F_64 ( V_2 -> V_23 == NULL ) ;
F_15 ( F_11 ( V_2 -> V_23 , struct V_7 , V_24 ) ) ;
if ( V_88 -> V_73 )
F_35 ( & V_88 -> V_73 ) ;
V_88 -> V_75 = 0 ;
F_52 ( & V_88 -> V_62 ) ;
F_12 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_4 -> V_87 )
V_2 -> V_4 -> V_87 ( V_2 , V_88 ) ;
if ( F_2 ( V_2 , V_70 ) )
F_41 ( & V_88 -> V_71 ) ;
F_43 ( V_88 -> V_56 ) ;
F_44 ( V_88 ) ;
F_14 ( & V_2 -> V_27 [ V_123 ] ) ;
if ( ! -- V_2 -> V_20 ) {
if ( F_65 ( & V_2 -> V_58 ) ) {
F_66 ( L_6 ,
F_65 ( & V_2 -> V_58 ) ) ;
V_13 = - V_46 ;
} else
V_13 = F_67 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_68 ( V_2 ) ;
}
F_12 ( & V_32 ) ;
return V_13 ;
}
static bool
F_69 ( struct V_42 * V_88 ,
T_1 V_124 , T_1 V_125 , struct V_91 * * V_33 )
{
struct V_1 * V_2 = V_88 -> V_12 -> V_2 ;
struct V_91 * V_92 ;
unsigned long V_97 ;
bool V_3 = false ;
F_50 ( & V_2 -> V_98 , V_97 ) ;
* V_33 = NULL ;
if ( F_60 ( & V_88 -> V_65 ) )
goto V_33;
V_92 = F_70 ( & V_88 -> V_65 ,
struct V_91 , V_100 ) ;
if ( V_92 -> V_126 -> V_127 + V_124 > V_125 )
goto V_33;
V_88 -> V_67 += V_92 -> V_126 -> V_127 ;
F_52 ( & V_92 -> V_100 ) ;
* V_33 = V_92 ;
V_3 = true ;
V_33:
F_54 ( & V_2 -> V_98 , V_97 ) ;
return V_3 ;
}
T_2 F_71 ( struct V_8 * V_9 , char T_3 * V_128 ,
T_1 V_129 , T_4 * V_130 )
{
struct V_42 * V_88 = V_9 -> V_54 ;
struct V_91 * V_92 ;
T_1 V_124 ;
T_2 V_3 ;
V_3 = F_72 ( V_88 -> V_66 ,
! F_60 ( & V_88 -> V_65 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_124 = 0 ;
while ( F_69 ( V_88 , V_124 , V_129 , & V_92 ) ) {
if ( F_73 ( V_128 + V_124 ,
V_92 -> V_126 , V_92 -> V_126 -> V_127 ) ) {
V_124 = - V_131 ;
break;
}
V_124 += V_92 -> V_126 -> V_127 ;
V_92 -> V_102 ( V_92 ) ;
}
return V_124 ;
}
unsigned int F_74 ( struct V_8 * V_9 , struct V_132 * V_133 )
{
struct V_42 * V_88 = V_9 -> V_54 ;
unsigned int V_134 = 0 ;
F_75 ( V_9 , & V_88 -> V_66 , V_133 ) ;
if ( ! F_60 ( & V_88 -> V_65 ) )
V_134 |= V_135 | V_136 ;
return V_134 ;
}
