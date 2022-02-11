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
F_23 ( V_22 ) ;
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
F_28 ( & V_22 -> V_39 , & V_2 -> V_56 ) ;
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
F_35 ( V_22 ) ;
if ( F_2 ( V_2 , V_48 ) )
F_36 ( V_2 , V_22 ) ;
F_37 ( V_22 -> V_35 ) ;
F_38 ( V_22 ) ;
V_9 -> V_34 = NULL ;
return V_3 ;
}
static void F_39 ( struct V_21 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_11 -> V_2 ;
struct V_68 * V_69 , * V_70 ;
unsigned long V_71 ;
F_40 ( & V_2 -> V_72 , V_71 ) ;
F_41 (e, et, &file_priv->pending_event_list,
pending_link) {
F_42 ( & V_69 -> V_73 ) ;
V_69 -> V_67 = NULL ;
}
F_41 (e, et, &file_priv->event_list, link) {
F_42 ( & V_69 -> V_74 ) ;
F_38 ( V_69 ) ;
}
F_43 ( & V_2 -> V_72 , V_71 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 )
F_45 ( V_2 ) ;
F_27 ( & V_2 -> V_76 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_29 ( & V_2 -> V_76 ) ;
V_2 -> V_77 . V_78 = NULL ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 = 0 ;
V_2 -> V_81 = 0 ;
F_4 ( L_3 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
if ( V_2 -> V_4 -> V_82 )
V_2 -> V_4 -> V_82 ( V_2 ) ;
F_4 ( L_4 ) ;
if ( F_2 ( V_2 , V_6 ) )
F_44 ( V_2 ) ;
}
int F_51 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
struct V_21 * V_67 = V_9 -> V_34 ;
struct V_10 * V_11 = V_67 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_27 ( & V_83 ) ;
F_4 ( L_5 , V_2 -> V_14 ) ;
F_27 ( & V_2 -> V_55 ) ;
F_42 ( & V_67 -> V_39 ) ;
F_29 ( & V_2 -> V_55 ) ;
if ( F_2 ( V_2 , V_6 ) &&
V_2 -> V_4 -> V_84 )
V_2 -> V_4 -> V_84 ( V_2 , V_67 ) ;
F_4 ( L_6 ,
F_14 ( V_30 ) ,
( long ) F_52 ( V_67 -> V_11 -> V_85 -> V_86 ) ,
V_2 -> V_14 ) ;
if ( F_2 ( V_2 , V_6 ) )
F_53 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 , V_87 ) )
F_54 ( V_2 , V_67 ) ;
F_39 ( V_67 ) ;
if ( F_2 ( V_2 , V_88 ) ) {
F_55 ( V_67 ) ;
F_56 ( V_2 , V_67 ) ;
}
if ( F_2 ( V_2 , V_49 ) )
F_35 ( V_67 ) ;
if ( F_2 ( V_2 , V_48 ) )
F_36 ( V_2 , V_67 ) ;
F_57 ( V_2 , V_67 ) ;
if ( F_25 ( V_67 ) )
F_58 ( V_67 ) ;
if ( V_2 -> V_4 -> V_66 )
V_2 -> V_4 -> V_66 ( V_2 , V_67 ) ;
if ( F_2 ( V_2 , V_50 ) )
F_34 ( & V_67 -> V_51 ) ;
F_59 ( ! F_60 ( & V_67 -> V_44 ) ) ;
F_37 ( V_67 -> V_35 ) ;
F_38 ( V_67 ) ;
if ( ! -- V_2 -> V_14 ) {
F_50 ( V_2 ) ;
if ( F_61 ( V_2 ) )
F_62 ( V_2 ) ;
}
F_29 ( & V_83 ) ;
F_11 ( V_11 ) ;
return 0 ;
}
T_1 F_63 ( struct V_8 * V_9 , char T_2 * V_89 ,
T_3 V_90 , T_4 * V_91 )
{
struct V_21 * V_67 = V_9 -> V_34 ;
struct V_1 * V_2 = V_67 -> V_11 -> V_2 ;
T_1 V_3 ;
if ( ! F_64 ( V_92 , V_89 , V_90 ) )
return - V_93 ;
V_3 = F_65 ( & V_67 -> V_47 ) ;
if ( V_3 )
return V_3 ;
for (; ; ) {
struct V_68 * V_69 = NULL ;
F_66 ( & V_2 -> V_72 ) ;
if ( ! F_60 ( & V_67 -> V_44 ) ) {
V_69 = F_67 ( & V_67 -> V_44 ,
struct V_68 , V_74 ) ;
V_67 -> V_46 += V_69 -> V_94 -> V_95 ;
F_42 ( & V_69 -> V_74 ) ;
}
F_68 ( & V_2 -> V_72 ) ;
if ( V_69 == NULL ) {
if ( V_3 )
break;
if ( V_9 -> V_23 & V_96 ) {
V_3 = - V_97 ;
break;
}
F_29 ( & V_67 -> V_47 ) ;
V_3 = F_69 ( V_67 -> V_45 ,
! F_60 ( & V_67 -> V_44 ) ) ;
if ( V_3 >= 0 )
V_3 = F_65 ( & V_67 -> V_47 ) ;
if ( V_3 )
return V_3 ;
} else {
unsigned V_95 = V_69 -> V_94 -> V_95 ;
if ( V_95 > V_90 - V_3 ) {
V_98:
F_66 ( & V_2 -> V_72 ) ;
V_67 -> V_46 -= V_95 ;
F_28 ( & V_69 -> V_74 , & V_67 -> V_44 ) ;
F_68 ( & V_2 -> V_72 ) ;
break;
}
if ( F_70 ( V_89 + V_3 , V_69 -> V_94 , V_95 ) ) {
if ( V_3 == 0 )
V_3 = - V_93 ;
goto V_98;
}
V_3 += V_95 ;
F_38 ( V_69 ) ;
}
}
F_29 ( & V_67 -> V_47 ) ;
return V_3 ;
}
unsigned int F_71 ( struct V_8 * V_9 , struct V_99 * V_100 )
{
struct V_21 * V_67 = V_9 -> V_34 ;
unsigned int V_101 = 0 ;
F_72 ( V_9 , & V_67 -> V_45 , V_100 ) ;
if ( ! F_60 ( & V_67 -> V_44 ) )
V_101 |= V_102 | V_103 ;
return V_101 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_21 * V_67 ,
struct V_68 * V_104 ,
struct V_105 * V_69 )
{
if ( V_67 -> V_46 < V_69 -> V_95 )
return - V_33 ;
V_67 -> V_46 -= V_69 -> V_95 ;
V_104 -> V_94 = V_69 ;
F_28 ( & V_104 -> V_73 , & V_67 -> V_43 ) ;
V_104 -> V_67 = V_67 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_21 * V_67 ,
struct V_68 * V_104 ,
struct V_105 * V_69 )
{
unsigned long V_71 ;
int V_3 ;
F_40 ( & V_2 -> V_72 , V_71 ) ;
V_3 = F_73 ( V_2 , V_67 , V_104 , V_69 ) ;
F_43 ( & V_2 -> V_72 , V_71 ) ;
return V_3 ;
}
void F_75 ( struct V_1 * V_2 ,
struct V_68 * V_104 )
{
unsigned long V_71 ;
F_40 ( & V_2 -> V_72 , V_71 ) ;
if ( V_104 -> V_67 ) {
V_104 -> V_67 -> V_46 += V_104 -> V_94 -> V_95 ;
F_42 ( & V_104 -> V_73 ) ;
}
F_43 ( & V_2 -> V_72 , V_71 ) ;
if ( V_104 -> V_106 )
F_76 ( V_104 -> V_106 ) ;
F_38 ( V_104 ) ;
}
void F_77 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
F_78 ( & V_2 -> V_72 ) ;
if ( V_69 -> V_107 ) {
F_79 ( V_69 -> V_107 ) ;
V_69 -> V_108 ( V_69 -> V_107 ) ;
V_69 -> V_107 = NULL ;
}
if ( V_69 -> V_106 ) {
F_80 ( V_69 -> V_106 ) ;
F_76 ( V_69 -> V_106 ) ;
}
if ( ! V_69 -> V_67 ) {
F_38 ( V_69 ) ;
return;
}
F_42 ( & V_69 -> V_73 ) ;
F_81 ( & V_69 -> V_74 ,
& V_69 -> V_67 -> V_44 ) ;
F_82 ( & V_69 -> V_67 -> V_45 ) ;
}
void F_83 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
unsigned long V_109 ;
F_40 ( & V_2 -> V_72 , V_109 ) ;
F_77 ( V_2 , V_69 ) ;
F_43 ( & V_2 -> V_72 , V_109 ) ;
}
