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
V_34 = F_27 ( V_12 , V_29 , V_28 , & V_2 -> V_43 , NULL , V_21 ) ;
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
static int F_30 ( struct V_45 * V_45 )
{
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
int V_34 ;
F_32 ( & V_49 ) ;
if ( V_47 -> V_50 >= 0 ) {
F_2 ( & V_47 -> V_51 ) ;
V_34 = V_47 -> V_50 ;
} else
V_34 = - V_52 ;
F_33 ( & V_49 ) ;
return V_34 ;
}
static void F_34 ( struct V_45 * V_45 )
{
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
if ( F_35 ( & V_47 -> V_51 , & V_49 ) ) {
V_47 -> V_50 = - 1 ;
F_33 ( & V_49 ) ;
}
}
static void
F_36 ( struct V_53 * V_54 )
{
struct V_45 * V_45 = V_54 -> V_55 -> V_45 ;
if ( ! F_4 ( & V_54 -> V_3 ) )
return;
F_34 ( V_45 ) ;
F_37 ( ! F_38 ( & V_54 -> V_56 ) ) ;
if ( V_54 -> V_2 != NULL )
F_3 ( V_54 -> V_2 ) ;
F_39 ( & V_54 -> V_57 ) ;
F_40 ( V_54 ) ;
}
static struct V_53 *
F_41 ( struct V_58 * V_59 , T_3 V_60 )
{
struct V_53 * V_61 ;
F_42 (pos, &pipe->in_downcall, list) {
if ( ! F_43 ( V_61 -> V_60 , V_60 ) )
continue;
F_2 ( & V_61 -> V_3 ) ;
F_28 ( L_3 , V_44 , V_61 ) ;
return V_61 ;
}
F_28 ( L_4 , V_44 ) ;
return NULL ;
}
static inline struct V_53 *
F_44 ( struct V_53 * V_54 )
{
struct V_58 * V_59 = V_54 -> V_59 ;
struct V_53 * V_62 ;
F_32 ( & V_59 -> V_63 ) ;
V_62 = F_41 ( V_59 , V_54 -> V_60 ) ;
if ( V_62 == NULL ) {
F_2 ( & V_54 -> V_3 ) ;
F_45 ( & V_54 -> V_56 , & V_59 -> V_64 ) ;
} else
V_54 = V_62 ;
F_33 ( & V_59 -> V_63 ) ;
return V_54 ;
}
static void
F_46 ( struct V_53 * V_54 )
{
F_47 ( & V_54 -> V_56 ) ;
F_48 ( & V_54 -> V_57 , V_54 -> V_65 . V_66 ) ;
F_49 ( & V_54 -> V_67 ) ;
F_50 ( & V_54 -> V_3 ) ;
}
static void
F_51 ( struct V_53 * V_54 )
{
struct V_58 * V_59 = V_54 -> V_59 ;
if ( F_38 ( & V_54 -> V_56 ) )
return;
F_32 ( & V_59 -> V_63 ) ;
if ( ! F_38 ( & V_54 -> V_56 ) )
F_46 ( V_54 ) ;
F_33 ( & V_59 -> V_63 ) ;
}
static void
F_52 ( struct V_6 * V_6 , struct V_53 * V_54 )
{
switch ( V_54 -> V_65 . V_66 ) {
case 0 :
if ( V_54 -> V_2 == NULL )
break;
F_12 ( V_68 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_54 -> V_2 ) ;
break;
case - V_40 :
F_10 ( V_68 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_69 = V_32 ;
V_6 -> V_70 = NULL ;
F_48 ( & V_54 -> V_57 , V_54 -> V_65 . V_66 ) ;
}
static void
F_53 ( struct V_71 * V_72 )
{
struct V_6 * V_6 = F_7 ( V_72 -> V_73 -> V_74 ,
struct V_6 , V_7 ) ;
struct V_53 * V_54 = V_6 -> V_70 ;
struct V_58 * V_59 = V_54 -> V_59 ;
F_32 ( & V_59 -> V_63 ) ;
F_52 ( V_6 , V_54 ) ;
F_33 ( & V_59 -> V_63 ) ;
V_72 -> V_75 = V_54 -> V_65 . V_66 ;
F_36 ( V_54 ) ;
}
static void F_54 ( struct V_53 * V_54 )
{
T_4 V_60 = F_55 ( & V_76 , V_54 -> V_60 ) ;
memcpy ( V_54 -> V_77 , & V_60 , sizeof( V_60 ) ) ;
V_54 -> V_65 . V_20 = V_54 -> V_77 ;
V_54 -> V_65 . V_15 = sizeof( V_60 ) ;
F_37 ( sizeof( V_60 ) > V_78 ) ;
}
static void F_56 ( struct V_53 * V_54 ,
const char * V_79 ,
const char * V_80 )
{
struct V_27 * V_81 = V_54 -> V_55 -> V_81 ;
char * V_12 = V_54 -> V_77 ;
int V_15 = 0 ;
V_54 -> V_65 . V_15 = sprintf ( V_54 -> V_77 , L_5 ,
V_81 -> V_82 ,
F_55 ( & V_76 , V_54 -> V_60 ) ) ;
V_12 += V_54 -> V_65 . V_15 ;
if ( V_80 ) {
V_15 = sprintf ( V_12 , L_6 , V_80 ) ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 += V_15 ;
}
if ( V_79 != NULL ) {
V_15 = sprintf ( V_12 , L_7 , V_79 ) ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 += V_15 ;
}
if ( V_81 -> V_83 ) {
V_15 = sprintf ( V_12 , L_8 , V_81 -> V_83 ) ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 += V_15 ;
}
V_15 = sprintf ( V_12 , L_9 ) ;
V_54 -> V_65 . V_15 += V_15 ;
V_54 -> V_65 . V_20 = V_54 -> V_77 ;
F_37 ( V_54 -> V_65 . V_15 > V_78 ) ;
}
static struct V_53 *
F_57 ( struct V_84 * V_84 ,
T_3 V_60 , const char * V_79 )
{
struct V_53 * V_54 ;
int V_85 ;
V_54 = F_23 ( sizeof( * V_54 ) , V_21 ) ;
if ( V_54 == NULL )
return F_15 ( - V_22 ) ;
V_85 = F_30 ( V_84 -> V_45 ) ;
if ( V_85 < 0 ) {
F_40 ( V_54 ) ;
return F_15 ( V_85 ) ;
}
V_54 -> V_59 = V_84 -> V_86 [ V_85 ] -> V_59 ;
F_58 ( & V_54 -> V_56 ) ;
F_59 ( & V_54 -> V_57 , L_10 ) ;
F_60 ( & V_54 -> V_67 ) ;
F_25 ( & V_54 -> V_3 , 1 ) ;
V_54 -> V_60 = V_60 ;
V_54 -> V_55 = V_84 ;
switch ( V_85 ) {
case 0 :
F_54 ( V_54 ) ;
default:
F_56 ( V_54 , V_79 , V_84 -> V_80 ) ;
} ;
return V_54 ;
}
static struct V_53 *
F_61 ( struct V_84 * V_84 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_53 * V_87 , * V_54 ;
T_3 V_60 = V_5 -> V_88 ;
V_87 = F_57 ( V_84 , V_60 , V_6 -> V_89 ) ;
if ( F_17 ( V_87 ) )
return V_87 ;
V_54 = F_44 ( V_87 ) ;
if ( V_54 == V_87 ) {
int V_14 = F_62 ( V_87 -> V_59 , & V_87 -> V_65 ) ;
if ( V_14 ) {
F_51 ( V_87 ) ;
V_54 = F_15 ( V_14 ) ;
}
} else
F_36 ( V_87 ) ;
return V_54 ;
}
static void F_63 ( void )
{
static unsigned long V_90 ;
unsigned long V_31 = V_32 ;
if ( F_64 ( V_31 , V_90 ) ) {
F_65 ( V_91 L_11
L_12 ) ;
V_90 = V_31 + 15 * V_38 ;
}
}
static inline int
F_66 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_84 * V_84 = F_7 ( V_5 -> V_92 ,
struct V_84 , V_93 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_53 * V_54 ;
struct V_58 * V_59 ;
int V_35 = 0 ;
F_28 ( L_13 ,
V_72 -> V_94 , V_44 , F_55 ( & V_76 , V_5 -> V_88 ) ) ;
V_54 = F_61 ( V_84 , V_5 ) ;
if ( F_29 ( V_54 ) == - V_52 ) {
F_63 () ;
V_72 -> V_95 = 15 * V_38 ;
F_67 ( & V_96 , V_72 , NULL ) ;
return - V_52 ;
}
if ( F_17 ( V_54 ) ) {
V_35 = F_29 ( V_54 ) ;
goto V_97;
}
V_59 = V_54 -> V_59 ;
F_32 ( & V_59 -> V_63 ) ;
if ( V_6 -> V_70 != NULL )
F_67 ( & V_6 -> V_70 -> V_57 , V_72 , NULL ) ;
else if ( V_54 -> V_2 == NULL && V_54 -> V_65 . V_66 >= 0 ) {
V_72 -> V_95 = 0 ;
V_6 -> V_70 = V_54 ;
F_2 ( & V_54 -> V_3 ) ;
F_67 ( & V_54 -> V_57 , V_72 , F_53 ) ;
} else {
F_52 ( V_6 , V_54 ) ;
V_35 = V_54 -> V_65 . V_66 ;
}
F_33 ( & V_59 -> V_63 ) ;
F_36 ( V_54 ) ;
V_97:
F_28 ( L_14 ,
V_72 -> V_94 , V_44 ,
F_55 ( & V_76 , V_5 -> V_88 ) , V_35 ) ;
return V_35 ;
}
static inline int
F_68 ( struct V_84 * V_84 , struct V_6 * V_6 )
{
struct V_45 * V_45 = V_84 -> V_45 ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
struct V_58 * V_59 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_53 * V_54 ;
unsigned long V_30 ;
F_69 ( V_98 ) ;
int V_35 ;
F_28 ( L_15 ,
V_44 , F_55 ( & V_76 , V_5 -> V_88 ) ) ;
V_99:
V_35 = 0 ;
V_30 = 15 * V_38 ;
if ( ! V_47 -> V_100 )
V_30 = V_38 >> 2 ;
V_54 = F_61 ( V_84 , V_5 ) ;
if ( F_29 ( V_54 ) == - V_52 ) {
V_35 = F_70 ( V_101 ,
V_47 -> V_50 >= 0 , V_30 ) ;
if ( V_47 -> V_50 < 0 ) {
if ( V_35 == 0 )
V_47 -> V_100 = 0 ;
F_63 () ;
V_35 = - V_41 ;
}
if ( V_35 < 0 )
goto V_97;
goto V_99;
}
if ( F_17 ( V_54 ) ) {
V_35 = F_29 ( V_54 ) ;
goto V_97;
}
V_59 = V_54 -> V_59 ;
for (; ; ) {
F_71 ( & V_54 -> V_67 , & V_98 , V_102 ) ;
F_32 ( & V_59 -> V_63 ) ;
if ( V_54 -> V_2 != NULL || V_54 -> V_65 . V_66 < 0 ) {
break;
}
F_33 ( & V_59 -> V_63 ) ;
if ( F_72 ( V_103 ) ) {
V_35 = - V_104 ;
goto V_105;
}
F_73 () ;
}
if ( V_54 -> V_2 )
F_6 ( V_5 , V_54 -> V_2 ) ;
else
V_35 = V_54 -> V_65 . V_66 ;
F_33 ( & V_59 -> V_63 ) ;
V_105:
F_74 ( & V_54 -> V_67 , & V_98 ) ;
F_36 ( V_54 ) ;
V_97:
F_28 ( L_16 ,
V_44 , F_55 ( & V_76 , V_5 -> V_88 ) , V_35 ) ;
return V_35 ;
}
static T_5
F_75 ( struct V_106 * V_107 , const char T_6 * V_108 , T_1 V_109 )
{
const void * V_12 , * V_13 ;
void * V_110 ;
struct V_53 * V_54 ;
struct V_58 * V_59 = F_76 ( F_77 ( V_107 ) ) -> V_59 ;
struct V_1 * V_2 ;
T_4 V_111 ;
T_3 V_60 ;
T_5 V_35 = - V_112 ;
if ( V_109 > V_113 )
goto V_97;
V_35 = - V_22 ;
V_110 = F_78 ( V_109 , V_21 ) ;
if ( ! V_110 )
goto V_97;
V_35 = - V_17 ;
if ( F_79 ( V_110 , V_108 , V_109 ) )
goto V_35;
V_13 = ( const void * ) ( ( char * ) V_110 + V_109 ) ;
V_12 = F_13 ( V_110 , V_13 , & V_111 , sizeof( V_111 ) ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
goto V_35;
}
V_60 = F_80 ( & V_76 , V_111 ) ;
if ( ! F_81 ( V_60 ) ) {
V_35 = - V_114 ;
goto V_35;
}
V_35 = - V_22 ;
V_2 = F_22 () ;
if ( V_2 == NULL )
goto V_35;
V_35 = - V_115 ;
F_32 ( & V_59 -> V_63 ) ;
V_54 = F_41 ( V_59 , V_60 ) ;
if ( V_54 == NULL ) {
F_33 ( & V_59 -> V_63 ) ;
goto V_116;
}
F_47 ( & V_54 -> V_56 ) ;
F_33 ( & V_59 -> V_63 ) ;
V_12 = F_26 ( V_12 , V_13 , V_2 , V_54 -> V_55 -> V_81 ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
switch ( V_35 ) {
case - V_41 :
case - V_40 :
V_54 -> V_65 . V_66 = V_35 ;
V_35 = V_109 ;
break;
case - V_17 :
case - V_22 :
case - V_114 :
case - V_117 :
V_54 -> V_65 . V_66 = - V_52 ;
break;
default:
F_65 ( V_118 L_17
L_18 , V_44 , V_35 ) ;
F_82 () ;
}
goto V_119;
}
V_54 -> V_2 = F_1 ( V_2 ) ;
V_35 = V_109 ;
V_119:
F_32 ( & V_59 -> V_63 ) ;
F_46 ( V_54 ) ;
F_33 ( & V_59 -> V_63 ) ;
F_36 ( V_54 ) ;
V_116:
F_3 ( V_2 ) ;
V_35:
F_40 ( V_110 ) ;
V_97:
F_28 ( L_19 , V_44 , V_35 ) ;
return V_35 ;
}
static int F_83 ( struct V_120 * V_120 , int V_121 )
{
struct V_45 * V_45 = V_120 -> V_122 -> V_123 ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
int V_34 = 0 ;
F_32 ( & V_49 ) ;
if ( V_47 -> V_50 < 0 ) {
V_47 -> V_50 = V_121 ;
F_84 ( & V_96 ) ;
F_85 ( & V_101 ) ;
} else if ( V_47 -> V_50 != V_121 ) {
V_34 = - V_124 ;
goto V_97;
}
F_2 ( & V_47 -> V_51 ) ;
V_97:
F_33 ( & V_49 ) ;
return V_34 ;
}
static int F_86 ( struct V_120 * V_120 )
{
return F_83 ( V_120 , 0 ) ;
}
static int F_87 ( struct V_120 * V_120 )
{
return F_83 ( V_120 , 1 ) ;
}
static void
F_88 ( struct V_120 * V_120 )
{
struct V_45 * V_45 = V_120 -> V_122 -> V_123 ;
struct V_58 * V_59 = F_76 ( V_120 ) -> V_59 ;
struct V_53 * V_54 ;
V_125:
F_32 ( & V_59 -> V_63 ) ;
F_42 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_38 ( & V_54 -> V_65 . V_56 ) )
continue;
V_54 -> V_65 . V_66 = - V_126 ;
F_2 ( & V_54 -> V_3 ) ;
F_46 ( V_54 ) ;
F_33 ( & V_59 -> V_63 ) ;
F_36 ( V_54 ) ;
goto V_125;
}
F_33 ( & V_59 -> V_63 ) ;
F_34 ( V_45 ) ;
}
static void
F_89 ( struct V_127 * V_65 )
{
struct V_53 * V_54 = F_7 ( V_65 , struct V_53 , V_65 ) ;
if ( V_65 -> V_66 < 0 ) {
F_28 ( L_20 ,
V_44 , V_54 ) ;
F_2 ( & V_54 -> V_3 ) ;
F_51 ( V_54 ) ;
if ( V_65 -> V_66 == - V_128 )
F_63 () ;
F_36 ( V_54 ) ;
}
}
static void F_90 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_86 * V_86 = V_132 -> V_133 ;
struct V_58 * V_59 = V_86 -> V_59 ;
if ( V_59 -> V_129 != NULL ) {
F_91 ( V_59 -> V_129 ) ;
V_59 -> V_129 = NULL ;
}
}
static int F_92 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_86 * V_12 = V_132 -> V_133 ;
struct V_129 * V_129 ;
V_129 = F_93 ( V_130 , V_12 -> V_134 , V_12 -> V_135 , V_12 -> V_59 ) ;
if ( F_17 ( V_129 ) )
return F_29 ( V_129 ) ;
V_12 -> V_59 -> V_129 = V_129 ;
return 0 ;
}
static struct V_86 * F_94 ( struct V_136 * V_135 ,
const char * V_134 ,
const struct V_137 * V_138 )
{
struct V_86 * V_12 ;
int V_35 = - V_22 ;
V_12 = F_78 ( sizeof( * V_12 ) , V_139 ) ;
if ( V_12 == NULL )
goto V_35;
V_12 -> V_59 = F_95 ( V_138 , V_140 ) ;
if ( F_17 ( V_12 -> V_59 ) ) {
V_35 = F_29 ( V_12 -> V_59 ) ;
goto V_141;
}
V_12 -> V_134 = V_134 ;
V_12 -> V_135 = V_135 ;
F_96 ( & V_12 -> V_142 ) ;
F_97 ( & V_12 -> V_132 ,
& V_143 ,
V_12 ) ;
return V_12 ;
V_141:
F_40 ( V_12 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static int F_98 ( struct V_131 * V_132 , void * V_20 )
{
struct V_86 * V_86 ;
struct V_144 * args = V_20 ;
if ( V_132 -> V_145 != & V_143 )
return 0 ;
V_86 = F_7 ( V_132 , struct V_86 , V_132 ) ;
if ( strcmp ( V_86 -> V_134 , args -> V_134 ) != 0 )
return 0 ;
if ( ! F_99 ( & V_86 -> V_142 ) )
return 0 ;
return 1 ;
}
static struct V_131 * F_100 ( void * V_20 )
{
struct V_86 * V_86 ;
struct V_144 * args = V_20 ;
V_86 = F_94 ( args -> V_135 , args -> V_134 , args -> V_138 ) ;
if ( ! F_17 ( V_86 ) )
return & V_86 -> V_132 ;
return NULL ;
}
static struct V_86 * F_101 ( struct V_136 * V_135 ,
const char * V_134 ,
const struct V_137 * V_138 )
{
struct V_45 * V_45 = F_102 ( V_135 ) ;
struct V_131 * V_132 ;
struct V_144 args = {
. V_135 = V_135 ,
. V_134 = V_134 ,
. V_138 = V_138 ,
} ;
V_132 = F_103 ( V_45 ,
& V_135 -> V_146 ,
F_98 ,
F_100 ,
& args ) ;
if ( V_132 != NULL )
return F_7 ( V_132 , struct V_86 , V_132 ) ;
return F_15 ( - V_22 ) ;
}
static void F_104 ( struct V_86 * V_12 )
{
struct V_136 * V_135 = V_12 -> V_135 ;
struct V_45 * V_45 = F_102 ( V_135 ) ;
F_105 ( V_45 ,
& V_135 -> V_146 ,
& V_12 -> V_132 ) ;
F_106 ( V_12 -> V_59 ) ;
F_40 ( V_12 ) ;
}
static void F_107 ( struct V_142 * V_142 )
{
struct V_86 * V_12 = F_7 ( V_142 , struct V_86 , V_142 ) ;
F_104 ( V_12 ) ;
}
static void F_108 ( struct V_86 * V_12 )
{
if ( V_12 != NULL )
F_109 ( & V_12 -> V_142 , F_107 ) ;
}
static struct V_84 *
F_110 ( struct V_147 * args , struct V_136 * V_135 )
{
T_7 V_148 = args -> V_149 ;
struct V_84 * V_84 ;
struct V_86 * V_86 ;
struct V_93 * V_55 ;
int V_35 = - V_22 ;
F_28 ( L_21 , V_135 ) ;
if ( ! F_111 ( V_150 ) )
return F_15 ( V_35 ) ;
if ( ! ( V_84 = F_78 ( sizeof( * V_84 ) , V_139 ) ) )
goto V_151;
F_112 ( & V_84 -> V_152 ) ;
V_84 -> V_80 = NULL ;
if ( args -> V_80 ) {
V_84 -> V_80 = F_113 ( args -> V_80 , V_139 ) ;
if ( V_84 -> V_80 == NULL )
goto V_153;
}
V_84 -> V_154 = V_135 ;
V_84 -> V_45 = F_114 ( F_102 ( V_135 ) ) ;
V_35 = - V_114 ;
V_84 -> V_81 = F_115 ( V_148 ) ;
if ( ! V_84 -> V_81 ) {
F_28 ( L_22 , V_148 ) ;
goto V_155;
}
V_84 -> V_156 = F_116 ( V_84 -> V_81 , V_148 ) ;
if ( V_84 -> V_156 == 0 )
goto V_157;
V_55 = & V_84 -> V_93 ;
V_55 -> V_158 = V_159 >> 2 ;
V_55 -> V_160 = V_161 >> 2 ;
V_55 -> V_162 = & V_163 ;
V_55 -> V_164 = V_148 ;
F_25 ( & V_55 -> V_165 , 1 ) ;
F_96 ( & V_84 -> V_142 ) ;
V_35 = F_117 ( V_55 ) ;
if ( V_35 )
goto V_157;
V_86 = F_101 ( V_135 , L_23 , & V_166 ) ;
if ( F_17 ( V_86 ) ) {
V_35 = F_29 ( V_86 ) ;
goto V_167;
}
V_84 -> V_86 [ 1 ] = V_86 ;
V_86 = F_101 ( V_135 , V_84 -> V_81 -> V_82 ,
& V_168 ) ;
if ( F_17 ( V_86 ) ) {
V_35 = F_29 ( V_86 ) ;
goto V_169;
}
V_84 -> V_86 [ 0 ] = V_86 ;
return V_84 ;
V_169:
F_108 ( V_84 -> V_86 [ 1 ] ) ;
V_167:
F_118 ( V_55 ) ;
V_157:
F_119 ( V_84 -> V_81 ) ;
V_155:
F_120 ( V_84 -> V_45 ) ;
V_153:
F_40 ( V_84 -> V_80 ) ;
F_40 ( V_84 ) ;
V_151:
F_121 ( V_150 ) ;
return F_15 ( V_35 ) ;
}
static void
F_122 ( struct V_84 * V_84 )
{
F_108 ( V_84 -> V_86 [ 0 ] ) ;
F_108 ( V_84 -> V_86 [ 1 ] ) ;
F_119 ( V_84 -> V_81 ) ;
F_120 ( V_84 -> V_45 ) ;
F_40 ( V_84 -> V_80 ) ;
F_40 ( V_84 ) ;
F_121 ( V_150 ) ;
}
static void
F_123 ( struct V_142 * V_142 )
{
struct V_84 * V_84 = F_7 ( V_142 , struct V_84 , V_142 ) ;
F_122 ( V_84 ) ;
}
static void
F_124 ( struct V_93 * V_55 )
{
struct V_84 * V_84 = F_7 ( V_55 ,
struct V_84 , V_93 ) ;
F_28 ( L_24 ,
V_55 , V_55 -> V_164 ) ;
if ( F_125 ( & V_84 -> V_152 ) ) {
F_32 ( & V_170 ) ;
F_126 ( & V_84 -> V_152 ) ;
F_33 ( & V_170 ) ;
}
F_108 ( V_84 -> V_86 [ 0 ] ) ;
V_84 -> V_86 [ 0 ] = NULL ;
F_108 ( V_84 -> V_86 [ 1 ] ) ;
V_84 -> V_86 [ 1 ] = NULL ;
F_118 ( V_55 ) ;
F_109 ( & V_84 -> V_142 , F_123 ) ;
}
static struct V_84 *
F_127 ( struct V_147 * args ,
struct V_136 * V_135 ,
struct V_84 * V_171 )
{
struct V_84 * V_84 ;
unsigned long V_172 = ( unsigned long ) V_135 ;
F_32 ( & V_170 ) ;
F_128 (gss_auth_hash_table,
gss_auth,
hash,
hashval) {
if ( V_84 -> V_154 != V_135 )
continue;
if ( V_84 -> V_93 . V_164 != args -> V_149 )
continue;
if ( V_84 -> V_80 != args -> V_80 ) {
if ( V_84 -> V_80 == NULL )
continue;
if ( args -> V_80 == NULL )
continue;
if ( strcmp ( V_84 -> V_80 , args -> V_80 ) )
continue;
}
if ( ! F_129 ( & V_84 -> V_93 . V_165 ) )
continue;
goto V_97;
}
if ( V_171 )
F_130 ( V_173 , & V_171 -> V_152 , V_172 ) ;
V_84 = V_171 ;
V_97:
F_33 ( & V_170 ) ;
return V_84 ;
}
static struct V_84 *
F_131 ( struct V_147 * args , struct V_136 * V_135 )
{
struct V_84 * V_84 ;
struct V_84 * V_171 ;
V_84 = F_127 ( args , V_135 , NULL ) ;
if ( V_84 != NULL )
goto V_97;
V_171 = F_110 ( args , V_135 ) ;
if ( F_17 ( V_171 ) )
return V_171 ;
V_84 = F_127 ( args , V_135 , V_171 ) ;
if ( V_84 != V_171 )
F_124 ( & V_171 -> V_93 ) ;
V_97:
return V_84 ;
}
static struct V_93 *
F_132 ( struct V_147 * args , struct V_136 * V_135 )
{
struct V_84 * V_84 ;
struct V_174 * V_175 = F_133 ( V_135 -> V_176 ) ;
while ( V_135 != V_135 -> V_177 ) {
struct V_136 * V_178 = V_135 -> V_177 ;
if ( F_133 ( V_178 -> V_176 ) != V_175 )
break;
V_135 = V_178 ;
}
V_84 = F_131 ( args , V_135 ) ;
if ( F_17 ( V_84 ) )
return F_134 ( V_84 ) ;
return & V_84 -> V_93 ;
}
static int
F_135 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_84 * V_84 = F_7 ( V_5 -> V_92 , struct V_84 , V_93 ) ;
struct V_71 * V_72 ;
if ( V_6 -> V_10 == NULL ||
F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_6 -> V_10 -> V_23 = V_179 ;
V_5 -> V_180 = & V_181 ;
F_136 ( V_5 ) ;
V_72 = F_137 ( V_84 -> V_154 , V_5 , V_182 | V_183 ) ;
if ( ! F_17 ( V_72 ) )
F_138 ( V_72 ) ;
F_139 ( V_5 ) ;
return 1 ;
}
static void
F_140 ( struct V_1 * V_2 )
{
F_28 ( L_25 , V_44 ) ;
F_141 ( & V_2 -> V_43 ) ;
F_40 ( V_2 -> V_42 . V_20 ) ;
F_40 ( V_2 ) ;
}
static void
F_142 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_7 ( V_185 , struct V_1 , V_186 ) ;
F_140 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_143 ( & V_2 -> V_186 , F_142 ) ;
}
static void
F_144 ( struct V_6 * V_6 )
{
F_28 ( L_26 , V_44 , V_6 ) ;
F_40 ( V_6 ) ;
}
static void
F_145 ( struct V_184 * V_185 )
{
struct V_6 * V_6 = F_7 ( V_185 , struct V_6 , V_7 . V_187 ) ;
F_144 ( V_6 ) ;
}
static void
F_146 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_84 * V_84 = F_7 ( V_5 -> V_92 , struct V_84 , V_93 ) ;
struct V_1 * V_2 = V_6 -> V_10 ;
F_147 ( V_6 -> V_10 , NULL ) ;
F_143 ( & V_5 -> V_187 , F_145 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_109 ( & V_84 -> V_142 , F_123 ) ;
}
static void
F_148 ( struct V_4 * V_5 )
{
if ( F_135 ( V_5 ) )
return;
F_146 ( V_5 ) ;
}
static struct V_4 *
F_149 ( struct V_93 * V_55 , struct V_188 * V_189 , int V_190 )
{
return F_150 ( V_55 , V_189 , V_190 ) ;
}
static struct V_4 *
F_151 ( struct V_93 * V_55 , struct V_188 * V_189 , int V_190 )
{
struct V_84 * V_84 = F_7 ( V_55 , struct V_84 , V_93 ) ;
struct V_6 * V_5 = NULL ;
int V_35 = - V_22 ;
F_28 ( L_27 ,
V_44 , F_55 ( & V_76 , V_189 -> V_60 ) ,
V_55 -> V_164 ) ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_191;
F_152 ( & V_5 -> V_7 , V_189 , V_55 , & V_192 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_193 = V_84 -> V_156 ;
V_5 -> V_89 = NULL ;
if ( V_189 -> V_194 )
V_5 -> V_89 = V_189 -> V_195 ;
F_153 ( & V_84 -> V_142 ) ;
return & V_5 -> V_7 ;
V_191:
F_28 ( L_28 , V_44 , V_35 ) ;
return F_15 ( V_35 ) ;
}
static int
F_154 ( struct V_93 * V_55 , struct V_4 * V_5 )
{
struct V_84 * V_84 = F_7 ( V_55 , struct V_84 , V_93 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_35 ;
do {
V_35 = F_68 ( V_84 , V_6 ) ;
} while ( V_35 == - V_52 );
return V_35 ;
}
static int
F_155 ( struct V_4 * V_196 )
{
struct V_6 * V_6 = F_7 ( V_196 , struct V_6 , V_7 ) ;
unsigned long V_31 = V_32 ;
unsigned long V_197 ;
if ( V_6 -> V_10 == NULL )
return - V_41 ;
V_197 = V_6 -> V_10 -> V_37 - ( V_198 * V_38 ) ;
if ( F_64 ( V_31 , V_197 ) )
return - V_41 ;
return 0 ;
}
static int
F_156 ( struct V_188 * V_189 , struct V_4 * V_196 , int V_190 )
{
struct V_6 * V_6 = F_7 ( V_196 , struct V_6 , V_7 ) ;
int V_34 ;
if ( F_8 ( V_8 , & V_196 -> V_9 ) )
goto V_97;
if ( F_64 ( V_32 , V_6 -> V_10 -> V_37 ) )
return 0 ;
if ( ! F_8 ( V_11 , & V_196 -> V_9 ) )
return 0 ;
V_97:
if ( V_189 -> V_195 != NULL ) {
if ( V_6 -> V_89 == NULL )
return 0 ;
V_34 = strcmp ( V_189 -> V_195 , V_6 -> V_89 ) == 0 ;
goto V_199;
}
if ( V_6 -> V_89 != NULL )
return 0 ;
V_34 = F_43 ( V_196 -> V_88 , V_189 -> V_60 ) ;
V_199:
if ( V_34 == 0 )
return V_34 ;
if ( F_8 ( V_200 , & V_189 -> V_201 ) &&
( F_155 ( V_196 ) != 0 ) ) {
F_157 ( V_200 , & V_189 -> V_201 ) ;
F_10 ( V_202 , & V_189 -> V_201 ) ;
}
return V_34 ;
}
static T_8 *
F_158 ( struct V_71 * V_72 , T_8 * V_12 )
{
struct V_203 * V_204 = V_72 -> V_73 ;
struct V_4 * V_5 = V_204 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_205 ;
T_2 V_206 = 0 ;
struct V_18 V_207 ;
struct V_208 V_209 ;
struct V_210 V_211 ;
F_28 ( L_29 , V_72 -> V_94 , V_44 ) ;
* V_12 ++ = F_159 ( V_212 ) ;
V_205 = V_12 ++ ;
F_32 ( & V_2 -> V_26 ) ;
V_204 -> V_213 = V_2 -> V_25 ++ ;
F_33 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_159 ( ( T_2 ) V_214 ) ;
* V_12 ++ = F_159 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_159 ( ( T_2 ) V_204 -> V_213 ) ;
* V_12 ++ = F_159 ( ( T_2 ) V_6 -> V_193 ) ;
V_12 = F_160 ( V_12 , & V_2 -> V_42 ) ;
* V_205 = F_159 ( ( V_12 - ( V_205 + 1 ) ) << 2 ) ;
V_209 . V_215 = F_161 ( V_204 -> V_216 ,
V_204 -> V_217 . V_185 [ 0 ] . V_215 ) ;
V_209 . V_218 = ( V_219 * ) V_12 - ( V_219 * ) V_209 . V_215 ;
F_162 ( & V_209 , & V_211 ) ;
* V_12 ++ = F_159 ( V_212 ) ;
V_207 . V_20 = ( V_219 * ) ( V_12 + 1 ) ;
V_206 = F_163 ( V_2 -> V_43 , & V_211 , & V_207 ) ;
if ( V_206 == V_220 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_206 != 0 ) {
F_65 ( L_30 , V_206 ) ;
goto V_221;
}
V_12 = F_164 ( V_12 , NULL , V_207 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_221:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_165 ( struct V_71 * V_72 )
{
struct V_4 * V_222 = V_72 -> V_73 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_222 ,
struct V_6 ,
V_7 ) ;
struct V_93 * V_55 = V_222 -> V_92 ;
struct V_188 V_189 = {
. V_60 = V_222 -> V_88 ,
. V_195 = V_6 -> V_89 ,
. V_194 = ( V_6 -> V_89 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_171 ;
V_171 = F_149 ( V_55 , & V_189 , V_223 ) ;
if ( F_17 ( V_171 ) )
return F_29 ( V_171 ) ;
V_72 -> V_73 -> V_74 = V_171 ;
F_139 ( V_222 ) ;
return 0 ;
}
static int F_166 ( struct V_4 * V_5 )
{
if ( F_8 ( V_68 , & V_5 -> V_9 ) ) {
unsigned long V_31 = V_32 ;
unsigned long V_224 , V_197 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_224 = V_6 -> V_69 ;
V_197 = V_224 + V_225 * V_38 ;
if ( F_167 ( V_31 , V_224 , V_197 ) )
return 1 ;
}
return 0 ;
}
static int
F_168 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
int V_34 = 0 ;
if ( F_166 ( V_5 ) )
return - V_40 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_34 = F_165 ( V_72 ) ;
if ( V_34 < 0 )
goto V_97;
V_5 = V_72 -> V_73 -> V_74 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_34 = F_66 ( V_72 ) ;
V_97:
return V_34 ;
}
static int
F_169 ( struct V_71 * V_72 )
{
return - V_41 ;
}
static T_8 *
F_170 ( struct V_71 * V_72 , T_8 * V_12 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 V_226 ;
struct V_208 V_209 ;
struct V_210 V_211 ;
struct V_18 V_207 ;
T_2 V_227 , V_15 ;
T_2 V_206 ;
T_8 * V_34 = F_15 ( - V_228 ) ;
F_28 ( L_29 , V_72 -> V_94 , V_44 ) ;
V_227 = F_171 ( * V_12 ++ ) ;
if ( ( V_15 = F_171 ( * V_12 ++ ) ) > V_229 )
goto V_230;
if ( V_227 != V_212 )
goto V_230;
V_226 = F_159 ( V_72 -> V_73 -> V_213 ) ;
V_209 . V_215 = & V_226 ;
V_209 . V_218 = sizeof( V_226 ) ;
F_162 ( & V_209 , & V_211 ) ;
V_207 . V_20 = ( V_219 * ) V_12 ;
V_207 . V_15 = V_15 ;
V_34 = F_15 ( - V_41 ) ;
V_206 = F_172 ( V_2 -> V_43 , & V_211 , & V_207 ) ;
if ( V_206 == V_220 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_206 ) {
F_28 ( L_31 ,
V_72 -> V_94 , V_44 , V_206 ) ;
goto V_230;
}
V_5 -> V_92 -> V_231 = F_173 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_28 ( L_32 ,
V_72 -> V_94 , V_44 ) ;
return V_12 + F_173 ( V_15 ) ;
V_230:
F_3 ( V_2 ) ;
F_28 ( L_33 , V_72 -> V_94 , V_44 ,
F_29 ( V_34 ) ) ;
return V_34 ;
}
static void F_174 ( T_9 V_232 , struct V_203 * V_233 ,
T_8 * V_12 , void * V_234 )
{
struct V_235 V_236 ;
F_175 ( & V_236 , & V_233 -> V_217 , V_12 ) ;
V_232 ( V_233 , & V_236 , V_234 ) ;
}
static inline int
F_176 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_232 , struct V_203 * V_233 ,
T_8 * V_12 , void * V_234 )
{
struct V_210 * V_237 = & V_233 -> V_217 ;
struct V_210 V_238 ;
T_8 * V_239 = NULL ;
struct V_18 V_207 ;
T_2 V_240 ;
T_8 * V_16 ;
struct V_208 * V_209 ;
T_2 V_206 = 0 ;
int V_241 = - V_228 ;
V_239 = V_12 ++ ;
V_240 = ( V_219 * ) V_12 - ( V_219 * ) V_237 -> V_185 [ 0 ] . V_215 ;
* V_12 ++ = F_159 ( V_233 -> V_213 ) ;
F_174 ( V_232 , V_233 , V_12 , V_234 ) ;
if ( F_177 ( V_237 , & V_238 ,
V_240 , V_237 -> V_15 - V_240 ) )
return V_241 ;
* V_239 = F_159 ( V_238 . V_15 ) ;
if ( V_237 -> V_242 || V_237 -> V_243 [ 0 ] . V_218 )
V_209 = V_237 -> V_243 ;
else
V_209 = V_237 -> V_185 ;
V_12 = V_209 -> V_215 + V_209 -> V_218 ;
V_207 . V_20 = ( V_219 * ) ( V_12 + 1 ) ;
V_206 = F_163 ( V_2 -> V_43 , & V_238 , & V_207 ) ;
V_241 = - V_228 ;
if ( V_206 == V_220 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_206 )
return V_241 ;
V_16 = F_164 ( V_12 , NULL , V_207 . V_15 ) ;
V_240 = ( V_219 * ) V_16 - ( V_219 * ) V_12 ;
V_209 -> V_218 += V_240 ;
V_237 -> V_15 += V_240 ;
return 0 ;
}
static void
F_178 ( struct V_203 * V_233 )
{
int V_244 ;
for ( V_244 = 0 ; V_244 < V_233 -> V_245 ; V_244 ++ )
F_179 ( V_233 -> V_246 [ V_244 ] ) ;
F_40 ( V_233 -> V_246 ) ;
}
static int
F_180 ( struct V_203 * V_233 )
{
struct V_210 * V_237 = & V_233 -> V_217 ;
int V_247 , V_248 , V_244 ;
if ( V_237 -> V_242 == 0 ) {
V_233 -> V_245 = 0 ;
return 0 ;
}
V_247 = V_237 -> V_249 >> V_250 ;
V_248 = ( V_237 -> V_249 + V_237 -> V_242 - 1 ) >> V_250 ;
V_233 -> V_245 = V_248 - V_247 + 1 + 1 ;
V_233 -> V_246
= F_78 ( V_233 -> V_245 * sizeof( struct V_251 * ) ,
V_21 ) ;
if ( ! V_233 -> V_246 )
goto V_97;
for ( V_244 = 0 ; V_244 < V_233 -> V_245 ; V_244 ++ ) {
V_233 -> V_246 [ V_244 ] = F_181 ( V_21 ) ;
if ( V_233 -> V_246 [ V_244 ] == NULL )
goto V_252;
}
V_233 -> V_253 = F_178 ;
return 0 ;
V_252:
V_233 -> V_245 = V_244 ;
F_178 ( V_233 ) ;
V_97:
return - V_52 ;
}
static inline int
F_182 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_232 , struct V_203 * V_233 ,
T_8 * V_12 , void * V_234 )
{
struct V_210 * V_237 = & V_233 -> V_217 ;
T_2 V_240 ;
T_2 V_206 ;
int V_241 ;
T_8 * V_254 ;
struct V_251 * * V_255 ;
int V_247 ;
int V_256 ;
struct V_208 * V_209 ;
char * V_257 ;
V_254 = V_12 ++ ;
V_240 = ( V_219 * ) V_12 - ( V_219 * ) V_237 -> V_185 [ 0 ] . V_215 ;
* V_12 ++ = F_159 ( V_233 -> V_213 ) ;
F_174 ( V_232 , V_233 , V_12 , V_234 ) ;
V_241 = F_180 ( V_233 ) ;
if ( V_241 )
return V_241 ;
V_247 = V_237 -> V_249 >> V_250 ;
V_255 = V_237 -> V_258 + V_247 ;
V_237 -> V_258 = V_233 -> V_246 ;
V_237 -> V_249 -= V_247 << V_250 ;
if ( V_237 -> V_242 || V_237 -> V_243 [ 0 ] . V_218 ) {
V_257 = F_183 ( V_233 -> V_246 [ V_233 -> V_245 - 1 ] ) ;
memcpy ( V_257 , V_237 -> V_243 [ 0 ] . V_215 , V_237 -> V_243 [ 0 ] . V_218 ) ;
V_237 -> V_243 [ 0 ] . V_215 = V_257 ;
}
V_206 = F_184 ( V_2 -> V_43 , V_240 , V_237 , V_255 ) ;
F_37 ( V_237 -> V_15 > V_237 -> V_259 ) ;
V_241 = - V_228 ;
if ( V_206 == V_220 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_206 )
return V_241 ;
* V_254 = F_159 ( V_237 -> V_15 - V_240 ) ;
if ( V_237 -> V_242 || V_237 -> V_243 [ 0 ] . V_218 )
V_209 = V_237 -> V_243 ;
else
V_209 = V_237 -> V_185 ;
V_12 = V_209 -> V_215 + V_209 -> V_218 ;
V_256 = 3 - ( ( V_237 -> V_15 - V_240 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_256 ) ;
V_209 -> V_218 += V_256 ;
V_237 -> V_15 += V_256 ;
return 0 ;
}
static int
F_185 ( struct V_71 * V_72 ,
T_9 V_232 , void * V_233 , T_8 * V_12 , void * V_234 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_241 = - V_228 ;
F_28 ( L_29 , V_72 -> V_94 , V_44 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_174 ( V_232 , V_233 , V_12 , V_234 ) ;
V_241 = 0 ;
goto V_97;
}
switch ( V_6 -> V_193 ) {
case V_260 :
F_174 ( V_232 , V_233 , V_12 , V_234 ) ;
V_241 = 0 ;
break;
case V_261 :
V_241 = F_176 ( V_5 , V_2 , V_232 , V_233 , V_12 , V_234 ) ;
break;
case V_262 :
V_241 = F_182 ( V_5 , V_2 , V_232 , V_233 , V_12 , V_234 ) ;
break;
}
V_97:
F_3 ( V_2 ) ;
F_28 ( L_34 , V_72 -> V_94 , V_44 , V_241 ) ;
return V_241 ;
}
static inline int
F_186 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_203 * V_233 , T_8 * * V_12 )
{
struct V_210 * V_263 = & V_233 -> V_264 ;
struct V_210 V_238 ;
struct V_18 V_207 ;
T_2 V_265 , V_266 ;
T_2 V_239 ;
T_2 V_206 ;
int V_241 = - V_228 ;
V_239 = F_171 ( * ( * V_12 ) ++ ) ;
if ( V_239 & 3 )
return V_241 ;
V_265 = ( V_219 * ) ( * V_12 ) - ( V_219 * ) V_263 -> V_185 [ 0 ] . V_215 ;
V_266 = V_239 + V_265 ;
if ( V_266 > V_263 -> V_15 )
return V_241 ;
if ( F_171 ( * ( * V_12 ) ++ ) != V_233 -> V_213 )
return V_241 ;
if ( F_177 ( V_263 , & V_238 , V_265 ,
V_266 - V_265 ) )
return V_241 ;
if ( F_187 ( V_263 , & V_207 , V_266 ) )
return V_241 ;
V_206 = F_172 ( V_2 -> V_43 , & V_238 , & V_207 ) ;
if ( V_206 == V_220 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_206 != V_267 )
return V_241 ;
return 0 ;
}
static inline int
F_188 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_203 * V_233 , T_8 * * V_12 )
{
struct V_210 * V_263 = & V_233 -> V_264 ;
T_2 V_240 ;
T_2 V_254 ;
T_2 V_206 ;
int V_241 = - V_228 ;
V_254 = F_171 ( * ( * V_12 ) ++ ) ;
V_240 = ( V_219 * ) ( * V_12 ) - ( V_219 * ) V_263 -> V_185 [ 0 ] . V_215 ;
if ( V_240 + V_254 > V_263 -> V_15 )
return V_241 ;
V_263 -> V_15 = V_240 + V_254 ;
V_206 = F_189 ( V_2 -> V_43 , V_240 , V_263 ) ;
if ( V_206 == V_220 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_206 != V_267 )
return V_241 ;
if ( F_171 ( * ( * V_12 ) ++ ) != V_233 -> V_213 )
return V_241 ;
return 0 ;
}
static int
F_190 ( T_10 V_268 , struct V_203 * V_233 ,
T_8 * V_12 , void * V_234 )
{
struct V_235 V_236 ;
F_191 ( & V_236 , & V_233 -> V_264 , V_12 ) ;
return V_268 ( V_233 , & V_236 , V_234 ) ;
}
static int
F_192 ( struct V_71 * V_72 ,
T_10 V_268 , void * V_233 , T_8 * V_12 , void * V_234 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_269 = V_12 ;
struct V_208 * V_185 = ( (struct V_203 * ) V_233 ) -> V_264 . V_185 ;
int V_270 = V_185 -> V_218 ;
int V_241 = - V_228 ;
if ( V_2 -> V_23 != V_24 )
goto V_271;
switch ( V_6 -> V_193 ) {
case V_260 :
break;
case V_261 :
V_241 = F_186 ( V_5 , V_2 , V_233 , & V_12 ) ;
if ( V_241 )
goto V_97;
break;
case V_262 :
V_241 = F_188 ( V_5 , V_2 , V_233 , & V_12 ) ;
if ( V_241 )
goto V_97;
break;
}
V_5 -> V_92 -> V_160 = V_5 -> V_92 -> V_231 + ( V_12 - V_269 )
+ ( V_270 - V_185 -> V_218 ) ;
V_271:
V_241 = F_190 ( V_268 , V_233 , V_12 , V_234 ) ;
V_97:
F_3 ( V_2 ) ;
F_28 ( L_34 ,
V_72 -> V_94 , V_44 , V_241 ) ;
return V_241 ;
}
static T_11 int F_193 ( struct V_45 * V_45 )
{
return F_194 ( V_45 ) ;
}
static T_12 void F_195 ( struct V_45 * V_45 )
{
F_196 ( V_45 ) ;
}
static int T_13 F_197 ( void )
{
int V_35 = 0 ;
V_35 = F_198 ( & V_163 ) ;
if ( V_35 )
goto V_97;
V_35 = F_199 () ;
if ( V_35 )
goto V_272;
V_35 = F_200 ( & V_273 ) ;
if ( V_35 )
goto V_274;
F_59 ( & V_96 , L_35 ) ;
return 0 ;
V_274:
F_201 () ;
V_272:
F_202 ( & V_163 ) ;
V_97:
return V_35 ;
}
static void T_14 F_203 ( void )
{
F_204 ( & V_273 ) ;
F_201 () ;
F_202 ( & V_163 ) ;
F_205 () ;
}
