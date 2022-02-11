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
F_56 ( sizeof( V_60 ) > sizeof( V_54 -> V_77 ) ) ;
}
static int F_57 ( struct V_53 * V_54 ,
const char * V_78 ,
const char * V_79 )
{
struct V_27 * V_80 = V_54 -> V_55 -> V_80 ;
char * V_12 = V_54 -> V_77 ;
T_1 V_81 = sizeof( V_54 -> V_77 ) ;
int V_15 ;
V_15 = F_58 ( V_12 , V_81 , L_5 , V_80 -> V_82 ,
F_55 ( & V_76 , V_54 -> V_60 ) ) ;
V_81 -= V_15 ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 = V_15 ;
if ( V_79 ) {
V_15 = F_58 ( V_12 , V_81 , L_6 , V_79 ) ;
V_81 -= V_15 ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 += V_15 ;
}
if ( V_78 != NULL ) {
V_15 = F_58 ( V_12 , V_81 , L_7 , V_78 ) ;
V_81 -= V_15 ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 += V_15 ;
}
if ( V_80 -> V_83 ) {
V_15 = F_58 ( V_12 , V_81 , L_8 ,
V_80 -> V_83 ) ;
V_81 -= V_15 ;
V_12 += V_15 ;
V_54 -> V_65 . V_15 += V_15 ;
}
V_15 = F_58 ( V_12 , V_81 , L_9 ) ;
if ( V_15 == 0 )
goto V_84;
V_54 -> V_65 . V_15 += V_15 ;
V_54 -> V_65 . V_20 = V_54 -> V_77 ;
return 0 ;
V_84:
F_59 ( 1 ) ;
return - V_22 ;
}
static struct V_53 *
F_60 ( struct V_85 * V_85 ,
T_3 V_60 , const char * V_78 )
{
struct V_53 * V_54 ;
int V_86 ;
int V_35 = - V_22 ;
V_54 = F_23 ( sizeof( * V_54 ) , V_21 ) ;
if ( V_54 == NULL )
goto V_35;
V_86 = F_30 ( V_85 -> V_45 ) ;
V_35 = V_86 ;
if ( V_35 < 0 )
goto V_87;
V_54 -> V_59 = V_85 -> V_88 [ V_86 ] -> V_59 ;
F_61 ( & V_54 -> V_56 ) ;
F_62 ( & V_54 -> V_57 , L_10 ) ;
F_63 ( & V_54 -> V_67 ) ;
F_25 ( & V_54 -> V_3 , 1 ) ;
V_54 -> V_60 = V_60 ;
V_54 -> V_55 = V_85 ;
switch ( V_86 ) {
case 0 :
F_54 ( V_54 ) ;
break;
default:
V_35 = F_57 ( V_54 , V_78 , V_85 -> V_79 ) ;
if ( V_35 )
goto V_87;
} ;
return V_54 ;
V_87:
F_40 ( V_54 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static struct V_53 *
F_64 ( struct V_85 * V_85 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_53 * V_89 , * V_54 ;
T_3 V_60 = V_5 -> V_90 ;
V_89 = F_60 ( V_85 , V_60 , V_6 -> V_91 ) ;
if ( F_17 ( V_89 ) )
return V_89 ;
V_54 = F_44 ( V_89 ) ;
if ( V_54 == V_89 ) {
int V_14 = F_65 ( V_89 -> V_59 , & V_89 -> V_65 ) ;
if ( V_14 ) {
F_51 ( V_89 ) ;
V_54 = F_15 ( V_14 ) ;
}
} else
F_36 ( V_89 ) ;
return V_54 ;
}
static void F_66 ( void )
{
static unsigned long V_92 ;
unsigned long V_31 = V_32 ;
if ( F_67 ( V_31 , V_92 ) ) {
F_68 ( V_93 L_11
L_12 ) ;
V_92 = V_31 + 15 * V_38 ;
}
}
static inline int
F_69 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_85 * V_85 = F_7 ( V_5 -> V_94 ,
struct V_85 , V_95 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_53 * V_54 ;
struct V_58 * V_59 ;
int V_35 = 0 ;
F_28 ( L_13 ,
V_72 -> V_96 , V_44 , F_55 ( & V_76 , V_5 -> V_90 ) ) ;
V_54 = F_64 ( V_85 , V_5 ) ;
if ( F_29 ( V_54 ) == - V_52 ) {
F_66 () ;
V_72 -> V_97 = 15 * V_38 ;
F_70 ( & V_98 , V_72 , NULL ) ;
return - V_52 ;
}
if ( F_17 ( V_54 ) ) {
V_35 = F_29 ( V_54 ) ;
goto V_99;
}
V_59 = V_54 -> V_59 ;
F_32 ( & V_59 -> V_63 ) ;
if ( V_6 -> V_70 != NULL )
F_70 ( & V_6 -> V_70 -> V_57 , V_72 , NULL ) ;
else if ( V_54 -> V_2 == NULL && V_54 -> V_65 . V_66 >= 0 ) {
V_72 -> V_97 = 0 ;
V_6 -> V_70 = V_54 ;
F_2 ( & V_54 -> V_3 ) ;
F_70 ( & V_54 -> V_57 , V_72 , F_53 ) ;
} else {
F_52 ( V_6 , V_54 ) ;
V_35 = V_54 -> V_65 . V_66 ;
}
F_33 ( & V_59 -> V_63 ) ;
F_36 ( V_54 ) ;
V_99:
F_28 ( L_14 ,
V_72 -> V_96 , V_44 ,
F_55 ( & V_76 , V_5 -> V_90 ) , V_35 ) ;
return V_35 ;
}
static inline int
F_71 ( struct V_85 * V_85 , struct V_6 * V_6 )
{
struct V_45 * V_45 = V_85 -> V_45 ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
struct V_58 * V_59 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_53 * V_54 ;
unsigned long V_30 ;
F_72 ( V_100 ) ;
int V_35 ;
F_28 ( L_15 ,
V_44 , F_55 ( & V_76 , V_5 -> V_90 ) ) ;
V_101:
V_35 = 0 ;
V_30 = 15 * V_38 ;
if ( ! V_47 -> V_102 )
V_30 = V_38 >> 2 ;
V_54 = F_64 ( V_85 , V_5 ) ;
if ( F_29 ( V_54 ) == - V_52 ) {
V_35 = F_73 ( V_103 ,
V_47 -> V_50 >= 0 , V_30 ) ;
if ( V_47 -> V_50 < 0 ) {
if ( V_35 == 0 )
V_47 -> V_102 = 0 ;
F_66 () ;
V_35 = - V_41 ;
}
if ( V_35 < 0 )
goto V_99;
goto V_101;
}
if ( F_17 ( V_54 ) ) {
V_35 = F_29 ( V_54 ) ;
goto V_99;
}
V_59 = V_54 -> V_59 ;
for (; ; ) {
F_74 ( & V_54 -> V_67 , & V_100 , V_104 ) ;
F_32 ( & V_59 -> V_63 ) ;
if ( V_54 -> V_2 != NULL || V_54 -> V_65 . V_66 < 0 ) {
break;
}
F_33 ( & V_59 -> V_63 ) ;
if ( F_75 ( V_105 ) ) {
V_35 = - V_106 ;
goto V_107;
}
F_76 () ;
}
if ( V_54 -> V_2 )
F_6 ( V_5 , V_54 -> V_2 ) ;
else
V_35 = V_54 -> V_65 . V_66 ;
F_33 ( & V_59 -> V_63 ) ;
V_107:
F_77 ( & V_54 -> V_67 , & V_100 ) ;
F_36 ( V_54 ) ;
V_99:
F_28 ( L_16 ,
V_44 , F_55 ( & V_76 , V_5 -> V_90 ) , V_35 ) ;
return V_35 ;
}
static T_5
F_78 ( struct V_108 * V_109 , const char T_6 * V_110 , T_1 V_111 )
{
const void * V_12 , * V_13 ;
void * V_112 ;
struct V_53 * V_54 ;
struct V_58 * V_59 = F_79 ( F_80 ( V_109 ) ) -> V_59 ;
struct V_1 * V_2 ;
T_4 V_113 ;
T_3 V_60 ;
T_5 V_35 = - V_114 ;
if ( V_111 > V_115 )
goto V_99;
V_35 = - V_22 ;
V_112 = F_81 ( V_111 , V_21 ) ;
if ( ! V_112 )
goto V_99;
V_35 = - V_17 ;
if ( F_82 ( V_112 , V_110 , V_111 ) )
goto V_35;
V_13 = ( const void * ) ( ( char * ) V_112 + V_111 ) ;
V_12 = F_13 ( V_112 , V_13 , & V_113 , sizeof( V_113 ) ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
goto V_35;
}
V_60 = F_83 ( & V_76 , V_113 ) ;
if ( ! F_84 ( V_60 ) ) {
V_35 = - V_116 ;
goto V_35;
}
V_35 = - V_22 ;
V_2 = F_22 () ;
if ( V_2 == NULL )
goto V_35;
V_35 = - V_117 ;
F_32 ( & V_59 -> V_63 ) ;
V_54 = F_41 ( V_59 , V_60 ) ;
if ( V_54 == NULL ) {
F_33 ( & V_59 -> V_63 ) ;
goto V_118;
}
F_47 ( & V_54 -> V_56 ) ;
F_33 ( & V_59 -> V_63 ) ;
V_12 = F_26 ( V_12 , V_13 , V_2 , V_54 -> V_55 -> V_80 ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
switch ( V_35 ) {
case - V_41 :
case - V_40 :
V_54 -> V_65 . V_66 = V_35 ;
V_35 = V_111 ;
break;
case - V_17 :
case - V_22 :
case - V_116 :
case - V_119 :
V_54 -> V_65 . V_66 = - V_52 ;
break;
default:
F_68 ( V_120 L_17
L_18 , V_44 , V_35 ) ;
F_85 () ;
}
goto V_121;
}
V_54 -> V_2 = F_1 ( V_2 ) ;
V_35 = V_111 ;
V_121:
F_32 ( & V_59 -> V_63 ) ;
F_46 ( V_54 ) ;
F_33 ( & V_59 -> V_63 ) ;
F_36 ( V_54 ) ;
V_118:
F_3 ( V_2 ) ;
V_35:
F_40 ( V_112 ) ;
V_99:
F_28 ( L_19 , V_44 , V_35 ) ;
return V_35 ;
}
static int F_86 ( struct V_122 * V_122 , int V_123 )
{
struct V_45 * V_45 = V_122 -> V_124 -> V_125 ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
int V_34 = 0 ;
F_32 ( & V_49 ) ;
if ( V_47 -> V_50 < 0 ) {
V_47 -> V_50 = V_123 ;
F_87 ( & V_98 ) ;
F_88 ( & V_103 ) ;
} else if ( V_47 -> V_50 != V_123 ) {
V_34 = - V_126 ;
goto V_99;
}
F_2 ( & V_47 -> V_51 ) ;
V_99:
F_33 ( & V_49 ) ;
return V_34 ;
}
static int F_89 ( struct V_122 * V_122 )
{
return F_86 ( V_122 , 0 ) ;
}
static int F_90 ( struct V_122 * V_122 )
{
return F_86 ( V_122 , 1 ) ;
}
static void
F_91 ( struct V_122 * V_122 )
{
struct V_45 * V_45 = V_122 -> V_124 -> V_125 ;
struct V_58 * V_59 = F_79 ( V_122 ) -> V_59 ;
struct V_53 * V_54 ;
V_127:
F_32 ( & V_59 -> V_63 ) ;
F_42 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_38 ( & V_54 -> V_65 . V_56 ) )
continue;
V_54 -> V_65 . V_66 = - V_128 ;
F_2 ( & V_54 -> V_3 ) ;
F_46 ( V_54 ) ;
F_33 ( & V_59 -> V_63 ) ;
F_36 ( V_54 ) ;
goto V_127;
}
F_33 ( & V_59 -> V_63 ) ;
F_34 ( V_45 ) ;
}
static void
F_92 ( struct V_129 * V_65 )
{
struct V_53 * V_54 = F_7 ( V_65 , struct V_53 , V_65 ) ;
if ( V_65 -> V_66 < 0 ) {
F_28 ( L_20 ,
V_44 , V_54 ) ;
F_2 ( & V_54 -> V_3 ) ;
F_51 ( V_54 ) ;
if ( V_65 -> V_66 == - V_130 )
F_66 () ;
F_36 ( V_54 ) ;
}
}
static void F_93 ( struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_88 * V_88 = V_134 -> V_135 ;
struct V_58 * V_59 = V_88 -> V_59 ;
if ( V_59 -> V_131 != NULL ) {
F_94 ( V_59 -> V_131 ) ;
V_59 -> V_131 = NULL ;
}
}
static int F_95 ( struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_88 * V_12 = V_134 -> V_135 ;
struct V_131 * V_131 ;
V_131 = F_96 ( V_132 , V_12 -> V_136 , V_12 -> V_137 , V_12 -> V_59 ) ;
if ( F_17 ( V_131 ) )
return F_29 ( V_131 ) ;
V_12 -> V_59 -> V_131 = V_131 ;
return 0 ;
}
static struct V_88 * F_97 ( struct V_138 * V_137 ,
const char * V_136 ,
const struct V_139 * V_140 )
{
struct V_88 * V_12 ;
int V_35 = - V_22 ;
V_12 = F_81 ( sizeof( * V_12 ) , V_141 ) ;
if ( V_12 == NULL )
goto V_35;
V_12 -> V_59 = F_98 ( V_140 , V_142 ) ;
if ( F_17 ( V_12 -> V_59 ) ) {
V_35 = F_29 ( V_12 -> V_59 ) ;
goto V_143;
}
V_12 -> V_136 = V_136 ;
V_12 -> V_137 = V_137 ;
F_99 ( & V_12 -> V_144 ) ;
F_100 ( & V_12 -> V_134 ,
& V_145 ,
V_12 ) ;
return V_12 ;
V_143:
F_40 ( V_12 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static int F_101 ( struct V_133 * V_134 , void * V_20 )
{
struct V_88 * V_88 ;
struct V_146 * args = V_20 ;
if ( V_134 -> V_147 != & V_145 )
return 0 ;
V_88 = F_7 ( V_134 , struct V_88 , V_134 ) ;
if ( strcmp ( V_88 -> V_136 , args -> V_136 ) != 0 )
return 0 ;
if ( ! F_102 ( & V_88 -> V_144 ) )
return 0 ;
return 1 ;
}
static struct V_133 * F_103 ( void * V_20 )
{
struct V_88 * V_88 ;
struct V_146 * args = V_20 ;
V_88 = F_97 ( args -> V_137 , args -> V_136 , args -> V_140 ) ;
if ( ! F_17 ( V_88 ) )
return & V_88 -> V_134 ;
return NULL ;
}
static struct V_88 * F_104 ( struct V_138 * V_137 ,
const char * V_136 ,
const struct V_139 * V_140 )
{
struct V_45 * V_45 = F_105 ( V_137 ) ;
struct V_133 * V_134 ;
struct V_146 args = {
. V_137 = V_137 ,
. V_136 = V_136 ,
. V_140 = V_140 ,
} ;
V_134 = F_106 ( V_45 ,
& V_137 -> V_148 ,
F_101 ,
F_103 ,
& args ) ;
if ( V_134 != NULL )
return F_7 ( V_134 , struct V_88 , V_134 ) ;
return F_15 ( - V_22 ) ;
}
static void F_107 ( struct V_88 * V_12 )
{
struct V_138 * V_137 = V_12 -> V_137 ;
struct V_45 * V_45 = F_105 ( V_137 ) ;
F_108 ( V_45 ,
& V_137 -> V_148 ,
& V_12 -> V_134 ) ;
F_109 ( V_12 -> V_59 ) ;
F_40 ( V_12 ) ;
}
static void F_110 ( struct V_144 * V_144 )
{
struct V_88 * V_12 = F_7 ( V_144 , struct V_88 , V_144 ) ;
F_107 ( V_12 ) ;
}
static void F_111 ( struct V_88 * V_12 )
{
if ( V_12 != NULL )
F_112 ( & V_12 -> V_144 , F_110 ) ;
}
static struct V_85 *
F_113 ( struct V_149 * args , struct V_138 * V_137 )
{
T_7 V_150 = args -> V_151 ;
struct V_85 * V_85 ;
struct V_88 * V_88 ;
struct V_95 * V_55 ;
int V_35 = - V_22 ;
F_28 ( L_21 , V_137 ) ;
if ( ! F_114 ( V_152 ) )
return F_15 ( V_35 ) ;
if ( ! ( V_85 = F_81 ( sizeof( * V_85 ) , V_141 ) ) )
goto V_153;
F_115 ( & V_85 -> V_154 ) ;
V_85 -> V_79 = NULL ;
if ( args -> V_79 ) {
V_85 -> V_79 = F_116 ( args -> V_79 , V_141 ) ;
if ( V_85 -> V_79 == NULL )
goto V_155;
}
V_85 -> V_156 = V_137 ;
V_85 -> V_45 = F_117 ( F_105 ( V_137 ) ) ;
V_35 = - V_116 ;
V_85 -> V_80 = F_118 ( V_150 ) ;
if ( ! V_85 -> V_80 ) {
F_28 ( L_22 , V_150 ) ;
goto V_157;
}
V_85 -> V_158 = F_119 ( V_85 -> V_80 , V_150 ) ;
if ( V_85 -> V_158 == 0 )
goto V_159;
V_55 = & V_85 -> V_95 ;
V_55 -> V_160 = V_161 >> 2 ;
V_55 -> V_162 = V_163 >> 2 ;
V_55 -> V_164 = & V_165 ;
V_55 -> V_166 = V_150 ;
F_25 ( & V_55 -> V_167 , 1 ) ;
F_99 ( & V_85 -> V_144 ) ;
V_35 = F_120 ( V_55 ) ;
if ( V_35 )
goto V_159;
V_88 = F_104 ( V_137 , L_23 , & V_168 ) ;
if ( F_17 ( V_88 ) ) {
V_35 = F_29 ( V_88 ) ;
goto V_169;
}
V_85 -> V_88 [ 1 ] = V_88 ;
V_88 = F_104 ( V_137 , V_85 -> V_80 -> V_82 ,
& V_170 ) ;
if ( F_17 ( V_88 ) ) {
V_35 = F_29 ( V_88 ) ;
goto V_171;
}
V_85 -> V_88 [ 0 ] = V_88 ;
return V_85 ;
V_171:
F_111 ( V_85 -> V_88 [ 1 ] ) ;
V_169:
F_121 ( V_55 ) ;
V_159:
F_122 ( V_85 -> V_80 ) ;
V_157:
F_123 ( V_85 -> V_45 ) ;
V_155:
F_40 ( V_85 -> V_79 ) ;
F_40 ( V_85 ) ;
V_153:
F_124 ( V_152 ) ;
return F_15 ( V_35 ) ;
}
static void
F_125 ( struct V_85 * V_85 )
{
F_111 ( V_85 -> V_88 [ 0 ] ) ;
F_111 ( V_85 -> V_88 [ 1 ] ) ;
F_122 ( V_85 -> V_80 ) ;
F_123 ( V_85 -> V_45 ) ;
F_40 ( V_85 -> V_79 ) ;
F_40 ( V_85 ) ;
F_124 ( V_152 ) ;
}
static void
F_126 ( struct V_144 * V_144 )
{
struct V_85 * V_85 = F_7 ( V_144 , struct V_85 , V_144 ) ;
F_125 ( V_85 ) ;
}
static void
F_127 ( struct V_95 * V_55 )
{
struct V_85 * V_85 = F_7 ( V_55 ,
struct V_85 , V_95 ) ;
F_28 ( L_24 ,
V_55 , V_55 -> V_166 ) ;
if ( F_128 ( & V_85 -> V_154 ) ) {
F_32 ( & V_172 ) ;
F_129 ( & V_85 -> V_154 ) ;
F_33 ( & V_172 ) ;
}
F_111 ( V_85 -> V_88 [ 0 ] ) ;
V_85 -> V_88 [ 0 ] = NULL ;
F_111 ( V_85 -> V_88 [ 1 ] ) ;
V_85 -> V_88 [ 1 ] = NULL ;
F_121 ( V_55 ) ;
F_112 ( & V_85 -> V_144 , F_126 ) ;
}
static struct V_85 *
F_130 ( struct V_149 * args ,
struct V_138 * V_137 ,
struct V_85 * V_173 )
{
struct V_85 * V_85 ;
unsigned long V_174 = ( unsigned long ) V_137 ;
F_32 ( & V_172 ) ;
F_131 (gss_auth_hash_table,
gss_auth,
hash,
hashval) {
if ( V_85 -> V_156 != V_137 )
continue;
if ( V_85 -> V_95 . V_166 != args -> V_151 )
continue;
if ( V_85 -> V_79 != args -> V_79 ) {
if ( V_85 -> V_79 == NULL )
continue;
if ( args -> V_79 == NULL )
continue;
if ( strcmp ( V_85 -> V_79 , args -> V_79 ) )
continue;
}
if ( ! F_132 ( & V_85 -> V_95 . V_167 ) )
continue;
goto V_99;
}
if ( V_173 )
F_133 ( V_175 , & V_173 -> V_154 , V_174 ) ;
V_85 = V_173 ;
V_99:
F_33 ( & V_172 ) ;
return V_85 ;
}
static struct V_85 *
F_134 ( struct V_149 * args , struct V_138 * V_137 )
{
struct V_85 * V_85 ;
struct V_85 * V_173 ;
V_85 = F_130 ( args , V_137 , NULL ) ;
if ( V_85 != NULL )
goto V_99;
V_173 = F_113 ( args , V_137 ) ;
if ( F_17 ( V_173 ) )
return V_173 ;
V_85 = F_130 ( args , V_137 , V_173 ) ;
if ( V_85 != V_173 )
F_127 ( & V_173 -> V_95 ) ;
V_99:
return V_85 ;
}
static struct V_95 *
F_135 ( struct V_149 * args , struct V_138 * V_137 )
{
struct V_85 * V_85 ;
struct V_176 * V_177 = F_136 ( V_137 -> V_178 ) ;
while ( V_137 != V_137 -> V_179 ) {
struct V_138 * V_180 = V_137 -> V_179 ;
if ( F_136 ( V_180 -> V_178 ) != V_177 )
break;
V_137 = V_180 ;
}
V_85 = F_134 ( args , V_137 ) ;
if ( F_17 ( V_85 ) )
return F_137 ( V_85 ) ;
return & V_85 -> V_95 ;
}
static int
F_138 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_85 * V_85 = F_7 ( V_5 -> V_94 , struct V_85 , V_95 ) ;
struct V_71 * V_72 ;
if ( V_6 -> V_10 == NULL ||
F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_6 -> V_10 -> V_23 = V_181 ;
V_5 -> V_182 = & V_183 ;
F_139 ( V_5 ) ;
V_72 = F_140 ( V_85 -> V_156 , V_5 , V_184 | V_185 ) ;
if ( ! F_17 ( V_72 ) )
F_141 ( V_72 ) ;
F_142 ( V_5 ) ;
return 1 ;
}
static void
F_143 ( struct V_1 * V_2 )
{
F_28 ( L_25 , V_44 ) ;
F_144 ( & V_2 -> V_43 ) ;
F_40 ( V_2 -> V_42 . V_20 ) ;
F_40 ( V_2 ) ;
}
static void
F_145 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_7 ( V_187 , struct V_1 , V_188 ) ;
F_143 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_146 ( & V_2 -> V_188 , F_145 ) ;
}
static void
F_147 ( struct V_6 * V_6 )
{
F_28 ( L_26 , V_44 , V_6 ) ;
F_40 ( V_6 ) ;
}
static void
F_148 ( struct V_186 * V_187 )
{
struct V_6 * V_6 = F_7 ( V_187 , struct V_6 , V_7 . V_189 ) ;
F_147 ( V_6 ) ;
}
static void
F_149 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_85 * V_85 = F_7 ( V_5 -> V_94 , struct V_85 , V_95 ) ;
struct V_1 * V_2 = V_6 -> V_10 ;
F_150 ( V_6 -> V_10 , NULL ) ;
F_146 ( & V_5 -> V_189 , F_148 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_112 ( & V_85 -> V_144 , F_126 ) ;
}
static void
F_151 ( struct V_4 * V_5 )
{
if ( F_138 ( V_5 ) )
return;
F_149 ( V_5 ) ;
}
static struct V_4 *
F_152 ( struct V_95 * V_55 , struct V_190 * V_191 , int V_192 )
{
return F_153 ( V_55 , V_191 , V_192 ) ;
}
static struct V_4 *
F_154 ( struct V_95 * V_55 , struct V_190 * V_191 , int V_192 )
{
struct V_85 * V_85 = F_7 ( V_55 , struct V_85 , V_95 ) ;
struct V_6 * V_5 = NULL ;
int V_35 = - V_22 ;
F_28 ( L_27 ,
V_44 , F_55 ( & V_76 , V_191 -> V_60 ) ,
V_55 -> V_166 ) ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_193;
F_155 ( & V_5 -> V_7 , V_191 , V_55 , & V_194 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_195 = V_85 -> V_158 ;
V_5 -> V_91 = NULL ;
if ( V_191 -> V_196 )
V_5 -> V_91 = V_191 -> V_197 ;
F_156 ( & V_85 -> V_144 ) ;
return & V_5 -> V_7 ;
V_193:
F_28 ( L_28 , V_44 , V_35 ) ;
return F_15 ( V_35 ) ;
}
static int
F_157 ( struct V_95 * V_55 , struct V_4 * V_5 )
{
struct V_85 * V_85 = F_7 ( V_55 , struct V_85 , V_95 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_35 ;
do {
V_35 = F_71 ( V_85 , V_6 ) ;
} while ( V_35 == - V_52 );
return V_35 ;
}
static int
F_158 ( struct V_4 * V_198 )
{
struct V_6 * V_6 = F_7 ( V_198 , struct V_6 , V_7 ) ;
unsigned long V_31 = V_32 ;
unsigned long V_199 ;
if ( V_6 -> V_10 == NULL )
return - V_41 ;
V_199 = V_6 -> V_10 -> V_37 - ( V_200 * V_38 ) ;
if ( F_67 ( V_31 , V_199 ) )
return - V_41 ;
return 0 ;
}
static int
F_159 ( struct V_190 * V_191 , struct V_4 * V_198 , int V_192 )
{
struct V_6 * V_6 = F_7 ( V_198 , struct V_6 , V_7 ) ;
int V_34 ;
if ( F_8 ( V_8 , & V_198 -> V_9 ) )
goto V_99;
if ( F_67 ( V_32 , V_6 -> V_10 -> V_37 ) )
return 0 ;
if ( ! F_8 ( V_11 , & V_198 -> V_9 ) )
return 0 ;
V_99:
if ( V_191 -> V_197 != NULL ) {
if ( V_6 -> V_91 == NULL )
return 0 ;
V_34 = strcmp ( V_191 -> V_197 , V_6 -> V_91 ) == 0 ;
goto V_201;
}
if ( V_6 -> V_91 != NULL )
return 0 ;
V_34 = F_43 ( V_198 -> V_90 , V_191 -> V_60 ) ;
V_201:
if ( V_34 == 0 )
return V_34 ;
if ( F_8 ( V_202 , & V_191 -> V_203 ) &&
( F_158 ( V_198 ) != 0 ) ) {
F_160 ( V_202 , & V_191 -> V_203 ) ;
F_10 ( V_204 , & V_191 -> V_203 ) ;
}
return V_34 ;
}
static T_8 *
F_161 ( struct V_71 * V_72 , T_8 * V_12 )
{
struct V_205 * V_206 = V_72 -> V_73 ;
struct V_4 * V_5 = V_206 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_207 ;
T_2 V_208 = 0 ;
struct V_18 V_209 ;
struct V_210 V_211 ;
struct V_212 V_213 ;
F_28 ( L_29 , V_72 -> V_96 , V_44 ) ;
* V_12 ++ = F_162 ( V_214 ) ;
V_207 = V_12 ++ ;
F_32 ( & V_2 -> V_26 ) ;
V_206 -> V_215 = V_2 -> V_25 ++ ;
F_33 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_162 ( ( T_2 ) V_216 ) ;
* V_12 ++ = F_162 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_162 ( ( T_2 ) V_206 -> V_215 ) ;
* V_12 ++ = F_162 ( ( T_2 ) V_6 -> V_195 ) ;
V_12 = F_163 ( V_12 , & V_2 -> V_42 ) ;
* V_207 = F_162 ( ( V_12 - ( V_207 + 1 ) ) << 2 ) ;
V_211 . V_217 = F_164 ( V_206 -> V_218 ,
V_206 -> V_219 . V_187 [ 0 ] . V_217 ) ;
V_211 . V_220 = ( V_221 * ) V_12 - ( V_221 * ) V_211 . V_217 ;
F_165 ( & V_211 , & V_213 ) ;
* V_12 ++ = F_162 ( V_214 ) ;
V_209 . V_20 = ( V_221 * ) ( V_12 + 1 ) ;
V_208 = F_166 ( V_2 -> V_43 , & V_213 , & V_209 ) ;
if ( V_208 == V_222 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_208 != 0 ) {
F_68 ( L_30 , V_208 ) ;
goto V_223;
}
V_12 = F_167 ( V_12 , NULL , V_209 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_223:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_168 ( struct V_71 * V_72 )
{
struct V_4 * V_224 = V_72 -> V_73 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_224 ,
struct V_6 ,
V_7 ) ;
struct V_95 * V_55 = V_224 -> V_94 ;
struct V_190 V_191 = {
. V_60 = V_224 -> V_90 ,
. V_197 = V_6 -> V_91 ,
. V_196 = ( V_6 -> V_91 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_173 ;
V_173 = F_152 ( V_55 , & V_191 , V_225 ) ;
if ( F_17 ( V_173 ) )
return F_29 ( V_173 ) ;
V_72 -> V_73 -> V_74 = V_173 ;
F_142 ( V_224 ) ;
return 0 ;
}
static int F_169 ( struct V_4 * V_5 )
{
if ( F_8 ( V_68 , & V_5 -> V_9 ) ) {
unsigned long V_31 = V_32 ;
unsigned long V_226 , V_199 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_226 = V_6 -> V_69 ;
V_199 = V_226 + V_227 * V_38 ;
if ( F_170 ( V_31 , V_226 , V_199 ) )
return 1 ;
}
return 0 ;
}
static int
F_171 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
int V_34 = 0 ;
if ( F_169 ( V_5 ) )
return - V_40 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_34 = F_168 ( V_72 ) ;
if ( V_34 < 0 )
goto V_99;
V_5 = V_72 -> V_73 -> V_74 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_34 = F_69 ( V_72 ) ;
V_99:
return V_34 ;
}
static int
F_172 ( struct V_71 * V_72 )
{
return 0 ;
}
static T_8 *
F_173 ( struct V_71 * V_72 , T_8 * V_12 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 V_228 ;
struct V_210 V_211 ;
struct V_212 V_213 ;
struct V_18 V_209 ;
T_2 V_229 , V_15 ;
T_2 V_208 ;
T_8 * V_34 = F_15 ( - V_230 ) ;
F_28 ( L_29 , V_72 -> V_96 , V_44 ) ;
V_229 = F_174 ( * V_12 ++ ) ;
if ( ( V_15 = F_174 ( * V_12 ++ ) ) > V_231 )
goto V_232;
if ( V_229 != V_214 )
goto V_232;
V_228 = F_162 ( V_72 -> V_73 -> V_215 ) ;
V_211 . V_217 = & V_228 ;
V_211 . V_220 = sizeof( V_228 ) ;
F_165 ( & V_211 , & V_213 ) ;
V_209 . V_20 = ( V_221 * ) V_12 ;
V_209 . V_15 = V_15 ;
V_34 = F_15 ( - V_41 ) ;
V_208 = F_175 ( V_2 -> V_43 , & V_213 , & V_209 ) ;
if ( V_208 == V_222 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_208 ) {
F_28 ( L_31 ,
V_72 -> V_96 , V_44 , V_208 ) ;
goto V_232;
}
V_5 -> V_94 -> V_233 = F_176 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_28 ( L_32 ,
V_72 -> V_96 , V_44 ) ;
return V_12 + F_176 ( V_15 ) ;
V_232:
F_3 ( V_2 ) ;
F_28 ( L_33 , V_72 -> V_96 , V_44 ,
F_29 ( V_34 ) ) ;
return V_34 ;
}
static void F_177 ( T_9 V_234 , struct V_205 * V_235 ,
T_8 * V_12 , void * V_236 )
{
struct V_237 V_238 ;
F_178 ( & V_238 , & V_235 -> V_219 , V_12 ) ;
V_234 ( V_235 , & V_238 , V_236 ) ;
}
static inline int
F_179 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_234 , struct V_205 * V_235 ,
T_8 * V_12 , void * V_236 )
{
struct V_212 * V_239 = & V_235 -> V_219 ;
struct V_212 V_240 ;
T_8 * V_241 = NULL ;
struct V_18 V_209 ;
T_2 V_242 ;
T_8 * V_16 ;
struct V_210 * V_211 ;
T_2 V_208 = 0 ;
int V_243 = - V_230 ;
V_241 = V_12 ++ ;
V_242 = ( V_221 * ) V_12 - ( V_221 * ) V_239 -> V_187 [ 0 ] . V_217 ;
* V_12 ++ = F_162 ( V_235 -> V_215 ) ;
F_177 ( V_234 , V_235 , V_12 , V_236 ) ;
if ( F_180 ( V_239 , & V_240 ,
V_242 , V_239 -> V_15 - V_242 ) )
return V_243 ;
* V_241 = F_162 ( V_240 . V_15 ) ;
if ( V_239 -> V_244 || V_239 -> V_245 [ 0 ] . V_220 )
V_211 = V_239 -> V_245 ;
else
V_211 = V_239 -> V_187 ;
V_12 = V_211 -> V_217 + V_211 -> V_220 ;
V_209 . V_20 = ( V_221 * ) ( V_12 + 1 ) ;
V_208 = F_166 ( V_2 -> V_43 , & V_240 , & V_209 ) ;
V_243 = - V_230 ;
if ( V_208 == V_222 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_208 )
return V_243 ;
V_16 = F_167 ( V_12 , NULL , V_209 . V_15 ) ;
V_242 = ( V_221 * ) V_16 - ( V_221 * ) V_12 ;
V_211 -> V_220 += V_242 ;
V_239 -> V_15 += V_242 ;
return 0 ;
}
static void
F_181 ( struct V_205 * V_235 )
{
int V_246 ;
for ( V_246 = 0 ; V_246 < V_235 -> V_247 ; V_246 ++ )
F_182 ( V_235 -> V_248 [ V_246 ] ) ;
F_40 ( V_235 -> V_248 ) ;
}
static int
F_183 ( struct V_205 * V_235 )
{
struct V_212 * V_239 = & V_235 -> V_219 ;
int V_249 , V_250 , V_246 ;
if ( V_239 -> V_244 == 0 ) {
V_235 -> V_247 = 0 ;
return 0 ;
}
V_249 = V_239 -> V_251 >> V_252 ;
V_250 = ( V_239 -> V_251 + V_239 -> V_244 - 1 ) >> V_252 ;
V_235 -> V_247 = V_250 - V_249 + 1 + 1 ;
V_235 -> V_248
= F_81 ( V_235 -> V_247 * sizeof( struct V_253 * ) ,
V_21 ) ;
if ( ! V_235 -> V_248 )
goto V_99;
for ( V_246 = 0 ; V_246 < V_235 -> V_247 ; V_246 ++ ) {
V_235 -> V_248 [ V_246 ] = F_184 ( V_21 ) ;
if ( V_235 -> V_248 [ V_246 ] == NULL )
goto V_254;
}
V_235 -> V_255 = F_181 ;
return 0 ;
V_254:
V_235 -> V_247 = V_246 ;
F_181 ( V_235 ) ;
V_99:
return - V_52 ;
}
static inline int
F_185 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_234 , struct V_205 * V_235 ,
T_8 * V_12 , void * V_236 )
{
struct V_212 * V_239 = & V_235 -> V_219 ;
T_2 V_242 ;
T_2 V_208 ;
int V_243 ;
T_8 * V_256 ;
struct V_253 * * V_257 ;
int V_249 ;
int V_258 ;
struct V_210 * V_211 ;
char * V_259 ;
V_256 = V_12 ++ ;
V_242 = ( V_221 * ) V_12 - ( V_221 * ) V_239 -> V_187 [ 0 ] . V_217 ;
* V_12 ++ = F_162 ( V_235 -> V_215 ) ;
F_177 ( V_234 , V_235 , V_12 , V_236 ) ;
V_243 = F_183 ( V_235 ) ;
if ( V_243 )
return V_243 ;
V_249 = V_239 -> V_251 >> V_252 ;
V_257 = V_239 -> V_260 + V_249 ;
V_239 -> V_260 = V_235 -> V_248 ;
V_239 -> V_251 -= V_249 << V_252 ;
if ( V_239 -> V_244 || V_239 -> V_245 [ 0 ] . V_220 ) {
V_259 = F_186 ( V_235 -> V_248 [ V_235 -> V_247 - 1 ] ) ;
memcpy ( V_259 , V_239 -> V_245 [ 0 ] . V_217 , V_239 -> V_245 [ 0 ] . V_220 ) ;
V_239 -> V_245 [ 0 ] . V_217 = V_259 ;
}
V_208 = F_187 ( V_2 -> V_43 , V_242 , V_239 , V_257 ) ;
F_37 ( V_239 -> V_15 > V_239 -> V_81 ) ;
V_243 = - V_230 ;
if ( V_208 == V_222 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_208 )
return V_243 ;
* V_256 = F_162 ( V_239 -> V_15 - V_242 ) ;
if ( V_239 -> V_244 || V_239 -> V_245 [ 0 ] . V_220 )
V_211 = V_239 -> V_245 ;
else
V_211 = V_239 -> V_187 ;
V_12 = V_211 -> V_217 + V_211 -> V_220 ;
V_258 = 3 - ( ( V_239 -> V_15 - V_242 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_258 ) ;
V_211 -> V_220 += V_258 ;
V_239 -> V_15 += V_258 ;
return 0 ;
}
static int
F_188 ( struct V_71 * V_72 ,
T_9 V_234 , void * V_235 , T_8 * V_12 , void * V_236 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_243 = - V_230 ;
F_28 ( L_29 , V_72 -> V_96 , V_44 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_177 ( V_234 , V_235 , V_12 , V_236 ) ;
V_243 = 0 ;
goto V_99;
}
switch ( V_6 -> V_195 ) {
case V_261 :
F_177 ( V_234 , V_235 , V_12 , V_236 ) ;
V_243 = 0 ;
break;
case V_262 :
V_243 = F_179 ( V_5 , V_2 , V_234 , V_235 , V_12 , V_236 ) ;
break;
case V_263 :
V_243 = F_185 ( V_5 , V_2 , V_234 , V_235 , V_12 , V_236 ) ;
break;
}
V_99:
F_3 ( V_2 ) ;
F_28 ( L_34 , V_72 -> V_96 , V_44 , V_243 ) ;
return V_243 ;
}
static inline int
F_189 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_205 * V_235 , T_8 * * V_12 )
{
struct V_212 * V_264 = & V_235 -> V_265 ;
struct V_212 V_240 ;
struct V_18 V_209 ;
T_2 V_266 , V_267 ;
T_2 V_241 ;
T_2 V_208 ;
int V_243 = - V_230 ;
V_241 = F_174 ( * ( * V_12 ) ++ ) ;
if ( V_241 & 3 )
return V_243 ;
V_266 = ( V_221 * ) ( * V_12 ) - ( V_221 * ) V_264 -> V_187 [ 0 ] . V_217 ;
V_267 = V_241 + V_266 ;
if ( V_267 > V_264 -> V_15 )
return V_243 ;
if ( F_174 ( * ( * V_12 ) ++ ) != V_235 -> V_215 )
return V_243 ;
if ( F_180 ( V_264 , & V_240 , V_266 ,
V_267 - V_266 ) )
return V_243 ;
if ( F_190 ( V_264 , & V_209 , V_267 ) )
return V_243 ;
V_208 = F_175 ( V_2 -> V_43 , & V_240 , & V_209 ) ;
if ( V_208 == V_222 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_208 != V_268 )
return V_243 ;
return 0 ;
}
static inline int
F_191 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_205 * V_235 , T_8 * * V_12 )
{
struct V_212 * V_264 = & V_235 -> V_265 ;
T_2 V_242 ;
T_2 V_256 ;
T_2 V_208 ;
int V_243 = - V_230 ;
V_256 = F_174 ( * ( * V_12 ) ++ ) ;
V_242 = ( V_221 * ) ( * V_12 ) - ( V_221 * ) V_264 -> V_187 [ 0 ] . V_217 ;
if ( V_242 + V_256 > V_264 -> V_15 )
return V_243 ;
V_264 -> V_15 = V_242 + V_256 ;
V_208 = F_192 ( V_2 -> V_43 , V_242 , V_264 ) ;
if ( V_208 == V_222 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_208 != V_268 )
return V_243 ;
if ( F_174 ( * ( * V_12 ) ++ ) != V_235 -> V_215 )
return V_243 ;
return 0 ;
}
static int
F_193 ( T_10 V_269 , struct V_205 * V_235 ,
T_8 * V_12 , void * V_236 )
{
struct V_237 V_238 ;
F_194 ( & V_238 , & V_235 -> V_265 , V_12 ) ;
return V_269 ( V_235 , & V_238 , V_236 ) ;
}
static int
F_195 ( struct V_71 * V_72 ,
T_10 V_269 , void * V_235 , T_8 * V_12 , void * V_236 )
{
struct V_4 * V_5 = V_72 -> V_73 -> V_74 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_270 = V_12 ;
struct V_210 * V_187 = ( (struct V_205 * ) V_235 ) -> V_265 . V_187 ;
int V_271 = V_187 -> V_220 ;
int V_243 = - V_230 ;
if ( V_2 -> V_23 != V_24 )
goto V_272;
switch ( V_6 -> V_195 ) {
case V_261 :
break;
case V_262 :
V_243 = F_189 ( V_5 , V_2 , V_235 , & V_12 ) ;
if ( V_243 )
goto V_99;
break;
case V_263 :
V_243 = F_191 ( V_5 , V_2 , V_235 , & V_12 ) ;
if ( V_243 )
goto V_99;
break;
}
V_5 -> V_94 -> V_162 = V_5 -> V_94 -> V_233 + ( V_12 - V_270 )
+ ( V_271 - V_187 -> V_220 ) ;
V_272:
V_243 = F_193 ( V_269 , V_235 , V_12 , V_236 ) ;
V_99:
F_3 ( V_2 ) ;
F_28 ( L_34 ,
V_72 -> V_96 , V_44 , V_243 ) ;
return V_243 ;
}
static T_11 int F_196 ( struct V_45 * V_45 )
{
return F_197 ( V_45 ) ;
}
static T_12 void F_198 ( struct V_45 * V_45 )
{
F_199 ( V_45 ) ;
}
static int T_13 F_200 ( void )
{
int V_35 = 0 ;
V_35 = F_201 ( & V_165 ) ;
if ( V_35 )
goto V_99;
V_35 = F_202 () ;
if ( V_35 )
goto V_273;
V_35 = F_203 ( & V_274 ) ;
if ( V_35 )
goto V_275;
F_62 ( & V_98 , L_35 ) ;
return 0 ;
V_275:
F_204 () ;
V_273:
F_205 ( & V_165 ) ;
V_99:
return V_35 ;
}
static void T_14 F_206 ( void )
{
F_207 ( & V_274 ) ;
F_204 () ;
F_205 ( & V_165 ) ;
F_208 () ;
}
