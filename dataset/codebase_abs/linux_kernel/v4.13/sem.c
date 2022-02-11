void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = 0 ;
F_2 ( & V_2 -> V_12 [ V_13 ] ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , & F_5 ( V_2 ) , V_14 ) ;
F_6 ( & V_2 -> V_12 [ V_13 ] . V_15 ) ;
}
void T_1 F_7 ( void )
{
F_1 ( & V_16 ) ;
F_8 ( L_1 ,
L_2 ,
V_13 , V_17 ) ;
}
static void F_9 ( struct V_18 * V_19 )
{
struct V_20 * V_21 , * V_22 ;
if ( V_19 -> V_23 )
return;
F_10 (q, tq, &sma->pending_alter, list) {
struct V_24 * V_25 ;
V_25 = & V_19 -> V_26 [ V_21 -> V_27 [ 0 ] . V_28 ] ;
F_11 ( & V_21 -> V_29 , & V_25 -> V_30 ) ;
}
F_12 ( & V_19 -> V_30 ) ;
}
static void F_13 ( struct V_18 * V_19 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = & V_19 -> V_26 [ V_31 ] ;
F_14 ( & V_24 -> V_30 , & V_19 -> V_30 ) ;
}
}
static void F_15 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_16 ( V_34 , struct V_35 , V_37 ) ;
struct V_18 * V_19 = F_16 ( V_36 , struct V_18 , V_38 ) ;
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static void F_19 ( struct V_18 * V_19 )
{
int V_31 ;
struct V_24 * V_24 ;
if ( V_19 -> V_39 > 0 ) {
V_19 -> V_39 = V_40 ;
return;
}
V_19 -> V_39 = V_40 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
V_24 = & V_19 -> V_26 [ V_31 ] ;
F_20 ( & V_24 -> V_41 ) ;
F_21 ( & V_24 -> V_41 ) ;
}
}
static void F_22 ( struct V_18 * V_19 )
{
if ( V_19 -> V_23 ) {
return;
}
if ( V_19 -> V_39 == 1 ) {
F_23 ( & V_19 -> V_39 , 0 ) ;
} else {
V_19 -> V_39 -- ;
}
}
static inline int F_24 ( struct V_18 * V_19 , struct V_42 * V_27 ,
int V_43 )
{
struct V_24 * V_24 ;
if ( V_43 != 1 ) {
F_25 ( & V_19 -> V_38 ) ;
F_19 ( V_19 ) ;
return V_44 ;
}
V_24 = & V_19 -> V_26 [ V_27 -> V_28 ] ;
if ( ! V_19 -> V_39 ) {
F_20 ( & V_24 -> V_41 ) ;
if ( ! F_26 ( & V_19 -> V_39 ) ) {
return V_27 -> V_28 ;
}
F_21 ( & V_24 -> V_41 ) ;
}
F_25 ( & V_19 -> V_38 ) ;
if ( V_19 -> V_39 == 0 ) {
F_20 ( & V_24 -> V_41 ) ;
F_27 ( & V_19 -> V_38 ) ;
return V_27 -> V_28 ;
} else {
return V_44 ;
}
}
static inline void F_28 ( struct V_18 * V_19 , int V_45 )
{
if ( V_45 == V_44 ) {
F_9 ( V_19 ) ;
F_22 ( V_19 ) ;
F_27 ( & V_19 -> V_38 ) ;
} else {
struct V_24 * V_24 = & V_19 -> V_26 [ V_45 ] ;
F_21 ( & V_24 -> V_41 ) ;
}
}
static inline struct V_18 * F_29 ( struct V_1 * V_2 , int V_46 )
{
struct V_35 * V_47 = F_30 ( & F_5 ( V_2 ) , V_46 ) ;
if ( F_31 ( V_47 ) )
return F_32 ( V_47 ) ;
return F_16 ( V_47 , struct V_18 , V_38 ) ;
}
static inline struct V_18 * F_33 ( struct V_1 * V_2 ,
int V_46 )
{
struct V_35 * V_47 = F_34 ( & F_5 ( V_2 ) , V_46 ) ;
if ( F_31 ( V_47 ) )
return F_32 ( V_47 ) ;
return F_16 ( V_47 , struct V_18 , V_38 ) ;
}
static inline void F_35 ( struct V_18 * V_19 )
{
F_24 ( V_19 , NULL , - 1 ) ;
F_36 ( & V_19 -> V_38 , F_15 ) ;
}
static inline void F_37 ( struct V_1 * V_2 , struct V_18 * V_48 )
{
F_38 ( & F_5 ( V_2 ) , & V_48 -> V_38 ) ;
}
static struct V_18 * F_39 ( T_2 V_49 )
{
struct V_18 * V_19 ;
T_2 V_50 ;
if ( V_49 > ( V_51 - sizeof( * V_19 ) ) / sizeof( V_19 -> V_26 [ 0 ] ) )
return NULL ;
V_50 = sizeof( * V_19 ) + V_49 * sizeof( V_19 -> V_26 [ 0 ] ) ;
V_19 = F_40 ( V_50 , V_52 ) ;
if ( F_41 ( ! V_19 ) )
return NULL ;
memset ( V_19 , 0 , V_50 ) ;
return V_19 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
int V_55 ;
struct V_18 * V_19 ;
T_3 V_56 = V_54 -> V_56 ;
int V_49 = V_54 -> V_57 . V_49 ;
int V_58 = V_54 -> V_59 ;
int V_31 ;
if ( ! V_49 )
return - V_60 ;
if ( V_2 -> V_11 + V_49 > V_2 -> V_5 )
return - V_61 ;
V_19 = F_39 ( V_49 ) ;
if ( ! V_19 )
return - V_62 ;
V_19 -> V_38 . V_63 = ( V_58 & V_64 ) ;
V_19 -> V_38 . V_56 = V_56 ;
V_19 -> V_38 . V_65 = NULL ;
V_55 = F_43 ( V_19 ) ;
if ( V_55 ) {
F_18 ( V_19 ) ;
return V_55 ;
}
for ( V_31 = 0 ; V_31 < V_49 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_66 ) ;
F_44 ( & V_19 -> V_26 [ V_31 ] . V_41 ) ;
}
V_19 -> V_23 = 0 ;
V_19 -> V_39 = V_40 ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_66 ) ;
F_12 ( & V_19 -> V_67 ) ;
V_19 -> V_32 = V_49 ;
V_19 -> V_68 = F_45 () ;
V_55 = F_46 ( & F_5 ( V_2 ) , & V_19 -> V_38 , V_2 -> V_9 ) ;
if ( V_55 < 0 ) {
F_47 ( & V_19 -> V_38 . V_37 , F_15 ) ;
return V_55 ;
}
V_2 -> V_11 += V_49 ;
F_28 ( V_19 , - 1 ) ;
F_48 () ;
return V_19 -> V_38 . V_46 ;
}
static inline int F_49 ( struct V_35 * V_47 , int V_58 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_47 , struct V_18 , V_38 ) ;
return F_50 ( V_19 , V_58 ) ;
}
static inline int F_51 ( struct V_35 * V_47 ,
struct V_53 * V_54 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_47 , struct V_18 , V_38 ) ;
if ( V_54 -> V_57 . V_49 > V_19 -> V_32 )
return - V_60 ;
return 0 ;
}
static int F_52 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_69 , V_70 , V_43 , V_71 ;
struct V_42 * V_72 ;
struct V_24 * V_25 ;
struct V_42 * V_27 ;
struct V_73 * V_74 ;
V_27 = V_21 -> V_27 ;
V_43 = V_21 -> V_43 ;
V_74 = V_21 -> V_75 ;
for ( V_72 = V_27 ; V_72 < V_27 + V_43 ; V_72 ++ ) {
V_25 = & V_19 -> V_26 [ V_72 -> V_28 ] ;
V_70 = V_72 -> V_70 ;
V_69 = V_25 -> V_76 ;
if ( ! V_70 && V_69 )
goto V_77;
V_69 += V_70 ;
if ( V_69 < 0 )
goto V_77;
if ( V_69 > V_78 )
goto V_79;
if ( V_72 -> V_80 & V_81 ) {
int V_75 = V_74 -> V_82 [ V_72 -> V_28 ] - V_70 ;
if ( V_75 < ( - V_83 - 1 ) || V_75 > V_83 )
goto V_79;
V_74 -> V_82 [ V_72 -> V_28 ] = V_75 ;
}
V_25 -> V_76 = V_69 ;
}
V_72 -- ;
V_71 = V_21 -> V_71 ;
while ( V_72 >= V_27 ) {
V_19 -> V_26 [ V_72 -> V_28 ] . V_84 = V_71 ;
V_72 -- ;
}
return 0 ;
V_79:
V_69 = - V_85 ;
goto V_75;
V_77:
V_21 -> V_86 = V_72 ;
if ( V_72 -> V_80 & V_87 )
V_69 = - V_88 ;
else
V_69 = 1 ;
V_75:
V_72 -- ;
while ( V_72 >= V_27 ) {
V_70 = V_72 -> V_70 ;
V_19 -> V_26 [ V_72 -> V_28 ] . V_76 -= V_70 ;
if ( V_72 -> V_80 & V_81 )
V_74 -> V_82 [ V_72 -> V_28 ] += V_70 ;
V_72 -- ;
}
return V_69 ;
}
static int F_53 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_69 , V_70 , V_43 ;
struct V_42 * V_72 ;
struct V_24 * V_25 ;
struct V_42 * V_27 ;
struct V_73 * V_74 ;
V_27 = V_21 -> V_27 ;
V_43 = V_21 -> V_43 ;
V_74 = V_21 -> V_75 ;
if ( F_41 ( V_21 -> V_89 ) )
return F_52 ( V_19 , V_21 ) ;
for ( V_72 = V_27 ; V_72 < V_27 + V_43 ; V_72 ++ ) {
V_25 = & V_19 -> V_26 [ V_72 -> V_28 ] ;
V_70 = V_72 -> V_70 ;
V_69 = V_25 -> V_76 ;
if ( ! V_70 && V_69 )
goto V_77;
V_69 += V_70 ;
if ( V_69 < 0 )
goto V_77;
if ( V_69 > V_78 )
return - V_85 ;
if ( V_72 -> V_80 & V_81 ) {
int V_75 = V_74 -> V_82 [ V_72 -> V_28 ] - V_70 ;
if ( V_75 < ( - V_83 - 1 ) || V_75 > V_83 )
return - V_85 ;
}
}
for ( V_72 = V_27 ; V_72 < V_27 + V_43 ; V_72 ++ ) {
V_25 = & V_19 -> V_26 [ V_72 -> V_28 ] ;
V_70 = V_72 -> V_70 ;
V_69 = V_25 -> V_76 ;
if ( V_72 -> V_80 & V_81 ) {
int V_75 = V_74 -> V_82 [ V_72 -> V_28 ] - V_70 ;
V_74 -> V_82 [ V_72 -> V_28 ] = V_75 ;
}
V_25 -> V_76 += V_70 ;
V_25 -> V_84 = V_21 -> V_71 ;
}
return 0 ;
V_77:
V_21 -> V_86 = V_72 ;
return V_72 -> V_80 & V_87 ? - V_88 : 1 ;
}
static inline void F_54 ( struct V_20 * V_21 , int error ,
struct V_90 * V_91 )
{
F_55 ( V_91 , V_21 -> V_92 ) ;
F_56 ( V_21 -> V_93 , error ) ;
}
static void F_57 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_58 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_43 > 1 )
V_19 -> V_23 -- ;
}
static inline int F_59 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_60 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_43 > 1 )
return 1 ;
return 0 ;
}
static int F_61 ( struct V_18 * V_19 , int V_94 ,
struct V_90 * V_91 )
{
struct V_20 * V_21 , * V_95 ;
struct V_96 * V_97 ;
int V_98 = 0 ;
if ( V_94 == - 1 )
V_97 = & V_19 -> V_66 ;
else
V_97 = & V_19 -> V_26 [ V_94 ] . V_66 ;
F_10 (q, tmp, pending_list, list) {
int error = F_53 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_57 ( V_19 , V_21 ) ;
F_54 ( V_21 , error , V_91 ) ;
if ( error == 0 )
V_98 = 1 ;
}
return V_98 ;
}
static int F_62 ( struct V_18 * V_19 , struct V_42 * V_27 ,
int V_43 , struct V_90 * V_91 )
{
int V_31 ;
int V_98 = 0 ;
int V_99 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_43 ; V_31 ++ ) {
int V_100 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_100 ] . V_76 == 0 ) {
V_99 = 1 ;
V_98 |= F_61 ( V_19 , V_100 , V_91 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_76 == 0 ) {
V_99 = 1 ;
V_98 |= F_61 ( V_19 , V_31 , V_91 ) ;
}
}
}
if ( V_99 )
V_98 |= F_61 ( V_19 , - 1 , V_91 ) ;
return V_98 ;
}
static int F_63 ( struct V_18 * V_19 , int V_94 , struct V_90 * V_91 )
{
struct V_20 * V_21 , * V_95 ;
struct V_96 * V_97 ;
int V_98 = 0 ;
if ( V_94 == - 1 )
V_97 = & V_19 -> V_30 ;
else
V_97 = & V_19 -> V_26 [ V_94 ] . V_30 ;
V_101:
F_10 (q, tmp, pending_list, list) {
int error , V_102 ;
if ( V_94 != - 1 && V_19 -> V_26 [ V_94 ] . V_76 == 0 )
break;
error = F_53 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_57 ( V_19 , V_21 ) ;
if ( error ) {
V_102 = 0 ;
} else {
V_98 = 1 ;
F_62 ( V_19 , V_21 -> V_27 , V_21 -> V_43 , V_91 ) ;
V_102 = F_59 ( V_19 , V_21 ) ;
}
F_54 ( V_21 , error , V_91 ) ;
if ( V_102 )
goto V_101;
}
return V_98 ;
}
static void F_64 ( struct V_18 * V_19 , struct V_42 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_103 = F_45 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_103 =
F_45 () ;
}
}
static void F_65 ( struct V_18 * V_19 , struct V_42 * V_27 , int V_43 ,
int V_104 , struct V_90 * V_91 )
{
int V_31 ;
V_104 |= F_62 ( V_19 , V_27 , V_43 , V_91 ) ;
if ( ! F_60 ( & V_19 -> V_30 ) ) {
V_104 |= F_63 ( V_19 , - 1 , V_91 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_104 |= F_63 ( V_19 , V_31 , V_91 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_43 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_70 > 0 ) {
V_104 |= F_63 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_91 ) ;
}
}
}
}
if ( V_104 )
F_64 ( V_19 , V_27 ) ;
}
static int F_66 ( struct V_18 * V_19 , int V_94 , struct V_20 * V_21 ,
bool V_105 )
{
struct V_42 * V_72 = V_21 -> V_86 ;
F_67 ( L_3
L_4 ,
V_106 -> V_107 , F_68 ( V_106 ) ) ;
if ( V_72 -> V_28 != V_94 )
return 0 ;
if ( V_105 && V_72 -> V_70 == 0 )
return 1 ;
if ( ! V_105 && V_72 -> V_70 < 0 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_18 * V_19 , T_4 V_94 ,
bool V_105 )
{
struct V_96 * V_108 ;
struct V_20 * V_21 ;
int V_109 ;
V_109 = 0 ;
if ( V_105 )
V_108 = & V_19 -> V_26 [ V_94 ] . V_66 ;
else
V_108 = & V_19 -> V_26 [ V_94 ] . V_30 ;
F_70 (q, l, list) {
V_109 ++ ;
}
F_70 (q, &sma->pending_alter, list) {
V_109 += F_66 ( V_19 , V_94 , V_21 , V_105 ) ;
}
if ( V_105 ) {
F_70 (q, &sma->pending_const, list) {
V_109 += F_66 ( V_19 , V_94 , V_21 , V_105 ) ;
}
}
return V_109 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_35 * V_47 )
{
struct V_73 * V_74 , * V_110 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_47 , struct V_18 , V_38 ) ;
int V_31 ;
F_71 ( V_91 ) ;
F_72 ( & V_19 -> V_38 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_58 ( & V_74 -> V_67 ) ;
F_20 ( & V_74 -> V_111 -> V_41 ) ;
V_74 -> V_112 = - 1 ;
F_73 ( & V_74 -> V_113 ) ;
F_21 ( & V_74 -> V_111 -> V_41 ) ;
F_74 ( V_74 , V_37 ) ;
}
F_10 (q, tq, &sma->pending_const, list) {
F_57 ( V_19 , V_21 ) ;
F_54 ( V_21 , - V_114 , & V_91 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_57 ( V_19 , V_21 ) ;
F_54 ( V_21 , - V_114 , & V_91 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = & V_19 -> V_26 [ V_31 ] ;
F_10 (q, tq, &sem->pending_const, list) {
F_57 ( V_19 , V_21 ) ;
F_54 ( V_21 , - V_114 , & V_91 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_57 ( V_19 , V_21 ) ;
F_54 ( V_21 , - V_114 , & V_91 ) ;
}
}
F_37 ( V_2 , V_19 ) ;
F_28 ( V_19 , - 1 ) ;
F_48 () ;
F_75 ( & V_91 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_36 ( & V_19 -> V_38 , F_15 ) ;
}
static unsigned long F_76 ( void T_5 * V_115 , struct V_116 * V_117 , int V_118 )
{
switch ( V_118 ) {
case V_119 :
return F_77 ( V_115 , V_117 , sizeof( * V_117 ) ) ;
case V_120 :
{
struct V_121 V_122 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
F_78 ( & V_117 -> V_38 , & V_122 . V_38 ) ;
V_122 . V_103 = V_117 -> V_103 ;
V_122 . V_68 = V_117 -> V_68 ;
V_122 . V_32 = V_117 -> V_32 ;
return F_77 ( V_115 , & V_122 , sizeof( V_122 ) ) ;
}
default:
return - V_60 ;
}
}
static T_6 F_79 ( struct V_18 * V_19 )
{
int V_31 ;
T_6 V_123 ;
V_123 = V_19 -> V_26 [ 0 ] . V_103 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_6 V_124 = V_19 -> V_26 [ V_31 ] . V_103 ;
if ( V_124 > V_123 )
V_123 = V_124 ;
}
return V_123 ;
}
static int F_80 ( struct V_1 * V_2 , int V_112 ,
int V_125 , int V_118 , void T_5 * V_36 )
{
int V_126 ;
struct V_18 * V_19 ;
switch ( V_125 ) {
case V_127 :
case V_128 :
{
struct V_129 V_129 ;
int V_130 ;
V_126 = F_81 ( NULL , V_125 ) ;
if ( V_126 )
return V_126 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_131 = V_2 -> V_9 ;
V_129 . V_132 = V_2 -> V_5 ;
V_129 . V_133 = V_2 -> V_3 ;
V_129 . V_134 = V_2 -> V_7 ;
V_129 . V_135 = V_78 ;
V_129 . V_136 = V_137 ;
V_129 . V_138 = V_139 ;
V_129 . V_140 = V_141 ;
F_82 ( & F_5 ( V_2 ) . V_142 ) ;
if ( V_125 == V_128 ) {
V_129 . V_143 = F_5 ( V_2 ) . V_144 ;
V_129 . V_145 = V_2 -> V_11 ;
} else {
V_129 . V_143 = V_146 ;
V_129 . V_145 = V_83 ;
}
V_130 = F_83 ( & F_5 ( V_2 ) ) ;
F_84 ( & F_5 ( V_2 ) . V_142 ) ;
if ( F_77 ( V_36 , & V_129 , sizeof( struct V_129 ) ) )
return - V_147 ;
return ( V_130 < 0 ) ? 0 : V_130 ;
}
case V_148 :
case V_149 :
{
struct V_116 V_150 ;
int V_46 = 0 ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
F_85 () ;
if ( V_125 == V_149 ) {
V_19 = F_29 ( V_2 , V_112 ) ;
if ( F_31 ( V_19 ) ) {
V_126 = F_86 ( V_19 ) ;
goto V_151;
}
V_46 = V_19 -> V_38 . V_46 ;
} else {
V_19 = F_33 ( V_2 , V_112 ) ;
if ( F_31 ( V_19 ) ) {
V_126 = F_86 ( V_19 ) ;
goto V_151;
}
}
V_126 = - V_152 ;
if ( F_87 ( V_2 , & V_19 -> V_38 , V_153 ) )
goto V_151;
V_126 = F_81 ( V_19 , V_125 ) ;
if ( V_126 )
goto V_151;
F_88 ( & V_19 -> V_38 , & V_150 . V_38 ) ;
V_150 . V_103 = F_79 ( V_19 ) ;
V_150 . V_68 = V_19 -> V_68 ;
V_150 . V_32 = V_19 -> V_32 ;
F_48 () ;
if ( F_76 ( V_36 , & V_150 , V_118 ) )
return - V_147 ;
return V_46 ;
}
default:
return - V_60 ;
}
V_151:
F_48 () ;
return V_126 ;
}
static int F_89 ( struct V_1 * V_2 , int V_112 , int V_94 ,
unsigned long V_154 )
{
struct V_73 * V_74 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_126 , V_155 ;
F_71 ( V_91 ) ;
#if F_90 ( V_156 ) && F_90 ( V_157 )
V_155 = V_154 >> 32 ;
#else
V_155 = V_154 ;
#endif
if ( V_155 > V_78 || V_155 < 0 )
return - V_85 ;
F_85 () ;
V_19 = F_33 ( V_2 , V_112 ) ;
if ( F_31 ( V_19 ) ) {
F_48 () ;
return F_86 ( V_19 ) ;
}
if ( V_94 < 0 || V_94 >= V_19 -> V_32 ) {
F_48 () ;
return - V_60 ;
}
if ( F_87 ( V_2 , & V_19 -> V_38 , V_158 ) ) {
F_48 () ;
return - V_152 ;
}
V_126 = F_81 ( V_19 , V_159 ) ;
if ( V_126 ) {
F_48 () ;
return - V_152 ;
}
F_24 ( V_19 , NULL , - 1 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
F_28 ( V_19 , - 1 ) ;
F_48 () ;
return - V_114 ;
}
V_25 = & V_19 -> V_26 [ V_94 ] ;
F_72 ( & V_19 -> V_38 ) ;
F_70 (un, &sma->list_id, list_id)
V_74 -> V_82 [ V_94 ] = 0 ;
V_25 -> V_76 = V_155 ;
V_25 -> V_84 = F_92 ( V_106 ) ;
V_19 -> V_68 = F_45 () ;
F_65 ( V_19 , NULL , 0 , 0 , & V_91 ) ;
F_28 ( V_19 , - 1 ) ;
F_48 () ;
F_75 ( & V_91 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , int V_112 , int V_94 ,
int V_125 , void T_5 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_126 , V_49 ;
T_4 V_160 [ V_161 ] ;
T_4 * V_162 = V_160 ;
F_71 ( V_91 ) ;
F_85 () ;
V_19 = F_33 ( V_2 , V_112 ) ;
if ( F_31 ( V_19 ) ) {
F_48 () ;
return F_86 ( V_19 ) ;
}
V_49 = V_19 -> V_32 ;
V_126 = - V_152 ;
if ( F_87 ( V_2 , & V_19 -> V_38 , V_125 == V_163 ? V_158 : V_153 ) )
goto V_164;
V_126 = F_81 ( V_19 , V_125 ) ;
if ( V_126 )
goto V_164;
V_126 = - V_152 ;
switch ( V_125 ) {
case V_165 :
{
T_4 T_5 * V_166 = V_36 ;
int V_31 ;
F_24 ( V_19 , NULL , - 1 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
V_126 = - V_114 ;
goto V_151;
}
if ( V_49 > V_161 ) {
if ( ! F_94 ( & V_19 -> V_38 ) ) {
V_126 = - V_114 ;
goto V_151;
}
F_28 ( V_19 , - 1 ) ;
F_48 () ;
V_162 = F_95 ( V_49 , sizeof( T_4 ) ,
V_52 ) ;
if ( V_162 == NULL ) {
F_36 ( & V_19 -> V_38 , F_15 ) ;
return - V_62 ;
}
F_85 () ;
F_35 ( V_19 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
V_126 = - V_114 ;
goto V_151;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_162 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_76 ;
F_28 ( V_19 , - 1 ) ;
F_48 () ;
V_126 = 0 ;
if ( F_77 ( V_166 , V_162 , V_49 * sizeof( T_4 ) ) )
V_126 = - V_147 ;
goto V_167;
}
case V_163 :
{
int V_31 ;
struct V_73 * V_74 ;
if ( ! F_94 ( & V_19 -> V_38 ) ) {
V_126 = - V_114 ;
goto V_164;
}
F_48 () ;
if ( V_49 > V_161 ) {
V_162 = F_95 ( V_49 , sizeof( T_4 ) ,
V_52 ) ;
if ( V_162 == NULL ) {
F_36 ( & V_19 -> V_38 , F_15 ) ;
return - V_62 ;
}
}
if ( F_96 ( V_162 , V_36 , V_49 * sizeof( T_4 ) ) ) {
F_36 ( & V_19 -> V_38 , F_15 ) ;
V_126 = - V_147 ;
goto V_167;
}
for ( V_31 = 0 ; V_31 < V_49 ; V_31 ++ ) {
if ( V_162 [ V_31 ] > V_78 ) {
F_36 ( & V_19 -> V_38 , F_15 ) ;
V_126 = - V_85 ;
goto V_167;
}
}
F_85 () ;
F_35 ( V_19 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
V_126 = - V_114 ;
goto V_151;
}
for ( V_31 = 0 ; V_31 < V_49 ; V_31 ++ ) {
V_19 -> V_26 [ V_31 ] . V_76 = V_162 [ V_31 ] ;
V_19 -> V_26 [ V_31 ] . V_84 = F_92 ( V_106 ) ;
}
F_72 ( & V_19 -> V_38 ) ;
F_70 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_49 ; V_31 ++ )
V_74 -> V_82 [ V_31 ] = 0 ;
}
V_19 -> V_68 = F_45 () ;
F_65 ( V_19 , NULL , 0 , 0 , & V_91 ) ;
V_126 = 0 ;
goto V_151;
}
}
V_126 = - V_60 ;
if ( V_94 < 0 || V_94 >= V_49 )
goto V_164;
F_24 ( V_19 , NULL , - 1 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
V_126 = - V_114 ;
goto V_151;
}
V_25 = & V_19 -> V_26 [ V_94 ] ;
switch ( V_125 ) {
case V_168 :
V_126 = V_25 -> V_76 ;
goto V_151;
case V_169 :
V_126 = V_25 -> V_84 ;
goto V_151;
case V_170 :
V_126 = F_69 ( V_19 , V_94 , 0 ) ;
goto V_151;
case V_171 :
V_126 = F_69 ( V_19 , V_94 , 1 ) ;
goto V_151;
}
V_151:
F_28 ( V_19 , - 1 ) ;
V_164:
F_48 () ;
F_75 ( & V_91 ) ;
V_167:
if ( V_162 != V_160 )
F_18 ( V_162 ) ;
return V_126 ;
}
static inline unsigned long
F_97 ( struct V_116 * V_122 , void T_5 * V_115 , int V_118 )
{
switch ( V_118 ) {
case V_119 :
if ( F_96 ( V_122 , V_115 , sizeof( * V_122 ) ) )
return - V_147 ;
return 0 ;
case V_120 :
{
struct V_121 V_172 ;
if ( F_96 ( & V_172 , V_115 , sizeof( V_172 ) ) )
return - V_147 ;
V_122 -> V_38 . V_173 = V_172 . V_38 . V_173 ;
V_122 -> V_38 . V_174 = V_172 . V_38 . V_174 ;
V_122 -> V_38 . V_63 = V_172 . V_38 . V_63 ;
return 0 ;
}
default:
return - V_60 ;
}
}
static int F_98 ( struct V_1 * V_2 , int V_112 ,
int V_125 , int V_118 , void T_5 * V_36 )
{
struct V_18 * V_19 ;
int V_126 ;
struct V_116 V_175 ;
struct V_35 * V_47 ;
if ( V_125 == V_176 ) {
if ( F_97 ( & V_175 , V_36 , V_118 ) )
return - V_147 ;
}
F_99 ( & F_5 ( V_2 ) . V_142 ) ;
F_85 () ;
V_47 = F_100 ( V_2 , & F_5 ( V_2 ) , V_112 , V_125 ,
& V_175 . V_38 , 0 ) ;
if ( F_31 ( V_47 ) ) {
V_126 = F_86 ( V_47 ) ;
goto V_177;
}
V_19 = F_16 ( V_47 , struct V_18 , V_38 ) ;
V_126 = F_81 ( V_19 , V_125 ) ;
if ( V_126 )
goto V_177;
switch ( V_125 ) {
case V_178 :
F_24 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_47 ) ;
goto V_179;
case V_176 :
F_24 ( V_19 , NULL , - 1 ) ;
V_126 = F_101 ( & V_175 . V_38 , V_47 ) ;
if ( V_126 )
goto V_180;
V_19 -> V_68 = F_45 () ;
break;
default:
V_126 = - V_60 ;
goto V_177;
}
V_180:
F_28 ( V_19 , - 1 ) ;
V_177:
F_48 () ;
V_179:
F_102 ( & F_5 ( V_2 ) . V_142 ) ;
return V_126 ;
}
static inline int F_103 ( struct V_181 * * V_182 )
{
struct V_181 * V_183 ;
V_183 = V_106 -> V_184 . V_183 ;
if ( ! V_183 ) {
V_183 = F_104 ( sizeof( * V_183 ) , V_52 ) ;
if ( V_183 == NULL )
return - V_62 ;
F_44 ( & V_183 -> V_41 ) ;
F_105 ( & V_183 -> V_185 , 1 ) ;
F_12 ( & V_183 -> V_113 ) ;
V_106 -> V_184 . V_183 = V_183 ;
}
* V_182 = V_183 ;
return 0 ;
}
static struct V_73 * F_106 ( struct V_181 * V_111 , int V_112 )
{
struct V_73 * V_74 ;
F_107 (un, &ulp->list_proc, list_proc) {
if ( V_74 -> V_112 == V_112 )
return V_74 ;
}
return NULL ;
}
static struct V_73 * F_108 ( struct V_181 * V_111 , int V_112 )
{
struct V_73 * V_74 ;
F_109 ( & V_111 -> V_41 ) ;
V_74 = F_106 ( V_111 , V_112 ) ;
if ( V_74 ) {
F_73 ( & V_74 -> V_113 ) ;
F_110 ( & V_74 -> V_113 , & V_111 -> V_113 ) ;
}
return V_74 ;
}
static struct V_73 * F_111 ( struct V_1 * V_2 , int V_112 )
{
struct V_18 * V_19 ;
struct V_181 * V_111 ;
struct V_73 * V_74 , * V_186 ;
int V_49 , error ;
error = F_103 ( & V_111 ) ;
if ( error )
return F_112 ( error ) ;
F_85 () ;
F_20 ( & V_111 -> V_41 ) ;
V_74 = F_108 ( V_111 , V_112 ) ;
F_21 ( & V_111 -> V_41 ) ;
if ( F_113 ( V_74 != NULL ) )
goto V_122;
V_19 = F_33 ( V_2 , V_112 ) ;
if ( F_31 ( V_19 ) ) {
F_48 () ;
return F_32 ( V_19 ) ;
}
V_49 = V_19 -> V_32 ;
if ( ! F_94 ( & V_19 -> V_38 ) ) {
F_48 () ;
V_74 = F_112 ( - V_114 ) ;
goto V_122;
}
F_48 () ;
V_186 = F_104 ( sizeof( struct V_73 ) + sizeof( short ) * V_49 , V_52 ) ;
if ( ! V_186 ) {
F_36 ( & V_19 -> V_38 , F_15 ) ;
return F_112 ( - V_62 ) ;
}
F_85 () ;
F_35 ( V_19 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
F_28 ( V_19 , - 1 ) ;
F_48 () ;
F_114 ( V_186 ) ;
V_74 = F_112 ( - V_114 ) ;
goto V_122;
}
F_20 ( & V_111 -> V_41 ) ;
V_74 = F_108 ( V_111 , V_112 ) ;
if ( V_74 ) {
F_114 ( V_186 ) ;
goto V_187;
}
V_186 -> V_82 = ( short * ) & V_186 [ 1 ] ;
V_186 -> V_111 = V_111 ;
V_186 -> V_112 = V_112 ;
F_109 ( & V_111 -> V_41 ) ;
F_110 ( & V_186 -> V_113 , & V_111 -> V_113 ) ;
F_72 ( & V_19 -> V_38 ) ;
F_115 ( & V_186 -> V_67 , & V_19 -> V_67 ) ;
V_74 = V_186 ;
V_187:
F_21 ( & V_111 -> V_41 ) ;
F_28 ( V_19 , - 1 ) ;
V_122:
return V_74 ;
}
int F_116 ( unsigned long V_188 , struct V_189 * V_190 )
{
struct V_181 * V_183 ;
int error ;
if ( V_188 & V_191 ) {
error = F_103 ( & V_183 ) ;
if ( error )
return error ;
F_117 ( & V_183 -> V_185 ) ;
V_190 -> V_184 . V_183 = V_183 ;
} else
V_190 -> V_184 . V_183 = NULL ;
return 0 ;
}
void F_118 ( struct V_189 * V_190 )
{
struct V_181 * V_111 ;
V_111 = V_190 -> V_184 . V_183 ;
if ( ! V_111 )
return;
V_190 -> V_184 . V_183 = NULL ;
if ( ! F_119 ( & V_111 -> V_185 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_73 * V_74 ;
int V_112 , V_31 ;
F_71 ( V_91 ) ;
F_120 () ;
F_85 () ;
V_74 = F_121 ( V_111 -> V_113 . V_192 ,
struct V_73 , V_113 ) ;
if ( & V_74 -> V_113 == & V_111 -> V_113 ) {
F_122 ( & V_111 -> V_41 ) ;
F_48 () ;
break;
}
F_20 ( & V_111 -> V_41 ) ;
V_112 = V_74 -> V_112 ;
F_21 ( & V_111 -> V_41 ) ;
if ( V_112 == - 1 ) {
F_48 () ;
continue;
}
V_19 = F_33 ( V_190 -> V_193 -> V_194 , V_112 ) ;
if ( F_31 ( V_19 ) ) {
F_48 () ;
continue;
}
F_24 ( V_19 , NULL , - 1 ) ;
if ( ! F_91 ( & V_19 -> V_38 ) ) {
F_28 ( V_19 , - 1 ) ;
F_48 () ;
continue;
}
V_74 = F_106 ( V_111 , V_112 ) ;
if ( V_74 == NULL ) {
F_28 ( V_19 , - 1 ) ;
F_48 () ;
continue;
}
F_72 ( & V_19 -> V_38 ) ;
F_58 ( & V_74 -> V_67 ) ;
F_73 ( & V_74 -> V_113 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_195 = & V_19 -> V_26 [ V_31 ] ;
if ( V_74 -> V_82 [ V_31 ] ) {
V_195 -> V_76 += V_74 -> V_82 [ V_31 ] ;
if ( V_195 -> V_76 < 0 )
V_195 -> V_76 = 0 ;
if ( V_195 -> V_76 > V_78 )
V_195 -> V_76 = V_78 ;
V_195 -> V_84 = F_92 ( V_106 ) ;
}
}
F_65 ( V_19 , NULL , 0 , 1 , & V_91 ) ;
F_28 ( V_19 , - 1 ) ;
F_48 () ;
F_75 ( & V_91 ) ;
F_74 ( V_74 , V_37 ) ;
}
F_114 ( V_111 ) ;
}
static int V_17 ( struct V_196 * V_48 , void * V_197 )
{
struct V_198 * V_199 = F_123 ( V_48 ) ;
struct V_35 * V_47 = V_197 ;
struct V_18 * V_19 = F_16 ( V_47 , struct V_18 , V_38 ) ;
T_6 V_103 ;
F_19 ( V_19 ) ;
V_103 = F_79 ( V_19 ) ;
F_124 ( V_48 ,
L_5 ,
V_19 -> V_38 . V_56 ,
V_19 -> V_38 . V_46 ,
V_19 -> V_38 . V_63 ,
V_19 -> V_32 ,
F_125 ( V_199 , V_19 -> V_38 . V_173 ) ,
F_126 ( V_199 , V_19 -> V_38 . V_174 ) ,
F_125 ( V_199 , V_19 -> V_38 . V_200 ) ,
F_126 ( V_199 , V_19 -> V_38 . V_201 ) ,
V_103 ,
V_19 -> V_68 ) ;
F_22 ( V_19 ) ;
return 0 ;
}
