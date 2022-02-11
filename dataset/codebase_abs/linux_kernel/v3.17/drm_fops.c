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
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_21 * V_22 ;
int V_3 ;
if ( V_9 -> V_23 & V_24 )
return - V_25 ;
if ( ! F_12 () )
return - V_26 ;
if ( V_2 -> V_27 != V_28 && V_2 -> V_27 != V_29 )
return - V_26 ;
F_4 ( L_2 , F_14 ( V_30 ) , V_11 -> V_31 ) ;
V_22 = F_15 ( sizeof( * V_22 ) , V_32 ) ;
if ( ! V_22 )
return - V_33 ;
V_9 -> V_34 = V_22 ;
V_22 -> V_9 = V_9 ;
V_22 -> V_35 = F_16 () ;
V_22 -> V_36 = F_17 ( F_18 ( V_30 ) ) ;
V_22 -> V_11 = V_11 ;
V_22 -> V_37 = F_19 ( V_38 ) ;
V_22 -> V_39 = 0 ;
F_20 ( & V_22 -> V_40 ) ;
F_20 ( & V_22 -> V_41 ) ;
F_21 ( & V_22 -> V_42 ) ;
F_20 ( & V_22 -> V_43 ) ;
F_22 ( & V_22 -> V_44 ) ;
V_22 -> V_45 = 4096 ;
if ( V_2 -> V_4 -> V_46 & V_47 )
F_23 ( V_2 , V_22 ) ;
if ( F_2 ( V_2 , V_48 ) )
F_24 ( & V_22 -> V_49 ) ;
if ( V_2 -> V_4 -> V_50 ) {
V_3 = V_2 -> V_4 -> V_50 ( V_2 , V_22 ) ;
if ( V_3 < 0 )
goto V_51;
}
F_25 ( & V_2 -> V_52 ) ;
if ( F_26 ( V_22 ) && ! V_22 -> V_11 -> V_53 ) {
V_22 -> V_11 -> V_53 = F_27 ( V_22 -> V_11 ) ;
if ( ! V_22 -> V_11 -> V_53 ) {
V_3 = - V_33 ;
goto V_54;
}
V_22 -> V_55 = 1 ;
V_22 -> V_53 = F_28 ( V_22 -> V_11 -> V_53 ) ;
V_22 -> V_37 = 1 ;
if ( V_2 -> V_4 -> V_56 ) {
V_3 = V_2 -> V_4 -> V_56 ( V_2 , V_22 -> V_53 ) ;
if ( V_3 ) {
F_29 ( & V_22 -> V_11 -> V_53 ) ;
F_29 ( & V_22 -> V_53 ) ;
goto V_54;
}
}
if ( V_2 -> V_4 -> V_57 ) {
V_3 = V_2 -> V_4 -> V_57 ( V_2 , V_22 , true ) ;
if ( V_3 ) {
F_29 ( & V_22 -> V_11 -> V_53 ) ;
F_29 ( & V_22 -> V_53 ) ;
goto V_54;
}
}
} else if ( F_26 ( V_22 ) ) {
V_22 -> V_53 = F_28 ( V_22 -> V_11 -> V_53 ) ;
}
F_30 ( & V_2 -> V_52 ) ;
F_25 ( & V_2 -> V_58 ) ;
F_31 ( & V_22 -> V_40 , & V_2 -> V_59 ) ;
F_30 ( & V_2 -> V_58 ) ;
#ifdef F_32
if ( ! V_2 -> V_60 ) {
struct V_61 * V_61 ;
V_61 = F_33 ( V_62 << 8 , NULL ) ;
if ( V_61 ) {
V_2 -> V_60 = V_61 -> V_63 ;
F_34 ( V_61 ) ;
}
if ( ! V_2 -> V_60 ) {
struct V_64 * V_65 = F_35 ( V_66 . V_67 ,
struct V_64 , V_68 ) ;
if ( V_65 )
V_2 -> V_60 = V_65 -> V_63 ;
}
}
#endif
return 0 ;
V_54:
F_30 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_4 -> V_69 )
V_2 -> V_4 -> V_69 ( V_2 , V_22 ) ;
V_51:
if ( F_2 ( V_2 , V_48 ) )
F_36 ( & V_22 -> V_49 ) ;
if ( V_2 -> V_4 -> V_46 & V_47 )
F_37 ( V_2 , V_22 ) ;
F_38 ( V_22 -> V_36 ) ;
F_39 ( V_22 ) ;
V_9 -> V_34 = NULL ;
return V_3 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_21 * V_70 = V_9 -> V_34 ;
if ( F_41 ( V_2 , V_70 ) ) {
F_4 ( L_3 ,
V_9 , F_42 ( V_70 -> V_53 -> V_71 . V_72 -> V_71 ) ) ;
F_43 ( & V_70 -> V_53 -> V_71 ,
F_42 ( V_70 -> V_53 -> V_71 . V_72 -> V_71 ) ) ;
}
}
static void F_44 ( struct V_21 * V_70 )
{
struct V_1 * V_2 = V_70 -> V_11 -> V_2 ;
struct V_73 * V_74 , * V_75 ;
struct V_76 * V_77 , * V_78 ;
unsigned long V_79 ;
F_45 ( & V_2 -> V_80 , V_79 ) ;
F_46 (v, vt, &dev->vblank_event_list, base.link)
if ( V_77 -> V_81 . V_70 == V_70 ) {
F_47 ( & V_77 -> V_81 . V_82 ) ;
F_48 ( V_2 , V_77 -> V_83 ) ;
V_77 -> V_81 . V_84 ( & V_77 -> V_81 ) ;
}
F_46 (e, et, &file_priv->event_list, link) {
F_47 ( & V_74 -> V_82 ) ;
V_74 -> V_84 ( V_74 ) ;
}
F_49 ( & V_2 -> V_80 , V_79 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 ) )
return;
V_2 -> V_85 . V_71 = NULL ;
V_2 -> V_86 = 0 ;
V_2 -> V_87 = 0 ;
V_2 -> V_88 = 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_89 * V_90 , * V_91 ;
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_92 )
V_2 -> V_4 -> V_92 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( V_2 -> V_93 && ! F_2 ( V_2 , V_6 ) )
F_52 ( V_2 ) ;
F_25 ( & V_2 -> V_58 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_46 (vma, vma_temp, &dev->vmalist, head) {
F_47 ( & V_90 -> V_94 ) ;
F_39 ( V_90 ) ;
}
F_55 ( V_2 ) ;
F_30 ( & V_2 -> V_58 ) ;
F_50 ( V_2 ) ;
F_4 ( L_5 ) ;
return 0 ;
}
int F_56 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_21 * V_70 = V_9 -> V_34 ;
struct V_10 * V_11 = V_70 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_12 = 0 ;
F_25 ( & V_95 ) ;
F_4 ( L_6 , V_2 -> V_14 ) ;
F_25 ( & V_2 -> V_58 ) ;
F_47 ( & V_70 -> V_40 ) ;
F_30 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_4 -> V_96 )
V_2 -> V_4 -> V_96 ( V_2 , V_70 ) ;
F_4 ( L_7 ,
F_14 ( V_30 ) ,
( long ) F_57 ( V_70 -> V_11 -> V_97 -> V_98 ) ,
V_2 -> V_14 ) ;
if ( V_70 -> V_99 )
( void ) F_58 ( V_70 -> V_53 , V_70 -> V_99 ) ;
if ( V_70 -> V_11 -> V_53 )
F_40 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_100 ) )
F_59 ( V_2 , V_70 ) ;
F_44 ( V_70 ) ;
if ( V_2 -> V_4 -> V_46 & V_6 )
F_60 ( V_70 ) ;
if ( V_2 -> V_4 -> V_46 & V_47 )
F_37 ( V_2 , V_70 ) ;
F_61 ( V_2 , V_70 ) ;
F_25 ( & V_2 -> V_52 ) ;
if ( V_70 -> V_55 ) {
struct V_101 * V_53 = V_70 -> V_53 ;
F_25 ( & V_2 -> V_58 ) ;
if ( V_53 -> V_71 . V_72 ) {
if ( V_2 -> V_85 . V_71 == V_53 -> V_71 . V_72 )
V_2 -> V_85 . V_71 = NULL ;
V_53 -> V_71 . V_72 = NULL ;
V_53 -> V_71 . V_70 = NULL ;
F_62 ( & V_53 -> V_71 . V_102 ) ;
}
F_30 ( & V_2 -> V_58 ) ;
if ( V_70 -> V_11 -> V_53 == V_70 -> V_53 ) {
if ( V_2 -> V_4 -> V_103 )
V_2 -> V_4 -> V_103 ( V_2 , V_70 , true ) ;
F_29 ( & V_70 -> V_11 -> V_53 ) ;
}
}
if ( V_70 -> V_53 )
F_29 ( & V_70 -> V_53 ) ;
V_70 -> V_55 = 0 ;
F_30 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_4 -> V_69 )
V_2 -> V_4 -> V_69 ( V_2 , V_70 ) ;
if ( F_2 ( V_2 , V_48 ) )
F_36 ( & V_70 -> V_49 ) ;
F_38 ( V_70 -> V_36 ) ;
F_39 ( V_70 ) ;
if ( ! -- V_2 -> V_14 ) {
V_12 = F_51 ( V_2 ) ;
if ( F_63 ( V_2 ) )
F_64 ( V_2 ) ;
}
F_30 ( & V_95 ) ;
F_11 ( V_11 ) ;
return V_12 ;
}
static bool
F_65 ( struct V_21 * V_70 ,
T_1 V_104 , T_1 V_105 , struct V_73 * * V_106 )
{
struct V_1 * V_2 = V_70 -> V_11 -> V_2 ;
struct V_73 * V_74 ;
unsigned long V_79 ;
bool V_3 = false ;
F_45 ( & V_2 -> V_80 , V_79 ) ;
* V_106 = NULL ;
if ( F_66 ( & V_70 -> V_43 ) )
goto V_106;
V_74 = F_67 ( & V_70 -> V_43 ,
struct V_73 , V_82 ) ;
if ( V_74 -> V_107 -> V_108 + V_104 > V_105 )
goto V_106;
V_70 -> V_45 += V_74 -> V_107 -> V_108 ;
F_47 ( & V_74 -> V_82 ) ;
* V_106 = V_74 ;
V_3 = true ;
V_106:
F_49 ( & V_2 -> V_80 , V_79 ) ;
return V_3 ;
}
T_2 F_68 ( struct V_8 * V_9 , char T_3 * V_109 ,
T_1 V_110 , T_4 * V_111 )
{
struct V_21 * V_70 = V_9 -> V_34 ;
struct V_73 * V_74 ;
T_1 V_104 ;
T_2 V_3 ;
V_3 = F_69 ( V_70 -> V_44 ,
! F_66 ( & V_70 -> V_43 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_104 = 0 ;
while ( F_65 ( V_70 , V_104 , V_110 , & V_74 ) ) {
if ( F_70 ( V_109 + V_104 ,
V_74 -> V_107 , V_74 -> V_107 -> V_108 ) ) {
V_104 = - V_112 ;
break;
}
V_104 += V_74 -> V_107 -> V_108 ;
V_74 -> V_84 ( V_74 ) ;
}
return V_104 ;
}
unsigned int F_71 ( struct V_8 * V_9 , struct V_113 * V_114 )
{
struct V_21 * V_70 = V_9 -> V_34 ;
unsigned int V_115 = 0 ;
F_72 ( V_9 , & V_70 -> V_44 , V_114 ) ;
if ( ! F_66 ( & V_70 -> V_43 ) )
V_115 |= V_116 | V_117 ;
return V_115 ;
}
