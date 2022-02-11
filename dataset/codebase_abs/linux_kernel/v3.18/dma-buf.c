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
struct V_3 * F_28 ( void * V_55 , const struct V_56 * V_11 ,
T_3 V_24 , int V_37 , const char * V_57 ,
struct V_17 * V_16 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
T_3 V_58 = sizeof( struct V_3 ) ;
if ( ! V_16 )
V_58 += sizeof( struct V_17 ) ;
else
V_58 += 1 ;
if ( F_29 ( ! V_55 || ! V_11
|| ! V_11 -> V_59
|| ! V_11 -> V_60
|| ! V_11 -> V_12
|| ! V_11 -> V_61
|| ! V_11 -> V_62
|| ! V_11 -> V_25 ) ) {
return F_30 ( - V_5 ) ;
}
V_4 = F_31 ( V_58 , V_63 ) ;
if ( V_4 == NULL )
return F_30 ( - V_64 ) ;
V_4 -> V_55 = V_55 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_24 = V_24 ;
V_4 -> V_57 = V_57 ;
F_32 ( & V_4 -> V_38 ) ;
V_4 -> V_10 . V_38 = V_4 -> V_8 . V_38 = & V_4 -> V_38 ;
V_4 -> V_10 . V_9 = V_4 -> V_8 . V_9 = 0 ;
if ( ! V_16 ) {
V_16 = (struct V_17 * ) & V_4 [ 1 ] ;
F_33 ( V_16 ) ;
}
V_4 -> V_16 = V_16 ;
V_2 = F_34 ( L_1 , & V_54 , V_4 , V_37 ) ;
if ( F_35 ( V_2 ) ) {
F_8 ( V_4 ) ;
return F_36 ( V_2 ) ;
}
V_2 -> V_65 |= V_66 ;
V_4 -> V_2 = V_2 ;
F_37 ( & V_4 -> V_14 ) ;
F_38 ( & V_4 -> V_67 ) ;
F_4 ( & V_13 . V_14 ) ;
F_39 ( & V_4 -> V_15 , & V_13 . V_68 ) ;
F_6 ( & V_13 . V_14 ) ;
return V_4 ;
}
int F_40 ( struct V_3 * V_4 , int V_37 )
{
int V_69 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_69 = F_41 ( V_37 ) ;
if ( V_69 < 0 )
return V_69 ;
F_42 ( V_69 , V_4 -> V_2 ) ;
return V_69 ;
}
struct V_3 * F_43 ( int V_69 )
{
struct V_2 * V_2 ;
V_2 = F_44 ( V_69 ) ;
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
struct V_70 * F_47 ( struct V_3 * V_4 ,
struct V_71 * V_72 )
{
struct V_70 * V_73 ;
int V_74 ;
if ( F_29 ( ! V_4 || ! V_72 ) )
return F_30 ( - V_5 ) ;
V_73 = F_31 ( sizeof( struct V_70 ) , V_63 ) ;
if ( V_73 == NULL )
return F_30 ( - V_64 ) ;
V_73 -> V_72 = V_72 ;
V_73 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_11 -> V_73 ) {
V_74 = V_4 -> V_11 -> V_73 ( V_4 , V_72 , V_73 ) ;
if ( V_74 )
goto V_75;
}
F_39 ( & V_73 -> V_76 , & V_4 -> V_67 ) ;
F_6 ( & V_4 -> V_14 ) ;
return V_73 ;
V_75:
F_8 ( V_73 ) ;
F_6 ( & V_4 -> V_14 ) ;
return F_30 ( V_74 ) ;
}
void F_48 ( struct V_3 * V_4 , struct V_70 * V_73 )
{
if ( F_29 ( ! V_4 || ! V_73 ) )
return;
F_4 ( & V_4 -> V_14 ) ;
F_5 ( & V_73 -> V_76 ) ;
if ( V_4 -> V_11 -> V_77 )
V_4 -> V_11 -> V_77 ( V_4 , V_73 ) ;
F_6 ( & V_4 -> V_14 ) ;
F_8 ( V_73 ) ;
}
struct V_78 * F_49 ( struct V_70 * V_73 ,
enum V_79 V_80 )
{
struct V_78 * V_78 = F_30 ( - V_5 ) ;
F_50 () ;
if ( F_29 ( ! V_73 || ! V_73 -> V_4 ) )
return F_30 ( - V_5 ) ;
V_78 = V_73 -> V_4 -> V_11 -> V_59 ( V_73 , V_80 ) ;
if ( ! V_78 )
V_78 = F_30 ( - V_64 ) ;
return V_78 ;
}
void F_51 ( struct V_70 * V_73 ,
struct V_78 * V_78 ,
enum V_79 V_80 )
{
F_50 () ;
if ( F_29 ( ! V_73 || ! V_73 -> V_4 || ! V_78 ) )
return;
V_73 -> V_4 -> V_11 -> V_60 ( V_73 , V_78 ,
V_80 ) ;
}
int F_52 ( struct V_3 * V_4 , T_3 V_81 , T_3 V_82 ,
enum V_79 V_80 )
{
int V_74 = 0 ;
if ( F_29 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_11 -> V_83 )
V_74 = V_4 -> V_11 -> V_83 ( V_4 , V_81 , V_82 , V_80 ) ;
return V_74 ;
}
void F_53 ( struct V_3 * V_4 , T_3 V_81 , T_3 V_82 ,
enum V_79 V_80 )
{
F_29 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_84 )
V_4 -> V_11 -> V_84 ( V_4 , V_81 , V_82 , V_80 ) ;
}
void * F_54 ( struct V_3 * V_4 , unsigned long V_85 )
{
F_29 ( ! V_4 ) ;
return V_4 -> V_11 -> V_61 ( V_4 , V_85 ) ;
}
void F_55 ( struct V_3 * V_4 , unsigned long V_85 ,
void * V_86 )
{
F_29 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_87 )
V_4 -> V_11 -> V_87 ( V_4 , V_85 , V_86 ) ;
}
void * F_56 ( struct V_3 * V_4 , unsigned long V_85 )
{
F_29 ( ! V_4 ) ;
return V_4 -> V_11 -> V_62 ( V_4 , V_85 ) ;
}
void F_57 ( struct V_3 * V_4 , unsigned long V_85 ,
void * V_86 )
{
F_29 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_88 )
V_4 -> V_11 -> V_88 ( V_4 , V_85 , V_86 ) ;
}
int F_58 ( struct V_3 * V_4 , struct V_18 * V_19 ,
unsigned long V_89 )
{
struct V_2 * V_90 ;
int V_74 ;
if ( F_29 ( ! V_4 || ! V_19 ) )
return - V_5 ;
if ( V_89 + ( ( V_19 -> V_21 - V_19 -> V_22 ) >> V_23 ) < V_89 )
return - V_91 ;
if ( V_89 + ( ( V_19 -> V_21 - V_19 -> V_22 ) >> V_23 ) >
V_4 -> V_24 >> V_23 )
return - V_5 ;
F_59 ( V_4 -> V_2 ) ;
V_90 = V_19 -> V_92 ;
V_19 -> V_92 = V_4 -> V_2 ;
V_19 -> V_20 = V_89 ;
V_74 = V_4 -> V_11 -> V_25 ( V_4 , V_19 ) ;
if ( V_74 ) {
V_19 -> V_92 = V_90 ;
F_45 ( V_4 -> V_2 ) ;
} else {
if ( V_90 )
F_45 ( V_90 ) ;
}
return V_74 ;
}
void * F_60 ( struct V_3 * V_4 )
{
void * V_93 ;
if ( F_29 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_11 -> V_94 )
return NULL ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_95 ) ;
V_93 = V_4 -> V_95 ;
goto V_96;
}
F_3 ( V_4 -> V_95 ) ;
V_93 = V_4 -> V_11 -> V_94 ( V_4 ) ;
if ( F_61 ( F_35 ( V_93 ) ) )
V_93 = NULL ;
if ( ! V_93 )
goto V_96;
V_4 -> V_95 = V_93 ;
V_4 -> V_7 = 1 ;
V_96:
F_6 ( & V_4 -> V_14 ) ;
return V_93 ;
}
void F_62 ( struct V_3 * V_4 , void * V_86 )
{
if ( F_29 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_95 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_95 != V_86 ) ;
F_4 ( & V_4 -> V_14 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_11 -> V_97 )
V_4 -> V_11 -> V_97 ( V_4 , V_86 ) ;
V_4 -> V_95 = NULL ;
}
F_6 ( & V_4 -> V_14 ) ;
}
static int F_63 ( struct V_98 * V_99 )
{
int V_74 ;
struct V_3 * V_100 ;
struct V_70 * V_101 ;
int V_102 = 0 , V_103 ;
T_3 V_24 = 0 ;
V_74 = F_64 ( & V_13 . V_14 ) ;
if ( V_74 )
return V_74 ;
F_65 ( V_99 , L_2 ) ;
F_65 ( V_99 , L_3 ) ;
F_66 (buf_obj, &db_list.head, list_node) {
V_74 = F_64 ( & V_100 -> V_14 ) ;
if ( V_74 ) {
F_65 ( V_99 ,
L_4 ) ;
continue;
}
F_67 ( V_99 , L_5 ,
V_100 -> V_24 ,
V_100 -> V_2 -> V_104 , V_100 -> V_2 -> V_65 ,
F_68 ( V_100 -> V_2 ) ,
V_100 -> V_57 ) ;
F_65 ( V_99 , L_6 ) ;
V_103 = 0 ;
F_66 (attach_obj, &buf_obj->attachments, node) {
F_65 ( V_99 , L_7 ) ;
F_67 ( V_99 , L_8 , F_69 ( V_101 -> V_72 ) ) ;
V_103 ++ ;
}
F_67 ( V_99 , L_9 ,
V_103 ) ;
V_102 ++ ;
V_24 += V_100 -> V_24 ;
F_6 ( & V_100 -> V_14 ) ;
}
F_67 ( V_99 , L_10 , V_102 , V_24 ) ;
F_6 ( & V_13 . V_14 ) ;
return 0 ;
}
static int F_70 ( struct V_98 * V_99 , void * V_105 )
{
void (* F_71)( struct V_98 * ) = V_99 -> V_106 ;
F_71 ( V_99 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_73 ( V_2 , F_70 , V_1 -> V_107 ) ;
}
static int F_74 ( void )
{
int V_108 = 0 ;
V_109 = F_75 ( L_11 , NULL ) ;
if ( F_35 ( V_109 ) ) {
V_108 = F_76 ( V_109 ) ;
V_109 = NULL ;
return V_108 ;
}
V_108 = F_77 ( L_12 , F_63 ) ;
if ( V_108 )
F_78 ( L_13 ) ;
return V_108 ;
}
static void F_79 ( void )
{
if ( V_109 )
F_80 ( V_109 ) ;
}
int F_77 ( const char * V_110 ,
int (* F_81)( struct V_98 * ) )
{
struct V_111 * V_112 ;
V_112 = F_82 ( V_110 , V_113 , V_109 ,
F_81 , & V_114 ) ;
return F_83 ( V_112 ) ;
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
F_38 ( & V_13 . V_68 ) ;
F_74 () ;
return 0 ;
}
static void T_5 F_85 ( void )
{
F_79 () ;
}
