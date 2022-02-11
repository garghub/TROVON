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
F_40 ( V_19 , F_19 ) ;
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
V_43 = F_46 ( & F_5 ( V_2 ) , & V_19 -> V_41 , V_2 -> V_9 ) ;
if ( V_43 < 0 ) {
F_40 ( V_19 , F_15 ) ;
return V_43 ;
}
V_2 -> V_11 += V_53 ;
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_62 ) ;
F_47 ( & V_19 -> V_26 [ V_31 ] . V_38 ) ;
}
V_19 -> V_23 = 0 ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_62 ) ;
F_12 ( & V_19 -> V_63 ) ;
V_19 -> V_32 = V_53 ;
V_19 -> V_64 = F_48 () ;
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
static int F_53 ( struct V_18 * V_19 , struct V_39 * V_27 ,
int V_40 , struct V_65 * V_66 , int V_67 )
{
int V_68 , V_69 ;
struct V_39 * V_70 ;
struct V_24 * V_25 ;
for ( V_70 = V_27 ; V_70 < V_27 + V_40 ; V_70 ++ ) {
V_25 = V_19 -> V_26 + V_70 -> V_28 ;
V_69 = V_70 -> V_69 ;
V_68 = V_25 -> V_71 ;
if ( ! V_69 && V_68 )
goto V_72;
V_68 += V_69 ;
if ( V_68 < 0 )
goto V_72;
if ( V_68 > V_73 )
goto V_74;
if ( V_70 -> V_75 & V_76 ) {
int V_77 = V_66 -> V_78 [ V_70 -> V_28 ] - V_69 ;
if ( V_77 < ( - V_79 - 1 ) || V_77 > V_79 )
goto V_74;
V_66 -> V_78 [ V_70 -> V_28 ] = V_77 ;
}
V_25 -> V_71 = V_68 ;
}
V_70 -- ;
while ( V_70 >= V_27 ) {
V_19 -> V_26 [ V_70 -> V_28 ] . V_80 = V_67 ;
V_70 -- ;
}
return 0 ;
V_74:
V_68 = - V_81 ;
goto V_77;
V_72:
if ( V_70 -> V_75 & V_82 )
V_68 = - V_83 ;
else
V_68 = 1 ;
V_77:
V_70 -- ;
while ( V_70 >= V_27 ) {
V_69 = V_70 -> V_69 ;
V_19 -> V_26 [ V_70 -> V_28 ] . V_71 -= V_69 ;
if ( V_70 -> V_75 & V_76 )
V_66 -> V_78 [ V_70 -> V_28 ] += V_69 ;
V_70 -- ;
}
return V_68 ;
}
static void F_54 ( struct V_84 * V_85 ,
struct V_20 * V_21 , int error )
{
if ( F_55 ( V_85 ) ) {
F_56 () ;
}
V_21 -> V_86 = V_87 ;
V_21 -> V_67 = error ;
F_11 ( & V_21 -> V_29 , V_85 ) ;
}
static void F_57 ( struct V_84 * V_85 )
{
struct V_20 * V_21 , * V_88 ;
int V_89 ;
V_89 = ! F_55 ( V_85 ) ;
F_10 (q, t, pt, list) {
F_58 ( V_21 -> V_90 ) ;
F_59 () ;
V_21 -> V_86 = V_21 -> V_67 ;
}
if ( V_89 )
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
static int F_64 ( struct V_18 * V_19 , int V_91 ,
struct V_84 * V_85 )
{
struct V_20 * V_21 ;
struct V_84 * V_92 ;
struct V_84 * V_93 ;
int V_94 = 0 ;
if ( V_91 == - 1 )
V_93 = & V_19 -> V_62 ;
else
V_93 = & V_19 -> V_26 [ V_91 ] . V_62 ;
V_92 = V_93 -> V_95 ;
while ( V_92 != V_93 ) {
int error ;
V_21 = F_16 ( V_92 , struct V_20 , V_29 ) ;
V_92 = V_92 -> V_95 ;
error = F_53 ( V_19 , V_21 -> V_27 , V_21 -> V_40 ,
V_21 -> V_77 , V_21 -> V_67 ) ;
if ( error <= 0 ) {
F_61 ( V_19 , V_21 ) ;
F_54 ( V_85 , V_21 , error ) ;
if ( error == 0 )
V_94 = 1 ;
}
}
return V_94 ;
}
static int F_65 ( struct V_18 * V_19 , struct V_39 * V_27 ,
int V_40 , struct V_84 * V_85 )
{
int V_31 ;
int V_94 = 0 ;
int V_96 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ ) {
int V_97 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_97 ] . V_71 == 0 ) {
V_96 = 1 ;
V_94 |= F_64 ( V_19 , V_97 , V_85 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_71 == 0 ) {
V_96 = 1 ;
V_94 |= F_64 ( V_19 , V_31 , V_85 ) ;
}
}
}
if ( V_96 )
V_94 |= F_64 ( V_19 , - 1 , V_85 ) ;
return V_94 ;
}
static int F_66 ( struct V_18 * V_19 , int V_91 , struct V_84 * V_85 )
{
struct V_20 * V_21 ;
struct V_84 * V_92 ;
struct V_84 * V_93 ;
int V_94 = 0 ;
if ( V_91 == - 1 )
V_93 = & V_19 -> V_30 ;
else
V_93 = & V_19 -> V_26 [ V_91 ] . V_30 ;
V_98:
V_92 = V_93 -> V_95 ;
while ( V_92 != V_93 ) {
int error , V_99 ;
V_21 = F_16 ( V_92 , struct V_20 , V_29 ) ;
V_92 = V_92 -> V_95 ;
if ( V_91 != - 1 && V_19 -> V_26 [ V_91 ] . V_71 == 0 )
break;
error = F_53 ( V_19 , V_21 -> V_27 , V_21 -> V_40 ,
V_21 -> V_77 , V_21 -> V_67 ) ;
if ( error > 0 )
continue;
F_61 ( V_19 , V_21 ) ;
if ( error ) {
V_99 = 0 ;
} else {
V_94 = 1 ;
F_65 ( V_19 , V_21 -> V_27 , V_21 -> V_40 , V_85 ) ;
V_99 = F_63 ( V_19 , V_21 ) ;
}
F_54 ( V_85 , V_21 , error ) ;
if ( V_99 )
goto V_98;
}
return V_94 ;
}
static void F_67 ( struct V_18 * V_19 , struct V_39 * V_27 )
{
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_100 = F_48 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_100 =
F_48 () ;
}
}
static void F_68 ( struct V_18 * V_19 , struct V_39 * V_27 , int V_40 ,
int V_101 , struct V_84 * V_85 )
{
int V_31 ;
V_101 |= F_65 ( V_19 , V_27 , V_40 , V_85 ) ;
if ( ! F_55 ( & V_19 -> V_30 ) ) {
V_101 |= F_66 ( V_19 , - 1 , V_85 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_101 |= F_66 ( V_19 , V_31 , V_85 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_69 > 0 ) {
V_101 |= F_66 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_85 ) ;
}
}
}
}
if ( V_101 )
F_67 ( V_19 , V_27 ) ;
}
static int F_69 ( struct V_18 * V_19 , T_3 V_91 )
{
int V_102 ;
struct V_20 * V_21 ;
V_102 = 0 ;
F_70 (q, &sma->sem_base[semnum].pending_alter, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
F_71 ( V_27 -> V_28 != V_91 ) ;
if ( ( V_27 -> V_69 < 0 ) && ! ( V_27 -> V_75 & V_82 ) )
V_102 ++ ;
}
F_70 (q, &sma->pending_alter, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
int V_40 = V_21 -> V_40 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ )
if ( V_27 [ V_31 ] . V_28 == V_91
&& ( V_27 [ V_31 ] . V_69 < 0 )
&& ! ( V_27 [ V_31 ] . V_75 & V_82 ) )
V_102 ++ ;
}
return V_102 ;
}
static int F_72 ( struct V_18 * V_19 , T_3 V_91 )
{
int V_103 ;
struct V_20 * V_21 ;
V_103 = 0 ;
F_70 (q, &sma->sem_base[semnum].pending_const, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
F_71 ( V_27 -> V_28 != V_91 ) ;
if ( ( V_27 -> V_69 == 0 ) && ! ( V_27 -> V_75 & V_82 ) )
V_103 ++ ;
}
F_70 (q, &sma->pending_const, list) {
struct V_39 * V_27 = V_21 -> V_27 ;
int V_40 = V_21 -> V_40 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ )
if ( V_27 [ V_31 ] . V_28 == V_91
&& ( V_27 [ V_31 ] . V_69 == 0 )
&& ! ( V_27 [ V_31 ] . V_75 & V_82 ) )
V_103 ++ ;
}
return V_103 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_65 * V_66 , * V_104 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
struct V_84 V_105 ;
int V_31 ;
F_73 ( & V_19 -> V_41 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_62 ( & V_66 -> V_63 ) ;
F_24 ( & V_66 -> V_106 -> V_38 ) ;
V_66 -> V_107 = - 1 ;
F_74 ( & V_66 -> V_108 ) ;
F_27 ( & V_66 -> V_106 -> V_38 ) ;
F_75 ( V_66 , V_37 ) ;
}
F_12 ( & V_105 ) ;
F_10 (q, tq, &sma->pending_const, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_105 , V_21 , - V_109 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_105 , V_21 , - V_109 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_105 , V_21 , - V_109 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_61 ( V_19 , V_21 ) ;
F_54 ( & V_105 , V_21 , - V_109 ) ;
}
}
F_41 ( V_2 , V_19 ) ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_57 ( & V_105 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_40 ( V_19 , F_15 ) ;
}
static unsigned long F_76 ( void T_4 * V_110 , struct V_111 * V_112 , int V_113 )
{
switch ( V_113 ) {
case V_114 :
return F_77 ( V_110 , V_112 , sizeof( * V_112 ) ) ;
case V_115 :
{
struct V_116 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
F_78 ( & V_112 -> V_41 , & V_117 . V_41 ) ;
V_117 . V_100 = V_112 -> V_100 ;
V_117 . V_64 = V_112 -> V_64 ;
V_117 . V_32 = V_112 -> V_32 ;
return F_77 ( V_110 , & V_117 , sizeof( V_117 ) ) ;
}
default:
return - V_46 ;
}
}
static T_5 F_79 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_118 ;
V_118 = V_19 -> V_26 [ 0 ] . V_100 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_119 = V_19 -> V_26 [ V_31 ] . V_100 ;
if ( V_119 > V_118 )
V_118 = V_119 ;
}
return V_118 ;
}
static int F_80 ( struct V_1 * V_2 , int V_107 ,
int V_120 , int V_113 , void T_4 * V_36 )
{
int V_121 ;
struct V_18 * V_19 ;
switch ( V_120 ) {
case V_122 :
case V_123 :
{
struct V_124 V_124 ;
int V_125 ;
V_121 = F_81 ( NULL , V_120 ) ;
if ( V_121 )
return V_121 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_126 = V_2 -> V_9 ;
V_124 . V_127 = V_2 -> V_5 ;
V_124 . V_128 = V_2 -> V_3 ;
V_124 . V_129 = V_2 -> V_7 ;
V_124 . V_130 = V_73 ;
V_124 . V_131 = V_132 ;
V_124 . V_133 = V_134 ;
V_124 . V_135 = V_136 ;
F_82 ( & F_5 ( V_2 ) . V_137 ) ;
if ( V_120 == V_123 ) {
V_124 . V_138 = F_5 ( V_2 ) . V_139 ;
V_124 . V_140 = V_2 -> V_11 ;
} else {
V_124 . V_138 = V_141 ;
V_124 . V_140 = V_79 ;
}
V_125 = F_83 ( & F_5 ( V_2 ) ) ;
F_84 ( & F_5 ( V_2 ) . V_137 ) ;
if ( F_77 ( V_36 , & V_124 , sizeof( struct V_124 ) ) )
return - V_142 ;
return ( V_125 < 0 ) ? 0 : V_125 ;
}
case V_143 :
case V_144 :
{
struct V_111 V_145 ;
int V_43 = 0 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
F_85 () ;
if ( V_120 == V_144 ) {
V_19 = F_36 ( V_2 , V_107 ) ;
if ( F_32 ( V_19 ) ) {
V_121 = F_86 ( V_19 ) ;
goto V_146;
}
V_43 = V_19 -> V_41 . V_43 ;
} else {
V_19 = F_37 ( V_2 , V_107 ) ;
if ( F_32 ( V_19 ) ) {
V_121 = F_86 ( V_19 ) ;
goto V_146;
}
}
V_121 = - V_147 ;
if ( F_87 ( V_2 , & V_19 -> V_41 , V_148 ) )
goto V_146;
V_121 = F_81 ( V_19 , V_120 ) ;
if ( V_121 )
goto V_146;
F_88 ( & V_19 -> V_41 , & V_145 . V_41 ) ;
V_145 . V_100 = F_79 ( V_19 ) ;
V_145 . V_64 = V_19 -> V_64 ;
V_145 . V_32 = V_19 -> V_32 ;
F_49 () ;
if ( F_76 ( V_36 , & V_145 , V_113 ) )
return - V_142 ;
return V_43 ;
}
default:
return - V_46 ;
}
V_146:
F_49 () ;
return V_121 ;
}
static int F_89 ( struct V_1 * V_2 , int V_107 , int V_91 ,
unsigned long V_149 )
{
struct V_65 * V_66 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_121 ;
struct V_84 V_105 ;
int V_150 ;
#if F_90 ( V_151 ) && F_90 ( V_152 )
V_150 = V_149 >> 32 ;
#else
V_150 = V_149 ;
#endif
if ( V_150 > V_73 || V_150 < 0 )
return - V_81 ;
F_12 ( & V_105 ) ;
F_85 () ;
V_19 = F_37 ( V_2 , V_107 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
return F_86 ( V_19 ) ;
}
if ( V_91 < 0 || V_91 >= V_19 -> V_32 ) {
F_49 () ;
return - V_46 ;
}
if ( F_87 ( V_2 , & V_19 -> V_41 , V_153 ) ) {
F_49 () ;
return - V_147 ;
}
V_121 = F_81 ( V_19 , V_154 ) ;
if ( V_121 ) {
F_49 () ;
return - V_147 ;
}
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
return - V_109 ;
}
V_25 = & V_19 -> V_26 [ V_91 ] ;
F_73 ( & V_19 -> V_41 ) ;
F_70 (un, &sma->list_id, list_id)
V_66 -> V_78 [ V_91 ] = 0 ;
V_25 -> V_71 = V_150 ;
V_25 -> V_80 = F_91 ( V_155 ) ;
V_19 -> V_64 = F_48 () ;
F_68 ( V_19 , NULL , 0 , 0 , & V_105 ) ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_57 ( & V_105 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , int V_107 , int V_91 ,
int V_120 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_121 , V_53 ;
T_3 V_156 [ V_157 ] ;
T_3 * V_158 = V_156 ;
struct V_84 V_105 ;
F_12 ( & V_105 ) ;
F_85 () ;
V_19 = F_37 ( V_2 , V_107 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
return F_86 ( V_19 ) ;
}
V_53 = V_19 -> V_32 ;
V_121 = - V_147 ;
if ( F_87 ( V_2 , & V_19 -> V_41 , V_120 == V_159 ? V_153 : V_148 ) )
goto V_160;
V_121 = F_81 ( V_19 , V_120 ) ;
if ( V_121 )
goto V_160;
V_121 = - V_147 ;
switch ( V_120 ) {
case V_161 :
{
T_3 T_4 * V_162 = V_36 ;
int V_31 ;
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_121 = - V_109 ;
goto V_146;
}
if ( V_53 > V_157 ) {
if ( ! F_93 ( V_19 ) ) {
V_121 = - V_109 ;
goto V_146;
}
F_29 ( V_19 , - 1 ) ;
F_49 () ;
V_158 = F_94 ( sizeof( T_3 ) * V_53 ) ;
if ( V_158 == NULL ) {
F_40 ( V_19 , F_19 ) ;
return - V_58 ;
}
F_85 () ;
F_39 ( V_19 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_121 = - V_109 ;
goto V_146;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_158 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_71 ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
V_121 = 0 ;
if ( F_77 ( V_162 , V_158 , V_53 * sizeof( T_3 ) ) )
V_121 = - V_142 ;
goto V_163;
}
case V_159 :
{
int V_31 ;
struct V_65 * V_66 ;
if ( ! F_93 ( V_19 ) ) {
V_121 = - V_109 ;
goto V_160;
}
F_49 () ;
if ( V_53 > V_157 ) {
V_158 = F_94 ( sizeof( T_3 ) * V_53 ) ;
if ( V_158 == NULL ) {
F_40 ( V_19 , F_19 ) ;
return - V_58 ;
}
}
if ( F_95 ( V_158 , V_36 , V_53 * sizeof( T_3 ) ) ) {
F_40 ( V_19 , F_19 ) ;
V_121 = - V_142 ;
goto V_163;
}
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ ) {
if ( V_158 [ V_31 ] > V_73 ) {
F_40 ( V_19 , F_19 ) ;
V_121 = - V_81 ;
goto V_163;
}
}
F_85 () ;
F_39 ( V_19 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_121 = - V_109 ;
goto V_146;
}
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ )
V_19 -> V_26 [ V_31 ] . V_71 = V_158 [ V_31 ] ;
F_73 ( & V_19 -> V_41 ) ;
F_70 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_53 ; V_31 ++ )
V_66 -> V_78 [ V_31 ] = 0 ;
}
V_19 -> V_64 = F_48 () ;
F_68 ( V_19 , NULL , 0 , 0 , & V_105 ) ;
V_121 = 0 ;
goto V_146;
}
}
V_121 = - V_46 ;
if ( V_91 < 0 || V_91 >= V_53 )
goto V_160;
F_22 ( V_19 , NULL , - 1 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
V_121 = - V_109 ;
goto V_146;
}
V_25 = & V_19 -> V_26 [ V_91 ] ;
switch ( V_120 ) {
case V_164 :
V_121 = V_25 -> V_71 ;
goto V_146;
case V_165 :
V_121 = V_25 -> V_80 ;
goto V_146;
case V_166 :
V_121 = F_69 ( V_19 , V_91 ) ;
goto V_146;
case V_167 :
V_121 = F_72 ( V_19 , V_91 ) ;
goto V_146;
}
V_146:
F_29 ( V_19 , - 1 ) ;
V_160:
F_49 () ;
F_57 ( & V_105 ) ;
V_163:
if ( V_158 != V_156 )
F_96 ( V_158 , sizeof( T_3 ) * V_53 ) ;
return V_121 ;
}
static inline unsigned long
F_97 ( struct V_111 * V_117 , void T_4 * V_110 , int V_113 )
{
switch ( V_113 ) {
case V_114 :
if ( F_95 ( V_117 , V_110 , sizeof( * V_117 ) ) )
return - V_142 ;
return 0 ;
case V_115 :
{
struct V_116 V_168 ;
if ( F_95 ( & V_168 , V_110 , sizeof( V_168 ) ) )
return - V_142 ;
V_117 -> V_41 . V_169 = V_168 . V_41 . V_169 ;
V_117 -> V_41 . V_170 = V_168 . V_41 . V_170 ;
V_117 -> V_41 . V_59 = V_168 . V_41 . V_59 ;
return 0 ;
}
default:
return - V_46 ;
}
}
static int F_98 ( struct V_1 * V_2 , int V_107 ,
int V_120 , int V_113 , void T_4 * V_36 )
{
struct V_18 * V_19 ;
int V_121 ;
struct V_111 V_171 ;
struct V_44 * V_45 ;
if ( V_120 == V_172 ) {
if ( F_97 ( & V_171 , V_36 , V_113 ) )
return - V_142 ;
}
F_99 ( & F_5 ( V_2 ) . V_137 ) ;
F_85 () ;
V_45 = F_100 ( V_2 , & F_5 ( V_2 ) , V_107 , V_120 ,
& V_171 . V_41 , 0 ) ;
if ( F_32 ( V_45 ) ) {
V_121 = F_86 ( V_45 ) ;
goto V_173;
}
V_19 = F_16 ( V_45 , struct V_18 , V_41 ) ;
V_121 = F_81 ( V_19 , V_120 ) ;
if ( V_121 )
goto V_173;
switch ( V_120 ) {
case V_174 :
F_22 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_45 ) ;
goto V_175;
case V_172 :
F_22 ( V_19 , NULL , - 1 ) ;
V_121 = F_101 ( & V_171 . V_41 , V_45 ) ;
if ( V_121 )
goto V_176;
V_19 -> V_64 = F_48 () ;
break;
default:
V_121 = - V_46 ;
goto V_173;
}
V_176:
F_29 ( V_19 , - 1 ) ;
V_173:
F_49 () ;
V_175:
F_102 ( & F_5 ( V_2 ) . V_137 ) ;
return V_121 ;
}
static inline int F_103 ( struct V_177 * * V_178 )
{
struct V_177 * V_179 ;
V_179 = V_155 -> V_180 . V_179 ;
if ( ! V_179 ) {
V_179 = F_104 ( sizeof( * V_179 ) , V_181 ) ;
if ( V_179 == NULL )
return - V_58 ;
F_47 ( & V_179 -> V_38 ) ;
F_105 ( & V_179 -> V_182 , 1 ) ;
F_12 ( & V_179 -> V_108 ) ;
V_155 -> V_180 . V_179 = V_179 ;
}
* V_178 = V_179 ;
return 0 ;
}
static struct V_65 * F_106 ( struct V_177 * V_106 , int V_107 )
{
struct V_65 * V_66 ;
F_107 (un, &ulp->list_proc, list_proc) {
if ( V_66 -> V_107 == V_107 )
return V_66 ;
}
return NULL ;
}
static struct V_65 * F_108 ( struct V_177 * V_106 , int V_107 )
{
struct V_65 * V_66 ;
F_109 ( & V_106 -> V_38 ) ;
V_66 = F_106 ( V_106 , V_107 ) ;
if ( V_66 ) {
F_74 ( & V_66 -> V_108 ) ;
F_110 ( & V_66 -> V_108 , & V_106 -> V_108 ) ;
}
return V_66 ;
}
static struct V_65 * F_111 ( struct V_1 * V_2 , int V_107 )
{
struct V_18 * V_19 ;
struct V_177 * V_106 ;
struct V_65 * V_66 , * V_183 ;
int V_53 , error ;
error = F_103 ( & V_106 ) ;
if ( error )
return F_35 ( error ) ;
F_85 () ;
F_24 ( & V_106 -> V_38 ) ;
V_66 = F_108 ( V_106 , V_107 ) ;
F_27 ( & V_106 -> V_38 ) ;
if ( F_112 ( V_66 != NULL ) )
goto V_117;
V_19 = F_37 ( V_2 , V_107 ) ;
if ( F_32 ( V_19 ) ) {
F_49 () ;
return F_33 ( V_19 ) ;
}
V_53 = V_19 -> V_32 ;
if ( ! F_93 ( V_19 ) ) {
F_49 () ;
V_66 = F_35 ( - V_109 ) ;
goto V_117;
}
F_49 () ;
V_183 = F_104 ( sizeof( struct V_65 ) + sizeof( short ) * V_53 , V_181 ) ;
if ( ! V_183 ) {
F_40 ( V_19 , F_19 ) ;
return F_35 ( - V_58 ) ;
}
F_85 () ;
F_39 ( V_19 ) ;
if ( ! F_34 ( & V_19 -> V_41 ) ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_113 ( V_183 ) ;
V_66 = F_35 ( - V_109 ) ;
goto V_117;
}
F_24 ( & V_106 -> V_38 ) ;
V_66 = F_108 ( V_106 , V_107 ) ;
if ( V_66 ) {
F_113 ( V_183 ) ;
goto V_184;
}
V_183 -> V_78 = ( short * ) & V_183 [ 1 ] ;
V_183 -> V_106 = V_106 ;
V_183 -> V_107 = V_107 ;
F_109 ( & V_106 -> V_38 ) ;
F_110 ( & V_183 -> V_108 , & V_106 -> V_108 ) ;
F_73 ( & V_19 -> V_41 ) ;
F_114 ( & V_183 -> V_63 , & V_19 -> V_63 ) ;
V_66 = V_183 ;
V_184:
F_27 ( & V_106 -> V_38 ) ;
F_29 ( V_19 , - 1 ) ;
V_117:
return V_66 ;
}
static int F_115 ( struct V_20 * V_21 )
{
int error ;
error = V_21 -> V_86 ;
while ( F_116 ( error == V_87 ) ) {
F_117 () ;
error = V_21 -> V_86 ;
}
return error ;
}
int F_118 ( unsigned long V_185 , struct V_186 * V_187 )
{
struct V_177 * V_179 ;
int error ;
if ( V_185 & V_188 ) {
error = F_103 ( & V_179 ) ;
if ( error )
return error ;
F_119 ( & V_179 -> V_182 ) ;
V_187 -> V_180 . V_179 = V_179 ;
} else
V_187 -> V_180 . V_179 = NULL ;
return 0 ;
}
void F_120 ( struct V_186 * V_187 )
{
struct V_177 * V_106 ;
V_106 = V_187 -> V_180 . V_179 ;
if ( ! V_106 )
return;
V_187 -> V_180 . V_179 = NULL ;
if ( ! F_121 ( & V_106 -> V_182 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_65 * V_66 ;
struct V_84 V_105 ;
int V_107 , V_31 ;
F_85 () ;
V_66 = F_122 ( V_106 -> V_108 . V_95 ,
struct V_65 , V_108 ) ;
if ( & V_66 -> V_108 == & V_106 -> V_108 )
V_107 = - 1 ;
else
V_107 = V_66 -> V_107 ;
if ( V_107 == - 1 ) {
F_49 () ;
break;
}
V_19 = F_37 ( V_187 -> V_189 -> V_190 , V_66 -> V_107 ) ;
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
V_66 = F_106 ( V_106 , V_107 ) ;
if ( V_66 == NULL ) {
F_29 ( V_19 , - 1 ) ;
F_49 () ;
continue;
}
F_73 ( & V_19 -> V_41 ) ;
F_62 ( & V_66 -> V_63 ) ;
F_24 ( & V_106 -> V_38 ) ;
F_74 ( & V_66 -> V_108 ) ;
F_27 ( & V_106 -> V_38 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_191 = & V_19 -> V_26 [ V_31 ] ;
if ( V_66 -> V_78 [ V_31 ] ) {
V_191 -> V_71 += V_66 -> V_78 [ V_31 ] ;
if ( V_191 -> V_71 < 0 )
V_191 -> V_71 = 0 ;
if ( V_191 -> V_71 > V_73 )
V_191 -> V_71 = V_73 ;
V_191 -> V_80 = F_91 ( V_155 ) ;
}
}
F_12 ( & V_105 ) ;
F_68 ( V_19 , NULL , 0 , 1 , & V_105 ) ;
F_29 ( V_19 , - 1 ) ;
F_49 () ;
F_57 ( & V_105 ) ;
F_75 ( V_66 , V_37 ) ;
}
F_113 ( V_106 ) ;
}
static int V_17 ( struct V_192 * V_47 , void * V_193 )
{
struct V_194 * V_195 = F_123 ( V_47 ) ;
struct V_18 * V_19 = V_193 ;
T_5 V_100 ;
F_20 ( V_19 ) ;
V_100 = F_79 ( V_19 ) ;
return F_124 ( V_47 ,
L_3 ,
V_19 -> V_41 . V_52 ,
V_19 -> V_41 . V_43 ,
V_19 -> V_41 . V_59 ,
V_19 -> V_32 ,
F_125 ( V_195 , V_19 -> V_41 . V_169 ) ,
F_126 ( V_195 , V_19 -> V_41 . V_170 ) ,
F_125 ( V_195 , V_19 -> V_41 . V_196 ) ,
F_126 ( V_195 , V_19 -> V_41 . V_197 ) ,
V_100 ,
V_19 -> V_64 ) ;
}
