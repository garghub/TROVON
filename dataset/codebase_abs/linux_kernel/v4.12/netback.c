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
V_2 -> V_25 = false ;
}
void F_18 ( unsigned long V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
F_15 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned int V_29 , T_4 V_30 )
{
T_4 V_31 = V_2 -> V_18 . V_32 ;
unsigned long V_33 ;
do {
F_20 ( & V_2 -> V_34 , V_33 ) ;
F_21 ( V_2 , V_28 , V_29 , V_35 ) ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
if ( V_31 == V_30 )
break;
F_24 ( & V_2 -> V_18 , V_31 ++ , V_28 ) ;
V_29 = 0 ;
} while ( 1 );
V_2 -> V_18 . V_32 = V_31 ;
}
static void F_25 ( struct V_36 * V_37 )
{
F_26 ( V_37 -> V_38 , L_1 ) ;
V_37 -> V_39 = true ;
if ( V_37 -> V_40 )
F_10 ( & V_37 -> V_41 [ 0 ] ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_27 * V_42 ,
unsigned int V_29 ,
struct V_27 * V_28 ,
int V_43 )
{
T_4 V_31 = V_2 -> V_18 . V_32 ;
int V_44 = 0 ;
int V_45 = 0 ;
int V_46 ;
if ( ! ( V_42 -> V_33 & V_47 ) )
return 0 ;
do {
struct V_27 V_48 = { 0 } ;
if ( V_44 >= V_43 ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_2 ,
V_43 ) ;
F_25 ( V_2 -> V_37 ) ;
return - V_49 ;
}
if ( F_28 ( V_44 >= V_50 ) ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_3 ,
V_44 , V_50 ) ;
F_25 ( V_2 -> V_37 ) ;
return - V_51 ;
}
if ( ! V_45 && V_44 >= V_52 ) {
if ( F_29 () )
F_30 ( V_2 -> V_37 -> V_38 ,
L_4 ,
V_44 , V_52 ) ;
V_45 = - V_51 ;
}
if ( V_45 )
V_28 = & V_48 ;
F_24 ( & V_2 -> V_18 , V_31 + V_44 , V_28 ) ;
if ( ! V_45 && V_28 -> V_53 > V_42 -> V_53 ) {
if ( F_29 () )
F_30 ( V_2 -> V_37 -> V_38 ,
L_5 ,
V_28 -> V_53 , V_42 -> V_53 ) ;
V_45 = - V_54 ;
}
V_42 -> V_53 -= V_28 -> V_53 ;
V_44 ++ ;
if ( F_28 ( ( V_28 -> V_55 + V_28 -> V_53 ) > V_56 ) ) {
F_26 ( V_2 -> V_37 -> V_38 , L_6 ,
V_28 -> V_55 , V_28 -> V_53 ) ;
F_25 ( V_2 -> V_37 ) ;
return - V_57 ;
}
V_46 = V_28 -> V_33 & V_47 ;
if ( ! V_45 )
V_28 ++ ;
} while ( V_46 );
if ( V_45 ) {
F_19 ( V_2 , V_42 , V_29 , V_31 + V_44 ) ;
return V_45 ;
}
return V_44 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
T_1 V_7 ,
struct V_27 * V_28 ,
unsigned int V_29 ,
struct V_58 * V_59 )
{
V_2 -> V_60 [ V_59 - V_2 -> V_61 ] = V_2 -> V_4 [ V_7 ] ;
F_32 ( V_59 , F_3 ( V_2 , V_7 ) ,
V_62 | V_63 ,
V_28 -> V_64 , V_2 -> V_37 -> V_65 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_66 , V_28 ,
sizeof( * V_28 ) ) ;
V_2 -> V_9 [ V_7 ] . V_29 = V_29 ;
}
static inline struct V_67 * F_33 ( unsigned int V_53 )
{
struct V_67 * V_68 =
F_34 ( V_53 + V_69 + V_70 ,
V_71 | V_72 ) ;
if ( F_28 ( V_68 == NULL ) )
return NULL ;
F_35 ( V_68 , V_69 + V_70 ) ;
F_36 ( V_68 ) -> V_73 = NULL ;
return V_68 ;
}
static struct V_58 * F_37 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_27 * V_28 ,
struct V_58 * V_74 ,
unsigned int V_75 ,
struct V_67 * V_76 )
{
struct V_77 * V_78 = F_36 ( V_68 ) ;
T_2 * V_79 = V_78 -> V_79 ;
T_1 V_7 = F_38 ( V_68 ) -> V_7 ;
int V_80 ;
T_3 V_81 ;
unsigned int V_82 ;
V_82 = V_78 -> V_83 ;
V_80 = ( F_7 ( & V_78 -> V_79 [ 0 ] ) == V_7 ) ;
for ( V_78 -> V_83 = V_80 ; V_78 -> V_83 < V_82 ;
V_78 -> V_83 ++ , V_28 ++ , V_74 ++ ) {
V_81 = F_9 ( V_2 -> V_84 ++ ) ;
V_7 = V_2 -> V_85 [ V_81 ] ;
F_31 ( V_2 , V_7 , V_28 , 0 , V_74 ) ;
F_8 ( & V_79 [ V_78 -> V_83 ] , V_7 ) ;
}
if ( V_75 ) {
V_78 = F_36 ( V_76 ) ;
V_79 = V_78 -> V_79 ;
for ( V_78 -> V_83 = 0 ; V_78 -> V_83 < V_75 ;
V_78 -> V_83 ++ , V_28 ++ , V_74 ++ ) {
V_81 = F_9 ( V_2 -> V_84 ++ ) ;
V_7 = V_2 -> V_85 [ V_81 ] ;
F_31 ( V_2 , V_7 , V_28 , 0 ,
V_74 ) ;
F_8 ( & V_79 [ V_78 -> V_83 ] ,
V_7 ) ;
}
F_36 ( V_68 ) -> V_86 = V_76 ;
}
return V_74 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_5 V_87 )
{
if ( F_28 ( V_2 -> V_88 [ V_7 ] !=
V_89 ) ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_7 ,
V_7 ) ;
F_40 () ;
}
V_2 -> V_88 [ V_7 ] = V_87 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
T_1 V_7 )
{
if ( F_28 ( V_2 -> V_88 [ V_7 ] ==
V_89 ) ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_8 ,
V_7 ) ;
F_40 () ;
}
V_2 -> V_88 [ V_7 ] = V_89 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_58 * * V_90 ,
struct V_91 * * V_92 )
{
struct V_58 * V_93 = * V_90 ;
T_1 V_7 = F_38 ( V_68 ) -> V_7 ;
struct V_77 * V_78 = F_36 ( V_68 ) ;
struct V_77 * V_94 = NULL ;
int V_83 = V_78 -> V_83 ;
const bool V_95 = V_83 &&
F_7 ( & V_78 -> V_79 [ 0 ] ) == V_7 ;
int V_14 , V_96 ;
V_96 = ( * V_92 ) -> V_97 ;
if ( F_28 ( V_96 ) ) {
if ( F_29 () )
F_30 ( V_2 -> V_37 -> V_38 ,
L_9 ,
( * V_92 ) -> V_97 ,
V_7 ,
( * V_92 ) -> V_98 . V_99 . V_100 ) ;
if ( ! V_95 )
F_43 ( V_2 , V_7 ,
V_35 ) ;
}
( * V_92 ) ++ ;
V_101:
for ( V_14 = 0 ; V_14 < V_83 ; V_14 ++ , V_93 ++ ) {
int V_102 , V_103 ;
V_7 = F_7 ( & V_78 -> V_79 [ V_14 ] ) ;
V_103 = V_93 -> V_97 ;
if ( F_44 ( ! V_103 ) ) {
F_39 ( V_2 ,
V_7 ,
V_93 -> V_87 ) ;
if ( F_28 ( V_96 ) ) {
F_45 ( V_2 , V_7 ) ;
if ( V_14 == 0 && V_95 )
F_43 ( V_2 , V_7 ,
V_35 ) ;
else
F_43 ( V_2 , V_7 ,
V_104 ) ;
}
continue;
}
if ( F_29 () )
F_30 ( V_2 -> V_37 -> V_38 ,
L_10 ,
V_14 ,
V_93 -> V_97 ,
V_7 ,
V_93 -> V_100 ) ;
F_43 ( V_2 , V_7 , V_35 ) ;
if ( V_96 )
continue;
if ( ! V_95 )
F_43 ( V_2 ,
F_38 ( V_68 ) -> V_7 ,
V_104 ) ;
for ( V_102 = 0 ; V_102 < V_14 ; V_102 ++ ) {
V_7 = F_7 ( & V_78 -> V_79 [ V_102 ] ) ;
F_45 ( V_2 , V_7 ) ;
F_43 ( V_2 , V_7 ,
V_104 ) ;
}
if ( V_94 ) {
for ( V_102 = 0 ; V_102 < V_94 -> V_83 ; V_102 ++ ) {
V_7 = F_7 ( & V_94 -> V_79 [ V_102 ] ) ;
F_45 ( V_2 , V_7 ) ;
F_43 ( V_2 , V_7 ,
V_104 ) ;
}
}
V_96 = V_103 ;
}
if ( F_46 ( V_68 ) && ! V_94 ) {
V_94 = F_36 ( V_68 ) ;
V_78 = F_36 ( F_36 ( V_68 ) -> V_86 ) ;
V_83 = V_78 -> V_83 ;
goto V_101;
}
* V_90 = V_93 ;
return V_96 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_77 * V_78 = F_36 ( V_68 ) ;
int V_83 = V_78 -> V_83 ;
int V_14 ;
T_1 V_105 = V_106 ;
for ( V_14 = 0 ; V_14 < V_83 ; V_14 ++ ) {
T_2 * V_12 = V_78 -> V_79 + V_14 ;
struct V_27 * V_28 ;
struct V_107 * V_107 ;
T_1 V_7 ;
V_7 = F_7 ( V_12 ) ;
if ( V_105 == V_106 )
F_36 ( V_68 ) -> V_73 =
& F_48 ( V_2 , V_7 ) ;
else
F_48 ( V_2 , V_105 ) . V_108 =
& F_48 ( V_2 , V_7 ) ;
F_48 ( V_2 , V_7 ) . V_108 = NULL ;
V_105 = V_7 ;
V_28 = & V_2 -> V_9 [ V_7 ] . V_66 ;
V_107 = F_49 ( F_3 ( V_2 , V_7 ) ) ;
F_50 ( V_68 , V_14 , V_107 , V_28 -> V_55 , V_28 -> V_53 ) ;
V_68 -> V_109 += V_28 -> V_53 ;
V_68 -> V_110 += V_28 -> V_53 ;
V_68 -> V_111 += V_28 -> V_53 ;
F_51 ( V_2 -> V_4 [ V_7 ] ) ;
}
}
static int F_52 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
unsigned int * V_29 ,
int V_43 )
{
struct V_112 V_114 ;
T_4 V_31 = V_2 -> V_18 . V_32 ;
do {
if ( F_28 ( V_43 -- <= 0 ) ) {
F_26 ( V_2 -> V_37 -> V_38 , L_11 ) ;
F_25 ( V_2 -> V_37 ) ;
return - V_115 ;
}
F_24 ( & V_2 -> V_18 , V_31 , & V_114 ) ;
V_2 -> V_18 . V_32 = ++ V_31 ;
( * V_29 ) ++ ;
if ( F_28 ( ! V_114 . type ||
V_114 . type >= V_116 ) ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_12 , V_114 . type ) ;
F_25 ( V_2 -> V_37 ) ;
return - V_57 ;
}
memcpy ( & V_113 [ V_114 . type - 1 ] , & V_114 , sizeof( V_114 ) ) ;
} while ( V_114 . V_33 & V_117 );
return V_43 ;
}
static int F_53 ( struct V_36 * V_37 ,
struct V_67 * V_68 ,
struct V_112 * V_118 )
{
if ( ! V_118 -> V_99 . V_118 . V_53 ) {
F_26 ( V_37 -> V_38 , L_13 ) ;
F_25 ( V_37 ) ;
return - V_57 ;
}
switch ( V_118 -> V_99 . V_118 . type ) {
case V_119 :
F_36 ( V_68 ) -> V_120 = V_121 ;
break;
case V_122 :
F_36 ( V_68 ) -> V_120 = V_123 ;
break;
default:
F_26 ( V_37 -> V_38 , L_14 , V_118 -> V_99 . V_118 . type ) ;
F_25 ( V_37 ) ;
return - V_57 ;
}
F_36 ( V_68 ) -> V_124 = V_118 -> V_99 . V_118 . V_53 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
bool V_125 = false ;
if ( V_68 -> V_126 != V_127 && F_55 ( V_68 ) ) {
V_2 -> V_128 . V_129 ++ ;
V_68 -> V_126 = V_127 ;
V_125 = true ;
}
if ( V_68 -> V_126 != V_127 )
return 0 ;
return F_56 ( V_68 , V_125 ) ;
}
static bool F_57 ( struct V_1 * V_2 , unsigned V_53 )
{
T_6 V_130 = F_58 () ;
T_6 V_131 = V_2 -> V_132 +
F_59 ( V_2 -> V_133 / 1000 ) ;
if ( F_60 ( & V_2 -> V_134 ) ) {
V_2 -> V_25 = true ;
return true ;
}
if ( F_61 ( V_130 , V_131 ) ) {
V_2 -> V_132 = V_130 ;
F_15 ( V_2 ) ;
}
if ( V_53 > V_2 -> V_23 ) {
V_2 -> V_134 . V_26 =
( unsigned long ) V_2 ;
F_62 ( & V_2 -> V_134 ,
V_131 ) ;
V_2 -> V_132 = V_131 ;
V_2 -> V_25 = true ;
return true ;
}
return false ;
}
static int F_63 ( struct V_36 * V_37 , const T_7 * V_135 )
{
struct V_136 * V_137 ;
if ( V_37 -> V_138 == V_139 ) {
if ( F_29 () )
F_26 ( V_37 -> V_38 ,
L_15 ) ;
return - V_140 ;
}
V_137 = F_64 ( sizeof( * V_137 ) , V_71 ) ;
if ( ! V_137 )
return - V_141 ;
F_65 ( V_137 -> V_135 , V_135 ) ;
F_66 ( & V_137 -> V_142 , & V_37 -> V_143 ) ;
V_37 -> V_138 ++ ;
return 0 ;
}
static void F_67 ( struct V_36 * V_37 , const T_7 * V_135 )
{
struct V_136 * V_137 ;
F_68 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_69 ( V_135 , V_137 -> V_135 ) ) {
-- V_37 -> V_138 ;
F_70 ( & V_137 -> V_142 ) ;
F_71 ( V_137 , V_144 ) ;
break;
}
}
}
bool F_72 ( struct V_36 * V_37 , const T_7 * V_135 )
{
struct V_136 * V_137 ;
F_73 () ;
F_68 (mcast, &vif->fe_mcast_addr, entry) {
if ( F_69 ( V_135 , V_137 -> V_135 ) ) {
F_74 () ;
return true ;
}
}
F_74 () ;
return false ;
}
void F_75 ( struct V_36 * V_37 )
{
while ( ! F_76 ( & V_37 -> V_143 ) ) {
struct V_136 * V_137 ;
V_137 = F_77 ( & V_37 -> V_143 ,
struct V_136 ,
V_142 ) ;
-- V_37 -> V_138 ;
F_78 ( & V_137 -> V_142 ) ;
F_79 ( V_137 ) ;
}
}
static void F_80 ( struct V_1 * V_2 ,
int V_145 ,
unsigned * V_146 ,
unsigned * V_147 )
{
struct V_58 * V_74 = V_2 -> V_61 ;
struct V_67 * V_68 , * V_76 ;
int V_148 ;
unsigned int V_75 ;
while ( F_81 ( & V_2 -> V_149 ) < V_145 ) {
struct V_27 V_150 ;
struct V_27 V_151 [ V_52 ] ;
struct V_112 V_113 [ V_116 - 1 ] ;
unsigned int V_29 ;
T_1 V_7 ;
T_4 V_3 ;
int V_43 ;
unsigned int V_110 ;
T_3 V_81 ;
if ( V_2 -> V_18 . V_152 -> V_153 - V_2 -> V_18 . V_32 >
V_154 ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_16
L_17 ,
V_2 -> V_18 . V_152 -> V_153 , V_2 -> V_18 . V_32 ,
V_154 ) ;
F_25 ( V_2 -> V_37 ) ;
break;
}
V_43 = F_82 ( & V_2 -> V_18 ) ;
if ( ! V_43 )
break;
V_3 = V_2 -> V_18 . V_32 ;
F_83 () ;
F_24 ( & V_2 -> V_18 , V_3 , & V_150 ) ;
if ( V_150 . V_53 > V_2 -> V_23 &&
F_57 ( V_2 , V_150 . V_53 ) )
break;
V_2 -> V_23 -= V_150 . V_53 ;
V_43 -- ;
V_2 -> V_18 . V_32 = ++ V_3 ;
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
V_29 = 0 ;
if ( V_150 . V_33 & V_155 ) {
V_43 = F_52 ( V_2 , V_113 ,
& V_29 ,
V_43 ) ;
V_3 = V_2 -> V_18 . V_32 ;
if ( F_28 ( V_43 < 0 ) )
break;
}
if ( V_113 [ V_156 - 1 ] . type ) {
struct V_112 * V_114 ;
V_114 = & V_113 [ V_156 - 1 ] ;
V_148 = F_63 ( V_2 -> V_37 , V_114 -> V_99 . V_137 . V_135 ) ;
F_21 ( V_2 , & V_150 , V_29 ,
( V_148 == 0 ) ?
V_104 :
V_35 ) ;
F_22 ( V_2 ) ;
continue;
}
if ( V_113 [ V_157 - 1 ] . type ) {
struct V_112 * V_114 ;
V_114 = & V_113 [ V_157 - 1 ] ;
F_67 ( V_2 -> V_37 , V_114 -> V_99 . V_137 . V_135 ) ;
F_21 ( V_2 , & V_150 , V_29 ,
V_104 ) ;
F_22 ( V_2 ) ;
continue;
}
V_148 = F_27 ( V_2 , & V_150 , V_29 ,
V_151 , V_43 ) ;
if ( F_28 ( V_148 < 0 ) )
break;
V_3 += V_148 ;
if ( F_28 ( V_150 . V_53 < V_158 ) ) {
F_30 ( V_2 -> V_37 -> V_38 ,
L_18 , V_150 . V_53 ) ;
F_19 ( V_2 , & V_150 , V_29 , V_3 ) ;
break;
}
if ( F_28 ( ( V_150 . V_55 + V_150 . V_53 ) > V_56 ) ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_19 ,
V_150 . V_55 , V_150 . V_53 ,
( unsigned long ) ( V_150 . V_55 & ~ V_159 ) + V_150 . V_53 ) ;
F_25 ( V_2 -> V_37 ) ;
break;
}
V_81 = F_9 ( V_2 -> V_84 ) ;
V_7 = V_2 -> V_85 [ V_81 ] ;
V_110 = ( V_150 . V_53 > V_160 &&
V_148 < V_52 ) ?
V_160 : V_150 . V_53 ;
V_68 = F_33 ( V_110 ) ;
if ( F_28 ( V_68 == NULL ) ) {
F_30 ( V_2 -> V_37 -> V_38 ,
L_20 ) ;
F_19 ( V_2 , & V_150 , V_29 , V_3 ) ;
break;
}
F_36 ( V_68 ) -> V_83 = V_148 ;
if ( V_110 < V_150 . V_53 )
F_36 ( V_68 ) -> V_83 ++ ;
V_75 = 0 ;
V_76 = NULL ;
if ( F_36 ( V_68 ) -> V_83 > V_161 ) {
V_75 = F_36 ( V_68 ) -> V_83 - V_161 ;
F_84 ( V_75 > V_161 ) ;
F_36 ( V_68 ) -> V_83 = V_161 ;
V_76 = F_33 ( 0 ) ;
if ( F_28 ( V_76 == NULL ) ) {
F_85 ( V_68 ) ;
F_19 ( V_2 , & V_150 , V_29 , V_3 ) ;
if ( F_29 () )
F_26 ( V_2 -> V_37 -> V_38 ,
L_21 ) ;
break;
}
}
if ( V_113 [ V_162 - 1 ] . type ) {
struct V_112 * V_118 ;
V_118 = & V_113 [ V_162 - 1 ] ;
if ( F_53 ( V_2 -> V_37 , V_68 , V_118 ) ) {
F_85 ( V_68 ) ;
F_85 ( V_76 ) ;
break;
}
}
if ( V_113 [ V_163 - 1 ] . type ) {
struct V_112 * V_114 ;
enum V_164 type = V_165 ;
V_114 = & V_113 [ V_163 - 1 ] ;
switch ( V_114 -> V_99 . V_166 . type ) {
case V_167 :
case V_168 :
type = V_169 ;
break;
case V_170 :
case V_171 :
type = V_172 ;
break;
default:
break;
}
if ( type != V_165 )
F_86 ( V_68 ,
* ( V_173 * ) V_114 -> V_99 . V_166 . V_174 ,
type ) ;
}
F_38 ( V_68 ) -> V_7 = V_7 ;
F_87 ( V_68 , V_110 ) ;
V_2 -> V_175 [ * V_146 ] . V_98 . V_99 . V_100 = V_150 . V_64 ;
V_2 -> V_175 [ * V_146 ] . V_98 . V_65 = V_2 -> V_37 -> V_65 ;
V_2 -> V_175 [ * V_146 ] . V_98 . V_55 = V_150 . V_55 ;
V_2 -> V_175 [ * V_146 ] . V_176 . V_99 . V_177 =
F_88 ( V_68 -> V_26 ) ;
V_2 -> V_175 [ * V_146 ] . V_176 . V_65 = V_178 ;
V_2 -> V_175 [ * V_146 ] . V_176 . V_55 =
F_89 ( V_68 -> V_26 ) & ~ V_159 ;
V_2 -> V_175 [ * V_146 ] . V_109 = V_110 ;
V_2 -> V_175 [ * V_146 ] . V_33 = V_179 ;
( * V_146 ) ++ ;
if ( V_110 < V_150 . V_53 ) {
F_8 ( & F_36 ( V_68 ) -> V_79 [ 0 ] ,
V_7 ) ;
F_31 ( V_2 , V_7 , & V_150 ,
V_29 , V_74 ) ;
V_74 ++ ;
} else {
F_8 ( & F_36 ( V_68 ) -> V_79 [ 0 ] ,
V_106 ) ;
memcpy ( & V_2 -> V_9 [ V_7 ] . V_66 ,
& V_150 , sizeof( V_150 ) ) ;
V_2 -> V_9 [ V_7 ] . V_29 =
V_29 ;
}
V_2 -> V_84 ++ ;
V_74 = F_37 ( V_2 , V_68 , V_151 , V_74 ,
V_75 , V_76 ) ;
F_90 ( & V_2 -> V_149 , V_68 ) ;
V_2 -> V_18 . V_32 = V_3 ;
if ( ( ( V_74 - V_2 -> V_61 ) >= F_91 ( V_2 -> V_61 ) ) ||
( * V_146 >= F_91 ( V_2 -> V_175 ) ) )
break;
}
( * V_147 ) = V_74 - V_2 -> V_61 ;
return;
}
static int F_92 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
unsigned int V_55 = F_93 ( V_68 ) ;
T_2 V_79 [ V_161 ] ;
int V_14 , V_180 ;
struct V_5 * V_181 ;
struct V_67 * V_76 = F_36 ( V_68 ) -> V_86 ;
V_2 -> V_128 . V_182 += 2 ;
V_2 -> V_128 . V_183 ++ ;
F_47 ( V_2 , V_76 ) ;
V_68 -> V_111 -= V_68 -> V_110 ;
V_68 -> V_109 += V_76 -> V_109 ;
V_68 -> V_110 += V_76 -> V_109 ;
for ( V_14 = 0 ; V_55 < V_68 -> V_109 ; V_14 ++ ) {
struct V_107 * V_107 ;
unsigned int V_109 ;
F_84 ( V_14 >= V_161 ) ;
V_107 = F_94 ( V_71 ) ;
if ( ! V_107 ) {
int V_102 ;
V_68 -> V_111 += V_68 -> V_110 ;
for ( V_102 = 0 ; V_102 < V_14 ; V_102 ++ )
F_95 ( V_79 [ V_102 ] . V_107 . V_184 ) ;
return - V_141 ;
}
if ( V_55 + V_185 < V_68 -> V_109 )
V_109 = V_185 ;
else
V_109 = V_68 -> V_109 - V_55 ;
if ( F_96 ( V_68 , V_55 , F_97 ( V_107 ) , V_109 ) )
F_40 () ;
V_55 += V_109 ;
V_79 [ V_14 ] . V_107 . V_184 = V_107 ;
V_79 [ V_14 ] . V_13 = 0 ;
F_98 ( & V_79 [ V_14 ] , V_109 ) ;
}
F_99 ( V_68 ) ;
F_100 ( V_2 , V_76 ) ;
F_85 ( V_76 ) ;
for ( V_180 = 0 ; V_180 < F_36 ( V_68 ) -> V_83 ; V_180 ++ )
F_101 ( V_68 , V_180 ) ;
V_181 = F_36 ( V_68 ) -> V_73 ;
F_102 ( & V_2 -> V_186 ) ;
V_181 -> V_187 ( V_181 , true ) ;
F_36 ( V_68 ) -> V_73 = NULL ;
memcpy ( F_36 ( V_68 ) -> V_79 , V_79 , V_14 * sizeof( T_2 ) ) ;
F_36 ( V_68 ) -> V_83 = V_14 ;
V_68 -> V_111 += V_14 * V_185 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_58 * V_93 = V_2 -> V_61 ;
struct V_91 * V_188 = V_2 -> V_175 ;
struct V_67 * V_68 ;
int V_189 = 0 ;
while ( ( V_68 = F_104 ( & V_2 -> V_149 ) ) != NULL ) {
struct V_27 * V_28 ;
T_1 V_7 ;
unsigned V_110 ;
V_7 = F_38 ( V_68 ) -> V_7 ;
V_28 = & V_2 -> V_9 [ V_7 ] . V_66 ;
if ( F_28 ( F_42 ( V_2 , V_68 , & V_93 , & V_188 ) ) ) {
F_36 ( V_68 ) -> V_83 = 0 ;
if ( F_46 ( V_68 ) ) {
struct V_67 * V_76 =
F_36 ( V_68 ) -> V_86 ;
F_36 ( V_76 ) -> V_83 = 0 ;
}
F_85 ( V_68 ) ;
continue;
}
V_110 = V_68 -> V_109 ;
F_48 ( V_2 , V_7 ) . V_108 = NULL ;
if ( V_110 < V_28 -> V_53 ) {
V_28 -> V_55 += V_110 ;
V_28 -> V_53 -= V_110 ;
} else {
F_43 ( V_2 , V_7 ,
V_104 ) ;
}
if ( V_28 -> V_33 & V_190 )
V_68 -> V_126 = V_127 ;
else if ( V_28 -> V_33 & V_191 )
V_68 -> V_126 = V_192 ;
F_47 ( V_2 , V_68 ) ;
if ( F_28 ( F_46 ( V_68 ) ) ) {
if ( F_92 ( V_2 , V_68 ) ) {
if ( F_29 () )
F_26 ( V_2 -> V_37 -> V_38 ,
L_22 ) ;
F_100 ( V_2 , V_68 ) ;
F_85 ( V_68 ) ;
continue;
}
}
V_68 -> V_38 = V_2 -> V_37 -> V_38 ;
V_68 -> V_193 = F_105 ( V_68 , V_68 -> V_38 ) ;
F_106 ( V_68 ) ;
if ( F_54 ( V_2 , V_68 ) ) {
F_30 ( V_2 -> V_37 -> V_38 ,
L_23 ) ;
if ( F_36 ( V_68 ) -> V_73 )
F_100 ( V_2 , V_68 ) ;
F_85 ( V_68 ) ;
continue;
}
F_107 ( V_68 , 0 ) ;
if ( F_55 ( V_68 ) ) {
int V_194 = F_36 ( V_68 ) -> V_124 ;
int V_195 = F_108 ( V_68 ) -
F_109 ( V_68 ) +
F_110 ( V_68 ) ;
F_36 ( V_68 ) -> V_196 =
F_111 ( V_68 -> V_109 - V_195 , V_194 ) ;
}
V_2 -> V_128 . V_197 += V_68 -> V_109 ;
V_2 -> V_128 . V_198 ++ ;
V_189 ++ ;
if ( F_36 ( V_68 ) -> V_73 ) {
F_100 ( V_2 , V_68 ) ;
V_2 -> V_128 . V_182 ++ ;
}
F_112 ( V_68 ) ;
}
return V_189 ;
}
void F_113 ( struct V_5 * V_6 , bool V_199 )
{
unsigned long V_33 ;
T_3 V_81 ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
F_20 ( & V_2 -> V_200 , V_33 ) ;
do {
T_1 V_7 = V_6 -> V_8 ;
V_6 = (struct V_5 * ) V_6 -> V_108 ;
F_84 ( V_2 -> V_201 - V_2 -> V_202 >=
V_15 ) ;
V_81 = F_9 ( V_2 -> V_201 ) ;
V_2 -> V_203 [ V_81 ] = V_7 ;
F_114 () ;
V_2 -> V_201 ++ ;
} while ( V_6 );
F_23 ( & V_2 -> V_200 , V_33 ) ;
if ( F_44 ( V_199 ) )
V_2 -> V_128 . V_204 ++ ;
else
V_2 -> V_128 . V_205 ++ ;
F_115 ( V_2 ) ;
}
static inline void F_116 ( struct V_1 * V_2 )
{
struct V_206 * V_74 ;
T_3 V_207 , V_208 ;
T_1 V_7 , V_209 [ V_15 ] ;
unsigned int V_14 = 0 ;
V_207 = V_2 -> V_202 ;
V_74 = V_2 -> V_210 ;
do {
V_208 = V_2 -> V_201 ;
F_117 () ;
while ( V_207 != V_208 ) {
F_84 ( V_74 - V_2 -> V_210 >= V_15 ) ;
V_7 =
V_2 -> V_203 [ F_9 ( V_207 ++ ) ] ;
V_209 [ V_74 - V_2 -> V_210 ] =
V_7 ;
V_2 -> V_211 [ V_74 - V_2 -> V_210 ] =
V_2 -> V_4 [ V_7 ] ;
F_118 ( V_74 ,
F_3 ( V_2 , V_7 ) ,
V_62 ,
V_2 -> V_88 [ V_7 ] ) ;
F_41 ( V_2 , V_7 ) ;
++ V_74 ;
}
} while ( V_208 != V_2 -> V_201 );
V_2 -> V_202 = V_207 ;
if ( V_74 - V_2 -> V_210 > 0 ) {
int V_148 ;
V_148 = F_119 ( V_2 -> V_210 ,
NULL ,
V_2 -> V_211 ,
V_74 - V_2 -> V_210 ) ;
if ( V_148 ) {
F_26 ( V_2 -> V_37 -> V_38 , L_24 ,
V_74 - V_2 -> V_210 , V_148 ) ;
for ( V_14 = 0 ; V_14 < V_74 - V_2 -> V_210 ; ++ V_14 ) {
if ( V_74 [ V_14 ] . V_97 != V_212 )
F_26 ( V_2 -> V_37 -> V_38 ,
L_25 ,
V_74 [ V_14 ] . V_213 ,
V_74 [ V_14 ] . V_87 ,
V_74 [ V_14 ] . V_97 ) ;
}
F_40 () ;
}
}
for ( V_14 = 0 ; V_14 < V_74 - V_2 -> V_210 ; ++ V_14 )
F_43 ( V_2 , V_209 [ V_14 ] ,
V_104 ) ;
}
int F_120 ( struct V_1 * V_2 , int V_145 )
{
unsigned V_214 , V_215 = 0 ;
int V_189 , V_148 ;
if ( F_28 ( ! F_121 ( V_2 ) ) )
return 0 ;
F_80 ( V_2 , V_145 , & V_215 , & V_214 ) ;
if ( V_215 == 0 )
return 0 ;
F_122 ( V_2 -> V_175 , V_215 ) ;
if ( V_214 != 0 ) {
V_148 = F_123 ( V_2 -> V_61 ,
NULL ,
V_2 -> V_60 ,
V_214 ) ;
F_84 ( V_148 ) ;
}
V_189 = F_103 ( V_2 ) ;
return V_189 ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_7 ,
T_7 V_97 )
{
struct V_9 * V_9 ;
T_3 V_81 ;
unsigned long V_33 ;
V_9 = & V_2 -> V_9 [ V_7 ] ;
F_20 ( & V_2 -> V_34 , V_33 ) ;
F_21 ( V_2 , & V_9 -> V_66 ,
V_9 -> V_29 , V_97 ) ;
V_81 = F_9 ( V_2 -> V_216 ++ ) ;
V_2 -> V_85 [ V_81 ] = V_7 ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_34 , V_33 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned int V_29 ,
T_8 V_217 )
{
T_4 V_14 = V_2 -> V_18 . V_218 ;
struct V_219 * V_220 ;
V_220 = F_124 ( & V_2 -> V_18 , V_14 ) ;
V_220 -> V_221 = V_28 -> V_221 ;
V_220 -> V_97 = V_217 ;
while ( V_29 -- != 0 )
F_124 ( & V_2 -> V_18 , ++ V_14 ) -> V_97 = V_222 ;
V_2 -> V_18 . V_218 = ++ V_14 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_223 ;
F_125 ( & V_2 -> V_18 , V_223 ) ;
if ( V_223 )
F_126 ( V_2 -> V_224 ) ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_148 ;
struct V_206 V_225 ;
F_118 ( & V_225 ,
F_3 ( V_2 , V_7 ) ,
V_62 ,
V_2 -> V_88 [ V_7 ] ) ;
F_41 ( V_2 , V_7 ) ;
V_148 = F_119 ( & V_225 , NULL ,
& V_2 -> V_4 [ V_7 ] , 1 ) ;
if ( V_148 ) {
F_26 ( V_2 -> V_37 -> V_38 ,
L_26 ,
V_148 ,
V_7 ,
V_225 . V_213 ,
V_225 . V_87 ,
V_225 . V_97 ) ;
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
return V_2 -> V_202 != V_2 -> V_201 ;
}
void F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 . V_152 )
F_129 ( F_130 ( V_2 -> V_37 ) ,
V_2 -> V_18 . V_152 ) ;
if ( V_2 -> V_226 . V_152 )
F_129 ( F_130 ( V_2 -> V_37 ) ,
V_2 -> V_226 . V_152 ) ;
}
int F_131 ( struct V_1 * V_2 ,
T_9 V_227 ,
T_9 V_228 )
{
void * V_135 ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
int V_96 = - V_141 ;
V_96 = F_132 ( F_130 ( V_2 -> V_37 ) ,
& V_227 , 1 , & V_135 ) ;
if ( V_96 )
goto V_96;
V_230 = (struct V_229 * ) V_135 ;
F_133 ( & V_2 -> V_18 , V_230 , V_56 ) ;
V_96 = F_132 ( F_130 ( V_2 -> V_37 ) ,
& V_228 , 1 , & V_135 ) ;
if ( V_96 )
goto V_96;
V_232 = (struct V_231 * ) V_135 ;
F_133 ( & V_2 -> V_226 , V_232 , V_56 ) ;
return 0 ;
V_96:
F_128 ( V_2 ) ;
return V_96 ;
}
static bool F_134 ( struct V_1 * V_2 )
{
return F_135 () &&
! F_136 ( & V_2 -> V_186 ) ;
}
int F_137 ( void * V_26 )
{
struct V_1 * V_2 = V_26 ;
for (; ; ) {
F_138 ( V_2 -> V_233 ,
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
static void F_140 ( struct V_36 * V_37 ,
const struct V_234 * V_66 ,
V_173 V_97 , V_173 V_26 )
{
T_4 V_3 = V_37 -> V_235 . V_218 ;
struct V_236 V_237 = {
. V_221 = V_66 -> V_221 ,
. type = V_66 -> type ,
. V_97 = V_97 ,
. V_26 = V_26 ,
} ;
* F_124 ( & V_37 -> V_235 , V_3 ) = V_237 ;
V_37 -> V_235 . V_218 = ++ V_3 ;
}
static void F_141 ( struct V_36 * V_37 )
{
int V_223 ;
F_125 ( & V_37 -> V_235 , V_223 ) ;
if ( V_223 )
F_126 ( V_37 -> V_238 ) ;
}
static void F_142 ( struct V_36 * V_37 ,
const struct V_234 * V_66 )
{
V_173 V_97 = V_239 ;
V_173 V_26 = 0 ;
switch ( V_66 -> type ) {
case V_240 :
V_97 = F_143 ( V_37 , V_66 -> V_26 [ 0 ] ) ;
break;
case V_241 :
V_97 = F_144 ( V_37 , & V_26 ) ;
break;
case V_242 :
V_97 = F_145 ( V_37 , V_66 -> V_26 [ 0 ] ) ;
break;
case V_243 :
V_97 = F_146 ( V_37 , V_66 -> V_26 [ 0 ] ,
V_66 -> V_26 [ 1 ] ) ;
break;
case V_244 :
V_97 = V_245 ;
V_26 = V_246 ;
break;
case V_247 :
V_97 = F_147 ( V_37 ,
V_66 -> V_26 [ 0 ] ) ;
break;
case V_248 :
V_97 = F_148 ( V_37 , V_66 -> V_26 [ 0 ] ,
V_66 -> V_26 [ 1 ] ,
V_66 -> V_26 [ 2 ] ) ;
break;
default:
break;
}
F_140 ( V_37 , V_66 , V_97 , V_26 ) ;
F_141 ( V_37 ) ;
}
static void F_149 ( struct V_36 * V_37 )
{
for (; ; ) {
T_4 V_153 , V_32 ;
V_153 = V_37 -> V_235 . V_152 -> V_153 ;
V_32 = V_37 -> V_235 . V_32 ;
F_83 () ;
if ( V_32 == V_153 )
break;
while ( V_32 != V_153 ) {
struct V_234 V_66 ;
F_24 ( & V_37 -> V_235 , V_32 , & V_66 ) ;
V_32 ++ ;
F_142 ( V_37 , & V_66 ) ;
}
V_37 -> V_235 . V_32 = V_32 ;
V_37 -> V_235 . V_152 -> V_249 = V_32 + 1 ;
}
}
static bool F_150 ( struct V_36 * V_37 )
{
if ( F_44 ( F_82 ( & V_37 -> V_235 ) ) )
return 1 ;
return 0 ;
}
T_10 F_151 ( int V_250 , void * V_26 )
{
struct V_36 * V_37 = V_26 ;
while ( F_150 ( V_37 ) )
F_149 ( V_37 ) ;
return V_251 ;
}
static int T_11 F_152 ( void )
{
int V_252 = 0 ;
if ( ! F_153 () )
return - V_253 ;
if ( V_254 == 0 )
V_254 = F_154 (unsigned int, MAX_QUEUES_DEFAULT,
num_online_cpus()) ;
if ( V_50 < V_52 ) {
F_155 ( L_27 ,
V_50 , V_52 ) ;
V_50 = V_52 ;
}
V_252 = F_156 () ;
if ( V_252 )
goto V_255;
#ifdef F_157
V_256 = F_158 ( L_28 , NULL ) ;
if ( F_159 ( V_256 ) )
F_160 ( L_29 ,
F_161 ( V_256 ) ) ;
#endif
return 0 ;
V_255:
return V_252 ;
}
static void T_12 F_162 ( void )
{
#ifdef F_157
if ( ! F_159 ( V_256 ) )
F_163 ( V_256 ) ;
#endif
F_164 () ;
}
