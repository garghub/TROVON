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
if ( F_2 ( V_2 , V_46 ) )
F_23 ( V_2 , V_22 ) ;
if ( F_2 ( V_2 , V_47 ) )
F_24 ( & V_22 -> V_48 ) ;
if ( V_2 -> V_4 -> V_49 ) {
V_3 = V_2 -> V_4 -> V_49 ( V_2 , V_22 ) ;
if ( V_3 < 0 )
goto V_50;
}
F_25 ( & V_2 -> V_51 ) ;
if ( F_26 ( V_22 ) && ! V_22 -> V_11 -> V_52 ) {
V_22 -> V_11 -> V_52 = F_27 ( V_22 -> V_11 ) ;
if ( ! V_22 -> V_11 -> V_52 ) {
V_3 = - V_33 ;
goto V_53;
}
V_22 -> V_54 = 1 ;
V_22 -> V_52 = F_28 ( V_22 -> V_11 -> V_52 ) ;
V_22 -> V_37 = 1 ;
if ( V_2 -> V_4 -> V_55 ) {
V_3 = V_2 -> V_4 -> V_55 ( V_2 , V_22 -> V_52 ) ;
if ( V_3 ) {
F_29 ( & V_22 -> V_11 -> V_52 ) ;
F_29 ( & V_22 -> V_52 ) ;
goto V_53;
}
}
if ( V_2 -> V_4 -> V_56 ) {
V_3 = V_2 -> V_4 -> V_56 ( V_2 , V_22 , true ) ;
if ( V_3 ) {
F_29 ( & V_22 -> V_11 -> V_52 ) ;
F_29 ( & V_22 -> V_52 ) ;
goto V_53;
}
}
} else if ( F_26 ( V_22 ) ) {
V_22 -> V_52 = F_28 ( V_22 -> V_11 -> V_52 ) ;
}
F_30 ( & V_2 -> V_51 ) ;
F_25 ( & V_2 -> V_57 ) ;
F_31 ( & V_22 -> V_40 , & V_2 -> V_58 ) ;
F_30 ( & V_2 -> V_57 ) ;
#ifdef F_32
if ( ! V_2 -> V_59 ) {
struct V_60 * V_60 ;
V_60 = F_33 ( V_61 << 8 , NULL ) ;
if ( V_60 ) {
V_2 -> V_59 = V_60 -> V_62 ;
F_34 ( V_60 ) ;
}
if ( ! V_2 -> V_59 ) {
struct V_63 * V_64 = F_35 ( V_65 . V_66 ,
struct V_63 , V_67 ) ;
if ( V_64 )
V_2 -> V_59 = V_64 -> V_62 ;
}
}
#endif
return 0 ;
V_53:
F_30 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_4 -> V_68 )
V_2 -> V_4 -> V_68 ( V_2 , V_22 ) ;
V_50:
if ( F_2 ( V_2 , V_47 ) )
F_36 ( & V_22 -> V_48 ) ;
if ( F_2 ( V_2 , V_46 ) )
F_37 ( V_2 , V_22 ) ;
F_38 ( V_22 -> V_36 ) ;
F_39 ( V_22 ) ;
V_9 -> V_34 = NULL ;
return V_3 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_21 * V_69 = V_9 -> V_34 ;
if ( F_41 ( V_2 , V_69 ) ) {
F_4 ( L_3 ,
V_9 , F_42 ( V_69 -> V_52 -> V_70 . V_71 -> V_70 ) ) ;
F_43 ( & V_69 -> V_52 -> V_70 ,
F_42 ( V_69 -> V_52 -> V_70 . V_71 -> V_70 ) ) ;
}
}
static void F_44 ( struct V_21 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_11 -> V_2 ;
struct V_72 * V_73 , * V_74 ;
struct V_75 * V_76 , * V_77 ;
unsigned long V_78 ;
F_45 ( & V_2 -> V_79 , V_78 ) ;
F_46 (v, vt, &dev->vblank_event_list, base.link)
if ( V_76 -> V_80 . V_69 == V_69 ) {
F_47 ( & V_76 -> V_80 . V_81 ) ;
F_48 ( V_2 , V_76 -> V_82 ) ;
V_76 -> V_80 . V_83 ( & V_76 -> V_80 ) ;
}
F_46 (e, et, &file_priv->event_list, link) {
F_47 ( & V_73 -> V_81 ) ;
V_73 -> V_83 ( V_73 ) ;
}
F_49 ( & V_2 -> V_79 , V_78 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 ) )
return;
V_2 -> V_84 . V_70 = NULL ;
V_2 -> V_85 = 0 ;
V_2 -> V_86 = 0 ;
V_2 -> V_87 = 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_88 )
V_2 -> V_4 -> V_88 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( V_2 -> V_89 && ! F_2 ( V_2 , V_6 ) )
F_52 ( V_2 ) ;
F_25 ( & V_2 -> V_57 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_30 ( & V_2 -> V_57 ) ;
F_50 ( V_2 ) ;
F_4 ( L_5 ) ;
return 0 ;
}
int F_57 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_21 * V_69 = V_9 -> V_34 ;
struct V_10 * V_11 = V_69 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_12 = 0 ;
F_25 ( & V_90 ) ;
F_4 ( L_6 , V_2 -> V_14 ) ;
F_25 ( & V_2 -> V_57 ) ;
F_47 ( & V_69 -> V_40 ) ;
F_30 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_4 -> V_91 )
V_2 -> V_4 -> V_91 ( V_2 , V_69 ) ;
F_4 ( L_7 ,
F_14 ( V_30 ) ,
( long ) F_58 ( V_69 -> V_11 -> V_92 -> V_93 ) ,
V_2 -> V_14 ) ;
if ( V_69 -> V_94 )
( void ) F_59 ( V_69 -> V_52 , V_69 -> V_94 ) ;
if ( V_69 -> V_11 -> V_52 )
F_40 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_95 ) )
F_60 ( V_2 , V_69 ) ;
F_44 ( V_69 ) ;
if ( F_2 ( V_2 , V_6 ) )
F_61 ( V_69 ) ;
if ( F_2 ( V_2 , V_46 ) )
F_37 ( V_2 , V_69 ) ;
F_62 ( V_2 , V_69 ) ;
F_25 ( & V_2 -> V_51 ) ;
if ( V_69 -> V_54 ) {
struct V_96 * V_52 = V_69 -> V_52 ;
F_25 ( & V_2 -> V_57 ) ;
if ( V_52 -> V_70 . V_71 ) {
if ( V_2 -> V_84 . V_70 == V_52 -> V_70 . V_71 )
V_2 -> V_84 . V_70 = NULL ;
V_52 -> V_70 . V_71 = NULL ;
V_52 -> V_70 . V_69 = NULL ;
F_63 ( & V_52 -> V_70 . V_97 ) ;
}
F_30 ( & V_2 -> V_57 ) ;
if ( V_69 -> V_11 -> V_52 == V_69 -> V_52 ) {
if ( V_2 -> V_4 -> V_98 )
V_2 -> V_4 -> V_98 ( V_2 , V_69 , true ) ;
F_29 ( & V_69 -> V_11 -> V_52 ) ;
}
}
if ( V_69 -> V_52 )
F_29 ( & V_69 -> V_52 ) ;
V_69 -> V_54 = 0 ;
F_30 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_4 -> V_68 )
V_2 -> V_4 -> V_68 ( V_2 , V_69 ) ;
if ( F_2 ( V_2 , V_47 ) )
F_36 ( & V_69 -> V_48 ) ;
F_64 ( ! F_65 ( & V_69 -> V_43 ) ) ;
F_38 ( V_69 -> V_36 ) ;
F_39 ( V_69 ) ;
if ( ! -- V_2 -> V_14 ) {
V_12 = F_51 ( V_2 ) ;
if ( F_66 ( V_2 ) )
F_67 ( V_2 ) ;
}
F_30 ( & V_90 ) ;
F_11 ( V_11 ) ;
return V_12 ;
}
T_1 F_68 ( struct V_8 * V_9 , char T_2 * V_99 ,
T_3 V_100 , T_4 * V_101 )
{
struct V_21 * V_69 = V_9 -> V_34 ;
struct V_1 * V_2 = V_69 -> V_11 -> V_2 ;
T_1 V_3 = 0 ;
if ( ! F_69 ( V_102 , V_99 , V_100 ) )
return - V_103 ;
F_70 ( & V_2 -> V_79 ) ;
for (; ; ) {
if ( F_65 ( & V_69 -> V_43 ) ) {
if ( V_3 )
break;
if ( V_9 -> V_23 & V_104 ) {
V_3 = - V_105 ;
break;
}
F_71 ( & V_2 -> V_79 ) ;
V_3 = F_72 ( V_69 -> V_44 ,
! F_65 ( & V_69 -> V_43 ) ) ;
F_70 ( & V_2 -> V_79 ) ;
if ( V_3 < 0 )
break;
V_3 = 0 ;
} else {
struct V_72 * V_73 ;
V_73 = F_73 ( & V_69 -> V_43 ,
struct V_72 , V_81 ) ;
if ( V_73 -> V_106 -> V_107 + V_3 > V_100 )
break;
if ( F_74 ( V_99 + V_3 ,
V_73 -> V_106 , V_73 -> V_106 -> V_107 ) ) {
if ( V_3 == 0 )
V_3 = - V_103 ;
break;
}
V_69 -> V_45 += V_73 -> V_106 -> V_107 ;
V_3 += V_73 -> V_106 -> V_107 ;
F_47 ( & V_73 -> V_81 ) ;
V_73 -> V_83 ( V_73 ) ;
}
}
F_71 ( & V_2 -> V_79 ) ;
return V_3 ;
}
unsigned int F_75 ( struct V_8 * V_9 , struct V_108 * V_109 )
{
struct V_21 * V_69 = V_9 -> V_34 ;
unsigned int V_110 = 0 ;
F_76 ( V_9 , & V_69 -> V_44 , V_109 ) ;
if ( ! F_65 ( & V_69 -> V_43 ) )
V_110 |= V_111 | V_112 ;
return V_110 ;
}
