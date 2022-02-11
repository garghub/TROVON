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
V_69 , V_52 , V_80 , V_62 -> V_148 ) ;
F_119 ( V_7 , F_120 ( V_146 ) ) ;
V_167 = F_121 ( V_1 , V_146 , V_7 ) ;
if ( F_122 ( V_167 ) ) {
V_99 = F_123 ( V_167 ) ;
V_167 = NULL ;
if ( V_99 == - V_218 )
F_124 ( V_1 , V_219 ) ;
goto V_107;
}
V_99 = - V_220 ;
if ( ( V_167 -> V_221 & V_222 ) &&
! F_114 ( V_7 , V_223 ) )
goto V_107;
if ( V_168 )
F_125 ( V_7 , F_126 ( & V_167 -> V_131 ) ) ;
}
if ( V_161 -> V_172 & V_224 )
goto V_225;
V_226:
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
V_146 -> V_227 = V_62 -> V_148 ;
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
else if ( F_58 ( F_131 ( & V_7 -> V_228 ) ) )
V_127 -> V_128 = 0 ;
F_105 ( V_7 ) ;
V_107:
F_132 ( V_167 ) ;
if ( free )
F_108 ( V_165 . V_178 ) ;
if ( ! V_99 )
return V_129 ;
if ( V_99 == - V_153 || F_28 ( V_229 , & V_7 -> V_230 -> V_231 ) ) {
F_98 ( F_6 ( V_7 ) ,
V_154 , V_147 ) ;
}
return V_99 ;
V_225:
F_133 ( & V_167 -> V_131 ) ;
if ( ! ( V_161 -> V_172 & V_232 ) || V_129 )
goto V_226;
V_99 = 0 ;
goto V_107;
}
int F_134 ( struct V_6 * V_7 , struct V_233 * V_233 , int V_132 ,
T_8 V_234 , int V_231 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_235 ;
if ( V_231 & V_236 )
V_231 |= V_173 ;
if ( ! V_127 -> V_128 ) {
struct V_160 V_161 = { . V_172 = V_231 | V_173 } ;
V_235 = F_101 ( V_7 , & V_161 , 0 ) ;
if ( V_235 < 0 )
return V_235 ;
}
F_103 ( V_7 ) ;
if ( F_58 ( ! V_127 -> V_128 ) ) {
F_105 ( V_7 ) ;
F_129 ( L_2 ) ;
return - V_184 ;
}
V_235 = F_135 ( V_7 , & V_62 -> V_156 . V_157 . V_158 . V_159 ,
V_233 , V_132 , V_234 , V_231 ) ;
if ( V_235 == - V_177 ) {
F_105 ( V_7 ) ;
return F_136 ( V_7 -> V_230 , V_233 , V_132 ,
V_234 , V_231 ) ;
}
if ( V_235 < 0 ) {
F_76 ( V_7 ) ;
goto V_107;
}
V_127 -> V_129 += V_234 ;
if ( ! ( V_127 -> V_171 || ( V_231 & V_173 ) ) )
V_235 = F_99 ( V_7 ) ;
if ( ! V_235 )
V_235 = V_234 ;
V_107:
F_105 ( V_7 ) ;
return V_235 ;
}
static int F_137 ( struct V_6 * V_7 )
{
struct V_237 V_238 , * V_239 = & V_7 -> V_240 ;
struct V_72 * V_73 ;
int V_18 ;
F_138 ( & V_238 ) ;
F_27 ( & V_239 -> V_19 ) ;
while ( ( V_73 = F_139 ( V_239 ) ) != NULL &&
F_140 ( V_73 ) ) {
F_141 ( F_6 ( V_7 ) , V_241 ,
F_93 ( V_7 ) ) ;
F_141 ( F_6 ( V_7 ) , V_242 ,
F_93 ( V_7 ) ) ;
F_142 ( & V_7 -> V_243 ) ;
F_143 ( V_73 , V_239 ) ;
F_144 ( & V_238 , V_73 ) ;
}
V_18 = V_73 ? V_73 -> V_129 : - 1 ;
F_30 ( & V_239 -> V_19 ) ;
if ( ! F_131 ( & V_238 ) ) {
bool V_244 = F_145 ( V_7 ) ;
F_146 ( & V_238 ) ;
F_147 ( V_7 ) ;
F_148 ( V_7 , V_244 ) ;
}
return V_18 ;
}
int F_149 ( struct V_6 * V_7 , int V_245 , unsigned long V_246 )
{
switch ( V_245 ) {
case V_247 :
{
int V_248 = F_150 ( V_7 ) ;
return F_151 ( V_248 , ( int V_249 * ) V_246 ) ;
}
case V_250 :
{
int V_248 = F_152 ( int , 0 , F_137 ( V_7 ) ) ;
return F_151 ( V_248 , ( int V_249 * ) V_246 ) ;
}
default:
return - V_251 ;
}
return 0 ;
}
int F_153 ( struct V_6 * V_7 , struct V_160 * V_161 , T_8 V_129 , int V_252 ,
int V_231 , int * V_253 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
F_106 ( struct V_187 * , sin , V_161 -> V_186 ) ;
struct V_72 * V_73 ;
unsigned int V_163 , V_254 ;
int V_255 , V_256 , V_257 ;
int V_99 ;
int V_147 = F_93 ( V_7 ) ;
bool V_258 = false ;
bool V_244 ;
if ( V_231 & V_259 )
return F_154 ( V_7 , V_161 , V_129 , V_253 ) ;
V_260:
V_256 = V_257 = F_155 ( V_7 , V_231 ) ;
V_73 = F_156 ( V_7 , V_231 | ( V_252 ? V_261 : 0 ) ,
& V_255 , & V_257 , & V_99 ) ;
if ( ! V_73 )
return V_99 ;
V_163 = V_73 -> V_129 ;
V_254 = V_129 ;
if ( V_254 > V_163 - V_257 )
V_254 = V_163 - V_257 ;
else if ( V_254 < V_163 )
V_161 -> V_172 |= V_262 ;
if ( V_254 < V_163 || F_157 ( V_73 ) -> V_263 || V_256 ) {
V_258 = ! F_140 ( V_73 ) ;
if ( ! V_258 )
goto V_264;
}
if ( V_258 || F_158 ( V_73 ) )
V_99 = F_159 ( V_73 , V_257 , V_161 , V_254 ) ;
else {
V_99 = F_160 ( V_73 , V_257 , V_161 ) ;
if ( V_99 == - V_184 )
goto V_264;
}
if ( F_58 ( V_99 ) ) {
F_161 ( V_73 , F_153 ) ;
if ( ! V_255 ) {
F_142 ( & V_7 -> V_243 ) ;
F_98 ( F_6 ( V_7 ) ,
V_242 , V_147 ) ;
}
F_162 ( V_7 , V_73 ) ;
return V_99 ;
}
if ( ! V_255 )
F_98 ( F_6 ( V_7 ) ,
V_265 , V_147 ) ;
F_163 ( V_161 , V_7 , V_73 ) ;
if ( sin ) {
sin -> V_190 = V_183 ;
sin -> V_195 = F_79 ( V_73 ) -> V_101 ;
sin -> V_193 . V_194 = F_61 ( V_73 ) -> V_52 ;
memset ( sin -> V_266 , 0 , sizeof( sin -> V_266 ) ) ;
* V_253 = sizeof( * sin ) ;
}
if ( V_62 -> V_267 )
F_164 ( V_161 , V_73 , sizeof( struct V_79 ) , V_257 ) ;
V_99 = V_254 ;
if ( V_231 & V_262 )
V_99 = V_163 ;
F_165 ( V_7 , V_73 , V_256 ? - V_99 : V_99 ) ;
return V_99 ;
V_264:
V_244 = F_145 ( V_7 ) ;
if ( ! F_166 ( V_7 , V_73 , V_231 ) ) {
F_98 ( F_6 ( V_7 ) , V_241 , V_147 ) ;
F_98 ( F_6 ( V_7 ) , V_242 , V_147 ) ;
}
F_148 ( V_7 , V_244 ) ;
F_167 () ;
V_161 -> V_172 &= ~ V_262 ;
goto V_260;
}
int F_168 ( struct V_6 * V_7 , int V_231 )
{
struct V_48 * V_62 = F_32 ( V_7 ) ;
V_7 -> V_121 = V_268 ;
V_62 -> V_64 = 0 ;
V_62 -> V_65 = 0 ;
F_169 ( V_7 ) ;
V_7 -> V_14 = 0 ;
if ( ! ( V_7 -> V_269 & V_270 ) )
F_170 ( V_7 ) ;
if ( ! ( V_7 -> V_269 & V_271 ) ) {
V_7 -> V_25 -> V_272 ( V_7 ) ;
V_62 -> V_148 = 0 ;
}
F_171 ( V_7 ) ;
return 0 ;
}
int F_172 ( struct V_6 * V_7 , int V_231 )
{
F_103 ( V_7 ) ;
F_168 ( V_7 , V_231 ) ;
F_105 ( V_7 ) ;
return 0 ;
}
void F_173 ( struct V_6 * V_7 )
{
if ( F_174 ( V_7 ) ) {
struct V_23 * V_24 = V_7 -> V_25 -> V_26 . V_23 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_25 ( V_24 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_12 ) ;
V_17 = F_31 ( V_24 , F_7 ( V_7 ) -> V_39 ) ;
F_27 ( & V_4 -> V_19 ) ;
if ( F_8 ( V_7 -> V_16 ) )
F_175 ( V_7 ) ;
if ( F_176 ( V_7 ) ) {
V_4 -> V_36 -- ;
F_32 ( V_7 ) -> V_42 = 0 ;
F_35 ( F_6 ( V_7 ) , V_7 -> V_25 , - 1 ) ;
F_12 ( & V_17 -> V_19 ) ;
F_177 ( & F_7 ( V_7 ) -> V_46 ) ;
V_17 -> V_36 -- ;
F_14 ( & V_17 -> V_19 ) ;
}
F_30 ( & V_4 -> V_19 ) ;
}
}
void F_178 ( struct V_6 * V_7 , T_10 V_273 )
{
if ( F_174 ( V_7 ) ) {
struct V_23 * V_24 = V_7 -> V_25 -> V_26 . V_23 ;
struct V_3 * V_4 , * V_17 , * V_274 ;
V_17 = F_31 ( V_24 , F_7 ( V_7 ) -> V_39 ) ;
V_274 = F_31 ( V_24 , V_273 ) ;
F_7 ( V_7 ) -> V_39 = V_273 ;
if ( V_17 != V_274 ||
F_8 ( V_7 -> V_16 ) ) {
V_4 = F_25 ( V_24 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_12 ) ;
F_27 ( & V_4 -> V_19 ) ;
if ( F_8 ( V_7 -> V_16 ) )
F_175 ( V_7 ) ;
if ( V_17 != V_274 ) {
F_12 ( & V_17 -> V_19 ) ;
F_177 ( & F_7 ( V_7 ) -> V_46 ) ;
V_17 -> V_36 -- ;
F_14 ( & V_17 -> V_19 ) ;
F_12 ( & V_274 -> V_19 ) ;
F_38 ( & F_7 ( V_7 ) -> V_46 ,
& V_274 -> V_43 ) ;
V_274 -> V_36 ++ ;
F_14 ( & V_274 -> V_19 ) ;
}
F_30 ( & V_4 -> V_19 ) ;
}
}
}
static void F_179 ( struct V_6 * V_7 )
{
T_10 V_275 = F_41 ( F_6 ( V_7 ) ,
F_32 ( V_7 ) -> V_51 ,
F_32 ( V_7 ) -> V_42 ) ;
F_178 ( V_7 , V_275 ) ;
}
int F_180 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
int V_276 ;
if ( F_32 ( V_7 ) -> V_64 ) {
F_181 ( V_7 , V_73 ) ;
F_182 ( V_7 , V_73 ) ;
F_183 ( V_7 ) ;
}
V_276 = F_184 ( V_7 , V_73 ) ;
if ( V_276 < 0 ) {
int V_147 = F_93 ( V_7 ) ;
if ( V_276 == - V_277 )
F_98 ( F_6 ( V_7 ) , V_278 ,
V_147 ) ;
F_98 ( F_6 ( V_7 ) , V_242 , V_147 ) ;
F_185 ( V_73 ) ;
F_186 ( V_276 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_187 ( void )
{
if ( ! F_188 ( & V_279 ) )
F_189 ( & V_279 ) ;
}
int F_190 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_276 ;
int V_147 = F_93 ( V_7 ) ;
if ( ! F_191 ( V_7 , V_280 , V_73 ) )
goto V_281;
F_192 ( V_73 ) ;
if ( F_193 ( & V_279 ) && V_127 -> V_282 ) {
int (* F_194)( struct V_6 * V_7 , struct V_72 * V_73 );
F_194 = F_195 ( V_127 -> F_194 ) ;
if ( F_194 ) {
int V_235 ;
if ( F_140 ( V_73 ) )
goto V_283;
V_235 = F_194 ( V_7 , V_73 ) ;
if ( V_235 <= 0 ) {
F_141 ( F_6 ( V_7 ) ,
V_265 ,
V_147 ) ;
return - V_235 ;
}
}
}
if ( ( V_147 & V_284 ) && F_157 ( V_73 ) -> V_263 ) {
if ( V_127 -> V_285 == 0 ) {
F_129 ( L_3 ,
F_157 ( V_73 ) -> V_286 , V_73 -> V_129 ) ;
goto V_281;
}
if ( F_157 ( V_73 ) -> V_286 < V_127 -> V_285 ) {
F_129 ( L_4 ,
F_157 ( V_73 ) -> V_286 , V_127 -> V_285 ) ;
goto V_281;
}
}
if ( F_8 ( V_7 -> V_287 ) &&
F_140 ( V_73 ) )
goto V_283;
if ( F_196 ( V_7 , V_73 , sizeof( struct V_79 ) ) )
goto V_281;
F_197 ( V_73 ) ;
if ( F_198 ( V_7 , V_7 -> V_288 ) ) {
F_141 ( F_6 ( V_7 ) , V_278 ,
V_147 ) ;
goto V_281;
}
V_276 = 0 ;
F_199 ( V_7 , V_73 ) ;
F_200 ( V_7 ) ;
if ( ! F_201 ( V_7 ) )
V_276 = F_180 ( V_7 , V_73 ) ;
else if ( F_202 ( V_7 , V_73 , V_7 -> V_288 ) ) {
F_203 ( V_7 ) ;
goto V_281;
}
F_203 ( V_7 ) ;
return V_276 ;
V_283:
F_141 ( F_6 ( V_7 ) , V_241 , V_147 ) ;
V_281:
F_141 ( F_6 ( V_7 ) , V_242 , V_147 ) ;
F_142 ( & V_7 -> V_243 ) ;
F_185 ( V_73 ) ;
return - 1 ;
}
static void F_204 ( struct V_6 * V_7 , struct V_289 * V_131 )
{
struct V_289 * V_290 ;
F_205 ( V_131 ) ;
V_290 = F_206 ( & V_7 -> V_291 , V_131 ) ;
F_207 ( V_290 ) ;
}
static int F_208 ( struct V_1 * V_1 , struct V_72 * V_73 ,
struct V_79 * V_95 ,
T_4 V_52 , T_4 V_58 ,
struct V_23 * V_24 ,
int V_292 )
{
struct V_6 * V_7 , * V_30 = NULL ;
unsigned short V_59 = F_56 ( V_95 -> V_100 ) ;
struct V_3 * V_4 = F_25 ( V_24 , V_1 , V_59 ) ;
unsigned int V_81 = 0 , V_293 = 0 , V_294 = ( V_4 -> V_36 > 10 ) ;
unsigned int V_132 = F_83 ( F_209 ( * V_7 ) , V_295 ) ;
int V_60 = V_73 -> V_87 -> V_102 ;
struct V_296 * V_297 ;
struct V_72 * V_298 ;
if ( V_294 ) {
V_293 = F_41 ( V_1 , F_45 ( V_55 ) , V_59 ) &
V_24 -> V_33 ;
V_81 = F_41 ( V_1 , V_58 , V_59 ) & V_24 -> V_33 ;
V_299:
V_4 = & V_24 -> V_81 [ V_81 ] ;
V_132 = F_83 ( F_209 ( * V_7 ) , V_300 . V_301 ) ;
}
F_210 (sk, node, &hslot->head, offset) {
if ( ! F_67 ( V_1 , V_7 , V_95 -> V_100 , V_58 ,
V_95 -> V_101 , V_52 , V_60 , V_59 ) )
continue;
if ( ! V_30 ) {
V_30 = V_7 ;
continue;
}
V_298 = F_211 ( V_73 , V_302 ) ;
if ( F_58 ( ! V_298 ) ) {
F_142 ( & V_7 -> V_243 ) ;
F_141 ( V_1 , V_278 ,
F_93 ( V_7 ) ) ;
F_141 ( V_1 , V_242 ,
F_93 ( V_7 ) ) ;
continue;
}
if ( F_190 ( V_7 , V_298 ) > 0 )
F_212 ( V_298 ) ;
}
if ( V_294 && V_81 != V_293 ) {
V_81 = V_293 ;
goto V_299;
}
if ( V_30 ) {
if ( F_190 ( V_30 , V_73 ) > 0 )
F_212 ( V_73 ) ;
} else {
F_185 ( V_73 ) ;
F_141 ( V_1 , V_303 ,
V_292 == V_304 ) ;
}
return 0 ;
}
static inline int F_213 ( struct V_72 * V_73 , struct V_79 * V_95 ,
int V_292 )
{
int V_99 ;
F_157 ( V_73 ) -> V_263 = 0 ;
F_157 ( V_73 ) -> V_286 = V_73 -> V_129 ;
if ( V_292 == V_304 ) {
V_99 = F_214 ( V_73 , V_95 ) ;
if ( V_99 )
return V_99 ;
}
return ( V_54 int ) F_215 ( V_73 , V_292 , V_95 -> V_137 ,
V_305 ) ;
}
int F_216 ( struct V_72 * V_73 , struct V_23 * V_24 ,
int V_292 )
{
struct V_6 * V_7 ;
struct V_79 * V_95 ;
unsigned short V_163 ;
struct V_166 * V_167 = F_217 ( V_73 ) ;
T_4 V_52 , V_58 ;
struct V_1 * V_1 = F_62 ( V_73 -> V_87 ) ;
if ( ! F_218 ( V_73 , sizeof( struct V_79 ) ) )
goto V_281;
V_95 = F_79 ( V_73 ) ;
V_163 = F_56 ( V_95 -> V_129 ) ;
V_52 = F_61 ( V_73 ) -> V_52 ;
V_58 = F_61 ( V_73 ) -> V_58 ;
if ( V_163 > V_73 -> V_129 )
goto V_306;
if ( V_292 == V_138 ) {
if ( V_163 < sizeof( * V_95 ) || F_219 ( V_73 , V_163 ) )
goto V_306;
V_95 = F_79 ( V_73 ) ;
}
if ( F_213 ( V_73 , V_95 , V_292 ) )
goto V_283;
V_7 = F_220 ( V_73 ) ;
if ( V_7 ) {
struct V_289 * V_131 = F_221 ( V_73 ) ;
int V_235 ;
if ( F_58 ( V_7 -> V_291 != V_131 ) )
F_204 ( V_7 , V_131 ) ;
V_235 = F_190 ( V_7 , V_73 ) ;
F_222 ( V_7 ) ;
if ( V_235 > 0 )
return - V_235 ;
return 0 ;
}
if ( V_167 -> V_221 & ( V_222 | V_307 ) )
return F_208 ( V_1 , V_73 , V_95 ,
V_52 , V_58 , V_24 , V_292 ) ;
V_7 = F_60 ( V_73 , V_95 -> V_101 , V_95 -> V_100 , V_24 ) ;
if ( V_7 ) {
int V_235 ;
if ( F_223 ( V_7 ) && V_95 -> V_137 && ! F_93 ( V_7 ) )
F_224 ( V_73 , V_138 , V_95 -> V_137 ,
V_305 ) ;
V_235 = F_190 ( V_7 , V_73 ) ;
if ( V_235 > 0 )
return - V_235 ;
return 0 ;
}
if ( ! F_191 ( NULL , V_280 , V_73 ) )
goto V_281;
F_192 ( V_73 ) ;
if ( F_140 ( V_73 ) )
goto V_283;
F_141 ( V_1 , V_308 , V_292 == V_304 ) ;
F_225 ( V_73 , V_110 , V_309 , 0 ) ;
F_185 ( V_73 ) ;
return 0 ;
V_306:
F_129 ( L_5 ,
V_292 == V_304 ? L_6 : L_7 ,
& V_52 , F_56 ( V_95 -> V_101 ) ,
V_163 , V_73 -> V_129 ,
& V_58 , F_56 ( V_95 -> V_100 ) ) ;
goto V_281;
V_283:
F_129 ( L_8 ,
V_292 == V_304 ? L_6 : L_7 ,
& V_52 , F_56 ( V_95 -> V_101 ) , & V_58 , F_56 ( V_95 -> V_100 ) ,
V_163 ) ;
F_141 ( V_1 , V_241 , V_292 == V_304 ) ;
V_281:
F_141 ( V_1 , V_242 , V_292 == V_304 ) ;
F_185 ( V_73 ) ;
return 0 ;
}
static struct V_6 * F_226 ( struct V_1 * V_1 ,
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
static struct V_6 * F_227 ( struct V_1 * V_1 ,
T_5 V_89 , T_4 V_90 ,
T_5 V_91 , T_4 V_92 ,
int V_60 )
{
unsigned short V_59 = F_56 ( V_89 ) ;
unsigned int V_81 = F_41 ( V_1 , V_90 , V_59 ) ;
unsigned int V_38 = V_81 & V_23 . V_33 ;
struct V_3 * V_17 = & V_23 . V_81 [ V_38 ] ;
F_228 ( V_310 , V_92 , V_90 ) ;
const T_11 V_311 = F_229 ( V_91 , V_59 ) ;
struct V_6 * V_7 ;
F_52 (sk, &hslot2->head) {
if ( F_230 ( V_7 , V_1 , V_310 , V_92 ,
V_90 , V_311 , V_60 ) )
return V_7 ;
break;
}
return NULL ;
}
void F_231 ( struct V_72 * V_73 )
{
struct V_1 * V_1 = F_62 ( V_73 -> V_87 ) ;
const struct V_85 * V_86 ;
const struct V_79 * V_95 ;
struct V_6 * V_7 = NULL ;
struct V_289 * V_131 ;
int V_60 = V_73 -> V_87 -> V_102 ;
int V_312 ;
if ( ! F_218 ( V_73 , F_80 ( V_73 ) + sizeof( struct V_79 ) ) )
return;
V_86 = F_61 ( V_73 ) ;
V_95 = F_79 ( V_73 ) ;
if ( V_73 -> V_313 == V_314 ||
V_73 -> V_313 == V_315 ) {
struct V_316 * V_317 = F_232 ( V_73 -> V_87 ) ;
if ( ! V_317 )
return;
if ( V_73 -> V_313 == V_315 ) {
V_312 = F_233 ( V_317 , V_86 -> V_58 , V_86 -> V_52 ,
V_86 -> V_318 ) ;
if ( ! V_312 )
return;
}
V_7 = F_226 ( V_1 , V_95 -> V_100 , V_86 -> V_58 ,
V_95 -> V_101 , V_86 -> V_52 , V_60 ) ;
} else if ( V_73 -> V_313 == V_319 ) {
V_7 = F_227 ( V_1 , V_95 -> V_100 , V_86 -> V_58 ,
V_95 -> V_101 , V_86 -> V_52 , V_60 ) ;
}
if ( ! V_7 || ! F_234 ( & V_7 -> V_88 , 2 ) )
return;
V_73 -> V_7 = V_7 ;
V_73 -> V_320 = V_321 ;
V_131 = F_235 ( V_7 -> V_291 ) ;
if ( V_131 )
V_131 = F_236 ( V_131 , 0 ) ;
if ( V_131 ) {
if ( V_131 -> V_231 & V_322 ) {
if ( F_104 ( F_66 ( & V_131 -> V_323 ) ) )
F_237 ( V_73 , V_131 ) ;
} else {
F_238 ( V_73 , V_131 ) ;
}
}
}
int F_239 ( struct V_72 * V_73 )
{
return F_216 ( V_73 , & V_23 , V_138 ) ;
}
void F_240 ( struct V_6 * V_7 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
bool V_244 = F_145 ( V_7 ) ;
F_76 ( V_7 ) ;
F_148 ( V_7 , V_244 ) ;
if ( F_193 ( & V_279 ) && V_127 -> V_282 ) {
void (* F_241)( struct V_6 * V_7 );
F_241 = F_195 ( V_127 -> F_241 ) ;
if ( F_241 )
F_241 ( V_7 ) ;
}
}
int F_242 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_249 * V_326 , unsigned int V_206 ,
int (* F_243)( struct V_6 * ) )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_327 , V_328 ;
int V_99 = 0 ;
int V_147 = F_93 ( V_7 ) ;
if ( V_206 < sizeof( int ) )
return - V_184 ;
if ( F_244 ( V_327 , ( int V_249 * ) V_326 ) )
return - V_329 ;
V_328 = V_327 ? 1 : 0 ;
switch ( V_325 ) {
case V_330 :
if ( V_327 != 0 ) {
V_127 -> V_171 = 1 ;
} else {
V_127 -> V_171 = 0 ;
F_103 ( V_7 ) ;
F_243 ( V_7 ) ;
F_105 ( V_7 ) ;
}
break;
case V_331 :
switch ( V_327 ) {
case 0 :
case V_332 :
case V_333 :
V_127 -> F_194 = V_334 ;
case V_335 :
V_127 -> V_282 = V_327 ;
F_187 () ;
break;
default:
V_99 = - V_336 ;
break;
}
break;
case V_337 :
V_127 -> V_338 = V_328 ;
break;
case V_339 :
V_127 -> V_340 = V_328 ;
break;
case V_341 :
if ( ! V_147 )
return - V_336 ;
if ( V_327 != 0 && V_327 < 8 )
V_327 = 8 ;
else if ( V_327 > V_342 )
V_327 = V_342 ;
V_127 -> V_343 = V_327 ;
V_127 -> V_344 |= V_345 ;
break;
case V_346 :
if ( ! V_147 )
return - V_336 ;
if ( V_327 != 0 && V_327 < 8 )
V_327 = 8 ;
else if ( V_327 > V_342 )
V_327 = V_342 ;
V_127 -> V_285 = V_327 ;
V_127 -> V_344 |= V_284 ;
break;
default:
V_99 = - V_336 ;
break;
}
return V_99 ;
}
int F_245 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_249 * V_326 , unsigned int V_206 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_242 ( V_7 , V_324 , V_325 , V_326 , V_206 ,
F_99 ) ;
return F_246 ( V_7 , V_324 , V_325 , V_326 , V_206 ) ;
}
int F_247 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_249 * V_326 , unsigned int V_206 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_242 ( V_7 , V_324 , V_325 , V_326 , V_206 ,
F_99 ) ;
return F_248 ( V_7 , V_324 , V_325 , V_326 , V_206 ) ;
}
int F_249 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_249 * V_326 , int V_249 * V_206 )
{
struct V_126 * V_127 = F_7 ( V_7 ) ;
int V_327 , V_129 ;
if ( F_244 ( V_129 , V_206 ) )
return - V_329 ;
V_129 = F_250 (unsigned int, len, sizeof(int)) ;
if ( V_129 < 0 )
return - V_184 ;
switch ( V_325 ) {
case V_330 :
V_327 = V_127 -> V_171 ;
break;
case V_331 :
V_327 = V_127 -> V_282 ;
break;
case V_337 :
V_327 = V_127 -> V_338 ;
break;
case V_339 :
V_327 = V_127 -> V_340 ;
break;
case V_341 :
V_327 = V_127 -> V_343 ;
break;
case V_346 :
V_327 = V_127 -> V_285 ;
break;
default:
return - V_336 ;
}
if ( F_151 ( V_129 , V_206 ) )
return - V_329 ;
if ( F_251 ( V_326 , & V_327 , V_129 ) )
return - V_329 ;
return 0 ;
}
int F_252 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_249 * V_326 , int V_249 * V_206 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_249 ( V_7 , V_324 , V_325 , V_326 , V_206 ) ;
return F_253 ( V_7 , V_324 , V_325 , V_326 , V_206 ) ;
}
int F_254 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_249 * V_326 , int V_249 * V_206 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_249 ( V_7 , V_324 , V_325 , V_326 , V_206 ) ;
return F_255 ( V_7 , V_324 , V_325 , V_326 , V_206 ) ;
}
unsigned int F_256 ( struct V_349 * V_349 , struct V_350 * V_6 , T_12 * V_351 )
{
unsigned int V_33 = F_257 ( V_349 , V_6 , V_351 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_258 ( V_7 ) ;
if ( ( V_33 & V_352 ) && ! ( V_349 -> V_353 & V_354 ) &&
! ( V_7 -> V_355 & V_356 ) && F_137 ( V_7 ) == - 1 )
V_33 &= ~ ( V_357 | V_352 ) ;
return V_33 ;
}
int F_259 ( struct V_6 * V_7 , int V_99 )
{
F_103 ( V_7 ) ;
V_7 -> V_124 = V_99 ;
V_7 -> V_125 ( V_7 ) ;
F_168 ( V_7 , 0 ) ;
F_105 ( V_7 ) ;
return 0 ;
}
static struct V_6 * F_260 ( struct V_358 * V_359 , int V_360 )
{
struct V_6 * V_7 ;
struct V_361 * V_362 = V_359 -> V_363 ;
struct V_1 * V_1 = F_261 ( V_359 ) ;
for ( V_362 -> V_364 = V_360 ; V_362 -> V_364 <= V_362 -> V_23 -> V_33 ;
++ V_362 -> V_364 ) {
struct V_3 * V_4 = & V_362 -> V_23 -> V_78 [ V_362 -> V_364 ] ;
if ( F_262 ( & V_4 -> V_43 ) )
continue;
F_27 ( & V_4 -> V_19 ) ;
F_4 (sk, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_20 == V_362 -> V_365 )
goto V_34;
}
F_30 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_34:
return V_7 ;
}
static struct V_6 * F_263 ( struct V_358 * V_359 , struct V_6 * V_7 )
{
struct V_361 * V_362 = V_359 -> V_363 ;
struct V_1 * V_1 = F_261 ( V_359 ) ;
do {
V_7 = F_264 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_20 != V_362 -> V_365 ) );
if ( ! V_7 ) {
if ( V_362 -> V_364 <= V_362 -> V_23 -> V_33 )
F_30 ( & V_362 -> V_23 -> V_78 [ V_362 -> V_364 ] . V_19 ) ;
return F_260 ( V_359 , V_362 -> V_364 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_265 ( struct V_358 * V_359 , T_13 V_366 )
{
struct V_6 * V_7 = F_260 ( V_359 , 0 ) ;
if ( V_7 )
while ( V_366 && ( V_7 = F_263 ( V_359 , V_7 ) ) != NULL )
-- V_366 ;
return V_366 ? NULL : V_7 ;
}
static void * F_266 ( struct V_358 * V_359 , T_13 * V_366 )
{
struct V_361 * V_362 = V_359 -> V_363 ;
V_362 -> V_364 = V_367 ;
return * V_366 ? F_265 ( V_359 , * V_366 - 1 ) : V_368 ;
}
static void * F_267 ( struct V_358 * V_359 , void * V_369 , T_13 * V_366 )
{
struct V_6 * V_7 ;
if ( V_369 == V_368 )
V_7 = F_265 ( V_359 , 0 ) ;
else
V_7 = F_263 ( V_359 , V_369 ) ;
++ * V_366 ;
return V_7 ;
}
static void F_268 ( struct V_358 * V_359 , void * V_369 )
{
struct V_361 * V_362 = V_359 -> V_363 ;
if ( V_362 -> V_364 <= V_362 -> V_23 -> V_33 )
F_30 ( & V_362 -> V_23 -> V_78 [ V_362 -> V_364 ] . V_19 ) ;
}
int F_269 ( struct V_370 * V_370 , struct V_349 * V_349 )
{
struct V_371 * V_372 = F_270 ( V_370 ) ;
struct V_361 * V_373 ;
int V_99 ;
V_99 = F_271 ( V_370 , V_349 , & V_372 -> V_374 ,
sizeof( struct V_361 ) ) ;
if ( V_99 < 0 )
return V_99 ;
V_373 = ( (struct V_358 * ) V_349 -> V_375 ) -> V_363 ;
V_373 -> V_365 = V_372 -> V_365 ;
V_373 -> V_23 = V_372 -> V_23 ;
return V_99 ;
}
int F_272 ( struct V_1 * V_1 , struct V_371 * V_372 )
{
struct V_376 * V_377 ;
int V_276 = 0 ;
V_372 -> V_374 . V_360 = F_266 ;
V_372 -> V_374 . V_378 = F_267 ;
V_372 -> V_374 . V_379 = F_268 ;
V_377 = F_273 ( V_372 -> V_380 , V_381 , V_1 -> V_382 ,
V_372 -> V_383 , V_372 ) ;
if ( ! V_377 )
V_276 = - V_277 ;
return V_276 ;
}
void F_274 ( struct V_1 * V_1 , struct V_371 * V_372 )
{
F_275 ( V_372 -> V_380 , V_1 -> V_382 ) ;
}
static void F_276 ( struct V_6 * V_384 , struct V_358 * V_385 ,
int V_364 )
{
struct V_48 * V_62 = F_32 ( V_384 ) ;
T_4 V_100 = V_62 -> V_64 ;
T_4 V_130 = V_62 -> V_51 ;
T_1 V_386 = F_56 ( V_62 -> V_65 ) ;
T_1 V_387 = F_56 ( V_62 -> V_148 ) ;
F_277 ( V_385 , L_9
L_10 ,
V_364 , V_130 , V_387 , V_100 , V_386 , V_384 -> V_121 ,
F_150 ( V_384 ) ,
F_278 ( V_384 ) ,
0 , 0L , 0 ,
F_279 ( F_280 ( V_385 ) , F_3 ( V_384 ) ) ,
0 , F_281 ( V_384 ) ,
F_282 ( & V_384 -> V_88 ) , V_384 ,
F_282 ( & V_384 -> V_243 ) ) ;
}
int F_283 ( struct V_358 * V_359 , void * V_369 )
{
F_284 ( V_359 , 127 ) ;
if ( V_369 == V_368 )
F_285 ( V_359 , L_11
L_12
L_13 ) ;
else {
struct V_361 * V_362 = V_359 -> V_363 ;
F_276 ( V_369 , V_359 , V_362 -> V_364 ) ;
}
F_286 ( V_359 , '\n' ) ;
return 0 ;
}
static int T_14 F_287 ( struct V_1 * V_1 )
{
return F_272 ( V_1 , & V_388 ) ;
}
static void T_15 F_288 ( struct V_1 * V_1 )
{
F_274 ( V_1 , & V_388 ) ;
}
int T_16 F_289 ( void )
{
return F_290 ( & V_389 ) ;
}
void F_291 ( void )
{
F_292 ( & V_389 ) ;
}
static int T_16 F_293 ( char * V_390 )
{
T_17 V_235 ;
if ( ! V_390 )
return 0 ;
V_235 = F_294 ( V_390 , 0 , & V_391 ) ;
if ( V_235 )
return 0 ;
if ( V_391 && V_391 < V_392 )
V_391 = V_392 ;
return 1 ;
}
void T_16 F_295 ( struct V_23 * V_393 , const char * V_380 )
{
unsigned int V_394 ;
V_393 -> V_78 = F_296 ( V_380 ,
2 * sizeof( struct V_3 ) ,
V_391 ,
21 ,
0 ,
& V_393 -> log ,
& V_393 -> V_33 ,
V_392 ,
64 * 1024 ) ;
V_393 -> V_81 = V_393 -> V_78 + ( V_393 -> V_33 + 1 ) ;
for ( V_394 = 0 ; V_394 <= V_393 -> V_33 ; V_394 ++ ) {
F_297 ( & V_393 -> V_78 [ V_394 ] . V_43 ) ;
V_393 -> V_78 [ V_394 ] . V_36 = 0 ;
F_298 ( & V_393 -> V_78 [ V_394 ] . V_19 ) ;
}
for ( V_394 = 0 ; V_394 <= V_393 -> V_33 ; V_394 ++ ) {
F_297 ( & V_393 -> V_81 [ V_394 ] . V_43 ) ;
V_393 -> V_81 [ V_394 ] . V_36 = 0 ;
F_298 ( & V_393 -> V_81 [ V_394 ] . V_19 ) ;
}
}
T_3 F_299 ( void )
{
static T_3 T_18 V_71 ;
F_49 ( & T_18 , sizeof( T_18 ) ) ;
return T_18 ;
}
void T_16 F_300 ( void )
{
unsigned long V_395 ;
F_295 ( & V_23 , L_14 ) ;
V_395 = F_301 () / 8 ;
V_395 = F_302 ( V_395 , 128UL ) ;
V_396 [ 0 ] = V_395 / 4 * 3 ;
V_396 [ 1 ] = V_395 ;
V_396 [ 2 ] = V_396 [ 0 ] * 2 ;
V_397 = V_398 ;
V_399 = V_398 ;
}
