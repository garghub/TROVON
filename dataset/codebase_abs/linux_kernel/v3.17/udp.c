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
void F_63 ( struct V_80 * V_81 , V_52 V_89 , struct V_22 * V_23 )
{
struct V_45 * V_61 ;
const struct V_82 * V_83 = ( const struct V_82 * ) V_81 -> V_90 ;
struct V_91 * V_92 = (struct V_91 * ) ( V_81 -> V_90 + ( V_83 -> V_93 << 2 ) ) ;
const int type = F_64 ( V_81 ) -> type ;
const int V_94 = F_64 ( V_81 ) -> V_94 ;
struct V_6 * V_7 ;
int V_95 ;
int V_96 ;
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
V_7 = F_49 ( V_1 , V_83 -> V_57 , V_92 -> V_97 ,
V_83 -> V_49 , V_92 -> V_98 , V_81 -> V_84 -> V_99 , V_23 ) ;
if ( V_7 == NULL ) {
F_65 ( V_1 , V_100 ) ;
return;
}
V_96 = 0 ;
V_95 = 0 ;
V_61 = F_25 ( V_7 ) ;
switch ( type ) {
default:
case V_101 :
V_96 = V_102 ;
break;
case V_103 :
goto V_104;
case V_105 :
V_96 = V_106 ;
V_95 = 1 ;
break;
case V_107 :
if ( V_94 == V_108 ) {
F_66 ( V_81 , V_7 , V_89 ) ;
if ( V_61 -> V_109 != V_110 ) {
V_96 = V_111 ;
V_95 = 1 ;
break;
}
goto V_104;
}
V_96 = V_102 ;
if ( V_94 <= V_112 ) {
V_95 = V_113 [ V_94 ] . V_114 ;
V_96 = V_113 [ V_94 ] . V_115 ;
}
break;
case V_116 :
F_67 ( V_81 , V_7 ) ;
goto V_104;
}
if ( ! V_61 -> V_117 ) {
if ( ! V_95 || V_7 -> V_118 != V_119 )
goto V_104;
} else
F_68 ( V_7 , V_81 , V_96 , V_92 -> V_97 , V_89 , ( V_120 * ) ( V_92 + 1 ) ) ;
V_7 -> V_121 = V_96 ;
V_7 -> V_122 ( V_7 ) ;
V_104:
F_48 ( V_7 ) ;
}
void F_69 ( struct V_80 * V_81 , V_52 V_89 )
{
F_63 ( V_81 , V_89 , & V_22 ) ;
}
void F_70 ( struct V_6 * V_7 )
{
struct V_123 * V_124 = F_7 ( V_7 ) ;
if ( V_124 -> V_125 ) {
V_124 -> V_126 = 0 ;
V_124 -> V_125 = 0 ;
F_71 ( V_7 ) ;
}
}
void F_72 ( struct V_80 * V_81 , T_3 V_127 , T_3 V_128 )
{
struct V_91 * V_92 = F_73 ( V_81 ) ;
int V_129 = F_74 ( V_81 ) ;
int V_126 = V_81 -> V_126 - V_129 ;
int V_130 = V_126 ;
T_6 V_131 = 0 ;
if ( ! F_75 ( V_81 ) ) {
V_81 -> V_132 = F_76 ( V_81 ) - V_81 -> V_43 ;
V_81 -> V_133 = F_77 ( struct V_91 , V_134 ) ;
V_92 -> V_134 = ~ F_78 ( V_127 , V_128 , V_126 ,
V_135 , 0 ) ;
} else {
struct V_80 * V_136 ;
F_79 (skb, frags) {
V_131 = F_80 ( V_131 , V_136 -> V_131 ) ;
V_130 -= V_136 -> V_126 ;
}
V_131 = F_81 ( V_81 , V_129 , V_130 , V_131 ) ;
V_81 -> V_137 = V_138 ;
V_92 -> V_134 = F_78 ( V_127 , V_128 , V_126 , V_135 , V_131 ) ;
if ( V_92 -> V_134 == 0 )
V_92 -> V_134 = V_139 ;
}
}
void F_82 ( bool V_140 , struct V_80 * V_81 ,
T_3 V_49 , T_3 V_57 , int V_126 )
{
struct V_91 * V_92 = F_73 ( V_81 ) ;
if ( V_140 )
V_92 -> V_134 = 0 ;
else if ( F_83 ( V_81 ) )
V_92 -> V_134 = ~ F_84 ( V_126 , V_49 , V_57 , 0 ) ;
else if ( F_58 ( V_81 ) && F_58 ( V_81 ) -> V_84 &&
( F_58 ( V_81 ) -> V_84 -> V_141 & V_142 ) ) {
F_85 ( V_81 -> V_137 == V_143 ) ;
V_81 -> V_137 = V_143 ;
V_81 -> V_132 = F_76 ( V_81 ) - V_81 -> V_43 ;
V_81 -> V_133 = F_77 ( struct V_91 , V_134 ) ;
V_92 -> V_134 = ~ F_84 ( V_126 , V_49 , V_57 , 0 ) ;
} else {
T_6 V_131 ;
F_85 ( V_81 -> V_137 == V_143 ) ;
V_92 -> V_134 = 0 ;
V_131 = F_81 ( V_81 , 0 , V_126 , 0 ) ;
V_92 -> V_134 = F_84 ( V_126 , V_49 , V_57 , V_131 ) ;
if ( V_92 -> V_134 == 0 )
V_92 -> V_134 = V_139 ;
V_81 -> V_137 = V_144 ;
}
}
static int F_86 ( struct V_80 * V_81 , struct V_145 * V_146 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_91 * V_92 ;
int V_96 = 0 ;
int V_147 = F_87 ( V_7 ) ;
int V_129 = F_74 ( V_81 ) ;
int V_126 = V_81 -> V_126 - V_129 ;
T_6 V_131 = 0 ;
V_92 = F_73 ( V_81 ) ;
V_92 -> V_98 = V_61 -> V_148 ;
V_92 -> V_97 = V_146 -> V_149 ;
V_92 -> V_126 = F_88 ( V_126 ) ;
V_92 -> V_134 = 0 ;
if ( V_147 )
V_131 = F_89 ( V_81 ) ;
else if ( V_7 -> V_150 ) {
V_81 -> V_137 = V_138 ;
goto V_151;
} else if ( V_81 -> V_137 == V_143 ) {
F_72 ( V_81 , V_146 -> V_49 , V_146 -> V_57 ) ;
goto V_151;
} else
V_131 = F_90 ( V_81 ) ;
V_92 -> V_134 = F_78 ( V_146 -> V_49 , V_146 -> V_57 , V_126 ,
V_7 -> V_152 , V_131 ) ;
if ( V_92 -> V_134 == 0 )
V_92 -> V_134 = V_139 ;
V_151:
V_96 = F_91 ( F_6 ( V_7 ) , V_81 ) ;
if ( V_96 ) {
if ( V_96 == - V_153 && ! V_61 -> V_117 ) {
F_92 ( F_6 ( V_7 ) ,
V_154 , V_147 ) ;
V_96 = 0 ;
}
} else
F_92 ( F_6 ( V_7 ) ,
V_155 , V_147 ) ;
return V_96 ;
}
int F_93 ( struct V_6 * V_7 )
{
struct V_123 * V_124 = F_7 ( V_7 ) ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_145 * V_146 = & V_61 -> V_156 . V_157 . V_158 . V_159 ;
struct V_80 * V_81 ;
int V_96 = 0 ;
V_81 = F_94 ( V_7 , V_146 ) ;
if ( ! V_81 )
goto V_104;
V_96 = F_86 ( V_81 , V_146 ) ;
V_104:
V_124 -> V_126 = 0 ;
V_124 -> V_125 = 0 ;
return V_96 ;
}
int F_95 ( struct V_160 * V_161 , struct V_6 * V_7 , struct V_162 * V_163 ,
T_7 V_126 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_123 * V_124 = F_7 ( V_7 ) ;
struct V_145 V_164 ;
struct V_145 * V_146 ;
int V_165 = V_126 ;
struct V_166 V_167 ;
struct V_168 * V_169 = NULL ;
int free = 0 ;
int V_170 = 0 ;
T_3 V_57 , V_68 , V_49 ;
T_4 V_58 ;
V_120 V_171 ;
int V_96 , V_147 = F_87 ( V_7 ) ;
int V_172 = V_124 -> V_173 || V_163 -> V_174 & V_175 ;
int (* F_96)( void * , char * , int , int , int , struct V_80 * );
struct V_80 * V_81 ;
struct V_176 V_177 ;
if ( V_126 > 0xFFFF )
return - V_111 ;
if ( V_163 -> V_174 & V_178 )
return - V_179 ;
V_167 . V_180 = NULL ;
V_167 . V_181 = 0 ;
V_167 . V_182 = 0 ;
V_167 . V_171 = - 1 ;
F_96 = V_147 ? V_183 : V_184 ;
V_146 = & V_61 -> V_156 . V_157 . V_158 . V_159 ;
if ( V_124 -> V_125 ) {
F_97 ( V_7 ) ;
if ( F_98 ( V_124 -> V_125 ) ) {
if ( F_46 ( V_124 -> V_125 != V_185 ) ) {
F_99 ( V_7 ) ;
return - V_186 ;
}
goto V_187;
}
F_99 ( V_7 ) ;
}
V_165 += sizeof( struct V_91 ) ;
if ( V_163 -> V_188 ) {
F_100 ( struct V_189 * , V_190 , V_163 -> V_188 ) ;
if ( V_163 -> V_191 < sizeof( * V_190 ) )
return - V_186 ;
if ( V_190 -> V_192 != V_185 ) {
if ( V_190 -> V_192 != V_193 )
return - V_194 ;
}
V_57 = V_190 -> V_195 . V_196 ;
V_58 = V_190 -> V_197 ;
if ( V_58 == 0 )
return - V_186 ;
} else {
if ( V_7 -> V_118 != V_119 )
return - V_198 ;
V_57 = V_61 -> V_64 ;
V_58 = V_61 -> V_65 ;
V_170 = 1 ;
}
V_167 . V_199 = V_61 -> V_200 ;
V_167 . V_201 = V_7 -> V_15 ;
F_101 ( V_7 , & V_167 . V_181 ) ;
if ( V_163 -> V_202 ) {
V_96 = F_102 ( F_6 ( V_7 ) , V_163 , & V_167 ,
V_7 -> V_62 == V_203 ) ;
if ( V_96 )
return V_96 ;
if ( V_167 . V_180 )
free = 1 ;
V_170 = 0 ;
}
if ( ! V_167 . V_180 ) {
struct V_204 * V_205 ;
F_52 () ;
V_205 = F_103 ( V_61 -> V_205 ) ;
if ( V_205 ) {
memcpy ( & V_177 , V_205 ,
sizeof( * V_205 ) + V_205 -> V_180 . V_206 ) ;
V_167 . V_180 = & V_177 . V_180 ;
}
F_53 () ;
}
V_49 = V_167 . V_199 ;
V_167 . V_199 = V_68 = V_57 ;
if ( V_167 . V_180 && V_167 . V_180 -> V_180 . V_207 ) {
if ( ! V_57 )
return - V_186 ;
V_68 = V_167 . V_180 -> V_180 . V_68 ;
V_170 = 0 ;
}
V_171 = F_104 ( & V_167 , V_61 ) ;
if ( F_105 ( V_7 , V_208 ) ||
( V_163 -> V_174 & V_209 ) ||
( V_167 . V_180 && V_167 . V_180 -> V_180 . V_210 ) ) {
V_171 |= V_211 ;
V_170 = 0 ;
}
if ( F_106 ( V_57 ) ) {
if ( ! V_167 . V_201 )
V_167 . V_201 = V_61 -> V_212 ;
if ( ! V_49 )
V_49 = V_61 -> V_213 ;
V_170 = 0 ;
} else if ( ! V_167 . V_201 )
V_167 . V_201 = V_61 -> V_214 ;
if ( V_170 )
V_169 = (struct V_168 * ) F_107 ( V_7 , 0 ) ;
if ( V_169 == NULL ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
V_146 = & V_164 ;
F_108 ( V_146 , V_167 . V_201 , V_7 -> V_215 , V_171 ,
V_216 , V_7 -> V_152 ,
F_109 ( V_7 ) ,
V_68 , V_49 , V_58 , V_61 -> V_148 ) ;
F_110 ( V_7 , F_111 ( V_146 ) ) ;
V_169 = F_112 ( V_1 , V_146 , V_7 ) ;
if ( F_113 ( V_169 ) ) {
V_96 = F_114 ( V_169 ) ;
V_169 = NULL ;
if ( V_96 == - V_217 )
F_115 ( V_1 , V_218 ) ;
goto V_104;
}
V_96 = - V_219 ;
if ( ( V_169 -> V_220 & V_221 ) &&
! F_105 ( V_7 , V_222 ) )
goto V_104;
if ( V_170 )
F_116 ( V_7 , F_117 ( & V_169 -> V_128 ) ) ;
}
if ( V_163 -> V_174 & V_223 )
goto V_224;
V_225:
V_49 = V_146 -> V_49 ;
if ( ! V_167 . V_199 )
V_57 = V_167 . V_199 = V_146 -> V_57 ;
if ( ! V_172 ) {
V_81 = F_118 ( V_7 , V_146 , F_96 , V_163 -> V_226 , V_165 ,
sizeof( struct V_91 ) , & V_167 , & V_169 ,
V_163 -> V_174 ) ;
V_96 = F_114 ( V_81 ) ;
if ( ! F_119 ( V_81 ) )
V_96 = F_86 ( V_81 , V_146 ) ;
goto V_104;
}
F_97 ( V_7 ) ;
if ( F_46 ( V_124 -> V_125 ) ) {
F_99 ( V_7 ) ;
F_120 (KERN_DEBUG pr_fmt(L_1)) ;
V_96 = - V_186 ;
goto V_104;
}
V_146 = & V_61 -> V_156 . V_157 . V_158 . V_159 ;
V_146 -> V_57 = V_57 ;
V_146 -> V_49 = V_49 ;
V_146 -> V_149 = V_58 ;
V_146 -> V_227 = V_61 -> V_148 ;
V_124 -> V_125 = V_185 ;
V_187:
V_124 -> V_126 += V_165 ;
V_96 = F_121 ( V_7 , V_146 , F_96 , V_163 -> V_226 , V_165 ,
sizeof( struct V_91 ) , & V_167 , & V_169 ,
V_172 ? V_163 -> V_174 | V_175 : V_163 -> V_174 ) ;
if ( V_96 )
F_70 ( V_7 ) ;
else if ( ! V_172 )
V_96 = F_93 ( V_7 ) ;
else if ( F_46 ( F_122 ( & V_7 -> V_228 ) ) )
V_124 -> V_125 = 0 ;
F_99 ( V_7 ) ;
V_104:
F_123 ( V_169 ) ;
if ( free )
F_124 ( V_167 . V_180 ) ;
if ( ! V_96 )
return V_126 ;
if ( V_96 == - V_153 || F_21 ( V_229 , & V_7 -> V_230 -> V_231 ) ) {
F_92 ( F_6 ( V_7 ) ,
V_154 , V_147 ) ;
}
return V_96 ;
V_224:
F_125 ( & V_169 -> V_128 ) ;
if ( ! ( V_163 -> V_174 & V_232 ) || V_126 )
goto V_225;
V_96 = 0 ;
goto V_104;
}
int F_126 ( struct V_6 * V_7 , struct V_233 * V_233 , int V_129 ,
T_7 V_234 , int V_231 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_123 * V_124 = F_7 ( V_7 ) ;
int V_235 ;
if ( V_231 & V_236 )
V_231 |= V_175 ;
if ( ! V_124 -> V_125 ) {
struct V_162 V_163 = { . V_174 = V_231 | V_175 } ;
V_235 = F_95 ( NULL , V_7 , & V_163 , 0 ) ;
if ( V_235 < 0 )
return V_235 ;
}
F_97 ( V_7 ) ;
if ( F_46 ( ! V_124 -> V_125 ) ) {
F_99 ( V_7 ) ;
F_120 (KERN_DEBUG pr_fmt(L_2)) ;
return - V_186 ;
}
V_235 = F_127 ( V_7 , & V_61 -> V_156 . V_157 . V_158 . V_159 ,
V_233 , V_129 , V_234 , V_231 ) ;
if ( V_235 == - V_179 ) {
F_99 ( V_7 ) ;
return F_128 ( V_7 -> V_230 , V_233 , V_129 ,
V_234 , V_231 ) ;
}
if ( V_235 < 0 ) {
F_70 ( V_7 ) ;
goto V_104;
}
V_124 -> V_126 += V_234 ;
if ( ! ( V_124 -> V_173 || ( V_231 & V_175 ) ) )
V_235 = F_93 ( V_7 ) ;
if ( ! V_235 )
V_235 = V_234 ;
V_104:
F_99 ( V_7 ) ;
return V_235 ;
}
static unsigned int F_129 ( struct V_6 * V_7 )
{
struct V_237 V_238 , * V_239 = & V_7 -> V_240 ;
struct V_80 * V_81 ;
unsigned int V_18 ;
F_130 ( & V_238 ) ;
F_20 ( & V_239 -> V_19 ) ;
while ( ( V_81 = F_131 ( V_239 ) ) != NULL &&
F_132 ( V_81 ) ) {
F_133 ( F_6 ( V_7 ) , V_241 ,
F_87 ( V_7 ) ) ;
F_133 ( F_6 ( V_7 ) , V_242 ,
F_87 ( V_7 ) ) ;
F_134 ( & V_7 -> V_243 ) ;
F_135 ( V_81 , V_239 ) ;
F_136 ( & V_238 , V_81 ) ;
}
V_18 = V_81 ? V_81 -> V_126 : 0 ;
F_23 ( & V_239 -> V_19 ) ;
if ( ! F_122 ( & V_238 ) ) {
bool V_244 = F_137 ( V_7 ) ;
F_138 ( & V_238 ) ;
F_139 ( V_7 ) ;
F_140 ( V_7 , V_244 ) ;
}
return V_18 ;
}
int F_141 ( struct V_6 * V_7 , int V_245 , unsigned long V_246 )
{
switch ( V_245 ) {
case V_247 :
{
int V_248 = F_142 ( V_7 ) ;
return F_143 ( V_248 , ( int V_249 * ) V_246 ) ;
}
case V_250 :
{
unsigned int V_248 = F_129 ( V_7 ) ;
if ( V_248 )
V_248 -= sizeof( struct V_91 ) ;
return F_143 ( V_248 , ( int V_249 * ) V_246 ) ;
}
default:
return - V_251 ;
}
return 0 ;
}
int F_144 ( struct V_160 * V_161 , struct V_6 * V_7 , struct V_162 * V_163 ,
T_7 V_126 , int V_252 , int V_231 , int * V_253 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
F_100 ( struct V_189 * , sin , V_163 -> V_188 ) ;
struct V_80 * V_81 ;
unsigned int V_165 , V_254 ;
int V_255 , V_256 = 0 ;
int V_96 ;
int V_147 = F_87 ( V_7 ) ;
bool V_244 ;
if ( V_231 & V_257 )
return F_145 ( V_7 , V_163 , V_126 , V_253 ) ;
V_258:
V_81 = F_146 ( V_7 , V_231 | ( V_252 ? V_259 : 0 ) ,
& V_255 , & V_256 , & V_96 ) ;
if ( ! V_81 )
goto V_104;
V_165 = V_81 -> V_126 - sizeof( struct V_91 ) ;
V_254 = V_126 ;
if ( V_254 > V_165 )
V_254 = V_165 ;
else if ( V_254 < V_165 )
V_163 -> V_174 |= V_260 ;
if ( V_254 < V_165 || F_147 ( V_81 ) -> V_261 ) {
if ( F_132 ( V_81 ) )
goto V_262;
}
if ( F_148 ( V_81 ) )
V_96 = F_149 ( V_81 , sizeof( struct V_91 ) ,
V_163 -> V_226 , V_254 ) ;
else {
V_96 = F_150 ( V_81 ,
sizeof( struct V_91 ) ,
V_163 -> V_226 ) ;
if ( V_96 == - V_186 )
goto V_262;
}
if ( F_46 ( V_96 ) ) {
F_151 ( V_81 , F_144 ) ;
if ( ! V_255 ) {
F_134 ( & V_7 -> V_243 ) ;
F_92 ( F_6 ( V_7 ) ,
V_242 , V_147 ) ;
}
goto V_263;
}
if ( ! V_255 )
F_92 ( F_6 ( V_7 ) ,
V_264 , V_147 ) ;
F_152 ( V_163 , V_7 , V_81 ) ;
if ( sin ) {
sin -> V_192 = V_185 ;
sin -> V_197 = F_73 ( V_81 ) -> V_98 ;
sin -> V_195 . V_196 = F_56 ( V_81 ) -> V_49 ;
memset ( sin -> V_265 , 0 , sizeof( sin -> V_265 ) ) ;
* V_253 = sizeof( * sin ) ;
}
if ( V_61 -> V_266 )
F_153 ( V_163 , V_81 ) ;
V_96 = V_254 ;
if ( V_231 & V_260 )
V_96 = V_165 ;
V_263:
F_154 ( V_7 , V_81 ) ;
V_104:
return V_96 ;
V_262:
V_244 = F_137 ( V_7 ) ;
if ( ! F_155 ( V_7 , V_81 , V_231 ) ) {
F_92 ( F_6 ( V_7 ) , V_241 , V_147 ) ;
F_92 ( F_6 ( V_7 ) , V_242 , V_147 ) ;
}
F_140 ( V_7 , V_244 ) ;
if ( V_252 )
return - V_267 ;
V_163 -> V_174 &= ~ V_260 ;
goto V_258;
}
int F_156 ( struct V_6 * V_7 , int V_231 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
V_7 -> V_118 = V_268 ;
V_61 -> V_64 = 0 ;
V_61 -> V_65 = 0 ;
F_157 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_269 & V_270 ) )
F_158 ( V_7 ) ;
if ( ! ( V_7 -> V_269 & V_271 ) ) {
V_7 -> V_24 -> V_272 ( V_7 ) ;
V_61 -> V_148 = 0 ;
}
F_159 ( V_7 ) ;
return 0 ;
}
void F_160 ( struct V_6 * V_7 )
{
if ( F_161 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
F_20 ( & V_4 -> V_19 ) ;
if ( F_162 ( V_7 ) ) {
V_4 -> V_36 -- ;
F_25 ( V_7 ) -> V_42 = 0 ;
F_28 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_163 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_23 ( & V_4 -> V_19 ) ;
}
}
void F_164 ( struct V_6 * V_7 , T_8 V_273 )
{
if ( F_161 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_274 ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
V_274 = F_24 ( V_23 , V_273 ) ;
F_7 ( V_7 ) -> V_39 = V_273 ;
if ( V_17 != V_274 ) {
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_20 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_163 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_274 -> V_19 ) ;
F_29 ( & F_7 ( V_7 ) -> V_44 ,
& V_274 -> V_43 ) ;
V_274 -> V_36 ++ ;
F_13 ( & V_274 -> V_19 ) ;
F_23 ( & V_4 -> V_19 ) ;
}
}
}
static void F_165 ( struct V_6 * V_7 )
{
T_8 V_275 = F_32 ( F_6 ( V_7 ) ,
F_25 ( V_7 ) -> V_48 ,
F_25 ( V_7 ) -> V_42 ) ;
F_164 ( V_7 , V_275 ) ;
}
static int F_166 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
int V_276 ;
if ( F_25 ( V_7 ) -> V_64 ) {
F_167 ( V_7 , V_81 ) ;
F_168 ( V_7 , V_81 ) ;
}
V_276 = F_169 ( V_7 , V_81 ) ;
if ( V_276 < 0 ) {
int V_147 = F_87 ( V_7 ) ;
if ( V_276 == - V_277 )
F_133 ( F_6 ( V_7 ) , V_278 ,
V_147 ) ;
F_133 ( F_6 ( V_7 ) , V_242 , V_147 ) ;
F_170 ( V_81 ) ;
F_171 ( V_276 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_172 ( void )
{
if ( ! F_173 ( & V_279 ) )
F_174 ( & V_279 ) ;
}
int F_175 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
struct V_123 * V_124 = F_7 ( V_7 ) ;
int V_276 ;
int V_147 = F_87 ( V_7 ) ;
if ( ! F_176 ( V_7 , V_280 , V_81 ) )
goto V_281;
F_177 ( V_81 ) ;
if ( F_178 ( & V_279 ) && V_124 -> V_282 ) {
int (* F_179)( struct V_6 * V_7 , struct V_80 * V_81 );
F_179 = F_180 ( V_124 -> F_179 ) ;
if ( V_81 -> V_126 > sizeof( struct V_91 ) && F_179 != NULL ) {
int V_235 ;
if ( F_132 ( V_81 ) )
goto V_283;
V_235 = F_179 ( V_7 , V_81 ) ;
if ( V_235 <= 0 ) {
F_133 ( F_6 ( V_7 ) ,
V_264 ,
V_147 ) ;
return - V_235 ;
}
}
}
if ( ( V_147 & V_284 ) && F_147 ( V_81 ) -> V_261 ) {
if ( V_124 -> V_285 == 0 ) {
F_120 ( V_286 L_3 ,
F_147 ( V_81 ) -> V_287 , V_81 -> V_126 ) ;
goto V_281;
}
if ( F_147 ( V_81 ) -> V_287 < V_124 -> V_285 ) {
F_120 ( V_286 L_4 ,
F_147 ( V_81 ) -> V_287 , V_124 -> V_285 ) ;
goto V_281;
}
}
if ( F_181 ( V_7 -> V_288 ) &&
F_132 ( V_81 ) )
goto V_283;
if ( F_182 ( V_7 , V_7 -> V_289 ) ) {
F_133 ( F_6 ( V_7 ) , V_278 ,
V_147 ) ;
goto V_281;
}
V_276 = 0 ;
F_183 ( V_7 , V_81 ) ;
F_184 ( V_7 ) ;
if ( ! F_185 ( V_7 ) )
V_276 = F_166 ( V_7 , V_81 ) ;
else if ( F_186 ( V_7 , V_81 , V_7 -> V_289 ) ) {
F_187 ( V_7 ) ;
goto V_281;
}
F_187 ( V_7 ) ;
return V_276 ;
V_283:
F_133 ( F_6 ( V_7 ) , V_241 , V_147 ) ;
V_281:
F_133 ( F_6 ( V_7 ) , V_242 , V_147 ) ;
F_134 ( & V_7 -> V_243 ) ;
F_170 ( V_81 ) ;
return - 1 ;
}
static void F_188 ( struct V_6 * * V_290 , unsigned int V_36 ,
struct V_80 * V_81 , unsigned int V_291 )
{
unsigned int V_292 ;
struct V_80 * V_293 = NULL ;
struct V_6 * V_7 ;
for ( V_292 = 0 ; V_292 < V_36 ; V_292 ++ ) {
V_7 = V_290 [ V_292 ] ;
if ( F_98 ( V_293 == NULL ) )
V_293 = ( V_292 == V_291 ) ? V_81 : F_189 ( V_81 , V_294 ) ;
if ( ! V_293 ) {
F_134 ( & V_7 -> V_243 ) ;
F_133 ( F_6 ( V_7 ) , V_278 ,
F_87 ( V_7 ) ) ;
F_133 ( F_6 ( V_7 ) , V_242 ,
F_87 ( V_7 ) ) ;
}
if ( V_293 && F_175 ( V_7 , V_293 ) <= 0 )
V_293 = NULL ;
F_48 ( V_7 ) ;
}
if ( F_46 ( V_293 ) )
F_170 ( V_293 ) ;
}
static void F_190 ( struct V_6 * V_7 , struct V_295 * V_128 )
{
struct V_295 * V_296 ;
F_191 ( V_128 ) ;
V_296 = F_192 ( & V_7 -> V_297 , V_128 ) ;
F_193 ( V_296 ) ;
}
static int F_194 ( struct V_1 * V_1 , struct V_80 * V_81 ,
struct V_91 * V_92 ,
T_3 V_49 , T_3 V_57 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_290 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_10 * V_11 ;
unsigned short V_55 = F_50 ( V_92 -> V_97 ) ;
struct V_3 * V_4 = F_18 ( V_23 , V_1 , V_55 ) ;
int V_59 = V_81 -> V_84 -> V_99 ;
unsigned int V_36 = 0 , V_129 = F_77 ( F_195 ( * V_7 ) , V_298 ) ;
unsigned int V_78 = 0 , V_299 = 0 , V_300 = ( V_4 -> V_36 > 10 ) ;
if ( V_300 ) {
V_299 = F_32 ( V_1 , F_36 ( V_53 ) , V_55 ) &
V_22 . V_33 ;
V_78 = F_32 ( V_1 , V_57 , V_55 ) & V_22 . V_33 ;
V_301:
V_4 = & V_22 . V_78 [ V_78 ] ;
V_129 = F_77 ( F_195 ( * V_7 ) , V_302 . V_303 ) ;
}
F_11 ( & V_4 -> V_19 ) ;
F_196 (sk, node, &hslot->head, offset) {
if ( F_61 ( V_1 , V_7 ,
V_92 -> V_97 , V_57 ,
V_92 -> V_98 , V_49 ,
V_59 , V_55 ) ) {
if ( F_46 ( V_36 == F_197 ( V_290 ) ) ) {
F_188 ( V_290 , V_36 , V_81 , ~ 0 ) ;
V_36 = 0 ;
}
V_290 [ V_36 ++ ] = V_7 ;
F_198 ( V_7 ) ;
}
}
F_13 ( & V_4 -> V_19 ) ;
if ( V_300 && V_78 != V_299 ) {
V_78 = V_299 ;
goto V_301;
}
if ( V_36 ) {
F_188 ( V_290 , V_36 , V_81 , V_36 - 1 ) ;
} else {
F_170 ( V_81 ) ;
}
return 0 ;
}
static inline int F_199 ( struct V_80 * V_81 , struct V_91 * V_92 ,
int V_304 )
{
int V_96 ;
F_147 ( V_81 ) -> V_261 = 0 ;
F_147 ( V_81 ) -> V_287 = V_81 -> V_126 ;
if ( V_304 == V_305 ) {
V_96 = F_200 ( V_81 , V_92 ) ;
if ( V_96 )
return V_96 ;
}
return F_201 ( V_81 , V_304 , V_92 -> V_134 ,
V_306 ) ;
}
int F_202 ( struct V_80 * V_81 , struct V_22 * V_23 ,
int V_304 )
{
struct V_6 * V_7 ;
struct V_91 * V_92 ;
unsigned short V_165 ;
struct V_168 * V_169 = F_203 ( V_81 ) ;
T_3 V_49 , V_57 ;
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
if ( ! F_204 ( V_81 , sizeof( struct V_91 ) ) )
goto V_281;
V_92 = F_73 ( V_81 ) ;
V_165 = F_50 ( V_92 -> V_126 ) ;
V_49 = F_56 ( V_81 ) -> V_49 ;
V_57 = F_56 ( V_81 ) -> V_57 ;
if ( V_165 > V_81 -> V_126 )
goto V_307;
if ( V_304 == V_135 ) {
if ( V_165 < sizeof( * V_92 ) || F_205 ( V_81 , V_165 ) )
goto V_307;
V_92 = F_73 ( V_81 ) ;
}
if ( F_199 ( V_81 , V_92 , V_304 ) )
goto V_283;
V_7 = F_206 ( V_81 ) ;
if ( V_7 ) {
struct V_295 * V_128 = F_58 ( V_81 ) ;
int V_235 ;
if ( F_46 ( V_7 -> V_297 != V_128 ) )
F_190 ( V_7 , V_128 ) ;
V_235 = F_175 ( V_7 , V_81 ) ;
F_48 ( V_7 ) ;
if ( V_235 > 0 )
return - V_235 ;
return 0 ;
} else {
if ( V_169 -> V_220 & ( V_221 | V_308 ) )
return F_194 ( V_1 , V_81 , V_92 ,
V_49 , V_57 , V_23 ) ;
V_7 = F_55 ( V_81 , V_92 -> V_98 , V_92 -> V_97 , V_23 ) ;
}
if ( V_7 != NULL ) {
int V_235 ;
V_235 = F_175 ( V_7 , V_81 ) ;
F_48 ( V_7 ) ;
if ( V_235 > 0 )
return - V_235 ;
return 0 ;
}
if ( ! F_176 ( NULL , V_280 , V_81 ) )
goto V_281;
F_177 ( V_81 ) ;
if ( F_132 ( V_81 ) )
goto V_283;
F_133 ( V_1 , V_309 , V_304 == V_305 ) ;
F_207 ( V_81 , V_107 , V_310 , 0 ) ;
F_170 ( V_81 ) ;
return 0 ;
V_307:
F_120 ( V_311 L_5 ,
V_304 == V_305 ? L_6 : L_7 ,
& V_49 , F_50 ( V_92 -> V_98 ) ,
V_165 , V_81 -> V_126 ,
& V_57 , F_50 ( V_92 -> V_97 ) ) ;
goto V_281;
V_283:
F_120 ( V_311 L_8 ,
V_304 == V_305 ? L_6 : L_7 ,
& V_49 , F_50 ( V_92 -> V_98 ) , & V_57 , F_50 ( V_92 -> V_97 ) ,
V_165 ) ;
F_133 ( V_1 , V_241 , V_304 == V_305 ) ;
V_281:
F_133 ( V_1 , V_242 , V_304 == V_305 ) ;
F_170 ( V_81 ) ;
return 0 ;
}
static struct V_6 * F_208 ( struct V_1 * V_1 ,
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
static struct V_6 * F_209 ( struct V_1 * V_1 ,
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
F_210 ( V_312 , V_88 , V_86 ) ;
const T_9 V_313 = F_211 ( V_87 , V_55 ) ;
F_52 () ;
V_71 = NULL ;
F_43 (sk, node, &hslot2->head) {
if ( F_212 ( V_7 , V_1 , V_312 ,
V_88 , V_86 , V_313 , V_59 ) )
V_71 = V_7 ;
break;
}
if ( V_71 ) {
if ( F_46 ( ! F_47 ( & V_71 -> V_77 , 2 ) ) )
V_71 = NULL ;
else if ( F_46 ( ! F_212 ( V_7 , V_1 , V_312 ,
V_88 , V_86 ,
V_313 , V_59 ) ) ) {
F_48 ( V_71 ) ;
V_71 = NULL ;
}
}
F_53 () ;
return V_71 ;
}
void F_213 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
const struct V_82 * V_83 ;
const struct V_91 * V_92 ;
struct V_6 * V_7 ;
struct V_295 * V_128 ;
int V_59 = V_81 -> V_84 -> V_99 ;
if ( ! F_204 ( V_81 , F_74 ( V_81 ) + sizeof( struct V_91 ) ) )
return;
V_83 = F_56 ( V_81 ) ;
V_92 = F_73 ( V_81 ) ;
if ( V_81 -> V_314 == V_315 ||
V_81 -> V_314 == V_316 )
V_7 = F_208 ( V_1 , V_92 -> V_97 , V_83 -> V_57 ,
V_92 -> V_98 , V_83 -> V_49 , V_59 ) ;
else if ( V_81 -> V_314 == V_317 )
V_7 = F_209 ( V_1 , V_92 -> V_97 , V_83 -> V_57 ,
V_92 -> V_98 , V_83 -> V_49 , V_59 ) ;
else
return;
if ( ! V_7 )
return;
V_81 -> V_7 = V_7 ;
V_81 -> V_318 = V_319 ;
V_128 = V_7 -> V_297 ;
if ( V_128 )
V_128 = F_214 ( V_128 , 0 ) ;
if ( V_128 )
F_215 ( V_81 , V_128 ) ;
}
int F_216 ( struct V_80 * V_81 )
{
return F_202 ( V_81 , & V_22 , V_135 ) ;
}
void F_217 ( struct V_6 * V_7 )
{
struct V_123 * V_124 = F_7 ( V_7 ) ;
bool V_244 = F_137 ( V_7 ) ;
F_70 ( V_7 ) ;
F_140 ( V_7 , V_244 ) ;
if ( F_178 ( & V_279 ) && V_124 -> V_282 ) {
void (* F_218)( struct V_6 * V_7 );
F_218 = F_180 ( V_124 -> F_218 ) ;
if ( F_218 )
F_218 ( V_7 ) ;
}
}
int F_219 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_249 * V_322 , unsigned int V_206 ,
int (* F_220)( struct V_6 * ) )
{
struct V_123 * V_124 = F_7 ( V_7 ) ;
int V_323 , V_324 ;
int V_96 = 0 ;
int V_147 = F_87 ( V_7 ) ;
if ( V_206 < sizeof( int ) )
return - V_186 ;
if ( F_221 ( V_323 , ( int V_249 * ) V_322 ) )
return - V_325 ;
V_324 = V_323 ? 1 : 0 ;
switch ( V_321 ) {
case V_326 :
if ( V_323 != 0 ) {
V_124 -> V_173 = 1 ;
} else {
V_124 -> V_173 = 0 ;
F_97 ( V_7 ) ;
(* F_220)( V_7 ) ;
F_99 ( V_7 ) ;
}
break;
case V_327 :
switch ( V_323 ) {
case 0 :
case V_328 :
case V_329 :
V_124 -> F_179 = V_330 ;
case V_331 :
V_124 -> V_282 = V_323 ;
F_172 () ;
break;
default:
V_96 = - V_332 ;
break;
}
break;
case V_333 :
V_124 -> V_334 = V_324 ;
break;
case V_335 :
V_124 -> V_336 = V_324 ;
break;
case V_337 :
if ( ! V_147 )
return - V_332 ;
if ( V_323 != 0 && V_323 < 8 )
V_323 = 8 ;
else if ( V_323 > V_338 )
V_323 = V_338 ;
V_124 -> V_339 = V_323 ;
V_124 -> V_340 |= V_341 ;
break;
case V_342 :
if ( ! V_147 )
return - V_332 ;
if ( V_323 != 0 && V_323 < 8 )
V_323 = 8 ;
else if ( V_323 > V_338 )
V_323 = V_338 ;
V_124 -> V_285 = V_323 ;
V_124 -> V_340 |= V_284 ;
break;
default:
V_96 = - V_332 ;
break;
}
return V_96 ;
}
int F_222 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_249 * V_322 , unsigned int V_206 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_219 ( V_7 , V_320 , V_321 , V_322 , V_206 ,
F_93 ) ;
return F_223 ( V_7 , V_320 , V_321 , V_322 , V_206 ) ;
}
int F_224 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_249 * V_322 , unsigned int V_206 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_219 ( V_7 , V_320 , V_321 , V_322 , V_206 ,
F_93 ) ;
return F_225 ( V_7 , V_320 , V_321 , V_322 , V_206 ) ;
}
int F_226 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_249 * V_322 , int V_249 * V_206 )
{
struct V_123 * V_124 = F_7 ( V_7 ) ;
int V_323 , V_126 ;
if ( F_221 ( V_126 , V_206 ) )
return - V_325 ;
V_126 = F_227 (unsigned int, len, sizeof(int)) ;
if ( V_126 < 0 )
return - V_186 ;
switch ( V_321 ) {
case V_326 :
V_323 = V_124 -> V_173 ;
break;
case V_327 :
V_323 = V_124 -> V_282 ;
break;
case V_333 :
V_323 = V_124 -> V_334 ;
break;
case V_335 :
V_323 = V_124 -> V_336 ;
break;
case V_337 :
V_323 = V_124 -> V_339 ;
break;
case V_342 :
V_323 = V_124 -> V_285 ;
break;
default:
return - V_332 ;
}
if ( F_143 ( V_126 , V_206 ) )
return - V_325 ;
if ( F_228 ( V_322 , & V_323 , V_126 ) )
return - V_325 ;
return 0 ;
}
int F_229 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_249 * V_322 , int V_249 * V_206 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_226 ( V_7 , V_320 , V_321 , V_322 , V_206 ) ;
return F_230 ( V_7 , V_320 , V_321 , V_322 , V_206 ) ;
}
int F_231 ( struct V_6 * V_7 , int V_320 , int V_321 ,
char V_249 * V_322 , int V_249 * V_206 )
{
if ( V_320 == V_343 || V_320 == V_344 )
return F_226 ( V_7 , V_320 , V_321 , V_322 , V_206 ) ;
return F_232 ( V_7 , V_320 , V_321 , V_322 , V_206 ) ;
}
unsigned int F_233 ( struct V_345 * V_345 , struct V_346 * V_6 , T_10 * V_347 )
{
unsigned int V_33 = F_234 ( V_345 , V_6 , V_347 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_235 ( V_7 ) ;
if ( ( V_33 & V_348 ) && ! ( V_345 -> V_349 & V_350 ) &&
! ( V_7 -> V_351 & V_352 ) && ! F_129 ( V_7 ) )
V_33 &= ~ ( V_353 | V_348 ) ;
return V_33 ;
}
static struct V_6 * F_236 ( struct V_354 * V_355 , int V_356 )
{
struct V_6 * V_7 ;
struct V_357 * V_358 = V_355 -> V_359 ;
struct V_1 * V_1 = F_237 ( V_355 ) ;
for ( V_358 -> V_360 = V_356 ; V_358 -> V_360 <= V_358 -> V_22 -> V_33 ;
++ V_358 -> V_360 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_358 -> V_22 -> V_75 [ V_358 -> V_360 ] ;
if ( F_238 ( & V_4 -> V_43 ) )
continue;
F_20 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_62 == V_358 -> V_361 )
goto V_34;
}
F_23 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_34:
return V_7 ;
}
static struct V_6 * F_239 ( struct V_354 * V_355 , struct V_6 * V_7 )
{
struct V_357 * V_358 = V_355 -> V_359 ;
struct V_1 * V_1 = F_237 ( V_355 ) ;
do {
V_7 = F_240 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_62 != V_358 -> V_361 ) );
if ( ! V_7 ) {
if ( V_358 -> V_360 <= V_358 -> V_22 -> V_33 )
F_23 ( & V_358 -> V_22 -> V_75 [ V_358 -> V_360 ] . V_19 ) ;
return F_236 ( V_355 , V_358 -> V_360 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_241 ( struct V_354 * V_355 , T_11 V_362 )
{
struct V_6 * V_7 = F_236 ( V_355 , 0 ) ;
if ( V_7 )
while ( V_362 && ( V_7 = F_239 ( V_355 , V_7 ) ) != NULL )
-- V_362 ;
return V_362 ? NULL : V_7 ;
}
static void * F_242 ( struct V_354 * V_355 , T_11 * V_362 )
{
struct V_357 * V_358 = V_355 -> V_359 ;
V_358 -> V_360 = V_363 ;
return * V_362 ? F_241 ( V_355 , * V_362 - 1 ) : V_364 ;
}
static void * F_243 ( struct V_354 * V_355 , void * V_365 , T_11 * V_362 )
{
struct V_6 * V_7 ;
if ( V_365 == V_364 )
V_7 = F_241 ( V_355 , 0 ) ;
else
V_7 = F_239 ( V_355 , V_365 ) ;
++ * V_362 ;
return V_7 ;
}
static void F_244 ( struct V_354 * V_355 , void * V_365 )
{
struct V_357 * V_358 = V_355 -> V_359 ;
if ( V_358 -> V_360 <= V_358 -> V_22 -> V_33 )
F_23 ( & V_358 -> V_22 -> V_75 [ V_358 -> V_360 ] . V_19 ) ;
}
int F_245 ( struct V_366 * V_366 , struct V_345 * V_345 )
{
struct V_367 * V_368 = F_246 ( V_366 ) ;
struct V_357 * V_369 ;
int V_96 ;
V_96 = F_247 ( V_366 , V_345 , & V_368 -> V_370 ,
sizeof( struct V_357 ) ) ;
if ( V_96 < 0 )
return V_96 ;
V_369 = ( (struct V_354 * ) V_345 -> V_371 ) -> V_359 ;
V_369 -> V_361 = V_368 -> V_361 ;
V_369 -> V_22 = V_368 -> V_22 ;
return V_96 ;
}
int F_248 ( struct V_1 * V_1 , struct V_367 * V_368 )
{
struct V_372 * V_373 ;
int V_276 = 0 ;
V_368 -> V_370 . V_356 = F_242 ;
V_368 -> V_370 . V_374 = F_243 ;
V_368 -> V_370 . V_375 = F_244 ;
V_373 = F_249 ( V_368 -> V_376 , V_377 , V_1 -> V_378 ,
V_368 -> V_379 , V_368 ) ;
if ( ! V_373 )
V_276 = - V_277 ;
return V_276 ;
}
void F_250 ( struct V_1 * V_1 , struct V_367 * V_368 )
{
F_251 ( V_368 -> V_376 , V_1 -> V_378 ) ;
}
static void F_252 ( struct V_6 * V_380 , struct V_354 * V_381 ,
int V_360 )
{
struct V_45 * V_61 = F_25 ( V_380 ) ;
T_3 V_97 = V_61 -> V_64 ;
T_3 V_127 = V_61 -> V_48 ;
T_1 V_382 = F_50 ( V_61 -> V_65 ) ;
T_1 V_383 = F_50 ( V_61 -> V_148 ) ;
F_253 ( V_381 , L_9
L_10 ,
V_360 , V_127 , V_383 , V_97 , V_382 , V_380 -> V_118 ,
F_142 ( V_380 ) ,
F_254 ( V_380 ) ,
0 , 0L , 0 ,
F_255 ( F_256 ( V_381 ) , F_3 ( V_380 ) ) ,
0 , F_257 ( V_380 ) ,
F_258 ( & V_380 -> V_77 ) , V_380 ,
F_258 ( & V_380 -> V_243 ) ) ;
}
int F_259 ( struct V_354 * V_355 , void * V_365 )
{
F_260 ( V_355 , 127 ) ;
if ( V_365 == V_364 )
F_261 ( V_355 , L_11
L_12
L_13 ) ;
else {
struct V_357 * V_358 = V_355 -> V_359 ;
F_252 ( V_365 , V_355 , V_358 -> V_360 ) ;
}
F_262 ( V_355 , '\n' ) ;
return 0 ;
}
static int T_12 F_263 ( struct V_1 * V_1 )
{
return F_248 ( V_1 , & V_384 ) ;
}
static void T_13 F_264 ( struct V_1 * V_1 )
{
F_250 ( V_1 , & V_384 ) ;
}
int T_14 F_265 ( void )
{
return F_266 ( & V_385 ) ;
}
void F_267 ( void )
{
F_268 ( & V_385 ) ;
}
static int T_14 F_269 ( char * V_386 )
{
T_15 V_235 ;
if ( ! V_386 )
return 0 ;
V_235 = F_270 ( V_386 , 0 , & V_387 ) ;
if ( V_235 )
return 0 ;
if ( V_387 && V_387 < V_388 )
V_387 = V_388 ;
return 1 ;
}
void T_14 F_271 ( struct V_22 * V_389 , const char * V_376 )
{
unsigned int V_292 ;
V_389 -> V_75 = F_272 ( V_376 ,
2 * sizeof( struct V_3 ) ,
V_387 ,
21 ,
0 ,
& V_389 -> log ,
& V_389 -> V_33 ,
V_388 ,
64 * 1024 ) ;
V_389 -> V_78 = V_389 -> V_75 + ( V_389 -> V_33 + 1 ) ;
for ( V_292 = 0 ; V_292 <= V_389 -> V_33 ; V_292 ++ ) {
F_273 ( & V_389 -> V_75 [ V_292 ] . V_43 , V_292 ) ;
V_389 -> V_75 [ V_292 ] . V_36 = 0 ;
F_274 ( & V_389 -> V_75 [ V_292 ] . V_19 ) ;
}
for ( V_292 = 0 ; V_292 <= V_389 -> V_33 ; V_292 ++ ) {
F_273 ( & V_389 -> V_78 [ V_292 ] . V_43 , V_292 ) ;
V_389 -> V_78 [ V_292 ] . V_36 = 0 ;
F_274 ( & V_389 -> V_78 [ V_292 ] . V_19 ) ;
}
}
void T_14 F_275 ( void )
{
unsigned long V_390 ;
F_271 ( & V_22 , L_14 ) ;
V_390 = F_276 () / 8 ;
V_390 = F_277 ( V_390 , 128UL ) ;
V_391 [ 0 ] = V_390 / 4 * 3 ;
V_391 [ 1 ] = V_390 ;
V_391 [ 2 ] = V_391 [ 0 ] * 2 ;
V_392 = V_393 ;
V_394 = V_393 ;
}
