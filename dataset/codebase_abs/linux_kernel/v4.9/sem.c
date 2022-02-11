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
if ( V_19 -> V_38 ) {
return;
}
F_21 ( V_19 -> V_38 , true ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
V_24 = V_19 -> V_26 + V_31 ;
F_22 ( & V_24 -> V_39 ) ;
}
F_23 () ;
}
static void F_24 ( struct V_18 * V_19 )
{
if ( V_19 -> V_23 ) {
return;
}
F_25 ( & V_19 -> V_38 , false ) ;
}
static inline int F_26 ( struct V_18 * V_19 , struct V_40 * V_27 ,
int V_41 )
{
struct V_24 * V_24 ;
if ( V_41 != 1 ) {
F_27 ( & V_19 -> V_42 ) ;
F_20 ( V_19 ) ;
return V_43 ;
}
V_24 = V_19 -> V_26 + V_27 -> V_28 ;
if ( ! V_19 -> V_38 ) {
F_28 ( & V_24 -> V_39 ) ;
F_29 () ;
if ( ! F_30 ( & V_19 -> V_38 ) ) {
return V_27 -> V_28 ;
}
F_31 ( & V_24 -> V_39 ) ;
}
F_27 ( & V_19 -> V_42 ) ;
if ( V_19 -> V_23 == 0 ) {
F_28 ( & V_24 -> V_39 ) ;
F_32 ( & V_19 -> V_42 ) ;
return V_27 -> V_28 ;
} else {
F_20 ( V_19 ) ;
return V_43 ;
}
}
static inline void F_33 ( struct V_18 * V_19 , int V_44 )
{
if ( V_44 == V_43 ) {
F_9 ( V_19 ) ;
F_24 ( V_19 ) ;
F_32 ( & V_19 -> V_42 ) ;
} else {
struct V_24 * V_24 = V_19 -> V_26 + V_44 ;
F_31 ( & V_24 -> V_39 ) ;
}
}
static inline struct V_18 * F_34 ( struct V_1 * V_2 ,
int V_45 , struct V_40 * V_27 , int V_41 , int * V_44 )
{
struct V_46 * V_47 ;
struct V_18 * V_19 ;
V_47 = F_35 ( & F_5 ( V_2 ) , V_45 ) ;
if ( F_36 ( V_47 ) )
return F_37 ( V_47 ) ;
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
* V_44 = F_26 ( V_19 , V_27 , V_41 ) ;
if ( F_38 ( V_47 ) )
return F_16 ( V_47 , struct V_18 , V_42 ) ;
F_33 ( V_19 , * V_44 ) ;
return F_39 ( - V_48 ) ;
}
static inline struct V_18 * F_40 ( struct V_1 * V_2 , int V_45 )
{
struct V_46 * V_47 = F_35 ( & F_5 ( V_2 ) , V_45 ) ;
if ( F_36 ( V_47 ) )
return F_37 ( V_47 ) ;
return F_16 ( V_47 , struct V_18 , V_42 ) ;
}
static inline struct V_18 * F_41 ( struct V_1 * V_2 ,
int V_45 )
{
struct V_46 * V_47 = F_42 ( & F_5 ( V_2 ) , V_45 ) ;
if ( F_36 ( V_47 ) )
return F_37 ( V_47 ) ;
return F_16 ( V_47 , struct V_18 , V_42 ) ;
}
static inline void F_43 ( struct V_18 * V_19 )
{
F_26 ( V_19 , NULL , - 1 ) ;
F_44 ( V_19 , F_15 ) ;
}
static inline void F_45 ( struct V_1 * V_2 , struct V_18 * V_49 )
{
F_46 ( & F_5 ( V_2 ) , & V_49 -> V_42 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
int V_45 ;
int V_52 ;
struct V_18 * V_19 ;
int V_53 ;
T_2 V_54 = V_51 -> V_54 ;
int V_55 = V_51 -> V_56 . V_55 ;
int V_57 = V_51 -> V_58 ;
int V_31 ;
if ( ! V_55 )
return - V_48 ;
if ( V_2 -> V_11 + V_55 > V_2 -> V_5 )
return - V_59 ;
V_53 = sizeof( * V_19 ) + V_55 * sizeof( struct V_24 ) ;
V_19 = F_48 ( V_53 ) ;
if ( ! V_19 )
return - V_60 ;
memset ( V_19 , 0 , V_53 ) ;
V_19 -> V_42 . V_61 = ( V_57 & V_62 ) ;
V_19 -> V_42 . V_54 = V_54 ;
V_19 -> V_42 . V_63 = NULL ;
V_52 = F_49 ( V_19 ) ;
if ( V_52 ) {
F_44 ( V_19 , F_19 ) ;
return V_52 ;
}
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_64 ) ;
F_50 ( & V_19 -> V_26 [ V_31 ] . V_39 ) ;
}
V_19 -> V_23 = 0 ;
V_19 -> V_38 = true ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_64 ) ;
F_12 ( & V_19 -> V_65 ) ;
V_19 -> V_32 = V_55 ;
V_19 -> V_66 = F_51 () ;
V_45 = F_52 ( & F_5 ( V_2 ) , & V_19 -> V_42 , V_2 -> V_9 ) ;
if ( V_45 < 0 ) {
F_44 ( V_19 , F_15 ) ;
return V_45 ;
}
V_2 -> V_11 += V_55 ;
F_33 ( V_19 , - 1 ) ;
F_53 () ;
return V_19 -> V_42 . V_45 ;
}
static inline int F_54 ( struct V_46 * V_47 , int V_57 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
return F_55 ( V_19 , V_57 ) ;
}
static inline int F_56 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
if ( V_51 -> V_56 . V_55 > V_19 -> V_32 )
return - V_48 ;
return 0 ;
}
static int F_57 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_67 , V_68 , V_41 , V_69 ;
struct V_40 * V_70 ;
struct V_24 * V_25 ;
struct V_40 * V_27 ;
struct V_71 * V_72 ;
V_27 = V_21 -> V_27 ;
V_41 = V_21 -> V_41 ;
V_72 = V_21 -> V_73 ;
for ( V_70 = V_27 ; V_70 < V_27 + V_41 ; V_70 ++ ) {
V_25 = V_19 -> V_26 + V_70 -> V_28 ;
V_68 = V_70 -> V_68 ;
V_67 = V_25 -> V_74 ;
if ( ! V_68 && V_67 )
goto V_75;
V_67 += V_68 ;
if ( V_67 < 0 )
goto V_75;
if ( V_67 > V_76 )
goto V_77;
if ( V_70 -> V_78 & V_79 ) {
int V_73 = V_72 -> V_80 [ V_70 -> V_28 ] - V_68 ;
if ( V_73 < ( - V_81 - 1 ) || V_73 > V_81 )
goto V_77;
V_72 -> V_80 [ V_70 -> V_28 ] = V_73 ;
}
V_25 -> V_74 = V_67 ;
}
V_70 -- ;
V_69 = V_21 -> V_69 ;
while ( V_70 >= V_27 ) {
V_19 -> V_26 [ V_70 -> V_28 ] . V_82 = V_69 ;
V_70 -- ;
}
return 0 ;
V_77:
V_67 = - V_83 ;
goto V_73;
V_75:
V_21 -> V_84 = V_70 ;
if ( V_70 -> V_78 & V_85 )
V_67 = - V_86 ;
else
V_67 = 1 ;
V_73:
V_70 -- ;
while ( V_70 >= V_27 ) {
V_68 = V_70 -> V_68 ;
V_19 -> V_26 [ V_70 -> V_28 ] . V_74 -= V_68 ;
if ( V_70 -> V_78 & V_79 )
V_72 -> V_80 [ V_70 -> V_28 ] += V_68 ;
V_70 -- ;
}
return V_67 ;
}
static void F_58 ( struct V_87 * V_88 ,
struct V_20 * V_21 , int error )
{
if ( F_59 ( V_88 ) ) {
F_60 () ;
}
V_21 -> V_89 = V_90 ;
V_21 -> V_69 = error ;
F_11 ( & V_21 -> V_29 , V_88 ) ;
}
static void F_61 ( struct V_87 * V_88 )
{
struct V_20 * V_21 , * V_91 ;
int V_92 ;
V_92 = ! F_59 ( V_88 ) ;
F_10 (q, t, pt, list) {
F_62 ( V_21 -> V_93 ) ;
F_63 () ;
V_21 -> V_89 = V_21 -> V_69 ;
}
if ( V_92 )
F_64 () ;
}
static void F_65 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_66 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_41 > 1 )
V_19 -> V_23 -- ;
}
static int F_67 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_59 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_41 > 1 )
return 1 ;
return 0 ;
}
static int F_68 ( struct V_18 * V_19 , int V_94 ,
struct V_87 * V_88 )
{
struct V_20 * V_21 ;
struct V_87 * V_95 ;
struct V_87 * V_96 ;
int V_97 = 0 ;
if ( V_94 == - 1 )
V_96 = & V_19 -> V_64 ;
else
V_96 = & V_19 -> V_26 [ V_94 ] . V_64 ;
V_95 = V_96 -> V_98 ;
while ( V_95 != V_96 ) {
int error ;
V_21 = F_16 ( V_95 , struct V_20 , V_29 ) ;
V_95 = V_95 -> V_98 ;
error = F_57 ( V_19 , V_21 ) ;
if ( error <= 0 ) {
F_65 ( V_19 , V_21 ) ;
F_58 ( V_88 , V_21 , error ) ;
if ( error == 0 )
V_97 = 1 ;
}
}
return V_97 ;
}
static int F_69 ( struct V_18 * V_19 , struct V_40 * V_27 ,
int V_41 , struct V_87 * V_88 )
{
int V_31 ;
int V_97 = 0 ;
int V_99 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
int V_100 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_100 ] . V_74 == 0 ) {
V_99 = 1 ;
V_97 |= F_68 ( V_19 , V_100 , V_88 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_74 == 0 ) {
V_99 = 1 ;
V_97 |= F_68 ( V_19 , V_31 , V_88 ) ;
}
}
}
if ( V_99 )
V_97 |= F_68 ( V_19 , - 1 , V_88 ) ;
return V_97 ;
}
static int F_70 ( struct V_18 * V_19 , int V_94 , struct V_87 * V_88 )
{
struct V_20 * V_21 ;
struct V_87 * V_95 ;
struct V_87 * V_96 ;
int V_97 = 0 ;
if ( V_94 == - 1 )
V_96 = & V_19 -> V_30 ;
else
V_96 = & V_19 -> V_26 [ V_94 ] . V_30 ;
V_101:
V_95 = V_96 -> V_98 ;
while ( V_95 != V_96 ) {
int error , V_102 ;
V_21 = F_16 ( V_95 , struct V_20 , V_29 ) ;
V_95 = V_95 -> V_98 ;
if ( V_94 != - 1 && V_19 -> V_26 [ V_94 ] . V_74 == 0 )
break;
error = F_57 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_65 ( V_19 , V_21 ) ;
if ( error ) {
V_102 = 0 ;
} else {
V_97 = 1 ;
F_69 ( V_19 , V_21 -> V_27 , V_21 -> V_41 , V_88 ) ;
V_102 = F_67 ( V_19 , V_21 ) ;
}
F_58 ( V_88 , V_21 , error ) ;
if ( V_102 )
goto V_101;
}
return V_97 ;
}
static void F_71 ( struct V_18 * V_19 , struct V_40 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_103 = F_51 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_103 =
F_51 () ;
}
}
static void F_72 ( struct V_18 * V_19 , struct V_40 * V_27 , int V_41 ,
int V_104 , struct V_87 * V_88 )
{
int V_31 ;
V_104 |= F_69 ( V_19 , V_27 , V_41 , V_88 ) ;
if ( ! F_59 ( & V_19 -> V_30 ) ) {
V_104 |= F_70 ( V_19 , - 1 , V_88 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_104 |= F_70 ( V_19 , V_31 , V_88 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_68 > 0 ) {
V_104 |= F_70 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_88 ) ;
}
}
}
}
if ( V_104 )
F_71 ( V_19 , V_27 ) ;
}
static int F_73 ( struct V_18 * V_19 , int V_94 , struct V_20 * V_21 ,
bool V_105 )
{
struct V_40 * V_70 = V_21 -> V_84 ;
F_74 ( L_3
L_4 ,
V_106 -> V_107 , F_75 ( V_106 ) ) ;
if ( V_70 -> V_28 != V_94 )
return 0 ;
if ( V_105 && V_70 -> V_68 == 0 )
return 1 ;
if ( ! V_105 && V_70 -> V_68 < 0 )
return 1 ;
return 0 ;
}
static int F_76 ( struct V_18 * V_19 , T_3 V_94 ,
bool V_105 )
{
struct V_87 * V_108 ;
struct V_20 * V_21 ;
int V_109 ;
V_109 = 0 ;
if ( V_105 )
V_108 = & V_19 -> V_26 [ V_94 ] . V_64 ;
else
V_108 = & V_19 -> V_26 [ V_94 ] . V_30 ;
F_77 (q, l, list) {
V_109 ++ ;
}
F_77 (q, &sma->pending_alter, list) {
V_109 += F_73 ( V_19 , V_94 , V_21 , V_105 ) ;
}
if ( V_105 ) {
F_77 (q, &sma->pending_const, list) {
V_109 += F_73 ( V_19 , V_94 , V_21 , V_105 ) ;
}
}
return V_109 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_71 * V_72 , * V_110 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
struct V_87 V_111 ;
int V_31 ;
F_78 ( & V_19 -> V_42 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_66 ( & V_72 -> V_65 ) ;
F_28 ( & V_72 -> V_112 -> V_39 ) ;
V_72 -> V_113 = - 1 ;
F_79 ( & V_72 -> V_114 ) ;
F_31 ( & V_72 -> V_112 -> V_39 ) ;
F_80 ( V_72 , V_37 ) ;
}
F_12 ( & V_111 ) ;
F_10 (q, tq, &sma->pending_const, list) {
F_65 ( V_19 , V_21 ) ;
F_58 ( & V_111 , V_21 , - V_115 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_65 ( V_19 , V_21 ) ;
F_58 ( & V_111 , V_21 , - V_115 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_65 ( V_19 , V_21 ) ;
F_58 ( & V_111 , V_21 , - V_115 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_65 ( V_19 , V_21 ) ;
F_58 ( & V_111 , V_21 , - V_115 ) ;
}
}
F_45 ( V_2 , V_19 ) ;
F_33 ( V_19 , - 1 ) ;
F_53 () ;
F_61 ( & V_111 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_44 ( V_19 , F_15 ) ;
}
static unsigned long F_81 ( void T_4 * V_116 , struct V_117 * V_118 , int V_119 )
{
switch ( V_119 ) {
case V_120 :
return F_82 ( V_116 , V_118 , sizeof( * V_118 ) ) ;
case V_121 :
{
struct V_122 V_123 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
F_83 ( & V_118 -> V_42 , & V_123 . V_42 ) ;
V_123 . V_103 = V_118 -> V_103 ;
V_123 . V_66 = V_118 -> V_66 ;
V_123 . V_32 = V_118 -> V_32 ;
return F_82 ( V_116 , & V_123 , sizeof( V_123 ) ) ;
}
default:
return - V_48 ;
}
}
static T_5 F_84 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_124 ;
V_124 = V_19 -> V_26 [ 0 ] . V_103 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_125 = V_19 -> V_26 [ V_31 ] . V_103 ;
if ( V_125 > V_124 )
V_124 = V_125 ;
}
return V_124 ;
}
static int F_85 ( struct V_1 * V_2 , int V_113 ,
int V_126 , int V_119 , void T_4 * V_36 )
{
int V_127 ;
struct V_18 * V_19 ;
switch ( V_126 ) {
case V_128 :
case V_129 :
{
struct V_130 V_130 ;
int V_131 ;
V_127 = F_86 ( NULL , V_126 ) ;
if ( V_127 )
return V_127 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_132 = V_2 -> V_9 ;
V_130 . V_133 = V_2 -> V_5 ;
V_130 . V_134 = V_2 -> V_3 ;
V_130 . V_135 = V_2 -> V_7 ;
V_130 . V_136 = V_76 ;
V_130 . V_137 = V_138 ;
V_130 . V_139 = V_140 ;
V_130 . V_141 = V_142 ;
F_87 ( & F_5 ( V_2 ) . V_143 ) ;
if ( V_126 == V_129 ) {
V_130 . V_144 = F_5 ( V_2 ) . V_145 ;
V_130 . V_146 = V_2 -> V_11 ;
} else {
V_130 . V_144 = V_147 ;
V_130 . V_146 = V_81 ;
}
V_131 = F_88 ( & F_5 ( V_2 ) ) ;
F_89 ( & F_5 ( V_2 ) . V_143 ) ;
if ( F_82 ( V_36 , & V_130 , sizeof( struct V_130 ) ) )
return - V_148 ;
return ( V_131 < 0 ) ? 0 : V_131 ;
}
case V_149 :
case V_150 :
{
struct V_117 V_151 ;
int V_45 = 0 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
F_90 () ;
if ( V_126 == V_150 ) {
V_19 = F_40 ( V_2 , V_113 ) ;
if ( F_36 ( V_19 ) ) {
V_127 = F_91 ( V_19 ) ;
goto V_152;
}
V_45 = V_19 -> V_42 . V_45 ;
} else {
V_19 = F_41 ( V_2 , V_113 ) ;
if ( F_36 ( V_19 ) ) {
V_127 = F_91 ( V_19 ) ;
goto V_152;
}
}
V_127 = - V_153 ;
if ( F_92 ( V_2 , & V_19 -> V_42 , V_154 ) )
goto V_152;
V_127 = F_86 ( V_19 , V_126 ) ;
if ( V_127 )
goto V_152;
F_93 ( & V_19 -> V_42 , & V_151 . V_42 ) ;
V_151 . V_103 = F_84 ( V_19 ) ;
V_151 . V_66 = V_19 -> V_66 ;
V_151 . V_32 = V_19 -> V_32 ;
F_53 () ;
if ( F_81 ( V_36 , & V_151 , V_119 ) )
return - V_148 ;
return V_45 ;
}
default:
return - V_48 ;
}
V_152:
F_53 () ;
return V_127 ;
}
static int F_94 ( struct V_1 * V_2 , int V_113 , int V_94 ,
unsigned long V_155 )
{
struct V_71 * V_72 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_127 ;
struct V_87 V_111 ;
int V_156 ;
#if F_95 ( V_157 ) && F_95 ( V_158 )
V_156 = V_155 >> 32 ;
#else
V_156 = V_155 ;
#endif
if ( V_156 > V_76 || V_156 < 0 )
return - V_83 ;
F_12 ( & V_111 ) ;
F_90 () ;
V_19 = F_41 ( V_2 , V_113 ) ;
if ( F_36 ( V_19 ) ) {
F_53 () ;
return F_91 ( V_19 ) ;
}
if ( V_94 < 0 || V_94 >= V_19 -> V_32 ) {
F_53 () ;
return - V_48 ;
}
if ( F_92 ( V_2 , & V_19 -> V_42 , V_159 ) ) {
F_53 () ;
return - V_153 ;
}
V_127 = F_86 ( V_19 , V_160 ) ;
if ( V_127 ) {
F_53 () ;
return - V_153 ;
}
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
F_33 ( V_19 , - 1 ) ;
F_53 () ;
return - V_115 ;
}
V_25 = & V_19 -> V_26 [ V_94 ] ;
F_78 ( & V_19 -> V_42 ) ;
F_77 (un, &sma->list_id, list_id)
V_72 -> V_80 [ V_94 ] = 0 ;
V_25 -> V_74 = V_156 ;
V_25 -> V_82 = F_96 ( V_106 ) ;
V_19 -> V_66 = F_51 () ;
F_72 ( V_19 , NULL , 0 , 0 , & V_111 ) ;
F_33 ( V_19 , - 1 ) ;
F_53 () ;
F_61 ( & V_111 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , int V_113 , int V_94 ,
int V_126 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_127 , V_55 ;
T_3 V_161 [ V_162 ] ;
T_3 * V_163 = V_161 ;
struct V_87 V_111 ;
F_12 ( & V_111 ) ;
F_90 () ;
V_19 = F_41 ( V_2 , V_113 ) ;
if ( F_36 ( V_19 ) ) {
F_53 () ;
return F_91 ( V_19 ) ;
}
V_55 = V_19 -> V_32 ;
V_127 = - V_153 ;
if ( F_92 ( V_2 , & V_19 -> V_42 , V_126 == V_164 ? V_159 : V_154 ) )
goto V_165;
V_127 = F_86 ( V_19 , V_126 ) ;
if ( V_127 )
goto V_165;
V_127 = - V_153 ;
switch ( V_126 ) {
case V_166 :
{
T_3 T_4 * V_167 = V_36 ;
int V_31 ;
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
V_127 = - V_115 ;
goto V_152;
}
if ( V_55 > V_162 ) {
if ( ! F_98 ( V_19 ) ) {
V_127 = - V_115 ;
goto V_152;
}
F_33 ( V_19 , - 1 ) ;
F_53 () ;
V_163 = F_99 ( sizeof( T_3 ) * V_55 ) ;
if ( V_163 == NULL ) {
F_44 ( V_19 , F_15 ) ;
return - V_60 ;
}
F_90 () ;
F_43 ( V_19 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
V_127 = - V_115 ;
goto V_152;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_163 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_74 ;
F_33 ( V_19 , - 1 ) ;
F_53 () ;
V_127 = 0 ;
if ( F_82 ( V_167 , V_163 , V_55 * sizeof( T_3 ) ) )
V_127 = - V_148 ;
goto V_168;
}
case V_164 :
{
int V_31 ;
struct V_71 * V_72 ;
if ( ! F_98 ( V_19 ) ) {
V_127 = - V_115 ;
goto V_165;
}
F_53 () ;
if ( V_55 > V_162 ) {
V_163 = F_99 ( sizeof( T_3 ) * V_55 ) ;
if ( V_163 == NULL ) {
F_44 ( V_19 , F_15 ) ;
return - V_60 ;
}
}
if ( F_100 ( V_163 , V_36 , V_55 * sizeof( T_3 ) ) ) {
F_44 ( V_19 , F_15 ) ;
V_127 = - V_148 ;
goto V_168;
}
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
if ( V_163 [ V_31 ] > V_76 ) {
F_44 ( V_19 , F_15 ) ;
V_127 = - V_83 ;
goto V_168;
}
}
F_90 () ;
F_43 ( V_19 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
V_127 = - V_115 ;
goto V_152;
}
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
V_19 -> V_26 [ V_31 ] . V_74 = V_163 [ V_31 ] ;
V_19 -> V_26 [ V_31 ] . V_82 = F_96 ( V_106 ) ;
}
F_78 ( & V_19 -> V_42 ) ;
F_77 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ )
V_72 -> V_80 [ V_31 ] = 0 ;
}
V_19 -> V_66 = F_51 () ;
F_72 ( V_19 , NULL , 0 , 0 , & V_111 ) ;
V_127 = 0 ;
goto V_152;
}
}
V_127 = - V_48 ;
if ( V_94 < 0 || V_94 >= V_55 )
goto V_165;
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
V_127 = - V_115 ;
goto V_152;
}
V_25 = & V_19 -> V_26 [ V_94 ] ;
switch ( V_126 ) {
case V_169 :
V_127 = V_25 -> V_74 ;
goto V_152;
case V_170 :
V_127 = V_25 -> V_82 ;
goto V_152;
case V_171 :
V_127 = F_76 ( V_19 , V_94 , 0 ) ;
goto V_152;
case V_172 :
V_127 = F_76 ( V_19 , V_94 , 1 ) ;
goto V_152;
}
V_152:
F_33 ( V_19 , - 1 ) ;
V_165:
F_53 () ;
F_61 ( & V_111 ) ;
V_168:
if ( V_163 != V_161 )
F_101 ( V_163 ) ;
return V_127 ;
}
static inline unsigned long
F_102 ( struct V_117 * V_123 , void T_4 * V_116 , int V_119 )
{
switch ( V_119 ) {
case V_120 :
if ( F_100 ( V_123 , V_116 , sizeof( * V_123 ) ) )
return - V_148 ;
return 0 ;
case V_121 :
{
struct V_122 V_173 ;
if ( F_100 ( & V_173 , V_116 , sizeof( V_173 ) ) )
return - V_148 ;
V_123 -> V_42 . V_174 = V_173 . V_42 . V_174 ;
V_123 -> V_42 . V_175 = V_173 . V_42 . V_175 ;
V_123 -> V_42 . V_61 = V_173 . V_42 . V_61 ;
return 0 ;
}
default:
return - V_48 ;
}
}
static int F_103 ( struct V_1 * V_2 , int V_113 ,
int V_126 , int V_119 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
int V_127 ;
struct V_117 V_176 ;
struct V_46 * V_47 ;
if ( V_126 == V_177 ) {
if ( F_102 ( & V_176 , V_36 , V_119 ) )
return - V_148 ;
}
F_104 ( & F_5 ( V_2 ) . V_143 ) ;
F_90 () ;
V_47 = F_105 ( V_2 , & F_5 ( V_2 ) , V_113 , V_126 ,
& V_176 . V_42 , 0 ) ;
if ( F_36 ( V_47 ) ) {
V_127 = F_91 ( V_47 ) ;
goto V_178;
}
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
V_127 = F_86 ( V_19 , V_126 ) ;
if ( V_127 )
goto V_178;
switch ( V_126 ) {
case V_179 :
F_26 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_47 ) ;
goto V_180;
case V_177 :
F_26 ( V_19 , NULL , - 1 ) ;
V_127 = F_106 ( & V_176 . V_42 , V_47 ) ;
if ( V_127 )
goto V_181;
V_19 -> V_66 = F_51 () ;
break;
default:
V_127 = - V_48 ;
goto V_178;
}
V_181:
F_33 ( V_19 , - 1 ) ;
V_178:
F_53 () ;
V_180:
F_107 ( & F_5 ( V_2 ) . V_143 ) ;
return V_127 ;
}
static inline int F_108 ( struct V_182 * * V_183 )
{
struct V_182 * V_184 ;
V_184 = V_106 -> V_185 . V_184 ;
if ( ! V_184 ) {
V_184 = F_109 ( sizeof( * V_184 ) , V_186 ) ;
if ( V_184 == NULL )
return - V_60 ;
F_50 ( & V_184 -> V_39 ) ;
F_110 ( & V_184 -> V_187 , 1 ) ;
F_12 ( & V_184 -> V_114 ) ;
V_106 -> V_185 . V_184 = V_184 ;
}
* V_183 = V_184 ;
return 0 ;
}
static struct V_71 * F_111 ( struct V_182 * V_112 , int V_113 )
{
struct V_71 * V_72 ;
F_112 (un, &ulp->list_proc, list_proc) {
if ( V_72 -> V_113 == V_113 )
return V_72 ;
}
return NULL ;
}
static struct V_71 * F_113 ( struct V_182 * V_112 , int V_113 )
{
struct V_71 * V_72 ;
F_114 ( & V_112 -> V_39 ) ;
V_72 = F_111 ( V_112 , V_113 ) ;
if ( V_72 ) {
F_79 ( & V_72 -> V_114 ) ;
F_115 ( & V_72 -> V_114 , & V_112 -> V_114 ) ;
}
return V_72 ;
}
static struct V_71 * F_116 ( struct V_1 * V_2 , int V_113 )
{
struct V_18 * V_19 ;
struct V_182 * V_112 ;
struct V_71 * V_72 , * V_188 ;
int V_55 , error ;
error = F_108 ( & V_112 ) ;
if ( error )
return F_39 ( error ) ;
F_90 () ;
F_28 ( & V_112 -> V_39 ) ;
V_72 = F_113 ( V_112 , V_113 ) ;
F_31 ( & V_112 -> V_39 ) ;
if ( F_117 ( V_72 != NULL ) )
goto V_123;
V_19 = F_41 ( V_2 , V_113 ) ;
if ( F_36 ( V_19 ) ) {
F_53 () ;
return F_37 ( V_19 ) ;
}
V_55 = V_19 -> V_32 ;
if ( ! F_98 ( V_19 ) ) {
F_53 () ;
V_72 = F_39 ( - V_115 ) ;
goto V_123;
}
F_53 () ;
V_188 = F_109 ( sizeof( struct V_71 ) + sizeof( short ) * V_55 , V_186 ) ;
if ( ! V_188 ) {
F_44 ( V_19 , F_15 ) ;
return F_39 ( - V_60 ) ;
}
F_90 () ;
F_43 ( V_19 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
F_33 ( V_19 , - 1 ) ;
F_53 () ;
F_118 ( V_188 ) ;
V_72 = F_39 ( - V_115 ) ;
goto V_123;
}
F_28 ( & V_112 -> V_39 ) ;
V_72 = F_113 ( V_112 , V_113 ) ;
if ( V_72 ) {
F_118 ( V_188 ) ;
goto V_189;
}
V_188 -> V_80 = ( short * ) & V_188 [ 1 ] ;
V_188 -> V_112 = V_112 ;
V_188 -> V_113 = V_113 ;
F_114 ( & V_112 -> V_39 ) ;
F_115 ( & V_188 -> V_114 , & V_112 -> V_114 ) ;
F_78 ( & V_19 -> V_42 ) ;
F_119 ( & V_188 -> V_65 , & V_19 -> V_65 ) ;
V_72 = V_188 ;
V_189:
F_31 ( & V_112 -> V_39 ) ;
F_33 ( V_19 , - 1 ) ;
V_123:
return V_72 ;
}
static int F_120 ( struct V_20 * V_21 )
{
int error ;
error = V_21 -> V_89 ;
while ( F_121 ( error == V_90 ) ) {
F_122 () ;
error = V_21 -> V_89 ;
}
return error ;
}
int F_123 ( unsigned long V_190 , struct V_191 * V_192 )
{
struct V_182 * V_184 ;
int error ;
if ( V_190 & V_193 ) {
error = F_108 ( & V_184 ) ;
if ( error )
return error ;
F_124 ( & V_184 -> V_187 ) ;
V_192 -> V_185 . V_184 = V_184 ;
} else
V_192 -> V_185 . V_184 = NULL ;
return 0 ;
}
void F_125 ( struct V_191 * V_192 )
{
struct V_182 * V_112 ;
V_112 = V_192 -> V_185 . V_184 ;
if ( ! V_112 )
return;
V_192 -> V_185 . V_184 = NULL ;
if ( ! F_126 ( & V_112 -> V_187 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_71 * V_72 ;
struct V_87 V_111 ;
int V_113 , V_31 ;
F_127 () ;
F_90 () ;
V_72 = F_128 ( V_112 -> V_114 . V_98 ,
struct V_71 , V_114 ) ;
if ( & V_72 -> V_114 == & V_112 -> V_114 ) {
F_22 ( & V_112 -> V_39 ) ;
F_53 () ;
break;
}
F_28 ( & V_112 -> V_39 ) ;
V_113 = V_72 -> V_113 ;
F_31 ( & V_112 -> V_39 ) ;
if ( V_113 == - 1 ) {
F_53 () ;
continue;
}
V_19 = F_41 ( V_192 -> V_194 -> V_195 , V_113 ) ;
if ( F_36 ( V_19 ) ) {
F_53 () ;
continue;
}
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_38 ( & V_19 -> V_42 ) ) {
F_33 ( V_19 , - 1 ) ;
F_53 () ;
continue;
}
V_72 = F_111 ( V_112 , V_113 ) ;
if ( V_72 == NULL ) {
F_33 ( V_19 , - 1 ) ;
F_53 () ;
continue;
}
F_78 ( & V_19 -> V_42 ) ;
F_66 ( & V_72 -> V_65 ) ;
F_79 ( & V_72 -> V_114 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_196 = & V_19 -> V_26 [ V_31 ] ;
if ( V_72 -> V_80 [ V_31 ] ) {
V_196 -> V_74 += V_72 -> V_80 [ V_31 ] ;
if ( V_196 -> V_74 < 0 )
V_196 -> V_74 = 0 ;
if ( V_196 -> V_74 > V_76 )
V_196 -> V_74 = V_76 ;
V_196 -> V_82 = F_96 ( V_106 ) ;
}
}
F_12 ( & V_111 ) ;
F_72 ( V_19 , NULL , 0 , 1 , & V_111 ) ;
F_33 ( V_19 , - 1 ) ;
F_53 () ;
F_61 ( & V_111 ) ;
F_80 ( V_72 , V_37 ) ;
}
F_118 ( V_112 ) ;
}
static int V_17 ( struct V_197 * V_49 , void * V_198 )
{
struct V_199 * V_200 = F_129 ( V_49 ) ;
struct V_18 * V_19 = V_198 ;
T_5 V_103 ;
F_20 ( V_19 ) ;
V_103 = F_84 ( V_19 ) ;
F_130 ( V_49 ,
L_5 ,
V_19 -> V_42 . V_54 ,
V_19 -> V_42 . V_45 ,
V_19 -> V_42 . V_61 ,
V_19 -> V_32 ,
F_131 ( V_200 , V_19 -> V_42 . V_174 ) ,
F_132 ( V_200 , V_19 -> V_42 . V_175 ) ,
F_131 ( V_200 , V_19 -> V_42 . V_201 ) ,
F_132 ( V_200 , V_19 -> V_42 . V_202 ) ,
V_103 ,
V_19 -> V_66 ) ;
F_24 ( V_19 ) ;
return 0 ;
}
