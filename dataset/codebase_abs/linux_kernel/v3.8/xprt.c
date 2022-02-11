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
if ( ! F_16 ( V_37 , & V_16 -> V_24 ) ) {
F_17 () ;
F_18 ( V_23 , & V_16 -> V_24 ) ;
F_19 () ;
} else
F_20 ( V_38 , & V_16 -> V_39 ) ;
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
int V_40 ;
F_24 ( & V_16 -> V_41 ) ;
V_40 = V_16 -> V_42 -> V_43 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_41 ) ;
return V_40 ;
}
static bool F_26 ( struct V_17 * V_18 , void * V_44 )
{
struct V_15 * V_16 = V_44 ;
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
static bool F_29 ( struct V_17 * V_18 , void * V_44 )
{
struct V_15 * V_16 = V_44 ;
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
goto V_45;
if ( F_28 ( & V_16 -> V_36 , F_29 , V_16 ) )
return;
V_45:
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
F_24 ( & V_16 -> V_41 ) ;
V_16 -> V_42 -> V_46 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_41 ) ;
}
static int
F_22 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 -> V_47 )
return 1 ;
F_13 ( L_5 ,
V_18 -> V_29 , V_16 -> V_48 , V_16 -> V_49 ) ;
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
F_35 ( V_18 -> V_51 , V_18 -> V_21 ) ;
}
void F_37 ( struct V_17 * V_18 , int V_4 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_18 -> V_51 ;
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
struct V_15 * V_16 = V_20 -> V_56 ;
V_18 -> V_30 = V_20 -> V_57 ;
F_43 ( & V_16 -> V_54 , V_18 , V_55 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
F_24 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_25 ) {
F_13 ( L_7
L_8 , V_16 ) ;
F_45 ( & V_16 -> V_54 , V_16 -> V_25 ) ;
}
F_25 ( & V_16 -> V_41 ) ;
}
void F_46 ( struct V_17 * V_18 )
{
V_18 -> V_30 = V_18 -> V_21 -> V_57 ;
}
void F_47 ( struct V_17 * V_18 )
{
int V_58 = V_18 -> V_59 . V_60 -> V_61 ;
struct V_62 * V_63 = V_18 -> V_64 ;
struct V_65 * V_66 = V_63 -> V_67 ;
struct V_19 * V_20 = V_18 -> V_21 ;
unsigned long V_68 = V_63 -> V_69 -> V_70 ;
V_18 -> V_30 = F_48 ( V_66 , V_58 ) ;
V_18 -> V_30 <<= F_49 ( V_66 , V_58 ) + V_20 -> V_71 ;
if ( V_18 -> V_30 > V_68 || V_18 -> V_30 == 0 )
V_18 -> V_30 = V_68 ;
}
static void F_50 ( struct V_19 * V_20 )
{
const struct V_72 * V_73 = V_20 -> V_74 -> V_64 -> V_69 ;
V_20 -> V_75 = V_20 -> V_57 ;
if ( V_73 -> V_76 )
V_20 -> V_75 <<= V_73 -> V_77 ;
else
V_20 -> V_75 += V_73 -> V_78 * V_73 -> V_77 ;
if ( V_20 -> V_75 > V_73 -> V_70 || V_20 -> V_75 == 0 )
V_20 -> V_75 = V_73 -> V_70 ;
V_20 -> V_75 += V_79 ;
}
int F_51 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_56 ;
const struct V_72 * V_73 = V_20 -> V_74 -> V_64 -> V_69 ;
int V_53 = 0 ;
if ( F_52 ( V_79 , V_20 -> V_75 ) ) {
if ( V_73 -> V_76 )
V_20 -> V_57 <<= 1 ;
else
V_20 -> V_57 += V_73 -> V_78 ;
if ( V_73 -> V_70 && V_20 -> V_57 >= V_73 -> V_70 )
V_20 -> V_57 = V_73 -> V_70 ;
V_20 -> V_71 ++ ;
} else {
V_20 -> V_57 = V_73 -> V_80 ;
V_20 -> V_71 = 0 ;
F_50 ( V_20 ) ;
F_24 ( & V_16 -> V_41 ) ;
F_53 ( V_20 -> V_74 -> V_64 -> V_67 , V_73 -> V_80 ) ;
F_25 ( & V_16 -> V_41 ) ;
V_53 = - V_52 ;
}
if ( V_20 -> V_57 == 0 ) {
F_5 ( V_81 L_9 ) ;
V_20 -> V_57 = 5 * V_82 ;
}
return V_53 ;
}
static void F_54 ( struct V_83 * V_84 )
{
struct V_15 * V_16 =
F_55 ( V_84 , struct V_15 , V_39 ) ;
V_16 -> V_42 -> V_85 ( V_16 ) ;
F_18 ( V_37 , & V_16 -> V_24 ) ;
F_34 ( V_16 , NULL ) ;
}
void F_56 ( struct V_15 * V_16 )
{
F_13 ( L_10 , V_16 ) ;
F_24 ( & V_16 -> V_41 ) ;
F_57 ( V_16 ) ;
F_39 ( V_16 , - V_32 ) ;
F_25 ( & V_16 -> V_41 ) ;
}
void F_58 ( struct V_15 * V_16 )
{
F_24 ( & V_16 -> V_41 ) ;
F_59 ( V_37 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_38 , & V_16 -> V_39 ) ;
F_39 ( V_16 , - V_32 ) ;
F_25 ( & V_16 -> V_41 ) ;
}
void F_60 ( struct V_15 * V_16 , unsigned int V_86 )
{
F_24 ( & V_16 -> V_41 ) ;
if ( V_86 != V_16 -> V_87 )
goto V_8;
if ( F_16 ( V_88 , & V_16 -> V_24 ) || ! F_61 ( V_16 ) )
goto V_8;
F_59 ( V_37 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_38 , & V_16 -> V_39 ) ;
F_39 ( V_16 , - V_32 ) ;
V_8:
F_25 ( & V_16 -> V_41 ) ;
}
static void
F_62 ( unsigned long V_44 )
{
struct V_15 * V_16 = (struct V_15 * ) V_44 ;
F_2 ( & V_16 -> V_41 ) ;
if ( ! F_63 ( & V_16 -> V_89 ) )
goto V_90;
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
goto V_90;
F_6 ( & V_16 -> V_41 ) ;
F_59 ( V_91 , & V_16 -> V_24 ) ;
F_20 ( V_38 , & V_16 -> V_39 ) ;
return;
V_90:
F_6 ( & V_16 -> V_41 ) ;
}
void F_64 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
F_13 ( L_11 , V_18 -> V_29 ,
V_16 , ( F_61 ( V_16 ) ? L_12 : L_13 ) ) ;
if ( ! F_65 ( V_16 ) ) {
V_18 -> V_31 = - V_32 ;
return;
}
if ( ! F_23 ( V_16 , V_18 ) )
return;
if ( F_66 ( V_37 , & V_16 -> V_24 ) )
V_16 -> V_42 -> V_85 ( V_16 ) ;
if ( F_61 ( V_16 ) )
F_34 ( V_16 , V_18 ) ;
else {
V_18 -> V_21 -> V_27 = 0 ;
V_18 -> V_30 = V_18 -> V_21 -> V_57 ;
F_43 ( & V_16 -> V_54 , V_18 , V_92 ) ;
if ( F_16 ( V_88 , & V_16 -> V_24 ) )
return;
if ( F_67 ( V_16 ) )
return;
V_16 -> V_93 . V_94 = V_79 ;
V_16 -> V_42 -> V_95 ( V_18 ) ;
}
}
static void V_92 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
if ( V_18 -> V_31 == 0 ) {
V_16 -> V_93 . V_96 ++ ;
V_16 -> V_93 . V_97 += ( long ) V_79 - V_16 -> V_93 . V_94 ;
F_13 ( L_14 ,
V_18 -> V_29 ) ;
return;
}
switch ( V_18 -> V_31 ) {
case - V_32 :
F_13 ( L_15 , V_18 -> V_29 ) ;
break;
case - V_52 :
F_13 ( L_16
L_17 , V_18 -> V_29 ) ;
break;
default:
F_13 ( L_18
L_19 , V_18 -> V_29 , - V_18 -> V_31 ,
V_16 -> V_98 ) ;
F_34 ( V_16 , V_18 ) ;
V_18 -> V_31 = - V_99 ;
}
}
struct V_19 * F_68 ( struct V_15 * V_16 , T_2 V_100 )
{
struct V_19 * V_101 ;
F_3 (entry, &xprt->recv, rq_list)
if ( V_101 -> V_102 == V_100 )
return V_101 ;
F_13 ( L_20 ,
F_69 ( V_100 ) ) ;
V_16 -> V_93 . V_103 ++ ;
return NULL ;
}
static void F_70 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_65 * V_66 = V_18 -> V_64 -> V_67 ;
unsigned int V_58 = V_18 -> V_59 . V_60 -> V_61 ;
long V_104 = F_71 ( F_72 ( V_20 -> V_105 ) ) ;
if ( V_58 ) {
if ( V_20 -> V_28 == 1 )
F_73 ( V_66 , V_58 , V_104 ) ;
F_74 ( V_66 , V_58 , V_20 -> V_28 - 1 ) ;
}
}
void F_75 ( struct V_17 * V_18 , int V_106 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
F_13 ( L_21 ,
V_18 -> V_29 , F_69 ( V_20 -> V_102 ) , V_106 ) ;
V_16 -> V_93 . V_107 ++ ;
V_20 -> V_105 = F_76 ( F_77 () , V_20 -> V_108 ) ;
if ( V_16 -> V_42 -> V_58 != NULL )
F_70 ( V_18 ) ;
F_8 ( & V_20 -> V_109 ) ;
V_20 -> V_110 . V_111 = V_106 ;
F_78 () ;
V_20 -> V_112 = V_106 ;
F_45 ( & V_16 -> V_54 , V_18 ) ;
}
static void F_79 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
if ( V_18 -> V_31 != - V_52 )
return;
F_13 ( L_22 , V_18 -> V_29 ) ;
F_24 ( & V_16 -> V_41 ) ;
if ( ! V_20 -> V_112 ) {
if ( V_16 -> V_42 -> V_58 )
V_16 -> V_42 -> V_58 ( V_18 ) ;
} else
V_18 -> V_31 = 0 ;
F_25 ( & V_16 -> V_41 ) ;
}
static inline int F_80 ( struct V_15 * V_16 )
{
return V_16 -> V_113 != 0 ;
}
int F_81 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
int V_114 = 0 ;
F_13 ( L_23 , V_18 -> V_29 ) ;
F_24 ( & V_16 -> V_41 ) ;
if ( V_20 -> V_112 && ! V_20 -> V_27 ) {
V_114 = V_20 -> V_112 ;
goto V_45;
}
if ( ! V_16 -> V_42 -> V_43 ( V_16 , V_18 ) )
V_114 = - V_32 ;
V_45:
F_25 ( & V_16 -> V_41 ) ;
return V_114 ;
}
void F_82 ( struct V_17 * V_18 )
{
F_34 ( V_18 -> V_21 -> V_56 , V_18 ) ;
}
void F_83 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
int V_53 , V_115 ;
F_13 ( L_24 , V_18 -> V_29 , V_20 -> V_116 ) ;
if ( ! V_20 -> V_112 ) {
if ( F_63 ( & V_20 -> V_109 ) && F_84 ( V_18 ) ) {
F_24 ( & V_16 -> V_41 ) ;
memcpy ( & V_20 -> V_110 , & V_20 -> V_117 ,
sizeof( V_20 -> V_110 ) ) ;
F_4 ( & V_20 -> V_109 , & V_16 -> V_89 ) ;
F_25 ( & V_16 -> V_41 ) ;
F_50 ( V_20 ) ;
F_85 ( & V_16 -> V_58 ) ;
}
} else if ( ! V_20 -> V_27 )
return;
V_20 -> V_118 = V_16 -> V_87 ;
V_20 -> V_108 = F_77 () ;
V_53 = V_16 -> V_42 -> V_119 ( V_18 ) ;
if ( V_53 != 0 ) {
V_18 -> V_31 = V_53 ;
return;
}
F_13 ( L_25 , V_18 -> V_29 ) ;
V_18 -> V_120 |= V_121 ;
F_24 ( & V_16 -> V_41 ) ;
V_16 -> V_42 -> V_122 ( V_18 ) ;
V_115 = F_86 ( & V_16 -> V_123 ) ;
if ( V_115 > V_16 -> V_93 . V_124 )
V_16 -> V_93 . V_124 = V_115 ;
V_16 -> V_93 . V_125 ++ ;
V_16 -> V_93 . V_126 += V_16 -> V_93 . V_125 - V_16 -> V_93 . V_107 ;
V_16 -> V_93 . V_127 += V_16 -> V_128 . V_129 ;
V_16 -> V_93 . V_130 += V_16 -> V_36 . V_129 ;
V_16 -> V_93 . V_131 += V_16 -> V_54 . V_129 ;
if ( ! F_61 ( V_16 ) )
V_18 -> V_31 = - V_132 ;
else if ( ! V_20 -> V_112 && F_84 ( V_18 ) ) {
F_43 ( & V_16 -> V_54 , V_18 , F_79 ) ;
}
F_25 ( & V_16 -> V_41 ) ;
}
static struct V_19 * F_87 ( struct V_15 * V_16 , T_3 V_133 )
{
struct V_19 * V_20 = F_88 ( - V_32 ) ;
if ( ! F_89 ( & V_16 -> V_123 , 1 , V_16 -> V_134 ) )
goto V_8;
V_20 = F_90 ( sizeof( struct V_19 ) , V_133 ) ;
if ( V_20 != NULL )
goto V_8;
F_91 ( & V_16 -> V_123 ) ;
V_20 = F_88 ( - V_135 ) ;
V_8:
return V_20 ;
}
static bool F_92 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( F_89 ( & V_16 -> V_123 , - 1 , V_16 -> V_136 ) ) {
F_93 ( V_20 ) ;
return true ;
}
return false ;
}
void F_94 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_2 ( & V_16 -> V_137 ) ;
if ( ! F_63 ( & V_16 -> free ) ) {
V_20 = F_95 ( V_16 -> free . V_138 , struct V_19 , V_109 ) ;
F_96 ( & V_20 -> V_109 ) ;
goto V_139;
}
V_20 = F_87 ( V_16 , V_140 | V_141 ) ;
if ( ! F_97 ( V_20 ) )
goto V_139;
switch ( F_98 ( V_20 ) ) {
case - V_135 :
F_13 ( L_26
L_27 ) ;
V_18 -> V_31 = - V_135 ;
break;
case - V_32 :
F_43 ( & V_16 -> V_128 , V_18 , NULL ) ;
F_13 ( L_28 ) ;
default:
V_18 -> V_31 = - V_32 ;
}
F_6 ( & V_16 -> V_137 ) ;
return;
V_139:
V_18 -> V_31 = 0 ;
V_18 -> V_21 = V_20 ;
F_99 ( V_18 , V_16 ) ;
F_6 ( & V_16 -> V_137 ) ;
}
void F_100 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( F_23 ( V_16 , V_18 ) ) {
F_94 ( V_16 , V_18 ) ;
F_34 ( V_16 , V_18 ) ;
}
}
static void F_101 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
F_2 ( & V_16 -> V_137 ) ;
if ( ! F_92 ( V_16 , V_20 ) ) {
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
F_102 ( & V_20 -> V_109 , & V_16 -> free ) ;
}
F_103 ( & V_16 -> V_128 ) ;
F_6 ( & V_16 -> V_137 ) ;
}
static void F_104 ( struct V_15 * V_16 )
{
struct V_19 * V_20 ;
while ( ! F_63 ( & V_16 -> free ) ) {
V_20 = F_105 ( & V_16 -> free , struct V_19 , V_109 ) ;
F_96 ( & V_20 -> V_109 ) ;
F_93 ( V_20 ) ;
}
}
struct V_15 * F_106 ( struct V_142 * V_142 , T_4 V_143 ,
unsigned int V_144 ,
unsigned int V_145 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_146 ;
V_16 = F_90 ( V_143 , V_147 ) ;
if ( V_16 == NULL )
goto V_8;
F_107 ( V_16 , V_142 ) ;
for ( V_146 = 0 ; V_146 < V_144 ; V_146 ++ ) {
V_20 = F_90 ( sizeof( struct V_19 ) , V_147 ) ;
if ( ! V_20 )
break;
F_102 ( & V_20 -> V_109 , & V_16 -> free ) ;
}
if ( V_146 < V_144 )
goto V_148;
if ( V_145 > V_144 )
V_16 -> V_134 = V_145 ;
else
V_16 -> V_134 = V_144 ;
V_16 -> V_136 = V_144 ;
F_108 ( & V_16 -> V_123 , V_144 ) ;
return V_16 ;
V_148:
F_109 ( V_16 ) ;
V_8:
return NULL ;
}
void F_109 ( struct V_15 * V_16 )
{
F_110 ( V_16 -> V_149 ) ;
F_104 ( V_16 ) ;
F_93 ( V_16 ) ;
}
void F_111 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
V_18 -> V_31 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = - V_32 ;
V_16 -> V_42 -> V_150 ( V_16 , V_18 ) ;
}
static inline T_2 F_112 ( struct V_15 * V_16 )
{
return ( V_151 T_2 ) V_16 -> V_100 ++ ;
}
static inline void F_113 ( struct V_15 * V_16 )
{
V_16 -> V_100 = F_114 () ;
}
static void F_99 ( struct V_17 * V_18 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
F_115 ( & V_20 -> V_109 ) ;
V_20 -> V_57 = V_18 -> V_64 -> V_69 -> V_80 ;
V_20 -> V_74 = V_18 ;
V_20 -> V_56 = V_16 ;
V_20 -> V_152 = NULL ;
V_20 -> V_102 = F_112 ( V_16 ) ;
V_20 -> V_153 = NULL ;
F_50 ( V_20 ) ;
F_13 ( L_29 , V_18 -> V_29 ,
V_20 , F_69 ( V_20 -> V_102 ) ) ;
}
void F_116 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 == NULL ) {
if ( V_18 -> V_64 ) {
F_117 () ;
V_16 = F_118 ( V_18 -> V_64 -> V_154 ) ;
if ( V_16 -> V_25 == V_18 )
F_34 ( V_16 , V_18 ) ;
F_119 () ;
}
return;
}
V_16 = V_20 -> V_56 ;
if ( V_18 -> V_155 -> V_156 != NULL )
V_18 -> V_155 -> V_156 ( V_18 , V_18 -> V_157 ) ;
else if ( V_18 -> V_64 )
F_120 ( V_18 , V_18 -> V_64 -> V_158 ) ;
F_24 ( & V_16 -> V_41 ) ;
V_16 -> V_42 -> V_46 ( V_16 , V_18 ) ;
if ( V_16 -> V_42 -> V_159 )
V_16 -> V_42 -> V_159 ( V_18 ) ;
if ( ! F_63 ( & V_20 -> V_109 ) )
F_96 ( & V_20 -> V_109 ) ;
V_16 -> V_160 = V_79 ;
if ( F_63 ( & V_16 -> V_89 ) && F_80 ( V_16 ) )
F_121 ( & V_16 -> V_58 ,
V_16 -> V_160 + V_16 -> V_113 ) ;
F_25 ( & V_16 -> V_41 ) ;
if ( V_20 -> V_152 )
V_16 -> V_42 -> V_161 ( V_20 -> V_152 ) ;
if ( V_20 -> V_162 != NULL )
F_122 ( V_20 -> V_162 ) ;
V_18 -> V_21 = NULL ;
if ( V_20 -> V_153 )
V_20 -> V_153 ( V_20 ) ;
F_13 ( L_30 , V_18 -> V_29 , V_20 ) ;
if ( F_123 ( ! F_124 ( V_20 ) ) )
F_101 ( V_16 , V_20 ) ;
else
F_125 ( V_20 ) ;
}
static void F_107 ( struct V_15 * V_16 , struct V_142 * V_142 )
{
F_108 ( & V_16 -> V_163 , 1 ) ;
F_126 ( & V_16 -> V_41 ) ;
F_126 ( & V_16 -> V_137 ) ;
F_115 ( & V_16 -> free ) ;
F_115 ( & V_16 -> V_89 ) ;
#if F_127 ( V_164 )
F_126 ( & V_16 -> V_165 ) ;
F_115 ( & V_16 -> V_166 ) ;
#endif
V_16 -> V_160 = V_79 ;
V_16 -> V_49 = V_167 ;
V_16 -> V_168 = 0 ;
F_128 ( & V_16 -> V_169 , L_31 ) ;
F_128 ( & V_16 -> V_54 , L_32 ) ;
F_129 ( & V_16 -> V_36 , L_33 ) ;
F_129 ( & V_16 -> V_128 , L_34 ) ;
F_113 ( V_16 ) ;
V_16 -> V_149 = F_130 ( V_142 ) ;
}
struct V_15 * F_131 ( struct V_170 * args )
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
return F_88 ( - V_99 ) ;
V_171:
V_16 = V_3 -> V_173 ( args ) ;
if ( F_97 ( V_16 ) ) {
F_13 ( L_36 ,
- F_98 ( V_16 ) ) ;
goto V_8;
}
F_132 ( & V_16 -> V_39 , F_54 ) ;
if ( F_80 ( V_16 ) )
F_133 ( & V_16 -> V_58 , F_62 ,
( unsigned long ) V_16 ) ;
else
F_134 ( & V_16 -> V_58 ) ;
if ( strlen ( args -> V_98 ) > V_174 ) {
F_135 ( V_16 ) ;
return F_88 ( - V_175 ) ;
}
V_16 -> V_98 = F_136 ( args -> V_98 , V_147 ) ;
if ( V_16 -> V_98 == NULL ) {
F_135 ( V_16 ) ;
return F_88 ( - V_135 ) ;
}
F_13 ( L_37 , V_16 ,
V_16 -> V_134 ) ;
V_8:
return V_16 ;
}
static void F_135 ( struct V_15 * V_16 )
{
F_13 ( L_38 , V_16 ) ;
F_137 ( & V_16 -> V_58 ) ;
F_138 ( & V_16 -> V_169 ) ;
F_138 ( & V_16 -> V_54 ) ;
F_138 ( & V_16 -> V_36 ) ;
F_138 ( & V_16 -> V_128 ) ;
F_139 ( & V_16 -> V_39 ) ;
F_93 ( V_16 -> V_98 ) ;
V_16 -> V_42 -> V_176 ( V_16 ) ;
}
void F_140 ( struct V_15 * V_16 )
{
if ( F_141 ( & V_16 -> V_163 ) )
F_135 ( V_16 ) ;
}
struct V_15 * F_142 ( struct V_15 * V_16 )
{
if ( F_143 ( & V_16 -> V_163 ) )
return V_16 ;
return NULL ;
}
