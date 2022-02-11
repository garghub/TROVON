void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_11 * V_12 = & V_10 -> V_13 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_15 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | 0x01 ) ;
V_2 -> V_18 [ V_6 ] = NULL ;
V_2 -> V_7 ++ ;
if ( V_3 ) {
V_12 -> V_19 = V_20 ;
F_4 ( V_2 , V_10 , 0 ) ;
}
}
static inline void F_5 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
switch ( V_24 -> type ) {
case V_25 :
F_6 ( V_22 , V_24 -> V_26 , V_24 -> V_27 , V_28 ) ;
break;
case V_29 :
F_7 ( V_22 , V_24 -> V_26 , V_24 -> V_27 , V_28 ) ;
break;
default:
F_8 ( true , L_1 ) ;
}
}
static inline void F_9 ( struct V_1 * V_2 ,
T_2 V_26 ,
T_3 V_27 ,
enum V_30 V_31 )
{
V_2 -> V_32 [ V_2 -> V_33 & V_2 -> V_34 ] . V_26 = V_26 ;
V_2 -> V_32 [ V_2 -> V_33 & V_2 -> V_34 ] . V_27 = V_27 ;
V_2 -> V_32 [ V_2 -> V_33 & V_2 -> V_34 ] . type = V_31 ;
V_2 -> V_33 ++ ;
}
static inline struct V_23 * F_10 ( struct V_1 * V_2 , T_3 V_35 )
{
return & V_2 -> V_32 [ V_35 & V_2 -> V_34 ] ;
}
static void F_11 ( struct V_1 * V_2 , T_4 V_36 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
struct V_23 * V_37 =
F_10 ( V_2 , -- V_2 -> V_33 ) ;
F_5 ( V_2 -> V_22 , V_37 ) ;
}
}
T_1 F_12 ( struct V_38 * V_39 , struct V_40 * V_18 ,
void * V_41 , T_5 V_42 )
{
struct V_43 * V_44 = F_13 ( V_39 ) ;
int V_45 = V_42 ( V_39 , V_18 ) ;
int V_46 = F_14 ( V_18 ) ?
V_18 -> V_47 >> V_48 :
V_44 -> V_49 ;
int V_50 = F_15 ( V_39 , V_46 ) ;
return V_44 -> V_51 [ V_45 ] [ V_50 ] ;
}
static inline T_1 F_16 ( struct V_1 * V_2 ,
struct V_40 * V_18 , bool V_52 )
{
#define F_17 ETH_HLEN
if ( V_52 ) {
T_1 V_53 = F_18 ( V_18 ) ;
if ( F_14 ( V_18 ) )
V_53 += V_54 ;
if ( V_53 <= V_2 -> V_55 )
return F_18 ( V_18 ) ;
}
return F_17 ;
}
static inline void F_19 ( unsigned char * * V_56 ,
unsigned int * V_57 ,
unsigned int V_58 )
{
* V_57 -= V_58 ;
* V_56 += V_58 ;
}
static inline void F_20 ( void * V_59 , struct V_40 * V_18 , T_1 V_53 ,
unsigned char * * V_56 ,
unsigned int * V_57 )
{
struct V_60 * V_61 = (struct V_60 * ) V_59 ;
int V_62 = 2 * V_63 ;
int V_64 = V_53 - V_62 ;
memcpy ( V_61 , * V_56 , V_62 ) ;
F_19 ( V_56 , V_57 , V_62 ) ;
V_61 -> V_65 = V_18 -> V_66 ;
V_61 -> V_67 = F_21 ( F_22 ( V_18 ) ) ;
memcpy ( & V_61 -> V_68 , * V_56 , V_64 ) ;
F_19 ( V_56 , V_57 , V_64 ) ;
}
static T_6 F_23 ( struct V_1 * V_2 , struct V_40 * V_18 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_69 * V_70 = & V_2 -> V_71 [ V_6 ] ;
struct V_11 * V_12 = & V_10 -> V_13 ;
struct V_72 * V_73 = & V_10 -> V_74 ;
struct V_75 * V_76 ;
unsigned char * V_56 = V_18 -> V_77 ;
unsigned int V_57 = V_18 -> V_58 ;
T_4 V_78 = V_79 ;
T_2 V_80 = 0 ;
unsigned int V_81 ;
bool V_52 = false ;
T_1 V_82 ;
T_1 V_83 ;
T_1 V_53 ;
int V_35 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( F_24 ( V_18 -> V_84 == V_85 ) )
V_73 -> V_86 = V_87 | V_88 ;
else
V_2 -> V_89 . V_90 ++ ;
if ( V_2 -> V_91 != V_2 -> V_92 ) {
V_2 -> V_92 = V_2 -> V_91 ;
V_2 -> V_93 = ( V_2 -> V_91 == V_2 -> V_7 ) ? V_94 : 0 ;
}
if ( F_25 ( V_18 ) ) {
T_3 V_95 ;
V_73 -> V_96 = F_21 ( F_26 ( V_18 ) -> V_97 ) ;
V_78 = V_98 ;
V_53 = F_27 ( V_18 ) + F_28 ( V_18 ) ;
V_95 = V_18 -> V_58 - V_53 ;
V_81 = V_18 -> V_58 + ( F_26 ( V_18 ) -> V_99 - 1 ) * V_53 ;
V_2 -> V_89 . V_100 ++ ;
V_2 -> V_89 . V_101 += V_95 ;
} else {
V_52 = V_2 -> V_93 &&
! V_18 -> V_102 &&
! F_26 ( V_18 ) -> V_103 ;
V_53 = F_16 ( V_2 , V_18 , V_52 ) ;
V_81 = F_29 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_70 -> V_81 = V_81 ;
if ( F_14 ( V_18 ) ) {
F_20 ( V_73 -> V_104 , V_18 , V_53 , & V_56 ,
& V_57 ) ;
V_53 += V_54 ;
} else {
memcpy ( V_73 -> V_104 , V_56 , V_53 ) ;
F_19 ( & V_56 , & V_57 , V_53 ) ;
}
V_73 -> V_105 = F_21 ( V_53 ) ;
V_83 = sizeof( * V_10 ) / V_106 ;
V_83 += F_30 ( V_53 - sizeof( V_73 -> V_104 ) ,
V_106 ) ;
V_76 = (struct V_75 * ) V_12 + V_83 ;
V_70 -> V_36 = 0 ;
V_82 = V_57 - V_18 -> V_107 ;
if ( V_82 ) {
V_80 = F_31 ( V_2 -> V_22 , V_56 , V_82 ,
V_28 ) ;
if ( F_32 ( F_33 ( V_2 -> V_22 , V_80 ) ) )
goto V_108;
V_76 -> V_26 = F_34 ( V_80 ) ;
V_76 -> V_109 = V_2 -> V_110 ;
V_76 -> V_111 = F_3 ( V_82 ) ;
F_9 ( V_2 , V_80 , V_82 , V_25 ) ;
V_70 -> V_36 ++ ;
V_76 ++ ;
}
for ( V_35 = 0 ; V_35 < F_26 ( V_18 ) -> V_103 ; V_35 ++ ) {
struct V_112 * V_113 = & F_26 ( V_18 ) -> V_114 [ V_35 ] ;
int V_115 = F_35 ( V_113 ) ;
V_80 = F_36 ( V_2 -> V_22 , V_113 , 0 , V_115 ,
V_28 ) ;
if ( F_32 ( F_33 ( V_2 -> V_22 , V_80 ) ) )
goto V_108;
V_76 -> V_26 = F_34 ( V_80 ) ;
V_76 -> V_109 = V_2 -> V_110 ;
V_76 -> V_111 = F_3 ( V_115 ) ;
F_9 ( V_2 , V_80 , V_115 , V_29 ) ;
V_70 -> V_36 ++ ;
V_76 ++ ;
}
V_83 += V_70 -> V_36 ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_78 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | V_83 ) ;
V_2 -> V_18 [ V_6 ] = V_18 ;
V_70 -> V_116 = F_30 ( V_83 , V_117 ) ;
V_2 -> V_7 += V_70 -> V_116 ;
F_37 ( V_2 -> V_118 , V_70 -> V_81 ) ;
if ( F_32 ( F_26 ( V_18 ) -> V_119 & V_120 ) )
F_26 ( V_18 ) -> V_119 |= V_121 ;
if ( F_32 ( ! F_38 ( V_2 , V_122 ) ) ) {
F_39 ( V_2 -> V_118 ) ;
V_2 -> V_89 . V_123 ++ ;
}
if ( ! V_18 -> V_102 || F_40 ( V_2 -> V_118 ) ) {
int V_124 = 0 ;
if ( V_52 && V_2 -> V_125 )
V_124 = V_70 -> V_116 << 3 ;
V_12 -> V_19 = V_20 ;
F_4 ( V_2 , V_10 , V_124 ) ;
}
while ( ( V_2 -> V_7 & V_5 -> V_8 ) > V_2 -> V_126 )
F_1 ( V_2 , false ) ;
V_2 -> V_93 = V_52 ? V_2 -> V_93 - 1 : 0 ;
V_2 -> V_89 . V_127 ++ ;
V_2 -> V_89 . V_128 += V_81 ;
return V_129 ;
V_108:
V_2 -> V_89 . V_130 ++ ;
F_11 ( V_2 , V_70 -> V_36 ) ;
F_41 ( V_18 ) ;
return V_129 ;
}
T_6 F_42 ( struct V_40 * V_18 , struct V_38 * V_39 )
{
struct V_43 * V_44 = F_13 ( V_39 ) ;
struct V_1 * V_2 = V_44 -> V_131 [ F_43 ( V_18 ) ] ;
return F_23 ( V_2 , V_18 ) ;
}
bool F_44 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
T_3 V_134 ;
T_3 V_135 ;
T_1 V_136 ;
T_1 V_137 ;
int V_35 ;
V_2 = F_45 ( V_133 , struct V_1 , V_133 ) ;
V_136 = 0 ;
V_135 = 0 ;
V_137 = V_2 -> V_91 ;
V_134 = V_2 -> V_134 ;
for ( V_35 = 0 ; V_35 < V_138 ; V_35 ++ ) {
struct V_139 * V_140 ;
T_1 V_141 ;
bool V_142 ;
V_140 = F_46 ( V_133 ) ;
if ( ! V_140 )
break;
F_47 ( & V_133 -> V_5 ) ;
V_141 = F_48 ( V_140 -> V_141 ) ;
do {
struct V_69 * V_70 ;
struct V_40 * V_18 ;
T_1 V_143 ;
int V_144 ;
V_142 = ( V_137 == V_141 ) ;
V_143 = V_137 & V_2 -> V_5 . V_8 ;
V_18 = V_2 -> V_18 [ V_143 ] ;
V_70 = & V_2 -> V_71 [ V_143 ] ;
if ( F_32 ( ! V_18 ) ) {
V_2 -> V_89 . V_145 ++ ;
V_137 ++ ;
continue;
}
if ( F_32 ( F_26 ( V_18 ) -> V_119 &
V_120 ) ) {
struct V_146 V_147 = {} ;
F_49 ( V_2 -> V_148 ,
F_50 ( V_140 ) , & V_147 ) ;
F_51 ( V_18 , & V_147 ) ;
}
for ( V_144 = 0 ; V_144 < V_70 -> V_36 ; V_144 ++ ) {
struct V_23 * V_24 =
F_10 ( V_2 , V_134 ++ ) ;
F_5 ( V_2 -> V_22 , V_24 ) ;
}
V_136 ++ ;
V_135 += V_70 -> V_81 ;
V_137 += V_70 -> V_116 ;
F_52 ( V_18 ) ;
} while ( ! V_142 );
}
F_53 ( & V_133 -> V_5 ) ;
F_54 () ;
V_2 -> V_134 = V_134 ;
V_2 -> V_91 = V_137 ;
F_55 ( V_2 -> V_118 , V_136 , V_135 ) ;
if ( F_56 ( V_2 -> V_118 ) &&
F_38 ( V_2 , V_122 ) &&
F_24 ( F_57 ( V_149 , & V_2 -> V_150 ) ) ) {
F_58 ( V_2 -> V_118 ) ;
V_2 -> V_89 . V_151 ++ ;
}
return ( V_35 == V_138 ) ;
}
