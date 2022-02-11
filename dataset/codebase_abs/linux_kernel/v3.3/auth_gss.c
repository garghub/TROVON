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
F_28 ( L_1 , - F_29 ( V_12 ) ) ;
return V_12 ;
}
static int F_30 ( void )
{
int V_32 ;
F_31 ( & V_43 ) ;
if ( V_44 >= 0 ) {
F_2 ( & V_45 ) ;
V_32 = V_44 ;
} else
V_32 = - V_46 ;
F_32 ( & V_43 ) ;
return V_32 ;
}
static void F_33 ( void )
{
if ( F_34 ( & V_45 , & V_43 ) ) {
V_44 = - 1 ;
F_32 ( & V_43 ) ;
}
}
static void
F_35 ( struct V_47 * V_48 )
{
if ( ! F_4 ( & V_48 -> V_3 ) )
return;
F_33 () ;
F_36 ( ! F_37 ( & V_48 -> V_49 ) ) ;
if ( V_48 -> V_2 != NULL )
F_3 ( V_48 -> V_2 ) ;
F_38 ( & V_48 -> V_50 ) ;
F_39 ( V_48 ) ;
}
static struct V_47 *
F_40 ( struct V_51 * V_52 , T_3 V_53 )
{
struct V_47 * V_54 ;
F_41 (pos, &rpci->in_downcall, list) {
if ( V_54 -> V_53 != V_53 )
continue;
F_2 ( & V_54 -> V_3 ) ;
F_28 ( L_2 , V_54 ) ;
return V_54 ;
}
F_28 ( L_3 ) ;
return NULL ;
}
static inline struct V_47 *
F_42 ( struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_55 ;
struct V_55 * V_55 = & V_52 -> V_56 ;
struct V_47 * V_57 ;
F_31 ( & V_55 -> V_58 ) ;
V_57 = F_40 ( V_52 , V_48 -> V_53 ) ;
if ( V_57 == NULL ) {
F_2 ( & V_48 -> V_3 ) ;
F_43 ( & V_48 -> V_49 , & V_52 -> V_59 ) ;
} else
V_48 = V_57 ;
F_32 ( & V_55 -> V_58 ) ;
return V_48 ;
}
static void
F_44 ( struct V_47 * V_48 )
{
F_45 ( & V_48 -> V_49 ) ;
F_46 ( & V_48 -> V_50 , V_48 -> V_60 . V_61 ) ;
F_47 ( & V_48 -> V_62 ) ;
F_48 ( & V_48 -> V_3 ) ;
}
static void
F_49 ( struct V_47 * V_48 )
{
struct V_55 * V_55 = & V_48 -> V_55 -> V_56 ;
if ( F_37 ( & V_48 -> V_49 ) )
return;
F_31 ( & V_55 -> V_58 ) ;
if ( ! F_37 ( & V_48 -> V_49 ) )
F_44 ( V_48 ) ;
F_32 ( & V_55 -> V_58 ) ;
}
static void
F_50 ( struct V_6 * V_6 , struct V_47 * V_48 )
{
switch ( V_48 -> V_60 . V_61 ) {
case 0 :
if ( V_48 -> V_2 == NULL )
break;
F_12 ( V_63 , & V_6 -> V_7 . V_9 ) ;
F_6 ( & V_6 -> V_7 , V_48 -> V_2 ) ;
break;
case - V_39 :
F_10 ( V_63 , & V_6 -> V_7 . V_9 ) ;
}
V_6 -> V_64 = V_36 ;
V_6 -> V_65 = NULL ;
F_46 ( & V_48 -> V_50 , V_48 -> V_60 . V_61 ) ;
}
static void
F_51 ( struct V_66 * V_67 )
{
struct V_6 * V_6 = F_7 ( V_67 -> V_68 -> V_69 ,
struct V_6 , V_7 ) ;
struct V_47 * V_48 = V_6 -> V_65 ;
struct V_55 * V_55 = & V_48 -> V_55 -> V_56 ;
F_31 ( & V_55 -> V_58 ) ;
F_50 ( V_6 , V_48 ) ;
F_32 ( & V_55 -> V_58 ) ;
V_67 -> V_70 = V_48 -> V_60 . V_61 ;
F_35 ( V_48 ) ;
}
static void F_52 ( struct V_47 * V_48 )
{
V_48 -> V_60 . V_20 = & V_48 -> V_53 ;
V_48 -> V_60 . V_15 = sizeof( V_48 -> V_53 ) ;
}
static void F_53 ( struct V_47 * V_48 ,
struct V_71 * V_72 ,
const char * V_73 )
{
struct V_27 * V_74 = V_48 -> V_75 -> V_74 ;
char * V_12 = V_48 -> V_76 ;
int V_15 = 0 ;
V_48 -> V_60 . V_15 = sprintf ( V_48 -> V_76 , L_4 ,
V_74 -> V_77 ,
V_48 -> V_53 ) ;
V_12 += V_48 -> V_60 . V_15 ;
if ( V_72 -> V_78 ) {
V_15 = sprintf ( V_12 , L_5 , V_72 -> V_78 ) ;
V_12 += V_15 ;
V_48 -> V_60 . V_15 += V_15 ;
}
if ( V_73 != NULL ) {
V_15 = sprintf ( V_12 , L_6 , V_73 ) ;
V_12 += V_15 ;
V_48 -> V_60 . V_15 += V_15 ;
}
if ( V_74 -> V_79 ) {
V_15 = sprintf ( V_12 , L_7 , V_74 -> V_79 ) ;
V_12 += V_15 ;
V_48 -> V_60 . V_15 += V_15 ;
}
V_15 = sprintf ( V_12 , L_8 ) ;
V_48 -> V_60 . V_15 += V_15 ;
V_48 -> V_60 . V_20 = V_48 -> V_76 ;
F_36 ( V_48 -> V_60 . V_15 > V_80 ) ;
}
static void F_54 ( struct V_47 * V_48 ,
struct V_71 * V_72 ,
const char * V_73 )
{
if ( V_44 == 0 )
F_52 ( V_48 ) ;
else
F_53 ( V_48 , V_72 , V_73 ) ;
}
static struct V_47 *
F_55 ( struct V_81 * V_81 , struct V_71 * V_72 ,
T_3 V_53 , const char * V_73 )
{
struct V_47 * V_48 ;
int V_82 ;
V_48 = F_23 ( sizeof( * V_48 ) , V_21 ) ;
if ( V_48 == NULL )
return F_15 ( - V_22 ) ;
V_82 = F_30 () ;
if ( V_82 < 0 ) {
F_39 ( V_48 ) ;
return F_15 ( V_82 ) ;
}
V_48 -> V_55 = F_56 ( V_81 -> V_83 [ V_82 ] -> V_84 ) ;
F_57 ( & V_48 -> V_49 ) ;
F_58 ( & V_48 -> V_50 , L_9 ) ;
F_59 ( & V_48 -> V_62 ) ;
F_25 ( & V_48 -> V_3 , 1 ) ;
V_48 -> V_53 = V_53 ;
V_48 -> V_75 = V_81 ;
F_54 ( V_48 , V_72 , V_73 ) ;
return V_48 ;
}
static struct V_47 *
F_60 ( struct V_71 * V_72 , struct V_81 * V_81 , struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_47 * V_85 , * V_48 ;
T_3 V_53 = V_5 -> V_86 ;
V_85 = F_55 ( V_81 , V_72 , V_53 , V_6 -> V_87 ) ;
if ( F_17 ( V_85 ) )
return V_85 ;
V_48 = F_42 ( V_85 ) ;
if ( V_48 == V_85 ) {
struct V_55 * V_55 = & V_85 -> V_55 -> V_56 ;
int V_14 = F_61 ( V_55 , & V_85 -> V_60 ) ;
if ( V_14 ) {
F_49 ( V_85 ) ;
V_48 = F_15 ( V_14 ) ;
}
} else
F_35 ( V_85 ) ;
return V_48 ;
}
static void F_62 ( void )
{
static unsigned long V_88 ;
unsigned long V_89 = V_36 ;
if ( F_63 ( V_89 , V_88 ) ) {
F_64 ( V_90 L_10
L_11 ) ;
V_88 = V_89 + 15 * V_37 ;
}
}
static inline int
F_65 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_81 * V_81 = F_7 ( V_5 -> V_91 ,
struct V_81 , V_92 ) ;
struct V_6 * V_6 = F_7 ( V_5 ,
struct V_6 , V_7 ) ;
struct V_47 * V_48 ;
struct V_55 * V_55 ;
int V_33 = 0 ;
F_28 ( L_12 , V_67 -> V_93 ,
V_5 -> V_86 ) ;
V_48 = F_60 ( V_67 -> V_94 , V_81 , V_5 ) ;
if ( F_29 ( V_48 ) == - V_46 ) {
F_62 () ;
V_67 -> V_95 = 15 * V_37 ;
F_66 ( & V_96 , V_67 , NULL ) ;
return - V_46 ;
}
if ( F_17 ( V_48 ) ) {
V_33 = F_29 ( V_48 ) ;
goto V_97;
}
V_55 = & V_48 -> V_55 -> V_56 ;
F_31 ( & V_55 -> V_58 ) ;
if ( V_6 -> V_65 != NULL )
F_66 ( & V_6 -> V_65 -> V_50 , V_67 , NULL ) ;
else if ( V_48 -> V_2 == NULL && V_48 -> V_60 . V_61 >= 0 ) {
V_67 -> V_95 = 0 ;
V_6 -> V_65 = V_48 ;
F_2 ( & V_48 -> V_3 ) ;
F_66 ( & V_48 -> V_50 , V_67 , F_51 ) ;
} else {
F_50 ( V_6 , V_48 ) ;
V_33 = V_48 -> V_60 . V_61 ;
}
F_32 ( & V_55 -> V_58 ) ;
F_35 ( V_48 ) ;
V_97:
F_28 ( L_13 ,
V_67 -> V_93 , V_5 -> V_86 , V_33 ) ;
return V_33 ;
}
static inline int
F_67 ( struct V_81 * V_81 , struct V_6 * V_6 )
{
struct V_55 * V_55 ;
struct V_4 * V_5 = & V_6 -> V_7 ;
struct V_47 * V_48 ;
F_68 ( V_98 ) ;
int V_33 = 0 ;
F_28 ( L_14 , V_5 -> V_86 ) ;
V_99:
V_48 = F_60 ( V_81 -> V_100 , V_81 , V_5 ) ;
if ( F_29 ( V_48 ) == - V_46 ) {
V_33 = F_69 ( V_101 ,
V_44 >= 0 , 15 * V_37 ) ;
if ( V_44 < 0 ) {
F_62 () ;
V_33 = - V_40 ;
}
if ( V_33 )
goto V_97;
goto V_99;
}
if ( F_17 ( V_48 ) ) {
V_33 = F_29 ( V_48 ) ;
goto V_97;
}
V_55 = & V_48 -> V_55 -> V_56 ;
for (; ; ) {
F_70 ( & V_48 -> V_62 , & V_98 , V_102 ) ;
F_31 ( & V_55 -> V_58 ) ;
if ( V_48 -> V_2 != NULL || V_48 -> V_60 . V_61 < 0 ) {
break;
}
F_32 ( & V_55 -> V_58 ) ;
if ( F_71 ( V_103 ) ) {
V_33 = - V_104 ;
goto V_105;
}
F_72 () ;
}
if ( V_48 -> V_2 )
F_6 ( V_5 , V_48 -> V_2 ) ;
else
V_33 = V_48 -> V_60 . V_61 ;
F_32 ( & V_55 -> V_58 ) ;
V_105:
F_73 ( & V_48 -> V_62 , & V_98 ) ;
F_35 ( V_48 ) ;
V_97:
F_28 ( L_15 ,
V_5 -> V_86 , V_33 ) ;
return V_33 ;
}
static T_4
F_74 ( struct V_106 * V_107 , const char T_5 * V_108 , T_1 V_109 )
{
const void * V_12 , * V_13 ;
void * V_110 ;
struct V_47 * V_48 ;
struct V_55 * V_55 = V_107 -> V_111 . V_83 -> V_84 ;
struct V_1 * V_2 ;
T_3 V_53 ;
T_4 V_33 = - V_112 ;
if ( V_109 > V_113 )
goto V_97;
V_33 = - V_22 ;
V_110 = F_75 ( V_109 , V_21 ) ;
if ( ! V_110 )
goto V_97;
V_33 = - V_17 ;
if ( F_76 ( V_110 , V_108 , V_109 ) )
goto V_33;
V_13 = ( const void * ) ( ( char * ) V_110 + V_109 ) ;
V_12 = F_13 ( V_110 , V_13 , & V_53 , sizeof( V_53 ) ) ;
if ( F_17 ( V_12 ) ) {
V_33 = F_29 ( V_12 ) ;
goto V_33;
}
V_33 = - V_22 ;
V_2 = F_22 () ;
if ( V_2 == NULL )
goto V_33;
V_33 = - V_114 ;
F_31 ( & V_55 -> V_58 ) ;
V_48 = F_40 ( F_56 ( V_55 ) , V_53 ) ;
if ( V_48 == NULL ) {
F_32 ( & V_55 -> V_58 ) ;
goto V_115;
}
F_45 ( & V_48 -> V_49 ) ;
F_32 ( & V_55 -> V_58 ) ;
V_12 = F_26 ( V_12 , V_13 , V_2 , V_48 -> V_75 -> V_74 ) ;
if ( F_17 ( V_12 ) ) {
V_33 = F_29 ( V_12 ) ;
switch ( V_33 ) {
case - V_40 :
case - V_39 :
V_48 -> V_60 . V_61 = V_33 ;
V_33 = V_109 ;
break;
case - V_17 :
case - V_22 :
case - V_116 :
case - V_117 :
V_48 -> V_60 . V_61 = - V_46 ;
break;
default:
F_64 ( V_118 L_16
L_17 , V_119 , V_33 ) ;
F_77 () ;
}
goto V_120;
}
V_48 -> V_2 = F_1 ( V_2 ) ;
V_33 = V_109 ;
V_120:
F_31 ( & V_55 -> V_58 ) ;
F_44 ( V_48 ) ;
F_32 ( & V_55 -> V_58 ) ;
F_35 ( V_48 ) ;
V_115:
F_3 ( V_2 ) ;
V_33:
F_39 ( V_110 ) ;
V_97:
F_28 ( L_18 , V_33 ) ;
return V_33 ;
}
static int F_78 ( struct V_55 * V_55 , int V_121 )
{
int V_32 = 0 ;
F_31 ( & V_43 ) ;
if ( V_44 < 0 ) {
V_44 = V_121 ;
F_79 ( & V_96 ) ;
F_80 ( & V_101 ) ;
} else if ( V_44 != V_121 ) {
V_32 = - V_122 ;
goto V_97;
}
F_2 ( & V_45 ) ;
V_97:
F_32 ( & V_43 ) ;
return V_32 ;
}
static int F_81 ( struct V_55 * V_55 )
{
return F_78 ( V_55 , 0 ) ;
}
static int F_82 ( struct V_55 * V_55 )
{
return F_78 ( V_55 , 1 ) ;
}
static void
F_83 ( struct V_55 * V_55 )
{
struct V_51 * V_52 = F_56 ( V_55 ) ;
struct V_47 * V_48 ;
V_123:
F_31 ( & V_55 -> V_58 ) ;
F_41 (gss_msg, &rpci->in_downcall, list) {
if ( ! F_37 ( & V_48 -> V_60 . V_49 ) )
continue;
V_48 -> V_60 . V_61 = - V_124 ;
F_2 ( & V_48 -> V_3 ) ;
F_44 ( V_48 ) ;
F_32 ( & V_55 -> V_58 ) ;
F_35 ( V_48 ) ;
goto V_123;
}
F_32 ( & V_55 -> V_58 ) ;
F_33 () ;
}
static void
F_84 ( struct V_125 * V_60 )
{
struct V_47 * V_48 = F_7 ( V_60 , struct V_47 , V_60 ) ;
if ( V_60 -> V_61 < 0 ) {
F_28 ( L_19 ,
V_48 ) ;
F_2 ( & V_48 -> V_3 ) ;
F_49 ( V_48 ) ;
if ( V_60 -> V_61 == - V_126 )
F_62 () ;
F_35 ( V_48 ) ;
}
}
static struct V_92 *
F_85 ( struct V_71 * V_72 , T_6 V_127 )
{
struct V_81 * V_81 ;
struct V_92 * V_75 ;
int V_33 = - V_22 ;
F_28 ( L_20 , V_72 ) ;
if ( ! F_86 ( V_128 ) )
return F_15 ( V_33 ) ;
if ( ! ( V_81 = F_75 ( sizeof( * V_81 ) , V_129 ) ) )
goto V_130;
V_81 -> V_100 = V_72 ;
V_33 = - V_116 ;
V_81 -> V_74 = F_87 ( V_127 ) ;
if ( ! V_81 -> V_74 ) {
F_64 ( V_90 L_21 ,
V_119 , V_127 ) ;
goto V_131;
}
V_81 -> V_132 = F_88 ( V_81 -> V_74 , V_127 ) ;
if ( V_81 -> V_132 == 0 )
goto V_133;
V_75 = & V_81 -> V_92 ;
V_75 -> V_134 = V_135 >> 2 ;
V_75 -> V_136 = V_137 >> 2 ;
V_75 -> V_138 = & V_139 ;
V_75 -> V_140 = V_127 ;
F_25 ( & V_75 -> V_141 , 1 ) ;
F_89 ( & V_81 -> V_142 ) ;
V_81 -> V_83 [ 1 ] = F_90 ( V_72 -> V_143 . V_83 ,
L_22 ,
V_72 , & V_144 ,
V_145 ) ;
if ( F_17 ( V_81 -> V_83 [ 1 ] ) ) {
V_33 = F_29 ( V_81 -> V_83 [ 1 ] ) ;
goto V_133;
}
V_81 -> V_83 [ 0 ] = F_90 ( V_72 -> V_143 . V_83 ,
V_81 -> V_74 -> V_77 ,
V_72 , & V_146 ,
V_145 ) ;
if ( F_17 ( V_81 -> V_83 [ 0 ] ) ) {
V_33 = F_29 ( V_81 -> V_83 [ 0 ] ) ;
goto V_147;
}
V_33 = F_91 ( V_75 ) ;
if ( V_33 )
goto V_148;
return V_75 ;
V_148:
F_92 ( V_81 -> V_83 [ 0 ] ) ;
V_147:
F_92 ( V_81 -> V_83 [ 1 ] ) ;
V_133:
F_93 ( V_81 -> V_74 ) ;
V_131:
F_39 ( V_81 ) ;
V_130:
F_94 ( V_128 ) ;
return F_15 ( V_33 ) ;
}
static void
F_95 ( struct V_81 * V_81 )
{
F_92 ( V_81 -> V_83 [ 1 ] ) ;
F_92 ( V_81 -> V_83 [ 0 ] ) ;
F_93 ( V_81 -> V_74 ) ;
F_39 ( V_81 ) ;
F_94 ( V_128 ) ;
}
static void
F_96 ( struct V_142 * V_142 )
{
struct V_81 * V_81 = F_7 ( V_142 , struct V_81 , V_142 ) ;
F_95 ( V_81 ) ;
}
static void
F_97 ( struct V_92 * V_75 )
{
struct V_81 * V_81 ;
F_28 ( L_23 ,
V_75 , V_75 -> V_140 ) ;
F_98 ( V_75 ) ;
V_81 = F_7 ( V_75 , struct V_81 , V_92 ) ;
F_99 ( & V_81 -> V_142 , F_96 ) ;
}
static int
F_100 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_81 * V_81 = F_7 ( V_5 -> V_91 , struct V_81 , V_92 ) ;
struct V_66 * V_67 ;
if ( V_6 -> V_10 == NULL ||
F_8 ( V_11 , & V_5 -> V_9 ) == 0 )
return 0 ;
V_6 -> V_10 -> V_23 = V_149 ;
V_5 -> V_150 = & V_151 ;
F_101 ( V_5 ) ;
V_67 = F_102 ( V_81 -> V_100 , V_5 , V_152 | V_153 ) ;
if ( ! F_17 ( V_67 ) )
F_103 ( V_67 ) ;
F_104 ( V_5 ) ;
return 1 ;
}
static void
F_105 ( struct V_1 * V_2 )
{
F_28 ( L_24 ) ;
F_106 ( & V_2 -> V_42 ) ;
F_39 ( V_2 -> V_41 . V_20 ) ;
F_39 ( V_2 ) ;
}
static void
F_107 ( struct V_154 * V_155 )
{
struct V_1 * V_2 = F_7 ( V_155 , struct V_1 , V_156 ) ;
F_105 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_108 ( & V_2 -> V_156 , F_107 ) ;
}
static void
F_109 ( struct V_6 * V_6 )
{
F_28 ( L_25 , V_6 ) ;
F_39 ( V_6 ) ;
}
static void
F_110 ( struct V_154 * V_155 )
{
struct V_6 * V_6 = F_7 ( V_155 , struct V_6 , V_7 . V_157 ) ;
F_109 ( V_6 ) ;
}
static void
F_111 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
struct V_81 * V_81 = F_7 ( V_5 -> V_91 , struct V_81 , V_92 ) ;
struct V_1 * V_2 = V_6 -> V_10 ;
F_112 ( V_6 -> V_10 , NULL ) ;
F_108 ( & V_5 -> V_157 , F_110 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_99 ( & V_81 -> V_142 , F_96 ) ;
}
static void
F_113 ( struct V_4 * V_5 )
{
if ( F_100 ( V_5 ) )
return;
F_111 ( V_5 ) ;
}
static struct V_4 *
F_114 ( struct V_92 * V_75 , struct V_158 * V_159 , int V_160 )
{
return F_115 ( V_75 , V_159 , V_160 ) ;
}
static struct V_4 *
F_116 ( struct V_92 * V_75 , struct V_158 * V_159 , int V_160 )
{
struct V_81 * V_81 = F_7 ( V_75 , struct V_81 , V_92 ) ;
struct V_6 * V_5 = NULL ;
int V_33 = - V_22 ;
F_28 ( L_26 ,
V_159 -> V_53 , V_75 -> V_140 ) ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_21 ) ) )
goto V_161;
F_117 ( & V_5 -> V_7 , V_159 , V_75 , & V_162 ) ;
V_5 -> V_7 . V_9 = 1UL << V_8 ;
V_5 -> V_163 = V_81 -> V_132 ;
V_5 -> V_87 = NULL ;
if ( V_159 -> V_164 )
V_5 -> V_87 = V_159 -> V_165 ;
F_118 ( & V_81 -> V_142 ) ;
return & V_5 -> V_7 ;
V_161:
F_28 ( L_27 , V_33 ) ;
return F_15 ( V_33 ) ;
}
static int
F_119 ( struct V_92 * V_75 , struct V_4 * V_5 )
{
struct V_81 * V_81 = F_7 ( V_75 , struct V_81 , V_92 ) ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
int V_33 ;
do {
V_33 = F_67 ( V_81 , V_6 ) ;
} while ( V_33 == - V_46 );
return V_33 ;
}
static int
F_120 ( struct V_158 * V_159 , struct V_4 * V_166 , int V_160 )
{
struct V_6 * V_6 = F_7 ( V_166 , struct V_6 , V_7 ) ;
if ( F_8 ( V_8 , & V_166 -> V_9 ) )
goto V_97;
if ( F_63 ( V_36 , V_6 -> V_10 -> V_35 ) )
return 0 ;
if ( ! F_8 ( V_11 , & V_166 -> V_9 ) )
return 0 ;
V_97:
if ( V_159 -> V_165 != NULL ) {
if ( V_6 -> V_87 == NULL )
return 0 ;
return strcmp ( V_159 -> V_165 , V_6 -> V_87 ) == 0 ;
}
if ( V_6 -> V_87 != NULL )
return 0 ;
return V_166 -> V_86 == V_159 -> V_53 ;
}
static T_7 *
F_121 ( struct V_66 * V_67 , T_7 * V_12 )
{
struct V_167 * V_168 = V_67 -> V_68 ;
struct V_4 * V_5 = V_168 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_7 * V_169 ;
T_2 V_170 = 0 ;
struct V_18 V_171 ;
struct V_172 V_173 ;
struct V_174 V_175 ;
F_28 ( L_28 , V_67 -> V_93 ) ;
* V_12 ++ = F_122 ( V_176 ) ;
V_169 = V_12 ++ ;
F_31 ( & V_2 -> V_26 ) ;
V_168 -> V_177 = V_2 -> V_25 ++ ;
F_32 ( & V_2 -> V_26 ) ;
* V_12 ++ = F_122 ( ( T_2 ) V_178 ) ;
* V_12 ++ = F_122 ( ( T_2 ) V_2 -> V_23 ) ;
* V_12 ++ = F_122 ( ( T_2 ) V_168 -> V_177 ) ;
* V_12 ++ = F_122 ( ( T_2 ) V_6 -> V_163 ) ;
V_12 = F_123 ( V_12 , & V_2 -> V_41 ) ;
* V_169 = F_122 ( ( V_12 - ( V_169 + 1 ) ) << 2 ) ;
V_173 . V_179 = F_124 ( V_67 -> V_180 ,
V_168 -> V_181 . V_155 [ 0 ] . V_179 ) ;
V_173 . V_182 = ( V_183 * ) V_12 - ( V_183 * ) V_173 . V_179 ;
F_125 ( & V_173 , & V_175 ) ;
* V_12 ++ = F_122 ( V_176 ) ;
V_171 . V_20 = ( V_183 * ) ( V_12 + 1 ) ;
V_170 = F_126 ( V_2 -> V_42 , & V_175 , & V_171 ) ;
if ( V_170 == V_184 ) {
F_12 ( V_11 , & V_5 -> V_9 ) ;
} else if ( V_170 != 0 ) {
F_64 ( L_29 , V_170 ) ;
goto V_185;
}
V_12 = F_127 ( V_12 , NULL , V_171 . V_15 ) ;
F_3 ( V_2 ) ;
return V_12 ;
V_185:
F_3 ( V_2 ) ;
return NULL ;
}
static int F_128 ( struct V_66 * V_67 )
{
struct V_4 * V_186 = V_67 -> V_68 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_186 ,
struct V_6 ,
V_7 ) ;
struct V_92 * V_75 = V_186 -> V_91 ;
struct V_158 V_159 = {
. V_53 = V_186 -> V_86 ,
. V_165 = V_6 -> V_87 ,
. V_164 = ( V_6 -> V_87 != NULL ? 1 : 0 ) ,
} ;
struct V_4 * V_187 ;
V_187 = F_114 ( V_75 , & V_159 , V_188 ) ;
if ( F_17 ( V_187 ) )
return F_29 ( V_187 ) ;
V_67 -> V_68 -> V_69 = V_187 ;
F_104 ( V_186 ) ;
return 0 ;
}
static int F_129 ( struct V_4 * V_5 )
{
if ( F_8 ( V_63 , & V_5 -> V_9 ) ) {
unsigned long V_89 = V_36 ;
unsigned long V_189 , V_190 ;
struct V_6 * V_6 ;
V_6 = F_7 ( V_5 , struct V_6 , V_7 ) ;
V_189 = V_6 -> V_64 ;
V_190 = V_189 + V_191 * V_37 ;
if ( F_130 ( V_89 , V_189 , V_190 ) )
return 1 ;
}
return 0 ;
}
static int
F_131 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
int V_32 = 0 ;
if ( F_129 ( V_5 ) )
return - V_39 ;
if ( ! F_8 ( V_8 , & V_5 -> V_9 ) &&
! F_8 ( V_11 , & V_5 -> V_9 ) ) {
V_32 = F_128 ( V_67 ) ;
if ( V_32 < 0 )
goto V_97;
V_5 = V_67 -> V_68 -> V_69 ;
}
if ( F_8 ( V_8 , & V_5 -> V_9 ) )
V_32 = F_65 ( V_67 ) ;
V_97:
return V_32 ;
}
static int
F_132 ( struct V_66 * V_67 )
{
return - V_40 ;
}
static T_7 *
F_133 ( struct V_66 * V_67 , T_7 * V_12 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_7 V_192 ;
struct V_172 V_173 ;
struct V_174 V_175 ;
struct V_18 V_171 ;
T_2 V_193 , V_15 ;
T_2 V_170 ;
F_28 ( L_30 , V_67 -> V_93 ) ;
V_193 = F_134 ( * V_12 ++ ) ;
if ( ( V_15 = F_134 ( * V_12 ++ ) ) > V_194 )
goto V_195;
if ( V_193 != V_176 )
goto V_195;
V_192 = F_122 ( V_67 -> V_68 -> V_177 ) ;
V_173 . V_179 = & V_192 ;
V_173 . V_182 = sizeof( V_192 ) ;
F_125 ( & V_173 , & V_175 ) ;
V_171 . V_20 = ( V_183 * ) V_12 ;
V_171 . V_15 = V_15 ;
V_170 = F_135 ( V_2 -> V_42 , & V_175 , & V_171 ) ;
if ( V_170 == V_184 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_170 ) {
F_28 ( L_31
L_32 , V_67 -> V_93 , V_170 ) ;
goto V_195;
}
V_5 -> V_91 -> V_196 = F_136 ( V_15 ) + 2 ;
F_3 ( V_2 ) ;
F_28 ( L_33 ,
V_67 -> V_93 ) ;
return V_12 + F_136 ( V_15 ) ;
V_195:
F_3 ( V_2 ) ;
F_28 ( L_34 , V_67 -> V_93 ) ;
return NULL ;
}
static void F_137 ( T_8 V_197 , struct V_167 * V_198 ,
T_7 * V_12 , void * V_199 )
{
struct V_200 V_201 ;
F_138 ( & V_201 , & V_198 -> V_181 , V_12 ) ;
V_197 ( V_198 , & V_201 , V_199 ) ;
}
static inline int
F_139 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_8 V_197 , struct V_167 * V_198 ,
T_7 * V_12 , void * V_199 )
{
struct V_174 * V_202 = & V_198 -> V_181 ;
struct V_174 V_203 ;
T_7 * V_204 = NULL ;
struct V_18 V_171 ;
T_2 V_205 ;
T_7 * V_16 ;
struct V_172 * V_173 ;
T_2 V_170 = 0 ;
int V_206 = - V_207 ;
V_204 = V_12 ++ ;
V_205 = ( V_183 * ) V_12 - ( V_183 * ) V_202 -> V_155 [ 0 ] . V_179 ;
* V_12 ++ = F_122 ( V_198 -> V_177 ) ;
F_137 ( V_197 , V_198 , V_12 , V_199 ) ;
if ( F_140 ( V_202 , & V_203 ,
V_205 , V_202 -> V_15 - V_205 ) )
return V_206 ;
* V_204 = F_122 ( V_203 . V_15 ) ;
if ( V_202 -> V_208 || V_202 -> V_209 [ 0 ] . V_182 )
V_173 = V_202 -> V_209 ;
else
V_173 = V_202 -> V_155 ;
V_12 = V_173 -> V_179 + V_173 -> V_182 ;
V_171 . V_20 = ( V_183 * ) ( V_12 + 1 ) ;
V_170 = F_126 ( V_2 -> V_42 , & V_203 , & V_171 ) ;
V_206 = - V_207 ;
if ( V_170 == V_184 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_170 )
return V_206 ;
V_16 = F_127 ( V_12 , NULL , V_171 . V_15 ) ;
V_205 = ( V_183 * ) V_16 - ( V_183 * ) V_12 ;
V_173 -> V_182 += V_205 ;
V_202 -> V_15 += V_205 ;
return 0 ;
}
static void
F_141 ( struct V_167 * V_198 )
{
int V_210 ;
for ( V_210 = 0 ; V_210 < V_198 -> V_211 ; V_210 ++ )
F_142 ( V_198 -> V_212 [ V_210 ] ) ;
F_39 ( V_198 -> V_212 ) ;
}
static int
F_143 ( struct V_167 * V_198 )
{
struct V_174 * V_202 = & V_198 -> V_181 ;
int V_213 , V_214 , V_210 ;
if ( V_202 -> V_208 == 0 ) {
V_198 -> V_211 = 0 ;
return 0 ;
}
V_213 = V_202 -> V_215 >> V_216 ;
V_214 = ( V_202 -> V_215 + V_202 -> V_208 - 1 ) >> V_216 ;
V_198 -> V_211 = V_214 - V_213 + 1 + 1 ;
V_198 -> V_212
= F_75 ( V_198 -> V_211 * sizeof( struct V_217 * ) ,
V_21 ) ;
if ( ! V_198 -> V_212 )
goto V_97;
for ( V_210 = 0 ; V_210 < V_198 -> V_211 ; V_210 ++ ) {
V_198 -> V_212 [ V_210 ] = F_144 ( V_21 ) ;
if ( V_198 -> V_212 [ V_210 ] == NULL )
goto V_218;
}
V_198 -> V_219 = F_141 ;
return 0 ;
V_218:
V_198 -> V_211 = V_210 ;
F_141 ( V_198 ) ;
V_97:
return - V_46 ;
}
static inline int
F_145 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_8 V_197 , struct V_167 * V_198 ,
T_7 * V_12 , void * V_199 )
{
struct V_174 * V_202 = & V_198 -> V_181 ;
T_2 V_205 ;
T_2 V_170 ;
int V_206 ;
T_7 * V_220 ;
struct V_217 * * V_221 ;
int V_213 ;
int V_222 ;
struct V_172 * V_173 ;
char * V_223 ;
V_220 = V_12 ++ ;
V_205 = ( V_183 * ) V_12 - ( V_183 * ) V_202 -> V_155 [ 0 ] . V_179 ;
* V_12 ++ = F_122 ( V_198 -> V_177 ) ;
F_137 ( V_197 , V_198 , V_12 , V_199 ) ;
V_206 = F_143 ( V_198 ) ;
if ( V_206 )
return V_206 ;
V_213 = V_202 -> V_215 >> V_216 ;
V_221 = V_202 -> V_224 + V_213 ;
V_202 -> V_224 = V_198 -> V_212 ;
V_202 -> V_215 -= V_213 << V_216 ;
if ( V_202 -> V_208 || V_202 -> V_209 [ 0 ] . V_182 ) {
V_223 = F_146 ( V_198 -> V_212 [ V_198 -> V_211 - 1 ] ) ;
memcpy ( V_223 , V_202 -> V_209 [ 0 ] . V_179 , V_202 -> V_209 [ 0 ] . V_182 ) ;
V_202 -> V_209 [ 0 ] . V_179 = V_223 ;
}
V_170 = F_147 ( V_2 -> V_42 , V_205 , V_202 , V_221 ) ;
F_36 ( V_202 -> V_15 > V_202 -> V_225 ) ;
V_206 = - V_207 ;
if ( V_170 == V_184 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
else if ( V_170 )
return V_206 ;
* V_220 = F_122 ( V_202 -> V_15 - V_205 ) ;
if ( V_202 -> V_208 || V_202 -> V_209 [ 0 ] . V_182 )
V_173 = V_202 -> V_209 ;
else
V_173 = V_202 -> V_155 ;
V_12 = V_173 -> V_179 + V_173 -> V_182 ;
V_222 = 3 - ( ( V_202 -> V_15 - V_205 - 1 ) & 3 ) ;
memset ( V_12 , 0 , V_222 ) ;
V_173 -> V_182 += V_222 ;
V_202 -> V_15 += V_222 ;
return 0 ;
}
static int
F_148 ( struct V_66 * V_67 ,
T_8 V_197 , void * V_198 , T_7 * V_12 , void * V_199 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_206 = - V_207 ;
F_28 ( L_35 , V_67 -> V_93 ) ;
if ( V_2 -> V_23 != V_24 ) {
F_137 ( V_197 , V_198 , V_12 , V_199 ) ;
V_206 = 0 ;
goto V_97;
}
switch ( V_6 -> V_163 ) {
case V_226 :
F_137 ( V_197 , V_198 , V_12 , V_199 ) ;
V_206 = 0 ;
break;
case V_227 :
V_206 = F_139 ( V_5 , V_2 , V_197 , V_198 , V_12 , V_199 ) ;
break;
case V_228 :
V_206 = F_145 ( V_5 , V_2 , V_197 , V_198 , V_12 , V_199 ) ;
break;
}
V_97:
F_3 ( V_2 ) ;
F_28 ( L_36 , V_67 -> V_93 , V_206 ) ;
return V_206 ;
}
static inline int
F_149 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_167 * V_198 , T_7 * * V_12 )
{
struct V_174 * V_229 = & V_198 -> V_230 ;
struct V_174 V_203 ;
struct V_18 V_171 ;
T_2 V_231 , V_232 ;
T_2 V_204 ;
T_2 V_170 ;
int V_206 = - V_207 ;
V_204 = F_134 ( * ( * V_12 ) ++ ) ;
if ( V_204 & 3 )
return V_206 ;
V_231 = ( V_183 * ) ( * V_12 ) - ( V_183 * ) V_229 -> V_155 [ 0 ] . V_179 ;
V_232 = V_204 + V_231 ;
if ( V_232 > V_229 -> V_15 )
return V_206 ;
if ( F_134 ( * ( * V_12 ) ++ ) != V_198 -> V_177 )
return V_206 ;
if ( F_140 ( V_229 , & V_203 , V_231 ,
V_232 - V_231 ) )
return V_206 ;
if ( F_150 ( V_229 , & V_171 , V_232 ) )
return V_206 ;
V_170 = F_135 ( V_2 -> V_42 , & V_203 , & V_171 ) ;
if ( V_170 == V_184 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_170 != V_233 )
return V_206 ;
return 0 ;
}
static inline int
F_151 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_167 * V_198 , T_7 * * V_12 )
{
struct V_174 * V_229 = & V_198 -> V_230 ;
T_2 V_205 ;
T_2 V_220 ;
T_2 V_170 ;
int V_206 = - V_207 ;
V_220 = F_134 ( * ( * V_12 ) ++ ) ;
V_205 = ( V_183 * ) ( * V_12 ) - ( V_183 * ) V_229 -> V_155 [ 0 ] . V_179 ;
if ( V_205 + V_220 > V_229 -> V_15 )
return V_206 ;
V_229 -> V_15 = V_205 + V_220 ;
V_170 = F_152 ( V_2 -> V_42 , V_205 , V_229 ) ;
if ( V_170 == V_184 )
F_12 ( V_11 , & V_5 -> V_9 ) ;
if ( V_170 != V_233 )
return V_206 ;
if ( F_134 ( * ( * V_12 ) ++ ) != V_198 -> V_177 )
return V_206 ;
return 0 ;
}
static int
F_153 ( T_9 V_234 , struct V_167 * V_198 ,
T_7 * V_12 , void * V_199 )
{
struct V_200 V_201 ;
F_154 ( & V_201 , & V_198 -> V_230 , V_12 ) ;
return V_234 ( V_198 , & V_201 , V_199 ) ;
}
static int
F_155 ( struct V_66 * V_67 ,
T_9 V_234 , void * V_198 , T_7 * V_12 , void * V_199 )
{
struct V_4 * V_5 = V_67 -> V_68 -> V_69 ;
struct V_6 * V_6 = F_7 ( V_5 , struct V_6 ,
V_7 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_7 * V_235 = V_12 ;
struct V_172 * V_155 = ( (struct V_167 * ) V_198 ) -> V_230 . V_155 ;
int V_236 = V_155 -> V_182 ;
int V_206 = - V_207 ;
if ( V_2 -> V_23 != V_24 )
goto V_237;
switch ( V_6 -> V_163 ) {
case V_226 :
break;
case V_227 :
V_206 = F_149 ( V_5 , V_2 , V_198 , & V_12 ) ;
if ( V_206 )
goto V_97;
break;
case V_228 :
V_206 = F_151 ( V_5 , V_2 , V_198 , & V_12 ) ;
if ( V_206 )
goto V_97;
break;
}
V_5 -> V_91 -> V_136 = V_5 -> V_91 -> V_196 + ( V_12 - V_235 )
+ ( V_236 - V_155 -> V_182 ) ;
V_237:
V_206 = F_153 ( V_234 , V_198 , V_12 , V_199 ) ;
V_97:
F_3 ( V_2 ) ;
F_28 ( L_37 , V_67 -> V_93 ,
V_206 ) ;
return V_206 ;
}
static int T_10 F_156 ( void )
{
int V_33 = 0 ;
V_33 = F_157 ( & V_139 ) ;
if ( V_33 )
goto V_97;
V_33 = F_158 () ;
if ( V_33 )
goto V_238;
F_58 ( & V_96 , L_38 ) ;
return 0 ;
V_238:
F_159 ( & V_139 ) ;
V_97:
return V_33 ;
}
static void T_11 F_160 ( void )
{
F_161 () ;
F_159 ( & V_139 ) ;
F_162 () ;
}
