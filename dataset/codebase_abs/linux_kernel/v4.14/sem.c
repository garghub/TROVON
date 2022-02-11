int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = 0 ;
return F_2 ( & V_2 -> V_12 [ V_13 ] ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , & F_5 ( V_2 ) , V_14 ) ;
F_6 ( & V_2 -> V_12 [ V_13 ] . V_15 ) ;
F_7 ( & V_2 -> V_12 [ V_13 ] . V_16 ) ;
}
int T_1 F_8 ( void )
{
const int V_17 = F_1 ( & V_18 ) ;
F_9 ( L_1 ,
L_2 ,
V_13 , V_19 ) ;
return V_17 ;
}
static void F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_24 ;
if ( V_21 -> V_25 )
return;
F_11 (q, tq, &sma->pending_alter, list) {
struct V_26 * V_27 ;
V_27 = & V_21 -> V_28 [ V_23 -> V_29 [ 0 ] . V_30 ] ;
F_12 ( & V_23 -> V_31 , & V_27 -> V_32 ) ;
}
F_13 ( & V_21 -> V_32 ) ;
}
static void F_14 ( struct V_20 * V_21 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ ) {
struct V_26 * V_26 = & V_21 -> V_28 [ V_33 ] ;
F_15 ( & V_26 -> V_32 , & V_21 -> V_32 ) ;
}
}
static void F_16 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_17 ( V_36 , struct V_37 , V_39 ) ;
struct V_20 * V_21 = F_17 ( V_38 , struct V_20 , V_40 ) ;
F_18 ( V_21 ) ;
F_19 ( V_21 ) ;
}
static void F_20 ( struct V_20 * V_21 )
{
int V_33 ;
struct V_26 * V_26 ;
if ( V_21 -> V_41 > 0 ) {
V_21 -> V_41 = V_42 ;
return;
}
V_21 -> V_41 = V_42 ;
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ ) {
V_26 = & V_21 -> V_28 [ V_33 ] ;
F_21 ( & V_26 -> V_43 ) ;
F_22 ( & V_26 -> V_43 ) ;
}
}
static void F_23 ( struct V_20 * V_21 )
{
if ( V_21 -> V_25 ) {
return;
}
if ( V_21 -> V_41 == 1 ) {
F_24 ( & V_21 -> V_41 , 0 ) ;
} else {
V_21 -> V_41 -- ;
}
}
static inline int F_25 ( struct V_20 * V_21 , struct V_44 * V_29 ,
int V_45 )
{
struct V_26 * V_26 ;
if ( V_45 != 1 ) {
F_26 ( & V_21 -> V_40 ) ;
F_20 ( V_21 ) ;
return V_46 ;
}
V_26 = & V_21 -> V_28 [ V_29 -> V_30 ] ;
if ( ! V_21 -> V_41 ) {
F_21 ( & V_26 -> V_43 ) ;
if ( ! F_27 ( & V_21 -> V_41 ) ) {
return V_29 -> V_30 ;
}
F_22 ( & V_26 -> V_43 ) ;
}
F_26 ( & V_21 -> V_40 ) ;
if ( V_21 -> V_41 == 0 ) {
F_21 ( & V_26 -> V_43 ) ;
F_28 ( & V_21 -> V_40 ) ;
return V_29 -> V_30 ;
} else {
return V_46 ;
}
}
static inline void F_29 ( struct V_20 * V_21 , int V_47 )
{
if ( V_47 == V_46 ) {
F_10 ( V_21 ) ;
F_23 ( V_21 ) ;
F_28 ( & V_21 -> V_40 ) ;
} else {
struct V_26 * V_26 = & V_21 -> V_28 [ V_47 ] ;
F_22 ( & V_26 -> V_43 ) ;
}
}
static inline struct V_20 * F_30 ( struct V_1 * V_2 , int V_48 )
{
struct V_37 * V_49 = F_31 ( & F_5 ( V_2 ) , V_48 ) ;
if ( F_32 ( V_49 ) )
return F_33 ( V_49 ) ;
return F_17 ( V_49 , struct V_20 , V_40 ) ;
}
static inline struct V_20 * F_34 ( struct V_1 * V_2 ,
int V_48 )
{
struct V_37 * V_49 = F_35 ( & F_5 ( V_2 ) , V_48 ) ;
if ( F_32 ( V_49 ) )
return F_33 ( V_49 ) ;
return F_17 ( V_49 , struct V_20 , V_40 ) ;
}
static inline void F_36 ( struct V_20 * V_21 )
{
F_25 ( V_21 , NULL , - 1 ) ;
F_37 ( & V_21 -> V_40 , F_16 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , struct V_20 * V_50 )
{
F_39 ( & F_5 ( V_2 ) , & V_50 -> V_40 ) ;
}
static struct V_20 * F_40 ( T_2 V_51 )
{
struct V_20 * V_21 ;
T_2 V_52 ;
if ( V_51 > ( V_53 - sizeof( * V_21 ) ) / sizeof( V_21 -> V_28 [ 0 ] ) )
return NULL ;
V_52 = sizeof( * V_21 ) + V_51 * sizeof( V_21 -> V_28 [ 0 ] ) ;
V_21 = F_41 ( V_52 , V_54 ) ;
if ( F_42 ( ! V_21 ) )
return NULL ;
memset ( V_21 , 0 , V_52 ) ;
return V_21 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
int V_57 ;
struct V_20 * V_21 ;
T_3 V_58 = V_56 -> V_58 ;
int V_51 = V_56 -> V_59 . V_51 ;
int V_60 = V_56 -> V_61 ;
int V_33 ;
if ( ! V_51 )
return - V_62 ;
if ( V_2 -> V_11 + V_51 > V_2 -> V_5 )
return - V_63 ;
V_21 = F_40 ( V_51 ) ;
if ( ! V_21 )
return - V_64 ;
V_21 -> V_40 . V_65 = ( V_60 & V_66 ) ;
V_21 -> V_40 . V_58 = V_58 ;
V_21 -> V_40 . V_67 = NULL ;
V_57 = F_44 ( V_21 ) ;
if ( V_57 ) {
F_19 ( V_21 ) ;
return V_57 ;
}
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
F_13 ( & V_21 -> V_28 [ V_33 ] . V_32 ) ;
F_13 ( & V_21 -> V_28 [ V_33 ] . V_68 ) ;
F_45 ( & V_21 -> V_28 [ V_33 ] . V_43 ) ;
}
V_21 -> V_25 = 0 ;
V_21 -> V_41 = V_42 ;
F_13 ( & V_21 -> V_32 ) ;
F_13 ( & V_21 -> V_68 ) ;
F_13 ( & V_21 -> V_69 ) ;
V_21 -> V_34 = V_51 ;
V_21 -> V_70 = F_46 () ;
V_57 = F_47 ( & F_5 ( V_2 ) , & V_21 -> V_40 , V_2 -> V_9 ) ;
if ( V_57 < 0 ) {
F_48 ( & V_21 -> V_40 . V_39 , F_16 ) ;
return V_57 ;
}
V_2 -> V_11 += V_51 ;
F_29 ( V_21 , - 1 ) ;
F_49 () ;
return V_21 -> V_40 . V_48 ;
}
static inline int F_50 ( struct V_37 * V_49 , int V_60 )
{
struct V_20 * V_21 ;
V_21 = F_17 ( V_49 , struct V_20 , V_40 ) ;
return F_51 ( V_21 , V_60 ) ;
}
static inline int F_52 ( struct V_37 * V_49 ,
struct V_55 * V_56 )
{
struct V_20 * V_21 ;
V_21 = F_17 ( V_49 , struct V_20 , V_40 ) ;
if ( V_56 -> V_59 . V_51 > V_21 -> V_34 )
return - V_62 ;
return 0 ;
}
static int F_53 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
int V_71 , V_72 , V_45 , V_73 ;
struct V_44 * V_74 ;
struct V_26 * V_27 ;
struct V_44 * V_29 ;
struct V_75 * V_76 ;
V_29 = V_23 -> V_29 ;
V_45 = V_23 -> V_45 ;
V_76 = V_23 -> V_77 ;
for ( V_74 = V_29 ; V_74 < V_29 + V_45 ; V_74 ++ ) {
V_27 = & V_21 -> V_28 [ V_74 -> V_30 ] ;
V_72 = V_74 -> V_72 ;
V_71 = V_27 -> V_78 ;
if ( ! V_72 && V_71 )
goto V_79;
V_71 += V_72 ;
if ( V_71 < 0 )
goto V_79;
if ( V_71 > V_80 )
goto V_81;
if ( V_74 -> V_82 & V_83 ) {
int V_77 = V_76 -> V_84 [ V_74 -> V_30 ] - V_72 ;
if ( V_77 < ( - V_85 - 1 ) || V_77 > V_85 )
goto V_81;
V_76 -> V_84 [ V_74 -> V_30 ] = V_77 ;
}
V_27 -> V_78 = V_71 ;
}
V_74 -- ;
V_73 = V_23 -> V_73 ;
while ( V_74 >= V_29 ) {
V_21 -> V_28 [ V_74 -> V_30 ] . V_86 = V_73 ;
V_74 -- ;
}
return 0 ;
V_81:
V_71 = - V_87 ;
goto V_77;
V_79:
V_23 -> V_88 = V_74 ;
if ( V_74 -> V_82 & V_89 )
V_71 = - V_90 ;
else
V_71 = 1 ;
V_77:
V_74 -- ;
while ( V_74 >= V_29 ) {
V_72 = V_74 -> V_72 ;
V_21 -> V_28 [ V_74 -> V_30 ] . V_78 -= V_72 ;
if ( V_74 -> V_82 & V_83 )
V_76 -> V_84 [ V_74 -> V_30 ] += V_72 ;
V_74 -- ;
}
return V_71 ;
}
static int F_54 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
int V_71 , V_72 , V_45 ;
struct V_44 * V_74 ;
struct V_26 * V_27 ;
struct V_44 * V_29 ;
struct V_75 * V_76 ;
V_29 = V_23 -> V_29 ;
V_45 = V_23 -> V_45 ;
V_76 = V_23 -> V_77 ;
if ( F_42 ( V_23 -> V_91 ) )
return F_53 ( V_21 , V_23 ) ;
for ( V_74 = V_29 ; V_74 < V_29 + V_45 ; V_74 ++ ) {
V_27 = & V_21 -> V_28 [ V_74 -> V_30 ] ;
V_72 = V_74 -> V_72 ;
V_71 = V_27 -> V_78 ;
if ( ! V_72 && V_71 )
goto V_79;
V_71 += V_72 ;
if ( V_71 < 0 )
goto V_79;
if ( V_71 > V_80 )
return - V_87 ;
if ( V_74 -> V_82 & V_83 ) {
int V_77 = V_76 -> V_84 [ V_74 -> V_30 ] - V_72 ;
if ( V_77 < ( - V_85 - 1 ) || V_77 > V_85 )
return - V_87 ;
}
}
for ( V_74 = V_29 ; V_74 < V_29 + V_45 ; V_74 ++ ) {
V_27 = & V_21 -> V_28 [ V_74 -> V_30 ] ;
V_72 = V_74 -> V_72 ;
V_71 = V_27 -> V_78 ;
if ( V_74 -> V_82 & V_83 ) {
int V_77 = V_76 -> V_84 [ V_74 -> V_30 ] - V_72 ;
V_76 -> V_84 [ V_74 -> V_30 ] = V_77 ;
}
V_27 -> V_78 += V_72 ;
V_27 -> V_86 = V_23 -> V_73 ;
}
return 0 ;
V_79:
V_23 -> V_88 = V_74 ;
return V_74 -> V_82 & V_89 ? - V_90 : 1 ;
}
static inline void F_55 ( struct V_22 * V_23 , int error ,
struct V_92 * V_93 )
{
F_56 ( V_93 , V_23 -> V_94 ) ;
F_57 ( V_23 -> V_95 , error ) ;
}
static void F_58 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
F_59 ( & V_23 -> V_31 ) ;
if ( V_23 -> V_45 > 1 )
V_21 -> V_25 -- ;
}
static inline int F_60 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
if ( ! F_61 ( & V_21 -> V_32 ) )
return 1 ;
if ( V_23 -> V_45 > 1 )
return 1 ;
return 0 ;
}
static int F_62 ( struct V_20 * V_21 , int V_96 ,
struct V_92 * V_93 )
{
struct V_22 * V_23 , * V_97 ;
struct V_98 * V_99 ;
int V_100 = 0 ;
if ( V_96 == - 1 )
V_99 = & V_21 -> V_68 ;
else
V_99 = & V_21 -> V_28 [ V_96 ] . V_68 ;
F_11 (q, tmp, pending_list, list) {
int error = F_54 ( V_21 , V_23 ) ;
if ( error > 0 )
continue;
F_58 ( V_21 , V_23 ) ;
F_55 ( V_23 , error , V_93 ) ;
if ( error == 0 )
V_100 = 1 ;
}
return V_100 ;
}
static int F_63 ( struct V_20 * V_21 , struct V_44 * V_29 ,
int V_45 , struct V_92 * V_93 )
{
int V_33 ;
int V_100 = 0 ;
int V_101 = 0 ;
if ( V_29 ) {
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
int V_102 = V_29 [ V_33 ] . V_30 ;
if ( V_21 -> V_28 [ V_102 ] . V_78 == 0 ) {
V_101 = 1 ;
V_100 |= F_62 ( V_21 , V_102 , V_93 ) ;
}
}
} else {
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ ) {
if ( V_21 -> V_28 [ V_33 ] . V_78 == 0 ) {
V_101 = 1 ;
V_100 |= F_62 ( V_21 , V_33 , V_93 ) ;
}
}
}
if ( V_101 )
V_100 |= F_62 ( V_21 , - 1 , V_93 ) ;
return V_100 ;
}
static int F_64 ( struct V_20 * V_21 , int V_96 , struct V_92 * V_93 )
{
struct V_22 * V_23 , * V_97 ;
struct V_98 * V_99 ;
int V_100 = 0 ;
if ( V_96 == - 1 )
V_99 = & V_21 -> V_32 ;
else
V_99 = & V_21 -> V_28 [ V_96 ] . V_32 ;
V_103:
F_11 (q, tmp, pending_list, list) {
int error , V_104 ;
if ( V_96 != - 1 && V_21 -> V_28 [ V_96 ] . V_78 == 0 )
break;
error = F_54 ( V_21 , V_23 ) ;
if ( error > 0 )
continue;
F_58 ( V_21 , V_23 ) ;
if ( error ) {
V_104 = 0 ;
} else {
V_100 = 1 ;
F_63 ( V_21 , V_23 -> V_29 , V_23 -> V_45 , V_93 ) ;
V_104 = F_60 ( V_21 , V_23 ) ;
}
F_55 ( V_23 , error , V_93 ) ;
if ( V_104 )
goto V_103;
}
return V_100 ;
}
static void F_65 ( struct V_20 * V_21 , struct V_44 * V_29 )
{
if ( V_29 == NULL ) {
V_21 -> V_28 [ 0 ] . V_105 = F_66 () ;
} else {
V_21 -> V_28 [ V_29 [ 0 ] . V_30 ] . V_105 =
F_66 () ;
}
}
static void F_67 ( struct V_20 * V_21 , struct V_44 * V_29 , int V_45 ,
int V_106 , struct V_92 * V_93 )
{
int V_33 ;
V_106 |= F_63 ( V_21 , V_29 , V_45 , V_93 ) ;
if ( ! F_61 ( & V_21 -> V_32 ) ) {
V_106 |= F_64 ( V_21 , - 1 , V_93 ) ;
} else {
if ( ! V_29 ) {
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ )
V_106 |= F_64 ( V_21 , V_33 , V_93 ) ;
} else {
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
if ( V_29 [ V_33 ] . V_72 > 0 ) {
V_106 |= F_64 ( V_21 ,
V_29 [ V_33 ] . V_30 , V_93 ) ;
}
}
}
}
if ( V_106 )
F_65 ( V_21 , V_29 ) ;
}
static int F_68 ( struct V_20 * V_21 , int V_96 , struct V_22 * V_23 ,
bool V_107 )
{
struct V_44 * V_74 = V_23 -> V_88 ;
F_69 ( L_3
L_4 ,
V_108 -> V_109 , F_70 ( V_108 ) ) ;
if ( V_74 -> V_30 != V_96 )
return 0 ;
if ( V_107 && V_74 -> V_72 == 0 )
return 1 ;
if ( ! V_107 && V_74 -> V_72 < 0 )
return 1 ;
return 0 ;
}
static int F_71 ( struct V_20 * V_21 , T_4 V_96 ,
bool V_107 )
{
struct V_98 * V_110 ;
struct V_22 * V_23 ;
int V_111 ;
V_111 = 0 ;
if ( V_107 )
V_110 = & V_21 -> V_28 [ V_96 ] . V_68 ;
else
V_110 = & V_21 -> V_28 [ V_96 ] . V_32 ;
F_72 (q, l, list) {
V_111 ++ ;
}
F_72 (q, &sma->pending_alter, list) {
V_111 += F_68 ( V_21 , V_96 , V_23 , V_107 ) ;
}
if ( V_107 ) {
F_72 (q, &sma->pending_const, list) {
V_111 += F_68 ( V_21 , V_96 , V_23 , V_107 ) ;
}
}
return V_111 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_37 * V_49 )
{
struct V_75 * V_76 , * V_112 ;
struct V_22 * V_23 , * V_24 ;
struct V_20 * V_21 = F_17 ( V_49 , struct V_20 , V_40 ) ;
int V_33 ;
F_73 ( V_93 ) ;
F_74 ( & V_21 -> V_40 ) ;
F_11 (un, tu, &sma->list_id, list_id) {
F_59 ( & V_76 -> V_69 ) ;
F_21 ( & V_76 -> V_113 -> V_43 ) ;
V_76 -> V_114 = - 1 ;
F_75 ( & V_76 -> V_115 ) ;
F_22 ( & V_76 -> V_113 -> V_43 ) ;
F_76 ( V_76 , V_39 ) ;
}
F_11 (q, tq, &sma->pending_const, list) {
F_58 ( V_21 , V_23 ) ;
F_55 ( V_23 , - V_116 , & V_93 ) ;
}
F_11 (q, tq, &sma->pending_alter, list) {
F_58 ( V_21 , V_23 ) ;
F_55 ( V_23 , - V_116 , & V_93 ) ;
}
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ ) {
struct V_26 * V_26 = & V_21 -> V_28 [ V_33 ] ;
F_11 (q, tq, &sem->pending_const, list) {
F_58 ( V_21 , V_23 ) ;
F_55 ( V_23 , - V_116 , & V_93 ) ;
}
F_11 (q, tq, &sem->pending_alter, list) {
F_58 ( V_21 , V_23 ) ;
F_55 ( V_23 , - V_116 , & V_93 ) ;
}
}
F_38 ( V_2 , V_21 ) ;
F_29 ( V_21 , - 1 ) ;
F_49 () ;
F_77 ( & V_93 ) ;
V_2 -> V_11 -= V_21 -> V_34 ;
F_37 ( & V_21 -> V_40 , F_16 ) ;
}
static unsigned long F_78 ( void T_5 * V_117 , struct V_118 * V_119 , int V_120 )
{
switch ( V_120 ) {
case V_121 :
return F_79 ( V_117 , V_119 , sizeof( * V_119 ) ) ;
case V_122 :
{
struct V_123 V_124 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
F_80 ( & V_119 -> V_40 , & V_124 . V_40 ) ;
V_124 . V_105 = V_119 -> V_105 ;
V_124 . V_70 = V_119 -> V_70 ;
V_124 . V_34 = V_119 -> V_34 ;
return F_79 ( V_117 , & V_124 , sizeof( V_124 ) ) ;
}
default:
return - V_62 ;
}
}
static T_6 F_81 ( struct V_20 * V_21 )
{
int V_33 ;
T_6 V_125 ;
V_125 = V_21 -> V_28 [ 0 ] . V_105 ;
for ( V_33 = 1 ; V_33 < V_21 -> V_34 ; V_33 ++ ) {
T_6 V_126 = V_21 -> V_28 [ V_33 ] . V_105 ;
if ( V_126 > V_125 )
V_125 = V_126 ;
}
return V_125 ;
}
static int F_82 ( struct V_1 * V_2 , int V_114 ,
int V_127 , struct V_118 * V_128 )
{
struct V_20 * V_21 ;
int V_48 = 0 ;
int V_17 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
F_83 () ;
if ( V_127 == V_129 ) {
V_21 = F_30 ( V_2 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
V_17 = F_84 ( V_21 ) ;
goto V_130;
}
V_48 = V_21 -> V_40 . V_48 ;
} else {
V_21 = F_34 ( V_2 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
V_17 = F_84 ( V_21 ) ;
goto V_130;
}
}
V_17 = - V_131 ;
if ( F_85 ( V_2 , & V_21 -> V_40 , V_132 ) )
goto V_130;
V_17 = F_86 ( V_21 , V_127 ) ;
if ( V_17 )
goto V_130;
F_87 ( & V_21 -> V_40 , & V_128 -> V_40 ) ;
V_128 -> V_105 = F_81 ( V_21 ) ;
V_128 -> V_70 = V_21 -> V_70 ;
V_128 -> V_34 = V_21 -> V_34 ;
F_49 () ;
return V_48 ;
V_130:
F_49 () ;
return V_17 ;
}
static int F_88 ( struct V_1 * V_2 , int V_114 ,
int V_127 , void T_5 * V_38 )
{
struct V_133 V_133 ;
int V_134 ;
int V_17 ;
V_17 = F_86 ( NULL , V_127 ) ;
if ( V_17 )
return V_17 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_135 = V_2 -> V_9 ;
V_133 . V_136 = V_2 -> V_5 ;
V_133 . V_137 = V_2 -> V_3 ;
V_133 . V_138 = V_2 -> V_7 ;
V_133 . V_139 = V_80 ;
V_133 . V_140 = V_141 ;
V_133 . V_142 = V_143 ;
V_133 . V_144 = V_145 ;
F_89 ( & F_5 ( V_2 ) . V_146 ) ;
if ( V_127 == V_147 ) {
V_133 . V_148 = F_5 ( V_2 ) . V_149 ;
V_133 . V_150 = V_2 -> V_11 ;
} else {
V_133 . V_148 = V_151 ;
V_133 . V_150 = V_85 ;
}
V_134 = F_90 ( & F_5 ( V_2 ) ) ;
F_91 ( & F_5 ( V_2 ) . V_146 ) ;
if ( F_79 ( V_38 , & V_133 , sizeof( struct V_133 ) ) )
return - V_152 ;
return ( V_134 < 0 ) ? 0 : V_134 ;
}
static int F_92 ( struct V_1 * V_2 , int V_114 , int V_96 ,
int V_153 )
{
struct V_75 * V_76 ;
struct V_20 * V_21 ;
struct V_26 * V_27 ;
int V_17 ;
F_73 ( V_93 ) ;
if ( V_153 > V_80 || V_153 < 0 )
return - V_87 ;
F_83 () ;
V_21 = F_34 ( V_2 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
F_49 () ;
return F_84 ( V_21 ) ;
}
if ( V_96 < 0 || V_96 >= V_21 -> V_34 ) {
F_49 () ;
return - V_62 ;
}
if ( F_85 ( V_2 , & V_21 -> V_40 , V_154 ) ) {
F_49 () ;
return - V_131 ;
}
V_17 = F_86 ( V_21 , V_155 ) ;
if ( V_17 ) {
F_49 () ;
return - V_131 ;
}
F_25 ( V_21 , NULL , - 1 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
F_29 ( V_21 , - 1 ) ;
F_49 () ;
return - V_116 ;
}
V_27 = & V_21 -> V_28 [ V_96 ] ;
F_74 ( & V_21 -> V_40 ) ;
F_72 (un, &sma->list_id, list_id)
V_76 -> V_84 [ V_96 ] = 0 ;
V_27 -> V_78 = V_153 ;
V_27 -> V_86 = F_94 ( V_108 ) ;
V_21 -> V_70 = F_46 () ;
F_67 ( V_21 , NULL , 0 , 0 , & V_93 ) ;
F_29 ( V_21 , - 1 ) ;
F_49 () ;
F_77 ( & V_93 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , int V_114 , int V_96 ,
int V_127 , void T_5 * V_38 )
{
struct V_20 * V_21 ;
struct V_26 * V_27 ;
int V_17 , V_51 ;
T_4 V_156 [ V_157 ] ;
T_4 * V_158 = V_156 ;
F_73 ( V_93 ) ;
F_83 () ;
V_21 = F_34 ( V_2 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
F_49 () ;
return F_84 ( V_21 ) ;
}
V_51 = V_21 -> V_34 ;
V_17 = - V_131 ;
if ( F_85 ( V_2 , & V_21 -> V_40 , V_127 == V_159 ? V_154 : V_132 ) )
goto V_160;
V_17 = F_86 ( V_21 , V_127 ) ;
if ( V_17 )
goto V_160;
V_17 = - V_131 ;
switch ( V_127 ) {
case V_161 :
{
T_4 T_5 * V_162 = V_38 ;
int V_33 ;
F_25 ( V_21 , NULL , - 1 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
V_17 = - V_116 ;
goto V_130;
}
if ( V_51 > V_157 ) {
if ( ! F_96 ( & V_21 -> V_40 ) ) {
V_17 = - V_116 ;
goto V_130;
}
F_29 ( V_21 , - 1 ) ;
F_49 () ;
V_158 = F_97 ( V_51 , sizeof( T_4 ) ,
V_54 ) ;
if ( V_158 == NULL ) {
F_37 ( & V_21 -> V_40 , F_16 ) ;
return - V_64 ;
}
F_83 () ;
F_36 ( V_21 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
V_17 = - V_116 ;
goto V_130;
}
}
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ )
V_158 [ V_33 ] = V_21 -> V_28 [ V_33 ] . V_78 ;
F_29 ( V_21 , - 1 ) ;
F_49 () ;
V_17 = 0 ;
if ( F_79 ( V_162 , V_158 , V_51 * sizeof( T_4 ) ) )
V_17 = - V_152 ;
goto V_163;
}
case V_159 :
{
int V_33 ;
struct V_75 * V_76 ;
if ( ! F_96 ( & V_21 -> V_40 ) ) {
V_17 = - V_116 ;
goto V_160;
}
F_49 () ;
if ( V_51 > V_157 ) {
V_158 = F_97 ( V_51 , sizeof( T_4 ) ,
V_54 ) ;
if ( V_158 == NULL ) {
F_37 ( & V_21 -> V_40 , F_16 ) ;
return - V_64 ;
}
}
if ( F_98 ( V_158 , V_38 , V_51 * sizeof( T_4 ) ) ) {
F_37 ( & V_21 -> V_40 , F_16 ) ;
V_17 = - V_152 ;
goto V_163;
}
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
if ( V_158 [ V_33 ] > V_80 ) {
F_37 ( & V_21 -> V_40 , F_16 ) ;
V_17 = - V_87 ;
goto V_163;
}
}
F_83 () ;
F_36 ( V_21 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
V_17 = - V_116 ;
goto V_130;
}
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
V_21 -> V_28 [ V_33 ] . V_78 = V_158 [ V_33 ] ;
V_21 -> V_28 [ V_33 ] . V_86 = F_94 ( V_108 ) ;
}
F_74 ( & V_21 -> V_40 ) ;
F_72 (un, &sma->list_id, list_id) {
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ )
V_76 -> V_84 [ V_33 ] = 0 ;
}
V_21 -> V_70 = F_46 () ;
F_67 ( V_21 , NULL , 0 , 0 , & V_93 ) ;
V_17 = 0 ;
goto V_130;
}
}
V_17 = - V_62 ;
if ( V_96 < 0 || V_96 >= V_51 )
goto V_160;
F_25 ( V_21 , NULL , - 1 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
V_17 = - V_116 ;
goto V_130;
}
V_27 = & V_21 -> V_28 [ V_96 ] ;
switch ( V_127 ) {
case V_164 :
V_17 = V_27 -> V_78 ;
goto V_130;
case V_165 :
V_17 = V_27 -> V_86 ;
goto V_130;
case V_166 :
V_17 = F_71 ( V_21 , V_96 , 0 ) ;
goto V_130;
case V_167 :
V_17 = F_71 ( V_21 , V_96 , 1 ) ;
goto V_130;
}
V_130:
F_29 ( V_21 , - 1 ) ;
V_160:
F_49 () ;
F_77 ( & V_93 ) ;
V_163:
if ( V_158 != V_156 )
F_19 ( V_158 ) ;
return V_17 ;
}
static inline unsigned long
F_99 ( struct V_118 * V_124 , void T_5 * V_117 , int V_120 )
{
switch ( V_120 ) {
case V_121 :
if ( F_98 ( V_124 , V_117 , sizeof( * V_124 ) ) )
return - V_152 ;
return 0 ;
case V_122 :
{
struct V_123 V_168 ;
if ( F_98 ( & V_168 , V_117 , sizeof( V_168 ) ) )
return - V_152 ;
V_124 -> V_40 . V_169 = V_168 . V_40 . V_169 ;
V_124 -> V_40 . V_170 = V_168 . V_40 . V_170 ;
V_124 -> V_40 . V_65 = V_168 . V_40 . V_65 ;
return 0 ;
}
default:
return - V_62 ;
}
}
static int F_100 ( struct V_1 * V_2 , int V_114 ,
int V_127 , struct V_118 * V_128 )
{
struct V_20 * V_21 ;
int V_17 ;
struct V_37 * V_49 ;
F_101 ( & F_5 ( V_2 ) . V_146 ) ;
F_83 () ;
V_49 = F_102 ( V_2 , & F_5 ( V_2 ) , V_114 , V_127 ,
& V_128 -> V_40 , 0 ) ;
if ( F_32 ( V_49 ) ) {
V_17 = F_84 ( V_49 ) ;
goto V_171;
}
V_21 = F_17 ( V_49 , struct V_20 , V_40 ) ;
V_17 = F_86 ( V_21 , V_127 ) ;
if ( V_17 )
goto V_171;
switch ( V_127 ) {
case V_172 :
F_25 ( V_21 , NULL , - 1 ) ;
V_14 ( V_2 , V_49 ) ;
goto V_173;
case V_174 :
F_25 ( V_21 , NULL , - 1 ) ;
V_17 = F_103 ( & V_128 -> V_40 , V_49 ) ;
if ( V_17 )
goto V_175;
V_21 -> V_70 = F_46 () ;
break;
default:
V_17 = - V_62 ;
goto V_171;
}
V_175:
F_29 ( V_21 , - 1 ) ;
V_171:
F_49 () ;
V_173:
F_104 ( & F_5 ( V_2 ) . V_146 ) ;
return V_17 ;
}
static int F_105 ( struct V_118 * V_124 , void T_5 * V_117 ,
int V_120 )
{
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
if ( V_120 == V_121 ) {
struct V_176 * V_38 = V_117 ;
return F_106 ( & V_124 -> V_40 , & V_38 -> V_40 ) ;
} else {
struct V_177 * V_38 = V_117 ;
return F_107 ( & V_124 -> V_40 , & V_38 -> V_40 ) ;
}
}
static int F_108 ( void T_5 * V_117 , struct V_118 * V_119 ,
int V_120 )
{
if ( V_120 == V_121 ) {
struct V_176 V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
F_109 ( & V_178 . V_40 , & V_119 -> V_40 ) ;
V_178 . V_105 = V_119 -> V_105 ;
V_178 . V_70 = V_119 -> V_70 ;
V_178 . V_34 = V_119 -> V_34 ;
return F_79 ( V_117 , & V_178 , sizeof( V_178 ) ) ;
} else {
struct V_177 V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
F_110 ( & V_178 . V_40 , & V_119 -> V_40 ) ;
V_178 . V_105 = V_119 -> V_105 ;
V_178 . V_70 = V_119 -> V_70 ;
V_178 . V_34 = V_119 -> V_34 ;
return F_79 ( V_117 , & V_178 , sizeof( V_178 ) ) ;
}
}
static inline int F_111 ( struct V_179 * * V_180 )
{
struct V_179 * V_181 ;
V_181 = V_108 -> V_182 . V_181 ;
if ( ! V_181 ) {
V_181 = F_112 ( sizeof( * V_181 ) , V_54 ) ;
if ( V_181 == NULL )
return - V_64 ;
F_45 ( & V_181 -> V_43 ) ;
F_113 ( & V_181 -> V_183 , 1 ) ;
F_13 ( & V_181 -> V_115 ) ;
V_108 -> V_182 . V_181 = V_181 ;
}
* V_180 = V_181 ;
return 0 ;
}
static struct V_75 * F_114 ( struct V_179 * V_113 , int V_114 )
{
struct V_75 * V_76 ;
F_115 (un, &ulp->list_proc, list_proc) {
if ( V_76 -> V_114 == V_114 )
return V_76 ;
}
return NULL ;
}
static struct V_75 * F_116 ( struct V_179 * V_113 , int V_114 )
{
struct V_75 * V_76 ;
F_117 ( & V_113 -> V_43 ) ;
V_76 = F_114 ( V_113 , V_114 ) ;
if ( V_76 ) {
F_75 ( & V_76 -> V_115 ) ;
F_118 ( & V_76 -> V_115 , & V_113 -> V_115 ) ;
}
return V_76 ;
}
static struct V_75 * F_119 ( struct V_1 * V_2 , int V_114 )
{
struct V_20 * V_21 ;
struct V_179 * V_113 ;
struct V_75 * V_76 , * V_184 ;
int V_51 , error ;
error = F_111 ( & V_113 ) ;
if ( error )
return F_120 ( error ) ;
F_83 () ;
F_21 ( & V_113 -> V_43 ) ;
V_76 = F_116 ( V_113 , V_114 ) ;
F_22 ( & V_113 -> V_43 ) ;
if ( F_121 ( V_76 != NULL ) )
goto V_124;
V_21 = F_34 ( V_2 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
F_49 () ;
return F_33 ( V_21 ) ;
}
V_51 = V_21 -> V_34 ;
if ( ! F_96 ( & V_21 -> V_40 ) ) {
F_49 () ;
V_76 = F_120 ( - V_116 ) ;
goto V_124;
}
F_49 () ;
V_184 = F_112 ( sizeof( struct V_75 ) + sizeof( short ) * V_51 , V_54 ) ;
if ( ! V_184 ) {
F_37 ( & V_21 -> V_40 , F_16 ) ;
return F_120 ( - V_64 ) ;
}
F_83 () ;
F_36 ( V_21 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
F_29 ( V_21 , - 1 ) ;
F_49 () ;
F_122 ( V_184 ) ;
V_76 = F_120 ( - V_116 ) ;
goto V_124;
}
F_21 ( & V_113 -> V_43 ) ;
V_76 = F_116 ( V_113 , V_114 ) ;
if ( V_76 ) {
F_122 ( V_184 ) ;
goto V_185;
}
V_184 -> V_84 = ( short * ) & V_184 [ 1 ] ;
V_184 -> V_113 = V_113 ;
V_184 -> V_114 = V_114 ;
F_117 ( & V_113 -> V_43 ) ;
F_118 ( & V_184 -> V_115 , & V_113 -> V_115 ) ;
F_74 ( & V_21 -> V_40 ) ;
F_123 ( & V_184 -> V_69 , & V_21 -> V_69 ) ;
V_76 = V_184 ;
V_185:
F_22 ( & V_113 -> V_43 ) ;
F_29 ( V_21 , - 1 ) ;
V_124:
return V_76 ;
}
static long F_124 ( int V_114 , struct V_44 T_5 * V_186 ,
unsigned V_45 , const struct V_187 * V_188 )
{
int error = - V_62 ;
struct V_20 * V_21 ;
struct V_44 V_189 [ V_190 ] ;
struct V_44 * V_29 = V_189 , * V_74 ;
struct V_75 * V_76 ;
int V_191 , V_47 ;
bool V_192 = false , V_193 = false , V_91 = false ;
struct V_22 V_194 ;
unsigned long V_195 = 0 , V_196 = 0 ;
struct V_1 * V_2 ;
V_2 = V_108 -> V_197 -> V_198 ;
if ( V_45 < 1 || V_114 < 0 )
return - V_62 ;
if ( V_45 > V_2 -> V_7 )
return - V_199 ;
if ( V_45 > V_190 ) {
V_29 = F_41 ( sizeof( * V_29 ) * V_45 , V_54 ) ;
if ( V_29 == NULL )
return - V_64 ;
}
if ( F_98 ( V_29 , V_186 , V_45 * sizeof( * V_186 ) ) ) {
error = - V_152 ;
goto V_163;
}
if ( V_188 ) {
if ( V_188 -> V_200 < 0 || V_188 -> V_201 < 0 ||
V_188 -> V_201 >= 1000000000L ) {
error = - V_62 ;
goto V_163;
}
V_196 = F_125 ( V_188 ) ;
}
V_191 = 0 ;
for ( V_74 = V_29 ; V_74 < V_29 + V_45 ; V_74 ++ ) {
unsigned long V_202 = 1ULL << ( ( V_74 -> V_30 ) % V_203 ) ;
if ( V_74 -> V_30 >= V_191 )
V_191 = V_74 -> V_30 ;
if ( V_74 -> V_82 & V_83 )
V_192 = true ;
if ( V_195 & V_202 ) {
V_91 = true ;
}
if ( V_74 -> V_72 != 0 ) {
V_193 = true ;
V_195 |= V_202 ;
}
}
if ( V_192 ) {
V_76 = F_119 ( V_2 , V_114 ) ;
if ( F_32 ( V_76 ) ) {
error = F_84 ( V_76 ) ;
goto V_163;
}
} else {
V_76 = NULL ;
F_83 () ;
}
V_21 = F_34 ( V_2 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
F_49 () ;
error = F_84 ( V_21 ) ;
goto V_163;
}
error = - V_204 ;
if ( V_191 >= V_21 -> V_34 ) {
F_49 () ;
goto V_163;
}
error = - V_131 ;
if ( F_85 ( V_2 , & V_21 -> V_40 , V_193 ? V_154 : V_132 ) ) {
F_49 () ;
goto V_163;
}
error = F_126 ( V_21 , V_29 , V_45 , V_193 ) ;
if ( error ) {
F_49 () ;
goto V_163;
}
error = - V_116 ;
V_47 = F_25 ( V_21 , V_29 , V_45 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) )
goto V_205;
if ( V_76 && V_76 -> V_114 == - 1 )
goto V_205;
V_194 . V_29 = V_29 ;
V_194 . V_45 = V_45 ;
V_194 . V_77 = V_76 ;
V_194 . V_73 = F_94 ( V_108 ) ;
V_194 . V_193 = V_193 ;
V_194 . V_91 = V_91 ;
error = F_54 ( V_21 , & V_194 ) ;
if ( error == 0 ) {
F_73 ( V_93 ) ;
if ( V_193 )
F_67 ( V_21 , V_29 , V_45 , 1 , & V_93 ) ;
else
F_65 ( V_21 , V_29 ) ;
F_29 ( V_21 , V_47 ) ;
F_49 () ;
F_77 ( & V_93 ) ;
goto V_163;
}
if ( error < 0 )
goto V_205;
if ( V_45 == 1 ) {
struct V_26 * V_27 ;
V_27 = & V_21 -> V_28 [ V_29 -> V_30 ] ;
if ( V_193 ) {
if ( V_21 -> V_25 ) {
F_12 ( & V_194 . V_31 ,
& V_21 -> V_32 ) ;
} else {
F_12 ( & V_194 . V_31 ,
& V_27 -> V_32 ) ;
}
} else {
F_12 ( & V_194 . V_31 , & V_27 -> V_68 ) ;
}
} else {
if ( ! V_21 -> V_25 )
F_14 ( V_21 ) ;
if ( V_193 )
F_12 ( & V_194 . V_31 , & V_21 -> V_32 ) ;
else
F_12 ( & V_194 . V_31 , & V_21 -> V_68 ) ;
V_21 -> V_25 ++ ;
}
do {
V_194 . V_95 = - V_206 ;
V_194 . V_94 = V_108 ;
F_127 ( V_207 ) ;
F_29 ( V_21 , V_47 ) ;
F_49 () ;
if ( V_188 )
V_196 = F_128 ( V_196 ) ;
else
F_129 () ;
error = F_130 ( V_194 . V_95 ) ;
if ( error != - V_206 ) {
F_131 () ;
goto V_163;
}
F_83 () ;
V_47 = F_25 ( V_21 , V_29 , V_45 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) )
goto V_205;
error = F_130 ( V_194 . V_95 ) ;
if ( error != - V_206 )
goto V_205;
if ( V_188 && V_196 == 0 )
error = - V_90 ;
} while ( error == - V_206 && ! F_132 ( V_108 ) );
F_58 ( V_21 , & V_194 ) ;
V_205:
F_29 ( V_21 , V_47 ) ;
F_49 () ;
V_163:
if ( V_29 != V_189 )
F_19 ( V_29 ) ;
return error ;
}
int F_133 ( unsigned long V_208 , struct V_209 * V_210 )
{
struct V_179 * V_181 ;
int error ;
if ( V_208 & V_211 ) {
error = F_111 ( & V_181 ) ;
if ( error )
return error ;
F_134 ( & V_181 -> V_183 ) ;
V_210 -> V_182 . V_181 = V_181 ;
} else
V_210 -> V_182 . V_181 = NULL ;
return 0 ;
}
void F_135 ( struct V_209 * V_210 )
{
struct V_179 * V_113 ;
V_113 = V_210 -> V_182 . V_181 ;
if ( ! V_113 )
return;
V_210 -> V_182 . V_181 = NULL ;
if ( ! F_136 ( & V_113 -> V_183 ) )
return;
for (; ; ) {
struct V_20 * V_21 ;
struct V_75 * V_76 ;
int V_114 , V_33 ;
F_73 ( V_93 ) ;
F_137 () ;
F_83 () ;
V_76 = F_138 ( V_113 -> V_115 . V_212 ,
struct V_75 , V_115 ) ;
if ( & V_76 -> V_115 == & V_113 -> V_115 ) {
F_21 ( & V_113 -> V_43 ) ;
F_22 ( & V_113 -> V_43 ) ;
F_49 () ;
break;
}
F_21 ( & V_113 -> V_43 ) ;
V_114 = V_76 -> V_114 ;
F_22 ( & V_113 -> V_43 ) ;
if ( V_114 == - 1 ) {
F_49 () ;
continue;
}
V_21 = F_34 ( V_210 -> V_197 -> V_198 , V_114 ) ;
if ( F_32 ( V_21 ) ) {
F_49 () ;
continue;
}
F_25 ( V_21 , NULL , - 1 ) ;
if ( ! F_93 ( & V_21 -> V_40 ) ) {
F_29 ( V_21 , - 1 ) ;
F_49 () ;
continue;
}
V_76 = F_114 ( V_113 , V_114 ) ;
if ( V_76 == NULL ) {
F_29 ( V_21 , - 1 ) ;
F_49 () ;
continue;
}
F_74 ( & V_21 -> V_40 ) ;
F_59 ( & V_76 -> V_69 ) ;
F_75 ( & V_76 -> V_115 ) ;
for ( V_33 = 0 ; V_33 < V_21 -> V_34 ; V_33 ++ ) {
struct V_26 * V_213 = & V_21 -> V_28 [ V_33 ] ;
if ( V_76 -> V_84 [ V_33 ] ) {
V_213 -> V_78 += V_76 -> V_84 [ V_33 ] ;
if ( V_213 -> V_78 < 0 )
V_213 -> V_78 = 0 ;
if ( V_213 -> V_78 > V_80 )
V_213 -> V_78 = V_80 ;
V_213 -> V_86 = F_94 ( V_108 ) ;
}
}
F_67 ( V_21 , NULL , 0 , 1 , & V_93 ) ;
F_29 ( V_21 , - 1 ) ;
F_49 () ;
F_77 ( & V_93 ) ;
F_76 ( V_76 , V_39 ) ;
}
F_122 ( V_113 ) ;
}
static int V_19 ( struct V_214 * V_50 , void * V_215 )
{
struct V_216 * V_217 = F_139 ( V_50 ) ;
struct V_37 * V_49 = V_215 ;
struct V_20 * V_21 = F_17 ( V_49 , struct V_20 , V_40 ) ;
T_6 V_105 ;
F_20 ( V_21 ) ;
V_105 = F_81 ( V_21 ) ;
F_140 ( V_50 ,
L_5 ,
V_21 -> V_40 . V_58 ,
V_21 -> V_40 . V_48 ,
V_21 -> V_40 . V_65 ,
V_21 -> V_34 ,
F_141 ( V_217 , V_21 -> V_40 . V_169 ) ,
F_142 ( V_217 , V_21 -> V_40 . V_170 ) ,
F_141 ( V_217 , V_21 -> V_40 . V_218 ) ,
F_142 ( V_217 , V_21 -> V_40 . V_219 ) ,
V_105 ,
V_21 -> V_70 ) ;
F_23 ( V_21 ) ;
return 0 ;
}
