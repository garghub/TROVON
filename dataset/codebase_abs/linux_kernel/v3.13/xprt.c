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
if ( V_20 != NULL )
V_20 -> V_27 ++ ;
return 1 ;
V_26:
F_13 ( L_4 ,
V_18 -> V_28 , V_16 ) ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - V_31 ;
if ( V_20 == NULL )
V_22 = V_32 ;
else if ( ! V_20 -> V_27 )
V_22 = V_33 ;
else
V_22 = V_34 ;
F_14 ( & V_16 -> V_35 , V_18 , NULL , V_22 ) ;
return 0 ;
}
static void F_15 ( struct V_15 * V_16 )
{
V_16 -> V_25 = NULL ;
if ( ! F_16 ( V_36 , & V_16 -> V_24 ) ) {
F_17 () ;
F_18 ( V_23 , & V_16 -> V_24 ) ;
F_19 () ;
} else
F_20 ( V_37 , & V_16 -> V_38 ) ;
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
V_20 -> V_27 ++ ;
return 1 ;
}
F_15 ( V_16 ) ;
V_26:
F_13 ( L_4 , V_18 -> V_28 , V_16 ) ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - V_31 ;
if ( V_20 == NULL )
V_22 = V_32 ;
else if ( ! V_20 -> V_27 )
V_22 = V_33 ;
else
V_22 = V_34 ;
F_14 ( & V_16 -> V_35 , V_18 , NULL , V_22 ) ;
return 0 ;
}
static inline int F_23 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_39 ;
F_24 ( & V_16 -> V_40 ) ;
V_39 = V_16 -> V_41 -> V_42 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_40 ) ;
return V_39 ;
}
static bool F_26 ( struct V_17 * V_18 , void * V_43 )
{
struct V_15 * V_16 = V_43 ;
struct V_19 * V_20 ;
V_20 = V_18 -> V_21 ;
V_16 -> V_25 = V_18 ;
if ( V_20 )
V_20 -> V_27 ++ ;
return true ;
}
static void F_27 ( struct V_15 * V_16 )
{
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
return;
if ( F_28 ( & V_16 -> V_35 , F_26 , V_16 ) )
return;
F_15 ( V_16 ) ;
}
static bool F_29 ( struct V_17 * V_18 , void * V_43 )
{
struct V_15 * V_16 = V_43 ;
struct V_19 * V_20 ;
V_20 = V_18 -> V_21 ;
if ( V_20 == NULL ) {
V_16 -> V_25 = V_18 ;
return true ;
}
if ( F_22 ( V_16 , V_18 ) ) {
V_16 -> V_25 = V_18 ;
V_20 -> V_27 ++ ;
return true ;
}
return false ;
}
static void F_30 ( struct V_15 * V_16 )
{
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
return;
if ( F_31 ( V_16 ) )
goto V_44;
if ( F_28 ( & V_16 -> V_35 , F_29 , V_16 ) )
return;
V_44:
F_15 ( V_16 ) ;
}
void F_32 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_16 -> V_25 == V_18 ) {
if ( V_18 != NULL ) {
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 != NULL )
V_20 -> V_45 = 0 ;
}
F_15 ( V_16 ) ;
F_27 ( V_16 ) ;
}
}
void F_33 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_16 -> V_25 == V_18 ) {
if ( V_18 != NULL ) {
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 != NULL )
V_20 -> V_45 = 0 ;
}
F_15 ( V_16 ) ;
F_30 ( V_16 ) ;
}
}
static inline void F_34 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
F_24 ( & V_16 -> V_40 ) ;
V_16 -> V_41 -> V_46 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_40 ) ;
}
static int
F_22 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 -> V_47 )
return 1 ;
F_13 ( L_5 ,
V_18 -> V_28 , V_16 -> V_48 , V_16 -> V_49 ) ;
if ( F_31 ( V_16 ) )
return 0 ;
V_20 -> V_47 = 1 ;
V_16 -> V_48 += V_50 ;
return 1 ;
}
static void
F_35 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( ! V_20 -> V_47 )
return;
V_20 -> V_47 = 0 ;
V_16 -> V_48 -= V_50 ;
F_30 ( V_16 ) ;
}
void F_36 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
F_35 ( V_20 -> V_51 , V_20 ) ;
}
void F_37 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_4 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
unsigned long V_49 = V_16 -> V_49 ;
if ( V_4 >= 0 && V_49 <= V_16 -> V_48 ) {
V_49 += ( V_50 * V_50 + ( V_49 >> 1 ) ) / V_49 ;
if ( V_49 > F_38 ( V_16 ) )
V_49 = F_38 ( V_16 ) ;
F_30 ( V_16 ) ;
} else if ( V_4 == - V_52 ) {
V_49 >>= 1 ;
if ( V_49 < V_50 )
V_49 = V_50 ;
}
F_13 ( L_6 ,
V_16 -> V_48 , V_16 -> V_49 , V_49 ) ;
V_16 -> V_49 = V_49 ;
F_35 ( V_16 , V_20 ) ;
}
void F_39 ( struct V_15 * V_16 , int V_53 )
{
if ( V_53 < 0 )
F_40 ( & V_16 -> V_54 , V_53 ) ;
else
F_41 ( & V_16 -> V_54 ) ;
}
void F_42 ( struct V_17 * V_18 , T_1 V_55 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
V_18 -> V_29 = F_43 ( V_18 ) ? V_20 -> V_56 : 0 ;
F_44 ( & V_16 -> V_54 , V_18 , V_55 ) ;
}
void F_45 ( struct V_15 * V_16 )
{
F_24 ( & V_16 -> V_40 ) ;
if ( V_16 -> V_25 ) {
F_13 ( L_7
L_8 , V_16 ) ;
F_46 ( & V_16 -> V_54 , V_16 -> V_25 ) ;
}
F_25 ( & V_16 -> V_40 ) ;
}
void F_47 ( struct V_17 * V_18 )
{
V_18 -> V_29 = V_18 -> V_21 -> V_56 ;
}
void F_48 ( struct V_17 * V_18 )
{
int V_57 = V_18 -> V_58 . V_59 -> V_60 ;
struct V_61 * V_62 = V_18 -> V_63 ;
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_19 * V_20 = V_18 -> V_21 ;
unsigned long V_67 = V_62 -> V_68 -> V_69 ;
V_18 -> V_29 = F_49 ( V_65 , V_57 ) ;
V_18 -> V_29 <<= F_50 ( V_65 , V_57 ) + V_20 -> V_70 ;
if ( V_18 -> V_29 > V_67 || V_18 -> V_29 == 0 )
V_18 -> V_29 = V_67 ;
}
static void F_51 ( struct V_19 * V_20 )
{
const struct V_71 * V_72 = V_20 -> V_73 -> V_63 -> V_68 ;
V_20 -> V_74 = V_20 -> V_56 ;
if ( V_72 -> V_75 )
V_20 -> V_74 <<= V_72 -> V_76 ;
else
V_20 -> V_74 += V_72 -> V_77 * V_72 -> V_76 ;
if ( V_20 -> V_74 > V_72 -> V_69 || V_20 -> V_74 == 0 )
V_20 -> V_74 = V_72 -> V_69 ;
V_20 -> V_74 += V_78 ;
}
int F_52 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_51 ;
const struct V_71 * V_72 = V_20 -> V_73 -> V_63 -> V_68 ;
int V_53 = 0 ;
if ( F_53 ( V_78 , V_20 -> V_74 ) ) {
if ( V_72 -> V_75 )
V_20 -> V_56 <<= 1 ;
else
V_20 -> V_56 += V_72 -> V_77 ;
if ( V_72 -> V_69 && V_20 -> V_56 >= V_72 -> V_69 )
V_20 -> V_56 = V_72 -> V_69 ;
V_20 -> V_70 ++ ;
} else {
V_20 -> V_56 = V_72 -> V_79 ;
V_20 -> V_70 = 0 ;
F_51 ( V_20 ) ;
F_24 ( & V_16 -> V_40 ) ;
F_54 ( V_20 -> V_73 -> V_63 -> V_66 , V_72 -> V_79 ) ;
F_25 ( & V_16 -> V_40 ) ;
V_53 = - V_52 ;
}
if ( V_20 -> V_56 == 0 ) {
F_5 ( V_80 L_9 ) ;
V_20 -> V_56 = 5 * V_81 ;
}
return V_53 ;
}
static void F_55 ( struct V_82 * V_83 )
{
struct V_15 * V_16 =
F_56 ( V_83 , struct V_15 , V_38 ) ;
V_16 -> V_41 -> V_84 ( V_16 ) ;
F_18 ( V_36 , & V_16 -> V_24 ) ;
F_34 ( V_16 , NULL ) ;
}
void F_57 ( struct V_15 * V_16 )
{
F_13 ( L_10 , V_16 ) ;
F_24 ( & V_16 -> V_40 ) ;
F_58 ( V_16 ) ;
F_39 ( V_16 , - V_31 ) ;
F_25 ( & V_16 -> V_40 ) ;
}
void F_59 ( struct V_15 * V_16 )
{
F_24 ( & V_16 -> V_40 ) ;
F_60 ( V_36 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_37 , & V_16 -> V_38 ) ;
F_39 ( V_16 , - V_31 ) ;
F_25 ( & V_16 -> V_40 ) ;
}
void F_61 ( struct V_15 * V_16 , unsigned int V_85 )
{
F_24 ( & V_16 -> V_40 ) ;
if ( V_85 != V_16 -> V_86 )
goto V_8;
if ( F_16 ( V_87 , & V_16 -> V_24 ) || ! F_62 ( V_16 ) )
goto V_8;
F_60 ( V_36 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_37 , & V_16 -> V_38 ) ;
F_39 ( V_16 , - V_31 ) ;
V_8:
F_25 ( & V_16 -> V_40 ) ;
}
static void
F_63 ( unsigned long V_43 )
{
struct V_15 * V_16 = (struct V_15 * ) V_43 ;
F_2 ( & V_16 -> V_40 ) ;
if ( ! F_64 ( & V_16 -> V_88 ) )
goto V_89;
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
goto V_89;
F_6 ( & V_16 -> V_40 ) ;
F_60 ( V_90 , & V_16 -> V_24 ) ;
F_20 ( V_37 , & V_16 -> V_38 ) ;
return;
V_89:
F_6 ( & V_16 -> V_40 ) ;
}
void F_65 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_21 -> V_51 ;
F_13 ( L_11 , V_18 -> V_28 ,
V_16 , ( F_62 ( V_16 ) ? L_12 : L_13 ) ) ;
if ( ! F_66 ( V_16 ) ) {
V_18 -> V_30 = - V_31 ;
return;
}
if ( ! F_23 ( V_16 , V_18 ) )
return;
if ( F_67 ( V_36 , & V_16 -> V_24 ) )
V_16 -> V_41 -> V_84 ( V_16 ) ;
if ( F_62 ( V_16 ) )
F_34 ( V_16 , V_18 ) ;
else {
V_18 -> V_21 -> V_45 = 0 ;
V_18 -> V_29 = V_18 -> V_21 -> V_56 ;
F_44 ( & V_16 -> V_54 , V_18 , V_91 ) ;
if ( F_16 ( V_87 , & V_16 -> V_24 ) )
return;
if ( F_68 ( V_16 ) )
return;
V_16 -> V_92 . V_93 = V_78 ;
V_16 -> V_41 -> V_94 ( V_16 , V_18 ) ;
}
}
static void V_91 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_21 -> V_51 ;
if ( V_18 -> V_30 == 0 ) {
V_16 -> V_92 . V_95 ++ ;
V_16 -> V_92 . V_96 += ( long ) V_78 - V_16 -> V_92 . V_93 ;
F_13 ( L_14 ,
V_18 -> V_28 ) ;
return;
}
switch ( V_18 -> V_30 ) {
case - V_31 :
F_13 ( L_15 , V_18 -> V_28 ) ;
break;
case - V_52 :
F_13 ( L_16
L_17 , V_18 -> V_28 ) ;
break;
default:
F_13 ( L_18
L_19 , V_18 -> V_28 , - V_18 -> V_30 ,
V_16 -> V_97 ) ;
F_34 ( V_16 , V_18 ) ;
V_18 -> V_30 = - V_98 ;
}
}
struct V_19 * F_69 ( struct V_15 * V_16 , T_2 V_99 )
{
struct V_19 * V_100 ;
F_3 (entry, &xprt->recv, rq_list)
if ( V_100 -> V_101 == V_99 )
return V_100 ;
F_13 ( L_20 ,
F_70 ( V_99 ) ) ;
V_16 -> V_92 . V_102 ++ ;
return NULL ;
}
static void F_71 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_64 * V_65 = V_18 -> V_63 -> V_66 ;
unsigned int V_57 = V_18 -> V_58 . V_59 -> V_60 ;
long V_103 = F_72 ( F_73 ( V_20 -> V_104 ) ) ;
if ( V_57 ) {
if ( V_20 -> V_27 == 1 )
F_74 ( V_65 , V_57 , V_103 ) ;
F_75 ( V_65 , V_57 , V_20 -> V_27 - 1 ) ;
}
}
void F_76 ( struct V_17 * V_18 , int V_105 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
F_13 ( L_21 ,
V_18 -> V_28 , F_70 ( V_20 -> V_101 ) , V_105 ) ;
V_16 -> V_92 . V_106 ++ ;
V_20 -> V_104 = F_77 ( F_78 () , V_20 -> V_107 ) ;
if ( V_16 -> V_41 -> V_57 != NULL )
F_71 ( V_18 ) ;
F_8 ( & V_20 -> V_108 ) ;
V_20 -> V_109 . V_110 = V_105 ;
F_79 () ;
V_20 -> V_111 = V_105 ;
F_46 ( & V_16 -> V_54 , V_18 ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
if ( V_18 -> V_30 != - V_52 )
return;
F_13 ( L_22 , V_18 -> V_28 ) ;
F_24 ( & V_16 -> V_40 ) ;
if ( ! V_20 -> V_111 ) {
if ( V_16 -> V_41 -> V_57 )
V_16 -> V_41 -> V_57 ( V_16 , V_18 ) ;
} else
V_18 -> V_30 = 0 ;
F_25 ( & V_16 -> V_40 ) ;
}
static inline int F_81 ( struct V_15 * V_16 )
{
return V_16 -> V_112 != 0 ;
}
bool F_82 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
bool V_113 = false ;
F_13 ( L_23 , V_18 -> V_28 ) ;
F_24 ( & V_16 -> V_40 ) ;
if ( ! V_20 -> V_45 ) {
if ( V_20 -> V_111 ) {
V_18 -> V_30 = V_20 -> V_111 ;
goto V_44;
}
if ( ( V_18 -> V_114 & V_115 )
&& F_62 ( V_16 )
&& V_20 -> V_116 == V_16 -> V_86 ) {
V_16 -> V_41 -> V_117 ( V_18 ) ;
F_44 ( & V_16 -> V_54 , V_18 , F_80 ) ;
goto V_44;
}
}
if ( ! V_16 -> V_41 -> V_42 ( V_16 , V_18 ) ) {
V_18 -> V_30 = - V_31 ;
goto V_44;
}
V_113 = true ;
V_44:
F_25 ( & V_16 -> V_40 ) ;
return V_113 ;
}
void F_83 ( struct V_17 * V_18 )
{
F_34 ( V_18 -> V_21 -> V_51 , V_18 ) ;
}
void F_84 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
int V_53 , V_118 ;
F_13 ( L_24 , V_18 -> V_28 , V_20 -> V_119 ) ;
if ( ! V_20 -> V_111 ) {
if ( F_64 ( & V_20 -> V_108 ) && F_85 ( V_18 ) ) {
F_24 ( & V_16 -> V_40 ) ;
memcpy ( & V_20 -> V_109 , & V_20 -> V_120 ,
sizeof( V_20 -> V_109 ) ) ;
F_4 ( & V_20 -> V_108 , & V_16 -> V_88 ) ;
F_25 ( & V_16 -> V_40 ) ;
F_51 ( V_20 ) ;
F_86 ( & V_16 -> V_57 ) ;
}
} else if ( ! V_20 -> V_45 )
return;
V_20 -> V_107 = F_78 () ;
V_53 = V_16 -> V_41 -> V_121 ( V_18 ) ;
if ( V_53 != 0 ) {
V_18 -> V_30 = V_53 ;
return;
}
F_13 ( L_25 , V_18 -> V_28 ) ;
V_18 -> V_114 |= V_122 ;
F_24 ( & V_16 -> V_40 ) ;
V_16 -> V_41 -> V_117 ( V_18 ) ;
V_118 = F_87 ( & V_16 -> V_123 ) ;
if ( V_118 > V_16 -> V_92 . V_124 )
V_16 -> V_92 . V_124 = V_118 ;
V_16 -> V_92 . V_125 ++ ;
V_16 -> V_92 . V_126 += V_16 -> V_92 . V_125 - V_16 -> V_92 . V_106 ;
V_16 -> V_92 . V_127 += V_16 -> V_128 . V_129 ;
V_16 -> V_92 . V_130 += V_16 -> V_35 . V_129 ;
V_16 -> V_92 . V_131 += V_16 -> V_54 . V_129 ;
if ( ! F_62 ( V_16 ) )
V_18 -> V_30 = - V_132 ;
else {
if ( ! V_20 -> V_111 && F_85 ( V_18 ) )
F_44 ( & V_16 -> V_54 , V_18 , F_80 ) ;
V_20 -> V_116 = V_16 -> V_86 ;
}
F_25 ( & V_16 -> V_40 ) ;
}
static void F_88 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
F_60 ( V_133 , & V_16 -> V_24 ) ;
F_44 ( & V_16 -> V_128 , V_18 , NULL ) ;
}
static void F_89 ( struct V_15 * V_16 )
{
if ( F_90 ( & V_16 -> V_128 ) == NULL )
F_18 ( V_133 , & V_16 -> V_24 ) ;
}
static bool F_91 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
bool V_113 = false ;
if ( ! F_16 ( V_133 , & V_16 -> V_24 ) )
goto V_8;
F_2 ( & V_16 -> V_134 ) ;
if ( F_16 ( V_133 , & V_16 -> V_24 ) ) {
F_44 ( & V_16 -> V_128 , V_18 , NULL ) ;
V_113 = true ;
}
F_6 ( & V_16 -> V_134 ) ;
V_8:
return V_113 ;
}
static struct V_19 * F_92 ( struct V_15 * V_16 , T_3 V_135 )
{
struct V_19 * V_20 = F_93 ( - V_31 ) ;
if ( ! F_94 ( & V_16 -> V_123 , 1 , V_16 -> V_136 ) )
goto V_8;
V_20 = F_95 ( sizeof( struct V_19 ) , V_135 ) ;
if ( V_20 != NULL )
goto V_8;
F_96 ( & V_16 -> V_123 ) ;
V_20 = F_93 ( - V_137 ) ;
V_8:
return V_20 ;
}
static bool F_97 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( F_94 ( & V_16 -> V_123 , - 1 , V_16 -> V_138 ) ) {
F_98 ( V_20 ) ;
return true ;
}
return false ;
}
void F_99 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_2 ( & V_16 -> V_134 ) ;
if ( ! F_64 ( & V_16 -> free ) ) {
V_20 = F_100 ( V_16 -> free . V_139 , struct V_19 , V_108 ) ;
F_101 ( & V_20 -> V_108 ) ;
goto V_140;
}
V_20 = F_92 ( V_16 , V_141 | V_142 ) ;
if ( ! F_102 ( V_20 ) )
goto V_140;
switch ( F_103 ( V_20 ) ) {
case - V_137 :
F_13 ( L_26
L_27 ) ;
V_18 -> V_30 = - V_137 ;
break;
case - V_31 :
F_88 ( V_16 , V_18 ) ;
F_13 ( L_28 ) ;
default:
V_18 -> V_30 = - V_31 ;
}
F_6 ( & V_16 -> V_134 ) ;
return;
V_140:
V_18 -> V_30 = 0 ;
V_18 -> V_21 = V_20 ;
F_104 ( V_18 , V_16 ) ;
F_6 ( & V_16 -> V_134 ) ;
}
void F_105 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( F_23 ( V_16 , V_18 ) ) {
F_99 ( V_16 , V_18 ) ;
F_34 ( V_16 , V_18 ) ;
}
}
static void F_106 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
F_2 ( & V_16 -> V_134 ) ;
if ( ! F_97 ( V_16 , V_20 ) ) {
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
F_107 ( & V_20 -> V_108 , & V_16 -> free ) ;
}
F_89 ( V_16 ) ;
F_6 ( & V_16 -> V_134 ) ;
}
static void F_108 ( struct V_15 * V_16 )
{
struct V_19 * V_20 ;
while ( ! F_64 ( & V_16 -> free ) ) {
V_20 = F_109 ( & V_16 -> free , struct V_19 , V_108 ) ;
F_101 ( & V_20 -> V_108 ) ;
F_98 ( V_20 ) ;
}
}
struct V_15 * F_110 ( struct V_143 * V_143 , T_4 V_144 ,
unsigned int V_145 ,
unsigned int V_146 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_147 ;
V_16 = F_95 ( V_144 , V_148 ) ;
if ( V_16 == NULL )
goto V_8;
F_111 ( V_16 , V_143 ) ;
for ( V_147 = 0 ; V_147 < V_145 ; V_147 ++ ) {
V_20 = F_95 ( sizeof( struct V_19 ) , V_148 ) ;
if ( ! V_20 )
goto V_149;
F_107 ( & V_20 -> V_108 , & V_16 -> free ) ;
}
if ( V_146 > V_145 )
V_16 -> V_136 = V_146 ;
else
V_16 -> V_136 = V_145 ;
V_16 -> V_138 = V_145 ;
F_112 ( & V_16 -> V_123 , V_145 ) ;
return V_16 ;
V_149:
F_113 ( V_16 ) ;
V_8:
return NULL ;
}
void F_113 ( struct V_15 * V_16 )
{
F_114 ( V_16 -> V_150 ) ;
F_108 ( V_16 ) ;
F_98 ( V_16 ) ;
}
void F_115 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
V_18 -> V_30 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - V_31 ;
F_116 () ;
V_16 = F_117 ( V_18 -> V_63 -> V_151 ) ;
if ( ! F_91 ( V_16 , V_18 ) )
V_16 -> V_41 -> V_152 ( V_16 , V_18 ) ;
F_118 () ;
}
void F_119 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
V_18 -> V_30 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - V_31 ;
F_116 () ;
V_16 = F_117 ( V_18 -> V_63 -> V_151 ) ;
V_16 -> V_41 -> V_152 ( V_16 , V_18 ) ;
F_118 () ;
}
static inline T_2 F_120 ( struct V_15 * V_16 )
{
return ( V_153 T_2 ) V_16 -> V_99 ++ ;
}
static inline void F_121 ( struct V_15 * V_16 )
{
V_16 -> V_99 = F_122 () ;
}
static void F_104 ( struct V_17 * V_18 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
F_123 ( & V_20 -> V_108 ) ;
V_20 -> V_56 = V_18 -> V_63 -> V_68 -> V_79 ;
V_20 -> V_73 = V_18 ;
V_20 -> V_51 = V_16 ;
V_20 -> V_154 = NULL ;
V_20 -> V_101 = F_120 ( V_16 ) ;
V_20 -> V_116 = V_16 -> V_86 - 1 ;
V_20 -> V_45 = 0 ;
V_20 -> V_155 . V_110 = 0 ;
V_20 -> V_155 . V_156 = 0 ;
V_20 -> V_120 . V_110 = 0 ;
V_20 -> V_120 . V_156 = 0 ;
V_20 -> V_157 = NULL ;
F_51 ( V_20 ) ;
F_13 ( L_29 , V_18 -> V_28 ,
V_20 , F_70 ( V_20 -> V_101 ) ) ;
}
void F_124 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 == NULL ) {
if ( V_18 -> V_63 ) {
F_116 () ;
V_16 = F_117 ( V_18 -> V_63 -> V_151 ) ;
if ( V_16 -> V_25 == V_18 )
F_34 ( V_16 , V_18 ) ;
F_118 () ;
}
return;
}
V_16 = V_20 -> V_51 ;
if ( V_18 -> V_158 -> V_159 != NULL )
V_18 -> V_158 -> V_159 ( V_18 , V_18 -> V_160 ) ;
else if ( V_18 -> V_63 )
F_125 ( V_18 , V_18 -> V_63 -> V_161 ) ;
F_24 ( & V_16 -> V_40 ) ;
V_16 -> V_41 -> V_46 ( V_16 , V_18 ) ;
if ( V_16 -> V_41 -> V_162 )
V_16 -> V_41 -> V_162 ( V_18 ) ;
if ( ! F_64 ( & V_20 -> V_108 ) )
F_101 ( & V_20 -> V_108 ) ;
V_16 -> V_163 = V_78 ;
if ( F_64 ( & V_16 -> V_88 ) && F_81 ( V_16 ) )
F_126 ( & V_16 -> V_57 ,
V_16 -> V_163 + V_16 -> V_112 ) ;
F_25 ( & V_16 -> V_40 ) ;
if ( V_20 -> V_154 )
V_16 -> V_41 -> V_164 ( V_20 -> V_154 ) ;
if ( V_20 -> V_165 != NULL )
F_127 ( V_20 -> V_165 ) ;
V_18 -> V_21 = NULL ;
if ( V_20 -> V_157 )
V_20 -> V_157 ( V_20 ) ;
F_13 ( L_30 , V_18 -> V_28 , V_20 ) ;
if ( F_128 ( ! F_129 ( V_20 ) ) )
F_106 ( V_16 , V_20 ) ;
else
F_130 ( V_20 ) ;
}
static void F_111 ( struct V_15 * V_16 , struct V_143 * V_143 )
{
F_112 ( & V_16 -> V_166 , 1 ) ;
F_131 ( & V_16 -> V_40 ) ;
F_131 ( & V_16 -> V_134 ) ;
F_123 ( & V_16 -> free ) ;
F_123 ( & V_16 -> V_88 ) ;
#if F_132 ( V_167 )
F_131 ( & V_16 -> V_168 ) ;
F_123 ( & V_16 -> V_169 ) ;
#endif
V_16 -> V_163 = V_78 ;
V_16 -> V_49 = V_170 ;
V_16 -> V_171 = 0 ;
F_133 ( & V_16 -> V_172 , L_31 ) ;
F_133 ( & V_16 -> V_54 , L_32 ) ;
F_134 ( & V_16 -> V_35 , L_33 ) ;
F_134 ( & V_16 -> V_128 , L_34 ) ;
F_121 ( V_16 ) ;
V_16 -> V_150 = F_135 ( V_143 ) ;
}
struct V_15 * F_136 ( struct V_173 * args )
{
struct V_15 * V_16 ;
struct V_1 * V_3 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 -> V_7 == args -> V_7 ) {
F_6 ( & V_6 ) ;
goto V_174;
}
}
F_6 ( & V_6 ) ;
F_5 ( V_175 L_35 , args -> V_7 ) ;
return F_93 ( - V_98 ) ;
V_174:
V_16 = V_3 -> V_176 ( args ) ;
if ( F_102 ( V_16 ) ) {
F_13 ( L_36 ,
- F_103 ( V_16 ) ) ;
goto V_8;
}
if ( args -> V_177 & V_178 )
V_16 -> V_112 = 0 ;
F_137 ( & V_16 -> V_38 , F_55 ) ;
if ( F_81 ( V_16 ) )
F_138 ( & V_16 -> V_57 , F_63 ,
( unsigned long ) V_16 ) ;
else
F_139 ( & V_16 -> V_57 ) ;
if ( strlen ( args -> V_97 ) > V_179 ) {
F_140 ( V_16 ) ;
return F_93 ( - V_180 ) ;
}
V_16 -> V_97 = F_141 ( args -> V_97 , V_148 ) ;
if ( V_16 -> V_97 == NULL ) {
F_140 ( V_16 ) ;
return F_93 ( - V_137 ) ;
}
F_13 ( L_37 , V_16 ,
V_16 -> V_136 ) ;
V_8:
return V_16 ;
}
static void F_140 ( struct V_15 * V_16 )
{
F_13 ( L_38 , V_16 ) ;
F_142 ( & V_16 -> V_57 ) ;
F_143 ( & V_16 -> V_172 ) ;
F_143 ( & V_16 -> V_54 ) ;
F_143 ( & V_16 -> V_35 ) ;
F_143 ( & V_16 -> V_128 ) ;
F_144 ( & V_16 -> V_38 ) ;
F_98 ( V_16 -> V_97 ) ;
V_16 -> V_41 -> V_181 ( V_16 ) ;
}
void F_145 ( struct V_15 * V_16 )
{
if ( F_146 ( & V_16 -> V_166 ) )
F_140 ( V_16 ) ;
}
struct V_15 * F_147 ( struct V_15 * V_16 )
{
if ( F_148 ( & V_16 -> V_166 ) )
return V_16 ;
return NULL ;
}
