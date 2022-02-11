static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 -> V_5 &&
F_2 ( V_2 , V_6 ) ) {
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
V_22 -> V_35 = F_16 ( F_17 ( V_30 ) ) ;
V_22 -> V_11 = V_11 ;
V_22 -> V_36 = F_18 ( V_37 ) ;
V_22 -> V_38 = 0 ;
F_19 ( & V_22 -> V_39 ) ;
F_19 ( & V_22 -> V_40 ) ;
F_20 ( & V_22 -> V_41 ) ;
F_19 ( & V_22 -> V_42 ) ;
F_19 ( & V_22 -> V_43 ) ;
F_19 ( & V_22 -> V_44 ) ;
F_21 ( & V_22 -> V_45 ) ;
V_22 -> V_46 = 4096 ;
F_20 ( & V_22 -> V_47 ) ;
if ( F_2 ( V_2 , V_48 ) )
F_22 ( V_2 , V_22 ) ;
if ( F_2 ( V_2 , V_49 ) )
F_23 ( & V_22 -> V_50 ) ;
if ( V_2 -> V_4 -> V_51 ) {
V_3 = V_2 -> V_4 -> V_51 ( V_2 , V_22 ) ;
if ( V_3 < 0 )
goto V_52;
}
if ( F_24 ( V_22 ) ) {
V_3 = F_25 ( V_22 ) ;
if ( V_3 )
goto V_53;
}
F_26 ( & V_2 -> V_54 ) ;
F_27 ( & V_22 -> V_39 , & V_2 -> V_55 ) ;
F_28 ( & V_2 -> V_54 ) ;
#ifdef F_29
if ( ! V_2 -> V_56 ) {
struct V_57 * V_57 ;
V_57 = F_30 ( V_58 << 8 , NULL ) ;
if ( V_57 ) {
V_2 -> V_56 = V_57 -> V_59 ;
F_31 ( V_57 ) ;
}
if ( ! V_2 -> V_56 ) {
struct V_60 * V_61 = F_32 ( V_62 . V_63 ,
struct V_60 , V_64 ) ;
if ( V_61 )
V_2 -> V_56 = V_61 -> V_59 ;
}
}
#endif
return 0 ;
V_53:
if ( V_2 -> V_4 -> V_65 )
V_2 -> V_4 -> V_65 ( V_2 , V_22 ) ;
V_52:
if ( F_2 ( V_2 , V_49 ) )
F_33 ( & V_22 -> V_50 ) ;
if ( F_2 ( V_2 , V_48 ) )
F_34 ( V_2 , V_22 ) ;
F_35 ( V_22 -> V_35 ) ;
F_36 ( V_22 ) ;
V_9 -> V_34 = NULL ;
return V_3 ;
}
static void F_37 ( struct V_21 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_11 -> V_2 ;
struct V_67 * V_68 , * V_69 ;
unsigned long V_70 ;
F_38 ( & V_2 -> V_71 , V_70 ) ;
F_39 (e, et, &file_priv->pending_event_list,
pending_link) {
F_40 ( & V_68 -> V_72 ) ;
V_68 -> V_66 = NULL ;
}
F_39 (e, et, &file_priv->event_list, link) {
F_40 ( & V_68 -> V_73 ) ;
F_36 ( V_68 ) ;
}
F_41 ( & V_2 -> V_71 , V_70 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 )
F_43 ( V_2 ) ;
F_26 ( & V_2 -> V_75 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_28 ( & V_2 -> V_75 ) ;
V_2 -> V_76 . V_77 = NULL ;
V_2 -> V_78 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 = 0 ;
F_4 ( L_3 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_81 )
V_2 -> V_4 -> V_81 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( F_2 ( V_2 , V_6 ) )
F_42 ( V_2 ) ;
}
int F_49 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_21 * V_66 = V_9 -> V_34 ;
struct V_10 * V_11 = V_66 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_26 ( & V_82 ) ;
F_4 ( L_5 , V_2 -> V_14 ) ;
F_26 ( & V_2 -> V_54 ) ;
F_40 ( & V_66 -> V_39 ) ;
F_28 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_4 -> V_83 )
V_2 -> V_4 -> V_83 ( V_2 , V_66 ) ;
F_4 ( L_6 ,
F_14 ( V_30 ) ,
( long ) F_50 ( V_66 -> V_11 -> V_84 -> V_85 ) ,
V_2 -> V_14 ) ;
if ( F_2 ( V_2 , V_6 ) )
F_51 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_86 ) )
F_52 ( V_2 , V_66 ) ;
F_37 ( V_66 ) ;
if ( F_2 ( V_2 , V_87 ) ) {
F_53 ( V_66 ) ;
F_54 ( V_2 , V_66 ) ;
}
if ( F_2 ( V_2 , V_48 ) )
F_34 ( V_2 , V_66 ) ;
F_55 ( V_2 , V_66 ) ;
if ( F_24 ( V_66 ) )
F_56 ( V_66 ) ;
if ( V_2 -> V_4 -> V_65 )
V_2 -> V_4 -> V_65 ( V_2 , V_66 ) ;
if ( F_2 ( V_2 , V_49 ) )
F_33 ( & V_66 -> V_50 ) ;
F_57 ( ! F_58 ( & V_66 -> V_44 ) ) ;
F_35 ( V_66 -> V_35 ) ;
F_36 ( V_66 ) ;
if ( ! -- V_2 -> V_14 ) {
F_48 ( V_2 ) ;
if ( F_59 ( V_2 ) )
F_60 ( V_2 ) ;
}
F_28 ( & V_82 ) ;
F_11 ( V_11 ) ;
return 0 ;
}
T_1 F_61 ( struct V_8 * V_9 , char T_2 * V_88 ,
T_3 V_89 , T_4 * V_90 )
{
struct V_21 * V_66 = V_9 -> V_34 ;
struct V_1 * V_2 = V_66 -> V_11 -> V_2 ;
T_1 V_3 ;
if ( ! F_62 ( V_91 , V_88 , V_89 ) )
return - V_92 ;
V_3 = F_63 ( & V_66 -> V_47 ) ;
if ( V_3 )
return V_3 ;
for (; ; ) {
struct V_67 * V_68 = NULL ;
F_64 ( & V_2 -> V_71 ) ;
if ( ! F_58 ( & V_66 -> V_44 ) ) {
V_68 = F_65 ( & V_66 -> V_44 ,
struct V_67 , V_73 ) ;
V_66 -> V_46 += V_68 -> V_93 -> V_94 ;
F_40 ( & V_68 -> V_73 ) ;
}
F_66 ( & V_2 -> V_71 ) ;
if ( V_68 == NULL ) {
if ( V_3 )
break;
if ( V_9 -> V_23 & V_95 ) {
V_3 = - V_96 ;
break;
}
F_28 ( & V_66 -> V_47 ) ;
V_3 = F_67 ( V_66 -> V_45 ,
! F_58 ( & V_66 -> V_44 ) ) ;
if ( V_3 >= 0 )
V_3 = F_63 ( & V_66 -> V_47 ) ;
if ( V_3 )
return V_3 ;
} else {
unsigned V_94 = V_68 -> V_93 -> V_94 ;
if ( V_94 > V_89 - V_3 ) {
V_97:
F_64 ( & V_2 -> V_71 ) ;
V_66 -> V_46 -= V_94 ;
F_27 ( & V_68 -> V_73 , & V_66 -> V_44 ) ;
F_66 ( & V_2 -> V_71 ) ;
break;
}
if ( F_68 ( V_88 + V_3 , V_68 -> V_93 , V_94 ) ) {
if ( V_3 == 0 )
V_3 = - V_92 ;
goto V_97;
}
V_3 += V_94 ;
F_36 ( V_68 ) ;
}
}
F_28 ( & V_66 -> V_47 ) ;
return V_3 ;
}
unsigned int F_69 ( struct V_8 * V_9 , struct V_98 * V_99 )
{
struct V_21 * V_66 = V_9 -> V_34 ;
unsigned int V_100 = 0 ;
F_70 ( V_9 , & V_66 -> V_45 , V_99 ) ;
if ( ! F_58 ( & V_66 -> V_44 ) )
V_100 |= V_101 | V_102 ;
return V_100 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_21 * V_66 ,
struct V_67 * V_103 ,
struct V_104 * V_68 )
{
if ( V_66 -> V_46 < V_68 -> V_94 )
return - V_33 ;
V_66 -> V_46 -= V_68 -> V_94 ;
V_103 -> V_93 = V_68 ;
F_27 ( & V_103 -> V_72 , & V_66 -> V_43 ) ;
V_103 -> V_66 = V_66 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_21 * V_66 ,
struct V_67 * V_103 ,
struct V_104 * V_68 )
{
unsigned long V_70 ;
int V_3 ;
F_38 ( & V_2 -> V_71 , V_70 ) ;
V_3 = F_71 ( V_2 , V_66 , V_103 , V_68 ) ;
F_41 ( & V_2 -> V_71 , V_70 ) ;
return V_3 ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_67 * V_103 )
{
unsigned long V_70 ;
F_38 ( & V_2 -> V_71 , V_70 ) ;
if ( V_103 -> V_66 ) {
V_103 -> V_66 -> V_46 += V_103 -> V_93 -> V_94 ;
F_40 ( & V_103 -> V_72 ) ;
}
F_41 ( & V_2 -> V_71 , V_70 ) ;
if ( V_103 -> V_105 )
F_74 ( V_103 -> V_105 ) ;
F_36 ( V_103 ) ;
}
void F_75 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
F_76 ( & V_2 -> V_71 ) ;
if ( V_68 -> V_106 ) {
F_77 ( V_68 -> V_106 ) ;
V_68 -> V_107 ( V_68 -> V_106 ) ;
V_68 -> V_106 = NULL ;
}
if ( V_68 -> V_105 ) {
F_78 ( V_68 -> V_105 ) ;
F_74 ( V_68 -> V_105 ) ;
}
if ( ! V_68 -> V_66 ) {
F_36 ( V_68 ) ;
return;
}
F_40 ( & V_68 -> V_72 ) ;
F_79 ( & V_68 -> V_73 ,
& V_68 -> V_66 -> V_44 ) ;
F_80 ( & V_68 -> V_66 -> V_45 ) ;
}
void F_81 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
unsigned long V_108 ;
F_38 ( & V_2 -> V_71 , V_108 ) ;
F_75 ( V_2 , V_68 ) ;
F_41 ( & V_2 -> V_71 , V_108 ) ;
}
