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
V_29 = F_18 ( rand , V_28 ) + V_26 ;
rand = ( rand | 1 ) * ( V_23 -> V_32 + 1 ) ;
V_30 = V_29 + V_23 -> V_32 + 1 ;
do {
V_4 = F_19 ( V_23 , V_1 , V_29 ) ;
F_20 ( V_5 , V_31 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_1 ( V_1 , V_20 , V_4 , V_5 , V_7 ,
F_2 , V_23 -> log ) ;
V_20 = V_29 ;
do {
if ( V_26 <= V_20 && V_20 <= V_27 &&
! F_22 ( V_20 >> V_23 -> log , V_5 ) &&
! F_23 ( V_1 , V_20 ) )
goto V_33;
V_20 += rand ;
} while ( V_20 != V_29 );
F_24 ( & V_4 -> V_19 ) ;
} while ( ++ V_29 != V_30 );
goto V_34;
} else {
V_4 = F_19 ( V_23 , V_1 , V_20 ) ;
F_21 ( & V_4 -> V_19 ) ;
if ( V_4 -> V_35 > 10 ) {
int V_36 ;
unsigned int V_37 = F_7 ( V_7 ) -> V_38 ^ V_20 ;
V_37 &= V_23 -> V_32 ;
V_21 &= V_23 -> V_32 ;
V_17 = F_25 ( V_23 , V_37 ) ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_39;
V_36 = F_10 ( V_1 , V_20 , V_17 ,
V_7 , F_2 ) ;
if ( ! V_36 && ( V_21 != V_37 ) ) {
V_17 = F_25 ( V_23 , V_21 ) ;
V_36 = F_10 ( V_1 , V_20 , V_17 ,
V_7 , F_2 ) ;
}
if ( V_36 )
goto V_40;
else
goto V_33;
}
V_39:
if ( F_1 ( V_1 , V_20 , V_4 , NULL , V_7 ,
F_2 , 0 ) )
goto V_40;
}
V_33:
F_26 ( V_7 ) -> V_41 = V_20 ;
F_7 ( V_7 ) -> V_13 = V_20 ;
F_7 ( V_7 ) -> V_38 ^= V_20 ;
if ( F_27 ( V_7 ) ) {
F_28 ( V_7 , & V_4 -> V_42 ) ;
V_4 -> V_35 ++ ;
F_29 ( F_6 ( V_7 ) , V_7 -> V_24 , 1 ) ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_30 ( & F_7 ( V_7 ) -> V_43 ,
& V_17 -> V_42 ) ;
V_17 -> V_35 ++ ;
F_13 ( & V_17 -> V_19 ) ;
}
error = 0 ;
V_40:
F_24 ( & V_4 -> V_19 ) ;
V_34:
return error ;
}
static int F_31 ( const struct V_6 * V_8 , const struct V_6 * V_9 )
{
struct V_44 * V_45 = F_26 ( V_8 ) , * V_46 = F_26 ( V_9 ) ;
return ( ! F_32 ( V_9 ) &&
( ! V_45 -> V_47 || ! V_46 -> V_47 ||
V_45 -> V_47 == V_46 -> V_47 ) ) ;
}
static unsigned int F_33 ( struct V_1 * V_1 , T_3 V_48 ,
unsigned int V_49 )
{
return F_34 ( ( V_50 V_51 ) V_48 , F_35 ( V_1 ) ) ^ V_49 ;
}
int F_36 ( struct V_6 * V_7 , unsigned short V_20 )
{
unsigned int V_21 =
F_33 ( F_6 ( V_7 ) , F_37 ( V_52 ) , V_20 ) ;
unsigned int V_53 =
F_33 ( F_6 ( V_7 ) , F_26 ( V_7 ) -> V_47 , 0 ) ;
F_7 ( V_7 ) -> V_38 = V_53 ;
return F_14 ( V_7 , V_20 , F_31 , V_21 ) ;
}
static inline int F_38 ( struct V_6 * V_7 , struct V_1 * V_1 , T_3 V_48 ,
unsigned short V_54 ,
T_4 V_55 , T_3 V_56 , T_4 V_57 , int V_58 )
{
int V_59 = - 1 ;
if ( F_5 ( F_6 ( V_7 ) , V_1 ) && F_7 ( V_7 ) -> V_13 == V_54 &&
! F_32 ( V_7 ) ) {
struct V_44 * V_60 = F_26 ( V_7 ) ;
V_59 = ( V_7 -> V_61 == V_62 ? 2 : 1 ) ;
if ( V_60 -> V_47 ) {
if ( V_60 -> V_47 != V_56 )
return - 1 ;
V_59 += 4 ;
}
if ( V_60 -> V_63 ) {
if ( V_60 -> V_63 != V_48 )
return - 1 ;
V_59 += 4 ;
}
if ( V_60 -> V_64 ) {
if ( V_60 -> V_64 != V_55 )
return - 1 ;
V_59 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_58 )
return - 1 ;
V_59 += 4 ;
}
}
return V_59 ;
}
static inline int F_39 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_3 V_48 , T_4 V_55 ,
T_3 V_56 , unsigned int V_54 , int V_58 )
{
int V_59 = - 1 ;
if ( F_5 ( F_6 ( V_7 ) , V_1 ) && ! F_32 ( V_7 ) ) {
struct V_44 * V_60 = F_26 ( V_7 ) ;
if ( V_60 -> V_47 != V_56 )
return - 1 ;
if ( V_60 -> V_41 != V_54 )
return - 1 ;
V_59 = ( V_7 -> V_61 == V_62 ? 2 : 1 ) ;
if ( V_60 -> V_63 ) {
if ( V_60 -> V_63 != V_48 )
return - 1 ;
V_59 += 4 ;
}
if ( V_60 -> V_64 ) {
if ( V_60 -> V_64 != V_55 )
return - 1 ;
V_59 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_58 )
return - 1 ;
V_59 += 4 ;
}
}
return V_59 ;
}
static unsigned int F_40 ( struct V_1 * V_1 , const T_3 V_65 ,
const T_1 V_66 , const T_3 V_67 ,
const T_4 V_68 )
{
static V_51 T_5 V_69 ;
F_41 ( & T_5 , sizeof( T_5 ) ) ;
return F_42 ( V_65 , V_66 , V_67 , V_68 ,
T_5 + F_35 ( V_1 ) ) ;
}
static struct V_6 * F_43 ( struct V_1 * V_1 ,
T_3 V_48 , T_4 V_55 ,
T_3 V_56 , unsigned int V_54 , int V_58 ,
struct V_3 * V_17 , unsigned int V_37 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
int V_59 , V_71 , V_72 = 0 , V_73 = 0 ;
V_51 V_74 = 0 ;
V_75:
V_70 = NULL ;
V_71 = 0 ;
F_44 (sk, node, &hslot2->head) {
V_59 = F_39 ( V_7 , V_1 , V_48 , V_55 ,
V_56 , V_54 , V_58 ) ;
if ( V_59 > V_71 ) {
V_70 = V_7 ;
V_71 = V_59 ;
V_73 = V_7 -> V_16 ;
if ( V_73 ) {
V_74 = F_40 ( V_1 , V_56 , V_54 ,
V_48 , V_55 ) ;
V_72 = 1 ;
}
} else if ( V_59 == V_71 && V_73 ) {
V_72 ++ ;
if ( F_18 ( V_74 , V_72 ) == 0 )
V_70 = V_7 ;
V_74 = F_45 ( V_74 ) ;
}
}
if ( F_46 ( V_11 ) != V_37 )
goto V_75;
if ( V_70 ) {
if ( F_47 ( ! F_48 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_47 ( F_39 ( V_70 , V_1 , V_48 , V_55 ,
V_56 , V_54 , V_58 ) < V_71 ) ) {
F_49 ( V_70 ) ;
goto V_75;
}
}
return V_70 ;
}
struct V_6 * F_50 ( struct V_1 * V_1 , T_3 V_48 ,
T_4 V_55 , T_3 V_56 , T_4 V_57 ,
int V_58 , struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
unsigned short V_54 = F_51 ( V_57 ) ;
unsigned int V_77 , V_37 , V_78 = F_52 ( V_1 , V_54 , V_23 -> V_32 ) ;
struct V_3 * V_17 , * V_4 = & V_23 -> V_74 [ V_78 ] ;
int V_59 , V_71 , V_72 = 0 , V_73 = 0 ;
V_51 V_74 = 0 ;
F_53 () ;
if ( V_4 -> V_35 > 10 ) {
V_77 = F_33 ( V_1 , V_56 , V_54 ) ;
V_37 = V_77 & V_23 -> V_32 ;
V_17 = & V_23 -> V_77 [ V_37 ] ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_75;
V_70 = F_43 ( V_1 , V_48 , V_55 ,
V_56 , V_54 , V_58 ,
V_17 , V_37 ) ;
if ( ! V_70 ) {
V_77 = F_33 ( V_1 , F_37 ( V_52 ) , V_54 ) ;
V_37 = V_77 & V_23 -> V_32 ;
V_17 = & V_23 -> V_77 [ V_37 ] ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_75;
V_70 = F_43 ( V_1 , V_48 , V_55 ,
F_37 ( V_52 ) , V_54 , V_58 ,
V_17 , V_37 ) ;
}
F_54 () ;
return V_70 ;
}
V_75:
V_70 = NULL ;
V_71 = 0 ;
F_55 (sk, node, &hslot->head) {
V_59 = F_38 ( V_7 , V_1 , V_48 , V_54 , V_55 ,
V_56 , V_57 , V_58 ) ;
if ( V_59 > V_71 ) {
V_70 = V_7 ;
V_71 = V_59 ;
V_73 = V_7 -> V_16 ;
if ( V_73 ) {
V_74 = F_40 ( V_1 , V_56 , V_54 ,
V_48 , V_55 ) ;
V_72 = 1 ;
}
} else if ( V_59 == V_71 && V_73 ) {
V_72 ++ ;
if ( F_18 ( V_74 , V_72 ) == 0 )
V_70 = V_7 ;
V_74 = F_45 ( V_74 ) ;
}
}
if ( F_46 ( V_11 ) != V_78 )
goto V_75;
if ( V_70 ) {
if ( F_47 ( ! F_48 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_47 ( F_38 ( V_70 , V_1 , V_48 , V_54 , V_55 ,
V_56 , V_57 , V_58 ) < V_71 ) ) {
F_49 ( V_70 ) ;
goto V_75;
}
}
F_54 () ;
return V_70 ;
}
static inline struct V_6 * F_56 ( struct V_79 * V_80 ,
T_4 V_55 , T_4 V_57 ,
struct V_22 * V_23 )
{
const struct V_81 * V_82 = F_57 ( V_80 ) ;
return F_50 ( F_58 ( F_59 ( V_80 ) -> V_83 ) , V_82 -> V_48 , V_55 ,
V_82 -> V_56 , V_57 , F_60 ( V_80 ) ,
V_23 ) ;
}
struct V_6 * F_61 ( struct V_1 * V_1 , T_3 V_48 , T_4 V_55 ,
T_3 V_56 , T_4 V_57 , int V_58 )
{
return F_50 ( V_1 , V_48 , V_55 , V_56 , V_57 , V_58 , & V_22 ) ;
}
static inline bool F_62 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_4 V_84 , T_3 V_85 ,
T_4 V_86 , T_3 V_87 ,
int V_58 , unsigned short V_54 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_13 != V_54 ||
( V_60 -> V_63 && V_60 -> V_63 != V_87 ) ||
( V_60 -> V_64 != V_86 && V_60 -> V_64 ) ||
( V_60 -> V_47 && V_60 -> V_47 != V_85 ) ||
F_32 ( V_7 ) ||
( V_7 -> V_15 && V_7 -> V_15 != V_58 ) )
return false ;
if ( ! F_63 ( V_7 , V_85 , V_87 , V_58 ) )
return false ;
return true ;
}
void F_64 ( struct V_79 * V_80 , V_51 V_88 , struct V_22 * V_23 )
{
struct V_44 * V_60 ;
const struct V_81 * V_82 = ( const struct V_81 * ) V_80 -> V_89 ;
struct V_90 * V_91 = (struct V_90 * ) ( V_80 -> V_89 + ( V_82 -> V_92 << 2 ) ) ;
const int type = F_65 ( V_80 ) -> type ;
const int V_93 = F_65 ( V_80 ) -> V_93 ;
struct V_6 * V_7 ;
int V_94 ;
int V_95 ;
struct V_1 * V_1 = F_58 ( V_80 -> V_83 ) ;
V_7 = F_50 ( V_1 , V_82 -> V_56 , V_91 -> V_96 ,
V_82 -> V_48 , V_91 -> V_97 , V_80 -> V_83 -> V_98 , V_23 ) ;
if ( V_7 == NULL ) {
F_66 ( V_1 , V_99 ) ;
return;
}
V_95 = 0 ;
V_94 = 0 ;
V_60 = F_26 ( V_7 ) ;
switch ( type ) {
default:
case V_100 :
V_95 = V_101 ;
break;
case V_102 :
goto V_103;
case V_104 :
V_95 = V_105 ;
V_94 = 1 ;
break;
case V_106 :
if ( V_93 == V_107 ) {
F_67 ( V_80 , V_7 , V_88 ) ;
if ( V_60 -> V_108 != V_109 ) {
V_95 = V_110 ;
V_94 = 1 ;
break;
}
goto V_103;
}
V_95 = V_101 ;
if ( V_93 <= V_111 ) {
V_94 = V_112 [ V_93 ] . V_113 ;
V_95 = V_112 [ V_93 ] . V_114 ;
}
break;
case V_115 :
F_68 ( V_80 , V_7 ) ;
goto V_103;
}
if ( ! V_60 -> V_116 ) {
if ( ! V_94 || V_7 -> V_117 != V_118 )
goto V_103;
} else
F_69 ( V_7 , V_80 , V_95 , V_91 -> V_96 , V_88 , ( V_119 * ) ( V_91 + 1 ) ) ;
V_7 -> V_120 = V_95 ;
V_7 -> V_121 ( V_7 ) ;
V_103:
F_49 ( V_7 ) ;
}
void F_70 ( struct V_79 * V_80 , V_51 V_88 )
{
F_64 ( V_80 , V_88 , & V_22 ) ;
}
void F_71 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
if ( V_123 -> V_124 ) {
V_123 -> V_125 = 0 ;
V_123 -> V_124 = 0 ;
F_72 ( V_7 ) ;
}
}
void F_73 ( struct V_79 * V_80 , T_3 V_126 , T_3 V_127 )
{
struct V_90 * V_91 = F_74 ( V_80 ) ;
int V_128 = F_75 ( V_80 ) ;
int V_125 = V_80 -> V_125 - V_128 ;
int V_129 = V_125 ;
T_6 V_130 = 0 ;
if ( ! F_76 ( V_80 ) ) {
V_80 -> V_131 = F_77 ( V_80 ) - V_80 -> V_42 ;
V_80 -> V_132 = F_78 ( struct V_90 , V_133 ) ;
V_91 -> V_133 = ~ F_79 ( V_126 , V_127 , V_125 ,
V_134 , 0 ) ;
} else {
struct V_79 * V_135 ;
F_80 (skb, frags) {
V_130 = F_81 ( V_130 , V_135 -> V_130 ) ;
V_129 -= V_135 -> V_125 ;
}
V_130 = F_82 ( V_80 , V_128 , V_129 , V_130 ) ;
V_80 -> V_136 = V_137 ;
V_91 -> V_133 = F_79 ( V_126 , V_127 , V_125 , V_134 , V_130 ) ;
if ( V_91 -> V_133 == 0 )
V_91 -> V_133 = V_138 ;
}
}
void F_83 ( bool V_139 , struct V_79 * V_80 ,
T_3 V_48 , T_3 V_56 , int V_125 )
{
struct V_90 * V_91 = F_74 ( V_80 ) ;
if ( V_139 )
V_91 -> V_133 = 0 ;
else if ( F_84 ( V_80 ) )
V_91 -> V_133 = ~ F_85 ( V_125 , V_48 , V_56 , 0 ) ;
else if ( F_59 ( V_80 ) && F_59 ( V_80 ) -> V_83 &&
( F_59 ( V_80 ) -> V_83 -> V_140 & V_141 ) ) {
F_86 ( V_80 -> V_136 == V_142 ) ;
V_80 -> V_136 = V_142 ;
V_80 -> V_131 = F_77 ( V_80 ) - V_80 -> V_42 ;
V_80 -> V_132 = F_78 ( struct V_90 , V_133 ) ;
V_91 -> V_133 = ~ F_85 ( V_125 , V_48 , V_56 , 0 ) ;
} else {
T_6 V_130 ;
F_86 ( V_80 -> V_136 == V_142 ) ;
V_91 -> V_133 = 0 ;
V_130 = F_82 ( V_80 , 0 , V_125 , 0 ) ;
V_91 -> V_133 = F_85 ( V_125 , V_48 , V_56 , V_130 ) ;
if ( V_91 -> V_133 == 0 )
V_91 -> V_133 = V_138 ;
V_80 -> V_136 = V_143 ;
}
}
static int F_87 ( struct V_79 * V_80 , struct V_144 * V_145 )
{
struct V_6 * V_7 = V_80 -> V_7 ;
struct V_44 * V_60 = F_26 ( V_7 ) ;
struct V_90 * V_91 ;
int V_95 = 0 ;
int V_146 = F_88 ( V_7 ) ;
int V_128 = F_75 ( V_80 ) ;
int V_125 = V_80 -> V_125 - V_128 ;
T_6 V_130 = 0 ;
V_91 = F_74 ( V_80 ) ;
V_91 -> V_97 = V_60 -> V_147 ;
V_91 -> V_96 = V_145 -> V_148 ;
V_91 -> V_125 = F_89 ( V_125 ) ;
V_91 -> V_133 = 0 ;
if ( V_146 )
V_130 = F_90 ( V_80 ) ;
else if ( V_7 -> V_149 ) {
V_80 -> V_136 = V_137 ;
goto V_150;
} else if ( V_80 -> V_136 == V_142 ) {
F_73 ( V_80 , V_145 -> V_48 , V_145 -> V_56 ) ;
goto V_150;
} else
V_130 = F_91 ( V_80 ) ;
V_91 -> V_133 = F_79 ( V_145 -> V_48 , V_145 -> V_56 , V_125 ,
V_7 -> V_151 , V_130 ) ;
if ( V_91 -> V_133 == 0 )
V_91 -> V_133 = V_138 ;
V_150:
V_95 = F_92 ( F_6 ( V_7 ) , V_80 ) ;
if ( V_95 ) {
if ( V_95 == - V_152 && ! V_60 -> V_116 ) {
F_93 ( F_6 ( V_7 ) ,
V_153 , V_146 ) ;
V_95 = 0 ;
}
} else
F_93 ( F_6 ( V_7 ) ,
V_154 , V_146 ) ;
return V_95 ;
}
int F_94 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
struct V_44 * V_60 = F_26 ( V_7 ) ;
struct V_144 * V_145 = & V_60 -> V_155 . V_156 . V_157 . V_158 ;
struct V_79 * V_80 ;
int V_95 = 0 ;
V_80 = F_95 ( V_7 , V_145 ) ;
if ( ! V_80 )
goto V_103;
V_95 = F_87 ( V_80 , V_145 ) ;
V_103:
V_123 -> V_125 = 0 ;
V_123 -> V_124 = 0 ;
return V_95 ;
}
int F_96 ( struct V_159 * V_160 , struct V_6 * V_7 , struct V_161 * V_162 ,
T_7 V_125 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
struct V_122 * V_123 = F_7 ( V_7 ) ;
struct V_144 V_163 ;
struct V_144 * V_145 ;
int V_164 = V_125 ;
struct V_165 V_166 ;
struct V_167 * V_168 = NULL ;
int free = 0 ;
int V_169 = 0 ;
T_3 V_56 , V_67 , V_48 ;
T_4 V_57 ;
V_119 V_170 ;
int V_95 , V_146 = F_88 ( V_7 ) ;
int V_171 = V_123 -> V_172 || V_162 -> V_173 & V_174 ;
int (* F_97)( void * , char * , int , int , int , struct V_79 * );
struct V_79 * V_80 ;
struct V_175 V_176 ;
if ( V_125 > 0xFFFF )
return - V_110 ;
if ( V_162 -> V_173 & V_177 )
return - V_178 ;
V_166 . V_179 = NULL ;
V_166 . V_180 = 0 ;
V_166 . V_181 = 0 ;
V_166 . V_170 = - 1 ;
F_97 = V_146 ? V_182 : V_183 ;
V_145 = & V_60 -> V_155 . V_156 . V_157 . V_158 ;
if ( V_123 -> V_124 ) {
F_98 ( V_7 ) ;
if ( F_99 ( V_123 -> V_124 ) ) {
if ( F_47 ( V_123 -> V_124 != V_184 ) ) {
F_100 ( V_7 ) ;
return - V_185 ;
}
goto V_186;
}
F_100 ( V_7 ) ;
}
V_164 += sizeof( struct V_90 ) ;
if ( V_162 -> V_187 ) {
F_101 ( struct V_188 * , V_189 , V_162 -> V_187 ) ;
if ( V_162 -> V_190 < sizeof( * V_189 ) )
return - V_185 ;
if ( V_189 -> V_191 != V_184 ) {
if ( V_189 -> V_191 != V_192 )
return - V_193 ;
}
V_56 = V_189 -> V_194 . V_195 ;
V_57 = V_189 -> V_196 ;
if ( V_57 == 0 )
return - V_185 ;
} else {
if ( V_7 -> V_117 != V_118 )
return - V_197 ;
V_56 = V_60 -> V_63 ;
V_57 = V_60 -> V_64 ;
V_169 = 1 ;
}
V_166 . V_198 = V_60 -> V_199 ;
V_166 . V_200 = V_7 -> V_15 ;
F_102 ( V_7 , & V_166 . V_180 ) ;
if ( V_162 -> V_201 ) {
V_95 = F_103 ( F_6 ( V_7 ) , V_162 , & V_166 ,
V_7 -> V_61 == V_202 ) ;
if ( V_95 )
return V_95 ;
if ( V_166 . V_179 )
free = 1 ;
V_169 = 0 ;
}
if ( ! V_166 . V_179 ) {
struct V_203 * V_204 ;
F_53 () ;
V_204 = F_104 ( V_60 -> V_204 ) ;
if ( V_204 ) {
memcpy ( & V_176 , V_204 ,
sizeof( * V_204 ) + V_204 -> V_179 . V_205 ) ;
V_166 . V_179 = & V_176 . V_179 ;
}
F_54 () ;
}
V_48 = V_166 . V_198 ;
V_166 . V_198 = V_67 = V_56 ;
if ( V_166 . V_179 && V_166 . V_179 -> V_179 . V_206 ) {
if ( ! V_56 )
return - V_185 ;
V_67 = V_166 . V_179 -> V_179 . V_67 ;
V_169 = 0 ;
}
V_170 = F_105 ( & V_166 , V_60 ) ;
if ( F_106 ( V_7 , V_207 ) ||
( V_162 -> V_173 & V_208 ) ||
( V_166 . V_179 && V_166 . V_179 -> V_179 . V_209 ) ) {
V_170 |= V_210 ;
V_169 = 0 ;
}
if ( F_107 ( V_56 ) ) {
if ( ! V_166 . V_200 )
V_166 . V_200 = V_60 -> V_211 ;
if ( ! V_48 )
V_48 = V_60 -> V_212 ;
V_169 = 0 ;
} else if ( ! V_166 . V_200 )
V_166 . V_200 = V_60 -> V_213 ;
if ( V_169 )
V_168 = (struct V_167 * ) F_108 ( V_7 , 0 ) ;
if ( V_168 == NULL ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
V_145 = & V_163 ;
F_109 ( V_145 , V_166 . V_200 , V_7 -> V_214 , V_170 ,
V_215 , V_7 -> V_151 ,
F_110 ( V_7 ) ,
V_67 , V_48 , V_57 , V_60 -> V_147 ) ;
F_111 ( V_7 , F_112 ( V_145 ) ) ;
V_168 = F_113 ( V_1 , V_145 , V_7 ) ;
if ( F_114 ( V_168 ) ) {
V_95 = F_115 ( V_168 ) ;
V_168 = NULL ;
if ( V_95 == - V_216 )
F_116 ( V_1 , V_217 ) ;
goto V_103;
}
V_95 = - V_218 ;
if ( ( V_168 -> V_219 & V_220 ) &&
! F_106 ( V_7 , V_221 ) )
goto V_103;
if ( V_169 )
F_117 ( V_7 , F_118 ( & V_168 -> V_127 ) ) ;
}
if ( V_162 -> V_173 & V_222 )
goto V_223;
V_224:
V_48 = V_145 -> V_48 ;
if ( ! V_166 . V_198 )
V_56 = V_166 . V_198 = V_145 -> V_56 ;
if ( ! V_171 ) {
V_80 = F_119 ( V_7 , V_145 , F_97 , V_162 -> V_225 , V_164 ,
sizeof( struct V_90 ) , & V_166 , & V_168 ,
V_162 -> V_173 ) ;
V_95 = F_115 ( V_80 ) ;
if ( ! F_120 ( V_80 ) )
V_95 = F_87 ( V_80 , V_145 ) ;
goto V_103;
}
F_98 ( V_7 ) ;
if ( F_47 ( V_123 -> V_124 ) ) {
F_100 ( V_7 ) ;
F_121 (KERN_DEBUG pr_fmt(L_1)) ;
V_95 = - V_185 ;
goto V_103;
}
V_145 = & V_60 -> V_155 . V_156 . V_157 . V_158 ;
V_145 -> V_56 = V_56 ;
V_145 -> V_48 = V_48 ;
V_145 -> V_148 = V_57 ;
V_145 -> V_226 = V_60 -> V_147 ;
V_123 -> V_124 = V_184 ;
V_186:
V_123 -> V_125 += V_164 ;
V_95 = F_122 ( V_7 , V_145 , F_97 , V_162 -> V_225 , V_164 ,
sizeof( struct V_90 ) , & V_166 , & V_168 ,
V_171 ? V_162 -> V_173 | V_174 : V_162 -> V_173 ) ;
if ( V_95 )
F_71 ( V_7 ) ;
else if ( ! V_171 )
V_95 = F_94 ( V_7 ) ;
else if ( F_47 ( F_123 ( & V_7 -> V_227 ) ) )
V_123 -> V_124 = 0 ;
F_100 ( V_7 ) ;
V_103:
F_124 ( V_168 ) ;
if ( free )
F_125 ( V_166 . V_179 ) ;
if ( ! V_95 )
return V_125 ;
if ( V_95 == - V_152 || F_22 ( V_228 , & V_7 -> V_229 -> V_230 ) ) {
F_93 ( F_6 ( V_7 ) ,
V_153 , V_146 ) ;
}
return V_95 ;
V_223:
F_126 ( & V_168 -> V_127 ) ;
if ( ! ( V_162 -> V_173 & V_231 ) || V_125 )
goto V_224;
V_95 = 0 ;
goto V_103;
}
int F_127 ( struct V_6 * V_7 , struct V_232 * V_232 , int V_128 ,
T_7 V_233 , int V_230 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_234 ;
if ( V_230 & V_235 )
V_230 |= V_174 ;
if ( ! V_123 -> V_124 ) {
struct V_161 V_162 = { . V_173 = V_230 | V_174 } ;
V_234 = F_96 ( NULL , V_7 , & V_162 , 0 ) ;
if ( V_234 < 0 )
return V_234 ;
}
F_98 ( V_7 ) ;
if ( F_47 ( ! V_123 -> V_124 ) ) {
F_100 ( V_7 ) ;
F_121 (KERN_DEBUG pr_fmt(L_2)) ;
return - V_185 ;
}
V_234 = F_128 ( V_7 , & V_60 -> V_155 . V_156 . V_157 . V_158 ,
V_232 , V_128 , V_233 , V_230 ) ;
if ( V_234 == - V_178 ) {
F_100 ( V_7 ) ;
return F_129 ( V_7 -> V_229 , V_232 , V_128 ,
V_233 , V_230 ) ;
}
if ( V_234 < 0 ) {
F_71 ( V_7 ) ;
goto V_103;
}
V_123 -> V_125 += V_233 ;
if ( ! ( V_123 -> V_172 || ( V_230 & V_174 ) ) )
V_234 = F_94 ( V_7 ) ;
if ( ! V_234 )
V_234 = V_233 ;
V_103:
F_100 ( V_7 ) ;
return V_234 ;
}
static unsigned int F_130 ( struct V_6 * V_7 )
{
struct V_236 V_237 , * V_238 = & V_7 -> V_239 ;
struct V_79 * V_80 ;
unsigned int V_18 ;
F_131 ( & V_237 ) ;
F_21 ( & V_238 -> V_19 ) ;
while ( ( V_80 = F_132 ( V_238 ) ) != NULL &&
F_133 ( V_80 ) ) {
F_134 ( F_6 ( V_7 ) , V_240 ,
F_88 ( V_7 ) ) ;
F_134 ( F_6 ( V_7 ) , V_241 ,
F_88 ( V_7 ) ) ;
F_135 ( & V_7 -> V_242 ) ;
F_136 ( V_80 , V_238 ) ;
F_137 ( & V_237 , V_80 ) ;
}
V_18 = V_80 ? V_80 -> V_125 : 0 ;
F_24 ( & V_238 -> V_19 ) ;
if ( ! F_123 ( & V_237 ) ) {
bool V_243 = F_138 ( V_7 ) ;
F_139 ( & V_237 ) ;
F_140 ( V_7 ) ;
F_141 ( V_7 , V_243 ) ;
}
return V_18 ;
}
int F_142 ( struct V_6 * V_7 , int V_244 , unsigned long V_245 )
{
switch ( V_244 ) {
case V_246 :
{
int V_247 = F_143 ( V_7 ) ;
return F_144 ( V_247 , ( int V_248 * ) V_245 ) ;
}
case V_249 :
{
unsigned int V_247 = F_130 ( V_7 ) ;
if ( V_247 )
V_247 -= sizeof( struct V_90 ) ;
return F_144 ( V_247 , ( int V_248 * ) V_245 ) ;
}
default:
return - V_250 ;
}
return 0 ;
}
int F_145 ( struct V_159 * V_160 , struct V_6 * V_7 , struct V_161 * V_162 ,
T_7 V_125 , int V_251 , int V_230 , int * V_252 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
F_101 ( struct V_188 * , sin , V_162 -> V_187 ) ;
struct V_79 * V_80 ;
unsigned int V_164 , V_253 ;
int V_254 , V_255 = 0 ;
int V_95 ;
int V_146 = F_88 ( V_7 ) ;
bool V_243 ;
if ( V_230 & V_256 )
return F_146 ( V_7 , V_162 , V_125 , V_252 ) ;
V_257:
V_80 = F_147 ( V_7 , V_230 | ( V_251 ? V_258 : 0 ) ,
& V_254 , & V_255 , & V_95 ) ;
if ( ! V_80 )
goto V_103;
V_164 = V_80 -> V_125 - sizeof( struct V_90 ) ;
V_253 = V_125 ;
if ( V_253 > V_164 )
V_253 = V_164 ;
else if ( V_253 < V_164 )
V_162 -> V_173 |= V_259 ;
if ( V_253 < V_164 || F_148 ( V_80 ) -> V_260 ) {
if ( F_133 ( V_80 ) )
goto V_261;
}
if ( F_149 ( V_80 ) )
V_95 = F_150 ( V_80 , sizeof( struct V_90 ) ,
V_162 -> V_225 , V_253 ) ;
else {
V_95 = F_151 ( V_80 ,
sizeof( struct V_90 ) ,
V_162 -> V_225 ) ;
if ( V_95 == - V_185 )
goto V_261;
}
if ( F_47 ( V_95 ) ) {
F_152 ( V_80 , F_145 ) ;
if ( ! V_254 ) {
F_135 ( & V_7 -> V_242 ) ;
F_93 ( F_6 ( V_7 ) ,
V_241 , V_146 ) ;
}
goto V_262;
}
if ( ! V_254 )
F_93 ( F_6 ( V_7 ) ,
V_263 , V_146 ) ;
F_153 ( V_162 , V_7 , V_80 ) ;
if ( sin ) {
sin -> V_191 = V_184 ;
sin -> V_196 = F_74 ( V_80 ) -> V_97 ;
sin -> V_194 . V_195 = F_57 ( V_80 ) -> V_48 ;
memset ( sin -> V_264 , 0 , sizeof( sin -> V_264 ) ) ;
* V_252 = sizeof( * sin ) ;
}
if ( V_60 -> V_265 )
F_154 ( V_162 , V_80 ) ;
V_95 = V_253 ;
if ( V_230 & V_259 )
V_95 = V_164 ;
V_262:
F_155 ( V_7 , V_80 ) ;
V_103:
return V_95 ;
V_261:
V_243 = F_138 ( V_7 ) ;
if ( ! F_156 ( V_7 , V_80 , V_230 ) ) {
F_93 ( F_6 ( V_7 ) , V_240 , V_146 ) ;
F_93 ( F_6 ( V_7 ) , V_241 , V_146 ) ;
}
F_141 ( V_7 , V_243 ) ;
if ( V_251 )
return - V_266 ;
V_162 -> V_173 &= ~ V_259 ;
goto V_257;
}
int F_157 ( struct V_6 * V_7 , int V_230 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
V_7 -> V_117 = V_267 ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = 0 ;
F_158 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_268 & V_269 ) )
F_159 ( V_7 ) ;
if ( ! ( V_7 -> V_268 & V_270 ) ) {
V_7 -> V_24 -> V_271 ( V_7 ) ;
V_60 -> V_147 = 0 ;
}
F_160 ( V_7 ) ;
return 0 ;
}
void F_161 ( struct V_6 * V_7 )
{
if ( F_162 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
F_21 ( & V_4 -> V_19 ) ;
if ( F_163 ( V_7 ) ) {
V_4 -> V_35 -- ;
F_26 ( V_7 ) -> V_41 = 0 ;
F_29 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_164 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_24 ( & V_4 -> V_19 ) ;
}
}
void F_165 ( struct V_6 * V_7 , T_8 V_272 )
{
if ( F_162 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_273 ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
V_273 = F_25 ( V_23 , V_272 ) ;
F_7 ( V_7 ) -> V_38 = V_272 ;
if ( V_17 != V_273 ) {
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_164 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_273 -> V_19 ) ;
F_30 ( & F_7 ( V_7 ) -> V_43 ,
& V_273 -> V_42 ) ;
V_273 -> V_35 ++ ;
F_13 ( & V_273 -> V_19 ) ;
F_24 ( & V_4 -> V_19 ) ;
}
}
}
static void F_166 ( struct V_6 * V_7 )
{
T_8 V_274 = F_33 ( F_6 ( V_7 ) ,
F_26 ( V_7 ) -> V_47 ,
F_26 ( V_7 ) -> V_41 ) ;
F_165 ( V_7 , V_274 ) ;
}
static int F_167 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
int V_275 ;
if ( F_26 ( V_7 ) -> V_63 ) {
F_168 ( V_7 , V_80 ) ;
F_169 ( V_7 , V_80 ) ;
}
V_275 = F_170 ( V_7 , V_80 ) ;
if ( V_275 < 0 ) {
int V_146 = F_88 ( V_7 ) ;
if ( V_275 == - V_276 )
F_134 ( F_6 ( V_7 ) , V_277 ,
V_146 ) ;
F_134 ( F_6 ( V_7 ) , V_241 , V_146 ) ;
F_171 ( V_80 ) ;
F_172 ( V_275 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_173 ( void )
{
if ( ! F_174 ( & V_278 ) )
F_175 ( & V_278 ) ;
}
int F_176 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_275 ;
int V_146 = F_88 ( V_7 ) ;
if ( ! F_177 ( V_7 , V_279 , V_80 ) )
goto V_280;
F_178 ( V_80 ) ;
if ( F_179 ( & V_278 ) && V_123 -> V_281 ) {
int (* F_180)( struct V_6 * V_7 , struct V_79 * V_80 );
F_180 = F_181 ( V_123 -> F_180 ) ;
if ( V_80 -> V_125 > sizeof( struct V_90 ) && F_180 != NULL ) {
int V_234 ;
if ( F_133 ( V_80 ) )
goto V_282;
V_234 = F_180 ( V_7 , V_80 ) ;
if ( V_234 <= 0 ) {
F_134 ( F_6 ( V_7 ) ,
V_263 ,
V_146 ) ;
return - V_234 ;
}
}
}
if ( ( V_146 & V_283 ) && F_148 ( V_80 ) -> V_260 ) {
if ( V_123 -> V_284 == 0 ) {
F_121 ( V_285 L_3 ,
F_148 ( V_80 ) -> V_286 , V_80 -> V_125 ) ;
goto V_280;
}
if ( F_148 ( V_80 ) -> V_286 < V_123 -> V_284 ) {
F_121 ( V_285 L_4 ,
F_148 ( V_80 ) -> V_286 , V_123 -> V_284 ) ;
goto V_280;
}
}
if ( F_182 ( V_7 -> V_287 ) &&
F_133 ( V_80 ) )
goto V_282;
if ( F_183 ( V_7 , V_7 -> V_288 ) ) {
F_134 ( F_6 ( V_7 ) , V_277 ,
V_146 ) ;
goto V_280;
}
V_275 = 0 ;
F_184 ( V_7 , V_80 ) ;
F_185 ( V_7 ) ;
if ( ! F_186 ( V_7 ) )
V_275 = F_167 ( V_7 , V_80 ) ;
else if ( F_187 ( V_7 , V_80 , V_7 -> V_288 ) ) {
F_188 ( V_7 ) ;
goto V_280;
}
F_188 ( V_7 ) ;
return V_275 ;
V_282:
F_134 ( F_6 ( V_7 ) , V_240 , V_146 ) ;
V_280:
F_134 ( F_6 ( V_7 ) , V_241 , V_146 ) ;
F_135 ( & V_7 -> V_242 ) ;
F_171 ( V_80 ) ;
return - 1 ;
}
static void F_189 ( struct V_6 * * V_289 , unsigned int V_35 ,
struct V_79 * V_80 , unsigned int V_290 )
{
unsigned int V_291 ;
struct V_79 * V_292 = NULL ;
struct V_6 * V_7 ;
for ( V_291 = 0 ; V_291 < V_35 ; V_291 ++ ) {
V_7 = V_289 [ V_291 ] ;
if ( F_99 ( V_292 == NULL ) )
V_292 = ( V_291 == V_290 ) ? V_80 : F_190 ( V_80 , V_293 ) ;
if ( ! V_292 ) {
F_135 ( & V_7 -> V_242 ) ;
F_134 ( F_6 ( V_7 ) , V_277 ,
F_88 ( V_7 ) ) ;
F_134 ( F_6 ( V_7 ) , V_241 ,
F_88 ( V_7 ) ) ;
}
if ( V_292 && F_176 ( V_7 , V_292 ) <= 0 )
V_292 = NULL ;
F_49 ( V_7 ) ;
}
if ( F_47 ( V_292 ) )
F_171 ( V_292 ) ;
}
static void F_191 ( struct V_6 * V_7 , struct V_294 * V_127 )
{
struct V_294 * V_295 ;
F_192 ( V_127 ) ;
V_295 = F_193 ( & V_7 -> V_296 , V_127 ) ;
F_194 ( V_295 ) ;
}
static int F_195 ( struct V_1 * V_1 , struct V_79 * V_80 ,
struct V_90 * V_91 ,
T_3 V_48 , T_3 V_56 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_289 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_10 * V_11 ;
unsigned short V_54 = F_51 ( V_91 -> V_96 ) ;
struct V_3 * V_4 = F_19 ( V_23 , V_1 , V_54 ) ;
int V_58 = V_80 -> V_83 -> V_98 ;
unsigned int V_35 = 0 , V_128 = F_78 ( F_196 ( * V_7 ) , V_297 ) ;
unsigned int V_77 = 0 , V_298 = 0 , V_299 = ( V_4 -> V_35 > 10 ) ;
if ( V_299 ) {
V_298 = F_33 ( V_1 , F_37 ( V_52 ) , V_54 ) &
V_22 . V_32 ;
V_77 = F_33 ( V_1 , V_56 , V_54 ) & V_22 . V_32 ;
V_300:
V_4 = & V_22 . V_77 [ V_77 ] ;
V_128 = F_78 ( F_196 ( * V_7 ) , V_301 . V_302 ) ;
}
F_11 ( & V_4 -> V_19 ) ;
F_197 (sk, node, &hslot->head, offset) {
if ( F_62 ( V_1 , V_7 ,
V_91 -> V_96 , V_56 ,
V_91 -> V_97 , V_48 ,
V_58 , V_54 ) ) {
if ( F_47 ( V_35 == F_198 ( V_289 ) ) ) {
F_189 ( V_289 , V_35 , V_80 , ~ 0 ) ;
V_35 = 0 ;
}
V_289 [ V_35 ++ ] = V_7 ;
F_199 ( V_7 ) ;
}
}
F_13 ( & V_4 -> V_19 ) ;
if ( V_299 && V_77 != V_298 ) {
V_77 = V_298 ;
goto V_300;
}
if ( V_35 ) {
F_189 ( V_289 , V_35 , V_80 , V_35 - 1 ) ;
} else {
F_171 ( V_80 ) ;
}
return 0 ;
}
static inline int F_200 ( struct V_79 * V_80 , struct V_90 * V_91 ,
int V_303 )
{
int V_95 ;
F_148 ( V_80 ) -> V_260 = 0 ;
F_148 ( V_80 ) -> V_286 = V_80 -> V_125 ;
if ( V_303 == V_304 ) {
V_95 = F_201 ( V_80 , V_91 ) ;
if ( V_95 )
return V_95 ;
}
return F_202 ( V_80 , V_303 , V_91 -> V_133 ,
V_305 ) ;
}
int F_203 ( struct V_79 * V_80 , struct V_22 * V_23 ,
int V_303 )
{
struct V_6 * V_7 ;
struct V_90 * V_91 ;
unsigned short V_164 ;
struct V_167 * V_168 = F_204 ( V_80 ) ;
T_3 V_48 , V_56 ;
struct V_1 * V_1 = F_58 ( V_80 -> V_83 ) ;
if ( ! F_205 ( V_80 , sizeof( struct V_90 ) ) )
goto V_280;
V_91 = F_74 ( V_80 ) ;
V_164 = F_51 ( V_91 -> V_125 ) ;
V_48 = F_57 ( V_80 ) -> V_48 ;
V_56 = F_57 ( V_80 ) -> V_56 ;
if ( V_164 > V_80 -> V_125 )
goto V_306;
if ( V_303 == V_134 ) {
if ( V_164 < sizeof( * V_91 ) || F_206 ( V_80 , V_164 ) )
goto V_306;
V_91 = F_74 ( V_80 ) ;
}
if ( F_200 ( V_80 , V_91 , V_303 ) )
goto V_282;
V_7 = F_207 ( V_80 ) ;
if ( V_7 ) {
struct V_294 * V_127 = F_59 ( V_80 ) ;
int V_234 ;
if ( F_47 ( V_7 -> V_296 != V_127 ) )
F_191 ( V_7 , V_127 ) ;
V_234 = F_176 ( V_7 , V_80 ) ;
F_49 ( V_7 ) ;
if ( V_234 > 0 )
return - V_234 ;
return 0 ;
} else {
if ( V_168 -> V_219 & ( V_220 | V_307 ) )
return F_195 ( V_1 , V_80 , V_91 ,
V_48 , V_56 , V_23 ) ;
V_7 = F_56 ( V_80 , V_91 -> V_97 , V_91 -> V_96 , V_23 ) ;
}
if ( V_7 != NULL ) {
int V_234 ;
if ( F_7 ( V_7 ) -> V_308 && V_91 -> V_133 && ! F_88 ( V_7 ) )
F_208 ( V_80 , V_134 , V_91 -> V_133 ,
V_305 ) ;
V_234 = F_176 ( V_7 , V_80 ) ;
F_49 ( V_7 ) ;
if ( V_234 > 0 )
return - V_234 ;
return 0 ;
}
if ( ! F_177 ( NULL , V_279 , V_80 ) )
goto V_280;
F_178 ( V_80 ) ;
if ( F_133 ( V_80 ) )
goto V_282;
F_134 ( V_1 , V_309 , V_303 == V_304 ) ;
F_209 ( V_80 , V_106 , V_310 , 0 ) ;
F_171 ( V_80 ) ;
return 0 ;
V_306:
F_121 ( V_311 L_5 ,
V_303 == V_304 ? L_6 : L_7 ,
& V_48 , F_51 ( V_91 -> V_97 ) ,
V_164 , V_80 -> V_125 ,
& V_56 , F_51 ( V_91 -> V_96 ) ) ;
goto V_280;
V_282:
F_121 ( V_311 L_8 ,
V_303 == V_304 ? L_6 : L_7 ,
& V_48 , F_51 ( V_91 -> V_97 ) , & V_56 , F_51 ( V_91 -> V_96 ) ,
V_164 ) ;
F_134 ( V_1 , V_240 , V_303 == V_304 ) ;
V_280:
F_134 ( V_1 , V_241 , V_303 == V_304 ) ;
F_171 ( V_80 ) ;
return 0 ;
}
static struct V_6 * F_210 ( struct V_1 * V_1 ,
T_4 V_84 , T_3 V_85 ,
T_4 V_86 , T_3 V_87 ,
int V_58 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
unsigned short V_54 = F_51 ( V_84 ) ;
unsigned int V_35 , V_78 = F_52 ( V_1 , V_54 , V_22 . V_32 ) ;
struct V_3 * V_4 = & V_22 . V_74 [ V_78 ] ;
if ( V_4 -> V_35 > 10 )
return NULL ;
F_53 () ;
V_75:
V_35 = 0 ;
V_70 = NULL ;
F_55 (sk, node, &hslot->head) {
if ( F_62 ( V_1 , V_7 ,
V_84 , V_85 ,
V_86 , V_87 ,
V_58 , V_54 ) ) {
V_70 = V_7 ;
++ V_35 ;
}
}
if ( F_46 ( V_11 ) != V_78 )
goto V_75;
if ( V_70 ) {
if ( V_35 != 1 ||
F_47 ( ! F_48 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_47 ( ! F_62 ( V_1 , V_70 ,
V_84 , V_85 ,
V_86 , V_87 ,
V_58 , V_54 ) ) ) {
F_49 ( V_70 ) ;
V_70 = NULL ;
}
}
F_54 () ;
return V_70 ;
}
static struct V_6 * F_211 ( struct V_1 * V_1 ,
T_4 V_84 , T_3 V_85 ,
T_4 V_86 , T_3 V_87 ,
int V_58 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
unsigned short V_54 = F_51 ( V_84 ) ;
unsigned int V_77 = F_33 ( V_1 , V_85 , V_54 ) ;
unsigned int V_37 = V_77 & V_22 . V_32 ;
struct V_3 * V_17 = & V_22 . V_77 [ V_37 ] ;
F_212 ( V_312 , V_87 , V_85 ) ;
const T_9 V_313 = F_213 ( V_86 , V_54 ) ;
F_53 () ;
V_70 = NULL ;
F_44 (sk, node, &hslot2->head) {
if ( F_214 ( V_7 , V_1 , V_312 ,
V_87 , V_85 , V_313 , V_58 ) )
V_70 = V_7 ;
break;
}
if ( V_70 ) {
if ( F_47 ( ! F_48 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_47 ( ! F_214 ( V_7 , V_1 , V_312 ,
V_87 , V_85 ,
V_313 , V_58 ) ) ) {
F_49 ( V_70 ) ;
V_70 = NULL ;
}
}
F_54 () ;
return V_70 ;
}
void F_215 ( struct V_79 * V_80 )
{
struct V_1 * V_1 = F_58 ( V_80 -> V_83 ) ;
const struct V_81 * V_82 ;
const struct V_90 * V_91 ;
struct V_6 * V_7 ;
struct V_294 * V_127 ;
int V_58 = V_80 -> V_83 -> V_98 ;
if ( ! F_205 ( V_80 , F_75 ( V_80 ) + sizeof( struct V_90 ) ) )
return;
V_82 = F_57 ( V_80 ) ;
V_91 = F_74 ( V_80 ) ;
if ( V_80 -> V_314 == V_315 ||
V_80 -> V_314 == V_316 )
V_7 = F_210 ( V_1 , V_91 -> V_96 , V_82 -> V_56 ,
V_91 -> V_97 , V_82 -> V_48 , V_58 ) ;
else if ( V_80 -> V_314 == V_317 )
V_7 = F_211 ( V_1 , V_91 -> V_96 , V_82 -> V_56 ,
V_91 -> V_97 , V_82 -> V_48 , V_58 ) ;
else
return;
if ( ! V_7 )
return;
V_80 -> V_7 = V_7 ;
V_80 -> V_318 = V_319 ;
V_127 = V_7 -> V_296 ;
if ( V_127 )
V_127 = F_216 ( V_127 , 0 ) ;
if ( V_127 )
F_217 ( V_80 , V_127 ) ;
}
int F_218 ( struct V_79 * V_80 )
{
return F_203 ( V_80 , & V_22 , V_134 ) ;
}
void F_219 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
bool V_243 = F_138 ( V_7 ) ;
F_71 ( V_7 ) ;
F_141 ( V_7 , V_243 ) ;
if ( F_179 ( & V_278 ) && V_123 -> V_281 ) {
void (* F_220)( struct V_6 * V_7 );
F_220 = F_181 ( V_123 -> F_220 ) ;
if ( F_220 )
F_220 ( V_7 ) ;
}
}
int F_221 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_248 * V_322 , unsigned int V_205 ,
int (* F_222)( struct V_6 * ) )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_323 , V_324 ;
int V_95 = 0 ;
int V_146 = F_88 ( V_7 ) ;
if ( V_205 < sizeof( int ) )
return - V_185 ;
if ( F_223 ( V_323 , ( int V_248 * ) V_322 ) )
return - V_325 ;
V_324 = V_323 ? 1 : 0 ;
switch ( V_321 ) {
case V_326 :
if ( V_323 != 0 ) {
V_123 -> V_172 = 1 ;
} else {
V_123 -> V_172 = 0 ;
F_98 ( V_7 ) ;
(* F_222)( V_7 ) ;
F_100 ( V_7 ) ;
}
break;
case V_327 :
switch ( V_323 ) {
case 0 :
case V_328 :
case V_329 :
V_123 -> F_180 = V_330 ;
case V_331 :
V_123 -> V_281 = V_323 ;
F_173 () ;
break;
default:
V_95 = - V_332 ;
break;
}
break;
case V_333 :
V_123 -> V_334 = V_324 ;
break;
case V_335 :
V_123 -> V_336 = V_324 ;
break;
case V_337 :
if ( ! V_146 )
return - V_332 ;
if ( V_323 != 0 && V_323 < 8 )
V_323 = 8 ;
else if ( V_323 > V_338 )
V_323 = V_338 ;
V_123 -> V_339 = V_323 ;
V_123 -> V_340 |= V_341 ;
break;
case V_342 :
if ( ! V_146 )
return - V_332 ;
if ( V_323 != 0 && V_323 < 8 )
V_323 = 8 ;
else if ( V_323 > V_338 )
V_323 = V_338 ;
V_123 -> V_284 = V_323 ;
V_123 -> V_340 |= V_283 ;
break;
default:
V_95 = - V_332 ;
break;
}
return V_95 ;
}
int F_224 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_248 * V_322 , unsigned int V_205 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_221 ( V_7 , V_320 , V_321 , V_322 , V_205 ,
F_94 ) ;
return F_225 ( V_7 , V_320 , V_321 , V_322 , V_205 ) ;
}
int F_226 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_248 * V_322 , unsigned int V_205 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_221 ( V_7 , V_320 , V_321 , V_322 , V_205 ,
F_94 ) ;
return F_227 ( V_7 , V_320 , V_321 , V_322 , V_205 ) ;
}
int F_228 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_248 * V_322 , int V_248 * V_205 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_323 , V_125 ;
if ( F_223 ( V_125 , V_205 ) )
return - V_325 ;
V_125 = F_229 (unsigned int, len, sizeof(int)) ;
if ( V_125 < 0 )
return - V_185 ;
switch ( V_321 ) {
case V_326 :
V_323 = V_123 -> V_172 ;
break;
case V_327 :
V_323 = V_123 -> V_281 ;
break;
case V_333 :
V_323 = V_123 -> V_334 ;
break;
case V_335 :
V_323 = V_123 -> V_336 ;
break;
case V_337 :
V_323 = V_123 -> V_339 ;
break;
case V_342 :
V_323 = V_123 -> V_284 ;
break;
default:
return - V_332 ;
}
if ( F_144 ( V_125 , V_205 ) )
return - V_325 ;
if ( F_230 ( V_322 , & V_323 , V_125 ) )
return - V_325 ;
return 0 ;
}
int F_231 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_248 * V_322 , int V_248 * V_205 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_228 ( V_7 , V_320 , V_321 , V_322 , V_205 ) ;
return F_232 ( V_7 , V_320 , V_321 , V_322 , V_205 ) ;
}
int F_233 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_248 * V_322 , int V_248 * V_205 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_228 ( V_7 , V_320 , V_321 , V_322 , V_205 ) ;
return F_234 ( V_7 , V_320 , V_321 , V_322 , V_205 ) ;
}
unsigned int F_235 ( struct V_345 * V_345 , struct V_346 * V_6 , T_10 * V_347 )
{
unsigned int V_32 = F_236 ( V_345 , V_6 , V_347 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_237 ( V_7 ) ;
if ( ( V_32 & V_348 ) && ! ( V_345 -> V_349 & V_350 ) &&
! ( V_7 -> V_351 & V_352 ) && ! F_130 ( V_7 ) )
V_32 &= ~ ( V_353 | V_348 ) ;
return V_32 ;
}
static struct V_6 * F_238 ( struct V_354 * V_355 , int V_356 )
{
struct V_6 * V_7 ;
struct V_357 * V_358 = V_355 -> V_359 ;
struct V_1 * V_1 = F_239 ( V_355 ) ;
for ( V_358 -> V_360 = V_356 ; V_358 -> V_360 <= V_358 -> V_22 -> V_32 ;
++ V_358 -> V_360 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_358 -> V_22 -> V_74 [ V_358 -> V_360 ] ;
if ( F_240 ( & V_4 -> V_42 ) )
continue;
F_21 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_61 == V_358 -> V_361 )
goto V_33;
}
F_24 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_33:
return V_7 ;
}
static struct V_6 * F_241 ( struct V_354 * V_355 , struct V_6 * V_7 )
{
struct V_357 * V_358 = V_355 -> V_359 ;
struct V_1 * V_1 = F_239 ( V_355 ) ;
do {
V_7 = F_242 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_61 != V_358 -> V_361 ) );
if ( ! V_7 ) {
if ( V_358 -> V_360 <= V_358 -> V_22 -> V_32 )
F_24 ( & V_358 -> V_22 -> V_74 [ V_358 -> V_360 ] . V_19 ) ;
return F_238 ( V_355 , V_358 -> V_360 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_243 ( struct V_354 * V_355 , T_11 V_362 )
{
struct V_6 * V_7 = F_238 ( V_355 , 0 ) ;
if ( V_7 )
while ( V_362 && ( V_7 = F_241 ( V_355 , V_7 ) ) != NULL )
-- V_362 ;
return V_362 ? NULL : V_7 ;
}
static void * F_244 ( struct V_354 * V_355 , T_11 * V_362 )
{
struct V_357 * V_358 = V_355 -> V_359 ;
V_358 -> V_360 = V_363 ;
return * V_362 ? F_243 ( V_355 , * V_362 - 1 ) : V_364 ;
}
static void * F_245 ( struct V_354 * V_355 , void * V_365 , T_11 * V_362 )
{
struct V_6 * V_7 ;
if ( V_365 == V_364 )
V_7 = F_243 ( V_355 , 0 ) ;
else
V_7 = F_241 ( V_355 , V_365 ) ;
++ * V_362 ;
return V_7 ;
}
static void F_246 ( struct V_354 * V_355 , void * V_365 )
{
struct V_357 * V_358 = V_355 -> V_359 ;
if ( V_358 -> V_360 <= V_358 -> V_22 -> V_32 )
F_24 ( & V_358 -> V_22 -> V_74 [ V_358 -> V_360 ] . V_19 ) ;
}
int F_247 ( struct V_366 * V_366 , struct V_345 * V_345 )
{
struct V_367 * V_368 = F_248 ( V_366 ) ;
struct V_357 * V_369 ;
int V_95 ;
V_95 = F_249 ( V_366 , V_345 , & V_368 -> V_370 ,
sizeof( struct V_357 ) ) ;
if ( V_95 < 0 )
return V_95 ;
V_369 = ( (struct V_354 * ) V_345 -> V_371 ) -> V_359 ;
V_369 -> V_361 = V_368 -> V_361 ;
V_369 -> V_22 = V_368 -> V_22 ;
return V_95 ;
}
int F_250 ( struct V_1 * V_1 , struct V_367 * V_368 )
{
struct V_372 * V_373 ;
int V_275 = 0 ;
V_368 -> V_370 . V_356 = F_244 ;
V_368 -> V_370 . V_374 = F_245 ;
V_368 -> V_370 . V_375 = F_246 ;
V_373 = F_251 ( V_368 -> V_376 , V_377 , V_1 -> V_378 ,
V_368 -> V_379 , V_368 ) ;
if ( ! V_373 )
V_275 = - V_276 ;
return V_275 ;
}
void F_252 ( struct V_1 * V_1 , struct V_367 * V_368 )
{
F_253 ( V_368 -> V_376 , V_1 -> V_378 ) ;
}
static void F_254 ( struct V_6 * V_380 , struct V_354 * V_381 ,
int V_360 )
{
struct V_44 * V_60 = F_26 ( V_380 ) ;
T_3 V_96 = V_60 -> V_63 ;
T_3 V_126 = V_60 -> V_47 ;
T_1 V_382 = F_51 ( V_60 -> V_64 ) ;
T_1 V_383 = F_51 ( V_60 -> V_147 ) ;
F_255 ( V_381 , L_9
L_10 ,
V_360 , V_126 , V_383 , V_96 , V_382 , V_380 -> V_117 ,
F_143 ( V_380 ) ,
F_256 ( V_380 ) ,
0 , 0L , 0 ,
F_257 ( F_258 ( V_381 ) , F_3 ( V_380 ) ) ,
0 , F_259 ( V_380 ) ,
F_260 ( & V_380 -> V_76 ) , V_380 ,
F_260 ( & V_380 -> V_242 ) ) ;
}
int F_261 ( struct V_354 * V_355 , void * V_365 )
{
F_262 ( V_355 , 127 ) ;
if ( V_365 == V_364 )
F_263 ( V_355 , L_11
L_12
L_13 ) ;
else {
struct V_357 * V_358 = V_355 -> V_359 ;
F_254 ( V_365 , V_355 , V_358 -> V_360 ) ;
}
F_264 ( V_355 , '\n' ) ;
return 0 ;
}
static int T_12 F_265 ( struct V_1 * V_1 )
{
return F_250 ( V_1 , & V_384 ) ;
}
static void T_13 F_266 ( struct V_1 * V_1 )
{
F_252 ( V_1 , & V_384 ) ;
}
int T_14 F_267 ( void )
{
return F_268 ( & V_385 ) ;
}
void F_269 ( void )
{
F_270 ( & V_385 ) ;
}
static int T_14 F_271 ( char * V_386 )
{
T_15 V_234 ;
if ( ! V_386 )
return 0 ;
V_234 = F_272 ( V_386 , 0 , & V_387 ) ;
if ( V_234 )
return 0 ;
if ( V_387 && V_387 < V_388 )
V_387 = V_388 ;
return 1 ;
}
void T_14 F_273 ( struct V_22 * V_389 , const char * V_376 )
{
unsigned int V_291 ;
V_389 -> V_74 = F_274 ( V_376 ,
2 * sizeof( struct V_3 ) ,
V_387 ,
21 ,
0 ,
& V_389 -> log ,
& V_389 -> V_32 ,
V_388 ,
64 * 1024 ) ;
V_389 -> V_77 = V_389 -> V_74 + ( V_389 -> V_32 + 1 ) ;
for ( V_291 = 0 ; V_291 <= V_389 -> V_32 ; V_291 ++ ) {
F_275 ( & V_389 -> V_74 [ V_291 ] . V_42 , V_291 ) ;
V_389 -> V_74 [ V_291 ] . V_35 = 0 ;
F_276 ( & V_389 -> V_74 [ V_291 ] . V_19 ) ;
}
for ( V_291 = 0 ; V_291 <= V_389 -> V_32 ; V_291 ++ ) {
F_275 ( & V_389 -> V_77 [ V_291 ] . V_42 , V_291 ) ;
V_389 -> V_77 [ V_291 ] . V_35 = 0 ;
F_276 ( & V_389 -> V_77 [ V_291 ] . V_19 ) ;
}
}
void T_14 F_277 ( void )
{
unsigned long V_390 ;
F_273 ( & V_22 , L_14 ) ;
V_390 = F_278 () / 8 ;
V_390 = F_279 ( V_390 , 128UL ) ;
V_391 [ 0 ] = V_390 / 4 * 3 ;
V_391 [ 1 ] = V_390 ;
V_391 [ 2 ] = V_391 [ 0 ] * 2 ;
V_392 = V_393 ;
V_394 = V_393 ;
}
