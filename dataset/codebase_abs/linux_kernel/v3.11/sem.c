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
static inline int F_15 ( struct V_18 * V_19 , struct V_33 * V_27 ,
int V_34 )
{
int V_35 ;
V_36:
if ( V_34 == 1 && ! V_19 -> V_23 ) {
struct V_24 * V_24 = V_19 -> V_26 + V_27 -> V_28 ;
F_16 ( & V_24 -> V_37 ) ;
if ( F_17 ( V_19 -> V_23 ) ) {
F_18 ( & V_24 -> V_37 ) ;
goto V_38;
}
if ( F_17 ( F_19 ( & V_19 -> V_39 . V_37 ) ) ) {
F_18 ( & V_24 -> V_37 ) ;
F_20 ( & V_19 -> V_39 . V_37 ) ;
goto V_36;
}
V_35 = V_27 -> V_28 ;
} else {
int V_31 ;
V_38:
F_21 ( & V_19 -> V_39 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_20 ( & V_24 -> V_37 ) ;
}
V_35 = - 1 ;
}
return V_35 ;
}
static inline void F_22 ( struct V_18 * V_19 , int V_35 )
{
if ( V_35 == - 1 ) {
F_9 ( V_19 ) ;
F_23 ( & V_19 -> V_39 ) ;
} else {
struct V_24 * V_24 = V_19 -> V_26 + V_35 ;
F_18 ( & V_24 -> V_37 ) ;
}
}
static inline struct V_18 * F_24 ( struct V_1 * V_2 ,
int V_40 , struct V_33 * V_27 , int V_34 , int * V_35 )
{
struct V_41 * V_42 ;
struct V_18 * V_19 ;
V_42 = F_25 ( & F_5 ( V_2 ) , V_40 ) ;
if ( F_26 ( V_42 ) )
return F_27 ( V_42 ) ;
V_19 = F_28 ( V_42 , struct V_18 , V_39 ) ;
* V_35 = F_15 ( V_19 , V_27 , V_34 ) ;
if ( ! V_42 -> V_43 )
return F_28 ( V_42 , struct V_18 , V_39 ) ;
F_22 ( V_19 , * V_35 ) ;
return F_29 ( - V_44 ) ;
}
static inline struct V_18 * F_30 ( struct V_1 * V_2 , int V_40 )
{
struct V_41 * V_42 = F_25 ( & F_5 ( V_2 ) , V_40 ) ;
if ( F_26 ( V_42 ) )
return F_27 ( V_42 ) ;
return F_28 ( V_42 , struct V_18 , V_39 ) ;
}
static inline struct V_18 * F_31 ( struct V_1 * V_2 ,
int V_40 )
{
struct V_41 * V_42 = F_32 ( & F_5 ( V_2 ) , V_40 ) ;
if ( F_26 ( V_42 ) )
return F_27 ( V_42 ) ;
return F_28 ( V_42 , struct V_18 , V_39 ) ;
}
static inline void F_33 ( struct V_18 * V_19 )
{
F_15 ( V_19 , NULL , - 1 ) ;
F_34 ( V_19 ) ;
}
static inline void F_35 ( struct V_18 * V_19 )
{
F_34 ( V_19 ) ;
}
static inline void F_36 ( struct V_1 * V_2 , struct V_18 * V_45 )
{
F_37 ( & F_5 ( V_2 ) , & V_45 -> V_39 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_40 ;
int V_48 ;
struct V_18 * V_19 ;
int V_49 ;
T_2 V_50 = V_47 -> V_50 ;
int V_51 = V_47 -> V_52 . V_51 ;
int V_53 = V_47 -> V_54 ;
int V_31 ;
if ( ! V_51 )
return - V_44 ;
if ( V_2 -> V_11 + V_51 > V_2 -> V_5 )
return - V_55 ;
V_49 = sizeof ( * V_19 ) + V_51 * sizeof ( struct V_24 ) ;
V_19 = F_39 ( V_49 ) ;
if ( ! V_19 ) {
return - V_56 ;
}
memset ( V_19 , 0 , V_49 ) ;
V_19 -> V_39 . V_57 = ( V_53 & V_58 ) ;
V_19 -> V_39 . V_50 = V_50 ;
V_19 -> V_39 . V_59 = NULL ;
V_48 = F_40 ( V_19 ) ;
if ( V_48 ) {
F_34 ( V_19 ) ;
return V_48 ;
}
V_40 = F_41 ( & F_5 ( V_2 ) , & V_19 -> V_39 , V_2 -> V_9 ) ;
if ( V_40 < 0 ) {
F_42 ( V_19 ) ;
F_34 ( V_19 ) ;
return V_40 ;
}
V_2 -> V_11 += V_51 ;
V_19 -> V_26 = (struct V_24 * ) & V_19 [ 1 ] ;
for ( V_31 = 0 ; V_31 < V_51 ; V_31 ++ ) {
F_12 ( & V_19 -> V_26 [ V_31 ] . V_30 ) ;
F_12 ( & V_19 -> V_26 [ V_31 ] . V_60 ) ;
F_43 ( & V_19 -> V_26 [ V_31 ] . V_37 ) ;
}
V_19 -> V_23 = 0 ;
F_12 ( & V_19 -> V_30 ) ;
F_12 ( & V_19 -> V_60 ) ;
F_12 ( & V_19 -> V_61 ) ;
V_19 -> V_32 = V_51 ;
V_19 -> V_62 = F_44 () ;
F_22 ( V_19 , - 1 ) ;
F_45 () ;
return V_19 -> V_39 . V_40 ;
}
static inline int F_46 ( struct V_41 * V_42 , int V_53 )
{
struct V_18 * V_19 ;
V_19 = F_28 ( V_42 , struct V_18 , V_39 ) ;
return F_47 ( V_19 , V_53 ) ;
}
static inline int F_48 ( struct V_41 * V_42 ,
struct V_46 * V_47 )
{
struct V_18 * V_19 ;
V_19 = F_28 ( V_42 , struct V_18 , V_39 ) ;
if ( V_47 -> V_52 . V_51 > V_19 -> V_32 )
return - V_44 ;
return 0 ;
}
static int F_49 ( struct V_18 * V_19 , struct V_33 * V_27 ,
int V_34 , struct V_63 * V_64 , int V_65 )
{
int V_66 , V_67 ;
struct V_33 * V_68 ;
struct V_24 * V_25 ;
for ( V_68 = V_27 ; V_68 < V_27 + V_34 ; V_68 ++ ) {
V_25 = V_19 -> V_26 + V_68 -> V_28 ;
V_67 = V_68 -> V_67 ;
V_66 = V_25 -> V_69 ;
if ( ! V_67 && V_66 )
goto V_70;
V_66 += V_67 ;
if ( V_66 < 0 )
goto V_70;
if ( V_66 > V_71 )
goto V_72;
if ( V_68 -> V_73 & V_74 ) {
int V_75 = V_64 -> V_76 [ V_68 -> V_28 ] - V_67 ;
if ( V_75 < ( - V_77 - 1 ) || V_75 > V_77 )
goto V_72;
}
V_25 -> V_69 = V_66 ;
}
V_68 -- ;
while ( V_68 >= V_27 ) {
V_19 -> V_26 [ V_68 -> V_28 ] . V_78 = V_65 ;
if ( V_68 -> V_73 & V_74 )
V_64 -> V_76 [ V_68 -> V_28 ] -= V_68 -> V_67 ;
V_68 -- ;
}
return 0 ;
V_72:
V_66 = - V_79 ;
goto V_75;
V_70:
if ( V_68 -> V_73 & V_80 )
V_66 = - V_81 ;
else
V_66 = 1 ;
V_75:
V_68 -- ;
while ( V_68 >= V_27 ) {
V_19 -> V_26 [ V_68 -> V_28 ] . V_69 -= V_68 -> V_67 ;
V_68 -- ;
}
return V_66 ;
}
static void F_50 ( struct V_82 * V_83 ,
struct V_20 * V_21 , int error )
{
if ( F_51 ( V_83 ) ) {
F_52 () ;
}
V_21 -> V_84 = V_85 ;
V_21 -> V_65 = error ;
F_11 ( & V_21 -> V_29 , V_83 ) ;
}
static void F_53 ( struct V_82 * V_83 )
{
struct V_20 * V_21 , * V_86 ;
int V_87 ;
V_87 = ! F_51 ( V_83 ) ;
F_10 (q, t, pt, list) {
F_54 ( V_21 -> V_88 ) ;
F_55 () ;
V_21 -> V_84 = V_21 -> V_65 ;
}
if ( V_87 )
F_56 () ;
}
static void F_57 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
F_58 ( & V_21 -> V_29 ) ;
if ( V_21 -> V_34 > 1 )
V_19 -> V_23 -- ;
}
static int F_59 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
if ( ! F_51 ( & V_19 -> V_30 ) )
return 1 ;
if ( V_21 -> V_34 > 1 )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_18 * V_19 , int V_89 ,
struct V_82 * V_83 )
{
struct V_20 * V_21 ;
struct V_82 * V_90 ;
struct V_82 * V_91 ;
int V_92 = 0 ;
if ( V_89 == - 1 )
V_91 = & V_19 -> V_60 ;
else
V_91 = & V_19 -> V_26 [ V_89 ] . V_60 ;
V_90 = V_91 -> V_93 ;
while ( V_90 != V_91 ) {
int error ;
V_21 = F_28 ( V_90 , struct V_20 , V_29 ) ;
V_90 = V_90 -> V_93 ;
error = F_49 ( V_19 , V_21 -> V_27 , V_21 -> V_34 ,
V_21 -> V_75 , V_21 -> V_65 ) ;
if ( error <= 0 ) {
F_57 ( V_19 , V_21 ) ;
F_50 ( V_83 , V_21 , error ) ;
if ( error == 0 )
V_92 = 1 ;
}
}
return V_92 ;
}
static int F_61 ( struct V_18 * V_19 , struct V_33 * V_27 ,
int V_34 , struct V_82 * V_83 )
{
int V_31 ;
int V_92 = 0 ;
int V_94 = 0 ;
if ( V_27 ) {
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
int V_95 = V_27 [ V_31 ] . V_28 ;
if ( V_19 -> V_26 [ V_95 ] . V_69 == 0 ) {
V_94 = 1 ;
V_92 |= F_60 ( V_19 , V_95 , V_83 ) ;
}
}
} else {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
if ( V_19 -> V_26 [ V_31 ] . V_69 == 0 ) {
V_94 = 1 ;
V_92 |= F_60 ( V_19 , V_31 , V_83 ) ;
}
}
}
if ( V_94 )
V_92 |= F_60 ( V_19 , - 1 , V_83 ) ;
return V_92 ;
}
static int F_62 ( struct V_18 * V_19 , int V_89 , struct V_82 * V_83 )
{
struct V_20 * V_21 ;
struct V_82 * V_90 ;
struct V_82 * V_91 ;
int V_92 = 0 ;
if ( V_89 == - 1 )
V_91 = & V_19 -> V_30 ;
else
V_91 = & V_19 -> V_26 [ V_89 ] . V_30 ;
V_36:
V_90 = V_91 -> V_93 ;
while ( V_90 != V_91 ) {
int error , V_96 ;
V_21 = F_28 ( V_90 , struct V_20 , V_29 ) ;
V_90 = V_90 -> V_93 ;
if ( V_89 != - 1 && V_19 -> V_26 [ V_89 ] . V_69 == 0 )
break;
error = F_49 ( V_19 , V_21 -> V_27 , V_21 -> V_34 ,
V_21 -> V_75 , V_21 -> V_65 ) ;
if ( error > 0 )
continue;
F_57 ( V_19 , V_21 ) ;
if ( error ) {
V_96 = 0 ;
} else {
V_92 = 1 ;
F_61 ( V_19 , V_21 -> V_27 , V_21 -> V_34 , V_83 ) ;
V_96 = F_59 ( V_19 , V_21 ) ;
}
F_50 ( V_83 , V_21 , error ) ;
if ( V_96 )
goto V_36;
}
return V_92 ;
}
static void F_63 ( struct V_18 * V_19 , struct V_33 * V_27 , int V_34 ,
int V_97 , struct V_82 * V_83 )
{
int V_31 ;
V_97 |= F_61 ( V_19 , V_27 , V_34 , V_83 ) ;
if ( ! F_51 ( & V_19 -> V_30 ) ) {
V_97 |= F_62 ( V_19 , - 1 , V_83 ) ;
} else {
if ( ! V_27 ) {
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_97 |= F_62 ( V_19 , V_31 , V_83 ) ;
} else {
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
if ( V_27 [ V_31 ] . V_67 > 0 ) {
V_97 |= F_62 ( V_19 ,
V_27 [ V_31 ] . V_28 , V_83 ) ;
}
}
}
}
if ( V_97 ) {
if ( V_27 == NULL ) {
V_19 -> V_26 [ 0 ] . V_98 = F_44 () ;
} else {
V_19 -> V_26 [ V_27 [ 0 ] . V_28 ] . V_98 =
F_44 () ;
}
}
}
static int F_64 ( struct V_18 * V_19 , T_3 V_89 )
{
int V_99 ;
struct V_20 * V_21 ;
V_99 = 0 ;
F_65 (q, &sma->sem_base[semnum].pending_alter, list) {
struct V_33 * V_27 = V_21 -> V_27 ;
F_66 ( V_27 -> V_28 != V_89 ) ;
if ( ( V_27 -> V_67 < 0 ) && ! ( V_27 -> V_73 & V_80 ) )
V_99 ++ ;
}
F_65 (q, &sma->pending_alter, list) {
struct V_33 * V_27 = V_21 -> V_27 ;
int V_34 = V_21 -> V_34 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ )
if ( V_27 [ V_31 ] . V_28 == V_89
&& ( V_27 [ V_31 ] . V_67 < 0 )
&& ! ( V_27 [ V_31 ] . V_73 & V_80 ) )
V_99 ++ ;
}
return V_99 ;
}
static int F_67 ( struct V_18 * V_19 , T_3 V_89 )
{
int V_100 ;
struct V_20 * V_21 ;
V_100 = 0 ;
F_65 (q, &sma->sem_base[semnum].pending_const, list) {
struct V_33 * V_27 = V_21 -> V_27 ;
F_66 ( V_27 -> V_28 != V_89 ) ;
if ( ( V_27 -> V_67 == 0 ) && ! ( V_27 -> V_73 & V_80 ) )
V_100 ++ ;
}
F_65 (q, &sma->pending_const, list) {
struct V_33 * V_27 = V_21 -> V_27 ;
int V_34 = V_21 -> V_34 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ )
if ( V_27 [ V_31 ] . V_28 == V_89
&& ( V_27 [ V_31 ] . V_67 == 0 )
&& ! ( V_27 [ V_31 ] . V_73 & V_80 ) )
V_100 ++ ;
}
return V_100 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_63 * V_64 , * V_101 ;
struct V_20 * V_21 , * V_22 ;
struct V_18 * V_19 = F_28 ( V_42 , struct V_18 , V_39 ) ;
struct V_82 V_102 ;
int V_31 ;
F_68 ( & V_19 -> V_39 ) ;
F_10 (un, tu, &sma->list_id, list_id) {
F_58 ( & V_64 -> V_61 ) ;
F_16 ( & V_64 -> V_103 -> V_37 ) ;
V_64 -> V_104 = - 1 ;
F_69 ( & V_64 -> V_105 ) ;
F_18 ( & V_64 -> V_103 -> V_37 ) ;
F_70 ( V_64 , V_106 ) ;
}
F_12 ( & V_102 ) ;
F_10 (q, tq, &sma->pending_const, list) {
F_57 ( V_19 , V_21 ) ;
F_50 ( & V_102 , V_21 , - V_107 ) ;
}
F_10 (q, tq, &sma->pending_alter, list) {
F_57 ( V_19 , V_21 ) ;
F_50 ( & V_102 , V_21 , - V_107 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_24 = V_19 -> V_26 + V_31 ;
F_10 (q, tq, &sem->pending_const, list) {
F_57 ( V_19 , V_21 ) ;
F_50 ( & V_102 , V_21 , - V_107 ) ;
}
F_10 (q, tq, &sem->pending_alter, list) {
F_57 ( V_19 , V_21 ) ;
F_50 ( & V_102 , V_21 , - V_107 ) ;
}
}
F_36 ( V_2 , V_19 ) ;
F_22 ( V_19 , - 1 ) ;
F_45 () ;
F_53 ( & V_102 ) ;
V_2 -> V_11 -= V_19 -> V_32 ;
F_42 ( V_19 ) ;
F_34 ( V_19 ) ;
}
static unsigned long F_71 ( void T_4 * V_108 , struct V_109 * V_110 , int V_111 )
{
switch( V_111 ) {
case V_112 :
return F_72 ( V_108 , V_110 , sizeof( * V_110 ) ) ;
case V_113 :
{
struct V_114 V_115 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
F_73 ( & V_110 -> V_39 , & V_115 . V_39 ) ;
V_115 . V_98 = V_110 -> V_98 ;
V_115 . V_62 = V_110 -> V_62 ;
V_115 . V_32 = V_110 -> V_32 ;
return F_72 ( V_108 , & V_115 , sizeof( V_115 ) ) ;
}
default:
return - V_44 ;
}
}
static T_5 F_74 ( struct V_18 * V_19 )
{
int V_31 ;
T_5 V_116 ;
V_116 = V_19 -> V_26 [ 0 ] . V_98 ;
for ( V_31 = 1 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
T_5 V_117 = V_19 -> V_26 [ V_31 ] . V_98 ;
if ( V_117 > V_116 )
V_116 = V_117 ;
}
return V_116 ;
}
static int F_75 ( struct V_1 * V_2 , int V_104 ,
int V_118 , int V_111 , void T_4 * V_119 )
{
int V_120 ;
struct V_18 * V_19 ;
switch( V_118 ) {
case V_121 :
case V_122 :
{
struct V_123 V_123 ;
int V_124 ;
V_120 = F_76 ( NULL , V_118 ) ;
if ( V_120 )
return V_120 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_125 = V_2 -> V_9 ;
V_123 . V_126 = V_2 -> V_5 ;
V_123 . V_127 = V_2 -> V_3 ;
V_123 . V_128 = V_2 -> V_7 ;
V_123 . V_129 = V_71 ;
V_123 . V_130 = V_131 ;
V_123 . V_132 = V_133 ;
V_123 . V_134 = V_135 ;
F_77 ( & F_5 ( V_2 ) . V_136 ) ;
if ( V_118 == V_122 ) {
V_123 . V_137 = F_5 ( V_2 ) . V_138 ;
V_123 . V_139 = V_2 -> V_11 ;
} else {
V_123 . V_137 = V_140 ;
V_123 . V_139 = V_77 ;
}
V_124 = F_78 ( & F_5 ( V_2 ) ) ;
F_79 ( & F_5 ( V_2 ) . V_136 ) ;
if ( F_72 ( V_119 , & V_123 , sizeof( struct V_123 ) ) )
return - V_141 ;
return ( V_124 < 0 ) ? 0 : V_124 ;
}
case V_142 :
case V_143 :
{
struct V_109 V_144 ;
int V_40 = 0 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
F_80 () ;
if ( V_118 == V_143 ) {
V_19 = F_30 ( V_2 , V_104 ) ;
if ( F_26 ( V_19 ) ) {
V_120 = F_81 ( V_19 ) ;
goto V_145;
}
V_40 = V_19 -> V_39 . V_40 ;
} else {
V_19 = F_31 ( V_2 , V_104 ) ;
if ( F_26 ( V_19 ) ) {
V_120 = F_81 ( V_19 ) ;
goto V_145;
}
}
V_120 = - V_146 ;
if ( F_82 ( V_2 , & V_19 -> V_39 , V_147 ) )
goto V_145;
V_120 = F_76 ( V_19 , V_118 ) ;
if ( V_120 )
goto V_145;
F_83 ( & V_19 -> V_39 , & V_144 . V_39 ) ;
V_144 . V_98 = F_74 ( V_19 ) ;
V_144 . V_62 = V_19 -> V_62 ;
V_144 . V_32 = V_19 -> V_32 ;
F_45 () ;
if ( F_71 ( V_119 , & V_144 , V_111 ) )
return - V_141 ;
return V_40 ;
}
default:
return - V_44 ;
}
V_145:
F_45 () ;
return V_120 ;
}
static int F_84 ( struct V_1 * V_2 , int V_104 , int V_89 ,
unsigned long V_148 )
{
struct V_63 * V_64 ;
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_120 ;
struct V_82 V_102 ;
int V_149 ;
#if F_85 ( V_150 ) && F_85 ( V_151 )
V_149 = V_148 >> 32 ;
#else
V_149 = V_148 ;
#endif
if ( V_149 > V_71 || V_149 < 0 )
return - V_79 ;
F_12 ( & V_102 ) ;
F_80 () ;
V_19 = F_31 ( V_2 , V_104 ) ;
if ( F_26 ( V_19 ) ) {
F_45 () ;
return F_81 ( V_19 ) ;
}
if ( V_89 < 0 || V_89 >= V_19 -> V_32 ) {
F_45 () ;
return - V_44 ;
}
if ( F_82 ( V_2 , & V_19 -> V_39 , V_152 ) ) {
F_45 () ;
return - V_146 ;
}
V_120 = F_76 ( V_19 , V_153 ) ;
if ( V_120 ) {
F_45 () ;
return - V_146 ;
}
F_15 ( V_19 , NULL , - 1 ) ;
V_25 = & V_19 -> V_26 [ V_89 ] ;
F_68 ( & V_19 -> V_39 ) ;
F_65 (un, &sma->list_id, list_id)
V_64 -> V_76 [ V_89 ] = 0 ;
V_25 -> V_69 = V_149 ;
V_25 -> V_78 = F_86 ( V_154 ) ;
V_19 -> V_62 = F_44 () ;
F_63 ( V_19 , NULL , 0 , 0 , & V_102 ) ;
F_22 ( V_19 , - 1 ) ;
F_45 () ;
F_53 ( & V_102 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , int V_104 , int V_89 ,
int V_118 , void T_4 * V_119 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
int V_120 , V_51 ;
T_3 V_155 [ V_156 ] ;
T_3 * V_157 = V_155 ;
struct V_82 V_102 ;
F_12 ( & V_102 ) ;
F_80 () ;
V_19 = F_31 ( V_2 , V_104 ) ;
if ( F_26 ( V_19 ) ) {
F_45 () ;
return F_81 ( V_19 ) ;
}
V_51 = V_19 -> V_32 ;
V_120 = - V_146 ;
if ( F_82 ( V_2 , & V_19 -> V_39 , V_118 == V_158 ? V_152 : V_147 ) )
goto V_159;
V_120 = F_76 ( V_19 , V_118 ) ;
if ( V_120 )
goto V_159;
V_120 = - V_146 ;
switch ( V_118 ) {
case V_160 :
{
T_3 T_4 * V_161 = V_119 ;
int V_31 ;
F_15 ( V_19 , NULL , - 1 ) ;
if( V_51 > V_156 ) {
if ( ! F_88 ( V_19 ) ) {
F_22 ( V_19 , - 1 ) ;
F_45 () ;
V_120 = - V_107 ;
goto V_162;
}
F_22 ( V_19 , - 1 ) ;
F_45 () ;
V_157 = F_89 ( sizeof( T_3 ) * V_51 ) ;
if( V_157 == NULL ) {
F_35 ( V_19 ) ;
return - V_56 ;
}
F_80 () ;
F_33 ( V_19 ) ;
if ( V_19 -> V_39 . V_43 ) {
F_22 ( V_19 , - 1 ) ;
F_45 () ;
V_120 = - V_107 ;
goto V_162;
}
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
V_157 [ V_31 ] = V_19 -> V_26 [ V_31 ] . V_69 ;
F_22 ( V_19 , - 1 ) ;
F_45 () ;
V_120 = 0 ;
if( F_72 ( V_161 , V_157 , V_51 * sizeof( T_3 ) ) )
V_120 = - V_141 ;
goto V_162;
}
case V_158 :
{
int V_31 ;
struct V_63 * V_64 ;
if ( ! F_88 ( V_19 ) ) {
F_45 () ;
return - V_107 ;
}
F_45 () ;
if( V_51 > V_156 ) {
V_157 = F_89 ( sizeof( T_3 ) * V_51 ) ;
if( V_157 == NULL ) {
F_35 ( V_19 ) ;
return - V_56 ;
}
}
if ( F_90 ( V_157 , V_119 , V_51 * sizeof( T_3 ) ) ) {
F_35 ( V_19 ) ;
V_120 = - V_141 ;
goto V_162;
}
for ( V_31 = 0 ; V_31 < V_51 ; V_31 ++ ) {
if ( V_157 [ V_31 ] > V_71 ) {
F_35 ( V_19 ) ;
V_120 = - V_79 ;
goto V_162;
}
}
F_80 () ;
F_33 ( V_19 ) ;
if ( V_19 -> V_39 . V_43 ) {
F_22 ( V_19 , - 1 ) ;
F_45 () ;
V_120 = - V_107 ;
goto V_162;
}
for ( V_31 = 0 ; V_31 < V_51 ; V_31 ++ )
V_19 -> V_26 [ V_31 ] . V_69 = V_157 [ V_31 ] ;
F_68 ( & V_19 -> V_39 ) ;
F_65 (un, &sma->list_id, list_id) {
for ( V_31 = 0 ; V_31 < V_51 ; V_31 ++ )
V_64 -> V_76 [ V_31 ] = 0 ;
}
V_19 -> V_62 = F_44 () ;
F_63 ( V_19 , NULL , 0 , 0 , & V_102 ) ;
V_120 = 0 ;
goto V_145;
}
}
V_120 = - V_44 ;
if ( V_89 < 0 || V_89 >= V_51 )
goto V_159;
F_15 ( V_19 , NULL , - 1 ) ;
V_25 = & V_19 -> V_26 [ V_89 ] ;
switch ( V_118 ) {
case V_163 :
V_120 = V_25 -> V_69 ;
goto V_145;
case V_164 :
V_120 = V_25 -> V_78 ;
goto V_145;
case V_165 :
V_120 = F_64 ( V_19 , V_89 ) ;
goto V_145;
case V_166 :
V_120 = F_67 ( V_19 , V_89 ) ;
goto V_145;
}
V_145:
F_22 ( V_19 , - 1 ) ;
V_159:
F_45 () ;
F_53 ( & V_102 ) ;
V_162:
if( V_157 != V_155 )
F_91 ( V_157 , sizeof( T_3 ) * V_51 ) ;
return V_120 ;
}
static inline unsigned long
F_92 ( struct V_109 * V_115 , void T_4 * V_108 , int V_111 )
{
switch( V_111 ) {
case V_112 :
if ( F_90 ( V_115 , V_108 , sizeof( * V_115 ) ) )
return - V_141 ;
return 0 ;
case V_113 :
{
struct V_114 V_167 ;
if( F_90 ( & V_167 , V_108 , sizeof( V_167 ) ) )
return - V_141 ;
V_115 -> V_39 . V_168 = V_167 . V_39 . V_168 ;
V_115 -> V_39 . V_169 = V_167 . V_39 . V_169 ;
V_115 -> V_39 . V_57 = V_167 . V_39 . V_57 ;
return 0 ;
}
default:
return - V_44 ;
}
}
static int F_93 ( struct V_1 * V_2 , int V_104 ,
int V_118 , int V_111 , void T_4 * V_119 )
{
struct V_18 * V_19 ;
int V_120 ;
struct V_109 V_170 ;
struct V_41 * V_42 ;
if( V_118 == V_171 ) {
if ( F_92 ( & V_170 , V_119 , V_111 ) )
return - V_141 ;
}
F_94 ( & F_5 ( V_2 ) . V_136 ) ;
F_80 () ;
V_42 = F_95 ( V_2 , & F_5 ( V_2 ) , V_104 , V_118 ,
& V_170 . V_39 , 0 ) ;
if ( F_26 ( V_42 ) ) {
V_120 = F_81 ( V_42 ) ;
goto V_172;
}
V_19 = F_28 ( V_42 , struct V_18 , V_39 ) ;
V_120 = F_76 ( V_19 , V_118 ) ;
if ( V_120 )
goto V_172;
switch ( V_118 ) {
case V_173 :
F_15 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_42 ) ;
goto V_174;
case V_171 :
F_15 ( V_19 , NULL , - 1 ) ;
V_120 = F_96 ( & V_170 . V_39 , V_42 ) ;
if ( V_120 )
goto V_175;
V_19 -> V_62 = F_44 () ;
break;
default:
V_120 = - V_44 ;
goto V_172;
}
V_175:
F_22 ( V_19 , - 1 ) ;
V_172:
F_45 () ;
V_174:
F_97 ( & F_5 ( V_2 ) . V_136 ) ;
return V_120 ;
}
static inline int F_98 ( struct V_176 * * V_177 )
{
struct V_176 * V_178 ;
V_178 = V_154 -> V_179 . V_178 ;
if ( ! V_178 ) {
V_178 = F_99 ( sizeof( * V_178 ) , V_180 ) ;
if ( V_178 == NULL )
return - V_56 ;
F_43 ( & V_178 -> V_37 ) ;
F_100 ( & V_178 -> V_181 , 1 ) ;
F_12 ( & V_178 -> V_105 ) ;
V_154 -> V_179 . V_178 = V_178 ;
}
* V_177 = V_178 ;
return 0 ;
}
static struct V_63 * F_101 ( struct V_176 * V_103 , int V_104 )
{
struct V_63 * V_64 ;
F_102 (un, &ulp->list_proc, list_proc) {
if ( V_64 -> V_104 == V_104 )
return V_64 ;
}
return NULL ;
}
static struct V_63 * F_103 ( struct V_176 * V_103 , int V_104 )
{
struct V_63 * V_64 ;
F_104 ( & V_103 -> V_37 ) ;
V_64 = F_101 ( V_103 , V_104 ) ;
if ( V_64 ) {
F_69 ( & V_64 -> V_105 ) ;
F_105 ( & V_64 -> V_105 , & V_103 -> V_105 ) ;
}
return V_64 ;
}
static struct V_63 * F_106 ( struct V_1 * V_2 , int V_104 )
{
struct V_18 * V_19 ;
struct V_176 * V_103 ;
struct V_63 * V_64 , * V_182 ;
int V_51 , error ;
error = F_98 ( & V_103 ) ;
if ( error )
return F_29 ( error ) ;
F_80 () ;
F_16 ( & V_103 -> V_37 ) ;
V_64 = F_103 ( V_103 , V_104 ) ;
F_18 ( & V_103 -> V_37 ) ;
if ( F_107 ( V_64 != NULL ) )
goto V_115;
V_19 = F_31 ( V_2 , V_104 ) ;
if ( F_26 ( V_19 ) ) {
F_45 () ;
return F_27 ( V_19 ) ;
}
V_51 = V_19 -> V_32 ;
if ( ! F_88 ( V_19 ) ) {
F_45 () ;
V_64 = F_29 ( - V_107 ) ;
goto V_115;
}
F_45 () ;
V_182 = F_99 ( sizeof( struct V_63 ) + sizeof( short ) * V_51 , V_180 ) ;
if ( ! V_182 ) {
F_35 ( V_19 ) ;
return F_29 ( - V_56 ) ;
}
F_80 () ;
F_33 ( V_19 ) ;
if ( V_19 -> V_39 . V_43 ) {
F_22 ( V_19 , - 1 ) ;
F_45 () ;
F_108 ( V_182 ) ;
V_64 = F_29 ( - V_107 ) ;
goto V_115;
}
F_16 ( & V_103 -> V_37 ) ;
V_64 = F_103 ( V_103 , V_104 ) ;
if ( V_64 ) {
F_108 ( V_182 ) ;
goto V_183;
}
V_182 -> V_76 = ( short * ) & V_182 [ 1 ] ;
V_182 -> V_103 = V_103 ;
V_182 -> V_104 = V_104 ;
F_104 ( & V_103 -> V_37 ) ;
F_105 ( & V_182 -> V_105 , & V_103 -> V_105 ) ;
F_68 ( & V_19 -> V_39 ) ;
F_109 ( & V_182 -> V_61 , & V_19 -> V_61 ) ;
V_64 = V_182 ;
V_183:
F_18 ( & V_103 -> V_37 ) ;
F_22 ( V_19 , - 1 ) ;
V_115:
return V_64 ;
}
static int F_110 ( struct V_20 * V_21 )
{
int error ;
error = V_21 -> V_84 ;
while ( F_17 ( error == V_85 ) ) {
F_111 () ;
error = V_21 -> V_84 ;
}
return error ;
}
int F_112 ( unsigned long V_184 , struct V_185 * V_186 )
{
struct V_176 * V_178 ;
int error ;
if ( V_184 & V_187 ) {
error = F_98 ( & V_178 ) ;
if ( error )
return error ;
F_113 ( & V_178 -> V_181 ) ;
V_186 -> V_179 . V_178 = V_178 ;
} else
V_186 -> V_179 . V_178 = NULL ;
return 0 ;
}
void F_114 ( struct V_185 * V_186 )
{
struct V_176 * V_103 ;
V_103 = V_186 -> V_179 . V_178 ;
if ( ! V_103 )
return;
V_186 -> V_179 . V_178 = NULL ;
if ( ! F_115 ( & V_103 -> V_181 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_63 * V_64 ;
struct V_82 V_102 ;
int V_104 , V_31 ;
F_80 () ;
V_64 = F_116 ( V_103 -> V_105 . V_93 ,
struct V_63 , V_105 ) ;
if ( & V_64 -> V_105 == & V_103 -> V_105 )
V_104 = - 1 ;
else
V_104 = V_64 -> V_104 ;
if ( V_104 == - 1 ) {
F_45 () ;
break;
}
V_19 = F_31 ( V_186 -> V_188 -> V_189 , V_64 -> V_104 ) ;
if ( F_26 ( V_19 ) ) {
F_45 () ;
continue;
}
F_15 ( V_19 , NULL , - 1 ) ;
V_64 = F_101 ( V_103 , V_104 ) ;
if ( V_64 == NULL ) {
F_22 ( V_19 , - 1 ) ;
F_45 () ;
continue;
}
F_68 ( & V_19 -> V_39 ) ;
F_58 ( & V_64 -> V_61 ) ;
F_16 ( & V_103 -> V_37 ) ;
F_69 ( & V_64 -> V_105 ) ;
F_18 ( & V_103 -> V_37 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_24 * V_190 = & V_19 -> V_26 [ V_31 ] ;
if ( V_64 -> V_76 [ V_31 ] ) {
V_190 -> V_69 += V_64 -> V_76 [ V_31 ] ;
if ( V_190 -> V_69 < 0 )
V_190 -> V_69 = 0 ;
if ( V_190 -> V_69 > V_71 )
V_190 -> V_69 = V_71 ;
V_190 -> V_78 = F_86 ( V_154 ) ;
}
}
F_12 ( & V_102 ) ;
F_63 ( V_19 , NULL , 0 , 1 , & V_102 ) ;
F_22 ( V_19 , - 1 ) ;
F_45 () ;
F_53 ( & V_102 ) ;
F_70 ( V_64 , V_106 ) ;
}
F_108 ( V_103 ) ;
}
static int V_17 ( struct V_191 * V_45 , void * V_192 )
{
struct V_193 * V_194 = F_117 ( V_45 ) ;
struct V_18 * V_19 = V_192 ;
T_5 V_98 ;
V_98 = F_74 ( V_19 ) ;
return F_118 ( V_45 ,
L_3 ,
V_19 -> V_39 . V_50 ,
V_19 -> V_39 . V_40 ,
V_19 -> V_39 . V_57 ,
V_19 -> V_32 ,
F_119 ( V_194 , V_19 -> V_39 . V_168 ) ,
F_120 ( V_194 , V_19 -> V_39 . V_169 ) ,
F_119 ( V_194 , V_19 -> V_39 . V_195 ) ,
F_120 ( V_194 , V_19 -> V_39 . V_196 ) ,
V_98 ,
V_19 -> V_62 ) ;
}
