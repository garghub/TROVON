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
return V_58 ;
}
static inline int F_39 ( struct V_6 * V_7 , struct V_1 * V_1 ,
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
return V_58 ;
}
static T_3 F_40 ( const struct V_1 * V_1 , const T_4 V_64 ,
const T_1 V_65 , const T_4 V_66 ,
const T_5 V_67 )
{
static T_3 T_6 V_68 ;
F_41 ( & T_6 , sizeof( T_6 ) ) ;
return F_42 ( V_64 , V_65 , V_66 , V_67 ,
T_6 + F_35 ( V_1 ) ) ;
}
static struct V_6 * F_43 ( struct V_1 * V_1 ,
T_4 V_48 , T_5 V_54 ,
T_4 V_55 , unsigned int V_53 , int V_57 ,
struct V_3 * V_17 , unsigned int V_37 )
{
struct V_6 * V_7 , * V_69 ;
struct V_10 * V_11 ;
int V_58 , V_70 , V_71 = 0 , V_72 = 0 ;
T_3 V_73 = 0 ;
V_74:
V_69 = NULL ;
V_70 = 0 ;
F_44 (sk, node, &hslot2->head) {
V_58 = F_39 ( V_7 , V_1 , V_48 , V_54 ,
V_55 , V_53 , V_57 ) ;
if ( V_58 > V_70 ) {
V_69 = V_7 ;
V_70 = V_58 ;
V_72 = V_7 -> V_16 ;
if ( V_72 ) {
V_73 = F_40 ( V_1 , V_55 , V_53 ,
V_48 , V_54 ) ;
V_71 = 1 ;
}
} else if ( V_58 == V_70 && V_72 ) {
V_71 ++ ;
if ( F_18 ( V_73 , V_71 ) == 0 )
V_69 = V_7 ;
V_73 = F_45 ( V_73 ) ;
}
}
if ( F_46 ( V_11 ) != V_37 )
goto V_74;
if ( V_69 ) {
if ( F_47 ( ! F_48 ( & V_69 -> V_75 , 2 ) ) )
V_69 = NULL ;
else if ( F_47 ( F_39 ( V_69 , V_1 , V_48 , V_54 ,
V_55 , V_53 , V_57 ) < V_70 ) ) {
F_49 ( V_69 ) ;
goto V_74;
}
}
return V_69 ;
}
struct V_6 * F_50 ( struct V_1 * V_1 , T_4 V_48 ,
T_5 V_54 , T_4 V_55 , T_5 V_56 ,
int V_57 , struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_69 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_51 ( V_56 ) ;
unsigned int V_76 , V_37 , V_77 = F_52 ( V_1 , V_53 , V_23 -> V_32 ) ;
struct V_3 * V_17 , * V_4 = & V_23 -> V_73 [ V_77 ] ;
int V_58 , V_70 , V_71 = 0 , V_72 = 0 ;
T_3 V_73 = 0 ;
F_53 () ;
if ( V_4 -> V_35 > 10 ) {
V_76 = F_33 ( V_1 , V_55 , V_53 ) ;
V_37 = V_76 & V_23 -> V_32 ;
V_17 = & V_23 -> V_76 [ V_37 ] ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_74;
V_69 = F_43 ( V_1 , V_48 , V_54 ,
V_55 , V_53 , V_57 ,
V_17 , V_37 ) ;
if ( ! V_69 ) {
V_76 = F_33 ( V_1 , F_37 ( V_51 ) , V_53 ) ;
V_37 = V_76 & V_23 -> V_32 ;
V_17 = & V_23 -> V_76 [ V_37 ] ;
if ( V_4 -> V_35 < V_17 -> V_35 )
goto V_74;
V_69 = F_43 ( V_1 , V_48 , V_54 ,
F_37 ( V_51 ) , V_53 , V_57 ,
V_17 , V_37 ) ;
}
F_54 () ;
return V_69 ;
}
V_74:
V_69 = NULL ;
V_70 = 0 ;
F_55 (sk, node, &hslot->head) {
V_58 = F_38 ( V_7 , V_1 , V_48 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) ;
if ( V_58 > V_70 ) {
V_69 = V_7 ;
V_70 = V_58 ;
V_72 = V_7 -> V_16 ;
if ( V_72 ) {
V_73 = F_40 ( V_1 , V_55 , V_53 ,
V_48 , V_54 ) ;
V_71 = 1 ;
}
} else if ( V_58 == V_70 && V_72 ) {
V_71 ++ ;
if ( F_18 ( V_73 , V_71 ) == 0 )
V_69 = V_7 ;
V_73 = F_45 ( V_73 ) ;
}
}
if ( F_46 ( V_11 ) != V_77 )
goto V_74;
if ( V_69 ) {
if ( F_47 ( ! F_48 ( & V_69 -> V_75 , 2 ) ) )
V_69 = NULL ;
else if ( F_47 ( F_38 ( V_69 , V_1 , V_48 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) < V_70 ) ) {
F_49 ( V_69 ) ;
goto V_74;
}
}
F_54 () ;
return V_69 ;
}
static inline struct V_6 * F_56 ( struct V_78 * V_79 ,
T_5 V_54 , T_5 V_56 ,
struct V_22 * V_23 )
{
const struct V_80 * V_81 = F_57 ( V_79 ) ;
return F_50 ( F_58 ( F_59 ( V_79 ) -> V_82 ) , V_81 -> V_48 , V_54 ,
V_81 -> V_55 , V_56 , F_60 ( V_79 ) ,
V_23 ) ;
}
struct V_6 * F_61 ( struct V_1 * V_1 , T_4 V_48 , T_5 V_54 ,
T_4 V_55 , T_5 V_56 , int V_57 )
{
return F_50 ( V_1 , V_48 , V_54 , V_55 , V_56 , V_57 , & V_22 ) ;
}
static inline bool F_62 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_5 V_83 , T_4 V_84 ,
T_5 V_85 , T_4 V_86 ,
int V_57 , unsigned short V_53 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_13 != V_53 ||
( V_59 -> V_62 && V_59 -> V_62 != V_86 ) ||
( V_59 -> V_63 != V_85 && V_59 -> V_63 ) ||
( V_59 -> V_47 && V_59 -> V_47 != V_84 ) ||
F_32 ( V_7 ) ||
( V_7 -> V_15 && V_7 -> V_15 != V_57 ) )
return false ;
if ( ! F_63 ( V_7 , V_84 , V_86 , V_57 ) )
return false ;
return true ;
}
void F_64 ( struct V_78 * V_79 , T_3 V_87 , struct V_22 * V_23 )
{
struct V_44 * V_59 ;
const struct V_80 * V_81 = ( const struct V_80 * ) V_79 -> V_88 ;
struct V_89 * V_90 = (struct V_89 * ) ( V_79 -> V_88 + ( V_81 -> V_91 << 2 ) ) ;
const int type = F_65 ( V_79 ) -> type ;
const int V_92 = F_65 ( V_79 ) -> V_92 ;
struct V_6 * V_7 ;
int V_93 ;
int V_94 ;
struct V_1 * V_1 = F_58 ( V_79 -> V_82 ) ;
V_7 = F_50 ( V_1 , V_81 -> V_55 , V_90 -> V_95 ,
V_81 -> V_48 , V_90 -> V_96 , V_79 -> V_82 -> V_97 , V_23 ) ;
if ( ! V_7 ) {
F_66 ( V_1 , V_98 ) ;
return;
}
V_94 = 0 ;
V_93 = 0 ;
V_59 = F_26 ( V_7 ) ;
switch ( type ) {
default:
case V_99 :
V_94 = V_100 ;
break;
case V_101 :
goto V_102;
case V_103 :
V_94 = V_104 ;
V_93 = 1 ;
break;
case V_105 :
if ( V_92 == V_106 ) {
F_67 ( V_79 , V_7 , V_87 ) ;
if ( V_59 -> V_107 != V_108 ) {
V_94 = V_109 ;
V_93 = 1 ;
break;
}
goto V_102;
}
V_94 = V_100 ;
if ( V_92 <= V_110 ) {
V_93 = V_111 [ V_92 ] . V_112 ;
V_94 = V_111 [ V_92 ] . V_113 ;
}
break;
case V_114 :
F_68 ( V_79 , V_7 ) ;
goto V_102;
}
if ( ! V_59 -> V_115 ) {
if ( ! V_93 || V_7 -> V_116 != V_117 )
goto V_102;
} else
F_69 ( V_7 , V_79 , V_94 , V_90 -> V_95 , V_87 , ( V_118 * ) ( V_90 + 1 ) ) ;
V_7 -> V_119 = V_94 ;
V_7 -> V_120 ( V_7 ) ;
V_102:
F_49 ( V_7 ) ;
}
void F_70 ( struct V_78 * V_79 , T_3 V_87 )
{
F_64 ( V_79 , V_87 , & V_22 ) ;
}
void F_71 ( struct V_6 * V_7 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
if ( V_122 -> V_123 ) {
V_122 -> V_124 = 0 ;
V_122 -> V_123 = 0 ;
F_72 ( V_7 ) ;
}
}
void F_73 ( struct V_78 * V_79 , T_4 V_125 , T_4 V_126 )
{
struct V_89 * V_90 = F_74 ( V_79 ) ;
int V_127 = F_75 ( V_79 ) ;
int V_124 = V_79 -> V_124 - V_127 ;
int V_128 = V_124 ;
T_7 V_129 = 0 ;
if ( ! F_76 ( V_79 ) ) {
V_79 -> V_130 = F_77 ( V_79 ) - V_79 -> V_42 ;
V_79 -> V_131 = F_78 ( struct V_89 , V_132 ) ;
V_90 -> V_132 = ~ F_79 ( V_125 , V_126 , V_124 ,
V_133 , 0 ) ;
} else {
struct V_78 * V_134 ;
F_80 (skb, frags) {
V_129 = F_81 ( V_129 , V_134 -> V_129 ) ;
V_128 -= V_134 -> V_124 ;
}
V_129 = F_82 ( V_79 , V_127 , V_128 , V_129 ) ;
V_79 -> V_135 = V_136 ;
V_90 -> V_132 = F_79 ( V_125 , V_126 , V_124 , V_133 , V_129 ) ;
if ( V_90 -> V_132 == 0 )
V_90 -> V_132 = V_137 ;
}
}
void F_83 ( bool V_138 , struct V_78 * V_79 ,
T_4 V_48 , T_4 V_55 , int V_124 )
{
struct V_89 * V_90 = F_74 ( V_79 ) ;
if ( V_138 )
V_90 -> V_132 = 0 ;
else if ( F_84 ( V_79 ) )
V_90 -> V_132 = ~ F_85 ( V_124 , V_48 , V_55 , 0 ) ;
else if ( F_59 ( V_79 ) && F_59 ( V_79 ) -> V_82 &&
( F_59 ( V_79 ) -> V_82 -> V_139 & V_140 ) ) {
F_86 ( V_79 -> V_135 == V_141 ) ;
V_79 -> V_135 = V_141 ;
V_79 -> V_130 = F_77 ( V_79 ) - V_79 -> V_42 ;
V_79 -> V_131 = F_78 ( struct V_89 , V_132 ) ;
V_90 -> V_132 = ~ F_85 ( V_124 , V_48 , V_55 , 0 ) ;
} else {
T_7 V_129 ;
F_86 ( V_79 -> V_135 == V_141 ) ;
V_90 -> V_132 = 0 ;
V_129 = F_82 ( V_79 , 0 , V_124 , 0 ) ;
V_90 -> V_132 = F_85 ( V_124 , V_48 , V_55 , V_129 ) ;
if ( V_90 -> V_132 == 0 )
V_90 -> V_132 = V_137 ;
V_79 -> V_135 = V_142 ;
}
}
static int F_87 ( struct V_78 * V_79 , struct V_143 * V_144 )
{
struct V_6 * V_7 = V_79 -> V_7 ;
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_89 * V_90 ;
int V_94 = 0 ;
int V_145 = F_88 ( V_7 ) ;
int V_127 = F_75 ( V_79 ) ;
int V_124 = V_79 -> V_124 - V_127 ;
T_7 V_129 = 0 ;
V_90 = F_74 ( V_79 ) ;
V_90 -> V_96 = V_59 -> V_146 ;
V_90 -> V_95 = V_144 -> V_147 ;
V_90 -> V_124 = F_89 ( V_124 ) ;
V_90 -> V_132 = 0 ;
if ( V_145 )
V_129 = F_90 ( V_79 ) ;
else if ( V_7 -> V_148 ) {
V_79 -> V_135 = V_136 ;
goto V_149;
} else if ( V_79 -> V_135 == V_141 ) {
F_73 ( V_79 , V_144 -> V_48 , V_144 -> V_55 ) ;
goto V_149;
} else
V_129 = F_91 ( V_79 ) ;
V_90 -> V_132 = F_79 ( V_144 -> V_48 , V_144 -> V_55 , V_124 ,
V_7 -> V_150 , V_129 ) ;
if ( V_90 -> V_132 == 0 )
V_90 -> V_132 = V_137 ;
V_149:
V_94 = F_92 ( F_6 ( V_7 ) , V_79 ) ;
if ( V_94 ) {
if ( V_94 == - V_151 && ! V_59 -> V_115 ) {
F_93 ( F_6 ( V_7 ) ,
V_152 , V_145 ) ;
V_94 = 0 ;
}
} else
F_93 ( F_6 ( V_7 ) ,
V_153 , V_145 ) ;
return V_94 ;
}
int F_94 ( struct V_6 * V_7 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_143 * V_144 = & V_59 -> V_154 . V_155 . V_156 . V_157 ;
struct V_78 * V_79 ;
int V_94 = 0 ;
V_79 = F_95 ( V_7 , V_144 ) ;
if ( ! V_79 )
goto V_102;
V_94 = F_87 ( V_79 , V_144 ) ;
V_102:
V_122 -> V_124 = 0 ;
V_122 -> V_123 = 0 ;
return V_94 ;
}
int F_96 ( struct V_6 * V_7 , struct V_158 * V_159 , T_8 V_124 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_121 * V_122 = F_7 ( V_7 ) ;
struct V_143 V_160 ;
struct V_143 * V_144 ;
int V_161 = V_124 ;
struct V_162 V_163 ;
struct V_164 * V_165 = NULL ;
int free = 0 ;
int V_166 = 0 ;
T_4 V_55 , V_66 , V_48 ;
T_5 V_56 ;
V_118 V_167 ;
int V_94 , V_145 = F_88 ( V_7 ) ;
int V_168 = V_122 -> V_169 || V_159 -> V_170 & V_171 ;
int (* F_97)( void * , char * , int , int , int , struct V_78 * );
struct V_78 * V_79 ;
struct V_172 V_173 ;
if ( V_124 > 0xFFFF )
return - V_109 ;
if ( V_159 -> V_170 & V_174 )
return - V_175 ;
V_163 . V_176 = NULL ;
V_163 . V_177 = 0 ;
V_163 . V_178 = 0 ;
V_163 . V_167 = - 1 ;
F_97 = V_145 ? V_179 : V_180 ;
V_144 = & V_59 -> V_154 . V_155 . V_156 . V_157 ;
if ( V_122 -> V_123 ) {
F_98 ( V_7 ) ;
if ( F_99 ( V_122 -> V_123 ) ) {
if ( F_47 ( V_122 -> V_123 != V_181 ) ) {
F_100 ( V_7 ) ;
return - V_182 ;
}
goto V_183;
}
F_100 ( V_7 ) ;
}
V_161 += sizeof( struct V_89 ) ;
if ( V_159 -> V_184 ) {
F_101 ( struct V_185 * , V_186 , V_159 -> V_184 ) ;
if ( V_159 -> V_187 < sizeof( * V_186 ) )
return - V_182 ;
if ( V_186 -> V_188 != V_181 ) {
if ( V_186 -> V_188 != V_189 )
return - V_190 ;
}
V_55 = V_186 -> V_191 . V_192 ;
V_56 = V_186 -> V_193 ;
if ( V_56 == 0 )
return - V_182 ;
} else {
if ( V_7 -> V_116 != V_117 )
return - V_194 ;
V_55 = V_59 -> V_62 ;
V_56 = V_59 -> V_63 ;
V_166 = 1 ;
}
V_163 . V_195 = V_59 -> V_196 ;
V_163 . V_197 = V_7 -> V_15 ;
F_102 ( V_7 , & V_163 . V_177 ) ;
if ( V_159 -> V_198 ) {
V_94 = F_103 ( F_6 ( V_7 ) , V_159 , & V_163 ,
V_7 -> V_60 == V_199 ) ;
if ( V_94 )
return V_94 ;
if ( V_163 . V_176 )
free = 1 ;
V_166 = 0 ;
}
if ( ! V_163 . V_176 ) {
struct V_200 * V_201 ;
F_53 () ;
V_201 = F_104 ( V_59 -> V_201 ) ;
if ( V_201 ) {
memcpy ( & V_173 , V_201 ,
sizeof( * V_201 ) + V_201 -> V_176 . V_202 ) ;
V_163 . V_176 = & V_173 . V_176 ;
}
F_54 () ;
}
V_48 = V_163 . V_195 ;
V_163 . V_195 = V_66 = V_55 ;
if ( V_163 . V_176 && V_163 . V_176 -> V_176 . V_203 ) {
if ( ! V_55 )
return - V_182 ;
V_66 = V_163 . V_176 -> V_176 . V_66 ;
V_166 = 0 ;
}
V_167 = F_105 ( & V_163 , V_59 ) ;
if ( F_106 ( V_7 , V_204 ) ||
( V_159 -> V_170 & V_205 ) ||
( V_163 . V_176 && V_163 . V_176 -> V_176 . V_206 ) ) {
V_167 |= V_207 ;
V_166 = 0 ;
}
if ( F_107 ( V_55 ) ) {
if ( ! V_163 . V_197 )
V_163 . V_197 = V_59 -> V_208 ;
if ( ! V_48 )
V_48 = V_59 -> V_209 ;
V_166 = 0 ;
} else if ( ! V_163 . V_197 )
V_163 . V_197 = V_59 -> V_210 ;
if ( V_166 )
V_165 = (struct V_164 * ) F_108 ( V_7 , 0 ) ;
if ( ! V_165 ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
V_144 = & V_160 ;
F_109 ( V_144 , V_163 . V_197 , V_7 -> V_211 , V_167 ,
V_212 , V_7 -> V_150 ,
F_110 ( V_7 ) ,
V_66 , V_48 , V_56 , V_59 -> V_146 ) ;
F_111 ( V_7 , F_112 ( V_144 ) ) ;
V_165 = F_113 ( V_1 , V_144 , V_7 ) ;
if ( F_114 ( V_165 ) ) {
V_94 = F_115 ( V_165 ) ;
V_165 = NULL ;
if ( V_94 == - V_213 )
F_116 ( V_1 , V_214 ) ;
goto V_102;
}
V_94 = - V_215 ;
if ( ( V_165 -> V_216 & V_217 ) &&
! F_106 ( V_7 , V_218 ) )
goto V_102;
if ( V_166 )
F_117 ( V_7 , F_118 ( & V_165 -> V_126 ) ) ;
}
if ( V_159 -> V_170 & V_219 )
goto V_220;
V_221:
V_48 = V_144 -> V_48 ;
if ( ! V_163 . V_195 )
V_55 = V_163 . V_195 = V_144 -> V_55 ;
if ( ! V_168 ) {
V_79 = F_119 ( V_7 , V_144 , F_97 , V_159 , V_161 ,
sizeof( struct V_89 ) , & V_163 , & V_165 ,
V_159 -> V_170 ) ;
V_94 = F_115 ( V_79 ) ;
if ( ! F_120 ( V_79 ) )
V_94 = F_87 ( V_79 , V_144 ) ;
goto V_102;
}
F_98 ( V_7 ) ;
if ( F_47 ( V_122 -> V_123 ) ) {
F_100 ( V_7 ) ;
F_121 ( L_1 ) ;
V_94 = - V_182 ;
goto V_102;
}
V_144 = & V_59 -> V_154 . V_155 . V_156 . V_157 ;
V_144 -> V_55 = V_55 ;
V_144 -> V_48 = V_48 ;
V_144 -> V_147 = V_56 ;
V_144 -> V_222 = V_59 -> V_146 ;
V_122 -> V_123 = V_181 ;
V_183:
V_122 -> V_124 += V_161 ;
V_94 = F_122 ( V_7 , V_144 , F_97 , V_159 , V_161 ,
sizeof( struct V_89 ) , & V_163 , & V_165 ,
V_168 ? V_159 -> V_170 | V_171 : V_159 -> V_170 ) ;
if ( V_94 )
F_71 ( V_7 ) ;
else if ( ! V_168 )
V_94 = F_94 ( V_7 ) ;
else if ( F_47 ( F_123 ( & V_7 -> V_223 ) ) )
V_122 -> V_123 = 0 ;
F_100 ( V_7 ) ;
V_102:
F_124 ( V_165 ) ;
if ( free )
F_125 ( V_163 . V_176 ) ;
if ( ! V_94 )
return V_124 ;
if ( V_94 == - V_151 || F_22 ( V_224 , & V_7 -> V_225 -> V_226 ) ) {
F_93 ( F_6 ( V_7 ) ,
V_152 , V_145 ) ;
}
return V_94 ;
V_220:
F_126 ( & V_165 -> V_126 ) ;
if ( ! ( V_159 -> V_170 & V_227 ) || V_124 )
goto V_221;
V_94 = 0 ;
goto V_102;
}
int F_127 ( struct V_6 * V_7 , struct V_228 * V_228 , int V_127 ,
T_8 V_229 , int V_226 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_230 ;
if ( V_226 & V_231 )
V_226 |= V_171 ;
if ( ! V_122 -> V_123 ) {
struct V_158 V_159 = { . V_170 = V_226 | V_171 } ;
V_230 = F_96 ( V_7 , & V_159 , 0 ) ;
if ( V_230 < 0 )
return V_230 ;
}
F_98 ( V_7 ) ;
if ( F_47 ( ! V_122 -> V_123 ) ) {
F_100 ( V_7 ) ;
F_121 ( L_2 ) ;
return - V_182 ;
}
V_230 = F_128 ( V_7 , & V_59 -> V_154 . V_155 . V_156 . V_157 ,
V_228 , V_127 , V_229 , V_226 ) ;
if ( V_230 == - V_175 ) {
F_100 ( V_7 ) ;
return F_129 ( V_7 -> V_225 , V_228 , V_127 ,
V_229 , V_226 ) ;
}
if ( V_230 < 0 ) {
F_71 ( V_7 ) ;
goto V_102;
}
V_122 -> V_124 += V_229 ;
if ( ! ( V_122 -> V_169 || ( V_226 & V_171 ) ) )
V_230 = F_94 ( V_7 ) ;
if ( ! V_230 )
V_230 = V_229 ;
V_102:
F_100 ( V_7 ) ;
return V_230 ;
}
static unsigned int F_130 ( struct V_6 * V_7 )
{
struct V_232 V_233 , * V_234 = & V_7 -> V_235 ;
struct V_78 * V_79 ;
unsigned int V_18 ;
F_131 ( & V_233 ) ;
F_21 ( & V_234 -> V_19 ) ;
while ( ( V_79 = F_132 ( V_234 ) ) != NULL &&
F_133 ( V_79 ) ) {
F_134 ( F_6 ( V_7 ) , V_236 ,
F_88 ( V_7 ) ) ;
F_134 ( F_6 ( V_7 ) , V_237 ,
F_88 ( V_7 ) ) ;
F_135 ( & V_7 -> V_238 ) ;
F_136 ( V_79 , V_234 ) ;
F_137 ( & V_233 , V_79 ) ;
}
V_18 = V_79 ? V_79 -> V_124 : 0 ;
F_24 ( & V_234 -> V_19 ) ;
if ( ! F_123 ( & V_233 ) ) {
bool V_239 = F_138 ( V_7 ) ;
F_139 ( & V_233 ) ;
F_140 ( V_7 ) ;
F_141 ( V_7 , V_239 ) ;
}
return V_18 ;
}
int F_142 ( struct V_6 * V_7 , int V_240 , unsigned long V_241 )
{
switch ( V_240 ) {
case V_242 :
{
int V_243 = F_143 ( V_7 ) ;
return F_144 ( V_243 , ( int V_244 * ) V_241 ) ;
}
case V_245 :
{
unsigned int V_243 = F_130 ( V_7 ) ;
if ( V_243 )
V_243 -= sizeof( struct V_89 ) ;
return F_144 ( V_243 , ( int V_244 * ) V_241 ) ;
}
default:
return - V_246 ;
}
return 0 ;
}
int F_145 ( struct V_6 * V_7 , struct V_158 * V_159 , T_8 V_124 , int V_247 ,
int V_226 , int * V_248 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
F_101 ( struct V_185 * , sin , V_159 -> V_184 ) ;
struct V_78 * V_79 ;
unsigned int V_161 , V_249 ;
int V_250 , V_251 = 0 ;
int V_94 ;
int V_145 = F_88 ( V_7 ) ;
bool V_239 ;
if ( V_226 & V_252 )
return F_146 ( V_7 , V_159 , V_124 , V_248 ) ;
V_253:
V_79 = F_147 ( V_7 , V_226 | ( V_247 ? V_254 : 0 ) ,
& V_250 , & V_251 , & V_94 ) ;
if ( ! V_79 )
goto V_102;
V_161 = V_79 -> V_124 - sizeof( struct V_89 ) ;
V_249 = V_124 ;
if ( V_249 > V_161 )
V_249 = V_161 ;
else if ( V_249 < V_161 )
V_159 -> V_170 |= V_255 ;
if ( V_249 < V_161 || F_148 ( V_79 ) -> V_256 ) {
if ( F_133 ( V_79 ) )
goto V_257;
}
if ( F_149 ( V_79 ) )
V_94 = F_150 ( V_79 , sizeof( struct V_89 ) ,
V_159 , V_249 ) ;
else {
V_94 = F_151 ( V_79 , sizeof( struct V_89 ) ,
V_159 ) ;
if ( V_94 == - V_182 )
goto V_257;
}
if ( F_47 ( V_94 ) ) {
F_152 ( V_79 , F_145 ) ;
if ( ! V_250 ) {
F_135 ( & V_7 -> V_238 ) ;
F_93 ( F_6 ( V_7 ) ,
V_237 , V_145 ) ;
}
goto V_258;
}
if ( ! V_250 )
F_93 ( F_6 ( V_7 ) ,
V_259 , V_145 ) ;
F_153 ( V_159 , V_7 , V_79 ) ;
if ( sin ) {
sin -> V_188 = V_181 ;
sin -> V_193 = F_74 ( V_79 ) -> V_96 ;
sin -> V_191 . V_192 = F_57 ( V_79 ) -> V_48 ;
memset ( sin -> V_260 , 0 , sizeof( sin -> V_260 ) ) ;
* V_248 = sizeof( * sin ) ;
}
if ( V_59 -> V_261 )
F_154 ( V_159 , V_79 , sizeof( struct V_89 ) ) ;
V_94 = V_249 ;
if ( V_226 & V_255 )
V_94 = V_161 ;
V_258:
F_155 ( V_7 , V_79 ) ;
V_102:
return V_94 ;
V_257:
V_239 = F_138 ( V_7 ) ;
if ( ! F_156 ( V_7 , V_79 , V_226 ) ) {
F_93 ( F_6 ( V_7 ) , V_236 , V_145 ) ;
F_93 ( F_6 ( V_7 ) , V_237 , V_145 ) ;
}
F_141 ( V_7 , V_239 ) ;
F_157 () ;
V_159 -> V_170 &= ~ V_255 ;
goto V_253;
}
int F_158 ( struct V_6 * V_7 , int V_226 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
V_7 -> V_116 = V_262 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
F_159 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_263 & V_264 ) )
F_160 ( V_7 ) ;
if ( ! ( V_7 -> V_263 & V_265 ) ) {
V_7 -> V_24 -> V_266 ( V_7 ) ;
V_59 -> V_146 = 0 ;
}
F_161 ( V_7 ) ;
return 0 ;
}
void F_162 ( struct V_6 * V_7 )
{
if ( F_163 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
F_21 ( & V_4 -> V_19 ) ;
if ( F_164 ( V_7 ) ) {
V_4 -> V_35 -- ;
F_26 ( V_7 ) -> V_41 = 0 ;
F_29 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_165 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_24 ( & V_4 -> V_19 ) ;
}
}
void F_166 ( struct V_6 * V_7 , T_9 V_267 )
{
if ( F_163 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_268 ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
V_268 = F_25 ( V_23 , V_267 ) ;
F_7 ( V_7 ) -> V_38 = V_267 ;
if ( V_17 != V_268 ) {
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_165 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_268 -> V_19 ) ;
F_30 ( & F_7 ( V_7 ) -> V_43 ,
& V_268 -> V_42 ) ;
V_268 -> V_35 ++ ;
F_13 ( & V_268 -> V_19 ) ;
F_24 ( & V_4 -> V_19 ) ;
}
}
}
static void F_167 ( struct V_6 * V_7 )
{
T_9 V_269 = F_33 ( F_6 ( V_7 ) ,
F_26 ( V_7 ) -> V_47 ,
F_26 ( V_7 ) -> V_41 ) ;
F_166 ( V_7 , V_269 ) ;
}
static int F_168 ( struct V_6 * V_7 , struct V_78 * V_79 )
{
int V_270 ;
if ( F_26 ( V_7 ) -> V_62 ) {
F_169 ( V_7 , V_79 ) ;
F_170 ( V_7 , V_79 ) ;
F_171 ( V_7 ) ;
}
V_270 = F_172 ( V_7 , V_79 ) ;
if ( V_270 < 0 ) {
int V_145 = F_88 ( V_7 ) ;
if ( V_270 == - V_271 )
F_134 ( F_6 ( V_7 ) , V_272 ,
V_145 ) ;
F_134 ( F_6 ( V_7 ) , V_237 , V_145 ) ;
F_173 ( V_79 ) ;
F_174 ( V_270 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_175 ( void )
{
if ( ! F_176 ( & V_273 ) )
F_177 ( & V_273 ) ;
}
int F_178 ( struct V_6 * V_7 , struct V_78 * V_79 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_270 ;
int V_145 = F_88 ( V_7 ) ;
if ( ! F_179 ( V_7 , V_274 , V_79 ) )
goto V_275;
F_180 ( V_79 ) ;
if ( F_181 ( & V_273 ) && V_122 -> V_276 ) {
int (* F_182)( struct V_6 * V_7 , struct V_78 * V_79 );
F_182 = F_183 ( V_122 -> F_182 ) ;
if ( V_79 -> V_124 > sizeof( struct V_89 ) && F_182 ) {
int V_230 ;
if ( F_133 ( V_79 ) )
goto V_277;
V_230 = F_182 ( V_7 , V_79 ) ;
if ( V_230 <= 0 ) {
F_134 ( F_6 ( V_7 ) ,
V_259 ,
V_145 ) ;
return - V_230 ;
}
}
}
if ( ( V_145 & V_278 ) && F_148 ( V_79 ) -> V_256 ) {
if ( V_122 -> V_279 == 0 ) {
F_121 ( L_3 ,
F_148 ( V_79 ) -> V_280 , V_79 -> V_124 ) ;
goto V_275;
}
if ( F_148 ( V_79 ) -> V_280 < V_122 -> V_279 ) {
F_121 ( L_4 ,
F_148 ( V_79 ) -> V_280 , V_122 -> V_279 ) ;
goto V_275;
}
}
if ( F_184 ( V_7 -> V_281 ) &&
F_133 ( V_79 ) )
goto V_277;
if ( F_185 ( V_7 , V_7 -> V_282 ) ) {
F_134 ( F_6 ( V_7 ) , V_272 ,
V_145 ) ;
goto V_275;
}
V_270 = 0 ;
F_186 ( V_7 , V_79 ) ;
F_187 ( V_7 ) ;
if ( ! F_188 ( V_7 ) )
V_270 = F_168 ( V_7 , V_79 ) ;
else if ( F_189 ( V_7 , V_79 , V_7 -> V_282 ) ) {
F_190 ( V_7 ) ;
goto V_275;
}
F_190 ( V_7 ) ;
return V_270 ;
V_277:
F_134 ( F_6 ( V_7 ) , V_236 , V_145 ) ;
V_275:
F_134 ( F_6 ( V_7 ) , V_237 , V_145 ) ;
F_135 ( & V_7 -> V_238 ) ;
F_173 ( V_79 ) ;
return - 1 ;
}
static void F_191 ( struct V_6 * * V_283 , unsigned int V_35 ,
struct V_78 * V_79 , unsigned int V_284 )
{
unsigned int V_285 ;
struct V_78 * V_286 = NULL ;
struct V_6 * V_7 ;
for ( V_285 = 0 ; V_285 < V_35 ; V_285 ++ ) {
V_7 = V_283 [ V_285 ] ;
if ( F_99 ( ! V_286 ) )
V_286 = ( V_285 == V_284 ) ? V_79 : F_192 ( V_79 , V_287 ) ;
if ( ! V_286 ) {
F_135 ( & V_7 -> V_238 ) ;
F_134 ( F_6 ( V_7 ) , V_272 ,
F_88 ( V_7 ) ) ;
F_134 ( F_6 ( V_7 ) , V_237 ,
F_88 ( V_7 ) ) ;
}
if ( V_286 && F_178 ( V_7 , V_286 ) <= 0 )
V_286 = NULL ;
F_49 ( V_7 ) ;
}
if ( F_47 ( V_286 ) )
F_173 ( V_286 ) ;
}
static void F_193 ( struct V_6 * V_7 , struct V_288 * V_126 )
{
struct V_288 * V_289 ;
F_194 ( V_126 ) ;
V_289 = F_195 ( & V_7 -> V_290 , V_126 ) ;
F_196 ( V_289 ) ;
}
static int F_197 ( struct V_1 * V_1 , struct V_78 * V_79 ,
struct V_89 * V_90 ,
T_4 V_48 , T_4 V_55 ,
struct V_22 * V_23 ,
int V_291 )
{
struct V_6 * V_7 , * V_283 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_10 * V_11 ;
unsigned short V_53 = F_51 ( V_90 -> V_95 ) ;
struct V_3 * V_4 = F_19 ( V_23 , V_1 , V_53 ) ;
int V_57 = V_79 -> V_82 -> V_97 ;
unsigned int V_35 = 0 , V_127 = F_78 ( F_198 ( * V_7 ) , V_292 ) ;
unsigned int V_76 = 0 , V_293 = 0 , V_294 = ( V_4 -> V_35 > 10 ) ;
bool V_295 = false ;
if ( V_294 ) {
V_293 = F_33 ( V_1 , F_37 ( V_51 ) , V_53 ) &
V_22 . V_32 ;
V_76 = F_33 ( V_1 , V_55 , V_53 ) & V_22 . V_32 ;
V_296:
V_4 = & V_22 . V_76 [ V_76 ] ;
V_127 = F_78 ( F_198 ( * V_7 ) , V_297 . V_298 ) ;
}
F_11 ( & V_4 -> V_19 ) ;
F_199 (sk, node, &hslot->head, offset) {
if ( F_62 ( V_1 , V_7 ,
V_90 -> V_95 , V_55 ,
V_90 -> V_96 , V_48 ,
V_57 , V_53 ) ) {
if ( F_47 ( V_35 == F_200 ( V_283 ) ) ) {
F_191 ( V_283 , V_35 , V_79 , ~ 0 ) ;
V_295 = true ;
V_35 = 0 ;
}
V_283 [ V_35 ++ ] = V_7 ;
F_201 ( V_7 ) ;
}
}
F_13 ( & V_4 -> V_19 ) ;
if ( V_294 && V_76 != V_293 ) {
V_76 = V_293 ;
goto V_296;
}
if ( V_35 ) {
F_191 ( V_283 , V_35 , V_79 , V_35 - 1 ) ;
} else {
if ( ! V_295 )
F_134 ( V_1 , V_299 ,
V_291 == V_300 ) ;
F_202 ( V_79 ) ;
}
return 0 ;
}
static inline int F_203 ( struct V_78 * V_79 , struct V_89 * V_90 ,
int V_291 )
{
int V_94 ;
F_148 ( V_79 ) -> V_256 = 0 ;
F_148 ( V_79 ) -> V_280 = V_79 -> V_124 ;
if ( V_291 == V_300 ) {
V_94 = F_204 ( V_79 , V_90 ) ;
if ( V_94 )
return V_94 ;
}
return F_205 ( V_79 , V_291 , V_90 -> V_132 ,
V_301 ) ;
}
int F_206 ( struct V_78 * V_79 , struct V_22 * V_23 ,
int V_291 )
{
struct V_6 * V_7 ;
struct V_89 * V_90 ;
unsigned short V_161 ;
struct V_164 * V_165 = F_207 ( V_79 ) ;
T_4 V_48 , V_55 ;
struct V_1 * V_1 = F_58 ( V_79 -> V_82 ) ;
if ( ! F_208 ( V_79 , sizeof( struct V_89 ) ) )
goto V_275;
V_90 = F_74 ( V_79 ) ;
V_161 = F_51 ( V_90 -> V_124 ) ;
V_48 = F_57 ( V_79 ) -> V_48 ;
V_55 = F_57 ( V_79 ) -> V_55 ;
if ( V_161 > V_79 -> V_124 )
goto V_302;
if ( V_291 == V_133 ) {
if ( V_161 < sizeof( * V_90 ) || F_209 ( V_79 , V_161 ) )
goto V_302;
V_90 = F_74 ( V_79 ) ;
}
if ( F_203 ( V_79 , V_90 , V_291 ) )
goto V_277;
V_7 = F_210 ( V_79 ) ;
if ( V_7 ) {
struct V_288 * V_126 = F_59 ( V_79 ) ;
int V_230 ;
if ( F_47 ( V_7 -> V_290 != V_126 ) )
F_193 ( V_7 , V_126 ) ;
V_230 = F_178 ( V_7 , V_79 ) ;
F_49 ( V_7 ) ;
if ( V_230 > 0 )
return - V_230 ;
return 0 ;
}
if ( V_165 -> V_216 & ( V_217 | V_303 ) )
return F_197 ( V_1 , V_79 , V_90 ,
V_48 , V_55 , V_23 , V_291 ) ;
V_7 = F_56 ( V_79 , V_90 -> V_96 , V_90 -> V_95 , V_23 ) ;
if ( V_7 ) {
int V_230 ;
if ( F_211 ( V_7 ) && V_90 -> V_132 && ! F_88 ( V_7 ) )
F_212 ( V_79 , V_133 , V_90 -> V_132 ,
V_301 ) ;
V_230 = F_178 ( V_7 , V_79 ) ;
F_49 ( V_7 ) ;
if ( V_230 > 0 )
return - V_230 ;
return 0 ;
}
if ( ! F_179 ( NULL , V_274 , V_79 ) )
goto V_275;
F_180 ( V_79 ) ;
if ( F_133 ( V_79 ) )
goto V_277;
F_134 ( V_1 , V_304 , V_291 == V_300 ) ;
F_213 ( V_79 , V_105 , V_305 , 0 ) ;
F_173 ( V_79 ) ;
return 0 ;
V_302:
F_121 ( L_5 ,
V_291 == V_300 ? L_6 : L_7 ,
& V_48 , F_51 ( V_90 -> V_96 ) ,
V_161 , V_79 -> V_124 ,
& V_55 , F_51 ( V_90 -> V_95 ) ) ;
goto V_275;
V_277:
F_121 ( L_8 ,
V_291 == V_300 ? L_6 : L_7 ,
& V_48 , F_51 ( V_90 -> V_96 ) , & V_55 , F_51 ( V_90 -> V_95 ) ,
V_161 ) ;
F_134 ( V_1 , V_236 , V_291 == V_300 ) ;
V_275:
F_134 ( V_1 , V_237 , V_291 == V_300 ) ;
F_173 ( V_79 ) ;
return 0 ;
}
static struct V_6 * F_214 ( struct V_1 * V_1 ,
T_5 V_83 , T_4 V_84 ,
T_5 V_85 , T_4 V_86 ,
int V_57 )
{
struct V_6 * V_7 , * V_69 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_51 ( V_83 ) ;
unsigned int V_35 , V_77 = F_52 ( V_1 , V_53 , V_22 . V_32 ) ;
struct V_3 * V_4 = & V_22 . V_73 [ V_77 ] ;
if ( V_4 -> V_35 > 10 )
return NULL ;
F_53 () ;
V_74:
V_35 = 0 ;
V_69 = NULL ;
F_55 (sk, node, &hslot->head) {
if ( F_62 ( V_1 , V_7 ,
V_83 , V_84 ,
V_85 , V_86 ,
V_57 , V_53 ) ) {
V_69 = V_7 ;
++ V_35 ;
}
}
if ( F_46 ( V_11 ) != V_77 )
goto V_74;
if ( V_69 ) {
if ( V_35 != 1 ||
F_47 ( ! F_48 ( & V_69 -> V_75 , 2 ) ) )
V_69 = NULL ;
else if ( F_47 ( ! F_62 ( V_1 , V_69 ,
V_83 , V_84 ,
V_85 , V_86 ,
V_57 , V_53 ) ) ) {
F_49 ( V_69 ) ;
V_69 = NULL ;
}
}
F_54 () ;
return V_69 ;
}
static struct V_6 * F_215 ( struct V_1 * V_1 ,
T_5 V_83 , T_4 V_84 ,
T_5 V_85 , T_4 V_86 ,
int V_57 )
{
struct V_6 * V_7 , * V_69 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_51 ( V_83 ) ;
unsigned int V_76 = F_33 ( V_1 , V_84 , V_53 ) ;
unsigned int V_37 = V_76 & V_22 . V_32 ;
struct V_3 * V_17 = & V_22 . V_76 [ V_37 ] ;
F_216 ( V_306 , V_86 , V_84 ) ;
const T_10 V_307 = F_217 ( V_85 , V_53 ) ;
F_53 () ;
V_69 = NULL ;
F_44 (sk, node, &hslot2->head) {
if ( F_218 ( V_7 , V_1 , V_306 ,
V_86 , V_84 , V_307 , V_57 ) )
V_69 = V_7 ;
break;
}
if ( V_69 ) {
if ( F_47 ( ! F_48 ( & V_69 -> V_75 , 2 ) ) )
V_69 = NULL ;
else if ( F_47 ( ! F_218 ( V_7 , V_1 , V_306 ,
V_86 , V_84 ,
V_307 , V_57 ) ) ) {
F_49 ( V_69 ) ;
V_69 = NULL ;
}
}
F_54 () ;
return V_69 ;
}
void F_219 ( struct V_78 * V_79 )
{
struct V_1 * V_1 = F_58 ( V_79 -> V_82 ) ;
const struct V_80 * V_81 ;
const struct V_89 * V_90 ;
struct V_6 * V_7 ;
struct V_288 * V_126 ;
int V_57 = V_79 -> V_82 -> V_97 ;
int V_308 ;
if ( ! F_208 ( V_79 , F_75 ( V_79 ) + sizeof( struct V_89 ) ) )
return;
V_81 = F_57 ( V_79 ) ;
V_90 = F_74 ( V_79 ) ;
if ( V_79 -> V_309 == V_310 ||
V_79 -> V_309 == V_311 ) {
struct V_312 * V_313 = F_220 ( V_79 -> V_82 ) ;
if ( ! V_313 )
return;
V_308 = F_221 ( V_313 , V_81 -> V_55 , V_81 -> V_48 ,
V_81 -> V_314 ) ;
if ( ! V_308 )
return;
V_7 = F_214 ( V_1 , V_90 -> V_95 , V_81 -> V_55 ,
V_90 -> V_96 , V_81 -> V_48 , V_57 ) ;
} else if ( V_79 -> V_309 == V_315 ) {
V_7 = F_215 ( V_1 , V_90 -> V_95 , V_81 -> V_55 ,
V_90 -> V_96 , V_81 -> V_48 , V_57 ) ;
} else {
return;
}
if ( ! V_7 )
return;
V_79 -> V_7 = V_7 ;
V_79 -> V_316 = V_317 ;
V_126 = V_7 -> V_290 ;
if ( V_126 )
V_126 = F_222 ( V_126 , 0 ) ;
if ( V_126 )
F_223 ( V_79 , V_126 ) ;
}
int F_224 ( struct V_78 * V_79 )
{
return F_206 ( V_79 , & V_22 , V_133 ) ;
}
void F_225 ( struct V_6 * V_7 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
bool V_239 = F_138 ( V_7 ) ;
F_71 ( V_7 ) ;
F_141 ( V_7 , V_239 ) ;
if ( F_181 ( & V_273 ) && V_122 -> V_276 ) {
void (* F_226)( struct V_6 * V_7 );
F_226 = F_183 ( V_122 -> F_226 ) ;
if ( F_226 )
F_226 ( V_7 ) ;
}
}
int F_227 ( struct V_6 * V_7 , int V_318 , int V_319 ,
char V_244 * V_320 , unsigned int V_202 ,
int (* F_228)( struct V_6 * ) )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_321 , V_322 ;
int V_94 = 0 ;
int V_145 = F_88 ( V_7 ) ;
if ( V_202 < sizeof( int ) )
return - V_182 ;
if ( F_229 ( V_321 , ( int V_244 * ) V_320 ) )
return - V_323 ;
V_322 = V_321 ? 1 : 0 ;
switch ( V_319 ) {
case V_324 :
if ( V_321 != 0 ) {
V_122 -> V_169 = 1 ;
} else {
V_122 -> V_169 = 0 ;
F_98 ( V_7 ) ;
F_228 ( V_7 ) ;
F_100 ( V_7 ) ;
}
break;
case V_325 :
switch ( V_321 ) {
case 0 :
case V_326 :
case V_327 :
V_122 -> F_182 = V_328 ;
case V_329 :
V_122 -> V_276 = V_321 ;
F_175 () ;
break;
default:
V_94 = - V_330 ;
break;
}
break;
case V_331 :
V_122 -> V_332 = V_322 ;
break;
case V_333 :
V_122 -> V_334 = V_322 ;
break;
case V_335 :
if ( ! V_145 )
return - V_330 ;
if ( V_321 != 0 && V_321 < 8 )
V_321 = 8 ;
else if ( V_321 > V_336 )
V_321 = V_336 ;
V_122 -> V_337 = V_321 ;
V_122 -> V_338 |= V_339 ;
break;
case V_340 :
if ( ! V_145 )
return - V_330 ;
if ( V_321 != 0 && V_321 < 8 )
V_321 = 8 ;
else if ( V_321 > V_336 )
V_321 = V_336 ;
V_122 -> V_279 = V_321 ;
V_122 -> V_338 |= V_278 ;
break;
default:
V_94 = - V_330 ;
break;
}
return V_94 ;
}
int F_230 ( struct V_6 * V_7 , int V_318 , int V_319 ,
char V_244 * V_320 , unsigned int V_202 )
{
if ( V_318 == V_341 || V_318 == V_342 )
return F_227 ( V_7 , V_318 , V_319 , V_320 , V_202 ,
F_94 ) ;
return F_231 ( V_7 , V_318 , V_319 , V_320 , V_202 ) ;
}
int F_232 ( struct V_6 * V_7 , int V_318 , int V_319 ,
char V_244 * V_320 , unsigned int V_202 )
{
if ( V_318 == V_341 || V_318 == V_342 )
return F_227 ( V_7 , V_318 , V_319 , V_320 , V_202 ,
F_94 ) ;
return F_233 ( V_7 , V_318 , V_319 , V_320 , V_202 ) ;
}
int F_234 ( struct V_6 * V_7 , int V_318 , int V_319 ,
char V_244 * V_320 , int V_244 * V_202 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_321 , V_124 ;
if ( F_229 ( V_124 , V_202 ) )
return - V_323 ;
V_124 = F_235 (unsigned int, len, sizeof(int)) ;
if ( V_124 < 0 )
return - V_182 ;
switch ( V_319 ) {
case V_324 :
V_321 = V_122 -> V_169 ;
break;
case V_325 :
V_321 = V_122 -> V_276 ;
break;
case V_331 :
V_321 = V_122 -> V_332 ;
break;
case V_333 :
V_321 = V_122 -> V_334 ;
break;
case V_335 :
V_321 = V_122 -> V_337 ;
break;
case V_340 :
V_321 = V_122 -> V_279 ;
break;
default:
return - V_330 ;
}
if ( F_144 ( V_124 , V_202 ) )
return - V_323 ;
if ( F_236 ( V_320 , & V_321 , V_124 ) )
return - V_323 ;
return 0 ;
}
int F_237 ( struct V_6 * V_7 , int V_318 , int V_319 ,
char V_244 * V_320 , int V_244 * V_202 )
{
if ( V_318 == V_341 || V_318 == V_342 )
return F_234 ( V_7 , V_318 , V_319 , V_320 , V_202 ) ;
return F_238 ( V_7 , V_318 , V_319 , V_320 , V_202 ) ;
}
int F_239 ( struct V_6 * V_7 , int V_318 , int V_319 ,
char V_244 * V_320 , int V_244 * V_202 )
{
if ( V_318 == V_341 || V_318 == V_342 )
return F_234 ( V_7 , V_318 , V_319 , V_320 , V_202 ) ;
return F_240 ( V_7 , V_318 , V_319 , V_320 , V_202 ) ;
}
unsigned int F_241 ( struct V_343 * V_343 , struct V_344 * V_6 , T_11 * V_345 )
{
unsigned int V_32 = F_242 ( V_343 , V_6 , V_345 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_243 ( V_7 ) ;
if ( ( V_32 & V_346 ) && ! ( V_343 -> V_347 & V_348 ) &&
! ( V_7 -> V_349 & V_350 ) && ! F_130 ( V_7 ) )
V_32 &= ~ ( V_351 | V_346 ) ;
return V_32 ;
}
static struct V_6 * F_244 ( struct V_352 * V_353 , int V_354 )
{
struct V_6 * V_7 ;
struct V_355 * V_356 = V_353 -> V_357 ;
struct V_1 * V_1 = F_245 ( V_353 ) ;
for ( V_356 -> V_358 = V_354 ; V_356 -> V_358 <= V_356 -> V_22 -> V_32 ;
++ V_356 -> V_358 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_356 -> V_22 -> V_73 [ V_356 -> V_358 ] ;
if ( F_246 ( & V_4 -> V_42 ) )
continue;
F_21 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_60 == V_356 -> V_359 )
goto V_33;
}
F_24 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_33:
return V_7 ;
}
static struct V_6 * F_247 ( struct V_352 * V_353 , struct V_6 * V_7 )
{
struct V_355 * V_356 = V_353 -> V_357 ;
struct V_1 * V_1 = F_245 ( V_353 ) ;
do {
V_7 = F_248 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_60 != V_356 -> V_359 ) );
if ( ! V_7 ) {
if ( V_356 -> V_358 <= V_356 -> V_22 -> V_32 )
F_24 ( & V_356 -> V_22 -> V_73 [ V_356 -> V_358 ] . V_19 ) ;
return F_244 ( V_353 , V_356 -> V_358 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_249 ( struct V_352 * V_353 , T_12 V_360 )
{
struct V_6 * V_7 = F_244 ( V_353 , 0 ) ;
if ( V_7 )
while ( V_360 && ( V_7 = F_247 ( V_353 , V_7 ) ) != NULL )
-- V_360 ;
return V_360 ? NULL : V_7 ;
}
static void * F_250 ( struct V_352 * V_353 , T_12 * V_360 )
{
struct V_355 * V_356 = V_353 -> V_357 ;
V_356 -> V_358 = V_361 ;
return * V_360 ? F_249 ( V_353 , * V_360 - 1 ) : V_362 ;
}
static void * F_251 ( struct V_352 * V_353 , void * V_363 , T_12 * V_360 )
{
struct V_6 * V_7 ;
if ( V_363 == V_362 )
V_7 = F_249 ( V_353 , 0 ) ;
else
V_7 = F_247 ( V_353 , V_363 ) ;
++ * V_360 ;
return V_7 ;
}
static void F_252 ( struct V_352 * V_353 , void * V_363 )
{
struct V_355 * V_356 = V_353 -> V_357 ;
if ( V_356 -> V_358 <= V_356 -> V_22 -> V_32 )
F_24 ( & V_356 -> V_22 -> V_73 [ V_356 -> V_358 ] . V_19 ) ;
}
int F_253 ( struct V_364 * V_364 , struct V_343 * V_343 )
{
struct V_365 * V_366 = F_254 ( V_364 ) ;
struct V_355 * V_367 ;
int V_94 ;
V_94 = F_255 ( V_364 , V_343 , & V_366 -> V_368 ,
sizeof( struct V_355 ) ) ;
if ( V_94 < 0 )
return V_94 ;
V_367 = ( (struct V_352 * ) V_343 -> V_369 ) -> V_357 ;
V_367 -> V_359 = V_366 -> V_359 ;
V_367 -> V_22 = V_366 -> V_22 ;
return V_94 ;
}
int F_256 ( struct V_1 * V_1 , struct V_365 * V_366 )
{
struct V_370 * V_371 ;
int V_270 = 0 ;
V_366 -> V_368 . V_354 = F_250 ;
V_366 -> V_368 . V_372 = F_251 ;
V_366 -> V_368 . V_373 = F_252 ;
V_371 = F_257 ( V_366 -> V_374 , V_375 , V_1 -> V_376 ,
V_366 -> V_377 , V_366 ) ;
if ( ! V_371 )
V_270 = - V_271 ;
return V_270 ;
}
void F_258 ( struct V_1 * V_1 , struct V_365 * V_366 )
{
F_259 ( V_366 -> V_374 , V_1 -> V_376 ) ;
}
static void F_260 ( struct V_6 * V_378 , struct V_352 * V_379 ,
int V_358 )
{
struct V_44 * V_59 = F_26 ( V_378 ) ;
T_4 V_95 = V_59 -> V_62 ;
T_4 V_125 = V_59 -> V_47 ;
T_1 V_380 = F_51 ( V_59 -> V_63 ) ;
T_1 V_381 = F_51 ( V_59 -> V_146 ) ;
F_261 ( V_379 , L_9
L_10 ,
V_358 , V_125 , V_381 , V_95 , V_380 , V_378 -> V_116 ,
F_143 ( V_378 ) ,
F_262 ( V_378 ) ,
0 , 0L , 0 ,
F_263 ( F_264 ( V_379 ) , F_3 ( V_378 ) ) ,
0 , F_265 ( V_378 ) ,
F_266 ( & V_378 -> V_75 ) , V_378 ,
F_266 ( & V_378 -> V_238 ) ) ;
}
int F_267 ( struct V_352 * V_353 , void * V_363 )
{
F_268 ( V_353 , 127 ) ;
if ( V_363 == V_362 )
F_269 ( V_353 , L_11
L_12
L_13 ) ;
else {
struct V_355 * V_356 = V_353 -> V_357 ;
F_260 ( V_363 , V_353 , V_356 -> V_358 ) ;
}
F_270 ( V_353 , '\n' ) ;
return 0 ;
}
static int T_13 F_271 ( struct V_1 * V_1 )
{
return F_256 ( V_1 , & V_382 ) ;
}
static void T_14 F_272 ( struct V_1 * V_1 )
{
F_258 ( V_1 , & V_382 ) ;
}
int T_15 F_273 ( void )
{
return F_274 ( & V_383 ) ;
}
void F_275 ( void )
{
F_276 ( & V_383 ) ;
}
static int T_15 F_277 ( char * V_384 )
{
T_16 V_230 ;
if ( ! V_384 )
return 0 ;
V_230 = F_278 ( V_384 , 0 , & V_385 ) ;
if ( V_230 )
return 0 ;
if ( V_385 && V_385 < V_386 )
V_385 = V_386 ;
return 1 ;
}
void T_15 F_279 ( struct V_22 * V_387 , const char * V_374 )
{
unsigned int V_285 ;
V_387 -> V_73 = F_280 ( V_374 ,
2 * sizeof( struct V_3 ) ,
V_385 ,
21 ,
0 ,
& V_387 -> log ,
& V_387 -> V_32 ,
V_386 ,
64 * 1024 ) ;
V_387 -> V_76 = V_387 -> V_73 + ( V_387 -> V_32 + 1 ) ;
for ( V_285 = 0 ; V_285 <= V_387 -> V_32 ; V_285 ++ ) {
F_281 ( & V_387 -> V_73 [ V_285 ] . V_42 , V_285 ) ;
V_387 -> V_73 [ V_285 ] . V_35 = 0 ;
F_282 ( & V_387 -> V_73 [ V_285 ] . V_19 ) ;
}
for ( V_285 = 0 ; V_285 <= V_387 -> V_32 ; V_285 ++ ) {
F_281 ( & V_387 -> V_76 [ V_285 ] . V_42 , V_285 ) ;
V_387 -> V_76 [ V_285 ] . V_35 = 0 ;
F_282 ( & V_387 -> V_76 [ V_285 ] . V_19 ) ;
}
}
T_3 F_283 ( void )
{
static T_3 T_17 V_68 ;
F_41 ( & T_17 , sizeof( T_17 ) ) ;
return T_17 ;
}
void T_15 F_284 ( void )
{
unsigned long V_388 ;
F_279 ( & V_22 , L_14 ) ;
V_388 = F_285 () / 8 ;
V_388 = F_286 ( V_388 , 128UL ) ;
V_389 [ 0 ] = V_388 / 4 * 3 ;
V_389 [ 1 ] = V_388 ;
V_389 [ 2 ] = V_389 [ 0 ] * 2 ;
V_390 = V_391 ;
V_392 = V_391 ;
}
