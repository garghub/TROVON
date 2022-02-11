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
T_2 V_31 ;
int V_32 ;
V_12 = F_13 ( V_12 , V_13 , & V_30 , sizeof( V_30 ) ) ;
if ( F_17 ( V_12 ) )
goto V_33;
if ( V_30 == 0 )
V_30 = V_34 ;
V_2 -> V_35 = V_36 + ( unsigned long ) V_30 * V_37 * 3 / 4 ;
V_12 = F_13 ( V_12 , V_13 , & V_31 , sizeof( V_31 ) ) ;
if ( F_17 ( V_12 ) )
goto V_33;
V_2 -> V_38 = V_31 ;
if ( V_2 -> V_38 == 0 ) {
V_12 = F_13 ( V_12 , V_13 , & V_32 , sizeof( V_32 ) ) ;
if ( ! F_17 ( V_12 ) )
V_12 = ( V_32 == - V_39 ) ? F_15 ( - V_39 ) :
F_15 ( - V_40 ) ;
goto V_33;
}
V_12 = F_16 ( V_12 , V_13 , & V_2 -> V_41 ) ;
if ( F_17 ( V_12 ) )
goto V_33;
V_12 = F_13 ( V_12 , V_13 , & V_29 , sizeof( V_29 ) ) ;
if ( F_17 ( V_12 ) )
goto V_33;
V_16 = ( const void * ) ( ( const char * ) V_12 + V_29 ) ;
if ( F_14 ( V_16 > V_13 || V_16 < V_12 ) ) {
V_12 = F_15 ( - V_17 ) ;
goto V_33;
}
V_32 = F_27 ( V_12 , V_29 , V_28 , & V_2 -> V_42 , V_21 ) ;
if ( V_32 < 0 ) {
V_12 = F_15 ( V_32 ) ;
goto V_33;
}
return V_16 ;
V_33:
F_28 ( L_1 , V_43 , - F_29 ( V_12 ) ) ;
return V_12 ;
}
static int F_30 ( void )
{
int V_32 ;
F_31 ( & V_44 ) ;
if ( V_45 >= 0 ) {
F_2 ( & V_46 ) ;
V_32 = V_45 ;
} else
V_32 = - V_47 ;
F_32 ( & V_44 ) ;
return V_32 ;
}
static void F_33 ( void )
{
if ( F_34 ( & V_46 , & V_44 ) ) {
V_45 = - 1 ;
F_32 ( & V_44 ) ;
}
}
static void
F_35 ( struct V_48 * V_49 )
{
if ( ! F_4 ( & V_49 -> V_3 ) )
return;
F_33 () ;
F_36 ( ! F_37 ( & V_49 -> V_50 ) ) ;
if ( V_49 -> V_2 != NULL )
F_3 ( V_49 -> V_2 ) ;
F_38 ( & V_49 -> V_51 ) ;
F_39 ( V_49 ) ;
}
static struct V_48 *
F_40 ( struct V_52 * V_53 , T_3 V_54 )
{
struct V_48 * V_55 ;
F_41 (pos, &pipe->in_downcall, list) {
if ( V_55 -> V_54 != V_54 )
continue;
F_2 ( & V_55 -> V_3 ) ;
F_28 ( L_2 , V_43 , V_55 ) ;
return V_55 ;
}
F_28 ( L_3 , V_43 ) ;
return NULL ;
}
static inline struct V_48 *
F_42 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
struct V_48 * V_56 ;
F_31 ( & V_53 -> V_57 ) ;
V_56 = F_40 ( V_53 , V_49 -> V_54 ) ;
if ( V_56 == NULL ) {
F_2 ( & V_49 -> V_3 ) ;
F_43 ( & V_49 -> V_50 , & V_53 -> V_58 ) ;
} else
V_49 = V_56 ;
F_32 ( & V_53 -> V_57 ) ;
return V_49 ;
}
static void
F_44 ( struct V_48 * V_49 )
{
F_45 ( & V_49 -> V_50 ) ;
F_46 ( & V_49 -> V_51 , V_49 -> V_59 . V_60 ) ;
F_47 ( & V_49 -> V_61 ) ;
F_48 ( & V_49 -> V_3 ) ;
}
static void
F_49 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
if ( F_37 ( & V_49 -> V_50 ) )
return;
F_31 ( & V_53 -> V_57 ) ;
if ( ! F_37 ( & V_49 -> V_50 ) )
F_44 ( V_49 ) ;
F_32 ( & V_53 -> V_57 ) ;
}
static void
F_50 ( struct V_6 * V_6 , struct V_48 * V_49 )
{
switch ( V_49 -> V_59 . V_60 ) {
case 0 :
if ( V_49 -> V_2 == NULL )
break;
F_12 ( V_62 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_49 -> V_2 ) ;
break;
case - V_39 :
F_10 ( V_62 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_63 = V_36 ;
V_6 -> V_64 = NULL ;
F_46 ( & V_49 -> V_51 , V_49 -> V_59 . V_60 ) ;
}
static void
F_51 ( struct V_65 * V_66 )
{
struct V_6 * V_6 = F_7 ( V_66 -> V_67 -> V_68 ,
struct V_6 , V_7 ) ;
struct V_48 * V_49 = V_6 -> V_64 ;
struct V_52 * V_53 = V_49 -> V_53 ;
F_31 ( & V_53 -> V_57 ) ;
F_50 ( V_6 , V_49 ) ;
F_32 ( & V_53 -> V_57 ) ;
V_66 -> V_69 = V_49 -> V_59 . V_60 ;
F_35 ( V_49 ) ;
}
static void F_52 ( struct V_48 * V_49 )
{
V_49 -> V_59 . V_20 = & V_49 -> V_54 ;
V_49 -> V_59 . V_15 = sizeof( V_49 -> V_54 ) ;
}
static void F_53 ( struct V_48 * V_49 ,
struct V_70 * V_71 ,
const char * V_72 )
{
struct V_27 * V_73 = V_49 -> V_74 -> V_73 ;
char * V_12 = V_49 -> V_75 ;
int V_15 = 0 ;
V_49 -> V_59 . V_15 = sprintf ( V_49 -> V_75 , L_4 ,
V_73 -> V_76 ,
V_49 -> V_54 ) ;
V_12 += V_49 -> V_59 . V_15 ;
if ( V_71 -> V_77 ) {
V_15 = sprintf ( V_12 , L_5 , V_71 -> V_77 ) ;
V_12 += V_15 ;
V_49 -> V_59 . V_15 += V_15 ;
}
if ( V_72 != NULL ) {
V_15 = sprintf ( V_12 , L_6 , V_72 ) ;
V_12 += V_15 ;
V_49 -> V_59 . V_15 += V_15 ;
}
if ( V_73 -> V_78 ) {
V_15 = sprintf ( V_12 , L_7 , V_73 -> V_78 ) ;
V_12 += V_15 ;
V_49 -> V_59 . V_15 += V_15 ;
}
V_15 = sprintf ( V_12 , L_8 ) ;
V_49 -> V_59 . V_15 += V_15 ;
V_49 -> V_59 . V_20 = V_49 -> V_75 ;
F_36 ( V_49 -> V_59 . V_15 > V_79 ) ;
}
static void F_54 ( struct V_48 * V_49 ,
struct V_70 * V_71 ,
const char * V_72 )
{
if ( V_45 == 0 )
F_52 ( V_49 ) ;
else
F_53 ( V_49 , V_71 , V_72 ) ;
}
static struct V_48 *
F_55 ( struct V_80 * V_80 , struct V_70 * V_71 ,
T_3 V_54 , const char * V_72 )
{
struct V_48 * V_49 ;
int V_81 ;
V_49 = F_23 ( sizeof( * V_49 ) , V_21 ) ;
if ( V_49 == NULL )
return F_15 ( - V_22 ) ;
V_81 = F_30 () ;
if ( V_81 < 0 ) {
F_39 ( V_49 ) ;
return F_15 ( V_81 ) ;
}
V_49 -> V_53 = V_80 -> V_53 [ V_81 ] ;
F_56 ( & V_49 -> V_50 ) ;
F_57 ( & V_49 -> V_51 , L_9 ) ;
F_58 ( & V_49 -> V_61 ) ;
F_25 ( & V_49 -> V_3 , 1 ) ;
V_49 -> V_54 = V_54 ;
V_49 -> V_74 = V_80 ;
F_54 ( V_49 , V_71 , V_72 ) ;
return V_49 ;
}
static struct V_48 *
F_59 ( struct V_70 * V_71 , struct V_80 * V_80 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_48 * V_82 , * V_49 ;
T_3 V_54 = V_5 -> V_83 ;
V_82 = F_55 ( V_80 , V_71 , V_54 , V_6 -> V_84 ) ;
if ( F_17 ( V_82 ) )
return V_82 ;
V_49 = F_42 ( V_82 ) ;
if ( V_49 == V_82 ) {
int V_14 = F_60 ( V_82 -> V_53 , & V_82 -> V_59 ) ;
if ( V_14 ) {
F_49 ( V_82 ) ;
V_49 = F_15 ( V_14 ) ;
}
} else
F_35 ( V_82 ) ;
return V_49 ;
}
static void F_61 ( void )
{
static unsigned long V_85 ;
unsigned long V_86 = V_36 ;
if ( F_62 ( V_86 , V_85 ) ) {
F_63 ( V_87 L_10
L_11 ) ;
V_85 = V_86 + 15 * V_37 ;
}
}
static inline int
F_64 ( struct V_65 * V_66 )
{
struct V_4 * V_5 = V_66 -> V_67 -> V_68 ;
struct V_80 * V_80 = F_7 ( V_5 -> V_88 ,
struct V_80 , V_89 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_48 * V_49 ;
struct V_52 * V_53 ;
int V_33 = 0 ;
F_28 ( L_12 ,
V_66 -> V_90 , V_43 , V_5 -> V_83 ) ;
V_49 = F_59 ( V_66 -> V_91 , V_80 , V_5 ) ;
if ( F_29 ( V_49 ) == - V_47 ) {
F_61 () ;
V_66 -> V_92 = 15 * V_37 ;
F_65 ( & V_93 , V_66 , NULL ) ;
return - V_47 ;
}
if ( F_17 ( V_49 ) ) {
V_33 = F_29 ( V_49 ) ;
goto V_94;
}
V_53 = V_49 -> V_53 ;
F_31 ( & V_53 -> V_57 ) ;
if ( V_6 -> V_64 != NULL )
F_65 ( & V_6 -> V_64 -> V_51 , V_66 , NULL ) ;
else if ( V_49 -> V_2 == NULL && V_49 -> V_59 . V_60 >= 0 ) {
V_66 -> V_92 = 0 ;
V_6 -> V_64 = V_49 ;
F_2 ( & V_49 -> V_3 ) ;
F_65 ( & V_49 -> V_51 , V_66 , F_51 ) ;
} else {
F_50 ( V_6 , V_49 ) ;
V_33 = V_49 -> V_59 . V_60 ;
}
F_32 ( & V_53 -> V_57 ) ;
F_35 ( V_49 ) ;
V_94:
F_28 ( L_13 ,
V_66 -> V_90 , V_43 , V_5 -> V_83 , V_33 ) ;
return V_33 ;
}
static inline int
F_66 ( struct V_80 * V_80 , struct V_6 * V_6 )
{
struct V_52 * V_53 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_48 * V_49 ;
F_67 ( V_95 ) ;
int V_33 = 0 ;
F_28 ( L_14 , V_43 , V_5 -> V_83 ) ;
V_96:
V_49 = F_59 ( V_80 -> V_97 , V_80 , V_5 ) ;
if ( F_29 ( V_49 ) == - V_47 ) {
V_33 = F_68 ( V_98 ,
V_45 >= 0 , 15 * V_37 ) ;
if ( V_45 < 0 ) {
F_61 () ;
V_33 = - V_40 ;
}
if ( V_33 )
goto V_94;
goto V_96;
}
if ( F_17 ( V_49 ) ) {
V_33 = F_29 ( V_49 ) ;
goto V_94;
}
V_53 = V_49 -> V_53 ;
for (; ; ) {
F_69 ( & V_49 -> V_61 , & V_95 , V_99 ) ;
F_31 ( & V_53 -> V_57 ) ;
if ( V_49 -> V_2 != NULL || V_49 -> V_59 . V_60 < 0 ) {
break;
}
F_32 ( & V_53 -> V_57 ) ;
if ( F_70 ( V_100 ) ) {
V_33 = - V_101 ;
goto V_102;
}
F_71 () ;
}
if ( V_49 -> V_2 )
F_6 ( V_5 , V_49 -> V_2 ) ;
else
V_33 = V_49 -> V_59 . V_60 ;
F_32 ( & V_53 -> V_57 ) ;
V_102:
F_72 ( & V_49 -> V_61 , & V_95 ) ;
F_35 ( V_49 ) ;
V_94:
F_28 ( L_15 ,
V_43 , V_5 -> V_83 , V_33 ) ;
return V_33 ;
}
static T_4
F_73 ( struct V_103 * V_104 , const char T_5 * V_105 , T_1 V_106 )
{
const void * V_12 , * V_13 ;
void * V_107 ;
struct V_48 * V_49 ;
struct V_52 * V_53 = F_74 ( V_104 -> V_108 -> V_109 ) -> V_53 ;
struct V_1 * V_2 ;
T_3 V_54 ;
T_4 V_33 = - V_110 ;
if ( V_106 > V_111 )
goto V_94;
V_33 = - V_22 ;
V_107 = F_75 ( V_106 , V_21 ) ;
if ( ! V_107 )
goto V_94;
V_33 = - V_17 ;
if ( F_76 ( V_107 , V_105 , V_106 ) )
goto V_33;
V_13 = ( const void * ) ( ( char * ) V_107 + V_106 ) ;
V_12 = F_13 ( V_107 , V_13 , & V_54 , sizeof( V_54 ) ) ;
if ( F_17 ( V_12 ) ) {
V_33 = F_29 ( V_12 ) ;
goto V_33;
}
V_33 = - V_22 ;
V_2 = F_22 () ;
if ( V_2 == NULL )
goto V_33;
V_33 = - V_112 ;
F_31 ( & V_53 -> V_57 ) ;
V_49 = F_40 ( V_53 , V_54 ) ;
if ( V_49 == NULL ) {
F_32 ( & V_53 -> V_57 ) ;
goto V_113;
}
F_45 ( & V_49 -> V_50 ) ;
F_32 ( & V_53 -> V_57 ) ;
V_12 = F_26 ( V_12 , V_13 , V_2 , V_49 -> V_74 -> V_73 ) ;
if ( F_17 ( V_12 ) ) {
V_33 = F_29 ( V_12 ) ;
switch ( V_33 ) {
case - V_40 :
case - V_39 :
V_49 -> V_59 . V_60 = V_33 ;
V_33 = V_106 ;
break;
case - V_17 :
case - V_22 :
case - V_114 :
case - V_115 :
V_49 -> V_59 . V_60 = - V_47 ;
break;
default:
F_63 ( V_116 L_16
L_17 , V_43 , V_33 ) ;
F_77 () ;
}
goto V_117;
}
V_49 -> V_2 = F_1 ( V_2 ) ;
V_33 = V_106 ;
V_117:
F_31 ( & V_53 -> V_57 ) ;
F_44 ( V_49 ) ;
F_32 ( & V_53 -> V_57 ) ;
F_35 ( V_49 ) ;
V_113:
F_3 ( V_2 ) ;
V_33:
F_39 ( V_107 ) ;
V_94:
F_28 ( L_18 , V_43 , V_33 ) ;
return V_33 ;
}
static int F_78 ( struct V_118 * V_118 , int V_119 )
{
int V_32 = 0 ;
F_31 ( & V_44 ) ;
if ( V_45 < 0 ) {
V_45 = V_119 ;
F_79 ( & V_93 ) ;
F_80 ( & V_98 ) ;
} else if ( V_45 != V_119 ) {
V_32 = - V_120 ;
goto V_94;
}
F_2 ( & V_46 ) ;
V_94:
F_32 ( & V_44 ) ;
return V_32 ;
}
static int F_81 ( struct V_118 * V_118 )
{
return F_78 ( V_118 , 0 ) ;
}
static int F_82 ( struct V_118 * V_118 )
{
return F_78 ( V_118 , 1 ) ;
}
static void
F_83 ( struct V_118 * V_118 )
{
struct V_52 * V_53 = F_74 ( V_118 ) -> V_53 ;
struct V_48 * V_49 ;
V_121:
F_31 ( & V_53 -> V_57 ) ;
F_41 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_37 ( & V_49 -> V_59 . V_50 ) )
continue;
V_49 -> V_59 . V_60 = - V_122 ;
F_2 ( & V_49 -> V_3 ) ;
F_44 ( V_49 ) ;
F_32 ( & V_53 -> V_57 ) ;
F_35 ( V_49 ) ;
goto V_121;
}
F_32 ( & V_53 -> V_57 ) ;
F_33 () ;
}
static void
F_84 ( struct V_123 * V_59 )
{
struct V_48 * V_49 = F_7 ( V_59 , struct V_48 , V_59 ) ;
if ( V_59 -> V_60 < 0 ) {
F_28 ( L_19 ,
V_43 , V_49 ) ;
F_2 ( & V_49 -> V_3 ) ;
F_49 ( V_49 ) ;
if ( V_59 -> V_60 == - V_124 )
F_61 () ;
F_35 ( V_49 ) ;
}
}
static void F_85 ( struct V_89 * V_74 )
{
struct V_80 * V_80 ;
V_80 = F_7 ( V_74 , struct V_80 , V_89 ) ;
if ( V_80 -> V_53 [ 0 ] -> V_125 )
F_86 ( V_80 -> V_53 [ 0 ] -> V_125 ) ;
if ( V_80 -> V_53 [ 1 ] -> V_125 )
F_86 ( V_80 -> V_53 [ 1 ] -> V_125 ) ;
}
static int F_87 ( struct V_89 * V_74 )
{
int V_33 ;
struct V_80 * V_80 ;
struct V_70 * V_71 ;
V_80 = F_7 ( V_74 , struct V_80 , V_89 ) ;
V_71 = V_80 -> V_97 ;
V_80 -> V_53 [ 1 ] -> V_125 = F_88 ( V_71 -> V_126 ,
L_20 ,
V_71 , V_80 -> V_53 [ 1 ] ) ;
if ( F_17 ( V_80 -> V_53 [ 1 ] -> V_125 ) )
return F_29 ( V_80 -> V_53 [ 1 ] -> V_125 ) ;
V_80 -> V_53 [ 0 ] -> V_125 = F_88 ( V_71 -> V_126 ,
V_80 -> V_73 -> V_76 ,
V_71 , V_80 -> V_53 [ 0 ] ) ;
if ( F_17 ( V_80 -> V_53 [ 0 ] -> V_125 ) ) {
V_33 = F_29 ( V_80 -> V_53 [ 0 ] -> V_125 ) ;
goto V_127;
}
return 0 ;
V_127:
F_86 ( V_80 -> V_53 [ 1 ] -> V_125 ) ;
return V_33 ;
}
static void F_89 ( struct V_70 * V_71 ,
struct V_89 * V_74 )
{
struct V_128 * V_128 = F_90 ( V_71 ) ;
struct V_129 * V_130 ;
V_130 = F_91 ( V_128 ) ;
if ( V_130 ) {
if ( V_71 -> V_126 )
F_85 ( V_74 ) ;
F_92 ( V_128 ) ;
}
}
static int F_93 ( struct V_70 * V_71 ,
struct V_89 * V_74 )
{
struct V_128 * V_128 = F_90 ( V_71 ) ;
struct V_129 * V_130 ;
int V_33 = 0 ;
V_130 = F_91 ( V_128 ) ;
if ( V_130 ) {
if ( V_71 -> V_126 )
V_33 = F_87 ( V_74 ) ;
F_92 ( V_128 ) ;
}
return V_33 ;
}
static struct V_89 *
F_94 ( struct V_70 * V_71 , T_6 V_131 )
{
struct V_80 * V_80 ;
struct V_89 * V_74 ;
int V_33 = - V_22 ;
F_28 ( L_21 , V_71 ) ;
if ( ! F_95 ( V_132 ) )
return F_15 ( V_33 ) ;
if ( ! ( V_80 = F_75 ( sizeof( * V_80 ) , V_133 ) ) )
goto V_134;
V_80 -> V_97 = V_71 ;
V_33 = - V_114 ;
V_80 -> V_73 = F_96 ( V_131 ) ;
if ( ! V_80 -> V_73 ) {
F_63 ( V_87 L_22 ,
V_43 , V_131 ) ;
goto V_135;
}
V_80 -> V_136 = F_97 ( V_80 -> V_73 , V_131 ) ;
if ( V_80 -> V_136 == 0 )
goto V_137;
V_74 = & V_80 -> V_89 ;
V_74 -> V_138 = V_139 >> 2 ;
V_74 -> V_140 = V_141 >> 2 ;
V_74 -> V_142 = & V_143 ;
V_74 -> V_144 = V_131 ;
F_25 ( & V_74 -> V_145 , 1 ) ;
F_98 ( & V_80 -> V_146 ) ;
V_80 -> V_53 [ 1 ] = F_99 ( & V_147 ,
V_148 ) ;
if ( F_17 ( V_80 -> V_53 [ 1 ] ) ) {
V_33 = F_29 ( V_80 -> V_53 [ 1 ] ) ;
goto V_137;
}
V_80 -> V_53 [ 0 ] = F_99 ( & V_149 ,
V_148 ) ;
if ( F_17 ( V_80 -> V_53 [ 0 ] ) ) {
V_33 = F_29 ( V_80 -> V_53 [ 0 ] ) ;
goto V_150;
}
V_33 = F_93 ( V_71 , V_74 ) ;
if ( V_33 )
goto V_151;
V_33 = F_100 ( V_74 ) ;
if ( V_33 )
goto V_152;
return V_74 ;
V_152:
F_89 ( V_71 , V_74 ) ;
V_151:
F_101 ( V_80 -> V_53 [ 0 ] ) ;
V_150:
F_101 ( V_80 -> V_53 [ 1 ] ) ;
V_137:
F_102 ( V_80 -> V_73 ) ;
V_135:
F_39 ( V_80 ) ;
V_134:
F_103 ( V_132 ) ;
return F_15 ( V_33 ) ;
}
static void
F_104 ( struct V_80 * V_80 )
{
F_89 ( V_80 -> V_97 , & V_80 -> V_89 ) ;
F_101 ( V_80 -> V_53 [ 0 ] ) ;
F_101 ( V_80 -> V_53 [ 1 ] ) ;
F_102 ( V_80 -> V_73 ) ;
F_39 ( V_80 ) ;
F_103 ( V_132 ) ;
}
static void
F_105 ( struct V_146 * V_146 )
{
struct V_80 * V_80 = F_7 ( V_146 , struct V_80 , V_146 ) ;
F_104 ( V_80 ) ;
}
static void
F_106 ( struct V_89 * V_74 )
{
struct V_80 * V_80 ;
F_28 ( L_23 ,
V_74 , V_74 -> V_144 ) ;
F_107 ( V_74 ) ;
V_80 = F_7 ( V_74 , struct V_80 , V_89 ) ;
F_108 ( & V_80 -> V_146 , F_105 ) ;
}
static int
F_109 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_80 * V_80 = F_7 ( V_5 -> V_88 , struct V_80 , V_89 ) ;
struct V_65 * V_66 ;
if ( V_6 -> V_10 == NULL ||
F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_6 -> V_10 -> V_23 = V_153 ;
V_5 -> V_154 = & V_155 ;
F_110 ( V_5 ) ;
V_66 = F_111 ( V_80 -> V_97 , V_5 , V_156 | V_157 ) ;
if ( ! F_17 ( V_66 ) )
F_112 ( V_66 ) ;
F_113 ( V_5 ) ;
return 1 ;
}
static void
F_114 ( struct V_1 * V_2 )
{
F_28 ( L_24 , V_43 ) ;
F_115 ( & V_2 -> V_42 ) ;
F_39 ( V_2 -> V_41 . V_20 ) ;
F_39 ( V_2 ) ;
}
static void
F_116 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_7 ( V_159 , struct V_1 , V_160 ) ;
F_114 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_117 ( & V_2 -> V_160 , F_116 ) ;
}
static void
F_118 ( struct V_6 * V_6 )
{
F_28 ( L_25 , V_43 , V_6 ) ;
F_39 ( V_6 ) ;
}
static void
F_119 ( struct V_158 * V_159 )
{
struct V_6 * V_6 = F_7 ( V_159 , struct V_6 , V_7 . V_161 ) ;
F_118 ( V_6 ) ;
}
static void
F_120 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_80 * V_80 = F_7 ( V_5 -> V_88 , struct V_80 , V_89 ) ;
struct V_1 * V_2 = V_6 -> V_10 ;
F_121 ( V_6 -> V_10 , NULL ) ;
F_117 ( & V_5 -> V_161 , F_119 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_108 ( & V_80 -> V_146 , F_105 ) ;
}
static void
F_122 ( struct V_4 * V_5 )
{
if ( F_109 ( V_5 ) )
return;
F_120 ( V_5 ) ;
}
static struct V_4 *
F_123 ( struct V_89 * V_74 , struct V_162 * V_163 , int V_164 )
{
return F_124 ( V_74 , V_163 , V_164 ) ;
}
static struct V_4 *
F_125 ( struct V_89 * V_74 , struct V_162 * V_163 , int V_164 )
{
struct V_80 * V_80 = F_7 ( V_74 , struct V_80 , V_89 ) ;
struct V_6 * V_5 = NULL ;
int V_33 = - V_22 ;
F_28 ( L_26 ,
V_43 , V_163 -> V_54 , V_74 -> V_144 ) ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_165;
F_126 ( & V_5 -> V_7 , V_163 , V_74 , & V_166 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_167 = V_80 -> V_136 ;
V_5 -> V_84 = NULL ;
if ( V_163 -> V_168 )
V_5 -> V_84 = V_163 -> V_169 ;
F_127 ( & V_80 -> V_146 ) ;
return & V_5 -> V_7 ;
V_165:
F_28 ( L_27 , V_43 , V_33 ) ;
return F_15 ( V_33 ) ;
}
static int
F_128 ( struct V_89 * V_74 , struct V_4 * V_5 )
{
struct V_80 * V_80 = F_7 ( V_74 , struct V_80 , V_89 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_33 ;
do {
V_33 = F_66 ( V_80 , V_6 ) ;
} while ( V_33 == - V_47 );
return V_33 ;
}
static int
F_129 ( struct V_162 * V_163 , struct V_4 * V_170 , int V_164 )
{
struct V_6 * V_6 = F_7 ( V_170 , struct V_6 , V_7 ) ;
if ( F_8 ( V_8 , & V_170 -> V_9 ) )
goto V_94;
if ( F_62 ( V_36 , V_6 -> V_10 -> V_35 ) )
return 0 ;
if ( ! F_8 ( V_11 , & V_170 -> V_9 ) )
return 0 ;
V_94:
if ( V_163 -> V_169 != NULL ) {
if ( V_6 -> V_84 == NULL )
return 0 ;
return strcmp ( V_163 -> V_169 , V_6 -> V_84 ) == 0 ;
}
if ( V_6 -> V_84 != NULL )
return 0 ;
return V_170 -> V_83 == V_163 -> V_54 ;
}
static T_7 *
F_130 ( struct V_65 * V_66 , T_7 * V_12 )
{
struct V_171 * V_172 = V_66 -> V_67 ;
struct V_4 * V_5 = V_172 -> V_68 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_7 * V_173 ;
T_2 V_174 = 0 ;
struct V_18 V_175 ;
struct V_176 V_177 ;
struct V_178 V_179 ;
F_28 ( L_28 , V_66 -> V_90 , V_43 ) ;
* V_12 ++ = F_131 ( V_180 ) ;
V_173 = V_12 ++ ;
F_31 ( & V_2 -> V_26 ) ;
V_172 -> V_181 = V_2 -> V_25 ++ ;
F_32 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_131 ( ( T_2 ) V_182 ) ;
* V_12 ++ = F_131 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_131 ( ( T_2 ) V_172 -> V_181 ) ;
* V_12 ++ = F_131 ( ( T_2 ) V_6 -> V_167 ) ;
V_12 = F_132 ( V_12 , & V_2 -> V_41 ) ;
* V_173 = F_131 ( ( V_12 - ( V_173 + 1 ) ) << 2 ) ;
V_177 . V_183 = F_133 ( V_66 -> V_184 ,
V_172 -> V_185 . V_159 [ 0 ] . V_183 ) ;
V_177 . V_186 = ( V_187 * ) V_12 - ( V_187 * ) V_177 . V_183 ;
F_134 ( & V_177 , & V_179 ) ;
* V_12 ++ = F_131 ( V_180 ) ;
V_175 . V_20 = ( V_187 * ) ( V_12 + 1 ) ;
V_174 = F_135 ( V_2 -> V_42 , & V_179 , & V_175 ) ;
if ( V_174 == V_188 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_174 != 0 ) {
F_63 ( L_29 , V_174 ) ;
goto V_189;
}
V_12 = F_136 ( V_12 , NULL , V_175 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_189:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_137 ( struct V_65 * V_66 )
{
struct V_4 * V_190 = V_66 -> V_67 -> V_68 ;
struct V_6 * V_6 = F_7 ( V_190 ,
struct V_6 ,
V_7 ) ;
struct V_89 * V_74 = V_190 -> V_88 ;
struct V_162 V_163 = {
. V_54 = V_190 -> V_83 ,
. V_169 = V_6 -> V_84 ,
. V_168 = ( V_6 -> V_84 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_191 ;
V_191 = F_123 ( V_74 , & V_163 , V_192 ) ;
if ( F_17 ( V_191 ) )
return F_29 ( V_191 ) ;
V_66 -> V_67 -> V_68 = V_191 ;
F_113 ( V_190 ) ;
return 0 ;
}
static int F_138 ( struct V_4 * V_5 )
{
if ( F_8 ( V_62 , & V_5 -> V_9 ) ) {
unsigned long V_86 = V_36 ;
unsigned long V_193 , V_194 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_193 = V_6 -> V_63 ;
V_194 = V_193 + V_195 * V_37 ;
if ( F_139 ( V_86 , V_193 , V_194 ) )
return 1 ;
}
return 0 ;
}
static int
F_140 ( struct V_65 * V_66 )
{
struct V_4 * V_5 = V_66 -> V_67 -> V_68 ;
int V_32 = 0 ;
if ( F_138 ( V_5 ) )
return - V_39 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_32 = F_137 ( V_66 ) ;
if ( V_32 < 0 )
goto V_94;
V_5 = V_66 -> V_67 -> V_68 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_32 = F_64 ( V_66 ) ;
V_94:
return V_32 ;
}
static int
F_141 ( struct V_65 * V_66 )
{
return - V_40 ;
}
static T_7 *
F_142 ( struct V_65 * V_66 , T_7 * V_12 )
{
struct V_4 * V_5 = V_66 -> V_67 -> V_68 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_7 V_196 ;
struct V_176 V_177 ;
struct V_178 V_179 ;
struct V_18 V_175 ;
T_2 V_197 , V_15 ;
T_2 V_174 ;
F_28 ( L_28 , V_66 -> V_90 , V_43 ) ;
V_197 = F_143 ( * V_12 ++ ) ;
if ( ( V_15 = F_143 ( * V_12 ++ ) ) > V_198 )
goto V_199;
if ( V_197 != V_180 )
goto V_199;
V_196 = F_131 ( V_66 -> V_67 -> V_181 ) ;
V_177 . V_183 = & V_196 ;
V_177 . V_186 = sizeof( V_196 ) ;
F_134 ( & V_177 , & V_179 ) ;
V_175 . V_20 = ( V_187 * ) V_12 ;
V_175 . V_15 = V_15 ;
V_174 = F_144 ( V_2 -> V_42 , & V_179 , & V_175 ) ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_174 ) {
F_28 ( L_30 ,
V_66 -> V_90 , V_43 , V_174 ) ;
goto V_199;
}
V_5 -> V_88 -> V_200 = F_145 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_28 ( L_31 ,
V_66 -> V_90 , V_43 ) ;
return V_12 + F_145 ( V_15 ) ;
V_199:
F_3 ( V_2 ) ;
F_28 ( L_32 , V_66 -> V_90 , V_43 ) ;
return NULL ;
}
static void F_146 ( T_8 V_201 , struct V_171 * V_202 ,
T_7 * V_12 , void * V_203 )
{
struct V_204 V_205 ;
F_147 ( & V_205 , & V_202 -> V_185 , V_12 ) ;
V_201 ( V_202 , & V_205 , V_203 ) ;
}
static inline int
F_148 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_8 V_201 , struct V_171 * V_202 ,
T_7 * V_12 , void * V_203 )
{
struct V_178 * V_206 = & V_202 -> V_185 ;
struct V_178 V_207 ;
T_7 * V_208 = NULL ;
struct V_18 V_175 ;
T_2 V_209 ;
T_7 * V_16 ;
struct V_176 * V_177 ;
T_2 V_174 = 0 ;
int V_210 = - V_211 ;
V_208 = V_12 ++ ;
V_209 = ( V_187 * ) V_12 - ( V_187 * ) V_206 -> V_159 [ 0 ] . V_183 ;
* V_12 ++ = F_131 ( V_202 -> V_181 ) ;
F_146 ( V_201 , V_202 , V_12 , V_203 ) ;
if ( F_149 ( V_206 , & V_207 ,
V_209 , V_206 -> V_15 - V_209 ) )
return V_210 ;
* V_208 = F_131 ( V_207 . V_15 ) ;
if ( V_206 -> V_212 || V_206 -> V_213 [ 0 ] . V_186 )
V_177 = V_206 -> V_213 ;
else
V_177 = V_206 -> V_159 ;
V_12 = V_177 -> V_183 + V_177 -> V_186 ;
V_175 . V_20 = ( V_187 * ) ( V_12 + 1 ) ;
V_174 = F_135 ( V_2 -> V_42 , & V_207 , & V_175 ) ;
V_210 = - V_211 ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_174 )
return V_210 ;
V_16 = F_136 ( V_12 , NULL , V_175 . V_15 ) ;
V_209 = ( V_187 * ) V_16 - ( V_187 * ) V_12 ;
V_177 -> V_186 += V_209 ;
V_206 -> V_15 += V_209 ;
return 0 ;
}
static void
F_150 ( struct V_171 * V_202 )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < V_202 -> V_215 ; V_214 ++ )
F_151 ( V_202 -> V_216 [ V_214 ] ) ;
F_39 ( V_202 -> V_216 ) ;
}
static int
F_152 ( struct V_171 * V_202 )
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
= F_75 ( V_202 -> V_215 * sizeof( struct V_221 * ) ,
V_21 ) ;
if ( ! V_202 -> V_216 )
goto V_94;
for ( V_214 = 0 ; V_214 < V_202 -> V_215 ; V_214 ++ ) {
V_202 -> V_216 [ V_214 ] = F_153 ( V_21 ) ;
if ( V_202 -> V_216 [ V_214 ] == NULL )
goto V_222;
}
V_202 -> V_223 = F_150 ;
return 0 ;
V_222:
V_202 -> V_215 = V_214 ;
F_150 ( V_202 ) ;
V_94:
return - V_47 ;
}
static inline int
F_154 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_8 V_201 , struct V_171 * V_202 ,
T_7 * V_12 , void * V_203 )
{
struct V_178 * V_206 = & V_202 -> V_185 ;
T_2 V_209 ;
T_2 V_174 ;
int V_210 ;
T_7 * V_224 ;
struct V_221 * * V_225 ;
int V_217 ;
int V_226 ;
struct V_176 * V_177 ;
char * V_227 ;
V_224 = V_12 ++ ;
V_209 = ( V_187 * ) V_12 - ( V_187 * ) V_206 -> V_159 [ 0 ] . V_183 ;
* V_12 ++ = F_131 ( V_202 -> V_181 ) ;
F_146 ( V_201 , V_202 , V_12 , V_203 ) ;
V_210 = F_152 ( V_202 ) ;
if ( V_210 )
return V_210 ;
V_217 = V_206 -> V_219 >> V_220 ;
V_225 = V_206 -> V_228 + V_217 ;
V_206 -> V_228 = V_202 -> V_216 ;
V_206 -> V_219 -= V_217 << V_220 ;
if ( V_206 -> V_212 || V_206 -> V_213 [ 0 ] . V_186 ) {
V_227 = F_155 ( V_202 -> V_216 [ V_202 -> V_215 - 1 ] ) ;
memcpy ( V_227 , V_206 -> V_213 [ 0 ] . V_183 , V_206 -> V_213 [ 0 ] . V_186 ) ;
V_206 -> V_213 [ 0 ] . V_183 = V_227 ;
}
V_174 = F_156 ( V_2 -> V_42 , V_209 , V_206 , V_225 ) ;
F_36 ( V_206 -> V_15 > V_206 -> V_229 ) ;
V_210 = - V_211 ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_174 )
return V_210 ;
* V_224 = F_131 ( V_206 -> V_15 - V_209 ) ;
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
F_157 ( struct V_65 * V_66 ,
T_8 V_201 , void * V_202 , T_7 * V_12 , void * V_203 )
{
struct V_4 * V_5 = V_66 -> V_67 -> V_68 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_210 = - V_211 ;
F_28 ( L_28 , V_66 -> V_90 , V_43 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_146 ( V_201 , V_202 , V_12 , V_203 ) ;
V_210 = 0 ;
goto V_94;
}
switch ( V_6 -> V_167 ) {
case V_230 :
F_146 ( V_201 , V_202 , V_12 , V_203 ) ;
V_210 = 0 ;
break;
case V_231 :
V_210 = F_148 ( V_5 , V_2 , V_201 , V_202 , V_12 , V_203 ) ;
break;
case V_232 :
V_210 = F_154 ( V_5 , V_2 , V_201 , V_202 , V_12 , V_203 ) ;
break;
}
V_94:
F_3 ( V_2 ) ;
F_28 ( L_33 , V_66 -> V_90 , V_43 , V_210 ) ;
return V_210 ;
}
static inline int
F_158 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_171 * V_202 , T_7 * * V_12 )
{
struct V_178 * V_233 = & V_202 -> V_234 ;
struct V_178 V_207 ;
struct V_18 V_175 ;
T_2 V_235 , V_236 ;
T_2 V_208 ;
T_2 V_174 ;
int V_210 = - V_211 ;
V_208 = F_143 ( * ( * V_12 ) ++ ) ;
if ( V_208 & 3 )
return V_210 ;
V_235 = ( V_187 * ) ( * V_12 ) - ( V_187 * ) V_233 -> V_159 [ 0 ] . V_183 ;
V_236 = V_208 + V_235 ;
if ( V_236 > V_233 -> V_15 )
return V_210 ;
if ( F_143 ( * ( * V_12 ) ++ ) != V_202 -> V_181 )
return V_210 ;
if ( F_149 ( V_233 , & V_207 , V_235 ,
V_236 - V_235 ) )
return V_210 ;
if ( F_159 ( V_233 , & V_175 , V_236 ) )
return V_210 ;
V_174 = F_144 ( V_2 -> V_42 , & V_207 , & V_175 ) ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_174 != V_237 )
return V_210 ;
return 0 ;
}
static inline int
F_160 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_171 * V_202 , T_7 * * V_12 )
{
struct V_178 * V_233 = & V_202 -> V_234 ;
T_2 V_209 ;
T_2 V_224 ;
T_2 V_174 ;
int V_210 = - V_211 ;
V_224 = F_143 ( * ( * V_12 ) ++ ) ;
V_209 = ( V_187 * ) ( * V_12 ) - ( V_187 * ) V_233 -> V_159 [ 0 ] . V_183 ;
if ( V_209 + V_224 > V_233 -> V_15 )
return V_210 ;
V_233 -> V_15 = V_209 + V_224 ;
V_174 = F_161 ( V_2 -> V_42 , V_209 , V_233 ) ;
if ( V_174 == V_188 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_174 != V_237 )
return V_210 ;
if ( F_143 ( * ( * V_12 ) ++ ) != V_202 -> V_181 )
return V_210 ;
return 0 ;
}
static int
F_162 ( T_9 V_238 , struct V_171 * V_202 ,
T_7 * V_12 , void * V_203 )
{
struct V_204 V_205 ;
F_163 ( & V_205 , & V_202 -> V_234 , V_12 ) ;
return V_238 ( V_202 , & V_205 , V_203 ) ;
}
static int
F_164 ( struct V_65 * V_66 ,
T_9 V_238 , void * V_202 , T_7 * V_12 , void * V_203 )
{
struct V_4 * V_5 = V_66 -> V_67 -> V_68 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_7 * V_239 = V_12 ;
struct V_176 * V_159 = ( (struct V_171 * ) V_202 ) -> V_234 . V_159 ;
int V_240 = V_159 -> V_186 ;
int V_210 = - V_211 ;
if ( V_2 -> V_23 != V_24 )
goto V_241;
switch ( V_6 -> V_167 ) {
case V_230 :
break;
case V_231 :
V_210 = F_158 ( V_5 , V_2 , V_202 , & V_12 ) ;
if ( V_210 )
goto V_94;
break;
case V_232 :
V_210 = F_160 ( V_5 , V_2 , V_202 , & V_12 ) ;
if ( V_210 )
goto V_94;
break;
}
V_5 -> V_88 -> V_140 = V_5 -> V_88 -> V_200 + ( V_12 - V_239 )
+ ( V_240 - V_159 -> V_186 ) ;
V_241:
V_210 = F_162 ( V_238 , V_202 , V_12 , V_203 ) ;
V_94:
F_3 ( V_2 ) ;
F_28 ( L_33 ,
V_66 -> V_90 , V_43 , V_210 ) ;
return V_210 ;
}
static T_10 int F_165 ( struct V_128 * V_128 )
{
return F_166 ( V_128 ) ;
}
static T_11 void F_167 ( struct V_128 * V_128 )
{
F_168 ( V_128 ) ;
}
static int T_12 F_169 ( void )
{
int V_33 = 0 ;
V_33 = F_170 ( & V_143 ) ;
if ( V_33 )
goto V_94;
V_33 = F_171 () ;
if ( V_33 )
goto V_242;
V_33 = F_172 ( & V_243 ) ;
if ( V_33 )
goto V_244;
F_57 ( & V_93 , L_34 ) ;
return 0 ;
V_244:
F_173 () ;
V_242:
F_174 ( & V_143 ) ;
V_94:
return V_33 ;
}
static void T_13 F_175 ( void )
{
F_176 ( & V_243 ) ;
F_173 () ;
F_174 ( & V_143 ) ;
F_177 () ;
}
