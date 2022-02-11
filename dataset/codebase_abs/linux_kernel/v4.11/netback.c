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
F_10 ( & V_36 -> V_40 [ 0 ] ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_26 * V_41 ,
unsigned int V_28 ,
struct V_26 * V_27 ,
int V_42 )
{
T_4 V_30 = V_2 -> V_18 . V_31 ;
int V_43 = 0 ;
int V_44 = 0 ;
int V_45 ;
if ( ! ( V_41 -> V_32 & V_46 ) )
return 0 ;
do {
struct V_26 V_47 = { 0 } ;
if ( V_43 >= V_42 ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_2 ,
V_42 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_48 ;
}
if ( F_28 ( V_43 >= V_49 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_3 ,
V_43 , V_49 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_50 ;
}
if ( ! V_44 && V_43 >= V_51 ) {
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_4 ,
V_43 , V_51 ) ;
V_44 = - V_50 ;
}
if ( V_44 )
V_27 = & V_47 ;
F_24 ( & V_2 -> V_18 , V_30 + V_43 , V_27 ) ;
if ( ! V_44 && V_27 -> V_52 > V_41 -> V_52 ) {
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_5 ,
V_27 -> V_52 , V_41 -> V_52 ) ;
V_44 = - V_53 ;
}
V_41 -> V_52 -= V_27 -> V_52 ;
V_43 ++ ;
if ( F_28 ( ( V_27 -> V_54 + V_27 -> V_52 ) > V_55 ) ) {
F_26 ( V_2 -> V_36 -> V_37 , L_6 ,
V_27 -> V_54 , V_27 -> V_52 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_56 ;
}
V_45 = V_27 -> V_32 & V_46 ;
if ( ! V_44 )
V_27 ++ ;
} while ( V_45 );
if ( V_44 ) {
F_19 ( V_2 , V_41 , V_28 , V_30 + V_43 ) ;
return V_44 ;
}
return V_43 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_26 * V_27 ,
unsigned int V_28 ,
struct V_57 * V_58 )
{
V_2 -> V_59 [ V_58 - V_2 -> V_60 ] = V_2 -> V_4 [ V_7 ] ;
F_32 ( V_58 , F_3 ( V_2 , V_7 ) ,
V_61 | V_62 ,
V_27 -> V_63 , V_2 -> V_36 -> V_64 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_65 , V_27 ,
sizeof( * V_27 ) ) ;
V_2 -> V_9 [ V_7 ] . V_28 = V_28 ;
}
static inline struct V_66 * F_33 ( unsigned int V_52 )
{
struct V_66 * V_67 =
F_34 ( V_52 + V_68 + V_69 ,
V_70 | V_71 ) ;
if ( F_28 ( V_67 == NULL ) )
return NULL ;
F_35 ( V_67 , V_68 + V_69 ) ;
F_36 ( V_67 ) -> V_72 = NULL ;
return V_67 ;
}
static struct V_57 * F_37 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_26 * V_27 ,
struct V_57 * V_73 ,
unsigned int V_74 ,
struct V_66 * V_75 )
{
struct V_76 * V_77 = F_36 ( V_67 ) ;
T_2 * V_78 = V_77 -> V_78 ;
T_1 V_7 = F_38 ( V_67 ) -> V_7 ;
int V_79 ;
T_3 V_80 ;
unsigned int V_81 ;
V_81 = V_77 -> V_82 ;
V_79 = ( F_7 ( & V_77 -> V_78 [ 0 ] ) == V_7 ) ;
for ( V_77 -> V_82 = V_79 ; V_77 -> V_82 < V_81 ;
V_77 -> V_82 ++ , V_27 ++ , V_73 ++ ) {
V_80 = F_9 ( V_2 -> V_83 ++ ) ;
V_7 = V_2 -> V_84 [ V_80 ] ;
F_31 ( V_2 , V_7 , V_27 , 0 , V_73 ) ;
F_8 ( & V_78 [ V_77 -> V_82 ] , V_7 ) ;
}
if ( V_74 ) {
V_77 = F_36 ( V_75 ) ;
V_78 = V_77 -> V_78 ;
for ( V_77 -> V_82 = 0 ; V_77 -> V_82 < V_74 ;
V_77 -> V_82 ++ , V_27 ++ , V_73 ++ ) {
V_80 = F_9 ( V_2 -> V_83 ++ ) ;
V_7 = V_2 -> V_84 [ V_80 ] ;
F_31 ( V_2 , V_7 , V_27 , 0 ,
V_73 ) ;
F_8 ( & V_78 [ V_77 -> V_82 ] ,
V_7 ) ;
}
F_36 ( V_67 ) -> V_85 = V_75 ;
}
return V_73 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_5 V_86 )
{
if ( F_28 ( V_2 -> V_87 [ V_7 ] !=
V_88 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_7 ,
V_7 ) ;
F_40 () ;
}
V_2 -> V_87 [ V_7 ] = V_86 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_28 ( V_2 -> V_87 [ V_7 ] ==
V_88 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_8 ,
V_7 ) ;
F_40 () ;
}
V_2 -> V_87 [ V_7 ] = V_88 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_57 * * V_89 ,
struct V_90 * * V_91 )
{
struct V_57 * V_92 = * V_89 ;
T_1 V_7 = F_38 ( V_67 ) -> V_7 ;
struct V_76 * V_77 = F_36 ( V_67 ) ;
struct V_76 * V_93 = NULL ;
int V_82 = V_77 -> V_82 ;
const bool V_94 = V_82 &&
F_7 ( & V_77 -> V_78 [ 0 ] ) == V_7 ;
int V_14 , V_95 ;
V_95 = ( * V_91 ) -> V_96 ;
if ( F_28 ( V_95 ) ) {
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_9 ,
( * V_91 ) -> V_96 ,
V_7 ,
( * V_91 ) -> V_97 . V_98 . V_99 ) ;
if ( ! V_94 )
F_43 ( V_2 , V_7 ,
V_34 ) ;
}
( * V_91 ) ++ ;
V_100:
for ( V_14 = 0 ; V_14 < V_82 ; V_14 ++ , V_92 ++ ) {
int V_101 , V_102 ;
V_7 = F_7 ( & V_77 -> V_78 [ V_14 ] ) ;
V_102 = V_92 -> V_96 ;
if ( F_44 ( ! V_102 ) ) {
F_39 ( V_2 ,
V_7 ,
V_92 -> V_86 ) ;
if ( F_28 ( V_95 ) ) {
F_45 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_94 )
F_43 ( V_2 , V_7 ,
V_34 ) ;
else
F_43 ( V_2 , V_7 ,
V_103 ) ;
}
continue;
}
if ( F_29 () )
F_30 ( V_2 -> V_36 -> V_37 ,
L_10 ,
V_14 ,
V_92 -> V_96 ,
V_7 ,
V_92 -> V_99 ) ;
F_43 ( V_2 , V_7 , V_34 ) ;
if ( V_95 )
continue;
if ( ! V_94 )
F_43 ( V_2 ,
F_38 ( V_67 ) -> V_7 ,
V_103 ) ;
for ( V_101 = 0 ; V_101 < V_14 ; V_101 ++ ) {
V_7 = F_7 ( & V_77 -> V_78 [ V_101 ] ) ;
F_45 ( V_2 , V_7 ) ;
F_43 ( V_2 , V_7 ,
V_103 ) ;
}
if ( V_93 ) {
for ( V_101 = 0 ; V_101 < V_93 -> V_82 ; V_101 ++ ) {
V_7 = F_7 ( & V_93 -> V_78 [ V_101 ] ) ;
F_45 ( V_2 , V_7 ) ;
F_43 ( V_2 , V_7 ,
V_103 ) ;
}
}
V_95 = V_102 ;
}
if ( F_46 ( V_67 ) && ! V_93 ) {
V_93 = F_36 ( V_67 ) ;
V_77 = F_36 ( F_36 ( V_67 ) -> V_85 ) ;
V_82 = V_77 -> V_82 ;
goto V_100;
}
* V_89 = V_92 ;
return V_95 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_76 * V_77 = F_36 ( V_67 ) ;
int V_82 = V_77 -> V_82 ;
int V_14 ;
T_1 V_104 = V_105 ;
for ( V_14 = 0 ; V_14 < V_82 ; V_14 ++ ) {
T_2 * V_12 = V_77 -> V_78 + V_14 ;
struct V_26 * V_27 ;
struct V_106 * V_106 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_104 == V_105 )
F_36 ( V_67 ) -> V_72 =
& F_48 ( V_2 , V_7 ) ;
else
F_48 ( V_2 , V_104 ) . V_107 =
& F_48 ( V_2 , V_7 ) ;
F_48 ( V_2 , V_7 ) . V_107 = NULL ;
V_104 = V_7 ;
V_27 = & V_2 -> V_9 [ V_7 ] . V_65 ;
V_106 = F_49 ( F_3 ( V_2 , V_7 ) ) ;
F_50 ( V_67 , V_14 , V_106 , V_27 -> V_54 , V_27 -> V_52 ) ;
V_67 -> V_108 += V_27 -> V_52 ;
V_67 -> V_109 += V_27 -> V_52 ;
V_67 -> V_110 += V_27 -> V_52 ;
F_51 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_52 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
unsigned int * V_28 ,
int V_42 )
{
struct V_111 V_113 ;
T_4 V_30 = V_2 -> V_18 . V_31 ;
do {
if ( F_28 ( V_42 -- <= 0 ) ) {
F_26 ( V_2 -> V_36 -> V_37 , L_11 ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_114 ;
}
F_24 ( & V_2 -> V_18 , V_30 , & V_113 ) ;
V_2 -> V_18 . V_31 = ++ V_30 ;
( * V_28 ) ++ ;
if ( F_28 ( ! V_113 . type ||
V_113 . type >= V_115 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_12 , V_113 . type ) ;
F_25 ( V_2 -> V_36 ) ;
return - V_56 ;
}
memcpy ( & V_112 [ V_113 . type - 1 ] , & V_113 , sizeof( V_113 ) ) ;
} while ( V_113 . V_32 & V_116 );
return V_42 ;
}
static int F_53 ( struct V_35 * V_36 ,
struct V_66 * V_67 ,
struct V_111 * V_117 )
{
if ( ! V_117 -> V_98 . V_117 . V_52 ) {
F_26 ( V_36 -> V_37 , L_13 ) ;
F_25 ( V_36 ) ;
return - V_56 ;
}
switch ( V_117 -> V_98 . V_117 . type ) {
case V_118 :
F_36 ( V_67 ) -> V_119 = V_120 ;
break;
case V_121 :
F_36 ( V_67 ) -> V_119 = V_122 ;
break;
default:
F_26 ( V_36 -> V_37 , L_14 , V_117 -> V_98 . V_117 . type ) ;
F_25 ( V_36 ) ;
return - V_56 ;
}
F_36 ( V_67 ) -> V_123 = V_117 -> V_98 . V_117 . V_52 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
bool V_124 = false ;
if ( V_67 -> V_125 != V_126 && F_55 ( V_67 ) ) {
V_2 -> V_127 . V_128 ++ ;
V_67 -> V_125 = V_126 ;
V_124 = true ;
}
if ( V_67 -> V_125 != V_126 )
return 0 ;
return F_56 ( V_67 , V_124 ) ;
}
static bool F_57 ( struct V_1 * V_2 , unsigned V_52 )
{
T_6 V_129 = F_58 () ;
T_6 V_130 = V_2 -> V_131 +
F_59 ( V_2 -> V_132 / 1000 ) ;
if ( F_60 ( & V_2 -> V_133 ) )
return true ;
if ( F_61 ( V_129 , V_130 ) ) {
V_2 -> V_131 = V_129 ;
F_15 ( V_2 ) ;
}
if ( V_52 > V_2 -> V_23 ) {
V_2 -> V_133 . V_25 =
( unsigned long ) V_2 ;
F_62 ( & V_2 -> V_133 ,
V_130 ) ;
V_2 -> V_131 = V_130 ;
return true ;
}
return false ;
}
static int F_63 ( struct V_35 * V_36 , const T_7 * V_134 )
{
struct V_135 * V_136 ;
if ( V_36 -> V_137 == V_138 ) {
if ( F_29 () )
F_26 ( V_36 -> V_37 ,
L_15 ) ;
return - V_139 ;
}
V_136 = F_64 ( sizeof( * V_136 ) , V_70 ) ;
if ( ! V_136 )
return - V_140 ;
F_65 ( V_136 -> V_134 , V_134 ) ;
F_66 ( & V_136 -> V_141 , & V_36 -> V_142 ) ;
V_36 -> V_137 ++ ;
return 0 ;
}
static void F_67 ( struct V_35 * V_36 , const T_7 * V_134 )
{
struct V_135 * V_136 ;
F_68 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_69 ( V_134 , V_136 -> V_134 ) ) {
-- V_36 -> V_137 ;
F_70 ( & V_136 -> V_141 ) ;
F_71 ( V_136 , V_143 ) ;
break;
}
}
}
bool F_72 ( struct V_35 * V_36 , const T_7 * V_134 )
{
struct V_135 * V_136 ;
F_73 () ;
F_68 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_69 ( V_134 , V_136 -> V_134 ) ) {
F_74 () ;
return true ;
}
}
F_74 () ;
return false ;
}
void F_75 ( struct V_35 * V_36 )
{
while ( ! F_76 ( & V_36 -> V_142 ) ) {
struct V_135 * V_136 ;
V_136 = F_77 ( & V_36 -> V_142 ,
struct V_135 ,
V_141 ) ;
-- V_36 -> V_137 ;
F_78 ( & V_136 -> V_141 ) ;
F_79 ( V_136 ) ;
}
}
static void F_80 ( struct V_1 * V_2 ,
int V_144 ,
unsigned * V_145 ,
unsigned * V_146 )
{
struct V_57 * V_73 = V_2 -> V_60 ;
struct V_66 * V_67 , * V_75 ;
int V_147 ;
unsigned int V_74 ;
while ( F_81 ( & V_2 -> V_148 ) < V_144 ) {
struct V_26 V_149 ;
struct V_26 V_150 [ V_51 ] ;
struct V_111 V_112 [ V_115 - 1 ] ;
unsigned int V_28 ;
T_1 V_7 ;
T_4 V_3 ;
int V_42 ;
unsigned int V_109 ;
T_3 V_80 ;
if ( V_2 -> V_18 . V_151 -> V_152 - V_2 -> V_18 . V_31 >
V_153 ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_16
L_17 ,
V_2 -> V_18 . V_151 -> V_152 , V_2 -> V_18 . V_31 ,
V_153 ) ;
F_25 ( V_2 -> V_36 ) ;
break;
}
V_42 = F_82 ( & V_2 -> V_18 ) ;
if ( ! V_42 )
break;
V_3 = V_2 -> V_18 . V_31 ;
F_83 () ;
F_24 ( & V_2 -> V_18 , V_3 , & V_149 ) ;
if ( V_149 . V_52 > V_2 -> V_23 &&
F_57 ( V_2 , V_149 . V_52 ) )
break;
V_2 -> V_23 -= V_149 . V_52 ;
V_42 -- ;
V_2 -> V_18 . V_31 = ++ V_3 ;
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
V_28 = 0 ;
if ( V_149 . V_32 & V_154 ) {
V_42 = F_52 ( V_2 , V_112 ,
& V_28 ,
V_42 ) ;
V_3 = V_2 -> V_18 . V_31 ;
if ( F_28 ( V_42 < 0 ) )
break;
}
if ( V_112 [ V_155 - 1 ] . type ) {
struct V_111 * V_113 ;
V_113 = & V_112 [ V_155 - 1 ] ;
V_147 = F_63 ( V_2 -> V_36 , V_113 -> V_98 . V_136 . V_134 ) ;
F_21 ( V_2 , & V_149 , V_28 ,
( V_147 == 0 ) ?
V_103 :
V_34 ) ;
F_22 ( V_2 ) ;
continue;
}
if ( V_112 [ V_156 - 1 ] . type ) {
struct V_111 * V_113 ;
V_113 = & V_112 [ V_156 - 1 ] ;
F_67 ( V_2 -> V_36 , V_113 -> V_98 . V_136 . V_134 ) ;
F_21 ( V_2 , & V_149 , V_28 ,
V_103 ) ;
F_22 ( V_2 ) ;
continue;
}
V_147 = F_27 ( V_2 , & V_149 , V_28 ,
V_150 , V_42 ) ;
if ( F_28 ( V_147 < 0 ) )
break;
V_3 += V_147 ;
if ( F_28 ( V_149 . V_52 < V_157 ) ) {
F_30 ( V_2 -> V_36 -> V_37 ,
L_18 , V_149 . V_52 ) ;
F_19 ( V_2 , & V_149 , V_28 , V_3 ) ;
break;
}
if ( F_28 ( ( V_149 . V_54 + V_149 . V_52 ) > V_55 ) ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_19 ,
V_149 . V_54 , V_149 . V_52 ,
( unsigned long ) ( V_149 . V_54 & ~ V_158 ) + V_149 . V_52 ) ;
F_25 ( V_2 -> V_36 ) ;
break;
}
V_80 = F_9 ( V_2 -> V_83 ) ;
V_7 = V_2 -> V_84 [ V_80 ] ;
V_109 = ( V_149 . V_52 > V_159 &&
V_147 < V_51 ) ?
V_159 : V_149 . V_52 ;
V_67 = F_33 ( V_109 ) ;
if ( F_28 ( V_67 == NULL ) ) {
F_30 ( V_2 -> V_36 -> V_37 ,
L_20 ) ;
F_19 ( V_2 , & V_149 , V_28 , V_3 ) ;
break;
}
F_36 ( V_67 ) -> V_82 = V_147 ;
if ( V_109 < V_149 . V_52 )
F_36 ( V_67 ) -> V_82 ++ ;
V_74 = 0 ;
V_75 = NULL ;
if ( F_36 ( V_67 ) -> V_82 > V_160 ) {
V_74 = F_36 ( V_67 ) -> V_82 - V_160 ;
F_84 ( V_74 > V_160 ) ;
F_36 ( V_67 ) -> V_82 = V_160 ;
V_75 = F_33 ( 0 ) ;
if ( F_28 ( V_75 == NULL ) ) {
F_85 ( V_67 ) ;
F_19 ( V_2 , & V_149 , V_28 , V_3 ) ;
if ( F_29 () )
F_26 ( V_2 -> V_36 -> V_37 ,
L_21 ) ;
break;
}
}
if ( V_112 [ V_161 - 1 ] . type ) {
struct V_111 * V_117 ;
V_117 = & V_112 [ V_161 - 1 ] ;
if ( F_53 ( V_2 -> V_36 , V_67 , V_117 ) ) {
F_85 ( V_67 ) ;
F_85 ( V_75 ) ;
break;
}
}
if ( V_112 [ V_162 - 1 ] . type ) {
struct V_111 * V_113 ;
enum V_163 type = V_164 ;
V_113 = & V_112 [ V_162 - 1 ] ;
switch ( V_113 -> V_98 . V_165 . type ) {
case V_166 :
case V_167 :
type = V_168 ;
break;
case V_169 :
case V_170 :
type = V_171 ;
break;
default:
break;
}
if ( type != V_164 )
F_86 ( V_67 ,
* ( V_172 * ) V_113 -> V_98 . V_165 . V_173 ,
type ) ;
}
F_38 ( V_67 ) -> V_7 = V_7 ;
F_87 ( V_67 , V_109 ) ;
V_2 -> V_174 [ * V_145 ] . V_97 . V_98 . V_99 = V_149 . V_63 ;
V_2 -> V_174 [ * V_145 ] . V_97 . V_64 = V_2 -> V_36 -> V_64 ;
V_2 -> V_174 [ * V_145 ] . V_97 . V_54 = V_149 . V_54 ;
V_2 -> V_174 [ * V_145 ] . V_175 . V_98 . V_176 =
F_88 ( V_67 -> V_25 ) ;
V_2 -> V_174 [ * V_145 ] . V_175 . V_64 = V_177 ;
V_2 -> V_174 [ * V_145 ] . V_175 . V_54 =
F_89 ( V_67 -> V_25 ) & ~ V_158 ;
V_2 -> V_174 [ * V_145 ] . V_108 = V_109 ;
V_2 -> V_174 [ * V_145 ] . V_32 = V_178 ;
( * V_145 ) ++ ;
if ( V_109 < V_149 . V_52 ) {
F_8 ( & F_36 ( V_67 ) -> V_78 [ 0 ] ,
V_7 ) ;
F_31 ( V_2 , V_7 , & V_149 ,
V_28 , V_73 ) ;
V_73 ++ ;
} else {
F_8 ( & F_36 ( V_67 ) -> V_78 [ 0 ] ,
V_105 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_65 ,
& V_149 , sizeof( V_149 ) ) ;
V_2 -> V_9 [ V_7 ] . V_28 =
V_28 ;
}
V_2 -> V_83 ++ ;
V_73 = F_37 ( V_2 , V_67 , V_150 , V_73 ,
V_74 , V_75 ) ;
F_90 ( & V_2 -> V_148 , V_67 ) ;
V_2 -> V_18 . V_31 = V_3 ;
if ( ( ( V_73 - V_2 -> V_60 ) >= F_91 ( V_2 -> V_60 ) ) ||
( * V_145 >= F_91 ( V_2 -> V_174 ) ) )
break;
}
( * V_146 ) = V_73 - V_2 -> V_60 ;
return;
}
static int F_92 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
unsigned int V_54 = F_93 ( V_67 ) ;
T_2 V_78 [ V_160 ] ;
int V_14 , V_179 ;
struct V_5 * V_180 ;
struct V_66 * V_75 = F_36 ( V_67 ) -> V_85 ;
V_2 -> V_127 . V_181 += 2 ;
V_2 -> V_127 . V_182 ++ ;
F_47 ( V_2 , V_75 ) ;
V_67 -> V_110 -= V_67 -> V_109 ;
V_67 -> V_108 += V_75 -> V_108 ;
V_67 -> V_109 += V_75 -> V_108 ;
for ( V_14 = 0 ; V_54 < V_67 -> V_108 ; V_14 ++ ) {
struct V_106 * V_106 ;
unsigned int V_108 ;
F_84 ( V_14 >= V_160 ) ;
V_106 = F_94 ( V_70 ) ;
if ( ! V_106 ) {
int V_101 ;
V_67 -> V_110 += V_67 -> V_109 ;
for ( V_101 = 0 ; V_101 < V_14 ; V_101 ++ )
F_95 ( V_78 [ V_101 ] . V_106 . V_183 ) ;
return - V_140 ;
}
if ( V_54 + V_184 < V_67 -> V_108 )
V_108 = V_184 ;
else
V_108 = V_67 -> V_108 - V_54 ;
if ( F_96 ( V_67 , V_54 , F_97 ( V_106 ) , V_108 ) )
F_40 () ;
V_54 += V_108 ;
V_78 [ V_14 ] . V_106 . V_183 = V_106 ;
V_78 [ V_14 ] . V_13 = 0 ;
F_98 ( & V_78 [ V_14 ] , V_108 ) ;
}
F_99 ( V_67 ) ;
F_100 ( V_2 , V_75 ) ;
F_85 ( V_75 ) ;
for ( V_179 = 0 ; V_179 < F_36 ( V_67 ) -> V_82 ; V_179 ++ )
F_101 ( V_67 , V_179 ) ;
V_180 = F_36 ( V_67 ) -> V_72 ;
F_102 ( & V_2 -> V_185 ) ;
V_180 -> V_186 ( V_180 , true ) ;
F_36 ( V_67 ) -> V_72 = NULL ;
memcpy ( F_36 ( V_67 ) -> V_78 , V_78 , V_14 * sizeof( T_2 ) ) ;
F_36 ( V_67 ) -> V_82 = V_14 ;
V_67 -> V_110 += V_14 * V_184 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_57 * V_92 = V_2 -> V_60 ;
struct V_90 * V_187 = V_2 -> V_174 ;
struct V_66 * V_67 ;
int V_188 = 0 ;
while ( ( V_67 = F_104 ( & V_2 -> V_148 ) ) != NULL ) {
struct V_26 * V_27 ;
T_1 V_7 ;
unsigned V_109 ;
V_7 = F_38 ( V_67 ) -> V_7 ;
V_27 = & V_2 -> V_9 [ V_7 ] . V_65 ;
if ( F_28 ( F_42 ( V_2 , V_67 , & V_92 , & V_187 ) ) ) {
F_36 ( V_67 ) -> V_82 = 0 ;
if ( F_46 ( V_67 ) ) {
struct V_66 * V_75 =
F_36 ( V_67 ) -> V_85 ;
F_36 ( V_75 ) -> V_82 = 0 ;
}
F_85 ( V_67 ) ;
continue;
}
V_109 = V_67 -> V_108 ;
F_48 ( V_2 , V_7 ) . V_107 = NULL ;
if ( V_109 < V_27 -> V_52 ) {
V_27 -> V_54 += V_109 ;
V_27 -> V_52 -= V_109 ;
} else {
F_43 ( V_2 , V_7 ,
V_103 ) ;
}
if ( V_27 -> V_32 & V_189 )
V_67 -> V_125 = V_126 ;
else if ( V_27 -> V_32 & V_190 )
V_67 -> V_125 = V_191 ;
F_47 ( V_2 , V_67 ) ;
if ( F_28 ( F_46 ( V_67 ) ) ) {
if ( F_92 ( V_2 , V_67 ) ) {
if ( F_29 () )
F_26 ( V_2 -> V_36 -> V_37 ,
L_22 ) ;
F_100 ( V_2 , V_67 ) ;
F_85 ( V_67 ) ;
continue;
}
}
V_67 -> V_37 = V_2 -> V_36 -> V_37 ;
V_67 -> V_192 = F_105 ( V_67 , V_67 -> V_37 ) ;
F_106 ( V_67 ) ;
if ( F_54 ( V_2 , V_67 ) ) {
F_30 ( V_2 -> V_36 -> V_37 ,
L_23 ) ;
if ( F_36 ( V_67 ) -> V_72 )
F_100 ( V_2 , V_67 ) ;
F_85 ( V_67 ) ;
continue;
}
F_107 ( V_67 , 0 ) ;
if ( F_55 ( V_67 ) ) {
int V_193 = F_36 ( V_67 ) -> V_123 ;
int V_194 = F_108 ( V_67 ) -
F_109 ( V_67 ) +
F_110 ( V_67 ) ;
F_36 ( V_67 ) -> V_195 =
F_111 ( V_67 -> V_108 - V_194 , V_193 ) ;
}
V_2 -> V_127 . V_196 += V_67 -> V_108 ;
V_2 -> V_127 . V_197 ++ ;
V_188 ++ ;
if ( F_36 ( V_67 ) -> V_72 ) {
F_100 ( V_2 , V_67 ) ;
V_2 -> V_127 . V_181 ++ ;
}
F_112 ( V_67 ) ;
}
return V_188 ;
}
void F_113 ( struct V_5 * V_6 , bool V_198 )
{
unsigned long V_32 ;
T_3 V_80 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_20 ( & V_2 -> V_199 , V_32 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_107 ;
F_84 ( V_2 -> V_200 - V_2 -> V_201 >=
V_15 ) ;
V_80 = F_9 ( V_2 -> V_200 ) ;
V_2 -> V_202 [ V_80 ] = V_7 ;
F_114 () ;
V_2 -> V_200 ++ ;
} while ( V_6 );
F_23 ( & V_2 -> V_199 , V_32 ) ;
if ( F_44 ( V_198 ) )
V_2 -> V_127 . V_203 ++ ;
else
V_2 -> V_127 . V_204 ++ ;
F_115 ( V_2 ) ;
}
static inline void F_116 ( struct V_1 * V_2 )
{
struct V_205 * V_73 ;
T_3 V_206 , V_207 ;
T_1 V_7 , V_208 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_206 = V_2 -> V_201 ;
V_73 = V_2 -> V_209 ;
do {
V_207 = V_2 -> V_200 ;
F_117 () ;
while ( V_206 != V_207 ) {
F_84 ( V_73 - V_2 -> V_209 >= V_15 ) ;
V_7 =
V_2 -> V_202 [ F_9 ( V_206 ++ ) ] ;
V_208 [ V_73 - V_2 -> V_209 ] =
V_7 ;
V_2 -> V_210 [ V_73 - V_2 -> V_209 ] =
V_2 -> V_4 [ V_7 ] ;
F_118 ( V_73 ,
F_3 ( V_2 , V_7 ) ,
V_61 ,
V_2 -> V_87 [ V_7 ] ) ;
F_41 ( V_2 , V_7 ) ;
++ V_73 ;
}
} while ( V_207 != V_2 -> V_200 );
V_2 -> V_201 = V_206 ;
if ( V_73 - V_2 -> V_209 > 0 ) {
int V_147 ;
V_147 = F_119 ( V_2 -> V_209 ,
NULL ,
V_2 -> V_210 ,
V_73 - V_2 -> V_209 ) ;
if ( V_147 ) {
F_26 ( V_2 -> V_36 -> V_37 , L_24 ,
V_73 - V_2 -> V_209 , V_147 ) ;
for ( V_14 = 0 ; V_14 < V_73 - V_2 -> V_209 ; ++ V_14 ) {
if ( V_73 [ V_14 ] . V_96 != V_211 )
F_26 ( V_2 -> V_36 -> V_37 ,
L_25 ,
V_73 [ V_14 ] . V_212 ,
V_73 [ V_14 ] . V_86 ,
V_73 [ V_14 ] . V_96 ) ;
}
F_40 () ;
}
}
for ( V_14 = 0 ; V_14 < V_73 - V_2 -> V_209 ; ++ V_14 )
F_43 ( V_2 , V_208 [ V_14 ] ,
V_103 ) ;
}
int F_120 ( struct V_1 * V_2 , int V_144 )
{
unsigned V_213 , V_214 = 0 ;
int V_188 , V_147 ;
if ( F_28 ( ! F_121 ( V_2 ) ) )
return 0 ;
F_80 ( V_2 , V_144 , & V_214 , & V_213 ) ;
if ( V_214 == 0 )
return 0 ;
F_122 ( V_2 -> V_174 , V_214 ) ;
if ( V_213 != 0 ) {
V_147 = F_123 ( V_2 -> V_60 ,
NULL ,
V_2 -> V_59 ,
V_213 ) ;
F_84 ( V_147 ) ;
}
V_188 = F_103 ( V_2 ) ;
return V_188 ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_7 ,
T_7 V_96 )
{
struct V_9 * V_9 ;
T_3 V_80 ;
unsigned long V_32 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_20 ( & V_2 -> V_33 , V_32 ) ;
F_21 ( V_2 , & V_9 -> V_65 ,
V_9 -> V_28 , V_96 ) ;
V_80 = F_9 ( V_2 -> V_215 ++ ) ;
V_2 -> V_84 [ V_80 ] = V_7 ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_33 , V_32 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
unsigned int V_28 ,
T_8 V_216 )
{
T_4 V_14 = V_2 -> V_18 . V_217 ;
struct V_218 * V_219 ;
V_219 = F_124 ( & V_2 -> V_18 , V_14 ) ;
V_219 -> V_220 = V_27 -> V_220 ;
V_219 -> V_96 = V_216 ;
while ( V_28 -- != 0 )
F_124 ( & V_2 -> V_18 , ++ V_14 ) -> V_96 = V_221 ;
V_2 -> V_18 . V_217 = ++ V_14 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_222 ;
F_125 ( & V_2 -> V_18 , V_222 ) ;
if ( V_222 )
F_126 ( V_2 -> V_223 ) ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_147 ;
struct V_205 V_224 ;
F_118 ( & V_224 ,
F_3 ( V_2 , V_7 ) ,
V_61 ,
V_2 -> V_87 [ V_7 ] ) ;
F_41 ( V_2 , V_7 ) ;
V_147 = F_119 ( & V_224 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_147 ) {
F_26 ( V_2 -> V_36 -> V_37 ,
L_26 ,
V_147 ,
V_7 ,
V_224 . V_212 ,
V_224 . V_86 ,
V_224 . V_96 ) ;
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
return V_2 -> V_201 != V_2 -> V_200 ;
}
void F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . V_151 )
F_129 ( F_130 ( V_2 -> V_36 ) ,
V_2 -> V_18 . V_151 ) ;
if ( V_2 -> V_225 . V_151 )
F_129 ( F_130 ( V_2 -> V_36 ) ,
V_2 -> V_225 . V_151 ) ;
}
int F_131 ( struct V_1 * V_2 ,
T_9 V_226 ,
T_9 V_227 )
{
void * V_134 ;
struct V_228 * V_229 ;
struct V_230 * V_231 ;
int V_95 = - V_140 ;
V_95 = F_132 ( F_130 ( V_2 -> V_36 ) ,
& V_226 , 1 , & V_134 ) ;
if ( V_95 )
goto V_95;
V_229 = (struct V_228 * ) V_134 ;
F_133 ( & V_2 -> V_18 , V_229 , V_55 ) ;
V_95 = F_132 ( F_130 ( V_2 -> V_36 ) ,
& V_227 , 1 , & V_134 ) ;
if ( V_95 )
goto V_95;
V_231 = (struct V_230 * ) V_134 ;
F_133 ( & V_2 -> V_225 , V_231 , V_55 ) ;
return 0 ;
V_95:
F_128 ( V_2 ) ;
return V_95 ;
}
static bool F_134 ( struct V_1 * V_2 )
{
return F_135 () &&
! F_136 ( & V_2 -> V_185 ) ;
}
int F_137 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
for (; ; ) {
F_138 ( V_2 -> V_232 ,
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
const struct V_233 * V_65 ,
V_172 V_96 , V_172 V_25 )
{
T_4 V_3 = V_36 -> V_234 . V_217 ;
struct V_235 V_236 = {
. V_220 = V_65 -> V_220 ,
. type = V_65 -> type ,
. V_96 = V_96 ,
. V_25 = V_25 ,
} ;
* F_124 ( & V_36 -> V_234 , V_3 ) = V_236 ;
V_36 -> V_234 . V_217 = ++ V_3 ;
}
static void F_141 ( struct V_35 * V_36 )
{
int V_222 ;
F_125 ( & V_36 -> V_234 , V_222 ) ;
if ( V_222 )
F_126 ( V_36 -> V_237 ) ;
}
static void F_142 ( struct V_35 * V_36 ,
const struct V_233 * V_65 )
{
V_172 V_96 = V_238 ;
V_172 V_25 = 0 ;
switch ( V_65 -> type ) {
case V_239 :
V_96 = F_143 ( V_36 , V_65 -> V_25 [ 0 ] ) ;
break;
case V_240 :
V_96 = F_144 ( V_36 , & V_25 ) ;
break;
case V_241 :
V_96 = F_145 ( V_36 , V_65 -> V_25 [ 0 ] ) ;
break;
case V_242 :
V_96 = F_146 ( V_36 , V_65 -> V_25 [ 0 ] ,
V_65 -> V_25 [ 1 ] ) ;
break;
case V_243 :
V_96 = V_244 ;
V_25 = V_245 ;
break;
case V_246 :
V_96 = F_147 ( V_36 ,
V_65 -> V_25 [ 0 ] ) ;
break;
case V_247 :
V_96 = F_148 ( V_36 , V_65 -> V_25 [ 0 ] ,
V_65 -> V_25 [ 1 ] ,
V_65 -> V_25 [ 2 ] ) ;
break;
default:
break;
}
F_140 ( V_36 , V_65 , V_96 , V_25 ) ;
F_141 ( V_36 ) ;
}
static void F_149 ( struct V_35 * V_36 )
{
for (; ; ) {
T_4 V_152 , V_31 ;
V_152 = V_36 -> V_234 . V_151 -> V_152 ;
V_31 = V_36 -> V_234 . V_31 ;
F_83 () ;
if ( V_31 == V_152 )
break;
while ( V_31 != V_152 ) {
struct V_233 V_65 ;
F_24 ( & V_36 -> V_234 , V_31 , & V_65 ) ;
V_31 ++ ;
F_142 ( V_36 , & V_65 ) ;
}
V_36 -> V_234 . V_31 = V_31 ;
V_36 -> V_234 . V_151 -> V_248 = V_31 + 1 ;
}
}
static bool F_150 ( struct V_35 * V_36 )
{
if ( F_44 ( F_82 ( & V_36 -> V_234 ) ) )
return 1 ;
return 0 ;
}
T_10 F_151 ( int V_249 , void * V_25 )
{
struct V_35 * V_36 = V_25 ;
while ( F_150 ( V_36 ) )
F_149 ( V_36 ) ;
return V_250 ;
}
static int T_11 F_152 ( void )
{
int V_251 = 0 ;
if ( ! F_153 () )
return - V_252 ;
if ( V_253 == 0 )
V_253 = F_154 (unsigned int, MAX_QUEUES_DEFAULT,
num_online_cpus()) ;
if ( V_49 < V_51 ) {
F_155 ( L_27 ,
V_49 , V_51 ) ;
V_49 = V_51 ;
}
V_251 = F_156 () ;
if ( V_251 )
goto V_254;
#ifdef F_157
V_255 = F_158 ( L_28 , NULL ) ;
if ( F_159 ( V_255 ) )
F_160 ( L_29 ,
F_161 ( V_255 ) ) ;
#endif
return 0 ;
V_254:
return V_251 ;
}
static void T_12 F_162 ( void )
{
#ifdef F_157
if ( ! F_159 ( V_255 ) )
F_163 ( V_255 ) ;
#endif
F_164 () ;
}
