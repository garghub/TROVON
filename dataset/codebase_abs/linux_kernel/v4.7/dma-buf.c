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
if ( V_20 -> V_21 + F_11 ( V_20 ) >
V_4 -> V_22 >> V_23 )
return - V_5 ;
return V_4 -> V_11 -> V_24 ( V_4 , V_20 ) ;
}
static T_1 F_12 ( struct V_2 * V_2 , T_1 V_25 , int V_26 )
{
struct V_3 * V_4 ;
T_1 V_27 ;
if ( ! F_2 ( V_2 ) )
return - V_28 ;
V_4 = V_2 -> V_6 ;
if ( V_26 == V_29 )
V_27 = V_4 -> V_22 ;
else if ( V_26 == V_30 )
V_27 = 0 ;
else
return - V_5 ;
if ( V_25 != 0 )
return - V_5 ;
return V_27 + V_25 ;
}
static void F_13 ( struct V_31 * V_31 , struct V_32 * V_33 )
{
struct V_34 * V_35 = (struct V_34 * ) V_33 ;
unsigned long V_36 ;
F_14 ( & V_35 -> V_37 -> V_14 , V_36 ) ;
F_15 ( V_35 -> V_37 , V_35 -> V_9 ) ;
V_35 -> V_9 = 0 ;
F_16 ( & V_35 -> V_37 -> V_14 , V_36 ) ;
}
static unsigned int F_17 ( struct V_2 * V_2 , T_2 * V_37 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 ;
struct V_38 * V_39 ;
struct V_31 * V_40 ;
unsigned long V_41 ;
unsigned V_42 , V_43 ;
V_4 = V_2 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_16 )
return V_44 ;
V_16 = V_4 -> V_16 ;
F_18 ( V_2 , & V_4 -> V_37 , V_37 ) ;
V_41 = F_19 ( V_37 ) & ( V_45 | V_46 ) ;
if ( ! V_41 )
return 0 ;
V_47:
V_43 = F_20 ( & V_16 -> V_43 ) ;
F_21 () ;
V_39 = F_22 ( V_16 -> V_31 ) ;
if ( V_39 )
V_42 = V_39 -> V_42 ;
else
V_42 = 0 ;
V_40 = F_22 ( V_16 -> V_40 ) ;
if ( F_23 ( & V_16 -> V_43 , V_43 ) ) {
F_24 () ;
goto V_47;
}
if ( V_40 && ( ! ( V_41 & V_46 ) || V_42 == 0 ) ) {
struct V_34 * V_35 = & V_4 -> V_10 ;
unsigned long V_48 = V_45 ;
if ( V_42 == 0 )
V_48 |= V_46 ;
F_25 ( & V_4 -> V_37 . V_14 ) ;
if ( V_35 -> V_9 ) {
V_35 -> V_9 |= V_48 ;
V_41 &= ~ V_48 ;
} else
V_35 -> V_9 = V_48 ;
F_26 ( & V_4 -> V_37 . V_14 ) ;
if ( V_41 & V_48 ) {
if ( ! F_27 ( V_40 ) ) {
V_41 &= ~ V_48 ;
F_13 ( NULL , & V_35 -> V_33 ) ;
} else if ( ! F_28 ( V_40 , & V_35 -> V_33 ,
F_13 ) ) {
V_41 &= ~ V_48 ;
F_29 ( V_40 ) ;
} else {
F_29 ( V_40 ) ;
F_13 ( NULL , & V_35 -> V_33 ) ;
}
}
}
if ( ( V_41 & V_46 ) && V_42 > 0 ) {
struct V_34 * V_35 = & V_4 -> V_8 ;
int V_49 ;
F_25 ( & V_4 -> V_37 . V_14 ) ;
if ( V_35 -> V_9 )
V_41 &= ~ V_46 ;
else
V_35 -> V_9 = V_46 ;
F_26 ( & V_4 -> V_37 . V_14 ) ;
if ( ! ( V_41 & V_46 ) )
goto V_50;
for ( V_49 = 0 ; V_49 < V_42 ; ++ V_49 ) {
struct V_31 * V_31 = F_22 ( V_39 -> V_51 [ V_49 ] ) ;
if ( ! F_27 ( V_31 ) ) {
V_41 &= ~ V_46 ;
F_13 ( NULL , & V_35 -> V_33 ) ;
break;
}
if ( ! F_28 ( V_31 , & V_35 -> V_33 ,
F_13 ) ) {
F_29 ( V_31 ) ;
V_41 &= ~ V_46 ;
break;
}
F_29 ( V_31 ) ;
}
if ( V_49 == V_42 )
F_13 ( NULL , & V_35 -> V_33 ) ;
}
V_50:
F_24 () ;
return V_41 ;
}
static long F_30 ( struct V_2 * V_2 ,
unsigned int V_52 , unsigned long V_53 )
{
struct V_3 * V_4 ;
struct V_54 V_55 ;
enum V_56 V_57 ;
int V_58 ;
V_4 = V_2 -> V_6 ;
switch ( V_52 ) {
case V_59 :
if ( F_31 ( & V_55 , ( void V_60 * ) V_53 , sizeof( V_55 ) ) )
return - V_61 ;
if ( V_55 . V_36 & ~ V_62 )
return - V_5 ;
switch ( V_55 . V_36 & V_63 ) {
case V_64 :
V_57 = V_65 ;
break;
case V_66 :
V_57 = V_67 ;
break;
case V_63 :
V_57 = V_68 ;
break;
default:
return - V_5 ;
}
if ( V_55 . V_36 & V_69 )
V_58 = F_32 ( V_4 , V_57 ) ;
else
V_58 = F_33 ( V_4 , V_57 ) ;
return V_58 ;
default:
return - V_70 ;
}
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_71 == & V_72 ;
}
struct V_3 * F_34 ( const struct V_73 * V_74 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 = V_74 -> V_16 ;
struct V_2 * V_2 ;
T_3 V_75 = sizeof( struct V_3 ) ;
if ( ! V_74 -> V_16 )
V_75 += sizeof( struct V_17 ) ;
else
V_75 += 1 ;
if ( F_35 ( ! V_74 -> V_76
|| ! V_74 -> V_11
|| ! V_74 -> V_11 -> V_77
|| ! V_74 -> V_11 -> V_78
|| ! V_74 -> V_11 -> V_12
|| ! V_74 -> V_11 -> V_79
|| ! V_74 -> V_11 -> V_80
|| ! V_74 -> V_11 -> V_24 ) ) {
return F_36 ( - V_5 ) ;
}
if ( ! F_37 ( V_74 -> V_18 ) )
return F_36 ( - V_81 ) ;
V_4 = F_38 ( V_75 , V_82 ) ;
if ( ! V_4 ) {
F_8 ( V_74 -> V_18 ) ;
return F_36 ( - V_83 ) ;
}
V_4 -> V_76 = V_74 -> V_76 ;
V_4 -> V_11 = V_74 -> V_11 ;
V_4 -> V_22 = V_74 -> V_22 ;
V_4 -> V_84 = V_74 -> V_84 ;
V_4 -> V_18 = V_74 -> V_18 ;
F_39 ( & V_4 -> V_37 ) ;
V_4 -> V_10 . V_37 = V_4 -> V_8 . V_37 = & V_4 -> V_37 ;
V_4 -> V_10 . V_9 = V_4 -> V_8 . V_9 = 0 ;
if ( ! V_16 ) {
V_16 = (struct V_17 * ) & V_4 [ 1 ] ;
F_40 ( V_16 ) ;
}
V_4 -> V_16 = V_16 ;
V_2 = F_41 ( L_1 , & V_72 , V_4 ,
V_74 -> V_36 ) ;
if ( F_42 ( V_2 ) ) {
F_9 ( V_4 ) ;
return F_43 ( V_2 ) ;
}
V_2 -> V_85 |= V_86 ;
V_4 -> V_2 = V_2 ;
F_44 ( & V_4 -> V_14 ) ;
F_45 ( & V_4 -> V_87 ) ;
F_4 ( & V_13 . V_14 ) ;
F_46 ( & V_4 -> V_15 , & V_13 . V_88 ) ;
F_6 ( & V_13 . V_14 ) ;
return V_4 ;
}
int F_47 ( struct V_3 * V_4 , int V_36 )
{
int V_89 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_89 = F_48 ( V_36 ) ;
if ( V_89 < 0 )
return V_89 ;
F_49 ( V_89 , V_4 -> V_2 ) ;
return V_89 ;
}
struct V_3 * F_50 ( int V_89 )
{
struct V_2 * V_2 ;
V_2 = F_51 ( V_89 ) ;
if ( ! V_2 )
return F_36 ( - V_28 ) ;
if ( ! F_2 ( V_2 ) ) {
F_52 ( V_2 ) ;
return F_36 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_53 ( struct V_3 * V_4 )
{
if ( F_35 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_52 ( V_4 -> V_2 ) ;
}
struct V_90 * F_54 ( struct V_3 * V_4 ,
struct V_91 * V_92 )
{
struct V_90 * V_93 ;
int V_58 ;
if ( F_35 ( ! V_4 || ! V_92 ) )
return F_36 ( - V_5 ) ;
V_93 = F_38 ( sizeof( struct V_90 ) , V_82 ) ;
if ( V_93 == NULL )
return F_36 ( - V_83 ) ;
V_93 -> V_92 = V_92 ;
V_93 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_11 -> V_93 ) {
V_58 = V_4 -> V_11 -> V_93 ( V_4 , V_92 , V_93 ) ;
if ( V_58 )
goto V_94;
}
F_46 ( & V_93 -> V_95 , & V_4 -> V_87 ) ;
F_6 ( & V_4 -> V_14 ) ;
return V_93 ;
V_94:
F_9 ( V_93 ) ;
F_6 ( & V_4 -> V_14 ) ;
return F_36 ( V_58 ) ;
}
void F_55 ( struct V_3 * V_4 , struct V_90 * V_93 )
{
if ( F_35 ( ! V_4 || ! V_93 ) )
return;
F_4 ( & V_4 -> V_14 ) ;
F_5 ( & V_93 -> V_95 ) ;
if ( V_4 -> V_11 -> V_96 )
V_4 -> V_11 -> V_96 ( V_4 , V_93 ) ;
F_6 ( & V_4 -> V_14 ) ;
F_9 ( V_93 ) ;
}
struct V_97 * F_56 ( struct V_90 * V_93 ,
enum V_56 V_57 )
{
struct V_97 * V_97 = F_36 ( - V_5 ) ;
F_57 () ;
if ( F_35 ( ! V_93 || ! V_93 -> V_4 ) )
return F_36 ( - V_5 ) ;
V_97 = V_93 -> V_4 -> V_11 -> V_77 ( V_93 , V_57 ) ;
if ( ! V_97 )
V_97 = F_36 ( - V_83 ) ;
return V_97 ;
}
void F_58 ( struct V_90 * V_93 ,
struct V_97 * V_97 ,
enum V_56 V_57 )
{
F_57 () ;
if ( F_35 ( ! V_93 || ! V_93 -> V_4 || ! V_97 ) )
return;
V_93 -> V_4 -> V_11 -> V_78 ( V_93 , V_97 ,
V_57 ) ;
}
int F_33 ( struct V_3 * V_4 ,
enum V_56 V_57 )
{
int V_58 = 0 ;
if ( F_35 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_11 -> V_98 )
V_58 = V_4 -> V_11 -> V_98 ( V_4 , V_57 ) ;
return V_58 ;
}
int F_32 ( struct V_3 * V_4 ,
enum V_56 V_57 )
{
int V_58 = 0 ;
F_35 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_99 )
V_58 = V_4 -> V_11 -> V_99 ( V_4 , V_57 ) ;
return V_58 ;
}
void * F_59 ( struct V_3 * V_4 , unsigned long V_100 )
{
F_35 ( ! V_4 ) ;
return V_4 -> V_11 -> V_79 ( V_4 , V_100 ) ;
}
void F_60 ( struct V_3 * V_4 , unsigned long V_100 ,
void * V_101 )
{
F_35 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_102 )
V_4 -> V_11 -> V_102 ( V_4 , V_100 , V_101 ) ;
}
void * F_61 ( struct V_3 * V_4 , unsigned long V_100 )
{
F_35 ( ! V_4 ) ;
return V_4 -> V_11 -> V_80 ( V_4 , V_100 ) ;
}
void F_62 ( struct V_3 * V_4 , unsigned long V_100 ,
void * V_101 )
{
F_35 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_103 )
V_4 -> V_11 -> V_103 ( V_4 , V_100 , V_101 ) ;
}
int F_63 ( struct V_3 * V_4 , struct V_19 * V_20 ,
unsigned long V_104 )
{
struct V_2 * V_105 ;
int V_58 ;
if ( F_35 ( ! V_4 || ! V_20 ) )
return - V_5 ;
if ( V_104 + F_11 ( V_20 ) < V_104 )
return - V_106 ;
if ( V_104 + F_11 ( V_20 ) >
V_4 -> V_22 >> V_23 )
return - V_5 ;
F_64 ( V_4 -> V_2 ) ;
V_105 = V_20 -> V_107 ;
V_20 -> V_107 = V_4 -> V_2 ;
V_20 -> V_21 = V_104 ;
V_58 = V_4 -> V_11 -> V_24 ( V_4 , V_20 ) ;
if ( V_58 ) {
V_20 -> V_107 = V_105 ;
F_52 ( V_4 -> V_2 ) ;
} else {
if ( V_105 )
F_52 ( V_105 ) ;
}
return V_58 ;
}
void * F_65 ( struct V_3 * V_4 )
{
void * V_108 ;
if ( F_35 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_11 -> V_109 )
return NULL ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_110 ) ;
V_108 = V_4 -> V_110 ;
goto V_111;
}
F_3 ( V_4 -> V_110 ) ;
V_108 = V_4 -> V_11 -> V_109 ( V_4 ) ;
if ( F_66 ( F_42 ( V_108 ) ) )
V_108 = NULL ;
if ( ! V_108 )
goto V_111;
V_4 -> V_110 = V_108 ;
V_4 -> V_7 = 1 ;
V_111:
F_6 ( & V_4 -> V_14 ) ;
return V_108 ;
}
void F_67 ( struct V_3 * V_4 , void * V_101 )
{
if ( F_35 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_110 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_110 != V_101 ) ;
F_4 ( & V_4 -> V_14 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_11 -> V_112 )
V_4 -> V_11 -> V_112 ( V_4 , V_101 ) ;
V_4 -> V_110 = NULL ;
}
F_6 ( & V_4 -> V_14 ) ;
}
static int F_68 ( struct V_113 * V_114 )
{
int V_58 ;
struct V_3 * V_115 ;
struct V_90 * V_116 ;
int V_117 = 0 , V_118 ;
T_3 V_22 = 0 ;
V_58 = F_69 ( & V_13 . V_14 ) ;
if ( V_58 )
return V_58 ;
F_70 ( V_114 , L_2 ) ;
F_70 ( V_114 , L_3 ) ;
F_71 (buf_obj, &db_list.head, list_node) {
V_58 = F_69 ( & V_115 -> V_14 ) ;
if ( V_58 ) {
F_70 ( V_114 ,
L_4 ) ;
continue;
}
F_72 ( V_114 , L_5 ,
V_115 -> V_22 ,
V_115 -> V_2 -> V_119 , V_115 -> V_2 -> V_85 ,
F_73 ( V_115 -> V_2 ) ,
V_115 -> V_84 ) ;
F_70 ( V_114 , L_6 ) ;
V_118 = 0 ;
F_71 (attach_obj, &buf_obj->attachments, node) {
F_70 ( V_114 , L_7 ) ;
F_72 ( V_114 , L_8 , F_74 ( V_116 -> V_92 ) ) ;
V_118 ++ ;
}
F_72 ( V_114 , L_9 ,
V_118 ) ;
V_117 ++ ;
V_22 += V_115 -> V_22 ;
F_6 ( & V_115 -> V_14 ) ;
}
F_72 ( V_114 , L_10 , V_117 , V_22 ) ;
F_6 ( & V_13 . V_14 ) ;
return 0 ;
}
static int F_75 ( struct V_113 * V_114 , void * V_120 )
{
void (* F_76)( struct V_113 * ) = V_114 -> V_121 ;
F_76 ( V_114 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_78 ( V_2 , F_75 , V_1 -> V_122 ) ;
}
static int F_79 ( void )
{
int V_123 = 0 ;
V_124 = F_80 ( L_11 , NULL ) ;
if ( F_42 ( V_124 ) ) {
V_123 = F_81 ( V_124 ) ;
V_124 = NULL ;
return V_123 ;
}
V_123 = F_82 ( L_12 , F_68 ) ;
if ( V_123 )
F_83 ( L_13 ) ;
return V_123 ;
}
static void F_84 ( void )
{
if ( V_124 )
F_85 ( V_124 ) ;
}
int F_82 ( const char * V_125 ,
int (* F_86)( struct V_113 * ) )
{
struct V_126 * V_127 ;
V_127 = F_87 ( V_125 , V_128 , V_124 ,
F_86 , & V_129 ) ;
return F_88 ( V_127 ) ;
}
static inline int F_79 ( void )
{
return 0 ;
}
static inline void F_84 ( void )
{
}
static int T_4 F_89 ( void )
{
F_44 ( & V_13 . V_14 ) ;
F_45 ( & V_13 . V_88 ) ;
F_79 () ;
return 0 ;
}
static void T_5 F_90 ( void )
{
F_84 () ;
}
