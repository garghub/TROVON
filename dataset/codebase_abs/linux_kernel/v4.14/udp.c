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
return F_22 ( V_13 ) ;
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
T_4 V_59 , unsigned short V_60 ,
int V_61 , int V_62 , bool V_63 )
{
int V_64 ;
struct V_65 * V_66 ;
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) ||
F_10 ( V_13 ) -> V_16 != V_60 ||
F_20 ( V_13 ) )
return - 1 ;
V_64 = ( V_13 -> V_24 == V_67 ) ? 2 : 1 ;
V_66 = F_36 ( V_13 ) ;
if ( V_66 -> V_57 ) {
if ( V_66 -> V_57 != V_59 )
return - 1 ;
V_64 += 4 ;
}
if ( V_66 -> V_68 ) {
if ( V_66 -> V_68 != V_52 )
return - 1 ;
V_64 += 4 ;
}
if ( V_66 -> V_69 ) {
if ( V_66 -> V_69 != V_58 )
return - 1 ;
V_64 += 4 ;
}
if ( V_13 -> V_18 || V_63 ) {
bool V_70 = ( V_13 -> V_18 == V_61 ||
V_13 -> V_18 == V_62 ) ;
if ( V_63 && ! V_70 )
return - 1 ;
if ( V_13 -> V_18 && V_70 )
V_64 += 4 ;
}
if ( V_13 -> V_71 == F_49 () )
V_64 ++ ;
return V_64 ;
}
static T_3 F_50 ( const struct V_1 * V_1 , const T_4 V_72 ,
const T_1 V_73 , const T_4 V_74 ,
const T_5 V_75 )
{
static T_3 T_6 V_76 ;
F_51 ( & T_6 , sizeof( T_6 ) ) ;
return F_52 ( V_72 , V_73 , V_74 , V_75 ,
T_6 + F_45 ( V_1 ) ) ;
}
static struct V_12 * F_53 ( struct V_1 * V_1 ,
T_4 V_52 , T_5 V_58 ,
T_4 V_59 , unsigned int V_60 ,
int V_61 , int V_62 , bool V_63 ,
struct V_9 * V_21 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 , * V_77 ;
int V_64 , V_78 , V_79 = 0 , V_80 = 0 ;
T_3 V_81 = 0 ;
V_77 = NULL ;
V_78 = 0 ;
F_54 (sk, &hslot2->head) {
V_64 = F_48 ( V_13 , V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 , V_62 , V_63 ) ;
if ( V_64 > V_78 ) {
V_80 = V_13 -> V_19 ;
if ( V_80 ) {
V_81 = F_50 ( V_1 , V_59 , V_60 ,
V_52 , V_58 ) ;
V_77 = F_55 ( V_13 , V_81 , V_3 ,
sizeof( struct V_82 ) ) ;
if ( V_77 )
return V_77 ;
V_79 = 1 ;
}
V_78 = V_64 ;
V_77 = V_13 ;
} else if ( V_64 == V_78 && V_80 ) {
V_79 ++ ;
if ( F_27 ( V_81 , V_79 ) == 0 )
V_77 = V_13 ;
V_81 = F_56 ( V_81 ) ;
}
}
return V_77 ;
}
struct V_12 * F_57 ( struct V_1 * V_1 , T_4 V_52 ,
T_5 V_58 , T_4 V_59 , T_5 V_83 , int V_61 ,
int V_62 , struct V_27 * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_13 , * V_77 ;
unsigned short V_60 = F_58 ( V_83 ) ;
unsigned int V_84 , V_42 , V_85 = F_59 ( V_1 , V_60 , V_28 -> V_37 ) ;
struct V_9 * V_21 , * V_10 = & V_28 -> V_81 [ V_85 ] ;
bool V_63 = F_1 ( V_1 , V_3 ) ;
int V_64 , V_78 , V_79 = 0 , V_80 = 0 ;
T_3 V_81 = 0 ;
if ( V_10 -> V_40 > 10 ) {
V_84 = F_43 ( V_1 , V_59 , V_60 ) ;
V_42 = V_84 & V_28 -> V_37 ;
V_21 = & V_28 -> V_84 [ V_42 ] ;
if ( V_10 -> V_40 < V_21 -> V_40 )
goto V_86;
V_77 = F_53 ( V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 , V_62 ,
V_63 , V_21 , V_3 ) ;
if ( ! V_77 ) {
unsigned int V_87 = V_42 ;
V_84 = F_43 ( V_1 , F_47 ( V_55 ) , V_60 ) ;
V_42 = V_84 & V_28 -> V_37 ;
if ( F_60 ( V_42 == V_87 ) )
return V_77 ;
V_21 = & V_28 -> V_84 [ V_42 ] ;
if ( V_10 -> V_40 < V_21 -> V_40 )
goto V_86;
V_77 = F_53 ( V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 , V_62 ,
V_63 , V_21 , V_3 ) ;
}
return V_77 ;
}
V_86:
V_77 = NULL ;
V_78 = 0 ;
F_61 (sk, &hslot->head) {
V_64 = F_48 ( V_13 , V_1 , V_52 , V_58 ,
V_59 , V_60 , V_61 , V_62 , V_63 ) ;
if ( V_64 > V_78 ) {
V_80 = V_13 -> V_19 ;
if ( V_80 ) {
V_81 = F_50 ( V_1 , V_59 , V_60 ,
V_52 , V_58 ) ;
V_77 = F_55 ( V_13 , V_81 , V_3 ,
sizeof( struct V_82 ) ) ;
if ( V_77 )
return V_77 ;
V_79 = 1 ;
}
V_77 = V_13 ;
V_78 = V_64 ;
} else if ( V_64 == V_78 && V_80 ) {
V_79 ++ ;
if ( F_27 ( V_81 , V_79 ) == 0 )
V_77 = V_13 ;
V_81 = F_56 ( V_81 ) ;
}
}
return V_77 ;
}
static inline struct V_12 * F_62 ( struct V_2 * V_3 ,
T_5 V_58 , T_5 V_83 ,
struct V_27 * V_28 )
{
const struct V_88 * V_89 = F_63 ( V_3 ) ;
return F_57 ( F_64 ( V_3 -> V_90 ) , V_89 -> V_52 , V_58 ,
V_89 -> V_59 , V_83 , F_65 ( V_3 ) ,
F_66 ( V_3 ) , V_28 , V_3 ) ;
}
struct V_12 * F_67 ( struct V_2 * V_3 ,
T_5 V_58 , T_5 V_83 )
{
return F_62 ( V_3 , V_58 , V_83 , & V_27 ) ;
}
struct V_12 * F_68 ( struct V_1 * V_1 , T_4 V_52 , T_5 V_58 ,
T_4 V_59 , T_5 V_83 , int V_61 )
{
struct V_12 * V_13 ;
V_13 = F_57 ( V_1 , V_52 , V_58 , V_59 , V_83 ,
V_61 , 0 , & V_27 , NULL ) ;
if ( V_13 && ! F_69 ( & V_13 -> V_91 ) )
V_13 = NULL ;
return V_13 ;
}
static inline bool F_70 ( struct V_1 * V_1 , struct V_12 * V_13 ,
T_5 V_92 , T_4 V_93 ,
T_5 V_94 , T_4 V_95 ,
int V_61 , int V_62 , unsigned short V_60 )
{
struct V_65 * V_66 = F_36 ( V_13 ) ;
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) ||
F_10 ( V_13 ) -> V_16 != V_60 ||
( V_66 -> V_68 && V_66 -> V_68 != V_95 ) ||
( V_66 -> V_69 != V_94 && V_66 -> V_69 ) ||
( V_66 -> V_57 && V_66 -> V_57 != V_93 ) ||
F_20 ( V_13 ) ||
( V_13 -> V_18 && V_13 -> V_18 != V_61 &&
V_13 -> V_18 != V_62 ) )
return false ;
if ( ! F_71 ( V_13 , V_93 , V_95 , V_61 , V_62 ) )
return false ;
return true ;
}
void F_72 ( struct V_2 * V_3 , T_3 V_96 , struct V_27 * V_28 )
{
struct V_65 * V_66 ;
const struct V_88 * V_89 = ( const struct V_88 * ) V_3 -> V_97 ;
struct V_82 * V_98 = (struct V_82 * ) ( V_3 -> V_97 + ( V_89 -> V_99 << 2 ) ) ;
const int type = F_73 ( V_3 ) -> type ;
const int V_100 = F_73 ( V_3 ) -> V_100 ;
struct V_12 * V_13 ;
int V_101 ;
int V_102 ;
struct V_1 * V_1 = F_64 ( V_3 -> V_90 ) ;
V_13 = F_57 ( V_1 , V_89 -> V_59 , V_98 -> V_103 ,
V_89 -> V_52 , V_98 -> V_104 , V_3 -> V_90 -> V_105 , 0 ,
V_28 , NULL ) ;
if ( ! V_13 ) {
F_74 ( V_1 , V_106 ) ;
return;
}
V_102 = 0 ;
V_101 = 0 ;
V_66 = F_36 ( V_13 ) ;
switch ( type ) {
default:
case V_107 :
V_102 = V_108 ;
break;
case V_109 :
goto V_110;
case V_111 :
V_102 = V_112 ;
V_101 = 1 ;
break;
case V_113 :
if ( V_100 == V_114 ) {
F_75 ( V_3 , V_13 , V_96 ) ;
if ( V_66 -> V_115 != V_116 ) {
V_102 = V_117 ;
V_101 = 1 ;
break;
}
goto V_110;
}
V_102 = V_108 ;
if ( V_100 <= V_118 ) {
V_101 = V_119 [ V_100 ] . V_120 ;
V_102 = V_119 [ V_100 ] . V_121 ;
}
break;
case V_122 :
F_76 ( V_3 , V_13 ) ;
goto V_110;
}
if ( ! V_66 -> V_123 ) {
if ( ! V_101 || V_13 -> V_124 != V_125 )
goto V_110;
} else
F_77 ( V_13 , V_3 , V_102 , V_98 -> V_103 , V_96 , ( V_126 * ) ( V_98 + 1 ) ) ;
V_13 -> V_127 = V_102 ;
V_13 -> V_128 ( V_13 ) ;
V_110:
return;
}
void F_78 ( struct V_2 * V_3 , T_3 V_96 )
{
F_72 ( V_3 , V_96 , & V_27 ) ;
}
void F_79 ( struct V_12 * V_13 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
if ( V_130 -> V_131 ) {
V_130 -> V_132 = 0 ;
V_130 -> V_131 = 0 ;
F_80 ( V_13 ) ;
}
}
void F_81 ( struct V_2 * V_3 , T_4 V_133 , T_4 V_134 )
{
struct V_82 * V_98 = F_82 ( V_3 ) ;
int V_135 = F_83 ( V_3 ) ;
int V_132 = V_3 -> V_132 - V_135 ;
int V_136 = V_132 ;
T_7 V_137 = 0 ;
if ( ! F_84 ( V_3 ) ) {
V_3 -> V_138 = F_85 ( V_3 ) - V_3 -> V_47 ;
V_3 -> V_139 = F_86 ( struct V_82 , V_140 ) ;
V_98 -> V_140 = ~ F_87 ( V_133 , V_134 , V_132 ,
V_141 , 0 ) ;
} else {
struct V_2 * V_142 ;
F_88 (skb, frags) {
V_137 = F_89 ( V_137 , V_142 -> V_137 ) ;
V_136 -= V_142 -> V_132 ;
}
V_137 = F_90 ( V_3 , V_135 , V_136 , V_137 ) ;
V_3 -> V_143 = V_144 ;
V_98 -> V_140 = F_87 ( V_133 , V_134 , V_132 , V_141 , V_137 ) ;
if ( V_98 -> V_140 == 0 )
V_98 -> V_140 = V_145 ;
}
}
void F_91 ( bool V_146 , struct V_2 * V_3 ,
T_4 V_52 , T_4 V_59 , int V_132 )
{
struct V_82 * V_98 = F_82 ( V_3 ) ;
if ( V_146 ) {
V_98 -> V_140 = 0 ;
} else if ( F_92 ( V_3 ) ) {
V_98 -> V_140 = ~ F_93 ( V_132 , V_52 , V_59 , 0 ) ;
} else if ( V_3 -> V_143 == V_147 ) {
V_98 -> V_140 = 0 ;
V_98 -> V_140 = F_93 ( V_132 , V_52 , V_59 , F_94 ( V_3 ) ) ;
if ( V_98 -> V_140 == 0 )
V_98 -> V_140 = V_145 ;
} else {
V_3 -> V_143 = V_147 ;
V_3 -> V_138 = F_85 ( V_3 ) - V_3 -> V_47 ;
V_3 -> V_139 = F_86 ( struct V_82 , V_140 ) ;
V_98 -> V_140 = ~ F_93 ( V_132 , V_52 , V_59 , 0 ) ;
}
}
static int F_95 ( struct V_2 * V_3 , struct V_148 * V_149 )
{
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_65 * V_66 = F_36 ( V_13 ) ;
struct V_82 * V_98 ;
int V_102 = 0 ;
int V_150 = F_96 ( V_13 ) ;
int V_135 = F_83 ( V_3 ) ;
int V_132 = V_3 -> V_132 - V_135 ;
T_7 V_137 = 0 ;
V_98 = F_82 ( V_3 ) ;
V_98 -> V_104 = V_66 -> V_151 ;
V_98 -> V_103 = V_149 -> V_152 ;
V_98 -> V_132 = F_97 ( V_132 ) ;
V_98 -> V_140 = 0 ;
if ( V_150 )
V_137 = F_98 ( V_3 ) ;
else if ( V_13 -> V_153 ) {
V_3 -> V_143 = V_144 ;
goto V_154;
} else if ( V_3 -> V_143 == V_147 ) {
F_81 ( V_3 , V_149 -> V_52 , V_149 -> V_59 ) ;
goto V_154;
} else
V_137 = F_99 ( V_3 ) ;
V_98 -> V_140 = F_87 ( V_149 -> V_52 , V_149 -> V_59 , V_132 ,
V_13 -> V_155 , V_137 ) ;
if ( V_98 -> V_140 == 0 )
V_98 -> V_140 = V_145 ;
V_154:
V_102 = F_100 ( F_9 ( V_13 ) , V_3 ) ;
if ( V_102 ) {
if ( V_102 == - V_156 && ! V_66 -> V_123 ) {
F_101 ( F_9 ( V_13 ) ,
V_157 , V_150 ) ;
V_102 = 0 ;
}
} else
F_101 ( F_9 ( V_13 ) ,
V_158 , V_150 ) ;
return V_102 ;
}
int F_102 ( struct V_12 * V_13 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
struct V_65 * V_66 = F_36 ( V_13 ) ;
struct V_148 * V_149 = & V_66 -> V_159 . V_160 . V_161 . V_162 ;
struct V_2 * V_3 ;
int V_102 = 0 ;
V_3 = F_103 ( V_13 , V_149 ) ;
if ( ! V_3 )
goto V_110;
V_102 = F_95 ( V_3 , V_149 ) ;
V_110:
V_130 -> V_132 = 0 ;
V_130 -> V_131 = 0 ;
return V_102 ;
}
int F_104 ( struct V_12 * V_13 , struct V_163 * V_164 , T_8 V_132 )
{
struct V_65 * V_66 = F_36 ( V_13 ) ;
struct V_129 * V_130 = F_10 ( V_13 ) ;
struct V_148 V_165 ;
struct V_148 * V_149 ;
int V_166 = V_132 ;
struct V_167 V_168 ;
struct V_169 * V_170 = NULL ;
int free = 0 ;
int V_171 = 0 ;
T_4 V_59 , V_74 , V_52 ;
T_5 V_83 ;
V_126 V_172 ;
int V_102 , V_150 = F_96 ( V_13 ) ;
int V_173 = V_130 -> V_174 || V_164 -> V_175 & V_176 ;
int (* F_105)( void * , char * , int , int , int , struct V_2 * );
struct V_2 * V_3 ;
struct V_177 V_178 ;
if ( V_132 > 0xFFFF )
return - V_117 ;
if ( V_164 -> V_175 & V_179 )
return - V_180 ;
V_168 . V_181 = NULL ;
V_168 . V_182 = 0 ;
V_168 . V_183 = 0 ;
V_168 . V_172 = - 1 ;
F_105 = V_150 ? V_184 : V_185 ;
V_149 = & V_66 -> V_159 . V_160 . V_161 . V_162 ;
if ( V_130 -> V_131 ) {
F_106 ( V_13 ) ;
if ( F_107 ( V_130 -> V_131 ) ) {
if ( F_60 ( V_130 -> V_131 != V_186 ) ) {
F_108 ( V_13 ) ;
return - V_187 ;
}
goto V_188;
}
F_108 ( V_13 ) ;
}
V_166 += sizeof( struct V_82 ) ;
if ( V_164 -> V_189 ) {
F_109 ( struct V_190 * , V_191 , V_164 -> V_189 ) ;
if ( V_164 -> V_192 < sizeof( * V_191 ) )
return - V_187 ;
if ( V_191 -> V_193 != V_186 ) {
if ( V_191 -> V_193 != V_194 )
return - V_195 ;
}
V_59 = V_191 -> V_196 . V_197 ;
V_83 = V_191 -> V_198 ;
if ( V_83 == 0 )
return - V_187 ;
} else {
if ( V_13 -> V_124 != V_125 )
return - V_199 ;
V_59 = V_66 -> V_68 ;
V_83 = V_66 -> V_69 ;
V_171 = 1 ;
}
V_168 . V_200 . V_201 = V_13 -> V_202 ;
V_168 . V_203 = V_66 -> V_204 ;
V_168 . V_205 = V_13 -> V_18 ;
if ( V_164 -> V_206 ) {
V_102 = F_110 ( V_13 , V_164 , & V_168 , V_13 -> V_24 == V_49 ) ;
if ( F_60 ( V_102 ) ) {
F_111 ( V_168 . V_181 ) ;
return V_102 ;
}
if ( V_168 . V_181 )
free = 1 ;
V_171 = 0 ;
}
if ( ! V_168 . V_181 ) {
struct V_207 * V_208 ;
F_112 () ;
V_208 = F_113 ( V_66 -> V_208 ) ;
if ( V_208 ) {
memcpy ( & V_178 , V_208 ,
sizeof( * V_208 ) + V_208 -> V_181 . V_209 ) ;
V_168 . V_181 = & V_178 . V_181 ;
}
F_114 () ;
}
V_52 = V_168 . V_203 ;
V_168 . V_203 = V_74 = V_59 ;
F_115 ( V_13 , V_168 . V_200 . V_201 , & V_168 . V_182 ) ;
if ( V_168 . V_181 && V_168 . V_181 -> V_181 . V_210 ) {
if ( ! V_59 )
return - V_187 ;
V_74 = V_168 . V_181 -> V_181 . V_74 ;
V_171 = 0 ;
}
V_172 = F_116 ( & V_168 , V_66 ) ;
if ( F_117 ( V_13 , V_211 ) ||
( V_164 -> V_175 & V_212 ) ||
( V_168 . V_181 && V_168 . V_181 -> V_181 . V_213 ) ) {
V_172 |= V_214 ;
V_171 = 0 ;
}
if ( F_118 ( V_59 ) ) {
if ( ! V_168 . V_205 )
V_168 . V_205 = V_66 -> V_215 ;
if ( ! V_52 )
V_52 = V_66 -> V_216 ;
V_171 = 0 ;
} else if ( ! V_168 . V_205 )
V_168 . V_205 = V_66 -> V_217 ;
if ( V_171 )
V_170 = (struct V_169 * ) F_119 ( V_13 , 0 ) ;
if ( ! V_170 ) {
struct V_1 * V_1 = F_9 ( V_13 ) ;
T_9 V_218 = F_120 ( V_13 ) ;
V_149 = & V_165 ;
F_121 ( V_149 , V_168 . V_205 , V_13 -> V_219 , V_172 ,
V_220 , V_13 -> V_155 ,
V_218 ,
V_74 , V_52 , V_83 , V_66 -> V_151 ,
V_13 -> V_221 ) ;
F_122 ( V_13 , F_123 ( V_149 ) ) ;
V_170 = F_124 ( V_1 , V_149 , V_13 ) ;
if ( F_125 ( V_170 ) ) {
V_102 = F_126 ( V_170 ) ;
V_170 = NULL ;
if ( V_102 == - V_222 )
F_127 ( V_1 , V_223 ) ;
goto V_110;
}
V_102 = - V_224 ;
if ( ( V_170 -> V_225 & V_226 ) &&
! F_117 ( V_13 , V_227 ) )
goto V_110;
if ( V_171 )
F_128 ( V_13 , F_129 ( & V_170 -> V_134 ) ) ;
}
if ( V_164 -> V_175 & V_228 )
goto V_229;
V_230:
V_52 = V_149 -> V_52 ;
if ( ! V_168 . V_203 )
V_59 = V_168 . V_203 = V_149 -> V_59 ;
if ( ! V_173 ) {
V_3 = F_130 ( V_13 , V_149 , F_105 , V_164 , V_166 ,
sizeof( struct V_82 ) , & V_168 , & V_170 ,
V_164 -> V_175 ) ;
V_102 = F_126 ( V_3 ) ;
if ( ! F_131 ( V_3 ) )
V_102 = F_95 ( V_3 , V_149 ) ;
goto V_110;
}
F_106 ( V_13 ) ;
if ( F_60 ( V_130 -> V_131 ) ) {
F_108 ( V_13 ) ;
F_132 ( L_1 ) ;
V_102 = - V_187 ;
goto V_110;
}
V_149 = & V_66 -> V_159 . V_160 . V_161 . V_162 ;
V_149 -> V_59 = V_59 ;
V_149 -> V_52 = V_52 ;
V_149 -> V_152 = V_83 ;
V_149 -> V_231 = V_66 -> V_151 ;
V_130 -> V_131 = V_186 ;
V_188:
V_130 -> V_132 += V_166 ;
V_102 = F_133 ( V_13 , V_149 , F_105 , V_164 , V_166 ,
sizeof( struct V_82 ) , & V_168 , & V_170 ,
V_173 ? V_164 -> V_175 | V_176 : V_164 -> V_175 ) ;
if ( V_102 )
F_79 ( V_13 ) ;
else if ( ! V_173 )
V_102 = F_102 ( V_13 ) ;
else if ( F_60 ( F_134 ( & V_13 -> V_232 ) ) )
V_130 -> V_131 = 0 ;
F_108 ( V_13 ) ;
V_110:
F_135 ( V_170 ) ;
if ( free )
F_111 ( V_168 . V_181 ) ;
if ( ! V_102 )
return V_132 ;
if ( V_102 == - V_156 || F_31 ( V_233 , & V_13 -> V_234 -> V_7 ) ) {
F_101 ( F_9 ( V_13 ) ,
V_157 , V_150 ) ;
}
return V_102 ;
V_229:
if ( V_164 -> V_175 & V_235 )
F_136 ( & V_170 -> V_134 , & V_149 -> V_59 ) ;
if ( ! ( V_164 -> V_175 & V_235 ) || V_132 )
goto V_230;
V_102 = 0 ;
goto V_110;
}
int F_137 ( struct V_12 * V_13 , struct V_236 * V_236 , int V_135 ,
T_8 V_237 , int V_7 )
{
struct V_65 * V_66 = F_36 ( V_13 ) ;
struct V_129 * V_130 = F_10 ( V_13 ) ;
int V_238 ;
if ( V_7 & V_239 )
V_7 |= V_176 ;
if ( ! V_130 -> V_131 ) {
struct V_163 V_164 = { . V_175 = V_7 | V_176 } ;
V_238 = F_104 ( V_13 , & V_164 , 0 ) ;
if ( V_238 < 0 )
return V_238 ;
}
F_106 ( V_13 ) ;
if ( F_60 ( ! V_130 -> V_131 ) ) {
F_108 ( V_13 ) ;
F_132 ( L_2 ) ;
return - V_187 ;
}
V_238 = F_138 ( V_13 , & V_66 -> V_159 . V_160 . V_161 . V_162 ,
V_236 , V_135 , V_237 , V_7 ) ;
if ( V_238 == - V_180 ) {
F_108 ( V_13 ) ;
return F_139 ( V_13 -> V_234 , V_236 , V_135 ,
V_237 , V_7 ) ;
}
if ( V_238 < 0 ) {
F_79 ( V_13 ) ;
goto V_110;
}
V_130 -> V_132 += V_237 ;
if ( ! ( V_130 -> V_174 || ( V_7 & V_176 ) ) )
V_238 = F_102 ( V_13 ) ;
if ( ! V_238 )
V_238 = V_237 ;
V_110:
F_108 ( V_13 ) ;
return V_238 ;
}
static void F_140 ( struct V_2 * V_3 )
{
struct V_240 * V_241 = F_141 ( V_3 ) ;
F_142 ( sizeof( struct V_240 ) > sizeof( long ) ) ;
V_241 -> V_242 = V_3 -> V_243 ;
#if V_244 == 64
V_241 -> V_132 = V_3 -> V_132 ;
V_241 -> V_245 = ! ! F_143 ( V_3 ) ;
V_241 -> V_246 = ! F_144 ( V_3 ) ;
#endif
if ( F_107 ( ! F_145 ( V_3 ) ) )
V_241 -> V_242 |= V_247 ;
}
static int F_146 ( struct V_2 * V_3 )
{
return F_141 ( V_3 ) -> V_242 & ~ V_247 ;
}
static bool F_147 ( struct V_2 * V_3 )
{
return ! ( F_141 ( V_3 ) -> V_242 & V_247 ) ;
}
static void F_148 ( struct V_12 * V_13 , int V_237 , int V_248 ,
bool V_249 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
struct V_250 * V_251 ;
int V_252 ;
if ( F_107 ( V_248 ) ) {
V_130 -> V_253 += V_237 ;
V_237 = V_130 -> V_253 ;
if ( V_237 < ( V_13 -> V_254 >> 2 ) &&
! F_134 ( & V_130 -> V_255 ) )
return;
} else {
V_237 += V_130 -> V_253 ;
}
V_130 -> V_253 = 0 ;
V_251 = & V_13 -> V_256 ;
if ( ! V_249 )
F_16 ( & V_251 -> V_23 ) ;
V_13 -> V_257 += V_237 ;
V_252 = ( V_13 -> V_257 - V_248 ) & ~ ( V_258 - 1 ) ;
V_13 -> V_257 -= V_252 ;
if ( V_252 )
F_149 ( V_13 , V_252 >> V_259 ) ;
F_150 ( V_237 , & V_13 -> V_260 ) ;
F_151 ( V_251 , & V_130 -> V_255 ) ;
if ( ! V_249 )
F_18 ( & V_251 -> V_23 ) ;
}
void F_152 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
F_153 ( & V_3 -> V_97 ) ;
F_148 ( V_13 , F_146 ( V_3 ) , 1 , false ) ;
}
static void F_154 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
F_153 ( & V_3 -> V_97 ) ;
F_148 ( V_13 , F_146 ( V_3 ) , 1 , true ) ;
}
static T_10 * F_155 ( void * V_261 )
{
T_10 * V_262 ;
V_262 = V_263 + F_156 ( V_261 , V_264 ) ;
F_16 ( V_262 ) ;
return V_262 ;
}
static void F_157 ( T_10 * V_262 )
{
if ( V_262 )
F_18 ( V_262 ) ;
}
int F_158 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_250 * V_265 = & V_13 -> V_256 ;
int V_266 , V_267 , V_252 , V_102 = - V_268 ;
T_10 * V_262 = NULL ;
int V_237 ;
V_266 = F_159 ( & V_13 -> V_260 ) ;
if ( V_266 > V_13 -> V_254 )
goto V_269;
if ( V_266 > ( V_13 -> V_254 >> 1 ) ) {
F_160 ( V_3 ) ;
V_262 = F_155 ( V_13 ) ;
}
V_237 = V_3 -> V_243 ;
F_140 ( V_3 ) ;
V_266 = F_161 ( V_237 , & V_13 -> V_260 ) ;
if ( V_266 > ( V_237 + V_13 -> V_254 ) )
goto V_270;
F_16 ( & V_265 -> V_23 ) ;
if ( V_237 >= V_13 -> V_257 ) {
V_252 = F_162 ( V_237 ) ;
V_267 = V_252 << V_259 ;
if ( ! F_163 ( V_13 , V_267 , V_252 , V_271 ) ) {
V_102 = - V_156 ;
F_18 ( & V_265 -> V_23 ) ;
goto V_270;
}
V_13 -> V_257 += V_267 ;
}
V_13 -> V_257 -= V_237 ;
F_164 ( V_13 , V_3 ) ;
F_165 ( V_265 , V_3 ) ;
F_18 ( & V_265 -> V_23 ) ;
if ( ! F_117 ( V_13 , V_272 ) )
V_13 -> V_273 ( V_13 ) ;
F_157 ( V_262 ) ;
return 0 ;
V_270:
F_150 ( V_3 -> V_243 , & V_13 -> V_260 ) ;
V_269:
F_166 ( & V_13 -> V_274 ) ;
F_157 ( V_262 ) ;
return V_102 ;
}
void F_167 ( struct V_12 * V_13 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
unsigned int V_275 = 0 ;
struct V_2 * V_3 ;
F_151 ( & V_13 -> V_256 , & V_130 -> V_255 ) ;
while ( ( V_3 = F_168 ( & V_130 -> V_255 ) ) != NULL ) {
V_275 += V_3 -> V_243 ;
F_169 ( V_3 ) ;
}
F_148 ( V_13 , V_275 , 0 , true ) ;
F_170 ( V_13 ) ;
}
int F_171 ( struct V_12 * V_13 )
{
F_172 ( & F_10 ( V_13 ) -> V_255 ) ;
V_13 -> V_276 = F_167 ;
return 0 ;
}
void F_173 ( struct V_12 * V_13 , struct V_2 * V_3 , int V_132 )
{
if ( F_60 ( F_174 ( V_13 -> V_277 ) >= 0 ) ) {
bool V_278 = F_175 ( V_13 ) ;
F_176 ( V_13 , V_132 ) ;
F_177 ( V_13 , V_278 ) ;
}
if ( ! F_178 ( V_3 ) )
return;
if ( F_60 ( F_147 ( V_3 ) ) )
F_179 ( V_3 ) ;
F_180 ( V_3 ) ;
}
static struct V_2 * F_181 ( struct V_12 * V_13 ,
struct V_250 * V_279 ,
int * V_275 )
{
struct V_2 * V_3 ;
while ( ( V_3 = F_182 ( V_279 ) ) != NULL ) {
if ( F_183 ( V_3 ) ) {
F_184 ( F_9 ( V_13 ) , V_280 ,
F_96 ( V_13 ) ) ;
F_184 ( F_9 ( V_13 ) , V_281 ,
F_96 ( V_13 ) ) ;
F_166 ( & V_13 -> V_274 ) ;
F_185 ( V_3 , V_279 ) ;
* V_275 += V_3 -> V_243 ;
F_169 ( V_3 ) ;
} else {
F_140 ( V_3 ) ;
break;
}
}
return V_3 ;
}
static int F_186 ( struct V_12 * V_13 )
{
struct V_250 * V_279 = & F_10 ( V_13 ) -> V_255 ;
struct V_250 * V_251 = & V_13 -> V_256 ;
struct V_2 * V_3 ;
int V_275 = 0 ;
int V_22 ;
F_30 ( & V_279 -> V_23 ) ;
V_3 = F_181 ( V_13 , V_279 , & V_275 ) ;
if ( ! V_3 && ! F_134 ( V_251 ) ) {
F_16 ( & V_251 -> V_23 ) ;
F_151 ( V_251 , V_279 ) ;
F_18 ( & V_251 -> V_23 ) ;
V_3 = F_181 ( V_13 , V_279 , & V_275 ) ;
}
V_22 = V_3 ? V_3 -> V_132 : - 1 ;
if ( V_275 )
F_148 ( V_13 , V_275 , 1 , false ) ;
F_33 ( & V_279 -> V_23 ) ;
return V_22 ;
}
int F_187 ( struct V_12 * V_13 , int V_282 , unsigned long V_283 )
{
switch ( V_282 ) {
case V_284 :
{
int V_285 = F_188 ( V_13 ) ;
return F_189 ( V_285 , ( int V_286 * ) V_283 ) ;
}
case V_287 :
{
int V_285 = F_190 ( int , 0 , F_186 ( V_13 ) ) ;
return F_189 ( V_285 , ( int V_286 * ) V_283 ) ;
}
default:
return - V_288 ;
}
return 0 ;
}
struct V_2 * F_191 ( struct V_12 * V_13 , unsigned int V_7 ,
int V_289 , int * V_290 , int * V_291 , int * V_102 )
{
struct V_250 * V_251 = & V_13 -> V_256 ;
struct V_250 * V_292 ;
struct V_2 * V_35 ;
long V_293 ;
int error ;
V_292 = & F_10 ( V_13 ) -> V_255 ;
V_7 |= V_289 ? V_294 : 0 ;
V_293 = F_192 ( V_13 , V_7 & V_294 ) ;
do {
struct V_2 * V_3 ;
error = F_193 ( V_13 ) ;
if ( error )
break;
error = - V_295 ;
* V_290 = 0 ;
do {
F_30 ( & V_292 -> V_23 ) ;
V_3 = F_194 ( V_13 , V_292 , V_7 ,
F_152 ,
V_290 , V_291 , V_102 ,
& V_35 ) ;
if ( V_3 ) {
F_33 ( & V_292 -> V_23 ) ;
return V_3 ;
}
if ( F_134 ( V_251 ) ) {
F_33 ( & V_292 -> V_23 ) ;
goto V_296;
}
F_16 ( & V_251 -> V_23 ) ;
F_151 ( V_251 , V_292 ) ;
V_3 = F_194 ( V_13 , V_292 , V_7 ,
F_154 ,
V_290 , V_291 , V_102 ,
& V_35 ) ;
F_18 ( & V_251 -> V_23 ) ;
F_33 ( & V_292 -> V_23 ) ;
if ( V_3 )
return V_3 ;
V_296:
if ( ! F_195 ( V_13 ) )
break;
F_196 ( V_13 , V_7 & V_294 ) ;
} while ( ! F_134 ( V_251 ) );
} while ( V_293 &&
! F_197 ( V_13 , & error , & V_293 ,
(struct V_2 * ) V_251 ) );
* V_102 = error ;
return NULL ;
}
int F_198 ( struct V_12 * V_13 , struct V_163 * V_164 , T_8 V_132 , int V_289 ,
int V_7 , int * V_297 )
{
struct V_65 * V_66 = F_36 ( V_13 ) ;
F_109 ( struct V_190 * , sin , V_164 -> V_189 ) ;
struct V_2 * V_3 ;
unsigned int V_166 , V_298 ;
int V_290 , V_299 , V_291 ;
int V_102 ;
int V_150 = F_96 ( V_13 ) ;
bool V_300 = false ;
if ( V_7 & V_301 )
return F_199 ( V_13 , V_164 , V_132 , V_297 ) ;
V_302:
V_299 = V_7 & V_303 ;
V_291 = F_200 ( V_13 , V_7 ) ;
V_3 = F_191 ( V_13 , V_7 , V_289 , & V_290 , & V_291 , & V_102 ) ;
if ( ! V_3 )
return V_102 ;
V_166 = F_201 ( V_3 ) ;
V_298 = V_132 ;
if ( V_298 > V_166 - V_291 )
V_298 = V_166 - V_291 ;
else if ( V_298 < V_166 )
V_164 -> V_175 |= V_304 ;
if ( V_298 < V_166 || V_299 ||
( V_150 && F_202 ( V_3 ) -> V_305 ) ) {
V_300 = F_203 ( V_3 ) ||
! F_204 ( V_3 ) ;
if ( ! V_300 )
goto V_306;
}
if ( V_300 || F_203 ( V_3 ) ) {
if ( F_205 ( V_3 ) )
V_102 = F_206 ( V_3 , V_298 , V_291 , & V_164 -> V_307 ) ;
else
V_102 = F_207 ( V_3 , V_291 , V_164 , V_298 ) ;
} else {
V_102 = F_208 ( V_3 , V_291 , V_164 ) ;
if ( V_102 == - V_187 )
goto V_306;
}
if ( F_60 ( V_102 ) ) {
if ( ! V_290 ) {
F_166 ( & V_13 -> V_274 ) ;
F_101 ( F_9 ( V_13 ) ,
V_281 , V_150 ) ;
}
F_169 ( V_3 ) ;
return V_102 ;
}
if ( ! V_290 )
F_101 ( F_9 ( V_13 ) ,
V_308 , V_150 ) ;
F_209 ( V_164 , V_13 , V_3 ) ;
if ( sin ) {
sin -> V_193 = V_186 ;
sin -> V_198 = F_82 ( V_3 ) -> V_104 ;
sin -> V_196 . V_197 = F_63 ( V_3 ) -> V_52 ;
memset ( sin -> V_309 , 0 , sizeof( sin -> V_309 ) ) ;
* V_297 = sizeof( * sin ) ;
}
if ( V_66 -> V_310 )
F_210 ( V_164 , V_13 , V_3 , sizeof( struct V_82 ) , V_291 ) ;
V_102 = V_298 ;
if ( V_7 & V_304 )
V_102 = V_166 ;
F_173 ( V_13 , V_3 , V_299 ? - V_102 : V_102 ) ;
return V_102 ;
V_306:
if ( ! F_211 ( V_13 , & F_10 ( V_13 ) -> V_255 , V_3 , V_7 ,
F_152 ) ) {
F_101 ( F_9 ( V_13 ) , V_280 , V_150 ) ;
F_101 ( F_9 ( V_13 ) , V_281 , V_150 ) ;
}
F_169 ( V_3 ) ;
F_34 () ;
V_164 -> V_175 &= ~ V_304 ;
goto V_302;
}
int F_212 ( struct V_12 * V_13 , int V_7 )
{
struct V_65 * V_66 = F_36 ( V_13 ) ;
V_13 -> V_124 = V_311 ;
V_66 -> V_68 = 0 ;
V_66 -> V_69 = 0 ;
F_213 ( V_13 ) ;
V_13 -> V_18 = 0 ;
if ( ! ( V_13 -> V_312 & V_313 ) )
F_214 ( V_13 ) ;
if ( ! ( V_13 -> V_312 & V_314 ) ) {
V_13 -> V_29 -> V_315 ( V_13 ) ;
V_66 -> V_151 = 0 ;
}
F_215 ( V_13 ) ;
return 0 ;
}
int F_216 ( struct V_12 * V_13 , int V_7 )
{
F_106 ( V_13 ) ;
F_212 ( V_13 , V_7 ) ;
F_108 ( V_13 ) ;
return 0 ;
}
void F_217 ( struct V_12 * V_13 )
{
if ( F_218 ( V_13 ) ) {
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
struct V_9 * V_10 , * V_21 ;
V_10 = F_28 ( V_28 , F_9 ( V_13 ) ,
F_10 ( V_13 ) -> V_16 ) ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( F_12 ( V_13 -> V_20 ) )
F_219 ( V_13 ) ;
if ( F_220 ( V_13 ) ) {
V_10 -> V_40 -- ;
F_36 ( V_13 ) -> V_46 = 0 ;
F_39 ( F_9 ( V_13 ) , V_13 -> V_29 , - 1 ) ;
F_16 ( & V_21 -> V_23 ) ;
F_221 ( & F_10 ( V_13 ) -> V_50 ) ;
V_21 -> V_40 -- ;
F_18 ( & V_21 -> V_23 ) ;
}
F_33 ( & V_10 -> V_23 ) ;
}
}
void F_222 ( struct V_12 * V_13 , T_11 V_316 )
{
if ( F_218 ( V_13 ) ) {
struct V_27 * V_28 = V_13 -> V_29 -> V_30 . V_27 ;
struct V_9 * V_10 , * V_21 , * V_317 ;
V_21 = F_35 ( V_28 , F_10 ( V_13 ) -> V_43 ) ;
V_317 = F_35 ( V_28 , V_316 ) ;
F_10 ( V_13 ) -> V_43 = V_316 ;
if ( V_21 != V_317 ||
F_12 ( V_13 -> V_20 ) ) {
V_10 = F_28 ( V_28 , F_9 ( V_13 ) ,
F_10 ( V_13 ) -> V_16 ) ;
F_30 ( & V_10 -> V_23 ) ;
if ( F_12 ( V_13 -> V_20 ) )
F_219 ( V_13 ) ;
if ( V_21 != V_317 ) {
F_16 ( & V_21 -> V_23 ) ;
F_221 ( & F_10 ( V_13 ) -> V_50 ) ;
V_21 -> V_40 -- ;
F_18 ( & V_21 -> V_23 ) ;
F_16 ( & V_317 -> V_23 ) ;
F_41 ( & F_10 ( V_13 ) -> V_50 ,
& V_317 -> V_47 ) ;
V_317 -> V_40 ++ ;
F_18 ( & V_317 -> V_23 ) ;
}
F_33 ( & V_10 -> V_23 ) ;
}
}
}
static void F_223 ( struct V_12 * V_13 )
{
T_11 V_318 = F_43 ( F_9 ( V_13 ) ,
F_36 ( V_13 ) -> V_57 ,
F_36 ( V_13 ) -> V_46 ) ;
F_222 ( V_13 , V_318 ) ;
}
static int F_224 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
int V_319 ;
if ( F_36 ( V_13 ) -> V_68 ) {
F_225 ( V_13 , V_3 ) ;
F_226 ( V_13 , V_3 ) ;
F_227 ( V_13 ) ;
} else {
F_228 ( V_13 , V_3 ) ;
}
V_319 = F_158 ( V_13 , V_3 ) ;
if ( V_319 < 0 ) {
int V_150 = F_96 ( V_13 ) ;
if ( V_319 == - V_268 )
F_101 ( F_9 ( V_13 ) , V_320 ,
V_150 ) ;
F_101 ( F_9 ( V_13 ) , V_281 , V_150 ) ;
F_169 ( V_3 ) ;
F_229 ( V_319 , V_13 ) ;
return - 1 ;
}
return 0 ;
}
void F_230 ( void )
{
F_231 ( & V_321 ) ;
}
static int F_232 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
int V_150 = F_96 ( V_13 ) ;
if ( ! F_233 ( V_13 , V_322 , V_3 ) )
goto V_269;
F_234 ( V_3 ) ;
if ( F_235 ( & V_321 ) && V_130 -> V_323 ) {
int (* F_236)( struct V_12 * V_13 , struct V_2 * V_3 );
F_236 = F_237 ( V_130 -> F_236 ) ;
if ( F_236 ) {
int V_238 ;
if ( F_183 ( V_3 ) )
goto V_324;
V_238 = F_236 ( V_13 , V_3 ) ;
if ( V_238 <= 0 ) {
F_184 ( F_9 ( V_13 ) ,
V_308 ,
V_150 ) ;
return - V_238 ;
}
}
}
if ( ( V_150 & V_325 ) && F_202 ( V_3 ) -> V_305 ) {
if ( V_130 -> V_326 == 0 ) {
F_132 ( L_3 ,
F_202 ( V_3 ) -> V_327 , V_3 -> V_132 ) ;
goto V_269;
}
if ( F_202 ( V_3 ) -> V_327 < V_130 -> V_326 ) {
F_132 ( L_4 ,
F_202 ( V_3 ) -> V_327 , V_130 -> V_326 ) ;
goto V_269;
}
}
F_153 ( & V_13 -> V_260 ) ;
if ( F_12 ( V_13 -> V_328 ) &&
F_183 ( V_3 ) )
goto V_324;
if ( F_238 ( V_13 , V_3 , sizeof( struct V_82 ) ) )
goto V_269;
F_239 ( V_3 ) ;
F_240 ( V_13 , V_3 ) ;
return F_224 ( V_13 , V_3 ) ;
V_324:
F_184 ( F_9 ( V_13 ) , V_280 , V_150 ) ;
V_269:
F_184 ( F_9 ( V_13 ) , V_281 , V_150 ) ;
F_166 ( & V_13 -> V_274 ) ;
F_169 ( V_3 ) ;
return - 1 ;
}
bool F_241 ( struct V_12 * V_13 , struct V_329 * V_134 )
{
struct V_329 * V_330 ;
if ( F_242 ( V_134 ) ) {
V_330 = F_243 ( & V_13 -> V_331 , V_134 ) ;
F_244 ( V_330 ) ;
return V_330 != V_134 ;
}
return false ;
}
static int F_245 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_82 * V_98 ,
T_4 V_52 , T_4 V_59 ,
struct V_27 * V_28 ,
int V_332 )
{
struct V_12 * V_13 , * V_34 = NULL ;
unsigned short V_60 = F_58 ( V_98 -> V_103 ) ;
struct V_9 * V_10 = F_28 ( V_28 , V_1 , V_60 ) ;
unsigned int V_84 = 0 , V_333 = 0 , V_334 = ( V_10 -> V_40 > 10 ) ;
unsigned int V_135 = F_86 ( F_246 ( * V_13 ) , V_335 ) ;
int V_61 = V_3 -> V_90 -> V_105 ;
int V_62 = F_66 ( V_3 ) ;
struct V_336 * V_337 ;
struct V_2 * V_338 ;
if ( V_334 ) {
V_333 = F_43 ( V_1 , F_47 ( V_55 ) , V_60 ) &
V_28 -> V_37 ;
V_84 = F_43 ( V_1 , V_59 , V_60 ) & V_28 -> V_37 ;
V_339:
V_10 = & V_28 -> V_84 [ V_84 ] ;
V_135 = F_86 ( F_246 ( * V_13 ) , V_340 . V_341 ) ;
}
F_247 (sk, node, &hslot->head, offset) {
if ( ! F_70 ( V_1 , V_13 , V_98 -> V_103 , V_59 ,
V_98 -> V_104 , V_52 , V_61 , V_62 , V_60 ) )
continue;
if ( ! V_34 ) {
V_34 = V_13 ;
continue;
}
V_338 = F_248 ( V_3 , V_342 ) ;
if ( F_60 ( ! V_338 ) ) {
F_166 ( & V_13 -> V_274 ) ;
F_184 ( V_1 , V_320 ,
F_96 ( V_13 ) ) ;
F_184 ( V_1 , V_281 ,
F_96 ( V_13 ) ) ;
continue;
}
if ( F_232 ( V_13 , V_338 ) > 0 )
F_249 ( V_338 ) ;
}
if ( V_334 && V_84 != V_333 ) {
V_84 = V_333 ;
goto V_339;
}
if ( V_34 ) {
if ( F_232 ( V_34 , V_3 ) > 0 )
F_249 ( V_3 ) ;
} else {
F_169 ( V_3 ) ;
F_184 ( V_1 , V_343 ,
V_332 == V_344 ) ;
}
return 0 ;
}
static inline int F_250 ( struct V_2 * V_3 , struct V_82 * V_98 ,
int V_332 )
{
int V_102 ;
F_202 ( V_3 ) -> V_305 = 0 ;
F_202 ( V_3 ) -> V_327 = V_3 -> V_132 ;
if ( V_332 == V_344 ) {
V_102 = F_251 ( V_3 , V_98 ) ;
if ( V_102 )
return V_102 ;
}
return ( V_54 int ) F_252 ( V_3 , V_332 , V_98 -> V_140 ,
V_345 ) ;
}
int F_253 ( struct V_2 * V_3 , struct V_27 * V_28 ,
int V_332 )
{
struct V_12 * V_13 ;
struct V_82 * V_98 ;
unsigned short V_166 ;
struct V_169 * V_170 = F_254 ( V_3 ) ;
T_4 V_52 , V_59 ;
struct V_1 * V_1 = F_64 ( V_3 -> V_90 ) ;
if ( ! F_255 ( V_3 , sizeof( struct V_82 ) ) )
goto V_269;
V_98 = F_82 ( V_3 ) ;
V_166 = F_58 ( V_98 -> V_132 ) ;
V_52 = F_63 ( V_3 ) -> V_52 ;
V_59 = F_63 ( V_3 ) -> V_59 ;
if ( V_166 > V_3 -> V_132 )
goto V_346;
if ( V_332 == V_141 ) {
if ( V_166 < sizeof( * V_98 ) || F_256 ( V_3 , V_166 ) )
goto V_346;
V_98 = F_82 ( V_3 ) ;
}
if ( F_250 ( V_3 , V_98 , V_332 ) )
goto V_324;
V_13 = F_257 ( V_3 ) ;
if ( V_13 ) {
struct V_329 * V_134 = F_258 ( V_3 ) ;
int V_238 ;
if ( F_60 ( V_13 -> V_331 != V_134 ) )
F_241 ( V_13 , V_134 ) ;
V_238 = F_232 ( V_13 , V_3 ) ;
F_259 ( V_13 ) ;
if ( V_238 > 0 )
return - V_238 ;
return 0 ;
}
if ( V_170 -> V_225 & ( V_226 | V_347 ) )
return F_245 ( V_1 , V_3 , V_98 ,
V_52 , V_59 , V_28 , V_332 ) ;
V_13 = F_62 ( V_3 , V_98 -> V_104 , V_98 -> V_103 , V_28 ) ;
if ( V_13 ) {
int V_238 ;
if ( F_260 ( V_13 ) && V_98 -> V_140 && ! F_96 ( V_13 ) )
F_261 ( V_3 , V_141 , V_98 -> V_140 ,
V_345 ) ;
V_238 = F_232 ( V_13 , V_3 ) ;
if ( V_238 > 0 )
return - V_238 ;
return 0 ;
}
if ( ! F_233 ( NULL , V_322 , V_3 ) )
goto V_269;
F_234 ( V_3 ) ;
if ( F_183 ( V_3 ) )
goto V_324;
F_184 ( V_1 , V_348 , V_332 == V_344 ) ;
F_262 ( V_3 , V_113 , V_349 , 0 ) ;
F_169 ( V_3 ) ;
return 0 ;
V_346:
F_132 ( L_5 ,
V_332 == V_344 ? L_6 : L_7 ,
& V_52 , F_58 ( V_98 -> V_104 ) ,
V_166 , V_3 -> V_132 ,
& V_59 , F_58 ( V_98 -> V_103 ) ) ;
goto V_269;
V_324:
F_132 ( L_8 ,
V_332 == V_344 ? L_6 : L_7 ,
& V_52 , F_58 ( V_98 -> V_104 ) , & V_59 , F_58 ( V_98 -> V_103 ) ,
V_166 ) ;
F_184 ( V_1 , V_280 , V_332 == V_344 ) ;
V_269:
F_184 ( V_1 , V_281 , V_332 == V_344 ) ;
F_169 ( V_3 ) ;
return 0 ;
}
static struct V_12 * F_263 ( struct V_1 * V_1 ,
T_5 V_92 , T_4 V_93 ,
T_5 V_94 , T_4 V_95 ,
int V_61 , int V_62 )
{
struct V_12 * V_13 , * V_77 ;
unsigned short V_60 = F_58 ( V_92 ) ;
unsigned int V_85 = F_59 ( V_1 , V_60 , V_27 . V_37 ) ;
struct V_9 * V_10 = & V_27 . V_81 [ V_85 ] ;
if ( V_10 -> V_40 > 10 )
return NULL ;
V_77 = NULL ;
F_61 (sk, &hslot->head) {
if ( F_70 ( V_1 , V_13 , V_92 , V_93 ,
V_94 , V_95 , V_61 , V_62 , V_60 ) ) {
if ( V_77 )
return NULL ;
V_77 = V_13 ;
}
}
return V_77 ;
}
static struct V_12 * F_264 ( struct V_1 * V_1 ,
T_5 V_92 , T_4 V_93 ,
T_5 V_94 , T_4 V_95 ,
int V_61 , int V_62 )
{
unsigned short V_60 = F_58 ( V_92 ) ;
unsigned int V_84 = F_43 ( V_1 , V_93 , V_60 ) ;
unsigned int V_42 = V_84 & V_27 . V_37 ;
struct V_9 * V_21 = & V_27 . V_84 [ V_42 ] ;
F_265 ( V_350 , V_95 , V_93 ) ;
const T_12 V_351 = F_266 ( V_94 , V_60 ) ;
struct V_12 * V_13 ;
F_54 (sk, &hslot2->head) {
if ( F_267 ( V_13 , V_1 , V_350 , V_95 ,
V_93 , V_351 , V_61 , V_62 ) )
return V_13 ;
break;
}
return NULL ;
}
int F_268 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_64 ( V_3 -> V_90 ) ;
struct V_352 * V_353 = NULL ;
const struct V_88 * V_89 ;
const struct V_82 * V_98 ;
struct V_12 * V_13 = NULL ;
struct V_329 * V_134 ;
int V_61 = V_3 -> V_90 -> V_105 ;
int V_62 = F_66 ( V_3 ) ;
int V_354 ;
if ( ! F_255 ( V_3 , F_83 ( V_3 ) + sizeof( struct V_82 ) ) )
return 0 ;
V_89 = F_63 ( V_3 ) ;
V_98 = F_82 ( V_3 ) ;
if ( V_3 -> V_355 == V_356 ) {
V_353 = F_269 ( V_3 -> V_90 ) ;
if ( ! V_353 )
return 0 ;
V_354 = F_270 ( V_353 , V_89 -> V_59 , V_89 -> V_52 ,
V_89 -> V_357 ) ;
if ( ! V_354 )
return 0 ;
V_13 = F_263 ( V_1 , V_98 -> V_103 , V_89 -> V_59 ,
V_98 -> V_104 , V_89 -> V_52 ,
V_61 , V_62 ) ;
} else if ( V_3 -> V_355 == V_358 ) {
V_13 = F_264 ( V_1 , V_98 -> V_103 , V_89 -> V_59 ,
V_98 -> V_104 , V_89 -> V_52 , V_61 , V_62 ) ;
}
if ( ! V_13 || ! F_69 ( & V_13 -> V_91 ) )
return 0 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_359 = V_360 ;
V_134 = F_174 ( V_13 -> V_331 ) ;
if ( V_134 )
V_134 = F_271 ( V_134 , 0 ) ;
if ( V_134 ) {
T_3 V_361 = 0 ;
F_272 ( V_3 , V_134 ) ;
if ( ! F_36 ( V_13 ) -> V_68 && V_353 )
return F_273 ( V_3 , V_89 -> V_59 ,
V_89 -> V_52 , V_89 -> V_172 ,
V_3 -> V_90 , V_353 , & V_361 ) ;
}
return 0 ;
}
int F_274 ( struct V_2 * V_3 )
{
return F_253 ( V_3 , & V_27 , V_141 ) ;
}
void F_275 ( struct V_12 * V_13 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
bool V_278 = F_175 ( V_13 ) ;
F_79 ( V_13 ) ;
F_177 ( V_13 , V_278 ) ;
if ( F_235 ( & V_321 ) && V_130 -> V_323 ) {
void (* F_276)( struct V_12 * V_13 );
F_276 = F_237 ( V_130 -> F_276 ) ;
if ( F_276 )
F_276 ( V_13 ) ;
}
}
int F_277 ( struct V_12 * V_13 , int V_362 , int V_363 ,
char V_286 * V_364 , unsigned int V_209 ,
int (* F_278)( struct V_12 * ) )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
int V_365 , V_366 ;
int V_102 = 0 ;
int V_150 = F_96 ( V_13 ) ;
if ( V_209 < sizeof( int ) )
return - V_187 ;
if ( F_279 ( V_365 , ( int V_286 * ) V_364 ) )
return - V_367 ;
V_366 = V_365 ? 1 : 0 ;
switch ( V_363 ) {
case V_368 :
if ( V_365 != 0 ) {
V_130 -> V_174 = 1 ;
} else {
V_130 -> V_174 = 0 ;
F_106 ( V_13 ) ;
F_278 ( V_13 ) ;
F_108 ( V_13 ) ;
}
break;
case V_369 :
switch ( V_365 ) {
case 0 :
case V_370 :
case V_371 :
V_130 -> F_236 = V_372 ;
case V_373 :
V_130 -> V_323 = V_365 ;
F_230 () ;
break;
default:
V_102 = - V_374 ;
break;
}
break;
case V_375 :
V_130 -> V_376 = V_366 ;
break;
case V_377 :
V_130 -> V_378 = V_366 ;
break;
case V_379 :
if ( ! V_150 )
return - V_374 ;
if ( V_365 != 0 && V_365 < 8 )
V_365 = 8 ;
else if ( V_365 > V_380 )
V_365 = V_380 ;
V_130 -> V_381 = V_365 ;
V_130 -> V_382 |= V_383 ;
break;
case V_384 :
if ( ! V_150 )
return - V_374 ;
if ( V_365 != 0 && V_365 < 8 )
V_365 = 8 ;
else if ( V_365 > V_380 )
V_365 = V_380 ;
V_130 -> V_326 = V_365 ;
V_130 -> V_382 |= V_325 ;
break;
default:
V_102 = - V_374 ;
break;
}
return V_102 ;
}
int F_280 ( struct V_12 * V_13 , int V_362 , int V_363 ,
char V_286 * V_364 , unsigned int V_209 )
{
if ( V_362 == V_385 || V_362 == V_386 )
return F_277 ( V_13 , V_362 , V_363 , V_364 , V_209 ,
F_102 ) ;
return F_281 ( V_13 , V_362 , V_363 , V_364 , V_209 ) ;
}
int F_282 ( struct V_12 * V_13 , int V_362 , int V_363 ,
char V_286 * V_364 , unsigned int V_209 )
{
if ( V_362 == V_385 || V_362 == V_386 )
return F_277 ( V_13 , V_362 , V_363 , V_364 , V_209 ,
F_102 ) ;
return F_283 ( V_13 , V_362 , V_363 , V_364 , V_209 ) ;
}
int F_284 ( struct V_12 * V_13 , int V_362 , int V_363 ,
char V_286 * V_364 , int V_286 * V_209 )
{
struct V_129 * V_130 = F_10 ( V_13 ) ;
int V_365 , V_132 ;
if ( F_279 ( V_132 , V_209 ) )
return - V_367 ;
V_132 = F_285 (unsigned int, len, sizeof(int)) ;
if ( V_132 < 0 )
return - V_187 ;
switch ( V_363 ) {
case V_368 :
V_365 = V_130 -> V_174 ;
break;
case V_369 :
V_365 = V_130 -> V_323 ;
break;
case V_375 :
V_365 = V_130 -> V_376 ;
break;
case V_377 :
V_365 = V_130 -> V_378 ;
break;
case V_379 :
V_365 = V_130 -> V_381 ;
break;
case V_384 :
V_365 = V_130 -> V_326 ;
break;
default:
return - V_374 ;
}
if ( F_189 ( V_132 , V_209 ) )
return - V_367 ;
if ( F_286 ( V_364 , & V_365 , V_132 ) )
return - V_367 ;
return 0 ;
}
int F_287 ( struct V_12 * V_13 , int V_362 , int V_363 ,
char V_286 * V_364 , int V_286 * V_209 )
{
if ( V_362 == V_385 || V_362 == V_386 )
return F_284 ( V_13 , V_362 , V_363 , V_364 , V_209 ) ;
return F_288 ( V_13 , V_362 , V_363 , V_364 , V_209 ) ;
}
int F_289 ( struct V_12 * V_13 , int V_362 , int V_363 ,
char V_286 * V_364 , int V_286 * V_209 )
{
if ( V_362 == V_385 || V_362 == V_386 )
return F_284 ( V_13 , V_362 , V_363 , V_364 , V_209 ) ;
return F_290 ( V_13 , V_362 , V_363 , V_364 , V_209 ) ;
}
unsigned int F_291 ( struct V_387 * V_387 , struct V_388 * V_12 , T_13 * V_389 )
{
unsigned int V_37 = F_292 ( V_387 , V_12 , V_389 ) ;
struct V_12 * V_13 = V_12 -> V_13 ;
if ( ! F_134 ( & F_10 ( V_13 ) -> V_255 ) )
V_37 |= V_390 | V_391 ;
F_293 ( V_13 ) ;
if ( ( V_37 & V_391 ) && ! ( V_387 -> V_392 & V_393 ) &&
! ( V_13 -> V_394 & V_395 ) && F_186 ( V_13 ) == - 1 )
V_37 &= ~ ( V_390 | V_391 ) ;
return V_37 ;
}
int F_294 ( struct V_12 * V_13 , int V_102 )
{
F_106 ( V_13 ) ;
V_13 -> V_127 = V_102 ;
V_13 -> V_128 ( V_13 ) ;
F_212 ( V_13 , 0 ) ;
F_108 ( V_13 ) ;
return 0 ;
}
static struct V_12 * F_295 ( struct V_396 * V_397 , int V_398 )
{
struct V_12 * V_13 ;
struct V_399 * V_400 = V_397 -> V_401 ;
struct V_1 * V_1 = F_296 ( V_397 ) ;
for ( V_400 -> V_402 = V_398 ; V_400 -> V_402 <= V_400 -> V_27 -> V_37 ;
++ V_400 -> V_402 ) {
struct V_9 * V_10 = & V_400 -> V_27 -> V_81 [ V_400 -> V_402 ] ;
if ( F_297 ( & V_10 -> V_47 ) )
continue;
F_30 ( & V_10 -> V_23 ) ;
F_7 (sk, &hslot->head) {
if ( ! F_8 ( F_9 ( V_13 ) , V_1 ) )
continue;
if ( V_13 -> V_24 == V_400 -> V_403 )
goto V_38;
}
F_33 ( & V_10 -> V_23 ) ;
}
V_13 = NULL ;
V_38:
return V_13 ;
}
static struct V_12 * F_298 ( struct V_396 * V_397 , struct V_12 * V_13 )
{
struct V_399 * V_400 = V_397 -> V_401 ;
struct V_1 * V_1 = F_296 ( V_397 ) ;
do {
V_13 = F_299 ( V_13 ) ;
} while ( V_13 && ( ! F_8 ( F_9 ( V_13 ) , V_1 ) || V_13 -> V_24 != V_400 -> V_403 ) );
if ( ! V_13 ) {
if ( V_400 -> V_402 <= V_400 -> V_27 -> V_37 )
F_33 ( & V_400 -> V_27 -> V_81 [ V_400 -> V_402 ] . V_23 ) ;
return F_295 ( V_397 , V_400 -> V_402 + 1 ) ;
}
return V_13 ;
}
static struct V_12 * F_300 ( struct V_396 * V_397 , T_14 V_404 )
{
struct V_12 * V_13 = F_295 ( V_397 , 0 ) ;
if ( V_13 )
while ( V_404 && ( V_13 = F_298 ( V_397 , V_13 ) ) != NULL )
-- V_404 ;
return V_404 ? NULL : V_13 ;
}
static void * F_301 ( struct V_396 * V_397 , T_14 * V_404 )
{
struct V_399 * V_400 = V_397 -> V_401 ;
V_400 -> V_402 = V_405 ;
return * V_404 ? F_300 ( V_397 , * V_404 - 1 ) : V_406 ;
}
static void * F_302 ( struct V_396 * V_397 , void * V_407 , T_14 * V_404 )
{
struct V_12 * V_13 ;
if ( V_407 == V_406 )
V_13 = F_300 ( V_397 , 0 ) ;
else
V_13 = F_298 ( V_397 , V_407 ) ;
++ * V_404 ;
return V_13 ;
}
static void F_303 ( struct V_396 * V_397 , void * V_407 )
{
struct V_399 * V_400 = V_397 -> V_401 ;
if ( V_400 -> V_402 <= V_400 -> V_27 -> V_37 )
F_33 ( & V_400 -> V_27 -> V_81 [ V_400 -> V_402 ] . V_23 ) ;
}
int F_304 ( struct V_408 * V_408 , struct V_387 * V_387 )
{
struct V_409 * V_410 = F_305 ( V_408 ) ;
struct V_399 * V_411 ;
int V_102 ;
V_102 = F_306 ( V_408 , V_387 , & V_410 -> V_412 ,
sizeof( struct V_399 ) ) ;
if ( V_102 < 0 )
return V_102 ;
V_411 = ( (struct V_396 * ) V_387 -> V_413 ) -> V_401 ;
V_411 -> V_403 = V_410 -> V_403 ;
V_411 -> V_27 = V_410 -> V_27 ;
return V_102 ;
}
int F_307 ( struct V_1 * V_1 , struct V_409 * V_410 )
{
struct V_414 * V_415 ;
int V_319 = 0 ;
V_410 -> V_412 . V_398 = F_301 ;
V_410 -> V_412 . V_416 = F_302 ;
V_410 -> V_412 . V_417 = F_303 ;
V_415 = F_308 ( V_410 -> V_418 , V_419 , V_1 -> V_420 ,
V_410 -> V_421 , V_410 ) ;
if ( ! V_415 )
V_319 = - V_268 ;
return V_319 ;
}
void F_309 ( struct V_1 * V_1 , struct V_409 * V_410 )
{
F_310 ( V_410 -> V_418 , V_1 -> V_420 ) ;
}
static void F_311 ( struct V_12 * V_422 , struct V_396 * V_423 ,
int V_402 )
{
struct V_65 * V_66 = F_36 ( V_422 ) ;
T_4 V_103 = V_66 -> V_68 ;
T_4 V_133 = V_66 -> V_57 ;
T_1 V_424 = F_58 ( V_66 -> V_69 ) ;
T_1 V_425 = F_58 ( V_66 -> V_151 ) ;
F_312 ( V_423 , L_9
L_10 ,
V_402 , V_133 , V_425 , V_103 , V_424 , V_422 -> V_124 ,
F_188 ( V_422 ) ,
F_313 ( V_422 ) ,
0 , 0L , 0 ,
F_314 ( F_315 ( V_423 ) , F_6 ( V_422 ) ) ,
0 , F_316 ( V_422 ) ,
F_317 ( & V_422 -> V_91 ) , V_422 ,
F_159 ( & V_422 -> V_274 ) ) ;
}
int F_318 ( struct V_396 * V_397 , void * V_407 )
{
F_319 ( V_397 , 127 ) ;
if ( V_407 == V_406 )
F_320 ( V_397 , L_11
L_12
L_13 ) ;
else {
struct V_399 * V_400 = V_397 -> V_401 ;
F_311 ( V_407 , V_397 , V_400 -> V_402 ) ;
}
F_321 ( V_397 , '\n' ) ;
return 0 ;
}
static int T_15 F_322 ( struct V_1 * V_1 )
{
return F_307 ( V_1 , & V_426 ) ;
}
static void T_16 F_323 ( struct V_1 * V_1 )
{
F_309 ( V_1 , & V_426 ) ;
}
int T_17 F_324 ( void )
{
return F_325 ( & V_427 ) ;
}
void F_326 ( void )
{
F_327 ( & V_427 ) ;
}
static int T_17 F_328 ( char * V_428 )
{
T_18 V_238 ;
if ( ! V_428 )
return 0 ;
V_238 = F_329 ( V_428 , 0 , & V_429 ) ;
if ( V_238 )
return 0 ;
if ( V_429 && V_429 < V_430 )
V_429 = V_430 ;
return 1 ;
}
void T_17 F_330 ( struct V_27 * V_431 , const char * V_418 )
{
unsigned int V_432 ;
V_431 -> V_81 = F_331 ( V_418 ,
2 * sizeof( struct V_9 ) ,
V_429 ,
21 ,
0 ,
& V_431 -> log ,
& V_431 -> V_37 ,
V_430 ,
64 * 1024 ) ;
V_431 -> V_84 = V_431 -> V_81 + ( V_431 -> V_37 + 1 ) ;
for ( V_432 = 0 ; V_432 <= V_431 -> V_37 ; V_432 ++ ) {
F_332 ( & V_431 -> V_81 [ V_432 ] . V_47 ) ;
V_431 -> V_81 [ V_432 ] . V_40 = 0 ;
F_333 ( & V_431 -> V_81 [ V_432 ] . V_23 ) ;
}
for ( V_432 = 0 ; V_432 <= V_431 -> V_37 ; V_432 ++ ) {
F_332 ( & V_431 -> V_84 [ V_432 ] . V_47 ) ;
V_431 -> V_84 [ V_432 ] . V_40 = 0 ;
F_333 ( & V_431 -> V_84 [ V_432 ] . V_23 ) ;
}
}
T_3 F_334 ( void )
{
static T_3 T_19 V_76 ;
F_51 ( & T_19 , sizeof( T_19 ) ) ;
return T_19 ;
}
void T_17 F_335 ( void )
{
unsigned long V_433 ;
unsigned int V_432 ;
F_330 ( & V_27 , L_14 ) ;
V_433 = F_336 () / 8 ;
V_433 = F_337 ( V_433 , 128UL ) ;
V_434 [ 0 ] = V_433 / 4 * 3 ;
V_434 [ 1 ] = V_433 ;
V_434 [ 2 ] = V_434 [ 0 ] * 2 ;
V_435 = V_258 ;
V_436 = V_258 ;
V_264 = F_338 ( V_437 ) + 4 ;
V_263 = F_339 ( sizeof( T_10 ) << V_264 ,
V_438 ) ;
if ( ! V_263 )
F_340 ( L_15 ) ;
for ( V_432 = 0 ; V_432 < ( 1U << V_264 ) ; V_432 ++ )
F_333 ( V_263 + V_432 ) ;
}
