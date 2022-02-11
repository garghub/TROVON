static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
unsigned long * V_5 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) ,
unsigned int log )
{
struct V_6 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 = F_3 ( V_7 ) ;
F_4 (sk2, node, &hslot->head)
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( V_5 || F_7 ( V_9 ) -> V_13 == V_2 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
V_9 -> V_15 == V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
! F_8 ( V_12 , F_3 ( V_9 ) ) ) &&
(* F_2)( V_7 , V_9 ) ) {
if ( V_5 )
F_9 ( F_7 ( V_9 ) -> V_13 >> log ,
V_5 ) ;
else
return 1 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_3 * V_17 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) )
{
struct V_6 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 = F_3 ( V_7 ) ;
int V_18 = 0 ;
F_11 ( & V_17 -> V_19 ) ;
F_12 (sk2, node, &hslot2->head)
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( F_7 ( V_9 ) -> V_13 == V_2 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
V_9 -> V_15 == V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
! F_8 ( V_12 , F_3 ( V_9 ) ) ) &&
(* F_2)( V_7 , V_9 ) ) {
V_18 = 1 ;
break;
}
F_13 ( & V_17 -> V_19 ) ;
return V_18 ;
}
int F_14 ( struct V_6 * V_7 , unsigned short V_20 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) ,
unsigned int V_21 )
{
struct V_3 * V_4 , * V_17 ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
int error = 1 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( ! V_20 ) {
int V_26 , V_27 , V_28 ;
unsigned int rand ;
unsigned short V_29 , V_30 ;
F_15 ( V_5 , V_31 ) ;
F_16 ( V_1 , & V_26 , & V_27 ) ;
V_28 = ( V_27 - V_26 ) + 1 ;
rand = F_17 () ;
V_29 = ( ( ( V_32 ) rand * V_28 ) >> 32 ) + V_26 ;
rand = ( rand | 1 ) * ( V_23 -> V_33 + 1 ) ;
V_30 = V_29 + V_23 -> V_33 + 1 ;
do {
V_4 = F_18 ( V_23 , V_1 , V_29 ) ;
F_19 ( V_5 , V_31 ) ;
F_20 ( & V_4 -> V_19 ) ;
F_1 ( V_1 , V_20 , V_4 , V_5 , V_7 ,
F_2 , V_23 -> log ) ;
V_20 = V_29 ;
do {
if ( V_26 <= V_20 && V_20 <= V_27 &&
! F_21 ( V_20 >> V_23 -> log , V_5 ) &&
! F_22 ( V_1 , V_20 ) )
goto V_34;
V_20 += rand ;
} while ( V_20 != V_29 );
F_23 ( & V_4 -> V_19 ) ;
} while ( ++ V_29 != V_30 );
goto V_35;
} else {
V_4 = F_18 ( V_23 , V_1 , V_20 ) ;
F_20 ( & V_4 -> V_19 ) ;
if ( V_4 -> V_36 > 10 ) {
int V_37 ;
unsigned int V_38 = F_7 ( V_7 ) -> V_39 ^ V_20 ;
V_38 &= V_23 -> V_33 ;
V_21 &= V_23 -> V_33 ;
V_17 = F_24 ( V_23 , V_38 ) ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_40;
V_37 = F_10 ( V_1 , V_20 , V_17 ,
V_7 , F_2 ) ;
if ( ! V_37 && ( V_21 != V_38 ) ) {
V_17 = F_24 ( V_23 , V_21 ) ;
V_37 = F_10 ( V_1 , V_20 , V_17 ,
V_7 , F_2 ) ;
}
if ( V_37 )
goto V_41;
else
goto V_34;
}
V_40:
if ( F_1 ( V_1 , V_20 , V_4 , NULL , V_7 ,
F_2 , 0 ) )
goto V_41;
}
V_34:
F_25 ( V_7 ) -> V_42 = V_20 ;
F_7 ( V_7 ) -> V_13 = V_20 ;
F_7 ( V_7 ) -> V_39 ^= V_20 ;
if ( F_26 ( V_7 ) ) {
F_27 ( V_7 , & V_4 -> V_43 ) ;
V_4 -> V_36 ++ ;
F_28 ( F_6 ( V_7 ) , V_7 -> V_24 , 1 ) ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_29 ( & F_7 ( V_7 ) -> V_44 ,
& V_17 -> V_43 ) ;
V_17 -> V_36 ++ ;
F_13 ( & V_17 -> V_19 ) ;
}
error = 0 ;
V_41:
F_23 ( & V_4 -> V_19 ) ;
V_35:
return error ;
}
static int F_30 ( const struct V_6 * V_8 , const struct V_6 * V_9 )
{
struct V_45 * V_46 = F_25 ( V_8 ) , * V_47 = F_25 ( V_9 ) ;
return ( ! F_31 ( V_9 ) &&
( ! V_46 -> V_48 || ! V_47 -> V_48 ||
V_46 -> V_48 == V_47 -> V_48 ) ) ;
}
static unsigned int F_32 ( struct V_1 * V_1 , T_3 V_49 ,
unsigned int V_50 )
{
return F_33 ( ( V_51 V_52 ) V_49 , F_34 ( V_1 ) ) ^ V_50 ;
}
int F_35 ( struct V_6 * V_7 , unsigned short V_20 )
{
unsigned int V_21 =
F_32 ( F_6 ( V_7 ) , F_36 ( V_53 ) , V_20 ) ;
unsigned int V_54 =
F_32 ( F_6 ( V_7 ) , F_25 ( V_7 ) -> V_48 , 0 ) ;
F_7 ( V_7 ) -> V_39 = V_54 ;
return F_14 ( V_7 , V_20 , F_30 , V_21 ) ;
}
static inline int F_37 ( struct V_6 * V_7 , struct V_1 * V_1 , T_3 V_49 ,
unsigned short V_55 ,
T_4 V_56 , T_3 V_57 , T_4 V_58 , int V_59 )
{
int V_60 = - 1 ;
if ( F_5 ( F_6 ( V_7 ) , V_1 ) && F_7 ( V_7 ) -> V_13 == V_55 &&
! F_31 ( V_7 ) ) {
struct V_45 * V_61 = F_25 ( V_7 ) ;
V_60 = ( V_7 -> V_62 == V_63 ? 2 : 1 ) ;
if ( V_61 -> V_48 ) {
if ( V_61 -> V_48 != V_57 )
return - 1 ;
V_60 += 4 ;
}
if ( V_61 -> V_64 ) {
if ( V_61 -> V_64 != V_49 )
return - 1 ;
V_60 += 4 ;
}
if ( V_61 -> V_65 ) {
if ( V_61 -> V_65 != V_56 )
return - 1 ;
V_60 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_59 )
return - 1 ;
V_60 += 4 ;
}
}
return V_60 ;
}
static inline int F_38 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_3 V_49 , T_4 V_56 ,
T_3 V_57 , unsigned int V_55 , int V_59 )
{
int V_60 = - 1 ;
if ( F_5 ( F_6 ( V_7 ) , V_1 ) && ! F_31 ( V_7 ) ) {
struct V_45 * V_61 = F_25 ( V_7 ) ;
if ( V_61 -> V_48 != V_57 )
return - 1 ;
if ( V_61 -> V_42 != V_55 )
return - 1 ;
V_60 = ( V_7 -> V_62 == V_63 ? 2 : 1 ) ;
if ( V_61 -> V_64 ) {
if ( V_61 -> V_64 != V_49 )
return - 1 ;
V_60 += 4 ;
}
if ( V_61 -> V_65 ) {
if ( V_61 -> V_65 != V_56 )
return - 1 ;
V_60 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_59 )
return - 1 ;
V_60 += 4 ;
}
}
return V_60 ;
}
static unsigned int F_39 ( struct V_1 * V_1 , const T_3 V_66 ,
const T_1 V_67 , const T_3 V_68 ,
const T_4 V_69 )
{
static V_52 T_5 V_70 ;
F_40 ( & T_5 , sizeof( T_5 ) ) ;
return F_41 ( V_66 , V_67 , V_68 , V_69 ,
T_5 + F_34 ( V_1 ) ) ;
}
static struct V_6 * F_42 ( struct V_1 * V_1 ,
T_3 V_49 , T_4 V_56 ,
T_3 V_57 , unsigned int V_55 , int V_59 ,
struct V_3 * V_17 , unsigned int V_38 )
{
struct V_6 * V_7 , * V_71 ;
struct V_10 * V_11 ;
int V_60 , V_72 , V_73 = 0 , V_74 = 0 ;
V_52 V_75 = 0 ;
V_76:
V_71 = NULL ;
V_72 = 0 ;
F_43 (sk, node, &hslot2->head) {
V_60 = F_38 ( V_7 , V_1 , V_49 , V_56 ,
V_57 , V_55 , V_59 ) ;
if ( V_60 > V_72 ) {
V_71 = V_7 ;
V_72 = V_60 ;
V_74 = V_7 -> V_16 ;
if ( V_74 ) {
V_75 = F_39 ( V_1 , V_57 , V_55 ,
V_49 , V_56 ) ;
V_73 = 1 ;
}
} else if ( V_60 == V_72 && V_74 ) {
V_73 ++ ;
if ( ( ( V_32 ) V_75 * V_73 ) >> 32 == 0 )
V_71 = V_7 ;
V_75 = F_44 ( V_75 ) ;
}
}
if ( F_45 ( V_11 ) != V_38 )
goto V_76;
if ( V_71 ) {
if ( F_46 ( ! F_47 ( & V_71 -> V_77 , 2 ) ) )
V_71 = NULL ;
else if ( F_46 ( F_38 ( V_71 , V_1 , V_49 , V_56 ,
V_57 , V_55 , V_59 ) < V_72 ) ) {
F_48 ( V_71 ) ;
goto V_76;
}
}
return V_71 ;
}
struct V_6 * F_49 ( struct V_1 * V_1 , T_3 V_49 ,
T_4 V_56 , T_3 V_57 , T_4 V_58 ,
int V_59 , struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_71 ;
struct V_10 * V_11 ;
unsigned short V_55 = F_50 ( V_58 ) ;
unsigned int V_78 , V_38 , V_79 = F_51 ( V_1 , V_55 , V_23 -> V_33 ) ;
struct V_3 * V_17 , * V_4 = & V_23 -> V_75 [ V_79 ] ;
int V_60 , V_72 , V_73 = 0 , V_74 = 0 ;
V_52 V_75 = 0 ;
F_52 () ;
if ( V_4 -> V_36 > 10 ) {
V_78 = F_32 ( V_1 , V_57 , V_55 ) ;
V_38 = V_78 & V_23 -> V_33 ;
V_17 = & V_23 -> V_78 [ V_38 ] ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_76;
V_71 = F_42 ( V_1 , V_49 , V_56 ,
V_57 , V_55 , V_59 ,
V_17 , V_38 ) ;
if ( ! V_71 ) {
V_78 = F_32 ( V_1 , F_36 ( V_53 ) , V_55 ) ;
V_38 = V_78 & V_23 -> V_33 ;
V_17 = & V_23 -> V_78 [ V_38 ] ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_76;
V_71 = F_42 ( V_1 , V_49 , V_56 ,
F_36 ( V_53 ) , V_55 , V_59 ,
V_17 , V_38 ) ;
}
F_53 () ;
return V_71 ;
}
V_76:
V_71 = NULL ;
V_72 = 0 ;
F_54 (sk, node, &hslot->head) {
V_60 = F_37 ( V_7 , V_1 , V_49 , V_55 , V_56 ,
V_57 , V_58 , V_59 ) ;
if ( V_60 > V_72 ) {
V_71 = V_7 ;
V_72 = V_60 ;
V_74 = V_7 -> V_16 ;
if ( V_74 ) {
V_75 = F_39 ( V_1 , V_57 , V_55 ,
V_49 , V_56 ) ;
V_73 = 1 ;
}
} else if ( V_60 == V_72 && V_74 ) {
V_73 ++ ;
if ( ( ( V_32 ) V_75 * V_73 ) >> 32 == 0 )
V_71 = V_7 ;
V_75 = F_44 ( V_75 ) ;
}
}
if ( F_45 ( V_11 ) != V_79 )
goto V_76;
if ( V_71 ) {
if ( F_46 ( ! F_47 ( & V_71 -> V_77 , 2 ) ) )
V_71 = NULL ;
else if ( F_46 ( F_37 ( V_71 , V_1 , V_49 , V_55 , V_56 ,
V_57 , V_58 , V_59 ) < V_72 ) ) {
F_48 ( V_71 ) ;
goto V_76;
}
}
F_53 () ;
return V_71 ;
}
static inline struct V_6 * F_55 ( struct V_80 * V_81 ,
T_4 V_56 , T_4 V_58 ,
struct V_22 * V_23 )
{
const struct V_82 * V_83 = F_56 ( V_81 ) ;
return F_49 ( F_57 ( F_58 ( V_81 ) -> V_84 ) , V_83 -> V_49 , V_56 ,
V_83 -> V_57 , V_58 , F_59 ( V_81 ) ,
V_23 ) ;
}
struct V_6 * F_60 ( struct V_1 * V_1 , T_3 V_49 , T_4 V_56 ,
T_3 V_57 , T_4 V_58 , int V_59 )
{
return F_49 ( V_1 , V_49 , V_56 , V_57 , V_58 , V_59 , & V_22 ) ;
}
static inline bool F_61 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_4 V_85 , T_3 V_86 ,
T_4 V_87 , T_3 V_88 ,
int V_59 , unsigned short V_55 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_13 != V_55 ||
( V_61 -> V_64 && V_61 -> V_64 != V_88 ) ||
( V_61 -> V_65 != V_87 && V_61 -> V_65 ) ||
( V_61 -> V_48 && V_61 -> V_48 != V_86 ) ||
F_31 ( V_7 ) ||
( V_7 -> V_15 && V_7 -> V_15 != V_59 ) )
return false ;
if ( ! F_62 ( V_7 , V_86 , V_88 , V_59 ) )
return false ;
return true ;
}
static inline struct V_6 * F_63 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_4 V_85 , T_3 V_86 ,
T_4 V_87 , T_3 V_88 ,
int V_59 )
{
struct V_10 * V_11 ;
struct V_6 * V_89 = V_7 ;
unsigned short V_55 = F_50 ( V_85 ) ;
F_64 (s, node) {
if ( F_61 ( V_1 , V_89 ,
V_85 , V_86 ,
V_87 , V_88 ,
V_59 , V_55 ) )
goto V_34;
}
V_89 = NULL ;
V_34:
return V_89 ;
}
void F_65 ( struct V_80 * V_81 , V_52 V_90 , struct V_22 * V_23 )
{
struct V_45 * V_61 ;
const struct V_82 * V_83 = ( const struct V_82 * ) V_81 -> V_91 ;
struct V_92 * V_93 = (struct V_92 * ) ( V_81 -> V_91 + ( V_83 -> V_94 << 2 ) ) ;
const int type = F_66 ( V_81 ) -> type ;
const int V_95 = F_66 ( V_81 ) -> V_95 ;
struct V_6 * V_7 ;
int V_96 ;
int V_97 ;
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
V_7 = F_49 ( V_1 , V_83 -> V_57 , V_93 -> V_98 ,
V_83 -> V_49 , V_93 -> V_99 , V_81 -> V_84 -> V_100 , V_23 ) ;
if ( V_7 == NULL ) {
F_67 ( V_1 , V_101 ) ;
return;
}
V_97 = 0 ;
V_96 = 0 ;
V_61 = F_25 ( V_7 ) ;
switch ( type ) {
default:
case V_102 :
V_97 = V_103 ;
break;
case V_104 :
goto V_105;
case V_106 :
V_97 = V_107 ;
V_96 = 1 ;
break;
case V_108 :
if ( V_95 == V_109 ) {
F_68 ( V_81 , V_7 , V_90 ) ;
if ( V_61 -> V_110 != V_111 ) {
V_97 = V_112 ;
V_96 = 1 ;
break;
}
goto V_105;
}
V_97 = V_103 ;
if ( V_95 <= V_113 ) {
V_96 = V_114 [ V_95 ] . V_115 ;
V_97 = V_114 [ V_95 ] . V_116 ;
}
break;
case V_117 :
F_69 ( V_81 , V_7 ) ;
goto V_105;
}
if ( ! V_61 -> V_118 ) {
if ( ! V_96 || V_7 -> V_119 != V_120 )
goto V_105;
} else
F_70 ( V_7 , V_81 , V_97 , V_93 -> V_98 , V_90 , ( V_121 * ) ( V_93 + 1 ) ) ;
V_7 -> V_122 = V_97 ;
V_7 -> V_123 ( V_7 ) ;
V_105:
F_48 ( V_7 ) ;
}
void F_71 ( struct V_80 * V_81 , V_52 V_90 )
{
F_65 ( V_81 , V_90 , & V_22 ) ;
}
void F_72 ( struct V_6 * V_7 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
if ( V_125 -> V_126 ) {
V_125 -> V_127 = 0 ;
V_125 -> V_126 = 0 ;
F_73 ( V_7 ) ;
}
}
void F_74 ( struct V_80 * V_81 , T_3 V_128 , T_3 V_129 )
{
struct V_92 * V_93 = F_75 ( V_81 ) ;
int V_130 = F_76 ( V_81 ) ;
int V_127 = V_81 -> V_127 - V_130 ;
int V_131 = V_127 ;
T_6 V_132 = 0 ;
if ( ! F_77 ( V_81 ) ) {
V_81 -> V_133 = F_78 ( V_81 ) - V_81 -> V_43 ;
V_81 -> V_134 = F_79 ( struct V_92 , V_135 ) ;
V_93 -> V_135 = ~ F_80 ( V_128 , V_129 , V_127 ,
V_136 , 0 ) ;
} else {
struct V_80 * V_137 ;
F_81 (skb, frags) {
V_132 = F_82 ( V_132 , V_137 -> V_132 ) ;
V_131 -= V_137 -> V_127 ;
}
V_132 = F_83 ( V_81 , V_130 , V_131 , V_132 ) ;
V_81 -> V_138 = V_139 ;
V_93 -> V_135 = F_80 ( V_128 , V_129 , V_127 , V_136 , V_132 ) ;
if ( V_93 -> V_135 == 0 )
V_93 -> V_135 = V_140 ;
}
}
void F_84 ( bool V_141 , struct V_80 * V_81 ,
T_3 V_49 , T_3 V_57 , int V_127 )
{
struct V_92 * V_93 = F_75 ( V_81 ) ;
if ( V_141 )
V_93 -> V_135 = 0 ;
else if ( F_85 ( V_81 ) )
V_93 -> V_135 = ~ F_86 ( V_127 , V_49 , V_57 , 0 ) ;
else if ( F_58 ( V_81 ) && F_58 ( V_81 ) -> V_84 &&
( F_58 ( V_81 ) -> V_84 -> V_142 & V_143 ) ) {
F_87 ( V_81 -> V_138 == V_144 ) ;
V_81 -> V_138 = V_144 ;
V_81 -> V_133 = F_78 ( V_81 ) - V_81 -> V_43 ;
V_81 -> V_134 = F_79 ( struct V_92 , V_135 ) ;
V_93 -> V_135 = ~ F_86 ( V_127 , V_49 , V_57 , 0 ) ;
} else {
T_6 V_132 ;
F_87 ( V_81 -> V_138 == V_144 ) ;
V_93 -> V_135 = 0 ;
V_132 = F_83 ( V_81 , 0 , V_127 , 0 ) ;
V_93 -> V_135 = F_86 ( V_127 , V_49 , V_57 , V_132 ) ;
if ( V_93 -> V_135 == 0 )
V_93 -> V_135 = V_140 ;
V_81 -> V_138 = V_145 ;
}
}
static int F_88 ( struct V_80 * V_81 , struct V_146 * V_147 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_92 * V_93 ;
int V_97 = 0 ;
int V_148 = F_89 ( V_7 ) ;
int V_130 = F_76 ( V_81 ) ;
int V_127 = V_81 -> V_127 - V_130 ;
T_6 V_132 = 0 ;
V_93 = F_75 ( V_81 ) ;
V_93 -> V_99 = V_61 -> V_149 ;
V_93 -> V_98 = V_147 -> V_150 ;
V_93 -> V_127 = F_90 ( V_127 ) ;
V_93 -> V_135 = 0 ;
if ( V_148 )
V_132 = F_91 ( V_81 ) ;
else if ( V_7 -> V_151 ) {
V_81 -> V_138 = V_139 ;
goto V_152;
} else if ( V_81 -> V_138 == V_144 ) {
F_74 ( V_81 , V_147 -> V_49 , V_147 -> V_57 ) ;
goto V_152;
} else
V_132 = F_92 ( V_81 ) ;
V_93 -> V_135 = F_80 ( V_147 -> V_49 , V_147 -> V_57 , V_127 ,
V_7 -> V_153 , V_132 ) ;
if ( V_93 -> V_135 == 0 )
V_93 -> V_135 = V_140 ;
V_152:
V_97 = F_93 ( F_6 ( V_7 ) , V_81 ) ;
if ( V_97 ) {
if ( V_97 == - V_154 && ! V_61 -> V_118 ) {
F_94 ( F_6 ( V_7 ) ,
V_155 , V_148 ) ;
V_97 = 0 ;
}
} else
F_94 ( F_6 ( V_7 ) ,
V_156 , V_148 ) ;
return V_97 ;
}
int F_95 ( struct V_6 * V_7 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_146 * V_147 = & V_61 -> V_157 . V_158 . V_159 . V_160 ;
struct V_80 * V_81 ;
int V_97 = 0 ;
V_81 = F_96 ( V_7 , V_147 ) ;
if ( ! V_81 )
goto V_105;
V_97 = F_88 ( V_81 , V_147 ) ;
V_105:
V_125 -> V_127 = 0 ;
V_125 -> V_126 = 0 ;
return V_97 ;
}
int F_97 ( struct V_161 * V_162 , struct V_6 * V_7 , struct V_163 * V_164 ,
T_7 V_127 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_124 * V_125 = F_7 ( V_7 ) ;
struct V_146 V_165 ;
struct V_146 * V_147 ;
int V_166 = V_127 ;
struct V_167 V_168 ;
struct V_169 * V_170 = NULL ;
int free = 0 ;
int V_171 = 0 ;
T_3 V_57 , V_68 , V_49 ;
T_4 V_58 ;
V_121 V_172 ;
int V_97 , V_148 = F_89 ( V_7 ) ;
int V_173 = V_125 -> V_174 || V_164 -> V_175 & V_176 ;
int (* F_98)( void * , char * , int , int , int , struct V_80 * );
struct V_80 * V_81 ;
struct V_177 V_178 ;
if ( V_127 > 0xFFFF )
return - V_112 ;
if ( V_164 -> V_175 & V_179 )
return - V_180 ;
V_168 . V_181 = NULL ;
V_168 . V_182 = 0 ;
V_168 . V_183 = 0 ;
V_168 . V_172 = - 1 ;
F_98 = V_148 ? V_184 : V_185 ;
V_147 = & V_61 -> V_157 . V_158 . V_159 . V_160 ;
if ( V_125 -> V_126 ) {
F_99 ( V_7 ) ;
if ( F_100 ( V_125 -> V_126 ) ) {
if ( F_46 ( V_125 -> V_126 != V_186 ) ) {
F_101 ( V_7 ) ;
return - V_187 ;
}
goto V_188;
}
F_101 ( V_7 ) ;
}
V_166 += sizeof( struct V_92 ) ;
if ( V_164 -> V_189 ) {
F_102 ( struct V_190 * , V_191 , V_164 -> V_189 ) ;
if ( V_164 -> V_192 < sizeof( * V_191 ) )
return - V_187 ;
if ( V_191 -> V_193 != V_186 ) {
if ( V_191 -> V_193 != V_194 )
return - V_195 ;
}
V_57 = V_191 -> V_196 . V_197 ;
V_58 = V_191 -> V_198 ;
if ( V_58 == 0 )
return - V_187 ;
} else {
if ( V_7 -> V_119 != V_120 )
return - V_199 ;
V_57 = V_61 -> V_64 ;
V_58 = V_61 -> V_65 ;
V_171 = 1 ;
}
V_168 . V_200 = V_61 -> V_201 ;
V_168 . V_202 = V_7 -> V_15 ;
F_103 ( V_7 , & V_168 . V_182 ) ;
if ( V_164 -> V_203 ) {
V_97 = F_104 ( F_6 ( V_7 ) , V_164 , & V_168 ,
V_7 -> V_62 == V_204 ) ;
if ( V_97 )
return V_97 ;
if ( V_168 . V_181 )
free = 1 ;
V_171 = 0 ;
}
if ( ! V_168 . V_181 ) {
struct V_205 * V_206 ;
F_52 () ;
V_206 = F_105 ( V_61 -> V_206 ) ;
if ( V_206 ) {
memcpy ( & V_178 , V_206 ,
sizeof( * V_206 ) + V_206 -> V_181 . V_207 ) ;
V_168 . V_181 = & V_178 . V_181 ;
}
F_53 () ;
}
V_49 = V_168 . V_200 ;
V_168 . V_200 = V_68 = V_57 ;
if ( V_168 . V_181 && V_168 . V_181 -> V_181 . V_208 ) {
if ( ! V_57 )
return - V_187 ;
V_68 = V_168 . V_181 -> V_181 . V_68 ;
V_171 = 0 ;
}
V_172 = F_106 ( & V_168 , V_61 ) ;
if ( F_107 ( V_7 , V_209 ) ||
( V_164 -> V_175 & V_210 ) ||
( V_168 . V_181 && V_168 . V_181 -> V_181 . V_211 ) ) {
V_172 |= V_212 ;
V_171 = 0 ;
}
if ( F_108 ( V_57 ) ) {
if ( ! V_168 . V_202 )
V_168 . V_202 = V_61 -> V_213 ;
if ( ! V_49 )
V_49 = V_61 -> V_214 ;
V_171 = 0 ;
} else if ( ! V_168 . V_202 )
V_168 . V_202 = V_61 -> V_215 ;
if ( V_171 )
V_170 = (struct V_169 * ) F_109 ( V_7 , 0 ) ;
if ( V_170 == NULL ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
V_147 = & V_165 ;
F_110 ( V_147 , V_168 . V_202 , V_7 -> V_216 , V_172 ,
V_217 , V_7 -> V_153 ,
F_111 ( V_7 ) ,
V_68 , V_49 , V_58 , V_61 -> V_149 ) ;
F_112 ( V_7 , F_113 ( V_147 ) ) ;
V_170 = F_114 ( V_1 , V_147 , V_7 ) ;
if ( F_115 ( V_170 ) ) {
V_97 = F_116 ( V_170 ) ;
V_170 = NULL ;
if ( V_97 == - V_218 )
F_117 ( V_1 , V_219 ) ;
goto V_105;
}
V_97 = - V_220 ;
if ( ( V_170 -> V_221 & V_222 ) &&
! F_107 ( V_7 , V_223 ) )
goto V_105;
if ( V_171 )
F_118 ( V_7 , F_119 ( & V_170 -> V_129 ) ) ;
}
if ( V_164 -> V_175 & V_224 )
goto V_225;
V_226:
V_49 = V_147 -> V_49 ;
if ( ! V_168 . V_200 )
V_57 = V_168 . V_200 = V_147 -> V_57 ;
if ( ! V_173 ) {
V_81 = F_120 ( V_7 , V_147 , F_98 , V_164 -> V_227 , V_166 ,
sizeof( struct V_92 ) , & V_168 , & V_170 ,
V_164 -> V_175 ) ;
V_97 = F_116 ( V_81 ) ;
if ( ! F_121 ( V_81 ) )
V_97 = F_88 ( V_81 , V_147 ) ;
goto V_105;
}
F_99 ( V_7 ) ;
if ( F_46 ( V_125 -> V_126 ) ) {
F_101 ( V_7 ) ;
F_122 (KERN_DEBUG pr_fmt(L_1)) ;
V_97 = - V_187 ;
goto V_105;
}
V_147 = & V_61 -> V_157 . V_158 . V_159 . V_160 ;
V_147 -> V_57 = V_57 ;
V_147 -> V_49 = V_49 ;
V_147 -> V_150 = V_58 ;
V_147 -> V_228 = V_61 -> V_149 ;
V_125 -> V_126 = V_186 ;
V_188:
V_125 -> V_127 += V_166 ;
V_97 = F_123 ( V_7 , V_147 , F_98 , V_164 -> V_227 , V_166 ,
sizeof( struct V_92 ) , & V_168 , & V_170 ,
V_173 ? V_164 -> V_175 | V_176 : V_164 -> V_175 ) ;
if ( V_97 )
F_72 ( V_7 ) ;
else if ( ! V_173 )
V_97 = F_95 ( V_7 ) ;
else if ( F_46 ( F_124 ( & V_7 -> V_229 ) ) )
V_125 -> V_126 = 0 ;
F_101 ( V_7 ) ;
V_105:
F_125 ( V_170 ) ;
if ( free )
F_126 ( V_168 . V_181 ) ;
if ( ! V_97 )
return V_127 ;
if ( V_97 == - V_154 || F_21 ( V_230 , & V_7 -> V_231 -> V_232 ) ) {
F_94 ( F_6 ( V_7 ) ,
V_155 , V_148 ) ;
}
return V_97 ;
V_225:
F_127 ( & V_170 -> V_129 ) ;
if ( ! ( V_164 -> V_175 & V_233 ) || V_127 )
goto V_226;
V_97 = 0 ;
goto V_105;
}
int F_128 ( struct V_6 * V_7 , struct V_234 * V_234 , int V_130 ,
T_7 V_235 , int V_232 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_236 ;
if ( V_232 & V_237 )
V_232 |= V_176 ;
if ( ! V_125 -> V_126 ) {
struct V_163 V_164 = { . V_175 = V_232 | V_176 } ;
V_236 = F_97 ( NULL , V_7 , & V_164 , 0 ) ;
if ( V_236 < 0 )
return V_236 ;
}
F_99 ( V_7 ) ;
if ( F_46 ( ! V_125 -> V_126 ) ) {
F_101 ( V_7 ) ;
F_122 (KERN_DEBUG pr_fmt(L_2)) ;
return - V_187 ;
}
V_236 = F_129 ( V_7 , & V_61 -> V_157 . V_158 . V_159 . V_160 ,
V_234 , V_130 , V_235 , V_232 ) ;
if ( V_236 == - V_180 ) {
F_101 ( V_7 ) ;
return F_130 ( V_7 -> V_231 , V_234 , V_130 ,
V_235 , V_232 ) ;
}
if ( V_236 < 0 ) {
F_72 ( V_7 ) ;
goto V_105;
}
V_125 -> V_127 += V_235 ;
if ( ! ( V_125 -> V_174 || ( V_232 & V_176 ) ) )
V_236 = F_95 ( V_7 ) ;
if ( ! V_236 )
V_236 = V_235 ;
V_105:
F_101 ( V_7 ) ;
return V_236 ;
}
static unsigned int F_131 ( struct V_6 * V_7 )
{
struct V_238 V_239 , * V_240 = & V_7 -> V_241 ;
struct V_80 * V_81 ;
unsigned int V_18 ;
F_132 ( & V_239 ) ;
F_20 ( & V_240 -> V_19 ) ;
while ( ( V_81 = F_133 ( V_240 ) ) != NULL &&
F_134 ( V_81 ) ) {
F_135 ( F_6 ( V_7 ) , V_242 ,
F_89 ( V_7 ) ) ;
F_135 ( F_6 ( V_7 ) , V_243 ,
F_89 ( V_7 ) ) ;
F_136 ( & V_7 -> V_244 ) ;
F_137 ( V_81 , V_240 ) ;
F_138 ( & V_239 , V_81 ) ;
}
V_18 = V_81 ? V_81 -> V_127 : 0 ;
F_23 ( & V_240 -> V_19 ) ;
if ( ! F_124 ( & V_239 ) ) {
bool V_245 = F_139 ( V_7 ) ;
F_140 ( & V_239 ) ;
F_141 ( V_7 ) ;
F_142 ( V_7 , V_245 ) ;
}
return V_18 ;
}
int F_143 ( struct V_6 * V_7 , int V_246 , unsigned long V_247 )
{
switch ( V_246 ) {
case V_248 :
{
int V_249 = F_144 ( V_7 ) ;
return F_145 ( V_249 , ( int V_250 * ) V_247 ) ;
}
case V_251 :
{
unsigned int V_249 = F_131 ( V_7 ) ;
if ( V_249 )
V_249 -= sizeof( struct V_92 ) ;
return F_145 ( V_249 , ( int V_250 * ) V_247 ) ;
}
default:
return - V_252 ;
}
return 0 ;
}
int F_146 ( struct V_161 * V_162 , struct V_6 * V_7 , struct V_163 * V_164 ,
T_7 V_127 , int V_253 , int V_232 , int * V_254 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
F_102 ( struct V_190 * , sin , V_164 -> V_189 ) ;
struct V_80 * V_81 ;
unsigned int V_166 , V_255 ;
int V_256 , V_257 = 0 ;
int V_97 ;
int V_148 = F_89 ( V_7 ) ;
bool V_245 ;
if ( V_232 & V_258 )
return F_147 ( V_7 , V_164 , V_127 , V_254 ) ;
V_259:
V_81 = F_148 ( V_7 , V_232 | ( V_253 ? V_260 : 0 ) ,
& V_256 , & V_257 , & V_97 ) ;
if ( ! V_81 )
goto V_105;
V_166 = V_81 -> V_127 - sizeof( struct V_92 ) ;
V_255 = V_127 ;
if ( V_255 > V_166 )
V_255 = V_166 ;
else if ( V_255 < V_166 )
V_164 -> V_175 |= V_261 ;
if ( V_255 < V_166 || F_149 ( V_81 ) -> V_262 ) {
if ( F_134 ( V_81 ) )
goto V_263;
}
if ( F_150 ( V_81 ) )
V_97 = F_151 ( V_81 , sizeof( struct V_92 ) ,
V_164 -> V_227 , V_255 ) ;
else {
V_97 = F_152 ( V_81 ,
sizeof( struct V_92 ) ,
V_164 -> V_227 ) ;
if ( V_97 == - V_187 )
goto V_263;
}
if ( F_46 ( V_97 ) ) {
F_153 ( V_81 , F_146 ) ;
if ( ! V_256 ) {
F_136 ( & V_7 -> V_244 ) ;
F_94 ( F_6 ( V_7 ) ,
V_243 , V_148 ) ;
}
goto V_264;
}
if ( ! V_256 )
F_94 ( F_6 ( V_7 ) ,
V_265 , V_148 ) ;
F_154 ( V_164 , V_7 , V_81 ) ;
if ( sin ) {
sin -> V_193 = V_186 ;
sin -> V_198 = F_75 ( V_81 ) -> V_99 ;
sin -> V_196 . V_197 = F_56 ( V_81 ) -> V_49 ;
memset ( sin -> V_266 , 0 , sizeof( sin -> V_266 ) ) ;
* V_254 = sizeof( * sin ) ;
}
if ( V_61 -> V_267 )
F_155 ( V_164 , V_81 ) ;
V_97 = V_255 ;
if ( V_232 & V_261 )
V_97 = V_166 ;
V_264:
F_156 ( V_7 , V_81 ) ;
V_105:
return V_97 ;
V_263:
V_245 = F_139 ( V_7 ) ;
if ( ! F_157 ( V_7 , V_81 , V_232 ) ) {
F_94 ( F_6 ( V_7 ) , V_242 , V_148 ) ;
F_94 ( F_6 ( V_7 ) , V_243 , V_148 ) ;
}
F_142 ( V_7 , V_245 ) ;
if ( V_253 )
return - V_268 ;
V_164 -> V_175 &= ~ V_261 ;
goto V_259;
}
int F_158 ( struct V_6 * V_7 , int V_232 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
V_7 -> V_119 = V_269 ;
V_61 -> V_64 = 0 ;
V_61 -> V_65 = 0 ;
F_159 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_270 & V_271 ) )
F_160 ( V_7 ) ;
if ( ! ( V_7 -> V_270 & V_272 ) ) {
V_7 -> V_24 -> V_273 ( V_7 ) ;
V_61 -> V_149 = 0 ;
}
F_161 ( V_7 ) ;
return 0 ;
}
void F_162 ( struct V_6 * V_7 )
{
if ( F_163 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
F_20 ( & V_4 -> V_19 ) ;
if ( F_164 ( V_7 ) ) {
V_4 -> V_36 -- ;
F_25 ( V_7 ) -> V_42 = 0 ;
F_28 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_165 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_23 ( & V_4 -> V_19 ) ;
}
}
void F_166 ( struct V_6 * V_7 , T_8 V_274 )
{
if ( F_163 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_275 ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
V_275 = F_24 ( V_23 , V_274 ) ;
F_7 ( V_7 ) -> V_39 = V_274 ;
if ( V_17 != V_275 ) {
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_20 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_165 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_275 -> V_19 ) ;
F_29 ( & F_7 ( V_7 ) -> V_44 ,
& V_275 -> V_43 ) ;
V_275 -> V_36 ++ ;
F_13 ( & V_275 -> V_19 ) ;
F_23 ( & V_4 -> V_19 ) ;
}
}
}
static void F_167 ( struct V_6 * V_7 )
{
T_8 V_276 = F_32 ( F_6 ( V_7 ) ,
F_25 ( V_7 ) -> V_48 ,
F_25 ( V_7 ) -> V_42 ) ;
F_166 ( V_7 , V_276 ) ;
}
static int F_168 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
int V_277 ;
if ( F_25 ( V_7 ) -> V_64 ) {
F_169 ( V_7 , V_81 ) ;
F_170 ( V_7 , V_81 ) ;
}
V_277 = F_171 ( V_7 , V_81 ) ;
if ( V_277 < 0 ) {
int V_148 = F_89 ( V_7 ) ;
if ( V_277 == - V_278 )
F_135 ( F_6 ( V_7 ) , V_279 ,
V_148 ) ;
F_135 ( F_6 ( V_7 ) , V_243 , V_148 ) ;
F_172 ( V_81 ) ;
F_173 ( V_277 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_174 ( void )
{
if ( ! F_175 ( & V_280 ) )
F_176 ( & V_280 ) ;
}
int F_177 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_277 ;
int V_148 = F_89 ( V_7 ) ;
if ( ! F_178 ( V_7 , V_281 , V_81 ) )
goto V_282;
F_179 ( V_81 ) ;
if ( F_180 ( & V_280 ) && V_125 -> V_283 ) {
int (* F_181)( struct V_6 * V_7 , struct V_80 * V_81 );
F_181 = F_182 ( V_125 -> F_181 ) ;
if ( V_81 -> V_127 > sizeof( struct V_92 ) && F_181 != NULL ) {
int V_236 ;
if ( F_134 ( V_81 ) )
goto V_284;
V_236 = F_181 ( V_7 , V_81 ) ;
if ( V_236 <= 0 ) {
F_135 ( F_6 ( V_7 ) ,
V_265 ,
V_148 ) ;
return - V_236 ;
}
}
}
if ( ( V_148 & V_285 ) && F_149 ( V_81 ) -> V_262 ) {
if ( V_125 -> V_286 == 0 ) {
F_122 ( V_287 L_3 ,
F_149 ( V_81 ) -> V_288 , V_81 -> V_127 ) ;
goto V_282;
}
if ( F_149 ( V_81 ) -> V_288 < V_125 -> V_286 ) {
F_122 ( V_287 L_4 ,
F_149 ( V_81 ) -> V_288 , V_125 -> V_286 ) ;
goto V_282;
}
}
if ( F_183 ( V_7 -> V_289 ) &&
F_134 ( V_81 ) )
goto V_284;
if ( F_184 ( V_7 , V_81 , V_7 -> V_290 ) ) {
F_135 ( F_6 ( V_7 ) , V_279 ,
V_148 ) ;
goto V_282;
}
V_277 = 0 ;
F_185 ( V_7 , V_81 ) ;
F_186 ( V_7 ) ;
if ( ! F_187 ( V_7 ) )
V_277 = F_168 ( V_7 , V_81 ) ;
else if ( F_188 ( V_7 , V_81 , V_7 -> V_290 ) ) {
F_189 ( V_7 ) ;
goto V_282;
}
F_189 ( V_7 ) ;
return V_277 ;
V_284:
F_135 ( F_6 ( V_7 ) , V_242 , V_148 ) ;
V_282:
F_135 ( F_6 ( V_7 ) , V_243 , V_148 ) ;
F_136 ( & V_7 -> V_244 ) ;
F_172 ( V_81 ) ;
return - 1 ;
}
static void F_190 ( struct V_6 * * V_291 , unsigned int V_36 ,
struct V_80 * V_81 , unsigned int V_292 )
{
unsigned int V_293 ;
struct V_80 * V_294 = NULL ;
struct V_6 * V_7 ;
for ( V_293 = 0 ; V_293 < V_36 ; V_293 ++ ) {
V_7 = V_291 [ V_293 ] ;
if ( F_100 ( V_294 == NULL ) )
V_294 = ( V_293 == V_292 ) ? V_81 : F_191 ( V_81 , V_295 ) ;
if ( ! V_294 ) {
F_136 ( & V_7 -> V_244 ) ;
F_135 ( F_6 ( V_7 ) , V_279 ,
F_89 ( V_7 ) ) ;
F_135 ( F_6 ( V_7 ) , V_243 ,
F_89 ( V_7 ) ) ;
}
if ( V_294 && F_177 ( V_7 , V_294 ) <= 0 )
V_294 = NULL ;
}
if ( F_46 ( V_294 ) )
F_172 ( V_294 ) ;
}
static void F_192 ( struct V_6 * V_7 , struct V_296 * V_129 )
{
struct V_296 * V_297 ;
F_193 ( V_129 ) ;
V_297 = F_194 ( & V_7 -> V_298 , V_129 ) ;
F_195 ( V_297 ) ;
}
static int F_196 ( struct V_1 * V_1 , struct V_80 * V_81 ,
struct V_92 * V_93 ,
T_3 V_49 , T_3 V_57 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_291 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_3 * V_4 = F_18 ( V_23 , V_1 , F_50 ( V_93 -> V_98 ) ) ;
int V_59 ;
unsigned int V_293 , V_36 = 0 ;
F_11 ( & V_4 -> V_19 ) ;
V_7 = F_197 ( & V_4 -> V_43 ) ;
V_59 = V_81 -> V_84 -> V_100 ;
V_7 = F_63 ( V_1 , V_7 , V_93 -> V_98 , V_57 , V_93 -> V_99 , V_49 , V_59 ) ;
while ( V_7 ) {
V_291 [ V_36 ++ ] = V_7 ;
V_7 = F_63 ( V_1 , F_198 ( V_7 ) , V_93 -> V_98 ,
V_57 , V_93 -> V_99 , V_49 , V_59 ) ;
if ( F_46 ( V_36 == F_199 ( V_291 ) ) ) {
if ( ! V_7 )
break;
F_190 ( V_291 , V_36 , V_81 , ~ 0 ) ;
V_36 = 0 ;
}
}
for ( V_293 = 0 ; V_293 < V_36 ; V_293 ++ )
F_200 ( V_291 [ V_293 ] ) ;
F_13 ( & V_4 -> V_19 ) ;
if ( V_36 ) {
F_190 ( V_291 , V_36 , V_81 , V_36 - 1 ) ;
for ( V_293 = 0 ; V_293 < V_36 ; V_293 ++ )
F_48 ( V_291 [ V_293 ] ) ;
} else {
F_172 ( V_81 ) ;
}
return 0 ;
}
static inline int F_201 ( struct V_80 * V_81 , struct V_92 * V_93 ,
int V_299 )
{
int V_97 ;
F_149 ( V_81 ) -> V_262 = 0 ;
F_149 ( V_81 ) -> V_288 = V_81 -> V_127 ;
if ( V_299 == V_300 ) {
V_97 = F_202 ( V_81 , V_93 ) ;
if ( V_97 )
return V_97 ;
}
return F_203 ( V_81 , V_299 , V_93 -> V_135 ,
V_301 ) ;
}
int F_204 ( struct V_80 * V_81 , struct V_22 * V_23 ,
int V_299 )
{
struct V_6 * V_7 ;
struct V_92 * V_93 ;
unsigned short V_166 ;
struct V_169 * V_170 = F_205 ( V_81 ) ;
T_3 V_49 , V_57 ;
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
if ( ! F_206 ( V_81 , sizeof( struct V_92 ) ) )
goto V_282;
V_93 = F_75 ( V_81 ) ;
V_166 = F_50 ( V_93 -> V_127 ) ;
V_49 = F_56 ( V_81 ) -> V_49 ;
V_57 = F_56 ( V_81 ) -> V_57 ;
if ( V_166 > V_81 -> V_127 )
goto V_302;
if ( V_299 == V_136 ) {
if ( V_166 < sizeof( * V_93 ) || F_207 ( V_81 , V_166 ) )
goto V_302;
V_93 = F_75 ( V_81 ) ;
}
if ( F_201 ( V_81 , V_93 , V_299 ) )
goto V_284;
V_7 = F_208 ( V_81 ) ;
if ( V_7 ) {
struct V_296 * V_129 = F_58 ( V_81 ) ;
int V_236 ;
if ( F_46 ( V_7 -> V_298 != V_129 ) )
F_192 ( V_7 , V_129 ) ;
V_236 = F_177 ( V_7 , V_81 ) ;
F_48 ( V_7 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
} else {
if ( V_170 -> V_221 & ( V_222 | V_303 ) )
return F_196 ( V_1 , V_81 , V_93 ,
V_49 , V_57 , V_23 ) ;
V_7 = F_55 ( V_81 , V_93 -> V_99 , V_93 -> V_98 , V_23 ) ;
}
if ( V_7 != NULL ) {
int V_236 ;
V_236 = F_177 ( V_7 , V_81 ) ;
F_48 ( V_7 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( ! F_178 ( NULL , V_281 , V_81 ) )
goto V_282;
F_179 ( V_81 ) ;
if ( F_134 ( V_81 ) )
goto V_284;
F_135 ( V_1 , V_304 , V_299 == V_300 ) ;
F_209 ( V_81 , V_108 , V_305 , 0 ) ;
F_172 ( V_81 ) ;
return 0 ;
V_302:
F_122 ( V_306 L_5 ,
V_299 == V_300 ? L_6 : L_7 ,
& V_49 , F_50 ( V_93 -> V_99 ) ,
V_166 , V_81 -> V_127 ,
& V_57 , F_50 ( V_93 -> V_98 ) ) ;
goto V_282;
V_284:
F_122 ( V_306 L_8 ,
V_299 == V_300 ? L_6 : L_7 ,
& V_49 , F_50 ( V_93 -> V_99 ) , & V_57 , F_50 ( V_93 -> V_98 ) ,
V_166 ) ;
F_135 ( V_1 , V_242 , V_299 == V_300 ) ;
V_282:
F_135 ( V_1 , V_243 , V_299 == V_300 ) ;
F_172 ( V_81 ) ;
return 0 ;
}
static struct V_6 * F_210 ( struct V_1 * V_1 ,
T_4 V_85 , T_3 V_86 ,
T_4 V_87 , T_3 V_88 ,
int V_59 )
{
struct V_6 * V_7 , * V_71 ;
struct V_10 * V_11 ;
unsigned short V_55 = F_50 ( V_85 ) ;
unsigned int V_36 , V_79 = F_51 ( V_1 , V_55 , V_22 . V_33 ) ;
struct V_3 * V_4 = & V_22 . V_75 [ V_79 ] ;
if ( V_4 -> V_36 > 10 )
return NULL ;
F_52 () ;
V_76:
V_36 = 0 ;
V_71 = NULL ;
F_54 (sk, node, &hslot->head) {
if ( F_61 ( V_1 , V_7 ,
V_85 , V_86 ,
V_87 , V_88 ,
V_59 , V_55 ) ) {
V_71 = V_7 ;
++ V_36 ;
}
}
if ( F_45 ( V_11 ) != V_79 )
goto V_76;
if ( V_71 ) {
if ( V_36 != 1 ||
F_46 ( ! F_47 ( & V_71 -> V_77 , 2 ) ) )
V_71 = NULL ;
else if ( F_46 ( ! F_61 ( V_1 , V_71 ,
V_85 , V_86 ,
V_87 , V_88 ,
V_59 , V_55 ) ) ) {
F_48 ( V_71 ) ;
V_71 = NULL ;
}
}
F_53 () ;
return V_71 ;
}
static struct V_6 * F_211 ( struct V_1 * V_1 ,
T_4 V_85 , T_3 V_86 ,
T_4 V_87 , T_3 V_88 ,
int V_59 )
{
struct V_6 * V_7 , * V_71 ;
struct V_10 * V_11 ;
unsigned short V_55 = F_50 ( V_85 ) ;
unsigned int V_78 = F_32 ( V_1 , V_86 , V_55 ) ;
unsigned int V_38 = V_78 & V_22 . V_33 ;
struct V_3 * V_17 = & V_22 . V_78 [ V_38 ] ;
F_212 ( V_307 , V_88 , V_86 ) ;
const T_9 V_308 = F_213 ( V_87 , V_55 ) ;
F_52 () ;
V_71 = NULL ;
F_43 (sk, node, &hslot2->head) {
if ( F_214 ( V_7 , V_1 , V_307 ,
V_88 , V_86 , V_308 , V_59 ) )
V_71 = V_7 ;
break;
}
if ( V_71 ) {
if ( F_46 ( ! F_47 ( & V_71 -> V_77 , 2 ) ) )
V_71 = NULL ;
else if ( F_46 ( ! F_214 ( V_7 , V_1 , V_307 ,
V_88 , V_86 ,
V_308 , V_59 ) ) ) {
F_48 ( V_71 ) ;
V_71 = NULL ;
}
}
F_53 () ;
return V_71 ;
}
void F_215 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
const struct V_82 * V_83 ;
const struct V_92 * V_93 ;
struct V_6 * V_7 ;
struct V_296 * V_129 ;
int V_59 = V_81 -> V_84 -> V_100 ;
if ( ! F_206 ( V_81 , F_76 ( V_81 ) + sizeof( struct V_92 ) ) )
return;
V_83 = F_56 ( V_81 ) ;
V_93 = F_75 ( V_81 ) ;
if ( V_81 -> V_309 == V_310 ||
V_81 -> V_309 == V_311 )
V_7 = F_210 ( V_1 , V_93 -> V_98 , V_83 -> V_57 ,
V_93 -> V_99 , V_83 -> V_49 , V_59 ) ;
else if ( V_81 -> V_309 == V_312 )
V_7 = F_211 ( V_1 , V_93 -> V_98 , V_83 -> V_57 ,
V_93 -> V_99 , V_83 -> V_49 , V_59 ) ;
else
return;
if ( ! V_7 )
return;
V_81 -> V_7 = V_7 ;
V_81 -> V_313 = V_314 ;
V_129 = V_7 -> V_298 ;
if ( V_129 )
V_129 = F_216 ( V_129 , 0 ) ;
if ( V_129 )
F_217 ( V_81 , V_129 ) ;
}
int F_218 ( struct V_80 * V_81 )
{
return F_204 ( V_81 , & V_22 , V_136 ) ;
}
void F_219 ( struct V_6 * V_7 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
bool V_245 = F_139 ( V_7 ) ;
F_72 ( V_7 ) ;
F_142 ( V_7 , V_245 ) ;
if ( F_180 ( & V_280 ) && V_125 -> V_283 ) {
void (* F_220)( struct V_6 * V_7 );
F_220 = F_182 ( V_125 -> F_220 ) ;
if ( F_220 )
F_220 ( V_7 ) ;
}
}
int F_221 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_250 * V_317 , unsigned int V_207 ,
int (* F_222)( struct V_6 * ) )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_318 , V_319 ;
int V_97 = 0 ;
int V_148 = F_89 ( V_7 ) ;
if ( V_207 < sizeof( int ) )
return - V_187 ;
if ( F_223 ( V_318 , ( int V_250 * ) V_317 ) )
return - V_320 ;
V_319 = V_318 ? 1 : 0 ;
switch ( V_316 ) {
case V_321 :
if ( V_318 != 0 ) {
V_125 -> V_174 = 1 ;
} else {
V_125 -> V_174 = 0 ;
F_99 ( V_7 ) ;
(* F_222)( V_7 ) ;
F_101 ( V_7 ) ;
}
break;
case V_322 :
switch ( V_318 ) {
case 0 :
case V_323 :
case V_324 :
V_125 -> F_181 = V_325 ;
case V_326 :
V_125 -> V_283 = V_318 ;
F_174 () ;
break;
default:
V_97 = - V_327 ;
break;
}
break;
case V_328 :
V_125 -> V_329 = V_319 ;
break;
case V_330 :
V_125 -> V_331 = V_319 ;
break;
case V_332 :
if ( ! V_148 )
return - V_327 ;
if ( V_318 != 0 && V_318 < 8 )
V_318 = 8 ;
else if ( V_318 > V_333 )
V_318 = V_333 ;
V_125 -> V_334 = V_318 ;
V_125 -> V_335 |= V_336 ;
break;
case V_337 :
if ( ! V_148 )
return - V_327 ;
if ( V_318 != 0 && V_318 < 8 )
V_318 = 8 ;
else if ( V_318 > V_333 )
V_318 = V_333 ;
V_125 -> V_286 = V_318 ;
V_125 -> V_335 |= V_285 ;
break;
default:
V_97 = - V_327 ;
break;
}
return V_97 ;
}
int F_224 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_250 * V_317 , unsigned int V_207 )
{
if ( V_315 == V_338 || V_315 == V_339 )
return F_221 ( V_7 , V_315 , V_316 , V_317 , V_207 ,
F_95 ) ;
return F_225 ( V_7 , V_315 , V_316 , V_317 , V_207 ) ;
}
int F_226 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_250 * V_317 , unsigned int V_207 )
{
if ( V_315 == V_338 || V_315 == V_339 )
return F_221 ( V_7 , V_315 , V_316 , V_317 , V_207 ,
F_95 ) ;
return F_227 ( V_7 , V_315 , V_316 , V_317 , V_207 ) ;
}
int F_228 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_250 * V_317 , int V_250 * V_207 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_318 , V_127 ;
if ( F_223 ( V_127 , V_207 ) )
return - V_320 ;
V_127 = F_229 (unsigned int, len, sizeof(int)) ;
if ( V_127 < 0 )
return - V_187 ;
switch ( V_316 ) {
case V_321 :
V_318 = V_125 -> V_174 ;
break;
case V_322 :
V_318 = V_125 -> V_283 ;
break;
case V_328 :
V_318 = V_125 -> V_329 ;
break;
case V_330 :
V_318 = V_125 -> V_331 ;
break;
case V_332 :
V_318 = V_125 -> V_334 ;
break;
case V_337 :
V_318 = V_125 -> V_286 ;
break;
default:
return - V_327 ;
}
if ( F_145 ( V_127 , V_207 ) )
return - V_320 ;
if ( F_230 ( V_317 , & V_318 , V_127 ) )
return - V_320 ;
return 0 ;
}
int F_231 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_250 * V_317 , int V_250 * V_207 )
{
if ( V_315 == V_338 || V_315 == V_339 )
return F_228 ( V_7 , V_315 , V_316 , V_317 , V_207 ) ;
return F_232 ( V_7 , V_315 , V_316 , V_317 , V_207 ) ;
}
int F_233 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_250 * V_317 , int V_250 * V_207 )
{
if ( V_315 == V_338 || V_315 == V_339 )
return F_228 ( V_7 , V_315 , V_316 , V_317 , V_207 ) ;
return F_234 ( V_7 , V_315 , V_316 , V_317 , V_207 ) ;
}
unsigned int F_235 ( struct V_340 * V_340 , struct V_341 * V_6 , T_10 * V_342 )
{
unsigned int V_33 = F_236 ( V_340 , V_6 , V_342 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_237 ( V_7 ) ;
if ( ( V_33 & V_343 ) && ! ( V_340 -> V_344 & V_345 ) &&
! ( V_7 -> V_346 & V_347 ) && ! F_131 ( V_7 ) )
V_33 &= ~ ( V_348 | V_343 ) ;
return V_33 ;
}
static struct V_6 * F_238 ( struct V_349 * V_350 , int V_351 )
{
struct V_6 * V_7 ;
struct V_352 * V_353 = V_350 -> V_354 ;
struct V_1 * V_1 = F_239 ( V_350 ) ;
for ( V_353 -> V_355 = V_351 ; V_353 -> V_355 <= V_353 -> V_22 -> V_33 ;
++ V_353 -> V_355 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_353 -> V_22 -> V_75 [ V_353 -> V_355 ] ;
if ( F_240 ( & V_4 -> V_43 ) )
continue;
F_20 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_62 == V_353 -> V_356 )
goto V_34;
}
F_23 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_34:
return V_7 ;
}
static struct V_6 * F_241 ( struct V_349 * V_350 , struct V_6 * V_7 )
{
struct V_352 * V_353 = V_350 -> V_354 ;
struct V_1 * V_1 = F_239 ( V_350 ) ;
do {
V_7 = F_198 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_62 != V_353 -> V_356 ) );
if ( ! V_7 ) {
if ( V_353 -> V_355 <= V_353 -> V_22 -> V_33 )
F_23 ( & V_353 -> V_22 -> V_75 [ V_353 -> V_355 ] . V_19 ) ;
return F_238 ( V_350 , V_353 -> V_355 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_242 ( struct V_349 * V_350 , T_11 V_357 )
{
struct V_6 * V_7 = F_238 ( V_350 , 0 ) ;
if ( V_7 )
while ( V_357 && ( V_7 = F_241 ( V_350 , V_7 ) ) != NULL )
-- V_357 ;
return V_357 ? NULL : V_7 ;
}
static void * F_243 ( struct V_349 * V_350 , T_11 * V_357 )
{
struct V_352 * V_353 = V_350 -> V_354 ;
V_353 -> V_355 = V_358 ;
return * V_357 ? F_242 ( V_350 , * V_357 - 1 ) : V_359 ;
}
static void * F_244 ( struct V_349 * V_350 , void * V_360 , T_11 * V_357 )
{
struct V_6 * V_7 ;
if ( V_360 == V_359 )
V_7 = F_242 ( V_350 , 0 ) ;
else
V_7 = F_241 ( V_350 , V_360 ) ;
++ * V_357 ;
return V_7 ;
}
static void F_245 ( struct V_349 * V_350 , void * V_360 )
{
struct V_352 * V_353 = V_350 -> V_354 ;
if ( V_353 -> V_355 <= V_353 -> V_22 -> V_33 )
F_23 ( & V_353 -> V_22 -> V_75 [ V_353 -> V_355 ] . V_19 ) ;
}
int F_246 ( struct V_361 * V_361 , struct V_340 * V_340 )
{
struct V_362 * V_363 = F_247 ( V_361 ) ;
struct V_352 * V_89 ;
int V_97 ;
V_97 = F_248 ( V_361 , V_340 , & V_363 -> V_364 ,
sizeof( struct V_352 ) ) ;
if ( V_97 < 0 )
return V_97 ;
V_89 = ( (struct V_349 * ) V_340 -> V_365 ) -> V_354 ;
V_89 -> V_356 = V_363 -> V_356 ;
V_89 -> V_22 = V_363 -> V_22 ;
return V_97 ;
}
int F_249 ( struct V_1 * V_1 , struct V_362 * V_363 )
{
struct V_366 * V_367 ;
int V_277 = 0 ;
V_363 -> V_364 . V_351 = F_243 ;
V_363 -> V_364 . V_368 = F_244 ;
V_363 -> V_364 . V_369 = F_245 ;
V_367 = F_250 ( V_363 -> V_370 , V_371 , V_1 -> V_372 ,
V_363 -> V_373 , V_363 ) ;
if ( ! V_367 )
V_277 = - V_278 ;
return V_277 ;
}
void F_251 ( struct V_1 * V_1 , struct V_362 * V_363 )
{
F_252 ( V_363 -> V_370 , V_1 -> V_372 ) ;
}
static void F_253 ( struct V_6 * V_374 , struct V_349 * V_375 ,
int V_355 )
{
struct V_45 * V_61 = F_25 ( V_374 ) ;
T_3 V_98 = V_61 -> V_64 ;
T_3 V_128 = V_61 -> V_48 ;
T_1 V_376 = F_50 ( V_61 -> V_65 ) ;
T_1 V_377 = F_50 ( V_61 -> V_149 ) ;
F_254 ( V_375 , L_9
L_10 ,
V_355 , V_128 , V_377 , V_98 , V_376 , V_374 -> V_119 ,
F_144 ( V_374 ) ,
F_255 ( V_374 ) ,
0 , 0L , 0 ,
F_256 ( F_257 ( V_375 ) , F_3 ( V_374 ) ) ,
0 , F_258 ( V_374 ) ,
F_259 ( & V_374 -> V_77 ) , V_374 ,
F_259 ( & V_374 -> V_244 ) ) ;
}
int F_260 ( struct V_349 * V_350 , void * V_360 )
{
F_261 ( V_350 , 127 ) ;
if ( V_360 == V_359 )
F_262 ( V_350 , L_11
L_12
L_13 ) ;
else {
struct V_352 * V_353 = V_350 -> V_354 ;
F_253 ( V_360 , V_350 , V_353 -> V_355 ) ;
}
F_263 ( V_350 , '\n' ) ;
return 0 ;
}
static int T_12 F_264 ( struct V_1 * V_1 )
{
return F_249 ( V_1 , & V_378 ) ;
}
static void T_13 F_265 ( struct V_1 * V_1 )
{
F_251 ( V_1 , & V_378 ) ;
}
int T_14 F_266 ( void )
{
return F_267 ( & V_379 ) ;
}
void F_268 ( void )
{
F_269 ( & V_379 ) ;
}
static int T_14 F_270 ( char * V_380 )
{
T_15 V_236 ;
if ( ! V_380 )
return 0 ;
V_236 = F_271 ( V_380 , 0 , & V_381 ) ;
if ( V_236 )
return 0 ;
if ( V_381 && V_381 < V_382 )
V_381 = V_382 ;
return 1 ;
}
void T_14 F_272 ( struct V_22 * V_383 , const char * V_370 )
{
unsigned int V_293 ;
V_383 -> V_75 = F_273 ( V_370 ,
2 * sizeof( struct V_3 ) ,
V_381 ,
21 ,
0 ,
& V_383 -> log ,
& V_383 -> V_33 ,
V_382 ,
64 * 1024 ) ;
V_383 -> V_78 = V_383 -> V_75 + ( V_383 -> V_33 + 1 ) ;
for ( V_293 = 0 ; V_293 <= V_383 -> V_33 ; V_293 ++ ) {
F_274 ( & V_383 -> V_75 [ V_293 ] . V_43 , V_293 ) ;
V_383 -> V_75 [ V_293 ] . V_36 = 0 ;
F_275 ( & V_383 -> V_75 [ V_293 ] . V_19 ) ;
}
for ( V_293 = 0 ; V_293 <= V_383 -> V_33 ; V_293 ++ ) {
F_274 ( & V_383 -> V_78 [ V_293 ] . V_43 , V_293 ) ;
V_383 -> V_78 [ V_293 ] . V_36 = 0 ;
F_275 ( & V_383 -> V_78 [ V_293 ] . V_19 ) ;
}
}
void T_14 F_276 ( void )
{
unsigned long V_384 ;
F_272 ( & V_22 , L_14 ) ;
V_384 = F_277 () / 8 ;
V_384 = F_278 ( V_384 , 128UL ) ;
V_385 [ 0 ] = V_384 / 4 * 3 ;
V_385 [ 1 ] = V_384 ;
V_385 [ 2 ] = V_385 [ 0 ] * 2 ;
V_386 = V_387 ;
V_388 = V_387 ;
}
struct V_80 * F_279 ( struct V_80 * V_81 ,
T_16 V_142 )
{
struct V_80 * V_389 = F_280 ( - V_187 ) ;
T_8 V_390 = V_81 -> V_391 ;
int V_392 = V_81 -> V_392 ;
int V_393 = F_281 ( V_81 ) - F_78 ( V_81 ) ;
T_4 V_394 = V_81 -> V_394 ;
T_16 V_395 ;
int V_396 , V_397 ;
unsigned int V_398 ;
bool V_399 ;
V_398 = ( T_8 ) ~ V_81 -> V_127 ;
if ( F_46 ( ! F_206 ( V_81 , V_393 ) ) )
goto V_105;
V_81 -> V_400 = 0 ;
F_282 ( V_81 , V_393 ) ;
F_283 ( V_81 ) ;
F_284 ( V_81 , F_285 ( V_81 ) ) ;
V_81 -> V_392 = F_285 ( V_81 ) ;
V_81 -> V_394 = F_90 ( V_401 ) ;
V_399 = ! ! ( F_286 ( V_81 ) -> V_402 & V_403 ) ;
if ( V_399 )
V_81 -> V_404 = 1 ;
V_395 = V_81 -> V_84 -> V_405 & F_287 ( V_81 ) ;
V_389 = F_288 ( V_81 , V_395 ) ;
if ( ! V_389 || F_115 ( V_389 ) ) {
F_289 ( V_81 , V_394 , V_393 , V_390 ,
V_392 ) ;
goto V_105;
}
V_397 = F_290 ( V_81 ) ;
V_396 = V_397 - V_393 ;
V_81 = V_389 ;
do {
struct V_92 * V_93 ;
int V_127 ;
F_291 ( V_81 ) ;
V_81 -> V_400 = 1 ;
V_81 -> V_392 = V_392 ;
F_292 ( V_81 , V_397 ) ;
F_283 ( V_81 ) ;
F_284 ( V_81 , V_392 ) ;
F_293 ( V_81 , V_396 ) ;
V_127 = V_81 -> V_127 - V_396 ;
V_93 = F_75 ( V_81 ) ;
V_93 -> V_127 = F_90 ( V_127 ) ;
if ( V_399 ) {
T_3 V_406 = F_36 ( V_398 + V_127 ) ;
V_93 -> V_135 = ~ F_294 ( ( V_51 T_6 )
( ( V_51 V_52 ) V_93 -> V_135 +
( V_51 V_52 ) V_406 ) ) ;
V_93 -> V_135 = F_295 ( V_81 , ~ V_93 -> V_135 ) ;
if ( V_93 -> V_135 == 0 )
V_93 -> V_135 = V_140 ;
}
V_81 -> V_394 = V_394 ;
} while ( ( V_81 = V_81 -> V_368 ) );
V_105:
return V_389 ;
}
