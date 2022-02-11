static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
#if F_2 ( V_4 )
if ( ! V_1 -> V_5 . V_6 &&
V_3 && F_3 ( F_4 ( V_3 ) -> V_7 ) )
return true ;
#endif
return false ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_8 ,
const struct V_9 * V_10 ,
unsigned long * V_11 ,
struct V_12 * V_13 , unsigned int log )
{
struct V_12 * V_14 ;
T_2 V_15 = F_6 ( V_13 ) ;
F_7 (sk2, &hslot->head) {
if ( F_8 ( F_9 ( V_14 ) , V_1 ) &&
V_14 != V_13 &&
( V_11 || F_10 ( V_14 ) -> V_16 == V_8 ) &&
( ! V_14 -> V_17 || ! V_13 -> V_17 ) &&
( ! V_14 -> V_18 || ! V_13 -> V_18 ||
V_14 -> V_18 == V_13 -> V_18 ) &&
F_11 ( V_13 , V_14 , true ) ) {
if ( V_14 -> V_19 && V_13 -> V_19 &&
! F_12 ( V_13 -> V_20 ) &&
F_13 ( V_15 , F_6 ( V_14 ) ) ) {
if ( ! V_11 )
return 0 ;
} else {
if ( ! V_11 )
return 1 ;
F_14 ( F_10 ( V_14 ) -> V_16 >> log ,
V_11 ) ;
}
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , T_1 V_8 ,
struct V_9 * V_21 ,
struct V_12 * V_13 )
{
struct V_12 * V_14 ;
T_2 V_15 = F_6 ( V_13 ) ;
int V_22 = 0 ;
F_16 ( & V_21 -> V_23 ) ;
F_17 (sk2, &hslot2->head) {
if ( F_8 ( F_9 ( V_14 ) , V_1 ) &&
V_14 != V_13 &&
( F_10 ( V_14 ) -> V_16 == V_8 ) &&
( ! V_14 -> V_17 || ! V_13 -> V_17 ) &&
( ! V_14 -> V_18 || ! V_13 -> V_18 ||
V_14 -> V_18 == V_13 -> V_18 ) &&
F_11 ( V_13 , V_14 , true ) ) {
if ( V_14 -> V_19 && V_13 -> V_19 &&
! F_12 ( V_13 -> V_20 ) &&
F_13 ( V_15 , F_6 ( V_14 ) ) ) {
V_22 = 0 ;
} else {
V_22 = 1 ;
}
break;
}
}
F_18 ( & V_21 -> V_23 ) ;
return V_22 ;
}
static int F_19 ( struct V_12 * V_13 , struct V_9 * V_10 )
{
struct V_1 * V_1 = F_9 ( V_13 ) ;
T_2 V_15 = F_6 ( V_13 ) ;
struct V_12 * V_14 ;
F_7 (sk2, &hslot->head) {
if ( F_8 ( F_9 ( V_14 ) , V_1 ) &&
V_14 != V_13 &&
V_14 -> V_24 == V_13 -> V_24 &&
F_20 ( V_14 ) == F_20 ( V_13 ) &&
( F_10 ( V_14 ) -> V_16 == F_10 ( V_13 ) -> V_16 ) &&
( V_14 -> V_18 == V_13 -> V_18 ) &&
V_14 -> V_19 && F_13 ( V_15 , F_6 ( V_14 ) ) &&
F_11 ( V_13 , V_14 , false ) ) {
return F_21 ( V_13 , V_14 ) ;
}
}
if ( ! F_12 ( V_13 -> V_20 ) )
return F_22 ( V_13 ) ;
return 0 ;
}
int F_23 ( struct V_12 * V_13 , unsigned short V_25 ,
unsigned int V_26 )
{
struct V_9 * V_10 , * V_21 ;
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
int error = 1 ;
struct V_1 * V_1 = F_9 ( V_13 ) ;
if ( ! V_25 ) {
int V_31 , V_32 , V_33 ;
unsigned int rand ;
unsigned short V_34 , V_35 ;
F_24 ( V_11 , V_36 ) ;
F_25 ( V_1 , & V_31 , & V_32 ) ;
V_33 = ( V_32 - V_31 ) + 1 ;
rand = F_26 () ;
V_34 = F_27 ( rand , V_33 ) + V_31 ;
rand = ( rand | 1 ) * ( V_28 -> V_37 + 1 ) ;
V_35 = V_34 + V_28 -> V_37 + 1 ;
do {
V_10 = F_28 ( V_28 , V_1 , V_34 ) ;
F_29 ( V_11 , V_36 ) ;
F_30 ( & V_10 -> V_23 ) ;
F_5 ( V_1 , V_25 , V_10 , V_11 , V_13 ,
V_28 -> log ) ;
V_25 = V_34 ;
do {
if ( V_31 <= V_25 && V_25 <= V_32 &&
! F_31 ( V_25 >> V_28 -> log , V_11 ) &&
! F_32 ( V_1 , V_25 ) )
goto V_38;
V_25 += rand ;
} while ( V_25 != V_34 );
F_33 ( & V_10 -> V_23 ) ;
F_34 () ;
} while ( ++ V_34 != V_35 );
goto V_39;
} else {
V_10 = F_28 ( V_28 , V_1 , V_25 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( V_10 -> V_40 > 10 ) {
int V_41 ;
unsigned int V_42 = F_10 ( V_13 ) -> V_43 ^ V_25 ;
V_42 &= V_28 -> V_37 ;
V_26 &= V_28 -> V_37 ;
V_21 = F_35 ( V_28 , V_42 ) ;
if ( V_10 -> V_40 < V_21 -> V_40 )
goto V_44;
V_41 = F_15 ( V_1 , V_25 , V_21 , V_13 ) ;
if ( ! V_41 && ( V_26 != V_42 ) ) {
V_21 = F_35 ( V_28 , V_26 ) ;
V_41 = F_15 ( V_1 , V_25 , V_21 ,
V_13 ) ;
}
if ( V_41 )
goto V_45;
else
goto V_38;
}
V_44:
if ( F_5 ( V_1 , V_25 , V_10 , NULL , V_13 , 0 ) )
goto V_45;
}
V_38:
F_36 ( V_13 ) -> V_46 = V_25 ;
F_10 ( V_13 ) -> V_16 = V_25 ;
F_10 ( V_13 ) -> V_43 ^= V_25 ;
if ( F_37 ( V_13 ) ) {
if ( V_13 -> V_19 &&
F_19 ( V_13 , V_10 ) ) {
F_36 ( V_13 ) -> V_46 = 0 ;
F_10 ( V_13 ) -> V_16 = 0 ;
F_10 ( V_13 ) -> V_43 ^= V_25 ;
goto V_45;
}
F_38 ( V_13 , & V_10 -> V_47 ) ;
V_10 -> V_40 ++ ;
F_39 ( F_9 ( V_13 ) , V_13 -> V_29 , 1 ) ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
F_16 ( & V_21 -> V_23 ) ;
if ( F_2 ( V_48 ) && V_13 -> V_19 &&
V_13 -> V_24 == V_49 )
F_40 ( & F_10 ( V_13 ) -> V_50 ,
& V_21 -> V_47 ) ;
else
F_41 ( & F_10 ( V_13 ) -> V_50 ,
& V_21 -> V_47 ) ;
V_21 -> V_40 ++ ;
F_18 ( & V_21 -> V_23 ) ;
}
F_42 ( V_13 , V_51 ) ;
error = 0 ;
V_45:
F_33 ( & V_10 -> V_23 ) ;
V_39:
return error ;
}
static T_3 F_43 ( const struct V_1 * V_1 , T_4 V_52 ,
unsigned int V_53 )
{
return F_44 ( ( V_54 T_3 ) V_52 , F_45 ( V_1 ) ) ^ V_53 ;
}
int F_46 ( struct V_12 * V_13 , unsigned short V_25 )
{
unsigned int V_26 =
F_43 ( F_9 ( V_13 ) , F_47 ( V_55 ) , V_25 ) ;
unsigned int V_56 =
F_43 ( F_9 ( V_13 ) , F_36 ( V_13 ) -> V_57 , 0 ) ;
F_10 ( V_13 ) -> V_43 = V_56 ;
return F_23 ( V_13 , V_25 , V_26 ) ;
}
static int F_48 ( struct V_12 * V_13 , struct V_1 * V_1 ,
T_4 V_52 , T_5 V_58 ,
T_4 V_59 , unsigned short V_60 , int V_61 ,
bool V_62 )
{
int V_63 ;
struct V_64 * V_65 ;
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) ||
F_10 ( V_13 ) -> V_16 != V_60 ||
F_20 ( V_13 ) )
return - 1 ;
V_63 = ( V_13 -> V_24 == V_66 ) ? 2 : 1 ;
V_65 = F_36 ( V_13 ) ;
if ( V_65 -> V_57 ) {
if ( V_65 -> V_57 != V_59 )
return - 1 ;
V_63 += 4 ;
}
if ( V_65 -> V_67 ) {
if ( V_65 -> V_67 != V_52 )
return - 1 ;
V_63 += 4 ;
}
if ( V_65 -> V_68 ) {
if ( V_65 -> V_68 != V_58 )
return - 1 ;
V_63 += 4 ;
}
if ( V_13 -> V_18 || V_62 ) {
if ( V_13 -> V_18 != V_61 )
return - 1 ;
V_63 += 4 ;
}
if ( V_13 -> V_69 == F_49 () )
V_63 ++ ;
return V_63 ;
}
static T_3 F_50 ( const struct V_1 * V_1 , const T_4 V_70 ,
const T_1 V_71 , const T_4 V_72 ,
const T_5 V_73 )
{
static T_3 T_6 V_74 ;
F_51 ( & T_6 , sizeof( T_6 ) ) ;
return F_52 ( V_70 , V_71 , V_72 , V_73 ,
T_6 + F_45 ( V_1 ) ) ;
}
static struct V_12 * F_53 ( struct V_1 * V_1 ,
T_4 V_52 , T_5 V_58 ,
T_4 V_59 , unsigned int V_60 , int V_61 , bool V_62 ,
struct V_9 * V_21 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 , * V_75 ;
int V_63 , V_76 , V_77 = 0 , V_78 = 0 ;
T_3 V_79 = 0 ;
V_75 = NULL ;
V_76 = 0 ;
F_54 (sk, &hslot2->head) {
V_63 = F_48 ( V_13 , V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 , V_62 ) ;
if ( V_63 > V_76 ) {
V_78 = V_13 -> V_19 ;
if ( V_78 ) {
V_79 = F_50 ( V_1 , V_59 , V_60 ,
V_52 , V_58 ) ;
V_75 = F_55 ( V_13 , V_79 , V_3 ,
sizeof( struct V_80 ) ) ;
if ( V_75 )
return V_75 ;
V_77 = 1 ;
}
V_76 = V_63 ;
V_75 = V_13 ;
} else if ( V_63 == V_76 && V_78 ) {
V_77 ++ ;
if ( F_27 ( V_79 , V_77 ) == 0 )
V_75 = V_13 ;
V_79 = F_56 ( V_79 ) ;
}
}
return V_75 ;
}
struct V_12 * F_57 ( struct V_1 * V_1 , T_4 V_52 ,
T_5 V_58 , T_4 V_59 , T_5 V_81 ,
int V_61 , struct V_27 * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 , * V_75 ;
unsigned short V_60 = F_58 ( V_81 ) ;
unsigned int V_82 , V_42 , V_83 = F_59 ( V_1 , V_60 , V_28 -> V_37 ) ;
struct V_9 * V_21 , * V_10 = & V_28 -> V_79 [ V_83 ] ;
bool V_62 = F_1 ( V_1 , V_3 ) ;
int V_63 , V_76 , V_77 = 0 , V_78 = 0 ;
T_3 V_79 = 0 ;
if ( V_10 -> V_40 > 10 ) {
V_82 = F_43 ( V_1 , V_59 , V_60 ) ;
V_42 = V_82 & V_28 -> V_37 ;
V_21 = & V_28 -> V_82 [ V_42 ] ;
if ( V_10 -> V_40 < V_21 -> V_40 )
goto V_84;
V_75 = F_53 ( V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 ,
V_62 , V_21 , V_3 ) ;
if ( ! V_75 ) {
unsigned int V_85 = V_42 ;
V_82 = F_43 ( V_1 , F_47 ( V_55 ) , V_60 ) ;
V_42 = V_82 & V_28 -> V_37 ;
if ( F_60 ( V_42 == V_85 ) )
return V_75 ;
V_21 = & V_28 -> V_82 [ V_42 ] ;
if ( V_10 -> V_40 < V_21 -> V_40 )
goto V_84;
V_75 = F_53 ( V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 ,
V_62 , V_21 , V_3 ) ;
}
return V_75 ;
}
V_84:
V_75 = NULL ;
V_76 = 0 ;
F_61 (sk, &hslot->head) {
V_63 = F_48 ( V_13 , V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 , V_62 ) ;
if ( V_63 > V_76 ) {
V_78 = V_13 -> V_19 ;
if ( V_78 ) {
V_79 = F_50 ( V_1 , V_59 , V_60 ,
V_52 , V_58 ) ;
V_75 = F_55 ( V_13 , V_79 , V_3 ,
sizeof( struct V_80 ) ) ;
if ( V_75 )
return V_75 ;
V_77 = 1 ;
}
V_75 = V_13 ;
V_76 = V_63 ;
} else if ( V_63 == V_76 && V_78 ) {
V_77 ++ ;
if ( F_27 ( V_79 , V_77 ) == 0 )
V_75 = V_13 ;
V_79 = F_56 ( V_79 ) ;
}
}
return V_75 ;
}
static inline struct V_12 * F_62 ( struct V_2 * V_3 ,
T_5 V_58 , T_5 V_81 ,
struct V_27 * V_28 )
{
const struct V_86 * V_87 = F_63 ( V_3 ) ;
return F_57 ( F_64 ( V_3 -> V_88 ) , V_87 -> V_52 , V_58 ,
V_87 -> V_59 , V_81 , F_65 ( V_3 ) ,
V_28 , V_3 ) ;
}
struct V_12 * F_66 ( struct V_2 * V_3 ,
T_5 V_58 , T_5 V_81 )
{
return F_62 ( V_3 , V_58 , V_81 , & V_27 ) ;
}
struct V_12 * F_67 ( struct V_1 * V_1 , T_4 V_52 , T_5 V_58 ,
T_4 V_59 , T_5 V_81 , int V_61 )
{
struct V_12 * V_13 ;
V_13 = F_57 ( V_1 , V_52 , V_58 , V_59 , V_81 ,
V_61 , & V_27 , NULL ) ;
if ( V_13 && ! F_68 ( & V_13 -> V_89 ) )
V_13 = NULL ;
return V_13 ;
}
static inline bool F_69 ( struct V_1 * V_1 , struct V_12 * V_13 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_61 , unsigned short V_60 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) ||
F_10 ( V_13 ) -> V_16 != V_60 ||
( V_65 -> V_67 && V_65 -> V_67 != V_93 ) ||
( V_65 -> V_68 != V_92 && V_65 -> V_68 ) ||
( V_65 -> V_57 && V_65 -> V_57 != V_91 ) ||
F_20 ( V_13 ) ||
( V_13 -> V_18 && V_13 -> V_18 != V_61 ) )
return false ;
if ( ! F_70 ( V_13 , V_91 , V_93 , V_61 ) )
return false ;
return true ;
}
void F_71 ( struct V_2 * V_3 , T_3 V_94 , struct V_27 * V_28 )
{
struct V_64 * V_65 ;
const struct V_86 * V_87 = ( const struct V_86 * ) V_3 -> V_95 ;
struct V_80 * V_96 = (struct V_80 * ) ( V_3 -> V_95 + ( V_87 -> V_97 << 2 ) ) ;
const int type = F_72 ( V_3 ) -> type ;
const int V_98 = F_72 ( V_3 ) -> V_98 ;
struct V_12 * V_13 ;
int V_99 ;
int V_100 ;
struct V_1 * V_1 = F_64 ( V_3 -> V_88 ) ;
V_13 = F_57 ( V_1 , V_87 -> V_59 , V_96 -> V_101 ,
V_87 -> V_52 , V_96 -> V_102 , V_3 -> V_88 -> V_103 , V_28 ,
NULL ) ;
if ( ! V_13 ) {
F_73 ( V_1 , V_104 ) ;
return;
}
V_100 = 0 ;
V_99 = 0 ;
V_65 = F_36 ( V_13 ) ;
switch ( type ) {
default:
case V_105 :
V_100 = V_106 ;
break;
case V_107 :
goto V_108;
case V_109 :
V_100 = V_110 ;
V_99 = 1 ;
break;
case V_111 :
if ( V_98 == V_112 ) {
F_74 ( V_3 , V_13 , V_94 ) ;
if ( V_65 -> V_113 != V_114 ) {
V_100 = V_115 ;
V_99 = 1 ;
break;
}
goto V_108;
}
V_100 = V_106 ;
if ( V_98 <= V_116 ) {
V_99 = V_117 [ V_98 ] . V_118 ;
V_100 = V_117 [ V_98 ] . V_119 ;
}
break;
case V_120 :
F_75 ( V_3 , V_13 ) ;
goto V_108;
}
if ( ! V_65 -> V_121 ) {
if ( ! V_99 || V_13 -> V_122 != V_123 )
goto V_108;
} else
F_76 ( V_13 , V_3 , V_100 , V_96 -> V_101 , V_94 , ( V_124 * ) ( V_96 + 1 ) ) ;
V_13 -> V_125 = V_100 ;
V_13 -> V_126 ( V_13 ) ;
V_108:
return;
}
void F_77 ( struct V_2 * V_3 , T_3 V_94 )
{
F_71 ( V_3 , V_94 , & V_27 ) ;
}
void F_78 ( struct V_12 * V_13 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
if ( V_128 -> V_129 ) {
V_128 -> V_130 = 0 ;
V_128 -> V_129 = 0 ;
F_79 ( V_13 ) ;
}
}
void F_80 ( struct V_2 * V_3 , T_4 V_131 , T_4 V_132 )
{
struct V_80 * V_96 = F_81 ( V_3 ) ;
int V_133 = F_82 ( V_3 ) ;
int V_130 = V_3 -> V_130 - V_133 ;
int V_134 = V_130 ;
T_7 V_135 = 0 ;
if ( ! F_83 ( V_3 ) ) {
V_3 -> V_136 = F_84 ( V_3 ) - V_3 -> V_47 ;
V_3 -> V_137 = F_85 ( struct V_80 , V_138 ) ;
V_96 -> V_138 = ~ F_86 ( V_131 , V_132 , V_130 ,
V_139 , 0 ) ;
} else {
struct V_2 * V_140 ;
F_87 (skb, frags) {
V_135 = F_88 ( V_135 , V_140 -> V_135 ) ;
V_134 -= V_140 -> V_130 ;
}
V_135 = F_89 ( V_3 , V_133 , V_134 , V_135 ) ;
V_3 -> V_141 = V_142 ;
V_96 -> V_138 = F_86 ( V_131 , V_132 , V_130 , V_139 , V_135 ) ;
if ( V_96 -> V_138 == 0 )
V_96 -> V_138 = V_143 ;
}
}
void F_90 ( bool V_144 , struct V_2 * V_3 ,
T_4 V_52 , T_4 V_59 , int V_130 )
{
struct V_80 * V_96 = F_81 ( V_3 ) ;
if ( V_144 ) {
V_96 -> V_138 = 0 ;
} else if ( F_91 ( V_3 ) ) {
V_96 -> V_138 = ~ F_92 ( V_130 , V_52 , V_59 , 0 ) ;
} else if ( V_3 -> V_141 == V_145 ) {
V_96 -> V_138 = 0 ;
V_96 -> V_138 = F_92 ( V_130 , V_52 , V_59 , F_93 ( V_3 ) ) ;
if ( V_96 -> V_138 == 0 )
V_96 -> V_138 = V_143 ;
} else {
V_3 -> V_141 = V_145 ;
V_3 -> V_136 = F_84 ( V_3 ) - V_3 -> V_47 ;
V_3 -> V_137 = F_85 ( struct V_80 , V_138 ) ;
V_96 -> V_138 = ~ F_92 ( V_130 , V_52 , V_59 , 0 ) ;
}
}
static int F_94 ( struct V_2 * V_3 , struct V_146 * V_147 )
{
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_64 * V_65 = F_36 ( V_13 ) ;
struct V_80 * V_96 ;
int V_100 = 0 ;
int V_148 = F_95 ( V_13 ) ;
int V_133 = F_82 ( V_3 ) ;
int V_130 = V_3 -> V_130 - V_133 ;
T_7 V_135 = 0 ;
V_96 = F_81 ( V_3 ) ;
V_96 -> V_102 = V_65 -> V_149 ;
V_96 -> V_101 = V_147 -> V_150 ;
V_96 -> V_130 = F_96 ( V_130 ) ;
V_96 -> V_138 = 0 ;
if ( V_148 )
V_135 = F_97 ( V_3 ) ;
else if ( V_13 -> V_151 ) {
V_3 -> V_141 = V_142 ;
goto V_152;
} else if ( V_3 -> V_141 == V_145 ) {
F_80 ( V_3 , V_147 -> V_52 , V_147 -> V_59 ) ;
goto V_152;
} else
V_135 = F_98 ( V_3 ) ;
V_96 -> V_138 = F_86 ( V_147 -> V_52 , V_147 -> V_59 , V_130 ,
V_13 -> V_153 , V_135 ) ;
if ( V_96 -> V_138 == 0 )
V_96 -> V_138 = V_143 ;
V_152:
V_100 = F_99 ( F_9 ( V_13 ) , V_3 ) ;
if ( V_100 ) {
if ( V_100 == - V_154 && ! V_65 -> V_121 ) {
F_100 ( F_9 ( V_13 ) ,
V_155 , V_148 ) ;
V_100 = 0 ;
}
} else
F_100 ( F_9 ( V_13 ) ,
V_156 , V_148 ) ;
return V_100 ;
}
int F_101 ( struct V_12 * V_13 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
struct V_64 * V_65 = F_36 ( V_13 ) ;
struct V_146 * V_147 = & V_65 -> V_157 . V_158 . V_159 . V_160 ;
struct V_2 * V_3 ;
int V_100 = 0 ;
V_3 = F_102 ( V_13 , V_147 ) ;
if ( ! V_3 )
goto V_108;
V_100 = F_94 ( V_3 , V_147 ) ;
V_108:
V_128 -> V_130 = 0 ;
V_128 -> V_129 = 0 ;
return V_100 ;
}
int F_103 ( struct V_12 * V_13 , struct V_161 * V_162 , T_8 V_130 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
struct V_127 * V_128 = F_10 ( V_13 ) ;
struct V_146 V_163 ;
struct V_146 * V_147 ;
int V_164 = V_130 ;
struct V_165 V_166 ;
struct V_167 * V_168 = NULL ;
int free = 0 ;
int V_169 = 0 ;
T_4 V_59 , V_72 , V_52 ;
T_5 V_81 ;
V_124 V_170 ;
int V_100 , V_148 = F_95 ( V_13 ) ;
int V_171 = V_128 -> V_172 || V_162 -> V_173 & V_174 ;
int (* F_104)( void * , char * , int , int , int , struct V_2 * );
struct V_2 * V_3 ;
struct V_175 V_176 ;
if ( V_130 > 0xFFFF )
return - V_115 ;
if ( V_162 -> V_173 & V_177 )
return - V_178 ;
V_166 . V_179 = NULL ;
V_166 . V_180 = 0 ;
V_166 . V_181 = 0 ;
V_166 . V_170 = - 1 ;
F_104 = V_148 ? V_182 : V_183 ;
V_147 = & V_65 -> V_157 . V_158 . V_159 . V_160 ;
if ( V_128 -> V_129 ) {
F_105 ( V_13 ) ;
if ( F_106 ( V_128 -> V_129 ) ) {
if ( F_60 ( V_128 -> V_129 != V_184 ) ) {
F_107 ( V_13 ) ;
return - V_185 ;
}
goto V_186;
}
F_107 ( V_13 ) ;
}
V_164 += sizeof( struct V_80 ) ;
if ( V_162 -> V_187 ) {
F_108 ( struct V_188 * , V_189 , V_162 -> V_187 ) ;
if ( V_162 -> V_190 < sizeof( * V_189 ) )
return - V_185 ;
if ( V_189 -> V_191 != V_184 ) {
if ( V_189 -> V_191 != V_192 )
return - V_193 ;
}
V_59 = V_189 -> V_194 . V_195 ;
V_81 = V_189 -> V_196 ;
if ( V_81 == 0 )
return - V_185 ;
} else {
if ( V_13 -> V_122 != V_123 )
return - V_197 ;
V_59 = V_65 -> V_67 ;
V_81 = V_65 -> V_68 ;
V_169 = 1 ;
}
V_166 . V_198 . V_199 = V_13 -> V_200 ;
V_166 . V_201 = V_65 -> V_202 ;
V_166 . V_203 = V_13 -> V_18 ;
if ( V_162 -> V_204 ) {
V_100 = F_109 ( V_13 , V_162 , & V_166 , V_13 -> V_24 == V_49 ) ;
if ( F_60 ( V_100 ) ) {
F_110 ( V_166 . V_179 ) ;
return V_100 ;
}
if ( V_166 . V_179 )
free = 1 ;
V_169 = 0 ;
}
if ( ! V_166 . V_179 ) {
struct V_205 * V_206 ;
F_111 () ;
V_206 = F_112 ( V_65 -> V_206 ) ;
if ( V_206 ) {
memcpy ( & V_176 , V_206 ,
sizeof( * V_206 ) + V_206 -> V_179 . V_207 ) ;
V_166 . V_179 = & V_176 . V_179 ;
}
F_113 () ;
}
V_52 = V_166 . V_201 ;
V_166 . V_201 = V_72 = V_59 ;
F_114 ( V_13 , V_166 . V_198 . V_199 , & V_166 . V_180 ) ;
if ( V_166 . V_179 && V_166 . V_179 -> V_179 . V_208 ) {
if ( ! V_59 )
return - V_185 ;
V_72 = V_166 . V_179 -> V_179 . V_72 ;
V_169 = 0 ;
}
V_170 = F_115 ( & V_166 , V_65 ) ;
if ( F_116 ( V_13 , V_209 ) ||
( V_162 -> V_173 & V_210 ) ||
( V_166 . V_179 && V_166 . V_179 -> V_179 . V_211 ) ) {
V_170 |= V_212 ;
V_169 = 0 ;
}
if ( F_117 ( V_59 ) ) {
if ( ! V_166 . V_203 )
V_166 . V_203 = V_65 -> V_213 ;
if ( ! V_52 )
V_52 = V_65 -> V_214 ;
V_169 = 0 ;
} else if ( ! V_166 . V_203 )
V_166 . V_203 = V_65 -> V_215 ;
if ( V_169 )
V_168 = (struct V_167 * ) F_118 ( V_13 , 0 ) ;
if ( ! V_168 ) {
struct V_1 * V_1 = F_9 ( V_13 ) ;
T_9 V_216 = F_119 ( V_13 ) ;
V_147 = & V_163 ;
F_120 ( V_147 , V_166 . V_203 , V_13 -> V_217 , V_170 ,
V_218 , V_13 -> V_153 ,
V_216 ,
V_72 , V_52 , V_81 , V_65 -> V_149 ,
V_13 -> V_219 ) ;
F_121 ( V_13 , F_122 ( V_147 ) ) ;
V_168 = F_123 ( V_1 , V_147 , V_13 ) ;
if ( F_124 ( V_168 ) ) {
V_100 = F_125 ( V_168 ) ;
V_168 = NULL ;
if ( V_100 == - V_220 )
F_126 ( V_1 , V_221 ) ;
goto V_108;
}
V_100 = - V_222 ;
if ( ( V_168 -> V_223 & V_224 ) &&
! F_116 ( V_13 , V_225 ) )
goto V_108;
if ( V_169 )
F_127 ( V_13 , F_128 ( & V_168 -> V_132 ) ) ;
}
if ( V_162 -> V_173 & V_226 )
goto V_227;
V_228:
V_52 = V_147 -> V_52 ;
if ( ! V_166 . V_201 )
V_59 = V_166 . V_201 = V_147 -> V_59 ;
if ( ! V_171 ) {
V_3 = F_129 ( V_13 , V_147 , F_104 , V_162 , V_164 ,
sizeof( struct V_80 ) , & V_166 , & V_168 ,
V_162 -> V_173 ) ;
V_100 = F_125 ( V_3 ) ;
if ( ! F_130 ( V_3 ) )
V_100 = F_94 ( V_3 , V_147 ) ;
goto V_108;
}
F_105 ( V_13 ) ;
if ( F_60 ( V_128 -> V_129 ) ) {
F_107 ( V_13 ) ;
F_131 ( L_1 ) ;
V_100 = - V_185 ;
goto V_108;
}
V_147 = & V_65 -> V_157 . V_158 . V_159 . V_160 ;
V_147 -> V_59 = V_59 ;
V_147 -> V_52 = V_52 ;
V_147 -> V_150 = V_81 ;
V_147 -> V_229 = V_65 -> V_149 ;
V_128 -> V_129 = V_184 ;
V_186:
V_128 -> V_130 += V_164 ;
V_100 = F_132 ( V_13 , V_147 , F_104 , V_162 , V_164 ,
sizeof( struct V_80 ) , & V_166 , & V_168 ,
V_171 ? V_162 -> V_173 | V_174 : V_162 -> V_173 ) ;
if ( V_100 )
F_78 ( V_13 ) ;
else if ( ! V_171 )
V_100 = F_101 ( V_13 ) ;
else if ( F_60 ( F_133 ( & V_13 -> V_230 ) ) )
V_128 -> V_129 = 0 ;
F_107 ( V_13 ) ;
V_108:
F_134 ( V_168 ) ;
if ( free )
F_110 ( V_166 . V_179 ) ;
if ( ! V_100 )
return V_130 ;
if ( V_100 == - V_154 || F_31 ( V_231 , & V_13 -> V_232 -> V_7 ) ) {
F_100 ( F_9 ( V_13 ) ,
V_155 , V_148 ) ;
}
return V_100 ;
V_227:
if ( V_162 -> V_173 & V_233 )
F_135 ( & V_168 -> V_132 , & V_147 -> V_59 ) ;
if ( ! ( V_162 -> V_173 & V_233 ) || V_130 )
goto V_228;
V_100 = 0 ;
goto V_108;
}
int F_136 ( struct V_12 * V_13 , struct V_234 * V_234 , int V_133 ,
T_8 V_235 , int V_7 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_236 ;
if ( V_7 & V_237 )
V_7 |= V_174 ;
if ( ! V_128 -> V_129 ) {
struct V_161 V_162 = { . V_173 = V_7 | V_174 } ;
V_236 = F_103 ( V_13 , & V_162 , 0 ) ;
if ( V_236 < 0 )
return V_236 ;
}
F_105 ( V_13 ) ;
if ( F_60 ( ! V_128 -> V_129 ) ) {
F_107 ( V_13 ) ;
F_131 ( L_2 ) ;
return - V_185 ;
}
V_236 = F_137 ( V_13 , & V_65 -> V_157 . V_158 . V_159 . V_160 ,
V_234 , V_133 , V_235 , V_7 ) ;
if ( V_236 == - V_178 ) {
F_107 ( V_13 ) ;
return F_138 ( V_13 -> V_232 , V_234 , V_133 ,
V_235 , V_7 ) ;
}
if ( V_236 < 0 ) {
F_78 ( V_13 ) ;
goto V_108;
}
V_128 -> V_130 += V_235 ;
if ( ! ( V_128 -> V_172 || ( V_7 & V_174 ) ) )
V_236 = F_101 ( V_13 ) ;
if ( ! V_236 )
V_236 = V_235 ;
V_108:
F_107 ( V_13 ) ;
return V_236 ;
}
static void F_139 ( struct V_12 * V_13 , int V_235 , int V_238 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_239 ;
if ( F_106 ( V_238 ) ) {
V_128 -> V_240 += V_235 ;
V_235 = V_128 -> V_240 ;
if ( V_235 < ( V_13 -> V_241 >> 2 ) &&
! F_133 ( & V_13 -> V_242 ) )
return;
} else {
V_235 += V_128 -> V_240 ;
}
V_128 -> V_240 = 0 ;
V_13 -> V_243 += V_235 ;
V_239 = ( V_13 -> V_243 - V_238 ) & ~ ( V_244 - 1 ) ;
V_13 -> V_243 -= V_239 ;
if ( V_239 )
F_140 ( V_13 , V_239 >> V_245 ) ;
F_141 ( V_235 , & V_13 -> V_246 ) ;
}
void F_142 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
F_139 ( V_13 , V_3 -> V_247 , 1 ) ;
}
static T_10 * F_143 ( void * V_248 )
{
T_10 * V_249 ;
V_249 = V_250 + F_144 ( V_248 , V_251 ) ;
F_16 ( V_249 ) ;
return V_249 ;
}
static void F_145 ( T_10 * V_249 )
{
if ( V_249 )
F_18 ( V_249 ) ;
}
int F_146 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_252 * V_253 = & V_13 -> V_242 ;
int V_254 , V_255 , V_239 , V_100 = - V_256 ;
T_10 * V_249 = NULL ;
int V_235 ;
V_254 = F_147 ( & V_13 -> V_246 ) ;
if ( V_254 > V_13 -> V_241 )
goto V_257;
if ( V_254 > ( V_13 -> V_241 >> 1 ) ) {
F_148 ( V_3 ) ;
V_249 = F_143 ( V_13 ) ;
}
V_235 = V_3 -> V_258 ;
V_3 -> V_247 = V_235 ;
V_254 = F_149 ( V_235 , & V_13 -> V_246 ) ;
if ( V_254 > ( V_235 + V_13 -> V_241 ) )
goto V_259;
F_16 ( & V_253 -> V_23 ) ;
if ( V_235 >= V_13 -> V_243 ) {
V_239 = F_150 ( V_235 ) ;
V_255 = V_239 << V_245 ;
if ( ! F_151 ( V_13 , V_255 , V_239 , V_260 ) ) {
V_100 = - V_154 ;
F_18 ( & V_253 -> V_23 ) ;
goto V_259;
}
V_13 -> V_243 += V_255 ;
}
V_13 -> V_243 -= V_235 ;
F_152 ( V_13 , V_3 ) ;
F_153 ( V_253 , V_3 ) ;
F_18 ( & V_253 -> V_23 ) ;
if ( ! F_116 ( V_13 , V_261 ) )
V_13 -> V_262 ( V_13 ) ;
F_145 ( V_249 ) ;
return 0 ;
V_259:
F_141 ( V_3 -> V_258 , & V_13 -> V_246 ) ;
V_257:
F_154 ( & V_13 -> V_263 ) ;
F_145 ( V_249 ) ;
return V_100 ;
}
void F_155 ( struct V_12 * V_13 )
{
unsigned int V_264 = 0 ;
struct V_2 * V_3 ;
while ( ( V_3 = F_156 ( & V_13 -> V_242 ) ) != NULL ) {
V_264 += V_3 -> V_258 ;
F_157 ( V_3 ) ;
}
F_139 ( V_13 , V_264 , 0 ) ;
F_158 ( V_13 ) ;
}
int F_159 ( struct V_12 * V_13 )
{
V_13 -> V_265 = F_155 ;
return 0 ;
}
void F_160 ( struct V_12 * V_13 , struct V_2 * V_3 , int V_130 )
{
if ( F_60 ( F_161 ( V_13 -> V_266 ) >= 0 ) ) {
bool V_267 = F_162 ( V_13 ) ;
F_163 ( V_13 , V_130 ) ;
F_164 ( V_13 , V_267 ) ;
}
F_165 ( V_3 ) ;
}
static int F_166 ( struct V_12 * V_13 )
{
struct V_252 * V_268 = & V_13 -> V_242 ;
struct V_2 * V_3 ;
int V_264 = 0 ;
int V_22 ;
F_30 ( & V_268 -> V_23 ) ;
while ( ( V_3 = F_167 ( V_268 ) ) != NULL &&
F_168 ( V_3 ) ) {
F_169 ( F_9 ( V_13 ) , V_269 ,
F_95 ( V_13 ) ) ;
F_169 ( F_9 ( V_13 ) , V_270 ,
F_95 ( V_13 ) ) ;
F_154 ( & V_13 -> V_263 ) ;
F_170 ( V_3 , V_268 ) ;
V_264 += V_3 -> V_258 ;
F_157 ( V_3 ) ;
}
V_22 = V_3 ? V_3 -> V_130 : - 1 ;
if ( V_264 )
F_139 ( V_13 , V_264 , 1 ) ;
F_33 ( & V_268 -> V_23 ) ;
return V_22 ;
}
int F_171 ( struct V_12 * V_13 , int V_271 , unsigned long V_272 )
{
switch ( V_271 ) {
case V_273 :
{
int V_274 = F_172 ( V_13 ) ;
return F_173 ( V_274 , ( int V_275 * ) V_272 ) ;
}
case V_276 :
{
int V_274 = F_174 ( int , 0 , F_166 ( V_13 ) ) ;
return F_173 ( V_274 , ( int V_275 * ) V_272 ) ;
}
default:
return - V_277 ;
}
return 0 ;
}
int F_175 ( struct V_12 * V_13 , struct V_161 * V_162 , T_8 V_130 , int V_278 ,
int V_7 , int * V_279 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
F_108 ( struct V_188 * , sin , V_162 -> V_187 ) ;
struct V_2 * V_3 ;
unsigned int V_164 , V_280 ;
int V_281 , V_282 , V_283 ;
int V_100 ;
int V_148 = F_95 ( V_13 ) ;
bool V_284 = false ;
if ( V_7 & V_285 )
return F_176 ( V_13 , V_162 , V_130 , V_279 ) ;
V_286:
V_282 = V_283 = F_177 ( V_13 , V_7 ) ;
V_3 = F_178 ( V_13 , V_7 , V_278 , & V_281 , & V_283 , & V_100 ) ;
if ( ! V_3 )
return V_100 ;
V_164 = V_3 -> V_130 ;
V_280 = V_130 ;
if ( V_280 > V_164 - V_283 )
V_280 = V_164 - V_283 ;
else if ( V_280 < V_164 )
V_162 -> V_173 |= V_287 ;
if ( V_280 < V_164 || V_282 ||
( V_148 && F_179 ( V_3 ) -> V_288 ) ) {
V_284 = ! F_168 ( V_3 ) ;
if ( ! V_284 )
goto V_289;
}
if ( V_284 || F_180 ( V_3 ) )
V_100 = F_181 ( V_3 , V_283 , V_162 , V_280 ) ;
else {
V_100 = F_182 ( V_3 , V_283 , V_162 ) ;
if ( V_100 == - V_185 )
goto V_289;
}
if ( F_60 ( V_100 ) ) {
if ( ! V_281 ) {
F_154 ( & V_13 -> V_263 ) ;
F_100 ( F_9 ( V_13 ) ,
V_270 , V_148 ) ;
}
F_157 ( V_3 ) ;
return V_100 ;
}
if ( ! V_281 )
F_100 ( F_9 ( V_13 ) ,
V_290 , V_148 ) ;
F_183 ( V_162 , V_13 , V_3 ) ;
if ( sin ) {
sin -> V_191 = V_184 ;
sin -> V_196 = F_81 ( V_3 ) -> V_102 ;
sin -> V_194 . V_195 = F_63 ( V_3 ) -> V_52 ;
memset ( sin -> V_291 , 0 , sizeof( sin -> V_291 ) ) ;
* V_279 = sizeof( * sin ) ;
}
if ( V_65 -> V_292 )
F_184 ( V_162 , V_13 , V_3 , sizeof( struct V_80 ) , V_283 ) ;
V_100 = V_280 ;
if ( V_7 & V_287 )
V_100 = V_164 ;
F_160 ( V_13 , V_3 , V_282 ? - V_100 : V_100 ) ;
return V_100 ;
V_289:
if ( ! F_185 ( V_13 , V_3 , V_7 , F_142 ) ) {
F_100 ( F_9 ( V_13 ) , V_269 , V_148 ) ;
F_100 ( F_9 ( V_13 ) , V_270 , V_148 ) ;
}
F_157 ( V_3 ) ;
F_34 () ;
V_162 -> V_173 &= ~ V_287 ;
goto V_286;
}
int F_186 ( struct V_12 * V_13 , int V_7 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
V_13 -> V_122 = V_293 ;
V_65 -> V_67 = 0 ;
V_65 -> V_68 = 0 ;
F_187 ( V_13 ) ;
V_13 -> V_18 = 0 ;
if ( ! ( V_13 -> V_294 & V_295 ) )
F_188 ( V_13 ) ;
if ( ! ( V_13 -> V_294 & V_296 ) ) {
V_13 -> V_29 -> V_297 ( V_13 ) ;
V_65 -> V_149 = 0 ;
}
F_189 ( V_13 ) ;
return 0 ;
}
int F_190 ( struct V_12 * V_13 , int V_7 )
{
F_105 ( V_13 ) ;
F_186 ( V_13 , V_7 ) ;
F_107 ( V_13 ) ;
return 0 ;
}
void F_191 ( struct V_12 * V_13 )
{
if ( F_192 ( V_13 ) ) {
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
struct V_9 * V_10 , * V_21 ;
V_10 = F_28 ( V_28 , F_9 ( V_13 ) ,
F_10 ( V_13 ) -> V_16 ) ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( F_12 ( V_13 -> V_20 ) )
F_193 ( V_13 ) ;
if ( F_194 ( V_13 ) ) {
V_10 -> V_40 -- ;
F_36 ( V_13 ) -> V_46 = 0 ;
F_39 ( F_9 ( V_13 ) , V_13 -> V_29 , - 1 ) ;
F_16 ( & V_21 -> V_23 ) ;
F_195 ( & F_10 ( V_13 ) -> V_50 ) ;
V_21 -> V_40 -- ;
F_18 ( & V_21 -> V_23 ) ;
}
F_33 ( & V_10 -> V_23 ) ;
}
}
void F_196 ( struct V_12 * V_13 , T_11 V_298 )
{
if ( F_192 ( V_13 ) ) {
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
struct V_9 * V_10 , * V_21 , * V_299 ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
V_299 = F_35 ( V_28 , V_298 ) ;
F_10 ( V_13 ) -> V_43 = V_298 ;
if ( V_21 != V_299 ||
F_12 ( V_13 -> V_20 ) ) {
V_10 = F_28 ( V_28 , F_9 ( V_13 ) ,
F_10 ( V_13 ) -> V_16 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( F_12 ( V_13 -> V_20 ) )
F_193 ( V_13 ) ;
if ( V_21 != V_299 ) {
F_16 ( & V_21 -> V_23 ) ;
F_195 ( & F_10 ( V_13 ) -> V_50 ) ;
V_21 -> V_40 -- ;
F_18 ( & V_21 -> V_23 ) ;
F_16 ( & V_299 -> V_23 ) ;
F_41 ( & F_10 ( V_13 ) -> V_50 ,
& V_299 -> V_47 ) ;
V_299 -> V_40 ++ ;
F_18 ( & V_299 -> V_23 ) ;
}
F_33 ( & V_10 -> V_23 ) ;
}
}
}
static void F_197 ( struct V_12 * V_13 )
{
T_11 V_300 = F_43 ( F_9 ( V_13 ) ,
F_36 ( V_13 ) -> V_57 ,
F_36 ( V_13 ) -> V_46 ) ;
F_196 ( V_13 , V_300 ) ;
}
int F_198 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
int V_301 ;
if ( F_36 ( V_13 ) -> V_67 ) {
F_199 ( V_13 , V_3 ) ;
F_200 ( V_13 , V_3 ) ;
F_201 ( V_13 ) ;
} else {
F_202 ( V_13 , V_3 ) ;
}
V_301 = F_146 ( V_13 , V_3 ) ;
if ( V_301 < 0 ) {
int V_148 = F_95 ( V_13 ) ;
if ( V_301 == - V_256 )
F_100 ( F_9 ( V_13 ) , V_302 ,
V_148 ) ;
F_100 ( F_9 ( V_13 ) , V_270 , V_148 ) ;
F_157 ( V_3 ) ;
F_203 ( V_301 , V_13 ) ;
return - 1 ;
}
return 0 ;
}
void F_204 ( void )
{
if ( ! F_205 ( & V_303 ) )
F_206 ( & V_303 ) ;
}
int F_207 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_148 = F_95 ( V_13 ) ;
if ( ! F_208 ( V_13 , V_304 , V_3 ) )
goto V_257;
F_209 ( V_3 ) ;
if ( F_210 ( & V_303 ) && V_128 -> V_305 ) {
int (* F_211)( struct V_12 * V_13 , struct V_2 * V_3 );
F_211 = F_212 ( V_128 -> F_211 ) ;
if ( F_211 ) {
int V_236 ;
if ( F_168 ( V_3 ) )
goto V_306;
V_236 = F_211 ( V_13 , V_3 ) ;
if ( V_236 <= 0 ) {
F_169 ( F_9 ( V_13 ) ,
V_290 ,
V_148 ) ;
return - V_236 ;
}
}
}
if ( ( V_148 & V_307 ) && F_179 ( V_3 ) -> V_288 ) {
if ( V_128 -> V_308 == 0 ) {
F_131 ( L_3 ,
F_179 ( V_3 ) -> V_309 , V_3 -> V_130 ) ;
goto V_257;
}
if ( F_179 ( V_3 ) -> V_309 < V_128 -> V_308 ) {
F_131 ( L_4 ,
F_179 ( V_3 ) -> V_309 , V_128 -> V_308 ) ;
goto V_257;
}
}
if ( F_12 ( V_13 -> V_310 ) &&
F_168 ( V_3 ) )
goto V_306;
if ( F_213 ( V_13 , V_3 , sizeof( struct V_80 ) ) )
goto V_257;
F_214 ( V_3 ) ;
F_215 ( V_13 , V_3 ) ;
return F_198 ( V_13 , V_3 ) ;
V_306:
F_169 ( F_9 ( V_13 ) , V_269 , V_148 ) ;
V_257:
F_169 ( F_9 ( V_13 ) , V_270 , V_148 ) ;
F_154 ( & V_13 -> V_263 ) ;
F_157 ( V_3 ) ;
return - 1 ;
}
static void F_216 ( struct V_12 * V_13 , struct V_311 * V_132 )
{
struct V_311 * V_312 ;
F_217 ( V_132 ) ;
V_312 = F_218 ( & V_13 -> V_313 , V_132 ) ;
F_219 ( V_312 ) ;
}
static int F_220 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_80 * V_96 ,
T_4 V_52 , T_4 V_59 ,
struct V_27 * V_28 ,
int V_314 )
{
struct V_12 * V_13 , * V_34 = NULL ;
unsigned short V_60 = F_58 ( V_96 -> V_101 ) ;
struct V_9 * V_10 = F_28 ( V_28 , V_1 , V_60 ) ;
unsigned int V_82 = 0 , V_315 = 0 , V_316 = ( V_10 -> V_40 > 10 ) ;
unsigned int V_133 = F_85 ( F_221 ( * V_13 ) , V_317 ) ;
int V_61 = V_3 -> V_88 -> V_103 ;
struct V_318 * V_319 ;
struct V_2 * V_320 ;
if ( V_316 ) {
V_315 = F_43 ( V_1 , F_47 ( V_55 ) , V_60 ) &
V_28 -> V_37 ;
V_82 = F_43 ( V_1 , V_59 , V_60 ) & V_28 -> V_37 ;
V_321:
V_10 = & V_28 -> V_82 [ V_82 ] ;
V_133 = F_85 ( F_221 ( * V_13 ) , V_322 . V_323 ) ;
}
F_222 (sk, node, &hslot->head, offset) {
if ( ! F_69 ( V_1 , V_13 , V_96 -> V_101 , V_59 ,
V_96 -> V_102 , V_52 , V_61 , V_60 ) )
continue;
if ( ! V_34 ) {
V_34 = V_13 ;
continue;
}
V_320 = F_223 ( V_3 , V_324 ) ;
if ( F_60 ( ! V_320 ) ) {
F_154 ( & V_13 -> V_263 ) ;
F_169 ( V_1 , V_302 ,
F_95 ( V_13 ) ) ;
F_169 ( V_1 , V_270 ,
F_95 ( V_13 ) ) ;
continue;
}
if ( F_207 ( V_13 , V_320 ) > 0 )
F_165 ( V_320 ) ;
}
if ( V_316 && V_82 != V_315 ) {
V_82 = V_315 ;
goto V_321;
}
if ( V_34 ) {
if ( F_207 ( V_34 , V_3 ) > 0 )
F_165 ( V_3 ) ;
} else {
F_157 ( V_3 ) ;
F_169 ( V_1 , V_325 ,
V_314 == V_326 ) ;
}
return 0 ;
}
static inline int F_224 ( struct V_2 * V_3 , struct V_80 * V_96 ,
int V_314 )
{
int V_100 ;
F_179 ( V_3 ) -> V_288 = 0 ;
F_179 ( V_3 ) -> V_309 = V_3 -> V_130 ;
if ( V_314 == V_326 ) {
V_100 = F_225 ( V_3 , V_96 ) ;
if ( V_100 )
return V_100 ;
}
return ( V_54 int ) F_226 ( V_3 , V_314 , V_96 -> V_138 ,
V_327 ) ;
}
int F_227 ( struct V_2 * V_3 , struct V_27 * V_28 ,
int V_314 )
{
struct V_12 * V_13 ;
struct V_80 * V_96 ;
unsigned short V_164 ;
struct V_167 * V_168 = F_228 ( V_3 ) ;
T_4 V_52 , V_59 ;
struct V_1 * V_1 = F_64 ( V_3 -> V_88 ) ;
if ( ! F_229 ( V_3 , sizeof( struct V_80 ) ) )
goto V_257;
V_96 = F_81 ( V_3 ) ;
V_164 = F_58 ( V_96 -> V_130 ) ;
V_52 = F_63 ( V_3 ) -> V_52 ;
V_59 = F_63 ( V_3 ) -> V_59 ;
if ( V_164 > V_3 -> V_130 )
goto V_328;
if ( V_314 == V_139 ) {
if ( V_164 < sizeof( * V_96 ) || F_230 ( V_3 , V_164 ) )
goto V_328;
V_96 = F_81 ( V_3 ) ;
}
if ( F_224 ( V_3 , V_96 , V_314 ) )
goto V_306;
V_13 = F_231 ( V_3 ) ;
if ( V_13 ) {
struct V_311 * V_132 = F_232 ( V_3 ) ;
int V_236 ;
if ( F_60 ( V_13 -> V_313 != V_132 ) )
F_216 ( V_13 , V_132 ) ;
V_236 = F_207 ( V_13 , V_3 ) ;
F_233 ( V_13 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( V_168 -> V_223 & ( V_224 | V_329 ) )
return F_220 ( V_1 , V_3 , V_96 ,
V_52 , V_59 , V_28 , V_314 ) ;
V_13 = F_62 ( V_3 , V_96 -> V_102 , V_96 -> V_101 , V_28 ) ;
if ( V_13 ) {
int V_236 ;
if ( F_234 ( V_13 ) && V_96 -> V_138 && ! F_95 ( V_13 ) )
F_235 ( V_3 , V_139 , V_96 -> V_138 ,
V_327 ) ;
V_236 = F_207 ( V_13 , V_3 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( ! F_208 ( NULL , V_304 , V_3 ) )
goto V_257;
F_209 ( V_3 ) ;
if ( F_168 ( V_3 ) )
goto V_306;
F_169 ( V_1 , V_330 , V_314 == V_326 ) ;
F_236 ( V_3 , V_111 , V_331 , 0 ) ;
F_157 ( V_3 ) ;
return 0 ;
V_328:
F_131 ( L_5 ,
V_314 == V_326 ? L_6 : L_7 ,
& V_52 , F_58 ( V_96 -> V_102 ) ,
V_164 , V_3 -> V_130 ,
& V_59 , F_58 ( V_96 -> V_101 ) ) ;
goto V_257;
V_306:
F_131 ( L_8 ,
V_314 == V_326 ? L_6 : L_7 ,
& V_52 , F_58 ( V_96 -> V_102 ) , & V_59 , F_58 ( V_96 -> V_101 ) ,
V_164 ) ;
F_169 ( V_1 , V_269 , V_314 == V_326 ) ;
V_257:
F_169 ( V_1 , V_270 , V_314 == V_326 ) ;
F_157 ( V_3 ) ;
return 0 ;
}
static struct V_12 * F_237 ( struct V_1 * V_1 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_61 )
{
struct V_12 * V_13 , * V_75 ;
unsigned short V_60 = F_58 ( V_90 ) ;
unsigned int V_83 = F_59 ( V_1 , V_60 , V_27 . V_37 ) ;
struct V_9 * V_10 = & V_27 . V_79 [ V_83 ] ;
if ( V_10 -> V_40 > 10 )
return NULL ;
V_75 = NULL ;
F_61 (sk, &hslot->head) {
if ( F_69 ( V_1 , V_13 , V_90 , V_91 ,
V_92 , V_93 , V_61 , V_60 ) ) {
if ( V_75 )
return NULL ;
V_75 = V_13 ;
}
}
return V_75 ;
}
static struct V_12 * F_238 ( struct V_1 * V_1 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_61 )
{
unsigned short V_60 = F_58 ( V_90 ) ;
unsigned int V_82 = F_43 ( V_1 , V_91 , V_60 ) ;
unsigned int V_42 = V_82 & V_27 . V_37 ;
struct V_9 * V_21 = & V_27 . V_82 [ V_42 ] ;
F_239 ( V_332 , V_93 , V_91 ) ;
const T_12 V_333 = F_240 ( V_92 , V_60 ) ;
struct V_12 * V_13 ;
F_54 (sk, &hslot2->head) {
if ( F_241 ( V_13 , V_1 , V_332 , V_93 ,
V_91 , V_333 , V_61 ) )
return V_13 ;
break;
}
return NULL ;
}
void F_242 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_64 ( V_3 -> V_88 ) ;
const struct V_86 * V_87 ;
const struct V_80 * V_96 ;
struct V_12 * V_13 = NULL ;
struct V_311 * V_132 ;
int V_61 = V_3 -> V_88 -> V_103 ;
int V_334 ;
if ( ! F_229 ( V_3 , F_82 ( V_3 ) + sizeof( struct V_80 ) ) )
return;
V_87 = F_63 ( V_3 ) ;
V_96 = F_81 ( V_3 ) ;
if ( V_3 -> V_335 == V_336 ||
V_3 -> V_335 == V_337 ) {
struct V_338 * V_339 = F_243 ( V_3 -> V_88 ) ;
if ( ! V_339 )
return;
if ( V_3 -> V_335 == V_337 ) {
V_334 = F_244 ( V_339 , V_87 -> V_59 , V_87 -> V_52 ,
V_87 -> V_340 ) ;
if ( ! V_334 )
return;
}
V_13 = F_237 ( V_1 , V_96 -> V_101 , V_87 -> V_59 ,
V_96 -> V_102 , V_87 -> V_52 , V_61 ) ;
} else if ( V_3 -> V_335 == V_341 ) {
V_13 = F_238 ( V_1 , V_96 -> V_101 , V_87 -> V_59 ,
V_96 -> V_102 , V_87 -> V_52 , V_61 ) ;
}
if ( ! V_13 || ! F_245 ( & V_13 -> V_89 , 2 ) )
return;
V_3 -> V_13 = V_13 ;
V_3 -> V_342 = V_343 ;
V_132 = F_161 ( V_13 -> V_313 ) ;
if ( V_132 )
V_132 = F_246 ( V_132 , 0 ) ;
if ( V_132 ) {
if ( V_132 -> V_7 & V_344 ) {
if ( F_106 ( F_68 ( & V_132 -> V_345 ) ) )
F_247 ( V_3 , V_132 ) ;
} else {
F_248 ( V_3 , V_132 ) ;
}
}
}
int F_249 ( struct V_2 * V_3 )
{
return F_227 ( V_3 , & V_27 , V_139 ) ;
}
void F_250 ( struct V_12 * V_13 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
bool V_267 = F_162 ( V_13 ) ;
F_78 ( V_13 ) ;
F_164 ( V_13 , V_267 ) ;
if ( F_210 ( & V_303 ) && V_128 -> V_305 ) {
void (* F_251)( struct V_12 * V_13 );
F_251 = F_212 ( V_128 -> F_251 ) ;
if ( F_251 )
F_251 ( V_13 ) ;
}
}
int F_252 ( struct V_12 * V_13 , int V_346 , int V_347 ,
char V_275 * V_348 , unsigned int V_207 ,
int (* F_253)( struct V_12 * ) )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_349 , V_350 ;
int V_100 = 0 ;
int V_148 = F_95 ( V_13 ) ;
if ( V_207 < sizeof( int ) )
return - V_185 ;
if ( F_254 ( V_349 , ( int V_275 * ) V_348 ) )
return - V_351 ;
V_350 = V_349 ? 1 : 0 ;
switch ( V_347 ) {
case V_352 :
if ( V_349 != 0 ) {
V_128 -> V_172 = 1 ;
} else {
V_128 -> V_172 = 0 ;
F_105 ( V_13 ) ;
F_253 ( V_13 ) ;
F_107 ( V_13 ) ;
}
break;
case V_353 :
switch ( V_349 ) {
case 0 :
case V_354 :
case V_355 :
V_128 -> F_211 = V_356 ;
case V_357 :
V_128 -> V_305 = V_349 ;
F_204 () ;
break;
default:
V_100 = - V_358 ;
break;
}
break;
case V_359 :
V_128 -> V_360 = V_350 ;
break;
case V_361 :
V_128 -> V_362 = V_350 ;
break;
case V_363 :
if ( ! V_148 )
return - V_358 ;
if ( V_349 != 0 && V_349 < 8 )
V_349 = 8 ;
else if ( V_349 > V_364 )
V_349 = V_364 ;
V_128 -> V_365 = V_349 ;
V_128 -> V_366 |= V_367 ;
break;
case V_368 :
if ( ! V_148 )
return - V_358 ;
if ( V_349 != 0 && V_349 < 8 )
V_349 = 8 ;
else if ( V_349 > V_364 )
V_349 = V_364 ;
V_128 -> V_308 = V_349 ;
V_128 -> V_366 |= V_307 ;
break;
default:
V_100 = - V_358 ;
break;
}
return V_100 ;
}
int F_255 ( struct V_12 * V_13 , int V_346 , int V_347 ,
char V_275 * V_348 , unsigned int V_207 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_252 ( V_13 , V_346 , V_347 , V_348 , V_207 ,
F_101 ) ;
return F_256 ( V_13 , V_346 , V_347 , V_348 , V_207 ) ;
}
int F_257 ( struct V_12 * V_13 , int V_346 , int V_347 ,
char V_275 * V_348 , unsigned int V_207 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_252 ( V_13 , V_346 , V_347 , V_348 , V_207 ,
F_101 ) ;
return F_258 ( V_13 , V_346 , V_347 , V_348 , V_207 ) ;
}
int F_259 ( struct V_12 * V_13 , int V_346 , int V_347 ,
char V_275 * V_348 , int V_275 * V_207 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_349 , V_130 ;
if ( F_254 ( V_130 , V_207 ) )
return - V_351 ;
V_130 = F_260 (unsigned int, len, sizeof(int)) ;
if ( V_130 < 0 )
return - V_185 ;
switch ( V_347 ) {
case V_352 :
V_349 = V_128 -> V_172 ;
break;
case V_353 :
V_349 = V_128 -> V_305 ;
break;
case V_359 :
V_349 = V_128 -> V_360 ;
break;
case V_361 :
V_349 = V_128 -> V_362 ;
break;
case V_363 :
V_349 = V_128 -> V_365 ;
break;
case V_368 :
V_349 = V_128 -> V_308 ;
break;
default:
return - V_358 ;
}
if ( F_173 ( V_130 , V_207 ) )
return - V_351 ;
if ( F_261 ( V_348 , & V_349 , V_130 ) )
return - V_351 ;
return 0 ;
}
int F_262 ( struct V_12 * V_13 , int V_346 , int V_347 ,
char V_275 * V_348 , int V_275 * V_207 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_259 ( V_13 , V_346 , V_347 , V_348 , V_207 ) ;
return F_263 ( V_13 , V_346 , V_347 , V_348 , V_207 ) ;
}
int F_264 ( struct V_12 * V_13 , int V_346 , int V_347 ,
char V_275 * V_348 , int V_275 * V_207 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_259 ( V_13 , V_346 , V_347 , V_348 , V_207 ) ;
return F_265 ( V_13 , V_346 , V_347 , V_348 , V_207 ) ;
}
unsigned int F_266 ( struct V_371 * V_371 , struct V_372 * V_12 , T_13 * V_373 )
{
unsigned int V_37 = F_267 ( V_371 , V_12 , V_373 ) ;
struct V_12 * V_13 = V_12 -> V_13 ;
F_268 ( V_13 ) ;
if ( ( V_37 & V_374 ) && ! ( V_371 -> V_375 & V_376 ) &&
! ( V_13 -> V_377 & V_378 ) && F_166 ( V_13 ) == - 1 )
V_37 &= ~ ( V_379 | V_374 ) ;
return V_37 ;
}
int F_269 ( struct V_12 * V_13 , int V_100 )
{
F_105 ( V_13 ) ;
V_13 -> V_125 = V_100 ;
V_13 -> V_126 ( V_13 ) ;
F_186 ( V_13 , 0 ) ;
F_107 ( V_13 ) ;
return 0 ;
}
static struct V_12 * F_270 ( struct V_380 * V_381 , int V_382 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 = V_381 -> V_385 ;
struct V_1 * V_1 = F_271 ( V_381 ) ;
for ( V_384 -> V_386 = V_382 ; V_384 -> V_386 <= V_384 -> V_27 -> V_37 ;
++ V_384 -> V_386 ) {
struct V_9 * V_10 = & V_384 -> V_27 -> V_79 [ V_384 -> V_386 ] ;
if ( F_272 ( & V_10 -> V_47 ) )
continue;
F_30 ( & V_10 -> V_23 ) ;
F_7 (sk, &hslot->head) {
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) )
continue;
if ( V_13 -> V_24 == V_384 -> V_387 )
goto V_38;
}
F_33 ( & V_10 -> V_23 ) ;
}
V_13 = NULL ;
V_38:
return V_13 ;
}
static struct V_12 * F_273 ( struct V_380 * V_381 , struct V_12 * V_13 )
{
struct V_383 * V_384 = V_381 -> V_385 ;
struct V_1 * V_1 = F_271 ( V_381 ) ;
do {
V_13 = F_274 ( V_13 ) ;
} while ( V_13 && ( ! F_8 ( F_9 ( V_13 ) , V_1 ) || V_13 -> V_24 != V_384 -> V_387 ) );
if ( ! V_13 ) {
if ( V_384 -> V_386 <= V_384 -> V_27 -> V_37 )
F_33 ( & V_384 -> V_27 -> V_79 [ V_384 -> V_386 ] . V_23 ) ;
return F_270 ( V_381 , V_384 -> V_386 + 1 ) ;
}
return V_13 ;
}
static struct V_12 * F_275 ( struct V_380 * V_381 , T_14 V_388 )
{
struct V_12 * V_13 = F_270 ( V_381 , 0 ) ;
if ( V_13 )
while ( V_388 && ( V_13 = F_273 ( V_381 , V_13 ) ) != NULL )
-- V_388 ;
return V_388 ? NULL : V_13 ;
}
static void * F_276 ( struct V_380 * V_381 , T_14 * V_388 )
{
struct V_383 * V_384 = V_381 -> V_385 ;
V_384 -> V_386 = V_389 ;
return * V_388 ? F_275 ( V_381 , * V_388 - 1 ) : V_390 ;
}
static void * F_277 ( struct V_380 * V_381 , void * V_391 , T_14 * V_388 )
{
struct V_12 * V_13 ;
if ( V_391 == V_390 )
V_13 = F_275 ( V_381 , 0 ) ;
else
V_13 = F_273 ( V_381 , V_391 ) ;
++ * V_388 ;
return V_13 ;
}
static void F_278 ( struct V_380 * V_381 , void * V_391 )
{
struct V_383 * V_384 = V_381 -> V_385 ;
if ( V_384 -> V_386 <= V_384 -> V_27 -> V_37 )
F_33 ( & V_384 -> V_27 -> V_79 [ V_384 -> V_386 ] . V_23 ) ;
}
int F_279 ( struct V_392 * V_392 , struct V_371 * V_371 )
{
struct V_393 * V_394 = F_280 ( V_392 ) ;
struct V_383 * V_395 ;
int V_100 ;
V_100 = F_281 ( V_392 , V_371 , & V_394 -> V_396 ,
sizeof( struct V_383 ) ) ;
if ( V_100 < 0 )
return V_100 ;
V_395 = ( (struct V_380 * ) V_371 -> V_397 ) -> V_385 ;
V_395 -> V_387 = V_394 -> V_387 ;
V_395 -> V_27 = V_394 -> V_27 ;
return V_100 ;
}
int F_282 ( struct V_1 * V_1 , struct V_393 * V_394 )
{
struct V_398 * V_399 ;
int V_301 = 0 ;
V_394 -> V_396 . V_382 = F_276 ;
V_394 -> V_396 . V_400 = F_277 ;
V_394 -> V_396 . V_401 = F_278 ;
V_399 = F_283 ( V_394 -> V_402 , V_403 , V_1 -> V_404 ,
V_394 -> V_405 , V_394 ) ;
if ( ! V_399 )
V_301 = - V_256 ;
return V_301 ;
}
void F_284 ( struct V_1 * V_1 , struct V_393 * V_394 )
{
F_285 ( V_394 -> V_402 , V_1 -> V_404 ) ;
}
static void F_286 ( struct V_12 * V_406 , struct V_380 * V_407 ,
int V_386 )
{
struct V_64 * V_65 = F_36 ( V_406 ) ;
T_4 V_101 = V_65 -> V_67 ;
T_4 V_131 = V_65 -> V_57 ;
T_1 V_408 = F_58 ( V_65 -> V_68 ) ;
T_1 V_409 = F_58 ( V_65 -> V_149 ) ;
F_287 ( V_407 , L_9
L_10 ,
V_386 , V_131 , V_409 , V_101 , V_408 , V_406 -> V_122 ,
F_172 ( V_406 ) ,
F_288 ( V_406 ) ,
0 , 0L , 0 ,
F_289 ( F_290 ( V_407 ) , F_6 ( V_406 ) ) ,
0 , F_291 ( V_406 ) ,
F_147 ( & V_406 -> V_89 ) , V_406 ,
F_147 ( & V_406 -> V_263 ) ) ;
}
int F_292 ( struct V_380 * V_381 , void * V_391 )
{
F_293 ( V_381 , 127 ) ;
if ( V_391 == V_390 )
F_294 ( V_381 , L_11
L_12
L_13 ) ;
else {
struct V_383 * V_384 = V_381 -> V_385 ;
F_286 ( V_391 , V_381 , V_384 -> V_386 ) ;
}
F_295 ( V_381 , '\n' ) ;
return 0 ;
}
static int T_15 F_296 ( struct V_1 * V_1 )
{
return F_282 ( V_1 , & V_410 ) ;
}
static void T_16 F_297 ( struct V_1 * V_1 )
{
F_284 ( V_1 , & V_410 ) ;
}
int T_17 F_298 ( void )
{
return F_299 ( & V_411 ) ;
}
void F_300 ( void )
{
F_301 ( & V_411 ) ;
}
static int T_17 F_302 ( char * V_412 )
{
T_18 V_236 ;
if ( ! V_412 )
return 0 ;
V_236 = F_303 ( V_412 , 0 , & V_413 ) ;
if ( V_236 )
return 0 ;
if ( V_413 && V_413 < V_414 )
V_413 = V_414 ;
return 1 ;
}
void T_17 F_304 ( struct V_27 * V_415 , const char * V_402 )
{
unsigned int V_416 ;
V_415 -> V_79 = F_305 ( V_402 ,
2 * sizeof( struct V_9 ) ,
V_413 ,
21 ,
0 ,
& V_415 -> log ,
& V_415 -> V_37 ,
V_414 ,
64 * 1024 ) ;
V_415 -> V_82 = V_415 -> V_79 + ( V_415 -> V_37 + 1 ) ;
for ( V_416 = 0 ; V_416 <= V_415 -> V_37 ; V_416 ++ ) {
F_306 ( & V_415 -> V_79 [ V_416 ] . V_47 ) ;
V_415 -> V_79 [ V_416 ] . V_40 = 0 ;
F_307 ( & V_415 -> V_79 [ V_416 ] . V_23 ) ;
}
for ( V_416 = 0 ; V_416 <= V_415 -> V_37 ; V_416 ++ ) {
F_306 ( & V_415 -> V_82 [ V_416 ] . V_47 ) ;
V_415 -> V_82 [ V_416 ] . V_40 = 0 ;
F_307 ( & V_415 -> V_82 [ V_416 ] . V_23 ) ;
}
}
T_3 F_308 ( void )
{
static T_3 T_19 V_74 ;
F_51 ( & T_19 , sizeof( T_19 ) ) ;
return T_19 ;
}
void T_17 F_309 ( void )
{
unsigned long V_417 ;
unsigned int V_416 ;
F_304 ( & V_27 , L_14 ) ;
V_417 = F_310 () / 8 ;
V_417 = F_311 ( V_417 , 128UL ) ;
V_418 [ 0 ] = V_417 / 4 * 3 ;
V_418 [ 1 ] = V_417 ;
V_418 [ 2 ] = V_418 [ 0 ] * 2 ;
V_419 = V_244 ;
V_420 = V_244 ;
V_251 = F_312 ( V_421 ) + 4 ;
V_250 = F_313 ( sizeof( T_10 ) << V_251 ,
V_422 ) ;
if ( ! V_250 )
F_314 ( L_15 ) ;
for ( V_416 = 0 ; V_416 < ( 1U << V_251 ) ; V_416 ++ )
F_307 ( V_250 + V_416 ) ;
}
