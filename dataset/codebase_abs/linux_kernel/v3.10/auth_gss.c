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
struct V_45 * V_45 = F_37 ( V_54 -> V_55 -> V_56 ) ;
if ( ! F_4 ( & V_54 -> V_3 ) )
return;
F_34 ( V_45 ) ;
F_38 ( ! F_39 ( & V_54 -> V_57 ) ) ;
if ( V_54 -> V_2 != NULL )
F_3 ( V_54 -> V_2 ) ;
F_40 ( & V_54 -> V_58 ) ;
F_41 ( V_54 ) ;
}
static struct V_53 *
F_42 ( struct V_59 * V_60 , T_3 V_61 )
{
struct V_53 * V_62 ;
F_43 (pos, &pipe->in_downcall, list) {
if ( ! F_44 ( V_62 -> V_61 , V_61 ) )
continue;
F_2 ( & V_62 -> V_3 ) ;
F_28 ( L_3 , V_44 , V_62 ) ;
return V_62 ;
}
F_28 ( L_4 , V_44 ) ;
return NULL ;
}
static inline struct V_53 *
F_45 ( struct V_53 * V_54 )
{
struct V_59 * V_60 = V_54 -> V_60 ;
struct V_53 * V_63 ;
F_32 ( & V_60 -> V_64 ) ;
V_63 = F_42 ( V_60 , V_54 -> V_61 ) ;
if ( V_63 == NULL ) {
F_2 ( & V_54 -> V_3 ) ;
F_46 ( & V_54 -> V_57 , & V_60 -> V_65 ) ;
} else
V_54 = V_63 ;
F_33 ( & V_60 -> V_64 ) ;
return V_54 ;
}
static void
F_47 ( struct V_53 * V_54 )
{
F_48 ( & V_54 -> V_57 ) ;
F_49 ( & V_54 -> V_58 , V_54 -> V_66 . V_67 ) ;
F_50 ( & V_54 -> V_68 ) ;
F_51 ( & V_54 -> V_3 ) ;
}
static void
F_52 ( struct V_53 * V_54 )
{
struct V_59 * V_60 = V_54 -> V_60 ;
if ( F_39 ( & V_54 -> V_57 ) )
return;
F_32 ( & V_60 -> V_64 ) ;
if ( ! F_39 ( & V_54 -> V_57 ) )
F_47 ( V_54 ) ;
F_33 ( & V_60 -> V_64 ) ;
}
static void
F_53 ( struct V_6 * V_6 , struct V_53 * V_54 )
{
switch ( V_54 -> V_66 . V_67 ) {
case 0 :
if ( V_54 -> V_2 == NULL )
break;
F_12 ( V_69 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_54 -> V_2 ) ;
break;
case - V_40 :
F_10 ( V_69 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_70 = V_32 ;
V_6 -> V_71 = NULL ;
F_49 ( & V_54 -> V_58 , V_54 -> V_66 . V_67 ) ;
}
static void
F_54 ( struct V_72 * V_73 )
{
struct V_6 * V_6 = F_7 ( V_73 -> V_74 -> V_75 ,
struct V_6 , V_7 ) ;
struct V_53 * V_54 = V_6 -> V_71 ;
struct V_59 * V_60 = V_54 -> V_60 ;
F_32 ( & V_60 -> V_64 ) ;
F_53 ( V_6 , V_54 ) ;
F_33 ( & V_60 -> V_64 ) ;
V_73 -> V_76 = V_54 -> V_66 . V_67 ;
F_36 ( V_54 ) ;
}
static void F_55 ( struct V_53 * V_54 )
{
T_4 V_61 = F_56 ( & V_77 , V_54 -> V_61 ) ;
memcpy ( V_54 -> V_78 , & V_61 , sizeof( V_61 ) ) ;
V_54 -> V_66 . V_20 = V_54 -> V_78 ;
V_54 -> V_66 . V_15 = sizeof( V_61 ) ;
F_38 ( sizeof( V_61 ) > V_79 ) ;
}
static void F_57 ( struct V_53 * V_54 ,
struct V_80 * V_81 ,
const char * V_82 )
{
struct V_27 * V_83 = V_54 -> V_55 -> V_83 ;
char * V_12 = V_54 -> V_78 ;
int V_15 = 0 ;
V_54 -> V_66 . V_15 = sprintf ( V_54 -> V_78 , L_5 ,
V_83 -> V_84 ,
F_56 ( & V_77 , V_54 -> V_61 ) ) ;
V_12 += V_54 -> V_66 . V_15 ;
if ( V_81 -> V_85 ) {
V_15 = sprintf ( V_12 , L_6 , V_81 -> V_85 ) ;
V_12 += V_15 ;
V_54 -> V_66 . V_15 += V_15 ;
}
if ( V_82 != NULL ) {
V_15 = sprintf ( V_12 , L_7 , V_82 ) ;
V_12 += V_15 ;
V_54 -> V_66 . V_15 += V_15 ;
}
if ( V_83 -> V_86 ) {
V_15 = sprintf ( V_12 , L_8 , V_83 -> V_86 ) ;
V_12 += V_15 ;
V_54 -> V_66 . V_15 += V_15 ;
}
V_15 = sprintf ( V_12 , L_9 ) ;
V_54 -> V_66 . V_15 += V_15 ;
V_54 -> V_66 . V_20 = V_54 -> V_78 ;
F_38 ( V_54 -> V_66 . V_15 > V_79 ) ;
}
static void F_58 ( struct V_53 * V_54 ,
struct V_80 * V_81 ,
const char * V_82 )
{
struct V_45 * V_45 = F_37 ( V_81 ) ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
if ( V_47 -> V_50 == 0 )
F_55 ( V_54 ) ;
else
F_57 ( V_54 , V_81 , V_82 ) ;
}
static struct V_53 *
F_59 ( struct V_87 * V_87 , struct V_80 * V_81 ,
T_3 V_61 , const char * V_82 )
{
struct V_53 * V_54 ;
int V_88 ;
V_54 = F_23 ( sizeof( * V_54 ) , V_21 ) ;
if ( V_54 == NULL )
return F_15 ( - V_22 ) ;
V_88 = F_30 ( F_37 ( V_81 ) ) ;
if ( V_88 < 0 ) {
F_41 ( V_54 ) ;
return F_15 ( V_88 ) ;
}
V_54 -> V_60 = V_87 -> V_60 [ V_88 ] ;
F_60 ( & V_54 -> V_57 ) ;
F_61 ( & V_54 -> V_58 , L_10 ) ;
F_62 ( & V_54 -> V_68 ) ;
F_25 ( & V_54 -> V_3 , 1 ) ;
V_54 -> V_61 = V_61 ;
V_54 -> V_55 = V_87 ;
F_58 ( V_54 , V_81 , V_82 ) ;
return V_54 ;
}
static struct V_53 *
F_63 ( struct V_80 * V_81 , struct V_87 * V_87 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_53 * V_89 , * V_54 ;
T_3 V_61 = V_5 -> V_90 ;
V_89 = F_59 ( V_87 , V_81 , V_61 , V_6 -> V_91 ) ;
if ( F_17 ( V_89 ) )
return V_89 ;
V_54 = F_45 ( V_89 ) ;
if ( V_54 == V_89 ) {
int V_14 = F_64 ( V_89 -> V_60 , & V_89 -> V_66 ) ;
if ( V_14 ) {
F_52 ( V_89 ) ;
V_54 = F_15 ( V_14 ) ;
}
} else
F_36 ( V_89 ) ;
return V_54 ;
}
static void F_65 ( void )
{
static unsigned long V_92 ;
unsigned long V_31 = V_32 ;
if ( F_66 ( V_31 , V_92 ) ) {
F_67 ( V_93 L_11
L_12 ) ;
V_92 = V_31 + 15 * V_38 ;
}
}
static inline int
F_68 ( struct V_72 * V_73 )
{
struct V_4 * V_5 = V_73 -> V_74 -> V_75 ;
struct V_87 * V_87 = F_7 ( V_5 -> V_94 ,
struct V_87 , V_95 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_53 * V_54 ;
struct V_59 * V_60 ;
int V_35 = 0 ;
F_28 ( L_13 ,
V_73 -> V_96 , V_44 , F_56 ( & V_77 , V_5 -> V_90 ) ) ;
V_54 = F_63 ( V_73 -> V_97 , V_87 , V_5 ) ;
if ( F_29 ( V_54 ) == - V_52 ) {
F_65 () ;
V_73 -> V_98 = 15 * V_38 ;
F_69 ( & V_99 , V_73 , NULL ) ;
return - V_52 ;
}
if ( F_17 ( V_54 ) ) {
V_35 = F_29 ( V_54 ) ;
goto V_100;
}
V_60 = V_54 -> V_60 ;
F_32 ( & V_60 -> V_64 ) ;
if ( V_6 -> V_71 != NULL )
F_69 ( & V_6 -> V_71 -> V_58 , V_73 , NULL ) ;
else if ( V_54 -> V_2 == NULL && V_54 -> V_66 . V_67 >= 0 ) {
V_73 -> V_98 = 0 ;
V_6 -> V_71 = V_54 ;
F_2 ( & V_54 -> V_3 ) ;
F_69 ( & V_54 -> V_58 , V_73 , F_54 ) ;
} else {
F_53 ( V_6 , V_54 ) ;
V_35 = V_54 -> V_66 . V_67 ;
}
F_33 ( & V_60 -> V_64 ) ;
F_36 ( V_54 ) ;
V_100:
F_28 ( L_14 ,
V_73 -> V_96 , V_44 ,
F_56 ( & V_77 , V_5 -> V_90 ) , V_35 ) ;
return V_35 ;
}
static inline int
F_70 ( struct V_87 * V_87 , struct V_6 * V_6 )
{
struct V_45 * V_45 = F_37 ( V_87 -> V_56 ) ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
struct V_59 * V_60 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_53 * V_54 ;
unsigned long V_30 ;
F_71 ( V_101 ) ;
int V_35 ;
F_28 ( L_15 ,
V_44 , F_56 ( & V_77 , V_5 -> V_90 ) ) ;
V_102:
V_35 = 0 ;
V_30 = 15 * V_38 ;
if ( ! V_47 -> V_103 )
V_30 = V_38 >> 2 ;
V_54 = F_63 ( V_87 -> V_56 , V_87 , V_5 ) ;
if ( F_29 ( V_54 ) == - V_52 ) {
V_35 = F_72 ( V_104 ,
V_47 -> V_50 >= 0 , V_30 ) ;
if ( V_47 -> V_50 < 0 ) {
if ( V_35 == 0 )
V_47 -> V_103 = 0 ;
F_65 () ;
V_35 = - V_41 ;
}
if ( V_35 < 0 )
goto V_100;
goto V_102;
}
if ( F_17 ( V_54 ) ) {
V_35 = F_29 ( V_54 ) ;
goto V_100;
}
V_60 = V_54 -> V_60 ;
for (; ; ) {
F_73 ( & V_54 -> V_68 , & V_101 , V_105 ) ;
F_32 ( & V_60 -> V_64 ) ;
if ( V_54 -> V_2 != NULL || V_54 -> V_66 . V_67 < 0 ) {
break;
}
F_33 ( & V_60 -> V_64 ) ;
if ( F_74 ( V_106 ) ) {
V_35 = - V_107 ;
goto V_108;
}
F_75 () ;
}
if ( V_54 -> V_2 )
F_6 ( V_5 , V_54 -> V_2 ) ;
else
V_35 = V_54 -> V_66 . V_67 ;
F_33 ( & V_60 -> V_64 ) ;
V_108:
F_76 ( & V_54 -> V_68 , & V_101 ) ;
F_36 ( V_54 ) ;
V_100:
F_28 ( L_16 ,
V_44 , F_56 ( & V_77 , V_5 -> V_90 ) , V_35 ) ;
return V_35 ;
}
static T_5
F_77 ( struct V_109 * V_110 , const char T_6 * V_111 , T_1 V_112 )
{
const void * V_12 , * V_13 ;
void * V_113 ;
struct V_53 * V_54 ;
struct V_59 * V_60 = F_78 ( F_79 ( V_110 ) ) -> V_60 ;
struct V_1 * V_2 ;
T_4 V_114 ;
T_3 V_61 ;
T_5 V_35 = - V_115 ;
if ( V_112 > V_116 )
goto V_100;
V_35 = - V_22 ;
V_113 = F_80 ( V_112 , V_21 ) ;
if ( ! V_113 )
goto V_100;
V_35 = - V_17 ;
if ( F_81 ( V_113 , V_111 , V_112 ) )
goto V_35;
V_13 = ( const void * ) ( ( char * ) V_113 + V_112 ) ;
V_12 = F_13 ( V_113 , V_13 , & V_114 , sizeof( V_114 ) ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
goto V_35;
}
V_61 = F_82 ( & V_77 , V_114 ) ;
if ( ! F_83 ( V_61 ) ) {
V_35 = - V_117 ;
goto V_35;
}
V_35 = - V_22 ;
V_2 = F_22 () ;
if ( V_2 == NULL )
goto V_35;
V_35 = - V_118 ;
F_32 ( & V_60 -> V_64 ) ;
V_54 = F_42 ( V_60 , V_61 ) ;
if ( V_54 == NULL ) {
F_33 ( & V_60 -> V_64 ) ;
goto V_119;
}
F_48 ( & V_54 -> V_57 ) ;
F_33 ( & V_60 -> V_64 ) ;
V_12 = F_26 ( V_12 , V_13 , V_2 , V_54 -> V_55 -> V_83 ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_29 ( V_12 ) ;
switch ( V_35 ) {
case - V_41 :
case - V_40 :
V_54 -> V_66 . V_67 = V_35 ;
V_35 = V_112 ;
break;
case - V_17 :
case - V_22 :
case - V_117 :
case - V_120 :
V_54 -> V_66 . V_67 = - V_52 ;
break;
default:
F_67 ( V_121 L_17
L_18 , V_44 , V_35 ) ;
F_84 () ;
}
goto V_122;
}
V_54 -> V_2 = F_1 ( V_2 ) ;
V_35 = V_112 ;
V_122:
F_32 ( & V_60 -> V_64 ) ;
F_47 ( V_54 ) ;
F_33 ( & V_60 -> V_64 ) ;
F_36 ( V_54 ) ;
V_119:
F_3 ( V_2 ) ;
V_35:
F_41 ( V_113 ) ;
V_100:
F_28 ( L_19 , V_44 , V_35 ) ;
return V_35 ;
}
static int F_85 ( struct V_123 * V_123 , int V_124 )
{
struct V_45 * V_45 = V_123 -> V_125 -> V_126 ;
struct V_46 * V_47 = F_31 ( V_45 , V_48 ) ;
int V_34 = 0 ;
F_32 ( & V_49 ) ;
if ( V_47 -> V_50 < 0 ) {
V_47 -> V_50 = V_124 ;
F_86 ( & V_99 ) ;
F_87 ( & V_104 ) ;
} else if ( V_47 -> V_50 != V_124 ) {
V_34 = - V_127 ;
goto V_100;
}
F_2 ( & V_47 -> V_51 ) ;
V_100:
F_33 ( & V_49 ) ;
return V_34 ;
}
static int F_88 ( struct V_123 * V_123 )
{
return F_85 ( V_123 , 0 ) ;
}
static int F_89 ( struct V_123 * V_123 )
{
return F_85 ( V_123 , 1 ) ;
}
static void
F_90 ( struct V_123 * V_123 )
{
struct V_45 * V_45 = V_123 -> V_125 -> V_126 ;
struct V_59 * V_60 = F_78 ( V_123 ) -> V_60 ;
struct V_53 * V_54 ;
V_128:
F_32 ( & V_60 -> V_64 ) ;
F_43 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_39 ( & V_54 -> V_66 . V_57 ) )
continue;
V_54 -> V_66 . V_67 = - V_129 ;
F_2 ( & V_54 -> V_3 ) ;
F_47 ( V_54 ) ;
F_33 ( & V_60 -> V_64 ) ;
F_36 ( V_54 ) ;
goto V_128;
}
F_33 ( & V_60 -> V_64 ) ;
F_34 ( V_45 ) ;
}
static void
F_91 ( struct V_130 * V_66 )
{
struct V_53 * V_54 = F_7 ( V_66 , struct V_53 , V_66 ) ;
if ( V_66 -> V_67 < 0 ) {
F_28 ( L_20 ,
V_44 , V_54 ) ;
F_2 ( & V_54 -> V_3 ) ;
F_52 ( V_54 ) ;
if ( V_66 -> V_67 == - V_131 )
F_65 () ;
F_36 ( V_54 ) ;
}
}
static void F_92 ( struct V_95 * V_55 )
{
struct V_87 * V_87 ;
V_87 = F_7 ( V_55 , struct V_87 , V_95 ) ;
if ( V_87 -> V_60 [ 0 ] -> V_132 )
F_93 ( V_87 -> V_60 [ 0 ] -> V_132 ) ;
if ( V_87 -> V_60 [ 1 ] -> V_132 )
F_93 ( V_87 -> V_60 [ 1 ] -> V_132 ) ;
}
static int F_94 ( struct V_95 * V_55 )
{
int V_35 ;
struct V_87 * V_87 ;
struct V_80 * V_81 ;
V_87 = F_7 ( V_55 , struct V_87 , V_95 ) ;
V_81 = V_87 -> V_56 ;
V_87 -> V_60 [ 1 ] -> V_132 = F_95 ( V_81 -> V_133 ,
L_21 ,
V_81 , V_87 -> V_60 [ 1 ] ) ;
if ( F_17 ( V_87 -> V_60 [ 1 ] -> V_132 ) )
return F_29 ( V_87 -> V_60 [ 1 ] -> V_132 ) ;
V_87 -> V_60 [ 0 ] -> V_132 = F_95 ( V_81 -> V_133 ,
V_87 -> V_83 -> V_84 ,
V_81 , V_87 -> V_60 [ 0 ] ) ;
if ( F_17 ( V_87 -> V_60 [ 0 ] -> V_132 ) ) {
V_35 = F_29 ( V_87 -> V_60 [ 0 ] -> V_132 ) ;
goto V_134;
}
return 0 ;
V_134:
F_93 ( V_87 -> V_60 [ 1 ] -> V_132 ) ;
return V_35 ;
}
static void F_96 ( struct V_80 * V_81 ,
struct V_95 * V_55 )
{
struct V_45 * V_45 = F_37 ( V_81 ) ;
struct V_135 * V_136 ;
V_136 = F_97 ( V_45 ) ;
if ( V_136 ) {
if ( V_81 -> V_133 )
F_92 ( V_55 ) ;
F_98 ( V_45 ) ;
}
}
static int F_99 ( struct V_80 * V_81 ,
struct V_95 * V_55 )
{
struct V_45 * V_45 = F_37 ( V_81 ) ;
struct V_135 * V_136 ;
int V_35 = 0 ;
V_136 = F_97 ( V_45 ) ;
if ( V_136 ) {
if ( V_81 -> V_133 )
V_35 = F_94 ( V_55 ) ;
F_98 ( V_45 ) ;
}
return V_35 ;
}
static struct V_95 *
F_100 ( struct V_80 * V_81 , T_7 V_137 )
{
struct V_87 * V_87 ;
struct V_95 * V_55 ;
int V_35 = - V_22 ;
F_28 ( L_22 , V_81 ) ;
if ( ! F_101 ( V_138 ) )
return F_15 ( V_35 ) ;
if ( ! ( V_87 = F_80 ( sizeof( * V_87 ) , V_139 ) ) )
goto V_140;
V_87 -> V_56 = V_81 ;
V_35 = - V_117 ;
V_87 -> V_83 = F_102 ( V_137 ) ;
if ( ! V_87 -> V_83 ) {
F_28 ( L_23 , V_137 ) ;
goto V_141;
}
V_87 -> V_142 = F_103 ( V_87 -> V_83 , V_137 ) ;
if ( V_87 -> V_142 == 0 )
goto V_143;
V_55 = & V_87 -> V_95 ;
V_55 -> V_144 = V_145 >> 2 ;
V_55 -> V_146 = V_147 >> 2 ;
V_55 -> V_148 = & V_149 ;
V_55 -> V_150 = V_137 ;
F_25 ( & V_55 -> V_151 , 1 ) ;
F_104 ( & V_87 -> V_152 ) ;
V_87 -> V_60 [ 1 ] = F_105 ( & V_153 ,
V_154 ) ;
if ( F_17 ( V_87 -> V_60 [ 1 ] ) ) {
V_35 = F_29 ( V_87 -> V_60 [ 1 ] ) ;
goto V_143;
}
V_87 -> V_60 [ 0 ] = F_105 ( & V_155 ,
V_154 ) ;
if ( F_17 ( V_87 -> V_60 [ 0 ] ) ) {
V_35 = F_29 ( V_87 -> V_60 [ 0 ] ) ;
goto V_156;
}
V_35 = F_99 ( V_81 , V_55 ) ;
if ( V_35 )
goto V_157;
V_35 = F_106 ( V_55 ) ;
if ( V_35 )
goto V_158;
return V_55 ;
V_158:
F_96 ( V_81 , V_55 ) ;
V_157:
F_107 ( V_87 -> V_60 [ 0 ] ) ;
V_156:
F_107 ( V_87 -> V_60 [ 1 ] ) ;
V_143:
F_108 ( V_87 -> V_83 ) ;
V_141:
F_41 ( V_87 ) ;
V_140:
F_109 ( V_138 ) ;
return F_15 ( V_35 ) ;
}
static void
F_110 ( struct V_87 * V_87 )
{
F_96 ( V_87 -> V_56 , & V_87 -> V_95 ) ;
F_107 ( V_87 -> V_60 [ 0 ] ) ;
F_107 ( V_87 -> V_60 [ 1 ] ) ;
F_108 ( V_87 -> V_83 ) ;
F_41 ( V_87 ) ;
F_109 ( V_138 ) ;
}
static void
F_111 ( struct V_152 * V_152 )
{
struct V_87 * V_87 = F_7 ( V_152 , struct V_87 , V_152 ) ;
F_110 ( V_87 ) ;
}
static void
F_112 ( struct V_95 * V_55 )
{
struct V_87 * V_87 ;
F_28 ( L_24 ,
V_55 , V_55 -> V_150 ) ;
F_113 ( V_55 ) ;
V_87 = F_7 ( V_55 , struct V_87 , V_95 ) ;
F_114 ( & V_87 -> V_152 , F_111 ) ;
}
static int
F_115 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_87 * V_87 = F_7 ( V_5 -> V_94 , struct V_87 , V_95 ) ;
struct V_72 * V_73 ;
if ( V_6 -> V_10 == NULL ||
F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_6 -> V_10 -> V_23 = V_159 ;
V_5 -> V_160 = & V_161 ;
F_116 ( V_5 ) ;
V_73 = F_117 ( V_87 -> V_56 , V_5 , V_162 | V_163 ) ;
if ( ! F_17 ( V_73 ) )
F_118 ( V_73 ) ;
F_119 ( V_5 ) ;
return 1 ;
}
static void
F_120 ( struct V_1 * V_2 )
{
F_28 ( L_25 , V_44 ) ;
F_121 ( & V_2 -> V_43 ) ;
F_41 ( V_2 -> V_42 . V_20 ) ;
F_41 ( V_2 ) ;
}
static void
F_122 ( struct V_164 * V_165 )
{
struct V_1 * V_2 = F_7 ( V_165 , struct V_1 , V_166 ) ;
F_120 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_123 ( & V_2 -> V_166 , F_122 ) ;
}
static void
F_124 ( struct V_6 * V_6 )
{
F_28 ( L_26 , V_44 , V_6 ) ;
F_41 ( V_6 ) ;
}
static void
F_125 ( struct V_164 * V_165 )
{
struct V_6 * V_6 = F_7 ( V_165 , struct V_6 , V_7 . V_167 ) ;
F_124 ( V_6 ) ;
}
static void
F_126 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_87 * V_87 = F_7 ( V_5 -> V_94 , struct V_87 , V_95 ) ;
struct V_1 * V_2 = V_6 -> V_10 ;
F_127 ( V_6 -> V_10 , NULL ) ;
F_123 ( & V_5 -> V_167 , F_125 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_114 ( & V_87 -> V_152 , F_111 ) ;
}
static void
F_128 ( struct V_4 * V_5 )
{
if ( F_115 ( V_5 ) )
return;
F_126 ( V_5 ) ;
}
static struct V_4 *
F_129 ( struct V_95 * V_55 , struct V_168 * V_169 , int V_170 )
{
return F_130 ( V_55 , V_169 , V_170 ) ;
}
static struct V_4 *
F_131 ( struct V_95 * V_55 , struct V_168 * V_169 , int V_170 )
{
struct V_87 * V_87 = F_7 ( V_55 , struct V_87 , V_95 ) ;
struct V_6 * V_5 = NULL ;
int V_35 = - V_22 ;
F_28 ( L_27 ,
V_44 , F_56 ( & V_77 , V_169 -> V_61 ) ,
V_55 -> V_150 ) ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_171;
F_132 ( & V_5 -> V_7 , V_169 , V_55 , & V_172 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_173 = V_87 -> V_142 ;
V_5 -> V_91 = NULL ;
if ( V_169 -> V_174 )
V_5 -> V_91 = V_169 -> V_175 ;
F_133 ( & V_87 -> V_152 ) ;
return & V_5 -> V_7 ;
V_171:
F_28 ( L_28 , V_44 , V_35 ) ;
return F_15 ( V_35 ) ;
}
static int
F_134 ( struct V_95 * V_55 , struct V_4 * V_5 )
{
struct V_87 * V_87 = F_7 ( V_55 , struct V_87 , V_95 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_35 ;
do {
V_35 = F_70 ( V_87 , V_6 ) ;
} while ( V_35 == - V_52 );
return V_35 ;
}
static int
F_135 ( struct V_168 * V_169 , struct V_4 * V_176 , int V_170 )
{
struct V_6 * V_6 = F_7 ( V_176 , struct V_6 , V_7 ) ;
if ( F_8 ( V_8 , & V_176 -> V_9 ) )
goto V_100;
if ( F_66 ( V_32 , V_6 -> V_10 -> V_37 ) )
return 0 ;
if ( ! F_8 ( V_11 , & V_176 -> V_9 ) )
return 0 ;
V_100:
if ( V_169 -> V_175 != NULL ) {
if ( V_6 -> V_91 == NULL )
return 0 ;
return strcmp ( V_169 -> V_175 , V_6 -> V_91 ) == 0 ;
}
if ( V_6 -> V_91 != NULL )
return 0 ;
return F_44 ( V_176 -> V_90 , V_169 -> V_61 ) ;
}
static T_8 *
F_136 ( struct V_72 * V_73 , T_8 * V_12 )
{
struct V_177 * V_178 = V_73 -> V_74 ;
struct V_4 * V_5 = V_178 -> V_75 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_179 ;
T_2 V_180 = 0 ;
struct V_18 V_181 ;
struct V_182 V_183 ;
struct V_184 V_185 ;
F_28 ( L_29 , V_73 -> V_96 , V_44 ) ;
* V_12 ++ = F_137 ( V_186 ) ;
V_179 = V_12 ++ ;
F_32 ( & V_2 -> V_26 ) ;
V_178 -> V_187 = V_2 -> V_25 ++ ;
F_33 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_137 ( ( T_2 ) V_188 ) ;
* V_12 ++ = F_137 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_137 ( ( T_2 ) V_178 -> V_187 ) ;
* V_12 ++ = F_137 ( ( T_2 ) V_6 -> V_173 ) ;
V_12 = F_138 ( V_12 , & V_2 -> V_42 ) ;
* V_179 = F_137 ( ( V_12 - ( V_179 + 1 ) ) << 2 ) ;
V_183 . V_189 = F_139 ( V_178 -> V_190 ,
V_178 -> V_191 . V_165 [ 0 ] . V_189 ) ;
V_183 . V_192 = ( V_193 * ) V_12 - ( V_193 * ) V_183 . V_189 ;
F_140 ( & V_183 , & V_185 ) ;
* V_12 ++ = F_137 ( V_186 ) ;
V_181 . V_20 = ( V_193 * ) ( V_12 + 1 ) ;
V_180 = F_141 ( V_2 -> V_43 , & V_185 , & V_181 ) ;
if ( V_180 == V_194 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_180 != 0 ) {
F_67 ( L_30 , V_180 ) ;
goto V_195;
}
V_12 = F_142 ( V_12 , NULL , V_181 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_195:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_143 ( struct V_72 * V_73 )
{
struct V_4 * V_196 = V_73 -> V_74 -> V_75 ;
struct V_6 * V_6 = F_7 ( V_196 ,
struct V_6 ,
V_7 ) ;
struct V_95 * V_55 = V_196 -> V_94 ;
struct V_168 V_169 = {
. V_61 = V_196 -> V_90 ,
. V_175 = V_6 -> V_91 ,
. V_174 = ( V_6 -> V_91 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_197 ;
V_197 = F_129 ( V_55 , & V_169 , V_198 ) ;
if ( F_17 ( V_197 ) )
return F_29 ( V_197 ) ;
V_73 -> V_74 -> V_75 = V_197 ;
F_119 ( V_196 ) ;
return 0 ;
}
static int F_144 ( struct V_4 * V_5 )
{
if ( F_8 ( V_69 , & V_5 -> V_9 ) ) {
unsigned long V_31 = V_32 ;
unsigned long V_199 , V_200 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_199 = V_6 -> V_70 ;
V_200 = V_199 + V_201 * V_38 ;
if ( F_145 ( V_31 , V_199 , V_200 ) )
return 1 ;
}
return 0 ;
}
static int
F_146 ( struct V_72 * V_73 )
{
struct V_4 * V_5 = V_73 -> V_74 -> V_75 ;
int V_34 = 0 ;
if ( F_144 ( V_5 ) )
return - V_40 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_34 = F_143 ( V_73 ) ;
if ( V_34 < 0 )
goto V_100;
V_5 = V_73 -> V_74 -> V_75 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_34 = F_68 ( V_73 ) ;
V_100:
return V_34 ;
}
static int
F_147 ( struct V_72 * V_73 )
{
return - V_41 ;
}
static T_8 *
F_148 ( struct V_72 * V_73 , T_8 * V_12 )
{
struct V_4 * V_5 = V_73 -> V_74 -> V_75 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 V_202 ;
struct V_182 V_183 ;
struct V_184 V_185 ;
struct V_18 V_181 ;
T_2 V_203 , V_15 ;
T_2 V_180 ;
F_28 ( L_29 , V_73 -> V_96 , V_44 ) ;
V_203 = F_149 ( * V_12 ++ ) ;
if ( ( V_15 = F_149 ( * V_12 ++ ) ) > V_204 )
goto V_205;
if ( V_203 != V_186 )
goto V_205;
V_202 = F_137 ( V_73 -> V_74 -> V_187 ) ;
V_183 . V_189 = & V_202 ;
V_183 . V_192 = sizeof( V_202 ) ;
F_140 ( & V_183 , & V_185 ) ;
V_181 . V_20 = ( V_193 * ) V_12 ;
V_181 . V_15 = V_15 ;
V_180 = F_150 ( V_2 -> V_43 , & V_185 , & V_181 ) ;
if ( V_180 == V_194 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_180 ) {
F_28 ( L_31 ,
V_73 -> V_96 , V_44 , V_180 ) ;
goto V_205;
}
V_5 -> V_94 -> V_206 = F_151 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_28 ( L_32 ,
V_73 -> V_96 , V_44 ) ;
return V_12 + F_151 ( V_15 ) ;
V_205:
F_3 ( V_2 ) ;
F_28 ( L_33 , V_73 -> V_96 , V_44 ) ;
return NULL ;
}
static void F_152 ( T_9 V_207 , struct V_177 * V_208 ,
T_8 * V_12 , void * V_209 )
{
struct V_210 V_211 ;
F_153 ( & V_211 , & V_208 -> V_191 , V_12 ) ;
V_207 ( V_208 , & V_211 , V_209 ) ;
}
static inline int
F_154 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_207 , struct V_177 * V_208 ,
T_8 * V_12 , void * V_209 )
{
struct V_184 * V_212 = & V_208 -> V_191 ;
struct V_184 V_213 ;
T_8 * V_214 = NULL ;
struct V_18 V_181 ;
T_2 V_215 ;
T_8 * V_16 ;
struct V_182 * V_183 ;
T_2 V_180 = 0 ;
int V_216 = - V_217 ;
V_214 = V_12 ++ ;
V_215 = ( V_193 * ) V_12 - ( V_193 * ) V_212 -> V_165 [ 0 ] . V_189 ;
* V_12 ++ = F_137 ( V_208 -> V_187 ) ;
F_152 ( V_207 , V_208 , V_12 , V_209 ) ;
if ( F_155 ( V_212 , & V_213 ,
V_215 , V_212 -> V_15 - V_215 ) )
return V_216 ;
* V_214 = F_137 ( V_213 . V_15 ) ;
if ( V_212 -> V_218 || V_212 -> V_219 [ 0 ] . V_192 )
V_183 = V_212 -> V_219 ;
else
V_183 = V_212 -> V_165 ;
V_12 = V_183 -> V_189 + V_183 -> V_192 ;
V_181 . V_20 = ( V_193 * ) ( V_12 + 1 ) ;
V_180 = F_141 ( V_2 -> V_43 , & V_213 , & V_181 ) ;
V_216 = - V_217 ;
if ( V_180 == V_194 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_180 )
return V_216 ;
V_16 = F_142 ( V_12 , NULL , V_181 . V_15 ) ;
V_215 = ( V_193 * ) V_16 - ( V_193 * ) V_12 ;
V_183 -> V_192 += V_215 ;
V_212 -> V_15 += V_215 ;
return 0 ;
}
static void
F_156 ( struct V_177 * V_208 )
{
int V_220 ;
for ( V_220 = 0 ; V_220 < V_208 -> V_221 ; V_220 ++ )
F_157 ( V_208 -> V_222 [ V_220 ] ) ;
F_41 ( V_208 -> V_222 ) ;
}
static int
F_158 ( struct V_177 * V_208 )
{
struct V_184 * V_212 = & V_208 -> V_191 ;
int V_223 , V_224 , V_220 ;
if ( V_212 -> V_218 == 0 ) {
V_208 -> V_221 = 0 ;
return 0 ;
}
V_223 = V_212 -> V_225 >> V_226 ;
V_224 = ( V_212 -> V_225 + V_212 -> V_218 - 1 ) >> V_226 ;
V_208 -> V_221 = V_224 - V_223 + 1 + 1 ;
V_208 -> V_222
= F_80 ( V_208 -> V_221 * sizeof( struct V_227 * ) ,
V_21 ) ;
if ( ! V_208 -> V_222 )
goto V_100;
for ( V_220 = 0 ; V_220 < V_208 -> V_221 ; V_220 ++ ) {
V_208 -> V_222 [ V_220 ] = F_159 ( V_21 ) ;
if ( V_208 -> V_222 [ V_220 ] == NULL )
goto V_228;
}
V_208 -> V_229 = F_156 ;
return 0 ;
V_228:
V_208 -> V_221 = V_220 ;
F_156 ( V_208 ) ;
V_100:
return - V_52 ;
}
static inline int
F_160 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_9 V_207 , struct V_177 * V_208 ,
T_8 * V_12 , void * V_209 )
{
struct V_184 * V_212 = & V_208 -> V_191 ;
T_2 V_215 ;
T_2 V_180 ;
int V_216 ;
T_8 * V_230 ;
struct V_227 * * V_231 ;
int V_223 ;
int V_232 ;
struct V_182 * V_183 ;
char * V_233 ;
V_230 = V_12 ++ ;
V_215 = ( V_193 * ) V_12 - ( V_193 * ) V_212 -> V_165 [ 0 ] . V_189 ;
* V_12 ++ = F_137 ( V_208 -> V_187 ) ;
F_152 ( V_207 , V_208 , V_12 , V_209 ) ;
V_216 = F_158 ( V_208 ) ;
if ( V_216 )
return V_216 ;
V_223 = V_212 -> V_225 >> V_226 ;
V_231 = V_212 -> V_234 + V_223 ;
V_212 -> V_234 = V_208 -> V_222 ;
V_212 -> V_225 -= V_223 << V_226 ;
if ( V_212 -> V_218 || V_212 -> V_219 [ 0 ] . V_192 ) {
V_233 = F_161 ( V_208 -> V_222 [ V_208 -> V_221 - 1 ] ) ;
memcpy ( V_233 , V_212 -> V_219 [ 0 ] . V_189 , V_212 -> V_219 [ 0 ] . V_192 ) ;
V_212 -> V_219 [ 0 ] . V_189 = V_233 ;
}
V_180 = F_162 ( V_2 -> V_43 , V_215 , V_212 , V_231 ) ;
F_38 ( V_212 -> V_15 > V_212 -> V_235 ) ;
V_216 = - V_217 ;
if ( V_180 == V_194 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_180 )
return V_216 ;
* V_230 = F_137 ( V_212 -> V_15 - V_215 ) ;
if ( V_212 -> V_218 || V_212 -> V_219 [ 0 ] . V_192 )
V_183 = V_212 -> V_219 ;
else
V_183 = V_212 -> V_165 ;
V_12 = V_183 -> V_189 + V_183 -> V_192 ;
V_232 = 3 - ( ( V_212 -> V_15 - V_215 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_232 ) ;
V_183 -> V_192 += V_232 ;
V_212 -> V_15 += V_232 ;
return 0 ;
}
static int
F_163 ( struct V_72 * V_73 ,
T_9 V_207 , void * V_208 , T_8 * V_12 , void * V_209 )
{
struct V_4 * V_5 = V_73 -> V_74 -> V_75 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_216 = - V_217 ;
F_28 ( L_29 , V_73 -> V_96 , V_44 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_152 ( V_207 , V_208 , V_12 , V_209 ) ;
V_216 = 0 ;
goto V_100;
}
switch ( V_6 -> V_173 ) {
case V_236 :
F_152 ( V_207 , V_208 , V_12 , V_209 ) ;
V_216 = 0 ;
break;
case V_237 :
V_216 = F_154 ( V_5 , V_2 , V_207 , V_208 , V_12 , V_209 ) ;
break;
case V_238 :
V_216 = F_160 ( V_5 , V_2 , V_207 , V_208 , V_12 , V_209 ) ;
break;
}
V_100:
F_3 ( V_2 ) ;
F_28 ( L_34 , V_73 -> V_96 , V_44 , V_216 ) ;
return V_216 ;
}
static inline int
F_164 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_177 * V_208 , T_8 * * V_12 )
{
struct V_184 * V_239 = & V_208 -> V_240 ;
struct V_184 V_213 ;
struct V_18 V_181 ;
T_2 V_241 , V_242 ;
T_2 V_214 ;
T_2 V_180 ;
int V_216 = - V_217 ;
V_214 = F_149 ( * ( * V_12 ) ++ ) ;
if ( V_214 & 3 )
return V_216 ;
V_241 = ( V_193 * ) ( * V_12 ) - ( V_193 * ) V_239 -> V_165 [ 0 ] . V_189 ;
V_242 = V_214 + V_241 ;
if ( V_242 > V_239 -> V_15 )
return V_216 ;
if ( F_149 ( * ( * V_12 ) ++ ) != V_208 -> V_187 )
return V_216 ;
if ( F_155 ( V_239 , & V_213 , V_241 ,
V_242 - V_241 ) )
return V_216 ;
if ( F_165 ( V_239 , & V_181 , V_242 ) )
return V_216 ;
V_180 = F_150 ( V_2 -> V_43 , & V_213 , & V_181 ) ;
if ( V_180 == V_194 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_180 != V_243 )
return V_216 ;
return 0 ;
}
static inline int
F_166 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_177 * V_208 , T_8 * * V_12 )
{
struct V_184 * V_239 = & V_208 -> V_240 ;
T_2 V_215 ;
T_2 V_230 ;
T_2 V_180 ;
int V_216 = - V_217 ;
V_230 = F_149 ( * ( * V_12 ) ++ ) ;
V_215 = ( V_193 * ) ( * V_12 ) - ( V_193 * ) V_239 -> V_165 [ 0 ] . V_189 ;
if ( V_215 + V_230 > V_239 -> V_15 )
return V_216 ;
V_239 -> V_15 = V_215 + V_230 ;
V_180 = F_167 ( V_2 -> V_43 , V_215 , V_239 ) ;
if ( V_180 == V_194 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_180 != V_243 )
return V_216 ;
if ( F_149 ( * ( * V_12 ) ++ ) != V_208 -> V_187 )
return V_216 ;
return 0 ;
}
static int
F_168 ( T_10 V_244 , struct V_177 * V_208 ,
T_8 * V_12 , void * V_209 )
{
struct V_210 V_211 ;
F_169 ( & V_211 , & V_208 -> V_240 , V_12 ) ;
return V_244 ( V_208 , & V_211 , V_209 ) ;
}
static int
F_170 ( struct V_72 * V_73 ,
T_10 V_244 , void * V_208 , T_8 * V_12 , void * V_209 )
{
struct V_4 * V_5 = V_73 -> V_74 -> V_75 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_8 * V_245 = V_12 ;
struct V_182 * V_165 = ( (struct V_177 * ) V_208 ) -> V_240 . V_165 ;
int V_246 = V_165 -> V_192 ;
int V_216 = - V_217 ;
if ( V_2 -> V_23 != V_24 )
goto V_247;
switch ( V_6 -> V_173 ) {
case V_236 :
break;
case V_237 :
V_216 = F_164 ( V_5 , V_2 , V_208 , & V_12 ) ;
if ( V_216 )
goto V_100;
break;
case V_238 :
V_216 = F_166 ( V_5 , V_2 , V_208 , & V_12 ) ;
if ( V_216 )
goto V_100;
break;
}
V_5 -> V_94 -> V_146 = V_5 -> V_94 -> V_206 + ( V_12 - V_245 )
+ ( V_246 - V_165 -> V_192 ) ;
V_247:
V_216 = F_168 ( V_244 , V_208 , V_12 , V_209 ) ;
V_100:
F_3 ( V_2 ) ;
F_28 ( L_34 ,
V_73 -> V_96 , V_44 , V_216 ) ;
return V_216 ;
}
static T_11 int F_171 ( struct V_45 * V_45 )
{
return F_172 ( V_45 ) ;
}
static T_12 void F_173 ( struct V_45 * V_45 )
{
F_174 ( V_45 ) ;
}
static int T_13 F_175 ( void )
{
int V_35 = 0 ;
V_35 = F_176 ( & V_149 ) ;
if ( V_35 )
goto V_100;
V_35 = F_177 () ;
if ( V_35 )
goto V_248;
V_35 = F_178 ( & V_249 ) ;
if ( V_35 )
goto V_250;
F_61 ( & V_99 , L_35 ) ;
return 0 ;
V_250:
F_179 () ;
V_248:
F_180 ( & V_149 ) ;
V_100:
return V_35 ;
}
static void T_14 F_181 ( void )
{
F_182 ( & V_249 ) ;
F_179 () ;
F_180 ( & V_149 ) ;
F_183 () ;
}
