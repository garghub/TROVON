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
F_43 ( struct V_60 * V_61 , T_3 V_62 , const struct V_63 * V_57 )
{
struct V_55 * V_64 ;
F_44 (pos, &pipe->in_downcall, list) {
if ( ! F_45 ( V_64 -> V_62 , V_62 ) )
continue;
if ( V_57 && V_64 -> V_57 -> V_65 != V_57 -> V_65 )
continue;
F_2 ( & V_64 -> V_3 ) ;
F_29 ( L_3 , V_46 , V_64 ) ;
return V_64 ;
}
F_29 ( L_4 , V_46 ) ;
return NULL ;
}
static inline struct V_55 *
F_46 ( struct V_55 * V_56 )
{
struct V_60 * V_61 = V_56 -> V_61 ;
struct V_55 * V_66 ;
F_33 ( & V_61 -> V_67 ) ;
V_66 = F_43 ( V_61 , V_56 -> V_62 , V_56 -> V_57 ) ;
if ( V_66 == NULL ) {
F_2 ( & V_56 -> V_3 ) ;
F_47 ( & V_56 -> V_58 , & V_61 -> V_68 ) ;
} else
V_56 = V_66 ;
F_34 ( & V_61 -> V_67 ) ;
return V_56 ;
}
static void
F_48 ( struct V_55 * V_56 )
{
F_49 ( & V_56 -> V_58 ) ;
F_50 ( & V_56 -> V_59 , V_56 -> V_69 . V_70 ) ;
F_51 ( & V_56 -> V_71 ) ;
F_52 ( & V_56 -> V_3 ) ;
}
static void
F_53 ( struct V_55 * V_56 )
{
struct V_60 * V_61 = V_56 -> V_61 ;
if ( F_39 ( & V_56 -> V_58 ) )
return;
F_33 ( & V_61 -> V_67 ) ;
if ( ! F_39 ( & V_56 -> V_58 ) )
F_48 ( V_56 ) ;
F_34 ( & V_61 -> V_67 ) ;
}
static void
F_54 ( struct V_6 * V_6 , struct V_55 * V_56 )
{
switch ( V_56 -> V_69 . V_70 ) {
case 0 :
if ( V_56 -> V_2 == NULL )
break;
F_12 ( V_72 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_56 -> V_2 ) ;
break;
case - V_40 :
F_10 ( V_72 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_73 = V_32 ;
V_6 -> V_74 = NULL ;
F_50 ( & V_56 -> V_59 , V_56 -> V_69 . V_70 ) ;
}
static void
F_55 ( struct V_75 * V_76 )
{
struct V_6 * V_6 = F_7 ( V_76 -> V_77 -> V_78 ,
struct V_6 , V_7 ) ;
struct V_55 * V_56 = V_6 -> V_74 ;
struct V_60 * V_61 = V_56 -> V_61 ;
F_33 ( & V_61 -> V_67 ) ;
F_54 ( V_6 , V_56 ) ;
F_34 ( & V_61 -> V_67 ) ;
V_76 -> V_79 = V_56 -> V_69 . V_70 ;
F_37 ( V_56 ) ;
}
static void F_56 ( struct V_55 * V_56 )
{
T_4 V_62 = F_57 ( & V_80 , V_56 -> V_62 ) ;
memcpy ( V_56 -> V_81 , & V_62 , sizeof( V_62 ) ) ;
V_56 -> V_69 . V_20 = V_56 -> V_81 ;
V_56 -> V_69 . V_15 = sizeof( V_62 ) ;
F_58 ( sizeof( V_62 ) > sizeof( V_56 -> V_81 ) ) ;
}
static int F_59 ( struct V_55 * V_56 ,
const char * V_82 ,
const char * V_83 )
{
struct V_27 * V_84 = V_56 -> V_57 -> V_84 ;
char * V_12 = V_56 -> V_81 ;
T_1 V_85 = sizeof( V_56 -> V_81 ) ;
int V_15 ;
V_15 = F_60 ( V_12 , V_85 , L_5 , V_84 -> V_86 ,
F_57 ( & V_80 , V_56 -> V_62 ) ) ;
V_85 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_69 . V_15 = V_15 ;
if ( V_83 ) {
V_15 = F_60 ( V_12 , V_85 , L_6 , V_83 ) ;
V_85 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_69 . V_15 += V_15 ;
}
if ( V_82 != NULL ) {
V_15 = F_60 ( V_12 , V_85 , L_7 , V_82 ) ;
V_85 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_69 . V_15 += V_15 ;
}
if ( V_84 -> V_87 ) {
V_15 = F_60 ( V_12 , V_85 , L_8 ,
V_84 -> V_87 ) ;
V_85 -= V_15 ;
V_12 += V_15 ;
V_56 -> V_69 . V_15 += V_15 ;
}
V_15 = F_60 ( V_12 , V_85 , L_9 ) ;
if ( V_15 == 0 )
goto V_88;
V_56 -> V_69 . V_15 += V_15 ;
V_56 -> V_69 . V_20 = V_56 -> V_81 ;
return 0 ;
V_88:
F_61 ( 1 ) ;
return - V_22 ;
}
static struct V_55 *
F_62 ( struct V_63 * V_63 ,
T_3 V_62 , const char * V_82 )
{
struct V_55 * V_56 ;
int V_89 ;
int V_35 = - V_22 ;
V_56 = F_24 ( sizeof( * V_56 ) , V_21 ) ;
if ( V_56 == NULL )
goto V_35;
V_89 = F_31 ( V_63 -> V_47 ) ;
V_35 = V_89 ;
if ( V_35 < 0 )
goto V_90;
V_56 -> V_61 = V_63 -> V_91 [ V_89 ] -> V_61 ;
F_63 ( & V_56 -> V_58 ) ;
F_64 ( & V_56 -> V_59 , L_10 ) ;
F_65 ( & V_56 -> V_71 ) ;
F_26 ( & V_56 -> V_3 , 1 ) ;
V_56 -> V_62 = V_62 ;
V_56 -> V_57 = V_63 ;
switch ( V_89 ) {
case 0 :
F_56 ( V_56 ) ;
break;
default:
V_35 = F_59 ( V_56 , V_82 , V_63 -> V_83 ) ;
if ( V_35 )
goto V_92;
} ;
F_66 ( & V_63 -> V_93 ) ;
return V_56 ;
V_92:
F_35 ( V_63 -> V_47 ) ;
V_90:
F_42 ( V_56 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static struct V_55 *
F_67 ( struct V_63 * V_63 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_55 * V_94 , * V_56 ;
T_3 V_62 = V_5 -> V_95 ;
V_94 = F_62 ( V_63 , V_62 , V_6 -> V_96 ) ;
if ( F_17 ( V_94 ) )
return V_94 ;
V_56 = F_46 ( V_94 ) ;
if ( V_56 == V_94 ) {
int V_14 = F_68 ( V_94 -> V_61 , & V_94 -> V_69 ) ;
if ( V_14 ) {
F_53 ( V_94 ) ;
V_56 = F_15 ( V_14 ) ;
}
} else
F_37 ( V_94 ) ;
return V_56 ;
}
static void F_69 ( void )
{
F_29 ( L_11 ) ;
}
static inline int
F_70 ( struct V_75 * V_76 )
{
struct V_4 * V_5 = V_76 -> V_77 -> V_78 ;
struct V_63 * V_63 = F_7 ( V_5 -> V_97 ,
struct V_63 , V_98 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_55 * V_56 ;
struct V_60 * V_61 ;
int V_35 = 0 ;
F_29 ( L_12 ,
V_76 -> V_99 , V_46 , F_57 ( & V_80 , V_5 -> V_95 ) ) ;
V_56 = F_67 ( V_63 , V_5 ) ;
if ( F_30 ( V_56 ) == - V_54 ) {
F_69 () ;
V_76 -> V_100 = 15 * V_38 ;
F_71 ( & V_101 , V_76 , NULL ) ;
return - V_54 ;
}
if ( F_17 ( V_56 ) ) {
V_35 = F_30 ( V_56 ) ;
goto V_102;
}
V_61 = V_56 -> V_61 ;
F_33 ( & V_61 -> V_67 ) ;
if ( V_6 -> V_74 != NULL )
F_71 ( & V_6 -> V_74 -> V_59 , V_76 , NULL ) ;
else if ( V_56 -> V_2 == NULL && V_56 -> V_69 . V_70 >= 0 ) {
V_76 -> V_100 = 0 ;
V_6 -> V_74 = V_56 ;
F_2 ( & V_56 -> V_3 ) ;
F_71 ( & V_56 -> V_59 , V_76 , F_55 ) ;
} else {
F_54 ( V_6 , V_56 ) ;
V_35 = V_56 -> V_69 . V_70 ;
}
F_34 ( & V_61 -> V_67 ) ;
F_37 ( V_56 ) ;
V_102:
F_29 ( L_13 ,
V_76 -> V_99 , V_46 ,
F_57 ( & V_80 , V_5 -> V_95 ) , V_35 ) ;
return V_35 ;
}
static inline int
F_72 ( struct V_63 * V_63 , struct V_6 * V_6 )
{
struct V_47 * V_47 = V_63 -> V_47 ;
struct V_48 * V_49 = F_32 ( V_47 , V_50 ) ;
struct V_60 * V_61 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_55 * V_56 ;
F_73 ( V_103 ) ;
int V_35 ;
F_29 ( L_14 ,
V_46 , F_57 ( & V_80 , V_5 -> V_95 ) ) ;
V_104:
V_35 = 0 ;
if ( ! F_74 ( V_47 ) ) {
F_69 () ;
return - V_41 ;
}
V_56 = F_67 ( V_63 , V_5 ) ;
if ( F_30 ( V_56 ) == - V_54 ) {
V_35 = F_75 ( V_105 ,
V_49 -> V_52 >= 0 , 15 * V_38 ) ;
if ( V_49 -> V_52 < 0 ) {
F_69 () ;
V_35 = - V_41 ;
}
if ( V_35 < 0 )
goto V_102;
goto V_104;
}
if ( F_17 ( V_56 ) ) {
V_35 = F_30 ( V_56 ) ;
goto V_102;
}
V_61 = V_56 -> V_61 ;
for (; ; ) {
F_76 ( & V_56 -> V_71 , & V_103 , V_106 ) ;
F_33 ( & V_61 -> V_67 ) ;
if ( V_56 -> V_2 != NULL || V_56 -> V_69 . V_70 < 0 ) {
break;
}
F_34 ( & V_61 -> V_67 ) ;
if ( F_77 ( V_107 ) ) {
V_35 = - V_108 ;
goto V_109;
}
F_78 () ;
}
if ( V_56 -> V_2 )
F_6 ( V_5 , V_56 -> V_2 ) ;
else
V_35 = V_56 -> V_69 . V_70 ;
F_34 ( & V_61 -> V_67 ) ;
V_109:
F_79 ( & V_56 -> V_71 , & V_103 ) ;
F_37 ( V_56 ) ;
V_102:
F_29 ( L_15 ,
V_46 , F_57 ( & V_80 , V_5 -> V_95 ) , V_35 ) ;
return V_35 ;
}
static T_5
F_80 ( struct V_110 * V_111 , const char T_6 * V_112 , T_1 V_113 )
{
const void * V_12 , * V_13 ;
void * V_114 ;
struct V_55 * V_56 ;
struct V_60 * V_61 = F_81 ( F_82 ( V_111 ) ) -> V_61 ;
struct V_1 * V_2 ;
T_4 V_115 ;
T_3 V_62 ;
T_5 V_35 = - V_116 ;
if ( V_113 > V_117 )
goto V_102;
V_35 = - V_22 ;
V_114 = F_83 ( V_113 , V_21 ) ;
if ( ! V_114 )
goto V_102;
V_35 = - V_17 ;
if ( F_84 ( V_114 , V_112 , V_113 ) )
goto V_35;
V_13 = ( const void * ) ( ( char * ) V_114 + V_113 ) ;
V_12 = F_13 ( V_114 , V_13 , & V_115 , sizeof( V_115 ) ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_30 ( V_12 ) ;
goto V_35;
}
V_62 = F_85 ( & V_80 , V_115 ) ;
if ( ! F_86 ( V_62 ) ) {
V_35 = - V_118 ;
goto V_35;
}
V_35 = - V_22 ;
V_2 = F_23 () ;
if ( V_2 == NULL )
goto V_35;
V_35 = - V_119 ;
F_33 ( & V_61 -> V_67 ) ;
V_56 = F_43 ( V_61 , V_62 , NULL ) ;
if ( V_56 == NULL ) {
F_34 ( & V_61 -> V_67 ) ;
goto V_120;
}
F_49 ( & V_56 -> V_58 ) ;
F_34 ( & V_61 -> V_67 ) ;
V_12 = F_27 ( V_12 , V_13 , V_2 , V_56 -> V_57 -> V_84 ) ;
if ( F_17 ( V_12 ) ) {
V_35 = F_30 ( V_12 ) ;
switch ( V_35 ) {
case - V_41 :
case - V_40 :
V_56 -> V_69 . V_70 = V_35 ;
V_35 = V_113 ;
break;
case - V_17 :
case - V_22 :
case - V_118 :
case - V_121 :
V_56 -> V_69 . V_70 = - V_54 ;
break;
default:
F_87 ( V_122 L_16
L_17 , V_46 , V_35 ) ;
V_56 -> V_69 . V_70 = - V_123 ;
}
goto V_124;
}
V_56 -> V_2 = F_1 ( V_2 ) ;
V_35 = V_113 ;
V_124:
F_33 ( & V_61 -> V_67 ) ;
F_48 ( V_56 ) ;
F_34 ( & V_61 -> V_67 ) ;
F_37 ( V_56 ) ;
V_120:
F_3 ( V_2 ) ;
V_35:
F_42 ( V_114 ) ;
V_102:
F_29 ( L_18 , V_46 , V_35 ) ;
return V_35 ;
}
static int F_88 ( struct V_125 * V_125 , int V_126 )
{
struct V_47 * V_47 = V_125 -> V_127 -> V_128 ;
struct V_48 * V_49 = F_32 ( V_47 , V_50 ) ;
int V_34 = 0 ;
F_33 ( & V_51 ) ;
if ( V_49 -> V_52 < 0 ) {
V_49 -> V_52 = V_126 ;
F_89 ( & V_101 ) ;
F_90 ( & V_105 ) ;
} else if ( V_49 -> V_52 != V_126 ) {
V_34 = - V_129 ;
goto V_102;
}
F_2 ( & V_49 -> V_53 ) ;
V_102:
F_34 ( & V_51 ) ;
return V_34 ;
}
static int F_91 ( struct V_125 * V_125 )
{
return F_88 ( V_125 , 0 ) ;
}
static int F_92 ( struct V_125 * V_125 )
{
return F_88 ( V_125 , 1 ) ;
}
static void
F_93 ( struct V_125 * V_125 )
{
struct V_47 * V_47 = V_125 -> V_127 -> V_128 ;
struct V_60 * V_61 = F_81 ( V_125 ) -> V_61 ;
struct V_55 * V_56 ;
V_130:
F_33 ( & V_61 -> V_67 ) ;
F_44 (gss_msg, &pipe->in_downcall, list) {
if ( ! F_39 ( & V_56 -> V_69 . V_58 ) )
continue;
V_56 -> V_69 . V_70 = - V_131 ;
F_2 ( & V_56 -> V_3 ) ;
F_48 ( V_56 ) ;
F_34 ( & V_61 -> V_67 ) ;
F_37 ( V_56 ) ;
goto V_130;
}
F_34 ( & V_61 -> V_67 ) ;
F_35 ( V_47 ) ;
}
static void
F_94 ( struct V_132 * V_69 )
{
struct V_55 * V_56 = F_7 ( V_69 , struct V_55 , V_69 ) ;
if ( V_69 -> V_70 < 0 ) {
F_29 ( L_19 ,
V_46 , V_56 ) ;
F_2 ( & V_56 -> V_3 ) ;
F_53 ( V_56 ) ;
if ( V_69 -> V_70 == - V_133 )
F_69 () ;
F_37 ( V_56 ) ;
}
}
static void F_95 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
struct V_91 * V_91 = V_137 -> V_138 ;
struct V_60 * V_61 = V_91 -> V_61 ;
if ( V_61 -> V_134 != NULL ) {
F_96 ( V_61 -> V_134 ) ;
V_61 -> V_134 = NULL ;
}
}
static int F_97 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
struct V_91 * V_12 = V_137 -> V_138 ;
struct V_134 * V_134 ;
V_134 = F_98 ( V_135 , V_12 -> V_139 , V_12 -> V_140 , V_12 -> V_61 ) ;
if ( F_17 ( V_134 ) )
return F_30 ( V_134 ) ;
V_12 -> V_61 -> V_134 = V_134 ;
return 0 ;
}
static struct V_91 * F_99 ( struct V_141 * V_140 ,
const char * V_139 ,
const struct V_142 * V_143 )
{
struct V_91 * V_12 ;
int V_35 = - V_22 ;
V_12 = F_83 ( sizeof( * V_12 ) , V_144 ) ;
if ( V_12 == NULL )
goto V_35;
V_12 -> V_61 = F_100 ( V_143 , V_145 ) ;
if ( F_17 ( V_12 -> V_61 ) ) {
V_35 = F_30 ( V_12 -> V_61 ) ;
goto V_146;
}
V_12 -> V_139 = V_139 ;
V_12 -> V_140 = V_140 ;
F_101 ( & V_12 -> V_93 ) ;
F_102 ( & V_12 -> V_137 ,
& V_147 ,
V_12 ) ;
return V_12 ;
V_146:
F_42 ( V_12 ) ;
V_35:
return F_15 ( V_35 ) ;
}
static int F_103 ( struct V_136 * V_137 , void * V_20 )
{
struct V_91 * V_91 ;
struct V_148 * args = V_20 ;
if ( V_137 -> V_149 != & V_147 )
return 0 ;
V_91 = F_7 ( V_137 , struct V_91 , V_137 ) ;
if ( strcmp ( V_91 -> V_139 , args -> V_139 ) != 0 )
return 0 ;
if ( ! F_104 ( & V_91 -> V_93 ) )
return 0 ;
return 1 ;
}
static struct V_136 * F_105 ( void * V_20 )
{
struct V_91 * V_91 ;
struct V_148 * args = V_20 ;
V_91 = F_99 ( args -> V_140 , args -> V_139 , args -> V_143 ) ;
if ( ! F_17 ( V_91 ) )
return & V_91 -> V_137 ;
return NULL ;
}
static struct V_91 * F_106 ( struct V_141 * V_140 ,
const char * V_139 ,
const struct V_142 * V_143 )
{
struct V_47 * V_47 = F_107 ( V_140 ) ;
struct V_136 * V_137 ;
struct V_148 args = {
. V_140 = V_140 ,
. V_139 = V_139 ,
. V_143 = V_143 ,
} ;
V_137 = F_108 ( V_47 ,
& V_140 -> V_150 ,
F_103 ,
F_105 ,
& args ) ;
if ( V_137 != NULL )
return F_7 ( V_137 , struct V_91 , V_137 ) ;
return F_15 ( - V_22 ) ;
}
static void F_109 ( struct V_91 * V_12 )
{
struct V_141 * V_140 = V_12 -> V_140 ;
struct V_47 * V_47 = F_107 ( V_140 ) ;
F_110 ( V_47 ,
& V_140 -> V_150 ,
& V_12 -> V_137 ) ;
F_111 ( V_12 -> V_61 ) ;
F_42 ( V_12 ) ;
}
static void F_112 ( struct V_93 * V_93 )
{
struct V_91 * V_12 = F_7 ( V_93 , struct V_91 , V_93 ) ;
F_109 ( V_12 ) ;
}
static void F_113 ( struct V_91 * V_12 )
{
if ( V_12 != NULL )
F_114 ( & V_12 -> V_93 , F_112 ) ;
}
static struct V_63 *
F_115 ( struct V_151 * args , struct V_141 * V_140 )
{
T_7 V_152 = args -> V_153 ;
struct V_63 * V_63 ;
struct V_91 * V_91 ;
struct V_98 * V_57 ;
int V_35 = - V_22 ;
F_29 ( L_20 , V_140 ) ;
if ( ! F_116 ( V_154 ) )
return F_15 ( V_35 ) ;
if ( ! ( V_63 = F_83 ( sizeof( * V_63 ) , V_144 ) ) )
goto V_155;
F_117 ( & V_63 -> V_156 ) ;
V_63 -> V_83 = NULL ;
if ( args -> V_83 ) {
V_63 -> V_83 = F_118 ( args -> V_83 , V_144 ) ;
if ( V_63 -> V_83 == NULL )
goto V_157;
}
V_63 -> V_158 = V_140 ;
V_63 -> V_47 = F_119 ( F_107 ( V_140 ) ) ;
V_35 = - V_118 ;
V_63 -> V_84 = F_120 ( V_152 ) ;
if ( ! V_63 -> V_84 ) {
F_29 ( L_21 , V_152 ) ;
goto V_159;
}
V_63 -> V_65 = F_121 ( V_63 -> V_84 , V_152 ) ;
if ( V_63 -> V_65 == 0 )
goto V_160;
if ( ! F_74 ( V_63 -> V_47 ) )
goto V_160;
V_57 = & V_63 -> V_98 ;
V_57 -> V_161 = V_162 >> 2 ;
V_57 -> V_163 = V_164 >> 2 ;
V_57 -> V_165 = 0 ;
V_57 -> V_166 = & V_167 ;
V_57 -> V_168 = V_152 ;
if ( F_122 ( V_63 -> V_84 , V_152 ) )
V_57 -> V_165 |= V_169 ;
F_26 ( & V_57 -> V_170 , 1 ) ;
F_101 ( & V_63 -> V_93 ) ;
V_35 = F_123 ( V_57 ) ;
if ( V_35 )
goto V_160;
V_91 = F_106 ( V_140 , L_22 , & V_171 ) ;
if ( F_17 ( V_91 ) ) {
V_35 = F_30 ( V_91 ) ;
goto V_172;
}
V_63 -> V_91 [ 1 ] = V_91 ;
V_91 = F_106 ( V_140 , V_63 -> V_84 -> V_86 ,
& V_173 ) ;
if ( F_17 ( V_91 ) ) {
V_35 = F_30 ( V_91 ) ;
goto V_174;
}
V_63 -> V_91 [ 0 ] = V_91 ;
return V_63 ;
V_174:
F_113 ( V_63 -> V_91 [ 1 ] ) ;
V_172:
F_124 ( V_57 ) ;
V_160:
F_125 ( V_63 -> V_84 ) ;
V_159:
F_126 ( V_63 -> V_47 ) ;
V_157:
F_42 ( V_63 -> V_83 ) ;
F_42 ( V_63 ) ;
V_155:
F_127 ( V_154 ) ;
return F_15 ( V_35 ) ;
}
static void
F_128 ( struct V_63 * V_63 )
{
F_113 ( V_63 -> V_91 [ 0 ] ) ;
F_113 ( V_63 -> V_91 [ 1 ] ) ;
F_125 ( V_63 -> V_84 ) ;
F_126 ( V_63 -> V_47 ) ;
F_42 ( V_63 -> V_83 ) ;
F_42 ( V_63 ) ;
F_127 ( V_154 ) ;
}
static void
F_129 ( struct V_93 * V_93 )
{
struct V_63 * V_63 = F_7 ( V_93 , struct V_63 , V_93 ) ;
F_128 ( V_63 ) ;
}
static void
F_41 ( struct V_63 * V_63 )
{
F_114 ( & V_63 -> V_93 , F_129 ) ;
}
static void
F_130 ( struct V_98 * V_57 )
{
struct V_63 * V_63 = F_7 ( V_57 ,
struct V_63 , V_98 ) ;
F_29 ( L_23 ,
V_57 , V_57 -> V_168 ) ;
if ( F_131 ( & V_63 -> V_156 ) ) {
F_33 ( & V_175 ) ;
F_132 ( & V_63 -> V_156 ) ;
F_34 ( & V_175 ) ;
}
F_113 ( V_63 -> V_91 [ 0 ] ) ;
V_63 -> V_91 [ 0 ] = NULL ;
F_113 ( V_63 -> V_91 [ 1 ] ) ;
V_63 -> V_91 [ 1 ] = NULL ;
F_124 ( V_57 ) ;
F_41 ( V_63 ) ;
}
static struct V_63 *
F_133 ( struct V_151 * args ,
struct V_141 * V_140 ,
struct V_63 * V_176 )
{
struct V_63 * V_63 ;
unsigned long V_177 = ( unsigned long ) V_140 ;
F_33 ( & V_175 ) ;
F_134 (gss_auth_hash_table,
gss_auth,
hash,
hashval) {
if ( V_63 -> V_158 != V_140 )
continue;
if ( V_63 -> V_98 . V_168 != args -> V_153 )
continue;
if ( V_63 -> V_83 != args -> V_83 ) {
if ( V_63 -> V_83 == NULL )
continue;
if ( args -> V_83 == NULL )
continue;
if ( strcmp ( V_63 -> V_83 , args -> V_83 ) )
continue;
}
if ( ! F_135 ( & V_63 -> V_98 . V_170 ) )
continue;
goto V_102;
}
if ( V_176 )
F_136 ( V_178 , & V_176 -> V_156 , V_177 ) ;
V_63 = V_176 ;
V_102:
F_34 ( & V_175 ) ;
return V_63 ;
}
static struct V_63 *
F_137 ( struct V_151 * args , struct V_141 * V_140 )
{
struct V_63 * V_63 ;
struct V_63 * V_176 ;
V_63 = F_133 ( args , V_140 , NULL ) ;
if ( V_63 != NULL )
goto V_102;
V_176 = F_115 ( args , V_140 ) ;
if ( F_17 ( V_176 ) )
return V_176 ;
V_63 = F_133 ( args , V_140 , V_176 ) ;
if ( V_63 != V_176 )
F_130 ( & V_176 -> V_98 ) ;
V_102:
return V_63 ;
}
static struct V_98 *
F_138 ( struct V_151 * args , struct V_141 * V_140 )
{
struct V_63 * V_63 ;
struct V_179 * V_180 = F_139 ( V_140 -> V_181 . V_182 ) ;
while ( V_140 != V_140 -> V_183 ) {
struct V_141 * V_184 = V_140 -> V_183 ;
if ( F_139 ( V_184 -> V_181 . V_182 ) != V_180 )
break;
V_140 = V_184 ;
}
V_63 = F_137 ( args , V_140 ) ;
if ( F_17 ( V_63 ) )
return F_140 ( V_63 ) ;
return & V_63 -> V_98 ;
}
static int
F_141 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_63 * V_63 = F_7 ( V_5 -> V_97 , struct V_63 , V_98 ) ;
struct V_1 * V_2 = F_142 ( V_6 -> V_10 , 1 ) ;
struct V_75 * V_76 ;
if ( F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_2 -> V_23 = V_185 ;
V_5 -> V_186 = & V_187 ;
F_143 ( V_5 ) ;
V_76 = F_144 ( V_63 -> V_158 , V_5 , V_188 | V_189 ) ;
if ( ! F_17 ( V_76 ) )
F_145 ( V_76 ) ;
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
F_149 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = F_7 ( V_191 , struct V_1 , V_192 ) ;
F_147 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_150 ( & V_2 -> V_192 , F_149 ) ;
}
static void
F_151 ( struct V_6 * V_6 )
{
F_29 ( L_25 , V_46 , V_6 ) ;
F_42 ( V_6 ) ;
}
static void
F_152 ( struct V_190 * V_191 )
{
struct V_6 * V_6 = F_7 ( V_191 , struct V_6 , V_7 . V_193 ) ;
F_151 ( V_6 ) ;
}
static void
F_153 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_63 * V_63 = F_7 ( V_5 -> V_97 , struct V_63 , V_98 ) ;
struct V_1 * V_2 = F_142 ( V_6 -> V_10 , 1 ) ;
F_154 ( V_6 -> V_10 , NULL ) ;
F_150 ( & V_5 -> V_193 , F_152 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_41 ( V_63 ) ;
}
static void
F_155 ( struct V_4 * V_5 )
{
if ( F_141 ( V_5 ) )
return;
F_153 ( V_5 ) ;
}
static struct V_4 *
F_156 ( struct V_98 * V_57 , struct V_194 * V_195 , int V_196 )
{
return F_157 ( V_57 , V_195 , V_196 , V_21 ) ;
}
static struct V_4 *
F_158 ( struct V_98 * V_57 , struct V_194 * V_195 , int V_196 , T_8 V_197 )
{
struct V_63 * V_63 = F_7 ( V_57 , struct V_63 , V_98 ) ;
struct V_6 * V_5 = NULL ;
int V_35 = - V_22 ;
F_29 ( L_26 ,
V_46 , F_57 ( & V_80 , V_195 -> V_62 ) ,
V_57 -> V_168 ) ;
if ( ! ( V_5 = F_24 ( sizeof( * V_5 ) , V_197 ) ) )
goto V_198;
F_159 ( & V_5 -> V_7 , V_195 , V_57 , & V_199 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_200 = V_63 -> V_65 ;
V_5 -> V_96 = NULL ;
if ( V_195 -> V_201 )
V_5 -> V_96 = V_195 -> V_202 ;
F_66 ( & V_63 -> V_93 ) ;
return & V_5 -> V_7 ;
V_198:
F_29 ( L_27 , V_46 , V_35 ) ;
return F_15 ( V_35 ) ;
}
static int
F_160 ( struct V_98 * V_57 , struct V_4 * V_5 )
{
struct V_63 * V_63 = F_7 ( V_57 , struct V_63 , V_98 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_35 ;
do {
V_35 = F_72 ( V_63 , V_6 ) ;
} while ( V_35 == - V_54 );
return V_35 ;
}
static char *
F_161 ( struct V_4 * V_5 )
{
char * string = NULL ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_1 * V_2 ;
unsigned int V_15 ;
struct V_18 * V_203 ;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( ! V_2 )
goto V_102;
V_15 = V_2 -> V_45 . V_15 ;
F_22 () ;
if ( ! V_15 )
return NULL ;
realloc:
string = F_83 ( V_15 + 1 , V_144 ) ;
if ( ! string )
return NULL ;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( ! V_2 || ! V_2 -> V_45 . V_15 ) {
F_42 ( string ) ;
string = NULL ;
goto V_102;
}
V_203 = & V_2 -> V_45 ;
if ( V_15 < V_203 -> V_15 ) {
V_15 = V_203 -> V_15 ;
F_22 () ;
F_42 ( string ) ;
goto realloc;
}
memcpy ( string , V_203 -> V_20 , V_203 -> V_15 ) ;
string [ V_203 -> V_15 ] = '\0' ;
V_102:
F_22 () ;
return string ;
}
static int
F_162 ( struct V_4 * V_204 )
{
struct V_6 * V_6 = F_7 ( V_204 , struct V_6 , V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_30 = V_32 + ( V_205 * V_38 ) ;
int V_34 = 0 ;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( ! V_2 || F_163 ( V_30 , V_2 -> V_37 ) )
V_34 = - V_41 ;
F_22 () ;
return V_34 ;
}
static int
F_164 ( struct V_194 * V_195 , struct V_4 * V_204 , int V_196 )
{
struct V_6 * V_6 = F_7 ( V_204 , struct V_6 , V_7 ) ;
struct V_1 * V_2 ;
int V_34 ;
if ( F_8 ( V_8 , & V_204 -> V_9 ) )
goto V_102;
F_20 () ;
V_2 = F_21 ( V_6 -> V_10 ) ;
if ( ! V_2 || F_163 ( V_32 , V_2 -> V_37 ) ) {
F_22 () ;
return 0 ;
}
F_22 () ;
if ( ! F_8 ( V_11 , & V_204 -> V_9 ) )
return 0 ;
V_102:
if ( V_195 -> V_202 != NULL ) {
if ( V_6 -> V_96 == NULL )
return 0 ;
V_34 = strcmp ( V_195 -> V_202 , V_6 -> V_96 ) == 0 ;
goto V_206;
}
if ( V_6 -> V_96 != NULL )
return 0 ;
V_34 = F_45 ( V_204 -> V_95 , V_195 -> V_62 ) ;
V_206:
if ( V_34 == 0 )
return V_34 ;
if ( F_8 ( V_207 , & V_195 -> V_208 ) &&
( F_162 ( V_204 ) != 0 ) ) {
F_165 ( V_207 , & V_195 -> V_208 ) ;
F_10 ( V_209 , & V_195 -> V_208 ) ;
}
return V_34 ;
}
static T_9 *
F_166 ( struct V_75 * V_76 , T_9 * V_12 )
{
struct V_210 * V_211 = V_76 -> V_77 ;
struct V_4 * V_5 = V_211 -> V_78 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_9 * V_212 ;
T_2 V_213 = 0 ;
struct V_18 V_214 ;
struct V_215 V_216 ;
struct V_217 V_218 ;
F_29 ( L_28 , V_76 -> V_99 , V_46 ) ;
* V_12 ++ = F_167 ( V_219 ) ;
V_212 = V_12 ++ ;
F_33 ( & V_2 -> V_26 ) ;
V_211 -> V_220 = V_2 -> V_25 ++ ;
F_34 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_221 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_211 -> V_220 ) ;
* V_12 ++ = F_167 ( ( T_2 ) V_6 -> V_200 ) ;
V_12 = F_168 ( V_12 , & V_2 -> V_42 ) ;
* V_212 = F_167 ( ( V_12 - ( V_212 + 1 ) ) << 2 ) ;
V_216 . V_222 = F_169 ( V_211 -> V_223 ,
V_211 -> V_224 . V_191 [ 0 ] . V_222 ) ;
V_216 . V_225 = ( V_226 * ) V_12 - ( V_226 * ) V_216 . V_222 ;
F_170 ( & V_216 , & V_218 ) ;
* V_12 ++ = F_167 ( V_219 ) ;
V_214 . V_20 = ( V_226 * ) ( V_12 + 1 ) ;
V_213 = F_171 ( V_2 -> V_43 , & V_218 , & V_214 ) ;
if ( V_213 == V_227 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_213 != 0 ) {
F_87 ( L_29 , V_213 ) ;
goto V_228;
}
V_12 = F_172 ( V_12 , NULL , V_214 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_228:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_173 ( struct V_75 * V_76 )
{
struct V_4 * V_229 = V_76 -> V_77 -> V_78 ;
struct V_6 * V_6 = F_7 ( V_229 ,
struct V_6 ,
V_7 ) ;
struct V_98 * V_57 = V_229 -> V_97 ;
struct V_194 V_195 = {
. V_62 = V_229 -> V_95 ,
. V_202 = V_6 -> V_96 ,
. V_201 = ( V_6 -> V_96 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_176 ;
V_176 = F_156 ( V_57 , & V_195 , V_230 ) ;
if ( F_17 ( V_176 ) )
return F_30 ( V_176 ) ;
V_76 -> V_77 -> V_78 = V_176 ;
F_146 ( V_229 ) ;
return 0 ;
}
static int F_174 ( struct V_4 * V_5 )
{
if ( F_8 ( V_72 , & V_5 -> V_9 ) ) {
unsigned long V_31 = V_32 ;
unsigned long V_231 , V_232 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_231 = V_6 -> V_73 ;
V_232 = V_231 + V_233 * V_38 ;
if ( F_175 ( V_31 , V_231 , V_232 ) )
return 1 ;
}
return 0 ;
}
static int
F_176 ( struct V_75 * V_76 )
{
struct V_4 * V_5 = V_76 -> V_77 -> V_78 ;
int V_34 = 0 ;
if ( F_174 ( V_5 ) )
return - V_40 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_34 = F_173 ( V_76 ) ;
if ( V_34 < 0 )
goto V_102;
V_5 = V_76 -> V_77 -> V_78 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_34 = F_70 ( V_76 ) ;
V_102:
return V_34 ;
}
static int
F_177 ( struct V_75 * V_76 )
{
return 0 ;
}
static T_9 *
F_178 ( struct V_75 * V_76 , T_9 * V_12 )
{
struct V_4 * V_5 = V_76 -> V_77 -> V_78 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_9 V_234 ;
struct V_215 V_216 ;
struct V_217 V_218 ;
struct V_18 V_214 ;
T_2 V_235 , V_15 ;
T_2 V_213 ;
T_9 * V_34 = F_15 ( - V_123 ) ;
F_29 ( L_28 , V_76 -> V_99 , V_46 ) ;
V_235 = F_179 ( * V_12 ++ ) ;
if ( ( V_15 = F_179 ( * V_12 ++ ) ) > V_236 )
goto V_237;
if ( V_235 != V_219 )
goto V_237;
V_234 = F_167 ( V_76 -> V_77 -> V_220 ) ;
V_216 . V_222 = & V_234 ;
V_216 . V_225 = sizeof( V_234 ) ;
F_170 ( & V_216 , & V_218 ) ;
V_214 . V_20 = ( V_226 * ) V_12 ;
V_214 . V_15 = V_15 ;
V_34 = F_15 ( - V_41 ) ;
V_213 = F_180 ( V_2 -> V_43 , & V_218 , & V_214 ) ;
if ( V_213 == V_227 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_213 ) {
F_29 ( L_30 ,
V_76 -> V_99 , V_46 , V_213 ) ;
goto V_237;
}
V_5 -> V_97 -> V_238 = F_181 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_29 ( L_31 ,
V_76 -> V_99 , V_46 ) ;
return V_12 + F_181 ( V_15 ) ;
V_237:
F_3 ( V_2 ) ;
F_29 ( L_32 , V_76 -> V_99 , V_46 ,
F_30 ( V_34 ) ) ;
return V_34 ;
}
static void F_182 ( T_10 V_239 , struct V_210 * V_240 ,
T_9 * V_12 , void * V_241 )
{
struct V_242 V_243 ;
F_183 ( & V_243 , & V_240 -> V_224 , V_12 ) ;
V_239 ( V_240 , & V_243 , V_241 ) ;
}
static inline int
F_184 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_10 V_239 , struct V_210 * V_240 ,
T_9 * V_12 , void * V_241 )
{
struct V_217 * V_244 = & V_240 -> V_224 ;
struct V_217 V_245 ;
T_9 * V_246 = NULL ;
struct V_18 V_214 ;
T_2 V_247 ;
T_9 * V_16 ;
struct V_215 * V_216 ;
T_2 V_213 = 0 ;
int V_248 = - V_123 ;
V_246 = V_12 ++ ;
V_247 = ( V_226 * ) V_12 - ( V_226 * ) V_244 -> V_191 [ 0 ] . V_222 ;
* V_12 ++ = F_167 ( V_240 -> V_220 ) ;
F_182 ( V_239 , V_240 , V_12 , V_241 ) ;
if ( F_185 ( V_244 , & V_245 ,
V_247 , V_244 -> V_15 - V_247 ) )
return V_248 ;
* V_246 = F_167 ( V_245 . V_15 ) ;
if ( V_244 -> V_249 || V_244 -> V_250 [ 0 ] . V_225 )
V_216 = V_244 -> V_250 ;
else
V_216 = V_244 -> V_191 ;
V_12 = V_216 -> V_222 + V_216 -> V_225 ;
V_214 . V_20 = ( V_226 * ) ( V_12 + 1 ) ;
V_213 = F_171 ( V_2 -> V_43 , & V_245 , & V_214 ) ;
V_248 = - V_123 ;
if ( V_213 == V_227 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_213 )
return V_248 ;
V_16 = F_172 ( V_12 , NULL , V_214 . V_15 ) ;
V_247 = ( V_226 * ) V_16 - ( V_226 * ) V_12 ;
V_216 -> V_225 += V_247 ;
V_244 -> V_15 += V_247 ;
return 0 ;
}
static void
F_186 ( struct V_210 * V_240 )
{
int V_251 ;
for ( V_251 = 0 ; V_251 < V_240 -> V_252 ; V_251 ++ )
F_187 ( V_240 -> V_253 [ V_251 ] ) ;
F_42 ( V_240 -> V_253 ) ;
}
static int
F_188 ( struct V_210 * V_240 )
{
struct V_217 * V_244 = & V_240 -> V_224 ;
int V_254 , V_255 , V_251 ;
if ( V_244 -> V_249 == 0 ) {
V_240 -> V_252 = 0 ;
return 0 ;
}
V_254 = V_244 -> V_256 >> V_257 ;
V_255 = ( V_244 -> V_256 + V_244 -> V_249 - 1 ) >> V_257 ;
V_240 -> V_252 = V_255 - V_254 + 1 + 1 ;
V_240 -> V_253
= F_83 ( V_240 -> V_252 * sizeof( struct V_258 * ) ,
V_21 ) ;
if ( ! V_240 -> V_253 )
goto V_102;
for ( V_251 = 0 ; V_251 < V_240 -> V_252 ; V_251 ++ ) {
V_240 -> V_253 [ V_251 ] = F_189 ( V_21 ) ;
if ( V_240 -> V_253 [ V_251 ] == NULL )
goto V_259;
}
V_240 -> V_260 = F_186 ;
return 0 ;
V_259:
V_240 -> V_252 = V_251 ;
F_186 ( V_240 ) ;
V_102:
return - V_54 ;
}
static inline int
F_190 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_10 V_239 , struct V_210 * V_240 ,
T_9 * V_12 , void * V_241 )
{
struct V_217 * V_244 = & V_240 -> V_224 ;
T_2 V_247 ;
T_2 V_213 ;
int V_248 ;
T_9 * V_261 ;
struct V_258 * * V_262 ;
int V_254 ;
int V_263 ;
struct V_215 * V_216 ;
char * V_264 ;
V_261 = V_12 ++ ;
V_247 = ( V_226 * ) V_12 - ( V_226 * ) V_244 -> V_191 [ 0 ] . V_222 ;
* V_12 ++ = F_167 ( V_240 -> V_220 ) ;
F_182 ( V_239 , V_240 , V_12 , V_241 ) ;
V_248 = F_188 ( V_240 ) ;
if ( V_248 )
return V_248 ;
V_254 = V_244 -> V_256 >> V_257 ;
V_262 = V_244 -> V_265 + V_254 ;
V_244 -> V_265 = V_240 -> V_253 ;
V_244 -> V_256 -= V_254 << V_257 ;
if ( V_244 -> V_249 || V_244 -> V_250 [ 0 ] . V_225 ) {
V_264 = F_191 ( V_240 -> V_253 [ V_240 -> V_252 - 1 ] ) ;
memcpy ( V_264 , V_244 -> V_250 [ 0 ] . V_222 , V_244 -> V_250 [ 0 ] . V_225 ) ;
V_244 -> V_250 [ 0 ] . V_222 = V_264 ;
}
V_213 = F_192 ( V_2 -> V_43 , V_247 , V_244 , V_262 ) ;
F_38 ( V_244 -> V_15 > V_244 -> V_85 ) ;
V_248 = - V_123 ;
if ( V_213 == V_227 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_213 )
return V_248 ;
* V_261 = F_167 ( V_244 -> V_15 - V_247 ) ;
if ( V_244 -> V_249 || V_244 -> V_250 [ 0 ] . V_225 )
V_216 = V_244 -> V_250 ;
else
V_216 = V_244 -> V_191 ;
V_12 = V_216 -> V_222 + V_216 -> V_225 ;
V_263 = 3 - ( ( V_244 -> V_15 - V_247 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_263 ) ;
V_216 -> V_225 += V_263 ;
V_244 -> V_15 += V_263 ;
return 0 ;
}
static int
F_193 ( struct V_75 * V_76 ,
T_10 V_239 , void * V_240 , T_9 * V_12 , void * V_241 )
{
struct V_4 * V_5 = V_76 -> V_77 -> V_78 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_248 = - V_123 ;
F_29 ( L_28 , V_76 -> V_99 , V_46 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_182 ( V_239 , V_240 , V_12 , V_241 ) ;
V_248 = 0 ;
goto V_102;
}
switch ( V_6 -> V_200 ) {
case V_266 :
F_182 ( V_239 , V_240 , V_12 , V_241 ) ;
V_248 = 0 ;
break;
case V_267 :
V_248 = F_184 ( V_5 , V_2 , V_239 , V_240 , V_12 , V_241 ) ;
break;
case V_268 :
V_248 = F_190 ( V_5 , V_2 , V_239 , V_240 , V_12 , V_241 ) ;
break;
}
V_102:
F_3 ( V_2 ) ;
F_29 ( L_33 , V_76 -> V_99 , V_46 , V_248 ) ;
return V_248 ;
}
static inline int
F_194 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_210 * V_240 , T_9 * * V_12 )
{
struct V_217 * V_269 = & V_240 -> V_270 ;
struct V_217 V_245 ;
struct V_18 V_214 ;
T_2 V_271 , V_272 ;
T_2 V_246 ;
T_2 V_213 ;
int V_248 = - V_123 ;
V_246 = F_179 ( * ( * V_12 ) ++ ) ;
if ( V_246 & 3 )
return V_248 ;
V_271 = ( V_226 * ) ( * V_12 ) - ( V_226 * ) V_269 -> V_191 [ 0 ] . V_222 ;
V_272 = V_246 + V_271 ;
if ( V_272 > V_269 -> V_15 )
return V_248 ;
if ( F_179 ( * ( * V_12 ) ++ ) != V_240 -> V_220 )
return V_248 ;
if ( F_185 ( V_269 , & V_245 , V_271 ,
V_272 - V_271 ) )
return V_248 ;
if ( F_195 ( V_269 , & V_214 , V_272 ) )
return V_248 ;
V_213 = F_180 ( V_2 -> V_43 , & V_245 , & V_214 ) ;
if ( V_213 == V_227 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_213 != V_273 )
return V_248 ;
return 0 ;
}
static inline int
F_196 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_210 * V_240 , T_9 * * V_12 )
{
struct V_217 * V_269 = & V_240 -> V_270 ;
T_2 V_247 ;
T_2 V_261 ;
T_2 V_213 ;
int V_248 = - V_123 ;
V_261 = F_179 ( * ( * V_12 ) ++ ) ;
V_247 = ( V_226 * ) ( * V_12 ) - ( V_226 * ) V_269 -> V_191 [ 0 ] . V_222 ;
if ( V_247 + V_261 > V_269 -> V_15 )
return V_248 ;
V_269 -> V_15 = V_247 + V_261 ;
V_213 = F_197 ( V_2 -> V_43 , V_247 , V_269 ) ;
if ( V_213 == V_227 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_213 != V_273 )
return V_248 ;
if ( F_179 ( * ( * V_12 ) ++ ) != V_240 -> V_220 )
return V_248 ;
return 0 ;
}
static int
F_198 ( T_11 V_274 , struct V_210 * V_240 ,
T_9 * V_12 , void * V_241 )
{
struct V_242 V_243 ;
F_199 ( & V_243 , & V_240 -> V_270 , V_12 ) ;
return V_274 ( V_240 , & V_243 , V_241 ) ;
}
static int
F_200 ( struct V_75 * V_76 ,
T_11 V_274 , void * V_240 , T_9 * V_12 , void * V_241 )
{
struct V_4 * V_5 = V_76 -> V_77 -> V_78 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_9 * V_275 = V_12 ;
struct V_215 * V_191 = ( (struct V_210 * ) V_240 ) -> V_270 . V_191 ;
int V_276 = V_191 -> V_225 ;
int V_248 = - V_123 ;
if ( V_2 -> V_23 != V_24 )
goto V_277;
switch ( V_6 -> V_200 ) {
case V_266 :
break;
case V_267 :
V_248 = F_194 ( V_5 , V_2 , V_240 , & V_12 ) ;
if ( V_248 )
goto V_102;
break;
case V_268 :
V_248 = F_196 ( V_5 , V_2 , V_240 , & V_12 ) ;
if ( V_248 )
goto V_102;
break;
}
V_5 -> V_97 -> V_163 = V_5 -> V_97 -> V_238 + ( V_12 - V_275 )
+ ( V_276 - V_191 -> V_225 ) ;
V_277:
V_248 = F_198 ( V_274 , V_240 , V_12 , V_241 ) ;
V_102:
F_3 ( V_2 ) ;
F_29 ( L_33 ,
V_76 -> V_99 , V_46 , V_248 ) ;
return V_248 ;
}
static T_12 int F_201 ( struct V_47 * V_47 )
{
return F_202 ( V_47 ) ;
}
static T_13 void F_203 ( struct V_47 * V_47 )
{
F_204 ( V_47 ) ;
}
static int T_14 F_205 ( void )
{
int V_35 = 0 ;
V_35 = F_206 ( & V_167 ) ;
if ( V_35 )
goto V_102;
V_35 = F_207 () ;
if ( V_35 )
goto V_278;
V_35 = F_208 ( & V_279 ) ;
if ( V_35 )
goto V_280;
F_64 ( & V_101 , L_34 ) ;
return 0 ;
V_280:
F_209 () ;
V_278:
F_210 ( & V_167 ) ;
V_102:
return V_35 ;
}
static void T_15 F_211 ( void )
{
F_212 ( & V_279 ) ;
F_209 () ;
F_210 ( & V_167 ) ;
F_213 () ;
}
