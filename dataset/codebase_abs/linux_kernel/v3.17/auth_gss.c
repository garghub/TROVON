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
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
F_22 () ;
return V_2 ;
}
static struct V_1 *
F_23 ( void )
{
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_21 ) ;
if ( V_2 != NULL ) {
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = 1 ;
F_25 ( & V_2 -> V_26 ) ;
F_26 ( & V_2 -> V_3 , 1 ) ;
}
return V_2 ;
}
static const void *
F_27 ( const void * V_12 , const void * V_13 , struct V_1 * V_2 , struct V_27 * V_28 )
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
V_34 = F_28 ( V_12 , V_29 , V_28 , & V_2 -> V_43 , NULL , V_21 ) ;
if ( V_34 < 0 ) {
V_12 = F_15 ( V_34 ) ;
goto V_35;
}
if ( V_16 == V_13 ) {
V_12 = V_16 ;
goto V_44;
}
V_12 = F_16 ( V_16 , V_13 , & V_2 -> V_45 ) ;
if ( F_17 ( V_12 ) )
goto V_35;
V_44:
F_29 ( L_1 ,
V_46 , V_2 -> V_37 , V_31 , V_30 , V_2 -> V_45 . V_15 ,
V_2 -> V_45 . V_20 ) ;
return V_12 ;
V_35:
F_29 ( L_2 , V_46 , - F_30 ( V_12 ) ) ;
return V_12 ;
}
static int F_31 ( struct V_47 * V_47 )
{
struct V_48 * V_49 = F_32 ( V_47 , V_50 ) ;
int V_34 ;
F_33 ( & V_51 ) ;
if ( V_49 -> V_52 >= 0 ) {
F_2 ( & V_49 -> V_53 ) ;
V_34 = V_49 -> V_52 ;
} else
V_34 = - V_54 ;
F_34 ( & V_51 ) ;
return V_34 ;
}
static void F_35 ( struct V_47 * V_47 )
{
struct V_48 * V_49 = F_32 ( V_47 , V_50 ) ;
if ( F_36 ( & V_49 -> V_53 , & V_51 ) ) {
V_49 -> V_52 = - 1 ;
F_34 ( & V_51 ) ;
}
}
static void
F_37 ( struct V_55 * V_56 )
{
struct V_47 * V_47 = V_56 -> V_57 -> V_47 ;
if ( ! F_4 ( & V_56 -> V_3 ) )
return;
F_35 ( V_47 ) ;
F_38 ( ! F_39 ( & V_56 -> V_58 ) ) ;
if ( V_56 -> V_2 != NULL )
F_3 ( V_56 -> V_2 ) ;
F_40 ( & V_56 -> V_59 ) ;
F_41 ( V_56 -> V_57 ) ;
F_42 ( V_56 ) ;
}
static struct V_55 *
F_43 ( struct V_60 * V_61 , T_3 V_62 )
{
struct V_55 * V_63 ;
F_44 (pos, &pipe->in_downcall, list) {
if ( ! F_45 ( V_63 -> V_62 , V_62 ) )
continue;
F_2 ( & V_63 -> V_3 ) ;
F_29 ( L_3 , V_46 , V_63 ) ;
return V_63 ;
}
F_29 ( L_4 , V_46 ) ;
return NULL ;
}
static inline struct V_55 *
F_46 ( struct V_55 * V_56 )
{
struct V_60 * V_61 = V_56 -> V_61 ;
struct V_55 * V_64 ;
F_33 ( & V_61 -> V_65 ) ;
V_64 = F_43 ( V_61 , V_56 -> V_62 ) ;
if ( V_64 == NULL ) {
F_2 ( & V_56 -> V_3 ) ;
F_47 ( & V_56 -> V_58 , & V_61 -> V_66 ) ;
} else
V_56 = V_64 ;
F_34 ( & V_61 -> V_65 ) ;
return V_56 ;
}
static void
F_48 ( struct V_55 * V_56 )
{
F_49 ( & V_56 -> V_58 ) ;
F_50 ( & V_56 -> V_59 , V_56 -> V_67 . V_68 ) ;
F_51 ( & V_56 -> V_69 ) ;
F_52 ( & V_56 -> V_3 ) ;
}
static void
F_53 ( struct V_55 * V_56 )
{
struct V_60 * V_61 = V_56 -> V_61 ;
if ( F_39 ( & V_56 -> V_58 ) )
return;
F_33 ( & V_61 -> V_65 ) ;
if ( ! F_39 ( & V_56 -> V_58 ) )
F_48 ( V_56 ) ;
F_34 ( & V_61 -> V_65 ) ;
}
static void
F_54 ( struct V_6 * V_6 , struct V_55 * V_56 )
{
switch ( V_56 -> V_67 . V_68 ) {
case 0 :
if ( V_56 -> V_2 == NULL )
break;
F_12 ( V_70 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_56 -> V_2 ) ;
break;
case - V_40 :
F_10 ( V_70 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_71 = V_32 ;
V_6 -> V_72 = NULL ;
F_50 ( & V_56 -> V_59 , V_56 -> V_67 . V_68 ) ;
}
static void
F_55 ( struct V_73 * V_74 )
{
struct V_6 * V_6 = F_7 ( V_74 -> V_75 -> V_76 ,
struct V_6 , V_7 ) ;
struct V_55 * V_56 = V_6 -> V_72 ;
struct V_60 * V_61 = V_56 -> V_61 ;
F_33 ( & V_61 -> V_65 ) ;
F_54 ( V_6 , V_56 ) ;
F_34 ( & V_61 -> V_65 ) ;
V_74 -> V_77 = V_56 -> V_67 . V_68 ;
F_37 ( V_56 ) ;
}
static void F_56 ( struct V_55 * V_56 )
{
T_4 V_62 = F_57 ( & V_78 , V_56 -> V_62 ) ;
memcpy ( V_56 -> V_79 , & V_62 , sizeof( V_62 ) ) ;
V_56 -> V_67 . V_20 = V_56 -> V_79 ;
V_56 -> V_67 . V_15 = sizeof( V_62 ) ;
F_58 ( sizeof( V_62 ) > sizeof( V_56 -> V_79 ) ) ;
}
static int F_59 ( struct V_55 * V_56 ,
const char * V_80 ,
const char * V_81 )
{
struct V_27 * V_82 = V_56 -> V_57 -> V_82 ;
char * V_12 = V_56 -> V_79 ;
T_1 V_83 = sizeof( V_56 -> V_79 ) ;
int V_15 ;
V_15 = F_60 ( V_12 , V_83 , L_5 , V_82 -> V_84 ,
F_57 ( & V_78 , V_56 -> V_62 ) ) ;
V_83 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_67 . V_15 = V_15 ;
if ( V_81 ) {
V_15 = F_60 ( V_12 , V_83 , L_6 , V_81 ) ;
V_83 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_67 . V_15 += V_15 ;
}
if ( V_80 != NULL ) {
V_15 = F_60 ( V_12 , V_83 , L_7 , V_80 ) ;
V_83 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_67 . V_15 += V_15 ;
}
if ( V_82 -> V_85 ) {
V_15 = F_60 ( V_12 , V_83 , L_8 ,
V_82 -> V_85 ) ;
V_83 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_67 . V_15 += V_15 ;
}
V_15 = F_60 ( V_12 , V_83 , L_9 ) ;
if ( V_15 == 0 )
goto V_86;
V_56 -> V_67 . V_15 += V_15 ;
V_56 -> V_67 . V_20 = V_56 -> V_79 ;
return 0 ;
V_86:
F_61 ( 1 ) ;
return - V_22 ;
}
static struct V_55 *
F_62 ( struct V_87 * V_87 ,
T_3 V_62 , const char * V_80 )
{
struct V_55 * V_56 ;
int V_88 ;
int V_35 = - V_22 ;
V_56 = F_24 ( sizeof( * V_56 ) , V_21 ) ;
if ( V_56 == NULL )
goto V_35;
V_88 = F_31 ( V_87 -> V_47 ) ;
V_35 = V_88 ;
if ( V_35 < 0 )
goto V_89;
V_56 -> V_61 = V_87 -> V_90 [ V_88 ] -> V_61 ;
F_63 ( & V_56 -> V_58 ) ;
F_64 ( & V_56 -> V_59 , L_10 ) ;
F_65 ( & V_56 -> V_69 ) ;
F_26 ( & V_56 -> V_3 , 1 ) ;
V_56 -> V_62 = V_62 ;
V_56 -> V_57 = V_87 ;
switch ( V_88 ) {
case 0 :
F_56 ( V_56 ) ;
break;
default:
V_35 = F_59 ( V_56 , V_80 , V_87 -> V_81 ) ;
if ( V_35 )
goto V_91;
} ;
F_66 ( & V_87 -> V_92 ) ;
return V_56 ;
V_91:
F_35 ( V_87 -> V_47 ) ;
V_89:
F_42 ( V_56 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static struct V_55 *
F_67 ( struct V_87 * V_87 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_55 * V_93 , * V_56 ;
T_3 V_62 = V_5 -> V_94 ;
V_93 = F_62 ( V_87 , V_62 , V_6 -> V_95 ) ;
if ( F_17 ( V_93 ) )
return V_93 ;
V_56 = F_46 ( V_93 ) ;
if ( V_56 == V_93 ) {
int V_14 = F_68 ( V_93 -> V_61 , & V_93 -> V_67 ) ;
if ( V_14 ) {
F_53 ( V_93 ) ;
V_56 = F_15 ( V_14 ) ;
}
} else
F_37 ( V_93 ) ;
return V_56 ;
}
static void F_69 ( void )
{
F_29 ( L_11 ) ;
}
static inline int
F_70 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = V_74 -> V_75 -> V_76 ;
struct V_87 * V_87 = F_7 ( V_5 -> V_96 ,
struct V_87 , V_97 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_55 * V_56 ;
struct V_60 * V_61 ;
int V_35 = 0 ;
F_29 ( L_12 ,
V_74 -> V_98 , V_46 , F_57 ( & V_78 , V_5 -> V_94 ) ) ;
V_56 = F_67 ( V_87 , V_5 ) ;
if ( F_30 ( V_56 ) == - V_54 ) {
F_69 () ;
V_74 -> V_99 = 15 * V_38 ;
F_71 ( & V_100 , V_74 , NULL ) ;
return - V_54 ;
}
if ( F_17 ( V_56 ) ) {
V_35 = F_30 ( V_56 ) ;
goto V_101;
}
V_61 = V_56 -> V_61 ;
F_33 ( & V_61 -> V_65 ) ;
if ( V_6 -> V_72 != NULL )
F_71 ( & V_6 -> V_72 -> V_59 , V_74 , NULL ) ;
else if ( V_56 -> V_2 == NULL && V_56 -> V_67 . V_68 >= 0 ) {
V_74 -> V_99 = 0 ;
V_6 -> V_72 = V_56 ;
F_2 ( & V_56 -> V_3 ) ;
F_71 ( & V_56 -> V_59 , V_74 , F_55 ) ;
} else {
F_54 ( V_6 , V_56 ) ;
V_35 = V_56 -> V_67 . V_68 ;
}
F_34 ( & V_61 -> V_65 ) ;
F_37 ( V_56 ) ;
V_101:
F_29 ( L_13 ,
V_74 -> V_98 , V_46 ,
F_57 ( & V_78 , V_5 -> V_94 ) , V_35 ) ;
return V_35 ;
}
static inline int
F_72 ( struct V_87 * V_87 , struct V_6 * V_6 )
{
struct V_47 * V_47 = V_87 -> V_47 ;
struct V_48 * V_49 = F_32 ( V_47 , V_50 ) ;
struct V_60 * V_61 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_55 * V_56 ;
F_73 ( V_102 ) ;
int V_35 ;
F_29 ( L_14 ,
V_46 , F_57 ( & V_78 , V_5 -> V_94 ) ) ;
V_103:
V_35 = 0 ;
if ( ! F_74 ( V_47 ) ) {
F_69 () ;
return - V_41 ;
}
V_56 = F_67 ( V_87 , V_5 ) ;
if ( F_30 ( V_56 ) == - V_54 ) {
V_35 = F_75 ( V_104 ,
V_49 -> V_52 >= 0 , 15 * V_38 ) ;
if ( V_49 -> V_52 < 0 ) {
F_69 () ;
V_35 = - V_41 ;
}
if ( V_35 < 0 )
goto V_101;
goto V_103;
}
if ( F_17 ( V_56 ) ) {
V_35 = F_30 ( V_56 ) ;
goto V_101;
}
V_61 = V_56 -> V_61 ;
for (; ; ) {
F_76 ( & V_56 -> V_69 , & V_102 , V_105 ) ;
F_33 ( & V_61 -> V_65 ) ;
if ( V_56 -> V_2 != NULL || V_56 -> V_67 . V_68 < 0 ) {
break;
}
F_34 ( & V_61 -> V_65 ) ;
if ( F_77 ( V_106 ) ) {
V_35 = - V_107 ;
goto V_108;
}
F_78 () ;
}
if ( V_56 -> V_2 )
F_6 ( V_5 , V_56 -> V_2 ) ;
else
V_35 = V_56 -> V_67 . V_68 ;
F_34 ( & V_61 -> V_65 ) ;
V_108:
F_79 ( & V_56 -> V_69 , & V_102 ) ;
F_37 ( V_56 ) ;
V_101:
F_29 ( L_15 ,
V_46 , F_57 ( & V_78 , V_5 -> V_94 ) , V_35 ) ;
return V_35 ;
}
static T_5
F_80 ( struct V_109 * V_110 , const char T_6 * V_111 , T_1 V_112 )
{
const void * V_12 , * V_13 ;
void * V_113 ;
struct V_55 * V_56 ;
struct V_60 * V_61 = F_81 ( F_82 ( V_110 ) ) -> V_61 ;
struct V_1 * V_2 ;
T_4 V_114 ;
T_3 V_62 ;
T_5 V_35 = - V_115 ;
if ( V_112 > V_116 )
goto V_101;
V_35 = - V_22 ;
V_113 = F_83 ( V_112 , V_21 ) ;
if ( ! V_113 )
goto V_101;
V_35 = - V_17 ;
if ( F_84 ( V_113 , V_111 , V_112 ) )
goto V_35;
V_13 = ( const void * ) ( ( char * ) V_113 + V_112 ) ;
V_12 = F_13 ( V_113 , V_13 , & V_114 , sizeof( V_114 ) ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_30 ( V_12 ) ;
goto V_35;
}
V_62 = F_85 ( & V_78 , V_114 ) ;
if ( ! F_86 ( V_62 ) ) {
V_35 = - V_117 ;
goto V_35;
}
V_35 = - V_22 ;
V_2 = F_23 () ;
if ( V_2 == NULL )
goto V_35;
V_35 = - V_118 ;
F_33 ( & V_61 -> V_65 ) ;
V_56 = F_43 ( V_61 , V_62 ) ;
if ( V_56 == NULL ) {
F_34 ( & V_61 -> V_65 ) ;
goto V_119;
}
F_49 ( & V_56 -> V_58 ) ;
F_34 ( & V_61 -> V_65 ) ;
V_12 = F_27 ( V_12 , V_13 , V_2 , V_56 -> V_57 -> V_82 ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_30 ( V_12 ) ;
switch ( V_35 ) {
case - V_41 :
case - V_40 :
V_56 -> V_67 . V_68 = V_35 ;
V_35 = V_112 ;
break;
case - V_17 :
case - V_22 :
case - V_117 :
case - V_120 :
V_56 -> V_67 . V_68 = - V_54 ;
break;
default:
F_87 ( V_121 L_16
L_17 , V_46 , V_35 ) ;
F_88 () ;
}
goto V_122;
}
V_56 -> V_2 = F_1 ( V_2 ) ;
V_35 = V_112 ;
V_122:
F_33 ( & V_61 -> V_65 ) ;
F_48 ( V_56 ) ;
F_34 ( & V_61 -> V_65 ) ;
F_37 ( V_56 ) ;
V_119:
F_3 ( V_2 ) ;
V_35:
F_42 ( V_113 ) ;
V_101:
F_29 ( L_18 , V_46 , V_35 ) ;
return V_35 ;
}
static int F_89 ( struct V_123 * V_123 , int V_124 )
{
struct V_47 * V_47 = V_123 -> V_125 -> V_126 ;
struct V_48 * V_49 = F_32 ( V_47 , V_50 ) ;
int V_34 = 0 ;
F_33 ( & V_51 ) ;
if ( V_49 -> V_52 < 0 ) {
V_49 -> V_52 = V_124 ;
F_90 ( & V_100 ) ;
F_91 ( & V_104 ) ;
} else if ( V_49 -> V_52 != V_124 ) {
V_34 = - V_127 ;
goto V_101;
}
F_2 ( & V_49 -> V_53 ) ;
V_101:
F_34 ( & V_51 ) ;
return V_34 ;
}
static int F_92 ( struct V_123 * V_123 )
{
return F_89 ( V_123 , 0 ) ;
}
static int F_93 ( struct V_123 * V_123 )
{
return F_89 ( V_123 , 1 ) ;
}
static void
F_94 ( struct V_123 * V_123 )
{
struct V_47 * V_47 = V_123 -> V_125 -> V_126 ;
struct V_60 * V_61 = F_81 ( V_123 ) -> V_61 ;
struct V_55 * V_56 ;
V_128:
F_33 ( & V_61 -> V_65 ) ;
F_44 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_39 ( & V_56 -> V_67 . V_58 ) )
continue;
V_56 -> V_67 . V_68 = - V_129 ;
F_2 ( & V_56 -> V_3 ) ;
F_48 ( V_56 ) ;
F_34 ( & V_61 -> V_65 ) ;
F_37 ( V_56 ) ;
goto V_128;
}
F_34 ( & V_61 -> V_65 ) ;
F_35 ( V_47 ) ;
}
static void
F_95 ( struct V_130 * V_67 )
{
struct V_55 * V_56 = F_7 ( V_67 , struct V_55 , V_67 ) ;
if ( V_67 -> V_68 < 0 ) {
F_29 ( L_19 ,
V_46 , V_56 ) ;
F_2 ( & V_56 -> V_3 ) ;
F_53 ( V_56 ) ;
if ( V_67 -> V_68 == - V_131 )
F_69 () ;
F_37 ( V_56 ) ;
}
}
static void F_96 ( struct V_132 * V_133 ,
struct V_134 * V_135 )
{
struct V_90 * V_90 = V_135 -> V_136 ;
struct V_60 * V_61 = V_90 -> V_61 ;
if ( V_61 -> V_132 != NULL ) {
F_97 ( V_61 -> V_132 ) ;
V_61 -> V_132 = NULL ;
}
}
static int F_98 ( struct V_132 * V_133 ,
struct V_134 * V_135 )
{
struct V_90 * V_12 = V_135 -> V_136 ;
struct V_132 * V_132 ;
V_132 = F_99 ( V_133 , V_12 -> V_137 , V_12 -> V_138 , V_12 -> V_61 ) ;
if ( F_17 ( V_132 ) )
return F_30 ( V_132 ) ;
V_12 -> V_61 -> V_132 = V_132 ;
return 0 ;
}
static struct V_90 * F_100 ( struct V_139 * V_138 ,
const char * V_137 ,
const struct V_140 * V_141 )
{
struct V_90 * V_12 ;
int V_35 = - V_22 ;
V_12 = F_83 ( sizeof( * V_12 ) , V_142 ) ;
if ( V_12 == NULL )
goto V_35;
V_12 -> V_61 = F_101 ( V_141 , V_143 ) ;
if ( F_17 ( V_12 -> V_61 ) ) {
V_35 = F_30 ( V_12 -> V_61 ) ;
goto V_144;
}
V_12 -> V_137 = V_137 ;
V_12 -> V_138 = V_138 ;
F_102 ( & V_12 -> V_92 ) ;
F_103 ( & V_12 -> V_135 ,
& V_145 ,
V_12 ) ;
return V_12 ;
V_144:
F_42 ( V_12 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static int F_104 ( struct V_134 * V_135 , void * V_20 )
{
struct V_90 * V_90 ;
struct V_146 * args = V_20 ;
if ( V_135 -> V_147 != & V_145 )
return 0 ;
V_90 = F_7 ( V_135 , struct V_90 , V_135 ) ;
if ( strcmp ( V_90 -> V_137 , args -> V_137 ) != 0 )
return 0 ;
if ( ! F_105 ( & V_90 -> V_92 ) )
return 0 ;
return 1 ;
}
static struct V_134 * F_106 ( void * V_20 )
{
struct V_90 * V_90 ;
struct V_146 * args = V_20 ;
V_90 = F_100 ( args -> V_138 , args -> V_137 , args -> V_141 ) ;
if ( ! F_17 ( V_90 ) )
return & V_90 -> V_135 ;
return NULL ;
}
static struct V_90 * F_107 ( struct V_139 * V_138 ,
const char * V_137 ,
const struct V_140 * V_141 )
{
struct V_47 * V_47 = F_108 ( V_138 ) ;
struct V_134 * V_135 ;
struct V_146 args = {
. V_138 = V_138 ,
. V_137 = V_137 ,
. V_141 = V_141 ,
} ;
V_135 = F_109 ( V_47 ,
& V_138 -> V_148 ,
F_104 ,
F_106 ,
& args ) ;
if ( V_135 != NULL )
return F_7 ( V_135 , struct V_90 , V_135 ) ;
return F_15 ( - V_22 ) ;
}
static void F_110 ( struct V_90 * V_12 )
{
struct V_139 * V_138 = V_12 -> V_138 ;
struct V_47 * V_47 = F_108 ( V_138 ) ;
F_111 ( V_47 ,
& V_138 -> V_148 ,
& V_12 -> V_135 ) ;
F_112 ( V_12 -> V_61 ) ;
F_42 ( V_12 ) ;
}
static void F_113 ( struct V_92 * V_92 )
{
struct V_90 * V_12 = F_7 ( V_92 , struct V_90 , V_92 ) ;
F_110 ( V_12 ) ;
}
static void F_114 ( struct V_90 * V_12 )
{
if ( V_12 != NULL )
F_115 ( & V_12 -> V_92 , F_113 ) ;
}
static struct V_87 *
F_116 ( struct V_149 * args , struct V_139 * V_138 )
{
T_7 V_150 = args -> V_151 ;
struct V_87 * V_87 ;
struct V_90 * V_90 ;
struct V_97 * V_57 ;
int V_35 = - V_22 ;
F_29 ( L_20 , V_138 ) ;
if ( ! F_117 ( V_152 ) )
return F_15 ( V_35 ) ;
if ( ! ( V_87 = F_83 ( sizeof( * V_87 ) , V_142 ) ) )
goto V_153;
F_118 ( & V_87 -> V_154 ) ;
V_87 -> V_81 = NULL ;
if ( args -> V_81 ) {
V_87 -> V_81 = F_119 ( args -> V_81 , V_142 ) ;
if ( V_87 -> V_81 == NULL )
goto V_155;
}
V_87 -> V_156 = V_138 ;
V_87 -> V_47 = F_120 ( F_108 ( V_138 ) ) ;
V_35 = - V_117 ;
V_87 -> V_82 = F_121 ( V_150 ) ;
if ( ! V_87 -> V_82 ) {
F_29 ( L_21 , V_150 ) ;
goto V_157;
}
V_87 -> V_158 = F_122 ( V_87 -> V_82 , V_150 ) ;
if ( V_87 -> V_158 == 0 )
goto V_159;
if ( ! F_74 ( V_87 -> V_47 ) )
goto V_159;
V_57 = & V_87 -> V_97 ;
V_57 -> V_160 = V_161 >> 2 ;
V_57 -> V_162 = V_163 >> 2 ;
V_57 -> V_164 = & V_165 ;
V_57 -> V_166 = V_150 ;
F_26 ( & V_57 -> V_167 , 1 ) ;
F_102 ( & V_87 -> V_92 ) ;
V_35 = F_123 ( V_57 ) ;
if ( V_35 )
goto V_159;
V_90 = F_107 ( V_138 , L_22 , & V_168 ) ;
if ( F_17 ( V_90 ) ) {
V_35 = F_30 ( V_90 ) ;
goto V_169;
}
V_87 -> V_90 [ 1 ] = V_90 ;
V_90 = F_107 ( V_138 , V_87 -> V_82 -> V_84 ,
& V_170 ) ;
if ( F_17 ( V_90 ) ) {
V_35 = F_30 ( V_90 ) ;
goto V_171;
}
V_87 -> V_90 [ 0 ] = V_90 ;
return V_87 ;
V_171:
F_114 ( V_87 -> V_90 [ 1 ] ) ;
V_169:
F_124 ( V_57 ) ;
V_159:
F_125 ( V_87 -> V_82 ) ;
V_157:
F_126 ( V_87 -> V_47 ) ;
V_155:
F_42 ( V_87 -> V_81 ) ;
F_42 ( V_87 ) ;
V_153:
F_127 ( V_152 ) ;
return F_15 ( V_35 ) ;
}
static void
F_128 ( struct V_87 * V_87 )
{
F_114 ( V_87 -> V_90 [ 0 ] ) ;
F_114 ( V_87 -> V_90 [ 1 ] ) ;
F_125 ( V_87 -> V_82 ) ;
F_126 ( V_87 -> V_47 ) ;
F_42 ( V_87 -> V_81 ) ;
F_42 ( V_87 ) ;
F_127 ( V_152 ) ;
}
static void
F_129 ( struct V_92 * V_92 )
{
struct V_87 * V_87 = F_7 ( V_92 , struct V_87 , V_92 ) ;
F_128 ( V_87 ) ;
}
static void
F_41 ( struct V_87 * V_87 )
{
F_115 ( & V_87 -> V_92 , F_129 ) ;
}
static void
F_130 ( struct V_97 * V_57 )
{
struct V_87 * V_87 = F_7 ( V_57 ,
struct V_87 , V_97 ) ;
F_29 ( L_23 ,
V_57 , V_57 -> V_166 ) ;
if ( F_131 ( & V_87 -> V_154 ) ) {
F_33 ( & V_172 ) ;
F_132 ( & V_87 -> V_154 ) ;
F_34 ( & V_172 ) ;
}
F_114 ( V_87 -> V_90 [ 0 ] ) ;
V_87 -> V_90 [ 0 ] = NULL ;
F_114 ( V_87 -> V_90 [ 1 ] ) ;
V_87 -> V_90 [ 1 ] = NULL ;
F_124 ( V_57 ) ;
F_41 ( V_87 ) ;
}
static struct V_87 *
F_133 ( struct V_149 * args ,
struct V_139 * V_138 ,
struct V_87 * V_173 )
{
struct V_87 * V_87 ;
unsigned long V_174 = ( unsigned long ) V_138 ;
F_33 ( & V_172 ) ;
F_134 (gss_auth_hash_table,
gss_auth,
hash,
hashval) {
if ( V_87 -> V_156 != V_138 )
continue;
if ( V_87 -> V_97 . V_166 != args -> V_151 )
continue;
if ( V_87 -> V_81 != args -> V_81 ) {
if ( V_87 -> V_81 == NULL )
continue;
if ( args -> V_81 == NULL )
continue;
if ( strcmp ( V_87 -> V_81 , args -> V_81 ) )
continue;
}
if ( ! F_135 ( & V_87 -> V_97 . V_167 ) )
continue;
goto V_101;
}
if ( V_173 )
F_136 ( V_175 , & V_173 -> V_154 , V_174 ) ;
V_87 = V_173 ;
V_101:
F_34 ( & V_172 ) ;
return V_87 ;
}
static struct V_87 *
F_137 ( struct V_149 * args , struct V_139 * V_138 )
{
struct V_87 * V_87 ;
struct V_87 * V_173 ;
V_87 = F_133 ( args , V_138 , NULL ) ;
if ( V_87 != NULL )
goto V_101;
V_173 = F_116 ( args , V_138 ) ;
if ( F_17 ( V_173 ) )
return V_173 ;
V_87 = F_133 ( args , V_138 , V_173 ) ;
if ( V_87 != V_173 )
F_130 ( & V_173 -> V_97 ) ;
V_101:
return V_87 ;
}
static struct V_97 *
F_138 ( struct V_149 * args , struct V_139 * V_138 )
{
struct V_87 * V_87 ;
struct V_176 * V_177 = F_139 ( V_138 -> V_178 ) ;
while ( V_138 != V_138 -> V_179 ) {
struct V_139 * V_180 = V_138 -> V_179 ;
if ( F_139 ( V_180 -> V_178 ) != V_177 )
break;
V_138 = V_180 ;
}
V_87 = F_137 ( args , V_138 ) ;
if ( F_17 ( V_87 ) )
return F_140 ( V_87 ) ;
return & V_87 -> V_97 ;
}
static int
F_141 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_87 * V_87 = F_7 ( V_5 -> V_96 , struct V_87 , V_97 ) ;
struct V_1 * V_2 = F_142 ( V_6 -> V_10 , 1 ) ;
struct V_73 * V_74 ;
if ( F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_2 -> V_23 = V_181 ;
V_5 -> V_182 = & V_183 ;
F_143 ( V_5 ) ;
V_74 = F_144 ( V_87 -> V_156 , V_5 , V_184 | V_185 ) ;
if ( ! F_17 ( V_74 ) )
F_145 ( V_74 ) ;
F_146 ( V_5 ) ;
return 1 ;
}
static void
F_147 ( struct V_1 * V_2 )
{
F_29 ( L_24 , V_46 ) ;
F_148 ( & V_2 -> V_43 ) ;
F_42 ( V_2 -> V_42 . V_20 ) ;
F_42 ( V_2 -> V_45 . V_20 ) ;
F_42 ( V_2 ) ;
}
static void
F_149 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_7 ( V_187 , struct V_1 , V_188 ) ;
F_147 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_150 ( & V_2 -> V_188 , F_149 ) ;
}
static void
F_151 ( struct V_6 * V_6 )
{
F_29 ( L_25 , V_46 , V_6 ) ;
F_42 ( V_6 ) ;
}
static void
F_152 ( struct V_186 * V_187 )
{
struct V_6 * V_6 = F_7 ( V_187 , struct V_6 , V_7 . V_189 ) ;
F_151 ( V_6 ) ;
}
static void
F_153 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_87 * V_87 = F_7 ( V_5 -> V_96 , struct V_87 , V_97 ) ;
struct V_1 * V_2 = F_142 ( V_6 -> V_10 , 1 ) ;
F_154 ( V_6 -> V_10 , NULL ) ;
F_150 ( & V_5 -> V_189 , F_152 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_41 ( V_87 ) ;
}
static void
F_155 ( struct V_4 * V_5 )
{
if ( F_141 ( V_5 ) )
return;
F_153 ( V_5 ) ;
}
static struct V_4 *
F_156 ( struct V_97 * V_57 , struct V_190 * V_191 , int V_192 )
{
return F_157 ( V_57 , V_191 , V_192 ) ;
}
static struct V_4 *
F_158 ( struct V_97 * V_57 , struct V_190 * V_191 , int V_192 )
{
struct V_87 * V_87 = F_7 ( V_57 , struct V_87 , V_97 ) ;
struct V_6 * V_5 = NULL ;
int V_35 = - V_22 ;
F_29 ( L_26 ,
V_46 , F_57 ( & V_78 , V_191 -> V_62 ) ,
V_57 -> V_166 ) ;
if ( ! ( V_5 = F_24 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_193;
F_159 ( & V_5 -> V_7 , V_191 , V_57 , & V_194 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_195 = V_87 -> V_158 ;
V_5 -> V_95 = NULL ;
if ( V_191 -> V_196 )
V_5 -> V_95 = V_191 -> V_197 ;
F_66 ( & V_87 -> V_92 ) ;
return & V_5 -> V_7 ;
V_193:
F_29 ( L_27 , V_46 , V_35 ) ;
return F_15 ( V_35 ) ;
}
static int
F_160 ( struct V_97 * V_57 , struct V_4 * V_5 )
{
struct V_87 * V_87 = F_7 ( V_57 , struct V_87 , V_97 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_35 ;
do {
V_35 = F_72 ( V_87 , V_6 ) ;
} while ( V_35 == - V_54 );
return V_35 ;
}
static char *
F_161 ( struct V_4 * V_5 )
{
char * string = NULL ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_1 * V_2 ;
struct V_18 * V_198 ;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( ! V_2 )
goto V_101;
V_198 = & V_2 -> V_45 ;
if ( ! V_198 -> V_15 )
goto V_101;
string = F_83 ( V_198 -> V_15 + 1 , V_142 ) ;
if ( ! string )
goto V_101;
memcpy ( string , V_198 -> V_20 , V_198 -> V_15 ) ;
string [ V_198 -> V_15 ] = '\0' ;
V_101:
F_22 () ;
return string ;
}
static int
F_162 ( struct V_4 * V_199 )
{
struct V_6 * V_6 = F_7 ( V_199 , struct V_6 , V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_31 = V_32 ;
unsigned long V_200 ;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( V_2 )
V_200 = V_2 -> V_37 - ( V_201 * V_38 ) ;
F_22 () ;
if ( ! V_2 || F_163 ( V_31 , V_200 ) )
return - V_41 ;
return 0 ;
}
static int
F_164 ( struct V_190 * V_191 , struct V_4 * V_199 , int V_192 )
{
struct V_6 * V_6 = F_7 ( V_199 , struct V_6 , V_7 ) ;
struct V_1 * V_2 ;
int V_34 ;
if ( F_8 ( V_8 , & V_199 -> V_9 ) )
goto V_101;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( ! V_2 || F_163 ( V_32 , V_2 -> V_37 ) ) {
F_22 () ;
return 0 ;
}
F_22 () ;
if ( ! F_8 ( V_11 , & V_199 -> V_9 ) )
return 0 ;
V_101:
if ( V_191 -> V_197 != NULL ) {
if ( V_6 -> V_95 == NULL )
return 0 ;
V_34 = strcmp ( V_191 -> V_197 , V_6 -> V_95 ) == 0 ;
goto V_202;
}
if ( V_6 -> V_95 != NULL )
return 0 ;
V_34 = F_45 ( V_199 -> V_94 , V_191 -> V_62 ) ;
V_202:
if ( V_34 == 0 )
return V_34 ;
if ( F_8 ( V_203 , & V_191 -> V_204 ) &&
( F_162 ( V_199 ) != 0 ) ) {
F_165 ( V_203 , & V_191 -> V_204 ) ;
F_10 ( V_205 , & V_191 -> V_204 ) ;
}
return V_34 ;
}
static T_8 *
F_166 ( struct V_73 * V_74 , T_8 * V_12 )
{
struct V_206 * V_207 = V_74 -> V_75 ;
struct V_4 * V_5 = V_207 -> V_76 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_208 ;
T_2 V_209 = 0 ;
struct V_18 V_210 ;
struct V_211 V_212 ;
struct V_213 V_214 ;
F_29 ( L_28 , V_74 -> V_98 , V_46 ) ;
* V_12 ++ = F_167 ( V_215 ) ;
V_208 = V_12 ++ ;
F_33 ( & V_2 -> V_26 ) ;
V_207 -> V_216 = V_2 -> V_25 ++ ;
F_34 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_217 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_207 -> V_216 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_6 -> V_195 ) ;
V_12 = F_168 ( V_12 , & V_2 -> V_42 ) ;
* V_208 = F_167 ( ( V_12 - ( V_208 + 1 ) ) << 2 ) ;
V_212 . V_218 = F_169 ( V_207 -> V_219 ,
V_207 -> V_220 . V_187 [ 0 ] . V_218 ) ;
V_212 . V_221 = ( V_222 * ) V_12 - ( V_222 * ) V_212 . V_218 ;
F_170 ( & V_212 , & V_214 ) ;
* V_12 ++ = F_167 ( V_215 ) ;
V_210 . V_20 = ( V_222 * ) ( V_12 + 1 ) ;
V_209 = F_171 ( V_2 -> V_43 , & V_214 , & V_210 ) ;
if ( V_209 == V_223 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_209 != 0 ) {
F_87 ( L_29 , V_209 ) ;
goto V_224;
}
V_12 = F_172 ( V_12 , NULL , V_210 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_224:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_173 ( struct V_73 * V_74 )
{
struct V_4 * V_225 = V_74 -> V_75 -> V_76 ;
struct V_6 * V_6 = F_7 ( V_225 ,
struct V_6 ,
V_7 ) ;
struct V_97 * V_57 = V_225 -> V_96 ;
struct V_190 V_191 = {
. V_62 = V_225 -> V_94 ,
. V_197 = V_6 -> V_95 ,
. V_196 = ( V_6 -> V_95 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_173 ;
V_173 = F_156 ( V_57 , & V_191 , V_226 ) ;
if ( F_17 ( V_173 ) )
return F_30 ( V_173 ) ;
V_74 -> V_75 -> V_76 = V_173 ;
F_146 ( V_225 ) ;
return 0 ;
}
static int F_174 ( struct V_4 * V_5 )
{
if ( F_8 ( V_70 , & V_5 -> V_9 ) ) {
unsigned long V_31 = V_32 ;
unsigned long V_227 , V_200 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_227 = V_6 -> V_71 ;
V_200 = V_227 + V_228 * V_38 ;
if ( F_175 ( V_31 , V_227 , V_200 ) )
return 1 ;
}
return 0 ;
}
static int
F_176 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = V_74 -> V_75 -> V_76 ;
int V_34 = 0 ;
if ( F_174 ( V_5 ) )
return - V_40 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_34 = F_173 ( V_74 ) ;
if ( V_34 < 0 )
goto V_101;
V_5 = V_74 -> V_75 -> V_76 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_34 = F_70 ( V_74 ) ;
V_101:
return V_34 ;
}
static int
F_177 ( struct V_73 * V_74 )
{
return 0 ;
}
static T_8 *
F_178 ( struct V_73 * V_74 , T_8 * V_12 )
{
struct V_4 * V_5 = V_74 -> V_75 -> V_76 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 V_229 ;
struct V_211 V_212 ;
struct V_213 V_214 ;
struct V_18 V_210 ;
T_2 V_230 , V_15 ;
T_2 V_209 ;
T_8 * V_34 = F_15 ( - V_231 ) ;
F_29 ( L_28 , V_74 -> V_98 , V_46 ) ;
V_230 = F_179 ( * V_12 ++ ) ;
if ( ( V_15 = F_179 ( * V_12 ++ ) ) > V_232 )
goto V_233;
if ( V_230 != V_215 )
goto V_233;
V_229 = F_167 ( V_74 -> V_75 -> V_216 ) ;
V_212 . V_218 = & V_229 ;
V_212 . V_221 = sizeof( V_229 ) ;
F_170 ( & V_212 , & V_214 ) ;
V_210 . V_20 = ( V_222 * ) V_12 ;
V_210 . V_15 = V_15 ;
V_34 = F_15 ( - V_41 ) ;
V_209 = F_180 ( V_2 -> V_43 , & V_214 , & V_210 ) ;
if ( V_209 == V_223 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_209 ) {
F_29 ( L_30 ,
V_74 -> V_98 , V_46 , V_209 ) ;
goto V_233;
}
V_5 -> V_96 -> V_234 = F_181 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_29 ( L_31 ,
V_74 -> V_98 , V_46 ) ;
return V_12 + F_181 ( V_15 ) ;
V_233:
F_3 ( V_2 ) ;
F_29 ( L_32 , V_74 -> V_98 , V_46 ,
F_30 ( V_34 ) ) ;
return V_34 ;
}
static void F_182 ( T_9 V_235 , struct V_206 * V_236 ,
T_8 * V_12 , void * V_237 )
{
struct V_238 V_239 ;
F_183 ( & V_239 , & V_236 -> V_220 , V_12 ) ;
V_235 ( V_236 , & V_239 , V_237 ) ;
}
static inline int
F_184 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_235 , struct V_206 * V_236 ,
T_8 * V_12 , void * V_237 )
{
struct V_213 * V_240 = & V_236 -> V_220 ;
struct V_213 V_241 ;
T_8 * V_242 = NULL ;
struct V_18 V_210 ;
T_2 V_243 ;
T_8 * V_16 ;
struct V_211 * V_212 ;
T_2 V_209 = 0 ;
int V_244 = - V_231 ;
V_242 = V_12 ++ ;
V_243 = ( V_222 * ) V_12 - ( V_222 * ) V_240 -> V_187 [ 0 ] . V_218 ;
* V_12 ++ = F_167 ( V_236 -> V_216 ) ;
F_182 ( V_235 , V_236 , V_12 , V_237 ) ;
if ( F_185 ( V_240 , & V_241 ,
V_243 , V_240 -> V_15 - V_243 ) )
return V_244 ;
* V_242 = F_167 ( V_241 . V_15 ) ;
if ( V_240 -> V_245 || V_240 -> V_246 [ 0 ] . V_221 )
V_212 = V_240 -> V_246 ;
else
V_212 = V_240 -> V_187 ;
V_12 = V_212 -> V_218 + V_212 -> V_221 ;
V_210 . V_20 = ( V_222 * ) ( V_12 + 1 ) ;
V_209 = F_171 ( V_2 -> V_43 , & V_241 , & V_210 ) ;
V_244 = - V_231 ;
if ( V_209 == V_223 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_209 )
return V_244 ;
V_16 = F_172 ( V_12 , NULL , V_210 . V_15 ) ;
V_243 = ( V_222 * ) V_16 - ( V_222 * ) V_12 ;
V_212 -> V_221 += V_243 ;
V_240 -> V_15 += V_243 ;
return 0 ;
}
static void
F_186 ( struct V_206 * V_236 )
{
int V_247 ;
for ( V_247 = 0 ; V_247 < V_236 -> V_248 ; V_247 ++ )
F_187 ( V_236 -> V_249 [ V_247 ] ) ;
F_42 ( V_236 -> V_249 ) ;
}
static int
F_188 ( struct V_206 * V_236 )
{
struct V_213 * V_240 = & V_236 -> V_220 ;
int V_250 , V_251 , V_247 ;
if ( V_240 -> V_245 == 0 ) {
V_236 -> V_248 = 0 ;
return 0 ;
}
V_250 = V_240 -> V_252 >> V_253 ;
V_251 = ( V_240 -> V_252 + V_240 -> V_245 - 1 ) >> V_253 ;
V_236 -> V_248 = V_251 - V_250 + 1 + 1 ;
V_236 -> V_249
= F_83 ( V_236 -> V_248 * sizeof( struct V_254 * ) ,
V_21 ) ;
if ( ! V_236 -> V_249 )
goto V_101;
for ( V_247 = 0 ; V_247 < V_236 -> V_248 ; V_247 ++ ) {
V_236 -> V_249 [ V_247 ] = F_189 ( V_21 ) ;
if ( V_236 -> V_249 [ V_247 ] == NULL )
goto V_255;
}
V_236 -> V_256 = F_186 ;
return 0 ;
V_255:
V_236 -> V_248 = V_247 ;
F_186 ( V_236 ) ;
V_101:
return - V_54 ;
}
static inline int
F_190 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_235 , struct V_206 * V_236 ,
T_8 * V_12 , void * V_237 )
{
struct V_213 * V_240 = & V_236 -> V_220 ;
T_2 V_243 ;
T_2 V_209 ;
int V_244 ;
T_8 * V_257 ;
struct V_254 * * V_258 ;
int V_250 ;
int V_259 ;
struct V_211 * V_212 ;
char * V_260 ;
V_257 = V_12 ++ ;
V_243 = ( V_222 * ) V_12 - ( V_222 * ) V_240 -> V_187 [ 0 ] . V_218 ;
* V_12 ++ = F_167 ( V_236 -> V_216 ) ;
F_182 ( V_235 , V_236 , V_12 , V_237 ) ;
V_244 = F_188 ( V_236 ) ;
if ( V_244 )
return V_244 ;
V_250 = V_240 -> V_252 >> V_253 ;
V_258 = V_240 -> V_261 + V_250 ;
V_240 -> V_261 = V_236 -> V_249 ;
V_240 -> V_252 -= V_250 << V_253 ;
if ( V_240 -> V_245 || V_240 -> V_246 [ 0 ] . V_221 ) {
V_260 = F_191 ( V_236 -> V_249 [ V_236 -> V_248 - 1 ] ) ;
memcpy ( V_260 , V_240 -> V_246 [ 0 ] . V_218 , V_240 -> V_246 [ 0 ] . V_221 ) ;
V_240 -> V_246 [ 0 ] . V_218 = V_260 ;
}
V_209 = F_192 ( V_2 -> V_43 , V_243 , V_240 , V_258 ) ;
F_38 ( V_240 -> V_15 > V_240 -> V_83 ) ;
V_244 = - V_231 ;
if ( V_209 == V_223 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_209 )
return V_244 ;
* V_257 = F_167 ( V_240 -> V_15 - V_243 ) ;
if ( V_240 -> V_245 || V_240 -> V_246 [ 0 ] . V_221 )
V_212 = V_240 -> V_246 ;
else
V_212 = V_240 -> V_187 ;
V_12 = V_212 -> V_218 + V_212 -> V_221 ;
V_259 = 3 - ( ( V_240 -> V_15 - V_243 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_259 ) ;
V_212 -> V_221 += V_259 ;
V_240 -> V_15 += V_259 ;
return 0 ;
}
static int
F_193 ( struct V_73 * V_74 ,
T_9 V_235 , void * V_236 , T_8 * V_12 , void * V_237 )
{
struct V_4 * V_5 = V_74 -> V_75 -> V_76 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_244 = - V_231 ;
F_29 ( L_28 , V_74 -> V_98 , V_46 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_182 ( V_235 , V_236 , V_12 , V_237 ) ;
V_244 = 0 ;
goto V_101;
}
switch ( V_6 -> V_195 ) {
case V_262 :
F_182 ( V_235 , V_236 , V_12 , V_237 ) ;
V_244 = 0 ;
break;
case V_263 :
V_244 = F_184 ( V_5 , V_2 , V_235 , V_236 , V_12 , V_237 ) ;
break;
case V_264 :
V_244 = F_190 ( V_5 , V_2 , V_235 , V_236 , V_12 , V_237 ) ;
break;
}
V_101:
F_3 ( V_2 ) ;
F_29 ( L_33 , V_74 -> V_98 , V_46 , V_244 ) ;
return V_244 ;
}
static inline int
F_194 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_206 * V_236 , T_8 * * V_12 )
{
struct V_213 * V_265 = & V_236 -> V_266 ;
struct V_213 V_241 ;
struct V_18 V_210 ;
T_2 V_267 , V_268 ;
T_2 V_242 ;
T_2 V_209 ;
int V_244 = - V_231 ;
V_242 = F_179 ( * ( * V_12 ) ++ ) ;
if ( V_242 & 3 )
return V_244 ;
V_267 = ( V_222 * ) ( * V_12 ) - ( V_222 * ) V_265 -> V_187 [ 0 ] . V_218 ;
V_268 = V_242 + V_267 ;
if ( V_268 > V_265 -> V_15 )
return V_244 ;
if ( F_179 ( * ( * V_12 ) ++ ) != V_236 -> V_216 )
return V_244 ;
if ( F_185 ( V_265 , & V_241 , V_267 ,
V_268 - V_267 ) )
return V_244 ;
if ( F_195 ( V_265 , & V_210 , V_268 ) )
return V_244 ;
V_209 = F_180 ( V_2 -> V_43 , & V_241 , & V_210 ) ;
if ( V_209 == V_223 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_209 != V_269 )
return V_244 ;
return 0 ;
}
static inline int
F_196 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_206 * V_236 , T_8 * * V_12 )
{
struct V_213 * V_265 = & V_236 -> V_266 ;
T_2 V_243 ;
T_2 V_257 ;
T_2 V_209 ;
int V_244 = - V_231 ;
V_257 = F_179 ( * ( * V_12 ) ++ ) ;
V_243 = ( V_222 * ) ( * V_12 ) - ( V_222 * ) V_265 -> V_187 [ 0 ] . V_218 ;
if ( V_243 + V_257 > V_265 -> V_15 )
return V_244 ;
V_265 -> V_15 = V_243 + V_257 ;
V_209 = F_197 ( V_2 -> V_43 , V_243 , V_265 ) ;
if ( V_209 == V_223 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_209 != V_269 )
return V_244 ;
if ( F_179 ( * ( * V_12 ) ++ ) != V_236 -> V_216 )
return V_244 ;
return 0 ;
}
static int
F_198 ( T_10 V_270 , struct V_206 * V_236 ,
T_8 * V_12 , void * V_237 )
{
struct V_238 V_239 ;
F_199 ( & V_239 , & V_236 -> V_266 , V_12 ) ;
return V_270 ( V_236 , & V_239 , V_237 ) ;
}
static int
F_200 ( struct V_73 * V_74 ,
T_10 V_270 , void * V_236 , T_8 * V_12 , void * V_237 )
{
struct V_4 * V_5 = V_74 -> V_75 -> V_76 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_271 = V_12 ;
struct V_211 * V_187 = ( (struct V_206 * ) V_236 ) -> V_266 . V_187 ;
int V_272 = V_187 -> V_221 ;
int V_244 = - V_231 ;
if ( V_2 -> V_23 != V_24 )
goto V_273;
switch ( V_6 -> V_195 ) {
case V_262 :
break;
case V_263 :
V_244 = F_194 ( V_5 , V_2 , V_236 , & V_12 ) ;
if ( V_244 )
goto V_101;
break;
case V_264 :
V_244 = F_196 ( V_5 , V_2 , V_236 , & V_12 ) ;
if ( V_244 )
goto V_101;
break;
}
V_5 -> V_96 -> V_162 = V_5 -> V_96 -> V_234 + ( V_12 - V_271 )
+ ( V_272 - V_187 -> V_221 ) ;
V_273:
V_244 = F_198 ( V_270 , V_236 , V_12 , V_237 ) ;
V_101:
F_3 ( V_2 ) ;
F_29 ( L_33 ,
V_74 -> V_98 , V_46 , V_244 ) ;
return V_244 ;
}
static T_11 int F_201 ( struct V_47 * V_47 )
{
return F_202 ( V_47 ) ;
}
static T_12 void F_203 ( struct V_47 * V_47 )
{
F_204 ( V_47 ) ;
}
static int T_13 F_205 ( void )
{
int V_35 = 0 ;
V_35 = F_206 ( & V_165 ) ;
if ( V_35 )
goto V_101;
V_35 = F_207 () ;
if ( V_35 )
goto V_274;
V_35 = F_208 ( & V_275 ) ;
if ( V_35 )
goto V_276;
F_64 ( & V_100 , L_34 ) ;
return 0 ;
V_276:
F_209 () ;
V_274:
F_210 ( & V_165 ) ;
V_101:
return V_35 ;
}
static void T_14 F_211 ( void )
{
F_212 ( & V_275 ) ;
F_209 () ;
F_210 ( & V_165 ) ;
F_213 () ;
}
