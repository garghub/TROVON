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
static int F_12 ( void )
{
#if F_13 ( V_19 ) && ! F_13 ( V_20 )
return 0 ;
#endif
return 1 ;
}
int F_14 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_23 * V_24 ;
int V_3 ;
F_15 ( & V_2 -> V_25 ) ;
V_22 -> V_11 -> V_26 = F_16 ( V_22 -> V_11 ) ;
if ( ! V_22 -> V_11 -> V_26 )
return - V_27 ;
V_24 = V_22 -> V_26 ;
V_22 -> V_26 = F_17 ( V_22 -> V_11 -> V_26 ) ;
if ( V_2 -> V_4 -> V_28 ) {
V_3 = V_2 -> V_4 -> V_28 ( V_2 , V_22 -> V_26 ) ;
if ( V_3 )
goto V_29;
}
if ( V_2 -> V_4 -> V_30 ) {
V_3 = V_2 -> V_4 -> V_30 ( V_2 , V_22 , true ) ;
if ( V_3 )
goto V_29;
}
V_22 -> V_31 = 1 ;
V_22 -> V_32 = 1 ;
V_22 -> V_33 = 1 ;
if ( V_24 )
F_18 ( & V_24 ) ;
return 0 ;
V_29:
F_18 ( & V_22 -> V_11 -> V_26 ) ;
F_18 ( & V_22 -> V_26 ) ;
V_22 -> V_26 = V_24 ;
return V_3 ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_21 * V_34 ;
int V_3 ;
if ( V_9 -> V_35 & V_36 )
return - V_37 ;
if ( ! F_12 () )
return - V_38 ;
if ( V_2 -> V_39 != V_40 && V_2 -> V_39 != V_41 )
return - V_38 ;
F_4 ( L_2 , F_19 ( V_42 ) , V_11 -> V_43 ) ;
V_34 = F_20 ( sizeof( * V_34 ) , V_44 ) ;
if ( ! V_34 )
return - V_27 ;
V_9 -> V_45 = V_34 ;
V_34 -> V_9 = V_9 ;
V_34 -> V_46 = F_21 () ;
V_34 -> V_47 = F_22 ( F_23 ( V_42 ) ) ;
V_34 -> V_11 = V_11 ;
V_34 -> V_33 = F_24 ( V_48 ) ;
V_34 -> V_49 = 0 ;
F_25 ( & V_34 -> V_50 ) ;
F_25 ( & V_34 -> V_51 ) ;
F_26 ( & V_34 -> V_52 ) ;
F_25 ( & V_34 -> V_53 ) ;
F_25 ( & V_34 -> V_54 ) ;
F_27 ( & V_34 -> V_55 ) ;
V_34 -> V_56 = 4096 ;
if ( F_2 ( V_2 , V_57 ) )
F_28 ( V_2 , V_34 ) ;
if ( F_2 ( V_2 , V_58 ) )
F_29 ( & V_34 -> V_59 ) ;
if ( V_2 -> V_4 -> V_60 ) {
V_3 = V_2 -> V_4 -> V_60 ( V_2 , V_34 ) ;
if ( V_3 < 0 )
goto V_61;
}
F_30 ( & V_2 -> V_25 ) ;
if ( F_31 ( V_34 ) && ! V_34 -> V_11 -> V_26 ) {
V_3 = F_14 ( V_2 , V_34 ) ;
if ( V_3 )
goto V_62;
} else if ( F_31 ( V_34 ) ) {
V_34 -> V_26 = F_17 ( V_34 -> V_11 -> V_26 ) ;
}
F_32 ( & V_2 -> V_25 ) ;
F_30 ( & V_2 -> V_63 ) ;
F_33 ( & V_34 -> V_50 , & V_2 -> V_64 ) ;
F_32 ( & V_2 -> V_63 ) ;
#ifdef F_34
if ( ! V_2 -> V_65 ) {
struct V_66 * V_66 ;
V_66 = F_35 ( V_67 << 8 , NULL ) ;
if ( V_66 ) {
V_2 -> V_65 = V_66 -> V_68 ;
F_36 ( V_66 ) ;
}
if ( ! V_2 -> V_65 ) {
struct V_69 * V_70 = F_37 ( V_71 . V_72 ,
struct V_69 , V_73 ) ;
if ( V_70 )
V_2 -> V_65 = V_70 -> V_68 ;
}
}
#endif
return 0 ;
V_62:
F_32 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_4 -> V_74 )
V_2 -> V_4 -> V_74 ( V_2 , V_34 ) ;
V_61:
if ( F_2 ( V_2 , V_58 ) )
F_38 ( & V_34 -> V_59 ) ;
if ( F_2 ( V_2 , V_57 ) )
F_39 ( V_2 , V_34 ) ;
F_40 ( V_34 -> V_47 ) ;
F_41 ( V_34 ) ;
V_9 -> V_45 = NULL ;
return V_3 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_21 * V_75 = V_9 -> V_45 ;
if ( F_43 ( V_2 , V_75 ) ) {
F_4 ( L_3 ,
V_9 , F_44 ( V_75 -> V_26 -> V_76 . V_77 -> V_76 ) ) ;
F_45 ( & V_75 -> V_26 -> V_76 ,
F_44 ( V_75 -> V_26 -> V_76 . V_77 -> V_76 ) ) ;
}
}
static void F_46 ( struct V_21 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_11 -> V_2 ;
struct V_78 * V_79 , * V_80 ;
struct V_81 * V_82 , * V_83 ;
unsigned long V_84 ;
F_47 ( & V_2 -> V_85 , V_84 ) ;
F_48 (v, vt, &dev->vblank_event_list, base.link)
if ( V_82 -> V_86 . V_75 == V_75 ) {
F_49 ( & V_82 -> V_86 . V_87 ) ;
F_50 ( V_2 , V_82 -> V_88 ) ;
V_82 -> V_86 . V_89 ( & V_82 -> V_86 ) ;
}
F_48 (e, et, &file_priv->event_list, link) {
F_49 ( & V_79 -> V_87 ) ;
V_79 -> V_89 ( V_79 ) ;
}
F_51 ( & V_2 -> V_85 , V_84 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 ) )
return;
V_2 -> V_90 . V_76 = NULL ;
V_2 -> V_91 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_93 = 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_94 )
V_2 -> V_4 -> V_94 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( V_2 -> V_95 && ! F_2 ( V_2 , V_6 ) )
F_54 ( V_2 ) ;
F_30 ( & V_2 -> V_63 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_32 ( & V_2 -> V_63 ) ;
F_52 ( V_2 ) ;
F_4 ( L_5 ) ;
return 0 ;
}
int F_59 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_21 * V_75 = V_9 -> V_45 ;
struct V_10 * V_11 = V_75 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_12 = 0 ;
F_30 ( & V_96 ) ;
F_4 ( L_6 , V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_63 ) ;
F_49 ( & V_75 -> V_50 ) ;
if ( V_75 -> V_97 )
F_60 ( & V_75 -> V_26 -> V_98 , V_75 -> V_97 ) ;
F_32 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_4 -> V_99 )
V_2 -> V_4 -> V_99 ( V_2 , V_75 ) ;
F_4 ( L_7 ,
F_19 ( V_42 ) ,
( long ) F_61 ( V_75 -> V_11 -> V_100 -> V_101 ) ,
V_2 -> V_14 ) ;
if ( V_75 -> V_11 -> V_26 )
F_42 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_102 ) )
F_62 ( V_2 , V_75 ) ;
F_46 ( V_75 ) ;
if ( F_2 ( V_2 , V_6 ) ) {
F_63 ( V_75 ) ;
F_64 ( V_2 , V_75 ) ;
}
if ( F_2 ( V_2 , V_57 ) )
F_39 ( V_2 , V_75 ) ;
F_65 ( V_2 , V_75 ) ;
F_30 ( & V_2 -> V_25 ) ;
if ( V_75 -> V_31 ) {
struct V_23 * V_26 = V_75 -> V_26 ;
F_30 ( & V_2 -> V_63 ) ;
if ( V_26 -> V_76 . V_77 ) {
if ( V_2 -> V_90 . V_76 == V_26 -> V_76 . V_77 )
V_2 -> V_90 . V_76 = NULL ;
V_26 -> V_76 . V_77 = NULL ;
V_26 -> V_76 . V_75 = NULL ;
F_66 ( & V_26 -> V_76 . V_103 ) ;
}
F_32 ( & V_2 -> V_63 ) ;
if ( V_75 -> V_11 -> V_26 == V_75 -> V_26 ) {
if ( V_2 -> V_4 -> V_104 )
V_2 -> V_4 -> V_104 ( V_2 , V_75 , true ) ;
F_18 ( & V_75 -> V_11 -> V_26 ) ;
}
}
if ( V_75 -> V_26 )
F_18 ( & V_75 -> V_26 ) ;
V_75 -> V_31 = 0 ;
F_32 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_4 -> V_74 )
V_2 -> V_4 -> V_74 ( V_2 , V_75 ) ;
if ( F_2 ( V_2 , V_58 ) )
F_38 ( & V_75 -> V_59 ) ;
F_67 ( ! F_68 ( & V_75 -> V_54 ) ) ;
F_40 ( V_75 -> V_47 ) ;
F_41 ( V_75 ) ;
if ( ! -- V_2 -> V_14 ) {
V_12 = F_53 ( V_2 ) ;
if ( F_69 ( V_2 ) )
F_70 ( V_2 ) ;
}
F_32 ( & V_96 ) ;
F_11 ( V_11 ) ;
return V_12 ;
}
T_1 F_71 ( struct V_8 * V_9 , char T_2 * V_105 ,
T_3 V_106 , T_4 * V_107 )
{
struct V_21 * V_75 = V_9 -> V_45 ;
struct V_1 * V_2 = V_75 -> V_11 -> V_2 ;
T_1 V_3 = 0 ;
if ( ! F_72 ( V_108 , V_105 , V_106 ) )
return - V_109 ;
F_73 ( & V_2 -> V_85 ) ;
for (; ; ) {
if ( F_68 ( & V_75 -> V_54 ) ) {
if ( V_3 )
break;
if ( V_9 -> V_35 & V_110 ) {
V_3 = - V_111 ;
break;
}
F_74 ( & V_2 -> V_85 ) ;
V_3 = F_75 ( V_75 -> V_55 ,
! F_68 ( & V_75 -> V_54 ) ) ;
F_73 ( & V_2 -> V_85 ) ;
if ( V_3 < 0 )
break;
V_3 = 0 ;
} else {
struct V_78 * V_79 ;
V_79 = F_76 ( & V_75 -> V_54 ,
struct V_78 , V_87 ) ;
if ( V_79 -> V_112 -> V_113 + V_3 > V_106 )
break;
if ( F_77 ( V_105 + V_3 ,
V_79 -> V_112 , V_79 -> V_112 -> V_113 ) ) {
if ( V_3 == 0 )
V_3 = - V_109 ;
break;
}
V_75 -> V_56 += V_79 -> V_112 -> V_113 ;
V_3 += V_79 -> V_112 -> V_113 ;
F_49 ( & V_79 -> V_87 ) ;
V_79 -> V_89 ( V_79 ) ;
}
}
F_74 ( & V_2 -> V_85 ) ;
return V_3 ;
}
unsigned int F_78 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
struct V_21 * V_75 = V_9 -> V_45 ;
unsigned int V_116 = 0 ;
F_79 ( V_9 , & V_75 -> V_55 , V_115 ) ;
if ( ! F_68 ( & V_75 -> V_54 ) )
V_116 |= V_117 | V_118 ;
return V_116 ;
}
