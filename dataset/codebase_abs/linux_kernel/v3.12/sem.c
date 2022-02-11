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
if ( ! V_45 -> V_46 )
return F_16 ( V_45 , struct V_18 , V_41 ) ;
F_29 ( V_19 , * V_42 ) ;
return F_34 ( - V_47 ) ;
}
static inline struct V_18 * F_35 ( struct V_1 * V_2 , int V_43 )
{
struct V_44 * V_45 = F_31 ( & F_5 ( V_2 ) , V_43 ) ;
if ( F_32 ( V_45 ) )
return F_33 ( V_45 ) ;
return F_16 ( V_45 , struct V_18 , V_41 ) ;
}
static inline struct V_18 * F_36 ( struct V_1 * V_2 ,
int V_43 )
{
struct V_44 * V_45 = F_37 ( & F_5 ( V_2 ) , V_43 ) ;
if ( F_32 ( V_45 ) )
return F_33 ( V_45 ) ;
return F_16 ( V_45 , struct V_18 , V_41 ) ;
}
static inline void F_38 ( struct V_18 * V_19 )
{
F_22 ( V_19 , NULL , - 1 ) ;
F_39 ( V_19 , F_19 ) ;
}
static inline void F_40 ( struct V_1 * V_2 , struct V_18 * V_48 )
{
F_41 ( & F_5 ( V_2 ) , & V_48 -> V_41 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_43 ;
int V_51 ;
struct V_18 * V_19 ;
int V_52 ;
T_2 V_53 = V_50 -> V_53 ;
int V_54 = V_50 -> V_55 . V_54 ;
int V_56 = V_50 -> V_57 ;
int V_31 ;
if ( ! V_54 )
return - V_47 ;
if ( V_2 -> V_11 + V_54 > V_2 -> V_5 )
return - V_58 ;
V_52 = sizeof ( * V_19 ) + V_54 * sizeof ( struct V_24 ) ;
V_19 = F_43 ( V_52 ) ;
if ( ! V_19 ) {
return - V_59 ;
}
memset ( V_19 , 0 , V_52 ) ;
V_19 -> V_41 . V_60 = ( V_56 & V_61 ) ;
V_19 -> V_41 . V_53 = V_53 ;
V_19 -> V_41 . V_62 = NULL ;
V_51 = F_44 ( V_19 ) ;
if ( V_51 ) {
F_39 ( V_19 , F_19 ) ;
return V_51 ;
}
V_43 = F_45 ( & F_5 ( V_2 ) , & V_19 -> V_41 , V_2 -> V_9 ) ;
if ( V_43 < 0 ) {
F_39 ( V_19 , F_15 ) ;
return V_43 ;
}
V_2 -> V_11 += V_54 ;
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_63 ) ;
F_46 ( & V_19 -> V_26 [ V_31 ] . V_38 ) ;
}
V_19 -> V_23 = 0 ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_63 ) ;
F_12 ( & V_19 -> V_64 ) ;
V_19 -> V_32 = V_54 ;
V_19 -> V_65 = F_47 () ;
F_29 ( V_19 , - 1 ) ;
F_48 () ;
return V_19 -> V_41 . V_43 ;
}
static inline int F_49 ( struct V_44 * V_45 , int V_56 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
return F_50 ( V_19 , V_56 ) ;
}
static inline int F_51 ( struct V_44 * V_45 ,
struct V_49 * V_50 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
if ( V_50 -> V_55 . V_54 > V_19 -> V_32 )
return - V_47 ;
return 0 ;
}
static int F_52 ( struct V_18 * V_19 , struct V_39 * V_27 ,
int V_40 , struct V_66 * V_67 , int V_68 )
{
int V_69 , V_70 ;
struct V_39 * V_71 ;
struct V_24 * V_25 ;
for ( V_71 = V_27 ; V_71 < V_27 + V_40 ; V_71 ++ ) {
V_25 = V_19 -> V_26 + V_71 -> V_28 ;
V_70 = V_71 -> V_70 ;
V_69 = V_25 -> V_72 ;
if ( ! V_70 && V_69 )
goto V_73;
V_69 += V_70 ;
if ( V_69 < 0 )
goto V_73;
if ( V_69 > V_74 )
goto V_75;
if ( V_71 -> V_76 & V_77 ) {
int V_78 = V_67 -> V_79 [ V_71 -> V_28 ] - V_70 ;
if ( V_78 < ( - V_80 - 1 ) || V_78 > V_80 )
goto V_75;
}
V_25 -> V_72 = V_69 ;
}
V_71 -- ;
while ( V_71 >= V_27 ) {
V_19 -> V_26 [ V_71 -> V_28 ] . V_81 = V_68 ;
if ( V_71 -> V_76 & V_77 )
V_67 -> V_79 [ V_71 -> V_28 ] -= V_71 -> V_70 ;
V_71 -- ;
}
return 0 ;
V_75:
V_69 = - V_82 ;
goto V_78;
V_73:
if ( V_71 -> V_76 & V_83 )
V_69 = - V_84 ;
else
V_69 = 1 ;
V_78:
V_71 -- ;
while ( V_71 >= V_27 ) {
V_19 -> V_26 [ V_71 -> V_28 ] . V_72 -= V_71 -> V_70 ;
V_71 -- ;
}
return V_69 ;
}
static void F_53 ( struct V_85 * V_86 ,
struct V_20 * V_21 , int error )
{
if ( F_54 ( V_86 ) ) {
F_55 () ;
}
V_21 -> V_87 = V_88 ;
V_21 -> V_68 = error ;
F_11 ( & V_21 -> V_29 , V_86 ) ;
}
static void F_56 ( struct V_85 * V_86 )
{
struct V_20 * V_21 , * V_89 ;
int V_90 ;
V_90 = ! F_54 ( V_86 ) ;
F_10 (q, t, pt, list) {
F_57 ( V_21 -> V_91 ) ;
F_58 () ;
V_21 -> V_87 = V_21 -> V_68 ;
}
if ( V_90 )
F_59 () ;
}
static void F_60 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_61 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_40 > 1 )
V_19 -> V_23 -- ;
}
static int F_62 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_54 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_40 > 1 )
return 1 ;
return 0 ;
}
static int F_63 ( struct V_18 * V_19 , int V_92 ,
struct V_85 * V_86 )
{
struct V_20 * V_21 ;
struct V_85 * V_93 ;
struct V_85 * V_94 ;
int V_95 = 0 ;
if ( V_92 == - 1 )
V_94 = & V_19 -> V_63 ;
else
V_94 = & V_19 -> V_26 [ V_92 ] . V_63 ;
V_93 = V_94 -> V_96 ;
while ( V_93 != V_94 ) {
int error ;
V_21 = F_16 ( V_93 , struct V_20 , V_29 ) ;
V_93 = V_93 -> V_96 ;
error = F_52 ( V_19 , V_21 -> V_27 , V_21 -> V_40 ,
V_21 -> V_78 , V_21 -> V_68 ) ;
if ( error <= 0 ) {
F_60 ( V_19 , V_21 ) ;
F_53 ( V_86 , V_21 , error ) ;
if ( error == 0 )
V_95 = 1 ;
}
}
return V_95 ;
}
static int F_64 ( struct V_18 * V_19 , struct V_39 * V_27 ,
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
V_95 |= F_63 ( V_19 , V_98 , V_86 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_72 == 0 ) {
V_97 = 1 ;
V_95 |= F_63 ( V_19 , V_31 , V_86 ) ;
}
}
}
if ( V_97 )
V_95 |= F_63 ( V_19 , - 1 , V_86 ) ;
return V_95 ;
}
static int F_65 ( struct V_18 * V_19 , int V_92 , struct V_85 * V_86 )
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
error = F_52 ( V_19 , V_21 -> V_27 , V_21 -> V_40 ,
V_21 -> V_78 , V_21 -> V_68 ) ;
if ( error > 0 )
continue;
F_60 ( V_19 , V_21 ) ;
if ( error ) {
V_100 = 0 ;
} else {
V_95 = 1 ;
F_64 ( V_19 , V_21 -> V_27 , V_21 -> V_40 , V_86 ) ;
V_100 = F_62 ( V_19 , V_21 ) ;
}
F_53 ( V_86 , V_21 , error ) ;
if ( V_100 )
goto V_99;
}
return V_95 ;
}
static void F_66 ( struct V_18 * V_19 , struct V_39 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_101 = F_47 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_101 =
F_47 () ;
}
}
static void F_67 ( struct V_18 * V_19 , struct V_39 * V_27 , int V_40 ,
int V_102 , struct V_85 * V_86 )
{
int V_31 ;
V_102 |= F_64 ( V_19 , V_27 , V_40 , V_86 ) ;
if ( ! F_54 ( & V_19 -> V_30 ) ) {
V_102 |= F_65 ( V_19 , - 1 , V_86 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_102 |= F_65 ( V_19 , V_31 , V_86 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_70 > 0 ) {
V_102 |= F_65 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_86 ) ;
}
}
}
}
if ( V_102 )
F_66 ( V_19 , V_27 ) ;
}
static int F_68 ( struct V_18 * V_19 , T_3 V_92 )
{
int V_103 ;
struct V_20 * V_21 ;
V_103 = 0 ;
F_69 (q, &sma->sem_base[semnum].pending_alter, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
F_70 ( V_27 -> V_28 != V_92 ) ;
if ( ( V_27 -> V_70 < 0 ) && ! ( V_27 -> V_76 & V_83 ) )
V_103 ++ ;
}
F_69 (q, &sma->pending_alter, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
int V_40 = V_21 -> V_40 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ )
if ( V_27 [ V_31 ] . V_28 == V_92
&& ( V_27 [ V_31 ] . V_70 < 0 )
&& ! ( V_27 [ V_31 ] . V_76 & V_83 ) )
V_103 ++ ;
}
return V_103 ;
}
static int F_71 ( struct V_18 * V_19 , T_3 V_92 )
{
int V_104 ;
struct V_20 * V_21 ;
V_104 = 0 ;
F_69 (q, &sma->sem_base[semnum].pending_const, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
F_70 ( V_27 -> V_28 != V_92 ) ;
if ( ( V_27 -> V_70 == 0 ) && ! ( V_27 -> V_76 & V_83 ) )
V_104 ++ ;
}
F_69 (q, &sma->pending_const, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
int V_40 = V_21 -> V_40 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ )
if ( V_27 [ V_31 ] . V_28 == V_92
&& ( V_27 [ V_31 ] . V_70 == 0 )
&& ! ( V_27 [ V_31 ] . V_76 & V_83 ) )
V_104 ++ ;
}
return V_104 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_66 * V_67 , * V_105 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
struct V_85 V_106 ;
int V_31 ;
F_72 ( & V_19 -> V_41 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_61 ( & V_67 -> V_64 ) ;
F_24 ( & V_67 -> V_107 -> V_38 ) ;
V_67 -> V_108 = - 1 ;
F_73 ( & V_67 -> V_109 ) ;
F_27 ( & V_67 -> V_107 -> V_38 ) ;
F_74 ( V_67 , V_37 ) ;
}
F_12 ( & V_106 ) ;
F_10 (q, tq, &sma->pending_const, list) {
F_60 ( V_19 , V_21 ) ;
F_53 ( & V_106 , V_21 , - V_110 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_60 ( V_19 , V_21 ) ;
F_53 ( & V_106 , V_21 , - V_110 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_60 ( V_19 , V_21 ) ;
F_53 ( & V_106 , V_21 , - V_110 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_60 ( V_19 , V_21 ) ;
F_53 ( & V_106 , V_21 , - V_110 ) ;
}
}
F_40 ( V_2 , V_19 ) ;
F_29 ( V_19 , - 1 ) ;
F_48 () ;
F_56 ( & V_106 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_39 ( V_19 , F_15 ) ;
}
static unsigned long F_75 ( void T_4 * V_111 , struct V_112 * V_113 , int V_114 )
{
switch( V_114 ) {
case V_115 :
return F_76 ( V_111 , V_113 , sizeof( * V_113 ) ) ;
case V_116 :
{
struct V_117 V_118 ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
F_77 ( & V_113 -> V_41 , & V_118 . V_41 ) ;
V_118 . V_101 = V_113 -> V_101 ;
V_118 . V_65 = V_113 -> V_65 ;
V_118 . V_32 = V_113 -> V_32 ;
return F_76 ( V_111 , & V_118 , sizeof( V_118 ) ) ;
}
default:
return - V_47 ;
}
}
static T_5 F_78 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_119 ;
V_119 = V_19 -> V_26 [ 0 ] . V_101 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_120 = V_19 -> V_26 [ V_31 ] . V_101 ;
if ( V_120 > V_119 )
V_119 = V_120 ;
}
return V_119 ;
}
static int F_79 ( struct V_1 * V_2 , int V_108 ,
int V_121 , int V_114 , void T_4 * V_36 )
{
int V_122 ;
struct V_18 * V_19 ;
switch( V_121 ) {
case V_123 :
case V_124 :
{
struct V_125 V_125 ;
int V_126 ;
V_122 = F_80 ( NULL , V_121 ) ;
if ( V_122 )
return V_122 ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_127 = V_2 -> V_9 ;
V_125 . V_128 = V_2 -> V_5 ;
V_125 . V_129 = V_2 -> V_3 ;
V_125 . V_130 = V_2 -> V_7 ;
V_125 . V_131 = V_74 ;
V_125 . V_132 = V_133 ;
V_125 . V_134 = V_135 ;
V_125 . V_136 = V_137 ;
F_81 ( & F_5 ( V_2 ) . V_138 ) ;
if ( V_121 == V_124 ) {
V_125 . V_139 = F_5 ( V_2 ) . V_140 ;
V_125 . V_141 = V_2 -> V_11 ;
} else {
V_125 . V_139 = V_142 ;
V_125 . V_141 = V_80 ;
}
V_126 = F_82 ( & F_5 ( V_2 ) ) ;
F_83 ( & F_5 ( V_2 ) . V_138 ) ;
if ( F_76 ( V_36 , & V_125 , sizeof( struct V_125 ) ) )
return - V_143 ;
return ( V_126 < 0 ) ? 0 : V_126 ;
}
case V_144 :
case V_145 :
{
struct V_112 V_146 ;
int V_43 = 0 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
F_84 () ;
if ( V_121 == V_145 ) {
V_19 = F_35 ( V_2 , V_108 ) ;
if ( F_32 ( V_19 ) ) {
V_122 = F_85 ( V_19 ) ;
goto V_147;
}
V_43 = V_19 -> V_41 . V_43 ;
} else {
V_19 = F_36 ( V_2 , V_108 ) ;
if ( F_32 ( V_19 ) ) {
V_122 = F_85 ( V_19 ) ;
goto V_147;
}
}
V_122 = - V_148 ;
if ( F_86 ( V_2 , & V_19 -> V_41 , V_149 ) )
goto V_147;
V_122 = F_80 ( V_19 , V_121 ) ;
if ( V_122 )
goto V_147;
F_87 ( & V_19 -> V_41 , & V_146 . V_41 ) ;
V_146 . V_101 = F_78 ( V_19 ) ;
V_146 . V_65 = V_19 -> V_65 ;
V_146 . V_32 = V_19 -> V_32 ;
F_48 () ;
if ( F_75 ( V_36 , & V_146 , V_114 ) )
return - V_143 ;
return V_43 ;
}
default:
return - V_47 ;
}
V_147:
F_48 () ;
return V_122 ;
}
static int F_88 ( struct V_1 * V_2 , int V_108 , int V_92 ,
unsigned long V_150 )
{
struct V_66 * V_67 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_122 ;
struct V_85 V_106 ;
int V_151 ;
#if F_89 ( V_152 ) && F_89 ( V_153 )
V_151 = V_150 >> 32 ;
#else
V_151 = V_150 ;
#endif
if ( V_151 > V_74 || V_151 < 0 )
return - V_82 ;
F_12 ( & V_106 ) ;
F_84 () ;
V_19 = F_36 ( V_2 , V_108 ) ;
if ( F_32 ( V_19 ) ) {
F_48 () ;
return F_85 ( V_19 ) ;
}
if ( V_92 < 0 || V_92 >= V_19 -> V_32 ) {
F_48 () ;
return - V_47 ;
}
if ( F_86 ( V_2 , & V_19 -> V_41 , V_154 ) ) {
F_48 () ;
return - V_148 ;
}
V_122 = F_80 ( V_19 , V_155 ) ;
if ( V_122 ) {
F_48 () ;
return - V_148 ;
}
F_22 ( V_19 , NULL , - 1 ) ;
if ( V_19 -> V_41 . V_46 ) {
F_29 ( V_19 , - 1 ) ;
F_48 () ;
return - V_110 ;
}
V_25 = & V_19 -> V_26 [ V_92 ] ;
F_72 ( & V_19 -> V_41 ) ;
F_69 (un, &sma->list_id, list_id)
V_67 -> V_79 [ V_92 ] = 0 ;
V_25 -> V_72 = V_151 ;
V_25 -> V_81 = F_90 ( V_156 ) ;
V_19 -> V_65 = F_47 () ;
F_67 ( V_19 , NULL , 0 , 0 , & V_106 ) ;
F_29 ( V_19 , - 1 ) ;
F_48 () ;
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , int V_108 , int V_92 ,
int V_121 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_122 , V_54 ;
T_3 V_157 [ V_158 ] ;
T_3 * V_159 = V_157 ;
struct V_85 V_106 ;
F_12 ( & V_106 ) ;
F_84 () ;
V_19 = F_36 ( V_2 , V_108 ) ;
if ( F_32 ( V_19 ) ) {
F_48 () ;
return F_85 ( V_19 ) ;
}
V_54 = V_19 -> V_32 ;
V_122 = - V_148 ;
if ( F_86 ( V_2 , & V_19 -> V_41 , V_121 == V_160 ? V_154 : V_149 ) )
goto V_161;
V_122 = F_80 ( V_19 , V_121 ) ;
if ( V_122 )
goto V_161;
V_122 = - V_148 ;
switch ( V_121 ) {
case V_162 :
{
T_3 T_4 * V_163 = V_36 ;
int V_31 ;
F_22 ( V_19 , NULL , - 1 ) ;
if ( V_19 -> V_41 . V_46 ) {
V_122 = - V_110 ;
goto V_147;
}
if( V_54 > V_158 ) {
if ( ! F_92 ( V_19 ) ) {
V_122 = - V_110 ;
goto V_147;
}
F_29 ( V_19 , - 1 ) ;
F_48 () ;
V_159 = F_93 ( sizeof( T_3 ) * V_54 ) ;
if( V_159 == NULL ) {
F_39 ( V_19 , F_19 ) ;
return - V_59 ;
}
F_84 () ;
F_38 ( V_19 ) ;
if ( V_19 -> V_41 . V_46 ) {
V_122 = - V_110 ;
goto V_147;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_159 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_72 ;
F_29 ( V_19 , - 1 ) ;
F_48 () ;
V_122 = 0 ;
if( F_76 ( V_163 , V_159 , V_54 * sizeof( T_3 ) ) )
V_122 = - V_143 ;
goto V_164;
}
case V_160 :
{
int V_31 ;
struct V_66 * V_67 ;
if ( ! F_92 ( V_19 ) ) {
V_122 = - V_110 ;
goto V_161;
}
F_48 () ;
if( V_54 > V_158 ) {
V_159 = F_93 ( sizeof( T_3 ) * V_54 ) ;
if( V_159 == NULL ) {
F_39 ( V_19 , F_19 ) ;
return - V_59 ;
}
}
if ( F_94 ( V_159 , V_36 , V_54 * sizeof( T_3 ) ) ) {
F_39 ( V_19 , F_19 ) ;
V_122 = - V_143 ;
goto V_164;
}
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
if ( V_159 [ V_31 ] > V_74 ) {
F_39 ( V_19 , F_19 ) ;
V_122 = - V_82 ;
goto V_164;
}
}
F_84 () ;
F_38 ( V_19 ) ;
if ( V_19 -> V_41 . V_46 ) {
V_122 = - V_110 ;
goto V_147;
}
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ )
V_19 -> V_26 [ V_31 ] . V_72 = V_159 [ V_31 ] ;
F_72 ( & V_19 -> V_41 ) ;
F_69 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ )
V_67 -> V_79 [ V_31 ] = 0 ;
}
V_19 -> V_65 = F_47 () ;
F_67 ( V_19 , NULL , 0 , 0 , & V_106 ) ;
V_122 = 0 ;
goto V_147;
}
}
V_122 = - V_47 ;
if ( V_92 < 0 || V_92 >= V_54 )
goto V_161;
F_22 ( V_19 , NULL , - 1 ) ;
if ( V_19 -> V_41 . V_46 ) {
V_122 = - V_110 ;
goto V_147;
}
V_25 = & V_19 -> V_26 [ V_92 ] ;
switch ( V_121 ) {
case V_165 :
V_122 = V_25 -> V_72 ;
goto V_147;
case V_166 :
V_122 = V_25 -> V_81 ;
goto V_147;
case V_167 :
V_122 = F_68 ( V_19 , V_92 ) ;
goto V_147;
case V_168 :
V_122 = F_71 ( V_19 , V_92 ) ;
goto V_147;
}
V_147:
F_29 ( V_19 , - 1 ) ;
V_161:
F_48 () ;
F_56 ( & V_106 ) ;
V_164:
if( V_159 != V_157 )
F_95 ( V_159 , sizeof( T_3 ) * V_54 ) ;
return V_122 ;
}
static inline unsigned long
F_96 ( struct V_112 * V_118 , void T_4 * V_111 , int V_114 )
{
switch( V_114 ) {
case V_115 :
if ( F_94 ( V_118 , V_111 , sizeof( * V_118 ) ) )
return - V_143 ;
return 0 ;
case V_116 :
{
struct V_117 V_169 ;
if( F_94 ( & V_169 , V_111 , sizeof( V_169 ) ) )
return - V_143 ;
V_118 -> V_41 . V_170 = V_169 . V_41 . V_170 ;
V_118 -> V_41 . V_171 = V_169 . V_41 . V_171 ;
V_118 -> V_41 . V_60 = V_169 . V_41 . V_60 ;
return 0 ;
}
default:
return - V_47 ;
}
}
static int F_97 ( struct V_1 * V_2 , int V_108 ,
int V_121 , int V_114 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
int V_122 ;
struct V_112 V_172 ;
struct V_44 * V_45 ;
if( V_121 == V_173 ) {
if ( F_96 ( & V_172 , V_36 , V_114 ) )
return - V_143 ;
}
F_98 ( & F_5 ( V_2 ) . V_138 ) ;
F_84 () ;
V_45 = F_99 ( V_2 , & F_5 ( V_2 ) , V_108 , V_121 ,
& V_172 . V_41 , 0 ) ;
if ( F_32 ( V_45 ) ) {
V_122 = F_85 ( V_45 ) ;
goto V_174;
}
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
V_122 = F_80 ( V_19 , V_121 ) ;
if ( V_122 )
goto V_174;
switch ( V_121 ) {
case V_175 :
F_22 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_45 ) ;
goto V_176;
case V_173 :
F_22 ( V_19 , NULL , - 1 ) ;
V_122 = F_100 ( & V_172 . V_41 , V_45 ) ;
if ( V_122 )
goto V_177;
V_19 -> V_65 = F_47 () ;
break;
default:
V_122 = - V_47 ;
goto V_174;
}
V_177:
F_29 ( V_19 , - 1 ) ;
V_174:
F_48 () ;
V_176:
F_101 ( & F_5 ( V_2 ) . V_138 ) ;
return V_122 ;
}
static inline int F_102 ( struct V_178 * * V_179 )
{
struct V_178 * V_180 ;
V_180 = V_156 -> V_181 . V_180 ;
if ( ! V_180 ) {
V_180 = F_103 ( sizeof( * V_180 ) , V_182 ) ;
if ( V_180 == NULL )
return - V_59 ;
F_46 ( & V_180 -> V_38 ) ;
F_104 ( & V_180 -> V_183 , 1 ) ;
F_12 ( & V_180 -> V_109 ) ;
V_156 -> V_181 . V_180 = V_180 ;
}
* V_179 = V_180 ;
return 0 ;
}
static struct V_66 * F_105 ( struct V_178 * V_107 , int V_108 )
{
struct V_66 * V_67 ;
F_106 (un, &ulp->list_proc, list_proc) {
if ( V_67 -> V_108 == V_108 )
return V_67 ;
}
return NULL ;
}
static struct V_66 * F_107 ( struct V_178 * V_107 , int V_108 )
{
struct V_66 * V_67 ;
F_108 ( & V_107 -> V_38 ) ;
V_67 = F_105 ( V_107 , V_108 ) ;
if ( V_67 ) {
F_73 ( & V_67 -> V_109 ) ;
F_109 ( & V_67 -> V_109 , & V_107 -> V_109 ) ;
}
return V_67 ;
}
static struct V_66 * F_110 ( struct V_1 * V_2 , int V_108 )
{
struct V_18 * V_19 ;
struct V_178 * V_107 ;
struct V_66 * V_67 , * V_184 ;
int V_54 , error ;
error = F_102 ( & V_107 ) ;
if ( error )
return F_34 ( error ) ;
F_84 () ;
F_24 ( & V_107 -> V_38 ) ;
V_67 = F_107 ( V_107 , V_108 ) ;
F_27 ( & V_107 -> V_38 ) ;
if ( F_111 ( V_67 != NULL ) )
goto V_118;
V_19 = F_36 ( V_2 , V_108 ) ;
if ( F_32 ( V_19 ) ) {
F_48 () ;
return F_33 ( V_19 ) ;
}
V_54 = V_19 -> V_32 ;
if ( ! F_92 ( V_19 ) ) {
F_48 () ;
V_67 = F_34 ( - V_110 ) ;
goto V_118;
}
F_48 () ;
V_184 = F_103 ( sizeof( struct V_66 ) + sizeof( short ) * V_54 , V_182 ) ;
if ( ! V_184 ) {
F_39 ( V_19 , F_19 ) ;
return F_34 ( - V_59 ) ;
}
F_84 () ;
F_38 ( V_19 ) ;
if ( V_19 -> V_41 . V_46 ) {
F_29 ( V_19 , - 1 ) ;
F_48 () ;
F_112 ( V_184 ) ;
V_67 = F_34 ( - V_110 ) ;
goto V_118;
}
F_24 ( & V_107 -> V_38 ) ;
V_67 = F_107 ( V_107 , V_108 ) ;
if ( V_67 ) {
F_112 ( V_184 ) ;
goto V_185;
}
V_184 -> V_79 = ( short * ) & V_184 [ 1 ] ;
V_184 -> V_107 = V_107 ;
V_184 -> V_108 = V_108 ;
F_108 ( & V_107 -> V_38 ) ;
F_109 ( & V_184 -> V_109 , & V_107 -> V_109 ) ;
F_72 ( & V_19 -> V_41 ) ;
F_113 ( & V_184 -> V_64 , & V_19 -> V_64 ) ;
V_67 = V_184 ;
V_185:
F_27 ( & V_107 -> V_38 ) ;
F_29 ( V_19 , - 1 ) ;
V_118:
return V_67 ;
}
static int F_114 ( struct V_20 * V_21 )
{
int error ;
error = V_21 -> V_87 ;
while ( F_115 ( error == V_88 ) ) {
F_116 () ;
error = V_21 -> V_87 ;
}
return error ;
}
int F_117 ( unsigned long V_186 , struct V_187 * V_188 )
{
struct V_178 * V_180 ;
int error ;
if ( V_186 & V_189 ) {
error = F_102 ( & V_180 ) ;
if ( error )
return error ;
F_118 ( & V_180 -> V_183 ) ;
V_188 -> V_181 . V_180 = V_180 ;
} else
V_188 -> V_181 . V_180 = NULL ;
return 0 ;
}
void F_119 ( struct V_187 * V_188 )
{
struct V_178 * V_107 ;
V_107 = V_188 -> V_181 . V_180 ;
if ( ! V_107 )
return;
V_188 -> V_181 . V_180 = NULL ;
if ( ! F_120 ( & V_107 -> V_183 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_66 * V_67 ;
struct V_85 V_106 ;
int V_108 , V_31 ;
F_84 () ;
V_67 = F_121 ( V_107 -> V_109 . V_96 ,
struct V_66 , V_109 ) ;
if ( & V_67 -> V_109 == & V_107 -> V_109 )
V_108 = - 1 ;
else
V_108 = V_67 -> V_108 ;
if ( V_108 == - 1 ) {
F_48 () ;
break;
}
V_19 = F_36 ( V_188 -> V_190 -> V_191 , V_67 -> V_108 ) ;
if ( F_32 ( V_19 ) ) {
F_48 () ;
continue;
}
F_22 ( V_19 , NULL , - 1 ) ;
if ( V_19 -> V_41 . V_46 ) {
F_29 ( V_19 , - 1 ) ;
F_48 () ;
continue;
}
V_67 = F_105 ( V_107 , V_108 ) ;
if ( V_67 == NULL ) {
F_29 ( V_19 , - 1 ) ;
F_48 () ;
continue;
}
F_72 ( & V_19 -> V_41 ) ;
F_61 ( & V_67 -> V_64 ) ;
F_24 ( & V_107 -> V_38 ) ;
F_73 ( & V_67 -> V_109 ) ;
F_27 ( & V_107 -> V_38 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_192 = & V_19 -> V_26 [ V_31 ] ;
if ( V_67 -> V_79 [ V_31 ] ) {
V_192 -> V_72 += V_67 -> V_79 [ V_31 ] ;
if ( V_192 -> V_72 < 0 )
V_192 -> V_72 = 0 ;
if ( V_192 -> V_72 > V_74 )
V_192 -> V_72 = V_74 ;
V_192 -> V_81 = F_90 ( V_156 ) ;
}
}
F_12 ( & V_106 ) ;
F_67 ( V_19 , NULL , 0 , 1 , & V_106 ) ;
F_29 ( V_19 , - 1 ) ;
F_48 () ;
F_56 ( & V_106 ) ;
F_74 ( V_67 , V_37 ) ;
}
F_112 ( V_107 ) ;
}
static int V_17 ( struct V_193 * V_48 , void * V_194 )
{
struct V_195 * V_196 = F_122 ( V_48 ) ;
struct V_18 * V_19 = V_194 ;
T_5 V_101 ;
F_20 ( V_19 ) ;
V_101 = F_78 ( V_19 ) ;
return F_123 ( V_48 ,
L_3 ,
V_19 -> V_41 . V_53 ,
V_19 -> V_41 . V_43 ,
V_19 -> V_41 . V_60 ,
V_19 -> V_32 ,
F_124 ( V_196 , V_19 -> V_41 . V_170 ) ,
F_125 ( V_196 , V_19 -> V_41 . V_171 ) ,
F_124 ( V_196 , V_19 -> V_41 . V_197 ) ,
F_125 ( V_196 , V_19 -> V_41 . V_198 ) ,
V_101 ,
V_19 -> V_65 ) ;
}
