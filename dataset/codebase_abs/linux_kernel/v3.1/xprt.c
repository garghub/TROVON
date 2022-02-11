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
static void F_26 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
return;
V_18 = F_27 ( & V_16 -> V_36 ) ;
if ( V_18 == NULL )
goto V_45;
V_20 = V_18 -> V_21 ;
V_16 -> V_25 = V_18 ;
if ( V_20 ) {
V_20 -> V_27 = 0 ;
V_20 -> V_28 ++ ;
}
return;
V_45:
F_15 ( V_16 ) ;
}
static void F_28 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
return;
if ( F_29 ( V_16 ) )
goto V_45;
V_18 = F_27 ( & V_16 -> V_36 ) ;
if ( V_18 == NULL )
goto V_45;
V_20 = V_18 -> V_21 ;
if ( V_20 == NULL ) {
V_16 -> V_25 = V_18 ;
return;
}
if ( F_22 ( V_16 , V_18 ) ) {
V_16 -> V_25 = V_18 ;
V_20 -> V_27 = 0 ;
V_20 -> V_28 ++ ;
return;
}
V_45:
F_15 ( V_16 ) ;
}
void F_30 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_16 -> V_25 == V_18 ) {
F_15 ( V_16 ) ;
F_26 ( V_16 ) ;
}
}
void F_31 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_16 -> V_25 == V_18 ) {
F_15 ( V_16 ) ;
F_28 ( V_16 ) ;
}
}
static inline void F_32 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
F_24 ( & V_16 -> V_42 ) ;
V_16 -> V_43 -> V_46 ( V_16 , V_18 ) ;
F_25 ( & V_16 -> V_42 ) ;
}
static int
F_22 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 -> V_47 )
return 1 ;
F_13 ( L_5 ,
V_18 -> V_29 , V_16 -> V_48 , V_16 -> V_49 ) ;
if ( F_29 ( V_16 ) )
return 0 ;
V_20 -> V_47 = 1 ;
V_16 -> V_48 += V_50 ;
return 1 ;
}
static void
F_33 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( ! V_20 -> V_47 )
return;
V_20 -> V_47 = 0 ;
V_16 -> V_48 -= V_50 ;
F_28 ( V_16 ) ;
}
void F_34 ( struct V_17 * V_18 )
{
F_33 ( V_18 -> V_51 , V_18 -> V_21 ) ;
}
void F_35 ( struct V_17 * V_18 , int V_4 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_18 -> V_51 ;
unsigned long V_49 = V_16 -> V_49 ;
if ( V_4 >= 0 && V_49 <= V_16 -> V_48 ) {
V_49 += ( V_50 * V_50 + ( V_49 >> 1 ) ) / V_49 ;
if ( V_49 > F_36 ( V_16 ) )
V_49 = F_36 ( V_16 ) ;
F_28 ( V_16 ) ;
} else if ( V_4 == - V_52 ) {
V_49 >>= 1 ;
if ( V_49 < V_50 )
V_49 = V_50 ;
}
F_13 ( L_6 ,
V_16 -> V_48 , V_16 -> V_49 , V_49 ) ;
V_16 -> V_49 = V_49 ;
F_33 ( V_16 , V_20 ) ;
}
void F_37 ( struct V_15 * V_16 , int V_53 )
{
if ( V_53 < 0 )
F_38 ( & V_16 -> V_54 , V_53 ) ;
else
F_39 ( & V_16 -> V_54 ) ;
}
void F_40 ( struct V_17 * V_18 , T_1 V_55 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
V_18 -> V_30 = V_20 -> V_57 ;
F_41 ( & V_16 -> V_54 , V_18 , V_55 ) ;
}
void F_42 ( struct V_15 * V_16 )
{
if ( F_43 ( V_16 -> V_38 ) )
return;
F_24 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_25 ) {
F_13 ( L_7
L_8 , V_16 ) ;
F_44 ( & V_16 -> V_54 , V_16 -> V_25 ) ;
}
F_25 ( & V_16 -> V_42 ) ;
}
void F_45 ( struct V_17 * V_18 )
{
V_18 -> V_30 = V_18 -> V_21 -> V_57 ;
}
void F_46 ( struct V_17 * V_18 )
{
int V_58 = V_18 -> V_59 . V_60 -> V_61 ;
struct V_62 * V_63 = V_18 -> V_64 ;
struct V_65 * V_66 = V_63 -> V_67 ;
struct V_19 * V_20 = V_18 -> V_21 ;
unsigned long V_68 = V_63 -> V_69 -> V_70 ;
V_18 -> V_30 = F_47 ( V_66 , V_58 ) ;
V_18 -> V_30 <<= F_48 ( V_66 , V_58 ) + V_20 -> V_71 ;
if ( V_18 -> V_30 > V_68 || V_18 -> V_30 == 0 )
V_18 -> V_30 = V_68 ;
}
static void F_49 ( struct V_19 * V_20 )
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
int F_50 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_56 ;
const struct V_72 * V_73 = V_20 -> V_74 -> V_64 -> V_69 ;
int V_53 = 0 ;
if ( F_51 ( V_79 , V_20 -> V_75 ) ) {
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
F_49 ( V_20 ) ;
F_24 ( & V_16 -> V_42 ) ;
F_52 ( V_20 -> V_74 -> V_64 -> V_67 , V_73 -> V_80 ) ;
F_25 ( & V_16 -> V_42 ) ;
V_53 = - V_52 ;
}
if ( V_20 -> V_57 == 0 ) {
F_5 ( V_81 L_9 ) ;
V_20 -> V_57 = 5 * V_82 ;
}
return V_53 ;
}
static void F_53 ( struct V_83 * V_84 )
{
struct V_15 * V_16 =
F_54 ( V_84 , struct V_15 , V_40 ) ;
V_16 -> V_43 -> V_85 ( V_16 ) ;
F_18 ( V_37 , & V_16 -> V_24 ) ;
F_32 ( V_16 , NULL ) ;
}
void F_55 ( struct V_15 * V_16 )
{
F_13 ( L_10 , V_16 ) ;
F_24 ( & V_16 -> V_42 ) ;
F_56 ( V_16 ) ;
F_37 ( V_16 , - V_32 ) ;
F_25 ( & V_16 -> V_42 ) ;
}
void F_57 ( struct V_15 * V_16 )
{
F_24 ( & V_16 -> V_42 ) ;
F_58 ( V_37 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_39 , & V_16 -> V_40 ) ;
F_37 ( V_16 , - V_32 ) ;
F_25 ( & V_16 -> V_42 ) ;
}
void F_59 ( struct V_15 * V_16 , unsigned int V_86 )
{
F_24 ( & V_16 -> V_42 ) ;
if ( V_86 != V_16 -> V_87 )
goto V_8;
if ( F_16 ( V_88 , & V_16 -> V_24 ) || ! F_60 ( V_16 ) )
goto V_8;
F_58 ( V_37 , & V_16 -> V_24 ) ;
if ( F_12 ( V_23 , & V_16 -> V_24 ) == 0 )
F_20 ( V_39 , & V_16 -> V_40 ) ;
F_37 ( V_16 , - V_32 ) ;
V_8:
F_25 ( & V_16 -> V_42 ) ;
}
static void
F_61 ( unsigned long V_89 )
{
struct V_15 * V_16 = (struct V_15 * ) V_89 ;
F_2 ( & V_16 -> V_42 ) ;
if ( ! F_62 ( & V_16 -> V_90 ) || V_16 -> V_38 )
goto V_91;
if ( F_12 ( V_23 , & V_16 -> V_24 ) )
goto V_91;
F_6 ( & V_16 -> V_42 ) ;
F_58 ( V_92 , & V_16 -> V_24 ) ;
F_20 ( V_39 , & V_16 -> V_40 ) ;
return;
V_91:
F_6 ( & V_16 -> V_42 ) ;
}
void F_63 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
F_13 ( L_11 , V_18 -> V_29 ,
V_16 , ( F_60 ( V_16 ) ? L_12 : L_13 ) ) ;
if ( ! F_64 ( V_16 ) ) {
V_18 -> V_31 = - V_32 ;
return;
}
if ( ! F_23 ( V_16 , V_18 ) )
return;
if ( F_65 ( V_37 , & V_16 -> V_24 ) )
V_16 -> V_43 -> V_85 ( V_16 ) ;
if ( F_60 ( V_16 ) )
F_32 ( V_16 , V_18 ) ;
else {
if ( V_18 -> V_21 )
V_18 -> V_21 -> V_27 = 0 ;
V_18 -> V_30 = V_18 -> V_21 -> V_57 ;
F_41 ( & V_16 -> V_54 , V_18 , V_93 ) ;
if ( F_16 ( V_88 , & V_16 -> V_24 ) )
return;
if ( F_66 ( V_16 ) )
return;
V_16 -> V_94 . V_95 = V_79 ;
V_16 -> V_43 -> V_96 ( V_18 ) ;
}
}
static void V_93 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
if ( V_18 -> V_31 == 0 ) {
V_16 -> V_94 . V_97 ++ ;
V_16 -> V_94 . V_98 += ( long ) V_79 - V_16 -> V_94 . V_95 ;
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
V_18 -> V_64 -> V_99 ) ;
F_32 ( V_16 , V_18 ) ;
V_18 -> V_31 = - V_100 ;
}
}
struct V_19 * F_67 ( struct V_15 * V_16 , T_2 V_101 )
{
struct V_19 * V_102 ;
F_3 (entry, &xprt->recv, rq_list)
if ( V_102 -> V_103 == V_101 )
return V_102 ;
F_13 ( L_20 ,
F_68 ( V_101 ) ) ;
V_16 -> V_94 . V_104 ++ ;
return NULL ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_65 * V_66 = V_18 -> V_64 -> V_67 ;
unsigned V_58 = V_18 -> V_59 . V_60 -> V_61 ;
long V_105 = F_70 ( F_71 ( V_20 -> V_106 ) ) ;
if ( V_58 ) {
if ( V_20 -> V_28 == 1 )
F_72 ( V_66 , V_58 , V_105 ) ;
F_73 ( V_66 , V_58 , V_20 -> V_28 - 1 ) ;
}
}
void F_74 ( struct V_17 * V_18 , int V_107 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
F_13 ( L_21 ,
V_18 -> V_29 , F_68 ( V_20 -> V_103 ) , V_107 ) ;
V_16 -> V_94 . V_108 ++ ;
V_20 -> V_106 = F_75 ( F_76 () , V_20 -> V_109 ) ;
if ( V_16 -> V_43 -> V_58 != NULL )
F_69 ( V_18 ) ;
F_8 ( & V_20 -> V_110 ) ;
V_20 -> V_111 . V_112 = V_107 ;
F_77 () ;
V_20 -> V_113 = V_107 ;
F_44 ( & V_16 -> V_54 , V_18 ) ;
}
static void F_78 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
if ( V_18 -> V_31 != - V_52 )
return;
F_13 ( L_22 , V_18 -> V_29 ) ;
F_24 ( & V_16 -> V_42 ) ;
if ( ! V_20 -> V_113 ) {
if ( V_16 -> V_43 -> V_58 )
V_16 -> V_43 -> V_58 ( V_18 ) ;
} else
V_18 -> V_31 = 0 ;
F_25 ( & V_16 -> V_42 ) ;
}
static inline int F_79 ( struct V_15 * V_16 )
{
return V_16 -> V_114 != 0 ;
}
int F_80 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
int V_115 = 0 ;
F_13 ( L_23 , V_18 -> V_29 ) ;
F_24 ( & V_16 -> V_42 ) ;
if ( V_20 -> V_113 && ! V_20 -> V_27 ) {
V_115 = V_20 -> V_113 ;
goto V_45;
}
if ( ! V_16 -> V_43 -> V_44 ( V_16 , V_18 ) )
V_115 = - V_32 ;
V_45:
F_25 ( & V_16 -> V_42 ) ;
return V_115 ;
}
void F_81 ( struct V_17 * V_18 )
{
F_32 ( V_18 -> V_21 -> V_56 , V_18 ) ;
}
void F_82 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_56 ;
int V_53 ;
F_13 ( L_24 , V_18 -> V_29 , V_20 -> V_116 ) ;
if ( ! V_20 -> V_113 ) {
if ( F_62 ( & V_20 -> V_110 ) && F_83 ( V_18 ) ) {
F_24 ( & V_16 -> V_42 ) ;
memcpy ( & V_20 -> V_111 , & V_20 -> V_117 ,
sizeof( V_20 -> V_111 ) ) ;
F_4 ( & V_20 -> V_110 , & V_16 -> V_90 ) ;
F_25 ( & V_16 -> V_42 ) ;
F_49 ( V_20 ) ;
F_84 ( & V_16 -> V_58 ) ;
}
} else if ( ! V_20 -> V_27 )
return;
V_20 -> V_118 = V_16 -> V_87 ;
V_20 -> V_109 = F_76 () ;
V_53 = V_16 -> V_43 -> V_119 ( V_18 ) ;
if ( V_53 != 0 ) {
V_18 -> V_31 = V_53 ;
return;
}
F_13 ( L_25 , V_18 -> V_29 ) ;
V_18 -> V_120 |= V_121 ;
F_24 ( & V_16 -> V_42 ) ;
V_16 -> V_43 -> V_122 ( V_18 ) ;
V_16 -> V_94 . V_123 ++ ;
V_16 -> V_94 . V_124 += V_16 -> V_94 . V_123 - V_16 -> V_94 . V_108 ;
V_16 -> V_94 . V_125 += V_16 -> V_126 . V_127 ;
if ( ! F_60 ( V_16 ) )
V_18 -> V_31 = - V_128 ;
else if ( ! V_20 -> V_113 && F_83 ( V_18 ) ) {
F_41 ( & V_16 -> V_54 , V_18 , F_78 ) ;
}
F_25 ( & V_16 -> V_42 ) ;
}
static struct V_19 * F_85 ( struct V_15 * V_16 , T_3 V_129 )
{
struct V_19 * V_20 = F_86 ( - V_32 ) ;
if ( ! F_87 ( & V_16 -> V_130 , 1 , V_16 -> V_131 ) )
goto V_8;
V_20 = F_88 ( sizeof( struct V_19 ) , V_129 ) ;
if ( V_20 != NULL )
goto V_8;
F_89 ( & V_16 -> V_130 ) ;
V_20 = F_86 ( - V_132 ) ;
V_8:
return V_20 ;
}
static bool F_90 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( F_87 ( & V_16 -> V_130 , - 1 , V_16 -> V_133 ) ) {
F_91 ( V_20 ) ;
return true ;
}
return false ;
}
static void F_92 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
struct V_19 * V_20 ;
if ( ! F_62 ( & V_16 -> free ) ) {
V_20 = F_93 ( V_16 -> free . V_134 , struct V_19 , V_110 ) ;
F_94 ( & V_20 -> V_110 ) ;
goto V_135;
}
V_20 = F_85 ( V_16 , V_136 ) ;
if ( ! F_95 ( V_20 ) )
goto V_135;
switch ( F_96 ( V_20 ) ) {
case - V_132 :
F_97 ( V_18 , V_82 >> 2 ) ;
F_13 ( L_26
L_27 ) ;
break;
case - V_32 :
F_41 ( & V_16 -> V_126 , V_18 , NULL ) ;
F_13 ( L_28 ) ;
}
V_18 -> V_31 = - V_32 ;
return;
V_135:
V_18 -> V_31 = 0 ;
V_18 -> V_21 = V_20 ;
F_98 ( V_18 , V_16 ) ;
}
static void F_99 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( F_90 ( V_16 , V_20 ) )
return;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
F_2 ( & V_16 -> V_137 ) ;
F_100 ( & V_20 -> V_110 , & V_16 -> free ) ;
F_27 ( & V_16 -> V_126 ) ;
F_6 ( & V_16 -> V_137 ) ;
}
static void F_101 ( struct V_15 * V_16 )
{
struct V_19 * V_20 ;
while ( ! F_62 ( & V_16 -> free ) ) {
V_20 = F_102 ( & V_16 -> free , struct V_19 , V_110 ) ;
F_94 ( & V_20 -> V_110 ) ;
F_91 ( V_20 ) ;
}
}
struct V_15 * F_103 ( struct V_138 * V_138 , T_4 V_139 ,
unsigned int V_140 ,
unsigned int V_141 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_142 ;
V_16 = F_88 ( V_139 , V_143 ) ;
if ( V_16 == NULL )
goto V_8;
F_104 ( V_16 , V_138 ) ;
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ ) {
V_20 = F_88 ( sizeof( struct V_19 ) , V_143 ) ;
if ( ! V_20 )
break;
F_100 ( & V_20 -> V_110 , & V_16 -> free ) ;
}
if ( V_142 < V_140 )
goto V_144;
if ( V_141 > V_140 )
V_16 -> V_131 = V_141 ;
else
V_16 -> V_131 = V_140 ;
V_16 -> V_133 = V_140 ;
F_105 ( & V_16 -> V_130 , V_140 ) ;
return V_16 ;
V_144:
F_106 ( V_16 ) ;
V_8:
return NULL ;
}
void F_106 ( struct V_15 * V_16 )
{
F_107 ( V_16 -> V_145 ) ;
F_101 ( V_16 ) ;
F_91 ( V_16 ) ;
}
void F_108 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_51 ;
V_18 -> V_31 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = - V_32 ;
if ( ! F_23 ( V_16 , V_18 ) )
return;
F_2 ( & V_16 -> V_137 ) ;
F_92 ( V_18 ) ;
F_6 ( & V_16 -> V_137 ) ;
F_32 ( V_16 , V_18 ) ;
}
static inline T_2 F_109 ( struct V_15 * V_16 )
{
return ( V_146 T_2 ) V_16 -> V_101 ++ ;
}
static inline void F_110 ( struct V_15 * V_16 )
{
V_16 -> V_101 = F_111 () ;
}
static void F_98 ( struct V_17 * V_18 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
F_112 ( & V_20 -> V_110 ) ;
V_20 -> V_57 = V_18 -> V_64 -> V_69 -> V_80 ;
V_20 -> V_74 = V_18 ;
V_20 -> V_56 = V_16 ;
V_20 -> V_147 = NULL ;
V_20 -> V_103 = F_109 ( V_16 ) ;
V_20 -> V_148 = NULL ;
F_49 ( V_20 ) ;
F_13 ( L_29 , V_18 -> V_29 ,
V_20 , F_68 ( V_20 -> V_103 ) ) ;
}
void F_113 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
if ( ! ( V_20 = V_18 -> V_21 ) )
return;
V_16 = V_20 -> V_56 ;
F_114 ( V_18 ) ;
F_24 ( & V_16 -> V_42 ) ;
V_16 -> V_43 -> V_46 ( V_16 , V_18 ) ;
if ( V_16 -> V_43 -> V_149 )
V_16 -> V_43 -> V_149 ( V_18 ) ;
if ( ! F_62 ( & V_20 -> V_110 ) )
F_94 ( & V_20 -> V_110 ) ;
V_16 -> V_150 = V_79 ;
if ( F_62 ( & V_16 -> V_90 ) && F_79 ( V_16 ) )
F_115 ( & V_16 -> V_58 ,
V_16 -> V_150 + V_16 -> V_114 ) ;
F_25 ( & V_16 -> V_42 ) ;
if ( V_20 -> V_147 )
V_16 -> V_43 -> V_151 ( V_20 -> V_147 ) ;
if ( V_20 -> V_152 != NULL )
F_116 ( V_20 -> V_152 ) ;
V_18 -> V_21 = NULL ;
if ( V_20 -> V_148 )
V_20 -> V_148 ( V_20 ) ;
F_13 ( L_30 , V_18 -> V_29 , V_20 ) ;
if ( F_117 ( ! F_118 ( V_20 ) ) )
F_99 ( V_16 , V_20 ) ;
else
F_119 ( V_20 ) ;
}
static void F_104 ( struct V_15 * V_16 , struct V_138 * V_138 )
{
F_105 ( & V_16 -> V_153 , 1 ) ;
F_120 ( & V_16 -> V_42 ) ;
F_120 ( & V_16 -> V_137 ) ;
F_112 ( & V_16 -> free ) ;
F_112 ( & V_16 -> V_90 ) ;
#if F_121 ( V_154 )
F_120 ( & V_16 -> V_155 ) ;
F_112 ( & V_16 -> V_156 ) ;
#endif
V_16 -> V_150 = V_79 ;
V_16 -> V_49 = V_157 ;
V_16 -> V_158 = 0 ;
F_122 ( & V_16 -> V_159 , L_31 ) ;
F_122 ( & V_16 -> V_54 , L_32 ) ;
F_123 ( & V_16 -> V_36 , L_33 ) ;
F_123 ( & V_16 -> V_126 , L_34 ) ;
F_110 ( V_16 ) ;
V_16 -> V_145 = F_124 ( V_138 ) ;
}
struct V_15 * F_125 ( struct V_160 * args )
{
struct V_15 * V_16 ;
struct V_1 * V_3 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 -> V_7 == args -> V_7 ) {
F_6 ( & V_6 ) ;
goto V_161;
}
}
F_6 ( & V_6 ) ;
F_5 ( V_162 L_35 , args -> V_7 ) ;
return F_86 ( - V_100 ) ;
V_161:
V_16 = V_3 -> V_163 ( args ) ;
if ( F_95 ( V_16 ) ) {
F_13 ( L_36 ,
- F_96 ( V_16 ) ) ;
goto V_8;
}
F_126 ( & V_16 -> V_40 , F_53 ) ;
if ( F_79 ( V_16 ) )
F_127 ( & V_16 -> V_58 , F_61 ,
( unsigned long ) V_16 ) ;
else
F_128 ( & V_16 -> V_58 ) ;
F_13 ( L_37 , V_16 ,
V_16 -> V_131 ) ;
V_8:
return V_16 ;
}
static void F_129 ( struct V_15 * V_16 )
{
F_13 ( L_38 , V_16 ) ;
V_16 -> V_38 = 1 ;
F_130 ( & V_16 -> V_58 ) ;
F_131 ( & V_16 -> V_159 ) ;
F_131 ( & V_16 -> V_54 ) ;
F_131 ( & V_16 -> V_36 ) ;
F_131 ( & V_16 -> V_126 ) ;
F_132 ( & V_16 -> V_40 ) ;
V_16 -> V_43 -> V_164 ( V_16 ) ;
}
void F_133 ( struct V_15 * V_16 )
{
if ( F_134 ( & V_16 -> V_153 ) )
F_129 ( V_16 ) ;
}
struct V_15 * F_135 ( struct V_15 * V_16 )
{
if ( F_136 ( & V_16 -> V_153 ) )
return V_16 ;
return NULL ;
}
