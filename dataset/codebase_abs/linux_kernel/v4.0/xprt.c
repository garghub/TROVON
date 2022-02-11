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
F_20 ( V_37 , & V_16 -> V_38 ) ;
return;
V_89:
F_6 ( & V_16 -> V_40 ) ;
}
bool F_65 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
void * V_85 )
{
bool V_90 = false ;
F_24 ( & V_16 -> V_40 ) ;
if ( ! F_16 ( V_23 , & V_16 -> V_24 ) )
goto V_8;
if ( V_16 -> V_25 != V_18 )
goto V_8;
V_16 -> V_25 = V_85 ;
V_90 = true ;
V_8:
F_25 ( & V_16 -> V_40 ) ;
return V_90 ;
}
void F_66 ( struct V_15 * V_16 , void * V_85 )
{
F_24 ( & V_16 -> V_40 ) ;
if ( V_16 -> V_25 != V_85 )
goto V_8;
if ( ! F_16 ( V_23 , & V_16 -> V_24 ) )
goto V_8;
V_16 -> V_25 = NULL ;
V_16 -> V_41 -> V_46 ( V_16 , NULL ) ;
V_8:
F_25 ( & V_16 -> V_40 ) ;
}
void F_67 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_21 -> V_51 ;
F_13 ( L_11 , V_18 -> V_28 ,
V_16 , ( F_62 ( V_16 ) ? L_12 : L_13 ) ) ;
if ( ! F_68 ( V_16 ) ) {
V_18 -> V_30 = - V_31 ;
return;
}
if ( ! F_23 ( V_16 , V_18 ) )
return;
if ( F_69 ( V_36 , & V_16 -> V_24 ) )
V_16 -> V_41 -> V_84 ( V_16 ) ;
if ( ! F_62 ( V_16 ) ) {
V_18 -> V_21 -> V_45 = 0 ;
V_18 -> V_29 = V_18 -> V_21 -> V_56 ;
F_44 ( & V_16 -> V_54 , V_18 , V_91 ) ;
if ( F_16 ( V_87 , & V_16 -> V_24 ) )
return;
if ( F_70 ( V_16 ) )
return;
V_16 -> V_92 . V_93 = V_78 ;
V_16 -> V_41 -> V_94 ( V_16 , V_18 ) ;
}
F_34 ( V_16 , V_18 ) ;
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
case - V_97 :
case - V_98 :
case - V_99 :
case - V_100 :
case - V_101 :
case - V_102 :
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
V_16 -> V_103 ) ;
V_18 -> V_30 = - V_104 ;
}
}
struct V_19 * F_71 ( struct V_15 * V_16 , T_2 V_105 )
{
struct V_19 * V_106 ;
F_3 (entry, &xprt->recv, rq_list)
if ( V_106 -> V_107 == V_105 ) {
F_72 ( V_16 , V_105 , 0 ) ;
return V_106 ;
}
F_13 ( L_20 ,
F_73 ( V_105 ) ) ;
F_72 ( V_16 , V_105 , - V_13 ) ;
V_16 -> V_92 . V_108 ++ ;
return NULL ;
}
static void F_74 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_64 * V_65 = V_18 -> V_63 -> V_66 ;
unsigned int V_57 = V_18 -> V_58 . V_59 -> V_60 ;
long V_109 = F_75 ( F_76 ( V_20 -> V_110 ) ) ;
if ( V_57 ) {
if ( V_20 -> V_27 == 1 )
F_77 ( V_65 , V_57 , V_109 ) ;
F_78 ( V_65 , V_57 , V_20 -> V_27 - 1 ) ;
}
}
void F_79 ( struct V_17 * V_18 , int V_111 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
F_13 ( L_21 ,
V_18 -> V_28 , F_73 ( V_20 -> V_107 ) , V_111 ) ;
F_80 ( V_16 , V_20 -> V_107 , V_111 ) ;
V_16 -> V_92 . V_112 ++ ;
V_20 -> V_110 = F_81 ( F_82 () , V_20 -> V_113 ) ;
if ( V_16 -> V_41 -> V_57 != NULL )
F_74 ( V_18 ) ;
F_8 ( & V_20 -> V_114 ) ;
V_20 -> V_115 . V_116 = V_111 ;
F_83 () ;
V_20 -> V_117 = V_111 ;
F_46 ( & V_16 -> V_54 , V_18 ) ;
}
static void F_84 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
if ( V_18 -> V_30 != - V_52 )
return;
F_13 ( L_22 , V_18 -> V_28 ) ;
F_24 ( & V_16 -> V_40 ) ;
if ( ! V_20 -> V_117 ) {
if ( V_16 -> V_41 -> V_57 )
V_16 -> V_41 -> V_57 ( V_16 , V_18 ) ;
} else
V_18 -> V_30 = 0 ;
F_25 ( & V_16 -> V_40 ) ;
}
static inline int F_85 ( struct V_15 * V_16 )
{
return V_16 -> V_118 != 0 ;
}
bool F_86 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
bool V_90 = false ;
F_13 ( L_23 , V_18 -> V_28 ) ;
F_24 ( & V_16 -> V_40 ) ;
if ( ! V_20 -> V_45 ) {
if ( V_20 -> V_117 ) {
V_18 -> V_30 = V_20 -> V_117 ;
goto V_44;
}
if ( ( V_18 -> V_119 & V_120 )
&& F_62 ( V_16 )
&& V_20 -> V_121 == V_16 -> V_86 ) {
V_16 -> V_41 -> V_122 ( V_18 ) ;
F_44 ( & V_16 -> V_54 , V_18 , F_84 ) ;
goto V_44;
}
}
if ( ! V_16 -> V_41 -> V_42 ( V_16 , V_18 ) ) {
V_18 -> V_30 = - V_31 ;
goto V_44;
}
V_90 = true ;
V_44:
F_25 ( & V_16 -> V_40 ) ;
return V_90 ;
}
void F_87 ( struct V_17 * V_18 )
{
F_34 ( V_18 -> V_21 -> V_51 , V_18 ) ;
}
void F_88 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
struct V_15 * V_16 = V_20 -> V_51 ;
int V_53 , V_123 ;
F_13 ( L_24 , V_18 -> V_28 , V_20 -> V_124 ) ;
if ( ! V_20 -> V_117 ) {
if ( F_64 ( & V_20 -> V_114 ) && F_89 ( V_18 ) ) {
F_24 ( & V_16 -> V_40 ) ;
memcpy ( & V_20 -> V_115 , & V_20 -> V_125 ,
sizeof( V_20 -> V_115 ) ) ;
F_4 ( & V_20 -> V_114 , & V_16 -> V_88 ) ;
F_25 ( & V_16 -> V_40 ) ;
F_51 ( V_20 ) ;
F_90 ( & V_16 -> V_57 ) ;
}
} else if ( ! V_20 -> V_45 )
return;
V_20 -> V_113 = F_82 () ;
V_53 = V_16 -> V_41 -> V_126 ( V_18 ) ;
F_91 ( V_16 , V_20 -> V_107 , V_53 ) ;
if ( V_53 != 0 ) {
V_18 -> V_30 = V_53 ;
return;
}
F_13 ( L_25 , V_18 -> V_28 ) ;
V_18 -> V_119 |= V_127 ;
F_24 ( & V_16 -> V_40 ) ;
V_16 -> V_41 -> V_122 ( V_18 ) ;
V_123 = F_92 ( & V_16 -> V_128 ) ;
if ( V_123 > V_16 -> V_92 . V_129 )
V_16 -> V_92 . V_129 = V_123 ;
V_16 -> V_92 . V_130 ++ ;
V_16 -> V_92 . V_131 += V_16 -> V_92 . V_130 - V_16 -> V_92 . V_112 ;
V_16 -> V_92 . V_132 += V_16 -> V_133 . V_134 ;
V_16 -> V_92 . V_135 += V_16 -> V_35 . V_134 ;
V_16 -> V_92 . V_136 += V_16 -> V_54 . V_134 ;
if ( ! F_62 ( V_16 ) )
V_18 -> V_30 = - V_137 ;
else {
if ( ! V_20 -> V_117 && F_89 ( V_18 ) )
F_44 ( & V_16 -> V_54 , V_18 , F_84 ) ;
V_20 -> V_121 = V_16 -> V_86 ;
}
F_25 ( & V_16 -> V_40 ) ;
}
static void F_93 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
F_60 ( V_138 , & V_16 -> V_24 ) ;
F_44 ( & V_16 -> V_133 , V_18 , NULL ) ;
}
static void F_94 ( struct V_15 * V_16 )
{
if ( F_95 ( & V_16 -> V_133 ) == NULL )
F_18 ( V_138 , & V_16 -> V_24 ) ;
}
static bool F_96 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
bool V_90 = false ;
if ( ! F_16 ( V_138 , & V_16 -> V_24 ) )
goto V_8;
F_2 ( & V_16 -> V_139 ) ;
if ( F_16 ( V_138 , & V_16 -> V_24 ) ) {
F_44 ( & V_16 -> V_133 , V_18 , NULL ) ;
V_90 = true ;
}
F_6 ( & V_16 -> V_139 ) ;
V_8:
return V_90 ;
}
static struct V_19 * F_97 ( struct V_15 * V_16 , T_3 V_140 )
{
struct V_19 * V_20 = F_98 ( - V_31 ) ;
if ( ! F_99 ( & V_16 -> V_128 , 1 , V_16 -> V_141 ) )
goto V_8;
V_20 = F_100 ( sizeof( struct V_19 ) , V_140 ) ;
if ( V_20 != NULL )
goto V_8;
F_101 ( & V_16 -> V_128 ) ;
V_20 = F_98 ( - V_142 ) ;
V_8:
return V_20 ;
}
static bool F_102 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
if ( F_99 ( & V_16 -> V_128 , - 1 , V_16 -> V_143 ) ) {
F_103 ( V_20 ) ;
return true ;
}
return false ;
}
void F_104 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_2 ( & V_16 -> V_139 ) ;
if ( ! F_64 ( & V_16 -> free ) ) {
V_20 = F_105 ( V_16 -> free . V_144 , struct V_19 , V_114 ) ;
F_106 ( & V_20 -> V_114 ) ;
goto V_145;
}
V_20 = F_97 ( V_16 , V_146 | V_147 ) ;
if ( ! F_107 ( V_20 ) )
goto V_145;
switch ( F_108 ( V_20 ) ) {
case - V_142 :
F_13 ( L_26
L_27 ) ;
V_18 -> V_30 = - V_142 ;
break;
case - V_31 :
F_93 ( V_16 , V_18 ) ;
F_13 ( L_28 ) ;
default:
V_18 -> V_30 = - V_31 ;
}
F_6 ( & V_16 -> V_139 ) ;
return;
V_145:
V_18 -> V_30 = 0 ;
V_18 -> V_21 = V_20 ;
F_109 ( V_18 , V_16 ) ;
F_6 ( & V_16 -> V_139 ) ;
}
void F_110 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( F_23 ( V_16 , V_18 ) ) {
F_104 ( V_16 , V_18 ) ;
F_34 ( V_16 , V_18 ) ;
}
}
static void F_111 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
F_2 ( & V_16 -> V_139 ) ;
if ( ! F_102 ( V_16 , V_20 ) ) {
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
F_112 ( & V_20 -> V_114 , & V_16 -> free ) ;
}
F_94 ( V_16 ) ;
F_6 ( & V_16 -> V_139 ) ;
}
static void F_113 ( struct V_15 * V_16 )
{
struct V_19 * V_20 ;
while ( ! F_64 ( & V_16 -> free ) ) {
V_20 = F_114 ( & V_16 -> free , struct V_19 , V_114 ) ;
F_106 ( & V_20 -> V_114 ) ;
F_103 ( V_20 ) ;
}
}
struct V_15 * F_115 ( struct V_148 * V_148 , T_4 V_149 ,
unsigned int V_150 ,
unsigned int V_151 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_152 ;
V_16 = F_100 ( V_149 , V_153 ) ;
if ( V_16 == NULL )
goto V_8;
F_116 ( V_16 , V_148 ) ;
for ( V_152 = 0 ; V_152 < V_150 ; V_152 ++ ) {
V_20 = F_100 ( sizeof( struct V_19 ) , V_153 ) ;
if ( ! V_20 )
goto V_154;
F_112 ( & V_20 -> V_114 , & V_16 -> free ) ;
}
if ( V_151 > V_150 )
V_16 -> V_141 = V_151 ;
else
V_16 -> V_141 = V_150 ;
V_16 -> V_143 = V_150 ;
F_117 ( & V_16 -> V_128 , V_150 ) ;
return V_16 ;
V_154:
F_118 ( V_16 ) ;
V_8:
return NULL ;
}
void F_118 ( struct V_15 * V_16 )
{
F_119 ( V_16 -> V_155 ) ;
F_113 ( V_16 ) ;
F_103 ( V_16 ) ;
}
void F_120 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
V_18 -> V_30 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - V_31 ;
F_121 () ;
V_16 = F_122 ( V_18 -> V_63 -> V_156 ) ;
if ( ! F_96 ( V_16 , V_18 ) )
V_16 -> V_41 -> V_157 ( V_16 , V_18 ) ;
F_123 () ;
}
void F_124 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
V_18 -> V_30 = 0 ;
if ( V_18 -> V_21 != NULL )
return;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - V_31 ;
F_121 () ;
V_16 = F_122 ( V_18 -> V_63 -> V_156 ) ;
V_16 -> V_41 -> V_157 ( V_16 , V_18 ) ;
F_123 () ;
}
static inline T_2 F_125 ( struct V_15 * V_16 )
{
return ( V_158 T_2 ) V_16 -> V_105 ++ ;
}
static inline void F_126 ( struct V_15 * V_16 )
{
V_16 -> V_105 = F_127 () ;
}
static void F_109 ( struct V_17 * V_18 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
F_128 ( & V_20 -> V_114 ) ;
V_20 -> V_56 = V_18 -> V_63 -> V_68 -> V_79 ;
V_20 -> V_73 = V_18 ;
V_20 -> V_51 = V_16 ;
V_20 -> V_159 = NULL ;
V_20 -> V_107 = F_125 ( V_16 ) ;
V_20 -> V_121 = V_16 -> V_86 - 1 ;
V_20 -> V_45 = 0 ;
V_20 -> V_160 . V_116 = 0 ;
V_20 -> V_160 . V_161 = 0 ;
V_20 -> V_125 . V_116 = 0 ;
V_20 -> V_125 . V_161 = 0 ;
V_20 -> V_162 = NULL ;
F_51 ( V_20 ) ;
F_13 ( L_29 , V_18 -> V_28 ,
V_20 , F_73 ( V_20 -> V_107 ) ) ;
}
void F_129 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 = V_18 -> V_21 ;
if ( V_20 == NULL ) {
if ( V_18 -> V_63 ) {
F_121 () ;
V_16 = F_122 ( V_18 -> V_63 -> V_156 ) ;
if ( V_16 -> V_25 == V_18 )
F_34 ( V_16 , V_18 ) ;
F_123 () ;
}
return;
}
V_16 = V_20 -> V_51 ;
if ( V_18 -> V_163 -> V_164 != NULL )
V_18 -> V_163 -> V_164 ( V_18 , V_18 -> V_165 ) ;
else if ( V_18 -> V_63 )
F_130 ( V_18 , V_18 -> V_63 -> V_166 ) ;
F_24 ( & V_16 -> V_40 ) ;
V_16 -> V_41 -> V_46 ( V_16 , V_18 ) ;
if ( V_16 -> V_41 -> V_167 )
V_16 -> V_41 -> V_167 ( V_18 ) ;
if ( ! F_64 ( & V_20 -> V_114 ) )
F_106 ( & V_20 -> V_114 ) ;
V_16 -> V_168 = V_78 ;
if ( F_64 ( & V_16 -> V_88 ) && F_85 ( V_16 ) )
F_131 ( & V_16 -> V_57 ,
V_16 -> V_168 + V_16 -> V_118 ) ;
F_25 ( & V_16 -> V_40 ) ;
if ( V_20 -> V_159 )
V_16 -> V_41 -> V_169 ( V_20 -> V_159 ) ;
if ( V_20 -> V_170 != NULL )
F_132 ( V_20 -> V_170 ) ;
V_18 -> V_21 = NULL ;
if ( V_20 -> V_162 )
V_20 -> V_162 ( V_20 ) ;
F_13 ( L_30 , V_18 -> V_28 , V_20 ) ;
if ( F_133 ( ! F_134 ( V_20 ) ) )
F_111 ( V_16 , V_20 ) ;
else
F_135 ( V_20 ) ;
}
static void F_116 ( struct V_15 * V_16 , struct V_148 * V_148 )
{
F_117 ( & V_16 -> V_171 , 1 ) ;
F_136 ( & V_16 -> V_40 ) ;
F_136 ( & V_16 -> V_139 ) ;
F_128 ( & V_16 -> free ) ;
F_128 ( & V_16 -> V_88 ) ;
#if F_137 ( V_172 )
F_136 ( & V_16 -> V_173 ) ;
F_128 ( & V_16 -> V_174 ) ;
#endif
V_16 -> V_168 = V_78 ;
V_16 -> V_49 = V_175 ;
V_16 -> V_176 = 0 ;
F_138 ( & V_16 -> V_177 , L_31 ) ;
F_138 ( & V_16 -> V_54 , L_32 ) ;
F_139 ( & V_16 -> V_35 , L_33 ) ;
F_139 ( & V_16 -> V_133 , L_34 ) ;
F_126 ( V_16 ) ;
V_16 -> V_155 = F_140 ( V_148 ) ;
}
struct V_15 * F_141 ( struct V_178 * args )
{
struct V_15 * V_16 ;
struct V_1 * V_3 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 -> V_7 == args -> V_7 ) {
F_6 ( & V_6 ) ;
goto V_179;
}
}
F_6 ( & V_6 ) ;
F_13 ( L_35 , args -> V_7 ) ;
return F_98 ( - V_104 ) ;
V_179:
V_16 = V_3 -> V_180 ( args ) ;
if ( F_107 ( V_16 ) ) {
F_13 ( L_36 ,
- F_108 ( V_16 ) ) ;
goto V_8;
}
if ( args -> V_181 & V_182 )
V_16 -> V_118 = 0 ;
F_142 ( & V_16 -> V_38 , F_55 ) ;
if ( F_85 ( V_16 ) )
F_143 ( & V_16 -> V_57 , F_63 ,
( unsigned long ) V_16 ) ;
else
F_144 ( & V_16 -> V_57 ) ;
if ( strlen ( args -> V_103 ) > V_183 ) {
F_145 ( V_16 ) ;
return F_98 ( - V_184 ) ;
}
V_16 -> V_103 = F_146 ( args -> V_103 , V_153 ) ;
if ( V_16 -> V_103 == NULL ) {
F_145 ( V_16 ) ;
return F_98 ( - V_142 ) ;
}
F_147 ( V_16 ) ;
F_13 ( L_37 , V_16 ,
V_16 -> V_141 ) ;
V_8:
return V_16 ;
}
static void F_145 ( struct V_15 * V_16 )
{
F_13 ( L_38 , V_16 ) ;
F_148 ( & V_16 -> V_57 ) ;
F_149 ( V_16 ) ;
F_150 ( & V_16 -> V_177 ) ;
F_150 ( & V_16 -> V_54 ) ;
F_150 ( & V_16 -> V_35 ) ;
F_150 ( & V_16 -> V_133 ) ;
F_151 ( & V_16 -> V_38 ) ;
F_103 ( V_16 -> V_103 ) ;
V_16 -> V_41 -> V_185 ( V_16 ) ;
}
void F_152 ( struct V_15 * V_16 )
{
if ( F_153 ( & V_16 -> V_171 ) )
F_145 ( V_16 ) ;
}
