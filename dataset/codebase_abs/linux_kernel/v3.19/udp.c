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
F_4 (sk2, node, &hslot->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( V_5 || F_7 ( V_9 ) -> V_13 == V_2 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
V_9 -> V_15 == V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
! F_8 ( V_12 , F_3 ( V_9 ) ) ) &&
F_2 ( V_7 , V_9 ) ) {
if ( ! V_5 )
return 1 ;
F_9 ( F_7 ( V_9 ) -> V_13 >> log , V_5 ) ;
}
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
F_12 (sk2, node, &hslot2->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( F_7 ( V_9 ) -> V_13 == V_2 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
V_9 -> V_15 == V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
! F_8 ( V_12 , F_3 ( V_9 ) ) ) &&
F_2 ( V_7 , V_9 ) ) {
V_18 = 1 ;
break;
}
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
static inline int F_38 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_3 V_48 , unsigned short V_54 , T_4 V_55 ,
T_3 V_56 , T_4 V_57 , int V_58 )
{
int V_59 ;
struct V_44 * V_60 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_13 != V_54 ||
F_32 ( V_7 ) )
return - 1 ;
V_59 = ( V_7 -> V_61 == V_62 ) ? 2 : 1 ;
V_60 = F_26 ( V_7 ) ;
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
return V_59 ;
}
static inline int F_39 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_3 V_48 , T_4 V_55 ,
T_3 V_56 , unsigned int V_54 , int V_58 )
{
int V_59 ;
struct V_44 * V_60 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_32 ( V_7 ) )
return - 1 ;
V_60 = F_26 ( V_7 ) ;
if ( V_60 -> V_47 != V_56 ||
V_60 -> V_41 != V_54 )
return - 1 ;
V_59 = ( V_7 -> V_61 == V_62 ) ? 2 : 1 ;
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
V_80 = F_119 ( V_7 , V_145 , F_97 , V_162 , V_164 ,
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
F_121 ( L_1 ) ;
V_95 = - V_185 ;
goto V_103;
}
V_145 = & V_60 -> V_155 . V_156 . V_157 . V_158 ;
V_145 -> V_56 = V_56 ;
V_145 -> V_48 = V_48 ;
V_145 -> V_148 = V_57 ;
V_145 -> V_225 = V_60 -> V_147 ;
V_123 -> V_124 = V_184 ;
V_186:
V_123 -> V_125 += V_164 ;
V_95 = F_122 ( V_7 , V_145 , F_97 , V_162 , V_164 ,
sizeof( struct V_90 ) , & V_166 , & V_168 ,
V_171 ? V_162 -> V_173 | V_174 : V_162 -> V_173 ) ;
if ( V_95 )
F_71 ( V_7 ) ;
else if ( ! V_171 )
V_95 = F_94 ( V_7 ) ;
else if ( F_47 ( F_123 ( & V_7 -> V_226 ) ) )
V_123 -> V_124 = 0 ;
F_100 ( V_7 ) ;
V_103:
F_124 ( V_168 ) ;
if ( free )
F_125 ( V_166 . V_179 ) ;
if ( ! V_95 )
return V_125 ;
if ( V_95 == - V_152 || F_22 ( V_227 , & V_7 -> V_228 -> V_229 ) ) {
F_93 ( F_6 ( V_7 ) ,
V_153 , V_146 ) ;
}
return V_95 ;
V_223:
F_126 ( & V_168 -> V_127 ) ;
if ( ! ( V_162 -> V_173 & V_230 ) || V_125 )
goto V_224;
V_95 = 0 ;
goto V_103;
}
int F_127 ( struct V_6 * V_7 , struct V_231 * V_231 , int V_128 ,
T_7 V_232 , int V_229 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_233 ;
if ( V_229 & V_234 )
V_229 |= V_174 ;
if ( ! V_123 -> V_124 ) {
struct V_161 V_162 = { . V_173 = V_229 | V_174 } ;
V_233 = F_96 ( NULL , V_7 , & V_162 , 0 ) ;
if ( V_233 < 0 )
return V_233 ;
}
F_98 ( V_7 ) ;
if ( F_47 ( ! V_123 -> V_124 ) ) {
F_100 ( V_7 ) ;
F_121 ( L_2 ) ;
return - V_185 ;
}
V_233 = F_128 ( V_7 , & V_60 -> V_155 . V_156 . V_157 . V_158 ,
V_231 , V_128 , V_232 , V_229 ) ;
if ( V_233 == - V_178 ) {
F_100 ( V_7 ) ;
return F_129 ( V_7 -> V_228 , V_231 , V_128 ,
V_232 , V_229 ) ;
}
if ( V_233 < 0 ) {
F_71 ( V_7 ) ;
goto V_103;
}
V_123 -> V_125 += V_232 ;
if ( ! ( V_123 -> V_172 || ( V_229 & V_174 ) ) )
V_233 = F_94 ( V_7 ) ;
if ( ! V_233 )
V_233 = V_232 ;
V_103:
F_100 ( V_7 ) ;
return V_233 ;
}
static unsigned int F_130 ( struct V_6 * V_7 )
{
struct V_235 V_236 , * V_237 = & V_7 -> V_238 ;
struct V_79 * V_80 ;
unsigned int V_18 ;
F_131 ( & V_236 ) ;
F_21 ( & V_237 -> V_19 ) ;
while ( ( V_80 = F_132 ( V_237 ) ) != NULL &&
F_133 ( V_80 ) ) {
F_134 ( F_6 ( V_7 ) , V_239 ,
F_88 ( V_7 ) ) ;
F_134 ( F_6 ( V_7 ) , V_240 ,
F_88 ( V_7 ) ) ;
F_135 ( & V_7 -> V_241 ) ;
F_136 ( V_80 , V_237 ) ;
F_137 ( & V_236 , V_80 ) ;
}
V_18 = V_80 ? V_80 -> V_125 : 0 ;
F_24 ( & V_237 -> V_19 ) ;
if ( ! F_123 ( & V_236 ) ) {
bool V_242 = F_138 ( V_7 ) ;
F_139 ( & V_236 ) ;
F_140 ( V_7 ) ;
F_141 ( V_7 , V_242 ) ;
}
return V_18 ;
}
int F_142 ( struct V_6 * V_7 , int V_243 , unsigned long V_244 )
{
switch ( V_243 ) {
case V_245 :
{
int V_246 = F_143 ( V_7 ) ;
return F_144 ( V_246 , ( int V_247 * ) V_244 ) ;
}
case V_248 :
{
unsigned int V_246 = F_130 ( V_7 ) ;
if ( V_246 )
V_246 -= sizeof( struct V_90 ) ;
return F_144 ( V_246 , ( int V_247 * ) V_244 ) ;
}
default:
return - V_249 ;
}
return 0 ;
}
int F_145 ( struct V_159 * V_160 , struct V_6 * V_7 , struct V_161 * V_162 ,
T_7 V_125 , int V_250 , int V_229 , int * V_251 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
F_101 ( struct V_188 * , sin , V_162 -> V_187 ) ;
struct V_79 * V_80 ;
unsigned int V_164 , V_252 ;
int V_253 , V_254 = 0 ;
int V_95 ;
int V_146 = F_88 ( V_7 ) ;
bool V_242 ;
if ( V_229 & V_255 )
return F_146 ( V_7 , V_162 , V_125 , V_251 ) ;
V_256:
V_80 = F_147 ( V_7 , V_229 | ( V_250 ? V_257 : 0 ) ,
& V_253 , & V_254 , & V_95 ) ;
if ( ! V_80 )
goto V_103;
V_164 = V_80 -> V_125 - sizeof( struct V_90 ) ;
V_252 = V_125 ;
if ( V_252 > V_164 )
V_252 = V_164 ;
else if ( V_252 < V_164 )
V_162 -> V_173 |= V_258 ;
if ( V_252 < V_164 || F_148 ( V_80 ) -> V_259 ) {
if ( F_133 ( V_80 ) )
goto V_260;
}
if ( F_149 ( V_80 ) )
V_95 = F_150 ( V_80 , sizeof( struct V_90 ) ,
V_162 , V_252 ) ;
else {
V_95 = F_151 ( V_80 , sizeof( struct V_90 ) ,
V_162 ) ;
if ( V_95 == - V_185 )
goto V_260;
}
if ( F_47 ( V_95 ) ) {
F_152 ( V_80 , F_145 ) ;
if ( ! V_253 ) {
F_135 ( & V_7 -> V_241 ) ;
F_93 ( F_6 ( V_7 ) ,
V_240 , V_146 ) ;
}
goto V_261;
}
if ( ! V_253 )
F_93 ( F_6 ( V_7 ) ,
V_262 , V_146 ) ;
F_153 ( V_162 , V_7 , V_80 ) ;
if ( sin ) {
sin -> V_191 = V_184 ;
sin -> V_196 = F_74 ( V_80 ) -> V_97 ;
sin -> V_194 . V_195 = F_57 ( V_80 ) -> V_48 ;
memset ( sin -> V_263 , 0 , sizeof( sin -> V_263 ) ) ;
* V_251 = sizeof( * sin ) ;
}
if ( V_60 -> V_264 )
F_154 ( V_162 , V_80 ) ;
V_95 = V_252 ;
if ( V_229 & V_258 )
V_95 = V_164 ;
V_261:
F_155 ( V_7 , V_80 ) ;
V_103:
return V_95 ;
V_260:
V_242 = F_138 ( V_7 ) ;
if ( ! F_156 ( V_7 , V_80 , V_229 ) ) {
F_93 ( F_6 ( V_7 ) , V_239 , V_146 ) ;
F_93 ( F_6 ( V_7 ) , V_240 , V_146 ) ;
}
F_141 ( V_7 , V_242 ) ;
if ( V_250 )
return - V_265 ;
V_162 -> V_173 &= ~ V_258 ;
goto V_256;
}
int F_157 ( struct V_6 * V_7 , int V_229 )
{
struct V_44 * V_60 = F_26 ( V_7 ) ;
V_7 -> V_117 = V_266 ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = 0 ;
F_158 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_267 & V_268 ) )
F_159 ( V_7 ) ;
if ( ! ( V_7 -> V_267 & V_269 ) ) {
V_7 -> V_24 -> V_270 ( V_7 ) ;
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
void F_165 ( struct V_6 * V_7 , T_8 V_271 )
{
if ( F_162 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_272 ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
V_272 = F_25 ( V_23 , V_271 ) ;
F_7 ( V_7 ) -> V_38 = V_271 ;
if ( V_17 != V_272 ) {
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_164 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_272 -> V_19 ) ;
F_30 ( & F_7 ( V_7 ) -> V_43 ,
& V_272 -> V_42 ) ;
V_272 -> V_35 ++ ;
F_13 ( & V_272 -> V_19 ) ;
F_24 ( & V_4 -> V_19 ) ;
}
}
}
static void F_166 ( struct V_6 * V_7 )
{
T_8 V_273 = F_33 ( F_6 ( V_7 ) ,
F_26 ( V_7 ) -> V_47 ,
F_26 ( V_7 ) -> V_41 ) ;
F_165 ( V_7 , V_273 ) ;
}
static int F_167 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
int V_274 ;
if ( F_26 ( V_7 ) -> V_63 ) {
F_168 ( V_7 , V_80 ) ;
F_169 ( V_7 , V_80 ) ;
F_170 ( V_7 ) ;
}
V_274 = F_171 ( V_7 , V_80 ) ;
if ( V_274 < 0 ) {
int V_146 = F_88 ( V_7 ) ;
if ( V_274 == - V_275 )
F_134 ( F_6 ( V_7 ) , V_276 ,
V_146 ) ;
F_134 ( F_6 ( V_7 ) , V_240 , V_146 ) ;
F_172 ( V_80 ) ;
F_173 ( V_274 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_174 ( void )
{
if ( ! F_175 ( & V_277 ) )
F_176 ( & V_277 ) ;
}
int F_177 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_274 ;
int V_146 = F_88 ( V_7 ) ;
if ( ! F_178 ( V_7 , V_278 , V_80 ) )
goto V_279;
F_179 ( V_80 ) ;
if ( F_180 ( & V_277 ) && V_123 -> V_280 ) {
int (* F_181)( struct V_6 * V_7 , struct V_79 * V_80 );
F_181 = F_182 ( V_123 -> F_181 ) ;
if ( V_80 -> V_125 > sizeof( struct V_90 ) && F_181 != NULL ) {
int V_233 ;
if ( F_133 ( V_80 ) )
goto V_281;
V_233 = F_181 ( V_7 , V_80 ) ;
if ( V_233 <= 0 ) {
F_134 ( F_6 ( V_7 ) ,
V_262 ,
V_146 ) ;
return - V_233 ;
}
}
}
if ( ( V_146 & V_282 ) && F_148 ( V_80 ) -> V_259 ) {
if ( V_123 -> V_283 == 0 ) {
F_121 ( L_3 ,
F_148 ( V_80 ) -> V_284 , V_80 -> V_125 ) ;
goto V_279;
}
if ( F_148 ( V_80 ) -> V_284 < V_123 -> V_283 ) {
F_121 ( L_4 ,
F_148 ( V_80 ) -> V_284 , V_123 -> V_283 ) ;
goto V_279;
}
}
if ( F_183 ( V_7 -> V_285 ) &&
F_133 ( V_80 ) )
goto V_281;
if ( F_184 ( V_7 , V_7 -> V_286 ) ) {
F_134 ( F_6 ( V_7 ) , V_276 ,
V_146 ) ;
goto V_279;
}
V_274 = 0 ;
F_185 ( V_7 , V_80 ) ;
F_186 ( V_7 ) ;
if ( ! F_187 ( V_7 ) )
V_274 = F_167 ( V_7 , V_80 ) ;
else if ( F_188 ( V_7 , V_80 , V_7 -> V_286 ) ) {
F_189 ( V_7 ) ;
goto V_279;
}
F_189 ( V_7 ) ;
return V_274 ;
V_281:
F_134 ( F_6 ( V_7 ) , V_239 , V_146 ) ;
V_279:
F_134 ( F_6 ( V_7 ) , V_240 , V_146 ) ;
F_135 ( & V_7 -> V_241 ) ;
F_172 ( V_80 ) ;
return - 1 ;
}
static void F_190 ( struct V_6 * * V_287 , unsigned int V_35 ,
struct V_79 * V_80 , unsigned int V_288 )
{
unsigned int V_289 ;
struct V_79 * V_290 = NULL ;
struct V_6 * V_7 ;
for ( V_289 = 0 ; V_289 < V_35 ; V_289 ++ ) {
V_7 = V_287 [ V_289 ] ;
if ( F_99 ( V_290 == NULL ) )
V_290 = ( V_289 == V_288 ) ? V_80 : F_191 ( V_80 , V_291 ) ;
if ( ! V_290 ) {
F_135 ( & V_7 -> V_241 ) ;
F_134 ( F_6 ( V_7 ) , V_276 ,
F_88 ( V_7 ) ) ;
F_134 ( F_6 ( V_7 ) , V_240 ,
F_88 ( V_7 ) ) ;
}
if ( V_290 && F_177 ( V_7 , V_290 ) <= 0 )
V_290 = NULL ;
F_49 ( V_7 ) ;
}
if ( F_47 ( V_290 ) )
F_172 ( V_290 ) ;
}
static void F_192 ( struct V_6 * V_7 , struct V_292 * V_127 )
{
struct V_292 * V_293 ;
F_193 ( V_127 ) ;
V_293 = F_194 ( & V_7 -> V_294 , V_127 ) ;
F_195 ( V_293 ) ;
}
static int F_196 ( struct V_1 * V_1 , struct V_79 * V_80 ,
struct V_90 * V_91 ,
T_3 V_48 , T_3 V_56 ,
struct V_22 * V_23 ,
int V_295 )
{
struct V_6 * V_7 , * V_287 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_10 * V_11 ;
unsigned short V_54 = F_51 ( V_91 -> V_96 ) ;
struct V_3 * V_4 = F_19 ( V_23 , V_1 , V_54 ) ;
int V_58 = V_80 -> V_83 -> V_98 ;
unsigned int V_35 = 0 , V_128 = F_78 ( F_197 ( * V_7 ) , V_296 ) ;
unsigned int V_77 = 0 , V_297 = 0 , V_298 = ( V_4 -> V_35 > 10 ) ;
bool V_299 = false ;
if ( V_298 ) {
V_297 = F_33 ( V_1 , F_37 ( V_52 ) , V_54 ) &
V_22 . V_32 ;
V_77 = F_33 ( V_1 , V_56 , V_54 ) & V_22 . V_32 ;
V_300:
V_4 = & V_22 . V_77 [ V_77 ] ;
V_128 = F_78 ( F_197 ( * V_7 ) , V_301 . V_302 ) ;
}
F_11 ( & V_4 -> V_19 ) ;
F_198 (sk, node, &hslot->head, offset) {
if ( F_62 ( V_1 , V_7 ,
V_91 -> V_96 , V_56 ,
V_91 -> V_97 , V_48 ,
V_58 , V_54 ) ) {
if ( F_47 ( V_35 == F_199 ( V_287 ) ) ) {
F_190 ( V_287 , V_35 , V_80 , ~ 0 ) ;
V_299 = true ;
V_35 = 0 ;
}
V_287 [ V_35 ++ ] = V_7 ;
F_200 ( V_7 ) ;
}
}
F_13 ( & V_4 -> V_19 ) ;
if ( V_298 && V_77 != V_297 ) {
V_77 = V_297 ;
goto V_300;
}
if ( V_35 ) {
F_190 ( V_287 , V_35 , V_80 , V_35 - 1 ) ;
} else {
if ( ! V_299 )
F_134 ( V_1 , V_303 ,
V_295 == V_304 ) ;
F_201 ( V_80 ) ;
}
return 0 ;
}
static inline int F_202 ( struct V_79 * V_80 , struct V_90 * V_91 ,
int V_295 )
{
int V_95 ;
F_148 ( V_80 ) -> V_259 = 0 ;
F_148 ( V_80 ) -> V_284 = V_80 -> V_125 ;
if ( V_295 == V_304 ) {
V_95 = F_203 ( V_80 , V_91 ) ;
if ( V_95 )
return V_95 ;
}
return F_204 ( V_80 , V_295 , V_91 -> V_133 ,
V_305 ) ;
}
int F_205 ( struct V_79 * V_80 , struct V_22 * V_23 ,
int V_295 )
{
struct V_6 * V_7 ;
struct V_90 * V_91 ;
unsigned short V_164 ;
struct V_167 * V_168 = F_206 ( V_80 ) ;
T_3 V_48 , V_56 ;
struct V_1 * V_1 = F_58 ( V_80 -> V_83 ) ;
if ( ! F_207 ( V_80 , sizeof( struct V_90 ) ) )
goto V_279;
V_91 = F_74 ( V_80 ) ;
V_164 = F_51 ( V_91 -> V_125 ) ;
V_48 = F_57 ( V_80 ) -> V_48 ;
V_56 = F_57 ( V_80 ) -> V_56 ;
if ( V_164 > V_80 -> V_125 )
goto V_306;
if ( V_295 == V_134 ) {
if ( V_164 < sizeof( * V_91 ) || F_208 ( V_80 , V_164 ) )
goto V_306;
V_91 = F_74 ( V_80 ) ;
}
if ( F_202 ( V_80 , V_91 , V_295 ) )
goto V_281;
V_7 = F_209 ( V_80 ) ;
if ( V_7 ) {
struct V_292 * V_127 = F_59 ( V_80 ) ;
int V_233 ;
if ( F_47 ( V_7 -> V_294 != V_127 ) )
F_192 ( V_7 , V_127 ) ;
V_233 = F_177 ( V_7 , V_80 ) ;
F_49 ( V_7 ) ;
if ( V_233 > 0 )
return - V_233 ;
return 0 ;
}
if ( V_168 -> V_219 & ( V_220 | V_307 ) )
return F_196 ( V_1 , V_80 , V_91 ,
V_48 , V_56 , V_23 , V_295 ) ;
V_7 = F_56 ( V_80 , V_91 -> V_97 , V_91 -> V_96 , V_23 ) ;
if ( V_7 != NULL ) {
int V_233 ;
if ( F_7 ( V_7 ) -> V_308 && V_91 -> V_133 && ! F_88 ( V_7 ) )
F_210 ( V_80 , V_134 , V_91 -> V_133 ,
V_305 ) ;
V_233 = F_177 ( V_7 , V_80 ) ;
F_49 ( V_7 ) ;
if ( V_233 > 0 )
return - V_233 ;
return 0 ;
}
if ( ! F_178 ( NULL , V_278 , V_80 ) )
goto V_279;
F_179 ( V_80 ) ;
if ( F_133 ( V_80 ) )
goto V_281;
F_134 ( V_1 , V_309 , V_295 == V_304 ) ;
F_211 ( V_80 , V_106 , V_310 , 0 ) ;
F_172 ( V_80 ) ;
return 0 ;
V_306:
F_121 ( L_5 ,
V_295 == V_304 ? L_6 : L_7 ,
& V_48 , F_51 ( V_91 -> V_97 ) ,
V_164 , V_80 -> V_125 ,
& V_56 , F_51 ( V_91 -> V_96 ) ) ;
goto V_279;
V_281:
F_121 ( L_8 ,
V_295 == V_304 ? L_6 : L_7 ,
& V_48 , F_51 ( V_91 -> V_97 ) , & V_56 , F_51 ( V_91 -> V_96 ) ,
V_164 ) ;
F_134 ( V_1 , V_239 , V_295 == V_304 ) ;
V_279:
F_134 ( V_1 , V_240 , V_295 == V_304 ) ;
F_172 ( V_80 ) ;
return 0 ;
}
static struct V_6 * F_212 ( struct V_1 * V_1 ,
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
static struct V_6 * F_213 ( struct V_1 * V_1 ,
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
F_214 ( V_311 , V_87 , V_85 ) ;
const T_9 V_312 = F_215 ( V_86 , V_54 ) ;
F_53 () ;
V_70 = NULL ;
F_44 (sk, node, &hslot2->head) {
if ( F_216 ( V_7 , V_1 , V_311 ,
V_87 , V_85 , V_312 , V_58 ) )
V_70 = V_7 ;
break;
}
if ( V_70 ) {
if ( F_47 ( ! F_48 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_47 ( ! F_216 ( V_7 , V_1 , V_311 ,
V_87 , V_85 ,
V_312 , V_58 ) ) ) {
F_49 ( V_70 ) ;
V_70 = NULL ;
}
}
F_54 () ;
return V_70 ;
}
void F_217 ( struct V_79 * V_80 )
{
struct V_1 * V_1 = F_58 ( V_80 -> V_83 ) ;
const struct V_81 * V_82 ;
const struct V_90 * V_91 ;
struct V_6 * V_7 ;
struct V_292 * V_127 ;
int V_58 = V_80 -> V_83 -> V_98 ;
if ( ! F_207 ( V_80 , F_75 ( V_80 ) + sizeof( struct V_90 ) ) )
return;
V_82 = F_57 ( V_80 ) ;
V_91 = F_74 ( V_80 ) ;
if ( V_80 -> V_313 == V_314 ||
V_80 -> V_313 == V_315 )
V_7 = F_212 ( V_1 , V_91 -> V_96 , V_82 -> V_56 ,
V_91 -> V_97 , V_82 -> V_48 , V_58 ) ;
else if ( V_80 -> V_313 == V_316 )
V_7 = F_213 ( V_1 , V_91 -> V_96 , V_82 -> V_56 ,
V_91 -> V_97 , V_82 -> V_48 , V_58 ) ;
else
return;
if ( ! V_7 )
return;
V_80 -> V_7 = V_7 ;
V_80 -> V_317 = V_318 ;
V_127 = V_7 -> V_294 ;
if ( V_127 )
V_127 = F_218 ( V_127 , 0 ) ;
if ( V_127 )
F_219 ( V_80 , V_127 ) ;
}
int F_220 ( struct V_79 * V_80 )
{
return F_205 ( V_80 , & V_22 , V_134 ) ;
}
void F_221 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
bool V_242 = F_138 ( V_7 ) ;
F_71 ( V_7 ) ;
F_141 ( V_7 , V_242 ) ;
if ( F_180 ( & V_277 ) && V_123 -> V_280 ) {
void (* F_222)( struct V_6 * V_7 );
F_222 = F_182 ( V_123 -> F_222 ) ;
if ( F_222 )
F_222 ( V_7 ) ;
}
}
int F_223 ( struct V_6 * V_7 , int V_319 , int V_320 ,
char V_247 * V_321 , unsigned int V_205 ,
int (* F_224)( struct V_6 * ) )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_322 , V_323 ;
int V_95 = 0 ;
int V_146 = F_88 ( V_7 ) ;
if ( V_205 < sizeof( int ) )
return - V_185 ;
if ( F_225 ( V_322 , ( int V_247 * ) V_321 ) )
return - V_324 ;
V_323 = V_322 ? 1 : 0 ;
switch ( V_320 ) {
case V_325 :
if ( V_322 != 0 ) {
V_123 -> V_172 = 1 ;
} else {
V_123 -> V_172 = 0 ;
F_98 ( V_7 ) ;
F_224 ( V_7 ) ;
F_100 ( V_7 ) ;
}
break;
case V_326 :
switch ( V_322 ) {
case 0 :
case V_327 :
case V_328 :
V_123 -> F_181 = V_329 ;
case V_330 :
V_123 -> V_280 = V_322 ;
F_174 () ;
break;
default:
V_95 = - V_331 ;
break;
}
break;
case V_332 :
V_123 -> V_333 = V_323 ;
break;
case V_334 :
V_123 -> V_335 = V_323 ;
break;
case V_336 :
if ( ! V_146 )
return - V_331 ;
if ( V_322 != 0 && V_322 < 8 )
V_322 = 8 ;
else if ( V_322 > V_337 )
V_322 = V_337 ;
V_123 -> V_338 = V_322 ;
V_123 -> V_339 |= V_340 ;
break;
case V_341 :
if ( ! V_146 )
return - V_331 ;
if ( V_322 != 0 && V_322 < 8 )
V_322 = 8 ;
else if ( V_322 > V_337 )
V_322 = V_337 ;
V_123 -> V_283 = V_322 ;
V_123 -> V_339 |= V_282 ;
break;
default:
V_95 = - V_331 ;
break;
}
return V_95 ;
}
int F_226 ( struct V_6 * V_7 , int V_319 , int V_320 ,
char V_247 * V_321 , unsigned int V_205 )
{
if ( V_319 == V_342 || V_319 == V_343 )
return F_223 ( V_7 , V_319 , V_320 , V_321 , V_205 ,
F_94 ) ;
return F_227 ( V_7 , V_319 , V_320 , V_321 , V_205 ) ;
}
int F_228 ( struct V_6 * V_7 , int V_319 , int V_320 ,
char V_247 * V_321 , unsigned int V_205 )
{
if ( V_319 == V_342 || V_319 == V_343 )
return F_223 ( V_7 , V_319 , V_320 , V_321 , V_205 ,
F_94 ) ;
return F_229 ( V_7 , V_319 , V_320 , V_321 , V_205 ) ;
}
int F_230 ( struct V_6 * V_7 , int V_319 , int V_320 ,
char V_247 * V_321 , int V_247 * V_205 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_322 , V_125 ;
if ( F_225 ( V_125 , V_205 ) )
return - V_324 ;
V_125 = F_231 (unsigned int, len, sizeof(int)) ;
if ( V_125 < 0 )
return - V_185 ;
switch ( V_320 ) {
case V_325 :
V_322 = V_123 -> V_172 ;
break;
case V_326 :
V_322 = V_123 -> V_280 ;
break;
case V_332 :
V_322 = V_123 -> V_333 ;
break;
case V_334 :
V_322 = V_123 -> V_335 ;
break;
case V_336 :
V_322 = V_123 -> V_338 ;
break;
case V_341 :
V_322 = V_123 -> V_283 ;
break;
default:
return - V_331 ;
}
if ( F_144 ( V_125 , V_205 ) )
return - V_324 ;
if ( F_232 ( V_321 , & V_322 , V_125 ) )
return - V_324 ;
return 0 ;
}
int F_233 ( struct V_6 * V_7 , int V_319 , int V_320 ,
char V_247 * V_321 , int V_247 * V_205 )
{
if ( V_319 == V_342 || V_319 == V_343 )
return F_230 ( V_7 , V_319 , V_320 , V_321 , V_205 ) ;
return F_234 ( V_7 , V_319 , V_320 , V_321 , V_205 ) ;
}
int F_235 ( struct V_6 * V_7 , int V_319 , int V_320 ,
char V_247 * V_321 , int V_247 * V_205 )
{
if ( V_319 == V_342 || V_319 == V_343 )
return F_230 ( V_7 , V_319 , V_320 , V_321 , V_205 ) ;
return F_236 ( V_7 , V_319 , V_320 , V_321 , V_205 ) ;
}
unsigned int F_237 ( struct V_344 * V_344 , struct V_345 * V_6 , T_10 * V_346 )
{
unsigned int V_32 = F_238 ( V_344 , V_6 , V_346 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_239 ( V_7 ) ;
if ( ( V_32 & V_347 ) && ! ( V_344 -> V_348 & V_349 ) &&
! ( V_7 -> V_350 & V_351 ) && ! F_130 ( V_7 ) )
V_32 &= ~ ( V_352 | V_347 ) ;
return V_32 ;
}
static struct V_6 * F_240 ( struct V_353 * V_354 , int V_355 )
{
struct V_6 * V_7 ;
struct V_356 * V_357 = V_354 -> V_358 ;
struct V_1 * V_1 = F_241 ( V_354 ) ;
for ( V_357 -> V_359 = V_355 ; V_357 -> V_359 <= V_357 -> V_22 -> V_32 ;
++ V_357 -> V_359 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_357 -> V_22 -> V_74 [ V_357 -> V_359 ] ;
if ( F_242 ( & V_4 -> V_42 ) )
continue;
F_21 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_61 == V_357 -> V_360 )
goto V_33;
}
F_24 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_33:
return V_7 ;
}
static struct V_6 * F_243 ( struct V_353 * V_354 , struct V_6 * V_7 )
{
struct V_356 * V_357 = V_354 -> V_358 ;
struct V_1 * V_1 = F_241 ( V_354 ) ;
do {
V_7 = F_244 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_61 != V_357 -> V_360 ) );
if ( ! V_7 ) {
if ( V_357 -> V_359 <= V_357 -> V_22 -> V_32 )
F_24 ( & V_357 -> V_22 -> V_74 [ V_357 -> V_359 ] . V_19 ) ;
return F_240 ( V_354 , V_357 -> V_359 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_245 ( struct V_353 * V_354 , T_11 V_361 )
{
struct V_6 * V_7 = F_240 ( V_354 , 0 ) ;
if ( V_7 )
while ( V_361 && ( V_7 = F_243 ( V_354 , V_7 ) ) != NULL )
-- V_361 ;
return V_361 ? NULL : V_7 ;
}
static void * F_246 ( struct V_353 * V_354 , T_11 * V_361 )
{
struct V_356 * V_357 = V_354 -> V_358 ;
V_357 -> V_359 = V_362 ;
return * V_361 ? F_245 ( V_354 , * V_361 - 1 ) : V_363 ;
}
static void * F_247 ( struct V_353 * V_354 , void * V_364 , T_11 * V_361 )
{
struct V_6 * V_7 ;
if ( V_364 == V_363 )
V_7 = F_245 ( V_354 , 0 ) ;
else
V_7 = F_243 ( V_354 , V_364 ) ;
++ * V_361 ;
return V_7 ;
}
static void F_248 ( struct V_353 * V_354 , void * V_364 )
{
struct V_356 * V_357 = V_354 -> V_358 ;
if ( V_357 -> V_359 <= V_357 -> V_22 -> V_32 )
F_24 ( & V_357 -> V_22 -> V_74 [ V_357 -> V_359 ] . V_19 ) ;
}
int F_249 ( struct V_365 * V_365 , struct V_344 * V_344 )
{
struct V_366 * V_367 = F_250 ( V_365 ) ;
struct V_356 * V_368 ;
int V_95 ;
V_95 = F_251 ( V_365 , V_344 , & V_367 -> V_369 ,
sizeof( struct V_356 ) ) ;
if ( V_95 < 0 )
return V_95 ;
V_368 = ( (struct V_353 * ) V_344 -> V_370 ) -> V_358 ;
V_368 -> V_360 = V_367 -> V_360 ;
V_368 -> V_22 = V_367 -> V_22 ;
return V_95 ;
}
int F_252 ( struct V_1 * V_1 , struct V_366 * V_367 )
{
struct V_371 * V_372 ;
int V_274 = 0 ;
V_367 -> V_369 . V_355 = F_246 ;
V_367 -> V_369 . V_373 = F_247 ;
V_367 -> V_369 . V_374 = F_248 ;
V_372 = F_253 ( V_367 -> V_375 , V_376 , V_1 -> V_377 ,
V_367 -> V_378 , V_367 ) ;
if ( ! V_372 )
V_274 = - V_275 ;
return V_274 ;
}
void F_254 ( struct V_1 * V_1 , struct V_366 * V_367 )
{
F_255 ( V_367 -> V_375 , V_1 -> V_377 ) ;
}
static void F_256 ( struct V_6 * V_379 , struct V_353 * V_380 ,
int V_359 )
{
struct V_44 * V_60 = F_26 ( V_379 ) ;
T_3 V_96 = V_60 -> V_63 ;
T_3 V_126 = V_60 -> V_47 ;
T_1 V_381 = F_51 ( V_60 -> V_64 ) ;
T_1 V_382 = F_51 ( V_60 -> V_147 ) ;
F_257 ( V_380 , L_9
L_10 ,
V_359 , V_126 , V_382 , V_96 , V_381 , V_379 -> V_117 ,
F_143 ( V_379 ) ,
F_258 ( V_379 ) ,
0 , 0L , 0 ,
F_259 ( F_260 ( V_380 ) , F_3 ( V_379 ) ) ,
0 , F_261 ( V_379 ) ,
F_262 ( & V_379 -> V_76 ) , V_379 ,
F_262 ( & V_379 -> V_241 ) ) ;
}
int F_263 ( struct V_353 * V_354 , void * V_364 )
{
F_264 ( V_354 , 127 ) ;
if ( V_364 == V_363 )
F_265 ( V_354 , L_11
L_12
L_13 ) ;
else {
struct V_356 * V_357 = V_354 -> V_358 ;
F_256 ( V_364 , V_354 , V_357 -> V_359 ) ;
}
F_266 ( V_354 , '\n' ) ;
return 0 ;
}
static int T_12 F_267 ( struct V_1 * V_1 )
{
return F_252 ( V_1 , & V_383 ) ;
}
static void T_13 F_268 ( struct V_1 * V_1 )
{
F_254 ( V_1 , & V_383 ) ;
}
int T_14 F_269 ( void )
{
return F_270 ( & V_384 ) ;
}
void F_271 ( void )
{
F_272 ( & V_384 ) ;
}
static int T_14 F_273 ( char * V_385 )
{
T_15 V_233 ;
if ( ! V_385 )
return 0 ;
V_233 = F_274 ( V_385 , 0 , & V_386 ) ;
if ( V_233 )
return 0 ;
if ( V_386 && V_386 < V_387 )
V_386 = V_387 ;
return 1 ;
}
void T_14 F_275 ( struct V_22 * V_388 , const char * V_375 )
{
unsigned int V_289 ;
V_388 -> V_74 = F_276 ( V_375 ,
2 * sizeof( struct V_3 ) ,
V_386 ,
21 ,
0 ,
& V_388 -> log ,
& V_388 -> V_32 ,
V_387 ,
64 * 1024 ) ;
V_388 -> V_77 = V_388 -> V_74 + ( V_388 -> V_32 + 1 ) ;
for ( V_289 = 0 ; V_289 <= V_388 -> V_32 ; V_289 ++ ) {
F_277 ( & V_388 -> V_74 [ V_289 ] . V_42 , V_289 ) ;
V_388 -> V_74 [ V_289 ] . V_35 = 0 ;
F_278 ( & V_388 -> V_74 [ V_289 ] . V_19 ) ;
}
for ( V_289 = 0 ; V_289 <= V_388 -> V_32 ; V_289 ++ ) {
F_277 ( & V_388 -> V_77 [ V_289 ] . V_42 , V_289 ) ;
V_388 -> V_77 [ V_289 ] . V_35 = 0 ;
F_278 ( & V_388 -> V_77 [ V_289 ] . V_19 ) ;
}
}
void T_14 F_279 ( void )
{
unsigned long V_389 ;
F_275 ( & V_22 , L_14 ) ;
V_389 = F_280 () / 8 ;
V_389 = F_281 ( V_389 , 128UL ) ;
V_390 [ 0 ] = V_389 / 4 * 3 ;
V_390 [ 1 ] = V_389 ;
V_390 [ 2 ] = V_390 [ 0 ] * 2 ;
V_391 = V_392 ;
V_393 = V_392 ;
}
