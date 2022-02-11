static inline struct V_1 *
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static inline void
F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) )
F_5 ( V_2 ) ;
}
static void
F_6 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) )
return;
F_1 ( V_2 ) ;
F_9 ( V_6 -> V_10 , V_2 ) ;
F_10 ( V_11 , & V_5 -> V_9 ) ;
F_11 () ;
F_12 ( V_8 , & V_5 -> V_9 ) ;
}
static const void *
F_13 ( const void * V_12 , const void * V_13 , void * V_14 , T_1 V_15 )
{
const void * V_16 = ( const void * ) ( ( const char * ) V_12 + V_15 ) ;
if ( F_14 ( V_16 > V_13 || V_16 < V_12 ) )
return F_15 ( - V_17 ) ;
memcpy ( V_14 , V_12 , V_15 ) ;
return V_16 ;
}
static inline const void *
F_16 ( const void * V_12 , const void * V_13 , struct V_18 * V_19 )
{
const void * V_16 ;
unsigned int V_15 ;
V_12 = F_13 ( V_12 , V_13 , & V_15 , sizeof( V_15 ) ) ;
if ( F_17 ( V_12 ) )
return V_12 ;
V_16 = ( const void * ) ( ( const char * ) V_12 + V_15 ) ;
if ( F_14 ( V_16 > V_13 || V_16 < V_12 ) )
return F_15 ( - V_17 ) ;
V_19 -> V_20 = F_18 ( V_12 , V_15 , V_21 ) ;
if ( F_14 ( V_19 -> V_20 == NULL ) )
return F_15 ( - V_22 ) ;
V_19 -> V_15 = V_15 ;
return V_16 ;
}
static struct V_1 *
F_19 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_1 * V_2 = NULL ;
F_20 () ;
if ( V_6 -> V_10 )
V_2 = F_1 ( V_6 -> V_10 ) ;
F_21 () ;
return V_2 ;
}
static struct V_1 *
F_22 ( void )
{
struct V_1 * V_2 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_21 ) ;
if ( V_2 != NULL ) {
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = 1 ;
F_24 ( & V_2 -> V_26 ) ;
F_25 ( & V_2 -> V_3 , 1 ) ;
}
return V_2 ;
}
static const void *
F_26 ( const void * V_12 , const void * V_13 , struct V_1 * V_2 , struct V_27 * V_28 )
{
const void * V_16 ;
unsigned int V_29 ;
unsigned int V_30 ;
unsigned long V_31 = V_32 ;
T_2 V_33 ;
int V_34 ;
V_12 = F_13 ( V_12 , V_13 , & V_30 , sizeof( V_30 ) ) ;
if ( F_17 ( V_12 ) )
goto V_35;
if ( V_30 == 0 )
V_30 = V_36 ;
V_2 -> V_37 = V_31 + ( ( unsigned long ) V_30 * V_38 ) ;
V_12 = F_13 ( V_12 , V_13 , & V_33 , sizeof( V_33 ) ) ;
if ( F_17 ( V_12 ) )
goto V_35;
V_2 -> V_39 = V_33 ;
if ( V_2 -> V_39 == 0 ) {
V_12 = F_13 ( V_12 , V_13 , & V_34 , sizeof( V_34 ) ) ;
if ( ! F_17 ( V_12 ) )
V_12 = ( V_34 == - V_40 ) ? F_15 ( - V_40 ) :
F_15 ( - V_41 ) ;
goto V_35;
}
V_12 = F_16 ( V_12 , V_13 , & V_2 -> V_42 ) ;
if ( F_17 ( V_12 ) )
goto V_35;
V_12 = F_13 ( V_12 , V_13 , & V_29 , sizeof( V_29 ) ) ;
if ( F_17 ( V_12 ) )
goto V_35;
V_16 = ( const void * ) ( ( const char * ) V_12 + V_29 ) ;
if ( F_14 ( V_16 > V_13 || V_16 < V_12 ) ) {
V_12 = F_15 ( - V_17 ) ;
goto V_35;
}
V_34 = F_27 ( V_12 , V_29 , V_28 , & V_2 -> V_43 , V_21 ) ;
if ( V_34 < 0 ) {
V_12 = F_15 ( V_34 ) ;
goto V_35;
}
F_28 ( L_1 ,
V_44 , V_2 -> V_37 , V_31 , V_30 ) ;
return V_16 ;
V_35:
F_28 ( L_2 , V_44 , - F_29 ( V_12 ) ) ;
return V_12 ;
}
static int F_30 ( void )
{
int V_34 ;
F_31 ( & V_45 ) ;
if ( V_46 >= 0 ) {
F_2 ( & V_47 ) ;
V_34 = V_46 ;
} else
V_34 = - V_48 ;
F_32 ( & V_45 ) ;
return V_34 ;
}
static void F_33 ( void )
{
if ( F_34 ( & V_47 , & V_45 ) ) {
V_46 = - 1 ;
F_32 ( & V_45 ) ;
}
}
static void
F_35 ( struct V_49 * V_50 )
{
if ( ! F_4 ( & V_50 -> V_3 ) )
return;
F_33 () ;
F_36 ( ! F_37 ( & V_50 -> V_51 ) ) ;
if ( V_50 -> V_2 != NULL )
F_3 ( V_50 -> V_2 ) ;
F_38 ( & V_50 -> V_52 ) ;
F_39 ( V_50 ) ;
}
static struct V_49 *
F_40 ( struct V_53 * V_54 , T_3 V_55 )
{
struct V_49 * V_56 ;
F_41 (pos, &pipe->in_downcall, list) {
if ( ! F_42 ( V_56 -> V_55 , V_55 ) )
continue;
F_2 ( & V_56 -> V_3 ) ;
F_28 ( L_3 , V_44 , V_56 ) ;
return V_56 ;
}
F_28 ( L_4 , V_44 ) ;
return NULL ;
}
static inline struct V_49 *
F_43 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_54 ;
struct V_49 * V_57 ;
F_31 ( & V_54 -> V_58 ) ;
V_57 = F_40 ( V_54 , V_50 -> V_55 ) ;
if ( V_57 == NULL ) {
F_2 ( & V_50 -> V_3 ) ;
F_44 ( & V_50 -> V_51 , & V_54 -> V_59 ) ;
} else
V_50 = V_57 ;
F_32 ( & V_54 -> V_58 ) ;
return V_50 ;
}
static void
F_45 ( struct V_49 * V_50 )
{
F_46 ( & V_50 -> V_51 ) ;
F_47 ( & V_50 -> V_52 , V_50 -> V_60 . V_61 ) ;
F_48 ( & V_50 -> V_62 ) ;
F_49 ( & V_50 -> V_3 ) ;
}
static void
F_50 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_54 ;
if ( F_37 ( & V_50 -> V_51 ) )
return;
F_31 ( & V_54 -> V_58 ) ;
if ( ! F_37 ( & V_50 -> V_51 ) )
F_45 ( V_50 ) ;
F_32 ( & V_54 -> V_58 ) ;
}
static void
F_51 ( struct V_6 * V_6 , struct V_49 * V_50 )
{
switch ( V_50 -> V_60 . V_61 ) {
case 0 :
if ( V_50 -> V_2 == NULL )
break;
F_12 ( V_63 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_50 -> V_2 ) ;
break;
case - V_40 :
F_10 ( V_63 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_64 = V_32 ;
V_6 -> V_65 = NULL ;
F_47 ( & V_50 -> V_52 , V_50 -> V_60 . V_61 ) ;
}
static void
F_52 ( struct V_66 * V_67 )
{
struct V_6 * V_6 = F_7 ( V_67 -> V_68 -> V_69 ,
struct V_6 , V_7 ) ;
struct V_49 * V_50 = V_6 -> V_65 ;
struct V_53 * V_54 = V_50 -> V_54 ;
F_31 ( & V_54 -> V_58 ) ;
F_51 ( V_6 , V_50 ) ;
F_32 ( & V_54 -> V_58 ) ;
V_67 -> V_70 = V_50 -> V_60 . V_61 ;
F_35 ( V_50 ) ;
}
static void F_53 ( struct V_49 * V_50 )
{
T_4 V_55 = F_54 ( & V_71 , V_50 -> V_55 ) ;
memcpy ( V_50 -> V_72 , & V_55 , sizeof( V_55 ) ) ;
V_50 -> V_60 . V_20 = V_50 -> V_72 ;
V_50 -> V_60 . V_15 = sizeof( V_55 ) ;
F_36 ( sizeof( V_55 ) > V_73 ) ;
}
static void F_55 ( struct V_49 * V_50 ,
struct V_74 * V_75 ,
const char * V_76 )
{
struct V_27 * V_77 = V_50 -> V_78 -> V_77 ;
char * V_12 = V_50 -> V_72 ;
int V_15 = 0 ;
V_50 -> V_60 . V_15 = sprintf ( V_50 -> V_72 , L_5 ,
V_77 -> V_79 ,
F_54 ( & V_71 , V_50 -> V_55 ) ) ;
V_12 += V_50 -> V_60 . V_15 ;
if ( V_75 -> V_80 ) {
V_15 = sprintf ( V_12 , L_6 , V_75 -> V_80 ) ;
V_12 += V_15 ;
V_50 -> V_60 . V_15 += V_15 ;
}
if ( V_76 != NULL ) {
V_15 = sprintf ( V_12 , L_7 , V_76 ) ;
V_12 += V_15 ;
V_50 -> V_60 . V_15 += V_15 ;
}
if ( V_77 -> V_81 ) {
V_15 = sprintf ( V_12 , L_8 , V_77 -> V_81 ) ;
V_12 += V_15 ;
V_50 -> V_60 . V_15 += V_15 ;
}
V_15 = sprintf ( V_12 , L_9 ) ;
V_50 -> V_60 . V_15 += V_15 ;
V_50 -> V_60 . V_20 = V_50 -> V_72 ;
F_36 ( V_50 -> V_60 . V_15 > V_73 ) ;
}
static void F_56 ( struct V_49 * V_50 ,
struct V_74 * V_75 ,
const char * V_76 )
{
if ( V_46 == 0 )
F_53 ( V_50 ) ;
else
F_55 ( V_50 , V_75 , V_76 ) ;
}
static struct V_49 *
F_57 ( struct V_82 * V_82 , struct V_74 * V_75 ,
T_3 V_55 , const char * V_76 )
{
struct V_49 * V_50 ;
int V_83 ;
V_50 = F_23 ( sizeof( * V_50 ) , V_21 ) ;
if ( V_50 == NULL )
return F_15 ( - V_22 ) ;
V_83 = F_30 () ;
if ( V_83 < 0 ) {
F_39 ( V_50 ) ;
return F_15 ( V_83 ) ;
}
V_50 -> V_54 = V_82 -> V_54 [ V_83 ] ;
F_58 ( & V_50 -> V_51 ) ;
F_59 ( & V_50 -> V_52 , L_10 ) ;
F_60 ( & V_50 -> V_62 ) ;
F_25 ( & V_50 -> V_3 , 1 ) ;
V_50 -> V_55 = V_55 ;
V_50 -> V_78 = V_82 ;
F_56 ( V_50 , V_75 , V_76 ) ;
return V_50 ;
}
static struct V_49 *
F_61 ( struct V_74 * V_75 , struct V_82 * V_82 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_49 * V_84 , * V_50 ;
T_3 V_55 = V_5 -> V_85 ;
V_84 = F_57 ( V_82 , V_75 , V_55 , V_6 -> V_86 ) ;
if ( F_17 ( V_84 ) )
return V_84 ;
V_50 = F_43 ( V_84 ) ;
if ( V_50 == V_84 ) {
int V_14 = F_62 ( V_84 -> V_54 , & V_84 -> V_60 ) ;
if ( V_14 ) {
F_50 ( V_84 ) ;
V_50 = F_15 ( V_14 ) ;
}
} else
F_35 ( V_84 ) ;
return V_50 ;
}
static void F_63 ( void )
{
static unsigned long V_87 ;
unsigned long V_31 = V_32 ;
if ( F_64 ( V_31 , V_87 ) ) {
F_65 ( V_88 L_11
L_12 ) ;
V_87 = V_31 + 15 * V_38 ;
}
}
static inline int
F_66 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_82 * V_82 = F_7 ( V_5 -> V_89 ,
struct V_82 , V_90 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_49 * V_50 ;
struct V_53 * V_54 ;
int V_35 = 0 ;
F_28 ( L_13 ,
V_67 -> V_91 , V_44 , F_54 ( & V_71 , V_5 -> V_85 ) ) ;
V_50 = F_61 ( V_67 -> V_92 , V_82 , V_5 ) ;
if ( F_29 ( V_50 ) == - V_48 ) {
F_63 () ;
V_67 -> V_93 = 15 * V_38 ;
F_67 ( & V_94 , V_67 , NULL ) ;
return - V_48 ;
}
if ( F_17 ( V_50 ) ) {
V_35 = F_29 ( V_50 ) ;
goto V_95;
}
V_54 = V_50 -> V_54 ;
F_31 ( & V_54 -> V_58 ) ;
if ( V_6 -> V_65 != NULL )
F_67 ( & V_6 -> V_65 -> V_52 , V_67 , NULL ) ;
else if ( V_50 -> V_2 == NULL && V_50 -> V_60 . V_61 >= 0 ) {
V_67 -> V_93 = 0 ;
V_6 -> V_65 = V_50 ;
F_2 ( & V_50 -> V_3 ) ;
F_67 ( & V_50 -> V_52 , V_67 , F_52 ) ;
} else {
F_51 ( V_6 , V_50 ) ;
V_35 = V_50 -> V_60 . V_61 ;
}
F_32 ( & V_54 -> V_58 ) ;
F_35 ( V_50 ) ;
V_95:
F_28 ( L_14 ,
V_67 -> V_91 , V_44 ,
F_54 ( & V_71 , V_5 -> V_85 ) , V_35 ) ;
return V_35 ;
}
static inline int
F_68 ( struct V_82 * V_82 , struct V_6 * V_6 )
{
struct V_53 * V_54 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_49 * V_50 ;
F_69 ( V_96 ) ;
int V_35 = 0 ;
F_28 ( L_15 ,
V_44 , F_54 ( & V_71 , V_5 -> V_85 ) ) ;
V_97:
V_50 = F_61 ( V_82 -> V_98 , V_82 , V_5 ) ;
if ( F_29 ( V_50 ) == - V_48 ) {
V_35 = F_70 ( V_99 ,
V_46 >= 0 , 15 * V_38 ) ;
if ( V_46 < 0 ) {
F_63 () ;
V_35 = - V_41 ;
}
if ( V_35 )
goto V_95;
goto V_97;
}
if ( F_17 ( V_50 ) ) {
V_35 = F_29 ( V_50 ) ;
goto V_95;
}
V_54 = V_50 -> V_54 ;
for (; ; ) {
F_71 ( & V_50 -> V_62 , & V_96 , V_100 ) ;
F_31 ( & V_54 -> V_58 ) ;
if ( V_50 -> V_2 != NULL || V_50 -> V_60 . V_61 < 0 ) {
break;
}
F_32 ( & V_54 -> V_58 ) ;
if ( F_72 ( V_101 ) ) {
V_35 = - V_102 ;
goto V_103;
}
F_73 () ;
}
if ( V_50 -> V_2 )
F_6 ( V_5 , V_50 -> V_2 ) ;
else
V_35 = V_50 -> V_60 . V_61 ;
F_32 ( & V_54 -> V_58 ) ;
V_103:
F_74 ( & V_50 -> V_62 , & V_96 ) ;
F_35 ( V_50 ) ;
V_95:
F_28 ( L_16 ,
V_44 , F_54 ( & V_71 , V_5 -> V_85 ) , V_35 ) ;
return V_35 ;
}
static T_5
F_75 ( struct V_104 * V_105 , const char T_6 * V_106 , T_1 V_107 )
{
const void * V_12 , * V_13 ;
void * V_108 ;
struct V_49 * V_50 ;
struct V_53 * V_54 = F_76 ( F_77 ( V_105 ) ) -> V_54 ;
struct V_1 * V_2 ;
T_4 V_109 ;
T_3 V_55 ;
T_5 V_35 = - V_110 ;
if ( V_107 > V_111 )
goto V_95;
V_35 = - V_22 ;
V_108 = F_78 ( V_107 , V_21 ) ;
if ( ! V_108 )
goto V_95;
V_35 = - V_17 ;
if ( F_79 ( V_108 , V_106 , V_107 ) )
goto V_35;
V_13 = ( const void * ) ( ( char * ) V_108 + V_107 ) ;
V_12 = F_13 ( V_108 , V_13 , & V_109 , sizeof( V_109 ) ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
goto V_35;
}
V_55 = F_80 ( & V_71 , V_109 ) ;
if ( ! F_81 ( V_55 ) ) {
V_35 = - V_112 ;
goto V_35;
}
V_35 = - V_22 ;
V_2 = F_22 () ;
if ( V_2 == NULL )
goto V_35;
V_35 = - V_113 ;
F_31 ( & V_54 -> V_58 ) ;
V_50 = F_40 ( V_54 , V_55 ) ;
if ( V_50 == NULL ) {
F_32 ( & V_54 -> V_58 ) ;
goto V_114;
}
F_46 ( & V_50 -> V_51 ) ;
F_32 ( & V_54 -> V_58 ) ;
V_12 = F_26 ( V_12 , V_13 , V_2 , V_50 -> V_78 -> V_77 ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
switch ( V_35 ) {
case - V_41 :
case - V_40 :
V_50 -> V_60 . V_61 = V_35 ;
V_35 = V_107 ;
break;
case - V_17 :
case - V_22 :
case - V_112 :
case - V_115 :
V_50 -> V_60 . V_61 = - V_48 ;
break;
default:
F_65 ( V_116 L_17
L_18 , V_44 , V_35 ) ;
F_82 () ;
}
goto V_117;
}
V_50 -> V_2 = F_1 ( V_2 ) ;
V_35 = V_107 ;
V_117:
F_31 ( & V_54 -> V_58 ) ;
F_45 ( V_50 ) ;
F_32 ( & V_54 -> V_58 ) ;
F_35 ( V_50 ) ;
V_114:
F_3 ( V_2 ) ;
V_35:
F_39 ( V_108 ) ;
V_95:
F_28 ( L_19 , V_44 , V_35 ) ;
return V_35 ;
}
static int F_83 ( struct V_118 * V_118 , int V_119 )
{
int V_34 = 0 ;
F_31 ( & V_45 ) ;
if ( V_46 < 0 ) {
V_46 = V_119 ;
F_84 ( & V_94 ) ;
F_85 ( & V_99 ) ;
} else if ( V_46 != V_119 ) {
V_34 = - V_120 ;
goto V_95;
}
F_2 ( & V_47 ) ;
V_95:
F_32 ( & V_45 ) ;
return V_34 ;
}
static int F_86 ( struct V_118 * V_118 )
{
return F_83 ( V_118 , 0 ) ;
}
static int F_87 ( struct V_118 * V_118 )
{
return F_83 ( V_118 , 1 ) ;
}
static void
F_88 ( struct V_118 * V_118 )
{
struct V_53 * V_54 = F_76 ( V_118 ) -> V_54 ;
struct V_49 * V_50 ;
V_121:
F_31 ( & V_54 -> V_58 ) ;
F_41 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_37 ( & V_50 -> V_60 . V_51 ) )
continue;
V_50 -> V_60 . V_61 = - V_122 ;
F_2 ( & V_50 -> V_3 ) ;
F_45 ( V_50 ) ;
F_32 ( & V_54 -> V_58 ) ;
F_35 ( V_50 ) ;
goto V_121;
}
F_32 ( & V_54 -> V_58 ) ;
F_33 () ;
}
static void
F_89 ( struct V_123 * V_60 )
{
struct V_49 * V_50 = F_7 ( V_60 , struct V_49 , V_60 ) ;
if ( V_60 -> V_61 < 0 ) {
F_28 ( L_20 ,
V_44 , V_50 ) ;
F_2 ( & V_50 -> V_3 ) ;
F_50 ( V_50 ) ;
if ( V_60 -> V_61 == - V_124 )
F_63 () ;
F_35 ( V_50 ) ;
}
}
static void F_90 ( struct V_90 * V_78 )
{
struct V_82 * V_82 ;
V_82 = F_7 ( V_78 , struct V_82 , V_90 ) ;
if ( V_82 -> V_54 [ 0 ] -> V_125 )
F_91 ( V_82 -> V_54 [ 0 ] -> V_125 ) ;
if ( V_82 -> V_54 [ 1 ] -> V_125 )
F_91 ( V_82 -> V_54 [ 1 ] -> V_125 ) ;
}
static int F_92 ( struct V_90 * V_78 )
{
int V_35 ;
struct V_82 * V_82 ;
struct V_74 * V_75 ;
V_82 = F_7 ( V_78 , struct V_82 , V_90 ) ;
V_75 = V_82 -> V_98 ;
V_82 -> V_54 [ 1 ] -> V_125 = F_93 ( V_75 -> V_126 ,
L_21 ,
V_75 , V_82 -> V_54 [ 1 ] ) ;
if ( F_17 ( V_82 -> V_54 [ 1 ] -> V_125 ) )
return F_29 ( V_82 -> V_54 [ 1 ] -> V_125 ) ;
V_82 -> V_54 [ 0 ] -> V_125 = F_93 ( V_75 -> V_126 ,
V_82 -> V_77 -> V_79 ,
V_75 , V_82 -> V_54 [ 0 ] ) ;
if ( F_17 ( V_82 -> V_54 [ 0 ] -> V_125 ) ) {
V_35 = F_29 ( V_82 -> V_54 [ 0 ] -> V_125 ) ;
goto V_127;
}
return 0 ;
V_127:
F_91 ( V_82 -> V_54 [ 1 ] -> V_125 ) ;
return V_35 ;
}
static void F_94 ( struct V_74 * V_75 ,
struct V_90 * V_78 )
{
struct V_128 * V_128 = F_95 ( V_75 ) ;
struct V_129 * V_130 ;
V_130 = F_96 ( V_128 ) ;
if ( V_130 ) {
if ( V_75 -> V_126 )
F_90 ( V_78 ) ;
F_97 ( V_128 ) ;
}
}
static int F_98 ( struct V_74 * V_75 ,
struct V_90 * V_78 )
{
struct V_128 * V_128 = F_95 ( V_75 ) ;
struct V_129 * V_130 ;
int V_35 = 0 ;
V_130 = F_96 ( V_128 ) ;
if ( V_130 ) {
if ( V_75 -> V_126 )
V_35 = F_92 ( V_78 ) ;
F_97 ( V_128 ) ;
}
return V_35 ;
}
static struct V_90 *
F_99 ( struct V_74 * V_75 , T_7 V_131 )
{
struct V_82 * V_82 ;
struct V_90 * V_78 ;
int V_35 = - V_22 ;
F_28 ( L_22 , V_75 ) ;
if ( ! F_100 ( V_132 ) )
return F_15 ( V_35 ) ;
if ( ! ( V_82 = F_78 ( sizeof( * V_82 ) , V_133 ) ) )
goto V_134;
V_82 -> V_98 = V_75 ;
V_35 = - V_112 ;
V_82 -> V_77 = F_101 ( V_131 ) ;
if ( ! V_82 -> V_77 ) {
F_65 ( V_88 L_23 ,
V_44 , V_131 ) ;
goto V_135;
}
V_82 -> V_136 = F_102 ( V_82 -> V_77 , V_131 ) ;
if ( V_82 -> V_136 == 0 )
goto V_137;
V_78 = & V_82 -> V_90 ;
V_78 -> V_138 = V_139 >> 2 ;
V_78 -> V_140 = V_141 >> 2 ;
V_78 -> V_142 = & V_143 ;
V_78 -> V_144 = V_131 ;
F_25 ( & V_78 -> V_145 , 1 ) ;
F_103 ( & V_82 -> V_146 ) ;
V_82 -> V_54 [ 1 ] = F_104 ( & V_147 ,
V_148 ) ;
if ( F_17 ( V_82 -> V_54 [ 1 ] ) ) {
V_35 = F_29 ( V_82 -> V_54 [ 1 ] ) ;
goto V_137;
}
V_82 -> V_54 [ 0 ] = F_104 ( & V_149 ,
V_148 ) ;
if ( F_17 ( V_82 -> V_54 [ 0 ] ) ) {
V_35 = F_29 ( V_82 -> V_54 [ 0 ] ) ;
goto V_150;
}
V_35 = F_98 ( V_75 , V_78 ) ;
if ( V_35 )
goto V_151;
V_35 = F_105 ( V_78 ) ;
if ( V_35 )
goto V_152;
return V_78 ;
V_152:
F_94 ( V_75 , V_78 ) ;
V_151:
F_106 ( V_82 -> V_54 [ 0 ] ) ;
V_150:
F_106 ( V_82 -> V_54 [ 1 ] ) ;
V_137:
F_107 ( V_82 -> V_77 ) ;
V_135:
F_39 ( V_82 ) ;
V_134:
F_108 ( V_132 ) ;
return F_15 ( V_35 ) ;
}
static void
F_109 ( struct V_82 * V_82 )
{
F_94 ( V_82 -> V_98 , & V_82 -> V_90 ) ;
F_106 ( V_82 -> V_54 [ 0 ] ) ;
F_106 ( V_82 -> V_54 [ 1 ] ) ;
F_107 ( V_82 -> V_77 ) ;
F_39 ( V_82 ) ;
F_108 ( V_132 ) ;
}
static void
F_110 ( struct V_146 * V_146 )
{
struct V_82 * V_82 = F_7 ( V_146 , struct V_82 , V_146 ) ;
F_109 ( V_82 ) ;
}
static void
F_111 ( struct V_90 * V_78 )
{
struct V_82 * V_82 ;
F_28 ( L_24 ,
V_78 , V_78 -> V_144 ) ;
F_112 ( V_78 ) ;
V_82 = F_7 ( V_78 , struct V_82 , V_90 ) ;
F_113 ( & V_82 -> V_146 , F_110 ) ;
}
static int
F_114 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_82 * V_82 = F_7 ( V_5 -> V_89 , struct V_82 , V_90 ) ;
struct V_66 * V_67 ;
if ( V_6 -> V_10 == NULL ||
F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_6 -> V_10 -> V_23 = V_153 ;
V_5 -> V_154 = & V_155 ;
F_115 ( V_5 ) ;
V_67 = F_116 ( V_82 -> V_98 , V_5 , V_156 | V_157 ) ;
if ( ! F_17 ( V_67 ) )
F_117 ( V_67 ) ;
F_118 ( V_5 ) ;
return 1 ;
}
static void
F_119 ( struct V_1 * V_2 )
{
F_28 ( L_25 , V_44 ) ;
F_120 ( & V_2 -> V_43 ) ;
F_39 ( V_2 -> V_42 . V_20 ) ;
F_39 ( V_2 ) ;
}
static void
F_121 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_7 ( V_159 , struct V_1 , V_160 ) ;
F_119 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_122 ( & V_2 -> V_160 , F_121 ) ;
}
static void
F_123 ( struct V_6 * V_6 )
{
F_28 ( L_26 , V_44 , V_6 ) ;
F_39 ( V_6 ) ;
}
static void
F_124 ( struct V_158 * V_159 )
{
struct V_6 * V_6 = F_7 ( V_159 , struct V_6 , V_7 . V_161 ) ;
F_123 ( V_6 ) ;
}
static void
F_125 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_82 * V_82 = F_7 ( V_5 -> V_89 , struct V_82 , V_90 ) ;
struct V_1 * V_2 = V_6 -> V_10 ;
F_126 ( V_6 -> V_10 , NULL ) ;
F_122 ( & V_5 -> V_161 , F_124 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_113 ( & V_82 -> V_146 , F_110 ) ;
}
static void
F_127 ( struct V_4 * V_5 )
{
if ( F_114 ( V_5 ) )
return;
F_125 ( V_5 ) ;
}
static struct V_4 *
F_128 ( struct V_90 * V_78 , struct V_162 * V_163 , int V_164 )
{
return F_129 ( V_78 , V_163 , V_164 ) ;
}
static struct V_4 *
F_130 ( struct V_90 * V_78 , struct V_162 * V_163 , int V_164 )
{
struct V_82 * V_82 = F_7 ( V_78 , struct V_82 , V_90 ) ;
struct V_6 * V_5 = NULL ;
int V_35 = - V_22 ;
F_28 ( L_27 ,
V_44 , F_54 ( & V_71 , V_163 -> V_55 ) ,
V_78 -> V_144 ) ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_165;
F_131 ( & V_5 -> V_7 , V_163 , V_78 , & V_166 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_167 = V_82 -> V_136 ;
V_5 -> V_86 = NULL ;
if ( V_163 -> V_168 )
V_5 -> V_86 = V_163 -> V_169 ;
F_132 ( & V_82 -> V_146 ) ;
return & V_5 -> V_7 ;
V_165:
F_28 ( L_28 , V_44 , V_35 ) ;
return F_15 ( V_35 ) ;
}
static int
F_133 ( struct V_90 * V_78 , struct V_4 * V_5 )
{
struct V_82 * V_82 = F_7 ( V_78 , struct V_82 , V_90 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_35 ;
do {
V_35 = F_68 ( V_82 , V_6 ) ;
} while ( V_35 == - V_48 );
return V_35 ;
}
static int
F_134 ( struct V_162 * V_163 , struct V_4 * V_170 , int V_164 )
{
struct V_6 * V_6 = F_7 ( V_170 , struct V_6 , V_7 ) ;
if ( F_8 ( V_8 , & V_170 -> V_9 ) )
goto V_95;
if ( F_64 ( V_32 , V_6 -> V_10 -> V_37 ) )
return 0 ;
if ( ! F_8 ( V_11 , & V_170 -> V_9 ) )
return 0 ;
V_95:
if ( V_163 -> V_169 != NULL ) {
if ( V_6 -> V_86 == NULL )
return 0 ;
return strcmp ( V_163 -> V_169 , V_6 -> V_86 ) == 0 ;
}
if ( V_6 -> V_86 != NULL )
return 0 ;
return F_42 ( V_170 -> V_85 , V_163 -> V_55 ) ;
}
static T_8 *
F_135 ( struct V_66 * V_67 , T_8 * V_12 )
{
struct V_171 * V_172 = V_67 -> V_68 ;
struct V_4 * V_5 = V_172 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_173 ;
T_2 V_174 = 0 ;
struct V_18 V_175 ;
struct V_176 V_177 ;
struct V_178 V_179 ;
F_28 ( L_29 , V_67 -> V_91 , V_44 ) ;
* V_12 ++ = F_136 ( V_180 ) ;
V_173 = V_12 ++ ;
F_31 ( & V_2 -> V_26 ) ;
V_172 -> V_181 = V_2 -> V_25 ++ ;
F_32 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_136 ( ( T_2 ) V_182 ) ;
* V_12 ++ = F_136 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_136 ( ( T_2 ) V_172 -> V_181 ) ;
* V_12 ++ = F_136 ( ( T_2 ) V_6 -> V_167 ) ;
V_12 = F_137 ( V_12 , & V_2 -> V_42 ) ;
* V_173 = F_136 ( ( V_12 - ( V_173 + 1 ) ) << 2 ) ;
V_177 . V_183 = F_138 ( V_172 -> V_184 ,
V_172 -> V_185 . V_159 [ 0 ] . V_183 ) ;
V_177 . V_186 = ( V_187 * ) V_12 - ( V_187 * ) V_177 . V_183 ;
F_139 ( & V_177 , & V_179 ) ;
* V_12 ++ = F_136 ( V_180 ) ;
V_175 . V_20 = ( V_187 * ) ( V_12 + 1 ) ;
V_174 = F_140 ( V_2 -> V_43 , & V_179 , & V_175 ) ;
if ( V_174 == V_188 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_174 != 0 ) {
F_65 ( L_30 , V_174 ) ;
goto V_189;
}
V_12 = F_141 ( V_12 , NULL , V_175 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_189:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_142 ( struct V_66 * V_67 )
{
struct V_4 * V_190 = V_67 -> V_68 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_190 ,
struct V_6 ,
V_7 ) ;
struct V_90 * V_78 = V_190 -> V_89 ;
struct V_162 V_163 = {
. V_55 = V_190 -> V_85 ,
. V_169 = V_6 -> V_86 ,
. V_168 = ( V_6 -> V_86 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_191 ;
V_191 = F_128 ( V_78 , & V_163 , V_192 ) ;
if ( F_17 ( V_191 ) )
return F_29 ( V_191 ) ;
V_67 -> V_68 -> V_69 = V_191 ;
F_118 ( V_190 ) ;
return 0 ;
}
static int F_143 ( struct V_4 * V_5 )
{
if ( F_8 ( V_63 , & V_5 -> V_9 ) ) {
unsigned long V_31 = V_32 ;
unsigned long V_193 , V_194 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_193 = V_6 -> V_64 ;
V_194 = V_193 + V_195 * V_38 ;
if ( F_144 ( V_31 , V_193 , V_194 ) )
return 1 ;
}
return 0 ;
}
static int
F_145 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
int V_34 = 0 ;
if ( F_143 ( V_5 ) )
return - V_40 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_34 = F_142 ( V_67 ) ;
if ( V_34 < 0 )
goto V_95;
V_5 = V_67 -> V_68 -> V_69 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_34 = F_66 ( V_67 ) ;
V_95:
return V_34 ;
}
static int
F_146 ( struct V_66 * V_67 )
{
return - V_41 ;
}
static T_8 *
F_147 ( struct V_66 * V_67 , T_8 * V_12 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 V_196 ;
struct V_176 V_177 ;
struct V_178 V_179 ;
struct V_18 V_175 ;
T_2 V_197 , V_15 ;
T_2 V_174 ;
F_28 ( L_29 , V_67 -> V_91 , V_44 ) ;
V_197 = F_148 ( * V_12 ++ ) ;
if ( ( V_15 = F_148 ( * V_12 ++ ) ) > V_198 )
goto V_199;
if ( V_197 != V_180 )
goto V_199;
V_196 = F_136 ( V_67 -> V_68 -> V_181 ) ;
V_177 . V_183 = & V_196 ;
V_177 . V_186 = sizeof( V_196 ) ;
F_139 ( & V_177 , & V_179 ) ;
V_175 . V_20 = ( V_187 * ) V_12 ;
V_175 . V_15 = V_15 ;
V_174 = F_149 ( V_2 -> V_43 , & V_179 , & V_175 ) ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_174 ) {
F_28 ( L_31 ,
V_67 -> V_91 , V_44 , V_174 ) ;
goto V_199;
}
V_5 -> V_89 -> V_200 = F_150 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_28 ( L_32 ,
V_67 -> V_91 , V_44 ) ;
return V_12 + F_150 ( V_15 ) ;
V_199:
F_3 ( V_2 ) ;
F_28 ( L_33 , V_67 -> V_91 , V_44 ) ;
return NULL ;
}
static void F_151 ( T_9 V_201 , struct V_171 * V_202 ,
T_8 * V_12 , void * V_203 )
{
struct V_204 V_205 ;
F_152 ( & V_205 , & V_202 -> V_185 , V_12 ) ;
V_201 ( V_202 , & V_205 , V_203 ) ;
}
static inline int
F_153 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_201 , struct V_171 * V_202 ,
T_8 * V_12 , void * V_203 )
{
struct V_178 * V_206 = & V_202 -> V_185 ;
struct V_178 V_207 ;
T_8 * V_208 = NULL ;
struct V_18 V_175 ;
T_2 V_209 ;
T_8 * V_16 ;
struct V_176 * V_177 ;
T_2 V_174 = 0 ;
int V_210 = - V_211 ;
V_208 = V_12 ++ ;
V_209 = ( V_187 * ) V_12 - ( V_187 * ) V_206 -> V_159 [ 0 ] . V_183 ;
* V_12 ++ = F_136 ( V_202 -> V_181 ) ;
F_151 ( V_201 , V_202 , V_12 , V_203 ) ;
if ( F_154 ( V_206 , & V_207 ,
V_209 , V_206 -> V_15 - V_209 ) )
return V_210 ;
* V_208 = F_136 ( V_207 . V_15 ) ;
if ( V_206 -> V_212 || V_206 -> V_213 [ 0 ] . V_186 )
V_177 = V_206 -> V_213 ;
else
V_177 = V_206 -> V_159 ;
V_12 = V_177 -> V_183 + V_177 -> V_186 ;
V_175 . V_20 = ( V_187 * ) ( V_12 + 1 ) ;
V_174 = F_140 ( V_2 -> V_43 , & V_207 , & V_175 ) ;
V_210 = - V_211 ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_174 )
return V_210 ;
V_16 = F_141 ( V_12 , NULL , V_175 . V_15 ) ;
V_209 = ( V_187 * ) V_16 - ( V_187 * ) V_12 ;
V_177 -> V_186 += V_209 ;
V_206 -> V_15 += V_209 ;
return 0 ;
}
static void
F_155 ( struct V_171 * V_202 )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < V_202 -> V_215 ; V_214 ++ )
F_156 ( V_202 -> V_216 [ V_214 ] ) ;
F_39 ( V_202 -> V_216 ) ;
}
static int
F_157 ( struct V_171 * V_202 )
{
struct V_178 * V_206 = & V_202 -> V_185 ;
int V_217 , V_218 , V_214 ;
if ( V_206 -> V_212 == 0 ) {
V_202 -> V_215 = 0 ;
return 0 ;
}
V_217 = V_206 -> V_219 >> V_220 ;
V_218 = ( V_206 -> V_219 + V_206 -> V_212 - 1 ) >> V_220 ;
V_202 -> V_215 = V_218 - V_217 + 1 + 1 ;
V_202 -> V_216
= F_78 ( V_202 -> V_215 * sizeof( struct V_221 * ) ,
V_21 ) ;
if ( ! V_202 -> V_216 )
goto V_95;
for ( V_214 = 0 ; V_214 < V_202 -> V_215 ; V_214 ++ ) {
V_202 -> V_216 [ V_214 ] = F_158 ( V_21 ) ;
if ( V_202 -> V_216 [ V_214 ] == NULL )
goto V_222;
}
V_202 -> V_223 = F_155 ;
return 0 ;
V_222:
V_202 -> V_215 = V_214 ;
F_155 ( V_202 ) ;
V_95:
return - V_48 ;
}
static inline int
F_159 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_201 , struct V_171 * V_202 ,
T_8 * V_12 , void * V_203 )
{
struct V_178 * V_206 = & V_202 -> V_185 ;
T_2 V_209 ;
T_2 V_174 ;
int V_210 ;
T_8 * V_224 ;
struct V_221 * * V_225 ;
int V_217 ;
int V_226 ;
struct V_176 * V_177 ;
char * V_227 ;
V_224 = V_12 ++ ;
V_209 = ( V_187 * ) V_12 - ( V_187 * ) V_206 -> V_159 [ 0 ] . V_183 ;
* V_12 ++ = F_136 ( V_202 -> V_181 ) ;
F_151 ( V_201 , V_202 , V_12 , V_203 ) ;
V_210 = F_157 ( V_202 ) ;
if ( V_210 )
return V_210 ;
V_217 = V_206 -> V_219 >> V_220 ;
V_225 = V_206 -> V_228 + V_217 ;
V_206 -> V_228 = V_202 -> V_216 ;
V_206 -> V_219 -= V_217 << V_220 ;
if ( V_206 -> V_212 || V_206 -> V_213 [ 0 ] . V_186 ) {
V_227 = F_160 ( V_202 -> V_216 [ V_202 -> V_215 - 1 ] ) ;
memcpy ( V_227 , V_206 -> V_213 [ 0 ] . V_183 , V_206 -> V_213 [ 0 ] . V_186 ) ;
V_206 -> V_213 [ 0 ] . V_183 = V_227 ;
}
V_174 = F_161 ( V_2 -> V_43 , V_209 , V_206 , V_225 ) ;
F_36 ( V_206 -> V_15 > V_206 -> V_229 ) ;
V_210 = - V_211 ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_174 )
return V_210 ;
* V_224 = F_136 ( V_206 -> V_15 - V_209 ) ;
if ( V_206 -> V_212 || V_206 -> V_213 [ 0 ] . V_186 )
V_177 = V_206 -> V_213 ;
else
V_177 = V_206 -> V_159 ;
V_12 = V_177 -> V_183 + V_177 -> V_186 ;
V_226 = 3 - ( ( V_206 -> V_15 - V_209 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_226 ) ;
V_177 -> V_186 += V_226 ;
V_206 -> V_15 += V_226 ;
return 0 ;
}
static int
F_162 ( struct V_66 * V_67 ,
T_9 V_201 , void * V_202 , T_8 * V_12 , void * V_203 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_210 = - V_211 ;
F_28 ( L_29 , V_67 -> V_91 , V_44 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_151 ( V_201 , V_202 , V_12 , V_203 ) ;
V_210 = 0 ;
goto V_95;
}
switch ( V_6 -> V_167 ) {
case V_230 :
F_151 ( V_201 , V_202 , V_12 , V_203 ) ;
V_210 = 0 ;
break;
case V_231 :
V_210 = F_153 ( V_5 , V_2 , V_201 , V_202 , V_12 , V_203 ) ;
break;
case V_232 :
V_210 = F_159 ( V_5 , V_2 , V_201 , V_202 , V_12 , V_203 ) ;
break;
}
V_95:
F_3 ( V_2 ) ;
F_28 ( L_34 , V_67 -> V_91 , V_44 , V_210 ) ;
return V_210 ;
}
static inline int
F_163 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_171 * V_202 , T_8 * * V_12 )
{
struct V_178 * V_233 = & V_202 -> V_234 ;
struct V_178 V_207 ;
struct V_18 V_175 ;
T_2 V_235 , V_236 ;
T_2 V_208 ;
T_2 V_174 ;
int V_210 = - V_211 ;
V_208 = F_148 ( * ( * V_12 ) ++ ) ;
if ( V_208 & 3 )
return V_210 ;
V_235 = ( V_187 * ) ( * V_12 ) - ( V_187 * ) V_233 -> V_159 [ 0 ] . V_183 ;
V_236 = V_208 + V_235 ;
if ( V_236 > V_233 -> V_15 )
return V_210 ;
if ( F_148 ( * ( * V_12 ) ++ ) != V_202 -> V_181 )
return V_210 ;
if ( F_154 ( V_233 , & V_207 , V_235 ,
V_236 - V_235 ) )
return V_210 ;
if ( F_164 ( V_233 , & V_175 , V_236 ) )
return V_210 ;
V_174 = F_149 ( V_2 -> V_43 , & V_207 , & V_175 ) ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_174 != V_237 )
return V_210 ;
return 0 ;
}
static inline int
F_165 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_171 * V_202 , T_8 * * V_12 )
{
struct V_178 * V_233 = & V_202 -> V_234 ;
T_2 V_209 ;
T_2 V_224 ;
T_2 V_174 ;
int V_210 = - V_211 ;
V_224 = F_148 ( * ( * V_12 ) ++ ) ;
V_209 = ( V_187 * ) ( * V_12 ) - ( V_187 * ) V_233 -> V_159 [ 0 ] . V_183 ;
if ( V_209 + V_224 > V_233 -> V_15 )
return V_210 ;
V_233 -> V_15 = V_209 + V_224 ;
V_174 = F_166 ( V_2 -> V_43 , V_209 , V_233 ) ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_174 != V_237 )
return V_210 ;
if ( F_148 ( * ( * V_12 ) ++ ) != V_202 -> V_181 )
return V_210 ;
return 0 ;
}
static int
F_167 ( T_10 V_238 , struct V_171 * V_202 ,
T_8 * V_12 , void * V_203 )
{
struct V_204 V_205 ;
F_168 ( & V_205 , & V_202 -> V_234 , V_12 ) ;
return V_238 ( V_202 , & V_205 , V_203 ) ;
}
static int
F_169 ( struct V_66 * V_67 ,
T_10 V_238 , void * V_202 , T_8 * V_12 , void * V_203 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_239 = V_12 ;
struct V_176 * V_159 = ( (struct V_171 * ) V_202 ) -> V_234 . V_159 ;
int V_240 = V_159 -> V_186 ;
int V_210 = - V_211 ;
if ( V_2 -> V_23 != V_24 )
goto V_241;
switch ( V_6 -> V_167 ) {
case V_230 :
break;
case V_231 :
V_210 = F_163 ( V_5 , V_2 , V_202 , & V_12 ) ;
if ( V_210 )
goto V_95;
break;
case V_232 :
V_210 = F_165 ( V_5 , V_2 , V_202 , & V_12 ) ;
if ( V_210 )
goto V_95;
break;
}
V_5 -> V_89 -> V_140 = V_5 -> V_89 -> V_200 + ( V_12 - V_239 )
+ ( V_240 - V_159 -> V_186 ) ;
V_241:
V_210 = F_167 ( V_238 , V_202 , V_12 , V_203 ) ;
V_95:
F_3 ( V_2 ) ;
F_28 ( L_34 ,
V_67 -> V_91 , V_44 , V_210 ) ;
return V_210 ;
}
static T_11 int F_170 ( struct V_128 * V_128 )
{
return F_171 ( V_128 ) ;
}
static T_12 void F_172 ( struct V_128 * V_128 )
{
F_173 ( V_128 ) ;
}
static int T_13 F_174 ( void )
{
int V_35 = 0 ;
V_35 = F_175 ( & V_143 ) ;
if ( V_35 )
goto V_95;
V_35 = F_176 () ;
if ( V_35 )
goto V_242;
V_35 = F_177 ( & V_243 ) ;
if ( V_35 )
goto V_244;
F_59 ( & V_94 , L_35 ) ;
return 0 ;
V_244:
F_178 () ;
V_242:
F_179 ( & V_143 ) ;
V_95:
return V_35 ;
}
static void T_14 F_180 ( void )
{
F_181 ( & V_243 ) ;
F_178 () ;
F_179 ( & V_143 ) ;
F_182 () ;
}
