static inline unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_2 ( V_2 -> V_4 [ V_3 ] ) ;
}
static inline unsigned long F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return ( unsigned long ) F_4 ( F_1 ( V_2 , V_3 ) ) ;
}
static inline struct V_1 * F_5 ( const struct V_5 * V_6 )
{
T_1 V_7 = V_6 -> V_8 ;
struct V_9 * V_10 =
F_6 ( V_6 , struct V_9 , V_11 ) ;
return F_6 ( V_10 - V_7 ,
struct V_1 ,
V_9 [ 0 ] ) ;
}
static T_1 F_7 ( T_2 * V_12 )
{
return ( T_1 ) V_12 -> V_13 ;
}
static void F_8 ( T_2 * V_12 , T_1 V_7 )
{
V_12 -> V_13 = V_7 ;
}
static inline T_3 F_9 ( unsigned V_14 )
{
return V_14 & ( V_15 - 1 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_16 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
int V_17 ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
if ( V_17 )
F_14 ( & V_2 -> V_19 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned long V_20 , V_21 ;
V_20 = F_16 ( 131072UL , V_2 -> V_22 ) ;
V_21 = V_2 -> V_23 + V_2 -> V_22 ;
if ( V_21 < V_2 -> V_23 )
V_21 = V_24 ;
V_2 -> V_23 = F_17 ( V_21 , V_20 ) ;
}
void F_18 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
F_15 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
unsigned int V_28 , T_4 V_29 )
{
T_4 V_30 = V_2 -> V_18 . V_31 ;
unsigned long V_32 ;
do {
F_20 ( & V_2 -> V_33 , V_32 ) ;
F_21 ( V_2 , V_27 , V_28 , V_34 ) ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_33 , V_32 ) ;
if ( V_30 == V_29 )
break;
F_24 ( & V_2 -> V_18 , V_30 ++ , V_27 ) ;
V_28 = 0 ;
} while ( 1 );
V_2 -> V_18 . V_31 = V_30 ;
}
static void F_25 ( struct V_35 * V_36 )
{
F_26 ( V_36 -> V_37 , L_1 ) ;
V_36 -> V_38 = true ;
if ( V_36 -> V_39 )
F_10 ( & V_36 -> V_39 [ 0 ] ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_26 * V_40 ,
unsigned int V_28 ,
struct V_26 * V_27 ,
int V_41 )
{
T_4 V_30 = V_2 -> V_18 . V_31 ;
int V_42 = 0 ;
int V_43 = 0 ;
int V_44 ;
if ( ! ( V_40 -> V_32 & V_45 ) )
return 0 ;
do {
struct V_26 V_46 = { 0 } ;
if ( V_42 >= V_41 ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_2 ,
V_41 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_47 ;
}
if ( F_28 ( V_42 >= V_48 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_3 ,
V_42 , V_48 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_49 ;
}
if ( ! V_43 && V_42 >= V_50 ) {
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_4 ,
V_42 , V_50 ) ;
V_43 = - V_49 ;
}
if ( V_43 )
V_27 = & V_46 ;
F_24 ( & V_2 -> V_18 , V_30 + V_42 , V_27 ) ;
if ( ! V_43 && V_27 -> V_51 > V_40 -> V_51 ) {
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_5 ,
V_27 -> V_51 , V_40 -> V_51 ) ;
V_43 = - V_52 ;
}
V_40 -> V_51 -= V_27 -> V_51 ;
V_42 ++ ;
if ( F_28 ( ( V_27 -> V_53 + V_27 -> V_51 ) > V_54 ) ) {
F_26 ( V_2 -> V_36 -> V_37 , L_6 ,
V_27 -> V_53 , V_27 -> V_51 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_55 ;
}
V_44 = V_27 -> V_32 & V_45 ;
if ( ! V_43 )
V_27 ++ ;
} while ( V_44 );
if ( V_43 ) {
F_19 ( V_2 , V_40 , V_28 , V_30 + V_42 ) ;
return V_43 ;
}
return V_42 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_26 * V_27 ,
unsigned int V_28 ,
struct V_56 * V_57 )
{
V_2 -> V_58 [ V_57 - V_2 -> V_59 ] = V_2 -> V_4 [ V_7 ] ;
F_32 ( V_57 , F_3 ( V_2 , V_7 ) ,
V_60 | V_61 ,
V_27 -> V_62 , V_2 -> V_36 -> V_63 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_64 , V_27 ,
sizeof( * V_27 ) ) ;
V_2 -> V_9 [ V_7 ] . V_28 = V_28 ;
}
static inline struct V_65 * F_33 ( unsigned int V_51 )
{
struct V_65 * V_66 =
F_34 ( V_51 + V_67 + V_68 ,
V_69 | V_70 ) ;
if ( F_28 ( V_66 == NULL ) )
return NULL ;
F_35 ( V_66 , V_67 + V_68 ) ;
F_36 ( V_66 ) -> V_71 = NULL ;
return V_66 ;
}
static struct V_56 * F_37 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
struct V_26 * V_27 ,
struct V_56 * V_72 ,
unsigned int V_73 ,
struct V_65 * V_74 )
{
struct V_75 * V_76 = F_36 ( V_66 ) ;
T_2 * V_77 = V_76 -> V_77 ;
T_1 V_7 = F_38 ( V_66 ) -> V_7 ;
int V_78 ;
T_3 V_79 ;
unsigned int V_80 ;
V_80 = V_76 -> V_81 ;
V_78 = ( F_7 ( & V_76 -> V_77 [ 0 ] ) == V_7 ) ;
for ( V_76 -> V_81 = V_78 ; V_76 -> V_81 < V_80 ;
V_76 -> V_81 ++ , V_27 ++ , V_72 ++ ) {
V_79 = F_9 ( V_2 -> V_82 ++ ) ;
V_7 = V_2 -> V_83 [ V_79 ] ;
F_31 ( V_2 , V_7 , V_27 , 0 , V_72 ) ;
F_8 ( & V_77 [ V_76 -> V_81 ] , V_7 ) ;
}
if ( V_73 ) {
V_76 = F_36 ( V_74 ) ;
V_77 = V_76 -> V_77 ;
for ( V_76 -> V_81 = 0 ; V_76 -> V_81 < V_73 ;
V_76 -> V_81 ++ , V_27 ++ , V_72 ++ ) {
V_79 = F_9 ( V_2 -> V_82 ++ ) ;
V_7 = V_2 -> V_83 [ V_79 ] ;
F_31 ( V_2 , V_7 , V_27 , 0 ,
V_72 ) ;
F_8 ( & V_77 [ V_76 -> V_81 ] ,
V_7 ) ;
}
F_36 ( V_66 ) -> V_84 = V_74 ;
}
return V_72 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_5 V_85 )
{
if ( F_28 ( V_2 -> V_86 [ V_7 ] !=
V_87 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_7 ,
V_7 ) ;
F_40 () ;
}
V_2 -> V_86 [ V_7 ] = V_85 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_28 ( V_2 -> V_86 [ V_7 ] ==
V_87 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_8 ,
V_7 ) ;
F_40 () ;
}
V_2 -> V_86 [ V_7 ] = V_87 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
struct V_56 * * V_88 ,
struct V_89 * * V_90 )
{
struct V_56 * V_91 = * V_88 ;
T_1 V_7 = F_38 ( V_66 ) -> V_7 ;
struct V_75 * V_76 = F_36 ( V_66 ) ;
struct V_75 * V_92 = NULL ;
int V_81 = V_76 -> V_81 ;
const bool V_93 = V_81 &&
F_7 ( & V_76 -> V_77 [ 0 ] ) == V_7 ;
int V_14 , V_94 ;
V_94 = ( * V_90 ) -> V_95 ;
if ( F_28 ( V_94 ) ) {
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_9 ,
( * V_90 ) -> V_95 ,
V_7 ,
( * V_90 ) -> V_96 . V_97 . V_98 ) ;
if ( ! V_93 )
F_43 ( V_2 , V_7 ,
V_34 ) ;
}
( * V_90 ) ++ ;
V_99:
for ( V_14 = 0 ; V_14 < V_81 ; V_14 ++ , V_91 ++ ) {
int V_100 , V_101 ;
V_7 = F_7 ( & V_76 -> V_77 [ V_14 ] ) ;
V_101 = V_91 -> V_95 ;
if ( F_44 ( ! V_101 ) ) {
F_39 ( V_2 ,
V_7 ,
V_91 -> V_85 ) ;
if ( F_28 ( V_94 ) ) {
F_45 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_93 )
F_43 ( V_2 , V_7 ,
V_34 ) ;
else
F_43 ( V_2 , V_7 ,
V_102 ) ;
}
continue;
}
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_10 ,
V_14 ,
V_91 -> V_95 ,
V_7 ,
V_91 -> V_98 ) ;
F_43 ( V_2 , V_7 , V_34 ) ;
if ( V_94 )
continue;
if ( ! V_93 )
F_43 ( V_2 ,
F_38 ( V_66 ) -> V_7 ,
V_102 ) ;
for ( V_100 = 0 ; V_100 < V_14 ; V_100 ++ ) {
V_7 = F_7 ( & V_76 -> V_77 [ V_100 ] ) ;
F_45 ( V_2 , V_7 ) ;
F_43 ( V_2 , V_7 ,
V_102 ) ;
}
if ( V_92 ) {
for ( V_100 = 0 ; V_100 < V_92 -> V_81 ; V_100 ++ ) {
V_7 = F_7 ( & V_92 -> V_77 [ V_100 ] ) ;
F_45 ( V_2 , V_7 ) ;
F_43 ( V_2 , V_7 ,
V_102 ) ;
}
}
V_94 = V_101 ;
}
if ( F_46 ( V_66 ) && ! V_92 ) {
V_92 = F_36 ( V_66 ) ;
V_76 = F_36 ( F_36 ( V_66 ) -> V_84 ) ;
V_81 = V_76 -> V_81 ;
goto V_99;
}
* V_88 = V_91 ;
return V_94 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_75 * V_76 = F_36 ( V_66 ) ;
int V_81 = V_76 -> V_81 ;
int V_14 ;
T_1 V_103 = V_104 ;
for ( V_14 = 0 ; V_14 < V_81 ; V_14 ++ ) {
T_2 * V_12 = V_76 -> V_77 + V_14 ;
struct V_26 * V_27 ;
struct V_105 * V_105 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_103 == V_104 )
F_36 ( V_66 ) -> V_71 =
& F_48 ( V_2 , V_7 ) ;
else
F_48 ( V_2 , V_103 ) . V_106 =
& F_48 ( V_2 , V_7 ) ;
F_48 ( V_2 , V_7 ) . V_106 = NULL ;
V_103 = V_7 ;
V_27 = & V_2 -> V_9 [ V_7 ] . V_64 ;
V_105 = F_49 ( F_3 ( V_2 , V_7 ) ) ;
F_50 ( V_66 , V_14 , V_105 , V_27 -> V_53 , V_27 -> V_51 ) ;
V_66 -> V_107 += V_27 -> V_51 ;
V_66 -> V_108 += V_27 -> V_51 ;
V_66 -> V_109 += V_27 -> V_51 ;
F_51 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_52 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
unsigned int * V_28 ,
int V_41 )
{
struct V_110 V_112 ;
T_4 V_30 = V_2 -> V_18 . V_31 ;
do {
if ( F_28 ( V_41 -- <= 0 ) ) {
F_26 ( V_2 -> V_36 -> V_37 , L_11 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_113 ;
}
F_24 ( & V_2 -> V_18 , V_30 , & V_112 ) ;
V_2 -> V_18 . V_31 = ++ V_30 ;
( * V_28 ) ++ ;
if ( F_28 ( ! V_112 . type ||
V_112 . type >= V_114 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_12 , V_112 . type ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_55 ;
}
memcpy ( & V_111 [ V_112 . type - 1 ] , & V_112 , sizeof( V_112 ) ) ;
} while ( V_112 . V_32 & V_115 );
return V_41 ;
}
static int F_53 ( struct V_35 * V_36 ,
struct V_65 * V_66 ,
struct V_110 * V_116 )
{
if ( ! V_116 -> V_97 . V_116 . V_51 ) {
F_26 ( V_36 -> V_37 , L_13 ) ;
F_25 ( V_36 ) ;
return - V_55 ;
}
switch ( V_116 -> V_97 . V_116 . type ) {
case V_117 :
F_36 ( V_66 ) -> V_118 = V_119 ;
break;
case V_120 :
F_36 ( V_66 ) -> V_118 = V_121 ;
break;
default:
F_26 ( V_36 -> V_37 , L_14 , V_116 -> V_97 . V_116 . type ) ;
F_25 ( V_36 ) ;
return - V_55 ;
}
F_36 ( V_66 ) -> V_122 = V_116 -> V_97 . V_116 . V_51 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
bool V_123 = false ;
if ( V_66 -> V_124 != V_125 && F_55 ( V_66 ) ) {
V_2 -> V_126 . V_127 ++ ;
V_66 -> V_124 = V_125 ;
V_123 = true ;
}
if ( V_66 -> V_124 != V_125 )
return 0 ;
return F_56 ( V_66 , V_123 ) ;
}
static bool F_57 ( struct V_1 * V_2 , unsigned V_51 )
{
T_6 V_128 = F_58 () ;
T_6 V_129 = V_2 -> V_130 +
F_59 ( V_2 -> V_131 / 1000 ) ;
if ( F_60 ( & V_2 -> V_132 ) )
return true ;
if ( F_61 ( V_128 , V_129 ) ) {
V_2 -> V_130 = V_128 ;
F_15 ( V_2 ) ;
}
if ( V_51 > V_2 -> V_23 ) {
V_2 -> V_132 . V_25 =
( unsigned long ) V_2 ;
F_62 ( & V_2 -> V_132 ,
V_129 ) ;
V_2 -> V_130 = V_129 ;
return true ;
}
return false ;
}
static int F_63 ( struct V_35 * V_36 , const T_7 * V_133 )
{
struct V_134 * V_135 ;
if ( V_36 -> V_136 == V_137 ) {
if ( F_29 () )
F_26 ( V_36 -> V_37 ,
L_15 ) ;
return - V_138 ;
}
V_135 = F_64 ( sizeof( * V_135 ) , V_69 ) ;
if ( ! V_135 )
return - V_139 ;
F_65 ( V_135 -> V_133 , V_133 ) ;
F_66 ( & V_135 -> V_140 , & V_36 -> V_141 ) ;
V_36 -> V_136 ++ ;
return 0 ;
}
static void F_67 ( struct V_35 * V_36 , const T_7 * V_133 )
{
struct V_134 * V_135 ;
F_68 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_69 ( V_133 , V_135 -> V_133 ) ) {
-- V_36 -> V_136 ;
F_70 ( & V_135 -> V_140 ) ;
F_71 ( V_135 , V_142 ) ;
break;
}
}
}
bool F_72 ( struct V_35 * V_36 , const T_7 * V_133 )
{
struct V_134 * V_135 ;
F_73 () ;
F_68 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_69 ( V_133 , V_135 -> V_133 ) ) {
F_74 () ;
return true ;
}
}
F_74 () ;
return false ;
}
void F_75 ( struct V_35 * V_36 )
{
while ( ! F_76 ( & V_36 -> V_141 ) ) {
struct V_134 * V_135 ;
V_135 = F_77 ( & V_36 -> V_141 ,
struct V_134 ,
V_140 ) ;
-- V_36 -> V_136 ;
F_78 ( & V_135 -> V_140 ) ;
F_79 ( V_135 ) ;
}
}
static void F_80 ( struct V_1 * V_2 ,
int V_143 ,
unsigned * V_144 ,
unsigned * V_145 )
{
struct V_56 * V_72 = V_2 -> V_59 ;
struct V_65 * V_66 , * V_74 ;
int V_146 ;
unsigned int V_73 ;
while ( F_81 ( & V_2 -> V_147 ) < V_143 ) {
struct V_26 V_148 ;
struct V_26 V_149 [ V_50 ] ;
struct V_110 V_111 [ V_114 - 1 ] ;
unsigned int V_28 ;
T_1 V_7 ;
T_4 V_3 ;
int V_41 ;
unsigned int V_108 ;
T_3 V_79 ;
if ( V_2 -> V_18 . V_150 -> V_151 - V_2 -> V_18 . V_31 >
V_152 ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_16
L_17 ,
V_2 -> V_18 . V_150 -> V_151 , V_2 -> V_18 . V_31 ,
V_152 ) ;
F_25 ( V_2 -> V_36 ) ;
break;
}
V_41 = F_82 ( & V_2 -> V_18 ) ;
if ( ! V_41 )
break;
V_3 = V_2 -> V_18 . V_31 ;
F_83 () ;
F_24 ( & V_2 -> V_18 , V_3 , & V_148 ) ;
if ( V_148 . V_51 > V_2 -> V_23 &&
F_57 ( V_2 , V_148 . V_51 ) )
break;
V_2 -> V_23 -= V_148 . V_51 ;
V_41 -- ;
V_2 -> V_18 . V_31 = ++ V_3 ;
memset ( V_111 , 0 , sizeof( V_111 ) ) ;
V_28 = 0 ;
if ( V_148 . V_32 & V_153 ) {
V_41 = F_52 ( V_2 , V_111 ,
& V_28 ,
V_41 ) ;
V_3 = V_2 -> V_18 . V_31 ;
if ( F_28 ( V_41 < 0 ) )
break;
}
if ( V_111 [ V_154 - 1 ] . type ) {
struct V_110 * V_112 ;
V_112 = & V_111 [ V_154 - 1 ] ;
V_146 = F_63 ( V_2 -> V_36 , V_112 -> V_97 . V_135 . V_133 ) ;
F_21 ( V_2 , & V_148 , V_28 ,
( V_146 == 0 ) ?
V_102 :
V_34 ) ;
F_22 ( V_2 ) ;
continue;
}
if ( V_111 [ V_155 - 1 ] . type ) {
struct V_110 * V_112 ;
V_112 = & V_111 [ V_155 - 1 ] ;
F_67 ( V_2 -> V_36 , V_112 -> V_97 . V_135 . V_133 ) ;
F_21 ( V_2 , & V_148 , V_28 ,
V_102 ) ;
F_22 ( V_2 ) ;
continue;
}
V_146 = F_27 ( V_2 , & V_148 , V_28 ,
V_149 , V_41 ) ;
if ( F_28 ( V_146 < 0 ) )
break;
V_3 += V_146 ;
if ( F_28 ( V_148 . V_51 < V_156 ) ) {
F_30 ( V_2 -> V_36 -> V_37 ,
L_18 , V_148 . V_51 ) ;
F_19 ( V_2 , & V_148 , V_28 , V_3 ) ;
break;
}
if ( F_28 ( ( V_148 . V_53 + V_148 . V_51 ) > V_54 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_19 ,
V_148 . V_53 , V_148 . V_51 ,
( unsigned long ) ( V_148 . V_53 & ~ V_157 ) + V_148 . V_51 ) ;
F_25 ( V_2 -> V_36 ) ;
break;
}
V_79 = F_9 ( V_2 -> V_82 ) ;
V_7 = V_2 -> V_83 [ V_79 ] ;
V_108 = ( V_148 . V_51 > V_158 &&
V_146 < V_50 ) ?
V_158 : V_148 . V_51 ;
V_66 = F_33 ( V_108 ) ;
if ( F_28 ( V_66 == NULL ) ) {
F_30 ( V_2 -> V_36 -> V_37 ,
L_20 ) ;
F_19 ( V_2 , & V_148 , V_28 , V_3 ) ;
break;
}
F_36 ( V_66 ) -> V_81 = V_146 ;
if ( V_108 < V_148 . V_51 )
F_36 ( V_66 ) -> V_81 ++ ;
V_73 = 0 ;
V_74 = NULL ;
if ( F_36 ( V_66 ) -> V_81 > V_159 ) {
V_73 = F_36 ( V_66 ) -> V_81 - V_159 ;
F_84 ( V_73 > V_159 ) ;
F_36 ( V_66 ) -> V_81 = V_159 ;
V_74 = F_33 ( 0 ) ;
if ( F_28 ( V_74 == NULL ) ) {
F_85 ( V_66 ) ;
F_19 ( V_2 , & V_148 , V_28 , V_3 ) ;
if ( F_29 () )
F_26 ( V_2 -> V_36 -> V_37 ,
L_21 ) ;
break;
}
}
if ( V_111 [ V_160 - 1 ] . type ) {
struct V_110 * V_116 ;
V_116 = & V_111 [ V_160 - 1 ] ;
if ( F_53 ( V_2 -> V_36 , V_66 , V_116 ) ) {
F_85 ( V_66 ) ;
F_85 ( V_74 ) ;
break;
}
}
if ( V_111 [ V_161 - 1 ] . type ) {
struct V_110 * V_112 ;
enum V_162 type = V_163 ;
V_112 = & V_111 [ V_161 - 1 ] ;
switch ( V_112 -> V_97 . V_164 . type ) {
case V_165 :
case V_166 :
type = V_167 ;
break;
case V_168 :
case V_169 :
type = V_170 ;
break;
default:
break;
}
if ( type != V_163 )
F_86 ( V_66 ,
* ( V_171 * ) V_112 -> V_97 . V_164 . V_172 ,
type ) ;
}
F_38 ( V_66 ) -> V_7 = V_7 ;
F_87 ( V_66 , V_108 ) ;
V_2 -> V_173 [ * V_144 ] . V_96 . V_97 . V_98 = V_148 . V_62 ;
V_2 -> V_173 [ * V_144 ] . V_96 . V_63 = V_2 -> V_36 -> V_63 ;
V_2 -> V_173 [ * V_144 ] . V_96 . V_53 = V_148 . V_53 ;
V_2 -> V_173 [ * V_144 ] . V_174 . V_97 . V_175 =
F_88 ( V_66 -> V_25 ) ;
V_2 -> V_173 [ * V_144 ] . V_174 . V_63 = V_176 ;
V_2 -> V_173 [ * V_144 ] . V_174 . V_53 =
F_89 ( V_66 -> V_25 ) & ~ V_157 ;
V_2 -> V_173 [ * V_144 ] . V_107 = V_108 ;
V_2 -> V_173 [ * V_144 ] . V_32 = V_177 ;
( * V_144 ) ++ ;
if ( V_108 < V_148 . V_51 ) {
F_8 ( & F_36 ( V_66 ) -> V_77 [ 0 ] ,
V_7 ) ;
F_31 ( V_2 , V_7 , & V_148 ,
V_28 , V_72 ) ;
V_72 ++ ;
} else {
F_8 ( & F_36 ( V_66 ) -> V_77 [ 0 ] ,
V_104 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_64 ,
& V_148 , sizeof( V_148 ) ) ;
V_2 -> V_9 [ V_7 ] . V_28 =
V_28 ;
}
V_2 -> V_82 ++ ;
V_72 = F_37 ( V_2 , V_66 , V_149 , V_72 ,
V_73 , V_74 ) ;
F_90 ( & V_2 -> V_147 , V_66 ) ;
V_2 -> V_18 . V_31 = V_3 ;
if ( ( ( V_72 - V_2 -> V_59 ) >= F_91 ( V_2 -> V_59 ) ) ||
( * V_144 >= F_91 ( V_2 -> V_173 ) ) )
break;
}
( * V_145 ) = V_72 - V_2 -> V_59 ;
return;
}
static int F_92 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
unsigned int V_53 = F_93 ( V_66 ) ;
T_2 V_77 [ V_159 ] ;
int V_14 , V_178 ;
struct V_5 * V_179 ;
struct V_65 * V_74 = F_36 ( V_66 ) -> V_84 ;
V_2 -> V_126 . V_180 += 2 ;
V_2 -> V_126 . V_181 ++ ;
F_47 ( V_2 , V_74 ) ;
V_66 -> V_109 -= V_66 -> V_108 ;
V_66 -> V_107 += V_74 -> V_107 ;
V_66 -> V_108 += V_74 -> V_107 ;
for ( V_14 = 0 ; V_53 < V_66 -> V_107 ; V_14 ++ ) {
struct V_105 * V_105 ;
unsigned int V_107 ;
F_84 ( V_14 >= V_159 ) ;
V_105 = F_94 ( V_69 ) ;
if ( ! V_105 ) {
int V_100 ;
V_66 -> V_109 += V_66 -> V_108 ;
for ( V_100 = 0 ; V_100 < V_14 ; V_100 ++ )
F_95 ( V_77 [ V_100 ] . V_105 . V_182 ) ;
return - V_139 ;
}
if ( V_53 + V_183 < V_66 -> V_107 )
V_107 = V_183 ;
else
V_107 = V_66 -> V_107 - V_53 ;
if ( F_96 ( V_66 , V_53 , F_97 ( V_105 ) , V_107 ) )
F_40 () ;
V_53 += V_107 ;
V_77 [ V_14 ] . V_105 . V_182 = V_105 ;
V_77 [ V_14 ] . V_13 = 0 ;
F_98 ( & V_77 [ V_14 ] , V_107 ) ;
}
F_99 ( V_66 ) ;
F_100 ( V_2 , V_74 ) ;
F_85 ( V_74 ) ;
for ( V_178 = 0 ; V_178 < F_36 ( V_66 ) -> V_81 ; V_178 ++ )
F_101 ( V_66 , V_178 ) ;
V_179 = F_36 ( V_66 ) -> V_71 ;
F_102 ( & V_2 -> V_184 ) ;
V_179 -> V_185 ( V_179 , true ) ;
F_36 ( V_66 ) -> V_71 = NULL ;
memcpy ( F_36 ( V_66 ) -> V_77 , V_77 , V_14 * sizeof( T_2 ) ) ;
F_36 ( V_66 ) -> V_81 = V_14 ;
V_66 -> V_109 += V_14 * V_183 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_56 * V_91 = V_2 -> V_59 ;
struct V_89 * V_186 = V_2 -> V_173 ;
struct V_65 * V_66 ;
int V_187 = 0 ;
while ( ( V_66 = F_104 ( & V_2 -> V_147 ) ) != NULL ) {
struct V_26 * V_27 ;
T_1 V_7 ;
unsigned V_108 ;
V_7 = F_38 ( V_66 ) -> V_7 ;
V_27 = & V_2 -> V_9 [ V_7 ] . V_64 ;
if ( F_28 ( F_42 ( V_2 , V_66 , & V_91 , & V_186 ) ) ) {
F_36 ( V_66 ) -> V_81 = 0 ;
if ( F_46 ( V_66 ) ) {
struct V_65 * V_74 =
F_36 ( V_66 ) -> V_84 ;
F_36 ( V_74 ) -> V_81 = 0 ;
}
F_85 ( V_66 ) ;
continue;
}
V_108 = V_66 -> V_107 ;
F_48 ( V_2 , V_7 ) . V_106 = NULL ;
if ( V_108 < V_27 -> V_51 ) {
V_27 -> V_53 += V_108 ;
V_27 -> V_51 -= V_108 ;
} else {
F_43 ( V_2 , V_7 ,
V_102 ) ;
}
if ( V_27 -> V_32 & V_188 )
V_66 -> V_124 = V_125 ;
else if ( V_27 -> V_32 & V_189 )
V_66 -> V_124 = V_190 ;
F_47 ( V_2 , V_66 ) ;
if ( F_28 ( F_46 ( V_66 ) ) ) {
if ( F_92 ( V_2 , V_66 ) ) {
if ( F_29 () )
F_26 ( V_2 -> V_36 -> V_37 ,
L_22 ) ;
F_100 ( V_2 , V_66 ) ;
F_85 ( V_66 ) ;
continue;
}
}
V_66 -> V_37 = V_2 -> V_36 -> V_37 ;
V_66 -> V_191 = F_105 ( V_66 , V_66 -> V_37 ) ;
F_106 ( V_66 ) ;
if ( F_54 ( V_2 , V_66 ) ) {
F_30 ( V_2 -> V_36 -> V_37 ,
L_23 ) ;
if ( F_36 ( V_66 ) -> V_71 )
F_100 ( V_2 , V_66 ) ;
F_85 ( V_66 ) ;
continue;
}
F_107 ( V_66 , 0 ) ;
if ( F_55 ( V_66 ) ) {
int V_192 = F_36 ( V_66 ) -> V_122 ;
int V_193 = F_108 ( V_66 ) -
F_109 ( V_66 ) +
F_110 ( V_66 ) ;
F_36 ( V_66 ) -> V_194 =
F_111 ( V_66 -> V_107 - V_193 , V_192 ) ;
}
V_2 -> V_126 . V_195 += V_66 -> V_107 ;
V_2 -> V_126 . V_196 ++ ;
V_187 ++ ;
if ( F_36 ( V_66 ) -> V_71 ) {
F_100 ( V_2 , V_66 ) ;
V_2 -> V_126 . V_180 ++ ;
}
F_112 ( V_66 ) ;
}
return V_187 ;
}
void F_113 ( struct V_5 * V_6 , bool V_197 )
{
unsigned long V_32 ;
T_3 V_79 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_20 ( & V_2 -> V_198 , V_32 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_106 ;
F_84 ( V_2 -> V_199 - V_2 -> V_200 >=
V_15 ) ;
V_79 = F_9 ( V_2 -> V_199 ) ;
V_2 -> V_201 [ V_79 ] = V_7 ;
F_114 () ;
V_2 -> V_199 ++ ;
} while ( V_6 );
F_23 ( & V_2 -> V_198 , V_32 ) ;
if ( F_44 ( V_197 ) )
V_2 -> V_126 . V_202 ++ ;
else
V_2 -> V_126 . V_203 ++ ;
F_115 ( V_2 ) ;
}
static inline void F_116 ( struct V_1 * V_2 )
{
struct V_204 * V_72 ;
T_3 V_205 , V_206 ;
T_1 V_7 , V_207 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_205 = V_2 -> V_200 ;
V_72 = V_2 -> V_208 ;
do {
V_206 = V_2 -> V_199 ;
F_117 () ;
while ( V_205 != V_206 ) {
F_84 ( V_72 - V_2 -> V_208 >= V_15 ) ;
V_7 =
V_2 -> V_201 [ F_9 ( V_205 ++ ) ] ;
V_207 [ V_72 - V_2 -> V_208 ] =
V_7 ;
V_2 -> V_209 [ V_72 - V_2 -> V_208 ] =
V_2 -> V_4 [ V_7 ] ;
F_118 ( V_72 ,
F_3 ( V_2 , V_7 ) ,
V_60 ,
V_2 -> V_86 [ V_7 ] ) ;
F_41 ( V_2 , V_7 ) ;
++ V_72 ;
}
} while ( V_206 != V_2 -> V_199 );
V_2 -> V_200 = V_205 ;
if ( V_72 - V_2 -> V_208 > 0 ) {
int V_146 ;
V_146 = F_119 ( V_2 -> V_208 ,
NULL ,
V_2 -> V_209 ,
V_72 - V_2 -> V_208 ) ;
if ( V_146 ) {
F_26 ( V_2 -> V_36 -> V_37 , L_24 ,
V_72 - V_2 -> V_208 , V_146 ) ;
for ( V_14 = 0 ; V_14 < V_72 - V_2 -> V_208 ; ++ V_14 ) {
if ( V_72 [ V_14 ] . V_95 != V_210 )
F_26 ( V_2 -> V_36 -> V_37 ,
L_25 ,
V_72 [ V_14 ] . V_211 ,
V_72 [ V_14 ] . V_85 ,
V_72 [ V_14 ] . V_95 ) ;
}
F_40 () ;
}
}
for ( V_14 = 0 ; V_14 < V_72 - V_2 -> V_208 ; ++ V_14 )
F_43 ( V_2 , V_207 [ V_14 ] ,
V_102 ) ;
}
int F_120 ( struct V_1 * V_2 , int V_143 )
{
unsigned V_212 , V_213 = 0 ;
int V_187 , V_146 ;
if ( F_28 ( ! F_121 ( V_2 ) ) )
return 0 ;
F_80 ( V_2 , V_143 , & V_213 , & V_212 ) ;
if ( V_213 == 0 )
return 0 ;
F_122 ( V_2 -> V_173 , V_213 ) ;
if ( V_212 != 0 ) {
V_146 = F_123 ( V_2 -> V_59 ,
NULL ,
V_2 -> V_58 ,
V_212 ) ;
F_84 ( V_146 ) ;
}
V_187 = F_103 ( V_2 ) ;
return V_187 ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_7 ,
T_7 V_95 )
{
struct V_9 * V_9 ;
T_3 V_79 ;
unsigned long V_32 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_20 ( & V_2 -> V_33 , V_32 ) ;
F_21 ( V_2 , & V_9 -> V_64 ,
V_9 -> V_28 , V_95 ) ;
V_79 = F_9 ( V_2 -> V_214 ++ ) ;
V_2 -> V_83 [ V_79 ] = V_7 ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_33 , V_32 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
unsigned int V_28 ,
T_8 V_215 )
{
T_4 V_14 = V_2 -> V_18 . V_216 ;
struct V_217 * V_218 ;
V_218 = F_124 ( & V_2 -> V_18 , V_14 ) ;
V_218 -> V_219 = V_27 -> V_219 ;
V_218 -> V_95 = V_215 ;
while ( V_28 -- != 0 )
F_124 ( & V_2 -> V_18 , ++ V_14 ) -> V_95 = V_220 ;
V_2 -> V_18 . V_216 = ++ V_14 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_221 ;
F_125 ( & V_2 -> V_18 , V_221 ) ;
if ( V_221 )
F_126 ( V_2 -> V_222 ) ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_146 ;
struct V_204 V_223 ;
F_118 ( & V_223 ,
F_3 ( V_2 , V_7 ) ,
V_60 ,
V_2 -> V_86 [ V_7 ] ) ;
F_41 ( V_2 , V_7 ) ;
V_146 = F_119 ( & V_223 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_146 ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_26 ,
V_146 ,
V_7 ,
V_223 . V_211 ,
V_223 . V_85 ,
V_223 . V_95 ) ;
F_40 () ;
}
}
static inline int F_121 ( struct V_1 * V_2 )
{
if ( F_44 ( F_82 ( & V_2 -> V_18 ) ) )
return 1 ;
return 0 ;
}
static inline bool F_127 ( struct V_1 * V_2 )
{
return V_2 -> V_200 != V_2 -> V_199 ;
}
void F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . V_150 )
F_129 ( F_130 ( V_2 -> V_36 ) ,
V_2 -> V_18 . V_150 ) ;
if ( V_2 -> V_224 . V_150 )
F_129 ( F_130 ( V_2 -> V_36 ) ,
V_2 -> V_224 . V_150 ) ;
}
int F_131 ( struct V_1 * V_2 ,
T_9 V_225 ,
T_9 V_226 )
{
void * V_133 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
int V_94 = - V_139 ;
V_94 = F_132 ( F_130 ( V_2 -> V_36 ) ,
& V_225 , 1 , & V_133 ) ;
if ( V_94 )
goto V_94;
V_228 = (struct V_227 * ) V_133 ;
F_133 ( & V_2 -> V_18 , V_228 , V_54 ) ;
V_94 = F_132 ( F_130 ( V_2 -> V_36 ) ,
& V_226 , 1 , & V_133 ) ;
if ( V_94 )
goto V_94;
V_230 = (struct V_229 * ) V_133 ;
F_133 ( & V_2 -> V_224 , V_230 , V_54 ) ;
return 0 ;
V_94:
F_128 ( V_2 ) ;
return V_94 ;
}
static bool F_134 ( struct V_1 * V_2 )
{
return F_135 () &&
! F_136 ( & V_2 -> V_184 ) ;
}
int F_137 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
for (; ; ) {
F_138 ( V_2 -> V_231 ,
F_127 ( V_2 ) ||
F_134 ( V_2 ) ) ;
if ( F_134 ( V_2 ) )
break;
F_116 ( V_2 ) ;
F_139 () ;
}
if ( F_127 ( V_2 ) )
F_116 ( V_2 ) ;
return 0 ;
}
static void F_140 ( struct V_35 * V_36 ,
const struct V_232 * V_64 ,
V_171 V_95 , V_171 V_25 )
{
T_4 V_3 = V_36 -> V_233 . V_216 ;
struct V_234 V_235 = {
. V_219 = V_64 -> V_219 ,
. type = V_64 -> type ,
. V_95 = V_95 ,
. V_25 = V_25 ,
} ;
* F_124 ( & V_36 -> V_233 , V_3 ) = V_235 ;
V_36 -> V_233 . V_216 = ++ V_3 ;
}
static void F_141 ( struct V_35 * V_36 )
{
int V_221 ;
F_125 ( & V_36 -> V_233 , V_221 ) ;
if ( V_221 )
F_126 ( V_36 -> V_236 ) ;
}
static void F_142 ( struct V_35 * V_36 ,
const struct V_232 * V_64 )
{
V_171 V_95 = V_237 ;
V_171 V_25 = 0 ;
switch ( V_64 -> type ) {
case V_238 :
V_95 = F_143 ( V_36 , V_64 -> V_25 [ 0 ] ) ;
break;
case V_239 :
V_95 = F_144 ( V_36 , & V_25 ) ;
break;
case V_240 :
V_95 = F_145 ( V_36 , V_64 -> V_25 [ 0 ] ) ;
break;
case V_241 :
V_95 = F_146 ( V_36 , V_64 -> V_25 [ 0 ] ,
V_64 -> V_25 [ 1 ] ) ;
break;
case V_242 :
V_95 = V_243 ;
V_25 = V_244 ;
break;
case V_245 :
V_95 = F_147 ( V_36 ,
V_64 -> V_25 [ 0 ] ) ;
break;
case V_246 :
V_95 = F_148 ( V_36 , V_64 -> V_25 [ 0 ] ,
V_64 -> V_25 [ 1 ] ,
V_64 -> V_25 [ 2 ] ) ;
break;
default:
break;
}
F_140 ( V_36 , V_64 , V_95 , V_25 ) ;
F_141 ( V_36 ) ;
}
static void F_149 ( struct V_35 * V_36 )
{
for (; ; ) {
T_4 V_151 , V_31 ;
V_151 = V_36 -> V_233 . V_150 -> V_151 ;
V_31 = V_36 -> V_233 . V_31 ;
F_83 () ;
if ( V_31 == V_151 )
break;
while ( V_31 != V_151 ) {
struct V_232 V_64 ;
F_24 ( & V_36 -> V_233 , V_31 , & V_64 ) ;
V_31 ++ ;
F_142 ( V_36 , & V_64 ) ;
}
V_36 -> V_233 . V_31 = V_31 ;
V_36 -> V_233 . V_150 -> V_247 = V_31 + 1 ;
}
}
static bool F_150 ( struct V_35 * V_36 )
{
if ( F_44 ( F_82 ( & V_36 -> V_233 ) ) )
return 1 ;
return 0 ;
}
T_10 F_151 ( int V_248 , void * V_25 )
{
struct V_35 * V_36 = V_25 ;
while ( F_150 ( V_36 ) )
F_149 ( V_36 ) ;
return V_249 ;
}
static int T_11 F_152 ( void )
{
int V_250 = 0 ;
if ( ! F_153 () )
return - V_251 ;
if ( V_252 == 0 )
V_252 = F_154 () ;
if ( V_48 < V_50 ) {
F_155 ( L_27 ,
V_48 , V_50 ) ;
V_48 = V_50 ;
}
V_250 = F_156 () ;
if ( V_250 )
goto V_253;
#ifdef F_157
V_254 = F_158 ( L_28 , NULL ) ;
if ( F_159 ( V_254 ) )
F_160 ( L_29 ,
F_161 ( V_254 ) ) ;
#endif
return 0 ;
V_253:
return V_250 ;
}
static void T_12 F_162 ( void )
{
#ifdef F_157
if ( ! F_159 ( V_254 ) )
F_163 ( V_254 ) ;
#endif
F_164 () ;
}
