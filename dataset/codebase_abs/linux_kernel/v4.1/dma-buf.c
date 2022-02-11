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
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
if ( V_19 -> V_20 + ( ( V_19 -> V_21 - V_19 -> V_22 ) >> V_23 ) >
V_4 -> V_24 >> V_23 )
return - V_5 ;
return V_4 -> V_11 -> V_25 ( V_4 , V_19 ) ;
}
static T_1 F_10 ( struct V_2 * V_2 , T_1 V_26 , int V_27 )
{
struct V_3 * V_4 ;
T_1 V_28 ;
if ( ! F_2 ( V_2 ) )
return - V_29 ;
V_4 = V_2 -> V_6 ;
if ( V_27 == V_30 )
V_28 = V_4 -> V_24 ;
else if ( V_27 == V_31 )
V_28 = 0 ;
else
return - V_5 ;
if ( V_26 != 0 )
return - V_5 ;
return V_28 + V_26 ;
}
static void F_11 ( struct V_32 * V_32 , struct V_33 * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 ;
unsigned long V_37 ;
F_12 ( & V_36 -> V_38 -> V_14 , V_37 ) ;
F_13 ( V_36 -> V_38 , V_36 -> V_9 ) ;
V_36 -> V_9 = 0 ;
F_14 ( & V_36 -> V_38 -> V_14 , V_37 ) ;
}
static unsigned int F_15 ( struct V_2 * V_2 , T_2 * V_38 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 ;
struct V_39 * V_40 ;
struct V_32 * V_41 ;
unsigned long V_42 ;
unsigned V_43 , V_44 ;
V_4 = V_2 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_16 )
return V_45 ;
V_16 = V_4 -> V_16 ;
F_16 ( V_2 , & V_4 -> V_38 , V_38 ) ;
V_42 = F_17 ( V_38 ) & ( V_46 | V_47 ) ;
if ( ! V_42 )
return 0 ;
V_48:
V_44 = F_18 ( & V_16 -> V_44 ) ;
F_19 () ;
V_40 = F_20 ( V_16 -> V_32 ) ;
if ( V_40 )
V_43 = V_40 -> V_43 ;
else
V_43 = 0 ;
V_41 = F_20 ( V_16 -> V_41 ) ;
if ( F_21 ( & V_16 -> V_44 , V_44 ) ) {
F_22 () ;
goto V_48;
}
if ( V_41 && ( ! ( V_42 & V_47 ) || V_43 == 0 ) ) {
struct V_35 * V_36 = & V_4 -> V_10 ;
unsigned long V_49 = V_46 ;
if ( V_43 == 0 )
V_49 |= V_47 ;
F_23 ( & V_4 -> V_38 . V_14 ) ;
if ( V_36 -> V_9 ) {
V_36 -> V_9 |= V_49 ;
V_42 &= ~ V_49 ;
} else
V_36 -> V_9 = V_49 ;
F_24 ( & V_4 -> V_38 . V_14 ) ;
if ( V_42 & V_49 ) {
if ( ! F_25 ( V_41 ) ) {
V_42 &= ~ V_49 ;
F_11 ( NULL , & V_36 -> V_34 ) ;
} else if ( ! F_26 ( V_41 , & V_36 -> V_34 ,
F_11 ) ) {
V_42 &= ~ V_49 ;
F_27 ( V_41 ) ;
} else {
F_27 ( V_41 ) ;
F_11 ( NULL , & V_36 -> V_34 ) ;
}
}
}
if ( ( V_42 & V_47 ) && V_43 > 0 ) {
struct V_35 * V_36 = & V_4 -> V_8 ;
int V_50 ;
F_23 ( & V_4 -> V_38 . V_14 ) ;
if ( V_36 -> V_9 )
V_42 &= ~ V_47 ;
else
V_36 -> V_9 = V_47 ;
F_24 ( & V_4 -> V_38 . V_14 ) ;
if ( ! ( V_42 & V_47 ) )
goto V_51;
for ( V_50 = 0 ; V_50 < V_43 ; ++ V_50 ) {
struct V_32 * V_32 = F_20 ( V_40 -> V_52 [ V_50 ] ) ;
if ( ! F_25 ( V_32 ) ) {
V_42 &= ~ V_47 ;
F_11 ( NULL , & V_36 -> V_34 ) ;
break;
}
if ( ! F_26 ( V_32 , & V_36 -> V_34 ,
F_11 ) ) {
F_27 ( V_32 ) ;
V_42 &= ~ V_47 ;
break;
}
F_27 ( V_32 ) ;
}
if ( V_50 == V_43 )
F_11 ( NULL , & V_36 -> V_34 ) ;
}
V_51:
F_22 () ;
return V_42 ;
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_53 == & V_54 ;
}
struct V_3 * F_28 ( const struct V_55 * V_56 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 = V_56 -> V_16 ;
struct V_2 * V_2 ;
T_3 V_57 = sizeof( struct V_3 ) ;
if ( ! V_56 -> V_16 )
V_57 += sizeof( struct V_17 ) ;
else
V_57 += 1 ;
if ( F_29 ( ! V_56 -> V_58
|| ! V_56 -> V_11
|| ! V_56 -> V_11 -> V_59
|| ! V_56 -> V_11 -> V_60
|| ! V_56 -> V_11 -> V_12
|| ! V_56 -> V_11 -> V_61
|| ! V_56 -> V_11 -> V_62
|| ! V_56 -> V_11 -> V_25 ) ) {
return F_30 ( - V_5 ) ;
}
V_4 = F_31 ( V_57 , V_63 ) ;
if ( V_4 == NULL )
return F_30 ( - V_64 ) ;
V_4 -> V_58 = V_56 -> V_58 ;
V_4 -> V_11 = V_56 -> V_11 ;
V_4 -> V_24 = V_56 -> V_24 ;
V_4 -> V_65 = V_56 -> V_65 ;
F_32 ( & V_4 -> V_38 ) ;
V_4 -> V_10 . V_38 = V_4 -> V_8 . V_38 = & V_4 -> V_38 ;
V_4 -> V_10 . V_9 = V_4 -> V_8 . V_9 = 0 ;
if ( ! V_16 ) {
V_16 = (struct V_17 * ) & V_4 [ 1 ] ;
F_33 ( V_16 ) ;
}
V_4 -> V_16 = V_16 ;
V_2 = F_34 ( L_1 , & V_54 , V_4 ,
V_56 -> V_37 ) ;
if ( F_35 ( V_2 ) ) {
F_8 ( V_4 ) ;
return F_36 ( V_2 ) ;
}
V_2 -> V_66 |= V_67 ;
V_4 -> V_2 = V_2 ;
F_37 ( & V_4 -> V_14 ) ;
F_38 ( & V_4 -> V_68 ) ;
F_4 ( & V_13 . V_14 ) ;
F_39 ( & V_4 -> V_15 , & V_13 . V_69 ) ;
F_6 ( & V_13 . V_14 ) ;
return V_4 ;
}
int F_40 ( struct V_3 * V_4 , int V_37 )
{
int V_70 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_70 = F_41 ( V_37 ) ;
if ( V_70 < 0 )
return V_70 ;
F_42 ( V_70 , V_4 -> V_2 ) ;
return V_70 ;
}
struct V_3 * F_43 ( int V_70 )
{
struct V_2 * V_2 ;
V_2 = F_44 ( V_70 ) ;
if ( ! V_2 )
return F_30 ( - V_29 ) ;
if ( ! F_2 ( V_2 ) ) {
F_45 ( V_2 ) ;
return F_30 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_46 ( struct V_3 * V_4 )
{
if ( F_29 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_45 ( V_4 -> V_2 ) ;
}
struct V_71 * F_47 ( struct V_3 * V_4 ,
struct V_72 * V_73 )
{
struct V_71 * V_74 ;
int V_75 ;
if ( F_29 ( ! V_4 || ! V_73 ) )
return F_30 ( - V_5 ) ;
V_74 = F_31 ( sizeof( struct V_71 ) , V_63 ) ;
if ( V_74 == NULL )
return F_30 ( - V_64 ) ;
V_74 -> V_73 = V_73 ;
V_74 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_11 -> V_74 ) {
V_75 = V_4 -> V_11 -> V_74 ( V_4 , V_73 , V_74 ) ;
if ( V_75 )
goto V_76;
}
F_39 ( & V_74 -> V_77 , & V_4 -> V_68 ) ;
F_6 ( & V_4 -> V_14 ) ;
return V_74 ;
V_76:
F_8 ( V_74 ) ;
F_6 ( & V_4 -> V_14 ) ;
return F_30 ( V_75 ) ;
}
void F_48 ( struct V_3 * V_4 , struct V_71 * V_74 )
{
if ( F_29 ( ! V_4 || ! V_74 ) )
return;
F_4 ( & V_4 -> V_14 ) ;
F_5 ( & V_74 -> V_77 ) ;
if ( V_4 -> V_11 -> V_78 )
V_4 -> V_11 -> V_78 ( V_4 , V_74 ) ;
F_6 ( & V_4 -> V_14 ) ;
F_8 ( V_74 ) ;
}
struct V_79 * F_49 ( struct V_71 * V_74 ,
enum V_80 V_81 )
{
struct V_79 * V_79 = F_30 ( - V_5 ) ;
F_50 () ;
if ( F_29 ( ! V_74 || ! V_74 -> V_4 ) )
return F_30 ( - V_5 ) ;
V_79 = V_74 -> V_4 -> V_11 -> V_59 ( V_74 , V_81 ) ;
if ( ! V_79 )
V_79 = F_30 ( - V_64 ) ;
return V_79 ;
}
void F_51 ( struct V_71 * V_74 ,
struct V_79 * V_79 ,
enum V_80 V_81 )
{
F_50 () ;
if ( F_29 ( ! V_74 || ! V_74 -> V_4 || ! V_79 ) )
return;
V_74 -> V_4 -> V_11 -> V_60 ( V_74 , V_79 ,
V_81 ) ;
}
int F_52 ( struct V_3 * V_4 , T_3 V_82 , T_3 V_83 ,
enum V_80 V_81 )
{
int V_75 = 0 ;
if ( F_29 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_11 -> V_84 )
V_75 = V_4 -> V_11 -> V_84 ( V_4 , V_82 , V_83 , V_81 ) ;
return V_75 ;
}
void F_53 ( struct V_3 * V_4 , T_3 V_82 , T_3 V_83 ,
enum V_80 V_81 )
{
F_29 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_85 )
V_4 -> V_11 -> V_85 ( V_4 , V_82 , V_83 , V_81 ) ;
}
void * F_54 ( struct V_3 * V_4 , unsigned long V_86 )
{
F_29 ( ! V_4 ) ;
return V_4 -> V_11 -> V_61 ( V_4 , V_86 ) ;
}
void F_55 ( struct V_3 * V_4 , unsigned long V_86 ,
void * V_87 )
{
F_29 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_88 )
V_4 -> V_11 -> V_88 ( V_4 , V_86 , V_87 ) ;
}
void * F_56 ( struct V_3 * V_4 , unsigned long V_86 )
{
F_29 ( ! V_4 ) ;
return V_4 -> V_11 -> V_62 ( V_4 , V_86 ) ;
}
void F_57 ( struct V_3 * V_4 , unsigned long V_86 ,
void * V_87 )
{
F_29 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_89 )
V_4 -> V_11 -> V_89 ( V_4 , V_86 , V_87 ) ;
}
int F_58 ( struct V_3 * V_4 , struct V_18 * V_19 ,
unsigned long V_90 )
{
struct V_2 * V_91 ;
int V_75 ;
if ( F_29 ( ! V_4 || ! V_19 ) )
return - V_5 ;
if ( V_90 + ( ( V_19 -> V_21 - V_19 -> V_22 ) >> V_23 ) < V_90 )
return - V_92 ;
if ( V_90 + ( ( V_19 -> V_21 - V_19 -> V_22 ) >> V_23 ) >
V_4 -> V_24 >> V_23 )
return - V_5 ;
F_59 ( V_4 -> V_2 ) ;
V_91 = V_19 -> V_93 ;
V_19 -> V_93 = V_4 -> V_2 ;
V_19 -> V_20 = V_90 ;
V_75 = V_4 -> V_11 -> V_25 ( V_4 , V_19 ) ;
if ( V_75 ) {
V_19 -> V_93 = V_91 ;
F_45 ( V_4 -> V_2 ) ;
} else {
if ( V_91 )
F_45 ( V_91 ) ;
}
return V_75 ;
}
void * F_60 ( struct V_3 * V_4 )
{
void * V_94 ;
if ( F_29 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_11 -> V_95 )
return NULL ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_96 ) ;
V_94 = V_4 -> V_96 ;
goto V_97;
}
F_3 ( V_4 -> V_96 ) ;
V_94 = V_4 -> V_11 -> V_95 ( V_4 ) ;
if ( F_61 ( F_35 ( V_94 ) ) )
V_94 = NULL ;
if ( ! V_94 )
goto V_97;
V_4 -> V_96 = V_94 ;
V_4 -> V_7 = 1 ;
V_97:
F_6 ( & V_4 -> V_14 ) ;
return V_94 ;
}
void F_62 ( struct V_3 * V_4 , void * V_87 )
{
if ( F_29 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_96 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_96 != V_87 ) ;
F_4 ( & V_4 -> V_14 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_11 -> V_98 )
V_4 -> V_11 -> V_98 ( V_4 , V_87 ) ;
V_4 -> V_96 = NULL ;
}
F_6 ( & V_4 -> V_14 ) ;
}
static int F_63 ( struct V_99 * V_100 )
{
int V_75 ;
struct V_3 * V_101 ;
struct V_71 * V_102 ;
int V_103 = 0 , V_104 ;
T_3 V_24 = 0 ;
V_75 = F_64 ( & V_13 . V_14 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_100 , L_2 ) ;
F_65 ( V_100 , L_3 ) ;
F_66 (buf_obj, &db_list.head, list_node) {
V_75 = F_64 ( & V_101 -> V_14 ) ;
if ( V_75 ) {
F_65 ( V_100 ,
L_4 ) ;
continue;
}
F_67 ( V_100 , L_5 ,
V_101 -> V_24 ,
V_101 -> V_2 -> V_105 , V_101 -> V_2 -> V_66 ,
F_68 ( V_101 -> V_2 ) ,
V_101 -> V_65 ) ;
F_65 ( V_100 , L_6 ) ;
V_104 = 0 ;
F_66 (attach_obj, &buf_obj->attachments, node) {
F_65 ( V_100 , L_7 ) ;
F_67 ( V_100 , L_8 , F_69 ( V_102 -> V_73 ) ) ;
V_104 ++ ;
}
F_67 ( V_100 , L_9 ,
V_104 ) ;
V_103 ++ ;
V_24 += V_101 -> V_24 ;
F_6 ( & V_101 -> V_14 ) ;
}
F_67 ( V_100 , L_10 , V_103 , V_24 ) ;
F_6 ( & V_13 . V_14 ) ;
return 0 ;
}
static int F_70 ( struct V_99 * V_100 , void * V_106 )
{
void (* F_71)( struct V_99 * ) = V_100 -> V_107 ;
F_71 ( V_100 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_73 ( V_2 , F_70 , V_1 -> V_108 ) ;
}
static int F_74 ( void )
{
int V_109 = 0 ;
V_110 = F_75 ( L_11 , NULL ) ;
if ( F_35 ( V_110 ) ) {
V_109 = F_76 ( V_110 ) ;
V_110 = NULL ;
return V_109 ;
}
V_109 = F_77 ( L_12 , F_63 ) ;
if ( V_109 )
F_78 ( L_13 ) ;
return V_109 ;
}
static void F_79 ( void )
{
if ( V_110 )
F_80 ( V_110 ) ;
}
int F_77 ( const char * V_111 ,
int (* F_81)( struct V_99 * ) )
{
struct V_112 * V_113 ;
V_113 = F_82 ( V_111 , V_114 , V_110 ,
F_81 , & V_115 ) ;
return F_83 ( V_113 ) ;
}
static inline int F_74 ( void )
{
return 0 ;
}
static inline void F_79 ( void )
{
}
static int T_4 F_84 ( void )
{
F_37 ( & V_13 . V_14 ) ;
F_38 ( & V_13 . V_69 ) ;
F_74 () ;
return 0 ;
}
static void T_5 F_85 ( void )
{
F_79 () ;
}
