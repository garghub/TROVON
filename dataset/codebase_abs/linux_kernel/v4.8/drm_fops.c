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
F_20 ( & V_22 -> V_44 ) ;
F_20 ( & V_22 -> V_45 ) ;
F_22 ( & V_22 -> V_46 ) ;
V_22 -> V_47 = 4096 ;
F_21 ( & V_22 -> V_48 ) ;
if ( F_2 ( V_2 , V_49 ) )
F_23 ( V_2 , V_22 ) ;
if ( F_2 ( V_2 , V_50 ) )
F_24 ( & V_22 -> V_51 ) ;
if ( V_2 -> V_4 -> V_52 ) {
V_3 = V_2 -> V_4 -> V_52 ( V_2 , V_22 ) ;
if ( V_3 < 0 )
goto V_53;
}
if ( F_25 ( V_22 ) ) {
V_3 = F_26 ( V_22 ) ;
if ( V_3 )
goto V_54;
}
F_27 ( & V_2 -> V_55 ) ;
F_28 ( & V_22 -> V_40 , & V_2 -> V_56 ) ;
F_29 ( & V_2 -> V_55 ) ;
#ifdef F_30
if ( ! V_2 -> V_57 ) {
struct V_58 * V_58 ;
V_58 = F_31 ( V_59 << 8 , NULL ) ;
if ( V_58 ) {
V_2 -> V_57 = V_58 -> V_60 ;
F_32 ( V_58 ) ;
}
if ( ! V_2 -> V_57 ) {
struct V_61 * V_62 = F_33 ( V_63 . V_64 ,
struct V_61 , V_65 ) ;
if ( V_62 )
V_2 -> V_57 = V_62 -> V_60 ;
}
}
#endif
return 0 ;
V_54:
if ( V_2 -> V_4 -> V_66 )
V_2 -> V_4 -> V_66 ( V_2 , V_22 ) ;
V_53:
if ( F_2 ( V_2 , V_50 ) )
F_34 ( & V_22 -> V_51 ) ;
if ( F_2 ( V_2 , V_49 ) )
F_35 ( V_2 , V_22 ) ;
F_36 ( V_22 -> V_36 ) ;
F_37 ( V_22 ) ;
V_9 -> V_34 = NULL ;
return V_3 ;
}
static void F_38 ( struct V_21 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_11 -> V_2 ;
struct V_68 * V_69 , * V_70 ;
unsigned long V_71 ;
F_39 ( & V_2 -> V_72 , V_71 ) ;
F_40 (e, et, &file_priv->pending_event_list,
pending_link) {
F_41 ( & V_69 -> V_73 ) ;
V_69 -> V_67 = NULL ;
}
F_40 (e, et, &file_priv->event_list, link) {
F_41 ( & V_69 -> V_74 ) ;
F_37 ( V_69 ) ;
}
F_42 ( & V_2 -> V_72 , V_71 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 )
F_44 ( V_2 ) ;
F_27 ( & V_2 -> V_76 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_29 ( & V_2 -> V_76 ) ;
V_2 -> V_77 . V_78 = NULL ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 = 0 ;
V_2 -> V_81 = 0 ;
F_4 ( L_3 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_82 )
V_2 -> V_4 -> V_82 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( ! F_2 ( V_2 , V_6 ) )
F_43 ( V_2 ) ;
}
int F_50 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_21 * V_67 = V_9 -> V_34 ;
struct V_10 * V_11 = V_67 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_27 ( & V_83 ) ;
F_4 ( L_5 , V_2 -> V_14 ) ;
F_27 ( & V_2 -> V_55 ) ;
F_41 ( & V_67 -> V_40 ) ;
F_29 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_4 -> V_84 )
V_2 -> V_4 -> V_84 ( V_2 , V_67 ) ;
F_4 ( L_6 ,
F_14 ( V_30 ) ,
( long ) F_51 ( V_67 -> V_11 -> V_85 -> V_86 ) ,
V_2 -> V_14 ) ;
if ( ! F_2 ( V_2 , V_6 ) )
F_52 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_87 ) )
F_53 ( V_2 , V_67 ) ;
F_38 ( V_67 ) ;
if ( F_2 ( V_2 , V_6 ) ) {
F_54 ( V_67 ) ;
F_55 ( V_2 , V_67 ) ;
}
if ( F_2 ( V_2 , V_49 ) )
F_35 ( V_2 , V_67 ) ;
F_56 ( V_2 , V_67 ) ;
if ( F_25 ( V_67 ) )
F_57 ( V_67 ) ;
if ( V_2 -> V_4 -> V_66 )
V_2 -> V_4 -> V_66 ( V_2 , V_67 ) ;
if ( F_2 ( V_2 , V_50 ) )
F_34 ( & V_67 -> V_51 ) ;
F_58 ( ! F_59 ( & V_67 -> V_45 ) ) ;
F_36 ( V_67 -> V_36 ) ;
F_37 ( V_67 ) ;
if ( ! -- V_2 -> V_14 ) {
F_49 ( V_2 ) ;
if ( F_60 ( V_2 ) )
F_61 ( V_2 ) ;
}
F_29 ( & V_83 ) ;
F_11 ( V_11 ) ;
return 0 ;
}
T_1 F_62 ( struct V_8 * V_9 , char T_2 * V_88 ,
T_3 V_89 , T_4 * V_90 )
{
struct V_21 * V_67 = V_9 -> V_34 ;
struct V_1 * V_2 = V_67 -> V_11 -> V_2 ;
T_1 V_3 ;
if ( ! F_63 ( V_91 , V_88 , V_89 ) )
return - V_92 ;
V_3 = F_64 ( & V_67 -> V_48 ) ;
if ( V_3 )
return V_3 ;
for (; ; ) {
struct V_68 * V_69 = NULL ;
F_65 ( & V_2 -> V_72 ) ;
if ( ! F_59 ( & V_67 -> V_45 ) ) {
V_69 = F_66 ( & V_67 -> V_45 ,
struct V_68 , V_74 ) ;
V_67 -> V_47 += V_69 -> V_93 -> V_94 ;
F_41 ( & V_69 -> V_74 ) ;
}
F_67 ( & V_2 -> V_72 ) ;
if ( V_69 == NULL ) {
if ( V_3 )
break;
if ( V_9 -> V_23 & V_95 ) {
V_3 = - V_96 ;
break;
}
F_29 ( & V_67 -> V_48 ) ;
V_3 = F_68 ( V_67 -> V_46 ,
! F_59 ( & V_67 -> V_45 ) ) ;
if ( V_3 >= 0 )
V_3 = F_64 ( & V_67 -> V_48 ) ;
if ( V_3 )
return V_3 ;
} else {
unsigned V_94 = V_69 -> V_93 -> V_94 ;
if ( V_94 > V_89 - V_3 ) {
V_97:
F_65 ( & V_2 -> V_72 ) ;
V_67 -> V_47 -= V_94 ;
F_28 ( & V_69 -> V_74 , & V_67 -> V_45 ) ;
F_67 ( & V_2 -> V_72 ) ;
break;
}
if ( F_69 ( V_88 + V_3 , V_69 -> V_93 , V_94 ) ) {
if ( V_3 == 0 )
V_3 = - V_92 ;
goto V_97;
}
V_3 += V_94 ;
F_37 ( V_69 ) ;
}
}
F_29 ( & V_67 -> V_48 ) ;
return V_3 ;
}
unsigned int F_70 ( struct V_8 * V_9 , struct V_98 * V_99 )
{
struct V_21 * V_67 = V_9 -> V_34 ;
unsigned int V_100 = 0 ;
F_71 ( V_9 , & V_67 -> V_46 , V_99 ) ;
if ( ! F_59 ( & V_67 -> V_45 ) )
V_100 |= V_101 | V_102 ;
return V_100 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_21 * V_67 ,
struct V_68 * V_103 ,
struct V_104 * V_69 )
{
if ( V_67 -> V_47 < V_69 -> V_94 )
return - V_33 ;
V_67 -> V_47 -= V_69 -> V_94 ;
V_103 -> V_93 = V_69 ;
F_28 ( & V_103 -> V_73 , & V_67 -> V_44 ) ;
V_103 -> V_67 = V_67 ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_21 * V_67 ,
struct V_68 * V_103 ,
struct V_104 * V_69 )
{
unsigned long V_71 ;
int V_3 ;
F_39 ( & V_2 -> V_72 , V_71 ) ;
V_3 = F_72 ( V_2 , V_67 , V_103 , V_69 ) ;
F_42 ( & V_2 -> V_72 , V_71 ) ;
return V_3 ;
}
void F_74 ( struct V_1 * V_2 ,
struct V_68 * V_103 )
{
unsigned long V_71 ;
F_39 ( & V_2 -> V_72 , V_71 ) ;
if ( V_103 -> V_67 ) {
V_103 -> V_67 -> V_47 += V_103 -> V_93 -> V_94 ;
F_41 ( & V_103 -> V_73 ) ;
}
F_42 ( & V_2 -> V_72 , V_71 ) ;
F_37 ( V_103 ) ;
}
void F_75 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
F_76 ( & V_2 -> V_72 ) ;
if ( V_69 -> V_105 ) {
F_77 ( V_69 -> V_105 ) ;
V_69 -> V_105 = NULL ;
}
if ( V_69 -> V_106 ) {
F_78 ( V_69 -> V_106 ) ;
F_79 ( V_69 -> V_106 ) ;
}
if ( ! V_69 -> V_67 ) {
F_37 ( V_69 ) ;
return;
}
F_41 ( & V_69 -> V_73 ) ;
F_80 ( & V_69 -> V_74 ,
& V_69 -> V_67 -> V_45 ) ;
F_81 ( & V_69 -> V_67 -> V_46 ) ;
}
void F_82 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
unsigned long V_107 ;
F_39 ( & V_2 -> V_72 , V_107 ) ;
F_75 ( V_2 , V_69 ) ;
F_42 ( & V_2 -> V_72 , V_107 ) ;
}
