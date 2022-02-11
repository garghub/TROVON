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
struct V_11 * V_12 ;
T_2 V_13 = F_3 ( V_7 ) ;
F_4 (sk2, node, &hslot->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( V_5 || F_7 ( V_9 ) -> V_14 == V_2 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
V_9 -> V_16 == V_7 -> V_16 ) &&
( ! V_9 -> V_17 || ! V_7 -> V_17 ||
F_8 ( V_7 -> V_18 ) ||
! F_9 ( V_13 , F_3 ( V_9 ) ) ) &&
F_2 ( V_7 , V_9 , true ) ) {
if ( ! V_5 )
return 1 ;
F_10 ( F_7 ( V_9 ) -> V_14 >> log , V_5 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_3 * V_19 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) )
{
struct V_6 * V_9 ;
struct V_11 * V_12 ;
T_2 V_13 = F_3 ( V_7 ) ;
int V_20 = 0 ;
F_12 ( & V_19 -> V_21 ) ;
F_13 (sk2, node, &hslot2->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( F_7 ( V_9 ) -> V_14 == V_2 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
V_9 -> V_16 == V_7 -> V_16 ) &&
( ! V_9 -> V_17 || ! V_7 -> V_17 ||
F_8 ( V_7 -> V_18 ) ||
! F_9 ( V_13 , F_3 ( V_9 ) ) ) &&
F_2 ( V_7 , V_9 , true ) ) {
V_20 = 1 ;
break;
}
}
F_14 ( & V_19 -> V_21 ) ;
return V_20 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_3 * V_4 ,
int (* F_16)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_11 * V_12 ;
T_2 V_13 = F_3 ( V_7 ) ;
struct V_6 * V_9 ;
F_4 (sk2, node, &hslot->head) {
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
V_9 -> V_22 == V_7 -> V_22 &&
F_17 ( V_9 ) == F_17 ( V_7 ) &&
( F_7 ( V_9 ) -> V_14 == F_7 ( V_7 ) -> V_14 ) &&
( V_9 -> V_16 == V_7 -> V_16 ) &&
V_9 -> V_17 && F_9 ( V_13 , F_3 ( V_9 ) ) &&
(* F_16)( V_7 , V_9 , false ) ) {
return F_18 ( V_7 , V_9 ) ;
}
}
if ( ! F_8 ( V_7 -> V_18 ) )
return F_19 ( V_7 ) ;
return 0 ;
}
int F_20 ( struct V_6 * V_7 , unsigned short V_23 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ,
bool V_10 ) ,
unsigned int V_24 )
{
struct V_3 * V_4 , * V_19 ;
struct V_25 * V_26 = V_7 -> V_27 -> V_28 . V_25 ;
int error = 1 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( ! V_23 ) {
int V_29 , V_30 , V_31 ;
unsigned int rand ;
unsigned short V_32 , V_33 ;
F_21 ( V_5 , V_34 ) ;
F_22 ( V_1 , & V_29 , & V_30 ) ;
V_31 = ( V_30 - V_29 ) + 1 ;
rand = F_23 () ;
V_32 = F_24 ( rand , V_31 ) + V_29 ;
rand = ( rand | 1 ) * ( V_26 -> V_35 + 1 ) ;
V_33 = V_32 + V_26 -> V_35 + 1 ;
do {
V_4 = F_25 ( V_26 , V_1 , V_32 ) ;
F_26 ( V_5 , V_34 ) ;
F_27 ( & V_4 -> V_21 ) ;
F_1 ( V_1 , V_23 , V_4 , V_5 , V_7 ,
F_2 , V_26 -> log ) ;
V_23 = V_32 ;
do {
if ( V_29 <= V_23 && V_23 <= V_30 &&
! F_28 ( V_23 >> V_26 -> log , V_5 ) &&
! F_29 ( V_1 , V_23 ) )
goto V_36;
V_23 += rand ;
} while ( V_23 != V_32 );
F_30 ( & V_4 -> V_21 ) ;
} while ( ++ V_32 != V_33 );
goto V_37;
} else {
V_4 = F_25 ( V_26 , V_1 , V_23 ) ;
F_27 ( & V_4 -> V_21 ) ;
if ( V_4 -> V_38 > 10 ) {
int V_39 ;
unsigned int V_40 = F_7 ( V_7 ) -> V_41 ^ V_23 ;
V_40 &= V_26 -> V_35 ;
V_24 &= V_26 -> V_35 ;
V_19 = F_31 ( V_26 , V_40 ) ;
if ( V_4 -> V_38 < V_19 -> V_38 )
goto V_42;
V_39 = F_11 ( V_1 , V_23 , V_19 ,
V_7 , F_2 ) ;
if ( ! V_39 && ( V_24 != V_40 ) ) {
V_19 = F_31 ( V_26 , V_24 ) ;
V_39 = F_11 ( V_1 , V_23 , V_19 ,
V_7 , F_2 ) ;
}
if ( V_39 )
goto V_43;
else
goto V_36;
}
V_42:
if ( F_1 ( V_1 , V_23 , V_4 , NULL , V_7 ,
F_2 , 0 ) )
goto V_43;
}
V_36:
F_32 ( V_7 ) -> V_44 = V_23 ;
F_7 ( V_7 ) -> V_14 = V_23 ;
F_7 ( V_7 ) -> V_41 ^= V_23 ;
if ( F_33 ( V_7 ) ) {
if ( V_7 -> V_17 &&
F_15 ( V_7 , V_4 , F_2 ) ) {
F_32 ( V_7 ) -> V_44 = 0 ;
F_7 ( V_7 ) -> V_14 = 0 ;
F_7 ( V_7 ) -> V_41 ^= V_23 ;
goto V_43;
}
F_34 ( V_7 , & V_4 -> V_45 ) ;
V_4 -> V_38 ++ ;
F_35 ( F_6 ( V_7 ) , V_7 -> V_27 , 1 ) ;
V_19 = F_31 ( V_26 , F_7 ( V_7 ) -> V_41 ) ;
F_12 ( & V_19 -> V_21 ) ;
F_36 ( & F_7 ( V_7 ) -> V_46 ,
& V_19 -> V_45 ) ;
V_19 -> V_38 ++ ;
F_14 ( & V_19 -> V_21 ) ;
}
error = 0 ;
V_43:
F_30 ( & V_4 -> V_21 ) ;
V_37:
return error ;
}
static int F_37 ( const struct V_6 * V_8 , const struct V_6 * V_9 ,
bool V_10 )
{
struct V_47 * V_48 = F_32 ( V_8 ) , * V_49 = F_32 ( V_9 ) ;
if ( ! F_17 ( V_9 ) ) {
if ( V_48 -> V_50 == V_49 -> V_50 )
return 1 ;
if ( ! V_48 -> V_50 || ! V_49 -> V_50 )
return V_10 ;
}
return 0 ;
}
static T_3 F_38 ( const struct V_1 * V_1 , T_4 V_51 ,
unsigned int V_52 )
{
return F_39 ( ( V_53 T_3 ) V_51 , F_40 ( V_1 ) ) ^ V_52 ;
}
int F_41 ( struct V_6 * V_7 , unsigned short V_23 )
{
unsigned int V_24 =
F_38 ( F_6 ( V_7 ) , F_42 ( V_54 ) , V_23 ) ;
unsigned int V_55 =
F_38 ( F_6 ( V_7 ) , F_32 ( V_7 ) -> V_50 , 0 ) ;
F_7 ( V_7 ) -> V_41 = V_55 ;
return F_20 ( V_7 , V_23 , F_37 , V_24 ) ;
}
static inline int F_43 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_51 , unsigned short V_56 , T_5 V_57 ,
T_4 V_58 , T_5 V_59 , int V_60 )
{
int V_61 ;
struct V_47 * V_62 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_14 != V_56 ||
F_17 ( V_7 ) )
return - 1 ;
V_61 = ( V_7 -> V_22 == V_63 ) ? 2 : 1 ;
V_62 = F_32 ( V_7 ) ;
if ( V_62 -> V_50 ) {
if ( V_62 -> V_50 != V_58 )
return - 1 ;
V_61 += 4 ;
}
if ( V_62 -> V_64 ) {
if ( V_62 -> V_64 != V_51 )
return - 1 ;
V_61 += 4 ;
}
if ( V_62 -> V_65 ) {
if ( V_62 -> V_65 != V_57 )
return - 1 ;
V_61 += 4 ;
}
if ( V_7 -> V_16 ) {
if ( V_7 -> V_16 != V_60 )
return - 1 ;
V_61 += 4 ;
}
if ( V_7 -> V_66 == F_44 () )
V_61 ++ ;
return V_61 ;
}
static inline int F_45 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_51 , T_5 V_57 ,
T_4 V_58 , unsigned int V_56 , int V_60 )
{
int V_61 ;
struct V_47 * V_62 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_17 ( V_7 ) )
return - 1 ;
V_62 = F_32 ( V_7 ) ;
if ( V_62 -> V_50 != V_58 ||
V_62 -> V_44 != V_56 )
return - 1 ;
V_61 = ( V_7 -> V_22 == V_63 ) ? 2 : 1 ;
if ( V_62 -> V_64 ) {
if ( V_62 -> V_64 != V_51 )
return - 1 ;
V_61 += 4 ;
}
if ( V_62 -> V_65 ) {
if ( V_62 -> V_65 != V_57 )
return - 1 ;
V_61 += 4 ;
}
if ( V_7 -> V_16 ) {
if ( V_7 -> V_16 != V_60 )
return - 1 ;
V_61 += 4 ;
}
if ( V_7 -> V_66 == F_44 () )
V_61 ++ ;
return V_61 ;
}
static T_3 F_46 ( const struct V_1 * V_1 , const T_4 V_67 ,
const T_1 V_68 , const T_4 V_69 ,
const T_5 V_70 )
{
static T_3 T_6 V_71 ;
F_47 ( & T_6 , sizeof( T_6 ) ) ;
return F_48 ( V_67 , V_68 , V_69 , V_70 ,
T_6 + F_40 ( V_1 ) ) ;
}
static struct V_6 * F_49 ( struct V_1 * V_1 ,
T_4 V_51 , T_5 V_57 ,
T_4 V_58 , unsigned int V_56 , int V_60 ,
struct V_3 * V_19 , unsigned int V_40 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 , * V_74 ;
struct V_11 * V_12 ;
int V_61 , V_75 , V_76 = 0 , V_77 = 0 ;
bool V_78 = true ;
T_3 V_79 = 0 ;
V_80:
V_74 = NULL ;
V_75 = 0 ;
F_50 (sk, node, &hslot2->head) {
V_61 = F_45 ( V_7 , V_1 , V_51 , V_57 ,
V_58 , V_56 , V_60 ) ;
if ( V_61 > V_75 ) {
V_74 = V_7 ;
V_75 = V_61 ;
V_77 = V_7 -> V_17 ;
if ( V_77 ) {
V_79 = F_46 ( V_1 , V_58 , V_56 ,
V_51 , V_57 ) ;
if ( V_78 ) {
struct V_6 * V_9 ;
V_9 = F_51 ( V_7 , V_79 , V_73 ,
sizeof( struct V_81 ) ) ;
if ( V_9 ) {
V_74 = V_9 ;
V_78 = false ;
goto V_36;
}
}
V_76 = 1 ;
}
} else if ( V_61 == V_75 && V_77 ) {
V_76 ++ ;
if ( F_24 ( V_79 , V_76 ) == 0 )
V_74 = V_7 ;
V_79 = F_52 ( V_79 ) ;
}
}
if ( F_53 ( V_12 ) != V_40 )
goto V_80;
if ( V_74 ) {
V_36:
if ( F_54 ( ! F_55 ( & V_74 -> V_82 , 2 ) ) )
V_74 = NULL ;
else if ( F_54 ( F_45 ( V_74 , V_1 , V_51 , V_57 ,
V_58 , V_56 , V_60 ) < V_75 ) ) {
F_56 ( V_74 ) ;
goto V_80;
}
}
return V_74 ;
}
struct V_6 * F_57 ( struct V_1 * V_1 , T_4 V_51 ,
T_5 V_57 , T_4 V_58 , T_5 V_59 ,
int V_60 , struct V_25 * V_26 , struct V_72 * V_73 )
{
struct V_6 * V_7 , * V_74 ;
struct V_11 * V_12 ;
unsigned short V_56 = F_58 ( V_59 ) ;
unsigned int V_83 , V_40 , V_84 = F_59 ( V_1 , V_56 , V_26 -> V_35 ) ;
struct V_3 * V_19 , * V_4 = & V_26 -> V_79 [ V_84 ] ;
int V_61 , V_75 , V_76 = 0 , V_77 = 0 ;
bool V_78 = true ;
T_3 V_79 = 0 ;
F_60 () ;
if ( V_4 -> V_38 > 10 ) {
V_83 = F_38 ( V_1 , V_58 , V_56 ) ;
V_40 = V_83 & V_26 -> V_35 ;
V_19 = & V_26 -> V_83 [ V_40 ] ;
if ( V_4 -> V_38 < V_19 -> V_38 )
goto V_80;
V_74 = F_49 ( V_1 , V_51 , V_57 ,
V_58 , V_56 , V_60 ,
V_19 , V_40 , V_73 ) ;
if ( ! V_74 ) {
V_83 = F_38 ( V_1 , F_42 ( V_54 ) , V_56 ) ;
V_40 = V_83 & V_26 -> V_35 ;
V_19 = & V_26 -> V_83 [ V_40 ] ;
if ( V_4 -> V_38 < V_19 -> V_38 )
goto V_80;
V_74 = F_49 ( V_1 , V_51 , V_57 ,
F_42 ( V_54 ) , V_56 , V_60 ,
V_19 , V_40 , V_73 ) ;
}
F_61 () ;
return V_74 ;
}
V_80:
V_74 = NULL ;
V_75 = 0 ;
F_62 (sk, node, &hslot->head) {
V_61 = F_43 ( V_7 , V_1 , V_51 , V_56 , V_57 ,
V_58 , V_59 , V_60 ) ;
if ( V_61 > V_75 ) {
V_74 = V_7 ;
V_75 = V_61 ;
V_77 = V_7 -> V_17 ;
if ( V_77 ) {
V_79 = F_46 ( V_1 , V_58 , V_56 ,
V_51 , V_57 ) ;
if ( V_78 ) {
struct V_6 * V_9 ;
V_9 = F_51 ( V_7 , V_79 , V_73 ,
sizeof( struct V_81 ) ) ;
if ( V_9 ) {
V_74 = V_9 ;
V_78 = false ;
goto V_36;
}
}
V_76 = 1 ;
}
} else if ( V_61 == V_75 && V_77 ) {
V_76 ++ ;
if ( F_24 ( V_79 , V_76 ) == 0 )
V_74 = V_7 ;
V_79 = F_52 ( V_79 ) ;
}
}
if ( F_53 ( V_12 ) != V_84 )
goto V_80;
if ( V_74 ) {
V_36:
if ( F_54 ( ! F_55 ( & V_74 -> V_82 , 2 ) ) )
V_74 = NULL ;
else if ( F_54 ( F_43 ( V_74 , V_1 , V_51 , V_56 , V_57 ,
V_58 , V_59 , V_60 ) < V_75 ) ) {
F_56 ( V_74 ) ;
goto V_80;
}
}
F_61 () ;
return V_74 ;
}
static inline struct V_6 * F_63 ( struct V_72 * V_73 ,
T_5 V_57 , T_5 V_59 ,
struct V_25 * V_26 )
{
const struct V_85 * V_86 = F_64 ( V_73 ) ;
return F_57 ( F_65 ( F_66 ( V_73 ) -> V_87 ) , V_86 -> V_51 , V_57 ,
V_86 -> V_58 , V_59 , F_67 ( V_73 ) ,
V_26 , V_73 ) ;
}
struct V_6 * F_68 ( struct V_1 * V_1 , T_4 V_51 , T_5 V_57 ,
T_4 V_58 , T_5 V_59 , int V_60 )
{
return F_57 ( V_1 , V_51 , V_57 , V_58 , V_59 , V_60 ,
& V_25 , NULL ) ;
}
static inline bool F_69 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_5 V_88 , T_4 V_89 ,
T_5 V_90 , T_4 V_91 ,
int V_60 , unsigned short V_56 )
{
struct V_47 * V_62 = F_32 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_14 != V_56 ||
( V_62 -> V_64 && V_62 -> V_64 != V_91 ) ||
( V_62 -> V_65 != V_90 && V_62 -> V_65 ) ||
( V_62 -> V_50 && V_62 -> V_50 != V_89 ) ||
F_17 ( V_7 ) ||
( V_7 -> V_16 && V_7 -> V_16 != V_60 ) )
return false ;
if ( ! F_70 ( V_7 , V_89 , V_91 , V_60 ) )
return false ;
return true ;
}
void F_71 ( struct V_72 * V_73 , T_3 V_92 , struct V_25 * V_26 )
{
struct V_47 * V_62 ;
const struct V_85 * V_86 = ( const struct V_85 * ) V_73 -> V_93 ;
struct V_81 * V_94 = (struct V_81 * ) ( V_73 -> V_93 + ( V_86 -> V_95 << 2 ) ) ;
const int type = F_72 ( V_73 ) -> type ;
const int V_96 = F_72 ( V_73 ) -> V_96 ;
struct V_6 * V_7 ;
int V_97 ;
int V_98 ;
struct V_1 * V_1 = F_65 ( V_73 -> V_87 ) ;
V_7 = F_57 ( V_1 , V_86 -> V_58 , V_94 -> V_99 ,
V_86 -> V_51 , V_94 -> V_100 , V_73 -> V_87 -> V_101 , V_26 ,
NULL ) ;
if ( ! V_7 ) {
F_73 ( V_1 , V_102 ) ;
return;
}
V_98 = 0 ;
V_97 = 0 ;
V_62 = F_32 ( V_7 ) ;
switch ( type ) {
default:
case V_103 :
V_98 = V_104 ;
break;
case V_105 :
goto V_106;
case V_107 :
V_98 = V_108 ;
V_97 = 1 ;
break;
case V_109 :
if ( V_96 == V_110 ) {
F_74 ( V_73 , V_7 , V_92 ) ;
if ( V_62 -> V_111 != V_112 ) {
V_98 = V_113 ;
V_97 = 1 ;
break;
}
goto V_106;
}
V_98 = V_104 ;
if ( V_96 <= V_114 ) {
V_97 = V_115 [ V_96 ] . V_116 ;
V_98 = V_115 [ V_96 ] . V_117 ;
}
break;
case V_118 :
F_75 ( V_73 , V_7 ) ;
goto V_106;
}
if ( ! V_62 -> V_119 ) {
if ( ! V_97 || V_7 -> V_120 != V_121 )
goto V_106;
} else
F_76 ( V_7 , V_73 , V_98 , V_94 -> V_99 , V_92 , ( V_122 * ) ( V_94 + 1 ) ) ;
V_7 -> V_123 = V_98 ;
V_7 -> V_124 ( V_7 ) ;
V_106:
F_56 ( V_7 ) ;
}
void F_77 ( struct V_72 * V_73 , T_3 V_92 )
{
F_71 ( V_73 , V_92 , & V_25 ) ;
}
void F_78 ( struct V_6 * V_7 )
{
struct V_125 * V_126 = F_7 ( V_7 ) ;
if ( V_126 -> V_127 ) {
V_126 -> V_128 = 0 ;
V_126 -> V_127 = 0 ;
F_79 ( V_7 ) ;
}
}
void F_80 ( struct V_72 * V_73 , T_4 V_129 , T_4 V_130 )
{
struct V_81 * V_94 = F_81 ( V_73 ) ;
int V_131 = F_82 ( V_73 ) ;
int V_128 = V_73 -> V_128 - V_131 ;
int V_132 = V_128 ;
T_7 V_133 = 0 ;
if ( ! F_83 ( V_73 ) ) {
V_73 -> V_134 = F_84 ( V_73 ) - V_73 -> V_45 ;
V_73 -> V_135 = F_85 ( struct V_81 , V_136 ) ;
V_94 -> V_136 = ~ F_86 ( V_129 , V_130 , V_128 ,
V_137 , 0 ) ;
} else {
struct V_72 * V_138 ;
F_87 (skb, frags) {
V_133 = F_88 ( V_133 , V_138 -> V_133 ) ;
V_132 -= V_138 -> V_128 ;
}
V_133 = F_89 ( V_73 , V_131 , V_132 , V_133 ) ;
V_73 -> V_139 = V_140 ;
V_94 -> V_136 = F_86 ( V_129 , V_130 , V_128 , V_137 , V_133 ) ;
if ( V_94 -> V_136 == 0 )
V_94 -> V_136 = V_141 ;
}
}
void F_90 ( bool V_142 , struct V_72 * V_73 ,
T_4 V_51 , T_4 V_58 , int V_128 )
{
struct V_81 * V_94 = F_81 ( V_73 ) ;
if ( V_142 )
V_94 -> V_136 = 0 ;
else if ( F_91 ( V_73 ) )
V_94 -> V_136 = ~ F_92 ( V_128 , V_51 , V_58 , 0 ) ;
else if ( F_66 ( V_73 ) && F_66 ( V_73 ) -> V_87 &&
( F_66 ( V_73 ) -> V_87 -> V_143 &
( V_144 | V_145 ) ) ) {
F_93 ( V_73 -> V_139 == V_146 ) ;
V_73 -> V_139 = V_146 ;
V_73 -> V_134 = F_84 ( V_73 ) - V_73 -> V_45 ;
V_73 -> V_135 = F_85 ( struct V_81 , V_136 ) ;
V_94 -> V_136 = ~ F_92 ( V_128 , V_51 , V_58 , 0 ) ;
} else {
T_7 V_133 ;
F_93 ( V_73 -> V_139 == V_146 ) ;
V_94 -> V_136 = 0 ;
V_133 = F_89 ( V_73 , 0 , V_128 , 0 ) ;
V_94 -> V_136 = F_92 ( V_128 , V_51 , V_58 , V_133 ) ;
if ( V_94 -> V_136 == 0 )
V_94 -> V_136 = V_141 ;
V_73 -> V_139 = V_147 ;
}
}
static int F_94 ( struct V_72 * V_73 , struct V_148 * V_149 )
{
struct V_6 * V_7 = V_73 -> V_7 ;
struct V_47 * V_62 = F_32 ( V_7 ) ;
struct V_81 * V_94 ;
int V_98 = 0 ;
int V_150 = F_95 ( V_7 ) ;
int V_131 = F_82 ( V_73 ) ;
int V_128 = V_73 -> V_128 - V_131 ;
T_7 V_133 = 0 ;
V_94 = F_81 ( V_73 ) ;
V_94 -> V_100 = V_62 -> V_151 ;
V_94 -> V_99 = V_149 -> V_152 ;
V_94 -> V_128 = F_96 ( V_128 ) ;
V_94 -> V_136 = 0 ;
if ( V_150 )
V_133 = F_97 ( V_73 ) ;
else if ( V_7 -> V_153 ) {
V_73 -> V_139 = V_140 ;
goto V_154;
} else if ( V_73 -> V_139 == V_146 ) {
F_80 ( V_73 , V_149 -> V_51 , V_149 -> V_58 ) ;
goto V_154;
} else
V_133 = F_98 ( V_73 ) ;
V_94 -> V_136 = F_86 ( V_149 -> V_51 , V_149 -> V_58 , V_128 ,
V_7 -> V_155 , V_133 ) ;
if ( V_94 -> V_136 == 0 )
V_94 -> V_136 = V_141 ;
V_154:
V_98 = F_99 ( F_6 ( V_7 ) , V_73 ) ;
if ( V_98 ) {
if ( V_98 == - V_156 && ! V_62 -> V_119 ) {
F_100 ( F_6 ( V_7 ) ,
V_157 , V_150 ) ;
V_98 = 0 ;
}
} else
F_100 ( F_6 ( V_7 ) ,
V_158 , V_150 ) ;
return V_98 ;
}
int F_101 ( struct V_6 * V_7 )
{
struct V_125 * V_126 = F_7 ( V_7 ) ;
struct V_47 * V_62 = F_32 ( V_7 ) ;
struct V_148 * V_149 = & V_62 -> V_159 . V_160 . V_161 . V_162 ;
struct V_72 * V_73 ;
int V_98 = 0 ;
V_73 = F_102 ( V_7 , V_149 ) ;
if ( ! V_73 )
goto V_106;
V_98 = F_94 ( V_73 , V_149 ) ;
V_106:
V_126 -> V_128 = 0 ;
V_126 -> V_127 = 0 ;
return V_98 ;
}
int F_103 ( struct V_6 * V_7 , struct V_163 * V_164 , T_8 V_128 )
{
struct V_47 * V_62 = F_32 ( V_7 ) ;
struct V_125 * V_126 = F_7 ( V_7 ) ;
struct V_148 V_165 ;
struct V_148 * V_149 ;
int V_166 = V_128 ;
struct V_167 V_168 ;
struct V_169 * V_170 = NULL ;
int free = 0 ;
int V_171 = 0 ;
T_4 V_58 , V_69 , V_51 ;
T_5 V_59 ;
V_122 V_172 ;
int V_98 , V_150 = F_95 ( V_7 ) ;
int V_173 = V_126 -> V_174 || V_164 -> V_175 & V_176 ;
int (* F_104)( void * , char * , int , int , int , struct V_72 * );
struct V_72 * V_73 ;
struct V_177 V_178 ;
if ( V_128 > 0xFFFF )
return - V_113 ;
if ( V_164 -> V_175 & V_179 )
return - V_180 ;
V_168 . V_181 = NULL ;
V_168 . V_182 = 0 ;
V_168 . V_183 = 0 ;
V_168 . V_172 = - 1 ;
F_104 = V_150 ? V_184 : V_185 ;
V_149 = & V_62 -> V_159 . V_160 . V_161 . V_162 ;
if ( V_126 -> V_127 ) {
F_105 ( V_7 ) ;
if ( F_106 ( V_126 -> V_127 ) ) {
if ( F_54 ( V_126 -> V_127 != V_186 ) ) {
F_107 ( V_7 ) ;
return - V_187 ;
}
goto V_188;
}
F_107 ( V_7 ) ;
}
V_166 += sizeof( struct V_81 ) ;
if ( V_164 -> V_189 ) {
F_108 ( struct V_190 * , V_191 , V_164 -> V_189 ) ;
if ( V_164 -> V_192 < sizeof( * V_191 ) )
return - V_187 ;
if ( V_191 -> V_193 != V_186 ) {
if ( V_191 -> V_193 != V_194 )
return - V_195 ;
}
V_58 = V_191 -> V_196 . V_197 ;
V_59 = V_191 -> V_198 ;
if ( V_59 == 0 )
return - V_187 ;
} else {
if ( V_7 -> V_120 != V_121 )
return - V_199 ;
V_58 = V_62 -> V_64 ;
V_59 = V_62 -> V_65 ;
V_171 = 1 ;
}
V_168 . V_200 = V_62 -> V_201 ;
V_168 . V_202 = V_7 -> V_16 ;
F_109 ( V_7 , & V_168 . V_182 ) ;
if ( V_164 -> V_203 ) {
V_98 = F_110 ( F_6 ( V_7 ) , V_164 , & V_168 ,
V_7 -> V_22 == V_204 ) ;
if ( F_54 ( V_98 ) ) {
F_111 ( V_168 . V_181 ) ;
return V_98 ;
}
if ( V_168 . V_181 )
free = 1 ;
V_171 = 0 ;
}
if ( ! V_168 . V_181 ) {
struct V_205 * V_206 ;
F_60 () ;
V_206 = F_112 ( V_62 -> V_206 ) ;
if ( V_206 ) {
memcpy ( & V_178 , V_206 ,
sizeof( * V_206 ) + V_206 -> V_181 . V_207 ) ;
V_168 . V_181 = & V_178 . V_181 ;
}
F_61 () ;
}
V_51 = V_168 . V_200 ;
V_168 . V_200 = V_69 = V_58 ;
if ( V_168 . V_181 && V_168 . V_181 -> V_181 . V_208 ) {
if ( ! V_58 )
return - V_187 ;
V_69 = V_168 . V_181 -> V_181 . V_69 ;
V_171 = 0 ;
}
V_172 = F_113 ( & V_168 , V_62 ) ;
if ( F_114 ( V_7 , V_209 ) ||
( V_164 -> V_175 & V_210 ) ||
( V_168 . V_181 && V_168 . V_181 -> V_181 . V_211 ) ) {
V_172 |= V_212 ;
V_171 = 0 ;
}
if ( F_115 ( V_58 ) ) {
if ( ! V_168 . V_202 )
V_168 . V_202 = V_62 -> V_213 ;
if ( ! V_51 )
V_51 = V_62 -> V_214 ;
V_171 = 0 ;
} else if ( ! V_168 . V_202 )
V_168 . V_202 = V_62 -> V_215 ;
if ( V_171 )
V_170 = (struct V_169 * ) F_116 ( V_7 , 0 ) ;
if ( ! V_170 ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
T_9 V_216 = F_117 ( V_7 ) ;
V_149 = & V_165 ;
F_118 ( V_149 , V_168 . V_202 , V_7 -> V_217 , V_172 ,
V_218 , V_7 -> V_155 ,
V_216 ,
V_69 , V_51 , V_59 , V_62 -> V_151 ) ;
if ( ! V_51 && V_168 . V_202 ) {
V_98 = F_119 ( V_1 , V_168 . V_202 , V_149 ) ;
if ( V_98 < 0 )
goto V_106;
}
F_120 ( V_7 , F_121 ( V_149 ) ) ;
V_170 = F_122 ( V_1 , V_149 , V_7 ) ;
if ( F_123 ( V_170 ) ) {
V_98 = F_124 ( V_170 ) ;
V_170 = NULL ;
if ( V_98 == - V_219 )
F_125 ( V_1 , V_220 ) ;
goto V_106;
}
V_98 = - V_221 ;
if ( ( V_170 -> V_222 & V_223 ) &&
! F_114 ( V_7 , V_224 ) )
goto V_106;
if ( V_171 )
F_126 ( V_7 , F_127 ( & V_170 -> V_130 ) ) ;
}
if ( V_164 -> V_175 & V_225 )
goto V_226;
V_227:
V_51 = V_149 -> V_51 ;
if ( ! V_168 . V_200 )
V_58 = V_168 . V_200 = V_149 -> V_58 ;
if ( ! V_173 ) {
V_73 = F_128 ( V_7 , V_149 , F_104 , V_164 , V_166 ,
sizeof( struct V_81 ) , & V_168 , & V_170 ,
V_164 -> V_175 ) ;
V_98 = F_124 ( V_73 ) ;
if ( ! F_129 ( V_73 ) )
V_98 = F_94 ( V_73 , V_149 ) ;
goto V_106;
}
F_105 ( V_7 ) ;
if ( F_54 ( V_126 -> V_127 ) ) {
F_107 ( V_7 ) ;
F_130 ( L_1 ) ;
V_98 = - V_187 ;
goto V_106;
}
V_149 = & V_62 -> V_159 . V_160 . V_161 . V_162 ;
V_149 -> V_58 = V_58 ;
V_149 -> V_51 = V_51 ;
V_149 -> V_152 = V_59 ;
V_149 -> V_228 = V_62 -> V_151 ;
V_126 -> V_127 = V_186 ;
V_188:
V_126 -> V_128 += V_166 ;
V_98 = F_131 ( V_7 , V_149 , F_104 , V_164 , V_166 ,
sizeof( struct V_81 ) , & V_168 , & V_170 ,
V_173 ? V_164 -> V_175 | V_176 : V_164 -> V_175 ) ;
if ( V_98 )
F_78 ( V_7 ) ;
else if ( ! V_173 )
V_98 = F_101 ( V_7 ) ;
else if ( F_54 ( F_132 ( & V_7 -> V_229 ) ) )
V_126 -> V_127 = 0 ;
F_107 ( V_7 ) ;
V_106:
F_133 ( V_170 ) ;
if ( free )
F_111 ( V_168 . V_181 ) ;
if ( ! V_98 )
return V_128 ;
if ( V_98 == - V_156 || F_28 ( V_230 , & V_7 -> V_231 -> V_232 ) ) {
F_100 ( F_6 ( V_7 ) ,
V_157 , V_150 ) ;
}
return V_98 ;
V_226:
F_134 ( & V_170 -> V_130 ) ;
if ( ! ( V_164 -> V_175 & V_233 ) || V_128 )
goto V_227;
V_98 = 0 ;
goto V_106;
}
int F_135 ( struct V_6 * V_7 , struct V_234 * V_234 , int V_131 ,
T_8 V_235 , int V_232 )
{
struct V_47 * V_62 = F_32 ( V_7 ) ;
struct V_125 * V_126 = F_7 ( V_7 ) ;
int V_236 ;
if ( V_232 & V_237 )
V_232 |= V_176 ;
if ( ! V_126 -> V_127 ) {
struct V_163 V_164 = { . V_175 = V_232 | V_176 } ;
V_236 = F_103 ( V_7 , & V_164 , 0 ) ;
if ( V_236 < 0 )
return V_236 ;
}
F_105 ( V_7 ) ;
if ( F_54 ( ! V_126 -> V_127 ) ) {
F_107 ( V_7 ) ;
F_130 ( L_2 ) ;
return - V_187 ;
}
V_236 = F_136 ( V_7 , & V_62 -> V_159 . V_160 . V_161 . V_162 ,
V_234 , V_131 , V_235 , V_232 ) ;
if ( V_236 == - V_180 ) {
F_107 ( V_7 ) ;
return F_137 ( V_7 -> V_231 , V_234 , V_131 ,
V_235 , V_232 ) ;
}
if ( V_236 < 0 ) {
F_78 ( V_7 ) ;
goto V_106;
}
V_126 -> V_128 += V_235 ;
if ( ! ( V_126 -> V_174 || ( V_232 & V_176 ) ) )
V_236 = F_101 ( V_7 ) ;
if ( ! V_236 )
V_236 = V_235 ;
V_106:
F_107 ( V_7 ) ;
return V_236 ;
}
static unsigned int F_138 ( struct V_6 * V_7 )
{
struct V_238 V_239 , * V_240 = & V_7 -> V_241 ;
struct V_72 * V_73 ;
unsigned int V_20 ;
F_139 ( & V_239 ) ;
F_27 ( & V_240 -> V_21 ) ;
while ( ( V_73 = F_140 ( V_240 ) ) != NULL &&
F_141 ( V_73 ) ) {
F_142 ( F_6 ( V_7 ) , V_242 ,
F_95 ( V_7 ) ) ;
F_142 ( F_6 ( V_7 ) , V_243 ,
F_95 ( V_7 ) ) ;
F_143 ( & V_7 -> V_244 ) ;
F_144 ( V_73 , V_240 ) ;
F_145 ( & V_239 , V_73 ) ;
}
V_20 = V_73 ? V_73 -> V_128 : 0 ;
F_30 ( & V_240 -> V_21 ) ;
if ( ! F_132 ( & V_239 ) ) {
bool V_245 = F_146 ( V_7 ) ;
F_147 ( & V_239 ) ;
F_148 ( V_7 ) ;
F_149 ( V_7 , V_245 ) ;
}
return V_20 ;
}
int F_150 ( struct V_6 * V_7 , int V_246 , unsigned long V_247 )
{
switch ( V_246 ) {
case V_248 :
{
int V_249 = F_151 ( V_7 ) ;
return F_152 ( V_249 , ( int V_250 * ) V_247 ) ;
}
case V_251 :
{
unsigned int V_249 = F_138 ( V_7 ) ;
if ( V_249 )
V_249 -= sizeof( struct V_81 ) ;
return F_152 ( V_249 , ( int V_250 * ) V_247 ) ;
}
default:
return - V_252 ;
}
return 0 ;
}
int F_153 ( struct V_6 * V_7 , struct V_163 * V_164 , T_8 V_128 , int V_253 ,
int V_232 , int * V_254 )
{
struct V_47 * V_62 = F_32 ( V_7 ) ;
F_108 ( struct V_190 * , sin , V_164 -> V_189 ) ;
struct V_72 * V_73 ;
unsigned int V_166 , V_255 ;
int V_256 , V_257 = 0 ;
int V_98 ;
int V_150 = F_95 ( V_7 ) ;
bool V_258 = false ;
bool V_245 ;
if ( V_232 & V_259 )
return F_154 ( V_7 , V_164 , V_128 , V_254 ) ;
V_260:
V_73 = F_155 ( V_7 , V_232 | ( V_253 ? V_261 : 0 ) ,
& V_256 , & V_257 , & V_98 ) ;
if ( ! V_73 )
goto V_106;
V_166 = V_73 -> V_128 - sizeof( struct V_81 ) ;
V_255 = V_128 ;
if ( V_255 > V_166 )
V_255 = V_166 ;
else if ( V_255 < V_166 )
V_164 -> V_175 |= V_262 ;
if ( V_255 < V_166 || F_156 ( V_73 ) -> V_263 ) {
V_258 = ! F_141 ( V_73 ) ;
if ( ! V_258 )
goto V_264;
}
if ( V_258 || F_157 ( V_73 ) )
V_98 = F_158 ( V_73 , sizeof( struct V_81 ) ,
V_164 , V_255 ) ;
else {
V_98 = F_159 ( V_73 , sizeof( struct V_81 ) ,
V_164 ) ;
if ( V_98 == - V_187 )
goto V_264;
}
if ( F_54 ( V_98 ) ) {
F_160 ( V_73 , F_153 ) ;
if ( ! V_256 ) {
F_143 ( & V_7 -> V_244 ) ;
F_100 ( F_6 ( V_7 ) ,
V_243 , V_150 ) ;
}
goto V_265;
}
if ( ! V_256 )
F_100 ( F_6 ( V_7 ) ,
V_266 , V_150 ) ;
F_161 ( V_164 , V_7 , V_73 ) ;
if ( sin ) {
sin -> V_193 = V_186 ;
sin -> V_198 = F_81 ( V_73 ) -> V_100 ;
sin -> V_196 . V_197 = F_64 ( V_73 ) -> V_51 ;
memset ( sin -> V_267 , 0 , sizeof( sin -> V_267 ) ) ;
* V_254 = sizeof( * sin ) ;
}
if ( V_62 -> V_268 )
F_162 ( V_164 , V_73 , sizeof( struct V_81 ) ) ;
V_98 = V_255 ;
if ( V_232 & V_262 )
V_98 = V_166 ;
V_265:
F_163 ( V_7 , V_73 ) ;
V_106:
return V_98 ;
V_264:
V_245 = F_146 ( V_7 ) ;
if ( ! F_164 ( V_7 , V_73 , V_232 ) ) {
F_100 ( F_6 ( V_7 ) , V_242 , V_150 ) ;
F_100 ( F_6 ( V_7 ) , V_243 , V_150 ) ;
}
F_149 ( V_7 , V_245 ) ;
F_165 () ;
V_164 -> V_175 &= ~ V_262 ;
goto V_260;
}
int F_166 ( struct V_6 * V_7 , int V_232 )
{
struct V_47 * V_62 = F_32 ( V_7 ) ;
V_7 -> V_120 = V_269 ;
V_62 -> V_64 = 0 ;
V_62 -> V_65 = 0 ;
F_167 ( V_7 ) ;
V_7 -> V_16 = 0 ;
if ( ! ( V_7 -> V_270 & V_271 ) )
F_168 ( V_7 ) ;
if ( ! ( V_7 -> V_270 & V_272 ) ) {
V_7 -> V_27 -> V_273 ( V_7 ) ;
V_62 -> V_151 = 0 ;
}
F_169 ( V_7 ) ;
return 0 ;
}
void F_170 ( struct V_6 * V_7 )
{
if ( F_171 ( V_7 ) ) {
struct V_25 * V_26 = V_7 -> V_27 -> V_28 . V_25 ;
struct V_3 * V_4 , * V_19 ;
V_4 = F_25 ( V_26 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_14 ) ;
V_19 = F_31 ( V_26 , F_7 ( V_7 ) -> V_41 ) ;
F_27 ( & V_4 -> V_21 ) ;
if ( F_8 ( V_7 -> V_18 ) )
F_172 ( V_7 ) ;
if ( F_173 ( V_7 ) ) {
V_4 -> V_38 -- ;
F_32 ( V_7 ) -> V_44 = 0 ;
F_35 ( F_6 ( V_7 ) , V_7 -> V_27 , - 1 ) ;
F_12 ( & V_19 -> V_21 ) ;
F_174 ( & F_7 ( V_7 ) -> V_46 ) ;
V_19 -> V_38 -- ;
F_14 ( & V_19 -> V_21 ) ;
}
F_30 ( & V_4 -> V_21 ) ;
}
}
void F_175 ( struct V_6 * V_7 , T_10 V_274 )
{
if ( F_171 ( V_7 ) ) {
struct V_25 * V_26 = V_7 -> V_27 -> V_28 . V_25 ;
struct V_3 * V_4 , * V_19 , * V_275 ;
V_19 = F_31 ( V_26 , F_7 ( V_7 ) -> V_41 ) ;
V_275 = F_31 ( V_26 , V_274 ) ;
F_7 ( V_7 ) -> V_41 = V_274 ;
if ( V_19 != V_275 ||
F_8 ( V_7 -> V_18 ) ) {
V_4 = F_25 ( V_26 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_14 ) ;
F_27 ( & V_4 -> V_21 ) ;
if ( F_8 ( V_7 -> V_18 ) )
F_172 ( V_7 ) ;
if ( V_19 != V_275 ) {
F_12 ( & V_19 -> V_21 ) ;
F_174 ( & F_7 ( V_7 ) -> V_46 ) ;
V_19 -> V_38 -- ;
F_14 ( & V_19 -> V_21 ) ;
F_12 ( & V_275 -> V_21 ) ;
F_36 ( & F_7 ( V_7 ) -> V_46 ,
& V_275 -> V_45 ) ;
V_275 -> V_38 ++ ;
F_14 ( & V_275 -> V_21 ) ;
}
F_30 ( & V_4 -> V_21 ) ;
}
}
}
static void F_176 ( struct V_6 * V_7 )
{
T_10 V_276 = F_38 ( F_6 ( V_7 ) ,
F_32 ( V_7 ) -> V_50 ,
F_32 ( V_7 ) -> V_44 ) ;
F_175 ( V_7 , V_276 ) ;
}
static int F_177 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
int V_277 ;
if ( F_32 ( V_7 ) -> V_64 ) {
F_178 ( V_7 , V_73 ) ;
F_179 ( V_7 , V_73 ) ;
F_180 ( V_7 ) ;
}
V_277 = F_181 ( V_7 , V_73 ) ;
if ( V_277 < 0 ) {
int V_150 = F_95 ( V_7 ) ;
if ( V_277 == - V_278 )
F_142 ( F_6 ( V_7 ) , V_279 ,
V_150 ) ;
F_142 ( F_6 ( V_7 ) , V_243 , V_150 ) ;
F_182 ( V_73 ) ;
F_183 ( V_277 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_184 ( void )
{
if ( ! F_185 ( & V_280 ) )
F_186 ( & V_280 ) ;
}
int F_187 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
struct V_125 * V_126 = F_7 ( V_7 ) ;
int V_277 ;
int V_150 = F_95 ( V_7 ) ;
if ( ! F_188 ( V_7 , V_281 , V_73 ) )
goto V_282;
F_189 ( V_73 ) ;
if ( F_190 ( & V_280 ) && V_126 -> V_283 ) {
int (* F_191)( struct V_6 * V_7 , struct V_72 * V_73 );
F_191 = F_192 ( V_126 -> F_191 ) ;
if ( V_73 -> V_128 > sizeof( struct V_81 ) && F_191 ) {
int V_236 ;
if ( F_141 ( V_73 ) )
goto V_284;
V_236 = F_191 ( V_7 , V_73 ) ;
if ( V_236 <= 0 ) {
F_142 ( F_6 ( V_7 ) ,
V_266 ,
V_150 ) ;
return - V_236 ;
}
}
}
if ( ( V_150 & V_285 ) && F_156 ( V_73 ) -> V_263 ) {
if ( V_126 -> V_286 == 0 ) {
F_130 ( L_3 ,
F_156 ( V_73 ) -> V_287 , V_73 -> V_128 ) ;
goto V_282;
}
if ( F_156 ( V_73 ) -> V_287 < V_126 -> V_286 ) {
F_130 ( L_4 ,
F_156 ( V_73 ) -> V_287 , V_126 -> V_286 ) ;
goto V_282;
}
}
if ( F_8 ( V_7 -> V_288 ) &&
F_141 ( V_73 ) )
goto V_284;
if ( F_193 ( V_7 , V_7 -> V_289 ) ) {
F_142 ( F_6 ( V_7 ) , V_279 ,
V_150 ) ;
goto V_282;
}
V_277 = 0 ;
F_194 ( V_7 , V_73 ) ;
F_195 ( V_7 ) ;
if ( ! F_196 ( V_7 ) )
V_277 = F_177 ( V_7 , V_73 ) ;
else if ( F_197 ( V_7 , V_73 , V_7 -> V_289 ) ) {
F_198 ( V_7 ) ;
goto V_282;
}
F_198 ( V_7 ) ;
return V_277 ;
V_284:
F_142 ( F_6 ( V_7 ) , V_242 , V_150 ) ;
V_282:
F_142 ( F_6 ( V_7 ) , V_243 , V_150 ) ;
F_143 ( & V_7 -> V_244 ) ;
F_182 ( V_73 ) ;
return - 1 ;
}
static void F_199 ( struct V_6 * * V_290 , unsigned int V_38 ,
struct V_72 * V_73 , unsigned int V_291 )
{
unsigned int V_292 ;
struct V_72 * V_293 = NULL ;
struct V_6 * V_7 ;
for ( V_292 = 0 ; V_292 < V_38 ; V_292 ++ ) {
V_7 = V_290 [ V_292 ] ;
if ( F_106 ( ! V_293 ) )
V_293 = ( V_292 == V_291 ) ? V_73 : F_200 ( V_73 , V_294 ) ;
if ( ! V_293 ) {
F_143 ( & V_7 -> V_244 ) ;
F_142 ( F_6 ( V_7 ) , V_279 ,
F_95 ( V_7 ) ) ;
F_142 ( F_6 ( V_7 ) , V_243 ,
F_95 ( V_7 ) ) ;
}
if ( V_293 && F_187 ( V_7 , V_293 ) <= 0 )
V_293 = NULL ;
F_56 ( V_7 ) ;
}
if ( F_54 ( V_293 ) )
F_182 ( V_293 ) ;
}
static void F_201 ( struct V_6 * V_7 , struct V_295 * V_130 )
{
struct V_295 * V_296 ;
F_202 ( V_130 ) ;
V_296 = F_203 ( & V_7 -> V_297 , V_130 ) ;
F_204 ( V_296 ) ;
}
static int F_205 ( struct V_1 * V_1 , struct V_72 * V_73 ,
struct V_81 * V_94 ,
T_4 V_51 , T_4 V_58 ,
struct V_25 * V_26 ,
int V_298 )
{
struct V_6 * V_7 , * V_290 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_11 * V_12 ;
unsigned short V_56 = F_58 ( V_94 -> V_99 ) ;
struct V_3 * V_4 = F_25 ( V_26 , V_1 , V_56 ) ;
int V_60 = V_73 -> V_87 -> V_101 ;
unsigned int V_38 = 0 , V_131 = F_85 ( F_206 ( * V_7 ) , V_299 ) ;
unsigned int V_83 = 0 , V_300 = 0 , V_301 = ( V_4 -> V_38 > 10 ) ;
bool V_302 = false ;
if ( V_301 ) {
V_300 = F_38 ( V_1 , F_42 ( V_54 ) , V_56 ) &
V_25 . V_35 ;
V_83 = F_38 ( V_1 , V_58 , V_56 ) & V_25 . V_35 ;
V_303:
V_4 = & V_25 . V_83 [ V_83 ] ;
V_131 = F_85 ( F_206 ( * V_7 ) , V_304 . V_305 ) ;
}
F_12 ( & V_4 -> V_21 ) ;
F_207 (sk, node, &hslot->head, offset) {
if ( F_69 ( V_1 , V_7 ,
V_94 -> V_99 , V_58 ,
V_94 -> V_100 , V_51 ,
V_60 , V_56 ) ) {
if ( F_54 ( V_38 == F_208 ( V_290 ) ) ) {
F_199 ( V_290 , V_38 , V_73 , ~ 0 ) ;
V_302 = true ;
V_38 = 0 ;
}
V_290 [ V_38 ++ ] = V_7 ;
F_209 ( V_7 ) ;
}
}
F_14 ( & V_4 -> V_21 ) ;
if ( V_301 && V_83 != V_300 ) {
V_83 = V_300 ;
goto V_303;
}
if ( V_38 ) {
F_199 ( V_290 , V_38 , V_73 , V_38 - 1 ) ;
} else {
if ( ! V_302 )
F_142 ( V_1 , V_306 ,
V_298 == V_307 ) ;
F_210 ( V_73 ) ;
}
return 0 ;
}
static inline int F_211 ( struct V_72 * V_73 , struct V_81 * V_94 ,
int V_298 )
{
int V_98 ;
F_156 ( V_73 ) -> V_263 = 0 ;
F_156 ( V_73 ) -> V_287 = V_73 -> V_128 ;
if ( V_298 == V_307 ) {
V_98 = F_212 ( V_73 , V_94 ) ;
if ( V_98 )
return V_98 ;
}
return F_213 ( V_73 , V_298 , V_94 -> V_136 ,
V_308 ) ;
}
int F_214 ( struct V_72 * V_73 , struct V_25 * V_26 ,
int V_298 )
{
struct V_6 * V_7 ;
struct V_81 * V_94 ;
unsigned short V_166 ;
struct V_169 * V_170 = F_215 ( V_73 ) ;
T_4 V_51 , V_58 ;
struct V_1 * V_1 = F_65 ( V_73 -> V_87 ) ;
if ( ! F_216 ( V_73 , sizeof( struct V_81 ) ) )
goto V_282;
V_94 = F_81 ( V_73 ) ;
V_166 = F_58 ( V_94 -> V_128 ) ;
V_51 = F_64 ( V_73 ) -> V_51 ;
V_58 = F_64 ( V_73 ) -> V_58 ;
if ( V_166 > V_73 -> V_128 )
goto V_309;
if ( V_298 == V_137 ) {
if ( V_166 < sizeof( * V_94 ) || F_217 ( V_73 , V_166 ) )
goto V_309;
V_94 = F_81 ( V_73 ) ;
}
if ( F_211 ( V_73 , V_94 , V_298 ) )
goto V_284;
V_7 = F_218 ( V_73 ) ;
if ( V_7 ) {
struct V_295 * V_130 = F_66 ( V_73 ) ;
int V_236 ;
if ( F_54 ( V_7 -> V_297 != V_130 ) )
F_201 ( V_7 , V_130 ) ;
V_236 = F_187 ( V_7 , V_73 ) ;
F_56 ( V_7 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( V_170 -> V_222 & ( V_223 | V_310 ) )
return F_205 ( V_1 , V_73 , V_94 ,
V_51 , V_58 , V_26 , V_298 ) ;
V_7 = F_63 ( V_73 , V_94 -> V_100 , V_94 -> V_99 , V_26 ) ;
if ( V_7 ) {
int V_236 ;
if ( F_219 ( V_7 ) && V_94 -> V_136 && ! F_95 ( V_7 ) )
F_220 ( V_73 , V_137 , V_94 -> V_136 ,
V_308 ) ;
V_236 = F_187 ( V_7 , V_73 ) ;
F_56 ( V_7 ) ;
if ( V_236 > 0 )
return - V_236 ;
return 0 ;
}
if ( ! F_188 ( NULL , V_281 , V_73 ) )
goto V_282;
F_189 ( V_73 ) ;
if ( F_141 ( V_73 ) )
goto V_284;
F_142 ( V_1 , V_311 , V_298 == V_307 ) ;
F_221 ( V_73 , V_109 , V_312 , 0 ) ;
F_182 ( V_73 ) ;
return 0 ;
V_309:
F_130 ( L_5 ,
V_298 == V_307 ? L_6 : L_7 ,
& V_51 , F_58 ( V_94 -> V_100 ) ,
V_166 , V_73 -> V_128 ,
& V_58 , F_58 ( V_94 -> V_99 ) ) ;
goto V_282;
V_284:
F_130 ( L_8 ,
V_298 == V_307 ? L_6 : L_7 ,
& V_51 , F_58 ( V_94 -> V_100 ) , & V_58 , F_58 ( V_94 -> V_99 ) ,
V_166 ) ;
F_142 ( V_1 , V_242 , V_298 == V_307 ) ;
V_282:
F_142 ( V_1 , V_243 , V_298 == V_307 ) ;
F_182 ( V_73 ) ;
return 0 ;
}
static struct V_6 * F_222 ( struct V_1 * V_1 ,
T_5 V_88 , T_4 V_89 ,
T_5 V_90 , T_4 V_91 ,
int V_60 )
{
struct V_6 * V_7 , * V_74 ;
struct V_11 * V_12 ;
unsigned short V_56 = F_58 ( V_88 ) ;
unsigned int V_38 , V_84 = F_59 ( V_1 , V_56 , V_25 . V_35 ) ;
struct V_3 * V_4 = & V_25 . V_79 [ V_84 ] ;
if ( V_4 -> V_38 > 10 )
return NULL ;
F_60 () ;
V_80:
V_38 = 0 ;
V_74 = NULL ;
F_62 (sk, node, &hslot->head) {
if ( F_69 ( V_1 , V_7 ,
V_88 , V_89 ,
V_90 , V_91 ,
V_60 , V_56 ) ) {
V_74 = V_7 ;
++ V_38 ;
}
}
if ( F_53 ( V_12 ) != V_84 )
goto V_80;
if ( V_74 ) {
if ( V_38 != 1 ||
F_54 ( ! F_55 ( & V_74 -> V_82 , 2 ) ) )
V_74 = NULL ;
else if ( F_54 ( ! F_69 ( V_1 , V_74 ,
V_88 , V_89 ,
V_90 , V_91 ,
V_60 , V_56 ) ) ) {
F_56 ( V_74 ) ;
V_74 = NULL ;
}
}
F_61 () ;
return V_74 ;
}
static struct V_6 * F_223 ( struct V_1 * V_1 ,
T_5 V_88 , T_4 V_89 ,
T_5 V_90 , T_4 V_91 ,
int V_60 )
{
struct V_6 * V_7 , * V_74 ;
struct V_11 * V_12 ;
unsigned short V_56 = F_58 ( V_88 ) ;
unsigned int V_83 = F_38 ( V_1 , V_89 , V_56 ) ;
unsigned int V_40 = V_83 & V_25 . V_35 ;
struct V_3 * V_19 = & V_25 . V_83 [ V_40 ] ;
F_224 ( V_313 , V_91 , V_89 ) ;
const T_11 V_314 = F_225 ( V_90 , V_56 ) ;
F_60 () ;
V_74 = NULL ;
F_50 (sk, node, &hslot2->head) {
if ( F_226 ( V_7 , V_1 , V_313 ,
V_91 , V_89 , V_314 , V_60 ) )
V_74 = V_7 ;
break;
}
if ( V_74 ) {
if ( F_54 ( ! F_55 ( & V_74 -> V_82 , 2 ) ) )
V_74 = NULL ;
else if ( F_54 ( ! F_226 ( V_7 , V_1 , V_313 ,
V_91 , V_89 ,
V_314 , V_60 ) ) ) {
F_56 ( V_74 ) ;
V_74 = NULL ;
}
}
F_61 () ;
return V_74 ;
}
void F_227 ( struct V_72 * V_73 )
{
struct V_1 * V_1 = F_65 ( V_73 -> V_87 ) ;
const struct V_85 * V_86 ;
const struct V_81 * V_94 ;
struct V_6 * V_7 ;
struct V_295 * V_130 ;
int V_60 = V_73 -> V_87 -> V_101 ;
int V_315 ;
if ( ! F_216 ( V_73 , F_82 ( V_73 ) + sizeof( struct V_81 ) ) )
return;
V_86 = F_64 ( V_73 ) ;
V_94 = F_81 ( V_73 ) ;
if ( V_73 -> V_316 == V_317 ||
V_73 -> V_316 == V_318 ) {
struct V_319 * V_320 = F_228 ( V_73 -> V_87 ) ;
if ( ! V_320 )
return;
V_315 = F_229 ( V_320 , V_86 -> V_58 , V_86 -> V_51 ,
V_86 -> V_321 ) ;
if ( ! V_315 )
return;
V_7 = F_222 ( V_1 , V_94 -> V_99 , V_86 -> V_58 ,
V_94 -> V_100 , V_86 -> V_51 , V_60 ) ;
} else if ( V_73 -> V_316 == V_322 ) {
V_7 = F_223 ( V_1 , V_94 -> V_99 , V_86 -> V_58 ,
V_94 -> V_100 , V_86 -> V_51 , V_60 ) ;
} else {
return;
}
if ( ! V_7 )
return;
V_73 -> V_7 = V_7 ;
V_73 -> V_323 = V_324 ;
V_130 = F_230 ( V_7 -> V_297 ) ;
if ( V_130 )
V_130 = F_231 ( V_130 , 0 ) ;
if ( V_130 ) {
if ( V_130 -> V_232 & V_325 ) {
if ( F_106 ( F_232 ( & V_130 -> V_326 ) ) )
F_233 ( V_73 , V_130 ) ;
} else {
F_234 ( V_73 , V_130 ) ;
}
}
}
int F_235 ( struct V_72 * V_73 )
{
return F_214 ( V_73 , & V_25 , V_137 ) ;
}
void F_236 ( struct V_6 * V_7 )
{
struct V_125 * V_126 = F_7 ( V_7 ) ;
bool V_245 = F_146 ( V_7 ) ;
F_78 ( V_7 ) ;
F_149 ( V_7 , V_245 ) ;
if ( F_190 ( & V_280 ) && V_126 -> V_283 ) {
void (* F_237)( struct V_6 * V_7 );
F_237 = F_192 ( V_126 -> F_237 ) ;
if ( F_237 )
F_237 ( V_7 ) ;
}
}
int F_238 ( struct V_6 * V_7 , int V_327 , int V_328 ,
char V_250 * V_329 , unsigned int V_207 ,
int (* F_239)( struct V_6 * ) )
{
struct V_125 * V_126 = F_7 ( V_7 ) ;
int V_330 , V_331 ;
int V_98 = 0 ;
int V_150 = F_95 ( V_7 ) ;
if ( V_207 < sizeof( int ) )
return - V_187 ;
if ( F_240 ( V_330 , ( int V_250 * ) V_329 ) )
return - V_332 ;
V_331 = V_330 ? 1 : 0 ;
switch ( V_328 ) {
case V_333 :
if ( V_330 != 0 ) {
V_126 -> V_174 = 1 ;
} else {
V_126 -> V_174 = 0 ;
F_105 ( V_7 ) ;
F_239 ( V_7 ) ;
F_107 ( V_7 ) ;
}
break;
case V_334 :
switch ( V_330 ) {
case 0 :
case V_335 :
case V_336 :
V_126 -> F_191 = V_337 ;
case V_338 :
V_126 -> V_283 = V_330 ;
F_184 () ;
break;
default:
V_98 = - V_339 ;
break;
}
break;
case V_340 :
V_126 -> V_341 = V_331 ;
break;
case V_342 :
V_126 -> V_343 = V_331 ;
break;
case V_344 :
if ( ! V_150 )
return - V_339 ;
if ( V_330 != 0 && V_330 < 8 )
V_330 = 8 ;
else if ( V_330 > V_345 )
V_330 = V_345 ;
V_126 -> V_346 = V_330 ;
V_126 -> V_347 |= V_348 ;
break;
case V_349 :
if ( ! V_150 )
return - V_339 ;
if ( V_330 != 0 && V_330 < 8 )
V_330 = 8 ;
else if ( V_330 > V_345 )
V_330 = V_345 ;
V_126 -> V_286 = V_330 ;
V_126 -> V_347 |= V_285 ;
break;
default:
V_98 = - V_339 ;
break;
}
return V_98 ;
}
int F_241 ( struct V_6 * V_7 , int V_327 , int V_328 ,
char V_250 * V_329 , unsigned int V_207 )
{
if ( V_327 == V_350 || V_327 == V_351 )
return F_238 ( V_7 , V_327 , V_328 , V_329 , V_207 ,
F_101 ) ;
return F_242 ( V_7 , V_327 , V_328 , V_329 , V_207 ) ;
}
int F_243 ( struct V_6 * V_7 , int V_327 , int V_328 ,
char V_250 * V_329 , unsigned int V_207 )
{
if ( V_327 == V_350 || V_327 == V_351 )
return F_238 ( V_7 , V_327 , V_328 , V_329 , V_207 ,
F_101 ) ;
return F_244 ( V_7 , V_327 , V_328 , V_329 , V_207 ) ;
}
int F_245 ( struct V_6 * V_7 , int V_327 , int V_328 ,
char V_250 * V_329 , int V_250 * V_207 )
{
struct V_125 * V_126 = F_7 ( V_7 ) ;
int V_330 , V_128 ;
if ( F_240 ( V_128 , V_207 ) )
return - V_332 ;
V_128 = F_246 (unsigned int, len, sizeof(int)) ;
if ( V_128 < 0 )
return - V_187 ;
switch ( V_328 ) {
case V_333 :
V_330 = V_126 -> V_174 ;
break;
case V_334 :
V_330 = V_126 -> V_283 ;
break;
case V_340 :
V_330 = V_126 -> V_341 ;
break;
case V_342 :
V_330 = V_126 -> V_343 ;
break;
case V_344 :
V_330 = V_126 -> V_346 ;
break;
case V_349 :
V_330 = V_126 -> V_286 ;
break;
default:
return - V_339 ;
}
if ( F_152 ( V_128 , V_207 ) )
return - V_332 ;
if ( F_247 ( V_329 , & V_330 , V_128 ) )
return - V_332 ;
return 0 ;
}
int F_248 ( struct V_6 * V_7 , int V_327 , int V_328 ,
char V_250 * V_329 , int V_250 * V_207 )
{
if ( V_327 == V_350 || V_327 == V_351 )
return F_245 ( V_7 , V_327 , V_328 , V_329 , V_207 ) ;
return F_249 ( V_7 , V_327 , V_328 , V_329 , V_207 ) ;
}
int F_250 ( struct V_6 * V_7 , int V_327 , int V_328 ,
char V_250 * V_329 , int V_250 * V_207 )
{
if ( V_327 == V_350 || V_327 == V_351 )
return F_245 ( V_7 , V_327 , V_328 , V_329 , V_207 ) ;
return F_251 ( V_7 , V_327 , V_328 , V_329 , V_207 ) ;
}
unsigned int F_252 ( struct V_352 * V_352 , struct V_353 * V_6 , T_12 * V_354 )
{
unsigned int V_35 = F_253 ( V_352 , V_6 , V_354 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_254 ( V_7 ) ;
if ( ( V_35 & V_355 ) && ! ( V_352 -> V_356 & V_357 ) &&
! ( V_7 -> V_358 & V_359 ) && ! F_138 ( V_7 ) )
V_35 &= ~ ( V_360 | V_355 ) ;
return V_35 ;
}
static struct V_6 * F_255 ( struct V_361 * V_362 , int V_363 )
{
struct V_6 * V_7 ;
struct V_364 * V_365 = V_362 -> V_366 ;
struct V_1 * V_1 = F_256 ( V_362 ) ;
for ( V_365 -> V_367 = V_363 ; V_365 -> V_367 <= V_365 -> V_25 -> V_35 ;
++ V_365 -> V_367 ) {
struct V_11 * V_12 ;
struct V_3 * V_4 = & V_365 -> V_25 -> V_79 [ V_365 -> V_367 ] ;
if ( F_257 ( & V_4 -> V_45 ) )
continue;
F_27 ( & V_4 -> V_21 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_22 == V_365 -> V_368 )
goto V_36;
}
F_30 ( & V_4 -> V_21 ) ;
}
V_7 = NULL ;
V_36:
return V_7 ;
}
static struct V_6 * F_258 ( struct V_361 * V_362 , struct V_6 * V_7 )
{
struct V_364 * V_365 = V_362 -> V_366 ;
struct V_1 * V_1 = F_256 ( V_362 ) ;
do {
V_7 = F_259 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_22 != V_365 -> V_368 ) );
if ( ! V_7 ) {
if ( V_365 -> V_367 <= V_365 -> V_25 -> V_35 )
F_30 ( & V_365 -> V_25 -> V_79 [ V_365 -> V_367 ] . V_21 ) ;
return F_255 ( V_362 , V_365 -> V_367 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_260 ( struct V_361 * V_362 , T_13 V_369 )
{
struct V_6 * V_7 = F_255 ( V_362 , 0 ) ;
if ( V_7 )
while ( V_369 && ( V_7 = F_258 ( V_362 , V_7 ) ) != NULL )
-- V_369 ;
return V_369 ? NULL : V_7 ;
}
static void * F_261 ( struct V_361 * V_362 , T_13 * V_369 )
{
struct V_364 * V_365 = V_362 -> V_366 ;
V_365 -> V_367 = V_370 ;
return * V_369 ? F_260 ( V_362 , * V_369 - 1 ) : V_371 ;
}
static void * F_262 ( struct V_361 * V_362 , void * V_372 , T_13 * V_369 )
{
struct V_6 * V_7 ;
if ( V_372 == V_371 )
V_7 = F_260 ( V_362 , 0 ) ;
else
V_7 = F_258 ( V_362 , V_372 ) ;
++ * V_369 ;
return V_7 ;
}
static void F_263 ( struct V_361 * V_362 , void * V_372 )
{
struct V_364 * V_365 = V_362 -> V_366 ;
if ( V_365 -> V_367 <= V_365 -> V_25 -> V_35 )
F_30 ( & V_365 -> V_25 -> V_79 [ V_365 -> V_367 ] . V_21 ) ;
}
int F_264 ( struct V_373 * V_373 , struct V_352 * V_352 )
{
struct V_374 * V_375 = F_265 ( V_373 ) ;
struct V_364 * V_376 ;
int V_98 ;
V_98 = F_266 ( V_373 , V_352 , & V_375 -> V_377 ,
sizeof( struct V_364 ) ) ;
if ( V_98 < 0 )
return V_98 ;
V_376 = ( (struct V_361 * ) V_352 -> V_378 ) -> V_366 ;
V_376 -> V_368 = V_375 -> V_368 ;
V_376 -> V_25 = V_375 -> V_25 ;
return V_98 ;
}
int F_267 ( struct V_1 * V_1 , struct V_374 * V_375 )
{
struct V_379 * V_380 ;
int V_277 = 0 ;
V_375 -> V_377 . V_363 = F_261 ;
V_375 -> V_377 . V_381 = F_262 ;
V_375 -> V_377 . V_382 = F_263 ;
V_380 = F_268 ( V_375 -> V_383 , V_384 , V_1 -> V_385 ,
V_375 -> V_386 , V_375 ) ;
if ( ! V_380 )
V_277 = - V_278 ;
return V_277 ;
}
void F_269 ( struct V_1 * V_1 , struct V_374 * V_375 )
{
F_270 ( V_375 -> V_383 , V_1 -> V_385 ) ;
}
static void F_271 ( struct V_6 * V_387 , struct V_361 * V_388 ,
int V_367 )
{
struct V_47 * V_62 = F_32 ( V_387 ) ;
T_4 V_99 = V_62 -> V_64 ;
T_4 V_129 = V_62 -> V_50 ;
T_1 V_389 = F_58 ( V_62 -> V_65 ) ;
T_1 V_390 = F_58 ( V_62 -> V_151 ) ;
F_272 ( V_388 , L_9
L_10 ,
V_367 , V_129 , V_390 , V_99 , V_389 , V_387 -> V_120 ,
F_151 ( V_387 ) ,
F_273 ( V_387 ) ,
0 , 0L , 0 ,
F_274 ( F_275 ( V_388 ) , F_3 ( V_387 ) ) ,
0 , F_276 ( V_387 ) ,
F_277 ( & V_387 -> V_82 ) , V_387 ,
F_277 ( & V_387 -> V_244 ) ) ;
}
int F_278 ( struct V_361 * V_362 , void * V_372 )
{
F_279 ( V_362 , 127 ) ;
if ( V_372 == V_371 )
F_280 ( V_362 , L_11
L_12
L_13 ) ;
else {
struct V_364 * V_365 = V_362 -> V_366 ;
F_271 ( V_372 , V_362 , V_365 -> V_367 ) ;
}
F_281 ( V_362 , '\n' ) ;
return 0 ;
}
static int T_14 F_282 ( struct V_1 * V_1 )
{
return F_267 ( V_1 , & V_391 ) ;
}
static void T_15 F_283 ( struct V_1 * V_1 )
{
F_269 ( V_1 , & V_391 ) ;
}
int T_16 F_284 ( void )
{
return F_285 ( & V_392 ) ;
}
void F_286 ( void )
{
F_287 ( & V_392 ) ;
}
static int T_16 F_288 ( char * V_393 )
{
T_17 V_236 ;
if ( ! V_393 )
return 0 ;
V_236 = F_289 ( V_393 , 0 , & V_394 ) ;
if ( V_236 )
return 0 ;
if ( V_394 && V_394 < V_395 )
V_394 = V_395 ;
return 1 ;
}
void T_16 F_290 ( struct V_25 * V_396 , const char * V_383 )
{
unsigned int V_292 ;
V_396 -> V_79 = F_291 ( V_383 ,
2 * sizeof( struct V_3 ) ,
V_394 ,
21 ,
0 ,
& V_396 -> log ,
& V_396 -> V_35 ,
V_395 ,
64 * 1024 ) ;
V_396 -> V_83 = V_396 -> V_79 + ( V_396 -> V_35 + 1 ) ;
for ( V_292 = 0 ; V_292 <= V_396 -> V_35 ; V_292 ++ ) {
F_292 ( & V_396 -> V_79 [ V_292 ] . V_45 , V_292 ) ;
V_396 -> V_79 [ V_292 ] . V_38 = 0 ;
F_293 ( & V_396 -> V_79 [ V_292 ] . V_21 ) ;
}
for ( V_292 = 0 ; V_292 <= V_396 -> V_35 ; V_292 ++ ) {
F_292 ( & V_396 -> V_83 [ V_292 ] . V_45 , V_292 ) ;
V_396 -> V_83 [ V_292 ] . V_38 = 0 ;
F_293 ( & V_396 -> V_83 [ V_292 ] . V_21 ) ;
}
}
T_3 F_294 ( void )
{
static T_3 T_18 V_71 ;
F_47 ( & T_18 , sizeof( T_18 ) ) ;
return T_18 ;
}
void T_16 F_295 ( void )
{
unsigned long V_397 ;
F_290 ( & V_25 , L_14 ) ;
V_397 = F_296 () / 8 ;
V_397 = F_297 ( V_397 , 128UL ) ;
V_398 [ 0 ] = V_397 / 4 * 3 ;
V_398 [ 1 ] = V_397 ;
V_398 [ 2 ] = V_398 [ 0 ] * 2 ;
V_399 = V_400 ;
V_401 = V_400 ;
}
