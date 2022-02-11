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
static T_3 F_33 ( const struct V_1 * V_1 , T_4 V_48 ,
unsigned int V_49 )
{
return F_34 ( ( V_50 T_3 ) V_48 , F_35 ( V_1 ) ) ^ V_49 ;
}
int F_36 ( struct V_6 * V_7 , unsigned short V_20 )
{
unsigned int V_21 =
F_33 ( F_6 ( V_7 ) , F_37 ( V_51 ) , V_20 ) ;
unsigned int V_52 =
F_33 ( F_6 ( V_7 ) , F_26 ( V_7 ) -> V_47 , 0 ) ;
F_7 ( V_7 ) -> V_38 = V_52 ;
return F_14 ( V_7 , V_20 , F_31 , V_21 ) ;
}
static inline int F_38 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_48 , unsigned short V_53 , T_5 V_54 ,
T_4 V_55 , T_5 V_56 , int V_57 )
{
int V_58 ;
struct V_44 * V_59 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_13 != V_53 ||
F_32 ( V_7 ) )
return - 1 ;
V_58 = ( V_7 -> V_60 == V_61 ) ? 2 : 1 ;
V_59 = F_26 ( V_7 ) ;
if ( V_59 -> V_47 ) {
if ( V_59 -> V_47 != V_55 )
return - 1 ;
V_58 += 4 ;
}
if ( V_59 -> V_62 ) {
if ( V_59 -> V_62 != V_48 )
return - 1 ;
V_58 += 4 ;
}
if ( V_59 -> V_63 ) {
if ( V_59 -> V_63 != V_54 )
return - 1 ;
V_58 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_57 )
return - 1 ;
V_58 += 4 ;
}
if ( V_7 -> V_64 == F_39 () )
V_58 ++ ;
return V_58 ;
}
static inline int F_40 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_48 , T_5 V_54 ,
T_4 V_55 , unsigned int V_53 , int V_57 )
{
int V_58 ;
struct V_44 * V_59 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_32 ( V_7 ) )
return - 1 ;
V_59 = F_26 ( V_7 ) ;
if ( V_59 -> V_47 != V_55 ||
V_59 -> V_41 != V_53 )
return - 1 ;
V_58 = ( V_7 -> V_60 == V_61 ) ? 2 : 1 ;
if ( V_59 -> V_62 ) {
if ( V_59 -> V_62 != V_48 )
return - 1 ;
V_58 += 4 ;
}
if ( V_59 -> V_63 ) {
if ( V_59 -> V_63 != V_54 )
return - 1 ;
V_58 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_57 )
return - 1 ;
V_58 += 4 ;
}
if ( V_7 -> V_64 == F_39 () )
V_58 ++ ;
return V_58 ;
}
static T_3 F_41 ( const struct V_1 * V_1 , const T_4 V_65 ,
const T_1 V_66 , const T_4 V_67 ,
const T_5 V_68 )
{
static T_3 T_6 V_69 ;
F_42 ( & T_6 , sizeof( T_6 ) ) ;
return F_43 ( V_65 , V_66 , V_67 , V_68 ,
T_6 + F_35 ( V_1 ) ) ;
}
static struct V_6 * F_44 ( struct V_1 * V_1 ,
T_4 V_48 , T_5 V_54 ,
T_4 V_55 , unsigned int V_53 , int V_57 ,
struct V_3 * V_17 , unsigned int V_37 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
int V_58 , V_71 , V_72 = 0 , V_73 = 0 ;
T_3 V_74 = 0 ;
V_75:
V_70 = NULL ;
V_71 = 0 ;
F_45 (sk, node, &hslot2->head) {
V_58 = F_40 ( V_7 , V_1 , V_48 , V_54 ,
V_55 , V_53 , V_57 ) ;
if ( V_58 > V_71 ) {
V_70 = V_7 ;
V_71 = V_58 ;
V_73 = V_7 -> V_16 ;
if ( V_73 ) {
V_74 = F_41 ( V_1 , V_55 , V_53 ,
V_48 , V_54 ) ;
V_72 = 1 ;
}
} else if ( V_58 == V_71 && V_73 ) {
V_72 ++ ;
if ( F_18 ( V_74 , V_72 ) == 0 )
V_70 = V_7 ;
V_74 = F_46 ( V_74 ) ;
}
}
if ( F_47 ( V_11 ) != V_37 )
goto V_75;
if ( V_70 ) {
if ( F_48 ( ! F_49 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_48 ( F_40 ( V_70 , V_1 , V_48 , V_54 ,
V_55 , V_53 , V_57 ) < V_71 ) ) {
F_50 ( V_70 ) ;
goto V_75;
}
}
return V_70 ;
}
struct V_6 * F_51 ( struct V_1 * V_1 , T_4 V_48 ,
T_5 V_54 , T_4 V_55 , T_5 V_56 ,
int V_57 , struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_52 ( V_56 ) ;
unsigned int V_77 , V_37 , V_78 = F_53 ( V_1 , V_53 , V_23 -> V_32 ) ;
struct V_3 * V_17 , * V_4 = & V_23 -> V_74 [ V_78 ] ;
int V_58 , V_71 , V_72 = 0 , V_73 = 0 ;
T_3 V_74 = 0 ;
F_54 () ;
if ( V_4 -> V_35 > 10 ) {
V_77 = F_33 ( V_1 , V_55 , V_53 ) ;
V_37 = V_77 & V_23 -> V_32 ;
V_17 = & V_23 -> V_77 [ V_37 ] ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_75;
V_70 = F_44 ( V_1 , V_48 , V_54 ,
V_55 , V_53 , V_57 ,
V_17 , V_37 ) ;
if ( ! V_70 ) {
V_77 = F_33 ( V_1 , F_37 ( V_51 ) , V_53 ) ;
V_37 = V_77 & V_23 -> V_32 ;
V_17 = & V_23 -> V_77 [ V_37 ] ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_75;
V_70 = F_44 ( V_1 , V_48 , V_54 ,
F_37 ( V_51 ) , V_53 , V_57 ,
V_17 , V_37 ) ;
}
F_55 () ;
return V_70 ;
}
V_75:
V_70 = NULL ;
V_71 = 0 ;
F_56 (sk, node, &hslot->head) {
V_58 = F_38 ( V_7 , V_1 , V_48 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) ;
if ( V_58 > V_71 ) {
V_70 = V_7 ;
V_71 = V_58 ;
V_73 = V_7 -> V_16 ;
if ( V_73 ) {
V_74 = F_41 ( V_1 , V_55 , V_53 ,
V_48 , V_54 ) ;
V_72 = 1 ;
}
} else if ( V_58 == V_71 && V_73 ) {
V_72 ++ ;
if ( F_18 ( V_74 , V_72 ) == 0 )
V_70 = V_7 ;
V_74 = F_46 ( V_74 ) ;
}
}
if ( F_47 ( V_11 ) != V_78 )
goto V_75;
if ( V_70 ) {
if ( F_48 ( ! F_49 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_48 ( F_38 ( V_70 , V_1 , V_48 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) < V_71 ) ) {
F_50 ( V_70 ) ;
goto V_75;
}
}
F_55 () ;
return V_70 ;
}
static inline struct V_6 * F_57 ( struct V_79 * V_80 ,
T_5 V_54 , T_5 V_56 ,
struct V_22 * V_23 )
{
const struct V_81 * V_82 = F_58 ( V_80 ) ;
return F_51 ( F_59 ( F_60 ( V_80 ) -> V_83 ) , V_82 -> V_48 , V_54 ,
V_82 -> V_55 , V_56 , F_61 ( V_80 ) ,
V_23 ) ;
}
struct V_6 * F_62 ( struct V_1 * V_1 , T_4 V_48 , T_5 V_54 ,
T_4 V_55 , T_5 V_56 , int V_57 )
{
return F_51 ( V_1 , V_48 , V_54 , V_55 , V_56 , V_57 , & V_22 ) ;
}
static inline bool F_63 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_5 V_84 , T_4 V_85 ,
T_5 V_86 , T_4 V_87 ,
int V_57 , unsigned short V_53 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_13 != V_53 ||
( V_59 -> V_62 && V_59 -> V_62 != V_87 ) ||
( V_59 -> V_63 != V_86 && V_59 -> V_63 ) ||
( V_59 -> V_47 && V_59 -> V_47 != V_85 ) ||
F_32 ( V_7 ) ||
( V_7 -> V_15 && V_7 -> V_15 != V_57 ) )
return false ;
if ( ! F_64 ( V_7 , V_85 , V_87 , V_57 ) )
return false ;
return true ;
}
void F_65 ( struct V_79 * V_80 , T_3 V_88 , struct V_22 * V_23 )
{
struct V_44 * V_59 ;
const struct V_81 * V_82 = ( const struct V_81 * ) V_80 -> V_89 ;
struct V_90 * V_91 = (struct V_90 * ) ( V_80 -> V_89 + ( V_82 -> V_92 << 2 ) ) ;
const int type = F_66 ( V_80 ) -> type ;
const int V_93 = F_66 ( V_80 ) -> V_93 ;
struct V_6 * V_7 ;
int V_94 ;
int V_95 ;
struct V_1 * V_1 = F_59 ( V_80 -> V_83 ) ;
V_7 = F_51 ( V_1 , V_82 -> V_55 , V_91 -> V_96 ,
V_82 -> V_48 , V_91 -> V_97 , V_80 -> V_83 -> V_98 , V_23 ) ;
if ( ! V_7 ) {
F_67 ( V_1 , V_99 ) ;
return;
}
V_95 = 0 ;
V_94 = 0 ;
V_59 = F_26 ( V_7 ) ;
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
F_68 ( V_80 , V_7 , V_88 ) ;
if ( V_59 -> V_108 != V_109 ) {
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
F_69 ( V_80 , V_7 ) ;
goto V_103;
}
if ( ! V_59 -> V_116 ) {
if ( ! V_94 || V_7 -> V_117 != V_118 )
goto V_103;
} else
F_70 ( V_7 , V_80 , V_95 , V_91 -> V_96 , V_88 , ( V_119 * ) ( V_91 + 1 ) ) ;
V_7 -> V_120 = V_95 ;
V_7 -> V_121 ( V_7 ) ;
V_103:
F_50 ( V_7 ) ;
}
void F_71 ( struct V_79 * V_80 , T_3 V_88 )
{
F_65 ( V_80 , V_88 , & V_22 ) ;
}
void F_72 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
if ( V_123 -> V_124 ) {
V_123 -> V_125 = 0 ;
V_123 -> V_124 = 0 ;
F_73 ( V_7 ) ;
}
}
void F_74 ( struct V_79 * V_80 , T_4 V_126 , T_4 V_127 )
{
struct V_90 * V_91 = F_75 ( V_80 ) ;
int V_128 = F_76 ( V_80 ) ;
int V_125 = V_80 -> V_125 - V_128 ;
int V_129 = V_125 ;
T_7 V_130 = 0 ;
if ( ! F_77 ( V_80 ) ) {
V_80 -> V_131 = F_78 ( V_80 ) - V_80 -> V_42 ;
V_80 -> V_132 = F_79 ( struct V_90 , V_133 ) ;
V_91 -> V_133 = ~ F_80 ( V_126 , V_127 , V_125 ,
V_134 , 0 ) ;
} else {
struct V_79 * V_135 ;
F_81 (skb, frags) {
V_130 = F_82 ( V_130 , V_135 -> V_130 ) ;
V_129 -= V_135 -> V_125 ;
}
V_130 = F_83 ( V_80 , V_128 , V_129 , V_130 ) ;
V_80 -> V_136 = V_137 ;
V_91 -> V_133 = F_80 ( V_126 , V_127 , V_125 , V_134 , V_130 ) ;
if ( V_91 -> V_133 == 0 )
V_91 -> V_133 = V_138 ;
}
}
void F_84 ( bool V_139 , struct V_79 * V_80 ,
T_4 V_48 , T_4 V_55 , int V_125 )
{
struct V_90 * V_91 = F_75 ( V_80 ) ;
if ( V_139 )
V_91 -> V_133 = 0 ;
else if ( F_85 ( V_80 ) )
V_91 -> V_133 = ~ F_86 ( V_125 , V_48 , V_55 , 0 ) ;
else if ( F_60 ( V_80 ) && F_60 ( V_80 ) -> V_83 &&
( F_60 ( V_80 ) -> V_83 -> V_140 & V_141 ) ) {
F_87 ( V_80 -> V_136 == V_142 ) ;
V_80 -> V_136 = V_142 ;
V_80 -> V_131 = F_78 ( V_80 ) - V_80 -> V_42 ;
V_80 -> V_132 = F_79 ( struct V_90 , V_133 ) ;
V_91 -> V_133 = ~ F_86 ( V_125 , V_48 , V_55 , 0 ) ;
} else {
T_7 V_130 ;
F_87 ( V_80 -> V_136 == V_142 ) ;
V_91 -> V_133 = 0 ;
V_130 = F_83 ( V_80 , 0 , V_125 , 0 ) ;
V_91 -> V_133 = F_86 ( V_125 , V_48 , V_55 , V_130 ) ;
if ( V_91 -> V_133 == 0 )
V_91 -> V_133 = V_138 ;
V_80 -> V_136 = V_143 ;
}
}
static int F_88 ( struct V_79 * V_80 , struct V_144 * V_145 )
{
struct V_6 * V_7 = V_80 -> V_7 ;
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_90 * V_91 ;
int V_95 = 0 ;
int V_146 = F_89 ( V_7 ) ;
int V_128 = F_76 ( V_80 ) ;
int V_125 = V_80 -> V_125 - V_128 ;
T_7 V_130 = 0 ;
V_91 = F_75 ( V_80 ) ;
V_91 -> V_97 = V_59 -> V_147 ;
V_91 -> V_96 = V_145 -> V_148 ;
V_91 -> V_125 = F_90 ( V_125 ) ;
V_91 -> V_133 = 0 ;
if ( V_146 )
V_130 = F_91 ( V_80 ) ;
else if ( V_7 -> V_149 ) {
V_80 -> V_136 = V_137 ;
goto V_150;
} else if ( V_80 -> V_136 == V_142 ) {
F_74 ( V_80 , V_145 -> V_48 , V_145 -> V_55 ) ;
goto V_150;
} else
V_130 = F_92 ( V_80 ) ;
V_91 -> V_133 = F_80 ( V_145 -> V_48 , V_145 -> V_55 , V_125 ,
V_7 -> V_151 , V_130 ) ;
if ( V_91 -> V_133 == 0 )
V_91 -> V_133 = V_138 ;
V_150:
V_95 = F_93 ( F_6 ( V_7 ) , V_80 ) ;
if ( V_95 ) {
if ( V_95 == - V_152 && ! V_59 -> V_116 ) {
F_94 ( F_6 ( V_7 ) ,
V_153 , V_146 ) ;
V_95 = 0 ;
}
} else
F_94 ( F_6 ( V_7 ) ,
V_154 , V_146 ) ;
return V_95 ;
}
int F_95 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_144 * V_145 = & V_59 -> V_155 . V_156 . V_157 . V_158 ;
struct V_79 * V_80 ;
int V_95 = 0 ;
V_80 = F_96 ( V_7 , V_145 ) ;
if ( ! V_80 )
goto V_103;
V_95 = F_88 ( V_80 , V_145 ) ;
V_103:
V_123 -> V_125 = 0 ;
V_123 -> V_124 = 0 ;
return V_95 ;
}
int F_97 ( struct V_6 * V_7 , struct V_159 * V_160 , T_8 V_125 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_122 * V_123 = F_7 ( V_7 ) ;
struct V_144 V_161 ;
struct V_144 * V_145 ;
int V_162 = V_125 ;
struct V_163 V_164 ;
struct V_165 * V_166 = NULL ;
int free = 0 ;
int V_167 = 0 ;
T_4 V_55 , V_67 , V_48 ;
T_5 V_56 ;
V_119 V_168 ;
int V_95 , V_146 = F_89 ( V_7 ) ;
int V_169 = V_123 -> V_170 || V_160 -> V_171 & V_172 ;
int (* F_98)( void * , char * , int , int , int , struct V_79 * );
struct V_79 * V_80 ;
struct V_173 V_174 ;
if ( V_125 > 0xFFFF )
return - V_110 ;
if ( V_160 -> V_171 & V_175 )
return - V_176 ;
V_164 . V_177 = NULL ;
V_164 . V_178 = 0 ;
V_164 . V_179 = 0 ;
V_164 . V_168 = - 1 ;
F_98 = V_146 ? V_180 : V_181 ;
V_145 = & V_59 -> V_155 . V_156 . V_157 . V_158 ;
if ( V_123 -> V_124 ) {
F_99 ( V_7 ) ;
if ( F_100 ( V_123 -> V_124 ) ) {
if ( F_48 ( V_123 -> V_124 != V_182 ) ) {
F_101 ( V_7 ) ;
return - V_183 ;
}
goto V_184;
}
F_101 ( V_7 ) ;
}
V_162 += sizeof( struct V_90 ) ;
if ( V_160 -> V_185 ) {
F_102 ( struct V_186 * , V_187 , V_160 -> V_185 ) ;
if ( V_160 -> V_188 < sizeof( * V_187 ) )
return - V_183 ;
if ( V_187 -> V_189 != V_182 ) {
if ( V_187 -> V_189 != V_190 )
return - V_191 ;
}
V_55 = V_187 -> V_192 . V_193 ;
V_56 = V_187 -> V_194 ;
if ( V_56 == 0 )
return - V_183 ;
} else {
if ( V_7 -> V_117 != V_118 )
return - V_195 ;
V_55 = V_59 -> V_62 ;
V_56 = V_59 -> V_63 ;
V_167 = 1 ;
}
V_164 . V_196 = V_59 -> V_197 ;
V_164 . V_198 = V_7 -> V_15 ;
F_103 ( V_7 , & V_164 . V_178 ) ;
if ( V_160 -> V_199 ) {
V_95 = F_104 ( F_6 ( V_7 ) , V_160 , & V_164 ,
V_7 -> V_60 == V_200 ) ;
if ( V_95 )
return V_95 ;
if ( V_164 . V_177 )
free = 1 ;
V_167 = 0 ;
}
if ( ! V_164 . V_177 ) {
struct V_201 * V_202 ;
F_54 () ;
V_202 = F_105 ( V_59 -> V_202 ) ;
if ( V_202 ) {
memcpy ( & V_174 , V_202 ,
sizeof( * V_202 ) + V_202 -> V_177 . V_203 ) ;
V_164 . V_177 = & V_174 . V_177 ;
}
F_55 () ;
}
V_48 = V_164 . V_196 ;
V_164 . V_196 = V_67 = V_55 ;
if ( V_164 . V_177 && V_164 . V_177 -> V_177 . V_204 ) {
if ( ! V_55 )
return - V_183 ;
V_67 = V_164 . V_177 -> V_177 . V_67 ;
V_167 = 0 ;
}
V_168 = F_106 ( & V_164 , V_59 ) ;
if ( F_107 ( V_7 , V_205 ) ||
( V_160 -> V_171 & V_206 ) ||
( V_164 . V_177 && V_164 . V_177 -> V_177 . V_207 ) ) {
V_168 |= V_208 ;
V_167 = 0 ;
}
if ( F_108 ( V_55 ) ) {
if ( ! V_164 . V_198 )
V_164 . V_198 = V_59 -> V_209 ;
if ( ! V_48 )
V_48 = V_59 -> V_210 ;
V_167 = 0 ;
} else if ( ! V_164 . V_198 )
V_164 . V_198 = V_59 -> V_211 ;
if ( V_167 )
V_166 = (struct V_165 * ) F_109 ( V_7 , 0 ) ;
if ( ! V_166 ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
T_9 V_212 = F_110 ( V_7 ) ;
V_145 = & V_161 ;
F_111 ( V_145 , V_164 . V_198 , V_7 -> V_213 , V_168 ,
V_214 , V_7 -> V_151 ,
V_212 ,
V_67 , V_48 , V_56 , V_59 -> V_147 ) ;
if ( ! V_48 && V_164 . V_198 ) {
V_95 = F_112 ( V_1 , V_164 . V_198 , V_145 ) ;
if ( V_95 < 0 )
goto V_103;
}
F_113 ( V_7 , F_114 ( V_145 ) ) ;
V_166 = F_115 ( V_1 , V_145 , V_7 ) ;
if ( F_116 ( V_166 ) ) {
V_95 = F_117 ( V_166 ) ;
V_166 = NULL ;
if ( V_95 == - V_215 )
F_118 ( V_1 , V_216 ) ;
goto V_103;
}
V_95 = - V_217 ;
if ( ( V_166 -> V_218 & V_219 ) &&
! F_107 ( V_7 , V_220 ) )
goto V_103;
if ( V_167 )
F_119 ( V_7 , F_120 ( & V_166 -> V_127 ) ) ;
}
if ( V_160 -> V_171 & V_221 )
goto V_222;
V_223:
V_48 = V_145 -> V_48 ;
if ( ! V_164 . V_196 )
V_55 = V_164 . V_196 = V_145 -> V_55 ;
if ( ! V_169 ) {
V_80 = F_121 ( V_7 , V_145 , F_98 , V_160 , V_162 ,
sizeof( struct V_90 ) , & V_164 , & V_166 ,
V_160 -> V_171 ) ;
V_95 = F_117 ( V_80 ) ;
if ( ! F_122 ( V_80 ) )
V_95 = F_88 ( V_80 , V_145 ) ;
goto V_103;
}
F_99 ( V_7 ) ;
if ( F_48 ( V_123 -> V_124 ) ) {
F_101 ( V_7 ) ;
F_123 ( L_1 ) ;
V_95 = - V_183 ;
goto V_103;
}
V_145 = & V_59 -> V_155 . V_156 . V_157 . V_158 ;
V_145 -> V_55 = V_55 ;
V_145 -> V_48 = V_48 ;
V_145 -> V_148 = V_56 ;
V_145 -> V_224 = V_59 -> V_147 ;
V_123 -> V_124 = V_182 ;
V_184:
V_123 -> V_125 += V_162 ;
V_95 = F_124 ( V_7 , V_145 , F_98 , V_160 , V_162 ,
sizeof( struct V_90 ) , & V_164 , & V_166 ,
V_169 ? V_160 -> V_171 | V_172 : V_160 -> V_171 ) ;
if ( V_95 )
F_72 ( V_7 ) ;
else if ( ! V_169 )
V_95 = F_95 ( V_7 ) ;
else if ( F_48 ( F_125 ( & V_7 -> V_225 ) ) )
V_123 -> V_124 = 0 ;
F_101 ( V_7 ) ;
V_103:
F_126 ( V_166 ) ;
if ( free )
F_127 ( V_164 . V_177 ) ;
if ( ! V_95 )
return V_125 ;
if ( V_95 == - V_152 || F_22 ( V_226 , & V_7 -> V_227 -> V_228 ) ) {
F_94 ( F_6 ( V_7 ) ,
V_153 , V_146 ) ;
}
return V_95 ;
V_222:
F_128 ( & V_166 -> V_127 ) ;
if ( ! ( V_160 -> V_171 & V_229 ) || V_125 )
goto V_223;
V_95 = 0 ;
goto V_103;
}
int F_129 ( struct V_6 * V_7 , struct V_230 * V_230 , int V_128 ,
T_8 V_231 , int V_228 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_232 ;
if ( V_228 & V_233 )
V_228 |= V_172 ;
if ( ! V_123 -> V_124 ) {
struct V_159 V_160 = { . V_171 = V_228 | V_172 } ;
V_232 = F_97 ( V_7 , & V_160 , 0 ) ;
if ( V_232 < 0 )
return V_232 ;
}
F_99 ( V_7 ) ;
if ( F_48 ( ! V_123 -> V_124 ) ) {
F_101 ( V_7 ) ;
F_123 ( L_2 ) ;
return - V_183 ;
}
V_232 = F_130 ( V_7 , & V_59 -> V_155 . V_156 . V_157 . V_158 ,
V_230 , V_128 , V_231 , V_228 ) ;
if ( V_232 == - V_176 ) {
F_101 ( V_7 ) ;
return F_131 ( V_7 -> V_227 , V_230 , V_128 ,
V_231 , V_228 ) ;
}
if ( V_232 < 0 ) {
F_72 ( V_7 ) ;
goto V_103;
}
V_123 -> V_125 += V_231 ;
if ( ! ( V_123 -> V_170 || ( V_228 & V_172 ) ) )
V_232 = F_95 ( V_7 ) ;
if ( ! V_232 )
V_232 = V_231 ;
V_103:
F_101 ( V_7 ) ;
return V_232 ;
}
static unsigned int F_132 ( struct V_6 * V_7 )
{
struct V_234 V_235 , * V_236 = & V_7 -> V_237 ;
struct V_79 * V_80 ;
unsigned int V_18 ;
F_133 ( & V_235 ) ;
F_21 ( & V_236 -> V_19 ) ;
while ( ( V_80 = F_134 ( V_236 ) ) != NULL &&
F_135 ( V_80 ) ) {
F_136 ( F_6 ( V_7 ) , V_238 ,
F_89 ( V_7 ) ) ;
F_136 ( F_6 ( V_7 ) , V_239 ,
F_89 ( V_7 ) ) ;
F_137 ( & V_7 -> V_240 ) ;
F_138 ( V_80 , V_236 ) ;
F_139 ( & V_235 , V_80 ) ;
}
V_18 = V_80 ? V_80 -> V_125 : 0 ;
F_24 ( & V_236 -> V_19 ) ;
if ( ! F_125 ( & V_235 ) ) {
bool V_241 = F_140 ( V_7 ) ;
F_141 ( & V_235 ) ;
F_142 ( V_7 ) ;
F_143 ( V_7 , V_241 ) ;
}
return V_18 ;
}
int F_144 ( struct V_6 * V_7 , int V_242 , unsigned long V_243 )
{
switch ( V_242 ) {
case V_244 :
{
int V_245 = F_145 ( V_7 ) ;
return F_146 ( V_245 , ( int V_246 * ) V_243 ) ;
}
case V_247 :
{
unsigned int V_245 = F_132 ( V_7 ) ;
if ( V_245 )
V_245 -= sizeof( struct V_90 ) ;
return F_146 ( V_245 , ( int V_246 * ) V_243 ) ;
}
default:
return - V_248 ;
}
return 0 ;
}
int F_147 ( struct V_6 * V_7 , struct V_159 * V_160 , T_8 V_125 , int V_249 ,
int V_228 , int * V_250 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
F_102 ( struct V_186 * , sin , V_160 -> V_185 ) ;
struct V_79 * V_80 ;
unsigned int V_162 , V_251 ;
int V_252 , V_253 = 0 ;
int V_95 ;
int V_146 = F_89 ( V_7 ) ;
bool V_241 ;
if ( V_228 & V_254 )
return F_148 ( V_7 , V_160 , V_125 , V_250 ) ;
V_255:
V_80 = F_149 ( V_7 , V_228 | ( V_249 ? V_256 : 0 ) ,
& V_252 , & V_253 , & V_95 ) ;
if ( ! V_80 )
goto V_103;
V_162 = V_80 -> V_125 - sizeof( struct V_90 ) ;
V_251 = V_125 ;
if ( V_251 > V_162 )
V_251 = V_162 ;
else if ( V_251 < V_162 )
V_160 -> V_171 |= V_257 ;
if ( V_251 < V_162 || F_150 ( V_80 ) -> V_258 ) {
if ( F_135 ( V_80 ) )
goto V_259;
}
if ( F_151 ( V_80 ) )
V_95 = F_152 ( V_80 , sizeof( struct V_90 ) ,
V_160 , V_251 ) ;
else {
V_95 = F_153 ( V_80 , sizeof( struct V_90 ) ,
V_160 ) ;
if ( V_95 == - V_183 )
goto V_259;
}
if ( F_48 ( V_95 ) ) {
F_154 ( V_80 , F_147 ) ;
if ( ! V_252 ) {
F_137 ( & V_7 -> V_240 ) ;
F_94 ( F_6 ( V_7 ) ,
V_239 , V_146 ) ;
}
goto V_260;
}
if ( ! V_252 )
F_94 ( F_6 ( V_7 ) ,
V_261 , V_146 ) ;
F_155 ( V_160 , V_7 , V_80 ) ;
if ( sin ) {
sin -> V_189 = V_182 ;
sin -> V_194 = F_75 ( V_80 ) -> V_97 ;
sin -> V_192 . V_193 = F_58 ( V_80 ) -> V_48 ;
memset ( sin -> V_262 , 0 , sizeof( sin -> V_262 ) ) ;
* V_250 = sizeof( * sin ) ;
}
if ( V_59 -> V_263 )
F_156 ( V_160 , V_80 , sizeof( struct V_90 ) ) ;
V_95 = V_251 ;
if ( V_228 & V_257 )
V_95 = V_162 ;
V_260:
F_157 ( V_7 , V_80 ) ;
V_103:
return V_95 ;
V_259:
V_241 = F_140 ( V_7 ) ;
if ( ! F_158 ( V_7 , V_80 , V_228 ) ) {
F_94 ( F_6 ( V_7 ) , V_238 , V_146 ) ;
F_94 ( F_6 ( V_7 ) , V_239 , V_146 ) ;
}
F_143 ( V_7 , V_241 ) ;
F_159 () ;
V_160 -> V_171 &= ~ V_257 ;
goto V_255;
}
int F_160 ( struct V_6 * V_7 , int V_228 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
V_7 -> V_117 = V_264 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
F_161 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_265 & V_266 ) )
F_162 ( V_7 ) ;
if ( ! ( V_7 -> V_265 & V_267 ) ) {
V_7 -> V_24 -> V_268 ( V_7 ) ;
V_59 -> V_147 = 0 ;
}
F_163 ( V_7 ) ;
return 0 ;
}
void F_164 ( struct V_6 * V_7 )
{
if ( F_165 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
F_21 ( & V_4 -> V_19 ) ;
if ( F_166 ( V_7 ) ) {
V_4 -> V_35 -- ;
F_26 ( V_7 ) -> V_41 = 0 ;
F_29 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_167 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_24 ( & V_4 -> V_19 ) ;
}
}
void F_168 ( struct V_6 * V_7 , T_10 V_269 )
{
if ( F_165 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_270 ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
V_270 = F_25 ( V_23 , V_269 ) ;
F_7 ( V_7 ) -> V_38 = V_269 ;
if ( V_17 != V_270 ) {
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_167 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_270 -> V_19 ) ;
F_30 ( & F_7 ( V_7 ) -> V_43 ,
& V_270 -> V_42 ) ;
V_270 -> V_35 ++ ;
F_13 ( & V_270 -> V_19 ) ;
F_24 ( & V_4 -> V_19 ) ;
}
}
}
static void F_169 ( struct V_6 * V_7 )
{
T_10 V_271 = F_33 ( F_6 ( V_7 ) ,
F_26 ( V_7 ) -> V_47 ,
F_26 ( V_7 ) -> V_41 ) ;
F_168 ( V_7 , V_271 ) ;
}
static int F_170 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
int V_272 ;
if ( F_26 ( V_7 ) -> V_62 ) {
F_171 ( V_7 , V_80 ) ;
F_172 ( V_7 , V_80 ) ;
F_173 ( V_7 ) ;
}
V_272 = F_174 ( V_7 , V_80 ) ;
if ( V_272 < 0 ) {
int V_146 = F_89 ( V_7 ) ;
if ( V_272 == - V_273 )
F_136 ( F_6 ( V_7 ) , V_274 ,
V_146 ) ;
F_136 ( F_6 ( V_7 ) , V_239 , V_146 ) ;
F_175 ( V_80 ) ;
F_176 ( V_272 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_177 ( void )
{
if ( ! F_178 ( & V_275 ) )
F_179 ( & V_275 ) ;
}
int F_180 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_272 ;
int V_146 = F_89 ( V_7 ) ;
if ( ! F_181 ( V_7 , V_276 , V_80 ) )
goto V_277;
F_182 ( V_80 ) ;
if ( F_183 ( & V_275 ) && V_123 -> V_278 ) {
int (* F_184)( struct V_6 * V_7 , struct V_79 * V_80 );
F_184 = F_185 ( V_123 -> F_184 ) ;
if ( V_80 -> V_125 > sizeof( struct V_90 ) && F_184 ) {
int V_232 ;
if ( F_135 ( V_80 ) )
goto V_279;
V_232 = F_184 ( V_7 , V_80 ) ;
if ( V_232 <= 0 ) {
F_136 ( F_6 ( V_7 ) ,
V_261 ,
V_146 ) ;
return - V_232 ;
}
}
}
if ( ( V_146 & V_280 ) && F_150 ( V_80 ) -> V_258 ) {
if ( V_123 -> V_281 == 0 ) {
F_123 ( L_3 ,
F_150 ( V_80 ) -> V_282 , V_80 -> V_125 ) ;
goto V_277;
}
if ( F_150 ( V_80 ) -> V_282 < V_123 -> V_281 ) {
F_123 ( L_4 ,
F_150 ( V_80 ) -> V_282 , V_123 -> V_281 ) ;
goto V_277;
}
}
if ( F_186 ( V_7 -> V_283 ) &&
F_135 ( V_80 ) )
goto V_279;
if ( F_187 ( V_7 , V_7 -> V_284 ) ) {
F_136 ( F_6 ( V_7 ) , V_274 ,
V_146 ) ;
goto V_277;
}
V_272 = 0 ;
F_188 ( V_7 , V_80 ) ;
F_189 ( V_7 ) ;
if ( ! F_190 ( V_7 ) )
V_272 = F_170 ( V_7 , V_80 ) ;
else if ( F_191 ( V_7 , V_80 , V_7 -> V_284 ) ) {
F_192 ( V_7 ) ;
goto V_277;
}
F_192 ( V_7 ) ;
return V_272 ;
V_279:
F_136 ( F_6 ( V_7 ) , V_238 , V_146 ) ;
V_277:
F_136 ( F_6 ( V_7 ) , V_239 , V_146 ) ;
F_137 ( & V_7 -> V_240 ) ;
F_175 ( V_80 ) ;
return - 1 ;
}
static void F_193 ( struct V_6 * * V_285 , unsigned int V_35 ,
struct V_79 * V_80 , unsigned int V_286 )
{
unsigned int V_287 ;
struct V_79 * V_288 = NULL ;
struct V_6 * V_7 ;
for ( V_287 = 0 ; V_287 < V_35 ; V_287 ++ ) {
V_7 = V_285 [ V_287 ] ;
if ( F_100 ( ! V_288 ) )
V_288 = ( V_287 == V_286 ) ? V_80 : F_194 ( V_80 , V_289 ) ;
if ( ! V_288 ) {
F_137 ( & V_7 -> V_240 ) ;
F_136 ( F_6 ( V_7 ) , V_274 ,
F_89 ( V_7 ) ) ;
F_136 ( F_6 ( V_7 ) , V_239 ,
F_89 ( V_7 ) ) ;
}
if ( V_288 && F_180 ( V_7 , V_288 ) <= 0 )
V_288 = NULL ;
F_50 ( V_7 ) ;
}
if ( F_48 ( V_288 ) )
F_175 ( V_288 ) ;
}
static void F_195 ( struct V_6 * V_7 , struct V_290 * V_127 )
{
struct V_290 * V_291 ;
F_196 ( V_127 ) ;
V_291 = F_197 ( & V_7 -> V_292 , V_127 ) ;
F_198 ( V_291 ) ;
}
static int F_199 ( struct V_1 * V_1 , struct V_79 * V_80 ,
struct V_90 * V_91 ,
T_4 V_48 , T_4 V_55 ,
struct V_22 * V_23 ,
int V_293 )
{
struct V_6 * V_7 , * V_285 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_10 * V_11 ;
unsigned short V_53 = F_52 ( V_91 -> V_96 ) ;
struct V_3 * V_4 = F_19 ( V_23 , V_1 , V_53 ) ;
int V_57 = V_80 -> V_83 -> V_98 ;
unsigned int V_35 = 0 , V_128 = F_79 ( F_200 ( * V_7 ) , V_294 ) ;
unsigned int V_77 = 0 , V_295 = 0 , V_296 = ( V_4 -> V_35 > 10 ) ;
bool V_297 = false ;
if ( V_296 ) {
V_295 = F_33 ( V_1 , F_37 ( V_51 ) , V_53 ) &
V_22 . V_32 ;
V_77 = F_33 ( V_1 , V_55 , V_53 ) & V_22 . V_32 ;
V_298:
V_4 = & V_22 . V_77 [ V_77 ] ;
V_128 = F_79 ( F_200 ( * V_7 ) , V_299 . V_300 ) ;
}
F_11 ( & V_4 -> V_19 ) ;
F_201 (sk, node, &hslot->head, offset) {
if ( F_63 ( V_1 , V_7 ,
V_91 -> V_96 , V_55 ,
V_91 -> V_97 , V_48 ,
V_57 , V_53 ) ) {
if ( F_48 ( V_35 == F_202 ( V_285 ) ) ) {
F_193 ( V_285 , V_35 , V_80 , ~ 0 ) ;
V_297 = true ;
V_35 = 0 ;
}
V_285 [ V_35 ++ ] = V_7 ;
F_203 ( V_7 ) ;
}
}
F_13 ( & V_4 -> V_19 ) ;
if ( V_296 && V_77 != V_295 ) {
V_77 = V_295 ;
goto V_298;
}
if ( V_35 ) {
F_193 ( V_285 , V_35 , V_80 , V_35 - 1 ) ;
} else {
if ( ! V_297 )
F_136 ( V_1 , V_301 ,
V_293 == V_302 ) ;
F_204 ( V_80 ) ;
}
return 0 ;
}
static inline int F_205 ( struct V_79 * V_80 , struct V_90 * V_91 ,
int V_293 )
{
int V_95 ;
F_150 ( V_80 ) -> V_258 = 0 ;
F_150 ( V_80 ) -> V_282 = V_80 -> V_125 ;
if ( V_293 == V_302 ) {
V_95 = F_206 ( V_80 , V_91 ) ;
if ( V_95 )
return V_95 ;
}
return F_207 ( V_80 , V_293 , V_91 -> V_133 ,
V_303 ) ;
}
int F_208 ( struct V_79 * V_80 , struct V_22 * V_23 ,
int V_293 )
{
struct V_6 * V_7 ;
struct V_90 * V_91 ;
unsigned short V_162 ;
struct V_165 * V_166 = F_209 ( V_80 ) ;
T_4 V_48 , V_55 ;
struct V_1 * V_1 = F_59 ( V_80 -> V_83 ) ;
if ( ! F_210 ( V_80 , sizeof( struct V_90 ) ) )
goto V_277;
V_91 = F_75 ( V_80 ) ;
V_162 = F_52 ( V_91 -> V_125 ) ;
V_48 = F_58 ( V_80 ) -> V_48 ;
V_55 = F_58 ( V_80 ) -> V_55 ;
if ( V_162 > V_80 -> V_125 )
goto V_304;
if ( V_293 == V_134 ) {
if ( V_162 < sizeof( * V_91 ) || F_211 ( V_80 , V_162 ) )
goto V_304;
V_91 = F_75 ( V_80 ) ;
}
if ( F_205 ( V_80 , V_91 , V_293 ) )
goto V_279;
V_7 = F_212 ( V_80 ) ;
if ( V_7 ) {
struct V_290 * V_127 = F_60 ( V_80 ) ;
int V_232 ;
if ( F_48 ( V_7 -> V_292 != V_127 ) )
F_195 ( V_7 , V_127 ) ;
V_232 = F_180 ( V_7 , V_80 ) ;
F_50 ( V_7 ) ;
if ( V_232 > 0 )
return - V_232 ;
return 0 ;
}
if ( V_166 -> V_218 & ( V_219 | V_305 ) )
return F_199 ( V_1 , V_80 , V_91 ,
V_48 , V_55 , V_23 , V_293 ) ;
V_7 = F_57 ( V_80 , V_91 -> V_97 , V_91 -> V_96 , V_23 ) ;
if ( V_7 ) {
int V_232 ;
if ( F_213 ( V_7 ) && V_91 -> V_133 && ! F_89 ( V_7 ) )
F_214 ( V_80 , V_134 , V_91 -> V_133 ,
V_303 ) ;
V_232 = F_180 ( V_7 , V_80 ) ;
F_50 ( V_7 ) ;
if ( V_232 > 0 )
return - V_232 ;
return 0 ;
}
if ( ! F_181 ( NULL , V_276 , V_80 ) )
goto V_277;
F_182 ( V_80 ) ;
if ( F_135 ( V_80 ) )
goto V_279;
F_136 ( V_1 , V_306 , V_293 == V_302 ) ;
F_215 ( V_80 , V_106 , V_307 , 0 ) ;
F_175 ( V_80 ) ;
return 0 ;
V_304:
F_123 ( L_5 ,
V_293 == V_302 ? L_6 : L_7 ,
& V_48 , F_52 ( V_91 -> V_97 ) ,
V_162 , V_80 -> V_125 ,
& V_55 , F_52 ( V_91 -> V_96 ) ) ;
goto V_277;
V_279:
F_123 ( L_8 ,
V_293 == V_302 ? L_6 : L_7 ,
& V_48 , F_52 ( V_91 -> V_97 ) , & V_55 , F_52 ( V_91 -> V_96 ) ,
V_162 ) ;
F_136 ( V_1 , V_238 , V_293 == V_302 ) ;
V_277:
F_136 ( V_1 , V_239 , V_293 == V_302 ) ;
F_175 ( V_80 ) ;
return 0 ;
}
static struct V_6 * F_216 ( struct V_1 * V_1 ,
T_5 V_84 , T_4 V_85 ,
T_5 V_86 , T_4 V_87 ,
int V_57 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_52 ( V_84 ) ;
unsigned int V_35 , V_78 = F_53 ( V_1 , V_53 , V_22 . V_32 ) ;
struct V_3 * V_4 = & V_22 . V_74 [ V_78 ] ;
if ( V_4 -> V_35 > 10 )
return NULL ;
F_54 () ;
V_75:
V_35 = 0 ;
V_70 = NULL ;
F_56 (sk, node, &hslot->head) {
if ( F_63 ( V_1 , V_7 ,
V_84 , V_85 ,
V_86 , V_87 ,
V_57 , V_53 ) ) {
V_70 = V_7 ;
++ V_35 ;
}
}
if ( F_47 ( V_11 ) != V_78 )
goto V_75;
if ( V_70 ) {
if ( V_35 != 1 ||
F_48 ( ! F_49 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_48 ( ! F_63 ( V_1 , V_70 ,
V_84 , V_85 ,
V_86 , V_87 ,
V_57 , V_53 ) ) ) {
F_50 ( V_70 ) ;
V_70 = NULL ;
}
}
F_55 () ;
return V_70 ;
}
static struct V_6 * F_217 ( struct V_1 * V_1 ,
T_5 V_84 , T_4 V_85 ,
T_5 V_86 , T_4 V_87 ,
int V_57 )
{
struct V_6 * V_7 , * V_70 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_52 ( V_84 ) ;
unsigned int V_77 = F_33 ( V_1 , V_85 , V_53 ) ;
unsigned int V_37 = V_77 & V_22 . V_32 ;
struct V_3 * V_17 = & V_22 . V_77 [ V_37 ] ;
F_218 ( V_308 , V_87 , V_85 ) ;
const T_11 V_309 = F_219 ( V_86 , V_53 ) ;
F_54 () ;
V_70 = NULL ;
F_45 (sk, node, &hslot2->head) {
if ( F_220 ( V_7 , V_1 , V_308 ,
V_87 , V_85 , V_309 , V_57 ) )
V_70 = V_7 ;
break;
}
if ( V_70 ) {
if ( F_48 ( ! F_49 ( & V_70 -> V_76 , 2 ) ) )
V_70 = NULL ;
else if ( F_48 ( ! F_220 ( V_7 , V_1 , V_308 ,
V_87 , V_85 ,
V_309 , V_57 ) ) ) {
F_50 ( V_70 ) ;
V_70 = NULL ;
}
}
F_55 () ;
return V_70 ;
}
void F_221 ( struct V_79 * V_80 )
{
struct V_1 * V_1 = F_59 ( V_80 -> V_83 ) ;
const struct V_81 * V_82 ;
const struct V_90 * V_91 ;
struct V_6 * V_7 ;
struct V_290 * V_127 ;
int V_57 = V_80 -> V_83 -> V_98 ;
int V_310 ;
if ( ! F_210 ( V_80 , F_76 ( V_80 ) + sizeof( struct V_90 ) ) )
return;
V_82 = F_58 ( V_80 ) ;
V_91 = F_75 ( V_80 ) ;
if ( V_80 -> V_311 == V_312 ||
V_80 -> V_311 == V_313 ) {
struct V_314 * V_315 = F_222 ( V_80 -> V_83 ) ;
if ( ! V_315 )
return;
V_310 = F_223 ( V_315 , V_82 -> V_55 , V_82 -> V_48 ,
V_82 -> V_316 ) ;
if ( ! V_310 )
return;
V_7 = F_216 ( V_1 , V_91 -> V_96 , V_82 -> V_55 ,
V_91 -> V_97 , V_82 -> V_48 , V_57 ) ;
} else if ( V_80 -> V_311 == V_317 ) {
V_7 = F_217 ( V_1 , V_91 -> V_96 , V_82 -> V_55 ,
V_91 -> V_97 , V_82 -> V_48 , V_57 ) ;
} else {
return;
}
if ( ! V_7 )
return;
V_80 -> V_7 = V_7 ;
V_80 -> V_318 = V_319 ;
V_127 = F_224 ( V_7 -> V_292 ) ;
if ( V_127 )
V_127 = F_225 ( V_127 , 0 ) ;
if ( V_127 ) {
if ( V_127 -> V_228 & V_320 ) {
if ( F_100 ( F_226 ( & V_127 -> V_321 ) ) )
F_227 ( V_80 , V_127 ) ;
} else {
F_228 ( V_80 , V_127 ) ;
}
}
}
int F_229 ( struct V_79 * V_80 )
{
return F_208 ( V_80 , & V_22 , V_134 ) ;
}
void F_230 ( struct V_6 * V_7 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
bool V_241 = F_140 ( V_7 ) ;
F_72 ( V_7 ) ;
F_143 ( V_7 , V_241 ) ;
if ( F_183 ( & V_275 ) && V_123 -> V_278 ) {
void (* F_231)( struct V_6 * V_7 );
F_231 = F_185 ( V_123 -> F_231 ) ;
if ( F_231 )
F_231 ( V_7 ) ;
}
}
int F_232 ( struct V_6 * V_7 , int V_322 , int V_323 ,
char V_246 * V_324 , unsigned int V_203 ,
int (* F_233)( struct V_6 * ) )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_325 , V_326 ;
int V_95 = 0 ;
int V_146 = F_89 ( V_7 ) ;
if ( V_203 < sizeof( int ) )
return - V_183 ;
if ( F_234 ( V_325 , ( int V_246 * ) V_324 ) )
return - V_327 ;
V_326 = V_325 ? 1 : 0 ;
switch ( V_323 ) {
case V_328 :
if ( V_325 != 0 ) {
V_123 -> V_170 = 1 ;
} else {
V_123 -> V_170 = 0 ;
F_99 ( V_7 ) ;
F_233 ( V_7 ) ;
F_101 ( V_7 ) ;
}
break;
case V_329 :
switch ( V_325 ) {
case 0 :
case V_330 :
case V_331 :
V_123 -> F_184 = V_332 ;
case V_333 :
V_123 -> V_278 = V_325 ;
F_177 () ;
break;
default:
V_95 = - V_334 ;
break;
}
break;
case V_335 :
V_123 -> V_336 = V_326 ;
break;
case V_337 :
V_123 -> V_338 = V_326 ;
break;
case V_339 :
if ( ! V_146 )
return - V_334 ;
if ( V_325 != 0 && V_325 < 8 )
V_325 = 8 ;
else if ( V_325 > V_340 )
V_325 = V_340 ;
V_123 -> V_341 = V_325 ;
V_123 -> V_342 |= V_343 ;
break;
case V_344 :
if ( ! V_146 )
return - V_334 ;
if ( V_325 != 0 && V_325 < 8 )
V_325 = 8 ;
else if ( V_325 > V_340 )
V_325 = V_340 ;
V_123 -> V_281 = V_325 ;
V_123 -> V_342 |= V_280 ;
break;
default:
V_95 = - V_334 ;
break;
}
return V_95 ;
}
int F_235 ( struct V_6 * V_7 , int V_322 , int V_323 ,
char V_246 * V_324 , unsigned int V_203 )
{
if ( V_322 == V_345 || V_322 == V_346 )
return F_232 ( V_7 , V_322 , V_323 , V_324 , V_203 ,
F_95 ) ;
return F_236 ( V_7 , V_322 , V_323 , V_324 , V_203 ) ;
}
int F_237 ( struct V_6 * V_7 , int V_322 , int V_323 ,
char V_246 * V_324 , unsigned int V_203 )
{
if ( V_322 == V_345 || V_322 == V_346 )
return F_232 ( V_7 , V_322 , V_323 , V_324 , V_203 ,
F_95 ) ;
return F_238 ( V_7 , V_322 , V_323 , V_324 , V_203 ) ;
}
int F_239 ( struct V_6 * V_7 , int V_322 , int V_323 ,
char V_246 * V_324 , int V_246 * V_203 )
{
struct V_122 * V_123 = F_7 ( V_7 ) ;
int V_325 , V_125 ;
if ( F_234 ( V_125 , V_203 ) )
return - V_327 ;
V_125 = F_240 (unsigned int, len, sizeof(int)) ;
if ( V_125 < 0 )
return - V_183 ;
switch ( V_323 ) {
case V_328 :
V_325 = V_123 -> V_170 ;
break;
case V_329 :
V_325 = V_123 -> V_278 ;
break;
case V_335 :
V_325 = V_123 -> V_336 ;
break;
case V_337 :
V_325 = V_123 -> V_338 ;
break;
case V_339 :
V_325 = V_123 -> V_341 ;
break;
case V_344 :
V_325 = V_123 -> V_281 ;
break;
default:
return - V_334 ;
}
if ( F_146 ( V_125 , V_203 ) )
return - V_327 ;
if ( F_241 ( V_324 , & V_325 , V_125 ) )
return - V_327 ;
return 0 ;
}
int F_242 ( struct V_6 * V_7 , int V_322 , int V_323 ,
char V_246 * V_324 , int V_246 * V_203 )
{
if ( V_322 == V_345 || V_322 == V_346 )
return F_239 ( V_7 , V_322 , V_323 , V_324 , V_203 ) ;
return F_243 ( V_7 , V_322 , V_323 , V_324 , V_203 ) ;
}
int F_244 ( struct V_6 * V_7 , int V_322 , int V_323 ,
char V_246 * V_324 , int V_246 * V_203 )
{
if ( V_322 == V_345 || V_322 == V_346 )
return F_239 ( V_7 , V_322 , V_323 , V_324 , V_203 ) ;
return F_245 ( V_7 , V_322 , V_323 , V_324 , V_203 ) ;
}
unsigned int F_246 ( struct V_347 * V_347 , struct V_348 * V_6 , T_12 * V_349 )
{
unsigned int V_32 = F_247 ( V_347 , V_6 , V_349 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_248 ( V_7 ) ;
if ( ( V_32 & V_350 ) && ! ( V_347 -> V_351 & V_352 ) &&
! ( V_7 -> V_353 & V_354 ) && ! F_132 ( V_7 ) )
V_32 &= ~ ( V_355 | V_350 ) ;
return V_32 ;
}
static struct V_6 * F_249 ( struct V_356 * V_357 , int V_358 )
{
struct V_6 * V_7 ;
struct V_359 * V_360 = V_357 -> V_361 ;
struct V_1 * V_1 = F_250 ( V_357 ) ;
for ( V_360 -> V_362 = V_358 ; V_360 -> V_362 <= V_360 -> V_22 -> V_32 ;
++ V_360 -> V_362 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_360 -> V_22 -> V_74 [ V_360 -> V_362 ] ;
if ( F_251 ( & V_4 -> V_42 ) )
continue;
F_21 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_60 == V_360 -> V_363 )
goto V_33;
}
F_24 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_33:
return V_7 ;
}
static struct V_6 * F_252 ( struct V_356 * V_357 , struct V_6 * V_7 )
{
struct V_359 * V_360 = V_357 -> V_361 ;
struct V_1 * V_1 = F_250 ( V_357 ) ;
do {
V_7 = F_253 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_60 != V_360 -> V_363 ) );
if ( ! V_7 ) {
if ( V_360 -> V_362 <= V_360 -> V_22 -> V_32 )
F_24 ( & V_360 -> V_22 -> V_74 [ V_360 -> V_362 ] . V_19 ) ;
return F_249 ( V_357 , V_360 -> V_362 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_254 ( struct V_356 * V_357 , T_13 V_364 )
{
struct V_6 * V_7 = F_249 ( V_357 , 0 ) ;
if ( V_7 )
while ( V_364 && ( V_7 = F_252 ( V_357 , V_7 ) ) != NULL )
-- V_364 ;
return V_364 ? NULL : V_7 ;
}
static void * F_255 ( struct V_356 * V_357 , T_13 * V_364 )
{
struct V_359 * V_360 = V_357 -> V_361 ;
V_360 -> V_362 = V_365 ;
return * V_364 ? F_254 ( V_357 , * V_364 - 1 ) : V_366 ;
}
static void * F_256 ( struct V_356 * V_357 , void * V_367 , T_13 * V_364 )
{
struct V_6 * V_7 ;
if ( V_367 == V_366 )
V_7 = F_254 ( V_357 , 0 ) ;
else
V_7 = F_252 ( V_357 , V_367 ) ;
++ * V_364 ;
return V_7 ;
}
static void F_257 ( struct V_356 * V_357 , void * V_367 )
{
struct V_359 * V_360 = V_357 -> V_361 ;
if ( V_360 -> V_362 <= V_360 -> V_22 -> V_32 )
F_24 ( & V_360 -> V_22 -> V_74 [ V_360 -> V_362 ] . V_19 ) ;
}
int F_258 ( struct V_368 * V_368 , struct V_347 * V_347 )
{
struct V_369 * V_370 = F_259 ( V_368 ) ;
struct V_359 * V_371 ;
int V_95 ;
V_95 = F_260 ( V_368 , V_347 , & V_370 -> V_372 ,
sizeof( struct V_359 ) ) ;
if ( V_95 < 0 )
return V_95 ;
V_371 = ( (struct V_356 * ) V_347 -> V_373 ) -> V_361 ;
V_371 -> V_363 = V_370 -> V_363 ;
V_371 -> V_22 = V_370 -> V_22 ;
return V_95 ;
}
int F_261 ( struct V_1 * V_1 , struct V_369 * V_370 )
{
struct V_374 * V_375 ;
int V_272 = 0 ;
V_370 -> V_372 . V_358 = F_255 ;
V_370 -> V_372 . V_376 = F_256 ;
V_370 -> V_372 . V_377 = F_257 ;
V_375 = F_262 ( V_370 -> V_378 , V_379 , V_1 -> V_380 ,
V_370 -> V_381 , V_370 ) ;
if ( ! V_375 )
V_272 = - V_273 ;
return V_272 ;
}
void F_263 ( struct V_1 * V_1 , struct V_369 * V_370 )
{
F_264 ( V_370 -> V_378 , V_1 -> V_380 ) ;
}
static void F_265 ( struct V_6 * V_382 , struct V_356 * V_383 ,
int V_362 )
{
struct V_44 * V_59 = F_26 ( V_382 ) ;
T_4 V_96 = V_59 -> V_62 ;
T_4 V_126 = V_59 -> V_47 ;
T_1 V_384 = F_52 ( V_59 -> V_63 ) ;
T_1 V_385 = F_52 ( V_59 -> V_147 ) ;
F_266 ( V_383 , L_9
L_10 ,
V_362 , V_126 , V_385 , V_96 , V_384 , V_382 -> V_117 ,
F_145 ( V_382 ) ,
F_267 ( V_382 ) ,
0 , 0L , 0 ,
F_268 ( F_269 ( V_383 ) , F_3 ( V_382 ) ) ,
0 , F_270 ( V_382 ) ,
F_271 ( & V_382 -> V_76 ) , V_382 ,
F_271 ( & V_382 -> V_240 ) ) ;
}
int F_272 ( struct V_356 * V_357 , void * V_367 )
{
F_273 ( V_357 , 127 ) ;
if ( V_367 == V_366 )
F_274 ( V_357 , L_11
L_12
L_13 ) ;
else {
struct V_359 * V_360 = V_357 -> V_361 ;
F_265 ( V_367 , V_357 , V_360 -> V_362 ) ;
}
F_275 ( V_357 , '\n' ) ;
return 0 ;
}
static int T_14 F_276 ( struct V_1 * V_1 )
{
return F_261 ( V_1 , & V_386 ) ;
}
static void T_15 F_277 ( struct V_1 * V_1 )
{
F_263 ( V_1 , & V_386 ) ;
}
int T_16 F_278 ( void )
{
return F_279 ( & V_387 ) ;
}
void F_280 ( void )
{
F_281 ( & V_387 ) ;
}
static int T_16 F_282 ( char * V_388 )
{
T_17 V_232 ;
if ( ! V_388 )
return 0 ;
V_232 = F_283 ( V_388 , 0 , & V_389 ) ;
if ( V_232 )
return 0 ;
if ( V_389 && V_389 < V_390 )
V_389 = V_390 ;
return 1 ;
}
void T_16 F_284 ( struct V_22 * V_391 , const char * V_378 )
{
unsigned int V_287 ;
V_391 -> V_74 = F_285 ( V_378 ,
2 * sizeof( struct V_3 ) ,
V_389 ,
21 ,
0 ,
& V_391 -> log ,
& V_391 -> V_32 ,
V_390 ,
64 * 1024 ) ;
V_391 -> V_77 = V_391 -> V_74 + ( V_391 -> V_32 + 1 ) ;
for ( V_287 = 0 ; V_287 <= V_391 -> V_32 ; V_287 ++ ) {
F_286 ( & V_391 -> V_74 [ V_287 ] . V_42 , V_287 ) ;
V_391 -> V_74 [ V_287 ] . V_35 = 0 ;
F_287 ( & V_391 -> V_74 [ V_287 ] . V_19 ) ;
}
for ( V_287 = 0 ; V_287 <= V_391 -> V_32 ; V_287 ++ ) {
F_286 ( & V_391 -> V_77 [ V_287 ] . V_42 , V_287 ) ;
V_391 -> V_77 [ V_287 ] . V_35 = 0 ;
F_287 ( & V_391 -> V_77 [ V_287 ] . V_19 ) ;
}
}
T_3 F_288 ( void )
{
static T_3 T_18 V_69 ;
F_42 ( & T_18 , sizeof( T_18 ) ) ;
return T_18 ;
}
void T_16 F_289 ( void )
{
unsigned long V_392 ;
F_284 ( & V_22 , L_14 ) ;
V_392 = F_290 () / 8 ;
V_392 = F_291 ( V_392 , 128UL ) ;
V_393 [ 0 ] = V_392 / 4 * 3 ;
V_393 [ 1 ] = V_392 ;
V_393 [ 2 ] = V_393 [ 0 ] * 2 ;
V_394 = V_395 ;
V_396 = V_395 ;
}
