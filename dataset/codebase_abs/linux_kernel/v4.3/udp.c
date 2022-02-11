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
T_9 V_211 = F_109 ( V_7 ) ;
V_144 = & V_160 ;
if ( F_110 ( V_1 , V_163 . V_197 ) ) {
F_111 ( V_144 , V_163 . V_197 , V_7 -> V_212 , V_167 ,
V_213 , V_7 -> V_150 ,
( V_211 | V_214 |
V_215 ) ,
V_66 , V_48 , V_56 ,
V_59 -> V_146 ) ;
V_165 = F_112 ( V_1 , V_144 , V_7 ) ;
if ( ! F_113 ( V_165 ) ) {
V_48 = V_144 -> V_48 ;
F_114 ( V_165 ) ;
}
}
F_111 ( V_144 , V_163 . V_197 , V_7 -> V_212 , V_167 ,
V_213 , V_7 -> V_150 ,
V_211 ,
V_66 , V_48 , V_56 , V_59 -> V_146 ) ;
F_115 ( V_7 , F_116 ( V_144 ) ) ;
V_165 = F_112 ( V_1 , V_144 , V_7 ) ;
if ( F_113 ( V_165 ) ) {
V_94 = F_117 ( V_165 ) ;
V_165 = NULL ;
if ( V_94 == - V_216 )
F_118 ( V_1 , V_217 ) ;
goto V_102;
}
V_94 = - V_218 ;
if ( ( V_165 -> V_219 & V_220 ) &&
! F_106 ( V_7 , V_221 ) )
goto V_102;
if ( V_166 )
F_119 ( V_7 , F_120 ( & V_165 -> V_126 ) ) ;
}
if ( V_159 -> V_170 & V_222 )
goto V_223;
V_224:
V_48 = V_144 -> V_48 ;
if ( ! V_163 . V_195 )
V_55 = V_163 . V_195 = V_144 -> V_55 ;
if ( ! V_168 ) {
V_79 = F_121 ( V_7 , V_144 , F_97 , V_159 , V_161 ,
sizeof( struct V_89 ) , & V_163 , & V_165 ,
V_159 -> V_170 ) ;
V_94 = F_117 ( V_79 ) ;
if ( ! F_122 ( V_79 ) )
V_94 = F_87 ( V_79 , V_144 ) ;
goto V_102;
}
F_98 ( V_7 ) ;
if ( F_47 ( V_122 -> V_123 ) ) {
F_100 ( V_7 ) ;
F_123 ( L_1 ) ;
V_94 = - V_182 ;
goto V_102;
}
V_144 = & V_59 -> V_154 . V_155 . V_156 . V_157 ;
V_144 -> V_55 = V_55 ;
V_144 -> V_48 = V_48 ;
V_144 -> V_147 = V_56 ;
V_144 -> V_225 = V_59 -> V_146 ;
V_122 -> V_123 = V_181 ;
V_183:
V_122 -> V_124 += V_161 ;
V_94 = F_124 ( V_7 , V_144 , F_97 , V_159 , V_161 ,
sizeof( struct V_89 ) , & V_163 , & V_165 ,
V_168 ? V_159 -> V_170 | V_171 : V_159 -> V_170 ) ;
if ( V_94 )
F_71 ( V_7 ) ;
else if ( ! V_168 )
V_94 = F_94 ( V_7 ) ;
else if ( F_47 ( F_125 ( & V_7 -> V_226 ) ) )
V_122 -> V_123 = 0 ;
F_100 ( V_7 ) ;
V_102:
F_114 ( V_165 ) ;
if ( free )
F_126 ( V_163 . V_176 ) ;
if ( ! V_94 )
return V_124 ;
if ( V_94 == - V_151 || F_22 ( V_227 , & V_7 -> V_228 -> V_229 ) ) {
F_93 ( F_6 ( V_7 ) ,
V_152 , V_145 ) ;
}
return V_94 ;
V_223:
F_127 ( & V_165 -> V_126 ) ;
if ( ! ( V_159 -> V_170 & V_230 ) || V_124 )
goto V_224;
V_94 = 0 ;
goto V_102;
}
int F_128 ( struct V_6 * V_7 , struct V_231 * V_231 , int V_127 ,
T_8 V_232 , int V_229 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_233 ;
if ( V_229 & V_234 )
V_229 |= V_171 ;
if ( ! V_122 -> V_123 ) {
struct V_158 V_159 = { . V_170 = V_229 | V_171 } ;
V_233 = F_96 ( V_7 , & V_159 , 0 ) ;
if ( V_233 < 0 )
return V_233 ;
}
F_98 ( V_7 ) ;
if ( F_47 ( ! V_122 -> V_123 ) ) {
F_100 ( V_7 ) ;
F_123 ( L_2 ) ;
return - V_182 ;
}
V_233 = F_129 ( V_7 , & V_59 -> V_154 . V_155 . V_156 . V_157 ,
V_231 , V_127 , V_232 , V_229 ) ;
if ( V_233 == - V_175 ) {
F_100 ( V_7 ) ;
return F_130 ( V_7 -> V_228 , V_231 , V_127 ,
V_232 , V_229 ) ;
}
if ( V_233 < 0 ) {
F_71 ( V_7 ) ;
goto V_102;
}
V_122 -> V_124 += V_232 ;
if ( ! ( V_122 -> V_169 || ( V_229 & V_171 ) ) )
V_233 = F_94 ( V_7 ) ;
if ( ! V_233 )
V_233 = V_232 ;
V_102:
F_100 ( V_7 ) ;
return V_233 ;
}
static unsigned int F_131 ( struct V_6 * V_7 )
{
struct V_235 V_236 , * V_237 = & V_7 -> V_238 ;
struct V_78 * V_79 ;
unsigned int V_18 ;
F_132 ( & V_236 ) ;
F_21 ( & V_237 -> V_19 ) ;
while ( ( V_79 = F_133 ( V_237 ) ) != NULL &&
F_134 ( V_79 ) ) {
F_135 ( F_6 ( V_7 ) , V_239 ,
F_88 ( V_7 ) ) ;
F_135 ( F_6 ( V_7 ) , V_240 ,
F_88 ( V_7 ) ) ;
F_136 ( & V_7 -> V_241 ) ;
F_137 ( V_79 , V_237 ) ;
F_138 ( & V_236 , V_79 ) ;
}
V_18 = V_79 ? V_79 -> V_124 : 0 ;
F_24 ( & V_237 -> V_19 ) ;
if ( ! F_125 ( & V_236 ) ) {
bool V_242 = F_139 ( V_7 ) ;
F_140 ( & V_236 ) ;
F_141 ( V_7 ) ;
F_142 ( V_7 , V_242 ) ;
}
return V_18 ;
}
int F_143 ( struct V_6 * V_7 , int V_243 , unsigned long V_244 )
{
switch ( V_243 ) {
case V_245 :
{
int V_246 = F_144 ( V_7 ) ;
return F_145 ( V_246 , ( int V_247 * ) V_244 ) ;
}
case V_248 :
{
unsigned int V_246 = F_131 ( V_7 ) ;
if ( V_246 )
V_246 -= sizeof( struct V_89 ) ;
return F_145 ( V_246 , ( int V_247 * ) V_244 ) ;
}
default:
return - V_249 ;
}
return 0 ;
}
int F_146 ( struct V_6 * V_7 , struct V_158 * V_159 , T_8 V_124 , int V_250 ,
int V_229 , int * V_251 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
F_101 ( struct V_185 * , sin , V_159 -> V_184 ) ;
struct V_78 * V_79 ;
unsigned int V_161 , V_252 ;
int V_253 , V_254 = 0 ;
int V_94 ;
int V_145 = F_88 ( V_7 ) ;
bool V_242 ;
if ( V_229 & V_255 )
return F_147 ( V_7 , V_159 , V_124 , V_251 ) ;
V_256:
V_79 = F_148 ( V_7 , V_229 | ( V_250 ? V_257 : 0 ) ,
& V_253 , & V_254 , & V_94 ) ;
if ( ! V_79 )
goto V_102;
V_161 = V_79 -> V_124 - sizeof( struct V_89 ) ;
V_252 = V_124 ;
if ( V_252 > V_161 )
V_252 = V_161 ;
else if ( V_252 < V_161 )
V_159 -> V_170 |= V_258 ;
if ( V_252 < V_161 || F_149 ( V_79 ) -> V_259 ) {
if ( F_134 ( V_79 ) )
goto V_260;
}
if ( F_150 ( V_79 ) )
V_94 = F_151 ( V_79 , sizeof( struct V_89 ) ,
V_159 , V_252 ) ;
else {
V_94 = F_152 ( V_79 , sizeof( struct V_89 ) ,
V_159 ) ;
if ( V_94 == - V_182 )
goto V_260;
}
if ( F_47 ( V_94 ) ) {
F_153 ( V_79 , F_146 ) ;
if ( ! V_253 ) {
F_136 ( & V_7 -> V_241 ) ;
F_93 ( F_6 ( V_7 ) ,
V_240 , V_145 ) ;
}
goto V_261;
}
if ( ! V_253 )
F_93 ( F_6 ( V_7 ) ,
V_262 , V_145 ) ;
F_154 ( V_159 , V_7 , V_79 ) ;
if ( sin ) {
sin -> V_188 = V_181 ;
sin -> V_193 = F_74 ( V_79 ) -> V_96 ;
sin -> V_191 . V_192 = F_57 ( V_79 ) -> V_48 ;
memset ( sin -> V_263 , 0 , sizeof( sin -> V_263 ) ) ;
* V_251 = sizeof( * sin ) ;
}
if ( V_59 -> V_264 )
F_155 ( V_159 , V_79 , sizeof( struct V_89 ) ) ;
V_94 = V_252 ;
if ( V_229 & V_258 )
V_94 = V_161 ;
V_261:
F_156 ( V_7 , V_79 ) ;
V_102:
return V_94 ;
V_260:
V_242 = F_139 ( V_7 ) ;
if ( ! F_157 ( V_7 , V_79 , V_229 ) ) {
F_93 ( F_6 ( V_7 ) , V_239 , V_145 ) ;
F_93 ( F_6 ( V_7 ) , V_240 , V_145 ) ;
}
F_142 ( V_7 , V_242 ) ;
F_158 () ;
V_159 -> V_170 &= ~ V_258 ;
goto V_256;
}
int F_159 ( struct V_6 * V_7 , int V_229 )
{
struct V_44 * V_59 = F_26 ( V_7 ) ;
V_7 -> V_116 = V_265 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
F_160 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_266 & V_267 ) )
F_161 ( V_7 ) ;
if ( ! ( V_7 -> V_266 & V_268 ) ) {
V_7 -> V_24 -> V_269 ( V_7 ) ;
V_59 -> V_146 = 0 ;
}
F_162 ( V_7 ) ;
return 0 ;
}
void F_163 ( struct V_6 * V_7 )
{
if ( F_164 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
F_21 ( & V_4 -> V_19 ) ;
if ( F_165 ( V_7 ) ) {
V_4 -> V_35 -- ;
F_26 ( V_7 ) -> V_41 = 0 ;
F_29 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_166 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_24 ( & V_4 -> V_19 ) ;
}
}
void F_167 ( struct V_6 * V_7 , T_10 V_270 )
{
if ( F_164 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_271 ;
V_17 = F_25 ( V_23 , F_7 ( V_7 ) -> V_38 ) ;
V_271 = F_25 ( V_23 , V_270 ) ;
F_7 ( V_7 ) -> V_38 = V_270 ;
if ( V_17 != V_271 ) {
V_4 = F_19 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_166 ( & F_7 ( V_7 ) -> V_43 ) ;
V_17 -> V_35 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_271 -> V_19 ) ;
F_30 ( & F_7 ( V_7 ) -> V_43 ,
& V_271 -> V_42 ) ;
V_271 -> V_35 ++ ;
F_13 ( & V_271 -> V_19 ) ;
F_24 ( & V_4 -> V_19 ) ;
}
}
}
static void F_168 ( struct V_6 * V_7 )
{
T_10 V_272 = F_33 ( F_6 ( V_7 ) ,
F_26 ( V_7 ) -> V_47 ,
F_26 ( V_7 ) -> V_41 ) ;
F_167 ( V_7 , V_272 ) ;
}
static int F_169 ( struct V_6 * V_7 , struct V_78 * V_79 )
{
int V_273 ;
if ( F_26 ( V_7 ) -> V_62 ) {
F_170 ( V_7 , V_79 ) ;
F_171 ( V_7 , V_79 ) ;
F_172 ( V_7 ) ;
}
V_273 = F_173 ( V_7 , V_79 ) ;
if ( V_273 < 0 ) {
int V_145 = F_88 ( V_7 ) ;
if ( V_273 == - V_274 )
F_135 ( F_6 ( V_7 ) , V_275 ,
V_145 ) ;
F_135 ( F_6 ( V_7 ) , V_240 , V_145 ) ;
F_174 ( V_79 ) ;
F_175 ( V_273 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_176 ( void )
{
if ( ! F_177 ( & V_276 ) )
F_178 ( & V_276 ) ;
}
int F_179 ( struct V_6 * V_7 , struct V_78 * V_79 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_273 ;
int V_145 = F_88 ( V_7 ) ;
if ( ! F_180 ( V_7 , V_277 , V_79 ) )
goto V_278;
F_181 ( V_79 ) ;
if ( F_182 ( & V_276 ) && V_122 -> V_279 ) {
int (* F_183)( struct V_6 * V_7 , struct V_78 * V_79 );
F_183 = F_184 ( V_122 -> F_183 ) ;
if ( V_79 -> V_124 > sizeof( struct V_89 ) && F_183 ) {
int V_233 ;
if ( F_134 ( V_79 ) )
goto V_280;
V_233 = F_183 ( V_7 , V_79 ) ;
if ( V_233 <= 0 ) {
F_135 ( F_6 ( V_7 ) ,
V_262 ,
V_145 ) ;
return - V_233 ;
}
}
}
if ( ( V_145 & V_281 ) && F_149 ( V_79 ) -> V_259 ) {
if ( V_122 -> V_282 == 0 ) {
F_123 ( L_3 ,
F_149 ( V_79 ) -> V_283 , V_79 -> V_124 ) ;
goto V_278;
}
if ( F_149 ( V_79 ) -> V_283 < V_122 -> V_282 ) {
F_123 ( L_4 ,
F_149 ( V_79 ) -> V_283 , V_122 -> V_282 ) ;
goto V_278;
}
}
if ( F_185 ( V_7 -> V_284 ) &&
F_134 ( V_79 ) )
goto V_280;
if ( F_186 ( V_7 , V_7 -> V_285 ) ) {
F_135 ( F_6 ( V_7 ) , V_275 ,
V_145 ) ;
goto V_278;
}
V_273 = 0 ;
F_187 ( V_7 , V_79 ) ;
F_188 ( V_7 ) ;
if ( ! F_189 ( V_7 ) )
V_273 = F_169 ( V_7 , V_79 ) ;
else if ( F_190 ( V_7 , V_79 , V_7 -> V_285 ) ) {
F_191 ( V_7 ) ;
goto V_278;
}
F_191 ( V_7 ) ;
return V_273 ;
V_280:
F_135 ( F_6 ( V_7 ) , V_239 , V_145 ) ;
V_278:
F_135 ( F_6 ( V_7 ) , V_240 , V_145 ) ;
F_136 ( & V_7 -> V_241 ) ;
F_174 ( V_79 ) ;
return - 1 ;
}
static void F_192 ( struct V_6 * * V_286 , unsigned int V_35 ,
struct V_78 * V_79 , unsigned int V_287 )
{
unsigned int V_288 ;
struct V_78 * V_289 = NULL ;
struct V_6 * V_7 ;
for ( V_288 = 0 ; V_288 < V_35 ; V_288 ++ ) {
V_7 = V_286 [ V_288 ] ;
if ( F_99 ( ! V_289 ) )
V_289 = ( V_288 == V_287 ) ? V_79 : F_193 ( V_79 , V_290 ) ;
if ( ! V_289 ) {
F_136 ( & V_7 -> V_241 ) ;
F_135 ( F_6 ( V_7 ) , V_275 ,
F_88 ( V_7 ) ) ;
F_135 ( F_6 ( V_7 ) , V_240 ,
F_88 ( V_7 ) ) ;
}
if ( V_289 && F_179 ( V_7 , V_289 ) <= 0 )
V_289 = NULL ;
F_49 ( V_7 ) ;
}
if ( F_47 ( V_289 ) )
F_174 ( V_289 ) ;
}
static void F_194 ( struct V_6 * V_7 , struct V_291 * V_126 )
{
struct V_291 * V_292 ;
F_195 ( V_126 ) ;
V_292 = F_196 ( & V_7 -> V_293 , V_126 ) ;
F_197 ( V_292 ) ;
}
static int F_198 ( struct V_1 * V_1 , struct V_78 * V_79 ,
struct V_89 * V_90 ,
T_4 V_48 , T_4 V_55 ,
struct V_22 * V_23 ,
int V_294 )
{
struct V_6 * V_7 , * V_286 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_10 * V_11 ;
unsigned short V_53 = F_51 ( V_90 -> V_95 ) ;
struct V_3 * V_4 = F_19 ( V_23 , V_1 , V_53 ) ;
int V_57 = V_79 -> V_82 -> V_97 ;
unsigned int V_35 = 0 , V_127 = F_78 ( F_199 ( * V_7 ) , V_295 ) ;
unsigned int V_76 = 0 , V_296 = 0 , V_297 = ( V_4 -> V_35 > 10 ) ;
bool V_298 = false ;
if ( V_297 ) {
V_296 = F_33 ( V_1 , F_37 ( V_51 ) , V_53 ) &
V_22 . V_32 ;
V_76 = F_33 ( V_1 , V_55 , V_53 ) & V_22 . V_32 ;
V_299:
V_4 = & V_22 . V_76 [ V_76 ] ;
V_127 = F_78 ( F_199 ( * V_7 ) , V_300 . V_301 ) ;
}
F_11 ( & V_4 -> V_19 ) ;
F_200 (sk, node, &hslot->head, offset) {
if ( F_62 ( V_1 , V_7 ,
V_90 -> V_95 , V_55 ,
V_90 -> V_96 , V_48 ,
V_57 , V_53 ) ) {
if ( F_47 ( V_35 == F_201 ( V_286 ) ) ) {
F_192 ( V_286 , V_35 , V_79 , ~ 0 ) ;
V_298 = true ;
V_35 = 0 ;
}
V_286 [ V_35 ++ ] = V_7 ;
F_202 ( V_7 ) ;
}
}
F_13 ( & V_4 -> V_19 ) ;
if ( V_297 && V_76 != V_296 ) {
V_76 = V_296 ;
goto V_299;
}
if ( V_35 ) {
F_192 ( V_286 , V_35 , V_79 , V_35 - 1 ) ;
} else {
if ( ! V_298 )
F_135 ( V_1 , V_302 ,
V_294 == V_303 ) ;
F_203 ( V_79 ) ;
}
return 0 ;
}
static inline int F_204 ( struct V_78 * V_79 , struct V_89 * V_90 ,
int V_294 )
{
int V_94 ;
F_149 ( V_79 ) -> V_259 = 0 ;
F_149 ( V_79 ) -> V_283 = V_79 -> V_124 ;
if ( V_294 == V_303 ) {
V_94 = F_205 ( V_79 , V_90 ) ;
if ( V_94 )
return V_94 ;
}
return F_206 ( V_79 , V_294 , V_90 -> V_132 ,
V_304 ) ;
}
int F_207 ( struct V_78 * V_79 , struct V_22 * V_23 ,
int V_294 )
{
struct V_6 * V_7 ;
struct V_89 * V_90 ;
unsigned short V_161 ;
struct V_164 * V_165 = F_208 ( V_79 ) ;
T_4 V_48 , V_55 ;
struct V_1 * V_1 = F_58 ( V_79 -> V_82 ) ;
if ( ! F_209 ( V_79 , sizeof( struct V_89 ) ) )
goto V_278;
V_90 = F_74 ( V_79 ) ;
V_161 = F_51 ( V_90 -> V_124 ) ;
V_48 = F_57 ( V_79 ) -> V_48 ;
V_55 = F_57 ( V_79 ) -> V_55 ;
if ( V_161 > V_79 -> V_124 )
goto V_305;
if ( V_294 == V_133 ) {
if ( V_161 < sizeof( * V_90 ) || F_210 ( V_79 , V_161 ) )
goto V_305;
V_90 = F_74 ( V_79 ) ;
}
if ( F_204 ( V_79 , V_90 , V_294 ) )
goto V_280;
V_7 = F_211 ( V_79 ) ;
if ( V_7 ) {
struct V_291 * V_126 = F_59 ( V_79 ) ;
int V_233 ;
if ( F_47 ( V_7 -> V_293 != V_126 ) )
F_194 ( V_7 , V_126 ) ;
V_233 = F_179 ( V_7 , V_79 ) ;
F_49 ( V_7 ) ;
if ( V_233 > 0 )
return - V_233 ;
return 0 ;
}
if ( V_165 -> V_219 & ( V_220 | V_306 ) )
return F_198 ( V_1 , V_79 , V_90 ,
V_48 , V_55 , V_23 , V_294 ) ;
V_7 = F_56 ( V_79 , V_90 -> V_96 , V_90 -> V_95 , V_23 ) ;
if ( V_7 ) {
int V_233 ;
if ( F_212 ( V_7 ) && V_90 -> V_132 && ! F_88 ( V_7 ) )
F_213 ( V_79 , V_133 , V_90 -> V_132 ,
V_304 ) ;
V_233 = F_179 ( V_7 , V_79 ) ;
F_49 ( V_7 ) ;
if ( V_233 > 0 )
return - V_233 ;
return 0 ;
}
if ( ! F_180 ( NULL , V_277 , V_79 ) )
goto V_278;
F_181 ( V_79 ) ;
if ( F_134 ( V_79 ) )
goto V_280;
F_135 ( V_1 , V_307 , V_294 == V_303 ) ;
F_214 ( V_79 , V_105 , V_308 , 0 ) ;
F_174 ( V_79 ) ;
return 0 ;
V_305:
F_123 ( L_5 ,
V_294 == V_303 ? L_6 : L_7 ,
& V_48 , F_51 ( V_90 -> V_96 ) ,
V_161 , V_79 -> V_124 ,
& V_55 , F_51 ( V_90 -> V_95 ) ) ;
goto V_278;
V_280:
F_123 ( L_8 ,
V_294 == V_303 ? L_6 : L_7 ,
& V_48 , F_51 ( V_90 -> V_96 ) , & V_55 , F_51 ( V_90 -> V_95 ) ,
V_161 ) ;
F_135 ( V_1 , V_239 , V_294 == V_303 ) ;
V_278:
F_135 ( V_1 , V_240 , V_294 == V_303 ) ;
F_174 ( V_79 ) ;
return 0 ;
}
static struct V_6 * F_215 ( struct V_1 * V_1 ,
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
static struct V_6 * F_216 ( struct V_1 * V_1 ,
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
F_217 ( V_309 , V_86 , V_84 ) ;
const T_11 V_310 = F_218 ( V_85 , V_53 ) ;
F_53 () ;
V_69 = NULL ;
F_44 (sk, node, &hslot2->head) {
if ( F_219 ( V_7 , V_1 , V_309 ,
V_86 , V_84 , V_310 , V_57 ) )
V_69 = V_7 ;
break;
}
if ( V_69 ) {
if ( F_47 ( ! F_48 ( & V_69 -> V_75 , 2 ) ) )
V_69 = NULL ;
else if ( F_47 ( ! F_219 ( V_7 , V_1 , V_309 ,
V_86 , V_84 ,
V_310 , V_57 ) ) ) {
F_49 ( V_69 ) ;
V_69 = NULL ;
}
}
F_54 () ;
return V_69 ;
}
void F_220 ( struct V_78 * V_79 )
{
struct V_1 * V_1 = F_58 ( V_79 -> V_82 ) ;
const struct V_80 * V_81 ;
const struct V_89 * V_90 ;
struct V_6 * V_7 ;
struct V_291 * V_126 ;
int V_57 = V_79 -> V_82 -> V_97 ;
int V_311 ;
if ( ! F_209 ( V_79 , F_75 ( V_79 ) + sizeof( struct V_89 ) ) )
return;
V_81 = F_57 ( V_79 ) ;
V_90 = F_74 ( V_79 ) ;
if ( V_79 -> V_312 == V_313 ||
V_79 -> V_312 == V_314 ) {
struct V_315 * V_316 = F_221 ( V_79 -> V_82 ) ;
if ( ! V_316 )
return;
V_311 = F_222 ( V_316 , V_81 -> V_55 , V_81 -> V_48 ,
V_81 -> V_317 ) ;
if ( ! V_311 )
return;
V_7 = F_215 ( V_1 , V_90 -> V_95 , V_81 -> V_55 ,
V_90 -> V_96 , V_81 -> V_48 , V_57 ) ;
} else if ( V_79 -> V_312 == V_318 ) {
V_7 = F_216 ( V_1 , V_90 -> V_95 , V_81 -> V_55 ,
V_90 -> V_96 , V_81 -> V_48 , V_57 ) ;
} else {
return;
}
if ( ! V_7 )
return;
V_79 -> V_7 = V_7 ;
V_79 -> V_319 = V_320 ;
V_126 = F_223 ( V_7 -> V_293 ) ;
if ( V_126 )
V_126 = F_224 ( V_126 , 0 ) ;
if ( V_126 ) {
if ( V_126 -> V_229 & V_321 ) {
if ( F_99 ( F_225 ( & V_126 -> V_322 ) ) )
F_226 ( V_79 , V_126 ) ;
} else {
F_227 ( V_79 , V_126 ) ;
}
}
}
int F_228 ( struct V_78 * V_79 )
{
return F_207 ( V_79 , & V_22 , V_133 ) ;
}
void F_229 ( struct V_6 * V_7 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
bool V_242 = F_139 ( V_7 ) ;
F_71 ( V_7 ) ;
F_142 ( V_7 , V_242 ) ;
if ( F_182 ( & V_276 ) && V_122 -> V_279 ) {
void (* F_230)( struct V_6 * V_7 );
F_230 = F_184 ( V_122 -> F_230 ) ;
if ( F_230 )
F_230 ( V_7 ) ;
}
}
int F_231 ( struct V_6 * V_7 , int V_323 , int V_324 ,
char V_247 * V_325 , unsigned int V_202 ,
int (* F_232)( struct V_6 * ) )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_326 , V_327 ;
int V_94 = 0 ;
int V_145 = F_88 ( V_7 ) ;
if ( V_202 < sizeof( int ) )
return - V_182 ;
if ( F_233 ( V_326 , ( int V_247 * ) V_325 ) )
return - V_328 ;
V_327 = V_326 ? 1 : 0 ;
switch ( V_324 ) {
case V_329 :
if ( V_326 != 0 ) {
V_122 -> V_169 = 1 ;
} else {
V_122 -> V_169 = 0 ;
F_98 ( V_7 ) ;
F_232 ( V_7 ) ;
F_100 ( V_7 ) ;
}
break;
case V_330 :
switch ( V_326 ) {
case 0 :
case V_331 :
case V_332 :
V_122 -> F_183 = V_333 ;
case V_334 :
V_122 -> V_279 = V_326 ;
F_176 () ;
break;
default:
V_94 = - V_335 ;
break;
}
break;
case V_336 :
V_122 -> V_337 = V_327 ;
break;
case V_338 :
V_122 -> V_339 = V_327 ;
break;
case V_340 :
if ( ! V_145 )
return - V_335 ;
if ( V_326 != 0 && V_326 < 8 )
V_326 = 8 ;
else if ( V_326 > V_341 )
V_326 = V_341 ;
V_122 -> V_342 = V_326 ;
V_122 -> V_343 |= V_344 ;
break;
case V_345 :
if ( ! V_145 )
return - V_335 ;
if ( V_326 != 0 && V_326 < 8 )
V_326 = 8 ;
else if ( V_326 > V_341 )
V_326 = V_341 ;
V_122 -> V_282 = V_326 ;
V_122 -> V_343 |= V_281 ;
break;
default:
V_94 = - V_335 ;
break;
}
return V_94 ;
}
int F_234 ( struct V_6 * V_7 , int V_323 , int V_324 ,
char V_247 * V_325 , unsigned int V_202 )
{
if ( V_323 == V_346 || V_323 == V_347 )
return F_231 ( V_7 , V_323 , V_324 , V_325 , V_202 ,
F_94 ) ;
return F_235 ( V_7 , V_323 , V_324 , V_325 , V_202 ) ;
}
int F_236 ( struct V_6 * V_7 , int V_323 , int V_324 ,
char V_247 * V_325 , unsigned int V_202 )
{
if ( V_323 == V_346 || V_323 == V_347 )
return F_231 ( V_7 , V_323 , V_324 , V_325 , V_202 ,
F_94 ) ;
return F_237 ( V_7 , V_323 , V_324 , V_325 , V_202 ) ;
}
int F_238 ( struct V_6 * V_7 , int V_323 , int V_324 ,
char V_247 * V_325 , int V_247 * V_202 )
{
struct V_121 * V_122 = F_7 ( V_7 ) ;
int V_326 , V_124 ;
if ( F_233 ( V_124 , V_202 ) )
return - V_328 ;
V_124 = F_239 (unsigned int, len, sizeof(int)) ;
if ( V_124 < 0 )
return - V_182 ;
switch ( V_324 ) {
case V_329 :
V_326 = V_122 -> V_169 ;
break;
case V_330 :
V_326 = V_122 -> V_279 ;
break;
case V_336 :
V_326 = V_122 -> V_337 ;
break;
case V_338 :
V_326 = V_122 -> V_339 ;
break;
case V_340 :
V_326 = V_122 -> V_342 ;
break;
case V_345 :
V_326 = V_122 -> V_282 ;
break;
default:
return - V_335 ;
}
if ( F_145 ( V_124 , V_202 ) )
return - V_328 ;
if ( F_240 ( V_325 , & V_326 , V_124 ) )
return - V_328 ;
return 0 ;
}
int F_241 ( struct V_6 * V_7 , int V_323 , int V_324 ,
char V_247 * V_325 , int V_247 * V_202 )
{
if ( V_323 == V_346 || V_323 == V_347 )
return F_238 ( V_7 , V_323 , V_324 , V_325 , V_202 ) ;
return F_242 ( V_7 , V_323 , V_324 , V_325 , V_202 ) ;
}
int F_243 ( struct V_6 * V_7 , int V_323 , int V_324 ,
char V_247 * V_325 , int V_247 * V_202 )
{
if ( V_323 == V_346 || V_323 == V_347 )
return F_238 ( V_7 , V_323 , V_324 , V_325 , V_202 ) ;
return F_244 ( V_7 , V_323 , V_324 , V_325 , V_202 ) ;
}
unsigned int F_245 ( struct V_348 * V_348 , struct V_349 * V_6 , T_12 * V_350 )
{
unsigned int V_32 = F_246 ( V_348 , V_6 , V_350 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_247 ( V_7 ) ;
if ( ( V_32 & V_351 ) && ! ( V_348 -> V_352 & V_353 ) &&
! ( V_7 -> V_354 & V_355 ) && ! F_131 ( V_7 ) )
V_32 &= ~ ( V_356 | V_351 ) ;
return V_32 ;
}
static struct V_6 * F_248 ( struct V_357 * V_358 , int V_359 )
{
struct V_6 * V_7 ;
struct V_360 * V_361 = V_358 -> V_362 ;
struct V_1 * V_1 = F_249 ( V_358 ) ;
for ( V_361 -> V_363 = V_359 ; V_361 -> V_363 <= V_361 -> V_22 -> V_32 ;
++ V_361 -> V_363 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_361 -> V_22 -> V_73 [ V_361 -> V_363 ] ;
if ( F_250 ( & V_4 -> V_42 ) )
continue;
F_21 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_60 == V_361 -> V_364 )
goto V_33;
}
F_24 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_33:
return V_7 ;
}
static struct V_6 * F_251 ( struct V_357 * V_358 , struct V_6 * V_7 )
{
struct V_360 * V_361 = V_358 -> V_362 ;
struct V_1 * V_1 = F_249 ( V_358 ) ;
do {
V_7 = F_252 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_60 != V_361 -> V_364 ) );
if ( ! V_7 ) {
if ( V_361 -> V_363 <= V_361 -> V_22 -> V_32 )
F_24 ( & V_361 -> V_22 -> V_73 [ V_361 -> V_363 ] . V_19 ) ;
return F_248 ( V_358 , V_361 -> V_363 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_253 ( struct V_357 * V_358 , T_13 V_365 )
{
struct V_6 * V_7 = F_248 ( V_358 , 0 ) ;
if ( V_7 )
while ( V_365 && ( V_7 = F_251 ( V_358 , V_7 ) ) != NULL )
-- V_365 ;
return V_365 ? NULL : V_7 ;
}
static void * F_254 ( struct V_357 * V_358 , T_13 * V_365 )
{
struct V_360 * V_361 = V_358 -> V_362 ;
V_361 -> V_363 = V_366 ;
return * V_365 ? F_253 ( V_358 , * V_365 - 1 ) : V_367 ;
}
static void * F_255 ( struct V_357 * V_358 , void * V_368 , T_13 * V_365 )
{
struct V_6 * V_7 ;
if ( V_368 == V_367 )
V_7 = F_253 ( V_358 , 0 ) ;
else
V_7 = F_251 ( V_358 , V_368 ) ;
++ * V_365 ;
return V_7 ;
}
static void F_256 ( struct V_357 * V_358 , void * V_368 )
{
struct V_360 * V_361 = V_358 -> V_362 ;
if ( V_361 -> V_363 <= V_361 -> V_22 -> V_32 )
F_24 ( & V_361 -> V_22 -> V_73 [ V_361 -> V_363 ] . V_19 ) ;
}
int F_257 ( struct V_369 * V_369 , struct V_348 * V_348 )
{
struct V_370 * V_371 = F_258 ( V_369 ) ;
struct V_360 * V_372 ;
int V_94 ;
V_94 = F_259 ( V_369 , V_348 , & V_371 -> V_373 ,
sizeof( struct V_360 ) ) ;
if ( V_94 < 0 )
return V_94 ;
V_372 = ( (struct V_357 * ) V_348 -> V_374 ) -> V_362 ;
V_372 -> V_364 = V_371 -> V_364 ;
V_372 -> V_22 = V_371 -> V_22 ;
return V_94 ;
}
int F_260 ( struct V_1 * V_1 , struct V_370 * V_371 )
{
struct V_375 * V_376 ;
int V_273 = 0 ;
V_371 -> V_373 . V_359 = F_254 ;
V_371 -> V_373 . V_377 = F_255 ;
V_371 -> V_373 . V_378 = F_256 ;
V_376 = F_261 ( V_371 -> V_379 , V_380 , V_1 -> V_381 ,
V_371 -> V_382 , V_371 ) ;
if ( ! V_376 )
V_273 = - V_274 ;
return V_273 ;
}
void F_262 ( struct V_1 * V_1 , struct V_370 * V_371 )
{
F_263 ( V_371 -> V_379 , V_1 -> V_381 ) ;
}
static void F_264 ( struct V_6 * V_383 , struct V_357 * V_384 ,
int V_363 )
{
struct V_44 * V_59 = F_26 ( V_383 ) ;
T_4 V_95 = V_59 -> V_62 ;
T_4 V_125 = V_59 -> V_47 ;
T_1 V_385 = F_51 ( V_59 -> V_63 ) ;
T_1 V_386 = F_51 ( V_59 -> V_146 ) ;
F_265 ( V_384 , L_9
L_10 ,
V_363 , V_125 , V_386 , V_95 , V_385 , V_383 -> V_116 ,
F_144 ( V_383 ) ,
F_266 ( V_383 ) ,
0 , 0L , 0 ,
F_267 ( F_268 ( V_384 ) , F_3 ( V_383 ) ) ,
0 , F_269 ( V_383 ) ,
F_270 ( & V_383 -> V_75 ) , V_383 ,
F_270 ( & V_383 -> V_241 ) ) ;
}
int F_271 ( struct V_357 * V_358 , void * V_368 )
{
F_272 ( V_358 , 127 ) ;
if ( V_368 == V_367 )
F_273 ( V_358 , L_11
L_12
L_13 ) ;
else {
struct V_360 * V_361 = V_358 -> V_362 ;
F_264 ( V_368 , V_358 , V_361 -> V_363 ) ;
}
F_274 ( V_358 , '\n' ) ;
return 0 ;
}
static int T_14 F_275 ( struct V_1 * V_1 )
{
return F_260 ( V_1 , & V_387 ) ;
}
static void T_15 F_276 ( struct V_1 * V_1 )
{
F_262 ( V_1 , & V_387 ) ;
}
int T_16 F_277 ( void )
{
return F_278 ( & V_388 ) ;
}
void F_279 ( void )
{
F_280 ( & V_388 ) ;
}
static int T_16 F_281 ( char * V_389 )
{
T_17 V_233 ;
if ( ! V_389 )
return 0 ;
V_233 = F_282 ( V_389 , 0 , & V_390 ) ;
if ( V_233 )
return 0 ;
if ( V_390 && V_390 < V_391 )
V_390 = V_391 ;
return 1 ;
}
void T_16 F_283 ( struct V_22 * V_392 , const char * V_379 )
{
unsigned int V_288 ;
V_392 -> V_73 = F_284 ( V_379 ,
2 * sizeof( struct V_3 ) ,
V_390 ,
21 ,
0 ,
& V_392 -> log ,
& V_392 -> V_32 ,
V_391 ,
64 * 1024 ) ;
V_392 -> V_76 = V_392 -> V_73 + ( V_392 -> V_32 + 1 ) ;
for ( V_288 = 0 ; V_288 <= V_392 -> V_32 ; V_288 ++ ) {
F_285 ( & V_392 -> V_73 [ V_288 ] . V_42 , V_288 ) ;
V_392 -> V_73 [ V_288 ] . V_35 = 0 ;
F_286 ( & V_392 -> V_73 [ V_288 ] . V_19 ) ;
}
for ( V_288 = 0 ; V_288 <= V_392 -> V_32 ; V_288 ++ ) {
F_285 ( & V_392 -> V_76 [ V_288 ] . V_42 , V_288 ) ;
V_392 -> V_76 [ V_288 ] . V_35 = 0 ;
F_286 ( & V_392 -> V_76 [ V_288 ] . V_19 ) ;
}
}
T_3 F_287 ( void )
{
static T_3 T_18 V_68 ;
F_41 ( & T_18 , sizeof( T_18 ) ) ;
return T_18 ;
}
void T_16 F_288 ( void )
{
unsigned long V_393 ;
F_283 ( & V_22 , L_14 ) ;
V_393 = F_289 () / 8 ;
V_393 = F_290 ( V_393 , 128UL ) ;
V_394 [ 0 ] = V_393 / 4 * 3 ;
V_394 [ 1 ] = V_393 ;
V_394 [ 2 ] = V_394 [ 0 ] * 2 ;
V_395 = V_396 ;
V_397 = V_396 ;
}
