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
! F_22 ( V_20 ) )
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
struct V_80 * V_130 = F_76 ( V_81 ) -> V_131 ;
int V_132 = F_77 ( V_81 ) ;
int V_127 = V_81 -> V_127 - V_132 ;
int V_133 = V_127 ;
T_6 V_134 = 0 ;
if ( ! V_130 ) {
V_81 -> V_135 = F_78 ( V_81 ) - V_81 -> V_43 ;
V_81 -> V_136 = F_79 ( struct V_92 , V_137 ) ;
V_93 -> V_137 = ~ F_80 ( V_128 , V_129 , V_127 ,
V_138 , 0 ) ;
} else {
do {
V_134 = F_81 ( V_134 , V_130 -> V_134 ) ;
V_133 -= V_130 -> V_127 ;
} while ( ( V_130 = V_130 -> V_139 ) );
V_134 = F_82 ( V_81 , V_132 , V_133 , V_134 ) ;
V_81 -> V_140 = V_141 ;
V_93 -> V_137 = F_80 ( V_128 , V_129 , V_127 , V_138 , V_134 ) ;
if ( V_93 -> V_137 == 0 )
V_93 -> V_137 = V_142 ;
}
}
static int F_83 ( struct V_80 * V_81 , struct V_143 * V_144 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_92 * V_93 ;
int V_97 = 0 ;
int V_145 = F_84 ( V_7 ) ;
int V_132 = F_77 ( V_81 ) ;
int V_127 = V_81 -> V_127 - V_132 ;
T_6 V_134 = 0 ;
V_93 = F_75 ( V_81 ) ;
V_93 -> V_99 = V_61 -> V_146 ;
V_93 -> V_98 = V_144 -> V_147 ;
V_93 -> V_127 = F_85 ( V_127 ) ;
V_93 -> V_137 = 0 ;
if ( V_145 )
V_134 = F_86 ( V_81 ) ;
else if ( V_7 -> V_148 == V_149 ) {
V_81 -> V_140 = V_141 ;
goto V_150;
} else if ( V_81 -> V_140 == V_151 ) {
F_74 ( V_81 , V_144 -> V_49 , V_144 -> V_57 ) ;
goto V_150;
} else
V_134 = F_87 ( V_81 ) ;
V_93 -> V_137 = F_80 ( V_144 -> V_49 , V_144 -> V_57 , V_127 ,
V_7 -> V_152 , V_134 ) ;
if ( V_93 -> V_137 == 0 )
V_93 -> V_137 = V_142 ;
V_150:
V_97 = F_88 ( F_6 ( V_7 ) , V_81 ) ;
if ( V_97 ) {
if ( V_97 == - V_153 && ! V_61 -> V_118 ) {
F_89 ( F_6 ( V_7 ) ,
V_154 , V_145 ) ;
V_97 = 0 ;
}
} else
F_89 ( F_6 ( V_7 ) ,
V_155 , V_145 ) ;
return V_97 ;
}
int F_90 ( struct V_6 * V_7 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_143 * V_144 = & V_61 -> V_156 . V_157 . V_158 . V_159 ;
struct V_80 * V_81 ;
int V_97 = 0 ;
V_81 = F_91 ( V_7 , V_144 ) ;
if ( ! V_81 )
goto V_105;
V_97 = F_83 ( V_81 , V_144 ) ;
V_105:
V_125 -> V_127 = 0 ;
V_125 -> V_126 = 0 ;
return V_97 ;
}
int F_92 ( struct V_160 * V_161 , struct V_6 * V_7 , struct V_162 * V_163 ,
T_7 V_127 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_124 * V_125 = F_7 ( V_7 ) ;
struct V_143 V_164 ;
struct V_143 * V_144 ;
int V_165 = V_127 ;
struct V_166 V_167 ;
struct V_168 * V_169 = NULL ;
int free = 0 ;
int V_170 = 0 ;
T_3 V_57 , V_68 , V_49 ;
T_4 V_58 ;
V_121 V_171 ;
int V_97 , V_145 = F_84 ( V_7 ) ;
int V_172 = V_125 -> V_173 || V_163 -> V_174 & V_175 ;
int (* F_93)( void * , char * , int , int , int , struct V_80 * );
struct V_80 * V_81 ;
struct V_176 V_177 ;
if ( V_127 > 0xFFFF )
return - V_112 ;
if ( V_163 -> V_174 & V_178 )
return - V_179 ;
V_167 . V_180 = NULL ;
V_167 . V_181 = 0 ;
V_167 . V_182 = 0 ;
V_167 . V_171 = - 1 ;
F_93 = V_145 ? V_183 : V_184 ;
V_144 = & V_61 -> V_156 . V_157 . V_158 . V_159 ;
if ( V_125 -> V_126 ) {
F_94 ( V_7 ) ;
if ( F_95 ( V_125 -> V_126 ) ) {
if ( F_46 ( V_125 -> V_126 != V_185 ) ) {
F_96 ( V_7 ) ;
return - V_186 ;
}
goto V_187;
}
F_96 ( V_7 ) ;
}
V_165 += sizeof( struct V_92 ) ;
if ( V_163 -> V_188 ) {
struct V_189 * V_190 = (struct V_189 * ) V_163 -> V_188 ;
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
if ( V_7 -> V_119 != V_120 )
return - V_198 ;
V_57 = V_61 -> V_64 ;
V_58 = V_61 -> V_65 ;
V_170 = 1 ;
}
V_167 . V_199 = V_61 -> V_200 ;
V_167 . V_201 = V_7 -> V_15 ;
F_97 ( V_7 , & V_167 . V_181 ) ;
if ( V_163 -> V_202 ) {
V_97 = F_98 ( F_6 ( V_7 ) , V_163 , & V_167 ) ;
if ( V_97 )
return V_97 ;
if ( V_167 . V_180 )
free = 1 ;
V_170 = 0 ;
}
if ( ! V_167 . V_180 ) {
struct V_203 * V_204 ;
F_52 () ;
V_204 = F_99 ( V_61 -> V_204 ) ;
if ( V_204 ) {
memcpy ( & V_177 , V_204 ,
sizeof( * V_204 ) + V_204 -> V_180 . V_205 ) ;
V_167 . V_180 = & V_177 . V_180 ;
}
F_53 () ;
}
V_49 = V_167 . V_199 ;
V_167 . V_199 = V_68 = V_57 ;
if ( V_167 . V_180 && V_167 . V_180 -> V_180 . V_206 ) {
if ( ! V_57 )
return - V_186 ;
V_68 = V_167 . V_180 -> V_180 . V_68 ;
V_170 = 0 ;
}
V_171 = F_100 ( & V_167 , V_61 ) ;
if ( F_101 ( V_7 , V_207 ) ||
( V_163 -> V_174 & V_208 ) ||
( V_167 . V_180 && V_167 . V_180 -> V_180 . V_209 ) ) {
V_171 |= V_210 ;
V_170 = 0 ;
}
if ( F_102 ( V_57 ) ) {
if ( ! V_167 . V_201 )
V_167 . V_201 = V_61 -> V_211 ;
if ( ! V_49 )
V_49 = V_61 -> V_212 ;
V_170 = 0 ;
} else if ( ! V_167 . V_201 )
V_167 . V_201 = V_61 -> V_213 ;
if ( V_170 )
V_169 = (struct V_168 * ) F_103 ( V_7 , 0 ) ;
if ( V_169 == NULL ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
V_144 = & V_164 ;
F_104 ( V_144 , V_167 . V_201 , V_7 -> V_214 , V_171 ,
V_215 , V_7 -> V_152 ,
F_105 ( V_7 ) | V_216 ,
V_68 , V_49 , V_58 , V_61 -> V_146 ) ;
F_106 ( V_7 , F_107 ( V_144 ) ) ;
V_169 = F_108 ( V_1 , V_144 , V_7 ) ;
if ( F_109 ( V_169 ) ) {
V_97 = F_110 ( V_169 ) ;
V_169 = NULL ;
if ( V_97 == - V_217 )
F_111 ( V_1 , V_218 ) ;
goto V_105;
}
V_97 = - V_219 ;
if ( ( V_169 -> V_220 & V_221 ) &&
! F_101 ( V_7 , V_222 ) )
goto V_105;
if ( V_170 )
F_112 ( V_7 , F_113 ( & V_169 -> V_129 ) ) ;
}
if ( V_163 -> V_174 & V_223 )
goto V_224;
V_225:
V_49 = V_144 -> V_49 ;
if ( ! V_167 . V_199 )
V_57 = V_167 . V_199 = V_144 -> V_57 ;
if ( ! V_172 ) {
V_81 = F_114 ( V_7 , V_144 , F_93 , V_163 -> V_226 , V_165 ,
sizeof( struct V_92 ) , & V_167 , & V_169 ,
V_163 -> V_174 ) ;
V_97 = F_110 ( V_81 ) ;
if ( ! F_115 ( V_81 ) )
V_97 = F_83 ( V_81 , V_144 ) ;
goto V_105;
}
F_94 ( V_7 ) ;
if ( F_46 ( V_125 -> V_126 ) ) {
F_96 ( V_7 ) ;
F_116 (KERN_DEBUG pr_fmt(L_1)) ;
V_97 = - V_186 ;
goto V_105;
}
V_144 = & V_61 -> V_156 . V_157 . V_158 . V_159 ;
V_144 -> V_57 = V_57 ;
V_144 -> V_49 = V_49 ;
V_144 -> V_147 = V_58 ;
V_144 -> V_227 = V_61 -> V_146 ;
V_125 -> V_126 = V_185 ;
V_187:
V_125 -> V_127 += V_165 ;
V_97 = F_117 ( V_7 , V_144 , F_93 , V_163 -> V_226 , V_165 ,
sizeof( struct V_92 ) , & V_167 , & V_169 ,
V_172 ? V_163 -> V_174 | V_175 : V_163 -> V_174 ) ;
if ( V_97 )
F_72 ( V_7 ) ;
else if ( ! V_172 )
V_97 = F_90 ( V_7 ) ;
else if ( F_46 ( F_118 ( & V_7 -> V_228 ) ) )
V_125 -> V_126 = 0 ;
F_96 ( V_7 ) ;
V_105:
F_119 ( V_169 ) ;
if ( free )
F_120 ( V_167 . V_180 ) ;
if ( ! V_97 )
return V_127 ;
if ( V_97 == - V_153 || F_21 ( V_229 , & V_7 -> V_230 -> V_231 ) ) {
F_89 ( F_6 ( V_7 ) ,
V_154 , V_145 ) ;
}
return V_97 ;
V_224:
F_121 ( & V_169 -> V_129 ) ;
if ( ! ( V_163 -> V_174 & V_232 ) || V_127 )
goto V_225;
V_97 = 0 ;
goto V_105;
}
int F_122 ( struct V_6 * V_7 , struct V_233 * V_233 , int V_132 ,
T_7 V_234 , int V_231 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_235 ;
if ( V_231 & V_236 )
V_231 |= V_175 ;
if ( ! V_125 -> V_126 ) {
struct V_162 V_163 = { . V_174 = V_231 | V_175 } ;
V_235 = F_92 ( NULL , V_7 , & V_163 , 0 ) ;
if ( V_235 < 0 )
return V_235 ;
}
F_94 ( V_7 ) ;
if ( F_46 ( ! V_125 -> V_126 ) ) {
F_96 ( V_7 ) ;
F_116 (KERN_DEBUG pr_fmt(L_2)) ;
return - V_186 ;
}
V_235 = F_123 ( V_7 , & V_61 -> V_156 . V_157 . V_158 . V_159 ,
V_233 , V_132 , V_234 , V_231 ) ;
if ( V_235 == - V_179 ) {
F_96 ( V_7 ) ;
return F_124 ( V_7 -> V_230 , V_233 , V_132 ,
V_234 , V_231 ) ;
}
if ( V_235 < 0 ) {
F_72 ( V_7 ) ;
goto V_105;
}
V_125 -> V_127 += V_234 ;
if ( ! ( V_125 -> V_173 || ( V_231 & V_175 ) ) )
V_235 = F_90 ( V_7 ) ;
if ( ! V_235 )
V_235 = V_234 ;
V_105:
F_96 ( V_7 ) ;
return V_235 ;
}
static unsigned int F_125 ( struct V_6 * V_7 )
{
struct V_237 V_238 , * V_239 = & V_7 -> V_240 ;
struct V_80 * V_81 ;
unsigned int V_18 ;
F_126 ( & V_238 ) ;
F_20 ( & V_239 -> V_19 ) ;
while ( ( V_81 = F_127 ( V_239 ) ) != NULL &&
F_128 ( V_81 ) ) {
F_129 ( F_6 ( V_7 ) , V_241 ,
F_84 ( V_7 ) ) ;
F_129 ( F_6 ( V_7 ) , V_242 ,
F_84 ( V_7 ) ) ;
F_130 ( & V_7 -> V_243 ) ;
F_131 ( V_81 , V_239 ) ;
F_132 ( & V_238 , V_81 ) ;
}
V_18 = V_81 ? V_81 -> V_127 : 0 ;
F_23 ( & V_239 -> V_19 ) ;
if ( ! F_118 ( & V_238 ) ) {
bool V_244 = F_133 ( V_7 ) ;
F_134 ( & V_238 ) ;
F_135 ( V_7 ) ;
F_136 ( V_7 , V_244 ) ;
}
return V_18 ;
}
int F_137 ( struct V_6 * V_7 , int V_245 , unsigned long V_246 )
{
switch ( V_245 ) {
case V_247 :
{
int V_248 = F_138 ( V_7 ) ;
return F_139 ( V_248 , ( int V_249 * ) V_246 ) ;
}
case V_250 :
{
unsigned int V_248 = F_125 ( V_7 ) ;
if ( V_248 )
V_248 -= sizeof( struct V_92 ) ;
return F_139 ( V_248 , ( int V_249 * ) V_246 ) ;
}
default:
return - V_251 ;
}
return 0 ;
}
int F_140 ( struct V_160 * V_161 , struct V_6 * V_7 , struct V_162 * V_163 ,
T_7 V_127 , int V_252 , int V_231 , int * V_253 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_189 * sin = (struct V_189 * ) V_163 -> V_188 ;
struct V_80 * V_81 ;
unsigned int V_165 , V_254 ;
int V_255 , V_256 = 0 ;
int V_97 ;
int V_145 = F_84 ( V_7 ) ;
bool V_244 ;
if ( V_231 & V_257 )
return F_141 ( V_7 , V_163 , V_127 , V_253 ) ;
V_258:
V_81 = F_142 ( V_7 , V_231 | ( V_252 ? V_259 : 0 ) ,
& V_255 , & V_256 , & V_97 ) ;
if ( ! V_81 )
goto V_105;
V_165 = V_81 -> V_127 - sizeof( struct V_92 ) ;
V_254 = V_127 ;
if ( V_254 > V_165 )
V_254 = V_165 ;
else if ( V_254 < V_165 )
V_163 -> V_174 |= V_260 ;
if ( V_254 < V_165 || F_143 ( V_81 ) -> V_261 ) {
if ( F_128 ( V_81 ) )
goto V_262;
}
if ( F_144 ( V_81 ) )
V_97 = F_145 ( V_81 , sizeof( struct V_92 ) ,
V_163 -> V_226 , V_254 ) ;
else {
V_97 = F_146 ( V_81 ,
sizeof( struct V_92 ) ,
V_163 -> V_226 ) ;
if ( V_97 == - V_186 )
goto V_262;
}
if ( F_46 ( V_97 ) ) {
F_147 ( V_81 , F_140 ) ;
if ( ! V_255 ) {
F_130 ( & V_7 -> V_243 ) ;
F_89 ( F_6 ( V_7 ) ,
V_242 , V_145 ) ;
}
goto V_263;
}
if ( ! V_255 )
F_89 ( F_6 ( V_7 ) ,
V_264 , V_145 ) ;
F_148 ( V_163 , V_7 , V_81 ) ;
if ( sin ) {
sin -> V_192 = V_185 ;
sin -> V_197 = F_75 ( V_81 ) -> V_99 ;
sin -> V_195 . V_196 = F_56 ( V_81 ) -> V_49 ;
memset ( sin -> V_265 , 0 , sizeof( sin -> V_265 ) ) ;
* V_253 = sizeof( * sin ) ;
}
if ( V_61 -> V_266 )
F_149 ( V_163 , V_81 ) ;
V_97 = V_254 ;
if ( V_231 & V_260 )
V_97 = V_165 ;
V_263:
F_150 ( V_7 , V_81 ) ;
V_105:
return V_97 ;
V_262:
V_244 = F_133 ( V_7 ) ;
if ( ! F_151 ( V_7 , V_81 , V_231 ) ) {
F_89 ( F_6 ( V_7 ) , V_241 , V_145 ) ;
F_89 ( F_6 ( V_7 ) , V_242 , V_145 ) ;
}
F_136 ( V_7 , V_244 ) ;
if ( V_252 )
return - V_267 ;
V_163 -> V_174 &= ~ V_260 ;
goto V_258;
}
int F_152 ( struct V_6 * V_7 , int V_231 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
V_7 -> V_119 = V_268 ;
V_61 -> V_64 = 0 ;
V_61 -> V_65 = 0 ;
F_153 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_269 & V_270 ) )
F_154 ( V_7 ) ;
if ( ! ( V_7 -> V_269 & V_271 ) ) {
V_7 -> V_24 -> V_272 ( V_7 ) ;
V_61 -> V_146 = 0 ;
}
F_155 ( V_7 ) ;
return 0 ;
}
void F_156 ( struct V_6 * V_7 )
{
if ( F_157 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
F_20 ( & V_4 -> V_19 ) ;
if ( F_158 ( V_7 ) ) {
V_4 -> V_36 -- ;
F_25 ( V_7 ) -> V_42 = 0 ;
F_28 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_159 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_23 ( & V_4 -> V_19 ) ;
}
}
void F_160 ( struct V_6 * V_7 , T_8 V_273 )
{
if ( F_157 ( V_7 ) ) {
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
F_159 ( & F_7 ( V_7 ) -> V_44 ) ;
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
static void F_161 ( struct V_6 * V_7 )
{
T_8 V_275 = F_32 ( F_6 ( V_7 ) ,
F_25 ( V_7 ) -> V_48 ,
F_25 ( V_7 ) -> V_42 ) ;
F_160 ( V_7 , V_275 ) ;
}
static int F_162 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
int V_276 ;
if ( F_25 ( V_7 ) -> V_64 ) {
F_163 ( V_7 , V_81 ) ;
F_164 ( V_7 , V_81 ) ;
}
V_276 = F_165 ( V_7 , V_81 ) ;
if ( V_276 < 0 ) {
int V_145 = F_84 ( V_7 ) ;
if ( V_276 == - V_277 )
F_129 ( F_6 ( V_7 ) , V_278 ,
V_145 ) ;
F_129 ( F_6 ( V_7 ) , V_242 , V_145 ) ;
F_166 ( V_81 ) ;
F_167 ( V_276 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_168 ( void )
{
if ( ! F_169 ( & V_279 ) )
F_170 ( & V_279 ) ;
}
int F_171 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_276 ;
int V_145 = F_84 ( V_7 ) ;
if ( ! F_172 ( V_7 , V_280 , V_81 ) )
goto V_281;
F_173 ( V_81 ) ;
if ( F_174 ( & V_279 ) && V_125 -> V_282 ) {
int (* F_175)( struct V_6 * V_7 , struct V_80 * V_81 );
F_175 = F_176 ( V_125 -> F_175 ) ;
if ( V_81 -> V_127 > sizeof( struct V_92 ) && F_175 != NULL ) {
int V_235 ;
V_235 = F_175 ( V_7 , V_81 ) ;
if ( V_235 <= 0 ) {
F_129 ( F_6 ( V_7 ) ,
V_264 ,
V_145 ) ;
return - V_235 ;
}
}
}
if ( ( V_145 & V_283 ) && F_143 ( V_81 ) -> V_261 ) {
if ( V_125 -> V_284 == 0 ) {
F_116 ( V_285 L_3 ,
F_143 ( V_81 ) -> V_286 , V_81 -> V_127 ) ;
goto V_281;
}
if ( F_143 ( V_81 ) -> V_286 < V_125 -> V_284 ) {
F_116 ( V_285 L_4 ,
F_143 ( V_81 ) -> V_286 , V_125 -> V_284 ) ;
goto V_281;
}
}
if ( F_177 ( V_7 -> V_287 ) &&
F_128 ( V_81 ) )
goto V_288;
if ( F_178 ( V_7 , V_81 , V_7 -> V_289 ) )
goto V_281;
V_276 = 0 ;
F_179 ( V_7 , V_81 ) ;
F_180 ( V_7 ) ;
if ( ! F_181 ( V_7 ) )
V_276 = F_162 ( V_7 , V_81 ) ;
else if ( F_182 ( V_7 , V_81 , V_7 -> V_289 ) ) {
F_183 ( V_7 ) ;
goto V_281;
}
F_183 ( V_7 ) ;
return V_276 ;
V_288:
F_129 ( F_6 ( V_7 ) , V_241 , V_145 ) ;
V_281:
F_129 ( F_6 ( V_7 ) , V_242 , V_145 ) ;
F_130 ( & V_7 -> V_243 ) ;
F_166 ( V_81 ) ;
return - 1 ;
}
static void F_184 ( struct V_6 * * V_290 , unsigned int V_36 ,
struct V_80 * V_81 , unsigned int V_291 )
{
unsigned int V_292 ;
struct V_80 * V_293 = NULL ;
struct V_6 * V_7 ;
for ( V_292 = 0 ; V_292 < V_36 ; V_292 ++ ) {
V_7 = V_290 [ V_292 ] ;
if ( F_95 ( V_293 == NULL ) )
V_293 = ( V_292 == V_291 ) ? V_81 : F_185 ( V_81 , V_294 ) ;
if ( ! V_293 ) {
F_130 ( & V_7 -> V_243 ) ;
F_129 ( F_6 ( V_7 ) , V_278 ,
F_84 ( V_7 ) ) ;
F_129 ( F_6 ( V_7 ) , V_242 ,
F_84 ( V_7 ) ) ;
}
if ( V_293 && F_171 ( V_7 , V_293 ) <= 0 )
V_293 = NULL ;
}
if ( F_46 ( V_293 ) )
F_166 ( V_293 ) ;
}
static void F_186 ( struct V_6 * V_7 , struct V_295 * V_129 )
{
struct V_295 * V_296 ;
F_187 ( V_129 ) ;
V_296 = F_188 ( & V_7 -> V_297 , V_129 ) ;
F_189 ( V_296 ) ;
}
static int F_190 ( struct V_1 * V_1 , struct V_80 * V_81 ,
struct V_92 * V_93 ,
T_3 V_49 , T_3 V_57 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_290 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_3 * V_4 = F_18 ( V_23 , V_1 , F_50 ( V_93 -> V_98 ) ) ;
int V_59 ;
unsigned int V_292 , V_36 = 0 ;
F_11 ( & V_4 -> V_19 ) ;
V_7 = F_191 ( & V_4 -> V_43 ) ;
V_59 = V_81 -> V_84 -> V_100 ;
V_7 = F_63 ( V_1 , V_7 , V_93 -> V_98 , V_57 , V_93 -> V_99 , V_49 , V_59 ) ;
while ( V_7 ) {
V_290 [ V_36 ++ ] = V_7 ;
V_7 = F_63 ( V_1 , F_192 ( V_7 ) , V_93 -> V_98 ,
V_57 , V_93 -> V_99 , V_49 , V_59 ) ;
if ( F_46 ( V_36 == F_193 ( V_290 ) ) ) {
if ( ! V_7 )
break;
F_184 ( V_290 , V_36 , V_81 , ~ 0 ) ;
V_36 = 0 ;
}
}
for ( V_292 = 0 ; V_292 < V_36 ; V_292 ++ )
F_194 ( V_290 [ V_292 ] ) ;
F_13 ( & V_4 -> V_19 ) ;
if ( V_36 ) {
F_184 ( V_290 , V_36 , V_81 , V_36 - 1 ) ;
for ( V_292 = 0 ; V_292 < V_36 ; V_292 ++ )
F_48 ( V_290 [ V_292 ] ) ;
} else {
F_166 ( V_81 ) ;
}
return 0 ;
}
static inline int F_195 ( struct V_80 * V_81 , struct V_92 * V_93 ,
int V_298 )
{
const struct V_82 * V_83 ;
int V_97 ;
F_143 ( V_81 ) -> V_261 = 0 ;
F_143 ( V_81 ) -> V_286 = V_81 -> V_127 ;
if ( V_298 == V_299 ) {
V_97 = F_196 ( V_81 , V_93 ) ;
if ( V_97 )
return V_97 ;
}
V_83 = F_56 ( V_81 ) ;
if ( V_93 -> V_137 == 0 ) {
V_81 -> V_140 = V_300 ;
} else if ( V_81 -> V_140 == V_301 ) {
if ( ! F_80 ( V_83 -> V_49 , V_83 -> V_57 , V_81 -> V_127 ,
V_298 , V_81 -> V_134 ) )
V_81 -> V_140 = V_300 ;
}
if ( ! F_144 ( V_81 ) )
V_81 -> V_134 = F_197 ( V_83 -> V_49 , V_83 -> V_57 ,
V_81 -> V_127 , V_298 , 0 ) ;
return 0 ;
}
int F_198 ( struct V_80 * V_81 , struct V_22 * V_23 ,
int V_298 )
{
struct V_6 * V_7 ;
struct V_92 * V_93 ;
unsigned short V_165 ;
struct V_168 * V_169 = F_199 ( V_81 ) ;
T_3 V_49 , V_57 ;
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
if ( ! F_200 ( V_81 , sizeof( struct V_92 ) ) )
goto V_281;
V_93 = F_75 ( V_81 ) ;
V_165 = F_50 ( V_93 -> V_127 ) ;
V_49 = F_56 ( V_81 ) -> V_49 ;
V_57 = F_56 ( V_81 ) -> V_57 ;
if ( V_165 > V_81 -> V_127 )
goto V_302;
if ( V_298 == V_138 ) {
if ( V_165 < sizeof( * V_93 ) || F_201 ( V_81 , V_165 ) )
goto V_302;
V_93 = F_75 ( V_81 ) ;
}
if ( F_195 ( V_81 , V_93 , V_298 ) )
goto V_288;
V_7 = F_202 ( V_81 ) ;
if ( V_7 ) {
struct V_295 * V_129 = F_58 ( V_81 ) ;
int V_235 ;
if ( F_46 ( V_7 -> V_297 != V_129 ) )
F_186 ( V_7 , V_129 ) ;
V_235 = F_171 ( V_7 , V_81 ) ;
F_48 ( V_7 ) ;
if ( V_235 > 0 )
return - V_235 ;
return 0 ;
} else {
if ( V_169 -> V_220 & ( V_221 | V_303 ) )
return F_190 ( V_1 , V_81 , V_93 ,
V_49 , V_57 , V_23 ) ;
V_7 = F_55 ( V_81 , V_93 -> V_99 , V_93 -> V_98 , V_23 ) ;
}
if ( V_7 != NULL ) {
int V_235 ;
V_235 = F_171 ( V_7 , V_81 ) ;
F_48 ( V_7 ) ;
if ( V_235 > 0 )
return - V_235 ;
return 0 ;
}
if ( ! F_172 ( NULL , V_280 , V_81 ) )
goto V_281;
F_173 ( V_81 ) ;
if ( F_128 ( V_81 ) )
goto V_288;
F_129 ( V_1 , V_304 , V_298 == V_299 ) ;
F_203 ( V_81 , V_108 , V_305 , 0 ) ;
F_166 ( V_81 ) ;
return 0 ;
V_302:
F_116 ( V_306 L_5 ,
V_298 == V_299 ? L_6 : L_7 ,
& V_49 , F_50 ( V_93 -> V_99 ) ,
V_165 , V_81 -> V_127 ,
& V_57 , F_50 ( V_93 -> V_98 ) ) ;
goto V_281;
V_288:
F_116 ( V_306 L_8 ,
V_298 == V_299 ? L_6 : L_7 ,
& V_49 , F_50 ( V_93 -> V_99 ) , & V_57 , F_50 ( V_93 -> V_98 ) ,
V_165 ) ;
F_129 ( V_1 , V_241 , V_298 == V_299 ) ;
V_281:
F_129 ( V_1 , V_242 , V_298 == V_299 ) ;
F_166 ( V_81 ) ;
return 0 ;
}
static struct V_6 * F_204 ( struct V_1 * V_1 ,
T_4 V_85 , T_3 V_86 ,
T_4 V_87 , T_3 V_88 ,
int V_59 )
{
struct V_6 * V_7 , * V_71 ;
struct V_10 * V_11 ;
unsigned short V_55 = F_50 ( V_85 ) ;
unsigned int V_36 , V_79 = F_51 ( V_1 , V_55 , V_22 . V_33 ) ;
struct V_3 * V_4 = & V_22 . V_75 [ V_79 ] ;
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
static struct V_6 * F_205 ( struct V_1 * V_1 ,
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
F_206 (acookie, rmt_addr, loc_addr)
const T_9 V_307 = F_207 ( V_87 , V_55 ) ;
F_52 () ;
V_71 = NULL ;
F_43 (sk, node, &hslot2->head) {
if ( F_208 ( V_7 , V_1 , V_308 ,
V_88 , V_86 , V_307 , V_59 ) )
V_71 = V_7 ;
break;
}
if ( V_71 ) {
if ( F_46 ( ! F_47 ( & V_71 -> V_77 , 2 ) ) )
V_71 = NULL ;
else if ( F_46 ( ! F_208 ( V_7 , V_1 , V_308 ,
V_88 , V_86 ,
V_307 , V_59 ) ) ) {
F_48 ( V_71 ) ;
V_71 = NULL ;
}
}
F_53 () ;
return V_71 ;
}
void F_209 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_57 ( V_81 -> V_84 ) ;
const struct V_82 * V_83 ;
const struct V_92 * V_93 ;
struct V_6 * V_7 ;
struct V_295 * V_129 ;
int V_59 = V_81 -> V_84 -> V_100 ;
if ( ! F_200 ( V_81 , F_77 ( V_81 ) + sizeof( struct V_92 ) ) )
return;
V_83 = F_56 ( V_81 ) ;
V_93 = F_75 ( V_81 ) ;
if ( V_81 -> V_309 == V_310 ||
V_81 -> V_309 == V_311 )
V_7 = F_204 ( V_1 , V_93 -> V_98 , V_83 -> V_57 ,
V_93 -> V_99 , V_83 -> V_49 , V_59 ) ;
else if ( V_81 -> V_309 == V_312 )
V_7 = F_205 ( V_1 , V_93 -> V_98 , V_83 -> V_57 ,
V_93 -> V_99 , V_83 -> V_49 , V_59 ) ;
else
return;
if ( ! V_7 )
return;
V_81 -> V_7 = V_7 ;
V_81 -> V_313 = V_314 ;
V_129 = V_7 -> V_297 ;
if ( V_129 )
V_129 = F_210 ( V_129 , 0 ) ;
if ( V_129 )
F_211 ( V_81 , V_129 ) ;
}
int F_212 ( struct V_80 * V_81 )
{
return F_198 ( V_81 , & V_22 , V_138 ) ;
}
void F_213 ( struct V_6 * V_7 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
bool V_244 = F_133 ( V_7 ) ;
F_72 ( V_7 ) ;
F_136 ( V_7 , V_244 ) ;
if ( F_174 ( & V_279 ) && V_125 -> V_282 ) {
void (* F_214)( struct V_6 * V_7 );
F_214 = F_176 ( V_125 -> F_214 ) ;
if ( F_214 )
F_214 ( V_7 ) ;
}
}
int F_215 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_249 * V_317 , unsigned int V_205 ,
int (* F_216)( struct V_6 * ) )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_318 ;
int V_97 = 0 ;
int V_145 = F_84 ( V_7 ) ;
if ( V_205 < sizeof( int ) )
return - V_186 ;
if ( F_217 ( V_318 , ( int V_249 * ) V_317 ) )
return - V_319 ;
switch ( V_316 ) {
case V_320 :
if ( V_318 != 0 ) {
V_125 -> V_173 = 1 ;
} else {
V_125 -> V_173 = 0 ;
F_94 ( V_7 ) ;
(* F_216)( V_7 ) ;
F_96 ( V_7 ) ;
}
break;
case V_321 :
switch ( V_318 ) {
case 0 :
case V_322 :
case V_323 :
V_125 -> F_175 = V_324 ;
case V_325 :
V_125 -> V_282 = V_318 ;
F_168 () ;
break;
default:
V_97 = - V_326 ;
break;
}
break;
case V_327 :
if ( ! V_145 )
return - V_326 ;
if ( V_318 != 0 && V_318 < 8 )
V_318 = 8 ;
else if ( V_318 > V_328 )
V_318 = V_328 ;
V_125 -> V_329 = V_318 ;
V_125 -> V_330 |= V_331 ;
break;
case V_332 :
if ( ! V_145 )
return - V_326 ;
if ( V_318 != 0 && V_318 < 8 )
V_318 = 8 ;
else if ( V_318 > V_328 )
V_318 = V_328 ;
V_125 -> V_284 = V_318 ;
V_125 -> V_330 |= V_283 ;
break;
default:
V_97 = - V_326 ;
break;
}
return V_97 ;
}
int F_218 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_249 * V_317 , unsigned int V_205 )
{
if ( V_315 == V_333 || V_315 == V_334 )
return F_215 ( V_7 , V_315 , V_316 , V_317 , V_205 ,
F_90 ) ;
return F_219 ( V_7 , V_315 , V_316 , V_317 , V_205 ) ;
}
int F_220 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_249 * V_317 , unsigned int V_205 )
{
if ( V_315 == V_333 || V_315 == V_334 )
return F_215 ( V_7 , V_315 , V_316 , V_317 , V_205 ,
F_90 ) ;
return F_221 ( V_7 , V_315 , V_316 , V_317 , V_205 ) ;
}
int F_222 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_249 * V_317 , int V_249 * V_205 )
{
struct V_124 * V_125 = F_7 ( V_7 ) ;
int V_318 , V_127 ;
if ( F_217 ( V_127 , V_205 ) )
return - V_319 ;
V_127 = F_223 (unsigned int, len, sizeof(int)) ;
if ( V_127 < 0 )
return - V_186 ;
switch ( V_316 ) {
case V_320 :
V_318 = V_125 -> V_173 ;
break;
case V_321 :
V_318 = V_125 -> V_282 ;
break;
case V_327 :
V_318 = V_125 -> V_329 ;
break;
case V_332 :
V_318 = V_125 -> V_284 ;
break;
default:
return - V_326 ;
}
if ( F_139 ( V_127 , V_205 ) )
return - V_319 ;
if ( F_224 ( V_317 , & V_318 , V_127 ) )
return - V_319 ;
return 0 ;
}
int F_225 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_249 * V_317 , int V_249 * V_205 )
{
if ( V_315 == V_333 || V_315 == V_334 )
return F_222 ( V_7 , V_315 , V_316 , V_317 , V_205 ) ;
return F_226 ( V_7 , V_315 , V_316 , V_317 , V_205 ) ;
}
int F_227 ( struct V_6 * V_7 , int V_315 , int V_316 ,
char V_249 * V_317 , int V_249 * V_205 )
{
if ( V_315 == V_333 || V_315 == V_334 )
return F_222 ( V_7 , V_315 , V_316 , V_317 , V_205 ) ;
return F_228 ( V_7 , V_315 , V_316 , V_317 , V_205 ) ;
}
unsigned int F_229 ( struct V_335 * V_335 , struct V_336 * V_6 , T_10 * V_337 )
{
unsigned int V_33 = F_230 ( V_335 , V_6 , V_337 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_231 ( V_7 ) ;
if ( ( V_33 & V_338 ) && ! ( V_335 -> V_339 & V_340 ) &&
! ( V_7 -> V_341 & V_342 ) && ! F_125 ( V_7 ) )
V_33 &= ~ ( V_343 | V_338 ) ;
return V_33 ;
}
static struct V_6 * F_232 ( struct V_344 * V_345 , int V_346 )
{
struct V_6 * V_7 ;
struct V_347 * V_348 = V_345 -> V_349 ;
struct V_1 * V_1 = F_233 ( V_345 ) ;
for ( V_348 -> V_350 = V_346 ; V_348 -> V_350 <= V_348 -> V_22 -> V_33 ;
++ V_348 -> V_350 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_348 -> V_22 -> V_75 [ V_348 -> V_350 ] ;
if ( F_234 ( & V_4 -> V_43 ) )
continue;
F_20 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_62 == V_348 -> V_351 )
goto V_34;
}
F_23 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_34:
return V_7 ;
}
static struct V_6 * F_235 ( struct V_344 * V_345 , struct V_6 * V_7 )
{
struct V_347 * V_348 = V_345 -> V_349 ;
struct V_1 * V_1 = F_233 ( V_345 ) ;
do {
V_7 = F_192 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_62 != V_348 -> V_351 ) );
if ( ! V_7 ) {
if ( V_348 -> V_350 <= V_348 -> V_22 -> V_33 )
F_23 ( & V_348 -> V_22 -> V_75 [ V_348 -> V_350 ] . V_19 ) ;
return F_232 ( V_345 , V_348 -> V_350 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_236 ( struct V_344 * V_345 , T_11 V_352 )
{
struct V_6 * V_7 = F_232 ( V_345 , 0 ) ;
if ( V_7 )
while ( V_352 && ( V_7 = F_235 ( V_345 , V_7 ) ) != NULL )
-- V_352 ;
return V_352 ? NULL : V_7 ;
}
static void * F_237 ( struct V_344 * V_345 , T_11 * V_352 )
{
struct V_347 * V_348 = V_345 -> V_349 ;
V_348 -> V_350 = V_353 ;
return * V_352 ? F_236 ( V_345 , * V_352 - 1 ) : V_354 ;
}
static void * F_238 ( struct V_344 * V_345 , void * V_355 , T_11 * V_352 )
{
struct V_6 * V_7 ;
if ( V_355 == V_354 )
V_7 = F_236 ( V_345 , 0 ) ;
else
V_7 = F_235 ( V_345 , V_355 ) ;
++ * V_352 ;
return V_7 ;
}
static void F_239 ( struct V_344 * V_345 , void * V_355 )
{
struct V_347 * V_348 = V_345 -> V_349 ;
if ( V_348 -> V_350 <= V_348 -> V_22 -> V_33 )
F_23 ( & V_348 -> V_22 -> V_75 [ V_348 -> V_350 ] . V_19 ) ;
}
int F_240 ( struct V_356 * V_356 , struct V_335 * V_335 )
{
struct V_357 * V_358 = F_241 ( V_356 ) ;
struct V_347 * V_89 ;
int V_97 ;
V_97 = F_242 ( V_356 , V_335 , & V_358 -> V_359 ,
sizeof( struct V_347 ) ) ;
if ( V_97 < 0 )
return V_97 ;
V_89 = ( (struct V_344 * ) V_335 -> V_360 ) -> V_349 ;
V_89 -> V_351 = V_358 -> V_351 ;
V_89 -> V_22 = V_358 -> V_22 ;
return V_97 ;
}
int F_243 ( struct V_1 * V_1 , struct V_357 * V_358 )
{
struct V_361 * V_362 ;
int V_276 = 0 ;
V_358 -> V_359 . V_346 = F_237 ;
V_358 -> V_359 . V_139 = F_238 ;
V_358 -> V_359 . V_363 = F_239 ;
V_362 = F_244 ( V_358 -> V_364 , V_365 , V_1 -> V_366 ,
V_358 -> V_367 , V_358 ) ;
if ( ! V_362 )
V_276 = - V_277 ;
return V_276 ;
}
void F_245 ( struct V_1 * V_1 , struct V_357 * V_358 )
{
F_246 ( V_358 -> V_364 , V_1 -> V_366 ) ;
}
static void F_247 ( struct V_6 * V_368 , struct V_344 * V_369 ,
int V_350 )
{
struct V_45 * V_61 = F_25 ( V_368 ) ;
T_3 V_98 = V_61 -> V_64 ;
T_3 V_128 = V_61 -> V_48 ;
T_1 V_370 = F_50 ( V_61 -> V_65 ) ;
T_1 V_371 = F_50 ( V_61 -> V_146 ) ;
F_248 ( V_369 , L_9
L_10 ,
V_350 , V_128 , V_371 , V_98 , V_370 , V_368 -> V_119 ,
F_138 ( V_368 ) ,
F_249 ( V_368 ) ,
0 , 0L , 0 ,
F_250 ( F_251 ( V_369 ) , F_3 ( V_368 ) ) ,
0 , F_252 ( V_368 ) ,
F_253 ( & V_368 -> V_77 ) , V_368 ,
F_253 ( & V_368 -> V_243 ) ) ;
}
int F_254 ( struct V_344 * V_345 , void * V_355 )
{
F_255 ( V_345 , 127 ) ;
if ( V_355 == V_354 )
F_256 ( V_345 , L_11
L_12
L_13 ) ;
else {
struct V_347 * V_348 = V_345 -> V_349 ;
F_247 ( V_355 , V_345 , V_348 -> V_350 ) ;
}
F_257 ( V_345 , '\n' ) ;
return 0 ;
}
static int T_12 F_258 ( struct V_1 * V_1 )
{
return F_243 ( V_1 , & V_372 ) ;
}
static void T_13 F_259 ( struct V_1 * V_1 )
{
F_245 ( V_1 , & V_372 ) ;
}
int T_14 F_260 ( void )
{
return F_261 ( & V_373 ) ;
}
void F_262 ( void )
{
F_263 ( & V_373 ) ;
}
static int T_14 F_264 ( char * V_374 )
{
T_15 V_235 ;
if ( ! V_374 )
return 0 ;
V_235 = F_265 ( V_374 , 0 , & V_375 ) ;
if ( V_235 )
return 0 ;
if ( V_375 && V_375 < V_376 )
V_375 = V_376 ;
return 1 ;
}
void T_14 F_266 ( struct V_22 * V_377 , const char * V_364 )
{
unsigned int V_292 ;
V_377 -> V_75 = F_267 ( V_364 ,
2 * sizeof( struct V_3 ) ,
V_375 ,
21 ,
0 ,
& V_377 -> log ,
& V_377 -> V_33 ,
V_376 ,
64 * 1024 ) ;
V_377 -> V_78 = V_377 -> V_75 + ( V_377 -> V_33 + 1 ) ;
for ( V_292 = 0 ; V_292 <= V_377 -> V_33 ; V_292 ++ ) {
F_268 ( & V_377 -> V_75 [ V_292 ] . V_43 , V_292 ) ;
V_377 -> V_75 [ V_292 ] . V_36 = 0 ;
F_269 ( & V_377 -> V_75 [ V_292 ] . V_19 ) ;
}
for ( V_292 = 0 ; V_292 <= V_377 -> V_33 ; V_292 ++ ) {
F_268 ( & V_377 -> V_78 [ V_292 ] . V_43 , V_292 ) ;
V_377 -> V_78 [ V_292 ] . V_36 = 0 ;
F_269 ( & V_377 -> V_78 [ V_292 ] . V_19 ) ;
}
}
void T_14 F_270 ( void )
{
unsigned long V_378 ;
F_266 ( & V_22 , L_14 ) ;
V_378 = F_271 () / 8 ;
V_378 = F_272 ( V_378 , 128UL ) ;
V_379 [ 0 ] = V_378 / 4 * 3 ;
V_379 [ 1 ] = V_378 ;
V_379 [ 2 ] = V_379 [ 0 ] * 2 ;
V_380 = V_381 ;
V_382 = V_381 ;
}
struct V_80 * F_273 ( struct V_80 * V_81 ,
T_16 V_383 )
{
struct V_80 * V_384 = F_274 ( - V_186 ) ;
T_8 V_385 = V_81 -> V_386 ;
int V_387 = V_81 -> V_387 ;
int V_388 = F_275 ( V_81 ) - F_78 ( V_81 ) ;
T_4 V_389 = V_81 -> V_389 ;
T_16 V_390 ;
int V_391 ;
if ( F_46 ( ! F_200 ( V_81 , V_388 ) ) )
goto V_105;
V_81 -> V_392 = 0 ;
F_276 ( V_81 , V_388 ) ;
F_277 ( V_81 ) ;
F_278 ( V_81 , F_279 ( V_81 ) ) ;
V_81 -> V_387 = F_279 ( V_81 ) ;
V_81 -> V_389 = F_85 ( V_393 ) ;
V_390 = V_81 -> V_84 -> V_394 & F_280 ( V_81 ) ;
V_384 = F_281 ( V_81 , V_390 ) ;
if ( ! V_384 || F_109 ( V_384 ) ) {
F_282 ( V_81 , V_389 , V_388 , V_385 ,
V_387 ) ;
goto V_105;
}
V_391 = F_283 ( V_81 ) ;
V_81 = V_384 ;
do {
struct V_92 * V_93 ;
int V_395 = V_391 - V_388 ;
F_284 ( V_81 ) ;
V_81 -> V_392 = 1 ;
V_81 -> V_387 = V_387 ;
F_285 ( V_81 , V_391 ) ;
F_277 ( V_81 ) ;
F_278 ( V_81 , V_387 ) ;
F_286 ( V_81 , V_395 ) ;
V_93 = F_75 ( V_81 ) ;
V_93 -> V_127 = F_85 ( V_81 -> V_127 - V_395 ) ;
if ( V_389 == F_85 ( V_396 ) && F_46 ( V_93 -> V_137 ) ) {
struct V_82 * V_83 = F_56 ( V_81 ) ;
V_93 -> V_137 = ~ F_80 ( V_83 -> V_49 , V_83 -> V_57 ,
V_81 -> V_127 - V_395 ,
V_138 , 0 ) ;
V_93 -> V_137 = F_287 ( F_82 ( V_81 , V_395 ,
V_81 -> V_127 - V_395 , 0 ) ) ;
if ( V_93 -> V_137 == 0 )
V_93 -> V_137 = V_142 ;
} else if ( V_389 == F_85 ( V_397 ) ) {
struct V_398 * V_399 = F_288 ( V_81 ) ;
V_52 V_127 = V_81 -> V_127 - V_395 ;
V_93 -> V_137 = ~ F_289 ( & V_399 -> V_49 , & V_399 -> V_57 ,
V_127 , V_138 , 0 ) ;
V_93 -> V_137 = F_287 ( F_82 ( V_81 , V_395 , V_127 , 0 ) ) ;
if ( V_93 -> V_137 == 0 )
V_93 -> V_137 = V_142 ;
V_81 -> V_140 = V_141 ;
}
V_81 -> V_389 = V_389 ;
} while ( ( V_81 = V_81 -> V_139 ) );
V_105:
return V_384 ;
}
