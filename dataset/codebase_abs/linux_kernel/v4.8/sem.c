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
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_14 ( & V_24 -> V_30 , & V_19 -> V_30 ) ;
}
}
static void F_15 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_16 ( V_34 , struct V_35 , V_37 ) ;
struct V_18 * V_19 = F_17 ( V_36 ) ;
F_18 ( V_19 ) ;
F_19 ( V_34 ) ;
}
static void F_20 ( struct V_18 * V_19 )
{
int V_31 ;
struct V_24 * V_24 ;
if ( V_19 -> V_23 ) {
return;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
V_24 = V_19 -> V_26 + V_31 ;
F_21 ( & V_24 -> V_38 ) ;
}
}
static inline int F_22 ( struct V_18 * V_19 , struct V_39 * V_27 ,
int V_40 )
{
struct V_24 * V_24 ;
if ( V_40 != 1 ) {
F_23 ( & V_19 -> V_41 ) ;
F_20 ( V_19 ) ;
return - 1 ;
}
V_24 = V_19 -> V_26 + V_27 -> V_28 ;
if ( V_19 -> V_23 == 0 ) {
F_24 ( & V_24 -> V_38 ) ;
if ( ! F_25 ( & V_19 -> V_41 . V_38 ) ) {
F_26 () ;
if ( V_19 -> V_23 == 0 ) {
return V_27 -> V_28 ;
}
}
F_27 ( & V_24 -> V_38 ) ;
}
F_23 ( & V_19 -> V_41 ) ;
if ( V_19 -> V_23 == 0 ) {
F_24 ( & V_24 -> V_38 ) ;
F_28 ( & V_19 -> V_41 ) ;
return V_27 -> V_28 ;
} else {
F_20 ( V_19 ) ;
return - 1 ;
}
}
static inline void F_29 ( struct V_18 * V_19 , int V_42 )
{
if ( V_42 == - 1 ) {
F_9 ( V_19 ) ;
F_28 ( & V_19 -> V_41 ) ;
} else {
struct V_24 * V_24 = V_19 -> V_26 + V_42 ;
F_27 ( & V_24 -> V_38 ) ;
}
}
static inline struct V_18 * F_30 ( struct V_1 * V_2 ,
int V_43 , struct V_39 * V_27 , int V_40 , int * V_42 )
{
struct V_44 * V_45 ;
struct V_18 * V_19 ;
V_45 = F_31 ( & F_5 ( V_2 ) , V_43 ) ;
if ( F_32 ( V_45 ) )
return F_33 ( V_45 ) ;
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
* V_42 = F_22 ( V_19 , V_27 , V_40 ) ;
if ( F_34 ( V_45 ) )
return F_16 ( V_45 , struct V_18 , V_41 ) ;
F_29 ( V_19 , * V_42 ) ;
return F_35 ( - V_46 ) ;
}
static inline struct V_18 * F_36 ( struct V_1 * V_2 , int V_43 )
{
struct V_44 * V_45 = F_31 ( & F_5 ( V_2 ) , V_43 ) ;
if ( F_32 ( V_45 ) )
return F_33 ( V_45 ) ;
return F_16 ( V_45 , struct V_18 , V_41 ) ;
}
static inline struct V_18 * F_37 ( struct V_1 * V_2 ,
int V_43 )
{
struct V_44 * V_45 = F_38 ( & F_5 ( V_2 ) , V_43 ) ;
if ( F_32 ( V_45 ) )
return F_33 ( V_45 ) ;
return F_16 ( V_45 , struct V_18 , V_41 ) ;
}
static inline void F_39 ( struct V_18 * V_19 )
{
F_22 ( V_19 , NULL , - 1 ) ;
F_40 ( V_19 , F_15 ) ;
}
static inline void F_41 ( struct V_1 * V_2 , struct V_18 * V_47 )
{
F_42 ( & F_5 ( V_2 ) , & V_47 -> V_41 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
int V_43 ;
int V_50 ;
struct V_18 * V_19 ;
int V_51 ;
T_2 V_52 = V_49 -> V_52 ;
int V_53 = V_49 -> V_54 . V_53 ;
int V_55 = V_49 -> V_56 ;
int V_31 ;
if ( ! V_53 )
return - V_46 ;
if ( V_2 -> V_11 + V_53 > V_2 -> V_5 )
return - V_57 ;
V_51 = sizeof( * V_19 ) + V_53 * sizeof( struct V_24 ) ;
V_19 = F_44 ( V_51 ) ;
if ( ! V_19 )
return - V_58 ;
memset ( V_19 , 0 , V_51 ) ;
V_19 -> V_41 . V_59 = ( V_55 & V_60 ) ;
V_19 -> V_41 . V_52 = V_52 ;
V_19 -> V_41 . V_61 = NULL ;
V_50 = F_45 ( V_19 ) ;
if ( V_50 ) {
F_40 ( V_19 , F_19 ) ;
return V_50 ;
}
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_62 ) ;
F_46 ( & V_19 -> V_26 [ V_31 ] . V_38 ) ;
}
V_19 -> V_23 = 0 ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_62 ) ;
F_12 ( & V_19 -> V_63 ) ;
V_19 -> V_32 = V_53 ;
V_19 -> V_64 = F_47 () ;
V_43 = F_48 ( & F_5 ( V_2 ) , & V_19 -> V_41 , V_2 -> V_9 ) ;
if ( V_43 < 0 ) {
F_40 ( V_19 , F_15 ) ;
return V_43 ;
}
V_2 -> V_11 += V_53 ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
return V_19 -> V_41 . V_43 ;
}
static inline int F_50 ( struct V_44 * V_45 , int V_55 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
return F_51 ( V_19 , V_55 ) ;
}
static inline int F_52 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
if ( V_49 -> V_54 . V_53 > V_19 -> V_32 )
return - V_46 ;
return 0 ;
}
static int F_53 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_65 , V_66 , V_40 , V_67 ;
struct V_39 * V_68 ;
struct V_24 * V_25 ;
struct V_39 * V_27 ;
struct V_69 * V_70 ;
V_27 = V_21 -> V_27 ;
V_40 = V_21 -> V_40 ;
V_70 = V_21 -> V_71 ;
for ( V_68 = V_27 ; V_68 < V_27 + V_40 ; V_68 ++ ) {
V_25 = V_19 -> V_26 + V_68 -> V_28 ;
V_66 = V_68 -> V_66 ;
V_65 = V_25 -> V_72 ;
if ( ! V_66 && V_65 )
goto V_73;
V_65 += V_66 ;
if ( V_65 < 0 )
goto V_73;
if ( V_65 > V_74 )
goto V_75;
if ( V_68 -> V_76 & V_77 ) {
int V_71 = V_70 -> V_78 [ V_68 -> V_28 ] - V_66 ;
if ( V_71 < ( - V_79 - 1 ) || V_71 > V_79 )
goto V_75;
V_70 -> V_78 [ V_68 -> V_28 ] = V_71 ;
}
V_25 -> V_72 = V_65 ;
}
V_68 -- ;
V_67 = V_21 -> V_67 ;
while ( V_68 >= V_27 ) {
V_19 -> V_26 [ V_68 -> V_28 ] . V_80 = V_67 ;
V_68 -- ;
}
return 0 ;
V_75:
V_65 = - V_81 ;
goto V_71;
V_73:
V_21 -> V_82 = V_68 ;
if ( V_68 -> V_76 & V_83 )
V_65 = - V_84 ;
else
V_65 = 1 ;
V_71:
V_68 -- ;
while ( V_68 >= V_27 ) {
V_66 = V_68 -> V_66 ;
V_19 -> V_26 [ V_68 -> V_28 ] . V_72 -= V_66 ;
if ( V_68 -> V_76 & V_77 )
V_70 -> V_78 [ V_68 -> V_28 ] += V_66 ;
V_68 -- ;
}
return V_65 ;
}
static void F_54 ( struct V_85 * V_86 ,
struct V_20 * V_21 , int error )
{
if ( F_55 ( V_86 ) ) {
F_56 () ;
}
V_21 -> V_87 = V_88 ;
V_21 -> V_67 = error ;
F_11 ( & V_21 -> V_29 , V_86 ) ;
}
static void F_57 ( struct V_85 * V_86 )
{
struct V_20 * V_21 , * V_89 ;
int V_90 ;
V_90 = ! F_55 ( V_86 ) ;
F_10 (q, t, pt, list) {
F_58 ( V_21 -> V_91 ) ;
F_59 () ;
V_21 -> V_87 = V_21 -> V_67 ;
}
if ( V_90 )
F_60 () ;
}
static void F_61 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_62 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_40 > 1 )
V_19 -> V_23 -- ;
}
static int F_63 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_55 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_40 > 1 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_18 * V_19 , int V_92 ,
struct V_85 * V_86 )
{
struct V_20 * V_21 ;
struct V_85 * V_93 ;
struct V_85 * V_94 ;
int V_95 = 0 ;
if ( V_92 == - 1 )
V_94 = & V_19 -> V_62 ;
else
V_94 = & V_19 -> V_26 [ V_92 ] . V_62 ;
V_93 = V_94 -> V_96 ;
while ( V_93 != V_94 ) {
int error ;
V_21 = F_16 ( V_93 , struct V_20 , V_29 ) ;
V_93 = V_93 -> V_96 ;
error = F_53 ( V_19 , V_21 ) ;
if ( error <= 0 ) {
F_61 ( V_19 , V_21 ) ;
F_54 ( V_86 , V_21 , error ) ;
if ( error == 0 )
V_95 = 1 ;
}
}
return V_95 ;
}
static int F_65 ( struct V_18 * V_19 , struct V_39 * V_27 ,
int V_40 , struct V_85 * V_86 )
{
int V_31 ;
int V_95 = 0 ;
int V_97 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ ) {
int V_98 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_98 ] . V_72 == 0 ) {
V_97 = 1 ;
V_95 |= F_64 ( V_19 , V_98 , V_86 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_72 == 0 ) {
V_97 = 1 ;
V_95 |= F_64 ( V_19 , V_31 , V_86 ) ;
}
}
}
if ( V_97 )
V_95 |= F_64 ( V_19 , - 1 , V_86 ) ;
return V_95 ;
}
static int F_66 ( struct V_18 * V_19 , int V_92 , struct V_85 * V_86 )
{
struct V_20 * V_21 ;
struct V_85 * V_93 ;
struct V_85 * V_94 ;
int V_95 = 0 ;
if ( V_92 == - 1 )
V_94 = & V_19 -> V_30 ;
else
V_94 = & V_19 -> V_26 [ V_92 ] . V_30 ;
V_99:
V_93 = V_94 -> V_96 ;
while ( V_93 != V_94 ) {
int error , V_100 ;
V_21 = F_16 ( V_93 , struct V_20 , V_29 ) ;
V_93 = V_93 -> V_96 ;
if ( V_92 != - 1 && V_19 -> V_26 [ V_92 ] . V_72 == 0 )
break;
error = F_53 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_61 ( V_19 , V_21 ) ;
if ( error ) {
V_100 = 0 ;
} else {
V_95 = 1 ;
F_65 ( V_19 , V_21 -> V_27 , V_21 -> V_40 , V_86 ) ;
V_100 = F_63 ( V_19 , V_21 ) ;
}
F_54 ( V_86 , V_21 , error ) ;
if ( V_100 )
goto V_99;
}
return V_95 ;
}
static void F_67 ( struct V_18 * V_19 , struct V_39 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_101 = F_47 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_101 =
F_47 () ;
}
}
static void F_68 ( struct V_18 * V_19 , struct V_39 * V_27 , int V_40 ,
int V_102 , struct V_85 * V_86 )
{
int V_31 ;
V_102 |= F_65 ( V_19 , V_27 , V_40 , V_86 ) ;
if ( ! F_55 ( & V_19 -> V_30 ) ) {
V_102 |= F_66 ( V_19 , - 1 , V_86 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_102 |= F_66 ( V_19 , V_31 , V_86 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_66 > 0 ) {
V_102 |= F_66 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_86 ) ;
}
}
}
}
if ( V_102 )
F_67 ( V_19 , V_27 ) ;
}
static int F_69 ( struct V_18 * V_19 , int V_92 , struct V_20 * V_21 ,
bool V_103 )
{
struct V_39 * V_68 = V_21 -> V_82 ;
F_70 ( L_3
L_4 ,
V_104 -> V_105 , F_71 ( V_104 ) ) ;
if ( V_68 -> V_28 != V_92 )
return 0 ;
if ( V_103 && V_68 -> V_66 == 0 )
return 1 ;
if ( ! V_103 && V_68 -> V_66 < 0 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_18 * V_19 , T_3 V_92 ,
bool V_103 )
{
struct V_85 * V_106 ;
struct V_20 * V_21 ;
int V_107 ;
V_107 = 0 ;
if ( V_103 )
V_106 = & V_19 -> V_26 [ V_92 ] . V_62 ;
else
V_106 = & V_19 -> V_26 [ V_92 ] . V_30 ;
F_73 (q, l, list) {
V_107 ++ ;
}
F_73 (q, &sma->pending_alter, list) {
V_107 += F_69 ( V_19 , V_92 , V_21 , V_103 ) ;
}
if ( V_103 ) {
F_73 (q, &sma->pending_const, list) {
V_107 += F_69 ( V_19 , V_92 , V_21 , V_103 ) ;
}
}
return V_107 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_69 * V_70 , * V_108 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
struct V_85 V_109 ;
int V_31 ;
F_74 ( & V_19 -> V_41 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_62 ( & V_70 -> V_63 ) ;
F_24 ( & V_70 -> V_110 -> V_38 ) ;
V_70 -> V_111 = - 1 ;
F_75 ( & V_70 -> V_112 ) ;
F_27 ( & V_70 -> V_110 -> V_38 ) ;
F_76 ( V_70 , V_37 ) ;
}
F_12 ( & V_109 ) ;
F_10 (q, tq, &sma->pending_const, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_109 , V_21 , - V_113 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_109 , V_21 , - V_113 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_109 , V_21 , - V_113 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_109 , V_21 , - V_113 ) ;
}
}
F_41 ( V_2 , V_19 ) ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_57 ( & V_109 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_40 ( V_19 , F_15 ) ;
}
static unsigned long F_77 ( void T_4 * V_114 , struct V_115 * V_116 , int V_117 )
{
switch ( V_117 ) {
case V_118 :
return F_78 ( V_114 , V_116 , sizeof( * V_116 ) ) ;
case V_119 :
{
struct V_120 V_121 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_79 ( & V_116 -> V_41 , & V_121 . V_41 ) ;
V_121 . V_101 = V_116 -> V_101 ;
V_121 . V_64 = V_116 -> V_64 ;
V_121 . V_32 = V_116 -> V_32 ;
return F_78 ( V_114 , & V_121 , sizeof( V_121 ) ) ;
}
default:
return - V_46 ;
}
}
static T_5 F_80 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_122 ;
V_122 = V_19 -> V_26 [ 0 ] . V_101 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_123 = V_19 -> V_26 [ V_31 ] . V_101 ;
if ( V_123 > V_122 )
V_122 = V_123 ;
}
return V_122 ;
}
static int F_81 ( struct V_1 * V_2 , int V_111 ,
int V_124 , int V_117 , void T_4 * V_36 )
{
int V_125 ;
struct V_18 * V_19 ;
switch ( V_124 ) {
case V_126 :
case V_127 :
{
struct V_128 V_128 ;
int V_129 ;
V_125 = F_82 ( NULL , V_124 ) ;
if ( V_125 )
return V_125 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_130 = V_2 -> V_9 ;
V_128 . V_131 = V_2 -> V_5 ;
V_128 . V_132 = V_2 -> V_3 ;
V_128 . V_133 = V_2 -> V_7 ;
V_128 . V_134 = V_74 ;
V_128 . V_135 = V_136 ;
V_128 . V_137 = V_138 ;
V_128 . V_139 = V_140 ;
F_83 ( & F_5 ( V_2 ) . V_141 ) ;
if ( V_124 == V_127 ) {
V_128 . V_142 = F_5 ( V_2 ) . V_143 ;
V_128 . V_144 = V_2 -> V_11 ;
} else {
V_128 . V_142 = V_145 ;
V_128 . V_144 = V_79 ;
}
V_129 = F_84 ( & F_5 ( V_2 ) ) ;
F_85 ( & F_5 ( V_2 ) . V_141 ) ;
if ( F_78 ( V_36 , & V_128 , sizeof( struct V_128 ) ) )
return - V_146 ;
return ( V_129 < 0 ) ? 0 : V_129 ;
}
case V_147 :
case V_148 :
{
struct V_115 V_149 ;
int V_43 = 0 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
F_86 () ;
if ( V_124 == V_148 ) {
V_19 = F_36 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
V_125 = F_87 ( V_19 ) ;
goto V_150;
}
V_43 = V_19 -> V_41 . V_43 ;
} else {
V_19 = F_37 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
V_125 = F_87 ( V_19 ) ;
goto V_150;
}
}
V_125 = - V_151 ;
if ( F_88 ( V_2 , & V_19 -> V_41 , V_152 ) )
goto V_150;
V_125 = F_82 ( V_19 , V_124 ) ;
if ( V_125 )
goto V_150;
F_89 ( & V_19 -> V_41 , & V_149 . V_41 ) ;
V_149 . V_101 = F_80 ( V_19 ) ;
V_149 . V_64 = V_19 -> V_64 ;
V_149 . V_32 = V_19 -> V_32 ;
F_49 () ;
if ( F_77 ( V_36 , & V_149 , V_117 ) )
return - V_146 ;
return V_43 ;
}
default:
return - V_46 ;
}
V_150:
F_49 () ;
return V_125 ;
}
static int F_90 ( struct V_1 * V_2 , int V_111 , int V_92 ,
unsigned long V_153 )
{
struct V_69 * V_70 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_125 ;
struct V_85 V_109 ;
int V_154 ;
#if F_91 ( V_155 ) && F_91 ( V_156 )
V_154 = V_153 >> 32 ;
#else
V_154 = V_153 ;
#endif
if ( V_154 > V_74 || V_154 < 0 )
return - V_81 ;
F_12 ( & V_109 ) ;
F_86 () ;
V_19 = F_37 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
return F_87 ( V_19 ) ;
}
if ( V_92 < 0 || V_92 >= V_19 -> V_32 ) {
F_49 () ;
return - V_46 ;
}
if ( F_88 ( V_2 , & V_19 -> V_41 , V_157 ) ) {
F_49 () ;
return - V_151 ;
}
V_125 = F_82 ( V_19 , V_158 ) ;
if ( V_125 ) {
F_49 () ;
return - V_151 ;
}
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
return - V_113 ;
}
V_25 = & V_19 -> V_26 [ V_92 ] ;
F_74 ( & V_19 -> V_41 ) ;
F_73 (un, &sma->list_id, list_id)
V_70 -> V_78 [ V_92 ] = 0 ;
V_25 -> V_72 = V_154 ;
V_25 -> V_80 = F_92 ( V_104 ) ;
V_19 -> V_64 = F_47 () ;
F_68 ( V_19 , NULL , 0 , 0 , & V_109 ) ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_57 ( & V_109 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , int V_111 , int V_92 ,
int V_124 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_125 , V_53 ;
T_3 V_159 [ V_160 ] ;
T_3 * V_161 = V_159 ;
struct V_85 V_109 ;
F_12 ( & V_109 ) ;
F_86 () ;
V_19 = F_37 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
return F_87 ( V_19 ) ;
}
V_53 = V_19 -> V_32 ;
V_125 = - V_151 ;
if ( F_88 ( V_2 , & V_19 -> V_41 , V_124 == V_162 ? V_157 : V_152 ) )
goto V_163;
V_125 = F_82 ( V_19 , V_124 ) ;
if ( V_125 )
goto V_163;
V_125 = - V_151 ;
switch ( V_124 ) {
case V_164 :
{
T_3 T_4 * V_165 = V_36 ;
int V_31 ;
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_125 = - V_113 ;
goto V_150;
}
if ( V_53 > V_160 ) {
if ( ! F_94 ( V_19 ) ) {
V_125 = - V_113 ;
goto V_150;
}
F_29 ( V_19 , - 1 ) ;
F_49 () ;
V_161 = F_95 ( sizeof( T_3 ) * V_53 ) ;
if ( V_161 == NULL ) {
F_40 ( V_19 , F_15 ) ;
return - V_58 ;
}
F_86 () ;
F_39 ( V_19 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_125 = - V_113 ;
goto V_150;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_161 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_72 ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
V_125 = 0 ;
if ( F_78 ( V_165 , V_161 , V_53 * sizeof( T_3 ) ) )
V_125 = - V_146 ;
goto V_166;
}
case V_162 :
{
int V_31 ;
struct V_69 * V_70 ;
if ( ! F_94 ( V_19 ) ) {
V_125 = - V_113 ;
goto V_163;
}
F_49 () ;
if ( V_53 > V_160 ) {
V_161 = F_95 ( sizeof( T_3 ) * V_53 ) ;
if ( V_161 == NULL ) {
F_40 ( V_19 , F_15 ) ;
return - V_58 ;
}
}
if ( F_96 ( V_161 , V_36 , V_53 * sizeof( T_3 ) ) ) {
F_40 ( V_19 , F_15 ) ;
V_125 = - V_146 ;
goto V_166;
}
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ ) {
if ( V_161 [ V_31 ] > V_74 ) {
F_40 ( V_19 , F_15 ) ;
V_125 = - V_81 ;
goto V_166;
}
}
F_86 () ;
F_39 ( V_19 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_125 = - V_113 ;
goto V_150;
}
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ ) {
V_19 -> V_26 [ V_31 ] . V_72 = V_161 [ V_31 ] ;
V_19 -> V_26 [ V_31 ] . V_80 = F_92 ( V_104 ) ;
}
F_74 ( & V_19 -> V_41 ) ;
F_73 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ )
V_70 -> V_78 [ V_31 ] = 0 ;
}
V_19 -> V_64 = F_47 () ;
F_68 ( V_19 , NULL , 0 , 0 , & V_109 ) ;
V_125 = 0 ;
goto V_150;
}
}
V_125 = - V_46 ;
if ( V_92 < 0 || V_92 >= V_53 )
goto V_163;
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_125 = - V_113 ;
goto V_150;
}
V_25 = & V_19 -> V_26 [ V_92 ] ;
switch ( V_124 ) {
case V_167 :
V_125 = V_25 -> V_72 ;
goto V_150;
case V_168 :
V_125 = V_25 -> V_80 ;
goto V_150;
case V_169 :
V_125 = F_72 ( V_19 , V_92 , 0 ) ;
goto V_150;
case V_170 :
V_125 = F_72 ( V_19 , V_92 , 1 ) ;
goto V_150;
}
V_150:
F_29 ( V_19 , - 1 ) ;
V_163:
F_49 () ;
F_57 ( & V_109 ) ;
V_166:
if ( V_161 != V_159 )
F_97 ( V_161 ) ;
return V_125 ;
}
static inline unsigned long
F_98 ( struct V_115 * V_121 , void T_4 * V_114 , int V_117 )
{
switch ( V_117 ) {
case V_118 :
if ( F_96 ( V_121 , V_114 , sizeof( * V_121 ) ) )
return - V_146 ;
return 0 ;
case V_119 :
{
struct V_120 V_171 ;
if ( F_96 ( & V_171 , V_114 , sizeof( V_171 ) ) )
return - V_146 ;
V_121 -> V_41 . V_172 = V_171 . V_41 . V_172 ;
V_121 -> V_41 . V_173 = V_171 . V_41 . V_173 ;
V_121 -> V_41 . V_59 = V_171 . V_41 . V_59 ;
return 0 ;
}
default:
return - V_46 ;
}
}
static int F_99 ( struct V_1 * V_2 , int V_111 ,
int V_124 , int V_117 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
int V_125 ;
struct V_115 V_174 ;
struct V_44 * V_45 ;
if ( V_124 == V_175 ) {
if ( F_98 ( & V_174 , V_36 , V_117 ) )
return - V_146 ;
}
F_100 ( & F_5 ( V_2 ) . V_141 ) ;
F_86 () ;
V_45 = F_101 ( V_2 , & F_5 ( V_2 ) , V_111 , V_124 ,
& V_174 . V_41 , 0 ) ;
if ( F_32 ( V_45 ) ) {
V_125 = F_87 ( V_45 ) ;
goto V_176;
}
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
V_125 = F_82 ( V_19 , V_124 ) ;
if ( V_125 )
goto V_176;
switch ( V_124 ) {
case V_177 :
F_22 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_45 ) ;
goto V_178;
case V_175 :
F_22 ( V_19 , NULL , - 1 ) ;
V_125 = F_102 ( & V_174 . V_41 , V_45 ) ;
if ( V_125 )
goto V_179;
V_19 -> V_64 = F_47 () ;
break;
default:
V_125 = - V_46 ;
goto V_176;
}
V_179:
F_29 ( V_19 , - 1 ) ;
V_176:
F_49 () ;
V_178:
F_103 ( & F_5 ( V_2 ) . V_141 ) ;
return V_125 ;
}
static inline int F_104 ( struct V_180 * * V_181 )
{
struct V_180 * V_182 ;
V_182 = V_104 -> V_183 . V_182 ;
if ( ! V_182 ) {
V_182 = F_105 ( sizeof( * V_182 ) , V_184 ) ;
if ( V_182 == NULL )
return - V_58 ;
F_46 ( & V_182 -> V_38 ) ;
F_106 ( & V_182 -> V_185 , 1 ) ;
F_12 ( & V_182 -> V_112 ) ;
V_104 -> V_183 . V_182 = V_182 ;
}
* V_181 = V_182 ;
return 0 ;
}
static struct V_69 * F_107 ( struct V_180 * V_110 , int V_111 )
{
struct V_69 * V_70 ;
F_108 (un, &ulp->list_proc, list_proc) {
if ( V_70 -> V_111 == V_111 )
return V_70 ;
}
return NULL ;
}
static struct V_69 * F_109 ( struct V_180 * V_110 , int V_111 )
{
struct V_69 * V_70 ;
F_110 ( & V_110 -> V_38 ) ;
V_70 = F_107 ( V_110 , V_111 ) ;
if ( V_70 ) {
F_75 ( & V_70 -> V_112 ) ;
F_111 ( & V_70 -> V_112 , & V_110 -> V_112 ) ;
}
return V_70 ;
}
static struct V_69 * F_112 ( struct V_1 * V_2 , int V_111 )
{
struct V_18 * V_19 ;
struct V_180 * V_110 ;
struct V_69 * V_70 , * V_186 ;
int V_53 , error ;
error = F_104 ( & V_110 ) ;
if ( error )
return F_35 ( error ) ;
F_86 () ;
F_24 ( & V_110 -> V_38 ) ;
V_70 = F_109 ( V_110 , V_111 ) ;
F_27 ( & V_110 -> V_38 ) ;
if ( F_113 ( V_70 != NULL ) )
goto V_121;
V_19 = F_37 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
return F_33 ( V_19 ) ;
}
V_53 = V_19 -> V_32 ;
if ( ! F_94 ( V_19 ) ) {
F_49 () ;
V_70 = F_35 ( - V_113 ) ;
goto V_121;
}
F_49 () ;
V_186 = F_105 ( sizeof( struct V_69 ) + sizeof( short ) * V_53 , V_184 ) ;
if ( ! V_186 ) {
F_40 ( V_19 , F_15 ) ;
return F_35 ( - V_58 ) ;
}
F_86 () ;
F_39 ( V_19 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_114 ( V_186 ) ;
V_70 = F_35 ( - V_113 ) ;
goto V_121;
}
F_24 ( & V_110 -> V_38 ) ;
V_70 = F_109 ( V_110 , V_111 ) ;
if ( V_70 ) {
F_114 ( V_186 ) ;
goto V_187;
}
V_186 -> V_78 = ( short * ) & V_186 [ 1 ] ;
V_186 -> V_110 = V_110 ;
V_186 -> V_111 = V_111 ;
F_110 ( & V_110 -> V_38 ) ;
F_111 ( & V_186 -> V_112 , & V_110 -> V_112 ) ;
F_74 ( & V_19 -> V_41 ) ;
F_115 ( & V_186 -> V_63 , & V_19 -> V_63 ) ;
V_70 = V_186 ;
V_187:
F_27 ( & V_110 -> V_38 ) ;
F_29 ( V_19 , - 1 ) ;
V_121:
return V_70 ;
}
static int F_116 ( struct V_20 * V_21 )
{
int error ;
error = V_21 -> V_87 ;
while ( F_117 ( error == V_88 ) ) {
F_118 () ;
error = V_21 -> V_87 ;
}
return error ;
}
int F_119 ( unsigned long V_188 , struct V_189 * V_190 )
{
struct V_180 * V_182 ;
int error ;
if ( V_188 & V_191 ) {
error = F_104 ( & V_182 ) ;
if ( error )
return error ;
F_120 ( & V_182 -> V_185 ) ;
V_190 -> V_183 . V_182 = V_182 ;
} else
V_190 -> V_183 . V_182 = NULL ;
return 0 ;
}
void F_121 ( struct V_189 * V_190 )
{
struct V_180 * V_110 ;
V_110 = V_190 -> V_183 . V_182 ;
if ( ! V_110 )
return;
V_190 -> V_183 . V_182 = NULL ;
if ( ! F_122 ( & V_110 -> V_185 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_69 * V_70 ;
struct V_85 V_109 ;
int V_111 , V_31 ;
F_86 () ;
V_70 = F_123 ( V_110 -> V_112 . V_96 ,
struct V_69 , V_112 ) ;
if ( & V_70 -> V_112 == & V_110 -> V_112 ) {
F_21 ( & V_110 -> V_38 ) ;
F_49 () ;
break;
}
F_24 ( & V_110 -> V_38 ) ;
V_111 = V_70 -> V_111 ;
F_27 ( & V_110 -> V_38 ) ;
if ( V_111 == - 1 ) {
F_49 () ;
continue;
}
V_19 = F_37 ( V_190 -> V_192 -> V_193 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
continue;
}
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
continue;
}
V_70 = F_107 ( V_110 , V_111 ) ;
if ( V_70 == NULL ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
continue;
}
F_74 ( & V_19 -> V_41 ) ;
F_62 ( & V_70 -> V_63 ) ;
F_75 ( & V_70 -> V_112 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_194 = & V_19 -> V_26 [ V_31 ] ;
if ( V_70 -> V_78 [ V_31 ] ) {
V_194 -> V_72 += V_70 -> V_78 [ V_31 ] ;
if ( V_194 -> V_72 < 0 )
V_194 -> V_72 = 0 ;
if ( V_194 -> V_72 > V_74 )
V_194 -> V_72 = V_74 ;
V_194 -> V_80 = F_92 ( V_104 ) ;
}
}
F_12 ( & V_109 ) ;
F_68 ( V_19 , NULL , 0 , 1 , & V_109 ) ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_57 ( & V_109 ) ;
F_76 ( V_70 , V_37 ) ;
}
F_114 ( V_110 ) ;
}
static int V_17 ( struct V_195 * V_47 , void * V_196 )
{
struct V_197 * V_198 = F_124 ( V_47 ) ;
struct V_18 * V_19 = V_196 ;
T_5 V_101 ;
F_20 ( V_19 ) ;
V_101 = F_80 ( V_19 ) ;
F_125 ( V_47 ,
L_5 ,
V_19 -> V_41 . V_52 ,
V_19 -> V_41 . V_43 ,
V_19 -> V_41 . V_59 ,
V_19 -> V_32 ,
F_126 ( V_198 , V_19 -> V_41 . V_172 ) ,
F_127 ( V_198 , V_19 -> V_41 . V_173 ) ,
F_126 ( V_198 , V_19 -> V_41 . V_199 ) ,
F_127 ( V_198 , V_19 -> V_41 . V_200 ) ,
V_101 ,
V_19 -> V_64 ) ;
return 0 ;
}
