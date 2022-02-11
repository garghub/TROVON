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
static inline struct V_18 * F_34 ( struct V_1 * V_2 , int V_45 )
{
struct V_46 * V_47 = F_35 ( & F_5 ( V_2 ) , V_45 ) ;
if ( F_36 ( V_47 ) )
return F_37 ( V_47 ) ;
return F_16 ( V_47 , struct V_18 , V_42 ) ;
}
static inline struct V_18 * F_38 ( struct V_1 * V_2 ,
int V_45 )
{
struct V_46 * V_47 = F_39 ( & F_5 ( V_2 ) , V_45 ) ;
if ( F_36 ( V_47 ) )
return F_37 ( V_47 ) ;
return F_16 ( V_47 , struct V_18 , V_42 ) ;
}
static inline void F_40 ( struct V_18 * V_19 )
{
F_26 ( V_19 , NULL , - 1 ) ;
F_41 ( V_19 , F_15 ) ;
}
static inline void F_42 ( struct V_1 * V_2 , struct V_18 * V_48 )
{
F_43 ( & F_5 ( V_2 ) , & V_48 -> V_42 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_45 ;
int V_51 ;
struct V_18 * V_19 ;
int V_52 ;
T_2 V_53 = V_50 -> V_53 ;
int V_54 = V_50 -> V_55 . V_54 ;
int V_56 = V_50 -> V_57 ;
int V_31 ;
if ( ! V_54 )
return - V_58 ;
if ( V_2 -> V_11 + V_54 > V_2 -> V_5 )
return - V_59 ;
V_52 = sizeof( * V_19 ) + V_54 * sizeof( struct V_24 ) ;
V_19 = F_45 ( V_52 ) ;
if ( ! V_19 )
return - V_60 ;
memset ( V_19 , 0 , V_52 ) ;
V_19 -> V_42 . V_61 = ( V_56 & V_62 ) ;
V_19 -> V_42 . V_53 = V_53 ;
V_19 -> V_42 . V_63 = NULL ;
V_51 = F_46 ( V_19 ) ;
if ( V_51 ) {
F_41 ( V_19 , F_19 ) ;
return V_51 ;
}
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_64 ) ;
F_47 ( & V_19 -> V_26 [ V_31 ] . V_39 ) ;
}
V_19 -> V_23 = 0 ;
V_19 -> V_38 = true ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_64 ) ;
F_12 ( & V_19 -> V_65 ) ;
V_19 -> V_32 = V_54 ;
V_19 -> V_66 = F_48 () ;
V_45 = F_49 ( & F_5 ( V_2 ) , & V_19 -> V_42 , V_2 -> V_9 ) ;
if ( V_45 < 0 ) {
F_41 ( V_19 , F_15 ) ;
return V_45 ;
}
V_2 -> V_11 += V_54 ;
F_33 ( V_19 , - 1 ) ;
F_50 () ;
return V_19 -> V_42 . V_45 ;
}
static inline int F_51 ( struct V_46 * V_47 , int V_56 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
return F_52 ( V_19 , V_56 ) ;
}
static inline int F_53 ( struct V_46 * V_47 ,
struct V_49 * V_50 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
if ( V_50 -> V_55 . V_54 > V_19 -> V_32 )
return - V_58 ;
return 0 ;
}
static int F_54 ( struct V_18 * V_19 , struct V_20 * V_21 )
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
static int F_55 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_67 , V_68 , V_41 ;
struct V_40 * V_70 ;
struct V_24 * V_25 ;
struct V_40 * V_27 ;
struct V_71 * V_72 ;
V_27 = V_21 -> V_27 ;
V_41 = V_21 -> V_41 ;
V_72 = V_21 -> V_73 ;
if ( F_56 ( V_21 -> V_87 ) )
return F_54 ( V_19 , V_21 ) ;
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
return - V_83 ;
if ( V_70 -> V_78 & V_79 ) {
int V_73 = V_72 -> V_80 [ V_70 -> V_28 ] - V_68 ;
if ( V_73 < ( - V_81 - 1 ) || V_73 > V_81 )
return - V_83 ;
}
}
for ( V_70 = V_27 ; V_70 < V_27 + V_41 ; V_70 ++ ) {
V_25 = V_19 -> V_26 + V_70 -> V_28 ;
V_68 = V_70 -> V_68 ;
V_67 = V_25 -> V_74 ;
if ( V_70 -> V_78 & V_79 ) {
int V_73 = V_72 -> V_80 [ V_70 -> V_28 ] - V_68 ;
V_72 -> V_80 [ V_70 -> V_28 ] = V_73 ;
}
V_25 -> V_74 += V_68 ;
V_25 -> V_82 = V_21 -> V_69 ;
}
return 0 ;
V_75:
V_21 -> V_84 = V_70 ;
return V_70 -> V_78 & V_85 ? - V_86 : 1 ;
}
static inline void F_57 ( struct V_20 * V_21 , int error ,
struct V_88 * V_89 )
{
F_58 ( V_89 , V_21 -> V_90 ) ;
F_59 ( V_21 -> V_91 , error ) ;
}
static void F_60 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_61 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_41 > 1 )
V_19 -> V_23 -- ;
}
static inline int F_62 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_63 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_41 > 1 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_18 * V_19 , int V_92 ,
struct V_88 * V_89 )
{
struct V_20 * V_21 , * V_93 ;
struct V_94 * V_95 ;
int V_96 = 0 ;
if ( V_92 == - 1 )
V_95 = & V_19 -> V_64 ;
else
V_95 = & V_19 -> V_26 [ V_92 ] . V_64 ;
F_10 (q, tmp, pending_list, list) {
int error = F_55 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_60 ( V_19 , V_21 ) ;
F_57 ( V_21 , error , V_89 ) ;
if ( error == 0 )
V_96 = 1 ;
}
return V_96 ;
}
static int F_65 ( struct V_18 * V_19 , struct V_40 * V_27 ,
int V_41 , struct V_88 * V_89 )
{
int V_31 ;
int V_96 = 0 ;
int V_97 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
int V_98 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_98 ] . V_74 == 0 ) {
V_97 = 1 ;
V_96 |= F_64 ( V_19 , V_98 , V_89 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_74 == 0 ) {
V_97 = 1 ;
V_96 |= F_64 ( V_19 , V_31 , V_89 ) ;
}
}
}
if ( V_97 )
V_96 |= F_64 ( V_19 , - 1 , V_89 ) ;
return V_96 ;
}
static int F_66 ( struct V_18 * V_19 , int V_92 , struct V_88 * V_89 )
{
struct V_20 * V_21 , * V_93 ;
struct V_94 * V_95 ;
int V_96 = 0 ;
if ( V_92 == - 1 )
V_95 = & V_19 -> V_30 ;
else
V_95 = & V_19 -> V_26 [ V_92 ] . V_30 ;
V_99:
F_10 (q, tmp, pending_list, list) {
int error , V_100 ;
if ( V_92 != - 1 && V_19 -> V_26 [ V_92 ] . V_74 == 0 )
break;
error = F_55 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_60 ( V_19 , V_21 ) ;
if ( error ) {
V_100 = 0 ;
} else {
V_96 = 1 ;
F_65 ( V_19 , V_21 -> V_27 , V_21 -> V_41 , V_89 ) ;
V_100 = F_62 ( V_19 , V_21 ) ;
}
F_57 ( V_21 , error , V_89 ) ;
if ( V_100 )
goto V_99;
}
return V_96 ;
}
static void F_67 ( struct V_18 * V_19 , struct V_40 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_101 = F_48 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_101 =
F_48 () ;
}
}
static void F_68 ( struct V_18 * V_19 , struct V_40 * V_27 , int V_41 ,
int V_102 , struct V_88 * V_89 )
{
int V_31 ;
V_102 |= F_65 ( V_19 , V_27 , V_41 , V_89 ) ;
if ( ! F_63 ( & V_19 -> V_30 ) ) {
V_102 |= F_66 ( V_19 , - 1 , V_89 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_102 |= F_66 ( V_19 , V_31 , V_89 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_68 > 0 ) {
V_102 |= F_66 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_89 ) ;
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
struct V_40 * V_70 = V_21 -> V_84 ;
F_70 ( L_3
L_4 ,
V_104 -> V_105 , F_71 ( V_104 ) ) ;
if ( V_70 -> V_28 != V_92 )
return 0 ;
if ( V_103 && V_70 -> V_68 == 0 )
return 1 ;
if ( ! V_103 && V_70 -> V_68 < 0 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_18 * V_19 , T_3 V_92 ,
bool V_103 )
{
struct V_94 * V_106 ;
struct V_20 * V_21 ;
int V_107 ;
V_107 = 0 ;
if ( V_103 )
V_106 = & V_19 -> V_26 [ V_92 ] . V_64 ;
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
static void V_14 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_71 * V_72 , * V_108 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
int V_31 ;
F_74 ( V_89 ) ;
F_75 ( & V_19 -> V_42 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_61 ( & V_72 -> V_65 ) ;
F_28 ( & V_72 -> V_109 -> V_39 ) ;
V_72 -> V_110 = - 1 ;
F_76 ( & V_72 -> V_111 ) ;
F_31 ( & V_72 -> V_109 -> V_39 ) ;
F_77 ( V_72 , V_37 ) ;
}
F_10 (q, tq, &sma->pending_const, list) {
F_60 ( V_19 , V_21 ) ;
F_57 ( V_21 , - V_112 , & V_89 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_60 ( V_19 , V_21 ) ;
F_57 ( V_21 , - V_112 , & V_89 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_60 ( V_19 , V_21 ) ;
F_57 ( V_21 , - V_112 , & V_89 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_60 ( V_19 , V_21 ) ;
F_57 ( V_21 , - V_112 , & V_89 ) ;
}
}
F_42 ( V_2 , V_19 ) ;
F_33 ( V_19 , - 1 ) ;
F_50 () ;
F_78 ( & V_89 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_41 ( V_19 , F_15 ) ;
}
static unsigned long F_79 ( void T_4 * V_113 , struct V_114 * V_115 , int V_116 )
{
switch ( V_116 ) {
case V_117 :
return F_80 ( V_113 , V_115 , sizeof( * V_115 ) ) ;
case V_118 :
{
struct V_119 V_120 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
F_81 ( & V_115 -> V_42 , & V_120 . V_42 ) ;
V_120 . V_101 = V_115 -> V_101 ;
V_120 . V_66 = V_115 -> V_66 ;
V_120 . V_32 = V_115 -> V_32 ;
return F_80 ( V_113 , & V_120 , sizeof( V_120 ) ) ;
}
default:
return - V_58 ;
}
}
static T_5 F_82 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_121 ;
V_121 = V_19 -> V_26 [ 0 ] . V_101 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_122 = V_19 -> V_26 [ V_31 ] . V_101 ;
if ( V_122 > V_121 )
V_121 = V_122 ;
}
return V_121 ;
}
static int F_83 ( struct V_1 * V_2 , int V_110 ,
int V_123 , int V_116 , void T_4 * V_36 )
{
int V_124 ;
struct V_18 * V_19 ;
switch ( V_123 ) {
case V_125 :
case V_126 :
{
struct V_127 V_127 ;
int V_128 ;
V_124 = F_84 ( NULL , V_123 ) ;
if ( V_124 )
return V_124 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_129 = V_2 -> V_9 ;
V_127 . V_130 = V_2 -> V_5 ;
V_127 . V_131 = V_2 -> V_3 ;
V_127 . V_132 = V_2 -> V_7 ;
V_127 . V_133 = V_76 ;
V_127 . V_134 = V_135 ;
V_127 . V_136 = V_137 ;
V_127 . V_138 = V_139 ;
F_85 ( & F_5 ( V_2 ) . V_140 ) ;
if ( V_123 == V_126 ) {
V_127 . V_141 = F_5 ( V_2 ) . V_142 ;
V_127 . V_143 = V_2 -> V_11 ;
} else {
V_127 . V_141 = V_144 ;
V_127 . V_143 = V_81 ;
}
V_128 = F_86 ( & F_5 ( V_2 ) ) ;
F_87 ( & F_5 ( V_2 ) . V_140 ) ;
if ( F_80 ( V_36 , & V_127 , sizeof( struct V_127 ) ) )
return - V_145 ;
return ( V_128 < 0 ) ? 0 : V_128 ;
}
case V_146 :
case V_147 :
{
struct V_114 V_148 ;
int V_45 = 0 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_88 () ;
if ( V_123 == V_147 ) {
V_19 = F_34 ( V_2 , V_110 ) ;
if ( F_36 ( V_19 ) ) {
V_124 = F_89 ( V_19 ) ;
goto V_149;
}
V_45 = V_19 -> V_42 . V_45 ;
} else {
V_19 = F_38 ( V_2 , V_110 ) ;
if ( F_36 ( V_19 ) ) {
V_124 = F_89 ( V_19 ) ;
goto V_149;
}
}
V_124 = - V_150 ;
if ( F_90 ( V_2 , & V_19 -> V_42 , V_151 ) )
goto V_149;
V_124 = F_84 ( V_19 , V_123 ) ;
if ( V_124 )
goto V_149;
F_91 ( & V_19 -> V_42 , & V_148 . V_42 ) ;
V_148 . V_101 = F_82 ( V_19 ) ;
V_148 . V_66 = V_19 -> V_66 ;
V_148 . V_32 = V_19 -> V_32 ;
F_50 () ;
if ( F_79 ( V_36 , & V_148 , V_116 ) )
return - V_145 ;
return V_45 ;
}
default:
return - V_58 ;
}
V_149:
F_50 () ;
return V_124 ;
}
static int F_92 ( struct V_1 * V_2 , int V_110 , int V_92 ,
unsigned long V_152 )
{
struct V_71 * V_72 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_124 , V_153 ;
F_74 ( V_89 ) ;
#if F_93 ( V_154 ) && F_93 ( V_155 )
V_153 = V_152 >> 32 ;
#else
V_153 = V_152 ;
#endif
if ( V_153 > V_76 || V_153 < 0 )
return - V_83 ;
F_88 () ;
V_19 = F_38 ( V_2 , V_110 ) ;
if ( F_36 ( V_19 ) ) {
F_50 () ;
return F_89 ( V_19 ) ;
}
if ( V_92 < 0 || V_92 >= V_19 -> V_32 ) {
F_50 () ;
return - V_58 ;
}
if ( F_90 ( V_2 , & V_19 -> V_42 , V_156 ) ) {
F_50 () ;
return - V_150 ;
}
V_124 = F_84 ( V_19 , V_157 ) ;
if ( V_124 ) {
F_50 () ;
return - V_150 ;
}
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
F_33 ( V_19 , - 1 ) ;
F_50 () ;
return - V_112 ;
}
V_25 = & V_19 -> V_26 [ V_92 ] ;
F_75 ( & V_19 -> V_42 ) ;
F_73 (un, &sma->list_id, list_id)
V_72 -> V_80 [ V_92 ] = 0 ;
V_25 -> V_74 = V_153 ;
V_25 -> V_82 = F_95 ( V_104 ) ;
V_19 -> V_66 = F_48 () ;
F_68 ( V_19 , NULL , 0 , 0 , & V_89 ) ;
F_33 ( V_19 , - 1 ) ;
F_50 () ;
F_78 ( & V_89 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , int V_110 , int V_92 ,
int V_123 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_124 , V_54 ;
T_3 V_158 [ V_159 ] ;
T_3 * V_160 = V_158 ;
F_74 ( V_89 ) ;
F_88 () ;
V_19 = F_38 ( V_2 , V_110 ) ;
if ( F_36 ( V_19 ) ) {
F_50 () ;
return F_89 ( V_19 ) ;
}
V_54 = V_19 -> V_32 ;
V_124 = - V_150 ;
if ( F_90 ( V_2 , & V_19 -> V_42 , V_123 == V_161 ? V_156 : V_151 ) )
goto V_162;
V_124 = F_84 ( V_19 , V_123 ) ;
if ( V_124 )
goto V_162;
V_124 = - V_150 ;
switch ( V_123 ) {
case V_163 :
{
T_3 T_4 * V_164 = V_36 ;
int V_31 ;
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
V_124 = - V_112 ;
goto V_149;
}
if ( V_54 > V_159 ) {
if ( ! F_97 ( V_19 ) ) {
V_124 = - V_112 ;
goto V_149;
}
F_33 ( V_19 , - 1 ) ;
F_50 () ;
V_160 = F_98 ( sizeof( T_3 ) * V_54 ) ;
if ( V_160 == NULL ) {
F_41 ( V_19 , F_15 ) ;
return - V_60 ;
}
F_88 () ;
F_40 ( V_19 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
V_124 = - V_112 ;
goto V_149;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_160 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_74 ;
F_33 ( V_19 , - 1 ) ;
F_50 () ;
V_124 = 0 ;
if ( F_80 ( V_164 , V_160 , V_54 * sizeof( T_3 ) ) )
V_124 = - V_145 ;
goto V_165;
}
case V_161 :
{
int V_31 ;
struct V_71 * V_72 ;
if ( ! F_97 ( V_19 ) ) {
V_124 = - V_112 ;
goto V_162;
}
F_50 () ;
if ( V_54 > V_159 ) {
V_160 = F_98 ( sizeof( T_3 ) * V_54 ) ;
if ( V_160 == NULL ) {
F_41 ( V_19 , F_15 ) ;
return - V_60 ;
}
}
if ( F_99 ( V_160 , V_36 , V_54 * sizeof( T_3 ) ) ) {
F_41 ( V_19 , F_15 ) ;
V_124 = - V_145 ;
goto V_165;
}
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
if ( V_160 [ V_31 ] > V_76 ) {
F_41 ( V_19 , F_15 ) ;
V_124 = - V_83 ;
goto V_165;
}
}
F_88 () ;
F_40 ( V_19 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
V_124 = - V_112 ;
goto V_149;
}
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
V_19 -> V_26 [ V_31 ] . V_74 = V_160 [ V_31 ] ;
V_19 -> V_26 [ V_31 ] . V_82 = F_95 ( V_104 ) ;
}
F_75 ( & V_19 -> V_42 ) ;
F_73 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ )
V_72 -> V_80 [ V_31 ] = 0 ;
}
V_19 -> V_66 = F_48 () ;
F_68 ( V_19 , NULL , 0 , 0 , & V_89 ) ;
V_124 = 0 ;
goto V_149;
}
}
V_124 = - V_58 ;
if ( V_92 < 0 || V_92 >= V_54 )
goto V_162;
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
V_124 = - V_112 ;
goto V_149;
}
V_25 = & V_19 -> V_26 [ V_92 ] ;
switch ( V_123 ) {
case V_166 :
V_124 = V_25 -> V_74 ;
goto V_149;
case V_167 :
V_124 = V_25 -> V_82 ;
goto V_149;
case V_168 :
V_124 = F_72 ( V_19 , V_92 , 0 ) ;
goto V_149;
case V_169 :
V_124 = F_72 ( V_19 , V_92 , 1 ) ;
goto V_149;
}
V_149:
F_33 ( V_19 , - 1 ) ;
V_162:
F_50 () ;
F_78 ( & V_89 ) ;
V_165:
if ( V_160 != V_158 )
F_100 ( V_160 ) ;
return V_124 ;
}
static inline unsigned long
F_101 ( struct V_114 * V_120 , void T_4 * V_113 , int V_116 )
{
switch ( V_116 ) {
case V_117 :
if ( F_99 ( V_120 , V_113 , sizeof( * V_120 ) ) )
return - V_145 ;
return 0 ;
case V_118 :
{
struct V_119 V_170 ;
if ( F_99 ( & V_170 , V_113 , sizeof( V_170 ) ) )
return - V_145 ;
V_120 -> V_42 . V_171 = V_170 . V_42 . V_171 ;
V_120 -> V_42 . V_172 = V_170 . V_42 . V_172 ;
V_120 -> V_42 . V_61 = V_170 . V_42 . V_61 ;
return 0 ;
}
default:
return - V_58 ;
}
}
static int F_102 ( struct V_1 * V_2 , int V_110 ,
int V_123 , int V_116 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
int V_124 ;
struct V_114 V_173 ;
struct V_46 * V_47 ;
if ( V_123 == V_174 ) {
if ( F_101 ( & V_173 , V_36 , V_116 ) )
return - V_145 ;
}
F_103 ( & F_5 ( V_2 ) . V_140 ) ;
F_88 () ;
V_47 = F_104 ( V_2 , & F_5 ( V_2 ) , V_110 , V_123 ,
& V_173 . V_42 , 0 ) ;
if ( F_36 ( V_47 ) ) {
V_124 = F_89 ( V_47 ) ;
goto V_175;
}
V_19 = F_16 ( V_47 , struct V_18 , V_42 ) ;
V_124 = F_84 ( V_19 , V_123 ) ;
if ( V_124 )
goto V_175;
switch ( V_123 ) {
case V_176 :
F_26 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_47 ) ;
goto V_177;
case V_174 :
F_26 ( V_19 , NULL , - 1 ) ;
V_124 = F_105 ( & V_173 . V_42 , V_47 ) ;
if ( V_124 )
goto V_178;
V_19 -> V_66 = F_48 () ;
break;
default:
V_124 = - V_58 ;
goto V_175;
}
V_178:
F_33 ( V_19 , - 1 ) ;
V_175:
F_50 () ;
V_177:
F_106 ( & F_5 ( V_2 ) . V_140 ) ;
return V_124 ;
}
static inline int F_107 ( struct V_179 * * V_180 )
{
struct V_179 * V_181 ;
V_181 = V_104 -> V_182 . V_181 ;
if ( ! V_181 ) {
V_181 = F_108 ( sizeof( * V_181 ) , V_183 ) ;
if ( V_181 == NULL )
return - V_60 ;
F_47 ( & V_181 -> V_39 ) ;
F_109 ( & V_181 -> V_184 , 1 ) ;
F_12 ( & V_181 -> V_111 ) ;
V_104 -> V_182 . V_181 = V_181 ;
}
* V_180 = V_181 ;
return 0 ;
}
static struct V_71 * F_110 ( struct V_179 * V_109 , int V_110 )
{
struct V_71 * V_72 ;
F_111 (un, &ulp->list_proc, list_proc) {
if ( V_72 -> V_110 == V_110 )
return V_72 ;
}
return NULL ;
}
static struct V_71 * F_112 ( struct V_179 * V_109 , int V_110 )
{
struct V_71 * V_72 ;
F_113 ( & V_109 -> V_39 ) ;
V_72 = F_110 ( V_109 , V_110 ) ;
if ( V_72 ) {
F_76 ( & V_72 -> V_111 ) ;
F_114 ( & V_72 -> V_111 , & V_109 -> V_111 ) ;
}
return V_72 ;
}
static struct V_71 * F_115 ( struct V_1 * V_2 , int V_110 )
{
struct V_18 * V_19 ;
struct V_179 * V_109 ;
struct V_71 * V_72 , * V_185 ;
int V_54 , error ;
error = F_107 ( & V_109 ) ;
if ( error )
return F_116 ( error ) ;
F_88 () ;
F_28 ( & V_109 -> V_39 ) ;
V_72 = F_112 ( V_109 , V_110 ) ;
F_31 ( & V_109 -> V_39 ) ;
if ( F_117 ( V_72 != NULL ) )
goto V_120;
V_19 = F_38 ( V_2 , V_110 ) ;
if ( F_36 ( V_19 ) ) {
F_50 () ;
return F_37 ( V_19 ) ;
}
V_54 = V_19 -> V_32 ;
if ( ! F_97 ( V_19 ) ) {
F_50 () ;
V_72 = F_116 ( - V_112 ) ;
goto V_120;
}
F_50 () ;
V_185 = F_108 ( sizeof( struct V_71 ) + sizeof( short ) * V_54 , V_183 ) ;
if ( ! V_185 ) {
F_41 ( V_19 , F_15 ) ;
return F_116 ( - V_60 ) ;
}
F_88 () ;
F_40 ( V_19 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
F_33 ( V_19 , - 1 ) ;
F_50 () ;
F_118 ( V_185 ) ;
V_72 = F_116 ( - V_112 ) ;
goto V_120;
}
F_28 ( & V_109 -> V_39 ) ;
V_72 = F_112 ( V_109 , V_110 ) ;
if ( V_72 ) {
F_118 ( V_185 ) ;
goto V_186;
}
V_185 -> V_80 = ( short * ) & V_185 [ 1 ] ;
V_185 -> V_109 = V_109 ;
V_185 -> V_110 = V_110 ;
F_113 ( & V_109 -> V_39 ) ;
F_114 ( & V_185 -> V_111 , & V_109 -> V_111 ) ;
F_75 ( & V_19 -> V_42 ) ;
F_119 ( & V_185 -> V_65 , & V_19 -> V_65 ) ;
V_72 = V_185 ;
V_186:
F_31 ( & V_109 -> V_39 ) ;
F_33 ( V_19 , - 1 ) ;
V_120:
return V_72 ;
}
int F_120 ( unsigned long V_187 , struct V_188 * V_189 )
{
struct V_179 * V_181 ;
int error ;
if ( V_187 & V_190 ) {
error = F_107 ( & V_181 ) ;
if ( error )
return error ;
F_121 ( & V_181 -> V_184 ) ;
V_189 -> V_182 . V_181 = V_181 ;
} else
V_189 -> V_182 . V_181 = NULL ;
return 0 ;
}
void F_122 ( struct V_188 * V_189 )
{
struct V_179 * V_109 ;
V_109 = V_189 -> V_182 . V_181 ;
if ( ! V_109 )
return;
V_189 -> V_182 . V_181 = NULL ;
if ( ! F_123 ( & V_109 -> V_184 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_71 * V_72 ;
int V_110 , V_31 ;
F_74 ( V_89 ) ;
F_124 () ;
F_88 () ;
V_72 = F_125 ( V_109 -> V_111 . V_191 ,
struct V_71 , V_111 ) ;
if ( & V_72 -> V_111 == & V_109 -> V_111 ) {
F_22 ( & V_109 -> V_39 ) ;
F_50 () ;
break;
}
F_28 ( & V_109 -> V_39 ) ;
V_110 = V_72 -> V_110 ;
F_31 ( & V_109 -> V_39 ) ;
if ( V_110 == - 1 ) {
F_50 () ;
continue;
}
V_19 = F_38 ( V_189 -> V_192 -> V_193 , V_110 ) ;
if ( F_36 ( V_19 ) ) {
F_50 () ;
continue;
}
F_26 ( V_19 , NULL , - 1 ) ;
if ( ! F_94 ( & V_19 -> V_42 ) ) {
F_33 ( V_19 , - 1 ) ;
F_50 () ;
continue;
}
V_72 = F_110 ( V_109 , V_110 ) ;
if ( V_72 == NULL ) {
F_33 ( V_19 , - 1 ) ;
F_50 () ;
continue;
}
F_75 ( & V_19 -> V_42 ) ;
F_61 ( & V_72 -> V_65 ) ;
F_76 ( & V_72 -> V_111 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_194 = & V_19 -> V_26 [ V_31 ] ;
if ( V_72 -> V_80 [ V_31 ] ) {
V_194 -> V_74 += V_72 -> V_80 [ V_31 ] ;
if ( V_194 -> V_74 < 0 )
V_194 -> V_74 = 0 ;
if ( V_194 -> V_74 > V_76 )
V_194 -> V_74 = V_76 ;
V_194 -> V_82 = F_95 ( V_104 ) ;
}
}
F_68 ( V_19 , NULL , 0 , 1 , & V_89 ) ;
F_33 ( V_19 , - 1 ) ;
F_50 () ;
F_78 ( & V_89 ) ;
F_77 ( V_72 , V_37 ) ;
}
F_118 ( V_109 ) ;
}
static int V_17 ( struct V_195 * V_48 , void * V_196 )
{
struct V_197 * V_198 = F_126 ( V_48 ) ;
struct V_18 * V_19 = V_196 ;
T_5 V_101 ;
F_20 ( V_19 ) ;
V_101 = F_82 ( V_19 ) ;
F_127 ( V_48 ,
L_5 ,
V_19 -> V_42 . V_53 ,
V_19 -> V_42 . V_45 ,
V_19 -> V_42 . V_61 ,
V_19 -> V_32 ,
F_128 ( V_198 , V_19 -> V_42 . V_171 ) ,
F_129 ( V_198 , V_19 -> V_42 . V_172 ) ,
F_128 ( V_198 , V_19 -> V_42 . V_199 ) ,
F_129 ( V_198 , V_19 -> V_42 . V_200 ) ,
V_101 ,
V_19 -> V_66 ) ;
F_24 ( V_19 ) ;
return 0 ;
}
