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
int F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
if ( F_12 ( V_23 , & V_21 -> V_24 ) ) {
if ( V_16 == V_21 -> V_25 )
return 1 ;
goto V_26;
}
V_21 -> V_25 = V_16 ;
V_18 -> V_27 = 0 ;
V_18 -> V_28 ++ ;
return 1 ;
V_26:
F_13 ( L_4 ,
V_16 -> V_29 , V_21 ) ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = - V_32 ;
if ( V_18 -> V_28 )
F_14 ( & V_21 -> V_33 , V_16 , NULL ) ;
else
F_14 ( & V_21 -> V_34 , V_16 , NULL ) ;
return 0 ;
}
static void F_15 ( struct V_20 * V_21 )
{
V_21 -> V_25 = NULL ;
if ( ! F_16 ( V_35 , & V_21 -> V_24 ) || V_21 -> V_36 ) {
F_17 () ;
F_18 ( V_23 , & V_21 -> V_24 ) ;
F_19 () ;
} else
F_20 ( V_37 , & V_21 -> V_38 ) ;
}
int F_21 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_16 -> V_39 ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( F_12 ( V_23 , & V_21 -> V_24 ) ) {
if ( V_16 == V_21 -> V_25 )
return 1 ;
goto V_26;
}
if ( F_22 ( V_21 , V_16 ) ) {
V_21 -> V_25 = V_16 ;
if ( V_18 ) {
V_18 -> V_27 = 0 ;
V_18 -> V_28 ++ ;
}
return 1 ;
}
F_15 ( V_21 ) ;
V_26:
F_13 ( L_4 , V_16 -> V_29 , V_21 ) ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = - V_32 ;
if ( V_18 && V_18 -> V_28 )
F_14 ( & V_21 -> V_33 , V_16 , NULL ) ;
else
F_14 ( & V_21 -> V_34 , V_16 , NULL ) ;
return 0 ;
}
static inline int F_23 ( struct V_20 * V_21 , struct V_15 * V_16 )
{
int V_40 ;
F_24 ( & V_21 -> V_41 ) ;
V_40 = V_21 -> V_42 -> V_43 ( V_16 ) ;
F_25 ( & V_21 -> V_41 ) ;
return V_40 ;
}
static void F_26 ( struct V_20 * V_21 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
if ( F_12 ( V_23 , & V_21 -> V_24 ) )
return;
V_16 = F_27 ( & V_21 -> V_33 ) ;
if ( ! V_16 ) {
V_16 = F_27 ( & V_21 -> V_34 ) ;
if ( ! V_16 )
goto V_44;
}
V_18 = V_16 -> V_19 ;
V_21 -> V_25 = V_16 ;
if ( V_18 ) {
V_18 -> V_27 = 0 ;
V_18 -> V_28 ++ ;
}
return;
V_44:
F_15 ( V_21 ) ;
}
static void F_28 ( struct V_20 * V_21 )
{
struct V_15 * V_16 ;
if ( F_12 ( V_23 , & V_21 -> V_24 ) )
return;
if ( F_29 ( V_21 ) )
goto V_44;
V_16 = F_27 ( & V_21 -> V_33 ) ;
if ( ! V_16 ) {
V_16 = F_27 ( & V_21 -> V_34 ) ;
if ( ! V_16 )
goto V_44;
}
if ( F_22 ( V_21 , V_16 ) ) {
struct V_17 * V_18 = V_16 -> V_19 ;
V_21 -> V_25 = V_16 ;
if ( V_18 ) {
V_18 -> V_27 = 0 ;
V_18 -> V_28 ++ ;
}
return;
}
V_44:
F_15 ( V_21 ) ;
}
void F_30 ( struct V_20 * V_21 , struct V_15 * V_16 )
{
if ( V_21 -> V_25 == V_16 ) {
F_15 ( V_21 ) ;
F_26 ( V_21 ) ;
}
}
void F_31 ( struct V_20 * V_21 , struct V_15 * V_16 )
{
if ( V_21 -> V_25 == V_16 ) {
F_15 ( V_21 ) ;
F_28 ( V_21 ) ;
}
}
static inline void F_32 ( struct V_20 * V_21 , struct V_15 * V_16 )
{
F_24 ( & V_21 -> V_41 ) ;
V_21 -> V_42 -> V_45 ( V_21 , V_16 ) ;
F_25 ( & V_21 -> V_41 ) ;
}
static int
F_22 ( struct V_20 * V_21 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
if ( V_18 -> V_46 )
return 1 ;
F_13 ( L_5 ,
V_16 -> V_29 , V_21 -> V_47 , V_21 -> V_48 ) ;
if ( F_29 ( V_21 ) )
return 0 ;
V_18 -> V_46 = 1 ;
V_21 -> V_47 += V_49 ;
return 1 ;
}
static void
F_33 ( struct V_20 * V_21 , struct V_17 * V_18 )
{
if ( ! V_18 -> V_46 )
return;
V_18 -> V_46 = 0 ;
V_21 -> V_47 -= V_49 ;
F_28 ( V_21 ) ;
}
void F_34 ( struct V_15 * V_16 )
{
F_33 ( V_16 -> V_39 , V_16 -> V_19 ) ;
}
void F_35 ( struct V_15 * V_16 , int V_4 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_16 -> V_39 ;
unsigned long V_48 = V_21 -> V_48 ;
if ( V_4 >= 0 && V_48 <= V_21 -> V_47 ) {
V_48 += ( V_49 * V_49 + ( V_48 >> 1 ) ) / V_48 ;
if ( V_48 > F_36 ( V_21 ) )
V_48 = F_36 ( V_21 ) ;
F_28 ( V_21 ) ;
} else if ( V_4 == - V_50 ) {
V_48 >>= 1 ;
if ( V_48 < V_49 )
V_48 = V_49 ;
}
F_13 ( L_6 ,
V_21 -> V_47 , V_21 -> V_48 , V_48 ) ;
V_21 -> V_48 = V_48 ;
F_33 ( V_21 , V_18 ) ;
}
void F_37 ( struct V_20 * V_21 , int V_51 )
{
if ( V_51 < 0 )
F_38 ( & V_21 -> V_52 , V_51 ) ;
else
F_39 ( & V_21 -> V_52 ) ;
}
void F_40 ( struct V_15 * V_16 , T_1 V_53 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
V_16 -> V_30 = V_18 -> V_54 ;
F_14 ( & V_21 -> V_52 , V_16 , V_53 ) ;
}
void F_41 ( struct V_20 * V_21 )
{
if ( F_42 ( V_21 -> V_36 ) )
return;
F_24 ( & V_21 -> V_41 ) ;
if ( V_21 -> V_25 ) {
F_13 ( L_7
L_8 , V_21 ) ;
F_43 ( & V_21 -> V_52 , V_21 -> V_25 ) ;
}
F_25 ( & V_21 -> V_41 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
V_16 -> V_30 = V_16 -> V_19 -> V_54 ;
}
void F_45 ( struct V_15 * V_16 )
{
int V_55 = V_16 -> V_56 . V_57 -> V_58 ;
struct V_59 * V_60 = V_16 -> V_61 ;
struct V_62 * V_63 = V_60 -> V_64 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned long V_65 = V_60 -> V_66 -> V_67 ;
V_16 -> V_30 = F_46 ( V_63 , V_55 ) ;
V_16 -> V_30 <<= F_47 ( V_63 , V_55 ) + V_18 -> V_68 ;
if ( V_16 -> V_30 > V_65 || V_16 -> V_30 == 0 )
V_16 -> V_30 = V_65 ;
}
static void F_48 ( struct V_17 * V_18 )
{
const struct V_69 * V_70 = V_18 -> V_71 -> V_61 -> V_66 ;
V_18 -> V_72 = V_18 -> V_54 ;
if ( V_70 -> V_73 )
V_18 -> V_72 <<= V_70 -> V_74 ;
else
V_18 -> V_72 += V_70 -> V_75 * V_70 -> V_74 ;
if ( V_18 -> V_72 > V_70 -> V_67 || V_18 -> V_72 == 0 )
V_18 -> V_72 = V_70 -> V_67 ;
V_18 -> V_72 += V_76 ;
}
int F_49 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
const struct V_69 * V_70 = V_18 -> V_71 -> V_61 -> V_66 ;
int V_51 = 0 ;
if ( F_50 ( V_76 , V_18 -> V_72 ) ) {
if ( V_70 -> V_73 )
V_18 -> V_54 <<= 1 ;
else
V_18 -> V_54 += V_70 -> V_75 ;
if ( V_70 -> V_67 && V_18 -> V_54 >= V_70 -> V_67 )
V_18 -> V_54 = V_70 -> V_67 ;
V_18 -> V_68 ++ ;
} else {
V_18 -> V_54 = V_70 -> V_77 ;
V_18 -> V_68 = 0 ;
F_48 ( V_18 ) ;
F_24 ( & V_21 -> V_41 ) ;
F_51 ( V_18 -> V_71 -> V_61 -> V_64 , V_70 -> V_77 ) ;
F_25 ( & V_21 -> V_41 ) ;
V_51 = - V_50 ;
}
if ( V_18 -> V_54 == 0 ) {
F_5 ( V_78 L_9 ) ;
V_18 -> V_54 = 5 * V_79 ;
}
return V_51 ;
}
static void F_52 ( struct V_80 * V_81 )
{
struct V_20 * V_21 =
F_53 ( V_81 , struct V_20 , V_38 ) ;
V_21 -> V_42 -> V_82 ( V_21 ) ;
F_18 ( V_35 , & V_21 -> V_24 ) ;
F_32 ( V_21 , NULL ) ;
}
void F_54 ( struct V_20 * V_21 )
{
F_13 ( L_10 , V_21 ) ;
F_24 ( & V_21 -> V_41 ) ;
F_55 ( V_21 ) ;
F_37 ( V_21 , - V_32 ) ;
F_25 ( & V_21 -> V_41 ) ;
}
void F_56 ( struct V_20 * V_21 )
{
F_24 ( & V_21 -> V_41 ) ;
F_57 ( V_35 , & V_21 -> V_24 ) ;
if ( F_12 ( V_23 , & V_21 -> V_24 ) == 0 )
F_20 ( V_37 , & V_21 -> V_38 ) ;
F_37 ( V_21 , - V_32 ) ;
F_25 ( & V_21 -> V_41 ) ;
}
void F_58 ( struct V_20 * V_21 , unsigned int V_83 )
{
F_24 ( & V_21 -> V_41 ) ;
if ( V_83 != V_21 -> V_84 )
goto V_8;
if ( F_16 ( V_85 , & V_21 -> V_24 ) || ! F_59 ( V_21 ) )
goto V_8;
F_57 ( V_35 , & V_21 -> V_24 ) ;
if ( F_12 ( V_23 , & V_21 -> V_24 ) == 0 )
F_20 ( V_37 , & V_21 -> V_38 ) ;
F_37 ( V_21 , - V_32 ) ;
V_8:
F_25 ( & V_21 -> V_41 ) ;
}
static void
F_60 ( unsigned long V_86 )
{
struct V_20 * V_21 = (struct V_20 * ) V_86 ;
F_2 ( & V_21 -> V_41 ) ;
if ( ! F_61 ( & V_21 -> V_87 ) || V_21 -> V_36 )
goto V_88;
if ( F_12 ( V_23 , & V_21 -> V_24 ) )
goto V_88;
F_6 ( & V_21 -> V_41 ) ;
F_57 ( V_89 , & V_21 -> V_24 ) ;
F_20 ( V_37 , & V_21 -> V_38 ) ;
return;
V_88:
F_6 ( & V_21 -> V_41 ) ;
}
void F_62 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_16 -> V_39 ;
F_13 ( L_11 , V_16 -> V_29 ,
V_21 , ( F_59 ( V_21 ) ? L_12 : L_13 ) ) ;
if ( ! F_63 ( V_21 ) ) {
V_16 -> V_31 = - V_32 ;
return;
}
if ( ! F_23 ( V_21 , V_16 ) )
return;
if ( F_64 ( V_35 , & V_21 -> V_24 ) )
V_21 -> V_42 -> V_82 ( V_21 ) ;
if ( F_59 ( V_21 ) )
F_32 ( V_21 , V_16 ) ;
else {
if ( V_16 -> V_19 )
V_16 -> V_19 -> V_27 = 0 ;
V_16 -> V_30 = V_16 -> V_19 -> V_54 ;
F_14 ( & V_21 -> V_52 , V_16 , V_90 ) ;
if ( F_16 ( V_85 , & V_21 -> V_24 ) )
return;
if ( F_65 ( V_21 ) )
return;
V_21 -> V_91 . V_92 = V_76 ;
V_21 -> V_42 -> V_93 ( V_16 ) ;
}
}
static void V_90 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_16 -> V_39 ;
if ( V_16 -> V_31 == 0 ) {
V_21 -> V_91 . V_94 ++ ;
V_21 -> V_91 . V_95 += ( long ) V_76 - V_21 -> V_91 . V_92 ;
F_13 ( L_14 ,
V_16 -> V_29 ) ;
return;
}
switch ( V_16 -> V_31 ) {
case - V_32 :
F_13 ( L_15 , V_16 -> V_29 ) ;
break;
case - V_50 :
F_13 ( L_16
L_17 , V_16 -> V_29 ) ;
break;
default:
F_13 ( L_18
L_19 , V_16 -> V_29 , - V_16 -> V_31 ,
V_16 -> V_61 -> V_96 ) ;
F_32 ( V_21 , V_16 ) ;
V_16 -> V_31 = - V_97 ;
}
}
struct V_17 * F_66 ( struct V_20 * V_21 , T_2 V_98 )
{
struct V_17 * V_99 ;
F_3 (entry, &xprt->recv, rq_list)
if ( V_99 -> V_100 == V_98 )
return V_99 ;
F_13 ( L_20 ,
F_67 ( V_98 ) ) ;
V_21 -> V_91 . V_101 ++ ;
return NULL ;
}
static void F_68 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_62 * V_63 = V_16 -> V_61 -> V_64 ;
unsigned V_55 = V_16 -> V_56 . V_57 -> V_58 ;
long V_102 = F_69 ( F_70 ( V_18 -> V_103 ) ) ;
if ( V_55 ) {
if ( V_18 -> V_28 == 1 )
F_71 ( V_63 , V_55 , V_102 ) ;
F_72 ( V_63 , V_55 , V_18 -> V_28 - 1 ) ;
}
}
void F_73 ( struct V_15 * V_16 , int V_104 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
F_13 ( L_21 ,
V_16 -> V_29 , F_67 ( V_18 -> V_100 ) , V_104 ) ;
V_21 -> V_91 . V_105 ++ ;
V_18 -> V_103 = F_74 ( F_75 () , V_18 -> V_106 ) ;
if ( V_21 -> V_42 -> V_55 != NULL )
F_68 ( V_16 ) ;
F_8 ( & V_18 -> V_107 ) ;
V_18 -> V_108 . V_109 = V_104 ;
F_76 () ;
V_18 -> V_110 = V_104 ;
F_43 ( & V_21 -> V_52 , V_16 ) ;
}
static void F_77 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
if ( V_16 -> V_31 != - V_50 )
return;
F_13 ( L_22 , V_16 -> V_29 ) ;
F_24 ( & V_21 -> V_41 ) ;
if ( ! V_18 -> V_110 ) {
if ( V_21 -> V_42 -> V_55 )
V_21 -> V_42 -> V_55 ( V_16 ) ;
} else
V_16 -> V_31 = 0 ;
F_25 ( & V_21 -> V_41 ) ;
}
static inline int F_78 ( struct V_20 * V_21 )
{
return V_21 -> V_111 != 0 ;
}
int F_79 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
int V_112 = 0 ;
F_13 ( L_23 , V_16 -> V_29 ) ;
F_24 ( & V_21 -> V_41 ) ;
if ( V_18 -> V_110 && ! V_18 -> V_27 ) {
V_112 = V_18 -> V_110 ;
goto V_44;
}
if ( ! V_21 -> V_42 -> V_43 ( V_16 ) )
V_112 = - V_32 ;
V_44:
F_25 ( & V_21 -> V_41 ) ;
return V_112 ;
}
void F_80 ( struct V_15 * V_16 )
{
F_32 ( V_16 -> V_19 -> V_22 , V_16 ) ;
}
void F_81 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
int V_51 ;
F_13 ( L_24 , V_16 -> V_29 , V_18 -> V_113 ) ;
if ( ! V_18 -> V_110 ) {
if ( F_61 ( & V_18 -> V_107 ) && F_82 ( V_16 ) ) {
F_24 ( & V_21 -> V_41 ) ;
memcpy ( & V_18 -> V_108 , & V_18 -> V_114 ,
sizeof( V_18 -> V_108 ) ) ;
F_4 ( & V_18 -> V_107 , & V_21 -> V_87 ) ;
F_25 ( & V_21 -> V_41 ) ;
F_48 ( V_18 ) ;
F_83 ( & V_21 -> V_55 ) ;
}
} else if ( ! V_18 -> V_27 )
return;
V_18 -> V_115 = V_21 -> V_84 ;
V_18 -> V_106 = F_75 () ;
V_51 = V_21 -> V_42 -> V_116 ( V_16 ) ;
if ( V_51 != 0 ) {
V_16 -> V_31 = V_51 ;
return;
}
F_13 ( L_25 , V_16 -> V_29 ) ;
V_16 -> V_117 |= V_118 ;
F_24 ( & V_21 -> V_41 ) ;
V_21 -> V_42 -> V_119 ( V_16 ) ;
V_21 -> V_91 . V_120 ++ ;
V_21 -> V_91 . V_121 += V_21 -> V_91 . V_120 - V_21 -> V_91 . V_105 ;
V_21 -> V_91 . V_122 += V_21 -> V_123 . V_124 ;
if ( ! F_59 ( V_21 ) )
V_16 -> V_31 = - V_125 ;
else if ( ! V_18 -> V_110 && F_82 ( V_16 ) ) {
F_14 ( & V_21 -> V_52 , V_16 , F_77 ) ;
}
F_25 ( & V_21 -> V_41 ) ;
}
static void F_84 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_16 -> V_39 ;
V_16 -> V_31 = 0 ;
if ( V_16 -> V_19 )
return;
if ( ! F_61 ( & V_21 -> free ) ) {
struct V_17 * V_18 = F_85 ( V_21 -> free . V_126 , struct V_17 , V_107 ) ;
F_8 ( & V_18 -> V_107 ) ;
V_16 -> V_19 = V_18 ;
F_86 ( V_16 , V_21 ) ;
return;
}
F_13 ( L_26 ) ;
V_16 -> V_31 = - V_32 ;
V_16 -> V_30 = 0 ;
F_14 ( & V_21 -> V_123 , V_16 , NULL ) ;
}
static void F_87 ( struct V_20 * V_21 , struct V_17 * V_18 )
{
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
F_2 ( & V_21 -> V_127 ) ;
F_88 ( & V_18 -> V_107 , & V_21 -> free ) ;
F_27 ( & V_21 -> V_123 ) ;
F_6 ( & V_21 -> V_127 ) ;
}
struct V_20 * F_89 ( struct V_128 * V_128 , int V_129 , int V_130 )
{
struct V_20 * V_21 ;
V_21 = F_90 ( V_129 , V_131 ) ;
if ( V_21 == NULL )
goto V_8;
F_91 ( & V_21 -> V_132 , 1 ) ;
V_21 -> V_133 = V_130 ;
V_21 -> V_134 = F_92 ( V_130 , sizeof( struct V_17 ) , V_131 ) ;
if ( V_21 -> V_134 == NULL )
goto V_135;
V_21 -> V_136 = F_93 ( V_128 ) ;
return V_21 ;
V_135:
F_94 ( V_21 ) ;
V_8:
return NULL ;
}
void F_95 ( struct V_20 * V_21 )
{
F_96 ( V_21 -> V_136 ) ;
F_94 ( V_21 -> V_134 ) ;
F_94 ( V_21 ) ;
}
void F_97 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_16 -> V_39 ;
V_16 -> V_31 = - V_97 ;
F_2 ( & V_21 -> V_127 ) ;
F_84 ( V_16 ) ;
F_6 ( & V_21 -> V_127 ) ;
}
static inline T_2 F_98 ( struct V_20 * V_21 )
{
return ( V_137 T_2 ) V_21 -> V_98 ++ ;
}
static inline void F_99 ( struct V_20 * V_21 )
{
V_21 -> V_98 = F_100 () ;
}
static void F_86 ( struct V_15 * V_16 , struct V_20 * V_21 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
V_18 -> V_54 = V_16 -> V_61 -> V_66 -> V_77 ;
V_18 -> V_71 = V_16 ;
V_18 -> V_22 = V_21 ;
V_18 -> V_138 = NULL ;
V_18 -> V_100 = F_98 ( V_21 ) ;
V_18 -> V_139 = NULL ;
F_48 ( V_18 ) ;
F_13 ( L_27 , V_16 -> V_29 ,
V_18 , F_67 ( V_18 -> V_100 ) ) ;
}
void F_101 ( struct V_15 * V_16 )
{
struct V_20 * V_21 ;
struct V_17 * V_18 ;
if ( ! ( V_18 = V_16 -> V_19 ) )
return;
V_21 = V_18 -> V_22 ;
F_102 ( V_16 ) ;
F_24 ( & V_21 -> V_41 ) ;
V_21 -> V_42 -> V_45 ( V_21 , V_16 ) ;
if ( V_21 -> V_42 -> V_140 )
V_21 -> V_42 -> V_140 ( V_16 ) ;
if ( ! F_61 ( & V_18 -> V_107 ) )
F_103 ( & V_18 -> V_107 ) ;
V_21 -> V_141 = V_76 ;
if ( F_61 ( & V_21 -> V_87 ) && F_78 ( V_21 ) )
F_104 ( & V_21 -> V_55 ,
V_21 -> V_141 + V_21 -> V_111 ) ;
F_25 ( & V_21 -> V_41 ) ;
if ( V_18 -> V_138 )
V_21 -> V_42 -> V_142 ( V_18 -> V_138 ) ;
if ( V_18 -> V_143 != NULL )
F_105 ( V_18 -> V_143 ) ;
V_16 -> V_19 = NULL ;
if ( V_18 -> V_139 )
V_18 -> V_139 ( V_18 ) ;
F_13 ( L_28 , V_16 -> V_29 , V_18 ) ;
if ( F_106 ( ! F_107 ( V_18 ) ) )
F_87 ( V_21 , V_18 ) ;
else
F_108 ( V_18 ) ;
}
struct V_20 * F_109 ( struct V_144 * args )
{
struct V_20 * V_21 ;
struct V_17 * V_18 ;
struct V_1 * V_3 ;
F_2 ( & V_6 ) ;
F_3 (t, &xprt_list, list) {
if ( V_3 -> V_7 == args -> V_7 ) {
F_6 ( & V_6 ) ;
goto V_145;
}
}
F_6 ( & V_6 ) ;
F_5 ( V_146 L_29 , args -> V_7 ) ;
return F_110 ( - V_97 ) ;
V_145:
V_21 = V_3 -> V_147 ( args ) ;
if ( F_111 ( V_21 ) ) {
F_13 ( L_30 ,
- F_112 ( V_21 ) ) ;
return V_21 ;
}
if ( F_12 ( V_148 , & V_21 -> V_24 ) )
return V_21 ;
F_113 ( & V_21 -> V_41 ) ;
F_113 ( & V_21 -> V_127 ) ;
F_114 ( & V_21 -> free ) ;
F_114 ( & V_21 -> V_87 ) ;
#if F_115 ( V_149 )
F_113 ( & V_21 -> V_150 ) ;
F_114 ( & V_21 -> V_151 ) ;
#endif
F_116 ( & V_21 -> V_38 , F_52 ) ;
if ( F_78 ( V_21 ) )
F_117 ( & V_21 -> V_55 , F_60 ,
( unsigned long ) V_21 ) ;
else
F_118 ( & V_21 -> V_55 ) ;
V_21 -> V_141 = V_76 ;
V_21 -> V_48 = V_152 ;
V_21 -> V_153 = 0 ;
F_119 ( & V_21 -> V_154 , L_31 ) ;
F_119 ( & V_21 -> V_52 , L_32 ) ;
F_119 ( & V_21 -> V_34 , L_33 ) ;
F_119 ( & V_21 -> V_33 , L_34 ) ;
F_120 ( & V_21 -> V_123 , L_35 ) ;
for ( V_18 = & V_21 -> V_134 [ V_21 -> V_133 - 1 ] ; V_18 >= & V_21 -> V_134 [ 0 ] ; V_18 -- )
F_88 ( & V_18 -> V_107 , & V_21 -> free ) ;
F_99 ( V_21 ) ;
F_13 ( L_36 , V_21 ,
V_21 -> V_133 ) ;
return V_21 ;
}
static void F_121 ( struct V_20 * V_21 )
{
F_13 ( L_37 , V_21 ) ;
V_21 -> V_36 = 1 ;
F_122 ( & V_21 -> V_55 ) ;
F_123 ( & V_21 -> V_154 ) ;
F_123 ( & V_21 -> V_52 ) ;
F_123 ( & V_21 -> V_34 ) ;
F_123 ( & V_21 -> V_33 ) ;
F_123 ( & V_21 -> V_123 ) ;
F_124 ( & V_21 -> V_38 ) ;
V_21 -> V_42 -> V_155 ( V_21 ) ;
}
void F_125 ( struct V_20 * V_21 )
{
if ( F_126 ( & V_21 -> V_132 ) )
F_121 ( V_21 ) ;
}
struct V_20 * F_127 ( struct V_20 * V_21 )
{
if ( F_128 ( & V_21 -> V_132 ) )
return V_21 ;
return NULL ;
}
