int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
V_4 = - V_5 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 -> V_7 == V_2 -> V_7 )
goto V_8;
}
F_4 ( & V_2 -> V_9 , & V_10 ) ;
F_5 ( V_11 L_1 ,
V_2 -> V_12 ) ;
V_4 = 0 ;
V_8:
F_6 ( & V_6 ) ;
return V_4 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
V_4 = 0 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 == V_2 ) {
F_5 ( V_11
L_2 ,
V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_9 ) ;
goto V_8;
}
}
V_4 = - V_13 ;
V_8:
F_6 ( & V_6 ) ;
return V_4 ;
}
int F_9 ( const char * V_14 )
{
struct V_1 * V_3 ;
int V_4 ;
V_4 = 0 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( strcmp ( V_3 -> V_12 , V_14 ) == 0 ) {
F_6 ( & V_6 ) ;
goto V_8;
}
}
F_6 ( & V_6 ) ;
V_4 = F_10 ( L_3 , V_14 ) ;
V_8:
return V_4 ;
}
int F_11 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
int V_22 ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) ) {
if ( V_18 == V_16 -> V_25 )
return 1 ;
goto V_26;
}
V_16 -> V_25 = V_18 ;
if ( V_20 != NULL ) {
V_20 -> V_27 = 0 ;
V_20 -> V_28 ++ ;
}
return 1 ;
V_26:
F_13 ( L_4 ,
V_18 -> V_29 , V_16 ) ;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = - V_32 ;
if ( V_20 == NULL )
V_22 = V_33 ;
else if ( ! V_20 -> V_28 )
V_22 = V_34 ;
else
V_22 = V_35 ;
F_14 ( & V_16 -> V_36 , V_18 , NULL , V_22 ) ;
return 0 ;
}
static void F_15 ( struct V_15 * V_16 )
{
V_16 -> V_25 = NULL ;
if ( ! F_16 ( V_37 , & V_16 -> V_24 ) || V_16 -> V_38 ) {
F_17 () ;
F_18 ( V_23 , & V_16 -> V_24 ) ;
F_19 () ;
} else
F_20 ( V_39 , & V_16 -> V_40 ) ;
}
int F_21 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
int V_22 ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) ) {
if ( V_18 == V_16 -> V_25 )
return 1 ;
goto V_26;
}
if ( V_20 == NULL ) {
V_16 -> V_25 = V_18 ;
return 1 ;
}
if ( F_22 ( V_16 , V_18 ) ) {
V_16 -> V_25 = V_18 ;
V_20 -> V_27 = 0 ;
V_20 -> V_28 ++ ;
return 1 ;
}
F_15 ( V_16 ) ;
V_26:
F_13 ( L_4 , V_18 -> V_29 , V_16 ) ;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = - V_32 ;
if ( V_20 == NULL )
V_22 = V_33 ;
else if ( ! V_20 -> V_28 )
V_22 = V_34 ;
else
V_22 = V_35 ;
F_14 ( & V_16 -> V_36 , V_18 , NULL , V_22 ) ;
return 0 ;
}
static inline int F_23 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_41 ;
F_24 ( & V_16 -> V_42 ) ;
V_41 = V_16 -> V_43 -> V_44 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_42 ) ;
return V_41 ;
}
static bool F_26 ( struct V_17 * V_18 , void * V_45 )
{
struct V_15 * V_16 = V_45 ;
struct V_19 * V_20 ;
V_20 = V_18 -> V_21 ;
V_16 -> V_25 = V_18 ;
if ( V_20 ) {
V_20 -> V_27 = 0 ;
V_20 -> V_28 ++ ;
}
return true ;
}
static void F_27 ( struct V_15 * V_16 )
{
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
return;
if ( F_28 ( & V_16 -> V_36 , F_26 , V_16 ) )
return;
F_15 ( V_16 ) ;
}
static bool F_29 ( struct V_17 * V_18 , void * V_45 )
{
struct V_15 * V_16 = V_45 ;
struct V_19 * V_20 ;
V_20 = V_18 -> V_21 ;
if ( V_20 == NULL ) {
V_16 -> V_25 = V_18 ;
return true ;
}
if ( F_22 ( V_16 , V_18 ) ) {
V_16 -> V_25 = V_18 ;
V_20 -> V_27 = 0 ;
V_20 -> V_28 ++ ;
return true ;
}
return false ;
}
static void F_30 ( struct V_15 * V_16 )
{
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
return;
if ( F_31 ( V_16 ) )
goto V_46;
if ( F_28 ( & V_16 -> V_36 , F_29 , V_16 ) )
return;
V_46:
F_15 ( V_16 ) ;
}
void F_32 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_16 -> V_25 == V_18 ) {
F_15 ( V_16 ) ;
F_27 ( V_16 ) ;
}
}
void F_33 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_16 -> V_25 == V_18 ) {
F_15 ( V_16 ) ;
F_30 ( V_16 ) ;
}
}
static inline void F_34 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
F_24 ( & V_16 -> V_42 ) ;
V_16 -> V_43 -> V_47 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_42 ) ;
}
static int
F_22 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 -> V_48 )
return 1 ;
F_13 ( L_5 ,
V_18 -> V_29 , V_16 -> V_49 , V_16 -> V_50 ) ;
if ( F_31 ( V_16 ) )
return 0 ;
V_20 -> V_48 = 1 ;
V_16 -> V_49 += V_51 ;
return 1 ;
}
static void
F_35 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( ! V_20 -> V_48 )
return;
V_20 -> V_48 = 0 ;
V_16 -> V_49 -= V_51 ;
F_30 ( V_16 ) ;
}
void F_36 ( struct V_17 * V_18 )
{
F_35 ( V_18 -> V_52 , V_18 -> V_21 ) ;
}
void F_37 ( struct V_17 * V_18 , int V_4 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_18 -> V_52 ;
unsigned long V_50 = V_16 -> V_50 ;
if ( V_4 >= 0 && V_50 <= V_16 -> V_49 ) {
V_50 += ( V_51 * V_51 + ( V_50 >> 1 ) ) / V_50 ;
if ( V_50 > F_38 ( V_16 ) )
V_50 = F_38 ( V_16 ) ;
F_30 ( V_16 ) ;
} else if ( V_4 == - V_53 ) {
V_50 >>= 1 ;
if ( V_50 < V_51 )
V_50 = V_51 ;
}
F_13 ( L_6 ,
V_16 -> V_49 , V_16 -> V_50 , V_50 ) ;
V_16 -> V_50 = V_50 ;
F_35 ( V_16 , V_20 ) ;
}
void F_39 ( struct V_15 * V_16 , int V_54 )
{
if ( V_54 < 0 )
F_40 ( & V_16 -> V_55 , V_54 ) ;
else
F_41 ( & V_16 -> V_55 ) ;
}
void F_42 ( struct V_17 * V_18 , T_1 V_56 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_57 ;
V_18 -> V_30 = V_20 -> V_58 ;
F_43 ( & V_16 -> V_55 , V_18 , V_56 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
if ( F_45 ( V_16 -> V_38 ) )
return;
F_24 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_25 ) {
F_13 ( L_7
L_8 , V_16 ) ;
F_46 ( & V_16 -> V_55 , V_16 -> V_25 ) ;
}
F_25 ( & V_16 -> V_42 ) ;
}
void F_47 ( struct V_17 * V_18 )
{
V_18 -> V_30 = V_18 -> V_21 -> V_58 ;
}
void F_48 ( struct V_17 * V_18 )
{
int V_59 = V_18 -> V_60 . V_61 -> V_62 ;
struct V_63 * V_64 = V_18 -> V_65 ;
struct V_66 * V_67 = V_64 -> V_68 ;
struct V_19 * V_20 = V_18 -> V_21 ;
unsigned long V_69 = V_64 -> V_70 -> V_71 ;
V_18 -> V_30 = F_49 ( V_67 , V_59 ) ;
V_18 -> V_30 <<= F_50 ( V_67 , V_59 ) + V_20 -> V_72 ;
if ( V_18 -> V_30 > V_69 || V_18 -> V_30 == 0 )
V_18 -> V_30 = V_69 ;
}
static void F_51 ( struct V_19 * V_20 )
{
const struct V_73 * V_74 = V_20 -> V_75 -> V_65 -> V_70 ;
V_20 -> V_76 = V_20 -> V_58 ;
if ( V_74 -> V_77 )
V_20 -> V_76 <<= V_74 -> V_78 ;
else
V_20 -> V_76 += V_74 -> V_79 * V_74 -> V_78 ;
if ( V_20 -> V_76 > V_74 -> V_71 || V_20 -> V_76 == 0 )
V_20 -> V_76 = V_74 -> V_71 ;
V_20 -> V_76 += V_80 ;
}
int F_52 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_57 ;
const struct V_73 * V_74 = V_20 -> V_75 -> V_65 -> V_70 ;
int V_54 = 0 ;
if ( F_53 ( V_80 , V_20 -> V_76 ) ) {
if ( V_74 -> V_77 )
V_20 -> V_58 <<= 1 ;
else
V_20 -> V_58 += V_74 -> V_79 ;
if ( V_74 -> V_71 && V_20 -> V_58 >= V_74 -> V_71 )
V_20 -> V_58 = V_74 -> V_71 ;
V_20 -> V_72 ++ ;
} else {
V_20 -> V_58 = V_74 -> V_81 ;
V_20 -> V_72 = 0 ;
F_51 ( V_20 ) ;
F_24 ( & V_16 -> V_42 ) ;
F_54 ( V_20 -> V_75 -> V_65 -> V_68 , V_74 -> V_81 ) ;
F_25 ( & V_16 -> V_42 ) ;
V_54 = - V_53 ;
}
if ( V_20 -> V_58 == 0 ) {
F_5 ( V_82 L_9 ) ;
V_20 -> V_58 = 5 * V_83 ;
}
return V_54 ;
}
static void F_55 ( struct V_84 * V_85 )
{
struct V_15 * V_16 =
F_56 ( V_85 , struct V_15 , V_40 ) ;
V_16 -> V_43 -> V_86 ( V_16 ) ;
F_18 ( V_37 , & V_16 -> V_24 ) ;
F_34 ( V_16 , NULL ) ;
}
void F_57 ( struct V_15 * V_16 )
{
F_13 ( L_10 , V_16 ) ;
F_24 ( & V_16 -> V_42 ) ;
F_58 ( V_16 ) ;
F_39 ( V_16 , - V_32 ) ;
F_25 ( & V_16 -> V_42 ) ;
}
void F_59 ( struct V_15 * V_16 )
{
F_24 ( & V_16 -> V_42 ) ;
F_60 ( V_37 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_39 , & V_16 -> V_40 ) ;
F_39 ( V_16 , - V_32 ) ;
F_25 ( & V_16 -> V_42 ) ;
}
void F_61 ( struct V_15 * V_16 , unsigned int V_87 )
{
F_24 ( & V_16 -> V_42 ) ;
if ( V_87 != V_16 -> V_88 )
goto V_8;
if ( F_16 ( V_89 , & V_16 -> V_24 ) || ! F_62 ( V_16 ) )
goto V_8;
F_60 ( V_37 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_39 , & V_16 -> V_40 ) ;
F_39 ( V_16 , - V_32 ) ;
V_8:
F_25 ( & V_16 -> V_42 ) ;
}
static void
F_63 ( unsigned long V_45 )
{
struct V_15 * V_16 = (struct V_15 * ) V_45 ;
F_2 ( & V_16 -> V_42 ) ;
if ( ! F_64 ( & V_16 -> V_90 ) || V_16 -> V_38 )
goto V_91;
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
goto V_91;
F_6 ( & V_16 -> V_42 ) ;
F_60 ( V_92 , & V_16 -> V_24 ) ;
F_20 ( V_39 , & V_16 -> V_40 ) ;
return;
V_91:
F_6 ( & V_16 -> V_42 ) ;
}
void F_65 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_52 ;
F_13 ( L_11 , V_18 -> V_29 ,
V_16 , ( F_62 ( V_16 ) ? L_12 : L_13 ) ) ;
if ( ! F_66 ( V_16 ) ) {
V_18 -> V_31 = - V_32 ;
return;
}
if ( ! F_23 ( V_16 , V_18 ) )
return;
if ( F_67 ( V_37 , & V_16 -> V_24 ) )
V_16 -> V_43 -> V_86 ( V_16 ) ;
if ( F_62 ( V_16 ) )
F_34 ( V_16 , V_18 ) ;
else {
V_18 -> V_21 -> V_27 = 0 ;
V_18 -> V_30 = V_18 -> V_21 -> V_58 ;
F_43 ( & V_16 -> V_55 , V_18 , V_93 ) ;
if ( F_16 ( V_89 , & V_16 -> V_24 ) )
return;
if ( F_68 ( V_16 ) )
return;
V_16 -> V_94 . V_95 = V_80 ;
V_16 -> V_43 -> V_96 ( V_18 ) ;
}
}
static void V_93 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_52 ;
if ( V_18 -> V_31 == 0 ) {
V_16 -> V_94 . V_97 ++ ;
V_16 -> V_94 . V_98 += ( long ) V_80 - V_16 -> V_94 . V_95 ;
F_13 ( L_14 ,
V_18 -> V_29 ) ;
return;
}
switch ( V_18 -> V_31 ) {
case - V_32 :
F_13 ( L_15 , V_18 -> V_29 ) ;
break;
case - V_53 :
F_13 ( L_16
L_17 , V_18 -> V_29 ) ;
break;
default:
F_13 ( L_18
L_19 , V_18 -> V_29 , - V_18 -> V_31 ,
V_16 -> V_99 ) ;
F_34 ( V_16 , V_18 ) ;
V_18 -> V_31 = - V_100 ;
}
}
struct V_19 * F_69 ( struct V_15 * V_16 , T_2 V_101 )
{
struct V_19 * V_102 ;
F_3 (entry, &xprt->recv, rq_list)
if ( V_102 -> V_103 == V_101 )
return V_102 ;
F_13 ( L_20 ,
F_70 ( V_101 ) ) ;
V_16 -> V_94 . V_104 ++ ;
return NULL ;
}
static void F_71 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_66 * V_67 = V_18 -> V_65 -> V_68 ;
unsigned int V_59 = V_18 -> V_60 . V_61 -> V_62 ;
long V_105 = F_72 ( F_73 ( V_20 -> V_106 ) ) ;
if ( V_59 ) {
if ( V_20 -> V_28 == 1 )
F_74 ( V_67 , V_59 , V_105 ) ;
F_75 ( V_67 , V_59 , V_20 -> V_28 - 1 ) ;
}
}
void F_76 ( struct V_17 * V_18 , int V_107 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_57 ;
F_13 ( L_21 ,
V_18 -> V_29 , F_70 ( V_20 -> V_103 ) , V_107 ) ;
V_16 -> V_94 . V_108 ++ ;
V_20 -> V_106 = F_77 ( F_78 () , V_20 -> V_109 ) ;
if ( V_16 -> V_43 -> V_59 != NULL )
F_71 ( V_18 ) ;
F_8 ( & V_20 -> V_110 ) ;
V_20 -> V_111 . V_112 = V_107 ;
F_79 () ;
V_20 -> V_113 = V_107 ;
F_46 ( & V_16 -> V_55 , V_18 ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_57 ;
if ( V_18 -> V_31 != - V_53 )
return;
F_13 ( L_22 , V_18 -> V_29 ) ;
F_24 ( & V_16 -> V_42 ) ;
if ( ! V_20 -> V_113 ) {
if ( V_16 -> V_43 -> V_59 )
V_16 -> V_43 -> V_59 ( V_18 ) ;
} else
V_18 -> V_31 = 0 ;
F_25 ( & V_16 -> V_42 ) ;
}
static inline int F_81 ( struct V_15 * V_16 )
{
return V_16 -> V_114 != 0 ;
}
int F_82 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_57 ;
int V_115 = 0 ;
F_13 ( L_23 , V_18 -> V_29 ) ;
F_24 ( & V_16 -> V_42 ) ;
if ( V_20 -> V_113 && ! V_20 -> V_27 ) {
V_115 = V_20 -> V_113 ;
goto V_46;
}
if ( ! V_16 -> V_43 -> V_44 ( V_16 , V_18 ) )
V_115 = - V_32 ;
V_46:
F_25 ( & V_16 -> V_42 ) ;
return V_115 ;
}
void F_83 ( struct V_17 * V_18 )
{
F_34 ( V_18 -> V_21 -> V_57 , V_18 ) ;
}
void F_84 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_57 ;
int V_54 , V_116 ;
F_13 ( L_24 , V_18 -> V_29 , V_20 -> V_117 ) ;
if ( ! V_20 -> V_113 ) {
if ( F_64 ( & V_20 -> V_110 ) && F_85 ( V_18 ) ) {
F_24 ( & V_16 -> V_42 ) ;
memcpy ( & V_20 -> V_111 , & V_20 -> V_118 ,
sizeof( V_20 -> V_111 ) ) ;
F_4 ( & V_20 -> V_110 , & V_16 -> V_90 ) ;
F_25 ( & V_16 -> V_42 ) ;
F_51 ( V_20 ) ;
F_86 ( & V_16 -> V_59 ) ;
}
} else if ( ! V_20 -> V_27 )
return;
V_20 -> V_119 = V_16 -> V_88 ;
V_20 -> V_109 = F_78 () ;
V_54 = V_16 -> V_43 -> V_120 ( V_18 ) ;
if ( V_54 != 0 ) {
V_18 -> V_31 = V_54 ;
return;
}
F_13 ( L_25 , V_18 -> V_29 ) ;
V_18 -> V_121 |= V_122 ;
F_24 ( & V_16 -> V_42 ) ;
V_16 -> V_43 -> V_123 ( V_18 ) ;
V_116 = F_87 ( & V_16 -> V_124 ) ;
if ( V_116 > V_16 -> V_94 . V_125 )
V_16 -> V_94 . V_125 = V_116 ;
V_16 -> V_94 . V_126 ++ ;
V_16 -> V_94 . V_127 += V_16 -> V_94 . V_126 - V_16 -> V_94 . V_108 ;
V_16 -> V_94 . V_128 += V_16 -> V_129 . V_130 ;
V_16 -> V_94 . V_131 += V_16 -> V_36 . V_130 ;
V_16 -> V_94 . V_132 += V_16 -> V_55 . V_130 ;
if ( ! F_62 ( V_16 ) )
V_18 -> V_31 = - V_133 ;
else if ( ! V_20 -> V_113 && F_85 ( V_18 ) ) {
F_43 ( & V_16 -> V_55 , V_18 , F_80 ) ;
}
F_25 ( & V_16 -> V_42 ) ;
}
static struct V_19 * F_88 ( struct V_15 * V_16 , T_3 V_134 )
{
struct V_19 * V_20 = F_89 ( - V_32 ) ;
if ( ! F_90 ( & V_16 -> V_124 , 1 , V_16 -> V_135 ) )
goto V_8;
V_20 = F_91 ( sizeof( struct V_19 ) , V_134 ) ;
if ( V_20 != NULL )
goto V_8;
F_92 ( & V_16 -> V_124 ) ;
V_20 = F_89 ( - V_136 ) ;
V_8:
return V_20 ;
}
static bool F_93 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( F_90 ( & V_16 -> V_124 , - 1 , V_16 -> V_137 ) ) {
F_94 ( V_20 ) ;
return true ;
}
return false ;
}
void F_95 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_2 ( & V_16 -> V_138 ) ;
if ( ! F_64 ( & V_16 -> free ) ) {
V_20 = F_96 ( V_16 -> free . V_139 , struct V_19 , V_110 ) ;
F_97 ( & V_20 -> V_110 ) ;
goto V_140;
}
V_20 = F_88 ( V_16 , V_141 | V_142 ) ;
if ( ! F_98 ( V_20 ) )
goto V_140;
switch ( F_99 ( V_20 ) ) {
case - V_136 :
F_13 ( L_26
L_27 ) ;
V_18 -> V_31 = - V_136 ;
break;
case - V_32 :
F_43 ( & V_16 -> V_129 , V_18 , NULL ) ;
F_13 ( L_28 ) ;
default:
V_18 -> V_31 = - V_32 ;
}
F_6 ( & V_16 -> V_138 ) ;
return;
V_140:
V_18 -> V_31 = 0 ;
V_18 -> V_21 = V_20 ;
F_100 ( V_18 , V_16 ) ;
F_6 ( & V_16 -> V_138 ) ;
}
void F_101 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( F_23 ( V_16 , V_18 ) ) {
F_95 ( V_16 , V_18 ) ;
F_34 ( V_16 , V_18 ) ;
}
}
static void F_102 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
F_2 ( & V_16 -> V_138 ) ;
if ( ! F_93 ( V_16 , V_20 ) ) {
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
F_103 ( & V_20 -> V_110 , & V_16 -> free ) ;
}
F_104 ( & V_16 -> V_129 ) ;
F_6 ( & V_16 -> V_138 ) ;
}
static void F_105 ( struct V_15 * V_16 )
{
struct V_19 * V_20 ;
while ( ! F_64 ( & V_16 -> free ) ) {
V_20 = F_106 ( & V_16 -> free , struct V_19 , V_110 ) ;
F_97 ( & V_20 -> V_110 ) ;
F_94 ( V_20 ) ;
}
}
struct V_15 * F_107 ( struct V_143 * V_143 , T_4 V_144 ,
unsigned int V_145 ,
unsigned int V_146 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_147 ;
V_16 = F_91 ( V_144 , V_148 ) ;
if ( V_16 == NULL )
goto V_8;
F_108 ( V_16 , V_143 ) ;
for ( V_147 = 0 ; V_147 < V_145 ; V_147 ++ ) {
V_20 = F_91 ( sizeof( struct V_19 ) , V_148 ) ;
if ( ! V_20 )
break;
F_103 ( & V_20 -> V_110 , & V_16 -> free ) ;
}
if ( V_147 < V_145 )
goto V_149;
if ( V_146 > V_145 )
V_16 -> V_135 = V_146 ;
else
V_16 -> V_135 = V_145 ;
V_16 -> V_137 = V_145 ;
F_109 ( & V_16 -> V_124 , V_145 ) ;
return V_16 ;
V_149:
F_110 ( V_16 ) ;
V_8:
return NULL ;
}
void F_110 ( struct V_15 * V_16 )
{
F_111 ( V_16 -> V_150 ) ;
F_105 ( V_16 ) ;
F_94 ( V_16 ) ;
}
void F_112 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_52 ;
V_18 -> V_31 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = - V_32 ;
V_16 -> V_43 -> V_151 ( V_16 , V_18 ) ;
}
static inline T_2 F_113 ( struct V_15 * V_16 )
{
return ( V_152 T_2 ) V_16 -> V_101 ++ ;
}
static inline void F_114 ( struct V_15 * V_16 )
{
V_16 -> V_101 = F_115 () ;
}
static void F_100 ( struct V_17 * V_18 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
F_116 ( & V_20 -> V_110 ) ;
V_20 -> V_58 = V_18 -> V_65 -> V_70 -> V_81 ;
V_20 -> V_75 = V_18 ;
V_20 -> V_57 = V_16 ;
V_20 -> V_153 = NULL ;
V_20 -> V_103 = F_113 ( V_16 ) ;
V_20 -> V_154 = NULL ;
F_51 ( V_20 ) ;
F_13 ( L_29 , V_18 -> V_29 ,
V_20 , F_70 ( V_20 -> V_103 ) ) ;
}
void F_117 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
if ( ! ( V_20 = V_18 -> V_21 ) )
return;
V_16 = V_20 -> V_57 ;
if ( V_18 -> V_155 -> V_156 != NULL )
V_18 -> V_155 -> V_156 ( V_18 , V_18 -> V_157 ) ;
else if ( V_18 -> V_65 )
F_118 ( V_18 , V_18 -> V_65 -> V_158 ) ;
F_24 ( & V_16 -> V_42 ) ;
V_16 -> V_43 -> V_47 ( V_16 , V_18 ) ;
if ( V_16 -> V_43 -> V_159 )
V_16 -> V_43 -> V_159 ( V_18 ) ;
if ( ! F_64 ( & V_20 -> V_110 ) )
F_97 ( & V_20 -> V_110 ) ;
V_16 -> V_160 = V_80 ;
if ( F_64 ( & V_16 -> V_90 ) && F_81 ( V_16 ) )
F_119 ( & V_16 -> V_59 ,
V_16 -> V_160 + V_16 -> V_114 ) ;
F_25 ( & V_16 -> V_42 ) ;
if ( V_20 -> V_153 )
V_16 -> V_43 -> V_161 ( V_20 -> V_153 ) ;
if ( V_20 -> V_162 != NULL )
F_120 ( V_20 -> V_162 ) ;
V_18 -> V_21 = NULL ;
if ( V_20 -> V_154 )
V_20 -> V_154 ( V_20 ) ;
F_13 ( L_30 , V_18 -> V_29 , V_20 ) ;
if ( F_121 ( ! F_122 ( V_20 ) ) )
F_102 ( V_16 , V_20 ) ;
else
F_123 ( V_20 ) ;
}
static void F_108 ( struct V_15 * V_16 , struct V_143 * V_143 )
{
F_109 ( & V_16 -> V_163 , 1 ) ;
F_124 ( & V_16 -> V_42 ) ;
F_124 ( & V_16 -> V_138 ) ;
F_116 ( & V_16 -> free ) ;
F_116 ( & V_16 -> V_90 ) ;
#if F_125 ( V_164 )
F_124 ( & V_16 -> V_165 ) ;
F_116 ( & V_16 -> V_166 ) ;
#endif
V_16 -> V_160 = V_80 ;
V_16 -> V_50 = V_167 ;
V_16 -> V_168 = 0 ;
F_126 ( & V_16 -> V_169 , L_31 ) ;
F_126 ( & V_16 -> V_55 , L_32 ) ;
F_127 ( & V_16 -> V_36 , L_33 ) ;
F_127 ( & V_16 -> V_129 , L_34 ) ;
F_114 ( V_16 ) ;
V_16 -> V_150 = F_128 ( V_143 ) ;
}
struct V_15 * F_129 ( struct V_170 * args )
{
struct V_15 * V_16 ;
struct V_1 * V_3 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 -> V_7 == args -> V_7 ) {
F_6 ( & V_6 ) ;
goto V_171;
}
}
F_6 ( & V_6 ) ;
F_5 ( V_172 L_35 , args -> V_7 ) ;
return F_89 ( - V_100 ) ;
V_171:
V_16 = V_3 -> V_173 ( args ) ;
if ( F_98 ( V_16 ) ) {
F_13 ( L_36 ,
- F_99 ( V_16 ) ) ;
goto V_8;
}
F_130 ( & V_16 -> V_40 , F_55 ) ;
if ( F_81 ( V_16 ) )
F_131 ( & V_16 -> V_59 , F_63 ,
( unsigned long ) V_16 ) ;
else
F_132 ( & V_16 -> V_59 ) ;
if ( strlen ( args -> V_99 ) > V_174 ) {
F_133 ( V_16 ) ;
return F_89 ( - V_175 ) ;
}
V_16 -> V_99 = F_134 ( args -> V_99 , V_148 ) ;
if ( V_16 -> V_99 == NULL ) {
F_133 ( V_16 ) ;
return F_89 ( - V_136 ) ;
}
F_13 ( L_37 , V_16 ,
V_16 -> V_135 ) ;
V_8:
return V_16 ;
}
static void F_133 ( struct V_15 * V_16 )
{
F_13 ( L_38 , V_16 ) ;
V_16 -> V_38 = 1 ;
F_135 ( & V_16 -> V_59 ) ;
F_136 ( & V_16 -> V_169 ) ;
F_136 ( & V_16 -> V_55 ) ;
F_136 ( & V_16 -> V_36 ) ;
F_136 ( & V_16 -> V_129 ) ;
F_137 ( & V_16 -> V_40 ) ;
F_94 ( V_16 -> V_99 ) ;
V_16 -> V_43 -> V_176 ( V_16 ) ;
}
void F_138 ( struct V_15 * V_16 )
{
if ( F_139 ( & V_16 -> V_163 ) )
F_133 ( V_16 ) ;
}
struct V_15 * F_140 ( struct V_15 * V_16 )
{
if ( F_141 ( & V_16 -> V_163 ) )
return V_16 ;
return NULL ;
}
