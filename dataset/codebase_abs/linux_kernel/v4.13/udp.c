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
else if ( V_13 -> V_151 && ! F_91 ( V_3 ) ) {
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
static void F_139 ( struct V_2 * V_3 )
{
struct V_238 * V_239 = F_140 ( V_3 ) ;
F_141 ( sizeof( struct V_238 ) > sizeof( long ) ) ;
V_239 -> V_240 = V_3 -> V_241 ;
#if V_242 == 64
V_239 -> V_130 = V_3 -> V_130 ;
V_239 -> V_243 = ! ! F_142 ( V_3 ) ;
V_239 -> V_244 = ! F_143 ( V_3 ) ;
#endif
if ( F_106 ( ! V_3 -> V_245 && ! F_144 ( V_3 ) ) )
V_239 -> V_240 |= V_246 ;
}
static int F_145 ( struct V_2 * V_3 )
{
return F_140 ( V_3 ) -> V_240 & ~ V_246 ;
}
static bool F_146 ( struct V_2 * V_3 )
{
return ! ( F_140 ( V_3 ) -> V_240 & V_246 ) ;
}
static void F_147 ( struct V_12 * V_13 , int V_235 , int V_247 ,
bool V_248 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
struct V_249 * V_250 ;
int V_251 ;
if ( F_106 ( V_247 ) ) {
V_128 -> V_252 += V_235 ;
V_235 = V_128 -> V_252 ;
if ( V_235 < ( V_13 -> V_253 >> 2 ) &&
! F_133 ( & V_128 -> V_254 ) )
return;
} else {
V_235 += V_128 -> V_252 ;
}
V_128 -> V_252 = 0 ;
V_250 = & V_13 -> V_255 ;
if ( ! V_248 )
F_16 ( & V_250 -> V_23 ) ;
V_13 -> V_256 += V_235 ;
V_251 = ( V_13 -> V_256 - V_247 ) & ~ ( V_257 - 1 ) ;
V_13 -> V_256 -= V_251 ;
if ( V_251 )
F_148 ( V_13 , V_251 >> V_258 ) ;
F_149 ( V_235 , & V_13 -> V_259 ) ;
F_150 ( V_250 , & V_128 -> V_254 ) ;
if ( ! V_248 )
F_18 ( & V_250 -> V_23 ) ;
}
void F_151 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
F_152 ( & V_3 -> V_95 ) ;
F_147 ( V_13 , F_145 ( V_3 ) , 1 , false ) ;
}
static void F_153 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
F_152 ( & V_3 -> V_95 ) ;
F_147 ( V_13 , F_145 ( V_3 ) , 1 , true ) ;
}
static T_10 * F_154 ( void * V_260 )
{
T_10 * V_261 ;
V_261 = V_262 + F_155 ( V_260 , V_263 ) ;
F_16 ( V_261 ) ;
return V_261 ;
}
static void F_156 ( T_10 * V_261 )
{
if ( V_261 )
F_18 ( V_261 ) ;
}
int F_157 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_249 * V_264 = & V_13 -> V_255 ;
int V_265 , V_266 , V_251 , V_100 = - V_267 ;
T_10 * V_261 = NULL ;
int V_235 ;
V_265 = F_158 ( & V_13 -> V_259 ) ;
if ( V_265 > V_13 -> V_253 )
goto V_268;
if ( V_265 > ( V_13 -> V_253 >> 1 ) ) {
F_159 ( V_3 ) ;
V_261 = F_154 ( V_13 ) ;
}
V_235 = V_3 -> V_241 ;
F_139 ( V_3 ) ;
V_265 = F_160 ( V_235 , & V_13 -> V_259 ) ;
if ( V_265 > ( V_235 + V_13 -> V_253 ) )
goto V_269;
F_16 ( & V_264 -> V_23 ) ;
if ( V_235 >= V_13 -> V_256 ) {
V_251 = F_161 ( V_235 ) ;
V_266 = V_251 << V_258 ;
if ( ! F_162 ( V_13 , V_266 , V_251 , V_270 ) ) {
V_100 = - V_154 ;
F_18 ( & V_264 -> V_23 ) ;
goto V_269;
}
V_13 -> V_256 += V_266 ;
}
V_13 -> V_256 -= V_235 ;
F_163 ( V_13 , V_3 ) ;
F_164 ( V_264 , V_3 ) ;
F_18 ( & V_264 -> V_23 ) ;
if ( ! F_116 ( V_13 , V_271 ) )
V_13 -> V_272 ( V_13 ) ;
F_156 ( V_261 ) ;
return 0 ;
V_269:
F_149 ( V_3 -> V_241 , & V_13 -> V_259 ) ;
V_268:
F_165 ( & V_13 -> V_273 ) ;
F_156 ( V_261 ) ;
return V_100 ;
}
void F_166 ( struct V_12 * V_13 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
unsigned int V_274 = 0 ;
struct V_2 * V_3 ;
F_150 ( & V_13 -> V_255 , & V_128 -> V_254 ) ;
while ( ( V_3 = F_167 ( & V_128 -> V_254 ) ) != NULL ) {
V_274 += V_3 -> V_241 ;
F_168 ( V_3 ) ;
}
F_147 ( V_13 , V_274 , 0 , true ) ;
F_169 ( V_13 ) ;
}
int F_170 ( struct V_12 * V_13 )
{
F_171 ( & F_10 ( V_13 ) -> V_254 ) ;
V_13 -> V_275 = F_166 ;
return 0 ;
}
void F_172 ( struct V_12 * V_13 , struct V_2 * V_3 , int V_130 )
{
if ( F_60 ( F_173 ( V_13 -> V_276 ) >= 0 ) ) {
bool V_277 = F_174 ( V_13 ) ;
F_175 ( V_13 , V_130 ) ;
F_176 ( V_13 , V_277 ) ;
}
if ( F_60 ( F_146 ( V_3 ) ) )
F_177 ( V_3 ) ;
F_178 ( V_3 ) ;
}
static struct V_2 * F_179 ( struct V_12 * V_13 ,
struct V_249 * V_278 ,
int * V_274 )
{
struct V_2 * V_3 ;
while ( ( V_3 = F_180 ( V_278 ) ) != NULL ) {
if ( F_181 ( V_3 ) ) {
F_182 ( F_9 ( V_13 ) , V_279 ,
F_95 ( V_13 ) ) ;
F_182 ( F_9 ( V_13 ) , V_280 ,
F_95 ( V_13 ) ) ;
F_165 ( & V_13 -> V_273 ) ;
F_183 ( V_3 , V_278 ) ;
* V_274 += V_3 -> V_241 ;
F_168 ( V_3 ) ;
} else {
F_139 ( V_3 ) ;
break;
}
}
return V_3 ;
}
static int F_184 ( struct V_12 * V_13 )
{
struct V_249 * V_278 = & F_10 ( V_13 ) -> V_254 ;
struct V_249 * V_250 = & V_13 -> V_255 ;
struct V_2 * V_3 ;
int V_274 = 0 ;
int V_22 ;
F_30 ( & V_278 -> V_23 ) ;
V_3 = F_179 ( V_13 , V_278 , & V_274 ) ;
if ( ! V_3 && ! F_133 ( V_250 ) ) {
F_16 ( & V_250 -> V_23 ) ;
F_150 ( V_250 , V_278 ) ;
F_18 ( & V_250 -> V_23 ) ;
V_3 = F_179 ( V_13 , V_278 , & V_274 ) ;
}
V_22 = V_3 ? V_3 -> V_130 : - 1 ;
if ( V_274 )
F_147 ( V_13 , V_274 , 1 , false ) ;
F_33 ( & V_278 -> V_23 ) ;
return V_22 ;
}
int F_185 ( struct V_12 * V_13 , int V_281 , unsigned long V_282 )
{
switch ( V_281 ) {
case V_283 :
{
int V_284 = F_186 ( V_13 ) ;
return F_187 ( V_284 , ( int V_285 * ) V_282 ) ;
}
case V_286 :
{
int V_284 = F_188 ( int , 0 , F_184 ( V_13 ) ) ;
return F_187 ( V_284 , ( int V_285 * ) V_282 ) ;
}
default:
return - V_287 ;
}
return 0 ;
}
struct V_2 * F_189 ( struct V_12 * V_13 , unsigned int V_7 ,
int V_288 , int * V_289 , int * V_290 , int * V_100 )
{
struct V_249 * V_250 = & V_13 -> V_255 ;
struct V_249 * V_291 ;
struct V_2 * V_35 ;
long V_292 ;
int error ;
V_291 = & F_10 ( V_13 ) -> V_254 ;
V_7 |= V_288 ? V_293 : 0 ;
V_292 = F_190 ( V_13 , V_7 & V_293 ) ;
do {
struct V_2 * V_3 ;
error = F_191 ( V_13 ) ;
if ( error )
break;
error = - V_294 ;
* V_289 = 0 ;
do {
F_30 ( & V_291 -> V_23 ) ;
V_3 = F_192 ( V_13 , V_291 , V_7 ,
F_151 ,
V_289 , V_290 , V_100 ,
& V_35 ) ;
if ( V_3 ) {
F_33 ( & V_291 -> V_23 ) ;
return V_3 ;
}
if ( F_133 ( V_250 ) ) {
F_33 ( & V_291 -> V_23 ) ;
goto V_295;
}
F_16 ( & V_250 -> V_23 ) ;
F_150 ( V_250 , V_291 ) ;
V_3 = F_192 ( V_13 , V_291 , V_7 ,
F_153 ,
V_289 , V_290 , V_100 ,
& V_35 ) ;
F_18 ( & V_250 -> V_23 ) ;
F_33 ( & V_291 -> V_23 ) ;
if ( V_3 )
return V_3 ;
V_295:
if ( ! F_193 ( V_13 ) )
break;
F_194 ( V_13 , V_7 & V_293 ) ;
} while ( ! F_133 ( V_250 ) );
} while ( V_292 &&
! F_195 ( V_13 , & error , & V_292 ,
(struct V_2 * ) V_250 ) );
* V_100 = error ;
return NULL ;
}
int F_196 ( struct V_12 * V_13 , struct V_161 * V_162 , T_8 V_130 , int V_288 ,
int V_7 , int * V_296 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
F_108 ( struct V_188 * , sin , V_162 -> V_187 ) ;
struct V_2 * V_3 ;
unsigned int V_164 , V_297 ;
int V_289 , V_298 , V_290 ;
int V_100 ;
int V_148 = F_95 ( V_13 ) ;
bool V_299 = false ;
if ( V_7 & V_300 )
return F_197 ( V_13 , V_162 , V_130 , V_296 ) ;
V_301:
V_298 = V_7 & V_302 ;
V_290 = F_198 ( V_13 , V_7 ) ;
V_3 = F_189 ( V_13 , V_7 , V_288 , & V_289 , & V_290 , & V_100 ) ;
if ( ! V_3 )
return V_100 ;
V_164 = F_199 ( V_3 ) ;
V_297 = V_130 ;
if ( V_297 > V_164 - V_290 )
V_297 = V_164 - V_290 ;
else if ( V_297 < V_164 )
V_162 -> V_173 |= V_303 ;
if ( V_297 < V_164 || V_298 ||
( V_148 && F_200 ( V_3 ) -> V_304 ) ) {
V_299 = F_201 ( V_3 ) ||
! F_202 ( V_3 ) ;
if ( ! V_299 )
goto V_305;
}
if ( V_299 || F_201 ( V_3 ) ) {
if ( F_203 ( V_3 ) )
V_100 = F_204 ( V_3 , V_297 , V_290 , & V_162 -> V_306 ) ;
else
V_100 = F_205 ( V_3 , V_290 , V_162 , V_297 ) ;
} else {
V_100 = F_206 ( V_3 , V_290 , V_162 ) ;
if ( V_100 == - V_185 )
goto V_305;
}
if ( F_60 ( V_100 ) ) {
if ( ! V_289 ) {
F_165 ( & V_13 -> V_273 ) ;
F_100 ( F_9 ( V_13 ) ,
V_280 , V_148 ) ;
}
F_168 ( V_3 ) ;
return V_100 ;
}
if ( ! V_289 )
F_100 ( F_9 ( V_13 ) ,
V_307 , V_148 ) ;
F_207 ( V_162 , V_13 , V_3 ) ;
if ( sin ) {
sin -> V_191 = V_184 ;
sin -> V_196 = F_81 ( V_3 ) -> V_102 ;
sin -> V_194 . V_195 = F_63 ( V_3 ) -> V_52 ;
memset ( sin -> V_308 , 0 , sizeof( sin -> V_308 ) ) ;
* V_296 = sizeof( * sin ) ;
}
if ( V_65 -> V_309 )
F_208 ( V_162 , V_13 , V_3 , sizeof( struct V_80 ) , V_290 ) ;
V_100 = V_297 ;
if ( V_7 & V_303 )
V_100 = V_164 ;
F_172 ( V_13 , V_3 , V_298 ? - V_100 : V_100 ) ;
return V_100 ;
V_305:
if ( ! F_209 ( V_13 , & F_10 ( V_13 ) -> V_254 , V_3 , V_7 ,
F_151 ) ) {
F_100 ( F_9 ( V_13 ) , V_279 , V_148 ) ;
F_100 ( F_9 ( V_13 ) , V_280 , V_148 ) ;
}
F_168 ( V_3 ) ;
F_34 () ;
V_162 -> V_173 &= ~ V_303 ;
goto V_301;
}
int F_210 ( struct V_12 * V_13 , int V_7 )
{
struct V_64 * V_65 = F_36 ( V_13 ) ;
V_13 -> V_122 = V_310 ;
V_65 -> V_67 = 0 ;
V_65 -> V_68 = 0 ;
F_211 ( V_13 ) ;
V_13 -> V_18 = 0 ;
if ( ! ( V_13 -> V_311 & V_312 ) )
F_212 ( V_13 ) ;
if ( ! ( V_13 -> V_311 & V_313 ) ) {
V_13 -> V_29 -> V_314 ( V_13 ) ;
V_65 -> V_149 = 0 ;
}
F_213 ( V_13 ) ;
return 0 ;
}
int F_214 ( struct V_12 * V_13 , int V_7 )
{
F_105 ( V_13 ) ;
F_210 ( V_13 , V_7 ) ;
F_107 ( V_13 ) ;
return 0 ;
}
void F_215 ( struct V_12 * V_13 )
{
if ( F_216 ( V_13 ) ) {
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
struct V_9 * V_10 , * V_21 ;
V_10 = F_28 ( V_28 , F_9 ( V_13 ) ,
F_10 ( V_13 ) -> V_16 ) ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( F_12 ( V_13 -> V_20 ) )
F_217 ( V_13 ) ;
if ( F_218 ( V_13 ) ) {
V_10 -> V_40 -- ;
F_36 ( V_13 ) -> V_46 = 0 ;
F_39 ( F_9 ( V_13 ) , V_13 -> V_29 , - 1 ) ;
F_16 ( & V_21 -> V_23 ) ;
F_219 ( & F_10 ( V_13 ) -> V_50 ) ;
V_21 -> V_40 -- ;
F_18 ( & V_21 -> V_23 ) ;
}
F_33 ( & V_10 -> V_23 ) ;
}
}
void F_220 ( struct V_12 * V_13 , T_11 V_315 )
{
if ( F_216 ( V_13 ) ) {
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
struct V_9 * V_10 , * V_21 , * V_316 ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
V_316 = F_35 ( V_28 , V_315 ) ;
F_10 ( V_13 ) -> V_43 = V_315 ;
if ( V_21 != V_316 ||
F_12 ( V_13 -> V_20 ) ) {
V_10 = F_28 ( V_28 , F_9 ( V_13 ) ,
F_10 ( V_13 ) -> V_16 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( F_12 ( V_13 -> V_20 ) )
F_217 ( V_13 ) ;
if ( V_21 != V_316 ) {
F_16 ( & V_21 -> V_23 ) ;
F_219 ( & F_10 ( V_13 ) -> V_50 ) ;
V_21 -> V_40 -- ;
F_18 ( & V_21 -> V_23 ) ;
F_16 ( & V_316 -> V_23 ) ;
F_41 ( & F_10 ( V_13 ) -> V_50 ,
& V_316 -> V_47 ) ;
V_316 -> V_40 ++ ;
F_18 ( & V_316 -> V_23 ) ;
}
F_33 ( & V_10 -> V_23 ) ;
}
}
}
static void F_221 ( struct V_12 * V_13 )
{
T_11 V_317 = F_43 ( F_9 ( V_13 ) ,
F_36 ( V_13 ) -> V_57 ,
F_36 ( V_13 ) -> V_46 ) ;
F_220 ( V_13 , V_317 ) ;
}
static int F_222 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
int V_318 ;
if ( F_36 ( V_13 ) -> V_67 ) {
F_223 ( V_13 , V_3 ) ;
F_224 ( V_13 , V_3 ) ;
F_225 ( V_13 ) ;
} else {
F_226 ( V_13 , V_3 ) ;
}
if ( F_106 ( F_4 ( V_3 ) -> V_179 . V_207 == 0 && ! F_144 ( V_3 ) ) )
F_177 ( V_3 ) ;
V_318 = F_157 ( V_13 , V_3 ) ;
if ( V_318 < 0 ) {
int V_148 = F_95 ( V_13 ) ;
if ( V_318 == - V_267 )
F_100 ( F_9 ( V_13 ) , V_319 ,
V_148 ) ;
F_100 ( F_9 ( V_13 ) , V_280 , V_148 ) ;
F_168 ( V_3 ) ;
F_227 ( V_318 , V_13 ) ;
return - 1 ;
}
return 0 ;
}
void F_228 ( void )
{
if ( ! F_229 ( & V_320 ) )
F_230 ( & V_320 ) ;
}
static int F_231 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_148 = F_95 ( V_13 ) ;
if ( ! F_232 ( V_13 , V_321 , V_3 ) )
goto V_268;
F_233 ( V_3 ) ;
if ( F_234 ( & V_320 ) && V_128 -> V_322 ) {
int (* F_235)( struct V_12 * V_13 , struct V_2 * V_3 );
F_235 = F_236 ( V_128 -> F_235 ) ;
if ( F_235 ) {
int V_236 ;
if ( F_181 ( V_3 ) )
goto V_323;
V_236 = F_235 ( V_13 , V_3 ) ;
if ( V_236 <= 0 ) {
F_182 ( F_9 ( V_13 ) ,
V_307 ,
V_148 ) ;
return - V_236 ;
}
}
}
if ( ( V_148 & V_324 ) && F_200 ( V_3 ) -> V_304 ) {
if ( V_128 -> V_325 == 0 ) {
F_131 ( L_3 ,
F_200 ( V_3 ) -> V_326 , V_3 -> V_130 ) ;
goto V_268;
}
if ( F_200 ( V_3 ) -> V_326 < V_128 -> V_325 ) {
F_131 ( L_4 ,
F_200 ( V_3 ) -> V_326 , V_128 -> V_325 ) ;
goto V_268;
}
}
F_152 ( & V_13 -> V_259 ) ;
if ( F_12 ( V_13 -> V_327 ) &&
F_181 ( V_3 ) )
goto V_323;
if ( F_237 ( V_13 , V_3 , sizeof( struct V_80 ) ) )
goto V_268;
F_238 ( V_3 ) ;
F_239 ( V_13 , V_3 ) ;
return F_222 ( V_13 , V_3 ) ;
V_323:
F_182 ( F_9 ( V_13 ) , V_279 , V_148 ) ;
V_268:
F_182 ( F_9 ( V_13 ) , V_280 , V_148 ) ;
F_165 ( & V_13 -> V_273 ) ;
F_168 ( V_3 ) ;
return - 1 ;
}
bool F_240 ( struct V_12 * V_13 , struct V_328 * V_132 )
{
struct V_328 * V_329 ;
if ( F_241 ( V_132 ) ) {
V_329 = F_242 ( & V_13 -> V_330 , V_132 ) ;
F_243 ( V_329 ) ;
return V_329 != V_132 ;
}
return false ;
}
static int F_244 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_80 * V_96 ,
T_4 V_52 , T_4 V_59 ,
struct V_27 * V_28 ,
int V_331 )
{
struct V_12 * V_13 , * V_34 = NULL ;
unsigned short V_60 = F_58 ( V_96 -> V_101 ) ;
struct V_9 * V_10 = F_28 ( V_28 , V_1 , V_60 ) ;
unsigned int V_82 = 0 , V_332 = 0 , V_333 = ( V_10 -> V_40 > 10 ) ;
unsigned int V_133 = F_85 ( F_245 ( * V_13 ) , V_334 ) ;
int V_61 = V_3 -> V_88 -> V_103 ;
struct V_335 * V_336 ;
struct V_2 * V_337 ;
if ( V_333 ) {
V_332 = F_43 ( V_1 , F_47 ( V_55 ) , V_60 ) &
V_28 -> V_37 ;
V_82 = F_43 ( V_1 , V_59 , V_60 ) & V_28 -> V_37 ;
V_338:
V_10 = & V_28 -> V_82 [ V_82 ] ;
V_133 = F_85 ( F_245 ( * V_13 ) , V_339 . V_340 ) ;
}
F_246 (sk, node, &hslot->head, offset) {
if ( ! F_69 ( V_1 , V_13 , V_96 -> V_101 , V_59 ,
V_96 -> V_102 , V_52 , V_61 , V_60 ) )
continue;
if ( ! V_34 ) {
V_34 = V_13 ;
continue;
}
V_337 = F_247 ( V_3 , V_341 ) ;
if ( F_60 ( ! V_337 ) ) {
F_165 ( & V_13 -> V_273 ) ;
F_182 ( V_1 , V_319 ,
F_95 ( V_13 ) ) ;
F_182 ( V_1 , V_280 ,
F_95 ( V_13 ) ) ;
continue;
}
if ( F_231 ( V_13 , V_337 ) > 0 )
F_248 ( V_337 ) ;
}
if ( V_333 && V_82 != V_332 ) {
V_82 = V_332 ;
goto V_338;
}
if ( V_34 ) {
if ( F_231 ( V_34 , V_3 ) > 0 )
F_248 ( V_3 ) ;
} else {
F_168 ( V_3 ) ;
F_182 ( V_1 , V_342 ,
V_331 == V_343 ) ;
}
return 0 ;
}
static inline int F_249 ( struct V_2 * V_3 , struct V_80 * V_96 ,
int V_331 )
{
int V_100 ;
F_200 ( V_3 ) -> V_304 = 0 ;
F_200 ( V_3 ) -> V_326 = V_3 -> V_130 ;
if ( V_331 == V_343 ) {
V_100 = F_250 ( V_3 , V_96 ) ;
if ( V_100 )
return V_100 ;
}
return ( V_54 int ) F_251 ( V_3 , V_331 , V_96 -> V_138 ,
V_344 ) ;
}
int F_252 ( struct V_2 * V_3 , struct V_27 * V_28 ,
int V_331 )
{
struct V_12 * V_13 ;
struct V_80 * V_96 ;
unsigned short V_164 ;
struct V_167 * V_168 = F_253 ( V_3 ) ;
T_4 V_52 , V_59 ;
struct V_1 * V_1 = F_64 ( V_3 -> V_88 ) ;
if ( ! F_254 ( V_3 , sizeof( struct V_80 ) ) )
goto V_268;
V_96 = F_81 ( V_3 ) ;
V_164 = F_58 ( V_96 -> V_130 ) ;
V_52 = F_63 ( V_3 ) -> V_52 ;
V_59 = F_63 ( V_3 ) -> V_59 ;
if ( V_164 > V_3 -> V_130 )
goto V_345;
if ( V_331 == V_139 ) {
if ( V_164 < sizeof( * V_96 ) || F_255 ( V_3 , V_164 ) )
goto V_345;
V_96 = F_81 ( V_3 ) ;
}
if ( F_249 ( V_3 , V_96 , V_331 ) )
goto V_323;
V_13 = F_256 ( V_3 ) ;
if ( V_13 ) {
struct V_328 * V_132 = F_257 ( V_3 ) ;
int V_236 ;
if ( F_60 ( V_13 -> V_330 != V_132 ) )
F_240 ( V_13 , V_132 ) ;
V_236 = F_231 ( V_13 , V_3 ) ;
F_258 ( V_13 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( V_168 -> V_223 & ( V_224 | V_346 ) )
return F_244 ( V_1 , V_3 , V_96 ,
V_52 , V_59 , V_28 , V_331 ) ;
V_13 = F_62 ( V_3 , V_96 -> V_102 , V_96 -> V_101 , V_28 ) ;
if ( V_13 ) {
int V_236 ;
if ( F_259 ( V_13 ) && V_96 -> V_138 && ! F_95 ( V_13 ) )
F_260 ( V_3 , V_139 , V_96 -> V_138 ,
V_344 ) ;
V_236 = F_231 ( V_13 , V_3 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( ! F_232 ( NULL , V_321 , V_3 ) )
goto V_268;
F_233 ( V_3 ) ;
if ( F_181 ( V_3 ) )
goto V_323;
F_182 ( V_1 , V_347 , V_331 == V_343 ) ;
F_261 ( V_3 , V_111 , V_348 , 0 ) ;
F_168 ( V_3 ) ;
return 0 ;
V_345:
F_131 ( L_5 ,
V_331 == V_343 ? L_6 : L_7 ,
& V_52 , F_58 ( V_96 -> V_102 ) ,
V_164 , V_3 -> V_130 ,
& V_59 , F_58 ( V_96 -> V_101 ) ) ;
goto V_268;
V_323:
F_131 ( L_8 ,
V_331 == V_343 ? L_6 : L_7 ,
& V_52 , F_58 ( V_96 -> V_102 ) , & V_59 , F_58 ( V_96 -> V_101 ) ,
V_164 ) ;
F_182 ( V_1 , V_279 , V_331 == V_343 ) ;
V_268:
F_182 ( V_1 , V_280 , V_331 == V_343 ) ;
F_168 ( V_3 ) ;
return 0 ;
}
static struct V_12 * F_262 ( struct V_1 * V_1 ,
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
static struct V_12 * F_263 ( struct V_1 * V_1 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_61 )
{
unsigned short V_60 = F_58 ( V_90 ) ;
unsigned int V_82 = F_43 ( V_1 , V_91 , V_60 ) ;
unsigned int V_42 = V_82 & V_27 . V_37 ;
struct V_9 * V_21 = & V_27 . V_82 [ V_42 ] ;
F_264 ( V_349 , V_93 , V_91 ) ;
const T_12 V_350 = F_265 ( V_92 , V_60 ) ;
struct V_12 * V_13 ;
F_54 (sk, &hslot2->head) {
if ( F_266 ( V_13 , V_1 , V_349 , V_93 ,
V_91 , V_350 , V_61 ) )
return V_13 ;
break;
}
return NULL ;
}
void F_267 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_64 ( V_3 -> V_88 ) ;
const struct V_86 * V_87 ;
const struct V_80 * V_96 ;
struct V_12 * V_13 = NULL ;
struct V_328 * V_132 ;
int V_61 = V_3 -> V_88 -> V_103 ;
int V_351 ;
if ( ! F_254 ( V_3 , F_82 ( V_3 ) + sizeof( struct V_80 ) ) )
return;
V_87 = F_63 ( V_3 ) ;
V_96 = F_81 ( V_3 ) ;
if ( V_3 -> V_352 == V_353 ||
V_3 -> V_352 == V_354 ) {
struct V_355 * V_356 = F_268 ( V_3 -> V_88 ) ;
if ( ! V_356 )
return;
if ( V_3 -> V_352 == V_354 ) {
V_351 = F_269 ( V_356 , V_87 -> V_59 , V_87 -> V_52 ,
V_87 -> V_357 ) ;
if ( ! V_351 )
return;
}
V_13 = F_262 ( V_1 , V_96 -> V_101 , V_87 -> V_59 ,
V_96 -> V_102 , V_87 -> V_52 , V_61 ) ;
} else if ( V_3 -> V_352 == V_358 ) {
V_13 = F_263 ( V_1 , V_96 -> V_101 , V_87 -> V_59 ,
V_96 -> V_102 , V_87 -> V_52 , V_61 ) ;
}
if ( ! V_13 || ! F_68 ( & V_13 -> V_89 ) )
return;
V_3 -> V_13 = V_13 ;
V_3 -> V_359 = V_360 ;
V_132 = F_173 ( V_13 -> V_330 ) ;
if ( V_132 )
V_132 = F_270 ( V_132 , 0 ) ;
if ( V_132 ) {
F_271 ( V_3 , V_132 ) ;
}
}
int F_272 ( struct V_2 * V_3 )
{
return F_252 ( V_3 , & V_27 , V_139 ) ;
}
void F_273 ( struct V_12 * V_13 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
bool V_277 = F_174 ( V_13 ) ;
F_78 ( V_13 ) ;
F_176 ( V_13 , V_277 ) ;
if ( F_234 ( & V_320 ) && V_128 -> V_322 ) {
void (* F_274)( struct V_12 * V_13 );
F_274 = F_236 ( V_128 -> F_274 ) ;
if ( F_274 )
F_274 ( V_13 ) ;
}
}
int F_275 ( struct V_12 * V_13 , int V_361 , int V_362 ,
char V_285 * V_363 , unsigned int V_207 ,
int (* F_276)( struct V_12 * ) )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_364 , V_365 ;
int V_100 = 0 ;
int V_148 = F_95 ( V_13 ) ;
if ( V_207 < sizeof( int ) )
return - V_185 ;
if ( F_277 ( V_364 , ( int V_285 * ) V_363 ) )
return - V_366 ;
V_365 = V_364 ? 1 : 0 ;
switch ( V_362 ) {
case V_367 :
if ( V_364 != 0 ) {
V_128 -> V_172 = 1 ;
} else {
V_128 -> V_172 = 0 ;
F_105 ( V_13 ) ;
F_276 ( V_13 ) ;
F_107 ( V_13 ) ;
}
break;
case V_368 :
switch ( V_364 ) {
case 0 :
case V_369 :
case V_370 :
V_128 -> F_235 = V_371 ;
case V_372 :
V_128 -> V_322 = V_364 ;
F_228 () ;
break;
default:
V_100 = - V_373 ;
break;
}
break;
case V_374 :
V_128 -> V_375 = V_365 ;
break;
case V_376 :
V_128 -> V_377 = V_365 ;
break;
case V_378 :
if ( ! V_148 )
return - V_373 ;
if ( V_364 != 0 && V_364 < 8 )
V_364 = 8 ;
else if ( V_364 > V_379 )
V_364 = V_379 ;
V_128 -> V_380 = V_364 ;
V_128 -> V_381 |= V_382 ;
break;
case V_383 :
if ( ! V_148 )
return - V_373 ;
if ( V_364 != 0 && V_364 < 8 )
V_364 = 8 ;
else if ( V_364 > V_379 )
V_364 = V_379 ;
V_128 -> V_325 = V_364 ;
V_128 -> V_381 |= V_324 ;
break;
default:
V_100 = - V_373 ;
break;
}
return V_100 ;
}
int F_278 ( struct V_12 * V_13 , int V_361 , int V_362 ,
char V_285 * V_363 , unsigned int V_207 )
{
if ( V_361 == V_384 || V_361 == V_385 )
return F_275 ( V_13 , V_361 , V_362 , V_363 , V_207 ,
F_101 ) ;
return F_279 ( V_13 , V_361 , V_362 , V_363 , V_207 ) ;
}
int F_280 ( struct V_12 * V_13 , int V_361 , int V_362 ,
char V_285 * V_363 , unsigned int V_207 )
{
if ( V_361 == V_384 || V_361 == V_385 )
return F_275 ( V_13 , V_361 , V_362 , V_363 , V_207 ,
F_101 ) ;
return F_281 ( V_13 , V_361 , V_362 , V_363 , V_207 ) ;
}
int F_282 ( struct V_12 * V_13 , int V_361 , int V_362 ,
char V_285 * V_363 , int V_285 * V_207 )
{
struct V_127 * V_128 = F_10 ( V_13 ) ;
int V_364 , V_130 ;
if ( F_277 ( V_130 , V_207 ) )
return - V_366 ;
V_130 = F_283 (unsigned int, len, sizeof(int)) ;
if ( V_130 < 0 )
return - V_185 ;
switch ( V_362 ) {
case V_367 :
V_364 = V_128 -> V_172 ;
break;
case V_368 :
V_364 = V_128 -> V_322 ;
break;
case V_374 :
V_364 = V_128 -> V_375 ;
break;
case V_376 :
V_364 = V_128 -> V_377 ;
break;
case V_378 :
V_364 = V_128 -> V_380 ;
break;
case V_383 :
V_364 = V_128 -> V_325 ;
break;
default:
return - V_373 ;
}
if ( F_187 ( V_130 , V_207 ) )
return - V_366 ;
if ( F_284 ( V_363 , & V_364 , V_130 ) )
return - V_366 ;
return 0 ;
}
int F_285 ( struct V_12 * V_13 , int V_361 , int V_362 ,
char V_285 * V_363 , int V_285 * V_207 )
{
if ( V_361 == V_384 || V_361 == V_385 )
return F_282 ( V_13 , V_361 , V_362 , V_363 , V_207 ) ;
return F_286 ( V_13 , V_361 , V_362 , V_363 , V_207 ) ;
}
int F_287 ( struct V_12 * V_13 , int V_361 , int V_362 ,
char V_285 * V_363 , int V_285 * V_207 )
{
if ( V_361 == V_384 || V_361 == V_385 )
return F_282 ( V_13 , V_361 , V_362 , V_363 , V_207 ) ;
return F_288 ( V_13 , V_361 , V_362 , V_363 , V_207 ) ;
}
unsigned int F_289 ( struct V_386 * V_386 , struct V_387 * V_12 , T_13 * V_388 )
{
unsigned int V_37 = F_290 ( V_386 , V_12 , V_388 ) ;
struct V_12 * V_13 = V_12 -> V_13 ;
if ( ! F_133 ( & F_10 ( V_13 ) -> V_254 ) )
V_37 |= V_389 | V_390 ;
F_291 ( V_13 ) ;
if ( ( V_37 & V_390 ) && ! ( V_386 -> V_391 & V_392 ) &&
! ( V_13 -> V_393 & V_394 ) && F_184 ( V_13 ) == - 1 )
V_37 &= ~ ( V_389 | V_390 ) ;
return V_37 ;
}
int F_292 ( struct V_12 * V_13 , int V_100 )
{
F_105 ( V_13 ) ;
V_13 -> V_125 = V_100 ;
V_13 -> V_126 ( V_13 ) ;
F_210 ( V_13 , 0 ) ;
F_107 ( V_13 ) ;
return 0 ;
}
static struct V_12 * F_293 ( struct V_395 * V_396 , int V_397 )
{
struct V_12 * V_13 ;
struct V_398 * V_399 = V_396 -> V_400 ;
struct V_1 * V_1 = F_294 ( V_396 ) ;
for ( V_399 -> V_401 = V_397 ; V_399 -> V_401 <= V_399 -> V_27 -> V_37 ;
++ V_399 -> V_401 ) {
struct V_9 * V_10 = & V_399 -> V_27 -> V_79 [ V_399 -> V_401 ] ;
if ( F_295 ( & V_10 -> V_47 ) )
continue;
F_30 ( & V_10 -> V_23 ) ;
F_7 (sk, &hslot->head) {
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) )
continue;
if ( V_13 -> V_24 == V_399 -> V_402 )
goto V_38;
}
F_33 ( & V_10 -> V_23 ) ;
}
V_13 = NULL ;
V_38:
return V_13 ;
}
static struct V_12 * F_296 ( struct V_395 * V_396 , struct V_12 * V_13 )
{
struct V_398 * V_399 = V_396 -> V_400 ;
struct V_1 * V_1 = F_294 ( V_396 ) ;
do {
V_13 = F_297 ( V_13 ) ;
} while ( V_13 && ( ! F_8 ( F_9 ( V_13 ) , V_1 ) || V_13 -> V_24 != V_399 -> V_402 ) );
if ( ! V_13 ) {
if ( V_399 -> V_401 <= V_399 -> V_27 -> V_37 )
F_33 ( & V_399 -> V_27 -> V_79 [ V_399 -> V_401 ] . V_23 ) ;
return F_293 ( V_396 , V_399 -> V_401 + 1 ) ;
}
return V_13 ;
}
static struct V_12 * F_298 ( struct V_395 * V_396 , T_14 V_403 )
{
struct V_12 * V_13 = F_293 ( V_396 , 0 ) ;
if ( V_13 )
while ( V_403 && ( V_13 = F_296 ( V_396 , V_13 ) ) != NULL )
-- V_403 ;
return V_403 ? NULL : V_13 ;
}
static void * F_299 ( struct V_395 * V_396 , T_14 * V_403 )
{
struct V_398 * V_399 = V_396 -> V_400 ;
V_399 -> V_401 = V_404 ;
return * V_403 ? F_298 ( V_396 , * V_403 - 1 ) : V_405 ;
}
static void * F_300 ( struct V_395 * V_396 , void * V_406 , T_14 * V_403 )
{
struct V_12 * V_13 ;
if ( V_406 == V_405 )
V_13 = F_298 ( V_396 , 0 ) ;
else
V_13 = F_296 ( V_396 , V_406 ) ;
++ * V_403 ;
return V_13 ;
}
static void F_301 ( struct V_395 * V_396 , void * V_406 )
{
struct V_398 * V_399 = V_396 -> V_400 ;
if ( V_399 -> V_401 <= V_399 -> V_27 -> V_37 )
F_33 ( & V_399 -> V_27 -> V_79 [ V_399 -> V_401 ] . V_23 ) ;
}
int F_302 ( struct V_407 * V_407 , struct V_386 * V_386 )
{
struct V_408 * V_409 = F_303 ( V_407 ) ;
struct V_398 * V_410 ;
int V_100 ;
V_100 = F_304 ( V_407 , V_386 , & V_409 -> V_411 ,
sizeof( struct V_398 ) ) ;
if ( V_100 < 0 )
return V_100 ;
V_410 = ( (struct V_395 * ) V_386 -> V_412 ) -> V_400 ;
V_410 -> V_402 = V_409 -> V_402 ;
V_410 -> V_27 = V_409 -> V_27 ;
return V_100 ;
}
int F_305 ( struct V_1 * V_1 , struct V_408 * V_409 )
{
struct V_413 * V_414 ;
int V_318 = 0 ;
V_409 -> V_411 . V_397 = F_299 ;
V_409 -> V_411 . V_415 = F_300 ;
V_409 -> V_411 . V_416 = F_301 ;
V_414 = F_306 ( V_409 -> V_417 , V_418 , V_1 -> V_419 ,
V_409 -> V_420 , V_409 ) ;
if ( ! V_414 )
V_318 = - V_267 ;
return V_318 ;
}
void F_307 ( struct V_1 * V_1 , struct V_408 * V_409 )
{
F_308 ( V_409 -> V_417 , V_1 -> V_419 ) ;
}
static void F_309 ( struct V_12 * V_421 , struct V_395 * V_422 ,
int V_401 )
{
struct V_64 * V_65 = F_36 ( V_421 ) ;
T_4 V_101 = V_65 -> V_67 ;
T_4 V_131 = V_65 -> V_57 ;
T_1 V_423 = F_58 ( V_65 -> V_68 ) ;
T_1 V_424 = F_58 ( V_65 -> V_149 ) ;
F_310 ( V_422 , L_9
L_10 ,
V_401 , V_131 , V_424 , V_101 , V_423 , V_421 -> V_122 ,
F_186 ( V_421 ) ,
F_311 ( V_421 ) ,
0 , 0L , 0 ,
F_312 ( F_313 ( V_422 ) , F_6 ( V_421 ) ) ,
0 , F_314 ( V_421 ) ,
F_315 ( & V_421 -> V_89 ) , V_421 ,
F_158 ( & V_421 -> V_273 ) ) ;
}
int F_316 ( struct V_395 * V_396 , void * V_406 )
{
F_317 ( V_396 , 127 ) ;
if ( V_406 == V_405 )
F_318 ( V_396 , L_11
L_12
L_13 ) ;
else {
struct V_398 * V_399 = V_396 -> V_400 ;
F_309 ( V_406 , V_396 , V_399 -> V_401 ) ;
}
F_319 ( V_396 , '\n' ) ;
return 0 ;
}
static int T_15 F_320 ( struct V_1 * V_1 )
{
return F_305 ( V_1 , & V_425 ) ;
}
static void T_16 F_321 ( struct V_1 * V_1 )
{
F_307 ( V_1 , & V_425 ) ;
}
int T_17 F_322 ( void )
{
return F_323 ( & V_426 ) ;
}
void F_324 ( void )
{
F_325 ( & V_426 ) ;
}
static int T_17 F_326 ( char * V_427 )
{
T_18 V_236 ;
if ( ! V_427 )
return 0 ;
V_236 = F_327 ( V_427 , 0 , & V_428 ) ;
if ( V_236 )
return 0 ;
if ( V_428 && V_428 < V_429 )
V_428 = V_429 ;
return 1 ;
}
void T_17 F_328 ( struct V_27 * V_430 , const char * V_417 )
{
unsigned int V_431 ;
V_430 -> V_79 = F_329 ( V_417 ,
2 * sizeof( struct V_9 ) ,
V_428 ,
21 ,
0 ,
& V_430 -> log ,
& V_430 -> V_37 ,
V_429 ,
64 * 1024 ) ;
V_430 -> V_82 = V_430 -> V_79 + ( V_430 -> V_37 + 1 ) ;
for ( V_431 = 0 ; V_431 <= V_430 -> V_37 ; V_431 ++ ) {
F_330 ( & V_430 -> V_79 [ V_431 ] . V_47 ) ;
V_430 -> V_79 [ V_431 ] . V_40 = 0 ;
F_331 ( & V_430 -> V_79 [ V_431 ] . V_23 ) ;
}
for ( V_431 = 0 ; V_431 <= V_430 -> V_37 ; V_431 ++ ) {
F_330 ( & V_430 -> V_82 [ V_431 ] . V_47 ) ;
V_430 -> V_82 [ V_431 ] . V_40 = 0 ;
F_331 ( & V_430 -> V_82 [ V_431 ] . V_23 ) ;
}
}
T_3 F_332 ( void )
{
static T_3 T_19 V_74 ;
F_51 ( & T_19 , sizeof( T_19 ) ) ;
return T_19 ;
}
void T_17 F_333 ( void )
{
unsigned long V_432 ;
unsigned int V_431 ;
F_328 ( & V_27 , L_14 ) ;
V_432 = F_334 () / 8 ;
V_432 = F_335 ( V_432 , 128UL ) ;
V_433 [ 0 ] = V_432 / 4 * 3 ;
V_433 [ 1 ] = V_432 ;
V_433 [ 2 ] = V_433 [ 0 ] * 2 ;
V_434 = V_257 ;
V_435 = V_257 ;
V_263 = F_336 ( V_436 ) + 4 ;
V_262 = F_337 ( sizeof( T_10 ) << V_263 ,
V_437 ) ;
if ( ! V_262 )
F_338 ( L_15 ) ;
for ( V_431 = 0 ; V_431 < ( 1U << V_263 ) ; V_431 ++ )
F_331 ( V_262 + V_431 ) ;
}
