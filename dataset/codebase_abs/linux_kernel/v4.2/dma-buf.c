static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 -> V_8 . V_9 || V_4 -> V_10 . V_9 ) ;
V_4 -> V_11 -> V_12 ( V_4 ) ;
F_4 ( & V_13 . V_14 ) ;
F_5 ( & V_4 -> V_15 ) ;
F_6 ( & V_13 . V_14 ) ;
if ( V_4 -> V_16 == (struct V_17 * ) & V_4 [ 1 ] )
F_7 ( V_4 -> V_16 ) ;
F_8 ( V_4 -> V_18 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_2 , struct V_19 * V_20 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
if ( V_20 -> V_21 + ( ( V_20 -> V_22 - V_20 -> V_23 ) >> V_24 ) >
V_4 -> V_25 >> V_24 )
return - V_5 ;
return V_4 -> V_11 -> V_26 ( V_4 , V_20 ) ;
}
static T_1 F_11 ( struct V_2 * V_2 , T_1 V_27 , int V_28 )
{
struct V_3 * V_4 ;
T_1 V_29 ;
if ( ! F_2 ( V_2 ) )
return - V_30 ;
V_4 = V_2 -> V_6 ;
if ( V_28 == V_31 )
V_29 = V_4 -> V_25 ;
else if ( V_28 == V_32 )
V_29 = 0 ;
else
return - V_5 ;
if ( V_27 != 0 )
return - V_5 ;
return V_29 + V_27 ;
}
static void F_12 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
unsigned long V_38 ;
F_13 ( & V_37 -> V_39 -> V_14 , V_38 ) ;
F_14 ( V_37 -> V_39 , V_37 -> V_9 ) ;
V_37 -> V_9 = 0 ;
F_15 ( & V_37 -> V_39 -> V_14 , V_38 ) ;
}
static unsigned int F_16 ( struct V_2 * V_2 , T_2 * V_39 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 ;
struct V_40 * V_41 ;
struct V_33 * V_42 ;
unsigned long V_43 ;
unsigned V_44 , V_45 ;
V_4 = V_2 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_16 )
return V_46 ;
V_16 = V_4 -> V_16 ;
F_17 ( V_2 , & V_4 -> V_39 , V_39 ) ;
V_43 = F_18 ( V_39 ) & ( V_47 | V_48 ) ;
if ( ! V_43 )
return 0 ;
V_49:
V_45 = F_19 ( & V_16 -> V_45 ) ;
F_20 () ;
V_41 = F_21 ( V_16 -> V_33 ) ;
if ( V_41 )
V_44 = V_41 -> V_44 ;
else
V_44 = 0 ;
V_42 = F_21 ( V_16 -> V_42 ) ;
if ( F_22 ( & V_16 -> V_45 , V_45 ) ) {
F_23 () ;
goto V_49;
}
if ( V_42 && ( ! ( V_43 & V_48 ) || V_44 == 0 ) ) {
struct V_36 * V_37 = & V_4 -> V_10 ;
unsigned long V_50 = V_47 ;
if ( V_44 == 0 )
V_50 |= V_48 ;
F_24 ( & V_4 -> V_39 . V_14 ) ;
if ( V_37 -> V_9 ) {
V_37 -> V_9 |= V_50 ;
V_43 &= ~ V_50 ;
} else
V_37 -> V_9 = V_50 ;
F_25 ( & V_4 -> V_39 . V_14 ) ;
if ( V_43 & V_50 ) {
if ( ! F_26 ( V_42 ) ) {
V_43 &= ~ V_50 ;
F_12 ( NULL , & V_37 -> V_35 ) ;
} else if ( ! F_27 ( V_42 , & V_37 -> V_35 ,
F_12 ) ) {
V_43 &= ~ V_50 ;
F_28 ( V_42 ) ;
} else {
F_28 ( V_42 ) ;
F_12 ( NULL , & V_37 -> V_35 ) ;
}
}
}
if ( ( V_43 & V_48 ) && V_44 > 0 ) {
struct V_36 * V_37 = & V_4 -> V_8 ;
int V_51 ;
F_24 ( & V_4 -> V_39 . V_14 ) ;
if ( V_37 -> V_9 )
V_43 &= ~ V_48 ;
else
V_37 -> V_9 = V_48 ;
F_25 ( & V_4 -> V_39 . V_14 ) ;
if ( ! ( V_43 & V_48 ) )
goto V_52;
for ( V_51 = 0 ; V_51 < V_44 ; ++ V_51 ) {
struct V_33 * V_33 = F_21 ( V_41 -> V_53 [ V_51 ] ) ;
if ( ! F_26 ( V_33 ) ) {
V_43 &= ~ V_48 ;
F_12 ( NULL , & V_37 -> V_35 ) ;
break;
}
if ( ! F_27 ( V_33 , & V_37 -> V_35 ,
F_12 ) ) {
F_28 ( V_33 ) ;
V_43 &= ~ V_48 ;
break;
}
F_28 ( V_33 ) ;
}
if ( V_51 == V_44 )
F_12 ( NULL , & V_37 -> V_35 ) ;
}
V_52:
F_23 () ;
return V_43 ;
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_54 == & V_55 ;
}
struct V_3 * F_29 ( const struct V_56 * V_57 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 = V_57 -> V_16 ;
struct V_2 * V_2 ;
T_3 V_58 = sizeof( struct V_3 ) ;
if ( ! V_57 -> V_16 )
V_58 += sizeof( struct V_17 ) ;
else
V_58 += 1 ;
if ( F_30 ( ! V_57 -> V_59
|| ! V_57 -> V_11
|| ! V_57 -> V_11 -> V_60
|| ! V_57 -> V_11 -> V_61
|| ! V_57 -> V_11 -> V_12
|| ! V_57 -> V_11 -> V_62
|| ! V_57 -> V_11 -> V_63
|| ! V_57 -> V_11 -> V_26 ) ) {
return F_31 ( - V_5 ) ;
}
if ( ! F_32 ( V_57 -> V_18 ) )
return F_31 ( - V_64 ) ;
V_4 = F_33 ( V_58 , V_65 ) ;
if ( ! V_4 ) {
F_8 ( V_57 -> V_18 ) ;
return F_31 ( - V_66 ) ;
}
V_4 -> V_59 = V_57 -> V_59 ;
V_4 -> V_11 = V_57 -> V_11 ;
V_4 -> V_25 = V_57 -> V_25 ;
V_4 -> V_67 = V_57 -> V_67 ;
V_4 -> V_18 = V_57 -> V_18 ;
F_34 ( & V_4 -> V_39 ) ;
V_4 -> V_10 . V_39 = V_4 -> V_8 . V_39 = & V_4 -> V_39 ;
V_4 -> V_10 . V_9 = V_4 -> V_8 . V_9 = 0 ;
if ( ! V_16 ) {
V_16 = (struct V_17 * ) & V_4 [ 1 ] ;
F_35 ( V_16 ) ;
}
V_4 -> V_16 = V_16 ;
V_2 = F_36 ( L_1 , & V_55 , V_4 ,
V_57 -> V_38 ) ;
if ( F_37 ( V_2 ) ) {
F_9 ( V_4 ) ;
return F_38 ( V_2 ) ;
}
V_2 -> V_68 |= V_69 ;
V_4 -> V_2 = V_2 ;
F_39 ( & V_4 -> V_14 ) ;
F_40 ( & V_4 -> V_70 ) ;
F_4 ( & V_13 . V_14 ) ;
F_41 ( & V_4 -> V_15 , & V_13 . V_71 ) ;
F_6 ( & V_13 . V_14 ) ;
return V_4 ;
}
int F_42 ( struct V_3 * V_4 , int V_38 )
{
int V_72 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_72 = F_43 ( V_38 ) ;
if ( V_72 < 0 )
return V_72 ;
F_44 ( V_72 , V_4 -> V_2 ) ;
return V_72 ;
}
struct V_3 * F_45 ( int V_72 )
{
struct V_2 * V_2 ;
V_2 = F_46 ( V_72 ) ;
if ( ! V_2 )
return F_31 ( - V_30 ) ;
if ( ! F_2 ( V_2 ) ) {
F_47 ( V_2 ) ;
return F_31 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_48 ( struct V_3 * V_4 )
{
if ( F_30 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_47 ( V_4 -> V_2 ) ;
}
struct V_73 * F_49 ( struct V_3 * V_4 ,
struct V_74 * V_75 )
{
struct V_73 * V_76 ;
int V_77 ;
if ( F_30 ( ! V_4 || ! V_75 ) )
return F_31 ( - V_5 ) ;
V_76 = F_33 ( sizeof( struct V_73 ) , V_65 ) ;
if ( V_76 == NULL )
return F_31 ( - V_66 ) ;
V_76 -> V_75 = V_75 ;
V_76 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_11 -> V_76 ) {
V_77 = V_4 -> V_11 -> V_76 ( V_4 , V_75 , V_76 ) ;
if ( V_77 )
goto V_78;
}
F_41 ( & V_76 -> V_79 , & V_4 -> V_70 ) ;
F_6 ( & V_4 -> V_14 ) ;
return V_76 ;
V_78:
F_9 ( V_76 ) ;
F_6 ( & V_4 -> V_14 ) ;
return F_31 ( V_77 ) ;
}
void F_50 ( struct V_3 * V_4 , struct V_73 * V_76 )
{
if ( F_30 ( ! V_4 || ! V_76 ) )
return;
F_4 ( & V_4 -> V_14 ) ;
F_5 ( & V_76 -> V_79 ) ;
if ( V_4 -> V_11 -> V_80 )
V_4 -> V_11 -> V_80 ( V_4 , V_76 ) ;
F_6 ( & V_4 -> V_14 ) ;
F_9 ( V_76 ) ;
}
struct V_81 * F_51 ( struct V_73 * V_76 ,
enum V_82 V_83 )
{
struct V_81 * V_81 = F_31 ( - V_5 ) ;
F_52 () ;
if ( F_30 ( ! V_76 || ! V_76 -> V_4 ) )
return F_31 ( - V_5 ) ;
V_81 = V_76 -> V_4 -> V_11 -> V_60 ( V_76 , V_83 ) ;
if ( ! V_81 )
V_81 = F_31 ( - V_66 ) ;
return V_81 ;
}
void F_53 ( struct V_73 * V_76 ,
struct V_81 * V_81 ,
enum V_82 V_83 )
{
F_52 () ;
if ( F_30 ( ! V_76 || ! V_76 -> V_4 || ! V_81 ) )
return;
V_76 -> V_4 -> V_11 -> V_61 ( V_76 , V_81 ,
V_83 ) ;
}
int F_54 ( struct V_3 * V_4 , T_3 V_84 , T_3 V_85 ,
enum V_82 V_83 )
{
int V_77 = 0 ;
if ( F_30 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_11 -> V_86 )
V_77 = V_4 -> V_11 -> V_86 ( V_4 , V_84 ,
V_85 , V_83 ) ;
return V_77 ;
}
void F_55 ( struct V_3 * V_4 , T_3 V_84 , T_3 V_85 ,
enum V_82 V_83 )
{
F_30 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_87 )
V_4 -> V_11 -> V_87 ( V_4 , V_84 , V_85 , V_83 ) ;
}
void * F_56 ( struct V_3 * V_4 , unsigned long V_88 )
{
F_30 ( ! V_4 ) ;
return V_4 -> V_11 -> V_62 ( V_4 , V_88 ) ;
}
void F_57 ( struct V_3 * V_4 , unsigned long V_88 ,
void * V_89 )
{
F_30 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_90 )
V_4 -> V_11 -> V_90 ( V_4 , V_88 , V_89 ) ;
}
void * F_58 ( struct V_3 * V_4 , unsigned long V_88 )
{
F_30 ( ! V_4 ) ;
return V_4 -> V_11 -> V_63 ( V_4 , V_88 ) ;
}
void F_59 ( struct V_3 * V_4 , unsigned long V_88 ,
void * V_89 )
{
F_30 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_91 )
V_4 -> V_11 -> V_91 ( V_4 , V_88 , V_89 ) ;
}
int F_60 ( struct V_3 * V_4 , struct V_19 * V_20 ,
unsigned long V_92 )
{
struct V_2 * V_93 ;
int V_77 ;
if ( F_30 ( ! V_4 || ! V_20 ) )
return - V_5 ;
if ( V_92 + ( ( V_20 -> V_22 - V_20 -> V_23 ) >> V_24 ) < V_92 )
return - V_94 ;
if ( V_92 + ( ( V_20 -> V_22 - V_20 -> V_23 ) >> V_24 ) >
V_4 -> V_25 >> V_24 )
return - V_5 ;
F_61 ( V_4 -> V_2 ) ;
V_93 = V_20 -> V_95 ;
V_20 -> V_95 = V_4 -> V_2 ;
V_20 -> V_21 = V_92 ;
V_77 = V_4 -> V_11 -> V_26 ( V_4 , V_20 ) ;
if ( V_77 ) {
V_20 -> V_95 = V_93 ;
F_47 ( V_4 -> V_2 ) ;
} else {
if ( V_93 )
F_47 ( V_93 ) ;
}
return V_77 ;
}
void * F_62 ( struct V_3 * V_4 )
{
void * V_96 ;
if ( F_30 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_11 -> V_97 )
return NULL ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_98 ) ;
V_96 = V_4 -> V_98 ;
goto V_99;
}
F_3 ( V_4 -> V_98 ) ;
V_96 = V_4 -> V_11 -> V_97 ( V_4 ) ;
if ( F_63 ( F_37 ( V_96 ) ) )
V_96 = NULL ;
if ( ! V_96 )
goto V_99;
V_4 -> V_98 = V_96 ;
V_4 -> V_7 = 1 ;
V_99:
F_6 ( & V_4 -> V_14 ) ;
return V_96 ;
}
void F_64 ( struct V_3 * V_4 , void * V_89 )
{
if ( F_30 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_98 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_98 != V_89 ) ;
F_4 ( & V_4 -> V_14 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_11 -> V_100 )
V_4 -> V_11 -> V_100 ( V_4 , V_89 ) ;
V_4 -> V_98 = NULL ;
}
F_6 ( & V_4 -> V_14 ) ;
}
static int F_65 ( struct V_101 * V_102 )
{
int V_77 ;
struct V_3 * V_103 ;
struct V_73 * V_104 ;
int V_105 = 0 , V_106 ;
T_3 V_25 = 0 ;
V_77 = F_66 ( & V_13 . V_14 ) ;
if ( V_77 )
return V_77 ;
F_67 ( V_102 , L_2 ) ;
F_67 ( V_102 , L_3 ) ;
F_68 (buf_obj, &db_list.head, list_node) {
V_77 = F_66 ( & V_103 -> V_14 ) ;
if ( V_77 ) {
F_67 ( V_102 ,
L_4 ) ;
continue;
}
F_69 ( V_102 , L_5 ,
V_103 -> V_25 ,
V_103 -> V_2 -> V_107 , V_103 -> V_2 -> V_68 ,
F_70 ( V_103 -> V_2 ) ,
V_103 -> V_67 ) ;
F_67 ( V_102 , L_6 ) ;
V_106 = 0 ;
F_68 (attach_obj, &buf_obj->attachments, node) {
F_67 ( V_102 , L_7 ) ;
F_69 ( V_102 , L_8 , F_71 ( V_104 -> V_75 ) ) ;
V_106 ++ ;
}
F_69 ( V_102 , L_9 ,
V_106 ) ;
V_105 ++ ;
V_25 += V_103 -> V_25 ;
F_6 ( & V_103 -> V_14 ) ;
}
F_69 ( V_102 , L_10 , V_105 , V_25 ) ;
F_6 ( & V_13 . V_14 ) ;
return 0 ;
}
static int F_72 ( struct V_101 * V_102 , void * V_108 )
{
void (* F_73)( struct V_101 * ) = V_102 -> V_109 ;
F_73 ( V_102 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_75 ( V_2 , F_72 , V_1 -> V_110 ) ;
}
static int F_76 ( void )
{
int V_111 = 0 ;
V_112 = F_77 ( L_11 , NULL ) ;
if ( F_37 ( V_112 ) ) {
V_111 = F_78 ( V_112 ) ;
V_112 = NULL ;
return V_111 ;
}
V_111 = F_79 ( L_12 , F_65 ) ;
if ( V_111 )
F_80 ( L_13 ) ;
return V_111 ;
}
static void F_81 ( void )
{
if ( V_112 )
F_82 ( V_112 ) ;
}
int F_79 ( const char * V_113 ,
int (* F_83)( struct V_101 * ) )
{
struct V_114 * V_115 ;
V_115 = F_84 ( V_113 , V_116 , V_112 ,
F_83 , & V_117 ) ;
return F_85 ( V_115 ) ;
}
static inline int F_76 ( void )
{
return 0 ;
}
static inline void F_81 ( void )
{
}
static int T_4 F_86 ( void )
{
F_39 ( & V_13 . V_14 ) ;
F_40 ( & V_13 . V_71 ) ;
F_76 () ;
return 0 ;
}
static void T_5 F_87 ( void )
{
F_81 () ;
}
