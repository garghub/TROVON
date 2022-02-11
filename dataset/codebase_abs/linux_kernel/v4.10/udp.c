static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
unsigned long * V_5 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) ,
unsigned int log )
{
struct V_6 * V_9 ;
T_2 V_11 = F_3 ( V_7 ) ;
F_4 (sk2, &hslot->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( V_5 || F_7 ( V_9 ) -> V_12 == V_2 ) &&
( ! V_9 -> V_13 || ! V_7 -> V_13 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ||
V_9 -> V_14 == V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
F_8 ( V_7 -> V_16 ) ||
! F_9 ( V_11 , F_3 ( V_9 ) ) ) &&
F_2 ( V_7 , V_9 , true ) ) {
if ( ! V_5 )
return 1 ;
F_10 ( F_7 ( V_9 ) -> V_12 >> log , V_5 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_3 * V_17 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) )
{
struct V_6 * V_9 ;
T_2 V_11 = F_3 ( V_7 ) ;
int V_18 = 0 ;
F_12 ( & V_17 -> V_19 ) ;
F_13 (sk2, &hslot2->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( F_7 ( V_9 ) -> V_12 == V_2 ) &&
( ! V_9 -> V_13 || ! V_7 -> V_13 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ||
V_9 -> V_14 == V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
F_8 ( V_7 -> V_16 ) ||
! F_9 ( V_11 , F_3 ( V_9 ) ) ) &&
F_2 ( V_7 , V_9 , true ) ) {
V_18 = 1 ;
break;
}
}
F_14 ( & V_17 -> V_19 ) ;
return V_18 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_3 * V_4 ,
int (* F_16)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
T_2 V_11 = F_3 ( V_7 ) ;
struct V_6 * V_9 ;
F_4 (sk2, &hslot->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
V_9 -> V_20 == V_7 -> V_20 &&
F_17 ( V_9 ) == F_17 ( V_7 ) &&
( F_7 ( V_9 ) -> V_12 == F_7 ( V_7 ) -> V_12 ) &&
( V_9 -> V_14 == V_7 -> V_14 ) &&
V_9 -> V_15 && F_9 ( V_11 , F_3 ( V_9 ) ) &&
(* F_16)( V_7 , V_9 , false ) ) {
return F_18 ( V_7 , V_9 ) ;
}
}
if ( ! F_8 ( V_7 -> V_16 ) )
return F_19 ( V_7 ) ;
return 0 ;
}
int F_20 ( struct V_6 * V_7 , unsigned short V_21 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) ,
unsigned int V_22 )
{
struct V_3 * V_4 , * V_17 ;
struct V_23 * V_24 = V_7 -> V_25 -> V_26 . V_23 ;
int error = 1 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( ! V_21 ) {
int V_27 , V_28 , V_29 ;
unsigned int rand ;
unsigned short V_30 , V_31 ;
F_21 ( V_5 , V_32 ) ;
F_22 ( V_1 , & V_27 , & V_28 ) ;
V_29 = ( V_28 - V_27 ) + 1 ;
rand = F_23 () ;
V_30 = F_24 ( rand , V_29 ) + V_27 ;
rand = ( rand | 1 ) * ( V_24 -> V_33 + 1 ) ;
V_31 = V_30 + V_24 -> V_33 + 1 ;
do {
V_4 = F_25 ( V_24 , V_1 , V_30 ) ;
F_26 ( V_5 , V_32 ) ;
F_27 ( & V_4 -> V_19 ) ;
F_1 ( V_1 , V_21 , V_4 , V_5 , V_7 ,
F_2 , V_24 -> log ) ;
V_21 = V_30 ;
do {
if ( V_27 <= V_21 && V_21 <= V_28 &&
! F_28 ( V_21 >> V_24 -> log , V_5 ) &&
! F_29 ( V_1 , V_21 ) )
goto V_34;
V_21 += rand ;
} while ( V_21 != V_30 );
F_30 ( & V_4 -> V_19 ) ;
} while ( ++ V_30 != V_31 );
goto V_35;
} else {
V_4 = F_25 ( V_24 , V_1 , V_21 ) ;
F_27 ( & V_4 -> V_19 ) ;
if ( V_4 -> V_36 > 10 ) {
int V_37 ;
unsigned int V_38 = F_7 ( V_7 ) -> V_39 ^ V_21 ;
V_38 &= V_24 -> V_33 ;
V_22 &= V_24 -> V_33 ;
V_17 = F_31 ( V_24 , V_38 ) ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_40;
V_37 = F_11 ( V_1 , V_21 , V_17 ,
V_7 , F_2 ) ;
if ( ! V_37 && ( V_22 != V_38 ) ) {
V_17 = F_31 ( V_24 , V_22 ) ;
V_37 = F_11 ( V_1 , V_21 , V_17 ,
V_7 , F_2 ) ;
}
if ( V_37 )
goto V_41;
else
goto V_34;
}
V_40:
if ( F_1 ( V_1 , V_21 , V_4 , NULL , V_7 ,
F_2 , 0 ) )
goto V_41;
}
V_34:
F_32 ( V_7 ) -> V_42 = V_21 ;
F_7 ( V_7 ) -> V_12 = V_21 ;
F_7 ( V_7 ) -> V_39 ^= V_21 ;
if ( F_33 ( V_7 ) ) {
if ( V_7 -> V_15 &&
F_15 ( V_7 , V_4 , F_2 ) ) {
F_32 ( V_7 ) -> V_42 = 0 ;
F_7 ( V_7 ) -> V_12 = 0 ;
F_7 ( V_7 ) -> V_39 ^= V_21 ;
goto V_41;
}
F_34 ( V_7 , & V_4 -> V_43 ) ;
V_4 -> V_36 ++ ;
F_35 ( F_6 ( V_7 ) , V_7 -> V_25 , 1 ) ;
V_17 = F_31 ( V_24 , F_7 ( V_7 ) -> V_39 ) ;
F_12 ( & V_17 -> V_19 ) ;
if ( F_36 ( V_44 ) && V_7 -> V_15 &&
V_7 -> V_20 == V_45 )
F_37 ( & F_7 ( V_7 ) -> V_46 ,
& V_17 -> V_43 ) ;
else
F_38 ( & F_7 ( V_7 ) -> V_46 ,
& V_17 -> V_43 ) ;
V_17 -> V_36 ++ ;
F_14 ( & V_17 -> V_19 ) ;
}
F_39 ( V_7 , V_47 ) ;
error = 0 ;
V_41:
F_30 ( & V_4 -> V_19 ) ;
V_35:
return error ;
}
int F_40 ( const struct V_6 * V_8 , const struct V_6 * V_9 ,
bool V_10 )
{
struct V_48 * V_49 = F_32 ( V_8 ) , * V_50 = F_32 ( V_9 ) ;
if ( ! F_17 ( V_9 ) ) {
if ( V_49 -> V_51 == V_50 -> V_51 )
return 1 ;
if ( ! V_49 -> V_51 || ! V_50 -> V_51 )
return V_10 ;
}
return 0 ;
}
static T_3 F_41 ( const struct V_1 * V_1 , T_4 V_52 ,
unsigned int V_53 )
{
return F_42 ( ( V_54 T_3 ) V_52 , F_43 ( V_1 ) ) ^ V_53 ;
}
int F_44 ( struct V_6 * V_7 , unsigned short V_21 )
{
unsigned int V_22 =
F_41 ( F_6 ( V_7 ) , F_45 ( V_55 ) , V_21 ) ;
unsigned int V_56 =
F_41 ( F_6 ( V_7 ) , F_32 ( V_7 ) -> V_51 , 0 ) ;
F_7 ( V_7 ) -> V_39 = V_56 ;
return F_20 ( V_7 , V_21 , F_40 , V_22 ) ;
}
static int F_46 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_52 , T_5 V_57 ,
T_4 V_58 , unsigned short V_59 , int V_60 )
{
int V_61 ;
struct V_48 * V_62 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_12 != V_59 ||
F_17 ( V_7 ) )
return - 1 ;
V_61 = ( V_7 -> V_20 == V_63 ) ? 2 : 1 ;
V_62 = F_32 ( V_7 ) ;
if ( V_62 -> V_51 ) {
if ( V_62 -> V_51 != V_58 )
return - 1 ;
V_61 += 4 ;
}
if ( V_62 -> V_64 ) {
if ( V_62 -> V_64 != V_52 )
return - 1 ;
V_61 += 4 ;
}
if ( V_62 -> V_65 ) {
if ( V_62 -> V_65 != V_57 )
return - 1 ;
V_61 += 4 ;
}
if ( V_7 -> V_14 ) {
if ( V_7 -> V_14 != V_60 )
return - 1 ;
V_61 += 4 ;
}
if ( V_7 -> V_66 == F_47 () )
V_61 ++ ;
return V_61 ;
}
static T_3 F_48 ( const struct V_1 * V_1 , const T_4 V_67 ,
const T_1 V_68 , const T_4 V_69 ,
const T_5 V_70 )
{
static T_3 T_6 V_71 ;
F_49 ( & T_6 , sizeof( T_6 ) ) ;
return F_50 ( V_67 , V_68 , V_69 , V_70 ,
T_6 + F_43 ( V_1 ) ) ;
}
static struct V_6 * F_51 ( struct V_1 * V_1 ,
T_4 V_52 , T_5 V_57 ,
T_4 V_58 , unsigned int V_59 , int V_60 ,
struct V_3 * V_17 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 , * V_74 ;
int V_61 , V_75 , V_76 = 0 , V_77 = 0 ;
T_3 V_78 = 0 ;
V_74 = NULL ;
V_75 = 0 ;
F_52 (sk, &hslot2->head) {
V_61 = F_46 ( V_7 , V_1 , V_52 , V_57 ,
V_58 , V_59 , V_60 ) ;
if ( V_61 > V_75 ) {
V_77 = V_7 -> V_15 ;
if ( V_77 ) {
V_78 = F_48 ( V_1 , V_58 , V_59 ,
V_52 , V_57 ) ;
V_74 = F_53 ( V_7 , V_78 , V_73 ,
sizeof( struct V_79 ) ) ;
if ( V_74 )
return V_74 ;
V_76 = 1 ;
}
V_75 = V_61 ;
V_74 = V_7 ;
} else if ( V_61 == V_75 && V_77 ) {
V_76 ++ ;
if ( F_24 ( V_78 , V_76 ) == 0 )
V_74 = V_7 ;
V_78 = F_54 ( V_78 ) ;
}
}
return V_74 ;
}
struct V_6 * F_55 ( struct V_1 * V_1 , T_4 V_52 ,
T_5 V_57 , T_4 V_58 , T_5 V_80 ,
int V_60 , struct V_23 * V_24 , struct V_72 * V_73 )
{
struct V_6 * V_7 , * V_74 ;
unsigned short V_59 = F_56 ( V_80 ) ;
unsigned int V_81 , V_38 , V_82 = F_57 ( V_1 , V_59 , V_24 -> V_33 ) ;
struct V_3 * V_17 , * V_4 = & V_24 -> V_78 [ V_82 ] ;
int V_61 , V_75 , V_76 = 0 , V_77 = 0 ;
T_3 V_78 = 0 ;
if ( V_4 -> V_36 > 10 ) {
V_81 = F_41 ( V_1 , V_58 , V_59 ) ;
V_38 = V_81 & V_24 -> V_33 ;
V_17 = & V_24 -> V_81 [ V_38 ] ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_83;
V_74 = F_51 ( V_1 , V_52 , V_57 ,
V_58 , V_59 , V_60 ,
V_17 , V_73 ) ;
if ( ! V_74 ) {
unsigned int V_84 = V_38 ;
V_81 = F_41 ( V_1 , F_45 ( V_55 ) , V_59 ) ;
V_38 = V_81 & V_24 -> V_33 ;
if ( F_58 ( V_38 == V_84 ) )
return V_74 ;
V_17 = & V_24 -> V_81 [ V_38 ] ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_83;
V_74 = F_51 ( V_1 , V_52 , V_57 ,
V_58 , V_59 , V_60 ,
V_17 , V_73 ) ;
}
return V_74 ;
}
V_83:
V_74 = NULL ;
V_75 = 0 ;
F_59 (sk, &hslot->head) {
V_61 = F_46 ( V_7 , V_1 , V_52 , V_57 ,
V_58 , V_59 , V_60 ) ;
if ( V_61 > V_75 ) {
V_77 = V_7 -> V_15 ;
if ( V_77 ) {
V_78 = F_48 ( V_1 , V_58 , V_59 ,
V_52 , V_57 ) ;
V_74 = F_53 ( V_7 , V_78 , V_73 ,
sizeof( struct V_79 ) ) ;
if ( V_74 )
return V_74 ;
V_76 = 1 ;
}
V_74 = V_7 ;
V_75 = V_61 ;
} else if ( V_61 == V_75 && V_77 ) {
V_76 ++ ;
if ( F_24 ( V_78 , V_76 ) == 0 )
V_74 = V_7 ;
V_78 = F_54 ( V_78 ) ;
}
}
return V_74 ;
}
static inline struct V_6 * F_60 ( struct V_72 * V_73 ,
T_5 V_57 , T_5 V_80 ,
struct V_23 * V_24 )
{
const struct V_85 * V_86 = F_61 ( V_73 ) ;
return F_55 ( F_62 ( V_73 -> V_87 ) , V_86 -> V_52 , V_57 ,
V_86 -> V_58 , V_80 , F_63 ( V_73 ) ,
V_24 , V_73 ) ;
}
struct V_6 * F_64 ( struct V_72 * V_73 ,
T_5 V_57 , T_5 V_80 )
{
return F_60 ( V_73 , V_57 , V_80 , & V_23 ) ;
}
struct V_6 * F_65 ( struct V_1 * V_1 , T_4 V_52 , T_5 V_57 ,
T_4 V_58 , T_5 V_80 , int V_60 )
{
struct V_6 * V_7 ;
V_7 = F_55 ( V_1 , V_52 , V_57 , V_58 , V_80 ,
V_60 , & V_23 , NULL ) ;
if ( V_7 && ! F_66 ( & V_7 -> V_88 ) )
V_7 = NULL ;
return V_7 ;
}
static inline bool F_67 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_5 V_89 , T_4 V_90 ,
T_5 V_91 , T_4 V_92 ,
int V_60 , unsigned short V_59 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_12 != V_59 ||
( V_62 -> V_64 && V_62 -> V_64 != V_92 ) ||
( V_62 -> V_65 != V_91 && V_62 -> V_65 ) ||
( V_62 -> V_51 && V_62 -> V_51 != V_90 ) ||
F_17 ( V_7 ) ||
( V_7 -> V_14 && V_7 -> V_14 != V_60 ) )
return false ;
if ( ! F_68 ( V_7 , V_90 , V_92 , V_60 ) )
return false ;
return true ;
}
void F_69 ( struct V_72 * V_73 , T_3 V_93 , struct V_23 * V_24 )
{
struct V_48 * V_62 ;
const struct V_85 * V_86 = ( const struct V_85 * ) V_73 -> V_94 ;
struct V_79 * V_95 = (struct V_79 * ) ( V_73 -> V_94 + ( V_86 -> V_96 << 2 ) ) ;
const int type = F_70 ( V_73 ) -> type ;
const int V_97 = F_70 ( V_73 ) -> V_97 ;
struct V_6 * V_7 ;
int V_98 ;
int V_99 ;
struct V_1 * V_1 = F_62 ( V_73 -> V_87 ) ;
V_7 = F_55 ( V_1 , V_86 -> V_58 , V_95 -> V_100 ,
V_86 -> V_52 , V_95 -> V_101 , V_73 -> V_87 -> V_102 , V_24 ,
NULL ) ;
if ( ! V_7 ) {
F_71 ( V_1 , V_103 ) ;
return;
}
V_99 = 0 ;
V_98 = 0 ;
V_62 = F_32 ( V_7 ) ;
switch ( type ) {
default:
case V_104 :
V_99 = V_105 ;
break;
case V_106 :
goto V_107;
case V_108 :
V_99 = V_109 ;
V_98 = 1 ;
break;
case V_110 :
if ( V_97 == V_111 ) {
F_72 ( V_73 , V_7 , V_93 ) ;
if ( V_62 -> V_112 != V_113 ) {
V_99 = V_114 ;
V_98 = 1 ;
break;
}
goto V_107;
}
V_99 = V_105 ;
if ( V_97 <= V_115 ) {
V_98 = V_116 [ V_97 ] . V_117 ;
V_99 = V_116 [ V_97 ] . V_118 ;
}
break;
case V_119 :
F_73 ( V_73 , V_7 ) ;
goto V_107;
}
if ( ! V_62 -> V_120 ) {
if ( ! V_98 || V_7 -> V_121 != V_122 )
goto V_107;
} else
F_74 ( V_7 , V_73 , V_99 , V_95 -> V_100 , V_93 , ( V_123 * ) ( V_95 + 1 ) ) ;
V_7 -> V_124 = V_99 ;
V_7 -> V_125 ( V_7 ) ;
V_107:
return;
}
void F_75 ( struct V_72 * V_73 , T_3 V_93 )
{
F_69 ( V_73 , V_93 , & V_23 ) ;
}
void F_76 ( struct V_6 * V_7 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
if ( V_127 -> V_128 ) {
V_127 -> V_129 = 0 ;
V_127 -> V_128 = 0 ;
F_77 ( V_7 ) ;
}
}
void F_78 ( struct V_72 * V_73 , T_4 V_130 , T_4 V_131 )
{
struct V_79 * V_95 = F_79 ( V_73 ) ;
int V_132 = F_80 ( V_73 ) ;
int V_129 = V_73 -> V_129 - V_132 ;
int V_133 = V_129 ;
T_7 V_134 = 0 ;
if ( ! F_81 ( V_73 ) ) {
V_73 -> V_135 = F_82 ( V_73 ) - V_73 -> V_43 ;
V_73 -> V_136 = F_83 ( struct V_79 , V_137 ) ;
V_95 -> V_137 = ~ F_84 ( V_130 , V_131 , V_129 ,
V_138 , 0 ) ;
} else {
struct V_72 * V_139 ;
F_85 (skb, frags) {
V_134 = F_86 ( V_134 , V_139 -> V_134 ) ;
V_133 -= V_139 -> V_129 ;
}
V_134 = F_87 ( V_73 , V_132 , V_133 , V_134 ) ;
V_73 -> V_140 = V_141 ;
V_95 -> V_137 = F_84 ( V_130 , V_131 , V_129 , V_138 , V_134 ) ;
if ( V_95 -> V_137 == 0 )
V_95 -> V_137 = V_142 ;
}
}
void F_88 ( bool V_143 , struct V_72 * V_73 ,
T_4 V_52 , T_4 V_58 , int V_129 )
{
struct V_79 * V_95 = F_79 ( V_73 ) ;
if ( V_143 ) {
V_95 -> V_137 = 0 ;
} else if ( F_89 ( V_73 ) ) {
V_95 -> V_137 = ~ F_90 ( V_129 , V_52 , V_58 , 0 ) ;
} else if ( V_73 -> V_140 == V_144 ) {
V_95 -> V_137 = 0 ;
V_95 -> V_137 = F_90 ( V_129 , V_52 , V_58 , F_91 ( V_73 ) ) ;
if ( V_95 -> V_137 == 0 )
V_95 -> V_137 = V_142 ;
} else {
V_73 -> V_140 = V_144 ;
V_73 -> V_135 = F_82 ( V_73 ) - V_73 -> V_43 ;
V_73 -> V_136 = F_83 ( struct V_79 , V_137 ) ;
V_95 -> V_137 = ~ F_90 ( V_129 , V_52 , V_58 , 0 ) ;
}
}
static int F_92 ( struct V_72 * V_73 , struct V_145 * V_146 )
{
struct V_6 * V_7 = V_73 -> V_7 ;
struct V_48 * V_62 = F_32 ( V_7 ) ;
struct V_79 * V_95 ;
int V_99 = 0 ;
int V_147 = F_93 ( V_7 ) ;
int V_132 = F_80 ( V_73 ) ;
int V_129 = V_73 -> V_129 - V_132 ;
T_7 V_134 = 0 ;
V_95 = F_79 ( V_73 ) ;
V_95 -> V_101 = V_62 -> V_148 ;
V_95 -> V_100 = V_146 -> V_149 ;
V_95 -> V_129 = F_94 ( V_129 ) ;
V_95 -> V_137 = 0 ;
if ( V_147 )
V_134 = F_95 ( V_73 ) ;
else if ( V_7 -> V_150 ) {
V_73 -> V_140 = V_141 ;
goto V_151;
} else if ( V_73 -> V_140 == V_144 ) {
F_78 ( V_73 , V_146 -> V_52 , V_146 -> V_58 ) ;
goto V_151;
} else
V_134 = F_96 ( V_73 ) ;
V_95 -> V_137 = F_84 ( V_146 -> V_52 , V_146 -> V_58 , V_129 ,
V_7 -> V_152 , V_134 ) ;
if ( V_95 -> V_137 == 0 )
V_95 -> V_137 = V_142 ;
V_151:
V_99 = F_97 ( F_6 ( V_7 ) , V_73 ) ;
if ( V_99 ) {
if ( V_99 == - V_153 && ! V_62 -> V_120 ) {
F_98 ( F_6 ( V_7 ) ,
V_154 , V_147 ) ;
V_99 = 0 ;
}
} else
F_98 ( F_6 ( V_7 ) ,
V_155 , V_147 ) ;
return V_99 ;
}
int F_99 ( struct V_6 * V_7 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
struct V_48 * V_62 = F_32 ( V_7 ) ;
struct V_145 * V_146 = & V_62 -> V_156 . V_157 . V_158 . V_159 ;
struct V_72 * V_73 ;
int V_99 = 0 ;
V_73 = F_100 ( V_7 , V_146 ) ;
if ( ! V_73 )
goto V_107;
V_99 = F_92 ( V_73 , V_146 ) ;
V_107:
V_127 -> V_129 = 0 ;
V_127 -> V_128 = 0 ;
return V_99 ;
}
int F_101 ( struct V_6 * V_7 , struct V_160 * V_161 , T_8 V_129 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
struct V_126 * V_127 = F_7 ( V_7 ) ;
struct V_145 V_162 ;
struct V_145 * V_146 ;
int V_163 = V_129 ;
struct V_164 V_165 ;
struct V_166 * V_167 = NULL ;
int free = 0 ;
int V_168 = 0 ;
T_4 V_58 , V_69 , V_52 ;
T_5 V_80 ;
V_123 V_169 ;
int V_99 , V_147 = F_93 ( V_7 ) ;
int V_170 = V_127 -> V_171 || V_161 -> V_172 & V_173 ;
int (* F_102)( void * , char * , int , int , int , struct V_72 * );
struct V_72 * V_73 ;
struct V_174 V_175 ;
if ( V_129 > 0xFFFF )
return - V_114 ;
if ( V_161 -> V_172 & V_176 )
return - V_177 ;
V_165 . V_178 = NULL ;
V_165 . V_179 = 0 ;
V_165 . V_180 = 0 ;
V_165 . V_169 = - 1 ;
F_102 = V_147 ? V_181 : V_182 ;
V_146 = & V_62 -> V_156 . V_157 . V_158 . V_159 ;
if ( V_127 -> V_128 ) {
F_103 ( V_7 ) ;
if ( F_104 ( V_127 -> V_128 ) ) {
if ( F_58 ( V_127 -> V_128 != V_183 ) ) {
F_105 ( V_7 ) ;
return - V_184 ;
}
goto V_185;
}
F_105 ( V_7 ) ;
}
V_163 += sizeof( struct V_79 ) ;
if ( V_161 -> V_186 ) {
F_106 ( struct V_187 * , V_188 , V_161 -> V_186 ) ;
if ( V_161 -> V_189 < sizeof( * V_188 ) )
return - V_184 ;
if ( V_188 -> V_190 != V_183 ) {
if ( V_188 -> V_190 != V_191 )
return - V_192 ;
}
V_58 = V_188 -> V_193 . V_194 ;
V_80 = V_188 -> V_195 ;
if ( V_80 == 0 )
return - V_184 ;
} else {
if ( V_7 -> V_121 != V_122 )
return - V_196 ;
V_58 = V_62 -> V_64 ;
V_80 = V_62 -> V_65 ;
V_168 = 1 ;
}
V_165 . V_197 . V_198 = V_7 -> V_199 ;
V_165 . V_200 = V_62 -> V_201 ;
V_165 . V_202 = V_7 -> V_14 ;
if ( V_161 -> V_203 ) {
V_99 = F_107 ( V_7 , V_161 , & V_165 , V_7 -> V_20 == V_45 ) ;
if ( F_58 ( V_99 ) ) {
F_108 ( V_165 . V_178 ) ;
return V_99 ;
}
if ( V_165 . V_178 )
free = 1 ;
V_168 = 0 ;
}
if ( ! V_165 . V_178 ) {
struct V_204 * V_205 ;
F_109 () ;
V_205 = F_110 ( V_62 -> V_205 ) ;
if ( V_205 ) {
memcpy ( & V_175 , V_205 ,
sizeof( * V_205 ) + V_205 -> V_178 . V_206 ) ;
V_165 . V_178 = & V_175 . V_178 ;
}
F_111 () ;
}
V_52 = V_165 . V_200 ;
V_165 . V_200 = V_69 = V_58 ;
F_112 ( V_7 , V_165 . V_197 . V_198 , & V_165 . V_179 ) ;
if ( V_165 . V_178 && V_165 . V_178 -> V_178 . V_207 ) {
if ( ! V_58 )
return - V_184 ;
V_69 = V_165 . V_178 -> V_178 . V_69 ;
V_168 = 0 ;
}
V_169 = F_113 ( & V_165 , V_62 ) ;
if ( F_114 ( V_7 , V_208 ) ||
( V_161 -> V_172 & V_209 ) ||
( V_165 . V_178 && V_165 . V_178 -> V_178 . V_210 ) ) {
V_169 |= V_211 ;
V_168 = 0 ;
}
if ( F_115 ( V_58 ) ) {
if ( ! V_165 . V_202 )
V_165 . V_202 = V_62 -> V_212 ;
if ( ! V_52 )
V_52 = V_62 -> V_213 ;
V_168 = 0 ;
} else if ( ! V_165 . V_202 )
V_165 . V_202 = V_62 -> V_214 ;
if ( V_168 )
V_167 = (struct V_166 * ) F_116 ( V_7 , 0 ) ;
if ( ! V_167 ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
T_9 V_215 = F_117 ( V_7 ) ;
V_146 = & V_162 ;
F_118 ( V_146 , V_165 . V_202 , V_7 -> V_216 , V_169 ,
V_217 , V_7 -> V_152 ,
V_215 ,
V_69 , V_52 , V_80 , V_62 -> V_148 ,
V_7 -> V_218 ) ;
F_119 ( V_7 , F_120 ( V_146 ) ) ;
V_167 = F_121 ( V_1 , V_146 , V_7 ) ;
if ( F_122 ( V_167 ) ) {
V_99 = F_123 ( V_167 ) ;
V_167 = NULL ;
if ( V_99 == - V_219 )
F_124 ( V_1 , V_220 ) ;
goto V_107;
}
V_99 = - V_221 ;
if ( ( V_167 -> V_222 & V_223 ) &&
! F_114 ( V_7 , V_224 ) )
goto V_107;
if ( V_168 )
F_125 ( V_7 , F_126 ( & V_167 -> V_131 ) ) ;
}
if ( V_161 -> V_172 & V_225 )
goto V_226;
V_227:
V_52 = V_146 -> V_52 ;
if ( ! V_165 . V_200 )
V_58 = V_165 . V_200 = V_146 -> V_58 ;
if ( ! V_170 ) {
V_73 = F_127 ( V_7 , V_146 , F_102 , V_161 , V_163 ,
sizeof( struct V_79 ) , & V_165 , & V_167 ,
V_161 -> V_172 ) ;
V_99 = F_123 ( V_73 ) ;
if ( ! F_128 ( V_73 ) )
V_99 = F_92 ( V_73 , V_146 ) ;
goto V_107;
}
F_103 ( V_7 ) ;
if ( F_58 ( V_127 -> V_128 ) ) {
F_105 ( V_7 ) ;
F_129 ( L_1 ) ;
V_99 = - V_184 ;
goto V_107;
}
V_146 = & V_62 -> V_156 . V_157 . V_158 . V_159 ;
V_146 -> V_58 = V_58 ;
V_146 -> V_52 = V_52 ;
V_146 -> V_149 = V_80 ;
V_146 -> V_228 = V_62 -> V_148 ;
V_127 -> V_128 = V_183 ;
V_185:
V_127 -> V_129 += V_163 ;
V_99 = F_130 ( V_7 , V_146 , F_102 , V_161 , V_163 ,
sizeof( struct V_79 ) , & V_165 , & V_167 ,
V_170 ? V_161 -> V_172 | V_173 : V_161 -> V_172 ) ;
if ( V_99 )
F_76 ( V_7 ) ;
else if ( ! V_170 )
V_99 = F_99 ( V_7 ) ;
else if ( F_58 ( F_131 ( & V_7 -> V_229 ) ) )
V_127 -> V_128 = 0 ;
F_105 ( V_7 ) ;
V_107:
F_132 ( V_167 ) ;
if ( free )
F_108 ( V_165 . V_178 ) ;
if ( ! V_99 )
return V_129 ;
if ( V_99 == - V_153 || F_28 ( V_230 , & V_7 -> V_231 -> V_232 ) ) {
F_98 ( F_6 ( V_7 ) ,
V_154 , V_147 ) ;
}
return V_99 ;
V_226:
F_133 ( & V_167 -> V_131 ) ;
if ( ! ( V_161 -> V_172 & V_233 ) || V_129 )
goto V_227;
V_99 = 0 ;
goto V_107;
}
int F_134 ( struct V_6 * V_7 , struct V_234 * V_234 , int V_132 ,
T_8 V_235 , int V_232 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_236 ;
if ( V_232 & V_237 )
V_232 |= V_173 ;
if ( ! V_127 -> V_128 ) {
struct V_160 V_161 = { . V_172 = V_232 | V_173 } ;
V_236 = F_101 ( V_7 , & V_161 , 0 ) ;
if ( V_236 < 0 )
return V_236 ;
}
F_103 ( V_7 ) ;
if ( F_58 ( ! V_127 -> V_128 ) ) {
F_105 ( V_7 ) ;
F_129 ( L_2 ) ;
return - V_184 ;
}
V_236 = F_135 ( V_7 , & V_62 -> V_156 . V_157 . V_158 . V_159 ,
V_234 , V_132 , V_235 , V_232 ) ;
if ( V_236 == - V_177 ) {
F_105 ( V_7 ) ;
return F_136 ( V_7 -> V_231 , V_234 , V_132 ,
V_235 , V_232 ) ;
}
if ( V_236 < 0 ) {
F_76 ( V_7 ) ;
goto V_107;
}
V_127 -> V_129 += V_235 ;
if ( ! ( V_127 -> V_171 || ( V_232 & V_173 ) ) )
V_236 = F_99 ( V_7 ) ;
if ( ! V_236 )
V_236 = V_235 ;
V_107:
F_105 ( V_7 ) ;
return V_236 ;
}
static void F_137 ( struct V_6 * V_7 , int V_235 , int V_238 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_239 ;
if ( F_104 ( V_238 ) ) {
V_127 -> V_240 += V_235 ;
V_235 = V_127 -> V_240 ;
if ( V_235 < ( V_7 -> V_241 >> 2 ) &&
! F_131 ( & V_7 -> V_242 ) )
return;
} else {
V_235 += V_127 -> V_240 ;
}
V_127 -> V_240 = 0 ;
V_7 -> V_243 += V_235 ;
V_239 = ( V_7 -> V_243 - V_238 ) & ~ ( V_244 - 1 ) ;
V_7 -> V_243 -= V_239 ;
if ( V_239 )
F_138 ( V_7 , V_239 >> V_245 ) ;
F_139 ( V_235 , & V_7 -> V_246 ) ;
}
void F_140 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
F_137 ( V_7 , V_73 -> V_247 , 1 ) ;
}
static T_10 * F_141 ( void * V_248 )
{
T_10 * V_249 ;
V_249 = V_250 + F_142 ( V_248 , V_251 ) ;
F_12 ( V_249 ) ;
return V_249 ;
}
static void F_143 ( T_10 * V_249 )
{
if ( V_249 )
F_14 ( V_249 ) ;
}
int F_144 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
struct V_252 * V_253 = & V_7 -> V_242 ;
int V_254 , V_255 , V_239 , V_99 = - V_256 ;
T_10 * V_249 = NULL ;
int V_235 ;
V_254 = F_145 ( & V_7 -> V_246 ) ;
if ( V_254 > V_7 -> V_241 )
goto V_257;
if ( V_254 > ( V_7 -> V_241 >> 1 ) ) {
F_146 ( V_73 ) ;
V_249 = F_141 ( V_7 ) ;
}
V_235 = V_73 -> V_258 ;
V_73 -> V_247 = V_235 ;
V_254 = F_147 ( V_235 , & V_7 -> V_246 ) ;
if ( V_254 > ( V_235 + V_7 -> V_241 ) )
goto V_259;
F_12 ( & V_253 -> V_19 ) ;
if ( V_235 >= V_7 -> V_243 ) {
V_239 = F_148 ( V_235 ) ;
V_255 = V_239 << V_245 ;
if ( ! F_149 ( V_7 , V_255 , V_239 , V_260 ) ) {
V_99 = - V_153 ;
F_14 ( & V_253 -> V_19 ) ;
goto V_259;
}
V_7 -> V_243 += V_255 ;
}
V_7 -> V_243 -= V_235 ;
F_150 ( V_7 , V_73 ) ;
F_151 ( V_253 , V_73 ) ;
F_14 ( & V_253 -> V_19 ) ;
if ( ! F_114 ( V_7 , V_261 ) )
V_7 -> V_262 ( V_7 ) ;
F_143 ( V_249 ) ;
return 0 ;
V_259:
F_139 ( V_73 -> V_258 , & V_7 -> V_246 ) ;
V_257:
F_152 ( & V_7 -> V_263 ) ;
F_143 ( V_249 ) ;
return V_99 ;
}
void F_153 ( struct V_6 * V_7 )
{
unsigned int V_264 = 0 ;
struct V_72 * V_73 ;
while ( ( V_73 = F_154 ( & V_7 -> V_242 ) ) != NULL ) {
V_264 += V_73 -> V_258 ;
F_155 ( V_73 ) ;
}
F_137 ( V_7 , V_264 , 0 ) ;
F_156 ( V_7 ) ;
}
int F_157 ( struct V_6 * V_7 )
{
V_7 -> V_265 = F_153 ;
return 0 ;
}
void F_158 ( struct V_6 * V_7 , struct V_72 * V_73 , int V_129 )
{
if ( F_58 ( F_159 ( V_7 -> V_266 ) >= 0 ) ) {
bool V_267 = F_160 ( V_7 ) ;
F_161 ( V_7 , V_129 ) ;
F_162 ( V_7 , V_267 ) ;
}
F_163 ( V_73 ) ;
}
static int F_164 ( struct V_6 * V_7 )
{
struct V_252 * V_268 = & V_7 -> V_242 ;
struct V_72 * V_73 ;
int V_264 = 0 ;
int V_18 ;
F_27 ( & V_268 -> V_19 ) ;
while ( ( V_73 = F_165 ( V_268 ) ) != NULL &&
F_166 ( V_73 ) ) {
F_167 ( F_6 ( V_7 ) , V_269 ,
F_93 ( V_7 ) ) ;
F_167 ( F_6 ( V_7 ) , V_270 ,
F_93 ( V_7 ) ) ;
F_152 ( & V_7 -> V_263 ) ;
F_168 ( V_73 , V_268 ) ;
V_264 += V_73 -> V_258 ;
F_155 ( V_73 ) ;
}
V_18 = V_73 ? V_73 -> V_129 : - 1 ;
if ( V_264 )
F_137 ( V_7 , V_264 , 1 ) ;
F_30 ( & V_268 -> V_19 ) ;
return V_18 ;
}
int F_169 ( struct V_6 * V_7 , int V_271 , unsigned long V_272 )
{
switch ( V_271 ) {
case V_273 :
{
int V_274 = F_170 ( V_7 ) ;
return F_171 ( V_274 , ( int V_275 * ) V_272 ) ;
}
case V_276 :
{
int V_274 = F_172 ( int , 0 , F_164 ( V_7 ) ) ;
return F_171 ( V_274 , ( int V_275 * ) V_272 ) ;
}
default:
return - V_277 ;
}
return 0 ;
}
int F_173 ( struct V_6 * V_7 , struct V_160 * V_161 , T_8 V_129 , int V_278 ,
int V_232 , int * V_279 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
F_106 ( struct V_187 * , sin , V_161 -> V_186 ) ;
struct V_72 * V_73 ;
unsigned int V_163 , V_280 ;
int V_281 , V_282 , V_283 ;
int V_99 ;
int V_147 = F_93 ( V_7 ) ;
bool V_284 = false ;
if ( V_232 & V_285 )
return F_174 ( V_7 , V_161 , V_129 , V_279 ) ;
V_286:
V_282 = V_283 = F_175 ( V_7 , V_232 ) ;
V_73 = F_176 ( V_7 , V_232 , V_278 , & V_281 , & V_283 , & V_99 ) ;
if ( ! V_73 )
return V_99 ;
V_163 = V_73 -> V_129 ;
V_280 = V_129 ;
if ( V_280 > V_163 - V_283 )
V_280 = V_163 - V_283 ;
else if ( V_280 < V_163 )
V_161 -> V_172 |= V_287 ;
if ( V_280 < V_163 || V_282 ||
( V_147 && F_177 ( V_73 ) -> V_288 ) ) {
V_284 = ! F_166 ( V_73 ) ;
if ( ! V_284 )
goto V_289;
}
if ( V_284 || F_178 ( V_73 ) )
V_99 = F_179 ( V_73 , V_283 , V_161 , V_280 ) ;
else {
V_99 = F_180 ( V_73 , V_283 , V_161 ) ;
if ( V_99 == - V_184 )
goto V_289;
}
if ( F_58 ( V_99 ) ) {
if ( ! V_281 ) {
F_152 ( & V_7 -> V_263 ) ;
F_98 ( F_6 ( V_7 ) ,
V_270 , V_147 ) ;
}
F_155 ( V_73 ) ;
return V_99 ;
}
if ( ! V_281 )
F_98 ( F_6 ( V_7 ) ,
V_290 , V_147 ) ;
F_181 ( V_161 , V_7 , V_73 ) ;
if ( sin ) {
sin -> V_190 = V_183 ;
sin -> V_195 = F_79 ( V_73 ) -> V_101 ;
sin -> V_193 . V_194 = F_61 ( V_73 ) -> V_52 ;
memset ( sin -> V_291 , 0 , sizeof( sin -> V_291 ) ) ;
* V_279 = sizeof( * sin ) ;
}
if ( V_62 -> V_292 )
F_182 ( V_161 , V_7 , V_73 , sizeof( struct V_79 ) , V_283 ) ;
V_99 = V_280 ;
if ( V_232 & V_287 )
V_99 = V_163 ;
F_158 ( V_7 , V_73 , V_282 ? - V_99 : V_99 ) ;
return V_99 ;
V_289:
if ( ! F_183 ( V_7 , V_73 , V_232 , F_140 ) ) {
F_98 ( F_6 ( V_7 ) , V_269 , V_147 ) ;
F_98 ( F_6 ( V_7 ) , V_270 , V_147 ) ;
}
F_155 ( V_73 ) ;
F_184 () ;
V_161 -> V_172 &= ~ V_287 ;
goto V_286;
}
int F_185 ( struct V_6 * V_7 , int V_232 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
V_7 -> V_121 = V_293 ;
V_62 -> V_64 = 0 ;
V_62 -> V_65 = 0 ;
F_186 ( V_7 ) ;
V_7 -> V_14 = 0 ;
if ( ! ( V_7 -> V_294 & V_295 ) )
F_187 ( V_7 ) ;
if ( ! ( V_7 -> V_294 & V_296 ) ) {
V_7 -> V_25 -> V_297 ( V_7 ) ;
V_62 -> V_148 = 0 ;
}
F_188 ( V_7 ) ;
return 0 ;
}
int F_189 ( struct V_6 * V_7 , int V_232 )
{
F_103 ( V_7 ) ;
F_185 ( V_7 , V_232 ) ;
F_105 ( V_7 ) ;
return 0 ;
}
void F_190 ( struct V_6 * V_7 )
{
if ( F_191 ( V_7 ) ) {
struct V_23 * V_24 = V_7 -> V_25 -> V_26 . V_23 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_25 ( V_24 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_12 ) ;
V_17 = F_31 ( V_24 , F_7 ( V_7 ) -> V_39 ) ;
F_27 ( & V_4 -> V_19 ) ;
if ( F_8 ( V_7 -> V_16 ) )
F_192 ( V_7 ) ;
if ( F_193 ( V_7 ) ) {
V_4 -> V_36 -- ;
F_32 ( V_7 ) -> V_42 = 0 ;
F_35 ( F_6 ( V_7 ) , V_7 -> V_25 , - 1 ) ;
F_12 ( & V_17 -> V_19 ) ;
F_194 ( & F_7 ( V_7 ) -> V_46 ) ;
V_17 -> V_36 -- ;
F_14 ( & V_17 -> V_19 ) ;
}
F_30 ( & V_4 -> V_19 ) ;
}
}
void F_195 ( struct V_6 * V_7 , T_11 V_298 )
{
if ( F_191 ( V_7 ) ) {
struct V_23 * V_24 = V_7 -> V_25 -> V_26 . V_23 ;
struct V_3 * V_4 , * V_17 , * V_299 ;
V_17 = F_31 ( V_24 , F_7 ( V_7 ) -> V_39 ) ;
V_299 = F_31 ( V_24 , V_298 ) ;
F_7 ( V_7 ) -> V_39 = V_298 ;
if ( V_17 != V_299 ||
F_8 ( V_7 -> V_16 ) ) {
V_4 = F_25 ( V_24 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_12 ) ;
F_27 ( & V_4 -> V_19 ) ;
if ( F_8 ( V_7 -> V_16 ) )
F_192 ( V_7 ) ;
if ( V_17 != V_299 ) {
F_12 ( & V_17 -> V_19 ) ;
F_194 ( & F_7 ( V_7 ) -> V_46 ) ;
V_17 -> V_36 -- ;
F_14 ( & V_17 -> V_19 ) ;
F_12 ( & V_299 -> V_19 ) ;
F_38 ( & F_7 ( V_7 ) -> V_46 ,
& V_299 -> V_43 ) ;
V_299 -> V_36 ++ ;
F_14 ( & V_299 -> V_19 ) ;
}
F_30 ( & V_4 -> V_19 ) ;
}
}
}
static void F_196 ( struct V_6 * V_7 )
{
T_11 V_300 = F_41 ( F_6 ( V_7 ) ,
F_32 ( V_7 ) -> V_51 ,
F_32 ( V_7 ) -> V_42 ) ;
F_195 ( V_7 , V_300 ) ;
}
int F_197 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
int V_301 ;
if ( F_32 ( V_7 ) -> V_64 ) {
F_198 ( V_7 , V_73 ) ;
F_199 ( V_7 , V_73 ) ;
F_200 ( V_7 ) ;
} else {
F_201 ( V_7 , V_73 ) ;
}
V_301 = F_144 ( V_7 , V_73 ) ;
if ( V_301 < 0 ) {
int V_147 = F_93 ( V_7 ) ;
if ( V_301 == - V_256 )
F_98 ( F_6 ( V_7 ) , V_302 ,
V_147 ) ;
F_98 ( F_6 ( V_7 ) , V_270 , V_147 ) ;
F_155 ( V_73 ) ;
F_202 ( V_301 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_203 ( void )
{
if ( ! F_204 ( & V_303 ) )
F_205 ( & V_303 ) ;
}
int F_206 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_147 = F_93 ( V_7 ) ;
if ( ! F_207 ( V_7 , V_304 , V_73 ) )
goto V_257;
F_208 ( V_73 ) ;
if ( F_209 ( & V_303 ) && V_127 -> V_305 ) {
int (* F_210)( struct V_6 * V_7 , struct V_72 * V_73 );
F_210 = F_211 ( V_127 -> F_210 ) ;
if ( F_210 ) {
int V_236 ;
if ( F_166 ( V_73 ) )
goto V_306;
V_236 = F_210 ( V_7 , V_73 ) ;
if ( V_236 <= 0 ) {
F_167 ( F_6 ( V_7 ) ,
V_290 ,
V_147 ) ;
return - V_236 ;
}
}
}
if ( ( V_147 & V_307 ) && F_177 ( V_73 ) -> V_288 ) {
if ( V_127 -> V_308 == 0 ) {
F_129 ( L_3 ,
F_177 ( V_73 ) -> V_309 , V_73 -> V_129 ) ;
goto V_257;
}
if ( F_177 ( V_73 ) -> V_309 < V_127 -> V_308 ) {
F_129 ( L_4 ,
F_177 ( V_73 ) -> V_309 , V_127 -> V_308 ) ;
goto V_257;
}
}
if ( F_8 ( V_7 -> V_310 ) &&
F_166 ( V_73 ) )
goto V_306;
if ( F_212 ( V_7 , V_73 , sizeof( struct V_79 ) ) )
goto V_257;
F_213 ( V_73 ) ;
F_214 ( V_7 , V_73 ) ;
return F_197 ( V_7 , V_73 ) ;
V_306:
F_167 ( F_6 ( V_7 ) , V_269 , V_147 ) ;
V_257:
F_167 ( F_6 ( V_7 ) , V_270 , V_147 ) ;
F_152 ( & V_7 -> V_263 ) ;
F_155 ( V_73 ) ;
return - 1 ;
}
static void F_215 ( struct V_6 * V_7 , struct V_311 * V_131 )
{
struct V_311 * V_312 ;
F_216 ( V_131 ) ;
V_312 = F_217 ( & V_7 -> V_313 , V_131 ) ;
F_218 ( V_312 ) ;
}
static int F_219 ( struct V_1 * V_1 , struct V_72 * V_73 ,
struct V_79 * V_95 ,
T_4 V_52 , T_4 V_58 ,
struct V_23 * V_24 ,
int V_314 )
{
struct V_6 * V_7 , * V_30 = NULL ;
unsigned short V_59 = F_56 ( V_95 -> V_100 ) ;
struct V_3 * V_4 = F_25 ( V_24 , V_1 , V_59 ) ;
unsigned int V_81 = 0 , V_315 = 0 , V_316 = ( V_4 -> V_36 > 10 ) ;
unsigned int V_132 = F_83 ( F_220 ( * V_7 ) , V_317 ) ;
int V_60 = V_73 -> V_87 -> V_102 ;
struct V_318 * V_319 ;
struct V_72 * V_320 ;
if ( V_316 ) {
V_315 = F_41 ( V_1 , F_45 ( V_55 ) , V_59 ) &
V_24 -> V_33 ;
V_81 = F_41 ( V_1 , V_58 , V_59 ) & V_24 -> V_33 ;
V_321:
V_4 = & V_24 -> V_81 [ V_81 ] ;
V_132 = F_83 ( F_220 ( * V_7 ) , V_322 . V_323 ) ;
}
F_221 (sk, node, &hslot->head, offset) {
if ( ! F_67 ( V_1 , V_7 , V_95 -> V_100 , V_58 ,
V_95 -> V_101 , V_52 , V_60 , V_59 ) )
continue;
if ( ! V_30 ) {
V_30 = V_7 ;
continue;
}
V_320 = F_222 ( V_73 , V_324 ) ;
if ( F_58 ( ! V_320 ) ) {
F_152 ( & V_7 -> V_263 ) ;
F_167 ( V_1 , V_302 ,
F_93 ( V_7 ) ) ;
F_167 ( V_1 , V_270 ,
F_93 ( V_7 ) ) ;
continue;
}
if ( F_206 ( V_7 , V_320 ) > 0 )
F_163 ( V_320 ) ;
}
if ( V_316 && V_81 != V_315 ) {
V_81 = V_315 ;
goto V_321;
}
if ( V_30 ) {
if ( F_206 ( V_30 , V_73 ) > 0 )
F_163 ( V_73 ) ;
} else {
F_155 ( V_73 ) ;
F_167 ( V_1 , V_325 ,
V_314 == V_326 ) ;
}
return 0 ;
}
static inline int F_223 ( struct V_72 * V_73 , struct V_79 * V_95 ,
int V_314 )
{
int V_99 ;
F_177 ( V_73 ) -> V_288 = 0 ;
F_177 ( V_73 ) -> V_309 = V_73 -> V_129 ;
if ( V_314 == V_326 ) {
V_99 = F_224 ( V_73 , V_95 ) ;
if ( V_99 )
return V_99 ;
}
return ( V_54 int ) F_225 ( V_73 , V_314 , V_95 -> V_137 ,
V_327 ) ;
}
int F_226 ( struct V_72 * V_73 , struct V_23 * V_24 ,
int V_314 )
{
struct V_6 * V_7 ;
struct V_79 * V_95 ;
unsigned short V_163 ;
struct V_166 * V_167 = F_227 ( V_73 ) ;
T_4 V_52 , V_58 ;
struct V_1 * V_1 = F_62 ( V_73 -> V_87 ) ;
if ( ! F_228 ( V_73 , sizeof( struct V_79 ) ) )
goto V_257;
V_95 = F_79 ( V_73 ) ;
V_163 = F_56 ( V_95 -> V_129 ) ;
V_52 = F_61 ( V_73 ) -> V_52 ;
V_58 = F_61 ( V_73 ) -> V_58 ;
if ( V_163 > V_73 -> V_129 )
goto V_328;
if ( V_314 == V_138 ) {
if ( V_163 < sizeof( * V_95 ) || F_229 ( V_73 , V_163 ) )
goto V_328;
V_95 = F_79 ( V_73 ) ;
}
if ( F_223 ( V_73 , V_95 , V_314 ) )
goto V_306;
V_7 = F_230 ( V_73 ) ;
if ( V_7 ) {
struct V_311 * V_131 = F_231 ( V_73 ) ;
int V_236 ;
if ( F_58 ( V_7 -> V_313 != V_131 ) )
F_215 ( V_7 , V_131 ) ;
V_236 = F_206 ( V_7 , V_73 ) ;
F_232 ( V_7 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( V_167 -> V_222 & ( V_223 | V_329 ) )
return F_219 ( V_1 , V_73 , V_95 ,
V_52 , V_58 , V_24 , V_314 ) ;
V_7 = F_60 ( V_73 , V_95 -> V_101 , V_95 -> V_100 , V_24 ) ;
if ( V_7 ) {
int V_236 ;
if ( F_233 ( V_7 ) && V_95 -> V_137 && ! F_93 ( V_7 ) )
F_234 ( V_73 , V_138 , V_95 -> V_137 ,
V_327 ) ;
V_236 = F_206 ( V_7 , V_73 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( ! F_207 ( NULL , V_304 , V_73 ) )
goto V_257;
F_208 ( V_73 ) ;
if ( F_166 ( V_73 ) )
goto V_306;
F_167 ( V_1 , V_330 , V_314 == V_326 ) ;
F_235 ( V_73 , V_110 , V_331 , 0 ) ;
F_155 ( V_73 ) ;
return 0 ;
V_328:
F_129 ( L_5 ,
V_314 == V_326 ? L_6 : L_7 ,
& V_52 , F_56 ( V_95 -> V_101 ) ,
V_163 , V_73 -> V_129 ,
& V_58 , F_56 ( V_95 -> V_100 ) ) ;
goto V_257;
V_306:
F_129 ( L_8 ,
V_314 == V_326 ? L_6 : L_7 ,
& V_52 , F_56 ( V_95 -> V_101 ) , & V_58 , F_56 ( V_95 -> V_100 ) ,
V_163 ) ;
F_167 ( V_1 , V_269 , V_314 == V_326 ) ;
V_257:
F_167 ( V_1 , V_270 , V_314 == V_326 ) ;
F_155 ( V_73 ) ;
return 0 ;
}
static struct V_6 * F_236 ( struct V_1 * V_1 ,
T_5 V_89 , T_4 V_90 ,
T_5 V_91 , T_4 V_92 ,
int V_60 )
{
struct V_6 * V_7 , * V_74 ;
unsigned short V_59 = F_56 ( V_89 ) ;
unsigned int V_82 = F_57 ( V_1 , V_59 , V_23 . V_33 ) ;
struct V_3 * V_4 = & V_23 . V_78 [ V_82 ] ;
if ( V_4 -> V_36 > 10 )
return NULL ;
V_74 = NULL ;
F_59 (sk, &hslot->head) {
if ( F_67 ( V_1 , V_7 , V_89 , V_90 ,
V_91 , V_92 , V_60 , V_59 ) ) {
if ( V_74 )
return NULL ;
V_74 = V_7 ;
}
}
return V_74 ;
}
static struct V_6 * F_237 ( struct V_1 * V_1 ,
T_5 V_89 , T_4 V_90 ,
T_5 V_91 , T_4 V_92 ,
int V_60 )
{
unsigned short V_59 = F_56 ( V_89 ) ;
unsigned int V_81 = F_41 ( V_1 , V_90 , V_59 ) ;
unsigned int V_38 = V_81 & V_23 . V_33 ;
struct V_3 * V_17 = & V_23 . V_81 [ V_38 ] ;
F_238 ( V_332 , V_92 , V_90 ) ;
const T_12 V_333 = F_239 ( V_91 , V_59 ) ;
struct V_6 * V_7 ;
F_52 (sk, &hslot2->head) {
if ( F_240 ( V_7 , V_1 , V_332 , V_92 ,
V_90 , V_333 , V_60 ) )
return V_7 ;
break;
}
return NULL ;
}
void F_241 ( struct V_72 * V_73 )
{
struct V_1 * V_1 = F_62 ( V_73 -> V_87 ) ;
const struct V_85 * V_86 ;
const struct V_79 * V_95 ;
struct V_6 * V_7 = NULL ;
struct V_311 * V_131 ;
int V_60 = V_73 -> V_87 -> V_102 ;
int V_334 ;
if ( ! F_228 ( V_73 , F_80 ( V_73 ) + sizeof( struct V_79 ) ) )
return;
V_86 = F_61 ( V_73 ) ;
V_95 = F_79 ( V_73 ) ;
if ( V_73 -> V_335 == V_336 ||
V_73 -> V_335 == V_337 ) {
struct V_338 * V_339 = F_242 ( V_73 -> V_87 ) ;
if ( ! V_339 )
return;
if ( V_73 -> V_335 == V_337 ) {
V_334 = F_243 ( V_339 , V_86 -> V_58 , V_86 -> V_52 ,
V_86 -> V_340 ) ;
if ( ! V_334 )
return;
}
V_7 = F_236 ( V_1 , V_95 -> V_100 , V_86 -> V_58 ,
V_95 -> V_101 , V_86 -> V_52 , V_60 ) ;
} else if ( V_73 -> V_335 == V_341 ) {
V_7 = F_237 ( V_1 , V_95 -> V_100 , V_86 -> V_58 ,
V_95 -> V_101 , V_86 -> V_52 , V_60 ) ;
}
if ( ! V_7 || ! F_244 ( & V_7 -> V_88 , 2 ) )
return;
V_73 -> V_7 = V_7 ;
V_73 -> V_342 = V_343 ;
V_131 = F_159 ( V_7 -> V_313 ) ;
if ( V_131 )
V_131 = F_245 ( V_131 , 0 ) ;
if ( V_131 ) {
if ( V_131 -> V_232 & V_344 ) {
if ( F_104 ( F_66 ( & V_131 -> V_345 ) ) )
F_246 ( V_73 , V_131 ) ;
} else {
F_247 ( V_73 , V_131 ) ;
}
}
}
int F_248 ( struct V_72 * V_73 )
{
return F_226 ( V_73 , & V_23 , V_138 ) ;
}
void F_249 ( struct V_6 * V_7 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
bool V_267 = F_160 ( V_7 ) ;
F_76 ( V_7 ) ;
F_162 ( V_7 , V_267 ) ;
if ( F_209 ( & V_303 ) && V_127 -> V_305 ) {
void (* F_250)( struct V_6 * V_7 );
F_250 = F_211 ( V_127 -> F_250 ) ;
if ( F_250 )
F_250 ( V_7 ) ;
}
}
int F_251 ( struct V_6 * V_7 , int V_346 , int V_347 ,
char V_275 * V_348 , unsigned int V_206 ,
int (* F_252)( struct V_6 * ) )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_349 , V_350 ;
int V_99 = 0 ;
int V_147 = F_93 ( V_7 ) ;
if ( V_206 < sizeof( int ) )
return - V_184 ;
if ( F_253 ( V_349 , ( int V_275 * ) V_348 ) )
return - V_351 ;
V_350 = V_349 ? 1 : 0 ;
switch ( V_347 ) {
case V_352 :
if ( V_349 != 0 ) {
V_127 -> V_171 = 1 ;
} else {
V_127 -> V_171 = 0 ;
F_103 ( V_7 ) ;
F_252 ( V_7 ) ;
F_105 ( V_7 ) ;
}
break;
case V_353 :
switch ( V_349 ) {
case 0 :
case V_354 :
case V_355 :
V_127 -> F_210 = V_356 ;
case V_357 :
V_127 -> V_305 = V_349 ;
F_203 () ;
break;
default:
V_99 = - V_358 ;
break;
}
break;
case V_359 :
V_127 -> V_360 = V_350 ;
break;
case V_361 :
V_127 -> V_362 = V_350 ;
break;
case V_363 :
if ( ! V_147 )
return - V_358 ;
if ( V_349 != 0 && V_349 < 8 )
V_349 = 8 ;
else if ( V_349 > V_364 )
V_349 = V_364 ;
V_127 -> V_365 = V_349 ;
V_127 -> V_366 |= V_367 ;
break;
case V_368 :
if ( ! V_147 )
return - V_358 ;
if ( V_349 != 0 && V_349 < 8 )
V_349 = 8 ;
else if ( V_349 > V_364 )
V_349 = V_364 ;
V_127 -> V_308 = V_349 ;
V_127 -> V_366 |= V_307 ;
break;
default:
V_99 = - V_358 ;
break;
}
return V_99 ;
}
int F_254 ( struct V_6 * V_7 , int V_346 , int V_347 ,
char V_275 * V_348 , unsigned int V_206 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_251 ( V_7 , V_346 , V_347 , V_348 , V_206 ,
F_99 ) ;
return F_255 ( V_7 , V_346 , V_347 , V_348 , V_206 ) ;
}
int F_256 ( struct V_6 * V_7 , int V_346 , int V_347 ,
char V_275 * V_348 , unsigned int V_206 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_251 ( V_7 , V_346 , V_347 , V_348 , V_206 ,
F_99 ) ;
return F_257 ( V_7 , V_346 , V_347 , V_348 , V_206 ) ;
}
int F_258 ( struct V_6 * V_7 , int V_346 , int V_347 ,
char V_275 * V_348 , int V_275 * V_206 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_349 , V_129 ;
if ( F_253 ( V_129 , V_206 ) )
return - V_351 ;
V_129 = F_259 (unsigned int, len, sizeof(int)) ;
if ( V_129 < 0 )
return - V_184 ;
switch ( V_347 ) {
case V_352 :
V_349 = V_127 -> V_171 ;
break;
case V_353 :
V_349 = V_127 -> V_305 ;
break;
case V_359 :
V_349 = V_127 -> V_360 ;
break;
case V_361 :
V_349 = V_127 -> V_362 ;
break;
case V_363 :
V_349 = V_127 -> V_365 ;
break;
case V_368 :
V_349 = V_127 -> V_308 ;
break;
default:
return - V_358 ;
}
if ( F_171 ( V_129 , V_206 ) )
return - V_351 ;
if ( F_260 ( V_348 , & V_349 , V_129 ) )
return - V_351 ;
return 0 ;
}
int F_261 ( struct V_6 * V_7 , int V_346 , int V_347 ,
char V_275 * V_348 , int V_275 * V_206 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_258 ( V_7 , V_346 , V_347 , V_348 , V_206 ) ;
return F_262 ( V_7 , V_346 , V_347 , V_348 , V_206 ) ;
}
int F_263 ( struct V_6 * V_7 , int V_346 , int V_347 ,
char V_275 * V_348 , int V_275 * V_206 )
{
if ( V_346 == V_369 || V_346 == V_370 )
return F_258 ( V_7 , V_346 , V_347 , V_348 , V_206 ) ;
return F_264 ( V_7 , V_346 , V_347 , V_348 , V_206 ) ;
}
unsigned int F_265 ( struct V_371 * V_371 , struct V_372 * V_6 , T_13 * V_373 )
{
unsigned int V_33 = F_266 ( V_371 , V_6 , V_373 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_267 ( V_7 ) ;
if ( ( V_33 & V_374 ) && ! ( V_371 -> V_375 & V_376 ) &&
! ( V_7 -> V_377 & V_378 ) && F_164 ( V_7 ) == - 1 )
V_33 &= ~ ( V_379 | V_374 ) ;
return V_33 ;
}
int F_268 ( struct V_6 * V_7 , int V_99 )
{
F_103 ( V_7 ) ;
V_7 -> V_124 = V_99 ;
V_7 -> V_125 ( V_7 ) ;
F_185 ( V_7 , 0 ) ;
F_105 ( V_7 ) ;
return 0 ;
}
static struct V_6 * F_269 ( struct V_380 * V_381 , int V_382 )
{
struct V_6 * V_7 ;
struct V_383 * V_384 = V_381 -> V_385 ;
struct V_1 * V_1 = F_270 ( V_381 ) ;
for ( V_384 -> V_386 = V_382 ; V_384 -> V_386 <= V_384 -> V_23 -> V_33 ;
++ V_384 -> V_386 ) {
struct V_3 * V_4 = & V_384 -> V_23 -> V_78 [ V_384 -> V_386 ] ;
if ( F_271 ( & V_4 -> V_43 ) )
continue;
F_27 ( & V_4 -> V_19 ) ;
F_4 (sk, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_20 == V_384 -> V_387 )
goto V_34;
}
F_30 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_34:
return V_7 ;
}
static struct V_6 * F_272 ( struct V_380 * V_381 , struct V_6 * V_7 )
{
struct V_383 * V_384 = V_381 -> V_385 ;
struct V_1 * V_1 = F_270 ( V_381 ) ;
do {
V_7 = F_273 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_20 != V_384 -> V_387 ) );
if ( ! V_7 ) {
if ( V_384 -> V_386 <= V_384 -> V_23 -> V_33 )
F_30 ( & V_384 -> V_23 -> V_78 [ V_384 -> V_386 ] . V_19 ) ;
return F_269 ( V_381 , V_384 -> V_386 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_274 ( struct V_380 * V_381 , T_14 V_388 )
{
struct V_6 * V_7 = F_269 ( V_381 , 0 ) ;
if ( V_7 )
while ( V_388 && ( V_7 = F_272 ( V_381 , V_7 ) ) != NULL )
-- V_388 ;
return V_388 ? NULL : V_7 ;
}
static void * F_275 ( struct V_380 * V_381 , T_14 * V_388 )
{
struct V_383 * V_384 = V_381 -> V_385 ;
V_384 -> V_386 = V_389 ;
return * V_388 ? F_274 ( V_381 , * V_388 - 1 ) : V_390 ;
}
static void * F_276 ( struct V_380 * V_381 , void * V_391 , T_14 * V_388 )
{
struct V_6 * V_7 ;
if ( V_391 == V_390 )
V_7 = F_274 ( V_381 , 0 ) ;
else
V_7 = F_272 ( V_381 , V_391 ) ;
++ * V_388 ;
return V_7 ;
}
static void F_277 ( struct V_380 * V_381 , void * V_391 )
{
struct V_383 * V_384 = V_381 -> V_385 ;
if ( V_384 -> V_386 <= V_384 -> V_23 -> V_33 )
F_30 ( & V_384 -> V_23 -> V_78 [ V_384 -> V_386 ] . V_19 ) ;
}
int F_278 ( struct V_392 * V_392 , struct V_371 * V_371 )
{
struct V_393 * V_394 = F_279 ( V_392 ) ;
struct V_383 * V_395 ;
int V_99 ;
V_99 = F_280 ( V_392 , V_371 , & V_394 -> V_396 ,
sizeof( struct V_383 ) ) ;
if ( V_99 < 0 )
return V_99 ;
V_395 = ( (struct V_380 * ) V_371 -> V_397 ) -> V_385 ;
V_395 -> V_387 = V_394 -> V_387 ;
V_395 -> V_23 = V_394 -> V_23 ;
return V_99 ;
}
int F_281 ( struct V_1 * V_1 , struct V_393 * V_394 )
{
struct V_398 * V_399 ;
int V_301 = 0 ;
V_394 -> V_396 . V_382 = F_275 ;
V_394 -> V_396 . V_400 = F_276 ;
V_394 -> V_396 . V_401 = F_277 ;
V_399 = F_282 ( V_394 -> V_402 , V_403 , V_1 -> V_404 ,
V_394 -> V_405 , V_394 ) ;
if ( ! V_399 )
V_301 = - V_256 ;
return V_301 ;
}
void F_283 ( struct V_1 * V_1 , struct V_393 * V_394 )
{
F_284 ( V_394 -> V_402 , V_1 -> V_404 ) ;
}
static void F_285 ( struct V_6 * V_406 , struct V_380 * V_407 ,
int V_386 )
{
struct V_48 * V_62 = F_32 ( V_406 ) ;
T_4 V_100 = V_62 -> V_64 ;
T_4 V_130 = V_62 -> V_51 ;
T_1 V_408 = F_56 ( V_62 -> V_65 ) ;
T_1 V_409 = F_56 ( V_62 -> V_148 ) ;
F_286 ( V_407 , L_9
L_10 ,
V_386 , V_130 , V_409 , V_100 , V_408 , V_406 -> V_121 ,
F_170 ( V_406 ) ,
F_287 ( V_406 ) ,
0 , 0L , 0 ,
F_288 ( F_289 ( V_407 ) , F_3 ( V_406 ) ) ,
0 , F_290 ( V_406 ) ,
F_145 ( & V_406 -> V_88 ) , V_406 ,
F_145 ( & V_406 -> V_263 ) ) ;
}
int F_291 ( struct V_380 * V_381 , void * V_391 )
{
F_292 ( V_381 , 127 ) ;
if ( V_391 == V_390 )
F_293 ( V_381 , L_11
L_12
L_13 ) ;
else {
struct V_383 * V_384 = V_381 -> V_385 ;
F_285 ( V_391 , V_381 , V_384 -> V_386 ) ;
}
F_294 ( V_381 , '\n' ) ;
return 0 ;
}
static int T_15 F_295 ( struct V_1 * V_1 )
{
return F_281 ( V_1 , & V_410 ) ;
}
static void T_16 F_296 ( struct V_1 * V_1 )
{
F_283 ( V_1 , & V_410 ) ;
}
int T_17 F_297 ( void )
{
return F_298 ( & V_411 ) ;
}
void F_299 ( void )
{
F_300 ( & V_411 ) ;
}
static int T_17 F_301 ( char * V_412 )
{
T_18 V_236 ;
if ( ! V_412 )
return 0 ;
V_236 = F_302 ( V_412 , 0 , & V_413 ) ;
if ( V_236 )
return 0 ;
if ( V_413 && V_413 < V_414 )
V_413 = V_414 ;
return 1 ;
}
void T_17 F_303 ( struct V_23 * V_415 , const char * V_402 )
{
unsigned int V_416 ;
V_415 -> V_78 = F_304 ( V_402 ,
2 * sizeof( struct V_3 ) ,
V_413 ,
21 ,
0 ,
& V_415 -> log ,
& V_415 -> V_33 ,
V_414 ,
64 * 1024 ) ;
V_415 -> V_81 = V_415 -> V_78 + ( V_415 -> V_33 + 1 ) ;
for ( V_416 = 0 ; V_416 <= V_415 -> V_33 ; V_416 ++ ) {
F_305 ( & V_415 -> V_78 [ V_416 ] . V_43 ) ;
V_415 -> V_78 [ V_416 ] . V_36 = 0 ;
F_306 ( & V_415 -> V_78 [ V_416 ] . V_19 ) ;
}
for ( V_416 = 0 ; V_416 <= V_415 -> V_33 ; V_416 ++ ) {
F_305 ( & V_415 -> V_81 [ V_416 ] . V_43 ) ;
V_415 -> V_81 [ V_416 ] . V_36 = 0 ;
F_306 ( & V_415 -> V_81 [ V_416 ] . V_19 ) ;
}
}
T_3 F_307 ( void )
{
static T_3 T_19 V_71 ;
F_49 ( & T_19 , sizeof( T_19 ) ) ;
return T_19 ;
}
void T_17 F_308 ( void )
{
unsigned long V_417 ;
unsigned int V_416 ;
F_303 ( & V_23 , L_14 ) ;
V_417 = F_309 () / 8 ;
V_417 = F_310 ( V_417 , 128UL ) ;
V_418 [ 0 ] = V_417 / 4 * 3 ;
V_418 [ 1 ] = V_417 ;
V_418 [ 2 ] = V_418 [ 0 ] * 2 ;
V_419 = V_244 ;
V_420 = V_244 ;
V_251 = F_311 ( V_421 ) + 4 ;
V_250 = F_312 ( sizeof( T_10 ) << V_251 ,
V_422 ) ;
if ( ! V_250 )
F_313 ( L_15 ) ;
for ( V_416 = 0 ; V_416 < ( 1U << V_251 ) ; V_416 ++ )
F_306 ( V_250 + V_416 ) ;
}
