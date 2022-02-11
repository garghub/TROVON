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
if ( V_19 -> V_38 > 0 ) {
V_19 -> V_38 = V_39 ;
return;
}
V_19 -> V_38 = V_39 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
V_24 = V_19 -> V_26 + V_31 ;
F_21 ( & V_24 -> V_40 ) ;
F_22 ( & V_24 -> V_40 ) ;
}
}
static void F_23 ( struct V_18 * V_19 )
{
if ( V_19 -> V_23 ) {
return;
}
if ( V_19 -> V_38 == 1 ) {
F_24 ( & V_19 -> V_38 , 0 ) ;
} else {
V_19 -> V_38 -- ;
}
}
static inline int F_25 ( struct V_18 * V_19 , struct V_41 * V_27 ,
int V_42 )
{
struct V_24 * V_24 ;
if ( V_42 != 1 ) {
F_26 ( & V_19 -> V_43 ) ;
F_20 ( V_19 ) ;
return V_44 ;
}
V_24 = V_19 -> V_26 + V_27 -> V_28 ;
if ( ! V_19 -> V_38 ) {
F_21 ( & V_24 -> V_40 ) ;
if ( ! F_27 ( & V_19 -> V_38 ) ) {
return V_27 -> V_28 ;
}
F_22 ( & V_24 -> V_40 ) ;
}
F_26 ( & V_19 -> V_43 ) ;
if ( V_19 -> V_38 == 0 ) {
F_21 ( & V_24 -> V_40 ) ;
F_28 ( & V_19 -> V_43 ) ;
return V_27 -> V_28 ;
} else {
return V_44 ;
}
}
static inline void F_29 ( struct V_18 * V_19 , int V_45 )
{
if ( V_45 == V_44 ) {
F_9 ( V_19 ) ;
F_23 ( V_19 ) ;
F_28 ( & V_19 -> V_43 ) ;
} else {
struct V_24 * V_24 = V_19 -> V_26 + V_45 ;
F_22 ( & V_24 -> V_40 ) ;
}
}
static inline struct V_18 * F_30 ( struct V_1 * V_2 , int V_46 )
{
struct V_47 * V_48 = F_31 ( & F_5 ( V_2 ) , V_46 ) ;
if ( F_32 ( V_48 ) )
return F_33 ( V_48 ) ;
return F_16 ( V_48 , struct V_18 , V_43 ) ;
}
static inline struct V_18 * F_34 ( struct V_1 * V_2 ,
int V_46 )
{
struct V_47 * V_48 = F_35 ( & F_5 ( V_2 ) , V_46 ) ;
if ( F_32 ( V_48 ) )
return F_33 ( V_48 ) ;
return F_16 ( V_48 , struct V_18 , V_43 ) ;
}
static inline void F_36 ( struct V_18 * V_19 )
{
F_25 ( V_19 , NULL , - 1 ) ;
F_37 ( V_19 , F_15 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , struct V_18 * V_49 )
{
F_39 ( & F_5 ( V_2 ) , & V_49 -> V_43 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
int V_46 ;
int V_52 ;
struct V_18 * V_19 ;
int V_53 ;
T_2 V_54 = V_51 -> V_54 ;
int V_55 = V_51 -> V_56 . V_55 ;
int V_57 = V_51 -> V_58 ;
int V_31 ;
if ( ! V_55 )
return - V_59 ;
if ( V_2 -> V_11 + V_55 > V_2 -> V_5 )
return - V_60 ;
V_53 = sizeof( * V_19 ) + V_55 * sizeof( struct V_24 ) ;
V_19 = F_41 ( V_53 ) ;
if ( ! V_19 )
return - V_61 ;
memset ( V_19 , 0 , V_53 ) ;
V_19 -> V_43 . V_62 = ( V_57 & V_63 ) ;
V_19 -> V_43 . V_54 = V_54 ;
V_19 -> V_43 . V_64 = NULL ;
V_52 = F_42 ( V_19 ) ;
if ( V_52 ) {
F_37 ( V_19 , F_19 ) ;
return V_52 ;
}
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_65 ) ;
F_43 ( & V_19 -> V_26 [ V_31 ] . V_40 ) ;
}
V_19 -> V_23 = 0 ;
V_19 -> V_38 = V_39 ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_65 ) ;
F_12 ( & V_19 -> V_66 ) ;
V_19 -> V_32 = V_55 ;
V_19 -> V_67 = F_44 () ;
V_46 = F_45 ( & F_5 ( V_2 ) , & V_19 -> V_43 , V_2 -> V_9 ) ;
if ( V_46 < 0 ) {
F_37 ( V_19 , F_15 ) ;
return V_46 ;
}
V_2 -> V_11 += V_55 ;
F_29 ( V_19 , - 1 ) ;
F_46 () ;
return V_19 -> V_43 . V_46 ;
}
static inline int F_47 ( struct V_47 * V_48 , int V_57 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_48 , struct V_18 , V_43 ) ;
return F_48 ( V_19 , V_57 ) ;
}
static inline int F_49 ( struct V_47 * V_48 ,
struct V_50 * V_51 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_48 , struct V_18 , V_43 ) ;
if ( V_51 -> V_56 . V_55 > V_19 -> V_32 )
return - V_59 ;
return 0 ;
}
static int F_50 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_68 , V_69 , V_42 , V_70 ;
struct V_41 * V_71 ;
struct V_24 * V_25 ;
struct V_41 * V_27 ;
struct V_72 * V_73 ;
V_27 = V_21 -> V_27 ;
V_42 = V_21 -> V_42 ;
V_73 = V_21 -> V_74 ;
for ( V_71 = V_27 ; V_71 < V_27 + V_42 ; V_71 ++ ) {
V_25 = V_19 -> V_26 + V_71 -> V_28 ;
V_69 = V_71 -> V_69 ;
V_68 = V_25 -> V_75 ;
if ( ! V_69 && V_68 )
goto V_76;
V_68 += V_69 ;
if ( V_68 < 0 )
goto V_76;
if ( V_68 > V_77 )
goto V_78;
if ( V_71 -> V_79 & V_80 ) {
int V_74 = V_73 -> V_81 [ V_71 -> V_28 ] - V_69 ;
if ( V_74 < ( - V_82 - 1 ) || V_74 > V_82 )
goto V_78;
V_73 -> V_81 [ V_71 -> V_28 ] = V_74 ;
}
V_25 -> V_75 = V_68 ;
}
V_71 -- ;
V_70 = V_21 -> V_70 ;
while ( V_71 >= V_27 ) {
V_19 -> V_26 [ V_71 -> V_28 ] . V_83 = V_70 ;
V_71 -- ;
}
return 0 ;
V_78:
V_68 = - V_84 ;
goto V_74;
V_76:
V_21 -> V_85 = V_71 ;
if ( V_71 -> V_79 & V_86 )
V_68 = - V_87 ;
else
V_68 = 1 ;
V_74:
V_71 -- ;
while ( V_71 >= V_27 ) {
V_69 = V_71 -> V_69 ;
V_19 -> V_26 [ V_71 -> V_28 ] . V_75 -= V_69 ;
if ( V_71 -> V_79 & V_80 )
V_73 -> V_81 [ V_71 -> V_28 ] += V_69 ;
V_71 -- ;
}
return V_68 ;
}
static int F_51 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_68 , V_69 , V_42 ;
struct V_41 * V_71 ;
struct V_24 * V_25 ;
struct V_41 * V_27 ;
struct V_72 * V_73 ;
V_27 = V_21 -> V_27 ;
V_42 = V_21 -> V_42 ;
V_73 = V_21 -> V_74 ;
if ( F_52 ( V_21 -> V_88 ) )
return F_50 ( V_19 , V_21 ) ;
for ( V_71 = V_27 ; V_71 < V_27 + V_42 ; V_71 ++ ) {
V_25 = V_19 -> V_26 + V_71 -> V_28 ;
V_69 = V_71 -> V_69 ;
V_68 = V_25 -> V_75 ;
if ( ! V_69 && V_68 )
goto V_76;
V_68 += V_69 ;
if ( V_68 < 0 )
goto V_76;
if ( V_68 > V_77 )
return - V_84 ;
if ( V_71 -> V_79 & V_80 ) {
int V_74 = V_73 -> V_81 [ V_71 -> V_28 ] - V_69 ;
if ( V_74 < ( - V_82 - 1 ) || V_74 > V_82 )
return - V_84 ;
}
}
for ( V_71 = V_27 ; V_71 < V_27 + V_42 ; V_71 ++ ) {
V_25 = V_19 -> V_26 + V_71 -> V_28 ;
V_69 = V_71 -> V_69 ;
V_68 = V_25 -> V_75 ;
if ( V_71 -> V_79 & V_80 ) {
int V_74 = V_73 -> V_81 [ V_71 -> V_28 ] - V_69 ;
V_73 -> V_81 [ V_71 -> V_28 ] = V_74 ;
}
V_25 -> V_75 += V_69 ;
V_25 -> V_83 = V_21 -> V_70 ;
}
return 0 ;
V_76:
V_21 -> V_85 = V_71 ;
return V_71 -> V_79 & V_86 ? - V_87 : 1 ;
}
static inline void F_53 ( struct V_20 * V_21 , int error ,
struct V_89 * V_90 )
{
F_54 ( V_90 , V_21 -> V_91 ) ;
F_55 ( V_21 -> V_92 , error ) ;
}
static void F_56 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_57 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_42 > 1 )
V_19 -> V_23 -- ;
}
static inline int F_58 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_59 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_42 > 1 )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_18 * V_19 , int V_93 ,
struct V_89 * V_90 )
{
struct V_20 * V_21 , * V_94 ;
struct V_95 * V_96 ;
int V_97 = 0 ;
if ( V_93 == - 1 )
V_96 = & V_19 -> V_65 ;
else
V_96 = & V_19 -> V_26 [ V_93 ] . V_65 ;
F_10 (q, tmp, pending_list, list) {
int error = F_51 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_56 ( V_19 , V_21 ) ;
F_53 ( V_21 , error , V_90 ) ;
if ( error == 0 )
V_97 = 1 ;
}
return V_97 ;
}
static int F_61 ( struct V_18 * V_19 , struct V_41 * V_27 ,
int V_42 , struct V_89 * V_90 )
{
int V_31 ;
int V_97 = 0 ;
int V_98 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_42 ; V_31 ++ ) {
int V_99 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_99 ] . V_75 == 0 ) {
V_98 = 1 ;
V_97 |= F_60 ( V_19 , V_99 , V_90 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_75 == 0 ) {
V_98 = 1 ;
V_97 |= F_60 ( V_19 , V_31 , V_90 ) ;
}
}
}
if ( V_98 )
V_97 |= F_60 ( V_19 , - 1 , V_90 ) ;
return V_97 ;
}
static int F_62 ( struct V_18 * V_19 , int V_93 , struct V_89 * V_90 )
{
struct V_20 * V_21 , * V_94 ;
struct V_95 * V_96 ;
int V_97 = 0 ;
if ( V_93 == - 1 )
V_96 = & V_19 -> V_30 ;
else
V_96 = & V_19 -> V_26 [ V_93 ] . V_30 ;
V_100:
F_10 (q, tmp, pending_list, list) {
int error , V_101 ;
if ( V_93 != - 1 && V_19 -> V_26 [ V_93 ] . V_75 == 0 )
break;
error = F_51 ( V_19 , V_21 ) ;
if ( error > 0 )
continue;
F_56 ( V_19 , V_21 ) ;
if ( error ) {
V_101 = 0 ;
} else {
V_97 = 1 ;
F_61 ( V_19 , V_21 -> V_27 , V_21 -> V_42 , V_90 ) ;
V_101 = F_58 ( V_19 , V_21 ) ;
}
F_53 ( V_21 , error , V_90 ) ;
if ( V_101 )
goto V_100;
}
return V_97 ;
}
static void F_63 ( struct V_18 * V_19 , struct V_41 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_102 = F_44 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_102 =
F_44 () ;
}
}
static void F_64 ( struct V_18 * V_19 , struct V_41 * V_27 , int V_42 ,
int V_103 , struct V_89 * V_90 )
{
int V_31 ;
V_103 |= F_61 ( V_19 , V_27 , V_42 , V_90 ) ;
if ( ! F_59 ( & V_19 -> V_30 ) ) {
V_103 |= F_62 ( V_19 , - 1 , V_90 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_103 |= F_62 ( V_19 , V_31 , V_90 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_42 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_69 > 0 ) {
V_103 |= F_62 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_90 ) ;
}
}
}
}
if ( V_103 )
F_63 ( V_19 , V_27 ) ;
}
static int F_65 ( struct V_18 * V_19 , int V_93 , struct V_20 * V_21 ,
bool V_104 )
{
struct V_41 * V_71 = V_21 -> V_85 ;
F_66 ( L_3
L_4 ,
V_105 -> V_106 , F_67 ( V_105 ) ) ;
if ( V_71 -> V_28 != V_93 )
return 0 ;
if ( V_104 && V_71 -> V_69 == 0 )
return 1 ;
if ( ! V_104 && V_71 -> V_69 < 0 )
return 1 ;
return 0 ;
}
static int F_68 ( struct V_18 * V_19 , T_3 V_93 ,
bool V_104 )
{
struct V_95 * V_107 ;
struct V_20 * V_21 ;
int V_108 ;
V_108 = 0 ;
if ( V_104 )
V_107 = & V_19 -> V_26 [ V_93 ] . V_65 ;
else
V_107 = & V_19 -> V_26 [ V_93 ] . V_30 ;
F_69 (q, l, list) {
V_108 ++ ;
}
F_69 (q, &sma->pending_alter, list) {
V_108 += F_65 ( V_19 , V_93 , V_21 , V_104 ) ;
}
if ( V_104 ) {
F_69 (q, &sma->pending_const, list) {
V_108 += F_65 ( V_19 , V_93 , V_21 , V_104 ) ;
}
}
return V_108 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_72 * V_73 , * V_109 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_48 , struct V_18 , V_43 ) ;
int V_31 ;
F_70 ( V_90 ) ;
F_71 ( & V_19 -> V_43 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_57 ( & V_73 -> V_66 ) ;
F_21 ( & V_73 -> V_110 -> V_40 ) ;
V_73 -> V_111 = - 1 ;
F_72 ( & V_73 -> V_112 ) ;
F_22 ( & V_73 -> V_110 -> V_40 ) ;
F_73 ( V_73 , V_37 ) ;
}
F_10 (q, tq, &sma->pending_const, list) {
F_56 ( V_19 , V_21 ) ;
F_53 ( V_21 , - V_113 , & V_90 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_56 ( V_19 , V_21 ) ;
F_53 ( V_21 , - V_113 , & V_90 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_56 ( V_19 , V_21 ) ;
F_53 ( V_21 , - V_113 , & V_90 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_56 ( V_19 , V_21 ) ;
F_53 ( V_21 , - V_113 , & V_90 ) ;
}
}
F_38 ( V_2 , V_19 ) ;
F_29 ( V_19 , - 1 ) ;
F_46 () ;
F_74 ( & V_90 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_37 ( V_19 , F_15 ) ;
}
static unsigned long F_75 ( void T_4 * V_114 , struct V_115 * V_116 , int V_117 )
{
switch ( V_117 ) {
case V_118 :
return F_76 ( V_114 , V_116 , sizeof( * V_116 ) ) ;
case V_119 :
{
struct V_120 V_121 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_77 ( & V_116 -> V_43 , & V_121 . V_43 ) ;
V_121 . V_102 = V_116 -> V_102 ;
V_121 . V_67 = V_116 -> V_67 ;
V_121 . V_32 = V_116 -> V_32 ;
return F_76 ( V_114 , & V_121 , sizeof( V_121 ) ) ;
}
default:
return - V_59 ;
}
}
static T_5 F_78 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_122 ;
V_122 = V_19 -> V_26 [ 0 ] . V_102 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_123 = V_19 -> V_26 [ V_31 ] . V_102 ;
if ( V_123 > V_122 )
V_122 = V_123 ;
}
return V_122 ;
}
static int F_79 ( struct V_1 * V_2 , int V_111 ,
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
V_125 = F_80 ( NULL , V_124 ) ;
if ( V_125 )
return V_125 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_130 = V_2 -> V_9 ;
V_128 . V_131 = V_2 -> V_5 ;
V_128 . V_132 = V_2 -> V_3 ;
V_128 . V_133 = V_2 -> V_7 ;
V_128 . V_134 = V_77 ;
V_128 . V_135 = V_136 ;
V_128 . V_137 = V_138 ;
V_128 . V_139 = V_140 ;
F_81 ( & F_5 ( V_2 ) . V_141 ) ;
if ( V_124 == V_127 ) {
V_128 . V_142 = F_5 ( V_2 ) . V_143 ;
V_128 . V_144 = V_2 -> V_11 ;
} else {
V_128 . V_142 = V_145 ;
V_128 . V_144 = V_82 ;
}
V_129 = F_82 ( & F_5 ( V_2 ) ) ;
F_83 ( & F_5 ( V_2 ) . V_141 ) ;
if ( F_76 ( V_36 , & V_128 , sizeof( struct V_128 ) ) )
return - V_146 ;
return ( V_129 < 0 ) ? 0 : V_129 ;
}
case V_147 :
case V_148 :
{
struct V_115 V_149 ;
int V_46 = 0 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
F_84 () ;
if ( V_124 == V_148 ) {
V_19 = F_30 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
V_125 = F_85 ( V_19 ) ;
goto V_150;
}
V_46 = V_19 -> V_43 . V_46 ;
} else {
V_19 = F_34 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
V_125 = F_85 ( V_19 ) ;
goto V_150;
}
}
V_125 = - V_151 ;
if ( F_86 ( V_2 , & V_19 -> V_43 , V_152 ) )
goto V_150;
V_125 = F_80 ( V_19 , V_124 ) ;
if ( V_125 )
goto V_150;
F_87 ( & V_19 -> V_43 , & V_149 . V_43 ) ;
V_149 . V_102 = F_78 ( V_19 ) ;
V_149 . V_67 = V_19 -> V_67 ;
V_149 . V_32 = V_19 -> V_32 ;
F_46 () ;
if ( F_75 ( V_36 , & V_149 , V_117 ) )
return - V_146 ;
return V_46 ;
}
default:
return - V_59 ;
}
V_150:
F_46 () ;
return V_125 ;
}
static int F_88 ( struct V_1 * V_2 , int V_111 , int V_93 ,
unsigned long V_153 )
{
struct V_72 * V_73 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_125 , V_154 ;
F_70 ( V_90 ) ;
#if F_89 ( V_155 ) && F_89 ( V_156 )
V_154 = V_153 >> 32 ;
#else
V_154 = V_153 ;
#endif
if ( V_154 > V_77 || V_154 < 0 )
return - V_84 ;
F_84 () ;
V_19 = F_34 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_46 () ;
return F_85 ( V_19 ) ;
}
if ( V_93 < 0 || V_93 >= V_19 -> V_32 ) {
F_46 () ;
return - V_59 ;
}
if ( F_86 ( V_2 , & V_19 -> V_43 , V_157 ) ) {
F_46 () ;
return - V_151 ;
}
V_125 = F_80 ( V_19 , V_158 ) ;
if ( V_125 ) {
F_46 () ;
return - V_151 ;
}
F_25 ( V_19 , NULL , - 1 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
F_29 ( V_19 , - 1 ) ;
F_46 () ;
return - V_113 ;
}
V_25 = & V_19 -> V_26 [ V_93 ] ;
F_71 ( & V_19 -> V_43 ) ;
F_69 (un, &sma->list_id, list_id)
V_73 -> V_81 [ V_93 ] = 0 ;
V_25 -> V_75 = V_154 ;
V_25 -> V_83 = F_91 ( V_105 ) ;
V_19 -> V_67 = F_44 () ;
F_64 ( V_19 , NULL , 0 , 0 , & V_90 ) ;
F_29 ( V_19 , - 1 ) ;
F_46 () ;
F_74 ( & V_90 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , int V_111 , int V_93 ,
int V_124 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_125 , V_55 ;
T_3 V_159 [ V_160 ] ;
T_3 * V_161 = V_159 ;
F_70 ( V_90 ) ;
F_84 () ;
V_19 = F_34 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_46 () ;
return F_85 ( V_19 ) ;
}
V_55 = V_19 -> V_32 ;
V_125 = - V_151 ;
if ( F_86 ( V_2 , & V_19 -> V_43 , V_124 == V_162 ? V_157 : V_152 ) )
goto V_163;
V_125 = F_80 ( V_19 , V_124 ) ;
if ( V_125 )
goto V_163;
V_125 = - V_151 ;
switch ( V_124 ) {
case V_164 :
{
T_3 T_4 * V_165 = V_36 ;
int V_31 ;
F_25 ( V_19 , NULL , - 1 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
V_125 = - V_113 ;
goto V_150;
}
if ( V_55 > V_160 ) {
if ( ! F_93 ( V_19 ) ) {
V_125 = - V_113 ;
goto V_150;
}
F_29 ( V_19 , - 1 ) ;
F_46 () ;
V_161 = F_94 ( sizeof( T_3 ) * V_55 ) ;
if ( V_161 == NULL ) {
F_37 ( V_19 , F_15 ) ;
return - V_61 ;
}
F_84 () ;
F_36 ( V_19 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
V_125 = - V_113 ;
goto V_150;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_161 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_75 ;
F_29 ( V_19 , - 1 ) ;
F_46 () ;
V_125 = 0 ;
if ( F_76 ( V_165 , V_161 , V_55 * sizeof( T_3 ) ) )
V_125 = - V_146 ;
goto V_166;
}
case V_162 :
{
int V_31 ;
struct V_72 * V_73 ;
if ( ! F_93 ( V_19 ) ) {
V_125 = - V_113 ;
goto V_163;
}
F_46 () ;
if ( V_55 > V_160 ) {
V_161 = F_94 ( sizeof( T_3 ) * V_55 ) ;
if ( V_161 == NULL ) {
F_37 ( V_19 , F_15 ) ;
return - V_61 ;
}
}
if ( F_95 ( V_161 , V_36 , V_55 * sizeof( T_3 ) ) ) {
F_37 ( V_19 , F_15 ) ;
V_125 = - V_146 ;
goto V_166;
}
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
if ( V_161 [ V_31 ] > V_77 ) {
F_37 ( V_19 , F_15 ) ;
V_125 = - V_84 ;
goto V_166;
}
}
F_84 () ;
F_36 ( V_19 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
V_125 = - V_113 ;
goto V_150;
}
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
V_19 -> V_26 [ V_31 ] . V_75 = V_161 [ V_31 ] ;
V_19 -> V_26 [ V_31 ] . V_83 = F_91 ( V_105 ) ;
}
F_71 ( & V_19 -> V_43 ) ;
F_69 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ )
V_73 -> V_81 [ V_31 ] = 0 ;
}
V_19 -> V_67 = F_44 () ;
F_64 ( V_19 , NULL , 0 , 0 , & V_90 ) ;
V_125 = 0 ;
goto V_150;
}
}
V_125 = - V_59 ;
if ( V_93 < 0 || V_93 >= V_55 )
goto V_163;
F_25 ( V_19 , NULL , - 1 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
V_125 = - V_113 ;
goto V_150;
}
V_25 = & V_19 -> V_26 [ V_93 ] ;
switch ( V_124 ) {
case V_167 :
V_125 = V_25 -> V_75 ;
goto V_150;
case V_168 :
V_125 = V_25 -> V_83 ;
goto V_150;
case V_169 :
V_125 = F_68 ( V_19 , V_93 , 0 ) ;
goto V_150;
case V_170 :
V_125 = F_68 ( V_19 , V_93 , 1 ) ;
goto V_150;
}
V_150:
F_29 ( V_19 , - 1 ) ;
V_163:
F_46 () ;
F_74 ( & V_90 ) ;
V_166:
if ( V_161 != V_159 )
F_96 ( V_161 ) ;
return V_125 ;
}
static inline unsigned long
F_97 ( struct V_115 * V_121 , void T_4 * V_114 , int V_117 )
{
switch ( V_117 ) {
case V_118 :
if ( F_95 ( V_121 , V_114 , sizeof( * V_121 ) ) )
return - V_146 ;
return 0 ;
case V_119 :
{
struct V_120 V_171 ;
if ( F_95 ( & V_171 , V_114 , sizeof( V_171 ) ) )
return - V_146 ;
V_121 -> V_43 . V_172 = V_171 . V_43 . V_172 ;
V_121 -> V_43 . V_173 = V_171 . V_43 . V_173 ;
V_121 -> V_43 . V_62 = V_171 . V_43 . V_62 ;
return 0 ;
}
default:
return - V_59 ;
}
}
static int F_98 ( struct V_1 * V_2 , int V_111 ,
int V_124 , int V_117 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
int V_125 ;
struct V_115 V_174 ;
struct V_47 * V_48 ;
if ( V_124 == V_175 ) {
if ( F_97 ( & V_174 , V_36 , V_117 ) )
return - V_146 ;
}
F_99 ( & F_5 ( V_2 ) . V_141 ) ;
F_84 () ;
V_48 = F_100 ( V_2 , & F_5 ( V_2 ) , V_111 , V_124 ,
& V_174 . V_43 , 0 ) ;
if ( F_32 ( V_48 ) ) {
V_125 = F_85 ( V_48 ) ;
goto V_176;
}
V_19 = F_16 ( V_48 , struct V_18 , V_43 ) ;
V_125 = F_80 ( V_19 , V_124 ) ;
if ( V_125 )
goto V_176;
switch ( V_124 ) {
case V_177 :
F_25 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_48 ) ;
goto V_178;
case V_175 :
F_25 ( V_19 , NULL , - 1 ) ;
V_125 = F_101 ( & V_174 . V_43 , V_48 ) ;
if ( V_125 )
goto V_179;
V_19 -> V_67 = F_44 () ;
break;
default:
V_125 = - V_59 ;
goto V_176;
}
V_179:
F_29 ( V_19 , - 1 ) ;
V_176:
F_46 () ;
V_178:
F_102 ( & F_5 ( V_2 ) . V_141 ) ;
return V_125 ;
}
static inline int F_103 ( struct V_180 * * V_181 )
{
struct V_180 * V_182 ;
V_182 = V_105 -> V_183 . V_182 ;
if ( ! V_182 ) {
V_182 = F_104 ( sizeof( * V_182 ) , V_184 ) ;
if ( V_182 == NULL )
return - V_61 ;
F_43 ( & V_182 -> V_40 ) ;
F_105 ( & V_182 -> V_185 , 1 ) ;
F_12 ( & V_182 -> V_112 ) ;
V_105 -> V_183 . V_182 = V_182 ;
}
* V_181 = V_182 ;
return 0 ;
}
static struct V_72 * F_106 ( struct V_180 * V_110 , int V_111 )
{
struct V_72 * V_73 ;
F_107 (un, &ulp->list_proc, list_proc) {
if ( V_73 -> V_111 == V_111 )
return V_73 ;
}
return NULL ;
}
static struct V_72 * F_108 ( struct V_180 * V_110 , int V_111 )
{
struct V_72 * V_73 ;
F_109 ( & V_110 -> V_40 ) ;
V_73 = F_106 ( V_110 , V_111 ) ;
if ( V_73 ) {
F_72 ( & V_73 -> V_112 ) ;
F_110 ( & V_73 -> V_112 , & V_110 -> V_112 ) ;
}
return V_73 ;
}
static struct V_72 * F_111 ( struct V_1 * V_2 , int V_111 )
{
struct V_18 * V_19 ;
struct V_180 * V_110 ;
struct V_72 * V_73 , * V_186 ;
int V_55 , error ;
error = F_103 ( & V_110 ) ;
if ( error )
return F_112 ( error ) ;
F_84 () ;
F_21 ( & V_110 -> V_40 ) ;
V_73 = F_108 ( V_110 , V_111 ) ;
F_22 ( & V_110 -> V_40 ) ;
if ( F_113 ( V_73 != NULL ) )
goto V_121;
V_19 = F_34 ( V_2 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_46 () ;
return F_33 ( V_19 ) ;
}
V_55 = V_19 -> V_32 ;
if ( ! F_93 ( V_19 ) ) {
F_46 () ;
V_73 = F_112 ( - V_113 ) ;
goto V_121;
}
F_46 () ;
V_186 = F_104 ( sizeof( struct V_72 ) + sizeof( short ) * V_55 , V_184 ) ;
if ( ! V_186 ) {
F_37 ( V_19 , F_15 ) ;
return F_112 ( - V_61 ) ;
}
F_84 () ;
F_36 ( V_19 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
F_29 ( V_19 , - 1 ) ;
F_46 () ;
F_114 ( V_186 ) ;
V_73 = F_112 ( - V_113 ) ;
goto V_121;
}
F_21 ( & V_110 -> V_40 ) ;
V_73 = F_108 ( V_110 , V_111 ) ;
if ( V_73 ) {
F_114 ( V_186 ) ;
goto V_187;
}
V_186 -> V_81 = ( short * ) & V_186 [ 1 ] ;
V_186 -> V_110 = V_110 ;
V_186 -> V_111 = V_111 ;
F_109 ( & V_110 -> V_40 ) ;
F_110 ( & V_186 -> V_112 , & V_110 -> V_112 ) ;
F_71 ( & V_19 -> V_43 ) ;
F_115 ( & V_186 -> V_66 , & V_19 -> V_66 ) ;
V_73 = V_186 ;
V_187:
F_22 ( & V_110 -> V_40 ) ;
F_29 ( V_19 , - 1 ) ;
V_121:
return V_73 ;
}
int F_116 ( unsigned long V_188 , struct V_189 * V_190 )
{
struct V_180 * V_182 ;
int error ;
if ( V_188 & V_191 ) {
error = F_103 ( & V_182 ) ;
if ( error )
return error ;
F_117 ( & V_182 -> V_185 ) ;
V_190 -> V_183 . V_182 = V_182 ;
} else
V_190 -> V_183 . V_182 = NULL ;
return 0 ;
}
void F_118 ( struct V_189 * V_190 )
{
struct V_180 * V_110 ;
V_110 = V_190 -> V_183 . V_182 ;
if ( ! V_110 )
return;
V_190 -> V_183 . V_182 = NULL ;
if ( ! F_119 ( & V_110 -> V_185 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_72 * V_73 ;
int V_111 , V_31 ;
F_70 ( V_90 ) ;
F_120 () ;
F_84 () ;
V_73 = F_121 ( V_110 -> V_112 . V_192 ,
struct V_72 , V_112 ) ;
if ( & V_73 -> V_112 == & V_110 -> V_112 ) {
F_122 ( & V_110 -> V_40 ) ;
F_46 () ;
break;
}
F_21 ( & V_110 -> V_40 ) ;
V_111 = V_73 -> V_111 ;
F_22 ( & V_110 -> V_40 ) ;
if ( V_111 == - 1 ) {
F_46 () ;
continue;
}
V_19 = F_34 ( V_190 -> V_193 -> V_194 , V_111 ) ;
if ( F_32 ( V_19 ) ) {
F_46 () ;
continue;
}
F_25 ( V_19 , NULL , - 1 ) ;
if ( ! F_90 ( & V_19 -> V_43 ) ) {
F_29 ( V_19 , - 1 ) ;
F_46 () ;
continue;
}
V_73 = F_106 ( V_110 , V_111 ) ;
if ( V_73 == NULL ) {
F_29 ( V_19 , - 1 ) ;
F_46 () ;
continue;
}
F_71 ( & V_19 -> V_43 ) ;
F_57 ( & V_73 -> V_66 ) ;
F_72 ( & V_73 -> V_112 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_195 = & V_19 -> V_26 [ V_31 ] ;
if ( V_73 -> V_81 [ V_31 ] ) {
V_195 -> V_75 += V_73 -> V_81 [ V_31 ] ;
if ( V_195 -> V_75 < 0 )
V_195 -> V_75 = 0 ;
if ( V_195 -> V_75 > V_77 )
V_195 -> V_75 = V_77 ;
V_195 -> V_83 = F_91 ( V_105 ) ;
}
}
F_64 ( V_19 , NULL , 0 , 1 , & V_90 ) ;
F_29 ( V_19 , - 1 ) ;
F_46 () ;
F_74 ( & V_90 ) ;
F_73 ( V_73 , V_37 ) ;
}
F_114 ( V_110 ) ;
}
static int V_17 ( struct V_196 * V_49 , void * V_197 )
{
struct V_198 * V_199 = F_123 ( V_49 ) ;
struct V_18 * V_19 = V_197 ;
T_5 V_102 ;
F_20 ( V_19 ) ;
V_102 = F_78 ( V_19 ) ;
F_124 ( V_49 ,
L_5 ,
V_19 -> V_43 . V_54 ,
V_19 -> V_43 . V_46 ,
V_19 -> V_43 . V_62 ,
V_19 -> V_32 ,
F_125 ( V_199 , V_19 -> V_43 . V_172 ) ,
F_126 ( V_199 , V_19 -> V_43 . V_173 ) ,
F_125 ( V_199 , V_19 -> V_43 . V_200 ) ,
F_126 ( V_199 , V_19 -> V_43 . V_201 ) ,
V_102 ,
V_19 -> V_67 ) ;
F_23 ( V_19 ) ;
return 0 ;
}
