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
if ( F_36 ( V_46 ) && V_7 -> V_17 &&
V_7 -> V_22 == V_47 )
F_37 ( & F_7 ( V_7 ) -> V_48 ,
& V_19 -> V_45 ) ;
else
F_38 ( & F_7 ( V_7 ) -> V_48 ,
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
int F_39 ( const struct V_6 * V_8 , const struct V_6 * V_9 ,
bool V_10 )
{
struct V_49 * V_50 = F_32 ( V_8 ) , * V_51 = F_32 ( V_9 ) ;
if ( ! F_17 ( V_9 ) ) {
if ( V_50 -> V_52 == V_51 -> V_52 )
return 1 ;
if ( ! V_50 -> V_52 || ! V_51 -> V_52 )
return V_10 ;
}
return 0 ;
}
static T_3 F_40 ( const struct V_1 * V_1 , T_4 V_53 ,
unsigned int V_54 )
{
return F_41 ( ( V_55 T_3 ) V_53 , F_42 ( V_1 ) ) ^ V_54 ;
}
int F_43 ( struct V_6 * V_7 , unsigned short V_23 )
{
unsigned int V_24 =
F_40 ( F_6 ( V_7 ) , F_44 ( V_56 ) , V_23 ) ;
unsigned int V_57 =
F_40 ( F_6 ( V_7 ) , F_32 ( V_7 ) -> V_52 , 0 ) ;
F_7 ( V_7 ) -> V_41 = V_57 ;
return F_20 ( V_7 , V_23 , F_39 , V_24 ) ;
}
static inline int F_45 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_53 , unsigned short V_58 , T_5 V_59 ,
T_4 V_60 , T_5 V_61 , int V_62 )
{
int V_63 ;
struct V_49 * V_64 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_14 != V_58 ||
F_17 ( V_7 ) )
return - 1 ;
V_63 = ( V_7 -> V_22 == V_65 ) ? 2 : 1 ;
V_64 = F_32 ( V_7 ) ;
if ( V_64 -> V_52 ) {
if ( V_64 -> V_52 != V_60 )
return - 1 ;
V_63 += 4 ;
}
if ( V_64 -> V_66 ) {
if ( V_64 -> V_66 != V_53 )
return - 1 ;
V_63 += 4 ;
}
if ( V_64 -> V_67 ) {
if ( V_64 -> V_67 != V_59 )
return - 1 ;
V_63 += 4 ;
}
if ( V_7 -> V_16 ) {
if ( V_7 -> V_16 != V_62 )
return - 1 ;
V_63 += 4 ;
}
if ( V_7 -> V_68 == F_46 () )
V_63 ++ ;
return V_63 ;
}
static inline int F_47 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_4 V_53 , T_5 V_59 ,
T_4 V_60 , unsigned int V_58 , int V_62 )
{
int V_63 ;
struct V_49 * V_64 ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_17 ( V_7 ) )
return - 1 ;
V_64 = F_32 ( V_7 ) ;
if ( V_64 -> V_52 != V_60 ||
V_64 -> V_44 != V_58 )
return - 1 ;
V_63 = ( V_7 -> V_22 == V_65 ) ? 2 : 1 ;
if ( V_64 -> V_66 ) {
if ( V_64 -> V_66 != V_53 )
return - 1 ;
V_63 += 4 ;
}
if ( V_64 -> V_67 ) {
if ( V_64 -> V_67 != V_59 )
return - 1 ;
V_63 += 4 ;
}
if ( V_7 -> V_16 ) {
if ( V_7 -> V_16 != V_62 )
return - 1 ;
V_63 += 4 ;
}
if ( V_7 -> V_68 == F_46 () )
V_63 ++ ;
return V_63 ;
}
static T_3 F_48 ( const struct V_1 * V_1 , const T_4 V_69 ,
const T_1 V_70 , const T_4 V_71 ,
const T_5 V_72 )
{
static T_3 T_6 V_73 ;
F_49 ( & T_6 , sizeof( T_6 ) ) ;
return F_50 ( V_69 , V_70 , V_71 , V_72 ,
T_6 + F_42 ( V_1 ) ) ;
}
static struct V_6 * F_51 ( struct V_1 * V_1 ,
T_4 V_53 , T_5 V_59 ,
T_4 V_60 , unsigned int V_58 , int V_62 ,
struct V_3 * V_19 , unsigned int V_40 ,
struct V_74 * V_75 )
{
struct V_6 * V_7 , * V_76 ;
struct V_11 * V_12 ;
int V_63 , V_77 , V_78 = 0 , V_79 = 0 ;
bool V_80 = true ;
T_3 V_81 = 0 ;
V_82:
V_76 = NULL ;
V_77 = 0 ;
F_52 (sk, node, &hslot2->head) {
V_63 = F_47 ( V_7 , V_1 , V_53 , V_59 ,
V_60 , V_58 , V_62 ) ;
if ( V_63 > V_77 ) {
V_76 = V_7 ;
V_77 = V_63 ;
V_79 = V_7 -> V_17 ;
if ( V_79 ) {
V_81 = F_48 ( V_1 , V_60 , V_58 ,
V_53 , V_59 ) ;
if ( V_80 ) {
struct V_6 * V_9 ;
V_9 = F_53 ( V_7 , V_81 , V_75 ,
sizeof( struct V_83 ) ) ;
if ( V_9 ) {
V_76 = V_9 ;
V_80 = false ;
goto V_36;
}
}
V_78 = 1 ;
}
} else if ( V_63 == V_77 && V_79 ) {
V_78 ++ ;
if ( F_24 ( V_81 , V_78 ) == 0 )
V_76 = V_7 ;
V_81 = F_54 ( V_81 ) ;
}
}
if ( F_55 ( V_12 ) != V_40 )
goto V_82;
if ( V_76 ) {
V_36:
if ( F_56 ( ! F_57 ( & V_76 -> V_84 , 2 ) ) )
V_76 = NULL ;
else if ( F_56 ( F_47 ( V_76 , V_1 , V_53 , V_59 ,
V_60 , V_58 , V_62 ) < V_77 ) ) {
F_58 ( V_76 ) ;
goto V_82;
}
}
return V_76 ;
}
struct V_6 * F_59 ( struct V_1 * V_1 , T_4 V_53 ,
T_5 V_59 , T_4 V_60 , T_5 V_61 ,
int V_62 , struct V_25 * V_26 , struct V_74 * V_75 )
{
struct V_6 * V_7 , * V_76 ;
struct V_11 * V_12 ;
unsigned short V_58 = F_60 ( V_61 ) ;
unsigned int V_85 , V_40 , V_86 = F_61 ( V_1 , V_58 , V_26 -> V_35 ) ;
struct V_3 * V_19 , * V_4 = & V_26 -> V_81 [ V_86 ] ;
int V_63 , V_77 , V_78 = 0 , V_79 = 0 ;
bool V_80 = true ;
T_3 V_81 = 0 ;
F_62 () ;
if ( V_4 -> V_38 > 10 ) {
V_85 = F_40 ( V_1 , V_60 , V_58 ) ;
V_40 = V_85 & V_26 -> V_35 ;
V_19 = & V_26 -> V_85 [ V_40 ] ;
if ( V_4 -> V_38 < V_19 -> V_38 )
goto V_82;
V_76 = F_51 ( V_1 , V_53 , V_59 ,
V_60 , V_58 , V_62 ,
V_19 , V_40 , V_75 ) ;
if ( ! V_76 ) {
V_85 = F_40 ( V_1 , F_44 ( V_56 ) , V_58 ) ;
V_40 = V_85 & V_26 -> V_35 ;
V_19 = & V_26 -> V_85 [ V_40 ] ;
if ( V_4 -> V_38 < V_19 -> V_38 )
goto V_82;
V_76 = F_51 ( V_1 , V_53 , V_59 ,
F_44 ( V_56 ) , V_58 , V_62 ,
V_19 , V_40 , V_75 ) ;
}
F_63 () ;
return V_76 ;
}
V_82:
V_76 = NULL ;
V_77 = 0 ;
F_64 (sk, node, &hslot->head) {
V_63 = F_45 ( V_7 , V_1 , V_53 , V_58 , V_59 ,
V_60 , V_61 , V_62 ) ;
if ( V_63 > V_77 ) {
V_76 = V_7 ;
V_77 = V_63 ;
V_79 = V_7 -> V_17 ;
if ( V_79 ) {
V_81 = F_48 ( V_1 , V_60 , V_58 ,
V_53 , V_59 ) ;
if ( V_80 ) {
struct V_6 * V_9 ;
V_9 = F_53 ( V_7 , V_81 , V_75 ,
sizeof( struct V_83 ) ) ;
if ( V_9 ) {
V_76 = V_9 ;
V_80 = false ;
goto V_36;
}
}
V_78 = 1 ;
}
} else if ( V_63 == V_77 && V_79 ) {
V_78 ++ ;
if ( F_24 ( V_81 , V_78 ) == 0 )
V_76 = V_7 ;
V_81 = F_54 ( V_81 ) ;
}
}
if ( F_55 ( V_12 ) != V_86 )
goto V_82;
if ( V_76 ) {
V_36:
if ( F_56 ( ! F_57 ( & V_76 -> V_84 , 2 ) ) )
V_76 = NULL ;
else if ( F_56 ( F_45 ( V_76 , V_1 , V_53 , V_58 , V_59 ,
V_60 , V_61 , V_62 ) < V_77 ) ) {
F_58 ( V_76 ) ;
goto V_82;
}
}
F_63 () ;
return V_76 ;
}
static inline struct V_6 * F_65 ( struct V_74 * V_75 ,
T_5 V_59 , T_5 V_61 ,
struct V_25 * V_26 )
{
const struct V_87 * V_88 = F_66 ( V_75 ) ;
return F_59 ( F_67 ( F_68 ( V_75 ) -> V_89 ) , V_88 -> V_53 , V_59 ,
V_88 -> V_60 , V_61 , F_69 ( V_75 ) ,
V_26 , V_75 ) ;
}
struct V_6 * F_70 ( struct V_1 * V_1 , T_4 V_53 , T_5 V_59 ,
T_4 V_60 , T_5 V_61 , int V_62 )
{
return F_59 ( V_1 , V_53 , V_59 , V_60 , V_61 , V_62 ,
& V_25 , NULL ) ;
}
static inline bool F_71 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_62 , unsigned short V_58 )
{
struct V_49 * V_64 = F_32 ( V_7 ) ;
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) ||
F_7 ( V_7 ) -> V_14 != V_58 ||
( V_64 -> V_66 && V_64 -> V_66 != V_93 ) ||
( V_64 -> V_67 != V_92 && V_64 -> V_67 ) ||
( V_64 -> V_52 && V_64 -> V_52 != V_91 ) ||
F_17 ( V_7 ) ||
( V_7 -> V_16 && V_7 -> V_16 != V_62 ) )
return false ;
if ( ! F_72 ( V_7 , V_91 , V_93 , V_62 ) )
return false ;
return true ;
}
void F_73 ( struct V_74 * V_75 , T_3 V_94 , struct V_25 * V_26 )
{
struct V_49 * V_64 ;
const struct V_87 * V_88 = ( const struct V_87 * ) V_75 -> V_95 ;
struct V_83 * V_96 = (struct V_83 * ) ( V_75 -> V_95 + ( V_88 -> V_97 << 2 ) ) ;
const int type = F_74 ( V_75 ) -> type ;
const int V_98 = F_74 ( V_75 ) -> V_98 ;
struct V_6 * V_7 ;
int V_99 ;
int V_100 ;
struct V_1 * V_1 = F_67 ( V_75 -> V_89 ) ;
V_7 = F_59 ( V_1 , V_88 -> V_60 , V_96 -> V_101 ,
V_88 -> V_53 , V_96 -> V_102 , V_75 -> V_89 -> V_103 , V_26 ,
NULL ) ;
if ( ! V_7 ) {
F_75 ( V_1 , V_104 ) ;
return;
}
V_100 = 0 ;
V_99 = 0 ;
V_64 = F_32 ( V_7 ) ;
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
F_76 ( V_75 , V_7 , V_94 ) ;
if ( V_64 -> V_113 != V_114 ) {
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
F_77 ( V_75 , V_7 ) ;
goto V_108;
}
if ( ! V_64 -> V_121 ) {
if ( ! V_99 || V_7 -> V_122 != V_123 )
goto V_108;
} else
F_78 ( V_7 , V_75 , V_100 , V_96 -> V_101 , V_94 , ( V_124 * ) ( V_96 + 1 ) ) ;
V_7 -> V_125 = V_100 ;
V_7 -> V_126 ( V_7 ) ;
V_108:
F_58 ( V_7 ) ;
}
void F_79 ( struct V_74 * V_75 , T_3 V_94 )
{
F_73 ( V_75 , V_94 , & V_25 ) ;
}
void F_80 ( struct V_6 * V_7 )
{
struct V_127 * V_128 = F_7 ( V_7 ) ;
if ( V_128 -> V_129 ) {
V_128 -> V_130 = 0 ;
V_128 -> V_129 = 0 ;
F_81 ( V_7 ) ;
}
}
void F_82 ( struct V_74 * V_75 , T_4 V_131 , T_4 V_132 )
{
struct V_83 * V_96 = F_83 ( V_75 ) ;
int V_133 = F_84 ( V_75 ) ;
int V_130 = V_75 -> V_130 - V_133 ;
int V_134 = V_130 ;
T_7 V_135 = 0 ;
if ( ! F_85 ( V_75 ) ) {
V_75 -> V_136 = F_86 ( V_75 ) - V_75 -> V_45 ;
V_75 -> V_137 = F_87 ( struct V_83 , V_138 ) ;
V_96 -> V_138 = ~ F_88 ( V_131 , V_132 , V_130 ,
V_139 , 0 ) ;
} else {
struct V_74 * V_140 ;
F_89 (skb, frags) {
V_135 = F_90 ( V_135 , V_140 -> V_135 ) ;
V_134 -= V_140 -> V_130 ;
}
V_135 = F_91 ( V_75 , V_133 , V_134 , V_135 ) ;
V_75 -> V_141 = V_142 ;
V_96 -> V_138 = F_88 ( V_131 , V_132 , V_130 , V_139 , V_135 ) ;
if ( V_96 -> V_138 == 0 )
V_96 -> V_138 = V_143 ;
}
}
void F_92 ( bool V_144 , struct V_74 * V_75 ,
T_4 V_53 , T_4 V_60 , int V_130 )
{
struct V_83 * V_96 = F_83 ( V_75 ) ;
if ( V_144 ) {
V_96 -> V_138 = 0 ;
} else if ( F_93 ( V_75 ) ) {
V_96 -> V_138 = ~ F_94 ( V_130 , V_53 , V_60 , 0 ) ;
} else if ( V_75 -> V_141 == V_145 ) {
V_96 -> V_138 = 0 ;
V_96 -> V_138 = F_94 ( V_130 , V_53 , V_60 , F_95 ( V_75 ) ) ;
if ( V_96 -> V_138 == 0 )
V_96 -> V_138 = V_143 ;
} else {
V_75 -> V_141 = V_145 ;
V_75 -> V_136 = F_86 ( V_75 ) - V_75 -> V_45 ;
V_75 -> V_137 = F_87 ( struct V_83 , V_138 ) ;
V_96 -> V_138 = ~ F_94 ( V_130 , V_53 , V_60 , 0 ) ;
}
}
static int F_96 ( struct V_74 * V_75 , struct V_146 * V_147 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
struct V_49 * V_64 = F_32 ( V_7 ) ;
struct V_83 * V_96 ;
int V_100 = 0 ;
int V_148 = F_97 ( V_7 ) ;
int V_133 = F_84 ( V_75 ) ;
int V_130 = V_75 -> V_130 - V_133 ;
T_7 V_135 = 0 ;
V_96 = F_83 ( V_75 ) ;
V_96 -> V_102 = V_64 -> V_149 ;
V_96 -> V_101 = V_147 -> V_150 ;
V_96 -> V_130 = F_98 ( V_130 ) ;
V_96 -> V_138 = 0 ;
if ( V_148 )
V_135 = F_99 ( V_75 ) ;
else if ( V_7 -> V_151 ) {
V_75 -> V_141 = V_142 ;
goto V_152;
} else if ( V_75 -> V_141 == V_145 ) {
F_82 ( V_75 , V_147 -> V_53 , V_147 -> V_60 ) ;
goto V_152;
} else
V_135 = F_100 ( V_75 ) ;
V_96 -> V_138 = F_88 ( V_147 -> V_53 , V_147 -> V_60 , V_130 ,
V_7 -> V_153 , V_135 ) ;
if ( V_96 -> V_138 == 0 )
V_96 -> V_138 = V_143 ;
V_152:
V_100 = F_101 ( F_6 ( V_7 ) , V_75 ) ;
if ( V_100 ) {
if ( V_100 == - V_154 && ! V_64 -> V_121 ) {
F_102 ( F_6 ( V_7 ) ,
V_155 , V_148 ) ;
V_100 = 0 ;
}
} else
F_102 ( F_6 ( V_7 ) ,
V_156 , V_148 ) ;
return V_100 ;
}
int F_103 ( struct V_6 * V_7 )
{
struct V_127 * V_128 = F_7 ( V_7 ) ;
struct V_49 * V_64 = F_32 ( V_7 ) ;
struct V_146 * V_147 = & V_64 -> V_157 . V_158 . V_159 . V_160 ;
struct V_74 * V_75 ;
int V_100 = 0 ;
V_75 = F_104 ( V_7 , V_147 ) ;
if ( ! V_75 )
goto V_108;
V_100 = F_96 ( V_75 , V_147 ) ;
V_108:
V_128 -> V_130 = 0 ;
V_128 -> V_129 = 0 ;
return V_100 ;
}
int F_105 ( struct V_6 * V_7 , struct V_161 * V_162 , T_8 V_130 )
{
struct V_49 * V_64 = F_32 ( V_7 ) ;
struct V_127 * V_128 = F_7 ( V_7 ) ;
struct V_146 V_163 ;
struct V_146 * V_147 ;
int V_164 = V_130 ;
struct V_165 V_166 ;
struct V_167 * V_168 = NULL ;
int free = 0 ;
int V_169 = 0 ;
T_4 V_60 , V_71 , V_53 ;
T_5 V_61 ;
V_124 V_170 ;
int V_100 , V_148 = F_97 ( V_7 ) ;
int V_171 = V_128 -> V_172 || V_162 -> V_173 & V_174 ;
int (* F_106)( void * , char * , int , int , int , struct V_74 * );
struct V_74 * V_75 ;
struct V_175 V_176 ;
if ( V_130 > 0xFFFF )
return - V_115 ;
if ( V_162 -> V_173 & V_177 )
return - V_178 ;
V_166 . V_179 = NULL ;
V_166 . V_180 = 0 ;
V_166 . V_181 = 0 ;
V_166 . V_170 = - 1 ;
F_106 = V_148 ? V_182 : V_183 ;
V_147 = & V_64 -> V_157 . V_158 . V_159 . V_160 ;
if ( V_128 -> V_129 ) {
F_107 ( V_7 ) ;
if ( F_108 ( V_128 -> V_129 ) ) {
if ( F_56 ( V_128 -> V_129 != V_184 ) ) {
F_109 ( V_7 ) ;
return - V_185 ;
}
goto V_186;
}
F_109 ( V_7 ) ;
}
V_164 += sizeof( struct V_83 ) ;
if ( V_162 -> V_187 ) {
F_110 ( struct V_188 * , V_189 , V_162 -> V_187 ) ;
if ( V_162 -> V_190 < sizeof( * V_189 ) )
return - V_185 ;
if ( V_189 -> V_191 != V_184 ) {
if ( V_189 -> V_191 != V_192 )
return - V_193 ;
}
V_60 = V_189 -> V_194 . V_195 ;
V_61 = V_189 -> V_196 ;
if ( V_61 == 0 )
return - V_185 ;
} else {
if ( V_7 -> V_122 != V_123 )
return - V_197 ;
V_60 = V_64 -> V_66 ;
V_61 = V_64 -> V_67 ;
V_169 = 1 ;
}
V_166 . V_198 = V_64 -> V_199 ;
V_166 . V_200 = V_7 -> V_16 ;
F_111 ( V_7 , & V_166 . V_180 ) ;
if ( V_162 -> V_201 ) {
V_100 = F_112 ( F_6 ( V_7 ) , V_162 , & V_166 ,
V_7 -> V_22 == V_47 ) ;
if ( F_56 ( V_100 ) ) {
F_113 ( V_166 . V_179 ) ;
return V_100 ;
}
if ( V_166 . V_179 )
free = 1 ;
V_169 = 0 ;
}
if ( ! V_166 . V_179 ) {
struct V_202 * V_203 ;
F_62 () ;
V_203 = F_114 ( V_64 -> V_203 ) ;
if ( V_203 ) {
memcpy ( & V_176 , V_203 ,
sizeof( * V_203 ) + V_203 -> V_179 . V_204 ) ;
V_166 . V_179 = & V_176 . V_179 ;
}
F_63 () ;
}
V_53 = V_166 . V_198 ;
V_166 . V_198 = V_71 = V_60 ;
if ( V_166 . V_179 && V_166 . V_179 -> V_179 . V_205 ) {
if ( ! V_60 )
return - V_185 ;
V_71 = V_166 . V_179 -> V_179 . V_71 ;
V_169 = 0 ;
}
V_170 = F_115 ( & V_166 , V_64 ) ;
if ( F_116 ( V_7 , V_206 ) ||
( V_162 -> V_173 & V_207 ) ||
( V_166 . V_179 && V_166 . V_179 -> V_179 . V_208 ) ) {
V_170 |= V_209 ;
V_169 = 0 ;
}
if ( F_117 ( V_60 ) ) {
if ( ! V_166 . V_200 )
V_166 . V_200 = V_64 -> V_210 ;
if ( ! V_53 )
V_53 = V_64 -> V_211 ;
V_169 = 0 ;
} else if ( ! V_166 . V_200 )
V_166 . V_200 = V_64 -> V_212 ;
if ( V_169 )
V_168 = (struct V_167 * ) F_118 ( V_7 , 0 ) ;
if ( ! V_168 ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
T_9 V_213 = F_119 ( V_7 ) ;
V_147 = & V_163 ;
F_120 ( V_147 , V_166 . V_200 , V_7 -> V_214 , V_170 ,
V_215 , V_7 -> V_153 ,
V_213 ,
V_71 , V_53 , V_61 , V_64 -> V_149 ) ;
if ( ! V_53 && V_166 . V_200 ) {
V_100 = F_121 ( V_1 , V_166 . V_200 , V_147 ) ;
if ( V_100 < 0 )
goto V_108;
}
F_122 ( V_7 , F_123 ( V_147 ) ) ;
V_168 = F_124 ( V_1 , V_147 , V_7 ) ;
if ( F_125 ( V_168 ) ) {
V_100 = F_126 ( V_168 ) ;
V_168 = NULL ;
if ( V_100 == - V_216 )
F_127 ( V_1 , V_217 ) ;
goto V_108;
}
V_100 = - V_218 ;
if ( ( V_168 -> V_219 & V_220 ) &&
! F_116 ( V_7 , V_221 ) )
goto V_108;
if ( V_169 )
F_128 ( V_7 , F_129 ( & V_168 -> V_132 ) ) ;
}
if ( V_162 -> V_173 & V_222 )
goto V_223;
V_224:
V_53 = V_147 -> V_53 ;
if ( ! V_166 . V_198 )
V_60 = V_166 . V_198 = V_147 -> V_60 ;
if ( ! V_171 ) {
V_75 = F_130 ( V_7 , V_147 , F_106 , V_162 , V_164 ,
sizeof( struct V_83 ) , & V_166 , & V_168 ,
V_162 -> V_173 ) ;
V_100 = F_126 ( V_75 ) ;
if ( ! F_131 ( V_75 ) )
V_100 = F_96 ( V_75 , V_147 ) ;
goto V_108;
}
F_107 ( V_7 ) ;
if ( F_56 ( V_128 -> V_129 ) ) {
F_109 ( V_7 ) ;
F_132 ( L_1 ) ;
V_100 = - V_185 ;
goto V_108;
}
V_147 = & V_64 -> V_157 . V_158 . V_159 . V_160 ;
V_147 -> V_60 = V_60 ;
V_147 -> V_53 = V_53 ;
V_147 -> V_150 = V_61 ;
V_147 -> V_225 = V_64 -> V_149 ;
V_128 -> V_129 = V_184 ;
V_186:
V_128 -> V_130 += V_164 ;
V_100 = F_133 ( V_7 , V_147 , F_106 , V_162 , V_164 ,
sizeof( struct V_83 ) , & V_166 , & V_168 ,
V_171 ? V_162 -> V_173 | V_174 : V_162 -> V_173 ) ;
if ( V_100 )
F_80 ( V_7 ) ;
else if ( ! V_171 )
V_100 = F_103 ( V_7 ) ;
else if ( F_56 ( F_134 ( & V_7 -> V_226 ) ) )
V_128 -> V_129 = 0 ;
F_109 ( V_7 ) ;
V_108:
F_135 ( V_168 ) ;
if ( free )
F_113 ( V_166 . V_179 ) ;
if ( ! V_100 )
return V_130 ;
if ( V_100 == - V_154 || F_28 ( V_227 , & V_7 -> V_228 -> V_229 ) ) {
F_102 ( F_6 ( V_7 ) ,
V_155 , V_148 ) ;
}
return V_100 ;
V_223:
F_136 ( & V_168 -> V_132 ) ;
if ( ! ( V_162 -> V_173 & V_230 ) || V_130 )
goto V_224;
V_100 = 0 ;
goto V_108;
}
int F_137 ( struct V_6 * V_7 , struct V_231 * V_231 , int V_133 ,
T_8 V_232 , int V_229 )
{
struct V_49 * V_64 = F_32 ( V_7 ) ;
struct V_127 * V_128 = F_7 ( V_7 ) ;
int V_233 ;
if ( V_229 & V_234 )
V_229 |= V_174 ;
if ( ! V_128 -> V_129 ) {
struct V_161 V_162 = { . V_173 = V_229 | V_174 } ;
V_233 = F_105 ( V_7 , & V_162 , 0 ) ;
if ( V_233 < 0 )
return V_233 ;
}
F_107 ( V_7 ) ;
if ( F_56 ( ! V_128 -> V_129 ) ) {
F_109 ( V_7 ) ;
F_132 ( L_2 ) ;
return - V_185 ;
}
V_233 = F_138 ( V_7 , & V_64 -> V_157 . V_158 . V_159 . V_160 ,
V_231 , V_133 , V_232 , V_229 ) ;
if ( V_233 == - V_178 ) {
F_109 ( V_7 ) ;
return F_139 ( V_7 -> V_228 , V_231 , V_133 ,
V_232 , V_229 ) ;
}
if ( V_233 < 0 ) {
F_80 ( V_7 ) ;
goto V_108;
}
V_128 -> V_130 += V_232 ;
if ( ! ( V_128 -> V_172 || ( V_229 & V_174 ) ) )
V_233 = F_103 ( V_7 ) ;
if ( ! V_233 )
V_233 = V_232 ;
V_108:
F_109 ( V_7 ) ;
return V_233 ;
}
static unsigned int F_140 ( struct V_6 * V_7 )
{
struct V_235 V_236 , * V_237 = & V_7 -> V_238 ;
struct V_74 * V_75 ;
unsigned int V_20 ;
F_141 ( & V_236 ) ;
F_27 ( & V_237 -> V_21 ) ;
while ( ( V_75 = F_142 ( V_237 ) ) != NULL &&
F_143 ( V_75 ) ) {
F_144 ( F_6 ( V_7 ) , V_239 ,
F_97 ( V_7 ) ) ;
F_144 ( F_6 ( V_7 ) , V_240 ,
F_97 ( V_7 ) ) ;
F_145 ( & V_7 -> V_241 ) ;
F_146 ( V_75 , V_237 ) ;
F_147 ( & V_236 , V_75 ) ;
}
V_20 = V_75 ? V_75 -> V_130 : 0 ;
F_30 ( & V_237 -> V_21 ) ;
if ( ! F_134 ( & V_236 ) ) {
bool V_242 = F_148 ( V_7 ) ;
F_149 ( & V_236 ) ;
F_150 ( V_7 ) ;
F_151 ( V_7 , V_242 ) ;
}
return V_20 ;
}
int F_152 ( struct V_6 * V_7 , int V_243 , unsigned long V_244 )
{
switch ( V_243 ) {
case V_245 :
{
int V_246 = F_153 ( V_7 ) ;
return F_154 ( V_246 , ( int V_247 * ) V_244 ) ;
}
case V_248 :
{
unsigned int V_246 = F_140 ( V_7 ) ;
if ( V_246 )
V_246 -= sizeof( struct V_83 ) ;
return F_154 ( V_246 , ( int V_247 * ) V_244 ) ;
}
default:
return - V_249 ;
}
return 0 ;
}
int F_155 ( struct V_6 * V_7 , struct V_161 * V_162 , T_8 V_130 , int V_250 ,
int V_229 , int * V_251 )
{
struct V_49 * V_64 = F_32 ( V_7 ) ;
F_110 ( struct V_188 * , sin , V_162 -> V_187 ) ;
struct V_74 * V_75 ;
unsigned int V_164 , V_252 ;
int V_253 , V_254 = 0 ;
int V_100 ;
int V_148 = F_97 ( V_7 ) ;
bool V_255 = false ;
bool V_242 ;
if ( V_229 & V_256 )
return F_156 ( V_7 , V_162 , V_130 , V_251 ) ;
V_257:
V_75 = F_157 ( V_7 , V_229 | ( V_250 ? V_258 : 0 ) ,
& V_253 , & V_254 , & V_100 ) ;
if ( ! V_75 )
goto V_108;
V_164 = V_75 -> V_130 - sizeof( struct V_83 ) ;
V_252 = V_130 ;
if ( V_252 > V_164 )
V_252 = V_164 ;
else if ( V_252 < V_164 )
V_162 -> V_173 |= V_259 ;
if ( V_252 < V_164 || F_158 ( V_75 ) -> V_260 ) {
V_255 = ! F_143 ( V_75 ) ;
if ( ! V_255 )
goto V_261;
}
if ( V_255 || F_159 ( V_75 ) )
V_100 = F_160 ( V_75 , sizeof( struct V_83 ) ,
V_162 , V_252 ) ;
else {
V_100 = F_161 ( V_75 , sizeof( struct V_83 ) ,
V_162 ) ;
if ( V_100 == - V_185 )
goto V_261;
}
if ( F_56 ( V_100 ) ) {
F_162 ( V_75 , F_155 ) ;
if ( ! V_253 ) {
F_145 ( & V_7 -> V_241 ) ;
F_102 ( F_6 ( V_7 ) ,
V_240 , V_148 ) ;
}
goto V_262;
}
if ( ! V_253 )
F_102 ( F_6 ( V_7 ) ,
V_263 , V_148 ) ;
F_163 ( V_162 , V_7 , V_75 ) ;
if ( sin ) {
sin -> V_191 = V_184 ;
sin -> V_196 = F_83 ( V_75 ) -> V_102 ;
sin -> V_194 . V_195 = F_66 ( V_75 ) -> V_53 ;
memset ( sin -> V_264 , 0 , sizeof( sin -> V_264 ) ) ;
* V_251 = sizeof( * sin ) ;
}
if ( V_64 -> V_265 )
F_164 ( V_162 , V_75 , sizeof( struct V_83 ) ) ;
V_100 = V_252 ;
if ( V_229 & V_259 )
V_100 = V_164 ;
V_262:
F_165 ( V_7 , V_75 ) ;
V_108:
return V_100 ;
V_261:
V_242 = F_148 ( V_7 ) ;
if ( ! F_166 ( V_7 , V_75 , V_229 ) ) {
F_102 ( F_6 ( V_7 ) , V_239 , V_148 ) ;
F_102 ( F_6 ( V_7 ) , V_240 , V_148 ) ;
}
F_151 ( V_7 , V_242 ) ;
F_167 () ;
V_162 -> V_173 &= ~ V_259 ;
goto V_257;
}
int F_168 ( struct V_6 * V_7 , int V_229 )
{
struct V_49 * V_64 = F_32 ( V_7 ) ;
V_7 -> V_122 = V_266 ;
V_64 -> V_66 = 0 ;
V_64 -> V_67 = 0 ;
F_169 ( V_7 ) ;
V_7 -> V_16 = 0 ;
if ( ! ( V_7 -> V_267 & V_268 ) )
F_170 ( V_7 ) ;
if ( ! ( V_7 -> V_267 & V_269 ) ) {
V_7 -> V_27 -> V_270 ( V_7 ) ;
V_64 -> V_149 = 0 ;
}
F_171 ( V_7 ) ;
return 0 ;
}
void F_172 ( struct V_6 * V_7 )
{
if ( F_173 ( V_7 ) ) {
struct V_25 * V_26 = V_7 -> V_27 -> V_28 . V_25 ;
struct V_3 * V_4 , * V_19 ;
V_4 = F_25 ( V_26 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_14 ) ;
V_19 = F_31 ( V_26 , F_7 ( V_7 ) -> V_41 ) ;
F_27 ( & V_4 -> V_21 ) ;
if ( F_8 ( V_7 -> V_18 ) )
F_174 ( V_7 ) ;
if ( F_175 ( V_7 ) ) {
V_4 -> V_38 -- ;
F_32 ( V_7 ) -> V_44 = 0 ;
F_35 ( F_6 ( V_7 ) , V_7 -> V_27 , - 1 ) ;
F_12 ( & V_19 -> V_21 ) ;
F_176 ( & F_7 ( V_7 ) -> V_48 ) ;
V_19 -> V_38 -- ;
F_14 ( & V_19 -> V_21 ) ;
}
F_30 ( & V_4 -> V_21 ) ;
}
}
void F_177 ( struct V_6 * V_7 , T_10 V_271 )
{
if ( F_173 ( V_7 ) ) {
struct V_25 * V_26 = V_7 -> V_27 -> V_28 . V_25 ;
struct V_3 * V_4 , * V_19 , * V_272 ;
V_19 = F_31 ( V_26 , F_7 ( V_7 ) -> V_41 ) ;
V_272 = F_31 ( V_26 , V_271 ) ;
F_7 ( V_7 ) -> V_41 = V_271 ;
if ( V_19 != V_272 ||
F_8 ( V_7 -> V_18 ) ) {
V_4 = F_25 ( V_26 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_14 ) ;
F_27 ( & V_4 -> V_21 ) ;
if ( F_8 ( V_7 -> V_18 ) )
F_174 ( V_7 ) ;
if ( V_19 != V_272 ) {
F_12 ( & V_19 -> V_21 ) ;
F_176 ( & F_7 ( V_7 ) -> V_48 ) ;
V_19 -> V_38 -- ;
F_14 ( & V_19 -> V_21 ) ;
F_12 ( & V_272 -> V_21 ) ;
F_38 ( & F_7 ( V_7 ) -> V_48 ,
& V_272 -> V_45 ) ;
V_272 -> V_38 ++ ;
F_14 ( & V_272 -> V_21 ) ;
}
F_30 ( & V_4 -> V_21 ) ;
}
}
}
static void F_178 ( struct V_6 * V_7 )
{
T_10 V_273 = F_40 ( F_6 ( V_7 ) ,
F_32 ( V_7 ) -> V_52 ,
F_32 ( V_7 ) -> V_44 ) ;
F_177 ( V_7 , V_273 ) ;
}
static int F_179 ( struct V_6 * V_7 , struct V_74 * V_75 )
{
int V_274 ;
if ( F_32 ( V_7 ) -> V_66 ) {
F_180 ( V_7 , V_75 ) ;
F_181 ( V_7 , V_75 ) ;
F_182 ( V_7 ) ;
}
V_274 = F_183 ( V_7 , V_75 ) ;
if ( V_274 < 0 ) {
int V_148 = F_97 ( V_7 ) ;
if ( V_274 == - V_275 )
F_144 ( F_6 ( V_7 ) , V_276 ,
V_148 ) ;
F_144 ( F_6 ( V_7 ) , V_240 , V_148 ) ;
F_184 ( V_75 ) ;
F_185 ( V_274 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_186 ( void )
{
if ( ! F_187 ( & V_277 ) )
F_188 ( & V_277 ) ;
}
int F_189 ( struct V_6 * V_7 , struct V_74 * V_75 )
{
struct V_127 * V_128 = F_7 ( V_7 ) ;
int V_274 ;
int V_148 = F_97 ( V_7 ) ;
if ( ! F_190 ( V_7 , V_278 , V_75 ) )
goto V_279;
F_191 ( V_75 ) ;
if ( F_192 ( & V_277 ) && V_128 -> V_280 ) {
int (* F_193)( struct V_6 * V_7 , struct V_74 * V_75 );
F_193 = F_194 ( V_128 -> F_193 ) ;
if ( V_75 -> V_130 > sizeof( struct V_83 ) && F_193 ) {
int V_233 ;
if ( F_143 ( V_75 ) )
goto V_281;
V_233 = F_193 ( V_7 , V_75 ) ;
if ( V_233 <= 0 ) {
F_144 ( F_6 ( V_7 ) ,
V_263 ,
V_148 ) ;
return - V_233 ;
}
}
}
if ( ( V_148 & V_282 ) && F_158 ( V_75 ) -> V_260 ) {
if ( V_128 -> V_283 == 0 ) {
F_132 ( L_3 ,
F_158 ( V_75 ) -> V_284 , V_75 -> V_130 ) ;
goto V_279;
}
if ( F_158 ( V_75 ) -> V_284 < V_128 -> V_283 ) {
F_132 ( L_4 ,
F_158 ( V_75 ) -> V_284 , V_128 -> V_283 ) ;
goto V_279;
}
}
if ( F_8 ( V_7 -> V_285 ) &&
F_143 ( V_75 ) )
goto V_281;
if ( F_195 ( V_7 , V_7 -> V_286 ) ) {
F_144 ( F_6 ( V_7 ) , V_276 ,
V_148 ) ;
goto V_279;
}
V_274 = 0 ;
F_196 ( V_7 , V_75 ) ;
F_197 ( V_7 ) ;
if ( ! F_198 ( V_7 ) )
V_274 = F_179 ( V_7 , V_75 ) ;
else if ( F_199 ( V_7 , V_75 , V_7 -> V_286 ) ) {
F_200 ( V_7 ) ;
goto V_279;
}
F_200 ( V_7 ) ;
return V_274 ;
V_281:
F_144 ( F_6 ( V_7 ) , V_239 , V_148 ) ;
V_279:
F_144 ( F_6 ( V_7 ) , V_240 , V_148 ) ;
F_145 ( & V_7 -> V_241 ) ;
F_184 ( V_75 ) ;
return - 1 ;
}
static void F_201 ( struct V_6 * * V_287 , unsigned int V_38 ,
struct V_74 * V_75 , unsigned int V_288 )
{
unsigned int V_289 ;
struct V_74 * V_290 = NULL ;
struct V_6 * V_7 ;
for ( V_289 = 0 ; V_289 < V_38 ; V_289 ++ ) {
V_7 = V_287 [ V_289 ] ;
if ( F_108 ( ! V_290 ) )
V_290 = ( V_289 == V_288 ) ? V_75 : F_202 ( V_75 , V_291 ) ;
if ( ! V_290 ) {
F_145 ( & V_7 -> V_241 ) ;
F_144 ( F_6 ( V_7 ) , V_276 ,
F_97 ( V_7 ) ) ;
F_144 ( F_6 ( V_7 ) , V_240 ,
F_97 ( V_7 ) ) ;
}
if ( V_290 && F_189 ( V_7 , V_290 ) <= 0 )
V_290 = NULL ;
F_58 ( V_7 ) ;
}
if ( F_56 ( V_290 ) )
F_184 ( V_290 ) ;
}
static void F_203 ( struct V_6 * V_7 , struct V_292 * V_132 )
{
struct V_292 * V_293 ;
F_204 ( V_132 ) ;
V_293 = F_205 ( & V_7 -> V_294 , V_132 ) ;
F_206 ( V_293 ) ;
}
static int F_207 ( struct V_1 * V_1 , struct V_74 * V_75 ,
struct V_83 * V_96 ,
T_4 V_53 , T_4 V_60 ,
struct V_25 * V_26 ,
int V_295 )
{
struct V_6 * V_7 , * V_287 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_11 * V_12 ;
unsigned short V_58 = F_60 ( V_96 -> V_101 ) ;
struct V_3 * V_4 = F_25 ( V_26 , V_1 , V_58 ) ;
int V_62 = V_75 -> V_89 -> V_103 ;
unsigned int V_38 = 0 , V_133 = F_87 ( F_208 ( * V_7 ) , V_296 ) ;
unsigned int V_85 = 0 , V_297 = 0 , V_298 = ( V_4 -> V_38 > 10 ) ;
bool V_299 = false ;
if ( V_298 ) {
V_297 = F_40 ( V_1 , F_44 ( V_56 ) , V_58 ) &
V_25 . V_35 ;
V_85 = F_40 ( V_1 , V_60 , V_58 ) & V_25 . V_35 ;
V_300:
V_4 = & V_25 . V_85 [ V_85 ] ;
V_133 = F_87 ( F_208 ( * V_7 ) , V_301 . V_302 ) ;
}
F_12 ( & V_4 -> V_21 ) ;
F_209 (sk, node, &hslot->head, offset) {
if ( F_71 ( V_1 , V_7 ,
V_96 -> V_101 , V_60 ,
V_96 -> V_102 , V_53 ,
V_62 , V_58 ) ) {
if ( F_56 ( V_38 == F_210 ( V_287 ) ) ) {
F_201 ( V_287 , V_38 , V_75 , ~ 0 ) ;
V_299 = true ;
V_38 = 0 ;
}
V_287 [ V_38 ++ ] = V_7 ;
F_211 ( V_7 ) ;
}
}
F_14 ( & V_4 -> V_21 ) ;
if ( V_298 && V_85 != V_297 ) {
V_85 = V_297 ;
goto V_300;
}
if ( V_38 ) {
F_201 ( V_287 , V_38 , V_75 , V_38 - 1 ) ;
} else {
if ( ! V_299 )
F_144 ( V_1 , V_303 ,
V_295 == V_304 ) ;
F_212 ( V_75 ) ;
}
return 0 ;
}
static inline int F_213 ( struct V_74 * V_75 , struct V_83 * V_96 ,
int V_295 )
{
int V_100 ;
F_158 ( V_75 ) -> V_260 = 0 ;
F_158 ( V_75 ) -> V_284 = V_75 -> V_130 ;
if ( V_295 == V_304 ) {
V_100 = F_214 ( V_75 , V_96 ) ;
if ( V_100 )
return V_100 ;
}
return F_215 ( V_75 , V_295 , V_96 -> V_138 ,
V_305 ) ;
}
int F_216 ( struct V_74 * V_75 , struct V_25 * V_26 ,
int V_295 )
{
struct V_6 * V_7 ;
struct V_83 * V_96 ;
unsigned short V_164 ;
struct V_167 * V_168 = F_217 ( V_75 ) ;
T_4 V_53 , V_60 ;
struct V_1 * V_1 = F_67 ( V_75 -> V_89 ) ;
if ( ! F_218 ( V_75 , sizeof( struct V_83 ) ) )
goto V_279;
V_96 = F_83 ( V_75 ) ;
V_164 = F_60 ( V_96 -> V_130 ) ;
V_53 = F_66 ( V_75 ) -> V_53 ;
V_60 = F_66 ( V_75 ) -> V_60 ;
if ( V_164 > V_75 -> V_130 )
goto V_306;
if ( V_295 == V_139 ) {
if ( V_164 < sizeof( * V_96 ) || F_219 ( V_75 , V_164 ) )
goto V_306;
V_96 = F_83 ( V_75 ) ;
}
if ( F_213 ( V_75 , V_96 , V_295 ) )
goto V_281;
V_7 = F_220 ( V_75 ) ;
if ( V_7 ) {
struct V_292 * V_132 = F_68 ( V_75 ) ;
int V_233 ;
if ( F_56 ( V_7 -> V_294 != V_132 ) )
F_203 ( V_7 , V_132 ) ;
V_233 = F_189 ( V_7 , V_75 ) ;
F_58 ( V_7 ) ;
if ( V_233 > 0 )
return - V_233 ;
return 0 ;
}
if ( V_168 -> V_219 & ( V_220 | V_307 ) )
return F_207 ( V_1 , V_75 , V_96 ,
V_53 , V_60 , V_26 , V_295 ) ;
V_7 = F_65 ( V_75 , V_96 -> V_102 , V_96 -> V_101 , V_26 ) ;
if ( V_7 ) {
int V_233 ;
if ( F_221 ( V_7 ) && V_96 -> V_138 && ! F_97 ( V_7 ) )
F_222 ( V_75 , V_139 , V_96 -> V_138 ,
V_305 ) ;
V_233 = F_189 ( V_7 , V_75 ) ;
F_58 ( V_7 ) ;
if ( V_233 > 0 )
return - V_233 ;
return 0 ;
}
if ( ! F_190 ( NULL , V_278 , V_75 ) )
goto V_279;
F_191 ( V_75 ) ;
if ( F_143 ( V_75 ) )
goto V_281;
F_144 ( V_1 , V_308 , V_295 == V_304 ) ;
F_223 ( V_75 , V_111 , V_309 , 0 ) ;
F_184 ( V_75 ) ;
return 0 ;
V_306:
F_132 ( L_5 ,
V_295 == V_304 ? L_6 : L_7 ,
& V_53 , F_60 ( V_96 -> V_102 ) ,
V_164 , V_75 -> V_130 ,
& V_60 , F_60 ( V_96 -> V_101 ) ) ;
goto V_279;
V_281:
F_132 ( L_8 ,
V_295 == V_304 ? L_6 : L_7 ,
& V_53 , F_60 ( V_96 -> V_102 ) , & V_60 , F_60 ( V_96 -> V_101 ) ,
V_164 ) ;
F_144 ( V_1 , V_239 , V_295 == V_304 ) ;
V_279:
F_144 ( V_1 , V_240 , V_295 == V_304 ) ;
F_184 ( V_75 ) ;
return 0 ;
}
static struct V_6 * F_224 ( struct V_1 * V_1 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_62 )
{
struct V_6 * V_7 , * V_76 ;
struct V_11 * V_12 ;
unsigned short V_58 = F_60 ( V_90 ) ;
unsigned int V_38 , V_86 = F_61 ( V_1 , V_58 , V_25 . V_35 ) ;
struct V_3 * V_4 = & V_25 . V_81 [ V_86 ] ;
if ( V_4 -> V_38 > 10 )
return NULL ;
F_62 () ;
V_82:
V_38 = 0 ;
V_76 = NULL ;
F_64 (sk, node, &hslot->head) {
if ( F_71 ( V_1 , V_7 ,
V_90 , V_91 ,
V_92 , V_93 ,
V_62 , V_58 ) ) {
V_76 = V_7 ;
++ V_38 ;
}
}
if ( F_55 ( V_12 ) != V_86 )
goto V_82;
if ( V_76 ) {
if ( V_38 != 1 ||
F_56 ( ! F_57 ( & V_76 -> V_84 , 2 ) ) )
V_76 = NULL ;
else if ( F_56 ( ! F_71 ( V_1 , V_76 ,
V_90 , V_91 ,
V_92 , V_93 ,
V_62 , V_58 ) ) ) {
F_58 ( V_76 ) ;
V_76 = NULL ;
}
}
F_63 () ;
return V_76 ;
}
static struct V_6 * F_225 ( struct V_1 * V_1 ,
T_5 V_90 , T_4 V_91 ,
T_5 V_92 , T_4 V_93 ,
int V_62 )
{
struct V_6 * V_7 , * V_76 ;
struct V_11 * V_12 ;
unsigned short V_58 = F_60 ( V_90 ) ;
unsigned int V_85 = F_40 ( V_1 , V_91 , V_58 ) ;
unsigned int V_40 = V_85 & V_25 . V_35 ;
struct V_3 * V_19 = & V_25 . V_85 [ V_40 ] ;
F_226 ( V_310 , V_93 , V_91 ) ;
const T_11 V_311 = F_227 ( V_92 , V_58 ) ;
F_62 () ;
V_76 = NULL ;
F_52 (sk, node, &hslot2->head) {
if ( F_228 ( V_7 , V_1 , V_310 ,
V_93 , V_91 , V_311 , V_62 ) )
V_76 = V_7 ;
break;
}
if ( V_76 ) {
if ( F_56 ( ! F_57 ( & V_76 -> V_84 , 2 ) ) )
V_76 = NULL ;
else if ( F_56 ( ! F_228 ( V_7 , V_1 , V_310 ,
V_93 , V_91 ,
V_311 , V_62 ) ) ) {
F_58 ( V_76 ) ;
V_76 = NULL ;
}
}
F_63 () ;
return V_76 ;
}
void F_229 ( struct V_74 * V_75 )
{
struct V_1 * V_1 = F_67 ( V_75 -> V_89 ) ;
const struct V_87 * V_88 ;
const struct V_83 * V_96 ;
struct V_6 * V_7 ;
struct V_292 * V_132 ;
int V_62 = V_75 -> V_89 -> V_103 ;
int V_312 ;
if ( ! F_218 ( V_75 , F_84 ( V_75 ) + sizeof( struct V_83 ) ) )
return;
V_88 = F_66 ( V_75 ) ;
V_96 = F_83 ( V_75 ) ;
if ( V_75 -> V_313 == V_314 ||
V_75 -> V_313 == V_315 ) {
struct V_316 * V_317 = F_230 ( V_75 -> V_89 ) ;
if ( ! V_317 )
return;
if ( V_75 -> V_313 == V_315 ) {
V_312 = F_231 ( V_317 , V_88 -> V_60 , V_88 -> V_53 ,
V_88 -> V_318 ) ;
if ( ! V_312 )
return;
}
V_7 = F_224 ( V_1 , V_96 -> V_101 , V_88 -> V_60 ,
V_96 -> V_102 , V_88 -> V_53 , V_62 ) ;
} else if ( V_75 -> V_313 == V_319 ) {
V_7 = F_225 ( V_1 , V_96 -> V_101 , V_88 -> V_60 ,
V_96 -> V_102 , V_88 -> V_53 , V_62 ) ;
} else {
return;
}
if ( ! V_7 )
return;
V_75 -> V_7 = V_7 ;
V_75 -> V_320 = V_321 ;
V_132 = F_232 ( V_7 -> V_294 ) ;
if ( V_132 )
V_132 = F_233 ( V_132 , 0 ) ;
if ( V_132 ) {
if ( V_132 -> V_229 & V_322 ) {
if ( F_108 ( F_234 ( & V_132 -> V_323 ) ) )
F_235 ( V_75 , V_132 ) ;
} else {
F_236 ( V_75 , V_132 ) ;
}
}
}
int F_237 ( struct V_74 * V_75 )
{
return F_216 ( V_75 , & V_25 , V_139 ) ;
}
void F_238 ( struct V_6 * V_7 )
{
struct V_127 * V_128 = F_7 ( V_7 ) ;
bool V_242 = F_148 ( V_7 ) ;
F_80 ( V_7 ) ;
F_151 ( V_7 , V_242 ) ;
if ( F_192 ( & V_277 ) && V_128 -> V_280 ) {
void (* F_239)( struct V_6 * V_7 );
F_239 = F_194 ( V_128 -> F_239 ) ;
if ( F_239 )
F_239 ( V_7 ) ;
}
}
int F_240 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_247 * V_326 , unsigned int V_204 ,
int (* F_241)( struct V_6 * ) )
{
struct V_127 * V_128 = F_7 ( V_7 ) ;
int V_327 , V_328 ;
int V_100 = 0 ;
int V_148 = F_97 ( V_7 ) ;
if ( V_204 < sizeof( int ) )
return - V_185 ;
if ( F_242 ( V_327 , ( int V_247 * ) V_326 ) )
return - V_329 ;
V_328 = V_327 ? 1 : 0 ;
switch ( V_325 ) {
case V_330 :
if ( V_327 != 0 ) {
V_128 -> V_172 = 1 ;
} else {
V_128 -> V_172 = 0 ;
F_107 ( V_7 ) ;
F_241 ( V_7 ) ;
F_109 ( V_7 ) ;
}
break;
case V_331 :
switch ( V_327 ) {
case 0 :
case V_332 :
case V_333 :
V_128 -> F_193 = V_334 ;
case V_335 :
V_128 -> V_280 = V_327 ;
F_186 () ;
break;
default:
V_100 = - V_336 ;
break;
}
break;
case V_337 :
V_128 -> V_338 = V_328 ;
break;
case V_339 :
V_128 -> V_340 = V_328 ;
break;
case V_341 :
if ( ! V_148 )
return - V_336 ;
if ( V_327 != 0 && V_327 < 8 )
V_327 = 8 ;
else if ( V_327 > V_342 )
V_327 = V_342 ;
V_128 -> V_343 = V_327 ;
V_128 -> V_344 |= V_345 ;
break;
case V_346 :
if ( ! V_148 )
return - V_336 ;
if ( V_327 != 0 && V_327 < 8 )
V_327 = 8 ;
else if ( V_327 > V_342 )
V_327 = V_342 ;
V_128 -> V_283 = V_327 ;
V_128 -> V_344 |= V_282 ;
break;
default:
V_100 = - V_336 ;
break;
}
return V_100 ;
}
int F_243 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_247 * V_326 , unsigned int V_204 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_240 ( V_7 , V_324 , V_325 , V_326 , V_204 ,
F_103 ) ;
return F_244 ( V_7 , V_324 , V_325 , V_326 , V_204 ) ;
}
int F_245 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_247 * V_326 , unsigned int V_204 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_240 ( V_7 , V_324 , V_325 , V_326 , V_204 ,
F_103 ) ;
return F_246 ( V_7 , V_324 , V_325 , V_326 , V_204 ) ;
}
int F_247 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_247 * V_326 , int V_247 * V_204 )
{
struct V_127 * V_128 = F_7 ( V_7 ) ;
int V_327 , V_130 ;
if ( F_242 ( V_130 , V_204 ) )
return - V_329 ;
V_130 = F_248 (unsigned int, len, sizeof(int)) ;
if ( V_130 < 0 )
return - V_185 ;
switch ( V_325 ) {
case V_330 :
V_327 = V_128 -> V_172 ;
break;
case V_331 :
V_327 = V_128 -> V_280 ;
break;
case V_337 :
V_327 = V_128 -> V_338 ;
break;
case V_339 :
V_327 = V_128 -> V_340 ;
break;
case V_341 :
V_327 = V_128 -> V_343 ;
break;
case V_346 :
V_327 = V_128 -> V_283 ;
break;
default:
return - V_336 ;
}
if ( F_154 ( V_130 , V_204 ) )
return - V_329 ;
if ( F_249 ( V_326 , & V_327 , V_130 ) )
return - V_329 ;
return 0 ;
}
int F_250 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_247 * V_326 , int V_247 * V_204 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_247 ( V_7 , V_324 , V_325 , V_326 , V_204 ) ;
return F_251 ( V_7 , V_324 , V_325 , V_326 , V_204 ) ;
}
int F_252 ( struct V_6 * V_7 , int V_324 , int V_325 ,
char V_247 * V_326 , int V_247 * V_204 )
{
if ( V_324 == V_347 || V_324 == V_348 )
return F_247 ( V_7 , V_324 , V_325 , V_326 , V_204 ) ;
return F_253 ( V_7 , V_324 , V_325 , V_326 , V_204 ) ;
}
unsigned int F_254 ( struct V_349 * V_349 , struct V_350 * V_6 , T_12 * V_351 )
{
unsigned int V_35 = F_255 ( V_349 , V_6 , V_351 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
F_256 ( V_7 ) ;
if ( ( V_35 & V_352 ) && ! ( V_349 -> V_353 & V_354 ) &&
! ( V_7 -> V_355 & V_356 ) && ! F_140 ( V_7 ) )
V_35 &= ~ ( V_357 | V_352 ) ;
return V_35 ;
}
static struct V_6 * F_257 ( struct V_358 * V_359 , int V_360 )
{
struct V_6 * V_7 ;
struct V_361 * V_362 = V_359 -> V_363 ;
struct V_1 * V_1 = F_258 ( V_359 ) ;
for ( V_362 -> V_364 = V_360 ; V_362 -> V_364 <= V_362 -> V_25 -> V_35 ;
++ V_362 -> V_364 ) {
struct V_11 * V_12 ;
struct V_3 * V_4 = & V_362 -> V_25 -> V_81 [ V_362 -> V_364 ] ;
if ( F_259 ( & V_4 -> V_45 ) )
continue;
F_27 ( & V_4 -> V_21 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_22 == V_362 -> V_365 )
goto V_36;
}
F_30 ( & V_4 -> V_21 ) ;
}
V_7 = NULL ;
V_36:
return V_7 ;
}
static struct V_6 * F_260 ( struct V_358 * V_359 , struct V_6 * V_7 )
{
struct V_361 * V_362 = V_359 -> V_363 ;
struct V_1 * V_1 = F_258 ( V_359 ) ;
do {
V_7 = F_261 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_22 != V_362 -> V_365 ) );
if ( ! V_7 ) {
if ( V_362 -> V_364 <= V_362 -> V_25 -> V_35 )
F_30 ( & V_362 -> V_25 -> V_81 [ V_362 -> V_364 ] . V_21 ) ;
return F_257 ( V_359 , V_362 -> V_364 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_262 ( struct V_358 * V_359 , T_13 V_366 )
{
struct V_6 * V_7 = F_257 ( V_359 , 0 ) ;
if ( V_7 )
while ( V_366 && ( V_7 = F_260 ( V_359 , V_7 ) ) != NULL )
-- V_366 ;
return V_366 ? NULL : V_7 ;
}
static void * F_263 ( struct V_358 * V_359 , T_13 * V_366 )
{
struct V_361 * V_362 = V_359 -> V_363 ;
V_362 -> V_364 = V_367 ;
return * V_366 ? F_262 ( V_359 , * V_366 - 1 ) : V_368 ;
}
static void * F_264 ( struct V_358 * V_359 , void * V_369 , T_13 * V_366 )
{
struct V_6 * V_7 ;
if ( V_369 == V_368 )
V_7 = F_262 ( V_359 , 0 ) ;
else
V_7 = F_260 ( V_359 , V_369 ) ;
++ * V_366 ;
return V_7 ;
}
static void F_265 ( struct V_358 * V_359 , void * V_369 )
{
struct V_361 * V_362 = V_359 -> V_363 ;
if ( V_362 -> V_364 <= V_362 -> V_25 -> V_35 )
F_30 ( & V_362 -> V_25 -> V_81 [ V_362 -> V_364 ] . V_21 ) ;
}
int F_266 ( struct V_370 * V_370 , struct V_349 * V_349 )
{
struct V_371 * V_372 = F_267 ( V_370 ) ;
struct V_361 * V_373 ;
int V_100 ;
V_100 = F_268 ( V_370 , V_349 , & V_372 -> V_374 ,
sizeof( struct V_361 ) ) ;
if ( V_100 < 0 )
return V_100 ;
V_373 = ( (struct V_358 * ) V_349 -> V_375 ) -> V_363 ;
V_373 -> V_365 = V_372 -> V_365 ;
V_373 -> V_25 = V_372 -> V_25 ;
return V_100 ;
}
int F_269 ( struct V_1 * V_1 , struct V_371 * V_372 )
{
struct V_376 * V_377 ;
int V_274 = 0 ;
V_372 -> V_374 . V_360 = F_263 ;
V_372 -> V_374 . V_378 = F_264 ;
V_372 -> V_374 . V_379 = F_265 ;
V_377 = F_270 ( V_372 -> V_380 , V_381 , V_1 -> V_382 ,
V_372 -> V_383 , V_372 ) ;
if ( ! V_377 )
V_274 = - V_275 ;
return V_274 ;
}
void F_271 ( struct V_1 * V_1 , struct V_371 * V_372 )
{
F_272 ( V_372 -> V_380 , V_1 -> V_382 ) ;
}
static void F_273 ( struct V_6 * V_384 , struct V_358 * V_385 ,
int V_364 )
{
struct V_49 * V_64 = F_32 ( V_384 ) ;
T_4 V_101 = V_64 -> V_66 ;
T_4 V_131 = V_64 -> V_52 ;
T_1 V_386 = F_60 ( V_64 -> V_67 ) ;
T_1 V_387 = F_60 ( V_64 -> V_149 ) ;
F_274 ( V_385 , L_9
L_10 ,
V_364 , V_131 , V_387 , V_101 , V_386 , V_384 -> V_122 ,
F_153 ( V_384 ) ,
F_275 ( V_384 ) ,
0 , 0L , 0 ,
F_276 ( F_277 ( V_385 ) , F_3 ( V_384 ) ) ,
0 , F_278 ( V_384 ) ,
F_279 ( & V_384 -> V_84 ) , V_384 ,
F_279 ( & V_384 -> V_241 ) ) ;
}
int F_280 ( struct V_358 * V_359 , void * V_369 )
{
F_281 ( V_359 , 127 ) ;
if ( V_369 == V_368 )
F_282 ( V_359 , L_11
L_12
L_13 ) ;
else {
struct V_361 * V_362 = V_359 -> V_363 ;
F_273 ( V_369 , V_359 , V_362 -> V_364 ) ;
}
F_283 ( V_359 , '\n' ) ;
return 0 ;
}
static int T_14 F_284 ( struct V_1 * V_1 )
{
return F_269 ( V_1 , & V_388 ) ;
}
static void T_15 F_285 ( struct V_1 * V_1 )
{
F_271 ( V_1 , & V_388 ) ;
}
int T_16 F_286 ( void )
{
return F_287 ( & V_389 ) ;
}
void F_288 ( void )
{
F_289 ( & V_389 ) ;
}
static int T_16 F_290 ( char * V_390 )
{
T_17 V_233 ;
if ( ! V_390 )
return 0 ;
V_233 = F_291 ( V_390 , 0 , & V_391 ) ;
if ( V_233 )
return 0 ;
if ( V_391 && V_391 < V_392 )
V_391 = V_392 ;
return 1 ;
}
void T_16 F_292 ( struct V_25 * V_393 , const char * V_380 )
{
unsigned int V_289 ;
V_393 -> V_81 = F_293 ( V_380 ,
2 * sizeof( struct V_3 ) ,
V_391 ,
21 ,
0 ,
& V_393 -> log ,
& V_393 -> V_35 ,
V_392 ,
64 * 1024 ) ;
V_393 -> V_85 = V_393 -> V_81 + ( V_393 -> V_35 + 1 ) ;
for ( V_289 = 0 ; V_289 <= V_393 -> V_35 ; V_289 ++ ) {
F_294 ( & V_393 -> V_81 [ V_289 ] . V_45 , V_289 ) ;
V_393 -> V_81 [ V_289 ] . V_38 = 0 ;
F_295 ( & V_393 -> V_81 [ V_289 ] . V_21 ) ;
}
for ( V_289 = 0 ; V_289 <= V_393 -> V_35 ; V_289 ++ ) {
F_294 ( & V_393 -> V_85 [ V_289 ] . V_45 , V_289 ) ;
V_393 -> V_85 [ V_289 ] . V_38 = 0 ;
F_295 ( & V_393 -> V_85 [ V_289 ] . V_21 ) ;
}
}
T_3 F_296 ( void )
{
static T_3 T_18 V_73 ;
F_49 ( & T_18 , sizeof( T_18 ) ) ;
return T_18 ;
}
void T_16 F_297 ( void )
{
unsigned long V_394 ;
F_292 ( & V_25 , L_14 ) ;
V_394 = F_298 () / 8 ;
V_394 = F_299 ( V_394 , 128UL ) ;
V_395 [ 0 ] = V_394 / 4 * 3 ;
V_395 [ 1 ] = V_394 ;
V_395 [ 2 ] = V_395 [ 0 ] * 2 ;
V_396 = V_397 ;
V_398 = V_397 ;
}
